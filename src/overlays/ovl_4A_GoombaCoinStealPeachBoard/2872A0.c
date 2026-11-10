#include "common.h"
#include "2872A0.h"

void func_8004DBD4(s32, s32);
s32 func_8004F628(s32, u16, s16, s16);
void func_800F6AE0_GoombaCoinStealPeachBoard(omObjData*);
void func_800F6BC4_GoombaCoinStealPeachBoard(omObjData*);

/* .data (0x800F7AE0..0x800F7BD0) */
Object* D_800F7AE0_GoombaCoinStealPeachBoard = NULL; /* bowser model */
Object* D_800F7AE4_GoombaCoinStealPeachBoard = NULL; /* character model */
Object* D_800F7AE8_GoombaCoinStealPeachBoard[3] = { NULL, NULL, NULL }; /* coin models */
omObjData* D_800F7AF4_GoombaCoinStealPeachBoard[3] = { NULL, NULL, NULL };
s32 D_800F7B00_GoombaCoinStealPeachBoard = 0;
/* splat's D_800F7B08 is .y of this vector */
Vec3f D_800F7B04_GoombaCoinStealPeachBoard = { 415.0f, 0.0f, 935.0f };
Vec3f D_800F7B10_GoombaCoinStealPeachBoard = { -80.0f, -235.0f, 1310.0f };
Vec3f D_800F7B1C_GoombaCoinStealPeachBoard = { 115.0f, 0.0f, 1520.0f };
Vec3f D_800F7B28_GoombaCoinStealPeachBoard = { -145.0f, 0.0f, 1440.0f };
/* MBModelCreate motion lists: words */
s32 D_800F7B34_GoombaCoinStealPeachBoard[] = { 2, 0x4E, 0x49 };
s32 D_800F7B40_GoombaCoinStealPeachBoard[] = { 2, 0x10095, 0x10000 };
s32 D_800F7B4C_GoombaCoinStealPeachBoard[] = { 2, 0x20095, 0x20000 };
s32 D_800F7B58_GoombaCoinStealPeachBoard[] = { 2, 0x60095, 0x60000 };
s32 D_800F7B64_GoombaCoinStealPeachBoard[] = { 2, 0x30095, 0x30000 };
s32 D_800F7B70_GoombaCoinStealPeachBoard[] = { 2, 0x40095, 0x40000 };
s32 D_800F7B7C_GoombaCoinStealPeachBoard[] = { 2, 0x50095, 0x50000 };
s32* D_800F7B88_GoombaCoinStealPeachBoard[] = {
    D_800F7B40_GoombaCoinStealPeachBoard, D_800F7B4C_GoombaCoinStealPeachBoard,
    D_800F7B58_GoombaCoinStealPeachBoard, D_800F7B64_GoombaCoinStealPeachBoard,
    D_800F7B70_GoombaCoinStealPeachBoard, D_800F7B7C_GoombaCoinStealPeachBoard,
};
/* CPU chance (percent) of paying, by [coins>=60][stolen-cake count band][rank band] */
u8 D_800F7BA0_GoombaCoinStealPeachBoard[] = {
    0x46, 0x55, 0x5F, 0x32, 0x3C, 0x46, 0x50, 0x5A, 0x64,
    0x50, 0x5A, 0x64, 0x46, 0x50, 0x5A, 0x55, 0x5F, 0x64,
};
u8 D_800F7BB4_GoombaCoinStealPeachBoard[] = {
    0x3C, 0x46, 0x46, 0x5F, 0x50, 0x50, 0x3C, 0x46, 0x50,
    0x3C, 0x46, 0x46, 0x46, 0x50, 0x50, 0x3C, 0x46, 0x50,
};

/* bss */
extern s32 D_800F7BF8_GoombaCoinStealPeachBoard;

void func_800F65E0_GoombaCoinStealPeachBoard(void) {
    D_800F7BE0_GoombaCoinStealPeachBoard = GwSystem.curPlayerIndex;
    omInitObjMan(0x32, 0xA);
    func_800F7A00_GoombaCoinStealPeachBoard();
    func_800F77D0_GoombaCoinStealPeachBoard();
    func_800544E4();
    func_800546B4(0, GwPlayer[0].turn_status);
    func_800546B4(1, GwPlayer[1].turn_status);
    func_800546B4(2, GwPlayer[2].turn_status);
    func_800546B4(3, GwPlayer[3].turn_status);
    func_8006CEA0();
    omAddPrcObj(&func_800F6CB0_GoombaCoinStealPeachBoard, 0x300, 0, 0);
    omAddObj(0x1000, 0, 0, -1, &func_800F7688_GoombaCoinStealPeachBoard);
    if (D_800C597A != 0) {
        SetFadeInTypeAndTime(6, 8);
    } else {
        SetFadeInTypeAndTime(1, 16);
    }
}

// scheduling: retail puts the rand compare in v1 and the maxTurns-1 addiu after both loads (masked 2; tried swapped operands of both compares, the rand result in a local)
#ifdef NON_MATCHING
s32 func_800F66D0_GoombaCoinStealPeachBoard(void) {
    u8* table;
    s32 rank;
    s32 idx;
    s32 i;
    s32 max;
    s32 min;

    if (GwPlayer[D_800F7BE0_GoombaCoinStealPeachBoard].cpu_difficulty_copy == 0) {
        table = D_800F7BB4_GoombaCoinStealPeachBoard;
    } else {
        table = D_800F7BA0_GoombaCoinStealPeachBoard;
    }
    if (GwSystem.maxTurns - GwSystem.currentTurn >= 2) {
        rank = func_8004FEBC(D_800F7BE0_GoombaCoinStealPeachBoard);
        if (rank == 0) {
            idx = 0;
        } else {
            idx = 2;
            if (rank >= 0) {
                if (rank < 3) {
                    idx = 1;
                }
            }
        }
        if (GwCommon.boardWork[14] >= 5) {
            if (GwCommon.boardWork[14] < 9) {
                idx += 3;
            } else {
                idx += 6;
            }
        }
        if (GwPlayer[D_800F7BE0_GoombaCoinStealPeachBoard].coins >= 60) {
            idx += 9;
        }
        if (func_8005021C(100.0f) < table[idx]) {
            return 1;
        }
    } else if (GwSystem.maxTurns - 1 == GwSystem.currentTurn) {
        max = -1;
        min = 1000;
        for (i = 0; i < 4; i++) {
            if (i != D_800F7BE0_GoombaCoinStealPeachBoard) {
                if (max < GwPlayer[i].coins) {
                    max = GwPlayer[i].coins;
                }
                if (GwPlayer[i].coins < min) {
                    min = GwPlayer[i].coins;
                }
            }
        }
        if (!(GwPlayer[D_800F7BE0_GoombaCoinStealPeachBoard].coins - 40 < max
              && max < GwPlayer[D_800F7BE0_GoombaCoinStealPeachBoard].coins + 50)) {
            return 1;
        }
    }
    return 2;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4A_GoombaCoinStealPeachBoard/2872A0", func_800F66D0_GoombaCoinStealPeachBoard);
#endif

// loop invariant motion: GCC hoists the -1 button value into s7 (retail loads it at the store); 169 vs 167 instructions, masked 18
#ifdef NON_MATCHING
s32 func_800F68B8_GoombaCoinStealPeachBoard(s32 win) {
    s16 buttons[4];
    s32 presses = 0;
    u8 portMask[4] = "\x01\x02\x04\x08";
    s32 i;
    s32 n;

    for (i = 0; i < 4; i++) {
        if (i == D_800F7BE0_GoombaCoinStealPeachBoard) {
            if (GwPlayer[i].flags & 1) {
                presses = func_800F66D0_GoombaCoinStealPeachBoard();
                buttons[GwPlayer[i].port] = 0x400;
            } else {
                func_8007155C(win, portMask[GwPlayer[i].port]);
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
                buttons[GwPlayer[D_800F7BE0_GoombaCoinStealPeachBoard].port] = -0x8000;
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
    return func_8006FCF0(win, 0, 1);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4A_GoombaCoinStealPeachBoard/2872A0", func_800F68B8_GoombaCoinStealPeachBoard);
#endif
#ifndef NON_MATCHING
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_4A_GoombaCoinStealPeachBoard/2872A0", D_800F7BD0_GoombaCoinStealPeachBoard);
#endif

void func_800F6AE0_GoombaCoinStealPeachBoard(omObjData* obj) {
    if (func_8004F018(D_800F7AE8_GoombaCoinStealPeachBoard[obj->work[0]]) == 0) {
        MBModelKill(D_800F7AE8_GoombaCoinStealPeachBoard[obj->work[0]]);
        D_800F7AE8_GoombaCoinStealPeachBoard[obj->work[0]] = NULL;
        D_800F7AF4_GoombaCoinStealPeachBoard[obj->work[0]] = NULL;
        omDelObj(obj);
        return;
    }
    D_800F7AE8_GoombaCoinStealPeachBoard[obj->work[0]]->coords.x -= 5.0f;
    D_800F7AE8_GoombaCoinStealPeachBoard[obj->work[0]]->coords.z += 5.0f;
}

void func_800F6BC4_GoombaCoinStealPeachBoard(omObjData* obj) {
    if (obj->work[0] != 0) {
        obj->work[0]--;
        return;
    }
    if (obj->trans.y == 0.0f) {
        D_800F7AE4_GoombaCoinStealPeachBoard->unk_3C->unk_2C += 1.0f;
        if (D_800F7AE4_GoombaCoinStealPeachBoard->unk_3C->unk_2C >= 10.0f) {
            omDelObj(obj);
        }
    } else {
        obj->trans.y -= 50.0f;
        D_800F7AE4_GoombaCoinStealPeachBoard->coords.y = obj->trans.y;
        if (obj->trans.y <= 0.0f) {
            D_800F7AE4_GoombaCoinStealPeachBoard->coords.y = 0.0f;
            obj->work[0] = 15;
        }
    }
}

// block layout: GCC cross-jumps the 0x195 window path into the 0x197 path (retail keeps it separate)
#ifdef NON_MATCHING
void func_800F6CB0_GoombaCoinStealPeachBoard(void) {
    Vec3f pos;
    Object* obj;
    omObjData* od;
    omObjData* drop;
    f32 f;
    s32 choice;
    s32 i;
    s32 win;

    choice = 0;
    if (D_800C597A != 0) {
        HuPrcSleep(8);
    } else {
        func_800421E0();
        HuPrcSleep(26);
    }
    if (D_800C597A == 0) {
        PlaySound(0x96);
        pos.x = D_800F7BE4_GoombaCoinStealPeachBoard->coords.x - 100.0f;
        pos.y = D_800F7BE4_GoombaCoinStealPeachBoard->coords.y;
        pos.z = D_800F7BE4_GoombaCoinStealPeachBoard->coords.z;
        func_8004CCD0(&D_800F7BE4_GoombaCoinStealPeachBoard->coords, &pos, &D_800F7BE4_GoombaCoinStealPeachBoard->unk_18);
        for (f = D_800F7B04_GoombaCoinStealPeachBoard.x; f >= -55.0f; f -= 50.0f) {
            D_800F7BE4_GoombaCoinStealPeachBoard->coords.x = f;
            func_8004CCD0(&D_800F7BE8_GoombaCoinStealPeachBoard->coords, &D_800F7BE4_GoombaCoinStealPeachBoard->coords, &D_800F7BE8_GoombaCoinStealPeachBoard->unk_18);
            HuPrcVSleep();
        }
        D_800F7BE4_GoombaCoinStealPeachBoard->coords.x = -55.0f;
        HuPrcVSleep();
        func_8004EE14(0, &D_800F7BE8_GoombaCoinStealPeachBoard->coords, 10, D_800F7BE4_GoombaCoinStealPeachBoard);
        HuPrcSleep(10);
    }
    if (GwPlayer[D_800F7BE0_GoombaCoinStealPeachBoard].coins < 30) {
        win = CreateTextWindow(0x50, 0x3C, 0x11, 5);
        LoadStringIntoWindow((s16)win, (void*)0x195, -1, -1);
        func_8006E070((s16)win, 0);
        ShowTextWindow(win);
        PlaySound(0x435);
    } else {
        win = CreateTextWindow(0x73, 0x3C, 0xF, 6);
        LoadStringIntoWindow((s16)win, (void*)0x1A3, -1, -1);
        func_8006E070((s16)win, 0);
        ShowTextWindow(win);
        PlaySound(0x435);
        while (func_8006FCC0((s16)win) != 0) {
            HuPrcVSleep();
        }
        choice = func_800F68B8_GoombaCoinStealPeachBoard(win);
        HideTextWindow(win);
        if (choice == 2) {
            D_800F7B00_GoombaCoinStealPeachBoard = 1;
            goto done;
        } else if (choice == 1) {
                win = CreateTextWindow(0x73, 0x3C, 6, 2);
                LoadStringIntoWindow((s16)win, (void*)0x197, -1, -1);
                func_8006E070((s16)win, 0);
                ShowTextWindow(win);
                PlaySound(0x435);
            } else {
                func_80055960(D_800F7BE0_GoombaCoinStealPeachBoard, -30);
                GwCommon.boardWork[GwCommon.boardWork[14]] = D_800F7BE0_GoombaCoinStealPeachBoard;
                func_8004EE14(0, &D_800F7B10_GoombaCoinStealPeachBoard, 10, D_800F7BE4_GoombaCoinStealPeachBoard);
                HuPrcSleep(10);
                for (i = 0; i < 1; i++) {
                    PlaySound(0xA6);
                    func_8004F00C(D_800F7BE4_GoombaCoinStealPeachBoard, 40.0f, -5.0f);
                    HuPrcSleep(10);
                    PlaySound(0xA7);
                    D_800F7AE8_GoombaCoinStealPeachBoard[i] = MBModelCreate(0x58, NULL);
                    D_800F7AE8_GoombaCoinStealPeachBoard[i]->coords.x = D_800F7BE4_GoombaCoinStealPeachBoard->coords.x;
                    D_800F7AE8_GoombaCoinStealPeachBoard[i]->coords.y = D_800F7BE4_GoombaCoinStealPeachBoard->coords.y - 30.0f;
                    D_800F7AE8_GoombaCoinStealPeachBoard[i]->coords.z = D_800F7BE4_GoombaCoinStealPeachBoard->coords.z;
                    D_800F7AE8_GoombaCoinStealPeachBoard[i]->unk_30 = D_800F7BE4_GoombaCoinStealPeachBoard->unk_30 + 30.0f;
                    od = D_800F7AF4_GoombaCoinStealPeachBoard[i] = omAddObj(0x1000, 0, 0, -1, func_800F6AE0_GoombaCoinStealPeachBoard);
                    od->work[0] = i;
                    func_8004F00C(D_800F7AE8_GoombaCoinStealPeachBoard[i], 20.0f, -5.0f);
                    func_8004F044(D_800F7BE4_GoombaCoinStealPeachBoard);
                    HuPrcSleep(10);
                }
                HuPrcSleep(10);
                for (i = 0; i < 2; i++) {
                    PlaySound(0xA6);
                    func_8004F00C(D_800F7BE4_GoombaCoinStealPeachBoard, 20.0f, -5.0f);
                    func_8004F044(D_800F7BE4_GoombaCoinStealPeachBoard);
                }
                HuPrcSleep(10);
                pos.x = 295.0f;
                pos.y = 0.0f;
                pos.z = 785.0f;
                func_8004E3E0(0, &pos, 10, D_800F7BE4_GoombaCoinStealPeachBoard);
                func_8004EE14(0, &pos, 10, D_800F7BE4_GoombaCoinStealPeachBoard);
                HuPrcSleep(10);
                func_8004EE14(0, &D_800F7B10_GoombaCoinStealPeachBoard, 10, D_800F7BE4_GoombaCoinStealPeachBoard);
                HuPrcSleep(10);
                PlaySound(0xA8);
                obj = D_800F7AE0_GoombaCoinStealPeachBoard = MBModelCreate(0xC, D_800F7B34_GoombaCoinStealPeachBoard);
                obj->coords.x = D_800F7B10_GoombaCoinStealPeachBoard.x - 235.0f;
                obj->coords.y = D_800F7B10_GoombaCoinStealPeachBoard.y;
                obj->coords.z = D_800F7B10_GoombaCoinStealPeachBoard.z;
                obj->unk_18.x = 1.0f;
                obj->unk_18.y = 0.0f;
                obj->unk_18.z = 0.0f;
                MBMotionSet(obj, 0, 0);
                func_8004F40C(D_800F7AE0_GoombaCoinStealPeachBoard, 1, 2);
                obj = D_800F7AE4_GoombaCoinStealPeachBoard = MBModelCreate(GwPlayer[D_800F7BE0_GoombaCoinStealPeachBoard].character + 0x1D, NULL);
                obj->coords.x = D_800F7B28_GoombaCoinStealPeachBoard.x;
                obj->coords.y = D_800F7B28_GoombaCoinStealPeachBoard.y + 1000.0f;
                obj->coords.z = D_800F7B28_GoombaCoinStealPeachBoard.z;
                D_800F7BF8_GoombaCoinStealPeachBoard = func_8004F628(0xA013C, 0x47FE, 100, 128);
                for (f = D_800F7AE0_GoombaCoinStealPeachBoard->coords.y; f < 0.0f; f += 20.0) {
                    D_800F7AE0_GoombaCoinStealPeachBoard->coords.x += 20.0;
                    D_800F7AE0_GoombaCoinStealPeachBoard->coords.y = f;
                    HuPrcVSleep();
                }
                D_800F7AE0_GoombaCoinStealPeachBoard->coords.y = 0.0f;
                HuPrcVSleep();
                PlaySound(0xA6);
                func_8004F00C(D_800F7BE4_GoombaCoinStealPeachBoard, 40.0f, -5.0f);
                func_8004F044(D_800F7BE4_GoombaCoinStealPeachBoard);
                for (i = 0; i < 25; i++) {
                    switch (i) {
                    case 14:
                    case 24:
                        PlaySound(0x9D);
                        break;
                    }
                    HuPrcVSleep();
                }
                func_8004EE14(0, &D_800F7BE8_GoombaCoinStealPeachBoard->coords, 5, D_800F7BE4_GoombaCoinStealPeachBoard);
                HuPrcSleep(5);
                drop = omAddObj(0x1000, 0, 0, -1, func_800F6BC4_GoombaCoinStealPeachBoard);
                drop->trans.y = D_800F7AE4_GoombaCoinStealPeachBoard->coords.y;
                drop->work[0] = 0;
                win = CreateTextWindow(0x9B, 0x3C, 9, 2);
                LoadStringIntoWindow((s16)win, (void*)0x198, -1, -1);
                func_8006E070((s16)win, 0);
                ShowTextWindow(win);
                PlaySound(0x435);
                func_8004F4D4(D_800F7BE8_GoombaCoinStealPeachBoard, 0, 0);
                func_8004DBD4(win, D_800F7BE0_GoombaCoinStealPeachBoard);
                HideTextWindow(win);
                func_8004F504(D_800F7BE8_GoombaCoinStealPeachBoard);
                win = CreateTextWindow(0x82, 0x3C, 0xC, 3);
                LoadStringIntoWindow((s16)win, (void*)0x199, -1, -1);
                func_8006E070((s16)win, 0);
                ShowTextWindow(win);
                PlaySound(0x435);
                func_8004F4D4(D_800F7BE8_GoombaCoinStealPeachBoard, 1, 2);
        }
    }
    func_8004DBD4(win, D_800F7BE0_GoombaCoinStealPeachBoard);
    HideTextWindow(win);
done:
    if (choice != 2) {
        PlaySound(0x97);
        pos.x = D_800F7B04_GoombaCoinStealPeachBoard.x;
        pos.y = D_800F7BE4_GoombaCoinStealPeachBoard->coords.y;
        pos.z = D_800F7BE4_GoombaCoinStealPeachBoard->coords.z;
        func_8004EE14(0, &pos, 10, D_800F7BE4_GoombaCoinStealPeachBoard);
        for (f = D_800F7BE4_GoombaCoinStealPeachBoard->coords.x; f <= 2.0f * D_800F7B04_GoombaCoinStealPeachBoard.x; f += 50.0f) {
            D_800F7BE4_GoombaCoinStealPeachBoard->coords.x = f;
            HuPrcVSleep();
        }
    }
    D_800F5144 = 1;
    while (TRUE) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4A_GoombaCoinStealPeachBoard/2872A0", func_800F6CB0_GoombaCoinStealPeachBoard);
#endif

void func_800F7610_GoombaCoinStealPeachBoard(void) {
    if (func_80072718() == 0) {
        func_800F7AA8_GoombaCoinStealPeachBoard();
        func_800F7928_GoombaCoinStealPeachBoard();
        func_80054654();
        func_80070ED4();
        if (D_800F7B00_GoombaCoinStealPeachBoard == 0) {
            omOvlReturnEx(1);
            return;
        }
        func_8004F284();
        func_8004F28C(0x4A, 1);
    }
}

void func_800F7688_GoombaCoinStealPeachBoard(omObjData* arg0) {
    if (D_800F5144 != 0) {
        if (D_800F7B00_GoombaCoinStealPeachBoard != 0) {
            func_800726AC(6, 8);
        } else {
            func_800726AC(1, 16);
        }
        arg0->func_ptr = &func_800F7610_GoombaCoinStealPeachBoard;
    }
}


void func_800F76E8_GoombaCoinStealPeachBoard(void) {
    void* temp_s0;

    D_800F7BEC_GoombaCoinStealPeachBoard = func_80064EF4(1, 5);
    temp_s0 = DataRead(0xA0101);
    D_800F7BF0_GoombaCoinStealPeachBoard = func_800678A4(temp_s0);
    DataClose(temp_s0);
    func_80067208((s16)D_800F7BEC_GoombaCoinStealPeachBoard, 0, (s16)D_800F7BF0_GoombaCoinStealPeachBoard, 0);
    func_80067384((s16)D_800F7BEC_GoombaCoinStealPeachBoard, 0, 0x47F4);
    func_800674BC((s16)D_800F7BEC_GoombaCoinStealPeachBoard, 0, 0x1000);
    func_80066DC4((s16)D_800F7BEC_GoombaCoinStealPeachBoard, 0, 0xA0, 0x78);
}

void func_800F77A4_GoombaCoinStealPeachBoard(void) {
    func_80064D38((s16)D_800F7BEC_GoombaCoinStealPeachBoard);
    func_80067704((s16)D_800F7BF0_GoombaCoinStealPeachBoard);
}

void func_800F77D0_GoombaCoinStealPeachBoard(void) {
    MBModelInit();
    func_8004F2AC();
    func_8004F548();
    D_800F7BE4_GoombaCoinStealPeachBoard = MBModelCreate(0xB, NULL);

    if (D_800C597A == 0) {
        D_800F7BE4_GoombaCoinStealPeachBoard->coords.x = D_800F7B04_GoombaCoinStealPeachBoard.x;
        D_800F7BE4_GoombaCoinStealPeachBoard->coords.y = D_800F7B04_GoombaCoinStealPeachBoard.y;
        D_800F7BE4_GoombaCoinStealPeachBoard->coords.z = D_800F7B04_GoombaCoinStealPeachBoard.z;
    } else {
        D_800F7BE4_GoombaCoinStealPeachBoard->coords.x = -55.0f;
        D_800F7BE4_GoombaCoinStealPeachBoard->coords.y = D_800F7B04_GoombaCoinStealPeachBoard.y;
        D_800F7BE4_GoombaCoinStealPeachBoard->coords.z = D_800F7B04_GoombaCoinStealPeachBoard.z;
    }

    D_800F7BE8_GoombaCoinStealPeachBoard = MBModelCreate(func_80052F04(D_800F7BE0_GoombaCoinStealPeachBoard), D_800F7B88_GoombaCoinStealPeachBoard[GwPlayer[D_800F7BE0_GoombaCoinStealPeachBoard].character]);
    D_800F7BE8_GoombaCoinStealPeachBoard->coords.x = D_800F7B1C_GoombaCoinStealPeachBoard.x;
    D_800F7BE8_GoombaCoinStealPeachBoard->coords.y = D_800F7B1C_GoombaCoinStealPeachBoard.y;
    D_800F7BE8_GoombaCoinStealPeachBoard->coords.z = D_800F7B1C_GoombaCoinStealPeachBoard.z;
    func_8004CCD0(&D_800F7BE8_GoombaCoinStealPeachBoard->coords, &D_800F7BE4_GoombaCoinStealPeachBoard->coords, &D_800F7BE8_GoombaCoinStealPeachBoard->unk_18);

    if (D_800C597A != 0) {
        func_8004EE14(0, &D_800F7BE8_GoombaCoinStealPeachBoard->coords, 1, D_800F7BE4_GoombaCoinStealPeachBoard);
    }
}

void func_800F7928_GoombaCoinStealPeachBoard(void) {
    s32 i;
    
    MBModelKill(D_800F7BE4_GoombaCoinStealPeachBoard);
    
    if (D_800F7AE0_GoombaCoinStealPeachBoard != NULL) {
        MBModelKill(D_800F7AE0_GoombaCoinStealPeachBoard);
    }
    
    if (D_800F7AE4_GoombaCoinStealPeachBoard != NULL) {
        MBModelKill(D_800F7AE4_GoombaCoinStealPeachBoard);
    }
    
    for (i = 0; i < 3; i++) {
        if (D_800F7AE8_GoombaCoinStealPeachBoard[i] != NULL) {
            MBModelKill(D_800F7AE8_GoombaCoinStealPeachBoard[i]);
        }
        
        if (D_800F7AF4_GoombaCoinStealPeachBoard[i] != 0) {
            omDelObj(D_800F7AF4_GoombaCoinStealPeachBoard[i]);
        }
    }

    MBModelKill(D_800F7BE8_GoombaCoinStealPeachBoard);
    func_8004F2EC();
    func_8004F5F0();
}

void func_800F7A00_GoombaCoinStealPeachBoard(void) {
    func_800178A0(1);
    func_80017660(0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    LoadBackgroundData(FE2310_ROM_START);
    LoadBackgroundIndex(9);
    func_800F76E8_GoombaCoinStealPeachBoard();
}

void func_800F7AA8_GoombaCoinStealPeachBoard(void) {
    func_8004A140();
    func_80049F0C();
    func_800F77A4_GoombaCoinStealPeachBoard();
}
