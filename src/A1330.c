#include "common.h"

extern f32 D_800C42B4[];

s32 func_800A0730(f32 x) {
    return (x < 0.0f) ? -1 : (x > 0.0f) ? 1 : 0;
}

s32 func_800A07A0(f32 x, f32 eps) {
    return (x < -eps) ? -1 : (x > eps) ? 1 : 0;
}

s32 func_800A0810(f32 x) {
    return (x < -D_800C42B4[0]) ? -1 : (x > D_800C42B4[0]) ? 1 : 0;
}
