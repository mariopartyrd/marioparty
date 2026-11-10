#include "7B.h"

#define D_800FB000 D_800FB000_MinigameStadiumMinigameResultsScreen
#define D_800FB0C0 D_800FB0C0_MinigameStadiumMinigameResultsScreen
#define SLOT(p, s) ((p) * 12 + (s) * 3)

/* per player, per slot: {x, y, z} (indexed flat: SLOT(player, slot) + 0..2) */
f32 D_800FB000_MinigameStadiumMinigameResultsScreen[4 * 4 * 3] = {
    -450.0f, -300.0f, -100.0f, -400.0f, -300.0f, -50.0f, -500.0f, -300.0f, -50.0f, -450.0f, -300.0f, 0.0f,
    -150.0f, -300.0f, -100.0f, -100.0f, -300.0f, -50.0f, -200.0f, -300.0f, -50.0f, -150.0f, -300.0f, 0.0f,
    150.0f, -300.0f, -100.0f, 200.0f, -300.0f, -50.0f, 100.0f, -300.0f, -50.0f, 150.0f, -300.0f, 0.0f,
    450.0f, -300.0f, -100.0f, 500.0f, -300.0f, -50.0f, 400.0f, -300.0f, -50.0f, 450.0f, -300.0f, 0.0f,
};
s32 D_800FB0C0_MinigameStadiumMinigameResultsScreen[4] = { 1, 2, 4, 8 };

void func_800F65E0_MinigameStadiumMinigameResultsScreen(void) {
    func_80029090(0x20);
    func_8002ADF0(&D_800EDEC0, 0x40);
    func_8001DE70(0x20);
    omInitObjMan(0x20, 0x20);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    D_800FB2A4_MinigameStadiumMinigameResultsScreen = 0;
    D_800FB298_MinigameStadiumMinigameResultsScreen = func_800F6A3C_MinigameStadiumMinigameResultsScreen();
    D_800FB2A0_MinigameStadiumMinigameResultsScreen = 0;
    omAddPrcObj(func_800F67D0_MinigameStadiumMinigameResultsScreen, 0x3F00, 0x800, 0);
    func_8002890C(0, 0, 0);
    omAddObj(5, 0, 0, -1, &func_800F8040_MinigameStadiumMinigameResultsScreen);
    func_800F66C0_MinigameStadiumMinigameResultsScreen();
    func_80060128(0x16);
}

void func_800F66C0_MinigameStadiumMinigameResultsScreen(void) {
    D_800FB238_MinigameStadiumMinigameResultsScreen = func_800174F4(0xC0008, 0x69D);
    D_800FB23A_MinigameStadiumMinigameResultsScreen = func_800174F4(0xC0009, 0x2DD);
    D_800FB294_MinigameStadiumMinigameResultsScreen = func_800174C0(0xC0000, 0x2CD);
    D_800FB28E_MinigameStadiumMinigameResultsScreen = func_800174C0(0x210001, 0x2CD);
    D_800FB29E_MinigameStadiumMinigameResultsScreen = func_800174C0(0xC000B, 0x2CD);
    D_800FB284_MinigameStadiumMinigameResultsScreen = InitSprite(0xC0015);
    D_800FB28C_MinigameStadiumMinigameResultsScreen = InitSprite(0xC0016);
    D_800FB280_MinigameStadiumMinigameResultsScreen = InitSprite(0xC0017);
    D_800FB292_MinigameStadiumMinigameResultsScreen = InitSprite(0xC0018);
    D_800FB2A2_MinigameStadiumMinigameResultsScreen = InitSprite(0x2B);
    D_800FB282_MinigameStadiumMinigameResultsScreen = InitSprite(0xC0014);
    D_800FB290_MinigameStadiumMinigameResultsScreen = InitSprite(0xC0013);
}

void func_800F67D0_MinigameStadiumMinigameResultsScreen(void) {
    Process* proc;
    Process* p;
    s32 i;

    D_800FB29C_MinigameStadiumMinigameResultsScreen = 0;
    proc = HuPrcCurrentGet();
    proc->user_data = D_800FB1C0_MinigameStadiumMinigameResultsScreen = func_80023684(sizeof(ResMain), 0x7918);
    for (i = 0; i < 4; i++) {
        D_800FB1C0_MinigameStadiumMinigameResultsScreen->player[i] =
            func_8005DCD8(func_800F9310_MinigameStadiumMinigameResultsScreen, 0x3F00, 0x1000, 0, proc);
        D_800FB1C0_MinigameStadiumMinigameResultsScreen->player[i]->user_data =
            D_800FB1C8_MinigameStadiumMinigameResultsScreen[i] = func_80023684(sizeof(PlayerRes), 0x7918);
    }
    for (i = 0; i < 4; i++) {
        D_800FB1C8_MinigameStadiumMinigameResultsScreen[i]->index = i;
    }
    for (i = 0; i < 4; i++) {
        D_800FB1C0_MinigameStadiumMinigameResultsScreen->col[i] =
            func_8005DCD8(func_800F6BEC_MinigameStadiumMinigameResultsScreen, 0x4000, 0x800, 0, proc);
        D_800FB1C0_MinigameStadiumMinigameResultsScreen->col[i]->user_data =
            D_800FB1D8_MinigameStadiumMinigameResultsScreen[i] = func_80023684(sizeof(ColWork), 0x7918);
        D_800FB1C0_MinigameStadiumMinigameResultsScreen->drop[i] =
            func_8005DCD8(func_800F8200_MinigameStadiumMinigameResultsScreen, 0x4000, 0x800, 0, proc);
        D_800FB1C0_MinigameStadiumMinigameResultsScreen->drop[i]->user_data =
            D_800FB1E8_MinigameStadiumMinigameResultsScreen[i] = func_80023684(sizeof(ColWork), 0x7918);
    }
    for (i = 0; i < 4; i++) {
        D_800FB1D8_MinigameStadiumMinigameResultsScreen[i]->player = i;
        D_800FB1E8_MinigameStadiumMinigameResultsScreen[i]->player = i;
    }
    p = func_8005DCD8(func_800F8A00_MinigameStadiumMinigameResultsScreen, 0x3F00, 0x800, 0, proc);
    p->user_data = func_80023684(sizeof(BgWork), 0x7918);
    do {
        HuPrcVSleep();
    } while (D_800FB2A4_MinigameStadiumMinigameResultsScreen == 0);
    while (TRUE) {
        HuPrcVSleep();
    }
}

/* 1: one player won coins and the rest none, 2: one player lost coins, else 0 */
// init order: the counters' two `move rN,zero` are swapped (raw 2, masked 0); declaration and
// init orders, chained and for-clause inits tried
#ifdef NON_MATCHING
s32 func_800F6A3C_MinigameStadiumMinigameResultsScreen(void) {
    s32 i;
    s32 neg;
    s32 zero;

    for (i = 0, neg = 0, zero = 0; i < 4; i++) {
        if (GwPlayer[i].coins_mg == 0) {
            zero++;
        } else if (GwPlayer[i].coins_mg < 0) {
            neg++;
        }
    }
    if (zero == 3 && neg == 0) {
        return 1;
    }
    return (neg == 1) * 2;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_7B_MinigameStadiumMinigameResultsScreen/303E70", func_800F6A3C_MinigameStadiumMinigameResultsScreen);
#endif

s8 func_800F6AC8_MinigameStadiumMinigameResultsScreen(void) {
    s8 ret;

    switch (GwSystem.unk_1E) {
    case 0:
    case 2:
    case 5:
    case 6:
    case 10:
    case 12:
    case 15:
    case 18:
    case 25:
    case 27:
    case 32:
    case 41:
        ret = 0;
        break;
    case 1:
    case 3:
    case 4:
    case 7:
    case 8:
    case 9:
    case 11:
    case 13:
    case 14:
    case 16:
    case 17:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 26:
    case 28:
    case 29:
    case 30:
    case 31:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    default:
        ret = -1;
        break;
    }
    return ret;
}

// decomp-permuter
s8 func_800F6B0C_MinigameStadiumMinigameResultsScreen(void)
{
  s32 i;
  s32 best;
  i = 0;
  best = i;
  for (i = i; i < 4; i++)
  {
    if (GwPlayer[i].coins_mg > GwPlayer[best].coins_mg)
    {
      best = i;
    }
  }

  return best;
}

s8 func_800F6B6C_MinigameStadiumMinigameResultsScreen(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (GwPlayer[i].coins_mg > 0) {
            break;
        }
    }
    return i;
}

s8 func_800F6BAC_MinigameStadiumMinigameResultsScreen(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (GwPlayer[i].coins_mg < 0) {
            break;
        }
    }
    return i;
}

/* A coin column: its four coins are child processes. */
void func_800F6BEC_MinigameStadiumMinigameResultsScreen(void) {
    ColWork* coins[4];
    Process* proc;
    Process* rel;
    ResMain* main;
    ColWork* w;
    PlayerRes* r;
    s32 i;

    proc = HuPrcCurrentGet();
    D_800FB1F8_MinigameStadiumMinigameResultsScreen = proc;
    w = proc->user_data;
    D_800FB1FC_MinigameStadiumMinigameResultsScreen = rel = proc->relative;
    main = rel->user_data;
    for (i = 0; i < 4; i++) {
        D_800FB200_MinigameStadiumMinigameResultsScreen[i] = main->player[i]->user_data;
    }
    for (i = 0; i < 4; i++) {
        w->child[i] = func_8005DCD8(func_800F6DCC_MinigameStadiumMinigameResultsScreen, 0x3F00, 0x800, 0,
                                    D_800FB1F8_MinigameStadiumMinigameResultsScreen);
        w->child[i]->user_data = coins[i] = func_80023684(sizeof(ColWork), 0x7918);
    }
    for (i = 0; i < 4; i++) {
        coins[i]->slot = w->slot = i;
        coins[i]->player = w->player;
        if (D_800FB200_MinigameStadiumMinigameResultsScreen[w->player]->coinsMg > 0) {
            w->flags = 0;
        } else if (D_800FB200_MinigameStadiumMinigameResultsScreen[w->player]->coinsMg < 0) {
            w->flags = 0x20;
        } else {
            w->flags = 0x400;
        }
        r = D_800FB200_MinigameStadiumMinigameResultsScreen[w->player];
        if (r->coinsMg >= 0 && r->coins >= 81) {
            w->step = (r->coins - 61) / 20;
        } else {
            w->step = 0;
        }
    }
    while (TRUE) {
        HuPrcVSleep();
    }
}

/* One coin of a column. */
void func_800F6DCC_MinigameStadiumMinigameResultsScreen(void) {
    Process* proc;
    ColWork* w;
    ColWork* col;
    ResMain* main;
    s32 idx;
    s32 i;

    proc = HuPrcCurrentGet();
    w = proc->user_data;
    col = proc->relative->user_data;
    main = proc->relative->relative->user_data;
    for (i = 0; i < 4; i++) {
        D_800FB210_MinigameStadiumMinigameResultsScreen[i] = main->player[i]->user_data;
    }
    w->ids[0] = func_80023FC8(D_800FB238_MinigameStadiumMinigameResultsScreen);
    func_800258EC(w->ids[0], 4, 0);
    idx = SLOT(w->player, w->slot);
    w->pos.x = D_800FB000[idx];
    w->pos.y = func_800F7158_MinigameStadiumMinigameResultsScreen(
        w->slot, D_800FB210_MinigameStadiumMinigameResultsScreen[w->player]->coins);
    w->pos.z = D_800FB000[idx + 2];
    func_80025798(w->ids[0], w->pos.x, w->pos.y, w->pos.z);
    w->scale.x = w->scale.y = w->scale.z = 1.0f;
    func_80025830(w->ids[0], w->scale.x, w->scale.y, w->scale.z);
    while (D_800FB2A0_MinigameStadiumMinigameResultsScreen == 0) {
        HuPrcVSleep();
    }
    for (i = 0; i < 4; i++) {
        if (D_800FB210_MinigameStadiumMinigameResultsScreen[i]->coinsMg > 0) {
            D_800FB210_MinigameStadiumMinigameResultsScreen[i]->flags = 1;
        } else if (D_800FB210_MinigameStadiumMinigameResultsScreen[i]->coinsMg < 0) {
            D_800FB210_MinigameStadiumMinigameResultsScreen[i]->flags = 2;
        } else {
            D_800FB210_MinigameStadiumMinigameResultsScreen[i]->flags = 0x80;
        }
    }
    while (!(col->flags & 0x400)) {
        HuPrcVSleep();
        if (D_800FB210_MinigameStadiumMinigameResultsScreen[w->player]->coinsMg > 0) {
            if (col->flags & 0x10) {
                do {
                    HuPrcVSleep();
                    func_800F72B0_MinigameStadiumMinigameResultsScreen(w, col);
                } while (col->flags & 0x10);
            } else {
                func_800F7CCC_MinigameStadiumMinigameResultsScreen(w, col,
                    D_800FB210_MinigameStadiumMinigameResultsScreen[w->player]);
            }
        } else if (D_800FB210_MinigameStadiumMinigameResultsScreen[w->player]->coinsMg >= 0) {
        } else {
            while (col->flags & 0x10) {
                HuPrcVSleep();
                func_800F75C0_MinigameStadiumMinigameResultsScreen(w, col);
            }
            func_800F7914_MinigameStadiumMinigameResultsScreen(w, col,
                D_800FB210_MinigameStadiumMinigameResultsScreen[w->player]);
        }
    }
    for (i = 0; i < 4; i++) {
        D_800FB220_MinigameStadiumMinigameResultsScreen[i] = main->col[i]->user_data;
    }
    if (D_800FB210_MinigameStadiumMinigameResultsScreen[0]->coinsMg == 0
        && D_800FB210_MinigameStadiumMinigameResultsScreen[1]->coinsMg == 0
        && D_800FB210_MinigameStadiumMinigameResultsScreen[2]->coinsMg == 0
        && D_800FB210_MinigameStadiumMinigameResultsScreen[3]->coinsMg == 0) {
        D_800FB210_MinigameStadiumMinigameResultsScreen[0]->unk_7A = D_800FB210_MinigameStadiumMinigameResultsScreen[1]->unk_7A =
            D_800FB210_MinigameStadiumMinigameResultsScreen[2]->unk_7A = D_800FB210_MinigameStadiumMinigameResultsScreen[3]->unk_7A = 1;
    }
    while (TRUE) {
        HuPrcVSleep();
    }
}

/* the height of a column's coin slot for a coin count */
f32 func_800F7158_MinigameStadiumMinigameResultsScreen(s8 slot, s16 coins) {
    f32 rem;
    f32 y;

    rem = (s16)(coins % 20);
    if (coins > 80) {
        if (slot != 3) {
            goto top;
        }
        if (rem == 0.0f) {
            goto top;
        }
        goto part;
    }
    if (coins > slot * 20) {
        if (rem == 0.0f || slot < (s16)(coins / 20)) {
        top:
            y = 150.0f;
        } else {
        part:
            y = rem * 22.5f + 150.0f - 450.0f;
        }
    } else {
        y = -300.0f;
    }
    return y;
}

/* rotate the column's coins one slot back (coins won) */
void func_800F72B0_MinigameStadiumMinigameResultsScreen(ColWork* w, ColWork* col) {
    ColWork* c;
    s32 slot;
    s32 i;

    slot = 0;
    if (w->slot == 0) {
        w->pos.y -= 20.0f;
        if (w->pos.y < -300.0f) {
            w->pos.y = -300.0f;
        }
    } else {
        slot = SLOT(w->player, w->slot - 1);
        if (w->slot == 1 || w->slot == 3) {
            w->pos.x -= 10.0f;
            w->pos.z -= 10.0f;
            if (w->pos.x < D_800FB000[slot]) {
                w->pos.x = D_800FB000[slot];
            }
            if (w->slot == 1 && w->pos.z < -100.0f) {
                w->pos.z = -100.0f;
            } else if (w->slot == 3 && w->pos.z < -50.0f) {
                w->pos.z = -50.0f;
            }
        } else if (w->slot == 2) {
            w->pos.x += 10.0f;
            if (w->pos.x > D_800FB000[slot]) {
                w->pos.x = D_800FB000[slot];
            }
        }
    }
    if (w->slot == 2 && w->pos.x == D_800FB000[slot]) {
        col->flags &= ~0x18;
        col->step++;
        for (i = 0; i < 4; i++) {
            c = col->child[i]->user_data;
            if (c->slot == 0) {
                c->slot = 3;
            } else {
                c->slot--;
            }
        }
        for (i = 0; i < 4; i++) {
            c = col->child[i]->user_data;
            slot = SLOT(c->player, c->slot);
            c->pos.x = D_800FB000[slot];
            c->pos.z = D_800FB000[slot + 2];
            if (c->slot == 3) {
                c->pos.y = -300.0f;
            } else {
                c->pos.y = 150.0f;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        c = col->child[i]->user_data;
        func_80025798(c->ids[0], c->pos.x, c->pos.y, c->pos.z);
    }
}

/* rotate the column's coins one slot forward (coins lost) */
// decomp-permuter
void func_800F75C0_MinigameStadiumMinigameResultsScreen(ColWork *w, ColWork *col)
{
  ColWork *c;
  s32 slot;
  s32 i;
  if (w->slot == 3)
  {
    slot = w->player;
    w->pos.x = D_800FB000_MinigameStadiumMinigameResultsScreen[slot * 12];
    w->pos.y = 150.0f;
    w->pos.z = -100.0f;
    func_80025798(w->ids[0], w->pos.x, w->pos.y, w->pos.z);
  }
  else
  {
    slot = (w->player * 12) + ((w->slot + 1) * 3);
    if ((w->slot == 0) || (w->slot == 2))
    {
      w->pos.x += 10.0f;
      w->pos.z += 10.0f;
      if (w->pos.x > D_800FB000_MinigameStadiumMinigameResultsScreen[slot])
      {
        w->pos.x = D_800FB000_MinigameStadiumMinigameResultsScreen[slot];
      }
      if ((w->slot == 0) && (w->pos.z > (-50.0f)))
      {
        w->pos.z = -50.0f;
      }
      else
        if ((w->slot == 2) && (w->pos.z > 0.0f))
      {
        w->pos.z = 0.0f;
      }
    }
    else
      if (w->slot == 1)
    {
      w->pos.x -= 10.0f;
      if (w->pos.x < D_800FB000_MinigameStadiumMinigameResultsScreen[slot])
      {
        w->pos.x = D_800FB000_MinigameStadiumMinigameResultsScreen[slot];
      }
    }
    w->pos.y = 150.0f;
    func_80025798(w->ids[0], w->pos.x, w->pos.y, w->pos.z);
  }
  slot = (w->player * 12) + (2 * 3);
  if (((w->slot == 1) && (w->pos.x == D_800FB000_MinigameStadiumMinigameResultsScreen[slot])) && (w->pos.z == (-50.0f)))
  {
    for (i = 0; i < 4; i++)
    {
      c = col->child[i]->user_data;
      if (c->slot == 3)
      {
        c->slot = 0;
      }
      else
      {
        c->slot++;
      }
    }

    for (i = 0; i < 4; i++)
    {
      c = col->child[i]->user_data;
      slot = (c->player * 12) + (c->slot * 3);
      c->pos.x = D_800FB000_MinigameStadiumMinigameResultsScreen[slot];
      c->pos.z = D_800FB000_MinigameStadiumMinigameResultsScreen[slot + 2];
      c->pos.y = 150.0f;
      func_80025798(c->ids[0], c->pos.x, 150.0f, c->pos.z);
    }

    col->flags &= ~0x210;
    col->step++;
  }
}

void func_800F7914_MinigameStadiumMinigameResultsScreen(ColWork* w, ColWork* col, PlayerRes* res) {
    func_800258EC(w->ids[0], 4, 0);
    switch (w->slot) {
    case 0:
        if (COL_FLAGS_TEST(col, 0x04800000, 0x00800000)) {
            func_800F7A40_MinigameStadiumMinigameResultsScreen(w, col, res);
        }
        w->pos.z = -100.0f;
        break;
    case 1:
        if (COL_FLAGS_TEST(col, 0x05000000, 0x01000000)) {
            func_800F7A40_MinigameStadiumMinigameResultsScreen(w, col, res);
        }
        w->pos.z = -50.0f;
        break;
    case 2:
        if (COL_FLAGS_TEST(col, 0x06000000, 0x02000000)) {
            func_800F7A40_MinigameStadiumMinigameResultsScreen(w, col, res);
        }
        w->pos.z = -50.0f;
        break;
    case 3:
        func_800F7A40_MinigameStadiumMinigameResultsScreen(w, col, res);
        w->pos.z = 0.0f;
        break;
    }
    func_80025798(w->ids[0], w->pos.x, w->pos.y, w->pos.z);
}

/* lower a coin out of the column (coins lost) */
// retail computes res->coins % 20 up to the quotient and drops it (dead code GCC kept); C has no use for it
#ifdef NON_MATCHING
void func_800F7A40_MinigameStadiumMinigameResultsScreen(ColWork* w, ColWork* col, PlayerRes* res) {
    f32 rem;
    f32 target;
    u16 f;

    rem = (s16)(res->coins % 20);
    rem = (f32)(s16)(res->total % 20);
    if (rem == 0.0f) {
        target = -300.0f;
    } else {
        target = rem * 22.5f + 150.0f - 450.0f;
    }
    if (w->pos.y > -300.0f && !(col->flags & 0x10)) {
        if (-res->coinsMg > res->unk_78) {
            w->pos.y -= 22.5f;
            res->unk_78++;
        }
        if (w->pos.y <= target && -res->coinsMg == res->unk_78) {
            w->pos.y = target;
            col->flags |= 0x400;
        }
    } else {
        w->pos.y = -300.0f;
        switch (w->slot) {
        case 3:
            col->flags |= 0x200;
            break;
        case 2:
            col->flags |= 0x100;
            break;
        case 1:
            col->flags |= 0x80;
            break;
        case 0:
            col->flags |= 0x40;
            break;
        }
    }
    if (res->coins < 81 || res->coins - res->unk_78 < 80 || (res->coins - res->unk_78) % 20 != 0
        || D_800FB230_MinigameStadiumMinigameResultsScreen != col->step || ((f = col->flags) & 0x10)) {
        col->flags &= ~0x10;
    } else {
        col->flags = f | 0x10;
    }
    if (!(col->flags & 0x10)) {
        D_800FB230_MinigameStadiumMinigameResultsScreen = col->step;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_7B_MinigameStadiumMinigameResultsScreen/303E70", func_800F7A40_MinigameStadiumMinigameResultsScreen);
#endif

void func_800F7CCC_MinigameStadiumMinigameResultsScreen(ColWork* w, ColWork* col, PlayerRes* res) {
    func_800258EC(w->ids[0], 4, 0);
    if (D_800FB29C_MinigameStadiumMinigameResultsScreen != 0) {
        switch (w->slot) {
        case 0:
            func_800F7D94_MinigameStadiumMinigameResultsScreen(w, col, res);
            break;
        case 1:
        case 2:
        case 3:
            if ((col->flags & D_800FB0C0[w->slot - 1]) && !(col->flags & 0x400)) {
                func_800F7D94_MinigameStadiumMinigameResultsScreen(w, col, res);
            }
            break;
        }
        func_80025798(w->ids[0], w->pos.x, w->pos.y, w->pos.z);
    }
}

/* raise a coin into the column (coins won) */
// decomp-permuter
void func_800F7D94_MinigameStadiumMinigameResultsScreen(ColWork *w, ColWork *col, PlayerRes *res)
{
  f32 y;
  int new_var;
  s32 n;
  n = w->slot;
  new_var = col->step + 1;
  n = new_var + n;
  y = w->pos.y;
  if (y < 150.0f)
  {
    if (res->unk_70 > res->unk_74)
    {
      w->pos.y = y + 22.5f;
      if (res->coinsMg >= res->unk_70)
      {
        res->unk_74++;
      }
    }
    if ((res->unk_70 >= res->coinsMg) && (res->total < (n * 20)))
    {
      if (!(col->flags & 0x10))
      {
        col->flags |= 0x400;
      }
    }
  }
  else
  {
    w->pos.y = 150.0f;
    if (res->total > (n * 20))
    {
      col->flags |= (u16) D_800FB0C0_MinigameStadiumMinigameResultsScreen[w->slot];
      if ((col->flags & 8) && (res->total > ((col->step + 4) * 20)))
      {
        col->flags |= 0x10;
        res->flags |= 0x40;
      }
    }
    else
      if (res->total == (n * 20))
    {
      col->flags |= (u16) D_800FB0C0_MinigameStadiumMinigameResultsScreen[w->slot];
      if (!(col->flags & 0x10))
      {
        col->flags |= 0x400;
      }
    }
  }
}

void func_800F7F0C_MinigameStadiumMinigameResultsScreen(void) {
    s16 cam;

    func_8004B1B8();
    func_800178A0(1);
    cam = func_800178E8();
    func_80017660(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(cam, 12.0f, 80.0f, 8000.0f);
    Center.x = -10.0f;
    Center.y = 420.0f;
    Center.z = -50.0f;
    CRot.x = -22.5f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    CZoom = 5000.0f;
}

void func_800F8040_MinigameStadiumMinigameResultsScreen(omObjData* obj) {
    s32 go;
    s32 i;

    go = 0;
    if (D_800FB2A4_MinigameStadiumMinigameResultsScreen != 0) {
        for (i = 0; i < 4; i++) {
            if (ContBtn[i] & 0x8000) {
                go = 1;
                break;
            }
        }
        D_800FB232_MinigameStadiumMinigameResultsScreen++;
        if (D_800FB232_MinigameStadiumMinigameResultsScreen >= 61) {
            go = 1;
        }
        if (go) {
            for (i = 0; i < 4; i++) {
                AdjustPlayerCoins(i, GwPlayer[i].coins_mg);
                GwPlayer[i].coins_total += GwPlayer[i].coins_mg;
                if (GwPlayer[i].coins_total > 30000) {
                    GwPlayer[i].coins_total = 30000;
                }
                if (GwPlayer[i].coins_total < -30000) {
                    GwPlayer[i].coins_total = -30000;
                }
            }
            func_800726AC(0, 0x14);
            func_800601D4(0x28);
            obj->func_ptr = &func_800F81C0_MinigameStadiumMinigameResultsScreen;
        }
    }
}

void func_800F81C0_MinigameStadiumMinigameResultsScreen(omObjData* obj) {
    if (func_80072718() != 1) {
        func_8004A140();
        func_80049F0C();
        omOvlReturnEx(1);
    }
}

/* The coins dropping onto a winner's column: five {model, sprite} pairs. */
// register allocation: the reset branch keeps the pair pointer in s0 (beqzl), C in s1
#ifdef NON_MATCHING
void func_800F8200_MinigameStadiumMinigameResultsScreen(void) {
    PlayerRes* res[4];
    ColWork* cols[4];
    Vec3f pos;
    Vec2f scr;
    Process* proc;
    ColWork* w;
    ResMain* main;
    s32 i;
    s32 j;
    s32 best;
    s32 n;
    s32 frame;

    while (D_800FB2A0_MinigameStadiumMinigameResultsScreen == 0) {
        HuPrcVSleep();
    }
    proc = HuPrcCurrentGet();
    w = proc->user_data;
    main = proc->relative->user_data;
    for (i = 0; i < 4; i++) {
        res[i] = main->player[i]->user_data;
    }
    if (res[w->player]->coinsMg > 0) {
        w->count = 1;
        for (i = 0; i < 10; i += 2) {
            w->ids[i] = func_80023FC8(D_800FB23A_MinigameStadiumMinigameResultsScreen);
            func_800258EC(w->ids[i], 4, 0);
            w->ids[i + 1] = func_80019060(D_800FB2A2_MinigameStadiumMinigameResultsScreen, 0, 1);
            func_80018D84(w->ids[i + 1], 0x10);
            func_80018F68(w->ids[i + 1], 0xFF, 0xFF, 0xBE);
            func_80018C90(w->ids[i + 1]);
            w->pos.x = D_800FB000[w->player * 12];
            w->y[i] = i * 50.0f + 950.0f;
            w->pos.z = 0.0f;
            func_80025798(w->ids[i], w->pos.x, w->y[i], w->pos.z);
            pos.x = w->pos.x;
            pos.y = w->y[i] + 5.0f;
            pos.z = w->pos.z;
            Convert3DTo2D(0, &pos, &scr);
            SetBasicSpritePos(w->ids[i + 1], scr.x, scr.y);
            func_80018E0C(w->ids[i + 1], 0);
            w->rot.x = w->rot.y = w->rot.z = 0.0f;
            func_800257E4(w->ids[i], w->rot.x, w->rot.y, w->rot.z);
            w->scale.x = w->scale.y = w->scale.z = 1.2f;
            func_80025830(w->ids[i], w->scale.x, w->scale.y, w->scale.z);
            SetBasicSpriteSize(w->ids[i + 1], 1.0f, 1.0f);
        }
        j = 0;
        for (i = 0; i < 4; i++) {
            if (res[i]->coinsMg > res[j]->coinsMg) {
                j = i;
            }
        }
        best = j;
        for (i = 0; i < 4; i++) {
            cols[i] = main->col[i]->user_data;
        }
        frame = 0;
        while (TRUE) {
            n = 10;
            HuPrcVSleep();
            if (res[w->player]->coinsMg < 5) {
                n = res[w->player]->coinsMg * 2;
            }
            for (i = 0; i < n; i += 2) {
                if (res[w->player]->flags & 0x100) {
                    func_80018C90(w->ids[i + 1]);
                }
                if (w->y[i] <= res[w->player]->pos.y + 100.0f) {
                    D_800FB29C_MinigameStadiumMinigameResultsScreen = 1;
                    func_800258EC(w->ids[i], 4, 4);
                    if (frame < 15) {
                        func_80018E0C(w->ids[i + 1], frame);
                        if (res[w->player]->flags & 0x100) {
                            func_80018C90(w->ids[i + 1]);
                            frame += 2;
                        } else {
                            ShowBasicSprite(w->ids[i + 1]);
                            frame += 2;
                        }
                    } else {
                        w->y[i] = i * 50.0f + 950.0f;
                        func_80025798(w->ids[i], w->pos.x, w->y[i], w->pos.z);
                        frame = 0;
                        pos.x = w->pos.x;
                        pos.y = w->y[i] + 5.0f;
                        pos.z = w->pos.z;
                        Convert3DTo2D(0, &pos, &scr);
                        SetBasicSpritePos(w->ids[i + 1], scr.x, scr.y);
                        func_80018E0C(w->ids[i + 1], 0);
                        func_80018C90(w->ids[i + 1]);
                        if (res[w->player]->index == best) {
                            if (D_800FB234_MinigameStadiumMinigameResultsScreen < res[w->player]->coinsMg) {
                                PlaySound(0xFC);
                                D_800FB234_MinigameStadiumMinigameResultsScreen++;
                                for (j = 0; j < 4; j++) {
                                    if (res[j]->coinsMg > 0) {
                                        res[j]->unk_70++;
                                    }
                                }
                                goto check;
                            }
                            goto set;
                        }
                    check:
                        if (D_800FB234_MinigameStadiumMinigameResultsScreen >= res[w->player]->coinsMg) {
                        set:
                            res[w->player]->flags |= 0x100;
                        }
                    }
                    if (w->count >= res[w->player]->coinsMg) {
                        res[w->player]->flags &= ~4;
                    }
                } else {
                    if (w->count < res[w->player]->coinsMg) {
                        func_800258EC(w->ids[i], 4, 0);
                    }
                    if (w->y[i] == i * 50.0f + 950.0f) {
                        w->count++;
                    }
                    w->rot.y += 20.0f;
                    w->rot.z += 20.0f;
                    func_800257E4(w->ids[i], w->rot.x + 10.0f, w->rot.y, w->rot.z);
                    w->y[i] -= 30.0f;
                    func_80025798(w->ids[i], w->pos.x, w->y[i], w->pos.z);
                    pos.x = w->pos.x;
                    pos.z = w->pos.z;
                    pos.y = w->y[i] + 5.0f;
                    Convert3DTo2D(0, &pos, &scr);
                    SetBasicSpritePos(w->ids[i + 1], scr.x, scr.y);
                    func_80018C90(w->ids[i + 1]);
                }
            }
        }
    }
    while (TRUE) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_7B_MinigameStadiumMinigameResultsScreen/303E70", func_800F8200_MinigameStadiumMinigameResultsScreen);
#endif
