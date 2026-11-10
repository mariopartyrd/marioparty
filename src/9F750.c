#include "common.h"

/* guTranslate (Hudson): the fixed-point matrix built directly. */
void func_8009EB50(Mtx* m, f32 x, f32 y, f32 z) {
    s32 e1;
    s32 e2;
    s32 e3;

    e1 = x * 65536.0f;
    e2 = y * 65536.0f;
    e3 = z * 65536.0f;
    m->m[0][0] = 0x10000;
    m->m[0][1] = 0;
    m->m[0][2] = 1;
    m->m[0][3] = 0;
    m->m[1][0] = 0;
    m->m[1][1] = 0x10000;
    m->m[1][2] = (e1 & 0xFFFF0000) | ((e2 >> 16) & 0xFFFF);
    m->m[1][3] = (e3 & 0xFFFF0000) | 1;
    m->m[2][0] = 0;
    m->m[2][1] = 0;
    m->m[2][2] = 0;
    m->m[2][3] = 0;
    m->m[3][0] = 0;
    m->m[3][1] = 0;
    m->m[3][2] = ((e1 << 16) & 0xFFFF0000) | (u16)e2;
    m->m[3][3] = (e3 << 16) & 0xFFFF0000;
}

void func_800AF2E0(f32, f32*, f32*);

void func_8009ECB0(Matrix4f m, f32 x, f32 y, f32 z) {
    f32 sx;
    f32 cx;
    f32 sy;
    f32 cy;
    f32 sz;
    f32 cz;

    func_800AF2E0(x, &sx, &cx);
    func_800AF2E0(y, &sy, &cy);
    func_800AF2E0(z, &sz, &cz);
    m[0][0] = cy * cz;
    m[0][1] = cy * sz;
    m[0][2] = -sy;
    m[1][0] = sx * sy * cz - cx * sz;
    m[1][1] = sx * sy * sz + cx * cz;
    m[1][2] = sx * cy;
    m[2][0] = cx * sy * cz + sx * sz;
    m[2][1] = cx * sy * sz - sx * cz;
    m[2][2] = cx * cy;
    m[0][3] = m[1][3] = m[2][3] = m[3][0] = m[3][1] = m[3][2] = 0.0f;
    m[3][3] = 1.0f;
}
/* guRotateRPY (Hudson): the fixed-point matrix built directly; m is an Mtx seen as its integer
   halves [0] and fraction halves [1]. */
void func_8009EEC0(s16 m[2][4][4], f32 r, f32 p, f32 h) {
    f32 sx;
    f32 cx;
    f32 sy;
    f32 cy;
    f32 sz;
    f32 cz;
    s32 e1;
    s32 e2;

    func_800AF2E0(r, &sx, &cx);
    func_800AF2E0(p, &sy, &cy);
    func_800AF2E0(h, &sz, &cz);
    e1 = cy * cz * 65536.0f;
    e2 = cy * sz * 65536.0f;
    m[0][0][0] = e1 >> 16;
    m[0][0][1] = e2 >> 16;
    m[1][0][0] = (u16)e1;
    m[1][0][1] = (u16)e2;
    e1 = -sy * 65536.0f;
    m[0][0][2] = e1 >> 16;
    m[0][0][3] = 0;
    m[1][0][2] = (u16)e1;
    m[1][0][3] = 0;
    e1 = (sx * sy * cz - cx * sz) * 65536.0f;
    e2 = (sx * sy * sz + cx * cz) * 65536.0f;
    m[0][1][0] = e1 >> 16;
    m[0][1][1] = e2 >> 16;
    m[1][1][0] = (u16)e1;
    m[1][1][1] = (u16)e2;
    e1 = sx * cy * 65536.0f;
    m[0][1][2] = e1 >> 16;
    m[0][1][3] = 0;
    m[1][1][2] = (u16)e1;
    m[1][1][3] = 0;
    e1 = (cx * sy * cz + sx * sz) * 65536.0f;
    e2 = (cx * sy * sz - sx * cz) * 65536.0f;
    m[0][2][0] = e1 >> 16;
    m[0][2][1] = e2 >> 16;
    m[1][2][0] = (u16)e1;
    m[1][2][1] = (u16)e2;
    e1 = cx * cy * 65536.0f;
    m[0][2][2] = e1 >> 16;
    m[0][2][3] = 0;
    m[1][2][2] = (u16)e1;
    m[1][2][3] = 0;
    m[0][3][0] = 0;
    m[0][3][1] = 0;
    m[1][3][0] = 0;
    m[1][3][1] = 0;
    m[0][3][2] = 0;
    m[0][3][3] = 1;
    m[1][3][2] = 0;
    m[1][3][3] = 0;
}
