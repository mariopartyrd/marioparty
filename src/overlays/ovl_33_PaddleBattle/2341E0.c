#include "PaddleBattle.h"

/* .data (0x800FE1F0..0x800FE210) */
s16 D_800FE1F0_PaddleBattle = 0;
PBRange D_800FE1F4_PaddleBattle[3] = { { 280, 380 }, { 650, 760 }, { 1400, 1600 } };
f32 D_800FE200_PaddleBattle = 0.0f;

/* Minigame setup. */
void func_800F65E0_PaddleBattle(void) {
    u8 cam;
    s16 i;

    func_80029090(0x32);
    func_8002ADF0(&D_800EDEC0, 0x40);
    func_8001DE70(0x20);
    omInitObjMan(0x32, 0);
    func_80060088();
    D_800FFF00_PaddleBattle = _CheckFlag(0x2B) != 0;
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    func_800178A0(1);
    cam = func_800178E8();
    func_80017660(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 50.0f, 80.0f, 4000.0f);
    func_80028510(0x3DD, 0x3E8, 0xF0, 0xF8, 0xFF);
    func_80023448(2);
    func_800234B8(0, 0x30, 0x30, 0x30);
    func_800234B8(2, 0xFF, 0xFF, 0xFF);
    func_80023504(1, 0.0f, 0.0f, -100.0f);
    func_80023504(2, 0.0f, 100.0f, 25.0f);
    D_800FFF02_PaddleBattle.state = 0;
    D_800FFF02_PaddleBattle.timer = 0;
    D_800FFF02_PaddleBattle.unk2 = 0;
    D_800FFF02_PaddleBattle.timer2 = 0;
    D_800ED430 = 0;
    D_800FF34E_PaddleBattle = -1;
    D_800FF34A_PaddleBattle = -1;
    D_800FF34C_PaddleBattle = -1;
    func_800F732C_PaddleBattle();
    D_800FF340_PaddleBattle = 0;
    D_800ED430 = 1;
    for (i = 0; i < 4; i++) {
        D_800FF342_PaddleBattle[i] = GwPlayer[i].coins;
        D_80100130_PaddleBattle[i] = 0;
    }
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    func_800090B8(0);
    omAddObj(0x20, 0, 0, -1, func_800F687C_PaddleBattle);
    func_800FBAE0_PaddleBattle();
    func_800F7380_PaddleBattle();
}

void func_800F687C_PaddleBattle(omObjData* obj) {
    obj->func_ptr = func_800F695C_PaddleBattle;
    omSetStatBit(obj, 0xA0);
    func_8007B168((u8*)"\x82\x72\x82\x73\x82\x60\x82\x71\x82\x73", 1);
}

void func_800F68B4_PaddleBattle(omObjData* obj) {
    if (func_80072718() == 0) {
        func_800F7310_PaddleBattle();
        omOvlReturnEx(1);
    }
}

/* Adds `n` coins to `player` (refused if it would go below 0); returns the new count or -1. */
s16 func_800F68E8_PaddleBattle(s16 player, s16 n) {
    player &= 3;
    if (n < 0 && D_800FF342_PaddleBattle[player] + n < 0) {
        return -1;
    }
    D_800FF342_PaddleBattle[player] += n;
    D_80100130_PaddleBattle[player] += n;
    return D_800FF342_PaddleBattle[player];
}

/* The game flow: start, race, result, exit. */
// logic-equivalent; register allocation and instruction order differ (normalised diff 37 lines)
#ifdef NON_MATCHING
void func_800F695C_PaddleBattle(omObjData* obj) {
    s32 best;
    s32 i;
    s32 win;
    s32 exit;

    if (func_8005FD5C() + D_800F64F8 != 0) {
        return;
    }
    switch (D_800FFF02_PaddleBattle.state) {
    case 0:
        switch (D_800FFF02_PaddleBattle.timer) {
        case 2:
            SetFadeInTypeAndTime(0, 0x10);
            break;
        case 8:
            func_80060128(0x22);
            break;
        case 30:
            GMesCreate(0);
            break;
        case 82:
            D_800FFF02_PaddleBattle.state = 1;
            D_800FFF02_PaddleBattle.timer = -1;
            D_800ED430 = 1;
            D_800FE1F0_PaddleBattle = 0;
            break;
        }
        break;
    case 1:
        if (D_800FFF10_PaddleBattle.dist >= 1980.0f) {
            D_800FFF02_PaddleBattle.state = 2;
            D_800FFF02_PaddleBattle.timer = -1;
            D_800ED430 = 2;
            GMesCreate(2);
            func_800601D4(0x5A);
        }
        if (++D_800FFF02_PaddleBattle.timer2 >= 0x7800) {
            D_800FFF02_PaddleBattle.timer2 -= 0x800;
        }
        break;
    case 2:
        if (GMesStatAllGet() == 2) {
            best = D_80100130_PaddleBattle[D_800FFF10_PaddleBattle.seat[0]];
            for (i = 1; i < 4; i++) {
                if (D_80100130_PaddleBattle[D_800FFF10_PaddleBattle.seat[i]] >= best) {
                    break;
                }
            }
            if (i < 4) {
                win = 0;
            } else {
                win = 1;
                if (best >= 10) {
                    D_800FE1F0_PaddleBattle = 0x24;
                }
            }
            if (D_800FFF00_PaddleBattle == 0) {
                func_80060128(win ? 0x32 : 0x36);
            }
            for (i = 0; i < 4; i++) {
                D_800FFFA0_PaddleBattle[D_800FFF10_PaddleBattle.seat[i]].obj->work[3] = win;
                if (i == 0) {
                    win = (1 - win) & ((s32)(D_80100130_PaddleBattle[D_800FFF10_PaddleBattle.seat[0]] << 16) >> 31);
                }
                GwPlayer[i].coins_mg += D_80100130_PaddleBattle[i];
            }
            D_800FFF02_PaddleBattle.state = 3;
            D_800FFF02_PaddleBattle.timer = -1;
            D_800ED430 = 3;
        }
        break;
    case 3:
        exit = 0;
        if (D_800FFF00_PaddleBattle != 0) {
            exit = D_800FFF02_PaddleBattle.timer == 60;
        } else {
            if (D_800FFF02_PaddleBattle.timer == 105) {
                exit = 1;
            }
            if (D_800FE1F0_PaddleBattle != 0 && --D_800FE1F0_PaddleBattle == 0) {
                func_80060468(0x451, GwPlayer[D_800FFF10_PaddleBattle.seat[0]].character);
            }
        }
        if (exit) {
            D_800FF340_PaddleBattle = 1;
            func_800726AC(0, 0x14);
            func_80060398(0x28);
        }
        break;
    }
    if (++D_800FFF02_PaddleBattle.timer >= 0x7800) {
        D_800FFF02_PaddleBattle.timer -= 0x800;
    }
    if (D_800F5144 == 1) {
        D_800FF340_PaddleBattle = 1;
        if (D_800FFF00_PaddleBattle == 0) {
            func_800601D4(0x5A);
        }
    }
    if (D_800FF340_PaddleBattle != 0) {
        func_800F68B4_PaddleBattle(obj);
    }
    func_800F6DB0_PaddleBattle();
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_33_PaddleBattle/2341E0", func_800F695C_PaddleBattle);
#endif

/* Water and paddle sounds. */
// logic-equivalent; register allocation and instruction order differ (normalised diff 88 lines)
#ifdef NON_MATCHING
void func_800F6DB0_PaddleBattle(void) {
    s32 i;
    s32 d;
    s32 vol;
    f32 v;
    f32 w;
    f64 l;

    if (D_800FFF02_PaddleBattle.state == 1 && D_800FFF02_PaddleBattle.timer >= 31) {
        D_800FE200_PaddleBattle += 0.05;
        if (D_800FE200_PaddleBattle > 1.0) {
            D_800FE200_PaddleBattle = 1.0f;
        }
    } else {
        D_800FE200_PaddleBattle -= 0.1;
        if (D_800FE200_PaddleBattle < 0.0) {
            D_800FE200_PaddleBattle = 0.0f;
        }
    }
    if (D_800FE200_PaddleBattle > 0.0) {
        if (D_800FF34C_PaddleBattle < 0) {
            D_800FF34C_PaddleBattle = PlaySound(0x365);
            if (D_800FF34C_PaddleBattle >= 0) {
                func_8006035C(D_800FF34C_PaddleBattle, 0);
            }
        }
        if (D_800FF34A_PaddleBattle < 0) {
            D_800FF34A_PaddleBattle = PlaySound(0x366);
            if (D_800FF34A_PaddleBattle >= 0) {
                func_8006035C(D_800FF34A_PaddleBattle, 0);
            }
        }
    }
    switch (D_800FFF02_PaddleBattle.timer & 3) {
    case 0:
        w = func_800FAE48_PaddleBattle(D_800FFF10_PaddleBattle.dist);
        l = 0.5 - D_800FFF10_PaddleBattle.lateral;
        if (l < 0.0) {
            l += 0.35;
        } else {
            l = 0.35 - (0.5 - D_800FFF10_PaddleBattle.lateral);
        }
        vol = 127.0 - (f32)(l * w) / 700.0 * 40.0;
        if (vol < 90) {
            vol = 90;
        } else if (vol > 127) {
            vol = 127;
        }
        func_80060214(vol * D_800FE200_PaddleBattle + (1.0 - D_800FE200_PaddleBattle) * 127.0);
        break;
    case 1:
        vol = D_800FFF10_PaddleBattle.lateral * 127.0f;
        if (vol > 127) {
            vol = 127;
        } else if (vol < 0) {
            vol = 0;
        }
        if (D_800FF34A_PaddleBattle >= 0) {
            func_8006035C(D_800FF34A_PaddleBattle, vol * D_800FE200_PaddleBattle);
        }
        vol = (1.0 - D_800FFF10_PaddleBattle.lateral) * 127.0;
        if (vol > 127) {
            vol = 127;
        } else if (vol < 0) {
            vol = 0;
        }
        if (D_800FF34C_PaddleBattle >= 0) {
            func_8006035C(D_800FF34C_PaddleBattle, vol * D_800FE200_PaddleBattle);
        }
        break;
    case 2:
        v = 0.0f;
        d = D_800FFF10_PaddleBattle.dist;
        for (i = 0; i < 3; i++) {
            if (D_800FE1F4_PaddleBattle[i].start - 200 < d && d < D_800FE1F4_PaddleBattle[i].end + 200) {
                v = 1.0f;
                if (D_800FE1F4_PaddleBattle[i].start < d) {
                    if (d >= D_800FE1F4_PaddleBattle[i].end) {
                        v = 1.0f - (d - D_800FE1F4_PaddleBattle[i].end) / 198.0;
                    }
                } else {
                    v = (d - D_800FE1F4_PaddleBattle[i].start) / 198.0 + 1.0f;
                }
                break;
            }
        }
        vol = v * 127.0f;
        if (vol > 0) {
            if (D_800FF34E_PaddleBattle < 0) {
                D_800FF34E_PaddleBattle = PlaySound(0x367);
                if (D_800FF34E_PaddleBattle < 0) {
                    break;
                }
            }
            func_8006035C(D_800FF34E_PaddleBattle, vol);
        } else {
            if (D_800FF34E_PaddleBattle >= 0) {
                func_8006071C(D_800FF34E_PaddleBattle);
            }
            D_800FF34E_PaddleBattle = -1;
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_33_PaddleBattle/2341E0", func_800F6DB0_PaddleBattle);
#endif

void func_800F7310_PaddleBattle(void) {
    func_800FBBD8_PaddleBattle();
}

void func_800F732C_PaddleBattle(void) {
    D_800FF352_PaddleBattle = 0;
    D_800FF350_PaddleBattle = 0;
    CZoom = 2000.0f;
    CRot.x = 0.0f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    Center.x = 0.0f;
    Center.y = 0.0f;
    Center.z = 0.0f;
}
