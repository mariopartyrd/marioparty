#include "common.h"

void func_800AF2E0(f32 angle, f32* sine, f32* cosine);

/* Rotation matrix about an arbitrary axis (guRotateF without the degree conversion: the angle
   goes to func_800AF2E0, the sine/cosine pair). */
void func_8009E060(Matrix4f mf, f32 a, f32 x, f32 y, f32 z) {
    f32 sine;
    f32 cosine;
    f32 xx;
    f32 yy;
    f32 zz;
    f32 ab;
    f32 bc;
    f32 ca;
    f32 t;

    t = 1.0f / func_800B1750(x * x + y * y + z * z);
    x *= t;
    y *= t;
    z *= t;
    xx = x * x;
    yy = y * y;
    zz = z * z;
    func_800AF2E0(a, &sine, &cosine);
    t = 1.0f - cosine;
    ab = x * y * t;
    bc = y * z * t;
    ca = z * x * t;
    x *= sine;
    y *= sine;
    z *= sine;
    mf[0][0] = xx + (1.0f - xx) * cosine;
    mf[2][1] = bc - x;
    mf[1][2] = bc + x;
    mf[1][1] = yy + (1.0f - yy) * cosine;
    mf[2][0] = ca + y;
    mf[0][2] = ca - y;
    mf[2][2] = zz + (1.0f - zz) * cosine;
    mf[1][0] = ab - z;
    mf[0][1] = ab + z;
    mf[0][3] = mf[1][3] = mf[2][3] = mf[3][0] = mf[3][1] = mf[3][2] = 0.0f;
    mf[3][3] = 1.0f;
}
