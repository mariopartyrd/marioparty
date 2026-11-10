#include "common.h"

void func_800F66CC_UnknownBowserScene0(void);
void func_800F6BB4_UnknownBowserScene0(omObjData* obj);
void func_800F6C00_UnknownBowserScene0(omObjData* obj);
void func_800F6C4C_UnknownBowserScene0(void);
void func_800F6D74_UnknownBowserScene0(void);
void func_800F6DE8_UnknownBowserScene0(void);
void func_800F6F60_UnknownBowserScene0(void);
void func_8004DBD4(s32, u8);

/* effect form ids (LoadFormFile, zero-extended); retail reads each one's low half (big-endian +2)
   as s16 */
s32 D_800F6F90_UnknownBowserScene0 = -1;
s32 D_800F6F94_UnknownBowserScene0 = -1;
s32 D_800F6F98_UnknownBowserScene0[] = { 2, 9, 0x14, 0x1D, 0x29, 0x31, 0x3A, 0x47 };
Vec3f D_800F6FB8_UnknownBowserScene0 = { -115.0f, 0.0f, 1120.0f };
Vec3f D_800F6FC4_UnknownBowserScene0 = { 115.0f, 0.0f, 1520.0f };
s32 D_800F6FD0_UnknownBowserScene0[] = { 3, 0x000A0068, 0x000A006A, 0x000A006C };
s32 D_800F6FE0_UnknownBowserScene0[] = { 5, 0x0001003E, 0x000A0091, 0x0001000A, 0x0001001C, 0x00010095 };
s32 D_800F6FF8_UnknownBowserScene0[] = { 5, 0x0002003E, 0x000A0092, 0x0002000A, 0x0002001C, 0x00020095 };
s32 D_800F7010_UnknownBowserScene0[] = { 5, 0x0006003E, 0x000A0093, 0x0006000A, 0x0006001C, 0x00060095 };
s32 D_800F7028_UnknownBowserScene0[] = { 5, 0x0003003E, 0x000A0094, 0x0003000A, 0x0003001C, 0x00030095 };
s32 D_800F7040_UnknownBowserScene0[] = { 5, 0x0004003E, 0x000A0095, 0x0004000A, 0x0004001C, 0x00040095 };
s32 D_800F7058_UnknownBowserScene0[] = { 5, 0x0005003E, 0x000A0096, 0x0005000A, 0x0005001C, 0x00050095 };
void* D_800F7070_UnknownBowserScene0[] = {
    D_800F6FE0_UnknownBowserScene0, D_800F6FF8_UnknownBowserScene0, D_800F7010_UnknownBowserScene0,
    D_800F7028_UnknownBowserScene0, D_800F7040_UnknownBowserScene0, D_800F7058_UnknownBowserScene0,
};

extern u8 D_800F70C0_UnknownBowserScene0;
extern u8 D_800F70C1_UnknownBowserScene0;
extern Object* D_800F70C4_UnknownBowserScene0;
extern Object* D_800F70C8_UnknownBowserScene0;

void func_800F65E0_UnknownBowserScene0(void) {
    D_800F70C0_UnknownBowserScene0 = GwSystem.curBoardIndex;
    D_800F70C1_UnknownBowserScene0 = GwSystem.curPlayerIndex;
    omInitObjMan(50, 10);
    func_800F6DE8_UnknownBowserScene0();
    func_800F6C4C_UnknownBowserScene0();
    func_800544E4();
    func_800546B4(0, GwPlayer[0].turn_status);
    func_800546B4(1, GwPlayer[1].turn_status);
    func_800546B4(2, GwPlayer[2].turn_status);
    func_800546B4(3, GwPlayer[3].turn_status);
    func_8006CEA0();
    omAddPrcObj(func_800F66CC_UnknownBowserScene0, 0x300, 0, 0);
    omAddObj(0x1000, 0, 0, -1, &func_800F6C00_UnknownBowserScene0);
    func_80060128(0x12);
    SetFadeInTypeAndTime(3, 16);
}

void func_800F66CC_UnknownBowserScene0(void) {
    s32 win;
    s32 coins;

    coins = 0;
    HuPrcSleep(26);
    func_8004F00C(D_800F70C4_UnknownBowserScene0, 0.0f, -3.0f);
    func_8004F044(D_800F70C4_UnknownBowserScene0);
    PlaySound(0x73);
    func_8004F00C(D_800F70C8_UnknownBowserScene0, 20.0f, -2.0f);
    func_8004F4D4(D_800F70C8_UnknownBowserScene0, 2, 0);
    func_8004F044(D_800F70C8_UnknownBowserScene0);
    PlaySound(0x9E);
    D_800F6F94_UnknownBowserScene0 = LoadFormFile(0x1E, 0x6B9);
    func_80025798((s16)D_800F6F94_UnknownBowserScene0, D_800F70C8_UnknownBowserScene0->coords.x,
                  D_800F70C8_UnknownBowserScene0->coords.y, D_800F70C8_UnknownBowserScene0->coords.z);
    func_80025830((s16)D_800F6F94_UnknownBowserScene0, 0.5f, 0.5f, 0.5f);
    D_800F6F90_UnknownBowserScene0 = LoadFormFile(0x1D, 0x6B9);
    func_80025798((s16)D_800F6F90_UnknownBowserScene0, D_800F70C8_UnknownBowserScene0->coords.x,
                  D_800F70C8_UnknownBowserScene0->coords.y, D_800F70C8_UnknownBowserScene0->coords.z);
    HuPrcSleep(5);
    func_8004F4D4(D_800F70C8_UnknownBowserScene0, 3, 0);
    HuPrcSleep(10);
    func_8004F40C(D_800F70C8_UnknownBowserScene0, -1, 2);
    HuPrcSleep(10);
    func_8002456C((s16)D_800F6F90_UnknownBowserScene0);
    D_800F6F90_UnknownBowserScene0 = -1;
    func_8002456C((s16)D_800F6F94_UnknownBowserScene0);
    D_800F6F94_UnknownBowserScene0 = -1;
    if (GwPlayer[D_800F70C1_UnknownBowserScene0].coins == 0) {
        win = CreateTextWindow(50, 60, 15, 2);
        LoadStringIntoWindow(win, (void*)0x185, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        PlaySound(0x4D);
        func_8004DBD4(win, D_800F70C1_UnknownBowserScene0);
        HideTextWindow(win);
    } else if (GwPlayer[D_800F70C1_UnknownBowserScene0].coins < 20) {
        win = CreateTextWindow(60, 60, 15, 2);
        LoadStringIntoWindow(win, (void*)0x184, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        PlaySound(0x4D);
        func_8004DBD4(win, D_800F70C1_UnknownBowserScene0);
        HideTextWindow(win);
        coins = -GwPlayer[D_800F70C1_UnknownBowserScene0].coins;
    } else {
        win = CreateTextWindow(60, 60, 15, 2);
        LoadStringIntoWindow(win, (void*)0x182, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        PlaySound(0x4D);
        func_8004DBD4(win, D_800F70C1_UnknownBowserScene0);
        HideTextWindow(win);
        coins = -20;
    }
    if (coins != 0) {
        func_8004F4D4(D_800F70C8_UnknownBowserScene0, 0, 0);
        func_80055960(D_800F70C1_UnknownBowserScene0, coins);
        func_800503B0(D_800F70C1_UnknownBowserScene0, 5);
        func_80060618(0x44A, D_800F70C1_UnknownBowserScene0);
    } else {
        func_8004F4D4(D_800F70C8_UnknownBowserScene0, 4, 0);
        func_80055960(D_800F70C1_UnknownBowserScene0, 1);
    }
    HuPrcSleep(40);
    win = CreateTextWindow(60, 60, 15, 2);
    LoadStringIntoWindow(win, (void*)0x183, -1, -1);
    func_8006E070(win, 0);
    ShowTextWindow(win);
    PlaySound(0x4C);
    func_8004DBD4(win, D_800F70C1_UnknownBowserScene0);
    HideTextWindow(win);
    func_8004F4D4(D_800F70C4_UnknownBowserScene0, 2, 0);
    HuPrcSleep(17);
    func_8004F00C(D_800F70C4_UnknownBowserScene0, 30.0f, -0.05f);
    PlaySound(0x71);
    HuPrcSleep(3);
    func_80025EB4(*D_800F70C4_UnknownBowserScene0->unk_3C->unk_40, 0, 1);
    if (GwPlayer[D_800F70C1_UnknownBowserScene0].character != 5) {
        func_8004F4D4(D_800F70C8_UnknownBowserScene0, 1, 0);
    }
    HuPrcSleep(15);
    D_800F5144 = 1;
    while (TRUE) {
        HuPrcVSleep();
    }
}

void func_800F6BB4_UnknownBowserScene0(omObjData* obj) {
    if (func_80072718() == 0) {
        func_800F6F60_UnknownBowserScene0();
        func_800F6D74_UnknownBowserScene0();
        func_80054654();
        func_80070ED4();
        omOvlReturnEx(1);
    }
}

void func_800F6C00_UnknownBowserScene0(omObjData* obj) {
    if (D_800F5144 != 0) {
        func_800726AC(3, 16);
        func_800601D4(32);
        obj->func_ptr = &func_800F6BB4_UnknownBowserScene0;
    }
}

void func_800F6C4C_UnknownBowserScene0(void) {
    MBModelInit();
    func_8004F2AC();
    D_800F70C4_UnknownBowserScene0 = MBModelCreate(6, &D_800F6FD0_UnknownBowserScene0);
    D_800F70C4_UnknownBowserScene0->coords.x = D_800F6FB8_UnknownBowserScene0.x;
    D_800F70C4_UnknownBowserScene0->coords.y = D_800F6FB8_UnknownBowserScene0.y;
    D_800F70C4_UnknownBowserScene0->coords.z = D_800F6FB8_UnknownBowserScene0.z;
    D_800F70C4_UnknownBowserScene0->unk_30 = 1000.0f;
    D_800F70C4_UnknownBowserScene0->xScale = D_800F70C4_UnknownBowserScene0->yScale = D_800F70C4_UnknownBowserScene0->zScale = 1.5f;
    D_800F70C8_UnknownBowserScene0 = MBModelCreate(func_80052F04(D_800F70C1_UnknownBowserScene0), D_800F7070_UnknownBowserScene0[GwPlayer[D_800F70C1_UnknownBowserScene0].character]);
    D_800F70C8_UnknownBowserScene0->coords.x = D_800F6FC4_UnknownBowserScene0.x;
    D_800F70C8_UnknownBowserScene0->coords.y = D_800F6FC4_UnknownBowserScene0.y;
    D_800F70C8_UnknownBowserScene0->coords.z = D_800F6FC4_UnknownBowserScene0.z;
    func_8004CCD0(&D_800F70C8_UnknownBowserScene0->coords, &D_800F70C4_UnknownBowserScene0->coords, &D_800F70C8_UnknownBowserScene0->unk_18);
    func_8004CCD0(&D_800F70C4_UnknownBowserScene0->coords, &D_800F70C8_UnknownBowserScene0->coords, &D_800F70C4_UnknownBowserScene0->unk_18);
}

void func_800F6D74_UnknownBowserScene0(void) {
    MBModelKill(D_800F70C8_UnknownBowserScene0);
    MBModelKill(D_800F70C4_UnknownBowserScene0);
    if (D_800F6F90_UnknownBowserScene0 != -1) {
        func_8002456C((s16)D_800F6F90_UnknownBowserScene0);
    }
    if (D_800F6F94_UnknownBowserScene0 != -1) {
        func_8002456C((s16)D_800F6F94_UnknownBowserScene0);
    }
    func_8004F2EC();
}

void func_800F6DE8_UnknownBowserScene0(void) {
    s32 bg;

    func_800178A0(1);
    func_80017660(0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    LoadBackgroundData(FE2310_ROM_START);
    switch (D_800F70C0_UnknownBowserScene0) {
    case 1:
        bg = 9;
        if (GwPlayer[D_800F70C1_UnknownBowserScene0].cur_chain == 2) {
            bg = 12;
        }
        break;
    case 3:
        switch (GwPlayer[D_800F70C1_UnknownBowserScene0].cur_chain) {
        case 2:
            bg = 0x1D;
            break;
        case 3:
            bg = 0x21;
            break;
        case 8:
            bg = 0x1F;
            break;
        case 1:
            bg = 0x20;
            break;
        case 0:
        default:
            bg = 0x1E;
            break;
        }
        break;
    default:
        bg = D_800F6F98_UnknownBowserScene0[D_800F70C0_UnknownBowserScene0];
        break;
    }
    LoadBackgroundIndex(bg);
}

void func_800F6F60_UnknownBowserScene0(void) {
    func_8004A140();
    func_80049F0C();
}
