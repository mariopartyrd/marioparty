#include "sdk_hu1.h"

/* guAlignF (Hudson): returns early on a zero vector; angle to the sin/cos helper as given. */
void func_8009F9B0(Matrix4f mf, f32 a, f32 x, f32 y, f32 z) {
    f32 s;
    f32 c;
    f32 h;
    f32 ih;
    f32 len;

    len = func_800B1750(x * x + y * y + z * z);
    if (len == 0.0f) {
        return;
    }
    len = 1.0f / len;
    x *= len;
    y *= len;
    z *= len;
    h = func_800B1750(x * x + z * z);
    func_800AF2E0(a, &s, &c);
    if (h != 0.0f) {
        ih = 1.0f / h;
        mf[0][0] = (-z * c - s * y * x) * ih;
        mf[1][0] = (z * s - c * y * x) * ih;
        mf[2][0] = -x;
        mf[0][1] = s * h;
        mf[1][1] = c * h;
        mf[2][1] = -y;
        mf[0][2] = (c * x - s * y * z) * ih;
        mf[1][2] = (-s * x - c * y * z) * ih;
        mf[2][2] = -z;
    } else {
        mf[0][0] = c;
        mf[1][0] = -s;
        mf[2][0] = 0.0f;
        mf[0][1] = 0.0f;
        mf[1][1] = 0.0f;
        mf[2][1] = -y;
        mf[0][2] = s * y;
        mf[1][2] = c * y;
        mf[2][2] = 0.0f;
    }
    mf[3][0] = 0.0f;
    mf[3][1] = 0.0f;
    mf[3][2] = 0.0f;
    mf[0][3] = 0.0f;
    mf[1][3] = 0.0f;
    mf[2][3] = 0.0f;
    mf[3][3] = 1.0f;
}
