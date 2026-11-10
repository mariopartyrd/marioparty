#include "macros.h"
#include "PR/os_internal.h"

#define SI_Q_BUF_LEN 1

extern u32 D_800C77C0;              /* __osSiAccessQueueEnabled */
extern OSMesg D_800EC6C0[SI_Q_BUF_LEN]; /* siAccessBuf */
extern OSMesgQueue D_800F65C0;      /* __osSiAccessQueue */

void __osSiCreateAccessQueue(void) {
    D_800C77C0 = 1;
    osCreateMesgQueue(&D_800F65C0, D_800EC6C0, SI_Q_BUF_LEN);
    osSendMesg(&D_800F65C0, NULL, OS_MESG_NOBLOCK);
}

void __osSiGetAccess(void) {
    OSMesg dummyMesg;

    if (!D_800C77C0) {
        __osSiCreateAccessQueue();
    }
    osRecvMesg(&D_800F65C0, &dummyMesg, OS_MESG_BLOCK);
}

void __osSiRelAccess(void) {
    osSendMesg(&D_800F65C0, NULL, OS_MESG_NOBLOCK);
}
