#include "engine/process.h"


void HuPrcInit(void) {
    processcnt = 0; //processcnt
    processtop = NULL;
}


void HuLinkProcess(Process** root, Process* process) {
    Process* src_process = *root;

    if (src_process != NULL && (src_process->priority >= process->priority)) {
        while (src_process->next != NULL) {
            if (src_process->next->priority < process->priority) {
                break;
            }
            src_process = src_process->next;
        }

        process->next = src_process->next;
        process->youngest_child = src_process;
        src_process->next = process;
        if (process->next) {
            process->next->youngest_child = process;
        }
    } else {
        process->next = (*root);
        process->youngest_child = NULL;
        *root = process;
        if (src_process != NULL) {
            src_process->youngest_child = process;
        }
    }
}

void HuUnlinkPrc(Process **root, Process *process) {
    if (process->next) {
        process->next->youngest_child = process->youngest_child;
    }

    if (process->youngest_child) {
        process->youngest_child->next = process->next;
    }

    else {
        *root = process->next;
    }
}

Process* HuPrcCreate(process_func func, u16 priority, s32 stack_size, s32 extra_data_size) {
    HeapNode* process_heap;
    Process* process;
    s32 alloc_size;

    if (stack_size == 0) {
        stack_size = 2048;
    }

    alloc_size = HuMemMemoryAllocSizeGet(sizeof(Process))
        + HuMemMemoryAllocSizeGet(stack_size)
        + HuMemMemoryAllocSizeGet(extra_data_size);

    process_heap = (HeapNode*)HuMemDirectMalloc(alloc_size);

    if (process_heap == NULL) {
        return NULL;
    }


    HuMemHeapInit(process_heap, alloc_size);

    process = (Process*)HuMemMemoryAlloc(process_heap, sizeof(Process));
    process->heap = process_heap;
    process->exec_mode = EXEC_PROCESS_DEFAULT;
    process->stat = 0;
    process->priority = priority;
    process->sleep_time = 0;
    process->base_sp = HuMemMemoryAlloc(process_heap, stack_size) + stack_size - 8;
    process->prc_jump.func = func;
    process->prc_jump.sp = process->base_sp;
    process->destructor = NULL;
    process->user_data = NULL;
    process->dtor_idx = 0;
    HuLinkProcess(&processtop, process);
    process->oldest_child = NULL;
    process->relative = NULL;
    processcnt++;
    return process;
}

void HuPrcChildLink(Process* process, Process* child) {
    HuPrcChildUnlink(child);

    if (process->oldest_child) {
        process->oldest_child->new_process = child;
    }

    child->parent_oldest_child = process->oldest_child;
    child->new_process = NULL;
    process->oldest_child = child;
    child->relative = process;
}

void HuPrcChildUnlink(Process* process) {
    if (process->relative) {
        if (process->parent_oldest_child) {
            process->parent_oldest_child->new_process = process->new_process;
        }

        if (process->new_process) {
            process->new_process->parent_oldest_child = process->parent_oldest_child;
        } else {
            process->relative->oldest_child = process->parent_oldest_child;
        }

        process->relative = NULL;
    }
}

Process* HuPrcChildCreate(process_func func, u16 priority, s32 stack_size, s32 extra_data_size, Process* parent) {
    Process* child = HuPrcCreate(func, priority, stack_size, extra_data_size);
    HuPrcChildLink(parent, child);
    return child;
}

void HuPrcChildWatch(void) {
    Process* process = HuPrcCurrentGet();
    if (process->oldest_child) {
        process->exec_mode = EXEC_PROCESS_WATCH;
        
        if (!setjmp(&process->prc_jump)) {
            longjmp(&process_jmp_buf, 1);
        }
    }
}

Process* HuPrcCurrentGet(void) {
    return processcur;
}

Process* GetChildProcess(Process* process) {
    Process* curr_child = process->oldest_child;

    while(curr_child) {
        curr_child = curr_child->parent_oldest_child;
    }

    return curr_child;
}

s32 SetKillStatusProcess(Process* process) {
    if (process->exec_mode != EXEC_PROCESS_DEAD) {
        HuPrcWakeup(process);
        process->exec_mode = EXEC_PROCESS_DEAD;
        return 0;
    } else {
        return -1;
    }
}

s32 HuPrcKill(Process* process) {
    HuPrcChildKill(process);
    HuPrcChildUnlink(process);
    return SetKillStatusProcess(process);
}

void HuPrcChildKill(Process* process) {
    Process* curr_child = process->oldest_child;

    while (curr_child != NULL) {
        if (curr_child->oldest_child != NULL) {
            HuPrcChildKill(curr_child);
        }

        SetKillStatusProcess(curr_child);

        curr_child = curr_child->parent_oldest_child;
    }

    process->oldest_child = NULL;
}

void HuPrcTerminate(Process* process) {
    if (process->destructor) {
        process->destructor();
    }

    HuUnlinkPrc(&processtop, process);
    processcnt--;
    longjmp(&process_jmp_buf, 2);
}

void HuPrcEnd(void) {
    Process* process = HuPrcCurrentGet();
    HuPrcChildKill(process);
    HuPrcChildUnlink(process);
    HuPrcTerminate(process);
}

void HuPrcSleep(s32 time) {
    Process* process = HuPrcCurrentGet();
    if (time != 0 && process->exec_mode != EXEC_PROCESS_DEAD) {
        process->exec_mode = EXEC_PROCESS_SLEEPING;
        process->sleep_time = time;
    }

    if (!setjmp(&process->prc_jump)) {
        longjmp(&process_jmp_buf, 1);
    }
}

void HuPrcVSleep(void) {
    HuPrcSleep(0);
}

void HuPrcWakeup(Process* process) {
    process->sleep_time = 0;
}

void HuPrcDestructorSet2(Process* process, process_func destructor) {
    process->destructor = destructor;
}

void HuPrcDestructorSet(process_func destructor) {
    Process* process = HuPrcCurrentGet();
    HuPrcDestructorSet2(process, destructor);
}

void HuPrcCall(s32 time) {
    Process* cur_proc_local;
    s32 ret;

    processcur = processtop;
    ret = setjmp(&process_jmp_buf);
    while (1) {
        switch (ret) {
            case 2:
                HuMemDirectFree(processcur->heap);
                processcur = processcur->next;
                break;
            case 1:
                processcur = processcur->next;
                break;
        }

        cur_proc_local = processcur;

        if (cur_proc_local == 0) {
            break;
        }
         
        if ((cur_proc_local->stat & 0x1)) {
            if (cur_proc_local->exec_mode != 3) {
                ret = 1;
                continue;
            }
        }

        switch (cur_proc_local->exec_mode) {
            case EXEC_PROCESS_SLEEPING:
                if (cur_proc_local->sleep_time > 0 && (cur_proc_local->sleep_time -= time) <= 0) {
                    cur_proc_local->sleep_time = 0;
                    cur_proc_local->exec_mode = EXEC_PROCESS_DEFAULT;
                }

                ret = 1;
                break;

            case EXEC_PROCESS_WATCH:
                if (cur_proc_local->oldest_child != 0) {
                    ret = 1;
                } else {
                    cur_proc_local->exec_mode = EXEC_PROCESS_DEFAULT;
                    ret = 0;
                }

                break;

            case EXEC_PROCESS_DEAD:
                cur_proc_local->prc_jump.func = HuPrcEnd;

            case 0:
                longjmp(&cur_proc_local->prc_jump, 1);
                break;
        }
    }
}


void* HuPrcMemAlloc(s32 size) {
    Process* process = HuPrcCurrentGet();
    return (void*)HuMemMemoryAlloc((HeapNode*)process->heap, size);
}

void HuPrcMemFree(void* ptr) {
    HuMemMemoryFree(ptr);
}