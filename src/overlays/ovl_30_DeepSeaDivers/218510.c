#include "DeepSeaDivers.h"

s32 D_800FF960_DeepSeaDivers[2] = { 0x440002, 0x440004 };
s16 D_800FF968_DeepSeaDivers[2] = { -500, 500 };
s32 D_800FF96C_DeepSeaDivers[2] = { 0x440000, 0x440001 };
f32 D_800FF974_DeepSeaDivers[4][2] = { { -90.0f, 0.0f }, { 0.0f, -90.0f }, { 90.0f, 0.0f }, { 0.0f, 90.0f } };
Vec D_800FF994_DeepSeaDivers[6] = {
    { 0.0f, -7.5f, 30.0f }, { 0.0f, -7.5f, 40.0f }, { 0.0f, -20.0f, -5.0f },
    { 0.0f, -7.5f, 10.0f }, { 0.0f, -15.0f, 20.0f }, { 0.0f, -30.0f, -10.0f },
};
f32 D_800FF9DC_DeepSeaDivers = 0.0f;
Vec D_800FF9E0_DeepSeaDivers[6] = {
    { -559.536f, -134.881f, 0.0f },
    { -559.536f, 38.971f, 0.0f },
    { -264.166f, 39.872f, 0.0f },
    { -251.559f, 3.84f, 0.0f },
    { -327.202f, -28.588f, 0.0f },
    { -420.856f, -85.338f, 0.0f },
};
Vec D_800FFA28_DeepSeaDivers[6] = {
    { -558.029f, -315.97f, 0.0f },
    { -558.029f, -181.818f, 0.0f },
    { -320.54f, -180.42f, 0.0f },
    { -306.57f, -239.112f, 0.0f },
    { -345.686f, -275.445f, 0.0f },
    { -475.606f, -306.188f, 0.0f },
};
Vec D_800FFA70_DeepSeaDivers[6] = {
    { -182.892f, -107.76f, 0.0f },
    { -197.146f, -61.775f, 0.0f },
    { -117.115f, -60.705f, 0.0f },
    { -121.24f, -83.876f, 0.0f },
    { -142.266f, -117.741f, 0.0f },
    { -162.222f, -116.671f, 0.0f },
};
Vec D_800FFAB8_DeepSeaDivers[7] = {
    { 119.526f, -88.393f, 0.0f },
    { 119.203f, -59.94f, 0.0f },
    { 198.608f, -59.94f, 0.0f },
    { 197.102f, -88.716f, 0.0f },
    { 185.466f, -117.17f, 0.0f },
    { 161.546f, -129.456f, 0.0f },
    { 140.859f, -130.426f, 0.0f },
};
Vec D_800FFB0C_DeepSeaDivers[6] = {
    { 261.844f, -33.523f, 0.0f },
    { 279.358f, 38.741f, 0.0f },
    { 559.571f, 38.741f, 0.0f },
    { 559.571f, -121.116f, 0.0f },
    { 464.342f, -90.458f, 0.0f },
    { 312.195f, -68.56f, 0.0f },
};
Vec D_800FFB54_DeepSeaDivers[6] = {
    { 307.227f, -214.576f, 0.0f },
    { 323.399f, -182.222f, 0.0f },
    { 559.51f, -183.84f, 0.0f },
    { 561.127f, -345.608f, 0.0f },
    { 460.861f, -324.578f, 0.0f },
    { 367.063f, -290.607f, 0.0f },
};
Vec D_800FFB9C_DeepSeaDivers[6] = {
    { -24.375f, -227.03f, 0.0f },
    { -38.93f, -179.26f, 0.0f },
    { 41.704f, -178.805f, 0.0f },
    { 37.935f, -201.553f, 0.0f },
    { 16.559f, -237.494f, 0.0f },
    { -3.453f, -234.765f, 0.0f },
};
Vec D_800FFBE4_DeepSeaDivers[7] = {
    { -203.906f, -269.248f, 0.0f },
    { -205.205f, -239.351f, 0.0f },
    { -122.601f, -239.351f, 0.0f },
    { -125.07f, -268.382f, 0.0f },
    { -137.199f, -298.712f, 0.0f },
    { -160.59f, -309.111f, 0.0f },
    { -182.681f, -311.278f, 0.0f },
};
Vec D_800FFC38_DeepSeaDivers[6] = {
    { 137.201f, -288.858f, 0.0f },
    { 122.158f, -239.702f, 0.0f },
    { 204.653f, -239.2f, 0.0f },
    { 200.884f, -264.28f, 0.0f },
    { 179.824f, -299.391f, 0.0f },
    { 157.76f, -297.385f, 0.0f },
};
Vec* D_800FFC80_DeepSeaDivers[9] = {
    D_800FF9E0_DeepSeaDivers, D_800FFA28_DeepSeaDivers, D_800FFA70_DeepSeaDivers,
    D_800FFAB8_DeepSeaDivers, D_800FFB0C_DeepSeaDivers, D_800FFB54_DeepSeaDivers,
    D_800FFB9C_DeepSeaDivers, D_800FFBE4_DeepSeaDivers, D_800FFC38_DeepSeaDivers,
};
s16 D_800FFCA4_DeepSeaDivers[14] = { 6, 6, 6, 7, 6, 6, 6, 7, 6 };
Gfx D_800FFCC0_DeepSeaDivers[] = {
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
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0000, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
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
Gfx D_800FFD78_DeepSeaDivers[] = {
    gsSPClearGeometryMode(0xFFFFFFFF),
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
    gsSPSetGeometryMode(G_SHADE | G_SHADING_SMOOTH),
    gsSPClipRatio(FRUSTRATIO_2),
    gsSPEndDisplayList(),
};
Gfx D_800FFDB8_DeepSeaDivers[] = {
    gsSPDisplayList(D_800FFD78_DeepSeaDivers),
    gsSPDisplayList(D_800FFCC0_DeepSeaDivers),
    gsSPEndDisplayList(),
};
Gfx D_800FFDD0_DeepSeaDivers[] = {
    gsDPPipeSync(),
    gsSPDisplayList(D_800FFDB8_DeepSeaDivers),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPSetGeometryMode(G_ZBUFFER | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x00),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0xFF),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPEndDisplayList(),
};
Gfx D_800FFE10_DeepSeaDivers[] = {
    gsDPPipeSync(),
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, 319, 239),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH),
    gsDPSetRenderMode(G_RM_AA_ZB_XLU_LINE, G_RM_NOOP2),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
s32 D_800FFE60_DeepSeaDivers[3] = { 0, 100, 220 };
s32 D_800FFE6C_DeepSeaDivers[5] = { 30, 30, 30, 0, 0 };

#ifdef NON_MATCHING
void func_800F65E0_DeepSeaDivers(void) {
    omObjData* obj;
    u8 cam;
    s16 i;
    s16 j;
    s16 n;

    func_80029090(50);
    func_8001DE70(32);
    omInitObjMan(50, 0);
    i = 0;
    func_80060088();
    omSetStatBit(omAddObj(32730, 0, 0, -1, omOutView), 160);
    func_800178A0(1);
    cam = func_800178E8();
    func_80017660(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 10.0f, 2000.0f, 32000.0f);
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    D_801003FC_DeepSeaDivers = 0;
    D_801003FE_DeepSeaDivers = 45;
    D_80100402_DeepSeaDivers = 0;
    D_80100400_DeepSeaDivers = 1;
    D_80100404_DeepSeaDivers = 2700;
    D_80100408_DeepSeaDivers = _CheckFlag(0x2B);
    do {
        D_801017B0_DeepSeaDivers[i] = NULL;
        i++;
    } while (i < 256);
    D_8010040E_DeepSeaDivers = 0;
    D_8010040C_DeepSeaDivers = 0;
    D_8010040A_DeepSeaDivers = 0;
    D_80100406_DeepSeaDivers = -1;
    D_80101BD4_DeepSeaDivers = 0;
    D_801017A0_DeepSeaDivers = 0;
    DataClose(DataRead(0x160014));
    i = 0;
    func_800FB860_DeepSeaDivers();
    func_800FD494_DeepSeaDivers();
    D_80100464_DeepSeaDivers = func_80076FF4(124);
    D_80101BD0_DeepSeaDivers = omAddObj(10, 0, 0, -1, func_800F6B1C_DeepSeaDivers);
    D_800F2AF8[D_800ED440++] = obj = omAddObj(0, 9, 0, -1, func_800F70F4_DeepSeaDivers);
    omSetStatBit(obj, 160);
    D_800F2AF8[D_800ED440++] = omAddObj(1, 6, 0, -1, func_800F791C_DeepSeaDivers);
    D_80100C70_DeepSeaDivers[1] = 0;
    D_80100C70_DeepSeaDivers[2] = 0;
    for (n = 0, j = 0; j < 4; j++) {
        for (i = 0; i < 4; i++) {
            if (GwPlayer[i].group == j) {
                D_8010046A_DeepSeaDivers[n++] = i;
            }
        }
        i = 0;
    }
    do {
        D_800F3FB0[D_800F2BC0++] = D_80101780_DeepSeaDivers[i].boat =
            omAddObj(2, 3, 50, -1, func_800F7968_DeepSeaDivers);
        D_800F3FB0[D_800F2BC0++] = D_80101780_DeepSeaDivers[i].diver =
            omAddObj(3, 1, 50, -1, func_800F8680_DeepSeaDivers);
        i++;
    } while (i < 2);
    for (i = 0; i < 8; i++) {
        D_80101BB0_DeepSeaDivers[D_801017A0_DeepSeaDivers++] = omAddObj(4, 2, 0, -1, func_800F9AF4_DeepSeaDivers);
    }
    D_80100460_DeepSeaDivers = omAddObj(0, 0, 0, -1, func_800F7000_DeepSeaDivers);
    func_800FB964_DeepSeaDivers();
    func_800FB984_DeepSeaDivers();
    func_800234B8(0, 128, 128, 128);
    func_800234B8(1, 255, 255, 255);
    func_80023504(1, 0.0f, 128.0f, 128.0f);
    D_801004A8_DeepSeaDivers[1] = 0;
    D_801004A8_DeepSeaDivers[0] = 0;
    D_80101798_DeepSeaDivers = 0.075f;
    func_800FDBA0_DeepSeaDivers();
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800F65E0_DeepSeaDivers);
#endif
void func_800F6B1C_DeepSeaDivers(omObjData* obj) {
    obj->func_ptr = func_800F6BDC_DeepSeaDivers;
    SetFadeInTypeAndTime(0, 16);
}
void func_800F6B48_DeepSeaDivers(void) {
    s16 i;

    for (i = 0; i < 2; i++) {
        func_800FE170_DeepSeaDivers(D_80100466_DeepSeaDivers[i], &D_80100478_DeepSeaDivers[i].top,
                                    &D_80100478_DeepSeaDivers[i].bottom);
    }
}
void func_800F6BDC_DeepSeaDivers(omObjData* obj) {
    switch (D_801003FC_DeepSeaDivers) {
        case 0:
            if (--D_801003FE_DeepSeaDivers == 0) {
                D_801003FC_DeepSeaDivers++;
                D_801003FE_DeepSeaDivers = 45;
                func_80060128(25);
            }
            break;
        case 1:
            if (--D_801003FE_DeepSeaDivers == 0) {
                D_801003FC_DeepSeaDivers++;
                D_801003FE_DeepSeaDivers = 60;
                GMesCreate(0);
            }
            break;
        case 2:
            if (--D_801003FE_DeepSeaDivers == 0) {
                D_801003FC_DeepSeaDivers++;
                D_80100400_DeepSeaDivers = 0;
                D_80101798_DeepSeaDivers = 0.5f;
            }
            break;
        case 3:
            if (D_80100402_DeepSeaDivers == 0) {
                if ((D_80100410_DeepSeaDivers | D_80100438_DeepSeaDivers) == 0) {
                    D_80100402_DeepSeaDivers = 1;
                    D_80100400_DeepSeaDivers = 1;
                    D_801003F0_DeepSeaDivers = 10;
                }
                if (D_80100402_DeepSeaDivers == 0 && D_80100404_DeepSeaDivers != 0) {
                    D_80100404_DeepSeaDivers--;
                }
            }
            if (D_80100404_DeepSeaDivers == 0 || D_80100402_DeepSeaDivers != 0) {
                D_80100400_DeepSeaDivers = 1;
                if (D_80100408_DeepSeaDivers == 0) {
                    D_801003FC_DeepSeaDivers++;
                    if (D_80100404_DeepSeaDivers == 0) {
                        GMesCreate(16);
                    } else {
                        GMesCreate(2);
                    }
                } else {
                    D_801003FC_DeepSeaDivers = 6;
                    GMesCreate(2);
                }
                func_800601D4(40);
            }
            break;
        case 4:
            if (GMesStatAllGet() == 2) {
                D_801003FC_DeepSeaDivers++;
                if (D_80100402_DeepSeaDivers != 0) {
                    func_80060128(54);
                } else {
                    func_80060128(60);
                }
            }
            break;
        case 5:
            if (func_8000C144() != 0x200 && func_8000C144() != 1) {
                D_801003FC_DeepSeaDivers = -1;
                D_80100402_DeepSeaDivers = -1;
                func_800726AC(0, 20);
            }
            break;
        case 6:
            if (GMesStatAllGet() == 2) {
                D_801003FC_DeepSeaDivers++;
                D_801003FE_DeepSeaDivers = 60;
            }
            break;
        case 7:
            if (--D_801003FE_DeepSeaDivers == 0) {
                D_801003FC_DeepSeaDivers = -1;
                D_80100402_DeepSeaDivers = -1;
                func_80060398(40);
                func_800726AC(0, 20);
            }
            break;
    }
    func_800FB130_DeepSeaDivers();
    if (D_800F5144 != 0) {
        D_80100402_DeepSeaDivers = -1;
    }
    if (D_801004A8_DeepSeaDivers[0] == 0 && D_801003FC_DeepSeaDivers != 0) {
        func_800FBB30_DeepSeaDivers();
    }
    func_800F6B48_DeepSeaDivers();
    func_800FD8C8_DeepSeaDivers();
    func_800F6F7C_DeepSeaDivers();
}
void func_800F6F7C_DeepSeaDivers(void) {
    if (D_80100402_DeepSeaDivers < 0 && func_80072718() == 0) {
        HuMemDirectFree(D_801003F8_DeepSeaDivers);
        HuMemDirectFree(D_801003F4_DeepSeaDivers);
        func_800FDD84_DeepSeaDivers(D_80100466_DeepSeaDivers[0]);
        func_800FDD84_DeepSeaDivers(D_80100466_DeepSeaDivers[1]);
        func_800FC148_DeepSeaDivers();
        func_80060198();
        omOvlReturnEx(1);
    }
}
void func_800F7000_DeepSeaDivers(omObjData* obj) {
    GMesCreate(8, (s16)(D_80100404_DeepSeaDivers / 30), 160, 24);
    obj->func_ptr = func_800F7074_DeepSeaDivers;
}
void func_800F7074_DeepSeaDivers(omObjData* obj) {
    func_80079078((s16)((D_80100404_DeepSeaDivers + 29) / 30));
    if (D_80100404_DeepSeaDivers == 0 || D_80100402_DeepSeaDivers != 0) {
        obj->func_ptr = NULL;
        func_800790C0();
    }
}
// register allocation: retail keeps sprite in s3 (the loop counter's register); tried reusing i, decl order (masked 3)
#ifdef NON_MATCHING
void func_800F70F4_DeepSeaDivers(omObjData* obj) {
    s16 sprite;
    s16 m;
    s16 i;

    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    for (i = 0; (u16)i < 2; i++) {
        obj->model[i] = func_800174C0(D_800FF960_DeepSeaDivers[i], 0x2D9);
        func_80025798(obj->model[i], obj->trans.x, obj->trans.y, obj->trans.z);
        func_80025830(obj->model[i], obj->scale.x, obj->scale.y, obj->scale.z);
        if (i == 0) {
            func_80025EB4(obj->model[0], 2, 2);
            D_800F2B7C[obj->model[0]].unk_4C = 0.5f;
        }
    }
    func_800FF6E0_DeepSeaDivers(obj);
    sprite = InitSprite(0x440007);
    D_801003F8_DeepSeaDivers = HuMemDirectMalloc(21 * 5 * sizeof(Vtx));
    func_800F72EC_DeepSeaDivers();
    D_801003F4_DeepSeaDivers = HuMemDirectMalloc(0x200 * sizeof(Gfx));
    func_800F7470_DeepSeaDivers(D_801003F4_DeepSeaDivers, sprite);
    m = func_80024198(0xC0, D_801003F4_DeepSeaDivers, 4);
    func_80025830(m, 2.0f, 2.0f, 2.0f);
    func_80025798(m, 0.0f, 0.0f, -2000.0f);
    obj->func_ptr = func_800F72D0_DeepSeaDivers;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800F70F4_DeepSeaDivers);
#endif
void func_800F72D0_DeepSeaDivers(omObjData* obj) {
    func_800FF730_DeepSeaDivers(obj);
}
// scheduling: retail places the sra of k*16 after the D_801003F8 load (masked 2)
#ifdef NON_MATCHING
void func_800F72EC_DeepSeaDivers(void) {
    Vtx* v;
    s16 i;
    s16 k;
    s16 y;

    for (i = 0; i < 21; i++) {
        k = i * 5;
        v = &D_801003F8_DeepSeaDivers[k];
        v[0].v.ob[0] = -1900;
        v[1].v.ob[0] = -950;
        v[2].v.ob[0] = 0;
        v[3].v.ob[0] = 950;
        v[4].v.ob[0] = 1900;
        v[0].v.ob[2] = v[1].v.ob[2] = v[2].v.ob[2] = v[3].v.ob[2] = v[4].v.ob[2] = -2000;
        y = (140.0 - i * 20) * 5.0;
        v[0].v.ob[1] = v[1].v.ob[1] = v[2].v.ob[1] = v[3].v.ob[1] = v[4].v.ob[1] = y;
        v[0].v.tc[0] = 0;
        v[1].v.tc[0] = 0xA00;
        v[2].v.tc[0] = 0x1400;
        v[3].v.tc[0] = 0x1E00;
        v[4].v.tc[0] = 0x2800;
        v[0].v.tc[1] = v[1].v.tc[1] = v[2].v.tc[1] = v[3].v.tc[1] = v[4].v.tc[1] = i * 0x300;
        v[0].v.cn[0] = v[1].v.cn[0] = v[2].v.cn[0] = v[3].v.cn[0] = v[0].v.cn[0] = 0;
        D_801003F8_DeepSeaDivers[k].v.cn[1] = D_801003F8_DeepSeaDivers[k + 1].v.cn[1] = D_801003F8_DeepSeaDivers[k + 2].v.cn[1] = D_801003F8_DeepSeaDivers[k + 3].v.cn[1] = D_801003F8_DeepSeaDivers[k].v.cn[1] = 0;
        D_801003F8_DeepSeaDivers[k].v.cn[2] = D_801003F8_DeepSeaDivers[k + 1].v.cn[2] = D_801003F8_DeepSeaDivers[k + 2].v.cn[2] = D_801003F8_DeepSeaDivers[k + 3].v.cn[2] = D_801003F8_DeepSeaDivers[k + 4].v.cn[2] = 0;
        D_801003F8_DeepSeaDivers[k].v.cn[3] = D_801003F8_DeepSeaDivers[k + 1].v.cn[3] = D_801003F8_DeepSeaDivers[k + 2].v.cn[3] = D_801003F8_DeepSeaDivers[k + 3].v.cn[3] = D_801003F8_DeepSeaDivers[k + 4].v.cn[3] = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800F72EC_DeepSeaDivers);
#endif
// one instruction short and loop-temporary registers differ (masked 4); not finished in M1c
#ifdef NON_MATCHING
void func_800F7470_DeepSeaDivers(Gfx* gfx, s16 sprite) {
    unk65770Anim* a = func_80067310(sprite);
    s16 i;
    s16 cur;
    s16 next;

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gfx++, G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
    gSPSetGeometryMode(gfx++, G_CULL_BACK);
    gDPSetCombine(gfx++, 0xFFFFFF, 0xFFFCF279);
    gDPSetRenderMode(gfx++, 0x443078, 0);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gDPSetTexturePersp(gfx++, G_TP_PERSP);
    gDPSetColorDither(gfx++, G_CD_NOISE);
    gSPTexture(gfx++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(gfx++, a->unkC);
    cur = 0;
    gSPVertex(gfx++, D_801003F8_DeepSeaDivers, 5, 0);
    for (i = 0; i < 20; i++) {
        gDPLoadTextureTile(gfx++, a->unk8, G_IM_FMT_CI, G_IM_SIZ_8b, 160, 0, 0, i * 12, 159, i * 12 + 11, 0,
                           G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        next = cur + 5;
        if (next >= 30) {
            next = 0;
        }
        gSPVertex(gfx++, &D_801003F8_DeepSeaDivers[(i + 1) * 5], 5, next);
        gSP2Triangles(gfx++, cur, next, cur + 1, 0, cur + 1, next, next + 1, 0);
        gSP2Triangles(gfx++, cur + 1, next + 1, cur + 2, 0, cur + 2, next + 1, next + 2, 0);
        gSP2Triangles(gfx++, cur + 2, next + 2, cur + 3, 0, cur + 3, next + 2, next + 3, 0);
        gSP2Triangles(gfx++, cur + 3, next + 3, cur + 4, 0, cur + 4, next + 3, next + 4, 0);
        cur = next;
    }
    gSPEndDisplayList(gfx++);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800F7470_DeepSeaDivers);
#endif
void func_800F791C_DeepSeaDivers(omObjData* obj) {
    obj->model[0] = LoadFormFile(0x16000E, 0x299);
    func_800FEA00_DeepSeaDivers(obj);
    obj->func_ptr = func_800FEF34_DeepSeaDivers;
}
void func_800F7968_DeepSeaDivers(omObjData* obj) {
    DSDPlayerWork* w;
    DSDWork* dw;
    s16 player;
    s32 dir;
    u8 chr;

    player = D_8010046A_DeepSeaDivers[D_80100C70_DeepSeaDivers[1] * 2];
    chr = GwPlayer[player].character;
    dir = D_800C59AC[chr].unk_00;
    obj->model[0] = LoadFormFile(dir | D_800C59AC[chr].unk_04, 0x299);
    D_800F2B7C[obj->model[0]].unk_4C = 0.0f;
    func_800093FC(obj, D_800FF968_DeepSeaDivers[D_80100C70_DeepSeaDivers[1]], 650.0f, -325.0f);
    func_8000941C(obj, 1.0f, 1.0f, 1.0f);
    obj->unk_50 = w = func_80023684(sizeof(DSDPlayerWork), 0x7918);
    func_8009B770(w, 0, sizeof(DSDPlayerWork));
    w->unk_50 = 0;
    w->unk_52 = 0;
    w->unk_56 = GwPlayer[player].port;
    w->unk_C0 = 0xFFFF;
    w->unk_D8 = func_80023684(obj->mtncnt * 0xE8, 0x7918);
    func_8009B770(w->unk_D8, 0, obj->mtncnt * 0xE8);
    func_8001874C(obj, 0, dir | 0x31, 1, 0);
    func_800184BC(obj, 0);
    func_80025BB8(obj->model[0], obj->motion[0]);
    D_800F2B7C[obj->model[0]].unk_4C = 0.0f;
    obj->model[1] = LoadFormFile(0x3F0004, 0x499);
    D_800F2B7C[obj->model[1]].unk_4C = 0.0f;
    func_80025798(obj->model[1], obj->trans.x, obj->trans.y + 25.0, obj->trans.z + 20.0);
    func_800257E4(obj->model[1], 0.0f, 0.0f, 0.0f);
    func_80025830(obj->model[1], 1.0f, 1.0f, 1.0f);
    obj->model[2] = func_800174C0(D_800FF96C_DeepSeaDivers[D_80100C70_DeepSeaDivers[1]], 0x2D9);
    func_80025830(obj->model[2], 1.0f, 1.0f, 1.0f);
    obj->func_ptr = func_800F7C9C_DeepSeaDivers;
    dw = func_800FC058_DeepSeaDivers(obj);
    dw->unkC = D_80100C70_DeepSeaDivers[1];
    dw->unk44 = player;
    D_80100C70_DeepSeaDivers[1]++;
}
#ifdef NON_MATCHING
void func_800F7C9C_DeepSeaDivers(omObjData* obj) {
    f32 dirs[4][2] = { { 64.0f, 0.0f }, { 0.0f, 64.0f }, { -64.0f, 0.0f }, { 0.0f, -64.0f } };
    DSDPlayerWork* pl;
    DSDWork* w;
    omObjData* diver;
    DSDWork* dw;
    f32 spd = 0.0f;
    f32 ang;
    s16 sx;
    s16 sy;
    s16 q;
    s16 d;
    s16 pressed;

    pl = obj->unk_50;
    w = func_800FC1C8_DeepSeaDivers(obj);
    diver = D_80101780_DeepSeaDivers[w->unkC].diver;
    dw = func_800FC1C8_DeepSeaDivers(diver);
    if (w->unk0 == 0) {
        w->unk0 = 1;
        D_80100466_DeepSeaDivers[w->unkC] = func_800FDBEC_DeepSeaDivers();
        D_80100478_DeepSeaDivers[w->unkC].top.x = obj->trans.x + -15.0;
        D_80100478_DeepSeaDivers[w->unkC].top.y = obj->trans.y + 165.0;
        D_80100478_DeepSeaDivers[w->unkC].top.z = obj->trans.z + 150.0;
        func_800FDE04_DeepSeaDivers(D_80100466_DeepSeaDivers[w->unkC], spd, &D_80100478_DeepSeaDivers[w->unkC].top);
        w->unk10 = spd;
        w->unk14 = obj->trans.y;
        w->unk48 = -1;
        w->unk4A = 5;
        w->unk4C = 4;
        w->unk4E = 4;
        w->unk50 = 0;
        w->unk52 = 0;
        w->unk54 = 0;
        w->unk56 = -1;
    } else {
        if (D_80100400_DeepSeaDivers == 0) {
            if (!(GwPlayer[w->unk44].flags & 1)) {
                sx = ContStkX[pl->unk_56];
                sy = ContStkY[pl->unk_56];
            } else if ((dw->unk2 & 1) && !(*(s32*)&dw->unk0 & 0xC)) {
                /* The diver holds on: follow it along the surface. */
                sy = 0;
                if (fabsf(diver->trans.x - obj->trans.x) >= 200.0) {
                    if (obj->trans.x < diver->trans.x) {
                        sx = 0x40;
                    } else {
                        sx = -0x40;
                    }
                } else {
                    sx = 0;
                }
            } else {
                sx = dirs[w->unk54][0];
                sy = dirs[w->unk54][1];
                if (!(GwPlayer[dw->unk44].flags & 1)) {
                    if ((u32)(func_800FC1F4_DeepSeaDivers() * (GwPlayer[w->unk44].cpu_difficulty + 15)) >> 16) {
                        w->unk54 = (w->unk54 + 1) & 3;
                    }
                } else {
                    if (((u32)(func_800FC1F4_DeepSeaDivers() * (GwPlayer[w->unk44].cpu_difficulty + 15)) >> 16) >=
                        8) {
                        w->unk54 = (w->unk54 + 1) & 3;
                    }
                }
            }
            pressed = 0;
            ang = func_8009B618(func_800B0CD8(sx, sy) + 180.0, 360.0);
            if (sx | sy) {
                q = (s32)(func_8009B618(ang + 45.0, 360.0) / 90.0);
                if (q == w->unk48) {
                    if (w->unk4A != 0) {
                        w->unk4A--;
                    }
                    if (w->unk4E != 0) {
                        pressed = 1;
                        if (--w->unk4E == 0 && w->unk56 >= 0) {
                            func_8006071C(w->unk56);
                            w->unk56 = -1;
                        }
                    } else {
                        w->unk4C = 4;
                        pressed = 1;
                    }
                } else {
                    d = q - w->unk48;
                    if (d < 0) {
                        d += 4;
                    }
                    if (w->unk50 == 0) {
                        if (d == 1) {
                            w->unk50 = 1;
                        }
                        if (d == 3) {
                            w->unk50 = 2;
                        }
                    }
                    if (((w->unk50 == 1) & (d == 1)) || ((w->unk50 == 2) & (d == 3))) {
                        if (w->unk4C != 0) {
                            w->unk4C--;
                        }
                        w->unk4E = 4;
                        if (w->unk56 < 0) {
                            w->unk56 = func_80060540(0x342, w->unk44);
                        }
                    } else {
                        w->unk50 = 0;
                    }
                    w->unk4A = 5;
                }
                if (w->unk4A != 0) {
                    w->unk48 = q;
                } else {
                    if (q == 1 && w->unk10 > -10.0) {
                        w->unk10 = w->unk10 - 2.0;
                    }
                    if (q == 3 && w->unk10 < 10.0) {
                        w->unk10 = w->unk10 + 2.0;
                    }
                    w->unk48 = q;
                }
            } else {
                w->unk48 = -1;
                w->unk4A = 5;
                w->unk4C = 4;
                w->unk4E = 4;
                w->unk50 = 0;
                if (w->unk56 >= 0) {
                    func_8006071C(w->unk56);
                    w->unk56 = -1;
                }
            }
            if (w->unk4C == 0) {
                spd = 10.0f;
                D_800F2B7C[obj->model[0]].unk_4C = 1.0f;
            } else {
                D_800F2B7C[obj->model[0]].unk_4C = 0.0f;
                spd = D_800F2B7C[obj->model[0]].unk_4C;
            }
            if (pressed == 0 && w->unk10 != 0.0) {
                if (w->unk10 > 0.0) {
                    w->unk10 = w->unk10 - 1.0;
                    if (w->unk10 < 0.0) {
                        w->unk10 = 0.0f;
                    }
                } else {
                    w->unk10 = w->unk10 + 1.0;
                    if (w->unk10 > 0.0) {
                        w->unk10 = 0.0f;
                    }
                }
            }
            obj->trans.x += w->unk10;
            obj->trans.y = w->unk14 + func_800AEAC0(func_8009B618(w->unk52, 360.0)) * 5.0;
            w->unk52 += 4;
            if (func_800FD28C_DeepSeaDivers(obj) != 0) {
                if (!(w->unk0 & 2)) {
                    func_80060540(0x343, w->unk44);
                    w->unk0 |= 2;
                }
            } else {
                w->unk0 &= ~2;
            }
        } else {
            D_800F2B7C[obj->model[0]].unk_4C = 0.0f;
            if (w->unk56 >= 0) {
                func_8006071C(w->unk56);
                w->unk56 = -1;
            }
        }
        func_80025798(obj->model[1], obj->trans.x, obj->trans.y + 25.0, obj->trans.z + 20.0);
        func_80025798(obj->model[2], obj->trans.x, obj->trans.y, obj->trans.z);
        D_80100478_DeepSeaDivers[w->unkC].top.x = obj->trans.x + -15.0;
        D_80100478_DeepSeaDivers[w->unkC].top.y = obj->trans.y + 165.0;
        D_80100478_DeepSeaDivers[w->unkC].top.z = obj->trans.z + 150.0;
        func_800FDE04_DeepSeaDivers(D_80100466_DeepSeaDivers[w->unkC], spd, &D_80100478_DeepSeaDivers[w->unkC].top);
        func_80017DB0(obj);
        func_800FBAC8_DeepSeaDivers(obj->trans.x, obj->trans.y + 200.0, obj->trans.z, 0.0f);
    }
}
#else
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", D_800FFEC0_DeepSeaDivers);
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800F7C9C_DeepSeaDivers);
#endif
void func_800F8680_DeepSeaDivers(omObjData* obj) {
    DSDPlayerWork* w;
    DSDWork* dw;
    s16 player;
    s32 dir;
    u8 chr;

    player = D_8010046A_DeepSeaDivers[D_80100C70_DeepSeaDivers[2] * 2 + 1];
    chr = GwPlayer[player].character;
    dir = D_800C59AC[chr].unk_00;
    obj->model[0] = LoadFormFile(dir | D_800C59AC[chr].unk_04, 0x299);
    func_800093FC(obj, D_800FF968_DeepSeaDivers[D_80100C70_DeepSeaDivers[2]], 325.0f, -200.0f);
    func_8000941C(obj, 1.0f, 1.0f, 1.0f);
    obj->unk_50 = w = func_80023684(sizeof(DSDPlayerWork), 0x7918);
    func_8009B770(w, 0, sizeof(DSDPlayerWork));
    w->unk_50 = 0;
    w->unk_52 = 0;
    w->unk_56 = GwPlayer[player].port;
    w->unk_C0 = 0xFFFF;
    w->unk_58 = GwPlayer[player].character;
    w->unk_AE = 0;
    obj->func_ptr = func_800F88E0_DeepSeaDivers;
    w->unk_D8 = func_80023684(obj->mtncnt * 0xE8, 0x7918);
    func_8009B770(w->unk_D8, 0, obj->mtncnt * 0xE8);
    func_8001874C(obj, 0, dir | 0xC, 1, 0);
    func_8001874C(obj, 1, dir | 0x13, 1, 0);
    func_8001874C(obj, 2, dir | 0x14, 1, 0);
    func_8001874C(obj, 3, dir | 0x16, 2, 0);
    func_8001874C(obj, 4, dir | 0x17, 1, 0);
    func_8001874C(obj, 5, dir | 0x24, 2, 0);
    dw = func_800FC058_DeepSeaDivers(obj);
    dw->unkC = D_80100C70_DeepSeaDivers[2];
    dw->unk44 = player;
    D_80100C70_DeepSeaDivers[2]++;
}
#ifdef NON_MATCHING
void func_800F88E0_DeepSeaDivers(omObjData* obj) {
    DSDPlayerWork* pl;
    DSDWork* w;
    DSDWork* tw;
    unk2C0C0Struct50* anim;
    Matrix4f m;
    Vec2f n;
    f32 cur;
    f32 tgt;
    f32 t;
    f32 f;
    f32 z;
    f32 fx;
    f32 fy;
    s32 r;
    s16 q;
    s16 k;
    s16 sx;
    s16 sy;
    s16 hit;
    u16 btn;
    s8 port;
    s32 flag;

    pl = obj->unk_50;
    w = func_800FC1C8_DeepSeaDivers(obj);
    if (w->unk0 >= 0) {
        w->unk0 |= 0x8000;
        w->unk2 = 1;
        w->unk4 = w->unk6 = 30;
        w->unk40 = -1;
        w->unk42 = 0;
        w->unk46 = 0;
        w->unk48 = 0;
        w->unk4A = 0;
        w->unk4C = 0;
        w->unk4E = 600;
        w->unk50 = 0;
        w->unk52 = 0;
        w->unk54 = 0;
        w->unk56 = 0;
        w->unk58 = 0;
        w->unk5A = 0;
        w->unk5E = -1;
        D_80100478_DeepSeaDivers[w->unkC].bottom.x = obj->trans.x;
        D_80100478_DeepSeaDivers[w->unkC].bottom.y = obj->trans.y;
        D_80100478_DeepSeaDivers[w->unkC].bottom.z = obj->trans.z;
    }
    cur = pl->unk_3C;
    port = pl->unk_56;
    w->unk1C = obj->trans.x;
    w->unk20 = obj->trans.y;
    if (D_80100400_DeepSeaDivers == 0 && w->unk8 >= 0) {
        sy = 0;
        if (!(GwPlayer[w->unk44].flags & 1)) {
            r = func_80009C90(obj, ContStkX[port], ContStkY[port]);
            sx = r >> 16;
            sy = r;
            btn = ContBtn[port] & ~w->unk5A;
            w->unk5A = ContBtn[port];
        } else {
            sx = 0;
            btn = func_800FB310_DeepSeaDivers(obj);
        }
        if (btn & 0x8000) {
            w->unk24 = w->unk24 + 0.4;
            if (w->unk24 > 2.0) {
                w->unk24 = 2.0f;
            }
            if (w->unk4C == 0) {
                func_800FD680_DeepSeaDivers(0, obj->trans.x, obj->trans.y, obj->trans.z, w->unkA);
                w->unk4C = 4;
                func_80060618((w->unk2 & 2) ? 0x178 : 0x163, w->unk44);
                w->unk5C = 16;
            } else {
                w->unk4C--;
                w->unk5C = 16;
            }
            if (pl->unk_AE == 0) {
                func_80060F04(w->unk44, 5, 0, 5);
                pl->unk_AE = 16;
            }
        }
        if (w->unk5C != 0) {
            w->unk5C--;
        } else {
            w->unk24 = w->unk24 - 0.1;
            if (w->unk24 < 0.0) {
                w->unk24 = 0.0f;
            }
        }
        if (pl->unk_AE != 0) {
            pl->unk_AE--;
        }
        if (w->unk5E < 0) {
            anim = D_800F2B7C[obj->model[0]].unk_6C->unk_A0;
            guTranslateF(m, obj->trans.x, obj->trans.y, obj->trans.z);
            MtxRotate(m, w->unk28 + anim->unk_44.x - 90.0, w->unk2C + anim->unk_44.y, 0.0f);
            MtxTranslate(m, 0.0f, -7.5f, 30.0f);
            w->unk5E = func_800FCDC8_DeepSeaDivers(m[3][0], m[3][1], 40.0f, 40.0f);
            if (w->unk5E >= 0) {
                w->unk8 = 1;
                tw = func_800FC1C8_DeepSeaDivers(D_80101BB0_DeepSeaDivers[w->unk5E]);
                tw->unk8 = 1;
                tw->unk40 = 16;
                tw->unk5E = w->unkC;
                func_80060F04(w->unk44, 20, 0, 20);
                func_80060F04(D_8010046A_DeepSeaDivers[w->unkC * 2], 20, 0, 20);
                func_80060540(0x344, w->unk44);
            }
        }
    } else {
        sy = 0;
        if (!(GwPlayer[w->unk44].flags & 1)) {
            func_80009C90(obj, ContStkX[port], ContStkY[port]);
            sy = 0;
        }
        sx = 0;
        pl->unk_40 = 0.0f;
        w->unk24 = 0.0f;
    }
    if (pl->unk_40 != w->unk24) {
        if (w->unk24 < pl->unk_40) {
            pl->unk_40 = pl->unk_40 - 0.08;
            if (pl->unk_40 < w->unk24) {
                pl->unk_40 = w->unk24;
            }
        } else {
            pl->unk_40 = pl->unk_40 + 0.08;
            if (w->unk24 < pl->unk_40) {
                pl->unk_40 = w->unk24;
            }
        }
    }
    if (w->unk8 >= 0) {
        if (w->unk50 != 0) {
            func_800184BC(obj, 1);
        } else {
            switch (w->unk8) {
                case 0:
                    if (pl->unk_40 < 0.2) {
                        func_800184BC(obj, 4);
                    } else {
                        func_800184BC(obj, 0);
                    }
                    break;
                case 1:
                    func_800184BC(obj, 0);
                    break;
            }
        }
    } else if (w->unk4A == 0) {
        func_800184BC(obj, 2);
        D_800F2B7C[obj->model[0]].unk_20 ^= 4;
    } else {
        func_800184BC(obj, 0);
    }
    if (w->unk2 & 8) {
        func_80028498(obj->model[0], D_800F2B7C[obj->motion[5]].unk_08, 0);
    } else {
        D_800F2B7C[obj->model[0]].unk_14 = -1;
    }
    if (!(GwPlayer[w->unk44].flags & 1)) {
        tgt = func_800B0CD8(sx, -sy) + 180.0;
    } else {
        tgt = w->unk42;
    }
    if (tgt >= 360.0) {
        tgt = tgt - 360.0;
    }
    if (tgt != cur) {
        if ((tgt - cur < -180.0f && tgt - cur < 0.0f) || (tgt - cur < 180.0f && tgt - cur > 0.0f)) {
            cur += 10.0f;
            if (-180.0f < tgt - cur && tgt - cur < 0.0f) {
                cur = tgt;
            } else if (180.0f < tgt - cur && 0.0f < tgt - cur) {
                cur = tgt;
            }
            if (cur > 360.0) {
                cur = cur - 360.0;
            }
        } else {
            cur -= 10.0f;
            if (tgt - cur < -180.0f && tgt - cur < 0.0f) {
                cur = tgt;
            } else if (tgt - cur < 180.0f && 0.0f < tgt - cur) {
                cur = tgt;
            }
            if (cur < 0.0) {
                cur = cur + 360.0;
            }
        }
    }
    pl->unk_3C = cur;
    q = (s32)(cur / 90.0);
    t = (cur - q * 90.0) / 90.0;
    k = (q + 1 < 4) ? q + 1 : 0;
    w->unk28 = t * (D_800FF974_DeepSeaDivers[k][0] - D_800FF974_DeepSeaDivers[q][0]) + D_800FF974_DeepSeaDivers[q][0];
    w->unk28 = w->unk28 * (pl->unk_40 / 2.0);
    w->unk2C = t * (D_800FF974_DeepSeaDivers[k][1] - D_800FF974_DeepSeaDivers[q][1]) + D_800FF974_DeepSeaDivers[q][1];
    obj->rot.x = w->unk28;
    obj->rot.y = w->unk2C;
    obj->rot.z = 0.0f;
    obj->trans.x = obj->trans.x - func_800AEAC0(cur) * pl->unk_40 * 5.0;
    obj->trans.y = obj->trans.y + func_800AEFD0(cur) * pl->unk_40 * 5.0;
    if (w->unk54 != 0) {
        if (w->unk54 > 0) {
            w->unk54--;
        } else {
            w->unk54++;
        }
    }
    if (obj->trans.y > 475.0) {
        if (obj->trans.y >= 625.0) {
            w->unk52++;
            w->unk54 = -fabs(func_800AEAC0(w->unk52 * 4.5) * 4.0);
            if (!(w->unk2 & 2)) {
                func_800FD680_DeepSeaDivers(1, obj->trans.x, obj->trans.y, obj->trans.z, 0);
                func_80060618(0x171, w->unk44);
            }
            w->unk2 |= 2;
            if ((s16)(w->unk52 % 80) == 0 && D_80100400_DeepSeaDivers == 0) {
                func_80060618(0x171, w->unk44);
            }
            if (w->unk8 < 0 && w->unk4A == 0) {
                w->unk2 = (w->unk2 | 1) & ~4;
                D_800F2B7C[obj->model[0]].unk_20 &= ~4;
                w->unk4A = 30;
            }
        } else {
            obj->trans.y = obj->trans.y + 1.0;
        }
        if (obj->trans.y < 585.0) {
            w->unk52 = 0;
            if (w->unk2 & 2) {
                func_800FD680_DeepSeaDivers(1, obj->trans.x, obj->trans.y, obj->trans.z, 0);
                func_80060618(0x16A, w->unk44);
            }
            w->unk2 &= ~2;
        }
        if (obj->trans.y > 485.0) {
            if (w->unk50 != 0) {
                w->unk2 &= ~4;
                w->unk8 = 0;
                w->unk50 = 0;
            }
            w->unk4E = 600;
        }
    } else if (D_80100400_DeepSeaDivers == 0) {
        obj->trans.y = obj->trans.y - 1.0;
        if (w->unk5E >= 0) {
            obj->trans.y =
                obj->trans.y - (f32)func_800FC1C8_DeepSeaDivers(D_80101BB0_DeepSeaDivers[w->unk5E])->unk52 / 96.0 * 5.0;
        }
        if (D_80100400_DeepSeaDivers == 0) {
            if (w->unk4E-- == 0) {
                w->unk2 |= 4;
                w->unk50 = 180;
                func_800FD680_DeepSeaDivers(2, 0.0f, 0.0f, 0.0f, w->unkA);
            }
        }
    }
    z = obj->trans.z;
    func_800FDE44_DeepSeaDivers(D_80100466_DeepSeaDivers[w->unkC], &obj->trans, &obj->trans);
    obj->trans.z = z;
    func_800FCF54_DeepSeaDivers(obj, obj->trans.x - w->unk1C, obj->trans.y - w->unk20);
    func_800FC22C_DeepSeaDivers(NULL, &obj->trans.x, &obj->trans.y, &obj->trans.z);
    w->unk2 &= ~0x20;
    if (w->unk8 >= 0) {
        n.y = 0.0f;
        n.x = 0.0f;
        flag = 0;
        if (func_8009B618(pl->unk_3C + 90.0f, 360.0) < 180.0) {
            flag = 1;
        }
        hit = func_800FC644_DeepSeaDivers(&obj->trans.x, &obj->trans.y, 50, flag, &n.x, &n.y);
        fx = -func_800AEAC0(pl->unk_3C);
        fy = func_800AEFD0(pl->unk_3C);
        if (hit != 0 && fx * n.x + fy * n.y < -0.75) {
            w->unk2 |= 0x20;
            if (w->unk58 < 16) {
                w->unk58++;
            } else if (w->unk56 == 0) {
                w->unk46 = w->unk42;
                w->unk56 = (func_800FC1F4_DeepSeaDivers() & 0x97) | 0x90;
                w->unk2 |= 0x40;
            }
        } else {
            w->unk58 = 0;
        }
    }
    D_80100478_DeepSeaDivers[w->unkC].bottom.x = obj->trans.x;
    D_80100478_DeepSeaDivers[w->unkC].bottom.y = obj->trans.y;
    D_80100478_DeepSeaDivers[w->unkC].bottom.z = obj->trans.z;
    if (w->unk4A != 0) {
        if (w->unk4A < 9) {
            f = (f32)w->unk4A / 8.0;
        } else {
            f = 1.0f;
        }
        obj->rot.x = f * -90.0;
        obj->rot.y = 0.0f;
        if (--w->unk4A == 0) {
            w->unk8 = 0;
            w->unk4E = 300;
            if (GwPlayer[w->unk44].flags & 1) {
                w->unk42 = 0;
            }
        } else if (w->unk4A == 15) {
            func_800FD680_DeepSeaDivers(4, obj->trans.x, obj->trans.y, obj->trans.z, w->unkC);
        }
    }
    if (w->unk8 >= 0 && w->unk50 != 0) {
        if ((s16)(w->unk50 % 30) == 0) {
            func_80060618(0x17F, w->unk44);
        }
        if (--w->unk50 == 0) {
            w->unk2 &= ~1;
            w->unk8 = -1;
            pl->unk_C0 = 0xFFFF;
            func_800184BC(obj, 2);
            D_800F2B7C[obj->model[0]].unk_14 = -1;
            func_80060618(0x187, w->unk44);
        }
        if (!(w->unk50 & 7)) {
            func_800FD680_DeepSeaDivers(0, obj->trans.x, obj->trans.y, obj->trans.z, w->unkA);
        }
    }
    w->unk10 = obj->trans.x;
    w->unk14 = obj->trans.y;
    w->unk18 = obj->trans.z;
    func_800FBAC8_DeepSeaDivers(obj->trans.x, obj->trans.y, obj->trans.z, 0.0f);
    if (w->unk5E < 0) {
        w->unk2 &= ~8;
    } else {
        w->unk2 |= 8;
    }
    func_80017DB0(obj);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800F88E0_DeepSeaDivers);
#endif
void func_800F9AF4_DeepSeaDivers(omObjData* obj) {
    DSDTreasureDef defs[8] = {
        { 1, -320, 40, 1 }, { 1, -150, -40, 2 }, { 1, -380, -180, 3 }, { 1, 320, 40, 1 },
        { 1, 150, -40, 2 }, { 1, 380, -180, 3 }, { 1, 0, -160, 5 },    { 2, 0, -2000, 10 },
    };
    DSDWork* w;
    f32 y;
    f64 s;

    obj->func_ptr = func_800F9DD8_DeepSeaDivers;
    y = func_800FCAE8_DeepSeaDivers((f32)defs[D_8010040C_DeepSeaDivers].x * 5.0,
                                    (f32)defs[D_8010040C_DeepSeaDivers].y * 5.0);
    if (D_8010040C_DeepSeaDivers == 0) {
        obj->model[0] = LoadFormFile(0x16000F, 0x99);
        obj->model[1] = LoadFormFile(0x440005, 0x99);
    } else {
        obj->model[0] = func_80023FC8(D_80101BB0_DeepSeaDivers[0]->model[0]);
        obj->model[1] = func_80023FC8(D_80101BB0_DeepSeaDivers[0]->model[1]);
    }
    func_800093FC(obj, defs[D_8010040C_DeepSeaDivers].x * 5.0, y, -300.0f);
    func_80025798(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    s = (f32)defs[D_8010040C_DeepSeaDivers].scale * 75.0 / 50.0;
    func_8000941C(obj, s, s, s * 0.5);
    func_80025830(obj->model[1], obj->scale.x, obj->scale.y, obj->scale.z);
    D_800F2B7C[obj->model[0]].unk_4C = 0.0f;
    w = func_800FC058_DeepSeaDivers(obj);
    w->unk4E = defs[D_8010040C_DeepSeaDivers].value;
    w->unk34 = obj->scale.x;
    D_8010040C_DeepSeaDivers++;
}
#ifdef NON_MATCHING
void func_800F9DD8_DeepSeaDivers(omObjData* obj) {
    DSDWork* w;
    DSDWork* pw;
    omObjData* diver;
    unk2C0C0Struct50* anim;
    DSDPlayerWork* plw;
    Matrix4f m;
    f64 sc;
    f32 h;
    f32 t;
    f32 s;

    w = func_800FC1C8_DeepSeaDivers(obj);
    if (w->unk0 >= 0) {
        w->unk0 |= 0x8080;
        w->unk10 = D_800F2B7C[obj->model[0]].unk_24;
        w->unk14 = D_800F2B7C[obj->model[0]].unk_28;
        w->unk18 = D_800F2B7C[obj->model[0]].unk_2C;
        w->unk42 = (u32)(func_800FC1F4_DeepSeaDivers() * 3) >> 16;
        if (w->unk4E < 10) {
            w->unk50 = 4;
            w->unk52 = 0xE0;
        } else {
            w->unk50 = 5;
            w->unk52 = 0x100;
        }
        w->unk5C = 24;
        w->unk5E = -1;
        sc = D_800F2B7C[obj->model[0]].unk_3C;
        w->unk4 = sc * 9.0 * 5.0;
        w->unk6 = sc * 7.5 * 5.0;
    }
    switch (w->unk8) {
        case 0:
            if (w->unk20 < (f32)w->unk52 / 32.0) {
                w->unk20 += (f32)w->unk50 / 128.0;
            }
            h = func_800FCAE8_DeepSeaDivers(obj->trans.x, obj->trans.y);
            obj->trans.y = obj->trans.y - w->unk20 * 5.0;
            if (obj->trans.y < h) {
                obj->trans.y = h;
            }
            obj->trans.z = -600.0f;
            func_800FC22C_DeepSeaDivers(NULL, &obj->trans.x, &obj->trans.y, &obj->trans.z);
            w->unk5C = 24;
            obj->scale.x = obj->scale.y = w->unk34;
            if (D_801003FC_DeepSeaDivers == 0) {
                if (D_801003FE_DeepSeaDivers & 7) {
                    D_800F2B7C[obj->model[0]].unk_20 &= ~4;
                    D_800F2B7C[obj->model[1]].unk_20 |= 4;
                } else {
                    D_800F2B7C[obj->model[0]].unk_20 |= 4;
                    D_800F2B7C[obj->model[1]].unk_20 &= ~4;
                }
            }
            break;
        case 1:
            if (w->unk5C != 0) {
                w->unk5C--;
                s = (f32)(fabs(func_800AEAC0(w->unk5C * 22.5)) * 0.5 + 1.0) * w->unk34;
                obj->scale.x = obj->scale.y = s;
            }
            diver = D_80101780_DeepSeaDivers[w->unk5E].diver;
            pw = func_800FC1C8_DeepSeaDivers(diver);
            if (!(pw->unk2 & 1)) {
                w->unk8 = 0;
                w->unk5E = -1;
                pw->unk5E = -1;
            } else {
                anim = D_800F2B7C[diver->model[0]].unk_6C->unk_A0;
                plw = diver->unk_50;
                guTranslateF(m, diver->trans.x, diver->trans.y, diver->trans.z);
                MtxRotate(m, pw->unk28 + anim->unk_44.x - 90.0, pw->unk2C + anim->unk_44.y, 0.0f);
                MtxTranslate(m, D_800FF994_DeepSeaDivers[plw->unk_58].x, D_800FF994_DeepSeaDivers[plw->unk_58].y,
                             D_800FF994_DeepSeaDivers[plw->unk_58].z);
                if (w->unk40 != 0) {
                    t = (f32)(16 - w->unk40) / 16.0;
                    obj->trans.x = t * (m[3][0] - obj->trans.x) + obj->trans.x;
                    obj->trans.y = t * (m[3][1] - obj->trans.y) + obj->trans.y;
                    obj->trans.z = t * 108.0 * 5.0 + -600.0;
                    w->unk40--;
                } else {
                    obj->trans.x = m[3][0];
                    obj->trans.y = m[3][1];
                    obj->trans.z = -60.0f;
                }
            }
            if (diver->trans.y >= 585.0) {
                w->unk0 &= ~0x80;
                w->unk8++;
                pw->unk8 = 0;
                pw->unk5E = -1;
            }
            func_800FC22C_DeepSeaDivers(NULL, &obj->trans.x, &obj->trans.y, &obj->trans.z);
            break;
        case 2:
            if (obj->trans.y < 625.0) {
                obj->trans.y = obj->trans.y + 5.0;
            } else {
                w->unk8++;
                D_800F2B7C[obj->model[0]].unk_4C = 1.0f;
                w->unk40 = 80;
                PlaySound(0x196);
                w->unk54 = w->unk4E;
                GwPlayer[D_8010046A_DeepSeaDivers[w->unk5E * 2]].coins_mg += w->unk4E;
                GwPlayer[D_8010046A_DeepSeaDivers[w->unk5E * 2 + 1]].coins_mg += w->unk54;
                D_80100406_DeepSeaDivers = 1;
            }
            break;
        case 3:
            if (w->unk40-- == 0) {
                w->unk8 = -1;
            }
            if (w->unk40 < 32 && !(w->unk40 & 1) && w->unk54 != 0) {
                func_800FD680_DeepSeaDivers(3, obj->trans.x, obj->trans.y + obj->scale.x * 8.0 * 5.0, obj->trans.z,
                                            (s16)((w->unk5E << 8) | w->unk42));
                w->unk54--;
            }
            if (w->unk40 < 16) {
                D_800F2B7C[obj->model[0]].unk_20 ^= 4;
            }
            break;
    }
    w->unk10 = obj->trans.x;
    w->unk14 = obj->trans.y;
    w->unk18 = obj->trans.z;
    if (D_801003FC_DeepSeaDivers == 0 && w->unk4E == 10) {
        func_800FBAC8_DeepSeaDivers(obj->trans.x, obj->trans.y, obj->trans.z, 0.0f);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800F9DD8_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800FA62C_DeepSeaDivers(s16 idx) {
    if (D_80100C80_DeepSeaDivers[idx].flags >= 0) {
        D_80100C80_DeepSeaDivers[idx].flags |= 0x8000;
        func_800674BC(D_80100C80_DeepSeaDivers[idx].sprite, 0, func_800FC1F4_DeepSeaDivers() & 1);
        func_80067208(D_80100C80_DeepSeaDivers[idx].sprite, 0, D_80101790_DeepSeaDivers[0], 0);
        func_800672B0(D_80100C80_DeepSeaDivers[idx].sprite, 0, 0);
        func_800671DC(D_80100C80_DeepSeaDivers[idx].sprite, 0, (func_800FC1F4_DeepSeaDivers() & 3) + 15);
        D_80100C80_DeepSeaDivers[idx].unk20 = 32;
    }
    D_80100C80_DeepSeaDivers[idx].x =
        D_80100C80_DeepSeaDivers[idx].x + func_800AEAC0((D_80100C80_DeepSeaDivers[idx].timer * 4) % 360) * 5.0;
    D_80100C80_DeepSeaDivers[idx].y = D_80100C80_DeepSeaDivers[idx].y + 5.0;
    D_80100C80_DeepSeaDivers[idx].sy = func_800AEAC0((D_80100C80_DeepSeaDivers[idx].timer << 5) % 360) * 0.125 + 0.875;
    D_80100C80_DeepSeaDivers[idx].timer++;
    if (D_80100C80_DeepSeaDivers[idx].unk1E != 0) {
        if (--D_80100C80_DeepSeaDivers[idx].unk1E == 0) {
            func_800FD870_DeepSeaDivers(idx);
        }
        func_8006752C(D_80100C80_DeepSeaDivers[idx].sprite, 0, D_80100C80_DeepSeaDivers[idx].unk1E << 5);
    }
    if (--D_80100C80_DeepSeaDivers[idx].unk20 == 0 || D_80100C80_DeepSeaDivers[idx].y >= 465.0) {
        D_80100C80_DeepSeaDivers[idx].unk1E = 8;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FA62C_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800FA9A4_DeepSeaDivers(s16 idx) {
    if (D_80100C80_DeepSeaDivers[idx].flags >= 0) {
        D_80100C80_DeepSeaDivers[idx].flags |= 0x8000;
        D_80100C80_DeepSeaDivers[idx].timer = 60;
        D_80100C80_DeepSeaDivers[idx].y = 665.0f;
        func_80067208(D_80100C80_DeepSeaDivers[idx].sprite, 0, D_80101790_DeepSeaDivers[0], 3);
        D_80100C80_DeepSeaDivers[idx].sx = 0.75f;
        D_80100C80_DeepSeaDivers[idx].sy = 0.5f;
    }
    if (func_80067328(D_80100C80_DeepSeaDivers[idx].sprite, 0) & 2) {
        func_800FD870_DeepSeaDivers(idx);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FA9A4_DeepSeaDivers);
#endif
void func_800FAABC_DeepSeaDivers(s16 idx) {
    DSDWork* w;

    if (D_80100C80_DeepSeaDivers[idx].flags >= 0) {
        D_80100C80_DeepSeaDivers[idx].flags |= 0x8080;
        D_80100C80_DeepSeaDivers[idx].timer = 180;
        func_80067354(D_80100C80_DeepSeaDivers[idx].sprite, 0, 0.75f, 0.75f);
        func_80067208(D_80100C80_DeepSeaDivers[idx].sprite, 0, D_80100464_DeepSeaDivers, 0);
    }
    func_800672DC(D_80100C80_DeepSeaDivers[idx].sprite, 0, (D_80100C80_DeepSeaDivers[idx].timer - 1) / 30, 0);
    w = D_801017B0_DeepSeaDivers[D_80100C80_DeepSeaDivers[idx].target];
    D_80100C80_DeepSeaDivers[idx].x = w->unk10;
    D_80100C80_DeepSeaDivers[idx].y = w->unk14 + 120.0;
    if (--D_80100C80_DeepSeaDivers[idx].timer == 0 || !(w->unk2 & 4)) {
        func_800FD870_DeepSeaDivers(idx);
    }
}
#ifdef NON_MATCHING
void func_800FAC68_DeepSeaDivers(s16 idx) {
    f64 x0;

    if (D_80100C80_DeepSeaDivers[idx].flags >= 0) {
        D_80100C80_DeepSeaDivers[idx].flags |= 0x8000;
        func_80067208(D_80100C80_DeepSeaDivers[idx].sprite, 0, D_80101790_DeepSeaDivers[1], 0);
        D_80100C80_DeepSeaDivers[idx].timer = 24;
        D_80100C80_DeepSeaDivers[idx].unk1E = ((func_800FC1F4_DeepSeaDivers() & 7) + 8) * 8;
        D_80100C80_DeepSeaDivers[idx].unk20 = D_80100C80_DeepSeaDivers[idx].x;
        D_80100C80_DeepSeaDivers[idx].unk22 = 2;
        D_80100C80_DeepSeaDivers[idx].unk24 = D_80100C80_DeepSeaDivers[idx].unk1E;
        D_80100C80_DeepSeaDivers[idx].unk26 = (func_800FC1F4_DeepSeaDivers() & 0x1F) - 16;
        D_80100C80_DeepSeaDivers[idx].sy = 0.75f;
        D_80100C80_DeepSeaDivers[idx].sx = 0.75f;
    }
    x0 = (f32)D_80100C80_DeepSeaDivers[idx].unk20;
    D_80100C80_DeepSeaDivers[idx].x =
        x0 + ((D_80101780_DeepSeaDivers[D_80100C80_DeepSeaDivers[idx].target >> 8].boat->trans.x +
               D_80100C80_DeepSeaDivers[idx].unk26 * 5.0) -
              x0) *
                 (f32)((24.0 - (f32)D_80100C80_DeepSeaDivers[idx].timer) / 24.0);
    D_80100C80_DeepSeaDivers[idx].y =
        D_80100C80_DeepSeaDivers[idx].y + (f32)(D_80100C80_DeepSeaDivers[idx].unk1E / 16.0) * 5.0;
    D_80100C80_DeepSeaDivers[idx].unk1E -= 8;
    if (D_80100C80_DeepSeaDivers[idx].timer != 0) {
        D_80100C80_DeepSeaDivers[idx].timer--;
    }
    if (D_80100C80_DeepSeaDivers[idx].unk1E < 0 && D_80100C80_DeepSeaDivers[idx].y <= 675.0) {
        D_80100C80_DeepSeaDivers[idx].y = 675.0f;
        if (--D_80100C80_DeepSeaDivers[idx].unk22 == 0) {
            PlaySound(0xFC);
            func_800FD870_DeepSeaDivers(idx);
        }
        D_80100C80_DeepSeaDivers[idx].unk1E = D_80100C80_DeepSeaDivers[idx].unk24 =
            D_80100C80_DeepSeaDivers[idx].unk24 / 2;
        PlaySound(0x108);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FAC68_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800FB010_DeepSeaDivers(s16 idx) {
    if (D_80100C80_DeepSeaDivers[idx].flags >= 0) {
        D_80100C80_DeepSeaDivers[idx].flags |= 0x8000;
        D_80100C80_DeepSeaDivers[idx].timer = 60;
        D_80100C80_DeepSeaDivers[idx].y = 725.0f;
        func_80067208(D_80100C80_DeepSeaDivers[idx].sprite, 0, D_80101790_DeepSeaDivers[2], 0);
    }
    D_80100C80_DeepSeaDivers[idx].x = D_80101780_DeepSeaDivers[D_80100C80_DeepSeaDivers[idx].target].diver->trans.x;
    if (func_80067328(D_80100C80_DeepSeaDivers[idx].sprite, 0) & 2) {
        func_800FD870_DeepSeaDivers(idx);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FB010_DeepSeaDivers);
#endif
s16 func_800FB130_DeepSeaDivers(void) {
    DSDWork* w;
    s16 i;

    D_80100410_DeepSeaDivers = 0;
    D_80100438_DeepSeaDivers = 0;
    for (i = 0; i < D_801017A0_DeepSeaDivers; i++) {
        w = func_800FC1C8_DeepSeaDivers(D_80101BB0_DeepSeaDivers[i]);
        if (w->unk8 >= 0) {
            if (w->unk5E < 0) {
                D_80100418_DeepSeaDivers[D_80100410_DeepSeaDivers++] =
                    func_800FC1C8_DeepSeaDivers(D_80101BB0_DeepSeaDivers[i]);
            } else if (DSD_LO8(w->unk0) < 0) {
                D_80100440_DeepSeaDivers[D_80100438_DeepSeaDivers++] =
                    func_800FC1C8_DeepSeaDivers(D_80101780_DeepSeaDivers[w->unk5E].diver);
            }
        }
    }
    return -(D_80100410_DeepSeaDivers == 0);
}
#ifdef NON_MATCHING
s32 func_800FB27C_DeepSeaDivers(omObjData* obj) {
    DSDWork* w = func_800FC1C8_DeepSeaDivers(obj);
    s32 d = (s16)((DSDPlayerWork*)obj->unk_50)->unk_3C - w->unk42;

    if (d < 0) {
        d = -d;
    }
    return -((d % 360) > 90);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FB27C_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
s16 func_800FB310_DeepSeaDivers(omObjData* obj) {
    DSDWork* w;
    DSDWork* t;
    f32 dx;
    f32 dy;
    s16 best;
    s16 sel;
    s16 i;
    s16 btn = 0;

    w = func_800FC1C8_DeepSeaDivers(obj);
    if (w->unk2 & 4) {
        if (w->unk40 >= 0) {
            w->unk40 = -1;
        }
        w->unk42 = 0;
    } else if (w->unk2 & 0x40) {
        if (w->unk56 & 0x80) {
            switch (((w->unk42 + 45) % 360) / 90) {
                case 0:
                case 2:
                    if (obj->trans.x >= 0.0f) {
                        w->unk42 = (w->unk2 & 8) ? 45 : 90;
                    } else {
                        w->unk42 = (w->unk2 & 8) ? 270 : 315;
                    }
                    if (fabs(obj->trans.x) < 250.0) {
                        w->unk42 = -w->unk42;
                        if (w->unk42 < 0) {
                            w->unk42 += 360;
                        }
                    }
                    break;
                case 1:
                case 3:
                    if ((w->unk42 + 90) % 360 < 180) {
                        w->unk42 = 0;
                    } else {
                        w->unk42 = 180;
                    }
                    break;
            }
            w->unk56 &= 0x7F;
        }
        if (--w->unk56 == 0) {
            w->unk2 &= ~0x40;
        }
    } else if (w->unk2 & 8) {
        if (w->unk40 >= 0) {
            w->unk40 = -1;
        }
        w->unk42 = (s32)func_800B0CD8(D_80100478_DeepSeaDivers[w->unkC].top.x - obj->trans.x,
                                      -(D_80100478_DeepSeaDivers[w->unkC].top.y - obj->trans.y)) +
                   180;
    } else {
        if (w->unk40 < 0) {
            best = 0;
            if (D_80100410_DeepSeaDivers != 0) {
                sel = -1;
                for (i = 0; i < D_80100410_DeepSeaDivers; i++) {
                    /* a new best is always taken; a tie only on a coin flip */
                    if (best < D_80100418_DeepSeaDivers[i]->unk4E) {
                        best = D_80100418_DeepSeaDivers[i]->unk4E;
                        sel = i;
                    } else if (D_80100418_DeepSeaDivers[i]->unk4E == best && (func_800FC1F4_DeepSeaDivers() & 1)) {
                        best = D_80100418_DeepSeaDivers[i]->unk4E;
                        sel = i;
                    }
                }
                w->unk40 = D_80100418_DeepSeaDivers[sel]->unkA;
                w->unk2 |= 0x10;
            } else {
                w->unk40 =
                    D_80100440_DeepSeaDivers[(func_800FC1F4_DeepSeaDivers() * D_80100438_DeepSeaDivers) >> 16]->unkA;
                w->unk2 &= ~0x10;
            }
        }
        t = D_801017B0_DeepSeaDivers[w->unk40];
        if ((w->unk2 & 0x10) && t->unk5E >= 0 && t->unk5E != w->unkC) {
            w->unk40 = -1;
        } else {
            if (!(w->unk2 & 0x10) && D_80100410_DeepSeaDivers != 0) {
                w->unk40 = -1;
            }
            dx = t->unk10 - w->unk10;
            dy = t->unk14 - w->unk14;
            w->unk42 = (s32)func_800B0CD8(dx, -dy) + 180;
            if (sqrtf(dx * dx + dy * dy) < 80.0) {
                btn = 0x4000;
            }
        }
    }
    if ((s16)func_800FB27C_DeepSeaDivers(obj) == 0) {
        if ((u32)(func_800FC1F4_DeepSeaDivers() & 0xFF) < (u32)(GwPlayer[w->unk44].cpu_difficulty * 4 + 60)) {
            btn |= 0x8000;
        }
    }
    return btn;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FB310_DeepSeaDivers);
#endif
void func_800FB860_DeepSeaDivers(void) {
    CZoom = 21000.0f;
    CRot.x = 2.9249f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    Center.x = 0.0f;
    Center.y = -580.0f;
    Center.z = -110.0f;
}
#ifdef NON_MATCHING
void func_800FB8C8_DeepSeaDivers(Matrix4f m, f32 x, f32 y, f32 z, Vec* out) {
    f32* o = (f32*)out;

    *o++ = x * m[0][0] + y * m[1][0] + z * m[2][0] + m[3][0];
    o[0] = x * m[0][1] + y * m[1][1] + z * m[2][1] + m[3][1];
    o[1] = x * m[0][2] + y * m[1][2] + z * m[2][2] + m[3][2];
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FB8C8_DeepSeaDivers);
#endif
void func_800FB964_DeepSeaDivers(void) {
    D_801004B4_DeepSeaDivers = 0;
    D_801004B0_DeepSeaDivers = 0;
    D_801004B2_DeepSeaDivers = -1;
}
void func_800FB984_DeepSeaDivers(void) {
    Matrix4f m;
    Vec v;

    D_801004B0_DeepSeaDivers = 1;
    D_801004C4_DeepSeaDivers.x = D_801004EC_DeepSeaDivers.x = CRot.x;
    D_801004C4_DeepSeaDivers.y = D_801004EC_DeepSeaDivers.y = CRot.y;
    D_801004C4_DeepSeaDivers.z = D_801004EC_DeepSeaDivers.z = CRot.z;
    D_801004B8_DeepSeaDivers.x = D_801004E0_DeepSeaDivers.x = Center.x;
    D_801004B8_DeepSeaDivers.y = D_801004E0_DeepSeaDivers.y = Center.y;
    D_801004B8_DeepSeaDivers.z = D_801004E0_DeepSeaDivers.z = Center.z;
    D_801004D0_DeepSeaDivers = D_801004F8_DeepSeaDivers = CZoom;
    guTranslateF(m, Center.x, Center.y, Center.z);
    MtxRotate(m, CRot.x, CRot.y, CRot.z);
    func_800FB8C8_DeepSeaDivers(m, 0.0f, 0.0f, CZoom, &v);
    D_801004D4_DeepSeaDivers.x = D_801004FC_DeepSeaDivers.x = v.x;
    D_801004D4_DeepSeaDivers.y = D_801004FC_DeepSeaDivers.y = v.y;
    D_801004D4_DeepSeaDivers.z = D_801004FC_DeepSeaDivers.z = v.z;
}
void func_800FBABC_DeepSeaDivers(void) {
    D_801004B0_DeepSeaDivers = 0;
}
void func_800FBAC8_DeepSeaDivers(f32 x, f32 y, f32 z, f32 w) {
    if (D_801004B4_DeepSeaDivers < 16) {
        D_80100508_DeepSeaDivers[D_801004B4_DeepSeaDivers].x = x;
        D_80100508_DeepSeaDivers[D_801004B4_DeepSeaDivers].y = y;
        D_80100508_DeepSeaDivers[D_801004B4_DeepSeaDivers].z = z;
        D_80100508_DeepSeaDivers[D_801004B4_DeepSeaDivers].w = w;
        D_801004B4_DeepSeaDivers++;
    }
}
#ifdef NON_MATCHING
void func_800FBB30_DeepSeaDivers(void) {
    f32 hi[4];
    f32 lo[4];
    f32 mid[4];
    Vec eye;
    Matrix4f m;
    Vec unused;
    Vec r;
    f32 t;
    f32 dx;
    f32 dy;
    f32 d;
    f32 maxd;
    f32 lim;
    f64 f;
    s16 i;
    s16 k;

    for (i = 0; i < 3; i++) {
        hi[i] = -2000.0f;
        lo[i] = 2000.0f;
    }
    for (i = 0; i < D_801004B4_DeepSeaDivers; i++) {
        for (k = 0; k < 3; k++) {
            if (hi[k] < (&D_80100508_DeepSeaDivers[i].x)[k]) {
                hi[k] = (&D_80100508_DeepSeaDivers[i].x)[k];
            }
            if ((&D_80100508_DeepSeaDivers[i].x)[k] < lo[k]) {
                lo[k] = (&D_80100508_DeepSeaDivers[i].x)[k];
            }
        }
    }
    for (i = 0; i < 3; i++) {
        mid[i] = lo[i] + (hi[i] - lo[i]) * 0.5;
    }
    eye.x = D_801004D4_DeepSeaDivers.x;
    eye.y = D_801004D4_DeepSeaDivers.y;
    eye.z = D_801004D4_DeepSeaDivers.z;
    HuGuLookAtF(m, eye.x, eye.y, eye.z, mid[0], mid[1], mid[2], 0.0f, 1.0f, 0.0f);
    unused.x = unused.y = unused.z = 0.0f;
    maxd = 0.0f;
    t = func_800AEAC0(D_800C3110->unk_40 * 0.5);
    t = t / func_800AEFD0(D_800C3110->unk_40 * 0.5);
    for (i = 0; i < D_801004B4_DeepSeaDivers; i++) {
        func_800FB8C8_DeepSeaDivers(m, D_80100508_DeepSeaDivers[i].x - mid[0], D_80100508_DeepSeaDivers[i].y - mid[1],
                                    D_80100508_DeepSeaDivers[i].z - mid[2], &r);
        dx = (r.x < 0.0f) ? -r.x : r.x;
        dx = dx / t + r.z;
        dy = (r.y < 0.0f) ? -r.y : r.y;
        dy = (dy / t + r.z) * 1.3333334f;
        d = (dy <= dx) ? dx : dy;
        if (maxd < d) {
            maxd = d;
        }
    }
    maxd = maxd * 1.1111111111111112;
    if (maxd > 22000.0) {
        maxd = 22000.0f;
    }
    if (maxd < 7000.0) {
        maxd = 7000.0f;
    }
    CZoom = (maxd - CZoom) * D_80101798_DeepSeaDivers + CZoom;
    D_801004B4_DeepSeaDivers = 0;
    Center.x += (mid[0] - Center.x) * D_80101798_DeepSeaDivers;
    Center.y += (mid[1] - Center.y) * D_80101798_DeepSeaDivers;
    Center.z += (mid[2] - Center.z) * D_80101798_DeepSeaDivers;
    f = (f32)((CZoom - 11000.0) / 11000.0);
    if (f < 0.0) {
        f = 0.0f;
    }
    lim = 1860.0 - f * 1160.0;
    if (Center.x < -lim) {
        Center.x = -lim;
    }
    if (lim < Center.x) {
        Center.x = lim;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FBB30_DeepSeaDivers);
#endif
DSDWork* func_800FC058_DeepSeaDivers(omObjData* obj) {
    DSDWork* w = HuMemDirectMalloc(sizeof(DSDWork));

    D_801017B0_DeepSeaDivers[D_80101BD4_DeepSeaDivers] = w;
    obj->work[0] = (u32)w >> 24;
    obj->work[1] = (u32)w >> 16;
    obj->work[2] = (u32)w >> 8;
    obj->work[3] = (u32)w;
    w->unk0 = 0;
    w->unk2 = 0;
    w->unk8 = 0;
    w->unkA = D_80101BD4_DeepSeaDivers;
    w->unkC = 0;
    w->unk10 = w->unk14 = w->unk18 = 0.0f;
    w->unk1C = w->unk20 = w->unk24 = 0.0f;
    w->unk28 = w->unk2C = w->unk30 = 0.0f;
    w->unk40 = w->unk42 = w->unk44 = w->unk46 = 0;
    w->unk48 = w->unk4A = w->unk4C = w->unk4E = 0;
    w->unk50 = w->unk52 = w->unk54 = w->unk56 = 0;
    w->unk58 = w->unk5A = w->unk5C = w->unk5E = 0;
    D_80101BD4_DeepSeaDivers++;
    return w;
}
void func_800FC148_DeepSeaDivers(void) {
    s16 i;

    for (i = 0; i < D_80101BD4_DeepSeaDivers; i++) {
        if (D_801017B0_DeepSeaDivers[i] != NULL) {
            HuMemDirectFree(D_801017B0_DeepSeaDivers[i]);
        }
    }
}
DSDWork* func_800FC1C8_DeepSeaDivers(omObjData* obj) {
    return (DSDWork*)((obj->work[0] << 24) | (obj->work[1] << 16) | (obj->work[2] << 8) | obj->work[3]);
}
u32 func_800FC1F4_DeepSeaDivers(void) {
    u8 hi = rand8();

    return (hi << 8) | rand8();
}
void func_800FC22C_DeepSeaDivers(omObjData* unused, f32* x, f32* y, f32* z) {
    if (*x < -2000.0) {
        *x = -2000.0f;
    }
    if (*x > 2000.0) {
        *x = 2000.0f;
    }
    if (*y > 625.0) {
        *y = 625.0f;
    }
    if (*y < -2000.0) {
        *y = -2000.0f;
    }
}
void func_800FC2F8_DeepSeaDivers(f32* x, f32* y, f32 dist, Vec2f* pts, s16 n, u16 flag, f32* outx, f32* outy) {
    f32 sx;
    f32 sy;
    f32 px;
    f32 py;
    f32 a;
    f32 b;
    f32 dy;
    f32 len;
    f32 nx;
    f32 ny;
    s16 i;

    if (n >= 2) {
        sy = 0.0f;
        sx = 0.0f;
        for (i = 0; i < n; i++) {
            sx += pts[i].x;
            sy += pts[i].y;
        }
        sx /= n;
        sy /= n;
        px = pts[0].x;
        py = pts[0].y;
        ny = 0.0f;
        nx = 0.0f;
        for (i = 0; i < n - 1; i++) {
            dy = pts[i + 1].y - py;
            a = -dy;
            b = pts[i + 1].x - px;
            if (a * (*x - sx) + b * (*y - sy) < 0.0) {
                a = dy;
                b = -b;
            }
            len = sqrtf(a * a + b * b);
            if (len != 0.0) {
                a /= len;
                b /= len;
                nx += a;
                ny += b;
            }
            px = pts[i + 1].x;
            py = pts[i + 1].y;
        }
        if (flag != 0 && ny < 0.0) {
            nx = 2.0 * nx;
            len = sqrtf(nx * nx + ny * ny);
            nx = nx / len;
            ny /= len;
        }
        *outx = nx;
        *outy = ny;
        len = sqrtf(nx * nx + ny * ny);
        if (len != 0.0) {
            nx /= len;
            ny /= len;
            *x = sx + nx * dist;
            *y = sy + ny * dist;
        }
    }
}
#ifdef NON_MATCHING
s16 func_800FC644_DeepSeaDivers(f32* x, f32* y, s16 r, u16 flag, f32* outx, f32* outy) {
    Vec2f pts[256];
    Vec* line;
    f32 px;
    f32 py;
    f32 dx;
    f32 dy;
    f32 ox;
    f32 oy;
    f32 a;
    f32 b;
    f32 disc;
    f32 q;
    f32 t0;
    f32 t1;
    s32 rr;
    s16 n = 0;
    s16 total = 0;
    u16 i;
    s8 j;
    s8 k;

    px = *x;
    py = *y;
    rr = -(r * r);
    for (i = 0; i < 9; i++) {
        line = D_800FFC80_DeepSeaDivers[i];
        for (j = 0; j < D_800FFCA4_DeepSeaDivers[i]; j++) {
            k = (j + 1 < D_800FFCA4_DeepSeaDivers[i]) ? j + 1 : 0;
            dx = (line[k].x - line[j].x) * 5.0;
            dy = (line[k].y - line[j].y) * 5.0;
            ox = line[j].x * 5.0 - px;
            oy = line[j].y * 5.0 - py;
            a = dx * dx + dy * dy;
            b = 2.0f * (dx * ox + dy * oy);
            disc = b * b - a * 4.0 * ((f32)rr + ox * ox + oy * oy);
            if (disc > 0.0f) {
                q = sqrtf(disc);
                t0 = (-b - q) / (2.0f * a);
                t1 = (-b + q) / (2.0f * a);
                if (t0 >= 0.0 && t0 <= 1.0) {
                    pts[n].x = line[j].x * 5.0 + t0 * dx;
                    pts[n].y = line[j].y * 5.0 + t0 * dy;
                    n++;
                    total++;
                }
                if (0.0 <= t1 && t1 <= 1.0) {
                    pts[n].x = line[j].x * 5.0 + t1 * dx;
                    pts[n].y = line[j].y * 5.0 + t1 * dy;
                    n++;
                    total++;
                }
            }
        }
        if (n >= 2) {
            func_800FC2F8_DeepSeaDivers(x, y, r, pts, n, flag, outx, outy);
            n -= 2;
        }
    }
    return total;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FC644_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
f32 func_800FCAE8_DeepSeaDivers(f32 x, f32 y) {
    Vec* pts;
    Vec* a;
    Vec* b;
    f32 best = -9999.0f;
    f32 h;
    s32 found = 0;
    u16 i;
    s8 j;
    s8 k;

    for (i = 0; i < 9; i++) {
        pts = D_800FFC80_DeepSeaDivers[i];
        for (j = 0; j < D_800FFCA4_DeepSeaDivers[i]; j++) {
            k = (j + 1 < D_800FFCA4_DeepSeaDivers[i]) ? j + 1 : 0;
            if ((pts[j].x * 5.0 <= x && x < pts[k].x * 5.0) || (x < pts[j].x * 5.0 && pts[k].x * 5.0 <= x)) {
                a = &pts[j];
                b = &pts[k];
                if (b->x - a->x != 0.0) {
                    h = a->y * 5.0 + (f32)((x - a->x * 5.0) / (b->x - a->x * 5.0)) * (b->y - a->y) * 5.0;
                    if (((b->x - a->x >= 0.0f) & (h <= y)) && best < h) {
                        best = h;
                        found = 1;
                    }
                }
            }
        }
    }
    if (found == 0) {
        best = -2000.0f;
    }
    return best;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FCAE8_DeepSeaDivers);
#endif
s16 func_800FCDC8_DeepSeaDivers(f32 x, f32 y, f32 w, f32 h) {
    omObjData* obj;
    DSDWork* dw;
    f64 dx;
    f64 dy;
    f32 d;
    s16 ret = -1;
    f32 best = 999.0f;
    s16 i;

    for (i = 0; i < D_801017A0_DeepSeaDivers; i++) {
        obj = D_80101BB0_DeepSeaDivers[i];
        dw = func_800FC1C8_DeepSeaDivers(obj);
        if (DSD_LO8(dw->unk0) < 0 && dw->unk5E < 0) {
            dx = fabs(obj->trans.x - x);
            if (dx < (f32)dw->unk4 + w) {
                dy = fabs(obj->trans.y - y);
                if (dy < (f32)dw->unk6 + h) {
                    d = dx + dy;
                    if (d < best) {
                        best = d;
                        ret = i;
                    }
                }
            }
        }
    }
    return ret;
}
#ifdef NON_MATCHING
void func_800FCF54_DeepSeaDivers(omObjData* obj, f32 vx, f32 vy) {
    omObjData* o;
    DSDWork* w;
    DSDWork* ow;
    f32 r;
    f32 orad;
    f32 dx;
    f32 dy;
    f32 d;
    f32 push;
    f32 nx = 0.0f;
    f32 ny = 0.0f;
    s16 i;

    w = func_800FC1C8_DeepSeaDivers(obj);
    r = (w->unk6 < w->unk4) ? w->unk4 : w->unk6;
    for (i = 0; i < D_80100C70_DeepSeaDivers[2]; i++) {
        o = D_80101780_DeepSeaDivers[i].diver;
        ow = func_800FC1C8_DeepSeaDivers(o);
        if (obj != o && ow->unk8 >= 0) {
            dx = o->trans.x - obj->trans.x;
            dy = o->trans.y - obj->trans.y;
            orad = (ow->unk6 < ow->unk4) ? ow->unk4 : ow->unk6;
            d = sqrtf(dx * dx + dy * dy);
            if (d < r + orad) {
                if (d != 0.0) {
                    dx /= d;
                    dy /= d;
                }
                push = r + orad - d;
                if (dx != 0.0 && dy != 0.0) {
                    nx = dy;
                    ny = -dx;
                    if (nx * vx + ny * vy < 0.0f) {
                        nx = -nx;
                        ny = dx;
                    }
                } else {
                    if (dx == 0.0) {
                        nx = 0.0f;
                        ny = -dy;
                    }
                    if (dy == 0.0) {
                        ny = 0.0f;
                        nx = -dx;
                    }
                }
                obj->trans.x = (obj->trans.x - dx * push) + nx * push * 0.5;
                obj->trans.y = (obj->trans.y - dy * push) + ny * push * 0.5;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FCF54_DeepSeaDivers);
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", D_80100268_DeepSeaDivers);
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", D_8010026C_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
s16 func_800FD28C_DeepSeaDivers(omObjData* obj) {
    omObjData* o;
    f32 d;
    s16 hit = 0;
    s16 i;

    for (i = 0; i < D_80100C70_DeepSeaDivers[1]; i++) {
        o = D_80101780_DeepSeaDivers[i].boat;
        if (obj != o) {
            d = fabsf(o->trans.x - obj->trans.x);
            if (d < 270.0) {
                if (!(o->trans.x < obj->trans.x)) {
                    o->trans.x = o->trans.x + (270.0 - d);
                    hit = 1;
                    if (o->trans.x > 2000.0) {
                        o->trans.x = 2000.0f;
                        obj->trans.x = 1730.0f;
                    }
                } else {
                    o->trans.x = o->trans.x - (270.0 - d);
                    hit = 1;
                    if (o->trans.x < -2000.0) {
                        o->trans.x = -2000.0f;
                        obj->trans.x = -1730.0f;
                    }
                }
            }
        }
    }
    if (obj->trans.x < -2000.0) {
        obj->trans.x = -2000.0f;
    }
    if (obj->trans.x > 2000.0) {
        obj->trans.x = 2000.0f;
    }
    return hit;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FD28C_DeepSeaDivers);
#endif
s16 func_800FD450_DeepSeaDivers(s32 file) {
    void* data = DataRead(file);
    s16 ret = func_800678A4(data);

    DataClose(data);
    return ret & 0xFF;
}
#ifdef NON_MATCHING
void func_800FD494_DeepSeaDivers(void) {
    s16 i;

    D_80101790_DeepSeaDivers[0] = func_800FD450_DeepSeaDivers(0x160010);
    D_80101790_DeepSeaDivers[1] = func_800FD450_DeepSeaDivers(0x21);
    D_80101790_DeepSeaDivers[2] = func_800FD450_DeepSeaDivers(0x440008);
    D_80100C70_DeepSeaDivers[0] = func_800FD450_DeepSeaDivers(0x440006);
    D_8010179E_DeepSeaDivers = func_80064EF4(1, 0);
    func_80067208(D_8010179E_DeepSeaDivers, 0, D_80100C70_DeepSeaDivers[0], 0);
    func_800674BC(D_8010179E_DeepSeaDivers, 0, 0x4000);
    func_80066DC4(D_8010179E_DeepSeaDivers, 0, 160, 64);
    func_80067354(D_8010179E_DeepSeaDivers, 0, 2.0f, 1.0f);
    for (i = 0; i < 64; i++) {
        D_80100C80_DeepSeaDivers[i].flags = 0;
        D_80100C80_DeepSeaDivers[i].type = 0;
        D_80100C80_DeepSeaDivers[i].sprite = func_80064EF4(1, 0);
        func_80067480(D_80100C80_DeepSeaDivers[i].sprite, 0, -1);
        func_800674BC(D_80100C80_DeepSeaDivers[i].sprite, 0, 0xC000);
        D_80100C80_DeepSeaDivers[i].target = 0;
        D_80100C80_DeepSeaDivers[i].x = 0.0f;
        D_80100C80_DeepSeaDivers[i].y = 0.0f;
        D_80100C80_DeepSeaDivers[i].z = 0.0f;
        D_80100C80_DeepSeaDivers[i].unk1E = D_80100C80_DeepSeaDivers[i].unk20 = D_80100C80_DeepSeaDivers[i].unk22 = 0;
        D_80100C80_DeepSeaDivers[i].timer = 0;
        D_80100C80_DeepSeaDivers[i].unk26 = D_80100C80_DeepSeaDivers[i].unk28 = D_80100C80_DeepSeaDivers[i].unk2A = 0;
        D_80100C80_DeepSeaDivers[i].unk24 = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FD494_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
s16 func_800FD680_DeepSeaDivers(s16 type, f32 x, f32 y, f32 z, s16 target) {
    s16 i;

    for (i = 0; i < 64; i++) {
        if (D_80100C80_DeepSeaDivers[i].flags == 0) {
            D_80100C80_DeepSeaDivers[i].flags = 1;
            D_80100C80_DeepSeaDivers[i].type = type;
            D_80100C80_DeepSeaDivers[i].target = target;
            D_80100C80_DeepSeaDivers[i].x = x;
            D_80100C80_DeepSeaDivers[i].y = y;
            D_80100C80_DeepSeaDivers[i].z = z;
            D_80100C80_DeepSeaDivers[i].sx = 1.0f;
            D_80100C80_DeepSeaDivers[i].sy = 1.0f;
            if (D_80100C80_DeepSeaDivers[i].sprite >= 0) {
                func_8006752C(D_80100C80_DeepSeaDivers[i].sprite, 0, 0x100);
                func_80067480(D_80100C80_DeepSeaDivers[i].sprite, 0, 0xFFFF);
                func_800674BC(D_80100C80_DeepSeaDivers[i].sprite, 0, 0x1000);
                func_80067354(D_80100C80_DeepSeaDivers[i].sprite, 0, 1.0f, 1.0f);
                func_800672B0(D_80100C80_DeepSeaDivers[i].sprite, 0, 1);
                func_80067384(D_80100C80_DeepSeaDivers[i].sprite, 0, 0x8000);
            }
            D_80100C80_DeepSeaDivers[i].unk1E = D_80100C80_DeepSeaDivers[i].unk20 = D_80100C80_DeepSeaDivers[i].unk22 = 0;
            D_80100C80_DeepSeaDivers[i].timer = 0;
            D_80100C80_DeepSeaDivers[i].unk26 = D_80100C80_DeepSeaDivers[i].unk28 = D_80100C80_DeepSeaDivers[i].unk2A = 0;
            D_80100C80_DeepSeaDivers[i].unk24 = 0;
            return i;
        }
    }
    return -1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FD680_DeepSeaDivers);
#endif
void func_800FD870_DeepSeaDivers(s16 idx) {
    D_80100C80_DeepSeaDivers[idx].flags = 0;
    if (D_80100C80_DeepSeaDivers[idx].sprite >= 0) {
        func_800674BC(D_80100C80_DeepSeaDivers[idx].sprite, 0, 0x8000);
    }
}
#ifdef NON_MATCHING
void func_800FD8C8_DeepSeaDivers(void) {
    Vec3f p;
    Vec2f s;
    unk65770Obj* o;
    s16 i;

    omOutView(NULL);
    for (i = 0; i < 64; i++) {
        if (D_80100C80_DeepSeaDivers[i].flags != 0) {
            switch (D_80100C80_DeepSeaDivers[i].type) {
                case 0:
                    func_800FA62C_DeepSeaDivers(i);
                    break;
                case 1:
                    func_800FA9A4_DeepSeaDivers(i);
                    break;
                case 2:
                    func_800FAABC_DeepSeaDivers(i);
                    break;
                case 3:
                    func_800FAC68_DeepSeaDivers(i);
                    break;
                case 4:
                    func_800FB010_DeepSeaDivers(i);
                    break;
            }
            if (D_80100C80_DeepSeaDivers[i].flags != 0 && D_80100C80_DeepSeaDivers[i].sprite >= 0) {
                o = func_800675F4(D_80100C80_DeepSeaDivers[i].sprite, 0);
                if (DSD_LO8(D_80100C80_DeepSeaDivers[i].flags) < 0) {
                    func_80066DF4(D_80100C80_DeepSeaDivers[i].sprite, 0, 0, D_80100C80_DeepSeaDivers[i].x, D_80100C80_DeepSeaDivers[i].y, D_80100C80_DeepSeaDivers[i].z);
                } else {
                    func_800670C4(D_80100C80_DeepSeaDivers[i].sprite, 0, 0, D_80100C80_DeepSeaDivers[i].x, D_80100C80_DeepSeaDivers[i].y, D_80100C80_DeepSeaDivers[i].z);
                    o->unk14 *= D_80100C80_DeepSeaDivers[i].sx * 4.0;
                    o->unk18 *= D_80100C80_DeepSeaDivers[i].sy * 4.0;
                }
            }
        }
    }
    o = func_800675F4(D_8010179E_DeepSeaDivers, 0);
    p.x = 0.0f;
    p.y = 625.0f;
    p.z = 0.0f;
    Convert3DTo2D(0, &p, &s);
    o->unk42 = s.y;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FD8C8_DeepSeaDivers);
#endif
void func_800FDBA0_DeepSeaDivers(void) {
    func_800FDBC4_DeepSeaDivers();
}
void func_800FDBBC_DeepSeaDivers(void) {
}

void func_800FDBC4_DeepSeaDivers(void) {
    func_8009B770(D_80100610_DeepSeaDivers, 0, sizeof(D_80100610_DeepSeaDivers));
}
s16 func_800FDBEC_DeepSeaDivers(void) {
    DSDRope* r;
    DSDRopeNode* node;
    s32 j;
    s32 k;
    f32 len;
    u8 hi;
    s16 i;

    for (i = 0; i < 4; i++) {
        if (D_80100610_DeepSeaDivers[i].active == 0) {
            break;
        }
    }
    if (i >= 4) {
        return -1;
    }
    r = &D_80100610_DeepSeaDivers[i];
    r->model = func_800FE2C0_DeepSeaDivers(i);
    r->nodes = func_80023668(5 * sizeof(DSDRopeNode));
    r->active = 1;
    hi = rand8();
    r->unk6 = ((hi << 8) | rand8()) / 2048;
    r->n = 1;
    r->unk8 = 600.0f;
    r->unk10 = 1.0f;
    node = r->nodes;
    func_8009B770(node, 0, 5 * sizeof(DSDRopeNode));
    for (j = 0; j < 5; j++) {
        node->unk2 = j;
        node++;
    }
    len = 0.0f;
    for (j = r->n, k = 0; j >= 0; j--, k++) {
        node = &r->nodes[j];
        node->unk0 = 1;
        if (k != 0) {
            node->unk4 = 200.0f;
        }
        len -= node->unk4;
        node->pos.y = len;
    }
    return i;
}
void func_800FDD84_DeepSeaDivers(s16 idx) {
    DSDRope* r;

    if (idx >= 0) {
        r = &D_80100610_DeepSeaDivers[idx];
        if (r->active != 0) {
            r->active = 0;
            if (r->nodes != NULL) {
                func_80023728(r->nodes);
            }
            r->nodes = NULL;
            if (r->model != 0) {
                func_8002456C(r->model);
            }
            r->model = 0;
        }
    }
}
void func_800FDE04_DeepSeaDivers(s16 idx, f32 speed, Vec* top) {
    DSDRope* r = &D_80100610_DeepSeaDivers[idx];

    r->unkC = speed;
    r->top.x = top->x;
    r->top.y = top->y;
    r->top.z = top->z;
}
#ifdef NON_MATCHING
void func_800FDE44_DeepSeaDivers(s16 idx, Vec* bottom, Vec* out) {
    DSDRope* r = &D_80100610_DeepSeaDivers[idx];
    DSDRopeNode* first;
    DSDRopeNode* last;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dist;
    f32 cur;
    f32 slack;
    f32 len;
    f32 want;
    f32 t;

    r->bottom.x = bottom->x;
    r->bottom.y = bottom->y;
    r->bottom.z = bottom->z;
    dx = r->top.x - r->bottom.x;
    dy = r->top.y - r->bottom.y;
    dz = r->top.z - r->bottom.z;
    dist = sqrtf(dx * dx + dy * dy + dz * dz);
    first = r->nodes;
    dx = r->top.x - first->pos.x;
    dy = r->top.y - first->pos.y;
    dz = r->top.z - first->pos.z;
    cur = sqrtf(dx * dx + dy * dy + dz * dz);
    last = &first[r->n];
    slack = dist - cur;
    if (slack < 0.0) {
        slack = 0.0f;
    }
    len = r->unk8 - r->unkC;
    if (len < 200.0) {
        len = 200.0f;
    }
    r->unk8 = len;
    if (len < dist) {
        r->unk8 = want = slack + len;
    } else {
        want = dist;
    }
    if (r->unkC != 0.0f && r->unk8 < dist + 10.0) {
        r->unk10 -= 0.05;
        if (r->unk10 < 0.0) {
            r->unk10 = 0.0f;
        }
    } else {
        r->unk10 += 0.05;
        if (r->unk10 > 1.0) {
            r->unk10 = 1.0f;
        }
    }
    t = 1.0 / dist * want;
    first->pos.x = r->bottom.x = (r->bottom.x - r->top.x) * t + r->top.x;
    first->pos.y = r->bottom.y = (r->bottom.y - r->top.y) * t + r->top.y;
    first->pos.z = r->bottom.z = (r->bottom.z - r->top.z) * t + r->top.z;
    last->pos.x = r->top.x;
    last->pos.y = r->top.y;
    last->pos.z = r->top.z;
    out->x = first->pos.x;
    out->y = first->pos.y;
    out->z = first->pos.z;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FDE44_DeepSeaDivers);
#endif
void func_800FE170_DeepSeaDivers(s16 idx, Vec* top, Vec* bottom) {
    DSDRope* r = &D_80100610_DeepSeaDivers[idx];
    DSDRopeNode* first = r->nodes;
    DSDRopeNode* last = &r->nodes[r->n];
    f32 dist;
    f32 d;

    d = top->x - bottom->x;
    dist = d * d;
    d = top->y - bottom->y;
    dist += d * d;
    d = top->z - bottom->z;
    dist += d * d;
    dist = sqrtf(dist);
    if (r->unk8 < dist) {
        r->unk8 = dist;
    }
    r->top.x = last->pos.x = top->x;
    r->top.y = last->pos.y = top->y;
    r->top.z = last->pos.z = top->z;
    r->bottom.x = first->pos.x = bottom->x;
    r->bottom.y = first->pos.y = bottom->y;
    r->bottom.z = first->pos.z = bottom->z;
    r->unk6++;
    if (r->unk6 >= 0x7000) {
        r->unk6 -= 0x800;
    }
}
s16 func_800FE2C0_DeepSeaDivers(s16 idx) {
    unk2C0C0StructC0* m;
    s32 model;
    s32 i;

    model = func_8002451C(0x1080, func_800FE378_DeepSeaDivers, 2);
    m = D_800F2B7C[model].unk_6C;
    for (i = 0; i < D_800F37DA; i++) {
        m->unk_08[i] = func_80023684(40 * sizeof(Vtx), m->unk_68);
        func_8009B770(m->unk_08[i], 0, 40 * sizeof(Vtx));
    }
    return model;
}
#ifdef NON_MATCHING
void func_800FE378_DeepSeaDivers(Gfx** gfx) {
    DSDRope* r;
    DSDRopeNode* first;
    DSDRopeNode* last;
    Vtx* v;
    f32 p[9];
    Vec mid;
    Vec d;
    f32 sag;
    f32 len;
    f32 s;
    f32 t;
    f32 u;
    f32 a;
    f32 b;
    f32 c;
    f32 ang;
    f32 amp;
    s32 col;
    s32 i;
    s32 k;

    for (i = 0; i < 4; i++) {
        if (D_80100610_DeepSeaDivers[i].model == D_800ED728) {
            break;
        }
    }
    if (i < 4) {
        r = &D_80100610_DeepSeaDivers[i];
        if (!(r->active & 0x80)) {
            r->active |= 0x80;
        }
        gSPDisplayList((*gfx)++, osVirtualToPhysical(D_800FFDD0_DeepSeaDivers));
        func_8001D658(0, gfx);
        gSPDisplayList((*gfx)++, osVirtualToPhysical(D_800FFE10_DeepSeaDivers));
        first = r->nodes;
        last = &first[r->n];
        v = (Vtx*)D_800F2B7C[D_800ED728].unk_6C->unk_08[D_800F37F0];
        d.x = last->pos.x - first->pos.x;
        d.y = last->pos.y - first->pos.y;
        d.z = last->pos.z - first->pos.z;
        sag = (-func_800AEAC0(func_800B0CD8(d.y, sqrtf(d.x * d.x + d.z * d.z))) + 1.0) * 0.5;
        mid.x = sag * d.x + first->pos.x;
        mid.y = sag * d.y + first->pos.y;
        len = sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
        mid.z = sag * d.z + first->pos.z;
        s = r->unk8 - len;
        if (s < 0.0) {
            s = 0.0f;
        }
        mid.y = mid.y - s - 50.0;
        gSPSegment((*gfx)++, 1, osVirtualToPhysical(v));
        gSPVertex((*gfx)++, 0x01000000, 17, 0);
        p[0] = (first->pos.x - mid.x) + first->pos.x;
        p[1] = (first->pos.y - mid.y) + first->pos.y;
        p[2] = (first->pos.z - mid.z) + first->pos.z;
        p[3] = mid.x;
        p[4] = mid.y;
        p[5] = mid.z;
        p[6] = (last->pos.x - mid.x) + last->pos.x;
        p[7] = (last->pos.y - mid.y) + last->pos.y;
        p[8] = (last->pos.z - mid.z) + last->pos.z;
        t = 0.0f;
        ang = (r->unk6 & 0x7F) * 360.0 / 128.0;
        for (i = 0; i < 17; i++) {
            u = 1.0 - t;
            a = u * u * 0.5;
            b = u * t + 0.5;
            c = t * t * 0.5;
            for (k = 0; k < 3; k++) {
                v->v.ob[k] = a * p[k] + b * p[k + 3] + c * p[k + 6];
                if (k == 0) {
                    amp = func_800AEAC0(i * 180.0 / 16.0) * (r->unk8 / 3000.0);
                    v->v.ob[0] = v->v.ob[0] + func_800AEAC0(ang) * 100.0 * amp * r->unk10;
                }
            }
            col = 0xFF;
            if (v->v.ob[1] < 1250) {
                if (func_800AEAC0(ang) < 0.0f) {
                    s = -func_800AEAC0(ang);
                } else {
                    s = func_800AEAC0(ang);
                }
                col = (1.0 - s) * 127.0;
                if (col < 72) {
                    col = (s32)(col * 0.25 + 24.0) - 128;
                } else {
                    col = col - 128;
                }
            }
            v->v.cn[0] = v->v.cn[1] = col;
            v->v.cn[3] = 0xFF;
            v->v.cn[2] = 0xFF;
            v++;
            t = t + 0.0625;
            ang = ang + 15.0;
            if (i < 16) {
                gSPLine3D((*gfx)++, i, i + 1, 0);
            }
        }
        gDPPipeSync((*gfx)++);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FE378_DeepSeaDivers);
#endif
void func_800FEA00_DeepSeaDivers(omObjData* obj) {
    s16 i;

    for (i = 0; i < 5; i++) {
        obj->model[i + 1] = func_80023FC8(obj->model[0]);
    }
    func_800258EC(obj->model[2], 4, 4);
    func_800258EC(obj->model[5], 4, 4);
    for (i = 0; i < 2; i++) {
        func_800FED88_DeepSeaDivers(obj, i);
    }
    D_80100C50_DeepSeaDivers = 0;
}
#ifdef NON_MATCHING
void func_800FEAC4_DeepSeaDivers(s16 idx, s16 dir) {
    if (dir != 0) {
        D_801006D8_DeepSeaDivers[idx].pos.x = 2990.0f;
        D_801006D8_DeepSeaDivers[idx].vx =
            -((f32)(((u32)(func_800FC1F4_DeepSeaDivers() * 5) >> 16) + 8) + D_80100C54_DeepSeaDivers[idx] * 10.0f);
        D_801006D8_DeepSeaDivers[idx].rot.y = 0.0f;
    } else {
        D_801006D8_DeepSeaDivers[idx].pos.x = -2990.0f;
        D_801006D8_DeepSeaDivers[idx].vx =
            (f32)(((u32)(func_800FC1F4_DeepSeaDivers() * 5) >> 16) + 8) + D_80100C54_DeepSeaDivers[idx] * 10.0f;
        D_801006D8_DeepSeaDivers[idx].rot.y = 180.0f;
    }
    D_801006D8_DeepSeaDivers[idx].pos.y = 550.0f - (f32)((u32)(func_800FC1F4_DeepSeaDivers() * 1650) >> 16) - 100.0;
    D_80100C54_DeepSeaDivers[idx] = (f32)(((u32)(func_800FC1F4_DeepSeaDivers() * 3) >> 16) + 5) / 10.0f * 1.5;
    D_801006D8_DeepSeaDivers[idx].pos.z = -50.0 - D_80100C54_DeepSeaDivers[idx] * 50.0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FEAC4_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800FED88_DeepSeaDivers(omObjData* obj, s16 idx) {
    s16 j;

    func_800FEAC4_DeepSeaDivers(idx, idx);
    D_801006D8_DeepSeaDivers[idx].rot.z = 0.0f;
    D_801006D8_DeepSeaDivers[idx].rot.x = 0.0f;
    for (j = 0; j < 10; j++) {
        D_80100758_DeepSeaDivers[idx][j].pos.x = D_801006D8_DeepSeaDivers[idx].pos.x;
        D_80100758_DeepSeaDivers[idx][j].pos.y = D_801006D8_DeepSeaDivers[idx].pos.y;
        D_80100758_DeepSeaDivers[idx][j].pos.z = D_801006D8_DeepSeaDivers[idx].pos.z;
        D_80100758_DeepSeaDivers[idx][j].rot.x = D_801006D8_DeepSeaDivers[idx].rot.x;
        D_80100758_DeepSeaDivers[idx][j].rot.y = D_801006D8_DeepSeaDivers[idx].rot.y;
        D_80100758_DeepSeaDivers[idx][j].rot.z = D_801006D8_DeepSeaDivers[idx].rot.z;
    }
    if ((u32)(func_800FC1F4_DeepSeaDivers() * 2) >> 16) {
        func_800258EC(obj->model[idx * 3 + 2], 4, 0);
    } else {
        func_800258EC(obj->model[idx * 3 + 2], 4, 4);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FED88_DeepSeaDivers);
#endif
#ifdef NON_MATCHING
void func_800FEF34_DeepSeaDivers(omObjData* obj) {
    DSDFish* t;
    s16 i;
    s16 j;
    s16 k;
    s16 n;

    for (i = 0; i < 2; i++) {
        if ((f32)D_800FFE6C_DeepSeaDivers[i] < D_801006D8_DeepSeaDivers[i].vx) {
            D_800FFE6C_DeepSeaDivers[i]++;
        }
        if (D_801006D8_DeepSeaDivers[i].vx < (f32)D_800FFE6C_DeepSeaDivers[i]) {
            D_800FFE6C_DeepSeaDivers[i]--;
        }
        t = &D_80100758_DeepSeaDivers[i][D_80100C50_DeepSeaDivers];
        t->pos.x = D_801006D8_DeepSeaDivers[i].pos.x;
        t->pos.y = D_801006D8_DeepSeaDivers[i].pos.y;
        t->pos.z = D_801006D8_DeepSeaDivers[i].pos.z;
        t->rot.y = D_801006D8_DeepSeaDivers[i].rot.y;
        t->rot.z = D_801006D8_DeepSeaDivers[i].rot.z;
        D_800FFE60_DeepSeaDivers[i] += 2 + ((u32)(func_800FC1F4_DeepSeaDivers() * 3) >> 16);
        if (D_800FFE60_DeepSeaDivers[i] >= 361) {
            D_800FFE60_DeepSeaDivers[i] = 0;
        }
        D_801006D8_DeepSeaDivers[i].pos.x =
            (func_800AEAC0(D_800FFE60_DeepSeaDivers[i]) + 1.0f) * D_801006D8_DeepSeaDivers[i].vx +
            D_801006D8_DeepSeaDivers[i].pos.x;
        if (D_800FFE60_DeepSeaDivers[i] < 180) {
            D_801006D8_DeepSeaDivers[i].pos.y = D_801006D8_DeepSeaDivers[i].pos.y + 3.0f;
        } else {
            D_801006D8_DeepSeaDivers[i].pos.y = D_801006D8_DeepSeaDivers[i].pos.y - 3.0f;
        }
        if ((D_800FFE60_DeepSeaDivers[i] == 180) | (D_800FFE60_DeepSeaDivers[i] == 0)) {
            func_800FC1F4_DeepSeaDivers();
        }
        if (D_801006D8_DeepSeaDivers[i].pos.y > 550.0f) {
            D_801006D8_DeepSeaDivers[i].pos.y = 540.0f;
        } else if (D_801006D8_DeepSeaDivers[i].pos.y < -1200.0f) {
            D_801006D8_DeepSeaDivers[i].pos.y = -1190.0f;
        }
        if (D_801006D8_DeepSeaDivers[i].pos.x > 3000.0f || D_801006D8_DeepSeaDivers[i].pos.x < -3000.0f) {
            func_800FEAC4_DeepSeaDivers(i, (s32)(func_800FC1F4_DeepSeaDivers() * 2) >> 16);
            if (((u32)(func_800FC1F4_DeepSeaDivers() * 2) >> 16) == 0) {
                func_800258EC(obj->model[i * 3 + 2], 4, 0);
            } else {
                func_800258EC(obj->model[i * 3 + 2], 4, 4);
            }
        }
        if (i == 0) {
            obj->scale.x = D_80100C54_DeepSeaDivers[0];
            obj->scale.y = D_80100C54_DeepSeaDivers[0];
            obj->scale.z = D_80100C54_DeepSeaDivers[0];
            obj->rot.x = D_801006D8_DeepSeaDivers[0].rot.x;
            obj->rot.y = D_801006D8_DeepSeaDivers[0].rot.y;
            obj->rot.z = D_801006D8_DeepSeaDivers[0].rot.z;
            obj->trans.x = D_801006D8_DeepSeaDivers[0].pos.x;
            obj->trans.y = D_801006D8_DeepSeaDivers[0].pos.y;
            obj->trans.z = D_801006D8_DeepSeaDivers[0].pos.z;
        } else {
            func_80025830(obj->model[i * 3], D_80100C54_DeepSeaDivers[i], D_80100C54_DeepSeaDivers[i],
                          D_80100C54_DeepSeaDivers[i]);
            func_800257E4(obj->model[i * 3], D_801006D8_DeepSeaDivers[i].rot.x, D_801006D8_DeepSeaDivers[i].rot.y,
                          D_801006D8_DeepSeaDivers[i].rot.z);
            func_80025798(obj->model[i * 3], D_801006D8_DeepSeaDivers[i].pos.x, D_801006D8_DeepSeaDivers[i].pos.y,
                          D_801006D8_DeepSeaDivers[i].pos.z);
        }
    }
    if (++D_80100C50_DeepSeaDivers >= 10) {
        D_80100C50_DeepSeaDivers = 0;
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            k = j + (i * 3 + 1);
            if (j == 0) {
                n = D_80100C50_DeepSeaDivers - 5;
            } else {
                n = D_80100C50_DeepSeaDivers - 7;
            }
            if (n < 0) {
                n += 10;
            }
            func_80025830(obj->model[k], D_80100C54_DeepSeaDivers[i], D_80100C54_DeepSeaDivers[i],
                          D_80100C54_DeepSeaDivers[i]);
            func_800257E4(obj->model[k], D_80100758_DeepSeaDivers[i][n].rot.x, D_80100758_DeepSeaDivers[i][n].rot.y,
                          D_80100758_DeepSeaDivers[i][n].rot.z);
            if (j == 0) {
                func_80025798(obj->model[k], (f32)(D_800FFE6C_DeepSeaDivers[i] * 3) + D_80100758_DeepSeaDivers[i][n].pos.x,
                              (f32)(D_800FFE6C_DeepSeaDivers[i] * 3) + D_80100758_DeepSeaDivers[i][n].pos.y,
                              (f32)(D_800FFE6C_DeepSeaDivers[i] * 3) + D_80100758_DeepSeaDivers[i][n].pos.z);
            } else {
                func_80025798(obj->model[k], D_80100758_DeepSeaDivers[i][n].pos.x - (f32)(D_800FFE6C_DeepSeaDivers[i] * 3),
                              D_80100758_DeepSeaDivers[i][n].pos.y - (f32)(D_800FFE6C_DeepSeaDivers[i] * 3),
                              D_80100758_DeepSeaDivers[i][n].pos.z - (f32)(D_800FFE6C_DeepSeaDivers[i] * 3));
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FEF34_DeepSeaDivers);
#endif
void func_800FF6E0_DeepSeaDivers(omObjData* obj) {
    func_80026040(obj->model[1]);
    D_80100C5C_DeepSeaDivers = 0.0f;
    func_80039C48("dmy_I8", &D_80100C60_DeepSeaDivers);
    D_80100C64_DeepSeaDivers = D_80100C68_DeepSeaDivers = 0.0f;
}
#ifdef NON_MATCHING
void func_800FF730_DeepSeaDivers(omObjData* obj) {
    unk2C0C0StructC0* m;
    unk2C0C0StructE0* src;
    unk2C0C0StructE0* dst;
    s16 flip = 0;
    s16 row = 0;
    s32 i;

    m = D_800F2B7C[obj->model[1]].unk_6C;
    D_80100C64_DeepSeaDivers -= 0.1f;
    func_80027E48(obj->model[1], D_80100C64_DeepSeaDivers, D_80100C68_DeepSeaDivers, D_80100C60_DeepSeaDivers[0],
                  D_80100C60_DeepSeaDivers[1], "yura_1_1", 1);
    src = m->unk_04;
    dst = m->unk_08[D_800F37F0];
    for (i = 0; i < m->unk_72; i++) {
        if (!(i & 3)) {
            flip = row ^ 1;
            if (!(i & 4)) {
                flip = row;
            }
        }
        if (flip == 0) {
            dst->unk_00 = src->unk_00 + func_800AEAC0(D_80100C5C_DeepSeaDivers) * 40.0;
        } else {
            dst->unk_00 = src->unk_00 - func_800AEAC0(D_80100C5C_DeepSeaDivers) * 40.0;
        }
        flip ^= 1;
        if ((i + 1) % 40 == 0) {
            row ^= 1;
        }
        src++;
        dst++;
    }
    D_80100C5C_DeepSeaDivers = func_8009B618(D_80100C5C_DeepSeaDivers + 4.0, 360.0);
}
#else
#ifdef NON_MATCHING
void func_800FF730_DeepSeaDivers(omObjData* obj) {
    unk2C0C0StructC0* m;
    unk2C0C0StructE0* src;
    unk2C0C0StructE0* dst;
    s16 flip = 0;
    s16 row = 0;
    s16 i;

    m = D_800F2B7C[obj->model[1]].unk_6C;
    D_80100C64_DeepSeaDivers -= 0.1f;
    func_80027E48(obj->model[1], D_80100C64_DeepSeaDivers, D_80100C68_DeepSeaDivers, D_80100C60_DeepSeaDivers[0],
                  D_80100C60_DeepSeaDivers[1], "yura_1_1", 1);
    src = m->unk_04;
    dst = m->unk_08[D_800F37F0];
    for (i = 0; i < m->unk_72; i++) {
        if (!(i & 3)) {
            flip = row ^ 1;
            if (!(i & 4)) {
                flip = row;
            }
        }
        if (flip == 0) {
            dst->unk_00 = src->unk_00 + func_800AEAC0(D_80100C5C_DeepSeaDivers) * 40.0;
        } else {
            dst->unk_00 = src->unk_00 - func_800AEAC0(D_80100C5C_DeepSeaDivers) * 40.0;
        }
        flip ^= 1;
        if ((i + 1) % 40 == 0) {
            row ^= 1;
        }
        src++;
        dst++;
    }
    D_80100C5C_DeepSeaDivers = func_8009B618(D_80100C5C_DeepSeaDivers + 4.0, 360.0);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_DeepSeaDivers/218510", func_800FF730_DeepSeaDivers);
#endif
#endif
