#include "GroundPound.h"

u16 D_800FA020_GroundPound = 0;

void func_800F65E0_GroundPound(void) {
    D_800FA26C_GroundPound = -1;
    func_80029090(0x18);
    func_8001DE70(0x40);
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    func_80009500();
    omInitObjMan(32, 0);
    func_80060088();
    func_800F9E80_GroundPound(2500.0f, 315.0f, 0.0f, 0.0f, -330.0f, 458.0f, 375.0f);
    func_80017660(0, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 20.0f, 80.0f, 8000.0f);
    func_8002578C(0);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, &omOutView), 160);
    omAddObj(0, 0, 0, -1, &func_800F67E0_GroundPound);
    func_800F7FEC_GroundPound();
    D_800FA43C_GroundPound = omAddObj(8, 0xA, 0x64, -1, &func_800F8C20_GroundPound);
    omAddObj(0x2710, 0, 0, -1, &func_800F6EE4_GroundPound);
    SetFadeInTypeAndTime(0, 0x10);
    D_800FA262_GroundPound = 3;
    PlaySound(0x1A2);
}

void func_800F67E0_GroundPound(omObjData* arg0) {
    D_800FA260_GroundPound = 0;
    D_800FA266_GroundPound = 30;
    D_800FA268_GroundPound = 30;
    D_800ED430 = 0;
    arg0->func_ptr = &func_800F6814_GroundPound;
}

void func_800F6814_GroundPound(void) {
    if (D_800C5982 != 1) {
        switch (D_800FA260_GroundPound) {
        case 0:
            func_800F6924_GroundPound();
            return;
        case 1:
            D_800FA268_GroundPound--;
            if (D_800FA268_GroundPound == 0) {
                if (D_800FA266_GroundPound != 0) {
                    D_800FA266_GroundPound--;
                    func_80079078(D_800FA266_GroundPound);
                }
                D_800FA268_GroundPound = 30;
            }
            if (D_800FA266_GroundPound == 0 || D_800FA310_GroundPound != 0) {
                D_800FA260_GroundPound = 2;
                D_800FA264_GroundPound = 1;
                return;
            }
            break;
        case 2:
            func_800F6B0C_GroundPound();
            break;
        }
        
    }
}

void func_800F6924_GroundPound(void) {
    switch (D_800FA262_GroundPound) {
    case 1:
    case 3:
        if (func_80072718() == 0) {
            D_800FA262_GroundPound = 4;
            D_800FA26A_GroundPound = 45;
        }
        break;
    case 4:
        if (--D_800FA26A_GroundPound == 0) {
            D_800FA262_GroundPound = 5;
            func_800F6F40_GroundPound();
            D_800FA26A_GroundPound = 105;
        }
        break;
    case 5:
        if (D_800FA26A_GroundPound != 0) {
            D_800FA26A_GroundPound--;
        } else if (func_800F6FD4_GroundPound() != 0) {
            D_800FA262_GroundPound = 6;
            GMesCreate(0);
        }
        break;
    case 6:
        {
            s32 stat = GMesStatAllGet();

            if (stat == 0) {
                D_800FA260_GroundPound = 1;
                D_800ED430 = 1;
                func_80060128(0x25);
            } else if ((stat & 2) && D_800FA26C_GroundPound < 0) {
                D_800FA26C_GroundPound = GMesCreate(8, D_800FA266_GroundPound, 0xA0, 0x1C);
            }
        }
        break;
    }
}

void func_800F6A84_GroundPound(omObjData* obj) {
    Center.x += ((obj->trans.x - Center.x) + 2.0f) / 15.0f;
    Center.z += ((obj->trans.z - Center.z) + 300.0f) / 15.0f;
    CZoom -= 30.0f;
}

void func_800F6B0C_GroundPound(void) {
    s32 practice;
    omObjData* obj;
    unkGlobalStruct_00* w;
    s32 stat;
    s16 mes;
    s32 anim;
    f32 f;

    practice = _CheckFlag(0x2B);
    obj = D_800FA43C_GroundPound;
    w = obj->unk_50;
    switch (D_800FA264_GroundPound) {
    case 1:
        func_800601D4(0x28);
        f = func_800F8AA0_GroundPound(obj);
        D_800FA264_GroundPound = 2;
        func_800F9E4C_GroundPound(f);
        break;
    case 2:
        func_800790C0();
        if (D_800FA310_GroundPound != 0) {
            GwPlayer[w->unk_58].coins_mg += 10;
            mes = 2;
        } else {
            GwPlayer[w->unk_58].coins_mg -= 5;
            mes = 0x10;
            if (practice != 0) {
                mes = 2;
            }
        }
        GMesCreate(mes);
        D_800FA264_GroundPound = 3;
        break;
    case 3:
        if (D_800ED430 == 2) {
            D_800FA264_GroundPound = 4;
        }
        break;
    case 4:
        if (w->unk_3C != 0.0f) {
            if (w->unk_3C < 0.0f) {
                w->unk_3C += 20.0f;
            } else {
                w->unk_3C -= 20.0f;
            }
            if (w->unk_3C > -20.0f && w->unk_3C < 20.0f) {
                w->unk_3C = 0.0f;
            }
        } else if (practice == 0) {
            D_800FA264_GroundPound = 5;
        } else {
            D_800FA264_GroundPound = 13;
        }
        break;
    case 5:
        stat = GMesStatAllGet();
        if (stat == 0 || (stat & 2)) {
            if (D_800FA310_GroundPound != 0) {
                if (practice == 0) {
                    func_80060128(0x33);
                }
                anim = 13;
                D_800FA26A_GroundPound = 36;
                D_800FA264_GroundPound = 6;
            } else {
                if (practice == 0) {
                    func_80060128(0x34);
                }
                anim = 14;
                D_800FA26A_GroundPound = 18;
                D_800FA264_GroundPound = 7;
            }
            if (practice == 0) {
                func_800184BC(obj, anim);
                func_80017DB0(obj);
            }
        }
        break;
    case 6:
        if (--D_800FA26A_GroundPound == 0) {
            D_800FA26A_GroundPound = 1;
            D_800FA264_GroundPound = 7;
        } else {
            func_800F6A84_GroundPound(obj);
        }
        break;
    case 7:
        if (--D_800FA26A_GroundPound == 0) {
            if (D_800FA310_GroundPound != 0) {
                func_80060618(0x451, w->unk_58);
                D_800FA26A_GroundPound = 72;
            } else {
                func_80060618(0x44A, w->unk_58);
                D_800FA26A_GroundPound = 77;
            }
            D_800FA264_GroundPound = 13;
        }
        break;
    case 13:
        stat = 0;
        if (practice != 0) {
            stat = GMesWait() == 0;
        } else if (--D_800FA26A_GroundPound == 0) {
            stat++;
        }
        if (stat) {
            D_800FA264_GroundPound = 14;
            func_800726AC(0, 20);
        }
        break;
    case 14:
        if (func_80072718() == 0) {
            D_800FA020_GroundPound = 1;
        }
        break;
    }
}

void func_800F6EE4_GroundPound(void) {
    if (D_800F5144 != 0 || D_800FA020_GroundPound != 0) {
        D_800B895C = 15.0f;
        func_800601D4(10);
        omOvlReturnEx(1);
    }
}
