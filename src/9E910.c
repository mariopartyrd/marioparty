#include "sdk_hu1.h"

/* guFrustum */
void func_8009DD10(Mtx* m, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f, f32 scale) {
    Matrix4f mf;

    func_8009DB50(mf, l, r, b, t, n, f, scale);

    func_800A0A20(mf, m);
}
