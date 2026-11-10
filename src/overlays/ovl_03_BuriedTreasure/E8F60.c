#include "common.h"
#include "BuriedTreasure.h"

#define U32_MAX 0xFFFFFFFF

s16 D_800FBA70_BuriedTreasure = 0;
s16 D_800FBA72_BuriedTreasure = 60;
s16 D_800FBA74_BuriedTreasure[4] = { 0, 1, 2, 3 };
unkStructSize6 D_800FBA7C_BuriedTreasure[4] = {
    { -120, -128, -200 },
    { 168, -88, -200 },
    { -168, 88, -200 },
    { 120, 128, -200 },
};
f32 D_800FBA94_BuriedTreasure[4] = { 0.0f, 270.0f, 90.0f, 180.0f };

void func_800F65E0_BuriedTreasure(void) {
    u8 temp_s0;
    unk_Struct00* temp_s0_2;
    omObjData* temp_s1;
    s16 i;

    func_80029090(0x32);
    func_8001DE70(0x20);
    omInitObjMan(0x32, 0);
    func_80060088();

    temp_s1 = omAddObj(0x7FDA, 0, 0, -1, omOutView);
    omSetStatBit(temp_s1, 0xA0);
    func_800178A0(1);

    temp_s0 = func_800178E8();
    func_80017660(temp_s0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(temp_s0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 5.0f, 80.0f, 4000.0f);

    D_800F2BC0 = 0;
    D_800FC020_BuriedTreasure = 0;
    D_800FC022_BuriedTreasure = 0x5A;
    D_800FC026_BuriedTreasure = 0;
    D_800FC024_BuriedTreasure = 1;
    D_800FC028_BuriedTreasure = 0x708;
    D_800FC02A_BuriedTreasure = _CheckFlag(0x2B);

    for (i = 0; i < ARRAY_COUNT(D_800FC188_BuriedTreasure); i++) {
        D_800FC188_BuriedTreasure[i] = NULL;
    }

    D_800FC02C_BuriedTreasure = 0;
    D_800FC034_BuriedTreasure = -1;
    D_800FC140_BuriedTreasure = 0;

    for (i = 0; i < ARRAY_COUNT(D_800FC100_BuriedTreasure); i++) {
        D_800FC100_BuriedTreasure[i] = 0;
    }

    func_800F8760_BuriedTreasure();
    omOutView(temp_s1);

    temp_s0_2 = D_800C3110;
    D_800FC5F0_BuriedTreasure = func_800AEAC0(temp_s0_2->unk_40 / 2.0) / func_800AEFD0(temp_s0_2->unk_40 / 2.0);

    guMtxL2F(D_800FC0C0_BuriedTreasure, &temp_s0_2->unk_138);
    guMtxL2F(D_800FC148_BuriedTreasure, &temp_s0_2->unk_138);

    func_800F8978_BuriedTreasure(D_800FC148_BuriedTreasure);
    func_800F9990_BuriedTreasure();

    D_800FC144_BuriedTreasure = omAddObj(0xA, 0, 0, -1, &func_800F692C_BuriedTreasure);

    for (i = 0; i < 4; i++) {
        D_800F3FB0[D_800F2BC0++] = omAddObj(3, 1, 2, -1, &func_800F6EC4_BuriedTreasure);
    }

    D_800FC030_BuriedTreasure = omAddObj(0, 0, 0, -1, &func_800F6DCC_BuriedTreasure);
    func_800F9F90_BuriedTreasure();
}

void func_800F692C_BuriedTreasure(omObjData* arg0) {
    arg0->func_ptr = &func_800F6958_BuriedTreasure;
    SetFadeInTypeAndTime(0, 16);
}

void func_800F6958_BuriedTreasure(void) {
    switch (D_800FC020_BuriedTreasure) {
        case 0:
            D_800FC022_BuriedTreasure--;
            if (D_800FC022_BuriedTreasure == 0) {
                D_800FC020_BuriedTreasure++;
                D_800FC022_BuriedTreasure = 60;
                GMesCreate(0);
            }
            if (D_800FC022_BuriedTreasure == 24) {
                func_80060128(0x1D);
            }
            break;
        case 1:
            D_800FC022_BuriedTreasure--;
            if (D_800FC022_BuriedTreasure == 0) {
                D_800FC020_BuriedTreasure++;
                D_800FC024_BuriedTreasure = 0;
            }
            break;
        case 2:
            if (D_800FC026_BuriedTreasure == 0 && D_800FC5EC_BuriedTreasure >= 0) {
                D_800FC026_BuriedTreasure = 1;
                D_800FC024_BuriedTreasure = 1;
                D_800FC034_BuriedTreasure = D_800FC5EC_BuriedTreasure;
            }
            if (D_800FC026_BuriedTreasure == 0 && D_800FC028_BuriedTreasure != 0) {
                D_800FC028_BuriedTreasure--;
            }
            if ((D_800FC028_BuriedTreasure == 0 || D_800FC026_BuriedTreasure != 0) && (D_800FC034_BuriedTreasure < 0 || D_800FC5C0_BuriedTreasure[0].unk_0A == 0)) {
                D_800FC026_BuriedTreasure++;
                D_800FC024_BuriedTreasure = 1;
                if (D_800FC02A_BuriedTreasure == 0) {
                    D_800FC020_BuriedTreasure++;
                    if (D_800FC034_BuriedTreasure < 0) {
                        GMesCreate(0x10);
                    } else {
                        GMesCreate(2);
                    }
                } else {
                    D_800FC020_BuriedTreasure = 6;
                    GMesCreate(2);
                }
                func_800601D4(0x28);
            }
            break;
        case 3:
            if (GMesStatAllGet() == 2) {
                D_800FC020_BuriedTreasure++;
                if (D_800FC034_BuriedTreasure >= 0) {
                    func_80060128(0x32);
                    D_800FC022_BuriedTreasure = 18;
                } else {
                    func_80060128(0x34);
                    D_800FC022_BuriedTreasure = 21;
                }
            }
            break;
        case 4:
            D_800FC022_BuriedTreasure--;
            if (D_800FC022_BuriedTreasure == 0) {
                D_800FC020_BuriedTreasure++;
                if (D_800FC034_BuriedTreasure >= 0) {
                    GMesCreate(4, GwPlayer[D_800FC034_BuriedTreasure].character);
                    D_800FC022_BuriedTreasure = 84;
                } else {
                    GMesCreate(0x11);
                    D_800FC022_BuriedTreasure = 77;
                }
            }
            break;
        case 5:
            if (D_800FC022_BuriedTreasure != 0) {
                D_800FC022_BuriedTreasure--;
            }
            if (D_800FBA72_BuriedTreasure != 0) {
                D_800FBA72_BuriedTreasure--;
            }
            if (GMesWait() == 0) {
                D_800FBA70_BuriedTreasure = 1;
            }
            if (D_800FC022_BuriedTreasure == 0 || (D_800FBA70_BuriedTreasure != 0 && D_800FBA72_BuriedTreasure == 0)) {
                D_800FC020_BuriedTreasure = -1;
                D_800FC026_BuriedTreasure = -1;
                if (D_800FC02A_BuriedTreasure != 0) {
                    func_80060398(0x28);
                }
                func_800726AC(0, 0x14);
            }
            break;
        case 6:
            if (GMesStatAllGet() == 2) {
                D_800FC020_BuriedTreasure = 5;
                D_800FC022_BuriedTreasure = 60;
                D_800FBA72_BuriedTreasure = 0;
            }
            break;
    }

    func_800F9E10_BuriedTreasure();

    if (D_800F5144 != 0) {
        D_800FC026_BuriedTreasure = -1;
    }

    func_800F6D6C_BuriedTreasure();
}

void func_800F6D6C_BuriedTreasure(void) {
    if (D_800FC026_BuriedTreasure < 0 && func_80072718() == 0) {
        func_800F8894_BuriedTreasure();
        HuMemDirectFree(D_800FC5E8_BuriedTreasure);
        func_800FB9E8_BuriedTreasure();
        func_80060198();
        omOvlReturnEx(1);
    }
}

void func_800F6DCC_BuriedTreasure(omObjData* arg0) {
    arg0->work[0] = GMesCreate(8, D_800FC028_BuriedTreasure / 30, 160, 24);
    arg0->func_ptr = &func_800F6E44_BuriedTreasure;
}

void func_800F6E44_BuriedTreasure(omObjData* arg0) {
    func_80079078((D_800FC028_BuriedTreasure + 29) / 30);
    if (D_800FC028_BuriedTreasure == 0 || D_800FC026_BuriedTreasure == 2) {
        arg0->func_ptr = NULL;
        func_800790C0();
    }
}

void func_800F6EC4_BuriedTreasure(omObjData* arg0) {
    unkGlobalStruct_00* temp_s1;
    s32 temp_s2;
    s16 temp_v1;

    temp_v1 = GwPlayer[D_800FBA74_BuriedTreasure[D_800FC02C_BuriedTreasure]].character;
    temp_s2 = D_800C59AC[temp_v1].unk_00;

    arg0->model[0] = LoadFormFile(temp_s2 | D_800C59AC[temp_v1].unk_04, 0x69D);
    arg0->func_ptr = &func_800F7164_BuriedTreasure;
    arg0->trans.x = D_800FBA7C_BuriedTreasure[D_800FC02C_BuriedTreasure].unk_00;
    arg0->trans.y = D_800FBA7C_BuriedTreasure[D_800FC02C_BuriedTreasure].unk_02;
    arg0->trans.z = D_800FBA7C_BuriedTreasure[D_800FC02C_BuriedTreasure].unk_04;
    arg0->rot.x = 90.0f;
    arg0->rot.z = D_800FBA94_BuriedTreasure[D_800FC02C_BuriedTreasure];
    arg0->scale.z = 0.14f;
    arg0->scale.y = 0.14f;
    arg0->scale.x = 0.14f;

    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_800257E4(arg0->model[0], arg0->rot.x, arg0->rot.y, arg0->rot.z);
    func_80025830(arg0->model[0], arg0->scale.x, arg0->scale.y, arg0->scale.z);

    arg0->unk_50 = func_80023684(sizeof(unkGlobalStruct_00), 31000);
    func_8009B770(arg0->unk_50, 0, sizeof(unkGlobalStruct_00));

    temp_s1 = arg0->unk_50;
    temp_s1->unk_3C = arg0->rot.z + 180.0f;

    temp_s1->unk_D8 = func_80023684(arg0->mtncnt * sizeof(unkGlobalStruct_00), 31000);
    func_8009B770(temp_s1->unk_D8, 0, arg0->mtncnt * sizeof(unkGlobalStruct_00));

    temp_s1->unk_50 = 0;
    temp_s1->unk_52 = 0;
    temp_s1->unk_56 = GwPlayer[D_800FC02C_BuriedTreasure].port;
    temp_s1->unk_C0 = 65535;

    func_8001874C(arg0, 0, temp_s2 | 0x40, 1, 0);
    func_8001874C(arg0, 1, temp_s2 | 0x17, 1, 0x13);

    func_800F87A8_BuriedTreasure(arg0)->unk_40 = D_800FC02C_BuriedTreasure++;
}

void func_800F7164_BuriedTreasure(omObjData* arg0) {
    unkGlobalStruct_00* temp_s1;
    unkStructSize0x5C* temp_v0;
    Vec3f sp18;
    f32 temp_f20_2;
    f32 temp_f24;
    f32 var_f20;
    f32 var_f22;
    f32 var_f4;
    u32 temp_v0_4;
    s16 sp28;
    s16 temp_v0_6;
    s16 var_s4;
    s16 var_s5;
    u16 temp_v1_2;
    u16 var_s0;
    s8 temp_s0;

    temp_s1 = arg0->unk_50;
    temp_v0 = func_800F8914_BuriedTreasure(arg0);

    if (temp_v0->unk_00 >= 0) {
        temp_v0->unk_00 |= 0x80C0;
        temp_v0->unk_02 = 1;
        temp_v0->unk_06 = 14;
        temp_v0->unk_04 = 14;
        temp_v0->unk_0C = D_800F2B7C[arg0->model[0]].unk_24;
        temp_v0->unk_10 = D_800F2B7C[arg0->model[0]].unk_28;
        temp_v0->unk_14 = D_800F2B7C[arg0->model[0]].unk_2C;
        temp_v0->unk_3C = 64;
        temp_v0->unk_3E = arg0->rot.z + 180.0f;
        temp_v0->unk_44 = 0;
        temp_v0->unk_46 = 0;
        temp_v0->unk_48 = 0;
        temp_v0->unk_4C = 0;
        temp_v0->unk_4E = 0;
        temp_v0->unk_50 = 2;
        temp_v0->unk_54 = 0;

        D_800F2B7C[arg0->model[0]].unk_20 &= ~4;
    }

    func_800184BC(arg0, 0);

    var_f20 = temp_s1->unk_3C;
    temp_s0 = temp_s1->unk_56;

    func_80017A60(arg0);

    temp_v0->unk_18 = temp_v0->unk_0C;
    temp_v0->unk_1C = temp_v0->unk_10;

    if (D_800FC024_BuriedTreasure == 0) {
        if (!(GwPlayer[temp_v0->unk_40].flags & 1)) {
            temp_v0_4 = func_80009C90(arg0, ContStkX[temp_s0], ContStkY[temp_s0]);
            var_s4 = temp_v0_4 >> 16;
            var_s5 = temp_v0_4;
            var_s0 = ContBtn[temp_s0] & ~temp_v0->unk_56;
            temp_v0->unk_56 = ContBtn[temp_s0];
        } else {
            var_s4 = var_s5 = 32;
            var_s0 = func_800F85B4_BuriedTreasure(arg0);
        }
    } else {
        if (temp_v0->unk_08 == 0) {
            var_s4 = var_s5 = 32;
            var_s0 = !(temp_v0->unk_3C & 3) << 15;
        } else {
            var_s4 = var_s5 = 0;
            var_s0 = 0;
        }
    }

    if (temp_v0->unk_54 != 0) {
        temp_v0->unk_54--;
    }

    if (var_s0 & 0x8000 && temp_v0->unk_4C == 0) {
        temp_v0->unk_4C = 8;
    }

    temp_s1->unk_40 = (sqrtf(SQ(var_s4) + SQ(var_s5))) / 6.0;
    if (temp_s1->unk_40 > 16.0) {
        temp_s1->unk_40 = 16.0f;
    }

    if (temp_v0->unk_02 & 2) {
        temp_s1->unk_40 *= 1.5;
    }

    if (temp_v0->unk_4C == 0) {
        D_800F2B7C[arg0->model[0]].unk_4C = temp_s1->unk_40 / 8.0;
    } else {
        if (temp_v0->unk_02 & 2) {
            D_800F2B7C[arg0->model[0]].unk_4C = 6.0f;
        } else {
            D_800F2B7C[arg0->model[0]].unk_4C = 2.0f;
        }
        temp_v0->unk_4C--;
    }

    if (temp_s1->unk_40 != 0.0) {
        if (!(GwPlayer[temp_v0->unk_40].flags & 1) && temp_v0->unk_08 != 0) {
            var_f22 = func_800B0CD8(var_s4, -var_s5) + 180.0;
        } else {
            var_f22 = temp_v0->unk_3E;
        }

        if (var_f22 >= 360.0) {
            var_f22 -= 360.0;
        }

        if (var_f22 != var_f20) {
            if ((var_f22 - var_f20 < -180.0f && var_f22 - var_f20 < 0.0f) || (var_f22 - var_f20 < 180.0f && var_f22 - var_f20 > 0.0f)) {
                var_f20 += 20.0f;
                if ((var_f22 - var_f20 > -180.0f && var_f22 - var_f20 < 0.0f) || (var_f22 - var_f20 > 180.0f && var_f22 - var_f20 > 0.0f)) {
                    var_f20 = var_f22;
                }
                if (360.0 < var_f20) {
                    var_f20 -= 360.0;
                }
            } else {
                var_f20 -= 20.0f;
                if ((var_f22 - var_f20 < -180.0f && var_f22 - var_f20 < 0.0f) || (var_f22 - var_f20 < 180.0f && var_f22 - var_f20 > 0.0f)) {
                    var_f20 = var_f22;
                }
                if (var_f20 < 0.0) {
                    var_f20 += 360.0;
                }
            }
        }

        temp_s1->unk_3C = var_f20;
        arg0->rot.z = var_f20 - 180.0;
        temp_v0->unk_0C -= func_800AEAC0(var_f22) * temp_s1->unk_40 / 10.0;
        temp_v0->unk_10 -= func_800AEFD0(var_f22) * temp_s1->unk_40 / 10.0;
    }

    if (var_s0 & 0x8000) {
        temp_f20_2 = temp_v0->unk_0C - temp_v0->unk_18;
        temp_f24 = temp_v0->unk_10 - temp_v0->unk_1C;

        var_f4 = sqrtf(SQ(temp_f20_2) + SQ(temp_f24));
        if (var_f4 != 0.0) {
            temp_f20_2 /= var_f4;
            temp_f24 /= var_f4;

            if (temp_v0->unk_02 & 2) {
                var_f22 = 2.0f;
            } else {
                var_f22 = 1.0f;
            }

            temp_v0_6 = func_800F92D4_BuriedTreasure(temp_f20_2 * var_f22 + temp_v0->unk_18, temp_f24 * var_f22 + temp_v0->unk_1C, temp_v0->unk_50, &temp_v0->unk_5A, &sp28);
            if (temp_v0_6 != 0) {
                if (temp_v0->unk_54 == 0 && D_800FC024_BuriedTreasure == 0) {
                    func_80060F04(temp_v0->unk_40, 5, 0, 5);
                    temp_v0->unk_54 = 16;
                }

                sp28 = -1;
                if (temp_v0->unk_02 & 2) {
                    sp28 = func_80060540(0x1DF, temp_v0->unk_40);
                } else if (temp_v0_6 == 1) {
                    sp28 = func_80060540(0x1DD, temp_v0->unk_40);
                } else {
                    sp28 = func_80060540(0x1DE, temp_v0->unk_40);
                }

                if (sp28 >= 0) {
                    func_80060440(sp28, func_800F8940_BuriedTreasure() * 600 / 65536 - 300);
                }

                temp_v1_2 = ((s16) temp_v0->unk_0C + 160) / 80 + ((s16) temp_v0->unk_10 + 120) / 60 * 4;
                if (temp_v1_2 < ARRAY_COUNT(D_800FC100_BuriedTreasure)) {
                    D_800FC100_BuriedTreasure[(s16) temp_v1_2] += sp28;
                }

                temp_v0->unk_2C = arg0->rot.z + 180.0;
                func_800F9C40_BuriedTreasure(1, temp_v0->unk_0C, temp_v0->unk_10, temp_v0->unk_0A);
            }
        }
    }

    if (temp_v0->unk_08 != 0) {
        func_800F8D1C_BuriedTreasure(temp_v0);
        func_800F9260_BuriedTreasure(&temp_v0->unk_0C, &temp_v0->unk_10, temp_v0->unk_04 - 4);
        func_800F8C84_BuriedTreasure(0, &temp_v0->unk_0C, &temp_v0->unk_10, &temp_v0->unk_14);
    } else {
        temp_v0->unk_3C--;
        if (temp_v0->unk_3C == 0) {
            temp_v0->unk_08++;
        }
    }

    func_800F8BB8_BuriedTreasure(temp_v0->unk_0C, temp_v0->unk_10, temp_v0->unk_14, &sp18);
    arg0->trans.x = sp18.x;
    arg0->trans.y = sp18.y;
    arg0->trans.z = sp18.z;

    if (temp_v0->unk_4E != 0) {
        D_800F2B7C[arg0->model[0]].unk_20 ^= 4;

        temp_v0->unk_4E--;
        if (temp_v0->unk_4E == 0) {
            temp_v0->unk_02 &= 0xFFFD;
            D_800F2B7C[arg0->model[0]].unk_20 &= ~4;
            temp_v0->unk_50 = 2;
        }

        if (D_800FC024_BuriedTreasure == 0 && !(temp_v0->unk_4E & 1)) {
            func_800F9C40_BuriedTreasure(4,
                (func_800F8940_BuriedTreasure() * 16 >> 16) + temp_v0->unk_0C - 8.0f,
                (func_800F8940_BuriedTreasure() * 16 >> 16) + temp_v0->unk_10 - 8.0f, 0);
        }
    }

    func_80017DB0(arg0);
}

void func_800F7D50_BuriedTreasure(s16 arg0) {
    if (D_800FC1C0_BuriedTreasure[arg0].unk_00 >= 0) {
        D_800FC1C0_BuriedTreasure[arg0].unk_00 |= 0x8000;
        D_800FC1C0_BuriedTreasure[arg0].unk_10 = 60;
        func_80067208(D_800FC1C0_BuriedTreasure[arg0].unk_04, 0, D_800FC198_BuriedTreasure[0], 0);
        func_800672B0(D_800FC1C0_BuriedTreasure[arg0].unk_04, 0, 0);
        func_800671DC(D_800FC1C0_BuriedTreasure[arg0].unk_04, 0, D_800FC1C0_BuriedTreasure[arg0].unk_06);
    } else if (--D_800FC1C0_BuriedTreasure[arg0].unk_10 == 0) {
        func_800F9DCC_BuriedTreasure(arg0);
    }
}

void func_800F7E48_BuriedTreasure(s16 arg0) {
    unkStructSize0x5C* temp_s1;
    u8 temp_a2;
    u8 temp_a3;
    u8 temp_a1;

    if (D_800FC1C0_BuriedTreasure[arg0].unk_00 >= 0) {
        D_800FC1C0_BuriedTreasure[arg0].unk_00 |= 0x8000;
        D_800FC1C0_BuriedTreasure[arg0].unk_10 = 0;

        func_80067208(D_800FC1C0_BuriedTreasure[arg0].unk_04, 0, D_800FC198_BuriedTreasure[4], 0);
        func_800672B0(D_800FC1C0_BuriedTreasure[arg0].unk_04, 0, 0);
        func_800671DC(D_800FC1C0_BuriedTreasure[arg0].unk_04, 0, 0);

        temp_s1 = D_800FC188_BuriedTreasure[D_800FC1C0_BuriedTreasure[arg0].unk_06];
        temp_a2 = (f32) ((temp_s1->unk_5A & 0xF800) >> 8) * 0.75;
        temp_a3 = (f32) ((temp_s1->unk_5A & 0x7C0) >> 3) * 0.75;
        temp_a1 = (f32) ((temp_s1->unk_5A & 0x3E) << 2) * 0.75;

        func_80067558(D_800FC1C0_BuriedTreasure[arg0].unk_04, 0, temp_a2, temp_a3, temp_a1, 256);
        func_800673B0(D_800FC1C0_BuriedTreasure[arg0].unk_04, 0, temp_s1->unk_2C);
        func_80067384(D_800FC1C0_BuriedTreasure[arg0].unk_04, 0, 0x9000);

        if (temp_s1->unk_02 & 2) {
            func_80067354(D_800FC1C0_BuriedTreasure[arg0].unk_04, 0, 1.5f, 1.5f);
        }
    } else if (++D_800FC1C0_BuriedTreasure[arg0].unk_10 >= 16) {
        func_800F9DCC_BuriedTreasure(arg0);
    } else {
        func_800671DC(D_800FC1C0_BuriedTreasure[arg0].unk_04, 0, D_800FC1C0_BuriedTreasure[arg0].unk_10);
    }
}

void func_800F815C_BuriedTreasure(s16 arg0) {
    if (D_800FC1C0_BuriedTreasure[arg0].unk_00 >= 0) {
        D_800FC1C0_BuriedTreasure[arg0].unk_00 |= 0x8000;
        func_80067208(D_800FC1C0_BuriedTreasure[arg0].unk_04, 0, D_800FC198_BuriedTreasure[5], 0);
        func_800672B0(D_800FC1C0_BuriedTreasure[arg0].unk_04, 0, 1);
        func_80067354(D_800FC1C0_BuriedTreasure[arg0].unk_04, 0, 0.2f, 0.2f);
        func_80067284(D_800FC1C0_BuriedTreasure[arg0].unk_04, 0, 2.0f);
        func_80067384(D_800FC1C0_BuriedTreasure[arg0].unk_04, 0, 0x9000);
    } else if (func_80067328(D_800FC1C0_BuriedTreasure[arg0].unk_04, 0) & 2) {
        func_800F9DCC_BuriedTreasure(arg0);
    }
}

s16 func_800F826C_BuriedTreasure(void) {
    s16 sp10[ARRAY_COUNT(D_800FC100_BuriedTreasure)];
    s16 var_s0 = 0;
    u32 var_a1 = U32_MAX;
    s16 i;

    for (i = 0; i < ARRAY_COUNT(D_800FC100_BuriedTreasure); i++) {
        if (D_800FC100_BuriedTreasure[i] < var_a1) {
            var_s0 = 0;
            var_a1 = D_800FC100_BuriedTreasure[i];
        }
        if (D_800FC100_BuriedTreasure[i] == var_a1) {
            sp10[var_s0++] = i;
        }
    }

    return sp10[func_800F8940_BuriedTreasure() * var_s0 >> 16];
}

s16 func_800F8334_BuriedTreasure(unkStructSize0x5C* arg0) {
    unkStructSize0x28* temp_s1;
    s16 var_s5 = 0;
    s16 temp_s0_2;
    s16 temp_s1_2;
    s16 temp_s0;
    s16 i;

    if (!(arg0->unk_02 & 4)) {
        for (i = 0; i < ARRAY_COUNT(D_800FC5C0_BuriedTreasure); i++) {
            temp_s1 = &D_800FC5C0_BuriedTreasure[i];
            temp_s0 = temp_s1->unk_12;
            if ((func_800F8940_BuriedTreasure() & 0xFF) < temp_s0 * 28 + GwPlayer[arg0->unk_40].cpu_difficulty * 8) {
                arg0->unk_02 |= 4;
                arg0->unk_44 = temp_s1->unk_0C - 160;
                arg0->unk_46 = temp_s1->unk_0E - 120;
                arg0->unk_4A = i;
                break;
            }
        }
        if (i == ARRAY_COUNT(D_800FC5C0_BuriedTreasure)) {
            i = func_800F826C_BuriedTreasure();
            arg0->unk_44 = (func_800F8940_BuriedTreasure() * 80 >> 16) + (i % 4) * 80 - 160;
            arg0->unk_46 = (func_800F8940_BuriedTreasure() * 60 >> 16) + (i / 4) * 60 - 120;
        }
    } else {
        temp_s1 = &D_800FC5C0_BuriedTreasure[arg0->unk_4A];
        if (temp_s1->unk_12 == 0) {
            arg0->unk_02 &= 0xFFFB;
            arg0->unk_44 = (func_800F8940_BuriedTreasure() * 288 >> 16) - 144;
            arg0->unk_46 = (func_800F8940_BuriedTreasure() * 208 >> 16) - 104;
        } else {
            temp_s0_2 = temp_s1->unk_0C - 160;
            temp_s1_2 = temp_s1->unk_0E - 120;
            arg0->unk_44 = temp_s0_2 + (func_800F8940_BuriedTreasure() * 32 >> 16) - 16;
            arg0->unk_46 = temp_s1_2 + (func_800F8940_BuriedTreasure() * 32 >> 16) - 16;
            var_s5 = 1;
        }
    }

    return var_s5;
}

s32 func_800F85B4_BuriedTreasure(omObjData* arg0) {
    unkStructSize0x5C* temp_v0;
    f32 temp_f0;
    f32 temp_f12;
    s32 temp_f2;
    u16 var_s1;

    var_s1 = 0;
    temp_v0 = func_800F8914_BuriedTreasure(arg0);

    temp_f12 = SQ(temp_v0->unk_44 - temp_v0->unk_0C) + SQ(temp_v0->unk_46 - temp_v0->unk_10);
    temp_f0 = sqrtf(temp_f12);

    if (temp_v0->unk_48 != 0) {
        temp_v0->unk_48--;
    }

    if (temp_f0 < 4.0 || temp_v0->unk_48 == 0) {
        if (func_800F8334_BuriedTreasure(temp_v0) == 0) {
            temp_v0->unk_48 = (func_800F8940_BuriedTreasure() & 63) + 64;
        } else {
            temp_v0->unk_48 = (func_800F8940_BuriedTreasure() & 7) + 8;
        }
    }

    temp_f2 = func_800B0CD8(temp_v0->unk_44 - temp_v0->unk_0C, temp_v0->unk_46 - temp_v0->unk_10);

    temp_v0->unk_3E = temp_f2 + 180;
    if (temp_v0->unk_3E < 0) {
        temp_v0->unk_3E += 360;
    }

    if ((func_800F8940_BuriedTreasure() & 0xFF) < GwPlayer[temp_v0->unk_40].cpu_difficulty * 8 + 56) {
        var_s1 |= 0x8000;
    }

    return var_s1;
}
