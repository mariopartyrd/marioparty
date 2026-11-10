#include "common.h"

void func_800A0B90(Matrix4f, void*);
void func_800ABCD0(Matrix4f, Vec3f*, Matrix4f);

// Mtx version of func_800ABCD0 (scale): arg0 -> arg2.
void func_800ABE30(void* arg0, Vec3f* arg1, void* arg2) {
    Matrix4f m;

    func_800A0B90(m, arg0);
    func_800ABCD0(m, arg1, m);
    func_800A0A20(m, arg2);
}
