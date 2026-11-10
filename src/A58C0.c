#include "common.h"

/* guScale (Hudson) */
void func_800A4CC0(Mtx* m, Vec3f* s) {
    s32 e1;
    s32 e2;
    s32 e3;

    e1 = s->x * 65536.0f;
    e2 = s->y * 65536.0f;
    e3 = s->z * 65536.0f;
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
