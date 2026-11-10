#include "common.h"
#include "28CFF0.h"
#include "engine/process.h"

void func_8004DBD4(s32, u8);
void func_800F705C_BowserVisitYoshiBoard(omObjData*);
void func_800F71CC_BowserVisitYoshiBoard(void);
void func_800F7400_BowserVisitYoshiBoard(void);
void func_800F7500_BowserVisitYoshiBoard(void);
void func_800F66BC_BowserVisitYoshiBoard(Object* arg0);

Vec3f D_800F7530_BowserVisitYoshiBoard = {-115.0f, 0.0f, 1120.0f};
Vec3f D_800F753C_BowserVisitYoshiBoard[] = {{115.0f, 400.0f, 1520.0f}, {115.0f, 60.0f, 1520.0f}, {115.0f, 210.0f, 1520.0f}};
Vec3f D_800F7560_BowserVisitYoshiBoard = {115.0f, 0.0f, 1520.0f};

s32 D_800F756C_BowserVisitYoshiBoard[] = {0x00000003, 0x000A0068, 0x000A006A, 0x000A006C};
s32 D_800F757C_BowserVisitYoshiBoard[] = {0x00000003, 0x0001003C, 0x0001003E, 0x0001000B};
s32 D_800F758C_BowserVisitYoshiBoard[] = {0x00000003, 0x0002003C, 0x0002003E, 0x0002000B};
s32 D_800F759C_BowserVisitYoshiBoard[] = {0x00000003, 0x0006003C, 0x0006003E, 0x0006000B};
s32 D_800F75AC_BowserVisitYoshiBoard[] = {0x00000003, 0x0003003C, 0x0003003E, 0x0003000B};
s32 D_800F75BC_BowserVisitYoshiBoard[] = {0x00000003, 0x0004003C, 0x0004003E, 0x0004000B};
s32 D_800F75CC_BowserVisitYoshiBoard[] = {0x00000003, 0x0005003C, 0x0005003E, 0x0005000B};
s32* D_800F75DC_BowserVisitYoshiBoard[] = {
    D_800F757C_BowserVisitYoshiBoard, D_800F758C_BowserVisitYoshiBoard,
    D_800F759C_BowserVisitYoshiBoard, D_800F75AC_BowserVisitYoshiBoard,
    D_800F75BC_BowserVisitYoshiBoard, D_800F75CC_BowserVisitYoshiBoard
};
f32 D_800F75F4_BowserVisitYoshiBoard = 1.0f;
f32 D_800F75F8_BowserVisitYoshiBoard = 0.0f;
f32 D_800F75FC_BowserVisitYoshiBoard = 1.0f;

//bss
extern Object* D_800F7624_BowserVisitYoshiBoard;
extern Object* D_800F762C_BowserVisitYoshiBoard;
extern omObjData* D_800F7630_BowserVisitYoshiBoard;

void func_800F65E0_BowserVisitYoshiBoard(void) {
    D_800F7620_BowserVisitYoshiBoard = GwSystem.curPlayerIndex;
    omInitObjMan(0x32, 0xA);
    func_800F744C_BowserVisitYoshiBoard();
    func_800F7264_BowserVisitYoshiBoard();
    func_800544E4();
    func_800546B4(0, GwPlayer[0].turn_status);
    func_800546B4(1, GwPlayer[1].turn_status);
    func_800546B4(2, GwPlayer[2].turn_status);
    func_800546B4(3, GwPlayer[3].turn_status);
    func_8006CEA0();
    omAddPrcObj(func_800F67F0_BowserVisitYoshiBoard, 0x300U, 0, 0);
    omAddObj(0x1000, 0, 0, -1, &func_800F7218_BowserVisitYoshiBoard);
    func_80060128(0x12);
    SetFadeInTypeAndTime(3, 0x10);
}

void func_800F66BC_BowserVisitYoshiBoard(Object* arg0) {
    D_800C34A4 = D_800F75F4_BowserVisitYoshiBoard;
    
    func_80025930(*D_800F7628_BowserVisitYoshiBoard->unk_3C->unk_40, 0x22000, 0x20000);
    func_80026B8C(*D_800F7628_BowserVisitYoshiBoard->unk_3C->unk_40, D_800F75F8_BowserVisitYoshiBoard, D_800F75FC_BowserVisitYoshiBoard, 2);
    
    if (D_800F384E == 0) {
        D_800F75F4_BowserVisitYoshiBoard += 39.0f;
        D_800F75F8_BowserVisitYoshiBoard = D_800F75F8_BowserVisitYoshiBoard + 0.05f;
        D_800F75FC_BowserVisitYoshiBoard = ((10.0f - D_800F75FC_BowserVisitYoshiBoard) / 30.0f) + D_800F75FC_BowserVisitYoshiBoard;
        if (D_800F75F8_BowserVisitYoshiBoard > 1.0f) {
            MBModelDispOff(D_800F7628_BowserVisitYoshiBoard);
            omDelObj(arg0);
        }
    }
}

void func_800F67F0_BowserVisitYoshiBoard(void) {
    f32 var_f26;
    f32 var_f28;
    s32 var_s0;
    s32 windowID;

    HuPrcSleep(0x10);
    PlaySound(0x46A);
    HuPrcSleep(0xA);
    if (GwPlayer[D_800F7620_BowserVisitYoshiBoard].coins == 0) {
        windowID = CreateTextWindow(0x3C, 0x28, 0xE, 3);
        LoadStringIntoWindow(windowID, (void*)0x1C1, -1, -1);
        func_8006E070(windowID, 0);
        ShowTextWindow(windowID);
        func_8004DBD4(windowID, D_800F7620_BowserVisitYoshiBoard);
        HideTextWindow(windowID);
        windowID = CreateTextWindow(0x3C, 0x28, 0xC, 3);
        LoadStringIntoWindow(windowID, (void*)0x1C2, -1, -1);
        func_8006E070(windowID, 0);
        ShowTextWindow(windowID);
        func_8004DBD4(windowID, D_800F7620_BowserVisitYoshiBoard);
        PlaySound(0x46A);
        HideTextWindow(windowID);
    } else if (GwPlayer[D_800F7620_BowserVisitYoshiBoard].coins < 0x1E) {
        windowID = CreateTextWindow(0x3C, 0x28, 0xE, 3);
        LoadStringIntoWindow(windowID, (void*)0x1BC, -1, -1);
        func_8006E070(windowID, 0);
        ShowTextWindow(windowID);
        func_8004DBD4(windowID, D_800F7620_BowserVisitYoshiBoard);
        HideTextWindow(windowID);
        windowID = CreateTextWindow(0x28, 0x28, 0x12, 3);
        LoadStringIntoWindow(windowID, (void*)0x1BD, -1, -1);
        func_8006E070(windowID, 0);
        ShowTextWindow(windowID);
        func_8004DBD4(windowID, D_800F7620_BowserVisitYoshiBoard);
        HideTextWindow(windowID);
        MBMotionSet(D_800F7624_BowserVisitYoshiBoard, 1, 0);
        func_8004F40C(D_800F7624_BowserVisitYoshiBoard, 0, 2);
        MBMotionSet(D_800F762C_BowserVisitYoshiBoard, 1, 0);
        func_80055960(D_800F7620_BowserVisitYoshiBoard, -GwPlayer[D_800F7620_BowserVisitYoshiBoard].coins);
        func_800503B0(D_800F7620_BowserVisitYoshiBoard, 5);
        func_80060618(0x44A, D_800F7620_BowserVisitYoshiBoard);
        HuPrcSleep(0x1E);
        windowID = CreateTextWindow(0x64, 0x28, 0xB, 2);
        LoadStringIntoWindow(windowID, (void*)0x1BE, -1, -1);
        func_8006E070(windowID, 0);
        ShowTextWindow(windowID);
        func_8004DBD4(windowID, D_800F7620_BowserVisitYoshiBoard);
        PlaySound(0x469);
        HideTextWindow(windowID);
    } else {
        windowID = CreateTextWindow(0x50, 0x28, 0xE, 3);
        LoadStringIntoWindow(windowID, (void*)0x1B9, -1, -1);
        func_8006E070(windowID, 0);
        ShowTextWindow(windowID);
        func_8004DBD4(windowID, D_800F7620_BowserVisitYoshiBoard);
        HideTextWindow(windowID);
        func_8004F4D4(D_800F7624_BowserVisitYoshiBoard, 2, 0);
        func_8004F40C(D_800F7624_BowserVisitYoshiBoard, 0, 2);
        HuPrcSleep(0x14);
        D_800F7628_BowserVisitYoshiBoard->unk_0A &= ~1;
        for (var_f28 = D_800F753C_BowserVisitYoshiBoard[0].y; D_800F753C_BowserVisitYoshiBoard[2].y <= var_f28; var_f28 -= 2.0f) {
            D_800F7628_BowserVisitYoshiBoard->unk_30 = var_f28;
            HuPrcVSleep();
        }
        windowID = CreateTextWindow(0x50, 0x28, 0xD, 3);
        LoadStringIntoWindow(windowID, (void*)0x1BF, -1, -1);
        func_8006E070(windowID, 0);
        ShowTextWindow(windowID);
        func_8004DBD4(windowID, D_800F7620_BowserVisitYoshiBoard);
        HideTextWindow(windowID);
        for (var_s0 = 0; var_s0 < 0x5B; var_s0 += 3) {
            D_800F7628_BowserVisitYoshiBoard->unk_3C->unk_24 = var_s0;
            HuPrcVSleep();
        }
        PlaySound(0xBA);
        for (var_f26 = 0.0f; D_800F753C_BowserVisitYoshiBoard[1].y <= var_f28; var_f28 -= 2.0f) {
            D_800F7628_BowserVisitYoshiBoard->unk_30 = var_f28;
            HuPrcVSleep();
            func_800A0D00((Vec3f*)&D_800F7628_BowserVisitYoshiBoard->xScale,
                          sinf(var_f26 * (M_PI / 180)) * 4.0f + 1.0f,
                          sinf(var_f26 * (M_PI / 180)) * 4.0f + 1.0f,
                          sinf(var_f26 * (M_PI / 180)) * 4.0f + 1.0f);
            switch (GwPlayer[D_800F7620_BowserVisitYoshiBoard].character) {
            case 0:
            case 1:
            case 2:
            case 3:
                var_f26 += 2.3f;
                break;
            case 4:
                var_f26 += 2.1f;
                break;
            case 5:
                var_f26 += 2.0f;
                break;
            }
        }
        D_800F7628_BowserVisitYoshiBoard->unk_30 = D_800F753C_BowserVisitYoshiBoard[1].y;
        D_800F7630_BowserVisitYoshiBoard->work[0] = 1;
        func_8004F4D4(D_800F762C_BowserVisitYoshiBoard, 2, 2);
        D_800F7628_BowserVisitYoshiBoard->unk_0A |= 1;
        func_800503B0(D_800F7620_BowserVisitYoshiBoard, 5);
        PlaySound(0xBB);
        func_80025930(*D_800F7628_BowserVisitYoshiBoard->unk_3C->unk_40, 0x20000, 0x20000);
        func_80025AD4(*D_800F7628_BowserVisitYoshiBoard->unk_3C->unk_40);
        func_80026040(*D_800F7628_BowserVisitYoshiBoard->unk_3C->unk_40);
        omSetStatBit(omAddObj(0x1000, 0, 0, -1, func_800F66BC_BowserVisitYoshiBoard), 0xA0);
        HuPrcSleep(5);
        MBMotionSet(D_800F7624_BowserVisitYoshiBoard, 1, 0);
        func_8004F40C(D_800F7624_BowserVisitYoshiBoard, 0, 2);
        HuPrcSleep(0x28);
        windowID = CreateTextWindow(0x28, 0x28, 0x11, 3);
        LoadStringIntoWindow(windowID, (void*)0x1C0, -1, -1);
        func_8006E070(windowID, 0);
        ShowTextWindow(windowID);
        func_8004DBD4(windowID, D_800F7620_BowserVisitYoshiBoard);
        PlaySound(0x469);
        HideTextWindow(windowID);
        MBMotionSet(D_800F7624_BowserVisitYoshiBoard, 1, 0);
        func_8004F40C(D_800F7624_BowserVisitYoshiBoard, 0, 2);
        func_8004F4D4(D_800F762C_BowserVisitYoshiBoard, 0, 0);
        func_80055960(D_800F7620_BowserVisitYoshiBoard, -0x1E);
        func_800503B0(D_800F7620_BowserVisitYoshiBoard, 5);
        func_80060618(0x44A, D_800F7620_BowserVisitYoshiBoard);
        HuPrcSleep(0x1E);
        HuPrcSleep(0x14);
    }
    D_800F5144 = 1;
    while (1) {
        HuPrcVSleep();
    }
}

void func_800F705C_BowserVisitYoshiBoard(omObjData* arg0) {
    Object* temp_s0;
    Object* temp_s0_2;
    Object* temp_s0_3;

    temp_s0 = D_800F7628_BowserVisitYoshiBoard;
    temp_s0->unk_18.x = sinf(arg0->rot.x * (M_PI / 180));
    temp_s0_2 = D_800F7628_BowserVisitYoshiBoard;
    temp_s0_2->unk_18.z = cosf(arg0->rot.x * (M_PI / 180));
    if ((arg0->work[0] == 0) || !(arg0->rot.x < -310.0f)) {
        arg0->rot.x = arg0->rot.x - 5.0f;
        if (arg0->rot.x <= -360.0f) {
            arg0->rot.x = arg0->rot.x + 360.0f;
        }
    } else {
        temp_s0_3 = D_800F7628_BowserVisitYoshiBoard;
        temp_s0_3->unk_30 = ((sinf(arg0->rot.y * (M_PI / 180))) * 4.0f) + D_800F753C_BowserVisitYoshiBoard[1].y;
        arg0->rot.y = arg0->rot.y + 5.0f;
        if (arg0->rot.y >= 360.0f) {
            arg0->rot.y -= 360.0f;
        }
    }
}
void func_800F71CC_BowserVisitYoshiBoard(void) {
    if (func_80072718() == 0) {
        func_800F7500_BowserVisitYoshiBoard();
        func_800F7400_BowserVisitYoshiBoard();
        func_80054654();
        func_80070ED4();
        omOvlReturnEx(1);
    }
}
void func_800F7218_BowserVisitYoshiBoard(omObjData* arg0) {
    if (D_800F5144 != 0) {
        func_800726AC(3, 0x10);
        func_800601D4(0x20);
        arg0->func_ptr = &func_800F71CC_BowserVisitYoshiBoard;
    }
}
void func_800F7264_BowserVisitYoshiBoard(void) {
    MBModelInit();
    func_8004F2AC();
    D_800F7624_BowserVisitYoshiBoard = MBModelCreate(6, D_800F756C_BowserVisitYoshiBoard);
    D_800F7624_BowserVisitYoshiBoard->coords.x = D_800F7530_BowserVisitYoshiBoard.x;
    D_800F7624_BowserVisitYoshiBoard->coords.y = D_800F7530_BowserVisitYoshiBoard.y;
    D_800F7624_BowserVisitYoshiBoard->coords.z = D_800F7530_BowserVisitYoshiBoard.z;
    D_800F7624_BowserVisitYoshiBoard->zScale = 1.5f;
    D_800F7624_BowserVisitYoshiBoard->yScale = 1.5f;
    D_800F7624_BowserVisitYoshiBoard->xScale = 1.5f;
    D_800F7628_BowserVisitYoshiBoard = MBModelCreate(0x6E, NULL);
    D_800F7628_BowserVisitYoshiBoard->coords.x = D_800F753C_BowserVisitYoshiBoard[0].x;
    D_800F7628_BowserVisitYoshiBoard->coords.y = 0.0f;
    D_800F7628_BowserVisitYoshiBoard->unk_30 = D_800F753C_BowserVisitYoshiBoard[0].y;
    D_800F7628_BowserVisitYoshiBoard->coords.z = D_800F753C_BowserVisitYoshiBoard[0].z;
    D_800F7628_BowserVisitYoshiBoard->unk_0A |= 1;
    D_800F7630_BowserVisitYoshiBoard = omAddObj(0x1000, 0, 0, -1, &func_800F705C_BowserVisitYoshiBoard);
    D_800F7630_BowserVisitYoshiBoard->rot.x = -12.0f;
    D_800F7630_BowserVisitYoshiBoard->rot.y = 0.0f;
    D_800F7630_BowserVisitYoshiBoard->work[0] = 0;
    D_800F762C_BowserVisitYoshiBoard = MBModelCreate(func_80052F04(D_800F7620_BowserVisitYoshiBoard), D_800F75DC_BowserVisitYoshiBoard[GwPlayer[D_800F7620_BowserVisitYoshiBoard].character]);
    D_800F762C_BowserVisitYoshiBoard->coords.x = D_800F7560_BowserVisitYoshiBoard.x;
    D_800F762C_BowserVisitYoshiBoard->coords.y = D_800F7560_BowserVisitYoshiBoard.y;
    D_800F762C_BowserVisitYoshiBoard->coords.z = D_800F7560_BowserVisitYoshiBoard.z;
    func_8004CCD0(&D_800F762C_BowserVisitYoshiBoard->coords, &D_800F7624_BowserVisitYoshiBoard->coords, &D_800F762C_BowserVisitYoshiBoard->unk_18);
    func_8004CCD0(&D_800F7624_BowserVisitYoshiBoard->coords, &D_800F762C_BowserVisitYoshiBoard->coords, &D_800F7624_BowserVisitYoshiBoard->unk_18);
}
void func_800F7400_BowserVisitYoshiBoard(void) {
    omDelObj(D_800F7630_BowserVisitYoshiBoard);
    MBModelKill(D_800F762C_BowserVisitYoshiBoard);
    MBModelKill(D_800F7624_BowserVisitYoshiBoard);
    MBModelKill(D_800F7628_BowserVisitYoshiBoard);
    func_8004F2EC();
}
void func_800F744C_BowserVisitYoshiBoard(void) {
    func_800178A0(1);
    func_80017660(0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    LoadBackgroundData(FE2310_ROM_START);
    if (GwCommon.boardWork[5] != 0) {
        LoadBackgroundIndex(0x16);
    } else {
        LoadBackgroundIndex(0x17);
    }
}
void func_800F7500_BowserVisitYoshiBoard(void) {
    func_8004A140();
    func_80049F0C();
}