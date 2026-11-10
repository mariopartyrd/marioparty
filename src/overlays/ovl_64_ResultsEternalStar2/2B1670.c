#include "ResultsEternalStar2.h"

void func_80071598(s16);
void func_8007166C(s16);

/* One row of the stats table: each player's value printed into its digits buffer. */
#define STATROW(i, j, fmt, cast, field)                                                         \
    for (j = 0; j < 4; j++) {                                                                   \
        sprintf((char*)D_800FC6A0_ResultsEternalStar2[i][j], fmt, (cast)GwPlayer[GwCommon.boardWork[j]].field); \
        func_8006DA5C((s16)D_800FC670_ResultsEternalStar2[i], D_800FC6A0_ResultsEternalStar2[i][j], j);       \
    }

/* ovl_64 is ovl_40 ResultsScene's twin (same data, rodata and code; built from a copy of 259EB0.c).
   Differences from ovl_40: the sound and voice ids, func_8006DA1C(win, 32, 32) after each message
   window is created in func_800FA61C, and func_800FB76C's story branch (on board 7 with flag 0x2A
   clear it sets 0x2A and stores -1 in GwCommon.unk_46).

   The end-of-game results: the stats table (stars, coins, minigame coins, max coins, space counts),
   scrolled with the stick; then each player's coins and stars fall into the bank, the board's item
   (if any) changes the coin total, and the stars go to the star pile. */

/* .data */
s32 D_800FC0C0_ResultsEternalStar2 = 3; /* falling-coin sound pacing */
Vec3f D_800FC0C4_ResultsEternalStar2 = { -60.0f, -30.0f, 0.0f }; /* star pile centre */
Vec3f D_800FC0D0_ResultsEternalStar2 = { -60.0f, 200.0f, 0.0f }; /* the board item model */
/* coin start points; [0].y is also the height a finished coin or star returns to */
Vec3f D_800FC0DC_ResultsEternalStar2[3] = { { -60.0f, 200.0f, 0.0f }, { -90.0f, 200.0f, 0.0f }, { -30.0f, 200.0f, 0.0f } };
Vec3f D_800FC100_ResultsEternalStar2 = { -500.0f, -30.0f, 0.0f };
s32 D_800FC10C_ResultsEternalStar2[11] = { 6, 17, 26, 38, 46, 55, 67, 76, 76, 102, 76 }; /* background per board */
s32 D_800FC138_ResultsEternalStar2[4] = { 14, 15, 16, 17 };
f32 D_800FC148_ResultsEternalStar2[2] = { 0.0f, 0.0f };
s32 D_800FC150_ResultsEternalStar2 = 0; /* first stats row shown (0..7) */
s32 D_800FC154_ResultsEternalStar2 = 0; /* cursor row on screen (0..3) */
s16 D_800FC158_ResultsEternalStar2[4][2] = { { 136, 105 }, { 179, 105 }, { 222, 105 }, { 267, 105 } };
s16 D_800FC168_ResultsEternalStar2[4][2] = { { 136, 64 }, { 179, 64 }, { 222, 64 }, { 267, 64 } };
s16 D_800FC178_ResultsEternalStar2[4][2] = { { 106, 70 }, { 150, 70 }, { 194, 70 }, { 238, 70 } };
s16 D_800FC188_ResultsEternalStar2[4][2] = { { 76, 80 }, { 76, 100 }, { 76, 120 }, { 76, 140 } };
s16 D_800FC198_ResultsEternalStar2[4][2] = { { 36, 80 }, { 36, 100 }, { 36, 120 }, { 36, 140 } };
s16 D_800FC1A8_ResultsEternalStar2[2] = { 107, 38 };
s16 D_800FC1AC_ResultsEternalStar2[2] = { 240, 35 };
s16 D_800FC1B0_ResultsEternalStar2[2][2] = { { 120, 157 }, { 280, 157 } }; /* scroll arrows */
f32 D_800FC1B8_ResultsEternalStar2[11] = { 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f };
s32 D_800FC1E4_ResultsEternalStar2[11] = { 0xA0014, 0xA0013, 0xA018D, 0xA018E, 0xA0190, 0xA018F,
                                    0xA0191, 0xA0192, 0xA0193, 0xA0194, 0xA0195 };
s32 D_800FC210_ResultsEternalStar2[2] = { 0xA0112, 0xA0113 };
s32 D_800FC218_ResultsEternalStar2[3] = { 0xA0189, 0xA018A, 0xA018B };
s32 D_800FC224_ResultsEternalStar2[8] = { 0xA0196, 0xA0197, 0xA0198, 0xA0199, 0xA019A, 0xA019B, 0xA019C, 0xA019D };
s32 D_800FC244_ResultsEternalStar2[6] = { 0x6E, 0x6F, 0x70, 0x71, 0x72, 0x73 };
s32 D_800FC25C_ResultsEternalStar2[6] = { 0xA010C, 0xA010D, 0xA010E, 0xA010F, 0xA0110, 0xA0111 };
s32 D_800FC274_ResultsEternalStar2[11] = { 0x4F4, 0x4F5, 0x4F6, 0x4F7, 0x4F8, 0x4F9, 0x4FA, 0x4FB, 0x4FC, 0x4FD, 0x4FE };
extern const char D_800FC3BC_ResultsEternalStar2[];
char* D_800FC2A0_ResultsEternalStar2 = (char*)D_800FC3BC_ResultsEternalStar2; /* "RESULTS" */
s16 D_800FC2A4_ResultsEternalStar2[2] = { 160, 34 };
s16 D_800FC2A8_ResultsEternalStar2[4][2] = { { 60, 70 }, { 60, 110 }, { 60, 150 }, { 60, 190 } };
s16 D_800FC2B8_ResultsEternalStar2[4][2] = { { 80, 70 }, { 80, 110 }, { 80, 150 }, { 80, 190 } };
s16 D_800FC2C8_ResultsEternalStar2[4][2] = { { 110, 70 }, { 110, 110 }, { 110, 150 }, { 110, 190 } };
s16 D_800FC2D8_ResultsEternalStar2[4][2] = { { 150, 70 }, { 150, 110 }, { 150, 150 }, { 150, 190 } };
s16 D_800FC2E8_ResultsEternalStar2[4][2] = { { 151, 70 }, { 151, 110 }, { 151, 150 }, { 151, 190 } };
s16 D_800FC2F8_ResultsEternalStar2[4][2] = { { 226, 70 }, { 226, 110 }, { 226, 150 }, { 226, 190 } };
s16 D_800FC308_ResultsEternalStar2[4][2] = { { 206, 70 }, { 206, 110 }, { 206, 150 }, { 206, 190 } };
s16 D_800FC318_ResultsEternalStar2[8][2] = { { 174, 74 }, { 174, 114 }, { 174, 154 }, { 174, 194 },
                                      { 250, 74 }, { 250, 114 }, { 250, 154 }, { 250, 194 } };
s16 D_800FC338_ResultsEternalStar2[8][2] = { { 174, 74 }, { 174, 114 }, { 174, 154 }, { 174, 194 },
                                      { 230, 74 }, { 230, 114 }, { 230, 154 }, { 230, 194 } };
s32 D_800FC358_ResultsEternalStar2[6] = { 0xA0183, 0xA0184, 0xA0185, 0xA0186, 0xA0187, 0xA0188 };
s32 D_800FC370_ResultsEternalStar2 = 0; /* next coin model (0..19); splat's D_800FC303 is its low byte */
s32 D_800FC374_ResultsEternalStar2[3] = { 0x260, 0x261, 0x262 }; /* the roulette's messages */

void func_800F65E0_ResultsEternalStar2(void) {
    s32 i;

    omInitObjMan(0x64, 0x50);
    D_800FC4B0_ResultsEternalStar2 = 0;
    for (i = 0; i < 4; i++) {
        D_800FC4A0_ResultsEternalStar2[GwCommon.boardWork[i]] = GwPlayer[GwCommon.boardWork[i]].coins;
        if (!(GwPlayer[GwCommon.boardWork[i]].flags & 1)) {
            D_800FC4B0_ResultsEternalStar2 += D_800FC4A0_ResultsEternalStar2[GwCommon.boardWork[i]];
        }
    }

    D_800FC4B8_ResultsEternalStar2 = 0;
    
    for (i = 0; i < 4; i++) {
        if (!(GwPlayer[GwCommon.boardWork[i]].flags & 1)) {
            D_800FC4B8_ResultsEternalStar2 += GwPlayer[GwCommon.boardWork[i]].stars + GwCommon.boardWork[GwCommon.boardWork[i] + 10];
        }    
    }

    func_800FBF78_ResultsEternalStar2();
    func_8006CEA0();
    func_800532E0();
    MBModelInit();
    func_8004F548();
    func_800F7F1C_ResultsEternalStar2();
    omAddPrcObj(func_800FB0A4_ResultsEternalStar2, 0x300, 0x2000, 0);
    omAddObj(0x1000, 0, 0, -1, &func_800FB8E4_ResultsEternalStar2);
}

void func_800F678C_ResultsEternalStar2(omObjData* arg0) {
    f32 x;

    if ((arg0->trans.x += 10.0f) >= 360.0f) {
        arg0->trans.x -= 360.0f;
    }
    func_800674F4((s16)D_800FC620_ResultsEternalStar2, 0, 0x40, 0x40,
                  sinf(arg0->trans.x * 0.017453292519943295) * 32.0f + 223.0f);
    if ((arg0->trans.y += 20.0f) >= 360.0f) {
        arg0->trans.y -= 360.0f;
    }
    D_800FC148_ResultsEternalStar2[0] += func_800AEAC0(arg0->trans.y) * 0.75f;
    func_80066DC4((s16)D_800FC630_ResultsEternalStar2, 1, D_800FC1B0_ResultsEternalStar2[0][0] + D_800FC148_ResultsEternalStar2[0],
                  D_800FC1B0_ResultsEternalStar2[0][1]);
    func_80066DC4((s16)D_800FC630_ResultsEternalStar2, 2, D_800FC1B0_ResultsEternalStar2[1][0] - D_800FC148_ResultsEternalStar2[0],
                  D_800FC1B0_ResultsEternalStar2[1][1]);
}
void func_800F6988_ResultsEternalStar2(void) {
    s32 i;

    if (D_800FC150_ResultsEternalStar2 == 0) {
        func_800674BC((s16)D_800FC630_ResultsEternalStar2, 1, 0x8000);
    } else {
        func_80067480((s16)D_800FC630_ResultsEternalStar2, 1, 0x8000);
    }
    if (D_800FC150_ResultsEternalStar2 == 7) {
        func_800674BC((s16)D_800FC630_ResultsEternalStar2, 2, 0x8000);
    } else {
        func_80067480((s16)D_800FC630_ResultsEternalStar2, 2, 0x8000);
    }
    for (i = 0; i < 11; i++) {
        func_800674BC((s16)D_800FC63C_ResultsEternalStar2, i + 1, 0x8000);
    }
    for (i = 0; i < 4; i++) {
        func_80067480((s16)D_800FC63C_ResultsEternalStar2, i + ((u16)D_800FC150_ResultsEternalStar2 + 1), 0x8000);
        func_80066DC4((s16)D_800FC63C_ResultsEternalStar2, i + ((u16)D_800FC150_ResultsEternalStar2 + 1),
                      D_800FC168_ResultsEternalStar2[i][0] / D_800FC1B8_ResultsEternalStar2[i + D_800FC150_ResultsEternalStar2],
                      D_800FC168_ResultsEternalStar2[i][1] / D_800FC1B8_ResultsEternalStar2[i + D_800FC150_ResultsEternalStar2]);
    }
    func_80066DC4((s16)D_800FC620_ResultsEternalStar2, 0, D_800FC158_ResultsEternalStar2[D_800FC154_ResultsEternalStar2][0],
                  D_800FC158_ResultsEternalStar2[D_800FC154_ResultsEternalStar2][1]);
    for (i = 0; i < 11; i++) {
        func_80071598((s16)D_800FC670_ResultsEternalStar2[i]);
    }
    for (i = 0; i < 4; i++) {
        func_8007166C((s16)D_800FC670_ResultsEternalStar2[i + D_800FC150_ResultsEternalStar2]);
        func_8006DDC8((s16)D_800FC670_ResultsEternalStar2[i + D_800FC150_ResultsEternalStar2], D_800FC178_ResultsEternalStar2[i][0],
                      D_800FC178_ResultsEternalStar2[i][1]);
    }
    func_8006EB40(D_800FC66C_ResultsEternalStar2->unk8);
    func_8006E070(D_800FC66C_ResultsEternalStar2->unk8, 0);
    LoadStringIntoWindow(D_800FC66C_ResultsEternalStar2->unk8,
                         (void*)(s32)D_800FC274_ResultsEternalStar2[D_800FC150_ResultsEternalStar2 + D_800FC154_ResultsEternalStar2], -1, -1);
}
void func_800F6C70_ResultsEternalStar2(void) {
    s32 i;
    s32 j;
    s32 k;

    for (i = 0; i < 11; i++) {
        switch (i) {
            case 0:
                STATROW(i, j, "%3d", s16, stars);
                D_800ED4B0[D_800FC670_ResultsEternalStar2[i]].unk_24 = 0x14;
                LoadStringIntoWindow((s16)D_800FC670_ResultsEternalStar2[i], (void*)0x4FF, 0x14, 4);
                break;
            case 1:
                STATROW(i, j, "%3d", s16, coins);
                D_800ED4B0[D_800FC670_ResultsEternalStar2[i]].unk_24 = 0x14;
                LoadStringIntoWindow((s16)D_800FC670_ResultsEternalStar2[i], (void*)0x4FF, 0x14, 4);
                break;
            case 2:
                for (j = 0; j < 4; j++) {
                    sprintf((char*)D_800FC6A0_ResultsEternalStar2[i][j], "%4d", GwPlayer[GwCommon.boardWork[j]].coins_total);
                    for (k = 0; k < 4; k++) {
                        if (D_800FC6A0_ResultsEternalStar2[i][j][k] == '-') {
                            D_800FC6A0_ResultsEternalStar2[i][j][k] = '=';
                        }
                    }
                    func_8006DA5C((s16)D_800FC670_ResultsEternalStar2[i], D_800FC6A0_ResultsEternalStar2[i][j], j);
                }
                D_800ED4B0[D_800FC670_ResultsEternalStar2[i]].unk_24 = 0xF;
                LoadStringIntoWindow((s16)D_800FC670_ResultsEternalStar2[i], (void*)0x4FF, 0xF, 4);
                break;
            case 3:
                STATROW(i, j, "%3d", s16, coins_max);
                D_800ED4B0[D_800FC670_ResultsEternalStar2[i]].unk_24 = 0x14;
                LoadStringIntoWindow((s16)D_800FC670_ResultsEternalStar2[i], (void*)0x4FF, 0x14, 4);
                break;
            case 4:
                STATROW(i, j, "%3d", s8, blue_count);
                D_800ED4B0[D_800FC670_ResultsEternalStar2[i]].unk_24 = 0x14;
                LoadStringIntoWindow((s16)D_800FC670_ResultsEternalStar2[i], (void*)0x4FF, 0x14, 4);
                break;
            case 5:
                STATROW(i, j, "%3d", s8, red_count);
                D_800ED4B0[D_800FC670_ResultsEternalStar2[i]].unk_24 = 0x14;
                LoadStringIntoWindow((s16)D_800FC670_ResultsEternalStar2[i], (void*)0x4FF, 0x14, 4);
                break;
            case 6:
                STATROW(i, j, "%3d", s8, happening_count);
                D_800ED4B0[D_800FC670_ResultsEternalStar2[i]].unk_24 = 0x14;
                LoadStringIntoWindow((s16)D_800FC670_ResultsEternalStar2[i], (void*)0x4FF, 0x14, 4);
                break;
            case 7:
                STATROW(i, j, "%3d", s8, minigame_count);
                D_800ED4B0[D_800FC670_ResultsEternalStar2[i]].unk_24 = 0x14;
                LoadStringIntoWindow((s16)D_800FC670_ResultsEternalStar2[i], (void*)0x4FF, 0x14, 4);
                break;
            case 8:
                STATROW(i, j, "%3d", s8, chance_count);
                D_800ED4B0[D_800FC670_ResultsEternalStar2[i]].unk_24 = 0x14;
                LoadStringIntoWindow((s16)D_800FC670_ResultsEternalStar2[i], (void*)0x4FF, 0x14, 4);
                break;
            case 9:
                STATROW(i, j, "%3d", s8, mushroom_count);
                D_800ED4B0[D_800FC670_ResultsEternalStar2[i]].unk_24 = 0x14;
                LoadStringIntoWindow((s16)D_800FC670_ResultsEternalStar2[i], (void*)0x4FF, 0x14, 4);
                break;
            case 10:
                STATROW(i, j, "%3d", s8, bowser_count);
                D_800ED4B0[D_800FC670_ResultsEternalStar2[i]].unk_24 = 0x14;
                LoadStringIntoWindow((s16)D_800FC670_ResultsEternalStar2[i], (void*)0x4FF, 0x14, 4);
                break;
        }
    }
}
void func_800F7324_ResultsEternalStar2(void) {
    void* file;
    s32 i;

    D_800FC5E8_ResultsEternalStar2 = func_80064EF4(5, 5);
    func_80066DC4((s16)D_800FC5E8_ResultsEternalStar2, 0, 0, 0);
    for (i = 0; i < 4; i++) {
        file = DataRead(D_800FC25C_ResultsEternalStar2[GwPlayer[GwCommon.boardWork[i]].character]);
        D_800FC5F0_ResultsEternalStar2[i] = func_800678A4(file);
        DataClose(file);
        func_80067208((s16)D_800FC5E8_ResultsEternalStar2, i + 1, (s16)D_800FC5F0_ResultsEternalStar2[i], 0);
        func_800672B0((s16)D_800FC5E8_ResultsEternalStar2, i + 1, 1);
        func_80067384((s16)D_800FC5E8_ResultsEternalStar2, i + 1, 0x10);
        func_800674BC((s16)D_800FC5E8_ResultsEternalStar2, i + 1, 0x1000);
        func_80066DC4((s16)D_800FC5E8_ResultsEternalStar2, i + 1, D_800FC198_ResultsEternalStar2[i][0], D_800FC198_ResultsEternalStar2[i][1]);
    }
    D_800FC600_ResultsEternalStar2 = func_80064EF4(5, 5);
    func_80066DC4((s16)D_800FC600_ResultsEternalStar2, 0, 0, 0);
    for (i = 0; i < 4; i++) {
        file = DataRead(D_800FC244_ResultsEternalStar2[GwPlayer[GwCommon.boardWork[i]].character]);
        D_800FC608_ResultsEternalStar2[i] = func_800678A4(file);
        DataClose(file);
        func_80067208((s16)D_800FC600_ResultsEternalStar2, i + 1, (s16)D_800FC608_ResultsEternalStar2[i], 0);
        func_800672B0((s16)D_800FC600_ResultsEternalStar2, i + 1, 1);
        func_80067384((s16)D_800FC600_ResultsEternalStar2, i + 1, 0x10);
        func_800674BC((s16)D_800FC600_ResultsEternalStar2, i + 1, 0x1000);
        func_80066DC4((s16)D_800FC600_ResultsEternalStar2, i + 1, D_800FC188_ResultsEternalStar2[i][0], D_800FC188_ResultsEternalStar2[i][1]);
    }
    D_800FC618_ResultsEternalStar2 = func_80064EF4(1, 5);
    func_80066DC4((s16)D_800FC618_ResultsEternalStar2, 0, 0, 0);
    file = DataRead(D_800FC224_ResultsEternalStar2[GwSystem.curBoardIndex]);
    D_800FC61C_ResultsEternalStar2 = func_800678A4(file);
    DataClose(file);
    func_80067208((s16)D_800FC618_ResultsEternalStar2, 0, (s16)D_800FC61C_ResultsEternalStar2, 0);
    func_800672B0((s16)D_800FC618_ResultsEternalStar2, 0, 1);
    func_80067384((s16)D_800FC618_ResultsEternalStar2, 0, 0x10);
    func_800674BC((s16)D_800FC618_ResultsEternalStar2, 0, 0x1000);
    func_80066DC4((s16)D_800FC618_ResultsEternalStar2, 0, D_800FC1A8_ResultsEternalStar2[0], D_800FC1A8_ResultsEternalStar2[1]);
    D_800FC628_ResultsEternalStar2 = func_80064EF4(1, 5);
    func_80066DC4((s16)D_800FC628_ResultsEternalStar2, 0, 0, 0);
    file = DataRead(D_800FC218_ResultsEternalStar2[GwSystem.playType]);
    D_800FC62C_ResultsEternalStar2 = func_800678A4(file);
    DataClose(file);
    func_80067208((s16)D_800FC628_ResultsEternalStar2, 0, (s16)D_800FC62C_ResultsEternalStar2, 0);
    func_800672B0((s16)D_800FC628_ResultsEternalStar2, 0, 1);
    func_80067384((s16)D_800FC628_ResultsEternalStar2, 0, 0x10);
    func_800674BC((s16)D_800FC628_ResultsEternalStar2, 0, 0x1000);
    func_80066DC4((s16)D_800FC628_ResultsEternalStar2, 0, D_800FC1AC_ResultsEternalStar2[0], D_800FC1AC_ResultsEternalStar2[1]);
    func_800674F4((s16)D_800FC628_ResultsEternalStar2, 0, 0xFF, 0xFF, 0xFF);
    D_800FC620_ResultsEternalStar2 = func_80064EF4(1, 5);
    func_80066DC4((s16)D_800FC620_ResultsEternalStar2, 0, 0, 0);
    file = DataRead(0xA018C);
    D_800FC624_ResultsEternalStar2 = func_800678A4(file);
    DataClose(file);
    func_80067208((s16)D_800FC620_ResultsEternalStar2, 0, (s16)D_800FC624_ResultsEternalStar2, 0);
    func_800672B0((s16)D_800FC620_ResultsEternalStar2, 0, 1);
    func_80067384((s16)D_800FC620_ResultsEternalStar2, 0, 0x8000);
    func_800674BC((s16)D_800FC620_ResultsEternalStar2, 0, 0x1000);
    func_80066DC4((s16)D_800FC620_ResultsEternalStar2, 0, D_800FC158_ResultsEternalStar2[D_800FC154_ResultsEternalStar2][0],
                  D_800FC158_ResultsEternalStar2[D_800FC154_ResultsEternalStar2][1]);
    func_800674F4((s16)D_800FC620_ResultsEternalStar2, 0, 0x40, 0x40, 0x80);
    D_800FC800_ResultsEternalStar2 = omAddObj(0x1000, 0, 0, -1, func_800F678C_ResultsEternalStar2);
    D_800FC800_ResultsEternalStar2->trans.x = 0.0f;
    D_800FC800_ResultsEternalStar2->trans.y = 0.0f;
    D_800FC148_ResultsEternalStar2[0] = D_800FC148_ResultsEternalStar2[1] = D_800FC800_ResultsEternalStar2->trans.y;
    D_800FC630_ResultsEternalStar2 = func_80064EF4(3, 5);
    func_80066DC4((s16)D_800FC630_ResultsEternalStar2, 0, 0, 0);
    for (i = 0; i < 2; i++) {
        file = DataRead(D_800FC210_ResultsEternalStar2[i]);
        D_800FC634_ResultsEternalStar2[i] = func_800678A4(file);
        DataClose(file);
        func_80067208((s16)D_800FC630_ResultsEternalStar2, i + 1, (s16)D_800FC634_ResultsEternalStar2[i], 0);
        func_800672B0((s16)D_800FC630_ResultsEternalStar2, i + 1, 1);
        func_80067384((s16)D_800FC630_ResultsEternalStar2, i + 1, 0x10);
        func_800674BC((s16)D_800FC630_ResultsEternalStar2, i + 1, 0x1000);
        func_80066DC4((s16)D_800FC630_ResultsEternalStar2, i + 1, D_800FC1B0_ResultsEternalStar2[i][0], D_800FC1B0_ResultsEternalStar2[i][1]);
        func_800674F4((s16)D_800FC630_ResultsEternalStar2, (s16)(i + 1), 0xFF, 0, 0);
    }
    D_800FC63C_ResultsEternalStar2 = func_80064EF4(0xC, 5);
    func_80066DC4((s16)D_800FC63C_ResultsEternalStar2, 0, 0, 0);
    for (i = 0; i < 11; i++) {
        file = DataRead(D_800FC1E4_ResultsEternalStar2[i]);
        D_800FC640_ResultsEternalStar2[i] = func_800678A4(file);
        DataClose(file);
        func_80067208((s16)D_800FC63C_ResultsEternalStar2, i + 1, (s16)D_800FC640_ResultsEternalStar2[i], 0);
        func_800672B0((s16)D_800FC63C_ResultsEternalStar2, i + 1, 1);
        func_80067384((s16)D_800FC63C_ResultsEternalStar2, i + 1, 0xF);
        func_800674BC((s16)D_800FC63C_ResultsEternalStar2, i + 1, 0x9000);
        func_80066DC4((s16)D_800FC63C_ResultsEternalStar2, i + 1, D_800FC168_ResultsEternalStar2[0][0], D_800FC168_ResultsEternalStar2[0][1]);
        func_80067354((s16)D_800FC63C_ResultsEternalStar2, i + 1, D_800FC1B8_ResultsEternalStar2[i], D_800FC1B8_ResultsEternalStar2[i]);
        func_80067284((s16)D_800FC63C_ResultsEternalStar2, i + 1, 0.0f);
    }
    for (i = 0; i < 11; i++) {
        D_800FC670_ResultsEternalStar2[i] = CreateTextWindow(D_800FC178_ResultsEternalStar2[0][0], D_800FC178_ResultsEternalStar2[0][1], 4, 6);
        func_8006E0A4((s16)D_800FC670_ResultsEternalStar2[i], 0x1000);
        func_8006E070((s16)D_800FC670_ResultsEternalStar2[i], 0);
        func_8006E154((s16)D_800FC670_ResultsEternalStar2[i], 0);
        D_800ED4B0[D_800FC670_ResultsEternalStar2[i]].unk_08 = 0x12;
        func_80071598((s16)D_800FC670_ResultsEternalStar2[i]);
    }
    func_800F6C70_ResultsEternalStar2();
    D_800FC66C_ResultsEternalStar2 = func_80048224(NULL);
    func_80071DE0(D_800FC66C_ResultsEternalStar2->unk8);
    func_80072108(D_800FC66C_ResultsEternalStar2->unk8, 0x1000);
    func_800F6988_ResultsEternalStar2();
}
void func_800F7C28_ResultsEternalStar2(void) {
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
                if (D_800FC154_ResultsEternalStar2 != 0) {
                    D_800FC154_ResultsEternalStar2--;
                    func_800F6988_ResultsEternalStar2();
                } else if (D_800FC150_ResultsEternalStar2 != 0) {
                    D_800FC150_ResultsEternalStar2--;
                    func_800F6988_ResultsEternalStar2();
                }
                i = 4;
                break;
            }
            if (D_800F2CF0[GwPlayer[i].port] & 0x100) {
                if (D_800FC154_ResultsEternalStar2 < 3) {
                    D_800FC154_ResultsEternalStar2++;
                    func_800F6988_ResultsEternalStar2();
                } else if (D_800FC150_ResultsEternalStar2 < 7) {
                    D_800FC150_ResultsEternalStar2++;
                    func_800F6988_ResultsEternalStar2();
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
const char D_800FC3BC_ResultsEternalStar2[] = "RESULTS";

const char D_800FC3C4_ResultsEternalStar2[] = "%d";


void func_800F7D94_ResultsEternalStar2(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_80067704(D_800FC608_ResultsEternalStar2[i]);
        func_80067704(D_800FC5F0_ResultsEternalStar2[i]);
    }

    func_80064D38((s16)D_800FC5E8_ResultsEternalStar2);
    func_80064D38((s16)D_800FC600_ResultsEternalStar2);
    func_80067704((s16)D_800FC61C_ResultsEternalStar2);
    func_80064D38((s16)D_800FC618_ResultsEternalStar2);
    func_80067704((s16)D_800FC62C_ResultsEternalStar2);
    func_80064D38((s16)D_800FC628_ResultsEternalStar2);
    func_80067704((s16)D_800FC624_ResultsEternalStar2);
    func_80064D38((s16)D_800FC620_ResultsEternalStar2);
    omDelObj(D_800FC800_ResultsEternalStar2);
    
    for (i = 0; i < 2; i++) {
        func_80067704(D_800FC634_ResultsEternalStar2[i]);
    }

    func_80064D38((s16)D_800FC630_ResultsEternalStar2);

    for (i = 0; i < 11; i++) {
        func_80067704(D_800FC640_ResultsEternalStar2[i]);
    }

    func_80064D38((s16)D_800FC63C_ResultsEternalStar2);

    for (i = 0; i < 11; i++) {
        func_80070D90(D_800FC670_ResultsEternalStar2[i]);
    }
    
    func_8004847C(D_800FC66C_ResultsEternalStar2);
}

void func_800F7F1C_ResultsEternalStar2(void) {
    char buf[16];
    void* file;
    s32 i;
    s32 attr;
    s32 v;

    func_80066DC4(D_800FC808_ResultsEternalStar2.unk_14[GMesFontMesCreate(&D_800FC808_ResultsEternalStar2, D_800FC2A0_ResultsEternalStar2, 1, -1, -1)],
                  0, D_800FC2A4_ResultsEternalStar2[0], D_800FC2A4_ResultsEternalStar2[1]);
    D_800FC870_ResultsEternalStar2 = func_80064EF4(5, 5);
    func_80066DC4((s16)D_800FC870_ResultsEternalStar2, 0, 0, 0);
    for (i = 0; i < 4; i++) {
        file = DataRead((i + 0x125) | 0xA0000);
        D_800FC878_ResultsEternalStar2[i] = func_800678A4(file);
        DataClose(file);
        func_80067208((s16)D_800FC870_ResultsEternalStar2, i + 1, (s16)D_800FC878_ResultsEternalStar2[i], 0);
        func_800672B0((s16)D_800FC870_ResultsEternalStar2, i + 1, 1);
        func_80067384((s16)D_800FC870_ResultsEternalStar2, i + 1, 0x10);
        func_800674BC((s16)D_800FC870_ResultsEternalStar2, i + 1, 0x1000);
        if (_CheckFlag(0x2C) == 0) {
            func_80066DC4((s16)D_800FC870_ResultsEternalStar2, i + 1, D_800FC2A8_ResultsEternalStar2[i][0], D_800FC2A8_ResultsEternalStar2[i][1]);
        } else {
            func_80066DC4((s16)D_800FC870_ResultsEternalStar2, i + 1, D_800FC2B8_ResultsEternalStar2[i][0], D_800FC2B8_ResultsEternalStar2[i][1]);
        }
    }
    for (i = 0; i < 4; i++) {
        attr = 0x10;
        if ((i == 0) | (i == 3)) {
            if (i == 0) {
                D_800FC888_ResultsEternalStar2[0] = func_800429CC(GwPlayer[GwCommon.boardWork[0]].character, 0);
            } else {
                D_800FC888_ResultsEternalStar2[i] = func_800429CC(GwPlayer[GwCommon.boardWork[i]].character, 1);
            }
            D_800FC888_ResultsEternalStar2[i]->flags |= 2;
            if (_CheckFlag(0x2C) == 0) {
                D_800FC888_ResultsEternalStar2[i]->x = D_800FC2C8_ResultsEternalStar2[i][0];
                D_800FC888_ResultsEternalStar2[i]->y = D_800FC2C8_ResultsEternalStar2[i][1];
            } else {
                D_800FC888_ResultsEternalStar2[i]->x = D_800FC2D8_ResultsEternalStar2[i][0];
                D_800FC888_ResultsEternalStar2[i]->y = D_800FC2D8_ResultsEternalStar2[i][1];
            }
            D_800FC888_ResultsEternalStar2[i]->scale = 0.5f;
            attr = 2;
            D_800FC888_ResultsEternalStar2[i]->attr = attr;
        } else {
            if (_CheckFlag(0x2C) == 0) {
                D_800FC8A8_ResultsEternalStar2[i] = func_8004F628(D_800FC358_ResultsEternalStar2[GwPlayer[GwCommon.boardWork[i]].character], 0x10,
                                                           D_800FC2C8_ResultsEternalStar2[i][0], D_800FC2C8_ResultsEternalStar2[i][1]);
            } else {
                D_800FC8A8_ResultsEternalStar2[i] = func_8004F628(D_800FC358_ResultsEternalStar2[GwPlayer[GwCommon.boardWork[i]].character], attr,
                                                           D_800FC2D8_ResultsEternalStar2[i][0], D_800FC2D8_ResultsEternalStar2[i][1]);
            }
        }
        if (_CheckFlag(0x2C) == 0) {
            D_800FC898_ResultsEternalStar2[i] = func_8004F628(0xA0163, attr + 1, D_800FC2C8_ResultsEternalStar2[i][0], D_800FC2C8_ResultsEternalStar2[i][1]);
        } else {
            D_800FC898_ResultsEternalStar2[i] = func_8004F628(0xA0163, attr + 1, D_800FC2D8_ResultsEternalStar2[i][0], D_800FC2D8_ResultsEternalStar2[i][1]);
        }
        func_8004F7C0(D_800FC898_ResultsEternalStar2[i], 0.5f, 0.5f);
    }
    if (_CheckFlag(0x2C) == 0) {
        D_800FC8B8_ResultsEternalStar2 = func_80064EF4(5, 5);
        func_80066DC4((s16)D_800FC8B8_ResultsEternalStar2, 0, 0, 0);
        file = DataRead(0xA0014);
        D_800FC8BC_ResultsEternalStar2 = func_800678A4(file);
        DataClose(file);
        for (i = 0; i < 4; i++) {
            func_80067208((s16)D_800FC8B8_ResultsEternalStar2, i + 1, (s16)D_800FC8BC_ResultsEternalStar2, 0);
            func_800672B0((s16)D_800FC8B8_ResultsEternalStar2, i + 1, 1);
            func_80067384((s16)D_800FC8B8_ResultsEternalStar2, i + 1, 0x10);
            func_800674BC((s16)D_800FC8B8_ResultsEternalStar2, i + 1, 0x1000);
            func_80066DC4((s16)D_800FC8B8_ResultsEternalStar2, i + 1, D_800FC2E8_ResultsEternalStar2[i][0], D_800FC2E8_ResultsEternalStar2[i][1]);
            func_80067284((s16)D_800FC8B8_ResultsEternalStar2, i + 1, 0.0f);
        }
    }
    D_800FC8C0_ResultsEternalStar2 = func_80064EF4(5, 5);
    func_80066DC4((s16)D_800FC8C0_ResultsEternalStar2, 0, 0, 0);
    file = DataRead(0xA0013);
    D_800FC8C4_ResultsEternalStar2 = func_800678A4(file);
    DataClose(file);
    for (i = 0; i < 4; i++) {
        func_80067208((s16)D_800FC8C0_ResultsEternalStar2, i + 1, (s16)D_800FC8C4_ResultsEternalStar2, 0);
        func_800672B0((s16)D_800FC8C0_ResultsEternalStar2, i + 1, 1);
        func_80067384((s16)D_800FC8C0_ResultsEternalStar2, i + 1, 0x10);
        func_800674BC((s16)D_800FC8C0_ResultsEternalStar2, i + 1, 0x1000);
        if (_CheckFlag(0x2C) == 0) {
            func_80066DC4((s16)D_800FC8C0_ResultsEternalStar2, i + 1, D_800FC2F8_ResultsEternalStar2[i][0], D_800FC2F8_ResultsEternalStar2[i][1]);
        } else {
            func_80066DC4((s16)D_800FC8C0_ResultsEternalStar2, i + 1, D_800FC308_ResultsEternalStar2[i][0], D_800FC308_ResultsEternalStar2[i][1]);
        }
        func_80067284((s16)D_800FC8C0_ResultsEternalStar2, i + 1, 0.0f);
    }
    if (_CheckFlag(0x2C) == 0) {
        for (i = 0; i < 8; i++) {
            if (i < 4) {
                v = GwPlayer[GwCommon.boardWork[i]].stars + GwCommon.boardWork[GwCommon.boardWork[i] + 10];
                if (v >= 10) {
                    sprintf(buf, D_800FC3C4_ResultsEternalStar2, v);
                } else {
                    sprintf(buf, "X%d", GwPlayer[GwCommon.boardWork[i]].stars + GwCommon.boardWork[GwCommon.boardWork[i] + 10]);
                }
            } else {
                v = GwPlayer[GwCommon.boardWork[i - 4]].coins;
                if (v >= 100) {
                    sprintf(buf, D_800FC3C4_ResultsEternalStar2, v);
                } else {
                    sprintf(buf, "X%2d", GwPlayer[GwCommon.boardWork[i - 4]].coins);
                }
            }
            func_80066DC4(D_800FC8C8_ResultsEternalStar2[i].unk_14[GMesFontMesCreate(&D_800FC8C8_ResultsEternalStar2[i], buf, 0, 0, -1)], 0,
                          D_800FC318_ResultsEternalStar2[i][0], D_800FC318_ResultsEternalStar2[i][1]);
        }
    } else {
        for (i = 4; i < 8; i++) {
            v = GwPlayer[GwCommon.boardWork[i - 4]].coins;
            if (v >= 100) {
                sprintf(buf, D_800FC3C4_ResultsEternalStar2, v);
            } else {
                sprintf(buf, "X%2d", GwPlayer[GwCommon.boardWork[i - 4]].coins);
            }
            func_80066DC4(D_800FC8C8_ResultsEternalStar2[i].unk_14[GMesFontMesCreate(&D_800FC8C8_ResultsEternalStar2[i], buf, 0, 0, -1)], 0,
                          D_800FC338_ResultsEternalStar2[i][0], D_800FC338_ResultsEternalStar2[i][1]);
        }
    }
    if (_CheckFlag(0x2C) == 0) {
        D_800FCC08_ResultsEternalStar2 = CreateTextWindow(0x46, 0xD0, 0x10, 1);
        func_8006E154((s16)D_800FCC08_ResultsEternalStar2, 0);
        func_8006E070((s16)D_800FCC08_ResultsEternalStar2, 0);
        LoadStringIntoWindow((s16)D_800FCC08_ResultsEternalStar2, (void*)0x4F2, -1, -1);
    } else {
        D_800FCC08_ResultsEternalStar2 = CreateTextWindow(0x82, 0xD0, 7, 1);
        func_8006E154((s16)D_800FCC08_ResultsEternalStar2, 0);
        func_8006E070((s16)D_800FCC08_ResultsEternalStar2, 0);
        LoadStringIntoWindow((s16)D_800FCC08_ResultsEternalStar2, (void*)0x4F3, -1, -1);
    }
    func_80071598((s16)D_800FCC08_ResultsEternalStar2);
}
void func_800F8990_ResultsEternalStar2(void) {
    f32 s;
    s32 i;

    HuPrcSleep(10);
    for (s = 0.5f; s <= 1.0f; s += 0.05f) {
        D_800FC888_ResultsEternalStar2[0]->scale = s;
        func_8004F7C0(D_800FC898_ResultsEternalStar2[0], s, s);
        HuPrcVSleep();
    }
    D_800FC888_ResultsEternalStar2[0]->scale = 1.0f;
    i = 0;
    func_8004F7C0(D_800FC898_ResultsEternalStar2[0], 1.0f, 1.0f);
    D_800FC888_ResultsEternalStar2[0]->flags &= ~2;
    while (1) {
        if (!(D_800FC888_ResultsEternalStar2[0]->flags & 1)) {
            break;
        }
        if (++i == 13) {
            func_80060468(0x89, GwPlayer[GwCommon.boardWork[0]].character);
        }
        HuPrcVSleep();
    }
    HuPrcSleep(30);
    for (s = 1.0f; s >= 0.5f; s -= 0.05f) {
        D_800FC888_ResultsEternalStar2[0]->scale = s;
        func_8004F7C0(D_800FC898_ResultsEternalStar2[0], s, s);
        HuPrcVSleep();
    }
    D_800FC888_ResultsEternalStar2[0]->scale = 0.5f;
    func_8004F7C0(D_800FC898_ResultsEternalStar2[0], 0.5f, 0.5f);
    HuPrcSleep(10);
    for (s = 0.5f; s <= 1.0f; s += 0.05f) {
        D_800FC888_ResultsEternalStar2[3]->scale = s;
        func_8004F7C0(D_800FC898_ResultsEternalStar2[3], s, s);
        HuPrcVSleep();
    }
    D_800FC888_ResultsEternalStar2[3]->scale = 1.0f;
    i = 0;
    func_8004F7C0(D_800FC898_ResultsEternalStar2[3], 1.0f, 1.0f);
    D_800FC888_ResultsEternalStar2[3]->flags &= ~2;
    while (1) {
        if (!(D_800FC888_ResultsEternalStar2[3]->flags & 1)) {
            break;
        }
        if (++i == 13) {
            func_80060468(0x90, GwPlayer[GwCommon.boardWork[3]].character);
        }
        HuPrcVSleep();
    }
    HuPrcSleep(30);
    for (s = 1.0f; s >= 0.5f; s -= 0.05f) {
        D_800FC888_ResultsEternalStar2[3]->scale = s;
        func_8004F7C0(D_800FC898_ResultsEternalStar2[3], s, s);
        HuPrcVSleep();
    }
    D_800FC888_ResultsEternalStar2[3]->scale = 0.5f;
    func_8004F7C0(D_800FC898_ResultsEternalStar2[3], 0.5f, 0.5f);
}
void func_800F8CFC_ResultsEternalStar2(void) {
    s32 i;

    func_80077044(&D_800FC808_ResultsEternalStar2);
    for (i = 0; i < 4; i++) {
        func_80067704((s16)D_800FC878_ResultsEternalStar2[i]);
        if ((i == 0) | (i == 3)) {
            func_80042B10(D_800FC888_ResultsEternalStar2[i]);
        } else {
            func_8004F584(D_800FC8A8_ResultsEternalStar2[i]);
        }
        func_8004F584(D_800FC898_ResultsEternalStar2[i]);
    }
    func_80064D38((s16)D_800FC870_ResultsEternalStar2);
    if (_CheckFlag(0x2C) == 0) {
        func_80067704((s16)D_800FC8BC_ResultsEternalStar2);
        func_80064D38((s16)D_800FC8B8_ResultsEternalStar2);
    }
    func_80067704((s16)D_800FC8C4_ResultsEternalStar2);
    func_80064D38((s16)D_800FC8C0_ResultsEternalStar2);
    if (_CheckFlag(0x2C) == 0) {
        for (i = 0; i < 8; i++) {
            func_80077044(&D_800FC8C8_ResultsEternalStar2[i]);
        }
    } else {
        for (i = 4; i < 8; i++) {
            func_80077044(&D_800FC8C8_ResultsEternalStar2[i]);
        }
    }
    func_80070D90((s16)D_800FCC08_ResultsEternalStar2);
}
void func_800F8EB8_ResultsEternalStar2(void) {
    s32 i;
    s32 xoff = 320;

    if (_CheckFlag(0x2C) == 0) {
        func_80066DC4(D_800FC808_ResultsEternalStar2.unk_14[0], 0, D_800FC2A4_ResultsEternalStar2[0] + xoff, D_800FC2A4_ResultsEternalStar2[1]);
        func_80066DC4((s16)D_800FC870_ResultsEternalStar2, 0, xoff, 0);
        for (i = 0; i < 4; i++) {
            if ((i == 0) | (i == 3)) {
                D_800FC888_ResultsEternalStar2[i]->x = D_800FC2C8_ResultsEternalStar2[i][0] + xoff;
                D_800FC888_ResultsEternalStar2[i]->y = D_800FC2C8_ResultsEternalStar2[i][1];
            } else {
                func_8004F754_unproto(D_800FC8A8_ResultsEternalStar2[i], D_800FC2C8_ResultsEternalStar2[i][0] + xoff, D_800FC2C8_ResultsEternalStar2[i][1]);
            }
            func_8004F754_unproto(D_800FC898_ResultsEternalStar2[i], D_800FC2C8_ResultsEternalStar2[i][0] + xoff, D_800FC2C8_ResultsEternalStar2[i][1]);
        }
        func_80066DC4((s16)D_800FC8B8_ResultsEternalStar2, 0, xoff, 0);
        func_80066DC4((s16)D_800FC8C0_ResultsEternalStar2, 0, xoff, 0);
        for (i = 0; i < 8; i++) {
            func_80066DC4(D_800FC8C8_ResultsEternalStar2[i].unk_14[0], 0, D_800FC318_ResultsEternalStar2[i][0] + xoff, D_800FC318_ResultsEternalStar2[i][1]);
        }
    } else {
        func_80066DC4(D_800FC808_ResultsEternalStar2.unk_14[0], 0, D_800FC2A4_ResultsEternalStar2[0] + xoff, D_800FC2A4_ResultsEternalStar2[1]);
        func_80066DC4((s16)D_800FC870_ResultsEternalStar2, 0, xoff, 0);
        for (i = 0; i < 4; i++) {
            if ((i == 0) | (i == 3)) {
                D_800FC888_ResultsEternalStar2[i]->x = D_800FC2D8_ResultsEternalStar2[i][0] + xoff;
                D_800FC888_ResultsEternalStar2[i]->y = D_800FC2D8_ResultsEternalStar2[i][1];
            } else {
                func_8004F754_unproto(D_800FC8A8_ResultsEternalStar2[i], D_800FC2D8_ResultsEternalStar2[i][0] + xoff, D_800FC2D8_ResultsEternalStar2[i][1]);
            }
            func_8004F754_unproto(D_800FC898_ResultsEternalStar2[i], D_800FC2D8_ResultsEternalStar2[i][0] + xoff, D_800FC2D8_ResultsEternalStar2[i][1]);
        }
        func_80066DC4((s16)D_800FC8C0_ResultsEternalStar2, 0, xoff, 0);
        for (i = 4; i < 8; i++) {
            func_80066DC4(D_800FC8C8_ResultsEternalStar2[i].unk_14[0], 0, D_800FC338_ResultsEternalStar2[i][0] + xoff, D_800FC338_ResultsEternalStar2[i][1]);
        }
    }
    func_80070D90((s16)D_800FCC08_ResultsEternalStar2);
}
void func_800F9250_ResultsEternalStar2(void) {
    s32 i;
    s32 xoff = 0;

    if (_CheckFlag(0x2C) == 0) {
        func_80066DC4(D_800FC808_ResultsEternalStar2.unk_14[0], 0, D_800FC2A4_ResultsEternalStar2[0] + xoff, D_800FC2A4_ResultsEternalStar2[1]);
        func_80066DC4((s16)D_800FC870_ResultsEternalStar2, 0, xoff, 0);
        for (i = 0; i < 4; i++) {
            if ((i == 0) | (i == 3)) {
                D_800FC888_ResultsEternalStar2[i]->x = D_800FC2C8_ResultsEternalStar2[i][0] + xoff;
                D_800FC888_ResultsEternalStar2[i]->y = D_800FC2C8_ResultsEternalStar2[i][1];
            } else {
                func_8004F754_unproto(D_800FC8A8_ResultsEternalStar2[i], D_800FC2C8_ResultsEternalStar2[i][0] + xoff, D_800FC2C8_ResultsEternalStar2[i][1]);
            }
            func_8004F754_unproto(D_800FC898_ResultsEternalStar2[i], D_800FC2C8_ResultsEternalStar2[i][0] + xoff, D_800FC2C8_ResultsEternalStar2[i][1]);
        }
        func_80066DC4((s16)D_800FC8B8_ResultsEternalStar2, 0, xoff, 0);
        func_80066DC4((s16)D_800FC8C0_ResultsEternalStar2, 0, xoff, 0);
        for (i = 0; i < 8; i++) {
            func_80066DC4(D_800FC8C8_ResultsEternalStar2[i].unk_14[0], 0, D_800FC318_ResultsEternalStar2[i][0] + xoff, D_800FC318_ResultsEternalStar2[i][1]);
        }
    } else {
        func_80066DC4(D_800FC808_ResultsEternalStar2.unk_14[0], 0, D_800FC2A4_ResultsEternalStar2[0] + xoff, D_800FC2A4_ResultsEternalStar2[1]);
        func_80066DC4((s16)D_800FC870_ResultsEternalStar2, 0, xoff, 0);
        for (i = 0; i < 4; i++) {
            if ((i == 0) | (i == 3)) {
                D_800FC888_ResultsEternalStar2[i]->x = D_800FC2D8_ResultsEternalStar2[i][0] + xoff;
                D_800FC888_ResultsEternalStar2[i]->y = D_800FC2D8_ResultsEternalStar2[i][1];
            } else {
                func_8004F754_unproto(D_800FC8A8_ResultsEternalStar2[i], D_800FC2D8_ResultsEternalStar2[i][0] + xoff, D_800FC2D8_ResultsEternalStar2[i][1]);
            }
            func_8004F754_unproto(D_800FC898_ResultsEternalStar2[i], D_800FC2D8_ResultsEternalStar2[i][0] + xoff, D_800FC2D8_ResultsEternalStar2[i][1]);
        }
        func_80066DC4((s16)D_800FC8C0_ResultsEternalStar2, 0, xoff, 0);
        for (i = 4; i < 8; i++) {
            func_80066DC4(D_800FC8C8_ResultsEternalStar2[i].unk_14[0], 0, D_800FC338_ResultsEternalStar2[i][0] + xoff, D_800FC338_ResultsEternalStar2[i][1]);
        }
    }
    D_800FCC08_ResultsEternalStar2 = CreateTextWindow(0x46, 0xD0, 0x10, 1);
    func_8006E154((s16)D_800FCC08_ResultsEternalStar2, 0);
    func_8006E070((s16)D_800FCC08_ResultsEternalStar2, 0);
    LoadStringIntoWindow((s16)D_800FCC08_ResultsEternalStar2, (void*)0x4F2, -1, -1);
}
const char D_800FC3D4_ResultsEternalStar2[] = "%5d";

void func_800F95F8_ResultsEternalStar2(void) {
    u8 sp10[5];
    s32 i;
    s32 var_s2;

    while (1) {
        var_s2 = 0;
        sprintf((char*)&sp10, D_800FC3D4_ResultsEternalStar2, GwCommon.coinNum);
        for (i = 0; i < 5; i++) {
            func_800672B0((s16)D_800FC4C8_ResultsEternalStar2[0], i, 1);
            if (var_s2 == 0 && (sp10[i] == ' ') & (i != 4)) {
                func_800672DC((s16)D_800FC4C8_ResultsEternalStar2[0], i, 0, 0);
                func_800674BC((s16)D_800FC4C8_ResultsEternalStar2[0], i, 0x8000);
            } else {
                var_s2 = 1;
                func_800672DC((s16)D_800FC4C8_ResultsEternalStar2[0], i, sp10[i] - 0x30, 0);
                func_80067480((s16)D_800FC4C8_ResultsEternalStar2[0], i, 0x8000);
            }
        }
        HuPrcVSleep();
    }
}
void func_800F972C_ResultsEternalStar2(void) {
    u8 sp10[5];
    s32 i;
    s32 var_s2;

    while (1) {
        var_s2 = 0;
        sprintf((char*)&sp10, D_800FC3D4_ResultsEternalStar2, GwCommon.starNum);
        for (i = 0; i < 5; i++) {
            func_800672B0((s16)D_800FC4C8_ResultsEternalStar2[1], i, 1);
             if (var_s2 == 0 && (sp10[i] == ' ') & (i != 4)) {
                func_800672DC((s16)D_800FC4C8_ResultsEternalStar2[1], i, 0, 0);
                func_800674BC((s16)D_800FC4C8_ResultsEternalStar2[1], i, 0x8000);             
             } else {
                var_s2 = 1;
                func_800672DC((s16)D_800FC4C8_ResultsEternalStar2[1], i, sp10[i] - 0x30, 0);
                func_80067480((s16)D_800FC4C8_ResultsEternalStar2[1], i, 0x8000);
             }
        }
        HuPrcVSleep();        
    }
}

void func_800F9860_ResultsEternalStar2(omObjData* obj) {
    D_800FC418_ResultsEternalStar2[obj->work[0]]->unk_18.x = sinf(obj->rot.y * 0.017453292519943295);
    D_800FC418_ResultsEternalStar2[obj->work[0]]->unk_18.z = cosf(obj->rot.y * 0.017453292519943295);
    if ((obj->rot.y += obj->trans.y) >= 360.0f) {
        obj->rot.y -= 360.0f;
    }
    if (obj->trans.z < 0.0f) {
        D_800FC418_ResultsEternalStar2[obj->work[0]]->coords.y += 10.0f;
        if (D_800FC418_ResultsEternalStar2[obj->work[0]]->coords.y >= 35.0f) {
            if (obj->work[2] == 1) {
                obj->trans.x -= 2.0f;
            } else if (obj->work[2] == 2) {
                obj->trans.x += 2.0f;
            }
        }
    } else {
        D_800FC418_ResultsEternalStar2[obj->work[0]]->coords.y -= 10.0f;
        if (obj->trans.x > D_800FC0DC_ResultsEternalStar2[0].x) {
            if ((obj->trans.x -= 2.0f) < D_800FC0DC_ResultsEternalStar2[0].x) {
                obj->trans.x = D_800FC0DC_ResultsEternalStar2[0].x;
            }
        } else if (obj->trans.x < D_800FC0DC_ResultsEternalStar2[0].x) {
            if ((obj->trans.x += 2.0f) > D_800FC0DC_ResultsEternalStar2[0].x) {
                obj->trans.x = D_800FC0DC_ResultsEternalStar2[0].x;
            }
        }
    }
    D_800FC418_ResultsEternalStar2[obj->work[0]]->coords.x = obj->trans.x;
    if (D_800FC418_ResultsEternalStar2[obj->work[0]]->coords.y == 100.0f && obj->trans.z <= 0.0f) {
        GwCommon.coinNum += (s32)obj->trans.z;
        if (D_800FC0C0_ResultsEternalStar2 >= 3) {
            PlaySound(0x3A);
            D_800FC0C0_ResultsEternalStar2 -= 3;
        } else {
            D_800FC0C0_ResultsEternalStar2 += 2;
        }
    }
    if (D_800FC418_ResultsEternalStar2[obj->work[0]]->coords.y <= 0.0f || D_800FC418_ResultsEternalStar2[obj->work[0]]->coords.y >= 200.0f) {
        if (GwCommon.boardItem != 3 && obj->trans.z > 0.0f) {
            GwCommon.coinNum += (s32)obj->trans.z;
            if ((s32)GwCommon.coinNum > 99999) {
                GwCommon.coinNum = 99999;
            }
            if (D_800FC0C0_ResultsEternalStar2 >= 3) {
                PlaySound(0x27);
                D_800FC0C0_ResultsEternalStar2 -= 3;
            } else {
                D_800FC0C0_ResultsEternalStar2 += 2;
            }
        }
        D_800FC418_ResultsEternalStar2[obj->work[0]]->coords.y = D_800FC0DC_ResultsEternalStar2[0].y;
        omDelObj(obj);
    }
}
void func_800F9C74_ResultsEternalStar2(omObjData* obj) {
    omObjData* coin;
    s32 p;
    s32 n;
    s32 j;

    p = obj->work[0];
    n = 0;
    if (obj->scale.x >= 1.0f) {
        while (1) {
            if (p >= 4) {
                if (D_800FC4B0_ResultsEternalStar2 > 0) {
                    D_800FC4B0_ResultsEternalStar2--;
                    n++;
                }
                if (D_800FC4B0_ResultsEternalStar2 == 0) {
                    break;
                }
            } else {
                if (!(GwPlayer[GwCommon.boardWork[p]].flags & 1)) {
                    if (D_800FC4A0_ResultsEternalStar2[GwCommon.boardWork[p]] > 0) {
                        D_800FC4A0_ResultsEternalStar2[GwCommon.boardWork[p]]--;
                        GwPlayer[GwCommon.boardWork[p]].coins--;
                        n++;
                    }
                }
                p = (p + 1) & 3;
                for (j = 0; j < 4; j++) {
                    if (!(GwPlayer[GwCommon.boardWork[j]].flags & 1) && D_800FC4A0_ResultsEternalStar2[GwCommon.boardWork[j]] > 0) {
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
            coin = omAddObj(0x1000, 0, 0, -1, func_800F9860_ResultsEternalStar2);
            coin->rot.y = rand8() & 0xFF;
            coin->trans.y = 20.0f;
            coin->work[2] = (rand8() & 0xFF) % 3;
            coin->work[0] = (u8)D_800FC370_ResultsEternalStar2;
            coin->trans.x = D_800FC0DC_ResultsEternalStar2[coin->work[2]].x;
            coin->trans.z = n;
            coin->scale.z = 3.0f;
            if (obj->work[0] == 5) {
                D_800FC418_ResultsEternalStar2[D_800FC370_ResultsEternalStar2]->coords.y = 0.0f;
                coin->trans.z = -coin->trans.z;
                coin->trans.x = D_800FC0DC_ResultsEternalStar2[0].x;
            }
            D_800FC370_ResultsEternalStar2 = (D_800FC370_ResultsEternalStar2 + 1) % 20;
            n--;
            p--;
        }
    } else {
        D_800FC0C0_ResultsEternalStar2 += 2;
    }
    if (obj->work[0] >= 4) {
        if (D_800FC4B0_ResultsEternalStar2 == 0) {
            omDelObj(obj);
        }
    } else {
        for (j = 0; j < 4; j++) {
            if (!(GwPlayer[GwCommon.boardWork[j]].flags & 1) && D_800FC4A0_ResultsEternalStar2[GwCommon.boardWork[j]] > 0) {
                break;
            }
        }
        if (j == 4) {
            omDelObj(obj);
        }
    }
}
void func_800FA08C_ResultsEternalStar2(omObjData* obj) {
    D_800FC410_ResultsEternalStar2->xScale = sinf(obj->scale.x * 0.017453292519943295) / 3.0f + 1.0f;
    D_800FC410_ResultsEternalStar2->zScale = sinf(obj->scale.z * 0.017453292519943295) / 3.0f + 1.0f;
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
void func_800FA200_ResultsEternalStar2(omObjData* obj) {
    D_800FC410_ResultsEternalStar2->xScale = sinf(obj->scale.x * 0.017453292519943295) / 3.0f + 1.0f;
    D_800FC410_ResultsEternalStar2->zScale = sinf(obj->scale.z * 0.017453292519943295) / 3.0f + 1.0f;
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
void func_800FA3A4_ResultsEternalStar2(omObjData* obj) {
    D_800FC468_ResultsEternalStar2[obj->work[0]]->coords.x = sinf(obj->rot.y * 0.017453292519943295) * obj->rot.x + D_800FC0C4_ResultsEternalStar2.x;
    D_800FC468_ResultsEternalStar2[obj->work[0]]->coords.y = obj->trans.y;
    D_800FC468_ResultsEternalStar2[obj->work[0]]->coords.z = cosf(obj->rot.y * 0.017453292519943295) * obj->rot.x + D_800FC0C4_ResultsEternalStar2.z;
    D_800FC468_ResultsEternalStar2[obj->work[0]]->unk_18.x = sinf(2.0f * -obj->rot.y * 0.017453292519943295);
    D_800FC468_ResultsEternalStar2[obj->work[0]]->unk_18.z = cosf(2.0f * -obj->rot.y * 0.017453292519943295);
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
            PlaySound(0x3E);
        }
        D_800FC468_ResultsEternalStar2[obj->work[0]]->coords.y = D_800FC0DC_ResultsEternalStar2[0].y;
        omDelObj(obj);
    }
}
void func_800FA5E0_ResultsEternalStar2(s32 arg0) {
    if (arg0 == 1) {
        arg0 = 30;
    } else if (arg0 == 2) {
        arg0 = 60;
    } else {
        arg0 = 90;
    }
    HuPrcSleep(arg0);
}
void func_800FA61C_ResultsEternalStar2(void) {
    s32 win[4];
    char buf[24];
    omObjData* obj;
    s32 i;
    s32 j;
    s32 k;
    s32 sel;

    func_8004E3E0(0, &D_800FC0C4_ResultsEternalStar2, 50, D_800FC410_ResultsEternalStar2);
    HuPrcSleep(60);
    D_800FC4B4_ResultsEternalStar2 = D_800FC4B0_ResultsEternalStar2;
    if ((s32)(D_800FC4B0_ResultsEternalStar2 + GwCommon.coinNum) > 99999) {
        D_800FC4B4_ResultsEternalStar2 = 99999 - GwCommon.coinNum;
    }
    if (D_800FC4B0_ResultsEternalStar2 != 0) {
        obj = omAddObj(0x1000, 0, 0, -1, func_800F9C74_ResultsEternalStar2);
        obj->trans.x = D_800FC4B0_ResultsEternalStar2 / 60.0f;
        obj->work[0] = 0;
        obj->scale.x = 1.0f;
        func_800FA5E0_ResultsEternalStar2(D_800FC4B0_ResultsEternalStar2);
    }
    if (GwCommon.boardItem == 1 || GwCommon.boardItem == 2 || GwCommon.boardItem == 3) {
        if (GwCommon.boardItem == 1) {
            D_800FC4B0_ResultsEternalStar2 /= 10;
            if (D_800FC4B0_ResultsEternalStar2 != 0) {
                win[0] = CreateTextWindow(0x28, 0x50, 0xB, 2);
                func_8006DA1C((s16)win[0], 32, 32);
                func_8006DE20((s16)win[0], 1.0f, 1.0f);
                sprintf(buf, D_800FC3C4_ResultsEternalStar2, D_800FC4B0_ResultsEternalStar2);
                func_8006DA5C((s16)win[0], buf, 0);
                LoadStringIntoWindow((s16)win[0], (void*)0x267, -1, -1);
                func_8006E070((s16)win[0], 0);
                while (func_8006FCC0((s16)win[0]) != 0) {
                    HuPrcVSleep();
                }
                func_80070D90((s16)win[0]);
                PlaySound(0x42);
                obj = omAddObj(0x1000, 0, 0, -1, func_800FA08C_ResultsEternalStar2);
                obj->scale.x = 0.0f;
                obj->scale.z = 0.0f;
                HuPrcSleep(90);
                obj = omAddObj(0x1000, 0, 0, -1, func_800F9C74_ResultsEternalStar2);
                obj->trans.x = D_800FC4B0_ResultsEternalStar2 / 60.0f;
                obj->work[0] = 4;
                obj->scale.x = 1.0f;
                func_800FA5E0_ResultsEternalStar2(D_800FC4B0_ResultsEternalStar2);
            }
        } else if (GwCommon.boardItem == 2 && D_800FC4B0_ResultsEternalStar2 != 0) {
            win[0] = CreateTextWindow(0x28, 0x50, 0xA, 4);
            func_8006DA1C((s16)win[0], 32, 32);
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
                LoadStringIntoWindow((s16)win[i], (void*)(s32)D_800FC374_ResultsEternalStar2[i], -1, -1);
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
                    PlaySound(0x2F);
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
                PlaySound(0x29);
            }
            if (sel == 2) {
                PlaySound(0x28);
            }
            HuPrcSleep(30);
            switch (sel) {
                case 0:
                    win[3] = CreateTextWindow(0x32, 0x3C, 9, 3);
                    func_8006DA1C((s16)win[3], 32, 32);
                    func_8006DE20((s16)win[3], 1.0f, 1.0f);
                    sprintf(buf, D_800FC3C4_ResultsEternalStar2, D_800FC4B4_ResultsEternalStar2 / 2);
                    func_8006DA5C((s16)win[3], buf, 0);
                    LoadStringIntoWindow((s16)win[3], (void*)0x266, -1, -1);
                    break;
                case 1:
                    win[3] = CreateTextWindow(0x32, 0x3C, 0xA, 2);
                    func_8006DA1C((s16)win[3], 32, 32);
                    func_8006DE20((s16)win[3], 1.0f, 1.0f);
                    LoadStringIntoWindow((s16)win[3], (void*)0x265, -1, -1);
                    break;
                case 2:
                    win[3] = CreateTextWindow(0x37, 0x3C, 8, 3);
                    func_8006DA1C((s16)win[3], 32, 32);
                    func_8006DE20((s16)win[3], 1.0f, 1.0f);
                    sprintf(buf, D_800FC3C4_ResultsEternalStar2, D_800FC4B0_ResultsEternalStar2);
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
                D_800FC4B0_ResultsEternalStar2 = D_800FC4B4_ResultsEternalStar2 / 2;
                if (D_800FC4B0_ResultsEternalStar2 != 0) {
                    PlaySound(0x45);
                    obj = omAddObj(0x1000, 0, 0, -1, func_800FA200_ResultsEternalStar2);
                    obj->scale.x = 0.0f;
                    obj->scale.y = 0.0f;
                    obj->scale.z = 0.0f;
                    obj->work[1] = 0;
                    obj->work[0] = 0;
                    HuPrcSleep(90);
                    obj = omAddObj(0x1000, 0, 0, -1, func_800F9C74_ResultsEternalStar2);
                    obj->trans.x = D_800FC4B0_ResultsEternalStar2 / 60.0f;
                    obj->work[0] = 5;
                    obj->scale.x = 1.0f;
                    func_800FA5E0_ResultsEternalStar2(D_800FC4B0_ResultsEternalStar2);
                }
            } else if (sel == 2) {
                PlaySound(0x42);
                obj = omAddObj(0x1000, 0, 0, -1, func_800FA200_ResultsEternalStar2);
                obj->scale.x = 0.0f;
                obj->scale.y = 0.0f;
                obj->scale.z = 0.0f;
                obj->work[1] = 0;
                obj->work[0] = 0;
                HuPrcSleep(90);
                obj = omAddObj(0x1000, 0, 0, -1, func_800F9C74_ResultsEternalStar2);
                obj->trans.x = D_800FC4B0_ResultsEternalStar2 / 60.0f;
                obj->work[0] = 4;
                obj->scale.x = 1.0f;
                func_800FA5E0_ResultsEternalStar2(D_800FC4B0_ResultsEternalStar2);
            }
        }
    }
    HuPrcSleep(20);
    for (j = 0; j < 7; j++) {
        D_800FC4E8_ResultsEternalStar2[j] = func_80042728(D_800FC468_ResultsEternalStar2[j], 2);
    }
    for (j = 0; j < D_800FC4B8_ResultsEternalStar2; j++) {
        obj = omAddObj(0x1000, 0, 0, -1, func_800FA3A4_ResultsEternalStar2);
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
        if (j + 1 == D_800FC4B8_ResultsEternalStar2) {
            HuPrcSleep(90);
        }
    }
    for (j = 0; j < 7; j++) {
        func_800427D4(D_800FC4E8_ResultsEternalStar2[j]);
    }
    if (GwCommon.boardItem == 3) {
        func_8004EE14(0, &D_800FC100_ResultsEternalStar2, 10, D_800FC410_ResultsEternalStar2);
        HuPrcSleep(10);
        func_8004E3E0(0, &D_800FC100_ResultsEternalStar2, 20, D_800FC410_ResultsEternalStar2);
        HuPrcSleep(20);
    }
    D_800F5144 = 1;
    while (1) {
        HuPrcVSleep();
    }
}
void func_800FB0A4_ResultsEternalStar2(void) {
    s32 i;
    s32 xoff;

    SetFadeInTypeAndTime(0, 16);
    HuPrcSleep(26);
    func_800F8990_ResultsEternalStar2();
    func_8007166C((s16)D_800FCC08_ResultsEternalStar2);
    for (i = 0; i < 4; i++) {
        D_800FC508_ResultsEternalStar2[i] = GwPlayer[i].stars;
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
                    func_800F8EB8_ResultsEternalStar2();
                    func_800F7324_ResultsEternalStar2();
                    func_800F7C28_ResultsEternalStar2();
                    func_800F7D94_ResultsEternalStar2();
                    func_800F9250_ResultsEternalStar2();
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
    func_80071598((s16)D_800FCC08_ResultsEternalStar2);
    for (xoff = 0; xoff >= -320; xoff -= 16) {
        if (_CheckFlag(0x2C) == 0) {
            func_80066DC4(D_800FC808_ResultsEternalStar2.unk_14[0], 0, D_800FC2A4_ResultsEternalStar2[0] + xoff, D_800FC2A4_ResultsEternalStar2[1]);
            func_80066DC4((s16)D_800FC870_ResultsEternalStar2, 0, xoff, 0);
            for (i = 0; i < 4; i++) {
                if ((i == 0) | (i == 3)) {
                    D_800FC888_ResultsEternalStar2[i]->x = D_800FC2C8_ResultsEternalStar2[i][0] + xoff;
                    D_800FC888_ResultsEternalStar2[i]->y = D_800FC2C8_ResultsEternalStar2[i][1];
                } else {
                    func_8004F754_unproto(D_800FC8A8_ResultsEternalStar2[i], D_800FC2C8_ResultsEternalStar2[i][0] + xoff, D_800FC2C8_ResultsEternalStar2[i][1]);
                }
                func_8004F754_unproto(D_800FC898_ResultsEternalStar2[i], D_800FC2C8_ResultsEternalStar2[i][0] + xoff, D_800FC2C8_ResultsEternalStar2[i][1]);
            }
            func_80066DC4((s16)D_800FC8B8_ResultsEternalStar2, 0, xoff, 0);
            func_80066DC4((s16)D_800FC8C0_ResultsEternalStar2, 0, xoff, 0);
            for (i = 0; i < 8; i++) {
                func_80066DC4(D_800FC8C8_ResultsEternalStar2[i].unk_14[0], 0, D_800FC318_ResultsEternalStar2[i][0] + xoff, D_800FC318_ResultsEternalStar2[i][1]);
            }
        } else {
            func_80066DC4(D_800FC808_ResultsEternalStar2.unk_14[0], 0, D_800FC2A4_ResultsEternalStar2[0] + xoff, D_800FC2A4_ResultsEternalStar2[1]);
            func_80066DC4((s16)D_800FC870_ResultsEternalStar2, 0, xoff, 0);
            for (i = 0; i < 4; i++) {
                if ((i == 0) | (i == 3)) {
                    D_800FC888_ResultsEternalStar2[i]->x = D_800FC2D8_ResultsEternalStar2[i][0] + xoff;
                    D_800FC888_ResultsEternalStar2[i]->y = D_800FC2D8_ResultsEternalStar2[i][1];
                } else {
                    func_8004F754_unproto(D_800FC8A8_ResultsEternalStar2[i], D_800FC2D8_ResultsEternalStar2[i][0] + xoff, D_800FC2D8_ResultsEternalStar2[i][1]);
                }
                func_8004F754_unproto(D_800FC898_ResultsEternalStar2[i], D_800FC2D8_ResultsEternalStar2[i][0] + xoff, D_800FC2D8_ResultsEternalStar2[i][1]);
            }
            func_80066DC4((s16)D_800FC8C0_ResultsEternalStar2, 0, xoff, 0);
            for (i = 4; i < 8; i++) {
                func_80066DC4(D_800FC8C8_ResultsEternalStar2[i].unk_14[0], 0, D_800FC338_ResultsEternalStar2[i][0] + xoff, D_800FC338_ResultsEternalStar2[i][1]);
            }
        }
        HuPrcVSleep();
    }
    func_800F8CFC_ResultsEternalStar2();
    func_800FB930_ResultsEternalStar2();
    func_800544E4();
    for (i = 0; i < 4; i++) {
        func_80054834(GwCommon.boardWork[i], i + 0x1C);
        func_80054744_unproto(GwCommon.boardWork[i], i);
    }
    for (xoff = 0; xoff >= -320; xoff -= 16) {
        func_8004F754_unproto(D_800FC4BC_ResultsEternalStar2[0], xoff + 370, 170);
        func_8004F754_unproto(D_800FC4BC_ResultsEternalStar2[1], xoff + 370, 204);
        func_80066DC4(D_800FC518_ResultsEternalStar2[0].unk_14[0], 0, xoff + 400, 170);
        func_80066DC4(D_800FC518_ResultsEternalStar2[1].unk_14[0], 0, xoff + 400, 204);
        func_80066DC4((s16)D_800FC4C8_ResultsEternalStar2[0], 0, xoff + 420, 170);
        func_80066DC4((s16)D_800FC4C8_ResultsEternalStar2[1], 0, xoff + 420, 204);
        HuPrcVSleep();
        if (xoff == 0) {
            for (i = 0; i < 4; i++) {
                func_80054868(D_800FC138_ResultsEternalStar2[i]);
            }
        }
    }
    func_800FA61C_ResultsEternalStar2();
}
void func_800FB76C_ResultsEternalStar2(omObjData* obj) {
    s32 i;

    if (func_80072718() == 0) {
        for (i = 0; i < 4; i++) {
            GwPlayer[i].stars = D_800FC508_ResultsEternalStar2[i];
        }
        func_800596DC_unproto(-1, (u16)GetSumOfPlayerStars());
        for (i = 0; i < 4; i++) {
            func_800596DC_unproto(-1, (u16)GwCommon.boardWork[i + 10]);
        }
        func_80059578(-1);
        if (GwSystem.curBoardIndex == 7 && _CheckFlag(0x2A) == 0) {
            SetBoardFeatureFlag(0x2A);
            GwCommon.unk_46 = -1;
        } else if (_CheckFlag(0x2C) == 0) {
            GwCommon.unk_46 = GwPlayer[GwCommon.boardWork[0]].character;
        }
        ClearBoardFeatureFlag(0x2C);
        func_8005B280();
        func_800FC090_ResultsEternalStar2();
        func_800FBE58_ResultsEternalStar2();
        func_8004F5F0();
        func_80054654();
        func_80070ED4();
        func_800532F4();
        MBModelClose();
        omOvlReturnEx(1);
    }
}
void func_800FB8E4_ResultsEternalStar2(omObjData* arg0) {
    if (D_800F5144 != 0) {
        func_800726AC(0, 0x4B);
        func_800601D4(0x96);
        arg0->func_ptr = &func_800FB76C_ResultsEternalStar2;
    }
}

void func_800FB930_ResultsEternalStar2(void) {
    s32 models[4] = { 0x5B, 0x59, 0x5A, 0x0B };
    void* file;
    s32 i;
    s32 j;

    D_800FC488_ResultsEternalStar2[0] = omAddPrcObj(func_800F95F8_ResultsEternalStar2, 0x1001, 0, 0);
    D_800FC488_ResultsEternalStar2[1] = omAddPrcObj(func_800F972C_ResultsEternalStar2, 0x1001, 0, 0);
    D_800FC4BC_ResultsEternalStar2[0] = func_8004F628(0xA0013, 10, 370, 170);
    D_800FC4BC_ResultsEternalStar2[1] = func_8004F628(0xA0014, 10, 370, 204);
    func_8004F860(D_800FC4BC_ResultsEternalStar2[0], 0);
    func_8004F860(D_800FC4BC_ResultsEternalStar2[1], 0);
    func_80066DC4(D_800FC518_ResultsEternalStar2[0].unk_14[GMesFontMesCreate(&D_800FC518_ResultsEternalStar2[0], "X", 0, -1, -1)], 0, 400, 170);
    func_80066DC4(D_800FC518_ResultsEternalStar2[1].unk_14[GMesFontMesCreate(&D_800FC518_ResultsEternalStar2[1], "X", 0, -1, -1)], 0, 400, 204);
    file = DataRead(0x7C);
    D_800FC4E0_ResultsEternalStar2[0] = func_800678A4(file);
    DataClose(file);
    D_800FC4C8_ResultsEternalStar2[0] = func_80064EF4(5, 5);
    for (i = 0; i < 5; i++) {
        func_80067208((s16)D_800FC4C8_ResultsEternalStar2[0], i, (s16)D_800FC4E0_ResultsEternalStar2[0], 0);
        func_800672B0((s16)D_800FC4C8_ResultsEternalStar2[0], i, 1);
        func_80067384((s16)D_800FC4C8_ResultsEternalStar2[0], i, 10);
        func_800674BC((s16)D_800FC4C8_ResultsEternalStar2[0], i, 0x1000);
        if (i == 0) {
            func_80066DC4((s16)D_800FC4C8_ResultsEternalStar2[0], 0, 420, 170);
        } else {
            func_80066DC4((s16)D_800FC4C8_ResultsEternalStar2[0], i, i * 16, 0);
        }
    }
    D_800FC4C8_ResultsEternalStar2[1] = func_80064EF4(5, 5);
    for (i = 0; i < 5; i++) {
        func_80067208((s16)D_800FC4C8_ResultsEternalStar2[1], i, (s16)D_800FC4E0_ResultsEternalStar2[0], 0);
        func_800672B0((s16)D_800FC4C8_ResultsEternalStar2[1], i, 1);
        func_80067384((s16)D_800FC4C8_ResultsEternalStar2[1], i, 10);
        func_800674BC((s16)D_800FC4C8_ResultsEternalStar2[1], i, 0x1000);
        func_800672DC((s16)D_800FC4C8_ResultsEternalStar2[1], i, 0, 0);
        func_80067284((s16)D_800FC4C8_ResultsEternalStar2[1], i, 0.0f);
        if (i == 0) {
            func_80066DC4((s16)D_800FC4C8_ResultsEternalStar2[1], 0, 420, 204);
        } else {
            func_80066DC4((s16)D_800FC4C8_ResultsEternalStar2[1], i, i * 16, 0);
        }
    }
    D_800FC410_ResultsEternalStar2 = MBModelCreate(models[GwCommon.boardItem], NULL);
    D_800FC410_ResultsEternalStar2->coords.x = D_800FC0D0_ResultsEternalStar2.x;
    D_800FC410_ResultsEternalStar2->coords.y = D_800FC0D0_ResultsEternalStar2.y;
    D_800FC410_ResultsEternalStar2->coords.z = D_800FC0D0_ResultsEternalStar2.z;
    D_800FC410_ResultsEternalStar2->unk_3C->unk_24 = 5.0f;
    func_8004CCD0(&D_800FC410_ResultsEternalStar2->coords, &D_800C3110->pos, &D_800FC410_ResultsEternalStar2->unk_18);
    for (j = 0; j < 20; j++) {
        if (j == 0) {
            D_800FC418_ResultsEternalStar2[0] = MBModelCreate(0x3D, NULL);
        } else {
            D_800FC418_ResultsEternalStar2[j] = MBModelParamCreate(D_800FC418_ResultsEternalStar2[0]);
        }
        D_800FC418_ResultsEternalStar2[j]->coords.x = D_800FC0DC_ResultsEternalStar2[0].x;
        D_800FC418_ResultsEternalStar2[j]->coords.y = D_800FC0DC_ResultsEternalStar2[0].y;
        D_800FC418_ResultsEternalStar2[j]->coords.z = D_800FC0DC_ResultsEternalStar2[0].z;
        D_800FC418_ResultsEternalStar2[j]->xScale = D_800FC418_ResultsEternalStar2[j]->yScale = D_800FC418_ResultsEternalStar2[j]->zScale = 0.5f;
    }
    for (j = 0; j < 7; j++) {
        if (j == 0) {
            D_800FC468_ResultsEternalStar2[0] = MBModelCreate(0x40, NULL);
        } else {
            D_800FC468_ResultsEternalStar2[j] = MBModelParamCreate(D_800FC468_ResultsEternalStar2[0]);
        }
        D_800FC468_ResultsEternalStar2[j]->coords.x = D_800FC0DC_ResultsEternalStar2[0].x;
        D_800FC468_ResultsEternalStar2[j]->coords.y = D_800FC0DC_ResultsEternalStar2[0].y;
        D_800FC468_ResultsEternalStar2[j]->coords.z = D_800FC0DC_ResultsEternalStar2[0].z;
        D_800FC468_ResultsEternalStar2[j]->xScale = D_800FC468_ResultsEternalStar2[j]->yScale = D_800FC468_ResultsEternalStar2[j]->zScale = 0.2f;
    }
}
void func_800FBE58_ResultsEternalStar2(void) {
    s32 i;

    MBModelKill(D_800FC410_ResultsEternalStar2);

    for (i = 0; i < ARRAY_COUNT(D_800FC418_ResultsEternalStar2); i++) {
        MBModelKill(D_800FC418_ResultsEternalStar2[i]);
    }
    for (i = 0; i < ARRAY_COUNT(D_800FC468_ResultsEternalStar2); i++) {
        MBModelKill(D_800FC468_ResultsEternalStar2[i]);
    }
    for (i = 0; i < ARRAY_COUNT(D_800FC488_ResultsEternalStar2); i++) {
        EndProcess(D_800FC488_ResultsEternalStar2[i]);
    }
    for (i = 0; i < ARRAY_COUNT(D_800FC4C8_ResultsEternalStar2); i++) {
        func_80064D38(D_800FC4C8_ResultsEternalStar2[i]);
    }
    for (i = 0; i < ARRAY_COUNT(D_800FC4E0_ResultsEternalStar2); i++) {
        func_80067704(D_800FC4E0_ResultsEternalStar2[i]);
    }

    func_80077044(D_800FC518_ResultsEternalStar2);
    func_80077044(&D_800FC518_ResultsEternalStar2[1]);
}

void func_800FBF78_ResultsEternalStar2(void) {
    func_800178A0(2);
    func_80017660(0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80017660(1, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(1, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    LoadBackgroundData(FE2310_ROM_START);
    LoadBackgroundIndex(D_800FC10C_ResultsEternalStar2[GwSystem.curBoardIndex]);
    func_8004B7F8(0x80);
}

void func_800FC090_ResultsEternalStar2(void) {
    func_8004A140();
    func_80049F0C();
}
