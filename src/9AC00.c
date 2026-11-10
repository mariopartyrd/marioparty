#include "PR/os_internal.h"

#ifndef OS_IM_RCP
#define OS_IM_RCP 0x00000401
#endif

/* __osResetGlobalIntMask */
void func_8009A000(OSHWIntr mask) {
    register u32 saveMask = __osDisableInt();

    __OSGlobalIntMask &= ~(mask & ~OS_IM_RCP);
    __osRestoreInt(saveMask);
}
