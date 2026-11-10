#include "common.h"

void func_800A0B90(Matrix4f, void*);
void func_800AC0B0(Matrix4f, Matrix4f, Matrix4f);

// Mtx version of func_800AC0B0 (4x4 product): arg0 * arg1 -> arg2.
void func_800AC310(void* arg0, void* arg1, void* arg2) {
    Matrix4f a;
    Matrix4f b;

    func_800A0B90(a, arg0);
    func_800A0B90(b, arg1);
    func_800AC0B0(a, b, a);
    func_800A0A20(a, arg2);
}
