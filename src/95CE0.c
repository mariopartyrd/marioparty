#include "macros.h"
#include "PR/os_internal.h"
#include "PR/R4300.h"
#include "PR/rcp.h"
#include "lib/2.0I/io/viint.h"

u32 __osSpGetStatus(void) {
    return IO_READ(SP_STATUS_REG);
}

void __osSpSetStatus(u32 data) {
    IO_WRITE(SP_STATUS_REG, data);
}

s32 __osSpSetPc(u32 pc) {
    register u32 status = IO_READ(SP_STATUS_REG);

    if (!(status & SP_STATUS_HALT)) {
        return -1;
    }
    IO_WRITE(SP_PC_REG, pc);
    return 0;
}

/* vi.c: the static vi[2] and the Lan1 modes live in the data asm */
extern __OSViContext D_800C7750[2]; /* vi */
extern OSViMode D_800C77D0;         /* osViModeNtscLan1 */
extern OSViMode D_800C7820;         /* osViModePalLan1 */
extern OSViMode D_800C7870;         /* osViModeMpalLan1 */

void __osViInit(void) {
    bzero(D_800C7750, sizeof(D_800C7750));
    __osViCurr = &D_800C7750[0];
    __osViNext = &D_800C7750[1];
    __osViNext->retraceCount = 1;
    __osViCurr->retraceCount = 1;
    __osViNext->framep = (void*)K0BASE;
    __osViCurr->framep = (void*)K0BASE;
    if (osTvType == OS_TV_PAL) {
        __osViNext->modep = &D_800C7820;
    } else if (osTvType == OS_TV_MPAL) {
        __osViNext->modep = &D_800C7870;
    } else {
        __osViNext->modep = &D_800C77D0;
    }
    __osViNext->state = VI_STATE_BLACK;
    __osViNext->control = __osViNext->modep->comRegs.ctrl;
    while (IO_READ(VI_CURRENT_REG) > 10) {
    }
    IO_WRITE(VI_CONTROL_REG, 0);
    __osViSwapContext();
}
