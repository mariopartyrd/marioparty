#include "macros.h"
#include "PR/os_internal.h"
#include "PR/rcp.h"
#include "viint.h"
#include "../os/osint.h"

/* libultra vimgr.c (2.0J: __additional_scanline). The statics live in the data/bss asm. */
extern OSDevMgr D_800C6550;     /* __osViDevMgr */
#define __osViDevMgr D_800C6550
extern OSThread D_800EB4A8;     /* viThread */
#define viThread D_800EB4A8
extern u8 D_800EC660[];         /* viEventQueue */
extern u8 D_800EB660[];         /* viThreadStack[0x1000] */
#define viEventQueue (*(OSMesgQueue*)D_800EC660)
extern OSMesg D_800EC678[5];    /* viEventBuf */
#define viEventBuf D_800EC678
extern OSIoMesg D_800EC690;     /* viRetraceMsg */
#define viRetraceMsg D_800EC690
extern OSIoMesg D_800EC6A8;     /* viCounterMsg */
#define viCounterMsg D_800EC6A8
extern u16 D_800EB4A0;          /* viMgrMain's static retrace */

void viMgrMain(void* arg);

void osCreateViManager(OSPri pri) {
    u32 savedMask;
    OSPri oldPri;
    OSPri myPri;

    if (__osViDevMgr.active) {
        return;
    }
    __osTimerServicesInit();
    __additional_scanline = 0;
    osCreateMesgQueue(&viEventQueue, viEventBuf, 5);
    viRetraceMsg.hdr.type = OS_MESG_TYPE_VRETRACE;
    viRetraceMsg.hdr.pri = OS_MESG_PRI_NORMAL;
    viRetraceMsg.hdr.retQueue = NULL;
    viCounterMsg.hdr.type = OS_MESG_TYPE_COUNTER;
    viCounterMsg.hdr.pri = OS_MESG_PRI_NORMAL;
    viCounterMsg.hdr.retQueue = NULL;
    osSetEventMesg(OS_EVENT_VI, &viEventQueue, &viRetraceMsg);
    osSetEventMesg(OS_EVENT_COUNTER, &viEventQueue, &viCounterMsg);
    oldPri = -1;
    myPri = osGetThreadPri(NULL);
    if (myPri < pri) {
        oldPri = myPri;
        osSetThreadPri(NULL, pri);
    }
    savedMask = __osDisableInt();
    __osViDevMgr.active = TRUE;
    __osViDevMgr.thread = &viThread;
    __osViDevMgr.cmdQueue = &viEventQueue;
    __osViDevMgr.evtQueue = &viEventQueue;
    __osViDevMgr.acsQueue = NULL;
    __osViDevMgr.dma = NULL;
    __osViDevMgr.edma = NULL;
    osCreateThread(&viThread, 0, viMgrMain, &__osViDevMgr, D_800EB660 + 0x1000, pri);
    __osViInit();
    osStartThread(&viThread);
    __osRestoreInt(savedMask);
    if (oldPri != -1) {
        osSetThreadPri(NULL, oldPri);
    }
}

void viMgrMain(void* arg) {
    __OSViContext* vc;
    OSDevMgr* dm;
    OSIoMesg* mb;
    s32 first;
    u32 count;

    mb = NULL;
    first = 0;
    vc = __osViGetCurrentContext();
    D_800EB4A0 = vc->retraceCount;
    if (D_800EB4A0 == 0) {
        D_800EB4A0 = 1;
    }
    dm = (OSDevMgr*)arg;
    while (TRUE) {
        osRecvMesg(dm->evtQueue, (OSMesg)&mb, OS_MESG_BLOCK);
        switch (mb->hdr.type) {
            case OS_MESG_TYPE_VRETRACE:
                __osViSwapContext();
                D_800EB4A0--;
                if (D_800EB4A0 == 0) {
                    vc = __osViGetCurrentContext();
                    if (vc->msgq != NULL) {
                        osSendMesg(vc->msgq, vc->msg, OS_MESG_NOBLOCK);
                    }
                    D_800EB4A0 = vc->retraceCount;
                }
                __osViIntrCount++;
                if (first) {
                    count = osGetCount();
                    __osCurrentTime = count;
                    first = 0;
                }
                count = __osBaseCounter;
                __osBaseCounter = osGetCount();
                count = __osBaseCounter - count;
                __osCurrentTime = __osCurrentTime + count;
                break;
            case OS_MESG_TYPE_COUNTER:
                __osTimerInterrupt();
                break;
            default:
                break;
        }
    }
}
