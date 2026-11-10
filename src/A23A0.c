#include "common.h"

extern f32 D_800C42B4[];

s32 func_800A17A0(Vec3f* a, Vec3f* b) {
    return (a->x - b->x >= -D_800C42B4[0] && a->x - b->x <= D_800C42B4[0] && a->y - b->y >= -D_800C42B4[0] &&
            a->y - b->y <= D_800C42B4[0] && a->z - b->z >= -D_800C42B4[0] && a->z - b->z <= D_800C42B4[0]);
}
