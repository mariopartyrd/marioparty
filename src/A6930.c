#include "common.h"

void func_800AF2E0(f32, f32*, f32*);

/* guPositionF (Hudson): rotation, then scale per axis, then translation */
void func_800A5D30(Matrix4f m, Vec3f* rpy, Vec3f* s, Vec3f* t) {
    f32 sr;
    f32 cr;
    f32 sp;
    f32 cp;
    f32 sh;
    f32 ch;

    func_800AF2E0(rpy->x, &sr, &cr);
    func_800AF2E0(rpy->y, &sp, &cp);
    func_800AF2E0(rpy->z, &sh, &ch);
    m[0][0] = s->x * (cp * ch);
    m[0][1] = s->y * (cp * sh);
    m[0][2] = s->z * -sp;
    m[0][3] = 0.0f;
    m[1][0] = s->x * (sr * sp * ch - cr * sh);
    m[1][1] = s->y * (sr * sp * sh + cr * ch);
    m[1][2] = s->z * (sr * cp);
    m[1][3] = 0.0f;
    m[2][0] = s->x * (cr * sp * ch + sr * sh);
    m[2][1] = s->y * (cr * sp * sh - sr * ch);
    m[2][2] = s->z * (cr * cp);
    m[2][3] = 0.0f;
    m[3][0] = t->x;
    m[3][1] = t->y;
    m[3][2] = t->z;
    m[3][3] = 1.0f;
}
