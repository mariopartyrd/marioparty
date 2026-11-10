#include "PR/os_internal.h"
#include "osint.h"

void osCreateMesgQueue(OSMesgQueue* mq, OSMesg* msgBuf, s32 count) {
    mq->mtqueue = (OSThread*)&__osThreadTail;
    mq->fullqueue = (OSThread*)&__osThreadTail;
    mq->validCount = 0;
    mq->first = 0;
    mq->msgCount = count;
    mq->msg = msgBuf;
}
