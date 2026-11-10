#include "sdk_hu1.h"

/* guPosition (Hudson): the fixed-point matrix built directly; angles to the sin/cos helper. */
void func_8009F530(Mtx* m, f32 r, f32 p, f32 h, f32 s, f32 x, f32 y, f32 z) {
    f32 sr;
    f32 cr;
    f32 sp;
    f32 cp;
    f32 sh;
    f32 ch;
    s32 e00;
    s32 e01;
    s32 e02;
    s32 e10;
    s32 e11;
    s32 e12;
    s32 e20;
    s32 e21;
    s32 e22;
    s32 e30;
    s32 e31;
    s32 e32;

    func_800AF2E0(r, &sr, &cr);
    func_800AF2E0(p, &sp, &cp);
    func_800AF2E0(h, &sh, &ch);
    e00 = cp * ch * s * 65536.0f;
    e01 = cp * sh * s * 65536.0f;
    e02 = -sp * s * 65536.0f;
    e10 = (sr * sp * ch - cr * sh) * s * 65536.0f;
    e11 = (sr * sp * sh + cr * ch) * s * 65536.0f;
    e12 = sr * cp * s * 65536.0f;
    e20 = (cr * sp * ch + sr * sh) * s * 65536.0f;
    e21 = (cr * sp * sh - sr * ch) * s * 65536.0f;
    e22 = cr * cp * s * 65536.0f;
    e30 = x * 65536.0f;
    e31 = y * 65536.0f;
    e32 = z * 65536.0f;
    m->m[0][0] = (e00 & 0xFFFF0000) | ((e01 >> 16) & 0xFFFF);
    m->m[0][1] = e02 & 0xFFFF0000;
    m->m[0][2] = (e10 & 0xFFFF0000) | ((e11 >> 16) & 0xFFFF);
    m->m[0][3] = e12 & 0xFFFF0000;
    m->m[1][0] = (e20 & 0xFFFF0000) | ((e21 >> 16) & 0xFFFF);
    m->m[1][1] = e22 & 0xFFFF0000;
    m->m[1][2] = (e30 & 0xFFFF0000) | ((e31 >> 16) & 0xFFFF);
    m->m[1][3] = (e32 & 0xFFFF0000) | 1;
    m->m[2][0] = ((e00 << 16) & 0xFFFF0000) | (u16)e01;
    m->m[2][1] = (e02 << 16) & 0xFFFF0000;
    m->m[2][2] = ((e10 << 16) & 0xFFFF0000) | (u16)e11;
    m->m[2][3] = (e12 << 16) & 0xFFFF0000;
    m->m[3][0] = ((e20 << 16) & 0xFFFF0000) | (u16)e21;
    m->m[3][1] = (e22 << 16) & 0xFFFF0000;
    m->m[3][2] = ((e30 << 16) & 0xFFFF0000) | (u16)e31;
    m->m[3][3] = (e32 << 16) & 0xFFFF0000;
}
