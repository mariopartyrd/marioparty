#include "BoxMountainMayhem.h"

s32 D_800FBFD0_BoxMountainMayhem = 0;

void func_800F7110_BoxMountainMayhem(void) {
    omObjData* obj;
    s32 i;

    D_800FC100_BoxMountainMayhem = -1;
    for (i = 0; i < 4; i++) {
        D_800FC1E0_BoxMountainMayhem[i] = obj = omAddObj(8, 3, 0, -1, func_800F719C_BoxMountainMayhem);
        omSetStatBit(obj, 0xA0);
    }
}

void func_800F719C_BoxMountainMayhem(omObjData* obj) {
    BMMBodyWork* work;
    BMMBoxExt* ext;
    void* p;
    u16 model;

    p = func_80023684(sizeof(BMMBodyWork), 0x7918);
    obj->unk_50 = p;
    func_8009B770(p, 0, sizeof(BMMBodyWork));
    work = obj->unk_50;
    p = func_80023684(sizeof(BMMBoxExt), 0x7918);
    work->unk_68.box = p;
    func_8009B770(p, 0, sizeof(BMMBoxExt));
    ext = work->unk_68.box;
    D_800FC100_BoxMountainMayhem = model = LoadFormFile(0x290001, 0x689);
    obj->model[0] = model;
    func_80025930(model, 0x20000, 0x20000);
    func_80025AD4(model);
    func_80026040(model);
    if (D_800FC244_BoxMountainMayhem < 0) {
        model = D_800FC244_BoxMountainMayhem = func_800174F4(6, 0x689);
    } else {
        model = func_80023FC8(D_800FC244_BoxMountainMayhem);
    }
    obj->model[1] = model;
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    obj->trans.x = obj->trans.z = rand8() & 0x3F;
    obj->work[0] = 0;
    obj->work[1] = 0;
    work->unk_54 = 0;
    work->unk_40 = 10.0f;
    work->unk_48 = 35.0f;
    work->unk_34 = 50.0f;
    ext->unk_00 = 200.0f;
    ext->unk_04 = -24.0f;
    ext->unk_28 = 0.0f;
    ext->unk_2C = 1.0f;
    work->unk_44 = 0.1f;
    work->unk_5C = 0;
    work->unk_60 = 0;
    work->unk_50 = 0;
    func_800090D8(obj, 0, 0);
    func_800090D8(obj, 1, 0);
    obj->func_ptr = func_800F79F4_BoxMountainMayhem;
}

void func_800F739C_BoxMountainMayhem(omObjData* obj, BMMBodyWork* work, BMMBoxExt* ext) {
    omObjData* player;
    f32 r;
    f32 x;
    f32 y;
    f32 z;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 floor;
    s16 model;

    floor = 0.0f;
    x = obj->trans.x;
    y = obj->trans.y;
    z = obj->trans.z;
    player = ext->unk_18;
    r = BMM_PLAYER(player)->unk_48;
    y += ext->unk_00;
    if (y < floor) {
        y = floor;
        ext->unk_00 = y - ext->unk_00;
        ext->unk_08 = y - ext->unk_08;
        ext->unk_0C = y - ext->unk_0C;
        work->unk_5C = 0;
    }
    ext->unk_00 += ext->unk_04;
    x += ext->unk_08;
    z += ext->unk_0C;
    dx = x - ext->unk_1C;
    dy = y - ext->unk_20;
    dz = z - ext->unk_24;
    if (dy < 0.0f) {
        dy = 0.0f;
        ext->unk_20 = dy - y;
    }
    if (dx < r + -350.0f) {
        dx = r + -350.0f;
        ext->unk_08 = 0.0f - ext->unk_08;
    }
    if (350.0f - r < dz) {
        dz = 350.0f - r;
        ext->unk_0C = 0.0f - ext->unk_0C;
    }
    if (750.0f - r < dx) {
        dx = 750.0f - r;
        ext->unk_08 = 0.0f - ext->unk_08;
    }
    if (dz < r + -750.0f) {
        dz = r + -750.0f;
        ext->unk_0C = 0.0f - ext->unk_0C;
    }
    x = dx + ext->unk_1C;
    y = dy + ext->unk_20;
    z = dz + ext->unk_24;
    if (x > 600.0f) {
        x = 600.0f;
        ext->unk_08 = 0.0f - ext->unk_08;
    }
    if (z < -600.0f) {
        z = -600.0f;
        ext->unk_0C = 0.0f - ext->unk_0C;
    }
    model = obj->model[1];
    if ((model != 0) & (floor != -10000.0f)) {
        func_80025798(model, x, floor, z);
        if (fabs(y - floor) < 50.0) {
            func_80025830(model, 1.0f, 1.0f, 1.0f);
        } else {
            func_80025830(model, 0.9f, 0.9f, 0.9f);
        }
    }
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = z;
    player->trans.x = dx;
    player->trans.y = dy;
    player->trans.z = dz;
}

/* Unreferenced double after func_800F739C's literal in retail .rodata. */
const f64 D_800FC0C8_BoxMountainMayhem = 0.0;

// decomp-permuter
void func_800F76F4_BoxMountainMayhem(f32 x, f32 y, f32 z, s32 count)
{
  omObjData *new_var;
  Vec pos;
  f32 angle;
  int new_var2;
  s16 n;
  pos.x = x;
  pos.y = y;
  pos.z = z;
  while (count != 0)
  {
    new_var2 = func_800FBD2C_BoxMountainMayhem() % 360;
    n = D_800FC288_BoxMountainMayhem;
    angle = (s32) new_var2;
    if (n < 12)
    {
      D_800FC288_BoxMountainMayhem = n + 1;
      new_var = D_800FC248_BoxMountainMayhem[n];
      func_800F8350_BoxMountainMayhem(new_var, &pos, angle);
    }
    count--;
  }

}

// 0x88888889 hoisted out of the retry loop, float registers (masked 24); a goto retry loop
// hoists nothing (retail hoists 950.0f and the table base)
#ifdef NON_MATCHING
void func_800F77C8_BoxMountainMayhem(omObjData* obj) {
    BMMBodyWork* work;
    BMMBoxExt* ext;
    BMMBodyWork* w;
    BMMBoxExt* e;
    omObjData* o;
    f32 min;
    f32 angle;
    f32 c;
    f32 s;
    f32 tx;
    f32 tz;
    f32 ax;
    f32 az;
    s32 tries;
    s32 i;

    work = BMM_BODY(obj);
    ext = work->unk_68.box;
    min = BMM_PLAYER(ext->unk_18)->unk_48;
    min += min;
    tries = 128;
    do {
        angle = (f32)(s32)(func_800FBD2C_BoxMountainMayhem() % 240 + 60) / 4.0f;
        c = func_800AEFD0(angle) * 950.0f;
        s = func_800AEAC0(angle) * 950.0f;
        tx = 750.0f - c;
        tz = s + -750.0f;
        for (i = 0; i < 4; i++) {
            o = D_800FC1E0_BoxMountainMayhem[i];
            if (o != NULL && (w = BMM_BODY(o))->unk_54 != 0) {
                e = w->unk_68.box;
                ax = fabsf(e->unk_10 - tx);
                az = fabsf(e->unk_14 - tz);
                if ((ax < min) & (az < min)) {
                    break;
                }
            }
        }
        tries--;
    } while ((i < 4) & (tries != 0));
    ext->unk_10 = tx;
    ext->unk_14 = tz;
    tx += ext->unk_1C;
    tz += ext->unk_24;
    ext->unk_00 = 165.0f;
    ext->unk_04 = -33.0f;
    work->unk_5C = 14;
    ext->unk_08 = (tx - obj->trans.x) / 10.0f;
    ext->unk_0C = (tz - obj->trans.z) / 10.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_BoxMountainMayhem/166D50", func_800F77C8_BoxMountainMayhem);
#endif

void func_800F79F4_BoxMountainMayhem(omObjData* obj) {
    BMMBodyWork* work;
    BMMBoxExt* ext;
    omObjData* player;

    work = BMM_BODY(obj);
    ext = work->unk_68.box;
    if (func_8005FD5C() + D_800F64F8 != 0) {
        if (work->unk_54 == 2) {
            func_80026B8C(obj->model[0], ext->unk_28, ext->unk_2C, 1);
        }
        return;
    }
    if (work->unk_54 == 1) {
        func_800F77C8_BoxMountainMayhem(obj);
        work->unk_60 = 3;
        obj->rot.y = work->unk_3C;
        func_80026B8C(obj->model[0], 0.0f, 1.0f, 1);
        func_800090D8(obj, 0, 1);
        func_800090D8(obj, 1, 1);
        work->unk_54 = 3;
    } else if (work->unk_54 == 2) {
        if (obj->work[1] != 0) {
            obj->work[1]--;
            func_80026B8C(obj->model[0], ext->unk_28, ext->unk_2C, 1);
            ext->unk_28 += 0.125f;
            ext->unk_2C += 0.6f;
        } else {
            func_800090D8(obj, 0, 0);
            func_80026B8C(obj->model[0], 0.0f, 1.0f, 1);
            work->unk_54 = 0;
        }
    }
    if (work->unk_54 >= 3) {
        if (work->unk_60 != 0) {
            work->unk_60--;
            func_80026B8C(obj->model[0], 0.0f, 1.0f, 1);
        }
        if (work->unk_5C != 0) {
            work->unk_5C--;
            goto move;
        }
        func_800090D8(obj, 1, 0);
        player = ext->unk_18;
        player->work[2] = 0;
        if (obj->work[0] != 0) {
            func_800F76F4_BoxMountainMayhem(obj->trans.x, obj->trans.y, obj->trans.z, obj->work[0]);
        }
        work->unk_54 = 2;
        obj->work[1] = 7;
        func_80060540(0x284, BMM_PLAYER(player)->unk_58);
        return;
    move:
        func_800F739C_BoxMountainMayhem(obj, work, ext);
    }
}

// register allocation: i in $v1 and table base in $a0, retail the reverse (raw 20, masked 1);
// tried i reused for the int angle, decl order, a local base pointer
#ifdef NON_MATCHING
void func_800F7C30_BoxMountainMayhem(Vec* pos, omObjData* player, s8 count) {
    BMMBodyWork* work;
    BMMBoxExt* ext;
    omObjData* obj;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 angle;
    s32 i;

    for (i = 0; i < 4; i++) {
        obj = D_800FC1E0_BoxMountainMayhem[i];
        if (obj != NULL && (work = BMM_BODY(obj))->unk_54 == 0) {
            break;
        }
    }
    if (i < 4) {
        func_800093FC(obj, pos->x, pos->y, pos->z);
        dx = pos->x - player->trans.x;
        dy = pos->y - player->trans.y;
        dz = pos->z - player->trans.z;
        angle = func_800B0CD8(dx, dz);
        if (angle > 0.0f) {
            angle += 45.5f;
        } else {
            angle -= 45.5f;
        }
        angle = (s32)angle / 90 * 90;
        if (angle > 180.0f) {
            angle -= 360.0f;
        } else if (angle < -180.0f) {
            angle += 360.0f;
        }
        work->unk_3C = angle;
        player->work[2] = 1;
        ext = work->unk_68.box;
        ext->unk_18 = player;
        ext->unk_1C = dx;
        ext->unk_20 = dy;
        ext->unk_24 = dz;
        obj->work[1] = 0;
        ext->unk_28 = 0.0f;
        ext->unk_2C = 1.0f;
        obj->work[0] = count;
        work->unk_54 = 1;
        func_80060618(0x27E, BMM_PLAYER(player)->unk_58);
        func_80060F04(BMM_PLAYER(player)->unk_58, 20, 0, 20);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_BoxMountainMayhem/166D50", func_800F7C30_BoxMountainMayhem);
#endif

// retail sets n in $a1 and copies it to $s2 before the shuffle; ours sets $s2 directly (one move;
// chkf masked 21, the rest are NON_MATCHING data offsets); tried a ternary
#ifdef NON_MATCHING
void func_800F7E70_BoxMountainMayhem(void) {
    s32 a;
    s32 b;
    s16 t;
    s32 n;
    s32 i;

    if (_CheckFlag(0x2B) != 0) {
        n = 12;
    } else {
        n = 6;
    }
    for (i = 0; i < 4; i++) {
        D_800FC118_BoxMountainMayhem[i] = 6;
    }
    for (; i < 12; i++) {
        D_800FC118_BoxMountainMayhem[i] = 3;
    }
    for (i = 32; i != 0; i--) {
        a = rand8() % n;
        b = rand8() % n;
        t = D_800FC118_BoxMountainMayhem[a];
        D_800FC118_BoxMountainMayhem[a] = D_800FC118_BoxMountainMayhem[b];
        D_800FC118_BoxMountainMayhem[b] = t;
    }
    D_800FC288_BoxMountainMayhem = 0;
    D_800FC110_BoxMountainMayhem = 0;
    D_800FC244_BoxMountainMayhem = -1;
    for (i = 0; i < 3; i++) {
        D_800FC238_BoxMountainMayhem[i] = -1;
    }
    for (i = 0; i < 12; i++) {
        D_800FC248_BoxMountainMayhem[i] = NULL;
    }
    for (i = 0; i < 12; i++) {
        D_800FC248_BoxMountainMayhem[i] = omAddObj(4, 4, 0, -1, func_800F80A0_BoxMountainMayhem);
        D_800EDE70[D_800EE984++] = D_800FC248_BoxMountainMayhem[i];
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_BoxMountainMayhem/166D50", func_800F7E70_BoxMountainMayhem);
#endif

// shadow model sign-extension register (masked 6)
#ifdef NON_MATCHING
void func_800F80A0_BoxMountainMayhem(omObjData* obj) {
    BMMBodyWork* work;
    BMMCoinExt* ext;
    void* p;
    s16 sprite; /* the shadow model, then the sprite */
    s32 i;

    p = func_80023684(sizeof(BMMBodyWork), 0x7918);
    obj->unk_50 = p;
    func_8009B770(p, 0, sizeof(BMMBodyWork));
    work = obj->unk_50;
    ext = work->unk_68.coin = func_80023684(sizeof(BMMCoinExt), 0x7918);
    if (D_800FC118_BoxMountainMayhem[D_800FC110_BoxMountainMayhem] == 3) {
        func_800FBE9C_BoxMountainMayhem(obj, 0x21, 0x289, 8, 0, &D_800FC238_BoxMountainMayhem[0]);
    } else {
        func_800FBE9C_BoxMountainMayhem(obj, 0x37, 0x289, 8, 0, &D_800FC238_BoxMountainMayhem[2]);
    }
    if (D_800FC244_BoxMountainMayhem < 0) {
        sprite = D_800FC244_BoxMountainMayhem = func_800174F4(6, 0x689);
    } else {
        sprite = func_80023FC8(D_800FC244_BoxMountainMayhem);
    }
    obj->model[1] = sprite;
    func_800FBE9C_BoxMountainMayhem(obj, 0x2A, 0x68D, 8, 3, &D_800FC238_BoxMountainMayhem[1]);
    sprite = work->unk_21[3];
    func_8001E268(sprite, 4, 4);
    func_8001E2F8(sprite, 0xC0);
    func_8001E360(sprite, 0xFF, 0xFF, 0xBE);
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    func_8000941C(obj, 2.0f, 2.0f, 2.0f);
    work->unk_54 = 0;
    work->unk_40 = 9.0f;
    work->unk_48 = 20.0f;
    work->unk_52 = D_800FC118_BoxMountainMayhem[D_800FC110_BoxMountainMayhem];
    work->unk_44 = 0.1f;
    work->unk_34 = 50.0f;
    work->unk_3C = rand8();
    work->unk_5C = 0;
    work->unk_60 = 0;
    work->unk_50 = D_800FC110_BoxMountainMayhem;
    ext->unk_00 = 0.0f;
    ext->unk_04 = -0.5f;
    for (i = 0; i < 32; i++) {
        func_800090C4(obj, i, 2);
    }
    func_800090D8(obj, 0, 0);
    func_800090D8(obj, 1, 0);
    func_800090D8(obj, 3, 0);
    obj->func_ptr = func_800F8C94_BoxMountainMayhem;
    D_800FC110_BoxMountainMayhem++;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_BoxMountainMayhem/166D50", func_800F80A0_BoxMountainMayhem);
#endif

void func_800F8350_BoxMountainMayhem(omObjData* obj, Vec* pos, f32 angle) {
    BMMBodyWork* work;
    BMMCoinExt* ext;

    if (obj != NULL) {
        work = BMM_BODY(obj);
        ext = work->unk_68.coin;
        func_800093FC(obj, pos->x, pos->y, pos->z);
        work->unk_3C = func_80029518(angle);
        work->unk_40 = 13.5f;
        work->unk_54 = 1;
        ext->unk_00 = 5.0f;
        ext->unk_04 = -0.8f;
        work->unk_38 = 0.0f;
        work->unk_5C = 10;
        work->unk_60 = 1;
    }
}

s32 func_800F8400_BoxMountainMayhem(Vec* from, Vec* out, f32* dist) {
    omObjData* obj;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 d;
    s32 count;
    s32 i;

    count = 0;
    *dist = 6.4e7f;
    for (i = 0; i < 12; i++) {
        obj = D_800FC248_BoxMountainMayhem[i];
        if (obj != NULL && BMM_BODY(obj)->unk_54 != 0) {
            dx = from->x - obj->trans.x;
            dy = from->y - obj->trans.y;
            dz = from->z - obj->trans.z;
            d = dx * dx + dy * dy + dz * dz;
            count++;
            if (d < *dist) {
                *dist = d;
                out->x = obj->trans.x;
                out->y = obj->trans.y;
                out->z = obj->trans.z;
            }
        }
    }
    return count;
}

// decomp-permuter
s32 func_800F84D0_BoxMountainMayhem(void)
{
  omObjData *obj;
  s32 count;
  s32 n;
  s32 i;
  if (_CheckFlag(0x2B) != 0)
  {
    n = 12;
  }
  else
  {
    n = 6;
  }
  count = n;
  count = D_800FC288_BoxMountainMayhem < count;
  for (i = 0; i < n; i++)
  {
    obj = D_800FC248_BoxMountainMayhem[i];
    if (obj != 0)
    {
      count += ((BMMBodyWork *) obj->unk_50)->unk_54 != 0;
    }
  }

  return count;
}

// register allocation throughout (masked 118; control flow and operations checked against the asm)
#ifdef NON_MATCHING
f32 func_800F8548_BoxMountainMayhem(omObjData* obj, Vec* pos, f32 r, s32* hitOut) {
    BMMStageWork* stage;
    BMMStageWork* sw;
    omObjData* stack;
    f32 x;
    f32 y;
    f32 z;
    f32 top;
    f32 t;
    f32 minX;
    f32 maxX;
    f32 minZ;
    f32 maxZ;
    f32 eMinX;
    f32 eMaxX;
    f32 eMinZ;
    f32 eMaxZ;
    f32 dy;
    f32 nx;
    f32 nz;
    f32 ddx;
    f32 ddz;
    f32 cx;
    f32 cz;
    f32 d1;
    f32 d2;
    f32 s;
    s32 hit;
    s32 side;
    s32 in;
    s32 x0;
    s32 x1;
    s32 z0;
    s32 z1;
    s32 i;
    s32 j;

    BMM_BODY(obj)->unk_53 = 0xFF;
    x = pos->x;
    y = pos->y;
    z = pos->z;
    stage = BMM_STAGE(D_800FC240_BoxMountainMayhem);
    top = stage->unk_10;
    hit = 0;
    if (stage->unk_01 & 8) {
        if (y <= top) {
            hit = 1;
            y = top;
        }
        if (x < r + stage->unk_18) {
            hit |= 2;
            x = r + stage->unk_18;
        }
        if (stage->unk_20 - r < x) {
            hit |= 4;
            x = stage->unk_20 - r;
        }
        if (z < r + stage->unk_1C) {
            hit |= 8;
            z = r + stage->unk_1C;
        }
        if (stage->unk_24 - r < z) {
            hit |= 0x10;
            z = stage->unk_24 - r;
        }
    }
    t = 750.0f - x;
    x0 = (s32)((t - r) / 150.0f) - 1;
    if (x0 < 0) {
        x0 = 0;
    }
    x1 = (s32)((t + r) / 150.0f) + 1;
    if (x1 >= 4) {
        x1 = 3;
    }
    t = z + 750.0f;
    z0 = (s32)((t - r) / 150.0f) - 1;
    if (z0 < 0) {
        z0 = 0;
    }
    z1 = (s32)((t + r) / 150.0f) + 1;
    if (z1 >= 4) {
        z1 = 3;
    }
    for (j = z0; j <= z1; j++) {
        for (i = x0; i <= x1; i++) {
            stack = D_800FC1F8_BoxMountainMayhem[j][i];
            if (stack == NULL || stack->work[0] == 0) {
                continue;
            }
            sw = BMM_STAGE(stack);
            if (!(sw->unk_01 & 0x10) || sw->unk_10 <= 0.0f) {
                continue;
            }
            minX = sw->unk_18 + stack->trans.x;
            maxX = sw->unk_20 + stack->trans.x;
            side = 0;
            if (maxX < minX) {
                t = maxX;
                maxX = minX;
                minX = t;
            }
            minZ = sw->unk_1C + stack->trans.z;
            maxZ = sw->unk_24 + stack->trans.z;
            if (maxZ < minZ) {
                t = maxZ;
                maxZ = minZ;
                minZ = t;
            }
            dy = y - sw->unk_10;
            eMinX = minX - r;
            eMaxX = maxX + r;
            eMinZ = minZ - r;
            eMaxZ = maxZ + r;
            if (((minX < x) & (x < maxX)) && ((minZ < z) & (z < maxZ))) {
                in = 3;
            } else if (((eMinX < x) & (x < eMaxX)) && ((eMinZ < z) & (z < eMaxZ))) {
                in = 2;
            } else {
                in = 0;
            }
            if (dy > 5.0) {
                if ((in & 1) && top < sw->unk_10) {
                    top = sw->unk_10;
                    continue;
                }
            } else if (dy >= -35.0f) {
                if (in & 2) {
                    y = sw->unk_10;
                    hit |= 1;
                    if (top < y) {
                        top = y;
                    }
                }
            } else if (!(in & 1)) {
                nx = x;
                if (in & 2) {
                    nz = z;
                    ddz = -1.0f;
                    ddx = -1.0f;
                    if (x < minX) {
                        side |= 4;
                        nx = eMinX;
                        ddx = minX - x;
                    } else if (maxX < x) {
                        side |= 2;
                        ddx = x - maxX;
                        nx = eMaxX;
                    }
                    if (z < minZ) {
                        side |= 0x10;
                        nz = eMinZ;
                        ddz = minZ - z;
                    } else if (maxZ < z) {
                        side |= 8;
                        ddz = z - maxZ;
                        nz = eMaxZ;
                    }
                    if ((ddx > 0.0f) & (ddz > 0.0f)) {
                        /* Retail measures the corner from (minX - r, minZ): no r on z. */
                        cx = stack->trans.x - eMinX;
                        cz = stack->trans.z - minZ;
                        d1 = cx * cx + cz * cz;
                        cx = stack->trans.x - x;
                        cz = stack->trans.z - z;
                        d2 = cx * cx + cz * cz;
                        if (d2 < d1) {
                            s = func_800B1750(d1);
                            t = func_800B1750(d2);
                            x = nx;
                            if (t != 0.0f) {
                                s /= t;
                                x = stack->trans.x - cx * s;
                                z = stack->trans.z - cz * s;
                            } else {
                                z = nz;
                            }
                        } else {
                            side &= ~0x1E;
                        }
                    } else {
                        x = nx;
                        z = nz;
                    }
                }
            }
            hit |= side;
        }
    }
    *hitOut = hit;
    pos->x = x;
    pos->y = y;
    pos->z = z;
    return top;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_BoxMountainMayhem/166D50", func_800F8548_BoxMountainMayhem);
#endif

// frame 8 bytes smaller, k = (hit & 6) != 0 as sltu, shadow sign-extension (masked 43)
#ifdef NON_MATCHING
void func_800F8C94_BoxMountainMayhem(omObjData* obj) {
    BMMBodyWork* work;
    BMMCoinExt* ext;
    Vec pos;
    s32 hit;
    f32 angle;
    f32 speed;
    f32 floor;
    s32 k;
    s32 model;

    work = BMM_BODY(obj);
    ext = work->unk_68.coin;
    if (D_800ED430 != 1 || work->unk_54 == 0) {
        return;
    }
    if (work->unk_60 != 0) {
        func_800090D8(obj, 0, 1);
        func_800090D8(obj, 1, 1);
        work->unk_60 = 0;
    }
    pos.x = obj->trans.x;
    pos.y = obj->trans.y;
    pos.z = obj->trans.z;
    pos.y += ext->unk_00;
    angle = work->unk_3C;
    speed = work->unk_40;
    if (speed > 9.0f) {
        speed -= 0.8f;
        if (speed < 9.0f) {
            speed = 9.0f;
        }
        work->unk_40 = speed;
    }
    pos.x += func_800AEAC0(angle) * speed;
    pos.z += func_800AEFD0(angle) * speed;
    floor = func_800F8548_BoxMountainMayhem(obj, &pos, work->unk_48, &hit);
    if (hit & 1) {
        ext->unk_00 = 0.0f;
        if (!(D_800FBFD0_BoxMountainMayhem & 1)) {
            PlaySound(0x108);
        }
    } else {
        ext->unk_00 += ext->unk_04;
        if (ext->unk_00 > 35.0f) {
            ext->unk_00 = 35.0f;
        } else if (ext->unk_00 < -35.0f) {
            ext->unk_00 = -35.0f;
        }
    }
    if (work->unk_5C != 0) {
        work->unk_5C -= 2;
        if (work->unk_5C < 0) {
            work->unk_5C = 0;
        }
    }
    if (work->unk_5C == 0 && (hit & 0x1E)) {
        if (hit & 6) {
            k = 1;
        } else {
            k = 0;
        }
        if (hit & 0x18) {
            k |= 2;
        }
        switch (k) {
        case 2:
            angle += 180.0f;
            /* fallthrough */
        case 1:
            angle = 0.0f - angle;
            break;
        case 3:
            angle += 180.0f;
            break;
        }
        if (angle > 180.0f) {
            angle -= 360.0f;
        } else if (angle < -180.0f) {
            angle += 360.0f;
        }
    }
    obj->trans.x = pos.x;
    obj->trans.y = pos.y;
    obj->trans.z = pos.z;
    work->unk_3C = angle;
    D_800FBFD0_BoxMountainMayhem = hit;
    model = obj->model[1];
    if ((model != 0) & (floor != -10000.0f)) {
        func_80025798((s16)model, pos.x, floor, pos.z);
        if (fabs(pos.y - floor) < 50.0) {
            func_80025830(model, 0.8f, 0.8f, 0.8f);
        } else {
            func_80025830(model, 0.6f, 0.6f, 0.6f);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_BoxMountainMayhem/166D50", func_800F8C94_BoxMountainMayhem);
#endif
