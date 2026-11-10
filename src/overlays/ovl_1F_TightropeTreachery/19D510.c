#include "common.h"
#include "TightropeTreachery.h"

void func_80008FA0(omObjData*, f32);

/* A bomb that reaches a team member stuns it (D_800FE700 entries other than `obj`). */
s8 func_800FBCD0_TightropeTreachery(omObjData* obj) {
    s8 hit = 0;
    s8 i;

    for (i = 0; i < 3; i++) {
        omObjData* o = D_800FE700_TightropeTreachery[i];
        f32 dx;
        f32 dy;
        f32 dz;

        if (o == obj) {
            continue;
        }
        if (o == NULL) {
            continue;
        }
        dx = obj->trans.x - o->trans.x;
        dy = obj->trans.y - o->trans.y;
        dz = obj->trans.z - o->trans.z;
        if (dx * dx + dy * dy + dz * dz < 12100.0f) {
            TTTeamWork* t = TT_WORK(o)->unk_E4;

            t->flash = 50;
            func_80060F04(t->player, 30, 0, 30);
            hit = 1;
            break;
        }
    }
    return hit;
}

/* Bomb, model caches and start positions. */
void func_800FBDB8_TightropeTreachery(void) {
    s16 i;
    u32 r;
    s32 a;
    s32 b;
    u8 tmp;

    for (i = 0; i < 3; i++) {
        D_800FE720_TightropeTreachery[i].active = 0;
    }
    for (i = 0; i < 8; i++) {
        D_800FE6E0_TightropeTreachery[i] = -1;
    }
    for (i = 0; i < 3; i++) {
        D_800FE6F0_TightropeTreachery[i] = -1;
    }
    func_800F9450_TightropeTreachery();
    func_800F9450_TightropeTreachery();
    for (i = 0; i < 4; i++) {
        D_800FE8AC_TightropeTreachery[i] = i;
    }
    /* shuffles the start spots */
    for (i = 0; i < 10; i++) {
        r = func_800F9450_TightropeTreachery();
        a = (r >> 16) & 3;
        tmp = D_800FE8AC_TightropeTreachery[a];
        b = r & 3;
        D_800FE8AC_TightropeTreachery[a] = D_800FE8AC_TightropeTreachery[b];
        D_800FE8AC_TightropeTreachery[b] = tmp;
    }
}

/* A bomb is thrown: it flies from its team member's position along its facing. */
void func_800FBF38_TightropeTreachery(omObjData* obj) {
    TTBomb* b = ((TTItemWork*)obj->unk_50)->bomb;
    omObjData* thrower = D_800FE700_TightropeTreachery[b->idx];
    s16 i;
    f32 dx;
    f32 dz;
    f32 d;

    for (i = 0; i < 3; i++) {
        if (obj != NULL) {
            func_800258EC(obj->model[i], 4, 0);
            func_800258EC(obj->model[1], 4, 4);
        }
    }
    b->vy = 0.0f;
    b->timer = 0;
    b->ang = thrower->rot.y;
    b->dir[0] = func_800AEAC0(b->ang);
    b->dir[1] = 0.0f;
    b->dir[2] = func_800AEFD0(b->ang);
    b->pos[0] = thrower->trans.x;
    b->pos[1] = thrower->trans.y;
    b->pos[2] = thrower->trans.z;
    b->pos[0] = b->dir[0] * 100.0f + b->pos[0];
    b->pos[1] = b->pos[1] + 50.0f;
    b->pos[2] = b->dir[2] * 100.0f + b->pos[2];
    obj->trans.x = b->pos[0];
    obj->trans.y = b->pos[1];
    obj->trans.z = b->pos[2];
    dx = b->pos[0] - D_800F3FB0[0]->trans.x;
    dz = b->pos[2] - D_800F3FB0[0]->trans.z;
    d = sqrtf(dx * dx + dz * dz) / 20.0f;
    b->speed = d + (f32)(guRandom() % 10) - 5.0f;
    func_8001E2A8(b->mdl[0], 0);
    func_800258EC(obj->model[3], 4, 0);
    func_80025798(obj->model[3], obj->trans.x, obj->trans.y, obj->trans.z);
    b->lit = 1;
}

/* A thrown bomb's flight: splashes in the water, or explodes on the rope or a team member. */
// register allocation of the rope-hit flag (masked ~3)
#ifdef NON_MATCHING
void func_800FC180_TightropeTreachery(omObjData* obj) {
    TTPlayerWork* w = D_800F3FB0[0]->unk_50;
    TTBomb* b = ((TTItemWork*)obj->unk_50)->bomb;
    s16 i;
    s32 rope;
    f32 rx;

    if (b != NULL) {
        for (i = 0; i < 3; i++) {
            b->pos[i] = b->dir[i] * b->speed + b->pos[i];
        }
    }
    b->pos[1] = b->vy + 108.0f + b->pos[1];
    obj->trans.x = b->pos[0];
    obj->trans.y = b->pos[1];
    obj->trans.z = b->pos[2];
    b->vy = b->vy - 10.0f;
    for (i = 0; i < 3; i++) {
        func_80025798(obj->model[i], b->pos[0], b->pos[1], b->pos[2]);
    }
    rope = 0;
    if (obj->trans.y < -650.0f) {
        PlaySound(0x2AB);
        b->active = 0;
        b->lit = 0;
        for (i = 0; i < 6; i++) {
            func_800258EC(obj->model[i], 4, 4);
        }
        func_8001E2A8(b->mdl[1], 0);
        func_800258EC(obj->model[4], 4, 0);
        rope = 0;
        func_80025798(obj->model[4], obj->trans.x, obj->trans.y, obj->trans.z);
        obj->trans.x = obj->trans.y = obj->trans.z = 1000.0f;
    }
    rx = D_800FE714_TightropeTreachery[0] * 70.0f * func_800AEFD0((obj->trans.z - -1100.0f + 2500.0f) * 90.0 / 5000.0) +
         D_800FE70C_TightropeTreachery;
    if (obj->trans.x < rx + 75.0f && rx + -75.0f < obj->trans.x && obj->trans.y < -30.0f && obj->trans.y > -125.0) {
        rope = 1;
    }
    if (rope == 1 || func_800FBCD0_TightropeTreachery(obj) == 1) {
        PlaySound(0x2AC);
        b->active = 0;
        b->lit = 0;
        for (i = 0; i < 6; i++) {
            func_800258EC(obj->model[i], 4, 4);
        }
        func_8001E2A8(b->mdl[2], 0);
        func_800258EC(obj->model[5], 4, 0);
        func_80025798(obj->model[5], obj->trans.x, obj->trans.y, obj->trans.z);
        if (rope == 1) {
            if (D_800FE2BD_TightropeTreachery == 0) {
                func_80060F04(w->player, 20, 0, 20);
            }
            D_800FE301_TightropeTreachery = 1;
            D_800FE302_TightropeTreachery = 0;
        }
        obj->trans.x = obj->trans.y = obj->trans.z = 1000.0f;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_TightropeTreachery/19D510", func_800FC180_TightropeTreachery);
#endif

/* A bomb object's update: waits 30 frames after a throw, then flies when its team member throws. */
void func_800FC598_TightropeTreachery(omObjData* obj) {
    TTBomb* b = ((TTItemWork*)obj->unk_50)->bomb;
    s32 idx = b->idx;

    if (b->active == 1) {
        if (b->lit == 0) {
            if (b->timer >= 30) {
                D_800FE4F0_TightropeTreachery[idx] = 0;
                func_800FBF38_TightropeTreachery(obj);
                return;
            }
        } else {
            if (D_800FE4F0_TightropeTreachery[b->idx] == 0) {
                PlaySound(0x2AA);
                D_800FE4F0_TightropeTreachery[b->idx] = 1;
            }
            func_800FC180_TightropeTreachery(obj);
        }
        b->timer++;
    }
}

/* A bomb object: the bomb, its shadow and three 3D sprites (fuse, splash, explosion). */
void func_800FC65C_TightropeTreachery(omObjData* obj) {
    TTItemWork* w;
    void* data;
    u16 ids[3];
    u16 id;
    s16 i;

    obj->unk_50 = func_80023684(sizeof(TTItemWork), 0x7918);
    func_8009B770(obj->unk_50, 0, sizeof(TTItemWork));
    w = obj->unk_50;
    if (D_800FE6E0_TightropeTreachery[0] < 0) {
        obj->model[0] = func_800174C0(0x320004, 0x299);
        D_800FE6E0_TightropeTreachery[0] = obj->model[0];
        obj->model[1] = func_800174F4(6, 0x699);
        D_800FE6E0_TightropeTreachery[1] = obj->model[1];
        func_800258EC(obj->model[1], 4, 4);
    } else {
        obj->model[0] = func_80023FC8(D_800FE6E0_TightropeTreachery[0]);
        obj->model[1] = func_80023FC8(D_800FE6E0_TightropeTreachery[1]);
    }
    func_80025930(obj->model[0], 0x70000000, 0x70000000);
    func_80009340(obj, 2, 0x25, 0x289, 8);
    if (D_800FE6E0_TightropeTreachery[2] < 0) {
        data = DataRead(0x26);
        id = func_8001E00C(data, 0x1E99, 8);
        HuMemDirectFree(data);
        obj->model[3] = D_800ECDE0[id].unk_00;
        ids[0] = id;
        D_800FE6E0_TightropeTreachery[2] = id;
    } else {
        id = func_8001E00C((void*)-1, 0x1E99, 8);
        D_800ECDE0[id].unk_02 = D_800ECDE0[D_800FE6E0_TightropeTreachery[2]].unk_02;
        obj->model[3] = D_800ECDE0[id].unk_00;
        ids[0] = id;
    }
    func_80025930(obj->model[3], 0x70000000, 0x70000000);
    func_8001E268(ids[0], 4, 4);
    func_80025830(obj->model[3], 3.5f, 3.5f, 3.5f);
    func_800258EC(obj->model[3], 4, 4);
    if (D_800FE6E0_TightropeTreachery[3] < 0) {
        data = DataRead(0x25);
        id = func_8001E00C(data, 0x1E99, 8);
        HuMemDirectFree(data);
        func_8001E2F8(id, 0x96);
        obj->model[4] = D_800ECDE0[id].unk_00;
        ids[1] = id;
        D_800FE6E0_TightropeTreachery[3] = id;
    } else {
        id = func_8001E00C((void*)-1, 0x1E99, 8);
        func_8001E2F8(id, 0x96);
        D_800ECDE0[id].unk_02 = D_800ECDE0[D_800FE6E0_TightropeTreachery[3]].unk_02;
        obj->model[4] = D_800ECDE0[id].unk_00;
        ids[1] = id;
    }
    func_80025930(obj->model[4], 0x70000000, 0x70000000);
    func_8001E268(ids[1], 4, 4);
    func_80025830(obj->model[4], 11.0f, 11.0f, 11.0f);
    func_800258EC(obj->model[4], 4, 4);
    if (D_800FE6E0_TightropeTreachery[4] < 0) {
        data = DataRead(0x26);
        id = func_8001E00C(data, 0x1E99, 8);
        HuMemDirectFree(data);
        obj->model[5] = D_800ECDE0[id].unk_00;
        ids[2] = id;
        D_800FE6E0_TightropeTreachery[4] = id;
    } else {
        id = func_8001E00C((void*)-1, 0x1E99, 8);
        D_800ECDE0[id].unk_02 = D_800ECDE0[D_800FE6E0_TightropeTreachery[4]].unk_02;
        obj->model[5] = D_800ECDE0[id].unk_00;
        ids[2] = id;
    }
    func_80025930(obj->model[5], 0x70000000, 0x70000000);
    func_8001E268(ids[2], 4, 4);
    func_80025830(obj->model[5], 5.0f, 5.0f, 5.0f);
    func_800258EC(obj->model[5], 4, 4);
    for (i = 0; i < 6; i++) {
        func_800258EC(obj->model[i], 4, 4);
        obj->trans.x = obj->trans.y = obj->trans.z = 1000.0f;
    }
    w->unk_44 = 0.1f;
    w->unk_48 = 18.0f;
    w->unk_34 = 50.0f;
    w->unk_3C = 0.0f;
    w->unk_52 = 7;
    w->unk_5C = 0;
    w->unk_60 = 0;
    w->unk_54 = 1;
    D_800FE720_TightropeTreachery[D_800FE4F4_TightropeTreachery].active = 0;
    D_800FE720_TightropeTreachery[D_800FE4F4_TightropeTreachery].idx = D_800FE4F4_TightropeTreachery;
    D_800FE720_TightropeTreachery[D_800FE4F4_TightropeTreachery].lit = 0;
    D_800FE720_TightropeTreachery[D_800FE4F4_TightropeTreachery].timer = 30;
    for (i = 0; i < 3; i++) {
        D_800FE720_TightropeTreachery[D_800FE4F4_TightropeTreachery].mdl[i] = ids[i];
    }
    w->bomb = &D_800FE720_TightropeTreachery[D_800FE4F4_TightropeTreachery];
    D_800FE4F4_TightropeTreachery++;
    obj->func_ptr = func_800FC598_TightropeTreachery;
}

void func_800FCCDC_TightropeTreachery(omObjData* obj) {
    func_800FC65C_TightropeTreachery(obj);
}

void func_800FCCF8_TightropeTreachery(omObjData* obj) {
    func_800FC65C_TightropeTreachery(obj);
}

void func_800FCD14_TightropeTreachery(omObjData* obj) {
    func_800FC65C_TightropeTreachery(obj);
}

/* Moves a team member by (dx, dz), pushed back by the others it would touch (radius 280). */
void func_800FCD30_TightropeTreachery(omObjData* obj, f32 dx, f32 dz) {
    TTTeamWork* t = TT_WORK(obj)->unk_E4;
    s16 i;

    for (i = 0; i < 3; i++) {
        omObjData* o = D_800FE700_TightropeTreachery[i];

        if (obj == o) {
            continue;
        }
        if (o != NULL) {
            f32 ex = dx + obj->trans.x - o->trans.x;
            f32 ez = dz + obj->trans.z - o->trans.z;
            f32 d = sqrtf(ex * ex + ez * ez);

            if (d < 280.0f) {
                t->target += 5.0f;
                if (d != 0.0f) {
                    f32 k = 280.0f - d;

                    obj->trans.x = dx - (dx - ex / d * k) + obj->trans.x;
                    obj->trans.z = dz - (dz - ez / d * k) + obj->trans.z;
                }
            } else {
                obj->trans.x = dx + obj->trans.x;
                obj->trans.z = dz + obj->trans.z;
            }
        }
    }
}

/* A team member: steers with the stick, throws its bomb with A. */
// float register allocation (masked 1)
#ifdef NON_MATCHING
void func_800FCEDC_TightropeTreachery(omObjData* obj) {
    TTTeamWork* t = TT_WORK(obj)->unk_E4;
    f32 sx;
    f32 sy;
    f32 push[2];
    f32 dx;
    f32 dz;
    f32 dir;
    f32 diff;
    f32 boost;
    f32 s;
    f32 c;
    f32 mag;
    s16 i;

    sx = 0.0f;
    sy = 0.0f;
    dx = dz = 0.0f;
    t->noCtrl = 0;
    if (t->flash != 0) {
        if (t->flash & 1) {
            func_800258EC(obj->model[0], 4, 0);
            func_800258EC(obj->model[1], 4, 0);
        } else {
            func_800258EC(obj->model[0], 4, 4);
            func_800258EC(obj->model[1], 4, 4);
        }
        t->flash--;
        t->noCtrl = 1;
    } else {
        func_800258EC(obj->model[0], 4, 0);
        func_800258EC(obj->model[1], 4, 0);
    }
    if (t->swayDir == 1) {
        if (++t->sway >= 9) {
            t->swayDir = 0;
        }
    } else {
        if (--t->sway < -8) {
            t->swayDir = 1;
        }
    }
    obj->rot.x = t->sway * 0.4166666;
    if (obj->rot.x < 0.0f) {
        obj->rot.x += 360.0f;
    }
    if (obj->rot.x > 360.0f) {
        obj->rot.x -= 360.0f;
    }
    func_800257E4(obj->model[1], t->sway, 0.0f, 0.0f);
    if (D_800ED430 != 1) {
        t->noCtrl = 1;
    }
    if (D_800FE2B4_TightropeTreachery == 1) {
        t->noCtrl = 1;
    }
    if (t->noCtrl == 0) {
        sx = ContStkX[t->port];
        sy = ContStkY[t->port];
    }
    mag = sx * sx + sy * sy;
    dx = dz = 0.0f;
    if (mag > 100.0f) {
        dir = func_800B0CD8(sx, -sy);
        diff = dir - t->angle;
        if ((diff < 0.0f ? -diff : diff) >= 180.0f) {
            if (diff <= 0.0f) {
                diff += 360.0f;
            } else {
                diff -= 360.0f;
            }
        }
        if ((diff < 0.0f ? -diff : diff) < 20.0f) {
            t->angle = diff + t->angle;
        } else {
            t->angle = t->angle + (diff <= 0.0f ? -20.0f : 20.0f);
        }
        obj->rot.y = t->angle;
        if (t->angle - dir < 5.0) {
            if (t->straight++ > 30) {
                boost = 3.0f;
            } else {
                boost = 1.0f;
            }
        } else {
            t->straight = 0;
            boost = 1.0f;
        }
        dx += func_800AEAC0(obj->rot.y) * 3.0f * boost;
        dz += func_800AEFD0(obj->rot.y) * 3.0f * boost;
    }
    obj->rot.y = t->angle;
    if (t->done != 1) {
        switch (D_800FE2B5_TightropeTreachery) {
        case 1:
            func_80025BB8(obj->model[0], obj->motion[2]);
            ContStkX[t->port] = 0;
            ContStkY[t->port] = 0;
            t->angle = 0.0f;
            t->done = 1;
            break;
        case 2:
            func_80025BB8(obj->model[0], obj->motion[2]);
            ContStkX[t->port] = 0;
            ContStkY[t->port] = 0;
            t->angle = 0.0f;
            t->done = 1;
            break;
        case 3:
            func_80025BB8(obj->model[0], obj->motion[1]);
            ContStkX[t->port] = 0;
            ContStkY[t->port] = 0;
            t->angle = 0.0f;
            t->done = 1;
            break;
        }
    }
    dx += func_800AEAC0(obj->rot.y) * 0.5f;
    dz += func_800AEFD0(obj->rot.y) * 0.5f;
    /* the wind pushes, at most 30 a frame */
    for (i = 0; i < 2; i++) {
        if ((t->push[i] < 0.0f ? -t->push[i] : t->push[i]) > 30.0f) {
            if (t->push[i] < 0.0f) {
                push[i] = t->push[i] + 30.0f;
                t->push[i] = -30.0f;
            } else {
                push[i] = t->push[i] - 30.0f;
                t->push[i] = 30.0f;
            }
        }
        push[i] = t->push[i] * 0.1f;
        t->push[i] = t->push[i] * 0.9f;
        t->push[i] = t->push[i] + D_800FE714_TightropeTreachery[i];
    }
    dx += push[0];
    dz += push[1];
    func_800F927C_TightropeTreachery(obj, &dx, &dz);
    func_800FCD30_TightropeTreachery(obj, dx, dz);
    s = func_800AEAC0(obj->rot.y) * 10.0f;
    c = func_800AEFD0(obj->rot.y) * 10.0f;
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80025798(obj->model[1], obj->trans.x - s, obj->trans.y - 80.0f, obj->trans.z - c);
    func_800257E4(obj->model[0], obj->rot.x, obj->rot.y, obj->rot.z);
    func_800257E4(obj->model[1], obj->rot.x, obj->rot.y, obj->rot.z);
    if (t->noCtrl == 0 && (ContBtnTrg[t->port] & 0x8000)) {
        if (D_800FE720_TightropeTreachery[t->idx].active == 0) {
            D_800FE720_TightropeTreachery[t->idx].active = 1;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_TightropeTreachery/19D510", func_800FCEDC_TightropeTreachery);
#endif

/* A CPU team member: walks to a free spot around the walker, aims and throws. */
// float register allocation: retail keeps one more value in a saved register (masked ~4)
#ifdef NON_MATCHING
void func_800FD70C_TightropeTreachery(omObjData* obj) {
    TTTeamWork* t = TT_WORK(obj)->unk_E4;
    s32 wait = 0;
    s16 i;
    f32 tx;
    f32 tz;
    f32 dx;
    f32 dz;
    f32 a;

    if (GwPlayer[t->player].flags & 1) {
        t->btn = 0;
        if (t->hasSpot == 0) {
            t->spot = func_800F9450_TightropeTreachery() & 3;
            if (D_800FE4D0_TightropeTreachery[t->spot].used == 1) {
                for (i = 0; i < 4; i++) {
                    if (D_800FE4D0_TightropeTreachery[i].used == 0) {
                        break;
                    }
                }
                if (i >= 4) {
                    t->spot = func_800F9450_TightropeTreachery() & 3;
                } else {
                    t->spot = i;
                }
            }
            D_800FE4D0_TightropeTreachery[t->spot].used = 1;
            t->timer = 0;
            t->unk_10 = 0.0f;
            t->unk_14 = 0.0f;
            t->aimed = 0;
            t->hasSpot = 1;
        } else if (t->aimed == 0) {
            tx = func_800AEAC0(D_800FE4D0_TightropeTreachery[t->spot].angle) * -885.0f;
            tz = func_800AEFD0(D_800FE4D0_TightropeTreachery[t->spot].angle) * -885.0f;
            tx += D_800F3FB0[0]->trans.x;
            tz += D_800F3FB0[0]->trans.z;
            dx = tx - obj->trans.x;
            dz = tz - obj->trans.z;
            t->target = func_800B0CD8(dz, dx);
            if (t->target < 0.0f) {
                t->target += 360.0f;
            }
            dx = tx - obj->trans.x;
            dz = tz - obj->trans.z;
            if (dx * dx + dz * dz < 2500.0f) {
                t->aimed = 1;
                t->timer = 0;
                t->aim = guRandom() % 20 - 10;
                switch (GwPlayer[t->player].cpu_difficulty) {
                case 0:
                    t->aim = guRandom() % 40 - 20;
                    break;
                case 1:
                    t->aim = guRandom() % 30 - 15;
                    break;
                case 2:
                    t->aim = guRandom() % 20 - 10;
                    break;
                case 3:
                    t->aim = 0.0f;
                    break;
                }
            }
        } else {
            dx = D_800F3FB0[0]->trans.x - obj->trans.x;
            dz = D_800F3FB0[0]->trans.z - obj->trans.z;
            a = func_800B0CD8(dz, dx) + t->aim;
            if (a < 0.0f) {
                a += 360.0f;
            }
            if (a > 360.0f) {
                a -= 360.0f;
            }
            t->target = a;
            switch (GwPlayer[t->player].cpu_difficulty) {
            case 0:
            case 1:
                wait = 40;
                break;
            case 2:
            case 3:
                wait = 80;
                break;
            }
            if (t->timer > wait) {
                t->aimed = 0;
                t->hasSpot = 0;
                D_800FE4D0_TightropeTreachery[t->spot].used = 0;
                t->btn &= 0x7FFF;
            } else if (t->timer > 10 && t->aimed == 1 && !(t->timer & 0xF)) {
                t->btn |= 0x8000;
            }
            t->timer++;
        }
        if (ContBtn[t->port] & 0x1000) {
            t->btn |= 0x1000;
        }
        ContBtn[t->port] = t->btn;
        ContBtnTrg[t->port] = t->btn & (t->btn ^ t->prevBtn);
        t->prevBtn = t->btn;
        if (t->target < 0.0f) {
            ContStkX[t->port] = 0;
            ContStkY[t->port] = 0;
        } else {
            ContStkX[t->port] = func_800AEFD0(t->target) * 80.0f;
            ContStkY[t->port] = -func_800AEAC0(t->target) * 80.0f;
        }
    }
    func_800FCEDC_TightropeTreachery(obj);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_TightropeTreachery/19D510", func_800FD70C_TightropeTreachery);
#endif

/* A team member (MgWork-style work; its own state in D_800FE7C8_TightropeTreachery[idx]). */
void func_800FDCE8_TightropeTreachery(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z, u16 idx) {
    void* mem;
    TTPlayerWork* w;
    TTTeamWork* t;
    s16 i;

    mem = func_80023684(sizeof(TTPlayerWork), 0x7918);
    obj->unk_50 = mem;
    func_8009B770(mem, 0, sizeof(TTPlayerWork));
    w = obj->unk_50;
    t = w->unk_E4 = &D_800FE7C8_TightropeTreachery[idx];
    w->unk_52 = 0;
    w->unk_A4 = 1.0f;
    w->unk_C0 = 0xFFFF;
    w->unk_4C = 0.5f;
    w->unk_BC = 1.0f;
    w->unk_60 = 0.0f;
    func_80008FD0(obj, 70.0f);
    func_80008FDC(obj, 150.0f);
    func_80008FE8(obj, 20.0f);
    func_80008FA0(obj, 1000.0f);
    t->port = GwPlayer[player].port;
    t->player = player;
    t->push[0] = 0.0f;
    t->idx = idx;
    t->sway = guRandom() % 8;
    t->swayDir = 1;
    t->noCtrl = 0;
    t->hasSpot = 0;
    t->spot = 0;
    t->timer = 0;
    t->aimed = 0;
    t->straight = 0;
    t->done = 0;
    t->aim = 0.0f;
    t->hasSpot = 1;
    t->spot = D_800FE8AC_TightropeTreachery[idx];
    D_800FE4D0_TightropeTreachery[t->spot].used = 1;
    obj->model[0] = LoadFormFile(dir | file, 0x299);
    if (D_800FE6F0_TightropeTreachery[0] < 0) {
        obj->model[1] = LoadFormFile(0x320001, 0x299);
        D_800FE6F0_TightropeTreachery[0] = obj->model[1];
    } else {
        obj->model[1] = func_80023FC8(D_800FE6F0_TightropeTreachery[0]);
    }
    func_8001775C(obj, 0, dir);
    guRandom();
    func_8001775C(obj, 1, dir | 0x10);
    guRandom();
    func_8001775C(obj, 2, dir | 0xF);
    func_80025BB8(obj->model[0], obj->motion[0]);
    func_80025EB4(obj->model[0], 2, 2);
    t->angle = 0.0f;
    t->unk_3E = 0;
    for (i = 0; i < 8; i++) {
        t->unk_2C[i] = 0;
        t->unk_34[i] = 0;
    }
    t->target = -1.0f;
    t->btn = 0;
    t->prevBtn = 0;
    t->flash = 0;
    obj->trans.x = x;
    obj->trans.y = y + 80.0f;
    obj->trans.z = z + 10.0f;
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80025798(obj->model[1], x, y, z);
    obj->func_ptr = func_800FD70C_TightropeTreachery;
}

void func_800FE040(omObjData* obj) {
    u8 chr = GwPlayer[D_800FE8A0_TightropeTreachery[1]].character;
    s32 dir = D_800C59AC[chr].unk_00;
    s32 file = D_800C59AC[chr].unk_04;

    func_800FDCE8_TightropeTreachery(obj, dir, file, D_800FE8A0_TightropeTreachery[1], D_800FE4A0_TightropeTreachery[(s8)D_800FE8AC_TightropeTreachery[0]].x,
                                     D_800FE4A0_TightropeTreachery[(s8)D_800FE8AC_TightropeTreachery[0]].y,
                                     D_800FE4A0_TightropeTreachery[(s8)D_800FE8AC_TightropeTreachery[0]].z, 0);
}

void func_800FE10C_TightropeTreachery(omObjData* obj) {
    u8 chr = GwPlayer[D_800FE8A0_TightropeTreachery[2]].character;
    s32 dir = D_800C59AC[chr].unk_00;
    s32 file = D_800C59AC[chr].unk_04;

    func_800FDCE8_TightropeTreachery(obj, dir, file, D_800FE8A0_TightropeTreachery[2], D_800FE4A0_TightropeTreachery[(s8)D_800FE8AC_TightropeTreachery[1]].x,
                                     D_800FE4A0_TightropeTreachery[(s8)D_800FE8AC_TightropeTreachery[1]].y,
                                     D_800FE4A0_TightropeTreachery[(s8)D_800FE8AC_TightropeTreachery[1]].z, 1);
}

void func_800FE1DC_TightropeTreachery(omObjData* obj) {
    u8 chr = GwPlayer[D_800FE8A0_TightropeTreachery[3]].character;
    s32 dir = D_800C59AC[chr].unk_00;
    s32 file = D_800C59AC[chr].unk_04;

    func_800FDCE8_TightropeTreachery(obj, dir, file, D_800FE8A0_TightropeTreachery[3], D_800FE4A0_TightropeTreachery[(s8)D_800FE8AC_TightropeTreachery[2]].x,
                                     D_800FE4A0_TightropeTreachery[(s8)D_800FE8AC_TightropeTreachery[2]].y,
                                     D_800FE4A0_TightropeTreachery[(s8)D_800FE8AC_TightropeTreachery[2]].z, 2);
}
