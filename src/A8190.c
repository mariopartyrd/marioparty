#include "common.h"

void func_800AF2E0(f32 angle, f32* sine, f32* cosine);

// Rotation about X by an angle (degrees): rows 1 and 2 of arg0 -> arg2.
void func_800A7590(Matrix4f arg0, f32 angle, Matrix4f arg2) {
    f32 s;
    f32 c;

    func_800AF2E0(angle, &s, &c);
    arg2[1][0] = arg0[1][0] * c + arg0[2][0] * s;
    arg2[1][1] = arg0[1][1] * c + arg0[2][1] * s;
    arg2[1][2] = arg0[1][2] * c + arg0[2][2] * s;
    arg2[1][3] = arg0[1][3] * c + arg0[2][3] * s;
    arg2[2][0] = arg0[2][0] * c - arg0[1][0] * s;
    arg2[2][1] = arg0[2][1] * c - arg0[1][1] * s;
    arg2[2][2] = arg0[2][2] * c - arg0[1][2] * s;
    arg2[2][3] = arg0[2][3] * c - arg0[1][3] * s;
    arg2[0][0] = arg0[0][0];
    arg2[0][1] = arg0[0][1];
    arg2[0][2] = arg0[0][2];
    arg2[0][3] = arg0[0][3];
    arg2[3][0] = arg0[3][0];
    arg2[3][1] = arg0[3][1];
    arg2[3][2] = arg0[3][2];
    arg2[3][3] = arg0[3][3];
}
