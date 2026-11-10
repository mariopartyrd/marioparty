#include "common.h"

void func_800AF2E0(f32, f32*, f32*);

/* guRotateRPYF (Hudson): rpy in the angle units func_800AF2E0 takes */
void func_800A50A0(Matrix4f m, Vec3f* rpy) {
    f32 sr;
    f32 cr;
    f32 sp;
    f32 cp;
    f32 sh;
    f32 ch;

    func_800AF2E0(rpy->x, &sr, &cr);
    func_800AF2E0(rpy->y, &sp, &cp);
    func_800AF2E0(rpy->z, &sh, &ch);
    m[0][0] = cp * ch;
    m[0][1] = cp * sh;
    m[0][2] = -sp;
    m[1][0] = sr * sp * ch - cr * sh;
    m[1][1] = sr * sp * sh + cr * ch;
    m[1][2] = sr * cp;
    m[2][0] = cr * sp * ch + sr * sh;
    m[2][1] = cr * sp * sh - sr * ch;
    m[2][2] = cr * cp;
    m[0][3] = m[1][3] = m[2][3] = m[3][0] = m[3][1] = m[3][2] = 0.0f;
    m[3][3] = 1.0f;
}
