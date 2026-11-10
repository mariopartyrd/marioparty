#include "StaffScene.h"

extern u16 D_800C597C;
extern s8 omSysPauseEnableFlag;
s32 func_800141FC(s16);
void func_80039AEC(void);
void func_8004FB14(void);
void func_8004F548(void);
void func_80060088(void);
void func_8006CEA0(void);
void func_80023448(s16);
void func_800234B8(s16, u8, u8, u8);
void func_80023504(s32, f32, f32, f32);

void func_800F6738_StaffScene(void);
void func_800F67B4_StaffScene(omObjData*);
void func_800F681C_StaffScene(omObjData*);

void func_800F65E0_StaffScene(void) {
    s32 i;

    omSysPauseEnableFlag = 1;
    D_800FE2E0_StaffScene = D_800C597C;
    D_800C597C &= 0xFFEF;
    InitCameras(1);
    func_80029090(1);
    func_8001DE70(0x19);
    omInitObjMan(0x10, 0x18);
    i = 0;
    func_80060088();
    func_8006CEA0();
    func_800FC480_StaffScene();
    func_80023448(3);
    func_800234B8(0, 0x78, 0x78, 0x78);
    func_800234B8(1, 0x40, 0x40, 0x60);
    func_80023504(1, -100.0f, 100.0f, 100.0f);
    func_800234B8(2, 0, 0, 0);
    func_800234B8(3, 0, 0, 0);
    for (; i < 4; i++) {
        if (func_800141FC(i) != 0) {
            break;
        }
    }
    D_800FE2F0_StaffScene = 0;
    D_800FE2F4_StaffScene = 0;
    omAddPrcObj(func_800F6738_StaffScene, 0x300, 0x2000, 0);
    omAddObj(0x1000, 0, 0, -1, func_800F681C_StaffScene);
}

void func_800F6738_StaffScene(void) {
    void (**scene)(void);

    MBModelInit();
    func_8004FB14();
    func_8004F2AC();
    func_8004F548();
    for (scene = D_800FD920_StaffScene; *scene != NULL; scene++) {
        (*scene)();
    }
    D_800F5144 = 1;
    while (1) {
        HuPrcVSleep();
    }
}

void func_800F67B4_StaffScene(omObjData* arg0) {
    if (D_800FE2F4_StaffScene == 0 || func_80072718() == 0) {
        func_80070ED4();
        func_8004A140();
        func_80049F0C();
        D_800C597C = D_800FE2E0_StaffScene;
        func_80039AEC();
        omOvlReturnEx(1);
    }
}

void func_800F681C_StaffScene(omObjData* arg0) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (func_800141FC(i) != 0 && (ContBtnTrg[i] & 0x1000)) {
            D_800F5144 = 1;
            D_800FE2F4_StaffScene = 1;
            break;
        }
    }
    if (D_800F5144 != 0) {
        if (D_800FE2F4_StaffScene != 0) {
            func_80072724(0, 0, 0);
            func_800726AC(0, 0x14);
            func_800601D4(0x14);
            func_800601D4(0x28);
        }
        arg0->func_ptr = func_800F67B4_StaffScene;
    }
}
