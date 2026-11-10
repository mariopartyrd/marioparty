#include "sdk_hu1.h"

/* guMtxXFMF */
void func_800A0270(Matrix4f mf, f32 x, f32 y, f32 z, f32* ox, f32* oy, f32* oz) {
    *ox = mf[0][0] * x + mf[1][0] * y + mf[2][0] * z + mf[3][0];
    *oy = mf[0][1] * x + mf[1][1] * y + mf[2][1] * z + mf[3][1];
    *oz = mf[0][2] * x + mf[1][2] * y + mf[2][2] * z + mf[3][2];
}
