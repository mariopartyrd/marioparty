#include "sdk_hu1.h"

/* guPositionF (Hudson): angles go to the sin/cos helper as given. */
void func_8009F2D0(Matrix4f mf, f32 r, f32 p, f32 h, f32 s, f32 x, f32 y, f32 z) {
    f32 sr;
    f32 cr;
    f32 sp;
    f32 cp;
    f32 sh;
    f32 ch;

    func_800AF2E0(r, &sr, &cr);
    func_800AF2E0(p, &sp, &cp);
    func_800AF2E0(h, &sh, &ch);
    mf[0][0] = s * (cp * ch);
    mf[0][1] = s * (cp * sh);
    mf[0][2] = s * -sp;
    mf[0][3] = 0.0f;
    mf[1][0] = s * (sr * sp * ch - cr * sh);
    mf[1][1] = s * (sr * sp * sh + cr * ch);
    mf[1][2] = s * (sr * cp);
    mf[1][3] = 0.0f;
    mf[2][0] = s * (cr * sp * ch + sr * sh);
    mf[2][1] = s * (cr * sp * sh - sr * ch);
    mf[2][2] = s * (cr * cp);
    mf[2][3] = 0.0f;
    mf[3][0] = x;
    mf[3][1] = y;
    mf[3][2] = z;
    mf[3][3] = 1.0f;
}
