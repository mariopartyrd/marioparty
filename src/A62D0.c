#include "common.h"
#include "sdk_hu2.h"

/* guRotateRPYF (Hudson) from precomputed sines and cosines */
void func_800A56D0(Matrix4f m, HuRPYSinCos* a) {
    m[0][0] = a->cp * a->ch;
    m[0][1] = a->cp * a->sh;
    m[0][2] = -a->sp;
    m[1][0] = a->sr * a->sp * a->ch - a->cr * a->sh;
    m[1][1] = a->sr * a->sp * a->sh + a->cr * a->ch;
    m[1][2] = a->sr * a->cp;
    m[2][0] = a->cr * a->sp * a->ch + a->sr * a->sh;
    m[2][1] = a->cr * a->sp * a->sh - a->sr * a->ch;
    m[2][2] = a->cr * a->cp;
    m[0][3] = m[1][3] = m[2][3] = m[3][0] = m[3][1] = m[3][2] = 0.0f;
    m[3][3] = 1.0f;
}

/* guRotateRPY (Hudson; m is the Mtx as halfwords: 16 integer parts, then 16 fractions) from precomputed sines and cosines */
void func_800A5900(u16* m, HuRPYSinCos* a) {
    s32 e1;
    s32 e2;

    e1 = a->cp * a->ch * 65536.0f;
    e2 = a->cp * a->sh * 65536.0f;
    *m = e1 >> 16;
    *(m + 1) = e2 >> 16;
    *(m + 16) = e1;
    *(m + 17) = e2;
    e1 = -a->sp * 65536.0f;
    *(m + 2) = e1 >> 16;
    *(m + 3) = 0;
    *(m + 18) = e1;
    *(m + 19) = 0;
    e1 = (a->sr * a->sp * a->ch - a->cr * a->sh) * 65536.0f;
    e2 = (a->sr * a->sp * a->sh + a->cr * a->ch) * 65536.0f;
    *(m + 4) = e1 >> 16;
    *(m + 5) = e2 >> 16;
    *(m + 20) = e1;
    *(m + 21) = e2;
    e1 = a->sr * a->cp * 65536.0f;
    *(m + 6) = e1 >> 16;
    *(m + 7) = 0;
    *(m + 22) = e1;
    *(m + 23) = 0;
    e1 = (a->cr * a->sp * a->ch + a->sr * a->sh) * 65536.0f;
    e2 = (a->cr * a->sp * a->sh - a->sr * a->ch) * 65536.0f;
    *(m + 8) = e1 >> 16;
    *(m + 9) = e2 >> 16;
    *(m + 24) = e1;
    *(m + 25) = e2;
    e1 = a->cr * a->cp * 65536.0f;
    *(m + 10) = e1 >> 16;
    *(m + 11) = 0;
    *(m + 26) = e1;
    *(m + 27) = 0;
    *(m + 12) = 0;
    *(m + 13) = 0;
    *(m + 28) = 0;
    *(m + 29) = 0;
    *(m + 14) = 0;
    *(m + 15) = 1;
    *(m + 30) = 0;
    *(m + 31) = 0;
}
