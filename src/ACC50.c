#include "common.h"

void func_800A0B90(Matrix4f, void*);
void func_800ABE90(Matrix4f, Vec3f*, Matrix4f);

// Mtx version of func_800ABE90: arg0 -> arg2.
void func_800AC050(void* arg0, Vec3f* arg1, void* arg2) {
    Matrix4f m;

    func_800A0B90(m, arg0);
    func_800ABE90(m, arg1, m);
    func_800A0A20(m, arg2);
}
