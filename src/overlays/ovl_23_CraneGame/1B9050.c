#include "CraneGame.h"

/* .data (0x800FF560..0x800FF8E0) */
/* An unused 32x32 I4 round-shadow texture (the game loads the shadow from file 0x36000C). */
u8 D_800FF560_CraneGame[512] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x22, 0x22, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0x33, 0x44, 0x43, 0x33, 0x32, 0x11, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x12, 0x33, 0x45, 0x55, 0x55, 0x54, 0x44, 0x32, 0x10, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x02, 0x34, 0x45, 0x56, 0x66, 0x66, 0x76, 0x55, 0x43, 0x32, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x23, 0x45, 0x66, 0x77, 0x77, 0x78, 0x77, 0x76, 0x65, 0x43, 0x20, 0x00, 0x00,
    0x00, 0x00, 0x02, 0x34, 0x56, 0x67, 0x88, 0x88, 0x79, 0x88, 0x77, 0x76, 0x54, 0x22, 0x00, 0x00,
    0x00, 0x00, 0x13, 0x45, 0x66, 0x78, 0x89, 0x9A, 0x99, 0xA9, 0x87, 0x76, 0x64, 0x43, 0x10, 0x00,
    0x00, 0x01, 0x24, 0x56, 0x77, 0x89, 0x99, 0x9B, 0xBB, 0x99, 0x99, 0x97, 0x76, 0x54, 0x20, 0x00,
    0x00, 0x01, 0x35, 0x66, 0x78, 0x89, 0xAD, 0xEF, 0xFF, 0xED, 0xA9, 0x98, 0x77, 0x64, 0x31, 0x00,
    0x00, 0x02, 0x45, 0x67, 0x78, 0x9A, 0xEF, 0xFF, 0xFF, 0xFF, 0xEB, 0x98, 0x87, 0x65, 0x32, 0x00,
    0x00, 0x12, 0x46, 0x78, 0x8A, 0xAE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xA8, 0x88, 0x76, 0x43, 0x10,
    0x00, 0x13, 0x56, 0x87, 0x99, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xDA, 0x97, 0x75, 0x43, 0x10,
    0x00, 0x23, 0x56, 0x78, 0x9A, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE9, 0x98, 0x76, 0x54, 0x20,
    0x00, 0x24, 0x57, 0x78, 0x8B, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0x98, 0x76, 0x54, 0x20,
    0x00, 0x24, 0x56, 0x78, 0x9C, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0x98, 0x76, 0x53, 0x20,
    0x00, 0x23, 0x56, 0x78, 0x9B, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0x98, 0x86, 0x53, 0x20,
    0x00, 0x23, 0x56, 0x78, 0x8A, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEA, 0x98, 0x76, 0x53, 0x20,
    0x00, 0x13, 0x46, 0x78, 0x99, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xD9, 0x98, 0x75, 0x43, 0x10,
    0x00, 0x13, 0x45, 0x78, 0x99, 0xAE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xA9, 0x97, 0x65, 0x43, 0x10,
    0x00, 0x02, 0x45, 0x67, 0x78, 0x9B, 0xEF, 0xFF, 0xFF, 0xFF, 0xEA, 0xA9, 0x86, 0x65, 0x42, 0x00,
    0x00, 0x01, 0x34, 0x66, 0x88, 0x99, 0xAD, 0xEF, 0xFF, 0xEC, 0xA9, 0x97, 0x76, 0x64, 0x31, 0x00,
    0x00, 0x01, 0x24, 0x46, 0x78, 0x78, 0x9A, 0xAB, 0xCB, 0x99, 0x98, 0x77, 0x75, 0x53, 0x21, 0x00,
    0x00, 0x00, 0x13, 0x45, 0x67, 0x78, 0x99, 0x8A, 0x99, 0x99, 0x98, 0x87, 0x65, 0x43, 0x10, 0x00,
    0x00, 0x00, 0x01, 0x24, 0x56, 0x67, 0x78, 0x88, 0x79, 0x98, 0x87, 0x75, 0x54, 0x32, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x23, 0x45, 0x56, 0x78, 0x78, 0x87, 0x87, 0x76, 0x54, 0x42, 0x20, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x02, 0x33, 0x45, 0x56, 0x66, 0x66, 0x66, 0x64, 0x53, 0x32, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x12, 0x34, 0x44, 0x55, 0x55, 0x55, 0x44, 0x32, 0x10, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x12, 0x33, 0x33, 0x44, 0x33, 0x32, 0x11, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x22, 0x22, 0x21, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

Gfx D_800FF760_CraneGame[] = {
    gsSPSegment(0x00, 0x00000000),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPPipelineMode(G_PM_1PRIMITIVE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0, 0),
    gsDPSetTileSize(1, 0, 0, 0, 0),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0000, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetDepthSource(G_ZS_PIXEL),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPNoOp(),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx D_800FF818_CraneGame[] = {
    gsSPClearGeometryMode(0xFFFFFFFF),
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
    gsSPSetGeometryMode(G_SHADE | G_SHADING_SMOOTH),
    gsSPClipRatio(FRUSTRATIO_2),
    gsSPEndDisplayList(),
};

Gfx D_800FF858_CraneGame[] = {
    gsSPDisplayList(D_800FF818_CraneGame),
    gsSPDisplayList(D_800FF760_CraneGame),
    gsSPEndDisplayList(),
};

Gfx D_800FF870_CraneGame[] = {
    gsDPPipeSync(),
    gsSPDisplayList(D_800FF858_CraneGame),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPSetGeometryMode(G_ZBUFFER | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x00),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0xFF),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPEndDisplayList(),
};

/* The claw's round shadow (func_800FCF78). */
Vtx D_800FF8B0_CraneGame[3] = {
    { { { -100, 0, 100 }, 0, { 0, 0 }, { 0, 0, 0, 0 } } },
    { { { 300, 0, 100 }, 0, { 0x800, 0 }, { 0, 0, 0, 0 } } },
    { { { -100, 0, -300 }, 0, { 0, 0x800 }, { 0, 0, 0, 0 } } },
};

/* Drop shadows: for each registered model, a flattened copy of its geometry is projected onto the
   floor every frame (func_800FBB18, the overlay's draw callback), plus a round shadow under the
   claw (func_800FCF78). */

void func_800FB830_CraneGame(void) {
    void* p;

    D_800FFEC4_CraneGame = 0;
    D_800FFEC2_CraneGame = 0;
    D_80100564_CraneGame = 0;
    D_800FFEC0_CraneGame = func_8002451C(0, func_800FBB18_CraneGame, 2);
    D_80100558_CraneGame.x = D_80100558_CraneGame.y = D_80100558_CraneGame.z = 0.0f;
    D_80100568_CraneGame = 0;
    p = DataRead(0x36000C);
    D_80100548_CraneGame = func_800678A4(p);
    DataClose(p);
    D_8010054C_CraneGame = func_80067310(D_80100548_CraneGame)->unk0->unk0;
}

void func_800FB8E8_CraneGame(void) {
    s32 i;

    if (D_800FFEC2_CraneGame != 0) {
        for (i = 0; i < D_800FFEC2_CraneGame; i++) {
            func_80023728(D_80100148_CraneGame[i][0]);
            func_80023728(D_80100148_CraneGame[i][1]);
            func_80023728(D_80100148_CraneGame[i][2]);
            func_80023728(D_80100448_CraneGame[i]->dl);
            func_80023728(D_80100448_CraneGame[i]);
        }
    }
    func_8002456C(D_800FFEC0_CraneGame);
    D_800FFEC4_CraneGame = 0;
    D_800FFEC2_CraneGame = 0;
}

void func_800FB9C4_CraneGame(s16 model) {
    D_800FFEC8_CraneGame[D_800FFEC2_CraneGame] = model;
    D_800FFF48_CraneGame[D_800FFEC2_CraneGame].cur = 1.0f;
    D_800FFF48_CraneGame[D_800FFEC2_CraneGame].target = 1.0f;
    D_80100148_CraneGame[D_800FFEC2_CraneGame][0] = NULL;
    D_80100148_CraneGame[D_800FFEC2_CraneGame][1] = NULL;
    D_80100148_CraneGame[D_800FFEC2_CraneGame][2] = NULL;
    D_80100448_CraneGame[D_800FFEC2_CraneGame] = NULL;
    D_80100550_CraneGame = D_800FFEC2_CraneGame;
    func_800FC4F4_CraneGame(model);
    D_800FFEC2_CraneGame++;
}

void func_800FBA78_CraneGame(s16 model, f32 target) {
    s32 i;

    for (i = 0; i < D_800FFEC2_CraneGame; i++) {
        if (D_800FFEC8_CraneGame[i] == model) {
            D_800FFF48_CraneGame[i].target = target;
            return;
        }
    }
}

void func_800FBAE8_CraneGame(f32 y) {
    D_80100568_CraneGame = 1;
    D_8010056C_CraneGame = y;
}

void func_800FBB00_CraneGame(f32 x, f32 y, f32 z) {
    D_80100558_CraneGame.x = x;
    D_80100558_CraneGame.y = y;
    D_80100558_CraneGame.z = z;
}

void func_800FBB18_CraneGame(Gfx** gfx, Mtx* mtx, camera* cam) {
    Matrix4f m1;
    Matrix4f m2;
    Matrix4f inv;
    unk_ovl_2D_struct* p;
    unk2C0C0StructC0* m;
    s32 i;
    s16 mdl;
    f32 a;

    if (++D_800FFEC4_CraneGame >= 3) {
        D_800FFEC4_CraneGame = 0;
    }
    D_80100564_CraneGame = (D_80100564_CraneGame + 1) & 0xF;
    gDPPipeSync((*gfx)++);
    gSPDisplayList((*gfx)++, D_800FF870_CraneGame);
    gDPPipeSync((*gfx)++);
    gDPSetCycleType((*gfx)++, G_CYC_1CYCLE);
    gSPSetGeometryMode((*gfx)++, G_ZBUFFER | G_CULL_BACK | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH);
    gDPSetRenderMode((*gfx)++, G_RM_AA_ZB_XLU_DECAL, G_RM_NOOP2);
    gDPSetCombineLERP((*gfx)++, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, SHADE, 0);
    gDPSetAlphaCompare((*gfx)++, G_AC_THRESHOLD);
    gDPSetBlendColor((*gfx)++, 0x08, 0x08, 0x08, 0x08);
    gDPSetColorDither((*gfx)++, G_CD_NOISE);
    gDPSetAlphaDither((*gfx)++, G_AD_PATTERN);
    gDPSetTexturePersp((*gfx)++, G_TP_PERSP);
    gDPSetPrimColor((*gfx)++, 0, 0, 0x00, 0x00, 0x00, 0xB0);
    gDPLoadTextureBlock_4b((*gfx)++, D_8010054C_CraneGame, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gSPTexture((*gfx)++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    func_8001D658(0, gfx);
    func_800A0B90(m1, mtx + 1);
    MtxTranslate(m1, D_80100558_CraneGame.x, D_80100558_CraneGame.y, D_80100558_CraneGame.z);
    func_8009EA40(m2, -m1[3][0], -m1[3][1], -m1[3][2]);
    MtxInv(m1, inv);
    func_800AC0B0(m2, inv, inv);
    for (i = 0; i < D_800FFEC2_CraneGame; i++) {
        D_80100550_CraneGame = i;
        if (func_8005FD5C() + D_800F64F8 == 0) {
            if (D_800FFF48_CraneGame[i].cur < D_800FFF48_CraneGame[i].target) {
                D_800FFF48_CraneGame[i].cur += 0.1;
                if (D_800FFF48_CraneGame[i].target < D_800FFF48_CraneGame[i].cur) {
                    D_800FFF48_CraneGame[i].cur = D_800FFF48_CraneGame[i].target;
                }
            } else {
                D_800FFF48_CraneGame[i].cur -= 0.1;
                if (D_800FFF48_CraneGame[i].cur < D_800FFF48_CraneGame[i].target) {
                    D_800FFF48_CraneGame[i].cur = D_800FFF48_CraneGame[i].target;
                }
            }
            D_800FFF48_CraneGame[i].target = 1.0f;
        }
        a = D_800FFF48_CraneGame[i].cur;
        D_80100554_CraneGame = a;
        mdl = D_800FFEC8_CraneGame[i];
        if (mdl >= 0) {
            p = &D_800F2B7C[mdl];
            m = p->unk_6C;
            if (m != NULL) {
                if (!(p->unk_20 & 4)) {
                    if (a != 0.0f) {
                        *gfx = func_800FC0A0_CraneGame(*gfx, m, inv);
                    }
                }
            }
        }
    }
    gDPPipeSync((*gfx)++);
    gDPSetRenderMode((*gfx)++, 0x404FD8, 0);
    *gfx = func_800FCF78_CraneGame(*gfx, mtx);
    gDPPipeSync((*gfx)++);
}

// register allocation and constant hoisting in the vertex loop (masked 56)
#ifdef NON_MATCHING
Gfx* func_800FC0A0_CraneGame(Gfx* gfx, unk2C0C0StructC0* m, Matrix4f inv) {
    Matrix4f mf;
    Matrix4f r;
    Vtx* vbuf;
    Vtx* v;
    CGShadowGroup* grp;
    void* mtx;
    s32 i;
    s32 j;
    f32 x;
    f32 y;
    f32 z;
    f32 h;
    f32 d;
    f32 px;
    f32 pz;
    f64 s;

    vbuf = D_80100148_CraneGame[D_80100550_CraneGame][D_800FFEC4_CraneGame];
    gSPSegment(gfx++, 1, osVirtualToPhysical(vbuf));
    grp = D_80100448_CraneGame[D_80100550_CraneGame];
    for (i = 0; i < (m->unk_6A & 0x3F); i++, grp++) {
        mtx = D_800ED0D8[m->unk_28][m->unk_80[i].unk_12].unk_44;
        func_800A0B90(mf, mtx);
        gSPMatrix(gfx++, osVirtualToPhysical(mtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        func_800AC0B0(mf, inv, r);
        d = r[3][0];
        if (d < 0.0f) {
            d = -d;
        }
        if (d > 300.0) {
            continue;
        }
        d = r[3][2];
        if (d < 0.0f) {
            d = -d;
        }
        if (d > 300.0) {
            continue;
        }
        v = vbuf + grp->start;
        for (j = 0; j < grp->count; j++, v++) {
            x = v->v.ob[0];
            y = v->v.ob[1];
            z = v->v.ob[2];
            px = x * r[0][0] + y * r[1][0] + z * r[2][0] + r[3][0];
            pz = x * r[0][2] + y * r[1][2] + z * r[2][2] + r[3][2];
            h = -(x * r[0][1] + y * r[1][1] + z * r[2][1] + r[3][1]) / 800.0;
            if (h < 0.0) {
                h = 0.0f;
            }
            s = (h + 1.0) * 120.0;
            v->v.tc[0] = ((s16)(s32)(px * 16.0f / s) << 5) + 0x200;
            v->v.tc[1] = ((s16)(s32)(pz * 16.0f / s) << 5) + 0x200;
            if (h > 1.0) {
                h = 1.0f;
            }
            v->v.cn[3] = (208.0 - h * 208.0f * 0.7) * D_80100554_CraneGame;
        }
        gSPDisplayList(gfx++, grp->dl);
    }
    return gfx;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CraneGame/1B9050", func_800FC0A0_CraneGame);
#endif

void func_800FC4F4_CraneGame(s16 model) {
    CGShadowGroup grp[64];
    s16 offs[64];
    Gfx* gp;
    Gfx* base;
    Gfx* dl;
    CGShadowGroup* g;
    unk2C0C0StructC0* m;
    s32 i;
    s32 size;
    Vtx* v;

    m = D_800F2B7C[model].unk_6C;
    D_80100448_CraneGame[D_80100550_CraneGame] = func_80023684((m->unk_6A & 0x3F) * sizeof(CGShadowGroup), (s16)m->unk_68);
    base = gp = func_80023684(0x2000 * sizeof(Gfx), (s16)m->unk_68);
    D_801006F4_CraneGame = func_80023684(0x10000, (s16)m->unk_68);
    D_801006F0_CraneGame = func_80023684(m->unk_6E * sizeof(unk2C0C0StructA0), (s16)m->unk_68);
    D_801006F8_CraneGame = func_80023684(0x8000, (s16)m->unk_68);
    D_801006FC_CraneGame = func_80023684(m->unk_6E * 2, (s16)m->unk_68);
    D_80100704_CraneGame = func_80023684(0x4000, (s16)m->unk_68);
    D_8010074C_CraneGame = 0;
    for (i = 0; i < (m->unk_6A & 0x3F); i++) {
        offs[i] = ((u32)gp - (u32)base) >> 3;
        grp[i].start = D_8010074C_CraneGame;
        func_800FC800_CraneGame(&m->unk_80[i], m->unk_78, m->unk_6E);
        func_800FC9B0_CraneGame();
        func_800FCB78_CraneGame(&gp, m);
        grp[i].count = D_8010074C_CraneGame - grp[i].start;
    }
    func_80023728(D_801006F0_CraneGame);
    func_80023728(D_801006F8_CraneGame);
    func_80023728(D_801006FC_CraneGame);
    func_80023728(D_80100704_CraneGame);
    size = (u8*)gp - (u8*)base;
    dl = func_80023684(size, (s16)m->unk_68);
    func_80023A38(base, dl, size);
    g = D_80100448_CraneGame[D_80100550_CraneGame];
    for (i = 0; i < (m->unk_6A & 0x3F); i++) {
        g[i].dl = dl + offs[i];
        g[i].start = grp[i].start;
        g[i].count = grp[i].count;
    }
    func_80023728(base);
    for (i = 0; i < 3; i++) {
        size = D_8010074C_CraneGame * sizeof(Vtx);
        v = func_80023684(size, (s16)m->unk_68);
        D_80100148_CraneGame[D_80100550_CraneGame][i] = v;
        func_80023A38(D_801006F4_CraneGame, v, size);
    }
    func_80023728(D_801006F4_CraneGame);
}

/* Builds the group's face list over unique vertices (D_801006F0_CraneGame) and counts how many
   faces use each vertex (D_801006FC_CraneGame). Retail's face-type test `(t < 3) & (t >= 5)` is
   never true, so every face is taken. */
void func_800FC800_CraneGame(unk2C0C0Struct30* g, unk2C0C0StructA0* verts, s16 nverts) {
    u16* refs;
    CGShadowOrder* order;
    unk2C0C0Struct20* f;
    u16* dst;
    unk2C0C0StructA0* p;
    unk2C0C0StructA0* u;
    s32 nv;
    s32 i;
    s32 nf;
    s32 j;
    s32 k;
    s32 t;

    refs = D_801006FC_CraneGame;
    func_8009B770(refs, 0, nverts * 2);
    order = D_80100704_CraneGame;
    f = g->unk_34;
    nv = 0;
    i = 0;
    nf = 0;
    for (; i < (g->unk_04 & 0x7FFF); i++, f++) {
        t = f->unk_00 & 7;
        if ((t < 3) & (t >= 5)) {
            continue;
        }
        dst = D_801006F8_CraneGame[i].v;
        for (j = 0; j < t; j++) {
            p = &verts[f->unk_04[j]];
            u = D_801006F0_CraneGame;
            u[nv].unk_00 = p->unk_00;
            u[nv].unk_02 = p->unk_02;
            u[nv].unk_04 = p->unk_04;
            k = 0;
            while (p->unk_00 != u->unk_00 || p->unk_02 != u->unk_02 || p->unk_04 != u->unk_04) {
                k++;
                u++;
            }
            nv += (k >= nv);
            refs[k]++;
            if (j == 0) {
                if (t >= 4) {
                    k |= 0x8000;
                }
            }
            *dst++ = k;
        }
        order->key = 0;
        order->face = nf;
        order++;
        nf++;
    }
    D_80100700_CraneGame = nv;
    D_80100702_CraneGame = nf;
}

/* Sorts the faces far to near by how shared their vertices are. Retail indexes the use counts with
   a quad's first vertex word, bit 15 included (a read 64 KB before the counts); the host masks that
   bit so the read stays inside the block. */
// post-decrement of the sort key folded into the add (masked 20)
#ifdef NON_MATCHING
void func_800FC9B0_CraneGame(void) {
    CGShadowOrder* q;
    CGShadowOrder* best;
    CGShadowOrder* r;
    s16* f;
    s32 key;
    s32 i;
    s32 j;
    s32 n;
    s16 sum;
    s16 t;

    if (D_80100700_CraneGame >= 29) {
        key = D_80100700_CraneGame;
        q = D_80100704_CraneGame;
        for (i = 0; i < D_80100702_CraneGame; i++, q++) {
            f = (s16*)D_801006F8_CraneGame[i].v;
            n = 3;
            if (*f & 0x8000) {
                n = 4;
            }
            sum = 0;
            for (j = 0; j < n; j++, f++) {
                sum += D_801006FC_CraneGame[*f];
            }
            q->key = key-- + (sum * 100) / n;
        }
        q = D_80100704_CraneGame;
        for (i = 0; i < D_80100702_CraneGame - 1; i++, q++) {
            best = q;
            r = q + 1;
            for (j = i; j < D_80100702_CraneGame - 1; j++, r++) {
                if (best->key < r->key) {
                    best = r;
                }
            }
            t = q->key;
            q->key = best->key;
            best->key = t;
            t = q->face;
            q->face = best->face;
            best->face = t;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CraneGame/1B9050", func_800FC9B0_CraneGame);
#endif

/* Emits the faces in draw order as gSP1Triangle/gSP1Quadrangle batches of at most 29 vertices. */
// register allocation; &D_80100708 is hoisted into a register, retail rebuilds it per use and has an 8-byte larger frame (masked 41; tried an indexed search loop)
#ifdef NON_MATCHING
void func_800FCB78_CraneGame(Gfx** gfx, unk2C0C0StructC0* m) {
    u8 (*start)[4];
    u8 (*cur)[4];
    u8* out;
    u16* f;
    CGShadowOrder* q;
    s32 i;
    s32 n;
    s32 k;
    s16 cnt;
    s32 quad;
    s16 idx;
    s16* s;

    start = cur = func_80023684(D_80100702_CraneGame * 4, m->unk_68);
    cnt = 0;
    D_8010074A_CraneGame = 0;
    q = D_80100704_CraneGame;
    for (i = 0; i < D_80100702_CraneGame; i++, q++) {
        f = D_801006F8_CraneGame[q->face].v;
        out = start[i];
        quad = (*f >> 15) << 7;
        n = 3;
        if (quad != 0) {
            n = 4;
        }
        for (; n > 0; n--) {
            idx = *f++ & 0x7FFF;
            k = 0;
            D_80100708_CraneGame[D_8010074A_CraneGame] = idx;
            s = D_80100708_CraneGame;
            while (idx != *s++) {
                k++;
            }
            *out++ = quad | k;
            quad = 0;
            if (k >= D_8010074A_CraneGame) {
                D_8010074A_CraneGame++;
            }
        }
        cnt++;
        if (D_8010074A_CraneGame >= 29) {
            *gfx = func_800FCD7C_CraneGame(*gfx, cur, cnt);
            cur += cnt;
            cnt = 0;
        }
    }
    if ((D_8010074A_CraneGame != 0) & (cnt != 0)) {
        *gfx = func_800FCD7C_CraneGame(*gfx, cur, cnt);
    }
    gSPEndDisplayList((*gfx)++);
    func_80023728(start);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CraneGame/1B9050", func_800FCB78_CraneGame);
#endif

// register allocation; retail steps the vertex pointer by 2 before reading z (masked 11)
#ifdef NON_MATCHING
Gfx* func_800FCD7C_CraneGame(Gfx* gfx, u8 (*tri)[4], s16 n) {
    Vtx* v;
    s16* s;
    unk2C0C0StructA0* p;
    s32 i;

    v = D_801006F4_CraneGame + D_8010074C_CraneGame;
    s = D_80100708_CraneGame;
    for (i = 0; i < D_8010074A_CraneGame; i++, v++, s++) {
        p = &D_801006F0_CraneGame[*s];
        v->v.ob[0] = p->unk_00;
        v->v.ob[1] = p->unk_02;
        v->v.ob[2] = p->unk_04;
        v->v.tc[0] = v->v.tc[1] = 0;
        v->v.cn[0] = v->v.cn[1] = v->v.cn[2] = 0xFF;
        v->v.cn[3] = 0xA0;
    }
    gSPVertex(gfx++, (Vtx*)(0x01000000 | (D_8010074C_CraneGame * sizeof(Vtx))), D_8010074A_CraneGame, 0);
    D_8010074C_CraneGame += D_8010074A_CraneGame;
    D_8010074A_CraneGame = 0;
    for (i = 0; i < n; i++, tri++) {
        if ((*tri)[0] & 0x80) {
            gSP1Quadrangle(gfx++, (*tri)[0] & 0x7F, (*tri)[1], (*tri)[2], (*tri)[3], 0);
        } else {
            gSP1Triangle(gfx++, (*tri)[0] & 0x7F, (*tri)[1], (*tri)[2], 0);
        }
    }
    return gfx;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CraneGame/1B9050", func_800FCD7C_CraneGame);
#endif

// float register allocation, 1.2 constant hoisting (masked 8)
#ifdef NON_MATCHING
Gfx* func_800FCF78_CraneGame(Gfx* gfx, Mtx* mtx) {
    Matrix4f m1;
    Matrix4f m2;
    Vtx* v;
    Vtx* src;
    f32 s;
    f64 sc;
    f64 a;
    s32 i;

    if (D_80100568_CraneGame == 0) {
        return gfx;
    }
    func_800A0B90(m1, mtx + 1);
    func_8009EA40(m2, D_80100558_CraneGame.x, D_8010056C_CraneGame, D_80100558_CraneGame.z);
    func_800AC0B0(m2, m1, m1);
    func_800A0A20(m1, &D_80100630_CraneGame[D_800FFEC4_CraneGame]);
    gSPMatrix(gfx++, osVirtualToPhysical(&D_80100630_CraneGame[D_800FFEC4_CraneGame]),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    v = D_80100570_CraneGame[D_800FFEC4_CraneGame];
    src = D_800FF8B0_CraneGame;
    gSPVertex(gfx++, osVirtualToPhysical(v), 3, 0);
    s = (D_80100558_CraneGame.y - D_8010056C_CraneGame) / 800.0;
    i = 0;
    if (s < 0.0) {
        s = 0.0f;
    }
    sc = s + 1.0;
    a = 176.0 - s * 176.0f * 0.7;
    do {
        v->v.ob[0] = src->v.ob[0] * sc * 1.2;
        v->v.ob[1] = src->v.ob[1] * 1.2;
        v->v.ob[2] = src->v.ob[2] * sc * 1.2;
        v->v.cn[3] = a;
        v->v.tc[0] = src->v.tc[0];
        v->v.tc[1] = src->v.tc[1];
        v->v.cn[0] = v->v.cn[1] = v->v.cn[2] = 0;
        v++;
        i++;
        src++;
    } while (i < 3);
    gSP1Triangle(gfx++, 0, 1, 2, 0);
    return gfx;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CraneGame/1B9050", func_800FCF78_CraneGame);
#endif
