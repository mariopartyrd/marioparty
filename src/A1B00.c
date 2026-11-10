#include "common.h"

void func_800A0F00(Vec3f* arg0, f32 arg1, Vec3f* arg2) {
    arg0->x = arg1 * arg2->x;
    arg0->y = arg1 * arg2->y;
    arg0->z = arg1 * arg2->z;
}
void func_800A0F70(Vec3f* out, Vec3f* a, f32 s, Vec3f* b) {
    out->x = a->x + s * b->x;
    out->y = a->y + s * b->y;
    out->z = a->z + s * b->z;
}
