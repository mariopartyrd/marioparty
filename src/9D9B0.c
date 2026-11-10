#include "sdk_hu1.h"

// register allocation: retail copies each value normalised by `len` through $f2 before storing
// (masked 19); the same residue as HuGuLookAtF (9CE40.c). Every other instruction matches.
#ifdef NON_MATCHING
/* guLookAtHiliteF (Hudson): single-precision eye - at, the matrix written as it is built, and
   squared-length highlight tests. */
void func_8009CDB0(Matrix4f mf, LookAt* l, Hilite* h, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt,
                   f32 zAt, f32 xUp, f32 yUp, f32 zUp, f32 xl1, f32 yl1, f32 zl1, f32 xl2, f32 yl2,
                   f32 zl2, s32 twidth, s32 theight) {
    f32 xLook;
    f32 yLook;
    f32 zLook;
    f32 xRight;
    f32 yRight;
    f32 zRight;
    f32 xHilite;
    f32 yHilite;
    f32 zHilite;
    f32 hlen;
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

    len = 1.0f / func_800B1750(xl1 * xl1 + yl1 * yl1 + zl1 * zl1);
    xl1 = xl1 * len;
    yl1 = yl1 * len;
    zl1 = zl1 * len;
    xHilite = xl1 + xLook;
    yHilite = yl1 + yLook;
    zHilite = zl1 + zLook;
    hlen = xHilite * xHilite + yHilite * yHilite + zHilite * zHilite;
    if (hlen > 0.01f) {
        hlen = 1.0f / func_800B1750(hlen);
        xHilite = xHilite * hlen;
        yHilite = yHilite * hlen;
        zHilite = zHilite * hlen;
        h->h.x1 = (xHilite * xRight + yHilite * yRight + zHilite * zRight + 2.0f) * twidth * 2.0f;
        h->h.y1 = (xHilite * xUp + yHilite * yUp + zHilite * zUp + 2.0f) * theight * 2.0f;
    } else {
        h->h.x1 = twidth * 2.0f;
        h->h.y1 = theight * 2.0f;
    }

    len = 1.0f / func_800B1750(xl2 * xl2 + yl2 * yl2 + zl2 * zl2);
    xl2 = xl2 * len;
    yl2 = yl2 * len;
    zl2 = zl2 * len;
    xHilite = xl2 + xLook;
    yHilite = yl2 + yLook;
    zHilite = zl2 + zLook;
    hlen = xHilite * xHilite + yHilite * yHilite + zHilite * zHilite;
    if (hlen > 0.01f) {
        hlen = 1.0f / func_800B1750(hlen);
        xHilite = xHilite * hlen;
        yHilite = yHilite * hlen;
        zHilite = zHilite * hlen;
        h->h.x2 = (xHilite * xRight + yHilite * yRight + zHilite * zRight + 2.0f) * twidth * 2.0f;
        h->h.y2 = (xHilite * xUp + yHilite * yUp + zHilite * zUp + 2.0f) * theight * 2.0f;
    } else {
        h->h.x2 = twidth * 2.0f;
        h->h.y2 = theight * 2.0f;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/9D9B0", func_8009CDB0);
#endif
