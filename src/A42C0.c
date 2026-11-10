#include "common.h"

/* guRotate (Hudson) from a precomputed {sin, cos}, straight to the fixed-point matrix */
void func_800A36C0(Mtx* m, Vec2f* sc, Vec3f* axis) {
    f32 xx;
    f32 yy;
    f32 zz;
    f32 t;
    f32 ab;
    f32 bc;
    f32 ca;
    s32 e1;
    s32 e2;
    s32 e3;
    Vec3f n;

    t = 1.0f / func_800B1750(axis->x * axis->x + axis->y * axis->y + axis->z * axis->z);
    n.x = t * axis->x;
    n.y = t * axis->y;
    n.z = t * axis->z;
    xx = n.x * n.x;
    yy = n.y * n.y;
    zz = n.z * n.z;
    t = 1.0f - sc->y;
    ab = n.x * n.y * t;
    bc = n.y * n.z * t;
    ca = n.z * n.x * t;
    n.x *= sc->x;
    n.y *= sc->x;
    n.z *= sc->x;
    e1 = (sc->y * (1.0f - xx) + xx) * 65536.0f;
    e2 = (ab + n.z) * 65536.0f;
    e3 = (ca - n.y) * 65536.0f;
    m->m[0][0] = (e1 & 0xFFFF0000) | ((e2 >> 16) & 0xFFFF);
    m->m[0][1] = e3 & 0xFFFF0000;
    m->m[2][0] = ((e1 << 16) & 0xFFFF0000) | (e2 & 0xFFFF);
    m->m[2][1] = (e3 << 16) & 0xFFFF0000;
    e1 = (ab - n.z) * 65536.0f;
    e2 = (sc->y * (1.0f - yy) + yy) * 65536.0f;
    e3 = (bc + n.x) * 65536.0f;
    m->m[0][2] = (e1 & 0xFFFF0000) | ((e2 >> 16) & 0xFFFF);
    m->m[0][3] = e3 & 0xFFFF0000;
    m->m[2][2] = ((e1 << 16) & 0xFFFF0000) | (e2 & 0xFFFF);
    m->m[2][3] = (e3 << 16) & 0xFFFF0000;
    e1 = (ca + n.y) * 65536.0f;
    e2 = (bc - n.x) * 65536.0f;
    e3 = (sc->y * (1.0f - zz) + zz) * 65536.0f;
    m->m[1][0] = (e1 & 0xFFFF0000) | ((e2 >> 16) & 0xFFFF);
    m->m[1][1] = e3 & 0xFFFF0000;
    m->m[3][0] = ((e1 << 16) & 0xFFFF0000) | (e2 & 0xFFFF);
    m->m[3][1] = (e3 << 16) & 0xFFFF0000;
    m->m[1][3] = 1;
    m->m[1][2] = m->m[3][2] = m->m[3][3] = 0;
}
