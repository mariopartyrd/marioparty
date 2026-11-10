#include "common.h"

void func_800A1010(Vec3f* out, f32 s, Vec3f* a, f32 t, Vec3f* b) {
    out->x = s * a->x + t * b->x;
    out->y = s * a->y + t * b->y;
    out->z = s * a->z + t * b->z;
}

void func_800A10C0(Vec3f* out, Vec2f* st, Vec3f* a, Vec3f* b) {
    out->x = st->x * a->x + st->y * b->x;
    out->y = st->x * a->y + st->y * b->y;
    out->z = st->x * a->z + st->y * b->z;
}
