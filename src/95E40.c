#include "PR/os_internal.h"
#include "lib/2.0I/io/viint.h"

__OSViContext* __osViGetCurrentContext(void) {
    return __osViCurr;
}
