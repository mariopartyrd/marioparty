#include "common.h"
#include "engine/pad.h"

s32 D_800B8950 = 0;
u8 D_800B8954 = 0;
u8 D_800B8955 = 1;
s16 D_800B8956 = 0;
u8 D_800B8958 = 0xFF;
u8 D_800B8959 = 0;
u8 D_800B895A = 0;
u8 D_800B895B = 0;
f32 D_800B895C = 15.0f;
f32 D_800B8960 = 0.5f;
f32 D_800B8964 = 1.47f;
f32 D_800B8968 = 0.15f;
f32 D_800B896C = 7.0f;
f32 D_800B8970 = 30.0f;
f32 D_800B8974 = 60.0f;
f32 D_800B8978 = 20.0f;
f32 D_800B897C = 3.3333333f;
f32 D_800B8980 = 18.0f;
f32 D_800B8984 = 13.5f;
f32 D_800B8988 = 9.0f;
f32 D_800B898C = 4.5f;
f32 D_800B8990 = 0.0f;
f32 D_800B8994 = 1.7f;
f32 D_800B8998 = 0.5f;
f32 D_800B899C = 0.147f;
s8 D_800B89A0 = 0;
/* Per-player model ids; overlay asm addresses row 0 through split labels (undefined_syms.txt). */
u16 D_800B89A4[4][14] = {
    { 0x0113, 0x011A, 0x0121, 0x0128, 0x012F, 0x0136, 0x013D, 0x0144, 0x0145, 0x0146, 0x0148, 0x014F, 0x0160, 0x0162 },
    { 0x0114, 0x011B, 0x0122, 0x0129, 0x0130, 0x0137, 0x013E, 0x0144, 0x0145, 0x0146, 0x0149, 0x0150, 0x0160, 0x0162 },
    { 0x0115, 0x011C, 0x0123, 0x012A, 0x0131, 0x0138, 0x013F, 0x0144, 0x0145, 0x0146, 0x014A, 0x0151, 0x0160, 0x0162 },
    { 0x0116, 0x011D, 0x0124, 0x012B, 0x0132, 0x0139, 0x0140, 0x0144, 0x0145, 0x0146, 0x014B, 0x0152, 0x0160, 0x0162 },
};
s16 D_800B8A14[6] = { 0, 0, 0, 0, 0, 0 }; /* unreferenced */
s32 D_800B8A20[] = { 0x0001009E, 0x0002009E, 0x0006009E, 0x0003009E, 0x0004009E, 0x0005009E };
s32 D_800B8A38[] = { 0x000100A0, 0x000200A0, 0x000600A0, 0x000300A0, 0x000400A0, 0x000500A0 };
extern const char D_800C9F70[], D_800C9F60[], D_800C9F50[], D_800C9F40[], D_800C9F30[], D_800C9F20[];
char* D_800B8A50[] = {
    (char*)D_800C9F70, (char*)D_800C9F60, (char*)D_800C9F50, (char*)D_800C9F40, (char*)D_800C9F30, (char*)D_800C9F20,
};

extern Vec3f D_800CD9B0;

void func_8000A534(void*, f32);
void func_8001E268(u8, s32, s32);
void func_8001E3B4(u8);
f32 func_80025D18(s16);
f32 func_80025E70(s16);

typedef struct ColVtx {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 z;
} ColVtx;

typedef struct ColTri {
    /* 0x0 */ s16 flags;
    /* 0x2 */ s16 v[3];
} ColTri;

/* Collision probe: a sphere plus a second (previous?) position. */
typedef struct ColSphere {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
    /* 0x0C */ f32 r;
    /* 0x10 */ f32 x2;
    /* 0x14 */ f32 y2;
    /* 0x18 */ f32 z2;
} ColSphere;

/* Work block of a moving floor / platform object in D_800F2AF8. */
typedef struct GroundWork {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ char unk_02[2];
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ s8 unk_05;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18; /* box min x */
    /* 0x1C */ f32 unk_1C; /* box min z */
    /* 0x20 */ f32 unk_20; /* box max x */
    /* 0x24 */ f32 unk_24; /* box max z */
} GroundWork;

/* Per-object work block hung off omObjData::unk_50 by the minigame player/actor code. */
typedef struct PlayerWork {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ char unk_06[4];
    /* 0x0A */ u16 unk_0A;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ u8 unk_24;
    /* 0x25 */ char unk_25[3];
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ s8 unk_53;
    /* 0x54 */ s8 unk_54;
    /* 0x55 */ s8 unk_55;
    /* 0x56 */ u8 unk_56;
    /* 0x57 */ s8 unk_57;
    /* 0x58 */ s8 unk_58;
    /* 0x59 */ char unk_59[3];
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ f32 unk_68;
    /* 0x6C */ s32 unk_6C[6]; /* MgWork's stick samples; no pointers here, so host offsets agree */
    /* 0x84 */ f32 unk_84;
    /* 0x88 */ f32 unk_88;
    /* 0x8C */ f32 unk_8C;
    /* 0x90 */ f32 unk_90;
    /* 0x94 */ f32 unk_94;
    /* 0x98 */ f32 unk_98;
    /* 0x9C */ f32 unk_9C;
    /* 0xA0 */ f32 unk_A0;
    /* 0xA4 */ f32 unk_A4;
    /* 0xA8 */ char unk_A8[4];
    /* 0xAC */ u16 unk_AC;
    /* 0xAE */ u16 unk_AE;
    /* 0xB0 */ u8 unk_B0;
    /* 0xB1 */ s8 unk_B1;
    /* 0xB2 */ s8 unk_B2;
    /* 0xB3 */ s8 unk_B3;
    /* 0xB4 */ s16 unk_B4;
    /* 0xB6 */ char unk_B6[2];
    /* 0xB8 */ void* unk_B8; /* MgWork's held item: a pointer, so the host layout agrees */
    /* 0xBC */ f32 unk_BC;
    /* 0xC0 */ u16 unk_C0;
    /* 0xC2 */ char unk_C2[0x16];
    /* 0xD8 */ void* unk_D8;
    /* 0xDC */ s32 (*unk_DC)(omObjData*, omObjData*);
    /* 0xE0 */ u16 unk_E0;
    /* 0xE2 */ char unk_E2[2];
    /* 0xE4 */ void* unk_E4;
} PlayerWork; /* size = 0xE8 */

extern omObjData* D_800EDE70[];
extern u16 D_800EE984;
extern u16 D_800F370C;
extern f32 D_800ED6B8;
extern f32 D_800F5254;

f32 func_80000530(f32, f32, f32, ColVtx*, ColTri*, Vec3f*, Vec3f*);
s32 func_80000828(Vec4f*, s16*, ColVtx*);
s32 func_80000F3C(omObjData*, f32, f32, f32);
s32 func_8000396C(ColSphere*, GroundWork*);
f32 func_80004578(omObjData*, f32, f32, f32, f32);
void func_80005A28(omObjData*);
void func_800078E8(f32, f32, f32);
void func_80007B34(omObjData*, f32, f32, f32);
f32 func_80007954(f32);
void func_800079A8(omObjData*, f32, f32, f32);
void func_80007A50(omObjData*);
void func_800093FC(omObjData*, f32, f32, f32);
s32 func_80009C90(omObjData*, s16, s16);
void func_80009D48(s16*, s16*);
s32 func_80009E4C(s8, s32, s8, s8);
void func_8000A6F4(omObjData*);
s32 func_80017A60(omObjData*);
void func_8001802C(omObjData*);

int abs(int);
void func_800090D8(omObjData*, s32, s32);
void func_800096B0(PlayerWork*, s32);
void func_8000A988(omObjData*, f32, f32);
void func_8000ACE4(omObjData*, omObjData*);
void func_80017C0C(omObjData*, s32, f32, f32, f32, f32, f32);
void func_80018450(omObjData*, s32);
void func_8001E2A8(s16, u16);
void func_80060F04(s16, s32, s32, s32);
void func_800295FC(ColVtx*, ColVtx*, ColVtx*, Vec3f*);
void func_8002956C(Vec3f*);
void func_8000A464(void*, Vec3f*);
s32 func_80004D1C(omObjData*, Vec4f*, f32);
f32 func_800051D4(omObjData*, f32, f32, f32, Vec3f*);
void func_800057F4(omObjData*, Vec3f*);
s32 func_8000A910(Vec4f*, GroundWork*);
f32 func_80029764(f32, f32, f32, ColVtx*, ColTri*);
void func_8002AE24(s16, s32*, void*, void*);
ColTri* func_8002B3A8(s32*);
void func_80037178(s16, Vec3f*);
s32 func_80009138(s8);
void func_8000A1C0(void*, void*, ColSphere*, omObjData*);
void func_8000A634(omObjData*, omObjData*);
f32 func_80029518(f32);
s32 func_8000A830(void*, ColSphere*, f32);
s32 func_8000A798(void*, ColSphere*);
void func_8000A3E8(void*, Vec3f*);
void func_8000A4F8(void*, ColSphere*);
s32 func_80019964(f32[3][3], Vec3f*, f32, Vec3f*);
s32 func_80019EDC(f32[4][3], Vec3f*, f32, Vec3f*);

extern s8 D_800F3704;
extern omObjData* D_800F2AF8[];
extern u8 D_800ED6E0[];
extern u8 D_800F2B80[];
/* Contact points, one Vec3f array. The bss splits its y and z columns into their own labels
   (D_800EDED4 = &D_800EDED0[0].y, D_800EDED8 = &D_800EDED0[0].z) and the code addresses each
   column through its label, so they are declared as three Vec3f arrays and read through .x. */
extern Vec3f D_800EDED0[];
extern Vec3f D_800EDED4[];
extern Vec3f D_800EDED8[];
f32 func_800296FC(f32, f32, ColVtx*, ColVtx*);

f32 func_80000530(f32 x, f32 y, f32 z, ColVtx* verts, ColTri* tri, Vec3f* dir, Vec3f* out) {
    Vec3f n;
    f32 vx, vy, vz;
    f32 dx, dy, dz;
    f32 t;
    f32 d;
    f32 nx, ny, nz;
    ColVtx* v = &verts[tri->v[0]];

    vx = v->x;
    vy = v->y;
    vz = v->z;
    dx = dir->x;
    dy = dir->y;
    dz = dir->z;
    func_800295FC(v, &verts[tri->v[1]], &verts[tri->v[2]], &n);
    nx = n.x;
    ny = n.y;
    nz = n.z;
    d = nx * dx + ny * dy + nz * dz;
    t = (nx * (vx - x) + ny * (vy - y) + nz * (vz - z)) / d;
    x += dx * t;
    out->x = x;
    y += dy * t;
    out->y = y;
    z += dz * t;
    out->z = z;
    return y;
}
f32 func_800006E4(omObjData* obj, f32 y) {
    u8* w = obj->unk_50;
    f32 r = obj->trans.y;

    if (w[w[0x53]] & 2) {
        r = y;
    }
    return r;
}
s32 func_80000710(Vec3f* pos, ColTri* tri, ColVtx* verts) {
    Vec3f n;
    ColVtx* v;
    f32 vx, vy, vz;
    f32 dx, dy, dz;
    s32 ret;

    func_800295FC(&verts[tri->v[0]], &verts[tri->v[1]], &verts[tri->v[2]], &n);
    v = &verts[tri->v[0]];
    vx = v->x;
    vy = v->y;
    vz = v->z;
    dx = vx - pos->x;
    dy = vy - pos->y;
    dz = vz - pos->z;
    ret = 1;
    if (dx * n.x + dy * n.y + dz * n.z < 0.0f) {
        ret = -1;
    }
    return ret;
}

s32 func_80000828(Vec4f* s, s16* tri, ColVtx* verts) {
    s32 side = -1;
    Vec3f n;
    ColVtx* v;
    f32 dx, dy, dz;
    f32 vx, vy, vz;
    f32 d;
    f32 t;

    if ((tri[0] & 0x3F00) <= 0x200) {
        return 0;
    }
    func_800295FC(&verts[tri[1]], &verts[tri[2]], &verts[tri[3]], &n);
    v = &verts[tri[1]];
    vx = v->x;
    vy = dx = v->y; // dx is reassigned below; the extra copy (decomp-permuter) reproduces retail's registers
    vz = v->z;
    dx = vx - s->x;
    dy = vy - s->y;
    dz = vz - s->z;
    d = dx * n.x + dy * n.y + dz * n.z;
    if (d >= 0.0f) {
        side = 1;
    }
    if (fabsf(d) > s->w) {
        return 0;
    }
    t = dx * n.x + dy * n.y + dz * n.z;
    s->x += t * n.x;
    s->y += t * n.y;
    s->z += t * n.z;
    return side;
}
f32 func_800009D8(f32 x, f32 y, f32 z, ColVtx* a, ColVtx* b, Vec3f* n) {
    f32 ax = a->x - x;
    f32 ay = a->y - y;
    f32 az = a->z - z;
    f32 bx = b->x - x;
    f32 by = b->y - y;
    f32 bz = b->z - z;

    return (ay * bz - az * by) * n->x + (az * bx - ax * bz) * n->y + (ax * by - ay * bx) * n->z;
}
s32 func_80000AB4(Vec3f* p, s16* idx, ColVtx* verts, Vec3f* n) {
    f32 x = p->x;
    f32 y = p->y;
    f32 z = p->z;
    s32 cnt = ((u16)*idx >> 14) + 2;
    s32 i;
    s32 j;

    idx++;
    if (func_800009D8(x, y, z, &verts[idx[0]], &verts[idx[1]], n) > 0.0f) {
        for (i = 1; i < cnt; i++) {
            j = (i + 1) % cnt;
            if (func_800009D8(x, y, z, &verts[idx[i]], &verts[idx[j]], n) < 0.0f) {
                return 0;
            }
        }
    } else {
        for (i = 1; i < cnt; i++) {
            j = (i + 1) % cnt;
            if (func_800009D8(x, y, z, &verts[idx[i]], &verts[idx[j]], n) > 0.0f) {
                return 0;
            }
        }
    }
    return 1;
}
s32 func_80000D14(Vec3f* p, ColTri* tri, ColVtx* verts) {
    f32 x, z;
    s32 cnt;
    s16* idx;
    s32 i;
    s32 j;

    idx = (s16*)tri;
    if (((u16)*idx & 0x3F00) > 0x200) {
        return 0;
    }
    x = p->x;
    z = p->z;
    cnt = ((u16)*idx >> 14) + 2;
    idx++;
    if (func_800296FC(x, z, &verts[idx[0]], &verts[idx[1]]) > 0.0f) {
        for (i = 1; i < cnt; i++) {
            j = (i + 1) % cnt;
            if (func_800296FC(x, z, &verts[idx[i]], &verts[idx[j]]) < 0.0f) {
                return 0;
            }
        }
    } else {
        for (i = 1; i < cnt; i++) {
            j = (i + 1) % cnt;
            if (func_800296FC(x, z, &verts[idx[i]], &verts[idx[j]]) > 0.0f) {
                return 0;
            }
        }
    }
    return 1;
}
// register allocation (masked 150) and block layout around the shared return-2 tail
#ifdef NON_MATCHING
s32 func_80000F3C(omObjData* obj, f32 x, f32 y, f32 z) {
    PlayerWork* w = obj->unk_50;
    f32 radius = w->unk_48;
    f32 speed = w->unk_40;
    omObjData* o;
    PlayerWork* ow;
    PlayerWork* ow2;
    f32 dx, dy, dz;
    f32 dist, flat;
    f32 dxx, dzz;
    f32 a;
    f32 dz2;
    u16 i;
    u8 c;
    s16 m;

    if (w->unk_50 & 6) {
        speed *= 0.6f;
    }
    speed *= (w->unk_38 != 1000.0f) ? w->unk_4C * w->unk_A4 : w->unk_A4;
    x += func_800AEAC0(w->unk_3C) * speed;
    z += func_800AEFD0(w->unk_3C) * speed;
    w->unk_E0 = 0;

    for (i = 0; i < D_800EE984; i++) {
        o = D_800EDE70[i];
        ow = o->unk_50;
        if ((u8)ow->unk_54 == 0) {
            continue;
        }
        dx = o->trans.x - (x + D_800ED6B8);
        dy = o->trans.y - y;
        dz = o->trans.z - (z + D_800F5254);
        flat = 100.0f;
        if (ow->unk_34 != 0.0f && o->trans.y <= y && y <= o->trans.y + ow->unk_34) {
            flat = func_800B1750(dx * dx + dz * dz) - (radius + ow->unk_48);
        }
        dist = func_800B1750(dx * dx + dy * dy + dz * dz) - (radius + ow->unk_48);
        if ((dist < 0.0f) | (flat < 0.0f)) {
            if (w->unk_DC != NULL && w->unk_DC(obj, o) == 1) {
                continue;
            }
            if (ow->unk_52 == 7) {
                if (w->unk_AE != 0) {
                    D_800F370C++;
                    continue;
                }
                if (w->unk_50 & 0x200) {
                    continue;
                }
                a = func_8000A72C(func_800AEAC0(w->unk_3C), func_800AEFD0(w->unk_3C), dx, dz);
                if (w->unk_50 & 0x20) {
                    func_8000A534(obj, D_800B8988);
                }
                if (a > 0.0f) {
                    func_800184BC(obj, 9);
                    w->unk_40 = -D_800B8980;
                } else {
                    func_800184BC(obj, 10);
                    w->unk_40 = D_800B8980;
                }
                w->unk_38 = -D_800B8964 * 0.7f;
                w->unk_AE = 105;
                func_80017C0C(obj, 5, o->trans.x, y, o->trans.z, 0.0f, func_800B0CD8(dx, dz) + 180.0f);
                func_80009624((unkGlobalStruct_00*)w, 8);
                func_80060F04(w->unk_58, 2, 2, 20);
            } else if (ow->unk_50 & 0x40) {
                if (!(ow->unk_50 & 0x20)) {
                    dist = func_800B1750(dx * dx + dy * dy + dz * dz) - (ow->unk_48 + w->unk_48);
                    if (dist < 0.0f) {
                        if (ow->unk_38 < 1000.0f) {
                            ow->unk_38 = -D_800B8964 * 0.6f;
                            if (func_8000A72C(func_800AEAC0(ow->unk_3C), func_800AEFD0(ow->unk_3C), dx, dz) < 0.0f) {
                                ow->unk_40 = -D_800B898C;
                            } else {
                                ow->unk_40 = D_800B898C;
                            }
                        } else if (ow->unk_40 == D_800B8990) {
                            if (w->unk_38 != 1000.0f) {
                                func_8000A988(obj, dx, dz);
                                func_800096B0(w, 9);
                            } else {
                                if ((dx == 0.0f) & (dz == 0.0f)) {
                                    dx = func_800AEAC0(w->unk_3C);
                                    dz = func_800AEFD0(w->unk_3C);
                                }
                                func_800078E8(dx, dz, dist);
                            }
                        } else {
                            ow->unk_40 = -ow->unk_40;
                        }
                    }
                }
            } else if (w->unk_AE != 0) {
                D_800F370C++;
            } else {
                c = ow->unk_24;
                m = (u8)o->model[3];
                func_800258EC(m, 4, 0);
                func_8001E2A8(c, 0);
                func_8001E268(c, 4, 4);
                func_80025798(m, x, y, z);
                func_80025830(m, 5.0f, 5.0f, 5.0f);
                switch (ow->unk_52) {
                    case 3:
                        GwPlayer[w->unk_58].coins_mg += 1;
                        PlaySound(0xFC);
                        break;
                    case 4:
                        GwPlayer[w->unk_58].coins_mg += 3;
                        PlaySound(0xFD);
                        break;
                    case 5:
                        GwPlayer[w->unk_58].coins_mg += 2;
                        PlaySound(0x105);
                        break;
                    case 6:
                        GwPlayer[w->unk_58].coins_mg += 5;
                        PlaySound(0x109);
                        func_80060F04(w->unk_58, 2, 3, 10);
                        break;
                }
                ow->unk_54 = 0;
                func_800090D8(o, 0, 0);
                func_800090D8(o, 1, 0);
            }
        }
    }

    y += w->unk_48;
    for (i = 0; i < D_800F2BC0; i++) {
        o = D_800F3FB0[i];
        ow2 = o->unk_50;
        if (w == ow2) {
            continue;
        }
        dx = o->trans.x - (x + D_800ED6B8);
        dy = (o->trans.y + ow2->unk_48) - y;
        dz2 = o->trans.z - (z + D_800F5254);
        dxx = dx * dx;
        dzz = dz2 * dz2;
        dist = func_800B1750(dxx + dzz) - (w->unk_48 + ow2->unk_48) * 0.6f;
        flat = func_800B1750(dxx + dy * dy + dzz) - (ow2->unk_48 + w->unk_48);
        if (((dist < 0.0f) | (flat < 0.0f)) && w->unk_38 != 1000.0f && !(w->unk_50 & 0x8000)) {
            if (y - (ow2->unk_34 + ow2->unk_48) <= o->trans.y && o->trans.y <= (y - w->unk_48) + w->unk_34) {
                if (!(ow2->unk_50 & 7) && w->unk_AE == 0 && ow2->unk_AE == 0) {
                    if (ow2->unk_38 != 1000.0f) {
                        if (w->unk_5C & 0x200) {
                            if (!(dist < 0.0f && dy < -w->unk_34 * 0.5f)) {
                                goto block_93;
                            }
                            func_80017C0C(obj, 7, x, y, z, 0.0f, 0.0f);
                            if (!(ow2->unk_50 & 0x200)) {
                                func_80018450(o, 1);
                                func_800184BC(o, 0x1E);
                                if (ow2->unk_50 & 0x20) {
                                    func_8000A534(o, D_800B898C);
                                }
                            }
                            ow2->unk_38 = w->unk_38;
                            goto block_104;
                        block_93:
                            if (D_800B8955 != 1) {
                                goto block_78;
                            }
                            func_8000ACE4(obj, o);
                            return 0;
                        }
                        if (!(dist < 0.0f && dy < -w->unk_34 * 0.2)) {
                            goto block_93;
                        }
                        if (!(ow2->unk_50 & 0x200)) {
                            func_80017C0C(obj, 6, x, y, z, -90.0f, 0.0f);
                            func_80018450(o, 2);
                            if (ow2->unk_50 & 0x20) {
                                func_8000A534(o, D_800B898C);
                            }
                        }
                        if (ow2->unk_38 < 0.0f) {
                            ow2->unk_38 = 0.0f;
                        }
                    block_104:
                        ow2->unk_40 = D_800B8990;
                        func_8000A988(obj, dx, dz2);
                        func_800096B0(w, 9);
                        func_80060F04(w->unk_58, 2, 3, 10);
                        func_80060F04(ow2->unk_58, 2, 3, 10);
                        return 2;
                    block_78:
                        func_800078E8(dx, dz2, func_800B1750(dx * dx + dz2 * dz2) - (ow2->unk_48 + w->unk_48));
                        return 0;
                    }
                    if ((dist < 0.0f) & (dy < 0.0f)) {
                        if (!(ow2->unk_50 & 0x200)) {
                            if (w->unk_5C & 0x200) {
                                func_80018450(o, 1);
                                func_800184BC(o, 0);
                                func_80017C0C(obj, 7, x, y, z, 0.0f, 0.0f);
                            } else {
                                func_80017C0C(obj, 6, x, y, z, -90.0f, 0.0f);
                                func_80018450(o, 2);
                            }
                            if (ow2->unk_50 & 0x20) {
                                func_8000A534(o, D_800B898C);
                            }
                        }
                        func_8000A988(obj, dx, dz2);
                        func_800096B0(w, 9);
                        func_80060F04(w->unk_58, 2, 3, 10);
                        func_80060F04(ow2->unk_58, 2, 2, 20);
                        return 2;
                    }
                    func_8000A988(obj, dx, dz2);
                    w->unk_38 = -D_800B8964 * 0.6f;
                    w->unk_40 = w->unk_40 * 0.5;
                    func_800096B0(w, 9);
                    func_80060F04(w->unk_58, 2, 3, 10);
                    func_80060F04(ow2->unk_58, 2, 2, 20);
                } else if (w->unk_38 != 1000.0f && ow2->unk_38 != 1000.0f) {
                    if (w->unk_AE != 0 || ow2->unk_AE != 0) {
                        if (D_800B8955 == 1) {
                            func_8000ACE4(obj, o);
                            func_80060F04(w->unk_58, 2, 3, 10);
                            return 0;
                        }
                        func_800078E8(dx, dz2, flat);
                        return 0;
                    }
                } else {
                    if (w->unk_5C & 0x200) {
                        func_80017C0C(obj, 7, x, y, z, 0.0f, 0.0f);
                    } else {
                        func_80017C0C(obj, 6, x, y, z, -90.0f, 0.0f);
                    }
                    func_80060F04(w->unk_58, 2, 3, 10);
                    func_8000A988(obj, dx, dz2);
                    func_800096B0(w, 9);
                }
            } else if (flat < 0.0f) {
                if (D_800B8955 == 1) {
                    func_8000ACE4(obj, o);
                } else {
                    func_800078E8(dx, dz2, flat);
                }
            }
        } else {
            flat = func_800B1750(dx * dx + dy * dy + dz2 * dz2) - (ow2->unk_48 + w->unk_48);
            if (flat < 0.0f && (ow2->unk_38 == 1000.0f || w->unk_38 != 1000.0f)) {
                func_800078E8(dx, dz2, flat);
                w->unk_54 = i;
            }
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/1130", func_80000F3C);
#endif
void func_80001F84(omObjData* obj) {
    PlayerWork* w = obj->unk_50;
    f32 r = w->unk_48;
    f32 rot;

    if (r < func_800B1750(D_800ED6B8 * D_800ED6B8 + D_800F5254 * D_800F5254) || fabs(D_800ED6B8) > r ||
        fabs(D_800F5254) > r) {
        rot = w->unk_3C;
        D_800ED6B8 = -func_800AEAC0(rot) * w->unk_40;
        D_800F5254 = -func_800AEFD0(rot) * w->unk_40;
    }
}
s32 func_80002060(void* arg0, s16* idx, ColVtx* verts, Vec3f* p) {
    return func_80000D14(p, (ColTri*)(idx - 1), verts);
}
s32 func_80002080(void* arg0, s16* idx, ColVtx* verts, ColSphere* s) {
    Vec4f sph;
    Vec3f pos;
    Vec3f hitPos;
    f32 quad[4][3];
    f32 tri3[3][3];
    Vec3f dir;
    s16* tri;
    s32 side;
    s32 hit;
    f32 pen, dz, dx;

    pos.x = sph.x = s->x + D_800ED6B8;
    pos.y = sph.y = s->y;
    pos.z = sph.z = s->z + D_800F5254;
    sph.w = s->r;
    tri = idx - 1;
    side = func_80000828(&sph, tri, verts);
    if (side == 0) {
        return 0;
    }
    if (((u16)*tri >> 14) + 2 == 4) {
        quad[0][0] = verts[idx[0]].x;
        quad[0][1] = verts[idx[0]].y;
        quad[0][2] = verts[idx[0]].z;
        quad[1][0] = verts[idx[1]].x;
        quad[1][1] = verts[idx[1]].y;
        quad[1][2] = verts[idx[1]].z;
        quad[2][0] = verts[idx[2]].x;
        quad[2][1] = verts[idx[2]].y;
        quad[2][2] = verts[idx[2]].z;
        quad[3][0] = verts[idx[3]].x;
        quad[3][1] = verts[idx[3]].y;
        quad[3][2] = verts[idx[3]].z;
        hit = func_80019EDC(quad, &pos, sph.w, &hitPos);
    } else {
        tri3[0][0] = verts[idx[0]].x;
        tri3[0][1] = verts[idx[0]].y;
        tri3[0][2] = verts[idx[0]].z;
        tri3[1][0] = verts[idx[1]].x;
        tri3[1][1] = verts[idx[1]].y;
        tri3[1][2] = verts[idx[1]].z;
        tri3[2][0] = verts[idx[2]].x;
        tri3[2][1] = verts[idx[2]].y;
        tri3[2][2] = verts[idx[2]].z;
        hit = func_80019964(tri3, &pos, sph.w, &hitPos);
    }
    if (hit == 1) {
        D_800EDED0[D_800B8956].x = hitPos.x;
        D_800EDED4[D_800B8956].x = hitPos.y;
        D_800EDED8[D_800B8956].x = hitPos.z;
        D_800B8956++;
        dx = hitPos.x - pos.x;
        dz = hitPos.z - pos.z;
        pen = sph.w - func_800B1750(dx * dx + dz * dz);
        if (side > 0) {
            idx--;
            if (func_80000710(&D_800CD9B0, (ColTri*)idx, verts) < 0) {
                dir.x = D_800CD9B0.x - pos.x;
                dir.y = D_800CD9B0.y - pos.y;
                dir.z = D_800CD9B0.z - pos.z;
                func_8002956C(&dir);
                if (func_80000AB4(&pos, idx, verts, &dir) == hit) {
                    pen = func_800B1750(dx * dx + dz * dz) + sph.w;
                }
            } else {
                pen = 0.0f;
            }
        }
        func_800078E8(-dx, -dz, pen);
    }
    return hit;
}
s32 func_8000261C(void* arg0, s16* idx, ColVtx* verts, ColSphere* s) {
    Vec4f sph;
    Vec4f pos;
    Vec3f hitPos;
    f32 quad[4][3];
    f32 tri3[3][3];
    Vec3f dir;
    s16* tri;
    s32 side;
    s32 hit;
    f32 pen, dz, dx;

    pos.x = sph.x = s->x + D_800ED6B8;
    pos.y = sph.y = s->y;
    pos.z = sph.z = s->z + D_800F5254;
    sph.w = pos.w = s->r;
    tri = idx - 1;
    side = func_80000828(&sph, tri, verts);
    if (side == 0) {
        return 0;
    }
    if (((u16)*tri >> 14) + 2 == 4) {
        quad[0][0] = verts[idx[0]].x;
        quad[0][1] = verts[idx[0]].y;
        quad[0][2] = verts[idx[0]].z;
        quad[1][0] = verts[idx[1]].x;
        quad[1][1] = verts[idx[1]].y;
        quad[1][2] = verts[idx[1]].z;
        quad[2][0] = verts[idx[2]].x;
        quad[2][1] = verts[idx[2]].y;
        quad[2][2] = verts[idx[2]].z;
        quad[3][0] = verts[idx[3]].x;
        quad[3][1] = verts[idx[3]].y;
        quad[3][2] = verts[idx[3]].z;
        hit = func_80019EDC(quad, (Vec3f*)&pos, sph.w, &hitPos);
    } else {
        tri3[0][0] = verts[idx[0]].x;
        tri3[0][1] = verts[idx[0]].y;
        tri3[0][2] = verts[idx[0]].z;
        tri3[1][0] = verts[idx[1]].x;
        tri3[1][1] = verts[idx[1]].y;
        tri3[1][2] = verts[idx[1]].z;
        tri3[2][0] = verts[idx[2]].x;
        tri3[2][1] = verts[idx[2]].y;
        tri3[2][2] = verts[idx[2]].z;
        hit = func_80019964(tri3, (Vec3f*)&pos, sph.w, &hitPos);
    }
    if (hit == 1) {
        pos.x = s->x2 + D_800ED6B8;
        pos.y = s->y2;
        pos.z = s->z2 + D_800F5254;
        func_8000A464(D_800F2B80, &hitPos);
        D_800EDED0[D_800B8956].x = hitPos.x;
        D_800EDED4[D_800B8956].x = hitPos.y;
        D_800EDED8[D_800B8956].x = hitPos.z;
        D_800B8956++;
        dx = hitPos.x - pos.x;
        dz = hitPos.z - pos.z;
        pen = sph.w - func_800B1750(dx * dx + dz * dz);
        if (side > 0) {
            sph.x = D_800CD9B0.x;
            sph.y = D_800CD9B0.y;
            sph.z = D_800CD9B0.z;
            func_8000A464(D_800ED6E0, (Vec3f*)&sph);
            idx--;
            if (func_80000710((Vec3f*)&sph, (ColTri*)idx, verts) < 0) {
                dir.x = sph.x - pos.x;
                dir.y = sph.y - pos.y;
                dir.z = sph.z - pos.z;
                func_8002956C(&dir);
                if (func_80000AB4((Vec3f*)&pos, idx, verts, &dir) == hit) {
                    pen = func_800B1750(dx * dx + dz * dz) + sph.w;
                }
            } else {
                pen = 0.0f;
            }
        }
        if (pen >= 0.0f) {
            func_800078E8(-dx, -dz, pen);
        }
    }
    return hit;
}
f32 func_80002C48(omObjData* obj, f32 rot, f32 x, f32 y, f32 z) {
    Vec4f probe;
    Vec3f n;
    Vec3f n2;
    PlayerWork* w;
    GroundWork* gw;
    GroundWork* cur;
    ColVtx* verts;
    ColTri* tri;
    s16 mdl;
    Vec3f* normal;
    s32 ground;
    f32 speed;
    f32 sa, sb;
    f32 floorY, shadowY;
    f32 h;
    f32 nx, nz;

    ground = -1;
    w = obj->unk_50;
    w->unk_54 = ground;
    w->unk_53 = ground;
    normal = NULL;
    sa = w->unk_40;
    sb = w->unk_A4;
    if (w->unk_50 & 6) {
        speed = sa * 0.6f * sb;
    } else {
        speed = sa * sb;
    }
    if (fabs(w->unk_84) > 1.0) {
        D_800ED6B8 += w->unk_84;
    }
    if (fabs(w->unk_8C) > 1.0) {
        D_800F5254 += w->unk_8C;
    }
    nx = x + func_800AEAC0(rot) * speed + D_800ED6B8;
    nz = z + func_800AEFD0(rot) * speed + D_800F5254;
    shadowY = floorY = -65536.0f;
    if (func_80000F3C(obj, nx, y, nz) != 2) {
    func_80001F84(obj);
    sa = w->unk_40;
    sb = w->unk_A4;
    if (w->unk_50 & 6) {
        speed = sa * 0.6f * sb;
    } else {
        speed = sa * sb;
    }
    nx = x + func_800AEAC0(rot) * speed;
    nz = z + func_800AEFD0(rot) * speed;
    probe.x = nx + D_800ED6B8;
    probe.y = y;
    probe.z = nz + D_800F5254;
    probe.w = w->unk_48;
    func_80004D1C(obj, &probe, 0);
    func_80001F84(obj);
    probe.x = nx + D_800ED6B8;
    probe.y = y;
    probe.z = nz + D_800F5254;
    if (!(((u8*)w)[D_800B8954] & 1)) {
        gw = D_800F2AF8[D_800B8954]->unk_50;
        if (gw->unk_01 & 0x1A) {
            if (func_8000A910(&probe, gw) == 1) {
                h = gw->unk_10;
                if (floorY < h && h < y + 150.0f) {
                    floorY = h;
                    ground = D_800B8954;
                    if (shadowY < floorY && shadowY < y + 35.0f) {
                        shadowY = floorY;
                        n.x = 0.0f;
                        n.y = 1.0f;
                        n.z = 0.0f;
                        normal = &n;
                    }
                }
            }
        } else {
            mdl = *D_800F2AF8[D_800B8954]->model;
            verts = (ColVtx*)D_800F2B7C[mdl].unk_6C->unk_78;
            func_8002AE24(mdl, &D_800EDEC0, func_80002060, &probe);
            for (tri = func_8002B3A8(&D_800EDEC0); tri != NULL; tri = func_8002B3A8(&D_800EDEC0)) {
                h = func_80029764(nx, y, nz, verts, tri);
                if (floorY < h) {
                    floorY = h;
                    ground = D_800B8954;
                }
                if (shadowY < h && shadowY < y + 35.0f) {
                    shadowY = h;
                    func_800295FC(&verts[tri->v[0]], &verts[tri->v[1]], &verts[tri->v[2]], &n);
                    normal = &n;
                }
            }
            if (floorY == -65536.0f) {
                floorY = -65536.0f;
            }
        }
    }
    h = func_800051D4(obj, nx + D_800ED6B8, y, nz + D_800F5254, &n2);
    if (floorY < h && h < y + 35.0f) {
        ground = D_800B8958;
        floorY = h;
    } else {
        if (h < y + 150.0f && y + 35.0f < h) {
            floorY = 65536.0f;
        }
        w->unk_53 = -1;
    }
    if (shadowY < h && h < y + 35.0f) {
        shadowY = h;
        normal = &n2;
    }
    if (y - 35.0f < floorY && floorY < y + 35.0f) {
        if ((s8)ground != -1) {
            w->unk_53 = ground;
        }
        y = func_800006E4(obj, floorY);
        if (((u8*)w)[(s8)ground] & 8) {
            func_80009438();
        }
        w->unk_38 = 1000.0f;
    } else {
        func_800184BC(obj, 6);
        w->unk_38 = D_800B899C;
        w->unk_53 = -1;
        func_80009624((unkGlobalStruct_00*)w, 13);
        return 65536.0f;
    }
    } else {
        probe.x = nx + D_800ED6B8;
        probe.y = y;
        probe.z = nz + D_800F5254;
        probe.w = w->unk_48;
        func_80004D1C(obj, &probe, 0);
    }
    if (obj->model[1] != 0) {
        if (shadowY != -65536.0f) {
            if (D_800B8959 == 1) {
                shadowY += 2.0f;
            }
            func_80025798(obj->model[1], nx, shadowY, nz);
            func_80037178(obj->model[1], normal);
            func_800258EC(obj->model[1], 4, 0);
        } else {
            func_800258EC(obj->model[1], 4, 4);
        }
    }
    if (w->unk_53 >= 0) {
        cur = D_800F2AF8[w->unk_53]->unk_50;
        w->unk_84 = normal->x * cur->unk_0C;
        w->unk_88 = normal->y;
        w->unk_8C = normal->z * cur->unk_0C;
        if (cur->unk_01 & 0x80) {
            func_800057F4(obj, normal);
        }
    } else {
        w->unk_90 = w->unk_98 = w->unk_84 = w->unk_88 = w->unk_8C = 0.0f;
        obj->rot.x = obj->rot.z = 0.0f;
    }
    return y;
}
void func_80003460(omObjData* obj, ColSphere* s) {
    s32 i = D_800B8956;
    GroundWork* g = obj->unk_50;
    f32 x0 = g->unk_18 + s->r;
    f32 z0 = g->unk_1C + s->r;
    f32 x1 = g->unk_20 - s->r;
    f32 z1 = g->unk_24 - s->r;
    f32 half;

    if (s->x <= x0) {
        D_800EDED0[D_800B8956].x = g->unk_18;
        D_800EDED4[D_800B8956].x = s->y;
        D_800EDED8[D_800B8956].x = s->z;
        D_800B8956++;
    }
    if (x1 <= s->x) {
        D_800EDED0[D_800B8956].x = g->unk_20;
        D_800EDED4[D_800B8956].x = s->y;
        D_800EDED8[D_800B8956].x = s->z;
        D_800B8956++;
    }
    if (s->z <= z0) {
        D_800EDED0[D_800B8956].x = s->x;
        D_800EDED4[D_800B8956].x = s->y;
        D_800EDED8[D_800B8956].x = g->unk_1C;
        D_800B8956++;
    }
    if (z1 <= s->z) {
        D_800EDED0[D_800B8956].x = s->x;
        D_800EDED4[D_800B8956].x = s->y;
        D_800EDED8[D_800B8956].x = g->unk_24;
        D_800B8956++;
    }
    if (i == D_800B8956) {
        half = s->r * 0.5f;
        if (s->x <= x0 - half) {
            D_800EDED0[D_800B8956].x = g->unk_18;
            D_800EDED4[D_800B8956].x = s->y;
            D_800EDED8[D_800B8956].x = s->z;
            D_800B8956++;
        }
        if (x1 + half <= s->x) {
            D_800EDED0[D_800B8956].x = g->unk_20;
            D_800EDED4[D_800B8956].x = s->y;
            D_800EDED8[D_800B8956].x = s->z;
            D_800B8956++;
        }
        if (s->z <= z0 - half) {
            D_800EDED0[D_800B8956].x = s->x;
            D_800EDED4[D_800B8956].x = s->y;
            D_800EDED8[D_800B8956].x = g->unk_1C;
            D_800B8956++;
        }
        if (z1 + half <= s->z) {
            D_800EDED0[D_800B8956].x = s->x;
            D_800EDED4[D_800B8956].x = s->y;
            D_800EDED8[D_800B8956].x = g->unk_24;
            D_800B8956++;
        }
    }
    for (; i < D_800B8956; i++) {
        x0 = D_800EDED0[i].x - s->x;
        z0 = D_800EDED8[i].x - s->z;
        func_800078E8(-x0, -z0, s->r - func_800B1750(x0 * x0 + z0 * z0));
        if (obj->trans.x != 0.0f || obj->trans.y != 0.0f || obj->trans.z != 0.0f || obj->rot.x != 0.0f ||
            obj->rot.y != 0.0f || obj->rot.z != 0.0f) {
            func_8000A464(D_800F2B80, &D_800EDED0[i]);
        }
    }
}
s32 func_8000396C(ColSphere* s, GroundWork* g) {
    f32 x = s->x;
    f32 z;
    f32 dx;
    ColSphere* t; // alias found by decomp-permuter; reproduces retail's registers
    f32 dz;
    f32 d;

    dx = g->unk_18;
    if (x <= dx) {
        dx -= x;
        z = s->z;
        dz = g->unk_1C;
        if (z <= dz) {
            dz -= z;
            d = func_800B1750(dx * dx + dz * dz) - s->r;
            if (d < 0.0f) {
                D_800EDED0[D_800B8956].x = g->unk_18;
                D_800EDED4[D_800B8956].x = s->y;
                D_800EDED8[D_800B8956].x = g->unk_1C;
                D_800B8956++;
                return 0;
            }
        } else if ((dz = g->unk_24) <= z) {
            dz -= z;
            d = func_800B1750(dx * dx + dz * dz) - s->r;
            if (d < 0.0f) {
                D_800EDED0[D_800B8956].x = g->unk_18;
                D_800EDED4[D_800B8956].x = s->y;
                D_800EDED8[D_800B8956].x = g->unk_24;
                D_800B8956++;
                return 0;
            }
        }
    } else if ((dx = g->unk_20) <= x) {
        dx -= x;
        t = s;
        z = t->z;
        dz = g->unk_1C;
        if (z <= dz) {
            dz -= z;
            d = func_800B1750(dx * dx + dz * dz) - t->r;
            if (d < 0.0f) {
                D_800EDED0[D_800B8956].x = g->unk_20;
                D_800EDED4[D_800B8956].x = t->y;
                D_800EDED8[D_800B8956].x = g->unk_1C;
                D_800B8956++;
                return 0;
            }
        } else if ((dz = g->unk_24) <= z) {
            dz -= z;
            d = func_800B1750(dx * dx + dz * dz) - t->r;
            if (d < 0.0f) {
                D_800EDED0[D_800B8956].x = g->unk_20;
                D_800EDED4[D_800B8956].x = t->y;
                D_800EDED8[D_800B8956].x = g->unk_24;
                D_800B8956++;
                return 0;
            }
        }
    }
    return 1;
}
void func_80003C08(omObjData* obj, ColSphere* s, f32 h) {
    s32 i = D_800B8956;
    GroundWork* g = obj->unk_50;
    f32 x = s->x;
    f32 z = s->z;
    f32 x0, z0, x1, z1;

    if (s->y < h + g->unk_10 && g->unk_10 - g->unk_14 < s->y) {
        x0 = g->unk_18 - s->r;
        z0 = g->unk_1C - s->r;
        x1 = g->unk_20 + s->r;
        z1 = g->unk_24 + s->r;
        if ((x0 <= x) & (x < x1)) {
            if ((z0 < z) & (z < z1)) {
                if (func_8000396C(s, g) == 1) {
                    if (x0 <= x && x <= g->unk_18) {
                        if (g->unk_1C <= s->z && s->z <= g->unk_24) {
                            if (g->unk_18 == s->x) {
                                D_800EDED0[D_800B8956].x = g->unk_18 + 1.0f;
                            } else {
                                D_800EDED0[D_800B8956].x = g->unk_18;
                            }
                            D_800EDED4[D_800B8956].x = s->y;
                            D_800EDED8[D_800B8956].x = s->z;
                            D_800B8956++;
                        }
                    } else if (x <= x1 && g->unk_20 <= x) {
                        if (g->unk_1C <= s->z && s->z <= g->unk_24) {
                            if (g->unk_20 == s->x) {
                                D_800EDED0[D_800B8956].x = g->unk_20 - 1.0f;
                            } else {
                                D_800EDED0[D_800B8956].x = g->unk_20;
                            }
                            D_800EDED4[D_800B8956].x = s->y;
                            D_800EDED8[D_800B8956].x = s->z;
                            D_800B8956++;
                        }
                    } else if (z0 <= z && z <= g->unk_1C) {
                        if (g->unk_18 <= s->x && s->x <= g->unk_20) {
                            D_800EDED0[D_800B8956].x = s->x;
                            D_800EDED4[D_800B8956].x = s->y;
                            if (g->unk_1C == s->z) {
                                D_800EDED8[D_800B8956].x = g->unk_1C + 1.0f;
                            } else {
                                D_800EDED8[D_800B8956].x = g->unk_1C;
                            }
                            D_800B8956++;
                        }
                    } else if (z <= z1 && g->unk_24 <= z) {
                        if (g->unk_18 <= s->x && s->x <= g->unk_20) {
                            D_800EDED0[D_800B8956].x = s->x;
                            D_800EDED4[D_800B8956].x = s->y;
                            if (g->unk_24 == s->z) {
                                D_800EDED8[D_800B8956].x = g->unk_24 - 1.0f;
                            } else {
                                D_800EDED8[D_800B8956].x = g->unk_24;
                            }
                            D_800B8956++;
                        }
                    }
                }
                for (; i < D_800B8956; i++) {
                    x0 = D_800EDED0[i].x - s->x;
                    z0 = D_800EDED8[i].x - s->z;
                    func_800078E8(x0, z0, func_800B1750(x0 * x0 + z0 * z0) - s->r);
                    if (obj->trans.x != 0.0f || obj->trans.y != 0.0f || obj->trans.z != 0.0f ||
                        obj->rot.x != 0.0f || obj->rot.y != 0.0f || obj->rot.z != 0.0f) {
                        func_8000A464(D_800F2B80, &D_800EDED0[i]);
                    }
                }
            }
        }
    }
}
void func_8000423C(omObjData* obj, ColSphere* s, f32 arg2) {
    PlayerWork* w;
    f32 speed;
    f32 sa, sb;
    f32 dx, dy, dz;
    f32 lim;
    f32 nx;
    s32 i;

    if (D_800B8956 == 0) {
        return;
    }
    w = obj->unk_50;
    if (w->unk_52 == 0) {
        sa = w->unk_40;
        sb = w->unk_A4;
        if (w->unk_50 & 6) {
            speed = sa * 0.6f * sb;
        } else {
            speed = sa * sb;
        }
    } else {
        speed = w->unk_40;
    }
    if (w->unk_38 != 1000.0f) {
        speed *= w->unk_4C;
    }
    for (i = 0; i < D_800B8956; i++) {
        dx = D_800EDED0[i].x - s->x;
        dy = D_800EDED4[i].x - s->y;
        dz = D_800EDED8[i].x - s->z;
        func_800B1750(dx * dx + dy * dy + dz * dz);
        nx = func_800AEAC0(w->unk_3C) * speed + D_800ED6B8;
        if (func_8000A72C(nx, func_800AEFD0(w->unk_3C) * speed + D_800F5254, dx, dz) > 0.9f &&
            w->unk_38 != 1000.0f && w->unk_40 > D_800B8984) {
            lim = w->unk_40;
            if (w->unk_50 & 6) {
                lim *= 0.6f;
            }
            lim *= w->unk_4C * w->unk_A4 * 0.98f;
            if (func_800B1750(D_800ED6B8 * D_800ED6B8 + D_800F5254 * D_800F5254) < lim) {
                if (w->unk_50 & 0x10) {
                    w->unk_40 = -D_800B8980;
                } else {
                    w->unk_40 = -D_800B898C;
                }
                func_800184BC(obj, 0x1E);
                func_80009624((unkGlobalStruct_00*)w, 7);
                func_80060F04(w->unk_58, 5, 0, 5);
                return;
            }
        }
        if (arg2 != 0.0f) {
            w->unk_40 = arg2;
            func_80009624((unkGlobalStruct_00*)w, 7);
            func_80060F04(w->unk_58, 2, 3, 10);
            return;
        }
    }
}
f32 func_80004578(omObjData* obj, f32 x, f32 y, f32 z, f32 unused) {
    Vec4f probe;
    Vec3f n;
    Vec3f n2;
    PlayerWork* w;
    GroundWork* gw;
    ColVtx* verts;
    ColTri* tri;
    s16 mdl;
    Vec3f* normal;
    f32 speed;
    f32 sa, sb, sc;
    f32 shadowY, floorY;
    f32 h;
    f32 nx, nz;
    f32 scale;

    w = obj->unk_50;
    w->unk_53 = w->unk_54 = -1;
    sa = w->unk_40;
    sb = w->unk_4C;
    sc = w->unk_A4;
    if (w->unk_50 & 6) {
        speed = sa * 0.6f * sb;
    } else {
        speed = sa * sb;
    }
    speed *= sc;
    nx = x + func_800AEAC0(w->unk_3C) * speed + D_800ED6B8;
    nz = z + func_800AEFD0(w->unk_3C) * speed + D_800F5254;
    floorY = shadowY = -65536.0f;
    if (func_80000F3C(obj, nx, y, nz) != 2) {
        func_80001F84(obj);
        sa = w->unk_40;
        sb = w->unk_4C;
        sc = w->unk_A4;
        if (w->unk_50 & 6) {
            speed = sa * 0.6f * sb;
        } else {
            speed = sa * sb;
        }
        speed *= sc;
        nx = x + func_800AEAC0(w->unk_3C) * speed;
        nz = z + func_800AEFD0(w->unk_3C) * speed;
        probe.x = nx;
        probe.y = y;
        probe.z = nz;
        probe.w = w->unk_48;
        func_80004D1C(obj, &probe, 0);
        func_80001F84(obj);
        probe.x = nx + D_800ED6B8;
        probe.y = y;
        probe.z = nz + D_800F5254;
        if (!(((u8*)w)[D_800B8954] & 1)) {
            gw = D_800F2AF8[D_800B8954]->unk_50;
            if (gw->unk_01 & 0x1A) {
                if (func_8000A910(&probe, gw) == 1) {
                    h = gw->unk_10;
                    if (floorY < h && h < y + 150.0f) {
                        floorY = h;
                        D_800B8958 = D_800B8954;
                        if (shadowY < floorY && shadowY < y + 35.0f) {
                            shadowY = floorY;
                            n.x = 0.0f;
                            n.y = 1.0f;
                            n.z = 0.0f;
                            normal = &n;
                        }
                    }
                }
            } else {
                mdl = *D_800F2AF8[D_800B8954]->model;
                verts = (ColVtx*)D_800F2B7C[mdl].unk_6C->unk_78;
                func_8002AE24(mdl, &D_800EDEC0, func_80002060, &probe);
                for (tri = func_8002B3A8(&D_800EDEC0); tri != NULL; tri = func_8002B3A8(&D_800EDEC0)) {
                    h = func_80029764(nx + D_800ED6B8, y, nz + D_800F5254, verts, tri);
                    if (floorY < h && h < y + 150.0f) {
                        floorY = h;
                        D_800B8958 = D_800B8954;
                    }
                    if (shadowY < h && shadowY < y + 35.0f) {
                        shadowY = h;
                        func_800295FC(&verts[tri->v[0]], &verts[tri->v[1]], &verts[tri->v[2]], &n);
                        normal = &n;
                    }
                }
                if (floorY == -65536.0f) {
                    floorY = -65536.0f;
                }
            }
        }
        h = func_800051D4(obj, nx + D_800ED6B8, y, nz + D_800F5254, &n2);
        if (floorY < h && h < y + 150.0f) {
            floorY = h;
        } else {
            w->unk_53 = -1;
        }
        if (shadowY < h && h < y + 150.0f) {
            shadowY = h;
            normal = &n2;
        }
        if (floorY == -65536.0f) {
            shadowY = -65536.0f;
            w->unk_4C = D_800B8998;
            if (w->unk_38 < 0.0f) {
                w->unk_38 = 0.0f;
            }
            w->unk_53 = -1;
        } else if (y < floorY) {
            w->unk_53 = D_800B8958;
            y = func_800006E4(obj, floorY);
            w->unk_38 = 1000.0f;
            w->unk_50 &= ~0x10;
            if (((u8*)w)[(s8)D_800B8958] & 8) {
                func_80009438();
            }
        } else {
            w->unk_53 = -1;
        }
    } else {
        probe.x = nx + D_800ED6B8;
        probe.y = y;
        probe.z = nz + D_800F5254;
        probe.w = w->unk_48;
        func_80004D1C(obj, &probe, 0);
    }
    if (obj->model[1] != 0) {
        if (shadowY != -65536.0f) {
            if (D_800B8959 == 1) {
                shadowY += 2.0f;
            }
            func_80025798(obj->model[1], nx, shadowY, nz);
            shadowY = y - shadowY;
            if (shadowY > 200.0f) {
                scale = 0.6f;
            } else {
                scale = 1.0 - fabs(shadowY) / 500.0;
            }
            func_80025830(obj->model[1], scale, scale, scale);
            func_80037178(obj->model[1], normal);
            func_800258EC(obj->model[1], 4, 0);
        } else {
            func_800258EC(obj->model[1], 4, 4);
        }
    }
    w->unk_90 = w->unk_98 = w->unk_84 = w->unk_88 = w->unk_8C = 0.0f;
    obj->rot.x = obj->rot.z = 0.0f;
    return y;
}
s32 func_80004D1C(omObjData* obj, Vec4f* p, f32 arg2) {
    Vec4f s;
    ColSphere s2;
    PlayerWork* w = obj->unk_50;
    omObjData* o;
    GroundWork* g;
    s16 prev;
    s16 i;

    s.x = p->x;
    s.y = w->unk_34 / 2.0f + p->y;
    s.z = p->z;
    s.w = p->w;
    D_800F3704 = -1;
    D_800B8956 = 0;
    prev = D_800B8956;
    if (!(((u8*)w)[D_800B8954] & 1)) {
        o = D_800F2AF8[D_800B8954];
        g = o->unk_50;
        if (g->unk_01 & 8) {
            s.x += D_800ED6B8;
            s.y += D_800F5254;
            func_80003460(o, (ColSphere*)&s);
        } else if (g->unk_01 & 0x10) {
            s.x += D_800ED6B8;
            s.y += D_800F5254;
            func_80003C08(o, (ColSphere*)&s, w->unk_34 / 2.0f);
        } else if (!(g->unk_01 & 2)) {
            func_8002AE24(*D_800F2AF8[D_800B8954]->model, &D_800EDEC0, func_80002080, &s);
        }
        if (prev != D_800B8956) {
            D_800F3704 = g->unk_05;
        }
    }
    for (i = 0; i < D_800ED440; i++) {
        o = D_800F2AF8[i];
        g = o->unk_50;
        if (i == D_800B8954 || (g->unk_01 & 2) || (((u8*)w)[i] & 1)) {
            continue;
        }
        prev = D_800B8956;
        s2.x = s2.x2 = p->x;
        s2.y = s2.y2 = w->unk_34 / 2.0f + p->y;
        s2.z = s2.z2 = p->z;
        s2.r = s.w = p->w;
        func_8000A1C0(D_800F2B80, D_800ED6E0, &s2, o);
        if ((g->unk_01 & 4) && func_8000A830(D_800F2B7C[*o->model].unk_6C->unk_80, &s2, w->unk_48) == 0) {
            continue;
        }
        if (g->unk_01 & 8) {
            s2.x += D_800ED6B8;
            s2.y += D_800F5254;
            func_80003460(o, &s2);
        } else if (g->unk_01 & 0x10) {
            s2.x += D_800ED6B8;
            s2.y += D_800F5254;
            func_80003C08(o, &s2, w->unk_34 / 2.0f);
        } else {
            func_8002AE24(*D_800F2AF8[i]->model, &D_800EDEC0, func_8000261C, &s2);
        }
        if (prev != D_800B8956) {
            D_800F3704 = g->unk_05;
        }
    }
    s.x = p->x + D_800ED6B8;
    s.y = w->unk_34 / 2.0f + p->y;
    s.z = p->z + D_800F5254;
    s.w = p->w;
    if (func_80009138(D_800F3704) == 1) {
        func_8000423C(obj, (ColSphere*)&s, arg2);
    }
    return D_800F3704;
}
f32 func_800051D4(omObjData* obj, f32 x, f32 y, f32 z, Vec3f* normal) {
    Vec4f s;
    Vec3f tmp;
    Vec3f dir;
    PlayerWork* w = obj->unk_50;
    omObjData* o;
    GroundWork* g;
    ColVtx* verts;
    ColTri* tri;
    unk_ovl_2D_struct* e;
    s16 mdl;
    s16 i;
    u8 xf;
    f32 best = -65536.0f;
    f32 h;

    s.w = 10.0f;
    w->unk_53 = -1;
    for (i = 0; i < D_800ED440; i++) {
        o = D_800F2AF8[i];
        g = o->unk_50;
        if (i == D_800B8954 || (((u8*)w)[i] & 1)) {
            continue;
        }
        s.x = x;
        s.y = y;
        s.z = z;
        func_8000A1C0(D_800F2B80, D_800ED6E0, (ColSphere*)&s, o);
        if ((g->unk_01 & 4) && func_8000A798(D_800F2B7C[*o->model].unk_6C->unk_80, (ColSphere*)&s) == 0) {
            continue;
        }
        if (g->unk_01 & 0x1A) {
            if ((g->unk_01 & 0x10) && func_8000A910(&s, g) == 0) {
                continue;
            }
            h = g->unk_10;
            if (o->trans.x != 0.0f || o->trans.y != 0.0f || o->trans.z != 0.0f || o->rot.x != 0.0f ||
                o->rot.y != 0.0f || o->rot.z != 0.0f) {
                s.y = h;
                func_8000A4F8(D_800F2B80, (ColSphere*)&s);
                if (best <= s.y && s.y < y + 150.0f) {
                    best = s.y;
                    w->unk_53 = D_800B8958 = i;
                    if (normal != NULL) {
                        tmp.x = 0.0f;
                        tmp.y = 1.0f;
                        tmp.z = 0.0f;
                        func_8000A3E8(D_800F2B80, &tmp);
                        normal->x = tmp.x;
                        normal->y = tmp.y;
                        normal->z = tmp.z;
                        func_8002956C(normal);
                    }
                }
            } else if (best <= h && h < y + 150.0f) {
                best = h;
                D_800B8958 = i;
                w->unk_53 = i;
                if (normal != NULL) {
                    normal->x = 0.0f;
                    normal->y = 1.0f;
                    normal->z = 0.0f;
                }
            }
        } else {
            mdl = *o->model;
            verts = (ColVtx*)D_800F2B7C[mdl].unk_6C->unk_78;
            func_8002AE24(mdl, &D_800EDEC0, func_80002060, &s);
            for (tri = func_8002B3A8(&D_800EDEC0); tri != NULL; tri = func_8002B3A8(&D_800EDEC0)) {
                e = &D_800F2B7C[mdl];
                xf = 0;
                if (e->unk_24 != 0.0f || e->unk_28 != 0.0f || e->unk_2C != 0.0f || e->unk_30 != 0.0f ||
                    e->unk_34 != 0.0f || e->unk_38 != 0.0f) {
                    tmp.x = x;
                    tmp.y = y + 10.0f;
                    tmp.z = z;
                    func_8000A464(D_800ED6E0, &tmp);
                    dir.x = tmp.x - s.x;
                    dir.y = tmp.y - s.y;
                    dir.z = tmp.z - s.z;
                    func_8002956C(&dir);
                    func_80000530(s.x, s.y, s.z, verts, tri, &dir, (Vec3f*)&s);
                    func_8000A4F8(D_800F2B80, (ColSphere*)&s);
                    h = s.y;
                    xf = 1;
                } else {
                    h = func_80029764(s.x, s.y, s.z, verts, tri);
                }
                if (best <= h && h < y + 150.0f) {
                    best = h;
                    D_800B8958 = i;
                    w->unk_53 = i;
                    if (normal != NULL) {
                        func_800295FC(&verts[tri->v[0]], &verts[tri->v[1]], &verts[tri->v[2]], normal);
                        if (xf == 1) {
                            tmp.x = normal->x;
                            tmp.y = normal->y;
                            tmp.z = normal->z;
                            func_8000A3E8(D_800F2B80, &tmp);
                            normal->x = tmp.x;
                            normal->y = tmp.y;
                            normal->z = tmp.z;
                            func_8002956C(normal);
                        }
                    }
                }
            }
        }
    }
    return best;
}
void func_800057F4(omObjData* obj, Vec3f* n) {
    PlayerWork* w = obj->unk_50;
    f32 rx, rz;
    f32 cx, cz;

    if (w->unk_40 > D_800B8984) {
        rx = -(func_800B0CD8(n->y, n->z) - 90.0f);
        rz = func_800B0CD8(n->y, n->x);
        cx = w->unk_90;
        cz = w->unk_98;
        rz -= 90.0f;
        if (cx < rx) {
            w->unk_90 += 4.0f;
            if (rx < w->unk_90) {
                w->unk_90 = rx;
            }
        } else if (rx < cx) {
            w->unk_90 -= 4.0f;
            if (w->unk_90 < rx) {
                w->unk_90 = rx;
            }
        }
        if (cz < rz) {
            w->unk_98 += 4.0f;
            if (rz < w->unk_98) {
                w->unk_98 = rz;
            }
        } else if (rz < cz) {
            w->unk_98 -= 4.0f;
            if (w->unk_98 < rz) {
                w->unk_98 = rz;
            }
        }
    } else {
        if (fabs(w->unk_90) > 2.0) {
            obj->rot.x = w->unk_90 = w->unk_90 * 0.3;
        }
        if (fabs(w->unk_98) > 2.0) {
            obj->rot.z = w->unk_98 = w->unk_98 * 0.3;
        }
    }
    obj->rot.x = w->unk_90;
    obj->rot.z = w->unk_98;
}
void func_80005A04(Object* arg0) {
    D_800CD9B0.x = arg0->unk_18.x;
    D_800CD9B0.y = arg0->unk_18.y;
    D_800CD9B0.z = arg0->unk_18.z;
}

// register allocation (masked 3): the cos*mag product takes $f12 instead of $f4
#ifdef NON_MATCHING
void func_80005A28(omObjData* obj) {
    s16 sx;
    s16 sy;
    PlayerWork* w = obj->unk_50;
    GroundWork* g;
    omObjData* o;
    u8 port = w->unk_56;
    f32 mag = 0.0f;
    f32 x = obj->trans.x;
    f32 y = obj->trans.y;
    f32 z = obj->trans.z;
    u16 mdl;
    f32 vy0;
    u16 btn;
    u16 trg;
    s32 flags;
    s32 ok;
    s32 anim;
    s32 r;
    s16 rx, ry;
    s32 r2;
    f32 dx, dy;
    f32 frame;
    f32 v;
    f32 ny;
    f32 vv1;
    f32 vv;
    f32 v1, ny1, v3, v5, frame5, frame2, frame6;
    omObjData* o7;
    f32 ang;
    f32 acc;
    f32 lim;
    f32 px;

    func_80005A04((Object*)obj);
    mdl = obj->model[0];
    vy0 = w->unk_38;
    D_800ED6B8 = D_800F5254 = mag;
    D_800F370C = 0;
    w->unk_55 = -1;
    D_800F3704 = -1;
    if (((D_800ED430 == 1) & ((s8)port >= 0)) && !(w->unk_50 & 1)) {
        sx = ContStkX[(s8)port];
        sy = ContStkY[(s8)port];
        if (sx > 60) {
            sx = 60;
        }
        if (sy > 60) {
            sy = 60;
        }
        if (sx < -60) {
            sx = -60;
        }
        if (sy < -60) {
            sy = -60;
        }
        func_80009D48(&sx, &sy);
        if (!(w->unk_50 & 6)) {
            trg = ContBtnTrg[(s8)port];
            btn = ContBtn[(s8)port];
        } else {
            btn = 0;
            trg = 0;
        }
    } else {
        sx = sy = 0;
        btn = 0;
        trg = 0;
    }
    flags = func_80017A60(obj);
    if (flags & 1) {
        ok = 1;
        if (w->unk_38 == 1000.0f) {
            if (func_80002C48(obj, w->unk_3C, x, y, z) != 65536.0f && (trg & 0x8000) &&
                func_800184BC(obj, 6) == 1) {
                w->unk_38 = -D_800B8964;
                func_80009624((unkGlobalStruct_00*)w, 3);
                ok = 0;
            }
        } else {
            v1 = w->unk_38;
            if (v1 > D_800B8994) {
                v1 = D_800B8994;
            }
            vv1 = v1 * v1;
            ny1 = y + vv1 * ((w->unk_38 >= 0.0f) ? -35.0f : 35.0f);
            w->unk_38 += D_800B8968;
            if (func_800184BC(obj, 6) == 1) {
                func_80009624((unkGlobalStruct_00*)w, 3);
                ok = 0;
            }
            y = func_80004578(obj, x, ny1, z, y);
            if (w->unk_38 == 1000.0f) {
                o = D_800F2AF8[w->unk_53];
                if (((GroundWork*)o->unk_50)->unk_04 == 2) {
                    func_800079A8(obj, x, o->trans.y, z);
                }
            }
        }
        if (ok == 1) {
            func_800184BC(obj, 0);
        }
        w->unk_B4 = 0;
    } else if (flags & 0x320) {
        frame2 = func_80025E70(mdl);
        if (frame2 == -1.0f) {
            frame2 = func_80025D18(mdl);
        }
        v = w->unk_38;
        if (!(flags & 0x300)) {
            if (((frame2 > 5.0f) & (frame2 < 7.0f)) && !(btn & 0x8000)) {
                if (!(w->unk_50 & 0x10) & (v < 0.0f)) {
                    w->unk_38 = -D_800B8964 * 0.2f;
                }
            }
            if (abs(sx) >= 9 || abs(sy) >= 9) {
                D_800ED6B8 = sx / D_800B896C * w->unk_A4;
                D_800F5254 = -(f32)sy / D_800B896C * w->unk_A4;
                mag = func_800B1750(D_800ED6B8 * D_800ED6B8 + D_800F5254 * D_800F5254);
                ang = func_800B0CD8(D_800ED6B8, D_800F5254) + w->unk_60;
                D_800ED6B8 = func_800AEAC0(ang) * mag;
                D_800F5254 = func_800AEFD0(ang) * mag;
                if (w->unk_50 & 0x10) {
                    D_800ED6B8 *= 0.2f;
                    D_800F5254 *= 0.2f;
                }
            }
            if (trg & 0x4000) {
                if (w->unk_50 & 0x20) {
                    if (func_800184BC(obj, 0x14) == 1) {
                        w->unk_38 = -D_800B8964 * 0.4f;
                        func_8000A6F4(obj);
                        func_80009624((unkGlobalStruct_00*)w, 12);
                    }
                } else if (func_800184BC(obj, 7) == 1) {
                    w->unk_38 = -D_800B8964 * 0.4f;
                    func_80009624((unkGlobalStruct_00*)w, 6);
                }
            }
            if ((trg & 0x2000) && !(w->unk_50 & 0x10) && func_800184BC(obj, 8) == 1) {
                w->unk_40 = D_800B8990;
                w->unk_38 = -D_800B8964 * 0.1f;
                if (w->unk_50 & 0x20) {
                    func_8000A534(obj, D_800B898C * 0.6f);
                }
                func_80009624((unkGlobalStruct_00*)w, 10);
            }
            if (v > D_800B8994) {
                v = D_800B8994;
            }
            ny = y + v * v * ((w->unk_38 >= 0.0f) ? -35.0f : 35.0f);
            w->unk_38 += D_800B8968;
        } else {
            if (v > D_800B8994) {
                v = D_800B8994;
            }
            if (frame2 > 26.0f) {
                ny = y + v * v * ((w->unk_38 >= 0.0f) ? -35.0f : 35.0f);
                w->unk_38 += D_800B8968 * 2.0f;
            } else if (flags & 0x100) {
                ny = y + v * v * ((w->unk_38 >= 0.0f) ? -35.0f : 35.0f);
                w->unk_38 += D_800B8968 / 2.0f;
            } else {
                ny = y;
            }
            if (flags & 0x100) {
                func_80007B34(obj, x, ny, z);
            }
        }
        y = func_80004578(obj, x, ny, z, y);
        if (w->unk_38 != 1000.0f) {
        } else {
            o = D_800F2AF8[w->unk_53];
            if (((GroundWork*)o->unk_50)->unk_04 == 2) {
                func_800079A8(obj, x, o->trans.y, z);
            } else if (flags & 0x200) {
                if (!(w->unk_50 & 0x80) && w->unk_AE == 0) {
                    w->unk_38 = -D_800B8964 * 0.6f;
                    func_80017C0C(obj, 7, x, y, z, 0.0f, 0.0f);
                    func_80017C0C(obj, 8, x, y, z, 0.0f, 0.0f);
                    w->unk_50 |= 0x80;
                    func_80009624((unkGlobalStruct_00*)w, 11);
                    func_80060F04(w->unk_58, 10, 0, 10);
                } else {
                    func_800184BC(obj, 0x12);
                    func_80017C0C(obj, 8, x, y, z, 0.0f, 0.0f);
                    w->unk_50 &= ~0x80;
                }
            } else if (abs(sx) < 8 && abs(sy) < 8) {
                w->unk_40 = D_800B8990;
                func_800184BC(obj, 0x15);
                func_80009624((unkGlobalStruct_00*)w, 4);
                func_80009E20(obj);
            } else {
                func_800184BC(obj, 1);
                w->unk_40 = D_800B8984;
                func_80009624((unkGlobalStruct_00*)w, 1);
            }
        }
        w->unk_B4 = 0;
    } else if (flags & 0x18C18) {
        if (flags & 0x10000) {
            if ((trg & 0x8000) && func_800184BC(obj, 6) == 1) {
                w->unk_38 = -D_800B8964;
                func_80009624((unkGlobalStruct_00*)w, 3);
            }
        } else if (w->unk_40 == D_800B8990) {
            if (flags & 0x400) {
                func_800184BC(obj, 0x21);
            } else if (flags & 0x10) {
                func_800184BC(obj, 0x12);
            } else if (flags & 0x800) {
                func_800184BC(obj, 0x22);
            } else if (flags & 8) {
                func_800184BC(obj, 0x13);
            } else {
                func_800184BC(obj, 0);
            }
        } else if (w->unk_40 < D_800B8990) {
            w->unk_40 += D_800B8960 * 2.0f;
            if (D_800B8990 <= w->unk_40) {
                w->unk_40 = D_800B8990;
            }
        } else if (D_800B8990 <= w->unk_40) {
            w->unk_40 += -D_800B8960 * 2.0f;
            if (w->unk_40 <= D_800B8990) {
                w->unk_40 = D_800B8990;
            }
        }
        v3 = w->unk_38;
        if (v3 == 1000.0f) {
            if (flags & 0x10) {
                if (w->unk_40 > D_800B8980) {
                    w->unk_3C += -(f32)sx / D_800B8970;
                } else {
                    lim = (w->unk_40 <= D_800B898C) ? D_800B898C : w->unk_40;
                    w->unk_3C += -(sx / D_800B8970) * (lim / D_800B8980);
                }
            }
            goto block_217;
        } else {
            if (v3 > D_800B8994) {
                v3 = D_800B8994;
            }
            vv = v3 * v3;
            ny = y + vv * ((w->unk_38 >= 0.0f) ? -35.0f : 35.0f);
            w->unk_38 += D_800B8968;
            y = func_80004578(obj, x, ny, z, y);
            if (w->unk_38 != 1000.0f) {
            } else {
                o = D_800F2AF8[w->unk_53];
                if (((GroundWork*)o->unk_50)->unk_04 == 2) {
                    func_800079A8(obj, x, o->trans.y, z);
                } else if (flags & 0x10) {
                    func_800184BC(obj, 0x12);
                } else if (flags & 8) {
                    func_800184BC(obj, 0x13);
                } else if (flags & 0xC00) {
                } else {
                    func_800184BC(obj, 0);
                }
            }
        }
        w->unk_B4 = 0;
    } else if (flags & 0x6000) {
        func_80009C90(obj, sx, sy);
        frame = func_80025E70(mdl);
        if (frame == -1.0f) {
            frame = func_80025D18(mdl);
        }
        if (flags & 0x4000) {
            w->unk_3C += 25.0f;
            if (frame >= 14.0f) {
                func_800184BC(obj, 1);
                w->unk_40 = D_800B8984;
                func_80009624((unkGlobalStruct_00*)w, 1);
                w->unk_50 &= ~8;
            }
        } else if (frame >= 10.0f) {
            if (abs(sx) >= 9 || abs(sy) >= 9) {
                if (func_8000A72C(sx, -sy, func_800AEAC0(w->unk_3C), func_800AEFD0(w->unk_3C)) < 0.0f) {
                    func_800184BC(obj, 0x20);
                }
            }
            if (frame >= 15.0f) {
                if (abs(sx) >= 9 || abs(sy) >= 9) {
                    func_800184BC(obj, 2);
                    w->unk_40 = D_800B8984;
                    func_80009624((unkGlobalStruct_00*)w, 1);
                } else {
                    func_800184BC(obj, 0);
                }
            }
        }
        if (w->unk_53 >= 0) {
            acc = ((GroundWork*)D_800F2AF8[w->unk_53]->unk_50)->unk_08;
        } else {
            acc = D_800B8960;
        }
        acc *= 2.0f;
        if (w->unk_40 < D_800B8990) {
            w->unk_40 = acc + w->unk_40;
            if (D_800B8990 <= w->unk_40) {
                w->unk_40 = D_800B8990;
            }
        } else if (D_800B8990 <= w->unk_40) {
            w->unk_40 = w->unk_40 - acc;
            if (w->unk_40 <= D_800B8990) {
                w->unk_40 = D_800B8990;
            }
        }
        ny = func_80002C48(obj, w->unk_3C, x, y, z);
        if (ny != 65536.0f) {
            y = ny;
            if (trg & 0x8000) {
                if (func_800184BC(obj, 6) != 1) {
                } else {
                    w->unk_38 = -D_800B8964;
                    w->unk_50 &= ~0x80;
                    func_80009624((unkGlobalStruct_00*)w, 3);
                }
            } else if (trg & 0x4000) {
                if (w->unk_50 & 0x20) {
                    if (func_800184BC(obj, 0x14) == 1) {
                        func_8000A6F4(obj);
                        func_80009624((unkGlobalStruct_00*)w, 12);
                    }
                } else if (func_800184BC(obj, 5) == 1) {
                    func_80009624((unkGlobalStruct_00*)w, 5);
                }
                func_80009E20(obj);
            }
        }
        w->unk_B4 = 0;
    } else if (flags & 0xC0) {
        if (flags & 0x80) {
            func_80007A50(obj);
        } else {
            func_80007B34(obj, x, y, z);
        }
        if (w->unk_38 == 1000.0f) {
            if (w->unk_40 < D_800B8990) {
                w->unk_40 += D_800B8960 * 2.0f;
                if (D_800B8990 < w->unk_40) {
                    w->unk_40 = D_800B8990;
                }
            } else if (D_800B8990 < w->unk_40) {
                w->unk_40 += -D_800B8960 * 2.0f;
                if (w->unk_40 < D_800B8990) {
                    w->unk_40 = D_800B8990;
                }
            }
        block_217:
            ny = func_80002C48(obj, w->unk_3C, x, y, z);
            if (ny != 65536.0f) {
                y = ny;
            }
        } else {
            v5 = w->unk_38;
            if (v5 > D_800B8994) {
                v5 = D_800B8994;
            }
            frame5 = func_80025E70(mdl);
            if (frame5 == -1.0f) {
                frame5 = func_80025D18(mdl);
            }
            ny = y + v5 * v5 * ((w->unk_38 >= 0.0f) ? -35.0f : 35.0f);
            if (frame5 > 30.0f) {
                w->unk_38 += D_800B8968 * 2.0f;
            } else {
                w->unk_38 += D_800B8968 / 2.0f;
            }
            y = func_80004578(obj, x, ny, z, y);
            if (w->unk_38 != 1000.0f) {
            } else {
                o = D_800F2AF8[w->unk_53];
                if (((GroundWork*)o->unk_50)->unk_04 == 2) {
                    func_800079A8(obj, x, o->trans.y, z);
                } else if (abs(sx) < 8 && abs(sy) < 8) {
                    w->unk_40 = D_800B8990;
                    func_800184BC(obj, 0x15);
                    func_80009624((unkGlobalStruct_00*)w, 4);
                } else {
                    func_800184BC(obj, 1);
                    w->unk_40 = D_800B8988;
                    func_80009624((unkGlobalStruct_00*)w, 1);
                }
            }
        }
        w->unk_B4 = 0;
    } else if (flags & 6) {
        r = func_80009C90(obj, sx, sy);
        rx = r >> 16;
        ry = r;
        mag = func_800B1750(rx * rx + ry * ry) / D_800B897C;
        w->unk_40 += mag / D_800B895C;
        if (w->unk_53 > 0) {
            g = D_800F2AF8[w->unk_53]->unk_50;
            if (sx | sy) {
                w->unk_40 = w->unk_40 - g->unk_08;
            } else {
                w->unk_40 = -g->unk_08 * 3.0f + w->unk_40;
            }
        } else if (sx | sy) {
            w->unk_40 = w->unk_40 - D_800B8960;
        } else {
            w->unk_40 = -D_800B8960 * 3.0f + w->unk_40;
        }
        mag = func_80007954(mag);
        if (w->unk_40 > mag) {
            w->unk_40 = mag;
        }
        if (w->unk_40 < D_800B8990) {
            w->unk_40 = D_800B8990;
        }
        if (abs(rx) >= 9 || abs(ry) >= 9) {
            w->unk_3C = func_800B0CD8(rx, -ry) + w->unk_60;
        }
        ny = func_80002C48(obj, w->unk_3C, x, y, z);
        if (ny != 65536.0f) {
            y = ny;
            if (!(func_80017A60(obj) & 0xC00)) {
                if (trg & 0x8000) {
                    if (func_800184BC(obj, 6) == 1) {
                        w->unk_38 = -D_800B8964;
                        w->unk_50 &= ~0x80;
                        func_80009624((unkGlobalStruct_00*)w, 3);
                    }
                } else if (trg & 0x4000) {
                    if (w->unk_50 & 0x20) {
                        if (func_800184BC(obj, 0x14) == 1) {
                            func_8000A6F4(obj);
                            func_80009624((unkGlobalStruct_00*)w, 12);
                        }
                    } else if (func_800184BC(obj, 5) == 1) {
                        func_80009624((unkGlobalStruct_00*)w, 5);
                    }
                } else if (dx = sx - rx, dy = sy - ry, func_800B1750(dx * dx + dy * dy) > 65.0f) {
                    if (fabs(w->unk_40) >= D_800B8984) {
                        if (func_800184BC(obj, 0x11) == 1) {
                            w->unk_50 |= 8;
                        } else {
                            func_800184BC(obj, 0x11);
                        }
                        w->unk_40 = D_800B8988;
                        func_80009624((unkGlobalStruct_00*)w, 2);
                        px = x + func_800AEAC0(w->unk_3C) * 70.0f;
                        func_80017C0C(obj, 4, px, y, z + func_800AEFD0(w->unk_3C) * 70.0f, 0.0f, w->unk_3C + 180.0f);
                    }
                } else if (func_800B1750(rx * rx + ry * ry) > 43.0f && abs(sx) < 8 && abs(sy) < 8) {
                    if (fabs(w->unk_40) >= D_800B8984) {
                        func_800184BC(obj, 0x11);
                        w->unk_40 = D_800B8988;
                        func_80009624((unkGlobalStruct_00*)w, 2);
                        px = x + func_800AEAC0(w->unk_3C) * 70.0f;
                        func_80017C0C(obj, 4, px, y, z + func_800AEFD0(w->unk_3C) * 70.0f, 0.0f, w->unk_3C + 180.0f);
                    }
                } else if (w->unk_40 == D_800B8990) {
                    w->unk_B4 = 0;
                    func_800184BC(obj, 0);
                    if (w->unk_B2 > 0) {
                        func_8006071C(w->unk_B3);
                        w->unk_B2 = -1;
                    }
                } else if (mag > D_800B8984) {
                    anim = 2;
                    r2 = func_80009E4C(w->unk_58, 12, sx, sy);
                    if ((s16)r2 > 0) {
                        w->unk_B4++;
                        if (w->unk_B4 >= 0) {
                            if (w->unk_B4 >= 13) {
                                w->unk_B4 = 12;
                                anim = 4;
                            }
                        }
                    } else if ((s16)r2 < 0) {
                        w->unk_B4--;
                        if (w->unk_B4 < 0) {
                            if (w->unk_B4 < -12) {
                                w->unk_B4 = -12;
                                anim = 3;
                            }
                        }
                    } else {
                        w->unk_B4 = 0;
                    }
                    if (func_800184BC(obj, anim) == 1) {
                        func_800096B0(w, 1);
                    } else {
                        frame6 = func_80025E70(mdl);
                        if (frame6 == -1.0f) {
                            frame6 = func_80025D18(mdl);
                        }
                        if (frame6 == 0.0f) {
                            func_800096B0(w, 1);
                        }
                    }
                    if (w->unk_AC < 60) {
                        px = x - func_800AEAC0(w->unk_3C) * 20.0f;
                        func_80017C0C(obj, 3, px, y, z - func_800AEFD0(w->unk_3C) * 20.0f, 0.0f, w->unk_3C);
                    }
                    w->unk_AC++;
                    if (w->unk_AC > 200) {
                        w->unk_AC = 200;
                    }
                    if (w->unk_84 > D_800B8988 || w->unk_8C > D_800B8988) {
                        px = x - func_800AEAC0(w->unk_3C) * 20.0f;
                        func_80017C0C(obj, 3, px, y, z - func_800AEFD0(w->unk_3C) * 20.0f, 0.0f, w->unk_3C);
                    }
                } else {
                    w->unk_B4 = 0;
                    if (func_800184BC(obj, 1) == 1) {
                        func_800096B0(w, 0);
                    } else {
                        frame6 = func_80025E70(mdl);
                        if (frame6 == -1.0f) {
                            frame6 = func_80025D18(mdl);
                        }
                        if (frame6 == 0.0f) {
                            func_800096B0(w, 0);
                        }
                    }
                    w->unk_AC = 0;
                }
            }
        }
    } else if (flags & 0x20000) {
        o7 = D_800F2AF8[w->unk_53];
        y -= 20.0f;
        if (y < o7->trans.y - 75.0f) {
            y = o7->trans.y - 75.0f;
        }
        if (w->unk_40 > D_800B8990) {
            w->unk_40 -= D_800B8960;
            if (w->unk_40 <= D_800B8990) {
                w->unk_40 = D_800B8990;
            }
        } else if (w->unk_40 < D_800B8990) {
            w->unk_40 += D_800B8960;
            if (D_800B8990 <= w->unk_40) {
                w->unk_40 = D_800B8990;
            }
        }
        if (obj->model[2] != 0) {
            func_80025798(obj->model[2], x, o7->trans.y - 64.0f, z);
            func_80025830(obj->model[2], 6.0f, 6.0f, 6.0f);
        }
    }
    mag = w->unk_40;
    if (w->unk_50 & 6) {
        mag *= 0.6f;
    }
    mag *= (vy0 != 1000.0f) ? w->unk_4C * w->unk_A4 : w->unk_A4;
    x += func_800AEAC0(w->unk_3C) * mag + D_800ED6B8;
    z += func_800AEFD0(w->unk_3C) * mag + D_800F5254;
    func_8009ECB0(&D_800F2B7C[obj->model[0]].unk7C, 0.0f, w->unk_3C, 0.0f);
    func_800093FC(obj, x, y, z);
    func_80017DB0(obj);
    func_8001802C(obj);
}
#else
INCLUDE_ASM("asm/nonmatchings/1130", func_80005A28);
#endif
void func_800078E8(f32 dx, f32 dz, f32 d) {
    Vec3f v;

    v.x = dx;
    v.y = 0.0f;
    v.z = dz;
    func_8002956C(&v);
    D_800ED6B8 += d * v.x;
    D_800F5254 += d * v.z;
}
f32 func_80007954(f32 arg0) {
    if (arg0 < D_800B898C)
        return D_800B898C;

    if (!(arg0 < D_800B8988)) {
        if (!(arg0 < D_800B8984)) {
            return arg0;
        } else {
            return D_800B8984;
        }
    } else {
        return D_800B8988;
    }
}

void func_800079A8(omObjData* arg0, f32 arg1, f32 arg2, f32 arg3) {
    u8 temp_s0;
    unkGlobalStruct_00* temp_s2;

    temp_s2 = arg0->unk_50;
    func_800184BC(arg0, 0x10);
    temp_s0 = temp_s2->unk_20.b[3];
    func_8001E3B4(temp_s0);
    func_8001E268(temp_s0, 4, 4);
    func_80025798(arg0->model[2], arg1, arg2, arg3);
    temp_s2->unk_40 = D_800B8990;
    func_80009438();
}

void func_80007A50(omObjData* arg0) {
    unkGlobalStruct_00* temp_s1 = arg0->unk_50;
    f32 var_f2 = func_80025E70(arg0->model[0]);
    s32 var_v0, var_v1;

    if (var_f2 == -1.0f) {
        var_f2 = func_80025D18(arg0->model[0]);
    }
    
    var_v0 = !(var_f2 >= 28.0f) ? 0 : 1;
    var_v1 = !(var_f2 <= 29.0f) ? 0 : 1;
    
    if (var_v0 & var_v1) {
        func_8000A534(arg0, (temp_s1->unk_40 + D_800B8988) * temp_s1->unk_BC);
    }
}

void func_80007B34(omObjData* obj, f32 x, f32 y, f32 z) {
    Vec4f v;
    PlayerWork* w = obj->unk_50;
    PlayerWork* ow;
    omObjData* o;
    f32 frame;
    f32 rot;
    f32 len;
    f32 nx, ny, nz;
    f32 dx, dy, dz;
    f32 a;
    u16 i;

    frame = func_80025E70(*obj->model);
    if (frame == -1.0f) {
        frame = func_80025D18(*obj->model);
    }
    if ((frame < 16.0f) | (frame > 20.0f)) {
        return;
    }
    if (w->unk_AE != 0) {
        D_800F370C++;
        return;
    }
    len = w->unk_64 + w->unk_48;
    rot = w->unk_3C;
    nx = x + func_800AEAC0(rot) * len;
    ny = y;
    nz = z + func_800AEFD0(rot) * len;
    w->unk_E0 = 1;
    for (i = 0; i < D_800F2BC0; i++) {
        o = D_800F3FB0[i];
        ow = o->unk_50;
        if (!(ow->unk_5C & 0x8C00) && !(ow->unk_50 & 7) && ow->unk_AE == 0) {
            if (w == ow) {
                continue;
            }
            dx = o->trans.x - nx;
            dy = o->trans.y - ny;
            dz = o->trans.z - nz;
            if (func_800B1750(dx * dx + dy * dy + dz * dz) < ow->unk_48 + 30.0f) {
                if (!(ow->unk_50 & 0x200)) {
                    a = func_8000A72C(func_800AEAC0(ow->unk_3C), func_800AEFD0(ow->unk_3C), dx, dz);
                    if (ow->unk_50 & 0x20) {
                        func_8000A534(o, D_800B8988);
                    }
                    if (a < 0.0f) {
                        func_800184BC(o, 0x1E);
                        if (ow->unk_38 == 1000.0f) {
                            ow->unk_40 = -D_800B8980;
                        } else {
                            ow->unk_40 = -D_800B8980;
                            ow->unk_38 = -D_800B8964 * 0.6f;
                        }
                        ow->unk_3C = func_80029518(w->unk_3C + 180.0f);
                    } else {
                        func_800184BC(o, 0x1F);
                        if (ow->unk_38 == 1000.0f) {
                            ow->unk_40 = D_800B8980;
                        } else {
                            ow->unk_40 = D_800B8980;
                            ow->unk_38 = -D_800B8964 * 0.6f;
                        }
                        ow->unk_3C = w->unk_3C;
                    }
                    func_80017C0C(obj, 6, o->trans.x, o->trans.y, o->trans.z, 0.0f, func_800B0CD8(dx, dz) + 180.0f);
                    func_80009624((unkGlobalStruct_00*)w, 8);
                    func_80060F04(w->unk_58, 2, 3, 10);
                    func_80060F04(ow->unk_58, 2, 2, 20);
                }
                w->unk_54 = i;
                ow->unk_B1 = w->unk_58;
            }
        }
    }
    if (!(w->unk_50 & 0x27)) {
        for (i = 0; i < D_800EE984; i++) {
            o = D_800EDE70[i];
            ow = o->unk_50;
            if (!(ow->unk_50 & 0x40)) {
                continue;
            }
            if (!(ow->unk_50 & 0x20)) {
                if (w->unk_AE != 0) {
                    D_800F370C++;
                } else {
                    dx = o->trans.x - nx;
                    dy = o->trans.y - ny;
                    dz = o->trans.z - nz;
                    len = func_800B1750(dx * dx + dy * dy + dz * dz) - (ow->unk_48 + w->unk_48);
                    if (len < 0.0f && (w->unk_DC == NULL || w->unk_DC(obj, o) != 1)) {
                        func_8000A634(obj, o);
                    }
                }
            }
        }
    }
    v.x = func_800AEAC0(rot) * w->unk_48 + obj->trans.x;
    v.y = ny;
    v.z = func_800AEFD0(rot) * w->unk_48 + obj->trans.z;
    v.w = w->unk_64;
    w->unk_55 = func_80004D1C(obj, &v, -D_800B8980);
    if (D_800B8956 != 0 && func_80009138(D_800F3704) == 1) {
        a = func_800B0CD8(D_800EDED0[0].x - obj->trans.x, D_800EDED0[0].z - obj->trans.z);
        func_80017C0C(obj, 6, nx, ny, nz, 0.0f, a + 180.0f);
    }
    D_800B8956 = 0;
    D_800ED6B8 = D_800F5254 = 0.0f;
}
void func_800081C0(omObjData* obj, s32 port) {
    PlayerWork* w;
    s32 i;

    if (port != 0) {
        return;
    }
    if (ContBtn[port] & 0x10) {
        CZoom -= 20.0f;
    }
    if (ContBtn[port] & 0x20) {
        CZoom += 20.0f;
    }
    if (ContBtn[port] & 8) {
        CRot.x += 0.3f;
    }
    if (ContBtn[port] & 4) {
        CRot.x -= 0.3f;
    }
    if (ContBtn[port] & 1) {
        CRot.y += 1.0f;
    }
    if (ContBtn[port] & 2) {
        CRot.y -= 1.0f;
    }
    if (ContBtnTrg[port] & 0x800) {
        D_800B89A0--;
    } else if (ContBtnTrg[port] & 0x400) {
        D_800B89A0++;
    }
    if (D_800B89A0 < 0) {
        D_800B89A0 = 0;
    }
    if (D_800B89A0 > 0) {
        D_800B89A0 = 0;
    }
    switch (D_800B89A0) {
        case 0:
            if (ContBtnTrg[port] & 0x300) {
                if (D_800B895B != 0) {
                    D_800B895B = 0;
                } else {
                    D_800B895B = 1;
                }
            }
            break;
        case 2:
            if (ContBtn[port] & 0x100) {
                D_800B895C += 0.1f;
            }
            if (ContBtn[port] & 0x200) {
                D_800B895C -= 0.1f;
            }
            if (D_800B895C > 50.0f) {
                D_800B895C = 50.0f;
            }
            if (D_800B895C < 1.0f) {
                D_800B895C = 1.0f;
            }
            break;
        case 3:
            if (ContBtn[port] & 0x100) {
                D_800B8960 += 0.001f;
            }
            if (ContBtn[port] & 0x200) {
                D_800B8960 -= 0.001f;
            }
            if (D_800B8960 > 0.999f) {
                D_800B8960 = 0.999f;
            }
            if (D_800B8960 < 0.001f) {
                D_800B8960 = 0.001f;
            }
            break;
        case 4:
            if (ContBtn[port] & 0x100) {
                D_800B8964 += 0.01f;
            }
            if (ContBtn[port] & 0x200) {
                D_800B8964 -= 0.01f;
            }
            if (D_800B8964 > 2.0f) {
                D_800B8964 = 2.0f;
            }
            if (D_800B8964 < 0.7f) {
                D_800B8964 = 0.7f;
            }
            break;
        case 5:
            if (ContBtn[port] & 0x100) {
                D_800B8968 += 0.001f;
            }
            if (ContBtn[port] & 0x200) {
                D_800B8968 -= 0.001f;
            }
            if (D_800B8968 > 0.2f) {
                D_800B8968 = 0.2f;
            }
            if (D_800B8968 < 0.01f) {
                D_800B8968 = 0.01f;
            }
            break;
        case 6:
            if (ContBtn[port] & 0x100) {
                D_800B896C += 0.1f;
            }
            if (ContBtn[port] & 0x200) {
                D_800B896C -= 0.1f;
            }
            if (D_800B896C > 30.0f) {
                D_800B896C = 30.0f;
            }
            if (D_800B896C < 0.0f) {
                D_800B896C = 0.0f;
            }
            break;
        case 7:
            if (ContBtn[port] & 0x100) {
                D_800B8970 += 0.1f;
            }
            if (ContBtn[port] & 0x200) {
                D_800B8970 -= 0.1f;
            }
            if (D_800B8970 > 100.0f) {
                D_800B8970 = 100.0f;
            }
            if (D_800B8970 < 20.0f) {
                D_800B8970 = 20.0f;
            }
            break;
        case 8:
            if (ContBtn[port] & 0x100) {
                D_800B8980 += 0.1f;
            }
            if (ContBtn[port] & 0x200) {
                D_800B8980 -= 0.1f;
            }
            if (D_800B8980 > 30.0f) {
                D_800B8980 = 30.0f;
            }
            if (D_800B8980 < 10.0f) {
                D_800B8980 = 10.0f;
            }
            D_800B898C = D_800B8980 / 4.0f;
            D_800B8988 = D_800B8980 / 2.0f;
            D_800B8984 = D_800B898C * 3.0f;
            D_800B897C = 60.0f / D_800B8980;
            break;
        case 9:
            if (ContBtn[port] & 0x100) {
                D_800B8974 += 0.1f;
            }
            if (ContBtn[port] & 0x200) {
                D_800B8974 -= 0.1f;
            }
            if (D_800B8974 > 100.0f) {
                D_800B8974 = 100.0f;
            }
            if (D_800B8974 < 40.0f) {
                D_800B8974 = 40.0f;
            }
            for (i = 0; i < D_800F2BC0; i++) {
                w = D_800F3FB0[i]->unk_50;
                w->unk_48 = D_800B8974;
            }
            break;
        case 10:
            if (ContBtn[port] & 0x100) {
                D_800B8978 += 0.1f;
            }
            if (ContBtn[port] & 0x200) {
                D_800B8978 -= 0.1f;
            }
            if (D_800B8978 > 100.0f) {
                D_800B8978 = 100.0f;
            }
            if (D_800B8978 < 10.0f) {
                D_800B8978 = 40.0f;
            }
            for (i = 0; i < D_800F2BC0; i++) {
                w = D_800F3FB0[i]->unk_50;
                w->unk_64 = D_800B8978;
            }
            break;
    }
    fontcolor = 15;
    sprintf(pfStrBuf, "*");
    print8(16, (D_800B89A0 + 2) * 8, ((s32)pfStrBuf));
    sprintf(pfStrBuf, "CAMERA :[%s]", D_800B895B ? "HOMING" : "LOCK");
    print8(24, 16, ((s32)pfStrBuf));
    if (D_800B895B != 0) {
        Center.x = obj->trans.x;
        Center.y = obj->trans.y;
        Center.z = obj->trans.z - 300.0f;
        /* retail bug: w is only set by the loops in cases 9 and 10 */
        w->unk_60 = CRot.y;
    }
}