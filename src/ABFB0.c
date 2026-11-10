#include "common.h"
#include "sdk_hu3.h"

// Mtx rotation about Z by a (sin, cos) pair: rows 0..2 of src unpacked, rotated, packed into dst; row 3 copied.
void func_800AB3B0(Mtx* src, Vec2f* sc, Mtx* dst) {
    u32* ai;
    u32* af;
    u32 e1;
    u32 e2;
    s32* bi;
    s32* bf;
    s32 q1;
    s32 q2;
    f32 in[4][4];
    f32 out[4][4];

    dst->m[1][2] = src->m[1][2];
    dst->m[1][3] = src->m[1][3];
    dst->m[3][2] = src->m[3][2];
    dst->m[3][3] = src->m[3][3];
    ai = (u32*)&src->m[0][0];
    af = (u32*)&src->m[2][0];
    HU_MTX_GET(in[0][0], in[0][1]);
    HU_MTX_GET(in[0][2], in[0][3]);
    HU_MTX_GET(in[1][0], in[1][1]);
    HU_MTX_GET(in[1][2], in[1][3]);
    HU_MTX_GET(in[2][0], in[2][1]);
    HU_MTX_GET_LAST(in[2][2], in[2][3]);
    out[0][0] = in[0][0] * sc->y + in[1][0] * sc->x;
    out[0][1] = in[0][1] * sc->y + in[1][1] * sc->x;
    out[0][2] = in[0][2] * sc->y + in[1][2] * sc->x;
    out[0][3] = in[0][3] * sc->y + in[1][3] * sc->x;
    out[1][0] = in[1][0] * sc->y - in[0][0] * sc->x;
    out[1][1] = in[1][1] * sc->y - in[0][1] * sc->x;
    out[1][2] = in[1][2] * sc->y - in[0][2] * sc->x;
    out[1][3] = in[1][3] * sc->y - in[0][3] * sc->x;
    out[2][0] = in[2][0];
    out[2][1] = in[2][1];
    out[2][2] = in[2][2];
    out[2][3] = in[2][3];
    bi = &dst->m[0][0];
    bf = &dst->m[2][0];
    HU_MTX_PUT(out[0][0], out[0][1]);
    HU_MTX_PUT(out[0][2], out[0][3]);
    HU_MTX_PUT(out[1][0], out[1][1]);
    HU_MTX_PUT(out[1][2], out[1][3]);
    HU_MTX_PUT(out[2][0], out[2][1]);
    HU_MTX_PUT_LAST(out[2][2], out[2][3]);
}

// Scales each row's x, y, z by arg1 (column scale): arg0 -> arg2.
void func_800ABCD0(Matrix4f arg0, Vec3f* arg1, Matrix4f arg2) {
    s32 i;

    for (i = 0; i < 4; i++) {
        arg2[i][0] = arg0[i][0] * arg1->x;
        arg2[i][1] = arg0[i][1] * arg1->y;
        arg2[i][2] = arg0[i][2] * arg1->z;
        arg2[i][3] = arg0[i][3];
    }
}
