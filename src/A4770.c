#include "common.h"

void func_800AF2E0(f32, f32*, f32*);

/* rotation about X (float) */
void func_800A3B70(Matrix4f m, f32 angle) {
    func_800AF2E0(angle, &m[1][2], &m[1][1]);
    m[2][1] = -m[1][2];
    m[2][2] = m[1][1];
    m[0][1] = m[0][2] = m[0][3] = m[1][0] = m[1][3] = m[2][0] = m[2][3] = m[3][0] = m[3][1] = m[3][2] = 0.0f;
    m[0][0] = m[3][3] = 1.0f;
}

/* rotation about X (fixed point) */
void func_800A3C90(Mtx* m, f32 angle) {
    f32 sine;
    f32 cosine;

    func_800AF2E0(angle, &sine, &cosine);
    m->m[1][1] = cosine * 65536.0f;
    m->m[3][0] = -(m->m[0][3] = sine * 65536.0f);
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

/* rotation about X from {sin, cos} (float) */
void func_800A3E30(Matrix4f m, Vec2f* sc) {
    m[0][0] = m[3][3] = 1.0f;
    m[2][1] = -(m[1][2] = sc->x);
    m[1][1] = m[2][2] = sc->y;
    m[0][1] = m[0][2] = m[0][3] = m[1][0] = m[1][3] = m[2][0] = m[2][3] = m[3][0] = m[3][1] = m[3][2] = 0.0f;
}
