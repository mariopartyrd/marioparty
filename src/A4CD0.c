#include "common.h"

void func_800AF2E0(f32, f32*, f32*);

/* rotation about Y: sin/cos into m[2][0] / m[2][2] */
void func_800A40D0(Matrix4f m, f32 angle) {
    func_800AF2E0(angle, &m[2][0], &m[2][2]);
    m[0][2] = -m[2][0];
    m[0][0] = m[2][2];
    m[0][1] = m[0][3] = m[1][0] = m[1][2] = m[1][3] = m[2][1] = m[2][3] = m[3][0] = m[3][1] = m[3][2] = 0.0f;
    m[1][1] = m[3][3] = 1.0f;
}

/* rotation about Z (fixed point) */
void func_800A41F0(Mtx* m, f32 angle) {
    f32 sine;
    f32 cosine;

    func_800AF2E0(angle, &sine, &cosine);
    m->m[0][0] = cosine * 65536.0f;
    m->m[0][1] = -(m->m[1][0] = sine * 65536.0f);
    m->m[2][0] = (m->m[0][0] << 16) & 0xFFFF0000;
    m->m[2][1] = (m->m[0][1] << 16) & 0xFFFF0000;
    m->m[1][1] = m->m[0][0] & 0xFFFF0000;
    m->m[3][0] = (m->m[1][0] << 16) & 0xFFFF0000;
    m->m[3][1] = (m->m[0][0] << 16) & 0xFFFF0000;
    m->m[1][0] &= 0xFFFF0000;
    m->m[0][0] &= 0xFFFF0000;
    m->m[0][1] &= 0xFFFF0000;
    m->m[0][2] = m->m[1][3] = 1;
    m->m[0][3] = m->m[2][2] = m->m[2][3] = m->m[1][2] = m->m[3][2] = m->m[3][3] = 0;
}

/* rotation about Y from {sin, cos} (float) */
void func_800A43A0(Matrix4f m, Vec2f* sc) {
    m[0][0] = m[2][2] = sc->y;
    m[0][2] = -(m[2][0] = sc->x);
    m[1][1] = m[3][3] = 1.0f;
    m[0][1] = m[0][3] = m[1][0] = m[1][2] = m[1][3] = m[2][1] = m[2][3] = m[3][0] = m[3][1] = m[3][2] = 0.0f;
}
