#include "common.h"
#include "engine/mallocblock.h"

typedef struct unk24740Floats8 {
    /* 0x00 */ f32 v[8];
} unk24740Floats8;

typedef unk34D80Struct80 unk24740Struct18; /* D_800ED554 entries (common_structs.h) */

extern u8 D_800C30C0;
extern u8 D_800C30C1;
extern u8 D_800C30C2;
extern const f32 D_800CA8D8[];
extern unk2C0C0StructC0 D_800ECB40;
extern u16 D_800ECE18[4];
extern void (*D_800ED3E4[2])(Gfx**, Mtx*, u8);
extern unk24740Struct18* D_800ED554;
extern u8 D_800ED6BC;
extern u16 D_800ED728;
extern u16 D_800F2D00[4][128];
extern s32 D_800F3758;
extern unk2C0C0Struct70* D_800F37AC;
extern s8 D_800F384E;

void func_8001D658(s16, Gfx**);
void func_800238F0(s16);
void func_80023964(void);
Gfx* func_800253EC(Gfx*, s16, u16);
void func_80026EA8(unk2C0C0StructC0*, f32, f32, u16, u16);
void func_80027100(unk2C0C0StructC0*, f32, f32, u16, u16);
void func_80027440(unk2C0C0StructC0*, f32, f32, u16, u16);
void func_8002854C(void);
void func_80028668(unk_ovl_2D_struct*, u16);
void func_80028A34(s16);
void func_8002AD04(void);
void func_8002AD30(s16);
void func_8002B4C0(void* (*arg0)(s32), void (*arg1)(void*), u16 arg2, u16 arg3, u16 arg4, u8 arg5);
void func_8002B6C8(void);
void func_8002B808(void);
void func_8002C1A8(unk2C0C0StructC0*, Matrix4f, Matrix4f);
Gfx* func_8002D614(s16, Gfx*, Gfx*);
void func_800337E4(unk2C0C0StructC0*, char*, unk2C0C0StructC0*);
void func_80034180(void);
void func_800343C8(s16);
void func_80034420(void);
void func_800363C8(unk2C0C0StructC0*);
void func_800368AC(unk2C0C0StructC0*, f32);
f32 func_800369FC(unk24740Struct18*, s16, f32, f32, f32);
void func_80037FA0(unk2C0C0StructC0*);
unk2C0C0Struct70* func_80038178(unk2C0C0StructC0*);
void func_800397AC(u16);
void func_80039AEC(void);
void func_80039BAC(void);
void func_800721D8(Gfx**);
s32 func_8009B850(unk2C0C0Struct70*, u8*);
void func_800A0B90(Matrix4f, void*);
Gfx* pfDrawFonts(Gfx*);
void guMtxCatF(float m[4][4], float n[4][4], float r[4][4]);
void guMtxL2F(float mf[4][4], Mtx* m);

#define CAM ((unk_Struct00*)D_800F32A0)

s32 D_800C32B0 = 0;
Gfx D_800C32B8[] = {
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
Gfx D_800C3370[] = {
    gsSPClearGeometryMode(0xFFFFFFFF),
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClipRatio(FRUSTRATIO_2),
    gsSPSetGeometryMode(G_SHADE | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

#define qu016(x) ((int)((x) * 65536.0f))

Gfx D_800C33B0[] = {
    gsSPDisplayList(D_800C3370),
    gsSPDisplayList(D_800C32B8),
    gsSPEndDisplayList()
};

Gfx D_800C33C8[] = {
    gsDPPipeSync(),
    gsSPDisplayList(D_800C33B0),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPSetGeometryMode(G_ZBUFFER | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x00),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0xFF),
    gsSPTexture(qu016(0.999985), qu016(0.999985), 0, G_TX_RENDERTILE, G_ON),
    gsSPEndDisplayList()
};

Gfx D_800C3408[] = {
    gsDPPipeSync(),
    gsSPDisplayList(D_800C3370),
    gsSPDisplayList(D_800C32B8),
    gsDPFullSync(),
    gsSPEndDisplayList()
};

Gfx D_800C3430[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_FILL),
    gsDPSetRenderMode(G_RM_NOOP, G_RM_NOOP2),
    gsDPSetFillColor(0xFFFCFFFC),
    gsDPFillRectangle(0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1),
    gsSPEndDisplayList()
};

Gfx D_800C3460[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_FILL),
    gsDPSetRenderMode(G_RM_NOOP, G_RM_NOOP2),
    gsDPFillRectangle(0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1),
    gsDPNoOp(),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPEndDisplayList(),
};

s16 D_800C34A0 = 1;
f32 D_800C34A4 = 0.0f;
//padding?
f32 D_800C34A8[] = {0.0f, 0.0f};

extern const char D_800CA8C4[];
extern s32 D_800ECB14;

void func_80023B40(void* (*arg0)(s32), void (*arg1)(void*), u16 arg2, u16 arg3, u16 arg4, u8 arg5) {
    s16 i;

    func_8002B4C0(arg0, arg1, arg2, arg3, arg4, arg5);
    func_80034180();
    D_800F2B7C = func_80023668(128 * sizeof(*D_800F2B7C));
    for (i = 0; i < 128; i++) {
        D_800F2B7C[i].unk_6C = NULL;
    }
    func_8002B6C8();
    D_800F3848 = 0;
    D_800F3758 = 0;
    D_800F3854 = 1;
    D_800F384E = 0;
    D_800ED6BC = 1;
    D_800ED3E4[0] = D_800ED3E4[1] = NULL;
}
s32 LoadFormBinary(u8* arg0, u32 arg1) {
    unk2C0C0StructC0* temp_v0;
    unk_ovl_2D_struct* temp_s0;
    s16 i;
    s16 j;

    for (i = 0; i < 128; i++) {
        if (D_800F2B7C[i].unk_6C == NULL) {
            break;
        }
    }

    if (i == 128) {
        osSyncPrintf(D_800CA8C4);
        return -1;
    }

    D_800F502C = i * 2 + 10000;
    D_800EE32E = i * 2 + 10001;

    temp_s0 = &D_800F2B7C[i];
    temp_v0 = temp_s0->unk_6C = func_80023668(sizeof(unk2C0C0StructC0));
    temp_v0->unk_68 = D_800F502C;

    if (arg0[0] == 77 && arg0[1] == 84 && arg0[2] == 78 && arg0[3] == 88) {
        temp_v0->unk_6E = 0;
        temp_v0->unk_A4 = NULL;
        temp_v0->unk_60 = NULL;
        temp_s0->unk_08 = func_800342BC(arg0);

        arg1 &= ~(0x10 | 0x01);
        if (temp_v0->unk_6E == 0) {
            arg1 |= 4;
        }
    } else {
        func_8001AC00(temp_v0, arg0, arg1);

        if (temp_v0->unk_60 != NULL) {
            func_80023AF0(temp_v0->unk_78, D_800EE32E);
            temp_s0->unk_04 = func_80029174(i);
        } else {
            temp_s0->unk_04 = -1;
        }

        temp_v0->unk_28 = (arg1 >> 10) & 7;
        temp_s0->unk_20 = arg1;
        temp_s0->unk_08 = func_800341E8(arg0, temp_v0);

        if (temp_s0->unk_08 != -1) {
            if (temp_v0->unk_6E == 0) {
                func_8001B1D4(temp_v0);
                if (temp_v0->unk_6E == 0) {
                    arg1 |= 4;
                }
            }
        } else {
            if (temp_v0->unk_6E == 0) {
                arg1 |= 4;
            }
        }
    }

    temp_s0->unk_20 = arg1;

    if (arg1 & 8) {
        D_800F33A4(arg0);
    }

    if (arg1 & 1) {
        D_800ECB14 = temp_s0->unk_20;
        func_8002B890(temp_v0);
    }

    temp_v0->unk_66 = 1;

    if (arg1 & 0x10) {
        for (j = 0; j < temp_v0->unk_6A; j++) {
            if (temp_v0->unk_80[j].unk_14 & 0x06000000) {
                break;
            }
        }
        if (j == temp_v0->unk_6A) {
            func_800237BC(D_800F502C);
        }
    }

    temp_s0->unk_48 = temp_s0->unk_0A = temp_s0->unk_50 =
        temp_s0->unk_54 = temp_s0->unk_0E = temp_s0->unk_5C =
        temp_s0->unk_60 = temp_s0->unk_16 = temp_s0->unk_68 = 0;
    temp_s0->unk_4C = temp_s0->unk_58 = temp_s0->unk_64 = 1.0f;
    temp_s0->unk_1A = temp_s0->unk_0C = temp_s0->unk_14 = -1;
    temp_s0->unk_24 = temp_s0->unk_28 = temp_s0->unk_2C = 0.0f;
    temp_s0->unk_30 = temp_s0->unk_34 = temp_s0->unk_38 = 0.0f;
    temp_s0->unk_3C = temp_s0->unk_40 = temp_s0->unk_44 = 1.0f;
    temp_s0->unk_02 = -1;
    temp_s0->unk_00 = 0;

    func_800A2A50(temp_s0->unk7C);
    return i;
}

s16 func_80023FC8(s16 arg0) {
    unk_ovl_2D_struct* temp_a0;
    s16 i;

    for (i = 0; i < 128; i++) {
        if (D_800F2B7C[i].unk_6C == NULL) {
            break;
        }
    }

    if (i == 128) {
        osSyncPrintf(D_800CA8C4);
        return -1;
    }

    temp_a0 = &D_800F2B7C[i];
    temp_a0->unk_6C = D_800F2B7C[arg0].unk_6C;
    temp_a0->unk_20 = D_800F2B7C[arg0].unk_20;
    temp_a0->unk_00 = D_800F2B7C[arg0].unk_00;
    temp_a0->unk_04 = D_800F2B7C[arg0].unk_04;
    temp_a0->unk_08 = D_800F2B7C[arg0].unk_08;
    temp_a0->unk_6C->unk_66++;
    temp_a0->unk_48 = temp_a0->unk_0A = temp_a0->unk_50 =
        temp_a0->unk_54 = temp_a0->unk_0E = temp_a0->unk_5C =
        temp_a0->unk_60 = temp_a0->unk_16 = temp_a0->unk_68 = 0;
    temp_a0->unk_4C = temp_a0->unk_58 = temp_a0->unk_64 = 1.0f;
    temp_a0->unk_1A = temp_a0->unk_0C = temp_a0->unk_14 = -1;
    temp_a0->unk_24 = temp_a0->unk_28 = temp_a0->unk_2C = 0.0f;
    temp_a0->unk_30 = temp_a0->unk_34 = temp_a0->unk_38 = 0.0f;
    temp_a0->unk_3C = temp_a0->unk_40 = temp_a0->unk_44 = 1.0f;
    temp_a0->unk_02 = -1;
    func_800A2A50(temp_a0->unk7C);
    return i;
}
s16 func_80024198(u32 arg0, Gfx* arg1, s32 arg2) {
    unk2C0C0StructC0* temp_v0;
    unk_ovl_2D_struct* temp_s0;
    s16 i;

    for (i = 0; i < 128; i++) {
        if (D_800F2B7C[i].unk_6C == NULL) {
            break;
        }
    }

    if (i == 128) {
        osSyncPrintf(D_800CA8C4);
        return -1;
    }

    D_800F502C = i * 2 + 10000;
    D_800EE32E = i * 2 + 10001;
    temp_s0 = &D_800F2B7C[i];
    temp_v0 = temp_s0->unk_6C = func_80023684(sizeof(unk2C0C0StructC0), D_800EE32E);
    temp_v0->unk_68 = D_800F502C;
    temp_v0->unk_00 = (Gfx**)arg1;
    temp_v0->unk_66 = 1;
    temp_v0->unk_28 = (arg0 >> 10) & 7;
    temp_s0->unk_78 = NULL;
    temp_s0->unk_6C->unk_B8 = NULL;
    temp_s0->unk_20 = arg0 | 1;
    temp_s0->unk_48 = temp_s0->unk_0A = temp_s0->unk_50 =
        temp_s0->unk_54 = temp_s0->unk_0E = temp_s0->unk_5C = 0;
    temp_s0->unk_4C = temp_s0->unk_58 = 1.0f;
    temp_s0->unk_1A = temp_s0->unk_08 = temp_s0->unk_0C = -1;
    temp_s0->unk_24 = temp_s0->unk_28 = temp_s0->unk_2C = 0.0f;
    temp_s0->unk_30 = temp_s0->unk_34 = temp_s0->unk_38 = 0.0f;
    temp_s0->unk_3C = temp_s0->unk_40 = temp_s0->unk_44 = 1.0f;

    switch (arg2 & 6) {
        case 4:
            func_800A2A50(temp_s0->unk7C);
            temp_v0->unk_00 = func_80023684(sizeof(Gfx*), D_800EE32E);
            *temp_v0->unk_00 = arg1;
            temp_v0->unk_80 = func_80023684(sizeof(unk2C0C0Struct30), D_800EE32E);
            temp_v0->unk_6A = 1;
            temp_v0->unk_40 = temp_v0->unk_44 = temp_v0->unk_48 = temp_v0->unk_4C =
                temp_v0->unk_50 = temp_v0->unk_54 = temp_v0->unk_58 = temp_v0->unk_5C =
                temp_v0->unk_60 = NULL;
            temp_v0->unk_6E = 1;
            temp_v0->unk_80->unk_14 = 0;
            temp_v0->unk_80->unk_02 = -1;
            temp_v0->unk_64 = 0;
            temp_v0->unk_80->unk_4A = temp_v0->unk_80->unk_4C = temp_v0->unk_80->unk_4E = -0x8000;
            temp_v0->unk_80->unk_50 = temp_v0->unk_80->unk_52 = temp_v0->unk_80->unk_54 = -0x8000;
        case 0:
        case 2:
            temp_s0->unk_02 = -1;
            break;
        case 6:
            temp_s0->unk_02 = 0;
            break;
    }
    temp_s0->unk_00 = arg2 | 1;
    return i;
}
s16 func_80024464(s16 arg0, s8 arg1) {
    s16 temp_v0 = func_80023FC8(arg0);

    if (temp_v0 < 0) {
        return -1;
    }
    D_800F2B7C[temp_v0].unk_00 = arg1;
    return temp_v0;
}
void func_800244C4(s16 arg0, u8 arg1) {
    unk_ovl_2D_struct* temp_v1;

    temp_v1 = &D_800F2B7C[arg0];
    temp_v1->unk_00 &= ~6;
    temp_v1->unk_00 |= 1;
    temp_v1->unk_00 |= arg1;
    if (arg1 == 6) {
        temp_v1->unk_02 = 0;
    } else {
        temp_v1->unk_02 = -1;
    }
}
s16 func_8002451C(u32 arg0, void (*arg1)(Gfx**, Mtx*, camera*), u8 arg2) {
    s16 i = func_80024198(arg0, NULL, arg2);
    unk_ovl_2D_struct* p = &D_800F2B7C[i];

    p->unk_78 = arg1;
    return i;
}
void func_8002456C(s16 arg0) {
    unk2C0C0StructC0* model;

    if (D_800F2B7C[arg0].unk_6C == NULL) {
        return;
    }
    if (D_800F2B7C[arg0].unk_1A != -1 && D_800F2B7C[arg0].unk_1C != 0.0f) {
        model = D_800F2B7C[arg0].unk_74;
    } else {
        model = D_800F2B7C[arg0].unk_6C;
    }
    D_800F2B7C[arg0].unk_6C = NULL;
    if (D_800F2B7C[arg0].unk_00 & 1) {
        if (--model->unk_66 == 0) {
            func_800238F0(model->unk_68);
            func_800238F0(model->unk_68 + 1);
        }
    } else if ((u8)D_800F2B7C[arg0].unk_00 == 0) {
        if (--model->unk_66 == 0) {
            func_800238F0(model->unk_68);
            func_800238F0(model->unk_68 + 1);
            func_80037FA0(model);
            if (model->unk_60 != NULL) {
                func_8002AD30(D_800F2B7C[arg0].unk_04);
            }
            func_80023888(model);
            if (D_800F2B7C[arg0].unk_08 != -1) {
                func_800343C8(D_800F2B7C[arg0].unk_08);
            }
        }
    }
}
void func_80024754(void) {
    s16 i;

    for (i = 0; i < 128; i++) {
        if (D_800F2B7C[i].unk_6C != NULL) {
            func_8002456C(i);
        }
    }
    func_80039BAC();
    func_80039AEC();
    func_8002AD04();
    func_80034420();
    func_8002854C();
    D_800ED3E4[0] = D_800ED3E4[1] = NULL;
}
// register allocation; D_800ED0D8 address not folded into the load (masked 25)
#ifdef NON_MATCHING
void func_800247FC(OSMesgQueue* arg0, s32 arg1) {
    Matrix4f sp18;
    Matrix4f sp58;
    Matrix4f sp98;
    unk_ovl_2D_struct* p;
    Gfx* gfx;
    Gfx* var_s4;
    Gfx* var_s6;
    Gfx* var_s2;
    s32 mask;
    s16 i;
    s16 layer;
    s16 temp;

    if (D_800F3854 == 0) {
        return;
    }

    gSPEndDisplayList(D_800F37DC++);
    D_800ECE18[0] = D_800ECE18[1] = D_800ECE18[2] = D_800ECE18[3] = 0;

    for (i = 0; i < 128; i++) {
        p = &D_800F2B7C[i];
        if (p->unk_6C != NULL && !(p->unk_20 & 4) && (u8)p->unk_00 != 0) {
            layer = 0;
            switch ((u8)p->unk_00 & 6) {
                case 6:
                    layer++;
                case 4:
                    layer++;
                case 2:
                    layer++;
                case 0:
                    D_800F2D00[layer][D_800ECE18[layer]] = i;
                    D_800ECE18[layer]++;
                    break;
            }
        }
    }

    var_s2 = D_800F37E0;
    D_800EE754 = 0;
    for (layer = 0; layer < D_800ECB00; layer++) {
        if (var_s2 == NULL) {
            gfx = func_800253EC(var_s4, 1, mask);
            gDPFullSync(D_800F37DC++);
            gSPEndDisplayList(D_800F37DC++);
            func_8001AAC4(gfx, D_800EE754, 0, NULL, 0);
        }
        func_8002B808();
        D_800F32A0 = (camera*)&D_800C3110[layer];
        D_800F2BCC = (Mtx*)((u8*)D_800F32A0 + 0xF8 + D_800F3FA8 * 0x80);
        var_s4 = D_800F37DC;
        func_8001D658(layer, &D_800F37DC);
        func_8001D7DC(layer, &D_800F37DC);
        mask = 1 << layer;
        gSPDisplayList(D_800F37DC++, D_800C33C8);
        gSPEndDisplayList(D_800F37DC++);
        var_s6 = D_800F37DC;
        if (var_s2 != NULL) {
            gSPDisplayList(D_800F37DC++, var_s2);
        }
        func_8001D7DC(layer, &D_800F37DC);
        if (CAM->unkF0 != 0) {
            ((void (*)(s16))CAM->unkF0)(layer);
        }
        if (D_800ED3E4[0] != NULL) {
            D_800ED3E4[0](&D_800F37DC, D_800F2BCC, layer);
        }
        if (D_800ED3E4[1] != NULL) {
            D_800ED3E4[1](&D_800F37DC, D_800F2BCC, layer);
        }
        var_s6 = func_800253EC(var_s6, 0, mask);
        gSPEndDisplayList(D_800F37DC++);
        temp = func_80061228(0, 200, 0);

        for (i = 0; i < 128; i++) {
            p = &D_800F2B7C[i];
            if (p->unk_6C != NULL && !(p->unk_20 & 4) && (mask & (u16)p->unk_02) &&
                ((u8)p->unk_00 == 0 || ((u8)p->unk_00 & 6) == 4)) {
            if (p->unk_6C->unk_60 != NULL && CAM->unkE8 != 0) {
                ((void (*)(s32, unk_ovl_2D_struct*))CAM->unkE8)(CAM->unkEC, p);
            } else {
            if (p->unk_1A != -1) {
                func_80028A34(i);
            }
            p->unk_6C->unk_64 = 1;
            p->unk_6C->unk_29 = p->unk_00;
            D_800ECB14 = p->unk_20;
            if (!(p->unk_20 & 0x40000)) {
                guMtxL2F(sp98, D_800F2BCC + 1);
                if (p->unk_24 != 0.0f || p->unk_28 != 0.0f || p->unk_2C != 0.0f) {
                    MtxTranslate(sp98, p->unk_24, p->unk_28, p->unk_2C);
                }
                if (p->unk_30 != 0.0f || p->unk_34 != 0.0f || p->unk_38 != 0.0f) {
                    MtxRotate(sp98, p->unk_30, p->unk_34, p->unk_38);
                }
                if (p->unk_3C != 1.0f || p->unk_40 != 1.0f || p->unk_44 != 1.0f) {
                    MtxScale(sp98, p->unk_3C, p->unk_40, p->unk_44);
                    sp58[0][0] = p->unk_3C;
                    sp58[1][1] = p->unk_40;
                    sp58[2][2] = p->unk_44;
                    sp58[3][3] = 1.0f;
                    sp58[0][1] = sp58[0][2] = sp58[0][3] = sp58[1][0] = sp58[1][2] = sp58[1][3] =
                        sp58[2][0] = sp58[2][1] = sp58[2][3] = sp58[3][0] = sp58[3][1] = sp58[3][2] = 0.0f;
                } else {
                    func_800A2A50(sp58);
                }
                guMtxCatF(p->unk7C, sp98, sp18);
            } else {
                func_8002C37C(sp18, p->unk7C);
                if (p->unk_24 != 0.0f || p->unk_28 != 0.0f || p->unk_2C != 0.0f) {
                    MtxTranslate(sp18, p->unk_24, p->unk_28, p->unk_2C);
                }
                if (p->unk_30 != 0.0f || p->unk_34 != 0.0f || p->unk_38 != 0.0f) {
                    MtxRotate(sp18, p->unk_30, p->unk_34, p->unk_38);
                }
                if (p->unk_3C != 1.0f || p->unk_40 != 1.0f || p->unk_44 != 1.0f) {
                    MtxScale(sp18, p->unk_3C, p->unk_40, p->unk_44);
                    sp58[0][0] = p->unk_3C;
                    sp58[1][1] = p->unk_40;
                    sp58[2][2] = p->unk_44;
                    sp58[3][3] = 1.0f;
                    sp58[0][1] = sp58[0][2] = sp58[0][3] = sp58[1][0] = sp58[1][2] = sp58[1][3] =
                        sp58[2][0] = sp58[2][1] = sp58[2][3] = sp58[3][0] = sp58[3][1] = sp58[3][2] = 0.0f;
                } else {
                    func_800A2A50(sp58);
                }
            }
            if (p->unk_08 != -1) {
                p->unk_6C->unk_AC = (s32)&D_800ED554[p->unk_08];
                p->unk_6C->unk_C0 = p->unk_48;
                if (p->unk_14 != -1) {
                    p->unk_6C->unk_B4 = (s32)&D_800ED554[p->unk_14];
                    p->unk_6C->unk_CC = p->unk_60;
                } else {
                    p->unk_6C->unk_B4 = 0;
                }
                if (p->unk_0C != -1 && p->unk_10 != 0) {
                    p->unk_6C->unk_B0 = (s32)&D_800ED554[p->unk_0C];
                    *(f32*)&p->unk_6C->unk_C4 = p->unk_54;
                    *(f32*)&p->unk_6C->unk_C8 = (f32)p->unk_12 / (f32)p->unk_10;
                    if (D_800F384E == 0) {
                        p->unk_12 = arg1 + p->unk_12;
                    }
                    if (p->unk_12 >= p->unk_10) {
                        p->unk_08 = p->unk_0C;
                        p->unk_48 = p->unk_54;
                        p->unk_0A = p->unk_0E;
                        p->unk_50 = p->unk_5C;
                        p->unk_0C = -1;
                    }
                } else {
                    p->unk_6C->unk_B0 = 0;
                }
            } else {
                unk2C0C0StructC0* model = p->unk_6C;
                model->unk_AC = model->unk_B0 = model->unk_B4 = 0;
            }
            if (D_800ECB14 & 0x4000) {
                func_800A0B90(sp18, D_800ED0D8[p->unk_70->unk_28][p->unk_70->unk_80[p->unk_18].unk_12].unk_44);
            }
            func_8002C1A8(p->unk_6C, sp18, sp58);
            if (p->unk_6C->unk_B8 != NULL) {
                func_800363C8(p->unk_6C);
            }
        }
            }
            }
        func_80061264(temp);
        var_s4 = func_8002D614(layer, var_s4, var_s6);
        var_s2 = NULL;
        if (CAM->unkF4 != 0) {
            ((void (*)(s16))CAM->unkF4)(layer);
        }
    }

    for (i = 0; i < 128; i++) {
        p = &D_800F2B7C[i];
        if (p->unk_6C != NULL && !(p->unk_20 & 4) && (D_800F384E == 0 || (p->unk_20 & 0x8000))) {
            if (p->unk_6C->unk_B8 != NULL && (u8)p->unk_00 == 0) {
                func_800368AC(p->unk_6C, (u16)arg1 * p->unk_4C);
            }
            if (p->unk_08 != -1) {
                func_80028668(p, arg1);
            }
        }
    }
    if (D_800F384E == 0) {
        func_800397AC(arg1);
    }
    gfx = func_800253EC(var_s4, 1, mask);
    gDPSetScissor(D_800F37DC++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    var_s4 = func_800253EC(gfx, 3, 0);
    gDPSetScissor(D_800F37DC++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800721D8(&D_800F37DC);
    D_800F37DC = pfDrawFonts(D_800F37DC);
    gDPFullSync(D_800F37DC++);
    gSPEndDisplayList(D_800F37DC++);
    func_8001AAC4(var_s4, D_800EE754, 1, arg0, 0x309);
    D_800C32B0++;
}
#else
INCLUDE_ASM("asm/nonmatchings/24740", func_800247FC);
#endif
Gfx* func_800253EC(Gfx* arg0, s16 arg1, u16 arg2) {
    unk_ovl_2D_struct* p;
    s16 i;

    for (i = 0; i < D_800ECE18[arg1]; i++) {
        p = &D_800F2B7C[D_800F2D00[arg1][i]];
        if (!(p->unk_02 & arg2) && arg2 != 0) {
            continue;
        }
        D_800ED728 = D_800F2D00[arg1][i];
        if (p->unk_6C->unk_28 != D_800EE754) {
            gDPFullSync(D_800F37DC++);
            gSPEndDisplayList(D_800F37DC++);
            func_8001AAC4(arg0, D_800EE754, 0, NULL, 0);
            D_800EE754 = p->unk_6C->unk_28;
            arg0 = D_800F37DC;
        }
        if (p->unk_78 != NULL) {
            p->unk_78(&D_800F37DC, D_800F2BCC, D_800F32A0);
        } else if (p->unk_6C->unk_00 != NULL) {
            gSPDisplayList(D_800F37DC++, p->unk_6C->unk_00);
        }
    }
    return arg0;
}
void func_800255DC(void) {
    s16 i;

    func_80023964();
    for (i = 0; i < 128; i++) {
        D_800F2B7C[i].unk_6C = NULL;
    }
    D_800C3110 = NULL;
    D_800ECB00 = 0;
    D_800F37F0 = 0;
    D_800F3854 = 0;
}
void func_80025658(void* arg0, void* arg1) {
    gSPSegment(D_800F37DC++, 0, 0);
    gSPDisplayList(D_800F37DC++, D_800C33B0);
    gDPSetDepthImage(D_800F37DC++, arg1);
    gDPSetColorImage(D_800F37DC++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, arg1);
    gSPDisplayList(D_800F37DC++, D_800C3430);
    gDPSetColorImage(D_800F37DC++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, arg0);
    if (D_800ED6BC != 0) {
        gDPSetFillColor(D_800F37DC++, GPACK_RGBA5551(D_800C30C0, D_800C30C1, D_800C30C2, 1) << 16 |
                                      GPACK_RGBA5551(D_800C30C0, D_800C30C1, D_800C30C2, 1));
        gSPDisplayList(D_800F37DC++, D_800C3460);
    }
}
void func_8002578C(s32 arg0) {
    D_800ED6BC = arg0;
}
void func_80025798(s16 arg0, f32 arg1, f32 arg2, f32 arg3) {
    unk_ovl_2D_struct* temp_v1;

    if (D_800F2B7C[arg0].unk_6C != NULL) {
        temp_v1 = &D_800F2B7C[arg0];
        temp_v1->unk_24 = arg1;
        temp_v1->unk_28 = arg2;
        temp_v1->unk_2C = arg3;
    }
}
void func_800257E4(s16 arg0, f32 arg1, f32 arg2, f32 arg3) {
    unk_ovl_2D_struct* temp_v1;

    if (D_800F2B7C[arg0].unk_6C != NULL) {
        temp_v1 = &D_800F2B7C[arg0];
        temp_v1->unk_30 = arg1;
        temp_v1->unk_34 = arg2;
        temp_v1->unk_38 = arg3;
    }
}
void func_80025830(s16 arg0, f32 arg1, f32 arg2, f32 arg3) {
    unk_ovl_2D_struct* temp_v1;

    if (D_800F2B7C[arg0].unk_6C != NULL) {
        temp_v1 = &D_800F2B7C[arg0];
        temp_v1->unk_3C = arg1;
        temp_v1->unk_40 = arg2;
        temp_v1->unk_44 = arg3;
    }
}
void func_8002587C(s16 arg0, s32 arg1) {
    unk_ovl_2D_struct* temp_v1;
    s16 i;

    for (i = 0; i < 128; i++) {
        temp_v1 = &D_800F2B7C[i];
        if (temp_v1->unk_6C != NULL) {
            temp_v1->unk_20 &= ~arg0;
            temp_v1->unk_20 |= arg1;
        }
    }
}
void func_800258EC(s16 arg0, s32 arg1, s32 arg2) {
    unk_ovl_2D_struct* temp_a0 = &D_800F2B7C[arg0];

    if (temp_a0->unk_6C != NULL) {
        temp_a0->unk_20 &= ~arg1;
        temp_a0->unk_20 |= arg2;
    }
}

void func_80025930(s16 arg0, s32 arg1, s32 arg2) {
    unk2C0C0StructC0* model = D_800F2B7C[arg0].unk_6C;
    s16 i;

    for (i = 0; i < model->unk_6A; i++) {
        model->unk_80[i].unk_14 &= ~arg1;
        model->unk_80[i].unk_14 |= arg2;
    }
}
void func_800259D0(s16 arg0, char* arg1, s32 arg2, s32 arg3) {
    unk2C0C0StructC0* model = D_800F2B7C[arg0].unk_6C;
    s16 idx = func_80033718(model, arg1);

    if (idx >= 0) {
        model->unk_80[idx].unk_14 &= ~arg2;
        model->unk_80[idx].unk_14 |= arg3;
    }
}
void func_80025A7C(s16 arg0, char* arg1, s16 arg2) {
    func_800337E4(D_800F2B7C[arg0].unk_6C, arg1, D_800F2B7C[arg2].unk_6C);
}
void func_80025AD4(s16 arg0) {
    func_800258EC(arg0, 1, 1);
    D_800ECB14 = D_800F2B7C[arg0].unk_20;
    func_8002C030(D_800F2B7C[arg0].unk_6C);
}


void func_80025B34(s16 arg0) {
    unk2C0C0StructC0* model = D_800F2B7C[arg0].unk_6C;

    if (model->unk_64 != 0) {
        func_800238F0(model->unk_68);
    } else {
        func_800237BC(D_800F2B7C[arg0].unk_6C->unk_68);
    }
}
void func_80025BB8(s16 arg0, s16 arg1) {
    unk_ovl_2D_struct* temp_v1 = &D_800F2B7C[arg0];

    temp_v1->unk_08 = D_800F2B7C[arg1].unk_08;
    temp_v1->unk_50 = temp_v1->unk_48 = temp_v1->unk_0A = 0;
    temp_v1->unk_4C = 1.0f;
}
void func_80025C20(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    unk_ovl_2D_struct* temp_a0 = &D_800F2B7C[arg0];

    if (temp_a0->unk_0C != -1) {
        temp_a0->unk_08 = temp_a0->unk_0C;
        temp_a0->unk_48 = temp_a0->unk_54;
        temp_a0->unk_0A = temp_a0->unk_0E;
        temp_a0->unk_50 = temp_a0->unk_5C;
    }

    temp_a0->unk_0C = arg1;
    temp_a0->unk_54 = arg2;
    temp_a0->unk_12 = 0;
    temp_a0->unk_10 = arg3;
    temp_a0->unk_0E = arg4;
    temp_a0->unk_5C = 0.0f;
}

void func_80025CA8(s16 arg0, f32 arg1) {
    unk_ovl_2D_struct* temp_a1 = &D_800F2B7C[arg0];
    f32 len = D_800ED554[temp_a1->unk_08].unk_02;

    if (len < arg1) {
        temp_a1->unk_48 = len;
    } else {
        temp_a1->unk_48 = arg1;
    }
}
f32 func_80025D18(s16 arg0) {
    return D_800F2B7C[arg0].unk_48;
}
f32 func_80025D40(s16 arg0) {
    return D_800ED554[D_800F2B7C[arg0].unk_08].unk_02;
}

// decomp-permuter
f32 func_80025D90(s16 arg0)
{
  f32 new_var;
  f32 x = D_800F2B7C[arg0].unk_60;
  f32 r;
  if (!(x < 0.0f))
  {
    new_var = x;
    r = new_var;
  }
  else
  {
    r = 0.0f;
  }
  return r;
}
f32 func_80025DD8(s16 arg0) {
    if (D_800F2B7C[arg0].unk_60 < 0.0f) {
        return 0.0f;
    }
    return D_800ED554[D_800F2B7C[arg0].unk_14].unk_02;
}
s16 func_80025E48(s16 arg0) {
    return D_800F2B7C[arg0].unk_08;
}

f32 func_80025E70(s16 arg0) {
    return (D_800F2B7C[arg0].unk_0C != -1) ? D_800F2B7C[arg0].unk_54 : -1.0f;
}
void func_80025EB4(s16 arg0, s32 arg1, s32 arg2) {
    unk_ovl_2D_struct* temp_a0 = &D_800F2B7C[arg0];

    temp_a0->unk_0A = arg2 | (temp_a0->unk_0A & ~arg1);
    if (temp_a0->unk_0C != -1) {
        temp_a0->unk_0E = arg2 | (temp_a0->unk_0E & ~arg1);
    }
}
void func_80025F10(s16 arg0, s32 arg1) {
    D_800F2B7C[arg0].unk_02 = arg1;
}
s16 func_80025F38(s16 arg0) {
    return D_800F2B7C[arg0].unk_02;
}
void func_80025F60(s16 arg0, s32 arg1) {
    func_800258EC(arg0, 0x1C00, arg1);
    D_800F2B7C[arg0].unk_6C->unk_28 = ((u32)arg1 >> 10) & 7;
}
void func_80025FC8(s16 arg0, f32 arg1) {
    D_800F2B7C[arg0].unk_50 = arg1;
}
void func_80025FF0(s16 arg0, f32 arg1) {
    D_800F2B7C[arg0].unk_5C = arg1;
}
void func_80026018(s16 arg0, f32 arg1) {
    unk_ovl_2D_struct* p = &D_800F2B7C[arg0];

    p->unk_4C = arg1;
}
void func_80026040(s16 arg0) {
    unk2C0C0StructC0* model = D_800F2B7C[arg0].unk_6C;
    unk2C0C0StructE0* dst;
    unk2C0C0StructE0* src;
    s16 n;
    s16 j;
    s16 i;

    for (i = 0; i < D_800F37DA; i++) {
        n = model->unk_72;
        dst = model->unk_08[i] = func_80023684(n * sizeof(unk2C0C0StructE0), model->unk_68 + 1);
        src = model->unk_04;
        for (j = 0; j < n; j++) {
            *dst++ = *src++;
        }
    }
}
void func_80026174(s16 arg0, s16 arg1, f32 arg2) {
    unk2C0C0StructC0* model = D_800F2B7C[arg0].unk_6C;
    unk2C0C0StructE0* var_a3 = model->unk_04;
    unk2C0C0StructE0* var_a2 = D_800F2B7C[arg1].unk_6C->unk_04;
    unk2C0C0StructE0* var_t0 = model->unk_08[D_800F37F0];
    s16 n = model->unk_72;
    s16 i;

    for (i = 0; i < n; i++) {
        *var_t0 = *var_a3;
        if (var_a3->unk_00 != var_a2->unk_00 || var_a3->unk_02 != var_a2->unk_02 || var_a3->unk_04 != var_a2->unk_04) {
            var_t0->unk_00 = var_a3->unk_00 * arg2 + var_a2->unk_00 * (1.0f - arg2);
            var_t0->unk_02 = var_a3->unk_02 * arg2 + var_a2->unk_02 * (1.0f - arg2);
            var_t0->unk_04 = var_a3->unk_04 * arg2 + var_a2->unk_04 * (1.0f - arg2);
            var_t0->unk_0C.r = (s32) ((s8) var_a3->unk_0C.r * arg2 + (s8) var_a2->unk_0C.r * (1.0f - arg2));
            var_t0->unk_0C.g = (s32) ((s8) var_a3->unk_0C.g * arg2 + (s8) var_a2->unk_0C.g * (1.0f - arg2));
            var_t0->unk_0C.b = (s32) ((s8) var_a3->unk_0C.b * arg2 + (s8) var_a2->unk_0C.b * (1.0f - arg2));
        }
        var_a3++;
        var_a2++;
        var_t0++;
    }
}
void func_80026404(s16 arg0, s16 arg1, f32 arg2, char* arg3, s32 arg4) {
    s16 temp_s0;
    s16 temp_v0;
    unk2C0C0StructC0* temp_s2;
    unk2C0C0StructC0* temp_s3;

    temp_s3 = D_800F2B7C[arg0].unk_6C;
    temp_s2 = D_800F2B7C[arg1].unk_6C;
    temp_s0 = func_80033718(temp_s3, arg3);
    temp_v0 = func_80033718(temp_s2, arg3);

    if (temp_s0 == -1 || temp_v0 == -1) {
        return;
    }

    func_800265EC(temp_s3, temp_s2, arg2, temp_s0, temp_v0, arg4);
}

void func_800264F8(s16 arg0, s16 arg1, f32 arg2, char* arg3, char* arg4, s32 arg5) { //arg4 is char array string ptr?
    s16 temp_s0;
    s16 temp_v0;
    unk2C0C0StructC0* temp_s2;
    unk2C0C0StructC0* temp_s3;

    temp_s3 = D_800F2B7C[arg0].unk_6C;
    temp_s2 = D_800F2B7C[arg1].unk_6C;
    temp_s0 = func_80033718(temp_s3, arg3);
    temp_v0 = func_80033718(temp_s2, arg4);

    if (temp_s0 == -1 || temp_v0 == -1) {
        return;
    }

    func_800265EC(temp_s3, temp_s2, arg2, temp_s0, temp_v0, arg5);
}

void func_800265EC(unk2C0C0StructC0* arg0, unk2C0C0StructC0* arg1, f32 arg2, s16 arg3, s16 arg4, s32 arg5) {
    unk2C0C0StructE0* var_a2;
    unk2C0C0StructE0* var_a3;
    unk2C0C0StructE0* var_t0;
    s16 temp_v1;
    s16 temp_t3;
    s16 var_t4;
    s16 i;

    var_t4 = 0;

    if (arg5 != 0) {
        var_t0 = arg0->unk_04;
        var_a2 = arg0->unk_08[D_800F37F0];
        var_t4 = arg0->unk_80[arg3].unk_0A;

        for (i = 0; i < var_t4; i++) {
            *var_a2 = *var_t0;
            var_t0++;
            var_a2++;
        }
    }

    var_t0 = &arg0->unk_04[arg0->unk_80[arg3].unk_0A];
    var_a3 = &arg1->unk_04[arg1->unk_80[arg4].unk_0A];
    var_a2 = &arg0->unk_08[D_800F37F0][arg0->unk_80[arg3].unk_0A];

    temp_t3 = arg0->unk_80[arg3].unk_0C;
    for (i = 0; i < temp_t3; i++) {
        *var_a2 = *var_t0;
        if (var_t0->unk_00 != var_a3->unk_00 || var_t0->unk_02 != var_a3->unk_02 || var_t0->unk_04 != var_a3->unk_04) {
            var_a2->unk_00 = var_t0->unk_00 * arg2 + var_a3->unk_00 * (1.0f - arg2);
            var_a2->unk_02 = var_t0->unk_02 * arg2 + var_a3->unk_02 * (1.0f - arg2);
            var_a2->unk_04 = var_t0->unk_04 * arg2 + var_a3->unk_04 * (1.0f - arg2);
            var_a2->unk_0C.r = (s32) ((s8) var_t0->unk_0C.r * arg2 + (s8) var_a3->unk_0C.r * (1.0f - arg2));
            var_a2->unk_0C.g = (s32) ((s8) var_t0->unk_0C.g * arg2 + (s8) var_a3->unk_0C.g * (1.0f - arg2));
            var_a2->unk_0C.b = (s32) ((s8) var_t0->unk_0C.b * arg2 + (s8) var_a3->unk_0C.b * (1.0f - arg2));
        }
        var_t0++;
        var_a3++;
        var_a2++;
    }

    if (arg5 != 0) {
        temp_v1 = var_t4 + temp_t3;
        temp_t3 = arg0->unk_72;
        for (i = temp_v1; i < temp_t3; i++) {
            *var_a2 = *var_t0;
            var_t0++;
            var_a2++;
        }
    }
}

void func_80026A00(s16 arg0) {
    D_800C34A0 = arg0;
}
// decomp-permuter
unk2C0C0Struct50 *func_80026A0C(s16 arg0, char *arg1)
{
  unk2C0C0StructC0 *model = D_800F2B7C[arg0].unk_6C;
  s16 new_var;
  s16 idx = func_80033718(model, arg1);
  s16 n;
  s16 j;
  s16 i;
  if (model->unk_A0 == ((unk2C0C0Struct50 *) (-1)))
  {
    return (unk2C0C0Struct50 *) (-1);
  }
  for (i = 0; i < model->unk_70; i++)
  {
    n = model->unk_A0[i].unk_00;
    for (j = 0; j < n; j++)
    {
      if (model->unk_A0[i].unk_04[j] == idx)
      {
        break;
      }
    }

    new_var = j;
    if (new_var != n)
    {
      break;
    }
  }

  if (i == model->unk_70)
  {
 do { } while (0);
    return (unk2C0C0Struct50 *) (-1);
  }
  return &model->unk_A0[i];
}
void func_80026B8C(s16 arg0, f32 arg1, f32 arg2, s32 arg3) {
    unk2C0C0StructC0* model = D_800F2B7C[arg0].unk_6C;

    if (model != NULL) {
        switch (arg3 & 0xF) {
            case 0:
                func_80026EA8(model, arg1, arg2, 0, model->unk_74);
                break;
            case 1:
                func_80027100(model, arg1, arg2, 0, model->unk_74);
                break;
            case 2:
                func_80027440(model, arg1, arg2, 0, model->unk_74);
                break;
        }
    }
}
// retail keeps an extra copy of arg4 in s2 (masked 16)
#ifdef NON_MATCHING
void func_80026C6C(s16 arg0, f32 arg1, f32 arg2, char* arg3, s32 arg4) {
    unk2C0C0StructC0* model = D_800F2B7C[arg0].unk_6C;
    unk2C0C0StructE0* src;
    unk2C0C0StructE0* dst;
    s16 idx;
    s16 n;
    s16 i;

    if (model == NULL) {
        return;
    }
    idx = func_80033718(model, arg3);
    if (idx == -1) {
        return;
    }
    if (arg4 & 0x80) {
        src = model->unk_04;
        dst = model->unk_08[D_800F37F0];
        n = model->unk_72;
        for (i = 0; i < n; i++) {
            *dst++ = *src++;
        }
    }
    switch (arg4 & 0xF) {
        case 0:
            func_80026EA8(model, arg1, arg2, model->unk_80[idx].unk_0E, model->unk_80[idx].unk_10);
            break;
        case 1:
            func_80027100(model, arg1, arg2, model->unk_80[idx].unk_0E, model->unk_80[idx].unk_10);
            break;
        case 2:
            func_80027440(model, arg1, arg2, model->unk_80[idx].unk_0E, model->unk_80[idx].unk_10);
            break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/24740", func_80026C6C);
#endif
void func_80026EA8(unk2C0C0StructC0* arg0, f32 arg1, f32 arg2, u16 arg3, u16 arg4) {
    unk2C0C0StructB0* b = &arg0->unk_D0[arg3];
    f32 inv = 1.0f - arg1;
    unk2C0C0StructE0* src;
    unk2C0C0StructE0* dst;
    s16* idx;
    s16 cx, cy, cz;
    s16 sx, sy, sz;
    s16 n;
    s16 j;
    s16 i;

    for (i = 0; i < arg4; i++) {
        cx = b->unk_0C;
        cy = b->unk_10;
        cz = b->unk_14;
        sx = cx * arg2;
        sy = cy * arg2;
        sz = cz * arg2;
        n = (u8)(b->unk_00 & 0x7F);
        idx = b->unk_02;
        for (j = 0; j < n; j++) {
            src = &arg0->unk_04[*idx];
            dst = &arg0->unk_08[D_800F37F0][*idx];
            dst->unk_00 = (src->unk_00 - cx) * inv + sx;
            dst->unk_02 = (src->unk_02 - cy) * inv + sy;
            dst->unk_04 = (src->unk_04 - cz) * inv + sz;
            idx++;
        }
        b++;
    }
}
void func_80027100(unk2C0C0StructC0* arg0, f32 arg1, f32 arg2, u16 arg3, u16 arg4) {
    unk24740Floats8 sp0 = *(unk24740Floats8*)D_800CA8D8;
    unk2C0C0StructB0* b = &arg0->unk_D0[arg3];
    f32 inv = 1.0f - arg1;
    unk2C0C0StructE0* src;
    unk2C0C0StructE0* dst;
    s16* idx;
    s16 cx, cy, cz;
    s16 sx, sy, sz;
    s16 n;
    s16 j;
    s16 i;

    for (i = 0; i < arg4; i++) {
        cx = b->unk_0C;
        cy = b->unk_10;
        cz = b->unk_14;
        if (arg2 == 1.0f) {
            sx = cx * arg2;
            sy = cy * arg2;
            sz = cz * arg2;
        } else {
            sx = cx * arg2 * sp0.v[i & 7];
            sy = cy * arg2 * sp0.v[i & 7];
            sz = cz * arg2 * sp0.v[i & 7];
        }
        n = (u8)(b->unk_00 & 0x7F);
        idx = b->unk_02;
        for (j = 0; j < n; j++) {
            src = &arg0->unk_04[*idx];
            dst = &arg0->unk_08[D_800F37F0][*idx];
            dst->unk_00 = (src->unk_00 - cx) * inv + sx;
            dst->unk_02 = (src->unk_02 - cy) * inv + sy;
            dst->unk_04 = (src->unk_04 - cz) * inv + sz;
            idx++;
        }
        b++;
    }
}
void func_80027440(unk2C0C0StructC0* arg0, f32 arg1, f32 arg2, u16 arg3, u16 arg4) {
    unk24740Floats8 sp10 = *(unk24740Floats8*)D_800CA8D8;
    unk2C0C0StructB0* b = &arg0->unk_D0[arg3];
    f32 inv = 1.0f - arg1;
    f32 s = func_800AEAC0(D_800C34A4);
    f32 c = func_800AEFD0(D_800C34A4);
    unk2C0C0StructE0* src;
    unk2C0C0StructE0* dst;
    s16* idx;
    s16 cx, cy, cz;
    s16 sx, sy, sz;
    f32 dx, dy, dz;
    s16 n;
    s16 j;
    s16 i;

    for (i = 0; i < arg4; i++) {
        cx = b->unk_0C;
        cy = b->unk_10;
        cz = b->unk_14;
        if (arg2 == 1.0f) {
            sx = cx * arg2;
            sy = cy * arg2;
            sz = cz * arg2;
        } else {
            sx = cx * arg2 * sp10.v[i & 7];
            sy = cy * arg2 * sp10.v[i & 7];
            sz = cz * arg2 * sp10.v[i & 7];
        }
        n = (u8)(b->unk_00 & 0x7F);
        idx = b->unk_02;
        switch (i & 3) {
            case 0:
            case 2:
                for (j = 0; j < n; j++) {
                    src = &arg0->unk_04[*idx];
                    dst = &arg0->unk_08[D_800F37F0][*idx];
                    dx = src->unk_00 - cx;
                    dy = src->unk_02 - cy;
                    dz = src->unk_04 - cz;
                    dst->unk_00 = dx * inv + sx;
                    dst->unk_02 = (dy * c + dz * s) * inv + sy;
                    dst->unk_04 = (-dy * s + dz * c) * inv + sz;
                    idx++;
                }
                break;
            case 1:
                for (j = 0; j < n; j++) {
                    src = &arg0->unk_04[*idx];
                    dst = &arg0->unk_08[D_800F37F0][*idx];
                    dx = src->unk_00 - cx;
                    dy = src->unk_02 - cy;
                    dz = src->unk_04 - cz;
                    dst->unk_00 = (dx * c - dz * s) * inv + sx;
                    dst->unk_02 = dy * inv + sy;
                    dst->unk_04 = (dx * s + dz * c) * inv + sz;
                    idx++;
                }
                break;
            case 3:
                for (j = 0; j < n; j++) {
                    src = &arg0->unk_04[*idx];
                    dst = &arg0->unk_08[D_800F37F0][*idx];
                    dx = src->unk_00 - cx;
                    dy = src->unk_02 - cy;
                    dz = src->unk_04 - cz;
                    dst->unk_00 = (dx * c + dy * s) * inv + sx;
                    dst->unk_02 = (-dx * s + dy * c) * inv + sy;
                    dst->unk_04 = dz * inv + sz;
                    idx++;
                }
                break;
        }
        b++;
    }
}
void func_80027AC8(s16 arg0, u8* arg1, u8* arg2) {
    unk2C0C0Struct70* found = NULL;
    unk2C0C0StructC0* model = D_800F2B7C[arg0].unk_6C;
    u16 hash = func_8001CD00(arg2);
    s16 i;

    for (i = 0; i < 128; i++) {
        if (D_800F37AC[i].unk_20 != 0 && D_800F37AC[i].unk_20 == hash && func_8009B850(&D_800F37AC[i], arg2) == 0) {
            found = &D_800F37AC[i];
            break;
        }
    }
    hash = func_8001CD00(arg1);
    for (i = 0; i < model->unk_6C; i++) {
        if (model->unk_A4[i].unk_0C->unk_20 == hash) {
            model->unk_A4[i].unk_0C = found;
        }
    }
}
void func_80027C1C(s16 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4) {
    u16 w;
    u16 h;
    s16 i;
    u16 var_a0;
    u16 var_a0_2;
    s16 temp_t2;
    unk2C0C0StructC0* temp_s0;
    unk2C0C0StructE0* var_t0;
    unk2C0C0StructE0* var_t1;

    temp_s0 = D_800F2B7C[arg0].unk_6C;
    if (temp_s0 != NULL) {
        var_t0 = temp_s0->unk_04;
        var_t1 = temp_s0->unk_08[D_800F37F0];
        temp_t2 = temp_s0->unk_72;
        w = arg3 << 5;
        h = arg4 << 5;
        var_a0 = arg1 * 32.0f;
        var_a0_2 = arg2 * 32.0f;

        if (arg1 < 0.0f) {
            arg1 = -arg1;
        }
        if (arg2 < 0.0f) {
            arg2 = -arg2;
        }

        if ((arg1 * 32.0f) > w) {
            var_a0 = var_a0 % w;
        }

        if ((arg2 * 32.0f) > h) {
            var_a0_2 = var_a0_2 % h;
        }

        for (i = 0; i < temp_t2; i++) {
            var_t1->unk_08 = var_a0 + var_t0->unk_08;
            var_t1->unk_0A = var_a0_2 + var_t0->unk_0A;
            var_t0++;
            var_t1++;
        }
    }
}
void func_80027E48(s16 arg0, f32 arg1, f32 arg2, u16 arg3, u16 arg4, char* arg5, u8 arg6) {
    s16 i;
    u16 var_a0;
    u16 var_a0_2;
    s16 temp_t2;
    unk2C0C0StructC0* temp_s0;
    unk2C0C0StructE0* var_t0;
    unk2C0C0StructE0* var_t1;
    s32 temp2;

    temp_s0 = D_800F2B7C[arg0].unk_6C;
    if (temp_s0 != NULL) {
        if (arg6 != 0) {
            var_t0 = temp_s0->unk_04;
            var_t1 = temp_s0->unk_08[D_800F37F0];
            temp_t2 = temp_s0->unk_72;
            for (i = 0; i < temp_t2; i++) {
                *var_t1++ = *var_t0++;
            }
        }
        temp2 = func_80033718(temp_s0, arg5);
        temp_t2 = temp_s0->unk_80[temp2].unk_0C;
        var_t0 = &temp_s0->unk_04[temp_s0->unk_80[temp2].unk_0A];
        var_t1 = &temp_s0->unk_08[D_800F37F0][temp_s0->unk_80[temp2].unk_0A];
        arg3 = (arg3 << 5);
        arg4 = (arg4 << 5);
        var_a0 = arg1 * 32.0f;
        var_a0_2 = arg2 * 32.0f;
        
        if (arg1 < 0.0f) {
            arg1 = -arg1;
        }
        if (arg2 < 0.0f) {
            arg2 = -arg2;
        }

        if ((arg1 * 32.0f) > arg3) {
            var_a0 = var_a0 % arg3;
        }

        if ((arg2 * 32.0f) > arg4) {
            var_a0_2 = var_a0_2 % arg4;
        }

        for (i = 0; i < temp_t2; i++) {
            var_t1->unk_08 = var_a0 + var_t0->unk_08;
            var_t1->unk_0A = var_a0_2 + var_t0->unk_0A;
            var_t0++;
            var_t1++;
        }
    }
}

void func_80028180(s16 arg0, char* arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5) {
    unk2C0C0StructC0* model = D_800F2B7C[arg0].unk_6C;
    unk2C0C0StructE0* src;
    unk2C0C0StructE0* dst;
    s16 idx;
    s16 n;
    s16 i;

    if (model != NULL) {
        if (arg5 != 0) {
            src = model->unk_04;
            dst = model->unk_08[D_800F37F0];
            n = model->unk_72;
            for (i = 0; i < n; i++) {
                *dst++ = *src++;
            }
        }
        idx = func_80033718(model, arg1);
        n = model->unk_80[idx].unk_0C;
        src = &model->unk_08[D_800F37F0][model->unk_80[idx].unk_0A];
        for (i = 0; i < n; i++) {
            src->unk_0C.r = arg2;
            src->unk_0C.g = arg3;
            src->unk_0C.b = arg4;
            src++;
        }
    }
}
void func_80028314(s16 arg0) {
    unk2C0C0StructC0* model = D_800F2B7C[arg0].unk_6C;
    unk2C0C0Struct30* obj;
    unk2C0C0Struct20* key;
    s16 tmp;
    f32 ftmp;
    s16 n;
    s16 k;
    s16 j;
    s16 i;

    for (i = 0; i < model->unk_6A; i++) {
        obj = &model->unk_80[i];
        for (j = 0; j < (s16)obj->unk_04; j++) {
            key = &obj->unk_34[j];
            n = (u8)(key->unk_00 & 0x7F);
            for (k = 0; k < n / 2; k++) {
                tmp = key->unk_04[k];
                key->unk_04[k] = key->unk_04[n - k - 1];
                key->unk_04[n - k - 1] = tmp;
                ftmp = key->unk_0C[k];
                key->unk_0C[k] = key->unk_0C[n - k - 1];
                key->unk_0C[n - k - 1] = ftmp;
                ftmp = key->unk_1C[k];
                key->unk_1C[k] = key->unk_1C[n - k - 1];
                key->unk_1C[n - k - 1] = ftmp;
            }
        }
    }
}
void func_80028498(s16 arg0, s16 arg1, s16 arg2) {
    unk_ovl_2D_struct* temp_v0 = &D_800F2B7C[arg0];

    temp_v0->unk_14 = arg1;
    temp_v0->unk_68 = temp_v0->unk_60 = 0.0f;
    temp_v0->unk_16 = arg2;
    temp_v0->unk_64 = 1.0f;
}
void func_800284E4(s16 arg0) {
    D_800F2B7C[arg0].unk_14 = -1;
}
void func_80028510(s16 arg0, s16 arg1, u8 arg2, u8 arg3, u8 arg4) {
    D_800EE988 = 1;
    D_800F65DA = arg0;
    D_800ED0D0 = arg1;
    D_800F2CF9 = arg2;
    D_800F3FF4 = arg3;
    D_800EDEBC = arg4;
}
void func_8002854C(void) {
    D_800EE988 = 0;
}
void func_80028558(s16 arg0, s16 arg1) {
    D_800F2B7C[arg0].unk_6C = D_800F2B7C[arg1].unk_6C;
}
void func_8002859C(s16 arg0, s16 arg1, char* arg2) {
    unk2C0C0StructC0* model = D_800F2B7C[arg1].unk_6C;
    s16 idx = func_80033718(model, arg2);

    D_800F2B7C[arg0].unk_70 = model;
    D_800F2B7C[arg0].unk_18 = idx;
}
void func_8002861C(s16 arg0) {
    unk2C0C0StructC0* model = D_800F2B7C[arg0].unk_6C;

    model->unk_BC = func_80038178(model);
}
void func_80028668(unk_ovl_2D_struct* arg0, u16 arg1) {
    arg0->unk_48 = func_800369FC(&D_800ED554[arg0->unk_08], arg0->unk_0A, arg0->unk_48, arg0->unk_50, (f32)arg1 * arg0->unk_4C);
    if (arg0->unk_0C != -1) {
        arg0->unk_54 = func_800369FC(&D_800ED554[arg0->unk_0C], arg0->unk_0E, arg0->unk_54, arg0->unk_5C, (f32)arg1 * arg0->unk_58);
    }
    if (arg0->unk_14 != -1) {
        arg0->unk_60 = func_800369FC(&D_800ED554[arg0->unk_14], arg0->unk_16, arg0->unk_60, arg0->unk_68, (f32)arg1 * arg0->unk_64);
    }
}
s16 func_80028784(u8* arg0, s16 arg1) {
    s16 ret;

    if (arg0[0] != 'M' || arg0[1] != 'T' || arg0[2] != 'N' || arg0[3] != 'X') {
        D_800F502C = 10256;
        D_800EE32E = 10257;
        D_800ECB40.unk_68 = D_800F502C;
        func_8001AC00(&D_800ECB40, arg0, arg1);
        ret = func_800341E8(arg0, &D_800ECB40);
        func_800237BC(D_800F502C);
        func_800237BC(D_800EE32E);
    } else {
        ret = func_800342BC(arg0);
    }
    if (arg1 & 8) {
        D_800F33A4(arg0);
    }
    return ret;
}
void func_8002888C(s16 arg0, s16 arg1) {
    unk_ovl_2D_struct* temp_v0 = &D_800F2B7C[arg0];

    temp_v0->unk_08 = arg1;
    temp_v0->unk_50 = temp_v0->unk_48 = temp_v0->unk_0A = 0;
    temp_v0->unk_4C = 1.0f;
}
f32 func_800288D8(s16 arg0) {
    return D_800ED554[arg0].unk_02;
}
void func_8002890C(s32 arg0, s32 arg1, s32 arg2) {
    D_800C30C0 = arg0;
    D_800C30C1 = arg1;
    D_800C30C2 = arg2;
}
void func_80028928(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    unk_ovl_2D_struct* p = &D_800F2B7C[arg0];

    if ((arg1 & 1) && p->unk_08 >= 0) {
        p->unk_0A = arg3 | (p->unk_0A & ~arg2);
        if ((arg1 & 2) && p->unk_0C >= 0) {
            p->unk_0E = arg3 | (p->unk_0E & ~arg2);
        }
        if ((arg1 & 4) && p->unk_14 >= 0) {
            p->unk_16 = arg3 | (p->unk_16 & ~arg2);
        }
    }
}
void func_800289D0(s16 arg0, s16 arg1, f32 arg2) {
    unk_ovl_2D_struct* p = &D_800F2B7C[arg0];

    p->unk_1A = arg1;
    p->unk_74 = p->unk_6C;
    p->unk_1C = arg2;
    p = &D_800F2B7C[arg1];
    p->unk_1A = arg0;
    p->unk_74 = NULL;
    p->unk_1C = 0.0f;
    p->unk_20 |= 4;
}
void func_80028A34(s16 arg0) {
    unk_ovl_2D_struct* p = &D_800F2B7C[arg0];
    f32 dx = D_800F32A0->coords.x - p->unk_24;
    f32 dy = D_800F32A0->coords.y - p->unk_28;
    f32 dz = D_800F32A0->coords.z - p->unk_2C;
    unk2C0C0StructC0* model;
    unk_ovl_2D_struct* q;
    s32 flags;
    s16 i;

    if (p->unk_1C < func_800B1750(dx * dx + dy * dy + dz * dz)) {
        model = p->unk_74;
    } else {
        model = D_800F2B7C[p->unk_1A].unk_6C;
    }
    if (model != p->unk_6C) {
        p->unk_6C = model;
        for (i = 0; i < 128; i++) {
            q = &D_800F2B7C[i];
            if (q->unk_6C != NULL) {
                continue;
            }
            flags = q->unk_20;
            if (flags & 4) {
                continue;
            }
            if (!(flags & 0x4000)) {
                continue;
            }
            if (p->unk_6C == q->unk_70 || D_800F2B7C[p->unk_1A].unk_6C == q->unk_70) {
                D_800F2B7C[i].unk_70 = model;
            }
        }
    }
    D_800F2B7C[p->unk_1A].unk_20 |= 4;
}
void func_80028BE0(s32 arg0) {
    D_800ED0C8 = arg0;
}
void func_80028BEC(s16 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4) {
    unk2C0C0StructC0* model = D_800F2B7C[arg0].unk_6C;

    model->unk_2A = arg1;
    model->unk_2B = arg2;
    model->unk_2C = arg3;
    model->unk_2D = arg4;
}
void func_80028C28(s16 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4) {
    unk2C0C0StructC0* model = D_800F2B7C[arg0].unk_6C;

    model->unk_2E = arg1;
    model->unk_2F = arg2;
    model->unk_30 = arg3;
    model->unk_31 = arg4;
}
void func_80028C64(s16 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4) {
    func_80028BEC(arg0, arg1, arg2, arg3, arg4);
    func_80028C28(arg0, arg1 * 0.5f, arg2 * 0.5f, arg3 * 0.5f, arg4 * 0.5f);
}
void func_80028E8C(s16 arg0, void (*arg1)(Gfx**, Mtx*, u8)) {
    D_800ED3E4[arg0] = arg1;
}
void func_80028EA4(s16 arg0, f32 arg1) {
    unk2C0C0StructC0* model = D_800F2B7C[arg0].unk_6C;
    unk2C0C0StructE0* src = model->unk_04;
    unk2C0C0StructE0* dst = model->unk_08[D_800F37F0];
    f32 dx, dy, r, a;
    s16 ang;
    s16 i;

    for (i = 0; i < model->unk_72; i++) {
        dx = src->unk_08 - 0x200;
        dy = src->unk_0A - 0x200;
        ang = func_800B0CD8(dy, dx);
        r = func_800B1750(dx * dx + dy * dy);
        ang = ang + arg1;
        a = ang % 360;
        dst->unk_08 = func_800AEFD0(a) * r + 512.0f;
        dst->unk_0A = func_800AEAC0(a) * r + 512.0f;
        src++;
        dst++;
    }
}
const char D_800CA810[] = "donky4_DEF";
const char D_800CA81C[] = "wario_kao_DEF";
const char D_800CA82C[] = "c003t000._DEF";
const char D_800CA83C[] = "pe_lod1c_DEF";
const char D_800CA84C[] = "luigi_kao_DEF";
const char D_800CA85C[] = "ma_l_3a_DEF";
const char D_800CA868[] = "donky_kao_3_DEF";
const char D_800CA878[] = "wario_kao2_DEF";
const char D_800CA888[] = "c003_400b_DEF";
const char D_800CA898[] = "pe_lod1a_DEF";
const char D_800CA8A8[] = "luigi_lod_DEF";
const char D_800CA8B8[] = "ma_l_3_DEF";
const char D_800CA8C4[] = "Model Entry Over!\n";

const f32 D_800CA8D8[] = {
    1.0f, 0.8f, 1.1f, 1.3f, 0.5f, 1.2f, 0.9f, 1.5f
};
