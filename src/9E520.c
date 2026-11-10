#include "sdk_hu1.h"

/* guOrthoF (Hudson): scale folded into the reciprocals. */
void func_8009D920(Matrix4f mf, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f, f32 scale) {
    f32 rl;
    f32 tb;
    f32 fn;

    rl = scale / (l - r);
    tb = scale / (b - t);
    fn = scale / (n - f);
    mf[0][0] = rl * -2.0f;
    mf[1][1] = tb * -2.0f;
    mf[2][2] = 2.0f * fn;
    mf[3][0] = (r + l) * rl;
    mf[3][1] = (t + b) * tb;
    mf[3][2] = (f + n) * fn;
    mf[3][3] = scale;
    mf[0][1] = mf[0][2] = mf[0][3] = mf[1][0] = mf[1][2] = mf[1][3] = mf[2][0] = mf[2][1] = mf[2][3] = 0.0f;
}
