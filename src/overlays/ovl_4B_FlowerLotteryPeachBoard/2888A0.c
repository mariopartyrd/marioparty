#include "common.h"
#include "2888A0.h"

void func_8004DBD4(s32, s32);
s32 func_8004F628(s32, u16, s16, s16);
void func_8004F548(void);
void func_80071788(s32, s16);
s32 func_800F6740_FlowerLotteryPeachBoard(s32 win, u8* avail);

/* func_8006FCF0 is called unprototyped in retail: the s16 cursor reaches it promoted to int
   (sll/sra 16), not narrowed to the prototype's s8. The host calls it normally. */
#define func_8006FCF0_unproto(win, cur, arg) ((s32 (*)())func_8006FCF0)(win, cur, arg)

/* .data (0x800F77C0..0x800F78C0) */
Object* D_800F77C0_FlowerLotteryPeachBoard = NULL;                         /* result model */
Object* D_800F77C4_FlowerLotteryPeachBoard[4] = { NULL, NULL, NULL, NULL }; /* flower per slot */
/* flower positions: x, rotation (unk_30), z; splat's D_800F77D8/D_800F77DC are fields of entry 0 */
Vec3f D_800F77D4_FlowerLotteryPeachBoard[4] = {
    { -250.0f, 300.0f, 1000.0f },
    { -200.0f, 300.0f, 1000.0f },
    { -150.0f, 300.0f, 1000.0f },
    { -100.0f, 300.0f, 1000.0f },
};
Vec3f D_800F7804_FlowerLotteryPeachBoard = { -175.0f, -100.0f, 1000.0f };
Vec3f D_800F7810_FlowerLotteryPeachBoard = { -175.0f, 0.0f, 935.0f };
/* splat's D_800F7834 is entry 2 */
Vec3f D_800F781C_FlowerLotteryPeachBoard[3] = {
    { 295.0f, 0.0f, 785.0f }, { -200.0f, -235.0f, 1310.0f }, { -100.0f, 0.0f, 1310.0f },
};
Vec3f D_800F7840_FlowerLotteryPeachBoard = { 115.0f, 0.0f, 1520.0f };
/* MBModelCreate motion lists: words */
s32 D_800F784C_FlowerLotteryPeachBoard[] = { 2, 0x1003A, 0x1003F };
s32 D_800F7858_FlowerLotteryPeachBoard[] = { 2, 0x2003A, 0x2003F };
s32 D_800F7864_FlowerLotteryPeachBoard[] = { 2, 0x6003A, 0x6003F };
s32 D_800F7870_FlowerLotteryPeachBoard[] = { 2, 0x3003A, 0x3003F };
s32 D_800F787C_FlowerLotteryPeachBoard[] = { 2, 0x4003A, 0x4003F };
s32 D_800F7888_FlowerLotteryPeachBoard[] = { 2, 0x5003A, 0x5003F };
s32* D_800F7894_FlowerLotteryPeachBoard[] = {
    D_800F784C_FlowerLotteryPeachBoard, D_800F7858_FlowerLotteryPeachBoard,
    D_800F7864_FlowerLotteryPeachBoard, D_800F7870_FlowerLotteryPeachBoard,
    D_800F787C_FlowerLotteryPeachBoard, D_800F7888_FlowerLotteryPeachBoard,
};
/* boardWork index of each flower slot's owner (-1 = still available) */
u8 D_800F78AC_FlowerLotteryPeachBoard[4] = { 0x14, 0x15, 0x16, 0x17 };
s32 D_800F78B0_FlowerLotteryPeachBoard[] = { 1, 0xA00A7 };
s32 D_800F78B8_FlowerLotteryPeachBoard[] = { 1, 0xA00A9 };

/* bss */
extern s32 D_800F78F4_FlowerLotteryPeachBoard; /* flowers still available */
extern s32 D_800F78F8_FlowerLotteryPeachBoard;

//is GwCommon.boardWork[18] the start of a u16 array for the data?
void func_800F65E0_FlowerLotteryPeachBoard(void) {
    D_800F78E0_FlowerLotteryPeachBoard = GwSystem.curPlayerIndex;
    if ((u32) ((u16)GwCommon.boardWork[18] - 1) >= 3U) {
        GwCommon.boardWork[18] = 4U;
        GwCommon.boardWork[19] = rand8() & 3 & 0xFF;
        GwCommon.boardWork[20] = GwCommon.boardWork[21] = GwCommon.boardWork[22] = GwCommon.boardWork[23] = -1;
    }
    omInitObjMan(50, 10);
    func_800F76EC_FlowerLotteryPeachBoard();
    func_800F744C_FlowerLotteryPeachBoard();
    func_800544E4();
    func_800546B4(0, GwPlayer[0].turn_status);
    func_800546B4(1, GwPlayer[1].turn_status);
    func_800546B4(2, GwPlayer[2].turn_status);
    func_800546B4(3, GwPlayer[3].turn_status);
    func_8006CEA0();
    omAddPrcObj(func_800F6A48_FlowerLotteryPeachBoard, 0x300, 0, 0);
    omAddObj(0x1000, 0, 0, -1, &func_800F7320_FlowerLotteryPeachBoard);
    SetFadeInTypeAndTime(1, 0x10);
    func_80023448(1);
    func_800234B8(0, 0x78, 0x78, 0x78);
    func_800234B8(1, 0x40, 0x40, 0x60);
    func_80023504(1, 100.0f, 100.0f, 300.0f);
}

s32 func_800F6740_FlowerLotteryPeachBoard(s32 win, u8* avail) {
    s16 buttons[4];
    s32 cpu = 0;
    u8 portMask[4] = { 1, 2, 4, 8 };
    s32 delay = 8;
    s32 i;
    s32 pick;
    s32 n;

    for (i = 0; i < 4; i++) {
        if (i == D_800F78E0_FlowerLotteryPeachBoard) {
            if (GwPlayer[i].flags & 1) {
                cpu = 1;
                buttons[GwPlayer[i].port] = 0x400;
            } else {
                func_8007155C(win, (s16)portMask[GwPlayer[i].port]);
                buttons[GwPlayer[i].port] = -1;
            }
        } else {
            buttons[GwPlayer[i].port] = 0;
        }
    }
    if (cpu != 0) {
        n = 0;
        pick = rand8() % D_800F78F4_FlowerLotteryPeachBoard;
        func_8006DA1C(win, 2, 2);
        for (i = 0; i < 4; i++) {
            if (avail[i] != 0) {
                if (pick == 0) {
                    buttons[GwPlayer[D_800F78E0_FlowerLotteryPeachBoard].port] = -0x8000;
                    if (i == 0) {
                        delay = 16;
                    }
                }
                pick--;
            }
            if (n == 0) {
                func_80070FF8(buttons[0], buttons[1], buttons[2], buttons[3], func_8004DBBC());
            } else {
                func_80070FF8(buttons[0], buttons[1], buttons[2], buttons[3], delay);
            }
            n++;
            if ((avail[i] != 0) & (pick == -1)) {
                break;
            }
        }
    } else {
        func_800710A4(buttons[0], buttons[1], buttons[2], buttons[3]);
    }
    for (i = 0; i < 4; i++) {
        if (avail[i] == 0) {
            func_80071788(win, i);
        }
    }
    i = 0;
    do {
        i = func_8006FCF0_unproto((s16)win, (s16)i, 1);
    } while (avail[i] == 0);
    return i;
}

void func_800F6A48_FlowerLotteryPeachBoard(void) {
    char buf[8];
    u8 avail[4];
    s32 win;
    s32 cost;
    s32 i;
    s32 choice;

    func_800421E0();
    HuPrcSleep(26);
    if (GwPlayer[D_800F78E0_FlowerLotteryPeachBoard].coins == 0) {
        win = CreateTextWindow(0x23, 0x3C, 0x14, 3);
        LoadStringIntoWindow((s16)win, (void*)0x1AE, -1, -1);
        cost = 0;
    } else if (GwPlayer[D_800F78E0_FlowerLotteryPeachBoard].coins < 10) {
        win = CreateTextWindow(0x23, 0x3C, 0x14, 3);
        cost = GwPlayer[D_800F78E0_FlowerLotteryPeachBoard].coins;
        sprintf(buf, "%d", cost);
        func_8006DA5C((s16)win, buf, 0);
        LoadStringIntoWindow((s16)win, (void*)0x1AD, -1, -1);
    } else {
        win = CreateTextWindow(0x23, 0x3C, 0x14, 3);
        LoadStringIntoWindow((s16)win, (void*)0x1A7, -1, -1);
        cost = 10;
    }
    func_8006E070((s16)win, 0);
    ShowTextWindow(win);
    PlaySound(0x435);
    func_8004DBD4(win, D_800F78E0_FlowerLotteryPeachBoard);
    HideTextWindow(win);
    if (cost != 0) {
        func_80055960(D_800F78E0_FlowerLotteryPeachBoard, -cost);
        HuPrcSleep(30);
    }

    win = CreateTextWindow(0x8C, 0x28, 0xB, 7);
    D_800F78F4_FlowerLotteryPeachBoard = 0;
    for (i = 0; i < 4; i++) {
        if (GwCommon.boardWork[D_800F78AC_FlowerLotteryPeachBoard[i]] == -1) {
            avail[i] = 1;
            D_800F78F4_FlowerLotteryPeachBoard++;
        } else {
            avail[i] = 0;
            func_8006DA5C((s16)win, "\x01", i + 1);
        }
    }
    LoadStringIntoWindow((s16)win, (void*)0x1A8, -1, -1);
    func_8006E070((s16)win, 0);
    ShowTextWindow(win);
    PlaySound(0x435);
    while (func_8006FCC0((s16)win) != 0) {
        HuPrcVSleep();
    }
    choice = func_800F6740_FlowerLotteryPeachBoard(win, avail);
    HideTextWindow(win);
    GwCommon.boardWork[D_800F78AC_FlowerLotteryPeachBoard[choice]] = D_800F78E0_FlowerLotteryPeachBoard;
    GwCommon.boardWork[18]--;
    for (i = 0; i < 4; i++) {
        if (choice != i) {
            MBModelDispOff(D_800F77C4_FlowerLotteryPeachBoard[i]);
        }
    }
    func_8004E3E0(0, &D_800F7804_FlowerLotteryPeachBoard, 10, D_800F77C4_FlowerLotteryPeachBoard[choice]);
    HuPrcSleep(10);
    PlaySound(0xA6);
    func_8004F00C(D_800F78E4_FlowerLotteryPeachBoard, 40.0f, -5.0f);
    HuPrcSleep(2);
    func_8004F00C(D_800F77C4_FlowerLotteryPeachBoard[choice], 20.0f, -5.0f);
    PlaySound(0xA7);
    for (i = 0; i < 10; i++) {
        D_800F77C4_FlowerLotteryPeachBoard[choice]->coords.x += 10.0f;
        D_800F77C4_FlowerLotteryPeachBoard[choice]->coords.z += 5.0f;
        HuPrcVSleep();
    }
    func_8004F044(D_800F78E4_FlowerLotteryPeachBoard);
    func_8004F044(D_800F77C4_FlowerLotteryPeachBoard[choice]);

    win = CreateTextWindow(0x64, 0x3C, 0xD, 2);
    LoadStringIntoWindow((s16)win, (void*)0x1A9, -1, -1);
    func_8006E070((s16)win, 0);
    ShowTextWindow(win);
    PlaySound(0x435);
    func_8004DBD4(win, D_800F78E0_FlowerLotteryPeachBoard);
    HideTextWindow(win);
    func_8004E3E0(0, &D_800F781C_FlowerLotteryPeachBoard[0], 10, D_800F78E4_FlowerLotteryPeachBoard);
    func_8004EE14(0, &D_800F781C_FlowerLotteryPeachBoard[0], 5, D_800F78E4_FlowerLotteryPeachBoard);
    HuPrcSleep(10);
    func_8004EE14(0, &D_800F781C_FlowerLotteryPeachBoard[2], 5, D_800F78E4_FlowerLotteryPeachBoard);
    HuPrcSleep(5);
    if (GwCommon.boardWork[19] == choice) {
        D_800F77C0_FlowerLotteryPeachBoard = MBModelCreate(0x82, D_800F78B0_FlowerLotteryPeachBoard);
        PlaySound(0x98);
    } else {
        D_800F77C0_FlowerLotteryPeachBoard = MBModelCreate(0x81, D_800F78B8_FlowerLotteryPeachBoard);
        PlaySound(0x9B);
    }
    func_80025EB4(*D_800F77C0_FlowerLotteryPeachBoard->unk_3C->unk_40, 0, 1);
    func_800A0D00(&D_800F77C0_FlowerLotteryPeachBoard->coords, D_800F781C_FlowerLotteryPeachBoard[2].x, D_800F781C_FlowerLotteryPeachBoard[2].y, D_800F781C_FlowerLotteryPeachBoard[2].z);
    func_8004CCD0(&D_800F77C0_FlowerLotteryPeachBoard->coords, &D_800F78E8_FlowerLotteryPeachBoard->coords, &D_800F77C0_FlowerLotteryPeachBoard->unk_18);
    func_800A0D00(&D_800F77C0_FlowerLotteryPeachBoard->coords, D_800F781C_FlowerLotteryPeachBoard[1].x, D_800F781C_FlowerLotteryPeachBoard[1].y, D_800F781C_FlowerLotteryPeachBoard[1].z);
    func_8004E3E0(0, &D_800F781C_FlowerLotteryPeachBoard[2], 20, D_800F77C0_FlowerLotteryPeachBoard);
    D_800F78F8_FlowerLotteryPeachBoard = func_8004F628(0xA013C, 0x47FE, 100, 128);
    func_80025EB4(*D_800F77C0_FlowerLotteryPeachBoard->unk_3C->unk_40, 3, 0);
    func_8004F504(D_800F77C0_FlowerLotteryPeachBoard);
    func_8004F4D4(D_800F77C0_FlowerLotteryPeachBoard, 0, 2);
    func_800503B0(D_800F78E0_FlowerLotteryPeachBoard, 1);
    HuPrcSleep(30);
    if (GwCommon.boardWork[19] == choice) {
        HuPrcSleep(5);
        func_8004F4D4(D_800F78E8_FlowerLotteryPeachBoard, 1, 0);
        func_80060468(0x44A, GwPlayer[D_800F78E0_FlowerLotteryPeachBoard].character);
        PlaySound(0xA6);
        func_8004F00C(D_800F78E4_FlowerLotteryPeachBoard, 40.0f, -5.0f);
        HuPrcSleep(20);
        if (_CheckFlag(0xD) == 0) {
            win = CreateTextWindow(0x28, 0x3C, 0x13, 4);
            LoadStringIntoWindow((s16)win, (void*)0x1AA, -1, -1);
        } else {
            win = CreateTextWindow(0x46, 0x3C, 0x11, 4);
            LoadStringIntoWindow((s16)win, (void*)0x1AB, -1, -1);
        }
        func_8006E070((s16)win, 0);
        ShowTextWindow(win);
        PlaySound(0x435);
        func_8004DBD4(win, D_800F78E0_FlowerLotteryPeachBoard);
        HideTextWindow(win);
        GwCommon.boardWork[24] = 1;
    } else {
        func_8004F4D4(D_800F78E8_FlowerLotteryPeachBoard, 0, 0);
        func_8004F40C(D_800F78E8_FlowerLotteryPeachBoard, -1, 2);
        func_80060468(0x451, GwPlayer[D_800F78E0_FlowerLotteryPeachBoard].character);
        HuPrcSleep(20);
        win = CreateTextWindow(0x32, 0x3C, 0x10, 4);
        LoadStringIntoWindow((s16)win, (void*)0x1AC, -1, -1);
        func_8006E070((s16)win, 0);
        ShowTextWindow(win);
        PlaySound(0x435);
        func_8004DBD4(win, D_800F78E0_FlowerLotteryPeachBoard);
        HideTextWindow(win);
        GwCommon.boardWork[24] = 0;
    }
    D_800F5144 = 1;
    while (TRUE) {
        HuPrcVSleep();
    }
}

void func_800F72D4_FlowerLotteryPeachBoard(void) {
    if (func_80072718() == 0) {
        func_800F7794_FlowerLotteryPeachBoard();
        func_800F7658_FlowerLotteryPeachBoard();
        func_80054654();
        func_80070ED4();
        omOvlReturnEx(1);
    }
}

void func_800F7320_FlowerLotteryPeachBoard(omObjData* arg0) {
    if (D_800F5144 != 0) {
        func_800726AC(1, 0x10);
        arg0->func_ptr = &func_800F72D4_FlowerLotteryPeachBoard;
    }
}

void func_800F7364_FlowerLotteryPeachBoard(void) {
    void* temp_s0;

    D_800F78EC_FlowerLotteryPeachBoard = func_80064EF4(1, 5);
    temp_s0 = DataRead(0xA0101);
    D_800F78F0_FlowerLotteryPeachBoard = func_800678A4(temp_s0);
    DataClose(temp_s0);
    func_80067208((s16)D_800F78EC_FlowerLotteryPeachBoard, 0, (s16)D_800F78F0_FlowerLotteryPeachBoard, 0);
    func_80067384((s16)D_800F78EC_FlowerLotteryPeachBoard, 0, 0x47F4);
    func_800674BC((s16)D_800F78EC_FlowerLotteryPeachBoard, 0, 0x1000U);
    func_80066DC4((s16)D_800F78EC_FlowerLotteryPeachBoard, 0, 0xA0, 0x78);
}

void func_800F7420_FlowerLotteryPeachBoard(void) {
    func_80064D38((s16)D_800F78EC_FlowerLotteryPeachBoard);
    func_80067704((s16)D_800F78F0_FlowerLotteryPeachBoard);
}

void func_800F744C_FlowerLotteryPeachBoard(void) {
    s16 models[4] = { 0x7E, 0x7C, 0x7D, 0x7F };
    s32 i;

    MBModelInit();
    func_8004F2AC();
    func_8004F548();
    D_800F78E4_FlowerLotteryPeachBoard = MBModelCreate(0xB, NULL);
    func_800A0D00(&D_800F78E4_FlowerLotteryPeachBoard->coords, D_800F7810_FlowerLotteryPeachBoard.x, D_800F7810_FlowerLotteryPeachBoard.y, D_800F7810_FlowerLotteryPeachBoard.z);
    D_800F78E8_FlowerLotteryPeachBoard = MBModelCreate(func_80052F04(D_800F78E0_FlowerLotteryPeachBoard), D_800F7894_FlowerLotteryPeachBoard[GwPlayer[D_800F78E0_FlowerLotteryPeachBoard].character]);
    func_800A0D00(&D_800F78E8_FlowerLotteryPeachBoard->coords, D_800F7840_FlowerLotteryPeachBoard.x, D_800F7840_FlowerLotteryPeachBoard.y, D_800F7840_FlowerLotteryPeachBoard.z);
    func_8004CCD0(&D_800F78E8_FlowerLotteryPeachBoard->coords, &D_800F78E4_FlowerLotteryPeachBoard->coords, &D_800F78E8_FlowerLotteryPeachBoard->unk_18);
    func_8004CCD0(&D_800F78E4_FlowerLotteryPeachBoard->coords, &D_800F78E8_FlowerLotteryPeachBoard->coords, &D_800F78E4_FlowerLotteryPeachBoard->unk_18);
    for (i = 0; i < 4; i++) {
        D_800F77C4_FlowerLotteryPeachBoard[i] = MBModelCreate(models[i], NULL);
        func_800A0D00(&D_800F77C4_FlowerLotteryPeachBoard[i]->coords, D_800F77D4_FlowerLotteryPeachBoard[i].x, -100.0f, D_800F77D4_FlowerLotteryPeachBoard[i].z);
        D_800F77C4_FlowerLotteryPeachBoard[i]->unk_30 = D_800F77D4_FlowerLotteryPeachBoard[i].y;
        if (GwCommon.boardWork[D_800F78AC_FlowerLotteryPeachBoard[i]] != -1) {
            MBModelDispOff(D_800F77C4_FlowerLotteryPeachBoard[i]);
        }
    }
}

void func_800F7658_FlowerLotteryPeachBoard(void) {
    s32 i;

    MBModelKill(D_800F78E8_FlowerLotteryPeachBoard);
    MBModelKill(D_800F78E4_FlowerLotteryPeachBoard);
    
    if (D_800F77C0_FlowerLotteryPeachBoard != NULL) {
        MBModelKill(D_800F77C0_FlowerLotteryPeachBoard);
    }
    
    for (i = 0; i < 4; i++) {
        if (D_800F77C4_FlowerLotteryPeachBoard[i] != NULL) {
            MBModelKill(D_800F77C4_FlowerLotteryPeachBoard[i]);
        }
    }
    func_8004F2EC();
    func_8004F5F0();
}

void func_800F76EC_FlowerLotteryPeachBoard(void) {
    func_800178A0(1);
    func_80017660(0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    LoadBackgroundData(FE2310_ROM_START);
    LoadBackgroundIndex(9);
    func_800F7364_FlowerLotteryPeachBoard();
}

void func_800F7794_FlowerLotteryPeachBoard(void) {
    func_8004A140();
    func_80049F0C();
    func_800F7420_FlowerLotteryPeachBoard();
}
