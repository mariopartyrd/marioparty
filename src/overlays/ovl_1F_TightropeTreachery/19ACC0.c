#include "common.h"
#include "TightropeTreachery.h"

/* A leaf blown across the water by the wind (D_800FE3B4_TightropeTreachery[4]). */
typedef struct TTLeaf {
    /* 0x00 */ s8 active;
    /* 0x04 */ f32 vx;
    /* 0x08 */ f32 vz;
    /* 0x0C */ f32 x;
    /* 0x10 */ f32 y;
    /* 0x14 */ f32 z;
    /* 0x18 */ s32 phase; /* bobbing angle (degrees) */
    /* 0x1C */ f32 tilt;
    /* 0x20 */ s8 dir;    /* tilt direction */
    /* 0x24 */ f32 spin;
} TTLeaf; /* size = 0x28 */

/* src/29C90.c's HitGrid (main code's collision grids, D_800F32AC). */
typedef struct TTHitGrid {
    /* 0x00 */ s32 w;
    /* 0x04 */ s32 h;
    /* 0x08 */ f32 cw;
    /* 0x0C */ f32 ch;
    /* 0x10 */ u16* polys;
    /* 0x14 */ s16* map0;
    /* 0x18 */ s16* map1;
    /* 0x1C */ s16* map2;
    /* 0x20 */ void* cells;
} TTHitGrid; /* size = 0x24 on the N64 */

extern TTHitGrid* D_800F32AC;
extern u8 D_800F64F8;

/* .data (0x800FE350..0x800FE500) */
f32 D_800FE350_TightropeTreachery = 0.0f; /* water texture scroll u */
f32 D_800FE354_TightropeTreachery = 0.0f; /* water texture scroll v */
f32 D_800FE358_TightropeTreachery = 0.0f;
s8 D_800FE35C_TightropeTreachery = 0; /* the wind sound is playing */
s8 D_800FE35D_TightropeTreachery = 0; /* the wind is over */
f32 D_800FE360_TightropeTreachery[7] = { 45.0f, 90.0f, 135.0f, 225.0f, 270.0f, 315.0f, 0.0f }; /* wind directions */
s8 D_800FE37C_TightropeTreachery = 6; /* wind direction (6: none) */
f32 D_800FE380_TightropeTreachery = 0.0f; /* wind strength */
f32 D_800FE384_TightropeTreachery = 0.0f;
f32 D_800FE388_TightropeTreachery = 0.0f;
f32 D_800FE38C_TightropeTreachery = 0.0f;
f32 D_800FE390_TightropeTreachery = 0.0f;
s8 D_800FE394_TightropeTreachery = 1; /* rope sway direction */
f32 D_800FE398_TightropeTreachery = 0.0f; /* rope sway */
f32 D_800FE39C_TightropeTreachery = 0.0f;
s8 D_800FE3A0_TightropeTreachery = 0;
s8 D_800FE3A1_TightropeTreachery = 0;
s8 D_800FE3A2_TightropeTreachery = 0x7F; /* wind sound volume */
s8 D_800FE3A3_TightropeTreachery = 0;    /* the wind blows */
s8 D_800FE3A4_TightropeTreachery = 1;    /* waiting for the next gust */
s8 D_800FE3A5_TightropeTreachery = 6;
s8 D_800FE3A6_TightropeTreachery = 6;
s32 D_800FE3A8_TightropeTreachery = 0;
s32 D_800FE3AC_TightropeTreachery = 0; /* gust length */
s32 D_800FE3B0_TightropeTreachery = 0;
TTLeaf D_800FE3B4_TightropeTreachery[4] = { 0 };
f32 D_800FE454_TightropeTreachery[2] = { -600.0f, 600.0f }; /* leaf x range */
f32 D_800FE45C_TightropeTreachery[2] = { -600.0f, 600.0f }; /* leaf z range */
f32 D_800FE464_TightropeTreachery = 0.0f;
f32 D_800FE468_TightropeTreachery = 0.0f;
u8 D_800FE46C_TightropeTreachery[8][2] = { /* the rescuer's two blended poses per state */
    { 5, 4 }, { 5, 4 }, { 0, 1 }, { 2, 3 }, { 5, 4 }, { 4, 5 }, { 4, 5 }, { 4, 5 },
};
f32 D_800FE47C_TightropeTreachery[8] = { /* per side: carry offset x, y, target x, (unused) */
    -30.0f, -10.0f, 1000.0f, -90.0f, 30.0f, -10.0f, -1000.0f, 90.0f,
};
f32 D_800FE49C_TightropeTreachery = 0.0f;
Vec3f D_800FE4A0_TightropeTreachery[4] = { /* the team's start positions */
    { -500.0f, -605.0f, 500.0f },
    { -500.0f, -605.0f, -100.0f },
    { 500.0f, -605.0f, -100.0f },
    { 500.0f, -605.0f, 500.0f },
};
TTSpot D_800FE4D0_TightropeTreachery[4] = { { 20.0f, 0 }, { 50.0f, 0 }, { 310.0f, 0 }, { 340.0f, 0 } };
s8 D_800FE4F0_TightropeTreachery[4] = { 0, 0, 0, 0 }; /* a bomb's fuse sound plays */
u16 D_800FE4F4_TightropeTreachery = 0; /* bombs created */

/* Copies the rope model's base vertices (func_800F9508_TightropeTreachery bends them). */
void func_800F9480_TightropeTreachery(s16 model) {
    unk2C0C0StructC0* m;
    unk2C0C0StructA0* src;
    s32 size;

    func_80026040(model);
    m = D_800F2B7C[model].unk_6C;
    src = m->unk_78;
    size = m->unk_6E * sizeof(unk2C0C0StructA0);
    D_800FE6AC_TightropeTreachery = func_80023684(size, 0x7918);
    func_80023A38(src, D_800FE6AC_TightropeTreachery, size);
}

/* The rope: sways, sags under the walker and bends with the wind. */
// register allocation (masked 0)
#ifdef NON_MATCHING
void func_800F9508_TightropeTreachery(s16 model) {
    TTPlayerWork* w = D_800F3FB0[0]->unk_50;
    f32 amp;
    f32 dz;
    f32 x;
    unk2C0C0StructC0* m;
    unk2C0C0StructE0* src;
    unk2C0C0StructE0* dst;
    unk2C0C0StructA0* src2;
    unk2C0C0StructA0* dst2;
    s16 i;
    s16 n;

    if (D_800FE394_TightropeTreachery == 1) {
        if (func_8005FD5C() + D_800F64F8 == 0) {
            D_800FE398_TightropeTreachery -= 0.6;
        }
        if (D_800FE398_TightropeTreachery <= -20.0f) {
            D_800FE394_TightropeTreachery = 0;
        }
    } else {
        if (func_8005FD5C() + D_800F64F8 == 0) {
            D_800FE398_TightropeTreachery += 0.6;
        }
        if (D_800FE398_TightropeTreachery >= 20.0f) {
            D_800FE394_TightropeTreachery = 1;
        }
    }
    if (w->speed > 0.0f) {
        amp = func_800AEFD0(D_800FE39C_TightropeTreachery * 18.0) * 5.0f + 35.0f;
        if (func_8005FD5C() + D_800F64F8 == 0) {
            D_800FE39C_TightropeTreachery += 1.0f;
        }
        if (D_800FE39C_TightropeTreachery >= 20.0f) {
            D_800FE39C_TightropeTreachery = 0.0f;
        }
    } else {
        D_800FE39C_TightropeTreachery = 0.0f;
        amp = 40.0f;
    }
    D_800FE388_TightropeTreachery = 0.0f;
    m = D_800F2B7C[model].unk_6C;
    src = m->unk_04;
    dst = m->unk_08[D_800F37F0];
    for (i = 0, n = m->unk_72; i < n; i++) {
        *dst = *src;
        if (D_800F3FB0[0]->trans.y >= D_800FE388_TightropeTreachery + -50.0) {
            dz = src->unk_04 + 500.0f - D_800F3FB0[0]->trans.z;
            if ((dz > -500.0f) & (dz < 500.0f)) {
                dst->unk_02 = src->unk_02 + func_800AEFD0((dz + 500.0f) * 0.36f) * amp - amp;
            } else {
                dst->unk_02 = src->unk_02;
            }
        }
        dst->unk_00 = src->unk_00 + D_800FE714_TightropeTreachery[0] * 70.0f * func_800AEFD0((src->unk_04 + 2500) / 5000.0 * 90.0) +
                      D_800FE398_TightropeTreachery;
        dst->unk_04 = src->unk_04;
        dst->unk_0C.r = src->unk_0C.r;
        dst->unk_0C.g = src->unk_0C.g;
        dst->unk_0C.b = src->unk_0C.b;
        src++;
        dst++;
    }
    m = D_800F2B7C[model].unk_6C;
    dst2 = m->unk_78;
    src2 = D_800FE6AC_TightropeTreachery;
    for (i = 0, n = m->unk_6E; i < n; i++) {
        dst2->unk_00 = src2->unk_00 + D_800FE714_TightropeTreachery[0] * 70.0f * func_800AEFD0((src2->unk_04 + 2500) / 5000.0 * 90.0) +
                       D_800FE398_TightropeTreachery;
        dst2->unk_02 = src2->unk_02;
        dst2->unk_04 = src2->unk_04;
        dst2++;
        src2++;
    }
    x = D_800FE714_TightropeTreachery[0] * 70.0f * func_800AEFD0((D_800F3FB0[0]->trans.z - 500.0f + 2500.0f) * 90.0 / 5000.0) +
        D_800FE398_TightropeTreachery;
    D_800FE384_TightropeTreachery = x;
    D_800FE390_TightropeTreachery = x - D_800FE38C_TightropeTreachery;
    D_800FE38C_TightropeTreachery = x;
    D_800FE70C_TightropeTreachery = D_800FE398_TightropeTreachery;
    if (D_800F3FB0[0]->trans.y >= D_800FE388_TightropeTreachery + -50.0 && w->unk_38 != -1.0f) {
        D_800F3FB0[0]->trans.x += D_800FE390_TightropeTreachery;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_TightropeTreachery/19ACC0", func_800F9508_TightropeTreachery);
#endif

/* The wind: gusts in a random direction, with their sound. */
void func_800F9BA0_TightropeTreachery(void) {
    if (D_800FE35D_TightropeTreachery == 1) {
        D_800FE3A3_TightropeTreachery = 0;
        D_800FE3A4_TightropeTreachery = 0;
        D_800FE3A1_TightropeTreachery = 1;
    }
    if (D_800FE3A4_TightropeTreachery == 1) {
        if (D_800FE3B0_TightropeTreachery++ > 90) {
            D_800FE3AC_TightropeTreachery = guRandom() % 120 / 2 + 30;
            D_800FE37C_TightropeTreachery = D_800FE3A5_TightropeTreachery = guRandom() % 5;
            D_800FE3A8_TightropeTreachery = 0;
            D_800FE3A4_TightropeTreachery = 0;
            D_800FE3A3_TightropeTreachery = 1;
        } else {
            D_800FE37C_TightropeTreachery = D_800FE3A5_TightropeTreachery = 6;
        }
    }
    if (D_800FE3A3_TightropeTreachery == 1) {
        if (D_800FE3A8_TightropeTreachery++ < D_800FE3AC_TightropeTreachery) {
            if (D_800FE3A0_TightropeTreachery == 0) {
                D_800FE6A0_TightropeTreachery = PlaySound(0x2AE);
                D_800FE35C_TightropeTreachery = 1;
                D_800FE710_TightropeTreachery = D_800FE6A0_TightropeTreachery;
                D_800FE3A2_TightropeTreachery = 0x60;
                func_8006035C(D_800FE6A0_TightropeTreachery, 0x60);
                D_800FE3A1_TightropeTreachery = 0;
                D_800FE3A0_TightropeTreachery = 1;
            }
            D_800FE380_TightropeTreachery += 0.012f;
            if (D_800FE380_TightropeTreachery > 0.4f) {
                D_800FE380_TightropeTreachery = 0.4f;
            }
        } else {
            D_800FE3A3_TightropeTreachery = 0;
            D_800FE3A4_TightropeTreachery = 1;
            D_800FE3B0_TightropeTreachery = 0;
            D_800FE37C_TightropeTreachery = D_800FE3A5_TightropeTreachery = 6;
            D_800FE3A1_TightropeTreachery = 1;
        }
    }
    if (D_800FE3A1_TightropeTreachery == 1 && D_800FE3A0_TightropeTreachery == 1) {
        D_800FE3A2_TightropeTreachery -= 3;
        if (D_800FE3A2_TightropeTreachery > 0) {
            func_8006035C(D_800FE6A0_TightropeTreachery, D_800FE3A2_TightropeTreachery);
        } else {
            D_800FE3A2_TightropeTreachery = 0x7F;
            func_8006071C(D_800FE6A0_TightropeTreachery);
            D_800FE35C_TightropeTreachery = 0;
            D_800FE3A1_TightropeTreachery = 0;
            D_800FE3A0_TightropeTreachery = 0;
        }
    }
    D_800FE380_TightropeTreachery -= 0.006666667f;
    if (D_800FE380_TightropeTreachery < 0.0f) {
        D_800FE380_TightropeTreachery = 0.0f;
    }
    if (D_800FE3A5_TightropeTreachery != 6) {
        D_800FE714_TightropeTreachery[0] = func_800AEAC0(D_800FE360_TightropeTreachery[D_800FE3A5_TightropeTreachery]) * D_800FE380_TightropeTreachery * 5.0f;
        D_800FE714_TightropeTreachery[1] = func_800AEFD0(D_800FE360_TightropeTreachery[D_800FE3A5_TightropeTreachery]) * D_800FE380_TightropeTreachery * 5.0f;
        D_800FE3A6_TightropeTreachery = D_800FE3A5_TightropeTreachery;
    } else {
        D_800FE714_TightropeTreachery[0] = func_800AEAC0(D_800FE360_TightropeTreachery[D_800FE3A6_TightropeTreachery]) * D_800FE380_TightropeTreachery * 5.0f;
        D_800FE714_TightropeTreachery[1] = func_800AEFD0(D_800FE360_TightropeTreachery[D_800FE3A6_TightropeTreachery]) * D_800FE380_TightropeTreachery * 5.0f;
    }
}

/* The leaves (models 4..7 of the water object). */
// scheduling of the leaf pointer and a 0.0f constant (masked ~8)
#ifdef NON_MATCHING
void func_800F9FD8_TightropeTreachery(omObjData* obj) {
    f32 r[2];
    TTLeaf* leaf;
    f32 ang;
    f32 bob;
    f32 base;
    s16 i;
    s16 j;

    for (i = 0; i < 4; i++) {
        if (D_800FE3B4_TightropeTreachery[i].active == 0) {
            if (D_800FE37C_TightropeTreachery != 6 && (guRandom() & 0x1F)) {
                for (j = 0; j < 2; j++) {
                    r[j] = guRandom() % 100 - 50.0f;
                }
                ang = (f32)(guRandom() % 90) - 45.0;
                ang += D_800FE360_TightropeTreachery[D_800FE37C_TightropeTreachery];
                ang -= ang / 360.0f * ang;
                D_800FE3B4_TightropeTreachery[i].phase = guRandom() % 180;
                D_800FE3B4_TightropeTreachery[i].x = func_800AEAC0(ang) * (r[0] + -450.0f);
                D_800FE3B4_TightropeTreachery[i].y = (f32)(guRandom() % 50) + 150.0f;
                D_800FE3B4_TightropeTreachery[i].z = D_800FE7C0_TightropeTreachery - 85.0f + 1150.0f - 200.0f + func_800AEFD0(ang) * (r[1] + -450.0f);
                D_800FE3B4_TightropeTreachery[i].vx = D_800FE3B4_TightropeTreachery[i].vz = 0.0f;
                D_800FE3B4_TightropeTreachery[i].tilt = guRandom() % 60 - 30;
                D_800FE3B4_TightropeTreachery[i].dir = guRandom() & 1;
                D_800FE3B4_TightropeTreachery[i].spin = guRandom() % 360 - 180;
                func_800258EC(obj->model[i + 4], 4, 0);
                func_80025798(obj->model[i + 4], D_800FE3B4_TightropeTreachery[i].x, D_800FE3B4_TightropeTreachery[i].y,
                              D_800FE3B4_TightropeTreachery[i].z);
                D_800FE3B4_TightropeTreachery[i].active = 1;
            }
        } else {
            D_800FE3B4_TightropeTreachery[i].phase %= 360;
            bob = func_800AEAC0(D_800FE3B4_TightropeTreachery[i].phase);
            leaf = &D_800FE3B4_TightropeTreachery[i];
            leaf->vx =
                func_800AEAC0(D_800FE360_TightropeTreachery[D_800FE37C_TightropeTreachery]) * (D_800FE380_TightropeTreachery / 2.0f) + D_800FE3B4_TightropeTreachery[i].vx;
            D_800FE3B4_TightropeTreachery[i].x = leaf->vx + D_800FE3B4_TightropeTreachery[i].x;
            leaf->vz =
                func_800AEFD0(D_800FE360_TightropeTreachery[D_800FE37C_TightropeTreachery]) * (D_800FE380_TightropeTreachery / 2.0f) + D_800FE3B4_TightropeTreachery[i].vz;
            D_800FE3B4_TightropeTreachery[i].z = leaf->vz + D_800FE3B4_TightropeTreachery[i].z;
            bob *= 40.0f;
            if (D_800FE3B4_TightropeTreachery[i].dir == 1) {
                D_800FE3B4_TightropeTreachery[i].tilt -= 3.0f;
                if (D_800FE3B4_TightropeTreachery[i].tilt < -30.0f) {
                    D_800FE3B4_TightropeTreachery[i].dir = 0;
                    D_800FE3B4_TightropeTreachery[i].tilt = -30.0f;
                }
            } else {
                D_800FE3B4_TightropeTreachery[i].tilt += 3.0f;
                if (D_800FE3B4_TightropeTreachery[i].tilt > 30.0f) {
                    D_800FE3B4_TightropeTreachery[i].dir = 1;
                    D_800FE3B4_TightropeTreachery[i].tilt = 30.0f;
                }
            }
            func_800257E4(obj->model[i + 4], 0.0f, D_800FE3B4_TightropeTreachery[i].spin, D_800FE3B4_TightropeTreachery[i].tilt);
            func_80025798(obj->model[i + 4], 0.0f + D_800FE3B4_TightropeTreachery[i].x, bob + D_800FE3B4_TightropeTreachery[i].y,
                          D_800FE3B4_TightropeTreachery[i].z);
            /* a leaf out of both ranges is gone */
            base = D_800FE7C0_TightropeTreachery - 85.0f + 1150.0f - 200.0f;
            if (!(D_800FE454_TightropeTreachery[0] < D_800FE3B4_TightropeTreachery[i].x && D_800FE3B4_TightropeTreachery[i].x < D_800FE454_TightropeTreachery[1]) &&
                !(base + D_800FE45C_TightropeTreachery[0] < D_800FE3B4_TightropeTreachery[i].z && D_800FE3B4_TightropeTreachery[i].z < base + D_800FE45C_TightropeTreachery[1])) {
                D_800FE3B4_TightropeTreachery[i].active = 0;
                func_800258EC(obj->model[i + 4], 4, 4);
            }
            D_800FE3B4_TightropeTreachery[i].phase += 5;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_TightropeTreachery/19ACC0", func_800F9FD8_TightropeTreachery);
#endif

/* Scrolls the texture coordinates of material `name` of a model. */
// load order of the material table base: retail loads m->unk_80 before the index math (masked 2); tried m->unk_80 + k, k inlined
#ifdef NON_MATCHING
void func_800FA838_TightropeTreachery(s16 model, f32 u, f32 v, s32 w, s32 h, char* name) {
    unk2C0C0StructC0* m = D_800F2B7C[model].unk_6C;
    unk2C0C0Struct30* mat;
    unk2C0C0StructE0* src;
    unk2C0C0StructE0* dst;
    u16 du;
    u16 dv;
    u16 sizeU;
    u16 sizeV;
    s16 n;
    s16 i;
    s16 k;

    if (m != NULL) {
        k = func_80033718(m, name);
        mat = &m->unk_80[k];
        n = mat->unk_0C;
        dst = src = &m->unk_08[D_800F37F0][mat->unk_0A];
        sizeU = w << 5;
        sizeV = h << 5;
        /* through u32 as GCC converts it (a direct float to u16 is undefined on the host once
           the scroll passes 65535) */
        du = (u32)(u * 32.0f);
        dv = (u32)(v * 32.0f);
        if (u < 0.0f) {
            u = -u;
        }
        if (v < 0.0f) {
            v = -v;
        }
        if (u * 32.0f > sizeU) {
            du %= sizeU;
        }
        if (v * 32.0f > sizeV) {
            dv %= sizeV;
        }
        for (i = 0; i < n; i++) {
            dst->unk_08 = du + src->unk_08;
            dst->unk_0A = dv + src->unk_0A;
            src++;
            dst++;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_TightropeTreachery/19ACC0", func_800FA838_TightropeTreachery);
#endif

/* The water's waves. */
void func_800FAAD8_TightropeTreachery(omObjData* obj) {
    unk2C0C0StructC0* m = D_800F2B7C[obj->model[0]].unk_6C;
    unk2C0C0StructE0* src = m->unk_04;
    unk2C0C0StructE0* dst = m->unk_08[D_800F37F0];
    s16 n = m->unk_72;
    s16 i;
    f32 dx1;
    f32 dz1;
    f32 dx2;
    f32 dz2;
    f32 d1;
    f32 d2;
    f32 h1;
    f32 h2;

    for (i = 0; i < n; i++) {
        *dst = *src;
        dx1 = src->unk_00 - 4000.0f;
        dz1 = src->unk_04 + 4000.0f;
        d1 = sqrtf(dx1 * dx1 + dz1 * dz1) / 30.0f;
        dx2 = src->unk_00 - 4000.0f;
        dz2 = src->unk_04 - 4000.0f;
        d2 = sqrtf(dx2 * dx2 + dz2 * dz2) / 12.0f * 12.0f;
        h1 = src->unk_02 + func_800AEAC0(d1 * 12.0f + D_800FE464_TightropeTreachery) * 30.0f;
        h2 = src->unk_02 + func_800AEFD0(D_800FE468_TightropeTreachery + d2 * 30.0) * 8.0f;
        if (h2 < h1) {
            dst->unk_02 = h1;
        } else {
            dst->unk_02 = h2;
        }
        dst->unk_00 = src->unk_00;
        dst->unk_04 = src->unk_04;
        dst->unk_0C.r = src->unk_0C.r;
        dst->unk_0C.g = src->unk_0C.g;
        dst->unk_0C.b = src->unk_0C.b;
        src++;
        dst++;
    }
    if (func_8005FD5C() + D_800F64F8 == 0) {
        D_800FE464_TightropeTreachery += 6.0f;
        D_800FE468_TightropeTreachery += 2.3f;
        if (D_800FE464_TightropeTreachery >= 360.0f) {
            D_800FE464_TightropeTreachery -= 360.0f;
        }
        if (D_800FE468_TightropeTreachery >= 360.0f) {
            D_800FE468_TightropeTreachery -= 360.0f;
        }
    }
}

void func_800FAE54_TightropeTreachery(omObjData* obj) {
    if (func_8005FD5C() + D_800F64F8 == 0) {
        if (D_800ED430 == 1) {
            func_800F9BA0_TightropeTreachery();
        }
        func_800F8BA0_TightropeTreachery();
        func_800F9FD8_TightropeTreachery(obj);
        D_800FE350_TightropeTreachery += 0.3f;
        D_800FE354_TightropeTreachery += 0.3f;
    }
    func_800FAAD8_TightropeTreachery(obj);
    func_800FA838_TightropeTreachery(obj->model[0], D_800FE350_TightropeTreachery, D_800FE354_TightropeTreachery,
                                     D_800FE6A8_TightropeTreachery.w, D_800FE6A8_TightropeTreachery.h, "00m_005-water");
}

/* The water (a ground object) and its four leaves. */
void func_800FAF34_TightropeTreachery(omObjData* obj) {
    TTGroundWork* w = func_80023684(sizeof(TTGroundWork), 0x7918);

    obj->unk_50 = w;
    func_8009B770(w, 0, sizeof(TTGroundWork));
    w->unk_04 = 2;
    w->unk_05 = 0;
    obj->model[0] = func_800174C0(8, 0x1A99);
    func_80026040(obj->model[0]);
    obj->model[4] = func_800174C0(0x320002, 0x299);
    func_80025830(obj->model[4], 0.8f, 0.8f, 0.8f);
    func_800258EC(obj->model[4], 4, 4);
    obj->model[5] = func_80023FC8(obj->model[4]);
    func_80025830(obj->model[5], 0.8f, 0.8f, 0.8f);
    func_800258EC(obj->model[5], 4, 4);
    obj->model[6] = func_80023FC8(obj->model[4]);
    func_80025830(obj->model[6], 0.8f, 0.8f, 0.8f);
    func_800258EC(obj->model[6], 4, 4);
    obj->model[7] = func_80023FC8(obj->model[4]);
    func_80025830(obj->model[7], 0.8f, 0.8f, 0.8f);
    func_800258EC(obj->model[7], 4, 4);
    func_80039C48("05mt000_DEF", &D_800FE6A8_TightropeTreachery);
    func_80026040(obj->model[0]);
    D_800FE350_TightropeTreachery = D_800FE354_TightropeTreachery = 0.0f;
    obj->trans.x = 0.0f;
    obj->trans.z = -800.0f;
    obj->trans.y = -600.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.22f;
    func_800F9204_TightropeTreachery(obj, 0.0f);
    obj->func_ptr = func_800FAE54_TightropeTreachery;
}

void func_800FB150_TightropeTreachery(omObjData* obj) {
    func_800F9508_TightropeTreachery(obj->model[0]);
}

/* The rope (a ground object) and the goal. */
void func_800FB170_TightropeTreachery(omObjData* obj) {
    TTGroundWork* w = func_80023684(sizeof(TTGroundWork), 0x7918);

    obj->unk_50 = w;
    func_8009B770(w, 0, sizeof(TTGroundWork));
    w->unk_04 = 1;
    w->unk_05 = 1;
    obj->model[0] = func_800174C0(0x320000, 0x299);
    func_800F9480_TightropeTreachery(obj->model[0]);
    obj->model[1] = func_800174C0(0x320003, 0x299);
    func_80008FC4(obj, 25.0f);
    func_80008FB8(obj, 0.5f);
    obj->trans.x = obj->trans.y = 0.0f;
    obj->trans.z = 500.0f;
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80025798(obj->model[1], 0.0f, 100.0f, -900.0f);
    func_80025830(obj->model[1], 0.5f, 0.5f, 0.5f);
    {
        TTHitGrid* g = &D_800F32AC[D_800F2B7C[obj->model[0]].unk_04];

        g->cw = 500.0f;
    }
    obj->func_ptr = func_800FB150_TightropeTreachery;
}

/* The direction from (0, 0) to (dx, dz), 0..360. */
f32 func_800FB2E0_TightropeTreachery(f32 dx, f32 dz) {
    f32 a = func_800B0CD8(dz, dx);

    if (a < 0.0) {
        a += 360.0;
    } else if (a >= 360.0) {
        a -= 360.0;
    }
    return a;
}

/* Blends model `model` between the vertices of `src` and its own (func_80026174). */
void func_800FB360_TightropeTreachery(s16 model, s16 src, s16 arg2, f32 t) {
    unk2C0C0StructC0* m = D_800F2B7C[model].unk_6C;
    unk2C0C0StructE0* save = m->unk_04;

    m->unk_04 = D_800F2B7C[src].unk_6C->unk_04;
    func_80026174(model, arg2, t);
    D_800F2B7C[model].unk_6C->unk_04 = save;
}

/* The rescuer: fishes a fallen walker out of the water and carries it back to the shore.
   work[0]: 0 wait, 1 fly to the walker, 2/3 carry it right/left, 4 done; work[2] wing phase;
   work[3] side. */
// scheduling of the show flag (masked ~7)
#ifdef NON_MATCHING
void func_800FB3F4_TightropeTreachery(omObjData* obj) {
    omObjData* p;
    s32 show;
    f32 dx;
    f32 dz;
    f32 ang;
    f32 s;
    f32 d;
    Vec3f step;
    s32 k;
    s16 k4;
    u16 pose0;
    u16 pose1;

    show = 1;
    switch (obj->work[0]) {
    case 0:
        if (D_800F3FB0[0]->trans.y <= -600.0f) {
            obj->work[0]++;
            func_800258EC(obj->model[0], 4, 0);
            func_800258EC(D_800F3FB0[0]->model[1], 4, 4);
            obj->work[3] = D_800F3FB0[0]->trans.x >= 0.0;
        } else {
            show = 0;
            func_800258EC(obj->model[0], 4, 4);
        }
        obj->trans.x = (obj->work[3] == 1) ? 900.0f : -900.0f;
        obj->trans.z = D_800F3FB0[0]->trans.z - (f32)(guRandom() % 200);
        break;
    case 1:
        p = D_800F3FB0[0];
        dx = p->trans.x - obj->trans.x;
        dz = p->trans.z - obj->trans.z;
        ang = func_800FB2E0_TightropeTreachery(dx, dz);
        s = func_800AEAC0((f32)obj->work[2] / 256.0 * 360.0) * 0.5 + 0.5;
        obj->trans.x += func_800AEFD0(ang) * (s * 0.1 + 0.05) * 20.0 * 8.0;
        obj->trans.z += func_800AEAC0(ang) * (s * 0.1 + 0.05) * 20.0 * 8.0;
        d = sqrtf(dx * dx + dz * dz);
        if (d < 20.0f) {
            p->work[3] = 1;
            if (p->trans.x > 0.0) {
                obj->work[0] = 2;
            } else {
                obj->work[0] = 3;
            }
        }
        D_800FE6A4_TightropeTreachery = D_800F3FB0[0]->trans.z - 20.0f;
        break;
    case 2:
    case 3:
        p = D_800F3FB0[0];
        k = obj->work[0] - 2;
        k4 = k * 4;
        s = func_800AEAC0((f32)obj->work[2] / 256.0 * 360.0) * 0.5 + 0.5;
        dx = D_800FE47C_TightropeTreachery[k * 4 + 2] - obj->trans.x;
        dz = D_800FE6A4_TightropeTreachery - obj->trans.z;
        ang = func_800FB2E0_TightropeTreachery(dx, dz);
        obj->trans.x += func_800AEFD0(ang) * (s * 0.1 + 0.05) * 20.0 * 6.0;
        obj->trans.z += func_800AEAC0(ang) * (s * 0.1 + 0.05) * 20.0 * 6.0;
        d = sqrtf(dx * dx + dz * dz);
        if (d < 10.0) {
            obj->work[0] = 4;
            p->work[3] = 2;
        }
        step.x = (obj->trans.x + D_800FE47C_TightropeTreachery[k4] - p->trans.x) * 0.2;
        step.y = (obj->trans.y + D_800FE47C_TightropeTreachery[k4 + 1] - p->trans.y) * 0.2;
        step.z = (obj->trans.z - p->trans.z) * 0.2;
        p->trans.x += step.x;
        p->trans.y += step.y;
        p->trans.z += step.z;
        break;
    default:
        show = 0;
        func_800258EC(D_800F3FB0[0]->model[0], 4, 4);
        func_800258EC(obj->model[0], 4, 4);
        break;
    }
    obj->work[2] += 8;
    if (show) {
        pose0 = D_800FE6B0_TightropeTreachery[D_800FE46C_TightropeTreachery[obj->work[0]][0]];
        pose1 = D_800FE6B0_TightropeTreachery[D_800FE46C_TightropeTreachery[obj->work[0]][1]];
        func_800FB360_TightropeTreachery(obj->model[0], pose0, pose1,
                                         func_800AEAC0((f32)obj->work[2] / 256.0 * 360.0) * 0.5 + 0.5);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_TightropeTreachery/19ACC0", func_800FB3F4_TightropeTreachery);
#endif

/* Loads the rescuer's poses. */
// decomp-permuter
void func_800FBAB4_TightropeTreachery(void)
{
  u16 ids[] = {8, 9, 10, 11, 12, 13, 0xFFFF};
  int new_var;
  s32 i;
  new_var = 0x350000;
  for (i = 0; ids[i] != 0xFFFF; i++)
  {
    D_800FE6B0_TightropeTreachery[i] = func_800174F4(new_var | ids[i], 0x9D);
  }

  for (i = 0; i < 4; i++)
  {
    D_800FE6C0_TightropeTreachery[i] = 0;
    D_800FE6D0_TightropeTreachery[i] = 0;
  }

}

void func_800FBBD0_TightropeTreachery(omObjData* obj) {
    void* w = func_80023684(0x6C, 0x7918);

    obj->unk_50 = w;
    func_8009B770(w, 0, 0x6C);
    func_800FBAB4_TightropeTreachery();
    obj->model[0] = func_800174F4(0x350008, 0x299);
    func_80026040(obj->model[0]);
    obj->trans.x = 1000.0f;
    obj->trans.y = -700.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 0.6f;
    obj->work[0] = obj->work[1] = obj->work[2] = obj->work[3] = 0;
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80025830(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    obj->func_ptr = func_800FB3F4_TightropeTreachery;
}
