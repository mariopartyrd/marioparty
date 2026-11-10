#ifndef SDK_HU1_H
#define SDK_HU1_H

/* Hudson's -O0 gu/vector math (main 0x9C370-0xA0FB0), decompiled by the SDK pass (2026-10-15). */

#include "common.h"
#include "PR/gbi.h"

f32 func_8009C0A0(f32 x, f32 y, f32 z); /* HuVecGetLengthSqr */
f32 func_8009C100(f32 x, f32 y, f32 z); /* HuVecGetLength */
void func_8009C770(Matrix4f mf, LookAt* l, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt,
                   f32 xUp, f32 yUp, f32 zUp); /* guLookAtReflectF */
void func_8009CDB0(Matrix4f mf, LookAt* l, Hilite* h, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt,
                   f32 zAt, f32 xUp, f32 yUp, f32 zUp, f32 xl1, f32 yl1, f32 zl1, f32 xl2, f32 yl2,
                   f32 zl2, s32 twidth, s32 theight); /* guLookAtHiliteF */
void func_8009D920(Matrix4f mf, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f, f32 scale); /* guOrthoF (Hudson) */
void func_8009DB50(Matrix4f mf, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f, f32 scale); /* guFrustumF (Hudson) */
void func_8009DD90(Matrix4f mf, u16* perspNorm, f32 fovy, f32 aspect, f32 near, f32 far,
                   f32 scale); /* guPerspectiveF */
void HuGuLookAtF(Matrix4f matrix, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp,
                 f32 yUp, f32 zUp);

void func_800AF2E0(f32 angle, f32* s, f32* c); /* sin and cos */

#endif
