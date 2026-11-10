#include "UnusedMinigame1.h"

f32 D_800F9230_UnusedMinigame1[6] = { 1.0f, 1.0f, 1.0f, 0.9f, 0.8f, 0.7f };

char* D_800F9248_UnusedMinigame1[5] = {
    "c012t001_DEF", "c012t002_DEF", "c012t003_DEF", "c012t005_DEF", "c012t004_DEF",
};

u8 D_800F925C_UnusedMinigame1[8] = { 2, 1, 0, 4, 3, 0, 0, 0 };

Vec D_800F9264_UnusedMinigame1[4] = {
    { -406.5f, 298.7f, -45.0f },
    { -406.5f, 298.7f, 155.0f },
    { -406.5f, 298.7f, 355.0f },
    { -406.5f, 298.7f, 555.0f },
};

/* A machine at the bottom (one per player). */
void func_800F7E10_UnusedMinigame1(omObjData* obj) {
    s8 chr;
    s32 dir;
    s32 file;
    s32 i;
    UM1Machine* w;
    Vec* pos;
    u8 row;
    u16 m;
    void* data;
    s16 tex;

    chr = GwPlayer[D_800F946A_UnusedMinigame1].character;
    dir = D_800C59AC[chr].unk_00;
    file = D_800C59AC[chr].unk_04;
    for (i = 0; i < obj->mdlcnt; i++) {
        obj->model[i] = 0;
    }
    for (i = 0; i < obj->mtncnt; i++) {
        obj->motion[i] = -1;
    }
    obj->unk_50 = func_80023684(sizeof(UM1Machine), 0x7918);
    func_8009B770(obj->unk_50, 0, sizeof(UM1Machine));
    w = obj->unk_50;
    pos = &D_800F9264_UnusedMinigame1[D_800F946A_UnusedMinigame1];
    row = 4;
    if (chr != 3) {
        row = D_800F9492_UnusedMinigame1[D_800F9454_UnusedMinigame1];
    }
    if (D_800F9450_UnusedMinigame1 < 0) {
        m = func_800174F4(0x1A0005, 0x289);
        obj->model[6] = m;
        D_800F9458_UnusedMinigame1[6] = m;
        D_800F9450_UnusedMinigame1 = m;
        func_800258EC(m, 4, 4);
    }
    m = LoadFormFile(0x1A0004, 0x289);
    obj->model[0] = m;
    omSetTra(obj, pos->x, pos->y, pos->z);
    func_80025EB4(m, 8, 8);
    if (D_800F9450_UnusedMinigame1 >= 0) {
        func_80027AC8(m, (u8*)"c003_sita_DEF", (u8*)D_800F9248_UnusedMinigame1[row]);
        func_80025AD4(m);
        func_80025B34(m);
    }
    if (chr != 3) {
        m = LoadFormFile(dir | file, 0x299);
        obj->model[2] = m;
        func_8001775C(obj, 1, dir | 0x6B);
        func_80025BB8(m, obj->motion[1]);
        func_80025EB4(m, 8, 8);
        func_80025830(m, 1.0f, D_800F9230_UnusedMinigame1[chr], 1.0f);
        func_80025798(m, pos->x, pos->y + 20.0f, pos->z);
    }
    if (D_800F9458_UnusedMinigame1[1] < 0) {
        m = func_800174F4(6, 0x289);
        D_800F9458_UnusedMinigame1[1] = m;
    } else {
        m = func_80023FC8(D_800F9458_UnusedMinigame1[1]);
    }
    obj->model[1] = m;
    func_800370D4(m);
    func_80025798(m, pos->x + 10.0f, pos->y, pos->z);
    if (chr != 3) {
        func_80025830(m, 1.0f, 1.0f, 1.0f);
    } else {
        func_80025830(m, 0.8f, 1.0f, 0.8f);
    }
    if (D_800F9458_UnusedMinigame1[3] < 0) {
        m = func_800174F4(0x1A0003, 0x289);
        D_800F9458_UnusedMinigame1[3] = m;
    } else {
        m = func_80023FC8(D_800F9458_UnusedMinigame1[3]);
    }
    obj->model[3] = m;
    func_80025798(m, pos->x + 60.0f, pos->y + 40.0f, pos->z);
    m = LoadFormFile(0x1A000A, 0x289);
    obj->model[5] = m;
    func_80025798(m, pos->x + 130.0f, pos->y + 80.0f, pos->z);
    func_80025930(m, 0x70000000, 0x70000000);
    if (D_800F94A8_UnusedMinigame1 < 0) {
        data = DataRead(0x1A000C);
        tex = func_80038A9C(D_800F2B7C[(s16)m].unk_6C, data, 0, "baby2_DEF");
        D_800F94A8_UnusedMinigame1 = tex;
        HuMemDirectFree(data);
    } else {
        tex = func_80038D5C(D_800F2B7C[(s16)m].unk_6C, D_800F94A8_UnusedMinigame1, 0, "baby2_DEF");
    }
    func_8003967C(tex, D_800F925C_UnusedMinigame1[row]);
    w->unk1A = tex;
    if (D_800F9470_UnusedMinigame1 < 0) {
        data = DataRead(0x1A000F);
        tex = func_80038A9C(D_800F2B7C[(s16)m].unk_6C, data, 0, "namida_IA44");
        D_800F9470_UnusedMinigame1 = tex;
        HuMemDirectFree(data);
    } else {
        tex = func_80038D5C(D_800F2B7C[(s16)m].unk_6C, D_800F9470_UnusedMinigame1, 0, "namida_IA44");
    }
    w->unk1C = tex;
    func_80025AD4(m);
    func_8001775C(obj, 2, 0x1A000B);
    w->unk21 = row;
    w->unk22 = chr;
    w->unk20 = (u8)D_800F946A_UnusedMinigame1;
    w->unk18 = 0;
    w->x = pos->x;
    w->y = pos->y;
    w->z = pos->z;
    w->unk23 = GwPlayer[w->unk20].port;
    w->unk14 = 0;
    D_800F9454_UnusedMinigame1++;
    D_800F946A_UnusedMinigame1++;
    obj->func_ptr = func_800F8A4C_UnusedMinigame1;
}

void func_800F84CC_UnusedMinigame1(void) {
    s32 i;

    D_800F9468_UnusedMinigame1 = -1;
    D_800F94A8_UnusedMinigame1 = -1;
    D_800F9450_UnusedMinigame1 = -1;
    D_800F9454_UnusedMinigame1 = 0;
    for (i = 0; i < 8; i++) {
        D_800F9458_UnusedMinigame1[i] = -1;
    }
    D_800F946C_UnusedMinigame1 = 0;
    D_800F946A_UnusedMinigame1 = 0;
    for (i = 0; i < 4; i++) {
        D_800F9498_UnusedMinigame1[i] = omAddObj(8, 8, 4, -1, func_800F7E10_UnusedMinigame1);
    }
}

/* The result: the machines that stopped closest to the mark (within 40) win 10 coins each. */
// decomp-permuter
void func_800F85A0_UnusedMinigame1(void)
{
  s32 dist[4];
  s32 idx[4];
  s32 chr[4];
  UM1Machine *w;
  s32 *dp;
  s32 best;
  s32 n;
  s32 i;
  s32 d;
  best = 10000;
  n = 0;
  for (i = 0; i < 4; i++)
  {
    w = D_800F9498_UnusedMinigame1[i]->unk_50;
    dp = &dist[i];
    d = (*(&dist[i]) = 344.0f - w->unk10);
    if (((u32) d) < 40)
    {
      if (d < best)
      {
        best = d;
        idx[0] = i;
        chr[0] = w->unk22;
        n = 1;
      }
      else
        if (dist[i] == best)
      {
        idx[n] = i;
        chr[n] = w->unk22;
        n++;
      }
    }
  }

  if (n != ((int) 0))
  {
    for (i = 0; i < n; i++)
    {
      GwPlayer[idx[i]].coins_mg += 10;
    }

    switch (n)
    {
      case 1:
        GMesCreate(4, chr[0]);
        break;

      case 2:
        GMesCreate(0xF, chr[0], chr[1]);
        break;

      case 3:
        GMesCreate(0x13, chr[0], chr[1], chr[2]);
        break;

      case 4:
        GMesCreate(4, 6);
        break;

    }

    func_80060128(0x32);
  }
  else
  {
    GMesCreate(0x11);
    func_80060128(0x34);
  }
}

/* The result text above a machine and its baby's face. */
void func_800F8764_UnusedMinigame1(omObjData* obj) {
    UM1Machine* w = obj->unk_50;
    Vec pos;
    f32 scr[3];
    s32 x;
    s32 y;
    s32 d;
    s32 ok;
    u16 m;
    void* data;

    pos.x = w->unk10;
    pos.y = w->y + 80.0f;
    pos.z = w->z;
    func_800F8FC0_UnusedMinigame1(0, &pos, scr);
    x = (s32)scr[0] + 0xA0;
    y = (s32)scr[1] + 0x68;
    d = 344.0f - w->unk10;
    fontcolor = 15;
    ok = 0;
    if (d < 0) {
        sprintf(pfStrBuf, "TOO LATE!", d);
        if (x > 0x108) {
            x = 0x108;
        }
        print8(x - 0x20, y, pfStrBuf);
    } else if (d < 2) {
        sprintf(pfStrBuf, "JUST!");
        goto near;
    } else if (d < 40) {
        sprintf(pfStrBuf, "%d LEFT", d);
    near:
        print8(x - 0x18, y, pfStrBuf);
        ok++;
    } else {
        sprintf(pfStrBuf, "TOO FAR!", d);
        if (x < 0x30) {
            x = 0x30;
        }
        print8(x - 0x20, y, pfStrBuf);
    }
    if (w->unk18 & 4) {
        return;
    }
    if (ok) {
        func_8003967C(w->unk1A, D_800F925C_UnusedMinigame1[w->unk21] + 5);
    } else {
        m = obj->model[5];
        func_800399F0(w->unk1C);
        if (D_800F9490_UnusedMinigame1 < 0) {
            data = DataRead(0x1A000E);
            D_800F9490_UnusedMinigame1 = func_80038A9C(D_800F2B7C[(s16)m].unk_6C, data, 0, "namida_IA44");
            HuMemDirectFree(data);
        } else {
            func_80038D5C(D_800F2B7C[(s16)m].unk_6C, D_800F9490_UnusedMinigame1, 0, "namida_IA44");
        }
        func_80025BB8(m, obj->motion[2]);
        func_80025EB4(m, 2, 2);
        func_8003967C(w->unk1A, D_800F925C_UnusedMinigame1[w->unk21] + 10);
        func_80025AD4(m);
    }
    w->unk18 |= 4;
}

/* A machine: stretch while the button is held (or the CPU keeps going), stop on A. */
void func_800F8A4C_UnusedMinigame1(omObjData* obj) {
    UM1Machine* w = obj->unk_50;
    u32 stop;

    switch (D_800ED430) {
        case 1:
            if (++w->unk14 == 20) {
                if (!(D_800F946C_UnusedMinigame1 & 1)) {
                    D_800F946C_UnusedMinigame1 |= 1;
                    func_80060540(0, 0);
                }
                func_80060540(0, w->unk20);
                w->unk18 = 1;
            }
            if (!(w->unk18 & 2)) {
                func_80025EB4(obj->model[0], 8, 0);
                func_80025EB4(obj->model[2], 8, 0);
                w->unk18 |= 2;
            }
            if (w->unk18 & 1) {
                stop = 0;
                if (GwPlayer[w->unk20].flags & 1) {
                    stop = func_800F8C44_UnusedMinigame1(obj);
                } else {
                    stop += ContBtn[w->unk23] >> 15;
                }
                if (stop != 0) {
                    func_80060540(0, w->unk20);
                    w->unk18 &= ~1;
                    return;
                }
                w->unkC = D_800F94AC_UnusedMinigame1;
                func_80025830(obj->model[3], D_800F94AC_UnusedMinigame1, 1.0f, 1.0f);
                w->unk10 = D_800F94AC_UnusedMinigame1 * 70.0f + 60.0f + w->x;
                func_80025798(obj->model[5], w->unk10, w->y + 80.0f, w->z);
            }
            break;
        case 2:
            func_800F8764_UnusedMinigame1(obj);
            break;
    }
}

/* CPU: stop now? More likely the closer the arm is to the mark. */
s32 func_800F8C44_UnusedMinigame1(omObjData* obj) {
    UM1Machine* w = obj->unk_50;
    u8 r;
    s32 d;
    u32 chance;
    s32 res = 0;

    r = rand8();
    d = 344.0f - w->unk10;
    chance = 0;
    if (d < -4) {
        chance = 0x20;
    } else if (d < 12) {
        chance = 0x48;
    } else if (d < 50) {
        chance = 0x28;
    }
    res += r < chance;
    return res;
}

/* The first machine with an arm (not character 3) has finished its intro animation. */
s32 func_800F8CD0_UnusedMinigame1(void) {
    omObjData* o;
    s32 i;
    s16 m;
    f32 t;

    for (i = 0; i < 4; i++) {
        o = D_800F9498_UnusedMinigame1[i];
        if (((UM1Machine*)o->unk_50)->unk22 != 3) {
            break;
        }
    }
    m = o->model[2];
    i = 0; /* reused as the result */
    if (m != 0) {
        t = func_80025D18(m);
        if (func_80025D40(m) <= t) {
            i = 1;
        }
    }
    return i;
}

/* Trailing zero words of the unit's .rodata (retail pads it to the next unit's 16-byte start). */
const s32 D_800F93E4_UnusedMinigame1[3] = { 0, 0, 0 };
