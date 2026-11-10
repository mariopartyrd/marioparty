#include "ending.h"

#define ENDING_BOARD D_801102B0_YoshisTropicalIslandEndingScene
/* ending.h: s32[2]; retail only ever uses it as a scalar (see the fork report) */

/* DK's Jungle Adventure ending (board 0): func_800F8848 (setup), func_800F8550 (scene) */

s32 func_8004FBEC(s32, s32, char*);
void func_8004FAB8(s32);
void func_8004FB50(s32);
f32 func_80025D40(s16);
void func_80028C64(s16, u8, u8, u8, u8);
void func_8004B7F8(s32);

void func_800F6D40_YoshisTropicalIslandEndingScene(void);
void func_800F717C_YoshisTropicalIslandEndingScene(omObjData* arg0);
void func_800F72C4_YoshisTropicalIslandEndingScene(omObjData* arg0);
void func_800F7384_YoshisTropicalIslandEndingScene(omObjData* arg0);
void func_800F74E0_YoshisTropicalIslandEndingScene(omObjData* arg0);
void func_800F759C_YoshisTropicalIslandEndingScene(void);
void func_800F8574_YoshisTropicalIslandEndingScene(omObjData* arg0);
void func_800F8620_YoshisTropicalIslandEndingScene(omObjData* arg0);

#define ENDING_CENTER D_8010DC9C_YoshisTropicalIslandEndingScene

/* .data 0x8010DDE0-0x8010E08F */
Vec3f D_8010DDE0_YoshisTropicalIslandEndingScene = { -1000.0f, 0.0f, -600.0f };
Vec3f D_8010DDEC_YoshisTropicalIslandEndingScene = { -3.0f, -10.0f, -35.0f }; /* splat: D_8010DDF0 = .y */
Vec3f D_8010DDF8_YoshisTropicalIslandEndingScene = { -1391.074951171875f, 163.9010009765625f, -806.0399780273438f };
Vec3f D_8010DE04_YoshisTropicalIslandEndingScene = { -109.54600524902344f, -167.447998046875f, -1129.89501953125f };
/* no splat label (reached from D_8010DE1C - 12); splat labels inside: D_8010DE1C [1], D_8010DE28 [2],
   D_8010DE34 [3] */
Vec3f D_8010DE10_YoshisTropicalIslandEndingScene[5] = {
    { -109.54600524902344f, 32.55199432373047f, -1129.89501953125f },
    { -109.54600524902344f, 450.0f, -1129.89501953125f },
    { -109.54600524902344f, 1000.0f, -1129.89501953125f },
    { 25.0f, 550.0f, 2820.0f },
    { 25.0f, 350.0f, 2570.0f },
};
/* splat labels inside: D_8010DE58 [0][1], D_8010DE70 [1][1], D_8010DE88 [2][1], D_8010DEF4 [7][0],
   D_8010DF00 [7][1] */
Vec3f D_8010DE4C_YoshisTropicalIslandEndingScene[8][2] = {
    { { 25.0f, 160.0f, 2820.0f }, { 25.0f, 160.0f, 3070.0f } },
    { { -400.0f, 160.0f, 2780.0f }, { -115.0f, 160.0f, 2780.0f } },
    { { 420.0f, 160.0f, 2725.0f }, { 250.0f, 160.0f, 2725.0f } },
    { { 150.0f, 160.0f, 2800.0f }, { 150.0f, 160.0f, 2800.0f } },
    { { 475.0f, 160.0f, 2570.0f }, { 210.0f, 160.0f, 2570.0f } },
    { { -440.0f, 160.0f, 2705.0f }, { -235.0f, 160.0f, 2705.0f } },
    { { -450.0f, 350.0f, 2580.0f }, { -180.0f, 250.0f, 2580.0f } },
    { { 25.0f, 390.0f, 4320.0f }, { 25.0f, 390.0f, 2800.0f } },
};
/* camera position and its per-frame step (func_8004B5DC) */
Vec3f D_8010DF0C_YoshisTropicalIslandEndingScene[2] = {
    { 1723.0f, 0.0f, -872.0f },
    { -22.5f, 0.0f, 0.6000000238418579f },
};
Vec3f D_8010DF24_YoshisTropicalIslandEndingScene[3] = {
    { 1923.0f, 0.0f, -872.0f },
    { 400.0f, 0.0f, -767.0f },
    { 100.0f, 0.0f, -767.0f },
};
Vec3f D_8010DF48_YoshisTropicalIslandEndingScene = { -109.54600524902344f, 500.0f, -5000.0f };
/* MBModelCreate lists per character (count, file ids) */
s32 D_8010DF54_YoshisTropicalIslandEndingScene[7] = { 6, 0x0001003A, 0x00010000, 0x00010001, 0x00010003, 0x00010005, 0x00010096 };
s32 D_8010DF70_YoshisTropicalIslandEndingScene[7] = { 6, 0x0002003A, 0x00020000, 0x00020001, 0x00020003, 0x00020005, 0x00020096 };
s32 D_8010DF8C_YoshisTropicalIslandEndingScene[7] = { 6, 0x0006003A, 0x00060000, 0x00060001, 0x00060003, 0x00060005, 0x00060096 };
s32 D_8010DFA8_YoshisTropicalIslandEndingScene[7] = { 6, 0x0003003A, 0x00030000, 0x00030001, 0x00030003, 0x00030005, 0x00030096 };
s32 D_8010DFC4_YoshisTropicalIslandEndingScene[7] = { 6, 0x0004003A, 0x00040000, 0x00040001, 0x00040003, 0x00040005, 0x00040096 };
s32 D_8010DFE0_YoshisTropicalIslandEndingScene[7] = { 6, 0x0005003A, 0x00050000, 0x00050001, 0x00050003, 0x00050005, 0x00050096 };
s32* D_8010DFFC_YoshisTropicalIslandEndingScene[6] = {
    D_8010DF54_YoshisTropicalIslandEndingScene, D_8010DF70_YoshisTropicalIslandEndingScene,
    D_8010DF8C_YoshisTropicalIslandEndingScene, D_8010DFA8_YoshisTropicalIslandEndingScene,
    D_8010DFC4_YoshisTropicalIslandEndingScene, D_8010DFE0_YoshisTropicalIslandEndingScene,
};
s32 D_8010E014_YoshisTropicalIslandEndingScene[4] = { 3, 0x00010000, 0x00010001, 0x00010097 };
s32 D_8010E024_YoshisTropicalIslandEndingScene[4] = { 3, 0x00020000, 0x00020001, 0x00020097 };
s32 D_8010E034_YoshisTropicalIslandEndingScene[4] = { 3, 0x00060000, 0x00060001, 0x00060097 };
s32 D_8010E044_YoshisTropicalIslandEndingScene[4] = { 3, 0x00030000, 0x00030001, 0x00030097 };
s32 D_8010E054_YoshisTropicalIslandEndingScene[4] = { 3, 0x00040000, 0x00040001, 0x00040097 };
s32 D_8010E064_YoshisTropicalIslandEndingScene[4] = { 3, 0x00050000, 0x00050001, 0x00050097 };
s32* D_8010E074_YoshisTropicalIslandEndingScene[7] = {
    D_8010E014_YoshisTropicalIslandEndingScene, D_8010E024_YoshisTropicalIslandEndingScene,
    D_8010E034_YoshisTropicalIslandEndingScene, D_8010E044_YoshisTropicalIslandEndingScene,
    D_8010E054_YoshisTropicalIslandEndingScene, D_8010E064_YoshisTropicalIslandEndingScene,
    NULL,
};

/* .bss used only here */
extern s32 D_8010F850_YoshisTropicalIslandEndingScene; /* func_8004FBEC handle */

#define MODEL D_80110448_YoshisTropicalIslandEndingScene
#define OBJ D_80110300_YoshisTropicalIslandEndingScene

void func_800F6D40_YoshisTropicalIslandEndingScene(void) {
    f32 f;
    s32 faded;

    LoadBackgroundIndex(3);
    MODEL[0] = MBModelCreate(0x2A, NULL);
    MODEL[0]->coords.x = D_8010DDF8_YoshisTropicalIslandEndingScene.x;
    MODEL[0]->coords.y = D_8010DDF8_YoshisTropicalIslandEndingScene.y;
    MODEL[0]->coords.z = D_8010DDF8_YoshisTropicalIslandEndingScene.z;
    func_8004CCD0(&MODEL[0]->coords, &D_800F32A0->coords, &MODEL[0]->unk_18);
    func_80025EB4(*MODEL[0]->unk_3C->unk_40, 2, 1);
    MODEL[1] = MBModelCreate(0x25, NULL);
    MODEL[1]->coords.x = D_8010DDF8_YoshisTropicalIslandEndingScene.x;
    MODEL[1]->coords.y = D_8010DDF8_YoshisTropicalIslandEndingScene.y + 600.0f;
    MODEL[1]->coords.z = D_8010DDF8_YoshisTropicalIslandEndingScene.z;
    MODEL[1]->xScale = MODEL[1]->yScale = MODEL[1]->zScale = 0.75f;
    func_8004CCD0(&MODEL[1]->coords, &D_800F32A0->coords, &MODEL[1]->unk_18);
    MODEL[2] = MBModelCreate(0x4D, NULL);
    MODEL[2]->coords.x = D_8010DDF8_YoshisTropicalIslandEndingScene.x;
    MODEL[2]->coords.y = D_8010DDF8_YoshisTropicalIslandEndingScene.y;
    MODEL[2]->coords.z = D_8010DDF8_YoshisTropicalIslandEndingScene.z;
    D_8010F850_YoshisTropicalIslandEndingScene = func_8004FBEC(0xA013A, *MODEL[2]->unk_3C->unk_40, "m1e_020_IA44");
    PlaySound(0x4D);
    SetFadeInTypeAndTime(0, 0x10);
    HuPrcSleep(0x10);
    f = 600.0f;
    do {
        HuPrcVSleep();
        MODEL[1]->coords.y = f + D_8010DDF8_YoshisTropicalIslandEndingScene.y;
        f -= 10.0f;
    } while (f >= 170.0f);
    func_80072724(0xFF, 0xFF, 0xFF);
    func_800726AC(0, 0);
    PlaySound(0x4E);
    HuPrcSleep(0xA);
    MBModelKill(MODEL[0]);
    MODEL[0] = MBModelCreate(0x3F, NULL);
    MODEL[0]->coords.x = D_8010DDF8_YoshisTropicalIslandEndingScene.x;
    MODEL[0]->coords.y = D_8010DDF8_YoshisTropicalIslandEndingScene.y;
    MODEL[0]->coords.z = D_8010DDF8_YoshisTropicalIslandEndingScene.z;
    func_8004CCD0(&MODEL[0]->coords, &D_800F32A0->coords, &MODEL[0]->unk_18);
    func_80025EB4(*MODEL[0]->unk_3C->unk_40, 2, 1);
    MBModelKill(MODEL[1]);
    MODEL[1] = NULL;
    SetFadeInTypeAndTime(0, 0x30);
    HuPrcSleep(0x3A);
    func_80025EB4(*MODEL[0]->unk_3C->unk_40, 1, 0);
    D_800F2B7C[*MODEL[0]->unk_3C->unk_40].unk_4C = 0.3f;
    PlaySound(0x50);
    HuPrcSleep(0x5A);
    faded = 0;
    f = 0.0f;
    do {
        if (f == 112.5f) {
            func_80060128(2);
        }
        MODEL[2]->coords.y = f + D_8010DDF8_YoshisTropicalIslandEndingScene.y;
        if ((faded == 0) & (f >= 190.0f)) {
            func_800726AC(0, 0x10);
            faded = 1;
        }
        HuPrcVSleep();
        f += 3.75f;
    } while (f <= 250.0f);
    HuPrcSleep(5);
    func_8004A140();
}

// float register allocation: z/dx in f2/f4 vs f4/f6 (masked 5)
#ifdef NON_MATCHING
void func_800F717C_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    Object* model;
    f32 dz;
    f32 x;
    f32 dx;
    f32 z;
    s32 r;

    if (!(arg0->work[0] & 3)) {
        func_8004FA90(D_80110440_YoshisTropicalIslandEndingScene, 8.0f, 8.0f, 8.0f);
        r = rand8();
        model = MODEL[1];
        z = (f32)(r & 0x7F) + model->coords.z;
        dz = 63.0f;
        x = model->coords.x;
        dx = 80.0f;
        goto spawn;
    }
    if (!(arg0->work[0] & 1)) {
        func_8004FA90(D_80110440_YoshisTropicalIslandEndingScene, 5.0f, 5.0f, 5.0f);
        r = rand8();
        model = MODEL[0];
        z = ((f32)(r & 0x7F) + model->coords.z) - 63.0f;
        dz = 40.0f;
        x = model->coords.x;
        dx = 30.0f;
    spawn:
        func_8004F9F4(D_80110440_YoshisTropicalIslandEndingScene, x + dx, model->coords.y - 200.0f, z - dz, 1);
    }
    arg0->work[0]++;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/2603D0", func_800F717C_YoshisTropicalIslandEndingScene);
#endif

void func_800F72C4_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    MODEL[1]->unk_18.x = sinf(arg0->rot.y * (M_PI / 180.0));
    MODEL[1]->unk_18.z = cosf(arg0->rot.y * (M_PI / 180.0));
    arg0->rot.y -= 5.0f;
    if (arg0->rot.y <= -360.0f) {
        arg0->rot.y += 360.0f;
    }
}

// GCC shares one base register for MODEL[3]/MODEL[11]; retail reloads each (count 105 vs 117)
#ifdef NON_MATCHING
void func_800F7384_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    f32 angle;
    Object* dst;
    Object* src;

    angle = func_8003D2B0(&MODEL[3]->unk_18) * (M_PI / 180.0);
    dst = MODEL[11];
    src = MODEL[3];
    dst->coords.x = (sinf(angle) * 30.0f) + src->coords.x;
    MODEL[11]->coords.y = MODEL[3]->coords.y;
    dst = MODEL[11];
    src = MODEL[3];
    dst->coords.z = (cosf(angle) * 30.0f) + src->coords.z;
    MODEL[11]->unk_18.x = MODEL[3]->unk_18.x;
    MODEL[11]->unk_18.z = MODEL[3]->unk_18.z;
    dst = MODEL[11];
    dst->unk_30 = (2.0f * sinf(arg0->rot.y * (M_PI / 180.0))) + 2.0f;
    arg0->rot.y += 10.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/2603D0", func_800F7384_YoshisTropicalIslandEndingScene);
#endif

void func_800F74E0_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    Object* model;

    model = MODEL[arg0->work[0]];
    model->unk_30 = (sinf(arg0->rot.y * (M_PI / 180.0)) * 10.0f) + arg0->trans.y;
    arg0->rot.y -= 5.0f;
    if (arg0->rot.y <= -360.0f) {
        arg0->rot.y += 360.0f;
    }
}

void func_800F759C_YoshisTropicalIslandEndingScene(void) {
    s32 ids[5] = { 7, 10, 8, 0x6D, 0x25 };
    s32 i;
    s32 j;

    LoadBackgroundIndex(1);
    for (i = 0; i < 4; i++) {
        if (i != 3) {
            MODEL[i + 8] = MBModelCreate(func_80052F04(GwCommon.boardWork[i]), D_8010DFFC_YoshisTropicalIslandEndingScene[GwPlayer[GwCommon.boardWork[i]].character]);
            func_80021B14(*MODEL[i + 8]->unk_3C->unk_40, GwPlayer[GwCommon.boardWork[i]].character, 0x80);
        } else {
            MODEL[i + 8] = MBModelCreate(ids[i - 3], NULL);
        }
        MODEL[i + 8]->coords.x = D_8010DE4C_YoshisTropicalIslandEndingScene[i][0].x;
        MODEL[i + 8]->coords.y = D_8010DE4C_YoshisTropicalIslandEndingScene[i][0].y;
        MODEL[i + 8]->coords.z = D_8010DE4C_YoshisTropicalIslandEndingScene[i][0].z;
        func_8004CCD0(&MODEL[i + 8]->coords, &MODEL[0]->coords, &MODEL[i + 8]->unk_18);
    }
    MODEL[0]->coords.x = D_8010DE04_YoshisTropicalIslandEndingScene.x;
    MODEL[0]->coords.y = D_8010DE04_YoshisTropicalIslandEndingScene.y;
    MODEL[0]->coords.z = D_8010DE04_YoshisTropicalIslandEndingScene.z;
    func_8004CCD0(&MODEL[0]->coords, &D_800F32A0->coords, &MODEL[0]->unk_18);
    MODEL[1] = MBModelCreate(0x27, NULL);
    MODEL[1]->coords.x = D_8010DE10_YoshisTropicalIslandEndingScene[1].x;
    MODEL[1]->coords.y = D_8010DE10_YoshisTropicalIslandEndingScene[1].y;
    MODEL[1]->coords.z = D_8010DE10_YoshisTropicalIslandEndingScene[1].z;
    MBModelDispOff(MODEL[1]);
    OBJ[1] = omAddObj(0x1000, 0, 0, -1, func_800F72C4_YoshisTropicalIslandEndingScene);
    OBJ[1]->rot.y = 0.0f;
    MODEL[2]->coords.x = D_8010DE10_YoshisTropicalIslandEndingScene[0].x;
    MODEL[2]->coords.y = D_8010DE10_YoshisTropicalIslandEndingScene[0].y;
    MODEL[2]->coords.z = D_8010DE10_YoshisTropicalIslandEndingScene[0].z;
    SetFadeInTypeAndTime(0, 0x10);
    func_8004E3E0(0, &D_8010DE10_YoshisTropicalIslandEndingScene[1], 0x3C, MODEL[2]);
    HuPrcSleep(0x3C);
    func_80072724(0xFF, 0xFF, 0xFF);
    func_800726AC(0, 0);
    HuPrcSleep(5);
    j = 0;
    func_8004FB50(D_8010F850_YoshisTropicalIslandEndingScene);
    MBModelKill(MODEL[2]);
    MODEL[2] = NULL;
    MBModelDispOn(MODEL[1]);
    PlaySound(0x52);
    SetFadeInTypeAndTime(0, 0x10);
    MODEL[15] = MBModelCreate(0x4E, NULL);
    MODEL[15]->coords.x = MODEL[1]->coords.x;
    MODEL[15]->coords.y = MODEL[1]->coords.y;
    MODEL[15]->coords.z = MODEL[1]->coords.z;
    MODEL[15]->unk_3C->unk_24 = -185.0f;
    D_800F2B7C[*MODEL[15]->unk_3C->unk_40].unk_4C = 2.0f;
    for (; j < 1; j++) {
        for (i = 0; i < 70; i += 2) {
            MODEL[15]->xScale = MODEL[15]->yScale = MODEL[15]->zScale = i;
            HuPrcVSleep();
        }
    }
    MBModelKill(MODEL[15]);
    MODEL[15] = NULL;
    func_8004E3E0(0, &D_8010DE10_YoshisTropicalIslandEndingScene[2], 0x14, MODEL[1]);
    HuPrcSleep(0x14);
    MODEL[1]->coords.x = D_8010DE10_YoshisTropicalIslandEndingScene[3].x;
    MODEL[1]->coords.y = D_8010DE10_YoshisTropicalIslandEndingScene[3].y;
    MODEL[1]->coords.z = D_8010DE10_YoshisTropicalIslandEndingScene[3].z;
    MODEL[1]->xScale = MODEL[1]->yScale = MODEL[1]->zScale = 1.0f;
    MODEL[1]->unk_18.x = 0.0f;
    MODEL[1]->unk_18.y = 0.0f;
    MODEL[1]->unk_18.z = 1.0f;
    omDelObj(OBJ[1]);
    OBJ[1] = NULL;
    MBMotionSet(MODEL[8], 4, 0);
    func_8004F40C(MODEL[8], 1, 2);
    func_8004EE14(0, D_800F32A0, 0x14, MODEL[8]);
    func_8004F00C(MODEL[8], 50.0f, -5.0f);
    func_8004F044(MODEL[8]);
    OBJ[1] = omAddObj(0x1000, 0, 0, -1, func_800F72C4_YoshisTropicalIslandEndingScene);
    OBJ[1]->rot.y = 0.0f;
    HuPrcSleep(0x1E);
    func_8004F4D4(MODEL[8], 5, 0);
    func_8004EE14(0, &MODEL[8]->coords, 0x32, MODEL[11]);
    func_8004E3E0(0, &D_8010DE10_YoshisTropicalIslandEndingScene[4], 0x5A, MODEL[1]);
    HuPrcSleep(0x5A);
    HuPrcSleep(0xA);
    MBMotionSet(MODEL[8], 0, 0);
    func_8004F40C(MODEL[8], 1, 2);
    MBMotionSet(MODEL[9], 3, 2);
    MBMotionSet(MODEL[10], 2, 2);
    func_8004CCD0(&MODEL[9]->coords, &MODEL[8]->coords, &MODEL[9]->unk_18);
    func_8004CCD0(&MODEL[10]->coords, &MODEL[8]->coords, &MODEL[10]->unk_18);
    func_8004E3E0(0, &D_8010DE4C_YoshisTropicalIslandEndingScene[1][1], 0x1E, MODEL[9]);
    func_8004E3E0(0, &D_8010DE4C_YoshisTropicalIslandEndingScene[2][1], 0x1E, MODEL[10]);
    HuPrcSleep(0x1E);
    func_8004F4D4(MODEL[9], 1, 2);
    func_8004F4D4(MODEL[10], 1, 2);
    HuPrcSleep(0x1E);
    func_800726AC(1, 0x10);
    HuPrcSleep(0x15);
    func_800F6B54_YoshisTropicalIslandEndingScene();
    func_8004A140();
    func_8004FAB8(D_80110440_YoshisTropicalIslandEndingScene);
    D_80110440_YoshisTropicalIslandEndingScene = func_8004F954(0x26, 0x20);
    func_8004FA90(D_80110440_YoshisTropicalIslandEndingScene, 5.0f, 5.0f, 5.0f);
    HuPrcSleep(5);
    LoadBackgroundIndex(0);
    HuPrcSleep(2);
    func_8004B5DC(D_8010DF0C_YoshisTropicalIslandEndingScene);
    MODEL[0] = MBModelCreate(func_80052F04(GwCommon.boardWork[3]),
                             D_8010DFFC_YoshisTropicalIslandEndingScene[GwPlayer[GwCommon.boardWork[3]].character]);
    MBMotionSet(MODEL[0], 3, 2);
    MODEL[1] = MBModelCreate(0x26, NULL);
    MODEL[0]->coords.x = D_8010DF24_YoshisTropicalIslandEndingScene[0].x;
    MODEL[0]->coords.y = D_8010DF24_YoshisTropicalIslandEndingScene[0].y;
    MODEL[0]->coords.z = D_8010DF24_YoshisTropicalIslandEndingScene[0].z;
    MODEL[1]->coords.x = D_8010DF24_YoshisTropicalIslandEndingScene[0].x + 400.0f;
    MODEL[1]->coords.y = D_8010DF24_YoshisTropicalIslandEndingScene[0].y;
    MODEL[1]->coords.z = D_8010DF24_YoshisTropicalIslandEndingScene[0].z;
    MODEL[0]->unk_18.x = MODEL[1]->unk_18.x = -1.0f;
    MODEL[0]->unk_18.y = MODEL[1]->unk_18.y = 0.0f;
    MODEL[0]->unk_18.z = MODEL[1]->unk_18.z = 0.0f;
    func_8004E3E0(0, &D_8010DF24_YoshisTropicalIslandEndingScene[2], 0x55, MODEL[0]);
    func_8004E3E0(0, &D_8010DF24_YoshisTropicalIslandEndingScene[1], 0x55, MODEL[1]);
    OBJ[1] = omAddObj(0x1000, 0, 0, -1, func_800F717C_YoshisTropicalIslandEndingScene);
    OBJ[1]->work[0] = 0;
    HuPrcVSleep();
    SetFadeInTypeAndTime(1, 0x10);
    for (i = 0; i < 78; i++) {
        D_8010DF0C_YoshisTropicalIslandEndingScene[0].x += D_8010DF0C_YoshisTropicalIslandEndingScene[1].x / 2.0f;
        D_8010DF0C_YoshisTropicalIslandEndingScene[0].y += D_8010DF0C_YoshisTropicalIslandEndingScene[1].y / 2.0f;
        D_8010DF0C_YoshisTropicalIslandEndingScene[0].z += D_8010DF0C_YoshisTropicalIslandEndingScene[1].z / 2.0f;
        func_8004B5DC(D_8010DF0C_YoshisTropicalIslandEndingScene);
        if (i == 62) {
            func_800726AC(1, 0x10);
        }
        HuPrcVSleep();
    }
    omDelObj(OBJ[1]);
    OBJ[1] = NULL;
    HuPrcSleep(0xA);
    func_800F6B54_YoshisTropicalIslandEndingScene();
    func_8004A140();
    HuPrcSleep(5);
    LoadBackgroundIndex(1);
    for (i = 0; i < 8; i++) {
        if (i < 3) {
            s16* p = &GwCommon.boardWork[i];
            MODEL[i] = MBModelCreate(func_80052F04(*p), D_8010E074_YoshisTropicalIslandEndingScene[GwPlayer[*p].character]);
            func_80021B14(*MODEL[i]->unk_3C->unk_40, GwPlayer[*p].character, 0x80);
        } else {
            MODEL[i] = MBModelCreate(ids[i - 3], NULL);
        }
        if (ids[i - 3] != 8)
        {
            func_80025B34(*MODEL[i]->unk_3C->unk_40);
        }
        if (i == 0 || i == 7) {
            MODEL[i]->coords.x = D_8010DE4C_YoshisTropicalIslandEndingScene[i][0].x;
            MODEL[i]->coords.y = D_8010DE4C_YoshisTropicalIslandEndingScene[i][0].y;
            MODEL[i]->coords.z = D_8010DE4C_YoshisTropicalIslandEndingScene[i][0].z;
            if (i == 7) {
                MODEL[i]->unk_3C->unk_24 = 90.0f;
                MODEL[i]->coords.x = D_8010DF48_YoshisTropicalIslandEndingScene.x;
                MODEL[i]->coords.y = D_8010DF48_YoshisTropicalIslandEndingScene.y;
                MODEL[i]->coords.z = D_8010DF48_YoshisTropicalIslandEndingScene.z;
            }
        } else {
            /* the same table read flat: entry [i][1] */
            MODEL[i]->coords.x = D_8010DE4C_YoshisTropicalIslandEndingScene[0][i * 2 + 1].x;
            MODEL[i]->coords.y = D_8010DE4C_YoshisTropicalIslandEndingScene[0][i * 2 + 1].y;
            MODEL[i]->coords.z = D_8010DE4C_YoshisTropicalIslandEndingScene[0][i * 2 + 1].z;
            if (i == 6) {
                MODEL[i]->unk_30 = 30.0f;
                OBJ[i] = omAddObj(0x1000, 0, 0, -1, func_800F74E0_YoshisTropicalIslandEndingScene);
                OBJ[i]->work[0] = i;
                OBJ[i]->trans.y = MODEL[i]->unk_30;
                OBJ[i]->rot.y = 0.0f;
            }
        }
        func_8004CCD0(&MODEL[i]->coords, &D_800F32A0->coords, &MODEL[i]->unk_18);
    }
    func_8004F140(*MODEL[5]->unk_3C->unk_40);
    MODEL[11] = MBModelCreate(0x27, NULL);
    OBJ[11] = omAddObj(0x2000, 0, 0, -1, func_800F7384_YoshisTropicalIslandEndingScene);
    OBJ[11]->rot.y = 0.0f;
    MODEL[10] = MBModelCreate(0x3F, NULL);
    MODEL[10]->coords.x = D_8010DE04_YoshisTropicalIslandEndingScene.x;
    MODEL[10]->coords.y = D_8010DE04_YoshisTropicalIslandEndingScene.y;
    MODEL[10]->coords.z = D_8010DE04_YoshisTropicalIslandEndingScene.z;
    func_8004CCD0(&MODEL[10]->coords, &D_800F32A0->coords, &MODEL[10]->unk_18);
    func_80025EB4(*MODEL[10]->unk_3C->unk_40, 2, 0);
    func_80025CA8(*MODEL[10]->unk_3C->unk_40, func_80025D40(*MODEL[10]->unk_3C->unk_40));
    SetFadeInTypeAndTime(1, 0x10);
    HuPrcSleep(0x1E);
    for (i = 0; i < 8; i++) {
        if (i == 7 || i == 0) {
            continue;
        }
        func_8004EE14(0, &MODEL[7]->coords, 0x14, MODEL[i]);
    }
    HuPrcSleep(0x14);
    func_8004E3E0(0, &D_8010DE4C_YoshisTropicalIslandEndingScene[7][0], 0x3C, MODEL[7]);
    for (j = 0; j < 60; j++) {
        for (i = 0; i < 8; i++) {
            if (i == 7 || i == 0) {
                continue;
            }
            func_8004CCD0(&MODEL[i]->coords, &MODEL[7]->coords, &MODEL[i]->unk_18);
        }
        HuPrcVSleep();
    }
    func_8004F4D4(MODEL[0], 1, 2);
    func_8004E3E0(0, &D_8010DE4C_YoshisTropicalIslandEndingScene[0][1], 0x14, MODEL[0]);
    HuPrcSleep(0x14);
    func_8004F4D4(MODEL[0], 0, 2);
    for (i = 0; i < 8; i++) {
        if (i == 7 || i == 0) {
            continue;
        }
        func_8004EE14(0, &D_8010DE4C_YoshisTropicalIslandEndingScene[0][1], 0x14, MODEL[i]);
    }
    func_8004EE14(0, &MODEL[0]->coords, 1, MODEL[7]);
    HuPrcSleep(1);
    func_8004E3E0(0, &D_8010DE4C_YoshisTropicalIslandEndingScene[7][1], 0x14, MODEL[7]);
    MBModelDispOff(MODEL[7]);
    HuPrcSleep(3);
    MBModelDispOn(MODEL[7]);
    HuPrcSleep(0x11);
    func_8004EE14(0, D_800F32A0, 0x14, MODEL[7]);
    HuPrcSleep(0x14);
    OBJ[7] = omAddObj(0x1000, 0, 0, -1, func_800F74E0_YoshisTropicalIslandEndingScene);
    OBJ[7]->work[0] = 7;
    OBJ[7]->trans.y = 0.0f;
    OBJ[7]->rot.y = 0.0f;
    func_8004F4D4(MODEL[0], 2, 0);
}

void func_800F8550_YoshisTropicalIslandEndingScene(void) {
    func_800F6D40_YoshisTropicalIslandEndingScene();
    func_800F759C_YoshisTropicalIslandEndingScene();
}

void func_800F8574_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    arg0->rot.x += 5.0f;
    if (arg0->rot.x >= 360.0f) {
        arg0->rot.x -= 360.0f;
    }
    MODEL[0]->unk_18.x = sinf(arg0->rot.x * (M_PI / 180.0)) * 0.2f;
    MODEL[0]->unk_18.z = 1.0f;
}

void func_800F8620_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    s32 count;
    s32 i;
    f32 angle;

    count = D_8010DC90_YoshisTropicalIslandEndingScene[2];
    for (i = 0; i < arg0->trans.y; i++) {
        angle = (360 / count) * i;
        func_800A0D00(&MODEL[i]->coords,
                      (sinf((angle + arg0->rot.y) * (M_PI / 180.0)) * arg0->trans.x) + ENDING_CENTER[ENDING_BOARD].x,
                      ENDING_CENTER[ENDING_BOARD].y,
                      (cosf((angle + arg0->rot.y) * (M_PI / 180.0)) * arg0->trans.x) + ENDING_CENTER[ENDING_BOARD].z);
        func_800A0D00((Vec3f*)&MODEL[i]->xScale, arg0->scale.x, arg0->scale.x, arg0->scale.x);
    }
    arg0->rot.y -= 2.0f;
    if (arg0->rot.y <= 0.0f) {
        arg0->rot.y += 360.0f;
    }
    arg0->work[0]++;
}

void func_800F8848_YoshisTropicalIslandEndingScene(void) {
    s32 count;
    s32 i;
    f32 dist;
    f32 angle;
    omObjData* ring;

    count = D_8010DC90_YoshisTropicalIslandEndingScene[2];
    dist = D_8010DCFC_YoshisTropicalIslandEndingScene[ENDING_BOARD];
    for (i = 0; i < count; i++) {
        MODEL[i] = MBModelCreate(0x25, NULL);
        angle = ((360 / count) * i) * (M_PI / 180.0);
        func_800A0D00(&MODEL[i]->coords,
                      (sinf(angle) * dist) + ENDING_CENTER[ENDING_BOARD].x,
                      ENDING_CENTER[ENDING_BOARD].y,
                      (cosf(angle) * dist) + ENDING_CENTER[ENDING_BOARD].z);
        /* retail writes the scale into coords here (and the ring object moves them anyway) */
        func_800A0D00(&MODEL[i]->coords,
                      D_8010DD1C_YoshisTropicalIslandEndingScene[ENDING_BOARD],
                      D_8010DD1C_YoshisTropicalIslandEndingScene[ENDING_BOARD],
                      D_8010DD1C_YoshisTropicalIslandEndingScene[ENDING_BOARD]);
        D_80110400_YoshisTropicalIslandEndingScene[i] = func_80042728(MODEL[i], 1);
    }
    ring = omAddObj(0x1000, 0, 0, -1, func_800F8620_YoshisTropicalIslandEndingScene);
    ring->rot.y = 0.0f;
    ring->trans.x = dist;
    ring->trans.y = count;
    ring->scale.x = D_8010DD1C_YoshisTropicalIslandEndingScene[ENDING_BOARD];
    ring->work[0] = 0;
    LoadBackgroundIndex(D_8010DD3C_YoshisTropicalIslandEndingScene[ENDING_BOARD]);
    func_80072724(0xFF, 0xFF, 0xFF);
    SetFadeInTypeAndTime(2, 0x18);
    PlaySound(0x48);
    HuPrcSleep(0x36);
    for (; dist >= 350.0f; dist -= 10.0f) {
        ring->trans.x = dist;
        if (dist - 10.0f < 350.0f) {
            func_80072724(0xFF, 0xFF, 0xFF);
            func_800726AC(0, 0);
            PlaySound(0x4B);
        }
        HuPrcVSleep();
    }
    HuPrcSleep(5);
    for (i = 0; i < count; i++) {
        MBModelKill(MODEL[i]);
        MODEL[i] = NULL;
        func_800427D4(D_80110400_YoshisTropicalIslandEndingScene[i]);
        D_80110400_YoshisTropicalIslandEndingScene[i] = NULL;
    }
    MODEL[0] = MBModelCreate(0x25, NULL);
    D_80110400_YoshisTropicalIslandEndingScene[0] = func_80042728(MODEL[0], 1);
    func_800258EC(*MODEL[0]->unk_3C->unk_40, 0x10000, 0x10000);
    i = 0xF8;
    func_80025AD4(*MODEL[0]->unk_3C->unk_40);
    func_80028C64(*MODEL[0]->unk_3C->unk_40, 0xFF, 0xFF, 0xFF, 0xFF);
    MODEL[0]->xScale = 2.0f * D_8010DD1C_YoshisTropicalIslandEndingScene[ENDING_BOARD];
    MODEL[0]->yScale = 2.0f * D_8010DD1C_YoshisTropicalIslandEndingScene[ENDING_BOARD];
    MODEL[0]->zScale = 2.0f * D_8010DD1C_YoshisTropicalIslandEndingScene[ENDING_BOARD];
    MODEL[0]->coords.x = ENDING_CENTER[ENDING_BOARD].x;
    MODEL[0]->coords.y = ENDING_CENTER[ENDING_BOARD].y;
    MODEL[0]->coords.z = ENDING_CENTER[ENDING_BOARD].z;
    omDelObj(ring);
    ring = omAddObj(0x1000, 0, 0, -1, func_800F8574_YoshisTropicalIslandEndingScene);
    ring->rot.x = 0.0f;
    HuPrcSleep(5);
    SetFadeInTypeAndTime(0, 0x10);
    HuPrcSleep(0x10);
    do {
        func_80028C64(*MODEL[0]->unk_3C->unk_40, i, i, i, 0xFF);
        i -= 4;
        HuPrcVSleep();
    } while (i >= 0);
    func_8004B7F8(0x40);
    func_8002578C(0);
    PlaySound(0x54);
    i = 0;
    dist = 0.0f;
    while (1) {
        MODEL[0]->coords.x += dist;
        MODEL[0]->coords.y += D_8010DDEC_YoshisTropicalIslandEndingScene.y;
        MODEL[0]->coords.z += D_8010DDEC_YoshisTropicalIslandEndingScene.z;
        MODEL[0]->xScale -= 0.1f;
        MODEL[0]->yScale -= 0.1f;
        MODEL[0]->zScale -= 0.1f;
        dist += D_8010DDEC_YoshisTropicalIslandEndingScene.x;
        if (i == 0) {
            if (MODEL[0]->coords.x <= D_8010DDE0_YoshisTropicalIslandEndingScene.x ||
                MODEL[0]->coords.z <= D_8010DDE0_YoshisTropicalIslandEndingScene.z) {
                func_800726AC(0, 8);
                i = 1;
            }
        }
        if (i != 0) {
            if (++i >= 18) {
                break;
            }
        }
        HuPrcVSleep();
    }
    func_8004B7F8(0xFF);
    func_8002578C(1);
    omDelObj(ring);
    MBModelKill(MODEL[0]);
    MODEL[0] = NULL;
    func_800427D4(D_80110400_YoshisTropicalIslandEndingScene[0]);
    D_80110400_YoshisTropicalIslandEndingScene[0] = NULL;
    func_8004A140();
    HuPrcSleep(0xA);
}
