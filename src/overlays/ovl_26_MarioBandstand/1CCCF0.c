#include "1CCCF0.h"

u16 D_800FCBF0_MarioBandstand = 0;

void func_800F65E0_MarioBandstand(void) {
    s32 i;

    func_80029090(4);
    func_8001DE70(0x48);
    omInitObjMan(0x10, 0);
    D_800FD286_MarioBandstand = D_800C597C;
    D_800C597C &= ~0x10;
    func_80060088();
    func_800FC930_MarioBandstand(1150.0f, -10.0f, 0, 0, 0, 50.0f, 445.0f);
    func_80017660(0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 25.0f, 80.0f, 8000.0f);
    func_8002890C(0, 0, 0);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    omAddObj(0, 0, 0, -1, &func_800F6808_MarioBandstand);
    omSetStatBit(omAddObj(6, 0, 0, -1, &func_800FB4D8_MarioBandstand), 0xA0);

    for (i = 0; i < 16; i++) {
        D_800FD6E0_MarioBandstand[i] = -1;
    }
    
    D_800FD714_MarioBandstand = -1;
    func_800F6F70_MarioBandstand();
    func_800F97D0_MarioBandstand();
    func_800FB1D0_MarioBandstand();
    omAddObj(0x2710, 0, 0, -1, &func_800F6F10_MarioBandstand);
    SetFadeInTypeAndTime(0, 0x10);
    D_800FD282_MarioBandstand = 1;
}

void func_800F6808_MarioBandstand(omObjData* arg0) {
    D_800FD280_MarioBandstand = 0;
    D_800ED430 = 0;
    arg0->func_ptr = &func_800F6828_MarioBandstand;
}

void func_800F6828_MarioBandstand(void) {
    if (D_800C5982 != 1) {
        switch (D_800FD280_MarioBandstand) {
        case 0:
            func_800F68D4_MarioBandstand();
            return;
        case 1:
            if (func_800FC8A8_MarioBandstand(0x4000) != 0) {
                D_800FD280_MarioBandstand = 2;
                D_800FD284_MarioBandstand = 1;
                D_800ED430 = 2;
                return;
            }
            break;
        case 2:
            func_800F6B04_MarioBandstand();
            break;
        }
    }
}

void func_800F68D4_MarioBandstand(void) {
    switch (D_800FD282_MarioBandstand) {
    case 1:
        func_800F7C1C_MarioBandstand(0x6A);
        D_800FD288_MarioBandstand = 0x2D;
        D_800FD282_MarioBandstand = 2;
        break;
    case 2:
        if (--D_800FD288_MarioBandstand == 0) {
            D_800FD288_MarioBandstand = 0x1E;
            D_800FD282_MarioBandstand = 3;
        }
        break;
    case 3:
        if (--D_800FD288_MarioBandstand == 0) {
            D_800FD288_MarioBandstand = 0x1E;
            PlaySound(0x1B1);
            PlaySound(0x1B2);
            D_800FD282_MarioBandstand = 4;
        }
        break;
    case 4:
        if (--D_800FD288_MarioBandstand == 0) {
            D_800FD282_MarioBandstand = 5;
            func_800F7C1C_MarioBandstand(1);
            func_800F7C1C_MarioBandstand(0x69);
            D_800FD288_MarioBandstand = 0x6E;
        }
        break;
    case 5:
        if (--D_800FD288_MarioBandstand == 0) {
            func_800FB214_MarioBandstand();
            func_8002578C(0);
            D_800FD282_MarioBandstand = 6;
            GMesCreate(0);
            func_800F7C1C_MarioBandstand(2);
            break;
        }
        CZoom -= 1.5f;
        if (CZoom < 1000.0f) {
            CZoom = 1000.0f;
        }
        Center.y += 1.7f;
        if (Center.y > 220.0f) {
            Center.y = 220.0f;
        }
        break;
    case 6:
        if (GMesStatAllGet() == 0) {
            D_800FD280_MarioBandstand = 1;
            D_800ED430 = 1;
        }
        break;
    }
}

// NON_MATCHING: masked 76 (first pass, inflated by address shift); calls/stores checked with n64nmcmp
#ifdef NON_MATCHING
void func_800F6B04_MarioBandstand(void) {
    s32 flag;
    s32 ret;
    s32 sound;
    u16 left;

    flag = _CheckFlag(0x2B);
    switch (D_800FD284_MarioBandstand) {
    case 1:
        D_800FD290_MarioBandstand = 0;
        D_800FD28C_MarioBandstand = 0xFFFF;
        func_800F7C1C_MarioBandstand(3);
        D_800FD288_MarioBandstand = 0;
        D_800FD294_MarioBandstand = 0;
        ret = func_800F7D58_MarioBandstand();
        if (ret < 0x10) {
            func_800F7C1C_MarioBandstand(0x65);
            PlaySound(0x1B1);
            sound = 0x1B2;
            goto play;
        }
        sound = 0x1B1;
        if (ret < 0x28) {
        play:
            PlaySound(sound);
        }
        func_8002578C(1);
        D_800FD284_MarioBandstand = 2;
        break;
    case 2:
        if (++D_800FD294_MarioBandstand == 0x2D) {
            GMesCreate(2);
            D_800FD290_MarioBandstand = 1;
        } else if (D_800FD290_MarioBandstand == 1) {
            ret = GMesStatAllGet();
            if (ret == 0 || (ret & 2)) {
                D_800FD290_MarioBandstand = 2;
                D_800FD28C_MarioBandstand = 0x19;
                ret = func_800F81C0_MarioBandstand(2);
                if (flag == 0) {
                    switch (ret) {
                    case 0:
                        func_80060128(0x35);
                        break;
                    case 1:
                        func_80060128(0x32);
                        break;
                    case 4:
                        func_80060128(0x37);
                        break;
                    case 2:
                    case 3:
                        func_80060128(0x36);
                        break;
                    }
                }
            }
        } else if (D_800FD290_MarioBandstand == 2) {
            if (D_800FD28C_MarioBandstand != 0) {
                D_800FD28C_MarioBandstand--;
            } else {
                D_800FD290_MarioBandstand = 3;
                if (func_800F81C0_MarioBandstand(2) == 1) {
                    func_800F81C0_MarioBandstand(1);
                }
            }
        }
        if ((f32) D_800FD294_MarioBandstand == 60.0f) {
            func_800F81C0_MarioBandstand(0);
            D_800FD288_MarioBandstand = D_800FD296_MarioBandstand;
        }
        CZoom += 11.2375f;
        if (CZoom > 1899.0f) {
            CZoom = 1899.0f;
            if (D_800FD290_MarioBandstand >= 3) {
                left = 0x5A - (D_800FD296_MarioBandstand - D_800FD288_MarioBandstand);
                D_800FD288_MarioBandstand = left;
                if (left & 0x8000) {
                    D_800FD288_MarioBandstand = 0;
                }
                if (flag != 0) {
                    D_800FD284_MarioBandstand = 6;
                } else {
                    D_800FD284_MarioBandstand = 4;
                }
            }
        }
        break;
    case 4:
        if (D_800FD288_MarioBandstand != 0) {
            D_800FD288_MarioBandstand--;
            break;
        }
        func_800F7C1C_MarioBandstand(0);
        D_800FD284_MarioBandstand = 6;
        D_800FD288_MarioBandstand = 0x23;
        break;
    case 5:
        ret = GMesStatAllGet();
        if (ret == 0 || (ret & 2)) {
            D_800FD284_MarioBandstand = 6;
            D_800FD288_MarioBandstand = 0x3C;
        }
        break;
    case 6:
        if (flag != 0) {
            if (GMesWait() == 0) {
                D_800FD284_MarioBandstand = 7;
                func_800726AC(0, 0x14);
            }
        } else if (--D_800FD288_MarioBandstand == 0) {
            D_800FD284_MarioBandstand = 7;
            func_800726AC(0, 0x23);
        }
        break;
    case 7:
        if (func_80072718() == 0) {
            D_800FCBF0_MarioBandstand = 1;
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_26_MarioBandstand/1CCCF0", func_800F6B04_MarioBandstand);
#endif

void func_800F6F10_MarioBandstand(void) {
    if (D_800F5144 != 0 || D_800FCBF0_MarioBandstand != 0) {
        D_800C597C = D_800FD286_MarioBandstand;
        func_800601D4(0xA);
        omOvlReturnEx(1);
    }
}
