#include "PR/os_internal.h"
#include "osint.h"

s32 osAfterPreNMI(void) {
    return __osSpSetPc(0);
}
