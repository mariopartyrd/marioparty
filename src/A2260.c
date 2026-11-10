#include "common.h"

s32 func_800A1660(Vec3f* a, Vec3f* b, f32 eps) {
    return (a->x - b->x >= -eps && a->x - b->x <= eps && a->y - b->y >= -eps && a->y - b->y <= eps &&
            a->z - b->z >= -eps && a->z - b->z <= eps);
}
