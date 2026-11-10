#include "common.h"
#include "sdk_hu3.h"

// Mtx form of func_800A6C80: the look-along-dir frame with a roll of angle (degrees), as fixed point.
void func_800A7030(Mtx* m, f32 angle, Vec3f* dir) {
    f32 s;
    f32 c;
    f32 xz;
    f32 invXz;
    f32 len;
    f32 x;
    f32 y;
    f32 z;
    s32 e00;
    s32 e01;
    s32 e02;
    s32 e10;
    s32 e11;
    s32 e12;
    s32 e20;
    s32 e21;
    s32 e22;

    len = func_800B1750(dir->x * dir->x + dir->y * dir->y + dir->z * dir->z);
    if (len == 0.0f) {
        return;
    }
    len = 1.0f / len;
    x = dir->x * len;
    y = dir->y * len;
    z = dir->z * len;
    xz = func_800B1750(x * x + z * z);
    func_800AF2E0(angle, &s, &c);
    if (xz != 0.0f) {
        invXz = 1.0f / xz;
        e00 = HU_FTOFIX32((-z * c - s * y * x) * invXz);
        e01 = HU_FTOFIX32(s * xz);
        e02 = HU_FTOFIX32((c * x - s * y * z) * invXz);
        e10 = HU_FTOFIX32((z * s - c * y * x) * invXz);
        e11 = HU_FTOFIX32(c * xz);
        e12 = HU_FTOFIX32((-s * x - c * y * z) * invXz);
        e20 = HU_FTOFIX32(-x);
        e21 = HU_FTOFIX32(-y);
        e22 = HU_FTOFIX32(-z);
    } else {
        e00 = HU_FTOFIX32(c);
        e01 = 0;
        e02 = HU_FTOFIX32(s * y);
        e10 = HU_FTOFIX32(-s);
        e11 = 0;
        e12 = HU_FTOFIX32(c * y);
        e20 = 0;
        e21 = HU_FTOFIX32(-y);
        e22 = 0;
    }
    m->m[0][0] = (e00 & 0xFFFF0000) | ((e01 >> 16) & 0xFFFF);
    m->m[0][1] = e02 & 0xFFFF0000;
    m->m[0][2] = (e10 & 0xFFFF0000) | ((e11 >> 16) & 0xFFFF);
    m->m[0][3] = e12 & 0xFFFF0000;
    m->m[1][0] = (e20 & 0xFFFF0000) | ((e21 >> 16) & 0xFFFF);
    m->m[1][1] = e22 & 0xFFFF0000;
    m->m[1][2] = 0;
    m->m[1][3] = 1;
    m->m[2][0] = ((e00 << 16) & 0xFFFF0000) | (e01 & 0xFFFF);
    m->m[2][1] = (e02 << 16) & 0xFFFF0000;
    m->m[2][2] = ((e10 << 16) & 0xFFFF0000) | (e11 & 0xFFFF);
    m->m[2][3] = (e12 << 16) & 0xFFFF0000;
    m->m[3][0] = ((e20 << 16) & 0xFFFF0000) | (e21 & 0xFFFF);
    m->m[3][1] = (e22 << 16) & 0xFFFF0000;
    m->m[3][2] = 0;
    m->m[3][3] = 0;
}
