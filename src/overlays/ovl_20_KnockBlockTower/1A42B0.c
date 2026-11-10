#include "common.h"
#include "19FEE0.h"
#include "sprite65770.h"

/* .data (0x800FB540..0x800FB550) */
u16 D_800FB540_KnockBlockTower = 0; /* display-list buffer in use */
u16 D_800FB542_KnockBlockTower = 0; /* unreferenced */
s32 D_800FB544_KnockBlockTower[3] = { 0, 0, 0 }; /* unreferenced */

s16 func_80024198(u32, Gfx*, s32); /* src/24740.c */
extern unk65770Anim* D_800EC700[256]; /* src/65770.c */

/* Builds the scrolling background: `strips` rows of the I8 image `image`, each cut into tiles,
   scaled by (sx, sy) and scrolled by D_800FB5E8[row]. */
// logic-equivalent rewrite; the asm interleaves the display-list writes differently (not attempted)
#ifdef NON_MATCHING
void func_800FA9B0_KnockBlockTower(Gfx* gfx, s16 image, u16 rowStep, s32 x, s32 y, u16 strips, f32 sx, f32 sy) {
    unk65770AnimC* frame;
    u8* timg;
    s16 w;
    u16 h;
    u16 sw;
    s32 shx;
    s32 shy;
    s32 x0;
    s32 y0;
    s32 n;
    s32 rows;
    s32 th;
    s32 i;
    s32 j;

    frame = D_800EC700[image]->unk0;
    timg = frame->unk0;
    h = frame->unk6;
    sw = (s32)(frame->unk4 * sx);
    y0 = y - (s32)((u16)frame->unkA * sy);
    shx = sx / 2.0f;
    shy = sy / 2.0f;
    w = frame->unk4;
    x0 = x - (s32)((u16)frame->unk8 * sx);
    if (w < 81) {
        n = (s16)((s16)h / 40);
    } else if (w < 161) {
        n = (s16)((s16)h / 20);
    } else if (w < 321) {
        n = (s16)((s16)h / 10);
    } else if (w < 641) {
        n = (s16)((s16)h / 5);
    } else {
        n = (s16)h;
    }
    if (n <= 0) {
        n = 1;
    }
    rows = (s16)h / n;
    th = rows * sy;

    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPPipeSync(gfx++);
    gDPSetTexturePersp(gfx++, G_TP_NONE);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gSPSetOtherMode(gfx++, G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, 0x004041C8);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gDPSetColorDither(gfx++, G_CD_MAGICSQ);
    gDPSetCombine(gfx++, 0xFFFFFF, 0xFFFDF2F9);
    for (i = 0; i < strips; i++) {
        switch (i % 3) {
        case 0:
            gDPSetPrimColor(gfx++, 0, 0, 0xD3, 0x98, 0x96, 0xFF);
            break;
        case 1:
            gDPSetPrimColor(gfx++, 0, 0, 0xF7, 0xFF, 0xC9, 0xFF);
            break;
        case 2:
            gDPSetPrimColor(gfx++, 0, 0, 0xDA, 0xBF, 0xBF, 0xFF);
            break;
        }
        for (j = 0; j < n; j++) {
            gDPLoadTextureTile(gfx++, timg + w * rows * j, G_IM_FMT_I, G_IM_SIZ_8b, w, rows, 0, 0, w - 1, rows - 1,
                               0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                               G_TX_NOLOD, G_TX_NOLOD);
            gSPScisTextureRectangle(gfx++, x0 * 4, (y0 + th * j) * 4, (x0 + sw) * 4, (y0 + th * (j + 1)) * 4,
                                    G_TX_RENDERTILE, D_800FB5E8_KnockBlockTower[i][1], 0, 0x400 >> shx,
                                    0x400 >> shy);
        }
        D_800FB5E8_KnockBlockTower[i][1] -= D_800FB5E8_KnockBlockTower[i][0];
        if (D_800FB5E8_KnockBlockTower[i][1] < -0xA00) {
            D_800FB5E8_KnockBlockTower[i][1] += 0x1400;
        } else if (D_800FB5E8_KnockBlockTower[i][1] > 0xA00) {
            D_800FB5E8_KnockBlockTower[i][1] -= 0x1400;
        }
        y0 += rowStep;
    }
    gDPPipeSync(gfx++);
    gSPEndDisplayList(gfx++);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_KnockBlockTower/1A42B0", func_800FA9B0_KnockBlockTower);
#endif

/* Rebuilds the next display-list buffer each frame. */
void func_800FB13C_KnockBlockTower(omObjData* obj) {
    Gfx* gfx;

    D_800FB540_KnockBlockTower++;
    if (D_800FB540_KnockBlockTower >= D_800F37DA) {
        D_800FB540_KnockBlockTower = 0;
    }
    gfx = D_800FB5D4_KnockBlockTower[D_800FB540_KnockBlockTower];
    func_800FA9B0_KnockBlockTower(gfx, D_800FB5D0_KnockBlockTower[0], 20, 160, 10, 11, 2.0f, 2.0f);
    D_800F2B7C[D_800FB5E0_KnockBlockTower].unk_6C->unk_00 = (Gfx**)gfx;
}

u16 func_800FB20C_KnockBlockTower(s32 file) {
    void* data;
    u16 ret;

    data = DataRead(file);
    ret = func_800678A4(data);
    DataClose(data);
    return ret;
}

void func_800FB250_KnockBlockTower(void) {
    s32 i;

    for (i = 0; i < D_800F37DA; i++) {
        HuMemDirectFree(D_800FB5D4_KnockBlockTower[i]);
    }
}

void func_800FB2B4_KnockBlockTower(omObjData* obj) {
    u16 i;

    obj->func_ptr = &func_800FB13C_KnockBlockTower;
    D_800FB5D0_KnockBlockTower[0] = func_800FB20C_KnockBlockTower(0x17000A);
    for (i = 0; i < D_800F37DA; i++) {
        /* 0x1900 bytes on the N64: 0x320 commands (a host Gfx is 16 bytes) */
        D_800FB5D4_KnockBlockTower[i] = HuMemDirectMalloc(0x320 * sizeof(Gfx));
    }
    for (i = 0; i < 11; i++) {
        D_800FB5E8_KnockBlockTower[i][0] = i * 4;
        D_800FB5E8_KnockBlockTower[i][1] = i * 10 - 80;
    }
    for (i = 0; i < D_800F37DA; i++) {
        func_800FA9B0_KnockBlockTower(D_800FB5D4_KnockBlockTower[i], D_800FB5D0_KnockBlockTower[0], 20, 160, 10, 11, 2.0f,
                                      2.0f);
    }
    D_800FB5E0_KnockBlockTower = func_80024198(0x99, D_800FB5D4_KnockBlockTower[0], 0);
    D_800FB5D0_KnockBlockTower[1] = func_800FB20C_KnockBlockTower(0x170009);
    D_800FB640_KnockBlockTower = func_80064EF4(1, 0);
    func_80067208(D_800FB640_KnockBlockTower, 0, D_800FB5D0_KnockBlockTower[1], 0);
    func_800674BC(D_800FB640_KnockBlockTower, 0, 0x02004000);
    func_80066DC4(D_800FB640_KnockBlockTower, 0, 0xA0, 0x78);
    func_800674F4(D_800FB640_KnockBlockTower, 0, 0xED, 0xE6, 0xC1);
    func_80067354(D_800FB640_KnockBlockTower, 0, 160.0f, 120.0f);
    func_80067384(D_800FB640_KnockBlockTower, 0, 0x20);
}
