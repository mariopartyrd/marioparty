#include "common.h"
#include "engine/pad.h"

/* Mini-Game Island: the "miss" / "clear" screen after an island minigame. Shows the lives and
   coins won or lost, counts the minigame coins into the quest's coins (a 1-up per 100), and on a
   lost last life asks whether to continue. */

#define ABS(x) ((x) < 0 ? -(x) : (x))

/* The head of 42E40.c's SpriteAnimWork (func_800429CC's result); no pointers before 0x10. */
typedef struct MissSpriteAnim {
    /* 0x00 */ u16 flags;
    /* 0x02 */ s16 frame;
    /* 0x04 */ s16 count;
    /* 0x06 */ u16 attr;
    /* 0x08 */ s16 x;
    /* 0x0A */ s16 y;
} MissSpriteAnim;

typedef struct unkMissStruct {
/* 0x00 */ s16 unk_00;
} unkMissStruct;

s32 func_8005B950(void);
void func_800607E8(void);
void func_8004FBB4(void);
void func_8005C384(void);
void func_8005C390(void);
void func_8005C3CC(void);
void func_800532E0(void);
void func_8004FB14(void);
void func_8004F548(void);
void func_8005049C(void);
void func_80056700(void);
void func_800565B4(void);
void func_80053074(void);
void MBModelClose(void);
void func_800532F4(void);
void func_80067284(s16, s16, f32);
void* func_800429CC(s16, s16);
void func_80042B10(MissSpriteAnim*);

void func_800F6708_MinigameIslandMISS(void);
void func_800F67A4_MinigameIslandMISS(void);
void func_800F7608_MinigameIslandMISS(void);
void func_800F7638_MinigameIslandMISS(void);
void func_800F7724_MinigameIslandMISS(void);
void func_800F7804_MinigameIslandMISS(void);
void func_800F7848_MinigameIslandMISS(void);
void func_800F78E8_MinigameIslandMISS(void);
void func_800F790C_MinigameIslandMISS(void);
void func_800F795C_MinigameIslandMISS(void);
void func_800F7C7C_MinigameIslandMISS(void);
void func_800F7D64_MinigameIslandMISS(void);
void func_800F8038_MinigameIslandMISS(s8);
void func_800F8180_MinigameIslandMISS(s8);
void func_800F82C8_MinigameIslandMISS(void);
void func_800F8448_MinigameIslandMISS(void);
s32 func_800F85C8_MinigameIslandMISS(s32);
void func_800F8768_MinigameIslandMISS(void);
void func_800F8898_MinigameIslandMISS(void);
void func_800F8E30_MinigameIslandMISS(void);
void func_800F8F8C_MinigameIslandMISS(void);
s8 func_800F9008_MinigameIslandMISS(void);
void func_800F9020_MinigameIslandMISS(void);
s32 func_800F90F0_MinigameIslandMISS(s16);

/* .data */
s8 D_800F9120_MinigameIslandMISS = 0; /* the screen is finished */
s8 D_800F9121_MinigameIslandMISS = 0; /* A/Start pressed: skip the waits */
s8 D_800F9122_MinigameIslandMISS = 1; /* skipping is not allowed */
s8 D_800F9123_MinigameIslandMISS = 0; /* the continue question was answered */
s8 D_800F9124_MinigameIslandMISS = -1; /* continue choice */
s8 D_800F9125_MinigameIslandMISS = 0; /* stop the music fade */
s8 D_800F9126_MinigameIslandMISS = 0;
s8 D_800F9127_MinigameIslandMISS = 0; /* the bonus 1-up is shown */
s16 D_800F9128_MinigameIslandMISS = 0; /* minigame coins counted so far */
/* Per mode (0 = clear, 1 = miss): the result banner files. */
s32 D_800F912C_MinigameIslandMISS[2][2] = { { 0x000D0000, 0x000D0001 }, { 0x000B0060, 0x000B0061 } };
s32 D_800F913C_MinigameIslandMISS[2] = { 0x000D0002, 0x000D0003 };
/* {x, y} of the lives and coins counters. */
s16 D_800F9144_MinigameIslandMISS[2][2] = { { 80, 60 }, { 264, 60 } };
/* Per number of digits - 1: the x offset of each digit (-1000 hides it). */
s16 D_800F914C_MinigameIslandMISS[3][3] = { { -1000, -1000, 0 }, { -1000, -4, 4 }, { -8, 0, 8 } };
s16 D_800F9160_MinigameIslandMISS[3][3] = { { -1000, -1000, 0 }, { -1000, -4, 4 }, { -8, 0, 8 } };
/* Per minigame: nonzero when it also changes the lives counter. */
s8 D_800F9174_MinigameIslandMISS[60] = {
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0,
};
/* Per minigame: the coins needed to clear it. */
unkMissStruct D_800F91B0_MinigameIslandMISS[56] = {
    { 10 }, { 0 },  { 1 },  { 10 }, { 10 }, { 10 }, { 0 },  { 5 },  { 0 },  { 10 }, { 10 }, { 10 },
    { 10 }, { 10 }, { 10 }, { 25 }, { 1 },  { 15 }, { 10 }, { 10 }, { 10 }, { 10 }, { 10 }, { 10 },
    { 10 }, { 10 }, { 10 }, { 0 },  { 15 }, { 10 }, { 10 }, { 15 }, { 10 }, { 10 }, { 10 }, { 20 },
    { 0 },  { 10 }, { 10 }, { 10 }, { 10 }, { 10 }, { 10 }, { 30 }, { 10 }, { 10 }, { 10 }, { 10 },
    { 0 },  { 15 }, { 15 }, { 15 }, { 15 }, { 0 },  { 20 }, { 10 },
};

/* .bss. The s32 slots hold s16 sprite/group ids (stored as words, read as their low half). */
extern s16 D_800F9250_MinigameIslandMISS; /* 0 = cleared, 1 = missed */
extern s16 D_800F9252_MinigameIslandMISS; /* coins before */
extern s16 D_800F9254_MinigameIslandMISS; /* lives before */
extern s32 D_800F9258_MinigameIslandMISS;
extern MissSpriteAnim* D_800F925C_MinigameIslandMISS;
extern s32 D_800F9260_MinigameIslandMISS;
extern s32 D_800F9264_MinigameIslandMISS;
extern s32 D_800F9268_MinigameIslandMISS;
extern s32 D_800F926C_MinigameIslandMISS;
extern s32 D_800F9270_MinigameIslandMISS;
extern s32 D_800F9278_MinigameIslandMISS;
extern s32 D_800F927C_MinigameIslandMISS;
extern s32 D_800F9284_MinigameIslandMISS[2];
extern s32 D_800F928C_MinigameIslandMISS;
extern s32 D_800F9290_MinigameIslandMISS[2];
extern s32 D_800F9298_MinigameIslandMISS[2][3];
extern s32 D_800F92B0_MinigameIslandMISS[3]; /* [2] is splat's D_800F92B8 */

void func_800F65E0_MinigameIslandMISS(void) {
    if (func_8005B950() != 0) {
        D_800F9126_MinigameIslandMISS = 1;
    } else {
        D_800F9126_MinigameIslandMISS = 0;
    }
    ClearBoardFeatureFlag(0x2D);
    if (func_800F90F0_MinigameIslandMISS(GwSystem.unk_1E) != 0) {
        D_800F9250_MinigameIslandMISS = 0;
        SetBoardFeatureFlag(0x2F);
    } else {
        D_800F9250_MinigameIslandMISS = 1;
        ClearBoardFeatureFlag(0x2F);
    }
    D_800F9252_MinigameIslandMISS = GwQuest.coinNum;
    D_800F9254_MinigameIslandMISS = GwQuest.lifeNum;
    omInitObjMan(0x14, 0x14);
    func_800607E8();
    func_800F7848_MinigameIslandMISS();
    func_800F7804_MinigameIslandMISS();
    omAddPrcObj(func_800F7638_MinigameIslandMISS, 0x300, 0x2500, 0x1000);
    omAddObj(5, 0, 0, -1, func_800F7724_MinigameIslandMISS);
    omAddObj(5, 0, 0, -1, func_800F6708_MinigameIslandMISS);
}

void func_800F6708_MinigameIslandMISS(void) {
    s8 i;

    if (D_800F9122_MinigameIslandMISS != 1) {
        for (i = 0; i < MAX_PLAYERS; i++) {
            if (!(GwPlayer[i].flags & 1)) {
                if (ContBtn[GwPlayer[i].port] & 0x9000) {
                    D_800F9121_MinigameIslandMISS = 1;
                }
            }
        }
    }
}

// file id select is if-converted differently; retail reloads vals[i] in the sign test (masked 39)
#ifdef NON_MATCHING
void func_800F67A4_MinigameIslandMISS(void) {
    s16 nd[2];
    s16 digits[2][3];
    s16 vals[2];
    s32 group;
    s16 i;
    s16 j;
    s16 k;
    void* file;
    s32 id;

    func_800565B4();
    func_8006CEA0();
    D_800F9258_MinigameIslandMISS = func_8006D010(0, 0, 320, 240, 0, 0);
    func_8006E154(D_800F9258_MinigameIslandMISS, 200);
    func_800714F0(D_800F9258_MinigameIslandMISS, 0, 0, 0);
    switch (D_800F9250_MinigameIslandMISS) {
    case 0:
        D_800F925C_MinigameIslandMISS = func_800429CC(GwPlayer[0].character, 0);
        break;
    case 1:
        D_800F925C_MinigameIslandMISS = func_800429CC(GwPlayer[0].character, 1);
        break;
    }
    D_800F925C_MinigameIslandMISS->flags |= 2;
    D_800F925C_MinigameIslandMISS->x = 160;
    D_800F925C_MinigameIslandMISS->y = 100;
    D_800F925C_MinigameIslandMISS->attr = 0x10;

    D_800F9264_MinigameIslandMISS = func_80064EF4(5, 5);
    func_80066DC4(D_800F9264_MinigameIslandMISS, 0, 0, 0);
    file = DataRead(0xA0163);
    D_800F9268_MinigameIslandMISS = func_800678A4(file);
    DataClose(file);
    func_80067208(D_800F9264_MinigameIslandMISS, 1, D_800F9268_MinigameIslandMISS, 0);
    func_800672B0(D_800F9264_MinigameIslandMISS, 1, 1);
    func_80067384(D_800F9264_MinigameIslandMISS, 1, 0x11);
    func_800674BC(D_800F9264_MinigameIslandMISS, 1, 0x1000);
    func_80066DC4(D_800F9264_MinigameIslandMISS, 1, 160, 100);
    func_80067284(D_800F9264_MinigameIslandMISS, 1, 0);

    D_800F926C_MinigameIslandMISS = func_80064EF4(3, 5);
    func_80066DC4(D_800F926C_MinigameIslandMISS, 0, 0, 0);
    file = DataRead(D_800F912C_MinigameIslandMISS[D_800F9250_MinigameIslandMISS][0]);
    D_800F9270_MinigameIslandMISS = func_800678A4(file);
    DataClose(file);
    func_80067208(D_800F926C_MinigameIslandMISS, 1, D_800F9270_MinigameIslandMISS, 0);
    func_800672B0(D_800F926C_MinigameIslandMISS, 1, 1);
    func_80067384(D_800F926C_MinigameIslandMISS, 1, 0x10);
    func_800674BC(D_800F926C_MinigameIslandMISS, 1, 0x9000);
    func_80066DC4(D_800F926C_MinigameIslandMISS, 1, 160, 160);
    func_80067284(D_800F926C_MinigameIslandMISS, 1, 0);

    D_800F9278_MinigameIslandMISS = func_80064EF4(3, 5);
    func_80066DC4(D_800F9278_MinigameIslandMISS, 0, 0, 0);
    file = DataRead(D_800F913C_MinigameIslandMISS[0]);
    D_800F927C_MinigameIslandMISS = func_800678A4(file);
    DataClose(file);
    func_80067208(D_800F9278_MinigameIslandMISS, 1, D_800F927C_MinigameIslandMISS, 0);
    func_800672B0(D_800F9278_MinigameIslandMISS, 1, 1);
    func_80067384(D_800F9278_MinigameIslandMISS, 1, 0x10);
    func_800674BC(D_800F9278_MinigameIslandMISS, 1, 0x9000);
    func_80066DC4(D_800F9278_MinigameIslandMISS, 1, 160, 160);
    func_80067284(D_800F926C_MinigameIslandMISS, 1, 0); /* sic: retail sets the clear banner again */

    vals[0] = GwQuest.lifeNum - D_800F9254_MinigameIslandMISS;
    vals[1] = GwPlayer[0].coins_mg;
    for (i = 0; i < 2; i++) {
        digits[i][0] = ABS(vals[i]) / 100;
        digits[i][1] = (ABS(vals[i]) - digits[i][0] * 100) / 10;
        digits[i][2] = ABS(vals[i]) - digits[i][0] * 100 - digits[i][1] * 10;
        nd[i] = 0;
        if (ABS(vals[i]) >= 10) {
            nd[i] = 1;
        }
        if (ABS(vals[i]) >= 100) {
            nd[i] = 2;
        }
    }

    for (i = 0; i < 2; i++) {
        k = 0;
        group = func_80064EF4(6, 5);
        D_800F92B0_MinigameIslandMISS[i] = group;
        if (i != 0 && vals[i] >= 0) {
            id = 0xD0004;
        } else {
            id = 0xC0016;
        }
        file = DataRead(id);
        D_800F9284_MinigameIslandMISS[i] = func_800678A4(file);
        DataClose(file);
        func_80067208(group, k, D_800F9284_MinigameIslandMISS[i], 0);
        func_80067598(group, k, -1);
        func_800674BC(group, k, 0x8000);
        func_80066DC4(group, k, D_800F9144_MinigameIslandMISS[i][0], D_800F9144_MinigameIslandMISS[i][1]);
        k++;
        func_80067208(group, k, D_800F9284_MinigameIslandMISS[i], 0);
        func_800672B0(group, k, 1);
        func_80067384(group, k, 0xF);
        func_800674BC(group, k, 0x9000);
        func_80066DC4(group, k, 0, 0);
        func_80067598(group, k, 0);
        k++;
        for (j = 0; j < 3; j++, k++) {
            file = DataRead(0xC0017);
            D_800F9298_MinigameIslandMISS[i][j] = func_800678A4(file);
            DataClose(file);
            func_80067208(group, k, D_800F9298_MinigameIslandMISS[i][j], 0);
            func_800672B0(group, k, 1);
            func_80067384(group, k, 0xE);
            func_800674BC(group, k, 0x9000);
            func_800672DC(group, k, digits[i][j], 0);
            func_80067598(group, k, 0);
            func_80067284(group, k, 0);
            if (i == 0) {
                if (vals[0] == 0) {
                    func_80066DC4(group, k, D_800F914C_MinigameIslandMISS[nd[0]][j], 2);
                } else {
                    func_80066DC4(group, k, D_800F914C_MinigameIslandMISS[nd[i]][j] + 4, 2);
                }
            } else if (D_800F9250_MinigameIslandMISS == 0) {
                if (vals[i] == 0) {
                    func_80066DC4(group, k, D_800F914C_MinigameIslandMISS[nd[i]][j], 2);
                } else {
                    func_80066DC4(group, k, D_800F914C_MinigameIslandMISS[nd[i]][j] + 4, 2);
                }
            } else {
                func_800674F4(group, k, 0xFF, 0, 0);
                func_80066DC4(group, k, D_800F914C_MinigameIslandMISS[nd[i]][j], 2);
            }
        }
        file = DataRead(0xC0017);
        D_800F9290_MinigameIslandMISS[i] = func_800678A4(file);
        DataClose(file);
        func_80067208(group, k, D_800F9290_MinigameIslandMISS[i], 0);
        func_800672B0(group, k, 1);
        func_80067384(group, k, 0xE);
        func_800674BC(group, k, 0x9000);
        func_80067598(group, k, 0);
        func_80067284(group, k, 0);
        if (i == 0) {
            if (vals[0] == 0) {
                func_80066DC4(group, k, -1000, 2);
                func_800672DC(group, k, 0xA, 0);
            } else {
                if (vals[i] > 0) {
                    func_800672DC(group, k, 0xB, 0);
                } else {
                    func_800672DC(group, k, 0xC, 0);
                }
                func_80066DC4(group, k, D_800F914C_MinigameIslandMISS[nd[i]][2 - nd[i]] - 4, 2);
            }
        } else if (D_800F9250_MinigameIslandMISS == 0 && vals[i] != 0) {
            if (vals[i] > 0) {
                func_800672DC(group, k, 0xB, 0);
            } else {
                func_800672DC(group, k, 0xC, 0);
            }
            func_80066DC4(group, k, D_800F914C_MinigameIslandMISS[nd[i]][2 - nd[i]] - 4, 2);
        } else {
            func_80066DC4(group, k, -1000, 2);
            func_800672DC(group, k, 0xA, 0);
        }
    }

    group = func_80064EF4(6, 5);
    D_800F92B0_MinigameIslandMISS[2] = group;
    file = DataRead(0xD0004);
    D_800F928C_MinigameIslandMISS = func_800678A4(file);
    DataClose(file);
    func_80067208(group, 0, D_800F928C_MinigameIslandMISS, 0);
    func_80067598(group, 0, -1);
    func_800674BC(group, 0, 0x8000);
    func_80066DC4(group, 0, D_800F9144_MinigameIslandMISS[0][0], D_800F9144_MinigameIslandMISS[0][1]);
    func_80067208(group, 1, D_800F928C_MinigameIslandMISS, 0);
    func_800672B0(group, 1, 1);
    func_80067384(group, 1, 0xF);
    func_800674BC(group, 1, 0x9000);
    func_80066DC4(group, 1, 0, 0);
    func_80067598(group, 1, 0);
    file = DataRead(0xD0005);
    D_800F9260_MinigameIslandMISS = func_800678A4(file);
    DataClose(file);
    func_80067208(group, 2, D_800F9260_MinigameIslandMISS, 0);
    func_800672B0(group, 2, 1);
    func_80067384(group, 2, 0xE);
    func_800674BC(group, 2, 0x9000);
    func_800672DC(group, 2, 0, 0);
    func_80067598(group, 2, 0);
    func_80067284(group, 2, 0);
    func_80066DC4(group, 2, 0, 2);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_7D_MinigameIslandMISS/30C540", func_800F67A4_MinigameIslandMISS);
#endif

void func_800F7608_MinigameIslandMISS(void) {
    func_80056700();
    func_80070D90(D_800F9258_MinigameIslandMISS);
    func_80070ED4();
}

void func_800F7638_MinigameIslandMISS(void) {
    s16 i;

    D_800F9122_MinigameIslandMISS = 0;
    func_800F67A4_MinigameIslandMISS();
    SetFadeInTypeAndTime(0, 0x10);
    if (func_80072718() != 0) {
        HuPrcVSleep();
    }
    func_800F795C_MinigameIslandMISS();
    i = 0;
    while (((D_800F9121_MinigameIslandMISS == 1) | (i >= 60)) == 0) {
        i++;
        HuPrcVSleep();
    }
    D_800F9122_MinigameIslandMISS = 1;
    D_800F9125_MinigameIslandMISS = 1;
    func_80060398(0x28);
    func_800601D4(0x28);
    func_800726AC(0, 0x10);
    D_800F9120_MinigameIslandMISS = 1;
    while (1) {
        HuPrcVSleep();
    }
}

void func_800F7724_MinigameIslandMISS(void) {
    if (D_800F9120_MinigameIslandMISS != 0 && func_80072718() == 0) {
        func_800F7608_MinigameIslandMISS();
        func_800F8E30_MinigameIslandMISS();
        func_800F78E8_MinigameIslandMISS();
        func_8004FBB4();
        func_8004F2EC();
        func_8004F5F0();
        GwPlayer[0].coins_mg = 0;
        switch (D_800F9124_MinigameIslandMISS) {
        case 0:
            func_8005C3CC();
            break;
        case 2:
            func_8005C390();
            break;
        case 1:
        case 3:
            func_8005C384();
            break;
        }
        omOvlReturnEx(1);
    }
}

void func_800F7804_MinigameIslandMISS(void) {
    func_800532E0();
    MBModelInit();
    func_80053020();
    func_8004FB14();
    func_8004F2AC();
    func_8004F548();
}

void func_800F7848_MinigameIslandMISS(void) {
    func_800178A0(1);
    func_80017660(0, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    LoadBackgroundData(D_FE2310);
    func_8005049C();
}

void func_800F78E8_MinigameIslandMISS(void) {
    func_8004A140();
    func_80049F0C();
}

void func_800F790C_MinigameIslandMISS(void) {
    switch (D_800F9250_MinigameIslandMISS) {
    case 0:
        if (D_800F9126_MinigameIslandMISS == 0) {
            func_80060128(0x33);
        } else {
            func_80060128(0x35);
        }
        break;
    case 1:
        func_80060128(0x34);
        break;
    }
}

void func_800F795C_MinigameIslandMISS(void) {
    s16 i;
    s8 cont;

    func_800F790C_MinigameIslandMISS();
    switch (D_800F9250_MinigameIslandMISS) {
    case 0:
        if (D_800F9126_MinigameIslandMISS == 0) {
            omAddPrcObj(func_800F9020_MinigameIslandMISS, 0x300, 0x2000, 0);
        }
    case 1:
        HuPrcSleep(0x24);
        break;
    }
    func_80067480(D_800F926C_MinigameIslandMISS, 1, 0x8000);
    switch (D_800F9250_MinigameIslandMISS) {
    case 0:
        PlaySound(0x441);
        break;
    case 1:
        PlaySound(0x422);
        break;
    }
    omAddPrcObj(func_800F8F8C_MinigameIslandMISS, 0x300, 0x2500, 0);
    D_800F925C_MinigameIslandMISS->flags &= ~2;
    while (1) {
        if (!(D_800F925C_MinigameIslandMISS->flags & 1)) {
            break;
        }
        HuPrcVSleep();
    }
    if (D_800F9250_MinigameIslandMISS == 0) {
        HuPrcSleep(30);
    } else {
        HuPrcSleep(20);
    }
    func_80060128(0x16);
    func_80060214(0);
    omAddPrcObj(func_800F7C7C_MinigameIslandMISS, 0x300, 0x2500, 0);
    if (D_800F9250_MinigameIslandMISS == 0 && D_800F9126_MinigameIslandMISS == 0) {
        while (D_800F9127_MinigameIslandMISS == 0) {
            HuPrcVSleep();
        }
    }
    cont = 0;
    switch (D_800F9250_MinigameIslandMISS) {
    case 0:
        func_800F8038_MinigameIslandMISS(1);
        HuPrcSleep(30);
        for (i = 0; i < 30; i++) {
            if (D_800F9121_MinigameIslandMISS == 1) {
                break;
            }
            HuPrcVSleep();
        }
        func_800F7D64_MinigameIslandMISS();
        func_800F8448_MinigameIslandMISS();
        break;
    case 1:
        if (GwQuest.lifeNum <= 0) {
            cont = 1;
        }
        GwQuest.lifeNum--;
        func_800F8898_MinigameIslandMISS();
        if (GwQuest.lifeNum < 0) {
            GwQuest.lifeNum = 0;
        }
        if (func_800F9008_MinigameIslandMISS()) {
            func_800F82C8_MinigameIslandMISS();
        } else {
            func_800F8038_MinigameIslandMISS(0);
        }
        HuPrcSleep(30);
        for (i = 0; i < 30; i++) {
            if (D_800F9121_MinigameIslandMISS == 1) {
                break;
            }
            HuPrcVSleep();
        }
        if (func_800F9008_MinigameIslandMISS()) {
            func_800F8448_MinigameIslandMISS();
        } else {
            func_800F8180_MinigameIslandMISS(0);
        }
        break;
    }
    if (cont != 0) {
        func_800F8768_MinigameIslandMISS();
    }
    if (D_800F9121_MinigameIslandMISS == 0) {
        HuPrcSleep(20);
    }
}

// register allocation: retail copies the 127 into a second register (masked 2)
#ifdef NON_MATCHING
void func_800F7C7C_MinigameIslandMISS(void) {
    f32 vol;
    s32 max = 127;
    s32 lim;

    vol = 0.0f;
    lim = max;
    while (1) {
        if (D_800F9125_MinigameIslandMISS == 0) {
            func_80060214(vol);
        }
        vol += 4.233333f;
        if (lim <= vol) {
            break;
        }
        HuPrcVSleep();
    }
    vol = max;
    if (D_800F9125_MinigameIslandMISS == 0) {
        func_80060214(vol);
    }
    while (1) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_7D_MinigameIslandMISS/30C540", func_800F7C7C_MinigameIslandMISS);
#endif

void func_800F7D64_MinigameIslandMISS(void) {
    u16 coins;
    s32 step;
    s8 n;

    coins = GwPlayer[0].coins_mg;
    if ((s16)coins < 31) {
        step = (s16)coins < 0 ? -1 : 1;
    } else {
        step = (s16)coins >= 0 ? (s16)coins / 30.0f + 0.5f : (s16)coins / 30.0f - 0.5f;
    }
    n = 0;
    while ((s16)coins > D_800F9128_MinigameIslandMISS) {
        D_800F9128_MinigameIslandMISS += step;
        if ((s16)coins <= D_800F9128_MinigameIslandMISS) {
            GwQuest.coinNum += step - ((u8)D_800F9128_MinigameIslandMISS - coins);
            D_800F9128_MinigameIslandMISS = coins;
            break;
        }
        GwQuest.coinNum = step + GwQuest.coinNum;
        if (GwQuest.coinNum >= 100) {
            if (GwQuest.lifeNum >= 99) {
                GwQuest.coinNum = 99;
                GwQuest.lifeNum = 99;
            } else {
                GwQuest.coinNum -= 100;
                GwQuest.lifeNum++;
                if (GwQuest.lifeNum >= 100) {
                    GwQuest.lifeNum = 99;
                }
                func_800F8038_MinigameIslandMISS(2);
                PlaySound(0x10C);
            }
        }
        if ((s16)coins > 0) {
            if (n < 2) {
                PlaySound(0xFC);
            }
            n++;
            if (n >= 3) {
                n = 0;
            }
        }
        func_800F8898_MinigameIslandMISS();
        HuPrcVSleep();
    }
    if (GwQuest.coinNum >= 100) {
        if (GwQuest.lifeNum >= 99) {
            GwQuest.coinNum = 99;
            GwQuest.lifeNum = 99;
        } else {
            GwQuest.coinNum -= 100;
            GwQuest.lifeNum++;
            if (GwQuest.lifeNum >= 100) {
                GwQuest.lifeNum = 99;
            }
            PlaySound(0x10C);
            func_800F8038_MinigameIslandMISS(2);
        }
    }
    func_800F8898_MinigameIslandMISS();
}

void func_800F8038_MinigameIslandMISS(s8 idx) {
    f32 scale;
    s32 i;
    s32 n = idx;

    i = 0;
    do {
        i++;
        func_80067480(D_800F92B0_MinigameIslandMISS[n], i, 0x8000);
    } while (i < 5);
    for (scale = 0.0f; scale < 1.0; scale += 0.3) {
        i = 0;
        do {
            i++;
            func_80067354(D_800F92B0_MinigameIslandMISS[n], i, scale, scale);
        } while (i < 5);
        if (D_800F9121_MinigameIslandMISS == 0) {
            HuPrcVSleep();
        }
    }
    i = 0;
    do {
        i++;
        func_80067354(D_800F92B0_MinigameIslandMISS[n], i, 1.0f, 1.0f);
    } while (i < 5);
}

void func_800F8180_MinigameIslandMISS(s8 idx) {
    f32 scale;
    s32 i;
    s32 n = idx;

    i = 0;
    do {
        i++;
        func_80067354(D_800F92B0_MinigameIslandMISS[n], i, 1.0f, 1.0f);
    } while (i < 5);
    for (scale = 1.0f; scale > 0.0f; scale -= 0.3f) {
        i = 0;
        do {
            i++;
            func_80067354(D_800F92B0_MinigameIslandMISS[n], i, scale, scale);
        } while (i < 5);
        if (D_800F9121_MinigameIslandMISS == 0) {
            HuPrcVSleep();
        }
    }
    i = 0;
    do {
        i++;
        func_800674BC(D_800F92B0_MinigameIslandMISS[n], i, 0x8000);
    } while (i < 5);
}

void func_800F82C8_MinigameIslandMISS(void) {
    f32 scale;
    s32 i;

    i = 0;
    do {
        i++;
        func_80067480(D_800F92B0_MinigameIslandMISS[0], i, 0x8000);
        func_80067480(D_800F92B0_MinigameIslandMISS[1], i, 0x8000);
    } while (i < 5);
    for (scale = 0.0f; scale < 1.0; scale += 0.3) {
        i = 0;
        do {
            i++;
            func_80067354(D_800F92B0_MinigameIslandMISS[0], i, scale, scale);
            func_80067354(D_800F92B0_MinigameIslandMISS[1], i, scale, scale);
        } while (i < 5);
        if (D_800F9121_MinigameIslandMISS == 0) {
            HuPrcVSleep();
        }
    }
    i = 0;
    do {
        i++;
        func_80067354(D_800F92B0_MinigameIslandMISS[0], i, 1.0f, 1.0f);
        func_80067354(D_800F92B0_MinigameIslandMISS[1], i, 1.0f, 1.0f);
    } while (i < 5);
}

void func_800F8448_MinigameIslandMISS(void) {
    f32 scale;
    s32 i;

    i = 0;
    do {
        i++;
        func_80067354(D_800F92B0_MinigameIslandMISS[0], i, 1.0f, 1.0f);
        func_80067354(D_800F92B0_MinigameIslandMISS[1], i, 1.0f, 1.0f);
    } while (i < 5);
    for (scale = 1.0f; scale > 0.0f; scale -= 0.3f) {
        i = 0;
        do {
            i++;
            func_80067354(D_800F92B0_MinigameIslandMISS[0], i, scale, scale);
            func_80067354(D_800F92B0_MinigameIslandMISS[1], i, scale, scale);
        } while (i < 5);
        if (D_800F9121_MinigameIslandMISS == 0) {
            HuPrcVSleep();
        }
    }
    i = 0;
    do {
        i++;
        func_800674BC(D_800F92B0_MinigameIslandMISS[0], i, 0x8000);
        func_800674BC(D_800F92B0_MinigameIslandMISS[1], i, 0x8000);
    } while (i < 5);
}

s32 func_800F85C8_MinigameIslandMISS(s32 win) {
    s32 cpu = 0;
    s16 choice[4];
    u8 colors[4] = { 1, 2, 4, 8 };
    s32 i;

    for (i = 0; i < 4; i++) {
        if (i == 0) {
            if (GwPlayer[i].flags & 1) {
                cpu = 1;
                choice[GwPlayer[i].port] = -0x8000;
            } else {
                func_8007155C(win, colors[GwPlayer[i].port]);
                choice[GwPlayer[i].port] = -1;
            }
        } else {
            choice[GwPlayer[i].port] = 0;
        }
    }
    if (cpu != 0) {
        func_8006DA1C(win, 2, 2);
        func_80070FF8(choice[0], choice[1], choice[2], choice[3], 0x10);
    } else {
        func_800710A4(choice[0], choice[1], choice[2], choice[3]);
    }
    return func_8006FCF0(win, 0, 1);
}

void func_800F8768_MinigameIslandMISS(void) {
    s32 win;

    func_800674BC(D_800F926C_MinigameIslandMISS, 1, 0x8000);
    HuPrcSleep(30);
    PlaySound(0x43F);
    func_80067480(D_800F9278_MinigameIslandMISS, 1, 0x8000);
    win = CreateTextWindow(0x3A, 0xB6, 0x12, 2);
    func_8006E154(win, 0);
    if (func_8005CE48(0) != 0) {
        LoadStringIntoWindow(win, (void*)0x398, -1, -1);
    } else {
        LoadStringIntoWindow(win, (void*)0x399, -1, -1);
    }
    func_8006E070(win, 0);
    while (func_8006FCC0(win) != 0) {
        HuPrcVSleep();
    }
    D_800F9124_MinigameIslandMISS = func_800F85C8_MinigameIslandMISS(win);
    if (func_8005CE48(0) == 0) {
        D_800F9124_MinigameIslandMISS += 2;
    }
    D_800F9123_MinigameIslandMISS = 1;
}

// register allocation, retail reloads vals[i] in the second sign test (masked 5)
#ifdef NON_MATCHING
void func_800F8898_MinigameIslandMISS(void) {
    s16 vals[2];
    s16 nd[2];
    s16 digits[3][3];
    s32 i;
    s32 k;
    s32 j;

    vals[0] = GwQuest.lifeNum - D_800F9254_MinigameIslandMISS;
    vals[1] = GwPlayer[0].coins_mg - D_800F9128_MinigameIslandMISS;
    for (i = 0; i < 2; i++) {
        digits[i][0] = ABS(vals[i]) / 100;
        digits[i][1] = (ABS(vals[i]) - digits[i][0] * 100) / 10;
        digits[i][2] = ABS(vals[i]) - digits[i][0] * 100 - digits[i][1] * 10;
        nd[i] = 0;
        if (ABS(vals[i]) >= 10) {
            nd[i] = 1;
        }
        if (ABS(vals[i]) >= 100) {
            nd[i] = 2;
        }
    }
    for (i = 0, k = 2; i < 2; i++, k = 2) {
        for (j = 0; j < 3; j++, k++) {
            func_800672DC(D_800F92B0_MinigameIslandMISS[i], k, digits[i][j], 0);
            if (i == 0) {
                if (vals[0] == 0) {
                    func_80066DC4(D_800F92B0_MinigameIslandMISS[0], k, D_800F9160_MinigameIslandMISS[nd[0]][j], 2);
                } else {
                    func_80066DC4(D_800F92B0_MinigameIslandMISS[i], k, D_800F9160_MinigameIslandMISS[nd[i]][j] + 4, 2);
                }
            } else if (D_800F9250_MinigameIslandMISS == 0 && vals[i] != 0) {
                func_80066DC4(D_800F92B0_MinigameIslandMISS[i], k, D_800F9160_MinigameIslandMISS[nd[i]][j] + 4, 2);
            } else {
                func_80066DC4(D_800F92B0_MinigameIslandMISS[i], k, D_800F9160_MinigameIslandMISS[nd[i]][j], 2);
            }
        }
        if (i == 0) {
            if (vals[0] == 0) {
                func_80066DC4(D_800F92B0_MinigameIslandMISS[0], k, -1000, -2);
                func_800672DC(D_800F92B0_MinigameIslandMISS[0], k, 0xA, 0);
            } else {
                if (vals[i] > 0) {
                    func_800672DC(D_800F92B0_MinigameIslandMISS[i], k, 0xB, 0);
                } else {
                    func_800672DC(D_800F92B0_MinigameIslandMISS[i], k, 0xC, 0);
                }
                func_80066DC4(D_800F92B0_MinigameIslandMISS[i], k, D_800F9160_MinigameIslandMISS[nd[i]][2 - nd[i]] - 4, 2);
            }
        } else if (D_800F9250_MinigameIslandMISS == 0 && vals[i] != 0) {
            /* retail reloads vals[i] here */
            if (((volatile s16*)vals)[i] > 0) {
                func_800672DC(D_800F92B0_MinigameIslandMISS[i], k, 0xB, 0);
            } else {
                func_800672DC(D_800F92B0_MinigameIslandMISS[i], k, 0xC, 0);
            }
            func_80066DC4(D_800F92B0_MinigameIslandMISS[i], k, D_800F9160_MinigameIslandMISS[nd[i]][2 - nd[i]] - 4, 2);
        } else {
            func_80066DC4(D_800F92B0_MinigameIslandMISS[i], k, -1000, -2);
            func_800672DC(D_800F92B0_MinigameIslandMISS[i], k, 0xA, 0);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_7D_MinigameIslandMISS/30C540", func_800F8898_MinigameIslandMISS);
#endif

void func_800F8E30_MinigameIslandMISS(void) {
    s32 i;
    s32 j;

    func_80064D38(D_800F9264_MinigameIslandMISS);
    func_80064D38(D_800F926C_MinigameIslandMISS);
    func_80064D38(D_800F9278_MinigameIslandMISS);
    for (i = 0; i < 3; i++) {
        func_80064D38(D_800F92B0_MinigameIslandMISS[i]);
        func_80067704(D_800F9284_MinigameIslandMISS[i]);
    }
    func_80067704(D_800F9268_MinigameIslandMISS);
    func_80067704(D_800F9260_MinigameIslandMISS);
    for (i = 0; i < 2; i++) {
        func_80067704(D_800F9290_MinigameIslandMISS[i]);
        for (j = 0; j < 3; j++) {
            func_80067704(D_800F9298_MinigameIslandMISS[i][j]);
        }
    }
    func_80067704(D_800F9270_MinigameIslandMISS);
    func_80067704(D_800F927C_MinigameIslandMISS);
    func_80042B10(D_800F925C_MinigameIslandMISS);
    func_80053074();
    MBModelClose();
    func_800532F4();
}

void func_800F8F8C_MinigameIslandMISS(void) {
    switch (D_800F9250_MinigameIslandMISS) {
    case 0:
        HuPrcSleep(12);
        if (D_800F9126_MinigameIslandMISS == 0) {
            func_80060468(0x451, GwQuest.charNo);
        }
        break;
    case 1:
        HuPrcSleep(12);
        func_80060468(0x44A, GwQuest.charNo);
        break;
    }
    while (1) {
        HuPrcVSleep();
    }
}

s8 func_800F9008_MinigameIslandMISS(void) {
    return D_800F9174_MinigameIslandMISS[GwSystem.unk_1E];
}

void func_800F9020_MinigameIslandMISS(void) {
    s16 i;

    HuPrcSleep(105);
    GwQuest.lifeNum++;
    if (GwQuest.lifeNum >= 100) {
        GwQuest.lifeNum = 99;
    }
    func_800F8038_MinigameIslandMISS(2);
    PlaySound(0x10C);
    HuPrcSleep(30);
    for (i = 0; i < 30; i++) {
        if (D_800F9121_MinigameIslandMISS == 1) {
            break;
        }
        HuPrcVSleep();
    }
    func_800F8180_MinigameIslandMISS(2);
    D_800F9127_MinigameIslandMISS = 1;
    while (1) {
        HuPrcVSleep();
    }
}

s32 func_800F90F0_MinigameIslandMISS(s16 arg0) {
    return (D_800F91B0_MinigameIslandMISS[arg0].unk_00 > GwPlayer[0].coins_mg) ^ 1;
}
