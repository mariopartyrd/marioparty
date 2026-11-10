#include "common.h"

void func_800AF2E0(f32, f32*, f32*);

/* rotation about Z (float) */
void func_800A4650(Matrix4f m, f32 angle) {
    func_800AF2E0(angle, &m[0][1], &m[0][0]);
    m[1][0] = -m[0][1];
    m[1][1] = m[0][0];
    m[0][2] = m[0][3] = m[1][3] = m[1][2] = m[2][0] = m[2][1] = m[2][3] = m[3][0] = m[3][1] = m[3][2] = 0.0f;
    m[2][2] = m[3][3] = 1.0f;
}
