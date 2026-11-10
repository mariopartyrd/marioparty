#include "common.h"
#include "19FEE0.h"

/* .data (0x800FB500..0x800FB510) */
s32 D_800FB500_KnockBlockTower = 0;
s32 D_800FB504_KnockBlockTower[3] = { 0, 0, 0 }; /* unreferenced */

#define KBT_ABS(x) (((x) < 0.0f) ? -(x) : (x))

/* Height of the tower top under (x, z): only above the tower's 150x150 footprint. */
#define KBT_FLOOR(out, o)                                                                          \
    (out) = 0.0f;                                                                                  \
    if (KBT_ABS((o)->trans.x) < 75.0f && KBT_ABS((o)->trans.z) < 75.0f) {                          \
        (out) = func_800F79BC_KnockBlockTower();                                                   \
    }

void func_800F65E0_KnockBlockTower(void) {
    u8 temp_s0;

    func_80029090(0x32);
    func_8002ADF0(&D_800EDEC0, 0x40);
    func_8001DE70(0x20);
    omInitObjMan(0x32, 0);
    func_80060088();
    func_8000942C();
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    func_800178A0(1);
    temp_s0 = func_800178E8();
    func_80017660(temp_s0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(temp_s0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 30.0f, 80.0f, 8000.0f);
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    func_800F6C98_KnockBlockTower();
    func_800090B8(D_800ED440);
    D_800F2AF8[D_800ED440++] = omAddObj(1, 3, 0, -1, &func_800F9BD0_KnockBlockTower);
    D_800F2AF8[D_800ED440++] = omAddObj(1, 1, 0, -1, &func_800F9C98_KnockBlockTower);
    D_800FB8E0_KnockBlockTower = omAddObj(2, 0, 0, -1, &func_800F69F8_KnockBlockTower);
    func_800F6A10_KnockBlockTower();
    func_800F6C4C_KnockBlockTower();
    func_80009500();
    D_800B8964 = 1.52f;
    D_800F3FB0[D_800F2BC0++] = omAddObj(0xA, 0xB, 0x32, -1, &func_800FA92C_KnockBlockTower);
    func_8006B870();
    D_800FB8D8_KnockBlockTower = (omObjData*)func_8006B8A4(0x1E, 0x699, 0xA89, 0x1A89, 0);
    omAddObj(0x28, 0, 0, -1, &func_800FA010_KnockBlockTower);
    omAddObj(0x1E, 2, 0, -1, &func_800FA560_KnockBlockTower);
    omAddObj(1, 0, 0, -1, &func_800FB2B4_KnockBlockTower);
    omAddObj(1, 0, 0, -1, &func_800F6BF8_KnockBlockTower);
    func_8007B168((u8*)"\x82\x65\x82\x68\x82\x6D\x82\x68\x82\x72\x82\x67", 1); /* "FINISH" (SJIS) */
    func_8002890C(0, 0, 0);
    func_80028510(0x3A5, 0x402, 0xFF, 0xC8, 0xC8);
    SetFadeInTypeAndTime(0, 0x10);
}

/* Drops one bomb block every 90 frames, alternating the first and second one. */
void func_800F692C_KnockBlockTower(omObjData* obj) {
    KBTNode* n;
    s32 i;

    if (D_800ED430 != 1 || D_800FB7D8_KnockBlockTower != 0 || D_800FB8DC_KnockBlockTower != -1) {
        return;
    }
    if (obj->work[0] != 0) {
        obj->work[0]--;
        return;
    }
    n = D_800FB650_KnockBlockTower[0].next;
    i = 0;
    while (n->next != NULL) {
        if (n->type == 1) {
            if (obj->work[1] == i++) {
                n->state = 2;
                obj->work[0] = 90;
                if (++obj->work[1] >= 2) {
                    obj->work[1] = 0;
                }
                return;
            }
        }
        n = n->next;
    }
}

void func_800F69F8_KnockBlockTower(omObjData* obj) {
    obj->work[0] = 0;
    obj->work[1] = 0;
    obj->func_ptr = &func_800F692C_KnockBlockTower;
}

/* Builds the tower: 5 or 6 blocks, two of them (type 1) bombs. */
// list-head stores: retail addresses D_800FB650[0]'s fields by symbol, GCC reuses the base register (masked ~24)
#ifdef NON_MATCHING
void func_800F6A10_KnockBlockTower(void) {
    KBTNode* n;
    s32 i;
    s32 count;
    s32 first;
    s32 second;

    count = (rand8() & 1) + 5;
    D_800FB650_KnockBlockTower[0].obj = NULL;
    D_800FB650_KnockBlockTower[0].type = -1;
    D_800FB650_KnockBlockTower[0].next = &D_800FB650_KnockBlockTower[1];
    n = D_800FB650_KnockBlockTower[0].next;
    for (i = 0; i < count; i++) {
        n->type = 0;
        n->state = 0;
        n->vel = 0.0f;
        n->accel = 2.0f;
        n->angle = 0.0f;
        n->next = n + 1;
        n = n + 1;
    }
    n->obj = NULL;
    n->type = -1;
    n->next = NULL;
    first = rand8() & 1;
    D_800FB650_KnockBlockTower[first + 1].type = 1;
    second = (rand8() & 0xFF) % (count - (first + 3)) + 2;
    D_800FB650_KnockBlockTower[first + second + 1].type = 1;
    n = D_800FB650_KnockBlockTower[0].next;
    for (i = 0; i < count; i++, n++) {
        if (n->type == 0) {
            D_800F2AF8[D_800ED440++] = n->obj = omAddObj(i + 3, 1, 0, -1, &func_800F9D3C_KnockBlockTower);
        } else {
            D_800F2AF8[D_800ED440++] = n->obj = omAddObj(i + 3, 2, 0, -1, &func_800F9EA0_KnockBlockTower);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_KnockBlockTower/19FEE0", func_800F6A10_KnockBlockTower);
#endif

void func_800F6BF8_KnockBlockTower(omObjData* obj) {
    if (D_800F5144 == 1 || D_800F5144 == 1) {
        func_800601D4(0x28);
        func_8002890C(0, 0, 0);
        func_800FB250_KnockBlockTower();
        omOvlReturnEx(1);
    }
}

// decomp-permuter
void func_800F6C4C_KnockBlockTower(void)
{
  s32 i;
  s32 t;
  int new_var;
  for (i = 0; i < 4; i++)
  {
    if (GwPlayer[i].group == 0)
    {
      break;
      if (1)
      {
      }
    }
  }

  new_var = -(t = i < 4);
  i = i & new_var;
  i = i & new_var;
  D_800FB8EC_KnockBlockTower = i;
}

void func_800F6C98_KnockBlockTower(void) {
    KBTCpu* cpu;
    s32 i;

    cpu = D_800FB7E0_KnockBlockTower;
    for (i = 0; i < 4; i++, cpu++) {
        cpu->unk0 = 0;
        cpu->unk2 = 0;
        cpu->unk6 = 0;
        cpu->unkA = 0;
        cpu->unkC = 0;
        cpu->unkE = 0;
        cpu->unk10 = 0;
    }
    D_800FB7D8_KnockBlockTower = 0;
    D_800FB8D4_KnockBlockTower = 0;
    D_800FB7D0_KnockBlockTower = 0;
    D_800FB8DC_KnockBlockTower = -1;
    D_800FB850_KnockBlockTower = 0;
    CZoom = 3380.0f;
    CRot.x = 340.75f;
    CRot.y = -6.75f;
    CRot.z = 0.0f;
    Center.x = 40.0f;
    Center.y = 0.0f;
    Center.z = -1375.0f;
}

void func_800F6D74_KnockBlockTower(s32 arg0, u8 arg1, u32 time) {
    if (arg1 == 1) {
        func_80079078(time / 30);
    }
}

void func_800F6DB4_KnockBlockTower(void) {
}

void func_800F6DBC_KnockBlockTower(void) {
}

/* Camera: glide to the player, then a bounce on the zoom. */
void func_800F6DC4_KnockBlockTower(omObjData* obj) {
    f32 v;

    switch (D_800FB500_KnockBlockTower) {
    case 0:
        if (D_800FB84C_KnockBlockTower != 0) {
            Center.x += D_800FB8F4_KnockBlockTower;
            Center.y += D_800FB8E4_KnockBlockTower;
            Center.z += D_800FB848_KnockBlockTower;
            CZoom += D_800FB8E8_KnockBlockTower;
            D_800FB84C_KnockBlockTower--;
        } else {
            D_800FB500_KnockBlockTower = 7;
            D_800FB5B0_KnockBlockTower = CZoom;
            D_800FB5B4_KnockBlockTower = 0.0f;
            D_800FB5B8_KnockBlockTower = -120.0f;
        }
        break;
    case 1:
        obj->func_ptr = NULL;
        break;
    default:
        CZoom = D_800FB5B0_KnockBlockTower + D_800FB5B4_KnockBlockTower;
        if ((v = D_800FB5B4_KnockBlockTower += D_800FB5B8_KnockBlockTower) < 0.0f) {
            if (-v > 200.0f) {
                goto flip;
            }
        } else if (D_800FB5B4_KnockBlockTower > 200.0f) {
        flip:
            D_800FB5B8_KnockBlockTower = -D_800FB5B8_KnockBlockTower;
            D_800FB500_KnockBlockTower--;
        }
        break;
    }
}

// register allocation: frames in v1, retail v0 (masked 0, raw 2); tried if/else, s32/u16 frames, a ternary store
#ifdef NON_MATCHING
void func_800F6F64_KnockBlockTower(omObjData* obj) {
    omObjData* p = D_800F3FB0[0];
    s16 frames;

    frames = 33;
    if (D_800FB8D4_KnockBlockTower == 0) {
        frames = 20;
    }
    D_800FB84C_KnockBlockTower = frames;
    D_800FB8F4_KnockBlockTower = (p->trans.x - Center.x) / D_800FB84C_KnockBlockTower;
    D_800FB8E4_KnockBlockTower = (p->trans.y - Center.y + 50.0f) / D_800FB84C_KnockBlockTower;
    D_800FB848_KnockBlockTower = (p->trans.z - Center.z) / D_800FB84C_KnockBlockTower;
    D_800FB8E8_KnockBlockTower = (900.0f - CZoom) / D_800FB84C_KnockBlockTower;
    obj->func_ptr = &func_800F6DC4_KnockBlockTower;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_KnockBlockTower/19FEE0", func_800F6F64_KnockBlockTower);
#endif

void func_800F702C_KnockBlockTower(omObjData* obj, f32 scale, f32 y, s32 idx) {
    func_80025798(obj->model[idx], obj->trans.x, y + obj->trans.y, obj->trans.z);
    func_80025830(obj->model[idx], scale, scale, scale);
}

void func_800F70B0_KnockBlockTower(omObjData* obj) {
    u8 player = obj->work[0];
    KBTCpu* cpu = &D_800FB7E0_KnockBlockTower[player];

    if (GwPlayer[player].flags & 1) {
        cpu->unk0 |= 1;
        cpu->unk4 = GwPlayer[player].cpu_difficulty;
    }
}

s32 func_800F7114_KnockBlockTower(u16 player) {
    omObjData* obj;
    KBTPlayerWork* work;
    s32 flags;
    s32 ret;

    if (player >= D_800F2BC0) {
        return 0;
    }
    obj = D_800F3FB0[player];
    work = obj->unk_50;
    flags = func_80017A60(obj);
    ret = 0;
    if (work->unk_38 == 1000.0f) {
        ret = (flags & 6) != 0;
    }
    return ret;
}

void func_800F7198_KnockBlockTower(omObjData* coin, Vec3f* pos) {
    KBTCoinWork* work = coin->unk_50;

    if (work->unk_54 != 0) {
        func_800258EC(coin->model[3], 4, 0);
        func_8001E2A8(work->unk_21[3], 0);
        func_8001E268(work->unk_21[3], 4, 4);
        func_80025798(coin->model[3], pos->x, pos->y, pos->z);
        func_80025830(coin->model[3], 10.0f, 10.0f, 10.0f);
        work->unk_54 = 0;
        func_800090D8(coin, 0, 0);
        func_800090D8(coin, 1, 0);
    }
}

void func_800F725C_KnockBlockTower(void) {
    Vec3f pos;
    Vec3f* vp;
    omObjData* coin;
    s32 i;

    vp = &pos;
    for (i = 0; i < D_800EE984; i++) {
        coin = D_800EDE70[i];
        vp->x = coin->trans.x;
        vp->y = coin->trans.y;
        vp->z = coin->trans.z;
        func_800F7198_KnockBlockTower(coin, vp);
    }
}

KBTNode* func_800F72E8_KnockBlockTower(s32 id) {
    KBTNode* n = D_800FB650_KnockBlockTower[0].next;

    while (n->next != NULL) {
        if (id == n->id) {
            break;
        }
        n = n->next;
    }
    return n;
}

void func_800F7320_KnockBlockTower(omObjData* obj) {
    KBTStageWork* work = obj->unk_50;
    s32 i;

    for (i = 0; i < D_800F2BC0; i++) {
        func_800090C4(D_800F3FB0[i], work->unk_05, 1);
    }
}

/* Knocks the block `id` out of the tower. */
// register allocation: the found node is copied through v1 first (masked 3)
#ifdef NON_MATCHING
void func_800F7398_KnockBlockTower(omObjData* obj, s32 id) {
    KBTPlayerWork* work = obj->unk_50;
    KBTNode* n;
    KBTNode* prev;
    omObjData* o;

    KBTNode* next;

    if ((n = func_800F72E8_KnockBlockTower(id)) == NULL) {
        return;
    }
    next = n->next;
    prev = D_800FB650_KnockBlockTower;
    while (prev->next != n) {
        prev = prev->next;
    }
    prev->next = next;
    func_800258EC(n->obj->model[0], 4, 4);
    func_800F7320_KnockBlockTower(n->obj);
    func_800258EC(obj->model[10], 4, 0);
    func_8001E2A8(work->unk_21[10], 0);
    func_8001E268(work->unk_21[10], 4, 4);
    o = n->obj;
    func_80025798(obj->model[10], o->trans.x, o->trans.y, o->trans.z + 200.0f);
    func_80025830(obj->model[10], 5.0f, 5.0f, 5.0f);
    PlaySound(0x2B2);
    n->obj->func_ptr = NULL;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_KnockBlockTower/19FEE0", func_800F7398_KnockBlockTower);
#endif

/* Top of the block below `node` (0 at the bottom). */
f32 func_800F74BC_KnockBlockTower(KBTNode* node) {
    KBTNode* prev = D_800FB650_KnockBlockTower;

    while (prev->next != NULL) {
        if (prev->next->obj == node->obj) {
            break;
        }
        prev = prev->next;
        if (prev->next == NULL) {
            break;
        }
    }
    if (prev->obj == NULL) {
        return 0.0f;
    }
    return prev->obj->trans.y + 150.0f;
}

// register allocation: a0/v1 swapped in the list walks (masked 4)
#ifdef NON_MATCHING
void func_800F7524_KnockBlockTower(omObjData* obj) {
    Vec3f vec;
    Vec3f* vp;
    KBTNode* prev;
    KBTNode* n;
    f32 below;
    f32 top;
    f32 s;
    f32 d;

    vp = &vec;
    func_800A0D00(vp, D_800F3FB0[0]->trans.x, 0.0f, D_800F3FB0[0]->trans.z);
    vp->x -= obj->trans.x;
    vp->y -= 0.0f;
    vp->z -= obj->trans.z;
    func_800A1200(vp);
    prev = D_800FB650_KnockBlockTower;
    while (prev->next != NULL) {
        if (prev->next->obj == obj) {
            break;
        }
        prev = prev->next;
        if (prev->next == NULL) {
            break;
        }
    }
    n = prev->next;
    if (n != NULL) {
        below = -150.0f;
        if (prev->obj != NULL) {
            below = prev->obj->trans.y;
        }
        if (obj->trans.y < n->baseY + 150.0f && n->state == 2 && n->vel == 0.0f) {
            obj->trans.y += 5.0f;
        } else if (below < obj->trans.y - 150.0f) {
            n->vel += n->accel;
            obj->trans.y -= n->vel;
            if (obj->trans.y - 150.0f <= below) {
                if (n->type == 1 && n->state == 2) {
                    PlaySound(0x2B4);
                }
                obj->trans.y = below + 150.0f;
                n->vel = 0.0f;
                n->state = 1;
                n->baseY = obj->trans.y;
            }
        } else {
            obj->trans.y = below + 150.0f;
        }
    }
    if (n->type != 0 && n->amp0 > 0.0f) {
        n->obj->trans.x = func_800AEAC0(n->dir) * n->amp;
        n->obj->trans.z = func_800AEFD0(n->dir) * n->amp;
        n->angle -= 30.0f;
        n->amp = KBT_ABS(func_800AEFD0(n->angle) * n->amp0);
        if (n->angle < 0.0f) {
            n->angle = 180.0f;
            n->amp0 -= 10.0f;
        }
    } else {
        n->obj->trans.x = 0.0f;
        n->obj->trans.z = 0.0f;
    }
    if (n->type == 1) {
        if (n->state != 0) {
            prev = D_800FB650_KnockBlockTower;
            while (prev->next != NULL) {
                if (prev->next == n) {
                    break;
                }
                prev = prev->next;
                if (prev->next == NULL) {
                    break;
                }
            }
            top = 0.0f;
            if (prev->obj != NULL) {
                top = prev->obj->trans.y + 150.0f;
            }
            func_80009058(obj, 150.0f, obj->trans.y - top + 150.0f, -75.0f, -75.0f, 75.0f, 75.0f);
        }
        top = func_800F74BC_KnockBlockTower(n);
        func_80025798(obj->model[1], obj->trans.x, top + 1.0f, obj->trans.z);
        d = obj->trans.y - top;
        if (d > 200.0f) {
            s = 0.6f;
        } else {
            s = 0.8f - d / 2000.0001f;
        }
        func_80025830(obj->model[1], s, s, s);
    }
    if (n->state == 1) {
        n->state = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_KnockBlockTower/19FEE0", func_800F7524_KnockBlockTower);
#endif

/* Height of the tower top. */
f32 func_800F79BC_KnockBlockTower(void) {
    KBTNode* n = D_800FB650_KnockBlockTower;

    while (n->next->next != NULL) {
        n = n->next;
    }
    if (n->obj == NULL) {
        return 0.0f;
    }
    return n->obj->trans.y + 150.0f;
}

/* Win check: every block resting, the goal on the top and the player standing. */
s32 func_800F7A1C_KnockBlockTower(void) {
    KBTNode* first = D_800FB650_KnockBlockTower[0].next;
    omObjData* goal = D_800FB8D8_KnockBlockTower;
    omObjData* o = first->obj;

    if (o != NULL && o->trans.y == 0.0f && func_800F79BC_KnockBlockTower() == goal->trans.y &&
        D_800FB8DC_KnockBlockTower == -1 && (u8)func_800F7114_KnockBlockTower(0)) {
        return 1;
    }
    return 0;
}

/* Index of the first bomb block, -1 if none is left. */
s32 func_800F7ABC_KnockBlockTower(void) {
    KBTNode* n = D_800FB650_KnockBlockTower[0].next;
    s32 i = 0;
    s32 r;

    while (n->next != NULL) {
        if (n->type == 0) {
            break;
        }
        n = n->next;
        i++;
    }
    if (n->next == NULL) {
        return -1;
    }
    return i;
}

void func_800F7B04_KnockBlockTower(KBTNode* node) {
    Vec3f vec;

    func_800A0D00(&vec, -D_800F3FB0[0]->trans.x, 0.0f, -D_800F3FB0[0]->trans.z);
    node->dir = func_800B0CD8(vec.x, vec.z);
    node->amp = 0.0f;
    node->angle = 180.0f;
    node->amp0 = 30.0f;
    PlaySound(0x2B1);
}

// register allocation: v0/v1 in the final next test (masked 0)
#ifdef NON_MATCHING
s32 func_800F7B90_KnockBlockTower(s32 idx) {
    KBTNode* n = D_800FB650_KnockBlockTower[0].next;
    s32 i = 0;

    if ((n->next != NULL) & (idx != 0)) {
        do {
            i++;
            n = n->next;
        } while ((n->next != NULL) & (idx != i));
    }
    if (n->next != NULL) {
        return D_800FB8E0_KnockBlockTower->work[0] < 45;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_KnockBlockTower/19FEE0", func_800F7B90_KnockBlockTower);
#endif

s32 func_800F7BF8_KnockBlockTower(void) {
    return D_800FB8E0_KnockBlockTower->work[0] < 45;
}

s32 func_800F7C0C_KnockBlockTower(s32 base, s32 difficulty) {
    s32 n;
    s32 r;
    s32 v;

    switch (difficulty) {
    case 0:
        n = 5;
        break;
    case 1:
        n = 4;
        break;
    case 2:
        n = 3;
        break;
    default:
        n = (-((u8)((rand8() & 0xFF) % 100) < 50) & 3) | 2;
        break;
    }
    r = (rand8() & 0xFF) % n;
    v = base - n + r;
    if (v <= 0) {
        v = base + ((u32)r >> 1);
    }
    return v;
}

/* CPU input. */
void func_800F7D0C_KnockBlockTower(omObjData* obj) {
    Vec3f vec;
    Vec3f* vp;
    KBTPlayerWork* work;
    KBTCpu* cpu;
    u16 player;
    f32 angle;
    f32 dist;
    s32 r;

    work = obj->unk_50;
    player = obj->work[0];
    vp = &vec;
    cpu = &D_800FB7E0_KnockBlockTower[player];
    if (!(cpu->unk0 & 1)) {
        return;
    }
    if (D_800ED430 != 1) {
        return;
    }
    cpu->unkC = 0;
    cpu->unkA = 0;
    cpu->unkE = 0;
    ContBtn[GwPlayer[player].port] = 0;
    ContBtnTrg[GwPlayer[player].port] = 0;
    ContStkX[GwPlayer[player].port] = 0;
    ContStkY[GwPlayer[player].port] = 0;
    switch (cpu->unk2) {
    case 0:
        /* retail reloads the list head for each access */
        if (((volatile KBTNode*)D_800FB650_KnockBlockTower)->next->next != NULL) {
            angle = func_80029518(((volatile KBTNode*)D_800FB650_KnockBlockTower)->next->obj->rot.y - 90.0f);
            func_800A0D00(vp, func_800AEAC0(angle) * 130.0f, 0.0f, func_800AEFD0(angle) * 130.0f);
            vp->x -= obj->trans.x;
            vp->y -= 0.0f;
            vp->z -= obj->trans.z;
            dist = func_800A1200(vp);
        } else {
            dist = 0.0f;
        }
        if (dist > 10.0f) {
            angle = func_800B0CD8(vp->x, vp->z);
            cpu->unkA = func_800AEAC0(angle) * 60.0f * 0.7f;
            cpu->unkC = func_800AEFD0(angle) * 60.0f * 0.7f;
            break;
        }
        if (!(u8)func_800F7114_KnockBlockTower(0)) {
            break;
        }
        cpu->unk2 = 4;
    case 4:
        func_800A0D00(vp, -obj->trans.x, 0.0f, -obj->trans.z);
        angle = func_80029518(func_800B0CD8(vp->x, vp->z));
        cpu->unkA = func_800AEAC0(angle) * 60.0f;
        cpu->unkC = func_800AEFD0(angle) * 60.0f;
        if (KBT_ABS(func_80029518(work->unk_3C) - angle) < 5.0f) {
            cpu->unk2 = 1;
        }
        break;
    case 1:
        r = func_800F7ABC_KnockBlockTower();
        switch (r) {
        case 0:
            if (func_800F7B90_KnockBlockTower(0) == 0) {
                break;
            }
            goto jump;
        case 1:
            if (func_800F7B90_KnockBlockTower(1) != 0) {
                cpu->unkE |= 0x8000;
                cpu->unk10 |= 0x8000;
                cpu->unk8 = func_800F7C0C_KnockBlockTower(1, cpu->unk4);
                cpu->unk2 = 2;
            }
            break;
        case 2:
            if (func_800F7B90_KnockBlockTower(2) != 0) {
                cpu->unkE |= 0x8000;
                cpu->unk10 |= 0x8000;
                cpu->unk8 = func_800F7C0C_KnockBlockTower(10, cpu->unk4);
                cpu->unk2 = 2;
            }
            break;
        case -1:
            if (func_800F7BF8_KnockBlockTower() != 0) {
                cpu->unkE |= 0x8000;
                cpu->unk10 |= 0x8000;
                cpu->unk8 = 10;
                cpu->unk2 = 3;
            }
            break;
        }
        break;
    case 2:
        cpu->unkE = 0;
        if (cpu->unk8 == 0) {
            cpu->unk10 = 0;
        jump:
            cpu->unkE |= 0x4000;
            cpu->unk2 = 0;
        } else {
            cpu->unk8--;
        }
        break;
    case 3:
        cpu->unkE = 0;
        func_800A0D00(vp, -obj->trans.x, 0.0f, -obj->trans.z);
        angle = func_800B0CD8(vp->x, vp->z);
        cpu->unkA = func_800AEAC0(angle) * 60.0f;
        cpu->unkC = func_800AEFD0(angle) * 60.0f;
        if (cpu->unk8 == 0) {
            cpu->unk10 = 0;
            if ((u8)func_800F7114_KnockBlockTower(0) && work->unk_53 == 0) {
                cpu->unk2 = 0;
            }
        } else {
            cpu->unk8--;
        }
        break;
    }
    ContBtn[GwPlayer[player].port] = cpu->unk10;
    ContBtnTrg[GwPlayer[player].port] = cpu->unkE;
    ContStkX[GwPlayer[player].port] = cpu->unkA;
    ContStkY[GwPlayer[player].port] = -cpu->unkC;
}

void func_800F834C_KnockBlockTower(omObjData* obj) {
    if (--obj->work[0] == 0xFF) {
        func_80060540(GwPlayer[D_800FB8EC_KnockBlockTower].character + 0x45F, 0);
        obj->func_ptr = NULL;
    }
}

void func_800F83B8_KnockBlockTower(omObjData* obj) {
    obj->work[0] = 18;
    obj->func_ptr = &func_800F834C_KnockBlockTower;
}

/* The player. */
void func_800F83D0_KnockBlockTower(omObjData* obj) {
    s32 player;
    KBTPlayerWork* work;
    KBTCpu* cpu;
    KBTNode* n;
    f32 y;
    f32 floor;
    f32 v;
    f32 angle;
    f32 x;

    player = obj->work[0];
    work = obj->unk_50;
    cpu = &D_800FB7E0_KnockBlockTower[player];
    cpu->unk18 = ContBtn[GwPlayer[player].port];
    cpu->unk16 = ContBtnTrg[GwPlayer[player].port];
    cpu->unk12 = ContStkX[GwPlayer[player].port];
    cpu->unk14 = ContStkY[GwPlayer[player].port];
    func_800F7D0C_KnockBlockTower(obj);
    if ((ContBtnTrg[GwPlayer[player].port] & 0x4000) && !(func_80017A60(obj) & 0x140)) {
        obj->work[1] = 0;
    }
    if (D_800FB7D8_KnockBlockTower != 0) {
        ContBtn[GwPlayer[player].port] = 0;
        ContBtnTrg[GwPlayer[player].port] = 0;
        ContStkX[GwPlayer[player].port] = 0;
        ContStkY[GwPlayer[player].port] = 0;
    }
    if (obj->work[2] == 0) {
        ContStkY[GwPlayer[player].port] = 0;
        func_80005A28(obj);
        ContBtn[GwPlayer[player].port] = cpu->unk18;
        ContBtnTrg[GwPlayer[player].port] = cpu->unk16;
        ContStkX[GwPlayer[player].port] = cpu->unk12;
        ContStkY[GwPlayer[player].port] = cpu->unk14;
    } else {
        y = obj->trans.y;
        if (work->unk_38 < 1000.0f) {
            v = work->unk_38;
            if (v > 2.0f) {
                v = 2.0f;
            }
            y += v * v * ((work->unk_38 >= 0.0f) ? -35.0f : 35.0f);
            KBT_FLOOR(floor, obj);
            if (y < floor) {
                work->unk_38 = 1000.0f;
                y = floor;
            }
            work->unk_38 += D_800B8968;
        } else {
            KBT_FLOOR(floor, obj);
            if (floor < y) {
                work->unk_38 = 0.0f;
            }
            if (y < floor) {
                y = floor;
            }
        }
        obj->trans.y = y;
        KBT_FLOOR(floor, obj);
        func_80025798(obj->model[1], obj->trans.x, floor + 1.0f, obj->trans.z);
        func_80017DB0(obj);
    }
    if (work->unk_55 != -1 && D_800FB8DC_KnockBlockTower == -1) {
        n = func_800F72E8_KnockBlockTower(work->unk_55);
        if (n->next == NULL) {
            return;
        }
        if (obj->work[1] == 0) {
            obj->work[1] = 1;
            n->unkE = work->unk_55;
            angle = work->unk_3C;
            x = func_800AEAC0(angle) * work->unk_64 + obj->trans.x;
            func_80017C0C(obj, 6, x, obj->trans.y + 50.0f, func_800AEFD0(angle) * work->unk_64 + obj->trans.z,
                          0.0f, angle);
            if (n->type == 0) {
                work->unk_40 = 0.0f;
                func_800F7398_KnockBlockTower(obj, work->unk_55);
            } else if (obj->trans.y + 110.0f > n->obj->trans.y) {
                omAddObj(0xA, 0, 0, -1, &func_800F83B8_KnockBlockTower);
                func_800184BC(obj, 0x1E);
                work->unk_40 = -45.0f;
                work->unk_38 = -1.6f;
                func_800F7320_KnockBlockTower(D_800F2AF8[1]);
                func_80060F04(work->unk_58, 20, 0, 20);
                func_800F7B04_KnockBlockTower(n);
            } else {
                work->unk_40 = 0.0f;
            }
        } else {
            work->unk_40 = 0.0f;
        }
    }
    if (obj->trans.y < -500.0f && D_800ED430 == 1) {
        D_800FB850_KnockBlockTower = 1;
        func_800601D4(0x28);
        D_800FB8D4_KnockBlockTower = 2;
        func_80009438();
    }
    if (obj->trans.y < -2000.0f) {
        obj->trans.y = -2000.0f;
        func_800258EC(obj->model[0], 4, 4);
        func_800258EC(obj->model[1], 4, 4);
        obj->func_ptr = NULL;
    }
}

/* The goal after a win: the player takes it. */
void func_800F8BEC_KnockBlockTower(omObjData* obj) {
    Vec3f unused; /* retail's frame has room for it */
    omObjData* player;
    KBTPlayerWork* work;
    omObjData* goal;
    s16 mdl;
    f32 floor;

    player = D_800F3FB0[0];
    work = player->unk_50;
    switch (obj->work[1]) {
    case 0:
        obj->work[1] = 1;
        break;
    case 1:
        func_8006BADC(D_800FB8D8_KnockBlockTower, player->trans.x, player->trans.y, player->trans.z);
        func_8006BAF0(D_800FB8D8_KnockBlockTower, 1);
        obj->work[1] = 2;
        break;
    case 2:
        mdl = D_800FB8D8_KnockBlockTower->model[0];
        if (func_80025D18(mdl) >= func_80025D40(mdl)) {
            obj->work[2] = 10;
            obj->work[1] = 3;
        }
        break;
    case 3:
        if (obj->work[2] == 0) {
            func_800790C0();
            GMesCreate(2);
            func_800790C0();
            obj->work[1] = 4;
        }
        obj->work[2]--;
        break;
    case 4:
        if (GMesStatAllGet() == 0 || (GMesStatAllGet() & 2)) {
            if (_CheckFlag(0x2B) == 0) {
                func_80060128(0x33);
                func_800184BC(player, 0xD);
                omAddObj(0xA, 0, 0, -1, &func_800F6F64_KnockBlockTower);
                work->unk_3C = CRot.y;
                func_8009ECB0(D_800F2B7C[player->model[0]].unk7C, 0.0f, work->unk_3C, 0.0f);
            }
            obj->work[1] = 5;
        }
        break;
    case 5:
        if (func_8006BAFC(D_800FB8D8_KnockBlockTower) == 0) {
            obj->work[1] = 6;
        }
        break;
    case 6:
        D_800FB850_KnockBlockTower = 1;
        break;
    }
    KBT_FLOOR(floor, D_800FB8D8_KnockBlockTower);
    goal = D_800FB8D8_KnockBlockTower;
    func_80025798(goal->model[1], goal->trans.x, floor + 1.0f, goal->trans.z);
    func_80025830(D_800FB8D8_KnockBlockTower->model[1], 0.5f, 0.5f, 0.5f);
}

/* Goal shake after a bomb hit. */
void func_800F8F28_KnockBlockTower(omObjData* obj) {
    f32 x = func_800AEAC0(obj->work[0]) * obj->work[1];

    D_800FB8D8_KnockBlockTower->trans.x = x + D_800FB5BC_KnockBlockTower;
    obj->work[0] += 30;
    if (obj->work[0] >= 181) {
        obj->work[0] += 76;
        obj->work[1] >>= 1;
        obj->work[2]--;
        if (obj->work[2] == 0) {
            omDelObj(obj);
            D_800FB8D8_KnockBlockTower->trans.x = D_800FB5BC_KnockBlockTower;
        }
    }
}

void func_800F8FE8_KnockBlockTower(omObjData* obj) {
    D_800FB5BC_KnockBlockTower = D_800FB8D8_KnockBlockTower->trans.x;
    obj->work[0] = 0;
    obj->work[1] = 20;
    obj->work[2] = 4;
    obj->func_ptr = &func_800F8F28_KnockBlockTower;
}

/* The goal: falls with the tower; touching it wins. */
// scheduling: retail fills the delay slot after the last 1000.0f test with a nop, not func_8009EA40's a1 (masked ~3)
#ifdef NON_MATCHING
void func_800F9020_KnockBlockTower(omObjData* obj) {
    Vec3f vec;
    Vec3f* vp;
    KBTThwompWork* gw;
    KBTPlayerWork* work;
    omObjData* p;
    KBTNode* n;
    s32 i;
    f32 x;
    f32 y;
    f32 z;
    f32 floor;
    f32 v;

    gw = obj->unk_50;
    vp = &vec;
    if (D_800FB8DC_KnockBlockTower == -1) {
        for (i = 0; i < D_800F2BC0; i++) {
            p = D_800F3FB0[i];
            work = p->unk_50;
            vp->x = D_800FB8D8_KnockBlockTower->trans.x - p->trans.x;
            vp->y = D_800FB8D8_KnockBlockTower->trans.y - p->trans.y;
            vp->z = D_800FB8D8_KnockBlockTower->trans.z - p->trans.z;
            if (func_800A1200(vp) <= work->unk_48 + 30.0f) {
                work->unk_38 = -1.5f;
                work->unk_40 = -10.0f;
                D_800FB8DC_KnockBlockTower = i;
                func_800601D4(0x28);
                D_800FB8D4_KnockBlockTower = 0;
                func_80060F04(work->unk_58, 20, 0, 20);
                omAddObj(100, 0, 0, -1, &func_800F8FE8_KnockBlockTower);
                func_80009438();
            }
        }
    } else {
        n = D_800FB650_KnockBlockTower[0].next;
        while (n->next != NULL) {
            if (n->vel != 0.0f || n->state == 2) {
                break;
            }
            n = n->next;
        }
        work = D_800F3FB0[0]->unk_50;
        if (n->next == NULL && gw->unk_38 == 1000.0f && work->unk_38 == 1000.0f) {
            obj->work[1] = 0;
            obj->work[2] = 0;
            obj->func_ptr = &func_800F8BEC_KnockBlockTower;
            func_8009EA40(D_800F2B7C[D_800FB8D8_KnockBlockTower->model[0]].unk7C, 0.0f, 50.0f, 0.0f);
        }
    }
    x = D_800FB8D8_KnockBlockTower->trans.x;
    y = D_800FB8D8_KnockBlockTower->trans.y;
    z = D_800FB8D8_KnockBlockTower->trans.z;
    if (D_800FB7D0_KnockBlockTower == 0) {
        D_800ED6B8 = D_800F5254 = 0.0f;
        if (gw->unk_38 < 1000.0f) {
            v = gw->unk_38;
            if (v > 2.0f) {
                v = 2.0f;
            }
            y += v * v * ((gw->unk_38 >= 0.0f) ? -35.0f : 35.0f);
            floor = func_800F79BC_KnockBlockTower();
            if (y < floor) {
                gw->unk_38 = 1000.0f;
                y = floor;
            } else {
                gw->unk_38 += D_800B8968;
            }
        } else {
            v = func_800F79BC_KnockBlockTower();
            if (v < y) {
                gw->unk_38 = 0.0f;
            }
            if (y < v) {
                y = v;
            }
            floor = v;
        }
        func_8006B9B0(D_800FB8D8_KnockBlockTower, x + D_800ED6B8, y, z + D_800F5254);
    } else {
        KBT_FLOOR(floor, D_800FB8D8_KnockBlockTower);
    }
    func_80025798(D_800FB8D8_KnockBlockTower->model[1], D_800FB8D8_KnockBlockTower->trans.x, floor + 1.0f,
                  D_800FB8D8_KnockBlockTower->trans.z);
    func_80025830(D_800FB8D8_KnockBlockTower->model[1], 0.5f, 0.5f, 0.5f);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_KnockBlockTower/19FEE0", func_800F9020_KnockBlockTower);
#endif

/* .rodata tail (0x800FB598): zero padding in the retail object */
const s32 D_800FB598_KnockBlockTower[2] = { 0, 0 };
