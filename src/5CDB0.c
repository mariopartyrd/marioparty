#include "common.h"
#include "engine/process.h"
#include "spaces.h"

typedef struct {
    /* 0x00 */ s32 overlay;
    /* 0x04 */ s16 event;
    /* 0x06 */ u16 stat;
} OvlCallEntry;

s32 D_800C58C0[] = { 0x72, 0x73, 0x74, 0x75, 0x76 }; /* board overlays by map number */
extern s16 D_800D8950;
extern s16 D_800D8952;
extern s16 D_800D8954;
extern OvlCallEntry D_800D8958[5];
extern s32 D_800D8980;
extern s16 D_800D8984;
extern s16 D_800D8986;
extern s16 D_800D8988;
extern s32 D_800D898C;
extern s16 D_800D8990;
extern s16 D_800D8992;
extern Vec3f D_800D8994;
extern s16 D_800D89A0;
extern s16 D_800F329A;
extern s16 D_800F3750;

void func_8005C52C(void);
void func_8005CE8C(s32 flag);
void func_8005CEDC(s32 flag);
void func_8005C384(void);
void func_8005C4D0(void);
void func_8005C624(void);
void func_8005C6F8(void);
void func_8005C834(void);
void func_8005C5E8(s16 mode);
void func_8005CD4C(s32 overlay, s16 event, s16 fade, s16 music);
void func_8005CE04(void);
void func_8005B388(void);
void func_8005B860(s16 index);
void func_8005B900(void);
s16 func_8005B984(void* str);
s16 func_8005BAB0(void* str);
void func_8005BC28(void);
void func_8005BC80(void);
void func_8005BD28(void);
s32 func_8005BDA0(u16* chain, u16* space);
void func_8005C00C(s16 curSpace);
void func_8005C124(void);
void func_80053064(void);
void func_80053074(void);
void func_80053080(void);
void func_800532E0(void);
void func_800532F4(void);
void func_800565B4(void);
void func_80056700(void);
void MBModelClose(void);
void FreeSpaceTexturesWrapper(void);
s32 ExecuteEventForSpace(s16 index, s16 activationType);
s32 func_8004D02C(s16 arg0, f32 arg1);
void func_8004D4A8(s16 arg0, s32 arg1);
void func_8004D6FC(s16 arg0, f32 arg1);
void func_8004220C(void);
s8 func_8000C4A0(void);


void func_8005C1B0(s32 overlay, s16 event, u16 stat) {
    OvlCallEntry* e = &D_800D8958[D_800D8954++];

    e->overlay = overlay;
    e->event = event;
    e->stat = stat;
    if (D_800D8954 >= 5) {
        D_800D8954 = 4;
    }
}

void func_8005C208(void) {
    SetBoardFeatureFlag(0x2B);
    if (func_8005CE48(1) != 0) {
        func_8005CE8C(4);
    } else {
        func_8005CEDC(4);
    }
    D_800D8950 = 1;
    D_800D8954 = 0;
    D_800D8952 = 2;
    if (func_8005CE48(4) == 0) {
        func_8005C1B0(0x78, 0, 0x92);
        func_8005C1B0(0x72, 1, 0x92);
    }
    func_8005C52C();
    func_8005CEDC(4);
    ClearBoardFeatureFlag(0x2F);
}

void func_8005C2B0(void) {
    OvlCallEntry* e;

    if (D_800D8954 != 0) {
        e = &D_800D8958[--D_800D8954];
        omOvlCallEx(e->overlay, e->event, e->stat);
        return;
    }
    if (D_800D8950 != 0) {
        if (func_8005CE48(5) != 0) {
            func_8005CEDC(5);
            SetBoardFeatureFlag(0x2F);
        }
        omOvlCallEx(D_800C58C0[GwQuest.mapNo], D_800D8952, 0x92);
        D_800D8952 = 2;
        return;
    }
    ClearBoardFeatureFlag(0x2B);
    omOvlReturnEx(1);
}

void func_8005C384(void) {
    D_800D8950 = 0;
}

void func_8005C390(void) {
    func_8005CEDC(4);
    ClearBoardFeatureFlag(0x2F);
    func_8005C52C();
    func_8005C1B0(0x72, 1, 0x92);
}

void func_8005C3CC(void) {
    func_8005B388();
    D_800F329A = -1;
    D_800F3750 = -1;
}

void func_8005C3FC(s32 bg, s16 spaces) {
    LoadBackgroundData(D_FE2310);
    if (bg >= 0) {
        LoadBackgroundIndex(bg);
    }
    LoadInitialSpaceTextures();
    if (spaces >= 0) {
        LoadBoardSpaces(10, spaces);
        ChangeSpaceTextures(2);
    }
    GwPlayer[0].character = GwQuest.charNo;
    MBModelInit();
    func_80053020();
    func_80053064();
    func_800532E0();
    func_8006CEA0();
    func_800565B4();
    D_800D8984 = -1;
    D_800D8986 = 0;
    D_800D8988 = 0;
    func_8005B900();
    func_80053080();
}

void func_8005C4D0(void) {
    func_80056700();
    func_80070ED4();
    func_800532F4();
    func_80053074();
    MBModelClose();
    FreeBoardSpaces();
    FreeSpaceTexturesWrapper();
    func_8004A140();
    func_80049F0C();
}

void func_8005C52C(void) {
    GW_SYSTEM* sys = &GwSystem;
    GWQUEST* quest = &GwQuest;
    s32 i;

    sys->curPlayerIndex = 0;
    sys->unk_1E = -1;
    sys->minigameExplanation = 0;
    func_8005B860(-1);
    func_8005CE04();
    D_800D89A0 = -1;
    if (func_8005CE48(4) == 0) {
        quest->mapNo = 0;
        quest->coinNum = 0;
        quest->lifeNum = 3;
        for (i = 0; i < 0x39; i++) {
            if (i != 0) {
                func_8005CEDC(i);
            }
        }
        for (i = 0; i < 4; i++) {
            GetPlayerStruct(i)->coins = 0;
        }
    }
}

void func_8005C5E8(s16 mode) {
    D_800D8992 = mode;
}

s16 func_8005C5F4(void) {
    return D_800D8992;
}

void func_8005C600(Vec3f* pos) {
    D_800D8994 = *pos;
}

void func_8005C624(void) {
    Vec2f cam;

    while (1) {
        switch (D_800D8992) {
        case 1:
            func_8004B5DC(&GwPlayer[GwSystem.curPlayerIndex].player_obj->coords);
            break;
        case 2:
            func_8004B5DC(&D_800D8994);
            break;
        case 3:
            func_8004B6D8(&cam);
            func_8004B61C(&cam);
            break;
        }
        HuPrcVSleep();
    }
}

void func_8005C6F8(void) {
    do {
        HuPrcVSleep();
    } while (func_80072718() != 0);
    while (1) {
        HuPrcVSleep();
        if (D_800F5144 == 0 && D_800D8984 < 0) {
            continue;
        }
        while (func_80072718() != 0) {
            HuPrcVSleep();
        }
        if (D_800D8988 != 0) {
            func_800601D4(0x5A);
        }
        func_800726AC(D_800D8986, 0x10);
        HuPrcSleep(0x11);
        func_8005C4D0();
        if (D_800D8984 & 0x10) {
            func_8005C384();
        }
        if (D_800D8984 & 1) {
            func_8005C1B0(0x6F, 0, 0x94);
        }
        if (D_800D8984 & 2) {
            func_8005C1B0(D_800D898C, D_800D8990, 0x92);
        }
        ClearBoardFeatureFlag(0x45);
        omOvlReturnEx(1);
        omOvlKill();
        HuPrcVSleep();
    }
}

// register allocation: s4-s7 permuted between arrows, bs, sys and shown (masked 1)
#ifdef NON_MATCHING
void func_8005C834(void) {
    u16 chain;
    u16 space;
    s16 curSpace;
    GW_SYSTEM* sys = &GwSystem;
    BoardSpace* bs;
    GW_PLAYER* player;
    s32 shown;
    s16 arrows;
    s32 t;
    s32 type;
    s16 win;
    s16 choice;

    arrows = 0;
    player = GetPlayerStruct(0);
    func_8004A520();
    func_8004B5C4(3.0f);
    while (func_80072718() != 0) {
        HuPrcVSleep();
    }
    func_8005CEDC(3);
restart:
    while (1) {
        sys->unk_1E = -1;
        curSpace = GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain, player->cur_space);
        bs = BoardSpaceGet(curSpace);
        func_8005BC80();
        D_800D8980 = ExecuteEventForSpace(curSpace, 1);
        func_8005BD28();
        t = 0;
        if (D_800D8980 & 2) {
            arrows = 1;
            func_8005C00C(D_800D89A0);
            t = 1;
        }
        shown = t;
    wait:
            HuPrcVSleep();
            if (ContBtnTrg[player->port] & 0x8000) {
                if (arrows != 0) {
                    arrows = 0;
                    func_8005C124();
                }
                D_800D8980 = ExecuteEventForSpace(curSpace, 3);
                if (D_800D8980 & 1) {
                    goto restart;
                }
                if (D_800D8984 >= 0) {
                    HuPrcSleep(-1);
                }
                if (sys->unk_1E >= 0) {
                    win = func_8005BAB0(NULL);
                    choice = func_8005B984(NULL);
                    func_80070D90(win);
                    if (choice == 0) {
                        D_800D8984 = 1;
                        D_800D8988 = 1;
                        D_800D8986 = 1;
                        func_8005BC28();
                        HuPrcSleep(-1);
                    }
                } else if (sys->unk_1E == -2) {
                    win = func_8005BAB0(NULL);
                    choice = func_8005B984(NULL);
                    func_80070D90(win);
                    if (choice == 0) {
                        func_8005CD4C(0x79, 0, 1, 0);
                        func_8005BC28();
                        HuPrcSleep(-1);
                    } else if (shown & (arrows ^ 1)) {
                        arrows = 1;
                        func_8005C00C(D_800D89A0);
                    }
                }
            }
            if ((s16)func_8004D02C(player->port, 50.0f) == 0) {
                goto wait;
            }
            if (func_8005BDA0(&chain, &space) == 0) {
                goto wait;
            }
            if (bs->spaceType == 2 && GetAbsSpaceIndexFromChainSpaceIndex(chain, space) != D_800D89A0) {
                goto wait;
            }
        if (arrows != 0) {
            arrows = 0;
            func_8005C124();
        }
        D_800D89A0 = curSpace;
        player->next_chain = chain;
        player->next_space = space;
        curSpace = GetAbsSpaceIndexFromChainSpaceIndex(chain, space);
        bs = BoardSpaceGet(curSpace);
        if (bs->unk2 & 0x8000) {
            func_80060468(0x127, 0);
            SetPlayerAnimation(-1, 2, 0);
            player->player_obj->unk_34 = 40.0f;
            player->player_obj->unk_38 = -4.0f;
            func_8004D4A8(sys->curPlayerIndex, 20);
        } else {
            if (((s16*)&player->player_obj->unk_44)[1] != 0) {
                SetPlayerAnimation(-1, 0, 2);
            }
            func_8004D6FC(sys->curPlayerIndex, 19.0f);
        }
        player->cur_chain = player->next_chain;
        player->cur_space = player->next_space;
        type = bs->spaceType;
        if (type < 5) {
            if (type != 0) {
                SetSpaceStepAnim(curSpace);
                PlaySound(0x2F);
            }
        }
        if (bs->spaceType == 2) {
            func_80058910(-1, 0);
        }
        func_8005CE8C(3);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/5CDB0", func_8005C834);
#endif

void func_8005CC3C(void) {
    GW_PLAYER* player = GetPlayerStruct(0);

    func_8004CC8C(0, GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain, player->cur_space));
    func_8004A510();
    func_8004B5C4(1.0f);
    func_8004B838(-1.0f);
    func_8002578C(1);
    SetFadeInTypeAndTime(0xFF, 0x10);
    func_8004B5DC(&GwPlayer[GwSystem.curPlayerIndex].player_obj->coords);
    omAddPrcObj(func_8005C834, 0xEFFF, 0, 0);
    omAddPrcObj(func_8005C6F8, 0x1005, 0, 0);
    omAddPrcObj(func_8005C624, 0x1005, 0, 0);
    func_8005C5E8(1);
    if (func_8000C4A0() < 0x7F) {
        func_8004220C();
    }
}

void func_8005CD4C(s32 overlay, s16 event, s16 fade, s16 music) {
    D_800D898C = overlay;
    D_800D8990 = event;
    D_800D8984 = 2;
    D_800D8986 = fade;
    D_800D8988 = music;
}

void func_8005CD7C(s8 map, s16 event, s16 fade, s16 music) {
    D_800D8984 = 4;
    GwQuest.mapNo = map;
    D_800D8952 = event;
    D_800D8986 = fade;
    D_800D8988 = music;
}

void func_8005CDAC(s16 fade, s16 music) {
    D_800D8984 = 8;
    D_800D8986 = fade;
    D_800D8988 = music;
    func_8005C384();
}

void func_8005CDE0(void) {
    GWQUEST* quest = &GwQuest;
    GW_PLAYER* player = &GwPlayer[0];

    quest->masuPathNo = player->cur_chain;
    quest->masuNo = player->cur_space;
}

void func_8005CE04(void) {
    GWQUEST* quest = &GwQuest;
    GW_PLAYER* player = &GwPlayer[0];

    player->cur_chain = (s8)quest->masuPathNo;
    player->cur_space = (s8)quest->masuNo;
    player->character = quest->charNo;
}

s32 func_8005CE48(s32 flag) {
    return (s8)GwQuest.mgFlag[flag / 8] & (1 << (flag % 8));
}

void func_8005CE8C(s32 flag) {
    GwQuest.mgFlag[flag / 8] |= (1 << (flag % 8));
}

void func_8005CEDC(s32 flag) {
    GwQuest.mgFlag[flag / 8] &= ~(1 << flag % 8);
}