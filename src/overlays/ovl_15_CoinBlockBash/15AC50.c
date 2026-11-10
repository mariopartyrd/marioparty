#include "15AC50.h"

/* ---------------------------------------------------------------------------------------------
   Data
   --------------------------------------------------------------------------------------------- */

s32 D_80101C00_CoinBlockBash = 0;
s32 D_80101C04_CoinBlockBash = 0;
char D_80101C08_CoinBlockBash[9][8] = {
    "bl00", "bl01", "bl02", "bl03", "bl04", "bl05", "bl06", "bl07", "bl08",
};
char D_80101C50_CoinBlockBash[9][8] = {
    "kg00", "kg01", "kg02", "kg03", "kg04", "kg05", "kg06", "kg07", "kg08",
};
s16 D_80101C98_CoinBlockBash[4][2] = { { 0, 0xFC }, { 0, 0x109 }, { 0, 0xFC }, { 0, 0x109 } };
s16 D_80101CA8_CoinBlockBash[4] = { 0, 0x3000, 0x2000, 0 };

/* ---------------------------------------------------------------------------------------------
   Coin blocks and drops
   --------------------------------------------------------------------------------------------- */

void func_800FE650_CoinBlockBash(void) {
    func_800FFED0_CoinBlockBash(0x40);
    func_800FE684_CoinBlockBash();
    func_800FEA5C_CoinBlockBash();
    func_80101748_CoinBlockBash();
}

void func_800FE684_CoinBlockBash(void) {
    s32 types[9] = { 1, 0, 0, 0, 0, 0, 1, 1, 1 };
    s32 files[4] = { 0x21, 0x37, 0x2A, 0x270005 };
    CBBDropFull* d;
    void* data;
    s32 i;

    D_80103290_CoinBlockBash = HuMemDirectMalloc(9 * sizeof(CBBDropFull));
    for (i = 0; i < 4; i++) {
        data = DataRead(files[i]);
        D_80103248_CoinBlockBash[i] = func_800678A4(data);
        DataClose(data);
    }
    D_80103244_CoinBlockBash = func_800174C0(0x350007, 0xDD);
    for (i = 0; i < 9; i++) {
        d = &CBB_DROPS[i];
        d->state = 0;
        d->active = 0;
        d->coin = NULL;
        d->type = types[i];
        d->pos.x = d->pos.y = d->pos.z = 0.0f;
        d->unk_28 = d->unk_2C = 2.5f;
        d->unk_30 = 1.0f;
        d->vel.x = d->vel.y = d->vel.z = 0.0f;
        d->radius = 30.0f;
        d->timer = 300;
        d->obj = NULL;
        d->unk_40 = 0.0f;
    }
    D_80103240_CoinBlockBash = 9;
}

/* The index of the model's object called name, or -1. */
// NON_MATCHING: frame size only (masked 10, raw 12): retail has 8 bytes of locals at 0x10, ours
// (s16 unused[2]) gives 16; body identical (M1c)
#ifdef NON_MATCHING
s16 func_800FE854_CoinBlockBash(unk2C0C0StructC0* model, char* name) {
    unk2C0C0Struct30* p = model->unk_80;
    s16 unused[2];
    s32 i;

    func_8001CD00((u8*)name);
    for (i = 0; i < model->unk_6A; i++, p++) {
        if (func_8009B850(p->unk_18, name) == 0) {
            return i;
        }
    }
    return -1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/15AC50", func_800FE854_CoinBlockBash);
#endif

/* The part of model that draws its object called name, or (unk2C0C0Struct50*)-1. */
// NON_MATCHING: register allocation of the found index (re-sign-extended twice in retail)
// decomp-permuter
unk2C0C0Struct50 *func_800FE8DC_CoinBlockBash(s16 model, char *name)
{
  unk2C0C0StructC0 *m = D_800F2B7C[model].unk_6C;
  s16 id = func_800FE854_CoinBlockBash(m, name);
  s16 count;
  s16 i;
  s16 j;
  if (m->unk_A0 == ((unk2C0C0Struct50 *) (-1)))
  {
    return (unk2C0C0Struct50 *) (-1);
  }
  for (i = 0; i < m->unk_70; i++)
  {
    count = m->unk_A0[i].unk_00;
    for (j = 0; j < count; j++)
    {
      if (m->unk_A0[i].unk_04[j] == id)
      {
        break;
      }
    }

    if (j != count)
    {
      break;
    }
  }

  if (i == m->unk_70)
  {
 do { } while (0);
    return (unk2C0C0Struct50 *) (-1);
  }
  return &m->unk_A0[i];
}

// NON_MATCHING: retail keeps &D_80103222 in s6 across the block loop
#ifdef NON_MATCHING
void func_800FEA5C_CoinBlockBash(void) {
    CBBCoinFull* c;
    CBBDropFull* d;
    f32 sx;
    f32 sz;
    s32 i;
    s32 j;
    s32 k;

    D_80103220_CoinBlockBash = func_800174C0(0x270002, 0xD9);
    for (j = 0; j < 5; j++) {
        D_80103228_CoinBlockBash[4 - j] = *func_80026A0C(D_80103222_CoinBlockBash, D_80101C08_CoinBlockBash[j])->unk_04;
    }
    D_80103294_CoinBlockBash = HuMemDirectMalloc(9 * sizeof(CBBCoinFull));
    sz = 303.33334f; /* 910 / 3 */
    sx = sz;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            c = &CBB_COINS[j + i * 3];
            if (i < 2) {
                do {
                    k = (u8)(rand8() % 9);
                } while (CBB_DROPS[k].coin != NULL);
            } else {
                for (k = 0; k < 9; k++) {
                    if (CBB_DROPS[k].coin == NULL) {
                        break;
                    }
                }
            }
            d = &CBB_DROPS[k];
            c->drop = d;
            d->coin = c;
            c->pos.x = d->pos.x = sx * (j + 0.5) + -480.0;
            c->pos.z = d->pos.z = sz * (i + 0.5) + -470.0;
            c->pos.y = d->pos.y = 270.0f;
            c->state = 0;
            c->bb = -1;
            c->unk_1C = 50.0f;
            c->unk_10 = 10;
            c->timer = 0;
            c->hittable = 1;
            c->blk = func_800FE8DC_CoinBlockBash(D_80103222_CoinBlockBash, D_80101C08_CoinBlockBash[j + i * 3]);
            c->shadow = func_800FE8DC_CoinBlockBash(D_80103222_CoinBlockBash, D_80101C50_CoinBlockBash[j + i * 3]);
            func_800FFE64_CoinBlockBash(c->blk, c->pos.x, c->pos.y, c->pos.z);
            func_800FFE64_CoinBlockBash(c->shadow, c->pos.x, -5.0f, c->pos.z);
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            c = &CBB_COINS[j + i * 3];
            func_800FFE84_CoinBlockBash(c->blk, D_80103228_CoinBlockBash[(c->unk_10 - 1) >> 1]);
        }
    }
    D_8010323C_CoinBlockBash = 9;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/15AC50", func_800FEA5C_CoinBlockBash);
#endif

void func_800FEE04_CoinBlockBash(void) {
    D_80101C00_CoinBlockBash = (D_80101C00_CoinBlockBash + 1) % 3;
    func_800FEE90_CoinBlockBash();
    func_800FF2B0_CoinBlockBash();
    if (D_80101C04_CoinBlockBash != 0) {
        func_800FFBB8_CoinBlockBash(D_80101C04_CoinBlockBash);
        D_80101C04_CoinBlockBash++;
    }
    func_80101748_CoinBlockBash();
}

/* Blocks: the bounce after a hit, and the flight of a broken one. */
void func_800FEE90_CoinBlockBash(void) {
    CBBCoinFull* c;
    s16 gone = 0;
    s32 i;
    s32 j;
    f32 s;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            c = &CBB_COINS[j + i * 3];
            switch (c->state) {
                case 0:
                    break;
                case 1:
                    c->pos.y = func_800AEFD0(c->timer) * 0.6 * 100.0 + 270.0;
                    func_800FFE64_CoinBlockBash(c->blk, c->pos.x, c->pos.y, c->pos.z);
                    s = 1.0 - func_800AEFD0(c->timer) * 0.15;
                    func_800FFE74_CoinBlockBash(c->shadow, s, 1.0f, 1.0 - func_800AEFD0(c->timer) * 0.15);
                    if (c->timer >= 90) {
                        c->hittable = 1;
                        c->state = 2;
                    }
                case 2:
                    func_80100304_CoinBlockBash(c->bb, c->pos.x, 270.0 - func_800AEAC0(c->timer * 0.5) * 1.5 * 100.0,
                                                c->pos.z);
                    func_8010034C_CoinBlockBash(c->bb, 4.5f, 4.5f, 1.0f);
                    if (c->timer >= 180) {
                        c->timer = 0;
                        c->state = 0;
                        func_80100454_CoinBlockBash(c->bb);
                        c->bb = -1;
                    }
                    c->timer += 18;
                    break;
                case 3:
                    if (c->angle != -361.0f) {
                        c->pos.x += func_800AEAC0(c->angle) * 0.2 * 100.0;
                        c->pos.z += func_800AEFD0(c->angle) * 0.2 * 100.0;
                        if (c->pos.x <= -405.0) {
                            c->pos.x = -405.0f;
                        }
                        if (c->pos.z <= -395.0) {
                            c->pos.z = -395.0f;
                        }
                    }
                    c->pos.y = func_800AEAC0(c->timer * 12.8) * 0.625 * 100.0 + 270.0;
                    func_80100304_CoinBlockBash(c->bb, c->pos.x, c->pos.y, c->pos.z);
                    func_8010034C_CoinBlockBash(c->bb, 6.0f, 6.0f, 1.0f);
                    c->timer++;
                    if (D_80103298_CoinBlockBash[c->bb].flags & 0x10) {
                        c->state = 4;
                        func_80100454_CoinBlockBash(c->bb);
                        c->bb = -1;
                    }
                    break;
                case 4:
                    gone++;
                    break;
            }
        }
    }
    D_8010323C_CoinBlockBash = 9 - gone;
}

/* Drops: rising out of a block, bobbing on the floor, blinking out, or spiralling into a player. */
void func_800FF2B0_CoinBlockBash(void) {
    CBBDropFull* d;
    s16 gone = 0;
    s32 i;
    f32 s;
    s16 id;

    for (i = 0; i < 9; i++) {
        d = &CBB_DROPS[i];
        switch (d->state) {
            case 0:
                break;
            case 5:
                gone++;
                break;
            case 1:
            case 2:
            case 3:
                if (d->state == 1) {
                    d->vel.y += -4.0;
                    d->pos.y += d->vel.y;
                    if (d->timer & 1) {
                        func_80100394_CoinBlockBash(d->bb, 0x10);
                    } else {
                        func_801003D0_CoinBlockBash(d->bb, 0x10);
                    }
                    if (d->pos.y <= 15.0) {
                        func_801003D0_CoinBlockBash(d->bb, 0x10);
                        d->active = 1;
                        d->pos.y = 15.0f;
                        d->state = 2;
                        d->unk_14 = 0;
                    }
                } else if (d->type == 0) {
                    d->unk_14 = (d->unk_14 + 9) % 180;
                    d->pos.y = func_800AEAC0(d->unk_14) * 1.2 * 100.0 + 15.0;
                    if (d->unk_14 < 9) {
                        PlaySound(0x108);
                    }
                }
                d->pos.x += d->vel.x;
                d->pos.z += d->vel.z;
                if (d->pos.x <= -480.0 || d->pos.x >= 430.0) {
                    d->vel.x = -d->vel.x;
                }
                if (d->pos.z <= -470.0 || d->pos.z >= 440.00000000000006) {
                    d->vel.z = -d->vel.z;
                }
                s = (1.0 - d->pos.y / 100.0 * 0.15) * 0.8;
                if (s <= 0.0) {
                    s = 0.01f;
                }
                func_80100304_CoinBlockBash(d->bb, d->pos.x, d->pos.y, d->pos.z);
                func_80100304_CoinBlockBash(d->shadow, d->pos.x, 15.0f, d->pos.z);
                func_8010034C_CoinBlockBash(d->bb, d->unk_28, d->unk_2C, 1.0f);
                func_8010034C_CoinBlockBash(d->shadow, s, 0.8f, s);
                if (--d->timer < 61) {
                    d->state = 3;
                    if (d->timer & 2) {
                        func_80100394_CoinBlockBash(d->bb, 0x10);
                    } else {
                        func_801003D0_CoinBlockBash(d->bb, 0x10);
                    }
                    if (d->timer <= 0) {
                        func_80100454_CoinBlockBash(d->bb);
                        func_80100454_CoinBlockBash(d->shadow);
                        d->state = 5;
                        d->active = 0;
                    }
                }
                if (D_80101C04_CoinBlockBash != 0) {
                    func_80100264_CoinBlockBash(d->bb, D_80103252_CoinBlockBash);
                    func_80100394_CoinBlockBash(d->bb, 0x20);
                    func_801003D0_CoinBlockBash(d->bb, 0x10);
                    func_8010034C_CoinBlockBash(d->bb, 2.0 * (d->unk_28 + 1.0), 2.0 * (d->unk_2C + 1.0), 1.0f);
                    func_80100410_CoinBlockBash(d->bb, 0xFF, 0xFF, 0xBE, 0xFF);
                    func_80100454_CoinBlockBash(d->shadow);
                    func_801002CC_CoinBlockBash(d->bb, 0.75f);
                    d->state = 5;
                }
                break;
            case 4:
                d->pos.x = d->obj->trans.x + func_800AEAC0(d->unk_14 * 20 + d->unk_40) * 0.8 * 100.0;
                d->pos.y = d->unk_14 * 0.04 * 100.0 + 15.0;
                d->pos.z = d->obj->trans.z - func_800AEFD0(d->unk_14 * 20 + d->unk_40) * 0.8 * 100.0;
                if (!(d->unk_14 & 3)) {
                    id = func_801000B8_CoinBlockBash(D_80103252_CoinBlockBash, 0x28);
                    func_80100304_CoinBlockBash(id, d->pos.x, d->pos.y, d->pos.z);
                    func_8010034C_CoinBlockBash(id, 2.0 * (d->unk_28 + 1.0), 2.0 * (d->unk_2C + 1.0), 1.0f);
                    func_80100410_CoinBlockBash(id, 0xFF, 0xFF, 0xBE, 0xFE);
                    func_801002CC_CoinBlockBash(id, 0.75f);
                }
                func_80100304_CoinBlockBash(d->bb, d->pos.x, d->pos.y, d->pos.z);
                if (++d->unk_14 >= 24) {
                    d->state = 5;
                    func_80100454_CoinBlockBash(d->bb);
                }
                break;
        }
    }
    D_80103240_CoinBlockBash = 9 - gone;
}

/* A player hits block coin for damage hits (10: a hammer smash). Returns 1 if it broke, 0 if it
   only bounced, -1 if it cannot be hit now. */
s16 func_800FF904_CoinBlockBash(omObjData* obj, s32 damage, CBBCoin* coin) {
    CBBCoinFull* c = (CBBCoinFull*)coin;
    CBBDropFull* d;
    s16 hits;
    f32 a;

    if (c->hittable == 0) {
        return -1;
    }
    hits = c->unk_10 - damage;
    c->unk_10 = hits;
    c->hittable = 0;
    if (hits <= 0) {
        func_800FFE90_CoinBlockBash(c->blk);
        func_800FFE90_CoinBlockBash(c->shadow);
        c->unk_10 = 0;
        c->timer = 0;
        if (damage == 10) {
            c->angle = obj->rot.y;
            PlaySound(0x270);
        } else {
            c->angle = -361.0f;
            PlaySound(0x195);
        }
        c->state = 3;
        if (c->bb != -1) {
            func_80100454_CoinBlockBash(c->bb);
        }
        c->bb = func_801000B8_CoinBlockBash(D_80103256_CoinBlockBash, 8);
        func_80100394_CoinBlockBash(c->bb, 4);
        func_801002CC_CoinBlockBash(c->bb, 1.0f);
        a = func_800B0CD8(obj->trans.x - c->pos.x, -(obj->trans.z - c->pos.z)) + 180.0;
        d = c->drop;
        d->bb = func_801000B8_CoinBlockBash(CBB_SPRITE(d->type), 8);
        d->shadow = func_80100160_CoinBlockBash(D_80103246_CoinBlockBash, 8);
        d->state = 1;
        d->vel.y = 28.0f;
        d->vel.x = func_800AEAC0(a) * 0.05 * 100.0;
        d->vel.z = func_800AEFD0(a) * -0.05 * 100.0;
        return 1;
    }
    c->timer = 0;
    c->state = 1;
    if (c->bb != -1) {
        func_80100454_CoinBlockBash(c->bb);
    }
    c->bb = func_801000B8_CoinBlockBash(D_80103256_CoinBlockBash, 8);
    func_80100394_CoinBlockBash(c->bb, 4);
    func_801002CC_CoinBlockBash(c->bb, 1.0f);
    if (c->bb != -1) {
        D_80103298_CoinBlockBash[c->bb].frame = 4;
    }
    func_800FFE84_CoinBlockBash(c->blk, D_80103228_CoinBlockBash[(c->unk_10 - 1) >> 1]);
    PlaySound(0x194);
    return 0;
}

void func_800FFBA8_CoinBlockBash(void) {
    D_80101C04_CoinBlockBash = 1;
}

/* Time up: on even frames, break the first block still standing (retail picks it twice). */
s32 func_800FFBB8_CoinBlockBash(s32 time) {
    s32 idx[2];
    CBBCoinFull* c;
    s32 i;
    s32 k;

    if (!(time & 1)) {
        for (i = 0; i < 9; i++) {
            c = CBB_DROPS[i].coin;
            if (c->hittable != 0) {
                break;
            }
        }
        if (i == 9) {
            return 1;
        }
        for (idx[0] = i; i < 9; i++) {
            c = CBB_DROPS[i].coin;
            if (c->hittable != 0) {
                break;
            }
        }
        idx[1] = i;
        for (k = 0; k < 2; k++) {
            if (idx[i] == 9) {
                return 1;
            }
            c = CBB_DROPS[idx[k]].coin;
            c->hittable = 0;
            func_800FFE90_CoinBlockBash(c->blk);
            func_800FFE90_CoinBlockBash(c->shadow);
            c->unk_10 = 0;
            c->timer = 0;
            c->angle = -361.0f;
            c->state = 3;
            if (c->bb != -1) {
                func_80100454_CoinBlockBash(c->bb);
            }
            c->bb = func_801000B8_CoinBlockBash(D_80103256_CoinBlockBash, 8);
            func_80100394_CoinBlockBash(c->bb, 4);
            func_801002CC_CoinBlockBash(c->bb, 1.0f);
        }
    }
    return 0;
}

s16 func_800FFD60_CoinBlockBash(void) {
    return D_8010323E_CoinBlockBash;
}

s16 func_800FFD6C_CoinBlockBash(void) {
    return D_80103242_CoinBlockBash;
}

/* A player picks up drop. */
// NON_MATCHING: retail returns d->type (or -1 if not active); callers ignore it and CoinBlockBash.h declares void
#ifdef NON_MATCHING
void func_800FFD78_CoinBlockBash(CBBDrop* drop, omObjData* obj) {
    CBBDropFull* d = (CBBDropFull*)drop;

    if (d->active != 0) {
        d->state = 4;
        d->active = 0;
        d->unk_14 = 0;
        func_801003D0_CoinBlockBash(d->bb, 0x10);
        func_80100454_CoinBlockBash(d->shadow);
        d->obj = obj;
        d->unk_40 = obj->rot.y;
        d->unk_2C = 2.5f;
        d->unk_28 = 2.5f;
        func_8010034C_CoinBlockBash(d->bb, 2.5f, d->unk_2C, 1.0f);
        func_80060540(D_80101C98_CoinBlockBash[d->type][1], obj->work[0]);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/15AC50", func_800FFD78_CoinBlockBash);
#endif

void func_800FFE30_CoinBlockBash(void) {
    HuMemDirectFree(D_80103290_CoinBlockBash);
    HuMemDirectFree(D_80103294_CoinBlockBash);
    func_80101A5C_CoinBlockBash();
}

void func_800FFE64_CoinBlockBash(unk2C0C0Struct50* node, f32 x, f32 y, f32 z) {
    node->unk_64[3][0] = x;
    node->unk_64[3][1] = y;
    node->unk_64[3][2] = z;
}

void func_800FFE74_CoinBlockBash(unk2C0C0Struct50* node, f32 x, f32 y, f32 z) {
    node->unk_64[0][0] = x;
    node->unk_64[1][1] = y;
    node->unk_64[2][2] = z;
}

void func_800FFE84_CoinBlockBash(unk2C0C0Struct50* node, s32 tex) {
    node->unk_04[0] = tex;
}

/* Moves a model part out of view. */
void func_800FFE90_CoinBlockBash(unk2C0C0Struct50* node) {
    node->unk_64[3][0] = 12700.0f;
    node->unk_64[3][1] = -fabs(node->unk_64[3][1]) - 100.0;
    node->unk_64[3][2] = 12700.0f;
}

/* ---------------------------------------------------------------------------------------------
   Billboards (ovl_2E HotRopeJump's library)
   --------------------------------------------------------------------------------------------- */

void func_800FFED0_CoinBlockBash(u8 count) {
    CBBBill* fx;
    s16 i;

    D_80103258_CoinBlockBash = count;
    for (i = 0; i < 3; i++) {
        D_80103284_CoinBlockBash[i] = HuMemDirectMalloc(D_80103258_CoinBlockBash * (8 * sizeof(Vtx)));
        D_80103278_CoinBlockBash[i] = HuMemDirectMalloc(D_80103258_CoinBlockBash * (32 * sizeof(Gfx)));
        D_8010325C_CoinBlockBash[i] = HuMemDirectMalloc(D_80103258_CoinBlockBash * (20 * sizeof(Gfx)));
        D_80103268_CoinBlockBash[i] = HuMemDirectMalloc(D_80103258_CoinBlockBash * sizeof(Mtx));
    }
    D_80103274_CoinBlockBash = func_80024198(0x19, D_8010325C_CoinBlockBash[0], 4);
    D_80103298_CoinBlockBash = HuMemDirectMalloc(D_80103258_CoinBlockBash * sizeof(CBBBill));
    for (i = 0; i < D_80103258_CoinBlockBash; i++) {
        fx = &D_80103298_CoinBlockBash[i];
        fx->dl = (Gfx*)-1;
        fx->unk_08 = 0;
        fx->flags = 0;
        fx->sprite = 0;
        fx->a = fx->r = fx->g = fx->b = 0xFF;
        fx->timer = 0;
        fx->frame = 0;
        fx->unk_0E = 0;
        fx->speed = 1.0f;
        fx->pos.x = fx->pos.y = fx->pos.z = 0.0f;
        fx->scale.x = fx->scale.y = 0.0f;
    }
}

// NON_MATCHING: scheduling of the slot address
// decomp-permuter
s16 func_801000B8_CoinBlockBash(s16 sprite, u8 flags)
{
  CBBBill *fx;
  s16 i;
  for (i = 0; i < D_80103258_CoinBlockBash; i++)
  {
    if (D_80103298_CoinBlockBash[i].dl == ((Gfx *) (-1)))
    {
      break;
    }
  }

  if (i == D_80103258_CoinBlockBash)
  {
    return -1;
  }
  ;
  (&D_80103298_CoinBlockBash[i])->dl = 0;
  (&D_80103298_CoinBlockBash[i])->sprite = sprite;
  (&D_80103298_CoinBlockBash[i])->flags = flags;
  return i;
}

/* A billboard that draws model's display list (its per-frame segment 1) instead of a sprite. */
s16 func_80100160_CoinBlockBash(s16 model, u8 flags) {
    CBBBill* fx;
    s16 i;

    for (i = 0; i < D_80103258_CoinBlockBash; i++) {
        if (D_80103298_CoinBlockBash[i].dl == (Gfx*)-1) {
            break;
        }
    }
    if (i == D_80103258_CoinBlockBash) {
        return -1;
    }
    D_80103298_CoinBlockBash[i].sprite = 0xFFFF;
    D_80103298_CoinBlockBash[i].flags = flags;
    D_80103298_CoinBlockBash[i].unk_08 = 1;
    fx = &D_80103298_CoinBlockBash[i];
    fx->model = D_800F2B7C[model].unk_6C;
    fx->dl = D_800F2B7C[model].unk_6C->unk_00[0];
    return i;
}

void func_80100264_CoinBlockBash(s16 id, s16 sprite) {
    CBBBill* fx;

    if (id != -1) {
        fx = &D_80103298_CoinBlockBash[id];
        fx->dl = NULL;
        fx->sprite = sprite;
        fx->a = fx->r = fx->g = fx->b = 0xFF;
        fx->timer = 0;
        fx->frame = 0;
        fx->unk_0E = 0;
        fx->speed = 1.0f;
    }
}

void func_801002CC_CoinBlockBash(s16 id, f32 speed) {
    CBBBill* fx;

    if (id != -1) {
        fx = &D_80103298_CoinBlockBash[id];
        fx->speed = speed;
    }
}

void func_80100304_CoinBlockBash(s16 id, f32 x, f32 y, f32 z) {
    CBBBill* fx;

    if (id != -1) {
        fx = &D_80103298_CoinBlockBash[id];
        fx->pos.x = x;
        fx->pos.y = y;
        fx->pos.z = z;
    }
}

void func_8010034C_CoinBlockBash(s16 id, f32 x, f32 y, f32 z) {
    CBBBill* fx;

    if (id != -1) {
        fx = &D_80103298_CoinBlockBash[id];
        fx->scale.x = x;
        fx->scale.y = y;
        fx->scale.z = z;
    }
}

void func_80100394_CoinBlockBash(s16 id, u8 flags) {
    CBBBill* fx;

    if (id != -1) {
        fx = &D_80103298_CoinBlockBash[id];
        fx->flags |= flags;
    }
}

void func_801003D0_CoinBlockBash(s16 id, u8 flags) {
    CBBBill* fx;

    if (id != -1) {
        fx = &D_80103298_CoinBlockBash[id];
        fx->flags &= ~flags;
    }
}

void func_80100410_CoinBlockBash(s16 id, u8 r, u8 g, u8 b, s32 a) {
    CBBBill* fx;

    if (id != -1) {
        fx = &D_80103298_CoinBlockBash[id];
        fx->r = r;
        fx->g = g;
        fx->b = b;
        fx->a = a;
    }
}

void func_80100454_CoinBlockBash(s16 id) {
    CBBBill* fx;

    if (id != -1) {
        fx = &D_80103298_CoinBlockBash[id];
        fx->dl = (Gfx*)-1;
        fx->model = NULL;
        fx->unk_08 = 0;
        fx->flags = 0;
        fx->sprite = 0;
        fx->a = fx->r = fx->g = fx->b = 0xFF;
        fx->timer = 0;
        fx->frame = 0;
        fx->unk_0E = 0;
        fx->pos.x = fx->pos.y = fx->pos.z = 0.0f;
        fx->scale.x = fx->scale.y = fx->scale.z = 0.0f;
        fx->speed = 1.0f;
    }
}

#define CBB_TEX_MASK(x) \
    ((x) < 3 ? 1 : (x) < 5 ? 2 : (x) < 9 ? 3 : (x) < 17 ? 4 : (x) < 33 ? 5 : (x) < 65 ? 6 : (x) < 129 ? 7 : (x) < 257 ? 8 : 9)

/* Builds this frame's display list and quad of every visible sprite billboard, then advances its
   animation. */
void func_801004E8_CoinBlockBash(void) {
    Vtx* v;
    Gfx* gfx;
    CBBBill* fx;
    unk65770Anim* anim;
    unk65770AnimC* frame;
    u16 w;
    u16 h;
    s16 x;
    s16 y;
    s16 nh;
    unk65770Anim8* keys;
    s16 k;
    u16 i;

    v = D_80103284_CoinBlockBash[D_80101C00_CoinBlockBash];
    gfx = D_80103278_CoinBlockBash[D_80101C00_CoinBlockBash];
    for (i = 0; (s16)i < D_80103258_CoinBlockBash; i++) {
        fx = &D_80103298_CoinBlockBash[(s16)i];
        if (fx->dl == (Gfx*)-1 || fx->unk_08 != 0) {
            continue;
        }
        if (fx->flags & 0x10) {
            fx->dl = NULL;
            continue;
        }
        fx->dl = gfx;
        gDPPipeSync(gfx++);
        anim = D_800EC700[fx->sprite];
        if (anim->unk18 & 0x8000) {
            gDPSetCombine(gfx++, 0xFF97FF, 0xFF2DFEFF);
            gDPSetRenderMode(gfx++, 0x5049D8, 0);
            gDPSetBlendColor(gfx++, 0, 0, 0, 0);
            gDPSetPrimColor(gfx++, 0, 0, fx->r, fx->g, fx->b, fx->a);
        } else if (fx->a == 0xFF) {
            gDPSetRenderMode(gfx++, 0x553078, 0);
            gDPSetCombine(gfx++, 0xFFFFFF, 0xFFFCF279);
        } else {
            gDPSetBlendColor(gfx++, 0, 0, 0, 0);
            gDPSetPrimColor(gfx++, 0, 0, fx->r, fx->g, fx->b, fx->a);
            gDPSetRenderMode(gfx++, 0x5049D8, 0);
            gDPSetCombine(gfx++, 0x143228, 0xFF65FEFF);
        }
        gDPSetTextureFilter(gfx++, D_80101CA8_CoinBlockBash[(fx->flags & 0x18) >> 3]);
        frame = &anim->unk0[fx->frame];
        w = frame->unk4;
        h = frame->unk6;
        if (anim->unk18 & 0x8000) {
            gDPSetTextureLUT(gfx++, G_TT_NONE);
            gDPLoadTextureBlock_4b(gfx++, frame->unk0, G_IM_FMT_I, (s16)w, (s16)h, 0, G_TX_CLAMP, G_TX_CLAMP,
                                   CBB_TEX_MASK((s16)w), CBB_TEX_MASK((s16)h), G_TX_NOLOD, G_TX_NOLOD);
        } else {
            gDPSetTextureLUT(gfx++, G_TT_RGBA16);
            if (anim->unk18 < 0x11) {
                gDPLoadTLUT_pal16(gfx++, 0, anim->unkC);
                gDPLoadTextureBlock_4b(gfx++, frame->unk0, G_IM_FMT_CI, (s16)w, (s16)h, 0, G_TX_CLAMP, G_TX_CLAMP,
                                       CBB_TEX_MASK((s16)w), CBB_TEX_MASK((s16)h), G_TX_NOLOD, G_TX_NOLOD);
            } else {
                gDPLoadTLUT_pal256(gfx++, anim->unkC);
                gDPLoadTextureBlock(gfx++, frame->unk0, G_IM_FMT_CI, G_IM_SIZ_8b, (s16)w, (s16)h, 0, G_TX_CLAMP,
                                    G_TX_CLAMP, CBB_TEX_MASK((s16)w), CBB_TEX_MASK((s16)h), G_TX_NOLOD, G_TX_NOLOD);
            }
        }
        gSPVertex(gfx++, osVirtualToPhysical(v), 4, 0);
        gSP1Quadrangle(gfx++, 0, 1, 2, 3, 0);
        nh = -h;
        x = -frame->unk8;
        y = frame->unkA;
        v->v.ob[0] = x;
        v->v.ob[1] = y;
        v->v.ob[2] = 0;
        v->n.n[0] = v->n.n[1] = v->n.n[2] = -1;
        v->v.tc[0] = 0;
        v->v.tc[1] = 0;
        v->n.a = 0xFF;
        v++;
        v->v.ob[0] = x;
        v->v.ob[1] = nh + y;
        v->v.ob[2] = 0;
        v->n.n[0] = v->n.n[1] = v->n.n[2] = -1;
        v->v.tc[0] = 0;
        v->v.tc[1] = (-nh - 1) << 5;
        v->n.a = 0xFF;
        v++;
        v->v.ob[0] = (s16)w + x;
        v->v.ob[1] = nh + y;
        v->v.ob[2] = 0;
        v->n.n[0] = v->n.n[1] = v->n.n[2] = -1;
        v->v.tc[0] = ((s16)w - 1) << 5;
        v->v.tc[1] = (-nh - 1) << 5;
        v->n.a = 0xFF;
        v++;
        v->v.ob[0] = (s16)w + x;
        v->v.ob[1] = y;
        v->v.ob[2] = 0;
        v->n.n[0] = v->n.n[1] = v->n.n[2] = -1;
        v->v.tc[0] = ((s16)w - 1) << 5;
        v->v.tc[1] = 0;
        v->n.a = 0xFF;
        v++;
        gDPSetTextureFilter(gfx++, D_80101CA8_CoinBlockBash[(u8)D_800F329C]);
        gSPEndDisplayList(gfx++);
        if (fx->flags & 1) {
            continue;
        }
        keys = anim->unk4[0];
        for (k = 0; k < 2; k++) {
            fx->timer += fx->speed;
            if (keys->unk4[fx->frame].unk2 < fx->timer) {
                fx->frame++;
                fx->timer = 0.0f;
                if (fx->frame + 1 >= keys->unk0) {
                    if (fx->flags & 4) {
                        func_80100394_CoinBlockBash(i, 0x10);
                        break;
                    }
                    if (fx->flags & 0x20) {
                        func_80100454_CoinBlockBash(i);
                        break;
                    }
                    if ((fx->flags & 2) || keys->unk4[fx->frame].unk2 != -1) {
                        fx->frame--;
                        break;
                    }
                    fx->frame = 0;
                }
            }
        }
    }
}

/* Draws the billboards: each one's matrix (facing the camera unless it is a model) and display
   list, into the billboard model's list for this frame. */
void func_80101748_CoinBlockBash(void) {
    Mtx view;
    Matrix4f m;
    Matrix4f m2;
    Matrix4f bb;
    Gfx* gfx;
    Mtx* mtx;
    CBBBill* fx;
    s32 i;
    u8* cams;

    func_801004E8_CoinBlockBash();
    D_800F2B7C[D_80103274_CoinBlockBash].unk_6C->unk_00[0] = D_8010325C_CoinBlockBash[D_80101C00_CoinBlockBash];
    gfx = D_8010325C_CoinBlockBash[D_80101C00_CoinBlockBash];
    mtx = D_80103268_CoinBlockBash[D_80101C00_CoinBlockBash];
    cams = (u8*)D_800C3110;
    view = ((unk_Struct00*)(cams + (D_800F3FA8 << 7)))->unk_138;
    gSPClearGeometryMode(gfx++, G_CULL_BACK | G_LIGHTING);
    gSPSetGeometryMode(gfx++, G_ZBUFFER);
    for (i = 0; i < D_80103258_CoinBlockBash; i++) {
        fx = &D_80103298_CoinBlockBash[i];
        if (fx->dl != (Gfx*)-1 && !(fx->flags & 0x10)) {
            guMtxL2F(m, &view);
            MtxTranslate(m, fx->pos.x, fx->pos.y, fx->pos.z);
            MtxScale(m, fx->scale.x, fx->scale.y, fx->scale.z);
            if (fx->unk_08 == 0) {
                bb[0][0] = fx->scale.x;
                bb[1][1] = fx->scale.y;
                bb[2][2] = fx->scale.z;
                bb[3][3] = 1.0f;
                bb[0][1] = bb[0][2] = bb[0][3] = bb[1][0] = bb[1][2] = bb[1][3] = bb[2][0] = bb[2][1] = bb[2][3] =
                    bb[3][0] = bb[3][1] = bb[3][2] = 0.0f;
                MtxReset(m, m2);
                MtxMult(bb, m2, m);
            } else {
                gSPSegment(gfx++, 1, osVirtualToPhysical(fx->model->unk_08[D_800F37F0]));
            }
            func_800A0A20(m, mtx);
            gSPMatrix(gfx++, osVirtualToPhysical(mtx++), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(gfx++, fx->dl);
        }
    }
    gSPMatrix(gfx++, osVirtualToPhysical(&view), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPEndDisplayList(gfx++);
}

void func_80101A5C_CoinBlockBash(void) {
    s32 i;

    HuMemDirectFree(D_80103298_CoinBlockBash);
    for (i = 0; i < 3; i++) {
        HuMemDirectFree(D_80103278_CoinBlockBash[i]);
        HuMemDirectFree(D_80103284_CoinBlockBash[i]);
        HuMemDirectFree(D_8010325C_CoinBlockBash[i]);
        HuMemDirectFree(D_80103268_CoinBlockBash[i]);
    }
}
