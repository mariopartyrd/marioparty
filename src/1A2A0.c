#include "common.h"

f32 func_800A1480(Vec3f*, Vec3f*);

void func_800196A0(Matrix4f src, Matrix4f dst) {
    f32 m00m11 = src[0][0] * src[1][1];
    f32 m00m12 = src[0][0] * src[1][2];
    f32 m00m21 = src[0][0] * src[2][1];
    f32 m00m22 = src[0][0] * src[2][2];
    f32 m01m10 = src[0][1] * src[1][0];
    f32 m01m12 = src[0][1] * src[1][2];
    f32 m01m20 = src[0][1] * src[2][0];
    f32 m01m22 = src[0][1] * src[2][2];
    f32 m02m10 = src[0][2] * src[1][0];
    f32 m02m11 = src[0][2] * src[1][1];
    f32 m02m20 = src[0][2] * src[2][0];
    f32 m02m21 = src[0][2] * src[2][1];
    f32 m10m21 = src[1][0] * src[2][1];
    f32 m10m22 = src[1][0] * src[2][2];
    f32 m11m20 = src[1][1] * src[2][0];
    f32 m11m22 = src[1][1] * src[2][2];
    f32 m12m20 = src[1][2] * src[2][0];
    f32 m12m21 = src[1][2] * src[2][1];
    f32 inv;

    inv = 1.0f / ((m01m12 - m02m11) * src[2][0] + (m02m10 - m00m12) * src[2][1] + (m00m11 - m01m10) * src[2][2]);
    dst[0][0] = (-m12m21 + m11m22) * inv;
    dst[0][1] = (m02m21 - m01m22) * inv;
    dst[0][2] = (-m02m11 + m01m12) * inv;
    dst[1][0] = (m12m20 - m10m22) * inv;
    dst[1][1] = (-m02m20 + m00m22) * inv;
    dst[1][2] = (m02m10 - m00m12) * inv;
    dst[2][0] = (-m11m20 + m10m21) * inv;
    dst[2][1] = (m01m20 - m00m21) * inv;
    dst[2][2] = (-m01m10 + m00m11) * inv;
    dst[3][0] = ((m10m22 - m12m20) * src[3][1] + (m11m20 - m10m21) * src[3][2] + (m12m21 - m11m22) * src[3][0]) * inv;
    dst[3][1] = ((m01m22 - m02m21) * src[3][0] + (m02m20 - m00m22) * src[3][1] + (m00m21 - m01m20) * src[3][2]) * inv;
    dst[3][2] = ((m02m11 - m01m12) * src[3][0] + (m00m12 - m02m10) * src[3][1] + (m01m10 - m00m11) * src[3][2]) * inv;
    dst[0][3] = dst[1][3] = dst[2][3] = 0.0f;
    dst[3][3] = 1.0f;
}
s32 func_80019964(Vec3f* arg0, Vec3f* arg1, f32 arg2, Vec3f* arg3) {
    Vec3f sp18;
    Vec3f sp28;
    Vec3f sp38;
    Vec3f sp48;
    Vec3f sp58;
    Vec3f sp68;
    s32 var_v0;

    func_800A0D50(&sp18, arg0);
    func_800A0E80(&sp28, &arg0[1], arg0);
    func_800A0E80(&sp38, &arg0[2], arg0);
    func_800A14F0(&sp48, &sp28, &sp38);
    func_800A0E80(&sp58, arg1, arg0);
    func_80019A78(&sp18, &sp28, &sp38, &sp48, &sp58, &sp68);
    func_800A0E00(arg3, &sp68, &sp18);

    if (!(arg2 < func_800A13C0(arg3, arg1))) {
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }
    return var_v0;
}

// float register allocation; GCC reuses the 1.0f constant across blocks (masked 21)
#ifdef NON_MATCHING
s32 func_80019A78(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, Vec3f* arg4, Vec3f* arg5) {
    Vec3f sp10;
    Vec3f sp20;
    s32 pad[4];
    f32 inv;
    f32 s;
    f32 t;
    f32 d;
    f32 p0, p1, p2, p3, p4, p5;

    func_800A0D00(&sp10, -arg4->x, -arg4->y, -arg4->z);
    inv = 1.0f / (-(arg1->z * arg2->y * arg3->x) + (arg1->y * arg2->z * arg3->x) + (arg1->z * arg2->x * arg3->y) - (arg1->x * arg2->z * arg3->y) - (arg1->y * arg2->x * arg3->z) + (arg1->x * arg2->y * arg3->z));
    s = ((((p0 = arg3->y * sp10.x) - (p1 = arg3->x * sp10.y)) * arg2->z) +
         (((p2 = arg3->x * sp10.z) - (p3 = arg3->z * sp10.x)) * arg2->y) +
         (((p4 = arg3->z * sp10.y) - (p5 = arg3->y * sp10.z)) * arg2->x)) * inv;
    t = (((p1 - p0) * arg1->z) + ((p3 - p2) * arg1->y) + ((p5 - p4) * arg1->x)) * inv;

    if (((s > 0.0f) & (t > 0.0f)) && (s + t > 1.0f)) {
        func_800A0E80(&sp10, arg2, arg1);
        func_800A0E80(&sp20, arg4, arg1);
        d = func_800A1480(&sp10, &sp20) / func_800A1480(&sp10, &sp10);
        if (d <= 0.0f) {
            goto copy1;
        } else if (d >= 1.0f) {
            goto copy2;
        } else {
            func_800A0F00(&sp20, d, &sp10);
            func_800A0E00(arg5, arg1, &sp20);
            return 1;
        }
    } else if (t < 0.0f) {
        d = func_800A1480(arg1, arg4) / func_800A1480(arg1, arg1);
        if (d <= 0.0f) {
            func_800A0D00(arg5, 0.0f, 0.0f, 0.0f);
            return 1;
        } else if (d >= 1.0f) {
        copy1:
            func_800A0D50(arg5, arg1);
            return 1;
        } else {
            func_800A0F00(arg5, d, arg1);
            return 1;
        }
    } else if (s < 0.0f) {
        d = func_800A1480(arg2, arg4) / func_800A1480(arg2, arg2);
        if (d <= 0.0f) {
            func_800A0D00(arg5, 0.0f, 0.0f, 0.0f);
            return 1;
        } else if (d >= 1.0f) {
        copy2:
            func_800A0D50(arg5, arg2);
            return 1;
        } else {
            func_800A0F00(arg5, d, arg2);
            return 1;
        }
    } else {
        func_800A0D00(arg5, s * arg1->x + t * arg2->x, s * arg1->y + t * arg2->y, s * arg1->z + t * arg2->z);
        return 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/1A2A0", func_80019A78);
#endif

s32 func_80019EDC(Vec3f* arg0, Vec3f* arg1, f32 arg2, Vec3f* arg3) {
    Vec3f sp18;
    Vec3f sp28;
    Vec3f sp38;
    Vec3f sp48;
    Vec3f sp58;
    Vec3f sp68;
    Vec3f sp78;
    Vec3f sp88;
    Vec3f sp98;
    f32 temp_f0;
    f32 var_f20;
    s32 var_v0;

    func_800A0D50(&sp18, arg0);
    func_800A0E80(&sp28, &arg0[1], arg0);
    func_800A0E80(&sp38, &arg0[2], arg0);
    func_800A0E80(&sp48, &arg0[3], arg0);
    func_800A14F0(&sp58, &sp28, &sp38);
    func_800A0E80(&sp68, arg1, arg0);
    func_80019A78(&sp18, &sp28, &sp38, &sp58, &sp68, &sp78);
    func_800A0E00(&sp88, &sp78, &sp18);
    func_80019A78(&sp18, &sp38, &sp48, &sp58, &sp68, &sp78);
    func_800A0E00(&sp98, &sp78, &sp18);
    var_f20 = func_800A13C0(&sp88, arg1);
    temp_f0 = func_800A13C0(&sp98, arg1);
    if (var_f20 < temp_f0) {
        func_800A0D50(arg3, &sp88);
    } else {
        var_f20 = temp_f0;
        func_800A0D50(arg3, &sp98);
    }
    if (!(arg2 < var_f20)) {
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }
    return var_v0;
}
void func_8001A084(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2) {
    f32 temp_f20;

    temp_f20 = func_800A1480(arg0, arg1);
    func_800A0F00(arg2, temp_f20 / func_800A1480(arg0, arg0), arg0);
}
