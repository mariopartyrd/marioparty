#include "common.h"
#include "29B410.h"
#include "engine/process.h"
#include "PR/gu.h"

void func_800FBB94_OpeningScene(void);
void func_800FC758_OpeningScene(void);
void func_800F7E50_OpeningScene(void);
void func_800F86D0_OpeningScene(void);
void func_800F8D3C_OpeningScene(void);
void func_800F916C_OpeningScene(void);
Object* func_800FBCC0_OpeningScene(s32 arg0, void* arg1);

typedef struct OpeningModelEntry {
    /* 0x00 */ s32 model;
    /* 0x04 */ void* data;
    /* 0x08 */ Vec3f pos;
    /* 0x14 */ s32 unk14;
} OpeningModelEntry; /* size = 0x18 */


extern s32 D_800FD704_OpeningScene;
extern OpeningModelEntry D_800FD0FC_OpeningScene[];
extern Vec3f D_800FD4B8_OpeningScene;
extern Vec3f D_800FD4C4_OpeningScene;

omObjData* func_800F69F0_OpeningScene(void);

void func_800FB79C_OpeningScene(Vec3f*, Vec3f*, Vec3f*);
void func_800FC2B8_OpeningScene(Vec3f*, Vec3f*, f32, Vec3f*);
extern s32 D_800FD050_OpeningScene;

extern const Vec3f D_800FD4E8_OpeningScene;

void func_800FBD14_OpeningScene(Object*, Vec3f*, f32);
void func_800FC48C_OpeningScene(f32, f32, f32);
void func_800FC4C0_OpeningScene(f32, f32, f32);
void func_800FC4F4_OpeningScene(f32, f32, f32);
void func_800FC5CC_OpeningScene(void* arg0, s32 arg1);

extern s16 D_800FD780_OpeningScene;
void func_800FB40C_OpeningScene(void);
void func_800FB608_OpeningScene(void);
omObjData* func_800FCB9C_OpeningScene(s32);
omObjData* func_800FCD20_OpeningScene(s32);

typedef struct OpeningModelDef2 {
    /* 0x00 */ s32 file;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 rotY;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ u16 flags;
} OpeningModelDef2; /* size 0x18 */

typedef struct OpeningObjDef {
    /* 0x00 */ s32 id; /* -1 ends the table; the model id is its low byte */
    /* 0x04 */ void* data;
    /* 0x08 */ Vec3f pos;
    /* 0x14 */ s32 unk_14;
} OpeningObjDef; /* size 0x18 */

extern OpeningModelDef2 D_800FD2DC_OpeningScene[];
extern OpeningObjDef D_800FD33C_OpeningScene[];
extern s32 D_800FD050_OpeningScene;
extern omObjData* D_800FD740_OpeningScene[];
extern s16 D_800FD780_OpeningScene;
void func_8005AE44(void);
void func_800FC850_OpeningScene(s16, f32, f32, Vec3f*);
omObjData* func_800FCB9C_OpeningScene(s32);


extern const Vec3f D_800FD4D0_OpeningScene;
extern const Vec3f D_800FD4DC_OpeningScene;
extern void* D_800FD434_OpeningScene[];
extern s32 D_800FD738_OpeningScene;
void func_800FB79C_OpeningScene(Vec3f*, Vec3f*, Vec3f*);
s32 func_800FBAFC_OpeningScene(void);
void func_800FBB94_OpeningScene(void);
Object* func_800FBCC0_OpeningScene(s32 arg0, void* arg1);


typedef struct OpeningModelDef {
    /* 0x00 */ s32 file;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 z;
    /* 0x10 */ f32 rotY;
    /* 0x14 */ s32 unk_14;
} OpeningModelDef; /* size 0x18 */

extern OpeningModelDef D_800FD054_OpeningScene[];


extern s16 D_800FD708_OpeningScene;
extern s16 D_800FD710_OpeningScene[];


extern OpeningModelDef2 D_800FD1EC_OpeningScene[];
extern OpeningObjDef D_800FD21C_OpeningScene[];
void func_800FBD14_OpeningScene(Object* arg0, Vec3f* arg1, f32 arg2);
void func_800FBD7C_OpeningScene(void);
void func_800FC6BC_OpeningScene(void* arg0, s32 arg1);
omObjData* func_800FCD20_OpeningScene(s32 arg0);

/* .data (in address order) */
s32 D_800FCF00_OpeningScene[] = { 0x9, 0x10001, 0xe0008, 0xe0009, 0xe000a, 0xe000b, 0xe000c, 0xe000f, 0xe0010, 0xe0011 };
s32 D_800FCF28_OpeningScene[] = { 0x3, 0x10003, 0xe000d, 0xe000e };
s32 D_800FCF38_OpeningScene[] = { 0x9, 0x20001, 0xe0013, 0xe001b, 0xe0015, 0xe0017, 0xe0018, 0xe0019, 0xe0014, 0xe001a };
s32 D_800FCF60_OpeningScene[] = { 0x5, 0x20003, 0xe0013, 0xe0016, 0x20001, 0xe001a };
s32 D_800FCF78_OpeningScene[] = { 0x6, 0x60001, 0x60097, 0xe001d, 0xe001e, 0xe0020, 0xe0021 };
s32 D_800FCF94_OpeningScene[] = { 0x2, 0x60003, 0xe001f };
s32 D_800FCFA0_OpeningScene[] = { 0x9, 0x30001, 0xe0024, 0xe0025, 0xe0026, 0xe0027, 0xe0029, 0xe002a, 0xe002b, 0xe002c };
s32 D_800FCFC8_OpeningScene[] = { 0x2, 0x30003, 0xe0028 };
s32 D_800FCFD4_OpeningScene[] = { 0x8, 0xe002d, 0xe002e, 0xe002f, 0xe0030, 0xe0031, 0xe0032, 0xe0033, 0x40001 };
s32 D_800FCFF8_OpeningScene[] = { 0x3, 0x40003, 0xe0034, 0xe0035 };
s32 D_800FD008_OpeningScene[] = { 0x7, 0xe0038, 0xe0039, 0xe003a, 0xe003d, 0xe003b, 0x50001, 0xe003e };
s32 D_800FD028_OpeningScene[] = { 0x2, 0x50003, 0xe003c };
s32 D_800FD034_OpeningScene[] = { 0x6, 0xe0040, 0xe0041, 0xe0042, 0xe0043, 0xe003f, 0xe0044 };
s32 D_800FD050_OpeningScene = 0;
OpeningModelDef D_800FD054_OpeningScene[] = {
    { 0x90019, 0.0f, 0.0f, 0.0f, 0.0f, 0x1 },
    { 0x90000, 0.0f, 378.0f, 0.0f, 0.0f, 0x1 },
    { 0x9001b, -900.0f, 95.0f, 50.0f, 45.0f, 0x1 },
    { 0x9001c, 1325.0f, 67.5f, 450.0f, 0.0f, 0x0 },
    { 0x9001e, 190.0f, 315.0f, -1350.0f, 0.0f, 0x1 },
    { 0x9001d, -400.0f, 35.0f, 985.0f, 75.0f, 0x1 },
    { -1, 0.0f, 0.0f, 0.0f, 0.0f, 0x0 },
};
OpeningModelEntry D_800FD0FC_OpeningScene[] = {
    { 0x19, D_800FCF78_OpeningScene, { 0.0f, 0.0f, 0.0f }, 0x1 },
    { 0x1a, D_800FCFA0_OpeningScene, { 0.0f, 0.0f, 0.0f }, 0x1 },
    { 0x17, D_800FCF00_OpeningScene, { 0.0f, 0.0f, 0.0f }, 0x1 },
    { 0x1c, D_800FD008_OpeningScene, { 0.0f, 0.0f, 0.0f }, 0x1 },
    { 0x18, D_800FCF38_OpeningScene, { 0.0f, 0.0f, 0.0f }, 0x1 },
    { 0x1b, D_800FCFD4_OpeningScene, { 0.0f, 0.0f, 0.0f }, 0x1 },
    { 0x7, D_800FD034_OpeningScene, { 50.0f, 0.0f, 900.0f }, 0x1 },
    { -1, NULL, { 0.0f, 0.0f, 0.0f }, 0x0 },
};
OpeningModelDef2 D_800FD1BC_OpeningScene[] = {
    { 0xe0000, { 0.0f, 0.0f, 0.0f }, 0.0f, 0, 1 },
    { -1, { 0.0f, 0.0f, 0.0f }, 0.0f, 0, 0 },
};
OpeningModelDef2 D_800FD1EC_OpeningScene[] = {
    { 0xe0000, { 0.0f, 0.0f, 0.0f }, 0.0f, 0, 1 },
    { -1, { 0.0f, 0.0f, 0.0f }, 0.0f, 0, 0 },
};
OpeningObjDef D_800FD21C_OpeningScene[] = {
    { 0x18, D_800FCF60_OpeningScene, { 0.0f, 0.0f, 180.0f }, 0x1 },
    { 0x1b, D_800FCFF8_OpeningScene, { -150.0f, 0.0f, 180.0f }, 0x1 },
    { 0x1c, D_800FD028_OpeningScene, { -300.0f, 0.0f, 180.0f }, 0x1 },
    { 0x17, D_800FCF28_OpeningScene, { -450.0f, 0.0f, 180.0f }, 0x1 },
    { 0x19, D_800FCF94_OpeningScene, { -600.0f, 0.0f, 180.0f }, 0x1 },
    { 0x1a, D_800FCFC8_OpeningScene, { -750.0f, 0.0f, 180.0f }, 0x1 },
    { 0x7, D_800FD034_OpeningScene, { -375.0f, 0.0f, -600.0f }, 0x1 },
    { -1, NULL, { 0.0f, 0.0f, 0.0f }, 0x0 },
};
OpeningModelDef2 D_800FD2DC_OpeningScene[] = {
    { 0xe0001, { 0.0f, 0.0f, 0.0f }, 0.0f, 0, 1 },
    { 0xe0002, { 0.0f, 0.0f, 0.0f }, 0.0f, 0, 0 },
    { 0xe0003, { 0.0f, 0.0f, 0.0f }, 0.0f, 0, 0 },
    { -1, { 0.0f, 0.0f, 0.0f }, 0.0f, 0, 0 },
};
OpeningObjDef D_800FD33C_OpeningScene[] = {
    { 0x18, D_800FCF60_OpeningScene, { -30.0f, 0.0f, 5014.5f }, 0x1 },
    { 0x1b, D_800FCFF8_OpeningScene, { -0.7f, 0.0f, 3539.0f }, 0x1 },
    { 0x1c, D_800FD028_OpeningScene, { 72.15f, 0.0f, 6164.0f }, 0x1 },
    { 0x19, D_800FCF94_OpeningScene, { -23.85f, 0.0f, 8162.5f }, 0x1 },
    { 0x1a, D_800FCFC8_OpeningScene, { -93.25f, 0.0f, 7336.5f }, 0x1 },
    { -1, NULL, { 0.0f, 0.0f, 0.0f }, 0x0 },
    { 0x17, D_800FCF28_OpeningScene, { -0.0f, 0.0f, 0.0f }, 0x1 },
    { 0x7, D_800FD034_OpeningScene, { 0.0f, 0.0f, 20600.0f }, 0x1 },
};
s32 D_800FD3FC_OpeningScene[] = { 0x1, 0x10005 };
s32 D_800FD404_OpeningScene[] = { 0x1, 0x2000d };
s32 D_800FD40C_OpeningScene[] = { 0x1, 0x60005 };
s32 D_800FD414_OpeningScene[] = { 0x1, 0x3000d };
s32 D_800FD41C_OpeningScene[] = { 0x1, 0x4000d };
s32 D_800FD424_OpeningScene[] = { 0x1, 0x5000d };
s32 D_800FD42C_OpeningScene[] = { 0x1, 0x70001 };
void* D_800FD434_OpeningScene[] = { D_800FD3FC_OpeningScene, D_800FD404_OpeningScene, D_800FD414_OpeningScene, D_800FD40C_OpeningScene, D_800FD41C_OpeningScene, D_800FD424_OpeningScene, D_800FD42C_OpeningScene };
Gfx D_800FD450_OpeningScene[] = {
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
Vec3f D_800FD4A0_OpeningScene = { 341.0f, 28.0f, 0.0f };
Vec3f D_800FD4AC_OpeningScene = { 50.0f, 0.0f, 900.0f };
Vec3f D_800FD4B8_OpeningScene = { 541.27f, 2040.06f, 2711.59f };
Vec3f D_800FD4C4_OpeningScene = { 945.37f, 463.56f, 33.24f };

void func_800F65E0_OpeningScene(void) {
    Vec3f sp18;
    Vec3f sp28;
    omObjData* temp_s0;

    pfWinClose();
    D_800C5972 = 0;
    D_800C59A6 = -1;
    omSysPauseEnableFlag = 1;
    InitCameras(1);
    func_80029090(1);
    func_8001DE70(25);
    omInitObjMan(50, 20);
    func_80060088();
    func_8006CEA0();
    func_8005AD18();
    
    sp18 = D_800FD4A0_OpeningScene;
    sp28 = D_800FD4AC_OpeningScene;

    func_800FB670_OpeningScene(&sp18, &sp28, 1200.0f);
    func_800FB7F8_OpeningScene(20.0f, 80.0f, 8000.0f);
    temp_s0 = omAddObj(0x7FDA, 0, 0, -1, func_800FB810_OpeningScene);
    omSetStatBit(temp_s0, 0xA0);
    func_800FB810_OpeningScene(temp_s0);
    func_80023448(3);
    func_800234B8(0, 0x78, 0x78, 0x78);
    func_800234B8(1, 0x40, 0x40, 0x60);
    func_80023504(1, 50.0f, 50.0f, 100.0f);
    func_800234B8(2, 0, 0, 0);
    func_800234B8(3, 0, 0, 0);
    D_800FD730_OpeningScene[1] = omAddPrcObj(&func_800FB86C_OpeningScene, 0x300, 0x2000, 0);
}

void func_800F6788_OpeningScene(omObjData* arg0) {
    if (arg0->work[1] != 0) {
        arg0->work[1]--;
        return;
    }
    
    arg0->work[0]++;
    
    if (arg0->work[0] >= 7) {
        arg0->work[0] = 0;
    }
    
    arg0->work[1] = 0x50;
    
    func_800FBD48_OpeningScene(D_80110448_OpeningScene[6], &D_80110448_OpeningScene[arg0->work[0]]->coords, 40.0f);
}

omObjData* func_800F6804_OpeningScene(unkGlobalStruct_00* arg0) {
    omObjData* temp_s0;

    temp_s0 = omAddObj(0x1000, 0, 0, -1, &func_800F6788_OpeningScene);
    omSetRot(temp_s0, 0, 0, 0);
    omSetSca(temp_s0, arg0->unk_18 + arg0->unk_0C, arg0->unk_1C + arg0->unk_10, arg0->unk_20.floatingPoint + arg0->unk_14);
    omSetTra(temp_s0, ((unkGlobalStruct_00*)D_80110448_OpeningScene[2])->unk_0C, ((unkGlobalStruct_00*)D_80110448_OpeningScene[2])->unk_10, ((unkGlobalStruct_00*)D_80110448_OpeningScene[2])->unk_14);
    temp_s0->work[0] = 2;
    temp_s0->work[1] = 48;
    temp_s0->unk_50 = arg0;
    return temp_s0;
}

void func_800F68D4_OpeningScene(omObjData* arg0) {
    f32 t;
    f32 v;
    f32 a;
    f32 c;
    f32 c2;

    t = arg0->rot.x;
    v = t;
    if (t > 1.0f) {
        v = t - 1.0f;
    }
    t = v;
    a = func_800AEAC0(t * 360.0f) * 45.0f;
    c = func_800AEFD0(a);
    D_80110448_OpeningScene[6]->unk_18.x = c * arg0->trans.x + func_800AEAC0(a) * arg0->trans.z;
    D_80110448_OpeningScene[6]->unk_18.y = D_80110448_OpeningScene[6]->coords.y;
    c2 = func_800AEAC0(a);
    D_80110448_OpeningScene[6]->unk_18.z = -arg0->trans.x * c2 + func_800AEFD0(a) * arg0->trans.z;
    t += 0.05f;
    arg0->rot.x = t;
}

omObjData* func_800F69F0_OpeningScene(void) {
    omObjData* obj;

    obj = omAddObj(0x1000, 0, 0, -1, func_800F68D4_OpeningScene);
    func_800A0E80(&D_80110448_OpeningScene[6]->unk_18, &D_800FD6D0_OpeningScene[0], &D_80110448_OpeningScene[6]->coords);
    omSetRot(obj, 0, 0, 0);
    omSetSca(obj, D_80110448_OpeningScene[6]->coords.x, D_80110448_OpeningScene[6]->coords.y, D_80110448_OpeningScene[6]->coords.z);
    omSetTra(obj, D_80110448_OpeningScene[6]->unk_18.x, D_80110448_OpeningScene[6]->unk_18.y, D_80110448_OpeningScene[6]->unk_18.z);
    obj->work[0] = 6;
    obj->unk_50 = D_80110448_OpeningScene[6];
    return obj;
}

const Vec3f D_800FD4D0_OpeningScene = { 0.0f, 1.0f, 0.0f };

const Vec3f D_800FD4DC_OpeningScene = { 0.0f, 0.0f, 0.0f };

const Vec3f D_800FD4E8_OpeningScene = { 0.0f, 100.0f, 0.0f };

void func_800F6AB8_OpeningScene(void) {
    Vec3f sp20;
    s32 sp30[0xD0];
    s32 sp370[0x50];
    Vec3f sp4B0;
    Vec3f sp4C0;
    Vec3f sp4D0;
    Vec3f sp4E0;
    Vec3f sp4F0;
    Vec3f sp500;
    Vec3f sp510;
    Vec3f sp520;
    Vec3f sp530;
    f32 sp540[4][4];
    Vec3f sp580;
    Vec3f sp590;
    Vec3f sp5A0;
    Vec3f sp5B0;
    Vec3f sp5C0;
    Vec3f sp5D0;
    f32 sp5E0[4][4];
    Vec3f sp620;
    Vec3f sp630;
    Vec3f sp640;
    Vec3f sp650;
    Vec3f sp660;
    Vec3f sp670;
    Vec3f sp680;
    Vec3f sp690;
    Vec3f sp6A0;
    f32 t;
    f32 u;
    f32 k;
    s32 i;
    s32 j;
    s32 n;

    D_800FD704_OpeningScene = 1;
    func_800FC394_OpeningScene(0);
    func_800FB7F8_OpeningScene(45.0f, 200.0f, 10000.0f);
    D_800FD050_OpeningScene = 1;
    for (i = 0; D_800FD0FC_OpeningScene[i].model != -1; i++) {
        D_80110448_OpeningScene[i] = func_800FBCC0_OpeningScene((u8)D_800FD0FC_OpeningScene[i].model, D_800FD0FC_OpeningScene[i].data);
        func_800A0D50(&D_80110448_OpeningScene[i]->coords, &D_800FD0FC_OpeningScene[i].pos);
        func_80025EB4(*D_80110448_OpeningScene[i]->unk_3C->unk_40, -1, 2);
    }
    func_800FBD98_OpeningScene((OpeningModel*)sp30, D_800FD1BC_OpeningScene[0].file, 0, &D_800FD1BC_OpeningScene[0].pos, D_800FD1BC_OpeningScene[0].flags);
    func_800A0D00(&sp20, 0.0f, D_800FD1BC_OpeningScene[0].rotY, 0.0f);
    func_800FC264_OpeningScene((OpeningModel*)sp30, &sp20);
    func_800FBEEC_OpeningScene((OpeningSprite*)sp370, 0xE0004, 0x47F4, 0, 50, 320, 120);
    sp4B0 = D_800FD4B8_OpeningScene;
    sp4C0 = D_800FD4C4_OpeningScene;
    sp4D0 = D_800FD4D0_OpeningScene;
    sp4E0 = D_800FD4DC_OpeningScene;
    k = 175.0f;
    for (j = 0; j < 6; j++) {
        func_800A0D00(&sp520, 0.0f, 0.0f, k);
        guRotateF(sp540, j * 360.0f / 6.0f, 0.0f, 1.0f, 0.0f);
        guMtxXFMF(sp540, sp520.x, sp520.y, sp520.z, &sp530.x, &sp530.y, &sp530.z);
        func_800A0D00(&sp510, sp530.x, sp530.y, sp530.z);
        func_800A0D50(&D_80110448_OpeningScene[j]->coords, &sp510);
        func_800A0E80(&D_80110448_OpeningScene[j]->unk_18, &sp4E0, &D_80110448_OpeningScene[j]->coords);
    }
    func_800A0D50(&D_80110448_OpeningScene[6]->coords, &sp4E0);
    MBMotionSet(D_80110448_OpeningScene[2], 1, 2);
    MBMotionSet(D_80110448_OpeningScene[4], 1, 2);
    MBMotionSet(D_80110448_OpeningScene[0], 2, 2);
    MBMotionSet(D_80110448_OpeningScene[1], 1, 2);
    MBMotionSet(D_80110448_OpeningScene[5], 1, 2);
    MBMotionSet(D_80110448_OpeningScene[3], 0, 0);
    MBMotionSet(D_80110448_OpeningScene[6], 0, 2);
    D_80110300[15] = func_800F6804_OpeningScene((unkGlobalStruct_00*)D_80110448_OpeningScene[6]);
    func_800A0D50(&D_800FD6D0_OpeningScene[0], &sp4B0);
    func_800A0D50(&D_800FD6D0_OpeningScene[1], &sp4E0);
    D_800FD6D0_OpeningScene[1].y = 60.0f;
    func_800A0D50(&D_800FD6D0_OpeningScene[2], &sp4D0);
    func_80060128(6);
    SetFadeInTypeAndTime(0, 16);
    func_800A0D50(&sp4F0, &sp4B0);
    func_800A0D50(&sp500, &sp4C0);
    for (j = 0; j < 801; j++) {
        t = j;
        t *= 0.00125f;
        func_800FC2B8_OpeningScene(&sp4F0, &sp500, t, &D_800FD6D0_OpeningScene[0]);
        D_800FD6D0_OpeningScene[0].y = func_800B1750(t) * (sp500.y - sp4F0.y) + sp4F0.y;
        switch (j) {
            case 80:
                func_800FC5CC_OpeningScene((void*)0x433, 0);
                break;
            case 200:
                func_800FC724_OpeningScene();
                break;
            case 280:
                func_800FC5CC_OpeningScene((void*)0x434, 0);
                break;
            case 400:
                func_800FC724_OpeningScene();
                break;
            case 480:
                func_800FC5CC_OpeningScene((void*)0x435, 0);
                break;
            case 600:
                func_800FC724_OpeningScene();
                break;
            case 680:
                func_800A0D50(&sp580, &D_80110448_OpeningScene[5]->coords);
                func_800A0D50(&sp590, &D_80110448_OpeningScene[6]->coords);
                func_800A0D00(&sp5A0, (sp590.x - sp580.x) * 0.5 + sp580.x, (sp590.y - sp580.y) * 0.6 + sp580.y,
                              (sp590.z - sp580.z) * 0.5 + sp580.z);
                MBMotionShiftSet(D_80110448_OpeningScene[5], 7, 0, 20, 2);
                MBMotionShiftSet(D_80110448_OpeningScene[6], -1, 0, 20, 2);
                func_800FC5CC_OpeningScene((void*)0x436, 0);
                func_800FBD14_OpeningScene(D_80110448_OpeningScene[5], &sp5A0, 20.0f);
                break;
            case 710:
                func_800FBD48_OpeningScene(D_80110448_OpeningScene[6], &D_80110448_OpeningScene[5]->coords, 30.0f);
                MBMotionShiftSet(D_80110448_OpeningScene[5], 1, 0, 20, 2);
                break;
        }
        if (((j == 80) | (j == 180)) || ((j == 380) | (j == 580))) {
            MBMotionShiftSet(D_80110448_OpeningScene[3], 0, 0, 20, 0);
        } else if (MBMotionCheck(D_80110448_OpeningScene[3]) & 1) {
            MBMotionShiftSet(D_80110448_OpeningScene[3], -1, 0, 20, 2);
        }
        HuPrcSleep(0);
    }
    func_800FC724_OpeningScene();
    omDelObj(D_80110300[15]);
    D_80110300[15] = NULL;
    sp580 = D_800FD4E8_OpeningScene;
    sp5D0 = D_800FD4DC_OpeningScene;
    k = 600.0f;
    for (j = 0; j < 6; j++) {
        func_800A0D00(&sp590, 0.0f, 0.0f, k);
        guRotateF(sp5E0, j * 120.0f / 6.0f, 0.0f, 1.0f, 0.0f);
        guMtxXFMF(sp5E0, sp590.x, sp590.y, sp590.z, &sp5B0.x, &sp5B0.y, &sp5B0.z);
        func_800A0D00(&sp5C0, sp5B0.x, sp5B0.y, sp5B0.z);
        func_800A0D50(&D_80110448_OpeningScene[j]->coords, &sp5C0);
        func_800A0E80(&D_80110448_OpeningScene[j]->unk_18, &sp5D0, &D_80110448_OpeningScene[j]->coords);
    }
    MBModelDispOff(D_80110448_OpeningScene[6]);
    MBMotionSet(D_80110448_OpeningScene[2], -1, 2);
    MBMotionSet(D_80110448_OpeningScene[4], -1, 2);
    MBMotionSet(D_80110448_OpeningScene[0], -1, 2);
    MBMotionSet(D_80110448_OpeningScene[1], -1, 2);
    MBMotionSet(D_80110448_OpeningScene[5], 3, 0);
    MBMotionSet(D_80110448_OpeningScene[3], -1, 2);
    MBMotionSet(D_80110448_OpeningScene[6], -1, 2);
    func_800A0D50(&D_800FD6D0_OpeningScene[0], &sp580);
    func_800A0D50(&D_800FD6D0_OpeningScene[1], &D_80110448_OpeningScene[4]->coords);
    D_800FD6D0_OpeningScene[1].y = 100.0f;
    MBMotionShiftSet(D_80110448_OpeningScene[4], 5, 0, 0x14, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[3], 6, 0, 0x14, 2);
    HuPrcSleep(0x14);
    func_8004F504(D_80110448_OpeningScene[5]);
    MBMotionShiftSet(D_80110448_OpeningScene[5], 3, 0, 8, 0);
    HuPrcSleep(8);
    func_8004F504(D_80110448_OpeningScene[5]);
    MBMotionShiftSet(D_80110448_OpeningScene[5], -1, 0, 0x14, 2);
    HuPrcSleep(0x1E);
    func_800FC5CC_OpeningScene((void*)0x437, 0);
    HuPrcSleep(0x50);
    func_800FC724_OpeningScene();
    MBMotionShiftSet(D_80110448_OpeningScene[3], 1, 0, 0x14, 0);
    func_8004F504(D_80110448_OpeningScene[3]);
    MBMotionShiftSet(D_80110448_OpeningScene[3], -1, 0, 0x1E, 2);
    HuPrcSleep(0x14);
    MBMotionShiftSet(D_80110448_OpeningScene[4], 6, 0, 8, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[5], 7, 0, 0x10, 0);
    func_800FBD48_OpeningScene(D_80110448_OpeningScene[5], &D_80110448_OpeningScene[3]->coords, 8.0f);
    HuPrcSleep(8);
    MBMotionShiftSet(D_80110448_OpeningScene[5], -1, 0, 0xA, 2);
    HuPrcSleep(0xE);
    HuPrcSleep(0xA);
    MBMotionShiftSet(D_80110448_OpeningScene[5], 7, 0, 8, 2);
    HuPrcSleep(8);
    HuPrcSleep(2);
    func_800A0E80(&sp640, &D_80110448_OpeningScene[4]->coords, &D_80110448_OpeningScene[5]->coords);
    func_800A0D50(&sp620, &D_80110448_OpeningScene[5]->coords);
    func_800A0D00(&sp630, (sp640.x * 0.36f) + sp620.x, (sp640.y * 0.36f) + sp620.y, (sp640.z * 0.36f) + sp620.z);
    MBMotionShiftSet(D_80110448_OpeningScene[3], 5, 0, 0xA, 2);
    func_800FBD48_OpeningScene(D_80110448_OpeningScene[3], &D_80110448_OpeningScene[5]->coords, 20.0f);
    func_800FBD14_OpeningScene(D_80110448_OpeningScene[5], &sp630, 16.0f);
    HuPrcSleep(0xC);
    MBMotionShiftSet(D_80110448_OpeningScene[3], -1, 0, 0xA, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[5], -1, 0, 0xA, 2);
    HuPrcSleep(0x26);
    MBMotionShiftSet(D_80110448_OpeningScene[5], 4, 0, 0x14, 0);
    MBMotionShiftSet(D_80110448_OpeningScene[4], 5, 0, 0x14, 2);
    HuPrcSleep(0x14);
    func_8004F504(D_80110448_OpeningScene[5]);
    MBMotionShiftSet(D_80110448_OpeningScene[5], -1, 0, 0x1E, 2);
    HuPrcSleep(0x1E);
    func_800FBD48_OpeningScene(D_80110448_OpeningScene[3], &D_80110448_OpeningScene[5]->coords, 10.0f);
    MBMotionShiftSet(D_80110448_OpeningScene[3], 5, 0, 0xA, 2);
    HuPrcSleep(0xA);
    func_800A0E80(&sp670, &D_80110448_OpeningScene[4]->coords, &D_80110448_OpeningScene[3]->coords);
    func_800A0D50(&sp650, &D_80110448_OpeningScene[3]->coords);
    func_800A0D00(&sp660, (sp670.x * 0.36f) + sp650.x, (sp670.y * 0.36f) + sp650.y, (sp670.z * 0.36f) + sp650.z);
    func_800FBD14_OpeningScene(D_80110448_OpeningScene[3], &sp660, 30.0f);
    MBMotionShiftSet(D_80110448_OpeningScene[4], 6, 0, 0x14, 2);
    HuPrcSleep(0x1E);
    MBMotionShiftSet(D_80110448_OpeningScene[3], -1, 0, 0xA, 2);
    HuPrcSleep(0x14);
    MBMotionShiftSet(D_80110448_OpeningScene[3], 2, 0, 0x14, 0);
    func_8004F504(D_80110448_OpeningScene[3]);
    MBMotionShiftSet(D_80110448_OpeningScene[3], -1, 0, 0x14, 2);
    HuPrcSleep(0x1E);
    MBMotionShiftSet(D_80110448_OpeningScene[5], 7, 0, 8, 2);
    func_800FBD48_OpeningScene(D_80110448_OpeningScene[5], &D_800FD6D0_OpeningScene[0], 20.0f);
    func_800A0E80(&sp6A0, &D_80110448_OpeningScene[4]->coords, &D_80110448_OpeningScene[5]->coords);
    func_800A0D50(&sp680, &D_80110448_OpeningScene[5]->coords);
    func_800A0D00(&sp690, (sp6A0.x * 0.3f) + sp680.x, (sp6A0.y * 0.3f) + sp680.y, (sp6A0.z * 0.3f) + sp680.z);
    func_800FBD14_OpeningScene(D_80110448_OpeningScene[5], &sp690, 20.0f);
    HuPrcSleep(0x14);
    MBMotionShiftSet(D_80110448_OpeningScene[5], 5, 0, 0x14, 0);
    MBMotionShiftSet(D_80110448_OpeningScene[4], 7, 0, 0xA, 0);
    func_8004F504(D_80110448_OpeningScene[4]);
    MBMotionShiftSet(D_80110448_OpeningScene[4], -1, 0, 0xA, 2);
    func_8004F504(D_80110448_OpeningScene[5]);
    func_800FBD48_OpeningScene(D_80110448_OpeningScene[5], &D_80110448_OpeningScene[4]->coords, 20.0f);
    MBMotionShiftSet(D_80110448_OpeningScene[5], -1, 0, 0x14, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[3], 5, 0, 8, 2);
    func_800FBD48_OpeningScene(D_80110448_OpeningScene[3], &D_800FD6D0_OpeningScene[0], 20.0f);
    func_800A0E80(&sp6A0, &D_80110448_OpeningScene[4]->coords, &D_80110448_OpeningScene[3]->coords);
    func_800A0D50(&sp680, &D_80110448_OpeningScene[3]->coords);
    func_800A0D00(&sp690, (sp6A0.x * 0.3f) + sp680.x, (sp6A0.y * 0.3f) + sp680.y, (sp6A0.z * 0.3f) + sp680.z);
    func_800FBD14_OpeningScene(D_80110448_OpeningScene[3], &sp690, 20.0f);
    HuPrcSleep(0x14);
    MBMotionShiftSet(D_80110448_OpeningScene[3], 3, 0, 0x14, 0);
    MBMotionShiftSet(D_80110448_OpeningScene[4], 8, 0, 0xA, 0);
    func_8004F504(D_80110448_OpeningScene[4]);
    MBMotionShiftSet(D_80110448_OpeningScene[4], -1, 0, 0x14, 2);
    func_8004F504(D_80110448_OpeningScene[3]);
    MBMotionShiftSet(D_80110448_OpeningScene[3], -1, 0, 0xA, 2);
    HuPrcSleep(0xA);
    func_800FBD48_OpeningScene(D_80110448_OpeningScene[5], &D_800FD6D0_OpeningScene[0], 20.0f);
    func_800FBD48_OpeningScene(D_80110448_OpeningScene[3], &D_800FD6D0_OpeningScene[0], 20.0f);
    MBMotionShiftSet(D_80110448_OpeningScene[5], 5, 0, 0x14, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[3], 3, 0, 0x14, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[4], 2, 0, 0xA, 2);
    HuPrcSleep(0x64);
    func_800FC5CC_OpeningScene((void*)0x438, 0);
    HuPrcSleep(0x50);
    func_800A0D50(&sp670, &D_800FD6D0_OpeningScene[1]);
    sp670.y = 100.0f;
    func_800A0D50(&sp620, &D_80110448_OpeningScene[1]->coords);
    sp620.y = 60.0f;
    MBMotionSet(D_80110448_OpeningScene[2], 7, 2);
    MBMotionSet(D_80110448_OpeningScene[0], 4, 2);
    MBMotionSet(D_80110448_OpeningScene[1], 6, 2);
    for (n = 0; n < 21; n++) {
        u = n * 0.05f;
        func_800FC2B8_OpeningScene(&sp670, &sp620, u * u, &D_800FD6D0_OpeningScene[1]);
        D_800FD6D0_OpeningScene[1].y = 100.0f;
        HuPrcSleep(0);
    }
    HuPrcSleep(0xA);
    func_800FC758_OpeningScene();
    HuPrcSleep(0xF);
    MBMotionShiftSet(D_80110448_OpeningScene[2], 2, 0, 0x1E, 0);
    func_8004F504(D_80110448_OpeningScene[2]);
    MBMotionShiftSet(D_80110448_OpeningScene[2], 8, 0, 0x1E, 2);
    HuPrcSleep(0x28);
    func_800FC5CC_OpeningScene((void*)0x439, 0x46);
    MBMotionShiftSet(D_80110448_OpeningScene[0], 1, 0, 0x14, 0);
    func_8004F504(D_80110448_OpeningScene[0]);
    MBMotionShiftSet(D_80110448_OpeningScene[0], -1, 0, 0x28, 2);
    HuPrcSleep(0x14);
    MBMotionShiftSet(D_80110448_OpeningScene[2], 3, 0, 8, 0);
    MBMotionShiftSet(D_80110448_OpeningScene[1], 5, 0, 0x14, 2);
    func_800FC758_OpeningScene();
    HuPrcSleep(0x1E);
    MBMotionShiftSet(D_80110448_OpeningScene[1], -1, 0, 0x14, 2);
    HuPrcSleep(0x1E);
    MBMotionShiftSet(D_80110448_OpeningScene[1], 2, 0, 0x14, 0);
    HuPrcSleep(0x1E);
    func_8004F504(D_80110448_OpeningScene[1]);
    MBMotionShiftSet(D_80110448_OpeningScene[1], 7, 0, 8, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[0], 4, 0, 0x14, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[2], 6, 0, 0x14, 2);
    HuPrcSleep(0x14);
    func_800FC6BC_OpeningScene((void*)0x43A, 0x5A);
    func_800FC5CC_OpeningScene((void*)0x43B, 0);
    HuPrcSleep(0x3C);
    MBMotionShiftSet(D_80110448_OpeningScene[2], -1, 0, 0x14, 2);
    HuPrcSleep(0x1E);
    func_800FC724_OpeningScene();
    D_800FD740_OpeningScene[0] = func_800FCD20_OpeningScene(0x28);
    HuPrcSleep(0x28);
    omDelObj(D_800FD740_OpeningScene[0]);
    func_8002456C(D_800FD780_OpeningScene);
    func_800FC110_OpeningScene((s16*)sp370);
    func_800F7E50_OpeningScene();
    func_800FC0EC_OpeningScene((s16*)sp370);
    func_800F86D0_OpeningScene();
    func_800F8D3C_OpeningScene();
    func_800F916C_OpeningScene();
    func_800FBB94_OpeningScene();
    func_800FBEA8_OpeningScene((OpeningModel*)sp30);
    func_800FC0BC_OpeningScene((OpeningSprite*)sp370);
    HuPrcSleep(4);
}
void func_800F7E50_OpeningScene(void) {
    Vec3f sp20;
    Vec3f sp30;
    Vec3f sp40;
    Vec3f sp50;
    Vec3f sp60;
    Vec3f sp70;
    f32 sp80[4][4];
    Vec3f spC0 = { 0.0f, 51.2f, 0.0f };
    Vec3f spD0 = { 0.0f, 101.1f, 1.0f };
    Vec3f spE0 = D_800FD4D0_OpeningScene;
    Vec3f spF0 = { 1.0f, 1.0f, 1.0f };
    f32 k = 175.0f;
    Vec3f sp100;
    Vec3f sp110;
    Vec3f sp120;
    Vec3f sp130;
    Vec3f sp140[16];
    f32 t;
    s32 i;
    s32 j;

    func_800FB79C_OpeningScene(&spC0, &spD0, &spE0);
    MBModelDispOn(D_80110448_OpeningScene[5]);
    MBModelDispOn(D_80110448_OpeningScene[4]);
    MBModelDispOn(D_80110448_OpeningScene[3]);
    func_800A0D50((Vec3f*)&D_80110448_OpeningScene[4]->xScale, &spF0);
    func_800A0D50(&sp20, &spC0);
    sp20.y = 0.0f;
    func_800A0D50(&D_80110448_OpeningScene[6]->coords, &sp20);
    for (i = 0; i < 6; i++) {
        func_800A0D50(&sp20, &spC0);
        sp20.y = 0.0f;
        func_800A0D50(&sp30, &spD0);
        sp30.y = 0.0f;
        func_800A0D00(&sp70, sp30.x - sp20.x, 0.0f, sp30.z - sp20.z);
        guNormalize(&sp70.x, &sp70.y, &sp70.z);
        func_800A0D00(&sp50, k * sp70.x, k * sp70.y, k * sp70.z);
        guRotateF(sp80, i * 360.0f / 6.0f, 0.0f, 1.0f, 0.0f);
        guMtxXFMF(sp80, sp50.x, sp50.y, sp50.z, &sp60.x, &sp60.y, &sp60.z);
        func_800A0D00(&sp40, sp60.x + sp20.x, sp60.y + sp20.y, sp60.z + sp20.z);
        func_800A0D50(&D_80110448_OpeningScene[i]->coords, &sp40);
        func_800A0E80(&D_80110448_OpeningScene[i]->unk_18, &D_800FD6D0_OpeningScene[0], &D_80110448_OpeningScene[i]->coords);
    }
    {
        Vec3f sp200 = { -417.48f, 420.94f, 890.64f };
        Vec3f sp210;
        Vec3f sp220;
        Object* obj;

        func_800FB7F8_OpeningScene(30.0f, 200.0f, 10000.0f);
        func_800FC48C_OpeningScene(sp200.x, sp200.y, sp200.z);
        obj = D_80110448_OpeningScene[6];
        obj->coords.y = 0.0f;
        func_800FC4C0_OpeningScene(obj->coords.x, 100.0f, obj->coords.z);
        MBModelDispOn(D_80110448_OpeningScene[6]);
        func_800A0E80(&D_80110448_OpeningScene[6]->unk_18, &sp200, &D_80110448_OpeningScene[6]->coords);
        {
            Vec3f sp230 = { -401.29f, 4578.61f, 856.1f };

            MBMotionShiftSet(D_80110448_OpeningScene[2], 4, 0, 8, 2);
            MBMotionShiftSet(D_80110448_OpeningScene[4], 3, 0, 8, 2);
            MBMotionShiftSet(D_80110448_OpeningScene[0], 3, 0, 8, 2);
            MBMotionSet(D_80110448_OpeningScene[1], 3, 2);
            MBMotionShiftSet(D_80110448_OpeningScene[5], 6, 0, 8, 2);
            MBMotionShiftSet(D_80110448_OpeningScene[3], 5, 0, 8, 2);
            MBMotionShiftSet(D_80110448_OpeningScene[6], 0, 0, 8, 2);
            D_800FD740_OpeningScene[0] = func_800FCB9C_OpeningScene(16);
            HuPrcSleep(8);
            for (i = 0; i < 6; i++) {
                func_800A0D50(&sp140[i], &D_80110448_OpeningScene[i]->coords);
            }
            func_800A0D50(&sp140[6], &D_80110448_OpeningScene[6]->coords);
            for (i = 0; i < 81; i++) {
                t = i * 0.0125f;
                for (j = 0; j < 6; j++) {
                    func_800A0D50(&sp100, &sp140[j]);
                    func_800A0D50(&sp110, &sp140[6]);
                    func_800A0D00(&sp120, t * (sp110.x - sp100.x) + sp100.x, t * (sp110.y - sp100.y) + sp100.y,
                                  t * (sp110.z - sp100.z) + sp100.z);
                    func_800A0D50(&D_80110448_OpeningScene[j]->coords, &sp120);
                }
                if (t > 0.6f) {
                    break;
                }
                HuPrcSleep(0);
            }
            HuPrcSleep(40);
            omDelObj(D_800FD740_OpeningScene[0]);
            func_8002456C(D_800FD780_OpeningScene);
            func_800A0D50(&sp210, &D_800FD6D0_OpeningScene[0]);
            func_800A0D50(&sp220, &D_800FD6D0_OpeningScene[1]);
            MBMotionShiftSet(D_80110448_OpeningScene[6], 1, 0, 8, 2);
            for (i = 0; i < 6; i++) {
                MBMotionShiftSet(D_80110448_OpeningScene[i], -1, 0, 8, 2);
            }
            func_800FC5CC_OpeningScene((void*)0x43C, 1);
            for (i = 0; i < 40; i++) {
                t = i * 0.025f;
                D_80110448_OpeningScene[6]->unk_30 = t * sp230.y;
                func_800A0D50(&sp110, &D_80110448_OpeningScene[6]->coords);
                for (j = 0; j < 6; j++) {
                    func_800A0D50(&sp100, &sp140[j]);
                    func_800A0D00(&sp120, (0.6f - t * 0.3f) * (sp110.x - sp100.x) + sp100.x, sp100.y,
                                  (0.6f - t * 0.3f) * (sp110.z - sp100.z) + sp100.z);
                    func_800A0D50(&D_80110448_OpeningScene[j]->coords, &sp120);
                }
                func_800A0D50(&sp100, &D_80110448_OpeningScene[6]->coords);
                sp100.y += 30.0f;
                func_800A0D50(&sp110, &sp100);
                sp110.y += D_80110448_OpeningScene[6]->unk_30;
                func_800A0D00(&D_800FD6D0_OpeningScene[1], sp110.x, sp110.y + 50.0f, sp110.z);
                func_800FC2B8_OpeningScene(&sp210, &sp230, t, &sp130);
                func_800A0D00(&D_800FD6D0_OpeningScene[0], sp130.x, sp130.y, sp130.z);
                HuPrcSleep(0);
            }
            D_80110300[15] = func_800F69F0_OpeningScene();
            HuPrcSleep(100);
            omDelObj(D_80110300[15]);
            D_80110300[15] = NULL;
            for (i = 0; i < 6; i++) {
                MBMotionSet(D_80110448_OpeningScene[i], -1, 2);
            }
            MBMotionSet(D_80110448_OpeningScene[6], -1, 2);
        }
    }
}
void func_800F86D0_OpeningScene(void) {
    Vec3f sp20;
    Vec3f sp30;
    Vec3f sp40;
    Vec3f sp50;
    Vec3f sp60;
    Vec3f sp70;
    Vec3f sp80 = D_800FD4DC_OpeningScene;
    f32 k = 200.0f;
    f32 sp90[4][4];
    Vec3f spD0 = { 0.0f, 150.0f, 580.0f };
    Vec3f spE0 = D_800FD4E8_OpeningScene;
    f32 t;
    s32 i;

    func_800FC48C_OpeningScene(spD0.x, spD0.y, spD0.z);
    func_800FC4C0_OpeningScene(spE0.x, spE0.y, spE0.z);
    func_800FC4F4_OpeningScene(0.0f, 1.0f, 0.0f);
    func_800FB7F8_OpeningScene(45.0f, 10.0f, 8000.0f);
    func_800A0D50(&D_80110448_OpeningScene[6]->coords, &sp80);
    func_800A0D00(&sp40, -D_800FD6D0_OpeningScene[0].x, D_800FD6D0_OpeningScene[0].y, -D_800FD6D0_OpeningScene[0].z);
    func_800A0E80(&D_80110448_OpeningScene[6]->unk_18, &sp40, &D_80110448_OpeningScene[6]->coords);
    for (i = 0; i < 6; i++) {
        func_800A0D50(&sp20, &sp80);
        sp20.y = 0.0f;
        func_800A0D50(&sp30, &D_800FD6D0_OpeningScene[0]);
        sp30.y = 0.0f;
        func_800A0D00(&sp70, sp30.x - sp20.x, 0.0f, sp30.z - sp20.z);
        guNormalize(&sp70.x, &sp70.y, &sp70.z);
        func_800A0D00(&sp50, k * sp70.x, k * sp70.y, k * sp70.z);
        guRotateF(sp90, i * 180.0f / 6.0f + 90.0f + 22.5f, 0.0f, 1.0f, 0.0f);
        guMtxXFMF(sp90, sp50.x, sp50.y, sp50.z, &sp60.x, &sp60.y, &sp60.z);
        func_800A0D00(&sp40, sp60.x + sp20.x, sp60.y + sp20.y, sp60.z + sp20.z);
        func_800A0D50(&D_80110448_OpeningScene[i]->coords, &sp40);
        func_800A0E80(&D_80110448_OpeningScene[i]->unk_18, &D_80110448_OpeningScene[6]->coords, &D_80110448_OpeningScene[i]->coords);
    }
    for (i = 0; i < 6; i++) {
        if (i != 2 && i != 3) {
            func_800A0D50(&sp40, &D_80110448_OpeningScene[2]->coords);
            func_800A0E80(&D_80110448_OpeningScene[i]->unk_18, &sp40, &D_80110448_OpeningScene[i]->coords);
        }
    }
    func_800A0E80(&D_80110448_OpeningScene[2]->unk_18, &D_80110448_OpeningScene[5]->coords, &D_80110448_OpeningScene[2]->coords);
    func_800A0E80(&D_80110448_OpeningScene[3]->unk_18, &D_80110448_OpeningScene[0]->coords, &D_80110448_OpeningScene[3]->coords);
    func_800A0D00(&D_80110448_OpeningScene[6]->coords, 0.0f, 0.0f, 300.0f);
    MBMotionShiftSet(D_80110448_OpeningScene[6], 4, 20, 0, 0);
    for (i = 15; i < 31; i++) {
        t = i / 30.0f;
        t = 1.0f - t * t;
        D_80110448_OpeningScene[6]->coords.y = 0.0f;
        D_80110448_OpeningScene[6]->unk_30 = t * 80.0f * 5.0f;
        HuPrcSleep(0);
    }
    D_80110448_OpeningScene[6]->coords.y = -13.333334f;
    func_800FC724_OpeningScene();
    MBMotionShiftSet(D_80110448_OpeningScene[6], -1, 20, 0, 2);
    for (i = 0; i < 6; i++) {
        func_800FBD48_OpeningScene(D_80110448_OpeningScene[i], &D_80110448_OpeningScene[6]->coords, 10.0f);
    }
    MBMotionShiftSet(D_80110448_OpeningScene[2], 0, 0, 10, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[4], 0, 0, 10, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[0], 0, 0, 10, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[1], 0, 0, 10, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[3], 5, 0, 10, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[5], 7, 0, 10, 2);
    HuPrcSleep(1);
    D_80110448_OpeningScene[6]->coords.y = 0.0f;
    HuPrcSleep(1);
    func_8004F00C(D_80110448_OpeningScene[6], 4.0f, -1.2f);
    HuPrcSleep(8);
    MBMotionShiftSet(D_80110448_OpeningScene[2], -1, 0, 20, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[4], -1, 0, 20, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[0], -1, 0, 20, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[1], -1, 0, 20, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[3], -1, 0, 20, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[5], -1, 0, 20, 2);
    HuPrcSleep(40);
    func_800FC6BC_OpeningScene((void*)0x43D, 0x78);
}
void func_800F8D3C_OpeningScene(void) {
    Vec3f sp18 = { 680.75f, 60.31f, 655.42f };
    Vec3f sp28 = { -13.46f, 51.22f, 920.31f };
    Vec3f sp38 = D_800FD4D0_OpeningScene;
    Vec3f sp48 = { -13.46f, 0.0f, 920.31f };
    Vec3f sp58;
    Vec3f sp68;
    Vec3f sp78;
    f32 k;
    s32 i;

    func_800FC48C_OpeningScene(sp18.x, sp18.y, sp18.z);
    func_800FC4C0_OpeningScene(sp28.x, sp28.y, sp28.z);
    func_800FC4F4_OpeningScene(0.0f, 1.0f, 0.0f);
    func_800FB7F8_OpeningScene(30.0f, 10.0f, 8000.0f);
    for (i = 0; i < 6; i++) {
        MBModelDispOff(D_80110448_OpeningScene[i]);
    }
    func_800A0D50(&D_80110448_OpeningScene[6]->coords, &sp48);
    func_800A0E80(&D_80110448_OpeningScene[6]->unk_18, &D_800FD6D0_OpeningScene[0], &D_80110448_OpeningScene[6]->coords);
    func_800A0D50(&sp78, &D_80110448_OpeningScene[6]->coords);
    func_800A0D00(&sp58, D_80110448_OpeningScene[6]->coords.x - D_800FD6D0_OpeningScene[0].x, 0.0f,
                  D_80110448_OpeningScene[6]->coords.z - D_800FD6D0_OpeningScene[0].z);
    func_800A14F0(&sp68, &sp58, &sp38);
    guNormalize(&sp68.x, &sp68.y, &sp68.z);
    MBMotionShiftSet(D_80110448_OpeningScene[6], -1, 0, 8, 2);
    HuPrcSleep(8);
    func_800A0D50(&sp58, &D_800FD6D0_OpeningScene[0]);
    func_800FBD48_OpeningScene(D_80110448_OpeningScene[6], &sp58, 20.0f);
    HuPrcSleep(30);
    k = 50.0f;
    func_800A0D00(&sp58, sp68.x * k + sp78.x, sp68.y * k + sp78.y, sp68.z * k + sp78.z);
    func_800FBD48_OpeningScene(D_80110448_OpeningScene[6], &sp58, 20.0f);
    HuPrcSleep(20);
    MBMotionShiftSet(D_80110448_OpeningScene[6], 2, 0, 8, 2);
    func_800FBD14_OpeningScene(D_80110448_OpeningScene[6], &sp58, 50.0f);
    HuPrcSleep(10);
    func_800FC5CC_OpeningScene((void*)0x43E, 0);
    HuPrcSleep(40);
    k = -50.0f;
    func_800A0D00(&sp58, sp68.x * k + sp78.x, sp68.y * k + sp78.y, sp68.z * k + sp78.z);
    func_800FBD48_OpeningScene(D_80110448_OpeningScene[6], &sp58, 20.0f);
    HuPrcSleep(20);
    MBMotionShiftSet(D_80110448_OpeningScene[6], 2, 0, 8, 2);
    func_800FBD14_OpeningScene(D_80110448_OpeningScene[6], &sp58, 100.0f);
    HuPrcSleep(40);
    func_800FC724_OpeningScene();
    HuPrcSleep(60);
    func_800FC5CC_OpeningScene((void*)0x43F, 0);
    k = 0.0f;
    func_800A0D00(&sp58, sp68.x * k + sp78.x, sp68.y * k + sp78.y, sp68.z * k + sp78.z);
    func_800FBD48_OpeningScene(D_80110448_OpeningScene[6], &sp58, 20.0f);
    HuPrcSleep(20);
    MBMotionShiftSet(D_80110448_OpeningScene[6], 2, 0, 8, 2);
    func_800FBD14_OpeningScene(D_80110448_OpeningScene[6], &sp58, 50.0f);
    HuPrcSleep(50);
    MBMotionSet(D_80110448_OpeningScene[6], -1, 2);
}
void func_800F916C_OpeningScene(void) {
    s32 i;

    func_800A0D00(&D_80110448_OpeningScene[2]->coords, 75.0f, 0.0f, 0.0f);
    func_800A0D00(&D_80110448_OpeningScene[4]->coords, -375.0f, 0.0f, 0.0f);
    func_800A0D00(&D_80110448_OpeningScene[0]->coords, 225.0f, 0.0f, 0.0f);
    func_800A0D00(&D_80110448_OpeningScene[1]->coords, 375.0f, 0.0f, 0.0f);
    func_800A0D00(&D_80110448_OpeningScene[5]->coords, -225.0f, 0.0f, 0.0f);
    func_800A0D00(&D_80110448_OpeningScene[3]->coords, -75.0f, 0.0f, 0.0f);
    func_800A0D00(&D_80110448_OpeningScene[6]->coords, 0.0f, 0.0f, -600.0f);
    MBModelDispOff(D_80110448_OpeningScene[6]);
    for (i = 0; i < 6; i++) {
        MBModelDispOn(D_80110448_OpeningScene[i]);
    }
    {
        Vec3f sp18[2] = { { -300.0f, 131.73f, 1200.0f }, { 450.0f, 131.73f, 1200.0f } };
        Vec3f sp30[2] = { { -300.0f, 131.73f, 0.0f }, { 450.0f, 131.73f, 0.0f } };
        Vec3f sp48 = D_800FD4D0_OpeningScene;
        Vec3f sp58;
        f32 t;
        s32 start;
        s32 end;

        func_800FB79C_OpeningScene(sp18, sp30, &sp48);
        D_800FD050_OpeningScene = 1;
        for (i = 0; i < 6; i++) {
            func_800A0D00(&sp58, 0.0f, 0.0f, 0.0f);
            func_800A0D00(&D_80110448_OpeningScene[i]->unk_18, 0.0f, 0.0f, 1.0f);
        }
        MBMotionSet(D_80110448_OpeningScene[4], 4, 2);
        MBMotionSet(D_80110448_OpeningScene[5], 5, 2);
        MBMotionSet(D_80110448_OpeningScene[3], 3, 2);
        MBMotionSet(D_80110448_OpeningScene[1], -1, 2);

        start = 0;
        end = 120;
        for (i = start; i < end; i++) {
            t = i * (1.0f / 720.0f);
            HuPrcSleep(0);
            func_800FC2B8_OpeningScene(&sp18[0], &sp18[1], t, &D_800FD6D0_OpeningScene[0]);
            func_800FC2B8_OpeningScene(&sp30[0], &sp30[1], t, &D_800FD6D0_OpeningScene[1]);
            if (i == 100) {
                MBMotionShiftSet(D_80110448_OpeningScene[4], -1, 0, 20, 2);
            }
        }
        start = end;
        end = 240;
        for (i = start; i < end; i++) {
            t = i * (1.0f / 720.0f);
            HuPrcSleep(0);
            func_800FC2B8_OpeningScene(&sp18[0], &sp18[1], t, &D_800FD6D0_OpeningScene[0]);
            func_800FC2B8_OpeningScene(&sp30[0], &sp30[1], t, &D_800FD6D0_OpeningScene[1]);
            if (i == end - 4) {
                func_800FC724_OpeningScene();
            }
        }
        func_800FC5CC_OpeningScene((void*)0x440, 0);
        start = end;
        end = 360;
        for (i = start; i < end; i++) {
            t = i * (1.0f / 720.0f);
            HuPrcSleep(0);
            func_800FC2B8_OpeningScene(&sp18[0], &sp18[1], t, &D_800FD6D0_OpeningScene[0]);
            func_800FC2B8_OpeningScene(&sp30[0], &sp30[1], t, &D_800FD6D0_OpeningScene[1]);
            if (i == start + 70) {
                MBMotionShiftSet(D_80110448_OpeningScene[2], 5, 0, 8, 2);
                MBMotionShiftSet(D_80110448_OpeningScene[1], 6, 0, 8, 2);
            }
            if (i == end - 4) {
                func_800FC724_OpeningScene();
            }
        }
        func_800FC5CC_OpeningScene((void*)0x441, 0);
        MBMotionShiftSet(D_80110448_OpeningScene[2], -1, 0, 20, 2);
        MBMotionShiftSet(D_80110448_OpeningScene[1], -1, 0, 16, 2);
        start = end;
        end = 600;
        for (i = start; i < end; i++) {
            t = i * (1.0f / 720.0f);
            HuPrcSleep(0);
            func_800FC2B8_OpeningScene(&sp18[0], &sp18[1], t, &D_800FD6D0_OpeningScene[0]);
            func_800FC2B8_OpeningScene(&sp30[0], &sp30[1], t, &D_800FD6D0_OpeningScene[1]);
            if (i == start + 40) {
                func_800FC724_OpeningScene();
                MBMotionShiftSet(D_80110448_OpeningScene[0], 5, 0, 8, 2);
                MBMotionShiftSet(D_80110448_OpeningScene[1], 6, 0, 20, 2);
            }
            if (i == start + 110) {
                MBMotionShiftSet(D_80110448_OpeningScene[0], -1, 0, 40, 2);
                MBMotionShiftSet(D_80110448_OpeningScene[1], -1, 0, 16, 2);
            }
            if (i == start + 170) {
                MBMotionShiftSet(D_80110448_OpeningScene[1], 8, 0, 20, 2);
            }
            if (i == end - 16) {
                MBMotionShiftSet(D_80110448_OpeningScene[1], -1, 0, 16, 2);
            }
        }
        HuPrcSleep(25);
        HuPrcSleep(15);
        func_800FC5CC_OpeningScene((void*)0x443, 0);
        HuPrcSleep(40);
        func_800FC724_OpeningScene();
        MBMotionShiftSet(D_80110448_OpeningScene[1], 4, 0, 8, 2);
        HuPrcSleep(60);
        D_800FD740_OpeningScene[0] = func_800FCD20_OpeningScene(40);
        HuPrcSleep(40);
        omDelObj(D_800FD740_OpeningScene[0]);
        func_8002456C(D_800FD780_OpeningScene);
    }
}
void func_800F983C_OpeningScene(void) {
    func_800FB40C_OpeningScene();
    D_800FD740_OpeningScene[0] = func_800FCB9C_OpeningScene(0x10);
    HuPrcSleep(0x10);
    omDelObj(D_800FD740_OpeningScene[0]);
    func_8002456C(D_800FD780_OpeningScene);
    func_800FC6BC_OpeningScene((void*)0x444, 0xBE);
    func_800FC6BC_OpeningScene((void*)0x445, 0xBE);
    func_800FC6BC_OpeningScene((void*)0x446, 0xBE);
    D_800FD740_OpeningScene[0] = func_800FCD20_OpeningScene(0x28);
    HuPrcSleep(0x28);
    omDelObj(D_800FD740_OpeningScene[0]);
    func_8002456C(D_800FD780_OpeningScene);
    func_800FB608_OpeningScene();
    HuPrcSleep(3);
}

void func_800F98F0_OpeningScene(void) {
    OpeningModel models[16];
    Vec3f rot;
    s32 i;
    s32 j;

    func_800FC394_OpeningScene(0);
    i = 0;
    func_800FBD98_OpeningScene(&models[i], D_800FD1EC_OpeningScene[i].file, 0, &D_800FD1EC_OpeningScene[i].pos,
                               D_800FD1EC_OpeningScene[i].flags);
    func_800A0D00(&rot, 0.0f, D_800FD1EC_OpeningScene[i].rotY, 0.0f);
    func_800FC264_OpeningScene(&models[i], &rot);
    for (; i < 7; i++) {
        if (D_800FD21C_OpeningScene[i].id == -1) {
            break;
        }
        D_80110448_OpeningScene[i] =
            func_800FBCC0_OpeningScene((u8)D_800FD21C_OpeningScene[i].id, D_800FD21C_OpeningScene[i].data);
        func_800A0D50(&D_80110448_OpeningScene[i]->coords, &D_800FD21C_OpeningScene[i].pos);
        func_80025F10(*D_80110448_OpeningScene[i]->unk_3C->unk_40, 1);
        func_80025EB4(*D_80110448_OpeningScene[i]->unk_3C->unk_40, 0, 2);
    }
    {
    Vec3f sp368 = { -375.02f, 60.5f, 195.0f };
    Vec3f sp378 = { -375.02f, 60.5f, 194.0f };
    Vec3f sp388 = D_800FD4D0_OpeningScene;
    Vec3f sp398;
    Vec3f pos;

    func_800FB79C_OpeningScene(&sp368, &sp378, &sp388);
    func_800FB7F8_OpeningScene(30.0f, 200.0f, 8000.0f);
    D_800FD050_OpeningScene = 1;
    for (j = 0; j < 6; j++) {
        if (D_800FD21C_OpeningScene[j].id == -1) {
            break;
        }
        func_800A0D00(&sp398, 0.0f, 0.0f, 0.0f);
        func_800A0D00(&D_80110448_OpeningScene[j]->unk_18, 0.0f, 0.0f, -1.0f);
    }
    MBModelDispOn(D_80110448_OpeningScene[6]);
    func_8004CCD0(&D_80110448_OpeningScene[6]->coords, &D_800FD6D0_OpeningScene[0], &D_80110448_OpeningScene[6]->unk_18);
    {
    omObjData* o = func_800FCB9C_OpeningScene(0x10);
    omObjData** obj = D_800FD740_OpeningScene;

    *obj = o;
    HuPrcSleep(0x24);
    omDelObj(*obj);
    }
    func_8002456C(D_800FD780_OpeningScene);
    func_800A0D00(&pos, -(D_800FD6D0_OpeningScene[0].x - D_80110448_OpeningScene[6]->coords.x) + D_80110448_OpeningScene[6]->coords.x,
                  -(D_800FD6D0_OpeningScene[0].y - D_80110448_OpeningScene[6]->coords.y) + D_80110448_OpeningScene[6]->coords.y,
                  -(D_800FD6D0_OpeningScene[0].z - D_80110448_OpeningScene[6]->coords.z) + D_80110448_OpeningScene[6]->coords.z);
    func_800FC6BC_OpeningScene((void*)0x447, 0x1E);
    func_800A0D00(&pos, -(D_800FD6D0_OpeningScene[0].x - D_80110448_OpeningScene[6]->coords.x) + D_80110448_OpeningScene[6]->coords.x,
                  -(D_800FD6D0_OpeningScene[0].y - D_80110448_OpeningScene[6]->coords.y) + D_80110448_OpeningScene[6]->coords.y,
                  -(D_800FD6D0_OpeningScene[0].z - D_80110448_OpeningScene[6]->coords.z) + D_80110448_OpeningScene[6]->coords.z);
    func_800FBD48_OpeningScene(D_80110448_OpeningScene[6], &pos, 8.0f);
    MBMotionShiftSet(D_80110448_OpeningScene[6], 5, 0, 8, 2);
    HuPrcSleep(0x30);
    func_800FC6BC_OpeningScene((void*)0x448, 0xAA);
    MBMotionShiftSet(D_80110448_OpeningScene[6], -1, 0, 8, 2);
    func_800FBD48_OpeningScene(D_80110448_OpeningScene[6], &D_800FD6D0_OpeningScene[0], 8.0f);
    HuPrcSleep(0x12);
    func_800FC6BC_OpeningScene((void*)0x449, 0x64);
    MBModelDispOff(D_80110448_OpeningScene[6]);
    {
    Vec3f sp3B8 = { -448.55f, 133.7f, -1232.47f };
    Vec3f sp3C8 = { -448.51f, 133.7f, -1231.48f };
    Vec3f sp3D8 = D_800FD4D0_OpeningScene;
    Vec3f target;
    Vec3f dir;

    for (j = 0; j < 6; j++) {
        func_8004CCD0(&D_80110448_OpeningScene[j]->coords, &D_80110448_OpeningScene[6]->coords,
                      &D_80110448_OpeningScene[j]->unk_18);
    }
    func_800FB79C_OpeningScene(&sp3B8, &sp3C8, &sp3D8);
    func_800FB7F8_OpeningScene(30.0f, 10.0f, 8000.0f);
    HuPrcSleep(0x1E);
    func_800A0D50(&dir, &D_80110448_OpeningScene[0]->unk_18);
    guNormalize(&dir.x, &dir.y, &dir.z);
    MBMotionShiftSet(D_80110448_OpeningScene[0], 2, 0, 0x14, 0);
    HuPrcSleep(0x14);
    func_8004F504(D_80110448_OpeningScene[0]);
    MBMotionShiftSet(D_80110448_OpeningScene[0], 3, 0, 10, 2);
    HuPrcSleep(10);
    func_800A0D00(&target, (dir.x * 35.0f + dir.z * 10.0f) * 5.0f + D_80110448_OpeningScene[0]->coords.x,
                  dir.y * 35.0f * 5.0f + D_80110448_OpeningScene[0]->coords.y,
                  (dir.z * 35.0f - dir.x * 10.0f) * 5.0f + D_80110448_OpeningScene[0]->coords.z);
    func_800FBD14_OpeningScene(D_80110448_OpeningScene[0], &target, 60.0f);
    HuPrcSleep(0x3C);
    MBMotionShiftSet(D_80110448_OpeningScene[0], -1, 0, 8, 2);
    HuPrcSleep(8);
    MBMotionShiftSet(D_80110448_OpeningScene[1], 1, 0, 0x14, 0);
    MBMotionShiftSet(D_80110448_OpeningScene[3], 1, 0, 0x14, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[2], 1, 0, 0x14, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[4], 1, 0, 0x14, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[5], 1, 0, 0x14, 2);
    func_8004F504(D_80110448_OpeningScene[1]);
    MBMotionShiftSet(D_80110448_OpeningScene[1], -1, 0, 8, 0);
    HuPrcSleep(0x14);
    func_800A0D00(&target, dir.x * 150.0f + D_80110448_OpeningScene[1]->coords.x,
                  dir.y * 150.0f + D_80110448_OpeningScene[1]->coords.y,
                  dir.z * 150.0f + D_80110448_OpeningScene[1]->coords.z);
    func_800FBD48_OpeningScene(D_80110448_OpeningScene[1], &target, 16.0f);
    HuPrcSleep(8);
    MBMotionShiftSet(D_80110448_OpeningScene[1], 2, 0, 8, 0);
    HuPrcSleep(8);
    func_800FBD14_OpeningScene(D_80110448_OpeningScene[1], &target, 20.0f);
    HuPrcSleep(10);
    MBMotionShiftSet(D_80110448_OpeningScene[0], 4, 0, 0x10, 0);
    func_800A0D00(&target, dir.x * 900.0f + D_80110448_OpeningScene[1]->coords.x,
                  dir.y * 900.0f + D_80110448_OpeningScene[1]->coords.y,
                  dir.z * 900.0f + D_80110448_OpeningScene[1]->coords.z);
    func_8004F504(D_80110448_OpeningScene[1]);
    MBMotionShiftSet(D_80110448_OpeningScene[1], 0, 0, 0xF, 2);
    func_800FBD14_OpeningScene(D_80110448_OpeningScene[1], &target, 60.0f);
    func_8004F504(D_80110448_OpeningScene[0]);
    MBMotionShiftSet(D_80110448_OpeningScene[0], 0, 0, 8, 2);
    HuPrcSleep(8);
    func_800A0D00(&target, dir.x * 800.0f + D_80110448_OpeningScene[0]->coords.x,
                  dir.y * 800.0f + D_80110448_OpeningScene[0]->coords.y,
                  dir.z * 800.0f + D_80110448_OpeningScene[0]->coords.z);
    func_800FBD14_OpeningScene(D_80110448_OpeningScene[0], &target, 50.0f);
    MBMotionShiftSet(D_80110448_OpeningScene[3], -1, 0, 0x1E, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[4], -1, 0, 0x1E, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[5], -1, 0, 0x1E, 2);
    MBMotionShiftSet(D_80110448_OpeningScene[2], -1, 0, 0x1E, 2);
    HuPrcSleep(0x1E);
    HuPrcSleep(8);
    func_800FBD48_OpeningScene(D_80110448_OpeningScene[2], &D_80110448_OpeningScene[1]->coords, 16.0f);
    func_800FBD48_OpeningScene(D_80110448_OpeningScene[4], &D_80110448_OpeningScene[1]->coords, 16.0f);
    func_800FBD7C_OpeningScene();
    sp3B8 = (Vec3f){ -1570.0f, 370.0f, -2860.0f };
    sp3C8 = (Vec3f){ -1046.71f, 218.79f, -1800.42f };
    {
    Vec3f sp408 = D_800FD4D0_OpeningScene;
    Vec3f from;
    Vec3f to;
    Vec3f dest;
    Vec3f vec;
    f32 dist;
    f32 dist2;
    f32 dist3;

    func_800A0D50(&sp3C8, &D_80110448_OpeningScene[2]->coords);
    sp3C8.y = 100.0f;
    func_800FB79C_OpeningScene(&sp3B8, &sp3C8, &sp408);
    func_800FB7F8_OpeningScene(30.0f, 1000.0f, 20000.0f);
    MBModelDispOn(D_80110448_OpeningScene[6]);
    func_800A0D50(&to, &D_800FD6D0_OpeningScene[0]);
    func_800A0D50(&from, &D_80110448_OpeningScene[1]->coords);
    func_800A0D00(&vec, to.x - from.x, to.y - from.y, to.z - from.z);
    vec.y = 0.0f;
    guNormalize(&vec.x, &vec.y, &vec.z);
    func_800A0D00(&dest, (dist = 840.0f) * vec.x + from.x, 0.0f, vec.z * dist + from.z);
    func_800A0D50(&D_80110448_OpeningScene[1]->coords, &dest);
    func_800A0D00(&D_80110448_OpeningScene[0]->coords, dest.x - vec.x * 200.0f, 0.0f, dest.z - vec.z * 200.0f);
    func_800A0D50(&from, &D_80110448_OpeningScene[2]->coords);
    func_800A0D00(&vec, to.x - from.x, to.y - from.y, to.z - from.z);
    guNormalize(&vec.x, &vec.y, &vec.z);
    func_800A0D00(&dest, vec.x * dist + from.x, 0.0f, vec.z * dist + from.z);
    func_800A0D50(&D_80110448_OpeningScene[2]->coords, &dest);
    func_800A0D50(&from, &D_80110448_OpeningScene[5]->coords);
    func_800A0D00(&vec, to.x - from.x, to.y - from.y, to.z - from.z);
    guNormalize(&vec.x, &vec.y, &vec.z);
    dist2 = 480.0f;
    func_800A0D00(&dest, vec.x * dist2 + from.x, 0.0f, vec.z * dist2 + from.z);
    func_800A0D50(&D_80110448_OpeningScene[5]->coords, &dest);
    func_800A0D50(&from, &D_80110448_OpeningScene[4]->coords);
    func_800A0D00(&vec, to.x - from.x, to.y - from.y, to.z - from.z);
    guNormalize(&vec.x, &vec.y, &vec.z);
    dist3 = 240.0f;
    func_800A0D00(&dest, vec.x * dist3 + from.x, 0.0f, vec.z * dist3 + from.z);
    func_800A0D50(&D_80110448_OpeningScene[4]->coords, &dest);
    MBMotionSet(D_80110448_OpeningScene[3], -1, 2);
    MBMotionSet(D_80110448_OpeningScene[1], 0, 2);
    MBMotionSet(D_80110448_OpeningScene[0], 0, 2);
    MBMotionSet(D_80110448_OpeningScene[2], 0, 2);
    MBMotionSet(D_80110448_OpeningScene[4], 0, 2);
    MBMotionSet(D_80110448_OpeningScene[5], 0, 2);
    for (j = 0; j < 6; j++) {
        func_8004CCD0(&D_80110448_OpeningScene[j]->coords, &D_800FD6D0_OpeningScene[0], &D_80110448_OpeningScene[j]->unk_18);
    }
    func_8004CCD0(&D_80110448_OpeningScene[6]->coords, &D_800FD6D0_OpeningScene[0], &D_80110448_OpeningScene[6]->unk_18);
    {
    s32 order[5] = { 1, 0, 4, 5, 2 };
    Vec3f objPos;
    Vec3f center;
    Vec3f goal;
    Vec3f away;
    f32 speed;

    speed = 120.0f;
    func_800A0D50(&center, &D_800FD6D0_OpeningScene[0]);
    for (i = 0; i < sizeof(order) / sizeof(order[0]); i++) {
        func_800A0D50(&objPos, &D_80110448_OpeningScene[order[i]]->coords);
        func_800A0D00(&away, center.x - objPos.x, center.y - objPos.y, center.z - objPos.z);
        away.y = 0.0f;
        guNormalize(&away.x, &away.y, &away.z);
        func_800A0D00(&goal, away.x * 2400.0f + objPos.x, 0.0f, away.z * 2400.0f + objPos.z);
        func_800FBD14_OpeningScene(D_80110448_OpeningScene[order[i]], &goal, speed + 20.0f);
    }
    HuPrcSleep(0xF);
    MBMotionSet(D_80110448_OpeningScene[3], 2, 0);
    func_8004F504(D_80110448_OpeningScene[3]);
    MBMotionShiftSet(D_80110448_OpeningScene[3], 0, 0, 0x14, 2);
    HuPrcSleep(0x14);
    func_800A0D50(&objPos, &D_80110448_OpeningScene[3]->coords);
    func_800A0D00(&away, center.x - objPos.x, center.y - objPos.y, center.z - objPos.z);
    away.y = 0.0f;
    guNormalize(&away.x, &away.y, &away.z);
    func_800A0D00(&goal, away.x * 600.0f + objPos.x, 0.0f, away.z * 600.0f + objPos.z);
    func_800FBD14_OpeningScene(D_80110448_OpeningScene[3], &goal, 60.0f);
    {
    omObjData* o = func_800FCD20_OpeningScene(0x28);
    omObjData** obj = D_800FD740_OpeningScene;

    *obj = o;
    HuPrcSleep(0x28);
    omDelObj(*obj);
    }
    func_8002456C(D_800FD780_OpeningScene);
    func_800FBEA8_OpeningScene(&models[0]);
    func_800FBB94_OpeningScene();
    HuPrcSleep(3);
    }
    }
    }
    }
}
void func_800FA990_OpeningScene(void) {
    OpeningModel models[16];
    OpeningSprite sprites[26];
    s32 pad[2]; /* retail reserves 0x140 bytes for sprites[] */
    Vec3f rot;
    s32 i;

    for (i = 0; i < 3; i++) {
        func_800FBD98_OpeningScene(&models[i], D_800FD2DC_OpeningScene[i].file, 0, &D_800FD2DC_OpeningScene[i].pos,
                                   D_800FD2DC_OpeningScene[i].flags);
        func_800A0D00(&rot, 0.0f, D_800FD2DC_OpeningScene[i].rotY, 0.0f);
        func_800FC264_OpeningScene(&models[i], &rot);
    }
    func_800FC134_OpeningScene(&models[1]);
    func_800FC134_OpeningScene(&models[2]);
    for (i = 0; i < 5; i++) {
        if (D_800FD33C_OpeningScene[i].id == -1) {
            break;
        }
        D_80110448_OpeningScene[i] =
            func_800FBCC0_OpeningScene((u8)D_800FD33C_OpeningScene[i].id, D_800FD33C_OpeningScene[i].data);
        func_800A0D50(&D_80110448_OpeningScene[i]->coords, &D_800FD33C_OpeningScene[i].pos);
        func_80025F10(*D_80110448_OpeningScene[i]->unk_3C->unk_40, 1);
        func_80025EB4(*D_80110448_OpeningScene[i]->unk_3C->unk_40, 0, 2);
    }
    func_800FBEEC_OpeningScene(&sprites[0], 0xE0004, 0x47F4, 0, 50, 320, 120);
    func_800FC110_OpeningScene(&sprites[0].group);
    func_800FC394_OpeningScene(0);
    {
    Vec3f sp4B0 = { 0.0f, 100.0f, 1000.0f };
    Vec3f sp4C0 = D_800FD4DC_OpeningScene;
    Vec3f sp4D0 = D_800FD4D0_OpeningScene;
    Vec3f sp4E0;
    Vec3f sp4F0 = { 0.0f, 5.0f, 0.0f };
    Vec3f sp500;

    func_800FB7F8_OpeningScene(45.0f, 80.0f, 13800.0f);
    func_800FC850_OpeningScene(models[1].model, 300.0f, 0.0f, &sp4B0);
    func_800FC850_OpeningScene(models[2].model, 300.0f, 0.0f, &sp4C0);
    func_800FB79C_OpeningScene(&sp4B0, &sp4C0, &sp4D0);
    D_800FD050_OpeningScene = 1;
    func_800A0D00(&sp4E0, 0.0f, 50.0f, 0.0f);
    for (i = 0; i < 5; i++) {
        if (D_800FD33C_OpeningScene[i].id == -1) {
            break;
        }
        MBMotionShiftSet(D_80110448_OpeningScene[i], 0, 0, 8, 2);
        func_8004CCD0(&D_80110448_OpeningScene[i]->coords, &sp4F0, &D_80110448_OpeningScene[i]->unk_18);
    }
    func_80023448(3);
    func_800234B8(0, 0x78, 0x78, 0x78);
    func_800234B8(1, 0x40, 0x40, 0x60);
    func_80023504(1, -100.0f, 100.0f, 100.0f);
    func_800234B8(2, 0, 0, 0);
    func_800234B8(3, 0, 0, 0);
    {
    omObjData* o = func_800FCB9C_OpeningScene(2);
    omObjData** obj = D_800FD740_OpeningScene;

    *obj = o;
    HuPrcSleep(2);
    omDelObj(*obj);
    }
    func_8002456C(D_800FD780_OpeningScene);
    {
    Vec3f sp510 = { 0.0f, 520.0f, -10.0f };

    for (i = 0; i < 0x128; i++) {
        if (i == 0x11C) {
            func_800726AC(0, 0xF);
            func_8005AE44();
        }
        func_800FC850_OpeningScene(models[1].model, 300.0f, i, &sp500);
        func_800A0D50(&D_800FD6D0_OpeningScene[0], &sp500);
        if (sp510.y + 200.0f <= sp500.y) {
            sp510.y -= 5.0f;
        }
        func_800FC850_OpeningScene(models[2].model, 300.0f, i, &sp500);
        func_800A0D50(&D_800FD6D0_OpeningScene[1], &sp510);
        HuPrcSleep(0);
    }
    HuPrcSleep(20);
    func_800FBEA8_OpeningScene(&models[0]);
    func_800FBEA8_OpeningScene(&models[1]);
    func_800FBEA8_OpeningScene(&models[2]);
    func_800FC0BC_OpeningScene(&sprites[0]);
    func_800FBB94_OpeningScene();
    HuPrcSleep(3);
    func_80072724(0xFF, 0xFF, 0xFF);
    func_800726AC(0, 0x28);
    HuPrcSleep(0x28);
    func_8002890C(0xFF, 0xFF, 0xFF);
    }
    }
}
void func_800FAEFC_OpeningScene(void) {
    Vec3f sp10 = { 0.0f, 0.0f, 1000.0f };
    Vec3f sp20 = D_800FD4DC_OpeningScene;
    Vec3f sp30 = D_800FD4D0_OpeningScene;
    Vec3f sp40[7] = {
        { 175.0f, 125.0f, 400.0f },
        { 250.0f, 0.0f, 500.0f },
        { 175.0f, -175.0f, 600.0f },
        { -175.0f, 125.0f, 400.0f },
        { -250.0f, 0.0f, 500.0f },
        { -175.0f, -175.0f, 600.0f },
        { 0.0f, -250.0f, 600.0f },
    };
    s32 sp98[6] = { 0x17, 0x18, 0x1A, 0x19, 0x1B, 0x1C };
    Vec3f spB0;
    Vec3f spC0;
    s32 i;
    s32 m;
    f32 t;
    f32 s;

    func_800FC394_OpeningScene(1);
    func_800FBAFC_OpeningScene();
    func_800FB79C_OpeningScene(&sp10, &sp20, &sp30);
    func_800FB7F8_OpeningScene(60.0f, 80.0f, 8000.0f);
    for (i = 0; i < sizeof(sp98) / sizeof(sp98[0]); i++) {
        D_80110448_OpeningScene[i] = func_800FBCC0_OpeningScene((u8)sp98[i], D_800FD434_OpeningScene[i]);
        func_800A0D00(&D_80110448_OpeningScene[i]->coords, sp40[i].x, sp40[i].y, sp40[i].z);
        func_800A0D00(&D_80110448_OpeningScene[i]->unk_18, 0.0f, 0.0f, 1.0f);
        MBModelDispOff(D_80110448_OpeningScene[i]);
        MBMotionSet(D_80110448_OpeningScene[i], 0, 0);
    }
    D_80110448_OpeningScene[i] = func_800FBCC0_OpeningScene(7, D_800FD434_OpeningScene[i]);
    func_80025EB4(*D_80110448_OpeningScene[i]->unk_3C->unk_40, 0, 0);
    func_800A0D00(&D_80110448_OpeningScene[i]->coords, sp40[i].x, sp40[i].y, sp40[i].z);
    func_800A0D00((Vec3f*)&D_80110448_OpeningScene[i]->xScale, 1.0f, 1.0f, 1.0f);
    func_800A0D00(&D_80110448_OpeningScene[i]->unk_18, 0.0f, 0.0f, 1.0f);
    MBModelDispOff(D_80110448_OpeningScene[i]);
    MBMotionSet(D_80110448_OpeningScene[i], 0, 0);
    func_8002890C(0xFF, 0xFF, 0xFF);
    for (i = 0; i < 7; i++) {
        MBModelDispOn(D_80110448_OpeningScene[i]);
        D_80110448_OpeningScene[i]->unk_0A |= 1;
    }
    func_80072724(0xFF, 0xFF, 0xFF);
    func_800726AC(0, 0x18);
    for (i = 50; i < 100; i += 2) {
        t = i * 0.01f;
        for (m = 0; m < 7; m++) {
            s = (t + t) * t;
            func_800A0D00(&spB0, 0.0f, 0.0f, 0.0f);
            func_800A0D50(&spC0, &sp40[m]);
            func_800A0D00(&D_80110448_OpeningScene[m]->unk_18, spC0.x - spB0.x, spC0.y - spB0.y, spC0.z - spB0.z);
            func_800A0D00(&D_80110448_OpeningScene[m]->coords, s * D_80110448_OpeningScene[m]->unk_18.x,
                          s * D_80110448_OpeningScene[m]->unk_18.y, s * D_80110448_OpeningScene[m]->unk_18.z);
        }
        HuPrcSleep(0);
    }
    func_800FBB94_OpeningScene();
    D_800FD738_OpeningScene = 1;
    while (TRUE) {
        HuPrcSleep(0);
    }
}
void func_800FB358_OpeningScene(void) {
    f32 f;
    f32 g;

    D_800FD708_OpeningScene = LoadFormFile(0x9001A, 0x299);
    func_80026040(D_800FD708_OpeningScene);
    func_80025F10(D_800FD708_OpeningScene, 1);
    g = f = 0.0f;
    while (TRUE) {
        HuPrcSleep(0);
        func_80027C1C(D_800FD708_OpeningScene, g, f, 0x20, 0x20);
        f += 0.5f;
    }
}
void func_800FB40C_OpeningScene(void) {
    Vec3f sp10 = { 349.0f, 29.25f, 0.0f };
    Vec3f sp20 = { 519.83f, 269.23f, 685.19f };
    s32 i;
    void* data;

    func_800FB670_OpeningScene(&sp10, &sp20, 6407.0f);
    func_800FB7F8_OpeningScene(20.0f, 80.0f, 13000.0f);
    for (i = 0; i < 6; i++) {
        D_800FD710_OpeningScene[i] = LoadFormFile(D_800FD054_OpeningScene[i].file, 0x289);
        func_80025EB4(D_800FD710_OpeningScene[i], 0, 1);
        func_80025F10(D_800FD710_OpeningScene[i], 1);
        func_80025798(D_800FD710_OpeningScene[i], D_800FD054_OpeningScene[i].x, D_800FD054_OpeningScene[i].y,
                      D_800FD054_OpeningScene[i].z);
        func_800257E4(D_800FD710_OpeningScene[i], 0.0f, D_800FD054_OpeningScene[i].rotY, 0.0f);
        func_80025830(D_800FD710_OpeningScene[i], 1.0f, 1.0f, 1.0f);
    }
    data = DataRead(0x90021);
    func_80038A9C(D_800F2B7C[D_800FD710_OpeningScene[3]].unk_6C, data, 0, "02tt004a_DEF");
    DataClose(data);
    func_80025AD4(D_800FD710_OpeningScene[3]);
    func_80025B34(D_800FD710_OpeningScene[3]);
    D_800FD730_OpeningScene[0] = omAddPrcObj(func_800FB358_OpeningScene, 0x3F00, 0x800, 0);
}
void func_800FB608_OpeningScene(void) {
    s32 i;

    EndProcess(D_800FD730_OpeningScene[0]);
    func_8002456C(D_800FD708_OpeningScene);
    for (i = 0; i < 6; i++) {
        func_8002456C(D_800FD710_OpeningScene[i]);
    }
}
void func_800FB670_OpeningScene(Vec3f* arg0, Vec3f* arg1, f32 arg2) {
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f22;
    f32 temp_f22_2;
    f32 temp_f22_3;
    f32 temp_f24;
    f32 temp_f24_2;

    temp_f22 = func_800AEAC0(arg0->y);
    temp_f22_2 = (temp_f22 * func_800AEFD0(arg0->z) * arg2) + arg1->x;
    temp_f24 = (-func_800AEAC0(arg0->x) * arg2) + arg1->y;
    temp_f20 = func_800AEFD0(arg0->y);
    func_800FC48C_OpeningScene(temp_f22_2, temp_f24, (temp_f20 * func_800AEFD0(arg0->x) * arg2) + arg1->z);
    func_800FC4C0_OpeningScene(arg1->x, arg1->y, arg1->z);
    temp_f20_2 = func_800AEAC0(arg0->y);
    temp_f20_3 = temp_f20_2 * func_800AEAC0(arg0->x);
    temp_f24_2 = func_800AEFD0(arg0->x);
    temp_f22_3 = func_800AEFD0(arg0->y);
    func_800FC4F4_OpeningScene(temp_f20_3, temp_f24_2, temp_f22_3 * func_800AEAC0(arg0->x));
}

void func_800FB79C_OpeningScene(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2) {
    func_800FC48C_OpeningScene(arg0->x, arg0->y, arg0->z);
    func_800FC4C0_OpeningScene(arg1->x, arg1->y, arg1->z);
    func_800FC4F4_OpeningScene(arg2->x, arg2->y, arg2->z);
}
void func_800FB7F8_OpeningScene(f32 x, f32 y, f32 z) {
    D_800FD6D0_OpeningScene[3].x = x;
    D_800FD6D0_OpeningScene[3].y = y;
    D_800FD6D0_OpeningScene[3].z = z;
}

void func_800FB810_OpeningScene(omObjData* arg0) {
    func_8001D494(0, D_800FD6D0_OpeningScene[3].x, D_800FD6D0_OpeningScene[3].y, D_800FD6D0_OpeningScene[3].z);
    func_8001D420(0, &D_800FD6D0_OpeningScene[0], &D_800FD6D0_OpeningScene[1], &D_800FD6D0_OpeningScene[2]);
    func_8001D57C(0);
}
void func_800FB864_OpeningScene(void) {
}

void func_800FB86C_OpeningScene(void) {
    D_800FD738_OpeningScene = 0;
    func_800FBAFC_OpeningScene();
    func_800FBAC0_OpeningScene();
    HuPrcSleep(3);
    omAddObj(0x1000, 0, 0, -1, func_800FB97C_OpeningScene);
    rand8();
    rand8();
    HuPrcDestructorSet(func_800FB864_OpeningScene);
    func_800F6AB8_OpeningScene();
    func_800F983C_OpeningScene();
    func_800F98F0_OpeningScene();
    func_800FA990_OpeningScene();
    func_800FAEFC_OpeningScene();
    D_800FD738_OpeningScene = 1;
    while (1) {
        HuPrcSleep(0);
    }
}
void func_800FB91C_OpeningScene(void) {
    if (func_80072718() == 0) {
        func_80070ED4();
        func_800FBB94_OpeningScene();
        func_800FBC9C_OpeningScene();
        func_800FC394_OpeningScene(1);
        D_800F5144 = 1;
        omOvlGotoEx(0x67, 1, 0x91);
    }
}
void func_800FB97C_OpeningScene(omObjData* arg0) {
    s32 skip;
    s32 i;
    Process* proc;

    skip = 0;
    if (func_80072718() == 0) {
        if (D_800C572F == 0) {
            arg0->rot.x -= 1.0f;
            for (i = 0; i < 4; i++) {
                if (func_800141FC(i) != 0) {
                    if (ContBtnTrg[i] & 0x1000) {
                        D_800FD738_OpeningScene = 1;
                        skip = 1;
                    }
                    break;
                }
            }
        }
        if (D_800FD738_OpeningScene != 0) {
            if (skip == 0) {
                func_80072724(0xFF, 0xFF, 0xFF);
            } else {
                func_80072724(0, 0, 0);
                func_800601D4(0x50);
                func_800726AC(0, 0x28);
            }
            proc = D_800FD730_OpeningScene[1];
            proc->stat &= 0xFFFE;
            EndProcess(proc);
            arg0->func_ptr = func_800FB91C_OpeningScene;
        }
    }
}
s32 func_800FBAC0_OpeningScene(void) {
    func_800178A0(1);
    func_800FC394_OpeningScene(0);
    LoadBackgroundData(FE2310_ROM_START);
    func_8004B1B8();
    return 1;
}

s32 func_800FBAFC_OpeningScene(void) {
    s32 i;

    MBModelInit();
    func_8004FB14();
    func_8004E154();
    func_8004F2AC();
    func_8004F548();
    for (i = 0; i < 16; i++) {
        D_801102B8[i] = -1;
        D_80110300[i] = NULL;
        D_80110448_OpeningScene[i] = NULL;
        D_80110400[i] = NULL;
    }
    return 16;
}
void func_800FBB94_OpeningScene(void) {
    s32 i;

    func_800FBD7C_OpeningScene();
    for (i = 0; i < 16; i++) {
        if (D_801102B8[i] != -1) {
            func_8002456C(D_801102B8[i]);
            D_801102B8[i] = -1;
        }
        if (D_80110300[i] != NULL) {
            omDelObj(D_80110300[i]);
            D_80110300[i] = NULL;
        }
        if (D_80110448_OpeningScene[i] != NULL) {
            MBModelKill(D_80110448_OpeningScene[i]);
            D_80110448_OpeningScene[i] = NULL;
        }
        if (D_80110400[i] != NULL) {
            func_800427D4(D_80110400[i]);
            D_80110400[i] = NULL;
        }
    }
}
void func_800FBC9C_OpeningScene(void) {
    func_8004A140();
    func_80049F0C();
}
Object* func_800FBCC0_OpeningScene(s32 arg0, void* arg1) {
    Object* temp_v0;

    temp_v0 = MBModelCreate(arg0, arg1);
    func_80025F60(*temp_v0->unk_3C->unk_40, 0x800);
    func_80025F60(*temp_v0->unk_40->unk_40, 0x400);
    return temp_v0;
}

void func_800FBD14_OpeningScene(Object* arg0, Vec3f* arg1, f32 arg2) {
    func_8004E3E0(0, arg1, (s32)arg2, arg0);
}
void func_800FBD48_OpeningScene(Object* arg0, Vec3f* arg1, f32 arg2) {
    func_8004EE14(0, arg1, arg2, arg0);
}

void func_800FBD7C_OpeningScene(void) {
    func_8004E184();
}

// retail copies the flags stack argument into a second callee-saved register (frame 72 vs 64; masked 11);
// retail tests arg3 & 2 in place on the original and keeps the copy for & 1; tried a late flags = arg3 & 1 (M1c)
#ifdef NON_MATCHING
s16 func_800FBD98_OpeningScene(OpeningModel* arg0, s32 arg1, s32 unused, Vec3f* arg2, s32 arg3) {
    Vec3f sp10;
    Vec3f sp20;
    s32 flags;

    flags = arg3;
    sp10 = D_800FD520_OpeningScene;
    sp20 = D_800FD4DC_OpeningScene;

    arg0->model = LoadFormFile(arg1, 0x2A9);
    arg0->self = arg0;
    if (arg3 & 2) {
        func_80025F60(arg0->model2, 0x800);
        arg0->model2 = LoadFormFile(0x20, 0x629);
        arg0->self2 = &arg0->model2;
    } else {
        arg0->model2 = -1;
        arg0->self2 = NULL;
    }
    func_800FC17C_OpeningScene(arg0, arg2);
    func_800FC1F0_OpeningScene(arg0, &sp10);
    func_800FC264_OpeningScene(arg0, &sp20);
    if (flags & 1) {
        func_80025B34(arg0->model);
    }
    return arg0->model;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_OpeningScene/29B410", func_800FBD98_OpeningScene);
#endif
s32 func_800FBEA8_OpeningScene(OpeningModel* arg0) {
    func_8002456C(arg0->model);
    if (arg0->self2 != NULL) {
        func_8002456C(arg0->model2);
    }
    return 0;
}
void func_800FBEEC_OpeningScene(OpeningSprite* arg0, s32 arg1, u16 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    void* temp_v0;
    OpeningSpriteObj* temp_v1;
    f32 cx;
    f32 cy;
    f32 sx;
    f32 sy;

    cx = arg3 + (arg5 / 2);
    cy = arg4 + (arg6 / 2);
    arg0->group = func_80064EF4(1, 5);
    temp_v0 = DataRead(arg1);
    arg0->sprite = func_800678A4(temp_v0);
    DataClose(temp_v0);
    func_80067208(arg0->group, 0, arg0->sprite, 0);
    func_80067384(arg0->group, 0, arg2);
    func_800674BC(arg0->group, 0, 0xD000);
    func_80066DC4(arg0->group, 0, cx, cy);
    arg0->x = arg3;
    arg0->y = arg4;
    temp_v1 = func_800675F4(arg0->group, 0);
    sx = (f32)arg5 / (f32)temp_v1->info->width;
    sy = (f32)arg6 / (f32)temp_v1->info->height;
    func_80067354(arg0->group, 0, sx, sy);
}
void func_800FC0BC_OpeningScene(OpeningSprite* arg0) {
    func_80064D38(arg0->group);
    func_80067704(arg0->sprite);
}
void func_800FC0EC_OpeningScene(s16* arg0) {
    func_800674BC(*arg0, 0, 0x8000);
}
void func_800FC110_OpeningScene(s16* arg0) {
    func_80067480(*arg0, 0, 0x8000);
}
void func_800FC134_OpeningScene(OpeningModel* arg0) {
    func_800258EC(arg0->model, 4, 4);
    if (arg0->self2 != NULL) {
        func_800258EC(arg0->model2, 4, 4);
    }
}
void func_800FC17C_OpeningScene(OpeningModel* arg0, Vec3f* arg1) {
    s16 temp_a0;

    func_80025798(arg0->model, arg1->x, arg1->y, arg1->z);
    func_800A0D00(&arg0->posA, arg1->x, arg1->y, arg1->z);
    temp_a0 = arg0->model2;
    if (temp_a0 != -1) {
        func_80025798(temp_a0, arg1->x, arg1->y, arg1->z);
    }
}
void func_800FC1F0_OpeningScene(OpeningModel* arg0, Vec3f* arg1) {
    s16 temp_a0;

    func_80025830(arg0->model, arg1->x, arg1->y, arg1->z);
    func_800A0D00(&arg0->posC, arg1->x, arg1->y, arg1->z);
    temp_a0 = arg0->model2;
    if (temp_a0 != -1) {
        func_80025830(temp_a0, arg1->x, arg1->y, arg1->z);
    }
}
void func_800FC264_OpeningScene(OpeningModel* arg0, Vec3f* arg1) {
    func_800257E4(arg0->model, arg1->x, arg1->y, arg1->z);
    func_800A0D00(&arg0->posB, arg1->x, arg1->y, arg1->z);
}
void func_800FC2B8_OpeningScene(Vec3f* arg0, Vec3f* arg1, f32 arg2, Vec3f* arg3) {
    Vec3f sp10;
    f32 t;

    t = arg2;
    if (t > 1.0f) {
        t = 1.0f;
    }
    func_800A0D00(&sp10, arg1->x - arg0->x, arg1->y - arg0->y, arg1->z - arg0->z);
    func_800A0D00(arg3, (t * sp10.x) + arg0->x, (t * sp10.y) + arg0->y, (t * sp10.z) + arg0->z);
}
void func_800FC394_OpeningScene(s32 arg0) {
    switch (arg0) {
        case 0:
            func_80017660(0, 0.0f, 50.0f, 320.0f, 170.0f);
            func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 432.0f, 511.0f);
            break;
        case 1:
            func_80017660(0, 0.0f, 0.0f, 320.0f, 240.0f);
            func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
            break;
        default:
            func_80017660(0, 0.0f, 24.0f, 320.0f, 196.0f);
            func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 432.0f, 511.0f);
            break;
    }
}

void func_800FC48C_OpeningScene(f32 arg0, f32 arg1, f32 arg2) {
    func_800A0D00(&D_800FD6D0_OpeningScene[0], arg0, arg1, arg2);
}
void func_800FC4C0_OpeningScene(f32 arg0, f32 arg1, f32 arg2) {
    func_800A0D00(&D_800FD6D0_OpeningScene[1], arg0, arg1, arg2);
}
void func_800FC4F4_OpeningScene(f32 arg0, f32 arg1, f32 arg2) {
    func_800A0D00(&D_800FD6D0_OpeningScene[2], arg0, arg1, arg2);
}
s32 func_800FC528_OpeningScene(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s16 temp_v0;
    s32 win;

    temp_v0 = func_8006D010(arg0, arg1, (arg2 * 0xB) + 8, (arg3 * 0xE) + 6, 0, 0);
    win = temp_v0;
    func_8006E070(win, 0);
    func_8006E154(win, 0xC8);
    func_800717C0(temp_v0);
    return temp_v0;
}

void func_800FC5CC_OpeningScene(void *arg0, s32 arg1) {
    D_800FD700_OpeningScene = func_800FC528_OpeningScene(0x18, 0xB4, 0x18, 2);
    func_8006E2B8(D_800FD700_OpeningScene, 0, 0, 0);
    func_800714F0(D_800FD700_OpeningScene, 0xFF, 0xFF, 0xFF);
    func_8006E154(D_800FD700_OpeningScene, 0);
    func_8006E288(D_800FD700_OpeningScene, 7);
    LoadStringIntoWindow(D_800FD700_OpeningScene, arg0, -1, -1);
    if (arg1 == -1) {
        while ((func_8006FCC0(D_800FD700_OpeningScene)) != 0) {
            HuPrcVSleep();
        }
    } else if (arg1 > 0) {
        HuPrcSleep(arg1);
    }
}

void func_800FC6BC_OpeningScene(void* arg0, s32 arg1) {
    func_800FC5CC_OpeningScene(arg0, 0);
    if (arg1 == 0) {
        while (func_8006FCC0((s16)D_800FD700_OpeningScene) != 0) {
            HuPrcVSleep();
        }
    } else {
        HuPrcSleep(arg1);
    }
    func_800FC758_OpeningScene();
}
void func_800FC724_OpeningScene(void) {
    func_8006EB40((s16)D_800FD700_OpeningScene);
    func_80070D90((s16)D_800FD700_OpeningScene);
}
void func_800FC758_OpeningScene(void) {
    func_800FC724_OpeningScene();
    HuPrcSleep(2);
}

void func_800FC77C_OpeningScene(Vec3f* arg0, f32* arg1, f32 arg2, Vec3f* arg3) {
    f32 xs[4];
    f32 ys[4];
    f32 zs[4];
    f32 ts[4];
    s32 i;

    for (i = 0; i < 4; i++) {
        xs[i] = arg0[i].x;
        ys[i] = arg0[i].y;
        zs[i] = arg0[i].z;
        ts[i] = arg1[i];
    }
    arg3->x = func_80022D9C(xs, ts, arg2);
    arg3->y = func_80022D9C(ys, ts, arg2);
    arg3->z = func_80022D9C(zs, ts, arg2);
}
// decomp-permuter
void func_800FC850_OpeningScene(s16 arg0, f32 arg1, f32 arg2, Vec3f *arg3)
{
  Vec3f pts[4];
  f32 ts[4];
  f32 step;
  unk2C0C0StructC0 *model;
  unk2C0C0StructA0 *verts;
  unk2C0C0StructA0 *p;
  s32 cnt;
  s32 n;
  s32 idx;
  model = D_800F2B7C[arg0].unk_6C;
  verts = model->unk_78 + 1;
  cnt = model->unk_6E;
  n = cnt - 3;
  step = arg1 / ((f32) n);
  idx = (s32) (arg2 / step);
  if ((idx + 1) >= n)
  {
    idx = cnt - 4;
  }
  else
    if (idx < 0)
  {
    idx = -1;
  }
  ;
  func_800A0D00(&pts[0], (&verts[idx])[-1].unk_00, (&verts[idx])[-1].unk_02, (&verts[idx])[-1].unk_04);
  ts[0] = step * ((f32) (idx - 1));
  func_800A0D00(&pts[1], (&verts[idx])[0].unk_00, (&verts[idx])[0].unk_02, (&verts[idx])[0].unk_04);
  ts[1] = step * ((f32) idx);
  func_800A0D00(&pts[2], (&verts[idx])[1].unk_00, (&verts[idx])[1].unk_02, (&verts[idx])[1].unk_04);
  ts[2] = step * ((f32) (idx + 1));
  func_800A0D00(&pts[3], (&verts[idx])[2].unk_00, (&verts[idx])[2].unk_02, (&verts[idx])[2].unk_04);
  ts[3] = step * ((f32) (idx + 2));
  func_800FC77C_OpeningScene(pts, ts, arg2, arg3);
}

void func_800FCAB0_OpeningScene(omObjData* arg0) {
    f32 temp_f20;
    f32 var_f2;

    temp_f20 = arg0->rot.x;
    var_f2 = temp_f20 / arg0->rot.y;
    if (var_f2 < 0.0f) {
        var_f2 = 0.0f;
    }
    func_800FCECC_OpeningScene(0, 0, 0, (u32)(var_f2 * 255.0f));
    temp_f20 -= 1.0f;
    if (temp_f20 < 0.0f) {
        temp_f20 = 0.0f;
    }
    arg0->rot.x = temp_f20;
}
omObjData* func_800FCB9C_OpeningScene(s32 arg0) {
    f32 temp_f0;
    omObjData* temp_v0;
    s16 temp_s2;

    temp_s2 = func_800FCE9C_OpeningScene();
    func_800FCECC_OpeningScene(0, 0, 0, 0xFF);
    temp_v0 = omAddObj(0x1000, 0, 0, -1, func_800FCAB0_OpeningScene);
    temp_f0 = arg0;
    omSetRot(temp_v0, temp_f0, temp_f0, 0.0f);
    D_800FD780_OpeningScene = temp_s2;
    return temp_v0;
}
void func_800FCC3C_OpeningScene(omObjData* arg0) {
    f32 temp_f20;
    f32 temp_f22;
    f32 var_f2;

    temp_f20 = arg0->rot.x;
    temp_f22 = arg0->rot.y;
    var_f2 = temp_f20 / temp_f22;
    if (temp_f22 < var_f2) {
        var_f2 = temp_f22;
    }
    func_800FCECC_OpeningScene(0, 0, 0, (u32)(var_f2 * 255.0f));
    temp_f20 += 1.0f;
    if (temp_f22 < temp_f20) {
        temp_f20 = temp_f22;
    }
    arg0->rot.x = temp_f20;
}
omObjData* func_800FCD20_OpeningScene(s32 arg0) {
    omObjData* temp_v0;
    s16 temp_s2;

    temp_s2 = func_800FCE9C_OpeningScene();
    func_800FCECC_OpeningScene(0, 0, 0, 0xFF);
    func_800FCEE8_OpeningScene(0.0f);
    temp_v0 = omAddObj(0x1000, 0, 0, -1, func_800FCC3C_OpeningScene);
    omSetRot(temp_v0, 0.0f, (f32)arg0, 0.0f);
    D_800FD780_OpeningScene = temp_s2;
    return temp_v0;
}
void func_800FCDCC_OpeningScene(Gfx** arg0) {
    gSPDisplayList((*arg0)++, D_800FD450_OpeningScene);
    gDPSetRenderMode((*arg0)++, 0x5041C8, 0);
    gDPSetCombineMode((*arg0)++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor((*arg0)++, 0, 0, D_800FD782_OpeningScene[0], D_800FD782_OpeningScene[1], D_800FD782_OpeningScene[2], D_800FD782_OpeningScene[3]);
    gDPFillRectangle((*arg0)++, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}
s16 func_800FCE9C_OpeningScene(void) {
    return func_8002451C(0, func_800FCDCC_OpeningScene, 2);
}
void func_800FCECC_OpeningScene(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    D_800FD782_OpeningScene[0] = arg0;
    D_800FD782_OpeningScene[1] = arg1;
    D_800FD782_OpeningScene[2] = arg2;
    D_800FD782_OpeningScene[3] = arg3;
}
void func_800FCEE8_OpeningScene(f32 arg0) {
    D_800FD794_OpeningScene = arg0;
}
