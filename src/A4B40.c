#include "common.h"

/* rotation about X from {sin, cos} (fixed point) */
void func_800A3F40(Mtx* m, Vec2f* sc) {
    m->m[1][1] = sc->y * 65536.0f;
    m->m[3][0] = -(m->m[0][3] = sc->x * 65536.0f);
    m->m[1][0] = (m->m[3][0] >> 16) & 0xFFFF;
    m->m[3][1] = (m->m[1][1] << 16) & 0xFFFF0000;
    m->m[0][2] = (m->m[1][1] >> 16) & 0xFFFF;
    m->m[2][2] = m->m[1][1] & 0xFFFF;
    m->m[2][3] = (m->m[0][3] << 16) & 0xFFFF0000;
    m->m[1][1] &= 0xFFFF0000;
    m->m[3][0] &= 0xFFFF;
    m->m[0][3] &= 0xFFFF0000;
    m->m[0][0] = 0x10000;
    m->m[1][3] = 1;
    m->m[0][1] = m->m[2][0] = m->m[2][1] = m->m[1][2] = m->m[3][2] = m->m[3][3] = 0;
}
