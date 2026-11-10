#include "PlatformPeril.h"

f32 D_800FDD40_PlatformPeril[4] = { 180.0f, 180.0f, 180.0f, 180.0f }; /* CPU stick angle per player */
s32 D_800FDD50_PlatformPeril[4] = { 0, 0, 0, 0 };                      /* CPU buttons per player */
s32 D_800FDD60_PlatformPeril[4] = { 1, 2, 4, 8 };                      /* player bits */
s32 D_800FDD70_PlatformPeril = 0;

/* Intro camera path: zoom, centre, rotation, frames, event. */
PPCamKey D_800FDD74_PlatformPeril[] = {
    { 1500.0f, { 100.0f, 121.0f, 200.0f }, { 320.7f, 405.0f, 0.0f }, 21.75f, 0 },
    { 875.0f, { -100.0f, 146.0f, 200.0f }, { 326.7f, 327.0f, 0.0f }, 17.25f, 0 },
    { 250.0f, { -300.0f, 171.0f, 200.0f }, { 332.7f, 250.0f, 0.0f }, 18.0f, 2 },
    { 200.0f, { -300.0f, 171.0f, 200.0f }, { 332.7f, 225.0f, 0.0f }, 23.25f, 0 },
    { 200.0f, { 100.0f, 171.0f, 230.0f }, { 332.7f, 180.0f, 0.0f }, 19.5f, 0 },
    { 300.0f, { 360.0f, 171.0f, 265.0f }, { 322.7f, 100.0f, 0.0f }, 18.0f, 0 },
    { 800.0f, { 250.0f, 181.0f, 385.0f }, { 312.7f, 45.0f, 0.0f }, 15.0f, 1 },
    { 2300.0f, { 0.0f, 101.0f, 400.0f }, { 312.7f, 45.0f, 0.0f }, 1.5f, 0 },
    { -1.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f, 0 },
};
PPCamKey* D_800FDEB8_PlatformPeril = D_800FDD74_PlatformPeril;
s32 D_800FDEBC_PlatformPeril = 0;
f32 D_800FDEC0_PlatformPeril = 0.0f;
PPCamKey* D_800FDEC4_PlatformPeril = D_800FDD74_PlatformPeril;
s32 D_800FDEC8_PlatformPeril = 0;
s32 D_800FDECC_PlatformPeril = 0;
s32 D_800FDED0_PlatformPeril = 0;

/* Winner camera path: [0] is filled from the current camera, [1] from the winner. */
PPCamKey D_800FDED4_PlatformPeril[] = {
    { 2300.0f, { 0.0f, 101.0f, 400.0f }, { 312.7f, 45.0f, 0.0f }, 30.0f, 2 },
    { -1.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f, 0 },
    { -1.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f, 0 },
};
f32 D_800FDF40_PlatformPeril = 0.0f;
PPCamKey* D_800FDF44_PlatformPeril = D_800FDED4_PlatformPeril;
s32 D_800FDF48_PlatformPeril = 0;

void func_800FAD30_PlatformPeril(void) {
    omAddObj(3, 0, 0, -1, &func_800FAD64_PlatformPeril);
}

void func_800FAD64_PlatformPeril(omObjData* arg0) {
    s32 temp_s0;

    arg0->func_ptr = NULL;
    temp_s0 = InitSprite(0x2A0009);
    temp_s0 = func_80019060(temp_s0, 0, 0);
    func_80018D44(temp_s0, 0x4000);
    SetBasicSpritePos(temp_s0, 0xA0, 0x78);
    ShowBasicSprite(temp_s0);
}

s32 func_800FADC8_PlatformPeril(omObjData* obj) {
    s32 t = (s32)(obj->trans.x * 200.0 * 2) % 100;
    s32 r;

    if (t < 12) {
        r = 1;
    } else if (t >= 89) {
        r = -1;
    } else if (t < 25) {
        r = 4;
    } else if (t >= 76) {
        r = -4;
    } else if (t < 32) {
        r = 7;
    } else if (t >= 69) {
        r = -7;
    } else {
        r = 0;
    }
    return r;
}

s32 func_800FAE7C_PlatformPeril(s32 col) {
    return (col < 6) ? -1 : 1;
}

f32 func_800FAE8C_PlatformPeril(f32 x) {
    s32 col = (x + 600.0f) / 100.0f;

    if (col < 0) {
        col = 0;
    } else if (col >= 12) {
        col = 11;
    }
    return 0.0f;
}

f32 func_800FAEC0_PlatformPeril(f32 x) {
    f32 tbl[12] = { 0.0f, 0.0f, 0.0f, 0.0f, 90.0f, 90.0f, -90.0f, -90.0f, 0.0f, 0.0f, 0.0f, 0.0f };
    s32 col = (x + 600.0f) / 100.0f;

    if (col < 0) {
        col = 0;
    } else if (col >= 12) {
        col = 11;
    }
    return tbl[col];
}

s32 func_800FAF58_PlatformPeril(f32 a, f32 b) {
    s32 ret = 0;

    if (a + 20.0 >= b && b >= a - 20.0) {
        ret = 1;
    }
    return ret;
}

s32 func_800FAFA0_PlatformPeril(s32 pl) {
    s32 ret = 1;
    s32 i;

    for (i = 1; i < 3; i++) {
        if (func_800FAF58_PlatformPeril(D_800FE550_PlatformPeril[pl][0], D_800FE550_PlatformPeril[pl][i]) == 0) {
            ret = 0;
            break;
        }
    }
    return ret;
}

// return-tail cross-jumping and register allocation (masked 58, logic-equivalent)
#ifdef NON_MATCHING
f32 func_800FB028_PlatformPeril(omObjData* obj, s32* jump) {
    s32 col;
    s32 row;
    s32 layer;
    s32 flags = 0;
    s32 dir;
    s32 a;

    *jump = 1;
    func_800FBC38_PlatformPeril(obj->trans.x, obj->trans.y, obj->trans.z, &col, &row, &layer);
    if (col == 0) {
        flags = 4;
    } else if (D_800FE5B0_PlatformPeril[layer + 3][col - 1] == 2) {
        flags += 4;
    }
    if (D_800FE5B0_PlatformPeril[layer + 3][col] == 2) {
        flags += 2;
    }
    if (col == 11) {
        flags += 1;
    } else {
        flags += D_800FE5B0_PlatformPeril[layer + 3][col + 1] == 2;
    }
    if (!(flags & 2)) {
        a = func_800FADC8_PlatformPeril(obj);
        if (a == 0) {
            return 180.0f;
        }
        return (f32)a + 180.0;
    }
    if (flags == 2) {
        dir = func_800FAE7C_PlatformPeril(col);
    } else if (flags == 6) {
        dir = -1;
    } else if (flags == 3) {
        dir = 1;
    } else {
        dir = func_800FAE7C_PlatformPeril(col);
    }
    a = func_800FADC8_PlatformPeril(obj);
    if (a == 0) {
        if (D_800FE5B0_PlatformPeril[layer][col - dir] != 2) {
            return (f32)dir * 45.0f + 180.0 + a;
        }
        return (f32)dir * 25.0 + 180.0;
    }
    if (((a < 0) & (dir < 0)) || ((a > 0) & (dir > 0))) {
        return (f32)a + 180.0 + (f32)dir * 25.0;
    }
    if ((a < 0 && !(flags & 1)) || (a > 0 && !(flags & 4))) {
        return (f32)a + 180.0 + -((f32)dir * 25.0);
    }
    if (D_800FE5B0_PlatformPeril[layer][col - dir] != 2) {
        return (f32)dir * 45.0f + 180.0 + a;
    }
    return (f32)dir * 25.0 + 180.0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_18_PlatformPeril/170470", func_800FB028_PlatformPeril);
#endif

f32 func_800FB3B0_PlatformPeril(omObjData* obj) {
    return 180.0 - func_800FADC8_PlatformPeril(obj);
}

/* Ranks the players by layer (D_800FE590[0] = furthest down). */
void func_800FB3E8_PlatformPeril(void) {
    s32 ids[4] = { 0, 1, 2, 3 };
    s32 rows[4];
    s32 i;
    s32 j;

    for (i = 0; i < 4; i++) {
        rows[i] = D_800FE5A0_PlatformPeril[i];
    }
    for (i = 0; i < 3; i++) {
        for (j = 2; j >= i; j--) {
            if (rows[j] < rows[j + 1]) {
                func_800FB60C_PlatformPeril(&rows[j], &rows[j + 1]);
                func_800FB60C_PlatformPeril(&ids[j], &ids[j + 1]);
            }
        }
    }
    for (i = 0; i < 4; i++) {
        D_800FE590_PlatformPeril[i] = ids[i];
    }
}

// decomp-permuter
s32 func_800FB544_PlatformPeril(s32 pl)
{
  int new_var;
  s32 idle = 0;
  s32 alive = D_800FE2C4_PlatformPeril;
  s32 i;
  s32 j;
  for (i = 0; i < 4; i++)
  {
    idle += D_800FE2D8_PlatformPeril[i] == 0;
  }

  for (i = 0; i < 4; i++)
  {
    if (pl == D_800FE590_PlatformPeril[i])
    {
      break;
    }
  }

  for (j = 0; j < 4; j++)
  {
    i += (alive & D_800FDD60_PlatformPeril[j]) == 0;
  }

  i += idle;
  if (i >= 4)
  {
    i = 3;
  }
  else
  {
    new_var = 0;
    i &= -(i > new_var);
  }
  return i;
}

void func_800FB60C_PlatformPeril(s32* a, s32* b) {
    s32 t = *a;

    *a = *b;
    *b = t;
}

s32 func_800FB620_PlatformPeril(omObjData* obj) {
    s32 col;
    s32 row;
    s32 layer;

    func_800FBC38_PlatformPeril(obj->trans.x, obj->trans.y, obj->trans.z, &col, &row, &layer);
    return D_800FE5B0_PlatformPeril[layer][col];
}

/* CPU player input. */
void func_800FB680_PlatformPeril(omObjData* obj) {
    s32 jump = 0;
    s32 col = 0;
    s32 layer = 0;
    s32 row = 0;
    s32 speeds[4] = { 90, 93, 95, 100 };
    s32 port = ((unkGlobalStruct_00*)obj->unk_50)->unk_56;
    s32 pl = obj->work[0];
    s32 tile;
    s32 speed;
    s32 i;

    if (obj->work[2] != 0) {
        return;
    }
    func_800FBC38_PlatformPeril(obj->trans.x, obj->trans.y, obj->trans.z, &col, &row, &layer);
    D_800FE5A0_PlatformPeril[pl] = layer;
    tile = func_800FB620_PlatformPeril(obj);
    if (obj->trans.y == 50.0f) {
        D_800FE2E8_PlatformPeril[pl] = 0;
    }
    if (D_800FE2E8_PlatformPeril[pl] <= 0) {
        if (tile == 1) {
            jump = 0;
            D_800FDD50_PlatformPeril[pl] = 0;
            D_800FDD40_PlatformPeril[pl] = func_800FB3B0_PlatformPeril(obj);
        } else if (tile == 3) {
            D_800FDD50_PlatformPeril[pl] = 0;
            jump = 0;
            obj->work[3] = 1;
            D_800FDD40_PlatformPeril[pl] = func_800FB028_PlatformPeril(obj, &jump);
        } else if (tile != 0) {
            if (tile == 2) {
                if ((col != 0 && D_800FE5B0_PlatformPeril[layer][0] == 3) || (col != 11 && D_800FE5B0_PlatformPeril[layer][11] == 3)) {
                    jump = 0;
                    D_800FDD50_PlatformPeril[pl] = 0;
                    obj->work[3] = 1;
                    D_800FDD40_PlatformPeril[pl] = func_800FB028_PlatformPeril(obj, &jump);
                } else {
                    jump = 0;
                    D_800FDD50_PlatformPeril[pl] = 0;
                    D_800FDD40_PlatformPeril[pl] = func_800FB3B0_PlatformPeril(obj);
                }
            } else {
                D_800FDD50_PlatformPeril[pl] = 0;
                D_800FDD40_PlatformPeril[pl] = 0;
            }
        }
        for (i = 2; i >= 0; i--) {
            D_800FE550_PlatformPeril[pl][i + 1] = D_800FE550_PlatformPeril[pl][i];
        }
        D_800FE550_PlatformPeril[pl][0] = D_800FDD40_PlatformPeril[pl];
        if (func_800FAFA0_PlatformPeril(pl) == 0) {
            D_800FDD50_PlatformPeril[pl] = 0;
            jump = 0;
        }
        if (jump == 1) {
            D_800FE2E8_PlatformPeril[pl] = 10;
            D_800FDD50_PlatformPeril[pl] = 0x8000;
        } else {
            D_800FDD50_PlatformPeril[pl] = 0;
        }
    }
    speed = speeds[func_800FB544_PlatformPeril(pl)];
    switch (D_800FE2A0_PlatformPeril[pl]) {
    case 0:
        speed = speed * 95 / 100;
        break;
    case 1:
        break;
    case 2:
        speed = speed * 105 / 100;
        break;
    case 3:
        speed = speed * 110 / 100;
        break;
    }
    if ((col == 0 && D_800FDD40_PlatformPeril[pl] - 180.0 > 0.0) || (col == 11 && D_800FDD40_PlatformPeril[pl] - 180.0 < 0.0)) {
        if (D_800FDD50_PlatformPeril[pl] == 0x8000) {
            D_800FDD40_PlatformPeril[pl] = 180.0f;
            D_800FDD50_PlatformPeril[pl] = 0;
        }
    }
    if (D_800FDD40_PlatformPeril[pl] != 0.0f) {
        ContStkX[port] = func_800AEAC0(D_800FDD40_PlatformPeril[pl]) * 60.0f * speed / 100.0f;
        ContStkY[port] = -(func_800AEFD0(D_800FDD40_PlatformPeril[pl]) * 60.0f * speed / 100.0f);
    } else {
        ContStkX[port] = 0;
        ContStkY[port] = 0;
    }
    ContBtn[port] = D_800FDD50_PlatformPeril[pl];
    ContBtnTrg[port] = D_800FDD50_PlatformPeril[pl];
    D_800FE2E8_PlatformPeril[pl]--;
}

void func_800FBC38_PlatformPeril(f32 x, f32 y, f32 z, s32* col, s32* row, s32* layer) {
    *col = (x + 600.0f) / 100.0f;
    *row = y / 200.0f;
    *layer = (-z - 200.0f) / 100.0f + 2.0f;
    if (*col < 0) {
        *col = 0;
    } else if (*col >= 12) {
        *col = 11;
    }
}

void func_800FBCD4_PlatformPeril(omObjData* obj) {
    s32 pl = obj->work[0];
    s32 cpu = obj->work[1];
    unkGlobalStruct_00* g = obj->unk_50;
    s32 port = g->unk_56;
    f32 angle;

    if (D_800FE2F8_PlatformPeril == 4 || D_800FE2F8_PlatformPeril == 9 || D_800FE2F8_PlatformPeril == 10) {
        D_800FE2D8_PlatformPeril[pl] = cpu;
        if (cpu != 0) {
            func_800FB680_PlatformPeril(obj);
        }
        if (D_800FE2B0_PlatformPeril[pl] == 1) {
            if (D_800FE2C8_PlatformPeril == -1) {
                D_800FE2C8_PlatformPeril = pl;
                D_800FE280_PlatformPeril = 0;
            }
            if (D_800FE2B0_PlatformPeril[pl] == 1) {
                ContStkX[port] = 0;
                ContStkY[port] = 0;
                ContBtn[port] = 0;
                ContBtnTrg[port] = 0;
                obj->work[2] = 1;
                if (D_800FE2C4_PlatformPeril & D_800FDD60_PlatformPeril[pl]) {
                    D_800FE2C4_PlatformPeril &= ~D_800FDD60_PlatformPeril[pl];
                }
            }
        }
        func_80005A28(obj);
        if ((s8)g->unk_54[0] != -1) {
            func_800FC48C_PlatformPeril(obj->trans.x, obj->trans.y, obj->trans.z);
        }
    } else if (D_800FE2F8_PlatformPeril == 2) {
        func_800FC000_PlatformPeril(obj);
        func_80005A28(obj);
    } else if (D_800FE2F8_PlatformPeril == 5) {
        ContBtn[port] = 0;
        ContBtnTrg[port] = 0;
        if (pl == D_800FE2C8_PlatformPeril) {
            angle = func_800FAE8C_PlatformPeril(obj->trans.x) + 180.0;
            if (angle == 180.0) {
                D_800FDD70_PlatformPeril = 1;
            }
            ContStkX[port] = func_800AEAC0(angle) * 45.0f;
            ContStkY[port] = -(func_800AEFD0(angle) * 45.0f);
        }
        func_80005A28(obj);
    } else if (D_800FE2F8_PlatformPeril >= 6) {
        ContStkX[port] = 0;
        ContStkY[port] = 0;
        ContBtn[port] = 0;
        ContBtnTrg[port] = 0;
        if (pl == D_800FE2C8_PlatformPeril) {
            g->unk_3C = 135.0f;
        }
        func_80005A28(obj);
    }
}

void func_800FBFB0_PlatformPeril(omObjData* obj) {
    s8 port = ((unkGlobalStruct_00*)obj->unk_50)->unk_56;

    ContStkX[port] = 0;
    ContStkY[port] = 0;
    ContBtnTrg[port] = 0;
    ContBtn[port] = 0;
    obj->rot.y = 180.0f;
}

/* Intro: every player walks forward, then jumps. */
void func_800FC000_PlatformPeril(omObjData* obj) {
    s32 port = ((unkGlobalStruct_00*)obj->unk_50)->unk_56;

    if (++D_800FE2FC_PlatformPeril > 160) {
        ContStkX[port] = 0;
        ContStkY[port] = 0;
    } else if (D_800FE2FC_PlatformPeril > 120) {
        ContStkX[port] = func_800AEAC0(180.0f) * 60.0f;
        ContStkY[port] = -(func_800AEFD0(180.0f) * 60.0f);
        ContBtn[port] = 0x8000;
        ContBtnTrg[port] = 0x8000;
        return;
    } else {
        ContStkX[port] = func_800AEAC0(180.0f) * 60.0f;
        ContStkY[port] = -(func_800AEFD0(180.0f) * 60.0f);
    }
    ContBtn[port] = 0;
    ContBtnTrg[port] = 0;
}

void func_800FC17C_PlatformPeril(void) {
    if (D_800FE2F8_PlatformPeril == 5) {
        D_800FE280_PlatformPeril++;
    }
    if (D_800FE2F8_PlatformPeril == 4) {
        func_800FB3E8_PlatformPeril();
    }
    func_800FC648_PlatformPeril();
}

void func_800FC1DC_PlatformPeril(void) {
    PPSpark* p = D_800FE300_PlatformPeril;
    s32 i;
    s16 id;

    D_800FE270_PlatformPeril = DataRead(0x390016);
    D_800FE274_PlatformPeril = func_800678A4(D_800FE270_PlatformPeril);
    DataClose(D_800FE270_PlatformPeril);
    D_800FE276_PlatformPeril = func_80064EF4(1, 0);
    func_80067208(D_800FE276_PlatformPeril, 0, D_800FE274_PlatformPeril, 0);
    func_80066DC4(D_800FE276_PlatformPeril, 0, 0xA0, 0x78);
    func_80067354(D_800FE276_PlatformPeril, 0, 1.0f, 1.0f);
    func_8006752C(D_800FE276_PlatformPeril, 0, 0x100);
    func_800674BC(D_800FE276_PlatformPeril, 0, 0x9000);
    func_800672B0(D_800FE276_PlatformPeril, 0, 0);
    func_800FAD30_PlatformPeril();
    for (i = 0; i < 4; i++) {
        D_800FE288_PlatformPeril[i] = i;
        D_800FE5A0_PlatformPeril[i] = 0;
        D_800FE2E8_PlatformPeril[i] = 0;
        D_800FE550_PlatformPeril[i][0] = 1.0f;
        D_800FE550_PlatformPeril[i][1] = 2.0f;
        D_800FE550_PlatformPeril[i][2] = 3.0f;
        D_800FE550_PlatformPeril[i][3] = 4.0f;
    }
    D_800FE2C4_PlatformPeril = D_800FDD60_PlatformPeril[0] | D_800FDD60_PlatformPeril[1] | D_800FDD60_PlatformPeril[2] | D_800FDD60_PlatformPeril[3];
    D_800FE2C8_PlatformPeril = -1;
    for (i = 0; i < 16; i++) {
        p->sprite = id = func_800FC438_PlatformPeril(0x12000F, 0x289, 8);
        if (id >= 0) {
            p->model = D_800ECDE0[id].unk_00;
            func_800258EC(p->model, 4, 4);
            func_8001E2A8(p->sprite, 0);
            p++;
        }
    }
}

s16 func_800FC438_PlatformPeril(s32 a, s32 b, s32 c) {
    s16 id = ReadImgPackand(a, b, c);

    func_80025930(D_800ECDE0[id].unk_00, 0x70000000, 0x70000000);
    return id;
}

// the constant 1 for p->active is hoisted out of the loop (one more saved register), retail
// loads it in the loop (masked 20); tried plain statements for the initialisers
#ifdef NON_MATCHING
/* Burst of 8 sparks at the winner's position. */
void func_800FC48C_PlatformPeril(f32 x, f32 y, f32 z) {
    PPSpark* p = D_800FE300_PlatformPeril;
    s32 base = ((rand8() << 8) | rand8()) % 181;
    u16 count;
    s32 full;
    u16 i;

    if (D_800FE2C8_PlatformPeril == -1) {
        count = 8;
        full = 360;
        for (i = 0; i < count; i++) {
            func_800258EC(p->model, 4, 0);
            p->angle = base + (full / count) * i;
            if (p->angle > 360) {
                p->angle -= 360;
            } else if (p->angle < 0) {
                p->angle += 360;
            }
            p->speed = 28;
            p->life = 10;
            p->active = 1;
            p->x = x;
            p->y = y;
            p->z = z;
            func_80025798(p->model, x, y, z);
            p++;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_18_PlatformPeril/170470", func_800FC48C_PlatformPeril);
#endif

void func_800FC648_PlatformPeril(void) {
    PPSpark* p = D_800FE300_PlatformPeril;
    u16 i;
    f32 t;

    if (D_800FE2C8_PlatformPeril == -1) {
        for (i = 0; i < 16; i++, p++) {
            if (p->active == 1) {
                t = p->life / 10.0f;
                p->x += func_800AEFD0(p->angle) * p->speed;
                p->y += (f32)(func_800AEAC0(t * 90.0f) * 1.5 * 20.0);
                p->z += func_800AEAC0(p->angle) * p->speed;
                func_80025798(p->model, p->x, p->y, p->z);
                func_80025830(p->model, 2.0f, 2.0f, 2.0f);
                if (t > 0.5) {
                    func_8001E2F8(p->sprite, 0xFF);
                } else {
                    func_8001E2F8(p->sprite, 128.0f - t * 128.0f);
                }
                if (p->life-- <= 0) {
                    func_800258EC(p->model, 4, 4);
                    p->angle = p->speed = p->life = p->active = p->unk_12 = p->unk_14 = 0;
                }
            }
        }
    } else {
        for (i = 0; i < 16; i++, p++) {
            func_800258EC(p->model, 4, 4);
            p->angle = p->speed = p->life = p->active = p->unk_12 = p->unk_14 = 0;
        }
    }
}

void func_800FC8D4_PlatformPeril(void) {
}

void func_800FC8DC_PlatformPeril(void) {
}

// zero-constant register reuse in the loop test (masked 6)
#ifdef NON_MATCHING
void func_800FC8E4_PlatformPeril(void) {
    s32 n;

    D_800FDEB8_PlatformPeril = D_800FDD74_PlatformPeril;
    D_800FDEBC_PlatformPeril = 0;
    for (n = 0; 0.0f < D_800FDD74_PlatformPeril[n].center.y; n++) {
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_18_PlatformPeril/170470", func_800FC8E4_PlatformPeril);
#endif

/* Intro camera; 1 when the path has ended. */
s32 func_800FC95C_PlatformPeril(void) {
    PPCamKey cam;
    PPCamKey* k;

    func_800FAAE0_PlatformPeril(D_800FDEC0_PlatformPeril, D_800FDEC4_PlatformPeril, &cam);
    CZoom = cam.zoom;
    CRot.x = cam.rot.x;
    CRot.y = cam.rot.y;
    CRot.z = cam.rot.z;
    Center.x = cam.center.x;
    Center.y = cam.center.y;
    Center.z = cam.center.z;
    D_800FDEC0_PlatformPeril += 1.0f / D_800FDEC4_PlatformPeril->time;
    switch (D_800FDEC4_PlatformPeril->event) {
    case 1:
        if (D_800FDECC_PlatformPeril == 0) {
            GMesCreate(0);
            D_800FDECC_PlatformPeril++;
        }
        break;
    case 2:
        if (D_800FDED0_PlatformPeril == 0) {
            func_80060128(0x23);
            D_800FDED0_PlatformPeril++;
        }
        break;
    }
    if (D_800FDEC0_PlatformPeril >= 1.0f) {
        D_800FDEC0_PlatformPeril = 0.0f;
        k = D_800FDEC4_PlatformPeril;
        D_800FDEC4_PlatformPeril = k + 1;
        D_800FDEC8_PlatformPeril++;
        if (k[2].zoom <= 0.0f) {
            D_800FDEC4_PlatformPeril = D_800FDD74_PlatformPeril;
            D_800FDEC8_PlatformPeril = 0;
            return 1;
        }
    }
    return 0;
}

void func_800FCB10_PlatformPeril(omObjData* obj) {
    D_800FDED4_PlatformPeril[0].center.x = Center.x;
    D_800FDED4_PlatformPeril[0].center.y = Center.y;
    D_800FDED4_PlatformPeril[0].center.z = Center.z;
    D_800FDED4_PlatformPeril[0].rot.x = CRot.x;
    D_800FDED4_PlatformPeril[0].rot.y = CRot.y;
    D_800FDED4_PlatformPeril[0].rot.z = CRot.z;
    D_800FDED4_PlatformPeril[0].zoom = CZoom;
    D_800FDED4_PlatformPeril[1].zoom = 500.0f;
    D_800FDED4_PlatformPeril[1].center.x = obj->trans.x;
    D_800FDED4_PlatformPeril[1].center.y = obj->trans.y + 60.0f;
    D_800FDED4_PlatformPeril[1].center.z = obj->trans.z;
    D_800FDED4_PlatformPeril[1].rot.x = 360.0f;
    D_800FDED4_PlatformPeril[1].rot.y = 135.0f;
    D_800FDED4_PlatformPeril[1].rot.z = 0.0f;
    D_800FDED4_PlatformPeril[1].time = 3.0f;
}

/* Winner camera; 1 when the path has ended. */
s32 func_800FCBD4_PlatformPeril(void) {
    PPCamKey* k = D_800FDF44_PlatformPeril;
    f32 s = 1.0f - D_800FDF40_PlatformPeril;

    CZoom = s * k[0].zoom + k[1].zoom * D_800FDF40_PlatformPeril;
    CRot.x = s * k[0].rot.x + k[1].rot.x * D_800FDF40_PlatformPeril;
    CRot.y = s * k[0].rot.y + k[1].rot.y * D_800FDF40_PlatformPeril;
    CRot.z = s * k[0].rot.z + k[1].rot.z * D_800FDF40_PlatformPeril;
    Center.x = s * k[0].center.x + k[1].center.x * D_800FDF40_PlatformPeril;
    Center.y = s * k[0].center.y + k[1].center.y * D_800FDF40_PlatformPeril;
    Center.z = s * k[0].center.z + k[1].center.z * D_800FDF40_PlatformPeril;
    D_800FDF40_PlatformPeril += 1.0f / k[0].time;
    if (D_800FDF40_PlatformPeril >= 1.0f) {
        D_800FDF40_PlatformPeril = 0.0f;
        D_800FDF44_PlatformPeril = k + 1;
        D_800FDF48_PlatformPeril++;
        if (k[2].zoom <= 0.0f) {
            D_800FDF44_PlatformPeril = D_800FDED4_PlatformPeril;
            D_800FDF48_PlatformPeril = 0;
            return 1;
        }
    }
    return 0;
}

void func_800FCD44_PlatformPeril(void) {
}
