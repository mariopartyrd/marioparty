#include "CoinBlockBash.h"

/* .data (0x80101B20..0x80101BF4) */
u8 D_80101B20_CoinBlockBash[2][2] = { { 0, 1 }, { 1, 5 } };
CBBFxDef D_80101B24_CoinBlockBash[8] = {
    { -8, 0, 0, 200, 100, 8, 1, 0 },   { 1, 1, 0, 100, 100, 11, 1, 0 },  { 5, 0, 0, 100, 100, 8, 1, 0 },
    { 2, 2, 0, 100, 100, 999, 2, 0 }, { 1, 3, 0, 100, 100, 30, 3, 0 },  { 3, 1, 0, 80, 100, 11, 1, 0 },
    { -3, 0, 0, 80, 100, 60, 1, 0 },  { 1, 0, 0, 100, 100, 1, 1, 0 },
};
Vec D_80101BA4_CoinBlockBash[3] = { { 0.0f, 90.0f, 0.0f }, { 0.0f, -90.0f, 0.0f }, { 0.0f, 0.0f, -70.0f } };
f32 D_80101BC8_CoinBlockBash[3] = { 50.0f, 50.0f, 30.0f };
CBBSwing D_80101BD4_CoinBlockBash[2] = { { 0x20, 0, 0x13 }, { 0x18, 0, 0x14 } };
u8 D_80101BDC_CoinBlockBash[12][2] = {
    { 0x0F, 0x15 }, { 0x09, 0x0D }, { 0x0F, 0x14 }, { 0x09, 0x10 }, { 0x0D, 0x14 }, { 0x0A, 0x0F },
    { 0x0C, 0x12 }, { 0x0A, 0x10 }, { 0x0D, 0x13 }, { 0x08, 0x0D }, { 0x0D, 0x13 }, { 0x08, 0x0D },
};

void func_800F65E0_CoinBlockBash(void) {
    D_801024F8_CoinBlockBash = _CheckFlag(0x2B) != 0;
    func_80029090(50);
    omInitObjMan(50, 0);
    func_80060088();
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    func_800F6CC8_CoinBlockBash();
    D_801024F0_CoinBlockBash.state = 0;
    D_801024F0_CoinBlockBash.timer = 0;
    D_801024F0_CoinBlockBash.unk_02 = 0;
    D_801024F0_CoinBlockBash.time = 1800;
    D_801025AC_CoinBlockBash = -1;
    func_800FAA7C_CoinBlockBash();
    func_800FDC5C_CoinBlockBash();
    func_800F78E8_CoinBlockBash();
    func_800FE650_CoinBlockBash();
    D_800F2AF8[D_800ED440++] = omAddObj(0x14, 0, 0, -1, func_800F66F8_CoinBlockBash);
}
void func_800F66F8_CoinBlockBash(omObjData* obj) {
    s32 i;

    func_800F8CD0_CoinBlockBash();
    for (i = 0; i < 9; i++) {
        D_8010320E_CoinBlockBash[i] = 0;
    }
    obj->func_ptr = func_800F6770_CoinBlockBash;
    omSetStatBit(obj, 0xA0);
    func_8007B168((u8*)"\x82\x72\x82\x73\x82\x60\x82\x71\x82\x73", 1);
    func_8007B168((u8*)"\x82\x4F\x82\x50\x82\x51\x82\x52\x82\x53\x82\x54\x82\x55\x82\x56\x82\x57\x82\x58", 0);
}


// NON_MATCHING: register allocation: wait in a1 vs v1 (masked 0)
#ifdef NON_MATCHING
void func_800F6770_CoinBlockBash(omObjData* obj) {
    s32 i;
    s32 mask;
    s16 msg;
    s32 wait;

    if (func_8005FD5C() + D_800F64F8 != 0) {
        func_800F8014_CoinBlockBash();
        return;
    }
    switch (D_801024F0_CoinBlockBash.state) {
    case 0:
        if (D_801024F0_CoinBlockBash.timer == 2) {
            SetFadeInTypeAndTime(0, 16);
        } else if (D_801024F0_CoinBlockBash.timer == 0x56) {
            GMesCreate(0);
        } else if (D_801024F0_CoinBlockBash.timer == 0x28) {
            func_80060128(0x1B);
        } else if (D_801024F0_CoinBlockBash.timer == 0x8E) {
            GMesCreate(8, D_801024F0_CoinBlockBash.time / 30, 0xA0, 0x20);
            D_801024F0_CoinBlockBash.state = 1;
            D_801024F0_CoinBlockBash.timer = -1;
        }
        if (D_801024F0_CoinBlockBash.timer >= 0x3D) {
            D_80102534_CoinBlockBash += 0.03;
            if (D_80102534_CoinBlockBash > 1.0) {
                D_80102534_CoinBlockBash = 1.0f;
            }
        }
        func_800F6EA0_CoinBlockBash();
        break;
    case 1:
        D_801024F0_CoinBlockBash.time--;
        if ((func_800FFD60_CoinBlockBash() == 0 && func_800FFD6C_CoinBlockBash() == 0) ||
            D_801024F0_CoinBlockBash.time <= 0) {
            D_801024F0_CoinBlockBash.state = 2;
            D_801024F0_CoinBlockBash.timer = -1;
            msg = 0x10;
            if (D_801024F0_CoinBlockBash.time != 0) {
                msg = 2;
            }
            GMesCreate(msg);
            func_800601D4(0x5A);
            func_800790C0();
        }
        func_80079078((D_801024F0_CoinBlockBash.time + 29) / 30);
        func_800F99A0_CoinBlockBash();
        func_800F9A98_CoinBlockBash();
        func_800F9FE4_CoinBlockBash();
        break;
    case 2:
        if (GMesStatAllGet() == 2) {
            D_801024F0_CoinBlockBash.timer = 500;
        }
        if (D_801024F0_CoinBlockBash.timer >= 500) {
            mask = 0;
            for (i = 0; i < D_801031FC_CoinBlockBash; i++) {
                if (D_801025B0_CoinBlockBash[i].state != 0xF) {
                    break;
                }
                mask |= D_801025B0_CoinBlockBash[i].unk_62;
            }
            if (i >= D_801031FC_CoinBlockBash) {
                if (D_801024F8_CoinBlockBash == 0) {
                    if (mask == 0) {
                        func_80060128(0x34);
                    } else {
                        func_80060128(D_801024F0_CoinBlockBash.time != 0 ? 0x36 : 0x3C);
                    }
                }
                D_801024F0_CoinBlockBash.state = 3;
                D_801024F0_CoinBlockBash.timer = -1;
                func_800FFBA8_CoinBlockBash();
            }
        }
        break;
    case 3:
        if (D_801024F8_CoinBlockBash != 0) {
            wait = GMesWait() != 0 ? 0x3C : 0;
        } else {
            wait = D_801024F0_CoinBlockBash.time != 0 ? 0x69 : 0x78;
        }
        if (D_801024F0_CoinBlockBash.timer >= wait) {
            if (D_801024F8_CoinBlockBash == 0) {
                func_800601D4(0x28);
            }
            if (D_801024F8_CoinBlockBash != 0) {
                func_80060398(0x28);
            }
            func_800726AC(0, 0x14);
            obj->func_ptr = func_800F6C20_CoinBlockBash;
            return;
        }
        break;
    }
    if (++D_801024F0_CoinBlockBash.timer >= 0x7800) {
        D_801024F0_CoinBlockBash.timer -= 0x800;
    }
    func_800FEE04_CoinBlockBash();
    func_800F7A5C_CoinBlockBash();
    func_800F8014_CoinBlockBash();
    func_800F8D98_CoinBlockBash();
    if (D_800F5144 == 1) {
        func_800F6C54_CoinBlockBash();
        omOvlReturnEx(1);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800F6770_CoinBlockBash);
#endif
void func_800F6C20_CoinBlockBash(omObjData* obj) {
    if (func_80072718() == 0) {
        func_800F6C54_CoinBlockBash();
        omOvlReturnEx(1);
    }
}
void func_800F6C54_CoinBlockBash(void) {
    func_800FB490_CoinBlockBash();
    func_80060198();
    func_800FFE30_CoinBlockBash();
}
s16 func_800F6C80_CoinBlockBash(s32 id) {
    void* file;
    s16 sprite;

    file = DataRead(id);
    sprite = func_800678A4(file);
    DataClose(file);
    return sprite;
}
void func_800F6CC8_CoinBlockBash(void) {
    u8 cam;

    func_800178A0(1);
    cam = func_800178E8();
    func_80017660(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 20.0f, 80.0f, 4500.0f);
    Center.x = -65.0f;
    Center.y = -100.0f;
    Center.z = -75.0f;
    CRot.x = -42.0f;
    CRot.y = 29.0f;
    CRot.z = 0.0f;
    CZoom = 3650.0f;
    D_801024FC_CoinBlockBash.x = D_80102508_CoinBlockBash.x = Center.x;
    D_801024FC_CoinBlockBash.y = D_80102508_CoinBlockBash.y = Center.y;
    D_801024FC_CoinBlockBash.z = D_80102508_CoinBlockBash.z = Center.z;
    D_80102514_CoinBlockBash.x = D_80102520_CoinBlockBash.x = CRot.x;
    D_80102514_CoinBlockBash.y = D_80102520_CoinBlockBash.y = CRot.y;
    D_80102514_CoinBlockBash.z = D_80102520_CoinBlockBash.z = CRot.z;
    D_8010252C_CoinBlockBash = D_80102530_CoinBlockBash = CZoom;
    D_80102534_CoinBlockBash = CRot.z;
    func_800234B8(0, 100, 100, 100);
    func_800234B8(1, 255, 255, 255);
    func_80023504(1, 200.0f, 200.0f, 500.0f);
}
void func_800F6EA0_CoinBlockBash(void) {
    f32 k;
    f32 near;

    Center.x = (D_80102508_CoinBlockBash.x - D_801024FC_CoinBlockBash.x) * D_80102534_CoinBlockBash + D_801024FC_CoinBlockBash.x;
    Center.y = (D_80102508_CoinBlockBash.y - D_801024FC_CoinBlockBash.y) * D_80102534_CoinBlockBash + D_801024FC_CoinBlockBash.y;
    Center.z = (D_80102508_CoinBlockBash.z - D_801024FC_CoinBlockBash.z) * D_80102534_CoinBlockBash + D_801024FC_CoinBlockBash.z;
    CRot.x = (D_80102520_CoinBlockBash.x - D_80102514_CoinBlockBash.x) * D_80102534_CoinBlockBash + D_80102514_CoinBlockBash.x;
    CRot.y = (D_80102520_CoinBlockBash.y - D_80102514_CoinBlockBash.y) * D_80102534_CoinBlockBash + D_80102514_CoinBlockBash.y;
    CRot.z = (D_80102520_CoinBlockBash.z - D_80102514_CoinBlockBash.z) * D_80102534_CoinBlockBash + D_80102514_CoinBlockBash.z;
    CZoom = (D_80102530_CoinBlockBash - D_8010252C_CoinBlockBash) * D_80102534_CoinBlockBash + D_8010252C_CoinBlockBash;
    k = 2.0 - D_80102534_CoinBlockBash;
    near = CZoom - k * 10.0 * 100.0;
    if (near < 80.0) {
        near = 80.0f;
    }
    func_8001D494(0, 20.0f, near, CZoom + k * 8.0 * 100.0);
}

const CBBQuad D_80101D18_CoinBlockBash = { { 29.0f, 0.0f, 90.0f, 29.0f } };

void func_800F7048_CoinBlockBash(omObjData* obj) {
    CBBQuad rot = D_80101D18_CoinBlockBash;
    s32 i;

    i = 1;
    if (!(obj->trans.x > 0.0)) {
        i = 0;
    }
    if (obj->trans.z > 0.0) {
        i |= 2;
    }
    D_801024FC_CoinBlockBash.x = obj->trans.x;
    D_801024FC_CoinBlockBash.y = obj->trans.y + 100.0;
    D_801024FC_CoinBlockBash.z = obj->trans.z;
    D_80102514_CoinBlockBash.x = -5.0f;
    D_80102514_CoinBlockBash.y = rot.v[i];
    D_8010252C_CoinBlockBash = 800.0f;
    D_80102534_CoinBlockBash = 0.0f;
}
// NON_MATCHING: register allocation of the two radii (masked ~40)
#ifdef NON_MATCHING
s32 func_800F7148_CoinBlockBash(s32 self, Vec* pos, f32 dx_, f32 vy, f32 dz_) {
    f32 rot[3];
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dist;
    f32 push;
    f32 rA;
    f32 rB;
    f32 angle;
    CBBPlayer* p;
    omObjData* o;
    s16 res;
    s16 i;

    res = 0;
    rA = rB = 50.0f;
    rB = 50.0f;
    rA = rB;
    rB = rA;
    for (i = 0; i < D_801031FC_CoinBlockBash; i++) {
        if (i == self) {
            continue;
        }
        if (i == D_801025B0_CoinBlockBash[self].unk_40) {
            continue;
        }
        p = &D_801025B0_CoinBlockBash[i];
        if (p->flags & 0x20) {
            continue;
        }
        o = p->obj;
        dx = o->trans.x - pos->x;
        dy = o->trans.y - pos->y;
        dz = o->trans.z - pos->z;
        if (abs((s32)dy) > 100.0) {
            continue;
        }
        dist = sqrtf(dx * dx + dz * dz);
        if (!(dist < rA + rB)) {
            continue;
        }
        if (vy < 0.0 && dy < 0.0 && dy + vy <= -100.0 && p->unk_44 == 0) {
            pos->y = rB + rB + o->trans.y;
            p->unk_40 = self;
            if (p->unk_44 == 0) {
                p->state = 8;
                p->unk_42 = 30;
                p->unk_50 = 0;
                rot[0] = -90.0f;
                rot[1] = rot[2] = 0.0f;
                func_80017C0C(o, 5, pos->x, pos->y, pos->z, rot[0], rot[1]);
            }
            res = -1;
            continue;
        }
        if (dist == 0.0) {
            dx = pos->x - -25.0;
            dz = pos->z - -14.999999999999972;
            if (dx == 0.0 && dz == 0.0) {
                angle = (((rand8() & 0xFF) << 8) | (rand8() & 0xFF)) * 360 / 65536;
                dx = func_800AEAC0(angle);
                dz = func_800AEFD0(angle);
            } else if (dx == 0.0) {
                dz /= abs((s32)dz);
            } else if (dz == 0.0) {
                dx /= abs((s32)dx);
            } else {
                dist = sqrtf(dx * dx + dz * dz);
                dx /= dist;
                dz /= dist;
            }
            push = 100.0f;
        } else {
            dx /= dist;
            dz /= dist;
            push = rA + rB - dist;
        }
        pos->x -= dx * push;
        pos->z -= dz * push;
        res = 1;
    }
    D_801025B0_CoinBlockBash[self].unk_40 = -1;
    return res;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800F7148_CoinBlockBash);
#endif
CBBPlayer* func_800F7644_CoinBlockBash(omObjData* obj) {
    return &D_801025B0_CoinBlockBash[obj->work[0]];
}
void* func_800F766C_CoinBlockBash(omObjData* obj) {
    return obj->unk_50;
}
s16 func_800F7674_CoinBlockBash(omObjData* obj) {
    return ((CBBPlayerWork*)obj->unk_50)->unk_56;
}
void func_800F7680_CoinBlockBash(omObjData* obj, s16 motion, char* name) {
    CBBMtxSet* set;
    CBBPlayer* p;
    Matrix4f* dst;
    Matrix4f* src;
    s32 i;
    s32 j;

    func_80025BB8(obj->model[0], obj->motion[motion]);
    set = func_8002040C(obj->model[0], 2, name);
    p = func_800F7644_CoinBlockBash(obj);
    for (i = 0; i < 2; i++) {
        if (p->mtxCount[i] == 0) {
            break;
        }
    }
    if (i < 2) {
        p->mtx[i] = dst = func_80023684((p->mtxCount[i] = set->count) * 64, 0x7918);
        src = set->mtx;
        for (j = 0; j < p->mtxCount[i]; j++) {
            func_8002C37C(*dst++, *src++);
        }
    }
    func_80020CC4(set);
}
void func_800F77BC_CoinBlockBash(omObjData* obj, s32 motion) {
    CBBPlayer* p;
    s16 id;
    u8 mdl;

    id = func_80017A50(obj);
    p = func_800F7644_CoinBlockBash(obj);
    if (p->unk_4A != id && p->unk_4C != id) {
        if (p->unk_48 != 0) {
            p->unk_4C = id;
        } else {
            p->unk_4A = id;
        }
        p->unk_48 = 1 - p->unk_48;
    }
    if (obj->motion[(u8)motion] >= 0) {
        mdl = obj->model[0];
        if (func_80018490(obj, (u8)motion) != 0) {
            D_800F2B7C[mdl].unk_0A |= 2;
        } else {
            D_800F2B7C[mdl].unk_0A &= ~2;
        }
        func_800184BC(obj, (u8)motion);
        p->unk_5E = (u8)motion;
    }
}
void func_800F78DC_CoinBlockBash(omObjData* obj, s32 a, s32 b) {
    s32 pad[4]; /* retail's frame */
}
void func_800F78E8_CoinBlockBash(void) {
    s32 i;

    D_801031E2_CoinBlockBash = 0;
    D_801031D0_CoinBlockBash[D_801031E2_CoinBlockBash++] = func_800F6C80_CoinBlockBash(0x270004);
    D_801031D0_CoinBlockBash[D_801031E2_CoinBlockBash++] = func_800F6C80_CoinBlockBash(0x390019);
    D_801031E2_CoinBlockBash++;
    D_801031E0_CoinBlockBash = func_80064EF4(40, 0);
    for (i = 0; i < 40; i++) {
        func_80067208(D_801031E0_CoinBlockBash, i, D_801031D0_CoinBlockBash[0], 0);
        func_80067354(D_801031E0_CoinBlockBash, i, 1.0f, 1.0f);
        func_8006752C(D_801031E0_CoinBlockBash, i, 0x100);
        func_800674BC(D_801031E0_CoinBlockBash, i, 0x9008);
        func_800672B0(D_801031E0_CoinBlockBash, i, 0);
    }
    func_8009B770(D_80102870_CoinBlockBash, 0, sizeof(D_80102870_CoinBlockBash));
    D_801031E4_CoinBlockBash = -1;
}
// NON_MATCHING: GCC hoists 360.0 out of the loop (one more saved FPR); otherwise identical
#ifdef NON_MATCHING
void func_800F7A5C_CoinBlockBash(void) {
    Vec pos;
    Vec scr;
    CBBFx* fx;
    s32 i;
    s32 sec;
    f32 scale;

    fx = D_80102870_CoinBlockBash;
    for (i = 0; i < 40; i++, fx++) {
        if (!(fx->flags & 0x80)) {
            continue;
        }
        switch (fx->type) {
        case 0:
            fx->scale -= 0.2;
            break;
        case 2:
            fx->scale -= fx->unk_2E != 0 ? 0.2 : 0.1;
            break;
        case 1:
            fx->scale += 0.01;
        case 5:
            fx->unk_06++;
            break;
        case 3:
            fx->flags |= 1;
            sec = (s16)(D_801024F0_CoinBlockBash.time / 30);
            fx->unk_06 = fx->unk_2C != 0 ? sec / 10 : sec % 10;
            if (D_801024F0_CoinBlockBash.state == 1) {
                fx->timer = 60;
            }
            break;
        case 6:
            fx->unk_2E += 12.0;
            if (fx->unk_2E >= 360.0) {
                fx->unk_2E = fx->unk_2E - 360.0;
            }
            fx->pos.x = fx->unk_38 + func_800AEAC0(fx->unk_2E) * 0.5 * 100.0;
            fx->pos.z = fx->unk_3A + func_800AEFD0(fx->unk_2E) * 0.5 * 100.0;
            fx->vel.y = func_800AEAC0((fx->unk_2E * 2) % 360) * 0.03 * 100.0;
            break;
        }
        fx->pos.x += fx->vel.x;
        fx->pos.y += fx->vel.y;
        fx->pos.z += fx->vel.z;
        if (fx->timer == 0) {
            if (fx->sound >= 0) {
                func_8006071C(fx->sound);
            }
            fx->sound = -1;
            fx->flags = 0;
        }
        fx->timer--;
    }
    fx = D_80102870_CoinBlockBash;
    for (i = 0; i < 40; i++, fx++) {
        if (fx->flags & 1) {
            func_80067480(D_801031E0_CoinBlockBash, i, 0x8000);
            if (fx->flags & 2) {
                func_80066DC4(D_801031E0_CoinBlockBash, i, fx->pos.x, fx->pos.y);
                func_80067354(D_801031E0_CoinBlockBash, i, fx->scale, fx->scale);
            } else {
                pos.x = fx->pos.x;
                pos.y = fx->pos.y;
                pos.z = fx->pos.z;
                func_800FE470_CoinBlockBash(0, &pos, &scr);
                func_80066DC4(D_801031E0_CoinBlockBash, i, scr.x + 160.0f, scr.y + 120.0f);
                scale = scr.z * fx->scale;
                func_80067354(D_801031E0_CoinBlockBash, i, scale, scale);
            }
            func_8006752C(D_801031E0_CoinBlockBash, i, (u32)(fx->alpha * 256.0f));
            func_800673B0(D_801031E0_CoinBlockBash, i, fx->rot * 360.0f);
            func_800671DC(D_801031E0_CoinBlockBash, i, fx->unk_06);
        } else {
            func_800674BC(D_801031E0_CoinBlockBash, i, 0x8000);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800F7A5C_CoinBlockBash);
#endif
void func_800F8014_CoinBlockBash(void) {
    Vec v;
    CBBPlayer* p;
    omObjData* o;
    s32 i;

    for (i = 0; i < D_801031FC_CoinBlockBash; i++) {
        p = &D_801025B0_CoinBlockBash[i];
        o = p->obj;
        if (func_8005FD5C() + D_800F64F8 == 0) {
            if ((p->unk_44 & 1) && !(p->flags & 0x10) && D_801024F0_CoinBlockBash.state == 1) {
                func_80025798(o->model[0], 1500.0f, 500.0f, 1500.0f);
                func_80025798(o->model[1], 1500.0f, 500.0f, 1500.0f);
            }
            p->pos.x = o->trans.x;
            p->pos.y = o->trans.y;
            p->pos.z = o->trans.z;
        } else {
            v.x = o->trans.x;
            v.z = o->trans.z;
            v.y = func_800FE284_CoinBlockBash(&v);
            func_80025798(o->model[1], o->trans.x, v.y, o->trans.z);
        }
    }
}
void func_800F8184_CoinBlockBash(s16 type, f32 x, f32 y, f32 z, s16 arg) {
    Vec pos;
    Vec rot;

    pos.x = x;
    pos.y = y;
    pos.z = z;
    rot.x = rot.y = rot.z = 0.0f;
    func_800F81E0_CoinBlockBash(NULL, type, &pos, &rot, arg);
}
// NON_MATCHING: register allocation: obj reloaded from its spill slot, case 1 float registers (masked 9)
#ifdef NON_MATCHING
void func_800F81E0_CoinBlockBash(omObjData* obj, s16 type, Vec* pos, Vec* rot, s16 arg) {
    Vec v;
    Matrix4f m;
    s16 ids[16];
    CBBFx* fxs[8];
    s32 pad[8]; /* retail's frame */
    CBBFx* fx;
    s32 left;
    s32 cnt;
    u32 all;
    s32 base;
    s32 j;
    s16 n;
    s32 id;
    f32 angle;
    f32 x;
    f32 y;
    f32 z;

    n = 0;
    cnt = D_80101B24_CoinBlockBash[type].count;
    all = cnt < 0;
    left = cnt;
    if (left < 0) {
        left = -left;
    }
    if (obj != NULL) {
        base = obj->work[0] * 8;
    } else {
        base = 32;
    }
    fx = &D_80102870_CoinBlockBash[base];
    for (j = 0; j < 8; j++, fx++) {
        if (all || fx->flags == 0) {
            fx->flags = D_80101B24_CoinBlockBash[type].flags | 0x80;
            fx->type = type;
            fx->unk_04 = D_80101B24_CoinBlockBash[type].sprite;
            fx->unk_06 = D_80101B24_CoinBlockBash[type].frame;
            fx->scale = D_80101B24_CoinBlockBash[type].scale / 100.0;
            fx->alpha = D_80101B24_CoinBlockBash[type].alpha / 100.0;
            fx->timer = D_80101B24_CoinBlockBash[type].timer;
            fx->rot = 0.0f;
            fx->vel.x = fx->vel.y = fx->vel.z = 0.0f;
            fx->unk_34 = fx->unk_38 = fx->unk_3A = 0;
            fx->sound = -1;
            if (obj != NULL) {
                fx->unk_30 = obj->work[0];
            } else {
                fx->unk_30 = 0;
            }
            fx->pos.x = pos->x;
            fx->pos.y = pos->y;
            fx->pos.z = pos->z;
            id = base + j;
            func_80067208(D_801031E0_CoinBlockBash, id, D_801031D0_CoinBlockBash[fx->unk_04], 0);
            func_800672B0(D_801031E0_CoinBlockBash, id, 0);
            fx->unk_2C = n;
            fx->unk_2E = arg;
            ids[n] = id;
            fxs[n++] = fx;
            if (--left <= 0) {
                break;
            }
        }
    }
    if (n == 0) {
        return;
    }
    fx = fxs[0];
    func_800A2A50(m);
    MtxRotate(m, rot->x, rot->y, rot->z);
    switch (type) {
    case 0:
        angle = 0.0f;
        for (j = 0; j < n; j++) {
            fx = fxs[j];
            fx->vel.x = func_800AEAC0(angle) * 0.2 * 100.0;
            fx->vel.y = 10.0f;
            fx->vel.z = func_800AEFD0(angle) * 0.2 * 100.0;
            fx->pos.x = fx->vel.x * 2.0f + fx->pos.x;
            fx->pos.z = fx->vel.z * 2.0f + fx->pos.z;
            angle += 360.0 / n;
        }
        break;
    case 1:
        x = ((((rand8() & 0xFF) << 8) | (rand8() & 0xFF)) * 100 / 65536) * 0.01 * 0.15 * 100.0;
        y = ((((rand8() & 0xFF) << 8) | (rand8() & 0xFF)) * 100 / 65536) * 0.01 * 0.15 * 100.0;
        z = (((((rand8() & 0xFF) << 8) | (rand8() & 0xFF)) * 50 / 65536) * 0.01 + 0.5) * 0.1 * 100.0;
        func_800FDD50_CoinBlockBash(m, x, y, z, &v);
        fx->vel.x = v.x;
        fx->vel.y = v.y;
        fx->vel.z = v.z;
        func_800674F4(D_801031E0_CoinBlockBash, ids[0], 0xFF, 0xFF, 0xFF);
        fx->alpha = arg * 0.00390625;
        break;
    case 2:
        angle = (((rand8() & 0xFF) << 8) | (rand8() & 0xFF)) * (360 / n) / 65536;
        for (j = 0; j < n; j++) {
            fx = fxs[j];
            x = func_800AEFD0(angle) * 0.2 * 100.0;
            y = func_800AEAC0(angle) * 0.2 * 100.0;
            z = (((((rand8() & 0xFF) << 8) | (rand8() & 0xFF)) * 80 / 65536) * 0.01 + 1.0) * 0.1 * 100.0;
            func_800FDD50_CoinBlockBash(m, x, y, z, &v);
            fx->vel.x = v.x;
            fx->vel.y = v.y;
            fx->vel.z = v.z;
            if (arg != 0) {
                fx->scale *= 2.0;
            }
            angle += 360 / n;
        }
        break;
    case 3:
        fx->pos.x += 8.0;
        fx = fxs[1];
        fx->pos.x -= 8.0;
        break;
    case 4:
        fx->unk_06 = arg;
        PlaySound(0x101);
        break;
    case 5:
        angle = (((rand8() & 0xFF) << 8) | (rand8() & 0xFF)) * (360 / n) / 65536;
        for (j = 0; j < n; j++) {
            fx = fxs[j];
            fx->vel.x = func_800AEAC0(angle) * 0.08 * 100.0;
            fx->vel.y = 5.0f;
            fx->vel.z = func_800AEFD0(angle) * 0.08 * 100.0;
            func_800674F4(D_801031E0_CoinBlockBash, ids[j], 0xD0, 0xD0, 0xB8);
            angle += 360.0 / n;
        }
        break;
    case 6:
        angle = 0.0f;
        for (j = 0; j < n; j++) {
            fx = fxs[j];
            fx->unk_38 = fx->pos.x;
            fx->pos.x += func_800AEAC0(angle) * 0.5 * 100.0;
            fx->pos.y += 150.0;
            fx->unk_3A = fx->pos.z;
            fx->pos.z += func_800AEFD0(angle) * 0.5 * 100.0;
            fx->unk_2E = angle;
            angle += 360.0 / n;
            if (j == 0) {
                fx->sound = PlaySound(0x155);
            }
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800F81E0_CoinBlockBash);
#endif
// NON_MATCHING: and-operand order of the clamp (masked 0)
#ifdef NON_MATCHING
void func_800F8CD0_CoinBlockBash(void) {
    s16* blk = (s16*)&D_80102538_CoinBlockBash;
    s32 i;

    func_8009B770(blk, 0, 0x74);
    *blk = LoadFormFile(0x270001, 0xB9);
    D_8010253A_CoinBlockBash = func_800174C0(6, 0x89);
    D_8010253C_CoinBlockBash = -1;
    D_80102548_CoinBlockBash = 0.0f;
    D_8010254C_CoinBlockBash = 0.0f;
    D_80102550_CoinBlockBash = 0.0f;
    i = D_801025AC_CoinBlockBash;
    i = (~i >> 31) & i;
    func_800FBF70_CoinBlockBash(D_801025B0_CoinBlockBash[i].obj);
    func_800F7048_CoinBlockBash(D_801025B0_CoinBlockBash[i].obj);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800F8CD0_CoinBlockBash);
#endif
// NON_MATCHING: float register allocation only (masked 0)
#ifdef NON_MATCHING
void func_800F8D98_CoinBlockBash(void) {
    Matrix4f m;
    Vec a;
    Vec r;
    f32 pts[3][3];
    f32 v[3][3]; /* normal, edge, centre */
    f32 d[3][3];
    CBBBlock* b;
    s32 i;
    s32 j;
    f32 ang;
    f32 h;
    f32 s;

    b = (CBBBlock*)&D_80102538_CoinBlockBash;
    if (D_8010253C_CoinBlockBash >= 0) {
        func_800258EC(D_8010253A_CoinBlockBash, 4, 4);
        return;
    }
    if (b->unk_10.y > 100.0 || b->unk_1C.y > 0.0) {
        if (b->unk_10.x < -480.0) {
            b->unk_1C.x = b->unk_1C.x < 0.0 ? b->unk_1C.x * -0.8 : b->unk_1C.x;
        } else if (b->unk_10.x > 430.0) {
            b->unk_1C.x = b->unk_1C.x > 0.0 ? b->unk_1C.x * -0.8 : b->unk_1C.x;
        }
        if (b->unk_10.z < -470.0) {
            b->unk_1C.z = b->unk_1C.z < 0.0 ? b->unk_1C.z * -0.8 : b->unk_1C.z;
        } else if (b->unk_10.z > 440.00000000000006) {
            b->unk_1C.z = b->unk_1C.z > 0.0 ? b->unk_1C.z * -0.8 : b->unk_1C.z;
        }
        b->unk_10.x += b->unk_1C.x;
        b->unk_10.y += b->unk_1C.y;
        b->unk_10.z += b->unk_1C.z;
        b->unk_1C.y -= 5.0;
        ang = b->unk_28.x + 20.0;
        b->unk_28.x = ang - (s32)(ang / 360.0f) * 360;
        if (b->unk_28.x < 0.0) {
            b->unk_28.x += 360.0;
        }
        ang = b->unk_28.y + 5.0;
        b->unk_28.y = ang - (s32)(ang / 360.0f) * 360;
        if (b->unk_28.y < 0.0) {
            b->unk_28.y += 360.0;
        }
    } else if (b->unk_1C.y != 0.0) {
        func_800A2A50(m);
        MtxTranslate(m, b->unk_10.x, b->unk_10.y, b->unk_10.z);
        MtxRotate(m, b->unk_28.x, b->unk_28.y, b->unk_28.z);
        for (i = 0; i < 3; i++) {
            func_800FDD50_CoinBlockBash(m, D_80101BA4_CoinBlockBash[i].x, D_80101BA4_CoinBlockBash[i].y,
                                        D_80101BA4_CoinBlockBash[i].z, (Vec*)pts[i]);
            pts[i][1] += b->unk_1C.y;
            if (pts[i][1] < D_80101BC8_CoinBlockBash[i]) {
                pts[i][1] = D_80101BC8_CoinBlockBash[i];
            }
        }
        for (i = 0; i < 3; i++) {
            j = 2;
            if (i != 0) {
                j = i - 1;
            }
            d[i][0] = pts[i][0] - pts[j][0];
            d[i][1] = pts[i][1] - pts[j][1];
            d[i][2] = pts[i][2] - pts[j][2];
        }
        v[0][0] = d[0][1] * d[1][2] - d[0][2] * d[1][1];
        v[0][1] = d[0][2] * d[1][0] - d[0][0] * d[1][2];
        v[0][2] = d[0][0] * d[1][1] - d[0][1] * d[1][0];
        for (i = 0; i < 3; i++) {
            v[1][i] = -d[1][i];
            v[2][i] = pts[2][i] - pts[0][i] + d[1][i] * 0.5;
        }
        func_800FE0AC_CoinBlockBash((Vec*)v[0], (Vec*)v[1], (Vec*)v[2], &b->unk_28);
        b->unk_10.y = pts[0][1] + d[1][1] * 0.5;
        if (b->unk_10.y < 70.0 && b->unk_0E == 0) {
            func_800F8184_CoinBlockBash(5, b->unk_10.x, 30.0f, b->unk_10.z, 0);
            b->unk_0E = 1;
        }
    }
    if (D_801024F0_CoinBlockBash.state >= 2 && b->unk_0E != 0) {
        func_800258EC(b->model, 4, 4);
        func_800258EC(b->unk_02, 4, 4);
        return;
    }
    for (j = 0; j < 3; j++) {
        h = (&b->unk_28.x)[j];
        for (i = 0; i < 361; i += 90) {
            h -= 90.0;
            if (h >= -1.0 && h < 0.0) {
                (&b->unk_28.x)[j] -= 2.0;
            } else if (h >= 0.0 && h <= 1.0) {
                (&b->unk_28.x)[j] += 2.0;
            }
        }
        if ((&b->unk_28.x)[j] >= 360.0f) {
            (&b->unk_28.x)[j] -= 360.0;
        }
    }
    func_800A2A50(m);
    MtxTranslate(m, b->unk_10.x, b->unk_10.y, b->unk_10.z);
    MtxRotate(m, b->unk_28.x, b->unk_28.y, b->unk_28.z);
    func_800FDD50_CoinBlockBash(m, 0.0f, 0.0f, -120.0f, &a);
    func_800FDF20_CoinBlockBash(m, &r);
    func_80025798(b->model, a.x, a.y, a.z);
    func_800257E4(b->model, r.x, r.y, r.z);
    h = func_800FE284_CoinBlockBash(&b->unk_10);
    func_80025798(b->unk_02, b->unk_10.x, h, b->unk_10.z);
    func_800FDD50_CoinBlockBash(m, 0.0f, 90.0f, 0.0f, &a);
    a.x -= b->unk_10.x;
    a.z -= b->unk_10.z;
    r.y = func_800FDEA0_CoinBlockBash(a.z, a.x);
    func_800257E4(b->unk_02, 0.0f, r.y, 0.0f);
    a.z = sqrtf(a.x * a.x + a.z * a.z) / 90.0 + 1.0;
    s = (1.0 - (b->unk_10.y - h) / 800.0) * 1.2;
    func_80025830(b->unk_02, s, 1.0f, s * a.z);
    func_800258EC(b->unk_02, 4, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800F8D98_CoinBlockBash);
#endif
void func_800F96A0_CoinBlockBash(omObjData* obj, Matrix4f parent) {
    Matrix4f m;

    if (D_80102538_CoinBlockBash.unk_08 != 0) {
        if (--D_80102538_CoinBlockBash.unk_08 == 0) {
            D_80102538_CoinBlockBash.unk_0C = D_80102538_CoinBlockBash.unk_0D = 1;
        }
    }
    if (D_80102538_CoinBlockBash.unk_0A != 0) {
        if (--D_80102538_CoinBlockBash.unk_0A == 0) {
            D_80102538_CoinBlockBash.unk_0C = D_80102538_CoinBlockBash.unk_0D = 0;
        }
    }
    if (D_80102538_CoinBlockBash.unk_0C | D_80102538_CoinBlockBash.unk_0D) {
        guMtxIdentF(m);
        MtxTranslate(m, obj->trans.x, obj->trans.y, obj->trans.z);
        MtxRotate(m, obj->rot.x, obj->rot.y, obj->rot.z);
        MtxScale(m, obj->scale.x, obj->scale.y, obj->scale.z);
        guMtxCatF(parent, m, m);
        guMtxIdentF(D_80102538_CoinBlockBash.unk_34);
        MtxInv(m, D_80102538_CoinBlockBash.unk_34);
        func_8009EA40(m, -m[3][0], -m[3][1], -m[3][2]);
        guMtxCatF(m, D_80102538_CoinBlockBash.unk_34, D_80102538_CoinBlockBash.unk_34);
        D_80102538_CoinBlockBash.unk_34[3][2] += -70.0;
    }
}
// NON_MATCHING: KMC as nop placement after the func_800FDD50 call (mul fix), one float register
#ifdef NON_MATCHING
s32 func_800F9814_CoinBlockBash(f32 x, f32 y, f32 z, f32 r) {
    Vec p;
    f32 dist;
    f32 lim;
    f32 dy;

    func_800FDD50_CoinBlockBash(D_80102538_CoinBlockBash.unk_34, x, y, z, &p);
    lim = r * r + 10000.0;
    dist = p.x * p.x + p.z * p.z;
    if (lim < dist) {
        return 0;
    }
    if (r + 90.0 < abs((s32)p.y)) {
        return 0;
    }
    dy = abs((s32)p.y) - 90.0;
    if (dy <= 0.0f) {
        return 1;
    }
    dy = sqrtf(dy * dy + r * r);
    lim = dy * dy + 10000.0;
    if (lim < dist) {
        return 0;
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800F9814_CoinBlockBash);
#endif
void func_800F99A0_CoinBlockBash(void) {
    CBBCoin* c;
    s32 i;

    if (D_80102538_CoinBlockBash.unk_0D != 0 && D_80102538_CoinBlockBash.unk_06 == 0) {
        c = D_80103294_CoinBlockBash;
        for (i = 0; i < 9; i++, c++) {
            if (c->unk_10 != 0 && func_800F9814_CoinBlockBash(c->pos.x, c->pos.y, c->pos.z, c->unk_1C * 1.2) != 0) {
                func_800FF904_CoinBlockBash(D_801025B0_CoinBlockBash[D_80102538_CoinBlockBash.unk_04].obj, 10, c);
                func_80060F04(D_80102538_CoinBlockBash.unk_04, 2, 3, 10);
            }
        }
    }
}
void func_800F9A98_CoinBlockBash(void) {
    Vec pos;
    Vec rot;
    s32 pad[2]; /* retail's frame */
    CBBPlayer* p;
    omObjData* o;
    omObjData* hammer;
    s32 i;
    f32 a;

    if (D_80102538_CoinBlockBash.unk_0C == 0) {
        return;
    }
    hammer = D_801025B0_CoinBlockBash[D_80102538_CoinBlockBash.unk_04].obj;
    p = D_801025B0_CoinBlockBash;
    for (i = 0; i < D_801031FC_CoinBlockBash; i++, p++) {
        if (i == D_80102538_CoinBlockBash.unk_04 || p->unk_44 != 0 || (p->flags & 0x10)) {
            continue;
        }
        o = p->obj;
        if (func_800F9814_CoinBlockBash(o->trans.x, o->trans.y + p->unk_04, o->trans.z, p->unk_04) == 0) {
            continue;
        }
        if (D_80102538_CoinBlockBash.unk_06 == 0) {
            p->state = 8;
            p->unk_50 = 0;
            pos.x = o->trans.x;
            pos.y = o->trans.y + p->unk_04;
            pos.z = o->trans.z;
            rot.x = -90.0f;
            rot.y = rot.z = 0.0f;
            p->unk_42 = 60;
        } else {
            p->state = 10;
            a = func_800FDEA0_CoinBlockBash(hammer->trans.z - o->trans.z, hammer->trans.x - o->trans.x) + 90.0;
            if (a >= 360.0) {
                a -= 360.0;
            }
            o->rot.y = a;
            p->unk_7C = a;
            p->unk_2C = a;
            pos.x = o->trans.x;
            pos.y = o->trans.y + p->unk_04;
            pos.z = o->trans.z;
            rot.x = rot.z = 0.0f;
            rot.y = o->rot.y;
        }
        func_80017C0C(o, 5, pos.x, pos.y, pos.z, rot.x, rot.y);
        PlaySound(0x271);
        func_80060F04(D_8010253C_CoinBlockBash, 2, 3, 10);
        p->unk_50 = 0;
    }
}
s32 func_800F9CF0_CoinBlockBash(CBBPlayer* p, Vec* pos, Vec* vel, Vec* out) {
    CBBCoin* c;
    s32 i;
    s32 res;
    f32 r;
    f32 ax;
    f32 az;
    f32 top;

    res = 0;
    out->x = pos->x;
    out->y = pos->y;
    out->z = pos->z;
    c = D_80103294_CoinBlockBash;
    for (i = 0; i < 9; i++, c++) {
        if (c->unk_10 == 0) {
            continue;
        }
        r = p->unk_04 + c->unk_1C;
        if (!(abs((s32)(pos->x - c->pos.x)) <= r)) {
            continue;
        }
        if (!(abs((s32)(pos->z - c->pos.z)) <= r)) {
            continue;
        }
        if (!(c->pos.y - pos->y < r + p->unk_04)) {
            continue;
        }
        ax = abs((s32)(p->pos.x - c->pos.x));
        az = abs((s32)(p->pos.z - c->pos.z));
        if ((ax < r) & (az < r)) {
            if (!(vel->y > 0.0f)) {
                continue;
            }
            res = 1;
            top = c->pos.y - (r + p->unk_04);
            if ((p->flags & 0x40) && func_800FF904_CoinBlockBash(p->obj, 1, c) != 0) {
                res = -1;
            } else {
                out->y = top;
            }
            p->flags &= ~0x40;
            func_80060F04(p->obj->work[0], 2, 3, 10);
        } else {
            if (az <= ax) {
                if (pos->x > c->pos.x) {
                    out->x = r + c->pos.x;
                } else {
                    out->x = c->pos.x - r;
                }
            } else {
                if (pos->z > c->pos.z) {
                    out->z = r + c->pos.z;
                } else {
                    out->z = c->pos.z - r;
                }
            }
            res = -1;
        }
    }
    return res;
}
// NON_MATCHING: delay-slot fill: hit = 0 lands in the active test's slot (one instruction short)
#ifdef NON_MATCHING
void func_800F9FE4_CoinBlockBash(void) {
    CBBDrop* d;
    CBBPlayer* p;
    omObjData* o;
    s32 i;
    s32 j;
    s32 hit;
    f32 dx;
    f32 dy;
    f32 dz;

    d = D_80103290_CoinBlockBash;
    for (i = 0; i < 9; i++, d++) {
        if (d->active != 0) {
            p = D_801025B0_CoinBlockBash;
            j = 0;
            hit = 0;
            for (; j < D_801031FC_CoinBlockBash; j++, p++) {
                if ((p->flags & 4) && !(p->flags & 0x10)) {
                    o = p->obj;
                    dx = d->pos.x - o->trans.x;
                    dy = 50.0 - (o->trans.y + p->unk_04);
                    dz = d->pos.z - o->trans.z;
                    if (sqrtf(dx * dx + dy * dy + dz * dz) <= d->radius + p->unk_04) {
                        hit = 1;
                        func_800FFD78_CoinBlockBash(d, o);
                        GwPlayer[o->work[0]].coins_mg += D_80101B20_CoinBlockBash[d->type][1];
                        p->unk_62 |= 1;
                        if (d->type == 1) {
                            func_80060F04(o->work[0], 2, 3, 10);
                        }
                        break;
                    }
                }
            }
            if (hit == 0 && D_80102538_CoinBlockBash.unk_0C != 0 &&
                func_800F9814_CoinBlockBash(d->pos.x, d->pos.y + d->radius, d->pos.z, d->radius) != 0) {
                hit = 1;
                p = &D_801025B0_CoinBlockBash[D_80102538_CoinBlockBash.unk_04];
                o = p->obj;
                func_800FFD78_CoinBlockBash(d, o);
                GwPlayer[o->work[0]].coins_mg += D_80101B20_CoinBlockBash[d->type][1];
                p->unk_62 |= 1;
                if (d->type == 1) {
                    func_80060F04(o->work[0], 2, 3, 10);
                }
            }
        }
    }
    if (D_8010253C_CoinBlockBash < 0 && D_801024F0_CoinBlockBash.state == 1) {
        p = D_801025B0_CoinBlockBash;
        for (j = 0; j < D_801031FC_CoinBlockBash; j++, p++) {
            if ((p->flags & 4) && !(p->flags & 0x10)) {
                o = p->obj;
                dx = D_80102538_CoinBlockBash.unk_10.x - o->trans.x;
                dy = D_80102538_CoinBlockBash.unk_10.y - (o->trans.y + 50.0);
                dz = D_80102538_CoinBlockBash.unk_10.z - o->trans.z;
                if (dx * dx + dy * dy + dz * dz <= 2879.9999999999995) {
                    func_800FBF70_CoinBlockBash(o);
                    return;
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800F9FE4_CoinBlockBash);
#endif
s32 func_800FA388_CoinBlockBash(CBBPlayer* self, Vec* pos, Vec* rot, Vec* off, f32 r) {
    Vec hit;
    Vec p;
    Vec q;
    Matrix4f m;
    CBBPlayer* pl;
    omObjData* o;
    s32 res;
    s32 i;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 a;

    res = 0;
    if (self->unk_44 != 0) {
        return 0;
    }
    func_800A2A50(m);
    MtxTranslate(m, pos->x, pos->y, pos->z);
    MtxRotate(m, rot->x, rot->y, rot->z);
    func_800FDD50_CoinBlockBash(m, off->x, off->y, off->z, &hit);
    pl = D_801025B0_CoinBlockBash;
    for (i = 0; i < D_801031FC_CoinBlockBash; i++, pl++) {
        if (pl == self || pl->unk_44 != 0) {
            continue;
        }
        o = pl->obj;
        if (sqrtf((o->trans.x - hit.x) * (o->trans.x - hit.x) +
                  (o->trans.y + pl->unk_04 - hit.y) * (o->trans.y + pl->unk_04 - hit.y) +
                  (o->trans.z - hit.z) * (o->trans.z - hit.z)) <= r + pl->unk_04) {
            pl->state = 9;
            a = func_800FDEA0_CoinBlockBash(pos->z - o->trans.z, pos->x - o->trans.x);
            if (a >= 360.0) {
                a -= 360.0;
            }
            o->rot.y = a;
            pl->unk_7C = a;
            pl->unk_2C = a;
            p.x = o->trans.x;
            p.y = o->trans.y + pl->unk_04;
            p.z = o->trans.z;
            q.x = q.z = 0.0f;
            q.y = o->rot.y;
            func_80017C0C(o, 5, hit.x, hit.y, hit.z, 0.0f, rot->y + 180.0f);
            pl->unk_50 = 0;
            res = 1;
        }
    }
    return res;
}
s32 func_800FA600_CoinBlockBash(f32 x, f32 z, f32* best) {
    CBBCoin* c;
    s32 i;
    s16 res;
    f32 dx;
    f32 dz;
    f32 d;

    res = -1;
    *best = 10000.0f;
    c = D_80103294_CoinBlockBash;
    for (i = 0; i < 9; i++, c++) {
        if (c->unk_10 != 0) {
            dx = c->pos.x - x;
            dz = c->pos.z - z;
            d = sqrtf(dx * dx + dz * dz);
            if (*best > d * (((((rand8() & 0xFF) << 8) | (rand8() & 0xFF)) * 60 / 65536 - 30) * 0.01 + 1.0) &&
                D_8010320E_CoinBlockBash[i] == 0) {
                *best = d;
                res = i;
            }
        }
    }
    return res;
}
s32 func_800FA7AC_CoinBlockBash(f32 x, f32 z, f32* best) {
    CBBDrop* d;
    s32 i;
    s16 res;
    f32 dx;
    f32 dz;
    f32 dist;

    res = -1;
    *best = 10000.0f;
    d = D_80103290_CoinBlockBash;
    for (i = 0; i < 9; i++, d++) {
        if (d->active != 0) {
            dx = d->pos.x - x;
            dz = d->pos.z - z;
            dist = sqrtf(dx * dx + dz * dz);
            if (*best > dist * (((((rand8() & 0xFF) << 8) | (rand8() & 0xFF)) * 60 / 65536 - 30) * 0.01 + 1.0)) {
                *best = dist;
                res = i;
            }
        }
    }
    return res;
}
s16 func_800FA944_CoinBlockBash(CBBPlayer* self, f32* best) {
    omObjData* o;
    CBBPlayer* p;
    s32 i;
    s16 res;
    f32 x;
    f32 z;
    f32 dx;
    f32 dz;
    f32 d;

    o = self->obj;
    x = o->trans.x;
    z = o->trans.z;
    res = -1;
    *best = 10000.0f;
    p = D_801025B0_CoinBlockBash;
    for (i = 0; i < D_801031FC_CoinBlockBash; i++, p++) {
        if (p != self && !(p->flags & 0x10) && p->unk_44 == 0) {
            o = p->obj;
            dx = o->trans.x - x;
            dz = o->trans.z - z;
            d = sqrtf(dx * dx + dz * dz);
            if (d < *best) {
                *best = d;
                res = i;
            }
        }
    }
    return res;
}
void func_800FAA7C_CoinBlockBash(void) {
    CBBPlayer* p;
    s32 i;
    s32 j;
    s32 t;

    p = D_801025B0_CoinBlockBash;
    for (i = 0; i < 4; i++, p++) {
        func_8009B770(p, 0, sizeof(CBBPlayer));
        p->unk_58 = -1;
        p->unk_66 = -1;
        D_80103200_CoinBlockBash[i] = i;
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (i == j) {
                continue;
            }
            if ((((rand8() & 0xFF) << 8) | (rand8() & 0xFF)) * 100 / 65536 > 40) {
                t = D_80103200_CoinBlockBash[i];
                D_80103200_CoinBlockBash[i] = D_80103200_CoinBlockBash[j];
                D_80103200_CoinBlockBash[j] = t;
            }
        }
    }
    D_8010320C_CoinBlockBash = -1;
    for (i = 0; i < 9; i++) {
        D_801031E8_CoinBlockBash[i] = -1;
    }
    D_801031FC_CoinBlockBash = 0;
    D_800F3FB0[D_800F2BC0++] = omAddObj(4, 9, 0x15, -1, func_800FACEC_CoinBlockBash);
    D_800F3FB0[D_800F2BC0++] = omAddObj(5, 9, 0x15, -1, func_800FACEC_CoinBlockBash);
    D_800F3FB0[D_800F2BC0++] = omAddObj(6, 9, 0x15, -1, func_800FACEC_CoinBlockBash);
    D_800F3FB0[D_800F2BC0++] = omAddObj(7, 9, 0x15, -1, func_800FACEC_CoinBlockBash);
}
void func_800FACEC_CoinBlockBash(omObjData* obj) {
    f32 start[4][2] = { { 4.0f, 4.0f }, { -4.0f, 4.0f }, { -4.0f, -4.0f }, { 4.0f, -4.0f } };
    CBBQuad rot = D_80101D18_CoinBlockBash;
    s32 motA[5] = { 0xF, 0x38, 0x39, 0x3A, 0x3B };
    s32 motB[5] = { 0x10, 0x3C, 0x3D, 0x3E, 0x3F };
    CBBPlayerWork* w;
    CBBPlayer* p;
    s32 dir;
    s32 i;
    s32 r;
    s16 id;

    id = D_801031FC_CoinBlockBash++;
    D_80103208_CoinBlockBash = D_801031FC_CoinBlockBash;
    dir = D_800C59AC[GwPlayer[id].character].unk_00;
    if (GwPlayer[id].group == 0 && D_801025AC_CoinBlockBash < 0) {
        D_801025AC_CoinBlockBash = id;
    }
    obj->unk_50 = func_80023684(sizeof(CBBPlayerWork), 0x7918);
    func_8009B770(obj->unk_50, 0, sizeof(CBBPlayerWork));
    w = obj->unk_50;
    w->unk_D8 = func_80023684(obj->mtncnt * sizeof(unkGlobalStruct_00), 0x7918);
    func_8009B770(w->unk_D8, 0, obj->mtncnt * sizeof(unkGlobalStruct_00));
    w->unk_56 = GwPlayer[id].port;
    w->unk_C0 = 0xFFFF;
    for (i = 0; i < obj->mtncnt; i++) {
        obj->motion[i] = -1;
    }
    for (i = 0; i < obj->mdlcnt; i++) {
        obj->model[i] = 0;
    }
    if (D_801025AC_CoinBlockBash == id) {
        obj->model[0] = LoadFormFile(dir | D_800C59AC[GwPlayer[id].character].unk_08, 0x2B9);
    } else {
        obj->model[0] = LoadFormFile(dir | D_800C59AC[GwPlayer[id].character].unk_04, 0x2B9);
    }
    obj->func_ptr = func_800FC2AC_CoinBlockBash;
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    if (D_801031E8_CoinBlockBash[1] < 0) {
        obj->model[1] = D_801031E8_CoinBlockBash[1] = func_800174F4(6, 0x699);
        obj->model[3] = D_801031E8_CoinBlockBash[3] = LoadFormFile(0x19, 0x68D);
        obj->model[4] = D_801031E8_CoinBlockBash[4] = LoadFormFile(0x1A, 0x68D);
        obj->model[5] = D_801031E8_CoinBlockBash[5] = LoadFormFile(0x1C, 0x68D);
    } else {
        obj->model[1] = func_80023FC8(D_801031E8_CoinBlockBash[1]);
        obj->model[3] = func_80023FC8(D_801031E8_CoinBlockBash[3]);
        obj->model[4] = func_80023FC8(D_801031E8_CoinBlockBash[4]);
        obj->model[5] = func_80023FC8(D_801031E8_CoinBlockBash[5]);
    }
    func_8001874C(obj, 0, dir, 1, 0);
    func_8001874C(obj, 1, dir | 1, 1, 0);
    func_8001874C(obj, 3, dir | 3, 1, 0);
    func_8001874C(obj, 4, dir | 4, 1, 30);
    func_8001874C(obj, 5, dir | 5, 1, 20);
    func_8001874C(obj, 8, dir | 0xA, 1, 40);
    func_8001874C(obj, 9, dir | 0x2F, 1, 0);
    func_8001874C(obj, 0xC, dir | 0x18, 1, 15);
    func_8001874C(obj, 0xD, dir | 0x67, 1, 14);
    func_8001874C(obj, 0x10, dir | 0x1C, 1, 45);
    func_8001874C(obj, 0x11, dir | 0x62, 1, 10);
    func_8001874C(obj, 0x12, dir | 0x41, 1, 80);
    func_8001874C(obj, 0x13, dir | 0x44, 1, 60);
    func_8001874C(obj, 0x14, dir | 0x45, 1, 45);
    r = (((rand8() & 0xFF) << 8) | (rand8() & 0xFF)) / 32768;
    r = r < 2 ? r : 0;
    func_8001874C(obj, 0xA, dir | motA[r], 1, 120);
    func_8001874C(obj, 0xB, dir | motB[r], 1, 120);
    obj->work[0] = id;
    p = &D_801025B0_CoinBlockBash[id];
    p->obj = obj;
    p->flags = 0xD;
    p->state = 0;
    obj->trans.x = p->pos.x = start[D_80103200_CoinBlockBash[id]][0] * 100.0;
    obj->trans.y = p->pos.y = 0.0f;
    obj->trans.z = p->pos.z = start[D_80103200_CoinBlockBash[id]][1] * 100.0;
    i = 1;
    if (!(obj->trans.x > 0.0)) {
        i = 0;
    }
    if (obj->trans.z > 0.0) {
        i |= 2;
    }
    p->unk_2C = p->unk_7C = obj->rot.y = rot.v[i];
    p->unk_56 = 8;
    p->unk_04 = 50.0f;
    p->unk_38 = -4.628099f;
    D_800B8980 = 12.5f;
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800F7680_CoinBlockBash(obj, 0x13, "item_hook");
    func_800F7680_CoinBlockBash(obj, 0x14, "item_hook");
}
void func_800FB490_CoinBlockBash(void) {
    CBBPlayer* p;
    s32 i;

    p = D_801025B0_CoinBlockBash;
    for (i = 0; i < 4; i++, p++) {
        if (p->mtx[0] != NULL) {
            func_80023728(p->mtx[0]);
        }
        if (p->mtx[1] != NULL) {
            func_80023728(p->mtx[1]);
        }
    }
}
void func_800FB4F4_CoinBlockBash(omObjData* obj) {
    CBBPlayer* p;
    s16 port;
    f32 x;
    f32 y;
    f32 a;

    p = func_800F7644_CoinBlockBash(obj);
    port = func_800F7674_CoinBlockBash(obj);
    x = ContStkX[port];
    y = ContStkY[port];
    if (abs((s32)x) >= 5 || abs((s32)y) >= 5) {
        a = func_800FDEA0_CoinBlockBash(x, y) + 90.0 + 29.0;
        p->unk_7C = a;
        if (a >= 360.0) {
            p->unk_7C = a - 360.0;
        }
    }
    p->unk_80 = sqrtf(x * x + y * y) / 64.0;
    if (p->unk_80 < 0.2) {
        p->unk_80 = 0.0f;
    } else if (p->unk_80 > 1.0) {
        p->unk_80 = 1.0f;
    }
    if (ContBtnTrg[port] & 0x8000) {
        p->unk_84 = 1;
    }
    if (ContBtnTrg[port] & 0x2010) {
        p->unk_86 = 1;
    }
    if (ContBtnTrg[port] & 0x4000) {
        p->unk_88 = 1;
    }
}
void func_800FB71C_CoinBlockBash(omObjData* obj, CBBPlayer* p) {
    f32 dDrop;
    f32 dCoin;
    s32 iDrop;
    s32 iCoin;

    if (D_8010253C_CoinBlockBash < 0 && (((rand8() & 0xFF) << 8) | (rand8() & 0xFF)) * 100 / 65536 < 30) {
        p->unk_9A = 0;
        p->unk_98 = 3;
        return;
    }
    iDrop = (s16)func_800FA7AC_CoinBlockBash(obj->trans.x, obj->trans.z, &dDrop);
    iCoin = (s16)func_800FA600_CoinBlockBash(obj->trans.x, obj->trans.z, &dCoin);
    if (dDrop < 400.0 || dDrop * 0.7 <= dCoin) {
        if (iDrop >= 0) {
            p->unk_9C = iDrop;
            p->unk_9A = 0;
            p->unk_98 = 2;
            p->unk_8C.x = D_80103290_CoinBlockBash[iDrop].pos.x;
            p->unk_8C.y = D_80103290_CoinBlockBash[iDrop].pos.y;
            p->unk_8C.z = D_80103290_CoinBlockBash[iDrop].pos.z;
        }
    } else if (iCoin >= 0) {
        p->unk_9C = iCoin;
        p->unk_9A = 0;
        p->unk_98 = 1;
        p->unk_8C.x = D_80103294_CoinBlockBash[iCoin].pos.x;
        p->unk_8C.y = D_80103294_CoinBlockBash[iCoin].pos.y;
        p->unk_8C.z = D_80103294_CoinBlockBash[iCoin].pos.z;
        p->unk_9E = (((rand8() & 0xFF) << 8) | (rand8() & 0xFF)) * 3 / 65536;
    }
}
// NON_MATCHING: register allocation and branch layout (frame, case 1 count test); logic checked against the asm
#ifdef NON_MATCHING
void func_800FB900_CoinBlockBash(omObjData* obj) {
    f32 d[4]; /* d[0]: distance; retail's frame holds 16 bytes here */
    CBBPlayer* p;
    CBBBlock* b;
    omObjData* o;
    f32 maxspd;
    f32 dist;
    f32 dx;
    f32 dz;
    s32 chance;
    s16 idx;
    s16 i;
    s32 level;

    p = func_800F7644_CoinBlockBash(obj);
    if (D_801024F0_CoinBlockBash.timer < 4) {
        return;
    }
    level = (u8)(GwPlayer[obj->work[0]].cpu_difficulty & 3);
    maxspd = 1.0 - (f32)(3 - level) * 0.03;
    if (p->unk_98 != 0) {
        p->unk_80 = 0.0f;
    }
    switch (p->unk_98) {
    case 0:
        func_800FB71C_CoinBlockBash(obj, p);
        break;
    case 1:
        dx = p->unk_8C.x - obj->trans.x;
        dz = p->unk_8C.z - obj->trans.z;
        d[0] = dist = sqrtf(dx * dx + dz * dz);
        p->unk_9E++;
        if (dist <= 100.0 && !(p->unk_9E & 3)) {
            if ((((rand8() & 0xFF) << 8) | (rand8() & 0xFF)) * 100 / 65536 < ((level << 2) | level) * 2 + 15) {
                p->unk_84 = 1;
            }
        }
        p->unk_80 = d[0] / (f32)((2.0 - (f32)level / 2.0) * 100.0);
        if (p->unk_80 > 0.2) {
            if (maxspd <= p->unk_80) {
                p->unk_80 = maxspd;
            }
            p->unk_7C = func_800FDEA0_CoinBlockBash(dz, dx);
        }
        D_8010320E_CoinBlockBash[p->unk_9C] = 1;
        if ((p->unk_9A > 150 || D_80103294_CoinBlockBash[p->unk_9C].unk_10 == 0) && (p->flags & 4)) {
            p->unk_98 = 0;
            D_8010320E_CoinBlockBash[p->unk_9C] = 0;
        }
        break;
    case 2:
        idx = p->unk_9C;
        dx = p->unk_8C.x - obj->trans.x;
        dz = p->unk_8C.z - obj->trans.z;
        d[0] = dist = sqrtf(dx * dx + dz * dz);
        p->unk_80 = dist / 50.0;
        if (p->unk_64 != 0 && dist < 140.0 && (s16)func_800FA944_CoinBlockBash(p, d) >= 0 && d[0] < 200.0) {
            p->unk_88 = 1;
        }
        if (!(p->unk_80 >= 0.2)) {
            p->unk_80 = 0.0f;
        } else {
            if (maxspd <= p->unk_80) {
                p->unk_80 = maxspd;
            }
            p->unk_7C = func_800FDEA0_CoinBlockBash(dz, dx);
        }
        if (D_80103290_CoinBlockBash[idx].active != 0) {
            p->unk_8C.x = D_80103290_CoinBlockBash[idx].pos.x;
            p->unk_8C.y = D_80103290_CoinBlockBash[idx].pos.y;
            p->unk_8C.z = D_80103290_CoinBlockBash[idx].pos.z;
        } else {
            p->unk_98 = 0;
        }
        break;
    case 3:
        b = &D_80102538_CoinBlockBash;
        dx = D_80102548_CoinBlockBash - obj->trans.x;
        dz = D_80102550_CoinBlockBash - obj->trans.z;
        d[0] = sqrtf(dx * dx + dz * dz);
        p->unk_80 = maxspd;
        p->unk_7C = func_800FDEA0_CoinBlockBash(dz, dx);
        if (b->unk_04 >= 0) {
            p->unk_98 = 0;
        }
        break;
    }
    i = func_800FA944_CoinBlockBash(p, d);
    if (i >= 0 && d[0] < 150.0) {
        if (p->unk_64 != 0) {
            chance = level * 15;
        } else {
            chance = level * 6;
        }
        if ((((rand8() & 0xFF) << 8) | (rand8() & 0xFF)) * 100 / 65536 < chance) {
            o = D_801025B0_CoinBlockBash[i].obj;
            dx = o->trans.x - obj->trans.x;
            dz = o->trans.z - obj->trans.z;
            p->unk_7C = func_800FDEA0_CoinBlockBash(dz, dx);
            p->unk_88 = 1;
            p->unk_84 = 0;
        }
    }
    if (++p->unk_9A >= 0x7800) {
        p->unk_9A -= 0x800;
    }
    level = p->unk_98 == 3 ? 30 : 12;
    if (level < p->unk_9A && !(p->unk_9A & 0xF) && (p->flags & 4)) {
        if (p->unk_98 == 1) {
            D_8010320E_CoinBlockBash[p->unk_9C] = 0;
        }
        func_800FB71C_CoinBlockBash(obj, p);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800FB900_CoinBlockBash);
#endif
void func_800FBF70_CoinBlockBash(omObjData* obj) {
    CBBPlayer* p;

    p = func_800F7644_CoinBlockBash(obj);
    func_80028498(obj->model[0], D_800F2B7C[obj->motion[0x12]].unk_08, 1);
    p->unk_58 = 1;
    p->unk_64 = 1;
    D_80102538_CoinBlockBash.unk_04 = obj->work[0];
    D_80102538_CoinBlockBash.unk_08 = D_80102538_CoinBlockBash.unk_0A = D_80102538_CoinBlockBash.unk_0C =
        D_80102538_CoinBlockBash.unk_0D = 0;
    func_800258EC(D_80102538_CoinBlockBash.model, 0x4000, 0x4000);
    func_8002859C(D_80102538_CoinBlockBash.model, obj->model[0], "item_hook");
    func_800F77BC_CoinBlockBash(obj, 0);
    if (D_801024F0_CoinBlockBash.state == 1) {
        p->unk_44 = 60;
    }
}
void func_800FC054_CoinBlockBash(omObjData* obj) {
    CBBBlock* b;
    CBBPlayer* p;

    b = &D_80102538_CoinBlockBash;
    p = func_800F7644_CoinBlockBash(obj);
    func_800284E4(obj->model[0]);
    p->unk_58 = -1;
    p->unk_64 = 0;
    func_800258EC(b->model, 4, 0);
    D_8010253C_CoinBlockBash = -1;
    D_80102545_CoinBlockBash = 0;
    D_80102544_CoinBlockBash = 0;
    D_80102542_CoinBlockBash = 0;
    D_80102540_CoinBlockBash = 0;
    D_80102546_CoinBlockBash = 0;
    D_80102548_CoinBlockBash = obj->trans.x;
    D_8010254C_CoinBlockBash = obj->trans.y + 100.0;
    D_80102550_CoinBlockBash = obj->trans.z;
    D_80102554_CoinBlockBash = func_800AEAC0(obj->rot.y) * 0.3 * 100.0;
    D_80102558_CoinBlockBash = 50.0f;
    D_8010255C_CoinBlockBash = func_800AEFD0(obj->rot.y) * 0.3 * 100.0;
    b->unk_28.x = (((rand8() & 0xFF) << 8) | (rand8() & 0xFF)) * 360 / 65536;
    b->unk_28.y = (((rand8() & 0xFF) << 8) | (rand8() & 0xFF)) * 360 / 65536;
    b->unk_28.z = (((rand8() & 0xFF) << 8) | (rand8() & 0xFF)) * 360 / 65536;
    func_800258EC(D_80102538_CoinBlockBash.model, 0x4000, 0);
}
void func_800FC2AC_CoinBlockBash(omObjData* obj) {
    Vec off;
    Vec rot;
    Vec pos;
    Vec ex;
    CBBPlayer* p;
    s32 hit;
    s32 c;
    s16 m;
    s32 id;
    s32 k;
    u8 chr;
    f32 d;
    f32 spd;

    p = func_800F7644_CoinBlockBash(obj);
    func_800F766C_CoinBlockBash(obj);
    id = obj->work[0];
    chr = GwPlayer[id].character;
    if (D_801024F0_CoinBlockBash.state == 1) {
        if (!(GwPlayer[id].flags & 1)) {
            func_800FB4F4_CoinBlockBash(obj);
        } else {
            func_800FB900_CoinBlockBash(obj);
        }
    } else if (D_801024F0_CoinBlockBash.state == 0 && p->unk_64 != 0 &&
               (u32)((u16)D_801024F0_CoinBlockBash.timer - 16) < 44) {
        p->unk_88 = 1;
    }
    pos.x = obj->trans.x;
    pos.y = obj->trans.y;
    pos.z = obj->trans.z;
    ex.x = ex.y = ex.z = 0.0f;
    if (p->unk_66 >= 0) {
        p->unk_68++;
        if (p->unk_68 >= p->mtxCount[p->unk_66]) {
            p->unk_68 = p->mtxCount[p->unk_66] - 1;
        }
    }
    switch (p->state) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        if (p->unk_42 != 0) {
            p->unk_80 = 0.5f;
        }
        if (p->flags & 4) {
            p->unk_3C = 0.4 - p->unk_80 * 0.2;
        } else {
            p->unk_3C = 0.2f;
        }
        p->vel.x *= 1.0 - p->unk_3C;
        p->vel.z *= 1.0 - p->unk_3C;
        if (p->unk_42 != 0) {
            if (p->unk_42 < 0) {
                break;
            }
            if ((p->flags & 4) && p->unk_42 == 8 && p->unk_66 < 0 && p->unk_5A == 0) {
                func_800F77BC_CoinBlockBash(obj, 0);
            }
            hit = 0;
            if (p->state == 5 && p->unk_42 == 12) {
                off.x = 0.0f;
                off.y = 50.0f;
                off.z = 80.0f;
                rot.x = rot.z = off.x;
                rot.y = obj->rot.y;
                hit = func_800FA388_CoinBlockBash(p, &pos, &rot, &off, 40.0f);
            } else if (p->state == 6 && p->unk_42 == 8) {
                off.x = 0.0f;
                off.y = 30.0f;
                off.z = 80.0f;
                rot.x = rot.z = off.x;
                rot.y = obj->rot.y;
                hit = func_800FA388_CoinBlockBash(p, &pos, &rot, &off, 50.0f);
            }
            if (hit != 0) {
                func_80060F04(id, 2, 3, 10);
            }
            if (p->unk_46 != 0) {
                p->unk_46--;
            }
            if (--p->unk_42 != 0) {
                break;
            }
            p->unk_80 = 0.0f;
            if (p->unk_5A != 0) {
                func_800F77BC_CoinBlockBash(obj, (u8)p->unk_5A);
                p->unk_42 = p->unk_5C;
                p->unk_5C = 0;
                p->unk_5A = 0;
                break;
            }
            obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
            if (p->unk_64 != 0) {
                func_80028498(obj->model[0], D_800F2B7C[obj->motion[0x12]].unk_08, 1);
                p->unk_58 = 1;
                p->unk_66 = -1;
                func_800F77BC_CoinBlockBash(obj, 0);
            }
        }
        p->flags &= ~0x10;
        p->unk_38 = -4.628099f;
        if (p->flags & 4) {
            if (p->unk_64 == 0) {
                if (p->unk_84 != 0) {
                    p->flags = (p->flags & 0xF3) | 0x40;
                    p->state = 4;
                    ex.y = 50.909092f;
                    p->vel.y = 0.0f;
                    func_80060618(0x128, id);
                    func_800F77BC_CoinBlockBash(obj, 5);
                } else if (p->unk_88 != 0) {
                    p->unk_2C = p->unk_7C;
                    p->state = 5;
                    p->unk_4E = 0;
                    p->unk_42 = 20;
                    func_80060618(0x136, id);
                    func_800F77BC_CoinBlockBash(obj, 4);
                    break;
                }
            } else {
                hit = -1;
                if (p->unk_84 != 0) {
                    hit = 0;
                } else if (p->unk_88 != 0) {
                    hit = 1;
                }
                if (hit >= 0) {
                    p->unk_2C = p->unk_7C;
                    p->unk_66 = hit;
                    p->unk_42 = D_80101BD4_CoinBlockBash[hit].timer;
                    func_80060540(0x272, id);
                    func_800F77BC_CoinBlockBash(obj, D_80101BD4_CoinBlockBash[hit].motion);
                    func_800284E4(obj->model[0]);
                    k = GwPlayer[obj->work[0]].character * 2 + hit;
                    D_80102538_CoinBlockBash.unk_06 = hit;
                    D_80102538_CoinBlockBash.unk_08 = D_80101BDC_CoinBlockBash[k][0];
                    D_80102538_CoinBlockBash.unk_0A = D_80101BDC_CoinBlockBash[k][1];
                    p->unk_58 = -1;
                    p->unk_68 = -1;
                    break;
                }
            }
        } else if (p->state == 4) {
            if (p->vel.y < 0.0 && obj->trans.y < 100.0) {
                func_800F77BC_CoinBlockBash(obj, 0x11);
            }
        } else if (p->state == 6) {
            if (obj->trans.y < 100.0 && p->unk_4E >= 16) {
                func_800F77BC_CoinBlockBash(obj, 0x11);
            }
        }
        if (p->unk_64 != 0) {
            p->unk_80 *= 0.7;
        }
        p->unk_30 = p->unk_30 + (p->unk_80 - p->unk_30) * 0.25;
        if (p->unk_80 == 0.0 && p->unk_30 < 0.05) {
            p->unk_30 = 0.0f;
        }
        if (((p->flags & 4) || p->state == 4) && !(p->state == 2 || p->state == 3)) {
            p->unk_2C = p->unk_7C;
            spd = p->unk_30 * D_800B8980 * p->unk_3C;
            ex.x = -func_800AEFD0(p->unk_2C + 90.0) * spd;
            ex.z = func_800AEAC0(p->unk_2C + 90.0) * spd;
        }
        d = p->unk_7C - obj->rot.y;
        if (d >= 0.0f) {
            if (d > 180.0) {
                d -= 360.0;
            }
        } else if (d < -180.0) {
            d += 360.0;
        }
        d = abs((s32)d);
        if (!(p->flags & 4)) {
            break;
        }
        if (!(p->state == 2 || p->state == 3)) {
            p->state = 0;
            p->flags |= 8;
            m = 0;
            if (p->unk_80 > 0.1) {
                m = 3;
                if (p->unk_80 < 0.5) {
                    m = 1;
                }
            }
            if (sqrtf(p->vel.x * p->vel.x + p->vel.z * p->vel.z) >= D_800B8980 * 0.4) {
                if (p->unk_64 == 0 && (m == 0 || d > 90.0)) {
                    p->state = 2;
                    p->flags &= ~8;
                    p->unk_50 = 7;
                    m = 12;
                    func_80017C0C(obj, 4, obj->trans.x + func_800AEAC0(obj->rot.y) * 0.8 * 100.0, obj->trans.y,
                                  obj->trans.z + func_800AEFD0(obj->rot.y) * 0.8 * 100.0, 0.0f, obj->rot.y + 180.0f);
                }
            }
            if (m == 3) {
                if (p->unk_60 < 60) {
                    func_80017C0C(obj, 3, obj->trans.x - func_800AEAC0(obj->rot.y) * 0.2 * 100.0, obj->trans.y,
                                  obj->trans.z - func_800AEFD0(obj->rot.y) * 0.2 * 100.0, 0.0f, obj->rot.y);
                }
                p->unk_60++;
            } else {
                p->unk_60 = 0;
            }
        } else {
            m = p->unk_5E;
            if (--p->unk_50 == 0) {
                p->state = 0;
                p->unk_2C = p->unk_7C = obj->rot.y;
            } else if (p->state == 2) {
                if (p->unk_50 == 3 && d > 90.0) {
                    p->state = 3;
                    m = 13;
                    p->unk_50 = 8;
                }
            } else {
                obj->rot.y += 22.5;
                if (obj->rot.y >= 360.0f) {
                    obj->rot.y -= 360.0f;
                }
            }
        }
        if (D_801024F0_CoinBlockBash.state == 2) {
            p->state = 15;
            p->unk_4E = 0;
            p->unk_50 = 0;
            if (p->unk_64 != 0) {
                func_800FC054_CoinBlockBash(obj);
            }
            m = 0;
        }
        func_800F77BC_CoinBlockBash(obj, (u8)m);
        break;
    case 7:
        if (p->unk_46 != 0) {
            p->unk_46--;
        }
        if (p->flags & 4) {
            func_80017C0C(obj, 7, obj->trans.x, obj->trans.y, obj->trans.z, 0.0f, 0.0f);
            func_80017C0C(obj, 8, obj->trans.x, obj->trans.y, obj->trans.z, 0.0f, 0.0f);
            func_80060468(0x14F, chr);
            func_80060F04(id, 10, 0, 10);
            ex.y = 17.818182f;
            p->vel.y = 0.0f;
            p->flags &= ~4;
            p->unk_50++;
            p->state = 0;
            p->unk_42 = 24;
            func_800F77BC_CoinBlockBash(obj, 0x10);
        }
        break;
    case 8:
        if (p->unk_50 == 0) {
            p->flags |= 0x10;
            p->unk_46 = 0;
            p->unk_42 = p->unk_42 >= 31;
            p->unk_50++;
            p->unk_4E = 0;
            p->vel.x = p->vel.y = p->vel.z = 0.0f;
            func_800F77BC_CoinBlockBash(obj, 0);
            func_80060540(0x146, id);
            func_80060F04(id, 2, 2, 20);
            if (p->unk_64 != 0) {
                func_800FC054_CoinBlockBash(obj);
            }
        }
        p->unk_44 = 30;
        if (func_800FD8CC_CoinBlockBash(obj, p, p->unk_42) != 0) {
            p->flags &= ~0x10;
            p->state = 0;
            p->unk_42 = 0;
        }
        break;
    case 9:
        p->flags |= 0x10;
        p->unk_44 = 74;
        p->unk_42 = 20;
        p->unk_46 = 0;
        ex.x = -(-func_800AEFD0(p->unk_2C + 90.0) * 0.5 * 100.0);
        ex.z = -(func_800AEAC0(p->unk_2C + 90.0) * 0.5 * 100.0);
        func_800F77BC_CoinBlockBash(obj, 8);
        func_80060540(0x145, id);
        func_80060F04(id, 2, 2, 20);
        p->flags &= ~8;
        p->state = 0;
        if (p->unk_64 != 0) {
            func_800FC054_CoinBlockBash(obj);
        }
        p->unk_5A = 16;
        p->unk_5C = 24;
        break;
    case 10:
        if (p->unk_50 == 0) {
            p->flags |= 0x30;
            p->unk_44 = 90;
            p->unk_42 = 60;
            func_800F77BC_CoinBlockBash(obj, 8);
            func_80060618(0x45F, id);
            p->flags &= ~8;
            p->unk_50++;
            p->vel.x = ex.x = -(-func_800AEFD0(p->unk_2C + 90.0) * 0.5 * 100.0);
            p->vel.z = ex.z = -(func_800AEAC0(p->unk_2C + 90.0) * 0.5 * 100.0);
            if (p->unk_64 != 0) {
                func_800FC054_CoinBlockBash(obj);
            }
            p->unk_4E = 0;
            p->unk_46 = 0;
            func_80060F04(id, 30, 0, 30);
        }
        obj->rot.y -= 60.0;
        if (obj->rot.y < 0.0) {
            obj->rot.y += 360.0;
        }
        if (!(p->unk_4E & 1)) {
            off.x = -90.0f;
            off.y = off.z = 0.0f;
            hit = 152 - p->unk_4E * 8;
            if (hit < 64) {
                hit = 64;
            }
            func_800F81E0_CoinBlockBash(obj, 1, &pos, &off, hit);
        }
        if (!(p->flags & 0x20)) {
            off.x = off.y = off.z = 0.0f;
            func_800F81E0_CoinBlockBash(obj, 6, &pos, &off, 0);
            func_800F77BC_CoinBlockBash(obj, 9);
            p->state = 0;
            p->unk_42 = 60;
            p->unk_44 = 144;
            p->unk_5A = 16;
            p->unk_5C = 24;
        }
        break;
    case 15:
        if (p->unk_50 == 0) {
            p->flags |= 8;
            p->unk_2C = 29.0f;
            p->vel.x = p->vel.y = p->vel.z = 0.0f;
            if (D_801024F0_CoinBlockBash.state == 3 && D_801024F8_CoinBlockBash == 0) {
                if (p->unk_62 != 0) {
                    func_800F77BC_CoinBlockBash(obj, 10);
                } else {
                    func_800F77BC_CoinBlockBash(obj, 11);
                }
                p->unk_50++;
                p->unk_4E = 0;
            }
        } else if (p->unk_4E >= 30) {
            func_800F78DC_CoinBlockBash(obj, 10, 11);
        }
        break;
    case 17:
        break;
    }
    if (p->flags & 8) {
        spd = p->unk_2C - obj->rot.y;
        if (spd >= 0.0f) {
            if (spd > 180.0) {
                spd -= 360.0;
            }
        } else if (spd < -180.0) {
            spd += 360.0;
        }
        spd = obj->rot.y + spd * 0.33;
        if (spd >= 360.0) {
            spd -= 360.0;
        } else if (spd < 0.0) {
            spd += 360.0;
        }
        obj->rot.y = spd;
    }
    if (p->unk_46 == 0) {
        ex.y += p->unk_38;
    }
    off.x = p->vel.x + ex.x;
    off.y = p->vel.y + ex.y;
    off.z = p->vel.z + ex.z;
    c = func_800FE294_CoinBlockBash(&pos, &off, &pos, &off, 1);
    hit = c;
    if (c & 1) {
        p->flags |= 4;
    }
    off.x = pos.x - obj->trans.x;
    off.y = pos.y - obj->trans.y;
    off.z = pos.z - obj->trans.z;
    c = func_800F9CF0_CoinBlockBash(p, &pos, &off, &pos);
    if (p->state != 10) {
        p->vel.x = pos.x - obj->trans.x;
        p->vel.y = pos.y - obj->trans.y;
        p->vel.z = pos.z - obj->trans.z;
    } else {
        if (hit & 2) {
            p->vel.x = -p->vel.x;
        }
        p->vel.y = pos.y - obj->trans.y;
        if (hit & 4) {
            p->vel.z = -p->vel.z;
        }
        if ((p->flags & 0x20) && p->unk_4E >= 9 && (hit & 6)) {
            p->flags &= ~0x20;
            p->vel.x = p->vel.z = 0.0f;
        }
    }
    if (c > 0) {
        p->vel.y = 0.0f;
    }
    if (!(p->flags & 0x20)) {
        if (off.x == 0.0) {
            off.x = pos.x - obj->trans.x;
        }
        if (off.z == 0.0) {
            off.z = pos.z - obj->trans.z;
        }
        if ((s16)func_800F7148_CoinBlockBash(obj->work[0], &pos, off.x, off.y, off.z) < 0) {
            p->vel.y = 50.909092f;
            func_80060F04(obj->work[0], 2, 3, 10);
        }
    }
    off.x = off.y = off.z = 0.0f;
    func_800FE294_CoinBlockBash(&pos, &off, &pos, &off, 1);
    p->unk_14.x = ex.x;
    p->unk_14.y = ex.y;
    p->unk_14.z = ex.z;
    obj->trans.x = pos.x;
    obj->trans.y = pos.y;
    obj->trans.z = pos.z;
    pos.y = func_800FE284_CoinBlockBash(&pos);
    func_80025798(obj->model[1], pos.x, pos.y, pos.z);
    spd = 1.1 - (obj->trans.y - pos.y) / 1000.0;
    func_80025830(obj->model[1], spd, 1.0f, spd);
    if (p->unk_44 != 0) {
        p->unk_44--;
    }
    func_80017DB0(obj);
    func_80017BB0(obj);
    p->unk_84 = p->unk_86 = p->unk_88 = 0;
    if (++p->unk_4E >= 0x7800) {
        p->unk_4E -= 0x800;
    }
    if (D_8010253C_CoinBlockBash == obj->work[0] && p->unk_64 != 0 && p->unk_66 >= 0 && p->unk_68 >= 0) {
        func_800F96A0_CoinBlockBash(obj, p->mtx[p->unk_66][p->unk_68]);
    }
}
// NON_MATCHING: scheduling of the character-scale load and the t - a subtractions (masked 10);
// retail addresses GwPlayer[i].character as sym+reg (lui at); tried &GwPlayer[i]->, (GwPlayer + i)-> (M1c)
#ifdef NON_MATCHING
s32 func_800FD8CC_CoinBlockBash(omObjData* obj, CBBPlayer* p, s16 big) {
    f32 scl[6] = { 1.0f, 1.0f, 1.0f, 0.8f, 0.9f, 0.7f };
    s32 done;
    u16 t;
    u16 a;
    u16 end;
    f32 lo;
    f32 base;
    f32 k;
    f32 f;

    done = 0;
    t = p->unk_4E * 2;
    if (big == 0) {
        a = 60;
        lo = 0.6f;
        base = scl[GwPlayer[obj->work[0]].character];
        k = 1.4f;
        end = 106;
    } else {
        a = 120;
        end = 166;
        lo = 0.1f;
        base = scl[GwPlayer[obj->work[0]].character];
        k = 1.6f;
    }
    base *= k;
    if (t < end) {
        if (t <= a) {
            obj->scale.x = obj->scale.z = base;
            obj->scale.y = lo;
        } else if (t <= a + 10) {
            f = t - a;
            obj->scale.y = f * 0.05f + 0.2;
            obj->scale.x = obj->scale.z = 1.8 - f * 0.08f;
        } else if (t <= a + 20) {
            f = (f32)(t - 10 - a) * 0.05f;
            obj->scale.y = 0.9 - f;
            obj->scale.x = obj->scale.z = f + 1.0;
        } else if (t <= a + 30) {
            f = t - 20 - a;
            obj->scale.y = f * 0.05f + 0.7;
            obj->scale.x = obj->scale.z = 1.4 - f * 0.04f;
        } else if (t <= a + 38) {
            f = t - 30 - a;
            obj->scale.y = 1.3 - f * 0.1f;
            obj->scale.x = obj->scale.z = f * 0.02f + 1.0;
        } else {
            f = t - 38 - a;
            obj->scale.y = f * 0.1f + 0.3;
            obj->scale.x = obj->scale.z = 1.1 - f * 0.01f;
        }
    } else {
        obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
        done = 1;
    }
    return done;
}
#else
const f32 D_80102280_CoinBlockBash[6] __attribute__((section(".rodata"))) = { 1.0f, 1.0f, 1.0f, 0.8f, 0.9f, 0.7f };
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800FD8CC_CoinBlockBash);
#endif
void func_800FDC5C_CoinBlockBash(void) {
    D_800F2AF8[D_800ED440++] = omAddObj(1, 2, 0, -1, func_800FDCF8_CoinBlockBash);
}
void func_800FDCB4_CoinBlockBash(omObjData* obj) {
    if (D_801024F0_CoinBlockBash.state == 0 && D_801024F0_CoinBlockBash.timer == 0x42) {
        func_800258EC(obj->model[1], 4, 0);
    }
}
void func_800FDCF8_CoinBlockBash(omObjData* obj) {
    obj->func_ptr = func_800FDCB4_CoinBlockBash;
    obj->model[0] = func_800174C0(0x270000, 0x99);
    obj->model[1] = func_800174C0(0x270003, 0xBD);
}
// NON_MATCHING: retail steps the output pointer by 4 before the y store (as ovl_33 func_800FBA44)
// decomp-permuter
void func_800FDD50_CoinBlockBash(Matrix4f m, f32 x, f32 y, f32 z, Vec *out)
{
  f32 *new_var;
  f32 *o = (f32 *) out;
 do { } while (0);
  *(o++) = (((x * m[0][0]) + (y * m[1][0])) + (z * m[2][0])) + m[3][0];
  *(o++) = (((x * m[0][1]) + (y * m[1][1])) + (z * m[2][1])) + m[3][1];
  new_var = m[0];
  *o = (((x * new_var[2]) + (y * m[1][2])) + (z * m[2][2])) + m[3][2];
}
void func_800FDDEC_CoinBlockBash(Vec* v) {
    f32 inv = v->x * v->x + v->y * v->y + v->z * v->z;

    inv = sqrtf(inv);
    if (inv != 0.0f) {
        inv = 1.0 / inv;
        v->x = inv * v->x;
        v->y = inv * v->y;
        v->z = inv * v->z;
    }
}
f32 func_800FDEA0_CoinBlockBash(f32 x, f32 y) {
    f32 a = func_800B0CD8(y, x);

    if (a < 0.0) {
        a += 360.0;
    } else if (a >= 360.0) {
        a -= 360.0;
    }
    return a;
}
void func_800FDF20_CoinBlockBash(Matrix4f m, Vec* angles) {
    f32 s;
    f32 c;
    f64 t;

    angles->x = func_800FDEA0_CoinBlockBash(m[2][2], m[1][2]);
    angles->z = func_800FDEA0_CoinBlockBash(m[0][0], m[0][1]);
    s = -m[0][2];
    t = 1.0 - s * s;
    if (t < 0.0) {
        t = -t;
    }
    c = sqrtf(t);
    if (angles->x > 90.0 && angles->x < 270.0 && angles->z > 90.0 && angles->z < 270.0) {
        angles->x = func_8009B618(angles->x + 180.0, 360.0);
        angles->z = func_8009B618(angles->z + 180.0, 360.0);
        c = -c;
    }
    angles->y = func_800FDEA0_CoinBlockBash(c, s);
}
void func_800FE0AC_CoinBlockBash(Vec* a, Vec* b, Vec* c, Vec* rot) {
    Matrix4f m;
    Vec v[3];

    v[0].x = a->x;
    v[0].y = a->y;
    v[0].z = a->z;
    func_800FDDEC_CoinBlockBash(&v[0]);
    v[1].x = b->x;
    v[1].y = b->y;
    v[1].z = b->z;
    func_800FDDEC_CoinBlockBash(&v[1]);
    v[2].x = c->x;
    v[2].y = c->y;
    v[2].z = c->z;
    func_800FDDEC_CoinBlockBash(&v[2]);
    rot->z = func_800FDEA0_CoinBlockBash(v[0].x, v[0].y);
    if (rot->z == 180.0 && v[1].y >= 0.0) {
        rot->z = 0.0f;
    }
    func_8009E060(m, -rot->z, 0.0f, 0.0f, 1.0f);
    func_800FDD50_CoinBlockBash(m, v[0].x, v[0].y, v[0].z, &v[0]);
    func_800FDD50_CoinBlockBash(m, v[1].x, v[1].y, v[1].z, &v[1]);
    func_800FDD50_CoinBlockBash(m, v[2].x, v[2].y, v[2].z, &v[2]);
    rot->y = func_800FDEA0_CoinBlockBash(v[0].x, -v[0].z);
    func_8009E060(m, -rot->y, 0.0f, 1.0f, 0.0f);
    func_800FDD50_CoinBlockBash(m, v[1].x, v[1].y, v[1].z, &v[1]);
    func_800FDDEC_CoinBlockBash(&v[1]);
    rot->x = func_800FDEA0_CoinBlockBash(v[1].y, v[1].z);
}
f32 func_800FE284_CoinBlockBash(Vec* pos) {
    return -5.0f;
}
s32 func_800FE294_CoinBlockBash(Vec* pos, Vec* vel, Vec* out, Vec* n, s32 unused) {
    s32 r;
    f32 h;

    out->x = pos->x + vel->x;
    out->y = pos->y + vel->y;
    out->z = pos->z + vel->z;
    r = 0;
    if (vel->y <= 0.0) {
        h = func_800FE284_CoinBlockBash(out);
        if (out->y <= h) {
            out->y = h;
            r = 1;
        }
    }
    n->x = 0.0f;
    if (out->x <= -480.0) {
        out->x = -480.0f;
        n->x = 1.0f;
        r |= 2;
    } else if (out->x >= 430.0) {
        out->x = 430.0f;
        n->x = -1.0f;
        r |= 2;
    }
    n->z = 0.0f;
    if (out->z <= -470.0) {
        out->z = -470.0f;
        n->z = 1.0f;
        r |= 4;
    } else if (out->z >= 440.00000000000006) {
        out->z = 440.0f;
        n->z = -1.0f;
        r |= 4;
    }
    return r;
}
// NON_MATCHING: register allocation and instruction order (as ovl_33 func_800FB868)
#ifdef NON_MATCHING
void func_800FE470_CoinBlockBash(s16 cam, Vec* pos, Vec* out) {
    Matrix4f m;
    Vec v;
    unk_Struct00* c;
    s16* vscale;
    f32 d;

    c = &D_800C3110[cam];
    HuGuLookAtF(m, c->pos.x, c->pos.y, c->pos.z, c->unkC.x, c->unkC.y, c->unkC.z, c->unk18.x, c->unk18.y,
                c->unk18.z);
    func_800FDD50_CoinBlockBash(m, pos->x, pos->y, pos->z, &v);
    d = func_800AEAC0(c->unk_40 * 0.5) / func_800AEFD0(c->unk_40 * 0.5) * v.z;
    if (d < 0.0f) {
        d = -d;
    }
    /* the screen's viewport scale: an s16 pair every 0x10 bytes from unk58 (no pointers before it) */
    vscale = (s16*)((u8*)c + D_800F3FA8 * 0x10 + 0x58);
    out->x = vscale[0] / 4.0 * v.x / d * 0.75;
    out->y = vscale[1] / 4.0 * -v.y / d;
    out->z = 400.0 / d;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_15_CoinBlockBash/152BE0", func_800FE470_CoinBlockBash);
#endif
