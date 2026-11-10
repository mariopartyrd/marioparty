#include "common.h"
#include "engine/process.h"

void func_800F66B4_ChangeCannonTargetWarioBoard(void);
void func_800F69D8_ChangeCannonTargetWarioBoard(s32);
void func_800F6B30_ChangeCannonTargetWarioBoard(void);
void func_800F6994_ChangeCannonTargetWarioBoard(omObjData*);
void func_800F6B04_ChangeCannonTargetWarioBoard(void);
void func_800F6BD0_ChangeCannonTargetWarioBoard(void);
void func_800F69D8_ChangeCannonTargetWarioBoard(s32);
void func_800F6B04_ChangeCannonTargetWarioBoard(void);
void func_8004DBD4(s32, u8);
void func_800F6948_ChangeCannonTargetWarioBoard(void);

extern u8 D_800F6C50_ChangeCannonTargetWarioBoard;
extern Object* D_800F6C54_ChangeCannonTargetWarioBoard;
extern Object* D_800F6C58_ChangeCannonTargetWarioBoard;

Vec3f D_800F6C00_ChangeCannonTargetWarioBoard = {0.0f, 0.0f, 1310.0f};
Vec3f D_800F6C0C_ChangeCannonTargetWarioBoard[2] = {{200.0f, 0.0f, 1050.0f}, {-200.0f, 0.0f, 1050.0f}};
Vec3f D_800F6C24_ChangeCannonTargetWarioBoard[2] = {{0.0f, 0.0f, 800.0f}, {0.0f, 0.0f, 1300.0f}};
/* [target][cannon]; row 1 was splat's D_800F6C44 */
s32 D_800F6C3C_ChangeCannonTargetWarioBoard[2][2] = {{0, 1}, {1, 0}};

void func_800F65E0_ChangeCannonTargetWarioBoard(void) {
    D_800F6C50_ChangeCannonTargetWarioBoard = GwSystem.curPlayerIndex;
    omInitObjMan(50, 10);
    func_800F6B30_ChangeCannonTargetWarioBoard();
    func_800F69D8_ChangeCannonTargetWarioBoard(1);
    func_800544E4();
    func_800546B4(0, GwPlayer[0].turn_status);
    func_800546B4(1, GwPlayer[1].turn_status);
    func_800546B4(2, GwPlayer[2].turn_status);
    func_800546B4(3, GwPlayer[3].turn_status);
    func_8006CEA0();
    omAddPrcObj(func_800F66B4_ChangeCannonTargetWarioBoard, 0x300, 0, 0);
    omAddObj(0x1000, 0, 0, -1, &func_800F6994_ChangeCannonTargetWarioBoard);
    SetFadeInTypeAndTime(4, 16);
}


void func_800F66B4_ChangeCannonTargetWarioBoard(void) {
    s32 windowID;
    s32 i;
    s32 j;

    func_800421E0();
    HuPrcSleep(16);
    PlaySound(0xBF);
    HuPrcSleep(0xA);
    windowID = CreateTextWindow(100, 80, 13, 3);
    LoadStringIntoWindow(windowID, (void* )0x1C4, -1, -1);
    func_8006E070(windowID, 0);
    ShowTextWindow(windowID);
    func_8004DBD4(windowID, D_800F6C50_ChangeCannonTargetWarioBoard);
    HideTextWindow(windowID);
    PlaySound(0xC4);
    func_8004EE14(0, &D_800F6C24_ChangeCannonTargetWarioBoard[D_800F6C3C_ChangeCannonTargetWarioBoard[1][GwCommon.boardWork[15]]], 0x1E, D_800F6C58_ChangeCannonTargetWarioBoard);
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            func_800503B0(j, 1);
        }
        HuPrcSleep(9);
    }
    
    PlaySound(0xC5);
    HuPrcSleep(30);
    func_800726AC(0, 4);
    HuPrcSleep(6);
    func_800F6B04_ChangeCannonTargetWarioBoard();
    func_8004A140();
    LoadBackgroundIndex(0x20);
    func_800F69D8_ChangeCannonTargetWarioBoard(0);
    SetFadeInTypeAndTime(0, 4);
    HuPrcSleep(4);
    windowID = CreateTextWindow(0x64, 0x50, 0xC, 3);
    LoadStringIntoWindow(windowID, (void* )0x1C5, -1, -1);
    func_8006E070(windowID, 0);
    ShowTextWindow(windowID);
    func_8004DBD4(windowID, D_800F6C50_ChangeCannonTargetWarioBoard);
    HideTextWindow(windowID);
    PlaySound(0xC4);
    func_8004EE14(0, &D_800F6C24_ChangeCannonTargetWarioBoard[D_800F6C3C_ChangeCannonTargetWarioBoard[0][GwCommon.boardWork[15]]], 30, D_800F6C58_ChangeCannonTargetWarioBoard);
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            func_800503B0(j, 1);
        }
        HuPrcSleep(9);
    }
    
    PlaySound(0xC5);
    HuPrcSleep(30);
    D_800F5144 = 1;
    while(1) {
        HuPrcVSleep();
    }
}

void func_800F6948_ChangeCannonTargetWarioBoard(void) {
    if (func_80072718() == 0) {
        func_800F6BD0_ChangeCannonTargetWarioBoard();
        func_800F6B04_ChangeCannonTargetWarioBoard();
        func_80054654();
        func_80070ED4();
        omOvlReturnEx(1);
    }
}

void func_800F6994_ChangeCannonTargetWarioBoard(omObjData* arg0) {
    if (D_800F5144 != 0) {
        func_800726AC(4, 16);
        arg0->func_ptr = &func_800F6948_ChangeCannonTargetWarioBoard;
    }
}

void func_800F69D8_ChangeCannonTargetWarioBoard(s32 arg0) {
    s32 sp10[2] = { 0xE, 0xF };

    MBModelInit();
    D_800F6C58_ChangeCannonTargetWarioBoard = MBModelCreate(0x2E, NULL);
    D_800F6C58_ChangeCannonTargetWarioBoard->coords.x = D_800F6C0C_ChangeCannonTargetWarioBoard[arg0].x;
    D_800F6C58_ChangeCannonTargetWarioBoard->coords.y = D_800F6C0C_ChangeCannonTargetWarioBoard[arg0].y;
    D_800F6C58_ChangeCannonTargetWarioBoard->coords.z = D_800F6C0C_ChangeCannonTargetWarioBoard[arg0].z;
    D_800F6C54_ChangeCannonTargetWarioBoard = MBModelCreate(sp10[arg0], NULL);
    D_800F6C54_ChangeCannonTargetWarioBoard->coords.x = D_800F6C00_ChangeCannonTargetWarioBoard.x;
    D_800F6C54_ChangeCannonTargetWarioBoard->coords.y = D_800F6C00_ChangeCannonTargetWarioBoard.y;
    D_800F6C54_ChangeCannonTargetWarioBoard->coords.z = D_800F6C00_ChangeCannonTargetWarioBoard.z;
    func_8004CCD0(&D_800F6C54_ChangeCannonTargetWarioBoard->coords, &D_800F32A0->coords, &D_800F6C54_ChangeCannonTargetWarioBoard->unk_18);
    func_8004CCD0(&D_800F6C58_ChangeCannonTargetWarioBoard->coords, &D_800F6C24_ChangeCannonTargetWarioBoard[D_800F6C3C_ChangeCannonTargetWarioBoard[arg0][(GwCommon.boardWork[15] + 1) & 1]], &D_800F6C58_ChangeCannonTargetWarioBoard->unk_18);
}

void func_800F6B04_ChangeCannonTargetWarioBoard(void) {
    MBModelKill(D_800F6C54_ChangeCannonTargetWarioBoard);
    MBModelKill(D_800F6C58_ChangeCannonTargetWarioBoard);
}

void func_800F6B30_ChangeCannonTargetWarioBoard(void) {
    func_800178A0(1);
    func_80017660(0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    LoadBackgroundData(FE2310_ROM_START);
    LoadBackgroundIndex(0x1D);
}

void func_800F6BD0_ChangeCannonTargetWarioBoard(void) {
    func_8004A140();
    func_80049F0C();
}
