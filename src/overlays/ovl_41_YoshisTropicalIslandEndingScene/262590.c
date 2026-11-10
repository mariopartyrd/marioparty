#include "ending.h"

/* Peach's Birthday Cake ending (board 1): func_800FA580 (setup), func_800F96E4 (scene) */

#define ENDING_BOARD D_801102B0_YoshisTropicalIslandEndingScene
/* ending.h: s32[2]; retail only ever uses it as a scalar (see the fork report) */
#define ENDING_CENTER D_8010DC9C_YoshisTropicalIslandEndingScene

void func_8004FAB8(s32);
void func_80028C64(s16, u8, u8, u8, u8);
void func_80052DC8(s16, void*);
void func_80052F34(s16);
void func_800674BC(s16, s16, s32);
void func_80067704(s16);

void func_800F8F00_YoshisTropicalIslandEndingScene(void);
void func_800F8FBC_YoshisTropicalIslandEndingScene(void);
void func_800F8FE8_YoshisTropicalIslandEndingScene(omObjData* arg0);
void func_800F9210_YoshisTropicalIslandEndingScene(s32 arg0);
void func_800FA258_YoshisTropicalIslandEndingScene(omObjData* arg0);
void func_800FA348_YoshisTropicalIslandEndingScene(omObjData* arg0);

/* 25FC70's .data: MBModelCreate lists */
extern s32 D_8010DD5C_YoshisTropicalIslandEndingScene[4];
extern s32 D_8010DD6C_YoshisTropicalIslandEndingScene[4];

/* .data 0x8010E090-0x8010E2AF */
/* LoadFormFile handles: -1 or a u16 id, passed on as (s16) */
s32 D_8010E090_YoshisTropicalIslandEndingScene = -1;
s32 D_8010E094_YoshisTropicalIslandEndingScene = -1;
/* positions, 3 per actor: [n * 3 + 0] first scene start, [+1] its end / second scene start,
   [+2] second scene end. Splat labels inside: D_8010E09C/E0A0 (.y/.z of [0]), D_8010E0A4 [1],
   D_8010E0B0 [2], D_8010E188 [20], D_8010E1AC [23] */
Vec3f D_8010E098_YoshisTropicalIslandEndingScene[27] = {
    { 0.0f, 0.0f, 1475.0f }, { 0.0f, 0.0f, 1475.0f }, { 0.0f, 0.0f, 2065.0f },
    { -125.0f, 0.0f, 1610.0f }, { -145.0f, 0.0f, 1660.0f }, { -160.0f, 0.0f, 1730.0f },
    { 150.0f, 0.0f, 1610.0f }, { 190.0f, 0.0f, 1610.0f }, { 225.0f, 0.0f, 1775.0f },
    { 0.0f, 295.0f, 1475.0f }, { 0.0f, 295.0f, 1475.0f }, { 0.0f, 250.0f, 1815.0f },
    { -135.0f, 0.0f, 1290.0f }, { -135.0f, 0.0f, 1290.0f }, { -135.0f, 0.0f, 1290.0f },
    { 135.0f, 0.0f, 1290.0f }, { 135.0f, 0.0f, 1290.0f }, { 135.0f, 0.0f, 1290.0f },
    { 20.0f, 0.0f, 1710.0f }, { 75.0f, 0.0f, 1775.0f }, { 130.0f, 0.0f, 1890.0f },
    { -235.0f, 0.0f, 1485.0f }, { -305.0f, 0.0f, 1540.0f }, { -235.0f, 0.0f, 1880.0f },
    { 280.0f, 0.0f, 1470.0f }, { 335.0f, 0.0f, 1490.0f }, { 330.0f, 0.0f, 1610.0f },
};
Vec3f D_8010E1DC_YoshisTropicalIslandEndingScene = { -80.0f, 0.0f, 1310.0f };
Vec3f D_8010E1E8_YoshisTropicalIslandEndingScene = { 115.0f, 0.0f, 1520.0f };
/* player model lists per character (count, file ids) */
s32 D_8010E1F4_YoshisTropicalIslandEndingScene[6] = { 5, 0x0001000A, 0x00010000, 0x00010001, 0x00010003, 0x00010097 };
s32 D_8010E20C_YoshisTropicalIslandEndingScene[6] = { 5, 0x0002000A, 0x00020000, 0x00020001, 0x00020003, 0x00020097 };
s32 D_8010E224_YoshisTropicalIslandEndingScene[6] = { 5, 0x0006000A, 0x00060000, 0x00060001, 0x00060003, 0x00060097 };
s32 D_8010E23C_YoshisTropicalIslandEndingScene[6] = { 5, 0x0003000A, 0x00030000, 0x00030001, 0x00030003, 0x00030097 };
s32 D_8010E254_YoshisTropicalIslandEndingScene[6] = { 5, 0x0004000A, 0x00040000, 0x00040001, 0x00040003, 0x00040097 };
s32 D_8010E26C_YoshisTropicalIslandEndingScene[6] = { 5, 0x0005000A, 0x00050000, 0x00050001, 0x00050003, 0x00050097 };
s32* D_8010E284_YoshisTropicalIslandEndingScene[6] = {
    D_8010E1F4_YoshisTropicalIslandEndingScene, D_8010E20C_YoshisTropicalIslandEndingScene,
    D_8010E224_YoshisTropicalIslandEndingScene, D_8010E23C_YoshisTropicalIslandEndingScene,
    D_8010E254_YoshisTropicalIslandEndingScene, D_8010E26C_YoshisTropicalIslandEndingScene,
};
s32 D_8010E29C_YoshisTropicalIslandEndingScene[5] = { 2, 0x4A, 0x4D, 0, 0 };

/* .bss used only here: s16 results kept as words, read back as (s16) */
extern s32 D_8010F860_YoshisTropicalIslandEndingScene;
extern s32 D_8010F864_YoshisTropicalIslandEndingScene;

#define MODEL D_80110448_YoshisTropicalIslandEndingScene
#define OBJ D_80110300_YoshisTropicalIslandEndingScene
#define POS D_8010E098_YoshisTropicalIslandEndingScene

void func_800F8F00_YoshisTropicalIslandEndingScene(void) {
    void* data;

    D_8010F860_YoshisTropicalIslandEndingScene = func_80064EF4(1, 5);
    data = DataRead(0xA0101);
    D_8010F864_YoshisTropicalIslandEndingScene = func_800678A4(data);
    DataClose(data);
    func_80067208((s16)D_8010F860_YoshisTropicalIslandEndingScene, 0, (s16)D_8010F864_YoshisTropicalIslandEndingScene, 0);
    func_80067384((s16)D_8010F860_YoshisTropicalIslandEndingScene, 0, 0x47F4);
    func_800674BC((s16)D_8010F860_YoshisTropicalIslandEndingScene, 0, 0x1000);
    func_80066DC4((s16)D_8010F860_YoshisTropicalIslandEndingScene, 0, 0xA0, 0x78);
}

void func_800F8FBC_YoshisTropicalIslandEndingScene(void) {
    func_80064D38((s16)D_8010F860_YoshisTropicalIslandEndingScene);
    func_80067704((s16)D_8010F864_YoshisTropicalIslandEndingScene);
}

void func_800F8FE8_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    switch (arg0->work[0]) {
    case 0:
    case 1:
        arg0->rot.x += 5.0f;
        if (arg0->rot.x >= 360.0f) {
            if (arg0->work[0] == 1) {
                arg0->work[0] = 2;
            }
            arg0->rot.x -= 360.0f;
        }
        MODEL[0]->coords.x = (sinf(arg0->rot.x * (M_PI / 180.0)) * 70.0f * 5.0f) + arg0->trans.x;
        MODEL[0]->coords.y = arg0->trans.y;
        MODEL[0]->coords.z = (arg0->trans.z - 150.0f) + (cosf(arg0->rot.x * (M_PI / 180.0)) * 30.0f * 5.0f);
        arg0->work[3]++;
        break;
    case 2:
        arg0->rot.x += 5.0f;
        if (arg0->rot.x >= 360.0f) {
            arg0->rot.x -= 360.0f;
        }
        MODEL[0]->unk_3C->unk_24 = 90.0f;
        MODEL[0]->unk_3C->unk28 = 0.0f;
        MODEL[0]->unk_3C->unk_2C = sinf(arg0->rot.x * (M_PI / 180.0)) * 10.0f;
        break;
    }
}

// argument register order in one func_8004CCD0 call (masked 1)
#ifdef NON_MATCHING
void func_800F9210_YoshisTropicalIslandEndingScene(s32 arg0) {
    s32 ids[6] = { 0x25, 12, 12, 7, 11, 8 };
    s32* lists[6] = { NULL, D_8010E29C_YoshisTropicalIslandEndingScene, D_8010E29C_YoshisTropicalIslandEndingScene, D_8010DD6C_YoshisTropicalIslandEndingScene, NULL, D_8010DD5C_YoshisTropicalIslandEndingScene };
    s32 i;
    Object* model;
    Vec3f* from;
    Vec3f* to;

    for (i = 0; i < 4; i++) {
        if (GwCommon.boardWork[3] != i) {
            func_80052DC8(i, D_8010E284_YoshisTropicalIslandEndingScene[GwPlayer[i].character]);
            func_80052F34(i);
            func_80021B14(*GwPlayer[i].player_obj->unk_3C->unk_40, GwPlayer[i].character, 0x80);
            GwPlayer[i].flags |= 2;
        }
    }
    HuPrcSleep(5);
    for (i = 0; i < 3; i++) {
        GwPlayer[GwCommon.boardWork[i]].player_obj->coords.x = POS[i * 3 + arg0].x;
        GwPlayer[GwCommon.boardWork[i]].player_obj->coords.y = POS[i * 3 + arg0].y;
        GwPlayer[GwCommon.boardWork[i]].player_obj->coords.z = POS[i * 3 + arg0].z;
        if (i != 0) {
            if (arg0 == 0) {
                model = GwPlayer[GwCommon.boardWork[i]].player_obj;
                to = &GwPlayer[GwCommon.boardWork[0]].player_obj->coords;
                from = &model->coords;
            } else {
                model = GwPlayer[GwCommon.boardWork[i]].player_obj;
                from = &model->coords;
                to = &D_800F32A0->coords;
            }
            func_8004CCD0(from, to, &model->unk_18);
        }
    }
    for (i = 0; i < 6; i++) {
        MODEL[i] = MBModelCreate(ids[i], lists[i]);
        MODEL[i]->coords.x = POS[(i + 3) * 3 + arg0].x;
        MODEL[i]->coords.y = POS[(i + 3) * 3 + arg0].y;
        MODEL[i]->coords.z = POS[(i + 3) * 3 + arg0].z;
        if (arg0 == 0) {
            model = MODEL[i];
            to = &GwPlayer[GwCommon.boardWork[0]].player_obj->coords;
            from = &model->coords;
        } else {
            model = MODEL[i];
            from = &model->coords;
            to = &D_800F32A0->coords;
        }
        func_8004CCD0(from, to, &model->unk_18);
        if (ids[i] != 8) {
            func_80025B34(*MODEL[i]->unk_3C->unk_40);
        }
    }
    func_8004F140(*MODEL[5]->unk_3C->unk_40);
    MODEL[0]->unk_3C->unk_24 = 90.0f;
    MODEL[0]->unk_3C->unk28 = 0.0f;
    MODEL[0]->unk_3C->unk_2C = 0.0f;
    OBJ[0] = omAddObj(0x1000, 0, 0, -1, func_800F8FE8_YoshisTropicalIslandEndingScene);
    OBJ[0]->trans.x = POS[arg0 + 9].x;
    OBJ[0]->trans.y = POS[arg0 + 9].y;
    OBJ[0]->trans.z = POS[arg0 + 9].z;
    OBJ[0]->rot.x = 360.0f;
    OBJ[0]->work[0] = arg0 * 2;
    OBJ[0]->work[3] = 0;
    D_80110400_YoshisTropicalIslandEndingScene[0] = func_80042728(MODEL[0], 1);
}
#else
const s32 D_8010EF00_YoshisTropicalIslandEndingScene[6] __attribute__((section(".rodata"))) = { 0x25, 12, 12, 7, 11, 8 };
s32* const D_8010EF18_YoshisTropicalIslandEndingScene[6] __attribute__((section(".rodata"))) = {
    NULL, D_8010E29C_YoshisTropicalIslandEndingScene, D_8010E29C_YoshisTropicalIslandEndingScene, D_8010DD6C_YoshisTropicalIslandEndingScene, NULL, D_8010DD5C_YoshisTropicalIslandEndingScene,
};
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/262590", func_800F9210_YoshisTropicalIslandEndingScene);
#endif

void func_800F96E4_YoshisTropicalIslandEndingScene(void) {
    s32 i;
    s32 j;
    Object* model;

    LoadBackgroundIndex(0xD);
    func_800F9210_YoshisTropicalIslandEndingScene(0);
    SetFadeInTypeAndTime(0, 0x10);
    HuPrcSleep(0x2E);
    OBJ[0]->work[0] = 1;
    HuPrcSleep(0x1E);
    for (i = 0; i < 3; i++) {
        func_8004E3E0(GwCommon.boardWork[i], &POS[i * 3 + 1], 0x14, NULL);
        func_8004EE14(GwCommon.boardWork[i], D_800F32A0, 0x14, NULL);
        if (i != 0) {
            func_8004F4D4(GwPlayer[GwCommon.boardWork[i]].player_obj, 2, 2);
        }
    }
    for (i = 1; i < 6; i++) {
        func_8004E3E0(0, &POS[(i + 3) * 3 + 1], 0x14, MODEL[i]);
        func_8004EE14(0, D_800F32A0, 0x14, MODEL[i]);
        if (i == 5) {
            func_8004F4D4(MODEL[5], 1, 2);
        }
        if (i == 3) {
            func_8004F4D4(MODEL[i], 1, 2);
        }
    }
    HuPrcSleep(0x14);
    func_8004F4D4(GwPlayer[GwCommon.boardWork[1]].player_obj, 1, 2);
    func_8004F4D4(GwPlayer[GwCommon.boardWork[2]].player_obj, 1, 2);
    func_8004F4D4(MODEL[5], 0, 2);
    func_8004F4D4(MODEL[3], 0, 2);
    HuPrcSleep(0x46);
    func_800726AC(1, 0x10);
    HuPrcSleep(0x10);
    i = 0;
    func_8004A140();
    func_800F6B54_YoshisTropicalIslandEndingScene();
    HuPrcSleep(5);
    LoadBackgroundIndex(9);
    func_800F8F00_YoshisTropicalIslandEndingScene();
    MODEL[0] = MBModelCreate(0xC, D_8010E29C_YoshisTropicalIslandEndingScene);
    MODEL[0]->coords.x = D_8010E1DC_YoshisTropicalIslandEndingScene.x;
    MODEL[0]->coords.y = D_8010E1DC_YoshisTropicalIslandEndingScene.y;
    MODEL[0]->coords.z = D_8010E1DC_YoshisTropicalIslandEndingScene.z;
    MODEL[0]->unk_18.x = 1.0f;
    MODEL[0]->unk_18.y = 0.0f;
    MODEL[0]->unk_18.z = 0.0f;
    MBMotionSet(MODEL[0], 0, 2);
    for (; i < 4; i++) {
        if (GwCommon.boardWork[3] == i) {
            func_80052DC8(i, D_8010E284_YoshisTropicalIslandEndingScene[GwPlayer[i].character]);
            func_80052F34(i);
            GwPlayer[i].flags |= 2;
            GwPlayer[i].player_obj->coords.x = D_8010E1E8_YoshisTropicalIslandEndingScene.x;
            GwPlayer[i].player_obj->coords.y = D_8010E1E8_YoshisTropicalIslandEndingScene.y;
            GwPlayer[i].player_obj->coords.z = D_8010E1E8_YoshisTropicalIslandEndingScene.z;
            func_8004CCD0(&GwPlayer[i].player_obj->coords, &MODEL[0]->coords, &GwPlayer[i].player_obj->unk_18);
        }
    }
    SetFadeInTypeAndTime(1, 0x10);
    HuPrcSleep(0x10);
    for (i = 0; i < 2; i++) {
        HuPrcSleep(0xE);
        HuPrcSleep(0xF);
        func_8004F4D4(GwPlayer[GwCommon.boardWork[3]].player_obj, 0, 0);
        if (D_8010E094_YoshisTropicalIslandEndingScene != -1) {
            func_8002456C((s16)D_8010E094_YoshisTropicalIslandEndingScene);
        }
        D_8010E094_YoshisTropicalIslandEndingScene = LoadFormFile(0x1E, 0x6B9);
        model = GwPlayer[GwCommon.boardWork[3]].player_obj;
        func_80025798((s16)D_8010E094_YoshisTropicalIslandEndingScene, model->coords.x, model->coords.y, model->coords.z);
        func_80025830((s16)D_8010E094_YoshisTropicalIslandEndingScene, 0.5f, 0.5f, 0.5f);
        HuPrcSleep(0xF);
        if (D_8010E090_YoshisTropicalIslandEndingScene != -1) {
            func_8002456C((s16)D_8010E090_YoshisTropicalIslandEndingScene);
        }
        D_8010E090_YoshisTropicalIslandEndingScene = LoadFormFile(0x1D, 0x6B9);
        model = GwPlayer[GwCommon.boardWork[3]].player_obj;
        func_80025798((s16)D_8010E090_YoshisTropicalIslandEndingScene, model->coords.x, model->coords.y, model->coords.z);
        HuPrcSleep(0xB);
    }
    func_800726AC(1, 0x10);
    HuPrcSleep(0xE);
    HuPrcSleep(2);
    i = 1;
    func_8004A140();
    func_800F8FBC_YoshisTropicalIslandEndingScene();
    func_800F6B54_YoshisTropicalIslandEndingScene();
    func_8004FAB8(D_80110440_YoshisTropicalIslandEndingScene);
    func_8002456C((s16)D_8010E090_YoshisTropicalIslandEndingScene);
    func_8002456C((s16)D_8010E094_YoshisTropicalIslandEndingScene);
    D_8010E090_YoshisTropicalIslandEndingScene = -1;
    D_8010E094_YoshisTropicalIslandEndingScene = -1;
    HuPrcSleep(5);
    LoadBackgroundIndex(0xD);
    func_800F9210_YoshisTropicalIslandEndingScene(1);
    SetFadeInTypeAndTime(1, 0x10);
    HuPrcSleep(0x1E);
    func_8004E3E0(0, &POS[20], 0x14, MODEL[3]);
    func_8004EE14(0, D_800F32A0, 0x14, MODEL[3]);
    func_8004F4D4(MODEL[3], 1, 2);
    HuPrcSleep(0xA);
    func_8004E3E0(0, &POS[23], 0xA, MODEL[4]);
    func_8004EE14(0, D_800F32A0, 0xA, MODEL[4]);
    HuPrcSleep(5);
    for (; i < 3; i++) {
        func_8004E3E0(GwCommon.boardWork[i], &POS[i * 3 + 2], 0x14, NULL);
        func_8004EE14(GwCommon.boardWork[i], D_800F32A0, 0x14, NULL);
    }
    for (i = 0; i < 6; i++) {
        if (i + 3 != 6 && i + 3 != 7) {
            func_8004E3E0(0, &POS[(i + 3) * 3 + 2], 0x14, MODEL[i]);
            func_8004EE14(0, D_800F32A0, 0x14, MODEL[i]);
        }
    }
    func_8004F4D4(GwPlayer[GwCommon.boardWork[1]].player_obj, 2, 2);
    func_8004F4D4(GwPlayer[GwCommon.boardWork[2]].player_obj, 2, 2);
    func_8004F4D4(MODEL[5], 1, 2);
    func_8004F4D4(MODEL[1], 1, 2);
    func_8004F4D4(MODEL[2], 1, 2);
    HuPrcSleep(5);
    func_8004F4D4(MODEL[3], 0, 2);
    HuPrcSleep(0xF);
    func_8004F4D4(GwPlayer[GwCommon.boardWork[1]].player_obj, 1, 2);
    func_8004F4D4(GwPlayer[GwCommon.boardWork[2]].player_obj, 1, 2);
    func_8004F4D4(MODEL[5], 0, 2);
    HuPrcSleep(0xA);
    for (i = 1; i < 3; i++) {
        func_8004EE14(GwCommon.boardWork[i], &GwPlayer[GwCommon.boardWork[0]].player_obj->coords, 0xA, NULL);
    }
    for (i = 0; i < 6; i++) {
        func_8004EE14(0, &GwPlayer[GwCommon.boardWork[0]].player_obj->coords, 0xA, MODEL[i]);
    }
    HuPrcSleep(0x14);
    for (i = 0; i < 2; i++) {
        func_8004F00C(MODEL[4], 40.0f, -5.0f);
        func_8004F044(MODEL[4]);
    }
    HuPrcSleep(0x14);
    func_8004E3E0(GwCommon.boardWork[0], &POS[2], 0x28, NULL);
    func_8004EE14(GwCommon.boardWork[0], D_800F32A0, 0x28, NULL);
    func_8004F4D4(GwPlayer[GwCommon.boardWork[0]].player_obj, 2, 2);
    for (j = 0; j < 40; j++) {
        for (i = 1; i < 3; i++) {
            func_8004EE14(GwCommon.boardWork[i], &GwPlayer[GwCommon.boardWork[0]].player_obj->coords, 1, NULL);
        }
        for (i = 0; i < 6; i++) {
            if (i + 3 != 3) {
                func_8004EE14(0, &GwPlayer[GwCommon.boardWork[0]].player_obj->coords, 1, MODEL[i]);
            }
        }
        HuPrcVSleep();
    }
    func_8004F4D4(GwPlayer[GwCommon.boardWork[0]].player_obj, 1, 2);
    HuPrcSleep(0xA);
    for (i = 1; i < 3; i++) {
        func_8004EE14(GwCommon.boardWork[i], D_800F32A0, 0x14, NULL);
    }
    for (i = 0; i < 6; i++) {
        func_8004EE14(0, D_800F32A0, 0x14, MODEL[i]);
    }
    HuPrcSleep(0x14);
    func_8004F4D4(GwPlayer[GwCommon.boardWork[0]].player_obj, 4, 0);
}

void func_800FA258_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    arg0->rot.x += 5.0f;
    if (arg0->rot.x >= 360.0f) {
        arg0->rot.x -= 360.0f;
    }
    MODEL[0]->unk_18.x = sinf((sinf(arg0->rot.x * (M_PI / 180.0)) * 10.0f) * (M_PI / 180.0));
    MODEL[0]->unk_18.z = cosf((sinf(arg0->rot.x * (M_PI / 180.0)) * 10.0f) * (M_PI / 180.0));
}

void func_800FA348_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    s32 count;
    s32 i;
    f32 angle;

    count = D_8010DC90_YoshisTropicalIslandEndingScene[GwSystem.unk_00];
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

// float register allocation (angle f20/f22 swapped) and centre-index scheduling
#ifdef NON_MATCHING
void func_800FA580_YoshisTropicalIslandEndingScene(void) {
    s32 count;
    s32 i;
    f32 dist;
    f32 angle;
    omObjData* ring;
    Vec3f pos;

    count = D_8010DC90_YoshisTropicalIslandEndingScene[GwSystem.unk_00];
    dist = D_8010DCFC_YoshisTropicalIslandEndingScene[ENDING_BOARD];
    for (i = 0; i < count; i++) {
        MODEL[i] = MBModelCreate(0x25, NULL);
        angle = ((360 / count) * i) * (M_PI / 180.0);
        func_800A0D00(&MODEL[i]->coords,
                      (sinf(angle) * dist) + ENDING_CENTER[ENDING_BOARD].x,
                      ENDING_CENTER[ENDING_BOARD].y,
                      (cosf(angle) * dist) + ENDING_CENTER[ENDING_BOARD].z);
        func_800A0D00((Vec3f*)&MODEL[i]->xScale,
                      D_8010DD1C_YoshisTropicalIslandEndingScene[ENDING_BOARD],
                      D_8010DD1C_YoshisTropicalIslandEndingScene[ENDING_BOARD],
                      D_8010DD1C_YoshisTropicalIslandEndingScene[ENDING_BOARD]);
        D_80110400_YoshisTropicalIslandEndingScene[i] = func_80042728(MODEL[i], 1);
    }
    ring = omAddObj(0x1000, 0, 0, -1, func_800FA348_YoshisTropicalIslandEndingScene);
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
    func_800258EC(*MODEL[0]->unk_3C->unk_40, 0x10000, 0x10000);
    i = 0xF8;
    func_80025AD4(*MODEL[0]->unk_3C->unk_40);
    func_80028C64(*MODEL[0]->unk_3C->unk_40, 0xFF, 0xFF, 0xFF, 0xFF);
    func_800A0D00((Vec3f*)&MODEL[0]->xScale, 2.0f * D_8010DD1C_YoshisTropicalIslandEndingScene[ENDING_BOARD],
                  2.0f * D_8010DD1C_YoshisTropicalIslandEndingScene[ENDING_BOARD],
                  2.0f * D_8010DD1C_YoshisTropicalIslandEndingScene[ENDING_BOARD]);
    func_800A0D00(&MODEL[0]->coords, ENDING_CENTER[ENDING_BOARD].x, ENDING_CENTER[ENDING_BOARD].y,
                  ENDING_CENTER[ENDING_BOARD].z);
    omDelObj(ring);
    ring = omAddObj(0x1000, 0, 0, -1, func_800FA258_YoshisTropicalIslandEndingScene);
    ring->rot.x = 0.0f;
    HuPrcSleep(5);
    SetFadeInTypeAndTime(0, 0x10);
    HuPrcSleep(0x10);
    do {
        func_80028C64(*MODEL[0]->unk_3C->unk_40, i, i, i, 0xFF);
        i -= 4;
        HuPrcVSleep();
    } while (i >= 0);
    for (i = 0; i < 8; i++) {
        MODEL[i + 4] = MBModelCreate(0x25, NULL);
        D_80110400_YoshisTropicalIslandEndingScene[i + 4] = func_80042728(MODEL[i + 4], 2);
        MBModelDispOff(MODEL[i + 4]);
        func_800A0D00((Vec3f*)&MODEL[i + 4]->xScale,
                      D_8010DD1C_YoshisTropicalIslandEndingScene[ENDING_BOARD],
                      D_8010DD1C_YoshisTropicalIslandEndingScene[ENDING_BOARD],
                      D_8010DD1C_YoshisTropicalIslandEndingScene[ENDING_BOARD]);
        func_800A0D00(&MODEL[i + 4]->coords, ENDING_CENTER[ENDING_BOARD].x, ENDING_CENTER[ENDING_BOARD].y,
                      ENDING_CENTER[ENDING_BOARD].z);
        {
            Vec3f* c = &ENDING_CENTER[ENDING_BOARD];
            f32 x;

            angle = (i * 45) * (M_PI / 180.0);
            x = (sinf(angle) * 1000.0f) + c->x;
            c = &ENDING_CENTER[ENDING_BOARD];
            func_800A0D00(&pos, x, ENDING_CENTER[ENDING_BOARD].y, (cosf(angle) * 1000.0f) + c->z);
        }
        func_8004E3E0(0, &pos, 0x32, MODEL[i + 4]);
    }
    HuPrcSleep(0x32);
    PlaySound(0x56);
    func_80072724(0xFF, 0xFF, 0xFF);
    func_800726AC(0, 0);
    HuPrcSleep(0x14);
    for (i = 0; i < 8; i++) {
        MBModelKill(MODEL[i + 4]);
        MODEL[i + 4] = NULL;
        func_800427D4(D_80110400_YoshisTropicalIslandEndingScene[i + 4]);
        D_80110400_YoshisTropicalIslandEndingScene[i + 4] = NULL;
    }
    func_8004A140();
    LoadBackgroundIndex(0x10);
    func_80060128(2);
    SetFadeInTypeAndTime(0, 0x3C);
    HuPrcSleep(0x3C);
    HuPrcSleep(0x1E);
    func_800726AC(0, 0x14);
    HuPrcSleep(0x14);
    omDelObj(ring);
    MBModelKill(MODEL[0]);
    MODEL[0] = NULL;
    func_8004A140();
    HuPrcSleep(5);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/262590", func_800FA580_YoshisTropicalIslandEndingScene);
#endif
