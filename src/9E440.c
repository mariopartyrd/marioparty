#include "sdk_hu1.h"

/* guLookAtHilite */
void func_8009D840(Mtx* m, LookAt* l, Hilite* h, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt,
                   f32 xUp, f32 yUp, f32 zUp, f32 xl1, f32 yl1, f32 zl1, f32 xl2, f32 yl2, f32 zl2,
                   s32 twidth, s32 theight) {
    Matrix4f mf;

    func_8009CDB0(mf, l, h, xEye, yEye, zEye, xAt, yAt, zAt, xUp, yUp, zUp, xl1, yl1, zl1, xl2, yl2, zl2,
                  twidth, theight);

    func_800A0A20(mf, m);
}
