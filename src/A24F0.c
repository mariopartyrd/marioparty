#include "common.h"
#include "sdk_hu2.h"

void func_800A0E80(Vec3f*, Vec3f*, Vec3f*);
void func_800A1250(Vec3f*);
void func_800A14F0(Vec3f*, Vec3f*, Vec3f*);

/* guLookAtF (Hudson): p = {eye, at, up}, tmp = three scratch axes */
void func_800A18F0(Matrix4f mf, Vec3f* p, Vec3f* tmp) {
    func_800A0E80(&tmp[2], &p[0], &p[1]);
    func_800A1250(&tmp[2]);
    func_800A14F0(&tmp[0], &p[2], &tmp[2]);
    func_800A1250(&tmp[0]);
    func_800A14F0(&tmp[1], &tmp[2], &tmp[0]);
    func_800A1250(&tmp[1]);
    mf[0][0] = tmp[0].x;
    mf[1][0] = tmp[0].y;
    mf[2][0] = tmp[0].z;
    mf[3][0] = -(p[0].x * tmp[0].x + p[0].y * tmp[0].y + p[0].z * tmp[0].z);
    mf[0][1] = tmp[1].x;
    mf[1][1] = tmp[1].y;
    mf[2][1] = tmp[1].z;
    mf[3][1] = -(p[0].x * tmp[1].x + p[0].y * tmp[1].y + p[0].z * tmp[1].z);
    mf[0][2] = tmp[2].x;
    mf[1][2] = tmp[2].y;
    mf[2][2] = tmp[2].z;
    mf[3][2] = -(p[0].x * tmp[2].x + p[0].y * tmp[2].y + p[0].z * tmp[2].z);
    mf[0][3] = mf[1][3] = mf[2][3] = 0.0f;
    mf[3][3] = 1.0f;
}
