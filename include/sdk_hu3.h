#ifndef SDK_HU3_H
#define SDK_HU3_H

/* Hudson's Mtx (s15.16 fixed point) helpers, sdk-hu3 units A7380..AD210. An Mtx holds the integer
   halves of each row pair at words 0..7 and the fractions at words 8..15 (gbi.h); these macros
   unpack/pack one pair of elements like libultra's guMtxL2F/guMtxF2L, one step at a time. */

#define HU_FIX32TOF(x) ((f32)(x) * (1.0f / 65536.0f))
#define HU_FTOFIX32(x) ((s32)((x) * 65536.0f))

/* Read the next pair through (ai, af) into a, b; post-increments both pointers. */
#define HU_MTX_GET(a, b)                                            \
    e1 = (*ai & 0xFFFF0000) | ((*af >> 16) & 0xFFFF);               \
    e2 = ((*(ai++) << 16) & 0xFFFF0000) | (*(af++) & 0xFFFF);       \
    q1 = e1;                                                        \
    q2 = e2;                                                        \
    a = HU_FIX32TOF(q1);                                            \
    b = HU_FIX32TOF(q2)

/* The last pair: no increment. */
#define HU_MTX_GET_LAST(a, b)                                       \
    e1 = (*ai & 0xFFFF0000) | ((*af >> 16) & 0xFFFF);               \
    e2 = ((*ai << 16) & 0xFFFF0000) | (*af & 0xFFFF);               \
    q1 = e1;                                                        \
    q2 = e2;                                                        \
    a = HU_FIX32TOF(q1);                                            \
    b = HU_FIX32TOF(q2)

/* Write a, b as the next pair through (bi, bf); post-increments both pointers. */
#define HU_MTX_PUT(a, b)                                            \
    q1 = HU_FTOFIX32(a);                                            \
    q2 = HU_FTOFIX32(b);                                            \
    *(bi++) = (q1 & 0xFFFF0000) | ((q2 >> 16) & 0xFFFF);            \
    *(bf++) = ((q1 << 16) & 0xFFFF0000) | (q2 & 0xFFFF)

#define HU_MTX_PUT_LAST(a, b)                                       \
    q1 = HU_FTOFIX32(a);                                            \
    q2 = HU_FTOFIX32(b);                                            \
    *bi = (q1 & 0xFFFF0000) | ((q2 >> 16) & 0xFFFF);                \
    *bf = ((q1 << 16) & 0xFFFF0000) | (q2 & 0xFFFF)

void func_800AF2E0(f32 angle, f32* sine, f32* cosine);

#endif
