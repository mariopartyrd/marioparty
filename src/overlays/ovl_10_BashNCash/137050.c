#include "BashNCash.h"

#define BASH_ABS(x) ((x) < 0.0f ? -(x) : (x))
#define PLAYER_WORK(obj) ((BashPlayerWork*)(obj)->unk_50)
#define COIN_WORK(obj) ((BashCoinWork*)(obj)->unk_50)

/* ---------------------------------------------------------------------------------------------
   .data
   --------------------------------------------------------------------------------------------- */

s32 D_800FE3A0_BashNCash = 0; /* next hammer effect */
f32 D_800FE3A4_BashNCash[6][2] = {
    { 320.0f, 320.0f }, { -320.0f, 320.0f }, { 320.0f, -320.0f }, { -320.0f, -320.0f }, { 0.0f, 0.0f }, { 0.0f, 0.0f },
}; /* quadrant centres (x, z) */
s32 D_800FE3D4_BashNCash = 0;
s32 D_800FE3D8_BashNCash = 120;
u32 D_800FE3DC_BashNCash = 929; /* frames left */
s32 D_800FE3E0_BashNCash = 0;
s32 D_800FE3E4_BashNCash = 0;
s32 D_800FE3E8_BashNCash = 0;
s32 D_800FE3EC_BashNCash = 0;
u32 D_800FE3F0_BashNCash = 0;
s32 D_800FE3F4_BashNCash = 0;
s32 D_800FE3F8_BashNCash = 0;
s16 D_800FE3FC_BashNCash[4][2] = { { 56, 38 }, { 264, 38 }, { 56, 216 }, { 264, 216 } }; /* coin counters */
s32 D_800FE40C_BashNCash[4] = { 0, 0, 0, 0 }; /* displayed coins */
s32 D_800FE41C_BashNCash = 0;
Vec3f D_800FE420_BashNCash[4] = {
    { 256.0f, 0.0f, -189.0f }, { -328.0f, 0.0f, -196.0f }, { -275.0f, 0.0f, 380.0f }, { 300.0f, 0.0f, 380.0f },
}; /* start positions: [0] the cash player */

/* ---------------------------------------------------------------------------------------------
   .bss
   --------------------------------------------------------------------------------------------- */

extern f32 D_800FE540_BashNCash;
extern Vec3f D_800FE544_BashNCash;
extern Vec3f D_800FE550_BashNCash;
extern Vec3f D_800FE55C_BashNCash;
extern f32 D_800FE568_BashNCash;
extern f32 D_800FE56C_BashNCash;
extern Vec3f D_800FE570_BashNCash; /* camera eye */
extern Vec3f D_800FE57C_BashNCash; /* camera target */
extern Vec3f D_800FE588_BashNCash; /* camera up */
extern Vec3f D_800FE594_BashNCash;
extern Vec3f D_800FE5A0_BashNCash;
extern s32 D_800FE5AC_BashNCash;
extern f32 D_800FE5B0_BashNCash[3];
extern f32 D_800FE5BC_BashNCash[3];
extern omObjData* D_800FE5D0_BashNCash;
extern u16 D_800FE5D8_BashNCash[4][3]; /* coin counter digits: ones, tens, hundreds */
extern u16 D_800FE5F0_BashNCash[4];
extern u16 D_800FE5F8_BashNCash[4];
extern omObjData* D_800FE600_BashNCash[4];
extern s32 D_800FE610_BashNCash; /* the cash player */
extern s32 D_800FE618_BashNCash[4];
extern u16 D_800FE628_BashNCash;
extern u16 D_800FE62A_BashNCash;
extern s32 D_800FE62C_BashNCash;
extern BashCoinSlot D_800FE630_BashNCash[8];
extern BashCash D_800FE690_BashNCash;
extern BashInput D_800FE6A8_BashNCash[4];
extern BashPlayer D_800FE710_BashNCash[4];

/* ---------------------------------------------------------------------------------------------
   Code
   --------------------------------------------------------------------------------------------- */

void func_800F65E0_BashNCash(void) {
    omObjData* obj;
    u8 cam;

    func_80029090(0x32);
    func_8002ADF0(&D_800EDEC0, 0x40);
    func_8001DE70(0x20);
    omInitObjMan(0x32, 0);
    func_80060088();
    func_8000942C();
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_800F6D20_BashNCash), 0xA0);
    func_800178A0(1);
    cam = func_800178E8();
    func_80017660(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 30.0f, 80.0f, 8000.0f);
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    func_800F6D6C_BashNCash();
    func_800090B8(D_800ED440);
    obj = omAddObj(1, 2, 0, -1, func_800FC840_BashNCash);
    D_800F2AF8[D_800ED440++] = obj;
    func_800F6BCC_BashNCash();
    D_800FE698_BashNCash = GwPlayer[D_800FE610_BashNCash].coins;
    if (_CheckFlag(0x2B) != 0) {
        D_800FE698_BashNCash = 20;
    }
    func_80009500();
    obj = omAddObj(2, 0xC, 0x32, -1, func_800FDF20_BashNCash);
    D_800F3FB0[D_800F2BC0++] = obj;
    obj = omAddObj(2, 0xC, 0x32, -1, func_800FE038_BashNCash);
    D_800F3FB0[D_800F2BC0++] = obj;
    obj = omAddObj(2, 0xC, 0x32, -1, func_800FE158_BashNCash);
    D_800F3FB0[D_800F2BC0++] = obj;
    obj = omAddObj(2, 0xC, 0x32, -1, func_800FE278_BashNCash);
    D_800F3FB0[D_800F2BC0++] = obj;
    obj = omAddObj(3, 4, 0, -1, func_800FCBA8_BashNCash);
    D_800EDE70[D_800EE984++] = obj;
    obj = omAddObj(3, 4, 0, -1, func_800FCC00_BashNCash);
    D_800EDE70[D_800EE984++] = obj;
    obj = omAddObj(3, 4, 0, -1, func_800FCC5C_BashNCash);
    D_800EDE70[D_800EE984++] = obj;
    obj = omAddObj(3, 4, 0, -1, func_800FCCB8_BashNCash);
    D_800EDE70[D_800EE984++] = obj;
    obj = omAddObj(3, 4, 0, -1, func_800FCD14_BashNCash);
    D_800EDE70[D_800EE984++] = obj;
    obj = omAddObj(3, 4, 0, -1, func_800FCD70_BashNCash);
    D_800EDE70[D_800EE984++] = obj;
    obj = omAddObj(3, 4, 0, -1, func_800FCDCC_BashNCash);
    D_800EDE70[D_800EE984++] = obj;
    obj = omAddObj(3, 4, 0, -1, func_800FCE28_BashNCash);
    D_800EDE70[D_800EE984++] = obj;
    omAddObj(4, 3, 0, -1, func_800FC904_BashNCash);
    omAddObj(5, 0, 0, -1, func_800FDBB4_BashNCash);
    omAddObj(0xA, 0, 0, -1, func_800FB928_BashNCash);
    omAddObj(1, 0, 0, -1, func_800F6B80_BashNCash);
    func_8002890C(0, 0, 0);
    SetFadeInTypeAndTime(0, 0x10);
}

void func_800F6B80_BashNCash(omObjData* obj) {
    if (D_800F5144 == 1 || D_800F5144 == 1) { /* retail's test (as in CoinBlockBlitz) */
        func_800601D4(0x28);
        func_8002890C(0, 0, 0);
        omOvlReturnEx(1);
    }
}

/* Picks the cash player (the one in group 0) and shuffles the other three's start positions. */
// register allocation and scheduling (nmcmp: calls and stores equal)
#ifdef NON_MATCHING
void func_800F6BCC_BashNCash(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 n;

    for (i = 0; i < 4; i++) {
        if (GwPlayer[i].group == 0) {
            break;
        }
    }
    if (i >= 4) {
        i = 0;
    }
    D_800FE690_BashNCash.order[0] = i;
    D_800FE610_BashNCash = (u16)i;
    for (k = 1; k < 4; k++) {
        n = rand8() % (4 - k);
        for (j = 0; j < 4; j++) {
            for (i = k; i != 0; i--) {
                if (D_800FE690_BashNCash.order[i - 1] == j) {
                    break;
                }
            }
            if (i == 0) {
                if (n == 0) {
                    break;
                }
                n--;
            }
        }
        if (j >= 4) {
            j = k;
        }
        D_800FE690_BashNCash.order[k] = j;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_BashNCash/137050", func_800F6BCC_BashNCash);
#endif

void func_800F6D20_BashNCash(omObjData* obj) {
    if (D_800FE5AC_BashNCash != 0) {
        func_8001D420(0, &D_800FE570_BashNCash, &D_800FE57C_BashNCash, &D_800FE588_BashNCash);
        func_8001D57C(0);
    }
}

void func_800F6D6C_BashNCash(void) {
    BashInput* in;
    BashPlayer* pl;
    s16 r;
    s32 i;

    in = D_800FE6A8_BashNCash;
    pl = D_800FE710_BashNCash;
    r = (u8)(rand8() % 3);
    for (i = 0; i < 4; i++, in++, pl++) {
        in->flags = 0;
        in->state = 0;
        in->unk_06 = 0;
        in->stickX = 0;
        in->stickY = 0;
        in->trg = 0;
        in->btn = 0;
        pl->obj = NULL;
        pl->unk_0C = r;
        D_800FE618_BashNCash[i] = -1;
    }
    D_800FE628_BashNCash = 0;
    D_800FE62A_BashNCash = 0;
    D_800FE62C_BashNCash = 0;
    D_800FE5AC_BashNCash = 0;
    CZoom = 1880.0f;
    CRot.x = 327.25f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    Center.x = 15.0f;
    Center.y = 0.0f;
    Center.z = -105.0f;
}

void func_800F6EA0_BashNCash(omObjData* obj, u8 arg1, u32 frames) {
    if (arg1 == 1) {
        func_80079078(frames / 30);
    }
}

void func_800F6EE0_BashNCash(void) {
}

void func_800F6EE8_BashNCash(omObjData* obj, f32 scale, f32 y, s32 mdl) {
    func_80025798(obj->model[mdl], obj->trans.x, y + obj->trans.y, obj->trans.z);
    func_80025830(obj->model[mdl], scale, scale, scale);
}

void func_800F6F6C_BashNCash(omObjData* obj) {
    u8 i = obj->work[0];
    BashInput* in = &D_800FE6A8_BashNCash[i];

    if (GwPlayer[i].flags & 1) {
        in->flags |= 1;
        in->difficulty = GwPlayer[i].cpu_difficulty;
    }
}

/* Whether target (moved by ofs) is within reach of obj's hammer. */
u16 func_800F6FD0_BashNCash(omObjData* obj, omObjData* target, Vec3f* ofs) {
    Vec3f v_s;
    Vec3f* v;
    BashPlayerWork* tw;
    BashPlayerWork* w;
    f32 angle;

    w = PLAYER_WORK(obj);
    tw = target->unk_50;
    v = &v_s;
    angle = w->unk_3C;
    v->x = func_800AEAC0(angle) * 200.0f;
    v->y = 40.0f;
    v->z = func_800AEFD0(angle) * 200.0f;
    v->x += obj->trans.x;
    v->z += obj->trans.z;
    v->x -= target->trans.x + ofs->x;
    v->y -= target->trans.y + tw->unk_48 + ofs->y;
    v->z -= target->trans.z + ofs->z;
    return func_800A1200(v) < tw->unk_48 + 40.0f;
}

void func_800F7108_BashNCash(f32* a, f32* b) {
    f32 t = *a;

    *a = *b;
    *b = t;
}

/* Distance and direction from the cash player to each hammer player. */
void func_800F711C_BashNCash(f32* dist, f32* angle) {
    Vec3f v_s;
    Vec3f* v;
    omObjData* cash;
    omObjData* obj;
    u16 n;
    u16 i;

    cash = D_800FE690_BashNCash.obj;
    v = &v_s;
    n = 0;
    for (i = 0; i < D_800F2BC0; i++) {
        obj = D_800FE710_BashNCash[i].obj;
        if (obj == NULL) {
            continue;
        }
        v->x = obj->trans.x;
        v->y = 0.0f;
        v->z = obj->trans.z;
        v->x -= cash->trans.x;
        v->z -= cash->trans.z;
        dist[n] = func_800A1200(v);
        angle[n++] = func_80029518(func_800B0CD8(v->x, v->z));
    }
}

/* The middle of the widest gap between three sorted angles. */
// register allocation and scheduling (nmcmp: calls and stores equal)
// decomp-permuter
f32 func_800F7240_BashNCash(f32 *angle)
{
  f32 gap;
  f32 start;
  f32 new_var;
  gap = angle[1] - angle[0];
  start = angle[0];
  new_var = angle[1];
  if (gap < (angle[2] - new_var))
  {
    gap = angle[2] - new_var;
    start = new_var;
  }
  new_var = angle[0];
  if (gap < ((new_var + 360.0f) - angle[2]))
  {
    gap = (new_var + 360.0f) - angle[2];
    start = angle[2];
  }
  return start + (gap / 2.0f);
}

/* The nearest coin in flight within 400 units, or NULL. */
omObjData* func_800F72BC_BashNCash(omObjData* obj) {
    Vec3f v_s;
    Vec3f* v;
    omObjData* coin;
    f32 best;
    f32 d;
    s32 found;
    s32 i;

    v = &v_s;
    found = -1;
    best = 400.0f;
    for (i = 0; i < D_800EE984; i++) {
        coin = D_800EDE70[i];
        if (COIN_WORK(coin)->unk_54 != 0) {
            func_800A0D00(v, coin->trans.x, 0.0f, coin->trans.z);
            v->x -= obj->trans.x;
            v->y -= 0.0f;
            v->z -= obj->trans.z;
            d = func_800A1200(v);
            if (d < best) {
                best = d;
                found = i;
            }
        }
    }
    if (found == -1) {
        return NULL;
    }
    return D_800EDE70[found];
}

s32 func_800F73F0_BashNCash(u16 player) {
    omObjData* obj;
    BashPlayerWork* w;
    s32 stat;
    s32 ret;

    obj = D_800F3FB0[player];
    w = obj->unk_50;
    stat = func_80017A60(obj);
    ret = 0;
    if (w->unk_38 == 1000.0f) {
        ret = (stat & 6) != 0;
    }
    return ret;
}

/* CPU for the cash player (difficulty: easy). */
// register allocation and scheduling (nmcmp: calls and stores equal)
#ifdef NON_MATCHING
void func_800F7458_BashNCash(omObjData* obj) {
    f32 angle[3];
    f32 dist[3];
    f32 angle2[3];
    Vec3f v_s;
    Vec3f* v;
    BashPlayerWork* w;
    BashInput* in;
    omObjData* other;
    f32 dir;
    f32 len;
    f32 px;
    f32 a;
    f32 off;
    f32 lim;
    s8 target;
    u16 i;
    u16 n;
    u16 k;

    if (D_800ED430 == 1) {
        w = obj->unk_50;
        i = obj->work[0];
        in = &D_800FE6A8_BashNCash[i];
        v = &v_s;
        if (in->flags & 1) {
            in->stickY = 0;
            in->stickX = 0;
            ContBtn[GwPlayer[i].port] = 0;
            ContBtnTrg[GwPlayer[i].port] = 0;
            ContStkX[GwPlayer[i].port] = 0;
            ContStkY[GwPlayer[i].port] = 0;
            if (in->state == 0) {
                k = 0;
                for (n = 0; n < D_800F2BC0;) {
                    other = D_800FE710_BashNCash[n++].obj;
                    if (other != NULL) {
                        v->x = other->trans.x;
                        v->y = 0.0f;
                        v->z = other->trans.z;
                        angle[k++] = func_80029518(func_800B0CD8(v->x, v->z));
                    }
                }
                if (angle[1] < angle[0]) {
                    func_800F7108_BashNCash(&angle[0], &angle[1]);
                }
                if (angle[2] < angle[1]) {
                    func_800F7108_BashNCash(&angle[1], &angle[2]);
                }
                if (angle[1] < angle[0]) {
                    func_800F7108_BashNCash(&angle[0], &angle[1]);
                }
                dir = func_800F7240_BashNCash(angle);
                v->x = obj->trans.x;
                v->z = obj->trans.z;
                a = dir - func_80029518(func_800B0CD8(v->x, v->z));
                if (BASH_ABS(a) > 150.0f && BASH_ABS(angle[2] - angle[0]) < 150.0f) {
                    print8(8, 0x60, "TEST");
                    dir += 120.0f;
                }
                px = func_800AEAC0(dir) * 500.0f;
                v->x = px;
                v->y = 0.0f;
                v->z = func_800AEFD0(dir) * 500.0f;
                v->x -= obj->trans.x;
                v->z -= obj->trans.z;
                dir = func_800B0CD8(v->x, v->z);
                len = func_800A1200(v);
                target = w->unk_54;
                if (target != -1 && target != i) {
                    other = D_800FE710_BashNCash[target].obj;
                    v->x = px;
                    v->y = 0.0f;
                    v->z = px;
                    v->x -= other->trans.x;
                    v->z -= other->trans.z;
                    a = func_80029518(func_800B0CD8(v->x, v->z));
                    if (BASH_ABS(dir - a) > 180.0f) {
                        off = 90.0f;
                    } else {
                        off = -90.0f;
                    }
                    if (dir - a < 0.0f) {
                        off = -off;
                    }
                    dir += off;
                }
                func_800F711C_BashNCash(dist, angle2);
                lim = w->unk_48 + 240.0f;
                if (dist[0] < lim && dist[1] < lim && dist[2] < lim) {
                    dir = func_800F7240_BashNCash(angle2);
                    len = 100.0f;
                }
                if (len > 50.0f) {
                    in->stickX = func_800AEAC0(dir) * 60.0f;
                    in->stickY = func_800AEFD0(dir) * 60.0f;
                }
            }
            ContStkX[GwPlayer[i].port] = in->stickX;
            ContStkY[GwPlayer[i].port] = -in->stickY;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_BashNCash/137050", func_800F7458_BashNCash);
#endif

/* CPU for the cash player (difficulty: normal and hard). */
// register allocation and scheduling (nmcmp: calls and stores equal)
#ifdef NON_MATCHING
void func_800F7A54_BashNCash(omObjData* obj) {
    struct {
        u16 idx[4];
        f32 dist[4];
    } near;
    Vec3f v_s;
    Vec3f* v;
    u16 i;
    BashPlayerWork* w;
    BashInput* in;
    omObjData* other;
    f32 dir;
    f32 a;
    f32 b;
    f32 off;
    f32 center;
    u16 n;
    u16 j;
    u16 k;

    if (D_800ED430 == 1) {
        w = obj->unk_50;
        i = obj->work[0];
        in = &D_800FE6A8_BashNCash[i];
        v = &v_s;
        if (in->flags & 1) {
            in->stickY = 0;
            in->stickX = 0;
            ContBtn[GwPlayer[i].port] = 0;
            ContBtnTrg[GwPlayer[i].port] = 0;
            ContStkX[GwPlayer[i].port] = 0;
            ContStkY[GwPlayer[i].port] = 0;
            switch (in->state) {
            case 0:
                k = 0;
                n = 0;
                for (j = 0; j < D_800F2BC0; j++, k++) {
                    other = D_800FE710_BashNCash[j].obj;
                    if (other != NULL) {
                        func_800A0D00(v, other->trans.x, 0.0f, other->trans.z);
                        v->x -= obj->trans.x;
                        v->y -= 0.0f;
                        v->z -= obj->trans.z;
                        if ((near.dist[k] = func_800A1200(v)) < 400.0f) {
                            near.idx[n++] = j;
                        }
                    }
                }
                func_800A0D00(v, -obj->trans.x, 0.0f, -obj->trans.z);
                center = func_800A1200(v);
                switch (n) {
                case 1:
                    other = D_800FE710_BashNCash[near.idx[0]].obj;
                    func_800A0D00(v, other->trans.x, 0.0f, other->trans.z);
                    v->x -= obj->trans.x;
                    v->y -= 0.0f;
                    v->z -= obj->trans.z;
                    dir = func_80029518(func_800B0CD8(v->x, v->z) + 180.0f);
                    break;
                case 2:
                    other = D_800FE710_BashNCash[near.idx[0]].obj;
                    func_800A0D00(v, other->trans.x, 0.0f, other->trans.z);
                    v->x -= obj->trans.x;
                    v->y -= 0.0f;
                    v->z -= obj->trans.z;
                    a = func_80029518(func_800B0CD8(v->x, v->z));
                    other = D_800FE710_BashNCash[near.idx[1]].obj;
                    func_800A0D00(v, other->trans.x, 0.0f, other->trans.z);
                    v->x -= obj->trans.x;
                    v->y -= 0.0f;
                    v->z -= obj->trans.z;
                    b = func_80029518(func_800B0CD8(v->x, v->z));
                    if (b < a) {
                        dir = func_80029518(b + (a - b) / 2.0f);
                    } else {
                        dir = func_80029518(a + (b - a) / 2.0f);
                    }
                    if (BASH_ABS(a - b) < 180.0f) {
                        dir = func_80029518(dir + 180.0f);
                    }
                    break;
                case 3:
                    if (D_800FE690_BashNCash.unk_04 == 0) {
                        func_800A0D00(v, -obj->trans.x, 0.0f, -obj->trans.z);
                        dir = func_80029518(func_800B0CD8(v->x, v->z));
                        D_800FE540_BashNCash = dir;
                        in->trg |= 0x8000;
                        in->btn |= 0x8000;
                        in->timer = 10;
                        in->state = 2;
                        break;
                    }
                default:
                    dir = w->unk_3C;
                    break;
                }
                if (center > 400.0f && !(in->trg & 0x8000)) {
                    a = func_80029518(dir - 180.0f);
                    func_800A0D00(v, -obj->trans.x, 0.0f, -obj->trans.z);
                    b = func_80029518(func_800B0CD8(v->x, v->z));
                    if (BASH_ABS(a - b) > 180.0f) {
                        off = -45.0f;
                    } else {
                        off = 45.0f;
                    }
                    if (a - b < 0.0f) {
                        off = -off;
                    }
                    dir += off;
                }
                in->stickX = func_800AEAC0(dir) * 60.0f;
                in->stickY = func_800AEFD0(dir) * 60.0f;
                break;
            case 2:
                if (w->unk_38 == 1000.0f) {
                    in->state = 0;
                }
                in->stickX = func_800AEAC0(D_800FE540_BashNCash) * 60.0f;
                in->stickY = func_800AEFD0(D_800FE540_BashNCash) * 60.0f;
                in->trg = 0;
                if (in->timer == 0) {
                    in->btn = 0;
                } else {
                    in->timer--;
                }
                break;
            }
            ContBtn[GwPlayer[i].port] = in->btn;
            ContBtnTrg[GwPlayer[i].port] = in->trg;
            ContStkX[GwPlayer[i].port] = in->stickX;
            ContStkY[GwPlayer[i].port] = -in->stickY;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_BashNCash/137050", func_800F7A54_BashNCash);
#endif

/* CPU for a hammer player (easy). */
void func_800F8240_BashNCash(omObjData* obj) {
    Vec3f v_s;
    Vec3f* v;
    BashPlayerWork* w;
    u16 i;
    omObjData* cash;
    u16 cashIdx;
    BashInput* in;
    omObjData* other;
    f32 dir;
    f32 d;
    f32 a;
    f32 off;
    s8 target;

    if (D_800ED430 == 1) {
        w = obj->unk_50;
        i = obj->work[0];
        cash = D_800FE690_BashNCash.obj;
        cashIdx = cash->work[0];
        in = &D_800FE6A8_BashNCash[i];
        v = &v_s;
        if (in->flags & 1) {
            in->btn = 0;
            in->trg = 0;
            ContBtn[GwPlayer[i].port] = 0;
            ContBtnTrg[GwPlayer[i].port] = 0;
            ContStkX[GwPlayer[i].port] = 0;
            ContStkY[GwPlayer[i].port] = 0;
            switch (in->state) {
            case 0:
                v->x = cash->trans.x;
                v->y = 0.0f;
                v->z = cash->trans.z;
                v->x -= obj->trans.x;
                v->z -= obj->trans.z;
                d = func_800A1200(v);
                if ((d < 240.0f) & (d > 160.0f)) {
                    dir = func_800B0CD8(v->x, v->z);
                    in->stickX = func_800AEAC0(dir) * 60.0f * 0.3f;
                    in->stickY = func_800AEFD0(dir) * 60.0f * 0.3f;
                    in->state = 1;
                } else {
                    in->state = 2;
                }
                break;
            case 1:
                v->x = 0.0f;
                v->y = 0.0f;
                v->z = 0.0f;
                if (func_800F6FD0_BashNCash(obj, cash, v)) {
                    in->stickY = 0;
                    in->stickX = 0;
                    in->trg |= 0x8000;
                }
                in->state = 0;
                break;
            case 2:
                v->x = cash->trans.x;
                v->y = 0.0f;
                v->z = cash->trans.z;
                v->x -= obj->trans.x;
                v->z -= obj->trans.z;
                dir = func_80029518(func_800B0CD8(v->x, v->z));
                d = func_800A1200(v);
                target = w->unk_54;
                if (target != -1 && target != cashIdx) {
                    other = D_800FE710_BashNCash[target].obj;
                    v->x = cash->trans.x;
                    v->y = 0.0f;
                    v->z = cash->trans.z;
                    v->x -= other->trans.x;
                    v->z -= other->trans.z;
                    a = func_80029518(func_800B0CD8(v->x, v->z));
                    if (BASH_ABS(dir - a) > 180.0f) {
                        off = 90.0f;
                    } else {
                        off = -90.0f;
                    }
                    if (dir - a < 0.0f) {
                        off = -off;
                    }
                    dir += off;
                }
                if (d < 240.0f) {
                    dir += 180.0f;
                }
                in->stickX = func_800AEAC0(dir) * 60.0f;
                in->stickY = func_800AEFD0(dir) * 60.0f;
                in->state = 0;
                break;
            }
            ContBtn[GwPlayer[i].port] = in->btn;
            ContBtnTrg[GwPlayer[i].port] = in->trg;
            ContStkX[GwPlayer[i].port] = in->stickX;
            ContStkY[GwPlayer[i].port] = -in->stickY;
        }
    }
}

/* CPU for a hammer player (normal). */
// register allocation and scheduling (nmcmp: calls and stores equal)
#ifdef NON_MATCHING
void func_800F875C_BashNCash(omObjData* obj) {
    f32 angle[2];
    Vec3f v_s;
    Vec3f* v;
    u16 cashIdx;
    BashPlayerWork* w;
    u16 i;
    omObjData* cash;
    BashInput* in;
    omObjData* other;
    f32 dir;
    f32 d;
    f32 a;
    f32 off;
    s8 target;
    u16 n;
    u16 k;

    if (D_800ED430 == 1) {
        w = obj->unk_50;
        i = obj->work[0];
        cash = D_800FE690_BashNCash.obj;
        cashIdx = cash->work[0];
        in = &D_800FE6A8_BashNCash[i];
        v = &v_s;
        if (in->flags & 1) {
            in->btn = 0;
            in->trg = 0;
            ContBtn[GwPlayer[i].port] = 0;
            ContBtnTrg[GwPlayer[i].port] = 0;
            ContStkX[GwPlayer[i].port] = 0;
            ContStkY[GwPlayer[i].port] = 0;
            switch (in->state) {
            case 0:
                if (func_800F72BC_BashNCash(obj) != NULL) {
                    in->state = 3;
                } else {
                    v->x = cash->trans.x;
                    v->y = 0.0f;
                    v->z = cash->trans.z;
                    v->x -= obj->trans.x;
                    v->z -= obj->trans.z;
                    d = func_800A1200(v);
                    if ((d < 240.0f) & (d > 160.0f)) {
                        dir = func_800B0CD8(v->x, v->z);
                        in->stickX = func_800AEAC0(dir) * 60.0f * 0.3f;
                        in->stickY = func_800AEFD0(dir) * 60.0f * 0.3f;
                        in->state = 1;
                    } else {
                        in->state = 2;
                    }
                }
                break;
            case 1:
                v->x = 0.0f;
                v->y = 0.0f;
                v->z = 0.0f;
                if (func_800F6FD0_BashNCash(obj, cash, v)) {
                    in->stickY = 0;
                    in->stickX = 0;
                    in->trg |= 0x8000;
                }
                in->state = 0;
                break;
            case 2:
                k = 0;
                for (n = 0; n < D_800F2BC0;) {
                    other = D_800FE710_BashNCash[n].obj;
                    if (other == NULL) {
                        n++;
                    } else {
                        n++;
                        if (other->work[0] != i) {
                            v->x = other->trans.x;
                            v->y = 0.0f;
                            v->z = other->trans.z;
                            v->x -= cash->trans.x;
                            v->z -= cash->trans.z;
                            angle[k++] = func_80029518(func_800B0CD8(v->x, v->z));
                        }
                    }
                }
                a = func_80029518(angle[1] - angle[0]);
                dir = a / 2.0f + angle[0];
                if (a < 180.0f) {
                    dir += 180.0f;
                }
                v->x = func_800AEAC0(dir) * 200.0f + cash->trans.x;
                v->y = 0.0f;
                v->z = func_800AEFD0(dir) * 200.0f + cash->trans.z;
                v->x -= obj->trans.x;
                v->z -= obj->trans.z;
                dir = func_80029518(func_800B0CD8(v->x, v->z));
                target = w->unk_54;
                if (target != -1 && target != cashIdx) {
                    other = D_800FE710_BashNCash[target].obj;
                    v->x = cash->trans.x;
                    v->y = 0.0f;
                    v->z = cash->trans.z;
                    v->x -= other->trans.x;
                    v->z -= other->trans.z;
                    a = func_80029518(func_800B0CD8(v->x, v->z));
                    if (BASH_ABS(dir - a) > 180.0f) {
                        off = 90.0f;
                    } else {
                        off = -90.0f;
                    }
                    if (dir - a < 0.0f) {
                        off = -off;
                    }
                    dir += off;
                }
                v->x = cash->trans.x;
                v->y = 0.0f;
                v->z = cash->trans.z;
                v->x -= obj->trans.x;
                v->z -= obj->trans.z;
                if (func_800A1200(v) < 240.0f) {
                    dir += 180.0f;
                }
                in->stickX = func_800AEAC0(dir) * 60.0f;
                in->stickY = func_800AEFD0(dir) * 60.0f;
                in->state = 0;
                break;
            case 3:
                other = func_800F72BC_BashNCash(obj);
                if (other == NULL) {
                    in->state = 0;
                } else {
                    v->x = other->trans.x;
                    v->y = 0.0f;
                    v->z = other->trans.z;
                    v->x -= obj->trans.x;
                    v->z -= obj->trans.z;
                    dir = func_80029518(func_800B0CD8(v->x, v->z));
                    target = w->unk_54;
                    if (target != -1) {
                        omObjData* t = D_800F3FB0[target];
                        v->x = other->trans.x;
                        v->y = 0.0f;
                        v->z = other->trans.z;
                        v->x -= t->trans.x;
                        v->z -= t->trans.z;
                        a = func_80029518(func_800B0CD8(v->x, v->z));
                        if (BASH_ABS(dir - a) > 180.0f) {
                            off = 90.0f;
                        } else {
                            off = -90.0f;
                        }
                        if (dir - a < 0.0f) {
                            off = -off;
                        }
                        dir += off;
                    }
                    in->stickX = func_800AEAC0(dir) * 60.0f;
                    in->stickY = func_800AEFD0(dir) * 60.0f;
                }
                break;
            }
            ContBtn[GwPlayer[i].port] = in->btn;
            ContBtnTrg[GwPlayer[i].port] = in->trg;
            ContStkX[GwPlayer[i].port] = in->stickX;
            ContStkY[GwPlayer[i].port] = -in->stickY;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_BashNCash/137050", func_800F875C_BashNCash);
#endif

/* CPU for a hammer player (hard). */
// register allocation and scheduling (nmcmp: calls and stores equal)
#ifdef NON_MATCHING
void func_800F8FD4_BashNCash(omObjData* obj) {
    f32 angle[2];
    Vec3f v_s;
    Vec3f* v;
    u16 i;
    BashPlayerWork* w;
    u16 cashIdx;
    omObjData* cash;
    BashPlayerWork* cw;
    BashInput* in;
    omObjData* other;
    f32 dir;
    f32 d;
    f32 a;
    f32 off;
    f32 reach;
    s8 target;
    u16 n;
    u16 k;

    if (D_800ED430 == 1) {
        w = obj->unk_50;
        i = obj->work[0];
        cash = D_800FE690_BashNCash.obj;
        cw = cash->unk_50;
        cashIdx = cash->work[0];
        in = &D_800FE6A8_BashNCash[i];
        v = &v_s;
        if (in->flags & 1) {
            in->btn = 0;
            in->trg = 0;
            ContBtn[GwPlayer[i].port] = 0;
            ContBtnTrg[GwPlayer[i].port] = 0;
            ContStkX[GwPlayer[i].port] = 0;
            ContStkY[GwPlayer[i].port] = 0;
            switch (in->state) {
            case 0:
                if (func_800F72BC_BashNCash(obj) != NULL) {
                    in->state = 3;
                } else {
                    v->x = cash->trans.x;
                    v->y = 0.0f;
                    v->z = cash->trans.z;
                    v->x -= obj->trans.x;
                    v->z -= obj->trans.z;
                    d = func_800A1200(v);
                    if ((d < 240.0f) & (d > 160.0f)) {
                        in->state = 1;
                    } else {
                        in->state = 2;
                    }
                }
                break;
            case 1:
                reach = cw->unk_40 * 12.0f;
                v->x = func_800AEAC0(cw->unk_3C) * reach + cash->trans.x;
                v->y = 0.0f;
                v->z = func_800AEFD0(cw->unk_3C) * reach + cash->trans.z;
                v->x -= obj->trans.x;
                v->z -= obj->trans.z;
                d = func_800A1200(v);
                dir = func_800B0CD8(v->x, v->z);
                if (d < 160.0f) {
                    dir += 180.0f;
                }
                func_800A0D00(v, cash->trans.x, 0.0f, cash->trans.x); /* retail passes x as z */
                v->x -= obj->trans.x;
                v->y -= 0.0f;
                v->z -= obj->trans.z;
                if (func_800A1200(v) < cw->unk_48 + w->unk_48) {
                    dir = func_80029518(func_800B0CD8(v->x, v->z) + 180.0f);
                }
                in->stickX = func_800AEAC0(dir) * 60.0f;
                in->stickY = func_800AEFD0(dir) * 60.0f;
                if (D_800FE690_BashNCash.unk_06 != 0) {
                    in->stickY = 0;
                    in->stickX = 0;
                    in->state = 0;
                } else {
                    v->x = func_800AEAC0(cw->unk_3C) * reach;
                    v->y = 0.0f;
                    v->z = func_800AEFD0(cw->unk_3C) * reach;
                    if (func_800F6FD0_BashNCash(obj, cash, v)) {
                        in->stickY = 0;
                        in->stickX = 0;
                        in->trg |= 0x8000;
                        in->state = 0;
                    }
                }
                break;
            case 2:
                k = 0;
                for (n = 0; n < D_800F2BC0;) {
                    other = D_800FE710_BashNCash[n].obj;
                    if (other == NULL) {
                        n++;
                    } else {
                        n++;
                        if (other->work[0] != i) {
                            v->x = other->trans.x;
                            v->y = 0.0f;
                            v->z = other->trans.z;
                            v->x -= cash->trans.x;
                            v->z -= cash->trans.z;
                            angle[k++] = func_80029518(func_800B0CD8(v->x, v->z));
                        }
                    }
                }
                a = func_80029518(angle[1] - angle[0]);
                dir = a / 2.0f + angle[0];
                if (a < 180.0f) {
                    dir += 180.0f;
                }
                v->x = func_800AEAC0(dir) * 200.0f + cash->trans.x;
                v->y = 0.0f;
                v->z = func_800AEFD0(dir) * 200.0f + cash->trans.z;
                v->x -= obj->trans.x;
                v->z -= obj->trans.z;
                dir = func_80029518(func_800B0CD8(v->x, v->z));
                target = w->unk_54;
                if (target != -1 && target != cashIdx) {
                    other = D_800FE710_BashNCash[target].obj;
                    v->x = cash->trans.x;
                    v->y = 0.0f;
                    v->z = cash->trans.z;
                    v->x -= other->trans.x;
                    v->z -= other->trans.z;
                    a = func_80029518(func_800B0CD8(v->x, v->z));
                    if (BASH_ABS(dir - a) > 180.0f) {
                        off = 90.0f;
                    } else {
                        off = -90.0f;
                    }
                    if (dir - a < 0.0f) {
                        off = -off;
                    }
                    dir += off;
                }
                v->x = cash->trans.x;
                v->y = 0.0f;
                v->z = cash->trans.z;
                v->x -= obj->trans.x;
                v->z -= obj->trans.z;
                if (func_800A1200(v) < 240.0f) {
                    dir += 180.0f;
                }
                in->stickX = func_800AEAC0(dir) * 60.0f;
                in->stickY = func_800AEFD0(dir) * 60.0f;
                in->state = 0;
                break;
            case 3:
                other = func_800F72BC_BashNCash(obj);
                if (other == NULL) {
                    in->state = 0;
                } else {
                    v->x = other->trans.x;
                    v->y = 0.0f;
                    v->z = other->trans.z;
                    v->x -= obj->trans.x;
                    v->z -= obj->trans.z;
                    dir = func_80029518(func_800B0CD8(v->x, v->z));
                    target = w->unk_54;
                    if (target != -1) {
                        omObjData* t = D_800F3FB0[target];
                        v->x = other->trans.x;
                        v->y = 0.0f;
                        v->z = other->trans.z;
                        v->x -= t->trans.x;
                        v->z -= t->trans.z;
                        a = func_80029518(func_800B0CD8(v->x, v->z));
                        if (BASH_ABS(dir - a) > 180.0f) {
                            off = 90.0f;
                        } else {
                            off = -90.0f;
                        }
                        if (dir - a < 0.0f) {
                            off = -off;
                        }
                        dir += off;
                    }
                    in->stickX = func_800AEAC0(dir) * 60.0f;
                    in->stickY = func_800AEFD0(dir) * 60.0f;
                }
                break;
            }
            ContBtn[GwPlayer[i].port] = in->btn;
            ContBtnTrg[GwPlayer[i].port] = in->trg;
            ContStkX[GwPlayer[i].port] = in->stickX;
            ContStkY[GwPlayer[i].port] = -in->stickY;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_BashNCash/137050", func_800F8FD4_BashNCash);
#endif

/* Launches a free coin of the given value from the cash player towards the hitter. */
u16 func_800F99A8_BashNCash(omObjData* cash, omObjData* hitter, s32 type) {
    Vec3f v;
    omObjData* coin;
    BashCoinWork* cw;
    BashCoinSlot* slot;
    s32 i;

    if (D_800ED430 != 1) {
        return 0;
    }
    for (i = 0; i < D_800EE984; i++) {
        coin = D_800EDE70[i];
        cw = coin->unk_50;
        if (cw->unk_54 == 0 && type == cw->unk_52) {
            break;
        }
    }
    if (i >= D_800EE984) {
        return 0;
    }
    slot = &D_800FE630_BashNCash[coin->work[0]];
    coin->trans.x = cash->trans.x;
    coin->trans.y = cash->trans.y + 200.0f;
    coin->trans.z = cash->trans.z;
    func_80025798(coin->model[0], hitter->trans.x, hitter->trans.y, hitter->trans.z);
    func_80025798(coin->model[1], hitter->trans.x, 0.0f, hitter->trans.z);
    v.x = hitter->trans.x;
    v.z = hitter->trans.z;
    v.x -= cash->trans.x;
    v.z -= cash->trans.z;
    cw->unk_3C = func_800B0CD8(v.x, v.z);
    if (_CheckFlag(0x45) != 0) {
        func_80060618(0x45F, PLAYER_WORK(cash)->unk_58);
        cw->unk_40 = 0.0f;
        cw->unk_38 = -1.1f;
    } else {
        cw->unk_40 = 17.5f;
        cw->unk_38 = -1.7f;
    }
    cw->unk_54 = 1;
    slot->timer = 150;
    func_800258EC(coin->model[0], 4, 0);
    func_800258EC(coin->model[1], 4, 0);
    return 1;
}

// register allocation and scheduling (nmcmp: calls and stores equal)
// decomp-permuter
s32 func_800F9BAC_BashNCash(void)
{
  s32 new_var;
  new_var = D_800FE610_BashNCash;
  return D_800FE698_BashNCash + GwPlayer[new_var].coins_mg;
}

/* The cash player was hit: knock out a 5-coin (or 1-coin) piece. */
// register allocation and scheduling (nmcmp: calls and stores equal)
#ifdef NON_MATCHING
void func_800F9BDC_BashNCash(omObjData* cash, omObjData* hitter) {
    BashPlayerWork* w;
    s32 coins;

    w = D_800F3FB0[cash->work[0]]->unk_50;
    coins = func_800F9BAC_BashNCash();
    if (coins == 0) {
        return;
    }
    if (coins >= 5) {
        if (func_800F99A8_BashNCash(cash, hitter, 6)) {
            if (D_800FE690_BashNCash.coins >= 5) {
                D_800FE690_BashNCash.coins -= 5;
            } else {
                s32 rest = 5 - D_800FE690_BashNCash.coins;

                D_800FE690_BashNCash.coins = 0;
                GwPlayer[w->unk_58].coins_mg -= rest;
            }
            if (coins == 5) {
                D_800FE628_BashNCash = 1;
            }
        }
    } else if (func_800F99A8_BashNCash(cash, hitter, 3)) {
        if (D_800FE690_BashNCash.coins != 0) {
            D_800FE690_BashNCash.coins--;
        } else {
            GwPlayer[w->unk_58].coins_mg--;
        }
        if (coins - 1 == 0) {
            D_800FE628_BashNCash = 1;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_BashNCash/137050", func_800F9BDC_BashNCash);
#endif

void func_800F9D60_BashNCash(omObjData* obj) {
    BashPlayerWork* w = obj->unk_50;

    func_80060F04(w->unk_58, 0x14, 0, 0x14);
    func_80017C0C(obj, 7, obj->trans.x, obj->trans.y, obj->trans.z, 0.0f, 0.0f);
    func_80060540(0x24E, w->unk_58);
}

/* A hammer player's swing: moves it and checks for a hit on the cash player. */
// register allocation; retail keeps 0.0f in $f20 (stores swc1, not sw zero)
#ifdef NON_MATCHING
void func_800F9DD0_BashNCash(omObjData* obj) {
    Vec3f v_s;
    Vec3f* v = &v_s;
    omObjData* cash;
    BashPlayerWork* w;

    if (func_80017A60(obj) == 0 && obj->work[1] != 0) {
        cash = D_800FE690_BashNCash.obj;
        w = obj->unk_50;
        D_800F5254 = 0.0f;
        D_800ED6B8 = 0.0f;
        func_80002C48(obj, w->unk_3C, obj->trans.x, obj->trans.y, obj->trans.z);
        obj->trans.x = func_800AEAC0(w->unk_3C) * w->unk_40 + D_800ED6B8 + obj->trans.x;
        obj->trans.z = func_800AEFD0(w->unk_3C) * w->unk_40 + D_800F5254 + obj->trans.z;
        D_800FE710_BashNCash[obj->work[0]].unk_04++;
        if (D_800FE710_BashNCash[obj->work[0]].unk_04 >= 12 && D_800FE710_BashNCash[obj->work[0]].unk_04 < 23 &&
            D_800FE690_BashNCash.unk_06 == 0) {
            v->x = 0.0f;
            v->y = 0.0f;
            v->z = 0.0f;
            if (func_800F6FD0_BashNCash(obj, cash, v)) {
                cash->work[1] = 1;
                func_80018450(cash, 2);
                func_800F9BDC_BashNCash(cash, obj);
                D_800FE690_BashNCash.unk_06 = 60;
                func_800F9D60_BashNCash(cash);
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_BashNCash/137050", func_800F9DD0_BashNCash);
#endif

/* Whether the round is over: no coin in flight and no coins left. */
s32 func_800F9F64_BashNCash(void) {
    s32 i;

    for (i = 0; i < D_800EE984; i++) {
        if (COIN_WORK(D_800EDE70[i])->unk_54 != 0) {
            return 0;
        }
    }
    return func_800F9BAC_BashNCash() == 0;
}

/* Puts a coin away (shows its sparkle at pos). */
void func_800F9FD0_BashNCash(omObjData* obj, Vec3f* pos) {
    BashCoinWork* w = obj->unk_50;

    if (w->unk_54 != 0) {
        func_800258EC(obj->model[3], 4, 0);
        func_8001E2A8(w->unk_24, 0);
        func_8001E268(w->unk_24, 4, 4);
        func_80025798(obj->model[3], pos->x, pos->y, pos->z);
        func_80025830(obj->model[3], 10.0f, 10.0f, 10.0f);
        w->unk_54 = 0;
        func_800090D8(obj, 0, 0);
        func_800090D8(obj, 1, 0);
    }
}

void func_800FA094_BashNCash(void) {
    Vec3f pos_s;
    Vec3f* pos = &pos_s;
    omObjData* obj;
    s32 i;

    for (i = 0; i < D_800EE984; i++) {
        obj = D_800EDE70[i];
        pos->x = obj->trans.x;
        pos->y = obj->trans.y;
        pos->z = obj->trans.z;
        func_800F9FD0_BashNCash(obj, pos);
    }
}

/* A stunned hammer player spins. */
// register allocation and scheduling (nmcmp: calls and stores equal)
#ifdef NON_MATCHING
void func_800FA120_BashNCash(omObjData* obj) {
    BashPlayerWork* w = obj->unk_50;
    BashInput* in;

    if (D_800FE710_BashNCash[obj->work[0]].unk_0A >= 46) {
        D_800FE710_BashNCash[obj->work[0]].unk_10 &= ~1;
        return;
    }
    w->unk_3C += 16.0f;
    D_800FE710_BashNCash[obj->work[0]].unk_0A++;
    in = &D_800FE6A8_BashNCash[obj->work[0]];
    in->stickX = 0;
    in->stickY = 0;
    in->btn = 0;
    in->trg = 0;
    ContBtn[GwPlayer[obj->work[0]].port] = in->btn;
    ContBtnTrg[GwPlayer[obj->work[0]].port] = in->trg;
    ContStkX[GwPlayer[obj->work[0]].port] = in->stickX;
    ContStkY[GwPlayer[obj->work[0]].port] = -in->stickY;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_BashNCash/137050", func_800FA120_BashNCash);
#endif

/* A thrown hammer flies and falls. */
void func_800FA26C_BashNCash(omObjData* obj) {
    u8 i = obj->work[0];
    omObjData* player;
    BashPlayerWork* w;

    obj->trans.y += D_800FE5B0_BashNCash[i];
    D_800FE5B0_BashNCash[i] -= 5.0f;
    if (obj->trans.y < 0.0f) {
        obj->trans.y = 0.0f;
        player = D_800FE600_BashNCash[i];
        w = player->unk_50;
        func_800258EC(player->model[0xB], 4, 0);
        func_8001E2A8(w->unk_2C, 0);
        func_8001E268(w->unk_2C, 4, 4);
        func_80025798(D_800FE600_BashNCash[i]->model[0xB], obj->trans.x, obj->trans.y, obj->trans.z);
        func_80025830(D_800FE600_BashNCash[i]->model[0xB], 5.0f, 5.0f, 5.0f);
        func_800258EC(D_800FE600_BashNCash[i]->model[0xA], 4, 4);
        obj->func_ptr = NULL;
    }
    obj->trans.x = func_800AEAC0(D_800FE5BC_BashNCash[i]) * 10.0f + obj->trans.x;
    obj->trans.z = func_800AEFD0(D_800FE5BC_BashNCash[i]) * 10.0f + obj->trans.z;
    func_80025798((s16)D_800FE618_BashNCash[i], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800257E4((s16)D_800FE618_BashNCash[i], obj->rot.x, obj->rot.y, obj->rot.z);
    obj->rot.x += 60.0f;
}

void func_800FA440_BashNCash(omObjData* obj) {
    Vec3f v;
    s32 i;
    f32 angle;

    obj->trans.x = D_800F2B7C[D_800FE618_BashNCash[D_800FE3A0_BashNCash]].unk_24;
    obj->trans.y = D_800F2B7C[D_800FE618_BashNCash[D_800FE3A0_BashNCash]].unk_28;
    obj->trans.z = D_800F2B7C[D_800FE618_BashNCash[D_800FE3A0_BashNCash]].unk_2C;
    obj->rot.x = D_800F2B7C[D_800FE618_BashNCash[D_800FE3A0_BashNCash]].unk_30;
    obj->rot.y = D_800F2B7C[D_800FE618_BashNCash[D_800FE3A0_BashNCash]].unk_34;
    obj->rot.z = D_800F2B7C[D_800FE618_BashNCash[D_800FE3A0_BashNCash]].unk_38;
    func_800A0D00(&v, -obj->trans.x, 0.0f, -obj->trans.z);
    angle = func_800B0CD8(v.x, v.z);
    i = D_800FE3A0_BashNCash;
    D_800FE5BC_BashNCash[i] = angle + 20.0f;
    D_800FE5B0_BashNCash[i] = 30.0f;
    D_800FE3A0_BashNCash = i + 1;
    obj->work[0] = i;
    obj->func_ptr = func_800FA26C_BashNCash;
}

/* A hammer player's object. */
// register allocation and scheduling (nmcmp: calls and stores equal)
#ifdef NON_MATCHING
void func_800FA5B4_BashNCash(omObjData* obj) {
    void (*cpu[3])(omObjData*) = { func_800F8FD4_BashNCash, func_800F875C_BashNCash, func_800F8240_BashNCash };
    BashPlayerWork* w;
    u8 i;
    BashPlayer* pl;
    BashInput* in;
    s32 anim;

    w = obj->unk_50;
    i = obj->work[0];
    pl = &D_800FE710_BashNCash[i];
    in = &D_800FE6A8_BashNCash[i];
    in->saveBtn = ContBtn[GwPlayer[i].port];
    in->saveTrg = ContBtnTrg[GwPlayer[i].port];
    in->saveStkX = ContStkX[GwPlayer[i].port];
    in->saveStkY = ContStkY[GwPlayer[i].port];
    func_800FD748_BashNCash(i, GwPlayer[i].coins + GwPlayer[i].coins_mg);
    cpu[pl->cpu](obj);
    if (func_80017A60(obj) != 0 && obj->work[1] != 0) {
        obj->work[1] = 0;
        func_80028498(obj->model[0], D_800F2B7C[obj->motion[0x23]].unk_08, 1);
        func_800184BC(obj, 0);
    }
    func_800F9DD0_BashNCash(obj);
    if (D_800FE62A_BashNCash == 0) {
        if (D_800ED430 == 1) {
            if (pl->unk_06 != 0) {
                pl->unk_06--;
            }
            if (pl->unk_08 != 0) {
                pl->unk_08--;
                if (pl->unk_08 == 0) {
                    func_80060540(0x24D, w->unk_58);
                }
            }
            if ((ContBtnTrg[GwPlayer[i].port] & 0x8000) && pl->unk_06 == 0 && func_800184BC(obj, 0x24) == 1) {
                obj->work[1] = 1;
                pl->unk_04 = 0;
                pl->unk_06 = 0;
                pl->unk_08 = 15;
                w->unk_40 = 0.0f;
                func_800284E4(obj->model[0]);
            }
        }
    } else {
        ContBtn[GwPlayer[i].port] = 0;
        ContBtnTrg[GwPlayer[i].port] = 0;
        ContStkX[GwPlayer[i].port] = 0;
        ContStkY[GwPlayer[i].port] = 0;
        if (D_800FE62C_BashNCash != 0) {
            D_800FE62C_BashNCash--;
            func_800284E4(obj->model[0]);
            func_800258EC(obj->model[0xA], 0x4000, 0);
            omAddObj(7, 0, 0, -1, func_800FA440_BashNCash);
            func_80025798(obj->model[0xA], obj->trans.x, obj->trans.y + 100.0f, obj->trans.z);
            func_800257E4(obj->model[0xA], obj->rot.x, w->unk_3C, obj->rot.z);
            if (_CheckFlag(0x2B) == 0) {
                w->unk_3C = 0.0f;
                func_8009ECB0(D_800F2B7C[obj->model[0]].unk7C, w->unk_3C, w->unk_3C, w->unk_3C);
                if (_CheckFlag(0x45) != 0) {
                    if (GwPlayer[PLAYER_WORK(D_800F3FB0[D_800FE610_BashNCash])->unk_58].coins_mg < 0) {
                        anim = 0xD;
                    } else {
                        anim = 0xE;
                    }
                } else {
                    if (GwPlayer[i].coins_mg != 0) {
                        anim = 0xD;
                    } else {
                        anim = 0xE;
                    }
                }
                func_800184BC(obj, anim);
            }
        }
    }
    func_80005A28(obj);
    ContBtn[GwPlayer[i].port] = in->saveBtn;
    ContBtnTrg[GwPlayer[i].port] = in->saveTrg;
    ContStkX[GwPlayer[i].port] = in->saveStkX;
    ContStkY[GwPlayer[i].port] = in->saveStkY;
}
#else
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_10_BashNCash/137050", D_800FE458_BashNCash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_BashNCash/137050", func_800FA5B4_BashNCash);
#endif

/* The cash player's object. */
// register allocation and scheduling (nmcmp: calls and stores equal)
#ifdef NON_MATCHING
void func_800FAAE4_BashNCash(omObjData* obj) {
    void (*cpu[2])(omObjData*);
    Vec3f v_s;
    Vec3f* v = &v_s;
    u8 i;
    BashPlayerWork* w;
    BashInput* in;
    omObjData* other;
    f32 dir;
    s32 q;
    s32 j;
    s32 found;

    cpu[0] = func_800F7A54_BashNCash;
    cpu[1] = func_800F7458_BashNCash;
    i = obj->work[0];
    w = obj->unk_50;
    in = &D_800FE6A8_BashNCash[i];
    in->saveBtn = ContBtn[GwPlayer[i].port];
    in->saveTrg = ContBtnTrg[GwPlayer[i].port];
    in->saveStkX = ContStkX[GwPlayer[i].port];
    in->saveStkY = ContStkY[GwPlayer[i].port];
    func_800FD748_BashNCash(i, D_800FE690_BashNCash.coins + GwPlayer[i].coins_mg);
    if (w->unk_9C >= 61 && obj->work[3] == 0) {
        obj->work[3] = 1;
        func_80060540(0x24F, w->unk_58);
    }
    if (!(w->unk_50 & 3)) {
        obj->work[3] = 0;
    }
    if (D_800FE690_BashNCash.unk_06 != 0) {
        D_800FE690_BashNCash.unk_06--;
    }
    cpu[0](obj);
    if (D_800FE690_BashNCash.unk_04 != 0) {
        if ((u8)func_800F73F0_BashNCash(i)) {
            D_800FE690_BashNCash.unk_04--;
        }
        ContBtnTrg[GwPlayer[obj->work[0]].port] &= 0x7FFF;
    }
    if ((ContBtnTrg[GwPlayer[obj->work[0]].port] & 0x8000) && D_800FE690_BashNCash.unk_04 == 0 && !(w->unk_50 & 6)) {
        D_800FE690_BashNCash.unk_04 = 30;
    }
    func_80025830(obj->model[1], 1.0f, 1.0f, 1.0f);
    if (D_800FE62A_BashNCash != 0) {
        ContBtn[GwPlayer[i].port] = 0;
        ContBtnTrg[GwPlayer[i].port] = 0;
        ContStkX[GwPlayer[i].port] = 0;
        ContStkY[GwPlayer[i].port] = 0;
        if (!(u8)func_800F73F0_BashNCash(i)) {
            for (q = 0; q < 4; q++) {
                for (j = 0; j < 4; j++) {
                    if (D_800FE610_BashNCash != j) {
                        other = D_800F3FB0[j];
                        found = 0;
                        switch (q) {
                        case 0:
                            if (other->trans.x >= 0.0f && other->trans.z >= 0.0f) {
                                found = 1;
                            }
                            break;
                        case 1:
                            if (other->trans.x < 0.0f && other->trans.z >= 0.0f) {
                                found = 1;
                            }
                            break;
                        case 2:
                            if (other->trans.x >= 0.0f && other->trans.z < 0.0f) {
                                found = 1;
                            }
                            break;
                        case 3:
                            if (other->trans.x < 0.0f && other->trans.z < 0.0f) {
                                found = 1;
                            }
                            break;
                        }
                        if (found) {
                            break;
                        }
                    }
                }
                if (j >= 4) {
                    break;
                }
            }
            if (q >= 4) {
                q = 0;
            }
            func_800A0D00(v, D_800FE3A4_BashNCash[q][0], 0.0f, D_800FE3A4_BashNCash[q][1]);
            v->x -= obj->trans.x;
            v->y -= 0.0f;
            v->z -= obj->trans.z;
            dir = func_80029518(func_800B0CD8(v->x, v->z));
            ContStkX[GwPlayer[i].port] = func_800AEAC0(dir) * 60.0f;
            ContStkY[GwPlayer[i].port] = -(func_800AEFD0(dir) * 60.0f);
        }
    }
    func_80005A28(obj);
    ContBtn[GwPlayer[i].port] = in->saveBtn;
    ContBtnTrg[GwPlayer[i].port] = in->saveTrg;
    ContStkX[GwPlayer[i].port] = in->saveStkX;
    ContStkY[GwPlayer[i].port] = in->saveStkY;
    func_80025830(obj->model[1], 2.0f * D_800F2B7C[obj->model[1]].unk_3C, 1.0f,
                  2.0f * D_800F2B7C[obj->model[1]].unk_3C);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_BashNCash/137050", func_800FAAE4_BashNCash);
#endif

/* Camera shake. */
void func_800FB0D8_BashNCash(omObjData* obj) {
    f32 d;

    d = func_800AEAC0(obj->work[0]) * obj->work[1];
    D_800FE570_BashNCash.x = d + D_800FE594_BashNCash.x;
    D_800FE57C_BashNCash.x = d + D_800FE5A0_BashNCash.x;
    obj->work[0] += 30;
    if (obj->work[0] >= 181) {
        obj->work[0] += 76;
        obj->work[1] >>= 1;
        obj->work[2]--;
        if (obj->work[2] == 0) {
            omDelObj(obj);
            D_800FE570_BashNCash.x = D_800FE594_BashNCash.x;
            D_800FE57C_BashNCash.x = D_800FE5A0_BashNCash.x;
        }
    }
}

void func_800FB1D4_BashNCash(void) {
    omObjData* obj;

    D_800FE594_BashNCash.x = D_800FE570_BashNCash.x;
    D_800FE5A0_BashNCash.x = D_800FE57C_BashNCash.x;
    obj = omAddObj(0x64, 0, 0, -1, func_800FB0D8_BashNCash);
    obj->work[0] = 90;
    obj->work[1] = 25;
    obj->work[2] = 3;
}

/* Opening camera: around the cash player, then up to the game view; the cash player jumps. */
// register allocation and scheduling (nmcmp: calls and stores equal)
#ifdef NON_MATCHING
void func_800FB240_BashNCash(omObjData* obj) {
    omObjData* cash;
    BashPlayerWork* w;

    cash = D_800FE690_BashNCash.obj;
    w = cash->unk_50;
    switch (obj->work[0]) {
    case 0:
        if (obj->work[1]++ >= 16) {
            obj->work[0] = 1;
            obj->work[1] = 0;
        }
        D_800FE568_BashNCash = func_80029518(w->unk_3C + 180.0f);
        D_800FE56C_BashNCash = 150.0f;
        D_800FE570_BashNCash.x = func_800AEAC0(D_800FE568_BashNCash) * D_800FE56C_BashNCash + cash->trans.x;
        D_800FE570_BashNCash.y = 400.0f;
        D_800FE570_BashNCash.z = func_800AEFD0(D_800FE568_BashNCash) * D_800FE56C_BashNCash + cash->trans.z;
        D_800FE57C_BashNCash.x = cash->trans.x;
        D_800FE57C_BashNCash.y = cash->trans.y;
        D_800FE57C_BashNCash.z = cash->trans.z;
        D_800FE588_BashNCash.x = 0.0f;
        D_800FE588_BashNCash.y = 1.0f;
        D_800FE588_BashNCash.z = 0.0f;
        break;
    case 1:
        if (obj->work[1]++ >= 31) {
            obj->work[0] = 2;
            obj->work[1] = 0;
        } else {
            D_800FE570_BashNCash.x = func_800AEAC0(D_800FE568_BashNCash) * D_800FE56C_BashNCash + cash->trans.x;
            D_800FE570_BashNCash.y -= 6.6666665f;
            D_800FE570_BashNCash.z = func_800AEFD0(D_800FE568_BashNCash) * D_800FE56C_BashNCash + cash->trans.z;
            D_800FE56C_BashNCash += 10.0f;
            D_800FE568_BashNCash -= 6.0f;
        }
        break;
    case 2:
        if (obj->work[1]++ >= 30) {
            obj->work[0] = 3;
            obj->work[1] = 0;
            D_800FE544_BashNCash.x = D_800FE570_BashNCash.x;
            D_800FE544_BashNCash.y = D_800FE570_BashNCash.y;
            D_800FE544_BashNCash.z = D_800FE570_BashNCash.z;
            D_800FE550_BashNCash.x = D_800FE57C_BashNCash.x;
            D_800FE550_BashNCash.y = D_800FE57C_BashNCash.y;
            D_800FE550_BashNCash.z = D_800FE57C_BashNCash.z;
            D_800FE55C_BashNCash.x = D_800FE588_BashNCash.x;
            D_800FE55C_BashNCash.y = D_800FE588_BashNCash.y;
            D_800FE55C_BashNCash.z = D_800FE588_BashNCash.z;
            func_80060128(0x1B);
        }
        D_800FE57C_BashNCash.y += 6.6666665f;
        break;
    case 3:
        if (obj->work[1]++ >= 29) {
            obj->work[0] = 4;
            obj->work[1] = 0;
        }
        D_800FE570_BashNCash.x = (15.0f - D_800FE544_BashNCash.x) / 30.0f + D_800FE570_BashNCash.x;
        D_800FE570_BashNCash.y = (1017.032f - D_800FE544_BashNCash.y) / 30.0f + D_800FE570_BashNCash.y;
        D_800FE570_BashNCash.z = (1476.153f - D_800FE544_BashNCash.z) / 30.0f + D_800FE570_BashNCash.z;
        D_800FE57C_BashNCash.x = (15.0f - D_800FE550_BashNCash.x) / 30.0f + D_800FE57C_BashNCash.x;
        D_800FE57C_BashNCash.y = (0.0f - D_800FE550_BashNCash.y) / 30.0f + D_800FE57C_BashNCash.y;
        D_800FE57C_BashNCash.z = (-105.0f - D_800FE550_BashNCash.z) / 30.0f + D_800FE57C_BashNCash.z;
        D_800FE588_BashNCash.x = (0.0f - D_800FE55C_BashNCash.x) / 30.0f + D_800FE588_BashNCash.x;
        D_800FE588_BashNCash.y = (0.841039f - D_800FE55C_BashNCash.y) / 30.0f + D_800FE588_BashNCash.y;
        D_800FE588_BashNCash.z = (-0.5409745f - D_800FE55C_BashNCash.z) / 30.0f + D_800FE588_BashNCash.z;
        break;
    case 4:
        D_800FE6A8_BashNCash[0].saveBtn = ContBtn[GwPlayer[D_800FE610_BashNCash].port];
        D_800FE6A8_BashNCash[0].saveTrg = ContBtnTrg[GwPlayer[D_800FE610_BashNCash].port];
        D_800FE6A8_BashNCash[0].saveStkX = ContStkX[GwPlayer[D_800FE610_BashNCash].port];
        D_800FE6A8_BashNCash[0].saveStkY = ContStkY[GwPlayer[D_800FE610_BashNCash].port];
        ContBtn[GwPlayer[D_800FE610_BashNCash].port] = 0;
        ContBtnTrg[GwPlayer[D_800FE610_BashNCash].port] = 0;
        ContStkX[GwPlayer[D_800FE610_BashNCash].port] = 0;
        ContStkY[GwPlayer[D_800FE610_BashNCash].port] = 0;
        ContBtnTrg[GwPlayer[D_800FE610_BashNCash].port] |= 0x8000;
        func_80009458();
        func_80009468();
        func_80005A28(cash);
        func_8000942C();
        func_80009468();
        ContBtn[GwPlayer[D_800FE610_BashNCash].port] = D_800FE6A8_BashNCash[0].saveBtn;
        ContBtnTrg[GwPlayer[D_800FE610_BashNCash].port] = D_800FE6A8_BashNCash[0].saveTrg;
        ContStkX[GwPlayer[D_800FE610_BashNCash].port] = D_800FE6A8_BashNCash[0].saveStkX;
        ContStkY[GwPlayer[D_800FE610_BashNCash].port] = D_800FE6A8_BashNCash[0].saveStkY;
        obj->work[0] = 5;
        break;
    case 5:
        if (w->unk_38 == 1000.0f) {
            PlaySound(0x253);
            func_800FB1D4_BashNCash();
            obj->work[0] = 6;
        }
        break;
    }
    D_800FE5AC_BashNCash = 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_BashNCash/137050", func_800FB240_BashNCash);
#endif

void func_800FB928_BashNCash(omObjData* obj) {
    obj->work[0] = 0;
    obj->work[1] = 0;
    obj->func_ptr = func_800FB240_BashNCash;
}

/* Pushes a coin out of the players it overlaps (D_800ED6B8 / D_800F5254). */
void func_800FB940_BashNCash(omObjData* obj, Vec3f* pos) {
    Vec3f dir;
    BashCoinWork* w;
    BashPlayerWork* pw;
    omObjData* player;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 d;
    u16 i;
    u32 flags;

    w = obj->unk_50;
    flags = *(u32*)&w->unk_50;
    if ((flags & 0x204000) == 0x4000) {
        for (i = 0; i < D_800F2BC0; i++) {
            player = D_800F3FB0[i];
            pw = player->unk_50;
            dx = player->trans.x - pos->x;
            dy = player->trans.y - pos->y;
            dz = player->trans.z - pos->z;
            d = func_800B1750(dx * dx + dy * dy + dz * dz) - (w->unk_48 + pw->unk_48);
            if (d < 0.0f) {
                dir.x = dx;
                dir.y = 0.0f;
                dir.z = dz;
                func_8002956C(&dir);
                D_800ED6B8 += d * dir.x;
                D_800F5254 += d * dir.z;
            }
        }
    }
}

/* Ground height under a coin. */
f32 func_800FBAB8_BashNCash(omObjData* obj, f32 x, f32 y, f32 z, Vec3f* normal) {
    Vec4f probe;
    BashColVtx* verts;
    s16* tri;
    f32 best;
    f32 h;
    s16 mdl;
    BashCoinWork* w;

    w = COIN_WORK(obj);
    best = -10000.0f;
    probe.x = x;
    probe.y = y;
    probe.z = z;
    probe.w = w->unk_48;
    func_800FB940_BashNCash(obj, (Vec3f*)&probe);
    probe.x = x + D_800ED6B8;
    probe.y = y;
    probe.z = z + D_800F5254;
    func_80004D1C(obj, &probe, D_800B8988);
    mdl = D_800F2AF8[D_800B8954]->model[0];
    verts = (BashColVtx*)D_800F2B7C[mdl].unk_6C->unk_78;
    func_8002AE24(mdl, &D_800EDEC0, func_80002060, &probe);
    goto next;
loop:
    h = func_80029764(x, y, z, verts, (u16*)tri);
    if (best < h) {
        best = h;
        func_800295FC(&verts[tri[1]], &verts[tri[2]], &verts[tri[3]], normal);
    }
next:
    if ((tri = (s16*)func_8002B3A8(&D_800EDEC0)) != NULL) {
        goto loop;
    }
    if (best == -10000.0f) {
        best = -65536.0f;
    }
    h = func_800051D4(obj, x, y, z, normal);
    if (best < h) {
        best = h;
    }
    return best;
}

/* A coin's object: flies, bounces off the walls, lands and blinks out. */
// loop layout (retail calls func_8002B3A8 before the loop and at its end) and register allocation
#ifdef NON_MATCHING
void func_800FBCC8_BashNCash(omObjData* obj) {
    Vec3f normal;
    Vec3f hit;
    Vec4f probe;
    Vec3f pos;
    BashCoinWork* w;
    BashCoinSlot* slot;
    BashColVtx* verts;
    s16* tri;
    s16 mdl;
    f32 x;
    f32 y;
    f32 z;
    f32 a;
    f32 vy;
    f32 dy;
    f32 h;
    f32 s;
    s32 one;

    one = D_800ED430;
    if (one == 1) {
        w = obj->unk_50;
        if (w->unk_54 != 0) {
            x = obj->trans.x;
            y = obj->trans.y;
            z = obj->trans.z;
            D_800F5254 = 0.0f;
            D_800ED6B8 = 0.0f;
            x += func_800AEAC0(w->unk_3C) * w->unk_40;
            z += func_800AEFD0(w->unk_3C) * w->unk_40;
            probe.x = x;
            probe.y = obj->trans.y + 100.0f;
            probe.z = z;
            probe.w = w->unk_48;
            D_800B8956 = 0;
            mdl = D_800F2AF8[0]->model[0];
            verts = (BashColVtx*)D_800F2B7C[mdl].unk_6C->unk_78;
            func_8002AE24(mdl, &D_800EDEC0, func_80002080, &probe);
            if (D_800B8956 == one) {
                while ((tri = (s16*)func_8002B3A8(&D_800EDEC0)) != NULL) {
                    func_800295FC(&verts[tri[1]], &verts[tri[2]], &verts[tri[3]], &hit);
                    pos.x = hit.x;
                    pos.y = 0.0f;
                    pos.z = hit.z;
                    a = func_80029518(func_800B0CD8(pos.x, hit.z));
                    w->unk_3C = a + func_80029518(a - func_80029518(w->unk_3C + 180.0f));
                }
            }
            if (D_800B8956 >= 2) {
                w->unk_3C += 180.0f;
            }
            if (w->unk_38 < 1000.0f) {
                obj->work[2] = 0;
                vy = w->unk_38;
                if (vy > 2.0f) {
                    vy = 2.0f;
                }
                dy = 35.0f;
                if (w->unk_38 >= 0.0f) {
                    dy = -35.0f;
                }
                y += vy * vy * dy;
                h = func_800FBAB8_BashNCash(obj, x, y, z, &normal);
                if (y < h) {
                    w->unk_38 = 1000.0f;
                    y = h;
                }
                w->unk_38 += D_800B8968;
            } else {
                if (w->unk_52 == 6) {
                    PlaySound(0x10A);
                    w->unk_38 = -1.0f;
                } else if (obj->work[2] == 0) {
                    PlaySound(0x108);
                    obj->work[2] = 1;
                }
                y = func_800FBAB8_BashNCash(obj, x, y, z, &normal);
            }
            obj->trans.x = x + D_800ED6B8;
            obj->trans.y = y;
            obj->trans.z = z + D_800F5254;
            obj->rot.y = w->unk_3C;
            if (_CheckFlag(0x45) != 0 && w->unk_38 > 0.0f) {
                pos.x = obj->trans.x;
                pos.y = obj->trans.y;
                pos.z = obj->trans.z;
                func_800F9FD0_BashNCash(obj, &pos);
            }
            if (_CheckFlag(0x45) == 0) {
                w->unk_40 = 17.5f;
            }
            slot = &D_800FE630_BashNCash[obj->work[0]];
            if (slot->timer < 31) {
                if (D_800F2B7C[obj->model[0]].unk_20 & 4) {
                    func_800258EC(obj->model[0], 4, 0);
                } else {
                    func_800258EC(obj->model[0], 4, 4);
                }
            }
            if (slot->timer == 0) {
                w->unk_54 = 0;
                func_800258EC(obj->model[0], 4, 4);
                func_800258EC(obj->model[1], 4, 4);
            }
            slot->timer--;
            func_80025798(obj->model[1], obj->trans.x, 0.0f, obj->trans.z);
            s = obj->trans.y - 0.0f;
            if (!(s > 200.0f)) {
                s = 0.4f - s / 2000.0001f;
            }
            func_80025830(obj->model[1], s, s, s);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_BashNCash/137050", func_800FBCC8_BashNCash);
#endif

/* The game's control object. */
// register allocation and a shared base register for this unit's .data
#ifdef NON_MATCHING
void func_800FC240_BashNCash(void) {
    BashPlayerWork* w;
    s32 diff;
    s32 i;

    func_800F6EE0_BashNCash();
    func_80009468();
    switch (D_800ED430) {
    case 0:
        if (func_80072718() == 0) {
            if (D_800FE3D4_BashNCash == 0) {
                if (D_800FE3D8_BashNCash == 120) {
                    PlaySound(0x255);
                }
                if (D_800FE3D8_BashNCash-- != 0) {
                    break;
                }
                GMesCreate(0);
                D_800FE3D4_BashNCash = 1;
            }
            if (GMesStatAllGet() == 0) {
                func_800FD774_BashNCash();
                GMesCreate(8, 0x1E, 0xA0, 0x18);
                func_80009458();
            }
        }
        func_80079078(D_800FE3DC_BashNCash / 30);
        break;
    case 1:
        func_80079078(D_800FE3DC_BashNCash / 30);
        if (--D_800FE3DC_BashNCash < 29) {
            D_800FE62A_BashNCash = 1;
        }
        if (D_800FE628_BashNCash != 0 && func_800F9F64_BashNCash() != 0) {
            D_800FE62A_BashNCash = 1;
        }
        if (D_800FE62A_BashNCash != 0) {
            if (D_800FE3F4_BashNCash == 0) {
                D_800FE3F4_BashNCash = 1;
                func_800601D4(0x28);
                D_800FE3E4_BashNCash = 210;
            }
            for (i = 0; i < D_800F2BC0; i++) {
                if (!(u8)func_800F73F0_BashNCash(i)) {
                    break;
                }
            }
            if (i >= D_800F2BC0 || --D_800FE3E4_BashNCash == 0) {
                func_80009438();
            }
        }
        break;
    case 2:
        if (D_800FE3E0_BashNCash == 0) {
            D_800FE5D0_BashNCash->work[1] = 0;
            w = D_800F3FB0[D_800FE610_BashNCash]->unk_50;
            if (_CheckFlag(0x2B) == 0) {
                diff = GwPlayer[w->unk_58].coins - D_800FE690_BashNCash.coins;
            } else {
                diff = -D_800FE690_BashNCash.coins;
            }
            GwPlayer[w->unk_58].coins_mg -= diff;
            func_80009730();
            D_800FE3E0_BashNCash = 1;
            func_800FA094_BashNCash();
            if (GwPlayer[w->unk_58].coins_mg >= 0) {
                D_800FE3EC_BashNCash = 1;
            } else {
                D_800FE3EC_BashNCash = 0;
            }
            GMesCreate(2);
        }
        if (GMesStatAllGet() == 0) {
            D_800FE62C_BashNCash = 3;
            w = D_800F3FB0[D_800FE610_BashNCash]->unk_50;
            if (_CheckFlag(0x2B) == 0) {
                w->unk_3C = 0.0f;
                func_8009ECB0(D_800F2B7C[D_800F3FB0[D_800FE610_BashNCash]->model[0]].unk7C, w->unk_3C, w->unk_3C,
                              w->unk_3C);
                if (D_800FE3EC_BashNCash != 0) {
                    func_800184BC(D_800F3FB0[D_800FE610_BashNCash], 0xD);
                    func_80060128(0x35);
                } else {
                    func_800184BC(D_800F3FB0[D_800FE610_BashNCash], 0xE);
                    func_80060128(0x34);
                }
            }
            func_800FD830_BashNCash();
            func_800790C0();
            func_80009448();
        }
        break;
    case 3:
        switch (D_800FE3E8_BashNCash) {
        case 0:
            if (D_800FE3EC_BashNCash == 0 && _CheckFlag(0x2B) == 0) {
                if (D_800FE3F0_BashNCash++ >= 19) {
                    PlaySound(GwPlayer[D_800FE610_BashNCash].character + 0x44A);
                    D_800FE3F0_BashNCash = 0;
                    D_800FE3E8_BashNCash = 1;
                }
            } else {
                D_800FE3E8_BashNCash = 1;
            }
            break;
        case 1:
            if (_CheckFlag(0x2B) == 0) {
                if (D_800FE3EC_BashNCash != 0) {
                    diff = D_800FE3F0_BashNCash++ < 90;
                } else {
                    diff = D_800FE3F0_BashNCash++ < 77;
                }
            } else {
                diff = D_800FE3F0_BashNCash++ < 20;
            }
            if (!diff && (_CheckFlag(0x2B) == 0 || GMesWait() != 1)) {
                func_800726AC(0, 0x14);
                D_800FE3E8_BashNCash = 2;
            }
            break;
        case 2:
            if (func_80072718() == 0) {
                func_8002890C(0, 0, 0);
                omOvlReturnEx(1);
            }
            break;
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_BashNCash/137050", func_800FC240_BashNCash);
#endif

void func_800FC840_BashNCash(omObjData* obj) {
    BashCtrlWork* w;

    obj->model[0] = func_800174C0(0x220000, 0x29D);
    obj->model[1] = func_800174C0(0x190000, 0x299);
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    func_80025798(obj->model[1], 0.0f, obj->trans.y, obj->trans.z);
    w = func_80023684(0x2C, 0x7918);
    obj->unk_50 = w;
    func_8009B770(w, 0, 0x2C);
    obj->func_ptr = func_800FC240_BashNCash;
    w->unk_04 = 1;
    func_80008FB8(obj, 0.5f);
    w->unk_05 = 0;
}

void func_800FC904_BashNCash(omObjData* obj) {
    void* w;

    w = func_80023684(0xE8, 0x7918);
    obj->unk_50 = w;
    func_8009B770(w, 0, 0xE8);
    obj->model[0] = LoadFormFile(0x190003, 0xA99);
    obj->model[1] = LoadFormFile(0x190004, 0xA99);
    obj->model[2] = LoadFormFile(0x220001, 0xA99);
    obj->func_ptr = NULL;
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    func_80025798(obj->model[1], 0.0f, obj->trans.y, obj->trans.z);
    func_80025798(obj->model[2], obj->trans.x, obj->trans.y, obj->trans.z);
}

// register allocation and scheduling (nmcmp: calls and stores equal)
// decomp-permuter
void func_800FC9D4_BashNCash(omObjData *obj, s32 file, s8 value, Vec3f *pos, s32 slot)
{
  BashCoinWork *new_var;
  long new_var2;
  BashCoinSlot *s;
  BashCoinWork *w;
  s = &D_800FE630_BashNCash[slot];
  obj->unk_50 = func_80023684(0x6C, 0x7918);
  func_8009B770(obj->unk_50, 0, 0x6C);
  obj->func_ptr = func_800FBCC8_BashNCash;
  w = obj->unk_50;
  func_800091BC(obj, file, 0x1A8D, 8);
  obj->model[1] = func_800174F4(6, 0xA9D);
  func_80009340(obj, 3, 0x2A, 0xA8D, 8);
  func_8001E360(w->unk_24, 0xFF, 0xFF, 0xBE);
  new_var = w;
  obj->work[2] = 0;
  obj->trans.x = pos->x;
  obj->trans.y = pos->y;
  obj->trans.z = pos->z;
  obj->scale.x = (obj->scale.y = (obj->scale.z = 2.0f));
  func_800F6EE8_BashNCash(obj, 0.8f, 0.0f, 1);
  new_var->unk_44 = 0.1f;
  new_var->unk_48 = 30.0f;
  new_var2 = value;
  new_var->unk_34 = 30.0f;
  new_var->unk_5C = 0;
  new_var->unk_3C = 60.0f;
  new_var->unk_40 = D_800B8984;
  new_var->unk_38 = 1000.0f;
  new_var->unk_52 = new_var2;
  new_var->unk_60 = 0;
  new_var->unk_4C = 0.5f;
  new_var->unk_50 = 0;
  new_var->unk_54 = 0;
  new_var->unk_58 = 0.5f;
  obj->work[0] = slot;
  s->obj = obj;
  s->unk_08 = 0;
}

void func_800FCBA8_BashNCash(omObjData* obj) {
    Vec3f pos_s;
    Vec3f* pos = &pos_s;

    func_800A0D00(pos, 0.0f, 0.0f, 0.0f);
    func_800FC9D4_BashNCash(obj, 0x21, 3, pos, 0);
}

void func_800FCC00_BashNCash(omObjData* obj) {
    Vec3f pos_s;
    Vec3f* pos = &pos_s;

    func_800A0D00(pos, 0.0f, 0.0f, 0.0f);
    func_800FC9D4_BashNCash(obj, 0x21, 3, pos, 1);
}

void func_800FCC5C_BashNCash(omObjData* obj) {
    Vec3f pos_s;
    Vec3f* pos = &pos_s;

    func_800A0D00(pos, 0.0f, 0.0f, 0.0f);
    func_800FC9D4_BashNCash(obj, 0x21, 3, pos, 2);
}

void func_800FCCB8_BashNCash(omObjData* obj) {
    Vec3f pos_s;
    Vec3f* pos = &pos_s;

    func_800A0D00(pos, 0.0f, 0.0f, 0.0f);
    func_800FC9D4_BashNCash(obj, 0x21, 3, pos, 3);
}

void func_800FCD14_BashNCash(omObjData* obj) {
    Vec3f pos_s;
    Vec3f* pos = &pos_s;

    func_800A0D00(pos, 0.0f, 0.0f, 0.0f);
    func_800FC9D4_BashNCash(obj, 0x37, 6, pos, 4);
}

void func_800FCD70_BashNCash(omObjData* obj) {
    Vec3f pos_s;
    Vec3f* pos = &pos_s;

    func_800A0D00(pos, 0.0f, 0.0f, 0.0f);
    func_800FC9D4_BashNCash(obj, 0x37, 6, pos, 5);
}

void func_800FCDCC_BashNCash(omObjData* obj) {
    Vec3f pos_s;
    Vec3f* pos = &pos_s;

    func_800A0D00(pos, 0.0f, 0.0f, 0.0f);
    func_800FC9D4_BashNCash(obj, 0x37, 6, pos, 6);
}

void func_800FCE28_BashNCash(omObjData* obj) {
    Vec3f pos_s;
    Vec3f* pos = &pos_s;

    func_800A0D00(pos, 0.0f, 0.0f, 0.0f);
    func_800FC9D4_BashNCash(obj, 0x37, 6, pos, 7);
}

s32 func_800FCE84_BashNCash(void) {
    return 1;
}

/* The cash player's object setup. */
// register allocation and scheduling (nmcmp: calls and stores equal)
#ifdef NON_MATCHING
void func_800FCE8C_BashNCash(omObjData* obj, s32 dir, s32 file, u16 player, Vec3f* pos, u16 chr) {
    char* heads[6] = {
        "atama_2", "Luigi1-atama_2", "C002_000b-bmerge10_1", "c003_000-head_1", "Luigi1-atama_1", "c005_000-bmerge1",
    };
    BashPlayerWork* w;
    s32 k;

    func_8000979C(obj, 0x220000, 3, player, 0xA99, 0xA99);
    obj->model[3] = LoadFormFile(0x19, 0xA8D);
    obj->model[4] = LoadFormFile(0x1A, 0xA8D);
    obj->model[7] = LoadFormFile(0x1E, 0xA8D);
    obj->model[6] = LoadFormFile(0x1B, 0xA8D);
    w = obj->unk_50;
    func_8001874C(obj, 0, 0x220004, 1, 0);
    func_8001874C(obj, 1, 0x220005, 1, 0);
    func_8001874C(obj, 2, 0x220005, 1, 0);
    func_8001874C(obj, 6, 0x220006, 1, 0xE);
    func_8001874C(obj, 0x15, 0x220007, 0, 0);
    func_8001874C(obj, 0xD, 0x220008, 1, 0);
    func_8001874C(obj, 0xE, 0x220009, 1, 0x3C);
    func_800090C4(obj, 0, 2);
    obj->work[0] = player;
    obj->work[1] = 0;
    obj->work[2] = 0;
    obj->work[3] = 0;
    func_800F6F6C_BashNCash(obj);
    obj->trans.x = pos->x;
    obj->trans.y = pos->y;
    obj->trans.z = pos->z;
    w->unk_3C = func_80029518(func_800B0CD8(-obj->trans.x, -obj->trans.z));
    func_800F6EE8_BashNCash(obj, 1.0f, 0.0f, 1);
    obj->func_ptr = func_800FAAE4_BashNCash;
    w->unk_52 = 0;
    w->unk_38 = 1000.0f;
    w->unk_A4 = 0.8f;
    w->unk_56 = GwPlayer[player].port;
    if (_CheckFlag(0x45) != 0) {
        w->unk_DC = func_800FCE84_BashNCash;
    }
    D_800B8964 = 1.6f;
    k = chr + 1;
    D_800B89A4[player][0] = 0x24C;
    D_800B89A4[player][1] = 0x24C;
    D_800B89A4[player][2] = k + 0x120;
    D_800B89A4[player][3] = 0x251;
    D_800B89A4[player][4] = k + 0x12E;
    D_800B89A4[player][5] = k + 0x135;
    D_800B89A4[player][6] = k + 0x13C;
    D_800B89A4[player][7] = 0x144;
    D_800B89A4[player][8] = 0x145;
    D_800B89A4[player][9] = 0x146;
    D_800B89A4[player][10] = k + 0x147;
    D_800B89A4[player][11] = k + 0x14E;
    D_800B89A4[player][12] = 0x160;
    D_800B89A4[player][13] = 0x162;
    func_80008FD0(obj, 120.0f);
    func_80008FDC(obj, 300.0f);
    D_800FE690_BashNCash.obj = obj;
    D_800FE690_BashNCash.unk_04 = 0;
    D_800FE690_BashNCash.unk_06 = 0;
    obj->model[0xA] = LoadFormFile(dir | 0x9E, 0xA9D);
    func_80020EA0(obj->model[0xA], heads[chr], obj->model[0], "21_kimoti_1b-atama_3");
}
#else
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_10_BashNCash/137050", D_800FE480_BashNCash);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_10_BashNCash/137050", D_800FE4E4_BashNCash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_BashNCash/137050", func_800FCE8C_BashNCash);
#endif

/* A hammer player's object setup. */
// register allocation and scheduling (nmcmp: calls and stores equal)
#ifdef NON_MATCHING
void func_800FD2B0_BashNCash(omObjData* obj, s32 dir, s32 file, u16 player, Vec3f* pos) {
    BashPlayerWork* w;
    Vec3f v;
    s32 mot;

    func_8000979C(obj, dir, file, player, 0xA99, 0xA99);
    obj->model[3] = LoadFormFile(0x19, 0xA8D);
    obj->model[4] = LoadFormFile(0x1A, 0xA8D);
    w = obj->unk_50;
    func_80009340(obj, 0xB, 0x26, 0x1A8D, 8);
    func_8001874C(obj, 0, dir, 1, 0);
    func_8001874C(obj, 1, dir | 1, 1, 0);
    func_8001874C(obj, 2, dir | 3, 1, 0);
    if (rand8() & 1) {
        func_800187D0(obj, 0xD, dir | 0xF, 1, 0x78);
        mot = dir | 0x10;
    } else {
        func_800187D0(obj, 0xD, dir | 0x38, 1, 0x78);
        mot = dir | 0x3C;
    }
    func_800187D0(obj, 0xE, mot, 1, 0x78);
    func_800090C4(obj, 0, 2);
    obj->work[0] = player;
    func_800F6F6C_BashNCash(obj);
    obj->trans.x = pos->x;
    obj->trans.y = pos->y;
    obj->trans.z = pos->z;
    func_800A0D00(&v, 256.0f, 0.0f, -189.0f);
    v.x -= obj->trans.x;
    v.y -= 0.0f;
    v.z -= obj->trans.z;
    w->unk_3C = func_80029518(func_800B0CD8(v.x, v.z));
    func_800F6EE8_BashNCash(obj, 1.0f, 0.0f, 1);
    obj->func_ptr = func_800FA5B4_BashNCash;
    w->unk_52 = 0;
    w->unk_38 = 1000.0f;
    w->unk_A4 = 1.0f;
    w->unk_54 = -1;
    w->unk_56 = GwPlayer[player].port;
    func_80008FD0(obj, 60.0f);
    func_80008FDC(obj, 150.0f);
    func_80008FE8(obj, 20.0f);
    D_800FE710_BashNCash[obj->work[0]].obj = obj;
    D_800FE710_BashNCash[obj->work[0]].unk_04 = 0;
    D_800FE710_BashNCash[obj->work[0]].unk_06 = 0;
    D_800FE710_BashNCash[obj->work[0]].unk_0A = 0;
    D_800FE710_BashNCash[obj->work[0]].unk_0C = 0;
    D_800FE710_BashNCash[obj->work[0]].unk_10 = 0;
    switch (GwPlayer[obj->work[0]].cpu_difficulty) {
    case 0:
    case 1:
        D_800FE710_BashNCash[obj->work[0]].cpu = 1;
        break;
    case 2:
    case 3:
        D_800FE710_BashNCash[obj->work[0]].cpu = 0;
        break;
    }
    obj->model[0xA] = LoadFormFile(0x220002, 0xA99);
    func_8002859C(obj->model[0xA], obj->model[0], "item_hook");
    func_800258EC(obj->model[0xA], 0x4000, 0x4000);
    func_8001874C(obj, 0x23, dir | 0x41, 1, 0x46);
    func_8001874C(obj, 0x24, dir | 0x44, 0, 0x3C);
    func_80028498(obj->model[0], D_800F2B7C[obj->motion[0x23]].unk_08, 1);
    D_800FE618_BashNCash[D_800FE3F8_BashNCash] = obj->model[0xA];
    D_800FE600_BashNCash[D_800FE3F8_BashNCash++] = obj;
    obj->work[1] = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_BashNCash/137050", func_800FD2B0_BashNCash);
#endif

void func_800FD748_BashNCash(s32 player, s32 coins) {
    if (coins < 0) {
        coins = 0;
    }
    if (coins >= 1000) {
        coins = 999;
    }
    D_800FE40C_BashNCash[player] = coins;
}

void func_800FD774_BashNCash(void) {
    s32 i;

    D_800FE5D0_BashNCash->work[1] = 1;
    for (i = 0; i < 4; i++) {
        ShowBasicSprite(D_800FE5F0_BashNCash[i]);
        ShowBasicSprite(D_800FE5F8_BashNCash[i]);
        ShowBasicSprite(D_800FE5D8_BashNCash[i][0]);
        ShowBasicSprite(D_800FE5D8_BashNCash[i][1]);
        ShowBasicSprite(D_800FE5D8_BashNCash[i][2]);
    }
}

void func_800FD830_BashNCash(void) {
    s32 i;

    D_800FE5D0_BashNCash->work[1] = 0;
    for (i = 0; i < 4; i++) {
        func_80018C90(D_800FE5F0_BashNCash[i]);
        func_80018C90(D_800FE5F8_BashNCash[i]);
        func_80018C90(D_800FE5D8_BashNCash[i][0]);
        func_80018C90(D_800FE5D8_BashNCash[i][1]);
        func_80018C90(D_800FE5D8_BashNCash[i][2]);
    }
}

/* Coin counters: three digits, leading zeros hidden. */
// the early-return test and register allocation
#ifdef NON_MATCHING
void func_800FD8E8_BashNCash(omObjData* obj) {
    s32 i;
    s32 coins;
    s32 d;
    s16 x;

    if (obj->work[1] == 0 || obj->work[1] != 1) {
        return;
    }
    for (i = 0; i < 4; i++) {
        coins = D_800FE40C_BashNCash[i];
        if (coins >= 1000) {
            coins = 999;
        }
        x = 0;
        ShowBasicSprite(D_800FE5D8_BashNCash[i][2]);
        d = coins / 100;
        if (d == 0) {
            func_80018C90(D_800FE5D8_BashNCash[i][2]);
        }
        func_80018E0C(D_800FE5D8_BashNCash[i][2], d);
        SetBasicSpritePos(D_800FE5D8_BashNCash[i][2], D_800FE3FC_BashNCash[i][0] + x, D_800FE3FC_BashNCash[i][1]);
        if (d != 0) {
            x += 12;
        }
        ShowBasicSprite(D_800FE5D8_BashNCash[i][1]);
        d = (coins % 100) / 10;
        if (d == 0 && coins / 100 == 0) {
            func_80018C90(D_800FE5D8_BashNCash[i][1]);
        }
        func_80018E0C(D_800FE5D8_BashNCash[i][1], d);
        SetBasicSpritePos(D_800FE5D8_BashNCash[i][1], D_800FE3FC_BashNCash[i][0] + x, D_800FE3FC_BashNCash[i][1]);
        if (d != 0 || coins / 100 != 0) {
            x += 12;
        }
        func_80018E0C(D_800FE5D8_BashNCash[i][0], coins % 10);
        SetBasicSpritePos(D_800FE5D8_BashNCash[i][0], D_800FE3FC_BashNCash[i][0] + x, D_800FE3FC_BashNCash[i][1]);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_BashNCash/137050", func_800FD8E8_BashNCash);
#endif

// s16 index conversions and register allocation
#ifdef NON_MATCHING
void func_800FDBB4_BashNCash(omObjData* obj) {
    s16 face[4][2] = { { 56, 24 }, { 264, 24 }, { 56, 202 }, { 264, 202 } };
    s16 coin[4][2] = { { 39, 38 }, { 247, 38 }, { 39, 216 }, { 247, 216 } };
    s32 i;
    s32 spr;

    for (i = 0; i < 4; i++) {
        D_800FE5F0_BashNCash[i] = func_80019060(InitSprite(GwPlayer[(s16)i].character + 0x6E), 0, 1);
        SetBasicSpritePos(D_800FE5F0_BashNCash[i], face[(s16)i][0], face[(s16)i][1]);
    }
    spr = InitSprite(0x74);
    for (i = 0; i < 4; i++) {
        D_800FE5F8_BashNCash[i] = func_80019060(spr, 0, 1);
        SetBasicSpritePos(D_800FE5F8_BashNCash[i], coin[i][0], coin[i][1]);
    }
    spr = InitSprite(0x87);
    for (i = 0; i < 4; i++) {
        D_800FE5D8_BashNCash[i][0] = func_80019060(spr, 0, 1);
        SetBasicSpritePos(D_800FE5D8_BashNCash[i][0], D_800FE3FC_BashNCash[i][0], D_800FE3FC_BashNCash[i][1]);
        D_800FE5D8_BashNCash[i][1] = func_80019060(spr, 0, 1);
        SetBasicSpritePos(D_800FE5D8_BashNCash[i][1], D_800FE3FC_BashNCash[i][0] + 12, D_800FE3FC_BashNCash[i][1]);
        D_800FE5D8_BashNCash[i][2] = func_80019060(spr, 0, 1);
        SetBasicSpritePos(D_800FE5D8_BashNCash[i][2], D_800FE3FC_BashNCash[i][0] + 24, D_800FE3FC_BashNCash[i][1]);
    }
    D_800FE5D0_BashNCash = obj;
    obj->work[1] = 0;
    obj->func_ptr = func_800FD8E8_BashNCash;
    func_800FD830_BashNCash();
}
#else
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_10_BashNCash/137050", D_800FE520_BashNCash);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_10_BashNCash/137050", D_800FE530_BashNCash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_BashNCash/137050", func_800FDBB4_BashNCash);
#endif

/* The next start position of a hammer player (skipping the cash player's slot 0). */
u16 func_800FDED0_BashNCash(void) {
    if (D_800FE690_BashNCash.order[D_800FE41C_BashNCash] == 0) {
        D_800FE41C_BashNCash++;
    }
    return D_800FE690_BashNCash.order[D_800FE41C_BashNCash++];
}

void func_800FDF20_BashNCash(omObjData* obj) {
    Vec3f pos_s;
    Vec3f* pos = &pos_s;
    s16 slot;
    s32 chr;

    if (D_800FE610_BashNCash == 0) {
        slot = 0;
    } else {
        slot = func_800FDED0_BashNCash();
    }
    pos->x = D_800FE420_BashNCash[slot].x;
    pos->y = D_800FE420_BashNCash[slot].y;
    pos->z = D_800FE420_BashNCash[slot].z;
    chr = GwPlayer[0].character;
    if (D_800FE610_BashNCash == 0) {
        func_800FCE8C_BashNCash(obj, D_800C59AC[chr].unk_00, D_800C59AC[chr].unk_04, 0,
                                pos, chr);
        return;
    }
    func_800FD2B0_BashNCash(obj, D_800C59AC[chr].unk_00, D_800C59AC[chr].unk_04, 0, pos);
}

void func_800FE038_BashNCash(omObjData* obj) {
    Vec3f pos_s;
    Vec3f* pos = &pos_s;
    s16 slot;
    s32 chr;

    if (D_800FE610_BashNCash == 1) {
        slot = 0;
    } else {
        slot = func_800FDED0_BashNCash();
    }
    pos->x = D_800FE420_BashNCash[slot].x;
    pos->y = D_800FE420_BashNCash[slot].y;
    pos->z = D_800FE420_BashNCash[slot].z;
    chr = GwPlayer[1].character;
    if (D_800FE610_BashNCash == 1) {
        func_800FCE8C_BashNCash(obj, D_800C59AC[chr].unk_00, D_800C59AC[chr].unk_04, 1,
                                pos, chr);
        return;
    }
    func_800FD2B0_BashNCash(obj, D_800C59AC[chr].unk_00, D_800C59AC[chr].unk_04, 1, pos);
}

void func_800FE158_BashNCash(omObjData* obj) {
    Vec3f pos_s;
    Vec3f* pos = &pos_s;
    s16 slot;
    s32 chr;

    if (D_800FE610_BashNCash == 2) {
        slot = 0;
    } else {
        slot = func_800FDED0_BashNCash();
    }
    pos->x = D_800FE420_BashNCash[slot].x;
    pos->y = D_800FE420_BashNCash[slot].y;
    pos->z = D_800FE420_BashNCash[slot].z;
    chr = GwPlayer[2].character;
    if (D_800FE610_BashNCash == 2) {
        func_800FCE8C_BashNCash(obj, D_800C59AC[chr].unk_00, D_800C59AC[chr].unk_04, 2,
                                pos, chr);
        return;
    }
    func_800FD2B0_BashNCash(obj, D_800C59AC[chr].unk_00, D_800C59AC[chr].unk_04, 2, pos);
}

void func_800FE278_BashNCash(omObjData* obj) {
    Vec3f pos_s;
    Vec3f* pos = &pos_s;
    s16 slot;
    s32 chr;

    if (D_800FE610_BashNCash == 3) {
        slot = 0;
    } else {
        slot = func_800FDED0_BashNCash();
    }
    pos->x = D_800FE420_BashNCash[slot].x;
    pos->y = D_800FE420_BashNCash[slot].y;
    pos->z = D_800FE420_BashNCash[slot].z;
    chr = GwPlayer[3].character;
    if (D_800FE610_BashNCash == 3) {
        func_800FCE8C_BashNCash(obj, D_800C59AC[chr].unk_00, D_800C59AC[chr].unk_04, 3,
                                pos, chr);
        return;
    }
    func_800FD2B0_BashNCash(obj, D_800C59AC[chr].unk_00, D_800C59AC[chr].unk_04, 3, pos);
}
