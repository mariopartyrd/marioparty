#include "common.h"
#include "engine/process.h"

extern u16 ContBtn[];
extern s8 ContStkY[];
extern u8 D_800F64E8[];
extern u8 D_800F3388[];
extern u16 D_800F338C[];
extern u16 D_800ECC24[];
void func_8006CE64(u8, s16, s16, s16);


typedef struct omSndFade {
    /* 0x00 */ f32 vol[13];
    /* 0x34 */ f32 step[13];
    /* 0x68 */ f32 vol2[13];
    /* 0x9C */ f32 step2[13];
    /* 0xD0 */ u8 flags[13];
} omSndFade; // sizeof 0xE0

extern Addr D_15396A0;
extern Addr D_1778BC0;
extern Addr D_1832AE0;
extern Addr D_1BB8460;

void func_800117AC(s16);
void func_8001165C(void);
s16 func_80011530(s16);
void func_8001286C(u8);
void func_8001249C(s16, u8);
s32 func_8000C144(void);
s32 func_800115C8(s16);
file_1ACF0_struct* func_8000B2BC(void);
void func_80010C30(Addr*, s32, s32, s32);
void func_8000BE98(Addr*, Addr*, s32, s32, s32);
void func_8000B13C(void);
void func_8000B364(s32);
void func_800608EC(omObjData* obj);


extern s16 D_800F0A08[];
void func_800123DC(s16, s8);
void func_80060BC8(s16, s16);
void func_80012738(s8);
void func_80012574(s16, s16);


extern omObjData* D_800EE750;
extern s32 D_800F6520;
void func_800607E8(void);
s16 func_8000BEBC(s16, s32);
void func_8000C1B8(void);
void func_8000C390(s8);
void func_8000C414(s8);
void func_8000C4BC(s16);
s16 func_80010C4C(s16);

void func_80060058(omObjData* obj);


extern u8 D_800F3B80;
void GamePauseStart(void);
void GamePauseEnd(void);
void func_8006CEA0(void);


typedef struct omDBGMenuItem {
    /* 0x00 */ u8 disabled;
    /* 0x01 */ u8 x;
    /* 0x02 */ u8 y;
    /* 0x03 */ u8 color;
    /* 0x04 */ u8 selColor;
    /* 0x08 */ char* str;
} omDBGMenuItem; // sizeof 0xC

extern const char D_800CB574[], D_800CB57C[], D_800CB584[], D_800CB58C[], D_800CB594[], D_800CB59C[];
/* Board/minigame pairs read by omMain (meaning not traced). */
u8 D_800C58E0[56][2] = {
    { 0x00, 0x14 }, { 0x02, 0x14 }, { 0x00, 0x14 }, { 0x00, 0x14 }, { 0x00, 0x14 }, { 0x00, 0x14 }, { 0x01, 0x14 }, { 0x01, 0x14 },
    { 0x00, 0x14 }, { 0x01, 0x14 }, { 0x01, 0x14 }, { 0x00, 0x14 }, { 0x01, 0x14 }, { 0x00, 0x14 }, { 0x02, 0x14 }, { 0x01, 0x14 },
    { 0x01, 0x14 }, { 0x02, 0x14 }, { 0x00, 0x14 }, { 0x01, 0x14 }, { 0x00, 0x14 }, { 0x00, 0x14 }, { 0x00, 0x14 }, { 0x01, 0x14 },
    { 0x00, 0x14 }, { 0x00, 0x14 }, { 0x00, 0x14 }, { 0x00, 0x14 }, { 0x01, 0x14 }, { 0x00, 0x14 }, { 0x00, 0x14 }, { 0x00, 0x14 },
    { 0x00, 0x14 }, { 0x02, 0x14 }, { 0x00, 0x14 }, { 0x02, 0x14 }, { 0x00, 0x14 }, { 0x00, 0x14 }, { 0x02, 0x14 }, { 0x00, 0x14 },
    { 0x00, 0x14 }, { 0x00, 0x14 }, { 0x01, 0x14 }, { 0x00, 0x14 }, { 0x01, 0x14 }, { 0x01, 0x14 }, { 0x01, 0x14 }, { 0x00, 0x14 },
    { 0x00, 0x14 }, { 0x00, 0x14 }, { 0x00, 0x14 }, { 0x00, 0x14 }, { 0x00, 0x14 }, { 0x00, 0x14 }, { 0x00, 0x14 }, { 0x00, 0x14 }
};
u8 D_800C5950[11][2] = {
    { 0x00, 0x14 }, { 0x00, 0x14 }, { 0x00, 0x14 }, { 0x00, 0x14 }, { 0x01, 0x14 }, { 0x00, 0x14 }, { 0x01, 0x14 }, { 0x01, 0x14 },
    { 0x00, 0x14 }, { 0x00, 0x14 }, { 0x00, 0x14 }
};
u8 D_800C5966 = 0;
s32 D_800C5968 = 999; // previous overlay
u16 D_800C596C = 0xFFFF;
s16 D_800C596E = 0;
s16 D_800C5970 = 0; /* unreferenced */
u16 D_800C5972 = 0;
u16 D_800C5974 = 1;
u16 D_800C5976 = 1;
u8 D_800C5978 = 0;
s16 D_800C597A = -1;
u16 D_800C597C = 0;
s16 omovlhisidx = -1;
s16 D_800C5980 = 0; /* unreferenced */
u8 D_800C5982 = 1;
omObjData* D_800C5984 = NULL;
s16 D_800C5988 = 0;
s16 D_800C598A = 0;
s16 D_800C598C = 0; //dtor index
s16 D_800C598E = 0; /* unreferenced */
unkProcessStruct* D_800C5990 = NULL;
s16 D_800C5994 = 0;
s16 D_800C5996 = -1;
u16 D_800C5998 = 1;
s16 D_800C599A = 0;
s16 D_800C599C = 0;
s16 D_800C599E = 1;
s16 D_800C59A0 = 1;
u8 D_800C59A2 = 0;
s8 D_800C59A3 = 0;
u8 D_800C59A4 = 1;
s16 D_800C59A6 = -1;
/* Per-character entries (index, character, two file ids, scale); the DesertDash overlay reads the
   low byte of entry 0's index through D_800C59A9 (undefined_syms.txt). */
typedef struct objmainChr {
    s16 index;
    s16 unk02;
    s16 chr;
    s16 unk06;
    s32 file0;
    s32 file1;
    f32 scale;
} objmainChr;
objmainChr D_800C59A8[6] = {
    { 0, 0, 1, 0, 0x9F, 0x9E, 1.0f }, { 1, 0, 2, 0, 0x9F, 0x9E, 1.0f }, { 2, 0, 6, 0, 0x9F, 0x9E, 1.0f },
    { 3, 0, 3, 0, 0x9F, 0x9E, 0.9f }, { 4, 0, 4, 0, 0x9F, 0x9E, 0.8f }, { 5, 0, 5, 0, 0x9F, 0x9E, 0.7f },
};
u8 D_800C5A20 = 0;
u8 D_800C5A21 = 0;
omDBGMenuItem D_800C5A24[6] = {
    { 0, 0x84, 0x70, 0x06, 0x0E, (char*)D_800CB59C },
    { 0, 0x84, 0x78, 0x06, 0x0E, (char*)D_800CB594 },
    { 0, 0x84, 0x80, 0x06, 0x0E, (char*)D_800CB58C },
    { 0, 0x84, 0x88, 0x06, 0x0E, (char*)D_800CB584 },
    { 0, 0x84, 0x90, 0x06, 0x0E, (char*)D_800CB57C },
    { 0, 0x84, 0x98, 0x06, 0x0E, (char*)D_800CB574 },
};

typedef struct omSaftyFrameColor {
    u8 r;
    u8 g;
    u8 b;
} omSaftyFrameColor;

extern u16 D_800EE324[];
extern u16 D_800ED55C[];
extern u8 D_800F384E;
extern s16 D_800D89BE;
extern s16 D_800D89C0;
extern omSaftyFrameColor saftyFrameColor;

void saftyFrameFlashSet(s32, s32, s32, s32, s32, s32, s32, s32, s32);
void saftyFrameFlashReset(void);
void saftyFrameReset(void);
void saftyFrameSet(s32, s32, s32);
void pfWinClose(void);
void pfWinKill(s16);
void func_80070ED4(void);
s32 func_80072718(void);
void func_8000C64C(s32);
void func_8000C5C4(void);
void func_80037C40(void);
void func_80037C90(void);
void func_80060C84(s16);
void func_80060D4C(void);


typedef struct omCameraView {
    /* 0x00 */ f32 rot;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 z;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 far;
    /* 0x14 */ f32 near;
} omCameraView; // sizeof 0x18

extern omCameraView D_800EE738;
extern omCameraView D_800F2C28[];
extern Vec3f CRotM[];
extern f32 CZoomM[];
extern Vec3f CenterM[];
void omSystemKeyCheck(omObjData*);


extern u8 D_800D89B0;
extern u8 D_800F3705;
extern u8 D_800C4250[];
extern u8 omSysPauseEnableFlag;

s16 pfWinCreate(s32, s32, s32, s32, s32);
s32 func_8003B710(void);
s32 func_8003B730(void);
void func_800255DC(void);
void func_8001AB84(void*, u8, s32);
void func_80023B40(void* (*)(s32), void (*)(void*), u16, u16, s32, s32);
void func_8002B6C8(void);
void func_80025658(s32, s32);
void MakeTempHeap(void*, s32);
void func_8006CD0C(s16);
void func_80018870(void);
void OvlLoad(s32);
void func_80012A18(s8);
void func_800F65E0(void);
s32 func_800141FC(s16);
s32 func_8000B198(void);
u16 func_80060AB4(void);
void func_80060AF0(void);
void func_80060E54(void);
void func_8006086C(void);
void func_8006073C(void);
void func_800607A8(s32);
void func_80060234(s8);


extern s32 D_800F09F4; // current overlay
extern u16 D_800F3184;
extern u8 D_800ED552;
extern u16 D_800F3F30;
extern u16 D_800ED726;
extern u16 D_800F64EC;

void func_80060DFC(s8);
void func_80060E20(s16, s16, s16);
void GMesClose(void);
void func_80024754(void);
void func_8002AD04(void);
void func_80018AFC(void);
void func_80020234(void);


typedef struct omGrpData {
    /* 0x00 */ u16 next;
    /* 0x02 */ u16 max;
    /* 0x04 */ u16 num;
    /* 0x08 */ u16* nextIdx;
    /* 0x0C */ omObjData** obj;
} omGrpData; // sizeof 0x10

extern s16 D_800ED434; // last object index
extern s16 D_800F5468; // first object index
extern omObjData* omDBGSysKeyObj;
extern s8 D_800F64F8;
extern omObjData* D_800F64E0;
extern omGrpData D_800ED618[10];

void func_8005DAD4(omObjData*);


extern s16 D_800D89B2[];
extern s16 D_800ED56C;
extern s16 D_800ED550;
extern s16 D_800F65BA;
extern s16 D_800ED56C;

s16 func_80010ED4(s16, s16);
s32 func_80012C7C(s16);
void func_8005DA64(u16, omObjData*);
void omInsertObj(omObjData*);

void omInitObjMan(s32 maxObjects, s32 maxProcesses) {
    omObjData* obj;
    unkProcessStruct* prc;
    s32 i;

    D_800ED550 = maxObjects;
    D_800ED56C = 0;
    D_800F65BA = 0;
    D_800ED434 = -1;
    D_800F5468 = -1;
    omDBGSysKeyObj = NULL;
    D_800F5144 = 0;
    D_800F64F8 = 0;
    if (D_800C5984 != NULL) {
        func_800237BC(0x7918);
    }
    D_800C5984 = func_80023684(D_800ED550 * sizeof(omObjData), 0x7918);
    for (i = 0; i < D_800ED550; i++) {
        obj = &D_800C5984[i];
        obj->stat = 1;
        obj->prio = obj->prev = obj->next = -1;
        obj->unk_10 = 0;
        obj->trans.x = obj->trans.y = obj->trans.z = obj->rot.x = obj->rot.y = obj->rot.z = 0.0f;
        obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
        obj->func_ptr = obj->unk_50 = obj->model = obj->motion = NULL;
        obj->next_idx = i + 1;
        obj->mtncnt = 0;
        obj->motion = NULL;
    }
    for (i = 0; i < 10; i++) {
        D_800ED618[i].max = 0;
        D_800ED618[i].num = 0;
        D_800ED618[i].next = 0;
        D_800ED618[i].obj = NULL;
        D_800ED618[i].nextIdx = NULL;
    }
    D_800C5988 = maxProcesses + 2;
    D_800C598A = 0;
    D_800C598C = 0;
    D_800C5990 = func_80023684(D_800C5988 * sizeof(unkProcessStruct), 0x7918);
    for (i = 0; i < D_800C5988; i++) {
        prc = &D_800C5990[i];
        prc->unk0 = 1;
        prc->unk2 = i + 1;
        prc->processInstance = NULL;
        prc->unk8 = NULL;
    }
    D_800F64E0 = NULL;
}
void omDestroyObjMan(void) {
    omObjData* obj;
    unkProcessStruct* prc;
    s32 i;

    D_800ED434 = -1;
    for (i = 0; i < D_800ED550; i++) {
        obj = &D_800C5984[i];
        if (obj->stat != 1) {
            if (obj->model != NULL) {
                func_80023728(obj->model);
            }
            if (obj->motion != NULL) {
                func_80023728(obj->motion);
            }
            if (obj->unk_50 != NULL) {
                func_80023728(obj->unk_50);
            }
        }
    }
    func_80023728(D_800C5984);
    D_800C5984 = NULL;
    for (i = 0; i < 10; i++) {
        if (D_800ED618[i].max != 0) {
            if (D_800ED618[i].obj != NULL) {
                func_80023728(D_800ED618[i].obj);
                D_800ED618[i].obj = NULL;
            }
            if (D_800ED618[i].nextIdx != NULL) {
                func_80023728(D_800ED618[i].nextIdx);
                D_800ED618[i].nextIdx = NULL;
            }
            D_800ED618[i].max = 0;
        }
    }
    for (i = 0; i < D_800C5988; i++) {
        prc = &D_800C5990[i];
        if (prc->unk0 != 1) {
            HuPrcDestructorSet2(prc->processInstance, prc->unk8);
            HuPrcKill(prc->processInstance);
        }
    }
    D_800C5988 = 0;
    D_800C598A = 0;
    func_80023728(D_800C5990);
    D_800C5990 = NULL;
    func_800237BC(0x7918);
    D_800F64E0 = NULL;
}
omObjData* omAddObj(s16 arg0, u16 arg1, u16 arg2, s16 arg3, void* arg4) {
    omObjData* temp_s0;

    if (D_800ED56C == D_800ED550) {
        return NULL;
    }

    temp_s0 = &D_800C5984[D_800F65BA];
    temp_s0->next_idx_alloc = D_800F65BA;
    temp_s0->prio = arg0;
    omInsertObj(temp_s0);

    if (arg1 != 0) {
        temp_s0->model = func_80023684(arg1 * sizeof(s16), 0x7918);
        temp_s0->mdlcnt = arg1;
    } else {
        temp_s0->model = NULL;
        temp_s0->mdlcnt = 0;
    }

    if (arg2 != 0) {
        temp_s0->motion = func_80023684(arg2 * sizeof(s16), 0x7918);
        temp_s0->mtncnt = arg2;
    } else {
        temp_s0->motion = NULL;
        temp_s0->mtncnt = 0;
    }

    if (arg3 >= 0) {
        func_8005DA64(arg3, temp_s0);
    } else {
        temp_s0->group = arg3;
        temp_s0->group_idx = 0;
    }

    temp_s0->stat = 4;
    temp_s0->unk_10 = 0;
    temp_s0->func_ptr = arg4;
    temp_s0->work[0] = temp_s0->work[1] = temp_s0->work[2] = temp_s0->work[3] = 0;

    D_800F65BA = temp_s0->next_idx;
    D_800ED56C++;

    return temp_s0;
}

void omSetObjPrio(omObjData* obj, s16 prio) {
    obj->prio = prio;
    if (D_800ED434 != D_800F5468) {
        if (obj->next >= 0) {
            D_800C5984[obj->next].prev = obj->prev;
        }
        if (obj->prev >= 0) {
            D_800C5984[obj->prev].next = obj->next;
        }
        if (obj->prev < 0) {
            D_800F5468 = D_800C5984[obj->next].next_idx_alloc;
        }
        if (obj->next < 0) {
            D_800ED434 = D_800C5984[obj->prev].next_idx_alloc;
        }
        omInsertObj(obj);
    }
}
void omInsertObj(omObjData* obj) {
    s16 idx = obj->next_idx_alloc;
    s16 prio = obj->prio;
    s16 i;
    s16 last;
    omObjData* o;

    if (D_800F5468 == -1) {
        obj->next = obj->prev = -1;
        D_800F5468 = idx;
    } else {
        i = D_800F5468;
        while (i != -1) {
            o = &D_800C5984[i];
            if (prio >= o->prio) {
                break;
            }
            last = i;
            i = o->next;
        }
        if (i != -1) {
            obj->prev = o->prev;
            obj->next = i;
            if (o->prev != -1) {
                D_800C5984[o->prev].next = idx;
            } else {
                D_800F5468 = idx;
            }
            o->prev = idx;
            return;
        }
        obj->next = -1;
        obj->prev = last;
        o->next = idx;
    }
    D_800ED434 = idx;
}
void omDelObj(omObjData* obj) {
    s16 idx = obj->next_idx_alloc;

    if (D_800ED56C != 0) {
        D_800ED56C--;
        if (obj->group >= 0) {
            func_8005DAD4(obj);
        }
        if (obj->motion != NULL) {
            func_80023728(obj->motion);
            obj->motion = NULL;
        }
        if (obj->model != NULL) {
            func_80023728(obj->model);
            obj->model = NULL;
        }
        if (obj->unk_50 != NULL) {
            func_80023728(obj->unk_50);
            obj->unk_50 = NULL;
        }
        obj->stat = 1;
        if (obj->next >= 0) {
            D_800C5984[obj->next].prev = obj->prev;
        }
        if (obj->prev >= 0) {
            D_800C5984[obj->prev].next = obj->next;
        }
        if (obj->prev < 0) {
            D_800F5468 = D_800C5984[obj->next].next_idx_alloc;
        }
        if (obj->next < 0) {
            D_800ED434 = D_800C5984[obj->prev].next_idx_alloc;
        }
        obj->next_idx = D_800F65BA;
        D_800F65BA = idx;
    }
}
void omSetStat(omObjData* obj, u16 stat) {
    obj->stat = stat;
}
void omSetStatBit(omObjData* obj, s32 bit) {
    obj->stat |= bit;
}
void omResetStatBit(omObjData* obj, s32 bit) {
    obj->stat &= ~bit;
}
void omPrcSetStat(Process* process, u16 stat) {
    D_800C5990[process->dtor_idx].unk0 = stat;
}
void omPrcSetStatBit(Process* process, s32 bit) {
    D_800C5990[process->dtor_idx].unk0 |= bit;
}
void omPrcResetStatBit(Process* process, s32 bit) {
    D_800C5990[process->dtor_idx].unk0 &= ~bit;
}
void omSetTra(omObjData* obj, f32 x, f32 y, f32 z) {
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = z;
}
void omSetRot(omObjData* obj, f32 x, f32 y, f32 z) {
    obj->rot.x = x;
    obj->rot.y = y;
    obj->rot.z = z;
}
void omSetSca(omObjData* obj, f32 x, f32 y, f32 z) {
    obj->scale.x = x;
    obj->scale.y = y;
    obj->scale.z = z;
}
void func_8005D98C(u16 grp, u16 max) {
    omGrpData* g = &D_800ED618[grp];
    s32 i;

    if (g->obj != NULL) {
        func_80023728(g->obj);
    }
    if (g->nextIdx != NULL) {
        func_80023728(g->nextIdx);
    }
    g->next = 0;
    g->max = max;
    g->num = 0;
    g->obj = func_80023684(max * sizeof(omObjData*), 0x7918);
    g->nextIdx = func_80023684(max * sizeof(u16), 0x7918);
    for (i = 0; i < max; i++) {
        g->obj[i] = NULL;
        g->nextIdx[i] = i + 1;
    }
}
void func_8005DA64(u16 grp, omObjData* obj) {
    omGrpData* g = &D_800ED618[grp];

    if (g->num != g->max) {
        obj->group = grp;
        obj->group_idx = g->next;
        g->obj[g->next] = obj;
        g->next = g->nextIdx[g->next];
        g->num++;
    }
}
void func_8005DAD4(omObjData* obj) {
    omGrpData* g;

    if (obj->group != -1) {
        g = &D_800ED618[obj->group];
        g->obj[obj->group_idx] = NULL;
        g->nextIdx[obj->group_idx] = g->next;
        g->next = obj->group_idx;
        obj->group = -1;
        g->num--;
    }
}
omObjData** func_8005DB44(s16 grp) {
    return D_800ED618[grp].obj;
}
omObjData* func_8005DB5C(s16 grp, u16 idx) {
    return D_800ED618[grp].obj[idx];
}
void func_8005DB84(s16 grp, s32 bit) {
    omGrpData* g = &D_800ED618[grp];
    s32 i;
    omObjData* obj;

    for (i = 0; i < g->max; i++) {
        obj = g->obj[i];
        if (obj != NULL) {
            obj->unk_10 |= bit;
        }
    }
}
void func_8005DBE4(s16 grp, u16 idx, s32 bit) {
    omObjData* obj = D_800ED618[grp].obj[idx];
    obj->unk_10 |= bit;
}
void func_8005DC18(omObjData* obj, s32 bit) {
    obj->unk_10 |= bit;
}
Process* omAddPrcObj(void (*func)(), u16 priority, s32 stack_size, s32 extra_data_size) {
    unkProcessStruct* temp_s0;
    Process* process;
    s16 temp_s1;
    
    if (D_800C598A != D_800C5988) {
        temp_s1 = D_800C598C;
        temp_s0 = &D_800C5990[D_800C598C];
        temp_s0->unk0 = 4;
        D_800C598C = temp_s0->unk2;
        process = HuPrcCreate(*func, priority, stack_size, extra_data_size);
        temp_s0->processInstance = process;
        process->dtor_idx = temp_s1;
        HuPrcDestructorSet2(temp_s0->processInstance, &omDelPrcObj);
        temp_s0->unk8 = 0;
        D_800C598A++;
        return temp_s0->processInstance;
    } else {
        return NULL;
    }
}

Process* func_8005DCD8(process_func arg0, u16 arg1, s32 arg2, s32 arg3, Process* arg4) {
    unkProcessStruct* temp_s0;
    Process* process;
    s16 temp_s1;
    
    if (D_800C598A != D_800C5988) {
        temp_s1 = D_800C598C;
        temp_s0 = &D_800C5990[D_800C598C];
        temp_s0->unk0 = 4;
        D_800C598C = temp_s0->unk2;
        process = HuPrcChildCreate(arg0, arg1, arg2, arg3, arg4);
        temp_s0->processInstance = process;
        process->dtor_idx = temp_s1;
        HuPrcDestructorSet2(temp_s0->processInstance, omDelPrcObj);
        temp_s0->unk8 = 0;
        D_800C598A++;
        return temp_s0->processInstance;
    }
    
    return NULL;
}

s32 EndProcess(Process* arg0) {
    if (arg0 != NULL) {
        return HuPrcKill(arg0);
    }
    
    if (HuPrcKill(HuPrcCurrentGet()) == 0) {
        HuPrcVSleep();
    }
    
    return -1;
}

void omDelPrcObj(void) {
    Process* temp_s1 = HuPrcCurrentGet();
    unkProcessStruct* temp_s0 = &D_800C5990[temp_s1->dtor_idx];
    
    if (temp_s0->unk8 != 0) {
        (temp_s0->unk8)();
    }
    
    temp_s0->unk0 = 1;
    temp_s0->unk2 = D_800C598C;
    D_800C598C = temp_s1->dtor_idx;
    D_800C598A--;
}

void omDestroyPrcObj(s32 arg0, void (*arg1)()) {
    unkProcessStruct* temp = &D_800C5990[HuPrcCurrentGet()->dtor_idx];
    temp->unk8 = arg1;
}

void omPrcSetDestructor(void) {
    unkProcessStruct* var_v1 = D_800C5990;
    s32 i;
    
    for (i = 0; i < D_800C5988; i++) {
        if ((var_v1->unk0 & 4) && (var_v1->processInstance->exec_mode == EXEC_PROCESS_DEAD)) {
            var_v1->unk0 = 1;
            var_v1->unk2 = D_800C598C;
            D_800C598C = i;
            D_800C598A--;
        }
        var_v1++;
    }
}

s32 omOvlCallEx(s32 arg0, s16 arg1, u16 arg2) {
    omOvlHisData* history;
    s32 ret;

    if (omovlhisidx < ARRAY_COUNT(omovlhis)) {
        history = &omovlhis[++omovlhisidx];
        history->overlayID = arg0;
        history->event = arg1;
        history->stat = arg2;
        omOvlGotoEx(arg0, arg1, arg2);
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}

s32 omOvlReturnEx(s16 level) {
    omovlhisidx -= level;
    
    if (omovlhisidx < 0) {
        omovlhisidx = 0;
        omOvlGotoEx(omovlhis[0].overlayID, omovlhis[0].event, omovlhis[0].stat);
        return 0;
    }
    omOvlGotoEx(omovlhis[omovlhisidx].overlayID, omovlhis[omovlhisidx].event, omovlhis[omovlhisidx].stat);
    return 1;
}

void omOvlGotoEx(s32 overlay, s16 event, u16 stat) {
    u8 a;
    u8 b;

    if (D_800F09F4 != 0x83 && D_800F09F4 != 0x7A) {
        D_800C5968 = D_800F09F4;
    }
    D_800C5982 = 1;
    D_800F09F4 = overlay;
    D_800C597A = event;
    D_800C597C = stat;
    D_800F3184 = 0;
    if ((stat & 0x40) && D_800ED552 != 2) {
        func_80060DFC(2);
    } else if ((stat & 0x80) && D_800ED552 != 3) {
        func_80060DFC(3);
    }
    if ((stat & 1) && (D_800F3F30 != 0x1000 || D_800ED726 != 0x2004 || D_800F64EC != 0x180)) {
        func_80060E20(0x1000, 0x2004, 0x180);
    } else if ((stat & 2) && (D_800F3F30 != 0x800 || D_800ED726 != 0x1000 || D_800F64EC != 0x180)) {
        func_80060E20(0x800, 0x1000, 0x180);
    } else if ((stat & 4) && (D_800F3F30 != 0x1000 || D_800ED726 != 0x2004 || D_800F64EC != 0x180)) {
        func_80060E20(0x1000, 0x2004, 0x180);
    }
    if (!(stat & 0x1000)) {
        if (stat & 2) {
            if (overlay == 1) {
                a = D_800C58E0[1][0];
                b = D_800C58E0[1][1];
            } else {
                a = D_800C5950[GwSystem.curBoardIndex][0];
                b = D_800C5950[GwSystem.curBoardIndex][1];
            }
        } else if (stat & 4) {
            if (overlay == 0x6F || overlay == 0x7B) {
                a = 0;
                b = 20;
            } else {
                a = D_800C58E0[GwSystem.unk_1E][0];
                b = D_800C58E0[GwSystem.unk_1E][1];
            }
        } else {
            a = 0;
            b = 20;
        }
        if (stat & 0x100) {
            a = 0;
            b = 20;
        } else if (stat & 0x200) {
            a = 1;
            b = 20;
        } else if (stat & 0x400) {
            a = 2;
            b = 20;
        } else if (stat & 0x800) {
            a = 3;
            b = 20;
        }
        D_800C59A3 = b;
        D_800C599A = a;
    }
    if (overlay == 0x67 || overlay == 0x68 || overlay == 0x66 || overlay == 0x81 || overlay == 0x61
        || overlay == 0x41 || overlay == 0x64 || overlay == 0x63) {
        D_800C599E = 1;
    } else {
        D_800C599E = 0;
    }
}
void omOvlHisChg(s16 arg0, s32 overlay, s16 event, s16 stat) {
    s32 ovlhisIndex = omovlhisidx - arg0;
    omOvlHisData* history;
    
    if (ovlhisIndex >= 0) {
        history = &omovlhis[ovlhisIndex];
        history->overlayID = overlay;
        history->event = event;
        history->stat = stat;
    }
}

void omOvlKill(void) {
    D_800C5978 = 4;
    GMesClose();
    func_80024754();
    func_8002AD04();
    omDestroyObjMan();
    func_80018AFC();
    func_80020234();
    func_8002578C(1);
}
void omMain(void) {
    omObjData* obj;
    s32 i;
    s16 j;
    s16 win;

    if (D_800C5972 != 0) {
        fontcolor = 14;
        sprintf(pfStrBuf, "%8lX(%ld)", func_8003B710(), func_8003B730());
        print8(16, 24, pfStrBuf);
        sprintf(pfStrBuf, "OVL:%d(%ld<%ld)", omovlhisidx, D_800F09F4, D_800C5968);
        print8(24, 32, pfStrBuf);
        sprintf(pfStrBuf, "OBJ:%d/%d", D_800ED56C, D_800ED550);
        print8(24, 40, pfStrBuf);
        sprintf(pfStrBuf, "PRC:%d/%d", D_800C598A, D_800C5988);
        print8(24, 48, pfStrBuf);
        sprintf(pfStrBuf, "%02X", D_800C5998);
        print8(112, 48, pfStrBuf);
        if (D_800C59A6 == -1) {
            D_800C59A6 = pfWinCreate(14, 22, 130, 58, 0xFF70);
        }
    }
    func_80060E54();
    func_8006086C();
    if (D_800C5982 != 0) {
        if (D_800C5998 & 8) {
            D_800C59A4 = 1;
            if (!(D_800C5998 & 1)) {
                if (D_800C5978 == 0) {
                    return;
                }
                goto dec;
            }
        }
        if (D_800C5978 == 0) {
            if (D_800C5994 == 1) {
                if (D_800F3184 == 4) {
                    func_800255DC();
                }
                if (D_800F3184 != 0) {
                    D_800F3184--;
                    return;
                }
                D_800ED552 = D_800F3705;
                func_8001AB84(D_800C4250, D_800F3705, 2);
                func_80023B40(HuMemDirectMalloc, HuMemDirectFree, D_800F3F30, D_800ED726, D_800F64EC, D_800F3705);
                func_8002B6C8();
                func_80025658(0x02000000, 0x3D0800);
                InitCameras(1);
            }
            D_800C5994 = 0;
            if (D_800C59A2 == 0) {
                if (D_800C5A20 != 0) {
                    if (--D_800C5A20 == 0) {
                        D_800C5A21 = 1;
                    }
                    return;
                }
                D_800D89B0 = 0;
                if (func_80060AB4() == 1) {
                    func_80060198();
                    func_8006073C();
                    if (D_800C5A21 == 0) {
                        D_800C5A20 = 5;
                        return;
                    }
                    if (D_800C5A21 == 1 && func_8000B198() == 0) {
                        D_800D89B0 = 1;
                        D_800C59A2 = 1;
                    }
                    return;
                }
            } else {
                if (--D_800D89B0 != 0) {
                    return;
                }
                func_80060AF0();
                D_800C599C = D_800C599A;
                D_800C59A0 = D_800C599E;
                D_800C59A2 = 0;
                D_800C5A21 = 0;
            }
            MakeTempHeap(((void *)0x80120000), 0x20000);
            for (i = 0; i < 4; i++) {
                func_8006CD0C(i);
            }
            if (D_800F09F4 != 0x83) {
                D_800C596C = D_800F09F4;
            }
            omSysPauseEnableFlag = 0;
            func_80018870();
            D_800C5982 = 0;
            OvlLoad(D_800F09F4);
            func_80023040();
            D_800F524C = 1.0f;
            D_800F5028 = 1.0f;
            func_80023448(3);
            func_800234B8(0, 255, 255, 255);
            func_800234B8(1, 64, 64, 96);
            func_80023504(1, -100.0f, 100.0f, 100.0f);
            func_800234B8(2, 32, 32, 32);
            func_80023504(2, 100.0f, 100.0f, 100.0f);
            func_800234B8(3, 0, 0, 0);
            func_80023504(3, 100.0f, 100.0f, 100.0f);
            func_8002890C(0, 0, 0);
            func_8002578C(1);
            func_80028BE0(1);
            func_8006073C();
            if (D_800C59A4 == 1) {
                func_80060234(0x7F);
                func_800603F0(0x7F);
            }
            func_800607A8(0x40);
            func_80012A18(D_800C59A3);
            D_800C59A4 = 0;
            func_800F65E0();
            for (i = 0; i < 4; i++) {
                if (func_800141FC(i) != 0) {
                    ContBtnTrg[i] = 0;
                }
            }
            if (D_800C5982 != 0) {
                omOvlKill();
                D_800C5978 = 0;
                return;
            }
        } else {
        dec:
            D_800C5978--;
            return;
        }
    }
    win = func_80061228(0, 0, 255);
    for (j = D_800ED434; j != -1; j = obj->prev) {
        obj = &D_800C5984[j];
        if (!(obj->stat & 3)) {
            if (obj->func_ptr != NULL && !(obj->stat & 0x58)) {
                ((void (*)(omObjData*))obj->func_ptr)(obj);
            }
            if (obj->model != NULL && obj->model[0] != -1) {
                func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
                func_800257E4(obj->model[0], obj->rot.x, obj->rot.y, obj->rot.z);
                func_80025830(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
            }
        }
    }
    func_80061264(win);
    if (D_800C5982 != 0) {
        omOvlKill();
    }
}
void omOutView(omObjData* obj) {
    Vec3f pos;
    Vec3f target;
    Vec3f up;
    f32 rx = CRot.x;
    f32 ry = CRot.y;

    pos.x = Center.x + func_800AEAC0(ry) * func_800AEFD0(rx) * CZoom;
    pos.y = -func_800AEAC0(rx) * CZoom + Center.y;
    pos.z = func_800AEFD0(ry) * func_800AEFD0(rx) * CZoom + Center.z;
    target.x = Center.x;
    target.y = Center.y;
    target.z = Center.z;
    up.x = func_800AEAC0(ry) * func_800AEAC0(rx);
    up.y = func_800AEFD0(rx);
    up.z = func_800AEFD0(ry) * func_800AEAC0(rx);
    D_800EE738.x = pos.x;
    D_800EE738.z = pos.z;
    D_800EE738.rot = CRot.y;
    D_800EE738.unk_0C = D_800C3110->unk_40;
    D_800EE738.far = 20000.0f;
    D_800EE738.near = 10000.0f;
    func_8001D420(0, &pos, &target, &up);
    func_8001D57C(0);
}
void omOutViewMulti(omObjData* obj) {
    Vec3f pos;
    Vec3f target;
    Vec3f up;
    f32 rx;
    f32 ry;
    u8 i;

    for (i = 0; i < obj->work[0]; i++) {
        rx = CRotM[i].x;
        ry = CRotM[i].y;
        pos.x = func_800AEAC0(ry) * func_800AEFD0(rx) * CZoomM[i] + CenterM[i].x;
        pos.y = -func_800AEAC0(rx) * CZoomM[i] + CenterM[i].y;
        pos.z = func_800AEFD0(ry) * func_800AEFD0(rx) * CZoomM[i] + CenterM[i].z;
        target.x = CenterM[i].x;
        target.y = CenterM[i].y;
        target.z = CenterM[i].z;
        up.x = func_800AEAC0(ry) * func_800AEAC0(rx);
        up.y = func_800AEFD0(rx);
        up.z = func_800AEFD0(ry) * func_800AEAC0(rx);
        D_800F2C28[i].x = pos.x;
        D_800F2C28[i].z = pos.z;
        D_800F2C28[i].rot = CRotM[i].y;
        D_800F2C28[i].unk_0C = D_800C3110[i].unk_40;
        D_800F2C28[i].far = 20000.0f;
        D_800F2C28[i].near = 10000.0f;
        func_8001D420(i, &pos, &target, &up);
        func_8001D57C(i);
    }
}
void omSystemKeyCheckSetup(void) {
    omObjData* obj;

    obj = omDBGSysKeyObj = omAddObj(0x7FD9, 0, 0, -1, omSystemKeyCheck);
    omSetStatBit(obj, 0xA0);
    obj->work[0] = 0;
    obj->work[1] = 0;
    obj->work[2] = 0;
}
const char D_800CB574[] = " SE STP";

const char D_800CB57C[] = " MUSSTP";

const char D_800CB584[] = " INFO  ";

const char D_800CB58C[] = " LIGHT ";

const char D_800CB594[] = " RESET ";

const char D_800CB59C[] = " CANCEL";

void omDBGSystemKeyCheck(omObjData* obj) {
    s32 i;
    s32 j;
    u8 pad;
    u8 close = 0;

    if (obj->work[0] & 1) {
        pad = obj->work[1];
        if (!(obj->work[0] & 4)) {
            sprintf(pfStrBuf, "- PAUSE -");
            fontcolor = 4;
            print8(125, 97, pfStrBuf);
            fontcolor = 12;
            print8(124, 96, pfStrBuf);
            for (i = 0; i < 6; i++) {
                sprintf(pfStrBuf, D_800C5A24[i].str);
                if (i == obj->work[2]) {
                    fontcolor = D_800C5A24[i].color;
                    print8(D_800C5A24[i].x + 1, D_800C5A24[i].y + 1, pfStrBuf);
                    fontcolor = D_800C5A24[i].selColor;
                    print8(D_800C5A24[i].x, D_800C5A24[i].y, pfStrBuf);
                } else {
                    fontcolor = 0;
                    print8(D_800C5A24[i].x + 1, D_800C5A24[i].y + 1, pfStrBuf);
                    fontcolor = D_800C5A24[i].color;
                    print8(D_800C5A24[i].x, D_800C5A24[i].y, pfStrBuf);
                }
            }
            sprintf(pfStrBuf, ">");
            fontcolor = 8;
            print8(D_800C5A24[obj->work[2]].x + 1, D_800C5A24[obj->work[2]].y + 1, pfStrBuf);
            fontcolor = 15;
            print8(D_800C5A24[obj->work[2]].x, D_800C5A24[obj->work[2]].y, pfStrBuf);
            if (D_800EE324[pad] & 0x400) {
                PlaySound(0xF5);
                do {
                    if (++obj->work[2] >= 6) {
                        obj->work[2] = 0;
                    }
                } while (D_800C5A24[obj->work[2]].disabled == 1);
            } else if (D_800EE324[pad] & 0x800) {
                PlaySound(0xF5);
                do {
                    if ((s8)--obj->work[2] < 0) {
                        obj->work[2] = 5;
                    }
                } while (D_800C5A24[obj->work[2]].disabled == 1);
            } else if (D_800EE324[pad] & 8) {
                obj->work[0] ^= 8;
                if (obj->work[0] & 8) {
                    saftyFrameFlashSet(1, 1, -1, 0x60, 0x80, 0xFF, 0, 0, 100);
                } else {
                    saftyFrameFlashReset();
                    saftyFrameColor.r = saftyFrameColor.g = 0;
                    saftyFrameColor.b = 0x90;
                }
            } else if (D_800EE324[pad] & 4) {
                obj->work[0] ^= 0x20;
                if (obj->work[0] & 0x20) {
                    saftyFrameColor.g = 0xFF;
                } else {
                    saftyFrameColor.g = 0;
                }
            } else if (D_800EE324[pad] & 2) {
                obj->work[0] ^= 0x10;
                if (obj->work[0] & 0x10) {
                    saftyFrameColor.r = 0xFF;
                } else {
                    saftyFrameColor.r = 0;
                }
            } else if (D_800EE324[pad] & 1) {
                obj->work[0] ^= 0x40;
                if (obj->work[0] & 0x40) {
                    saftyFrameColor.b = 0xFF;
                } else {
                    saftyFrameColor.b = 0;
                }
            } else if (D_800EE324[pad] & 0x8000) {
                D_800EE324[pad] = 0;
                PlaySound(0xF6);
                switch (obj->work[2]) {
                case 0:
                    D_800EE324[pad] |= 0x20;
                    break;
                case 1:
                    D_800F5144 = 1;
                    D_800EE324[pad] |= 0x20;
                    if (omDBGSysKeyObj->work[0] & 1) {
                        omDBGSysKeyObj->work[0] &= ~1;
                        func_80070ED4();
                    }
                    break;
                case 2:
                    pfWinClose();
                    D_800C5972 = 0;
                    D_800C59A6 = -1;
                    saftyFrameReset();
                    obj->work[0] |= 4;
                    func_80037C40();
                    break;
                case 3:
                    if ((D_800C5972 ^= 1) == 0) {
                        pfWinKill(D_800C59A6);
                        D_800C59A6 = -1;
                    }
                    break;
                case 4:
                    if ((D_800C5974 ^= 1) == 0) {
                        func_80060198();
                    }
                    break;
                case 5:
                    if ((D_800C5976 ^= 1) == 0) {
                        func_8006073C();
                    }
                    break;
                }
            }
        }
        if (D_800EE324[pad] & 0x20) {
            close = 1;
            obj->work[0] &= ~4;
        }
        if (D_800C5982 == 1) {
            close = 1;
        }
        if (close == 1) {
            obj->work[0] &= ~1;
            if (!(omDBGSysKeyObj->work[0] & 1)) {
                D_800F384E = D_800C5966;
                for (j = 0; j < D_800ED550; j++) {
                    if (!(D_800C5984[j].stat & 0x21)) {
                        omResetStatBit(&D_800C5984[j], 0x10);
                    }
                }
                for (j = 0; j < D_800C5988; j++) {
                    if (!(D_800C5990[j].unk0 & 0x21)) {
                        omPrcResetStatBit(D_800C5990[j].processInstance, 0x10);
                        if (!(D_800C5990[j].unk0 & 0x40)) {
                            D_800C5990[j].processInstance->stat &= ~1;
                        }
                    }
                }
                func_8000C64C(0);
                func_80060D4C();
                if (D_800C5998 & 8) {
                    D_800C5998 &= ~8;
                }
                for (i = 0; i < 4; i++) {
                    func_8006CD0C(i);
                }
            }
            pfWinKill(D_800D89BE);
            pfWinKill(D_800D89C0);
            saftyFrameReset();
            func_80037C90();
        }
    } else if (func_80072718() != 1 && D_800C5982 != 1) {
        for (i = 0; i < 4; i++) {
            if (func_800141FC(i) != 0 && (D_800EE324[i] & 0x20) && !((D_800ED55C[i] | D_800EE324[i]) & 0x10)) {
                D_800C5966 = D_800F384E;
                D_800F384E = 1;
                obj->work[0] = 1;
                obj->work[1] = i;
                for (j = 0; j < D_800ED550; j++) {
                    if (!(D_800C5984[j].stat & 0x21)) {
                        omSetStatBit(&D_800C5984[j], 0x10);
                    }
                }
                for (j = 0; j < D_800C5988; j++) {
                    if (!(D_800C5990[j].unk0 & 0x21)) {
                        omPrcSetStatBit(D_800C5990[j].processInstance, 0x10);
                        D_800C5990[j].processInstance->stat |= 1;
                    }
                }
                D_800D89BE = pfWinCreate(0x78, 0x60, 0xD0, 0xA8, 0x40FF);
                D_800D89C0 = pfWinCreate(0x74, 0x5C, 0xCC, 0xA4, 0x90FF);
                saftyFrameSet(0, 0, 0x90);
                func_8000C5C4();
                func_80060C84(4);
                return;
            }
        }
    }
}
void omSystemKeyCheck(omObjData* obj) {
    s32 i;
    s32 j;

    if (omSysPauseEnableFlag == 0) {
        if (obj->work[0] & 1) {
            if (D_800F3B80 != 0 && ((D_800EE324[obj->work[1]] & 0x1000) || D_800C5982 == 1)) {
                D_800F384E = 0;
                obj->work[0] &= ~1;
                for (j = 0; j < D_800ED550; j++) {
                    if (!(D_800C5984[j].stat & 0x21)) {
                        omResetStatBit(&D_800C5984[j], 0x10);
                    }
                }
                for (j = 0; j < D_800C5988; j++) {
                    if (!(D_800C5990[j].unk0 & 0x21)) {
                        omPrcResetStatBit(D_800C5990[j].processInstance, 0x10);
                        if (!(D_800C5990[j].unk0 & 0x40)) {
                            D_800C5990[j].processInstance->stat &= ~1;
                        }
                    }
                }
                for (j = 0; j < 4; j++) {
                    func_8006CD0C(j);
                }
                func_80070ED4();
                GamePauseEnd();
                func_8000C64C(0);
                func_80060D4C();
                if (D_800C5998 & 8) {
                    D_800C5998 &= ~8;
                }
            }
        } else if (func_80072718() != 1 && D_800C5982 != 1 && (D_800C597C & 4)) {
            for (i = 0; i < 4; i++) {
                if (func_800141FC(i) != 0 && (D_800EE324[i] & 0x1000)) {
                    D_800F3B80 = 0;
                    D_800F384E = 1;
                    obj->work[0] = 1;
                    obj->work[1] = i;
                    for (j = 0; j < D_800ED550; j++) {
                        if (!(D_800C5984[j].stat & 0x21)) {
                            omSetStatBit(&D_800C5984[j], 0x10);
                        }
                    }
                    for (j = 0; j < D_800C5988; j++) {
                        if (!(D_800C5990[j].unk0 & 0x21)) {
                            omPrcSetStatBit(D_800C5990[j].processInstance, 0x10);
                            D_800C5990[j].processInstance->stat |= 1;
                        }
                    }
                    func_8006CEA0();
                    GamePauseStart();
                    func_8000C5C4();
                    func_80060C84(4);
                    for (j = 0; j < 4; j++) {
                        func_8006CD0C(j);
                    }
                    return;
                }
            }
        }
    }
}
u16 func_8005FD5C(void) {
    if (omDBGSysKeyObj == NULL) {
        return 0;
    }
    return omDBGSysKeyObj->work[0] & 1;
}
s32 func_8005FD7C(void) {
    s32 i;

    if (func_80072718() == 1 || D_800C5982 == 1) {
        return 0;
    }
    D_800F64F8 = 1;
    for (i = 0; i < D_800ED550; i++) {
        if (!(D_800C5984[i].stat & 0x81)) {
            omSetStatBit(&D_800C5984[i], 0x40);
        }
    }
    for (i = 0; i < D_800C5988; i++) {
        if (!(D_800C5990[i].unk0 & 0x81)) {
            omPrcSetStatBit(D_800C5990[i].processInstance, 0x40);
            D_800C5990[i].processInstance->stat |= 1;
        }
    }
    for (i = 0; i < 4; i++) {
        func_8006CD0C(i);
    }
    return 1;
}

void func_8005FECC(void) {
    s32 i;

    D_800F64F8 = 0;
    for (i = 0; i < D_800ED550; i++) {
        if (!(D_800C5984[i].stat & 0x81)) {
            omResetStatBit(&D_800C5984[i], 0x40);
        }
    }
    for (i = 0; i < D_800C5988; i++) {
        if (!(D_800C5990[i].unk0 & 0x81)) {
            omPrcResetStatBit(D_800C5990[i].processInstance, 0x40);
            if (!(D_800C5990[i].unk0 & 0x10)) {
                D_800C5990[i].processInstance->stat &= ~1;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        func_8006CD0C(i);
    }
}
void func_8005FFFC(void) {
    D_800EE750 = omAddObj(0x7FD8, 0, 0, -1, func_80060058);
    omSetStatBit(D_800EE750, 0xA0);
    *(s32*)D_800EE750->work = D_800F6520;
}
void func_80060058(omObjData* obj) {
    s32* timer = (s32*)obj->work;

    if (*timer == 0) {
        D_800F5144 = 1;
    } else {
        (*timer)--;
    }
}
void func_80060088(void) {
    s32 i;
    GW_PLAYER* player;

    for (i = 0; i < 4; i++) {
        player = &GwPlayer[i];
        player->coins_mg = 0;
    }
    if (D_800C597C & 0x10) {
        omSystemKeyCheckSetup();
        if (D_800C597C & 4) {
            omSysPauseEnableFlag = 1;
        }
    }
    if (D_800C597C & 0x20) {
        func_8005FFFC();
    }
    func_800607E8();
}
s16 func_80060128(s32 arg0) {
    if (D_800C5974 != 0 && D_800C5996 != (s16)arg0) {
        D_800C5996 = arg0;
        D_800C5998 = (D_800C5998 | 2) & ~9;
        return func_8000BEBC(arg0, arg0);
    }
    return 0;
}
void func_80060198(void) {
    D_800C5996 = -1;
    func_8000C1B8();
    D_800C5998 = (D_800C5998 & ~0xA) | 1;
}
void func_800601D4(s32 arg0) {
    D_800C5996 = -1;
    func_8000C250(arg0);
    D_800C5998 |= 8;
}

void func_80060214(s8 arg0) {
    func_8000C390(arg0);
}
void func_80060234(s8 arg0) {
    func_8000C414(arg0);
    D_800C5998 &= ~8;
}
void func_80060268(s16 arg0) {
    func_8000C4BC(arg0);
}
s16 func_80060288(void) {
    return func_8000C544();
}
s32 PlaySound(s32 arg0) {
    s32 idx;

    if (D_800C5976 == 0) {
        return 0;
    }
    idx = func_80012C7C(arg0);
    if (idx > 0) {
        if (D_800D89B2[idx] == -1) {
            D_800D89B2[idx] = func_80010C4C(arg0);
        }
        return D_800D89B2[idx];
    }
    return func_80010C4C(arg0);
}
void func_8006035C(s16 arg0, s8 arg1) {
    D_800F0A08[arg0] = arg1;
    func_800123DC(arg0, arg1);
}
void func_80060398(s32 arg0) {
    s32 i;

    if (D_800F64E0 != 0) {
        for (i = 0; i < 13; i++) {
            func_80060BC8(i, arg0);
        }
    }
}
void func_800603F0(s32 arg0) {
    s32 i;

    for (i = 0; i < 13; i++) {
        D_800F0A08[i] = (s8)arg0;
    }
    func_80012738(arg0);
}
void func_80060440(s16 arg0, s16 arg1) {
    func_80012574(arg0, arg1);
}
s16 func_80060468(s16 arg0, u8 arg1) {
    s16 idx;

    if (D_800C5976 == 0) {
        return 0;
    }
    idx = func_80012C7C(arg0 + arg1);
    if (idx > 0) {
        if (D_800D89B2[idx] == -1) {
            D_800D89B2[idx] = func_80010C4C(arg0 + arg1);
        }
        return D_800D89B2[idx];
    }
    return func_80010C4C(arg0 + arg1);
}
s16 func_80060540(s16 arg0, s16 arg1) {
    s16 temp_v0;

    if (D_800C5976 == 0) {
        return 0;
    }

    temp_v0 = func_80012C7C(arg0);

    if (temp_v0 > 0) {
        if (D_800D89B2[temp_v0] == -1) {
            D_800D89B2[temp_v0] = func_80010ED4(arg0, arg1);
        }
        return D_800D89B2[temp_v0];
    } else {
        return func_80010ED4(arg0, arg1);
    }
}

s16 func_80060618(s16 arg0, s16 arg1) {
    s16 idx;

    if (D_800C5976 == 0) {
        return 0;
    }
    arg0 += GwPlayer[arg1].character;
    idx = func_80012C7C(arg0);
    if (idx > 0) {
        if (D_800D89B2[idx] == -1) {
            D_800D89B2[idx] = func_80010ED4(arg0, arg1);
        }
        return D_800D89B2[idx];
    }
    return func_80010ED4(arg0, arg1);
}
void func_8006071C(s16 arg0) {
    func_800117AC(arg0);
}
void func_8006073C(void) {
    func_8001165C();
}
s16 func_80060758(s16 arg0) {
    s16 ret = func_80011530(arg0);

    if (ret != -1) {
        func_800117AC(ret);
    }
    return ret;
}
void func_800607A8(s32 arg0) {
    func_8001286C(arg0);
}
void func_800607C4(s16 arg0, s32 arg1) {
    func_8001249C(arg0, arg1);
}
void func_800607E8(void) {
    omSndFade* fade;
    s32 i;

    D_800F64E0 = omAddObj(0x7FD8, 0, 0, -1, func_800608EC);
    D_800F64E0->unk_50 = func_80023684(sizeof(omSndFade), 0x7918);
    omSetStatBit(D_800F64E0, 0xA0);
    fade = D_800F64E0->unk_50;
    for (i = 0; i < 13; i++) {
        fade->flags[i] = 0;
    }
}
void func_8006086C(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        D_800D89B2[i] = -1;
    }
    switch (func_8000C144()) {
    case 0:
        D_800C5998 = (D_800C5998 | 1) & ~0xA;
        break;
    case 2:
        break;
    case 3:
        break;
    }
}
void func_800608EC(omObjData* obj) {
    omSndFade* fade = D_800F64E0->unk_50;
    s16 i;
    u8 flags;
    s32 playing;

    for (i = 0; i < 13; i++) {
        flags = fade->flags[i];
        playing = func_800115C8(i);
        if (flags & 2) {
            if (playing == 0) {
                fade->flags[i] &= ~5;
            } else if (flags & 4) {
                if ((fade->vol2[i] -= fade->step2[i]) <= 0.0f) {
                    fade->vol2[i] = 0.0f;
                    func_800123DC(i, 0);
                    fade->flags[i] &= ~4;
                } else {
                    func_800123DC(i, fade->vol2[i]);
                }
            }
        } else if (fade->flags[i] & 1) {
            if (playing == 0) {
                fade->flags[i] &= ~1;
            } else if ((fade->vol[i] -= fade->step[i]) <= 0.0f) {
                fade->vol[i] = 0.0f;
                func_800123DC(i, 0);
                func_800117AC(i);
                fade->flags[i] &= ~1;
            } else {
                func_800123DC(i, fade->vol[i]);
            }
        }
    }
}
u16 func_80060AB4(void) {
    u16 ret = D_800C599A != D_800C599C;

    if (D_800C599E != D_800C59A0) {
        ret = 1;
    }
    return ret;
}
void func_80060AF0(void) {
    file_1ACF0_struct* data = func_8000B2BC();

    data->unk_40 = D_800C599A + 20;
    if (D_800C599E == 0) {
        data->unk_4C = 32;
        func_80010C30(&D_1832AE0, 0, 0, 0);
        func_8000BE98(&D_15396A0, &D_1778BC0, 0, 0, 0);
    } else {
        data->unk_4C = 45;
        func_80010C30(&D_1BB8460, 0, 0, 0);
        func_8000BE98(&D_1778BC0, &D_1832AE0, 0, 0, 0);
    }
    func_8000B13C();
    if (_CheckFlag(0x10) != 0) {
        func_8000B364(0);
    } else {
        func_8000B364(1);
    }
}
void func_80060BC8(s16 ch, s16 frames) {
    omSndFade* fade;

    if (D_800F64E0 != NULL && func_800115C8(ch) != 0) {
        fade = D_800F64E0->unk_50;
        fade->flags[ch] |= 1;
        fade->vol[ch] = D_800F0A08[ch];
        fade->step[ch] = (f32)D_800F0A08[ch] / frames;
    }
}
void func_80060C84(s16 frames) {
    omSndFade* fade;
    s32 i;

    if (D_800F64E0 != NULL) {
        fade = D_800F64E0->unk_50;
        for (i = 0; i < 13; i++) {
            if ((fade->flags[i] |= 6) & 1) {
                fade->vol2[i] = fade->vol[i];
                fade->step2[i] = fade->vol[i] / frames;
            } else {
                fade->vol2[i] = D_800F0A08[i];
                fade->step2[i] = (f32)D_800F0A08[i] / frames;
            }
        }
    }
}
void func_80060D4C(void) {
    omSndFade* fade;
    s32 i;
    u8 flags;
    s32 vol;

    if (D_800F64E0 != NULL) {
        fade = D_800F64E0->unk_50;
        for (i = 0; i < 13; i++) {
            flags = fade->flags[i];
            fade->flags[i] = flags & ~6;
            if (flags & 1) {
                vol = fade->vol[i];
            } else {
                vol = (u16)D_800F0A08[i];
            }
            func_800123DC(i, vol);
        }
    }
}
void func_80060DFC(s8 arg0) {
    D_800C5994 = 1;
    D_800F3184 = 4;
    D_800F3705 = arg0;
}
void func_80060E20(s16 arg0, s16 arg1, s16 arg2) {
    D_800F3F30 = arg0;
    D_800ED726 = arg1;
    D_800F64EC = arg2;
    D_800C5994 = 1;
    D_800F3184 = 4;
}
void func_80060E54(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_800F64E8[i] = ContStkX[i];
        D_800F3388[i] = ContStkY[i];
        D_800ED55C[i] = ContBtn[i];
        D_800EE324[i] = ContBtnTrg[i];
        D_800ECC24[i] = D_800F338C[i];
    }
}
void func_80060F04(s16 player, s16 arg1, s16 arg2, s16 arg3) {
    if (!(GwPlayer[player].flags & 1)) {
        func_8006CE64(GwPlayer[player].port, arg1, arg2, arg3);
    }
}