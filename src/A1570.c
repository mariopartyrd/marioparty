#include "common.h"

s32 func_800A0890(f32 x, f32 eps);

s32 func_800A0970(f32 a, f32 b, f32 eps) {
    return func_800A0890(a - b, eps);
}
