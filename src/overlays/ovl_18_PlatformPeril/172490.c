#include "common.h"

/* Overlay-local pseudo-random generator state. */
u32 D_800FDF50_PlatformPeril = 0x0A6B99CD;

void func_800FCD50_PlatformPeril(u32 seed) {
    D_800FDF50_PlatformPeril = seed;
}

void func_800FCD5C_PlatformPeril(void) {
    u32 x = D_800FDF50_PlatformPeril << 2;
    u32 y;

    x += 2;
    y = x + 1;
    D_800FDF50_PlatformPeril = (x * y) >> 2;
}
