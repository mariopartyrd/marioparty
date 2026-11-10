#include "common.h"
#include "sprite65770.h"
#include "engine/pad.h"

#define ABS(x) ((x) < 0 ? -(x) : (x))

/* The minigame results screen: ranks the players (stars, then coins), shows the stars and coins
   per player, then counts each player's minigame coins into their total. */

void func_80067284(s16, s16, f32);
void func_8004FB14(void);
void func_8004FBB4(void);
void func_8004F548(void);
void func_8005049C(void);
void MBModelClose(void);
void func_80053074(void);
void AdjustPlayerCoins(s32, s32);
void func_80060F04(s16, s32, s32, s32);
int abs(int);

void func_800F6688_UnknownResultsScreen(void);
void func_800F6724_UnknownResultsScreen(void);
void func_800F7310_UnknownResultsScreen(void);
void func_800F7614_UnknownResultsScreen(void);
void func_800F7754_UnknownResultsScreen(void);
void func_800F79C8_UnknownResultsScreen(void);
void func_800F7A3C_UnknownResultsScreen(void);
void func_800F7A78_UnknownResultsScreen(void);
void func_800F7A9C_UnknownResultsScreen(void);
void func_800F7B3C_UnknownResultsScreen(void);
void func_800F7B60_UnknownResultsScreen(s16, s16, s16, s16);
void func_800F7BA0_UnknownResultsScreen(s16, s16, s16);
void func_800F7BCC_UnknownResultsScreen(s16, s16, s16);
void func_800F7BF8_UnknownResultsScreen(s16, s16, s32);
void func_800F7C30_UnknownResultsScreen(void);
void func_800F7DB4_UnknownResultsScreen(void);
void func_800F7F38_UnknownResultsScreen(void);
void func_800F8194_UnknownResultsScreen(void);
void func_800F82C4_UnknownResultsScreen(void);
void func_800F8B44_UnknownResultsScreen(void);
void func_800F90A4_UnknownResultsScreen(void);
void func_800F9A98_UnknownResultsScreen(s16);
s8 func_800F9BCC_UnknownResultsScreen(void);
void func_800F9E68_UnknownResultsScreen(void);

/* .data */
s8 D_800F9FD0_UnknownResultsScreen = 0; /* the screen is finished */
s8 D_800F9FD1_UnknownResultsScreen = 0; /* A/Start pressed: skip the waits */
s8 D_800F9FD2_UnknownResultsScreen = 1; /* skipping is not allowed */
s32 D_800F9FD4_UnknownResultsScreen[6] = { 0x000A0183, 0x000A0184, 0x000A0185,
                                           0x000A0186, 0x000A0187, 0x000A0188 };
char* D_800F9FEC_UnknownResultsScreen = "RESULTS";
s16 D_800F9FF0_UnknownResultsScreen[2] = { 160, 34 };
/* Per table row, the {x, y} of each place (rows: place sprite, character, coin icon, coins,
   stars, star counters). */
s16 D_800F9FF4_UnknownResultsScreen[6][4][2] = {
    { { 60, 70 }, { 60, 110 }, { 60, 150 }, { 60, 190 } },
    { { 110, 70 }, { 110, 110 }, { 110, 150 }, { 110, 190 } },
    { { 151, 70 }, { 151, 110 }, { 151, 150 }, { 151, 190 } },
    { { 226, 70 }, { 226, 110 }, { 226, 150 }, { 226, 190 } },
    { { 174, 74 }, { 174, 114 }, { 174, 154 }, { 174, 194 } },
    { { 250, 74 }, { 250, 114 }, { 250, 154 }, { 250, 194 } },
};
/* Per number of digits - 1: the x offset of each digit (-1000 hides it) and of the "X". */
s16 D_800FA054_UnknownResultsScreen[3][4] = {
    { -1000, -1000, 0, 250 },
    { -1000, 0, 0, 250 },
    { 0, 0, 0, -1000 },
};
s8 D_800FA06C_UnknownResultsScreen = 0;
/* Per number of digits - 1: the x offset of each digit of the minigame coins (-1000 hides it). */
s16 D_800FA070_UnknownResultsScreen[3][3] = { { -1000, -1000, 0 }, { -1000, -4, 4 }, { -8, 0, 8 } };
s16 D_800FA084_UnknownResultsScreen[3][3] = { { -1000, -1000, 0 }, { -1000, -4, 4 }, { -8, 0, 8 } };
s8 D_800FA096_UnknownResultsScreen = 0;
s8 D_800FA097_UnknownResultsScreen = 0;

/* .bss. The s32 slots hold s16 sprite/group ids (stored as words, read as their low half). */
extern s16 D_800FA0D0_UnknownResultsScreen[4]; /* coins to add (clamped to 0..999) */
extern s16 D_800FA0D8_UnknownResultsScreen[4]; /* coins won in the minigame */
typedef struct ResRank {
    /* 0x00 */ s8 rank;  /* 0 = first; tied players share a rank */
    /* 0x01 */ s8 place; /* row on the screen */
} ResRank;
extern ResRank D_800FA0E0_UnknownResultsScreen[4];
extern ResRank D_800FA0E8_UnknownResultsScreen[4]; /* before the minigame coins */
extern s16 D_800FA0F0_UnknownResultsScreen[4]; /* coins before the minigame */
extern s32 D_800FA0F8_UnknownResultsScreen;
extern unkCommonStruct0 D_800FA100_UnknownResultsScreen;
extern s32 D_800FA168_UnknownResultsScreen;
extern s32 D_800FA170_UnknownResultsScreen[4];
extern s32 D_800FA180_UnknownResultsScreen;
extern s32 D_800FA188_UnknownResultsScreen[4];
extern s32 D_800FA198_UnknownResultsScreen;
extern s32 D_800FA19C_UnknownResultsScreen;
extern s32 D_800FA1A0_UnknownResultsScreen;
extern s32 D_800FA1A4_UnknownResultsScreen;
extern unkCommonStruct0 D_800FA1A8_UnknownResultsScreen[8];
extern s32 D_800FA4E8_UnknownResultsScreen[8];
extern s32 D_800FA508_UnknownResultsScreen;
extern s32 D_800FA50C_UnknownResultsScreen;
extern s32 D_800FA510_UnknownResultsScreen;
extern s32 D_800FA514_UnknownResultsScreen;
extern s32 D_800FA518_UnknownResultsScreen[4];
extern s32 D_800FA528_UnknownResultsScreen;
extern s32 D_800FA530_UnknownResultsScreen[4];
extern s32 D_800FA540_UnknownResultsScreen[4];
extern s32 D_800FA550_UnknownResultsScreen[4][3];
extern s16 D_800FA580_UnknownResultsScreen[4]; /* coins counted per step */
extern s16 D_800FA588_UnknownResultsScreen[4]; /* coins counted so far */

void func_800F65E0_UnknownResultsScreen(void) {
    omInitObjMan(0x14, 0x14);
    func_800F7F38_UnknownResultsScreen();
    func_800F7A9C_UnknownResultsScreen();
    func_800F7A3C_UnknownResultsScreen();
    func_800F8194_UnknownResultsScreen();
    func_800F82C4_UnknownResultsScreen();
    omAddPrcObj(func_800F7754_UnknownResultsScreen, 0x300, 0x2500, 0);
    func_80060128(0x16);
    omAddObj(5, 0, 0, -1, func_800F79C8_UnknownResultsScreen);
    omAddObj(5, 0, 0, -1, func_800F6688_UnknownResultsScreen);
}

void func_800F6688_UnknownResultsScreen(void) {
    s8 i;

    if (D_800F9FD2_UnknownResultsScreen != 1) {
        for (i = 0; i < MAX_PLAYERS; i++) {
            if (!(GwPlayer[i].flags & 1)) {
                if (ContBtn[GwPlayer[i].port] & 0x9000) {
                    D_800F9FD1_UnknownResultsScreen = 1;
                }
            }
        }
    }
}

// register allocation of the sprite counters (masked 4)
#ifdef NON_MATCHING
void func_800F6724_UnknownResultsScreen(void) {
    char buf[16];
    s16 coins[4];
    s8 digits[4][3];
    s8 nd[4];
    s32 i;
    s32 n;
    s32 j;
    void* file;

    i = 0;
    func_8006CEA0();
    D_800FA0F8_UnknownResultsScreen = func_8006D010(0, 0, 320, 240, 0, 0);
    func_8006E154(D_800FA0F8_UnknownResultsScreen, 200);
    func_800714F0(D_800FA0F8_UnknownResultsScreen, 0, 0, 0);
    func_80066DC4(D_800FA100_UnknownResultsScreen.unk_14[GMesFontMesCreate(&D_800FA100_UnknownResultsScreen,
                                                                           D_800F9FEC_UnknownResultsScreen, 1, -1, -1)],
                  0, D_800F9FF0_UnknownResultsScreen[0], D_800F9FF0_UnknownResultsScreen[1]);

    D_800FA168_UnknownResultsScreen = func_80064EF4(0x11, 5);
    func_80066DC4(D_800FA168_UnknownResultsScreen, 0, 0, 0);
    for (n = 0; i < 4; i++) {
        file = DataRead((i + 0x125) | 0xA0000);
        D_800FA170_UnknownResultsScreen[i] = func_800678A4(file);
        DataClose(file);
        for (j = 0; j < 4; j++) {
            func_80067208(D_800FA168_UnknownResultsScreen, n + 1, D_800FA170_UnknownResultsScreen[i], 0);
            func_800672B0(D_800FA168_UnknownResultsScreen, n + 1, 1);
            func_80067384(D_800FA168_UnknownResultsScreen, n + 1, 0x10);
            func_800674BC(D_800FA168_UnknownResultsScreen, n + 1, 0x1000);
            if (D_800FA0E0_UnknownResultsScreen[j].rank == i) {
                func_80066DC4(D_800FA168_UnknownResultsScreen, n + 1,
                              D_800F9FF4_UnknownResultsScreen[0][D_800FA0E0_UnknownResultsScreen[j].place][0],
                              D_800F9FF4_UnknownResultsScreen[0][D_800FA0E0_UnknownResultsScreen[j].place][1]);
            } else {
                func_80066DC4(D_800FA168_UnknownResultsScreen, n + 1, -1000,
                              D_800F9FF4_UnknownResultsScreen[0][D_800FA0E0_UnknownResultsScreen[j].place][1]);
            }
            n++;
        }
    }

    D_800FA180_UnknownResultsScreen = func_80064EF4(5, 5);
    func_80066DC4(D_800FA180_UnknownResultsScreen, 0, 0, 0);
    for (i = 0; i < 4; i++) {
        file = DataRead(D_800F9FD4_UnknownResultsScreen[GwPlayer[i].character]);
        D_800FA188_UnknownResultsScreen[i] = func_800678A4(file);
        DataClose(file);
        func_80067208(D_800FA180_UnknownResultsScreen, i + 1, D_800FA188_UnknownResultsScreen[i], 0);
        func_800672B0(D_800FA180_UnknownResultsScreen, i + 1, 1);
        func_80067384(D_800FA180_UnknownResultsScreen, i + 1, 0x10);
        func_800674BC(D_800FA180_UnknownResultsScreen, i + 1, 0x1000);
        func_800672DC(D_800FA180_UnknownResultsScreen, i + 1, 0, 0);
        func_80067284(D_800FA180_UnknownResultsScreen, i + 1, 0);
        func_80066DC4(D_800FA180_UnknownResultsScreen, i + 1,
                      D_800F9FF4_UnknownResultsScreen[1][D_800FA0E0_UnknownResultsScreen[i].place][0],
                      D_800F9FF4_UnknownResultsScreen[1][D_800FA0E0_UnknownResultsScreen[i].place][1]);
    }

    D_800FA510_UnknownResultsScreen = func_80064EF4(5, 5);
    func_80066DC4(D_800FA510_UnknownResultsScreen, 0, 0, 0);
    file = DataRead(0xA0163);
    D_800FA514_UnknownResultsScreen = func_800678A4(file);
    DataClose(file);
    for (i = 0; i < 4; i++) {
        func_80067208(D_800FA510_UnknownResultsScreen, i + 1, D_800FA514_UnknownResultsScreen, 0);
        func_800672B0(D_800FA510_UnknownResultsScreen, i + 1, 1);
        func_80067384(D_800FA510_UnknownResultsScreen, i + 1, 0x11);
        func_800674BC(D_800FA510_UnknownResultsScreen, i + 1, 0x1000);
        func_80067354(D_800FA510_UnknownResultsScreen, i + 1, 0.5f, 0.5f);
        func_80066DC4(D_800FA510_UnknownResultsScreen, i + 1,
                      D_800F9FF4_UnknownResultsScreen[1][D_800FA0E0_UnknownResultsScreen[i].place][0] * 2,
                      D_800F9FF4_UnknownResultsScreen[1][D_800FA0E0_UnknownResultsScreen[i].place][1] * 2);
        func_80067284(D_800FA510_UnknownResultsScreen, i + 1, 0);
    }

    D_800FA198_UnknownResultsScreen = func_80064EF4(5, 5);
    func_80066DC4(D_800FA198_UnknownResultsScreen, 0, 0, 0);
    file = DataRead(0xA0014);
    D_800FA19C_UnknownResultsScreen = func_800678A4(file);
    DataClose(file);
    for (i = 0; i < 4; i++) {
        func_80067208(D_800FA198_UnknownResultsScreen, i + 1, D_800FA19C_UnknownResultsScreen, 0);
        func_800672B0(D_800FA198_UnknownResultsScreen, i + 1, 1);
        func_80067384(D_800FA198_UnknownResultsScreen, i + 1, 0x10);
        func_800674BC(D_800FA198_UnknownResultsScreen, i + 1, 0x1000);
        func_80066DC4(D_800FA198_UnknownResultsScreen, i + 1,
                      D_800F9FF4_UnknownResultsScreen[2][D_800FA0E0_UnknownResultsScreen[i].place][0],
                      D_800F9FF4_UnknownResultsScreen[2][D_800FA0E0_UnknownResultsScreen[i].place][1]);
        func_80067284(D_800FA198_UnknownResultsScreen, i + 1, 0);
    }

    D_800FA1A0_UnknownResultsScreen = func_80064EF4(5, 5);
    func_80066DC4(D_800FA1A0_UnknownResultsScreen, 0, 0, 0);
    file = DataRead(0xA0013);
    D_800FA1A4_UnknownResultsScreen = func_800678A4(file);
    DataClose(file);
    for (i = 0; i < 4; i++) {
        func_80067208(D_800FA1A0_UnknownResultsScreen, i + 1, D_800FA1A4_UnknownResultsScreen, 0);
        func_800672B0(D_800FA1A0_UnknownResultsScreen, i + 1, 1);
        func_80067384(D_800FA1A0_UnknownResultsScreen, i + 1, 0x10);
        func_800674BC(D_800FA1A0_UnknownResultsScreen, i + 1, 0x1000);
        func_80066DC4(D_800FA1A0_UnknownResultsScreen, i + 1,
                      D_800F9FF4_UnknownResultsScreen[3][D_800FA0E0_UnknownResultsScreen[i].place][0],
                      D_800F9FF4_UnknownResultsScreen[3][D_800FA0E0_UnknownResultsScreen[i].place][1]);
        func_80067284(D_800FA1A0_UnknownResultsScreen, i + 1, 0);
    }

    for (i = 0; i < 8; i++) {
        if (i < 4) {
            if (GwPlayer[i].stars < 10) {
                sprintf(buf, "X%d", GwPlayer[i].stars);
            } else {
                sprintf(buf, "%d", GwPlayer[i].stars);
            }
        } else {
            sprintf(buf, "X");
        }
        D_800FA4E8_UnknownResultsScreen[i] =
            D_800FA1A8_UnknownResultsScreen[i].unk_14[GMesFontMesCreate(&D_800FA1A8_UnknownResultsScreen[i], buf, 0, 0, -1)];
        if (i < 4) {
            func_80066DC4(D_800FA4E8_UnknownResultsScreen[i], 0,
                          D_800F9FF4_UnknownResultsScreen[4][D_800FA0E0_UnknownResultsScreen[i].place][0],
                          D_800F9FF4_UnknownResultsScreen[4][D_800FA0E0_UnknownResultsScreen[i].place][1]);
        } else {
            func_80066DC4(D_800FA4E8_UnknownResultsScreen[i], 0,
                          D_800F9FF4_UnknownResultsScreen[4][D_800FA0E0_UnknownResultsScreen[i - 4].place][0],
                          D_800F9FF4_UnknownResultsScreen[4][D_800FA0E0_UnknownResultsScreen[i - 4].place][1]);
        }
    }

    for (i = 0; i < 4; i++) {
        coins[i] = GwPlayer[i].coins;
        digits[i][0] = coins[i] / 100;
        digits[i][1] = (coins[i] - digits[i][0] * 100) / 10;
        digits[i][2] = coins[i] - digits[i][0] * 100 - digits[i][1] * 10;
        nd[i] = 0;
        if (coins[i] >= 10) {
            nd[i] = 1;
        }
        if (coins[i] >= 100) {
            nd[i] = 2;
        }
    }

    D_800FA508_UnknownResultsScreen = func_80064EF4(0xD, 5);
    func_80066DC4(D_800FA508_UnknownResultsScreen, 0, 0, 0);
    file = DataRead(0x7C);
    D_800FA50C_UnknownResultsScreen = func_800678A4(file);
    DataClose(file);
    for (n = 0, i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            n++;
            func_80067208(D_800FA508_UnknownResultsScreen, n, D_800FA50C_UnknownResultsScreen, 0);
            func_800672B0(D_800FA508_UnknownResultsScreen, n, 1);
            func_80067384(D_800FA508_UnknownResultsScreen, n, 0x10);
            func_800674BC(D_800FA508_UnknownResultsScreen, n, 0x1000);
            func_80066DC4(D_800FA508_UnknownResultsScreen, n,
                          D_800F9FF4_UnknownResultsScreen[3][D_800FA0E0_UnknownResultsScreen[i].place][0] + j * 16 + 24 +
                              D_800FA054_UnknownResultsScreen[nd[i]][j],
                          D_800F9FF4_UnknownResultsScreen[3][D_800FA0E0_UnknownResultsScreen[i].place][1] + 4);
            func_800672DC(D_800FA508_UnknownResultsScreen, n, digits[i][j], 0);
            func_80067284(D_800FA508_UnknownResultsScreen, n, 0);
        }
        func_800F7BA0_UnknownResultsScreen(D_800FA4E8_UnknownResultsScreen[4 + i], 0, D_800FA054_UnknownResultsScreen[nd[i]][3]);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_7C_UnknownResultsScreen/308A50", func_800F6724_UnknownResultsScreen);
#endif

// register allocation of the loop counters (masked 2)
#ifdef NON_MATCHING
void func_800F7310_UnknownResultsScreen(void) {
    s16 coins[4];
    s8 digits[4][3];
    s8 nd[4];
    s16 i;
    s16 j;
    s32 n;

    for (i = 0; i < 4; i++) {
        coins[i] = GwPlayer[i].coins;
        digits[i][0] = coins[i] / 100;
        digits[i][1] = (coins[i] - digits[i][0] * 100) / 10;
        digits[i][2] = coins[i] - digits[i][0] * 100 - digits[i][1] * 10;
        nd[i] = 0;
        if (coins[i] >= 10) {
            nd[i] = 1;
        }
        if (coins[i] >= 100) {
            nd[i] = 2;
        }
    }
    for (i = 0, n = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            n++;
            func_80066DC4(D_800FA508_UnknownResultsScreen, n,
                          D_800F9FF4_UnknownResultsScreen[3][D_800FA0E0_UnknownResultsScreen[i].place][0] + j * 16 + 24 +
                              D_800FA054_UnknownResultsScreen[nd[i]][j],
                          D_800F9FF4_UnknownResultsScreen[3][D_800FA0E0_UnknownResultsScreen[i].place][1] + 4);
            func_800672DC(D_800FA508_UnknownResultsScreen, n, digits[i][j], 0);
        }
        func_800F7BA0_UnknownResultsScreen(D_800FA4E8_UnknownResultsScreen[4 + i], 0, D_800FA054_UnknownResultsScreen[nd[i]][3]);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_7C_UnknownResultsScreen/308A50", func_800F7310_UnknownResultsScreen);
#endif

void func_800F7614_UnknownResultsScreen(void) {
    s32 i;

    func_80077044(&D_800FA100_UnknownResultsScreen);
    for (i = 0; i < 4; i++) {
        func_80067704(D_800FA188_UnknownResultsScreen[i]);
    }
    for (i = 0; i < 4; i++) {
        func_80067704(D_800FA170_UnknownResultsScreen[i]);
    }
    func_80064D38(D_800FA168_UnknownResultsScreen);
    func_80064D38(D_800FA180_UnknownResultsScreen);
    func_80067704(D_800FA514_UnknownResultsScreen);
    func_80064D38(D_800FA510_UnknownResultsScreen);
    func_80067704(D_800FA19C_UnknownResultsScreen);
    func_80067704(D_800FA1A4_UnknownResultsScreen);
    func_80064D38(D_800FA198_UnknownResultsScreen);
    func_80064D38(D_800FA1A0_UnknownResultsScreen);
    func_80064D38(D_800FA508_UnknownResultsScreen);
    for (i = 0; i < 8; i++) {
        func_80077044(&D_800FA1A8_UnknownResultsScreen[i]);
    }
    func_80070D90(D_800FA0F8_UnknownResultsScreen);
    func_80070ED4();
}

// scheduling of one register copy (masked 2)
#ifdef NON_MATCHING
void func_800F7754_UnknownResultsScreen(void) {
    s16 i;
    s8 cpus;
    s32 allCpu;
    s32 autoSkip;

    func_800F6724_UnknownResultsScreen();
    SetFadeInTypeAndTime(0, 16);
    if (func_80072718() != 0) {
        HuPrcVSleep();
    }
    D_800F9FD2_UnknownResultsScreen = 0;
    if (D_800F9FD1_UnknownResultsScreen == 0) {
        HuPrcSleep(30);
    }
    func_800F7DB4_UnknownResultsScreen();
    HuPrcSleep(60);
    func_800F9A98_UnknownResultsScreen(60);
    while (func_800F9BCC_UnknownResultsScreen() == 0) {
        func_800F7310_UnknownResultsScreen();
        func_800F8B44_UnknownResultsScreen();
        if (D_800F9FD1_UnknownResultsScreen == 0) {
            HuPrcVSleep();
        }
    }
    func_800F7310_UnknownResultsScreen();
    func_800F8B44_UnknownResultsScreen();
    if (D_800F9FD1_UnknownResultsScreen != 0) {
        HuPrcSleep(30);
    }
    func_800F7C30_UnknownResultsScreen();
    func_800F90A4_UnknownResultsScreen();
    allCpu = 0;
    cpus = 0;
    for (i = 0; i < MAX_PLAYERS; i++) {
        if (GwPlayer[i].flags & 1) {
            cpus++;
        }
    }
    if (cpus >= 4) {
        allCpu = 1;
    }
    autoSkip = allCpu;
    while (D_800FA06C_UnknownResultsScreen == 0) {
        for (i = 0; i < MAX_PLAYERS; i++) {
            if (!(GwPlayer[i].flags & 1)) {
                if (ContBtn[GwPlayer[i].port] & 0x9000) {
                    D_800FA06C_UnknownResultsScreen = 1;
                }
            }
        }
        if (autoSkip == 1) {
            HuPrcSleep(10);
            D_800FA06C_UnknownResultsScreen = 1;
        }
        HuPrcVSleep();
    }
    HuPrcSleep(10);
    D_800F9FD2_UnknownResultsScreen = 1;
    func_800726AC(0, 16);
    func_800601D4(40);
    D_800F9FD0_UnknownResultsScreen = 1;
    while (1) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_7C_UnknownResultsScreen/308A50", func_800F7754_UnknownResultsScreen);
#endif

void func_800F79C8_UnknownResultsScreen(void) {
    if (D_800F9FD0_UnknownResultsScreen != 0 && func_80072718() == 0) {
        func_800F9E68_UnknownResultsScreen();
        func_800F7614_UnknownResultsScreen();
        func_800F7B3C_UnknownResultsScreen();
        func_800F7A78_UnknownResultsScreen();
        func_8004FBB4();
        func_8004F2EC();
        func_8004F5F0();
        omOvlReturnEx(1);
    }
}

void func_800F7A3C_UnknownResultsScreen(void) {
    MBModelInit();
    func_80053020();
    func_8004FB14();
    func_8004F2AC();
    func_8004F548();
}

void func_800F7A78_UnknownResultsScreen(void) {
    MBModelClose();
    func_80053074();
}

void func_800F7A9C_UnknownResultsScreen(void) {
    func_800178A0(1);
    func_80017660(0, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    LoadBackgroundData(D_FE2310);
    func_8005049C();
}

void func_800F7B3C_UnknownResultsScreen(void) {
    func_8004A140();
    func_80049F0C();
}

void func_800F7B60_UnknownResultsScreen(s16 grp, s16 idx, s16 dx, s16 dy) {
    unk65770Obj* obj = D_800EE330[grp]->obj[idx];

    obj->unk40 += dx;
    obj->unk42 += dy;
}

void func_800F7BA0_UnknownResultsScreen(s16 grp, s16 idx, s16 x) {
    D_800EE330[grp]->obj[idx]->unk40 = x;
}

void func_800F7BCC_UnknownResultsScreen(s16 grp, s16 idx, s16 y) {
    D_800EE330[grp]->obj[idx]->unk42 = y;
}

void func_800F7BF8_UnknownResultsScreen(s16 grp, s16 idx, s32 mask) {
    unk65770Obj* obj = D_800EE330[grp]->obj[idx];

    obj->unk20 = obj->unk48 &= mask;
}

void func_800F7C30_UnknownResultsScreen(void) {
    s32 i;
    s32 j;
    f32 scale;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5;) {
            j++;
            func_80067354(D_800FA518_UnknownResultsScreen[i], j, 1.0f, 1.0f);
        }
    }
    for (scale = 1.0f; scale > 0.0f; scale -= 0.3f) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 5;) {
                j++;
                func_80067354(D_800FA518_UnknownResultsScreen[i], j, scale, scale);
            }
        }
        if (D_800F9FD1_UnknownResultsScreen == 0) {
            HuPrcVSleep();
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            func_800674BC(D_800FA518_UnknownResultsScreen[i], j + 1, 0x8000);
        }
    }
}

void func_800F7DB4_UnknownResultsScreen(void) {
    s32 i;
    s32 j;
    f32 scale;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5;) {
            j++;
            func_800F7BF8_UnknownResultsScreen(D_800FA518_UnknownResultsScreen[i], j, 0x7FFF);
        }
    }
    for (scale = 0.0f; scale < 1.0; scale += 0.3) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 5;) {
                j++;
                func_80067354(D_800FA518_UnknownResultsScreen[i], j, scale, scale);
            }
        }
        if (D_800F9FD1_UnknownResultsScreen == 0) {
            HuPrcVSleep();
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5;) {
            j++;
            func_80067354(D_800FA518_UnknownResultsScreen[i], j, 1.0f, 1.0f);
        }
    }
}

// register allocation of the rank counter (masked 2)
#ifdef NON_MATCHING
void func_800F7F38_UnknownResultsScreen(void) {
    s32 score[4];
    s32 who[4];
    s32 place[4];
    s32 rank[4];
    s16 i;
    s16 j;
    s32 tmp;
    s8 r;
    s8 k;

    for (i = 0; i < 4; i++) {
        score[i] = GwPlayer[i].coins;
        score[i] += GwPlayer[i].stars * 10000;
        who[i] = i;
    }
    for (j = 0; j < 3; j++) {
        for (i = j + 1; i < 4; i++) {
            if (score[j] < score[i]) {
                tmp = score[j];
                score[j] = score[i];
                score[i] = tmp;
                tmp = who[j];
                who[j] = who[i];
                who[i] = tmp;
            }
        }
    }
    D_800FA0E0_UnknownResultsScreen[0].rank = 0;
    D_800FA0E0_UnknownResultsScreen[0].place = who[0];
    r = 0;
    k = 0;
    for (i = 1; i < 4; i++) {
        k++;
        if (score[i - 1] != score[i]) {
            r = k;
        }
        D_800FA0E0_UnknownResultsScreen[i].rank = r;
        D_800FA0E0_UnknownResultsScreen[i].place = who[i];
    }
    for (i = 0; i < 4; i++) {
        place[i] = D_800FA0E0_UnknownResultsScreen[i].place;
        rank[i] = D_800FA0E0_UnknownResultsScreen[i].rank;
    }
    for (i = 0; i < 4; i++) {
        D_800FA0E0_UnknownResultsScreen[place[i]].place = i;
        D_800FA0E0_UnknownResultsScreen[place[i]].rank = rank[i];
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_7C_UnknownResultsScreen/308A50", func_800F7F38_UnknownResultsScreen);
#endif

void func_800F8194_UnknownResultsScreen(void) {
    s32 i;

    for (i = 0; i < MAX_PLAYERS; i++) {
        D_800FA0F0_UnknownResultsScreen[i] = GwPlayer[i].coins;
        D_800FA0D0_UnknownResultsScreen[i] = GwPlayer[i].coins_mg;
        if ((GwPlayer[i].coins + D_800FA0D0_UnknownResultsScreen[i]) > 999) {
            D_800FA0D0_UnknownResultsScreen[i] = 999 - GwPlayer[i].coins;
        }
        if ((GwPlayer[i].coins + D_800FA0D0_UnknownResultsScreen[i] < 0)) {
            D_800FA0D0_UnknownResultsScreen[i] = -GwPlayer[i].coins;
        }
        GwPlayer[i].coins_total = GwPlayer[i].coins_total + GwPlayer[i].coins_mg;
        D_800FA0D8_UnknownResultsScreen[i] = GwPlayer[i].coins_mg;
        GwPlayer[i].coins_mg = 0;
    }
}

// register allocation (masked 1)
#ifdef NON_MATCHING
void func_800F82C4_UnknownResultsScreen(void) {
    s16 nd[4];
    s16 digits[4][3];
    s16 n;
    s32 j;
    s32 i;
    void* file;

    for (i = 0; i < 4; i++) {
        digits[i][0] = ABS(D_800FA0D8_UnknownResultsScreen[i]) / 100;
        digits[i][1] = (ABS(D_800FA0D8_UnknownResultsScreen[i]) - digits[i][0] * 100) / 10;
        digits[i][2] = ABS(D_800FA0D8_UnknownResultsScreen[i]) - digits[i][0] * 100 - digits[i][1] * 10;
        nd[i] = 0;
        if (ABS(D_800FA0D8_UnknownResultsScreen[i]) >= 10) {
            nd[i] = 1;
        }
        if (ABS(D_800FA0D8_UnknownResultsScreen[i]) >= 100) {
            nd[i] = 2;
        }
    }
    for (i = 0; i < 4; i++) {
        n = 0;
        D_800FA528_UnknownResultsScreen = func_80064EF4(6, 5);
        D_800FA518_UnknownResultsScreen[i] = D_800FA528_UnknownResultsScreen;
        file = DataRead(D_800FA0D8_UnknownResultsScreen[i] >= 0 ? 0xC0015 : 0xC0016);
        D_800FA530_UnknownResultsScreen[i] = func_800678A4(file);
        DataClose(file);
        func_80067208(D_800FA528_UnknownResultsScreen, n, D_800FA530_UnknownResultsScreen[i], 0);
        func_80067598(D_800FA528_UnknownResultsScreen, n, -1);
        func_800674BC(D_800FA528_UnknownResultsScreen, n, 0x8000);
        if (D_800FA0D8_UnknownResultsScreen[i] >= 0) {
            func_80066DC4(D_800FA528_UnknownResultsScreen, n,
                          D_800F9FF4_UnknownResultsScreen[1][D_800FA0E0_UnknownResultsScreen[i].place][0] - 24,
                          D_800F9FF4_UnknownResultsScreen[1][D_800FA0E0_UnknownResultsScreen[i].place][1] - 16);
        } else {
            func_80066DC4(D_800FA528_UnknownResultsScreen, n,
                          D_800F9FF4_UnknownResultsScreen[1][D_800FA0E0_UnknownResultsScreen[i].place][0] + 24,
                          D_800F9FF4_UnknownResultsScreen[1][D_800FA0E0_UnknownResultsScreen[i].place][1] + 16);
        }
        n++;
        func_80067208(D_800FA528_UnknownResultsScreen, n, D_800FA530_UnknownResultsScreen[i], 0);
        func_800672B0(D_800FA528_UnknownResultsScreen, n, 1);
        func_80067384(D_800FA528_UnknownResultsScreen, n, 15);
        func_800674BC(D_800FA528_UnknownResultsScreen, n, 0x1000);
        func_80066DC4(D_800FA528_UnknownResultsScreen, n, 0, 0);
        func_80067598(D_800FA528_UnknownResultsScreen, n, 0);
        n++;
        for (j = 0; j < 3; j++) {
            file = DataRead(0xC0017);
            D_800FA550_UnknownResultsScreen[i][j] = func_800678A4(file);
            DataClose(file);
            func_80067208(D_800FA528_UnknownResultsScreen, n, D_800FA550_UnknownResultsScreen[i][j], 0);
            func_800672B0(D_800FA528_UnknownResultsScreen, n, 1);
            func_80067384(D_800FA528_UnknownResultsScreen, n, 14);
            func_800674BC(D_800FA528_UnknownResultsScreen, n, 0x1000);
            func_800672DC(D_800FA528_UnknownResultsScreen, n, digits[i][j], 0);
            func_80067598(D_800FA528_UnknownResultsScreen, n, 0);
            func_80067284(D_800FA528_UnknownResultsScreen, n, 0);
            if (D_800FA0D8_UnknownResultsScreen[i] == 0) {
                func_80066DC4(D_800FA528_UnknownResultsScreen, n, D_800FA070_UnknownResultsScreen[nd[i]][j], -2);
            } else if (D_800FA0D8_UnknownResultsScreen[i] > 0) {
                func_80066DC4(D_800FA528_UnknownResultsScreen, n, D_800FA070_UnknownResultsScreen[nd[i]][j] + 4, -2);
            } else {
                func_80066DC4(D_800FA528_UnknownResultsScreen, n, D_800FA070_UnknownResultsScreen[nd[i]][j] + 4, 2);
            }
            n++;
        }
        file = DataRead(0xC0017);
        D_800FA540_UnknownResultsScreen[i] = func_800678A4(file);
        DataClose(file);
        func_80067208(D_800FA528_UnknownResultsScreen, n, D_800FA540_UnknownResultsScreen[i], 0);
        func_800672B0(D_800FA528_UnknownResultsScreen, n, 1);
        func_80067384(D_800FA528_UnknownResultsScreen, n, 14);
        func_800674BC(D_800FA528_UnknownResultsScreen, n, 0x1000);
        func_80067598(D_800FA528_UnknownResultsScreen, n, 0);
        if (D_800FA0D8_UnknownResultsScreen[i] == 0) {
            func_80066DC4(D_800FA528_UnknownResultsScreen, n, -1000, -2);
            func_800672DC(D_800FA528_UnknownResultsScreen, n, 10, 0);
        } else if (D_800FA0D8_UnknownResultsScreen[i] > 0) {
            func_800672DC(D_800FA528_UnknownResultsScreen, n, 11, 0);
            func_80066DC4(D_800FA528_UnknownResultsScreen, n, D_800FA070_UnknownResultsScreen[nd[i]][2 - nd[i]] - 4, -2);
        } else {
            func_800672DC(D_800FA528_UnknownResultsScreen, n, 12, 0);
            func_80066DC4(D_800FA528_UnknownResultsScreen, n, D_800FA070_UnknownResultsScreen[nd[i]][2 - nd[i]] - 4, 2);
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            func_800674BC(D_800FA518_UnknownResultsScreen[i], j + 1, 0x8000);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_7C_UnknownResultsScreen/308A50", func_800F82C4_UnknownResultsScreen);
#endif

// scheduling of the sprite counter init (masked 2)
#ifdef NON_MATCHING
void func_800F8B44_UnknownResultsScreen(void) {
    s16 left[4];
    s16 nd[4];
    s16 digits[4][3];
    s32 i;
    s32 j;
    s16 n;

    for (i = 0; i < 4; i++) {
        left[i] = D_800FA0D8_UnknownResultsScreen[i] - (GwPlayer[i].coins - D_800FA0F0_UnknownResultsScreen[i]);
        digits[i][0] = ABS(left[i]) / 100;
        digits[i][1] = (ABS(left[i]) - digits[i][0] * 100) / 10;
        digits[i][2] = ABS(left[i]) - digits[i][0] * 100 - digits[i][1] * 10;
        nd[i] = 0;
        if (ABS(left[i]) >= 10) {
            nd[i] = 1;
        }
        if (ABS(left[i]) >= 100) {
            nd[i] = 2;
        }
    }
    for (i = 0, n = 2; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            func_800672DC(D_800FA518_UnknownResultsScreen[i], n, digits[i][j], 0);
            if (left[i] == 0) {
                if (D_800FA0D8_UnknownResultsScreen[i] >= 0) {
                    func_80066DC4(D_800FA518_UnknownResultsScreen[i], n, D_800FA084_UnknownResultsScreen[nd[i]][j], -2);
                } else {
                    func_80066DC4(D_800FA518_UnknownResultsScreen[i], n, D_800FA084_UnknownResultsScreen[nd[i]][j], 2);
                }
            } else if (left[i] > 0) {
                func_80066DC4(D_800FA518_UnknownResultsScreen[i], n, D_800FA084_UnknownResultsScreen[nd[i]][j] + 4, -2);
            } else {
                func_80066DC4(D_800FA518_UnknownResultsScreen[i], n, D_800FA084_UnknownResultsScreen[nd[i]][j] + 4, 2);
            }
            n++;
        }
        if (left[i] == 0) {
            func_80066DC4(D_800FA518_UnknownResultsScreen[i], n, -1000, -2);
            func_800672DC(D_800FA518_UnknownResultsScreen[i], n, 10, 0);
        } else if (left[i] > 0) {
            func_800672DC(D_800FA518_UnknownResultsScreen[i], n, 11, 0);
            func_80066DC4(D_800FA518_UnknownResultsScreen[i], n, D_800FA084_UnknownResultsScreen[nd[i]][2 - nd[i]] - 4, -2);
        } else {
            func_800672DC(D_800FA518_UnknownResultsScreen[i], n, 12, 0);
            func_80066DC4(D_800FA518_UnknownResultsScreen[i], n, D_800FA084_UnknownResultsScreen[nd[i]][2 - nd[i]] - 4, 2);
        }
        n = 2;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_7C_UnknownResultsScreen/308A50", func_800F8B44_UnknownResultsScreen);
#endif

/* A player's rank or place changed with the minigame coins. */
#define MOVED(i)                                                                                         \
    (newRank[D_800FA0E8_UnknownResultsScreen[i].place] != oldRank[D_800FA0E8_UnknownResultsScreen[i].place] || \
     D_800FA0E8_UnknownResultsScreen[i].rank != D_800FA0E0_UnknownResultsScreen[i].rank)

// spill/hoist of speed * 25 and one delay slot (3 instructions short)
#ifdef NON_MATCHING
void func_800F90A4_UnknownResultsScreen(void) {
    s16 delay[4];
    s16 off[4];
    f32 ang[4];
    s8 taken[4];
    s8 newRank[4];
    s8 oldRank[4];
    u16 speed;
    s32 spd;
    s32 spd2;
    s32 p;
    s32 i;
    s32 j;
    s32 n;
    s32 t;
    s32 d;

    p = 0;
    for (i = 0; i < 4; i++) {
        D_800FA0E8_UnknownResultsScreen[i] = D_800FA0E0_UnknownResultsScreen[i];
    }
    func_800F7F38_UnknownResultsScreen();
    speed = (D_800F9FD1_UnknownResultsScreen != 0) ? 3 : 1;
    for (i = 0; i < 4; i++) {
        oldRank[D_800FA0E8_UnknownResultsScreen[i].place] = D_800FA0E8_UnknownResultsScreen[i].rank;
        newRank[D_800FA0E0_UnknownResultsScreen[i].place] = D_800FA0E0_UnknownResultsScreen[i].rank;
    }

    /* Slide the players whose place changes out to the right. */
    t = 0;
    spd = speed;
    do {
        for (i = 0, n = 0; i < 4; i++) {
            d = func_800AEAC0(t) * 25.0f * spd;
            if (MOVED(i)) {
                func_800F7B60_UnknownResultsScreen(D_800FA180_UnknownResultsScreen, i + 1, d, 0);
                func_800F7B60_UnknownResultsScreen(D_800FA510_UnknownResultsScreen, i + 1, d * 2, 0);
                func_800F7B60_UnknownResultsScreen(D_800FA198_UnknownResultsScreen, i + 1, d, 0);
                func_800F7B60_UnknownResultsScreen(D_800FA1A0_UnknownResultsScreen, i + 1, d, 0);
                func_800F7B60_UnknownResultsScreen(D_800FA4E8_UnknownResultsScreen[i], 0, d, 0);
                func_800F7B60_UnknownResultsScreen(D_800FA4E8_UnknownResultsScreen[4 + i], 0, d, 0);
            }
            for (j = 0; j < 3; j++) {
                if (MOVED(i)) {
                    func_800F7B60_UnknownResultsScreen(D_800FA508_UnknownResultsScreen, n + 1, d, 0);
                }
                n++;
            }
        }
        HuPrcVSleep();
        t += spd * 5;
    } while (t < 90);

    /* Give each of them the first free place from its new rank down. */
    for (i = 0; i < 4; i++) {
        if (MOVED(i)) {
            taken[D_800FA0E8_UnknownResultsScreen[i].place] = 0;
        } else {
            taken[D_800FA0E8_UnknownResultsScreen[i].place] = 1;
        }
    }
    for (i = 0, n = 0; i < 4; i++) {
        if (MOVED(i)) {
            for (p = D_800FA0E0_UnknownResultsScreen[i].rank; p < 4; p++) {
                if (taken[p] == 0) {
                    taken[p] = 1;
                    break;
                }
            }
            if (p >= 4) {
                p = 0;
            }
            func_800F7BCC_UnknownResultsScreen(D_800FA180_UnknownResultsScreen, i + 1, D_800F9FF4_UnknownResultsScreen[1][p][1]);
            func_800F7BCC_UnknownResultsScreen(D_800FA510_UnknownResultsScreen, i + 1, D_800F9FF4_UnknownResultsScreen[1][p][1] * 2);
            func_800F7BCC_UnknownResultsScreen(D_800FA198_UnknownResultsScreen, i + 1, D_800F9FF4_UnknownResultsScreen[2][p][1]);
            func_800F7BCC_UnknownResultsScreen(D_800FA1A0_UnknownResultsScreen, i + 1, D_800F9FF4_UnknownResultsScreen[3][p][1]);
            func_800F7BCC_UnknownResultsScreen(D_800FA4E8_UnknownResultsScreen[i], 0, D_800F9FF4_UnknownResultsScreen[4][p][1]);
            func_800F7BCC_UnknownResultsScreen(D_800FA4E8_UnknownResultsScreen[4 + i], 0, D_800F9FF4_UnknownResultsScreen[4][p][1]);
        }
        for (j = 0; j < 3; j++) {
            if (MOVED(i)) {
                func_800F7BCC_UnknownResultsScreen(D_800FA508_UnknownResultsScreen, n + 1, D_800F9FF4_UnknownResultsScreen[3][p][1] + 4);
            }
            n++;
        }
        if (D_800FA0E8_UnknownResultsScreen[i].rank == D_800FA0E0_UnknownResultsScreen[i].rank) {
            func_800672DC(D_800FA180_UnknownResultsScreen, i + 1, 0, 0);
        } else if (D_800FA0E8_UnknownResultsScreen[i].rank > D_800FA0E0_UnknownResultsScreen[i].rank) {
            func_800672DC(D_800FA180_UnknownResultsScreen, i + 1, 1, 0);
        } else {
            func_800672DC(D_800FA180_UnknownResultsScreen, i + 1, 2, 0);
        }
    }

    /* Slide them back in, one rank after another. */
    for (i = 0; i < 4; i++) {
        if (MOVED(i)) {
            delay[i] = D_800FA0E0_UnknownResultsScreen[i].rank * 8;
        } else {
            delay[i] = -1;
        }
        ang[i] = 0.0f;
    }
    t = 0;
    spd2 = speed;
    do {
        for (i = 0; i < 4; i++) {
            if (delay[i] < 0) {
                continue;
            }
            if (D_800F9FD1_UnknownResultsScreen != 0) {
                delay[i] = 0;
            }
            if (delay[i] < t) {
                off[i] = -func_800AEAC0(ang[i]) * (spd2 * 25);
                func_800F7B60_UnknownResultsScreen(D_800FA180_UnknownResultsScreen, i + 1, off[i], 0);
                func_800F7B60_UnknownResultsScreen(D_800FA510_UnknownResultsScreen, i + 1, off[i] * 2, 0);
                func_800F7B60_UnknownResultsScreen(D_800FA198_UnknownResultsScreen, i + 1, off[i], 0);
                func_800F7B60_UnknownResultsScreen(D_800FA1A0_UnknownResultsScreen, i + 1, off[i], 0);
                func_800F7B60_UnknownResultsScreen(D_800FA4E8_UnknownResultsScreen[i], 0, off[i], 0);
                func_800F7B60_UnknownResultsScreen(D_800FA4E8_UnknownResultsScreen[4 + i], 0, off[i], 0);
                for (j = 0; j < 3; j++) {
                    func_800F7B60_UnknownResultsScreen(D_800FA508_UnknownResultsScreen, i * 3 + j + 1, off[i], 0);
                }
                ang[i] += spd2 * 5;
                if (ang[i] >= 90.0f) {
                    delay[i] = -1;
                    if (D_800F9FD1_UnknownResultsScreen == 0) {
                        func_80060F04(i, 2, 3, 10);
                    }
                }
            }
        }
        HuPrcVSleep();
        t++;
    } while (delay[0] >= 0 || delay[1] >= 0 || delay[2] >= 0 || delay[3] >= 0);

    /* Show the new place sprites. */
    for (i = 0, n = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (D_800FA0E0_UnknownResultsScreen[j].rank == i) {
                func_80066DC4(D_800FA168_UnknownResultsScreen, n + 1,
                              D_800F9FF4_UnknownResultsScreen[0][D_800FA0E0_UnknownResultsScreen[j].place][0],
                              D_800F9FF4_UnknownResultsScreen[0][D_800FA0E0_UnknownResultsScreen[j].place][1]);
            } else {
                func_80066DC4(D_800FA168_UnknownResultsScreen, n + 1, -1000, D_800F9FF4_UnknownResultsScreen[0][j][1]);
            }
            n++;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_7C_UnknownResultsScreen/308A50", func_800F90A4_UnknownResultsScreen);
#endif

// decomp-permuter
void func_800F9A98_UnknownResultsScreen(s16 steps)
{
  int new_var;
  s16 i;
  f32 f;
  for (i = 0; i < 4; i++)
  {
    new_var = steps;
    if (!((D_800FA0D0_UnknownResultsScreen[i] >= 0) ? (steps < D_800FA0D0_UnknownResultsScreen[i]) : (new_var < (-D_800FA0D0_UnknownResultsScreen[i]))))
    {
      if (D_800FA0D0_UnknownResultsScreen[i] >= 0)
      {
        D_800FA580_UnknownResultsScreen[i] = 1;
      }
      else
      {
        D_800FA580_UnknownResultsScreen[i] = -1;
      }
    }
    else
    {
      f = ((f32) D_800FA0D0_UnknownResultsScreen[i]) / new_var;
      if (D_800FA0D0_UnknownResultsScreen[i] >= 0)
      {
        f += 0.5f;
      }
      else
      {
        f -= 0.5f;
      }
      D_800FA580_UnknownResultsScreen[i] = f;
    }
    D_800FA588_UnknownResultsScreen[i] = 0;
  }

}

s8 func_800F9BCC_UnknownResultsScreen(void) {
    s8 upDone = 0;
    s8 downDone = 0;
    s8 upSound = 0;
    s8 downSound = 0;
    s8 i = 0;
    s8 done = 0;
    s32 n;
    s16* cur;
    s16* goal;
    s32 pad[4]; /* unused: retail frame size */

    for (; i < 4; i++) {
        if (D_800FA588_UnknownResultsScreen[i] != D_800FA0D0_UnknownResultsScreen[i]) {
            n = abs(D_800FA588_UnknownResultsScreen[i] + D_800FA580_UnknownResultsScreen[i]);
            if ((D_800FA0D0_UnknownResultsScreen[i] >= 0) ? (D_800FA0D0_UnknownResultsScreen[i] < n)
                                                          : (-D_800FA0D0_UnknownResultsScreen[i] < n)) {
                cur = &D_800FA588_UnknownResultsScreen[i];
                AdjustPlayerCoins(i, -*cur + *(goal = &D_800FA0D0_UnknownResultsScreen[i]));
                *cur = *goal;
            } else {
                D_800FA588_UnknownResultsScreen[i] += D_800FA580_UnknownResultsScreen[i];
                AdjustPlayerCoins(i, D_800FA580_UnknownResultsScreen[i]);
            }
            if (upDone == 0 && D_800FA580_UnknownResultsScreen[i] > 0) {
                if (D_800FA096_UnknownResultsScreen < 2) {
                    upSound = 1;
                }
                upDone = 1;
                if (++D_800FA096_UnknownResultsScreen >= 3) {
                    D_800FA096_UnknownResultsScreen = 0;
                }
            }
            if (downDone == 0 && D_800FA580_UnknownResultsScreen[i] < 0) {
                if (D_800FA097_UnknownResultsScreen < 2) {
                    downSound = 1;
                }
                downDone = 1;
                if (++D_800FA097_UnknownResultsScreen >= 3) {
                    D_800FA097_UnknownResultsScreen = 0;
                }
            }
        } else {
            done++;
        }
    }
    if (upSound == 1) {
        PlaySound(0xFC);
    } else if (downSound == 1) {
        PlaySound(0x57);
    }
    return done > 3;
}

void func_800F9E68_UnknownResultsScreen(void) {
    s16 i;
    s16 j;

    for (i = 0; i < 4; i++) {
        func_80067704(D_800FA530_UnknownResultsScreen[i]);
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            func_80067704(D_800FA550_UnknownResultsScreen[i][j]);
        }
    }
    for (i = 0; i < 4; i++) {
        func_80067704(D_800FA540_UnknownResultsScreen[i]);
    }
    for (i = 0; i < 4; i++) {
        func_80064D38(D_800FA518_UnknownResultsScreen[i]);
    }
}
