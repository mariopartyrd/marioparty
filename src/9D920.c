#include "sdk_hu1.h"

/* guLookAtReflect */
void func_8009CD20(Mtx* m, LookAt* l, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp,
                   f32 yUp, f32 zUp) {
    Matrix4f mf;

    func_8009C770(mf, l, xEye, yEye, zEye, xAt, yAt, zAt, xUp, yUp, zUp);

    func_800A0A20(mf, m);
}
