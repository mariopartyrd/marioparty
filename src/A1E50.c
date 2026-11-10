#include "common.h"

void func_800A1250(Vec3f* arg0) {
    f32 inv;

    inv = 1.0f / func_800B1750(arg0->x * arg0->x + arg0->y * arg0->y + arg0->z * arg0->z);
    arg0->x = inv * arg0->x;
    arg0->y = inv * arg0->y;
    arg0->z = inv * arg0->z;
}
f32 func_800A1320(Vec3f* a, Vec3f* b) {
    f32 dx;
    f32 dy;
    f32 dz;

    dx = a->x - b->x;
    dy = a->y - b->y;
    dz = a->z - b->z;
    return dx * dx + dy * dy + dz * dz;
}

f32 func_800A13C0(Vec3f* arg0, Vec3f* arg1) {
    f32 dx;
    f32 dy;
    f32 dz;

    dx = arg0->x - arg1->x;
    dy = arg0->y - arg1->y;
    dz = arg0->z - arg1->z;
    return func_800B1750(dx * dx + dy * dy + dz * dz);
}