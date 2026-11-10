#include "common.h"

void func_800AF2E0(f32, f32*, f32*);

/* guMtxIdentF */
void func_800A2A50(Matrix4f mf) {
    mf[0][0] = mf[1][1] = mf[2][2] = mf[3][3] = 1.0f;
    mf[0][1] = mf[0][2] = mf[0][3] = mf[1][0] = mf[1][2] = mf[1][3] = mf[2][0] = mf[2][1] = mf[2][3] = mf[3][0] =
        mf[3][1] = mf[3][2] = 0.0f;
}

/* guMtxIdent */
void func_800A2B40(Mtx* m) {
    m->m[0][1] = m->m[0][3] = m->m[1][0] = m->m[1][2] = m->m[2][0] = m->m[2][1] = m->m[2][2] = m->m[2][3] =
        m->m[3][0] = m->m[3][1] = m->m[3][2] = m->m[3][3] = 0;
    m->m[0][0] = m->m[1][1] = 0x10000;
    m->m[0][2] = m->m[1][3] = 1;
}

/* guRotateF (Hudson): angle through func_800AF2E0 (sin, cos), any axis */
void func_800A2BF0(Matrix4f mf, f32 a, Vec3f* axis) {
    f32 sine;
    f32 cosine;
    f32 xx;
    f32 yy;
    f32 zz;
    f32 ab;
    f32 bc;
    f32 ca;
    f32 t;
    Vec3f n;

    t = 1.0f / func_800B1750(axis->x * axis->x + axis->y * axis->y + axis->z * axis->z);
    n.x = t * axis->x;
    n.y = t * axis->y;
    n.z = t * axis->z;
    xx = n.x * n.x;
    yy = n.y * n.y;
    zz = n.z * n.z;
    func_800AF2E0(a, &sine, &cosine);
    t = 1.0f - cosine;
    ab = n.x * n.y * t;
    bc = n.y * n.z * t;
    ca = n.z * n.x * t;
    n.x *= sine;
    n.y *= sine;
    n.z *= sine;
    mf[0][0] = xx + (1.0f - xx) * cosine;
    mf[2][1] = bc - n.x;
    mf[1][2] = bc + n.x;
    mf[1][1] = yy + (1.0f - yy) * cosine;
    mf[2][0] = ca + n.y;
    mf[0][2] = ca - n.y;
    mf[2][2] = zz + (1.0f - zz) * cosine;
    mf[1][0] = ab - n.z;
    mf[0][1] = ab + n.z;
    mf[0][3] = mf[1][3] = mf[2][3] = mf[3][0] = mf[3][1] = mf[3][2] = 0.0f;
    mf[3][3] = 1.0f;
}
