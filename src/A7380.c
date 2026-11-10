#include "common.h"
#include "sdk_hu3.h"

// Mtx from per-axis (sin, cos) pairs rot[0..2] (X, Y, Z), a scale and a translation, as fixed point.
void func_800A6780(Mtx* m, Vec2f* rot, Vec3f* scaleIn, Vec3f* transIn) {
    s32 e00;
    s32 e01;
    s32 e02;
    s32 e10;
    s32 e11;
    s32 e12;
    s32 e20;
    s32 e21;
    s32 e22;
    s32 e30;
    s32 e31;
    s32 e32;
    Vec2f* rx;
    Vec2f* ry;
    Vec2f* rz;
    Vec3f scale;
    Vec3f trans;

    rx = rot;
    ry = rot + 1;
    rz = rot + 2;
    scale = *scaleIn;
    trans = *transIn;
    e00 = HU_FTOFIX32(ry->y * rz->y * scale.x);
    e01 = HU_FTOFIX32(ry->y * rz->x * scale.y);
    e02 = HU_FTOFIX32(-ry->x * scale.z);
    e10 = HU_FTOFIX32((rx->x * ry->x * rz->y - rx->y * rz->x) * scale.x);
    e11 = HU_FTOFIX32((rx->x * ry->x * rz->x + rx->y * rz->y) * scale.y);
    e12 = HU_FTOFIX32(rx->x * ry->y * scale.z);
    e20 = HU_FTOFIX32((rx->y * ry->x * rz->y + rx->x * rz->x) * scale.x);
    e21 = HU_FTOFIX32((rx->y * ry->x * rz->x - rx->x * rz->y) * scale.y);
    e22 = HU_FTOFIX32(rx->y * ry->y * scale.z);
    e30 = HU_FTOFIX32(trans.x);
    e31 = HU_FTOFIX32(trans.y);
    e32 = HU_FTOFIX32(trans.z);
    m->m[0][0] = (e00 & 0xFFFF0000) | ((e01 >> 16) & 0xFFFF);
    m->m[0][1] = e02 & 0xFFFF0000;
    m->m[0][2] = (e10 & 0xFFFF0000) | ((e11 >> 16) & 0xFFFF);
    m->m[0][3] = e12 & 0xFFFF0000;
    m->m[1][0] = (e20 & 0xFFFF0000) | ((e21 >> 16) & 0xFFFF);
    m->m[1][1] = e22 & 0xFFFF0000;
    m->m[1][2] = (e30 & 0xFFFF0000) | ((e31 >> 16) & 0xFFFF);
    m->m[1][3] = (e32 & 0xFFFF0000) | 1;
    m->m[2][0] = ((e00 << 16) & 0xFFFF0000) | (u16)e01;
    m->m[2][1] = (e02 << 16) & 0xFFFF0000;
    m->m[2][2] = ((e10 << 16) & 0xFFFF0000) | (u16)e11;
    m->m[2][3] = (e12 << 16) & 0xFFFF0000;
    m->m[3][0] = ((e20 << 16) & 0xFFFF0000) | (u16)e21;
    m->m[3][1] = (e22 << 16) & 0xFFFF0000;
    m->m[3][2] = ((e30 << 16) & 0xFFFF0000) | (u16)e31;
    m->m[3][3] = (e32 << 16) & 0xFFFF0000;
}

// Rotation matrix that looks along dir (normalised here) with a roll of angle (degrees); no-op for
// a zero dir. Rows 0..2 are the frame, the translation is 0.
void func_800A6C80(Matrix4f m, f32 angle, Vec3f* dir) {
    f32 s;
    f32 c;
    f32 xz;
    f32 invXz;
    f32 len;
    f32 x;
    f32 y;
    f32 z;

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
        m[0][0] = (-z * c - s * y * x) * invXz;
        m[1][0] = (z * s - c * y * x) * invXz;
        m[2][0] = -x;
        m[0][1] = s * xz;
        m[1][1] = c * xz;
        m[2][1] = -y;
        m[0][2] = (c * x - s * y * z) * invXz;
        m[1][2] = (-s * x - c * y * z) * invXz;
        m[2][2] = -z;
    } else {
        m[0][0] = c;
        m[1][0] = -s;
        m[2][0] = 0.0f;
        m[0][1] = 0.0f;
        m[1][1] = 0.0f;
        m[2][1] = -y;
        m[0][2] = s * y;
        m[1][2] = c * y;
        m[2][2] = 0.0f;
    }
    m[3][0] = 0;
    m[3][1] = 0;
    m[3][2] = 0;
    m[0][3] = 0;
    m[1][3] = 0;
    m[2][3] = 0;
    m[3][3] = 1.0f;
}
