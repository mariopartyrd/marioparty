#include "PR/gu.h"
#include "engine/graphics.h"

u8 D_800C30C0 = 0;
u8 D_800C30C1 = 0;
u8 D_800C30C2 = 0;
Gfx D_800C30C8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, TEXEL0, PRIMITIVE, TEXEL0, TEXEL0, 0, SHADE, 0, 0, TEXEL0, PRIMITIVE, TEXEL0),
    gsDPSetRenderMode(G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2),
    gsDPSetAlphaCompare(G_AC_THRESHOLD),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsSPEndDisplayList(),
};

typedef struct {
    s32 unk00;
    u16 unk04;
    s32 unk08;
    OSMesgQueue *unk0C;
    s32 unk10; // OSMesg to send to unk0C
} graphicsMessage; // OSMesg

typedef struct combinedStruct {
    OSTask task;
    OSMesgQueue mesgQueue;
} swapChainTaskQueue;

extern swapChainTaskQueue swapChainTask;
extern OSThread swapChainThread;
extern u8 swapChainStack[];

extern graphicsMessage gMesgRingBuffer[0x20];
extern s16 ringBufferIndex;

extern void **frameBufferPool;
extern u16 frameBufferCount;
extern u16 frameBufferSegmentID;

extern u64 *gThreadOutStackSize;
extern u64 *gThreadYieldStack;
extern u64 *gThreadOutStack;
extern u64 *gThread3Stack;

extern u8 rspBootAddressStart;
extern u8 rspBootAddressEnd;
extern Gfx gTaskDataPointers[];

extern s32 D_800ED0C4;
extern void *nextFrameBuffer;
extern void *currFrameBuffer;

extern s32 *gUCodeAddresses;
extern u32 D_800D5FF0; // message count?


extern OSMesgQueue gSwapChainMesgQueue;
extern void* gSwapChainInitMesg;
extern s16 gSwapChainMesgTotal;

extern OSMesgQueue gMesgQueue;
extern void* gMesgQueueInitMesg;

extern u32 D_800F383C; // Unk
extern OSMesgQueue D_800ED3C8; // Another system's message queue

/* Initialize Graphics SwapChain */
void func_8001A600(void **arg1, s32 arg2, s32 arg3, u64 **arg4, s32 *arg5) {
    func_8001AB84(arg1, arg2, arg3);
    func_8001ABAC(arg4);
    func_8001ABE8(arg5);
    func_8001ABF4(0);

    swapChainTask.mesgQueue.mtqueue = (OSThread*) &gMesgQueue;
    swapChainTask.task.t.type = 1;
    swapChainTask.task.t.flags = 2;
    swapChainTask.task.t.ucode_boot = (u64*) &rspBootAddressStart;
    swapChainTask.task.t.ucode_boot_size = (s32) (&rspBootAddressEnd - &rspBootAddressStart);
    swapChainTask.task.t.ucode_size = 0x1000;
    swapChainTask.task.t.ucode_data_size = 0x800;
    swapChainTask.task.t.dram_stack_size = 0x400;
    swapChainTask.task.t.data_ptr = (u64*) &gTaskDataPointers;
    swapChainTask.task.t.data_size = 2;
    swapChainTask.task.t.yield_data_size = 0xC00;

    gSwapChainMesgTotal = 0;
    ringBufferIndex = 0;
    D_800ED0C4 = 0;
    nextFrameBuffer = 0;
    currFrameBuffer = 0;
    osCreateMesgQueue(&gSwapChainMesgQueue, &gSwapChainInitMesg, 0x20);
    osCreateMesgQueue(&gMesgQueue, &gMesgQueueInitMesg, 8);
    osCreateThread(&swapChainThread, 0x10, &func_8001A7DC, NULL, &swapChainStack, 0x64);
    osStartThread(&swapChainThread);
}

/* Retrieve available frame buffer (triple buffering?) */
void *func_8001A750(void) {
    void *current;
    void *next;
    void *fBuffer;
    s16 i;

    current = osViGetCurrentFramebuffer();
    next = osViGetNextFramebuffer();
    
    for (i = 0; i < frameBufferCount; i++) {
        fBuffer = frameBufferPool[i];
        if (fBuffer != current) {
            if (fBuffer != next) {
                return fBuffer;
            }
        }
    }
    return NULL;
}

/* Swap Chain Loop */
void func_8001A7DC(void* arg0) {
    unkSchedStruct sp10;
    OSMesgQueue mesgQueue;
    unkGraphicsMessage2 sp38;
    graphicsMessage* recvdMesg;
    void* pAvailableFrameBuffer; // available frameBuffer
    s32 var_s4;
    u32 i;

    swapChainTaskQueue *pSwapChain;
    OSTask *pTask;

    recvdMesg = NULL;
    pTask = &swapChainTask.task;
    pSwapChain = &swapChainTask;
    var_s4 = 0;

    osCreateMesgQueue(&mesgQueue, (OSMesg*) &sp38, 8);
    func_800639F8(&sp10, &mesgQueue, 1);

    while (TRUE) {
        do {
            recvmesg:
            osRecvMesg(&mesgQueue, NULL, 1);
            if ((D_800F383C - var_s4) < D_800D5FF0) {
                goto recvmesg;
            }
    
            var_s4 = D_800F383C;
            func_800613E8();
            pAvailableFrameBuffer = func_8001A750();
        } while (pAvailableFrameBuffer == NULL);
    
        currFrameBuffer = nextFrameBuffer;
        nextFrameBuffer = pAvailableFrameBuffer;

        /* TODO: WHY EXTRA DO? */
        do { do {
            u32 intMask;
            Gfx *dl = gTaskDataPointers;
            osRecvMesg(&gSwapChainMesgQueue, (OSMesg) &recvdMesg, 1);
            gSPSegment(dl++, frameBufferSegmentID, pAvailableFrameBuffer);
            gSPBranchList(dl++, recvdMesg->unk00);
            pSwapChain->mesgQueue.fullqueue = (void *) (recvdMesg->unk08);
            pTask->t.dram_stack = gThread3Stack;
            pTask->t.output_buff = gThreadOutStack;
            pTask->t.output_buff_size = gThreadOutStackSize;
            pTask->t.yield_data_ptr = gThreadYieldStack;
            pTask->t.ucode =      (u64 *) *(   (recvdMesg->unk04 * 2)      + gUCodeAddresses); // offset     (data pairs?)
            pTask->t.ucode_data = (u64 *) *( ( (recvdMesg->unk04 * 2) | 1) + gUCodeAddresses); // offset + 1

            osSendMesg(&D_800ED3C8, (OSMesg) pSwapChain, 1);
            osRecvMesg(&gMesgQueue, NULL, 1);

            intMask = osSetIntMask(1);
            gSwapChainMesgTotal -= 1;
            osSetIntMask(intMask);

            if (recvdMesg->unk0C != NULL) {
                osSendMesg(recvdMesg->unk0C, (OSMesg) (recvdMesg->unk10), 1);
            }
        } while (!((s32) recvdMesg->unk08 & 1)); } while (FALSE);
    
        for (i = 1; i < D_800D5FF0; i++) {
            osRecvMesg(&mesgQueue, NULL, 1);
        }
    
        osViSwapBuffer(pAvailableFrameBuffer);
        if (D_800ED0C4 == 0) {
            osViBlack(0);
        }
        D_800ED0C4++;
        func_80061414(); // empty function
    }
}

/* Retrieve graphics OSMesg from ring buffer */
graphicsMessage* func_8001AA70(void) {
    if (ringBufferIndex >= 0x20) {
        ringBufferIndex = NULL;
    }
    return &gMesgRingBuffer[ringBufferIndex++];
}

/* Send graphics OSMesg */
u8 func_8001AAC4(s32 arg0, u16 arg1, s32 arg2, OSMesgQueue *arg3, s32 arg4) {
    graphicsMessage* mesg;
    u32 intMask;

    if (gSwapChainMesgTotal >= 0x20) {
        return FALSE;
    }

    intMask = osSetIntMask(1);
    gSwapChainMesgTotal++;
    osSetIntMask(intMask);
    mesg = func_8001AA70();

    /* Initialize message. */
    mesg->unk00 = arg0;
    mesg->unk04 = arg1;
    mesg->unk08 = arg2;
    mesg->unk0C = arg3;
    mesg->unk10 = arg4;

    osSendMesg(&gSwapChainMesgQueue, mesg, 1);
    return TRUE;
}

/* Init graphics frame buffer pool */
void func_8001AB84(void **pool, u16 size, u16 segment) {
    frameBufferPool = pool;
    frameBufferCount = size;
    frameBufferSegmentID = segment;
}

/* Reset frame buffer pool size. (Switch between double and triple buffering) */
void func_8001ABA0(u16 size) {
    frameBufferCount = size;
}

/* Initialize gThreadStacks */
void func_8001ABAC(u64 **threadStacks) {
    gThread3Stack = *threadStacks++;
    gThreadOutStack = *threadStacks++;
    gThreadOutStackSize = *threadStacks++;
    gThreadYieldStack = *threadStacks;
}

/* Set pointer to swapchain task's ucode addresses */
void func_8001ABE8(s32 *uCodeAdresses) {
    gUCodeAddresses = uCodeAdresses;
}

/* Swap chain state set? */
void func_8001ABF4(u32 arg0) {
    D_800D5FF0 = arg0;
}
