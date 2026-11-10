#include "sdk_hu1.h"

/* guLookAt */
void func_8009C6E0(Mtx* m, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp,
                   f32 zUp) {
    Matrix4f mf;

    HuGuLookAtF(mf, xEye, yEye, zEye, xAt, yAt, zAt, xUp, yUp, zUp);

    func_800A0A20(mf, m);
}
