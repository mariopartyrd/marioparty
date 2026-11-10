#include "common.h"

void func_800A1250(Vec3f*);
f32 func_800A1480(Vec3f*, Vec3f*);
f64 func_8009B0A8(f64);


f32 func_8003D2B0(Vec3f* v) {
    f32 a;

    if (v->x != 0.0f || v->z != 0.0f) {
        if (v->x == 0.0f) {
            if (0.0f < v->z) {
                return 0.0f;
            }
            return 180.0f;
        }
        if (v->z == 0.0f) {
            if (0.0f < v->x) {
                return 90.0f;
            }
            return 270.0f;
        }
        a = func_800B0CD8(v->z, v->x);
        if (v->z < 0.0f) {
            a = 90.0f - a;
        } else {
            a = 90.0f - a;
            if (a < 0.0f) {
                a += 360.0f;
            }
        }
        return a;
    }
    return -1.0f;
}
void func_8003D408(Vec3f* v) {
    if (v->x == 0.0f && v->y == 0.0f && v->z == 0.0f) {
        v->z = 1.0f;
    }
    func_800A1250(v);
}
void func_8003D478(Vec3f* v, f32 angle) {
    Vec3f orig;

    orig.y = v->y;
    orig.z = v->z;
    v->y = func_800AEFD0(angle) * orig.y - func_800AEAC0(angle) * orig.z;
    v->z = func_800AEFD0(angle) * orig.z + func_800AEAC0(angle) * orig.y;
}
void func_8003D514(Vec3f* v, f32 angle) {
    Vec3f orig;

    orig.x = v->x;
    orig.z = v->z;
    v->x = func_800AEFD0(angle) * orig.x + func_800AEAC0(angle) * orig.z;
    v->z = func_800AEFD0(angle) * orig.z - func_800AEAC0(angle) * orig.x;
}
void func_8003D5B0(Vec3f* v, f32 angle) {
    Vec3f orig;

    orig.x = v->x;
    orig.y = v->y;
    v->x = func_800AEFD0(angle) * orig.x - func_800AEAC0(angle) * orig.y;
    v->y = func_800AEFD0(angle) * orig.y + func_800AEAC0(angle) * orig.x;
}
void func_8003D64C(Vec3f* v, Vec3f* axis, f32 angle) {
    Vec3f orig;

    orig.x = v->x;
    orig.y = v->y;
    orig.z = v->z;
    func_8003D408(axis);
    v->x = (axis->x * axis->x + (1.0f - axis->x * axis->x) * func_800AEFD0(angle)) * orig.x +
           (axis->x * axis->y * (1.0f - func_800AEFD0(angle)) - func_800AEAC0(angle) * axis->z) * orig.y +
           (axis->x * axis->z * (1.0f - func_800AEFD0(angle)) + func_800AEAC0(angle) * axis->y) * orig.z;
    v->y = (axis->x * axis->y * (1.0f - func_800AEFD0(angle)) + func_800AEAC0(angle) * axis->z) * orig.x +
           (axis->y * axis->y + (1.0f - axis->y * axis->y) * func_800AEFD0(angle)) * orig.y +
           (axis->y * axis->z * (1.0f - func_800AEFD0(angle)) - func_800AEAC0(angle) * axis->x) * orig.z;
    v->z = (axis->x * axis->z * (1.0f - func_800AEFD0(angle)) - func_800AEAC0(angle) * axis->y) * orig.x +
           (axis->y * axis->z * (1.0f - func_800AEFD0(angle)) + func_800AEAC0(angle) * axis->x) * orig.y +
           (axis->z * axis->z + (1.0f - axis->z * axis->z) * func_800AEFD0(angle)) * orig.z;
}
// register allocation: the length product lands in $f20, retail $f12 (masked 0)
#ifdef NON_MATCHING
f32 func_8003D8CC(Vec3f* a, Vec3f* b) {
    f32 dot;
    f32 len;

    dot = func_800A1480(a, b);
    len = func_800A1200(a) * func_800A1200(b);
    if (len != 0.0f) {
        return func_8009B0A8(dot / len) / 0.017453292519943295;
    }
    return 0.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/3DEB0", func_8003D8CC);
#endif
