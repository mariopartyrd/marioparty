#include "common.h"
#include "engine/process.h"
#include "2908F0.h"

Vec3f D_800F6F70_BowserVisitWarioBoard = {-115.0f, 0.0f, 1120.0f};
Vec3f D_800F6F7C_BowserVisitWarioBoard = {115.0f, 0.0f, 1520.0f};
Vec3f D_800F6F88_BowserVisitWarioBoard = {500.0f, 0.0f, 1520.0f};
Vec3f D_800F6F94_BowserVisitWarioBoard = {345.0f, 0.0f, 1920.0f};

s32 D_800F6FA0_BowserVisitWarioBoard[] = {0x00000004, 0x00010000, 0x00010001, 0x00010049, 0x0001003E};
s32 D_800F6FB4_BowserVisitWarioBoard[] = {0x00000004, 0x00020000, 0x00020001, 0x00020049, 0x0002003E};
s32 D_800F6FC8_BowserVisitWarioBoard[] = {0x00000004, 0x00060000, 0x00060001, 0x00060049, 0x0006003E};
s32 D_800F6FDC_BowserVisitWarioBoard[] = {0x00000004, 0x00030000, 0x00030001, 0x00030049, 0x0003003E};
s32 D_800F6FF0_BowserVisitWarioBoard[] = {0x00000004, 0x00040000, 0x00040001, 0x00040049, 0x0004003E};
s32 D_800F7004_BowserVisitWarioBoard[] = {0x00000004, 0x00050000, 0x00050001, 0x00050049, 0x0005003E};

s32* D_800F7018_BowserVisitWarioBoard[] = {
    D_800F6FA0_BowserVisitWarioBoard, D_800F6FB4_BowserVisitWarioBoard,
    D_800F6FC8_BowserVisitWarioBoard, D_800F6FDC_BowserVisitWarioBoard,
    D_800F6FF0_BowserVisitWarioBoard, D_800F7004_BowserVisitWarioBoard
};

s32 D_800F7030_BowserVisitWarioBoard[] = {0x00000003, 0x000A0068, 0x000A006B, 0x000A006A};

// bss
extern u8 D_800F7050_BowserVisitWarioBoard;
extern Object* D_800F7054_BowserVisitWarioBoard;
extern Object* D_800F7058_BowserVisitWarioBoard;
extern s32 D_800F705C_BowserVisitWarioBoard;

void func_800F65E0_BowserVisitWarioBoard(void) {
    D_800F7050_BowserVisitWarioBoard = GwSystem.curPlayerIndex;
    omInitObjMan(50, 10);
    func_800F6EA0_BowserVisitWarioBoard();
    func_800F6CE8_BowserVisitWarioBoard();
    func_800544E4();
    func_800546B4(0, GwPlayer[0].turn_status);
    func_800546B4(1, GwPlayer[1].turn_status);
    func_800546B4(2, GwPlayer[2].turn_status);
    func_800546B4(3, GwPlayer[3].turn_status);
    func_8006CEA0();
    omAddPrcObj(func_800F66BC_BowserVisitWarioBoard, 0x300, 0, 0);
    omAddObj(0x1000, 0, 0, -1, &func_800F6C9C_BowserVisitWarioBoard);
    func_80060128(0x12);
    SetFadeInTypeAndTime(3, 0x10);
}

void func_800F66BC_BowserVisitWarioBoard(void) {
    char sp18[8];
    s32 windowID;
    s32 i;

    HuPrcSleep(0x10);
    PlaySound(0x46A);
    HuPrcSleep(10);
    if (GwPlayer[D_800F7050_BowserVisitWarioBoard].coins == 0) {
        windowID = CreateTextWindow(0x3C, 0x28, 0x11, 4);
        LoadStringIntoWindow(windowID, (void*)0x1D1, -1, -1);
        func_8006E070(windowID, 0);
        ShowTextWindow(windowID);
        func_8004DBD4(windowID, D_800F7050_BowserVisitWarioBoard);
        HideTextWindow(windowID);
    } else {
        if (GwPlayer[D_800F7050_BowserVisitWarioBoard].coins < 20) {
            windowID = CreateTextWindow(0x3C, 0x28, 0x11, 4);
            sprintf(sp18, "%d", GwPlayer[D_800F7050_BowserVisitWarioBoard].coins);
            func_8006DA5C(windowID, sp18, 0);
            LoadStringIntoWindow(windowID, (void*)0x1D0, -1, -1);
            func_8006E070(windowID, 0);
            ShowTextWindow(windowID);
            func_8004DBD4(windowID, D_800F7050_BowserVisitWarioBoard);
            HideTextWindow(windowID);
            func_8004F4D4(D_800F7058_BowserVisitWarioBoard, 3, 0);
            func_80055960(D_800F7050_BowserVisitWarioBoard, -GwPlayer[D_800F7050_BowserVisitWarioBoard].coins);
        } else {
            windowID = CreateTextWindow(0x3C, 0x28, 0x11, 4);
            LoadStringIntoWindow(windowID, (void*)0x1CF, -1, -1);
            func_8006E070(windowID, 0);
            ShowTextWindow(windowID);
            func_8004DBD4(windowID, D_800F7050_BowserVisitWarioBoard);
            HideTextWindow(windowID);
            func_8004F4D4(D_800F7058_BowserVisitWarioBoard, 3, 0);
            func_80055960(D_800F7050_BowserVisitWarioBoard, -20);
        }
        func_800503B0(D_800F7050_BowserVisitWarioBoard, 5);
        HuPrcSleep(30);
    }
    windowID = CreateTextWindow(0x3C, 0x3C, 0x12, 2);
    LoadStringIntoWindow(windowID, (void*)0x1D2, -1, -1);
    func_8006E070(windowID, 0);
    ShowTextWindow(windowID);
    func_8004DBD4(windowID, D_800F7050_BowserVisitWarioBoard);
    HideTextWindow(windowID);
    func_8004F4D4(D_800F7058_BowserVisitWarioBoard, 1, 0);
    func_8004EE14(0, &D_800F6F94_BowserVisitWarioBoard, 20, D_800F7058_BowserVisitWarioBoard);
    HuPrcSleep(20);
    func_8004F4D4(D_800F7058_BowserVisitWarioBoard, 0, 2);
    windowID = CreateTextWindow(0x50, 0x3C, 0x10, 2);
    LoadStringIntoWindow(windowID, (void*)0x1D3, -1, -1);
    func_8006E070(windowID, 0);
    ShowTextWindow(windowID);
    func_8004DBD4(windowID, D_800F7050_BowserVisitWarioBoard);
    HideTextWindow(windowID);
    func_8004F4D4(D_800F7054_BowserVisitWarioBoard, 1, 0);
    func_8004F40C(D_800F7054_BowserVisitWarioBoard, 2, 2);
    HuPrcSleep(15);
    PlaySound(0x6C);
    HuPrcSleep(5);
    PlaySound(0xD0);
    func_80060468(0x45F, GwPlayer[D_800F7050_BowserVisitWarioBoard].character);
    func_800503B0(D_800F7050_BowserVisitWarioBoard, 6);
    func_8004E3E0(0, &D_800F6F88_BowserVisitWarioBoard, 20, D_800F7058_BowserVisitWarioBoard);
    i = 0;
    func_8004F00C(D_800F7058_BowserVisitWarioBoard, 20.0f, -0.05f);
    MBMotionSet(D_800F7058_BowserVisitWarioBoard, 2, 2);
    do {
        if ((GwPlayer[D_800F7050_BowserVisitWarioBoard].character == 2) | (GwPlayer[D_800F7050_BowserVisitWarioBoard].character == 0)) {
            func_8004F9F4(D_800F705C_BowserVisitWarioBoard, D_800F7058_BowserVisitWarioBoard->coords.x,
                          (D_800F7058_BowserVisitWarioBoard->coords.y + D_800F7058_BowserVisitWarioBoard->unk_30) - 50.0f,
                          D_800F7058_BowserVisitWarioBoard->coords.z, 1);
        } else {
            func_8004F9F4(D_800F705C_BowserVisitWarioBoard, D_800F7058_BowserVisitWarioBoard->coords.x,
                          D_800F7058_BowserVisitWarioBoard->coords.y + D_800F7058_BowserVisitWarioBoard->unk_30,
                          D_800F7058_BowserVisitWarioBoard->coords.z, 1);
        }
        i++;
        HuPrcSleep(1);
    } while (i < 10);
    HuPrcSleep(10);
    windowID = CreateTextWindow(0x3C, 0x3C, 0x11, 2);
    LoadStringIntoWindow(windowID, (void*)0x1D4, -1, -1);
    func_8006E070(windowID, 0);
    ShowTextWindow(windowID);
    func_8004DBD4(windowID, D_800F7050_BowserVisitWarioBoard);
    PlaySound(0x469);
    HideTextWindow(windowID);
    D_800F5144 = 1;
    while (1) {
        HuPrcVSleep();
    }
}

void func_800F6C50_BowserVisitWarioBoard(void) {
    if (func_80072718() == 0) {
        func_800F6F40_BowserVisitWarioBoard();
        func_800F6E6C_BowserVisitWarioBoard();
        func_80054654();
        func_80070ED4();
        omOvlReturnEx(1);
    }
}

void func_800F6C9C_BowserVisitWarioBoard(omObjData* arg0) {
    if (D_800F5144 != 0) {
        func_800726AC(3, 16);
        func_800601D4(0x20);
        arg0->func_ptr = &func_800F6C50_BowserVisitWarioBoard;
    }
}

void func_800F6CE8_BowserVisitWarioBoard(void) {
    MBModelInit();
    func_8004F2AC();
    func_8004F8DC();
    D_800F705C_BowserVisitWarioBoard = func_8004F954(0x26, 0x10);
    func_8004FA90(D_800F705C_BowserVisitWarioBoard, 2.0f, 2.0f, 2.0f);
    D_800F7054_BowserVisitWarioBoard = MBModelCreate(6, D_800F7030_BowserVisitWarioBoard);
    D_800F7054_BowserVisitWarioBoard->coords.x = D_800F6F70_BowserVisitWarioBoard.x;
    D_800F7054_BowserVisitWarioBoard->coords.y = D_800F6F70_BowserVisitWarioBoard.y;
    D_800F7054_BowserVisitWarioBoard->coords.z = D_800F6F70_BowserVisitWarioBoard.z;
    D_800F7054_BowserVisitWarioBoard->xScale = D_800F7054_BowserVisitWarioBoard->yScale = D_800F7054_BowserVisitWarioBoard->zScale = 1.5f;
    D_800F7058_BowserVisitWarioBoard = MBModelCreate(func_80052F04(D_800F7050_BowserVisitWarioBoard), D_800F7018_BowserVisitWarioBoard[GwPlayer[D_800F7050_BowserVisitWarioBoard].character]);
    D_800F7058_BowserVisitWarioBoard->coords.x = D_800F6F7C_BowserVisitWarioBoard.x;
    D_800F7058_BowserVisitWarioBoard->coords.y = D_800F6F7C_BowserVisitWarioBoard.y;
    D_800F7058_BowserVisitWarioBoard->coords.z = D_800F6F7C_BowserVisitWarioBoard.z;
    func_80021B14(*D_800F7058_BowserVisitWarioBoard->unk_3C->unk_40, GwPlayer[D_800F7050_BowserVisitWarioBoard].character, 0x80);
    func_8004CCD0(&D_800F7058_BowserVisitWarioBoard->coords, &D_800F7054_BowserVisitWarioBoard->coords, &D_800F7058_BowserVisitWarioBoard->unk_18);
    func_8004CCD0(&D_800F7054_BowserVisitWarioBoard->coords, &D_800F7058_BowserVisitWarioBoard->coords, &D_800F7054_BowserVisitWarioBoard->unk_18);
}

void func_800F6E6C_BowserVisitWarioBoard(void) {
    MBModelKill(D_800F7058_BowserVisitWarioBoard);
    MBModelKill(D_800F7054_BowserVisitWarioBoard);
    func_8004F2EC();
}

void func_800F6EA0_BowserVisitWarioBoard(void) {
    func_800178A0(1);
    func_80017660(0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    LoadBackgroundData(FE2310_ROM_START);
    LoadBackgroundIndex(0x1E);
}

void func_800F6F40_BowserVisitWarioBoard(void) {
    func_8004A140();
    func_80049F0C();
}
