#include "PR/os_internal.h"
#include "osint.h"

extern u32 D_800C7740; /* __osPreNMI */

void osSetEventMesg(OSEvent event, OSMesgQueue* mq, OSMesg msg) {
    register u32 saveMask;
    __OSEventState* es;

    saveMask = __osDisableInt();
    es = &__osEventStateTab[event];
    es->messageQueue = mq;
    es->message = msg;
    if (event == OS_EVENT_PRENMI) {
        if (__osShutdown && !D_800C7740) {
            osSendMesg(mq, msg, OS_MESG_NOBLOCK);
        }
        D_800C7740 = TRUE;
    }
    __osRestoreInt(saveMask);
}
