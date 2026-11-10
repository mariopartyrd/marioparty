#include "sdk_hu1.h"

/* guAlign (Hudson): the fixed-point matrix built directly; returns early on a zero vector. */
void func_8009FD40(Mtx* m, f32 a, f32 x, f32 y, f32 z) {
    f32 s;
    f32 c;
    f32 h;
    f32 ih;
    f32 len;
    f32 unused; /* retail's frame has one more f32 slot here */
    s32 e00;
    s32 e01;
    s32 e02;
    s32 e10;
    s32 e11;
    s32 e12;
    s32 e20;
    s32 e21;
    s32 e22;

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
        e00 = (-z * c - s * y * x) * ih * 65536.0f;
        e01 = s * h * 65536.0f;
        e02 = (c * x - s * y * z) * ih * 65536.0f;
        e10 = (z * s - c * y * x) * ih * 65536.0f;
        e11 = c * h * 65536.0f;
        e12 = (-s * x - c * y * z) * ih * 65536.0f;
        e20 = -x * 65536.0f;
        e21 = -y * 65536.0f;
        e22 = -z * 65536.0f;
    } else {
        e00 = c * 65536.0f;
        e01 = 0;
        e02 = s * y * 65536.0f;
        e10 = -s * 65536.0f;
        e11 = 0;
        e12 = c * y * 65536.0f;
        e20 = 0;
        e21 = -y * 65536.0f;
        e22 = 0;
    }
    m->m[0][0] = (e00 & 0xFFFF0000) | ((e01 >> 16) & 0xFFFF);
    m->m[0][1] = e02 & 0xFFFF0000;
    m->m[0][2] = (e10 & 0xFFFF0000) | ((e11 >> 16) & 0xFFFF);
    m->m[0][3] = e12 & 0xFFFF0000;
    m->m[1][0] = (e20 & 0xFFFF0000) | ((e21 >> 16) & 0xFFFF);
    m->m[1][1] = e22 & 0xFFFF0000;
    m->m[1][2] = 0;
    m->m[1][3] = 1;
    m->m[2][0] = ((e00 << 16) & 0xFFFF0000) | (u16)e01;
    m->m[2][1] = (e02 << 16) & 0xFFFF0000;
    m->m[2][2] = ((e10 << 16) & 0xFFFF0000) | (u16)e11;
    m->m[2][3] = (e12 << 16) & 0xFFFF0000;
    m->m[3][0] = ((e20 << 16) & 0xFFFF0000) | (u16)e21;
    m->m[3][1] = (e22 << 16) & 0xFFFF0000;
    m->m[3][2] = 0;
    m->m[3][3] = 0;
}
