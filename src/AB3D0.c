#include "common.h"
#include "sdk_hu3.h"

// Mtx rotation about Z by an angle (degrees): rows 0..2 of src unpacked, rotated, packed into dst; row 3 copied.
void func_800AA7D0(Mtx* src, f32 angle, Mtx* dst) {
    f32 s;
    f32 c;
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

    func_800AF2E0(angle, &s, &c);
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
    out[0][0] = in[0][0] * c + in[1][0] * s;
    out[0][1] = in[0][1] * c + in[1][1] * s;
    out[0][2] = in[0][2] * c + in[1][2] * s;
    out[0][3] = in[0][3] * c + in[1][3] * s;
    out[1][0] = in[1][0] * c - in[0][0] * s;
    out[1][1] = in[1][1] * c - in[0][1] * s;
    out[1][2] = in[1][2] * c - in[0][2] * s;
    out[1][3] = in[1][3] * c - in[0][3] * s;
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
