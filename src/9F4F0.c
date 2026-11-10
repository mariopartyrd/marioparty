#include "sdk_hu1.h"

/* guScale (Hudson): the fixed-point matrix built directly. */
void func_8009E8F0(Mtx* m, f32 x, f32 y, f32 z) {
    s32 e1;
    s32 e2;
    s32 e3;

    e1 = x * 65536.0f;
    e2 = y * 65536.0f;
    e3 = z * 65536.0f;
    m->m[0][0] = e1 & 0xFFFF0000;
    m->m[0][1] = 0;
    m->m[0][2] = (e2 >> 16) & 0xFFFF;
    m->m[0][3] = 0;
    m->m[1][0] = 0;
    m->m[1][1] = e3 & 0xFFFF0000;
    m->m[1][2] = 0;
    m->m[1][3] = 1;
    m->m[2][0] = (e1 << 16) & 0xFFFF0000;
    m->m[2][1] = 0;
    m->m[2][2] = e2 & 0xFFFF;
    m->m[2][3] = 0;
    m->m[3][0] = 0;
    m->m[3][1] = (e3 << 16) & 0xFFFF0000;
    m->m[3][2] = 0;
    m->m[3][3] = 0;
}

/* guTranslateF (Hudson) */
void func_8009EA40(Matrix4f mf, f32 x, f32 y, f32 z) {
    mf[3][0] = x;
    mf[3][1] = y;
    mf[3][2] = z;
    mf[0][0] = mf[1][1] = mf[2][2] = mf[3][3] = 1.0f;
    mf[0][1] = mf[0][2] = mf[0][3] = mf[1][0] = mf[1][2] = mf[1][3] = mf[2][0] = mf[2][1] = mf[2][3] = 0.0f;
}
