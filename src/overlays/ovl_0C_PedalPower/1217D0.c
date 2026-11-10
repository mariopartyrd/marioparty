#include "PedalPower.h"

/* .data (0x800F9DE0) */
s32 D_800F9DE0_PedalPower = 0;
u32 D_800F9DE4_PedalPower = 0; /* state-0 frames */
u32 D_800F9DE8_PedalPower = 0; /* state-1 frames */
u32 D_800F9DEC_PedalPower = 0; /* state-2 frames */
s32 D_800F9DF0_PedalPower = 0; /* state-3 frames */
s32 D_800F9DF4_PedalPower = 0;
s8 D_800F9DF8_PedalPower = 0;  /* result jingle started */
u8 D_800F9DF9_PedalPower = 0;  /* bulb sway direction */
u8 D_800F9DFA_PedalPower = 0;  /* pedal sound playing */
s32 D_800F9DFC_PedalPower = 0;
s32 D_800F9E00_PedalPower = 0;
s32 D_800F9E04_PedalPower = 0;
s32 D_800F9E08_PedalPower = 0;
u8 D_800F9E0C_PedalPower = 0; /* fizzle sound played */
u8 D_800F9E0D_PedalPower = 0; /* 2 = burst done */
u8 D_800F9E0E_PedalPower = 0; /* burst sound played */
u8 D_800F9E0F_PedalPower = 0;
f32 D_800F9E10_PedalPower = 0.7f;

void func_800F73CC_PedalPower(omObjData* arg0);
void func_800F7618_PedalPower(omObjData* arg0);
void func_800F689C_PedalPower(omObjData* arg0, u32 arg1);

void func_800F65E0_PedalPower(void) {
    func_80029090(0x20);
    func_8002ADF0(&D_800EDEC0, 64);
    func_8001DE70(32);
    omInitObjMan(32, 0);
    func_80060088();
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 160);
    func_8000942C();
    Center.x = 50.0f;
    Center.y = 200.0f;
    Center.z = -100.0f;
    CRot.x = CRot.y = CRot.z = 0.0f;
    CZoom = 1750.0f;
    func_800F67AC_PedalPower();
    func_800F6870_PedalPower();
    D_800FA72D_PedalPower = 0;
    D_800FA738_PedalPower = 0;
    D_800FA72C_PedalPower = 0;
    func_800F8EE0_PedalPower();
    func_800F79B0_PedalPower();
    func_800F6CF8_PedalPower();
    func_80023448(3);
    func_800234B8(0, 16, 16, 16);
    func_80023504(1, -43.0f, -18.0f, -110.0f);
    func_800234B8(1, 0, 0, 0);
    func_80023504(2, 9.0f, -17.0f, 118.0f);
    func_800234B8(2, 0, 0, 0);
    func_80023504(3, -43.0f, -18.0f, -110.0f);
    func_800234B8(3, 0, 0, 0);
    func_8002890C(0, 15, 0);
    SetFadeInTypeAndTime(0, 16);
}

void func_800F67AC_PedalPower(void) {
    s16 temp_s0;
    u8 temp_s1;

    func_800178A0(1);
    temp_s0 = func_800178E8();
    temp_s1 = temp_s0;
    func_80017660(temp_s1, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(temp_s1, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(temp_s0, 30.0f, 80.0f, 8000.0f);
}

void func_800F6870_PedalPower(void) {
    if (GMesStatAllGet() != 0) {
        GMesStatAllGet();
    }
}

void func_800F689C_PedalPower(omObjData* arg0, u32 arg1) {
    u32 new_var;
    switch (D_800ED430) {
    case 0:
        GMesStatAllGet();
        if (arg1 == 0) {
            GMesCreate(0);
            if (GMesStatAllGet() != 0) {
                GMesStatAllGet();
                break;
            }
        } else {
            if (arg1 >= 60) {
                func_80009458();
                break;
            }
        }
        break;
    case 1:
        do { (new_var = 0x384); } while (0); //required to match
        if (new_var == arg1) {
            func_80009438();
        }
        break;
    case 2:
        break;
    }
}

void func_800F6944_PedalPower(omObjData* arg0) {
    s32 flag;

    func_80009468();
    switch (D_800ED430) {
    case 0:
        if (D_800F9DE4_PedalPower > 60) {
            func_80009458();
        }
        func_800F689C_PedalPower(arg0, D_800F9DE4_PedalPower);
        D_800F9DE4_PedalPower++;
        break;
    case 1:
        if (D_800F9DE8_PedalPower == 0) {
            func_80060128(0x20);
        }
        func_800F689C_PedalPower(arg0, D_800F9DE8_PedalPower);
        D_800F9DE8_PedalPower++;
        break;
    case 2:
        func_80060758(0x22C);
        func_80060758(0x22E);
        if (D_800F9DF4_PedalPower == 36) {
            if (D_800FA72C_PedalPower == 2) {
                PlaySound(0x230);
            } else if (_CheckFlag(0x2B) == 0) {
                func_80060618(0x451, (s16)D_800FA728_PedalPower);
            }
        } else if ((D_800FA72C_PedalPower == 1 && D_800F9DF4_PedalPower == 100)
                   || (D_800FA72C_PedalPower == 2 && D_800F9DF4_PedalPower == 72)) {
            if (_CheckFlag(0x2B) == 0) {
                func_800726AC(0, 20);
                func_80009448();
            }
        }
        if (_CheckFlag(0x2B) != 0 && D_800F9DF4_PedalPower == 72
            && (D_800FA72C_PedalPower == 1 || D_800FA72C_PedalPower == 2)) {
            func_800726AC(0, 20);
            func_80009448();
        }
        if (D_800F9DEC_PedalPower == 0) {
            func_800601D4(40);
            if (_CheckFlag(0x2B) == 0 && D_800FA72C_PedalPower == 2) {
                GMesCreate(0xE);
            } else {
                GMesCreate(2);
            }
        } else if (GMesStatAllGet() == 0 || (GMesStatAllGet() & 2)) {
            if (D_800FA72C_PedalPower == 1 && D_800F9DF8_PedalPower == 0) {
                if (_CheckFlag(0x2B) == 0) {
                    func_80060128(0x33);
                    D_800F9DF8_PedalPower = 1;
                }
            } else if (D_800FA72C_PedalPower == 2 && D_800F9DF8_PedalPower == 0) {
                if (_CheckFlag(0x2B) == 0) {
                    func_80060128(0x34);
                    D_800F9DF8_PedalPower = 1;
                }
            }
            D_800F9DF4_PedalPower++;
        }
        func_800F689C_PedalPower(arg0, D_800F9DEC_PedalPower);
        D_800F9DEC_PedalPower++;
        break;
    case 3:
        flag = _CheckFlag(0x2B);
        if (flag == 1 && GMesWait() == flag) {
            func_800726AC(0, 20);
        }
        func_80060758(0x22D);
        func_80060758(0x22F);
        func_80060758(0x230);
        if (func_80072718() == 0) {
            func_8006073C();
            omOvlReturnEx(1);
        }
        D_800F9DF0_PedalPower++;
        break;
    }
}

void func_800F6CF8_PedalPower(void) {
    omAddObj(2, 2, 0, -1, &func_800F6D2C_PedalPower);
}

void func_800F6D2C_PedalPower(omObjData* arg0) {
    UnkPedalPowerStruct* temp_s1;

    arg0->unk_50 = func_80023684(sizeof(UnkPedalPowerStruct), 0x7918);
    func_8009B770(arg0->unk_50, 0, sizeof(UnkPedalPowerStruct));
    temp_s1 = arg0->unk_50;
    D_800FA73C_PedalPower.x = 400.0f;
    D_800FA73C_PedalPower.y = 250.0f;
    D_800FA73C_PedalPower.z = 600.0f;
    arg0->trans.x = 400.0f;
    arg0->trans.y = D_800FA73C_PedalPower.y;
    arg0->trans.z = D_800FA73C_PedalPower.z;
    arg0->scale.z = 1.2f;
    arg0->scale.y = 1.2f;
    arg0->scale.x = 1.2f;
    arg0->rot.y = -45.0f;
    arg0->func_ptr = &func_800F6ED0_PedalPower;
    arg0->model[0] = LoadFormFile(0xA0088, 0x649);
    func_80009340(arg0, 1, 0x26, 0x64D, 8);
    func_8001E360(temp_s1->unk_22, 255, 255, 255);
    func_8001E2F8(temp_s1->unk_22, 255);
    func_80025EB4(arg0->model[0], 2, 1);
    func_80021240(arg0->model[0]);
    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_800257E4(arg0->model[0], arg0->rot.x, arg0->rot.y, arg0->rot.z);
    func_80025830(arg0->model[0], arg0->scale.x, arg0->scale.y, arg0->scale.z);
    func_80025830(arg0->model[1], 2.0f, 2.0f, 2.0f);
}

// register allocation of the rand8() & 3 temp (masked 0)
#ifdef NON_MATCHING
void func_800F6ED0_PedalPower(omObjData* arg0) {
    s32 snd;
    s32 pan;

    func_800211BC(arg0->model[0], 0x40);
    if (D_800FA72C_PedalPower == 1) {
        func_800F73CC_PedalPower(arg0);
    }
    if (D_800FA72C_PedalPower == 2) {
        func_800F7618_PedalPower(arg0);
    }
    if (D_800ED430 != 1) {
        return;
    }
    if (D_800F9DFC_PedalPower % ((rand8() & 3) * 30 + 60) == 0) {
        D_800F9DFA_PedalPower = 0;
    }
    if (D_800F9DFA_PedalPower == 0) {
        snd = PlaySound(0x231);
        pan = (arg0->trans.x + 150.0f) / 550.0f * 16.0f;
        D_800F9EE1_PedalPower = pan;
        D_800F9EE0_PedalPower = 0x7F - pan;
        func_8006035C(snd, D_800F9EE0_PedalPower);
        D_800F9DFA_PedalPower = 1;
    }
    if (arg0->trans.x <= -60.0f) {
        arg0->trans.y -= 1.5f;
        if (arg0->trans.y < 100.0f) {
            arg0->trans.y = 100.0f;
        }
        if (arg0->scale.y < 1.2f) {
            arg0->scale.y += 0.05f;
        } else if (arg0->scale.y > 1.2f) {
            arg0->scale.y -= 0.05f;
        }
        arg0->rot.y = -45.0f;
        arg0->rot.z = 0.0f;
        D_800FA72C_PedalPower = 2;
    } else {
        arg0->trans.y = func_800AEAC0((u32)D_800F9DFC_PedalPower) * 64.0f + D_800FA73C_PedalPower.y;
        if (D_800FA738_PedalPower >= 35) {
            f32 s = func_800AEAC0((u32)(D_800F9E00_PedalPower * 5)) * 0.5f;
            arg0->scale.x = 1.2f - s;
            arg0->scale.y = s + 1.2f;
            D_800F9E00_PedalPower++;
        } else {
            if (arg0->scale.y < 1.1500001f) {
                arg0->scale.y += 0.05f;
            } else if (arg0->scale.y > 1.25f) {
                arg0->scale.y -= 0.05f;
            } else {
                arg0->scale.y = 1.2f;
            }
            arg0->rot.y = -45.0f;
        }
        if (D_800F9DF9_PedalPower == 1) {
            arg0->rot.z += 1.5f;
            if (arg0->rot.z > 20.0f) {
                D_800F9DF9_PedalPower = 0;
            }
        } else if (D_800F9DF9_PedalPower == 0) {
            arg0->rot.z -= 1.5f;
            if (arg0->rot.z < -40.0f) {
                D_800F9DF9_PedalPower = 1;
            }
        }
    }
    arg0->trans.x -= 0.85f;
    if (arg0->trans.x < -150.0f) {
        arg0->trans.x = -150.0f;
    }
    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_800257E4(arg0->model[0], arg0->rot.x, arg0->rot.y, arg0->rot.z);
    func_80025830(arg0->model[0], arg0->scale.x, arg0->scale.y, arg0->scale.z);
    D_800F9DFC_PedalPower++;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_PedalPower/1217D0", func_800F6ED0_PedalPower);
#endif

void func_800F73CC_PedalPower(omObjData* arg0) {
    arg0->scale.x -= 0.04f;
    arg0->scale.y -= 0.04f;
    arg0->scale.z -= 0.04f;
    if ((D_800F9E04_PedalPower & 7) == 0) {
        D_800F9E08_PedalPower ^= 1;
    }
    if (D_800F9E08_PedalPower != 0) {
        arg0->scale.y += func_800AEAC0((u32)(D_800F9E04_PedalPower * 45)) * 0.5f;
    } else {
        arg0->scale.x += func_800AEAC0((u32)(D_800F9E04_PedalPower * 45)) * 0.5f;
    }
    if (arg0->scale.x < 0.0f) {
        arg0->scale.x = 0.0f;
    }
    if (arg0->scale.y < 0.0f) {
        arg0->scale.y = 0.0f;
    }
    if (arg0->scale.z < 0.0f) {
        arg0->scale.z = 0.0f;
    }
    if (arg0->scale.z <= 0.1f) {
        func_800258EC(arg0->model[0], 4, 4);
        if (D_800F9E0C_PedalPower == 0) {
            PlaySound(0x232);
            D_800F9E0C_PedalPower = 1;
        }
        func_80025798(arg0->model[1], arg0->trans.x, arg0->trans.y - 100.0f, arg0->trans.z);
        func_800258EC(arg0->model[1], 4, 0);
    }
    D_800F9E04_PedalPower++;
}

void func_800F7618_PedalPower(omObjData* arg0) {
    if (D_800F9E0D_PedalPower == 2) {
        arg0->trans.x -= 3.0f;
        arg0->trans.y += 3.0f;
    } else {
        func_80060F04((s16)D_800FA728_PedalPower, 20, 0, 20);
        if (D_800F9E0E_PedalPower == 0) {
            if (_CheckFlag(0x2B) == 0) {
                func_80060618(0x45F, (s16)D_800FA728_PedalPower);
                PlaySound(0x22F);
            }
            D_800F9E0E_PedalPower = 1;
        }
        D_800F9EE4_PedalPower = func_800AEAC0((u32)(D_800F9EE8_PedalPower * 30)) * D_800F9E10_PedalPower;
        if (D_800F9EE4_PedalPower < 0.0f) {
            D_800F9EE4_PedalPower = -D_800F9EE4_PedalPower;
        }
        D_800F9EE4_PedalPower += 1.0f;
        if (D_800F9EE4_PedalPower < 1.2f) {
            D_800F9EE4_PedalPower = 1.2f;
        }
        arg0->scale.x = arg0->scale.y = arg0->scale.z = D_800F9EE4_PedalPower;
        D_800F9E10_PedalPower -= 0.02f;
        if (D_800F9E10_PedalPower < 0.0f) {
            D_800F9E10_PedalPower = 0.0f;
            D_800F9E0D_PedalPower = 2;
        }
        D_800F9EE8_PedalPower++;
        if (D_800FA724_PedalPower == 1) {
            if (D_800FA730_PedalPower.x + 10.0f < arg0->trans.x) {
                arg0->trans.x -= 3.0f;
            } else {
                arg0->trans.x = D_800FA730_PedalPower.x + 10.0f;
            }
            if (D_800FA730_PedalPower.y + 130.0f < arg0->trans.y) {
                arg0->trans.y -= 3.0f;
            } else {
                arg0->trans.y = D_800FA730_PedalPower.y + 130.0f;
            }
        } else {
            if (D_800FA730_PedalPower.x - 20.0f < arg0->trans.x) {
                arg0->trans.x -= 3.0f;
            } else {
                arg0->trans.x = D_800FA730_PedalPower.x - 20.0f;
            }
            if (D_800FA730_PedalPower.y + 120.0f < arg0->trans.y) {
                arg0->trans.y -= 3.0f;
            } else {
                arg0->trans.y = D_800FA730_PedalPower.y + 120.0f;
            }
        }
    }
    D_800FA73C_PedalPower.x = arg0->trans.x;
    D_800FA73C_PedalPower.y = arg0->trans.y;
    D_800FA73C_PedalPower.z = arg0->trans.z;
}
