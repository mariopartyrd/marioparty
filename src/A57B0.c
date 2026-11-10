#include "common.h"

/* guScaleF (Hudson) */
void func_800A4BB0(Matrix4f m, Vec3f* s) {
    m[0][0] = s->x;
    m[1][1] = s->y;
    m[2][2] = s->z;
    m[3][3] = 1.0f;
    m[0][1] = m[0][2] = m[0][3] = m[1][0] = m[1][2] = m[1][3] = m[2][0] = m[2][1] = m[2][3] = m[3][0] = m[3][1] =
        m[3][2] = 0.0f;
}
