#include "7B.h"

#define D_800FB0E0 D_800FB0E0_MinigameStadiumMinigameResultsScreen
#define D_800FB0F0 D_800FB0F0_MinigameStadiumMinigameResultsScreen
#define D_800FB104 D_800FB104_MinigameStadiumMinigameResultsScreen
#define D_800FB108 D_800FB108_MinigameStadiumMinigameResultsScreen
#define D_800FB10C D_800FB10C_MinigameStadiumMinigameResultsScreen

f32 D_800FB0E0_MinigameStadiumMinigameResultsScreen[4] = { -450.0f, -150.0f, 150.0f, 450.0f }; /* each player's x */
s16 D_800FB0F0_MinigameStadiumMinigameResultsScreen[6] = { 1, 2, 6, 3, 4, 5 }; /* per character: file directory */
u8 D_800FB0FC_MinigameStadiumMinigameResultsScreen[8] = { 1, 2, 3, 4, 5, 6, 0, 0 };
f32 D_800FB104_MinigameStadiumMinigameResultsScreen = 0.0f;  /* the jump's angle */
f32 D_800FB108_MinigameStadiumMinigameResultsScreen = 10.0f; /* its step */
f32 D_800FB10C_MinigameStadiumMinigameResultsScreen = 100.0f; /* its height */

/* One player: model, coin counter and the minigame coins' digits. */
// block layout: the else-if path reloads flags (retail) / reuses them (C) (masked 33)
#ifdef NON_MATCHING
void func_800F9310_MinigameStadiumMinigameResultsScreen(void) {
    PlayerRes* all[4];
    Process* proc;
    PlayerRes* res;
    ColWork* col;
    ResMain* main;
    s32 i;

    proc = HuPrcCurrentGet();
    res = proc->user_data;
    main = proc->relative->user_data;
    col = main->col[res->index]->user_data;
    func_800F9654_MinigameStadiumMinigameResultsScreen(res);
    func_800F97FC_MinigameStadiumMinigameResultsScreen(res);
    func_800F9A0C_MinigameStadiumMinigameResultsScreen(res);
    HuPrcSleep(2);
    func_800F9B34_MinigameStadiumMinigameResultsScreen(res);
    func_800F9BF0_MinigameStadiumMinigameResultsScreen();
    func_800F9C94_MinigameStadiumMinigameResultsScreen(res, col);
    func_80025798(res->model, res->pos.x, res->pos.y, res->pos.z);
    func_80025798(res->model2, D_800FB0E0[res->index], 0.0f, 0.0f);
    func_80025830(res->model, 1.0f, 1.0f, 1.0f);
    func_800F9F94_MinigameStadiumMinigameResultsScreen(res);
    while (res->flags == 0) {
        HuPrcVSleep();
        func_800F9F54_MinigameStadiumMinigameResultsScreen(res);
    }
    if (res->flags & 1) {
        if (!(res->flags & 0x100)) {
            while (TRUE) {
                HuPrcVSleep();
                func_800FADE8_MinigameStadiumMinigameResultsScreen(res);
                func_800FA020_MinigameStadiumMinigameResultsScreen(res);
                while (res->flags & 0x40) {
                    HuPrcVSleep();
                    func_800FA35C_MinigameStadiumMinigameResultsScreen(res);
                }
                if (res->flags & 0x100) {
                    func_800FAE64_MinigameStadiumMinigameResultsScreen(res);
                }
                if ((col->flags & 0x400) && RES_FLAGS_TEST(res, 0x140, 0x100)) {
                    break;
                }
                if (res->flags & 0x100) {
                    break;
                }
            }
        }
    } else if ((res->flags & 2) && res->flags == 2) {
        do {
            HuPrcVSleep();
            func_800F9F94_MinigameStadiumMinigameResultsScreen(res);
            func_800FA1C0_MinigameStadiumMinigameResultsScreen(res, col);
            if ((col->flags & 0x400) && !(res->flags & 0x40)) {
                break;
            }
        } while (res->flags == 2);
    }
    res->flags |= 0x80;
    if (res->unk_7A == 0) {
        func_80060540(0x54, res->index);
        res->unk_7A = 1;
    }
    while (!(res->flags & 0x200)) {
        HuPrcVSleep();
        if (res->flags & 0x80) {
            res->flags |= 0x200;
        }
    }
    while (!(res->flags & 0x800)) {
        HuPrcVSleep();
        func_800FA64C_MinigameStadiumMinigameResultsScreen(res);
        func_800FAD74_MinigameStadiumMinigameResultsScreen(res);
    }
    for (i = 0; i < 4; i++) {
        all[i] = main->player[i]->user_data;
    }
    if ((all[0]->flags & 0x800) && (all[1]->flags & 0x800) && (all[2]->flags & 0x800) && (all[3]->flags & 0x800)) {
        D_800FB2A4_MinigameStadiumMinigameResultsScreen = 1;
    }
    while (TRUE) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_7B_MinigameStadiumMinigameResultsScreen/306BA0", func_800F9310_MinigameStadiumMinigameResultsScreen);
#endif

// scheduling: the index shift of &D_800FB0F0[c] comes before the table base (raw 2, masked 2);
// `D_800FB0F0 + c` tried
#ifdef NON_MATCHING
void func_800F9654_MinigameStadiumMinigameResultsScreen(PlayerRes* res) {
    u8 c;
    s16* dir;
    s32 mode;

    c = GwPlayer[res->index].character;
    mode = 0x2DD;
    dir = &D_800FB0F0[c];
    res->model = LoadFormFile((*dir << 16) | 0x9F, mode);
    res->mot[0] = func_80023FC8(res->model);
    res->mot[1] = LoadFormFile((*dir << 16) | 0x74, mode);
    res->mot[2] = LoadFormFile((*dir << 16) | 0xF, mode);
    if (c == 5) {
        res->mot[3] = LoadFormFile((D_800FB0F0[5] << 16) | 0x3E, mode);
    } else {
        res->mot[3] = LoadFormFile((D_800FB0F0[c] << 16) | 0x3F, mode);
    }
    res->mot[4] = LoadFormFile((D_800FB0F0[c] << 16) | 5, mode);
    res->model2 = func_800174C0(D_800FB0FC_MinigameStadiumMinigameResultsScreen[c] | 0xC0000, mode);
    func_80025798(res->model2, D_800FB0E0[res->index], 0.0f, 100.0f);
    func_80025830(res->model2, 1.0f, 1.0f, 1.0f);
    func_800258EC(res->model2, 4, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_7B_MinigameStadiumMinigameResultsScreen/306BA0", func_800F9654_MinigameStadiumMinigameResultsScreen);
#endif

void func_800F97FC_MinigameStadiumMinigameResultsScreen(PlayerRes* res) {
    s32 i;

    res->sprPlus = func_80019060(D_800FB284_MinigameStadiumMinigameResultsScreen, 0, 1);
    func_80018D84(res->sprPlus, 0x10);
    SetBasicSpriteSize(res->sprPlus, 1.0f, 1.0f);
    func_80018CF8(res->sprPlus, 0xC0);
    func_80018C90(res->sprPlus);
    res->sprMinus = func_80019060(D_800FB28C_MinigameStadiumMinigameResultsScreen, 0, 1);
    func_80018D84(res->sprMinus, 0x10);
    SetBasicSpriteSize(res->sprMinus, 1.0f, 1.0f);
    func_80018CF8(res->sprMinus, 0xC0);
    func_80018C90(res->sprMinus);
    for (i = 0; i < 4; i++) {
        res->digPlus[i] = func_80019060(D_800FB280_MinigameStadiumMinigameResultsScreen, 0, 1);
        func_80018D84(res->digPlus[i], 1);
        func_80018F68(res->digPlus[i], 0, 0, 0x80);
        SetBasicSpriteSize(res->digPlus[i], 1.0f, 1.0f);
        func_80018CF8(res->digPlus[i], 0xFF);
        func_80018C90(res->digPlus[i]);
    }
    for (i = 0; i < 4; i++) {
        res->digMinus[i] = func_80019060(D_800FB280_MinigameStadiumMinigameResultsScreen, 0, 1);
        func_80018D84(res->digMinus[i], 1);
        func_80018F68(res->digMinus[i], 0x80, 0, 0);
        SetBasicSpriteSize(res->digMinus[i], 1.0f, 1.0f);
        func_80018CF8(res->digMinus[i], 0xFF);
        func_80018C90(res->digMinus[i]);
    }
    for (i = 0; i < 3; i++) {
        res->sprTotal[i] = func_80019060(D_800FB292_MinigameStadiumMinigameResultsScreen, 0, 1);
    }
}

void func_800F9A0C_MinigameStadiumMinigameResultsScreen(PlayerRes* res) {
    res->pos.z = res->unk_18.x = res->unk_18.y = res->unk_18.z = 0.0f;
    res->pos.x = 0.0f;
    res->pos.y = 150.0f;
    res->rank = 1;
    res->unk_7A = 0;
    res->flags = 0;
    res->unk_04 = 0;
    res->unk_70 = res->unk_74 = 0;
    res->coins = GwPlayer[res->index].coins;
    res->coinsMg = GwPlayer[res->index].coins_mg;
    if (res->coins + res->coinsMg < 0) {
        if (res->coins == 0) {
            res->coinsMg = 0;
        } else {
            res->coinsMg = -res->coins;
        }
    } else if (res->coins + res->coinsMg >= 1000) {
        res->coinsMg = 999 - res->coins;
    }
    res->total = res->coins + res->coinsMg;
    if (res->total <= 0) {
        res->total = 0;
    } else if (res->total >= 1000) {
        res->total = 999;
    }
    res->unk_78 = 0;
}

/* the player's rank by minigame coins (1 + how many won more) */
// register allocation and loop scheduling (masked 12)
#ifdef NON_MATCHING
void func_800F9B34_MinigameStadiumMinigameResultsScreen(PlayerRes* res) {
    PlayerRes* all[4];
    ResMain* main;
    PlayerRes* me;
    s32 i;
    s32 n;

    main = HuPrcCurrentGet()->relative->user_data;
    for (i = 0; i < 4; i++) {
        all[i] = main->player[i]->user_data;
    }
    n = 0;
    me = all[res->index];
    for (i = 0; i < 4; i++) {
        if (me != all[i] && me->coinsMg < all[i]->coinsMg) {
            n++;
        }
    }
    res->rank += n;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_7B_MinigameStadiumMinigameResultsScreen/306BA0", func_800F9B34_MinigameStadiumMinigameResultsScreen);
#endif

void func_800F9BF0_MinigameStadiumMinigameResultsScreen(void) {
    PlayerRes* all[4];
    ResMain* main;
    Process* prc;
    s32 i;

    main = HuPrcCurrentGet()->relative->user_data;
    for (i = 0; i < 4; i++) {
        prc = main->player[i];
        all[i] = prc->user_data;
    }
    for (i = 0, D_800FB2A1_MinigameStadiumMinigameResultsScreen = 1; i < 4; i++) {
        if (D_800FB2A1_MinigameStadiumMinigameResultsScreen < all[i]->rank) {
            D_800FB2A1_MinigameStadiumMinigameResultsScreen = all[i]->rank;
        }
    }
}

void func_800F9C94_MinigameStadiumMinigameResultsScreen(PlayerRes* res, ColWork* col) {
    func_800F9CB8_MinigameStadiumMinigameResultsScreen(col, res);
}

/* the player's starting spot: on top of their column (coins before the minigame) */
void func_800F9CB8_MinigameStadiumMinigameResultsScreen(ColWork* col, PlayerRes* res) {
    f32 rem;

    if (res->coins < 81) {
        if (res->coins < 21) {
            res->pos.x = D_800FB0E0[res->index];
            res->pos.z = -50.0f;
            if (res->coins == 20) {
                res->pos.y = 600.0f;
                return;
            }
        part:
            rem = (s16)(res->coins % 20);
            goto calc;
        } else if (res->coins < 41) {
            res->pos.x = D_800FB0E0[res->index] + 50.0f;
            res->pos.z = 0.0f;
            if (res->coins == 40) {
                res->pos.y = 600.0f;
                return;
            }
            goto part;
        } else if (res->coins < 61) {
            res->pos.x = D_800FB0E0[res->index] - 50.0f;
            res->pos.z = 0.0f;
            if (res->coins == 60) {
                res->pos.y = 600.0f;
                return;
            }
            goto part;
        } else if (res->coins < 81) {
            res->pos.x = D_800FB0E0[res->index];
            res->pos.z = 50.0f;
            if (res->coins == 80) {
                res->pos.y = 600.0f;
                return;
            }
            goto part;
        }
        return;
    }
    res->pos.x = D_800FB0E0[res->index];
    res->pos.z = 50.0f;
    rem = (s16)(res->coins % 20);
    if (rem == 0.0f) {
        res->pos.y = 600.0f;
        return;
    }
calc:
    res->pos.y = rem * 22.5f + 150.0f;
}

void func_800F9F54_MinigameStadiumMinigameResultsScreen(PlayerRes* res) {
    func_800258EC(res->model, 4, 0);
    func_80025EB4(res->model, 2, 2);
}

/* the minigame coins' digits */
// decomp-permuter
void func_800F9F94_MinigameStadiumMinigameResultsScreen(PlayerRes *res)
{
  s32 n;
  s16 new_var;
  s16 rem;
  new_var = res->coinsMg;
  n = (new_var < 0) ? (-new_var) : (res->coinsMg);
  res->digits[1] = n / 100;
  rem = n % 100;
  res->digits[2] = rem / 10;
  res->digits[3] = rem % 10;
}

/* climb with the counted coins */
// retail recomputes coins % 20 in its own block; C shares it (masked 21)
#ifdef NON_MATCHING
void func_800FA020_MinigameStadiumMinigameResultsScreen(PlayerRes* res) {
    f32 top;

    top = (s16)(res->total % 20) * 22.5f + 150.0f;
    if (res->unk_70 > res->unk_74) {
        res->pos.y += 22.5f;
    }
    if ((s16)(res->coins % 20) + res->coinsMg < 20) {
        if (res->pos.y > top) {
            res->pos.y = top;
        } else {
            if ((s16)(res->coins % 20) == 0 && res->coins != 0) {
                res->pos.y = 600.0f;
            }
            goto end;
        }
    }
    if (res->pos.y > 600.0f) {
        res->pos.y = 600.0f;
    }
end:
    func_80025798(res->model, res->pos.x, res->pos.y, res->pos.z);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_7B_MinigameStadiumMinigameResultsScreen/306BA0", func_800FA020_MinigameStadiumMinigameResultsScreen);
#endif

/* sink with the coins lost */
void func_800FA1C0_MinigameStadiumMinigameResultsScreen(PlayerRes* res, ColWork* col) {
    f32 top;
    s16 rem;

    top = (s16)(res->total % 20) * 22.5f + 150.0f;
    res->pos.y -= 22.5f;
    if (-res->coinsMg >= 20) {
        if (res->pos.y < 150.0f) {
            res->pos.y = 150.0f;
        }
    } else {
        rem = res->coins % 20;
        if (rem > 0 && rem < (s16)(res->total % 20)) {
            if (res->pos.y < 150.0f) {
                res->pos.y = 150.0f;
            }
        } else if (res->pos.y <= top) {
            res->pos.y = top;
        }
    }
    func_80025798(res->model, res->pos.x, res->pos.y, res->pos.z);
}

/* the jump down one column step */
void func_800FA35C_MinigameStadiumMinigameResultsScreen(PlayerRes* res) {
    f32 t;

    if (res->pos.x == D_800FB0E0[res->index] - 50.0f) {
        if (res->pos.z == -50.0f && res->unk_04 == 1) {
            D_800FB104 = 0.0f;
            D_800FB108 = 10.0f;
            D_800FB10C = 100.0f;
            res->pos.y = 600.0f;
            if (func_80025E48(res->model) != func_80025E48(res->mot[0])) {
                func_80025C20(res->model, func_80025E48(res->mot[0]), 0, 8, 0);
            }
            func_80025798(res->model, res->pos.x, res->pos.y, res->pos.z);
            res->unk_04 = 0;
            res->flags &= ~0x40;
            return;
        }
    }
    res->pos.x -= 10.0f;
    if (res->pos.x < D_800FB0E0[res->index] - 50.0f) {
        res->pos.x = D_800FB0E0[res->index] - 50.0f;
    }
    res->pos.z -= 10.0f;
    if (res->pos.z < -50.0f) {
        res->pos.z = -50.0f;
    }
    D_800FB104 += D_800FB108;
    if (D_800FB104 > 180.0f) {
        D_800FB104 = 180.0f;
    }
    func_80025798(res->model, res->pos.x, func_800AEAC0(D_800FB104) * D_800FB10C + res->pos.y, res->pos.z);
    if (func_80025E48(res->model) != func_80025E48(res->mot[4])) {
        func_80025C20(res->model, func_80025E48(res->mot[4]), 0, 8, 0);
    }
    if (func_80025E48(res->model) == func_80025E48(res->mot[4])) {
        t = func_80025D18(res->model);
        if (func_80025D40(res->model) <= t) {
            res->unk_04 = 1;
        }
    }
}

/* the minigame coins over the player: a sign, then one to three digits */
// register allocation and hoisting of 12.5f in the minus branch (masked 12)
#ifdef NON_MATCHING
void func_800FA64C_MinigameStadiumMinigameResultsScreen(PlayerRes* res) {
    Vec3f pos;
    Vec2f scr;
    f32 x;
    s32 i;

    if (res->coinsMg > 0) {
        res->digits[0] = 11;
        pos.x = res->pos.x;
        pos.y = res->pos.y + 220.0f;
        pos.z = res->pos.z;
        Convert3DTo2D(0, &pos, &scr);
        SetBasicSpritePos(res->sprPlus, scr.x, scr.y);
        ShowBasicSprite(res->sprPlus);
        i = 0;
        if (res->digits[1] == 0 && res->digits[2] == 0) {
            for (x = -25.0f; i < 4; x += 12.5f) {
                if (!(i == 1 || i == 2)) {
                    pos.x = x + res->pos.x;
                    pos.y = res->pos.y + 230.0f;
                    pos.z = res->pos.z;
                    Convert3DTo2D(0, &pos, &scr);
                    SetBasicSpritePos(res->digPlus[i], scr.x, scr.y);
                    func_80018E0C(res->digPlus[i], res->digits[i]);
                    func_80018CF8(res->digPlus[i], 0xFF);
                    ShowBasicSprite(res->digPlus[i]);
                    i++;
                } else {
                    i++;
                }
            }
        } else if (i = 0, res->digits[1] == 0 && res->digits[2] != 0) {
            do {
                if (i != 1) {
                    pos.y = res->pos.y + 230.0f;
                    pos.z = res->pos.z;
                    if (i == 0) {
                        pos.x = res->pos.x - 50.0f;
                    } else if (i == 2) {
                        pos.x = res->pos.x;
                    } else if (i == 3) {
                        pos.x = res->pos.x + 50.0f;
                    }
                    Convert3DTo2D(0, &pos, &scr);
                    SetBasicSpritePos(res->digPlus[i], scr.x, scr.y);
                    func_80018E0C(res->digPlus[i], res->digits[i]);
                    func_80018CF8(res->digPlus[i], 0xFF);
                    ShowBasicSprite(res->digPlus[i]);
                    i++;
                } else {
                    i++;
                }
            } while (i < 4);
        } else if (res->digits[1] != 0) {
            for (i = 0, x = -75.0f; i < 4; x += 50.0f) {
                pos.x = x + res->pos.x;
                pos.y = res->pos.y + 230.0f;
                pos.z = res->pos.z;
                Convert3DTo2D(0, &pos, &scr);
                SetBasicSpritePos(res->digPlus[i], scr.x, scr.y);
                func_80018E0C(res->digPlus[i], res->digits[i]);
                func_80018CF8(res->digPlus[i], 0xFF);
                ShowBasicSprite(res->digPlus[i]);
                i++;
            }
        }
    } else if (res->coinsMg < 0) {
        res->digits[0] = 12;
        pos.x = res->pos.x;
        pos.y = res->pos.y - 50.0f;
        pos.z = res->pos.z;
        Convert3DTo2D(0, &pos, &scr);
        SetBasicSpritePos(res->sprMinus, scr.x, scr.y);
        ShowBasicSprite(res->sprMinus);
        i = 0;
        if (res->digits[1] == 0 && res->digits[2] == 0) {
            for (x = -25.0f; i < 4; x += 12.5f) {
                if (!(i == 1 || i == 2)) {
                    pos.x = x + res->pos.x;
                    pos.y = res->pos.y - 70.0f;
                    pos.z = res->pos.z;
                    Convert3DTo2D(0, &pos, &scr);
                    SetBasicSpritePos(res->digMinus[i], scr.x, scr.y);
                    func_80018E0C(res->digMinus[i], res->digits[i]);
                    func_80018D84(res->digMinus[i], 1);
                    func_80018CF8(res->digMinus[i], 0xFF);
                    ShowBasicSprite(res->digMinus[i]);
                    i++;
                } else {
                    i++;
                }
            }
        } else if (i = 0, res->digits[1] == 0 && res->digits[2] != 0) {
            do {
                if (i != 1) {
                    pos.y = res->pos.y - 70.0f;
                    pos.z = res->pos.z;
                    if (i == 0) {
                        pos.x = res->pos.x - 50.0f;
                    } else if (i == 2) {
                        pos.x = res->pos.x;
                    } else if (i == 3) {
                        pos.x = res->pos.x + 50.0f;
                    }
                    Convert3DTo2D(0, &pos, &scr);
                    SetBasicSpritePos(res->digMinus[i], scr.x, scr.y);
                    func_80018E0C(res->digMinus[i], res->digits[i]);
                    func_80018D84(res->digMinus[i], 1);
                    func_80018CF8(res->digMinus[i], 0xFF);
                    ShowBasicSprite(res->digMinus[i]);
                    i++;
                } else {
                    i++;
                }
            } while (i < 4);
        } else if (res->digits[1] != 0) {
            for (i = 0, x = -75.0f; i < 4; x += 50.0f) {
                pos.x = x + res->pos.x;
                pos.y = res->pos.y - 70.0f;
                pos.z = res->pos.z;
                Convert3DTo2D(0, &pos, &scr);
                SetBasicSpritePos(res->digMinus[i], scr.x, scr.y);
                func_80018E0C(res->digMinus[i], res->digits[i]);
                func_80018D84(res->digMinus[i], 1);
                func_80018CF8(res->digMinus[i], 0xFF);
                ShowBasicSprite(res->digMinus[i]);
                i++;
            }
        }
    }
    res->flags |= 0x400;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_7B_MinigameStadiumMinigameResultsScreen/306BA0", func_800FA64C_MinigameStadiumMinigameResultsScreen);
#endif

// decomp-permuter
void func_800FAD74_MinigameStadiumMinigameResultsScreen(PlayerRes *unused)
{
  Process *proc;
  PlayerRes *res;
  ResMain *main;
  Process *new_var;
  s32 i;
  proc = HuPrcCurrentGet();
  res = proc->user_data;
  main = proc->relative->user_data;
  for (i = 0; i < 4; i++)
  {
    new_var = main->player[i];
    D_800FB260_MinigameStadiumMinigameResultsScreen[i] = new_var->user_data;
  }

  if (res->flags & 0x400)
  {
    func_800FAEE0_MinigameStadiumMinigameResultsScreen(res);
  }
}

void func_800FADE8_MinigameStadiumMinigameResultsScreen(PlayerRes* res) {
    if (func_80025E48(res->model) != func_80025E48(res->mot[1])) {
        func_80025C20(res->model, func_80025E48(res->mot[1]), 0, 8, 2);
    }
}

void func_800FAE64_MinigameStadiumMinigameResultsScreen(PlayerRes* res) {
    if (func_80025E48(res->model) != func_80025E48(res->mot[0])) {
        func_80025C20(res->model, func_80025E48(res->mot[0]), 0, 8, 2);
    }
}

/* the end pose: cheer (won coins) or sulk (lost) */
// block layout: retail branches into the cheer/sulk tails with gotos (masked 14)
#ifdef NON_MATCHING
void func_800FAEE0_MinigameStadiumMinigameResultsScreen(PlayerRes* res) {
    s8 t;

    t = func_800F6AC8_MinigameStadiumMinigameResultsScreen();
    if (res->coinsMg > 0) {
        if (func_80025E48(res->model) != func_80025E48(res->mot[2])) {
            func_80025C20(res->model, func_80025E48(res->mot[2]), 0, 8, 0);
        }
        HuPrcVSleep();
    } else if (res->coinsMg < 0 || (t == 0 && res->coinsMg < 0)) {
        if (func_80025E48(res->model) != func_80025E48(res->mot[3])) {
            func_80025C20(res->model, func_80025E48(res->mot[3]), 0, 8, 0);
        }
        HuPrcVSleep();
    }
    if (++D_800FB270_MinigameStadiumMinigameResultsScreen >= 0x5B) {
        res->flags |= 0x800;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_7B_MinigameStadiumMinigameResultsScreen/306BA0", func_800FAEE0_MinigameStadiumMinigameResultsScreen);
#endif
