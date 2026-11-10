#include "common.h"
#include "engine/process.h"
#include "28ECA0.h"

Object* D_800F8070_FlyGuyWarioBoard = NULL;
omObjData* D_800F8074_FlyGuyWarioBoard = NULL;
omObjData* D_800F8078_FlyGuyWarioBoard = NULL;
s32 D_800F807C_FlyGuyWarioBoard = 0;
/* coin cost of each Fly Guy offer */
u8 D_800F8080_FlyGuyWarioBoard[2] = {10, 10};
Vec3f D_800F8084_FlyGuyWarioBoard = {-80.0f, 0.0f, 1310.0f};
Vec3f D_800F8090_FlyGuyWarioBoard = {80.0f, 0.0f, 1520.0f};
Vec3f D_800F809C_FlyGuyWarioBoard = {160.0f, 0.0f, 1730.0f};
Vec3f D_800F80A8_FlyGuyWarioBoard = {45.0f, 0.0f, 1450.0f};
Vec3f D_800F80B4_FlyGuyWarioBoard = {-125.0f, 0.0f, 1240.0f};

s32 D_800F80C0_FlyGuyWarioBoard[] = {0x00000002, 0x00010001, 0x00010003};
s32 D_800F80CC_FlyGuyWarioBoard[] = {0x00000002, 0x00020001, 0x00020003};
s32 D_800F80D8_FlyGuyWarioBoard[] = {0x00000002, 0x00060001, 0x00060003};
s32 D_800F80E4_FlyGuyWarioBoard[] = {0x00000002, 0x00030001, 0x00030003};
s32 D_800F80F0_FlyGuyWarioBoard[] = {0x00000002, 0x00040001, 0x00040003};
s32 D_800F80FC_FlyGuyWarioBoard[] = {0x00000002, 0x00050001, 0x00050038};

s32* D_800F8108_FlyGuyWarioBoard[] = {
    D_800F80C0_FlyGuyWarioBoard, D_800F80CC_FlyGuyWarioBoard,
    D_800F80D8_FlyGuyWarioBoard, D_800F80E4_FlyGuyWarioBoard,
    D_800F80F0_FlyGuyWarioBoard, D_800F80FC_FlyGuyWarioBoard
};

void func_800F65E0_FlyGuyWarioBoard(void) {
    D_800F8230_FlyGuyWarioBoard = GwSystem.curPlayerIndex;
    omInitObjMan(50, 10);
    func_800F7FA4_FlyGuyWarioBoard();
    func_800F7DF0_FlyGuyWarioBoard();
    func_800544E4();
    func_800546B4(0, GwPlayer[0].turn_status);
    func_800546B4(1, GwPlayer[1].turn_status);
    func_800546B4(2, GwPlayer[2].turn_status);
    func_800546B4(3, GwPlayer[3].turn_status);
    func_8006CEA0();
    omAddPrcObj(func_800F742C_FlyGuyWarioBoard, 0x300, 0, 0);
    omAddObj(0x1000, 0, 0, -1, &func_800F7D90_FlyGuyWarioBoard);
    if (D_800C597A != 0) {
        SetFadeInTypeAndTime(6, 8);
    } else {
        SetFadeInTypeAndTime(1, 16);
    }
}

void func_800F66D0_FlyGuyWarioBoard(s32 arg0) {
    s32 r;
    s32 r2;

    r = func_8005021C(100.0f);
    if (r < (D_800F8260_FlyGuyWarioBoard + D_800F825C_FlyGuyWarioBoard * 5 + arg0)[0]) {
        D_800F8250_FlyGuyWarioBoard = 0;
    } else if (r < (D_800F8260_FlyGuyWarioBoard + D_800F825C_FlyGuyWarioBoard * 5 + arg0)[1]) {
        r2 = func_8005021C(100.0f);
        if (r2 < (D_800F8260_FlyGuyWarioBoard + D_800F825C_FlyGuyWarioBoard * 5 + arg0)[2]) {
            D_800F8250_FlyGuyWarioBoard = 1;
            if (D_800F825C_FlyGuyWarioBoard == 0) {
                D_800F8258_FlyGuyWarioBoard = 1;
            } else {
                D_800F8258_FlyGuyWarioBoard = 0;
            }
        } else if (r2 < (D_800F8260_FlyGuyWarioBoard + D_800F825C_FlyGuyWarioBoard * 5 + arg0)[3]) {
            D_800F8250_FlyGuyWarioBoard = 1;
            if (D_800F825C_FlyGuyWarioBoard == 0) {
                D_800F8258_FlyGuyWarioBoard = 2;
            } else if (D_800F825C_FlyGuyWarioBoard == 1) {
                D_800F8258_FlyGuyWarioBoard = 2;
            } else {
                D_800F8258_FlyGuyWarioBoard = 1;
            }
        } else {
            D_800F8250_FlyGuyWarioBoard = 2;
        }
    } else {
        D_800F8250_FlyGuyWarioBoard = 2;
    }
}
/* CPU odds (percent); 104 bytes, read as [rank*2], [rank*3 + 8] and 5-byte rows at 20/40/61/81 */
const u8 D_800F8120_FlyGuyWarioBoard[104] = {
    100, 0, 100, 0, 100, 0, 100, 0, 80, 40, 0, 70, 10, 0, 70, 10, 0, 30, 0, 0,
    0, 40, 90, 0, 0, 0, 40, 100, 0, 0, 0, 30, 90, 100, 0, 0, 30, 90, 100, 0,
    0, 30, 100, 0, 0, 0, 30, 100, 0, 0, 0, 20, 90, 100, 0, 0, 20, 90, 100, 0,
    100, 0, 40, 90, 0, 0, 0, 40, 100, 0, 0, 0, 30, 90, 100, 0, 0, 30, 90, 100,
    0, 0, 30, 100, 0, 0, 0, 30, 100, 0, 0, 0, 20, 90, 100, 0, 0, 20, 90, 100,
    0, 100, 0, 0,
};

/* CPU odds (percent); 104 bytes, read as [rank*2], [rank*3 + 8] and 5-byte rows at 20/40/61/81 */
const u8 D_800F8188_FlyGuyWarioBoard[104] = {
    80, 0, 90, 0, 90, 0, 100, 0, 70, 50, 0, 60, 20, 0, 60, 20, 0, 40, 0, 0,
    0, 20, 90, 0, 0, 0, 20, 100, 0, 0, 0, 10, 90, 100, 0, 0, 10, 90, 100, 0,
    0, 20, 100, 0, 0, 0, 20, 100, 0, 0, 0, 10, 90, 100, 0, 0, 10, 90, 100, 0,
    100, 0, 20, 90, 0, 0, 0, 20, 100, 0, 0, 0, 10, 90, 100, 0, 0, 10, 90, 100,
    0, 0, 20, 100, 0, 0, 0, 20, 100, 0, 0, 0, 10, 90, 100, 0, 0, 10, 90, 100,
    0, 100, 0, 0,
};

void func_800F6834_FlyGuyWarioBoard(void) {
    s32 star;

    star = GwSystem.starSpaces[GwSystem.chosenStarSpaceIndex] + 1;
    D_800F825C_FlyGuyWarioBoard = func_8004FEBC(D_800F8230_FlyGuyWarioBoard);
    if (GwPlayer[D_800F8230_FlyGuyWarioBoard].cpu_difficulty_copy == 0) {
        D_800F8260_FlyGuyWarioBoard = D_800F8188_FlyGuyWarioBoard;
    } else {
        D_800F8260_FlyGuyWarioBoard = D_800F8120_FlyGuyWarioBoard;
    }
    if (GwCommon.boardWork[15] == 0) {
        switch (star) {
        case 7:
        case7:
            if (GwPlayer[D_800F8230_FlyGuyWarioBoard].coins >= 40) {
                if (func_8005021C(100.0f) < D_800F8260_FlyGuyWarioBoard[D_800F825C_FlyGuyWarioBoard * 2]) {
                    D_800F8250_FlyGuyWarioBoard = 0;
                } else {
                    D_800F8250_FlyGuyWarioBoard = 2;
                }
            } else if (GwPlayer[D_800F8230_FlyGuyWarioBoard].coins >= 20) {
                if (func_800415E8(D_800F8230_FlyGuyWarioBoard) < 3) {
                    if (func_8005021C(100.0f) < D_800F8260_FlyGuyWarioBoard[D_800F825C_FlyGuyWarioBoard * 3 + 8]) {
                        D_800F8250_FlyGuyWarioBoard = 0;
                    } else {
                        D_800F8250_FlyGuyWarioBoard = 2;
                    }
                } else {
                    if (func_8005021C(100.0f) < D_800F8260_FlyGuyWarioBoard[D_800F825C_FlyGuyWarioBoard * 3 + 9]) {
                        D_800F8250_FlyGuyWarioBoard = 0;
                    } else {
                        D_800F8250_FlyGuyWarioBoard = 2;
                    }
                }
            } else {
                D_800F8250_FlyGuyWarioBoard = 2;
            }
            break;
        case 2:
        case 4:
            if (GwPlayer[D_800F8230_FlyGuyWarioBoard].coins >= 40) {
                func_800F66D0_FlyGuyWarioBoard(20);
            } else if (GwPlayer[D_800F8230_FlyGuyWarioBoard].coins >= 20) {
                func_800F66D0_FlyGuyWarioBoard(40);
            } else {
                D_800F8250_FlyGuyWarioBoard = 2;
            }
            break;
        case 1:
        case 3:
        case 5:
        case 6:
            D_800F8250_FlyGuyWarioBoard = 2;
            break;
        }
    } else {
        switch (star) {
        case 1:
            if (GwPlayer[D_800F8230_FlyGuyWarioBoard].coins >= 40) {
                func_800F66D0_FlyGuyWarioBoard(61);
            } else if (GwPlayer[D_800F8230_FlyGuyWarioBoard].coins >= 20) {
                func_800F66D0_FlyGuyWarioBoard(81);
            } else {
                D_800F8250_FlyGuyWarioBoard = 2;
            }
            break;
        case 7:
            goto case7;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            D_800F8250_FlyGuyWarioBoard = 2;
            break;
        }
    }
}
void func_800F6B54_FlyGuyWarioBoard(void) {
    s32 counts[4];
    s32 i;
    s32 j;
    s32 pick;

    for (i = 0; i < 4; i++) {
        counts[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        counts[func_8004FEBC(i)]++;
    }
    for (i = 0; i < 4; i++) {
        D_800F8240_FlyGuyWarioBoard[i] = -1;
    }
    for (i = 0; i < 4; i++) {
        j = func_8004FEBC(i);
    loop:
        if (D_800F8240_FlyGuyWarioBoard[j] != -1) {
            j++;
            goto loop;
        }
        D_800F8240_FlyGuyWarioBoard[j] = i;
    }
    D_800F8250_FlyGuyWarioBoard = D_800F8254_FlyGuyWarioBoard = D_800F8258_FlyGuyWarioBoard = -1;
    func_800F6834_FlyGuyWarioBoard();
    if (D_800F8250_FlyGuyWarioBoard == -1) {
        D_800F8250_FlyGuyWarioBoard = 2;
    }
    if (D_800F8250_FlyGuyWarioBoard == 1) {
        while (counts[D_800F8258_FlyGuyWarioBoard] == 0) {
            D_800F8258_FlyGuyWarioBoard--;
        }
        j = func_8004FEBC(D_800F8230_FlyGuyWarioBoard);
        if (j == D_800F8258_FlyGuyWarioBoard) {
            counts[j]--;
        }
        i = 0;
        pick = rand8() % counts[D_800F8258_FlyGuyWarioBoard];
        for (; i < 4; i++) {
            if (i != D_800F8230_FlyGuyWarioBoard && D_800F8258_FlyGuyWarioBoard == func_8004FEBC(i)) {
                if (pick == 0) {
                    D_800F8254_FlyGuyWarioBoard = i;
                    break;
                }
                pick--;
            }
        }
        if (GwPlayer[D_800F8254_FlyGuyWarioBoard].cur_chain != 3) {
            D_800F8250_FlyGuyWarioBoard = 2;
        }
    }
}
/* the port-mask template both menu functions copy */
typedef struct {
    u8 m[4];
} PortMask;
const PortMask D_800F820C_FlyGuyWarioBoard = {{ 1, 2, 4, 8 }};

// register allocation: 0x400 vs -1 constant held in s8 (masked 5)
#ifdef NON_MATCHING
s32 func_800F6DE0_FlyGuyWarioBoard(s32 win, u8* avail) {
    s32 count = 0;
    s16 buttons[4];
    PortMask portMask = D_800F820C_FlyGuyWarioBoard;
    s32 i;
    s32 n;

    for (i = 0; i < 4; i++) {
        if (i == D_800F8230_FlyGuyWarioBoard) {
            if (GwPlayer[i].flags & 1) {
                func_800F6B54_FlyGuyWarioBoard();
                count = D_800F8250_FlyGuyWarioBoard + 1;
                buttons[GwPlayer[i].port] = 0x400;
            } else {
                func_8007155C(win, portMask.m[GwPlayer[i].port]);
                buttons[GwPlayer[i].port] = -1;
            }
        } else {
            buttons[GwPlayer[i].port] = 0;
        }
    }
    if (count != 0) {
        func_8006DA1C(win, 2, 2);
        n = 0;
        do {
            if (--count == 0) {
                buttons[GwPlayer[D_800F8230_FlyGuyWarioBoard].port] = -0x8000;
            }
            if (n == 0) {
                func_80070FF8(buttons[0], buttons[1], buttons[2], buttons[3], func_8004DBBC());
            } else {
                func_80070FF8(buttons[0], buttons[1], buttons[2], buttons[3], 16);
            }
            n++;
        } while (count != 0);
    } else {
        func_800710A4(buttons[0], buttons[1], buttons[2], buttons[3]);
    }
    for (i = 0; i < 2; i++) {
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
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_52_FlyGuyWarioBoard/28ECA0", func_800F6DE0_FlyGuyWarioBoard);
#endif

// loop-invariant choice: retail hoists 0x400 into s8, ours hoists -1; tried if-inversion, 0xFFFF (masked 5, raw 7)
#ifdef NON_MATCHING
s32 func_800F7070_FlyGuyWarioBoard(s32 win, u8* avail) {
    s32 count = 0;
    s16 buttons[4];
    PortMask portMask = D_800F820C_FlyGuyWarioBoard;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (i == D_800F8230_FlyGuyWarioBoard) {
            if (GwPlayer[i].flags & 1) {
                count = D_800F8254_FlyGuyWarioBoard;
                count += count < i;
                buttons[GwPlayer[i].port] = 0x400;
            } else {
                func_8007155C(win, portMask.m[GwPlayer[i].port]);
                buttons[GwPlayer[i].port] = -1;
            }
        } else {
            buttons[GwPlayer[i].port] = 0;
        }
    }
    if (count != 0) {
        func_8006DA1C(win, 2, 2);
        do {
            if (--count == 0) {
                buttons[GwPlayer[D_800F8230_FlyGuyWarioBoard].port] = -0x8000;
            }
            func_80070FF8(buttons[0], buttons[1], buttons[2], buttons[3], 16);
        } while (count != 0);
    } else {
        func_800710A4(buttons[0], buttons[1], buttons[2], buttons[3]);
    }
    for (i = 0; i < 3; i++) {
        if (avail[i] == 0) {
            func_80071788(win, i);
        }
    }
    i = 0;
    do {
        i = func_8006FCF0_unproto((s16)win, (s16)i, 0);
    } while (i != -1 && avail[i] == 0);
    return i;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_52_FlyGuyWarioBoard/28ECA0", func_800F7070_FlyGuyWarioBoard);
#endif


void func_800F72DC_FlyGuyWarioBoard(omObjData* arg0) {
    Object* temp_s0 = D_800F8234_FlyGuyWarioBoard;

    temp_s0->unk_30 = ((sinf((arg0->rot.y * (M_PI/180))) * arg0->work[0]) + arg0->trans.y);
    arg0->rot.y += 10.0f;
    if (arg0->rot.y >= 360.0f) {
        arg0->rot.y -= 360.0f;
    }
}

void func_800F7384_FlyGuyWarioBoard(omObjData* arg0) {
    Object* temp_s0 = D_800F8070_FlyGuyWarioBoard;

    temp_s0->unk_30 = ((sinf((arg0->rot.y * (M_PI/180))) * arg0->work[0]) + arg0->trans.y);
    arg0->rot.y += 10.0f;
    if (arg0->rot.y >= 360.0f) {
        arg0->rot.y -= 360.0f;
    }
}



void func_800F742C_FlyGuyWarioBoard(void) {
    u8 avail[4];
    s32 win;
    s32 choice;
    s32 i;
    s32 n;
    f32 angle;
    f32 rad;

    if (D_800C597A == 0) {
        func_800421E0();
        HuPrcSleep(16);
        PlaySound(0xC9);
        HuPrcSleep(10);
    } else {
        HuPrcSleep(8);
    }
    GwCommon.boardWork[1] = -1;
    if (D_800C597A == 2) {
        goto pick_player;
    }
retry:
    {
        win = CreateTextWindow(0x50, 0x28, 0x11, 6);
        for (i = 0; i < 2; i++) {
            if (GwPlayer[D_800F8230_FlyGuyWarioBoard].coins < D_800F8080_FlyGuyWarioBoard[i]) {
                func_8006DA5C(win, "\x01", i);
                avail[i] = 0;
            } else {
                func_8006DA5C(win, "\x08", i);
                avail[i] = 1;
            }
        }
        avail[2] = avail[3] = 1;
        LoadStringIntoWindow(win, (void*)0x1C7, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        while (func_8006FCC0(win) != 0) {
            HuPrcVSleep();
        }
        choice = func_800F6DE0_FlyGuyWarioBoard(win, avail);
        HideTextWindow(win);
        if (choice == 3) {
            D_800F807C_FlyGuyWarioBoard = 1;
            goto end;
        }
        if (choice == 2) {
            win = CreateTextWindow(0x78, 0x3C, 0xB, 2);
            LoadStringIntoWindow(win, (void*)0x1CB, -1, -1);
            func_8006E070(win, 0);
            ShowTextWindow(win);
            func_8004DBD4(win, D_800F8230_FlyGuyWarioBoard);
            HideTextWindow(win);
            GwCommon.boardWork[1] = -1;
            goto end;
        }
        if (choice == 0) {
            func_80055960(D_800F8230_FlyGuyWarioBoard, -D_800F8080_FlyGuyWarioBoard[0]);
            HuPrcSleep(30);
            win = CreateTextWindow(0x78, 0x3C, 8, 2);
            LoadStringIntoWindow(win, (void*)0x1C8, -1, -1);
            func_8006E070(win, 0);
            ShowTextWindow(win);
            func_8004DBD4(win, D_800F8230_FlyGuyWarioBoard);
            HideTextWindow(win);
            PlaySound(0xCE);
            GwCommon.boardWork[1] = 4;
            func_8004F4D4(D_800F8238_FlyGuyWarioBoard, 0, 2);
            func_8004EE14(0, &D_800F809C_FlyGuyWarioBoard, 20, D_800F8238_FlyGuyWarioBoard);
            HuPrcSleep(10);
            func_8004E3E0(0, &D_800F80A8_FlyGuyWarioBoard, 15, D_800F8234_FlyGuyWarioBoard);
            HuPrcSleep(11);
            if (GwPlayer[D_800F8230_FlyGuyWarioBoard].character == 5) {
                func_8004F4D4(D_800F8238_FlyGuyWarioBoard, 1, 0);
            } else {
                func_8004F4D4(D_800F8238_FlyGuyWarioBoard, 1, 2);
            }
            PlaySound(0xCD);
            HuPrcSleep(4);
            omDelObj(D_800F8074_FlyGuyWarioBoard);
            D_800F8074_FlyGuyWarioBoard = NULL;
            angle = 0.0f;
            for (i = 0; i < 90; i++) {
                D_800F8238_FlyGuyWarioBoard->unk_30 += 5.0f;
                D_800F8234_FlyGuyWarioBoard->unk_30 += 5.0f;
                rad = angle * (M_PI / 180);
                D_800F8234_FlyGuyWarioBoard->coords.x = sinf(rad) * 10.0f + D_800F80A8_FlyGuyWarioBoard.x;
                D_800F8238_FlyGuyWarioBoard->coords.x = sinf(rad) * 10.0f + D_800F8090_FlyGuyWarioBoard.x;
                angle += 10.0f;
                if (angle >= 360.0f) {
                    angle -= 360.0f;
                }
                HuPrcVSleep();
            }
            goto end;
        }
    pick_player:
        win = CreateTextWindow(0x78, 0x28, 0xF, 5);
        for (i = 0, n = 0; i < 4; i++) {
            avail[i] = 1;
            if (i != D_800F8230_FlyGuyWarioBoard) {
                func_8006DA5C(win, D_800C5218[GwPlayer[i].character], n++);
            }
        }
        LoadStringIntoWindow(win, (void*)0x1C9, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        while (func_8006FCC0(win) != 0) {
            HuPrcVSleep();
        }
        choice = func_800F7070_FlyGuyWarioBoard(win, avail);
        HideTextWindow(win);
        if (choice == -1) {
            goto retry;
        }
        if (choice == 3) {
            D_800F807C_FlyGuyWarioBoard = 2;
            goto end;
        }
        func_80055960(D_800F8230_FlyGuyWarioBoard, -D_800F8080_FlyGuyWarioBoard[1]);
        HuPrcSleep(30);
        win = CreateTextWindow(0x78, 0x3C, 0xA, 2);
        LoadStringIntoWindow(win, (void*)0x1CA, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        func_8004DBD4(win, D_800F8230_FlyGuyWarioBoard);
        HideTextWindow(win);
        GwCommon.boardWork[1] = choice;
        if (choice >= D_800F8230_FlyGuyWarioBoard) {
            GwCommon.boardWork[1] = choice + 1;
        }
        omDelObj(D_800F8074_FlyGuyWarioBoard);
        D_800F8074_FlyGuyWarioBoard = NULL;
        PlaySound(0xCE);
        D_800F8234_FlyGuyWarioBoard->unk_30 = 50.0f;
        for (i = 0; i < 50; i++) {
            D_800F8234_FlyGuyWarioBoard->unk_30 += 10.0f;
            HuPrcVSleep();
        }
        D_800F8070_FlyGuyWarioBoard = MBModelCreate(func_80052F04(GwCommon.boardWork[1]), D_800F8108_FlyGuyWarioBoard[GwPlayer[GwCommon.boardWork[1]].character]);
        D_800F8070_FlyGuyWarioBoard->coords.x = D_800F8234_FlyGuyWarioBoard->coords.x;
        D_800F8070_FlyGuyWarioBoard->coords.y = D_800F8234_FlyGuyWarioBoard->coords.y;
        D_800F8070_FlyGuyWarioBoard->coords.z = D_800F8234_FlyGuyWarioBoard->coords.z;
        D_800F8070_FlyGuyWarioBoard->unk_30 = D_800F8234_FlyGuyWarioBoard->unk_30 - 50.0f;
        func_80021B14(*D_800F8070_FlyGuyWarioBoard->unk_3C->unk_40, GwPlayer[GwCommon.boardWork[1]].character, 0x80);
        func_8004CCD0(&D_800F8070_FlyGuyWarioBoard->coords, &D_800F8238_FlyGuyWarioBoard->coords, &D_800F8070_FlyGuyWarioBoard->unk_18);
        D_800F8234_FlyGuyWarioBoard->coords.x = D_800F80B4_FlyGuyWarioBoard.x;
        D_800F8234_FlyGuyWarioBoard->coords.z = D_800F80B4_FlyGuyWarioBoard.z;
        for (i = 0; i < 95; i++) {
            D_800F8070_FlyGuyWarioBoard->unk_30 -= 5.0f;
            D_800F8234_FlyGuyWarioBoard->unk_30 -= 5.0f;
            HuPrcVSleep();
            if (i == 20) {
                PlaySound(0xD3);
            }
        }
        D_800F8074_FlyGuyWarioBoard = omAddObj(0x1000, 0, 0, -1, func_800F72DC_FlyGuyWarioBoard);
        D_800F8074_FlyGuyWarioBoard->trans.y = D_800F8234_FlyGuyWarioBoard->unk_30;
        D_800F8074_FlyGuyWarioBoard->rot.y = 180.0f;
        D_800F8074_FlyGuyWarioBoard->work[0] = 6;
        D_800F8078_FlyGuyWarioBoard = omAddObj(0x1000, 0, 0, -1, func_800F7384_FlyGuyWarioBoard);
        D_800F8078_FlyGuyWarioBoard->trans.y = D_800F8070_FlyGuyWarioBoard->unk_30;
        D_800F8078_FlyGuyWarioBoard->rot.y = 180.0f;
        D_800F8078_FlyGuyWarioBoard->work[0] = 6;
        HuPrcSleep(60);
    }
end:
    D_800F5144 = 1;
    while (1) {
        HuPrcVSleep();
    }
}
void func_800F7D14_FlyGuyWarioBoard(void) {
    if (func_80072718() == 0) {
        func_800F8044_FlyGuyWarioBoard();
        func_800F7F30_FlyGuyWarioBoard();
        func_80054654();
        func_80070ED4();
        if (D_800F807C_FlyGuyWarioBoard == 0) {
            omOvlReturnEx(1);
            return;
        }
        func_8004F284();
        func_8004F28C(0x52, D_800F807C_FlyGuyWarioBoard);
    }
}

void func_800F7D90_FlyGuyWarioBoard(omObjData* arg0) {
    if (D_800F5144 != 0) {
        if (D_800F807C_FlyGuyWarioBoard != 0) {
            func_800726AC(6, 8);
        } else {
            func_800726AC(1, 16);
        }
        arg0->func_ptr = &func_800F7D14_FlyGuyWarioBoard;
    }
}

void func_800F7DF0_FlyGuyWarioBoard(void) {
    MBModelInit();
    D_800F8234_FlyGuyWarioBoard = MBModelCreate(0x10, NULL);
    D_800F8234_FlyGuyWarioBoard->coords.x = D_800F8084_FlyGuyWarioBoard.x;
    D_800F8234_FlyGuyWarioBoard->coords.y = D_800F8084_FlyGuyWarioBoard.y;
    D_800F8234_FlyGuyWarioBoard->coords.z = D_800F8084_FlyGuyWarioBoard.z;
    D_800F8234_FlyGuyWarioBoard->unk_30 = 50.0f;
    D_800F8074_FlyGuyWarioBoard = omAddObj(0x1000, 0, 0, -1, func_800F72DC_FlyGuyWarioBoard);
    D_800F8074_FlyGuyWarioBoard->trans.y = 50.0f;
    D_800F8074_FlyGuyWarioBoard->rot.y = 0.0f;
    D_800F8074_FlyGuyWarioBoard->work[0] = 3;
    D_800F8238_FlyGuyWarioBoard = MBModelCreate(func_80052F04(D_800F8230_FlyGuyWarioBoard), D_800F8108_FlyGuyWarioBoard[GwPlayer[D_800F8230_FlyGuyWarioBoard].character]);
    D_800F8238_FlyGuyWarioBoard->coords.x = D_800F8090_FlyGuyWarioBoard.x;
    D_800F8238_FlyGuyWarioBoard->coords.y = D_800F8090_FlyGuyWarioBoard.y;
    D_800F8238_FlyGuyWarioBoard->coords.z = D_800F8090_FlyGuyWarioBoard.z;
    func_8004CCD0(&D_800F8238_FlyGuyWarioBoard->coords, &D_800F8234_FlyGuyWarioBoard->coords, &D_800F8238_FlyGuyWarioBoard->unk_18);
    func_8004CCD0(&D_800F8234_FlyGuyWarioBoard->coords, &D_800F8238_FlyGuyWarioBoard->coords, &D_800F8234_FlyGuyWarioBoard->unk_18);
}
void func_800F7F30_FlyGuyWarioBoard(void) {
    if (D_800F8074_FlyGuyWarioBoard != NULL) {
        omDelObj(D_800F8074_FlyGuyWarioBoard);
    }
    if (D_800F8078_FlyGuyWarioBoard != NULL) {
        omDelObj(D_800F8078_FlyGuyWarioBoard);
    }
    if (D_800F8070_FlyGuyWarioBoard != NULL) {
        MBModelKill(D_800F8070_FlyGuyWarioBoard);
    }
    MBModelKill(D_800F8238_FlyGuyWarioBoard);
    MBModelKill(D_800F8234_FlyGuyWarioBoard);
}
void func_800F7FA4_FlyGuyWarioBoard(void) {
    func_800178A0(1);
    func_80017660(0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    LoadBackgroundData(FE2310_ROM_START);
    LoadBackgroundIndex(0x20);
}
void func_800F8044_FlyGuyWarioBoard(void) {
    func_8004A140();
    func_80049F0C();
}