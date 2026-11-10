#include "common.h"

void func_800F66AC_Last5Turns(void);
void func_800F6F10_Last5Turns(omObjData* obj);
void func_800F6F5C_Last5Turns(omObjData* obj);
void func_800F6FA8_Last5Turns(void);
void func_800F700C_Last5Turns(void);
void func_800F7034_Last5Turns(void);
void func_800F70E8_Last5Turns(void);

extern char* D_800C5230[]; /* character names (4E530.c) */

s32 D_800F7110_Last5Turns[] = { 2, 9, 0x14, 0x1D, 0x29, 0x31, 0x3A, 0x47 };
Vec3f D_800F7130_Last5Turns = { 500.0f, 0.0f, 2050.0f };
Vec3f D_800F713C_Last5Turns = { 0.0f, 0.0f, 1475.0f };
Vec3f D_800F7148_Last5Turns = { -125.0f, 0.0f, 1275.0f };
s32 D_800F7154_Last5Turns[] = { 3, 0x000A0072, 0x000A0073, 0x000A0074 };
extern char D_800F71A0_Last5Turns[];
extern char D_800F71A8_Last5Turns[];
extern char D_800F71B0_Last5Turns[];
extern char D_800F71B8_Last5Turns[];
/* place names, indexed by rank */
char* D_800F7164_Last5Turns[] = { D_800F71B8_Last5Turns, D_800F71B0_Last5Turns, D_800F71A8_Last5Turns,
                                   D_800F71A0_Last5Turns };
s32 D_800F7174_Last5Turns[] = { 0xE, 0xF, 0x10, 0x11 };
s32 D_800F7184_Last5Turns[] = { 0x12, 0x13, 0x14, 0x15, 0, 0, 0 };
char D_800F71A0_Last5Turns[] = "Last\x0E";
char D_800F71A8_Last5Turns[] = "3rd\x0E";
char D_800F71B0_Last5Turns[] = "2nd\x0E";
char D_800F71B8_Last5Turns[] = "1st\x0E";
char D_800F71C0_Last5Turns[] = "\x07";
char D_800F71C4_Last5Turns[] = "\x08";
char D_800F71C8_Last5Turns[] = "\x04";

extern u8 D_800F71F0_Last5Turns;
extern Object* D_800F71F4_Last5Turns;

void func_800F65E0_Last5Turns(void) {
    D_800F71F0_Last5Turns = GwSystem.curBoardIndex;
    omInitObjMan(50, 10);
    func_800F7034_Last5Turns();
    func_800F6FA8_Last5Turns();
    func_800544E4();
    func_80054834(0, 0x1C);
    func_80054834(1, 0x1C);
    func_80054834(2, 0x1C);
    func_80054834(3, 0x1C);
    func_8006CEA0();
    omAddPrcObj(func_800F66AC_Last5Turns, 0x300, 0, 0);
    omAddObj(0x1000, 0, 0, -1, &func_800F6F5C_Last5Turns);
    func_80060128(0x13);
    SetFadeInTypeAndTime(1, 16);
}

// register allocation: retail keeps the second window id in s6 behind an extra move (masked 0 besides
// the resulting 1-instruction shift)
#ifdef NON_MATCHING
void func_800F66AC_Last5Turns(void) {
    s32 score[4];
    s32 rank[4];
    s32 order[4];
    s32 i;
    s32 j;
    s32 n;
    s32 win;
    s32 pick;
    s16 win0;

    HuPrcSleep(51);
    MBMotionSet(D_800F71F4_Last5Turns, 2, 2);
    func_8004EE14(0, &D_800F713C_Last5Turns, 1, D_800F71F4_Last5Turns);
    func_8004E3E0(0, &D_800F713C_Last5Turns, 15, D_800F71F4_Last5Turns);
    HuPrcSleep(10);
    HuPrcSleep(5);
    func_8004EE14(0, D_800F32A0, 10, D_800F71F4_Last5Turns);
    func_8004F4D4(D_800F71F4_Last5Turns, 0, 2);
    HuPrcSleep(10);
    win0 = CreateTextWindow(80, 60, 17, 2);
    LoadStringIntoWindow(win0, (void*)0, -1, -1);
    func_8006E070(win0, 0);
    ShowTextWindow(win0);
    PlaySound(0x432);
    WaitForTextConfirmation(win0);
    HideTextWindow(win0);
    func_8004F4D4(D_800F71F4_Last5Turns, 1, 2);
    func_8004EE14(0, &D_800F7148_Last5Turns, 20, D_800F71F4_Last5Turns);
    HuPrcSleep(20);
    func_8004E3E0(0, &D_800F7148_Last5Turns, 20, D_800F71F4_Last5Turns);
    for (i = 0; i < 20; i++) {
        HuPrcVSleep();
    }
    func_8004EE14(0, D_800F32A0, 20, D_800F71F4_Last5Turns);
    HuPrcSleep(20);
    func_8004F4D4(D_800F71F4_Last5Turns, 0, 2);

    for (i = 0; i < 4; i++) {
        score[i] = GwPlayer[i].stars * 1000 + GwPlayer[i].coins;
    }
    for (i = 0; i < 4; i++) {
        order[i] = -1;
    }
    for (i = 0; i < 4; i++) {
        for (j = 0, n = 0; j < 4; j++) {
            if (i != j) {
                n += score[i] < score[j];
            }
        }
        rank[i] = n;
        for (j = 0; j < 4; j++) {
            if (order[n + j] == -1) {
                order[n + j] = i;
                break;
            }
        }
    }

    win0 = win = CreateTextWindow(30, 40, 13, 4);
    LoadStringIntoWindow(win0, (void*)7, -1, -1);
    func_8006E070(win0, 0);
    ShowTextWindow(win0);
    PlaySound(0x432);
    WaitForTextConfirmation(win0);
    func_8006EB40(win0);
    for (i = 0; i < 4; i++) {
        func_8006DA5C(win, D_800C5230[GwPlayer[order[i]].character], i);
        func_80054834(order[i], i + 0x1C);
    }
    for (i = 0; i < 4; i++) {
        func_8006DA5C(win, D_800F7164_Last5Turns[rank[order[i]]], i + 4);
    }
    switch (rand8() % 7) {
    case 1:
    case 2:
        pick = order[1];
        break;
    case 3:
    case 4:
        pick = order[2];
        break;
    case 5:
    case 6:
        pick = order[3];
        break;
    case 0:
    default:
        pick = order[0];
        break;
    }
    func_8006DA5C(win, D_800C5230[GwPlayer[pick].character], 8);
    for (i = 0; i < 4; i++) {
        func_80054868(D_800F7174_Last5Turns[order[i]]);
        func_8006DA5C(win, D_800C5230[GwPlayer[order[i]].character], 0);
        func_8006DA5C(win, D_800F7164_Last5Turns[rank[order[i]]], 2);
        switch (rank[order[i]]) {
        case 0:
            func_8006DA5C(win, D_800F71C0_Last5Turns, 1);
            break;
        case 1:
        case 2:
            func_8006DA5C(win, D_800F71C4_Last5Turns, 1);
            break;
        case 3:
            func_8006DA5C(win, D_800F71C8_Last5Turns, 1);
            break;
        }
        LoadStringIntoWindow(win, (void*)8, 4, i * 14 + 4);
        func_8006E070(win, 0);
        HuPrcSleep(20);
        if (i == 3) {
            HuPrcSleep(10);
        }
        WaitForTextConfirmation(win);
    }
    func_8006EB40(win);
    LoadStringIntoWindow(win, (void*)5, -1, -1);
    func_8006E070(win, 0);
    WaitForTextConfirmation(win);
    for (i = 0; i < 4; i++) {
        if (i != pick) {
            func_80054868(D_800F7184_Last5Turns[i]);
        }
    }
    LoadStringIntoWindow(win, (void*)6, 4, 18);
    func_8006E070(win, 0);
    WaitForTextConfirmation(win);
    HideTextWindow(win);
    func_80054868(D_800F7184_Last5Turns[pick]);

    func_8004F4D4(D_800F71F4_Last5Turns, 1, 2);
    func_8004EE14(0, &D_800F713C_Last5Turns, 10, D_800F71F4_Last5Turns);
    HuPrcSleep(10);
    func_8004E3E0(0, &D_800F713C_Last5Turns, 20, D_800F71F4_Last5Turns);
    HuPrcSleep(12);
    HuPrcSleep(8);
    func_8004EE14(0, D_800F32A0, 10, D_800F71F4_Last5Turns);
    HuPrcSleep(10);
    func_8004F4D4(D_800F71F4_Last5Turns, 0, 2);
    win = CreateTextWindow(65, 40, 19, 3);
    if (D_800F71F0_Last5Turns == 7 || _CheckFlag(0xE) != 0) {
        LoadStringIntoWindow(win, (void*)0xA, -1, -1);
    } else {
        LoadStringIntoWindow(win, (void*)9, -1, -1);
    }
    func_8006E070(win, 0);
    ShowTextWindow(win);
    PlaySound(0x432);
    WaitForTextConfirmation(win);
    HideTextWindow(win);
    D_800F5144 = 1;
    while (TRUE) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_Last5Turns/2592A0", func_800F66AC_Last5Turns);
#endif

void func_800F6F10_Last5Turns(omObjData* obj) {
    if (func_80072718() == 0) {
        func_800F70E8_Last5Turns();
        func_800F700C_Last5Turns();
        func_80054654();
        func_80070ED4();
        omOvlReturnEx(1);
    }
}

void func_800F6F5C_Last5Turns(omObjData* obj) {
    if (D_800F5144 != 0) {
        func_800726AC(1, 16);
        func_800601D4(32);
        obj->func_ptr = &func_800F6F10_Last5Turns;
    }
}

void func_800F6FA8_Last5Turns(void) {
    MBModelInit();
    D_800F71F4_Last5Turns = MBModelCreate(8, &D_800F7154_Last5Turns);
    D_800F71F4_Last5Turns->coords.x = D_800F7130_Last5Turns.x;
    D_800F71F4_Last5Turns->coords.y = D_800F7130_Last5Turns.y;
    D_800F71F4_Last5Turns->coords.z = D_800F7130_Last5Turns.z;
    func_8004F140(*D_800F71F4_Last5Turns->unk_3C->unk_40);
}

void func_800F700C_Last5Turns(void) {
    MBModelKill(D_800F71F4_Last5Turns);
    func_8004F1D0();
}

void func_800F7034_Last5Turns(void) {
    func_800178A0(1);
    func_80017660(0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    LoadBackgroundData(FE2310_ROM_START);
    LoadBackgroundIndex(D_800F7110_Last5Turns[D_800F71F0_Last5Turns]);
}

void func_800F70E8_Last5Turns(void) {
    func_8004A140();
    func_80049F0C();
}
