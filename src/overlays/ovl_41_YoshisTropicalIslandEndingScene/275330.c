#include "ending.h"

/* engine functions without an include/ prototype (types from their C definitions) */
void func_80052DC8(s16, void*);
void func_80052F34(s16);
void func_8004B7F8(s32);
void func_80028C64(s16, u8, u8, u8, u8);
s32 func_8004F628(s32, u16, s16, s16);
void func_8004F584(s32);
void func_8004F7C0(s32, f32, f32);
void func_8004F898(s32, u8, u8, u8);
void func_8004F754(s32, s32, s32); /* defined (s32, s16, s16); retail passes the ints unextended */

void func_8010BCA0_YoshisTropicalIslandEndingScene(omObjData*);
void func_8010BD1C_YoshisTropicalIslandEndingScene(void);
void func_8010C1BC_YoshisTropicalIslandEndingScene(omObjData*);
void func_8010C2EC_YoshisTropicalIslandEndingScene(void);
void func_8010C350_YoshisTropicalIslandEndingScene(omObjData*);
void func_8010C40C_YoshisTropicalIslandEndingScene(omObjData*);
void func_8010C4C0_YoshisTropicalIslandEndingScene(void);
void func_8010CCB8_YoshisTropicalIslandEndingScene(omObjData*);
void func_8010CD88_YoshisTropicalIslandEndingScene(omObjData*);
void func_8010CE34_YoshisTropicalIslandEndingScene(omObjData*);

/* func_80042728's result (42E40.c ModelEmitterWork; only its leading fields) */
typedef struct EndingEmitterWork {
    /* 0x00 */ Process* process;
    /* 0x04 */ Object* model;
} EndingEmitterWork;

/* bss used only by this unit */
typedef struct EndingTexSize {
    /* 0x00 */ s16 w;
    /* 0x02 */ s16 h;
} EndingTexSize; /* func_80039C48 writes w and h */
extern EndingTexSize D_80110280_YoshisTropicalIslandEndingScene;
extern s32 D_80110284_YoshisTropicalIslandEndingScene; /* cleared with it; scalars in retail's codegen */
extern s32 D_80110288_YoshisTropicalIslandEndingScene;
extern Vec3f D_8011028C_YoshisTropicalIslandEndingScene; /* camera eye */
extern Vec3f D_80110298_YoshisTropicalIslandEndingScene; /* camera at */
extern Vec3f D_801102A4_YoshisTropicalIslandEndingScene; /* camera up */

/* the background layer id: D_801102B8[15] holds a u16 file id as a word, read as its s16 */
#define ENDING_BG_LAYER ((s16)D_801102B8_YoshisTropicalIslandEndingScene[15])

/* .data */
s32 D_8010ED00_YoshisTropicalIslandEndingScene[4] = { 3, 0x00010001, 0x00010097, 0x0001003B };
s32 D_8010ED10_YoshisTropicalIslandEndingScene[4] = { 3, 0x00020001, 0x00020097, 0x0002003B };
s32 D_8010ED20_YoshisTropicalIslandEndingScene[4] = { 3, 0x00060001, 0x00060097, 0x0006003B };
s32 D_8010ED30_YoshisTropicalIslandEndingScene[4] = { 3, 0x00030001, 0x00030097, 0x0003003B };
s32 D_8010ED40_YoshisTropicalIslandEndingScene[4] = { 3, 0x00040001, 0x00040097, 0x0004003B };
s32 D_8010ED50_YoshisTropicalIslandEndingScene[4] = { 3, 0x00050001, 0x00050097, 0x0005003B };
/* per-character player model lists (func_80052DC8) */
s32* D_8010ED60_YoshisTropicalIslandEndingScene[6] = {
    D_8010ED00_YoshisTropicalIslandEndingScene, D_8010ED10_YoshisTropicalIslandEndingScene,
    D_8010ED20_YoshisTropicalIslandEndingScene, D_8010ED30_YoshisTropicalIslandEndingScene,
    D_8010ED40_YoshisTropicalIslandEndingScene, D_8010ED50_YoshisTropicalIslandEndingScene,
};
s32 D_8010ED78_YoshisTropicalIslandEndingScene[2] = { 1, 0x000A006C };
s32 D_8010ED80_YoshisTropicalIslandEndingScene[3] = { 2, 0x000A00E8, 0x000A00E9 };
Vec3f D_8010ED8C_YoshisTropicalIslandEndingScene[2] = { { 0.0f, 250.0f, 640.0f }, { 0.0f, 450.0f, 550.0f } };
f32 D_8010EDA4_YoshisTropicalIslandEndingScene[5] = { 8.0f, 0.75f, 0.75f, 0.75f, 0.75f };
s16 D_8010EDB8_YoshisTropicalIslandEndingScene[6] = { 0x68, 7, 8, 0x6D, 0x40, 0 }; /* model ids */
Vec3f D_8010EDC4_YoshisTropicalIslandEndingScene[7] = {
    { 0.0f, 0.0f, 0.0f },
    { 560.0f, 2800.0f, 2600.0f },
    { 0.0f, -3000.0f, -4000.0f },
    { -1000.0f, 0.0f, 1000.0f },
    { 0.0f, 0.0f, 0.0f },
    { 300.0f, 2800.0f, 2600.0f },
    { 1000.0f, 2800.0f, 2700.0f },
};
Process* D_8010EE18_YoshisTropicalIslandEndingScene = NULL;
Vec3f D_8010EE1C_YoshisTropicalIslandEndingScene = { -340.0f, 0.0f, -435.0f };
s32 D_8010EE28_YoshisTropicalIslandEndingScene[6] = { 0x000A00ED, 0x000A00EE, 0x000A00EF, 0x000A00F0, 0x000A00F1, 0x000A00F2 };
Vec2f D_8010EE40_YoshisTropicalIslandEndingScene[6] = {
    { 87.0f, 70.0f }, { 167.0f, 59.0f }, { 235.0f, 81.0f }, { 77.0f, 165.0f }, { 163.0f, 160.0f }, { 228.0f, 162.0f },
};

/* .rodata */
const Vec3f D_8010F770_YoshisTropicalIslandEndingScene[4] = {
    { 0.0f, 250.0f, 525.0f }, { -75.0f, 250.0f, 525.0f }, { 75.0f, 250.0f, 500.0f }, { -175.0f, 250.0f, 475.0f },
};
const Vec3f D_8010F7A0_YoshisTropicalIslandEndingScene[5] = {
    { 0.0f, 0.0f, 4500.0f },
    { 150.0f, 250.0f, 575.0f },
    { -125.0f, 250.0f, 300.0f },
    { 187.5f, 250.0f, 200.0f },
    { 1000.0f, 750.0f, 550.0f },
};

const f64 D_8010F7E0_YoshisTropicalIslandEndingScene __attribute__((section(".rodata"))) = 0.0174532925199432955;
void func_8010BCA0_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    unk_Struct04* node = D_80110448_YoshisTropicalIslandEndingScene[0]->unk_3C;

    node->unk_2C = sinf(arg0->rot.x * D_8010F7E0_YoshisTropicalIslandEndingScene) * 15.0f;
    arg0->rot.x += 5.0f;
}

const f64 D_8010F7E8_YoshisTropicalIslandEndingScene __attribute__((section(".rodata"))) = 1.0;
const f64 D_8010F7F0_YoshisTropicalIslandEndingScene __attribute__((section(".rodata"))) = 0.5;
const f64 D_8010F7F8_YoshisTropicalIslandEndingScene __attribute__((section(".rodata"))) = 0.5;
void func_8010BD1C_YoshisTropicalIslandEndingScene(void) {
    s32 i;
    s32 sprite;
    f32 scale;

    for (i = 0; i < 4; i++) {
        func_80052DC8(GwCommon.boardWork[i], D_8010ED60_YoshisTropicalIslandEndingScene[GwPlayer[GwCommon.boardWork[i]].character]);
        func_80052F34(GwCommon.boardWork[i]);
        func_80021B14(*GwPlayer[GwCommon.boardWork[i]].player_obj->unk_3C->unk_40, GwPlayer[GwCommon.boardWork[i]].character, 0x80);
        GwPlayer[GwCommon.boardWork[i]].flags |= 4;
        func_800A0D00(&GwPlayer[GwCommon.boardWork[i]].player_obj->coords, D_8010F770_YoshisTropicalIslandEndingScene[i].x + D_8010F7A0_YoshisTropicalIslandEndingScene[0].x,
                      D_8010F770_YoshisTropicalIslandEndingScene[i].y + D_8010F7A0_YoshisTropicalIslandEndingScene[0].y, D_8010F770_YoshisTropicalIslandEndingScene[i].z + D_8010F7A0_YoshisTropicalIslandEndingScene[0].z);
        func_800A0D00((Vec3f*)&GwPlayer[GwCommon.boardWork[i]].player_obj->xScale, 0.75f, 0.75f, 0.75f);
        MBModelDispOff(GwPlayer[GwCommon.boardWork[i]].player_obj);
    }
    D_80110448_YoshisTropicalIslandEndingScene[0] = MBModelCreate(0x68, NULL);
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[0]->coords, D_8010EDC4_YoshisTropicalIslandEndingScene[0].x, D_8010EDC4_YoshisTropicalIslandEndingScene[0].y, D_8010EDC4_YoshisTropicalIslandEndingScene[0].z);
    func_800A0D00((Vec3f*)&D_80110448_YoshisTropicalIslandEndingScene[0]->xScale, 14.0f, 14.0f, 14.0f);
    D_80110300_YoshisTropicalIslandEndingScene[0] = omAddObj(0x1000, 0, 0, -1, &func_8010BCA0_YoshisTropicalIslandEndingScene);
    D_80110300_YoshisTropicalIslandEndingScene[0]->rot.x = 0.0f;
    SetFadeInTypeAndTime(0, 0x30);
    HuPrcSleep(0x30);
    HuPrcSleep(0x14);
    func_8004EA8C(D_80110448_YoshisTropicalIslandEndingScene[0], &D_8010EDC4_YoshisTropicalIslandEndingScene[1], 0x5A, &D_8010EDC4_YoshisTropicalIslandEndingScene[3]);
    func_8004EE14(0, &D_8010EDC4_YoshisTropicalIslandEndingScene[1], 0x5A, D_80110448_YoshisTropicalIslandEndingScene[0]);
    HuPrcSleep(0x78);
    func_8004B7F8(0x40);
    func_8002578C(0);
    func_8004EA8C(D_80110448_YoshisTropicalIslandEndingScene[0], &D_8010EDC4_YoshisTropicalIslandEndingScene[2], 0xA, &D_8010EDC4_YoshisTropicalIslandEndingScene[4]);
    for (i = 0; i < 10; i++) {
        D_80110448_YoshisTropicalIslandEndingScene[0]->xScale = D_80110448_YoshisTropicalIslandEndingScene[0]->xScale - D_8010F7E8_YoshisTropicalIslandEndingScene;
        D_80110448_YoshisTropicalIslandEndingScene[0]->yScale = D_80110448_YoshisTropicalIslandEndingScene[0]->yScale - D_8010F7E8_YoshisTropicalIslandEndingScene;
        D_80110448_YoshisTropicalIslandEndingScene[0]->zScale = D_80110448_YoshisTropicalIslandEndingScene[0]->zScale - D_8010F7E8_YoshisTropicalIslandEndingScene;
        HuPrcVSleep();
    }
    omDelObj(D_80110300_YoshisTropicalIslandEndingScene[0]);
    MBModelKill(D_80110448_YoshisTropicalIslandEndingScene[0]);
    D_80110300_YoshisTropicalIslandEndingScene[0] = NULL;
    D_80110448_YoshisTropicalIslandEndingScene[0] = NULL;
    func_8004B7F8(0xFF);
    func_8002578C(1);
    sprite = func_8004F628(0xA0161, 0xA, 0xA0, 0x32);
    func_8004F898(sprite, 0xFF, 0xFF, 0xFF);
    scale = 0.0f;
    do {
        func_8004F7C0(sprite, scale, scale);
        HuPrcVSleep();
        scale = scale + D_8010F7F0_YoshisTropicalIslandEndingScene;
    } while (scale < 2.0f);
    while (scale >= 0.0f) {
        func_8004F7C0(sprite, scale, scale);
        HuPrcVSleep();
        scale = scale - D_8010F7F8_YoshisTropicalIslandEndingScene;
    }
    func_8004F7C0(sprite, 0.0f, 0.0f);
    func_800726AC(0, 0x14);
    HuPrcSleep(0x14);
    func_8004F584(sprite);
    func_8004A140();
}

void func_8010C1BC_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    struct {
        s16 w;
        s16 h;
    } size;
    f32 angle;

    arg0->scale.y += 6.0f;
    angle = arg0->rot.x;
    if (angle >= 360.0f) {
        angle -= 360.0f;
    }
    size.w = arg0->trans.x;
    size.h = arg0->trans.y;
    func_80027C1C(ENDING_BG_LAYER, arg0->scale.x, arg0->scale.y, (u16)size.w, (u16)size.h);
    func_800257E4(ENDING_BG_LAYER, 0.0f, 0.0f, angle);
    if (size.h < arg0->scale.y) {
        arg0->scale.y -= size.h;
    }
    arg0->rot.x = angle + 0.1f;
    if (arg0->rot.x >= 360.0f) {
        arg0->rot.x -= 360.0f;
    }
}

void func_8010C2EC_YoshisTropicalIslandEndingScene(void) {
    while (1) {
        func_8001D494(0, 20.0f, 80.0f, 12000.0f);
        func_8001D420(0, &D_8011028C_YoshisTropicalIslandEndingScene, &D_80110298_YoshisTropicalIslandEndingScene, &D_801102A4_YoshisTropicalIslandEndingScene);
        func_8001D57C(0);
        HuPrcVSleep();
    }
}

const f64 D_8010F800_YoshisTropicalIslandEndingScene __attribute__((section(".rodata"))) = 0.0174532925199432955;
void func_8010C350_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    Object* model = D_80110448_YoshisTropicalIslandEndingScene[arg0->work[0]];

    model->unk_30 = sinf(arg0->rot.y * D_8010F800_YoshisTropicalIslandEndingScene) * 10.0f + arg0->trans.y;
    arg0->rot.y -= 5.0f;
    if (arg0->rot.y <= -360.0f) {
        arg0->rot.y += 360.0f;
    }
}

const f64 D_8010F808_YoshisTropicalIslandEndingScene __attribute__((section(".rodata"))) = 0.0174532925199432955;
void func_8010C40C_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    unk_Struct04* node;

    arg0->rot.x += 5.0f;
    if (arg0->rot.x >= 360.0f) {
        arg0->rot.x -= 360.0f;
    }
    D_80110448_YoshisTropicalIslandEndingScene[4]->unk_3C->unk_24 = 0.0f;
    D_80110448_YoshisTropicalIslandEndingScene[4]->unk_3C->unk28 = 0.0f;
    node = D_80110448_YoshisTropicalIslandEndingScene[4]->unk_3C;
    node->unk_2C = sinf(arg0->rot.x * D_8010F808_YoshisTropicalIslandEndingScene) * 10.0f;
}

void func_8010C4C0_YoshisTropicalIslandEndingScene(void) {
    Vec3f pos;
    s32 i;
    s32 j;

    func_80017660(0, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    D_8011028C_YoshisTropicalIslandEndingScene.x = 0.0f;
    D_8011028C_YoshisTropicalIslandEndingScene.y = 1000.0f;
    D_8011028C_YoshisTropicalIslandEndingScene.z = 5000.0f;
    D_80110298_YoshisTropicalIslandEndingScene.x = 0.0f;
    D_80110298_YoshisTropicalIslandEndingScene.y = 0.0f;
    D_80110298_YoshisTropicalIslandEndingScene.z = 3000.0f;
    D_801102A4_YoshisTropicalIslandEndingScene.x = 0.0f;
    D_801102A4_YoshisTropicalIslandEndingScene.y = 1.0f;
    D_801102A4_YoshisTropicalIslandEndingScene.z = 0.0f;
    D_8010EE18_YoshisTropicalIslandEndingScene = omAddPrcObj(func_8010C2EC_YoshisTropicalIslandEndingScene, 0x1001, 0, 0);
    omPrcSetStatBit(D_8010EE18_YoshisTropicalIslandEndingScene, 0x80);
    func_8001D494(0, 20.0f, 80.0f, 4000.0f);
    func_8001D420(0, &D_8011028C_YoshisTropicalIslandEndingScene, &D_80110298_YoshisTropicalIslandEndingScene, &D_801102A4_YoshisTropicalIslandEndingScene);
    func_8001D57C(0);
    D_801102B8_YoshisTropicalIslandEndingScene[15] = LoadFormFile(0xA0160, 0x2A9);
    func_80025798(ENDING_BG_LAYER, 0.0f, 0.0f, -2000.0f);
    func_80025830(ENDING_BG_LAYER, 1.0f, 1.0f, 3.0f);
    func_80025F10(ENDING_BG_LAYER, 1);
    D_80110284_YoshisTropicalIslandEndingScene = 0;
    D_80110288_YoshisTropicalIslandEndingScene = 0;
    func_80039C48("nagare_IA44", &D_80110280_YoshisTropicalIslandEndingScene);
    func_80026040(ENDING_BG_LAYER);
    D_80110300_YoshisTropicalIslandEndingScene[15] = omAddObj(0x1000, 0, 0, -1, &func_8010C1BC_YoshisTropicalIslandEndingScene);
    omSetRot(D_80110300_YoshisTropicalIslandEndingScene[15], 0.0f, 0.0f, 0.0f);
    omSetSca(D_80110300_YoshisTropicalIslandEndingScene[15], 0.0f, 0.0f, 0.0f);
    omSetTra(D_80110300_YoshisTropicalIslandEndingScene[15], D_80110280_YoshisTropicalIslandEndingScene.w, D_80110280_YoshisTropicalIslandEndingScene.h, 0.0f);
    for (i = 0; i < 5; i++) {
        D_80110448_YoshisTropicalIslandEndingScene[i] = MBModelCreate(D_8010EDB8_YoshisTropicalIslandEndingScene[i], NULL);
        if (i == 0) {
            func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[i]->coords, D_8010F7A0_YoshisTropicalIslandEndingScene[i].x, D_8010F7A0_YoshisTropicalIslandEndingScene[i].y, D_8010F7A0_YoshisTropicalIslandEndingScene[i].z);
            func_80025F60(*D_80110448_YoshisTropicalIslandEndingScene[i]->unk_3C->unk_40, 0);
        } else {
            func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[i]->coords, D_8010F7A0_YoshisTropicalIslandEndingScene[i].x + D_8010F7A0_YoshisTropicalIslandEndingScene[0].x,
                          D_8010F7A0_YoshisTropicalIslandEndingScene[i].y + D_8010F7A0_YoshisTropicalIslandEndingScene[0].y, D_8010F7A0_YoshisTropicalIslandEndingScene[i].z + D_8010F7A0_YoshisTropicalIslandEndingScene[0].z);
        }
        func_800A0D00((Vec3f*)&D_80110448_YoshisTropicalIslandEndingScene[i]->xScale, D_8010EDA4_YoshisTropicalIslandEndingScene[i], D_8010EDA4_YoshisTropicalIslandEndingScene[i], D_8010EDA4_YoshisTropicalIslandEndingScene[i]);
    }
    func_8004F140(*D_80110448_YoshisTropicalIslandEndingScene[2]->unk_3C->unk_40);
    D_80110300_YoshisTropicalIslandEndingScene[0] = omAddObj(0x1000, 0, 0, -1, &func_8010C350_YoshisTropicalIslandEndingScene);
    D_80110300_YoshisTropicalIslandEndingScene[0]->work[0] = 3;
    D_80110300_YoshisTropicalIslandEndingScene[0]->trans.y = 50.0f;
    D_80110300_YoshisTropicalIslandEndingScene[0]->rot.y = 0.0f;
    D_80110300_YoshisTropicalIslandEndingScene[1] = omAddObj(0x1000, 0, 0, -1, &func_8010C40C_YoshisTropicalIslandEndingScene);
    D_80110300_YoshisTropicalIslandEndingScene[1]->rot.x = 0.0f;
    for (i = 0; i < 4; i++) {
        MBModelDispOn(GwPlayer[i].player_obj);
    }
    SetFadeInTypeAndTime(0, 0x10);
    HuPrcSleep(0x10);
    for (j = 0; j < 100; j++) {
        for (i = 0; i < 4; i++) {
            GwPlayer[GwCommon.boardWork[i]].player_obj->coords.z -= 15.0f;
        }
        for (i = 0; i < 5; i++) {
            D_80110448_YoshisTropicalIslandEndingScene[i]->coords.z -= 15.0f;
        }
        HuPrcVSleep();
    }
    HuPrcSleep(0x14);
    func_8004F4D4(GwPlayer[GwCommon.boardWork[1]].player_obj, 2, 0);
    func_8004F4D4(GwPlayer[GwCommon.boardWork[2]].player_obj, 2, 0);
    func_8004F4D4(GwPlayer[GwCommon.boardWork[3]].player_obj, 2, 0);
    func_8004F40C(GwPlayer[GwCommon.boardWork[1]].player_obj, -1, 2);
    func_8004F40C(GwPlayer[GwCommon.boardWork[2]].player_obj, -1, 2);
    func_8004F40C(GwPlayer[GwCommon.boardWork[3]].player_obj, -1, 2);
    HuPrcSleep(0x1E);
    pos.x = D_8010ED8C_YoshisTropicalIslandEndingScene[0].x + D_8010F7A0_YoshisTropicalIslandEndingScene[0].x;
    pos.y = D_8010ED8C_YoshisTropicalIslandEndingScene[0].y + D_8010F7A0_YoshisTropicalIslandEndingScene[0].y;
    pos.z = (D_8010ED8C_YoshisTropicalIslandEndingScene[0].z + D_8010F7A0_YoshisTropicalIslandEndingScene[0].z) - 1500.0f;
    func_8004E3E0(GwCommon.boardWork[0], &pos, 0x1E, NULL);
    func_8004F4D4(GwPlayer[GwCommon.boardWork[0]].player_obj, 0, 2);
    HuPrcSleep(0x14);
    D_80110400_YoshisTropicalIslandEndingScene[4] = func_80042728(D_80110448_YoshisTropicalIslandEndingScene[4], 1);
    pos.x = D_8010ED8C_YoshisTropicalIslandEndingScene[1].x + D_8010F7A0_YoshisTropicalIslandEndingScene[0].x;
    pos.y = D_8010ED8C_YoshisTropicalIslandEndingScene[1].y + D_8010F7A0_YoshisTropicalIslandEndingScene[0].y;
    pos.z = (D_8010ED8C_YoshisTropicalIslandEndingScene[1].z + D_8010F7A0_YoshisTropicalIslandEndingScene[0].z) - 1500.0f;
    func_8004E3E0(0, &pos, 0x32, D_80110448_YoshisTropicalIslandEndingScene[4]);
    HuPrcSleep(0xA);
    func_8004F4D4(GwPlayer[GwCommon.boardWork[0]].player_obj, -1, 2);
    HuPrcSleep(0x32);
    func_8004F4D4(GwPlayer[GwCommon.boardWork[0]].player_obj, 1, 0);
    EndProcess(D_8010EE18_YoshisTropicalIslandEndingScene);
    D_8010EE18_YoshisTropicalIslandEndingScene = NULL;
}

void func_8010CC94_YoshisTropicalIslandEndingScene(void) {
    func_8010BD1C_YoshisTropicalIslandEndingScene();
    func_8010C4C0_YoshisTropicalIslandEndingScene();
}

const f64 D_8010F820_YoshisTropicalIslandEndingScene __attribute__((section(".rodata"))) = 0.0174532925199432955;
void func_8010CCB8_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    Object* model;

    D_80110448_YoshisTropicalIslandEndingScene[arg0->work[0]]->unk_3C->unk_24 = -90.0f;
    model = D_80110448_YoshisTropicalIslandEndingScene[arg0->work[0]];
    model->unk_18.x = sinf(arg0->rot.x * D_8010F820_YoshisTropicalIslandEndingScene);
    model = D_80110448_YoshisTropicalIslandEndingScene[arg0->work[0]];
    model->unk_18.z = cosf(arg0->rot.x * D_8010F820_YoshisTropicalIslandEndingScene);
    arg0->rot.x += 7.0f;
}

const f64 D_8010F828_YoshisTropicalIslandEndingScene __attribute__((section(".rodata"))) = 0.0174532925199432955;
void func_8010CD88_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    Object* model;

    arg0->rot.x += 5.0f;
    if (arg0->rot.x >= 360.0f) {
        arg0->rot.x -= 360.0f;
    }
    model = D_80110448_YoshisTropicalIslandEndingScene[0];
    model->unk_18.x = sinf(arg0->rot.x * D_8010F828_YoshisTropicalIslandEndingScene) * 0.2f;
    D_80110448_YoshisTropicalIslandEndingScene[0]->unk_18.z = 1.0f;
}

const f64 D_8010F830_YoshisTropicalIslandEndingScene __attribute__((section(".rodata"))) = 0.0174532925199432955;
void func_8010CE34_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    s32 count = D_8010DC90_YoshisTropicalIslandEndingScene[GwSystem.unk_00];
    s32 i;
    f32 angle;
    f32 x;

    for (i = 0; i < arg0->trans.y; i++) {
        angle = (360 / count) * i;
        x = sinf((angle + arg0->rot.y) * D_8010F830_YoshisTropicalIslandEndingScene) * arg0->trans.x + D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].x;
        func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[i]->coords, x, D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].y,
                      cosf((angle + arg0->rot.y) * D_8010F830_YoshisTropicalIslandEndingScene) * arg0->trans.x + D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].z);
        func_800A0D00((Vec3f*)&D_80110448_YoshisTropicalIslandEndingScene[i]->xScale, arg0->scale.x, arg0->scale.x, arg0->scale.x);
    }
    arg0->rot.y -= 2.0f;
    if (arg0->rot.y <= 0.0f) {
        arg0->rot.y += 360.0f;
    }
    arg0->work[0]++;
}

const f64 D_8010F838_YoshisTropicalIslandEndingScene __attribute__((section(".rodata"))) = 0.0174532925199432955;
void func_8010D06C_YoshisTropicalIslandEndingScene(void) {
    Vec3f target;
    s32 sprites[6];
    Vec2f vel[6];
    Vec2f pos[6];
    s32 count = D_8010DC90_YoshisTropicalIslandEndingScene[GwSystem.unk_00];
    f32 radius = D_8010DCFC_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene];
    f32 angle;
    f32 x;
    s32 i;
    omObjData* obj;

    for (i = 0; i < count; i++) {
        D_80110448_YoshisTropicalIslandEndingScene[i] = MBModelCreate(0x25, NULL);
        angle = (360 / count) * i * D_8010F838_YoshisTropicalIslandEndingScene;
        x = sinf(angle) * radius + D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].x;
        func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[i]->coords, x, D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].y,
                      cosf(angle) * radius + D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].z);
        /* retail writes the scale into coords */
        func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[i]->coords, D_8010DD1C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene],
                      D_8010DD1C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene], D_8010DD1C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene]);
        D_80110400_YoshisTropicalIslandEndingScene[i] = func_80042728(D_80110448_YoshisTropicalIslandEndingScene[i], 1);
    }
    obj = omAddObj(0x1000, 0, 0, -1, &func_8010CE34_YoshisTropicalIslandEndingScene);
    obj->rot.y = 0.0f;
    obj->trans.x = radius;
    obj->trans.y = count;
    obj->scale.x = D_8010DD1C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene];
    obj->work[0] = 0;
    D_80110448_YoshisTropicalIslandEndingScene[10] = MBModelCreate(6, D_8010ED78_YoshisTropicalIslandEndingScene);
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[10]->coords, D_8010EE1C_YoshisTropicalIslandEndingScene.x, D_8010EE1C_YoshisTropicalIslandEndingScene.y, D_8010EE1C_YoshisTropicalIslandEndingScene.z);
    D_80110448_YoshisTropicalIslandEndingScene[10]->unk_0A |= 1;
    D_80110448_YoshisTropicalIslandEndingScene[11] = MBModelCreate(0x78, D_8010ED80_YoshisTropicalIslandEndingScene);
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[11]->coords, D_8010EE1C_YoshisTropicalIslandEndingScene.x - 100.0f, D_8010EE1C_YoshisTropicalIslandEndingScene.y, D_8010EE1C_YoshisTropicalIslandEndingScene.z);
    D_80110448_YoshisTropicalIslandEndingScene[11]->unk_0A |= 1;
    LoadBackgroundIndex(D_8010DD3C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene]);
    func_80072724(0xFF, 0xFF, 0xFF);
    SetFadeInTypeAndTime(2, 0x18);
    PlaySound(0x48);
    HuPrcSleep(0x36);
    while (radius >= 350.0f) {
        obj->trans.x = radius;
        if (radius - 10.0f < 350.0f) {
            func_80072724(0xFF, 0xFF, 0xFF);
            func_800726AC(0, 0);
            PlaySound(0x4B);
        }
        HuPrcVSleep();
        radius -= 10.0f;
    }
    HuPrcSleep(5);
    for (i = 0; i < count; i++) {
        MBModelKill(D_80110448_YoshisTropicalIslandEndingScene[i]);
        D_80110448_YoshisTropicalIslandEndingScene[i] = NULL;
        func_800427D4(D_80110400_YoshisTropicalIslandEndingScene[i]);
        D_80110400_YoshisTropicalIslandEndingScene[i] = NULL;
    }
    D_80110448_YoshisTropicalIslandEndingScene[0] = MBModelCreate(0x25, NULL);
    D_80110400_YoshisTropicalIslandEndingScene[0] = func_80042728(D_80110448_YoshisTropicalIslandEndingScene[0], 1);
    func_800258EC(*D_80110448_YoshisTropicalIslandEndingScene[0]->unk_3C->unk_40, 0x10000, 0x10000);
    i = 0xF8;
    func_80025AD4(*D_80110448_YoshisTropicalIslandEndingScene[0]->unk_3C->unk_40);
    func_80028C64(*D_80110448_YoshisTropicalIslandEndingScene[0]->unk_3C->unk_40, 0xFF, 0xFF, 0xFF, 0xFF);
    D_80110448_YoshisTropicalIslandEndingScene[0]->xScale = 2.0f * D_8010DD1C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene];
    D_80110448_YoshisTropicalIslandEndingScene[0]->yScale = 2.0f * D_8010DD1C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene];
    D_80110448_YoshisTropicalIslandEndingScene[0]->zScale = 2.0f * D_8010DD1C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene];
    D_80110448_YoshisTropicalIslandEndingScene[0]->coords.x = D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].x;
    D_80110448_YoshisTropicalIslandEndingScene[0]->coords.y = D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].y;
    D_80110448_YoshisTropicalIslandEndingScene[0]->coords.z = D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].z;
    omDelObj(obj);
    obj = omAddObj(0x1000, 0, 0, -1, &func_8010CD88_YoshisTropicalIslandEndingScene);
    obj->rot.x = 0.0f;
    HuPrcSleep(5);
    SetFadeInTypeAndTime(0, 0x10);
    HuPrcSleep(0x10);
    do {
        func_80028C64(*D_80110448_YoshisTropicalIslandEndingScene[0]->unk_3C->unk_40, i, i, i, 0xFF);
        HuPrcVSleep();
        if (i == 0x1C) {
            func_80060128(2);
        }
        i -= 4;
    } while (i >= 0);
    func_8004E3E0(0, &D_8010EE1C_YoshisTropicalIslandEndingScene, 0x14, D_80110448_YoshisTropicalIslandEndingScene[0]);
    for (i = 0; i < 0x14; i++) {
        D_80110448_YoshisTropicalIslandEndingScene[0]->xScale -= 0.15f;
        D_80110448_YoshisTropicalIslandEndingScene[0]->yScale -= 0.15f;
        D_80110448_YoshisTropicalIslandEndingScene[0]->zScale -= 0.15f;
        HuPrcVSleep();
    }
    omDelObj(obj);
    MBModelKill(D_80110448_YoshisTropicalIslandEndingScene[0]);
    D_80110448_YoshisTropicalIslandEndingScene[0] = NULL;
    func_800427D4(D_80110400_YoshisTropicalIslandEndingScene[0]);
    D_80110400_YoshisTropicalIslandEndingScene[0] = NULL;
    target.x = D_800F32A0->coords.x + 300.0f;
    target.y = D_800F32A0->coords.y + 1000.0f;
    target.z = D_800F32A0->coords.z + 1000.0f;
    func_8004E3E0(0, &target, 0x46, D_80110448_YoshisTropicalIslandEndingScene[10]);
    func_8004F4D4(D_80110448_YoshisTropicalIslandEndingScene[10], 0, 2);
    D_800F2B7C[*D_80110448_YoshisTropicalIslandEndingScene[10]->unk_3C->unk_40].unk_4C = 0.5f;
    D_80110300_YoshisTropicalIslandEndingScene[10] = omAddObj(0x800, 0, 0, -1, &func_8010CCB8_YoshisTropicalIslandEndingScene);
    D_80110300_YoshisTropicalIslandEndingScene[10]->rot.x = 0.0f;
    D_80110300_YoshisTropicalIslandEndingScene[10]->work[0] = 10;
    target.x = D_800F32A0->coords.x - 0.0f;
    target.y = D_800F32A0->coords.y + 1000.0f;
    target.z = D_800F32A0->coords.z + 1000.0f;
    func_8004E3E0(0, &target, 0x46, D_80110448_YoshisTropicalIslandEndingScene[11]);
    func_8004F4D4(D_80110448_YoshisTropicalIslandEndingScene[11], 0, 2);
    D_800F2B7C[*D_80110448_YoshisTropicalIslandEndingScene[11]->unk_3C->unk_40].unk_4C = 0.5f;
    D_80110300_YoshisTropicalIslandEndingScene[11] = omAddObj(0x800, 0, 0, -1, &func_8010CCB8_YoshisTropicalIslandEndingScene);
    D_80110300_YoshisTropicalIslandEndingScene[11]->rot.x = 0.0f;
    D_80110300_YoshisTropicalIslandEndingScene[11]->work[0] = 11;
    PlaySound(0x82);
    D_80110448_YoshisTropicalIslandEndingScene[14] = MBModelCreate(0x4E, NULL);
    D_80110448_YoshisTropicalIslandEndingScene[15] = MBModelParamCreate(D_80110448_YoshisTropicalIslandEndingScene[14]);
    D_80110448_YoshisTropicalIslandEndingScene[14]->coords.x = D_80110448_YoshisTropicalIslandEndingScene[15]->coords.x = D_80110448_YoshisTropicalIslandEndingScene[10]->coords.x;
    D_80110448_YoshisTropicalIslandEndingScene[14]->coords.y = D_80110448_YoshisTropicalIslandEndingScene[15]->coords.y = D_80110448_YoshisTropicalIslandEndingScene[10]->coords.y;
    D_80110448_YoshisTropicalIslandEndingScene[14]->coords.z = D_80110448_YoshisTropicalIslandEndingScene[15]->coords.z = D_80110448_YoshisTropicalIslandEndingScene[10]->coords.z;
    D_80110448_YoshisTropicalIslandEndingScene[15]->coords.x = D_80110448_YoshisTropicalIslandEndingScene[10]->coords.x;
    D_80110448_YoshisTropicalIslandEndingScene[15]->coords.y = D_80110448_YoshisTropicalIslandEndingScene[10]->coords.y;
    D_80110448_YoshisTropicalIslandEndingScene[15]->coords.z = D_80110448_YoshisTropicalIslandEndingScene[10]->coords.z;
    D_800F2B7C[*D_80110448_YoshisTropicalIslandEndingScene[14]->unk_3C->unk_40].unk_4C = 0.5f;
    for (i = 0; i < 0x46; i += 2) {
        /* retail scales model 14 on x only, then all of model 15 */
        D_80110448_YoshisTropicalIslandEndingScene[14]->xScale = D_80110448_YoshisTropicalIslandEndingScene[15]->yScale = D_80110448_YoshisTropicalIslandEndingScene[15]->zScale = i * 2;
        D_80110448_YoshisTropicalIslandEndingScene[15]->xScale = D_80110448_YoshisTropicalIslandEndingScene[15]->yScale = D_80110448_YoshisTropicalIslandEndingScene[15]->zScale = i;
        HuPrcVSleep();
    }
    PlaySound(0x7C);
    PlaySound(0x80);
    HuPrcSleep(0x14);
    func_80072724(0xFF, 0xFF, 0xFF);
    func_800726AC(0, 0x14);
    HuPrcSleep(0x14);
    i = 0;
    omDelObj(D_80110300_YoshisTropicalIslandEndingScene[10]);
    D_80110300_YoshisTropicalIslandEndingScene[10] = NULL;
    omDelObj(D_80110300_YoshisTropicalIslandEndingScene[11]);
    D_80110300_YoshisTropicalIslandEndingScene[11] = NULL;
    MBModelKill(D_80110448_YoshisTropicalIslandEndingScene[14]);
    MBModelKill(D_80110448_YoshisTropicalIslandEndingScene[15]);
    MBModelKill(D_80110448_YoshisTropicalIslandEndingScene[10]);
    MBModelKill(D_80110448_YoshisTropicalIslandEndingScene[11]);
    D_80110448_YoshisTropicalIslandEndingScene[14] = NULL;
    D_80110448_YoshisTropicalIslandEndingScene[15] = NULL;
    D_80110448_YoshisTropicalIslandEndingScene[10] = NULL;
    D_80110448_YoshisTropicalIslandEndingScene[11] = NULL;
    func_8004A140();
    for (i = 0; i < 6; i++) {
        sprites[i] = func_8004F628(D_8010EE28_YoshisTropicalIslandEndingScene[i], 0xA, D_8010EE40_YoshisTropicalIslandEndingScene[i].x, D_8010EE40_YoshisTropicalIslandEndingScene[i].y);
        pos[i].x = D_8010EE40_YoshisTropicalIslandEndingScene[i].x;
        pos[i].y = D_8010EE40_YoshisTropicalIslandEndingScene[i].y;
        vel[i].x = (160.0f - pos[i].x) / 200.0f;
        vel[i].y = (120.0f - pos[i].y) / 200.0f;
    }
    LoadBackgroundIndex(0x49);
    SetFadeInTypeAndTime(0, 0x10);
    HuPrcSleep(0x38);
    for (count = 0; count < 0x3C; count++) {
        for (i = 0; i < 6; i++) {
            pos[i].x += vel[i].x;
            pos[i].y += vel[i].y;
            func_8004F754(sprites[i], pos[i].x, pos[i].y);
        }
        HuPrcVSleep();
        if (count == 0x28) {
            func_80072724(0xFF, 0xFF, 0);
            func_800726AC(0, 0x10);
        }
    }
    for (i = 0; i < 6; i++) {
        func_8004F584(sprites[i]);
    }
}
