#include "common.h"
#include "HotBobOmb.h"

/* .data 0x800FA3C0..0x800FA5D0 */
s32 D_800FA3C0_HotBobOmb[5][25] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 1, 1, 1, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 1, 1, 1, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 0, 0 },
};
s32 D_800FA5B4_HotBobOmb[4] = { 0, 0, 0, 0 };

void func_800F8FA0_HotBobOmb(void) {
    D_800FA8CC_HotBobOmb = 0;
    D_800FA8EC_HotBobOmb = InitSprite(0x76);
    D_800FA990_HotBobOmb = func_80019060(D_800FA8EC_HotBobOmb, 2, 1);
    func_80018CF8(D_800FA990_HotBobOmb, 0);
    func_80018C90(D_800FA990_HotBobOmb);
    D_800FA9B6_HotBobOmb = func_80019060(D_800FA8EC_HotBobOmb, 1, 1);
    func_80018C90(D_800FA9B6_HotBobOmb);
}

void func_800F902C_HotBobOmb(void) {
    s32 i;
    s32 coins;
    s32 gain;

    switch (D_800FA8CC_HotBobOmb) {
    case 0:
        func_800601D4(0x1C);
        D_800FA920_HotBobOmb = 30;
        D_800FA8CC_HotBobOmb++;
        break;
    case 1:
        if (--D_800FA920_HotBobOmb < 0) {
            GMesCreate(2);
            if (_CheckFlag(0x2B) != 0) {
                func_800601D4(0x28);
            }
            D_800FA920_HotBobOmb = 18;
            D_800FA8CC_HotBobOmb++;
        }
        break;
    case 2:
        if (GMesStatAllGet() == 2) {
            if (_CheckFlag(0x2B) == 0) {
                func_80060128(0x34);
                func_80025BB8(D_800FA8D8_HotBobOmb[D_800FA8B0_HotBobOmb]->model[0],
                              D_800FA8D8_HotBobOmb[D_800FA8B0_HotBobOmb]->motion[7]);
                func_80025BB8(D_800FA8D8_HotBobOmb[(D_800FA8B0_HotBobOmb + 1) % 4]->model[0],
                              D_800FA8D8_HotBobOmb[(D_800FA8B0_HotBobOmb + 1) % 4]->motion[5]);
                func_80025BB8(D_800FA8D8_HotBobOmb[(D_800FA8B0_HotBobOmb + 2) % 4]->model[0],
                              D_800FA8D8_HotBobOmb[(D_800FA8B0_HotBobOmb + 2) % 4]->motion[5]);
                func_80025BB8(D_800FA8D8_HotBobOmb[(D_800FA8B0_HotBobOmb + 3) % 4]->model[0],
                              D_800FA8D8_HotBobOmb[(D_800FA8B0_HotBobOmb + 3) % 4]->motion[5]);
                D_800FA8CC_HotBobOmb++;
            } else {
                D_800FA8CC_HotBobOmb = 5;
            }
        }
        break;
    case 3:
        if (--D_800FA920_HotBobOmb < 0) {
            D_800FA8CC_HotBobOmb += 2;
        }
        break;
    case 4:
        D_800FA8CC_HotBobOmb++;
        break;
    case 5:
        if (_CheckFlag(0x2B) == 0) {
            GMesCreate(5, GwPlayer[D_800FA8B0_HotBobOmb].character);
            PlaySound(GwPlayer[D_800FA8B0_HotBobOmb].character + 0x44A);
        }
        gain = 5;
        coins = GwPlayer[D_800FA8B0_HotBobOmb].coins;
        if (coins < 15) {
            GwPlayer[D_800FA8B0_HotBobOmb].coins_mg = -coins;
        } else {
            GwPlayer[D_800FA8B0_HotBobOmb].coins_mg = -15;
        }
        for (i = 0; i < 4; i++) {
            if (i != D_800FA8B0_HotBobOmb) {
                GwPlayer[i].coins_mg += gain;
            }
        }
        D_800FA920_HotBobOmb = 0x70;
        if (_CheckFlag(0x2B) == 0) {
            D_800FA8CC_HotBobOmb++;
        } else {
            D_800FA8CC_HotBobOmb = 8;
        }
        break;
    case 6:
        if (--D_800FA920_HotBobOmb < 0) {
            func_800726AC(0, 0x14);
            if (_CheckFlag(0x2B) != 0) {
                func_80060398(0x28);
            }
            D_800FA8CC_HotBobOmb++;
        }
        break;
    case 7:
        if (func_80072718() == 0) {
            omOvlReturnEx(1);
        }
        break;
    case 8:
        if (GMesWait() == 0) {
            func_800726AC(0, 0x14);
            D_800FA8CC_HotBobOmb = 7;
        }
        break;
    }
}

void func_800F94AC_HotBobOmb(void) {
    func_800F8FA0_HotBobOmb();
    D_800FA988_HotBobOmb = 2;
    D_800FA98C_HotBobOmb = 0x8000;
    D_800FA9A0_HotBobOmb = 0x4000;
    D_800FA99C_HotBobOmb = 0;
    D_800FA998_HotBobOmb = 0;
    D_800FA8B8_HotBobOmb[0] = 1;
    D_800FA8B8_HotBobOmb[1] = 0;
    D_800FA8B8_HotBobOmb[2] = 0;
    D_800FA8B8_HotBobOmb[3] = 0;
    D_800FA880_HotBobOmb[0] = GwPlayer[0].port;
    D_800FA880_HotBobOmb[1] = GwPlayer[1].port;
    D_800FA880_HotBobOmb[2] = GwPlayer[2].port;
    D_800FA880_HotBobOmb[3] = GwPlayer[3].port;
    D_800FA9BC_HotBobOmb = D_800FA9A8_HotBobOmb = func_800F680C_HotBobOmb() % 211 + 390;
    D_800FA194_HotBobOmb = D_800FA9A8_HotBobOmb / 15;
    D_800FA924_HotBobOmb = 0;
    D_800FA8A0_HotBobOmb[0] = 0;
    D_800FA8A0_HotBobOmb[1] = 0;
    D_800FA8A0_HotBobOmb[2] = 0;
    D_800FA8A0_HotBobOmb[3] = 0;
    D_800FA89C_HotBobOmb = 1;
    D_800FA8E8_HotBobOmb = 90;
    D_800FA9B8_HotBobOmb = 0;
    D_800FA994_HotBobOmb = 0;
    D_800FA8D0_HotBobOmb = 0;
}

// register allocation, table load in v1 not v0 (masked 0, raw 2); tried early returns, else-if, ret reuse
#ifdef NON_MATCHING
s32 func_800F9610_HotBobOmb(s32 player) {
    s32 n;
    s32 temp;
    s32 ret;

    n = D_800FA8A0_HotBobOmb[player];
    if (n <= 0 && D_800FA924_HotBobOmb <= 0) {
        ret = 1;
    } else {
        temp = D_800FA8D0_HotBobOmb;
        ret = 0;
        if (temp == 0) {
            temp = D_800FA3C0_HotBobOmb[D_800FA994_HotBobOmb][n];
            ret = temp != 0;
        }
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_07_HotBobOmb/10F6D0", func_800F9610_HotBobOmb);
#endif

void func_800F9690_HotBobOmb(void) {
    s32 i;

    if (--D_800FA9BC_HotBobOmb <= 0 && D_800FA99C_HotBobOmb == D_800FA998_HotBobOmb) {
        D_800FA8C8_HotBobOmb = 4;
        D_800FA8B0_HotBobOmb = D_800FA99C_HotBobOmb;
    }
    /* retail's order: only the first two tests can be taken */
    if (D_800FA9BC_HotBobOmb < 150) {
        D_800FA994_HotBobOmb = 4;
    } else if (D_800FA9BC_HotBobOmb < 120) {
        D_800FA994_HotBobOmb = 3;
    } else if (D_800FA9BC_HotBobOmb < 90) {
        D_800FA994_HotBobOmb = 2;
    } else if (D_800FA9BC_HotBobOmb < 45) {
        D_800FA994_HotBobOmb = 1;
    } else {
        D_800FA994_HotBobOmb = 0;
    }
    for (i = 0; i < 4; i++) {
        if (D_800FA8A0_HotBobOmb[i] > 0) {
            D_800FA8A0_HotBobOmb[i]--;
        }
    }
    if (D_800FA924_HotBobOmb > 0) {
        if (--D_800FA924_HotBobOmb == 0) {
            D_800FA8A0_HotBobOmb[D_800FA998_HotBobOmb] = 25;
            D_800FA8D0_HotBobOmb = 0;
            D_800FA99C_HotBobOmb = D_800FA998_HotBobOmb;
        }
    }
    if (D_800FA8A0_HotBobOmb[D_800FA99C_HotBobOmb] <= 0) {
        D_800FA8D0_HotBobOmb = 0;
    }
}

void func_800F9814_HotBobOmb(s32 port) {
    s32 d;

    d = 2;
    switch (GwPlayer[port].cpu_difficulty) {
    case 1:
        break;
    case 0:
        d = 1;
        break;
    case 3:
        d = 4;
        break;
    case 2:
        d = 3;
        break;
    }
    if (rand8() % (d * 2) == 0 || D_800FA5B4_HotBobOmb[port] == d * 2) {
        ContBtn[port] |= 0x8000;
        ContBtnTrg[port] |= 0x8000;
        D_800FA5B4_HotBobOmb[port] = 0;
    }
    ContStkX[port] = ((u8)(rand8() % 3) - 1) * 50;
    ContStkY[port] = ((u8)(rand8() % 3) - 1) * 50;
    D_800FA5B4_HotBobOmb[port]++;
}

// sign tests: GCC if-converts dy/dx = +-1 to slti/negu/ori where retail branches (masked 20, raw 59); tried if/else, the s8 parameters directly
#ifdef NON_MATCHING
s32 func_800F99F4_HotBobOmb(s8 arg0, s8 arg1) {
    s32 x;
    s32 y;
    s32 ax;
    s32 ay;
    s32 dx;
    s32 dy;

    x = arg0;
    y = arg1;
    ax = x;
    if (ax < 0) {
        ax = -ax;
    }
    ay = y;
    if (ay < 0) {
        ay = -ay;
    }
    if (ay < ax) {
        if (ax / 2 >= ay) {
            dy = 0;
        } else {
            dy = 1;
            if (y <= 0) {
                dy = -1;
            }
        }
        if (x > 10) {
            dx = 1;
        } else {
            dx = -(x < -10);
        }
    } else {
        if (ay / 2 >= ax) {
            dx = 0;
        } else {
            dx = 1;
            if (x <= 0) {
                dx = -1;
            }
        }
        if (y > 10) {
            dy = 1;
        } else {
            dy = -(y < -10);
        }
    }
    return (dy + 1) * 3 + 1 + dx;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_07_HotBobOmb/10F6D0", func_800F99F4_HotBobOmb);
#endif

void func_800F9AB8_HotBobOmb(s32 player) {
    s32 passA[4] = { 0x4000, 0x8000, 0x8000, 0x4000 };
    s32 passB[4] = { 0x8000, 0x4000, 0x4000, 0x8000 };
    s32 dirs[4][9] = {
        { 3, 3, 2, 3, 2, 1, 3, 1, 1 },
        { 3, 3, 2, 0, 3, 2, 0, 0, 2 },
        { 3, 3, 3, 3, 0, 1, 0, 1, 1 },
        { 2, 2, 2, 0, 1, 2, 0, 0, 1 },
    };
    s32 kind[4][4] = {
        { -1, 0, 2, 1 },
        { 1, -1, 0, 2 },
        { 2, 1, -1, 0 },
        { 0, 2, 1, -1 },
    };
    s32 r;
    s32 t;

    r = func_800F9610_HotBobOmb(player);
    D_800FA89C_HotBobOmb = r;
    if (D_800FA8C8_HotBobOmb != 3) {
        return;
    }
    if (D_800FA99C_HotBobOmb != player) {
        return;
    }
    if (r == 1) {
        if (GwPlayer[player].flags & 1) {
            func_800F9814_HotBobOmb(D_800FA880_HotBobOmb[player]);
        }
        if (ContBtnTrg[D_800FA880_HotBobOmb[player]] & 0x8000) {
            D_800FA8B8_HotBobOmb[player] = 0;
            D_800FA8E8_HotBobOmb = 90;
            t = dirs[player][func_800F99F4_HotBobOmb(ContStkX[D_800FA880_HotBobOmb[player]],
                                                     ContStkY[D_800FA880_HotBobOmb[player]])];
            D_800FA8B8_HotBobOmb[t] = 1;
            D_800FA998_HotBobOmb = t;
            D_800FA924_HotBobOmb = 18 - D_800FA994_HotBobOmb;
            D_800FA988_HotBobOmb = kind[player][t];
            D_800FA9A0_HotBobOmb = passA[player];
            D_800FA98C_HotBobOmb = passB[player];
            D_800FA8A0_HotBobOmb[player] = 0;
            return;
        }
        D_800FA8E8_HotBobOmb--;
    }
}

/* Zero tail of .rodata: retail pads the unit to 16 bytes here. */
const s32 D_800FA858_HotBobOmb[2] = { 0, 0 };
