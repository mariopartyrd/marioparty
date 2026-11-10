#include "common.h"
#include "libc/stdarg.h"
u32 strlen(const char*);

/* Text window manager: an 18-entry window list sorted by priority, 4-bit window textures,
   a printf-style text renderer and a choice cursor. */

typedef struct Win {
    /* 0x00 */ u8 prio; /* 0xFF = free; entry 0 is the list head, entry 1 the tail (prio 0) */
    /* 0x01 */ u8 next;
    /* 0x02 */ s16 x;
    /* 0x04 */ s16 y;
    /* 0x06 */ s16 w;
    /* 0x08 */ s16 h;
    /* 0x0A */ s16 dsdx;
    /* 0x0C */ s16 dtdy;
    /* 0x0E */ s16 curX;
    /* 0x10 */ s16 curY;
    /* 0x12 */ s16 startX;
    /* 0x14 */ s16 startY;
    /* 0x16 */ s16 lineH;
    /* 0x18 */ s32 unk_18[4];
    /* 0x28 */ s16 choice;
    /* 0x2A */ s16 flags;
    /* 0x2C */ u8* tex;
    /* 0x30 */ void (*draw)(s16);
} Win; /* size = 0x34 */

typedef struct ChoiceRect {
    /* 0x00 */ s16 x0;
    /* 0x02 */ s16 y0;
    /* 0x04 */ s16 x1;
    /* 0x06 */ s16 y1;
} ChoiceRect;

extern u8 D_31BFE0[];
extern u8 D_31C7E0[];
u8* D_800C1910 = NULL; /* 8x8 1-bit font */
u8* D_800C1914 = NULL; /* window background texture */
u8* D_800C1918 = NULL; /* window palette */
u16 D_800C191C[] = { 0x0000, 0x003F, 0xF801, 0xF83F, 0x07C1, 0x07FF, 0xFFC1, 0xFFFF, 0x0001, 0x0000 };
Gfx D_800C1930[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineLERP(TEXEL0, PRIMITIVE, TEXEL0_ALPHA, PRIMITIVE, 0, TEXEL0, PRIMITIVE, TEXEL0, TEXEL0, PRIMITIVE, TEXEL0_ALPHA, PRIMITIVE, 0, TEXEL0, PRIMITIVE, TEXEL0),
    gsDPSetRenderMode(G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x00),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0x40),
    gsDPSetAlphaCompare(G_AC_THRESHOLD),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsSPEndDisplayList(),
};
u8 D_800C1988[] = { 0x22, 0x22 }; /* 2x2 CI4 texture */
u8 D_800C198C[] = { 0x00, 0x01, 0x02, 0x04, 0x10, 0x20, 0x40, 0x80, 0x80, 0x40, 0x20, 0x10, 0x04, 0x02, 0x01, 0x00 };
extern s16 D_800ED3E0; /* choice count */
extern s16 D_800ED724;
extern u16 D_800EDE50[];
extern ChoiceRect D_800EE758[];
extern s16 D_800EE958;
extern u16 D_800F2CF0;
extern char D_800F3188[];
extern s16 D_800F33E8; /* current window */
extern s16 D_800F3968;
extern Win D_800F3B88[18];
extern s16 D_800F5248;

s32 func_8002451C(s32, void (*)(void), s32);
void func_80023888(void*);
void func_8009B960(char*, char*);

void func_80014F7C(void);
void func_800150C8(s16 id);
void func_8001536C(s32 arg0);
void func_80015430(u8* dst, u8* src, s16 count, s16 scale);
void func_800154F8(s16 id);
void func_80015A38(s16 id);
void func_80015C10(s16 id);
void func_80015F90(u8* str);
void func_80016220(u8 ch, s16 id, s16 x, s16 y, u8 color);
s16 func_800166D8(char* buf, s32 val, s16 width);
s16 func_800168A8(char* buf, u32 val, s16 width);
s16 func_800169A8(char* buf, f64 val, s16 width, s16 prec);
s16 func_80016BDC(char* buf, s32 val, s16 bits);

void func_80014AF0(void) {
    s16 i;
    s32 size;

    for (i = 0; i < 18; i++) {
        D_800F3B88[i].prio = 0xFF;
    }
    D_800F3B88[0].prio = 0xFF;
    D_800F3B88[0].next = 1;
    D_800F3B88[1].prio = 0;
    D_800F3B88[1].next = 0;
    D_800EE958 = 0;
    D_800F5248 = 0x80;
    func_8001536C(0);
    func_80015430((u8*)D_800EDE50, (u8*)D_800C191C, 16, 0xA0);
    size = D_31C7E0 - D_31BFE0;
    D_800C1910 = func_80023684(size, 0x7918);
    dmaRead(D_31BFE0, D_800C1910, size);
    D_800ED724 = func_8002451C(0, func_80014F7C, 6);
}

s16 func_80014C0C(s16 prio) {
    s16 i;
    s16 cur;
    s16 prev;

    for (i = 1; i < 18; i++) {
        if (D_800F3B88[i].prio == 0xFF) {
            break;
        }
    }
    if (i == 18) {
        return -1;
    }
    cur = D_800F3B88[0].next;
    prev = 0;
    while (D_800F3B88[cur].prio != 0 && D_800F3B88[cur].prio >= prio) {
        prev = cur;
        cur = D_800F3B88[cur].next;
    }
    D_800F3B88[prev].next = i;
    D_800F3B88[i].next = cur;
    D_800F3B88[i].prio = prio;
    D_800F3B88[i].tex = NULL;
    D_800F3B88[i].dsdx = 0x400;
    D_800F3B88[i].dtdy = 0x400;
    D_800F3B88[i].choice = -1;
    D_800F3B88[i].draw = NULL;
    (D_800F3B88 + i)->unk_18[0] = (D_800F3B88 + i)->unk_18[1] = (D_800F3B88 + i)->unk_18[2] = (D_800F3B88 + i)->unk_18[3] = 0;
    D_800F3B88[i].flags = 0;
    return i;
}

void func_80014DF4(s16 id) {
    s16 cur;
    s16 prev;

    cur = D_800F3B88[0].next;
    prev = 0;
    while (D_800F3B88[cur].prio != 0) {
        if (cur == id) {
            break;
        }
        prev = cur;
        cur = D_800F3B88[cur].next;
    }
    if (D_800F3B88[cur].prio != 0) {
        if (D_800F3B88[id].tex != NULL) {
            func_80023888(D_800F3B88[id].tex);
        }
        D_800F3B88[prev].next = D_800F3B88[id].next;
        D_800F3B88[id].prio = 0xFF;
    }
}

void func_80014F7C(void) {
    s16 i;

    gSPDisplayList(D_800F37DC++, D_800C1930);
    for (i = D_800F3B88[0].next; D_800F3B88[i].next != 0; i = D_800F3B88[i].next) {
        func_800150C8(i);
        D_800F33E8 = i;
        D_800ED3E0 = 0;
        if (D_800F3B88[i].draw != NULL) {
            D_800F3B88[i].curX = D_800F3B88[i].startX;
            D_800F3B88[i].curY = D_800F3B88[i].startY;
            D_800F3B88[i].draw(i);
        }
        func_80015C10(i);
        func_800154F8(i);
    }
}

void func_800150C8(s16 id) {
    Win* w;
    u16 ww;
    u16 wh;

    gDPPipeSync(D_800F37DC++);
    gDPSetRenderMode(D_800F37DC++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    w = &D_800F3B88[id];
    ww = w->w;
    wh = w->h;
    gDPLoadTLUT_pal16(D_800F37DC++, 0, D_800C1918);
    gDPLoadTextureTile_4b(D_800F37DC++, D_800C1914, G_IM_FMT_CI, 32, 32, 0, 0, 32, 32, 0, G_TX_WRAP | G_TX_NOMIRROR,
                          G_TX_WRAP | G_TX_NOMIRROR, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(D_800F37DC++, w->x * 4, w->y * 4, (w->x + (s16)ww) * 4, (w->y + (s16)wh) * 4,
                        G_TX_RENDERTILE, 0, 0, w->dsdx, w->dtdy);
}

void func_8001536C(s32 arg0) {
    u16 i;

    D_800C1914 = func_80023684(0x200, 0x7918);
    for (i = 0; i < 0x200; i++) {
        D_800C1914[i] = 1;
    }
    D_800C1918 = func_80023684(0x20, 0x7918);
    for (i = 0; i < 0x20; i += 2) {
        D_800C1918[i] = 0;
        (D_800C1918 + i)[1] = 0x11;
    }
    func_80015430(D_800C1918, D_800C1918, 16, D_800F5248);
}

void func_80015430(u8* dst, u8* src, s16 count, s16 scale) {
    u16 i;
    u16 c;
    s32 r;
    s32 g;
    s32 b;
    u32 v;

    for (i = 0; i < count; i++) {
        c = (src[i * 2] << 8) + src[i * 2 + 1];
        g = c >> 6;
        b = c >> 1;
        r = c >> 11;
        r *= scale;
        r <<= 3;
        g &= 0x1F;
        g *= scale;
        g >>= 2;
        b &= 0x1F;
        b *= scale;
        b >>= 7;
        v = (r & 0xF800) | (g & 0x7C0) | (b & 0x3E) | (c & 1);
        dst[i * 2] = v >> 8;
        dst[i * 2 + 1] = v;
    }
}

void func_800154F8(s16 id) {
    Win* w;
    u16 ww;
    u16 wh;
    s16 tw;
    s16 s;
    s16 t;
    s16 sw;
    s16 th;

    gDPPipeSync(D_800F37DC++);
    gDPSetRenderMode(D_800F37DC++, 0x0F0A7008, 0);
    gDPSetPrimColor(D_800F37DC++, 0, 0, 0, 0, 0, 0x40);
    w = &D_800F3B88[id];
    if (D_800F3B88[w->next].next == 0 || (w->flags & 1)) {
        gDPLoadTLUT_pal16(D_800F37DC++, 0, D_800C191C);
    } else {
        gDPLoadTLUT_pal16(D_800F37DC++, 0, D_800EDE50);
    }
    tw = (w->w + 1) & ~1;
    ww = w->w;
    wh = w->h;
    th = 32;
    for (t = 0; t < (s16)wh; t += 32) {
        sw = 64;
        if (t >= (s16)wh - 32) {
            th = wh - t;
        }
        for (s = 0; s < (s16)ww; s += 64) {
            if (s >= (s16)ww - 64) {
                sw = ww - s;
            }
            gDPLoadTextureTile_4b(D_800F37DC++, w->tex + (s + t * tw) / 2, G_IM_FMT_CI, tw, 0, 0, 0, 64, th, 0,
                                  G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(D_800F37DC++, (w->x + s) * 4, (w->y + t) * 4, (w->x + s + sw) * 4, (w->y + t + th) * 4,
                                G_TX_RENDERTILE, 0, 0, w->dsdx, w->dtdy);
        }
    }
}

u8* func_80015970(s16 id, s16 x, s16 y, s16 w, s16 h, void (*draw)(s16)) {
    Win* win = &D_800F3B88[id];

    win->x = x;
    win->y = y;
    win->w = w;
    win->h = h;
    win->tex = func_80023684((s16)((w + 1) & ~1) * h / 2, 0x7918);
    win->draw = draw;
    win->startY = 3;
    win->startX = 3;
    win->lineH = 9;
    func_80015A38(id);
    return win->tex;
}

void func_80015A38(s16 id) {
    u8* tex;
    u8* p;
    s16 tw;
    s16 h;
    s16 n;
    s16 i;
    u8 edge;
    s32 pad[8]; // unused; retail's frame is 0x28

    tex = D_800F3B88[id].tex;
    tw = (D_800F3B88[id].w + 1) & ~1;
    h = D_800F3B88[id].h;
    n = (tw * h) >> 1;
    for (i = 0; i < n; i++) {
        tex[i] = 0;
    }
    n = tw >> 1;
    for (i = 0; i < n; i++) {
        p = &tex[i];
        *p = 0x77;
        p[((h - 1) * tw) >> 1] = 0x77;
    }
    n = h - 1;
    edge = 7;
    if (D_800F3B88[id].w & 1) {
        edge = 0x70;
    }
    for (i = 1; i < n; i++) {
        p = &tex[i * (tw >> 1)];
        *p = 0x70;
        (p + (tw >> 1))[-1] = edge;
    }
}

void func_80015C10(s16 id) {
    Win* w = &D_800F3B88[id];
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;

    if (w->choice != -1 && D_800ED3E0 >= w->choice) {
        gDPPipeSync(D_800F37DC++);
        gDPSetRenderMode(D_800F37DC++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        if (D_800F3B88[w->next].next != 0) {
            gDPSetPrimColor(D_800F37DC++, 0, 0, 0, 0, 0, 0x80);
        } else {
            gDPSetPrimColor(D_800F37DC++, 0, 0, 0, 0, 0, D_800C198C[D_800F3968++ & 0xF] + 0x40);
        }
        x0 = D_800EE758[w->choice].x0 + w->x;
        y0 = D_800EE758[w->choice].y0 + w->y;
        x1 = D_800EE758[w->choice].x1 + w->x;
        y1 = D_800EE758[w->choice].y1 + w->y;
        gDPLoadTLUT_pal16(D_800F37DC++, 0, D_800C191C);
        gDPLoadTextureTile_4b(D_800F37DC++, D_800C1988, G_IM_FMT_CI, 2, 2, 0, 0, 2, 2, 0, G_TX_WRAP | G_TX_NOMIRROR,
                              G_TX_WRAP | G_TX_NOMIRROR, 1, 1, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(D_800F37DC++, x0 * 4, y0 * 4, x1 * 4, y1 * 4, G_TX_RENDERTILE, 0, 0, w->dsdx, w->dtdy);
    }
}

// one unfilled delay slot on the newline path's jump (masked 2)
#ifdef NON_MATCHING
void func_80015F90(u8* str) {
    Win* w = &D_800F3B88[D_800F33E8];
    s16 i;
    s16 len;
    s32 color;
    s16 inChoice;
    s32 t;

    if (w->curY + 8 > w->h) {
        return;
    }
    inChoice = 0;
    len = strlen((char*)str);
    color = 7;
    for (i = 0; i < len; i++) {
        if (*str == 0) {
            break;
        }
        if (*str == '\n') {
            w->curX = w->startX;
            w->curY += w->lineH;
            if (w->curY + 8 > w->h) {
                break;
            }
            str++;
        } else if (*str == '[' && str[1] == '[') {
            inChoice = 1;
            D_800EE758[D_800ED3E0].x0 = w->curX - 1;
            D_800EE758[D_800ED3E0].y0 = w->curY - 1;
            str += 2;
            color = 6;
        } else if (*str == ']' && (inChoice & (t = (str[1] == ']')))) {
            inChoice = 0;
            D_800EE758[D_800ED3E0].x1 = w->curX;
            D_800EE758[D_800ED3E0].y1 = w->curY + w->lineH;
            D_800ED3E0++;
            str += 2;
            color = 7;
        } else {
            func_80016220(*str, D_800F33E8, w->curX, w->curY, color);
            w->curX += 8;
            if (w->curX <= w->w - 9) {
                str++;
            } else {
                t = (str[1] == '\n');
                str += t;
                if (str[1] == ']' && str[2] == ']') {
                    str++;
                } else {
                    w->curX = w->startX;
                    w->curY += w->lineH;
                    str++;
                    if (w->curY + 8 > w->h) {
                        break;
                    }
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/156F0", func_80015F90);
#endif

// glyph nibble store: retail reloads *p and re-masks color (masked 9)
#ifdef NON_MATCHING
void func_80016220(u8 ch, s16 id, s16 x, s16 y, u8 color) {
    Win* w = &D_800F3B88[D_800F33E8];
    u8* src = &D_800C1910[ch * 8];
    s16 tw = (w->w + 1) & ~1;
    u8* row = x / 2 + w->tex + y * tw / 2;
    u8* p;
    s16 mask;
    s16 r;
    s16 c;

    for (r = 0; r < 8; r++) {
        p = row;
        mask = 0x80;
        for (c = 0; c < 4; c++) {
            *p = (*src & mask) ? color << 4 : 0;
            mask >>= 1;
            *p = (*src & mask) ? *p | color : *p;
            mask >>= 1;
            p++;
        }
        src++;
        row += tw / 2;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/156F0", func_80016220);
#endif

// register allocation (pos/args swapped) and one va_arg addressing form (masked 1)
#ifdef NON_MATCHING
void func_8001636C(char* fmt, ...) {
    s16 pos;
    s16 i;
    va_list args;
    s16 len;
    s16 width;
    s16 prec;
    char* s;
    s32 val;
    s32 hex;
    s32 bin;
    f64 fval;

    len = strlen(fmt);
    va_start(args, fmt);
    pos = 0;
    for (i = 0; i < len; i++, fmt++) {
        if (*fmt == 0) {
            break;
        }
        if (*fmt == '%') {
            fmt++;
            if (*fmt >= '0' && *fmt <= '9') {
                width = *fmt - '0';
                fmt++;
            } else {
                width = -1;
            }
            if (*fmt >= '0' && *fmt <= '9') {
                prec = *fmt - '0';
                fmt++;
            } else {
                prec = -1;
            }
            switch (*fmt) {
                case '%':
                    D_800F3188[pos++] = '%';
                    break;
                case 'd':
                    if (width == -1) {
                        width = 7;
                    }
                    val = va_arg(args, s32);
                    pos += func_800166D8(&D_800F3188[pos], val, width);
                    break;
                case 'x':
                    if (width == -1) {
                        width = 8;
                    }
                    hex = va_arg(args, s32);
                    pos += func_800168A8(&D_800F3188[pos], hex, width);
                    break;
                case 'f':
                    if (width == -1) {
                        width = 8;
                    }
                    if (prec == -1) {
                        prec = 2;
                    }
                    fval = va_arg(args, f64);
                    pos += func_800169A8(&D_800F3188[pos], fval, width, prec);
                    break;
                case 's':
                    s = va_arg(args, char*);
                    func_8009B960(&D_800F3188[pos], s);
                    pos += strlen(s);
                    break;
                case 'b':
                    bin = va_arg(args, s32);
                    if (width == -1) {
                        width = 8;
                    }
                    if (prec != -1) {
                        width = width * 10 + prec;
                    }
                    pos += func_80016BDC(&D_800F3188[pos], bin, width);
                    break;
                default:
                    D_800F3188[pos++] = *fmt;
                    break;
            }
        } else {
            D_800F3188[pos++] = *fmt;
        }
    }
    D_800F3188[pos] = 0;
    func_80015F90((u8*)D_800F3188);
}
#else
INCLUDE_ASM("asm/nonmatchings/156F0", func_8001636C);
#endif

// register allocation (i and len swapped) (masked 0)
#ifdef NON_MATCHING
s16 func_800166D8(char* buf, s32 val, s16 width) {
    s16 neg;
    s32 div;
    s16 i;
    s8 started;
    s16 len;
    s16 digit;

    if (val < 0) {
        neg = 1;
        val = -val;
    } else {
        neg = 0;
    }
    div = 1;
    for (i = 0; i < width - 1; i++) {
        div *= 10;
    }
    started = 0;
    len = 0;
    for (i = 0; i < width - 1; i++) {
        if (val >= div) {
            digit = val / div;
            if ((started ^ 1) & neg) {
                if (i != 0) {
                    buf--;
                    len--;
                }
                *buf++ = '-';
                len++;
            }
            *buf++ = digit + '0';
            val -= digit * div;
            started = 1;
        } else {
            if (started != 0) {
                *buf = '0';
            } else {
                *buf = ' ';
            }
            buf++;
        }
        div /= 10;
        len++;
    }
    if (neg & (started ^ 1)) {
        if (width >= 2) {
            buf--;
            *buf++ = '-';
        }
    }
    *buf = val + '0';
    return len + 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/156F0", func_800166D8);
#endif

s16 func_800168A8(char* buf, u32 val, s16 width) {
    u16 i;
    u32 mask;
    u16 digits;
    u32 d;
    u32 top;

    mask = 0;
    for (i = 0; i < width; i++) {
        mask <<= 4;
        mask |= 0xF;
    }
    mask &= val;
    digits = 8;
    top = 0xF0000000;
loop:
    if (!(mask & top)) {
        digits--;
        mask <<= 4;
        if (digits >= 2) {
            goto loop;
        }
    }
    for (i = 0; i < width - digits; i++) {
        *buf++ = '0';
    }
    for (i = 0; i < digits; i++) {
        d = mask >> 28;
        *buf++ = (d < 10) ? d | '0' : d + '7';
        mask <<= 4;
    }
    return width;
}

// loop-invariant '.' and 0.0 hoisted out of the loop; len register copies (masked 31)
#ifdef NON_MATCHING
s16 func_800169A8(char* buf, f64 val, s16 width, s16 prec) {
    s32 neg;
    f64 div;
    s16 i;
    s8 started;
    s16 len;
    s32 digit;
    s32 t;

    if (val < 0.0) {
        neg = 1;
        val = -val;
    } else {
        neg = 0;
    }
    div = 1.0;
    for (i = 0; i < width - 1; i++) {
        div *= 10.0;
    }
    started = 0;
    len = 0;
    for (i = 0; i < width + prec; i++) {
        if (div <= val) {
            if ((started ^ 1) & (t = (neg != 0))) {
                if (i != 0) {
                    buf--;
                    len--;
                }
                *buf++ = '-';
                len++;
            }
            digit = val / div;
            *buf++ = digit + '0';
            val -= (s16)digit * div;
            started = 1;
        } else {
            if (started != 0) {
                *buf = '0';
            } else {
                *buf = ' ';
            }
            buf++;
        }
        len++;
        div /= 10.0;
        if (i == width - 1) {
            if (started == 0) {
                buf--;
                len--;
                if (neg != 0) {
                    if (i >= 2) {
                        buf--;
                        len--;
                    }
                    *buf++ = '-';
                    len++;
                }
                *buf++ = '0';
                len++;
            }
            *buf++ = '.';
            len++;
            if (val == 0.0) {
                *buf = '0';
                len++;
                break;
            }
            started = 1;
        }
    }
    return len;
}
#else
INCLUDE_ASM("asm/nonmatchings/156F0", func_800169A8);
#endif

s16 func_80016BDC(char* buf, s32 val, s16 bits) {
    s16 i;

    for (i = 0; i < 32 - bits; i++) {
        val <<= 1;
    }
    for (i = 0; i < bits; i++) {
        *buf++ = (val & 0x80000000) ? '1' : '0';
        val <<= 1;
    }
    return bits;
}

s16 func_80016C84(void) {
    s16 cur;
    s16 sel;
    s16 dir;
    s16 x;
    s16 y;
    s16 i;
    s16 d;
    f32 best;
    f32 bestX;
    f32 f;
    u16 btn;
    s16 dx;

    if (D_800ED3E0 == 0) {
        return 0;
    }
    cur = D_800F3B88[D_800F33E8].choice;
    btn = D_800F2CF0;
    dir = -((btn & 0x200) == 0);
    sel = cur;
    if (btn & 0x100) {
        dir = 2;
    }
    if (btn & 0x800) {
        dir = 1;
    }
    if (btn & 0x400) {
        dir = 3;
    }
    x = D_800EE758[cur].x0;
    y = D_800EE758[cur].y0;
    bestX = 100000.0f;
    best = 100000.0f;
    switch (dir) {
        case 0:
            for (i = 0; i < D_800ED3E0; i++) {
                if (i != cur && D_800EE758[i].y0 == y && D_800EE758[i].x0 < x) {
                    f = x - D_800EE758[i].x0;
                    if (f < best) {
                        best = f;
                        sel = i;
                    }
                }
            }
            break;
        case 1:
            for (i = 0; i < D_800ED3E0; i++) {
                if (i != cur && D_800EE758[i].y0 < y) {
                    d = y - D_800EE758[i].y0;
                    f = d;
                    if (f <= best) {
                        if (f < best) {
                            bestX = 100000.0f;
                        }
                        dx = x - D_800EE758[i].x0;
                        f = (s16)(dx * dx);
                        if (f < bestX) {
                            best = d;
                            bestX = f;
                            sel = i;
                        }
                    }
                }
            }
            break;
        case 2:
            for (i = 0; i < D_800ED3E0; i++) {
                if (i != cur && D_800EE758[i].y0 == y && x < D_800EE758[i].x0) {
                    f = D_800EE758[i].x0 - x;
                    if (f < best) {
                        best = f;
                        sel = i;
                    }
                }
            }
            break;
        case 3:
            for (i = 0; i < D_800ED3E0; i++) {
                if (i != cur && y < D_800EE758[i].y0) {
                    d = D_800EE758[i].y0 - y;
                    f = d;
                    if (f <= best) {
                        if (f < best) {
                            bestX = 100000.0f;
                        }
                        dx = x - D_800EE758[i].x0;
                        f = (s16)(dx * dx);
                        if (f < bestX) {
                            best = d;
                            bestX = f;
                            sel = i;
                        }
                    }
                }
            }
            break;
    }
    if (sel != cur) {
        D_800F3968 = 0;
    }
    return sel;
}
