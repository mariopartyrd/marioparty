#include "common.h"

extern f32 D_800C42B4[];

s32 func_800A0900(f32 x) {
    return (-D_800C42B4[0] <= x && x <= D_800C42B4[0]);
}
