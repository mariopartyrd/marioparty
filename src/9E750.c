#include "sdk_hu1.h"

/* guFrustumF (Hudson): scale folded into the reciprocals. */
void func_8009DB50(Matrix4f mf, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f, f32 scale) {
    f32 rl;
    f32 tb;
    f32 fn;
    f32 n2;

    rl = scale / (r - l);
    tb = scale / (t - b);
    fn = scale / (f - n);
    n2 = 2.0f * n;
    mf[0][0] = n2 * rl;
    mf[1][1] = n2 * tb;
    mf[2][0] = (r + l) * rl;
    mf[2][1] = (t + b) * tb;
    mf[2][2] = -(f + n) * fn;
    mf[2][3] = -scale;
    mf[3][2] = -f * n2 * fn;
    mf[0][1] = mf[0][2] = mf[0][3] = mf[1][0] = mf[1][2] = mf[1][3] = mf[3][0] = mf[3][1] = mf[3][3] = 0.0f;
}
