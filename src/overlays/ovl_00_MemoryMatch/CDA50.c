#include "common.h"
#include "MemoryMatch.h"
#include "PR/os.h"
#include "PR/gu.h"

void func_800F8314_MemoryMatch(void);
void func_800FADDC_MemoryMatch(omObjData*);
void func_800FAD94_MemoryMatch(omObjData* arg0, s16 arg1);
extern s16 D_800FE190_MemoryMatch;
extern s16 D_800FE150_MemoryMatch;

/* .data */
u32 D_800FD7E0_MemoryMatch = 0x19971204;
Vec3f D_800FD7E4_MemoryMatch = { 296.0f, 0.0f, 296.0f };
Vec3f D_800FD7F0_MemoryMatch[NUM_OF_TILES] = {
    { -1.0f, 0.0f, -1.0f }, { -1.0f, 0.0f, 0.0f }, { -1.0f, 0.0f, 1.0f },
    { 0.0f, 0.0f, -1.0f },  { 0.0f, 0.0f, 0.0f },  { 0.0f, 0.0f, 1.0f },
    { 1.0f, 0.0f, -1.0f },  { 1.0f, 0.0f, 0.0f },  { 1.0f, 0.0f, 1.0f },
};
u16 D_800FD85C_MemoryMatch[NUM_OF_TILES] = { 1, 2, 3, 4, 5, 1, 2, 3, 4 };
u8 D_800FD86E_MemoryMatch = 0;
s16 D_800FD870_MemoryMatch = 0;
s16 D_800FD872_MemoryMatch = 0;
s16 D_800FD874_MemoryMatch = 0;
s16 D_800FD876_MemoryMatch = 0;
s16 D_800FD878_MemoryMatch = 0;
u16 D_800FD87A_MemoryMatch = 1;
u16 D_800FD87C_MemoryMatch = 0;
s16 D_800FD87E_MemoryMatch = 0; /* unreferenced filler */
s16 D_800FD880_MemoryMatch = 0;
s16 D_800FD882_MemoryMatch = 0;
s16 D_800FD884_MemoryMatch = 0;
s16 D_800FD886_MemoryMatch = 0; /* unreferenced filler */
s16 D_800FD888_MemoryMatch[9] = { 9, 9, 9, 9, 9, 9, 9, 9, 9 };
s16 D_800FD89A_MemoryMatch = 9;
s16 D_800FD89C_MemoryMatch = 0;
s16 D_800FD89E_MemoryMatch = 0;
s16 D_800FD8A0_MemoryMatch = 4;
s16 D_800FD8A2_MemoryMatch = 0; /* unreferenced filler */
f32 D_800FD8A4_MemoryMatch = 80.0f;
f32 D_800FD8A8_MemoryMatch = 0.0f;
s32 D_800FD8AC_MemoryMatch = 0; /* unreferenced filler */
s32 D_800FD8B0_MemoryMatch[4] = { 0x21, 0x22, 0x23, 0x120012 };

void func_800F65E0_MemoryMatch(void) {
    f32 temp_f20;
    f64 temp_f22;
    s32 temp_s0;
    unk_Struct00* temp_s0_2;

    func_80029090(50);
    omInitObjMan(50, 0);
    func_80060088();
    func_8001DE70(64);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, &omOutView), 0xA0);
    func_80023448(2);
    func_800234B8(0, 0xA0, 0xA0, 0xA0);
    func_800234B8(1, 0xFF, 0xFF, 0xFF);
    func_80023504(1, -96.0f, 100.0f, 26.0f);
    func_800178A0(1);
    temp_s0 = func_800178E8() & 0xFF;
    func_80017660(temp_s0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(temp_s0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 45.0f, 80.0f, 4000.0f);
    func_800F7C08_MemoryMatch();
    temp_s0_2 = D_800C3110;
    temp_s0_2->unk_40 = 40.0f;
    temp_f22 = 2.0;
    temp_f20 = func_800AEAC0(20.0f);
    D_800FDE28_MemoryMatch = temp_f20 / func_800AEFD0(temp_s0_2->unk_40 / temp_f22);
    guMtxL2F(D_800FDDE8_MemoryMatch, &temp_s0_2->unk_138);
    D_800ED440 = 0;
    D_800F2BC0 = 0;
    D_800FDDDC_MemoryMatch = omAddObj(0x20, 0, 0, -1, &func_800F6858_MemoryMatch);
    func_800F7B6C_MemoryMatch(rand8() & 0xFF);
    func_800F7D74_MemoryMatch();
    D_800FE2C2_MemoryMatch = -1;
    D_800FDE2C_MemoryMatch = 0;
    D_800ED430 = 0;
    D_800FE2C4_MemoryMatch = 0;
    D_800FE2C0_MemoryMatch = 0;
    D_800FE180_MemoryMatch = 0;
    func_8007B168(D_800FD8D0_MemoryMatch, 1);
    func_8007B168(D_800FD8DC_MemoryMatch, 1);
    func_8007B168(D_800FD8EC_MemoryMatch, 1);
    PlaySound(0x1A2);
}

void func_800F6858_MemoryMatch(omObjData* arg0) {
    arg0->func_ptr = &func_800F68CC_MemoryMatch;
    D_800FE2C2_MemoryMatch = 0;
    D_800FDE2C_MemoryMatch = 0;
    func_800F8C38_MemoryMatch();
    func_800F7EDC_MemoryMatch();
    func_800F963C_MemoryMatch();
    func_800F8E38_MemoryMatch();
    func_800F90CC_MemoryMatch();
    func_800FB360_MemoryMatch();
    if (_CheckFlag(MINIGAME_ISLAND_ENDING) != 0) {
        D_800FE180_MemoryMatch = 1;
    }
}

// register allocation (masked 0, raw 2)
#ifdef NON_MATCHING
void func_800F68CC_MemoryMatch(omObjData* arg0) {
    s16 t;
    u16 i;
    u16 j;
    f32 f;

    func_800F796C_MemoryMatch(arg0);
    t = D_800FDE2C_MemoryMatch;
    if (t == 0) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 2; j++) {
                D_800FDD80_MemoryMatch[j][i] = 160.0f;
                if ((i == 0) & (j == 1)) {
                    D_800FDDA0_MemoryMatch[j][i] = 100.0f;
                } else if ((i == 1) & (j == 0)) {
                    D_800FDDA0_MemoryMatch[j][i] = 100.0f;
                } else if ((i == 2) & (j == 0)) {
                    D_800FDDA0_MemoryMatch[j][i] = 140.0f;
                } else if ((i == 3) & (j == 1)) {
                    D_800FDDA0_MemoryMatch[j][i] = 140.0f;
                } else {
                    D_800FDDA0_MemoryMatch[j][i] = 120.0f;
                }
                D_800FDD70_MemoryMatch[j][i] = func_80064EF4(1, 0);
                func_80067480(D_800FDD70_MemoryMatch[j][i], 0, -1);
                func_80067354(D_800FDD70_MemoryMatch[j][i], 0, 1.0f, 1.0f);
                func_80067208(D_800FDD70_MemoryMatch[j][i], 0, ((s16*)&D_800FDE30_MemoryMatch.unk_04)[i], 0);
                func_800671DC(D_800FDD70_MemoryMatch[j][i], 0, 0);
                if (j & 1) {
                    func_800674BC(D_800FDD70_MemoryMatch[j][i], 0, 0x140C);
                } else {
                    func_800674BC(D_800FDD70_MemoryMatch[j][i], 0, 0x140D);
                }
                func_80066DC4(D_800FDD70_MemoryMatch[j][i], 0, D_800FDD80_MemoryMatch[j][i], D_800FDDA0_MemoryMatch[j][i]);
                func_800672B0(D_800FDD70_MemoryMatch[j][i], 0, 0);
                func_80067384(D_800FDD70_MemoryMatch[j][i], 0, i - 16);
            }
        }
    } else {
        if (t == 70) {
            GMesCreate(0);
        }
        if (t < 90) {
            CZoom = ((f32)((f32)t / 90.0) * -7.5 + 78.32) * 20.0;
        }
        if (t < 40) {
            f = (f32)t / 40.0;
            D_800FDD80_MemoryMatch[0][0] = 160.0 - f * 320.0;
            D_800FDD80_MemoryMatch[1][0] = f * 320.0 + 140.0;
            D_800FDDA0_MemoryMatch[0][0] = 120.0 - f * 120.0;
            D_800FDDA0_MemoryMatch[1][0] = 100.0 - f * 120.0;
            for (i = 0; i < 2; i++) {
                func_80066DC4(D_800FDD70_MemoryMatch[i][0], 0, D_800FDD80_MemoryMatch[i][0], D_800FDDA0_MemoryMatch[i][0]);
            }
            D_800FDD80_MemoryMatch[0][2] = 180.0 - f * 320.0;
            D_800FDD80_MemoryMatch[1][2] = f * 320.0 + 160.0;
            D_800FDDA0_MemoryMatch[0][2] = f * 120.0 + 140.0;
            D_800FDDA0_MemoryMatch[1][2] = f * 120.0 + 120.0;
            for (i = 0; i < 2; i++) {
                func_80066DC4(D_800FDD70_MemoryMatch[i][2], 0, D_800FDD80_MemoryMatch[i][2], D_800FDDA0_MemoryMatch[i][2]);
            }
            if (t == 39) {
                func_80060128(0x1A);
            }
        }
        i = 0;
        if (t < 120) {
            f = (f32)t / 120.0;
            D_800FDD80_MemoryMatch[0][1] = 140.0 - f * 320.0;
            D_800FDD80_MemoryMatch[1][1] = f * 320.0 + 160.0;
            D_800FDDA0_MemoryMatch[0][1] = 100.0 - f * 120.0;
            D_800FDDA0_MemoryMatch[1][1] = 120.0 - f * 120.0;
            for (i = 0; i < 2; i++) {
                func_80066DC4(D_800FDD70_MemoryMatch[i][1], 0, D_800FDD80_MemoryMatch[i][1], D_800FDDA0_MemoryMatch[i][1]);
            }
            D_800FDD80_MemoryMatch[0][3] = 160.0 - f * 320.0;
            D_800FDD80_MemoryMatch[1][3] = f * 320.0 + 180.0;
            D_800FDDA0_MemoryMatch[0][3] = f * 120.0 + 120.0;
            D_800FDDA0_MemoryMatch[1][3] = f * 120.0 + 140.0;
            for (i = 0; i < 2; i++) {
                func_80066DC4(D_800FDD70_MemoryMatch[i][3], 0, D_800FDD80_MemoryMatch[i][3], D_800FDDA0_MemoryMatch[i][3]);
            }
        } else if (t == 120) {
            for (i = 0; i < 4; i++) {
                for (j = 0; j < 2; j++) {
                    func_8006503C(D_800FDD70_MemoryMatch[j][i], 0, 1);
                }
            }
            if (func_80072718() == 0) {
                arg0->func_ptr = func_800F714C_MemoryMatch;
                D_800FDE2C_MemoryMatch = 0;
                return;
            }
        }
    }
    D_800FDE2C_MemoryMatch++;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_00_MemoryMatch/CDA50", func_800F68CC_MemoryMatch);
#endif
void func_800F714C_MemoryMatch(omObjData* arg0) {
    func_800F9178_MemoryMatch();
    func_800F796C_MemoryMatch(arg0);
    if (GMesStatAllGet() == 0) {
        D_800FDE2C_MemoryMatch = 0;
        D_800FE2C2_MemoryMatch = 1;
        arg0->func_ptr = &func_800F71C4_MemoryMatch;
        func_800F8FEC_MemoryMatch();
        D_800FE150_MemoryMatch = func_8000C544();
        D_800ED430 = 1;
    }
}

void func_800F71C4_MemoryMatch(omObjData* arg0) {
    func_800F8F58_MemoryMatch();
    func_800F9178_MemoryMatch();
    func_800F7E20_MemoryMatch();
    func_800F796C_MemoryMatch(arg0);
    
    if (func_800F901C_MemoryMatch() == 0) {
        D_800FE2C4_MemoryMatch = 1;
    }
    
    if (D_800FE30E_MemoryMatch < 2) {
        if (D_800FD86E_MemoryMatch++ >= 0x1F) {
            D_800FE2C2_MemoryMatch = 2;
            D_800ED430 = 0;
            D_800FDE2C_MemoryMatch = 0;
            if (D_800FE180_MemoryMatch == 0) {
                arg0->func_ptr = &func_800F73A4_MemoryMatch;
            } else {
                arg0->func_ptr = &func_800F7874_MemoryMatch;
            }
            func_800790C0();
            func_80009730();
            func_800601D4(0x28);
            return;
        }
    } else if (((u16) D_800FE2C4_MemoryMatch != 0) && func_800F9BC8_MemoryMatch(D_800F3FB0[0]) != 0) {
        D_800FE2C2_MemoryMatch = 2;
        D_800ED430 = 0;
        D_800FDE2C_MemoryMatch = 0;
        if (D_800FE180_MemoryMatch == 0) {
            arg0->func_ptr = &func_800F73A4_MemoryMatch;
        } else {
            arg0->func_ptr = &func_800F7874_MemoryMatch;
        }
        
        func_80009730();
        func_800601D4(0x28);
    }
}

void func_800F7318_MemoryMatch(omObjData* arg0) {
    if (func_80072718() == 0) {
        arg0->func_ptr = &func_800F7350_MemoryMatch;
    }
}

void func_800F7350_MemoryMatch(void) {
    D_800C3110->unk_40 = 45.0f;
    osViBlack(FALSE);
    func_80060198();
    func_800F94E0_MemoryMatch();
    func_800F830C_MemoryMatch();
    omOvlReturnEx(1);
}

// case 1 reloads D_800FE30E before the <8 test (masked 4)
#ifdef NON_MATCHING
void func_800F73A4_MemoryMatch(omObjData* arg0) {
    s16 sounds1[6] = { 0x451, 0x452, 0x453, 0x454, 0x455, 0x456 };
    s16 sounds2[6] = { 0x44A, 0x44B, 0x44C, 0x44D, 0x44E, 0x44F };
    f32 t;
    s32 flag;

    func_800F796C_MemoryMatch(arg0);
    if (D_800FD876_MemoryMatch != 0) {
        if (D_800FE30E_MemoryMatch >= 8) {
            t = (f32)D_800FD874_MemoryMatch / 45.0;
        } else {
            t = (f32)D_800FD874_MemoryMatch / 30.0;
        }
        if (t > 1.0) {
            t = 1.0f;
            D_800FD876_MemoryMatch = 0;
        }
        func_800F7C70_MemoryMatch(t);
        D_800FE2C0_MemoryMatch = 1;
        D_800FD874_MemoryMatch++;
    }
    switch (D_800FD872_MemoryMatch) {
    case 0:
        D_800FD870_MemoryMatch++;
        if (D_800FE30E_MemoryMatch < 2) {
            if (D_800FD870_MemoryMatch >= 15) {
                GMesCreate(2);
                D_800FD870_MemoryMatch = 0;
                D_800FD872_MemoryMatch = 1;
            }
        } else {
            GMesCreate(0x10);
            D_800FD870_MemoryMatch = 0;
            D_800FD872_MemoryMatch = 1;
        }
        break;
    case 1:
        D_800FD870_MemoryMatch++;
        if (D_800FE30E_MemoryMatch < 2) {
            flag = D_800FD870_MemoryMatch > 20;
        } else {
            flag = D_800FD870_MemoryMatch >= 18;
        }
        if (flag) {
            if (D_800FE30E_MemoryMatch < 2) {
                goto music;
            }
            if (D_800FE30E_MemoryMatch < 8) {
            music:
                func_80060128(0x33);
            } else {
                func_80060128(0x34);
                D_800FE2C2_MemoryMatch = 5;
            }
            D_800FD876_MemoryMatch = 1;
            if (D_800FE30E_MemoryMatch < 2) {
                GwPlayer[D_800FE30C_MemoryMatch].coins_mg += 2;
            }
            D_800FD870_MemoryMatch = 0;
            D_800FD872_MemoryMatch = 2;
        }
        break;
    case 2:
        D_800FD870_MemoryMatch++;
        if (D_800FE30E_MemoryMatch < 2) {
            flag = D_800FD870_MemoryMatch > 1;
        } else if (D_800FE30E_MemoryMatch < 8) {
            flag = D_800FD870_MemoryMatch >= 16;
        } else {
            flag = D_800FD870_MemoryMatch >= 18;
        }
        if (flag) {
            if (D_800FE30E_MemoryMatch >= 8) {
                PlaySound(sounds2[D_800FE312_MemoryMatch]);
            }
            D_800FE2C2_MemoryMatch = 5;
            D_800FD870_MemoryMatch = 0;
            if (D_800FE30E_MemoryMatch < 2) {
                D_800FD872_MemoryMatch = 3;
            } else {
                D_800FD872_MemoryMatch = 4;
            }
        }
        break;
    case 3:
        D_800FD870_MemoryMatch++;
        if (D_800FD870_MemoryMatch >= 31) {
            if (D_800FE30E_MemoryMatch < 2) {
                PlaySound(sounds1[D_800FE312_MemoryMatch]);
            }
            D_800FD870_MemoryMatch = 0;
            D_800FD872_MemoryMatch = 4;
        }
        break;
    case 4:
        D_800FD870_MemoryMatch++;
        if (D_800FE30E_MemoryMatch < 2) {
            flag = D_800FD870_MemoryMatch > 56;
        } else if (D_800FE30E_MemoryMatch < 8) {
            flag = D_800FD870_MemoryMatch >= 75;
        } else {
            flag = D_800FD870_MemoryMatch >= 72;
        }
        if (flag && GMesWait() != 1) {
            func_800726AC(0, 20);
            func_800601D4(40);
            arg0->func_ptr = func_800F7318_MemoryMatch;
            D_800FD870_MemoryMatch = 0;
            D_800FD872_MemoryMatch = 5;
        }
        break;
    }
    func_800F9178_MemoryMatch();
}
#else
const s16 D_800FD9D0_MemoryMatch[6] __attribute__((section(".rodata"))) = { 0x451, 0x452, 0x453, 0x454, 0x455, 0x456 };
const s16 D_800FD9DC_MemoryMatch[6] __attribute__((section(".rodata"))) = { 0x44A, 0x44B, 0x44C, 0x44D, 0x44E, 0x44F };
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_00_MemoryMatch/CDA50", func_800F73A4_MemoryMatch);
#endif
void func_800F7874_MemoryMatch(omObjData* arg0) {
    func_800F796C_MemoryMatch(arg0);
    func_800F9178_MemoryMatch();
    switch (D_800FD878_MemoryMatch) {
    case 0:
        GMesCreate(2);
        if (D_800FE30E_MemoryMatch < 2) {
            GwPlayer[D_800FE30C_MemoryMatch].coins_mg += 2;
        }
        D_800FD878_MemoryMatch++;
        break;
    case 1:
        if (GMesStatAllGet() != 2) {
            return;
        }
        D_800FD878_MemoryMatch++;
        break;
    default:
        if (GMesWait() == 0) {
            func_800726AC(0, 20);
            func_80060398(40);
            arg0->func_ptr = &func_800F7318_MemoryMatch;
            D_800FD878_MemoryMatch++;
            break;
        }
        break;
    }
}

void func_800F796C_MemoryMatch(omObjData* arg0) {
    if (D_800F5144 == 1) {
        arg0->func_ptr = &func_800F7318_MemoryMatch;
    }
}

f32 func_800F7994_MemoryMatch(f32 arg0, f32 arg1, f32 arg2) {
    f32 diff;

    if (arg0 >= 360.0) {
        arg0 -= 360.0;
    } else if (arg0 < 0.0) {
        arg0 += 360.0;
    }
    if (arg1 >= 360.0) {
        arg1 -= 360.0;
    } else if (arg1 < 0.0) {
        arg1 += 360.0;
    }
    diff = func_8009B618((arg0 - arg1) + 360.0, 360.0);
    if (diff < 180.0) {
        if (diff <= arg2) {
            return diff;
        }
        return arg2;
    }
    if (360.0 - diff <= arg2) {
        return -(360.0 - diff);
    }
    return -arg2;
}
u16 func_800F7AFC_MemoryMatch(u16 arg0) {
    D_800FD7E0_MemoryMatch = D_800FD7E0_MemoryMatch * 0x19971204;
    D_800FD7E0_MemoryMatch = (D_800FD7E0_MemoryMatch + 0x19760831) >> 0x10;
    if (arg0 == 0) {
        return D_800FD7E0_MemoryMatch;
    } else {
        return (D_800FD7E0_MemoryMatch % arg0);
    }
}

void func_800F7B6C_MemoryMatch(u16 arg0) {
    D_800FD7E0_MemoryMatch = arg0 * D_800FD7E0_MemoryMatch;
    D_800FD7E0_MemoryMatch += arg0;
}

f32 func_800F7B90_MemoryMatch(f32 arg0, f32 arg1) {
    f32 phi_f4 = func_800B0CD8(arg0, arg1);

    if (360.0 < phi_f4) {
        phi_f4 -= 360.0;  
    } else {
        if (phi_f4 < 0.0) {
            phi_f4 += 360.0;
        }
    }
    return phi_f4;
}

void func_800F7C08_MemoryMatch(void) {
    CRot.x = -41.39f;
    CRot.y = 0.0f;
    CRot.z = 0;
    Center.x = -5.0f;
    Center.y = -30.0f;
    Center.z = 0;
    CZoom = 1556.0f;
}

void func_800F7C70_MemoryMatch(f32 arg0) {
    omObjData* temp_a0;

    if (arg0 == 0.0) {
        temp_a0 = D_800F3FB0[0];
        D_800FDDC0_MemoryMatch.x = Center.x;
        D_800FDDC0_MemoryMatch.y = Center.y;
        D_800FDDC0_MemoryMatch.z = Center.z;
        D_800FDDCC_MemoryMatch.x = temp_a0->trans.x;
        D_800FDDCC_MemoryMatch.y = temp_a0->trans.y;
        D_800FDDCC_MemoryMatch.z = temp_a0->trans.z;
        return;
    }
    
    Center.x = D_800FDDC0_MemoryMatch.x + (arg0 * (D_800FDDCC_MemoryMatch.x - D_800FDDC0_MemoryMatch.x));
    Center.y = D_800FDDC0_MemoryMatch.y + (arg0 * (D_800FDDCC_MemoryMatch.y - D_800FDDC0_MemoryMatch.y));
    Center.z = D_800FDDC0_MemoryMatch.z + (arg0 * (D_800FDDCC_MemoryMatch.z - D_800FDDC0_MemoryMatch.z));
    CZoom = (1416.3999999999999 - (arg0 * 840.0));
}

void func_800F7D74_MemoryMatch(void) {
    s16 i;

    for (i = 0; i < 10; i++) {
        D_800FE158_MemoryMatch[i].unk0 = -1;
        D_800FE158_MemoryMatch[i].unk2 = -1;
    }
}

void func_800F7DC0_MemoryMatch(s16 arg0, s16 arg1) {
    s16 i;
    for (i = 0; i < 0x0A; i++) {
        if (D_800FE158_MemoryMatch[i].unk0 == -1) {
            D_800FE158_MemoryMatch[i].unk0 = arg0;
            D_800FE158_MemoryMatch[i].unk2 = arg1;
            return;
        }
    }
}

void func_800F7E20_MemoryMatch(void) {
    s16 i;
    s16 t;

    for (i = 0; i < 10; i++) {
        if (D_800FE158_MemoryMatch[i].unk0 != -1) {
            t = D_800FE158_MemoryMatch[i].unk2 - 1;
            D_800FE158_MemoryMatch[i].unk2 = t;
            if (t <= 0) {
                PlaySound(D_800FE158_MemoryMatch[i].unk0);
                D_800FE158_MemoryMatch[i].unk0 = -1;
                D_800FE158_MemoryMatch[i].unk2 = -1;
            }
        }
    }
}
typedef struct unkStruct_01 {
/* 0x00 */ s8 unk_00;
/* 0x01 */ s8 unk_01;
} unkStruct_01;

typedef struct unkStruct_02 {
/* 0x00 */ u16 unk_00;
} unkStruct_02;


extern omObjData* D_800FDDE0_MemoryMatch;

void func_800F7EDC_MemoryMatch(void) {
    omObjData* curObject;
    Vec3f sp18 = {0.0f, 0.0f, 0.0f};
    Vec2f sp24;
    u16 i;

    sp24.x = 0;
    sp24.y = 0;

    func_800090B8(D_800ED440);
    D_800F2AF8[D_800ED440++] = omAddObj(0, 1, 0, -1, (*func_800FB0A8_MemoryMatch));
    D_800FDDE0_MemoryMatch = omAddObj(1, 3, 0, -1, (*func_800F8130_MemoryMatch));

    curObject = D_800FDDE0_MemoryMatch;
    curObject->model[0] = LoadFormFile(0x120000, 0x99);
    curObject->model[1] = LoadFormFile(0x12000A, 0xB9);
    curObject->model[2] = LoadFormFile(0x12000B, 0xB9);

    sp18.x = -540.0f;
    sp18.y = 0.0f;
    sp18.z = -280.0f;
    sp24.x = 160.0f;
    sp24.y = 200.0f;

    func_800F8D84_MemoryMatch(&sp18, &sp24);
    for (i = 0; i < 9; i++) {
        curObject = D_800FE2E8_MemoryMatch[i] = omAddObj(0, 1, 0, -1, (*func_800F87DC_MemoryMatch));
        curObject->work[0] = i;
        curObject->work[1] = D_800FD85C_MemoryMatch[i];
        curObject->scale.x = curObject->scale.y = curObject->scale.z = 1.0f;
        D_800FE30E_MemoryMatch++;
    }

    D_800FDE40_MemoryMatch = 0;
    D_800FDE46_MemoryMatch[0] = -1;
    D_800FDE46_MemoryMatch[1] = -1;
    D_800FDE42_MemoryMatch[0] = 0;
    D_800FDE42_MemoryMatch[1] = 0;
    func_800F8314_MemoryMatch();
    SetFadeInTypeAndTime(0, 0x10);
}



void func_800F8130_MemoryMatch(omObjData* arg0) {
    f32 f;

    if (D_800FD87A_MemoryMatch == 1) {
        D_800FDE3E_MemoryMatch[0] = func_800F8DF4_MemoryMatch(0x120011);
        D_800FDDD8_MemoryMatch = func_80064EF4(1, 0);
        func_80067480(D_800FDDD8_MemoryMatch, 0, -1);
        func_80067354(D_800FDDD8_MemoryMatch, 0, 160.0f, 120.0f);
        func_80067208(D_800FDDD8_MemoryMatch, 0, D_800FDE3E_MemoryMatch[0], 0);
        func_800674BC(D_800FDDD8_MemoryMatch, 0, 0x140C);
        func_80066DC4(D_800FDDD8_MemoryMatch, 0, 0xA0, 0x78);
        func_8006752C(D_800FDDD8_MemoryMatch, 0, 0xB4);
        D_800FD87A_MemoryMatch = 0;
        D_800FD87C_MemoryMatch = 0;
        return;
    }
    if (D_800FD87C_MemoryMatch < 45) {
        f = 1.0 - (f32)((f32)D_800FD87C_MemoryMatch / 45.0);
        func_8006752C(D_800FDDD8_MemoryMatch, 0, f * 180.0);
    } else if (D_800FD87C_MemoryMatch == 45) {
        func_800674BC(D_800FDDD8_MemoryMatch, 0, 0x8000);
        arg0->func_ptr = NULL;
    } else {
        return;
    }
    D_800FD87C_MemoryMatch++;
}
void func_800F830C_MemoryMatch(void) {
}

void func_800F8314_MemoryMatch(void) {
    Vec3f temp_f0;
    s16 temp_s0;
    s16 phi_v1;
    u16 temp_s3 = func_800F7AFC_MemoryMatch(512);
    u16 i;

    for (i = 0; i < temp_s3; i++) {
        temp_s0 = func_800F7AFC_MemoryMatch(NUM_OF_TILES);

        if (temp_s0 >= NUM_OF_TILES) {
            temp_s0 = 0;
        }

        if (func_800F7AFC_MemoryMatch(0) & 1) {
            phi_v1 = temp_s0 + 1;
        } else {
            phi_v1 = temp_s0 - 1;
        }

        if (phi_v1 >= NUM_OF_TILES) {
            phi_v1 = 0;
        } else if (phi_v1 < 0) {
            phi_v1 = 8;
        }
        
        temp_f0.x = D_800FD7F0_MemoryMatch[phi_v1].x;
        temp_f0.y = D_800FD7F0_MemoryMatch[phi_v1].y;
        temp_f0.z = D_800FD7F0_MemoryMatch[phi_v1].z;
        D_800FD7F0_MemoryMatch[phi_v1].x = D_800FD7F0_MemoryMatch[temp_s0].x;
        D_800FD7F0_MemoryMatch[phi_v1].y = D_800FD7F0_MemoryMatch[temp_s0].y;
        D_800FD7F0_MemoryMatch[phi_v1].z = D_800FD7F0_MemoryMatch[temp_s0].z;
        D_800FD7F0_MemoryMatch[temp_s0].x = temp_f0.x;
        D_800FD7F0_MemoryMatch[temp_s0].y = temp_f0.y;
        D_800FD7F0_MemoryMatch[temp_s0].z = temp_f0.z;
    }
}

// range test folded into sltiu; retail slti+bltz (masked 8)
#ifdef NON_MATCHING
s16 func_800F84A8_MemoryMatch(s16 arg0) {
    u16 i;

    if (arg0 >= 9 || arg0 < 0) {
        return -1;
    }
    for (i = 0; i < 9; i++) {
        if (D_800FE2E8_MemoryMatch[i]->work[2] == 2) {
            return -1;
        }
        if (D_800FE2E8_MemoryMatch[i]->work[2] == 3) {
            return -1;
        }
        if (D_800FE2E8_MemoryMatch[i]->work[2] == 4) {
            return -1;
        }
    }
    if (D_800FE2E8_MemoryMatch[arg0]->work[2] == 0) {
        D_800FE2E8_MemoryMatch[arg0]->work[2] = 2;
        D_800FDE46_MemoryMatch[D_800FDE40_MemoryMatch] = arg0;
        D_800FDE42_MemoryMatch[D_800FDE40_MemoryMatch] = D_800FE2E8_MemoryMatch[arg0]->work[1];
        D_800FDE40_MemoryMatch++;
        PlaySound(0x1C2);
        if (D_800FDE40_MemoryMatch == 2 && D_800FDE42_MemoryMatch[0] == D_800FDE42_MemoryMatch[1]) {
            func_800F8BC0_MemoryMatch(D_800FDE42_MemoryMatch[0]);
            D_800FE30E_MemoryMatch -= 2;
        }
    }
    if (D_800FE2E8_MemoryMatch[arg0]->work[1] == 5 && D_800FE2E8_MemoryMatch[arg0]->work[2] == 1) {
        return -1;
    }
    return D_800FE2E8_MemoryMatch[arg0]->work[1];
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_00_MemoryMatch/CDA50", func_800F84A8_MemoryMatch);
#endif
// retail reloads every global and keeps a 0x18 frame (masked 18)
#ifdef NON_MATCHING
void func_800F8654_MemoryMatch(omObjData* arg0) {
    omObjData* obj;

    if ((&D_800FE2C8_MemoryMatch)[D_800F3FB0[0]->work[0]].unk_04 == -1) {
        if (D_800FDE40_MemoryMatch >= 2 && D_800FDE42_MemoryMatch[0] != D_800FDE42_MemoryMatch[1]
            && D_800FE2E8_MemoryMatch[D_800FDE46_MemoryMatch[0]]->work[2] == 1
            && D_800FE2E8_MemoryMatch[D_800FDE46_MemoryMatch[1]]->work[2] == 1) {
            D_800FE2E8_MemoryMatch[D_800FDE46_MemoryMatch[0]]->work[2] = 3;
            D_800FE2E8_MemoryMatch[D_800FDE46_MemoryMatch[1]]->work[2] = 3;
            D_800FDE40_MemoryMatch = 0;
            D_800FDE46_MemoryMatch[0] = D_800FDE46_MemoryMatch[1] = -1;
            D_800FDE42_MemoryMatch[0] = D_800FDE42_MemoryMatch[1] = 0;
            return;
        }
        if (D_800FDE40_MemoryMatch == 1) {
            obj = D_800FE2E8_MemoryMatch[D_800FDE46_MemoryMatch[0]];
            if (obj->work[1] == 5 && obj->work[2] == 1) {
                obj->work[2] = 3;
                D_800FDE40_MemoryMatch = 0;
                D_800FDE46_MemoryMatch[0] = -1;
                D_800FDE42_MemoryMatch[0] = 0;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_00_MemoryMatch/CDA50", func_800F8654_MemoryMatch);
#endif
void func_800F87DC_MemoryMatch(omObjData* arg0) {
    u16 idx = arg0->work[0];

    arg0->func_ptr = func_800F89A8_MemoryMatch;
    arg0->scale.x = arg0->scale.y = arg0->scale.z = 1.0f;
    switch (idx) {
    case 0:
        arg0->model[0] = LoadFormFile(0x120001, 0xB9);
        break;
    case 1:
        arg0->model[0] = LoadFormFile(0x120002, 0xB9);
        break;
    case 2:
        arg0->model[0] = LoadFormFile(0x120003, 0xB9);
        break;
    case 3:
        arg0->model[0] = LoadFormFile(0x120004, 0xB9);
        break;
    case 4:
        arg0->model[0] = LoadFormFile(0x120005, 0xB9);
        break;
    }
    switch (idx) {
    case 5:
        arg0->model[0] = func_80023FC8(D_800FE2E8_MemoryMatch[0]->model[0]);
        break;
    case 6:
        arg0->model[0] = func_80023FC8(D_800FE2E8_MemoryMatch[1]->model[0]);
        break;
    case 7:
        arg0->model[0] = func_80023FC8(D_800FE2E8_MemoryMatch[2]->model[0]);
        break;
    case 8:
        arg0->model[0] = func_80023FC8(D_800FE2E8_MemoryMatch[3]->model[0]);
        break;
    }
    arg0->trans.x = D_800FD7F0_MemoryMatch[idx].x * D_800FD7E4_MemoryMatch.x;
    arg0->trans.y = D_800FD7F0_MemoryMatch[idx].y * D_800FD7E4_MemoryMatch.y;
    arg0->trans.z = D_800FD7F0_MemoryMatch[idx].z * D_800FD7E4_MemoryMatch.z;
    D_800F2B7C[arg0->model[0]].unk_4C = 0.0f;
    arg0->work[2] = 0;
    arg0->work[3] = 0;
}
// void func_800F87DC_MemoryMatch(omObjData* arg0) {
//     u16 temp_s1 = arg0->work[0];
    
//     arg0->func_ptr = func_800F89A8_MemoryMatch;
//     arg0->scale.x = arg0->scale.y = arg0->scale.z = 1.0f;
//     switch (temp_s1) {
//         case 0:
//             arg0->model[0] = LoadFormFile(0x120001, 0xB9);
//             break;
//         case 1:
//             arg0->model[0] = LoadFormFile(0x120002, 0xB9);
//             break;
//         case 2:
//             arg0->model[0] = LoadFormFile(0x120003, 0xB9);
//             break;
//         case 3:
//             arg0->model[0] = LoadFormFile(0x120004, 0xB9);
//             break;
//         case 4:
//             arg0->model[0] = LoadFormFile(0x120005, 0xB9);
//             break;
//     }

//     switch(temp_s1) {
//         case 5:
//             arg0->model[0] = func_80023FC8(D_800FE2E8_MemoryMatch[0]->model);
//             break;
//         case 6:
//             arg0->model[0] = func_80023FC8(D_800FE2E8_MemoryMatch[1]->model);
//             break;
//         case 7:
//             arg0->model[0] = func_80023FC8(D_800FE2E8_MemoryMatch[2]->model);
//             break;
//         case 8:
//             arg0->model[0] = func_80023FC8(D_800FE2E8_MemoryMatch[3]->model);
//             break;
//     }

//     arg0->trans.x = (D_800FD7F0_MemoryMatch[temp_s1].x * D_800FD7E4_MemoryMatch.x);
//     arg0->trans.y = (D_800FD7F0_MemoryMatch[temp_s1].y * D_800FD7E4_MemoryMatch.y);
//     arg0->trans.z = (D_800FD7F0_MemoryMatch[temp_s1].z * D_800FD7E4_MemoryMatch.z);
//     D_800F2B7C[arg0->model[0]].unk_4C.signed32 = 0; //unsure what this should be
//     arg0->work[2] = 0;
//     arg0->work[3] = 0;
// }

void func_800F89A8_MemoryMatch(omObjData* arg0) {
    switch (arg0->work[2]) {
    case 0:
    case 1:
    case 5:
        break;
    case 2:
        if (arg0->rot.x < 180.0f) {
            arg0->rot.x += 20.0f;
        }
        if (arg0->rot.x >= 180.0f) {
            arg0->rot.x = 180.0f;
            arg0->work[2] = 1;
            if (D_800FDE40_MemoryMatch >= 2) {
                if (D_800FDE42_MemoryMatch[0] == D_800FDE42_MemoryMatch[1]) {
                    D_800FE2E8_MemoryMatch[D_800FDE46_MemoryMatch[0]]->work[2] = 5;
                    D_800FE2E8_MemoryMatch[D_800FDE46_MemoryMatch[1]]->work[2] = 5;
                    func_800FD6A0_MemoryMatch(D_800FE2E8_MemoryMatch[D_800FDE46_MemoryMatch[0]], D_800FE2E8_MemoryMatch[D_800FDE46_MemoryMatch[1]]);
                    func_800F7DC0_MemoryMatch(0x1C4, 9);
                    D_800FDE46_MemoryMatch[0] = D_800FDE46_MemoryMatch[1] = -1;
                    D_800FDE42_MemoryMatch[0] = D_800FDE42_MemoryMatch[1] = 0;
                    D_800FDE40_MemoryMatch = 0;
                } else if (D_800FDE42_MemoryMatch[1] != 5) {
                    func_800F7DC0_MemoryMatch(0x1C7, 9);
                }
            }
        }
        break;
    case 3:
        if (arg0->rot.x < 360.0f) {
            arg0->rot.x += 20.0f;
        }
        if (arg0->rot.x >= 360.0f) {
            arg0->rot.x = 0.0f;
            arg0->work[2] = 0;
        }
        break;
    case 4:
        if (arg0->rot.x < 360.0f) {
            arg0->rot.x += 5.0f;
        }
        if (arg0->rot.x >= 360.0f) {
            arg0->rot.x = 0.0f;
            arg0->work[2] = 0;
        }
        break;
    }
}
void func_800F8BC0_MemoryMatch(s16 arg0) {
    switch (arg0) {
    case 1:
        GwPlayer[D_800FE30C_MemoryMatch].coins_mg += 2;
        break;
    case 2:
        GwPlayer[D_800FE30C_MemoryMatch].coins_mg += 2;
        break;
    case 3:
        GwPlayer[D_800FE30C_MemoryMatch].coins_mg += 2;
        break;
    case 4:
        GwPlayer[D_800FE30C_MemoryMatch].coins_mg += 2;
        break;
    }
}
void func_800F8C38_MemoryMatch(void) {
    tikiThing* temp_a0 = D_800FDE50_MemoryMatch;
    u16 i = 0;
    
    for (i = 0; i < 8; i++) {
        temp_a0->unk_00 = 0;
        temp_a0->unk_02 = 0;
        temp_a0->unk_04 = 0;
        temp_a0->unk_08 = 0;
        temp_a0->unk_0C = temp_a0->unk_10 = temp_a0->unk_14 = 0;
        temp_a0++;
    }
}

void func_800F8C80_MemoryMatch(omObjData* arg0) {
    tikiThing* p = D_800FDE50_MemoryMatch;
    u16 i;
    f32 dx, dz, dy, angle;

    for (i = 0; i < 8; i++, p++) {
        if (p->unk_00 != 0) {
            dx = arg0->trans.x - p->unk_0C;
            dy = arg0->trans.y - p->unk_10;
            dz = arg0->trans.z - p->unk_14;
            if (dx * dx + dz * dz < p->unk_04 * p->unk_04 && dy < p->unk_08) {
                angle = func_800F7B90_MemoryMatch(dx, dz);
                arg0->trans.x = func_800AEAC0(angle) * p->unk_04 + p->unk_0C;
                arg0->trans.z = func_800AEFD0(angle) * p->unk_04 + p->unk_14;
                return;
            }
        }
    }
}
s16 func_800F8D84_MemoryMatch(Vec3f* arg0, Vec2f* arg1) {
    tikiThing* p = D_800FDE50_MemoryMatch;
    u16 i;

    for (i = 0; i < 8; i++, p++) {
        if (p->unk_00 == 0) {
            p->unk_00 = 1;
            p->unk_0C = arg0->x;
            p->unk_10 = arg0->y;
            p->unk_14 = arg0->z;
            p->unk_04 = arg1->x;
            p->unk_08 = arg1->y;
            return i;
        }
    }
    return -1;
}
u16 func_800F8DF4_MemoryMatch(u32 arg0) {
    void* fsData;
    s16 temp_s1;

    fsData = DataRead(arg0);
    temp_s1 = func_800678A4(fsData);
    DataClose(fsData);
    return temp_s1;
}

void func_800F8E38_MemoryMatch(void) {
    unk_MemoryMatch_00* phi_s0;
    u16 i;

    D_800FDE30_MemoryMatch.unk_00 = func_800F8DF4_MemoryMatch(0x12000F);
    D_800FDE30_MemoryMatch.unk_02 = func_800F8DF4_MemoryMatch(0x75);
    D_800FDE30_MemoryMatch.unk_04 = func_800F8DF4_MemoryMatch(0x120013);
    D_800FDE30_MemoryMatch.unk_06 = func_800F8DF4_MemoryMatch(0x120014);
    D_800FDE30_MemoryMatch.unk_08 = func_800F8DF4_MemoryMatch(0x120015);
    D_800FDE30_MemoryMatch.unk_0A = func_800F8DF4_MemoryMatch(0x120016);
    phi_s0 = &D_800FE318_MemoryMatch[0];
    for (i = 0; i < 0x10; i++) {
        phi_s0->unk_04 = func_80064EF4(1, 0);
        func_80067480(phi_s0->unk_04, 0, -1);
        func_800674BC(phi_s0->unk_04, 0, 0x8000);
        func_800672B0(phi_s0->unk_04, 0, 0);
        phi_s0->unk_00 = 0;
        phi_s0->unk_02 = 0;
        phi_s0->unk_06 = 0;
        phi_s0->unk_08 = 0;
        phi_s0->unk_0C = 0;
        phi_s0->unk_10 = phi_s0->unk_12 = phi_s0->unk_14 = phi_s0->unk_16 = 0;
        phi_s0->unk_18 = phi_s0->unk_1A = phi_s0->unk_1C = phi_s0->unk_1E = 0;
        phi_s0++;
    }
}

void func_800F8F58_MemoryMatch(void) {
    unk_MemoryMatch_00* p = D_800FE318_MemoryMatch;
    u16 i;

    for (i = 0; i < 16; i++, p++) {
        if (p->unk_02 != 0 && p->unk_00 != 0) {
            func_80066DC4(p->unk_04, 0, p->unk_08, p->unk_0C);
        }
    }
}
void func_800F8FEC_MemoryMatch(void) {
    GMesCreate(8, 0x2D, 0xA0, 0x20);
    D_800FDE2C_MemoryMatch = 0;
}

u16 func_800F901C_MemoryMatch(void) {
    u16 time = 45 - D_800FDE2C_MemoryMatch / 30;

    func_80079078(time);
    if (D_800FE2C2_MemoryMatch == 1 && D_800FE2C4_MemoryMatch == 0) {
        D_800FDE2C_MemoryMatch++;
    }
    if (time == 0) {
        if (D_800FE2C4_MemoryMatch == 0) {
            func_800790C0();
        }
        return 0;
    }
    return 1;
}
void func_800F90CC_MemoryMatch(void) {
    unk_MemoryMatch_02* p = D_800FDF10_MemoryMatch;
    u16 i;

    for (i = 0; i < 16; i++) {
        p->unk_02 = func_800F94E8_MemoryMatch(0x12000F, 0x289, 8);
        if (p->unk_02 >= 0) {
            p->unk_00 = D_800ECDE0[p->unk_02].unk_00;
            func_800258EC(p->unk_00, 4, 4);
            func_8001E2A8(p->unk_02, 0);
            p++;
        }
    }
}
void func_800F9178_MemoryMatch(void) {
    unk_MemoryMatch_02* p;
    u16 i;
    f32 t;
    f32 x;

    for (i = 0; i < 16; i++) {
        p = &D_800FDF10_MemoryMatch[i];
        if (D_800FE2C2_MemoryMatch != 1) {
            func_800258EC(p->unk_00, 4, 4);
        }
        switch (p->unk_10) {
        case 1:
            t = p->unk_0E / 8.0f;
            p->unk_18 += func_800AEFD0(p->unk_0A) * p->unk_0C;
            p->unk_1C += (f32)(func_800AEAC0(t * 90.0f) * 1.5 * 20.0);
            p->unk_20 += func_800AEAC0(p->unk_0A) * p->unk_0C;
            func_80025798(p->unk_00, p->unk_18, p->unk_1C, p->unk_20);
            func_80025830(p->unk_00, 2.0f, 2.0f, 2.0f);
            if (t > 0.5) {
                func_8001E2F8(p->unk_02, 0xFF);
            } else {
                func_8001E2F8(p->unk_02, 128.0f - t * 128.0f);
            }
            if (p->unk_0E-- <= 0) {
                func_800258EC(p->unk_00, 4, 4);
                p->unk_0A = p->unk_0C = p->unk_0E = p->unk_10 = p->unk_12 = p->unk_14 = 0;
            }
            break;
        case 2:
            p->unk_0A += 20;
            if (p->unk_0A >= 360) {
                p->unk_0A -= 360;
            }
            t = p->unk_0A;
            x = p->unk_18 + func_800AEFD0(t) * 40.0 * 1.5;
            func_80025798(p->unk_00, x, p->unk_1C, p->unk_20 + func_800AEAC0(t) * 40.0 * 1.5);
            func_80025830(p->unk_00, 2.0f, 2.0f, 2.0f);
            func_8001E2F8(p->unk_02, 0xFF);
            if (p->unk_0C-- <= 0) {
                func_800258EC(p->unk_00, 4, 4);
                p->unk_0A = p->unk_0C = p->unk_0E = p->unk_10 = p->unk_12 = p->unk_14 = 0;
            }
            break;
        }
    }
}
void func_800F94E0_MemoryMatch(void) {
}

s16 func_800F94E8_MemoryMatch(s32 arg0, s32 arg1, s32 arg2) {
    s16 temp_s0;

    temp_s0 = ReadImgPackand(arg0, arg1, arg2);
    func_80025930(D_800ECDE0[temp_s0].unk_00, 0x70000000, 0x70000000);
    return temp_s0;
}

void func_800F953C_MemoryMatch(f32 arg0, f32 arg1, f32 arg2) {
    unk_MemoryMatch_02* p;
    u16 angle;
    u16 i;

    if (D_800FE2C2_MemoryMatch == 1) {
        angle = func_800F7AFC_MemoryMatch(360);
        p = D_800FDF10_MemoryMatch;
        for (i = 0; i < 3; i++) {
            func_800258EC(p->unk_00, 4, 0);
            angle += 120;
            if (angle >= 360) {
                angle -= 360;
            }
            p->unk_0A = angle;
            p->unk_0C = 45;
            p->unk_10 = 2;
            p->unk_18 = arg0;
            p->unk_1C = arg1;
            p->unk_20 = arg2;
            func_80025798(p->unk_00, arg0, arg1, arg2);
            p++;
        }
    }
}
void func_800F963C_MemoryMatch(void) {
    omObjData* obj = omAddObj(1, 9, 0x3C, -1, func_800F9C50_MemoryMatch);

    obj->work[0] = (u8)D_800F2BC0;
    D_800F3FB0[D_800F2BC0] = obj;
    D_800F2BC0++;
}
// fabsf/compare scheduling (masked 10)
#ifdef NON_MATCHING
f32 func_800F96A8_MemoryMatch(f32 arg0, f32 arg1) {
    omObjData* obj;
    f32 dx, dz;
    f64 d;
    u16 i;

    for (i = 0; i < 9; i++) {
        obj = D_800FE2E8_MemoryMatch[i];
        dx = fabsf(obj->trans.x - arg0);
        dz = fabsf(obj->trans.z - arg1);
        if (dx < 80.0 && dz < 80.0) {
            return 30.0f;
        }
        if (dx < 90.0 && dz < 90.0) {
            if (dx < 80.0) {
                d = dz;
            } else {
                d = dx;
            }
            return (1.0 - (f32)((d - 80.0) / 10.0)) * 30.0;
        }
    }
    return 0.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_00_MemoryMatch/CDA50", func_800F96A8_MemoryMatch);
#endif
// register allocation (masked 0, raw 47)
#ifdef NON_MATCHING
void func_800F97D0_MemoryMatch(omObjData* arg0) {
    unk_MemoryMatch_03* p = &(&D_800FE2C8_MemoryMatch)[arg0->work[0]];
    omObjData* obj;
    f32 ox, oz, dx, dz, f;
    u16 i;

    p->unk_08 = 0.0f;
    p->unk_04 = -1;
    p->unk_0C = p->unk_10 = p->unk_14 = 0.0f;
    if (arg0->trans.x > 450.0) {
        arg0->trans.x = 450.0f;
    } else if (arg0->trans.x < -450.0) {
        arg0->trans.x = -450.0f;
    }
    if (arg0->trans.z > 400.0) {
        arg0->trans.z = 400.0f;
    } else if (arg0->trans.z < -400.0) {
        arg0->trans.z = -400.0f;
    }
    for (i = 0; i < 9; i++) {
        obj = D_800FE2E8_MemoryMatch[i];
        ox = obj->trans.x;
        oz = obj->trans.z;
        dx = fabsf(ox - arg0->trans.x);
        dz = fabsf(oz - arg0->trans.z);
        if (dx < 120.0 && dz < 120.0) {
            if (dx < dz) {
                f = (dz - 80.0) / 40.0;
                if (oz < arg0->trans.z) {
                    p->unk_0C = (f32)fabs(f - 0.5) * 70.0f;
                } else {
                    p->unk_0C = (f32)-fabs(f - 0.5) * 70.0f;
                }
                p->unk_14 = (1.0 - f) * 36.0;
            } else {
                f = (dx - 80.0) / 40.0;
                if (ox < arg0->trans.x) {
                    p->unk_10 = (f32)-fabs(f - 0.5) * 70.0f;
                } else {
                    p->unk_10 = (f32)fabs(f - 0.5) * 70.0f;
                }
                p->unk_14 = (1.0 - f) * 33.0;
            }
        }
        if (dx < 120.0 && dz < 120.0) {
            p->unk_04 = i;
        }
        if (dx < 80.0 && dz < 80.0) {
            p->unk_08 = 30.0f;
            p->unk_14 = 30.0f;
            p->unk_0C = p->unk_10 = 0.0f;
            return;
        }
        if (dx < 90.0 && dz < 90.0) {
            if (dx < 80.0) {
                p->unk_08 = (1.0 - (f32)((dz - 80.0) / 10.0)) * 30.0;
            } else {
                p->unk_08 = (1.0 - (f32)((dx - 80.0) / 10.0)) * 30.0;
            }
            return;
        }
    }
}
/* trailing literal of func_800F97D0 in retail .rodata (unreferenced by the C) */
const f64 D_800FDBB8_MemoryMatch __attribute__((section(".rodata"))) = 0.0;
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_00_MemoryMatch/CDA50", func_800F97D0_MemoryMatch);
#endif

s16 func_800F9BC8_MemoryMatch(omObjData* arg0) {
    unkGlobalStruct_00* g = arg0->unk_50;
    unk_MemoryMatch_03* p = &(&D_800FE2C8_MemoryMatch)[arg0->work[0]];
    unk_ovl_2D_struct* m = &D_800F2B7C[arg0->model[0]];
    s16 ret;

    if (g->unk_5C == 0x20 || m->unk_0C != -1 || p->unk_08 != arg0->trans.y) {
        ret = 0;
    } else {
        ret = 1;
    }
    return ret;
}
// register allocation (masked 0, raw 2)
#ifdef NON_MATCHING
void func_800F9C50_MemoryMatch(omObjData* arg0) {
    s16 tbl[4][4];
    s16* row;
    unk_MemoryMatch_03* p;
    u16 i;
    u16 idx;
    s32 dir;
    s32 dir2;
    u16 chr;

    tbl[0][0] = 0xF;
    tbl[0][1] = 0x38;
    tbl[1][0] = 0x78;
    tbl[1][1] = 0x78;
    tbl[2][0] = 0x10;
    tbl[2][1] = 0x3C;
    tbl[3][0] = 0x78;
    tbl[3][1] = 0x78;
    for (i = 0; i < 4; i++) {
        if (GwPlayer[i].group == 0) {
            break;
        }
    }
    switch (i) {
    case 0:
        idx = 0;
        break;
    case 1:
        idx = 1;
        break;
    case 2:
        idx = 2;
        break;
    case 3:
        idx = 3;
        break;
    default:
        idx = 0;
        break;
    }
    D_800FE30C_MemoryMatch = idx;
    D_800FE310_MemoryMatch = GwPlayer[D_800FE30C_MemoryMatch].port;
    if (GwPlayer[idx].flags & 1) {
        D_800FE192_MemoryMatch = 1;
    } else {
        D_800FE192_MemoryMatch = 0;
    }
    chr = GwPlayer[idx].character;
    D_800FE312_MemoryMatch = chr;
    dir = D_800C59AC[chr].unk_00;
    dir2 = dir | 0x1C;
    func_80009500();
    func_8000979C(arg0, dir, 0x9E, idx, 0x699, 0x689);
    func_80025930(arg0->model[1], 0x80000000, 0);
    func_80025AD4(arg0->model[1]);
    func_80025B34(arg0->model[1]);
    func_8009EA40(D_800F2B7C[arg0->model[1]].unk7C, 0.0f, 15.0f, 0.0f);
    arg0->func_ptr = func_800FA1E4_MemoryMatch;
    ((unkGlobalStruct_00*)arg0->unk_50)->unk_DC = NULL;
    func_800258EC(arg0->model[1], 0x60, 0x20);
    func_800258EC(arg0->model[1], 0x180, 0);
    arg0->model[3] = LoadFormFile(0x19, 0x2BD);
    arg0->model[4] = LoadFormFile(0x1A, 0x2BD);
    arg0->model[6] = LoadFormFile(0x1B, 0x2BD);
    arg0->model[5] = LoadFormFile(0x1C, 0x2BD);
    arg0->model[7] = LoadFormFile(0x1E, 0x2BD);
    arg0->model[8] = LoadFormFile(0x1D, 0x2BD);
    func_800187D0(arg0, 0, dir, 1, 0);
    func_800187D0(arg0, 1, dir | 1, 1, 0);
    func_800187D0(arg0, 2, dir | 3, 1, 0);
    func_800187D0(arg0, 6, dir | 5, 1, 0x13);
    func_800187D0(arg0, 8, dir | 9, 1, 0x1B);
    func_800187D0(arg0, 0x11, dir | 0x18, 0, 0);
    func_800187D0(arg0, 0x12, dir2, 0, 0);
    func_8001874C(arg0, 0x15, dir | 0x62, 0, 0);
    func_8001874C(arg0, 0x14, dir | 0x5F, 0, 0);
    func_8001874C(arg0, 4, dir | 0x61, 1, 0);
    func_8001874C(arg0, 0x20, dir | 0x67, 0, 0);
    func_8001874C(arg0, 0x21, dir | 0x68, 2, 0);
    func_8001874C(arg0, 0x22, dir | 0x69, 2, 0);
    func_8001874C(arg0, 0x23, dir | 0x2F, 1, 4);
    row = &tbl[0][func_800F7AFC_MemoryMatch(2)];
    func_8001874C(arg0, 0x24, dir | row[0], 1, (u16)row[4]);
    func_8001874C(arg0, 0x25, dir2, 2, 0);
    row = &tbl[0][func_800F7AFC_MemoryMatch(2)];
    func_8001874C(arg0, 0x26, dir | row[8], 1, (u16)row[12]);
    arg0->trans.x = arg0->trans.y = 0.0f;
    arg0->trans.z = 144.0f;
    func_800FAD18_MemoryMatch(arg0->work[0]);
    p = &(&D_800FE2C8_MemoryMatch)[arg0->work[0]];
    switch (GwPlayer[D_800FE30C_MemoryMatch].cpu_difficulty) {
    case 0:
        p->unk_18 = 5;
        break;
    case 1:
        p->unk_18 = 3;
        break;
    case 2:
        p->unk_18 = 1;
        break;
    case 3:
        p->unk_18 = 0;
        break;
    default:
        p->unk_18 = 3;
        break;
    }
    func_800090C4(arg0, 0, 2);
    D_800FD880_MemoryMatch = 0;
    D_800FD882_MemoryMatch = 0;
    D_800FD884_MemoryMatch = 0;
    func_800184BC(arg0, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_00_MemoryMatch/CDA50", func_800F9C50_MemoryMatch);
#endif
void func_800FA1E4_MemoryMatch(omObjData* arg0) {
    unk_MemoryMatch_03* p = &(&D_800FE2C8_MemoryMatch)[arg0->work[0]];

    if (D_800FE2C4_MemoryMatch != 0) {
        ContBtnTrg[D_800FE310_MemoryMatch] &= 0x2000;
    }
    if (D_800FE2C2_MemoryMatch == 1) {
        if (D_800FE192_MemoryMatch != 0) {
            func_800FA400_MemoryMatch(arg0);
        }
        if (D_800FD880_MemoryMatch == 0 && D_800FD882_MemoryMatch == 0) {
            func_80005A28(arg0);
        } else {
            func_800FAB80_MemoryMatch(arg0);
        }
        func_800FAF9C_MemoryMatch(arg0);
        func_800FAEB4_MemoryMatch(arg0);
    } else {
        func_800FAAC4_MemoryMatch(arg0);
    }
    func_800F8C80_MemoryMatch(arg0);
    func_800F8654_MemoryMatch(arg0);
    func_800FB1B8_MemoryMatch(arg0);
    func_800257E4(arg0->model[1], p->unk_0C, 0.0f, p->unk_10);
    if (p->unk_0C != 0.0 || p->unk_10 != 0.0) {
        func_80025798(arg0->model[1], arg0->trans.x, p->unk_08 * 1.1, arg0->trans.z);
    }
    if (p->unk_0C >= 0.0) {
        func_8009EA40(D_800F2B7C[arg0->model[1]].unk7C, 0.0f, 15.0f, 0.0f);
    } else {
        func_8009EA40(D_800F2B7C[arg0->model[1]].unk7C, 0.0f, 0.0f, 0.0f);
    }
}
// rand(100) result vs unk_18 load order (masked 9)
#ifdef NON_MATCHING
void func_800FA400_MemoryMatch(omObjData* arg0) {
    unk_MemoryMatch_03* p = &(&D_800FE2C8_MemoryMatch)[arg0->work[0]];
    omObjData* obj;
    f32 dx, dz, dist, angle, sx, sy;
    s16 i;
    u8 w;
    u16 r;

    ContBtnTrg[D_800FE310_MemoryMatch] = 0;
    ContBtn[D_800FE310_MemoryMatch] = 0;
    ContStkX[D_800FE310_MemoryMatch] = 0;
    ContStkY[D_800FE310_MemoryMatch] = 0;
    if (D_800FD89A_MemoryMatch == 9) {
        for (i = 0; i < 9; i++) {
            if (D_800FE2E8_MemoryMatch[i]->work[2] == 5) {
                D_800FD888_MemoryMatch[i] = -1;
            }
        }
        for (i = 0; i < 9; i++) {
            if (D_800FD89C_MemoryMatch == D_800FD888_MemoryMatch[i] && D_800FE2E8_MemoryMatch[i]->work[2] == 0) {
                break;
            }
        }
        if (i == 9 || D_800FD89C_MemoryMatch == 0) {
            D_800FD89A_MemoryMatch = func_800F7AFC_MemoryMatch(9);
            for (i = 0; i < 9; i++) {
                if (D_800FE2E8_MemoryMatch[D_800FD89A_MemoryMatch]->work[2] == 0
                    && ((D_800FD888_MemoryMatch[D_800FD89A_MemoryMatch] == 9) & (D_800FD888_MemoryMatch[D_800FD89A_MemoryMatch] != 5))) {
                    break;
                }
                if (++D_800FD89A_MemoryMatch >= 9) {
                    D_800FD89A_MemoryMatch = 0;
                }
            }
            if (i == 9) {
                for (i = 0; i < 9; i++) {
                    if (D_800FE2E8_MemoryMatch[i]->work[2] == 0
                        && ((D_800FD888_MemoryMatch[D_800FD89A_MemoryMatch] != -1) & (D_800FD888_MemoryMatch[D_800FD89A_MemoryMatch] != 5))) {
                        break;
                    }
                }
                if (i == 9) {
                    D_800FD89A_MemoryMatch = 9;
                }
                return;
            }
        } else {
            D_800FD89A_MemoryMatch = i;
        }
        D_800FD8A4_MemoryMatch = func_800F7AFC_MemoryMatch(60) + 80.0;
        D_800FD8A0_MemoryMatch = func_800F7AFC_MemoryMatch(3) + 3;
        return;
    }
    w = D_800FE2E8_MemoryMatch[D_800FD89A_MemoryMatch]->work[2];
    if ((w == 1) | (w == 5)) {
        D_800FD89A_MemoryMatch = 9;
        return;
    }
    obj = D_800FE2E8_MemoryMatch[D_800FD89A_MemoryMatch];
    dx = obj->trans.x - arg0->trans.x;
    dz = obj->trans.z - arg0->trans.z;
    dist = sqrtf(dx * dx + dz * dz);
    angle = func_800F7B90_MemoryMatch(dx, dz);
    sx = func_800AEAC0(angle) * 64.0f;
    sy = -(func_800AEFD0(angle) * 64.0f);
    ContStkX[D_800FE310_MemoryMatch] = sx;
    ContStkY[D_800FE310_MemoryMatch] = sy;
    if (dist < D_800FD8A4_MemoryMatch) {
        if (D_800FD89E_MemoryMatch == 0) {
            if (func_800F7AFC_MemoryMatch(20) + 1 < p->unk_18) {
                D_800FD89A_MemoryMatch = 9;
                D_800FD89C_MemoryMatch = 0;
            } else {
                ContBtnTrg[D_800FE310_MemoryMatch] |= 0x8000;
                ContBtn[D_800FE310_MemoryMatch] |= 0x8000;
                D_800FD89E_MemoryMatch++;
            }
        } else if (D_800FD89E_MemoryMatch < D_800FD8A0_MemoryMatch) {
            ContBtn[D_800FE310_MemoryMatch] |= 0x8000;
            D_800FD89E_MemoryMatch++;
        } else if (D_800FD89E_MemoryMatch == D_800FD8A0_MemoryMatch) {
            ContBtnTrg[D_800FE310_MemoryMatch] |= 0x2000;
            ContBtn[D_800FE310_MemoryMatch] |= 0x2000;
            D_800FD89E_MemoryMatch++;
        } else if (D_800FD89E_MemoryMatch < D_800FD8A0_MemoryMatch + 3) {
            D_800FD89E_MemoryMatch++;
        } else {
            for (i = 0; i < 9; i++) {
                if (D_800FE2E8_MemoryMatch[i]->work[2] == 1) {
                    break;
                }
            }
            if (i != 9 || obj->work[1] == 5) {
                D_800FD888_MemoryMatch[D_800FD89A_MemoryMatch] = obj->work[1];
                D_800FD89C_MemoryMatch = 0;
            } else if ((r = func_800F7AFC_MemoryMatch(100), p->unk_18 * 10 < r)) {
                D_800FD888_MemoryMatch[D_800FD89A_MemoryMatch] = D_800FD89C_MemoryMatch = obj->work[1];
            }
            D_800FD89A_MemoryMatch = 9;
            D_800FD89E_MemoryMatch = 0;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_00_MemoryMatch/CDA50", func_800FA400_MemoryMatch);
#endif
void func_800FAAC4_MemoryMatch(omObjData* arg0) {
    if (((unkGlobalStruct_00*) arg0->unk_50)->unk_5C & 0x6324) {
        func_80005A28(arg0);
        return;
    }
    func_800FADDC_MemoryMatch(arg0);
    func_80025798(arg0->model[1], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    if (D_800FE2C2_MemoryMatch == 5) {
        if (D_800FE30E_MemoryMatch < 8) {
            func_800FAD94_MemoryMatch(arg0, 0x24);
        } else {
            func_800FAD94_MemoryMatch(arg0, 0x26);
        }
    } else {
        func_800184BC(arg0, 0);
    }
    func_80017DB0(arg0);
}

// unk_50 load scheduling (masked 3)
#ifdef NON_MATCHING
void func_800FAB80_MemoryMatch(omObjData* arg0) {
    unkGlobalStruct_00* g;

    if (D_800FD884_MemoryMatch != 0) {
        func_80005A28(arg0);
        D_800FD884_MemoryMatch--;
        return;
    }
    g = arg0->unk_50;
    arg0->trans.y = (&D_800FE2C8_MemoryMatch)[arg0->work[0]].unk_08;
    func_80025798(arg0->model[1], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    if (D_800FD880_MemoryMatch != 0) {
        if (D_800FD880_MemoryMatch == 45) {
            func_800F953C_MemoryMatch(arg0->trans.x, arg0->trans.y + 160.0, arg0->trans.z);
            func_80060540(0x15E, 0);
            func_80060F04(g->unk_58, 2, 2, 0x14);
        } else if (D_800FD880_MemoryMatch < 2) {
            D_800FD882_MemoryMatch = 9;
            func_800FAD94_MemoryMatch(arg0, 0x25);
        } else {
            func_800FAD94_MemoryMatch(arg0, 0x23);
        }
        D_800FD880_MemoryMatch--;
    } else if (D_800FD882_MemoryMatch != 0) {
        if (D_800FD882_MemoryMatch < 2) {
            func_800FAD94_MemoryMatch(arg0, 0);
        } else {
            func_800FAD94_MemoryMatch(arg0, 0x25);
        }
        func_80060758(0x15E);
        D_800FD882_MemoryMatch--;
    }
    func_80017DB0(arg0);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_00_MemoryMatch/CDA50", func_800FAB80_MemoryMatch);
#endif
void func_800FAD18_MemoryMatch(u16 arg0) {
    if (arg0 == 0) {
        unk_MemoryMatch_03* p = &D_800FE2C8_MemoryMatch;

        func_8009B770(p, 0, sizeof(unk_MemoryMatch_03));
        p->unk_00 = 0;
        D_800FE2CA_MemoryMatch = 0;
        D_800FE2CC_MemoryMatch = -1;
        D_800FE2D0_MemoryMatch = 0;
        D_800FE2D4_MemoryMatch = 0;
        D_800FE2D8_MemoryMatch = 0;
        D_800FE2DC_MemoryMatch = 0;
        D_800FE2E0_MemoryMatch = 0;
    }
}
void func_800FAD94_MemoryMatch(omObjData* arg0, s16 arg1) {
    if (D_800FE190_MemoryMatch != arg1) {
        func_800184BC(arg0, arg1);
    }
    D_800FE190_MemoryMatch = arg1;
}

void func_800FADDC_MemoryMatch(omObjData* arg0) {
    unkGlobalStruct_00* p = arg0->unk_50;

    p->unk_3C += func_800F7994_MemoryMatch(0.0f, p->unk_3C, 25.0f);
    if (p->unk_3C > 360.0) {
        p->unk_3C -= 360.0;
    } else if (p->unk_3C < 0.0) {
        p->unk_3C += 360.0;
    }
    func_8009ECB0(D_800F2B7C[arg0->model[0]].unk7C, 0.0f, p->unk_3C, 0.0f);
}
void func_800FAEB4_MemoryMatch(omObjData* arg0) {
    D_800FD8A8_MemoryMatch += func_800F7994_MemoryMatch(((unkGlobalStruct_00*)arg0->unk_50)->unk_3C, D_800FD8A8_MemoryMatch, 25.0f);
    if (D_800FD8A8_MemoryMatch > 360.0) {
        D_800FD8A8_MemoryMatch -= 360.0;
    } else if (D_800FD8A8_MemoryMatch < 0.0) {
        D_800FD8A8_MemoryMatch += 360.0;
    }
    func_8009ECB0(D_800F2B7C[arg0->model[0]].unk7C, 0.0f, D_800FD8A8_MemoryMatch, 0.0f);
}
// decomp-permuter
void func_800FAF9C_MemoryMatch(omObjData *arg0)
{
  unkGlobalStruct_00 *g = arg0->unk_50;
  unk_MemoryMatch_03 *p = &(&D_800FE2C8_MemoryMatch)[arg0->work[0]];
  f32 frame;
  if (g->unk_5C == 0x200)
  {
    frame = func_80025E70(arg0->model[0]);
    if (frame == (-1.0f))
    {
      frame = func_80025D18(arg0->model[0]);
    }
    if ((frame >= 27.0f) && (arg0->trans.y == p->unk_08))
    {
      if (func_800F84A8_MemoryMatch(p->unk_04) == 5)
      {
        D_800FD880_MemoryMatch = 45;
      }
      else
      {
        D_800FD882_MemoryMatch = 10;
      }
      D_800FD884_MemoryMatch = 7;
    }
  }
}
// retail keeps 0.0f in f20 and passes it as a1 (masked 11)
#ifdef NON_MATCHING
void func_800FB0A8_MemoryMatch(omObjData* arg0) {
    unk_MemoryMatch_2C* work;

    arg0->func_ptr = func_800FB1B0_MemoryMatch;
    arg0->trans.x = arg0->trans.y = arg0->trans.z = 0.0f;
    arg0->scale.x = arg0->scale.y = arg0->scale.z = 5.0f;
    arg0->model[0] = func_800174C0(0x12000E, 0xDD);
    work = func_80023684(0x2C, 0x7918);
    arg0->unk_50 = work;
    func_8009B770(work, 0, 0x2C);
    work->unk_04 = 1;
    work->unk_05 = 0;
    func_80008FC4(arg0, 20.0f);
    func_80008FB8(arg0, 1.0f);
    func_80009028(D_800F2AF8[0], 0, -550.0f, -500.0f, 550.0f, 500.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_00_MemoryMatch/CDA50", func_800FB0A8_MemoryMatch);
#endif
void func_800FB1B0_MemoryMatch(void) {
}

void func_800FB1B8_MemoryMatch(omObjData* arg0) {
    unk_MemoryMatch_03* p;

    func_800F97D0_MemoryMatch(arg0);
    p = &(&D_800FE2C8_MemoryMatch)[arg0->work[0]];
    if (p->unk_08 > 100.0) {
        p->unk_08 = 100.0f;
    } else if (p->unk_08 < 0.0) {
        p->unk_08 = 0.0f;
    }
    if (p->unk_0C < -60.0) {
        p->unk_0C = -60.0f;
    } else if (p->unk_0C > 60.0) {
        p->unk_0C = 60.0f;
    }
    if (p->unk_10 < -60.0) {
        p->unk_10 = -60.0f;
    } else if (p->unk_10 > 60.0) {
        p->unk_10 = 60.0f;
    }
    func_80009028(D_800F2AF8[0], *(s32*)&p->unk_08, -550.0f, -500.0f, 550.0f, 500.0f);
}
