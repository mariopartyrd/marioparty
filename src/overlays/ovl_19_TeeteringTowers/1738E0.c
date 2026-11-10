#include "common.h"
#include "TeeteringTowers.h"

/* .data (0x800FA930..0x800FADD0) */
s32 D_800FA930_TeeteringTowers = 0;
s32 D_800FA934_TeeteringTowers = 0;
s32 D_800FA938_TeeteringTowers = 0;
s32 D_800FA93C_TeeteringTowers = 0xFFFF;
s32 D_800FA940_TeeteringTowers = 0;
s32 D_800FA944_TeeteringTowers = 0;
s32 D_800FA948_TeeteringTowers = 0;
s32 D_800FA94C_TeeteringTowers = 0; /* unreferenced */
s32 D_800FA950_TeeteringTowers = 0; /* unreferenced */
s32 D_800FA954_TeeteringTowers = 0;
UnkTeeteringTowers0 D_800FA958_TeeteringTowers[] = {
    { 4, 0, func_800F7EE4_TeeteringTowers, { 0.0f, 250.0f, -6350.5f }, { 0, 0, 0 } },
    { 2, 0, func_800F6C58_TeeteringTowers, { 0.0f, 50.0f, 400.0f }, { 0, 0, 0 } },
    { 1, 0, func_800F6CE4_TeeteringTowers, { 0.0f, 50.0f, -977.0f }, { 0, 0, 0 } },
    { 1, 0, func_800F6CE4_TeeteringTowers, { -1150.0f, -150.0f, -1954.0f }, { 0, 0, 0 } },
    { 1, 0, func_800F6CE4_TeeteringTowers, { 0.0f, -150.0f, -1954.0f }, { 0, 0, 0 } },
    { 1, 0, func_800F6CE4_TeeteringTowers, { 1150.0f, -150.0f, -1954.0f }, { 0, 0, 0 } },
    { 1, 0, func_800F6CE4_TeeteringTowers, { -2300.0f, -350.0f, -2931.0f }, { 0, 0, 0 } },
    { 1, 0, func_800F6CE4_TeeteringTowers, { -1150.0f, -350.0f, -2931.0f }, { 0, 0, 0 } },
    { 1, 0, func_800F6CE4_TeeteringTowers, { 0.0f, -350.0f, -2931.0f }, { 0, 0, 0 } },
    { 1, 0, func_800F6CE4_TeeteringTowers, { 1150.0f, -350.0f, -2931.0f }, { 0, 0, 0 } },
    { 1, 0, func_800F6CE4_TeeteringTowers, { 2300.0f, -350.0f, -2931.0f }, { 0, 0, 0 } },
    { 1, 0, func_800F6CE4_TeeteringTowers, { -1725.0f, -550.0f, -3908.0f }, { 0, 0, 0 } },
    { 1, 1, func_800F6CE4_TeeteringTowers, { -575.0f, -550.0f, -3908.0f }, { 0, 0, 0 } },
    { 1, 1, func_800F6CE4_TeeteringTowers, { 575.0f, -550.0f, -3908.0f }, { 0, 0, 0 } },
    { 1, 0, func_800F6CE4_TeeteringTowers, { 1725.0f, -550.0f, -3908.0f }, { 0, 0, 0 } },
    { 1, 1, func_800F6CE4_TeeteringTowers, { -1150.0f, -750.0f, -4885.0f }, { 0, 0, 0 } },
    { 1, 1, func_800F6CE4_TeeteringTowers, { 0.0f, -750.0f, -4885.0f }, { 0, 0, 0 } },
    { 1, 1, func_800F6CE4_TeeteringTowers, { 1150.0f, -750.0f, -4885.0f }, { 0, 0, 0 } },
    { 1, 1, func_800F6CE4_TeeteringTowers, { -1725.0f, -950.0f, -5862.0f }, { 0, 0, 0 } },
    { 1, 1, func_800F6CE4_TeeteringTowers, { -575.0f, -950.0f, -5862.0f }, { 0, 0, 0 } },
    { 1, 1, func_800F6CE4_TeeteringTowers, { 575.0f, -950.0f, -5862.0f }, { 0, 0, 0 } },
    { 1, 1, func_800F6CE4_TeeteringTowers, { 1725.0f, -950.0f, -5862.0f }, { 0, 0, 0 } },
    { 1, 1, func_800F6CE4_TeeteringTowers, { -1150.0f, -1150.0f, -6839.0f }, { 0, 0, 0 } },
    { 1, 1, func_800F6CE4_TeeteringTowers, { 0.0f, -1150.0f, -6839.0f }, { 0, 0, 0 } },
    { 1, 1, func_800F6CE4_TeeteringTowers, { 1150.0f, -1150.0f, -6839.0f }, { 0, 0, 0 } },
    { 1, 1, func_800F6CE4_TeeteringTowers, { -575.0f, -1350.0f, -7816.0f }, { 0, 0, 0 } },
    { 1, 1, func_800F6CE4_TeeteringTowers, { 575.0f, -1350.0f, -7816.0f }, { 0, 0, 0 } },
    { 3, 0, func_800F6CA0_TeeteringTowers, { 0.0f, -1550.0f, -9193.0f }, { 0, 0, 0 } },
    { 0, 0, NULL, { 0.0f, 0.0f, 0.0f }, { 0, 0, 0 } },
};
s32 D_800FAD6C_TeeteringTowers = 0;
s32 D_800FAD70_TeeteringTowers[14] = { 1, 1, 2 };
s32 D_800FADA8_TeeteringTowers = 0xFF;
s32 D_800FADAC_TeeteringTowers = 0;
s32 D_800FADB0_TeeteringTowers = 0;
s32 D_800FADB4_TeeteringTowers = 0xB4;
s32 D_800FADB8_TeeteringTowers = 0;
s32 D_800FADBC_TeeteringTowers = -1;
s32 D_800FADC0_TeeteringTowers = 0;

void func_800F65E0_TeeteringTowers(void) {
    D_800FA930_TeeteringTowers = 0;
    D_800FA934_TeeteringTowers = 0;
    D_800FA938_TeeteringTowers = 0;
    func_800F6C20_TeeteringTowers();
    func_800F8E30_TeeteringTowers();
    func_80029090(0x32);
    func_8002ADF0(&D_800EDEC0, 0x40);
    func_8001DE70(0x20);
    omInitObjMan(0x32, 0);
    func_80060088();
    func_8000942C();
    func_8007B168((u8*)"\x82\x72\x82\x73\x82\x60\x82\x71\x82\x73", 1);
    func_8007B168((u8*)"\x82\x65\x82\x68\x82\x6D\x82\x68\x82\x72\x82\x67", 1);
    func_8007B168((u8*)"\x82\x6C\x82\x68\x82\x72\x82\x72\x81\x49", 1);
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    omAddObj(4, 0, 0, -1, &func_800F6748_TeeteringTowers);
    omAddObj(1, 0, 0, 1, &func_800F6780_TeeteringTowers);
    D_800FA934_TeeteringTowers = 0;
    D_800FA930_TeeteringTowers = 0;
    func_8002890C(0, 0, 0xA);
    func_800FA274_TeeteringTowers();
    func_800F7FF0_TeeteringTowers();
    func_800F7864_TeeteringTowers();
    func_800F8E3C_TeeteringTowers();
}

void func_800F6748_TeeteringTowers(omObjData* obj) {
    if (D_800F5144 == 1) {
        func_800601D4(0x28);
        omOvlReturnEx(1);
    }
}

// stack frame 8 bytes larger and one extra move in the coin clamp (register allocation, masked 2)
#ifdef NON_MATCHING
void func_800F6780_TeeteringTowers(omObjData* obj) {
    func_80009468();
    switch (D_800FA934_TeeteringTowers) {
    case 0:
        D_800FA934_TeeteringTowers = 1;
        SetFadeInTypeAndTime(0, 0x10);
        break;
    case 1:
        if (func_800F8EC8_TeeteringTowers() != 0) {
            D_800FA934_TeeteringTowers = 2;
        }
        break;
    case 2:
        func_80009458();
        switch (func_800F8E20_TeeteringTowers()) {
        case 1:
            D_800FA930_TeeteringTowers = 0;
            D_800FA934_TeeteringTowers = 3;
            break;
        case 2:
            func_80060618(0x45F, (s16)D_800FA938_TeeteringTowers);
            D_800FA934_TeeteringTowers = 4;
            break;
        }
        func_800FA62C_TeeteringTowers();
        break;
    case 3:
        func_800F99F4_TeeteringTowers();
        if (D_800FA930_TeeteringTowers == 1) {
            func_800601D4(0x28);
            func_800184BC(D_800FB270_TeeteringTowers, 0x11);
            TT_PLAYER(D_800FB270_TeeteringTowers)->unk_40 = 0.0f;
            TT_PLAYER(D_800FB270_TeeteringTowers)->unk_3C = 0.0f;
            GwPlayer[D_800FA938_TeeteringTowers].coins_mg += 10;
        } else if (D_800FA930_TeeteringTowers == 0x1E) {
            GMesCreate(2);
            if (_CheckFlag(0x2B) != 0) {
                D_800FA934_TeeteringTowers = 6;
                D_800FA930_TeeteringTowers = 0;
            }
        } else if (GMesStatAllGet() == 2 && D_800FA93C_TeeteringTowers == 0xFFFF && D_800FA930_TeeteringTowers >= 0x1F) {
            func_80060128(0x33);
            func_800184BC(D_800FB270_TeeteringTowers, 0xD);
            D_800FA93C_TeeteringTowers = D_800FA930_TeeteringTowers;
        } else if (D_800FA930_TeeteringTowers == D_800FA93C_TeeteringTowers + 0x24) {
            PlaySound(GwPlayer[D_800FA938_TeeteringTowers].character + 0x451);
        } else if (D_800FA93C_TeeteringTowers + 0x39 < D_800FA930_TeeteringTowers) {
            D_800FA930_TeeteringTowers = 0x1E;
            D_800FA934_TeeteringTowers = 5;
        }
        break;
    case 4:
        if (D_800FA93C_TeeteringTowers == 0xFFFF) {
            if (func_800FA080_TeeteringTowers() != 0) {
                func_800258EC(D_800FB270_TeeteringTowers->model[0], 4, 4);
                if (_CheckFlag(0x2B) != 0) {
                    GMesCreate(2);
                    D_800FA934_TeeteringTowers = 6;
                    D_800FA930_TeeteringTowers = 0;
                    break;
                }
                GMesCreate(0xE);
                D_800FA93C_TeeteringTowers = 0xFFFE;
            }
        }
        if (D_800FA93C_TeeteringTowers == 0xFFFE && GMesStatAllGet() == 2) {
            func_80060128(0x34);
            D_800FA934_TeeteringTowers = 5;
            D_800FA930_TeeteringTowers = 0;
            GwPlayer[D_800FA938_TeeteringTowers].coins_mg -= 5;
            if (GwPlayer[D_800FA938_TeeteringTowers].coins_mg + GwPlayer[D_800FA938_TeeteringTowers].coins < 0) {
                GwPlayer[D_800FA938_TeeteringTowers].coins_mg = -GwPlayer[D_800FA938_TeeteringTowers].coins;
            }
        }
        break;
    case 5:
        if (D_800FA930_TeeteringTowers >= 0x3D && D_800FA930_TeeteringTowers < 0x5A
            && (ContBtnTrg[TT_PLAYER(D_800FB270_TeeteringTowers)->unk_56] & 0x8000)) {
            func_800601D4(0x28);
            D_800FA930_TeeteringTowers = 0x5A;
        }
        if (D_800FA930_TeeteringTowers == 0x5A) {
            func_800726AC(0, 0x14);
        } else if (func_80072718() == 0 && D_800FA930_TeeteringTowers > 0x5A) {
            omOvlReturnEx(1);
        }
        break;
    case 6:
        if (GMesWait() == 0) {
            func_80060398(0x28);
            func_800726AC(0, 0x14);
            D_800FA934_TeeteringTowers = 7;
        }
        break;
    case 7:
        if (func_80072718() == 0) {
            omOvlReturnEx(1);
        }
        break;
    }
    D_800FA930_TeeteringTowers++;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_TeeteringTowers/1738E0", func_800F6780_TeeteringTowers);
#endif

void func_800F6C20_TeeteringTowers(void) {
    D_800FA954_TeeteringTowers = 0;
    D_800FA940_TeeteringTowers = 0;
    D_800FA944_TeeteringTowers = 0;
    D_800FA948_TeeteringTowers = 0;
}

//swap
void func_800F6C44_TeeteringTowers(s32* arg0, s32* arg1) {
    s32 temp_v1;

    temp_v1 = *arg0;
    *arg0 = *arg1;
    *arg1 = temp_v1;
}

void func_800F6C58_TeeteringTowers(omObjData* obj) {
    func_800258EC(obj->model[0], 4, 4);
    obj->trans.y = -10000.0f;
}

void func_800F6CA0_TeeteringTowers(omObjData* obj) {
    TTPlatformWork* work;

    if (D_800FA934_TeeteringTowers == 2) {
        work = TT_PLATFORM(obj);
        if (TT_PLAYER(D_800FB270_TeeteringTowers)->unk_53 == work->unk_05) {
            D_800FA940_TeeteringTowers = 1;
        }
    }
}

/* Retail's .rodata has 8 zero bytes after func_800F6780's jump table (its .s counts them in
   jtbl_800FB008); a C func_800F6780 needs `const s32 D_800FB028_TeeteringTowers[2] = { 0, 0 };`
   here for func_800F6CE4's table to stay at D_800FB030. */

/* The asm path's copy source for func_800F6CE4's shake table (the C path makes its own; the
   function's doubles are in its .s). */
#ifndef NON_MATCHING
const s8 D_800FB030_TeeteringTowers[33][2] = {
    { 2, 2 }, { 2, 2 }, { 2, 2 }, { 3, 3 }, { 3, 3 }, { 3, 4 }, { 4, 4 }, { 5, 5 }, { 6, 5 },
    { 5, 4 }, { 4, 4 }, { 3, 3 }, { 3, 3 }, { 3, 2 }, { 2, 2 }, { 2, 2 }, { 2, 2 }, { 2, 2 },
    { 2, 2 }, { 2, 3 }, { 3, 3 }, { 3, 3 }, { 4, 4 }, { 4, 5 }, { 5, 6 }, { 5, 5 }, { 4, 4 },
    { 4, 3 }, { 3, 3 }, { 3, 3 }, { 2, 2 }, { 2, 2 }, { 2, 2 },
};
#endif

/* A platform: shakes when the player lands on it, then tips over in the direction it was left
   (func_800F773C) and falls. */
// one callee-saved register fewer (frame 120 vs 128) and ten `trans -= const` sites load the
// field before the constant (register allocation / load order, masked ~40)
#ifdef NON_MATCHING
void func_800F6CE4_TeeteringTowers(omObjData* obj) {
    TTPlatformWork* work;
    s32 idx;
    omObjData* pl;
    TTPlayerWork* pw;
    s32 state;
    s32 n;
    f32 ang;

    if (D_800FA934_TeeteringTowers == 2) {
        work = TT_PLATFORM(obj);
        idx = work->unk_05;
        pl = D_800FB270_TeeteringTowers;
        pw = TT_PLAYER(pl);
        if (pw->unk_53 == idx && obj->work[0] == 0) {
            D_800FB274_TeeteringTowers = 1;
            obj->work[0] = 1;
            obj->work[1] = 0x3C;
            obj->work[2] = 0x1E;
        }
        if (obj->work[0] == 0) {
            return;
        }
        state = obj->work[0];
        if (obj->work[1] != 0) {
            s8 shake[33][2] = {
                { 2, 2 }, { 2, 2 }, { 2, 2 }, { 3, 3 }, { 3, 3 }, { 3, 4 }, { 4, 4 }, { 5, 5 }, { 6, 5 },
                { 5, 4 }, { 4, 4 }, { 3, 3 }, { 3, 3 }, { 3, 2 }, { 2, 2 }, { 2, 2 }, { 2, 2 }, { 2, 2 },
                { 2, 2 }, { 2, 3 }, { 3, 3 }, { 3, 3 }, { 4, 4 }, { 4, 5 }, { 5, 6 }, { 5, 5 }, { 4, 4 },
                { 4, 3 }, { 3, 3 }, { 3, 3 }, { 2, 2 }, { 2, 2 }, { 2, 2 },
            };

            n = obj->work[1];
            if ((n % 10 == 0) & (n != 0)) {
                func_80060F04((s16)D_800FA938_TeeteringTowers, 5, 0, 5);
            }
            ang = n * 45;
            obj->rot.x = func_800AEAC0(ang) * (shake[n % 30][0] + n / 15);
            obj->rot.z = func_800AEFD0(ang) * (shake[n % 30][0] + n / 15);
            if ((idx & 0xFE) == idx - 1) {
                obj->rot.x = -obj->rot.x;
                obj->rot.z = -obj->rot.z;
            }
            func_800257E4(obj->model[0], obj->rot.x, obj->rot.y, obj->rot.z);
            obj->work[1]--;
            if (obj->work[1] == 0) {
                obj->rot.x = 0.0f;
                obj->rot.z = 0.0f;
                func_80008FC4(obj, 30.0f);
                PlaySound(0x28C);
                obj->work[0] = func_800F773C_TeeteringTowers(obj->trans.x - pl->trans.x, obj->trans.z - pl->trans.z);
                if (obj->work[0] == 4) {
                    obj->work[2] = 0x1E;
                }
            }
        } else if ((n = obj->work[2]) != 0) {
            if (((n % 10 == 0) & (n != 0)) && pw->unk_53 == work->unk_05) {
                func_80060F04((s16)D_800FA938_TeeteringTowers, 5, 0, 5);
            }
            if (state == 1) {
                obj->rot.x -= 0.8333333f;
                func_800257E4(obj->model[0], obj->rot.x, obj->rot.y, obj->rot.z);
                func_800257E4(obj->model[1], obj->rot.x, obj->rot.y, obj->rot.z);
                obj->trans.z -= 15.0f;
                func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
                func_80025798(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
                if (D_800FA934_TeeteringTowers == 2) {
                    pl->trans.z -= 15.0f / 2.0;
                    func_80025798(pl->model[0], pl->trans.x, pl->trans.y, pl->trans.z);
                }
            } else if (state == 4) {
                obj->rot.x -= 0.8333333f;
                func_800257E4(obj->model[0], obj->rot.x, obj->rot.y, obj->rot.z);
                func_800257E4(obj->model[1], obj->rot.x, obj->rot.y, obj->rot.z);
                obj->trans.z -= 15.0f;
                func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
                func_80025798(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
                if (D_800FA934_TeeteringTowers == 2) {
                    pl->trans.z -= 15.0f / 2.0;
                    func_80025798(pl->model[0], pl->trans.x, pl->trans.y, pl->trans.z);
                }
            } else if (state == 2) {
                obj->rot.x -= 0.7f;
                obj->rot.y += 0.4f;
                func_800257E4(obj->model[0], obj->rot.x, obj->rot.y, obj->rot.z);
                func_800257E4(obj->model[1], obj->rot.x, obj->rot.y, obj->rot.z);
                obj->trans.x -= 7.6666665f;
                obj->trans.z -= 12.666667f;
                func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
                func_80025798(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
                if (D_800FA934_TeeteringTowers == 2) {
                    pl->trans.x -= 7.6666665f / 2.0;
                    pl->trans.z -= 12.666667f / 2.0;
                    func_80025798(pl->model[0], pl->trans.x, pl->trans.y, pl->trans.z);
                }
            } else if (state == 3) {
                obj->rot.x -= 0.7f;
                obj->rot.y -= 0.4f;
                func_800257E4(obj->model[0], obj->rot.x, obj->rot.y, obj->rot.z);
                func_800257E4(obj->model[1], obj->rot.x, obj->rot.y, obj->rot.z);
                obj->trans.x += 7.6666665f;
                obj->trans.z -= 12.666667f;
                func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
                func_80025798(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
                if (D_800FA934_TeeteringTowers == 2) {
                    pl->trans.x += 7.6666665f / 2.0;
                    pl->trans.z -= 12.666667f / 2.0;
                    func_80025798(pl->model[0], pl->trans.x, pl->trans.y, pl->trans.z);
                }
            } else if (state == 5) {
                obj->rot.x -= 0.78333336f;
                obj->rot.y += 0.2f;
                func_800257E4(obj->model[0], obj->rot.x, obj->rot.y, obj->rot.z);
                func_800257E4(obj->model[1], obj->rot.x, obj->rot.y, obj->rot.z);
                obj->trans.x -= 3.8333333f;
                obj->trans.z -= 13.833333f;
                func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
                func_80025798(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
                if (D_800FA934_TeeteringTowers == 2) {
                    pl->trans.x -= 3.8333333f / 2.0;
                    pl->trans.z -= 13.833333f / 2.0;
                    func_80025798(pl->model[0], pl->trans.x, pl->trans.y, pl->trans.z);
                }
            } else if (state == 6) {
                obj->rot.x -= 0.78333336f;
                obj->rot.y -= 0.2f;
                func_800257E4(obj->model[0], obj->rot.x, obj->rot.y, obj->rot.z);
                func_800257E4(obj->model[1], obj->rot.x, obj->rot.y, obj->rot.z);
                obj->trans.x += 3.8333333f;
                obj->trans.z -= 13.833333f;
                func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
                func_80025798(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
                if (D_800FA934_TeeteringTowers == 2) {
                    pl->trans.x += 3.8333333f / 2.0;
                    pl->trans.z -= 13.833333f / 2.0;
                    func_80025798(pl->model[0], pl->trans.x, pl->trans.y, pl->trans.z);
                }
            }
            obj->work[0] = func_800F773C_TeeteringTowers(obj->trans.x - pl->trans.x, obj->trans.z - pl->trans.z);
            obj->work[2]--;
        } else if (obj->work[3] < 150) {
            obj->work[3]++;
            obj->trans.y -= obj->work[3] * 2;
            func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
            func_80025798(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
        }
    } else if (D_800FA934_TeeteringTowers >= 3) {
        func_800258EC(obj->model[0], 4, 4);
        func_800258EC(obj->model[1], 4, 4);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_TeeteringTowers/1738E0", func_800F6CE4_TeeteringTowers);
#endif

u8 func_800F773C_TeeteringTowers(f32 x, f32 z) {
    u8 ret;

    if (x >= 50.0) {
        ret = 2;
    } else if (x <= -50.0) {
        ret = 3;
    } else if (z <= -50.0) {
        ret = 4;
    } else if (x >= 30.0) {
        ret = 5;
    } else if (x <= -30.0) {
        ret = 6;
    } else {
        ret = 1;
    }
    return ret;
}

/* Snaps the stick to the nearest of eight directions. */
// register allocation: retail negates the copies, not the loaded values (masked 0, raw 2; tried testing x, reordering, separate abs loads)
#ifdef NON_MATCHING
void func_800F77E4_TeeteringTowers(s8* sx, s8* sy) {
    s32 x = *sx;
    s32 y = *sy;
    s32 ax;
    s32 ay;

    ax = x;
    ay = y;
    if (ax < 0) {
        ax = -ax;
    }
    if (ay < 0) {
        ay = -ay;
    }
    if (ay < ax) {
        if (ax / 2 < ay) {
            if (y > 0) {
                y = ax;
            } else {
                y = -ax;
            }
        } else {
            y = 0;
        }
    } else {
        if (ay / 2 < ax) {
            if (x > 0) {
                x = ay;
            } else {
                x = -ay;
            }
        } else {
            x = 0;
        }
    }
    *sx = x;
    *sy = y;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_TeeteringTowers/1738E0", func_800F77E4_TeeteringTowers);
#endif

void func_800F7864_TeeteringTowers(void) {
    s32 i;
    //15 platforms total, dont include the starting one?
    for (i = 0; i < 14; i++) {
        //swap item between 2 platforms
        func_800F6C44_TeeteringTowers(&D_800FAD70_TeeteringTowers[i], &D_800FAD70_TeeteringTowers[rand8() % 14]);
    }

    D_800FA948_TeeteringTowers = 0;

    func_800090B8(D_800ED440);
    func_80023448(3);
    func_800234B8(0, 0xFF, 0xFF, 0xFF);
    func_8002346C(0, 1, 1);
    func_800234B8(1, 0, 0, 0xC8);
    func_8002346C(1, 1, 0);
    func_80023504(1, 0.0f, 36.0f, -114.0f);
    func_800234B8(2, 0, 0, 0);
    func_80023504(2, 0.0f, 100.0f, 65.0f);
    func_8002346C(2, 1, 0);
    func_800234B8(3, 0, 0, 0);
    func_80023504(3, 0.0f, -35.0f, 114.0f);
    func_8002346C(3, 1, 0);
    for (i = 0; D_800FA958_TeeteringTowers[i].unk_00 != 0; i++) {
        omAddObj(5, 3, 1, -1, &func_800F7A94_TeeteringTowers);
    }

    //only spawn 3 items? (coin/money bag)
    for (i = 0; i < 3; i++) {
        D_800EDE70[D_800EE984++] = omAddObj(6, 3, 0, -1, &func_800F8AF4_TeeteringTowers);
    }

}

void func_800F7A94_TeeteringTowers(omObjData* obj) {
    TTPlatformWork* work;
    s32 item;

    obj->trans.x = D_800FA958_TeeteringTowers[D_800FA948_TeeteringTowers].pos.x;
    obj->trans.y = D_800FA958_TeeteringTowers[D_800FA948_TeeteringTowers].pos.y;
    obj->trans.z = D_800FA958_TeeteringTowers[D_800FA948_TeeteringTowers].pos.z;
    obj->func_ptr = D_800FA958_TeeteringTowers[D_800FA948_TeeteringTowers].func;
    obj->work[3] = 0;
    obj->work[2] = 0;
    obj->work[1] = 0;
    obj->work[0] = 0;
    obj->model[0] = -1;
    work = obj->unk_50 = func_80023684(sizeof(TTPlatformWork), 0x7918);
    func_8009B770(work, 0, sizeof(TTPlatformWork));
    work->unk_04 = 1;
    work->unk_05 = (u8)D_800FA948_TeeteringTowers;
    D_800F524C = 0.0f;
    switch (D_800FA958_TeeteringTowers[D_800FA948_TeeteringTowers].unk_00) {
    case 1:
        obj->model[0] = func_800174C0(0x2B0000, 0x299);
        obj->model[1] = func_800174C0(0x2B0001, 0x299);
        func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
        func_80025798(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
        func_80025830(obj->model[0], 1.5f, 1.5f, 1.5f);
        func_800090A4(obj);
        func_80009000(obj, 4, obj->trans.y);
        obj->rot.x = 0.0f;
        obj->rot.y = 0.0f;
        obj->rot.z = 0.0f;
        func_800257E4(obj->model[0], obj->rot.x, obj->rot.y, obj->rot.z);
        func_800257E4(obj->model[1], obj->rot.x, obj->rot.y, obj->rot.z);
        func_80008FB8(obj, 0.5f);
        func_8000941C(obj, 1.0f, 1.0f, 1.0f);
        func_80008FC4(obj, 0.0f);
        D_800F2AF8[D_800ED440++] = obj;
        break;
    case 2:
    case 3:
        D_800F2AF8[D_800ED440++] = obj;
        obj->model[0] = func_800174C0(0x2B0002, 0x99);
        func_80009000(obj, 4, obj->trans.y);
        func_80008FB8(obj, 0.8f);
        func_80008FC4(obj, 20.0f);
        func_8000941C(obj, 1.0f, 1.0f, 1.0f);
        break;
    case 4:
        D_800F524C = 1.0f;
        obj->model[0] = func_800174C0(0x2B0003, 0xB9);
        D_800F2AF8[D_800ED440++] = obj;
        func_80009000(obj, 2, -10000.0f);
        D_800F524C = 0.0f;
        break;
    }
    if (D_800FA958_TeeteringTowers[D_800FA948_TeeteringTowers].unk_04 != 0) {
        item = D_800FAD70_TeeteringTowers[D_800FA954_TeeteringTowers];
        if (item != 0) {
            D_800FB1E0_TeeteringTowers[D_800FAD6C_TeeteringTowers].type = item;
            D_800FB1E0_TeeteringTowers[D_800FAD6C_TeeteringTowers].pos.x = D_800FA958_TeeteringTowers[D_800FA948_TeeteringTowers].pos.x;
            D_800FB1E0_TeeteringTowers[D_800FAD6C_TeeteringTowers].pos.y = D_800FA958_TeeteringTowers[D_800FA948_TeeteringTowers].pos.y;
            D_800FB1E0_TeeteringTowers[D_800FAD6C_TeeteringTowers].pos.z = D_800FA958_TeeteringTowers[D_800FA948_TeeteringTowers].pos.z;
            D_800FAD6C_TeeteringTowers++;
            D_800FA958_TeeteringTowers[D_800FA948_TeeteringTowers].unk_04 = 1;
        } else {
            D_800FA958_TeeteringTowers[D_800FA948_TeeteringTowers].unk_04 = 0;
        }
        D_800FA954_TeeteringTowers++;
    }
    D_800F524C = 1.0f;
    D_800FA948_TeeteringTowers++;
}

void func_800F7EE4_TeeteringTowers(omObjData* obj) {
    if (D_800FA934_TeeteringTowers == 4) {
        D_800FADA8_TeeteringTowers -= 0x14;
        if (D_800FADA8_TeeteringTowers < 0) {
            D_800FADA8_TeeteringTowers = 0;
        }
        func_800234B8(2, (u8)D_800FADA8_TeeteringTowers, (u8)D_800FADA8_TeeteringTowers, (u8)D_800FADA8_TeeteringTowers);
        return;
    }
    if (D_800FA934_TeeteringTowers == 2) {
        obj->trans.x = 0.0f;
        obj->trans.z = -15632.0f;
        obj->trans.y = -1600.0f;
        if (D_800FB274_TeeteringTowers == 1) {
            func_80023504(0, Center.x, Center.y, Center.z);
        }
    } else if (D_800FA944_TeeteringTowers == 1) {
        obj->trans.y += 100.0f;
        obj->trans.z -= 50.0f;
    }
}

void func_800F7FF0_TeeteringTowers(void) {
    s32 i;

    func_80009500();
    func_80009618(1);
    for (i = 0; i < 4; i++) {
        if (GwPlayer[i].group == 0) {
            D_800FA938_TeeteringTowers = i;
            break;
        }
    }
    D_800F3FB0[D_800F2BC0++] = omAddObj(2, 9, 0x46, -1, &func_800F8330_TeeteringTowers);
}

void func_800F8094_TeeteringTowers(omObjData* obj, s32 arg1, s32 arg2, u16 arg3, f32 x, f32 y, f32 z) {
    s32 i;
    s32 flags = 0x699;

    D_800F524C = 0.0f;
    func_8000979C(obj, arg1, arg2, arg3, flags, flags);
    D_800F524C = 1.0f;
    obj->func_ptr = &func_800F83F4_TeeteringTowers;
    TT_PLAYER(obj)->unk_3C = 180.0f;
    D_800B8964 = 1.76f;
    func_800187D0(obj, 0, arg1, 1, 0);
    func_800187D0(obj, 1, arg1 | 1, 1, 0);
    func_800187D0(obj, 2, arg1 | 3, 1, 0);
    func_800187D0(obj, 6, arg1 | 5, 1, 0x13);
    if (!(rand8() & 1)) {
        func_8001874C(obj, 0xD, arg1 | 0xF, 1, 0x78);
    } else {
        func_8001874C(obj, 0xD, arg1 | 0x38, 1, 0x78);
    }
    func_8001874C(obj, 0x11, arg1 | 0x18, 0, 0);
    func_8001874C(obj, 0x15, arg1 | 0x62, 0, 0);
    func_8001874C(obj, 0x20, arg1 | 0x67, 0, 0);
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = z;
    obj->scale.x = 1.0f;
    obj->scale.y = 1.0f;
    obj->scale.z = 1.0f;
    MtxRotate(D_800F2B7C[obj->model[0]].unk7C, 0.0f, 180.0f, 0.0f);
    func_80025830(obj->model[1], obj->scale.x, obj->scale.y, obj->scale.z);
    func_800257E4(obj->model[1], obj->rot.x, obj->rot.y, obj->rot.z);
    func_80025798(obj->model[1], obj->trans.x, obj->trans.y - 20.0f, obj->trans.z);
    func_800258EC(obj->model[1], 4, 4);
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    for (i = 0; i < 0x1D; i++) {
        func_800090C4(obj, i, 2);
    }
}

void func_800F8330_TeeteringTowers(omObjData* obj) {
    s32 chr = GwPlayer[D_800FA938_TeeteringTowers].character;
    s32 arg2 = D_800C59AC[chr].unk_04;
    s32 arg1 = D_800C59AC[chr].unk_00;

    obj->model[0] = -1;
    D_800FB270_TeeteringTowers = obj;
    func_800F8094_TeeteringTowers(obj, arg1, arg2, (u16)D_800FA938_TeeteringTowers, -300.0f, 51.0f, -977.0f);
    TT_PLAYER(obj)->unk_50 = 0x200;
}

void func_800F83F4_TeeteringTowers(omObjData* obj) {
    TTPlayerWork* work;
    s32 port;

    if ((D_800FA934_TeeteringTowers == 2) | (D_800FA934_TeeteringTowers == 4) || D_800FA934_TeeteringTowers == 3) {
        work = TT_PLAYER(obj);
        port = work->unk_56;
        D_800FADB0_TeeteringTowers = GwPlayer[D_800FA938_TeeteringTowers].coins_mg;
        if (obj->trans.y < (f32)(-((s32)((obj->trans.z + 200.0f) / -977.0f) * 200) - 300)) {
            D_800FA940_TeeteringTowers = 2;
        }
        if ((GwPlayer[D_800FA938_TeeteringTowers].flags & 1) || D_800FADAC_TeeteringTowers < 0xAA) {
            func_800F85EC_TeeteringTowers(obj);
        }
        if (D_800FADAC_TeeteringTowers == 0x78) {
            GMesCreate(0);
        }
        if (work->unk_5C & 0x20) {
            func_800F77E4_TeeteringTowers(&ContStkX[port], &ContStkY[port]);
        }
        if (D_800FA934_TeeteringTowers != 2) {
            ContStkX[port] = 0;
            ContStkY[port] = 0;
            ContBtn[port] = 0;
            ContBtnTrg[port] = 0;
        }
        func_80005A28(obj);
        D_800FADAC_TeeteringTowers++;
    }
}

void func_800F85EC_TeeteringTowers(omObjData* obj) {
    TTPlayerWork* work = TT_PLAYER(obj);
    s32 player = D_800FA938_TeeteringTowers;
    s32 tries = 3;
    s32 skill = 0x5A;
    s32 next[30][2] = {
        { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 12, 13 }, { 0, 0 },
        { 0, 0 }, { 0, 0 }, { 15, 16 }, { 16, 17 }, { 0, 0 }, { 18, 19 }, { 19, 20 }, { 20, 21 }, { 0, 22 }, { 22, 23 },
        { 23, 24 }, { 24, 0 }, { 0, 25 }, { 25, 26 }, { 26, 0 }, { 0, 27 }, { 27, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 },
    };
    s32 port;
    s32 plat;
    omObjData* p;

    switch (GwPlayer[player].cpu_difficulty) {
    case 0:
        skill = 0x50;
        break;
    case 1:
        skill = 0x5A;
        break;
    case 2:
        skill = 0x5F;
        break;
    case 3:
        skill = 0x64;
        break;
    }
    port = work->unk_56;
    plat = work->unk_53;
    if (plat != -1) {
        p = D_800F2AF8[plat];
        if (plat < 6) {
            if (p->work[2] < tries && p->work[2] != 0) {
                D_800FADB4_TeeteringTowers = 0xB4;
                D_800FADB8_TeeteringTowers = 0x8000;
                D_800FADBC_TeeteringTowers = -1;
            } else {
                if (p->trans.z - 130.0f < obj->trans.z) {
                    D_800FADB4_TeeteringTowers = 0xB4;
                } else {
                    D_800FADB4_TeeteringTowers = -1;
                }
                D_800FADB8_TeeteringTowers = 0;
            }
        } else {
            p = D_800F2AF8[plat];
            if (skill < (u8)((rand8() & 0xFF) % 100)) {
                tries = 4;
            }
            if (p->work[2] < tries) {
                if (p->work[1] == 2) {
                    D_800FADB4_TeeteringTowers = 0xDC;
                } else if (p->work[1] == 3) {
                    D_800FADB4_TeeteringTowers = 0x8C;
                }
                D_800FADB8_TeeteringTowers = 0x8000;
                D_800FADBC_TeeteringTowers = -1;
                if (skill < (u8)((rand8() & 0xFF) % 100)) {
                    D_800FADB4_TeeteringTowers = -1;
                }
            } else {
                D_800FADB4_TeeteringTowers = -1;
                if (D_800FADBC_TeeteringTowers == -1) {
                    if (plat == 0xE || plat == 0x11 || plat == 0x15 || plat == 0x18 || plat == 0x1A) {
                        D_800FADBC_TeeteringTowers = 0;
                    } else if (plat == 0xB || plat == 0xF || plat == 0x12 || plat == 0x16 || plat == 0x19) {
                        D_800FADBC_TeeteringTowers = 1;
                    } else if (D_800FA958_TeeteringTowers[next[plat][0]].unk_04 == 1) {
                        D_800FADBC_TeeteringTowers = 0;
                    } else if (D_800FA958_TeeteringTowers[next[plat][1]].unk_04 == 1) {
                        D_800FADBC_TeeteringTowers = 1;
                    } else {
                        D_800FADBC_TeeteringTowers = rand8() & 1;
                    }
                }
                if (D_800FADBC_TeeteringTowers == 0) {
                    if (p->trans.x - 110.0f < obj->trans.x) {
                        D_800FADB4_TeeteringTowers = 0xE1;
                    } else if (p->trans.z - 110.0f < obj->trans.z) {
                        D_800FADB4_TeeteringTowers = 0xB4;
                    }
                } else {
                    if (obj->trans.x < p->trans.x + 110.0f) {
                        D_800FADB4_TeeteringTowers = 0x87;
                    } else if (p->trans.z - 110.0f < obj->trans.z) {
                        D_800FADB4_TeeteringTowers = 0xB4;
                    }
                }
                D_800FADB8_TeeteringTowers = 0;
            }
        }
    }
    if (D_800FADB4_TeeteringTowers != -1) {
        ContStkX[port] = func_800AEAC0(D_800FADB4_TeeteringTowers) * 60.0f;
        ContStkY[port] = -(func_800AEFD0(D_800FADB4_TeeteringTowers) * 60.0f);
    } else {
        ContStkX[port] = 0;
        ContStkY[port] = 0;
    }
    ContBtn[port] = (u16)D_800FADB8_TeeteringTowers;
    ContBtnTrg[port] = (u16)D_800FADB8_TeeteringTowers;
}

void func_800F8AF4_TeeteringTowers(omObjData* arg0) {
    UnkTeeteringTowers1* temp_v0_2;
    
    arg0->trans.x = D_800FB1E0_TeeteringTowers[D_800FADC0_TeeteringTowers].pos.x;
    arg0->trans.y = D_800FB1E0_TeeteringTowers[D_800FADC0_TeeteringTowers].pos.y + 50.0f;
    arg0->trans.z = D_800FB1E0_TeeteringTowers[D_800FADC0_TeeteringTowers].pos.z;
    arg0->func_ptr = &func_800F8DC0_TeeteringTowers;
    arg0->work[3] = 0;
    arg0->work[2] = 0;
    arg0->work[1] = 0;
    arg0->work[0] = 0;
    arg0->model[0] = -1;
    temp_v0_2 = arg0->unk_50 = func_80023684(sizeof(UnkTeeteringTowers1), 0x7918);
    func_8009B770(temp_v0_2, 0, 0x6C);
    if (D_800FB1E0_TeeteringTowers[D_800FADC0_TeeteringTowers].type == PLATFORM_ITEM_MONEY_BAG) {
        func_800091BC(arg0, 0x37, 0x289, 8);
        func_80009340(arg0, 2, 0x25, 0x289, 8);
        func_80009340(arg0, 3, 0x2A, 0x689, 8);
        func_8001E360(temp_v0_2->unk_24, 0xFF, 0xFF, 0xBE);
        func_8000941C(arg0, 4.5f, 4.5f, 4.5f);
        func_80025830(arg0->model[3], 2.0f, 2.0f, 2.0f);
        temp_v0_2->unk_52 = 6;
    } else {
        func_800091BC(arg0, 0x21, 0x289, 8);
        func_80009340(arg0, 2, 0x25, 0x289, 8);
        func_80009340(arg0, 3, 0x2A, 0x689, 8);
        func_8001E360(temp_v0_2->unk_24, 0xFF, 0xFF, 0xBE);
        func_8000941C(arg0, 4.5f, 4.5f, 4.5f);
        func_80025830(arg0->model[3], 2.0f, 2.0f, 2.0f);
        temp_v0_2->unk_52 = 3;
    }
    arg0->model[1] = func_800174F4(0x2B0004, 0xA99);
    func_80025798(arg0->model[1], arg0->trans.x, arg0->trans.y - 35.0f, arg0->trans.z);
    func_80025830(arg0->model[1], 1.5f, 1.5f, 1.5f);
    func_800211BC(arg0->model[1], 0x32);
    temp_v0_2->unk_5C = 0;
    temp_v0_2->unk_60 = 60;
    temp_v0_2->unk_44 = 0.1f;
    temp_v0_2->unk_48 = 200.0f;
    temp_v0_2->unk_34 = 50.0f;
    temp_v0_2->unk_3C = 0;
    temp_v0_2->unk_54 = 1;
    D_800FADC0_TeeteringTowers++;
}

void func_800F8DC0_TeeteringTowers(omObjData* obj) {
    UnkTeeteringTowers1* work = obj->unk_50;

    if (D_800FA934_TeeteringTowers >= 3) {
        work->unk_54 = 0;
        func_800258EC(obj->model[1], 4, 4);
        func_800258EC(obj->model[0], 4, 4);
    }
}

s32 func_800F8E20_TeeteringTowers(void) {
    return D_800FA940_TeeteringTowers;
}
