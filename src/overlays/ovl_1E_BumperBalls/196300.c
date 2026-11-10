#include "BumperBalls.h"


s32 func_80024198(u32, Gfx*, s32);
s32 func_8009B850(const void*, const void*);
void func_800295FC(Vtx*, Vtx*, Vtx*, Vec3f*);
f64 func_8009B618(f64, f64); /* fmod */
void func_800FBA20_BumperBalls(void);

extern u8 D_800F37DA;
extern u8 D_800F37F0;
extern unk2C0C0Struct70* D_800F37AC;

/* .data */
u16 D_800FCBC0_BumperBalls = 0; /* set by func_800F8E40 when the minigame ends */
u16 D_800FCBC2_BumperBalls = 0; /* unreferenced filler */
/* Water texture scroll: s/t of the near edge, of the far edge (+1024), per-frame steps. */
f32 D_800FCBC4_BumperBalls = 0.0f;
f32 D_800FCBC8_BumperBalls = 0.0f;
f32 D_800FCBCC_BumperBalls = 1024.0f;
f32 D_800FCBD0_BumperBalls = 1024.0f;
f32 D_800FCBD4_BumperBalls = 12.8f;
f32 D_800FCBD8_BumperBalls = 12.8f;

void func_800FB1E0_BumperBalls(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    func_800178A0(1);
    func_800178E8();
    CZoom = arg1;
    CRot.x = arg2;
    CRot.y = arg3;
    CRot.z = arg4;
    Center.x = arg5;
    Center.y = arg6;
    Center.z = arg7;
    D_800C3110->unk_40 = arg0;
}

void func_800FB298_BumperBalls(void) {
    s32 i;
    for (i = 0; i < D_800F3778; i++) {}
}

void func_800FB2D0_BumperBalls(s32 arg0) {
    omOvlReturnEx(1);
}

// Logic-equivalent water mesh setup; wave-table addressing and register allocation differ (masked 89).
#ifdef NON_MATCHING
void func_800FB2EC_BumperBalls(void) {
    BumperBallsAnglePair* near;
    BumperBallsAnglePair* far;
    unk2C0C0Struct70* texture;
    Vtx* source;
    Vtx* dst;
    Vtx* src;
    Vtx* v;
    f32 angle;
    f32 rowAngle;
    f32 second;
    f32 farFirst;
    f32 farSecond;
    s32 x0;
    s32 x1;
    s32 z0;
    s32 z1;
    s32 row;
    s32 column;
    u16 textureId;
    u16 screen;
    u16 i;

    for (screen = 0; screen < D_800F37DA; screen++) {
        D_800FCFA8_BumperBalls[screen] = func_80023684(144 * sizeof(Vtx), 0x7918);
        D_800FCFC8_BumperBalls[screen] = func_80023684(144 * sizeof(Vtx), 0x7918);
        D_800FCF88_BumperBalls[screen] = func_80023684(0x800 * sizeof(Gfx), 0x7918);
    }
    rowAngle = 0.0f;
    angle = 0.0f;
    for (row = 0; row < 6; row++) {
        near = D_800FCD40_BumperBalls[row];
        far = D_800FCD70_BumperBalls[row * 2];
        for (column = 0; column < 6; column++) {
            second = angle + 90.0f;
            if (second >= 360.0f) {
                second -= 360.0f;
            }
            farFirst = angle + 90.0f;
            if (farFirst >= 360.0f) {
                farFirst -= 360.0f;
            }
            farSecond = angle + 180.0f;
            if (farSecond >= 360.0f) {
                farSecond -= 360.0f;
            }
            near[column].first = angle;
            near[column].second = second;
            far[column].first = farFirst;
            angle += 90.0f;
            far[column].second = farSecond;
            if (angle >= 360.0f) {
                angle -= 360.0f;
            }
        }
        rowAngle += 90.0f;
        if (rowAngle >= 360.0f) {
            rowAngle -= 360.0f;
        }
        angle = rowAngle;
    }
    source = D_800FCFA8_BumperBalls[D_800F37F0];
    for (row = 0; row < 6; row++) {
        near = D_800FCD40_BumperBalls[row];
        for (column = 0; column < 6; column++) {
            v = &source[column * 2 + row * 24];
            x0 = column * 400.0f - 1200.0f;
            v->n.ob[0] = x0;
            v->n.ob[1] = func_800AEAC0(near[column].first) * 40.0f;
            z0 = row * 400.0f - 1200.0f + -350.0f;
            v->n.ob[2] = z0;
            v->n.n[0] = 0;
            v->n.n[1] = -0x80;
            v->n.n[2] = 0;
            v->n.tc[0] = 0x400;
            v->n.tc[1] = 0;
            v->n.a = 0x90;
            v = &source[column * 2 + (row * 24 + 1)];
            x1 = (column + 1) * 400.0f - 1200.0f;
            v->n.ob[0] = x1;
            v->n.ob[1] = func_800AEAC0(near[column].second) * 40.0f;
            v->n.ob[2] = z0;
            v->n.n[0] = 0;
            v->n.n[1] = -0x80;
            v->n.n[2] = 0;
            v->n.tc[0] = 0;
            v->n.tc[1] = 0;
            v->n.a = 0x90;
            v = &source[column * 2 + (row * 2 + 1) * 12];
            v->n.ob[0] = x0;
            v->n.ob[1] = func_800AEAC0(D_800FCD70_BumperBalls[row * 2][column].first) * 40.0f;
            z1 = (row + 1) * 400.0f - 1200.0f + -350.0f;
            v->n.ob[2] = z1;
            v->n.n[0] = 0;
            v->n.n[1] = -0x80;
            v->n.n[2] = 0;
            v->n.tc[0] = 0x400;
            v->n.tc[1] = 0x400;
            v->n.a = 0x90;
            v = &source[column * 2 + ((row * 2 + 1) * 12 + 1)];
            v->n.ob[0] = x1;
            v->n.ob[1] = func_800AEAC0(D_800FCD70_BumperBalls[row * 2][column].second) * 40.0f;
            v->n.ob[2] = z1;
            v->n.n[0] = 0;
            v->n.n[1] = -0x80;
            v->n.n[2] = 0;
            v->n.tc[0] = 0;
            v->n.tc[1] = 0x400;
            v->n.a = 0x90;
        }
    }
    for (screen = 0; screen < D_800F37DA; screen++) {
        if (screen != D_800F37F0) {
            src = source;
            dst = D_800FCFA8_BumperBalls[screen];
            for (i = 0; i < 144; i++) {
                *dst++ = *src++;
            }
        }
    }
    for (screen = 0; screen < D_800F37DA; screen++) {
        src = source;
        dst = D_800FCFC8_BumperBalls[screen];
        for (i = 0; i < 144; i++) {
            *dst++ = *src++;
        }
    }
    textureId = func_8001CD00((u8*) "47mt003_DEF");
    for (i = 0; i < 0x80; i++) {
        texture = &D_800F37AC[i];
        if (texture->unk_20 == textureId && func_8009B850(texture, "47mt003_DEF") == 0) {
            break;
        }
    }
    D_800FCF80_BumperBalls = &D_800F37AC[i];
    textureId = func_8001CD00((u8*) "47mt002_IA44");
    for (i = 0; i < 0x80; i++) {
        texture = &D_800F37AC[i];
        if (texture->unk_20 == textureId && func_8009B850(texture, "47mt002_IA44") == 0) {
            break;
        }
    }
    D_800FCF84_BumperBalls = &D_800F37AC[i];
    func_800FBA20_BumperBalls();
    D_800FCFE8_BumperBalls = func_80024198(0x681, D_800FCF88_BumperBalls[D_800F37F0], 4);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1E_BumperBalls/196300", func_800FB2EC_BumperBalls);
#endif

void func_800FBA20_BumperBalls(void) {
    unk2C0C0Struct70* tex;
    Gfx* gfx;
    s32 screen;
    s32 row;
    s32 column;

    for (screen = 0; screen < D_800F37DA; screen++) {
        gfx = D_800FCF88_BumperBalls[screen];
        gDPPipeSync(gfx++);
        gSPSetOtherMode(gfx++, G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, 0x504A50);
        gSPClearGeometryMode(gfx++, G_LIGHTING);
        gDPSetTextureFilter(gfx++, G_TF_BILERP);
        gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
        gDPSetPrimColor(gfx++, 0, 0, 0x1E, 0x5E, 0xBC, 0xB0);
        gDPSetCombineLERP(gfx++, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0,
            TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetTextureLUT(gfx++, G_TT_NONE);
        switch (D_800FCF84_BumperBalls->unk_19) {
            case G_IM_SIZ_16b:
                D_800ED568 = G_IM_SIZ_16b_LOAD_BLOCK;
                D_800ED734 = G_IM_SIZ_16b_INCR;
                D_800F64C0 = G_IM_SIZ_16b_BYTES;
                D_800EC6F4 = G_IM_SIZ_16b_LINE_BYTES;
                D_800F37E4 = G_IM_SIZ_16b_SHIFT;
                break;
            case G_IM_SIZ_8b:
                D_800ED568 = G_IM_SIZ_8b_LOAD_BLOCK;
                D_800ED734 = G_IM_SIZ_8b_INCR;
                D_800F64C0 = G_IM_SIZ_8b_BYTES;
                D_800EC6F4 = G_IM_SIZ_8b_LINE_BYTES;
                D_800F37E4 = G_IM_SIZ_8b_SHIFT;
                break;
            case G_IM_SIZ_4b:
                D_800ED568 = G_IM_SIZ_4b_LOAD_BLOCK;
                D_800ED734 = G_IM_SIZ_4b_INCR;
                D_800F64C0 = G_IM_SIZ_4b_BYTES;
                D_800EC6F4 = G_IM_SIZ_4b_LINE_BYTES;
                D_800F37E4 = G_IM_SIZ_4b_SHIFT;
                break;
            default:
                D_800ED568 = G_IM_SIZ_32b_LOAD_BLOCK;
                D_800ED734 = G_IM_SIZ_32b_INCR;
                D_800F64C0 = G_IM_SIZ_32b_BYTES;
                D_800EC6F4 = G_IM_SIZ_32b_LINE_BYTES;
                D_800F37E4 = G_IM_SIZ_32b_SHIFT;
                break;
        }
        gDPSetTextureImage(gfx++, D_800FCF84_BumperBalls->unk_18, D_800ED568, 1, D_800FCF84_BumperBalls->unk_24);
        gDPSetTile(gfx++, D_800FCF84_BumperBalls->unk_18, D_800ED568, 0, 0x0000, G_TX_LOADTILE, 0,
            G_TX_WRAP, INTEGER_LOG2(D_800FCF84_BumperBalls->unk_1B), G_TX_NOLOD,
            G_TX_WRAP, INTEGER_LOG2(D_800FCF84_BumperBalls->unk_1A), G_TX_NOLOD);
        gDPLoadSync(gfx++);
        gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, 0,
            ((D_800FCF84_BumperBalls->unk_1A * D_800FCF84_BumperBalls->unk_1B + D_800ED734) >> D_800F37E4) - 1,
            CALC_DXT(D_800FCF84_BumperBalls->unk_1A, D_800F64C0));
        gDPPipeSync(gfx++);
        gDPSetTile(gfx++, D_800FCF84_BumperBalls->unk_18, D_800FCF84_BumperBalls->unk_19,
            (D_800FCF84_BumperBalls->unk_1A * D_800EC6F4 + 7) >> 3, 0x0000, G_TX_RENDERTILE, 0,
            G_TX_WRAP, INTEGER_LOG2(D_800FCF84_BumperBalls->unk_1B), G_TX_NOLOD,
            G_TX_WRAP, INTEGER_LOG2(D_800FCF84_BumperBalls->unk_1A), G_TX_NOLOD);
        gDPSetTileSize(gfx++, G_TX_RENDERTILE, 0, 0, (D_800FCF84_BumperBalls->unk_1A - 1) * 4,
            (D_800FCF84_BumperBalls->unk_1B - 1) * 4);
        for (row = 0; row < 6; row++) {
            gSPVertex(gfx++, D_800FCFC8_BumperBalls[screen] + (row * 24), 24, 0);
            for (column = 0; column < 6; column++) {
                gSP2Triangles(gfx++, column * 2, column * 2 + 1, column * 2 + 12, 0,
                    column * 2 + 1, column * 2 + 13, column * 2 + 12, 0);
            }
        }
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0xB2, 0xB2, 0xB2, 0xA0);
        gDPSetCombineLERP(gfx++, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE,
            TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE);
        gDPSetTextureLUT(gfx++, G_TT_RGBA16);
        gDPLoadTLUT_pal16(gfx++, 0, D_800FCF80_BumperBalls->unk_2C->unk_24);
        gDPLoadTextureBlock_4b(gfx++, D_800FCF80_BumperBalls->unk_24,
            D_800FCF80_BumperBalls->unk_18,
            D_800FCF80_BumperBalls->unk_1A, D_800FCF80_BumperBalls->unk_1B, 0,
            G_TX_WRAP, G_TX_WRAP, INTEGER_LOG2(D_800FCF80_BumperBalls->unk_1A),
            INTEGER_LOG2(D_800FCF80_BumperBalls->unk_1B), G_TX_NOLOD, G_TX_NOLOD);
        for (row = 0; row < 6; row++) {
            gSPVertex(gfx++, D_800FCFA8_BumperBalls[screen] + (row * 24), 24, 0);
            for (column = 0; column < 6; column++) {
                gSP2Triangles(gfx++, column * 2, column * 2 + 1, column * 2 + 12, 0,
                    column * 2 + 1, column * 2 + 13, column * 2 + 12, 0);
            }
        }
        gDPPipeSync(gfx++);
        gSPEndDisplayList(gfx++);
    }
}

// register allocation (column counter and v1 swap s3/s4; masked 0)
#ifdef NON_MATCHING
void func_800FC618_BumperBalls(void) {
    Vec3f normal;
    f32* p;
    Vtx* vertices;
    Vtx* v0;
    Vtx* v2;
    Vtx* v1;
    Vtx* v3;
    Vtx* src;
    Vtx* dst;
    f32 angle;
    s32 row;
    s32 column;
    s32 k;

    *D_800F2B7C[D_800FCFE8_BumperBalls].unk_6C->unk_00 = D_800FCF88_BumperBalls[D_800F37F0];
    vertices = D_800FCFA8_BumperBalls[D_800F37F0];
    for (row = 0; row < 6; row++) {
        for (column = 0; column < 6; column++) {
            p = &D_800FCD40_BumperBalls[row][column].first;
            angle = *p + 4.0f;
            *p = angle;
            if (angle >= 360.0f) {
                *p = angle - 360.0f;
            }
            v0 = &vertices[column * 2 + row * 24];
            v0->n.ob[1] = func_800AEAC0(*p) * 40.0f;
            v0->n.tc[0] = D_800FCBC4_BumperBalls;
            v0->n.tc[1] = D_800FCBC8_BumperBalls;
            p++;
            angle = *p + 4.0f;
            *p = angle;
            if (angle >= 360.0f) {
                *p = angle - 360.0f;
            }
            v1 = v0 + 1;
            v1->n.ob[1] = func_800AEAC0(*p) * 40.0f;
            v1->n.tc[0] = D_800FCBCC_BumperBalls;
            v1->n.tc[1] = D_800FCBC8_BumperBalls;
            p = &BB_WAVE_FAR[row][column].first;
            angle = *p + 4.0f;
            *p = angle;
            if (angle >= 360.0f) {
                *p = angle - 360.0f;
            }
            v2 = &vertices[column * 2 + (row * 2 + 1) * 12];
            v2->n.ob[1] = func_800AEAC0(*p) * 40.0f;
            v2->n.tc[0] = D_800FCBC4_BumperBalls;
            v2->n.tc[1] = D_800FCBD0_BumperBalls;
            p++;
            angle = *p + 4.0f;
            *p = angle;
            if (angle >= 360.0f) {
                *p = angle - 360.0f;
            }
            v3 = v2 + 1;
            v3->n.ob[1] = func_800AEAC0(*p) * 40.0f;
            v3->n.tc[0] = D_800FCBCC_BumperBalls;
            v3->n.tc[1] = D_800FCBD0_BumperBalls;
            func_800295FC(v0, v1, v2, &normal);
            for (k = 0; k < 3; k++) {
                v0->n.n[k] = ((f32*) &normal)[k] * 127.0f;
                v1->n.n[k] = ((f32*) &normal)[k] * 127.0f;
                v2->n.n[k] = ((f32*) &normal)[k] * 127.0f;
                v3->n.n[k] = ((f32*) &normal)[k] * 127.0f;
            }
        }
    }
    D_800FCBC4_BumperBalls += D_800FCBD4_BumperBalls;
    D_800FCBC8_BumperBalls += D_800FCBD8_BumperBalls;
    D_800FCBC4_BumperBalls = func_8009B618(D_800FCBC4_BumperBalls, 1024.0);
    D_800FCBC8_BumperBalls = func_8009B618(D_800FCBC8_BumperBalls, 1024.0);
    D_800FCBCC_BumperBalls = D_800FCBC4_BumperBalls + 1024.0f;
    D_800FCBD0_BumperBalls = D_800FCBC8_BumperBalls + 1024.0f;
    src = D_800FCFA8_BumperBalls[D_800F37F0];
    dst = D_800FCFC8_BumperBalls[D_800F37F0];
    for (k = 0; k < 144; k++) {
        dst->n.ob[1] = src->n.ob[1];
        dst->n.n[0] = src->n.n[0];
        dst->n.n[1] = src->n.n[1];
        dst->n.n[2] = src->n.n[2];
        src++;
        dst++;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1E_BumperBalls/196300", func_800FC618_BumperBalls);
#endif
