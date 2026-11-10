#include "common.h"
#include "engine/mallocblock.h"
#include "engine/process.h"
#include "libc/stdarg.h"

typedef struct unk72D90Struct0 {
    /* 0x00 */ Vtx* unk_00;
    /* 0x04 */ Gfx* unk_04;
} unk72D90Struct0; //sizeof 8

typedef struct unk72D90Struct1 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ void* unk_04;
} unk72D90Struct1; //sizeof unknown

typedef struct unk72D90Struct2 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ char unk_01;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ u16 unk_04;
} unk72D90Struct2; //sizeof 6

u8 D_800C6100 = 0;
void* D_800C6104 = NULL;
Gfx D_800C6108[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetRenderMode(G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0xC0),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetAlphaDither(G_AD_DISABLE),
    gsSPEndDisplayList(),
};
s32 D_800C6158[4] = { -1, -1, -1, -1 };
Vp D_800C6168 = { { { 640, 480, 511, 0 }, { 640, 480, 511, 0 } } };
Gfx D_800C6178[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_FILL),
    gsDPSetRenderMode(G_RM_NOOP, G_RM_NOOP2),
    gsDPSetFillColor(0x00000000),
    gsDPFillRectangle(0, 0, 319, 239),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPEndDisplayList(),
};
s16 D_800C61B8[] = { 0x102, 0x106, 0x107, 0x101 };
u8 D_800C61C0[] = {
    0x03, 0x03, 0x03, 0x00, 0x02, 0x03, 0x03, 0x01, 0x03, 0x01, 0x03, 0x01, 0x03, 0x01, 0x01, 0x03,
    0x01, 0x01, 0x03, 0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x03, 0x02, 0x03, 0x01, 0x00, 0x02, 0x02,
    0x03, 0x01, 0x02, 0x03, 0x03, 0x03, 0x03, 0x00, 0x02, 0x03, 0x01, 0x02, 0x01, 0x01, 0x01, 0x03,
    0x03, 0x02, 0x00, 0x00, 0x02, 0x03, 0x02, 0x03
};
u8 D_800C61F8[] = {
    0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F, 0xA0,
    0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0,
    0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0x86, 0xBD, 0x87, 0x88,
    0x89, 0x8A, 0x8B, 0x8F, 0x8C, 0x8D, 0x8E, 0x00
};
u8 D_800C6230[] = {
    0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xAA,
    0xAB, 0xAC, 0xAD, 0xAE, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0x00, 0x00, 0x00
};
extern const char D_800CBA68[], D_800CBA60[], D_800CBA58[], D_800CBA50[], D_800CBA48[], D_800CBA44[], D_800CBA40[];
char* D_800C624C[] = {
    (char*)D_800CBA68, (char*)D_800CBA60, (char*)D_800CBA58, (char*)D_800CBA50, (char*)D_800CBA48, (char*)D_800CBA44, (char*)D_800CBA40,
};
unk72D90Struct2 D_800C6268[57] = {
    { 0, 0, 0x39A, 0x0 }, { 0, 0, 0x39B, 0x0 }, { 0, 0, 0x39C, 0x0 }, { 1, 0, 0x39D, 0x0 },
    { 1, 0, 0x39E, 0x0 }, { 0, 0, 0x39F, 0x0 }, { 0, 0, 0x3A0, 0x0 }, { 1, 0, 0x3A1, 0x0 },
    { 1, 0, 0x3A2, 0x0 }, { 3, 0, 0x3A3, 0x0 }, { 0, 0, 0x3A4, 0x0 }, { 1, 0, 0x3A5, 0x0 },
    { 0, 0, 0x3A6, 0x0 }, { 1, 0, 0x3A7, 0x0 }, { 1, 0, 0x3A8, 0x0 }, { 0, 0, 0x3A9, 0x0 },
    { 3, 0, 0x3AA, 0x3AB }, { 3, 0, 0x3AC, 0x3AD }, { 0, 0, 0x3AE, 0x0 }, { 1, 0, 0x3AF, 0x0 },
    { 1, 0, 0x3B0, 0x0 }, { 3, 0, 0x3B1, 0x3B2 }, { 1, 0, 0x3B3, 0x0 }, { 1, 0, 0x3B4, 0x0 },
    { 1, 0, 0x3B5, 0x0 }, { 0, 0, 0x3B6, 0x0 }, { 1, 0, 0x3B7, 0x0 }, { 0, 0, 0x3B8, 0x0 },
    { 1, 0, 0x3B9, 0x0 }, { 2, 0, 0x3BA, 0x0 }, { 1, 0, 0x3BB, 0x0 }, { 3, 0, 0x3BC, 0x3BD },
    { 0, 0, 0x3BE, 0x0 }, { 1, 0, 0x3BF, 0x0 }, { 1, 0, 0x3C0, 0x0 }, { 3, 0, 0x3C1, 0x3C2 },
    { 1, 0, 0x3C3, 0x0 }, { 1, 0, 0x3C4, 0x0 }, { 1, 0, 0x3C5, 0x0 }, { 2, 0, 0x3C6, 0x0 },
    { 1, 0, 0x3C7, 0x0 }, { 0, 0, 0x3C8, 0x0 }, { 2, 0, 0x3C9, 0x3CA }, { 1, 0, 0x3CB, 0x0 },
    { 1, 0, 0x3CC, 0x0 }, { 1, 0, 0x3CD, 0x3CE }, { 1, 0, 0x3CF, 0x0 }, { 2, 0, 0x3D0, 0x0 },
    { 1, 0, 0x3D1, 0x0 }, { 2, 0, 0x3D2, 0x3D3 }, { 3, 0, 0x3D4, 0x3D5 }, { 3, 0, 0x3D6, 0x0 },
    { 3, 0, 0x3D7, 0x0 }, { 0, 0, 0x3D8, 0x0 }, { 3, 0, 0x3D9, 0x3DA }, { 1, 0, 0x3DB, 0x0 },
    { 0, 0, 0x0, 0x0 }
};

extern void guLookAt(Mtx*, f32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void guPerspective(Mtx*, u16*, f32, f32, f32, f32, f32);
void* func_80023668(s32);
u32 osVirtualToPhysical(void*);
u32 strlen(const char*);
void* func_80014614(s32);
void DataCloseTemp(void*);
void func_800238F0(s32);
s32 func_8002451C(s32, void (*)(Gfx**), s32);
void func_8003A060(Gfx**, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s16 func_8006DB3C(s16, s32, s16, s16, s16);
s16 func_8006DD8C(s16, s16);
void func_80071598(s16);
void func_8007166C(s16);
s32 func_80072740(Gfx**);
s32 func_8007281C(Gfx**);
void func_800728F4(Gfx**, u8, s32*);
s32 func_800729C8(Gfx**);
s32 func_80072B5C(Gfx**);
void func_80072C34(Gfx**, s32);
void func_80072E1C(Gfx**);
void func_80072E5C(Gfx**, s32);
s32 func_80073008(Gfx**);
s32 func_800730E4(Gfx**);
Gfx* func_80073100(Gfx*, Vtx*);
s32 func_80073560(Gfx**);
s32 func_80073F84(Gfx**);
s32 func_80074040(Gfx**);
void* func_80074124(s32);
s16 func_8006D93C(u8*);
s32 func_80076B2C(u8*, s32);
void func_8007420C(Gfx**, f32, f32);
s32 func_80074C20(Gfx**);
s32 func_80074CE0(Gfx**);
s32 func_80074DB4(Gfx**);
s32 func_80074EBC(Gfx**);
s32 func_80074FC0(Gfx**);
s32 func_800750C8(Gfx**);
s32 func_800751CC(Gfx**);
s32 func_800752D4(Gfx**);
s32 func_800753D8(Gfx**);
s32 func_80075498(Gfx**);
s32 func_8007556C(Gfx**);
s32 func_8007562C(Gfx**);
s32 func_80075700(Gfx**);
s32 func_80075808(Gfx**);
void GMesInit(void);
void GMesCall(Gfx**);
void GMesSprClose();
s32 func_800763CC(unkCommonStruct0*, Gfx**);
s16 func_80076FF4(s16);
s32 func_80077068(unkCommonStruct0*, Gfx**);
s32 func_800773EC(unkCommonStruct0*, s32, s16);
void func_8007767C(unkCommonStruct0*, s32);
s32 func_80077838(unkCommonStruct0*, Gfx**);
s32 func_80077FC4(unkCommonStruct0*, Gfx**);
s32 func_800786F0(unkCommonStruct0*, Gfx**);
s32 func_800789C0(unkCommonStruct0*, Gfx**);
s32 func_80078B6C(unkCommonStruct0*, Gfx**);
s32 func_80079104(unkCommonStruct0*, Gfx**);
s32 func_80079128(unkCommonStruct0*, char*, s16);
s32 func_80079608(unkCommonStruct0*, Gfx**);
s32 func_8007962C(unkCommonStruct0*, Gfx**);
s32 func_80079650(unkCommonStruct0*, Gfx**);
s32 func_80079B2C(unkCommonStruct0*, Gfx**);
s32 func_80079884(unkCommonStruct0*, Gfx**);
s32 func_8007A0FC(unkCommonStruct0*, Gfx**);
s32 func_8007983C(unkCommonStruct0*, Gfx**);
s32 func_8007A7A4(unkCommonStruct0*, Gfx**);
s32 func_80079860(unkCommonStruct0*, Gfx**);
s32 func_8007A978(unkCommonStruct0*, Gfx**);
void func_8007B420(Gfx**);
void func_8007B458(Gfx**);
void func_8007B52C();
s32 func_8007BCA8(s32, s16);

extern u8 fadeStatus;
extern f64 D_800CBA78;
extern f64 D_800CBA80;
extern f64 D_800CBA88;
extern f64 D_800CBA90;
extern f64 D_800CBAA0;
extern f64 D_800CBAA8;
extern char D_800CBAD0[];
extern char D_800CBAD8[];
extern char D_800CBAE4[];
extern Gfx* D_800E4340;
extern s32 D_800E4344;
extern s8 D_800E4348;
extern Gfx* D_800E434C;
extern s16 D_800E4350;
extern s16 D_800E4352;
extern s32 D_800ECB1C;
extern unk72D90Struct0* D_800ED438;
extern TextWindow* D_800ED4B0;
extern s16 D_800ED720;
extern unkCommonStruct0 GMesData[];
extern u8 D_800EDEB0;
extern u16 ContBtn[];
extern Process* D_800F0A24;
extern s8 D_800F2CB8;
extern s16 D_800F2CE0;
extern u8 D_800F2CF8;
extern s16 D_800F3182;
extern f32 D_800F3288;
extern u8 GMesCloseF;
extern unk72D90Struct1 D_800F3744;
extern u8 D_800F3753;
extern s16 D_800F3768[];
extern Gfx* D_800F37DC;
extern s8 D_800F384E;
extern Mtx D_800F3860[];
extern u8 D_800F396A;
extern s16 D_800F3B70[];
extern s8 D_800F3B80;
extern s8 D_800F3FFC;
extern f32 D_800F5024;
extern u8 D_800F50B8;
extern Mtx D_800F5340[];
extern s32 D_800F545C;
extern s8 omSysPauseEnableFlag;
extern s16 D_800F64F4;
extern s16 D_800F6548;

void func_80072190(void) {
    fadeStatus = 0;
    D_800ED0D2 = 0;
    D_800F396A = 0;
    D_800F2CF8 = 0;
    D_800EDEB0 = 0;
    D_800F50B8 = 0;

    GMesInit();
}

void func_800721D8(Gfx** arg0) {
    if (D_800ED0D2 == 3) {
        if (D_800C6100 == 254) {
            func_80072E1C(arg0);
        } else {
            func_800728F4(arg0, 255, D_800C6158);
        }
        return;
    }

    GMesCall(arg0);

    if (D_800ED0D2 == 0) {
        return;
    }

    switch (D_800ED0D2) {
        case 1:
            switch (D_800C6100) {
                case 0:
                    fadeStatus = func_80072740(arg0);
                    break;
                case 254:
                    fadeStatus = func_800729C8(arg0);
                    break;
                case 253:
                    fadeStatus = func_80073008(arg0);
                    break;
                case 252:
                    fadeStatus = 0;
                    break;
                case 1:
                    fadeStatus = func_80073F84(arg0);
                    break;
                case 2:
                    fadeStatus = func_80074C20(arg0);
                    break;
                case 3:
                    fadeStatus = func_80074DB4(arg0);
                    break;
                case 4:
                    fadeStatus = func_80074FC0(arg0);
                    break;
                case 5:
                    fadeStatus = func_800751CC(arg0);
                    break;
                case 6:
                    fadeStatus = func_800753D8(arg0);
                    break;
                case 7:
                    fadeStatus = func_8007556C(arg0);
                    break;
                case 8:
                    fadeStatus = func_80075700(arg0);
                    break;
            }
            D_800F5024 += 1.0f;
            if (fadeStatus == 0) {
                func_80072724(0, 0, 0);
                if (D_800C6104 != NULL) {
                    if (D_800F50B8 == 0) {
                        HuMemDirectFree(D_800C6104);
                    }
                    D_800C6104 = NULL;
                }
                func_800238F0(28000);
            }
            break;
        case 2:
            switch (D_800C6100) {
                case 0:
                    fadeStatus = func_8007281C(arg0);
                    break;
                case 254:
                    fadeStatus = func_80072B5C(arg0);
                    break;
                case 253:
                    fadeStatus = func_800730E4(arg0);
                    break;
                case 252:
                    fadeStatus = func_80073560(arg0);
                    break;
                case 1:
                    fadeStatus = func_80074040(arg0);
                    break;
                case 2:
                    fadeStatus = func_80074CE0(arg0);
                    break;
                case 3:
                    fadeStatus = func_80074EBC(arg0);
                    break;
                case 4:
                    fadeStatus = func_800750C8(arg0);
                    break;
                case 5:
                    fadeStatus = func_800752D4(arg0);
                    break;
                case 6:
                    fadeStatus = func_80075498(arg0);
                    break;
                case 7:
                    fadeStatus = func_8007562C(arg0);
                    break;
                case 8:
                    fadeStatus = func_80075808(arg0);
                    break;
            }
            D_800F5024 += 1.0f;
            break;
    }

    if (fadeStatus == 0) {
        if (D_800ED0D2 == 2) {
            D_800ED0D2 = 3;
        } else {
            D_800ED0D2 = 0;
        }
        D_800F5024 = 0.0f;
    }
}

void SetFadeInTypeAndTime(s16 a, s16 b) {
    if (fadeStatus == 0) {
        D_800ED0D2 = 1;
        fadeStatus = 1;
        if (a != 255) {
            D_800C6100 = a;
        }
        D_800F3288 = b;
        D_800F5024 = 0.0f;
    }
}

void func_800726AC(s16 a, s16 b) {
    if (fadeStatus == 0) {
        D_800ED0D2 = 2;
        fadeStatus = 1;
        if (a != 255) {
            D_800C6100 = a;
        }
        D_800F3288 = b;
        D_800F5024 = 0.0f;
    }
}

s32 func_80072718(void) {
    return fadeStatus;
}

void func_80072724(u8 arg0, u8 arg1, u8 arg2) {
    D_800EDEB0 = arg0;
    D_800F2CF8 = arg1;
    D_800F396A = arg2;
}

s32 func_80072740(Gfx** arg0) {
    if (D_800F3288 == 0.0f) {
        return 0;
    }

    func_800728F4(arg0, 255.0f - D_800F5024 / D_800F3288 * 255.0f, D_800C6158);

    if (D_800F5024 >= D_800F3288) {
        return 0;
    }

    return 1;
}

s32 func_8007281C(Gfx** arg0) {
    if (D_800F3288 == 0.0f) {
        return 0;
    }

    func_800728F4(arg0, D_800F5024 / D_800F3288 * 255.0f, D_800C6158);

    if (D_800F5024 >= D_800F3288) {
        return 0;
    }

    return 1;
}

void func_800728F4(Gfx** arg0, u8 arg1, s32* arg2) {
    gSPDisplayList((*arg0)++, D_800C6108);
    gDPSetRenderMode((*arg0)++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    gDPSetCombineMode((*arg0)++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor((*arg0)++, 0, 0, D_800EDEB0, D_800F2CF8, D_800F396A, arg1);
    gDPFillRectangle((*arg0)++, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}

// decomp-permuter
s32 func_800729C8(Gfx **arg0)
{
  f32 new_var;
  if (D_800C6104 == 0)
  {
    return 0;
  }
 do { if ((new_var = D_800F3288) != 0.0f) { u8 var_a1 = 255.0f - ((D_800F5024 / D_800F3288) * 255.0f); gSPDisplayList((*arg0)++, D_800C6108); gDPSetCombineMode((*arg0)++, G_CC_MODULATEI_PRIM, G_CC_MODULATEI_PRIM); gDPSetRenderMode((*arg0)++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2); gDPSetPrimColor((*arg0)++, 0, 0, 255, 255, 255, var_a1); func_80072E5C(arg0, D_800F545C); if (!(D_800F5024 >= D_800F3288)) { return 1; } } if (D_800F50B8 == 0) { HuMemDirectFree(D_800C6104); } } while (0);
  D_800C6104 = 0;
  return 0;
}

s32 func_80072B5C(Gfx** arg0) {
    gSPDisplayList((*arg0)++, D_800C6108);

    if (D_800F5024 == 0.0f) {
        D_800C6104 = HuMemDirectMalloc(153664);
        D_800F545C = (s32) (D_800C6104 + 63) & ~63;
        func_80072C34(arg0, D_800F545C);
        return 1;
    }

    func_80072E5C(arg0, D_800F545C);

    if (D_800F5024 > 1.0f) {
        return 0;
    }

    return 1;
}

void func_80072C34(Gfx** arg0, s32 arg1) {
    s16 i;
    s16 j;

    gDPSetColorImage((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, arg1);

    for (i = 0; i < SCREEN_HEIGHT; i += 16) {
        for (j = 0; j < SCREEN_WIDTH; j += 64) {
            func_8003A060(arg0, ((j + (i * SCREEN_WIDTH)) * 2) + 0x02000000, 0, 2, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 64, 16, 0, 2, 2, 0, 0, 0, 0);
            gSPTextureRectangle((*arg0)++, j * 4, i * 4, (j + 64) * 4, (i + 16) * 4, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
        }
    }

    gDPSetColorImage((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, 0x02000000);
}

void func_80072E1C(Gfx** arg0) {
    gSPDisplayList((*arg0)++, D_800C6108);
    func_80072E5C(arg0, D_800F545C);
}

void func_80072E5C(Gfx** arg0, s32 arg1) {
    s16 i;
    s16 j;

    for (i = 0; i < SCREEN_HEIGHT; i += 16) {
        for (j = 0; j < SCREEN_WIDTH; j += 64) {
            func_8003A060(arg0, arg1 + (j + i * SCREEN_WIDTH) * 2, 0, 2, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 64, 16, 0, 2, 2, 0, 0, 0, 0);
            gSPTextureRectangle((*arg0)++, j * 4, i * 4, (j + 64) * 4, (i + 16) * 4, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
        }
    }
}

s32 func_80073008(Gfx** arg0) {
    unk72D90Struct0* temp_v0;

    if (D_800F5024 == 0.0f) {
        temp_v0 = D_800ED438 = func_80023684(sizeof(unk72D90Struct0), 28000);
        temp_v0->unk_00 = func_80023684(400 * sizeof(Vtx), 28000);
        temp_v0->unk_04 = func_80023684(1000 * sizeof(Gfx), 28000);
        func_80073100(temp_v0->unk_04, temp_v0->unk_00);
    }

    temp_v0 = D_800ED438;

    gSPDisplayList((*arg0)++, temp_v0->unk_04);

    if (D_800F5024 >= 60.0f) {
        return 0;
    }

    return 1;
}

s32 func_800730E4(Gfx** arg0) {
    return func_80072B5C(arg0);
}

Gfx* func_80073100(Gfx* arg0, Vtx* arg1) {
    Gfx* sp4C = arg0;
    Vtx* var_s2 = arg1;
    u16 sp48;
    s16 i;
    s16 j;

    gSPDisplayList(sp4C++, D_800C6108);
    gDPSetCombineMode(sp4C++, G_CC_DECALRGB, G_CC_DECALRGB);
    gDPSetRenderMode(sp4C++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    gDPSetTexturePersp(sp4C++, G_TP_PERSP);
    gSPTexture(sp4C++, -1, -1, 0, G_TX_RENDERTILE, G_ON);

    guPerspective(&D_800F3860[D_800F3FA8], &sp48, 20.0f, 1.3333334f, 80.0f, 8000.0f, 1.0f);
    guLookAt(&D_800F5340[D_800F3FA8], 0.0f, 0.0f, 3000.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    gSPPerspNormalize(sp4C++, &sp48);
    gSPViewport(sp4C++, &D_800C6168);
    gSPMatrix(sp4C++, osVirtualToPhysical(&D_800F3860[D_800F3FA8]), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(sp4C++, VIRTUAL_TO_PHYSICAL(&D_800F5340[D_800F3FA8]), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetScissor(sp4C++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    for (i = 96; i >= -120; i -= 24) {
        for (j = -160; j < 160; j += 32) {
            s32 sp54 = (96 - i) * SCREEN_WIDTH + 160;

            func_8003A060(&sp4C, D_800F545C + (j + sp54) * 2, 0, 2, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 32, 24, 0, 2, 2, 5, 5, 0, 0);

            gSPVertex(sp4C++, osVirtualToPhysical(var_s2), 4, 0);
            gSP1Quadrangle(sp4C++, 0, 1, 2, 3, 0);

            var_s2->n.ob[0] = j * 10;
            var_s2->n.ob[1] = i * 10;
            var_s2->n.ob[2] = 0;
            var_s2->n.n[0] = var_s2->n.n[1] = var_s2->n.n[2] = -1;
            var_s2->n.tc[0] = 0;
            var_s2->n.tc[1] = 768;
            var_s2->n.a = 255;
            var_s2++;

            var_s2->n.ob[0] = j * 10;
            var_s2->n.ob[1] = i * 10 + SCREEN_HEIGHT;
            var_s2->n.ob[2] = 0;
            var_s2->n.n[0] = var_s2->n.n[1] = var_s2->n.n[2] = -1;
            var_s2->n.tc[0] = 0;
            var_s2->n.tc[1] = 0;
            var_s2->n.a = 255;
            var_s2++;

            var_s2->n.ob[0] = j * 10 + SCREEN_WIDTH;
            var_s2->n.ob[1] = i * 10 + SCREEN_HEIGHT;
            var_s2->n.ob[2] = 0;
            var_s2->n.n[0] = var_s2->n.n[1] = var_s2->n.n[2] = -1;
            var_s2->n.tc[0] = 1024;
            var_s2->n.tc[1] = 0;
            var_s2->n.a = 255;
            var_s2++;

            var_s2->n.ob[0] = j * 10 + SCREEN_WIDTH;
            var_s2->n.ob[1] = i * 10;
            var_s2->n.ob[2] = 0;
            var_s2->n.n[0] = var_s2->n.n[1] = var_s2->n.n[2] = -1;
            var_s2->n.tc[0] = 1024;
            var_s2->n.tc[1] = 768;
            var_s2->n.a = 255;
            var_s2++;
        }
    }

    gSPEndDisplayList(sp4C++);
    return sp4C;
}

s32 func_80073560(Gfx** arg0) {
    f32 temp_f22;
    f32 temp_f24;
    s32 var_s8; /* s32 on the N64: a framebuffer address */
    s16 i;
    s16 j;

    if (D_800F3288 - 1.0f <= D_800F5024) {
        func_800728F4(arg0, 255, D_800C6158);
        return 0;
    }

    temp_f22 = 1.0f - D_800F5024 / D_800F3288;
    temp_f24 = 1.0f / temp_f22;

    gSPDisplayList((*arg0)++, D_800C6108);
    gDPSetAlphaCompare((*arg0)++, G_AC_THRESHOLD);
    gDPSetBlendColor((*arg0)++, 0, 0, 0, 0);
    gDPSetTextureFilter((*arg0)++, G_TF_BILERP);
    gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    var_s8 = D_800ECB1C;

    gDPSetColorImage((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, 0x003D0800);
    gSPDisplayList((*arg0)++, D_800C6178);
    gDPSetCombineMode((*arg0)++, G_CC_DECALRGB, G_CC_DECALRGB);
    gDPSetRenderMode((*arg0)++, G_RM_OPA_SURF, G_RM_OPA_SURF2);

    for (i = 0; i < SCREEN_HEIGHT; i += 16) {
        for (j = 0; j < SCREEN_WIDTH; j += 64) {
            func_8003A060(arg0, var_s8 + (j + i * SCREEN_WIDTH) * 2, 0, 2, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 64, 16, 0, 2, 2, 0, 0, 0, 0);
            gSPTextureRectangle((*arg0)++, j * temp_f22 * 4.0f, i * temp_f22 * 4.0f,
                (j * temp_f22 + temp_f22 * 64.0f) * 4.0f, (i * temp_f22 + temp_f22 * 16.0f) * 4.0f,
                G_TX_RENDERTILE, 0, 0, temp_f24 * 1024.0f, temp_f24 * 1024.0f);
        }
    }

    gDPSetColorImage((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, 0x02000000);

    var_s8 = 0x803D0800;
    for (i = 0; i < temp_f22 * (f32)SCREEN_HEIGHT + 15.0f; i += 16) {
        for (j = 0; j < temp_f22 * (f32)SCREEN_WIDTH + 31.0f; j += 32) {
            func_8003A060(arg0, var_s8 + (j + i * SCREEN_WIDTH) * 2, 0, 2, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 32, 16, 0, 2, 2, 0, 0, 0, 0);
            gSPTextureRectangle((*arg0)++, j * temp_f24 * 4.0f, i * temp_f24 * 4.0f,
                (j + 32) * temp_f24 * 4.0f, (i + 16) * temp_f24 * 4.0f,
                G_TX_RENDERTILE, 0, 0, temp_f22 * 1024.0f, temp_f22 * 1024.0f);
        }
    }

    gDPPipeSync((*arg0)++);
    gDPSetCombineMode((*arg0)++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode((*arg0)++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetPrimColor((*arg0)++, 0, 0, 0, 0, 0, 8);
    gDPFillRectangle((*arg0)++, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    return 1;
}

s32 func_80073F84(Gfx** arg0) {
    if (D_800F3288 == 0.0f) {
        return 0;
    }

    if (D_800F5024 == 0.0f) {
        func_80074124(44);
    }

    func_8007420C(arg0, D_800F5024 / D_800F3288, 1.0f);

    if (D_800F5024 >= D_800F3288) {
        return 0;
    }

    return 1;
}

s32 func_80074040(Gfx** arg0) {
    f32 var_a2;

    if (D_800F3288 == 0.0f) {
        return 0;
    }

    if (D_800F5024 == 0.0f) {
        func_80074124(44);
    }

    var_a2 = (1.0f - D_800F5024 / D_800F3288) * 1.1f;
    func_8007420C(arg0, var_a2, 1.0f);

    if (D_800F5024 >= D_800F3288) {
        return 0;
    }

    return 1;
}

void* func_80074124(s32 arg0) {
    u8* data;
    u8* p;

    data = DataRead(arg0);
    p = data + (data[2] << 8) + data[3];
    D_800F3744.unk_00 = (p[4] << 8) + p[5];
    D_800F3744.unk_02 = (p[6] << 8) + p[7];
    p = data + (p[2] << 8) + p[3];
    D_800F3744.unk_04 = func_80023684(D_800F3744.unk_00 * D_800F3744.unk_02, 0x6D60);
    func_80023A38(p, D_800F3744.unk_04, D_800F3744.unk_00 * D_800F3744.unk_02);
    DataClose(data);
    return data;
}


void func_8007420C(Gfx** arg0, f32 arg1, f32 arg2) {
    s16 var_t1;
    s16 var_t2;
    s16 var_t3;
    s16 var_t4;
    f32 temp_f4;

    if (arg1 == 0) {
        func_800728F4(arg0, 255, D_800C6158);
        return;
    }

    gSPDisplayList((*arg0)++, D_800C6108);
    gDPSetAlphaCompare((*arg0)++, G_AC_THRESHOLD);
    gDPSetBlendColor((*arg0)++, 0, 0, 0, 1);
    gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    gDPSetTextureFilter((*arg0)++, G_TF_BILERP);
    gDPSetRenderMode((*arg0)++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineLERP((*arg0)++, 0, 0, 0, PRIMITIVE, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, PRIMITIVE, PRIMITIVE, 0, TEXEL0, 0);
    gDPLoadTextureBlock((*arg0)++, D_800F3744.unk_04, G_IM_FMT_I, G_IM_SIZ_8b, D_800F3744.unk_00, D_800F3744.unk_02, 0,
        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gDPSetPrimColor((*arg0)++, 0, 0, D_800EDEB0, D_800F2CF8, D_800F396A, arg2 * 255.0f);

    var_t3 = 160.0f - arg1 * 160.0f;
    var_t1 = 120.0f - arg1 * 160.0f;
    var_t4 = 160.0f + arg1 * 160.0f;
    var_t2 = 120.0f + arg1 * 160.0f;
    temp_f4 = ((f32) var_t4 - var_t3) / D_800F3744.unk_00;

    gSPScisTextureRectangle((*arg0)++, var_t3 * 4, var_t1 * 4, var_t4 * 4, var_t2 * 4, 0, 0, 0,
        (1.0f / temp_f4) * 1024.0f, (1.0f / temp_f4) * 1024.0f);
    gDPSetRenderMode((*arg0)++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode((*arg0)++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor((*arg0)++, 0, 0, D_800EDEB0, D_800F2CF8, D_800F396A, arg2 * 255.0f);

    if (var_t1 > 0) {
        gDPScisFillRectangle((*arg0)++, 0, 0, SCREEN_WIDTH, var_t1);
    } else {
        var_t1 = 0;
    }

    if (var_t2 < SCREEN_HEIGHT) {
        gDPScisFillRectangle((*arg0)++, 0, var_t2, SCREEN_WIDTH, SCREEN_HEIGHT);
    } else {
        var_t2 = SCREEN_HEIGHT;
    }

    if (var_t3 > 0) {
        gDPScisFillRectangle((*arg0)++, 0, var_t1, var_t3, var_t2);
    }

    if (var_t4 < SCREEN_WIDTH) {
        gDPScisFillRectangle((*arg0)++, var_t4, var_t1, SCREEN_WIDTH, var_t2);
    }
}

s32 func_80074C20(Gfx** arg0) {
    if (D_800F3288 == 0.0f) {
        return 0;
    }

    if (D_800F5024 == 0.0f) {
        func_80074124(45);
    }

    func_8007420C(arg0, D_800F5024 / D_800F3288 * 2.0f, 1.0f);

    if (D_800F5024 >= D_800F3288) {
        return 0;
    }

    return 1;
}

s32 func_80074CE0(Gfx** arg0) {
    if (D_800F3288 == 0.0f) {
        return 0;
    }

    if (D_800F5024 == 0.0f) {
        func_80074124(45);
    }

    func_8007420C(arg0, (1.0f - D_800F5024 / D_800F3288) * 2.0f, 1.0f);

    if (D_800F5024 >= D_800F3288) {
        return 0;
    }

    return 1;
}

s32 func_80074DB4(Gfx** arg0) {
    f32 var_a2;
    f32 temp_f2;
    f32 var_f2;

    if (D_800F3288 == 0.0f) {
        return 0;
    }

    if (D_800F5024 == 0.0f) {
        func_80074124(46);
    }

    var_a2 = D_800F5024 / D_800F3288 * 2.0f;
    temp_f2 = D_800F3288 * 0.5f;
    if (temp_f2 < D_800F5024) {
        var_f2 = 1.0f - (D_800F5024 - temp_f2) / temp_f2;
    } else {
        var_f2 = 1.0f;
    }

    func_8007420C(arg0, var_a2, var_f2);

    if (D_800F5024 >= D_800F3288) {
        return 0;
    }

    return 1;
}

s32 func_80074EBC(Gfx** arg0) {
    f32 var_a2;
    f32 temp_f2;
    f32 var_f2;

    if (D_800F3288 == 0.0f) {
        return 0;
    }

    if (D_800F5024 == 0.0f) {
        func_80074124(46);
    }

    var_a2 = (1.0f - D_800F5024 / D_800F3288) * 2.0f;
    temp_f2 = D_800F3288 * 0.5f;
    if (temp_f2 > D_800F5024) {
        var_f2 = D_800F5024 / temp_f2;
    } else {
        var_f2 = 1.0f;
    }

    func_8007420C(arg0, var_a2, var_f2);

    if (D_800F5024 >= D_800F3288) {
        return 0;
    }

    return 1;
}

s32 func_80074FC0(Gfx** arg0) {
    f32 var_a2;
    f32 temp_f2;
    f32 var_f2;

    if (D_800F3288 == 0.0f) {
        return 0;
    }

    if (D_800F5024 == 0.0f) {
        func_80074124(47);
    }

    var_a2 = D_800F5024 / D_800F3288 * 2.0f;
    temp_f2 = D_800F3288 * 0.5f;
    if (temp_f2 < D_800F5024) {
        var_f2 = 1.0f - (D_800F5024 - temp_f2) / temp_f2;
    } else {
        var_f2 = 1.0f;
    }

    func_8007420C(arg0, var_a2, var_f2);

    if (D_800F5024 >= D_800F3288) {
        return 0;
    }

    return 1;
}

s32 func_800750C8(Gfx** arg0) {
    f32 var_a2;
    f32 temp_f2;
    f32 var_f2;

    if (D_800F3288 == 0.0f) {
        return 0;
    }

    if (D_800F5024 == 0.0f) {
        func_80074124(47);
    }

    var_a2 = (1.0f - D_800F5024 / D_800F3288) * 2.0f;
    temp_f2 = D_800F3288 * 0.5f;
    if (temp_f2 > D_800F5024) {
        var_f2 = D_800F5024 / temp_f2;
    } else {
        var_f2 = 1.0f;
    }

    func_8007420C(arg0, var_a2, var_f2);

    if (D_800F5024 >= D_800F3288) {
        return 0;
    }

    return 1;
}

s32 func_800751CC(Gfx** arg0) {
    f32 var_a2;
    f32 temp_f2;
    f32 var_f2;

    if (D_800F3288 == 0.0f) {
        return 0;
    }

    if (D_800F5024 == 0.0f) {
        func_80074124(48);
    }

    var_a2 = D_800F5024 / D_800F3288 * 2.0f;
    temp_f2 = D_800F3288 * 0.5f;
    if (temp_f2 < D_800F5024) {
        var_f2 = 1.0f - (D_800F5024 - temp_f2) / temp_f2;
    } else {
        var_f2 = 1.0f;
    }

    func_8007420C(arg0, var_a2, var_f2);

    if (D_800F5024 >= D_800F3288) {
        return 0;
    }

    return 1;
}

s32 func_800752D4(Gfx** arg0) {
    f32 var_a2;
    f32 temp_f2;
    f32 var_f2;

    if (D_800F3288 == 0.0f) {
        return 0;
    }

    if (D_800F5024 == 0.0f) {
        func_80074124(48);
    }

    var_a2 = (1.0f - D_800F5024 / D_800F3288) * 2.0f;
    temp_f2 = D_800F3288 * 0.5f;
    if (temp_f2 > D_800F5024) {
        var_f2 = D_800F5024 / temp_f2;
    } else {
        var_f2 = 1.0f;
    }

    func_8007420C(arg0, var_a2, var_f2);

    if (D_800F5024 >= D_800F3288) {
        return 0;
    }

    return 1;
}

s32 func_800753D8(Gfx** arg0) {
    if (D_800F3288 == 0.0f) {
        return 0;
    }

    if (D_800F5024 == 0.0f) {
        func_80074124(49);
    }

    func_8007420C(arg0, D_800F5024 / D_800F3288 * 2.0f, 1.0f);

    if (D_800F5024 >= D_800F3288) {
        return 0;
    }

    return 1;
}

s32 func_80075498(Gfx** arg0) {
    if (D_800F3288 == 0.0f) {
        return 0;
    }

    if (D_800F5024 == 0.0f) {
        func_80074124(49);
    }

    func_8007420C(arg0, (1.0f - D_800F5024 / D_800F3288) * 2.0f, 1.0f);

    if (D_800F5024 >= D_800F3288) {
        return 0;
    }

    return 1;
}

s32 func_8007556C(Gfx** arg0) {
    if (D_800F3288 == 0.0f) {
        return 0;
    }

    if (D_800F5024 == 0.0f) {
        func_80074124(50);
    }

    func_8007420C(arg0, D_800F5024 / D_800F3288 * 2.0f, 1.0f);

    if (D_800F5024 >= D_800F3288) {
        return 0;
    }

    return 1;
}

s32 func_8007562C(Gfx** arg0) {
    if (D_800F3288 == 0.0f) {
        return 0;
    }

    if (D_800F5024 == 0.0f) {
        func_80074124(50);
    }

    func_8007420C(arg0, (1.0f - D_800F5024 / D_800F3288) * 2.0f, 1.0f);

    if (D_800F5024 >= D_800F3288) {
        return 0;
    }

    return 1;
}

s32 func_80075700(Gfx** arg0) {
    f32 var_a2;
    f32 temp_f2;
    f32 var_f2;

    if (D_800F3288 == 0.0f) {
        return 0;
    }

    if (D_800F5024 == 0.0f) {
        func_80074124(51);
    }

    var_a2 = D_800F5024 / D_800F3288 * 2.0f;
    temp_f2 = D_800F3288 * 0.5f;
    if (temp_f2 < D_800F5024) {
        var_f2 = 1.0f - (D_800F5024 - temp_f2) / temp_f2;
    } else {
        var_f2 = 1.0f;
    }

    func_8007420C(arg0, var_a2, var_f2);

    if (D_800F5024 >= D_800F3288) {
        return 0;
    }

    return 1;
}

s32 func_80075808(Gfx** arg0) {
    f32 var_a2;
    f32 temp_f2;
    f32 var_f2;

    if (D_800F3288 == 0.0f) {
        return 0;
    }

    if (D_800F5024 == 0.0f) {
        func_80074124(51);
    }

    var_a2 = (1.0f - D_800F5024 / D_800F3288) * 2.0f;
    temp_f2 = D_800F3288 * 0.5f;
    if (temp_f2 > D_800F5024) {
        var_f2 = D_800F5024 / temp_f2;
    } else {
        var_f2 = 1.0f;
    }

    func_8007420C(arg0, var_a2, var_f2);

    if (D_800F5024 >= D_800F3288) {
        return 0;
    }

    return 1;
}

void GMesInit(void) {
    s16 i;

    D_800F2CB8 = 0;

    for (i = 0; i < 8; i++) {
        GMesData[i].unk_00 = 0;
    }

    for (i = 0; i < 8; i++) {
        D_800F3B70[i] = D_800F3768[i] = -1;
    }

    GMesCloseF = 0;
    D_800F3FFC = -1;
    D_800F3753 = 0;
}

void GMesCall(Gfx** arg0) {
    unkCommonStruct0* var_s0;
    s16 var_s1 = 0;
    s16 i;
    s16 j;

    if (D_800F384E != 0 && GMesCloseF == 0) {
        return;
    }

    for (i = 0; i < 8; i++) {
        if (GMesData[i].unk_01 == 0) {
            continue;
        }

        var_s0 = &GMesData[i];

        switch (var_s0->unk_00) {
            case 0:
                var_s1 = func_800763CC(var_s0, arg0);
                break;
            case 2:
                var_s1 = func_80077068(var_s0, arg0);
                break;
            case 4:
                var_s1 = func_80077838(var_s0, arg0);
                break;
            case 5:
                var_s1 = func_80077FC4(var_s0, arg0);
                break;
            case 6:
                var_s1 = func_800786F0(var_s0, arg0);
                break;
            case 7:
                var_s1 = func_800789C0(var_s0, arg0);
                break;
            case 8:
                var_s1 = func_80078B6C(var_s0, arg0);
                break;
            case 9:
                var_s1 = func_80079104(var_s0, arg0);
                break;
            case 10:
                var_s1 = func_80079608(var_s0, arg0);
                break;
            case 11:
                var_s1 = func_8007962C(var_s0, arg0);
                break;
            case 12:
                var_s1 = func_80079650(var_s0, arg0);
                break;
            case 16:
                var_s1 = func_8007983C(var_s0, arg0);
                break;
            case 18:
                var_s1 = func_80079860(var_s0, arg0);
                break;
            case 14:
                var_s1 = func_80079884(var_s0, arg0);
                break;
            case 13:
                var_s1 = func_80079B2C(var_s0, arg0);
                break;
            case 15:
                var_s1 = func_8007A0FC(var_s0, arg0);
                break;
            case 17:
                var_s1 = func_8007A7A4(var_s0, arg0);
                break;
            case 19:
                var_s1 = func_8007A978(var_s0, arg0);
                break;
        }

        var_s0->unk_04++;
        if (var_s0->unk_04 >= 16384) {
            var_s0->unk_04 = 8192;
        }

        if (var_s1 == 0) {
            var_s0->unk_01 = 0;

            if (D_800F3753 == 0) {
                for (j = 0; j < 8; j++) {
                    if (GMesData[j].unk_01 != 0 && GMesData[j].unk_00 != 8) {
                        break;
                    }
                }

                if (j == 8) {
                    GMesSprClose();
                }
            }
        }
    }
}

// // Matches but needs rodata
// #ifdef NON_MATCHING
s32 GMesCreate(s16 arg0, ...) {
    unkCommonStruct0* temp_a2;
    va_list args;
    s16 var_t0;
    s32 temp_s32; // required to match
    s16 i;

    va_start(args, arg0);

    for (var_t0 = 0; var_t0 < 8; var_t0++) {
        if (GMesData[var_t0].unk_01 == 0) {
            break;
        }
    }

    if (var_t0 == 8) {
        return -1;
    }

    temp_a2 = &GMesData[var_t0];
    temp_a2->unk_01 = 1;
    temp_a2->unk_00 = arg0;
    temp_a2->unk_04 = 0;
    temp_a2->unk_54 = 160.0f;
    temp_a2->unk_58 = 120.0f;
    temp_a2->unk_60 = 1.0f;
    temp_a2->unk_5C = 1.0f;
    temp_a2->unk_64 = 0.0f;
    temp_a2->unk_03 = 255;
    temp_a2->unk_06 = 60;

    for (i = 0; i < 16; i++) {
        temp_a2->unk_14[i] = -1;
        temp_a2->unk_34[i] = -1;
    }

    switch (arg0) {
        case 4:
        case 5:
            temp_a2->unk_08 = temp_s32 = va_arg(args, s32);
            break;
        case 6:
        case 7:
            temp_a2->unk_10 = va_arg(args, s32);
            temp_a2->unk_54 = va_arg(args, s32);
            temp_a2->unk_58 = va_arg(args, s32);
            temp_a2->unk_5C = va_arg(args, f64);
            temp_a2->unk_60 = va_arg(args, f64);
            temp_a2->unk_02 = va_arg(args, s32);
            break;
        case 8:
            D_800F3FFC = var_t0;
            temp_a2->unk_08 = va_arg(args, s32);
            temp_a2->unk_54 = va_arg(args, s32);
            temp_a2->unk_58 = va_arg(args, s32);
            temp_a2->unk_54 = 160.0f;
            temp_a2->unk_58 = 28.0f;
            break;
        case 15:
            temp_a2->unk_08 = temp_s32 = va_arg(args, s32);
            temp_a2->unk_0A = temp_s32 = va_arg(args, s32);
            break;
        case 19:
            temp_a2->unk_08 = temp_s32 = va_arg(args, s32);
            temp_a2->unk_0A = temp_s32 = va_arg(args, s32);
            temp_a2->unk_0C = temp_s32 = va_arg(args, s32);
            temp_a2->unk_58 = 160.0f;
            break;
        case 0:
        case 2:
        case 14:
        case 16:
        case 18:
            temp_a2->unk_06 = 45;
            break;
    }

    D_800ED720 = 90;
    return var_t0;
}

s32 GMesStatAllGet(void) {
    s16 var_a1;
    s16 i;

    for (i = 0, var_a1 = 0; i < 8; i++) {
        if (GMesData[i].unk_00 != 8) {
            var_a1 |= GMesData[i].unk_01;
        }
    }

    return var_a1;
}

s32 GMesStatGet(s16 arg0) {
    return GMesData[arg0].unk_01;
}

void GMesMaxTimeGet(s16 arg0, s16 arg1) {
    GMesData[arg0].unk_06 = arg1;
}

void GMesPosSet(s16 arg0, f32 arg1, f32 arg2) {
    GMesData[arg0].unk_54 = arg1;
    GMesData[arg0].unk_58 = arg2;
}

void func_800760E4(s16 arg0) {
    if (GMesData[arg0].unk_01 != 0) {
        GMesData[arg0].unk_01 = 4;
    }
}

void GMesClose(void) {
    D_800F3FFC = -1;
    GMesCloseF = 1;
    GMesCall(&D_800F37DC);
    GMesCloseF = 0;
    GMesSprClose();
    D_800F3753 = 0;
}

s32 GMesWait(void) {
    s32 temp_v0;
    s32 i;

    if (D_800F384E == 0 && D_800F5144 == 0) {
        temp_v0 = GMesStatAllGet();

        if (temp_v0 == 0 || temp_v0 & 2) {
            if (_CheckFlag(0x2B)) {
                return 0;
            }

            D_800ED720--;
            if (D_800ED720 < 0) {
                return 0;
            }

            for (i = 0; i < MAX_PLAYERS; i++) {
                if (ContBtn[GwPlayer[i].port] & 0xC000) {
                    return 0;
                }
            }
        }
    }

    return 1;
}

void GMesMaxWaitSet(s16 arg0) {
    D_800ED720 = arg0;
}

void GMesSprClose(void) {
    s16 i;

    for (i = 0; i < 8; i++) {
        if (i == 2 && D_800F3FFC != -1) {
            continue;
        }
        if (D_800F3B70[i] != -1) {
            func_80067704(D_800F3B70[i]);
        }
        if (D_800F3768[i] != -1) {
            func_80067704(D_800F3768[i]);
        }
        D_800F3B70[i] = D_800F3768[i] = -1;
    }
}

void GMesSprKill(unkCommonStruct0* arg0) {
    s16 i;

    for (i = 0; i < 16; i++) {
        if (arg0->unk_14[i] != -1) {
            func_80064D38(arg0->unk_14[i]);
        }
        if (arg0->unk_34[i] != -1) {
            func_80067704(arg0->unk_34[i]);
        }
    }
}

// unk_04 kept in a register across the "< 10" branch where retail reloads it (masked 8)
#ifdef NON_MATCHING
s32 func_800763CC(unkCommonStruct0* arg0, Gfx** arg1) {
    f32 temp_f24;
    f32 n;
    f32 i;
    s32 d;

    n = 5.0f;

    if (arg0->unk_04 == 0) {
        GMesFontCreate(arg0, "START", 1, -12, 0);
        func_80066DC4(arg0->unk_14[0], 0, 83, arg0->unk_58);
    }

    if (arg0->unk_04 > arg0->unk_06 || GMesCloseF != 0 || arg0->unk_01 == 4) {
        GMesSprKill(arg0);
        omSysPauseEnableFlag = 0;
        return 0;
    }

    if (arg0->unk_04 == 10) {
        PlaySound(0x41A);
    }

    if (arg0->unk_04 == 38) {
        PlaySound(D_800C61B8[D_800C61C0[GwSystem.unk_1E]]);
    }

    if (arg0->unk_04 > arg0->unk_06 - 10) {
        arg0->unk_01 = 2;
        d = arg0->unk_04 + 10;
        temp_f24 = d - arg0->unk_06;
        func_800673B0(arg0->unk_14[0], 0, temp_f24 * 5.0f);

        for (i = 0.0f; i < n; i++) {
            func_80067354(arg0->unk_14[0], i + 1.0f, 1.0f - temp_f24 / 10.0f, 1.0f - temp_f24 / 10.0f);
            func_8006752C(arg0->unk_14[0], i + 1.0f, 255.0f - temp_f24 * 25.5f);
        }
        return 1;
    }

    if (arg0->unk_04 < 10) {
        func_800673B0(arg0->unk_14[0], 0, 180.0f - arg0->unk_04 * 20.0f);

        for (i = 0.0f; i < n;) {
            i++;
            func_80067354(arg0->unk_14[0], i, arg0->unk_04 / 7.0f, arg0->unk_04 / 7.0f);
        }
    }

    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/72D90", func_800763CC);
#endif

s16 GMesFontMesCreate(unkCommonStruct0* arg0, char* arg1, u8 arg2, s16 arg3, s16 arg4) {
    s16 i;

    for (i = 0; i < 16; i++) {
        arg0->unk_14[i] = -1;
        arg0->unk_34[i] = -1;
    }

    return GMesFontCreate(arg0, arg1, arg2, arg3, arg4);
}

// register allocation: retail loads the unused arg4 into s3 and copies w per loop (masked 24)
#ifdef NON_MATCHING
s16 GMesFontCreate(unkCommonStruct0* arg0, void* arg1, u8 arg2, s16 arg3, s16 arg4) {
    u16 hi;
    s16 id;
    u8* str;
    u8* p;
    s16 i;
    s16 len;
    s16 total;
    s16 x;
    s16 idx;
    u8 w;
    u32 v;

    str = arg1;
    len = func_8006D93C(str);

    for (i = 0; i < 16; i++) {
        if (arg0->unk_34[i] == -1 && arg0->unk_14[i] == -1) {
            break;
        }
    }

    id = arg0->unk_14[i] = func_80064EF4((u16)(len + 1), 5);

    w = 15;
    if (arg2 & 1) {
        w = 22;
    }

    p = str;
    for (total = 0; *p != 0; p++) {
        if ((u32)(*p - 'a') < 26) {
            total += 10;
        } else if (*p == '\\') {
            total += (w == 15) ? 4 : 8;
        } else if ((*p == 0x10) | (*p == ' ')) {
            total += (w == 15) ? 8 : 11;
        } else {
            total = w + total;
        }
    }

    x = -arg3;
    if (arg3 == -1) {
        x = (w >> 1) - total / 2;
    }

    for (idx = 1; *str != 0; idx++) {
        v = func_80076B2C(str, arg2);
        hi = v >> 16;
        func_80067208(id, idx, hi, v & 0xFF);
        func_80066DC4(id, idx, x, (u32)(*str - 'a') < 26);
        func_8006752C(id, idx, 255);
        func_80067384(id, idx, 5);
        func_80067480(id, idx, 0xFFFF);
        func_800674BC(id, idx, 0x1008);
        if ((u32)(*str - 'a') < 26) {
            x += 10;
        } else if (*str == '\\') {
            x += (w != 15) ? 12 : 8;
        } else if ((*str == 0x10) | (*str == ' ')) {
            x += (w == 15) ? 8 : 11;
        } else {
            x = w + x;
        }
        func_80067598(id, idx, 0);
        str += ((u8)(str[1] + 0x80) < 2) + 1;
    }

    func_80067208(id, 0, hi, 0);
    func_800674BC(id, 0, 0x8000);
    func_80067598(id, 0, -1);
    return i;
}
#else
INCLUDE_ASM("asm/nonmatchings/72D90", GMesFontCreate);
#endif

s32 func_80076B2C(u8* arg0, s32 arg1) {
    u16 var_v0;
    u16 var_a2;
    s16 var_v1;
    u8 temp_s0;
    u16 i;

    var_v1 = arg1;
    temp_s0 = arg0[0];

    if (temp_s0 >= 'A' && temp_s0 <= 'Z') {
        if (var_v1 & 1) {
            if (D_800F3768[0] == -1) {
                var_a2 = D_800F3768[0] = func_80076FF4(0x7D);
            } else {
                var_a2 = D_800F3768[0];
            }
        } else {
            if (D_800F3B70[0] == -1) {
                var_a2 = D_800F3B70[0] = func_80076FF4(0x7B);
            } else {
                var_a2 = D_800F3B70[0];
            }
        }
        var_v0 = temp_s0 - 'A';
    } else if (temp_s0 >= 'a' && temp_s0 <= 'z') {
        if (!(var_v1 & 1)) {
            if (D_800F3B70[1] == -1) {
                var_a2 = D_800F3B70[1] = func_80076FF4(0x88);
            } else {
                var_a2 = D_800F3B70[1];
            }
        }
        var_v0 = temp_s0 - 'a';
    } else if (temp_s0 >= '0' && temp_s0 <= '9') {
        if (var_v1 & 1) {
            if (D_800F3768[2] == -1) {
                var_a2 = D_800F3768[2] = func_80076FF4(0x7E);
            } else {
                var_a2 = D_800F3768[2];
            }
        } else {
            if (D_800F3B70[2] == -1) {
                var_a2 = D_800F3B70[2] = func_80076FF4(0x7C);
            } else {
                var_a2 = D_800F3B70[2];
            }
        }
        var_v0 = ASCII_DIGIT_TO_INT(temp_s0);
    } else if (temp_s0 >= 134 && temp_s0 <= 189) {
        if (var_v1 & 1) {
            return 0;
        }

        if (arg0[1] == 128 || arg0[1] == 129) {
            if (D_800F3B70[5] == -1) {
                var_a2 = D_800F3B70[5] = func_80076FF4(0x82);
            } else {
                var_a2 = D_800F3B70[5];
            }
            for (i = 0; i < 20; i++) {
                if (temp_s0 == D_800C6230[i]) {
                    break;
                }
            }
            if (arg0[1] == 129) {
                i += 5;
            }
        } else {
            if (D_800F3B70[4] == -1) {
                var_a2 = D_800F3B70[4] = func_80076FF4(0x81);
            } else {
                var_a2 = D_800F3B70[4];
            }
            for (i = 0; i < 55; i++) {
                if (temp_s0 == D_800C61F8[i]) {
                    break;
                }
            }
        }
        var_v0 = i;
    } else if (temp_s0 >= 198 && temp_s0 <= 253) {
        if (var_v1 & 1) {
            return 0;
        }

        if (arg0[1] == 128 || arg0[1] == 129) {
            if (D_800F3B70[7] == -1) {
                var_a2 = D_800F3B70[7] = func_80076FF4(0x84);
            } else {
                var_a2 = D_800F3B70[7];
            }
            temp_s0 -= 'A' - 1;
            for (i = 0; i < 20; i++) {
                if (temp_s0 == D_800C6230[i]) {
                    break;
                }
            }
            if (arg0[1] == 129) {
                i += 5;
            }
        } else {
            if (D_800F3B70[6] == -1) {
                var_a2 = D_800F3B70[6] = func_80076FF4(0x83);
            } else {
                var_a2 = D_800F3B70[6];
            }
            temp_s0 -= 'A' - 1;
            for (i = 0; i < 55; i++) {
                if (temp_s0 == D_800C61F8[i]) {
                    break;
                }
            }
        }
        var_v0 = i;
    } else {
        if (var_v1 & 1) {
            if (D_800F3768[3] == -1) {
                var_a2 = D_800F3768[3] = func_80076FF4(0x80);
            } else {
                var_a2 = D_800F3768[3];
            }
        } else {
            if (D_800F3B70[3] == -1) {
                var_a2 = D_800F3B70[3] = func_80076FF4(0x7F);
            } else {
                var_a2 = D_800F3B70[3];
            }
        }

        switch (temp_s0) {
            case 132:
                var_v0 = 2;
                break;
            case 194:
            case 196:
                var_v0 = 1;
                break;
            case 195:
            case 197:
                var_v0 = 3;
                break;
            case 61:
                var_v0 = 4;
                break;
            case 92:
                var_v0 = 5;
                break;
            case 0:
            case 32:
            default:
                var_v0 = 0;
                break;
        }
    }

    return (var_a2 << 16) | var_v0;
}

s16 func_80076FF4(s16 arg0) {
    void* temp_v0 = func_80014614(arg0);
    s16 temp_s0 = func_800678A4(temp_v0);

    DataCloseTemp(temp_v0);
    return temp_s0;
}

void func_80077044(unkCommonStruct0* arg0) {
    GMesSprKill(arg0);
    GMesSprClose();
}

s32 func_80077068(unkCommonStruct0* arg0, Gfx** arg1) {
    return func_800773EC(arg0, 720984, 1057);
}

s32 func_8007708C(unkCommonStruct0* arg0, char* arg1, s16 arg2) {
    f64 var_f2;
    f32 temp_f24;
    f32 temp_f30;
    f32 i;

    var_f2 = strlen(arg1);
    temp_f30 = var_f2;

    if (arg0->unk_04 == 0) {
        GMesFontCreate(arg0, arg1, 1, -1, -1);
        func_80066DC4(arg0->unk_14[0], 0, 160, arg0->unk_58);
        arg0->unk_08 = -1000;
        arg0->unk_0A = 300;
        PlaySound(arg2);
        omSysPauseEnableFlag = 1;
    }

    if (arg0->unk_04 > arg0->unk_06 || GMesCloseF != 0 || arg0->unk_01 == 4) {
        GMesSprKill(arg0);
        return 0;
    }

    if (arg0->unk_04 > arg0->unk_06 - 10) {
        arg0->unk_01 = 2;
        temp_f24 = arg0->unk_04 - (arg0->unk_06 - 10);

        for (i = 0.0f; i < temp_f30; i++) {
            func_80067354(arg0->unk_14[0], i + 1.0f, 1.8f - temp_f24 / 6.0f, 1.8f - temp_f24 / 6.0f);
            func_8006752C(arg0->unk_14[0], i + 1.0f, 255.0f - temp_f24 * 25.5f);
        }

        arg0->unk_08 += arg0->unk_0A;
        arg0->unk_58 += arg0->unk_08 / 100.0f;

        func_80066DC4(arg0->unk_14[0], 0, 160, arg0->unk_58);
    } else {
        for (i = 0.0f; i < temp_f30; i++) {
            func_80067354(arg0->unk_14[0], i + 1.0f, 1.8f, 1.8f);
        }
    }

    return 1;
}

s32 func_800773EC(unkCommonStruct0* arg0, s32 arg1, s16 arg2) {
    f32 temp_f22;
    s16 i;

    if (arg0->unk_04 == 0) {
        func_8007767C(arg0, arg1);
        arg0->unk_08 = -1000;
        arg0->unk_0A = 300;
        PlaySound(arg2);
        omSysPauseEnableFlag = 1;
    }

    if (arg0->unk_04 > arg0->unk_06 || GMesCloseF != 0 || arg0->unk_01 == 4) {
        GMesSprKill(arg0);
        return 0;
    }

    if (arg0->unk_04 > arg0->unk_06 - 10) {
        arg0->unk_01 = 2;
        temp_f22 = arg0->unk_04 - (arg0->unk_06 - 10);

        for (i = 0; i < 2; i++) {
            func_80067354(arg0->unk_14[0], i, 1.0f - temp_f22 / 10.0f, 1.0f - temp_f22 / 10.0f);
            func_8006752C(arg0->unk_14[0], i, 255.0f - temp_f22 * 25.5f);
        }

        arg0->unk_08 += arg0->unk_0A;
        arg0->unk_58 += arg0->unk_08 / 100.0f;

        func_80066DC4(arg0->unk_14[0], 0, 0xA0, arg0->unk_58);
    } else {
        for (i = 0; i < 2; i++) {
            func_80067354(arg0->unk_14[0], i, 1.0f, 1.0f);
        }
    }

    return 1;
}

void func_8007767C(unkCommonStruct0* arg0, s32 arg1) {
    void* temp_v0;
    s16 temp_v0_2;
    s16 temp_v0_4;
    s16 temp_v0_5;

    temp_v0 = func_80014614(arg1);
    arg0->unk_34[0] = temp_v0_2 = func_800678A4(temp_v0);
    DataCloseTemp(temp_v0);

    temp_v0 = func_80014614(arg1 + 1);
    arg0->unk_34[1] = temp_v0_4 = func_800678A4(temp_v0);
    DataCloseTemp(temp_v0);

    arg0->unk_14[0] = temp_v0_5 = func_80064EF4(2, 5);

    func_80067208(temp_v0_5, 0, temp_v0_2, 0);
    func_8006752C(temp_v0_5, 0, 0xFF);
    func_80067384(temp_v0_5, 0, 5);
    func_80067480(temp_v0_5, 0, 0xFFFF);
    func_800674BC(temp_v0_5, 0, 0x1008);
    func_80066DC4(temp_v0_5, 0, 0xA0, arg0->unk_58);
    func_80067598(temp_v0_5, 0, -1);
    func_80067208(temp_v0_5, 1, temp_v0_4, 0);
    func_8006752C(temp_v0_5, 1, 0xFF);
    func_80067384(temp_v0_5, 1, 6);
    func_80067480(temp_v0_5, 1, 0xFFFF);
    func_800674BC(temp_v0_5, 1, 0x1008);
    func_800674F4(temp_v0_5, 1, 0x45, 2, 0x85);
    func_80067598(temp_v0_5, 1, 0);
}

const char D_800CBA40[] = "ALL";

const char D_800CBA44[] = "DK";

const char D_800CBA48[] = "WARIO";

const char D_800CBA50[] = "YOSHI";

const char D_800CBA58[] = "PEACH";

const char D_800CBA60[] = "LUIGI";

const char D_800CBA68[] = "MARIO";

s32 func_80077838(unkCommonStruct0* arg0, Gfx** arg1) {
    char sp18[] = "WINS\xC4"; // D_800CBA70
    f64 var_f2;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f22_2;
    f32 temp_f22_3;
    f32 temp_f24;
    f32 temp_f30;
    f32 i;

    var_f2 = strlen(D_800C624C[arg0->unk_08]);
    temp_f24 = var_f2;

    var_f2 = strlen(sp18);
    temp_f30 = var_f2;

    if (arg0->unk_04 == 0) {
        GMesFontCreate(arg0, D_800C624C[arg0->unk_08], 1, -1, -1);
        GMesFontCreate(arg0, sp18, 1, -1, -1);

        temp_f22 = temp_f24 + temp_f30 + 1.0f;
        temp_f20 = (320.0f - temp_f22 * 24.0f) / 2.0f;

        var_f2 = strlen(D_800C624C[arg0->unk_08]) * 12;
        temp_f20 += (f32) var_f2;

        func_80066DC4(arg0->unk_14[0], 0, temp_f20, arg0->unk_58 + 40.0f);

        temp_f20 = 320.0f - (320.0f - temp_f22 * 24.0f) / 2.0f;

        var_f2  = strlen(sp18) * 0xC;
        temp_f20 -= (f32) var_f2;

        func_80066DC4(arg0->unk_14[1], 0, temp_f20, arg0->unk_58 + 40.0f);

        for (i = 0.0f; i < temp_f24; i++) {
            func_800674BC(arg0->unk_14[0], i + 1.0f, 0x8000);
        }

        for (i = 0.0f; i < temp_f30; i++) {
            func_800674BC(arg0->unk_14[1], i + 1.0f, 0x8000);
        }
    }

    if (GMesCloseF != 0 || arg0->unk_01 == 4) {
        GMesSprKill(arg0);
        return 0;
    }

    temp_f22_2 = arg0->unk_04 - 20;
    temp_f22_2 = func_800AEAC0(temp_f22_2 * 10.0f) / 8.0f + 1.0f;

    for (i = 0.0f; i < temp_f24; i++) {
        func_80067354(arg0->unk_14[0], i + 1.0f, temp_f22_2, temp_f22_2);
    }

    for (i = 0.0f; i < temp_f30; i++) {
        func_80067354(arg0->unk_14[1], i + 1.0f, temp_f22_2, temp_f22_2);
    }

    if (arg0->unk_04 >= 51) {
        arg0->unk_01 = 2;
    }

    if (arg0->unk_04 >= 21) {
        return 1;
    }

    temp_f22_3 = arg0->unk_04;
    if (temp_f22_3 <= 15.0f) {
        for (i = 0.0f; i < temp_f24; i++) {
            func_80067480(arg0->unk_14[0], i + 1.0f, 0x8000);
            func_80067354(arg0->unk_14[0], i + 1.0f, 5.0f - temp_f22_3 / 15.0f * 4.0f, 5.0f - temp_f22_3 / 15.0f * 4.0f);
            func_8006752C(arg0->unk_14[0], i + 1.0f, temp_f22_3 * 17.0f);
        }
    }

    temp_f22_3 = arg0->unk_04 - 5;
    if (temp_f22_3 <= 15.0f && temp_f22_3 > 0.0f) {
        for (i = 0.0f; i < temp_f30; i++) {
            func_80067480(arg0->unk_14[1], i + 1.0f, 0x8000);
            func_80067354(arg0->unk_14[1], i + 1.0f, 5.0f - temp_f22_3 / 15.0f * 4.0f, 5.0f - temp_f22_3 / 15.0f * 4.0f);
            func_8006752C(arg0->unk_14[1], i + 1.0f, temp_f22_3 * 17.0f);
        }
    }

    return 1;
}


s32 func_80077FC4(unkCommonStruct0* arg0, Gfx** arg1) {
    char sp18[] = "LOSES";
    f64 var_f2;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f2;
    f32 temp_f30;
    s16 i;

    var_f2 = strlen(D_800C624C[arg0->unk_08]);
    temp_f30 = var_f2;

    var_f2 = strlen(sp18);
    temp_f2 = var_f2;

    if (arg0->unk_04 == 0) {
        GMesFontCreate(arg0, D_800C624C[arg0->unk_08], 1, -1, -1);
        GMesFontCreate(arg0, sp18, 1, -1, -1);

        temp_f20 = (320.0f - (temp_f30 + temp_f2 + 1.0f) * 24.0f) / 2.0f;

        func_80066DC4(arg0->unk_14[0], 0, temp_f20 + temp_f30 * 24.0f / 2.0f, arg0->unk_58 + 40.0f);
        func_80066DC4(arg0->unk_14[1], 0, (320.0f - temp_f20) - temp_f2 * 24.0f / 2.0f, arg0->unk_58 + 40.0f);

        for (i = 0; i < temp_f30; i++) {
            func_800674BC(arg0->unk_14[0], i + 1, 0x8000);
        }

        for (i = 0; i < temp_f2; i++) {
            func_800674BC(arg0->unk_14[1], i + 1, 0x8000);
        }

        arg0->unk_0A = 0;
    }

    if (GMesCloseF != 0 || arg0->unk_01 == 4) {
        GMesSprKill(arg0);
        return 0;
    }

    if (arg0->unk_04 >= 81) {
        arg0->unk_01 = 2;
    }

    if (arg0->unk_04 >= 51) {
        arg0->unk_0A++;
        if (arg0->unk_0A & 0x40) {
            temp_f20_3 = (u16) arg0->unk_0A % 32;
            temp_f20_2 = func_800AEFD0(temp_f20_3 * (360.0f / 31)) * 55.0f + 200.0f;

            for (i = 0; i < temp_f30; i++) {
                func_8006752C(arg0->unk_14[0], i + 1, temp_f20_2);
            }

            for (i = 0; i < temp_f2; i++) {
                func_8006752C(arg0->unk_14[1], i + 1, temp_f20_2);
            }
        }

        return 1;
    }

    temp_f20_3 = arg0->unk_04;
    if (temp_f20_3 <= 30.0f) {
        for (i = 0; i < temp_f30; i++) {
            func_80067480(arg0->unk_14[0], i + 1, 0x8000);
            func_8006752C(arg0->unk_14[0], i + 1, temp_f20_3 * 8.5f);
        }
    }

    temp_f20_3 = arg0->unk_04 - 20;
    if (temp_f20_3 <= 30.0f && temp_f20_3 > 0.0f) {
        for (i = 0; i < temp_f2; i++) {
            func_80067480(arg0->unk_14[1], i + 1, 0x8000);
            func_8006752C(arg0->unk_14[1], i + 1, temp_f20_3 * 8.5f);
        }
    }

    return 1;
}

s32 func_800786F0(unkCommonStruct0* arg0, Gfx** arg1) {
    f32 temp_f22;
    f32 i;

    if (arg0->unk_04 == 0) {
        char* temp_v0 = HuMemDirectMalloc(256);

        func_8007149C((u8*) temp_v0, arg0->unk_10);
        GMesFontCreate(arg0, temp_v0, arg0->unk_02, -1, -1);
        arg0->unk_08 = strlen(temp_v0);
        func_80066DC4(arg0->unk_14[0], 0, arg0->unk_54, arg0->unk_58);

        HuMemDirectFree(temp_v0);
    }

    if (arg0->unk_04 > arg0->unk_06 || GMesCloseF != 0 || arg0->unk_01 == 4) {
        GMesSprKill(arg0);
        return 0;
    }

    if (arg0->unk_04 < 14) {
        temp_f22 = func_800AEAC0(arg0->unk_04 * 10.0f) + (1.0f - func_800AEAC0(130.0f));

        for (i = 0.0f; i < arg0->unk_08; i++) {
            func_80067354(arg0->unk_14[0], i + 1.0f, arg0->unk_5C, temp_f22 * arg0->unk_60);
        }
    }

    if (arg0->unk_04 > arg0->unk_06 - 10) {
        arg0->unk_01 = 2;
        temp_f22 = func_800AEFD0((arg0->unk_04 - (arg0->unk_06 - 10)) * 9.0f);

        for (i = 0.0f; i < arg0->unk_08; i++) {
            func_80067354(arg0->unk_14[0], i + 1.0f, arg0->unk_5C, temp_f22 * arg0->unk_60);
        }
    }

    return 1;
}

s32 func_800789C0(unkCommonStruct0* arg0, Gfx** arg1) {
    f32 i;

    if (arg0->unk_04 == 0) {
        char* temp_v0 = HuMemDirectMalloc(256);

        func_8007149C((u8*) temp_v0, arg0->unk_10);
        GMesFontCreate(arg0, temp_v0, arg0->unk_02, -1, -1);
        arg0->unk_08 = strlen(temp_v0);

        HuMemDirectFree(temp_v0);
    }

    if (arg0->unk_04 > arg0->unk_06 || GMesCloseF != 0 || arg0->unk_01 == 4) {
        GMesSprKill(arg0);
        return 0;
    }

    func_80066DC4(arg0->unk_14[0], 0, arg0->unk_54, arg0->unk_58);
    func_800673B0(arg0->unk_14[0], 0, arg0->unk_64);

    for (i = 0.0f; i < arg0->unk_08; i++) {
        func_80067354(arg0->unk_14[0], i + 1.0f, arg0->unk_5C, arg0->unk_60);
        func_8006752C(arg0->unk_14[0], i + 1.0f, arg0->unk_03);
    }

    return 1;
}

s32 func_80078B6C(unkCommonStruct0* arg0, Gfx** arg1) {
    f32 temp_f22;
    u8 temp_s0;
    u8 temp_s2;

    if (arg0->unk_04 == 0) {
        GMesFontCreate(arg0, "99", 0, -1, -1);
        func_80066DC4(arg0->unk_14[0], 0, arg0->unk_54, arg0->unk_58);
        func_8006752C(arg0->unk_14[0], 1, 230);
        func_8006752C(arg0->unk_14[0], 2, 230);
        arg0->unk_0A = 0;
    }

    temp_s2 = arg0->unk_08 % 100;

    temp_s0 = temp_s2 / 10;
    if (temp_s0 == 0) {
        func_800674BC(arg0->unk_14[0], 1, 0x8000);
    } else {
        func_80067480(arg0->unk_14[0], 1, 0x8000);
    }
    func_800672DC(arg0->unk_14[0], 1, temp_s0, 0);
    func_800672B0(arg0->unk_14[0], 1, 1);

    temp_s0 = temp_s2 % 10;
    func_800672DC(arg0->unk_14[0], 2, temp_s0, 0);
    func_800672B0(arg0->unk_14[0], 2, 1);

    switch (arg0->unk_0A) {
        case 0:
            if (arg0->unk_04 < 14) {
                temp_f22 = func_800AEAC0(arg0->unk_04 * 10.0f) * 5.0f + (1.0f - func_800AEAC0(130.0f) * 5.0f);
                func_80067354(arg0->unk_14[0], 1, temp_f22, temp_f22);
                func_80067354(arg0->unk_14[0], 2, temp_f22, temp_f22);
            } else {
                arg0->unk_0A = 1;
            }
            break;
        case 1:
            if (arg0->unk_0E != arg0->unk_08 && arg0->unk_08 < 6) {
                arg0->unk_0C = 0;
                arg0->unk_0A = 3;
                if (arg0->unk_08 != 0) {
                    PlaySound(0xFB);
                }
            }
            break;
        case 2:
            if (arg0->unk_0C < 10) {
                func_8006752C(arg0->unk_14[0], 1, 230 - arg0->unk_0C * 23);
                func_8006752C(arg0->unk_14[0], 2, 230 - arg0->unk_0C * 23);
            } else {
                arg0->unk_0A = 1;
                arg0->unk_01 = 4;
            }
            arg0->unk_0C++;
            break;
        case 3:
            if (arg0->unk_0C < 11) {
                temp_f22 = func_800AEAC0(arg0->unk_0C * 18.0f) + 1.0f;
                func_80067354(arg0->unk_14[0], 1, temp_f22, temp_f22);
                func_80067354(arg0->unk_14[0], 2, temp_f22, temp_f22);

                temp_f22 = 230.0f - func_800AEAC0(arg0->unk_0C * 18.0f) * 60.0f;
                func_8006752C(arg0->unk_14[0], 1, temp_f22);
                func_8006752C(arg0->unk_14[0], 2, temp_f22);
            } else {
                arg0->unk_0A = 1;
            }
            arg0->unk_0C++;
            break;
    }

    arg0->unk_0E = arg0->unk_08;

    if (GMesCloseF != 0 || arg0->unk_01 == 4) {
        GMesSprKill(arg0);
        D_800F3FFC = -1;
        return 0;
    }

    return 1;
}

void func_80079078(s16 arg0) {
    // Checks if both sign bits are zero. Seems some kind of compiler optimization.
    if ((((u32) D_800F3FFC >> 31) | ((u32) (arg0 << 16) >> 31)) == 0) {
        GMesData[D_800F3FFC].unk_08 = arg0;
    }
}

void func_800790C0(void) {
    if (D_800F3FFC >= 0) {
        GMesData[D_800F3FFC].unk_0A = 2;
        GMesData[D_800F3FFC].unk_0C = 0;
    }
}

s32 func_80079104(unkCommonStruct0* arg0, Gfx** arg1) {
    return func_80079128(arg0, "GREAT\xC4", -1);
}

s32 func_80079128(unkCommonStruct0* arg0, char* arg1, s16 arg2) {
    f32 a;
    f32 x;
    f32 y;
    f32 b;
    s16 i;
    u16 t;
    f32 c;
    f32 c2;
    f32 nb;
    f32 y2;

    if (arg0->unk_04 == 0) {
        GMesFontCreate(arg0, arg1, 1, -1, -1);
        func_80066DC4(arg0->unk_14[0], 0, arg0->unk_54, arg0->unk_58);
        arg0->unk_08 = strlen(arg1);
        for (i = 0; i < arg0->unk_08; i++) {
            func_800674BC(arg0->unk_14[0], i + 1, 0x8000);
        }
        omSysPauseEnableFlag = 1;
    }

    if (GMesCloseF != 0 || arg0->unk_01 == 4) {
        GMesSprKill(arg0);
        return 0;
    }

    if ((arg0->unk_04 == 20) & (arg2 != -1)) {
        PlaySound(arg2);
    }

    if (arg0->unk_04 >= 69) {
        arg0->unk_01 = 2;
    }

    if (arg0->unk_04 > 20 && arg0->unk_04 < 39) {
        t = arg0->unk_04 - 20;
        for (i = 0; i < arg0->unk_08; i++) {
            func_80067354(arg0->unk_14[0], i + 1, func_800AEAC0((s16)t * 10) * 0.5f + 1.0, func_800AEAC0((s16)t * 10) * 0.5f + 1.0);
        }
    } else if (arg0->unk_04 < 16) {
        for (i = 0; i < arg0->unk_08; i++) {
            t = arg0->unk_04;
            if (t >= 15) {
                func_80066DC4(arg0->unk_14[0], i + 1, -(arg0->unk_08 * 22) / 2 + i * 22 + 12, 0);
            } else {
                a = func_800AEAC0(i * 10 + 430) * 100.0f;
                c = arg0->unk_08 * -11 + 12;
                if (!(i & 1)) {
                    a = -a;
                }
                x = c - a;
                y = -(func_800AEFD0(i * 20 + 430) * 50.0f);
                func_80067480(arg0->unk_14[0], i + 1, 0x8000);
                b = (15 - (s16)t) * 10 + func_800AEAC0((s16)t * 20 + 130 + i * 10) * 100.0f;
                c2 = x + i * 22;
                if (!(i & 1)) {
                    nb = -b;
                    x = c2 + nb;
                } else {
                    x = c2 + b;
                }
                y2 = y + func_800AEFD0((s16)t * 20 + 130 + i * 20) * 50.0f;
                func_80066DC4(arg0->unk_14[0], i + 1, x, y2);
            }
        }
    }

    return 1;
}

s32 func_80079608(unkCommonStruct0* arg0, Gfx** arg1) {
    return func_80079128(arg0, "BRAVO\xC4", -1);
}

s32 func_8007962C(unkCommonStruct0* arg0, Gfx** arg1) {
    return func_80079128(arg0, "STRIKE\xC4", 0x41D);
}

s32 func_80079650(unkCommonStruct0* arg0, Gfx** arg1) {
    f32 temp_f20;
    s16 var_s4 = 10;
    s16 i;

    if (arg0->unk_04 == 0) {
        GMesFontCreate(arg0, "NEW RECORD", 1, -1, -1);
        for (i = 0; i < var_s4; i++) {
            func_800674BC(arg0->unk_14[0], i + 1, 0x8000);
            func_80067354(arg0->unk_14[0], i + 1, 1.0f, 1.0f);
        }
        func_80066DC4(arg0->unk_14[0], 0, arg0->unk_54, arg0->unk_58);
        omSysPauseEnableFlag = 1;
    }

    if (GMesCloseF != 0 || arg0->unk_01 == 4) {
        GMesSprKill(arg0);
        return 0;
    }

    if (arg0->unk_04 == 10) {
        PlaySound(0x41E);
    }

    if (arg0->unk_04 < 20) {
        temp_f20 = func_800AEAC0(arg0->unk_04 * 7) * 1.5f;
        for (i = 0; i < var_s4; i++) {
            func_80067354(arg0->unk_14[0], i + 1, 1.0f, temp_f20);
            func_80067480(arg0->unk_14[0], i + 1, 0x8000);
        }
    } else if (arg0->unk_04 >= 31) {
        arg0->unk_01 = 2;
    }

    return 1;
}

s32 func_8007983C(unkCommonStruct0* arg0, Gfx** arg1) {
    return func_800773EC(arg0, 0xB005A, 0x425);
}

s32 func_80079860(unkCommonStruct0* arg0, Gfx** arg1) {
    return func_800773EC(arg0, 0xB005C, 0x420);
}

s32 func_80079884(unkCommonStruct0* arg0, Gfx** arg1) {
    f32 temp_f20;
    s16 i;

    if (arg0->unk_04 == 0) {
        func_8007767C(arg0, 0xB0060);
        for (i = 0; i < 2; i++) {
            func_80067354(arg0->unk_14[0], i, 1.0f, 1.0f);
        }
        func_80066DC4(arg0->unk_14[0], 0, arg0->unk_54, arg0->unk_58);
        arg0->unk_08 = 0;
        omSysPauseEnableFlag = 1;
    }

    if (GMesCloseF != 0 || arg0->unk_01 == 4) {
        GMesSprKill(arg0);
        return 0;
    }

    if (arg0->unk_04 == 30) {
        PlaySound(0x422);
    }

    if (arg0->unk_04 == 50) {
        arg0->unk_01 = 2;
    }

    if (arg0->unk_04 < 50) {
        temp_f20 = arg0->unk_04 * 5.1f;
        for (i = 0; i < 2; i++) {
            func_8006752C(arg0->unk_14[0], i, temp_f20);
        }
    } else if (arg0->unk_04 > 120) {
        arg0->unk_08 += 20;
        temp_f20 = func_800AEFD0(arg0->unk_08) * 55.0f + 200.0f;
        for (i = 0; i < 2; i++) {
            func_8006752C(arg0->unk_14[0], i, temp_f20);
        }
    }

    return 1;
}

s32 func_80079B2C(unkCommonStruct0* arg0, Gfx** arg1) {
    f32 temp_f20;
    f32 temp_f22;
    s16 var_s5;
    s16 var_s6;
    s16 i;

    var_s5 = 5;
    var_s6 = 3;

    if (arg0->unk_04 == 0) {
        GMesFontCreate(arg0, "READY", 1, -1, -1);
        GMesFontCreate(arg0, "GO\xC4", 1, -1, -1);

        for (i = 0; i < var_s5; i++) {
            func_80067354(arg0->unk_14[0], i + 1, 5.0f, 5.0f);
        }
        for (i = 0; i < var_s6; i++) {
            func_800674BC(arg0->unk_14[1], i + 1, 0x8000);
        }

        func_80066DC4(arg0->unk_14[0], 0, arg0->unk_54, arg0->unk_58);
        func_80066DC4(arg0->unk_14[1], 0, arg0->unk_54, arg0->unk_58);

        arg0->unk_08 = arg0->unk_0A = 0;
    }

    if (arg0->unk_04 >= 56 || GMesCloseF != 0 || arg0->unk_01 == 4) {
        GMesSprKill(arg0);
        omSysPauseEnableFlag = 0;
        return 0;
    }

    if (arg0->unk_04 == 10) {
        PlaySound(0x41B);
    }

    if (arg0->unk_04 <= 10) {
        temp_f22 = (10 - arg0->unk_04) * 0.4f + 1.5f;
        temp_f20 = arg0->unk_04 * 25;

        for (i = 0; i < var_s5; i++) {
            func_8006752C(arg0->unk_14[0], i + 1, temp_f20);
            func_80067354(arg0->unk_14[0], i + 1, temp_f22, temp_f22);
        }

        return 1;
    }

    if (arg0->unk_04 == 35) {
        PlaySound(0x41C);
    }

    if (arg0->unk_04 == 50) {
        PlaySound(D_800C61B8[D_800C61C0[GwSystem.unk_1E]]);
    }

    if (arg0->unk_04 >= 31 && arg0->unk_04 <= 40) {
        arg0->unk_5C = arg0->unk_60 = func_800AEAC0(arg0->unk_08 * 15) * 3.0f;
        temp_f20 = (10 - arg0->unk_08) * 25;

        for (i = 0; i < var_s5; i++) {
            if (temp_f20 < 10.0f) {
                func_800674BC(arg0->unk_14[0], i + 1, 0x8000);
            } else {
                func_8006752C(arg0->unk_14[0], i + 1, temp_f20);
            }
        }

        for (i = 0; i < var_s6; i++) {
            func_80067480(arg0->unk_14[1], i + 1, 0x8000);
            func_80067354(arg0->unk_14[1], i + 1, arg0->unk_5C, arg0->unk_60);
        }

        arg0->unk_08++;
    } else if (arg0->unk_04 >= 51) {
        arg0->unk_01 = 2;
        arg0->unk_5C += 0.2f;
        arg0->unk_60 += 0.2f;
        temp_f20 = (5 - arg0->unk_0A) * 51;

        for (i = 0; i < var_s6; i++) {
            func_8006752C(arg0->unk_14[1], i + 1, temp_f20);
            func_80067354(arg0->unk_14[1], i + 1, arg0->unk_5C, arg0->unk_60);
        }

        arg0->unk_0A++;
    }

    return 1;
}

s32 func_8007A0FC(unkCommonStruct0* arg0, Gfx** arg1) {
    f32 scale;
    f32 alpha;
    f32 dx;
    s16 n;
    s16 len0;
    s16 len1;
    s16 i;
    s32 d;

    n = 5;
    len0 = strlen(D_800C624C[arg0->unk_08]);
    len1 = strlen(D_800C624C[arg0->unk_0A]);

    if (arg0->unk_04 == 0) {
        GMesFontCreate(arg0, D_800C624C[arg0->unk_08], 1, -1, -1);
        GMesFontCreate(arg0, D_800C624C[arg0->unk_0A], 1, -1, -1);
        GMesFontCreate(arg0, "WINS\xC4", 1, -1, -1);
        for (i = 0; i < len0; i++) {
            func_80067354(arg0->unk_14[0], i + 1, 5.0f, 5.0f);
        }
        for (i = 0; i < len1; i++) {
            func_80067354(arg0->unk_14[1], i + 1, 5.0f, 5.0f);
        }
        for (i = 0; i < n; i++) {
            func_800674BC(arg0->unk_14[2], i + 1, 0x8000);
        }
        func_80066DC4(arg0->unk_14[0], 0, 288, arg0->unk_58);
        func_80066DC4(arg0->unk_14[1], 0, 32, arg0->unk_58);
        func_80066DC4(arg0->unk_14[2], 0, 160, arg0->unk_58 + 40.0f);
    }

    if (GMesCloseF != 0 || arg0->unk_01 == 4) {
        GMesSprKill(arg0);
        return 0;
    }

    if (arg0->unk_04 <= 20) {
        scale = (20 - arg0->unk_04) * 0.4f + 1.0f;
        alpha = arg0->unk_04 * 12;
        dx = arg0->unk_04 * 10;
        func_80066DC4(arg0->unk_14[0], 0, 320.0f - (dx + 32.0f), arg0->unk_58);
        for (i = 0; i < len0; i++) {
            func_8006752C(arg0->unk_14[0], i + 1, alpha);
            func_80067354(arg0->unk_14[0], i + 1, scale, scale);
        }
        func_80066DC4(arg0->unk_14[1], 0, dx + 32.0f, arg0->unk_58);
        for (i = 0; i < len1; i++) {
            func_8006752C(arg0->unk_14[1], i + 1, alpha);
            func_80067354(arg0->unk_14[1], i + 1, scale, scale);
        }
    } else if (arg0->unk_04 >= 31 && arg0->unk_04 <= 50) {
        if (arg0->unk_04 <= 40) {
            d = arg0->unk_04 - 30;
            alpha = d * 25;
            func_800673B0(arg0->unk_14[2], 0, d * 36);
            for (i = 0; i < n; i++) {
                func_80067480(arg0->unk_14[2], i + 1, 0x8000);
                func_8006752C(arg0->unk_14[2], i + 1, alpha);
            }
        } else {
            scale = func_800AEAC0((arg0->unk_04 - 40) * 18) + 1.0f;
            for (i = 0; i < n; i++) {
                func_80067354(arg0->unk_14[2], i + 1, scale, scale);
            }
        }
    } else if (arg0->unk_04 >= 81) {
        arg0->unk_01 = 2;
    }

    return 1;
}

s32 func_8007A7A4(unkCommonStruct0* arg0, Gfx** arg1) {
    f32 temp_f20;
    s16 i;

    if (arg0->unk_04 == 0) {
        func_8007767C(arg0, 0xB005E);
        for (i = 0; i < 2; i++) {
            func_800674BC(arg0->unk_14[0], i, 0x8000);
            func_80067354(arg0->unk_14[0], i, 1.0f, 1.0f);
        }
        func_80066DC4(arg0->unk_14[0], 0, arg0->unk_54, arg0->unk_58);
        omSysPauseEnableFlag = 1;
    }

    if (GMesCloseF != 0 || arg0->unk_01 == 4) {
        GMesSprKill(arg0);
        return 0;
    }

    if (arg0->unk_04 == 10) {
        PlaySound(0x423);
    }

    if (arg0->unk_04 < 20) {
        temp_f20 = func_800AEAC0(arg0->unk_04 * 7) * 1.5f;
        for (i = 0; i < 2; i++) {
            func_80067354(arg0->unk_14[0], i, 1.0f, temp_f20);
            func_80067480(arg0->unk_14[0], i, 0x8000);
        }
    } else if (arg0->unk_04 >= 51) {
        arg0->unk_01 = 2;
    }

    return 1;
}

s32 func_8007A978(unkCommonStruct0* arg0, Gfx** arg1) {
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f26;
    s16 temp_s5;
    s16 temp_s6;
    s16 temp_s7;
    s16 temp_s8;
    s16 i;

    temp_s6 = strlen(D_800C624C[arg0->unk_08]);
    temp_s5 = strlen(D_800C624C[arg0->unk_0A]);
    temp_s7 = strlen(D_800C624C[arg0->unk_0C]);
    temp_s8 = 5;

    if (arg0->unk_04 == 0) {
        GMesFontCreate(arg0, D_800C624C[arg0->unk_08], 1, -1, -1);
        GMesFontCreate(arg0, D_800C624C[arg0->unk_0A], 1, -1, -1);
        GMesFontCreate(arg0, D_800C624C[arg0->unk_0C], 1, -1, -1);
        GMesFontCreate(arg0, "WINS\xC4", 1, -1, -1);

        for (i = 0; i < temp_s6; i++) {
            func_80067354(arg0->unk_14[0], i + 1, 5.0f, 5.0f);
        }
        for (i = 0; i < temp_s5; i++) {
            func_80067354(arg0->unk_14[1], i + 1, 5.0f, 5.0f);
        }
        for (i = 0; i < temp_s7; i++) {
            func_80067354(arg0->unk_14[2], i + 1, 5.0f, 5.0f);
        }
        for (i = 0; i < temp_s8; i++) {
            func_800674BC(arg0->unk_14[3], i + 1, 0x8000);
        }

        func_80066DC4(arg0->unk_14[0], 0, 0x120, arg0->unk_58 - 48.0f);
        func_80066DC4(arg0->unk_14[1], 0, 0xA0, arg0->unk_58 - 24.0f);
        func_80066DC4(arg0->unk_14[2], 0, 0x20, arg0->unk_58);
        func_80066DC4(arg0->unk_14[3], 0, 0xA0, arg0->unk_58 + 24.0f);
    }

    if (GMesCloseF != 0 || arg0->unk_01 == 4) {
        GMesSprKill(arg0);
        return 0;
    }

    if (arg0->unk_04 < 21) {
        temp_f22 = (20 - arg0->unk_04) * 0.4f + 1.0f;
        temp_f26 = temp_f20 = arg0->unk_04 * 12;

        func_80066DC4(arg0->unk_14[0], 0, 320.0f - temp_f20, arg0->unk_58 - 48.0f);

        for (i = 0; i < temp_s6; i++) {
            func_8006752C(arg0->unk_14[0], i + 1, temp_f20);
            func_80067354(arg0->unk_14[0], i + 1, temp_f22, temp_f22);
        }
        for (i = 0; i < temp_s5; i++) {
            func_8006752C(arg0->unk_14[1], i + 1, temp_f20);
            func_80067354(arg0->unk_14[1], i + 1, temp_f22, temp_f22);
        }

        func_80066DC4(arg0->unk_14[2], 0, temp_f26, arg0->unk_58);

        for (i = 0; i < temp_s7; i++) {
            func_8006752C(arg0->unk_14[2], i + 1, temp_f20);
            func_80067354(arg0->unk_14[2], i + 1, temp_f22, temp_f22);
        }
    } else if (arg0->unk_04 >= 41 && arg0->unk_04 <= 60) {
        if (arg0->unk_04 < 51) {
            temp_f20 = (arg0->unk_04 - 40) * 25;

            func_800673B0(arg0->unk_14[3], 0, (arg0->unk_04 - 40) * 36);

            for (i = 0; i < temp_s8; i++) {
                func_80067480(arg0->unk_14[3], i + 1, 0x8000);
                func_8006752C(arg0->unk_14[3], i + 1, temp_f20);
            }
        } else {
            temp_f22 = func_800AEAC0((arg0->unk_04 - 50) * 18) + 1.0f;

            for (i = 0; i < temp_s8; i++) {
                func_80067354(arg0->unk_14[3], i + 1, temp_f22, temp_f22);
            }
        }
    } else if (arg0->unk_04 >= 81) {
        arg0->unk_01 = 2;
    }

    return 1;
}

// First arg is a u8*
void func_8007B168(u8* arg0, u8 arg1) {
    u8* temp_v0;
    u8* var_s1;

    var_s1 = temp_v0 = HuMemDirectMalloc(512);
    func_8007149C(temp_v0, arg0);

    for (; *var_s1 != 0; var_s1++) {
        func_80076B2C(var_s1, arg1);
        if (var_s1[1] == 128 || var_s1[1] == 129) {
            var_s1++;
        }
    }

    D_800F3753 = 1;
    HuMemDirectFree(temp_v0);
}

void func_8007B210(void) {
    Gfx* sp10;

    D_800E4340 = func_80023668(153664);
    sp10 = D_800E434C = func_80023668(6400);

    D_800E4344 = ((s32) D_800E4340 + 63) & ~63;
    D_800E4350 = func_8002451C(0, (&func_8007B420), 6);

    gSPDisplayList(sp10++, D_800C6108);
    func_80072C34(&sp10, D_800E4344);
    gSPEndDisplayList(sp10);

    D_800E4348 = 0;
}

s32 func_8007B2CC(void) {
    if (D_800E4348 >= 0 && D_800E4348 < 3) {
        return 0;
    }

    func_80023888(D_800E434C);
    func_8002456C(D_800E4350);

    return 1;
}

void func_8007B310(void) {
    Gfx* sp10;

    sp10 = D_800E434C = func_80023668(6400);
    D_800E4352 = func_8002451C(0, (&func_8007B458), 0);

    gSPDisplayList(sp10++, D_800C6108);
    gDPSetCombineMode(sp10++, G_CC_MODULATEI_PRIM, G_CC_MODULATEI_PRIM);
    gDPSetRenderMode(sp10++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    gDPSetPrimColor(sp10++, 0, 0, 255, 255, 255, 128);

    func_80072E5C(&sp10, D_800E4344);
    gSPEndDisplayList(sp10);
}

void func_8007B3E8(void) {
    func_80023888(D_800E434C);
    func_80023888(D_800E4340);
    func_8002456C(D_800E4352);
}

void func_8007B420(Gfx** arg0) {
    gSPDisplayList((*arg0)++, D_800E434C);
    D_800E4348++;
}

void func_8007B458(Gfx** arg0) {
    gSPDisplayList((*arg0)++, D_800E434C);
}

void func_8007B47C(void) {
    D_800E4340 = D_800C6104;
    D_800E4344 = D_800F545C;
    D_800F50B8 = 1;
}

void func_8007B4AC(void) {
    func_80023888(D_800E434C);
    HuMemDirectFree(D_800E4340);
    func_8002456C(D_800E4352);
    D_800F50B8 = 0;
}

void GamePauseStart(void) {
    D_800F0A24 = omAddPrcObj(func_8007B52C, 0x3FFF, 0x800, 0);
    omPrcSetStatBit(D_800F0A24, 0xA0);
}

void func_8007B52C(void) {
    void* temp_v0_12;
    s16 temp_fp;
    s16 temp_s0;
    s16 temp_v0;
    s16 var_s6;
    s16 var_a0;
    s8 var_s2;
    s8 var_s3;
    s16 i;

    HuPrcSleep(2);

    D_800ECC22 = 1;
    temp_fp = GwSystem.unk_1E;
    temp_s0 = D_800C6268[GwSystem.unk_1E].unk_04 == 0 ? 110 : 70;
    temp_v0 = func_8007BCA8(60, temp_s0);
    D_800F2CE0 = func_8006DD8C(temp_v0, D_800ED4B0[temp_v0].unk_274);

    if (D_800C6268[temp_fp].unk_04 != 0) {
        var_s6 = func_8007BCA8(60, temp_s0 + 70);
        D_800F64F4 = func_8006DD8C(var_s6, D_800ED4B0[var_s6].unk_274);

        if (D_800C6268[temp_fp].unk_00 == 2) {
            for (i = 0, var_a0 = 0; i < MAX_PLAYERS; i++) {
                if (var_a0 < GwPlayer[i].group) {
                    var_a0 = GwPlayer[i].group;
                }
            }

            if (var_a0 < 2) {
                var_s3 = 0;
                var_s2 = 2;
                for (i = 0; i < MAX_PLAYERS; i++) {
                    if (GwPlayer[i].group == 0) {
                        func_8006DA5C(temp_v0, (void*) (s32) GwPlayer[i].character + 44, var_s3);
                        func_8006DA5C(var_s6, (void*) (s32) GwPlayer[i].character + 44, var_s3++);
                    } else {
                        func_8006DA5C(temp_v0, (void*) (s32) GwPlayer[i].character + 44, var_s2);
                        func_8006DA5C(var_s6, (void*) (s32) GwPlayer[i].character + 44, var_s2++);
                    }
                }
            } else {
                for (i = 0; i < MAX_PLAYERS; i++) {
                    func_8006DA5C(temp_v0, (void*) (s32) GwPlayer[i].character + 44, GwPlayer[i].group);
                    func_8006DA5C(var_s6, (void*) (s32) GwPlayer[i].character + 44, GwPlayer[i].group);
                }
            }
        } else {
            if (D_800C6268[temp_fp].unk_00 == 3) {
                var_s3 = 0;
                var_s2 = 1;
                for (i = 0; i < MAX_PLAYERS; i++) {
                    if (GwPlayer[i].group == 0) {
                        func_8006DA5C(temp_v0, (void*) (s32) GwPlayer[i].character + 44, var_s3++);
                    } else {
                        func_8006DA5C(var_s6, (void*) (s32) GwPlayer[i].character + 44, var_s2++);
                    }
                }
            } else {
                for (i = 0; i < MAX_PLAYERS; i++) {
                    func_8006DA5C(temp_v0, (void*) (s32) GwPlayer[i].character + 44, i);
                }
            }
        }

        LoadStringIntoWindow(var_s6, (void*) (s32) D_800C6268[temp_fp].unk_04, -1, -1);
    } else {
        D_800F64F4 = -1;
        var_s6 = -1;
    }

    LoadStringIntoWindow(temp_v0, (void*) (s32) D_800C6268[temp_fp].unk_02, -1, -1);

    temp_v0_12 = DataRead(0xB001B);
    D_800F3182 = func_800678A4(temp_v0_12);
    D_800F6548 = func_80064EF4(1, 5);
    DataClose(temp_v0_12);

    func_80067208(D_800F6548, 0, D_800F3182, 0);
    func_800674BC(D_800F6548, 0, 0x01001000);
    func_80066DC4(D_800F6548, 0, 0xA0, temp_s0 - 20);
    func_80067384(D_800F6548, 0, 1);
    func_80071598(temp_v0);
    func_800674BC(D_800ED4B0[temp_v0].unk_44, D_800ED4B0[temp_v0].unk_274, 0x8000);
    func_800674BC(D_800F6548, 0, 0x8000);

    if (var_s6 != -1) {
        func_80071598(var_s6);
        func_800674BC(D_800ED4B0[var_s6].unk_44, D_800ED4B0[var_s6].unk_274, 0x8000);
    }

    HuPrcVSleep();
    PlaySound(0xFA);
    func_8007166C(temp_v0);
    func_80067480(D_800ED4B0[temp_v0].unk_44, D_800ED4B0[temp_v0].unk_274, 0x8000);
    func_80067480(D_800F6548, 0, 0x8000);

    if (var_s6 != -1) {
        func_8007166C(var_s6);
        func_80067480(D_800ED4B0[var_s6].unk_44, D_800ED4B0[var_s6].unk_274, 0x8000);
    }

    D_800F3B80 = 1;

    while (func_8005FD5C()) {
        HuPrcVSleep();
    }

    while (TRUE) {
        HuPrcVSleep();
    }
}

void GamePauseEnd(void) {
    if (D_800F64F4 != -1) {
        func_80067704(D_800F64F4);
    }
    func_80067704(D_800F2CE0);
    func_80064D38(D_800F6548);
    func_80067704(D_800F3182);
    EndProcess(D_800F0A24);
}

s32 func_8007BCA8(s32 arg0, s16 arg1) {
    TextWindow* temp_s0;
    s16 temp_v0;
    s16 temp_v0_2;

    temp_v0 = func_8006D010(arg0, arg1, 200, 60, 0, 0);
    func_8006E0A4(temp_v0, 0);

    temp_s0 = &D_800ED4B0[temp_v0];
    temp_s0->unk_09 = 0;
    temp_s0->unk_0A = 1;

    func_8006E070(temp_v0, 0);
    func_8006E154(temp_v0, 0);

    temp_s0->unk_274 = temp_v0_2 = func_8006DB3C(temp_v0, 0xB001A, 0, 0, 0);

    func_80067384(temp_s0->unk_44, temp_v0_2, 1);
    func_80067354(temp_s0->unk_44, temp_v0_2, 3.325f, 3.75f);
    func_800674BC(temp_s0->unk_44, temp_v0_2, 0x01001008);
    func_8006752C(temp_s0->unk_44, temp_v0_2, 192);
    func_800674F4(temp_s0->unk_44, temp_v0_2, 16, 16, 64);

    return temp_v0;
}

const char D_800CBAF0[] = "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00";