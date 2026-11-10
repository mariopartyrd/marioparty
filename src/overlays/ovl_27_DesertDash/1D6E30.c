#include "common.h"
#include "DesertDash.h"

/* .data (0x800FC030..0x800FC050) */
u32 D_800FC030_DesertDash = 0x19971204;
u32 D_800FC034_DesertDash = 0;
u32 D_800FC038_DesertDash = 0;
s16 D_800FC03C_DesertDash = 60;
s16 D_800FC03E_DesertDash = 20;
s16 D_800FC040_DesertDash = 0;
s16 D_800FC042_DesertDash = 0;
f64 D_800FC048_DesertDash = 0.0;

void func_800F9A80_DesertDash(omObjData* obj) {
    obj->func_ptr = func_800F9B2C_DesertDash;
    func_800234B8(0, 0xA0, 0x50, 0x50);
    func_800234B8(1, 0xFF, 0x80, 0x80);
    func_80023504(1, -96.0f, 100.0f, 26.0f);
    func_80028510(0x3B4, 0x40C, 0xFF, 0x55, 0x55);
    func_800FA210_DesertDash(rand8());
    func_800FA29C_DesertDash();
    D_800FC650_DesertDash = 1;
    D_800FC652_DesertDash = 1;
    D_800FC654_DesertDash = 0;
}

/* Course driver: after 80 frames picks five random frames that clear the obstacles' "unk2". */
void func_800F9B2C_DesertDash(omObjData* obj) {
    u16 i;

    func_800FAFD4_DesertDash();
    if (D_800FC034_DesertDash < 80) {
        if (++D_800FC034_DesertDash == 80) {
            D_800FC650_DesertDash = 1;
            D_800FC652_DesertDash = 0;
            for (i = 0; i < 5; i++) {
                D_800FC4D0_DesertDash[i] = func_800FA1A0_DesertDash(120);
            }
        }
    } else if (D_800FC038_DesertDash < 120) {
        for (i = 0; i < 5; i++) {
            if (D_800FC038_DesertDash == D_800FC4D0_DesertDash[i]) {
                if (D_800FC670_DesertDash[i].unk2 != 0 && D_800FC670_DesertDash[i].unk0 != 0) {
                    D_800FC670_DesertDash[i].unk2 = 0;
                }
            }
        }
        D_800FC038_DesertDash++;
    }
}

void func_800F9C68_DesertDash(void) {
    HuMemDirectFree(D_800FC608_DesertDash[0]);
    HuMemDirectFree(D_800FC608_DesertDash[1]);
}

// register allocation (scale/off temporaries; masked residue is FPR choice)
#ifdef NON_MATCHING
/* The split-screen intro and the two banners: x is the split position (320 = full). */
void func_800F9C9C_DesertDash(s16 x) {
    f32 off;
    f32 scale;
    f32 f;
    u16 i;
    unk65770Obj* spr;
    omObjData* o;

    off = 0.0f;
    if (D_800FC654_DesertDash == 0) {
        return;
    }
    scale = x / 160.0f;
    if (D_800FC03C_DesertDash > 0) {
        if (D_800FC03C_DesertDash == 60) {
            o = D_800FC4E0_DesertDash[1];
            for (i = 0; i < 4; i++) {
                func_800258EC(o->model[i], 4, 4);
            }
        } else if (D_800FC03C_DesertDash == 1) {
            o = D_800FC4E0_DesertDash[1];
            for (i = 0; i < 4; i++) {
                func_800258EC(o->model[i], 4, 0);
            }
        }
        scale = D_800FC03C_DesertDash / 60.0f + 2.0;
        if (func_80072718() == 0) {
            D_800FC03C_DesertDash--;
        }
    } else if (D_800FC03E_DesertDash > 0) {
        off = (1.0 - D_800FC03E_DesertDash / 20.0f) * 200.0;
        D_800FC03E_DesertDash--;
    }
    if (D_800FC03C_DesertDash > 0) {
        func_800673B0(D_800FC5FE_DesertDash[0], 0, 360.0f);
    } else {
        func_800673B0(D_800FC5FE_DesertDash[0], 0, 0.0f);
    }
    f = x / 160.0f;
    func_8006761C(D_800FC5FE_DesertDash[0], 0, -D_800FC03C_DesertDash * 4, -D_800FC03C_DesertDash * 2,
                  (s16)(x + D_800FC03C_DesertDash * 4), (s16)(f * f * 66.0 + D_800FC03C_DesertDash * 4));
    func_8006761C(D_800FC5FE_DesertDash[1], 0, x, 0, 321, (s16)(f * f * 66.0));
    if (x >= 318) {
        func_800674BC(D_800FC5FE_DesertDash[1], 0, 0x8000);
    } else {
        func_80067480(D_800FC5FE_DesertDash[1], 0, 0x8000);
    }
    func_80066DF4(D_800FC602_DesertDash[1], 0, 0, -off, 600.0f, (f32)D_800FC658_DesertDash[0] + -7000.0);
    spr = func_800675F4(D_800FC602_DesertDash[1], 0);
    D_800FC620_DesertDash[0].unkC = spr->unk40;
    D_800FC620_DesertDash[0].unk0 = spr->unk42;
    if (func_80072718() != 0) {
        D_800FC620_DesertDash[0].unkC = 160.0f;
        D_800FC620_DesertDash[0].unk0 = 200.0f;
    }
    func_80066DF4(D_800FC602_DesertDash[1], 0, 1, 0.0f, 600.0f, (f32)D_800FC658_DesertDash[1] + -7000.0);
    spr = func_800675F4(D_800FC602_DesertDash[1], 0);
    D_800FC620_DesertDash[1].unkC = spr->unk40;
    D_800FC620_DesertDash[1].unk0 = spr->unk42;
    D_800FC620_DesertDash[0].unk14 = scale;
    D_800FC620_DesertDash[0].unk10 = scale;
    D_800FC620_DesertDash[1].unk14 = scale;
    D_800FC620_DesertDash[1].unk10 = scale;
    func_80066DC4(D_800FC602_DesertDash[0], 0, x, 120);
    if (x == 320 && D_800FC040_DesertDash == 0) {
        func_800674BC(D_800FC602_DesertDash[0], 0, 0x9000);
        D_800FC040_DesertDash = 1;
        return;
    }
    if (x < 320 && D_800FC042_DesertDash == 0) {
        func_80067480(D_800FC602_DesertDash[0], 0, 0x8000);
        D_800FC042_DesertDash = 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_DesertDash/1D6E30", func_800F9C9C_DesertDash);
#endif

/* The overlay's own random generator (D_800FC030). */
u16 func_800FA1A0_DesertDash(u16 range) {
    D_800FC030_DesertDash = (D_800FC030_DesertDash * 0x19971204 + 0x19760831) >> 16;
    if (range == 0) {
        return (u16)D_800FC030_DesertDash;
    }
    return D_800FC030_DesertDash % range;
}

void func_800FA210_DesertDash(u8 seed) {
    D_800FC030_DesertDash = seed + seed * D_800FC030_DesertDash;
}

void func_800FA234_DesertDash(DDObstacle* o) {
    s32 pad[4]; /* retail's 16-byte frame */

    o->unk4 = 3;
    o->unkC = 30.0f;
}

u16 func_800FA258_DesertDash(s32 file) {
    void* data;
    u16 ret;

    data = DataRead(file);
    ret = func_800678A4(data);
    DataClose(data);
    return ret;
}

// register allocation only (the two table bases swap s0/s1)
#ifdef NON_MATCHING
void func_800FA29C_DesertDash(void) {
    unk65770AnimC* frame;

    D_800F2AF8[0] = D_800FC4E0_DesertDash[0] = omAddObj(2, 5, 0, -1, func_800FA460_DesertDash);
    omSetStatBit(D_800FC4E0_DesertDash[0], 0xA0);
    D_800FC4E0_DesertDash[0]->work[0] = 1;
    D_800FC4E0_DesertDash[0]->work[1] = 0;
    D_800F2AF8[1] = D_800FC4E0_DesertDash[1] = omAddObj(3, 5, 0, -1, func_800FA460_DesertDash);
    omSetStatBit(D_800FC4E0_DesertDash[1], 0xA0);
    D_800FC4E0_DesertDash[1]->work[0] = 2;
    D_800FC4E0_DesertDash[1]->work[1] = 1;
    D_800F2AF8[2] = D_800FC4E0_DesertDash[2] = omAddObj(4, 0x16, 0, -1, func_800FA9E0_DesertDash);
    omSetStatBit(D_800FC4E0_DesertDash[2], 0xA0);
    D_800FC5F8_DesertDash[0] = func_800FA258_DesertDash(0x3B000B);
    frame = D_800EC700[D_800FC5F8_DesertDash[0]]->unk0;
    frame->unk8 = 0;
    frame->unkA = 0;
    D_800FC5F8_DesertDash[1] = func_800FA258_DesertDash(0x3B000C);
    D_800FC5F8_DesertDash[2] = func_800FA258_DesertDash(0x3B000E);
    D_800FC658_DesertDash[0] = D_800FC658_DesertDash[1] = 0.0;
    D_800FC602_DesertDash[1] = func_80064EF4(1, 0);
    func_80067208(D_800FC602_DesertDash[1], 0, D_800FC5F8_DesertDash[1], 0);
    func_800674BC(D_800FC602_DesertDash[1], 0, 0x8000);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_DesertDash/1D6E30", func_800FA29C_DesertDash);
#endif

// one andi scheduled before its copy (register only)
#ifdef NON_MATCHING
/* A team's track object (work[0] = camera group, work[1] = team). */
void func_800FA460_DesertDash(omObjData* obj) {
    u16 i;
    s32 w;
    s32 t;

    obj->func_ptr = func_800FA724_DesertDash;
    obj->trans.x = obj->trans.y = 0.0f;
    obj->model[0] = LoadFormFile(0x3B0000, 0x99);
    for (i = 1; i < 4; i++) {
        obj->model[i] = func_80023FC8(obj->model[0]);
    }
    obj->model[4] = func_80023FC8(obj->model[0]);
    func_800258EC(obj->model[4], 4, 4);
    func_80026040(obj->model[0]);
    for (i = 0; i < 5; i++) {
        func_80025F10(obj->model[i], obj->work[0]);
    }
    w = obj->work[1];
    t = (u16)w;
    D_800FC5FE_DesertDash[t] = func_80064EF4(1, 0);
    func_80067208(D_800FC5FE_DesertDash[t], 0, D_800FC5F8_DesertDash[0], 0);
    func_800674BC(D_800FC5FE_DesertDash[t], 0, 0x1403C);
    func_8006761C(D_800FC5FE_DesertDash[t], 0, 160, 0, 320, 240);
    func_80067384(D_800FC5FE_DesertDash[t], 0, w - 16);
    /* 0x1000 bytes on the N64: 0x200 commands (a host Gfx is 16 bytes) */
    D_800FC608_DesertDash[t] = HuMemDirectMalloc(0x200 * sizeof(Gfx));
    D_800FC614_DesertDash[t] = func_80024198(0xA0, D_800FC608_DesertDash[t], 0);
    func_80025F10(D_800FC614_DesertDash[t], obj->work[0]);
    func_800FB750_DesertDash(&D_800FC608_DesertDash[t], D_800FC5F8_DesertDash[2], 0, 160, 480, 0, 1, 1.0f, 0, 1,
                             1.0f, 1.0f);
    D_800FC620_DesertDash[t].unk0 = 480.0f;
    D_800FC620_DesertDash[t].unk4 = 0.0f;
    D_800FC620_DesertDash[t].unk8 = 160.0f;
    D_800FC620_DesertDash[t].unkC = obj->work[1] * 160 + 48;
    D_800FC620_DesertDash[t].unk10 = 1.0f;
    D_800FC620_DesertDash[t].unk14 = 1.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_DesertDash/1D6E30", func_800FA460_DesertDash);
#endif

// index copy and a model-pointer load scheduled differently
#ifdef NON_MATCHING
void func_800FA724_DesertDash(omObjData* obj) {
    s32 t;
    s16 i;

    t = obj->work[1];
    obj->trans.z = D_800FC658_DesertDash[t];
    if (func_8005FD5C() + D_800F64F8 == 0) {
        D_800FC048_DesertDash += 0.25;
    }
    func_800FB750_DesertDash(&D_800FC608_DesertDash[t], D_800FC5F8_DesertDash[2], 0, D_800FC620_DesertDash[t].unkC,
                             D_800FC620_DesertDash[t].unk0, D_800FC048_DesertDash, 1, 0.75f, 40, 1,
                             D_800FC620_DesertDash[t].unk10, D_800FC620_DesertDash[t].unk14);
    if (D_800FC620_DesertDash[t].unk8 != 0.0f) {
        D_800FC620_DesertDash[t].unk0 -= D_800FC620_DesertDash[t].unk4;
        D_800FC620_DesertDash[t].unk8 -= 1.0;
    }
    for (i = 1; i < 4; i++) {
        func_80025798(obj->model[i], obj->trans.x, obj->trans.y, obj->trans.z - i * 2100);
    }
    if (D_800FC650_DesertDash == 0 && D_800FC652_DesertDash == 0) {
        func_800258EC(obj->model[4], 4, 0);
        func_80025798(obj->model[4], obj->trans.x, obj->trans.y, obj->trans.z + 2100.0f);
    }
    func_80027C1C(obj->model[0], 0.0f, obj->trans.z / 16.0, 0x40, 0x40);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_DesertDash/1D6E30", func_800FA724_DesertDash);
#endif

// register allocation and the i*800 grouping (not finished)
#ifdef NON_MATCHING
/* The desert scenery: 16 random cacti/rocks (D_800FC4F8) and the obstacles. */
void func_800FA9E0_DesertDash(omObjData* obj) {
    DDScenery* e;
    u16 i;
    s32 k;

    obj->func_ptr = func_800FACD0_DesertDash;
    for (e = D_800FC4F8_DesertDash, i = 0; i < 16; i++, e++) {
        e->x = func_800FA1A0_DesertDash(400) + 600;
        e->y = 0.0f;
        k = i * 800;
        e->z = -(k - 200 + func_800FA1A0_DesertDash(400));
        if (k > 6000 && (i & 3)) {
            e->x *= 1.5;
        }
        if (i & 1) {
            e->x = -e->x;
        }
        e->unk2 = i % 3;
    }
    obj->model[0] = LoadFormFile(0x3B0001, 0x99);
    obj->model[1] = LoadFormFile(0x3B0002, 0x99);
    obj->model[2] = LoadFormFile(0x3B0003, 0x99);
    obj->model[3] = LoadFormFile(0x3B0004, 0x99);
    obj->model[4] = LoadFormFile(0x3B0005, 0x99);
    obj->model[5] = func_80023FC8(obj->model[4]);
    for (e = D_800FC4F8_DesertDash, i = 0; i < 16; i++, e++) {
        obj->model[6 + i] = func_80023FC8(obj->model[e->unk2]);
    }
    for (i = 0; i < 3; i++) {
        func_800258EC(obj->model[i], 4, 4);
    }
    func_800FAE60_DesertDash();
    func_800FB3F8_DesertDash((u16)D_800FC004_DesertDash);
    D_800FC602_DesertDash[0] = func_80064EF4(1, 0);
    func_80067208(D_800FC602_DesertDash[0], 0, D_800FC5F8_DesertDash[1], 0);
    func_800674BC(D_800FC602_DesertDash[0], 0, 0x1000);
    func_80067354(D_800FC602_DesertDash[0], 0, 1.0f, 1.0f);
    func_80066DC4(D_800FC602_DesertDash[0], 0, 160, 120);
    func_80067384(D_800FC602_DesertDash[0], 0, 0x7FF0);
    D_800FC654_DesertDash = 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_DesertDash/1D6E30", func_800FA9E0_DesertDash);
#endif

void func_800FACD0_DesertDash(omObjData* obj) {
    DDScenery* e;
    u16 i;

    func_80025798(obj->model[3], 0.0f, 0.0f, -6000.0f);
    func_80025798(obj->model[4], 0.0f, 0.0f, 0.0f);
    func_80025798(obj->model[5], 0.0f, 0.0f, -6000.0f);
    for (e = D_800FC4F8_DesertDash, i = 0; i < 16; i++) {
        func_80025798(obj->model[6 + i], e->x, e->y, e->z);
        e++;
    }
}

/* Records team t's z; 1 when it crossed the goal line. */
s16 func_800FAD98_DesertDash(u16 t, f32 z) {
    if (t >= 2) {
        return 0;
    }
    D_800FC658_DesertDash[t] = z;
    func_800FB4F8_DesertDash(t, z);
    if (z <= -6000.0f) {
        D_800FC650_DesertDash = 0;
        return 1;
    }
    return 0;
}

void func_800FAE1C_DesertDash(u16 t, f32 frames) {
    D_800FC620_DesertDash[t].unk4 = 64.0 / frames;
    D_800FC620_DesertDash[t].unk8 = frames;
}

void func_800FAE60_DesertDash(void) {
    DDObstacle* o;
    u16 i;

    for (o = D_800FC670_DesertDash, i = 0; i < 5; i++, o++) {
        o->unk0 = 0;
        o->unk2 = 1;
        if (i == 0) {
            o->unk6 = LoadFormFile(0x3B0006, 0x99);
            o->unk8 = LoadFormFile(0x3B000A, 0x99);
        } else {
            o->unk6 = func_80023FC8(D_800FC670_DesertDash[0].unk6);
            o->unk8 = func_80023FC8(D_800FC670_DesertDash[0].unk8);
        }
        o->unkA = LoadFormFile(0x1D, 0x99);
        func_800FA234_DesertDash(o);
        o->unk10 = 0.0f;
        o->unk14 = -((i + 1) * 1000);
        func_80025F10(o->unk6, 3);
        func_80025F10(o->unk8, 3);
        D_800F2B7C[o->unkA].unk_4C = 1.0f;
        func_800258EC(o->unk6, 4, 4);
        func_800258EC(o->unk8, 4, 4);
        func_800258EC(o->unkA, 4, 4);
    }
}

// loop-head branch layout (bnez/j where retail has beqzl) and FPR constants
#ifdef NON_MATCHING
/* Moves the obstacles up and down; plays the slam sound for the teams that see one land. */
void func_800FAFD4_DesertDash(void) {
    DDObstacle* o;
    u16 i;
    u16 j;
    f32 v;
    s32 vol;
    s16 h;
    f32 s;
    s32 bit;

    o = D_800FC670_DesertDash;
    i = 0;
    do {
        if (o->unk0 == 0) {
            i++;
        } else {
        switch (o->unk4) {
            case 2:
                o->unk10 = 0.0f;
                if (o->unkC == 0.0f) {
                    o->unkC = 180.0f;
                    o->unk4 = 0;
                }
                break;
            case 0:
                o->unk10 = 440.0f - o->unkC / 180.0f * 440.0f;
                if (o->unkC == 0.0f) {
                    o->unkC = 30.0f;
                    o->unk4 = 3;
                }
                break;
            case 3:
                o->unk10 = 440.0f;
                if (o->unkC == 0.0f) {
                    o->unkC = 5.0f;
                    o->unk4 = 1;
                }
                if (o->unk2 == 0 && D_800FC650_DesertDash != 0) {
                    o->unkC -= 1.0f;
                }
                goto place;
            case 1:
                o->unk10 = o->unkC / 5.0f * 440.0f;
                if (o->unkC == 0.0f) {
                    o->unk10 = 0.0f;
                    o->unkC = 30.0f;
                    o->unk4 = 2;
                    for (j = 0; j < 2; j++) {
                        bit = 1 << j;
                        if (bit & (u16)D_800F2B7C[o->unk6].unk_02) {
                            v = 1.0 - (f32)fabs(D_800FC658_DesertDash[j] + 200.0 - o->unk14) / 3000.0;
                            if (v > 1.0) {
                                v = 1.0f;
                            } else if (v < 0.0) {
                                v = 0.0f;
                            }
                            vol = v * 57.0 + 70.0;
                            if (j == 0) {
                                h = func_80060540(0x2E9, 3);
                            } else {
                                h = func_80060540(0x2EA, 4);
                            }
                            if (h != -1) {
                                func_8006035C(h, vol);
                            }
                        }
                    }
                    func_800FB610_DesertDash(o->unkA);
                }
                break;
            default:
                goto place;
        }
        if (o->unk2 == 0) {
            o->unkC -= 1.0f;
        }
    place:
        func_80025798(o->unk6, 0.0f, o->unk10, o->unk14);
        func_80025830(o->unk6, 2.0f, 2.0f, 1.0f);
        func_80025798(o->unk8, 0.0f, 2.0f, o->unk14);
        s = 1.0 - o->unk10 / 440.0f / 3.0;
        i++;
        func_80025830(o->unk8, 2.0 * s, 1.0f, s);
        func_80025798(o->unkA, 0.0f, 0.0f, o->unk14);
        func_80025830(o->unkA, 3.0f, 3.0f, 3.0f);
        }
        o++;
    } while (i < 5);
    func_800FB6B8_DesertDash();
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_DesertDash/1D6E30", func_800FAFD4_DesertDash);
#endif

void func_800FB3F8_DesertDash(u16 n) {
    DDObstacle* o;
    u16 i;

    o = D_800FC670_DesertDash;
    if (n >= 6) {
        n = 5;
    }
    for (i = 0; i < n; o++, i++) {
        o->unk14 = -((6000 / (n + 1)) * (i + 1));
        func_800258EC(o->unk6, 4, 0);
        func_800258EC(o->unk8, 4, 0);
        o->unk0 = 1;
    }
}

// (u16)bit hoisted out of the loop; register allocation (raw 56, masked 12);
// tried inline 1 << t, (u16)v & bit
#ifdef NON_MATCHING
/* Hides the obstacles behind team t's camera, shows those ahead (bit t of the model flags). */
void func_800FB4F8_DesertDash(u16 t, f32 z) {
    DDObstacle* o;
    u16 i;
    s16 lock;
    s32 bit;
    unk_ovl_2D_struct* m;
    s16 v;

    o = D_800FC670_DesertDash;
    i = 0;
    lock = D_800FC652_DesertDash;
    bit = 1 << t;
    for (; i < 5; i++, o++) {
        if (lock == 0 && o->unk0 != 0) {
            if (o->unk14 > z + 200.0) {
                m = &D_800F2B7C[o->unk6];
                v = m->unk_02;
                if (v & (u16)bit) {
                    m->unk_02 = bit ^ v;
                    D_800F2B7C[o->unk8].unk_02 = bit ^ (u16)D_800F2B7C[o->unk8].unk_02;
                }
            } else {
                D_800F2B7C[o->unk6].unk_02 = bit | (u16)D_800F2B7C[o->unk6].unk_02;
                D_800F2B7C[o->unk8].unk_02 = bit | (u16)D_800F2B7C[o->unk8].unk_02;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_DesertDash/1D6E30", func_800FB4F8_DesertDash);
#endif

void func_800FB610_DesertDash(s16 mdl) {
    f32 end;

    end = func_80025D18(mdl);
    if (func_80025D40(mdl) <= end) {
        if (D_800F2B7C[mdl].unk_6C->unk_B8 != NULL) {
            D_800F2B7C[mdl].unk_6C->unk_B8->unk_08 = 0.0f;
        }
        func_80025CA8(mdl, 0.0f);
    }
    func_800258EC(mdl, 4, 0);
}

void func_800FB6B8_DesertDash(void) {
    DDObstacle* o;
    u16 i;
    s16 m;
    f32 end;

    for (o = D_800FC670_DesertDash, i = 0; i < 5; i++, o++) {
        if (o->unk0 != 0) {
            m = o->unkA;
            end = func_80025D18(m);
            if (func_80025D40(m) <= end) {
                func_800258EC(m, 4, 4);
            }
        }
    }
}

/* Builds a team banner's display list into *buf: frame `frame` of sprite animation `anim` (an I4
   image) drawn at (x, y) scaled by (sx, sy), `strips` texture loads of `rows` lines each, every
   `band` lines a rectangle shifted sideways by sin(phase) * amp (phase advances by `step`). */
// logic-equivalent gbi-macro rewrite (ovl_20 func_800FA9B0's shape); retail interleaves the writes
#ifdef NON_MATCHING
void func_800FB750_DesertDash(Gfx** buf, s16 anim, s32 frame, s32 x, s32 y, s32 phase, s32 band, f32 amp, s32 step,
                              s32 strips, f32 sx, f32 sy) {
    unk65770AnimC* f;
    Gfx* gfx;
    s32 ang;
    s32 rows;
    s32 x0;
    s32 x1;
    s32 y0;
    s32 i;
    s32 j;
    s32 wave;
    f32 top;
    f32 h;

    ang = step * phase;
    gfx = *buf;
    f = &func_80067310(anim)->unk0[frame];
    rows = f->unk6 / strips;
    x0 = x - (u16)f->unk8 * sx;
    x1 = x0 + f->unk4 * sx;
    y0 = y - (u16)f->unkA * sy;
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPPipeSync(gfx++);
    gDPSetTexturePersp(gfx++, G_TP_NONE);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gSPSetOtherMode(gfx++, G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, 0x004041C8);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gSPSetOtherMode(gfx++, G_SETOTHERMODE_H, G_MDSFT_RGBDITHER, 2, 0x40);
    gDPSetCombine(gfx++, 0xFFFFFF, 0xFFFDF2F9);
    gDPSetPrimColor(gfx++, 0, 0, 0xFF, 0xFF, 0x00, 0xFF);
    for (i = 0; i < strips; i++) {
        /* an I4 image loaded as I8 of half the width (gDPLoadTextureTile_4b) */
        gDPSetTextureImage(gfx++, G_IM_FMT_I, G_IM_SIZ_8b, f->unk4 >> 1, f->unk0);
        gDPSetTile(gfx++, G_IM_FMT_I, G_IM_SIZ_8b, ((f->unk4 >> 1) + 7) >> 3, 0, G_TX_LOADTILE, 0, 0, 0, 0, 0, 0,
                   0);
        gDPLoadSync(gfx++);
        gDPLoadTile(gfx++, G_TX_LOADTILE, 0, (rows * i) << 2, (f->unk4 - 1) << 1, (rows * (i + 1) - 1) << 2);
        gDPPipeSync(gfx++);
        gDPSetTile(gfx++, G_IM_FMT_I, G_IM_SIZ_4b, ((f->unk4 >> 1) + 7) >> 3, 0, G_TX_RENDERTILE, 0, 0, 0, 0, 0, 0,
                   0);
        gDPSetTileSize(gfx++, G_TX_RENDERTILE, 0, (rows * i) << 2, (f->unk4 - 1) << 2, (rows * (i + 1) - 1) << 2);
        for (j = 0; j < rows / band; j++) {
            wave = func_800AEAC0(ang) * amp * 4.0f * sx;
            ang = (ang + step) % 360;
            top = (f32)y0 + rows * sy * i;
            h = band * sy;
            gSPScisTextureRectangle(gfx++, x0 * 4 + wave, (s16)(s32)(top + h * j) << 2, x1 * 4 + wave,
                                    (s32)(top + h * (j + 1)) * 4, G_TX_RENDERTILE, 0, (rows * i + band * j) << 5,
                                    (s32)(1.0 / sx * 1024.0), (s32)(1.0 / sy * 1024.0));
        }
    }
    gDPPipeSync(gfx++);
    gSPEndDisplayList(gfx++);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_DesertDash/1D6E30", func_800FB750_DesertDash);
#endif
