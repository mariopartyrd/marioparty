#include "sdk_hu1.h"

/* guScaleF (Hudson) */
void func_8009E7E0(Matrix4f mf, f32 x, f32 y, f32 z) {
    mf[0][0] = x;
    mf[1][1] = y;
    mf[2][2] = z;
    mf[3][3] = 1.0f;
    mf[0][1] = mf[0][2] = mf[0][3] = mf[1][0] = mf[1][2] = mf[1][3] = mf[2][0] = mf[2][1] = mf[2][3] =
        mf[3][0] = mf[3][1] = mf[3][2] = 0.0f;
}
