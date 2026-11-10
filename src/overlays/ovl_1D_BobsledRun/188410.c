#include "BobsledRun.h"

s8 D_800FF2A0_BobsledRun = -1;
s8 D_800FF2A1_BobsledRun = -1;
f32 D_800FF2A4_BobsledRun = 350.0f;
BRTeam D_800FF2A8_BobsledRun[2] = {
    { 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -60.0f, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, -1, { -1, -1 }, { -1, -1 },
      { -1, -1, -1, -1, -1, -1, -1, -1, -1, 0 }, 0, 0, { 0 } },
    { 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -60.0f, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, -1, { -1, -1 }, { -1, -1 },
      { -1, -1, -1, -1, -1, -1, -1, -1, -1, 0 }, 0, 0, { 0 } },
};
f32 D_800FF338_BobsledRun = 0.0f;
f32 D_800FF33C_BobsledRun = 0.0f;
f32 D_800FF340_BobsledRun[2] = { 0.0f, 0.0f };
s32 D_800FF348_BobsledRun = 0;
s16 D_800FF34C_BobsledRun = 0;
s32 D_800FF350_BobsledRun = -1;
s32 D_800FF354_BobsledRun = -1;
f32 D_800FF358_BobsledRun[6] = { 0.0f, 0.0f, 0.0f, 0.25f, 0.67f, 0.8f };
f32 D_800FF370_BobsledRun[6] = { 1.7f, 0.05f, 0.3f, 0.72f, 1.2f, 1.2f };
f32 D_800FF388_BobsledRun[2] = { -870.0f, -3520.0f };
f32 D_800FF390_BobsledRun[2] = { -5340.0f, -6380.0f };
u32 D_800FF398_BobsledRun = 0;
s32 D_800FF39C_BobsledRun = 0x744;
s32 D_800FF3A0_BobsledRun = 0;
s32 D_800FF3A4_BobsledRun = 0;
s32 D_800FF3A8_BobsledRun = 0;
s32 D_800FF3AC_BobsledRun = 0;
s32 D_800FF3B0_BobsledRun = 0;
Vec3f D_800FF3B4_BobsledRun[44] = {
    { 2998.0f, 9172.0f, 7394.0f }, { 3567.0f, 8770.0f, 9656.0f }, { 5815.0f, 8261.0f, 10914.0f }, { 8110.0f, 7748.0f, 9750.0f },
    { 8736.0f, 7300.0f, 6364.0f }, { 8560.0f, 6316.0f, -4123.0f }, { 7028.0f, 5965.0f, -6312.0f }, { 3444.0f, 5131.0f, -6894.0f },
    { 1036.0f, 4604.0f, -6808.0f }, { -1706.0f, 3628.0f, -6533.0f }, { -2450.0f, 3550.0f, -6300.0f }, { -3523.0f, 3160.0f, -5406.0f },
    { -3638.0f, 2551.0f, -1897.0f }, { 302.0f, 1799.0f, 2747.0f }, { 1623.0f, 1450.0f, 4691.0f }, { 2232.0f, 1250.0f, 6670.0f },
    { 1770.0f, 995.0f, 8561.0f }, { 167.0f, 630.0f, 9419.0f }, { -2156.0f, 140.0f, 8776.0f }, { -3056.0f, -579.0f, 4934.0f },
    { -3267.0f, -3253.0f, -7520.0f }, { -4269.0f, -3561.0f, -10094.0f }, { -6475.0f, -3808.0f, -11557.0f }, { -10880.0f, -4270.0f, -9834.0f },
    { -11353.0f, -4618.0f, -6280.0f }, { -8742.0f, -4991.0f, -3400.0f }, { -3732.0f, -5453.0f, -3056.0f }, { -470.0f, -6259.0f, -3324.0f },
    { 2305.0f, -7015.0f, -4155.0f }, { 3951.0f, -7451.0f, -4570.0f }, { 5794.0f, -8053.0f, -5356.0f }, { 11056.0f, -9561.0f, -4652.0f },
    { 11660.0f, -10310.0f, -2312.0f }, { 10522.0f, -10720.0f, -531.0f }, { 8569.0f, -11090.0f, 184.0f }, { 1148.0f, -12419.0f, 299.0f },
    { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f },
};
Vec3f D_800FF5C4_BobsledRun[40] = {
    { 3200.0f, 9096.0f, 7880.0f }, { 4470.0f, 8560.0f, 10362.0f }, { 6695.0f, 8100.0f, 10960.0f }, { 8432.0f, 7650.0f, 9334.0f },
    { 8736.0f, 7300.0f, 6364.0f }, { 8710.0f, 6420.0f, -3010.0f }, { 8052.0f, 6232.0f, -4750.0f }, { 7480.0f, 6053.0f, -5985.0f },
    { 5511.0f, 5592.0f, -6792.0f }, { 428.0f, 4471.0f, -6926.0f }, { -1706.0f, 3628.0f, -6533.0f }, { -3210.0f, 3245.0f, -5685.0f },
    { -3777.0f, 3000.0f, -4300.0f }, { -4126.0f, 2810.0f, -2782.0f }, { -2114.0f, 2286.0f, 174.0f }, { 416.0f, 1712.0f, 3383.0f },
    { 1791.0f, 1390.0f, 5313.0f }, { 2045.0f, 1110.0f, 7950.0f }, { -505.0f, 490.0f, 9365.0f }, { -3120.0f, -250.0f, 6846.0f },
    { -3103.0f, -1132.0f, 2410.0f }, { -3714.0f, -3428.0f, -8820.0f }, { -4740.0f, -3605.0f, -10332.0f }, { -5997.0f, -3748.0f, -11110.0f },
    { -9772.0f, -4135.0f, -10715.0f }, { -11236.0f, -4384.0f, -8677.0f }, { -10991.0f, -4680.0f, -5728.0f }, { -7606.0f, -5091.0f, -3323.0f },
    { -3220.0f, -5500.0f, -3310.0f }, { -470.0f, -6259.0f, -3324.0f }, { 2305.0f, -7015.0f, -4155.0f }, { 8786.0f, -8800.0f, -5688.0f },
    { 10801.0f, -9510.0f, -4660.0f }, { 11480.0f, -10362.0f, -2100.0f }, { 11078.0f, -10570.0f, -1073.0f }, { 9150.0f, -11000.0f, 95.0f },
    { 1050.0f, -12431.0f, 270.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f },
};
Vec3f D_800FF7A4_BobsledRun[6] = {
    { 9200.0f, 8000.0f, 0.85f }, { 6500.0f, 5800.0f, 0.8f }, { 3800.0f, 2800.0f, 0.75f }, { 1300.0f, 0.0f, 0.7f },
    { -8200.0f, -10200.0f, 0.6f }, { -12500.0f, -13000.0f, 0.0f },
};
Vec3f D_800FF7EC_BobsledRun[7] = {
    { 9000.0f, 8000.0f, 0.85f }, { 6500.0f, 5800.0f, 0.98f }, { 3500.0f, 2900.0f, 0.75f }, { 1300.0f, 400.0f, 0.7f },
    { -8200.0f, -9700.0f, 0.6f }, { -12500.0f, -13000.0f, 0.0f }, { 0.0f, 0.0f, 0.0f },
};

void func_800F65E0_BobsledRun(void) {
    omObjData* Obj;

    func_80029090(50);
    func_8002ADF0(&D_800EDEC0, 64);
    func_8001DE70(32);
    omInitObjMan(50, 0);
    func_80060088();
    func_8000942C();
    func_800178A0(2);
    func_800179C0(2);
    func_8002578C(1);
    func_8002890C(0, 0, 50);
    func_80017660(0, 0.0f, 8.0f, 320.0f, 112.0f);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 240.0f, 511.0f);
    func_8001D494(0, 90.0f, 20.0f, 12000.0f);
    func_80017660(1, 0.0f, 128.0f, 320.0f, 232.0f);
    func_800176C4(1, 640.0f, 480.0f, 511.0f, 640.0f, 720.0f, 511.0f);
    func_8001D494(1, 90.0f, 20.0f, 12000.0f);
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    func_80009500();
    func_800090B8(D_800ED440);
    D_800F2AF8[D_800ED440++] = omAddObj(1, 5, 0, -1, &func_800FA890_BobsledRun);
    D_800F2AF8[D_800ED440++] = omAddObj(1, 1, 0, -1, &func_800FA96C_BobsledRun);
    D_800F2AF8[D_800ED440++] = omAddObj(1, 1, 0, -1, &func_800FAD64_BobsledRun);
    D_800F2AF8[D_800ED440++] = omAddObj(1, 1, 0, -1, &func_800FAE44_BobsledRun);
    D_800F2AF8[D_800ED440++] = omAddObj(1, 1, 0, -1, &func_800FAF20_BobsledRun);
    D_800F2AF8[D_800ED440++] = omAddObj(1, 1, 0, -1, &func_800FB000_BobsledRun);
    D_800F2AF8[D_800ED440++] = omAddObj(1, 1, 0, -1, &func_800FB0DC_BobsledRun);

    func_800FC918_BobsledRun();
    func_800FD164_BobsledRun();
    func_800FD124_BobsledRun();
    func_800FD36C_BobsledRun(0xF6, 0x18);
    func_800FD1BC_BobsledRun(0xF6, 0x24);
    func_800FCE2C_BobsledRun(1, func_800594FC(0));
    func_800FCE2C_BobsledRun(0, D_800FF34C_BobsledRun);
    D_800F3FB0[D_800F2BC0++] = omAddObj(2, 10, 60, -1, &func_800FBA00_BobsledRun);
    D_800F3FB0[D_800F2BC0++] = omAddObj(2, 10, 60, -1, &func_800FBB5C_BobsledRun);
    omAddObj(2, 10, 60, -1, &func_800FBCB8_BobsledRun);
    omAddObj(2, 10, 60, -1, &func_800FBD5C_BobsledRun);
    Obj = omAddObj(0x7FDA, 0, 0, -1, &func_800FC180_BobsledRun);
    Obj->work[0] = 2;
    omSetStatBit(Obj, 0xA0);
    D_800B895C = 10.0f;
    D_800B8968 = 0.06f;
    D_800B896C = 5.0f;
    D_800B8980 = 80.0f;
    func_80028510(990, 1000, 0, 0, 50);
    func_80028BE0(4);
    func_8007B168((u8*)"\x82\x71\x82\x64\x82\x60\x82\x63\x82\x78\x82\x66\x82\x6E\x82\x76\x82\x6B\x81\x49", 1);
    func_800234B8(0, 128, 128, 176);
    func_800234B8(1, 128, 128, 200);
    func_80060214(0x7F);
    func_800603F0(0x7F);
}

/* A shove from the other sled: if it is too strong, stop dead and bounce off. */
void func_800F6B60_BobsledRun(omObjData* obj) {
    BRWork* work;
    f32 lim;
    f32 d;
    f32 rot;

    work = obj->unk_50;
    lim = work->unk_48 * 0.8f;
    d = func_800B1750(D_800ED6B8 * D_800ED6B8 + D_800F5254 * D_800F5254);
    if (lim < d || fabs(D_800ED6B8) > lim || fabs(D_800F5254) > lim) {
        rot = work->unk_3C;
        work->unk_40 = D_800B8980 / 5.0f;
        func_80060F04(D_800FF2A8_BobsledRun[work->unk_58].player[0], 2, 2, 20);
        func_80060F04(D_800FF2A8_BobsledRun[work->unk_58].player[1], 2, 2, 20);
        D_800ED6B8 = -func_800AEAC0(rot) * work->unk_40;
        D_800F5254 = -func_800AEFD0(rot) * work->unk_40;
    }
    if (work->unk_58 == 0) {
        if (D_800FF338_BobsledRun < d) {
            D_800FF338_BobsledRun = d;
        }
    } else if (D_800FF33C_BobsledRun < d) {
        D_800FF33C_BobsledRun = d;
    }
}

BRGround* func_800F6D20_BobsledRun(BRWork* work) {
    BRGround* g;
    s32 i;

    if (work->unk_53 >= 0) {
        for (i = 0; i < D_800ED440; i++) {
            g = (D_800F2AF8[i])->unk_50;
            if (work->unk_53 == g->unk_05) {
                return g;
            }
        }
    }
    return NULL;
}

void func_800F6D8C_BobsledRun(void) {
    if (func_80072718() == 0) {
        omOvlReturnEx(1);
    }
}

/* Speed change from a bump against the other sled at (ox, oz). */
void func_800F6DB8_BobsledRun(BRWork* work, f32 x, f32 z, f32 ox, f32 oz) {
    f32 dx;
    f32 dz;
    f32 s;
    f32 dist;
    f32 rot;

    dx = x - ox;
    dz = z - oz;
    dist = func_800B1750(dx * dx + dz * dz);
    rot = work->unk_3C;
    s = func_800AEAC0(rot);
    rot = func_8000A72C(dx, dz, s, func_800AEFD0(rot));
    if (dist != 0.0f) {
        if (dist < work->unk_40 * 0.4f) {
            dist *= 0.05f;
        } else if (dist < work->unk_40 * 0.8f) {
            dist *= 0.1f;
        } else {
            dist *= 0.02f;
        }
        work->unk_40 = dist * rot + work->unk_40;
    }
}

/* The game controller (D_800F2AF8[1]): start, race, results. */
// the photo-finish branch: retail reloads D_800F3FB0[0]/[1] through a base register
#ifdef NON_MATCHING
void func_800F6F20_BobsledRun(omObjData* obj) {
    f32 x0;
    f32 x1;
    BRWork* w;
    omObjData* o;
    s16 st0;
    s16 st1;
    s32 a;
    s32 b;
    s16 mes;
    s32 coins;
    s32 lose;

    if (func_8005FD5C() + D_800F64F8 == 0) {
        func_80009468();
        if (D_800ED430 == 1) {
            D_800FF34C_BobsledRun += 2;
        }
        switch (D_800ED430) {
            case 0:
                if (D_800FF398_BobsledRun == 5) {
                    SetFadeInTypeAndTime(0, 16);
                }
                if (D_800FF398_BobsledRun >= 6) {
                    if (func_80072718() != 0) {
                        return;
                    }
                    if (D_800FF3B0_BobsledRun == 0) {
                        func_80060128(0x23);
                        D_800FF3B0_BobsledRun++;
                    }
                    if (D_800FF398_BobsledRun == 30) {
                        GMesCreate(13);
                    }
                    if (D_800FF398_BobsledRun > 80) {
                        func_80009458();
                    }
                }
                D_800FF398_BobsledRun++;
                break;
            case 1:
                st0 = D_800FF2A8_BobsledRun[0].state;
                st1 = D_800FF2A8_BobsledRun[1].state;
                if (D_800FF34C_BobsledRun > 18000) {
                    D_800FF2A1_BobsledRun = -3;
                    func_80009438();
                } else if (D_800FF2A0_BobsledRun == -1 && D_800FF2A1_BobsledRun != -2) {
                    a = st0 == 2;
                    b = st1 == 2;
                    if (a | b) {
                        if (a & b) {
                            if (D_800F3FB0[0]->trans.x < D_800F3FB0[1]->trans.x) {
                                w = D_800F3FB0[0]->unk_50;
                                w->unk_40 = x0 = D_800B8980;
                                D_800FF2A0_BobsledRun = w->unk_58;
                                o = D_800F3FB0[1];
                            } else {
                                w = D_800F3FB0[1]->unk_50;
                                w->unk_40 = x0 = D_800B8980;
                                D_800FF2A0_BobsledRun = w->unk_58;
                                o = D_800F3FB0[0];
                            }
                            BR_WORK(o)->unk_40 = x0 * 0.8f;
                        } else {
                            if (st0 == 2) {
                                o = D_800F3FB0[0];
                            } else if (st1 == 2) {
                                o = D_800F3FB0[1];
                            } else {
                                goto done;
                            }
                            w = o->unk_50;
                            w->unk_40 = D_800B8980;
                            D_800FF2A0_BobsledRun = w->unk_58;
                        }
                    done:
                        func_80009438();
                    }
                    if (_CheckFlag(0x2B) != 0 && D_800FF2A8_BobsledRun[0].state == 3) {
                        D_800FF2A0_BobsledRun = BR_WORK(D_800F3FB0[1])->unk_58;
                        func_80009438();
                    }
                } else {
                    func_80009438();
                }
                D_800FF39C_BobsledRun -= 2;
                break;
            case 2:
                if (D_800FF3A0_BobsledRun == 0) {
                    func_800601D4(40);
                    if (D_800FF350_BobsledRun != -1) {
                        func_8006071C((s16)D_800FF350_BobsledRun);
                    }
                    if (D_800FF354_BobsledRun != -1) {
                        func_8006071C((s16)D_800FF354_BobsledRun);
                    }
                    if (D_800FF2A8_BobsledRun[0].sound != -1) {
                        func_8006071C(D_800FF2A8_BobsledRun[0].sound);
                    }
                    if (D_800FF2A8_BobsledRun[1].sound != -1) {
                        func_8006071C(D_800FF2A8_BobsledRun[1].sound);
                    }
                    if (_CheckFlag(0x2B) != 0) {
                        GMesCreate(2);
                    } else if (D_800FF2A1_BobsledRun == -2) {
                        GMesCreate(0x11);
                    } else if (D_800FF2A1_BobsledRun == -3) {
                        GMesCreate(0x10);
                    } else {
                        GMesCreate(0x12);
                    }
                }
                if (D_800FF3A8_BobsledRun == 0) {
                    if (GMesStatAllGet() == 0 || (GMesStatAllGet() & 2)) {
                        if (D_800FF2A1_BobsledRun >= -1) {
                            GwPlayer[D_800FF2A8_BobsledRun[D_800FF2A0_BobsledRun].player[0]].coins_mg += 10;
                            GwPlayer[D_800FF2A8_BobsledRun[D_800FF2A0_BobsledRun].player[1]].coins_mg += 10;
                            lose = D_800FF2A0_BobsledRun == 0;
                            coins = GwPlayer[D_800FF2A8_BobsledRun[lose].player[0]].coins;
                            if (coins > 10) {
                                coins = 10;
                            }
                            GwPlayer[D_800FF2A8_BobsledRun[lose].player[0]].coins_mg -= coins;
                            coins = GwPlayer[D_800FF2A8_BobsledRun[lose].player[1]].coins;
                            if (coins > 10) {
                                coins = 10;
                            }
                            GwPlayer[D_800FF2A8_BobsledRun[lose].player[1]].coins_mg -= coins;
                            if (func_800594FC(0) > D_800FF34C_BobsledRun &&
                                (!(GwPlayer[D_800FF2A8_BobsledRun[D_800FF2A0_BobsledRun].player[0]].flags & 1) ||
                                 !(GwPlayer[D_800FF2A8_BobsledRun[D_800FF2A0_BobsledRun].player[1]].flags & 1))) {
                                if (_CheckFlag(0x2B) != 0) {
                                    if (D_800FF2A8_BobsledRun[0].state != 3) {
                                        func_800594E4(0, D_800FF34C_BobsledRun);
                                    }
                                } else {
                                    func_800594E4(0, D_800FF34C_BobsledRun);
                                    func_80060128(0x37);
                                }
                            } else {
                                if (_CheckFlag(0x2B) == 0) {
                                    func_80060128(0x36);
                                }
                                D_800FF3AC_BobsledRun = 1;
                            }
                        } else {
                            if (_CheckFlag(0x2B) == 0) {
                                func_80060128(0x35);
                            }
                            D_800FF3AC_BobsledRun = 2;
                        }
                        D_800FF3A8_BobsledRun++;
                    }
                } else {
                    switch (D_800FF3AC_BobsledRun) {
                        case 0:
                            if (D_800FF3A8_BobsledRun == 30) {
                                if (_CheckFlag(0x2B) == 0 || D_800FF2A8_BobsledRun[0].state != 3) {
                                    GMesCreate(12);
                                }
                            }
                            if (D_800FF3A8_BobsledRun == 120) {
                                func_80009448();
                            }
                            break;
                        case 1:
                            if (D_800FF3A8_BobsledRun == 105) {
                                func_80009448();
                            }
                            break;
                        case 2:
                            if (D_800FF3A8_BobsledRun == 90) {
                                func_80009448();
                            }
                            break;
                    }
                    D_800FF3A8_BobsledRun++;
                }
                D_800FF3A0_BobsledRun += 2;
                break;
            case 3:
                if (GMesWait() != 1) {
                    func_800726AC(0, 20);
                    obj->func_ptr = func_800F6D8C_BobsledRun;
                }
                D_800FF3A4_BobsledRun += 2;
                break;
        }
    }
    x0 = D_800FF2A8_BobsledRun[0].progress * 262.0f + 20.0f;
    x1 = D_800FF2A8_BobsledRun[1].progress * 262.0f + 20.0f;
    SetBasicSpritePos(D_800FFADA_BobsledRun, x0 - 2.0f, 104);
    SetBasicSpritePos(D_800FFADC_BobsledRun, x1 - 2.0f, 108);
    SetBasicSpritePos(D_800FF2A8_BobsledRun[0].sprite, x0 + 12.0f, 90);
    SetBasicSpritePos(D_800FF2A8_BobsledRun[1].sprite, x1 + 12.0f, 94);
    SetBasicSpritePos(D_800FF2A8_BobsledRun[0].sprite2, x0 + 2.0f, 90);
    SetBasicSpritePos(D_800FF2A8_BobsledRun[1].sprite2, x1 + 2.0f, 94);
    if (D_800FF2A8_BobsledRun[0].progress > D_800FF2A8_BobsledRun[1].progress) {
        D_800FF2A8_BobsledRun[0].path = 1;
        D_800FF2A8_BobsledRun[1].path = 0;
    } else {
        D_800FF2A8_BobsledRun[0].path = 0;
        D_800FF2A8_BobsledRun[1].path = 1;
    }
    func_800FCE2C_BobsledRun(0, D_800FF34C_BobsledRun);
    func_800FCB44_BobsledRun();
    if (D_800F5144 == 1) {
        omOvlReturnEx(1);
        func_800601D4(40);
        func_8006073C();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_BobsledRun/188410", func_800F6F20_BobsledRun);
#endif

/* The bobsled (D_800F3FB0[team]): steering, jumps, bumps and both cameras. */
// trans.y kept in an integer register, the bump branches not cross-jumped, block layout
#ifdef NON_MATCHING
void func_800F78F4_BobsledRun(omObjData* obj) {
    s16 stkX;
    s16 stkY;
    BRWork* work;
    BRGround* gw;
    f32 x;
    f32 y;
    f32 z;
    f32 accel;
    f32 turn;
    f32 dy;
    f32 v;
    f32 f;
    f32 r;
    f32 s2;
    f32 speed;
    f32 nx;
    f32 nz;
    f32 push;
    f32 sp;
    f32 roll;
    f32 cy;
    f32 back;
    f32 p;
    f32 t;
    s32 stick;
    s32 hit;
    u16 trg;
    u16 mdl0;
    u8 p0;
    u8 p1;
    s32 ground0;
    s32 a;
    u32 ust;
    u32 hi;
    f32 ny;
    u16 spr;
    s16 ah;

    accel = 0.0f;
    work = obj->unk_50;
    x = obj->trans.x;
    y = obj->trans.y;
    z = obj->trans.z;
    func_80005A04(obj);
    mdl0 = obj->model[0];
    D_800F5254 = 0.0f;
    D_800ED6B8 = 0.0f;
    D_800F370C = 0;
    stkX = stkY = 0;
    p0 = D_800FF2A8_BobsledRun[work->unk_58].port[0];
    p1 = D_800FF2A8_BobsledRun[work->unk_58].port[1];
    ground0 = work->unk_53;
    turn = 0.0f;
    if (D_800ED430 == 1 && !(work->unk_50 & 1)) {
        stick = (ContStkX[(s8)p0] + ContStkX[(s8)p1]) / 2;
        stkX = stick;
        stkY = (ContStkY[(s8)p0] + ContStkY[(s8)p1]) / 2;
        if (stick > 60) {
            stkX = 60;
        }
        if (stkY > 60) {
            stkY = 60;
        }
        if (stkX < -60) {
            stkX = -60;
        }
        if (stkY < -60) {
            stkY = -60;
        }
        func_80009D48(&stkX, &stkY);
        if (!(work->unk_50 & 6)) {
            trg = ContBtnTrg[(s8)p1] | ContBtnTrg[(s8)p0];
        } else {
            trg = 0;
        }
    } else {
        stkX = stkY = 0;
        trg = 0;
    }
    func_800FC4D0_BobsledRun(work);
    if (work->unk_38 != 1000.0f) {
        v = work->unk_38;
        if (D_800B8994 < v) {
            v = D_800B8994;
        }
        if (work->unk_38 >= 0.0f) {
            f = -35.0f;
        } else {
            f = 35.0f;
        }
        dy = v * v * f;
        ny = y + dy;
        if (!(work->unk_50 & 0x80)) {
            work->unk_38 += D_800B8968;
            if (D_800B8980 * 0.6f < work->unk_40) {
                work->unk_40 += -1.6f;
            }
        } else {
            work->unk_38 += 2.0f * D_800B8968;
        }
        a = stkX;
        if (a < 0) {
            a = -a;
        }
        if (a >= 9) {
            if (work->unk_40 < D_800B8980 / 3.0f) {
                turn = -(f32)stkX;
                f = 20.0f;
            } else if (work->unk_40 < D_800B8980 / 2.0f) {
                turn = -(f32)stkX;
                f = 30.0f;
            } else {
                turn = -(f32)stkX;
                f = 40.0f;
            }
            turn = turn / f;
        }
        work->unk_3C = turn + work->unk_3C;
        s2 = work->unk_40 * work->unk_40;
        r = func_800B1750(s2);
        r = r / func_800B1750(s2 + dy * dy);
        if (r != 0.0f) {
            work->unk_4C = r * 0.9f;
        }
        y = func_800F9A8C_BobsledRun(obj, x, ny, z, y);
        func_800FDCA8_BobsledRun(obj, 0, 24.0f, work->unk_3C, x, y, z);
        if (work->unk_38 == 1000.0f) {
            if (!(work->unk_50 & 0x80)) {
                work->unk_38 = -D_800B8964 * 0.5f;
                work->unk_50 |= 0x80;
            } else {
                work->unk_50 &= 0xFF7F;
                func_800184BC(obj, 0);
            }
            D_800FF2A8_BobsledRun[work->unk_58].timer = 0;
            PlaySound(0x29C);
            func_80060F04(D_800FF2A8_BobsledRun[work->unk_58].player[0], 20, 0, 20);
            func_80060F04(D_800FF2A8_BobsledRun[work->unk_58].player[1], 20, 0, 20);
            work->unk_B4 = 0;
        } else {
            D_800FF2A8_BobsledRun[work->unk_58].timer++;
            work->unk_B4 = 0;
        }
    } else {
        work->unk_4C = 1.0f;
        stick = func_80017A60(obj);
        D_800FF2A8_BobsledRun[work->unk_58].anim = 0;
        if (stick & 0x20) {
            D_800FF2A8_BobsledRun[work->unk_58].anim = 2;
            t = func_80025E70(mdl0);
            if (t == -1.0f) {
                t = func_80025D18(mdl0);
            }
            if (t > 44.0f) {
                func_800258EC(obj->model[0], 4, 4);
                obj->model[0] = D_800FF2A8_BobsledRun[work->unk_58].mdl[1];
                func_800186E4(obj, 0x23, 0);
                func_800184BC(obj, 0);
                func_800258EC(obj->model[0], 4, 0);
                D_800FF2A8_BobsledRun[work->unk_58].anim = 3;
                func_80060540(0x2A1, work->unk_58);
            }
        }
        ust = func_80009C90(obj, stkX, stkY);
        hi = ust >> 16;
        if (D_800FF8D0_BobsledRun[work->unk_58].y >= 0.0f) {
            if (D_800FF2A8_BobsledRun[work->unk_58].boost != 0) {
                work->unk_40 = 4.0f * D_800FF8D0_BobsledRun[work->unk_58].y + work->unk_40;
            } else {
                work->unk_40 = work->unk_40 + D_800FF8D0_BobsledRun[work->unk_58].y;
            }
        } else {
            work->unk_40 = D_800FF8D0_BobsledRun[work->unk_58].y * 4.0f + work->unk_40;
        }
        if (D_800FF2A8_BobsledRun[work->unk_58].state == 0) {
            if (trg & 0x8000) {
                accel = 1.0f;
                if (func_800184BC(obj, 1) == 1) {
                    func_800096B0(work, 1);
                }
                D_800FF2A8_BobsledRun[work->unk_58].anim = 1;
            }
        } else {
            if ((s16)ust >= 9) {
                accel = (s16)ust / 60.0f;
            } else if ((s16)ust < -8) {
                accel = (s16)ust / 48.0f;
            }
            if (D_800FF2A8_BobsledRun[work->unk_58].anim == 0) {
                D_800FF2A8_BobsledRun[work->unk_58].anim = 4;
            }
        }
        gw = func_800F6D20_BobsledRun(work);
        if (gw != NULL) {
            accel -= gw->unk_08;
        }
        work->unk_40 = accel + work->unk_40;
        if (D_800B8980 < work->unk_40) {
            work->unk_40 = D_800B8980;
        }
        if (work->unk_40 < 0.0f) {
            work->unk_40 = 0.0f;
        }
        if (D_800FF2A8_BobsledRun[work->unk_58].state != 0 &&
            D_800FF2A8_BobsledRun[work->unk_58].progress >= 0.005f) {
            if (work->unk_40 < D_800B8980 / 3.0f) {
                turn = -(f32)(s16)hi;
                f = 15.0f;
            } else if (work->unk_40 < D_800B8980 / 2.0f) {
                turn = -(f32)(s16)hi;
                f = 20.0f;
            } else {
                turn = -(f32)(s16)hi;
                f = 30.0f;
            }
            turn = turn / f;
            if (D_800FF2A8_BobsledRun[work->unk_58].state == 1 && D_800FF2A0_BobsledRun == -1 &&
                work->unk_40 != 0.0f && D_800ED430 == D_800FF2A8_BobsledRun[work->unk_58].state) {
                if (D_800FF2A8_BobsledRun[work->unk_58].sound == -1) {
                    D_800FF2A8_BobsledRun[work->unk_58].sound = PlaySound(work->unk_58 + 0x2A4);
                }
                func_80060440(D_800FF2A8_BobsledRun[work->unk_58].sound, work->unk_40 * 6.0f);
            }
        }
        func_800FCCE8_BobsledRun(obj, &work->unk_84, turn);
        t = func_800F93C0_BobsledRun(obj, work->unk_3C, x, y, z);
        if (t != 65536.0f) {
            y = t;
            ah = hi;
            if (ah < 0) {
                ah = -ah;
            }
            func_800FDCA8_BobsledRun(obj, ah, 24.0f, work->unk_3C, x, t, z);
            if ((ground0 != work->unk_53) & (ground0 == 1)) {
                func_800185A4(obj, 6);
                D_800FF2A8_BobsledRun[work->unk_58].anim = 2;
                func_80009624((unkGlobalStruct_00*)work, 3);
            }
        } else {
            work->unk_50 &= 0xFF7F;
            func_8006071C(D_800FF2A8_BobsledRun[work->unk_58].sound);
            D_800FF2A8_BobsledRun[work->unk_58].sound = -1;
        }
    }
    speed = work->unk_40;
    if (work->unk_38 != 1000.0f) {
        speed = speed * work->unk_4C;
    }
    nx = x + (func_800AEAC0(work->unk_3C) * speed + D_800ED6B8);
    nz = z + (func_800AEFD0(work->unk_3C) * speed + D_800F5254);
    func_8009ECB0(D_800F2B7C[obj->model[0]].unk7C, 0.0f, work->unk_3C, 0.0f);
    func_8009ECB0(D_800F2B7C[obj->model[4]].unk7C, 0.0f, work->unk_3C, 0.0f);
    func_800257E4(obj->model[4], obj->rot.x, obj->rot.y, obj->rot.z);
    if (work->unk_40 == D_800B8990 || work->unk_38 != 1000.0f) {
        D_800FF8D0_BobsledRun[work->unk_58].x = D_800FF8D0_BobsledRun[work->unk_58].y =
            D_800FF8D0_BobsledRun[work->unk_58].z = 0.0f;
    } else {
        D_800FF8D0_BobsledRun[work->unk_58].x = obj->trans.x - nx;
        D_800FF8D0_BobsledRun[work->unk_58].y = obj->trans.y - y;
        D_800FF8D0_BobsledRun[work->unk_58].z = obj->trans.z - nz;
        func_8002956C(&D_800FF8D0_BobsledRun[work->unk_58]);
    }
    func_800093FC(obj, nx, y, nz);
    func_80025798(obj->model[4], nx, y, nz);
    push = func_800B1750(D_800ED6B8 * D_800ED6B8 + D_800F5254 * D_800F5254);
    if (push != 0.0f) {
        sp = work->unk_40;
        hit = 0;
        if (push < sp * 0.4f) {
            work->unk_40 = -push * 0.1f + sp;
        } else {
            hit = 1;
            if (push < sp * 0.8f) {
                work->unk_40 = -push * 0.15f + sp;
            } else {
                work->unk_40 = -push * 0.2f + work->unk_40;
                hit = 2;
            }
        }
        if (D_800ED430 == 1 && D_800FF2A8_BobsledRun[work->unk_58].unk44 == 0) {
            PlaySound(0x29E);
            if (hit != 0) {
                if (hit == 1) {
                    goto shake;
                }
            } else {
                func_80060F04(D_800FF2A8_BobsledRun[work->unk_58].player[0], 5, 0, 5);
                func_80060F04(D_800FF2A8_BobsledRun[work->unk_58].player[1], 5, 0, 5);
            shake:
                func_80060F04(D_800FF2A8_BobsledRun[work->unk_58].player[0], 2, 3, 10);
                func_80060F04(D_800FF2A8_BobsledRun[work->unk_58].player[1], 2, 3, 10);
            }
            func_80060F04(D_800FF2A8_BobsledRun[work->unk_58].player[0], 10, 0, 10);
            func_80060F04(D_800FF2A8_BobsledRun[work->unk_58].player[1], 10, 0, 10);
        }
        D_800FF2A8_BobsledRun[work->unk_58].unk44++;
        if (D_800FF2A8_BobsledRun[work->unk_58].unk44 > 10) {
            D_800FF2A8_BobsledRun[work->unk_58].unk44 = 0;
        }
    } else {
        D_800FF2A8_BobsledRun[work->unk_58].unk44 = 0;
    }
    if (work->unk_58 == 0) {
        if (D_800FF338_BobsledRun < push) {
            D_800FF338_BobsledRun = push;
        }
    } else if (D_800FF33C_BobsledRun < push) {
        D_800FF33C_BobsledRun = push;
    }
    roll = func_800FCA48_BobsledRun(work->unk_58, (f32)(func_800FCAC0_BobsledRun(obj) >> 16) / 60.0f * 15.0f *
                                                      (work->unk_40 / (D_800B8980 * 0.7)));
    if (D_800FF2A8_BobsledRun[work->unk_58].timer < 30) {
        CRotM[work->unk_58].y = roll + work->unk_3C + 180.0f;
        D_800FF340_BobsledRun[work->unk_58] = roll * work->unk_40 * -0.003f;
        cy = 200.0f - (sp = work->unk_40);
        back = 2.0f * sp - D_800FF2A8_BobsledRun[work->unk_58].roll;
        CenterM[work->unk_58].x = obj->trans.x - func_800AEAC0(roll + work->unk_3C) * back;
        CenterM[work->unk_58].y = cy + obj->trans.y + 2.0f * D_800FF2A8_BobsledRun[work->unk_58].roll;
        CenterM[work->unk_58].z = obj->trans.z - func_800AEFD0(roll + work->unk_3C) * back;
        CZoomM[work->unk_58] = work->unk_40 + 300.0f;
        r = D_800FF2A8_BobsledRun[work->unk_58].roll;
        if (r != 0.0f) {
            CRotM[work->unk_58].y = CRotM[work->unk_58].y + r;
            if (D_800FF2A8_BobsledRun[work->unk_58].state != 0) {
                D_800FF2A8_BobsledRun[work->unk_58].roll = D_800FF2A8_BobsledRun[work->unk_58].roll * 0.98f;
            }
        }
        if (work->unk_38 != 1000.0f) {
            CRotM[work->unk_58].x = 2.0f * work->unk_38 + CRotM[work->unk_58].x;
            if (CRotM[work->unk_58].x < 320.0f) {
                CRotM[work->unk_58].x = 320.0f;
            }
            if (CRotM[work->unk_58].x > 350.0f) {
                CRotM[work->unk_58].x = 350.0f;
            }
            CenterM[work->unk_58].y = (200.0f - work->unk_40 * work->unk_38) + obj->trans.y;
        }
        p = 1.0 - (y + 12500.0f) / 23000.0f;
        if (D_800FF2A8_BobsledRun[work->unk_58].progress < p) {
            D_800FF2A8_BobsledRun[work->unk_58].progress = p;
        }
    } else if (D_800FF2A8_BobsledRun[work->unk_58].timer > 40) {
        obj->func_ptr = NULL;
        if (work->unk_58 == 0) {
            spr = D_800FFADA_BobsledRun;
        } else {
            spr = D_800FFADC_BobsledRun;
        }
        func_80018FBC(spr, 0, 255, -16);
        func_80018FBC(D_800FF2A8_BobsledRun[work->unk_58].sprite, 0, 255, -16);
        func_80018FBC(D_800FF2A8_BobsledRun[work->unk_58].sprite2, 0, 255, -16);
        func_800258EC(obj->model[0], 4, 4);
        func_800258EC(obj->model[4], 4, 4);
        func_800258EC(obj->model[3], 4, 4);
        obj->model[3] = 0;
        if (D_800FF348_BobsledRun == 0) {
            ShowBasicSprite(D_800FFADE_BobsledRun);
            func_80018CF8(D_800FFADE_BobsledRun, 2);
            func_80018FBC(D_800FFADE_BobsledRun, 255, 0, 8);
            if (work->unk_58 == 0) {
                SetBasicSpritePos(D_800FFADE_BobsledRun, 0, 0);
            } else {
                SetBasicSpritePos(D_800FFADE_BobsledRun, 0, 120);
            }
            D_800FF348_BobsledRun++;
        }
    }
    func_800FC7DC_BobsledRun(obj);
    if (D_800FF2A8_BobsledRun[work->unk_58].state == 2) {
        work->unk_3C = 270.0f;
        obj->func_ptr = func_800FE080_BobsledRun;
        D_800FF2A8_BobsledRun[work->unk_58].roll = 1.0f;
    }
    func_80017DB0(obj);
    func_800FDFC8_BobsledRun(work->unk_58, obj->model[3]);
    func_800FB858_BobsledRun(obj);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_BobsledRun/188410", func_800F78F4_BobsledRun);
#endif

/* Bumping into the other sled: returns 0 (retail never returns 2). */
// branch-likely delay slot of the bump test: retail copies mov.s $f12 into a bc1tl slot (one instruction
// short, masked 5); tried nested if, !(a && b) (M1c)
#ifdef NON_MATCHING
s32 func_800F9138_BobsledRun(omObjData* obj, f32 x, f32 y, f32 z) {
    BRWork* work;
    BRWork* ow;
    omObjData* o;
    f32 speed;
    f32 nx;
    f32 nz;
    f32 ny;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dx2;
    f32 dz2;
    f32 d2;
    f32 d;
    u16 i;

    work = obj->unk_50;
    speed = work->unk_40;
    if (work->unk_50 & 6) {
        speed *= 0.6f;
    }
    speed = speed * (work->unk_38 != 1000.0f ? work->unk_4C * work->unk_A4 : work->unk_A4);
    x += func_800AEAC0(work->unk_3C) * speed;
    z += func_800AEFD0(work->unk_3C) * speed;
    y += work->unk_48;
    for (i = 0; i < 2; i++) {
        o = D_800F3FB0[i];
        ow = o->unk_50;
        if (work != ow) {
            dx = o->trans.x - (x + D_800ED6B8);
            dy = (o->trans.y + ow->unk_48) - y;
            dz = o->trans.z - (z + D_800F5254);
            dx2 = dx * dx;
            dz2 = dz * dz;
            func_800B1750(dx2 + dz2);
            d2 = dx2 + dy * dy + dz2;
            func_800B1750(d2);
            d = func_800B1750(d2) - (ow->unk_48 + work->unk_48);
            if (d < 0.0f && (ow->unk_38 == 1000.0f || work->unk_38 != 1000.0f)) {
                func_800078E8(dx, dz, d);
                func_800F6DB8_BobsledRun(work, x, z, o->trans.x, o->trans.z);
                work->unk_54 = i;
            }
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_BobsledRun/188410", func_800F9138_BobsledRun);
#endif

/* Ground probe on the track (after a bump check); returns the ground height or 65536 (airborne). */
f32 func_800F93C0_BobsledRun(omObjData* obj, f32 rot, f32 x, f32 y, f32 z) {
    Vec4f probe;
    Vec3f n;
    Vec3f n2;
    BRWork* work;
    BRGround* gw;
    BRGround* cur;
    BRColVtx* verts;
    BRColTri* tri;
    Vec3f* normal;
    f32 speed;
    f32 nx;
    f32 nz;
    f32 floorY;
    f32 shadowY;
    f32 h;
    s16 mdl;
    u16 i0;
    u16 i1;
    u16 i2;
    s8 ground;

    ground = -1;
    normal = NULL;
    work = obj->unk_50;
    work->unk_54 = -1;
    work->unk_53 = -1;
    speed = work->unk_40 * work->unk_A4;
    nx = x + func_800AEAC0(rot) * speed + D_800ED6B8;
    nz = z + func_800AEFD0(rot) * speed + D_800F5254;
    floorY = -65536.0f;
    shadowY = -65536.0f;
    if (func_800F9138_BobsledRun(obj, nx, y, nz) != 2) {
        func_800F6B60_BobsledRun(obj);
        speed = work->unk_40;
        nx = x + func_800AEAC0(rot) * speed;
        nz = z + func_800AEFD0(rot) * speed;
        probe.x = nx + D_800ED6B8;
        probe.y = y + work->unk_48;
        probe.z = nz + D_800F5254;
        probe.w = work->unk_48;
        func_80004D1C(obj, &probe, 0);
        func_800F6B60_BobsledRun(obj);
        if (!(((u8*)work)[D_800B8954] & 1)) {
            gw = D_800F2AF8[D_800B8954]->unk_50;
            if (gw->unk_01 & 0x1A) {
                if (func_8000A910(&probe, gw) == 1) {
                    h = gw->unk_10;
                    if (floorY < h && h < y + 150.0f) {
                        floorY = h;
                        ground = D_800B8954;
                        if (shadowY < floorY && shadowY < y + 50.0f) {
                            shadowY = floorY;
                            n.x = 0.0f;
                            n.y = 1.0f;
                            n.z = 0.0f;
                            normal = &n;
                        }
                    }
                }
            } else {
                mdl = *D_800F2AF8[D_800B8954]->model;
                verts = (BRColVtx*)D_800F2B7C[mdl].unk_6C->unk_78;
                func_8002AE24(mdl, &D_800EDEC0, func_80002060, &probe);
                for (tri = func_8002B3A8(&D_800EDEC0); tri != NULL; tri = func_8002B3A8(&D_800EDEC0)) {
                    h = func_80029764(nx, y, nz, verts, tri);
                    if (floorY < h && h < y + 150.0f) {
                        floorY = h;
                        ground = D_800B8954;
                    }
                    if (shadowY < h && h < y + 150.0f) {
                        shadowY = h;
                        D_800FFAE8_BobsledRun = i0 = tri->v[0];
                        D_800FFAEA_BobsledRun = i1 = tri->v[1];
                        D_800FFAEC_BobsledRun = i2 = tri->v[2];
                        func_800295FC(D_800FFAF0_BobsledRun = &verts[(s16)i0], D_800FFAF8_BobsledRun = &verts[(s16)i1],
                                      D_800FFAF4_BobsledRun = &verts[(s16)i2], &n);
                        normal = &n;
                    }
                }
                if (floorY == -65536.0f) {
                    floorY = -65536.0f;
                }
            }
        }
        h = func_800051D4(obj, nx + D_800ED6B8, y, nz + D_800F5254, &n2);
        if (floorY < h && h < y + 50.0f) {
            ground = D_800B8958;
            floorY = h;
        } else {
            if (h < y + 150.0f && y + 50.0f < h) {
                floorY = 65536.0f;
            }
            work->unk_53 = -1;
        }
        if (shadowY < h && h < y + 50.0f) {
            normal = &n2;
        }
        if (y - 50.0f < floorY && floorY < y + 50.0f) {
            if (ground != -1) {
                work->unk_53 = ground;
            }
            y = floorY;
            work->unk_38 = 1000.0f;
        } else {
            work->unk_38 = D_800B8964 * 0.1f;
            work->unk_53 = -1;
            PlaySound(0x29A);
            return 65536.0f;
        }
    } else {
        probe.x = nx + D_800ED6B8;
        probe.y = y;
        probe.z = nz + D_800F5254;
        probe.w = work->unk_48;
        func_80004D1C(obj, &probe, 0);
    }
    if (obj->model[1] != 0) {
        func_800258EC(obj->model[1], 4, 4);
    }
    if (work->unk_53 >= 0) {
        cur = D_800F2AF8[work->unk_53]->unk_50;
        work->unk_84.x = normal->x * cur->unk_0C;
        work->unk_84.y = normal->y;
        work->unk_84.z = normal->z * cur->unk_0C;
        func_800FBE04_BobsledRun(obj, normal);
        func_800FA15C_BobsledRun(work->unk_58, normal);
    } else {
        work->unk_84.x = work->unk_84.y = work->unk_84.z = 0.0f;
        work->unk_90 = work->unk_98 = 0.0f;
        obj->rot.x = obj->rot.z = 0.0f;
    }
    return y;
}

/* Airborne probe: lands the sled when the ground comes up under it. */
f32 func_800F9A8C_BobsledRun(omObjData* obj, f32 x, f32 y, f32 z, f32 oldY) {
    Vec4f probe;
    Vec3f n;
    Vec3f n2;
    BRWork* work;
    BRGround* gw;
    BRColVtx* verts;
    BRColTri* tri;
    Vec3f* normal;
    f32 speed;
    f32 nx;
    f32 nz;
    f32 floorY;
    f32 shadowY;
    f32 h;
    f32 d;
    f32 s;
    s16 mdl;

    work = obj->unk_50;
    work->unk_54 = -1;
    work->unk_53 = -1;
    speed = work->unk_40 * work->unk_4C;
    nx = x + func_800AEAC0(work->unk_3C) * speed + D_800ED6B8;
    nz = z + func_800AEFD0(work->unk_3C) * speed + D_800F5254;
    shadowY = -65536.0f;
    floorY = -65536.0f;
    if (func_800F9138_BobsledRun(obj, nx, y, nz) != 2) {
        speed = work->unk_40;
        nx = x + func_800AEAC0(work->unk_3C) * speed;
        nz = z + func_800AEFD0(work->unk_3C) * speed;
        probe.x = nx + D_800ED6B8;
        probe.y = y;
        probe.z = nz + D_800F5254;
        probe.w = work->unk_48;
        func_80004D1C(obj, &probe, 0);
        probe.x = nx + D_800ED6B8;
        probe.y = y;
        probe.z = nz + D_800F5254;
        if (!(((u8*)work)[D_800B8954] & 1)) {
            gw = D_800F2AF8[D_800B8954]->unk_50;
            if (gw->unk_01 & 0x1A) {
                if (func_8000A910(&probe, gw) == 1) {
                    h = gw->unk_10;
                    if (floorY < h && h < y + 150.0f) {
                        floorY = h;
                        D_800B8958 = D_800B8954;
                        if (shadowY < floorY && shadowY < y + 35.0f) {
                            shadowY = floorY;
                            n.x = 0.0f;
                            n.y = 1.0f;
                            n.z = 0.0f;
                            normal = &n;
                        }
                    }
                }
            } else {
                mdl = *D_800F2AF8[D_800B8954]->model;
                verts = (BRColVtx*)D_800F2B7C[mdl].unk_6C->unk_78;
                func_8002AE24(mdl, &D_800EDEC0, func_80002060, &probe);
                for (tri = func_8002B3A8(&D_800EDEC0); tri != NULL; tri = func_8002B3A8(&D_800EDEC0)) {
                    h = func_80029764(nx + D_800ED6B8, y, nz + D_800F5254, verts, tri);
                    if (floorY < h && h < y + 150.0f) {
                        floorY = h;
                        D_800B8958 = D_800B8954;
                    }
                    if (shadowY < h && shadowY < y + 35.0f) {
                        shadowY = h;
                        func_800295FC(&verts[tri->v[0]], &verts[tri->v[1]], &verts[tri->v[2]], &n);
                        normal = &n;
                    }
                }
                if (floorY == -65536.0f) {
                    floorY = -65536.0f;
                }
            }
        }
        h = func_800051D4(obj, nx + D_800ED6B8, y, nz + D_800F5254, &n2);
        if (floorY < h && h < y + 150.0f) {
            floorY = h;
        } else {
            work->unk_53 = -1;
        }
        if (shadowY < h && h < y + 150.0f) {
            shadowY = h;
            normal = &n2;
        }
        if (floorY == -65536.0f) {
            shadowY = -65536.0f;
            work->unk_4C = 0.5f;
            if (work->unk_38 < 0.0f) {
                work->unk_38 = 0.0f;
            }
            work->unk_53 = -1;
        } else if (y < floorY) {
            work->unk_53 = D_800B8958;
            y = func_800006E4(obj, floorY);
            work->unk_38 = 1000.0f;
            work->unk_50 &= 0xFFEF;
        } else {
            work->unk_53 = -1;
        }
    } else {
        probe.x = nx + D_800ED6B8;
        probe.y = y;
        probe.z = nz + D_800F5254;
        probe.w = work->unk_48;
        func_80004D1C(obj, &probe, 0);
    }
    if (obj->model[1] != 0) {
        if (shadowY != -65536.0f) {
            func_80025798(obj->model[1], nx, shadowY, nz);
            shadowY = y - shadowY;
            if (shadowY > 200.0f) {
                s = 1.5f;
            } else {
                s = 2.0f - fabsf(shadowY) / 2000.0f;
            }
            func_80025830(obj->model[1], s, s, s);
            func_80037178(obj->model[1], normal);
            func_800258EC(obj->model[1], 4, 0);
        } else {
            func_800258EC(obj->model[1], 4, 4);
        }
    }
    work->unk_84.x = work->unk_84.y = work->unk_84.z = 0.0f;
    return y;
}

/* Pitch the team's camera with the slope under the sled. */
void func_800FA15C_BobsledRun(s8 team, Vec3f* normal) {
    f32 target;

    target = D_800FF2A4_BobsledRun - (1.0f - normal->y) * 500.0f;
    if (CRotM[team].x < target) {
        CRotM[team].x += 0.5f;
        if (target < CRotM[team].x) {
            CRotM[team].x = target;
        }
    } else {
        CRotM[team].x -= 0.5f;
        if (CRotM[team].x < target) {
            CRotM[team].x = target;
        }
    }
}

/* func_8000979C for the bobsled (no character model): its work, models and motions. */
void func_800FA244_BobsledRun(omObjData* obj, s32 dir, s32 file, u16 team, u16 flags, u16 motFile) {
    BRWork* work;
    s32 i;

    for (i = 0; i < obj->mdlcnt; i++) {
        obj->model[i] = 0;
    }
    obj->unk_50 = func_80023684(sizeof(BRWork), 0x7918);
    func_8009B770(obj->unk_50, 0, sizeof(BRWork));
    work = obj->unk_50;
    work->unk_D8 = func_80023684(obj->mtncnt * 4, 0x7918);
    obj->model[0] = LoadFormFile(dir | file, flags);
    obj->model[1] = func_800174F4(D_800B8959 == 0 ? 6 : 0x20, motFile);
    func_800370D4(obj->model[1]);
    for (i = 0; i < obj->mtncnt; i++) {
        obj->motion[i] = -1;
    }
    for (i = 0; i < obj->mtncnt; i++) {
        work->unk_D8[i][0] = 0;
        work->unk_D8[i][1] = 0;
    }
    work->unk_56 = GwPlayer[team].port;
    obj->func_ptr = func_80005A28;
    work->unk_52 = 0;
    work->unk_A4 = 1.0f;
    work->unk_C0 = 0xFFFF;
    work->unk_4C = 0.5f;
    work->unk_BC = 1.0f;
    work->unk_60 = 0.0f;
    func_80008FD0(obj, 60.0f);
    func_80008FDC(obj, 150.0f);
    func_80008FE8(obj, 20.0f);
    func_80008FF4(obj, 30.0f);
    func_80008FA0(obj, 1000.0f);
    work->unk_90 = work->unk_94 = work->unk_98 = 0.0f;
    work->unk_58 = team;
    work->unk_B2 = work->unk_B1 = -1;
}

/* A CPU rider: push off at the start, then steer for the next waypoint and brake on the bends. */
void func_800FA484_BobsledRun(omObjData* obj, s8 player, s8 port) {
    BRWork* work;
    f32 skill;
    f32 px;
    f32 py;
    f32 pz;
    f32 dx;
    f32 dz;
    f32 a;
    f32 s;
    f32 ty;
    u32 chance;
    s32 i;

    work = obj->unk_50;
    switch (GwPlayer[player].cpu_difficulty) {
        case 0:
            skill = 0.7f;
            chance = 0xD8;
            break;
        case 1:
            skill = 0.8f;
            chance = 0xB8;
            break;
        case 2:
            skill = 0.9f;
            chance = 0x90;
            break;
        default:
            chance = 0x60;
            skill = 1.0f;
            break;
    }
    switch (D_800FF2A8_BobsledRun[work->unk_58].state) {
        case 0:
            if (chance < rand8()) {
                ContBtnTrg[port] |= 0x8000;
            }
            break;
        case 2:
            ContStkY[port] = -60;
            break;
        default:
            i = 0;
            do {
                if (D_800FF2A8_BobsledRun[work->unk_58].path != 0) {
                    px = D_800FF3B4_BobsledRun[i].x;
                    py = D_800FF3B4_BobsledRun[i].y;
                    pz = D_800FF3B4_BobsledRun[i].z;
                } else {
                    px = D_800FF5C4_BobsledRun[i].x;
                    py = D_800FF5C4_BobsledRun[i].y;
                    pz = D_800FF5C4_BobsledRun[i].z;
                }
                if (px == 0.0f) {
                    break;
                }
                i++;
                if (py < obj->trans.y) {
                    px -= obj->trans.x;
                    pz -= obj->trans.z;
                    a = work->unk_3C - 90.0f;
                    s = func_800AEAC0(a);
                    ContStkX[port] = func_8000A72C(px, pz, s, func_800AEFD0(a)) * 120.0f * skill;
                    break;
                }
            } while (i < 42);
            ContStkY[port] = skill * 60.0f;
            for (i = 0; i < 6; i++) {
                if (D_800FF2A8_BobsledRun[work->unk_58].path != 0) {
                    px = D_800FF7A4_BobsledRun[i].x;
                    py = D_800FF7A4_BobsledRun[i].y;
                    pz = D_800FF7A4_BobsledRun[i].z;
                } else {
                    px = D_800FF7EC_BobsledRun[i].x;
                    py = D_800FF7EC_BobsledRun[i].y;
                    pz = D_800FF7EC_BobsledRun[i].z;
                }
                ty = obj->trans.y;
                if (ty <= px) {
                    if (py <= ty) {
                        if (pz * 80.0f < work->unk_40) {
                            ContStkY[port] = skill * -60.0f;
                        }
                        break;
                    }
                }
            }
            break;
    }
}

/* The track sections (ground objects 0..6). */
void func_800FA890_BobsledRun(omObjData* obj) {
    BRGround* w;

    D_800F5028 = 0.8f;
    D_800F524C = 0.8f;
    obj->model[0] = func_800174C0(0x300006, 0x2299);
    obj->trans.x = 0.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    obj->unk_50 = w = func_80023684(sizeof(BRGround), 0x7918);
    func_8009B770(w, 0, sizeof(BRGround));
    obj->func_ptr = NULL;
    w->unk_04 = 1;
    func_80009000(obj, 2, -18000.0f);
    w->unk_05 = 0;
    func_80025930(obj->model[0], 0x600, 0x600);
}

// register allocation
#ifdef NON_MATCHING
void func_800FA96C_BobsledRun(omObjData* obj) {
    s16 x;
    s32 spr;
    BRGround* w;

    D_800F5028 = 0.8f;
    D_800F524C = 0.8f;
    obj->model[0] = func_800174C0(0x300000, 0x22099);
    D_800F5028 = 1.0f;
    D_800F524C = 1.0f;
    obj->trans.x = 0.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    obj->unk_50 = w = func_80023684(sizeof(BRGround), 0x7918);
    func_8009B770(w, 0, sizeof(BRGround));
    obj->func_ptr = func_800F6F20_BobsledRun;
    w->unk_04 = 1;
    func_800090A4(obj);
    func_80008FB8(obj, 0.2f);
    func_80008FC4(obj, 25.0f);
    w->unk_05 = 1;
    CenterM[0].x = 8.0f;
    CenterM[0].y = 110.0f;
    CenterM[0].z = -86.0f;
    CRotM[0].x = D_800FF2A4_BobsledRun;
    CZoomM[0] = 600.0f;
    CenterM[1].x = 8.0f;
    CenterM[1].y = 110.0f;
    CenterM[1].z = -86.0f;
    CRotM[1].x = D_800FF2A4_BobsledRun;
    CZoomM[1] = 600.0f;
    omSetStatBit(obj, 0xA0);
    func_80025F10(obj->model[0], 3);
    spr = InitSprite(0x300039);
    x = 8;
    do {
        D_800FFAD4_BobsledRun = func_80019060((s16)spr, 0, 1);
        SetBasicSpritePos(D_800FFAD4_BobsledRun, x, 0x70);
        func_80018D84(D_800FFAD4_BobsledRun, 16);
        x += 16;
    } while (x < 0x120);
    D_800FFAD4_BobsledRun = func_80019060((s16)spr, 0, 1);
    SetBasicSpritePos(D_800FFAD4_BobsledRun, 0x130, 0x70);
    func_80018D84(D_800FFAD4_BobsledRun, 16);
    D_800FFAD6_BobsledRun = func_80019060((s16)InitSprite(0x30003B), 0, 1);
    SetBasicSpritePos(D_800FFAD6_BobsledRun, 0x120, 0x70);
    func_80018D84(D_800FFAD6_BobsledRun, 16);
    D_800FFAD8_BobsledRun = func_80019060((s16)InitSprite(0x30003A), 0, 1);
    SetBasicSpritePos(D_800FFAD8_BobsledRun, 0x120, 0x60);
    func_80018D84(D_800FFAD8_BobsledRun, 16);
    D_800FFADA_BobsledRun = func_80019060((s16)InitSprite(0x300036), 0, 1);
    SetBasicSpriteSize(D_800FFADA_BobsledRun, 1.0f, 1.0f);
    func_80018D84(D_800FFADA_BobsledRun, 8);
    D_800FFADC_BobsledRun = func_80019060((s16)InitSprite(0x300037), 0, 1);
    SetBasicSpriteSize(D_800FFADC_BobsledRun, 1.0f, 1.0f);
    func_80018D84(D_800FFADC_BobsledRun, 6);
    SetBasicSpritePos(D_800FFADA_BobsledRun, 0x12, 0x68);
    SetBasicSpritePos(D_800FFADC_BobsledRun, 0x12, 0x6C);
    D_800FFADE_BobsledRun = func_80019060((s16)InitSprite(0x300038), 0, 1);
    SetBasicSpriteSize(D_800FFADE_BobsledRun, 40.0f, 14.0f);
    func_80018D84(D_800FFADE_BobsledRun, 0x20);
    func_80018C90(D_800FFADE_BobsledRun);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_BobsledRun/188410", func_800FA96C_BobsledRun);
#endif

void func_800FAD64_BobsledRun(omObjData* obj) {
    BRGround* w;

    D_800F5028 = 0.8f;
    D_800F524C = 0.8f;
    obj->model[0] = func_800174C0(0x300001, 0x220D9);
    obj->trans.x = 0.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    obj->unk_50 = w = func_80023684(sizeof(BRGround), 0x7918);
    func_8009B770(w, 0, sizeof(BRGround));
    obj->func_ptr = NULL;
    w->unk_04 = 1;
    func_800090A4(obj);
    func_80008FB8(obj, 0.1f);
    func_80008FC4(obj, 25.0f);
    w->unk_05 = 2;
}

void func_800FAE44_BobsledRun(omObjData* obj) {
    BRGround* w;

    D_800F5028 = 0.8f;
    D_800F524C = 0.8f;
    obj->model[0] = func_800174C0(0x300002, 0x20D9);
    obj->trans.x = 0.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    obj->unk_50 = w = func_80023684(sizeof(BRGround), 0x7918);
    func_8009B770(w, 0, sizeof(BRGround));
    obj->func_ptr = NULL;
    w->unk_04 = 1;
    func_800090A4(obj);
    func_80008FB8(obj, 0.1f);
    func_80008FC4(obj, 25.0f);
    w->unk_05 = 3;
}

void func_800FAF20_BobsledRun(omObjData* obj) {
    BRGround* w;

    D_800F5028 = 0.8f;
    D_800F524C = 0.8f;
    obj->model[0] = func_800174C0(0x300003, 0x220D9);
    obj->trans.x = 0.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    obj->unk_50 = w = func_80023684(sizeof(BRGround), 0x7918);
    func_8009B770(w, 0, sizeof(BRGround));
    obj->func_ptr = NULL;
    w->unk_04 = 1;
    func_800090A4(obj);
    func_80008FB8(obj, 0.1f);
    func_80008FC4(obj, 25.0f);
    w->unk_05 = 4;
}

void func_800FB000_BobsledRun(omObjData* obj) {
    BRGround* w;

    D_800F5028 = 0.8f;
    D_800F524C = 0.8f;
    obj->model[0] = func_800174C0(0x300004, 0x20099);
    obj->trans.x = 0.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    obj->unk_50 = w = func_80023684(sizeof(BRGround), 0x7918);
    func_8009B770(w, 0, sizeof(BRGround));
    obj->func_ptr = NULL;
    w->unk_04 = 1;
    func_800090A4(obj);
    func_80008FB8(obj, 0.5f);
    func_80008FC4(obj, 25.0f);
    w->unk_05 = 5;
}

void func_800FB0DC_BobsledRun(omObjData* obj) {
    BRGround* w;

    D_800F5028 = 1.0f;
    D_800F524C = 1.0f;
    obj->model[0] = func_800174C0(0x300005, 0x2209D);
    obj->trans.x = 0.0f;
    obj->trans.y = 10.0f;
    obj->trans.z = 0.0f;
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    obj->unk_50 = w = func_80023684(sizeof(BRGround), 0x7918);
    func_8009B770(w, 0, sizeof(BRGround));
    obj->func_ptr = NULL;
    w->unk_04 = 1;
    func_800090A4(obj);
    func_80008FB8(obj, 0.1f);
    func_80008FC4(obj, 25.0f);
    w->unk_05 = 6;
}

/* A bobsled for team (the front rider's character dir/file). */
void func_800FB1C4_BobsledRun(omObjData* obj, s32 dir, s32 file, u16 team) {
    BRWork* work;
    s32 sled;
    s32 mot;
    s32 spr;
    s32 motFile;
    s32 flags;

    motFile = 0x22A99;
    switch ((u32)dir >> 16) {
        case 1:
            sled = 0xC;
            mot = 0x12;
            spr = 0x30;
            break;
        case 2:
            sled = 0xD;
            mot = 0x17;
            spr = 0x31;
            break;
        case 6:
            sled = 0xE;
            mot = 0x1C;
            spr = 0x32;
            break;
        case 3:
            sled = 0xF;
            mot = 0x21;
            spr = 0x33;
            break;
        case 4:
            sled = 0x10;
            mot = 0x26;
            spr = 0x34;
            break;
        default:
            sled = 0x11;
            mot = 0x2B;
            spr = 0x35;
            break;
    }
    D_800F5028 = 0.8f;
    D_800F524C = 0.8f;
    func_800FA244_BobsledRun(obj, 0x300000, sled, team, flags = motFile | 4, motFile);
    work = obj->unk_50;
    D_800FF2A8_BobsledRun[team].mdl[1] = obj->model[0];
    func_80025830(obj->model[1], 2.0f, 2.0f, 2.0f);
    D_800FF2A8_BobsledRun[team].mdl[0] = obj->model[0] = LoadFormFile(dir | file, 0x2A99);
    D_800F5028 = 0.4f;
    D_800F524C = 0.4f;
    D_800FF2A8_BobsledRun[team].mdl[4] = LoadFormFile(sled | 0x300000, flags);
    D_800F5028 = 0.8f;
    D_800F524C = 0.8f;
    func_800187D0(obj, 0x23, mot | 0x300000, 1, 0);
    func_800187D0(obj, 0, (mot + 1) | 0x300000, 1, 0);
    func_800187D0(obj, 1, (mot + 2) | 0x300000, 2, 0);
    func_800187D0(obj, 6, (mot + 3) | 0x300000, 0, 0);
    func_800187D0(obj, 0xD, (mot + 4) | 0x300000, 0, 0);
    func_800187D0(obj, 9, dir | 0xA, 0, 0);
    func_800187D0(obj, 0xE, dir | 0x2F, 1, 0);
    obj->func_ptr = func_800FD51C_BobsledRun;
    func_80008FD0(obj, 100.0f);
    work->unk_3C = 0.0f;
    func_800090C4(obj, 0, 2);
    func_800090C4(obj, 1, 2);
    func_800090C4(obj, 2, 2);
    func_800090C4(obj, 3, 2);
    func_800090C4(obj, 4, 2);
    func_800090C4(obj, 5, 2);
    func_800090C4(obj, 6, 2);
    func_800FC9F8_BobsledRun();
    D_800FF2A8_BobsledRun[team].mdl[8] = obj->model[3] = LoadFormFile(0x30000B, 0x889);
    D_800F5028 = 0.2f;
    D_800F524C = 0.2f;
    D_800FF2A8_BobsledRun[team].mdl[9] = LoadFormFile(0x30000B, 0x88D);
    D_800F5028 = 0.8f;
    D_800F524C = 0.8f;
    D_800FF2A8_BobsledRun[team].sprite = func_80019060((s16)InitSprite(spr | 0x300000), 0, 1);
}

/* The back rider of team (sits on the sled; func_800FEC80). */
// register allocation
#ifdef NON_MATCHING
void func_800FB594_BobsledRun(omObjData* obj, s32 dir, s32 file, u16 player, u16 team) {
    BRWork* work;
    s32 body;
    s32 mot;
    s32 spr;
    s32 flags;

    flags = 0x22A99;
    switch ((u32)dir >> 16) {
        case 1:
            body = 0xC;
            mot = 0x12;
            spr = 0x30;
            break;
        case 2:
            body = 0xD;
            mot = 0x17;
            spr = 0x31;
            break;
        case 6:
            body = 0xE;
            mot = 0x1C;
            spr = 0x32;
            break;
        case 3:
            body = 0xF;
            mot = 0x21;
            spr = 0x33;
            break;
        case 4:
            body = 0x10;
            mot = 0x26;
            spr = 0x34;
            break;
        default:
            body = 0x11;
            mot = 0x2B;
            spr = 0x35;
            break;
    }
    D_800F5028 = 0.8f;
    D_800F524C = 0.8f;
    flags |= 4;
    func_8000979C(obj, 0x300000, body, player, flags, flags);
    D_800FF2A8_BobsledRun[team].mdl[3] = obj->model[0];
    work = obj->unk_50;
    D_800FF2A8_BobsledRun[team].mdl[2] = obj->model[0] = LoadFormFile(dir | file, 0x2A99);
    D_800F5028 = 0.4f;
    D_800F524C = 0.4f;
    D_800FF2A8_BobsledRun[team].mdl[5] = LoadFormFile(body | 0x300000, flags);
    D_800F5028 = 0.8f;
    D_800F524C = 0.8f;
    func_800187D0(obj, 0x23, mot | 0x300000, 1, 0);
    func_800187D0(obj, 0, (mot + 1) | 0x300000, 1, 0);
    func_800187D0(obj, 1, (mot + 2) | 0x300000, 0, 0);
    func_800187D0(obj, 6, (mot + 3) | 0x300000, 0, 0);
    func_800187D0(obj, 0xD, (mot + 4) | 0x300000, 0, 0);
    func_800187D0(obj, 9, dir | 0xA, 0, 0);
    func_800187D0(obj, 0xE, dir | 0x2F, 1, 0);
    obj->func_ptr = func_800FEC80_BobsledRun;
    work->unk_58 = team;
    D_800FF2A8_BobsledRun[team].sprite2 = func_80019060((s16)InitSprite(spr | 0x300000), 0, 1);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_BobsledRun/188410", func_800FB594_BobsledRun);
#endif

/* Draw layer by distance to the other team's camera (1: top screen only, 2: bottom, 3: both). */
// register allocation (masked 0, raw 21): obj/layer swap s0/s1, dx..dz not tied to their loads;
// tried declaration order, per-branch distance, operand order (M1c)
#ifdef NON_MATCHING
void func_800FB858_BobsledRun(omObjData* obj) {
    Vec3f* c;
    s32 layer;
    f32 dx;
    f32 dy;
    f32 dz;

    layer = 2;
    if (BR_WORK(obj)->unk_58 == 0) {
        c = &CenterM[1];
        layer = 1;
    } else {
        c = &CenterM[0];
    }
    dx = obj->trans.x - c->x;
    dy = obj->trans.y - c->y;
    dz = obj->trans.z - c->z;
    if (func_800B1750(dx * dx + dy * dy + dz * dz) < 5000.0f) {
        layer = 3;
    }
    func_80025F10(obj->model[0], layer);
    func_80025F10(obj->model[1], layer);
    func_80025F10(obj->model[4], layer);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_BobsledRun/188410", func_800FB858_BobsledRun);
#endif

// register allocation
// decomp-permuter
void func_800FB93C_BobsledRun(omObjData *obj)
{
  Vec3f *c;
  s32 layer;
  unsigned char pad;
  f32 dx;
  f32 dy;
  f32 dz;
  layer = 2;
  if (((BRWork *) obj->unk_50)->unk_58 == 0)
  {
    c = &CenterM[1];
    layer = 1;
  }
  else
  {
    c = &CenterM[0];
  }
  if (c)
  {
    dx = obj->trans.x - c->x;
    dy = obj->trans.y - c->y;
    dz = obj->trans.z - c->z;
  }
  else
  {
    dx = obj->trans.x - c->x;
    dy = obj->trans.y - c->y;
    dz = obj->trans.z - c->z;
  }
  if (func_800B1750(((dx * dx) + (dy * dy)) + (dz * dz)) < 5000.0f)
  {
    layer = 3;
  }
  func_80025F10(obj->model[0], layer);
}

void func_800FBA00_BobsledRun(omObjData* obj) {
    func_800FB1C4_BobsledRun(obj, D_800C59AC[GwPlayer[D_800FF2A8_BobsledRun[0].player[0]].character].unk_00,
                             D_800C59AC[GwPlayer[D_800FF2A8_BobsledRun[0].player[0]].character].unk_04, 0);
    D_800FF2A8_BobsledRun[0].mdl[6] = obj->model[4] = LoadFormFile(0x300007, 0x20AC9);
    D_800F5028 = 0.4f;
    D_800F524C = 0.4f;
    D_800FF2A8_BobsledRun[0].mdl[7] = LoadFormFile(0x300007, 0x20ACD);
    D_800F5028 = 1.0f;
    D_800F524C = 1.0f;
    func_800184BC(obj, 0);
    obj->trans.x = 2800.0f;
    obj->trans.y = 10500.0f;
    obj->trans.z = -4000.0f;
    func_80025798(obj->model[4], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80018D84(D_800FF2A8_BobsledRun[0].sprite, 9);
    SetBasicSpritePos(D_800FF2A8_BobsledRun[0].sprite, 0x20, 0x5A);
}

void func_800FBB5C_BobsledRun(omObjData* obj) {
    func_800FB1C4_BobsledRun(obj, D_800C59AC[GwPlayer[D_800FF2A8_BobsledRun[1].player[0]].character].unk_00,
                             D_800C59AC[GwPlayer[D_800FF2A8_BobsledRun[1].player[0]].character].unk_04, 1);
    D_800FF2A8_BobsledRun[1].mdl[6] = obj->model[4] = LoadFormFile(0x300008, 0x20AC9);
    D_800F5028 = 0.4f;
    D_800F524C = 0.4f;
    D_800FF2A8_BobsledRun[1].mdl[7] = LoadFormFile(0x300008, 0x20ACD);
    D_800F5028 = 1.0f;
    D_800F524C = 1.0f;
    func_800184BC(obj, 0);
    obj->trans.x = 3200.0f;
    obj->trans.y = 10500.0f;
    obj->trans.z = -4000.0f;
    func_80025798(obj->model[4], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80018D84(D_800FF2A8_BobsledRun[1].sprite, 7);
    SetBasicSpritePos(D_800FF2A8_BobsledRun[1].sprite, 0x20, 0x5E);
}

// argument evaluation order (a2 before a1)
#ifdef NON_MATCHING
void func_800FBCB8_BobsledRun(omObjData* obj) {
    s8 p = D_800FF2A8_BobsledRun[0].player[1];

    func_800FB594_BobsledRun(obj, D_800C59AC[GwPlayer[p].character].unk_00, D_800C59AC[GwPlayer[p].character].unk_04, p,
                             0);
    func_800184BC(obj, 0);
    func_80018D84(D_800FF2A8_BobsledRun[0].sprite2, 9);
    SetBasicSpritePos(D_800FF2A8_BobsledRun[0].sprite2, 0x16, 0x5A);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_BobsledRun/188410", func_800FBCB8_BobsledRun);
#endif

// argument evaluation order (a2 before a1)
#ifdef NON_MATCHING
void func_800FBD5C_BobsledRun(omObjData* obj) {
    s8 p = D_800FF2A8_BobsledRun[1].player[1];

    func_800FB594_BobsledRun(obj, D_800C59AC[GwPlayer[p].character].unk_00, D_800C59AC[GwPlayer[p].character].unk_04, p,
                             1);
    func_800184BC(obj, 0);
    func_80018D84(D_800FF2A8_BobsledRun[1].sprite2, 7);
    SetBasicSpritePos(D_800FF2A8_BobsledRun[1].sprite2, 0x16, 0x5E);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_BobsledRun/188410", func_800FBD5C_BobsledRun);
#endif

/* Tilt the sled (rot.x / rot.z) towards the ground normal. */
void func_800FBE04_BobsledRun(omObjData* obj, Vec3f* normal) {
    BRWork* work;
    f32 rx;
    f32 rz;
    f32 cx;
    f32 cz;

    work = obj->unk_50;
    rx = -(func_800B0CD8(normal->y, normal->z) - 90.0f);
    rz = func_800B0CD8(normal->y, normal->x) - 90.0f;
    cx = work->unk_90;
    cz = work->unk_98;
    if (cx < rx) {
        work->unk_90 += 0.8f;
        if (rx < work->unk_90) {
            work->unk_90 = rx;
        }
    } else if (rx < cx) {
        work->unk_90 -= 0.8f;
        if (work->unk_90 < rx) {
            work->unk_90 = rx;
        }
    }
    if (cz < rz) {
        work->unk_98 += 0.8f;
        if (rz < work->unk_98) {
            work->unk_98 = rz;
        }
    } else if (rz < cz) {
        work->unk_98 -= 0.8f;
        if (work->unk_98 < rz) {
            work->unk_98 = rz;
        }
    }
    obj->rot.x = work->unk_90;
    obj->rot.z = work->unk_98;
}

/* Rotation of angle about axis, translated (ovl_11's func_800FA1D8_BowlOver; retail uses pos->z
   where pos->x would be expected). */
void func_800FBF88_BobsledRun(Mat4 m, Vec3f* pos, Vec3f* axis, f32 angle) {
    f32 s;
    f32 c;
    f32 t;
    f32 x;
    f32 y;
    f32 z;
    f32 xx;
    f32 yy;
    f32 zz;
    f32 xs;
    f32 ys;
    f32 zs;
    f32 xy;
    f32 xz;
    f32 yz;
    f32 txy;
    f32 txz;
    f32 tyz;
    f32 py;
    f32 pz;

    func_800AF2E0(angle, &s, &c);
    t = 1.0f - c;
    pz = pos->z;
    py = pos->y;
    x = axis->x;
    y = axis->y;
    z = axis->z;
    xy = x * y;
    yz = y * z;
    xz = z * x;
    xx = x * x;
    yy = y * y;
    zz = z * z;
    xs = x * s;
    ys = y * s;
    zs = z * s;
    m[3][3] = 1.0f;
    m[0][3] = m[1][3] = m[2][3] = 0.0f;
    m[0][0] = t * xx + c;
    txy = t * xy;
    m[0][1] = txy + zs;
    txz = t * xz;
    m[0][2] = txz - ys;
    m[1][0] = txy - zs;
    m[1][1] = t * yy + c;
    tyz = t * yz;
    m[1][2] = tyz + xs;
    m[2][0] = txz + ys;
    m[2][1] = tyz - xs;
    m[2][2] = t * zz + c;
    m[3][0] = pz * t * (1.0f - xx) + py * (zs - txy) - pz * (txz + ys);
    m[3][1] = -pz * (txy + zs) + py * t * (1.0f - yy) + pz * (xs - tyz);
    m[3][2] = pz * (ys - txz) - py * (tyz + xs) + pz * t * (1.0f - zz);
}

/* omOutViewMulti with each camera rolled by D_800FF340[i]. */
// the 350.0f near-plane constant is hoisted out of the loop
#ifdef NON_MATCHING
void func_800FC180_BobsledRun(omObjData* obj) {
    Vec3f pos;
    Vec3f target;
    Vec3f up;
    Mat4 m;
    Vec3f dir;
    f32 rx;
    f32 ry;
    f32 near;
    f32 zero;
    f32 one;
    u8 i;

    one = 1.0f;
    zero = 0.0f;
    for (i = 0; i < obj->work[0]; i++) {
        near = 350.0f;
        if (BR_WORK(D_800F3FB0[i])->unk_53 == 5) {
            near = 700.0f;
        }
        rx = CRotM[i].x;
        ry = CRotM[i].y;
        pos.x = func_800AEAC0(ry) * func_800AEFD0(rx) * CZoomM[i] + CenterM[i].x;
        pos.y = -func_800AEAC0(rx) * CZoomM[i] + CenterM[i].y;
        pos.z = func_800AEFD0(ry) * func_800AEFD0(rx) * CZoomM[i] + CenterM[i].z;
        target.x = CenterM[i].x;
        target.y = CenterM[i].y;
        target.z = CenterM[i].z;
        dir.x = target.x - pos.x;
        dir.y = target.y - pos.y;
        dir.z = target.z - pos.z;
        func_8002956C(&dir);
        func_800FBF88_BobsledRun(m, &target, &dir, D_800FF340_BobsledRun[i]);
        up.x = zero * m[0][0] + one * m[1][0];
        up.y = zero * m[0][1] + one * m[1][1];
        up.z = zero * m[0][2] + one * m[1][2];
        func_8002956C(&up);
        D_800F2C28[i].x = pos.x;
        D_800F2C28[i].z = pos.z;
        D_800F2C28[i].rot = CRotM[i].y;
        D_800F2C28[i].unk_0C = D_800C3110[i].unk_40;
        D_800F2C28[i].far = 20000.0f;
        D_800F2C28[i].near = near * 20.0f;
        func_8001D420(i, &pos, &target, &up);
        func_8001D57C(i);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_BobsledRun/188410", func_800FC180_BobsledRun);
#endif

/* Boost pads (ground 6) and the catch-up bonus for the team behind. */
// the other team's index is multiplied with sll/addu in retail (negu/andi here)
#ifdef NON_MATCHING
void func_800FC4D0_BobsledRun(BRWork* work) {
    f32 bonus;
    f32 me;
    f32 other;
    s32 team;
    s32 o;
    f32 f;

    bonus = 0.0f;
    if (work->unk_53 == 6) {
        D_800FF2A8_BobsledRun[work->unk_58].boost = 150;
        func_80060540(0x29F, work->unk_58);
    }
    team = work->unk_58;
    o = team == 0;
    me = D_800FF2A8_BobsledRun[team].progress;
    other = D_800FF2A8_BobsledRun[o].progress;
    if (me < other && other - me > 0.001f) {
        bonus = 5.0f;
    }
    if (D_800FF2A8_BobsledRun[work->unk_58].boost != 0) {
        f = 150 - D_800FF2A8_BobsledRun[work->unk_58].boost;
        D_800B8980 = f + 80.0f;
        work->unk_48 = f + 100.0f;
        D_800FF2A8_BobsledRun[work->unk_58].boost--;
        if (D_800B8980 > 100.0f) {
            D_800B8980 = 100.0f;
        }
        if (work->unk_48 > 120.0f) {
            work->unk_48 = 120.0f;
        }
        if (D_800FF2A8_BobsledRun[work->unk_58].unk32 == 0) {
            func_80060F04(D_800FF2A8_BobsledRun[work->unk_58].player[0], 10, 0, 10);
            func_80060F04(D_800FF2A8_BobsledRun[work->unk_58].player[1], 10, 0, 10);
        }
        D_800FF2A8_BobsledRun[work->unk_58].unk32 = 1;
        return;
    }
    if (bonus + 80.0f < work->unk_40) {
        D_800B8980 = work->unk_40 * 0.98f;
    } else {
        D_800B8980 = bonus + 80.0f;
    }
    if (work->unk_48 > 100.0f) {
        work->unk_48 = work->unk_48 * 0.98f;
    }
    if (work->unk_48 < bonus + 100.0f) {
        work->unk_48 = bonus + 100.0f;
    }
    D_800FF2A8_BobsledRun[work->unk_58].unk32 = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_BobsledRun/188410", func_800FC4D0_BobsledRun);
#endif

/* Race state from the ground under the sled: 1 start ramp, 5 crash zone, else racing / goal. */
// register allocation
#ifdef NON_MATCHING
void func_800FC7DC_BobsledRun(omObjData* obj) {
    BRWork* work;
    s8 r;

    work = obj->unk_50;
    if (work->unk_53 == 1) {
        D_800FF2A8_BobsledRun[work->unk_58].state = 0;
        return;
    }
    if (work->unk_53 == 5) {
        D_800FF2A8_BobsledRun[work->unk_58].state = 2;
        return;
    }
    if (D_800FF2A8_BobsledRun[work->unk_58].timer > 40) {
        D_800FF2A8_BobsledRun[work->unk_58].state = 3;
        r = -2;
        if (D_800FF2A1_BobsledRun == -1) {
            r = work->unk_58;
        }
        D_800FF2A1_BobsledRun = r;
        PlaySound(0x2A0);
        func_80060618(0x45F, D_800FF2A8_BobsledRun[work->unk_58].player[0]);
        func_80060618(0x45F, D_800FF2A8_BobsledRun[work->unk_58].player[1]);
        return;
    }
    D_800FF2A8_BobsledRun[work->unk_58].state = 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_BobsledRun/188410", func_800FC7DC_BobsledRun);
#endif

/* Teams from the players' groups. */
void func_800FC918_BobsledRun(void) {
    s32 t;
    s32 i;

    for (t = 0; t < 2; t++) {
        for (i = 0; i < 4; i++) {
            if (t == GwPlayer[i].group) {
                if (D_800FF2A8_BobsledRun[t].player[0] < 0) {
                    D_800FF2A8_BobsledRun[t].player[0] = i;
                    D_800FF2A8_BobsledRun[t].port[0] = GwPlayer[i].port;
                } else if (D_800FF2A8_BobsledRun[t].player[1] < 0) {
                    D_800FF2A8_BobsledRun[t].player[1] = i;
                    D_800FF2A8_BobsledRun[t].port[1] = GwPlayer[i].port;
                }
            }
        }
    }
}

void func_800FC9F8_BobsledRun(void) {
    s32 i;

    D_800FF9E0_BobsledRun.idx = 0;
    D_800FF8E8_BobsledRun.idx = 0;
    for (i = 0; i < 20; i++) {
        D_800FF9E0_BobsledRun.samples[i] = D_800FF8E8_BobsledRun.samples[i] = 0.0f;
    }
}

/* Running mean of the last 20 values (the camera roll). */
f32 func_800FCA48_BobsledRun(s32 team, f32 value) {
    BRHist* h;
    f32 sum;
    s32 i;

    h = &D_800FF9E0_BobsledRun;
    if (team == 0) {
        h = &D_800FF8E8_BobsledRun;
    }
    h->samples[h->idx++] = value;
    if (h->idx >= 20) {
        h->idx = 0;
    }
    sum = 0.0f;
    for (i = 0; i < 20; i++) {
        sum += h->samples[i];
    }
    return sum / 20.0f;
}

/* Mean of the last six stick samples, packed (x << 16) | y. */
// register allocation (masked 0, raw 15): x/i swap a0/a1; tried shift/mask reads, declaration order (M1c)
#ifdef NON_MATCHING
s32 func_800FCAC0_BobsledRun(omObjData* obj) {
    BRWork* work;
    s32 x;
    u8 i;
    s32 y;

    work = obj->unk_50;
    y = 0;
    x = 0;
    for (i = 0; i < 6; i++) {
        x += ((s16*)&work->unk_6C[i])[0];
        y = ((u16*)&work->unk_6C[i])[1] + y;
    }
    x = (s16)x / 6;
    y = (s16)y / 6;
    return (x << 16) | (y & 0xFFFF);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_BobsledRun/188410", func_800FCAC0_BobsledRun);
#endif

/* Which track sections each team's camera draws (by progress). */
void func_800FCB44_BobsledRun(void) {
    s32 bits[2];
    omObjData* g;
    omObjData* sled;
    f32 lo;
    f32 hi;
    f32 p;
    s32 i;
    s32 t;
    s16 mask;

    bits[0] = 1;
    bits[1] = 2;
    for (i = 0; i < 6; i++) {
        g = D_800F2AF8[i];
        mask = 0;
        lo = D_800FF358_BobsledRun[i];
        hi = D_800FF370_BobsledRun[i];
        for (t = 0; t < 2; t++) {
            sled = D_800F3FB0[t];
            p = D_800FF2A8_BobsledRun[t].progress;
            if ((lo <= p) & (p < hi)) {
                if (D_800FF2A8_BobsledRun[t].progress < 50.0f) {
                    func_800090C4(sled, i, 2);
                    mask |= bits[t];
                }
            } else {
                func_800090C4(sled, i, 1);
            }
        }
        func_80025F10(g->model[0], mask);
    }
}

/* Turn by turn, glancing off walls the sled faces into. */
// register allocation
#ifdef NON_MATCHING
void func_800FCCE8_BobsledRun(omObjData* obj, Vec3f* normal, f32 turn) {
    BRWork* work;
    s32 team;
    f32 a;
    f32 s;
    f32 dot;

    work = obj->unk_50;
    team = work->unk_58;
    work->unk_3C = turn + work->unk_3C;
    a = work->unk_3C - 90.0f;
    s = func_800AEAC0(a);
    dot = func_8000A72C(normal->x, normal->z, s, func_800AEFD0(a));
    if (dot > 0.7f) {
        work->unk_3C = work->unk_3C - (turn + 1.0f);
    } else if (dot < -0.7f) {
        work->unk_3C = (f32)(fabs(turn) + 1.0) + work->unk_3C;
    }
    work->unk_3C = func_80029518(work->unk_3C);
    D_800FF2A8_BobsledRun[team].unk08 = dot;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_BobsledRun/188410", func_800FCCE8_BobsledRun);
#endif

/* Time display m:ss"cc (frames at 60 per second). */
void func_800FCE2C_BobsledRun(s16 idx, s16 time) {
    s16 g;
    s16 d;
    s16 sec;
    s16 cs;

    g = D_800FFAE4_BobsledRun[idx];
    func_80067480(g, 0, 0x8000);
    d = time / 3600;
    func_800672DC(g, 0, d, 0);
    func_800672B0(g, 0, 1);
    time -= d * 3600;
    func_80067480(g, 1, 0x8000);
    func_800672DC(g, 1, 10, 0);
    func_800672B0(g, 1, 1);
    func_80067480(g, 2, 0x8000);
    d = time / 600;
    func_800672DC(g, 2, d, 0);
    func_800672B0(g, 2, 1);
    time -= d * 600;
    sec = time / 60;
    func_80067480(g, 3, 0x8000);
    func_800672DC(g, 3, sec, 0);
    func_800672B0(g, 3, 1);
    cs = time * 100 / 60 - sec * 100;
    func_80067480(g, 4, 0x8000);
    func_800672DC(g, 4, 11, 0);
    func_800672B0(g, 4, 1);
    func_80067480(g, 5, 0x8000);
    func_800672DC(g, 5, cs / 10, 0);
    func_800672B0(g, 5, 1);
    cs %= 10;
    func_80067480(g, 6, 0x8000);
    func_800672DC(g, 6, cs, 0);
    func_800672B0(g, 6, 1);
}

void func_800FD124_BobsledRun(void) {
    void* data;

    data = DataRead(0x87);
    D_800FFAE0_BobsledRun = func_800678A4(data);
    DataClose(data);
}

void func_800FD164_BobsledRun(void) {
    void* data;

    data = DataRead(0x87);
    D_800FFAE2_BobsledRun = func_800678A4(data);
    DataClose(data);
    func_8001897C(D_800FFAE2_BobsledRun, 0.0f, 1.0f, 0.0f);
}

s16 func_800FD1BC_BobsledRun(s32 x, s32 y) {
    s16 g;
    s32 px;
    s16 i;

    g = D_800FFAE4_BobsledRun[0] = func_80064EF4(7, 5);
    func_80067208(g, 0, D_800FFAE0_BobsledRun, 0);
    func_80067480(g, 0, 0xFFFF);
    func_800674BC(g, 0, 0x8000);
    func_80066DC4(g, 0, x - 16, y);
    func_80067384(g, 0, 1);
    px = 4;
    for (i = 1; i < 7; i++) {
        func_80067384(g, i, 1);
        func_80067208(g, i, D_800FFAE0_BobsledRun, 0);
        func_80066DC4(g, i, px, 0);
        func_80067480(g, i, 0xFFFF);
        func_800674BC(g, i, 0x8000);
        if (i == 3) {
            px += 8;
        } else {
            px += 12;
        }
        func_80067598(g, i, 0);
    }
    func_80067480(g, 2, 0x8000);
    return g;
}

// register allocation; the group id is stored before its copy
#ifdef NON_MATCHING
void func_800FD36C_BobsledRun(s32 x, s32 y) {
    s32 g;
    s32 px;
    s16 i;

    /* retail's func_80064EF4 returned a full int (no extension before the store) */
    g = ((s32(*)(s32, s32))func_80064EF4)(7, 5);
    D_800FFAE4_BobsledRun[1] = g;
    func_80067208(g, 0, D_800FFAE2_BobsledRun, 0);
    func_80067480(g, 0, 0xFFFF);
    func_800674BC(g, 0, 0x8000);
    func_80066DC4(g, 0, x - 16, y);
    func_80067384(g, 0, 1);
    px = 4;
    for (i = 1; i < 7; i++) {
        func_80067384(g, i, 1);
        func_80067208(g, i, D_800FFAE2_BobsledRun, 0);
        func_80066DC4(g, i, px, 0);
        func_80067480(g, i, 0xFFFF);
        func_800674BC(g, i, 0x8000);
        if (i == 3) {
            px += 8;
        } else {
            px += 12;
        }
        func_80067598(g, i, 0);
    }
    func_80067480(g, 2, 0x8000);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_BobsledRun/188410", func_800FD36C_BobsledRun);
#endif

/* The bobsled's process: CPU riders write the shared controls, the tunnels swap in the dark
   models, then func_800F78F4 runs; the riders' real inputs are restored afterwards. */
void func_800FD51C_BobsledRun(omObjData* obj) {
    s32 team;
    s32 p0;
    s32 p1;
    s32 btn0;
    s32 trg0;
    s32 sx0;
    s32 sy0;
    s32 btn1;
    s32 trg1;
    s32 sx1;
    s32 sy1;
    s32 a;
    s32 b;
    unk2C0C0StructB8* anim;

    team = BR_WORK(obj)->unk_58;
    p0 = D_800FF2A8_BobsledRun[team].port[0];
    p1 = D_800FF2A8_BobsledRun[team].port[1];
    trg0 = ContBtnTrg[p0];
    btn0 = ContBtn[p0];
    sx0 = ContStkX[p0];
    sy0 = ContStkY[p0];
    trg1 = ContBtnTrg[p1];
    btn1 = ContBtn[p1];
    sx1 = ContStkX[p1];
    sy1 = ContStkY[p1];
    switch (D_800ED430) {
        case 0 ... 1:
            a = D_800FF2A8_BobsledRun[team].player[0];
            b = D_800FF2A8_BobsledRun[team].player[1];
            if (GwPlayer[a].flags & 1) {
                ContStkY[p0] = 0;
                ContStkX[p0] = 0;
                ContBtnTrg[p0] = 0;
                ContBtn[p0] = 0;
                func_800FA484_BobsledRun(obj, a, p0);
            }
            if (GwPlayer[b].flags & 1) {
                ContStkY[p1] = 0;
                ContStkX[p1] = 0;
                ContBtnTrg[p1] = 0;
                ContBtn[p1] = 0;
                func_800FA484_BobsledRun(obj, b, p1);
            }
            if (D_800FF2A8_BobsledRun[team].anim == 4) {
                if (D_800FF388_BobsledRun[0] > obj->trans.y && D_800FF388_BobsledRun[1] < obj->trans.y) {
                    if (obj->model[0] != D_800FF2A8_BobsledRun[team].mdl[4]) {
                        obj->model[0] = D_800FF2A8_BobsledRun[team].mdl[4];
                        func_800258EC(D_800FF2A8_BobsledRun[team].mdl[1], 4, 4);
                        func_800258EC(D_800FF2A8_BobsledRun[team].mdl[4], 4, 0);
                        func_800185A4(obj, 0);
                        obj->model[4] = D_800FF2A8_BobsledRun[team].mdl[7];
                        func_800258EC(D_800FF2A8_BobsledRun[team].mdl[6], 4, 4);
                        func_800258EC(D_800FF2A8_BobsledRun[team].mdl[7], 4, 0);
                        obj->model[3] = D_800FF2A8_BobsledRun[team].mdl[9];
                        func_800258EC(D_800FF2A8_BobsledRun[team].mdl[8], 4, 4);
                        func_800258EC(D_800FF2A8_BobsledRun[team].mdl[9], 4, 0);
                        func_80025CA8(D_800FF2A8_BobsledRun[team].mdl[9],
                                      func_80025D18(D_800FF2A8_BobsledRun[team].mdl[8]));
                        anim = D_800F2B7C[D_800FF2A8_BobsledRun[team].mdl[9]].unk_6C->unk_B8;
                        anim->unk_08 = D_800F2B7C[D_800FF2A8_BobsledRun[team].mdl[8]].unk_6C->unk_B8->unk_08;
                    }
                } else if (D_800FF390_BobsledRun[0] > obj->trans.y && D_800FF390_BobsledRun[1] < obj->trans.y) {
                    if (obj->model[0] != D_800FF2A8_BobsledRun[team].mdl[4]) {
                        obj->model[0] = D_800FF2A8_BobsledRun[team].mdl[4];
                        func_800258EC(D_800FF2A8_BobsledRun[team].mdl[1], 4, 4);
                        func_800258EC(D_800FF2A8_BobsledRun[team].mdl[4], 4, 0);
                        func_800185A4(obj, 0);
                        obj->model[4] = D_800FF2A8_BobsledRun[team].mdl[7];
                        func_800258EC(D_800FF2A8_BobsledRun[team].mdl[6], 4, 4);
                        func_800258EC(D_800FF2A8_BobsledRun[team].mdl[7], 4, 0);
                        obj->model[3] = D_800FF2A8_BobsledRun[team].mdl[9];
                        func_800258EC(D_800FF2A8_BobsledRun[team].mdl[8], 4, 4);
                        func_800258EC(D_800FF2A8_BobsledRun[team].mdl[9], 4, 0);
                        func_80025CA8(D_800FF2A8_BobsledRun[team].mdl[9],
                                      func_80025D18(D_800FF2A8_BobsledRun[team].mdl[8]));
                        anim = D_800F2B7C[D_800FF2A8_BobsledRun[team].mdl[9]].unk_6C->unk_B8;
                        anim->unk_08 = D_800F2B7C[D_800FF2A8_BobsledRun[team].mdl[8]].unk_6C->unk_B8->unk_08;
                    }
                } else if (obj->model[0] == D_800FF2A8_BobsledRun[team].mdl[4]) {
                    obj->model[0] = D_800FF2A8_BobsledRun[team].mdl[1];
                    func_800258EC(D_800FF2A8_BobsledRun[team].mdl[1], 4, 0);
                    func_800258EC(D_800FF2A8_BobsledRun[team].mdl[4], 4, 4);
                    func_800185A4(obj, 0);
                    obj->model[4] = D_800FF2A8_BobsledRun[team].mdl[6];
                    func_800258EC(D_800FF2A8_BobsledRun[team].mdl[6], 4, 0);
                    func_800258EC(D_800FF2A8_BobsledRun[team].mdl[7], 4, 4);
                    obj->model[3] = D_800FF2A8_BobsledRun[team].mdl[8];
                    func_800258EC(D_800FF2A8_BobsledRun[team].mdl[8], 4, 0);
                    func_800258EC(D_800FF2A8_BobsledRun[team].mdl[9], 4, 4);
                    func_80025CA8(D_800FF2A8_BobsledRun[team].mdl[8],
                                  func_80025D18(D_800FF2A8_BobsledRun[team].mdl[9]));
                    anim = D_800F2B7C[D_800FF2A8_BobsledRun[team].mdl[8]].unk_6C->unk_B8;
                    anim->unk_08 = D_800F2B7C[D_800FF2A8_BobsledRun[team].mdl[9]].unk_6C->unk_B8->unk_08;
                }
            }
            /* fallthrough */
        case 2 ... 3:
            func_800F78F4_BobsledRun(obj);
            break;
    }
    ContBtnTrg[p0] = trg0;
    ContBtn[p0] = btn0;
    ContStkX[p0] = sx0;
    ContStkY[p0] = sy0;
    ContBtnTrg[p1] = trg1;
    ContBtn[p1] = btn1;
    ContStkX[p1] = sx1;
    ContStkY[p1] = sy1;
}

/* Snow spray from the runners (model[3]) and its sliding sound. */
void func_800FDCA8_BobsledRun(omObjData* obj, s16 force, f32 minSpeed, f32 rot, f32 x, f32 y, f32 z) {
    BRWork* work;
    s32 mdl;
    f32 s;
    f32 a;
    unk2C0C0StructB8* anim;

    work = obj->unk_50;
    mdl = obj->model[3];
    if (force >= 21 && minSpeed < work->unk_40) {
        x += D_800FF8D0_BobsledRun[work->unk_58].x * 220.0f;
        y += D_800FF8D0_BobsledRun[work->unk_58].y * 220.0f;
        z += D_800FF8D0_BobsledRun[work->unk_58].z * 220.0f;
        s = work->unk_40 / 100.0f;
        if (s > 1.0f) {
            s = 1.0f;
        }
        a = (2.0f * force) / 60.0f;
        if (a > 2.0f) {
            a = 2.0f;
        }
        D_800F2B7C[mdl].unk_4C = a;
        func_800258EC(mdl, 4, 0);
        func_80025798(mdl, x, y + 30.0f, z);
        func_800257E4(mdl, 0.0f, rot, 0.0f);
        func_80025830(mdl, s, s, s);
        if (work->unk_58 == 0) {
            if (D_800FF350_BobsledRun == -1) {
                D_800FF350_BobsledRun = func_80060540(0x299, work->unk_56);
            }
        } else if (D_800FF354_BobsledRun == -1) {
            D_800FF354_BobsledRun = func_80060540(0x299, work->unk_56);
        }
    } else {
        if (func_80025D18(mdl) > 32.0f) {
            func_800258EC(mdl, 4, 4);
            func_80025CA8(mdl, 0.0f);
            anim = D_800F2B7C[mdl].unk_6C->unk_B8;
            if (anim != NULL) {
                anim->unk_08 = 0.0f;
            }
        }
        if (work->unk_58 == 0) {
            if (D_800FF350_BobsledRun != -1) {
                func_8006071C((s16)D_800FF350_BobsledRun);
                D_800FF350_BobsledRun = -1;
            }
        } else if (D_800FF354_BobsledRun != -1) {
            func_8006071C((s16)D_800FF354_BobsledRun);
            D_800FF354_BobsledRun = -1;
        }
    }
}

/* Loop the spray animation (model mdl) back to frame 32. */
void func_800FDFC8_BobsledRun(s32 team, u8 mdl) {
    f32 cur;
    unk2C0C0StructB8* anim;

    if (mdl != 0) {
        cur = func_80025D18(mdl);
        if (func_80025D40(mdl) <= cur) {
            func_80025CA8(mdl, 32.0f);
            anim = D_800F2B7C[mdl].unk_6C->unk_B8;
            if (anim != NULL) {
                anim->unk_08 = anim->unk_04 * 0.6f;
            }
        }
    }
}

/* The bobsled after the crash zone or the goal: the winner slides to a stop, the loser spins out. */
// trans.z kept in an integer register, delay-slot fill of the jump arc
#ifdef NON_MATCHING
void func_800FE080_BobsledRun(omObjData* obj) {
    BRWork* work;
    omObjData* o;
    s32 team;
    f32 x;
    f32 y;
    f32 z;
    f32 spin;
    f32 speed;
    f32 h;
    f32 nx;
    f32 nz;
    f32 roll;
    f32 sp;
    f32 cy;
    f32 d;
    f32 v;
    f32 f;

    work = obj->unk_50;
    team = work->unk_58;
    x = obj->trans.x;
    y = obj->trans.y;
    z = obj->trans.z;
    spin = D_800ED6B8 = D_800F5254 = 0.0f;
    if (D_800FF2A0_BobsledRun == team) {
        speed = work->unk_40;
        spin = -D_800FF2A8_BobsledRun[team].roll * 3.0f;
        if (speed != D_800B8990) {
            speed -= D_800FF2A8_BobsledRun[team].roll * 0.06f;
            if (speed < 1.0f) {
                work->unk_40 = D_800B8990;
                speed = D_800B8990;
            }
            work->unk_40 = speed;
        }
        h = func_800F93C0_BobsledRun(obj, work->unk_3C, x, y, z);
        if (h != 65536.0f) {
            y = h;
            func_800FDCA8_BobsledRun(obj, 100, 60.0f, spin + work->unk_3C, x, h, z);
        }
        x = x + (func_800AEAC0(work->unk_3C) * speed + D_800ED6B8);
        z = z + (func_800AEFD0(work->unk_3C) * speed + D_800F5254);
        func_8009ECB0(D_800F2B7C[obj->model[0]].unk7C, 0.0f, spin + work->unk_3C, 0.0f);
        func_8009ECB0(D_800F2B7C[obj->model[4]].unk7C, 0.0f, spin + work->unk_3C, 0.0f);
        func_800257E4(obj->model[4], obj->rot.x, obj->rot.y, obj->rot.z);
        D_800FF8D0_BobsledRun[team].x = func_800AEAC0(work->unk_3C + 180.0f - spin);
        D_800FF8D0_BobsledRun[team].y = 0.0f;
        D_800FF8D0_BobsledRun[team].z = func_800AEFD0(work->unk_3C + 180.0f - spin);
        func_8002956C(&D_800FF8D0_BobsledRun[team]);
        func_800093FC(obj, x, y, z);
        func_80025798(obj->model[4], x, y, z);
        roll = D_800FF2A8_BobsledRun[team].roll;
        cy = 200.0f - (roll * 5.0f + (sp = work->unk_40)) + obj->trans.y;
        CRotM[team].y = work->unk_3C + roll + 180.0f;
        d = 2.0f * sp;
        CenterM[team].x = obj->trans.x - func_800AEAC0(work->unk_3C) * d;
        CenterM[team].z = obj->trans.z - func_800AEFD0(work->unk_3C) * d;
        if (d != 0.0f) {
            CenterM[team].y = cy;
            CZoomM[team] = work->unk_40 + 300.0f + D_800FF2A8_BobsledRun[team].roll;
        }
        D_800FF2A8_BobsledRun[team].roll *= 1.15f;
        if (D_800FF2A8_BobsledRun[team].roll > 30.0f) {
            func_800184BC(obj, 13);
            D_800FF2A8_BobsledRun[team].anim = 5;
            D_800FF2A8_BobsledRun[team].roll = 30.0f;
        }
    } else {
        speed = work->unk_40;
        switch (D_800FF2A8_BobsledRun[team].anim) {
            case 6:
                v = work->unk_38;
                if (D_800B8994 < v) {
                    v = D_800B8994;
                }
                v = v * v;
                if (work->unk_38 >= 0.0f) {
                    f = v * -35.0f;
                } else {
                    f = v * 35.0f;
                }
                y += f;
                if (!(work->unk_50 & 0x80)) {
                    work->unk_38 += 0.16f;
                    if (D_800B8964 * 0.6f <= work->unk_38) {
                        work->unk_50 |= 0x80;
                        work->unk_38 = -D_800B8964 * 0.6f;
                    }
                } else {
                    work->unk_38 += 0.16f;
                    if (D_800B8964 * 0.6f <= work->unk_38) {
                        D_800FF2A8_BobsledRun[team].anim = 7;
                        work->unk_40 = D_800B8990;
                        func_800184BC(obj, 14);
                        work->unk_3C = work->unk_3C + -240.0f;
                    }
                }
                break;
            case 7:
                break;
            default:
                roll = D_800FF2A8_BobsledRun[team].roll;
                spin = -roll;
                if (speed != D_800B8990) {
                    if (roll < 8.0f) {
                        if (D_800FF2A0_BobsledRun != -1) {
                            o = D_800F3FB0[D_800FF2A0_BobsledRun];
                        } else if (team != 0) {
                            o = D_800F3FB0[0];
                        } else {
                            o = D_800F3FB0[1];
                        }
                        if (o->trans.z < obj->trans.z) {
                            work->unk_3C = work->unk_3C + D_800FF2A8_BobsledRun[team].roll;
                        } else {
                            work->unk_3C = work->unk_3C - D_800FF2A8_BobsledRun[team].roll;
                        }
                    }
                    speed -= D_800FF2A8_BobsledRun[team].roll * 0.02f;
                    if (speed < 1.0f) {
                        work->unk_40 = D_800B8990;
                        speed = D_800B8990;
                    }
                    work->unk_40 = speed;
                }
                h = func_800F93C0_BobsledRun(obj, work->unk_3C, x, y, z);
                if (h != 65536.0f) {
                    y = h;
                    if (D_800B8956 != 0) {
                        func_800258EC(obj->model[0], 4, 4);
                        obj->model[0] = D_800FF2A8_BobsledRun[team].mdl[0];
                        func_800258EC(obj->model[0], 4, 0);
                        func_800184BC(obj, 9);
                        work->unk_3C = work->unk_3C + 60.0f;
                        work->unk_40 = -14.0f;
                        work->unk_38 = -D_800B8964 * 0.6f;
                        D_800FF2A8_BobsledRun[team].anim = 6;
                    }
                }
                break;
        }
        func_800FDCA8_BobsledRun(obj, 30, 50.0f, work->unk_3C - spin, x, y, z);
        x = x + (func_800AEAC0(work->unk_3C) * speed + D_800ED6B8);
        z = z + (func_800AEFD0(work->unk_3C) * speed + D_800F5254);
        func_8009ECB0(D_800F2B7C[obj->model[0]].unk7C, 0.0f, work->unk_3C, 0.0f);
        D_800FF8D0_BobsledRun[team].x = func_800AEAC0(work->unk_3C + 180.0f);
        D_800FF8D0_BobsledRun[team].y = 0.0f;
        D_800FF8D0_BobsledRun[team].z = func_800AEFD0(work->unk_3C + 180.0f);
        func_8002956C(&D_800FF8D0_BobsledRun[team]);
        func_800093FC(obj, x, y, z);
        if (D_800FF2A8_BobsledRun[team].anim == 4) {
            func_8009ECB0(D_800F2B7C[obj->model[4]].unk7C, 0.0f, work->unk_3C, 0.0f);
            func_800257E4(obj->model[4], obj->rot.x, obj->rot.y, obj->rot.z);
            func_80025798(obj->model[4], x, y, z);
            cy = 200.0f - (D_800FF2A8_BobsledRun[team].roll * 3.0f + (sp = work->unk_40)) + obj->trans.y;
            CRotM[team].y = work->unk_3C + 180.0f;
            d = 2.0f * sp;
            CenterM[team].x = obj->trans.x - func_800AEAC0(work->unk_3C) * d;
            CenterM[team].z = obj->trans.z - func_800AEFD0(work->unk_3C) * d;
            if (d != 0.0f) {
                CenterM[team].y = cy;
                CZoomM[team] = work->unk_40 + 300.0f + D_800FF2A8_BobsledRun[team].roll * 3.0f;
            }
        } else if (D_800FF2A8_BobsledRun[team].anim == 6) {
            D_800F2B7C[obj->model[4]].unk_28 = obj->trans.y;
        }
        D_800FF2A8_BobsledRun[team].roll = D_800FF2A8_BobsledRun[team].roll * 1.07;
        if (D_800FF2A8_BobsledRun[team].roll > 40.0f) {
            D_800FF2A8_BobsledRun[team].roll = 40.0f;
        }
    }
    func_80017DB0(obj);
    func_800FDFC8_BobsledRun(team, obj->model[3]);
    func_800FB858_BobsledRun(obj);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_BobsledRun/188410", func_800FE080_BobsledRun);
#endif

/* The back rider: follows its sled and plays the requested animation. */
void func_800FEC80_BobsledRun(omObjData* obj) {
    s32 team;
    omObjData* sled;
    BRWork* sw;
    f32 rot;
    f32 dist;
    f32 t;

    sw = obj->unk_50;
    team = sw->unk_58;
    if (team == 0) {
        sled = D_800F3FB0[0];
    } else {
        sled = D_800F3FB0[1];
    }
    sw = sled->unk_50;
    rot = sw->unk_3C;
    switch (D_800FF2A8_BobsledRun[team].anim) {
        case 2:
            func_800184BC(obj, 6);
            break;
        case 3:
            func_800258EC(obj->model[0], 4, 4);
            obj->model[0] = D_800FF2A8_BobsledRun[team].mdl[3];
            func_800258EC(obj->model[0], 4, 0);
            func_800186E4(obj, 0x23, 0);
            func_800184BC(obj, 0);
            break;
        case 1:
            func_800184BC(obj, 1);
            break;
        case 5:
            func_800184BC(obj, 13);
            break;
        case 6:
            func_800258EC(D_800FF2A8_BobsledRun[team].mdl[3], 4, 4);
            obj->model[0] = D_800FF2A8_BobsledRun[team].mdl[2];
            func_800258EC(obj->model[0], 4, 0);
            func_800184BC(obj, 9);
            obj->trans.y = sled->trans.y;
        default:
            break;
        case 7:
            obj->trans.y = sled->trans.y;
            func_800184BC(obj, 14);
            break;
        case 4:
            if (D_800FF388_BobsledRun[0] > obj->trans.y && D_800FF388_BobsledRun[1] < obj->trans.y) {
                obj->model[0] = D_800FF2A8_BobsledRun[team].mdl[5];
                func_800258EC(D_800FF2A8_BobsledRun[team].mdl[3], 4, 4);
                func_800258EC(D_800FF2A8_BobsledRun[team].mdl[5], 4, 0);
            } else if (D_800FF390_BobsledRun[0] > obj->trans.y && D_800FF390_BobsledRun[1] < obj->trans.y) {
                obj->model[0] = D_800FF2A8_BobsledRun[team].mdl[5];
                func_800258EC(D_800FF2A8_BobsledRun[team].mdl[3], 4, 4);
                func_800258EC(D_800FF2A8_BobsledRun[team].mdl[5], 4, 0);
            } else {
                obj->model[0] = D_800FF2A8_BobsledRun[team].mdl[3];
                func_800258EC(D_800FF2A8_BobsledRun[team].mdl[3], 4, 0);
                func_800258EC(D_800FF2A8_BobsledRun[team].mdl[5], 4, 4);
            }
            break;
    }
    if (D_800FF2A8_BobsledRun[team].state == 2 && D_800FF2A0_BobsledRun == team) {
        rot -= D_800FF2A8_BobsledRun[team].roll * 4.0f;
    }
    if (D_800FF2A8_BobsledRun[team].anim >= 6) {
        obj->trans.x += func_800AEAC0(sw->unk_3C + 200.0f) * sw->unk_40;
        obj->trans.z += func_800AEFD0(sw->unk_3C + 200.0f) * sw->unk_40;
        func_8009ECB0(D_800F2B7C[obj->model[0]].unk7C, 0.0f, rot, 0.0f);
    } else {
        dist = -80.0f;
        if (D_800FF2A8_BobsledRun[team].anim == 2) {
            t = func_80025E70(obj->model[0]);
            if (t == -1.0f) {
                t = func_80025D18(obj->model[0]);
            }
            dist = t + -120.0f;
            if (dist < -80.0f) {
                dist = -80.0f;
            }
        } else if (D_800FF2A8_BobsledRun[team].anim < 2) {
            dist = -120.0f;
        }
        obj->trans.x = func_800AEAC0(rot) * dist + sled->trans.x;
        obj->trans.y = sw->unk_84.y * 10.0f + sled->trans.y;
        obj->trans.z = func_800AEFD0(rot) * dist + sled->trans.z;
        obj->rot.x = sw->unk_90;
        obj->rot.z = sw->unk_98;
        func_8009ECB0(D_800F2B7C[obj->model[0]].unk7C, 0.0f, rot, 0.0f);
        if (D_800FF2A8_BobsledRun[sw->unk_58].timer > 40) {
            obj->func_ptr = NULL;
            func_800258EC(obj->model[0], 4, 4);
        }
    }
    func_80017DB0(obj);
    func_800FB93C_BobsledRun(obj);
}
