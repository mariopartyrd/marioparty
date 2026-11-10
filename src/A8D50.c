#include "common.h"
#include "sdk_hu3.h"


// Rotation about X by a (sin, cos) pair: rows 1 and 2 of arg0 -> arg2.
void func_800A8150(Matrix4f arg0, Vec2f* arg1, Matrix4f arg2) {
    arg2[1][0] = arg0[1][0] * arg1->y + arg0[2][0] * arg1->x;
    arg2[1][1] = arg0[1][1] * arg1->y + arg0[2][1] * arg1->x;
    arg2[1][2] = arg0[1][2] * arg1->y + arg0[2][2] * arg1->x;
    arg2[1][3] = arg0[1][3] * arg1->y + arg0[2][3] * arg1->x;
    arg2[2][0] = arg0[2][0] * arg1->y - arg0[1][0] * arg1->x;
    arg2[2][1] = arg0[2][1] * arg1->y - arg0[1][1] * arg1->x;
    arg2[2][2] = arg0[2][2] * arg1->y - arg0[1][2] * arg1->x;
    arg2[2][3] = arg0[2][3] * arg1->y - arg0[1][3] * arg1->x;
    arg2[0][0] = arg0[0][0];
    arg2[0][1] = arg0[0][1];
    arg2[0][2] = arg0[0][2];
    arg2[0][3] = arg0[0][3];
    arg2[3][0] = arg0[3][0];
    arg2[3][1] = arg0[3][1];
    arg2[3][2] = arg0[3][2];
    arg2[3][3] = arg0[3][3];
}

// Mtx rotation about X by a (sin, cos) pair: rows 0..2 of src unpacked, rotated, packed into dst; row 3 copied.
void func_800A8430(Mtx* src, Vec2f* sc, Mtx* dst) {
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
    out[1][0] = in[1][0] * sc->y + in[2][0] * sc->x;
    out[1][1] = in[1][1] * sc->y + in[2][1] * sc->x;
    out[1][2] = in[1][2] * sc->y + in[2][2] * sc->x;
    out[1][3] = in[1][3] * sc->y + in[2][3] * sc->x;
    out[2][0] = in[2][0] * sc->y - in[1][0] * sc->x;
    out[2][1] = in[2][1] * sc->y - in[1][1] * sc->x;
    out[2][2] = in[2][2] * sc->y - in[1][2] * sc->x;
    out[2][3] = in[2][3] * sc->y - in[1][3] * sc->x;
    out[0][0] = in[0][0];
    out[0][1] = in[0][1];
    out[0][2] = in[0][2];
    out[0][3] = in[0][3];
    bi = &dst->m[0][0];
    bf = &dst->m[2][0];
    HU_MTX_PUT(out[0][0], out[0][1]);
    HU_MTX_PUT(out[0][2], out[0][3]);
    HU_MTX_PUT(out[1][0], out[1][1]);
    HU_MTX_PUT(out[1][2], out[1][3]);
    HU_MTX_PUT(out[2][0], out[2][1]);
    HU_MTX_PUT_LAST(out[2][2], out[2][3]);
}

// Rotation about Y by an angle (degrees): rows 0 and 2 of arg0 -> arg2.
void func_800A8D50(Matrix4f arg0, f32 angle, Matrix4f arg2) {
    f32 s;
    f32 c;

    func_800AF2E0(angle, &s, &c);
    arg2[0][0] = arg0[0][0] * c - arg0[2][0] * s;
    arg2[0][1] = arg0[0][1] * c - arg0[2][1] * s;
    arg2[0][2] = arg0[0][2] * c - arg0[2][2] * s;
    arg2[0][3] = arg0[0][3] * c - arg0[2][3] * s;
    arg2[2][0] = arg0[0][0] * s + arg0[2][0] * c;
    arg2[2][1] = arg0[0][1] * s + arg0[2][1] * c;
    arg2[2][2] = arg0[0][2] * s + arg0[2][2] * c;
    arg2[2][3] = arg0[0][3] * s + arg0[2][3] * c;
    arg2[1][0] = arg0[1][0];
    arg2[1][1] = arg0[1][1];
    arg2[1][2] = arg0[1][2];
    arg2[1][3] = arg0[1][3];
    arg2[3][0] = arg0[3][0];
    arg2[3][1] = arg0[3][1];
    arg2[3][2] = arg0[3][2];
    arg2[3][3] = arg0[3][3];
}
