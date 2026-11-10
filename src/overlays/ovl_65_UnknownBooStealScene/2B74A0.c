#include "common.h"
#include "2B74A0.h"

Object* D_800F93D0_UnknownBooStealScene = NULL;
s32 D_800F93D4_UnknownBooStealScene = 0;
void* D_800F93D8_UnknownBooStealScene = NULL;
u8 D_800F93DC_UnknownBooStealScene[4] = { 0, 5, 10, 15 };
s32 D_800F93E0_UnknownBooStealScene[8] = { 2, 9, 20, 31, 41, 49, 58, 70 };
Vec3f D_800F9400_UnknownBooStealScene[8] = {
    { -80.0f, 0.0f, 1310.0f }, { -80.0f, 0.0f, 1310.0f }, { -80.0f, 0.0f, 1310.0f }, { -80.0f, 0.0f, 1310.0f },
    { -80.0f, 0.0f, 1310.0f }, { -80.0f, 0.0f, 1310.0f }, { -80.0f, 0.0f, 1310.0f }, { -80.0f, 0.0f, 1310.0f },
};
Vec3f D_800F9460_UnknownBooStealScene[8] = {
    { 80.0f, 0.0f, 1520.0f }, { 80.0f, 0.0f, 1520.0f }, { 80.0f, 0.0f, 1520.0f }, { 80.0f, 0.0f, 1520.0f },
    { 80.0f, 0.0f, 1520.0f }, { 80.0f, 0.0f, 1520.0f }, { 80.0f, 0.0f, 1520.0f }, { 80.0f, 0.0f, 1520.0f },
};
/* the other three players, in order, for each player */
u8 D_800F94C0_UnknownBooStealScene[4][3] = { { 1, 2, 3 }, { 0, 2, 3 }, { 0, 1, 3 }, { 0, 1, 2 } };
BooStealVec2f D_800F94CC_UnknownBooStealScene[4] = {
    { 76.0f, 48.0f }, { 244.0f, 48.0f }, { 76.0f, 192.0f }, { 244.0f, 192.0f },
};
BooStealVec2f D_800F94EC_UnknownBooStealScene[4] = {
    { -1.0f, -1.0f }, { 1.0f, -1.0f }, { -1.0f, 1.0f }, { 1.0f, 1.0f },
};
/* MBModelCreate motion lists (words: a count, then file ids), one per character */
s32 D_800F950C_UnknownBooStealScene[] = { 3, 0x0001000F, 0x00010039, 0x0001003D };
s32 D_800F951C_UnknownBooStealScene[] = { 3, 0x0002000F, 0x00020039, 0x0002003D };
s32 D_800F952C_UnknownBooStealScene[] = { 3, 0x0006000F, 0x00060039, 0x0006003D };
s32 D_800F953C_UnknownBooStealScene[] = { 3, 0x0003000F, 0x00030039, 0x0003003D };
s32 D_800F954C_UnknownBooStealScene[] = { 3, 0x0004000F, 0x00040039, 0x0004003D };
s32 D_800F955C_UnknownBooStealScene[] = { 3, 0x0005000F, 0x00050039, 0x0005003D };
s32* D_800F956C_UnknownBooStealScene[6] = {
    D_800F950C_UnknownBooStealScene, D_800F951C_UnknownBooStealScene, D_800F952C_UnknownBooStealScene,
    D_800F953C_UnknownBooStealScene, D_800F954C_UnknownBooStealScene, D_800F955C_UnknownBooStealScene,
};
/* CPU star-steal chance (%) by turn band and coin band */
u8 D_800F9584_UnknownBooStealScene[3][4] = { { 60, 70, 80, 85 }, { 70, 80, 90, 95 }, { 80, 90, 95, 95 } };

void func_800F65E0_UnknownBooStealScene(void) {
    D_800F9600_UnknownBooStealScene = GwSystem.curBoardIndex;
    D_800F9601_UnknownBooStealScene = GwSystem.curPlayerIndex;
    
    if (GwSystem.currentTurn < 10) {
        D_800F9602_UnknownBooStealScene = 0;
    } else if (GwSystem.currentTurn < 20) {
        D_800F9602_UnknownBooStealScene = 1;
    } else if (GwSystem.currentTurn < 40) {
        D_800F9602_UnknownBooStealScene = 2;
    } else {
        D_800F9602_UnknownBooStealScene = 3;
    }
    
    omInitObjMan(0x32, 0x32);
    func_800F922C_UnknownBooStealScene();
    func_800F9024_UnknownBooStealScene();
    func_800544E4();
    func_800546B4(0, GwPlayer[0].turn_status);
    func_800546B4(1, GwPlayer[1].turn_status);
    func_800546B4(2, GwPlayer[2].turn_status);
    func_800546B4(3, GwPlayer[3].turn_status);
    func_8006CEA0();
    omAddPrcObj(func_800F884C_UnknownBooStealScene, 0x300, 0, 0);
    omAddObj(0x1000, 0, 0, -1, &func_800F8F18_UnknownBooStealScene);
    if (D_800C597A != 0) {
        SetFadeInTypeAndTime(6, 8);
    } else {
        SetFadeInTypeAndTime(1, 0x10);
    }
}

s32 func_800F6734_UnknownBooStealScene(void) {
    return rand8() / 256.0f * 100.0f;
}

void func_800F6788_UnknownBooStealScene(void) {
    s32 i;
    s32 turnBand;
    s32 coinBand;

    for (i = 0; i < 4; i++) {
        if (i != D_800F9601_UnknownBooStealScene && GwPlayer[i].stars != 0) {
            break;
        }
    }
    if (i != 4 && GwPlayer[D_800F9601_UnknownBooStealScene].coins >= 50) {
        if (GwSystem.maxTurns == GwSystem.currentTurn) {
            D_800F9630_UnknownBooStealScene = 1;
            return;
        }
        if (GwSystem.currentTurn < 10) {
            turnBand = 0;
        } else if (GwSystem.currentTurn < 30) {
            turnBand = 1;
        } else {
            turnBand = 2;
        }
        if (GwPlayer[D_800F9601_UnknownBooStealScene].coins < 61) {
            coinBand = 0;
        } else if (GwPlayer[D_800F9601_UnknownBooStealScene].coins < 71) {
            coinBand = 1;
        } else {
            coinBand = (GwPlayer[D_800F9601_UnknownBooStealScene].coins < 101) ? 2 : 3;
        }
        if (func_800F6734_UnknownBooStealScene() < D_800F9584_UnknownBooStealScene[turnBand][coinBand]) {
            D_800F9630_UnknownBooStealScene = 1;
        } else {
            goto coins;
        }
    }
    if (D_800F9630_UnknownBooStealScene == 1) {
        return;
    }
coins:
    for (i = 0; i < 4; i++) {
        if (i != D_800F9601_UnknownBooStealScene && GwPlayer[i].coins != 0) {
            break;
        }
    }
    if (i != 4) {
        D_800F9630_UnknownBooStealScene = 0;
    } else {
        D_800F9630_UnknownBooStealScene = 2;
    }
}

s32 func_800F699C_UnknownBooStealScene(void) {
    s32 eligible[4] = { 0, 0, 0, 0 };
    s32 i;
    s32 coins;
    s32 best;

    if (D_800F9601_UnknownBooStealScene != D_800F9620_UnknownBooStealScene[0]) {
        coins = GwPlayer[D_800F9620_UnknownBooStealScene[0]].coins;
        i = 1;
        eligible[0] = 1;
    } else {
        coins = GwPlayer[D_800F9620_UnknownBooStealScene[1]].coins;
        i = 2;
        eligible[1] = 1;
    }
    for (; i < 4; i++) {
        if (D_800F9601_UnknownBooStealScene != D_800F9620_UnknownBooStealScene[i]
            && GwPlayer[D_800F9620_UnknownBooStealScene[i]].coins + 5 >= coins) {
            eligible[i] = 1;
        }
    }
    best = 4;
    for (i = 0; i < 4; i++) {
        if (eligible[i] != 0 && func_8004FEBC(D_800F9620_UnknownBooStealScene[i]) < best) {
            best = func_8004FEBC(D_800F9620_UnknownBooStealScene[i]);
        }
    }
    return best;
}

// cross-jumped duplicate cases, if-converted star tests, layout (masked 253, logic checked against the asm)
#ifdef NON_MATCHING
void func_800F6B3C_UnknownBooStealScene(void) {
    s32 cand[4];
    s32 count;
    s32 i;
    s32 r;

    r = func_800F6734_UnknownBooStealScene();
    switch (D_800F9630_UnknownBooStealScene) {
    case 1:
        if (GwSystem.maxTurns < GwSystem.currentTurn + 5) {
            switch (func_8004FEBC(D_800F9601_UnknownBooStealScene)) {
            case 0:
                if (r >= 95 && GwPlayer[D_800F9610_UnknownBooStealScene[2]].stars < 2) {
                    if (GwPlayer[D_800F9610_UnknownBooStealScene[2]].stars != 0) {
                        D_800F9638_UnknownBooStealScene = 2;
                        break;
                    }
                }
                D_800F9638_UnknownBooStealScene = 1;
                break;
            case 1:
                if (r >= 95 && GwPlayer[D_800F9610_UnknownBooStealScene[2]].stars != 0) {
                    D_800F9638_UnknownBooStealScene = 2;
                } else {
                    D_800F9638_UnknownBooStealScene = 0;
                }
                break;
            case 2:
                if (r >= 95 && GwPlayer[D_800F9610_UnknownBooStealScene[1]].stars != 0) {
                    D_800F9638_UnknownBooStealScene = 1;
                } else {
                    D_800F9638_UnknownBooStealScene = 0;
                }
                break;
            case 3:
                if (r > 94 && GwPlayer[D_800F9610_UnknownBooStealScene[1]].stars != 0) {
                    D_800F9638_UnknownBooStealScene = 1;
                } else {
                    D_800F9638_UnknownBooStealScene = 0;
                }
                break;
            }
        } else {
            switch (func_8004FEBC(D_800F9601_UnknownBooStealScene)) {
            case 0:
                if (r >= 80 && GwPlayer[D_800F9610_UnknownBooStealScene[2]].stars < 2) {
                    if (GwPlayer[D_800F9610_UnknownBooStealScene[2]].stars != 0) {
                        D_800F9638_UnknownBooStealScene = 2;
                        break;
                    }
                }
                D_800F9638_UnknownBooStealScene = 1;
                break;
            case 1:
                if (r >= 90 && GwPlayer[D_800F9610_UnknownBooStealScene[2]].stars != 0) {
                    D_800F9638_UnknownBooStealScene = 2;
                } else {
                    D_800F9638_UnknownBooStealScene = 0;
                }
                break;
            case 2:
                if (r >= 90 && GwPlayer[D_800F9610_UnknownBooStealScene[1]].stars != 0) {
                    D_800F9638_UnknownBooStealScene = 1;
                } else {
                    D_800F9638_UnknownBooStealScene = 0;
                }
                break;
            case 3:
                if (r >= 95 && GwPlayer[D_800F9610_UnknownBooStealScene[1]].stars != 0) {
                    D_800F9638_UnknownBooStealScene = 1;
                } else {
                    D_800F9638_UnknownBooStealScene = 0;
                }
                break;
            }
        }
        break;
    case 0:
        count = 0;
        for (i = 0; i < 4; i++) {
            cand[i] = 0;
        }
        if (count == 0 || GwSystem.maxTurns == GwSystem.currentTurn
            || (GwSystem.maxTurns < GwSystem.currentTurn + 5 && func_800F6734_UnknownBooStealScene() < 80)
            || func_800F6734_UnknownBooStealScene() < 40) {
            if (GwSystem.maxTurns < GwSystem.currentTurn + 5) {
                if (func_8004FEBC(D_800F9601_UnknownBooStealScene) == 0) {
                    if (GwPlayer[D_800F9610_UnknownBooStealScene[1]].coins == 0) {
                        goto steal;
                    }
                    if (GwPlayer[D_800F9610_UnknownBooStealScene[0]].stars == GwPlayer[D_800F9610_UnknownBooStealScene[1]].stars) {
                        goto one;
                    }
                    if (r < 85) {
                        D_800F9638_UnknownBooStealScene = 1;
                        return;
                    }
                    goto steal;
                }
                if (GwPlayer[D_800F9610_UnknownBooStealScene[0]].coins == 0) {
                    goto steal;
                }
                if (GwPlayer[D_800F9610_UnknownBooStealScene[0]].stars - 1 <= GwPlayer[D_800F9610_UnknownBooStealScene[1]].stars) {
                    if (r < 80) {
                        goto zero;
                    }
                    goto steal;
                }
                if (GwPlayer[D_800F9610_UnknownBooStealScene[0]].stars - 2 == GwPlayer[D_800F9610_UnknownBooStealScene[1]].stars) {
                    if (r < 85) {
                        goto zero;
                    }
                    goto steal;
                }
                if (r < 95) {
                    goto zero;
                }
                goto steal;
            }
            if (func_8004FEBC(D_800F9601_UnknownBooStealScene) == 0) {
                if (GwPlayer[D_800F9610_UnknownBooStealScene[1]].coins == 0) {
                    goto steal;
                }
                if (GwPlayer[D_800F9610_UnknownBooStealScene[0]].stars != GwPlayer[D_800F9610_UnknownBooStealScene[1]].stars
                    && r >= 35) {
                    goto steal;
                }
            one:
                D_800F9638_UnknownBooStealScene = 1;
                return;
            }
            if (GwPlayer[D_800F9610_UnknownBooStealScene[0]].coins == 0) {
                goto steal;
            }
            if (GwPlayer[D_800F9610_UnknownBooStealScene[0]].stars - 1 <= GwPlayer[D_800F9610_UnknownBooStealScene[1]].stars) {
                if (r < 60) {
                    goto zero;
                }
                goto steal;
            }
            if (GwPlayer[D_800F9610_UnknownBooStealScene[0]].stars - 2 == GwPlayer[D_800F9610_UnknownBooStealScene[1]].stars) {
                if (r < 75) {
                    goto zero;
                }
                goto steal;
            }
            if (r >= 80) {
                goto steal;
            }
        zero:
            D_800F9638_UnknownBooStealScene = 0;
            return;
        steal:
            D_800F9638_UnknownBooStealScene = func_800F699C_UnknownBooStealScene();
            return;
        }
        for (i = 0; i < 4; i++) {
            if (cand[D_800F9610_UnknownBooStealScene[i]] != 0) {
                if (--count == 0) {
                    D_800F9638_UnknownBooStealScene = i;
                    return;
                }
            }
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_65_UnknownBooStealScene/2B74A0", func_800F6B3C_UnknownBooStealScene);
#endif

// register allocation: the -1 constant and the D_800F9620 base swap s2/s3 (raw 5, masked 0); tried declaration order, operand order, while loops
#ifdef NON_MATCHING
void func_800F7278_UnknownBooStealScene(void) {
    s32 starRankCount[4];
    s32 coinRankCount[4];
    s32 i;
    s32 j;
    s32 rank;
    s32 coinRank;

    for (i = 0; i < 4; i++) {
        starRankCount[i] = 0;
        coinRankCount[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        starRankCount[func_8004FEBC(i)]++;
        coinRank = 0;
        for (j = 0; j < 4; j++) {
            if (i != j) {
                coinRank += GwPlayer[i].coins < GwPlayer[j].coins;
            }
        }
        coinRankCount[coinRank]++;
    }
    for (i = 0; i < 4; i++) {
        D_800F9610_UnknownBooStealScene[i] = -1;
        D_800F9620_UnknownBooStealScene[i] = -1;
    }
    for (i = 0; i < 4; i++) {
        j = func_8004FEBC(i);
    starSlot:
        if (D_800F9610_UnknownBooStealScene[j] != -1) {
            j++;
            goto starSlot;
        }
        D_800F9610_UnknownBooStealScene[j] = i;
        coinRank = 0;
        for (j = 0; j < 4; j++) {
            if (i != j) {
                coinRank += GwPlayer[i].coins < GwPlayer[j].coins;
            }
        }
    coinSlot:
        if (D_800F9620_UnknownBooStealScene[coinRank] != -1) {
            coinRank++;
            goto coinSlot;
        }
        D_800F9620_UnknownBooStealScene[coinRank] = i;
    }
    D_800F9630_UnknownBooStealScene = D_800F9634_UnknownBooStealScene = D_800F9638_UnknownBooStealScene = -1;
    func_800F6788_UnknownBooStealScene();
    if (D_800F9638_UnknownBooStealScene == -1) {
        func_800F6B3C_UnknownBooStealScene();
    }
    while (starRankCount[D_800F9638_UnknownBooStealScene] == 0) {
        D_800F9638_UnknownBooStealScene--;
    }
    rank = func_8004FEBC(D_800F9601_UnknownBooStealScene);
    if (rank == D_800F9638_UnknownBooStealScene) {
        starRankCount[rank]--;
    }
    coinRank = rand8() % starRankCount[D_800F9638_UnknownBooStealScene];
    for (i = 0; i < 4; i++) {
        if (i == D_800F9601_UnknownBooStealScene) {
            continue;
        }
        if (D_800F9638_UnknownBooStealScene != func_8004FEBC(i)) {
            continue;
        }
        if (coinRank != 0) {
            coinRank--;
            continue;
        }
        D_800F9634_UnknownBooStealScene = i;
        break;
    }
    if (D_800F9630_UnknownBooStealScene == 0 && GwPlayer[D_800F9634_UnknownBooStealScene].coins == 0) {
        for (i = 0; i < 4; i++) {
            if (i != D_800F9601_UnknownBooStealScene && GwPlayer[i].coins != 0) {
                D_800F9634_UnknownBooStealScene = i;
                break;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_65_UnknownBooStealScene/2B74A0", func_800F7278_UnknownBooStealScene);
#endif

s32 func_800F7648_UnknownBooStealScene(s32 win, u8* options) {
    s16 buttons[4];
    s32 presses = 0;
    u8 portMask[4] = "\x01\x02\x04\x08";
    s32 i;
    s32 n;

    for (i = 0; i < 4; i++) {
        if (i == D_800F9601_UnknownBooStealScene) {
            if (GwPlayer[i].flags & 1) {
                func_800F7278_UnknownBooStealScene();
                presses = D_800F9630_UnknownBooStealScene + 1;
                buttons[GwPlayer[D_800F9601_UnknownBooStealScene].port] = 0x400;
            } else {
                func_8007155C(win, (s16)portMask[GwPlayer[i].port]);
                buttons[GwPlayer[i].port] = -1;
            }
        } else {
            buttons[GwPlayer[i].port] = 0;
        }
    }
    if (presses != 0) {
        func_8006DA1C(win, 2, 2);
        n = 0;
        do {
            presses--;
            if (presses == 0) {
                buttons[GwPlayer[D_800F9601_UnknownBooStealScene].port] = -0x8000;
            }
            if (n == 0) {
                func_80070FF8(buttons[0], buttons[1], buttons[2], buttons[3], func_8004DBBC());
            } else {
                func_80070FF8(buttons[0], buttons[1], buttons[2], buttons[3], 16);
            }
            n++;
        } while (presses != 0);
    } else {
        func_800710A4(buttons[0], buttons[1], buttons[2], buttons[3]);
    }
    for (i = 0; i < 2; i++) {
        if (options[i] == 0) {
            func_80071788(win, i);
        }
    }
    i = 0;
    do {
        i = func_8006FCF0_unproto((s16)win, (s16)i, 1);
    } while (options[i] == 0);
    return i;
}

s32 func_800F78E0_UnknownBooStealScene(s32 win, s32 mode, u8* options) {
    s16 buttons[4];
    s32 presses = 0;
    u8 portMask[4] = "\x01\x02\x04\x08";
    s32 i;

    for (i = 0; i < 4; i++) {
        if (i == D_800F9601_UnknownBooStealScene) {
            if (GwPlayer[i].flags & 1) {
                presses = D_800F9634_UnknownBooStealScene;
                presses += presses < i;
                buttons[GwPlayer[i].port] = 0x400;
            } else {
                func_8007155C(win, (s16)portMask[GwPlayer[i].port]);
                buttons[GwPlayer[i].port] = -1;
            }
        } else {
            buttons[GwPlayer[i].port] = 0;
        }
    }
    if (presses != 0) {
        func_8006DA1C(win, 2, 2);
        do {
            presses--;
            if (presses == 0) {
                buttons[GwPlayer[D_800F9601_UnknownBooStealScene].port] = -0x8000;
            }
            func_80070FF8(buttons[0], buttons[1], buttons[2], buttons[3], 16);
        } while (presses != 0);
    } else {
        func_800710A4(buttons[0], buttons[1], buttons[2], buttons[3]);
    }
    for (i = 0; i < 3; i++) {
        if (options[i] == 0) {
            func_80071788(win, i);
        }
    }
    i = 0;
    do {
        i = func_8006FCF0_unproto((s16)win, (s16)i, 0);
        if (i == -1) {
            return -1;
        }
    } while (options[i] == 0);
    return i;
}

// delay-slot fill: one redundant move a0,s5 before func_80055994 (masked 1, one extra instruction)
#ifdef NON_MATCHING
void func_800F7B54_UnknownBooStealScene(s32 mode, s32 victim) {
    s32 coinIds[26];
    Object* obj;
    void* data;
    s16 sprite;
    s16 image;
    s32 count;
    s32 i;
    s32 j;
    f32 y;
    f32 rot;
    f32 angle;
    s32 bonus;

    func_80021240(*D_800F9604_UnknownBooStealScene->unk_3C->unk_40);
    func_80021240(*D_800F9604_UnknownBooStealScene->unk_40->unk_40);
    for (i = 0; i < 256; i += 10) {
        func_800211BC(*D_800F9604_UnknownBooStealScene->unk_3C->unk_40, i);
        func_800211BC(*D_800F9604_UnknownBooStealScene->unk_40->unk_40, ~i);
        D_800F9604_UnknownBooStealScene->coords.x += D_800F9604_UnknownBooStealScene->unk_18.x;
        D_800F9604_UnknownBooStealScene->coords.y += D_800F9604_UnknownBooStealScene->unk_18.y;
        D_800F9604_UnknownBooStealScene->coords.z += D_800F9604_UnknownBooStealScene->unk_18.z;
        HuPrcVSleep();
    }
    MBModelDispOff(D_800F9604_UnknownBooStealScene);
    sprite = func_80064EF4(1, 5);
    data = DataRead(0xA000E);
    image = func_800678A4(data);
    DataClose(data);
    func_80067208(sprite, 0, image, 0);
    func_80067384(sprite, 0, 10);
    func_800672B0(sprite, 0, 0);
    func_800674BC(sprite, 0, 0x1000);
    func_80066DC4(sprite, 0, D_800F94CC_UnknownBooStealScene[victim].x, D_800F94CC_UnknownBooStealScene[victim].y);
    func_8006752C(sprite, 0, 0);
    PlaySound(0x94);
    for (i = 0; i < 17; i++) {
        func_80066DC4(sprite, 0, i * D_800F94EC_UnknownBooStealScene[victim].x + D_800F94CC_UnknownBooStealScene[victim].x,
                      i * D_800F94EC_UnknownBooStealScene[victim].y + D_800F94CC_UnknownBooStealScene[victim].y);
        func_8006752C(sprite, 0, i * 16);
        HuPrcVSleep();
    }
    func_8006752C(sprite, 0, 0xFF);
    count = 1;
    if (mode == 0) {
        count = rand8() % 10;
        bonus = D_800F93DC_UnknownBooStealScene[D_800F9602_UnknownBooStealScene] + 1;
        count += bonus;
        if (GwPlayer[victim].coins < count) {
            count = GwPlayer[victim].coins;
        }
    }
    if (mode != 0) {
        func_80055994(victim, 2);
        func_800503B0(victim, 5);
    } else {
        func_800503B0(victim, 4);
    }
    for (i = 0; i < 30; i++) {
        func_80066DC4(sprite, 0,
                      D_800F94EC_UnknownBooStealScene[victim].x * 16.0f + D_800F94CC_UnknownBooStealScene[victim].x + sinf(i * 50 * (M_PI / 180)) * 2.0f,
                      D_800F94EC_UnknownBooStealScene[victim].y * 16.0f + D_800F94CC_UnknownBooStealScene[victim].y);
        HuPrcVSleep();
    }
    PlaySound(0x94);
    for (i = 16; i >= 0; i--) {
        func_80066DC4(sprite, 0, i * D_800F94EC_UnknownBooStealScene[victim].x + D_800F94CC_UnknownBooStealScene[victim].x,
                      i * D_800F94EC_UnknownBooStealScene[victim].y + D_800F94CC_UnknownBooStealScene[victim].y);
        func_8006752C(sprite, 0, i * 16);
        HuPrcVSleep();
    }
    func_80064D38(sprite);
    func_80067704(image);
    MBModelDispOn(D_800F9604_UnknownBooStealScene);
    for (i = 255; i >= 0; i -= 10) {
        func_800211BC(*D_800F9604_UnknownBooStealScene->unk_3C->unk_40, i);
        func_800211BC(*D_800F9604_UnknownBooStealScene->unk_40->unk_40, ~i);
        obj = D_800F9604_UnknownBooStealScene;
        obj->coords.x = D_800F9400_UnknownBooStealScene[D_800F9600_UnknownBooStealScene].x;
        obj->coords.y = D_800F9400_UnknownBooStealScene[D_800F9600_UnknownBooStealScene].y;
        obj->coords.z = D_800F9400_UnknownBooStealScene[D_800F9600_UnknownBooStealScene].z;
        HuPrcVSleep();
    }
    func_800211BC(*D_800F9604_UnknownBooStealScene->unk_3C->unk_40, 0);
    func_800211BC(*D_800F9604_UnknownBooStealScene->unk_40->unk_40, 0xFF);
    if (mode == 0) {
        for (i = 0; i < count; i++) {
            if (i == 0) {
                coinIds[0] = LoadFormFile(0x1F0001, 0x2B9);
            } else {
                coinIds[i] = func_80023FC8_s32(coinIds[0]);
            }
            func_80025798(coinIds[i], D_800F9400_UnknownBooStealScene[D_800F9600_UnknownBooStealScene].x,
                          D_800F9400_UnknownBooStealScene[D_800F9600_UnknownBooStealScene].y + 200.0f,
                          D_800F9400_UnknownBooStealScene[D_800F9600_UnknownBooStealScene].z);
            func_80025830(coinIds[i], 0.15f, 0.15f, 0.15f);
            func_800258EC(coinIds[i], 4, 4);
        }
        for (j = 0; j < count; j++) {
            i = 0;
            rot = 0.0f;
            for (; i < 181; i += 30) {
                func_800258EC(coinIds[j], 4, 0);
                y = D_800F9400_UnknownBooStealScene[D_800F9600_UnknownBooStealScene].y + 200.0f;
                func_80025798(coinIds[j],
                              (D_800F9460_UnknownBooStealScene[D_800F9600_UnknownBooStealScene].x - D_800F9400_UnknownBooStealScene[D_800F9600_UnknownBooStealScene].x) * i / 180.0f + D_800F9400_UnknownBooStealScene[D_800F9600_UnknownBooStealScene].x,
                              y + sinf(i * (M_PI / 180)) * 100.0f,
                              (D_800F9460_UnknownBooStealScene[D_800F9600_UnknownBooStealScene].z - D_800F9400_UnknownBooStealScene[D_800F9600_UnknownBooStealScene].z) * i / 180.0f + D_800F9400_UnknownBooStealScene[D_800F9600_UnknownBooStealScene].z);
                func_800257E4(coinIds[j], 0.0f, rot, 0.0f);
                HuPrcVSleep();
                rot += 50.0f;
            }
            func_800258EC(coinIds[j], 4, 4);
            func_80055960(D_800F9601_UnknownBooStealScene, 1);
            func_80055810(victim, -1, 0);
        }
        if (count == 1) {
            MBMotionSet(D_800F9608_UnknownBooStealScene, 2, 0);
            HuPrcSleep(5);
            func_80060468(0x44A, GwPlayer[D_800F9601_UnknownBooStealScene].character);
            HuPrcSleep(50);
        } else {
            func_8004CCD0(&D_800F9608_UnknownBooStealScene->coords, &D_800F32A0->coords, &D_800F9608_UnknownBooStealScene->unk_18);
            MBMotionSet(D_800F9608_UnknownBooStealScene, 1, 0);
            HuPrcSleep(5);
            if (count >= 10) {
                func_80060468(0x451, GwPlayer[D_800F9601_UnknownBooStealScene].character);
            }
            HuPrcSleep(35);
        }
        for (i = 0; i < count; i++) {
            func_8002456C(coinIds[i]);
        }
    } else {
        func_800500A4();
        PlaySound(0x44);
        PlaySound(0x6D);
        D_800F93D0_UnknownBooStealScene = MBModelCreate(0x40, NULL);
        D_800F93D0_UnknownBooStealScene->coords.x = D_800F9400_UnknownBooStealScene[D_800F9600_UnknownBooStealScene].x;
        D_800F93D0_UnknownBooStealScene->coords.y = D_800F9400_UnknownBooStealScene[D_800F9600_UnknownBooStealScene].y + 200.0f;
        D_800F93D0_UnknownBooStealScene->coords.z = D_800F9400_UnknownBooStealScene[D_800F9600_UnknownBooStealScene].z;
        D_800F93D0_UnknownBooStealScene->xScale = 0.5f;
        D_800F93D0_UnknownBooStealScene->yScale = 0.5f;
        D_800F93D0_UnknownBooStealScene->zScale = 0.5f;
        D_800F93D8_UnknownBooStealScene = func_80042728(D_800F93D0_UnknownBooStealScene, 0);
        for (i = 0; i < 181; i += 5) {
            D_800F93D0_UnknownBooStealScene->coords.x = (D_800F9460_UnknownBooStealScene[D_800F9600_UnknownBooStealScene].x - D_800F9400_UnknownBooStealScene[D_800F9600_UnknownBooStealScene].x) * i / 180.0f + D_800F9400_UnknownBooStealScene[D_800F9600_UnknownBooStealScene].x;
            D_800F93D0_UnknownBooStealScene->coords.y = D_800F9400_UnknownBooStealScene[D_800F9600_UnknownBooStealScene].y + 200.0f + sinf(i * (M_PI / 180)) * 100.0f;
            D_800F93D0_UnknownBooStealScene->coords.z = (D_800F9460_UnknownBooStealScene[D_800F9600_UnknownBooStealScene].z - D_800F9400_UnknownBooStealScene[D_800F9600_UnknownBooStealScene].z) * i / 180.0f + D_800F9400_UnknownBooStealScene[D_800F9600_UnknownBooStealScene].z;
            angle = i * 10 * (M_PI / 180);
            D_800F93D0_UnknownBooStealScene->unk_18.x = sinf(angle);
            D_800F93D0_UnknownBooStealScene->unk_18.z = cosf(angle);
            HuPrcVSleep();
        }
        PlaySound(0x474);
        func_80055994(D_800F9601_UnknownBooStealScene, 1);
        func_800503B0(D_800F9601_UnknownBooStealScene, 4);
        MBModelKill(D_800F93D0_UnknownBooStealScene);
        D_800F93D0_UnknownBooStealScene = NULL;
        func_800427D4(D_800F93D8_UnknownBooStealScene);
        D_800F93D8_UnknownBooStealScene = NULL;
        func_80021CDC(*D_800F9608_UnknownBooStealScene->unk_3C->unk_40, GwPlayer[D_800F9601_UnknownBooStealScene].character, 0x81);
        func_8004CCD0(&D_800F9608_UnknownBooStealScene->coords, &D_800F32A0->coords, &D_800F9608_UnknownBooStealScene->unk_18);
        MBMotionSet(D_800F9608_UnknownBooStealScene, 0, 0);
        GwPlayer[D_800F9601_UnknownBooStealScene].stars++;
        GwPlayer[victim].stars--;
        HuPrcSleep(36);
        func_80060468(0x443, GwPlayer[D_800F9601_UnknownBooStealScene].character);
        HuPrcSleep(48);
        func_80050160();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_65_UnknownBooStealScene/2B74A0", func_800F7B54_UnknownBooStealScene);
#endif

// the two D_800F93D4 stores are cross-jumped, D_800C5218 hoisted into s8, i/n registers swapped (masked 29)
#ifdef NON_MATCHING
void func_800F884C_UnknownBooStealScene(void) {
    u8 options[4];
    s32 mode;
    s32 choice;
    s32 target;
    s32 delay;
    s16 win;
    s32 n;
    s32 i;

    mode = D_800C597A;
    target = 0;
    if (mode != 0) {
        delay = 8;
    } else {
        func_800421E0();
        HuPrcSleep(16);
        PlaySound(0x43A);
        delay = 10;
    }
    HuPrcSleep(delay);
    while (1) {
        if (mode < 2) {
            win = CreateTextWindow(0x38, 0x3C, 0x12, 9);
            for (i = 0; i < 4; i++) {
                if (i != D_800F9601_UnknownBooStealScene && GwPlayer[i].coins != 0) {
                    break;
                }
            }
            if (i == 4) {
                func_8006DA5C(win, "\x01", 0);
                options[0] = 0;
            } else {
                func_8006DA5C(win, "\x08", 0);
                options[0] = 1;
            }
            for (i = 0; i < 4; i++) {
                if (i != D_800F9601_UnknownBooStealScene && GwPlayer[i].stars != 0) {
                    break;
                }
            }
            if (i == 4 || GwPlayer[D_800F9601_UnknownBooStealScene].coins < 50
                || GwPlayer[D_800F9601_UnknownBooStealScene].stars >= 99) {
                func_8006DA5C(win, "\x01", 1);
                options[1] = 0;
            } else {
                func_8006DA5C(win, "\x08", 1);
                options[1] = 1;
            }
            options[2] = 1;
            options[3] = 1;
            LoadStringIntoWindow(win, (void*)0x268, -1, -1);
            func_8006E070(win, 0);
            ShowTextWindow(win);
            while (func_8006FCC0(win) != 0) {
                HuPrcVSleep();
            }
            choice = func_800F7648_UnknownBooStealScene(win, options);
            HideTextWindow(win);
            if (choice == 3) {
                D_800F93D4_UnknownBooStealScene = 1;
                choice = -2;
                break;
            }
            mode = 0;
            if (choice == 2) {
                choice = -1;
                break;
            }
        } else {
            choice = mode - 2;
            mode = 0;
        }
        win = CreateTextWindow(0xA0, 0x3C, 6, 5);
        for (i = 0, n = 0; i < 4; i++) {
            if (i == D_800F9601_UnknownBooStealScene) {
                continue;
            }
            if (choice == 0) {
                if (GwPlayer[i].coins == 0) {
                    options[n / 2] = 0;
                    func_8006DA5C(win, "\x01", n++);
                } else {
                    goto has;
                }
            } else {
                if (GwPlayer[i].stars == 0) {
                    options[n / 2] = 0;
                    func_8006DA5C(win, "\x01", n++);
                } else {
                has:
                    options[n / 2] = 1;
                    func_8006DA5C(win, "\x08", n++);
                }
            }
            func_8006DA5C(win, D_800C5218[GwPlayer[i].character], n++);
        }
        options[3] = 1;
        LoadStringIntoWindow(win, (void*)0x269, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        while (func_8006FCC0(win) != 0) {
            HuPrcVSleep();
        }
        target = func_800F78E0_UnknownBooStealScene(win, choice, options);
        HideTextWindow(win);
        if (target == -1) {
            continue;
        }
        if (target == 3) {
            D_800F93D4_UnknownBooStealScene = choice + 2;
            choice = -2;
        }
        break;
    }
    if (choice == -1) {
        func_80021240(*D_800F9604_UnknownBooStealScene->unk_3C->unk_40);
        func_80021240(*D_800F9604_UnknownBooStealScene->unk_40->unk_40);
        PlaySound(0x43A);
        for (i = 0; i < 256; i += 10) {
            func_800211BC(*D_800F9604_UnknownBooStealScene->unk_3C->unk_40, i);
            func_800211BC(*D_800F9604_UnknownBooStealScene->unk_40->unk_40, ~i);
            HuPrcVSleep();
        }
        MBModelDispOff(D_800F9604_UnknownBooStealScene);
        win = CreateTextWindow(0x8C, 0x50, 0xA, 2);
        LoadStringIntoWindow(win, (void*)0x26B, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        func_8004DBD4(win, D_800F9601_UnknownBooStealScene);
        HideTextWindow(win);
        HuPrcSleep(10);
    } else if (choice != -2) {
        if (choice != 0) {
            func_80055960(D_800F9601_UnknownBooStealScene, -50);
        }
        win = CreateTextWindow(0x8C, 0x50, 0xA, 1);
        LoadStringIntoWindow(win, (void*)0x26A, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        func_8004DBD4(win, D_800F9601_UnknownBooStealScene);
        HideTextWindow(win);
        func_800F7B54_UnknownBooStealScene(choice, D_800F94C0_UnknownBooStealScene[D_800F9601_UnknownBooStealScene][target]);
    }
    D_800F5144 = 1;
    while (1) {
        HuPrcVSleep();
    }
}
#else
/* the C's message insert strings; the asm above left the assembler in .text while GCC still
   believes it is in .rodata (from D_800F95A0), so switch explicitly */
__asm__(".section .rodata");
const char D_800F95C0_UnknownBooStealScene[] __attribute__((section(".rodata"))) = "\x01";
const char D_800F95C4_UnknownBooStealScene[] __attribute__((section(".rodata"))) = "\x08";
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_65_UnknownBooStealScene/2B74A0", func_800F884C_UnknownBooStealScene);
#endif

void func_800F8E9C_UnknownBooStealScene(omObjData* obj) {
    if (func_80072718() == 0) {
        func_800F93A4_UnknownBooStealScene();
        func_800F91D0_UnknownBooStealScene();
        func_80054654();
        func_80070ED4();
        if (D_800F93D4_UnknownBooStealScene != 0) {
            func_8004F284();
            func_8004F28C(0x65, (s16)D_800F93D4_UnknownBooStealScene);
        } else {
            omOvlReturnEx(1);
        }
    }
}

void func_800F8F18_UnknownBooStealScene(omObjData* obj) {
    if (D_800F5144 != 0) {
        if (D_800F93D4_UnknownBooStealScene != 0) {
            func_800726AC(6, 8);
        } else {
            func_800726AC(1, 16);
        }
        obj->func_ptr = &func_800F8E9C_UnknownBooStealScene;
    }
}

void func_800F8F78_UnknownBooStealScene(omObjData* arg0) {
    Object* temp_s0;

    temp_s0 = D_800F9604_UnknownBooStealScene;
    temp_s0->unk_30 = sinf(arg0->rot.y * (M_PI/180))* 20.0f + 150.0f;
    arg0->rot.y += 2.0f;
    if (arg0->rot.y >= 360.0f) {
        arg0->rot.y -=  360.0f;
    }
}

void func_800F9024_UnknownBooStealScene(void) {
    MBModelInit();
    D_800F9604_UnknownBooStealScene = MBModelCreate(0x6D, NULL);
    D_800F9604_UnknownBooStealScene->coords.x = D_800F9400_UnknownBooStealScene[D_800F9600_UnknownBooStealScene].x;
    D_800F9604_UnknownBooStealScene->coords.y = D_800F9400_UnknownBooStealScene[D_800F9600_UnknownBooStealScene].y;
    D_800F9604_UnknownBooStealScene->coords.z = D_800F9400_UnknownBooStealScene[D_800F9600_UnknownBooStealScene].z;
    D_800F9604_UnknownBooStealScene->unk_30 = 150.0f;
    D_800F9608_UnknownBooStealScene = MBModelCreate(func_80052F04(D_800F9601_UnknownBooStealScene),
        D_800F956C_UnknownBooStealScene[GwPlayer[D_800F9601_UnknownBooStealScene].character]);
    D_800F9608_UnknownBooStealScene->coords.x = D_800F9460_UnknownBooStealScene[D_800F9600_UnknownBooStealScene].x;
    D_800F9608_UnknownBooStealScene->coords.y = D_800F9460_UnknownBooStealScene[D_800F9600_UnknownBooStealScene].y;
    D_800F9608_UnknownBooStealScene->coords.z = D_800F9460_UnknownBooStealScene[D_800F9600_UnknownBooStealScene].z;
    func_80021B14(*D_800F9608_UnknownBooStealScene->unk_3C->unk_40, GwPlayer[D_800F9601_UnknownBooStealScene].character, 0x80);
    func_8004CCD0(&D_800F9604_UnknownBooStealScene->coords, &D_800F9608_UnknownBooStealScene->coords, &D_800F9604_UnknownBooStealScene->unk_18);
    func_8004CCD0(&D_800F9608_UnknownBooStealScene->coords, &D_800F9604_UnknownBooStealScene->coords, &D_800F9608_UnknownBooStealScene->unk_18);
    omAddObj(0x1000, 0, 0, -1, &func_800F8F78_UnknownBooStealScene)->rot.y = 0.0f;
}

void func_800F91D0_UnknownBooStealScene(void) {
    MBModelKill(D_800F9604_UnknownBooStealScene);
    MBModelKill(D_800F9608_UnknownBooStealScene);
    if (D_800F93D0_UnknownBooStealScene != NULL) {
        MBModelKill(D_800F93D0_UnknownBooStealScene);
    }
    if (D_800F93D8_UnknownBooStealScene != NULL) {
        func_800427D4(D_800F93D8_UnknownBooStealScene);
    }
}

void func_800F922C_UnknownBooStealScene(void) {
    s32 index;

    func_800178A0(1);
    func_80017660(0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    LoadBackgroundData(FE2310_ROM_START);
    switch (D_800F9600_UnknownBooStealScene) {
    case 1:
        if (GwPlayer[D_800F9601_UnknownBooStealScene].cur_chain == 2) {
            index = 12;
        } else {
            index = 9;
        }
        break;
    case 3:
        switch (GwPlayer[D_800F9601_UnknownBooStealScene].cur_chain) {
        case 2:
            index = 0x1D;
            break;
        case 3:
            index = 0x21;
            break;
        case 8:
            index = 0x1F;
            break;
        case 1:
            index = 0x20;
            break;
        case 0:
        default:
            index = 0x1E;
            break;
        }
        break;
    default:
        index = D_800F93E0_UnknownBooStealScene[D_800F9600_UnknownBooStealScene];
        break;
    }
    LoadBackgroundIndex(index);
}

void func_800F93A4_UnknownBooStealScene(void) {
    func_8004A140();
    func_80049F0C();
}
