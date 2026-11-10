#include "common.h"

void func_800AF2E0(f32, f32*, f32*);

/* guPosition (Hudson) */
void func_800A5FD0(Mtx* m, Vec3f* rpy, Vec3f* s, Vec3f* t) {
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

    func_800AF2E0(rpy->x, &sr, &cr);
    func_800AF2E0(rpy->y, &sp, &cp);
    func_800AF2E0(rpy->z, &sh, &ch);
    e00 = s->x * (cp * ch) * 65536.0f;
    e01 = s->y * (cp * sh) * 65536.0f;
    e02 = s->z * -sp * 65536.0f;
    e10 = s->x * (sr * sp * ch - cr * sh) * 65536.0f;
    e11 = s->y * (sr * sp * sh + cr * ch) * 65536.0f;
    e12 = s->z * (sr * cp) * 65536.0f;
    e20 = s->x * (cr * sp * ch + sr * sh) * 65536.0f;
    e21 = s->y * (cr * sp * sh - sr * ch) * 65536.0f;
    e22 = s->z * (cr * cp) * 65536.0f;
    e30 = t->x * 65536.0f;
    e31 = t->y * 65536.0f;
    e32 = t->z * 65536.0f;
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
