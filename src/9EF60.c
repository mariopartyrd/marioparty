#include "sdk_hu1.h"

/* guRotate (Hudson): the fixed-point matrix built directly; angle to the sin/cos helper as given. */
void func_8009E360(Mtx* m, f32 a, f32 x, f32 y, f32 z) {
    f32 s;
    f32 c;
    f32 xx;
    f32 yy;
    f32 zz;
    f32 t;
    f32 xy;
    f32 yz;
    f32 zx;
    s32 e1;
    s32 e2;
    s32 e3;

    t = 1.0f / func_800B1750(x * x + y * y + z * z);
    x *= t;
    y *= t;
    z *= t;
    xx = x * x;
    yy = y * y;
    zz = z * z;
    func_800AF2E0(a, &s, &c);
    t = 1.0f - c;
    xy = x * y * t;
    yz = y * z * t;
    zx = z * x * t;
    x *= s;
    y *= s;
    z *= s;
    e1 = ((1.0f - xx) * c + xx) * 65536.0f;
    e2 = (xy + z) * 65536.0f;
    e3 = (zx - y) * 65536.0f;
    m->m[0][0] = (e1 & 0xFFFF0000) | ((e2 >> 16) & 0xFFFF);
    m->m[0][1] = e3 & 0xFFFF0000;
    m->m[2][0] = ((e1 << 16) & 0xFFFF0000) | (e2 & 0xFFFF);
    m->m[2][1] = (e3 << 16) & 0xFFFF0000;
    e1 = (xy - z) * 65536.0f;
    e2 = ((1.0f - yy) * c + yy) * 65536.0f;
    e3 = (yz + x) * 65536.0f;
    m->m[0][2] = (e1 & 0xFFFF0000) | ((e2 >> 16) & 0xFFFF);
    m->m[0][3] = e3 & 0xFFFF0000;
    m->m[2][2] = ((e1 << 16) & 0xFFFF0000) | (e2 & 0xFFFF);
    m->m[2][3] = (e3 << 16) & 0xFFFF0000;
    e1 = (zx + y) * 65536.0f;
    e2 = (yz - x) * 65536.0f;
    e3 = ((1.0f - zz) * c + zz) * 65536.0f;
    m->m[1][0] = (e1 & 0xFFFF0000) | ((e2 >> 16) & 0xFFFF);
    m->m[1][1] = e3 & 0xFFFF0000;
    m->m[3][0] = ((e1 << 16) & 0xFFFF0000) | (e2 & 0xFFFF);
    m->m[3][1] = (e3 << 16) & 0xFFFF0000;
    m->m[1][3] = 1;
    m->m[1][2] = m->m[3][2] = m->m[3][3] = 0;
}
