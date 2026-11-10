#include "ResultsScene.h"

void func_80071598(s16);
void func_8007166C(s16);

/* One row of the stats table: each player's value printed into its digits buffer. */
#define STATROW(i, j, fmt, cast, field)                                                         \
    for (j = 0; j < 4; j++) {                                                                   \
        sprintf((char*)D_800FC630_ResultsScene[i][j], fmt, (cast)GwPlayer[GwCommon.boardWork[j]].field); \
        func_8006DA5C((s16)D_800FC600_ResultsScene[i], D_800FC630_ResultsScene[i][j], j);       \
    }

/* The end-of-game results: the stats table (stars, coins, minigame coins, max coins, space counts),
   scrolled with the stick; then each player's coins and stars fall into the bank, the board's item
   (if any) changes the coin total, and the stars go to the star pile. */

/* .data */
s32 D_800FC050_ResultsScene = 3; /* falling-coin sound pacing */
Vec3f D_800FC054_ResultsScene = { -60.0f, -30.0f, 0.0f }; /* star pile centre */
Vec3f D_800FC060_ResultsScene = { -60.0f, 200.0f, 0.0f }; /* the board item model */
/* coin start points; [0].y is also the height a finished coin or star returns to */
Vec3f D_800FC06C_ResultsScene[3] = { { -60.0f, 200.0f, 0.0f }, { -90.0f, 200.0f, 0.0f }, { -30.0f, 200.0f, 0.0f } };
Vec3f D_800FC090_ResultsScene = { -500.0f, -30.0f, 0.0f };
s32 D_800FC09C_ResultsScene[11] = { 6, 17, 26, 38, 46, 55, 67, 76, 76, 102, 76 }; /* background per board */
s32 D_800FC0C8_ResultsScene[4] = { 14, 15, 16, 17 };
f32 D_800FC0D8_ResultsScene[2] = { 0.0f, 0.0f };
s32 D_800FC0E0_ResultsScene = 0; /* first stats row shown (0..7) */
s32 D_800FC0E4_ResultsScene = 0; /* cursor row on screen (0..3) */
s16 D_800FC0E8_ResultsScene[4][2] = { { 136, 105 }, { 179, 105 }, { 222, 105 }, { 267, 105 } };
s16 D_800FC0F8_ResultsScene[4][2] = { { 136, 64 }, { 179, 64 }, { 222, 64 }, { 267, 64 } };
s16 D_800FC108_ResultsScene[4][2] = { { 106, 70 }, { 150, 70 }, { 194, 70 }, { 238, 70 } };
s16 D_800FC118_ResultsScene[4][2] = { { 76, 80 }, { 76, 100 }, { 76, 120 }, { 76, 140 } };
s16 D_800FC128_ResultsScene[4][2] = { { 36, 80 }, { 36, 100 }, { 36, 120 }, { 36, 140 } };
s16 D_800FC138_ResultsScene[2] = { 107, 38 };
s16 D_800FC13C_ResultsScene[2] = { 240, 35 };
s16 D_800FC140_ResultsScene[2][2] = { { 120, 157 }, { 280, 157 } }; /* scroll arrows */
f32 D_800FC148_ResultsScene[11] = { 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f };
s32 D_800FC174_ResultsScene[11] = { 0xA0014, 0xA0013, 0xA018D, 0xA018E, 0xA0190, 0xA018F,
                                    0xA0191, 0xA0192, 0xA0193, 0xA0194, 0xA0195 };
s32 D_800FC1A0_ResultsScene[2] = { 0xA0112, 0xA0113 };
s32 D_800FC1A8_ResultsScene[3] = { 0xA0189, 0xA018A, 0xA018B };
s32 D_800FC1B4_ResultsScene[8] = { 0xA0196, 0xA0197, 0xA0198, 0xA0199, 0xA019A, 0xA019B, 0xA019C, 0xA019D };
s32 D_800FC1D4_ResultsScene[6] = { 0x6E, 0x6F, 0x70, 0x71, 0x72, 0x73 };
s32 D_800FC1EC_ResultsScene[6] = { 0xA010C, 0xA010D, 0xA010E, 0xA010F, 0xA0110, 0xA0111 };
s32 D_800FC204_ResultsScene[11] = { 0x4F4, 0x4F5, 0x4F6, 0x4F7, 0x4F8, 0x4F9, 0x4FA, 0x4FB, 0x4FC, 0x4FD, 0x4FE };
extern const char D_800FC34C_ResultsScene[];
char* D_800FC230_ResultsScene = (char*)D_800FC34C_ResultsScene; /* "RESULTS" */
s16 D_800FC234_ResultsScene[2] = { 160, 34 };
s16 D_800FC238_ResultsScene[4][2] = { { 60, 70 }, { 60, 110 }, { 60, 150 }, { 60, 190 } };
s16 D_800FC248_ResultsScene[4][2] = { { 80, 70 }, { 80, 110 }, { 80, 150 }, { 80, 190 } };
s16 D_800FC258_ResultsScene[4][2] = { { 110, 70 }, { 110, 110 }, { 110, 150 }, { 110, 190 } };
s16 D_800FC268_ResultsScene[4][2] = { { 150, 70 }, { 150, 110 }, { 150, 150 }, { 150, 190 } };
s16 D_800FC278_ResultsScene[4][2] = { { 151, 70 }, { 151, 110 }, { 151, 150 }, { 151, 190 } };
s16 D_800FC288_ResultsScene[4][2] = { { 226, 70 }, { 226, 110 }, { 226, 150 }, { 226, 190 } };
s16 D_800FC298_ResultsScene[4][2] = { { 206, 70 }, { 206, 110 }, { 206, 150 }, { 206, 190 } };
s16 D_800FC2A8_ResultsScene[8][2] = { { 174, 74 }, { 174, 114 }, { 174, 154 }, { 174, 194 },
                                      { 250, 74 }, { 250, 114 }, { 250, 154 }, { 250, 194 } };
s16 D_800FC2C8_ResultsScene[8][2] = { { 174, 74 }, { 174, 114 }, { 174, 154 }, { 174, 194 },
                                      { 230, 74 }, { 230, 114 }, { 230, 154 }, { 230, 194 } };
s32 D_800FC2E8_ResultsScene[6] = { 0xA0183, 0xA0184, 0xA0185, 0xA0186, 0xA0187, 0xA0188 };
s32 D_800FC300_ResultsScene = 0; /* next coin model (0..19); splat's D_800FC303 is its low byte */
s32 D_800FC304_ResultsScene[3] = { 0x260, 0x261, 0x262 }; /* the roulette's messages */

void func_800F65E0_ResultsScene(void) {
    s32 i;

    omInitObjMan(0x64, 0x50);
    D_800FC440_ResultsScene = 0;
    for (i = 0; i < 4; i++) {
        D_800FC430_ResultsScene[GwCommon.boardWork[i]] = GwPlayer[GwCommon.boardWork[i]].coins;
        if (!(GwPlayer[GwCommon.boardWork[i]].flags & 1)) {
            D_800FC440_ResultsScene += D_800FC430_ResultsScene[GwCommon.boardWork[i]];
        }
    }

    D_800FC448_ResultsScene = 0;
    
    for (i = 0; i < 4; i++) {
        if (!(GwPlayer[GwCommon.boardWork[i]].flags & 1)) {
            D_800FC448_ResultsScene += GwPlayer[GwCommon.boardWork[i]].stars + GwCommon.boardWork[GwCommon.boardWork[i] + 10];
        }    
    }

    func_800FBF10_ResultsScene();
    func_8006CEA0();
    func_800532E0();
    MBModelInit();
    func_8004F548();
    func_800F7F1C_ResultsScene();
    omAddPrcObj(func_800FB054_ResultsScene, 0x300, 0x2000, 0);
    omAddObj(0x1000, 0, 0, -1, &func_800FB87C_ResultsScene);
}

void func_800F678C_ResultsScene(omObjData* arg0) {
    f32 x;

    if ((arg0->trans.x += 10.0f) >= 360.0f) {
        arg0->trans.x -= 360.0f;
    }
    func_800674F4((s16)D_800FC5B0_ResultsScene, 0, 0x40, 0x40,
                  sinf(arg0->trans.x * 0.017453292519943295) * 32.0f + 223.0f);
    if ((arg0->trans.y += 20.0f) >= 360.0f) {
        arg0->trans.y -= 360.0f;
    }
    D_800FC0D8_ResultsScene[0] += func_800AEAC0(arg0->trans.y) * 0.75f;
    func_80066DC4((s16)D_800FC5C0_ResultsScene, 1, D_800FC140_ResultsScene[0][0] + D_800FC0D8_ResultsScene[0],
                  D_800FC140_ResultsScene[0][1]);
    func_80066DC4((s16)D_800FC5C0_ResultsScene, 2, D_800FC140_ResultsScene[1][0] - D_800FC0D8_ResultsScene[0],
                  D_800FC140_ResultsScene[1][1]);
}
void func_800F6988_ResultsScene(void) {
    s32 i;

    if (D_800FC0E0_ResultsScene == 0) {
        func_800674BC((s16)D_800FC5C0_ResultsScene, 1, 0x8000);
    } else {
        func_80067480((s16)D_800FC5C0_ResultsScene, 1, 0x8000);
    }
    if (D_800FC0E0_ResultsScene == 7) {
        func_800674BC((s16)D_800FC5C0_ResultsScene, 2, 0x8000);
    } else {
        func_80067480((s16)D_800FC5C0_ResultsScene, 2, 0x8000);
    }
    for (i = 0; i < 11; i++) {
        func_800674BC((s16)D_800FC5CC_ResultsScene, i + 1, 0x8000);
    }
    for (i = 0; i < 4; i++) {
        func_80067480((s16)D_800FC5CC_ResultsScene, i + ((u16)D_800FC0E0_ResultsScene + 1), 0x8000);
        func_80066DC4((s16)D_800FC5CC_ResultsScene, i + ((u16)D_800FC0E0_ResultsScene + 1),
                      D_800FC0F8_ResultsScene[i][0] / D_800FC148_ResultsScene[i + D_800FC0E0_ResultsScene],
                      D_800FC0F8_ResultsScene[i][1] / D_800FC148_ResultsScene[i + D_800FC0E0_ResultsScene]);
    }
    func_80066DC4((s16)D_800FC5B0_ResultsScene, 0, D_800FC0E8_ResultsScene[D_800FC0E4_ResultsScene][0],
                  D_800FC0E8_ResultsScene[D_800FC0E4_ResultsScene][1]);
    for (i = 0; i < 11; i++) {
        func_80071598((s16)D_800FC600_ResultsScene[i]);
    }
    for (i = 0; i < 4; i++) {
        func_8007166C((s16)D_800FC600_ResultsScene[i + D_800FC0E0_ResultsScene]);
        func_8006DDC8((s16)D_800FC600_ResultsScene[i + D_800FC0E0_ResultsScene], D_800FC108_ResultsScene[i][0],
                      D_800FC108_ResultsScene[i][1]);
    }
    func_8006EB40(D_800FC5FC_ResultsScene->unk8);
    func_8006E070(D_800FC5FC_ResultsScene->unk8, 0);
    LoadStringIntoWindow(D_800FC5FC_ResultsScene->unk8,
                         (void*)(s32)D_800FC204_ResultsScene[D_800FC0E0_ResultsScene + D_800FC0E4_ResultsScene], -1, -1);
}
void func_800F6C70_ResultsScene(void) {
    s32 i;
    s32 j;
    s32 k;

    for (i = 0; i < 11; i++) {
        switch (i) {
            case 0:
                STATROW(i, j, "%3d", s16, stars);
                D_800ED4B0[D_800FC600_ResultsScene[i]].unk_24 = 0x14;
                LoadStringIntoWindow((s16)D_800FC600_ResultsScene[i], (void*)0x4FF, 0x14, 4);
                break;
            case 1:
                STATROW(i, j, "%3d", s16, coins);
                D_800ED4B0[D_800FC600_ResultsScene[i]].unk_24 = 0x14;
                LoadStringIntoWindow((s16)D_800FC600_ResultsScene[i], (void*)0x4FF, 0x14, 4);
                break;
            case 2:
                for (j = 0; j < 4; j++) {
                    sprintf((char*)D_800FC630_ResultsScene[i][j], "%4d", GwPlayer[GwCommon.boardWork[j]].coins_total);
                    for (k = 0; k < 4; k++) {
                        if (D_800FC630_ResultsScene[i][j][k] == '-') {
                            D_800FC630_ResultsScene[i][j][k] = '=';
                        }
                    }
                    func_8006DA5C((s16)D_800FC600_ResultsScene[i], D_800FC630_ResultsScene[i][j], j);
                }
                D_800ED4B0[D_800FC600_ResultsScene[i]].unk_24 = 0xF;
                LoadStringIntoWindow((s16)D_800FC600_ResultsScene[i], (void*)0x4FF, 0xF, 4);
                break;
            case 3:
                STATROW(i, j, "%3d", s16, coins_max);
                D_800ED4B0[D_800FC600_ResultsScene[i]].unk_24 = 0x14;
                LoadStringIntoWindow((s16)D_800FC600_ResultsScene[i], (void*)0x4FF, 0x14, 4);
                break;
            case 4:
                STATROW(i, j, "%3d", s8, blue_count);
                D_800ED4B0[D_800FC600_ResultsScene[i]].unk_24 = 0x14;
                LoadStringIntoWindow((s16)D_800FC600_ResultsScene[i], (void*)0x4FF, 0x14, 4);
                break;
            case 5:
                STATROW(i, j, "%3d", s8, red_count);
                D_800ED4B0[D_800FC600_ResultsScene[i]].unk_24 = 0x14;
                LoadStringIntoWindow((s16)D_800FC600_ResultsScene[i], (void*)0x4FF, 0x14, 4);
                break;
            case 6:
                STATROW(i, j, "%3d", s8, happening_count);
                D_800ED4B0[D_800FC600_ResultsScene[i]].unk_24 = 0x14;
                LoadStringIntoWindow((s16)D_800FC600_ResultsScene[i], (void*)0x4FF, 0x14, 4);
                break;
            case 7:
                STATROW(i, j, "%3d", s8, minigame_count);
                D_800ED4B0[D_800FC600_ResultsScene[i]].unk_24 = 0x14;
                LoadStringIntoWindow((s16)D_800FC600_ResultsScene[i], (void*)0x4FF, 0x14, 4);
                break;
            case 8:
                STATROW(i, j, "%3d", s8, chance_count);
                D_800ED4B0[D_800FC600_ResultsScene[i]].unk_24 = 0x14;
                LoadStringIntoWindow((s16)D_800FC600_ResultsScene[i], (void*)0x4FF, 0x14, 4);
                break;
            case 9:
                STATROW(i, j, "%3d", s8, mushroom_count);
                D_800ED4B0[D_800FC600_ResultsScene[i]].unk_24 = 0x14;
                LoadStringIntoWindow((s16)D_800FC600_ResultsScene[i], (void*)0x4FF, 0x14, 4);
                break;
            case 10:
                STATROW(i, j, "%3d", s8, bowser_count);
                D_800ED4B0[D_800FC600_ResultsScene[i]].unk_24 = 0x14;
                LoadStringIntoWindow((s16)D_800FC600_ResultsScene[i], (void*)0x4FF, 0x14, 4);
                break;
        }
    }
}
void func_800F7324_ResultsScene(void) {
    void* file;
    s32 i;

    D_800FC578_ResultsScene = func_80064EF4(5, 5);
    func_80066DC4((s16)D_800FC578_ResultsScene, 0, 0, 0);
    for (i = 0; i < 4; i++) {
        file = DataRead(D_800FC1EC_ResultsScene[GwPlayer[GwCommon.boardWork[i]].character]);
        D_800FC580_ResultsScene[i] = func_800678A4(file);
        DataClose(file);
        func_80067208((s16)D_800FC578_ResultsScene, i + 1, (s16)D_800FC580_ResultsScene[i], 0);
        func_800672B0((s16)D_800FC578_ResultsScene, i + 1, 1);
        func_80067384((s16)D_800FC578_ResultsScene, i + 1, 0x10);
        func_800674BC((s16)D_800FC578_ResultsScene, i + 1, 0x1000);
        func_80066DC4((s16)D_800FC578_ResultsScene, i + 1, D_800FC128_ResultsScene[i][0], D_800FC128_ResultsScene[i][1]);
    }
    D_800FC590_ResultsScene = func_80064EF4(5, 5);
    func_80066DC4((s16)D_800FC590_ResultsScene, 0, 0, 0);
    for (i = 0; i < 4; i++) {
        file = DataRead(D_800FC1D4_ResultsScene[GwPlayer[GwCommon.boardWork[i]].character]);
        D_800FC598_ResultsScene[i] = func_800678A4(file);
        DataClose(file);
        func_80067208((s16)D_800FC590_ResultsScene, i + 1, (s16)D_800FC598_ResultsScene[i], 0);
        func_800672B0((s16)D_800FC590_ResultsScene, i + 1, 1);
        func_80067384((s16)D_800FC590_ResultsScene, i + 1, 0x10);
        func_800674BC((s16)D_800FC590_ResultsScene, i + 1, 0x1000);
        func_80066DC4((s16)D_800FC590_ResultsScene, i + 1, D_800FC118_ResultsScene[i][0], D_800FC118_ResultsScene[i][1]);
    }
    D_800FC5A8_ResultsScene = func_80064EF4(1, 5);
    func_80066DC4((s16)D_800FC5A8_ResultsScene, 0, 0, 0);
    file = DataRead(D_800FC1B4_ResultsScene[GwSystem.curBoardIndex]);
    D_800FC5AC_ResultsScene = func_800678A4(file);
    DataClose(file);
    func_80067208((s16)D_800FC5A8_ResultsScene, 0, (s16)D_800FC5AC_ResultsScene, 0);
    func_800672B0((s16)D_800FC5A8_ResultsScene, 0, 1);
    func_80067384((s16)D_800FC5A8_ResultsScene, 0, 0x10);
    func_800674BC((s16)D_800FC5A8_ResultsScene, 0, 0x1000);
    func_80066DC4((s16)D_800FC5A8_ResultsScene, 0, D_800FC138_ResultsScene[0], D_800FC138_ResultsScene[1]);
    D_800FC5B8_ResultsScene = func_80064EF4(1, 5);
    func_80066DC4((s16)D_800FC5B8_ResultsScene, 0, 0, 0);
    file = DataRead(D_800FC1A8_ResultsScene[GwSystem.playType]);
    D_800FC5BC_ResultsScene = func_800678A4(file);
    DataClose(file);
    func_80067208((s16)D_800FC5B8_ResultsScene, 0, (s16)D_800FC5BC_ResultsScene, 0);
    func_800672B0((s16)D_800FC5B8_ResultsScene, 0, 1);
    func_80067384((s16)D_800FC5B8_ResultsScene, 0, 0x10);
    func_800674BC((s16)D_800FC5B8_ResultsScene, 0, 0x1000);
    func_80066DC4((s16)D_800FC5B8_ResultsScene, 0, D_800FC13C_ResultsScene[0], D_800FC13C_ResultsScene[1]);
    func_800674F4((s16)D_800FC5B8_ResultsScene, 0, 0xFF, 0xFF, 0xFF);
    D_800FC5B0_ResultsScene = func_80064EF4(1, 5);
    func_80066DC4((s16)D_800FC5B0_ResultsScene, 0, 0, 0);
    file = DataRead(0xA018C);
    D_800FC5B4_ResultsScene = func_800678A4(file);
    DataClose(file);
    func_80067208((s16)D_800FC5B0_ResultsScene, 0, (s16)D_800FC5B4_ResultsScene, 0);
    func_800672B0((s16)D_800FC5B0_ResultsScene, 0, 1);
    func_80067384((s16)D_800FC5B0_ResultsScene, 0, 0x8000);
    func_800674BC((s16)D_800FC5B0_ResultsScene, 0, 0x1000);
    func_80066DC4((s16)D_800FC5B0_ResultsScene, 0, D_800FC0E8_ResultsScene[D_800FC0E4_ResultsScene][0],
                  D_800FC0E8_ResultsScene[D_800FC0E4_ResultsScene][1]);
    func_800674F4((s16)D_800FC5B0_ResultsScene, 0, 0x40, 0x40, 0x80);
    D_800FC790_ResultsScene = omAddObj(0x1000, 0, 0, -1, func_800F678C_ResultsScene);
    D_800FC790_ResultsScene->trans.x = 0.0f;
    D_800FC790_ResultsScene->trans.y = 0.0f;
    D_800FC0D8_ResultsScene[0] = D_800FC0D8_ResultsScene[1] = D_800FC790_ResultsScene->trans.y;
    D_800FC5C0_ResultsScene = func_80064EF4(3, 5);
    func_80066DC4((s16)D_800FC5C0_ResultsScene, 0, 0, 0);
    for (i = 0; i < 2; i++) {
        file = DataRead(D_800FC1A0_ResultsScene[i]);
        D_800FC5C4_ResultsScene[i] = func_800678A4(file);
        DataClose(file);
        func_80067208((s16)D_800FC5C0_ResultsScene, i + 1, (s16)D_800FC5C4_ResultsScene[i], 0);
        func_800672B0((s16)D_800FC5C0_ResultsScene, i + 1, 1);
        func_80067384((s16)D_800FC5C0_ResultsScene, i + 1, 0x10);
        func_800674BC((s16)D_800FC5C0_ResultsScene, i + 1, 0x1000);
        func_80066DC4((s16)D_800FC5C0_ResultsScene, i + 1, D_800FC140_ResultsScene[i][0], D_800FC140_ResultsScene[i][1]);
        func_800674F4((s16)D_800FC5C0_ResultsScene, (s16)(i + 1), 0xFF, 0, 0);
    }
    D_800FC5CC_ResultsScene = func_80064EF4(0xC, 5);
    func_80066DC4((s16)D_800FC5CC_ResultsScene, 0, 0, 0);
    for (i = 0; i < 11; i++) {
        file = DataRead(D_800FC174_ResultsScene[i]);
        D_800FC5D0_ResultsScene[i] = func_800678A4(file);
        DataClose(file);
        func_80067208((s16)D_800FC5CC_ResultsScene, i + 1, (s16)D_800FC5D0_ResultsScene[i], 0);
        func_800672B0((s16)D_800FC5CC_ResultsScene, i + 1, 1);
        func_80067384((s16)D_800FC5CC_ResultsScene, i + 1, 0xF);
        func_800674BC((s16)D_800FC5CC_ResultsScene, i + 1, 0x9000);
        func_80066DC4((s16)D_800FC5CC_ResultsScene, i + 1, D_800FC0F8_ResultsScene[0][0], D_800FC0F8_ResultsScene[0][1]);
        func_80067354((s16)D_800FC5CC_ResultsScene, i + 1, D_800FC148_ResultsScene[i], D_800FC148_ResultsScene[i]);
        func_80067284((s16)D_800FC5CC_ResultsScene, i + 1, 0.0f);
    }
    for (i = 0; i < 11; i++) {
        D_800FC600_ResultsScene[i] = CreateTextWindow(D_800FC108_ResultsScene[0][0], D_800FC108_ResultsScene[0][1], 4, 6);
        func_8006E0A4((s16)D_800FC600_ResultsScene[i], 0x1000);
        func_8006E070((s16)D_800FC600_ResultsScene[i], 0);
        func_8006E154((s16)D_800FC600_ResultsScene[i], 0);
        D_800ED4B0[D_800FC600_ResultsScene[i]].unk_08 = 0x12;
        func_80071598((s16)D_800FC600_ResultsScene[i]);
    }
    func_800F6C70_ResultsScene();
    D_800FC5FC_ResultsScene = func_80048224(NULL);
    func_80071DE0(D_800FC5FC_ResultsScene->unk8);
    func_80072108(D_800FC5FC_ResultsScene->unk8, 0x1000);
    func_800F6988_ResultsScene();
}
void func_800F7C28_ResultsScene(void) {
    s32 i;

    HuPrcSleep(2);
    while (1) {
        for (i = 0; i < 4; i++) {
            if (GwPlayer[i].flags & 1) {
                continue;
            }
            if (ContDStkTrg[GwPlayer[i].port] & 0x1000) {
                break;
            }
            if (D_800F2CF0[GwPlayer[i].port] & 0x200) {
                if (D_800FC0E4_ResultsScene != 0) {
                    D_800FC0E4_ResultsScene--;
                    func_800F6988_ResultsScene();
                } else if (D_800FC0E0_ResultsScene != 0) {
                    D_800FC0E0_ResultsScene--;
                    func_800F6988_ResultsScene();
                }
                i = 4;
                break;
            }
            if (D_800F2CF0[GwPlayer[i].port] & 0x100) {
                if (D_800FC0E4_ResultsScene < 3) {
                    D_800FC0E4_ResultsScene++;
                    func_800F6988_ResultsScene();
                } else if (D_800FC0E0_ResultsScene < 7) {
                    D_800FC0E0_ResultsScene++;
                    func_800F6988_ResultsScene();
                }
                i = 4;
                break;
            }
        }
        if (i != 4) {
            break;
        }
        HuPrcVSleep();
    }
}
const char D_800FC34C_ResultsScene[] = "RESULTS";

const char D_800FC354_ResultsScene[] = "%d";


void func_800F7D94_ResultsScene(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_80067704(D_800FC598_ResultsScene[i]);
        func_80067704(D_800FC580_ResultsScene[i]);
    }

    func_80064D38((s16)D_800FC578_ResultsScene);
    func_80064D38((s16)D_800FC590_ResultsScene);
    func_80067704((s16)D_800FC5AC_ResultsScene);
    func_80064D38((s16)D_800FC5A8_ResultsScene);
    func_80067704((s16)D_800FC5BC_ResultsScene);
    func_80064D38((s16)D_800FC5B8_ResultsScene);
    func_80067704((s16)D_800FC5B4_ResultsScene);
    func_80064D38((s16)D_800FC5B0_ResultsScene);
    omDelObj(D_800FC790_ResultsScene);
    
    for (i = 0; i < 2; i++) {
        func_80067704(D_800FC5C4_ResultsScene[i]);
    }

    func_80064D38((s16)D_800FC5C0_ResultsScene);

    for (i = 0; i < 11; i++) {
        func_80067704(D_800FC5D0_ResultsScene[i]);
    }

    func_80064D38((s16)D_800FC5CC_ResultsScene);

    for (i = 0; i < 11; i++) {
        func_80070D90(D_800FC600_ResultsScene[i]);
    }
    
    func_8004847C(D_800FC5FC_ResultsScene);
}

void func_800F7F1C_ResultsScene(void) {
    char buf[16];
    void* file;
    s32 i;
    s32 attr;
    s32 v;

    func_80066DC4(D_800FC798_ResultsScene.unk_14[GMesFontMesCreate(&D_800FC798_ResultsScene, D_800FC230_ResultsScene, 1, -1, -1)],
                  0, D_800FC234_ResultsScene[0], D_800FC234_ResultsScene[1]);
    D_800FC800_ResultsScene = func_80064EF4(5, 5);
    func_80066DC4((s16)D_800FC800_ResultsScene, 0, 0, 0);
    for (i = 0; i < 4; i++) {
        file = DataRead((i + 0x125) | 0xA0000);
        D_800FC808_ResultsScene[i] = func_800678A4(file);
        DataClose(file);
        func_80067208((s16)D_800FC800_ResultsScene, i + 1, (s16)D_800FC808_ResultsScene[i], 0);
        func_800672B0((s16)D_800FC800_ResultsScene, i + 1, 1);
        func_80067384((s16)D_800FC800_ResultsScene, i + 1, 0x10);
        func_800674BC((s16)D_800FC800_ResultsScene, i + 1, 0x1000);
        if (_CheckFlag(0x2C) == 0) {
            func_80066DC4((s16)D_800FC800_ResultsScene, i + 1, D_800FC238_ResultsScene[i][0], D_800FC238_ResultsScene[i][1]);
        } else {
            func_80066DC4((s16)D_800FC800_ResultsScene, i + 1, D_800FC248_ResultsScene[i][0], D_800FC248_ResultsScene[i][1]);
        }
    }
    for (i = 0; i < 4; i++) {
        attr = 0x10;
        if ((i == 0) | (i == 3)) {
            if (i == 0) {
                D_800FC818_ResultsScene[0] = func_800429CC(GwPlayer[GwCommon.boardWork[0]].character, 0);
            } else {
                D_800FC818_ResultsScene[i] = func_800429CC(GwPlayer[GwCommon.boardWork[i]].character, 1);
            }
            D_800FC818_ResultsScene[i]->flags |= 2;
            if (_CheckFlag(0x2C) == 0) {
                D_800FC818_ResultsScene[i]->x = D_800FC258_ResultsScene[i][0];
                D_800FC818_ResultsScene[i]->y = D_800FC258_ResultsScene[i][1];
            } else {
                D_800FC818_ResultsScene[i]->x = D_800FC268_ResultsScene[i][0];
                D_800FC818_ResultsScene[i]->y = D_800FC268_ResultsScene[i][1];
            }
            D_800FC818_ResultsScene[i]->scale = 0.5f;
            attr = 2;
            D_800FC818_ResultsScene[i]->attr = attr;
        } else {
            if (_CheckFlag(0x2C) == 0) {
                D_800FC838_ResultsScene[i] = func_8004F628(D_800FC2E8_ResultsScene[GwPlayer[GwCommon.boardWork[i]].character], 0x10,
                                                           D_800FC258_ResultsScene[i][0], D_800FC258_ResultsScene[i][1]);
            } else {
                D_800FC838_ResultsScene[i] = func_8004F628(D_800FC2E8_ResultsScene[GwPlayer[GwCommon.boardWork[i]].character], attr,
                                                           D_800FC268_ResultsScene[i][0], D_800FC268_ResultsScene[i][1]);
            }
        }
        if (_CheckFlag(0x2C) == 0) {
            D_800FC828_ResultsScene[i] = func_8004F628(0xA0163, attr + 1, D_800FC258_ResultsScene[i][0], D_800FC258_ResultsScene[i][1]);
        } else {
            D_800FC828_ResultsScene[i] = func_8004F628(0xA0163, attr + 1, D_800FC268_ResultsScene[i][0], D_800FC268_ResultsScene[i][1]);
        }
        func_8004F7C0(D_800FC828_ResultsScene[i], 0.5f, 0.5f);
    }
    if (_CheckFlag(0x2C) == 0) {
        D_800FC848_ResultsScene = func_80064EF4(5, 5);
        func_80066DC4((s16)D_800FC848_ResultsScene, 0, 0, 0);
        file = DataRead(0xA0014);
        D_800FC84C_ResultsScene = func_800678A4(file);
        DataClose(file);
        for (i = 0; i < 4; i++) {
            func_80067208((s16)D_800FC848_ResultsScene, i + 1, (s16)D_800FC84C_ResultsScene, 0);
            func_800672B0((s16)D_800FC848_ResultsScene, i + 1, 1);
            func_80067384((s16)D_800FC848_ResultsScene, i + 1, 0x10);
            func_800674BC((s16)D_800FC848_ResultsScene, i + 1, 0x1000);
            func_80066DC4((s16)D_800FC848_ResultsScene, i + 1, D_800FC278_ResultsScene[i][0], D_800FC278_ResultsScene[i][1]);
            func_80067284((s16)D_800FC848_ResultsScene, i + 1, 0.0f);
        }
    }
    D_800FC850_ResultsScene = func_80064EF4(5, 5);
    func_80066DC4((s16)D_800FC850_ResultsScene, 0, 0, 0);
    file = DataRead(0xA0013);
    D_800FC854_ResultsScene = func_800678A4(file);
    DataClose(file);
    for (i = 0; i < 4; i++) {
        func_80067208((s16)D_800FC850_ResultsScene, i + 1, (s16)D_800FC854_ResultsScene, 0);
        func_800672B0((s16)D_800FC850_ResultsScene, i + 1, 1);
        func_80067384((s16)D_800FC850_ResultsScene, i + 1, 0x10);
        func_800674BC((s16)D_800FC850_ResultsScene, i + 1, 0x1000);
        if (_CheckFlag(0x2C) == 0) {
            func_80066DC4((s16)D_800FC850_ResultsScene, i + 1, D_800FC288_ResultsScene[i][0], D_800FC288_ResultsScene[i][1]);
        } else {
            func_80066DC4((s16)D_800FC850_ResultsScene, i + 1, D_800FC298_ResultsScene[i][0], D_800FC298_ResultsScene[i][1]);
        }
        func_80067284((s16)D_800FC850_ResultsScene, i + 1, 0.0f);
    }
    if (_CheckFlag(0x2C) == 0) {
        for (i = 0; i < 8; i++) {
            if (i < 4) {
                v = GwPlayer[GwCommon.boardWork[i]].stars + GwCommon.boardWork[GwCommon.boardWork[i] + 10];
                if (v >= 10) {
                    sprintf(buf, D_800FC354_ResultsScene, v);
                } else {
                    sprintf(buf, "X%d", GwPlayer[GwCommon.boardWork[i]].stars + GwCommon.boardWork[GwCommon.boardWork[i] + 10]);
                }
            } else {
                v = GwPlayer[GwCommon.boardWork[i - 4]].coins;
                if (v >= 100) {
                    sprintf(buf, D_800FC354_ResultsScene, v);
                } else {
                    sprintf(buf, "X%2d", GwPlayer[GwCommon.boardWork[i - 4]].coins);
                }
            }
            func_80066DC4(D_800FC858_ResultsScene[i].unk_14[GMesFontMesCreate(&D_800FC858_ResultsScene[i], buf, 0, 0, -1)], 0,
                          D_800FC2A8_ResultsScene[i][0], D_800FC2A8_ResultsScene[i][1]);
        }
    } else {
        for (i = 4; i < 8; i++) {
            v = GwPlayer[GwCommon.boardWork[i - 4]].coins;
            if (v >= 100) {
                sprintf(buf, D_800FC354_ResultsScene, v);
            } else {
                sprintf(buf, "X%2d", GwPlayer[GwCommon.boardWork[i - 4]].coins);
            }
            func_80066DC4(D_800FC858_ResultsScene[i].unk_14[GMesFontMesCreate(&D_800FC858_ResultsScene[i], buf, 0, 0, -1)], 0,
                          D_800FC2C8_ResultsScene[i][0], D_800FC2C8_ResultsScene[i][1]);
        }
    }
    if (_CheckFlag(0x2C) == 0) {
        D_800FCB98_ResultsScene = CreateTextWindow(0x46, 0xD0, 0x10, 1);
        func_8006E154((s16)D_800FCB98_ResultsScene, 0);
        func_8006E070((s16)D_800FCB98_ResultsScene, 0);
        LoadStringIntoWindow((s16)D_800FCB98_ResultsScene, (void*)0x4F2, -1, -1);
    } else {
        D_800FCB98_ResultsScene = CreateTextWindow(0x82, 0xD0, 7, 1);
        func_8006E154((s16)D_800FCB98_ResultsScene, 0);
        func_8006E070((s16)D_800FCB98_ResultsScene, 0);
        LoadStringIntoWindow((s16)D_800FCB98_ResultsScene, (void*)0x4F3, -1, -1);
    }
    func_80071598((s16)D_800FCB98_ResultsScene);
}
void func_800F8990_ResultsScene(void) {
    f32 s;
    s32 i;

    HuPrcSleep(10);
    for (s = 0.5f; s <= 1.0f; s += 0.05f) {
        D_800FC818_ResultsScene[0]->scale = s;
        func_8004F7C0(D_800FC828_ResultsScene[0], s, s);
        HuPrcVSleep();
    }
    D_800FC818_ResultsScene[0]->scale = 1.0f;
    i = 0;
    func_8004F7C0(D_800FC828_ResultsScene[0], 1.0f, 1.0f);
    D_800FC818_ResultsScene[0]->flags &= ~2;
    while (1) {
        if (!(D_800FC818_ResultsScene[0]->flags & 1)) {
            break;
        }
        if (++i == 13) {
            func_80060468(0x46E, GwPlayer[GwCommon.boardWork[0]].character);
        }
        HuPrcVSleep();
    }
    HuPrcSleep(30);
    for (s = 1.0f; s >= 0.5f; s -= 0.05f) {
        D_800FC818_ResultsScene[0]->scale = s;
        func_8004F7C0(D_800FC828_ResultsScene[0], s, s);
        HuPrcVSleep();
    }
    D_800FC818_ResultsScene[0]->scale = 0.5f;
    func_8004F7C0(D_800FC828_ResultsScene[0], 0.5f, 0.5f);
    HuPrcSleep(10);
    for (s = 0.5f; s <= 1.0f; s += 0.05f) {
        D_800FC818_ResultsScene[3]->scale = s;
        func_8004F7C0(D_800FC828_ResultsScene[3], s, s);
        HuPrcVSleep();
    }
    D_800FC818_ResultsScene[3]->scale = 1.0f;
    i = 0;
    func_8004F7C0(D_800FC828_ResultsScene[3], 1.0f, 1.0f);
    D_800FC818_ResultsScene[3]->flags &= ~2;
    while (1) {
        if (!(D_800FC818_ResultsScene[3]->flags & 1)) {
            break;
        }
        if (++i == 13) {
            func_80060468(0x44A, GwPlayer[GwCommon.boardWork[3]].character);
        }
        HuPrcVSleep();
    }
    HuPrcSleep(30);
    for (s = 1.0f; s >= 0.5f; s -= 0.05f) {
        D_800FC818_ResultsScene[3]->scale = s;
        func_8004F7C0(D_800FC828_ResultsScene[3], s, s);
        HuPrcVSleep();
    }
    D_800FC818_ResultsScene[3]->scale = 0.5f;
    func_8004F7C0(D_800FC828_ResultsScene[3], 0.5f, 0.5f);
}
void func_800F8CFC_ResultsScene(void) {
    s32 i;

    func_80077044(&D_800FC798_ResultsScene);
    for (i = 0; i < 4; i++) {
        func_80067704((s16)D_800FC808_ResultsScene[i]);
        if ((i == 0) | (i == 3)) {
            func_80042B10(D_800FC818_ResultsScene[i]);
        } else {
            func_8004F584(D_800FC838_ResultsScene[i]);
        }
        func_8004F584(D_800FC828_ResultsScene[i]);
    }
    func_80064D38((s16)D_800FC800_ResultsScene);
    if (_CheckFlag(0x2C) == 0) {
        func_80067704((s16)D_800FC84C_ResultsScene);
        func_80064D38((s16)D_800FC848_ResultsScene);
    }
    func_80067704((s16)D_800FC854_ResultsScene);
    func_80064D38((s16)D_800FC850_ResultsScene);
    if (_CheckFlag(0x2C) == 0) {
        for (i = 0; i < 8; i++) {
            func_80077044(&D_800FC858_ResultsScene[i]);
        }
    } else {
        for (i = 4; i < 8; i++) {
            func_80077044(&D_800FC858_ResultsScene[i]);
        }
    }
    func_80070D90((s16)D_800FCB98_ResultsScene);
}
void func_800F8EB8_ResultsScene(void) {
    s32 i;
    s32 xoff = 320;

    if (_CheckFlag(0x2C) == 0) {
        func_80066DC4(D_800FC798_ResultsScene.unk_14[0], 0, D_800FC234_ResultsScene[0] + xoff, D_800FC234_ResultsScene[1]);
        func_80066DC4((s16)D_800FC800_ResultsScene, 0, xoff, 0);
        for (i = 0; i < 4; i++) {
            if ((i == 0) | (i == 3)) {
                D_800FC818_ResultsScene[i]->x = D_800FC258_ResultsScene[i][0] + xoff;
                D_800FC818_ResultsScene[i]->y = D_800FC258_ResultsScene[i][1];
            } else {
                func_8004F754_unproto(D_800FC838_ResultsScene[i], D_800FC258_ResultsScene[i][0] + xoff, D_800FC258_ResultsScene[i][1]);
            }
            func_8004F754_unproto(D_800FC828_ResultsScene[i], D_800FC258_ResultsScene[i][0] + xoff, D_800FC258_ResultsScene[i][1]);
        }
        func_80066DC4((s16)D_800FC848_ResultsScene, 0, xoff, 0);
        func_80066DC4((s16)D_800FC850_ResultsScene, 0, xoff, 0);
        for (i = 0; i < 8; i++) {
            func_80066DC4(D_800FC858_ResultsScene[i].unk_14[0], 0, D_800FC2A8_ResultsScene[i][0] + xoff, D_800FC2A8_ResultsScene[i][1]);
        }
    } else {
        func_80066DC4(D_800FC798_ResultsScene.unk_14[0], 0, D_800FC234_ResultsScene[0] + xoff, D_800FC234_ResultsScene[1]);
        func_80066DC4((s16)D_800FC800_ResultsScene, 0, xoff, 0);
        for (i = 0; i < 4; i++) {
            if ((i == 0) | (i == 3)) {
                D_800FC818_ResultsScene[i]->x = D_800FC268_ResultsScene[i][0] + xoff;
                D_800FC818_ResultsScene[i]->y = D_800FC268_ResultsScene[i][1];
            } else {
                func_8004F754_unproto(D_800FC838_ResultsScene[i], D_800FC268_ResultsScene[i][0] + xoff, D_800FC268_ResultsScene[i][1]);
            }
            func_8004F754_unproto(D_800FC828_ResultsScene[i], D_800FC268_ResultsScene[i][0] + xoff, D_800FC268_ResultsScene[i][1]);
        }
        func_80066DC4((s16)D_800FC850_ResultsScene, 0, xoff, 0);
        for (i = 4; i < 8; i++) {
            func_80066DC4(D_800FC858_ResultsScene[i].unk_14[0], 0, D_800FC2C8_ResultsScene[i][0] + xoff, D_800FC2C8_ResultsScene[i][1]);
        }
    }
    func_80070D90((s16)D_800FCB98_ResultsScene);
}
void func_800F9250_ResultsScene(void) {
    s32 i;
    s32 xoff = 0;

    if (_CheckFlag(0x2C) == 0) {
        func_80066DC4(D_800FC798_ResultsScene.unk_14[0], 0, D_800FC234_ResultsScene[0] + xoff, D_800FC234_ResultsScene[1]);
        func_80066DC4((s16)D_800FC800_ResultsScene, 0, xoff, 0);
        for (i = 0; i < 4; i++) {
            if ((i == 0) | (i == 3)) {
                D_800FC818_ResultsScene[i]->x = D_800FC258_ResultsScene[i][0] + xoff;
                D_800FC818_ResultsScene[i]->y = D_800FC258_ResultsScene[i][1];
            } else {
                func_8004F754_unproto(D_800FC838_ResultsScene[i], D_800FC258_ResultsScene[i][0] + xoff, D_800FC258_ResultsScene[i][1]);
            }
            func_8004F754_unproto(D_800FC828_ResultsScene[i], D_800FC258_ResultsScene[i][0] + xoff, D_800FC258_ResultsScene[i][1]);
        }
        func_80066DC4((s16)D_800FC848_ResultsScene, 0, xoff, 0);
        func_80066DC4((s16)D_800FC850_ResultsScene, 0, xoff, 0);
        for (i = 0; i < 8; i++) {
            func_80066DC4(D_800FC858_ResultsScene[i].unk_14[0], 0, D_800FC2A8_ResultsScene[i][0] + xoff, D_800FC2A8_ResultsScene[i][1]);
        }
    } else {
        func_80066DC4(D_800FC798_ResultsScene.unk_14[0], 0, D_800FC234_ResultsScene[0] + xoff, D_800FC234_ResultsScene[1]);
        func_80066DC4((s16)D_800FC800_ResultsScene, 0, xoff, 0);
        for (i = 0; i < 4; i++) {
            if ((i == 0) | (i == 3)) {
                D_800FC818_ResultsScene[i]->x = D_800FC268_ResultsScene[i][0] + xoff;
                D_800FC818_ResultsScene[i]->y = D_800FC268_ResultsScene[i][1];
            } else {
                func_8004F754_unproto(D_800FC838_ResultsScene[i], D_800FC268_ResultsScene[i][0] + xoff, D_800FC268_ResultsScene[i][1]);
            }
            func_8004F754_unproto(D_800FC828_ResultsScene[i], D_800FC268_ResultsScene[i][0] + xoff, D_800FC268_ResultsScene[i][1]);
        }
        func_80066DC4((s16)D_800FC850_ResultsScene, 0, xoff, 0);
        for (i = 4; i < 8; i++) {
            func_80066DC4(D_800FC858_ResultsScene[i].unk_14[0], 0, D_800FC2C8_ResultsScene[i][0] + xoff, D_800FC2C8_ResultsScene[i][1]);
        }
    }
    D_800FCB98_ResultsScene = CreateTextWindow(0x46, 0xD0, 0x10, 1);
    func_8006E154((s16)D_800FCB98_ResultsScene, 0);
    func_8006E070((s16)D_800FCB98_ResultsScene, 0);
    LoadStringIntoWindow((s16)D_800FCB98_ResultsScene, (void*)0x4F2, -1, -1);
}
const char D_800FC364_ResultsScene[] = "%5d";

void func_800F95F8_ResultsScene(void) {
    u8 sp10[5];
    s32 i;
    s32 var_s2;

    while (1) {
        var_s2 = 0;
        sprintf((char*)&sp10, D_800FC364_ResultsScene, GwCommon.coinNum);
        for (i = 0; i < 5; i++) {
            func_800672B0((s16)D_800FC458_ResultsScene[0], i, 1);
            if (var_s2 == 0 && (sp10[i] == ' ') & (i != 4)) {
                func_800672DC((s16)D_800FC458_ResultsScene[0], i, 0, 0);
                func_800674BC((s16)D_800FC458_ResultsScene[0], i, 0x8000);
            } else {
                var_s2 = 1;
                func_800672DC((s16)D_800FC458_ResultsScene[0], i, sp10[i] - 0x30, 0);
                func_80067480((s16)D_800FC458_ResultsScene[0], i, 0x8000);
            }
        }
        HuPrcVSleep();
    }
}
void func_800F972C_ResultsScene(void) {
    u8 sp10[5];
    s32 i;
    s32 var_s2;

    while (1) {
        var_s2 = 0;
        sprintf((char*)&sp10, D_800FC364_ResultsScene, GwCommon.starNum);
        for (i = 0; i < 5; i++) {
            func_800672B0((s16)D_800FC458_ResultsScene[1], i, 1);
             if (var_s2 == 0 && (sp10[i] == ' ') & (i != 4)) {
                func_800672DC((s16)D_800FC458_ResultsScene[1], i, 0, 0);
                func_800674BC((s16)D_800FC458_ResultsScene[1], i, 0x8000);             
             } else {
                var_s2 = 1;
                func_800672DC((s16)D_800FC458_ResultsScene[1], i, sp10[i] - 0x30, 0);
                func_80067480((s16)D_800FC458_ResultsScene[1], i, 0x8000);
             }
        }
        HuPrcVSleep();        
    }
}

void func_800F9860_ResultsScene(omObjData* obj) {
    D_800FC3A8_ResultsScene[obj->work[0]]->unk_18.x = sinf(obj->rot.y * 0.017453292519943295);
    D_800FC3A8_ResultsScene[obj->work[0]]->unk_18.z = cosf(obj->rot.y * 0.017453292519943295);
    if ((obj->rot.y += obj->trans.y) >= 360.0f) {
        obj->rot.y -= 360.0f;
    }
    if (obj->trans.z < 0.0f) {
        D_800FC3A8_ResultsScene[obj->work[0]]->coords.y += 10.0f;
        if (D_800FC3A8_ResultsScene[obj->work[0]]->coords.y >= 35.0f) {
            if (obj->work[2] == 1) {
                obj->trans.x -= 2.0f;
            } else if (obj->work[2] == 2) {
                obj->trans.x += 2.0f;
            }
        }
    } else {
        D_800FC3A8_ResultsScene[obj->work[0]]->coords.y -= 10.0f;
        if (obj->trans.x > D_800FC06C_ResultsScene[0].x) {
            if ((obj->trans.x -= 2.0f) < D_800FC06C_ResultsScene[0].x) {
                obj->trans.x = D_800FC06C_ResultsScene[0].x;
            }
        } else if (obj->trans.x < D_800FC06C_ResultsScene[0].x) {
            if ((obj->trans.x += 2.0f) > D_800FC06C_ResultsScene[0].x) {
                obj->trans.x = D_800FC06C_ResultsScene[0].x;
            }
        }
    }
    D_800FC3A8_ResultsScene[obj->work[0]]->coords.x = obj->trans.x;
    if (D_800FC3A8_ResultsScene[obj->work[0]]->coords.y == 100.0f && obj->trans.z <= 0.0f) {
        GwCommon.coinNum += (s32)obj->trans.z;
        if (D_800FC050_ResultsScene >= 3) {
            PlaySound(0x57);
            D_800FC050_ResultsScene -= 3;
        } else {
            D_800FC050_ResultsScene += 2;
        }
    }
    if (D_800FC3A8_ResultsScene[obj->work[0]]->coords.y <= 0.0f || D_800FC3A8_ResultsScene[obj->work[0]]->coords.y >= 200.0f) {
        if (GwCommon.boardItem != 3 && obj->trans.z > 0.0f) {
            GwCommon.coinNum += (s32)obj->trans.z;
            if ((s32)GwCommon.coinNum > 99999) {
                GwCommon.coinNum = 99999;
            }
            if (D_800FC050_ResultsScene >= 3) {
                PlaySound(0xFC);
                D_800FC050_ResultsScene -= 3;
            } else {
                D_800FC050_ResultsScene += 2;
            }
        }
        D_800FC3A8_ResultsScene[obj->work[0]]->coords.y = D_800FC06C_ResultsScene[0].y;
        omDelObj(obj);
    }
}
void func_800F9C74_ResultsScene(omObjData* obj) {
    omObjData* coin;
    s32 p;
    s32 n;
    s32 j;

    p = obj->work[0];
    n = 0;
    if (obj->scale.x >= 1.0f) {
        while (1) {
            if (p >= 4) {
                if (D_800FC440_ResultsScene > 0) {
                    D_800FC440_ResultsScene--;
                    n++;
                }
                if (D_800FC440_ResultsScene == 0) {
                    break;
                }
            } else {
                if (!(GwPlayer[GwCommon.boardWork[p]].flags & 1)) {
                    if (D_800FC430_ResultsScene[GwCommon.boardWork[p]] > 0) {
                        D_800FC430_ResultsScene[GwCommon.boardWork[p]]--;
                        GwPlayer[GwCommon.boardWork[p]].coins--;
                        n++;
                    }
                }
                p = (p + 1) & 3;
                for (j = 0; j < 4; j++) {
                    if (!(GwPlayer[GwCommon.boardWork[j]].flags & 1) && D_800FC430_ResultsScene[GwCommon.boardWork[j]] > 0) {
                        break;
                    }
                }
                if (j == 4) {
                    break;
                }
            }
            if (obj->scale.x < n + 1.0f) {
                obj->scale.x -= n;
                break;
            }
        }
    }
    obj->scale.x += obj->trans.x;
    obj->work[0] = p;
    if (n != 0) {
        p = 1; /* retail reuses the player counter as the one-coin-per-frame limit */
        while ((n != 0) & (p != 0)) {
            coin = omAddObj(0x1000, 0, 0, -1, func_800F9860_ResultsScene);
            coin->rot.y = rand8() & 0xFF;
            coin->trans.y = 20.0f;
            coin->work[2] = (rand8() & 0xFF) % 3;
            coin->work[0] = (u8)D_800FC300_ResultsScene;
            coin->trans.x = D_800FC06C_ResultsScene[coin->work[2]].x;
            coin->trans.z = n;
            coin->scale.z = 3.0f;
            if (obj->work[0] == 5) {
                D_800FC3A8_ResultsScene[D_800FC300_ResultsScene]->coords.y = 0.0f;
                coin->trans.z = -coin->trans.z;
                coin->trans.x = D_800FC06C_ResultsScene[0].x;
            }
            D_800FC300_ResultsScene = (D_800FC300_ResultsScene + 1) % 20;
            n--;
            p--;
        }
    } else {
        D_800FC050_ResultsScene += 2;
    }
    if (obj->work[0] >= 4) {
        if (D_800FC440_ResultsScene == 0) {
            omDelObj(obj);
        }
    } else {
        for (j = 0; j < 4; j++) {
            if (!(GwPlayer[GwCommon.boardWork[j]].flags & 1) && D_800FC430_ResultsScene[GwCommon.boardWork[j]] > 0) {
                break;
            }
        }
        if (j == 4) {
            omDelObj(obj);
        }
    }
}
void func_800FA08C_ResultsScene(omObjData* obj) {
    D_800FC3A0_ResultsScene->xScale = sinf(obj->scale.x * 0.017453292519943295) / 3.0f + 1.0f;
    D_800FC3A0_ResultsScene->zScale = sinf(obj->scale.z * 0.017453292519943295) / 3.0f + 1.0f;
    if (obj->scale.z < 900.0f && obj->scale.x >= 45.0f) {
        obj->scale.z += 15.0f;
    }
    if (obj->scale.x < 900.0f) {
        obj->scale.x += 15.0f;
    }
    if (obj->scale.x >= 900.0f && obj->scale.z >= 900.0f) {
        omDelObj(obj);
    }
}
void func_800FA200_ResultsScene(omObjData* obj) {
    D_800FC3A0_ResultsScene->xScale = sinf(obj->scale.x * 0.017453292519943295) / 3.0f + 1.0f;
    D_800FC3A0_ResultsScene->zScale = sinf(obj->scale.z * 0.017453292519943295) / 3.0f + 1.0f;
    obj->scale.z += obj->scale.y + 20.0f;
    obj->scale.x += obj->scale.y + 20.0f;
    if (obj->work[0] == 0) {
        if (obj->scale.y <= 20.0f) {
            obj->scale.y += 1.0f;
        } else {
            obj->work[1]++;
        }
        if (obj->work[1] == 10) {
            obj->work[0] = 1;
        }
    } else if (obj->scale.y > 0.0f) {
        obj->scale.y -= 2.0f;
    }
    if (obj->scale.x >= 1980.0f && obj->scale.z >= 1980.0f) {
        omDelObj(obj);
    }
}
void func_800FA3A4_ResultsScene(omObjData* obj) {
    D_800FC3F8_ResultsScene[obj->work[0]]->coords.x = sinf(obj->rot.y * 0.017453292519943295) * obj->rot.x + D_800FC054_ResultsScene.x;
    D_800FC3F8_ResultsScene[obj->work[0]]->coords.y = obj->trans.y;
    D_800FC3F8_ResultsScene[obj->work[0]]->coords.z = cosf(obj->rot.y * 0.017453292519943295) * obj->rot.x + D_800FC054_ResultsScene.z;
    D_800FC3F8_ResultsScene[obj->work[0]]->unk_18.x = sinf(2.0f * -obj->rot.y * 0.017453292519943295);
    D_800FC3F8_ResultsScene[obj->work[0]]->unk_18.z = cosf(2.0f * -obj->rot.y * 0.017453292519943295);
    obj->work[1]++;
    obj->rot.y += 10.0f;
    if ((obj->rot.x -= 1.25f) < 0.0f) {
        obj->rot.x = 0.0f;
    }
    if ((obj->trans.y -= 1.25f) <= 45.0f) {
        if (GwCommon.boardItem != 3) {
            if (++GwCommon.starNum > 100) {
                GwCommon.starNum = 100;
            }
            PlaySound(0x64);
        }
        D_800FC3F8_ResultsScene[obj->work[0]]->coords.y = D_800FC06C_ResultsScene[0].y;
        omDelObj(obj);
    }
}
void func_800FA5E0_ResultsScene(s32 arg0) {
    if (arg0 == 1) {
        arg0 = 30;
    } else if (arg0 == 2) {
        arg0 = 60;
    } else {
        arg0 = 90;
    }
    HuPrcSleep(arg0);
}
void func_800FA61C_ResultsScene(void) {
    s32 win[4];
    char buf[24];
    omObjData* obj;
    s32 i;
    s32 j;
    s32 k;
    s32 sel;

    func_8004E3E0(0, &D_800FC054_ResultsScene, 50, D_800FC3A0_ResultsScene);
    HuPrcSleep(60);
    D_800FC444_ResultsScene = D_800FC440_ResultsScene;
    if ((s32)(D_800FC440_ResultsScene + GwCommon.coinNum) > 99999) {
        D_800FC444_ResultsScene = 99999 - GwCommon.coinNum;
    }
    if (D_800FC440_ResultsScene != 0) {
        obj = omAddObj(0x1000, 0, 0, -1, func_800F9C74_ResultsScene);
        obj->trans.x = D_800FC440_ResultsScene / 60.0f;
        obj->work[0] = 0;
        obj->scale.x = 1.0f;
        func_800FA5E0_ResultsScene(D_800FC440_ResultsScene);
    }
    if (GwCommon.boardItem == 1 || GwCommon.boardItem == 2 || GwCommon.boardItem == 3) {
        if (GwCommon.boardItem == 1) {
            D_800FC440_ResultsScene /= 10;
            if (D_800FC440_ResultsScene != 0) {
                win[0] = CreateTextWindow(0x28, 0x50, 0xB, 2);
                func_8006DE20((s16)win[0], 1.0f, 1.0f);
                sprintf(buf, D_800FC354_ResultsScene, D_800FC440_ResultsScene);
                func_8006DA5C((s16)win[0], buf, 0);
                LoadStringIntoWindow((s16)win[0], (void*)0x267, -1, -1);
                func_8006E070((s16)win[0], 0);
                while (func_8006FCC0((s16)win[0]) != 0) {
                    HuPrcVSleep();
                }
                func_80070D90((s16)win[0]);
                PlaySound(0x84);
                obj = omAddObj(0x1000, 0, 0, -1, func_800FA08C_ResultsScene);
                obj->scale.x = 0.0f;
                obj->scale.z = 0.0f;
                HuPrcSleep(90);
                obj = omAddObj(0x1000, 0, 0, -1, func_800F9C74_ResultsScene);
                obj->trans.x = D_800FC440_ResultsScene / 60.0f;
                obj->work[0] = 4;
                obj->scale.x = 1.0f;
                func_800FA5E0_ResultsScene(D_800FC440_ResultsScene);
            }
        } else if (GwCommon.boardItem == 2 && D_800FC440_ResultsScene != 0) {
            win[0] = CreateTextWindow(0x28, 0x50, 0xA, 4);
            func_8006DE20((s16)win[0], 1.0f, 1.0f);
            LoadStringIntoWindow((s16)win[0], (void*)0x263, -1, -1);
            func_8006E070((s16)win[0], 0);
            while (func_8006FCC0((s16)win[0]) != 0) {
                HuPrcVSleep();
            }
            func_80070D90((s16)win[0]);
            for (i = 0; i < 3; i++) {
                win[i] = CreateTextWindow(0x51, 0x78, 3, 1);
                func_8006DE20((s16)win[i], 1.0f, 1.0f);
                LoadStringIntoWindow((s16)win[i], (void*)(s32)D_800FC304_ResultsScene[i], -1, -1);
                func_8006E070((s16)win[i], 0);
                func_80071598((s16)win[i]);
                while (func_8006FCC0((s16)win[i]) != 0) {
                    HuPrcVSleep();
                }
            }
            j = 0;
            sel = (u8)(rand8() % 3);
            do {
                sel++;
                sel %= 3;
                if (!(j & 1)) {
                    PlaySound(0x3D);
                }
                for (i = 0; i < 3; i++) {
                    if (sel == i) {
                        func_8007166C((s16)win[sel]);
                    } else {
                        func_80071598((s16)win[i]);
                    }
                }
                for (i = 0; i < 4; i++) {
                    if (GwPlayer[i].flags & 1) {
                        continue;
                    }
                    if (ContBtnTrg[GwPlayer[i].port] & 0xC000) {
                        break;
                    }
                }
                if (i != 4) {
                    break;
                }
                HuPrcVSleep();
            } while (++j < 150);
            if (sel == 0) {
                PlaySound(0x100);
            }
            if (sel == 2) {
                PlaySound(0xFF);
            }
            HuPrcSleep(30);
            switch (sel) {
                case 0:
                    win[3] = CreateTextWindow(0x32, 0x3C, 9, 3);
                    func_8006DE20((s16)win[3], 1.0f, 1.0f);
                    sprintf(buf, D_800FC354_ResultsScene, D_800FC444_ResultsScene / 2);
                    func_8006DA5C((s16)win[3], buf, 0);
                    LoadStringIntoWindow((s16)win[3], (void*)0x266, -1, -1);
                    break;
                case 1:
                    win[3] = CreateTextWindow(0x32, 0x3C, 0xA, 2);
                    func_8006DE20((s16)win[3], 1.0f, 1.0f);
                    LoadStringIntoWindow((s16)win[3], (void*)0x265, -1, -1);
                    break;
                case 2:
                    win[3] = CreateTextWindow(0x37, 0x3C, 8, 3);
                    func_8006DE20((s16)win[3], 1.0f, 1.0f);
                    sprintf(buf, D_800FC354_ResultsScene, D_800FC440_ResultsScene);
                    func_8006DA5C((s16)win[3], buf, 0);
                    LoadStringIntoWindow((s16)win[3], (void*)0x264, -1, -1);
                    break;
            }
            func_8006E070((s16)win[3], 0);
            while (func_8006FCC0((s16)win[3]) != 0) {
                HuPrcVSleep();
            }
            for (j = 0; j < 4; j++) {
                func_80070D90((s16)win[j]);
            }
            if (sel == 0) {
                D_800FC440_ResultsScene = D_800FC444_ResultsScene / 2;
                if (D_800FC440_ResultsScene != 0) {
                    PlaySound(0x87);
                    obj = omAddObj(0x1000, 0, 0, -1, func_800FA200_ResultsScene);
                    obj->scale.x = 0.0f;
                    obj->scale.y = 0.0f;
                    obj->scale.z = 0.0f;
                    obj->work[1] = 0;
                    obj->work[0] = 0;
                    HuPrcSleep(90);
                    obj = omAddObj(0x1000, 0, 0, -1, func_800F9C74_ResultsScene);
                    obj->trans.x = D_800FC440_ResultsScene / 60.0f;
                    obj->work[0] = 5;
                    obj->scale.x = 1.0f;
                    func_800FA5E0_ResultsScene(D_800FC440_ResultsScene);
                }
            } else if (sel == 2) {
                PlaySound(0x84);
                obj = omAddObj(0x1000, 0, 0, -1, func_800FA200_ResultsScene);
                obj->scale.x = 0.0f;
                obj->scale.y = 0.0f;
                obj->scale.z = 0.0f;
                obj->work[1] = 0;
                obj->work[0] = 0;
                HuPrcSleep(90);
                obj = omAddObj(0x1000, 0, 0, -1, func_800F9C74_ResultsScene);
                obj->trans.x = D_800FC440_ResultsScene / 60.0f;
                obj->work[0] = 4;
                obj->scale.x = 1.0f;
                func_800FA5E0_ResultsScene(D_800FC440_ResultsScene);
            }
        }
    }
    HuPrcSleep(20);
    for (j = 0; j < 7; j++) {
        D_800FC478_ResultsScene[j] = func_80042728(D_800FC3F8_ResultsScene[j], 2);
    }
    for (j = 0; j < D_800FC448_ResultsScene; j++) {
        obj = omAddObj(0x1000, 0, 0, -1, func_800FA3A4_ResultsScene);
        obj->rot.x = 100.0f;
        obj->rot.y = 0.0f;
        obj->trans.y = 160.0f;
        obj->work[0] = j % 7;
        obj->work[1] = 0;
        for (k = 0; k < 4; k++) {
            if (GwPlayer[GwCommon.boardWork[k]].flags & 1) {
                continue;
            }
            if (GwPlayer[GwCommon.boardWork[k]].stars != 0) {
                GwPlayer[GwCommon.boardWork[k]].stars--;
                break;
            }
        }
        HuPrcSleep(20);
        if (j + 1 == D_800FC448_ResultsScene) {
            HuPrcSleep(90);
        }
    }
    for (j = 0; j < 7; j++) {
        func_800427D4(D_800FC478_ResultsScene[j]);
    }
    if (GwCommon.boardItem == 3) {
        func_8004EE14(0, &D_800FC090_ResultsScene, 10, D_800FC3A0_ResultsScene);
        HuPrcSleep(10);
        func_8004E3E0(0, &D_800FC090_ResultsScene, 20, D_800FC3A0_ResultsScene);
        HuPrcSleep(20);
    }
    D_800F5144 = 1;
    while (1) {
        HuPrcVSleep();
    }
}
void func_800FB054_ResultsScene(void) {
    s32 i;
    s32 xoff;

    SetFadeInTypeAndTime(0, 16);
    HuPrcSleep(26);
    func_800F8990_ResultsScene();
    func_8007166C((s16)D_800FCB98_ResultsScene);
    for (i = 0; i < 4; i++) {
        D_800FC498_ResultsScene[i] = GwPlayer[i].stars;
        GwPlayer[i].stars += GwCommon.boardWork[i + 10];
    }
    HuPrcSleep(2);
    for (i = 0; i < 4; i++) {
        if (!(GwPlayer[i].flags & 1)) {
            break;
        }
    }
    if (i == 4) {
        HuPrcSleep(30);
    } else {
        while (1) {
            for (i = 0; i < 4; i++) {
                if (GwPlayer[i].flags & 1) {
                    continue;
                }
                if (ContBtnTrg[GwPlayer[i].port] & 0x8000) {
                    break;
                }
                if (_CheckFlag(0x2C) == 0 && (ContBtnTrg[GwPlayer[i].port] & 0x1000)) {
                    i = 4;
                    func_800F8EB8_ResultsScene();
                    func_800F7324_ResultsScene();
                    func_800F7C28_ResultsScene();
                    func_800F7D94_ResultsScene();
                    func_800F9250_ResultsScene();
                    HuPrcSleep(5);
                    break;
                }
            }
            if (i != 4) {
                break;
            }
            HuPrcVSleep();
        }
    }
    func_80071598((s16)D_800FCB98_ResultsScene);
    for (xoff = 0; xoff >= -320; xoff -= 16) {
        if (_CheckFlag(0x2C) == 0) {
            func_80066DC4(D_800FC798_ResultsScene.unk_14[0], 0, D_800FC234_ResultsScene[0] + xoff, D_800FC234_ResultsScene[1]);
            func_80066DC4((s16)D_800FC800_ResultsScene, 0, xoff, 0);
            for (i = 0; i < 4; i++) {
                if ((i == 0) | (i == 3)) {
                    D_800FC818_ResultsScene[i]->x = D_800FC258_ResultsScene[i][0] + xoff;
                    D_800FC818_ResultsScene[i]->y = D_800FC258_ResultsScene[i][1];
                } else {
                    func_8004F754_unproto(D_800FC838_ResultsScene[i], D_800FC258_ResultsScene[i][0] + xoff, D_800FC258_ResultsScene[i][1]);
                }
                func_8004F754_unproto(D_800FC828_ResultsScene[i], D_800FC258_ResultsScene[i][0] + xoff, D_800FC258_ResultsScene[i][1]);
            }
            func_80066DC4((s16)D_800FC848_ResultsScene, 0, xoff, 0);
            func_80066DC4((s16)D_800FC850_ResultsScene, 0, xoff, 0);
            for (i = 0; i < 8; i++) {
                func_80066DC4(D_800FC858_ResultsScene[i].unk_14[0], 0, D_800FC2A8_ResultsScene[i][0] + xoff, D_800FC2A8_ResultsScene[i][1]);
            }
        } else {
            func_80066DC4(D_800FC798_ResultsScene.unk_14[0], 0, D_800FC234_ResultsScene[0] + xoff, D_800FC234_ResultsScene[1]);
            func_80066DC4((s16)D_800FC800_ResultsScene, 0, xoff, 0);
            for (i = 0; i < 4; i++) {
                if ((i == 0) | (i == 3)) {
                    D_800FC818_ResultsScene[i]->x = D_800FC268_ResultsScene[i][0] + xoff;
                    D_800FC818_ResultsScene[i]->y = D_800FC268_ResultsScene[i][1];
                } else {
                    func_8004F754_unproto(D_800FC838_ResultsScene[i], D_800FC268_ResultsScene[i][0] + xoff, D_800FC268_ResultsScene[i][1]);
                }
                func_8004F754_unproto(D_800FC828_ResultsScene[i], D_800FC268_ResultsScene[i][0] + xoff, D_800FC268_ResultsScene[i][1]);
            }
            func_80066DC4((s16)D_800FC850_ResultsScene, 0, xoff, 0);
            for (i = 4; i < 8; i++) {
                func_80066DC4(D_800FC858_ResultsScene[i].unk_14[0], 0, D_800FC2C8_ResultsScene[i][0] + xoff, D_800FC2C8_ResultsScene[i][1]);
            }
        }
        HuPrcVSleep();
    }
    func_800F8CFC_ResultsScene();
    func_800FB8C8_ResultsScene();
    func_800544E4();
    for (i = 0; i < 4; i++) {
        func_80054834(GwCommon.boardWork[i], i + 0x1C);
        func_80054744_unproto(GwCommon.boardWork[i], i);
    }
    for (xoff = 0; xoff >= -320; xoff -= 16) {
        func_8004F754_unproto(D_800FC44C_ResultsScene[0], xoff + 370, 170);
        func_8004F754_unproto(D_800FC44C_ResultsScene[1], xoff + 370, 204);
        func_80066DC4(D_800FC4A8_ResultsScene[0].unk_14[0], 0, xoff + 400, 170);
        func_80066DC4(D_800FC4A8_ResultsScene[1].unk_14[0], 0, xoff + 400, 204);
        func_80066DC4((s16)D_800FC458_ResultsScene[0], 0, xoff + 420, 170);
        func_80066DC4((s16)D_800FC458_ResultsScene[1], 0, xoff + 420, 204);
        HuPrcVSleep();
        if (xoff == 0) {
            for (i = 0; i < 4; i++) {
                func_80054868(D_800FC0C8_ResultsScene[i]);
            }
        }
    }
    func_800FA61C_ResultsScene();
}
void func_800FB71C_ResultsScene(omObjData* obj) {
    s32 i;

    if (func_80072718() == 0) {
        for (i = 0; i < 4; i++) {
            GwPlayer[i].stars = D_800FC498_ResultsScene[i];
        }
        func_800596DC_unproto(-1, (u16)GetSumOfPlayerStars());
        for (i = 0; i < 4; i++) {
            func_800596DC_unproto(-1, (u16)GwCommon.boardWork[i + 10]);
        }
        func_80059578(-1);
        if ((GwSystem.curBoardIndex == 7 && _CheckFlag(0x2A) == 0) || _CheckFlag(0x2C) == 0) {
            GwCommon.unk_46 = GwPlayer[GwCommon.boardWork[0]].character;
        }
        ClearBoardFeatureFlag(0x2C);
        func_8005B280();
        func_800FC028_ResultsScene();
        func_800FBDF0_ResultsScene();
        func_8004F5F0();
        func_80054654();
        func_80070ED4();
        func_800532F4();
        MBModelClose();
        omOvlReturnEx(1);
    }
}
void func_800FB87C_ResultsScene(omObjData* arg0) {
    if (D_800F5144 != 0) {
        func_800726AC(0, 0x4B);
        func_800601D4(0x96);
        arg0->func_ptr = &func_800FB71C_ResultsScene;
    }
}

void func_800FB8C8_ResultsScene(void) {
    s32 models[4] = { 0x5B, 0x59, 0x5A, 0x0B };
    void* file;
    s32 i;
    s32 j;

    D_800FC418_ResultsScene[0] = omAddPrcObj(func_800F95F8_ResultsScene, 0x1001, 0, 0);
    D_800FC418_ResultsScene[1] = omAddPrcObj(func_800F972C_ResultsScene, 0x1001, 0, 0);
    D_800FC44C_ResultsScene[0] = func_8004F628(0xA0013, 10, 370, 170);
    D_800FC44C_ResultsScene[1] = func_8004F628(0xA0014, 10, 370, 204);
    func_8004F860(D_800FC44C_ResultsScene[0], 0);
    func_8004F860(D_800FC44C_ResultsScene[1], 0);
    func_80066DC4(D_800FC4A8_ResultsScene[0].unk_14[GMesFontMesCreate(&D_800FC4A8_ResultsScene[0], "X", 0, -1, -1)], 0, 400, 170);
    func_80066DC4(D_800FC4A8_ResultsScene[1].unk_14[GMesFontMesCreate(&D_800FC4A8_ResultsScene[1], "X", 0, -1, -1)], 0, 400, 204);
    file = DataRead(0x7C);
    D_800FC470_ResultsScene[0] = func_800678A4(file);
    DataClose(file);
    D_800FC458_ResultsScene[0] = func_80064EF4(5, 5);
    for (i = 0; i < 5; i++) {
        func_80067208((s16)D_800FC458_ResultsScene[0], i, (s16)D_800FC470_ResultsScene[0], 0);
        func_800672B0((s16)D_800FC458_ResultsScene[0], i, 1);
        func_80067384((s16)D_800FC458_ResultsScene[0], i, 10);
        func_800674BC((s16)D_800FC458_ResultsScene[0], i, 0x1000);
        if (i == 0) {
            func_80066DC4((s16)D_800FC458_ResultsScene[0], 0, 420, 170);
        } else {
            func_80066DC4((s16)D_800FC458_ResultsScene[0], i, i * 16, 0);
        }
    }
    D_800FC458_ResultsScene[1] = func_80064EF4(5, 5);
    for (i = 0; i < 5; i++) {
        func_80067208((s16)D_800FC458_ResultsScene[1], i, (s16)D_800FC470_ResultsScene[0], 0);
        func_800672B0((s16)D_800FC458_ResultsScene[1], i, 1);
        func_80067384((s16)D_800FC458_ResultsScene[1], i, 10);
        func_800674BC((s16)D_800FC458_ResultsScene[1], i, 0x1000);
        func_800672DC((s16)D_800FC458_ResultsScene[1], i, 0, 0);
        func_80067284((s16)D_800FC458_ResultsScene[1], i, 0.0f);
        if (i == 0) {
            func_80066DC4((s16)D_800FC458_ResultsScene[1], 0, 420, 204);
        } else {
            func_80066DC4((s16)D_800FC458_ResultsScene[1], i, i * 16, 0);
        }
    }
    D_800FC3A0_ResultsScene = MBModelCreate(models[GwCommon.boardItem], NULL);
    D_800FC3A0_ResultsScene->coords.x = D_800FC060_ResultsScene.x;
    D_800FC3A0_ResultsScene->coords.y = D_800FC060_ResultsScene.y;
    D_800FC3A0_ResultsScene->coords.z = D_800FC060_ResultsScene.z;
    D_800FC3A0_ResultsScene->unk_3C->unk_24 = 5.0f;
    func_8004CCD0(&D_800FC3A0_ResultsScene->coords, &D_800C3110->pos, &D_800FC3A0_ResultsScene->unk_18);
    for (j = 0; j < 20; j++) {
        if (j == 0) {
            D_800FC3A8_ResultsScene[0] = MBModelCreate(0x3D, NULL);
        } else {
            D_800FC3A8_ResultsScene[j] = MBModelParamCreate(D_800FC3A8_ResultsScene[0]);
        }
        D_800FC3A8_ResultsScene[j]->coords.x = D_800FC06C_ResultsScene[0].x;
        D_800FC3A8_ResultsScene[j]->coords.y = D_800FC06C_ResultsScene[0].y;
        D_800FC3A8_ResultsScene[j]->coords.z = D_800FC06C_ResultsScene[0].z;
        D_800FC3A8_ResultsScene[j]->xScale = D_800FC3A8_ResultsScene[j]->yScale = D_800FC3A8_ResultsScene[j]->zScale = 0.5f;
    }
    for (j = 0; j < 7; j++) {
        if (j == 0) {
            D_800FC3F8_ResultsScene[0] = MBModelCreate(0x40, NULL);
        } else {
            D_800FC3F8_ResultsScene[j] = MBModelParamCreate(D_800FC3F8_ResultsScene[0]);
        }
        D_800FC3F8_ResultsScene[j]->coords.x = D_800FC06C_ResultsScene[0].x;
        D_800FC3F8_ResultsScene[j]->coords.y = D_800FC06C_ResultsScene[0].y;
        D_800FC3F8_ResultsScene[j]->coords.z = D_800FC06C_ResultsScene[0].z;
        D_800FC3F8_ResultsScene[j]->xScale = D_800FC3F8_ResultsScene[j]->yScale = D_800FC3F8_ResultsScene[j]->zScale = 0.2f;
    }
}
void func_800FBDF0_ResultsScene(void) {
    s32 i;

    MBModelKill(D_800FC3A0_ResultsScene);

    for (i = 0; i < ARRAY_COUNT(D_800FC3A8_ResultsScene); i++) {
        MBModelKill(D_800FC3A8_ResultsScene[i]);
    }
    for (i = 0; i < ARRAY_COUNT(D_800FC3F8_ResultsScene); i++) {
        MBModelKill(D_800FC3F8_ResultsScene[i]);
    }
    for (i = 0; i < ARRAY_COUNT(D_800FC418_ResultsScene); i++) {
        EndProcess(D_800FC418_ResultsScene[i]);
    }
    for (i = 0; i < ARRAY_COUNT(D_800FC458_ResultsScene); i++) {
        func_80064D38(D_800FC458_ResultsScene[i]);
    }
    for (i = 0; i < ARRAY_COUNT(D_800FC470_ResultsScene); i++) {
        func_80067704(D_800FC470_ResultsScene[i]);
    }

    func_80077044(D_800FC4A8_ResultsScene);
    func_80077044(&D_800FC4A8_ResultsScene[1]);
}

void func_800FBF10_ResultsScene(void) {
    func_800178A0(2);
    func_80017660(0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80017660(1, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(1, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    LoadBackgroundData(FE2310_ROM_START);
    LoadBackgroundIndex(D_800FC09C_ResultsScene[GwSystem.curBoardIndex]);
    func_8004B7F8(0x80);
}

void func_800FC028_ResultsScene(void) {
    func_8004A140();
    func_80049F0C();
}
