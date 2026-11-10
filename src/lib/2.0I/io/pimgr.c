#include "macros.h"
#include "PR/os_internal.h"
#include "piint.h"

/* libultra pimgr.c (_FINALROM: no ramrom thread). The statics live in the bss asm. */
extern OSThread D_800EA2D0;     /* piThread */
extern u8 D_800EB480[];         /* piEventQueue */
extern u8 D_800EA480[];         /* piThreadStack[0x1000] */
#define piThread D_800EA2D0
#define piEventQueue (*(OSMesgQueue*)D_800EB480)
extern OSMesg D_800EB498[1];    /* piEventBuf */
#define piEventBuf D_800EB498

extern OSMesgQueue __osPiAccessQueue;
extern u32 __osPiAccessQueueEnabled;

void osCreatePiManager(OSPri pri, OSMesgQueue* cmdQ, OSMesg* cmdBuf, s32 cmdMsgCnt) {
    u32 savedMask;
    OSPri oldPri;
    OSPri myPri;

    if (__osPiDevMgr.active) {
        return;
    }
    osCreateMesgQueue(cmdQ, cmdBuf, cmdMsgCnt);
    osCreateMesgQueue(&piEventQueue, (OSMesg*)piEventBuf, 1);
    if (!__osPiAccessQueueEnabled) {
        __osPiCreateAccessQueue();
    }
    osSetEventMesg(OS_EVENT_PI, &piEventQueue, (OSMesg)0x22222222);
    oldPri = -1;
    myPri = osGetThreadPri(NULL);
    if (myPri < pri) {
        oldPri = myPri;
        osSetThreadPri(NULL, pri);
    }
    savedMask = __osDisableInt();
    __osPiDevMgr.active = 1;
    __osPiDevMgr.thread = &piThread;
    __osPiDevMgr.cmdQueue = cmdQ;
    __osPiDevMgr.evtQueue = &piEventQueue;
    __osPiDevMgr.acsQueue = &__osPiAccessQueue;
    __osPiDevMgr.dma = __osPiRawStartDma;
    __osPiDevMgr.edma = __osEPiRawStartDma;
    osCreateThread(&piThread, 0, __osDevMgrMain, &__osPiDevMgr, D_800EA480 + 0x1000, pri);
    osStartThread(&piThread);
    __osRestoreInt(savedMask);
    if (oldPri != -1) {
        osSetThreadPri(NULL, oldPri);
    }
}
