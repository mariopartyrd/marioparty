#include "sdk_hu1.h"

// register allocation: retail copies each normalised value through $f2 before storing (masked 9),
// as HuGuLookAtF (9CE40.c).
#ifdef NON_MATCHING
/* guLookAtReflectF (Hudson): HuGuLookAtF's single-precision eye - at, plus the LookAt directions. */
void func_8009C770(Matrix4f mf, LookAt* l, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt,
                   f32 xUp, f32 yUp, f32 zUp) {
    f32 xLook;
    f32 yLook;
    f32 zLook;
    f32 xRight;
    f32 yRight;
    f32 zRight;
    f32 len;

    xLook = xEye - xAt;
    yLook = yEye - yAt;
    zLook = zEye - zAt;
    len = 1.0f / func_800B1750(xLook * xLook + yLook * yLook + zLook * zLook);
    xLook = xLook * len;
    yLook = yLook * len;
    zLook = zLook * len;
    mf[0][2] = xLook;
    mf[1][2] = yLook;
    mf[2][2] = zLook;
    mf[3][2] = -(xEye * xLook + yEye * yLook + zEye * zLook);
    xRight = yUp * zLook - zUp * yLook;
    yRight = zUp * xLook - xUp * zLook;
    zRight = xUp * yLook - yUp * xLook;
    len = 1.0f / func_800B1750(xRight * xRight + yRight * yRight + zRight * zRight);
    xRight = xRight * len;
    yRight = yRight * len;
    zRight = zRight * len;
    mf[0][0] = xRight;
    mf[1][0] = yRight;
    mf[2][0] = zRight;
    mf[3][0] = -(xEye * xRight + yEye * yRight + zEye * zRight);
    xUp = yLook * zRight - zLook * yRight;
    yUp = zLook * xRight - xLook * zRight;
    zUp = xLook * yRight - yLook * xRight;
    len = 1.0f / func_800B1750(xUp * xUp + yUp * yUp + zUp * zUp);
    xUp = xUp * len;
    yUp = yUp * len;
    zUp = zUp * len;
    mf[0][1] = xUp;
    mf[1][1] = yUp;
    mf[2][1] = zUp;
    mf[3][1] = -(xEye * xUp + yEye * yUp + zEye * zUp);
    mf[0][3] = mf[1][3] = mf[2][3] = 0.0f;
    mf[3][3] = 1.0f;

    l->l[0].l.dir[0] = xRight * 127.0f;
    l->l[0].l.dir[1] = yRight * 127.0f;
    l->l[0].l.dir[2] = zRight * 127.0f;
    l->l[1].l.dir[0] = xUp * 127.0f;
    l->l[1].l.dir[1] = yUp * 127.0f;
    l->l[1].l.dir[2] = zUp * 127.0f;
    l->l[0].l.col[0] = 0x00;
    l->l[0].l.col[1] = 0x00;
    l->l[0].l.col[2] = 0x00;
    l->l[0].l.pad1 = 0x00;
    l->l[0].l.colc[0] = 0x00;
    l->l[0].l.colc[1] = 0x00;
    l->l[0].l.colc[2] = 0x00;
    l->l[0].l.pad2 = 0x00;
    l->l[1].l.col[0] = 0x00;
    l->l[1].l.col[1] = 0x80;
    l->l[1].l.col[2] = 0x00;
    l->l[1].l.pad1 = 0x00;
    l->l[1].l.colc[0] = 0x00;
    l->l[1].l.colc[1] = 0x80;
    l->l[1].l.colc[2] = 0x00;
    l->l[1].l.pad2 = 0x00;
}
#else
INCLUDE_ASM("asm/nonmatchings/9D370", func_8009C770);
#endif
