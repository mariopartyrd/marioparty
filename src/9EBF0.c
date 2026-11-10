#include "sdk_hu1.h"

/* guPerspective */
void func_8009DFF0(Mtx* m, u16* perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale) {
    Matrix4f mf;

    func_8009DD90(mf, perspNorm, fovy, aspect, near, far, scale);

    func_800A0A20(mf, m);
}
