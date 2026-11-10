#include "common.h"
#include "engine/process.h"

void func_8004DBD4(s32, u8);

void func_800F66BC_BowserVisitMagmaMountain(void);
void func_800F6BA4_BowserVisitMagmaMountain(void);
void func_800F6C04_BowserVisitMagmaMountain(omObjData*);
void func_800F6C48_BowserVisitMagmaMountain(void);
void func_800F6DD4_BowserVisitMagmaMountain(void);
void func_800F6E08_BowserVisitMagmaMountain(void);
void func_800F6EA8_BowserVisitMagmaMountain(void);

Vec3f D_800F6ED0_BowserVisitMagmaMountain = {0.0f, 0.0f, 840.0f};
Vec3f D_800F6EDC_BowserVisitMagmaMountain = {80.0f, 0.0f, 1520.0f};
Vec3f D_800F6EE8_BowserVisitMagmaMountain = {0.0f, 0.0f, 1250.0f};

s32 D_800F6EF4_BowserVisitMagmaMountain[] = {0x00000007, 0x00010003, 0x00010000, 0x000A008B, 0x00010018, 0x00010096, 0x00010039, 0x0001003F};
s32 D_800F6F14_BowserVisitMagmaMountain[] = {0x00000007, 0x00020003, 0x00020000, 0x000A008C, 0x00020018, 0x00020096, 0x00020039, 0x0002003F};
s32 D_800F6F34_BowserVisitMagmaMountain[] = {0x00000007, 0x00060003, 0x00060000, 0x000A008D, 0x00060018, 0x00060096, 0x00060039, 0x0006003F};
s32 D_800F6F54_BowserVisitMagmaMountain[] = {0x00000007, 0x00030003, 0x00030000, 0x000A008E, 0x00030018, 0x00030096, 0x00030039, 0x0003003F};
s32 D_800F6F74_BowserVisitMagmaMountain[] = {0x00000007, 0x00040003, 0x00040000, 0x000A008F, 0x00040018, 0x00040096, 0x00040039, 0x0004003F};
s32 D_800F6F94_BowserVisitMagmaMountain[] = {0x00000007, 0x00050003, 0x00050000, 0x000A0090, 0x00050018, 0x00050096, 0x00050039, 0x0005003F};
void* D_800F6FB4_BowserVisitMagmaMountain[] = {D_800F6EF4_BowserVisitMagmaMountain, D_800F6F14_BowserVisitMagmaMountain, D_800F6F34_BowserVisitMagmaMountain, D_800F6F54_BowserVisitMagmaMountain, D_800F6F74_BowserVisitMagmaMountain, D_800F6F94_BowserVisitMagmaMountain};

// bss
extern u8 D_800F6FD0_BowserVisitMagmaMountain;
extern Object* D_800F6FD4_BowserVisitMagmaMountain;
extern s32 D_800F6FD8_BowserVisitMagmaMountain;

void func_800F65E0_BowserVisitMagmaMountain(void) {
    D_800F6FD0_BowserVisitMagmaMountain = GwSystem.curPlayerIndex;
    omInitObjMan(50, 10);
    func_800F6E08_BowserVisitMagmaMountain();
    func_800F6C48_BowserVisitMagmaMountain();
    func_800544E4();
    func_800546B4(0, GwPlayer[0].turn_status);
    func_800546B4(1, GwPlayer[1].turn_status);
    func_800546B4(2, GwPlayer[2].turn_status);
    func_800546B4(3, GwPlayer[3].turn_status);
    func_8006CEA0();
    func_8003FCD4();
    omAddPrcObj(func_800F66BC_BowserVisitMagmaMountain, 0x300, 0, 0);
    omAddObj(0x1000, 0, 0, -1, &func_800F6C04_BowserVisitMagmaMountain);
    SetFadeInTypeAndTime(1, 16);
}

// register allocation (masked 2)
#ifdef NON_MATCHING
void func_800F66BC_BowserVisitMagmaMountain(void) {
    s32 windowID;
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;

    var_s2 = 0;
    func_800421E0();
    HuPrcSleep(0x10);
    PlaySound(0xE6);
    HuPrcSleep(10);
    windowID = CreateTextWindow(0x64, 0x28, 0xD, 4);
    LoadStringIntoWindow(windowID, (void*)0x1F0, -1, -1);
    func_8006E070(windowID, 0);
    ShowTextWindow(windowID);
    func_8004F4D4(D_800F6FD4_BowserVisitMagmaMountain, 4, 0);
    func_8004DBD4(windowID, D_800F6FD0_BowserVisitMagmaMountain);
    HideTextWindow(windowID);
    func_80041048(D_800F6FD0_BowserVisitMagmaMountain, 0);
    HuPrcSleep(0x14);
    func_8004F4D4(D_800F6FD4_BowserVisitMagmaMountain, 0, 2);
    func_8004E3E0(0, &D_800F6EE8_BowserVisitMagmaMountain, 0x14, D_800F6FD4_BowserVisitMagmaMountain);
    HuPrcSleep(0x14);
    func_8004F4D4(D_800F6FD4_BowserVisitMagmaMountain, 3, 0);
    func_8004F40C(D_800F6FD4_BowserVisitMagmaMountain, 1, 2);
    func_8004EE14(0, D_800F32A0, 0xA, D_800F6FD4_BowserVisitMagmaMountain);
    var_s1 = 0;
    func_8004F9F4(D_800F6FD8_BowserVisitMagmaMountain, D_800F6FD4_BowserVisitMagmaMountain->coords.x, D_800F6FD4_BowserVisitMagmaMountain->coords.y - 22.0f, D_800F6FD4_BowserVisitMagmaMountain->coords.z + 50.0f, 1);
    HuPrcSleep(3);
    func_8004F9F4(D_800F6FD8_BowserVisitMagmaMountain, D_800F6FD4_BowserVisitMagmaMountain->coords.x + 20.0f, D_800F6FD4_BowserVisitMagmaMountain->coords.y - 22.0f, D_800F6FD4_BowserVisitMagmaMountain->coords.z + 50.0f, 1);
    HuPrcSleep(3);
    var_s0 = 0;
    func_8004F9F4(D_800F6FD8_BowserVisitMagmaMountain, D_800F6FD4_BowserVisitMagmaMountain->coords.x - 20.0f, D_800F6FD4_BowserVisitMagmaMountain->coords.y - 22.0f, D_800F6FD4_BowserVisitMagmaMountain->coords.z + 50.0f, 1);
    HuPrcSleep(4);

    do {
        switch (var_s0) {
        case 0:
            if (((GwPlayer[D_800F6FD0_BowserVisitMagmaMountain].flags & 1) && (var_s2 >= 0xF)) || (!(GwPlayer[D_800F6FD0_BowserVisitMagmaMountain].flags & 1) && (ContBtnTrg[GwPlayer[D_800F6FD0_BowserVisitMagmaMountain].port] & 0x8000))) {
                var_s0 = 1;
                MBMotionSet(D_800F6FD4_BowserVisitMagmaMountain, 2, 0);
                func_8004F40C(D_800F6FD4_BowserVisitMagmaMountain, 1, 2);
            }
            break;
        case 1:
            if (++var_s1 == 5) {
                var_s0 = 2;
                func_800413B0(D_800F6FD0_BowserVisitMagmaMountain);
            }
            break;
        }
        var_s2++;
        HuPrcVSleep();
    } while (var_s0 != 2);

    HuPrcSleep(0x28);
    GwCommon.boardWork[1] = func_80041604(D_800F6FD0_BowserVisitMagmaMountain);

    if (!(GwCommon.boardWork[1])) {
        windowID = CreateTextWindow(0x64, 0x28, 0xD, 4);
        LoadStringIntoWindow(windowID, (void*)0x1F1, -1, -1);
        func_8006E070(windowID, 0);
        ShowTextWindow(windowID);
        PlaySound(0xE6);
        func_8004F4D4(D_800F6FD4_BowserVisitMagmaMountain, 6, 0);
        func_80060468(0x44A, GwPlayer[D_800F6FD0_BowserVisitMagmaMountain].character);
    } else {
        windowID = CreateTextWindow(0x50, 0x3C, 0xE, 2);
        LoadStringIntoWindow(windowID, (void*)0x1F2, -1, -1);
        func_8006E070(windowID, 0);
        ShowTextWindow(windowID);
        PlaySound(0xE6);
        func_8004F4D4(D_800F6FD4_BowserVisitMagmaMountain, 5, 0);
        func_80060468(0x451, GwPlayer[D_800F6FD0_BowserVisitMagmaMountain].character);
    }
    func_8004DBD4(windowID, D_800F6FD0_BowserVisitMagmaMountain);
    HideTextWindow(windowID);
    HuPrcSleep(0x14);

    D_800F5144 = 1;

    while (1) {
        HuPrcVSleep();
    }
}

#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_59_BowserVisitMagmaMountain/295450", func_800F66BC_BowserVisitMagmaMountain);
#endif

void func_800F6BA4_BowserVisitMagmaMountain(void) {
    if (func_80072718() == 0) {
        func_800F6EA8_BowserVisitMagmaMountain();
        func_800F6DD4_BowserVisitMagmaMountain();
        func_80054654();
        func_80070ED4();
        func_80041370();
        func_800405DC(D_800F6FD0_BowserVisitMagmaMountain);
        omOvlReturnEx(1);
    }
}

void func_800F6C04_BowserVisitMagmaMountain(omObjData* arg0) {
    if (D_800F5144 != 0) {
        func_800726AC(1, 16);
        arg0->func_ptr = &func_800F6BA4_BowserVisitMagmaMountain;
    }
}

void func_800F6C48_BowserVisitMagmaMountain(void) {
    MBModelInit();
    func_80053020();
    func_8004F2AC();
    func_8004F8DC();
    D_800F6FD8_BowserVisitMagmaMountain = func_8004F954(0x26, 0x20);
    D_800F6FD4_BowserVisitMagmaMountain = MBModelCreate(func_80052F04(D_800F6FD0_BowserVisitMagmaMountain), D_800F6FB4_BowserVisitMagmaMountain[GwPlayer[D_800F6FD0_BowserVisitMagmaMountain].character]);
    VEC3F_COPY_TO_OBJ(D_800F6FD4_BowserVisitMagmaMountain, D_800F6EDC_BowserVisitMagmaMountain);
    func_80021B14(*D_800F6FD4_BowserVisitMagmaMountain->unk_3C->unk_40, GwPlayer[D_800F6FD0_BowserVisitMagmaMountain].character, 0x80);
    func_8004CCD0(&D_800F6FD4_BowserVisitMagmaMountain->coords, &D_800F6ED0_BowserVisitMagmaMountain, &D_800F6FD4_BowserVisitMagmaMountain->unk_18);
    func_80052E84(D_800F6FD0_BowserVisitMagmaMountain);
    MBModelDispOff(GwPlayer[D_800F6FD0_BowserVisitMagmaMountain].player_obj);
    VEC3F_COPY_TO_OBJ(GwPlayer[D_800F6FD0_BowserVisitMagmaMountain].player_obj, D_800F6EE8_BowserVisitMagmaMountain);
}

void func_800F6DD4_BowserVisitMagmaMountain(void) {
    MBModelKill(D_800F6FD4_BowserVisitMagmaMountain);
    func_80052FD4(D_800F6FD0_BowserVisitMagmaMountain);
    func_8004F2EC();
}

void func_800F6E08_BowserVisitMagmaMountain(void) {
    func_800178A0(1);
    func_80017660(0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    LoadBackgroundData(FE2310_ROM_START);
    LoadBackgroundIndex(0x3C);
}

void func_800F6EA8_BowserVisitMagmaMountain(void) {
    func_8004A140();
    func_80049F0C();
}
