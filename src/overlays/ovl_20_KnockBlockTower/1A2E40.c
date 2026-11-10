#include "common.h"
#include "19FEE0.h"

/* .data (0x800FB510..0x800FB540) */
s32 D_800FB510_KnockBlockTower = 0;
u32 D_800FB514_KnockBlockTower = 329;
s32 D_800FB518_KnockBlockTower = 0;
s32 D_800FB51C_KnockBlockTower = 0;
u32 D_800FB520_KnockBlockTower = 0;
u32 D_800FB524_KnockBlockTower = 0;
s32 D_800FB528_KnockBlockTower = 0;
u32 D_800FB52C_KnockBlockTower = 0;
s32 D_800FB530_KnockBlockTower = 0;
s32 D_800FB534_KnockBlockTower[3] = { 0, 0, 0 }; /* unreferenced */

#define KBT_ABS(x) (((x) < 0.0f) ? -(x) : (x))

/* The game flow (stage object). */
// scheduling: one unfilled delay slot in case 3's compare tree, v0/v1 swapped on D_800FB52C (masked ~39, mostly branch offsets)
#ifdef NON_MATCHING
void func_800F9540_KnockBlockTower(omObjData* obj) {
    omObjData* p;
    KBTPlayerWork* work;
    KBTPlayerWork* w2;
    s32 t;

    p = D_800F3FB0[0];
    work = p->unk_50;
    func_80009468();
    switch (D_800ED430) {
    case 0:
        if (func_80072718() == 0) {
            if (D_800FB510_KnockBlockTower == 0) {
                D_800FB510_KnockBlockTower = 1;
                func_80060128(0x1E);
                GMesCreate(0);
            }
            if (GMesStatAllGet() == 0) {
                GMesCreate(8, 0x1E, 0xA0, 0x18);
                func_80009458();
            }
        }
        func_80079078(D_800FB514_KnockBlockTower / 30);
        break;
    case 1:
        if (D_800FB514_KnockBlockTower != 0) {
            func_80079078(D_800FB514_KnockBlockTower / 30);
            D_800FB514_KnockBlockTower--;
            break;
        }
        if (D_800FB7D8_KnockBlockTower == 0) {
            D_800FB7D8_KnockBlockTower = 1;
            func_800601D4(0x28);
        }
        if (func_800F7A1C_KnockBlockTower() != 0 && D_800FB530_KnockBlockTower == 0) {
            D_800FB530_KnockBlockTower = 1;
            if (_CheckFlag(0x2B) != 0) {
                GMesCreate(2);
            } else {
                GMesCreate(0x10);
            }
            func_800790C0();
            PlaySound(0x2B6);
            D_800FB7D0_KnockBlockTower = 1;
            D_800FB8D0_KnockBlockTower->func_ptr = &func_800FA0C4_KnockBlockTower;
        }
        break;
    case 2:
        if (D_800FB850_KnockBlockTower == 0) {
            break;
        }
        if (D_800FB8D4_KnockBlockTower == 1 && (p = D_800F3FB0[0])->trans.y >= 0.0f && work->unk_38 != 1000.0f) {
            break;
        }
        if (D_800FB518_KnockBlockTower == 0) {
            D_800FB518_KnockBlockTower = 1;
            switch (D_800FB8D4_KnockBlockTower) {
            case 0:
                GwPlayer[work->unk_58].coins_mg += 10;
                break;
            case 1:
                GwPlayer[work->unk_58].coins_mg -= 5;
                break;
            case 2:
                GwPlayer[work->unk_58].coins_mg -= 5;
                if (_CheckFlag(0x2B) != 0) {
                    GMesCreate(2);
                } else {
                    GMesCreate(0xE);
                }
                func_800790C0();
                break;
            }
        }
        if (GMesStatAllGet() != 0 && !(GMesStatAllGet() & 2)) {
            break;
        }
        if (D_800FB51C_KnockBlockTower == 0) {
            D_800FB51C_KnockBlockTower = 1;
            if (_CheckFlag(0x2B) == 0 && (t = D_800FB8D4_KnockBlockTower) < 3) {
                if (D_800FB8D4_KnockBlockTower != 0) {
                    func_80060128(0x34);
                }
            }
        }
        if (D_800FB524_KnockBlockTower < 3 && D_800FB8D4_KnockBlockTower == 1) {
            if (D_800FB524_KnockBlockTower++ < 2) {
                break;
            }
            w2 = p->unk_50;
            if (_CheckFlag(0x2B) == 0) {
                func_800184BC(p, 0xE);
                omAddObj(0xA, 0, 0, -1, &func_800F6F64_KnockBlockTower);
                w2->unk_3C = CRot.y;
                func_8009ECB0(D_800F2B7C[p->model[0]].unk7C, 0.0f, w2->unk_3C, 0.0f);
            }
        }
        if (_CheckFlag(0x2B) == 0) {
            switch (D_800FB8D4_KnockBlockTower) {
            case 0:
                if (D_800FB520_KnockBlockTower++ < 36) {
                    return;
                }
                func_80060540(GwPlayer[D_800FB8EC_KnockBlockTower].character + 0x451, 0);
                break;
            case 1:
                if (D_800FB520_KnockBlockTower++ < 18) {
                    return;
                }
                func_80060540(GwPlayer[D_800FB8EC_KnockBlockTower].character + 0x44A, 0);
                break;
            case 2:
                break;
            }
        }
        func_80009448();
        break;
    case 3:
        switch (D_800FB528_KnockBlockTower) {
        case 0:
            if (_CheckFlag(0x2B) == 0) {
                switch (D_800FB8D4_KnockBlockTower) {
                case 0:
                    t = D_800FB52C_KnockBlockTower++ < 57;
                    break;
                case 1:
                    t = D_800FB52C_KnockBlockTower++ < 72;
                    break;
                case 2:
                    t = D_800FB52C_KnockBlockTower++ < 90;
                    break;
                default:
                    goto proceed;
                }
            } else {
                t = D_800FB52C_KnockBlockTower++ < 20;
            }
            if (t != 0) {
                break;
            }
        proceed:
            if (_CheckFlag(0x2B) == 0 || GMesWait() != 1) {
                func_800726AC(0, 0x14);
                D_800FB528_KnockBlockTower = 1;
            }
            break;
        case 1:
            if (func_80072718() == 0) {
                func_8002890C(0, 0, 0);
                func_800FB250_KnockBlockTower();
                omOvlReturnEx(1);
            }
            break;
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_KnockBlockTower/1A2E40", func_800F9540_KnockBlockTower);
#endif

/* The stage. */
void func_800F9BD0_KnockBlockTower(omObjData* obj) {
    KBTStageWork* w;

    obj->model[0] = func_800174C0(0x330001, 0x69D);
    obj->model[1] = func_800174C0(0x170000, 0x699);
    obj->model[2] = func_800174C0(0x170006, 0x699);
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    w = func_80023684(0x2C, 0x7918);
    obj->unk_50 = w;
    func_8009B770(w, 0, 0x2C);
    obj->func_ptr = &func_800F9540_KnockBlockTower;
    w->unk_04 = 1;
    func_80008FB8(obj, 0.5f);
    w->unk_05 = 0;
}

void func_800F9C98_KnockBlockTower(omObjData* obj) {
    KBTStageWork* w;

    obj->model[0] = func_800174C0(0x330002, 0x69D);
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    w = func_80023684(0x2C, 0x7918);
    obj->unk_50 = w;
    func_8009B770(w, 0, 0x2C);
    obj->func_ptr = NULL;
    w->unk_04 = 1;
    func_80008FB8(obj, 0.5f);
    func_80009090(obj);
    w->unk_05 = 1;
}

/* A plain block. */
// register allocation: the work block reaches obj->unk_50 through s3 (masked 2)
#ifdef NON_MATCHING
void func_800F9D3C_KnockBlockTower(omObjData* obj) {
    KBTStageWork* w;
    KBTNode* n;
    s32 i;

    obj->model[0] = func_800174C0(0x330000, 0xA99);
    obj->unk_50 = func_80023684(0x2C, 0x7918);
    w = obj->unk_50;
    func_8009B770(w, 0, 0x2C);
    obj->func_ptr = &func_800F7524_KnockBlockTower;
    n = D_800FB650_KnockBlockTower[0].next;
    i = 0;
    while (n->next != NULL) {
        if (n->obj == obj) {
            break;
        }
        n = n->next;
        i++;
    }
    if (n->type == -1) {
        while (1) {
        }
    }
    obj->work[0] = i;
    obj->trans.x = obj->trans.z = 0.0f;
    obj->trans.y = n->baseY = i * 150.0f;
    w->unk_04 = 1;
    func_80008FB8(obj, 0.5f);
    func_80009058(obj, 150.0f, 150.0f, -75.0f, -75.0f, 75.0f, 75.0f);
    func_80009090(obj);
    w->unk_05 = n->id = i + 2;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_KnockBlockTower/1A2E40", func_800F9D3C_KnockBlockTower);
#endif

/* A bomb block. */
// register allocation: the work block reaches obj->unk_50 through s3 (masked 2)
#ifdef NON_MATCHING
void func_800F9EA0_KnockBlockTower(omObjData* obj) {
    KBTStageWork* w;
    KBTNode* n;
    s32 i;

    obj->model[0] = func_800174C0(0x4F, 0xA99);
    obj->model[1] = func_800174C0(0x10, 0xA99);
    obj->unk_50 = func_80023684(0x2C, 0x7918);
    w = obj->unk_50;
    func_8009B770(w, 0, 0x2C);
    obj->func_ptr = &func_800F7524_KnockBlockTower;
    n = D_800FB650_KnockBlockTower[0].next;
    i = 0;
    while (n->next != NULL) {
        if (n->obj == obj) {
            break;
        }
        n = n->next;
        i++;
    }
    if (n->type == -1) {
        while (1) {
        }
    }
    obj->work[0] = i;
    obj->trans.x = obj->trans.z = 0.0f;
    obj->trans.y = n->baseY = i * 150.0f;
    func_80009058(obj, 150.0f, 150.0f, -75.0f, -75.0f, 75.0f, 75.0f);
    func_80009090(obj);
    w->unk_04 = 1;
    func_80008FB8(obj, 0.5f);
    w->unk_05 = n->id = i + 2;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_20_KnockBlockTower/1A2E40", func_800F9EA0_KnockBlockTower);
#endif

/* The goal's physics object. */
void func_800FA010_KnockBlockTower(omObjData* obj) {
    KBTThwompWork* w;

    obj->unk_50 = func_80023684(0x6C, 0x7918);
    func_8009B770(obj->unk_50, 0, 0x6C);
    w = obj->unk_50;
    func_8006B9B0(D_800FB8D8_KnockBlockTower, 0.0f, func_800F79BC_KnockBlockTower(), 0.0f);
    func_8006BAD0(D_800FB8D8_KnockBlockTower, func_800F79BC_KnockBlockTower());
    w->unk_3C = 0.0f;
    w->unk_40 = D_800B8990;
    w->unk_38 = 0.0f;
    obj->work[0] = 0;
    obj->work[1] = 0;
    obj->func_ptr = &func_800F9020_KnockBlockTower;
}

/* The Thwomp that knocks the goal off a finished tower. */
void func_800FA0C4_KnockBlockTower(omObjData* obj) {
    Vec3f vec;
    Vec3f* vp;
    omObjData* goal;
    omObjData* p;
    KBTPlayerWork* work;
    f32 floor;
    f32 d;
    f32 s;

    vp = &vec;
    goal = D_800FB8D8_KnockBlockTower;
    p = D_800F3FB0[0];
    work = p->unk_50;
    switch (obj->work[0]) {
    case 0:
        func_800258EC(obj->model[0], 4, 0);
        func_800258EC(obj->model[1], 4, 0);
        obj->trans.x = goal->trans.x + 920.0f + 50.0f;
        obj->trans.y = goal->trans.y + 0.0f;
        obj->trans.z = goal->trans.z;
        obj->work[0] = 1;
    case 1:
        obj->trans.x -= 40.0f;
        if (obj->trans.x <= goal->trans.x + 50.0f) {
            obj->trans.x = goal->trans.x + 50.0f;
            D_800FB5C0_KnockBlockTower = obj->trans.y;
            obj->work[0] = 2;
        }
        break;
    case 2:
        if (obj->trans.x < -900.0f) {
            func_800258EC(obj->model[0], 4, 4);
            func_800258EC(obj->model[1], 4, 4);
            func_800F725C_KnockBlockTower();
            D_800FB850_KnockBlockTower = 1;
            D_800FB8D4_KnockBlockTower = 1;
            func_80009438();
            obj->func_ptr = NULL;
        } else {
            obj->trans.x -= 40.0f;
            obj->trans.y = D_800FB5C0_KnockBlockTower + (1.0 - func_800AEFD0(obj->work[1])) * 500.0;
            obj->work[1] += 8;
            goal->trans.x = obj->trans.x - 50.0f;
            goal->trans.y = obj->trans.y;
            goal->trans.z = obj->trans.z;
            func_80025798(goal->model[0], goal->trans.x, goal->trans.y, goal->trans.z);
        }
        break;
    }
    func_800A0D00(vp, obj->trans.x, obj->trans.y, obj->trans.z);
    vp->x -= p->trans.x;
    vp->y -= p->trans.y;
    vp->z -= p->trans.z;
    if (func_800A1200(vp) < work->unk_48 + 40.0f) {
        func_800184BC(p, 0x1E);
        work->unk_3C = func_800B0CD8(vp->x, vp->z);
        work->unk_40 = -35.0f;
        work->unk_38 = -1.6f;
    }
    floor = 0.0f;
    if (KBT_ABS(obj->trans.x) < 75.0f && KBT_ABS(obj->trans.z) < 75.0f) {
        floor = func_800F79BC_KnockBlockTower();
    }
    func_80025798(obj->model[1], obj->trans.x, floor + 1.0f, obj->trans.z);
    d = obj->trans.y - floor;
    if (d > 200.0f) {
        s = 0.6f;
    } else {
        s = 0.8f - d / 2000.0001f;
    }
    func_80025830(obj->model[1], s, s, s);
}

/* Thwomp setup. */
void func_800FA560_KnockBlockTower(omObjData* obj) {
    obj->model[0] = LoadFormFile(0x6A, 0xA9D);
    obj->model[1] = func_800174F4(6, 0xA9D);
    D_800FB8D0_KnockBlockTower = obj;
    obj->func_ptr = NULL;
    func_80025EB4(obj->model[0], 2, 2);
    obj->trans.x = obj->trans.z = obj->trans.y = 0.0f;
    obj->rot.y = 270.0f;
    obj->work[0] = 0;
    obj->work[1] = 0;
}

void func_800FA5F4_KnockBlockTower(omObjData* obj, s32 arg1, s32 arg2, u16 player, Vec3f* pos) {
    KBTPlayerWork* w;

    func_80009618(0);
    func_8000979C(obj, arg1, arg2, player, 0xA99, 0xA99);
    obj->model[3] = LoadFormFile(0x19, 0xA8D);
    obj->model[4] = LoadFormFile(0x1A, 0xA8D);
    obj->model[7] = LoadFormFile(0x1E, 0xA8D);
    obj->model[6] = LoadFormFile(0x1B, 0xA8D);
    func_80009340(obj, 0xA, 0x26, 0x1A8D, 8);
    w = obj->unk_50;
    func_800187D0(obj, 0, arg1, 1, 0);
    func_800187D0(obj, 1, arg1 | 1, 1, 0);
    func_800187D0(obj, 2, arg1 | 3, 1, 0);
    func_800187D0(obj, 5, arg1 | 4, 0, 0);
    func_800187D0(obj, 7, arg1 | 4, 1, 0x22);
    func_800187D0(obj, 6, arg1 | 5, 1, 0x13);
    func_800187D0(obj, 0xD, arg1 | 0x38, 1, 0x78);
    func_800187D0(obj, 0xE, arg1 | 0x3C, 1, 0x78);
    func_800187D0(obj, 0x11, arg1 | 0x18, 0, 0);
    func_800187D0(obj, 0x15, arg1 | 0x62, 0, 0);
    func_800187D0(obj, 3, arg1 | 0x60, 1, 0);
    func_800187D0(obj, 4, arg1 | 0x61, 1, 0);
    func_800187D0(obj, 0x1E, arg1 | 0x63, 1, 0);
    func_800187D0(obj, 0x20, arg1 | 0x67, 0, 0);
    func_800090C4(obj, 0, 2);
    func_800090C4(obj, 2, 2);
    func_800090C4(obj, 3, 2);
    func_800090C4(obj, 4, 2);
    func_800090C4(obj, 5, 2);
    func_800090C4(obj, 6, 2);
    func_800090C4(obj, 7, 2);
    obj->work[0] = player;
    obj->work[1] = 0;
    obj->work[2] = 0;
    func_800F70B0_KnockBlockTower(obj);
    obj->trans.x = pos->x;
    obj->trans.y = pos->y;
    obj->trans.z = pos->z;
    func_800F702C_KnockBlockTower(obj, 1.0f, 0.0f, 1);
    obj->func_ptr = &func_800F83D0_KnockBlockTower;
    w->unk_56 = GwPlayer[player].port;
    w->unk_52 = 0;
}

void func_800FA92C_KnockBlockTower(omObjData* obj) {
    Vec3f pos;
    Vec3f* vp;
    u8 chr;

    vp = &pos;
    vp->x = -200.0f;
    vp->y = 0.0f;
    vp->z = 0.0f;
    chr = GwPlayer[D_800FB8EC_KnockBlockTower].character;
    func_800FA5F4_KnockBlockTower(obj, D_800C59AC[chr].unk_00, D_800C59AC[chr].unk_04, D_800FB8EC_KnockBlockTower,
                                  vp);
}
