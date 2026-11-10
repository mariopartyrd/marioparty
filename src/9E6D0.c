#include "sdk_hu1.h"

/* guOrtho */
void func_8009DAD0(Mtx* m, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f, f32 scale) {
    Matrix4f mf;

    func_8009D920(mf, l, r, b, t, n, f, scale);

    func_800A0A20(mf, m);
}
