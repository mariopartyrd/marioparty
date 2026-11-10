#include "CrazyCutter.h"
#include "sprite65770.h"

/* Sprite palettes stay in the file's big-endian byte order on the host too (65770.c copies them
   byte by byte), so a 16-bit entry is read from its two bytes there. */
#define CC_PAL16(pal, i) (((u16*)(pal))[i])

/* Converts a sprite frame's image into a one-byte-per-pixel mask (0xFF where opaque). */
// register allocation, and buf + off + x recomputed per store in case 8 (raw 20, masked 6; tried
// &pal[c], a dst temp, (buf + off)[x])
#ifdef NON_MATCHING
u8* func_800FC4F0_CrazyCutter(s16 grpIdx, s16 idx, s32* width, s32* height) {
    unk65770Obj* spr;
    unk65770AnimC* img;
    u8* buf;
    u8* src;
    u16* pal;
    u32 x;
    u32 y;
    s32 stride;
    u8 c;
    u8* dst;
    u16* pp;
    s32 off;

    spr = func_800675F4(grpIdx, idx);
    img = &spr->unk4C->unk0[spr->unk52];
    buf = func_80023684(img->unk4 * img->unk6, 0x7918);
    src = img->unk0;
    pal = spr->unk4C->unkC;
    *width = img->unk4;
    *height = img->unk6;
    switch (spr->unk4C->unk18 & 0xF) {
        case 4:
            stride = (img->unk4 + (img->unk4 & 1)) >> 1;
            for (y = 0; y < img->unk6; y++) {
                for (x = 0; x < img->unk4; x++) {
                    c = (src + stride * y)[x >> 1];
                    if (x & 1) {
                        c &= 0xF;
                    } else {
                        c >>= 4;
                    }
                    pp = c + pal;
                    dst = buf + img->unk4 * y + x;
                    if (*pp >= 0x80) {
                        *dst = 0xFF;
                    } else {
                        *dst = 0;
                    }
                }
            }
            break;
        case 8:
            for (y = 0; y < img->unk6; y++) {
                for (x = 0; x < img->unk4; x++) {
                    off = img->unk4 * y;
                    c = (src + off)[x];
                    if (CC_PAL16(pal, c) & 1) {
                        *(buf + off + x) = 0xFF;
                    } else {
                        *(buf + off + x) = 0;
                    }
                }
            }
            break;
    }
    return buf;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_CrazyCutter/12AFE0", func_800FC4F0_CrazyCutter);
#endif

typedef s32 (*CrazyCutterPixelFunc)(s32, s32, s32, u8*, s32);

/* Writes the palette's transparent index into the sprite image wherever mask is set, at (x0, y0).
   Returns the number of pixels that changed. */
s32 func_800FC70C_CrazyCutter(s16 grpIdx, s16 idx, s32 x0, s32 y0, s32 w, s32 h, s8* mask) {
    unk65770Obj* spr;
    unk65770AnimC* img;
    u8* pixels;
    CrazyCutterPixelFunc fn;
    s32 col;
    s32 x;
    s32 y;
    s32 count;
    s32 px;
    s32 py;
    s32 ww = w;
    s32 hh = h;

    fn = NULL;
    spr = func_800675F4(grpIdx, idx);
    col = func_800FCA20_CrazyCutter(spr->unk4C->unkC, spr->unk4C->unk18);
    img = &spr->unk4C->unk0[spr->unk52];
    pixels = img->unk0;
    switch (spr->unk4C->unk18 & 0xF) {
        case 4:
            fn = (CrazyCutterPixelFunc)(void (*)(void))func_800FC998_CrazyCutter;
            break;
        case 8:
            fn = (CrazyCutterPixelFunc)(void (*)(void))func_800FC9F4_CrazyCutter;
            break;
    }
    count = 0;
    for (y = 0; y < hh; y++) {
        for (x = 0; x < ww; x++) {
            px = x + x0;
            py = y + y0;
            if (px >= 0 && px < img->unk4) {
                if (py >= 0 && py < img->unk6 && (mask + ww * y)[x] != 0) {
                    count += fn(px, py, img->unk4, pixels, col & 0xFF) != 0;
                }
            }
        }
    }
    return count;
}

s32 func_800FC8C0_CrazyCutter(s16 grpIdx, s16 idx, s32 x, s32 y) {
    unk65770Obj* spr;
    unk65770AnimC* img;
    u8* pixels;
    s32 col;

    spr = func_800675F4(grpIdx, idx);
    col = func_800FCA20_CrazyCutter(spr->unk4C->unkC, spr->unk4C->unk18);
    img = &spr->unk4C->unk0[spr->unk52];
    pixels = img->unk0;
    switch (spr->unk4C->unk18 & 0xF) {
        case 4:
            return func_800FC998_CrazyCutter(x, y, img->unk4, pixels, col & 0xFF);
        case 8:
            return func_800FC9F4_CrazyCutter(x, y, img->unk4, pixels, col & 0xFF);
        default:
            return 0;
    }
}

s32 func_800FC998_CrazyCutter(u32 arg0, s32 arg1, u32 arg2, u8* arg3, s32 arg4) { //fake match
    s32 new_var = arg4;
    s32 var_v0;
    s32 var_v1;
    u8 *temp_a3;
    temp_a3 = (arg3 + (((arg2 >> 1) + (arg2 & 1)) * arg1)) + (arg0 >> 1);
    
    if ((arg0 & 1) != 0) {
        var_v0 = (*temp_a3) & 0xF0;
        var_v1 = arg4 & 0xF;
    } else {
        var_v0 = (*temp_a3) & 0xF;
        var_v1 = arg4 * 0x10;
    }
    
    *temp_a3 = var_v0 | var_v1;
    var_v1 = new_var & 0xF;
    return 0;
}

s32 func_800FC9F4_CrazyCutter(s32 arg0, s32 arg1, s32 arg2, u8* arg3, u8 arg4) {
    u8 temp_v1;
    u8* temp_a3;

    temp_a3 = arg3 + (arg2 * arg1) + arg0;
    temp_v1 = *temp_a3;
    *temp_a3 = arg4;
    return *temp_a3 != temp_v1;
}

/* Returns the first palette index whose alpha bit is clear; with none, clears one and returns the
   last index. Retail's fallback index is (n - 1) * n, past the palette (kept as retail). */
s32 func_800FCA20_CrazyCutter(u8* pal, u16 fmt) {
    u16 n;
    u16 i;

    n = 0x100;
    if ((fmt & 0xF) == 4) {
        n = 0x10;
    }
    for (i = 0; i < n; i++) {
        if (!(pal[i * 2 + 1] & 1)) {
            return i;
        }
    }
    pal[(n - 1) * i * 2 + 1] &= ~1;
    return (u16)(n - 1);
}

/* As func_800FC70C_CrazyCutter, but only counts the masked pixels that differ from the
   transparent index. */
s32 func_800FCAAC_CrazyCutter(s16 grpIdx, s16 idx, s32 x0, s32 y0, s32 w, s32 h, s8* mask) {
    unk65770Obj* spr;
    unk65770AnimC* img;
    u8* pixels;
    CrazyCutterPixelFunc fn;
    s32 col;
    s32 x;
    s32 y;
    s32 count;
    s32 px;
    s32 py;
    s32 ww;
    s32 hh;

    spr = func_800675F4(grpIdx, idx);
    ww = w;
    hh = h;
    fn = NULL;
    col = func_800FCA20_CrazyCutter(spr->unk4C->unkC, spr->unk4C->unk18);
    img = &spr->unk4C->unk0[spr->unk52];
    pixels = img->unk0;
    switch (spr->unk4C->unk18 & 0xF) {
        case 4:
            fn = (CrazyCutterPixelFunc)(void (*)(void))func_800FCC64_CrazyCutter;
            break;
        case 8:
            fn = (CrazyCutterPixelFunc)(void (*)(void))CC_FUNC_800FCCC4;
            break;
    }
    count = 0;
    for (y = 0; y < hh; y++) {
        for (x = 0; x < ww; x++) {
            px = x + x0;
            py = y + y0;
            if (px >= 0 && px < img->unk4) {
                if (py >= 0 && py < img->unk6 && (mask + ww * y)[x] != 0) {
                    count += fn(px, py, img->unk4, pixels, col & 0xFF) != 0;
                }
            }
        }
    }
    return count;
}

s32 func_800FCC64_CrazyCutter(u32 arg0, s32 arg1, u32 arg2, u8* arg3, s32 arg4) {
    s32 new_var = arg4;
    s32 var_v0;
    s32 var_v1;
    u8* temp_a3;

    temp_a3 = arg3 + (((arg2 >> 1) + (arg2 & 1)) * arg1) + (arg0 >> 1);
    if ((arg0 & 1) != 0) {
        var_v0 = *temp_a3 & 0xF0;
        var_v1 = arg4 & 0xF;
    } else {
        var_v0 = *temp_a3 & 0xF;
        var_v1 = arg4 * 0x10;
    }
    var_v0 = ((var_v0 | var_v1) ^ arg4) & 0xFF;
    var_v1 = new_var & 0xF;
    return var_v0 != 0;
}

/* Retail has one nop between func_800FCC64 and func_800FCCC8, and func_800FCAAC takes the address
   of that nop (D_800FCCC4) as its 8-bit pixel test: running the nop first is harmless. The host
   uses func_800FCCC8 directly. */
__asm__(".globl D_800FCCC4_CrazyCutter\n.type D_800FCCC4_CrazyCutter,@function\nD_800FCCC4_CrazyCutter:\n.word 0\n");

s32 func_800FCCC8_CrazyCutter(s32 arg0, s32 arg1, s32 arg2, u8* arg3, u8 arg4) {
    return arg4 != *(arg3 + (arg2 * arg1) + arg0);
}
