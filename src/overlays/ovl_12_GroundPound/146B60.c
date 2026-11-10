#include "GroundPound.h"

/* One hole grid layout (D_800FA030[3], indexed by D_800FA270). */
typedef struct GPGrid {
    /* 0x00 */ f32 x0;
    /* 0x04 */ f32 z0;
    /* 0x08 */ f32 dx;
    /* 0x0C */ f32 dz;
    /* 0x10 */ f32 cx;
    /* 0x14 */ f32 cz;
    /* 0x18 */ u8 cols;
    /* 0x19 */ u8 rows;
    /* 0x1A */ u8 nKind1;
} GPGrid; /* size = 0x1C */

/* A scenery model placement (D_800FA0AC[17]). */
typedef struct GPProp {
    f32 x;
    f32 y;
    f32 z;
    f32 scale;
} GPProp;

GPGrid D_800FA030_GroundPound[3] = {
    { -710.0f, -150.0f, 260.0f, 260.0f, -315.0f, 85.0f, 4, 3, 7 },
    { -580.0f, -150.0f, 260.0f, 260.0f, -450.0f, 110.0f, 3, 3, 5 },
    { -710.0f, -350.0f, 260.0f, 260.0f, -305.0f, 10.0f, 4, 4, 9 },
};

s32 D_800FA084_GroundPound[6] = { 0x240005, 0x240006, 0x240007, 0x240008, 0x240009, 0x24000A };

f32 func_800F750C_GroundPound(omObjData* obj, f32 angle);
f32 func_800F7560_GroundPound(omObjData* obj, f32 angle);
f32 func_800F7628_GroundPound(omObjData* obj, f32 angle);
f32 func_800F7844_GroundPound(omObjData* obj, f32 angle);

/* Mole behaviour by GPMoleWork.state (1..4); retail indexes it from D_800FA098 = this - 4. */
f32 (*D_800FA09C_GroundPound[4])(omObjData*, f32) = {
    func_800F750C_GroundPound,
    func_800F7560_GroundPound,
    func_800F7844_GroundPound,
    func_800F7628_GroundPound,
};

GPProp D_800FA0AC_GroundPound[17] = {
    { -875.0f, 10.0f, 865.0f, 0.6f },
    { -720.0f, 10.0f, -615.0f, 0.55f },
    { -950.0f, 10.0f, -575.0f, 0.75f },
    { -1075.0f, 10.0f, -305.0f, 0.8f },
    { 375.0f, 10.0f, -305.0f, 0.6f },
    { 125.0f, 10.0f, -580.0f, 0.55f },
    { -725.0f, 10.0f, 775.0f, 0.35f },
    { -365.0f, 10.0f, 1075.0f, 0.7f },
    { -185.0f, 10.0f, 795.0f, 0.4f },
    { 240.0f, 10.0f, 820.0f, 0.55f },
    { 380.0f, 10.0f, 410.0f, 0.75f },
    { -1015.0f, 10.0f, 115.0f, 0.45f },
    { -530.0f, 10.0f, -715.0f, 0.95f },
    { -105.0f, 10.0f, -660.0f, 0.9f },
    { -25.0f, 10.0f, 1245.0f, 0.9f },
    { -375.0f, 10.0f, -795.0f, 0.75f },
    { -850.0f, 10.0f, -725.0f, 1.1f },
};

void func_800F6F40_GroundPound(void) {
    s32 i;

    D_800FA450_GroundPound = 105;
    for (i = 0; i < D_800FA276_GroundPound; i++) {
        omObjData* obj = D_800FA3F0_GroundPound[i];

        ((GPMoleWork*)obj->unk_50)->req = 4;
        func_800258EC(obj->model[0], 4, 0);
    }
}

s32 func_800F6FD4_GroundPound(void) {
    s32 ret = 0;
    s32 i;

    for (i = 0; i < D_800FA276_GroundPound; i++) {
        if (((GPMoleWork*)D_800FA3F0_GroundPound[i]->unk_50)->state != 1) {
            break;
        }
    }
    if (i == D_800FA276_GroundPound) {
        ret++;
    }
    return ret;
}

void func_800F7044_GroundPound(s16 i) {
    GPMoleWork* w = D_800FA3F0_GroundPound[i]->unk_50;

    if (w->state == 1) {
        w->req = 3;
    }
}

void func_800F7078_GroundPound(s16 i) {
    omObjData* obj = D_800FA3F0_GroundPound[i];

    if (((GPMoleWork*)obj->unk_50)->state == 1) {
        obj->work[0] = 1;
    }
}

void func_800F70AC_GroundPound(Vec* home, Vec* out) {
    f32 dx;
    f32 dz;
    f32 alt;

    alt = -1120.0f - home->x;
    dx = 450.0f - home->x;
    if (fabs(alt) < fabs(dx)) {
        dx = alt;
    }
    alt = -820.0f - home->z;
    dz = 830.0f - home->z;
    if (fabs(alt) < fabs(dz)) {
        dz = alt;
    }
    if (fabs(dx) < fabs(dz)) {
        dx += home->x;
        dz = home->z;
    } else {
        dx = home->x;
        dz += home->z;
    }
    out->x = dx;
    out->z = dz;
}

void func_800F7180_GroundPound(omObjData* obj, f32 angle, f32 speed, f32 minY, f32 maxY) {
    f32 dx;
    f32 frame;
    s32 r;

    r = (rand8() & 3) - 1;
    speed += r;
    dx = speed * func_800AEAC0(angle);
    obj->trans.z -= speed * func_800AEFD0(angle);
    obj->trans.x -= dx;
    frame = func_80025D18(obj->model[0]);
    r = rand8();
    dx = (r & 7) + 1;
    r >>= 3;
    dx += r & 7;
    if (frame < 8.0f) {
        if ((obj->trans.y += dx) > maxY + 30.0f) {
            obj->trans.y = obj->trans.y - dx - dx;
        }
    } else {
        if ((obj->trans.y -= dx) < maxY - 15.0f) {
            obj->trans.y = dx + (dx + obj->trans.y);
        }
        if (obj->trans.y < minY) {
            obj->trans.y = minY;
        }
    }
}

f32 func_800F7310_GroundPound(s32 fast, f32 angle, f32 dx, f32 dz) {
    f32 t;
    f32 diff;
    s32 neg;

    t = func_800B0CD8(dx, dz) - angle;
    neg = 0;
    if (t < 0.0f) {
        neg = 1;
    }
    diff = fabsf(t);
    if (diff > 180.0f) {
        diff = 360.0f - diff;
        neg--;
    }
    t = 6.0f;
    if (fast != 0) {
        t = 24.0f;
    }
    if (diff > t) {
        diff = t;
    }
    if (neg != 0) {
        angle -= diff;
    } else {
        angle += diff;
    }
    return angle;
}

f32 func_800F73E4_GroundPound(GPMoleWork* w, f32 angle) {
    if (w->timer-- == 0) {
        if (w->dir != 0) {
            w->timer = 6;
            w->dir = 0;
        } else {
            s32 r = rand8();

            w->timer = (r & 3) + 2 + ((r >> 2) & 3);
            if (w->timer & 1) {
                w->dir = 1;
            } else {
                w->dir = -1;
            }
        }
    }
    if (w->dir < 0) {
        angle -= 6.0f;
    } else if (w->dir != 0) {
        angle += 6.0f;
    }
    if (angle < -180.0f) {
        angle += 360.0f;
    } else if (angle > 180.0f) {
        angle -= 360.0f;
    }
    return angle;
}

f32 func_800F750C_GroundPound(omObjData* obj, f32 angle) {
    GPMoleWork* w = obj->unk_50;

    if (w->timer-- == 0) {
        w->timer = 120;
        func_80025BB8(obj->model[0], obj->motion[0]);
    }
    return angle;
}

f32 func_800F7560_GroundPound(omObjData* obj, f32 angle) {
    GPMoleWork* w = obj->unk_50;
    f32 dx = obj->trans.x - w->home.x;
    f32 dz = obj->trans.z - w->home.z;

    if (dx * dx + dz * dz > 57600.0f) {
        angle = func_800F7310_GroundPound(0, angle, dx, dz);
    }
    angle = func_800F73E4_GroundPound(w, angle);
    func_800F7180_GroundPound(obj, angle, w->speed, w->home.y, w->pos.y);
    return angle;
}

// decomp-permuter
f32 func_800F7628_GroundPound(omObjData *obj, f32 angle)
{
  f32 dist;
  GPMoleWork *w = obj->unk_50;
  f32 dx = obj->trans.x - w->home.x;
  f32 dz = obj->trans.z - w->home.z;
  f32 d = (dx * dx) + (dz * dz);
  s32 fast;
  if (d < 196.0f)
  {
    w->state = 1;
    w->pos.x = w->home.x;
    w->pos.y = w->home.y;
    w->pos.z = w->home.z;
    func_80025BB8(obj->model[0], obj->motion[0]);
    func_80025EB4(obj->model[0], 2, 0);
    w->timer = 120;
  }
  else
  {
    dist = func_800B1750(d);
    if (d < 3600.0f)
    {
      if (dist > 0.01f)
      {
        d = (w->pos.y - w->home.y) / dist;
        w->pos.y -= d;
      }
    }
    fast = D_800FA450_GroundPound < 25;
    if (D_800FA450_GroundPound < 48)
    {
      goto turn;
    }
    if (d > 57600.0f)
    {
      turn:
      angle = func_800F7310_GroundPound(fast, angle, dx, dz);

    }
    if (D_800FA450_GroundPound != 0)
    {
      if ((dist / w->speed) > (D_800FA450_GroundPound - 15))
      {
        w->speed = dist / D_800FA450_GroundPound;
      }
      else
      {
        angle = func_800F73E4_GroundPound(w, angle);
      }
    }
    func_800F7180_GroundPound(obj, angle, w->speed, w->home.y, w->pos.y);
  }
  if (dist || (&w->home))
  {
    return angle;
  }
  else
  {
    return angle;
  }
}

f32 func_800F7844_GroundPound(omObjData* obj, f32 angle) {
    GPMoleWork* w = obj->unk_50;
    f32 dx = obj->trans.x - w->pos.x;
    f32 dz = obj->trans.z - w->pos.z;

    if (dx * dx + dz * dz < 1024.0f) {
        w->state = 0;
        func_80025EB4(obj->model[0], 2, 0);
        func_800258EC(obj->model[0], 4, 4);
        return angle;
    }
    if (obj->trans.y < w->pos.y) {
        obj->trans.y += 12.0f;
    }
    angle = func_800F73E4_GroundPound(w, func_800F7310_GroundPound(0, angle, dx, dz));
    func_800F7180_GroundPound(obj, angle, w->speed, w->home.y, w->pos.y);
    return angle;
}

void func_800F796C_GroundPound(omObjData* obj) {
    GPMoleWork* w = obj->unk_50;
    f32 angle = w->angle;
    f32 s;

    if (w->req != 0) {
        switch (w->req) {
        case 4:
            w->speed *= 1.5f;
            break;
        case 3:
            w->timer = 12;
            func_800F70AC_GroundPound(&w->home, &w->pos);
            w->pos.y = w->home.y + 120.0f;
            w->speed = 30.0f;
            func_80025BB8(obj->model[0], obj->motion[1]);
            func_80025EB4(obj->model[0], 2, 2);
            break;
        }
        w->state = w->req;
        w->req = 0;
    }
    if (w->state != 0) {
        angle = D_800FA09C_GroundPound[w->state - 1](obj, angle);
    }
    if (w->angle != angle) {
        w->angle = angle;
        s = func_800AEAC0(angle) * 45.0f;
        omSetRot(obj, 90.0f - func_800AEFD0(angle) * 45.0f, s, angle);
    }
    if (obj->work[0] != obj->work[1]) {
        obj->work[1] = obj->work[0];
        if (obj->work[0] != 0) {
            func_800399F0(w->sprite);
            w->sprite = func_80038D5C(D_800F2B7C[obj->model[0]].unk_6C, D_800FA27A_GroundPound[w->type + 1], 0, "c130t000_DEF");
        } else {
            func_800399F0(w->sprite);
            w->sprite = func_80038D5C(D_800F2B7C[obj->model[0]].unk_6C, D_800FA27A_GroundPound[w->type], 0, "c130t000_DEF");
        }
        func_80025AD4(obj->model[0]);
    }
    obj->work[0] = 0;
}

void func_800F7BB8_GroundPound(omObjData* obj) {
    GPMoleWork* w;
    unkStructGroundPound_00* hole;
    Vec* home;
    Vec* pos;
    u16 mdl;
    s32 i;
    s32 found;
    void* file;

    obj->unk_50 = func_80023684(sizeof(GPMoleWork), 0x7918);
    func_8009B770(obj->unk_50, 0, sizeof(GPMoleWork));
    w = obj->unk_50;
    if (D_800FA290_GroundPound[D_800FA278_GroundPound].kind == 0) {
        hole = &D_800FA318_GroundPound[D_800FA290_GroundPound[D_800FA278_GroundPound].idx];
    } else {
        hole = &D_800FA380_GroundPound[D_800FA290_GroundPound[D_800FA278_GroundPound].idx];
    }
    mdl = LoadFormFile(0x240002, 0x689);
    obj->model[0] = mdl;
    func_8001775C(obj, 0, 0x240002);
    func_8001775C(obj, 1, 0x240003);
    if (D_800FA27A_GroundPound[0] < 0) {
        for (i = 0; i < 6; i++) {
            file = DataRead(D_800FA084_GroundPound[i]);
            D_800FA27A_GroundPound[i] = func_80038A9C((unk2C0C0StructC0*)-1, file, 0, "c130t000_DEF");
            HuMemDirectFree(file);
        }
    }
    i = rand8();
    w->type = 0;
    if (i < 85) {
        w->type = 2;
    } else if (i < 170) {
        w->type = 4;
    }
    w->sprite = func_80038D5C(D_800F2B7C[(s16)mdl].unk_6C, D_800FA27A_GroundPound[w->type], 0, "c130t000_DEF");
    func_80025AD4(mdl);
    func_80025BB8(mdl, obj->motion[1]);
    func_80025EB4(mdl, 2, 2);
    i = (u8)(rand8() % 10) * 2;
    func_80025CA8(mdl, i);
    omSetRot(obj, 20.0f, 0.0f, 0.0f);
    i = func_800F9FEC_GroundPound() % 360 - 180;
    w->angle = i;
    i = rand8() & 0xF;
    w->speed = (i + 32) / 4.0f;
    w->timer = 8;
    w->unk_28 = D_800FA278_GroundPound;
    w->dir = 0;
    w->req = 0;
    obj->work[0] = 0;
    obj->work[1] = 0;
    pos = &w->pos;
    home = &pos[1];
    home->x = hole->unk_00;
    home->y = 180.0f;
    home->z = hole->unk_04 + 90.0f;
    found = 0;
    for (i = 0; i < 4; i++) {
        if (D_800FA286_GroundPound[i] == D_800FA278_GroundPound) {
            found++;
            break;
        }
    }
    if (found) {
        pos->x = home->x;
        pos->z = home->z;
        w->state = 2;
    } else {
        w->state = 0;
        func_800F70AC_GroundPound(home, pos);
    }
    pos->y = home->y + 60.0f;
    omSetTra(obj, pos->x, pos->y, pos->z);
    obj->func_ptr = &func_800F796C_GroundPound;
    D_800FA278_GroundPound++;
}

void func_800F7FEC_GroundPound(void) {
    s32 i;
    s32 j;
    s32 r;

    D_800FA270_GroundPound = 0;
    D_800FA276_GroundPound = 0;
    D_800FA278_GroundPound = 0;
    for (i = 0; i < 16; i++) {
        D_800FA3F0_GroundPound[i] = NULL;
    }
    D_800FA272_GroundPound[0] = -1;
    D_800FA272_GroundPound[1] = -1;
    for (i = 0; i < 6; i++) {
        D_800FA27A_GroundPound[i] = -1;
    }
    D_800FA430_GroundPound[0] = omAddObj(4, 0x18, 0, -1, &func_800F8264_GroundPound);
    func_800F8744_GroundPound();
    D_800FA430_GroundPound[1] = omAddObj(4, 7, 0, -1, &func_800F8688_GroundPound);
    D_800FA430_GroundPound[2] = omAddObj(4, 9, 0, -1, &func_800F86FC_GroundPound);
    for (i = 0; i < 4; i++) {
        D_800FA286_GroundPound[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        do {
            r = rand8() % D_800FA276_GroundPound;
            if (i != 0) {
                for (j = 0; j < i; j++) {
                    if (D_800FA286_GroundPound[j] == r) {
                        break;
                    }
                }
                if (j != i) {
                    r = 1;
                    continue;
                }
            }
            D_800FA286_GroundPound[i] = r;
            r = 0;
        } while (r);
    }
    for (i = 0; i < D_800FA276_GroundPound; i++) {
        D_800FA3F0_GroundPound[i] = omAddObj(8, 8, 2, -1, &func_800F7BB8_GroundPound);
    }
}

void func_800F823C_GroundPound(void) {
    if (D_800FA450_GroundPound != 0) {
        D_800FA450_GroundPound--;
    }
}

void func_800F8264_GroundPound(omObjData* obj) {
    u16 tree;
    s16 copy;
    s32 slot;
    u32 i;
    GPStageWork* w;

    obj->model[0] = func_800174C0(0x370000, 0x699);
    obj->scale.y = 0.0001f;
    obj->trans.y = -1.3f;
    tree = func_800174C0(0x1D0004, 0x699);
    obj->model[1] = tree;
    slot = 2;
    func_80025798(tree, 265.0f, 10.0f, -660.0f);
    func_80025830(tree, 1.6f, 1.6f, 1.6f);
    for (i = 0; i < ARRAY_COUNT(D_800FA0AC_GroundPound); i++) {
        copy = func_80023FC8(tree);
        obj->model[slot++] = copy;
        func_80025798(copy, D_800FA0AC_GroundPound[i].x, D_800FA0AC_GroundPound[i].y, D_800FA0AC_GroundPound[i].z);
        func_80025830(copy, D_800FA0AC_GroundPound[i].scale, D_800FA0AC_GroundPound[i].scale, D_800FA0AC_GroundPound[i].scale);
    }
    func_800090B8(D_800ED440);
    D_800F2AF8[D_800ED440++] = obj;
    obj->unk_50 = w = func_80023684(sizeof(GPStageWork), 0x7918);
    func_8009B770(w, 0, sizeof(GPStageWork));
    w->unk_04 = 1;
    w->unk_05 = 0;
    func_80009028(obj, 0, -950.0f, -600.0f, 310.0f, 600.0f);
    func_80009090(obj);
    obj->func_ptr = &func_800F823C_GroundPound;
}

s32 func_800F8480_GroundPound(omObjData* obj, s32 i, unkStructGroundPound_00* hole, s32 file, s32 heap, s32 max) {
    while ((hole->unk_08 != 0) & (i < max)) {
        if (i == 0) {
            obj->model[0] = func_800174C0(file, heap);
            obj->trans.x = hole->unk_00;
            obj->trans.y = 0.0f;
            obj->trans.z = hole->unk_04;
        } else {
            obj->model[i] = func_80023FC8(obj->model[0]);
            func_80025798(obj->model[i], hole->unk_00, 0.0f, hole->unk_04);
        }
        hole++;
        i++;
    }
    return i;
}

void func_800F8568_GroundPound(omObjData* obj) {
    s16* mdl;
    unkStructGroundPound_00* hole;
    u8* st;
    s32 i;
    f32 y;

    mdl = obj->model;
    hole = D_800FA318_GroundPound;
    st = D_800FA378_GroundPound;
    for (i = 0; i < 7; st++, hole++, i++, mdl++) {
        if (*st == 0) {
            continue;
        }
        switch (*st) {
        case 10:
            *st = 2;
        case 2:
            y = -61.9f;
            break;
        case 1:
            y = -123.8f;
            break;
        }
        if (i != 0) {
            func_80025798(*mdl, hole->unk_00, y, hole->unk_04);
        } else {
            obj->trans.y = y;
        }
        (*st)--;
    }
}

void func_800F8688_GroundPound(omObjData* obj) {
    s32 i;
    u8* p = D_800FA378_GroundPound;

    for (i = 7; i != 0; i--) {
        *p++ = 0;
    }
    func_800F8480_GroundPound(obj, 0, D_800FA318_GroundPound, 0x240001, 0x699, 7);
    obj->func_ptr = &func_800F8568_GroundPound;
}

void func_800F86FC_GroundPound(omObjData* obj) {
    func_800F8480_GroundPound(obj, 0, D_800FA380_GroundPound, 0x240000, 0x699, 9);
    obj->func_ptr = NULL;
}

// register allocation: t0/t1, a1/a2 (masked 0)
#ifdef NON_MATCHING
void func_800F8744_GroundPound(void) {
    u8 order[16];
    Vec pos;
    GPGrid* g;
    u8* p;
    s32 i;
    s32 n;
    s32 row;
    u8 t;
    u8 count;
    u8 kind;
    s32 k;
    s32 n0;
    s32 n1;

    g = &D_800FA030_GroundPound[D_800FA270_GroundPound];
    D_800FA36C_GroundPound.x = g->cx;
    D_800FA36C_GroundPound.y = 0.0f;
    D_800FA36C_GroundPound.z = g->cz;
    p = order;
    for (i = 0; i < g->nKind1; i++) {
        *p++ = 1;
    }
    for (; i < 16; i++) {
        *p++ = 0;
    }
    count = g->rows * g->cols;
    n = 64;
    do {
        n--;
        i = (u8)(rand8() % count);
        row = (u8)(rand8() % count);
        t = order[i];
        order[i] = order[row];
        order[row] = t;
    } while (n != 0);
    k = 0;
    n0 = 0;
    pos.z = g->z0;
    n1 = 0;
    for (row = 0; row < g->rows; row++) {
        pos.x = g->x0;
        for (i = 0; i < g->cols; i++) {
            D_800FA2B0_GroundPound[i][row].kind = kind = order[k & 0xFF];
            if (kind == 0) {
                D_800FA2B0_GroundPound[i][row].idx = n0;
                D_800FA318_GroundPound[n0].unk_00 = pos.x;
                D_800FA318_GroundPound[n0].unk_04 = pos.z;
                D_800FA318_GroundPound[n0].unk_08 = 1;
                D_800FA318_GroundPound[n0].unk_0A = D_800FA276_GroundPound;
                n = n0++;
            } else {
                D_800FA2B0_GroundPound[i][row].idx = n1;
                D_800FA380_GroundPound[n1].unk_00 = pos.x;
                D_800FA380_GroundPound[n1].unk_04 = pos.z;
                D_800FA380_GroundPound[n1].unk_08 = 1;
                D_800FA380_GroundPound[n1].unk_0A = D_800FA276_GroundPound;
                n = n1++;
            }
            D_800FA290_GroundPound[D_800FA276_GroundPound].kind = kind;
            D_800FA290_GroundPound[D_800FA276_GroundPound].idx = n;
            D_800FA276_GroundPound++;
            pos.x += g->dx;
            k++;
        }
        pos.z += g->dz;
    }
    for (; n0 < 7; n0++) {
        D_800FA318_GroundPound[n0].unk_08 = 0;
    }
    for (; n1 < 9; n1++) {
        D_800FA380_GroundPound[n1].unk_08 = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_12_GroundPound/146B60", func_800F8744_GroundPound);
#endif

// register allocation: float registers (masked 0)
#ifdef NON_MATCHING
f32 func_800F8AA0_GroundPound(omObjData* obj) {
    f32 lo;
    f32 hi;
    f32 x;
    f32 res;
    GPGrid* g;
    s32 i;

    res = 0.0f;
    g = &D_800FA030_GroundPound[D_800FA270_GroundPound];

    hi = g->rows * g->dz + g->z0;
    if (obj->trans.z < hi) {
        hi = g->x0 + 80.0f;
        lo = g->x0 - 80.0f;
        x = obj->trans.x;
        for (i = 0; i < g->cols; i++) {
            if (i == 0 && x < hi) {
                res = hi - 20.0f;
                break;
            }
            if (i == g->cols - 1 && lo < x) {
                res = lo + 20.0f;
                break;
            }
            if (lo < x && x < hi) {
                if (hi - x < x - lo) {
                    res = hi - 20.0f;
                } else {
                    res = lo + 20.0f;
                }
                break;
            }
            lo += g->dx;
            hi += g->dx;
        }
    }
    return res;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_12_GroundPound/146B60", func_800F8AA0_GroundPound);
#endif
