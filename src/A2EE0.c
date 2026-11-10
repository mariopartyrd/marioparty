#include "common.h"
#include "sdk_hu2.h"

/* guOrthoF (Hudson) */
void func_800A22E0(Matrix4f mf, HuViewVolume* v) {
    f32 sx;
    f32 sy;
    f32 sz;

    sx = v->scale / (v->r - v->l);
    sy = v->scale / (v->t - v->b);
    sz = v->scale / (v->f - v->n);
    mf[0][0] = 2.0f * sx;
    mf[1][1] = 2.0f * sy;
    mf[2][2] = -2.0f * sz;
    mf[3][0] = (v->l - v->r) * sx;
    mf[3][1] = (v->b - v->t) * sy;
    mf[3][2] = (v->n - v->f) * sz;
    mf[3][3] = v->scale;
    mf[0][1] = mf[0][2] = mf[0][3] = mf[1][0] = mf[1][2] = mf[1][3] = mf[2][0] = mf[2][1] = mf[2][3] = 0.0f;
}
