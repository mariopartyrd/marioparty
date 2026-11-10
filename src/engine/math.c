#include "common.h"
#include "engine/math.h"
#include "PR/gu.h"

f32 D_800C3290 = 0.01745329238474369f;
f32 D_800C3294 = 0.01745329238474369f;
f32 D_800C3298 = 0.01745329238474369f;






/* Translate Matrix. */
void MtxTranslate(Mat4 mtx, f32 x, f32 y, f32 z) {
     mtx[3][0] = (x * mtx[0][0]) + (y * mtx[1][0]) + (z * mtx[2][0]) + mtx[3][0];
     mtx[3][1] = (x * mtx[0][1]) + (y * mtx[1][1]) + (z * mtx[2][1]) + mtx[3][1];
     mtx[3][2] = (x * mtx[0][2]) + (y * mtx[1][2]) + (z * mtx[2][2]) + mtx[3][2];
     mtx[3][3] = (x * mtx[0][3]) + (y * mtx[1][3]) + (z * mtx[2][3]) + mtx[3][3];
}

/* Scale Matrix */
void MtxScale(Mat4 mtx, f32 sx, f32 sy, f32 sz) {
    s32 i;
    for (i = 0; i < 3; i++) {
        mtx[0][i] *= sx;
        mtx[1][i] *= sy;
        mtx[2][i] *= sz;
    }
}

/* Rotate Matrix. */
extern void func_800AF2E0(f32, f32*, f32*);  // Get sin and cosf of angle
void MtxRotate(Mat4 mtx, f32 angle1, f32 angle2, f32 angle3) {    
    Mat3 rot;
    f32 sx, cx;
    f32 sy, cy;
    f32 sz, cz;

    /* Get sin and cosf for three angles. */
    func_800AF2E0(angle1, &sx, &cx);
    if (angle1 == angle2){
        sy = sx;
        cy = cx;
    } else {
        func_800AF2E0(angle2, &sy, &cy);
    }

    if (angle1 == angle3){
        sz = sx;
        cz = cx;
    } else if (angle2 == angle3) {
        sz = sy;
        cz = cy;
    } else {
        func_800AF2E0(angle3, &sz, &cz);
    }

    /* Rotation Matrix First Column */
    rot[0][0] = cy * cz;
    rot[0][1] = cy * sz;
    rot[0][2] = -sy;
    /* Rotation Matrix Second Column */
    rot[1][0] = sx * sy * cz - cx * sz;
    rot[1][1] = sx * sy * sz + cx * cz;
    rot[1][2] = sx * cy;
    /* Rotation Matrix Third Column */
    rot[2][0] = cx * sy * cz + sx * sz;
    rot[2][1] = cx * sy * sz - sx * cz;
    rot[2][2] = cx * cy;

    {
        /* Multiply Matrices */
        f32 ret00, ret01, ret02;
        f32 ret10, ret11, ret12;

        ret00 = (rot[0][0] * mtx[0][0]) + (rot[0][1] * mtx[1][0]) + (rot[0][2] * mtx[2][0]);
        ret01 = (rot[0][0] * mtx[0][1]) + (rot[0][1] * mtx[1][1]) + (rot[0][2] * mtx[2][1]);
        ret02 = (rot[0][0] * mtx[0][2]) + (rot[0][1] * mtx[1][2]) + (rot[0][2] * mtx[2][2]);
        ret10 = (rot[1][0] * mtx[0][0]) + (rot[1][1] * mtx[1][0]) + (rot[1][2] * mtx[2][0]);
        ret11 = (rot[1][0] * mtx[0][1]) + (rot[1][1] * mtx[1][1]) + (rot[1][2] * mtx[2][1]);
        ret12 = (rot[1][0] * mtx[0][2]) + (rot[1][1] * mtx[1][2]) + (rot[1][2] * mtx[2][2]);

        /* Evaluate Result Matrix */
        mtx[2][0] = (rot[2][0] * mtx[0][0]) + (rot[2][1] * mtx[1][0]) + (rot[2][2] * mtx[2][0]);
        mtx[2][1] = (rot[2][0] * mtx[0][1]) + (rot[2][1] * mtx[1][1]) + (rot[2][2] * mtx[2][1]);
        mtx[2][2] = (rot[2][0] * mtx[0][2]) + (rot[2][1] * mtx[1][2]) + (rot[2][2] * mtx[2][2]);
        mtx[0][0] = ret00;
        mtx[0][1] = ret01;
        mtx[0][2] = ret02;
        mtx[1][0] = ret10;
        mtx[1][1] = ret11;
        mtx[1][2] = ret12;
    }
}

/* Multiply 2 Matrices */
void MtxMult(Mat4 a, Mat4 b, Mat4 c) {
    s32 i;
    f32 temp;
    f32  a0,  a1,  a2,  a3;
    f32 b00, b10, b20, b30;
    f32 b01, b11, b21, b31;
    f32 b02, b12, b22, b32;
    f32 b03, b13, b23, b33;

    i = 0;
    b00 = b[0][0]; b10 = b[1][0]; b20 = b[2][0]; b30 = b[3][0];
    b01 = b[0][1]; b11 = b[1][1]; b21 = b[2][1]; b31 = b[3][1];
    b02 = b[0][2]; b12 = b[1][2]; b22 = b[2][2]; b32 = b[3][2];
    b03 = b[0][3]; b13 = b[1][3]; b23 = b[2][3]; b33 = b[3][3];

    for (; i < 4; i++) {
        c[i][0] = (a0 = a[i][0]) * b00 + (a1 = a[i][1]) * b10 + (a2 = a[i][2]) * b20 + (a3 = a[i][3]) * b30;
        c[i][1] = a0 * b01 + a1 * b11 + a2 * b21 + a3 * b31;
        c[i][2] = a0 * b02 + a1 * b12 + a2 * b22 + a3 * b32;
        c[i][3] = a0 * b03 + a1 * b13 + a2 * b23 + a3 * b33;
    }
}  

/* Calculate Inverse Matrix */
s16 MtxInv(Mat4 a, Mat4 b) {
    u32 success;
    f32 d0, d1, d2;
    f32 det;

    d0 = (a[1][1] * a[2][2]) - (a[1][2] * a[2][1]);
    d1 = (a[1][2] * a[2][0]) - (a[1][0] * a[2][2]);
    d2 = (a[1][0] * a[2][1]) - (a[1][1] * a[2][0]);
    det = (a[0][0] * d0) + (a[0][1] * d1) + (a[0][2] * d2);

    success = FALSE;
    if (det != 0.0f) {
        f32 idet = (det = 1.0f / det); // They use same var, but I prefer this alias.
        b[0][0] = d0 * idet;
        b[1][0] = d1 * idet;
        b[2][0] = d2 * idet;
        b[0][1] = ((a[0][2] * a[2][1]) - (a[0][1] * a[2][2])) * idet;
        b[0][2] = ((a[0][1] * a[1][2]) - (a[0][2] * a[1][1])) * idet;
        b[1][1] = ((a[0][0] * a[2][2]) - (a[0][2] * a[2][0])) * idet;
        b[1][2] = ((a[0][2] * a[1][0]) - (a[0][0] * a[1][2])) * idet;
        b[2][1] = ((a[0][1] * a[2][0]) - (a[0][0] * a[2][1])) * idet;
        b[2][2] = ((a[0][0] * a[1][1]) - (a[0][1] * a[1][0])) * idet;
        b[3][2] = 0.0f;
        b[3][1] = 0.0f;
        b[3][0] = 0.0f;
        b[2][3] = 0.0f;
        b[1][3] = 0.0f;
        b[0][3] = 0.0f;
        b[3][3] = 1.0f;
        success = TRUE;
    }
    return success;
}

/* Reset Pose */
u32 MtxReset(Mat4 a, Mat4 b) {
    Mat4 invA;
    u32 success;
    if (MtxInv(a, invA)) {
        guMtxCatF(invA, a, b);
        success = TRUE;
    } else {
        guMtxIdentF(b);
        success = FALSE;
    }
    return success;
}

/* Rotate X-Axis */
void MtxRotateX(Mat4 mtx, f32 angle) {
    s32 i;
    f32 s, c;
    f32 vec[4];

    vec[0] = angle * D_800C3290;
    s = sinf(vec[0]);
    c = cosf(vec[0]);

    for (i = 0; i < 3; i++) {
        vec[i] = mtx[1][i];
    }

    for (i = 0; i < 3; i++) {
        mtx[1][i] = (c *  vec[i]) + (s * mtx[2][i]);
        mtx[2][i] = (-vec[i] * s) + (c * mtx[2][i]);
    }
}

/* Rotate Y-Axis */
void MtxRotateY(Mat4 mtx, f32 angle) {
    s32 i;
    f32 s, c;
    f32 vec[4];

    vec[0] = angle * D_800C3294;
    s = sinf(vec[0]);
    c = cosf(vec[0]);

    for (i = 0; i < 3; i++) {
        vec[i] = mtx[0][i];
    }

    for (i = 0; i < 3; i++) {
        mtx[0][i] = (c * vec[i]) - (s * mtx[2][i]);
        mtx[2][i] = (s * vec[i]) + (c * mtx[2][i]);
    }
}

/* Rotate Z-Axis */
void MtxRotateZ(Mat4 mtx, f32 angle) {
    s32 i;
    f32 s, c;
    f32 vec[4];

    vec[0] = angle * D_800C3298;
    s = sinf(vec[0]);
    c = cosf(vec[0]);

    for (i = 0; i < 3; i++) {
        vec[i] = mtx[0][i];
    }

    for (i = 0; i < 3; i++) {
        mtx[0][i] = (c *  vec[i]) + (s * mtx[1][i]);
        mtx[1][i] = (-vec[i] * s) + (c * mtx[1][i]);
    }
}

/* Unrelated? Animation Code? */
// FPR allocation in the found/else branches (masked 0)
#ifdef NON_MATCHING
// Piecewise-quadratic interpolation through four keys (y[], x[]) at time t.
f32 func_80022D9C(f32* y, f32* x, f32 t) {
    f32 slope[2];
    s32 i;
    f32 mid;
    f32 ds;
    f32 cross;
    s32 found;
    f32 u;
    f32 w;
    f32 b;
    f32 r;
    f32 midVal;
    f32 midSlope;
    f32 x0;
    f32 x1;
    f32 y0;
    f32 y1;
    f32 s0;
    f32 s1;

    if (y[0] == y[1] && y[0] == y[2] && y[0] == y[3]) {
        return y[0];
    }
    for (i = 1; i < 3; i++) {
        slope[i - 1] = ((y[i] - y[i - 1]) / (x[i] - x[i - 1]) + (y[i + 1] - y[i]) / (x[i + 1] - x[i])) * 0.5f;
    }
    mid = (x[2] + x[1]) * 0.5f;
    found = 0;
    if (slope[1] - slope[0] != 0.0f) {
        cross = ((slope[1] * x[2] - slope[0] * x[1]) - (y[2] - y[1])) / (slope[1] - slope[0]);
        if (x[1] <= cross && cross <= x[2]) {
            found = 1;
        }
    }
    if (found == 1) {
        u = mid - x[1];
        b = (y[2] - y[1]) / (x[2] - x[1]) - (slope[1] - slope[0]) / 2.0f;
        midVal = (slope[1] - slope[0]) / ((x[2] - x[1]) + (x[2] - x[1])) * u * u + b * u + y[1];
        midSlope = (slope[1] - slope[0]) / (x[2] - x[1]) * u + b;
    } else {
        u = mid - x[1];
        midVal = (y[2] + y[1]) * (r = u / (x[2] - x[1]));
        midSlope = ((y[2] - y[1]) + (y[2] - y[1])) / (x[2] - x[1]) - (slope[1] + slope[0]) * r;
    }
    if (t < mid) {
        x0 = x[1];
        y0 = y[1];
        s0 = slope[0];
        x1 = mid;
        y1 = midVal;
        s1 = midSlope;
    } else {
        x0 = mid;
        y0 = midVal;
        s0 = midSlope;
        x1 = x[2];
        y1 = y[2];
        s1 = slope[1];
    }
    ds = s1 - s0;
    w = x1 - x0;
    return ds / (w + w) * (t - x0) * (t - x0) + ((y1 - y0) / w - ds / 2.0f) * (t - x0) + y0;
}
#else
INCLUDE_ASM("asm/nonmatchings/engine/math", func_80022D9C);
#endif
