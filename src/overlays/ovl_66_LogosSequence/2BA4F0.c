#include "common.h"

void func_800F6704_LogosSequence(omObjData* arg0);
void func_800F6774_LogosSequence(void);
void func_800F67E0_LogosSequence(void);
void func_800F686C_LogosSequence(void);
s32 func_800141FC(s16);
void func_800191F8(u16);
extern s8 omSysPauseEnableFlag;
extern u8 D_800C572F;
extern Process* D_800F6B00_LogosSequence;


s32 D_800F6AF0_LogosSequence = 0;
s32 D_800F6AF4_LogosSequence = 0;

void func_800F6610_LogosSequence(void) {
    InitCameras(1);
    omInitObjMan(0x10, 4);
    omSysPauseEnableFlag = 1;
    D_800F6B00_LogosSequence = omAddPrcObj(func_800F686C_LogosSequence, 0xA, 0, 0);
    omAddObj(0x3E8, 0, 0, -1, func_800F6704_LogosSequence);
    if (D_800F6AF0_LogosSequence != 0 && D_800C572F == 0) {
        omAddObj(0xA, 0, 0, -1, func_800F67E0_LogosSequence);
    }
}
void func_800F66C0_LogosSequence(void) {
    D_800F6AF0_LogosSequence = 0;
    func_800F6610_LogosSequence();
}
void func_800F66E0_LogosSequence(void) {
    D_800F6AF0_LogosSequence = 1;
    func_800F6610_LogosSequence();
}
void func_800F6704_LogosSequence(omObjData* arg0) {
    if ((D_800F5144 != 0 || D_800F6AF4_LogosSequence != 0) && func_80072718() == 0) {
        func_80072724(0, 0, 0);
        func_800726AC(0, 9);
        arg0->func_ptr = func_800F6774_LogosSequence;
    }
}
void func_800F6774_LogosSequence(void) {
    if (func_80072718() == 0) {
        if (D_800F6AF4_LogosSequence != 0) {
            omOvlGotoEx(0x67, 1, 0x91);
            return;
        }
        omOvlCallEx(0x61, 0, 0x91);
        omOvlHisChg(1, 0x81, 0, 0x91);
    }
}
void func_800F67E0_LogosSequence(void) {
    s32 i;
    s32 ret;

    if (func_80072718() == 0) {
        for (i = 0; i < 4; i++) {
            ret = func_800141FC(i);
            if (ret == 1) {
                if (ContBtnTrg[i] & 0x1000) {
                    D_800F6AF4_LogosSequence = ret;
                }
                break;
            }
        }
    }
}
void func_800F686C_LogosSequence(void) {
    s32 sprite;
    u16 obj;

    sprite = InitSprite(0x9006D);
    obj = func_80019060((s16)sprite, 0, 1);
    SetBasicSpritePos(obj, 0xA0, 0x78);
    ShowBasicSprite(obj);
    func_80018D84(obj, 0xFFFF);
    SetFadeInTypeAndTime(0, 0x1E);
    while (func_80072718() != 0) {
        HuPrcVSleep();
    }
    HuPrcSleep(0x2D);
    func_800726AC(0, 9);
    while (func_80072718() != 0) {
        HuPrcVSleep();
    }
    func_800191F8(obj);
    func_80067704(sprite);
    HuPrcSleep(9);

    sprite = InitSprite(0x9006E);
    obj = func_80019060((s16)sprite, 0, 1);
    SetBasicSpritePos(obj, 0xA0, 0x78);
    ShowBasicSprite(obj);
    func_80018D84(obj, 0xFFFF);
    SetFadeInTypeAndTime(0, 9);
    while (func_80072718() != 0) {
        HuPrcVSleep();
    }
    HuPrcSleep(0x2D);
    func_800726AC(0, 9);
    while (func_80072718() != 0) {
        HuPrcVSleep();
    }
    func_800191F8(obj);
    func_80067704(sprite);
    HuPrcSleep(9);

    sprite = InitSprite(0x9006F);
    obj = func_80019060((s16)sprite, 0, 1);
    SetBasicSpritePos(obj, 0xA0, 0x78);
    ShowBasicSprite(obj);
    func_80018D84(obj, 0xFFFF);
    SetFadeInTypeAndTime(0, 9);
    while (func_80072718() != 0) {
        HuPrcVSleep();
    }
    HuPrcSleep(0x2D);
    D_800F5144 = 1;
    while (1) {
        HuPrcVSleep();
    }
}