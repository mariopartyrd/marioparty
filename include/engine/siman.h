#ifndef _SIMAN_H
#define _SIMAN_H

#include "PR/os.h"

#define HOS_PRIORITY_SIMGR 0x5A

typedef s32 (*HuSiFuncVoid)(void);
typedef s32 (*HuSiFunc)(void *);

typedef struct functionListEntryt {
    struct functionListEntryt *child;
    HuSiFuncVoid func;
    s16 type;
} functionListEntry;

typedef struct {
    HuSiFunc func;
    //functionListEntry *pFuncListEntry;
    void * arg;
    s32 ret;
    OSMesgQueue *recvQueue;
} unkMesg;

typedef struct {
    s32 unk0[4]; /* the nnsched client (next, msgQ, mask): 24 bytes on the host, so this must be
                         pointer-wide or unkMsg (the SI thread's receive slot) overlaps its mask */
    unkMesg* unkMsg;
} unkMesgWrapper;

void func_80064234(void* arg0);

extern OSMesg D_800E3620;
extern OSMesg D_800E36A0;
extern OSThread D_800E3720;

extern functionListEntry *D_800E40D0;
extern functionListEntry *D_800E40D4;

extern OSMesgQueue D_800EE960;
extern OSMesgQueue D_800F3370;

// TODO: Put this in correct header
void func_800639F8(unkMesgWrapper*, OSMesgQueue*, s32); // nnsched func

#endif
