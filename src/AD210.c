#include "common.h"

void func_800A0B90(Matrix4f, void*);
void func_800AC380(Matrix4f, Matrix4f, Matrix4f);

// Mtx version (arg1: an Mtx as u16 halves, integer parts then fractions at +0x20) of func_800AC380: arg0 * arg1 (3x4 part of arg1), into arg2.
void func_800AC610(void* arg0, u16 (*arg1)[4], void* arg2) {
    s32 i;
    s32 j;
    Matrix4f a;
    Matrix4f b;

    func_800A0B90(a, arg0);
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            b[i][j] = ((arg1[i][j] << 16) | *(&arg1[i][j] + 16)) * (1.0f / 65536.0f);
        }
    }
    func_800AC380(a, b, a);
    func_800A0A20(a, arg2);
}
