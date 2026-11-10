#include "common.h"

/* guRotateF (Hudson) from a precomputed {sin, cos}; leaves mf[3][3] alone */
void func_800A33B0(Matrix4f mf, Vec2f* sc, Vec3f* axis) {
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
    t = 1.0f - sc->y;
    ab = n.x * n.y * t;
    bc = n.y * n.z * t;
    ca = n.z * n.x * t;
    n.x *= sc->x;
    n.y *= sc->x;
    n.z *= sc->x;
    mf[0][0] = xx + sc->y * (1.0f - xx);
    mf[2][1] = bc - n.x;
    mf[1][2] = bc + n.x;
    mf[1][1] = yy + sc->y * (1.0f - yy);
    mf[2][0] = ca + n.y;
    mf[0][2] = ca - n.y;
    mf[2][2] = zz + sc->y * (1.0f - zz);
    mf[1][0] = ab - n.z;
    mf[0][1] = ab + n.z;
    mf[0][3] = mf[1][3] = mf[2][3] = mf[3][0] = mf[3][1] = mf[3][2] = 0.0f;
}
