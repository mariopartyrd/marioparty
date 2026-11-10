#include "engine/process.h"
#include "285B70.h"

Vec3f D_800F70C0_BowserVisitDKBoard = {-115.0f, 0.0f, 1120.0f};
Vec3f D_800F70CC_BowserVisitDKBoard[] = {{30.0f, 350.0f, 1475.0f},{30.0f, 65.0f, 1475.0f}};
Vec3f D_800F70E4_BowserVisitDKBoard = {115.0f, 0.0f, 1520.0f};

s32 D_800F70F0_BowserVisitDKBoard[] = { 0x00000003, 0x000A0068, 0x000A006A, 0x000A006C };
s32 D_800F7100_BowserVisitDKBoard[] =  { 0x00000002, 0x0001003C, 0x0001003E };
s32 D_800F710C_BowserVisitDKBoard[] = { 0x00000002, 0x0002003C, 0x0002003E };
s32 D_800F7118_BowserVisitDKBoard[] = { 0x00000002, 0x0006003C, 0x0006003E };
s32 D_800F7124_BowserVisitDKBoard[] = { 0x00000002, 0x0003003C, 0x0003003E };
s32 D_800F7130_BowserVisitDKBoard[] = { 0x00000002, 0x0004003C, 0x0004003E };
s32 D_800F713C_BowserVisitDKBoard[] = { 0x00000002, 0x0005003C, 0x0005003E };

s32* D_800F7148_BowserVisitDKBoard[] = {
    D_800F7100_BowserVisitDKBoard, D_800F710C_BowserVisitDKBoard,
    D_800F7118_BowserVisitDKBoard, D_800F7124_BowserVisitDKBoard,
    D_800F7130_BowserVisitDKBoard, D_800F713C_BowserVisitDKBoard
};

//bss
extern u8 D_800F7170_BowserVisitDKBoard;
extern Object* D_800F7174_BowserVisitDKBoard;
extern Object* D_800F7178_BowserVisitDKBoard;
extern Object* D_800F717C_BowserVisitDKBoard;
extern omObjData* D_800F7180_BowserVisitDKBoard;

void func_800F65E0_BowserVisitDKBoard(void) {
    D_800F7170_BowserVisitDKBoard = GwSystem.curPlayerIndex;
    omInitObjMan(50, 10);
    func_800F6FF8_BowserVisitDKBoard();
    func_800F6E1C_BowserVisitDKBoard();
    func_800544E4();
    func_800546B4(0, GwPlayer[0].turn_status);
    func_800546B4(1, GwPlayer[1].turn_status);
    func_800546B4(2, GwPlayer[2].turn_status);
    func_800546B4(3, GwPlayer[3].turn_status);
    func_8006CEA0();
    omAddPrcObj(func_800F66BC_BowserVisitDKBoard, 0x300, 0, 0);
    omAddObj(0x1000, 0, 0, -1, &func_800F6DD0_BowserVisitDKBoard);
    func_80060128(0x12);
    SetFadeInTypeAndTime(3, 0x10);
}

void func_800F66BC_BowserVisitDKBoard(void) {
    f32 var_f20;
    s32 temp_s1;

    HuPrcSleep(0x10);
    PlaySound(0x46A);
    HuPrcSleep(0xA);
    if (GwPlayer[D_800F7170_BowserVisitDKBoard].coins == 0) {
        temp_s1 = CreateTextWindow(0x28, 0x28, 0x10, 2);
        LoadStringIntoWindow(temp_s1, (void* )0x192, -1, -1);
        func_8006E070(temp_s1, 0);
        ShowTextWindow(temp_s1);
        func_8004DBD4(temp_s1, D_800F7170_BowserVisitDKBoard);
        HideTextWindow(temp_s1);
        temp_s1 = CreateTextWindow(0x28, 0x28, 0x13, 3);
        LoadStringIntoWindow(temp_s1, (void* )0x193, -1, -1);
        func_8006E070(temp_s1, 0);
        ShowTextWindow(temp_s1);
        PlaySound(0x46A);
        func_8004DBD4(temp_s1, D_800F7170_BowserVisitDKBoard);
        HideTextWindow(temp_s1);
    } else if (!(GwPlayer[D_800F7170_BowserVisitDKBoard].coins >= 0xA)) {
        temp_s1 = CreateTextWindow(0x28, 0x28, 0x10, 2);
        LoadStringIntoWindow(temp_s1, (void* )0x18F, -1, -1);
        func_8006E070(temp_s1, 0);
        ShowTextWindow(temp_s1);
        func_8004DBD4(temp_s1, D_800F7170_BowserVisitDKBoard);
        HideTextWindow(temp_s1);
        temp_s1 = CreateTextWindow(0x28, 0x28, 0x12, 3);
        LoadStringIntoWindow(temp_s1, (void* )0x190, -1, -1);
        func_8006E070(temp_s1, 0);
        ShowTextWindow( temp_s1);
        func_8004DBD4(temp_s1, D_800F7170_BowserVisitDKBoard);
        HideTextWindow(temp_s1);
        MBMotionSet(D_800F7174_BowserVisitDKBoard, 1, 0);
        func_8004F40C(D_800F7174_BowserVisitDKBoard, 0, 2);
        MBMotionSet(D_800F717C_BowserVisitDKBoard, 1, 0);
        func_80055960(D_800F7170_BowserVisitDKBoard, -GwPlayer[D_800F7170_BowserVisitDKBoard].coins);
        func_800503B0(D_800F7170_BowserVisitDKBoard, 5);
        func_80060618(0x44A, D_800F7170_BowserVisitDKBoard);
        HuPrcSleep(0x1E);
        temp_s1 = CreateTextWindow(0x28, 0x28, 0x10, 2);
        LoadStringIntoWindow(temp_s1, (void* )0x191, -1, -1);
        func_8006E070(temp_s1, 0);
        ShowTextWindow(temp_s1);
        PlaySound(0x469);
        func_8004DBD4(temp_s1, D_800F7170_BowserVisitDKBoard);
        HideTextWindow(temp_s1);
    } else {
        temp_s1 = CreateTextWindow(0x37, 0x28, 0x10, 2);
        LoadStringIntoWindow(temp_s1, (void* )0x18C, -1, -1);
        func_8006E070(temp_s1, 0);
        ShowTextWindow(temp_s1);
        func_8004DBD4(temp_s1, D_800F7170_BowserVisitDKBoard);
        HideTextWindow(temp_s1);
        func_8004F4D4(D_800F7174_BowserVisitDKBoard, 2, 0);
        func_8004F40C(D_800F7174_BowserVisitDKBoard, 0, 2);
        HuPrcSleep(0x14);
        var_f20 = D_800F70CC_BowserVisitDKBoard[0].y;

        while (D_800F70CC_BowserVisitDKBoard[1].y <= var_f20) {
            D_800F7178_BowserVisitDKBoard->unk_30 = var_f20;
            HuPrcVSleep();
            var_f20 -= 2.0f;
        }

        D_800F7178_BowserVisitDKBoard->unk_30 = D_800F70CC_BowserVisitDKBoard[1].y;
        D_800F7180_BowserVisitDKBoard->work[0] = 1;
        HuPrcVSleep();
        MBMotionSet(D_800F7174_BowserVisitDKBoard, 1, 0);
        func_8004F40C(D_800F7174_BowserVisitDKBoard, 0, 2);
        HuPrcSleep(0x28);
        temp_s1 = CreateTextWindow(0x28, 0x28, 0x12, 3);
        LoadStringIntoWindow(temp_s1, (void* )0x18D, -1, -1);
        func_8006E070(temp_s1, 0);
        ShowTextWindow(temp_s1);
        func_8004DBD4(temp_s1, D_800F7170_BowserVisitDKBoard);
        HideTextWindow(temp_s1);
        MBMotionSet(D_800F7174_BowserVisitDKBoard, 1, 0);
        func_8004F40C(D_800F7174_BowserVisitDKBoard, 0, 2);
        MBMotionSet(D_800F717C_BowserVisitDKBoard, 0, 0);
        func_80055960(D_800F7170_BowserVisitDKBoard, -0xA);
        func_800503B0(D_800F7170_BowserVisitDKBoard, 5);
        func_80060618(0x44A, D_800F7170_BowserVisitDKBoard);
        HuPrcSleep(0x1E);
        temp_s1 = CreateTextWindow(0x50, 0x28, 0xF, 3);
        LoadStringIntoWindow(temp_s1, (void* )0x18E, -1, -1);
        func_8006E070(temp_s1, 0);
        ShowTextWindow(temp_s1);
        PlaySound(0x469);
        func_8004DBD4(temp_s1, D_800F7170_BowserVisitDKBoard);
        HideTextWindow(temp_s1);
    }

    D_800F5144 = 1;
    while (1) {
        HuPrcVSleep();
    }
}

void func_800F6C14_BowserVisitDKBoard(omObjData* arg0) {
    Object* temp_s0;
    Object* temp_s0_2;
    Object* temp_s0_3;

    temp_s0 = D_800F7178_BowserVisitDKBoard;
    temp_s0->unk_18.x = sinf(arg0->rot.x * (M_PI/180));
    temp_s0_2 = D_800F7178_BowserVisitDKBoard;
    temp_s0_2->unk_18.z = cosf(arg0->rot.x * (M_PI/180));
    if ((arg0->work[0] == 0) || !(arg0->rot.x < -310.0f)) {
        arg0->rot.x = arg0->rot.x - 5.0f;
        if (arg0->rot.x <= -360.0f) {
            arg0->rot.x = arg0->rot.x + 360.0f;
        }
    } else {
        temp_s0_3 = D_800F7178_BowserVisitDKBoard;
        temp_s0_3->unk_30 = ((sinf(arg0->rot.y * (M_PI/180))) * 4.0f) + D_800F70CC_BowserVisitDKBoard[1].y;
        arg0->rot.y = arg0->rot.y + 5.0f;
        if (arg0->rot.y >= 360.0f) {
            arg0->rot.y -= 360.0f;
        }
    }
}

void func_800F6D84_BowserVisitDKBoard(void) {
    if (func_80072718() == 0) {
        func_800F7098_BowserVisitDKBoard();
        func_800F6FAC_BowserVisitDKBoard();
        func_80054654();
        func_80070ED4();
        omOvlReturnEx(1);
    }
}

void func_800F6DD0_BowserVisitDKBoard(omObjData* arg0) {
    if (D_800F5144 != 0) {
        func_800726AC(3, 0x10);
        func_800601D4(0x20);
        arg0->func_ptr = &func_800F6D84_BowserVisitDKBoard;
    }
}

void func_800F6E1C_BowserVisitDKBoard(void) {
    MBModelInit();
    func_8004F2AC();
    D_800F7174_BowserVisitDKBoard = MBModelCreate(6, D_800F70F0_BowserVisitDKBoard);
    D_800F7174_BowserVisitDKBoard->coords.x = D_800F70C0_BowserVisitDKBoard.x;
    D_800F7174_BowserVisitDKBoard->coords.y = D_800F70C0_BowserVisitDKBoard.y;
    D_800F7174_BowserVisitDKBoard->coords.z = D_800F70C0_BowserVisitDKBoard.z;
    D_800F7174_BowserVisitDKBoard->zScale = 1.5f;
    D_800F7174_BowserVisitDKBoard->yScale = 1.5f;
    D_800F7174_BowserVisitDKBoard->xScale = 1.5f;
    D_800F7178_BowserVisitDKBoard = MBModelCreate(0x28, NULL);
    D_800F7178_BowserVisitDKBoard->coords.x = D_800F70CC_BowserVisitDKBoard[0].x;
    D_800F7178_BowserVisitDKBoard->coords.y = 0.0f;
    D_800F7178_BowserVisitDKBoard->unk_30 = D_800F70CC_BowserVisitDKBoard[0].y;
    D_800F7178_BowserVisitDKBoard->coords.z = D_800F70CC_BowserVisitDKBoard[0].z;
    D_800F7180_BowserVisitDKBoard = omAddObj(0x1000, 0, 0, -1, &func_800F6C14_BowserVisitDKBoard);
    D_800F7180_BowserVisitDKBoard->rot.x = -12.0f;
    D_800F7180_BowserVisitDKBoard->rot.y = 0.0f;
    D_800F7180_BowserVisitDKBoard->work[0] = 0;
    D_800F717C_BowserVisitDKBoard = MBModelCreate(func_80052F04(D_800F7170_BowserVisitDKBoard), D_800F7148_BowserVisitDKBoard[GwPlayer[D_800F7170_BowserVisitDKBoard].character]);
    D_800F717C_BowserVisitDKBoard->coords.x = D_800F70E4_BowserVisitDKBoard.x;
    D_800F717C_BowserVisitDKBoard->coords.y = D_800F70E4_BowserVisitDKBoard.y;
    D_800F717C_BowserVisitDKBoard->coords.z = D_800F70E4_BowserVisitDKBoard.z;
    func_8004CCD0(&D_800F717C_BowserVisitDKBoard->coords, &D_800F7174_BowserVisitDKBoard->coords, &D_800F717C_BowserVisitDKBoard->unk_18);
    func_8004CCD0(&D_800F7174_BowserVisitDKBoard->coords, &D_800F717C_BowserVisitDKBoard->coords, &D_800F7174_BowserVisitDKBoard->unk_18);
}

void func_800F6FAC_BowserVisitDKBoard(void) {
    omDelObj(D_800F7180_BowserVisitDKBoard);
    MBModelKill(D_800F717C_BowserVisitDKBoard);
    MBModelKill(D_800F7174_BowserVisitDKBoard);
    MBModelKill(D_800F7178_BowserVisitDKBoard);
    func_8004F2EC();
}

void func_800F6FF8_BowserVisitDKBoard(void) {
    func_800178A0(1);
    func_80017660(0U, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0U, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    LoadBackgroundData(FE2310_ROM_START);
    LoadBackgroundIndex(2);
}

void func_800F7098_BowserVisitDKBoard(void) {
    func_8004A140();
    func_80049F0C();
}
