#include "sdk_hu1.h"

/* guPerspectiveF (Hudson): fovy goes to the sin/cos helper halved; scale folded in. */
void func_8009DD90(Matrix4f mf, u16* perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale) {
    f32 cot;
    f32 nf;
    f32 sum;
    f32 s;
    f32 c;

    func_800AF2E0(fovy * 0.5f, &s, &c);
    cot = (c / s) * scale;
    nf = scale / (near - far);
    sum = near + far;
    mf[0][0] = cot / aspect;
    mf[1][1] = cot;
    mf[2][2] = sum * nf;
    mf[2][3] = -scale;
    mf[3][2] = 2.0f * near * far * nf;
    mf[0][1] = mf[0][2] = mf[0][3] = mf[1][0] = mf[1][2] = mf[1][3] = mf[2][0] = mf[2][1] = mf[3][0] =
        mf[3][1] = mf[3][3] = 0.0f;
    if (perspNorm != NULL) {
        if (sum <= 2.0f) {
            *perspNorm = 0xFFFF;
        } else {
            *perspNorm = 131072.0f / sum;
            if (*perspNorm == 0) {
                *perspNorm = 1;
            }
        }
    }
}
