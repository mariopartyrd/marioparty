#include "common.h"

/* guTranslateF (Hudson) */
void func_800A4E20(Matrix4f m, Vec3f* t) {
    m[3][0] = t->x;
    m[3][1] = t->y;
    m[3][2] = t->z;
    m[0][0] = m[1][1] = m[2][2] = m[3][3] = 1.0f;
    m[0][1] = m[0][2] = m[0][3] = m[1][0] = m[1][2] = m[1][3] = m[2][0] = m[2][1] = m[2][3] = 0.0f;
}
