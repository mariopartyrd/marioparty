#include "common.h"
#include "engine/process.h"

void func_8004DBD4(s32, u8);
void func_80060BC8(s16, s16);
void func_800607E8(void);

void func_800F66C4_BowserVisitLuigiBoard(void);
void func_800F6D9C_BowserVisitLuigiBoard(void);
void func_800F6DE8_BowserVisitLuigiBoard(omObjData*);
void func_800F6E34_BowserVisitLuigiBoard(void);
void func_800F7050_BowserVisitLuigiBoard(void);
void func_800F70C0_BowserVisitLuigiBoard(void);
void func_800F7160_BowserVisitLuigiBoard(void);

Object* D_800F7190_BowserVisitLuigiBoard = NULL;
s16 D_800F7194_BowserVisitLuigiBoard = -1;
Process* D_800F7198_BowserVisitLuigiBoard = NULL;
Vec3f D_800F719C_BowserVisitLuigiBoard = {135.0f, 0.0f, 995.0f};
Vec3f D_800F71A8_BowserVisitLuigiBoard = {-115.0f, 0.0f, 1120.0f};
Vec3f D_800F71B4_BowserVisitLuigiBoard = {115.0f, 0.0f, 1520.0f};
Vec3f D_800F71C0_BowserVisitLuigiBoard = {135.0f, 183.4054871f, 1037.5f};
Vec3f D_800F71CC_BowserVisitLuigiBoard = {-4.0f, 0.0f, 10.0f};
s32 D_800F71D8_BowserVisitLuigiBoard[] = {0x00000003, 0x000A0068, 0x000A006D, 0x000A006A};
s32 D_800F71E8_BowserVisitLuigiBoard[] = {0x00000005, 0x0001003E, 0x00010095, 0x00010000, 0x00010027, 0x00010001};
s32 D_800F7200_BowserVisitLuigiBoard[] = {0x00000005, 0x0002003E, 0x00020095, 0x00020000, 0x00020027, 0x00020001};
s32 D_800F7218_BowserVisitLuigiBoard[] = {0x00000005, 0x0006003E, 0x00060095, 0x00060000, 0x00060027, 0x00060001};
s32 D_800F7230_BowserVisitLuigiBoard[] = {0x00000005, 0x0003003E, 0x00030095, 0x00030000, 0x00030027, 0x00030001};
s32 D_800F7248_BowserVisitLuigiBoard[] = {0x00000005, 0x0004003E, 0x00040095, 0x00040000, 0x00040027, 0x00040001};
s32 D_800F7260_BowserVisitLuigiBoard[] = {0x00000005, 0x0005003E, 0x00050095, 0x00050000, 0x00050027, 0x00050001};
s32* D_800F7278_BowserVisitLuigiBoard[] = {
    D_800F71E8_BowserVisitLuigiBoard, D_800F7200_BowserVisitLuigiBoard, D_800F7218_BowserVisitLuigiBoard,
    D_800F7230_BowserVisitLuigiBoard, D_800F7248_BowserVisitLuigiBoard, D_800F7260_BowserVisitLuigiBoard,
};

// bss
extern u8 D_800F72A0_BowserVisitLuigiBoard;
extern Object* D_800F72A4_BowserVisitLuigiBoard;
extern Object* D_800F72A8_BowserVisitLuigiBoard;
extern Object* D_800F72AC_BowserVisitLuigiBoard;

void func_800F65E0_BowserVisitLuigiBoard(void) {
    D_800F72A0_BowserVisitLuigiBoard = GwSystem.curPlayerIndex;
    omInitObjMan(50, 10);
    func_800607E8();
    func_800F70C0_BowserVisitLuigiBoard();
    func_800F6E34_BowserVisitLuigiBoard();
    func_800544E4();
    func_800546B4(0, GwPlayer[0].turn_status);
    func_800546B4(1, GwPlayer[1].turn_status);
    func_800546B4(2, GwPlayer[2].turn_status);
    func_800546B4(3, GwPlayer[3].turn_status);
    func_8006CEA0();
    omAddPrcObj(func_800F66C4_BowserVisitLuigiBoard, 0x300, 0, 0);
    omAddObj(0x1000, 0, 0, -1, &func_800F6DE8_BowserVisitLuigiBoard);
    func_80060128(0x12);
    SetFadeInTypeAndTime(3, 0x10);
}

void func_800F66C4_BowserVisitLuigiBoard(void) {
    char sp18[8];
    Vec3f sp20;
    s32 windowID;
    Object* obj;
    f32 angle;
    f32 rad;

    HuPrcSleep(0x10);
    D_800F7194_BowserVisitLuigiBoard = PlaySound(0xD7);
    PlaySound(0x46A);
    HuPrcSleep(0xA);
    if (GwPlayer[D_800F72A0_BowserVisitLuigiBoard].coins == 0) {
        windowID = CreateTextWindow(0x28, 0x28, 0x14, 3);
        LoadStringIntoWindow(windowID, (void*)0x1DE, -1, -1);
        func_8006E070(windowID, 0);
        ShowTextWindow(windowID);
        func_8004DBD4(windowID, D_800F72A0_BowserVisitLuigiBoard);
        HideTextWindow(windowID);
        func_80060BC8(D_800F7194_BowserVisitLuigiBoard, 0x20);
    } else if (GwPlayer[D_800F72A0_BowserVisitLuigiBoard].coins < 20) {
        windowID = CreateTextWindow(0x32, 0x28, 0x11, 3);
        sprintf(sp18, "%d", GwPlayer[D_800F72A0_BowserVisitLuigiBoard].coins);
        func_8006DA5C(windowID, sp18, 0);
        LoadStringIntoWindow(windowID, (void*)0x1DC, -1, -1);
        func_8006E070(windowID, 0);
        ShowTextWindow(windowID);
        func_8004DBD4(windowID, D_800F72A0_BowserVisitLuigiBoard);
        PlaySound(0x469);
        LoadStringIntoWindow(windowID, (void*)0x1DD, -1, -1);
        func_8004DBD4(windowID, D_800F72A0_BowserVisitLuigiBoard);
        HideTextWindow(windowID);
        func_8004F4D4(D_800F72A4_BowserVisitLuigiBoard, 2, 2);
        func_8004F4D4(D_800F72AC_BowserVisitLuigiBoard, 0, 0);
        func_80055960(D_800F72A0_BowserVisitLuigiBoard, -GwPlayer[D_800F72A0_BowserVisitLuigiBoard].coins);
        func_800503B0(D_800F72A0_BowserVisitLuigiBoard, 5);
        func_80060618(0x44A, D_800F72A0_BowserVisitLuigiBoard);
        HuPrcSleep(0x32);
        func_80060BC8(D_800F7194_BowserVisitLuigiBoard, 0x20);
    } else {
        windowID = CreateTextWindow(0x32, 0x28, 0x14, 4);
        LoadStringIntoWindow(windowID, (void*)0x1D9, -1, -1);
        func_8006E070(windowID, 0);
        ShowTextWindow(windowID);
        func_8004DBD4(windowID, D_800F72A0_BowserVisitLuigiBoard);
        HideTextWindow(windowID);
        func_8004F4D4(D_800F72A4_BowserVisitLuigiBoard, 1, 0);
        HuPrcSleep(0xA);
        PlaySound(0xDB);
        HuPrcSleep(0xA);
        func_80025EB4(*D_800F72A8_BowserVisitLuigiBoard->unk_3C->unk_40, 2, 1);
        HuPrcSleep(0x14);
        D_800F7190_BowserVisitLuigiBoard = MBModelCreate(0x3D, NULL);
        D_800F7190_BowserVisitLuigiBoard->coords.x = D_800F71C0_BowserVisitLuigiBoard.x;
        D_800F7190_BowserVisitLuigiBoard->unk_30 = D_800F71C0_BowserVisitLuigiBoard.y;
        D_800F7190_BowserVisitLuigiBoard->coords.y = 0.0f;
        D_800F7190_BowserVisitLuigiBoard->coords.z = D_800F71C0_BowserVisitLuigiBoard.z;
        func_8004F00C(D_800F7190_BowserVisitLuigiBoard, 15.0f, -1.0f);
        angle = -40.0f;
        PlaySound(0x108);
        while (func_8004F018(D_800F7190_BowserVisitLuigiBoard) != 0) {
            obj = D_800F7190_BowserVisitLuigiBoard;
            obj->coords.x += D_800F71CC_BowserVisitLuigiBoard.x;
            obj->coords.z += D_800F71CC_BowserVisitLuigiBoard.z;
            rad = angle * 0.017453292519943295;
            obj->unk_18.x = sinf(rad);
            obj = D_800F7190_BowserVisitLuigiBoard;
            obj->unk_18.z = cosf(rad);
            angle += 30.0f;
            HuPrcVSleep();
        }
        PlaySound(0x108);
        D_800F7190_BowserVisitLuigiBoard->unk_3C->unk_24 = 90.0f;
        func_8004F4D4(D_800F72A4_BowserVisitLuigiBoard, 2, 0);
        func_8004F4D4(D_800F72AC_BowserVisitLuigiBoard, 1, 0);
        HuPrcSleep(0x32);
        MBMotionSet(D_800F72A4_BowserVisitLuigiBoard, 0, 2);
        windowID = CreateTextWindow(0x50, 0x28, 0xC, 3);
        LoadStringIntoWindow(windowID, (void*)0x1DA, -1, -1);
        func_8006E070(windowID, 0);
        ShowTextWindow(windowID);
        func_8004DBD4(windowID, D_800F72A0_BowserVisitLuigiBoard);
        HideTextWindow(windowID);
        func_8004F4D4(D_800F72AC_BowserVisitLuigiBoard, 4, 2);
        sp20.x = D_800F7190_BowserVisitLuigiBoard->coords.x + 25.0f;
        sp20.y = D_800F7190_BowserVisitLuigiBoard->coords.y;
        sp20.z = D_800F7190_BowserVisitLuigiBoard->coords.z + 25.0f;
        func_8004E3E0(0, &sp20, 0x14, D_800F72AC_BowserVisitLuigiBoard);
        HuPrcSleep(0x14);
        MBMotionShiftSet(D_800F72AC_BowserVisitLuigiBoard, 3, 0, 0x14, 0);
        D_800F2B7C[*D_800F72AC_BowserVisitLuigiBoard->unk_3C->unk_40].unk_4C = 0.5f;
        HuPrcSleep(0x14);
        MBModelKill(D_800F7190_BowserVisitLuigiBoard);
        D_800F7190_BowserVisitLuigiBoard = NULL;
        MBMotionShiftSet(D_800F72AC_BowserVisitLuigiBoard, 2, 0, 0x14, 2);
        func_80055960(D_800F72A0_BowserVisitLuigiBoard, 1);
        HuPrcSleep(0x14);
        windowID = CreateTextWindow(0x3C, 0x28, 0x10, 3);
        LoadStringIntoWindow(windowID, (void*)0x1DB, -1, -1);
        func_8006E070(windowID, 0);
        ShowTextWindow(windowID);
        func_8004DBD4(windowID, D_800F72A0_BowserVisitLuigiBoard);
        PlaySound(0x469);
        HideTextWindow(windowID);
        MBMotionSet(D_800F72A4_BowserVisitLuigiBoard, 2, 2);
        func_8004F4D4(D_800F72AC_BowserVisitLuigiBoard, 0, 0);
        func_80055960(D_800F72A0_BowserVisitLuigiBoard, -20);
        func_800503B0(D_800F72A0_BowserVisitLuigiBoard, 5);
        func_80060618(0x44A, D_800F72A0_BowserVisitLuigiBoard);
        HuPrcSleep(0x32);
    }
    D_800F5144 = 1;
    while (1) {
        HuPrcVSleep();
    }
}

void func_800F6D9C_BowserVisitLuigiBoard(void) {
    if (func_80072718() == 0) {
        func_800F7160_BowserVisitLuigiBoard();
        func_800F7050_BowserVisitLuigiBoard();
        func_80054654();
        func_80070ED4();
        omOvlReturnEx(1);
    }
}

void func_800F6DE8_BowserVisitLuigiBoard(omObjData* arg0) {
    if (D_800F5144 != 0) {
        func_800726AC(3, 0x10);
        func_800601D4(0x20);
        arg0->func_ptr = &func_800F6D9C_BowserVisitLuigiBoard;
    }
}

void func_800F6E34_BowserVisitLuigiBoard(void) {
    Object* obj;

    MBModelInit();
    func_8004F2AC();
    obj = D_800F72A4_BowserVisitLuigiBoard = MBModelCreate(6, D_800F71D8_BowserVisitLuigiBoard);
    obj->coords.x = D_800F71A8_BowserVisitLuigiBoard.x;
    obj->coords.y = D_800F71A8_BowserVisitLuigiBoard.y;
    obj->coords.z = D_800F71A8_BowserVisitLuigiBoard.z;
    obj->xScale = obj->yScale = obj->zScale = 1.5f;
    func_80025F60(*obj->unk_3C->unk_40, 0);
    func_800258EC(*D_800F72A4_BowserVisitLuigiBoard->unk_40->unk_40, 0x180, 0x80);
    func_80025AD4(*D_800F72A4_BowserVisitLuigiBoard->unk_40->unk_40);
    obj = D_800F72A8_BowserVisitLuigiBoard = MBModelCreate(0x3C, NULL);
    obj->coords.x = D_800F719C_BowserVisitLuigiBoard.x;
    obj->coords.y = D_800F719C_BowserVisitLuigiBoard.y;
    obj->coords.z = D_800F719C_BowserVisitLuigiBoard.z;
    D_800F2B7C[*obj->unk_3C->unk_40].unk_4C = 0.5f;
    func_80025F60(*obj->unk_3C->unk_40, 0);
    obj = D_800F72AC_BowserVisitLuigiBoard = MBModelCreate(func_80052F04(D_800F72A0_BowserVisitLuigiBoard), D_800F7278_BowserVisitLuigiBoard[GwPlayer[D_800F72A0_BowserVisitLuigiBoard].character]);
    obj->coords.x = D_800F71B4_BowserVisitLuigiBoard.x;
    obj->coords.y = D_800F71B4_BowserVisitLuigiBoard.y;
    obj->coords.z = D_800F71B4_BowserVisitLuigiBoard.z;
    func_80021B14(*obj->unk_3C->unk_40, GwPlayer[D_800F72A0_BowserVisitLuigiBoard].character, 0x80);
    func_8004CCD0(&D_800F72AC_BowserVisitLuigiBoard->coords, &D_800F72A4_BowserVisitLuigiBoard->coords, &D_800F72AC_BowserVisitLuigiBoard->unk_18);
    func_8004CCD0(&D_800F72A4_BowserVisitLuigiBoard->coords, &D_800F72AC_BowserVisitLuigiBoard->coords, &D_800F72A4_BowserVisitLuigiBoard->unk_18);
}

void func_800F7050_BowserVisitLuigiBoard(void) {
    MBModelKill(D_800F72A8_BowserVisitLuigiBoard);
    MBModelKill(D_800F72AC_BowserVisitLuigiBoard);
    MBModelKill(D_800F72A4_BowserVisitLuigiBoard);
    if (D_800F7190_BowserVisitLuigiBoard != NULL) {
        MBModelKill(D_800F7190_BowserVisitLuigiBoard);
    }
    if (D_800F7198_BowserVisitLuigiBoard != NULL) {
        EndProcess(D_800F7198_BowserVisitLuigiBoard);
    }
    func_8004F2EC();
}

void func_800F70C0_BowserVisitLuigiBoard(void) {
    func_800178A0(1);
    func_80017660(0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    LoadBackgroundData(FE2310_ROM_START);
    LoadBackgroundIndex(0x29);
}

void func_800F7160_BowserVisitLuigiBoard(void) {
    func_8004A140();
    func_80049F0C();
}
