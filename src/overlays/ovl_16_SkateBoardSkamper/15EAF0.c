#include "SkateBoardSkamper.h"

/* Collision vertex and triangle of a course model (src/1130.c's view). */
typedef struct SbsColVtx {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 z;
} SbsColVtx;

typedef struct SbsColTri {
    /* 0x0 */ s16 flags;
    /* 0x2 */ s16 v[3];
} SbsColTri;

/* ---------------------------------------------------------------------------------------------
   .data
   --------------------------------------------------------------------------------------------- */

u32 D_800FDA00_SkateBoardSkamper = 0;
s16 D_800FDA04_SkateBoardSkamper = -1;
u8 D_800FDA08_SkateBoardSkamper[4] = { 0, 0, 0, 0 };
u8 D_800FDA0C_SkateBoardSkamper = 0;
u8 D_800FDA0D_SkateBoardSkamper = 4;
u8 D_800FDA0E_SkateBoardSkamper = 0;
s8 D_800FDA0F_SkateBoardSkamper = -1;
f32 D_800FDA10_SkateBoardSkamper = 9500.0f;
f32 D_800FDA14_SkateBoardSkamper[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
f32 D_800FDA24_SkateBoardSkamper[4] = { 8500.0f, 2200.0f, -4100.0f, 0.0f };
f32 D_800FDA34_SkateBoardSkamper[4] = { 7500.0f, 1200.0f, -5100.0f, 0.0f };
f32 D_800FDA44_SkateBoardSkamper[4] = { 6500.0f, 50.0f, -6100.0f, 0.0f };
f32 D_800FDA54_SkateBoardSkamper[4] = { 5350.0f, -950.0f, -7100.0f, 0.0f };
f32 D_800FDA64_SkateBoardSkamper[4] = { 4350.0f, -2100.0f, -8100.0f, 0.0f };
f32 D_800FDA74_SkateBoardSkamper[4] = { 3200.0f, -3100.0f, -9100.0f, 0.0f };
f32 D_800FDA84_SkateBoardSkamper[4] = { 5200.0f, 1550.0f, -3100.0f, -5100.0f };
f32 D_800FDA94_SkateBoardSkamper[3] = { 4200.0f, -2100.0f, -4100.0f };
f32 D_800FDAA0_SkateBoardSkamper[4] = { 5925.0f, 3775.0f, 625.0f, -1525.0f };
s32 D_800FDAB0_SkateBoardSkamper[4] = { 0, 0, 0, 0 };
f32 D_800FDAC0_SkateBoardSkamper[4] = { 4.0f, 4.6f, 5.0f, 6.0f };
f32 D_800FDAD0_SkateBoardSkamper[4] = { -0.04f, -0.03f, -0.025f, -0.02f };
Vec D_800FDAE0_SkateBoardSkamper = { 0.0f, 0.0f, 0.0f };
s32 D_800FDAEC_SkateBoardSkamper = 0;
f32 D_800FDAF0_SkateBoardSkamper = 0.0f;
f32 D_800FDAF4_SkateBoardSkamper = 0.0f;
f32 D_800FDAF8_SkateBoardSkamper = 0.0f;
u32 D_800FDAFC_SkateBoardSkamper = 3600;
u32 D_800FDB00_SkateBoardSkamper = 0;
s32 D_800FDB04_SkateBoardSkamper = 0;
u8 D_800FDB08_SkateBoardSkamper = 0;
/* ---------------------------------------------------------------------------------------------
   .text
   --------------------------------------------------------------------------------------------- */

void func_800F65E0_SkateBoardSkamper(void) {
    func_80029090(50);
    func_8002ADF0(&D_800EDEC0, 64);
    func_8001DE70(32);
    omInitObjMan(50, 0);
    func_80060088();
    func_8000942C();
    func_800178A0(1);
    ((s16 (*)(s32))func_800178E8)(1); /* retail passes a stray 1 */
    func_80017660(0, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 20.0f, 80.0f, 8000.0f);
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    func_8002578C(1);
    func_80009500();
    D_800B8998 = 1.0f;
    D_800B8980 = 24.0f;
    D_800B898C = 6.0f;
    D_800B8988 = 12.0f;
    D_800B8984 = 18.0f;
    func_80009618(0);
    func_800090B8(D_800ED440);
    D_800F2AF8[D_800ED440++] = omAddObj(200, 1, 0, -1, func_800F8158_SkateBoardSkamper);
    D_800F2AF8[D_800ED440++] = omAddObj(200, 1, 0, -1, func_800F83C4_SkateBoardSkamper);
    D_800F2AF8[D_800ED440++] = omAddObj(200, 1, 0, -1, func_800F849C_SkateBoardSkamper);
    D_800F2AF8[D_800ED440++] = omAddObj(200, 4, 0, -1, func_800F8CF8_SkateBoardSkamper);
    D_800F2AF8[D_800ED440++] = omAddObj(200, 4, 0, -1, func_800F8EE8_SkateBoardSkamper);
    D_800F2AF8[D_800ED440++] = omAddObj(200, 4, 0, -1, func_800F90D8_SkateBoardSkamper);
    D_800F2AF8[D_800ED440++] = omAddObj(200, 1, 0, -1, func_800F85AC_SkateBoardSkamper);
    D_800F2AF8[D_800ED440++] = omAddObj(200, 1, 0, -1, func_800F86F4_SkateBoardSkamper);
    D_800F2AF8[D_800ED440++] = omAddObj(200, 1, 0, -1, func_800F8828_SkateBoardSkamper);
    D_800F2AF8[D_800ED440++] = omAddObj(200, 1, 0, -1, func_800F895C_SkateBoardSkamper);
    D_800F2AF8[D_800ED440++] = omAddObj(200, 1, 0, -1, func_800F8A90_SkateBoardSkamper);
    D_800F2AF8[D_800ED440++] = omAddObj(200, 1, 0, -1, func_800F8BC4_SkateBoardSkamper);
    D_800EDE70[D_800EE984++] = omAddObj(400, 4, 0, -1, func_800F9CB8_SkateBoardSkamper);
    D_800EDE70[D_800EE984++] = omAddObj(400, 4, 0, -1, func_800F9CF8_SkateBoardSkamper);
    D_800EDE70[D_800EE984++] = omAddObj(400, 4, 0, -1, func_800F9D3C_SkateBoardSkamper);
    D_800EDE70[D_800EE984++] = omAddObj(400, 4, 0, -1, func_800F9D80_SkateBoardSkamper);
    D_800F3FB0[D_800F2BC0++] = omAddObj(300, 11, 60, -1, func_800F95B0_SkateBoardSkamper);
    D_800F3FB0[D_800F2BC0++] = omAddObj(300, 11, 60, -1, func_800F9708_SkateBoardSkamper);
    D_800F3FB0[D_800F2BC0++] = omAddObj(300, 11, 60, -1, func_800F9864_SkateBoardSkamper);
    D_800F3FB0[D_800F2BC0++] = omAddObj(300, 11, 60, -1, func_800F99C0_SkateBoardSkamper);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_800F6CE4_SkateBoardSkamper), 0xA0);
    func_80028BE0(5);
    func_8007B168((u8*)"\x82\x71\x82\x64\x82\x60\x82\x63\x82\x78\x82\x66\x82\x6E\x82\x76\x82\x6B\x81\x49", 1);
}

/* The camera (omOutView with the up vector tilted while the camera rolls). */
void func_800F6CE4_SkateBoardSkamper(omObjData* obj) {
    Vec3f eye;
    Vec3f at;
    Vec3f up;
    f32 rx = CRot.x;
    f32 ry = CRot.y;
    f32 a;

    eye.x = Center.x + func_800AEAC0(ry) * func_800AEFD0(rx) * CZoom;
    eye.y = -func_800AEAC0(rx) * CZoom + Center.y;
    eye.z = func_800AEFD0(ry) * func_800AEFD0(rx) * CZoom + Center.z;
    at.x = Center.x;
    at.y = Center.y;
    at.z = Center.z;
    if (CRot.x == 325.0f) {
        up.x = 0.0f;
        up.y = 1.0f;
    } else {
        a = 55.0 - fabs(270.0f - CRot.x);
        up.x = func_800AEAC0(a);
        up.y = func_800AEFD0(a);
    }
    up.z = 0.0f;
    D_800EE738[1] = eye.x;
    D_800EE738[2] = eye.z;
    D_800EE738[0] = CRot.y;
    D_800EE738[3] = D_800C3110->unk_40;
    D_800EE738[4] = 20000.0f;
    D_800EE738[5] = 10000.0f;
    func_8001D420(0, &eye, &at, &up);
    func_8001D57C(0);
}

/* The game object after the results: keeps the stage animating until the fade ends. */
void func_800F6EC8_SkateBoardSkamper(omObjData* obj) {
    if (func_80072718() != 0) {
        func_800F71B8_SkateBoardSkamper(obj);
        func_800F7758_SkateBoardSkamper(obj);
        obj->trans.z = Center.z;
        return;
    }
    omOvlReturnEx(1);
}

/* Messages and sounds of each game state (state = D_800ED430's low byte, t = its frame count). */
void func_800F6F1C_SkateBoardSkamper(omObjData* obj, u8 state, u32 t) {
    switch (state) {
        case 0:
            if (t == 0) {
                PlaySound(0x27B);
                func_80060214(0x7F);
                func_800603F0(0x7F);
            }
            if (t == 100) {
                GMesCreate(13);
            }
            break;
        case 1:
            break;
        case 2:
            if (_CheckFlag(0x2B) != 0) {
                if (t == 0) {
                    if (D_800FDA0F_SkateBoardSkamper >= 0) {
                        GwPlayer[D_800FDA0F_SkateBoardSkamper].coins_mg += 10;
                    }
                    GMesCreate(2);
                } else if ((GMesStatAllGet() == 0 || (GMesStatAllGet() & 2)) && t > 80) {
                    func_80009448();
                }
            } else if (t == 0) {
                if (D_800FDA0D_SkateBoardSkamper == 0) {
                    GMesCreate(17);
                } else {
                    GMesCreate(18);
                }
            } else if (D_800FDAEC_SkateBoardSkamper == 0) {
                if (D_800FDA0F_SkateBoardSkamper >= 0) {
                    if (GMesStatAllGet() == 0 || (GMesStatAllGet() & 2)) {
                        func_80060128(0x32);
                        D_800FDAEC_SkateBoardSkamper = 1;
                    }
                } else if (GMesStatAllGet() == 0 || (GMesStatAllGet() & 2)) {
                    func_80060128(0x34);
                    D_800FDAEC_SkateBoardSkamper = 1;
                }
            } else {
                if (D_800FDA0F_SkateBoardSkamper >= 0) {
                    if (D_800FDAEC_SkateBoardSkamper >= 25) {
                        GwPlayer[D_800FDA0F_SkateBoardSkamper].coins_mg += 10;
                        GMesCreate(4, GwPlayer[D_800FDA0F_SkateBoardSkamper].character);
                        func_80060540(D_800FDD22_SkateBoardSkamper[D_800FDA0F_SkateBoardSkamper], D_800FDA0F_SkateBoardSkamper);
                        func_80009448();
                    }
                } else if (D_800FDAEC_SkateBoardSkamper >= 91) {
                    func_80009448();
                }
                D_800FDAEC_SkateBoardSkamper++;
            }
            break;
    }
}

/* Camera moves of each state, and the stage's texture scroll (model light "00m_037"). */
void func_800F71B8_SkateBoardSkamper(omObjData* obj) {
    if ((func_8005FD5C() & 0xFFFF) + D_800F64F8 == 0) {
        D_800FDAF0_SkateBoardSkamper += 0.2f;
        D_800FDAF4_SkateBoardSkamper -= (Center.z - obj->trans.z) * ((s16)D_800FDD1C_SkateBoardSkamper[1] / 800.0f);
        switch (D_800ED430) {
            case 0:
                if (D_800FDA00_SkateBoardSkamper > 20) {
                    if (D_800FDA00_SkateBoardSkamper == 50) {
                        func_80060128(0x21);
                    } else if (D_800FDA00_SkateBoardSkamper > 50) {
                        if ((CRot.y -= CRot.y * 0.002) < 135.0f) {
                            CRot.y = 135.0f;
                        }
                        if ((Center.x -= 5.0f) < 0.0f) {
                            Center.x = 0.0f;
                        }
                        if ((Center.y -= Center.y * 0.01f) < 350.0f) {
                            Center.y = 350.0f;
                        }
                        if ((Center.z += 2.0f) > 9500.0f) {
                            Center.z = 9500.0f;
                        }
                        if ((CZoom += CZoom * 0.02f) > 2400.0f) {
                            CZoom = 2400.0f;
                        }
                    } else {
                        if ((Center.x += 10.0f) > 225.0f) {
                            Center.x = 225.0f;
                        }
                        if ((CRot.y -= CRot.y * 0.001) < 135.0f) {
                            CRot.y = 135.0f;
                        }
                    }
                }
                break;
            case 1:
                if (Center.z > -5100.0f) {
                    if ((CRot.y = (Center.z - 7000.0f) / 2500.0f * 45.0f + 90.0f) > 135.0f) {
                        CRot.y = 135.0f;
                    }
                    if (CRot.y < 45.0f) {
                        CRot.y = 45.0f;
                    }
                } else if ((CRot.y -= 0.22f) < 0.0f) {
                    CRot.y = 0.0f;
                }
                break;
            case 2:
                if (D_800FDA0D_SkateBoardSkamper != 0 && D_800FDA0E_SkateBoardSkamper == 0) {
                    if ((CRot.x -= CRot.x * 0.01) < 215.0f) {
                        CRot.x = 215.0f;
                    }
                    if (D_800FDAE0_SkateBoardSkamper.x < 0.0f) {
                        if ((Center.x -= 5.0f) < D_800FDAE0_SkateBoardSkamper.x) {
                            Center.x = D_800FDAE0_SkateBoardSkamper.x;
                        }
                    } else if ((Center.x += 5.0f) > D_800FDAE0_SkateBoardSkamper.x) {
                        Center.x = D_800FDAE0_SkateBoardSkamper.x;
                    }
                    if ((CZoom -= CZoom * 0.01) < 1600.0f) {
                        CZoom = 1600.0f;
                    }
                }
                break;
        }
    }
    func_80027E48(obj->model[0], D_800FDAF0_SkateBoardSkamper, D_800FDAF4_SkateBoardSkamper,
                  D_800FDD1C_SkateBoardSkamper[0], D_800FDD1C_SkateBoardSkamper[1], "00m_037", 1);
}

/* Ripples on the course model's vertex colours and heights around (+-1000, z). */
// register allocation (masked 25): retail hoists 28.0f into a saved register, this C hoists 255.0f
#ifdef NON_MATCHING
void func_800F7758_SkateBoardSkamper(omObjData* obj) {
    unk2C0C0StructC0* m = D_800F2B7C[obj->model[0]].unk_6C;
    unk2C0C0StructB0* b;
    unk2C0C0StructE0* dst;
    unk2C0C0StructE0* src;
    s32 i;
    s32 j;
    s16 idx;
    f32 x;
    f32 z;
    f32 dx;
    f32 dz;
    f32 h;

    for (i = 0; i < m->unk_74; i++) {
        b = &m->unk_D0[i];
        for (j = 0; j < b->unk_00; j++) {
            idx = b->unk_02[j];
            dst = &m->unk_08[D_800F37F0][idx];
            src = &m->unk_04[idx];
            x = src->unk_00;
            z = src->unk_04;
            if (func_800B1750(x * x + z * z) < 500.0f) {
                dx = x - 1000.0f;
                dz = z + obj->trans.z;
                h = func_800AEAC0((D_800FDAF8_SkateBoardSkamper / 0.4 - func_800B1750(dx * dx + dz * dz) / 28.0f) * 6.283185307179586) * 128.0f;
                dx = x + 1000.0f;
                dz = z + obj->trans.z - 2000.0f;
                h += func_800AEAC0((D_800FDAF8_SkateBoardSkamper / 0.4 - func_800B1750(dx * dx + dz * dz) / 28.0f) * 6.283185307179586) * 128.0f;
                h *= 0.5f;
            } else {
                h = 0.0f;
            }
            dst->unk_02 = h;
            if (h > 0.0) {
                h = 256.0f - h;
                dst->unk_0C.r = h;
                dst->unk_0C.g = 0xA0;
                dst->unk_0C.b = 0xA0;
            } else {
                h = 176.0f - h;
                if (h > 255.0f) {
                    h = 255.0f;
                }
                dst->unk_0C.r = 0xFF;
                dst->unk_0C.g = h;
                dst->unk_0C.b = h;
            }
        }
    }
    if ((func_8005FD5C() & 0xFFFF) + D_800F64F8 == 0) {
        D_800FDAF8_SkateBoardSkamper += 0.1f;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_16_SkateBoardSkamper/15EAF0", func_800F7758_SkateBoardSkamper);
#endif

/* 1 when no earlier rank already holds player. */
s32 func_800F7B7C_SkateBoardSkamper(s32 n, s32 player) {
    s32 i;

    for (i = 0; i < n; i++) {
        if (D_800FDAB0_SkateBoardSkamper[i] == player) {
            return 0;
        }
    }
    return 1;
}

/* The player's rank (0 leads). */
// if-conversion (masked 9): GCC turns the last rank test into xor/sltu/negu (retail branches), and retail's frame is 0x18
#ifdef NON_MATCHING
s32 func_800F7BC4_SkateBoardSkamper(s32 player) {
    s32 rank;

    if (player == D_800FDAB0_SkateBoardSkamper[0]) {
        rank = 0;
    } else if (player == D_800FDAB0_SkateBoardSkamper[1]) {
        rank = 1;
    } else if (player == D_800FDAB0_SkateBoardSkamper[2]) {
        rank = 2;
    } else {
        rank = 3;
    }
    return rank;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_16_SkateBoardSkamper/15EAF0", func_800F7BC4_SkateBoardSkamper);
#endif

/* Ranks the players by z (smallest first). */
void func_800F7C08_SkateBoardSkamper(void) {
    omObjData* obj;
    SbsPlayerWork* w;
    s32 i;
    s32 j;
    f32 best;
    f32 prev;

    D_800FDAB0_SkateBoardSkamper[0] = D_800FDAB0_SkateBoardSkamper[1] = D_800FDAB0_SkateBoardSkamper[2] =
        D_800FDAB0_SkateBoardSkamper[3] = -1;
    prev = -10000.0f;
    for (i = 0; i < 4; i++) {
        best = 10000.0f;
        for (j = 0; j < D_800F2BC0; j++) {
            obj = D_800F3FB0[j];
            w = obj->unk_50;
            if (obj->trans.z < best && prev <= obj->trans.z) {
                if (func_800F7B7C_SkateBoardSkamper(i, w->unk_58) == 1) {
                    best = obj->trans.z;
                    D_800FDAB0_SkateBoardSkamper[i] = w->unk_58;
                }
            }
        }
        prev = best;
    }
}

/* The game object: state 0 intro, 1 race, 2 results, 3 wait for the last message. */
void func_800F7D50_SkateBoardSkamper(omObjData* obj) {
    omObjData* o;
    s32 i;

    func_80009468();
    switch (D_800ED430) {
        case 0:
            if (func_80072718() != 0) {
                return;
            }
            if (D_800FDA00_SkateBoardSkamper > 140) {
                func_80028BE0(3);
                func_80009458();
            }
            func_800F6F1C_SkateBoardSkamper(obj, D_800ED430, D_800FDA00_SkateBoardSkamper);
            if ((func_8005FD5C() & 0xFFFF) + D_800F64F8 == 0) {
                D_800FDA00_SkateBoardSkamper++;
            }
            break;
        case 1:
            func_800F6F1C_SkateBoardSkamper(obj, D_800ED430, D_800FDAFC_SkateBoardSkamper);
            if (D_800FDA08_SkateBoardSkamper[0] != 0 && D_800FDA08_SkateBoardSkamper[1] != 0 &&
                D_800FDA08_SkateBoardSkamper[2] != 0 && D_800FDA08_SkateBoardSkamper[3] != 0) {
                func_80009438();
            }
            if (_CheckFlag(0x2B) != 0 && D_800FDA08_SkateBoardSkamper[0] != 0) {
                func_80009438();
                D_800FDA0E_SkateBoardSkamper = 1;
            }
            if (D_800FDB08_SkateBoardSkamper == 0 && D_800FDA0F_SkateBoardSkamper >= 0 &&
                D_800FDA0C_SkateBoardSkamper != 0) {
                for (i = 0; i < D_800F2BC0; i++) {
                    o = D_800F3FB0[i];
                    if (D_800FDAE0_SkateBoardSkamper.z > o->trans.z) {
                        D_800FDA0F_SkateBoardSkamper = i;
                        D_800FDAE0_SkateBoardSkamper.x = o->trans.x;
                        D_800FDAE0_SkateBoardSkamper.y = o->trans.y;
                        D_800FDAE0_SkateBoardSkamper.z = o->trans.z;
                    }
                }
                D_800FDB08_SkateBoardSkamper = 1;
                func_80009438();
            }
            func_800F7C08_SkateBoardSkamper();
            if ((func_8005FD5C() & 0xFFFF) + D_800F64F8 == 0) {
                D_800FDA10_SkateBoardSkamper -= 20.0f;
            }
            if (D_800FDA10_SkateBoardSkamper < -10000.0f) {
                D_800FDA10_SkateBoardSkamper = -10000.0f;
            }
            Center.z = D_800FDA10_SkateBoardSkamper;
            break;
        case 2:
            if (D_800FDB00_SkateBoardSkamper == 0) {
                func_80028BE0(5);
                func_800601D4(40);
                func_8006071C(D_800FDA04_SkateBoardSkamper);
            }
            func_800F6F1C_SkateBoardSkamper(obj, D_800ED430, D_800FDB00_SkateBoardSkamper);
            if ((D_800FDB00_SkateBoardSkamper += 2) > 450) {
                D_800FDB00_SkateBoardSkamper = 450;
            }
            if ((func_8005FD5C() & 0xFFFF) + D_800F64F8 == 0 && D_800FDA0D_SkateBoardSkamper != 0 &&
                D_800FDA0E_SkateBoardSkamper == 0) {
                D_800FDA10_SkateBoardSkamper -= 20.0f;
            }
            if (D_800FDA10_SkateBoardSkamper < -10000.0f) {
                D_800FDA10_SkateBoardSkamper = -10000.0f;
            }
            Center.z = D_800FDA10_SkateBoardSkamper;
            break;
        case 3:
            if (GMesWait() != 1) {
                func_800726AC(0, 20);
                obj->func_ptr = func_800F6EC8_SkateBoardSkamper;
            }
            func_800F6F1C_SkateBoardSkamper(obj, D_800ED430, D_800FDB00_SkateBoardSkamper);
            D_800FDB04_SkateBoardSkamper += 2;
            if ((func_8005FD5C() & 0xFFFF) + D_800F64F8 == 0 && D_800FDA0D_SkateBoardSkamper != 0 &&
                D_800FDA0E_SkateBoardSkamper == 0) {
                D_800FDA10_SkateBoardSkamper -= 20.0f;
            }
            if (D_800FDA10_SkateBoardSkamper < -10000.0f) {
                D_800FDA10_SkateBoardSkamper = -10000.0f;
            }
            Center.z = D_800FDA10_SkateBoardSkamper;
            break;
    }
    func_800F71B8_SkateBoardSkamper(obj);
    func_800F7758_SkateBoardSkamper(obj);
    obj->trans.z = Center.z;
    if (D_800F5144 == 1) {
        omOvlReturnEx(1);
        func_800601D4(40);
        func_8006073C();
    }
}

/* The course (D_800F2AF8 slot 0) and the game object; loads the dust models. */
void func_800F8158_SkateBoardSkamper(omObjData* obj) {
    SbsFloorWork* w;

    obj->model[0] = func_800174C0(0x280007, 0x20889);
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    w = func_80023684(sizeof(SbsFloorWork), 0x7918);
    obj->unk_50 = w;
    func_8009B770(w, 0, sizeof(SbsFloorWork));
    obj->func_ptr = func_800F7D50_SkateBoardSkamper;
    w->unk_04 = 1;
    func_80009000(obj, 2, 0.0f);
    func_80008FB8(obj, 0.6f);
    func_80008FC4(obj, 25.0f);
    w->unk_05 = 0;
    SetFadeInTypeAndTime(0, 16);
    Center.x = -225.0f;
    Center.y = 525.0f;
    Center.z = 9400.0f;
    CRot.x = 325.0f;
    CRot.y = 150.0f;
    CRot.z = 0.0f;
    CZoom = 1000.0f;
    obj->trans.x = -600.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 9500.0f;
    func_80039C48("00mt037_DEF", D_800FDD1C_SkateBoardSkamper);
    func_80025930(obj->model[0], 0x20000, 0x20000);
    func_80025AD4(obj->model[0]);
    func_80026040(obj->model[0]);
    omSetStatBit(obj, 0xA0);
    D_800FDD10_SkateBoardSkamper = func_800174C0(0x280001, 0x899);
    D_800FDD12_SkateBoardSkamper = func_800174C0(0x280001, 0x899);
    D_800FDD14_SkateBoardSkamper = func_800174C0(0x280001, 0x899);
    D_800FDD16_SkateBoardSkamper = func_800174C0(0x280002, 0x899);
    D_800FDD18_SkateBoardSkamper = func_800174C0(0x280002, 0x899);
    D_800FDD1A_SkateBoardSkamper = func_800174C0(0x280002, 0x899);
    D_800FDD20_SkateBoardSkamper = LoadFormFile(0x280006, 0x20A8D);
}

/* The start ramp (slot 1). */
void func_800F83C4_SkateBoardSkamper(omObjData* obj) {
    SbsFloorWork* w;

    obj->model[0] = func_800174C0(0x280004, 0x20499);
    obj->trans.x = 0.0f;
    obj->trans.y = 300.0f;
    obj->trans.z = 9600.0f;
    w = func_80023684(sizeof(SbsFloorWork), 0x7918);
    obj->unk_50 = w;
    func_8009B770(w, 0, sizeof(SbsFloorWork));
    obj->func_ptr = func_800FA2B8_SkateBoardSkamper;
    w->unk_04 = 1;
    func_800090A4(obj);
    func_80008FB8(obj, 0.3f);
    func_8000941C(obj, 1.0f, 1.0f, 1.0f);
    w->unk_05 = 1;
}

/* The goal (slot 2). */
void func_800F849C_SkateBoardSkamper(omObjData* obj) {
    SbsFloorWork* w;

    obj->model[0] = func_800174C0(0x280005, 0x2049D);
    obj->trans.x = 0.0f;
    obj->trans.y = 300.0f;
    obj->trans.z = -10000.0f;
    w = func_80023684(sizeof(SbsFloorWork), 0x7918);
    obj->unk_50 = w;
    func_8009B770(w, 0, sizeof(SbsFloorWork));
    obj->func_ptr = func_800FA3B4_SkateBoardSkamper;
    w->unk_04 = 1;
    func_80009058(obj, 0.0f, 300.0f, -300.0f, -900.0f, 300.0f, 400.0f);
    func_80008FB8(obj, 0.3f);
    func_8000941C(obj, 1.0f, 1.0f, 1.0f);
    w->unk_05 = 2;
}

/* The six course tiles (slots 6-11); only the first moves at the start. */
void func_800F85AC_SkateBoardSkamper(omObjData* obj) {
    SbsFloorWork* w;

    obj->model[0] = func_800174C0(0x280000, 0x20889);
    obj->trans.x = 0.0f;
    obj->trans.y = 300.0f;
    obj->trans.z = D_800FDA24_SkateBoardSkamper[0];
    w = func_80023684(sizeof(SbsFloorWork), 0x7918);
    obj->unk_50 = w;
    func_8009B770(w, 0, sizeof(SbsFloorWork));
    obj->func_ptr = func_800F9DC4_SkateBoardSkamper;
    w->unk_04 = 1;
    func_80009058(obj, 0.0f, 100.0f, -300.0f, -500.0f, 300.0f, 500.0f);
    func_80008FB8(obj, 0.3f);
    func_8000941C(obj, 1.0f, 1.0f, 1.0f);
    func_80008FC4(obj, 25.0f);
    w->unk_05 = 6;
    func_80025930(obj->model[0], 0x20000, 0x20000);
    func_80025AD4(obj->model[0]);
    func_80026040(obj->model[0]);
    omSetStatBit(obj, 0xA0);
}

void func_800F86F4_SkateBoardSkamper(omObjData* obj) {
    SbsFloorWork* w;

    obj->model[0] = func_800174C0(0x280000, 0x20889);
    obj->trans.x = 0.0f;
    obj->trans.y = 300.0f;
    obj->trans.z = D_800FDA34_SkateBoardSkamper[0];
    w = func_80023684(sizeof(SbsFloorWork), 0x7918);
    obj->unk_50 = w;
    func_8009B770(w, 0, sizeof(SbsFloorWork));
    obj->func_ptr = NULL;
    w->unk_04 = 1;
    func_80009058(obj, 0.0f, 100.0f, -300.0f, -500.0f, 300.0f, 500.0f);
    func_80008FB8(obj, 0.3f);
    func_8000941C(obj, 1.0f, 1.0f, 1.0f);
    w->unk_05 = 7;
    func_80025930(obj->model[0], 0x20000, 0x20000);
    func_80025AD4(obj->model[0]);
    func_80026040(obj->model[0]);
    omSetStatBit(obj, 0xA0);
}

void func_800F8828_SkateBoardSkamper(omObjData* obj) {
    SbsFloorWork* w;

    obj->model[0] = func_800174C0(0x280000, 0x20889);
    obj->trans.x = 0.0f;
    obj->trans.y = 300.0f;
    obj->trans.z = D_800FDA44_SkateBoardSkamper[0];
    w = func_80023684(sizeof(SbsFloorWork), 0x7918);
    obj->unk_50 = w;
    func_8009B770(w, 0, sizeof(SbsFloorWork));
    obj->func_ptr = NULL;
    w->unk_04 = 1;
    func_80009058(obj, 0.0f, 100.0f, -300.0f, -500.0f, 300.0f, 500.0f);
    func_80008FB8(obj, 0.3f);
    func_8000941C(obj, 1.0f, 1.0f, 1.0f);
    w->unk_05 = 8;
    func_80025930(obj->model[0], 0x20000, 0x20000);
    func_80025AD4(obj->model[0]);
    func_80026040(obj->model[0]);
    omSetStatBit(obj, 0xA0);
}

void func_800F895C_SkateBoardSkamper(omObjData* obj) {
    SbsFloorWork* w;

    obj->model[0] = func_800174C0(0x280000, 0x20889);
    obj->trans.x = 0.0f;
    obj->trans.y = 300.0f;
    obj->trans.z = D_800FDA54_SkateBoardSkamper[0];
    w = func_80023684(sizeof(SbsFloorWork), 0x7918);
    obj->unk_50 = w;
    func_8009B770(w, 0, sizeof(SbsFloorWork));
    obj->func_ptr = NULL;
    w->unk_04 = 1;
    func_80009058(obj, 0.0f, 100.0f, -300.0f, -500.0f, 300.0f, 500.0f);
    func_80008FB8(obj, 0.3f);
    func_8000941C(obj, 1.0f, 1.0f, 1.0f);
    w->unk_05 = 9;
    func_80025930(obj->model[0], 0x20000, 0x20000);
    func_80025AD4(obj->model[0]);
    func_80026040(obj->model[0]);
    omSetStatBit(obj, 0xA0);
}

void func_800F8A90_SkateBoardSkamper(omObjData* obj) {
    SbsFloorWork* w;

    obj->model[0] = func_800174C0(0x280000, 0x20889);
    obj->trans.x = 0.0f;
    obj->trans.y = 300.0f;
    obj->trans.z = D_800FDA64_SkateBoardSkamper[0];
    w = func_80023684(sizeof(SbsFloorWork), 0x7918);
    obj->unk_50 = w;
    func_8009B770(w, 0, sizeof(SbsFloorWork));
    obj->func_ptr = NULL;
    w->unk_04 = 1;
    func_80009058(obj, 0.0f, 100.0f, -300.0f, -500.0f, 300.0f, 500.0f);
    func_80008FB8(obj, 0.3f);
    func_8000941C(obj, 1.0f, 1.0f, 1.0f);
    w->unk_05 = 10;
    func_80025930(obj->model[0], 0x20000, 0x20000);
    func_80025AD4(obj->model[0]);
    func_80026040(obj->model[0]);
    omSetStatBit(obj, 0xA0);
}

void func_800F8BC4_SkateBoardSkamper(omObjData* obj) {
    SbsFloorWork* w;

    obj->model[0] = func_800174C0(0x280000, 0x20889);
    obj->trans.x = 0.0f;
    obj->trans.y = 300.0f;
    obj->trans.z = D_800FDA74_SkateBoardSkamper[0];
    w = func_80023684(sizeof(SbsFloorWork), 0x7918);
    obj->unk_50 = w;
    func_8009B770(w, 0, sizeof(SbsFloorWork));
    obj->func_ptr = NULL;
    w->unk_04 = 1;
    func_80009058(obj, 0.0f, 100.0f, -300.0f, -500.0f, 300.0f, 500.0f);
    func_80008FB8(obj, 0.3f);
    func_8000941C(obj, 1.0f, 1.0f, 1.0f);
    w->unk_05 = 11;
    func_80025930(obj->model[0], 0x20000, 0x20000);
    func_80025AD4(obj->model[0]);
    func_80026040(obj->model[0]);
    omSetStatBit(obj, 0xA0);
}

/* The three rows of falling logs (slots 3-5), four models each. */
void func_800F8CF8_SkateBoardSkamper(omObjData* obj) {
    SbsFloorWork* w;

    obj->model[0] = func_800174C0(0x280008, 0x20899);
    obj->model[1] = func_800174C0(0x280008, 0x20899);
    obj->model[2] = func_800174C0(0x280008, 0x20899);
    obj->model[3] = func_800174C0(0x280008, 0x20899);
    obj->trans.x = 225.0f;
    obj->trans.y = 300.0f;
    obj->trans.z = D_800FDA84_SkateBoardSkamper[0];
    w = func_80023684(sizeof(SbsFloorWork), 0x7918);
    obj->unk_50 = w;
    func_8009B770(w, 0, sizeof(SbsFloorWork));
    obj->func_ptr = func_800FA498_SkateBoardSkamper;
    w->unk_04 = 1;
    func_80009058(obj, 150.0f, 200.0f, -500.0f, -100.0f, 500.0f, 100.0f);
    func_80008FB8(obj, 0.3f);
    func_8000941C(obj, 1.0f, 1.0f, 1.0f);
    func_80008FC4(obj, 25.0f);
    w->unk_05 = 3;
    func_80025798(obj->model[1], obj->trans.x - 150.0f, obj->trans.y, obj->trans.z);
    func_80025798(obj->model[2], obj->trans.x - 300.0f, obj->trans.y, obj->trans.z);
    func_80025798(obj->model[3], obj->trans.x - 450.0f, obj->trans.y, obj->trans.z);
}

void func_800F8EE8_SkateBoardSkamper(omObjData* obj) {
    SbsFloorWork* w;

    obj->model[0] = func_800174C0(0x280008, 0x20899);
    obj->model[1] = func_800174C0(0x280008, 0x20899);
    obj->model[2] = func_800174C0(0x280008, 0x20899);
    obj->model[3] = func_800174C0(0x280008, 0x20899);
    obj->trans.x = 225.0f;
    obj->trans.y = 300.0f;
    obj->trans.z = D_800FDA94_SkateBoardSkamper[0];
    w = func_80023684(sizeof(SbsFloorWork), 0x7918);
    obj->unk_50 = w;
    func_8009B770(w, 0, sizeof(SbsFloorWork));
    obj->func_ptr = func_800FAC0C_SkateBoardSkamper;
    w->unk_04 = 1;
    func_80009058(obj, 150.0f, 200.0f, -500.0f, -100.0f, 500.0f, 100.0f);
    func_80008FB8(obj, 0.3f);
    func_8000941C(obj, 1.0f, 1.0f, 1.0f);
    func_80008FC4(obj, 25.0f);
    w->unk_05 = 4;
    func_80025798(obj->model[1], obj->trans.x - 150.0f, obj->trans.y, obj->trans.z);
    func_80025798(obj->model[2], obj->trans.x - 300.0f, obj->trans.y, obj->trans.z);
    func_80025798(obj->model[3], obj->trans.x - 450.0f, obj->trans.y, obj->trans.z);
}

void func_800F90D8_SkateBoardSkamper(omObjData* obj) {
    SbsFloorWork* w;

    obj->model[0] = func_800174C0(0x280008, 0x20899);
    obj->model[1] = func_800174C0(0x280008, 0x20899);
    obj->model[2] = func_800174C0(0x280008, 0x20899);
    obj->model[3] = func_800174C0(0x280008, 0x20899);
    obj->trans.x = 225.0f;
    obj->trans.y = 200.0f;
    obj->trans.z = D_800FDAA0_SkateBoardSkamper[0];
    w = func_80023684(sizeof(SbsFloorWork), 0x7918);
    obj->unk_50 = w;
    func_8009B770(w, 0, sizeof(SbsFloorWork));
    obj->func_ptr = func_800FB380_SkateBoardSkamper;
    w->unk_04 = 1;
    func_80009058(obj, 150.0f, 200.0f, -500.0f, -100.0f, 500.0f, 100.0f);
    func_80008FB8(obj, 0.3f);
    func_8000941C(obj, 1.0f, 1.0f, 1.0f);
    func_80008FC4(obj, 25.0f);
    w->unk_05 = 5;
    func_80025798(obj->model[1], obj->trans.x - 150.0f, obj->trans.y, obj->trans.z);
    func_80025798(obj->model[2], obj->trans.x - 300.0f, obj->trans.y, obj->trans.z);
    func_80025798(obj->model[3], obj->trans.x - 450.0f, obj->trans.y, obj->trans.z);
}

/* .data from here on is defined between the functions so that the table's strings land in
   .rodata where retail has them. */
char* D_800FDB0C_SkateBoardSkamper[6] = {
    "27mt003_DEF", "27mt004_DEF", "27mt005_DEF", "27mt006_DEF", "27mt007_DEF", "27mt008_DEF",
};
s32 D_800FDB24_SkateBoardSkamper = 10;
s32 D_800FDB28_SkateBoardSkamper = 1;
s32 D_800FDB2C_SkateBoardSkamper = 0;
u8 D_800FDB30_SkateBoardSkamper[4] = { 1, 1, 0, 0 };
/* func_800FA498's log row: fall speeds, heights, tilts, next position. */
f32 D_800FDB34_SkateBoardSkamper = 0.0f;
f32 D_800FDB38_SkateBoardSkamper = 0.0f;
f32 D_800FDB3C_SkateBoardSkamper = 0.0f;
f32 D_800FDB40_SkateBoardSkamper = 0.0f;
f32 D_800FDB44_SkateBoardSkamper = 300.0f;
f32 D_800FDB48_SkateBoardSkamper = 300.0f;
f32 D_800FDB4C_SkateBoardSkamper = 300.0f;
f32 D_800FDB50_SkateBoardSkamper = 0.0f;
f32 D_800FDB54_SkateBoardSkamper = 0.0f;
f32 D_800FDB58_SkateBoardSkamper = 0.0f;
s32 D_800FDB5C_SkateBoardSkamper = 1;
/* func_800FAC0C's. */
f32 D_800FDB60_SkateBoardSkamper = 0.0f;
f32 D_800FDB64_SkateBoardSkamper = 0.0f;
f32 D_800FDB68_SkateBoardSkamper = 0.0f;
f32 D_800FDB6C_SkateBoardSkamper = 0.0f;
f32 D_800FDB70_SkateBoardSkamper = 300.0f;
f32 D_800FDB74_SkateBoardSkamper = 300.0f;
f32 D_800FDB78_SkateBoardSkamper = 300.0f;
f32 D_800FDB7C_SkateBoardSkamper = 0.0f;
f32 D_800FDB80_SkateBoardSkamper = 0.0f;
f32 D_800FDB84_SkateBoardSkamper = 0.0f;
s32 D_800FDB88_SkateBoardSkamper = 1;
/* func_800FB380's (splat read 200.0f's bytes as the strings "CH"). */
f32 D_800FDB8C_SkateBoardSkamper = 0.0f;
f32 D_800FDB90_SkateBoardSkamper = 0.0f;
f32 D_800FDB94_SkateBoardSkamper = 0.0f;
f32 D_800FDB98_SkateBoardSkamper = 0.0f;
f32 D_800FDB9C_SkateBoardSkamper = 200.0f;
f32 D_800FDBA0_SkateBoardSkamper = 200.0f;
f32 D_800FDBA4_SkateBoardSkamper = 200.0f;
f32 D_800FDBA8_SkateBoardSkamper = 0.0f;
f32 D_800FDBAC_SkateBoardSkamper = 0.0f;
f32 D_800FDBB0_SkateBoardSkamper = 0.0f;
s32 D_800FDBB4_SkateBoardSkamper = 1;

/* Sets up a player: motions, the skateboard (model 9) and the character's voice. */
void func_800F92D0_SkateBoardSkamper(omObjData* obj, s32 dir, s32 file, s32 arg3, u16 player, f32 x, f32 y, f32 z) {
    SbsPlayerWork* w;
    s32 idle;
    s32 win;
    s32 i;

    func_8000979C(obj, dir, file, player, 0x20A99, 0x20A99);
    w = obj->unk_50;
    obj->model[9] = LoadFormFile(0x280003, 0xA89);
    func_80008EF0(obj, 10, dir | arg3, 0x20AD9, 1700.0f);
    idle = 0x38;
    if (rand8() >= 0x80) {
        idle = 0xF;
    }
    win = (rand8() < 0x80) ? 0x3C : 0x10;
    func_800187D0(obj, 0, dir | 0x4A, 1, 0);
    func_800187D0(obj, 1, dir | 0x4B, 2, 0);
    func_800187D0(obj, 6, dir | 0x4C, 1, 24);
    func_800187D0(obj, 13, dir | idle, 1, 120);
    func_800187D0(obj, 14, dir | win, 1, 120);
    func_800187D0(obj, 16, dir | 0x49, 1, 0);
    func_800187D0(obj, 31, dir | 0x64, 1, 0);
    func_800187D0(obj, 21, dir | 0x6E, 0, 0);
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = z + 200.0f;
    obj->func_ptr = func_800FBAD4_SkateBoardSkamper;
    w->unk_4C = 0.7f;
    w->unk_3C = 180.0f;
    switch ((u32)dir >> 16) {
        case 1:
            i = 0;
            D_800FDD22_SkateBoardSkamper[player] = 0x451;
            break;
        case 2:
            i = 1;
            D_800FDD22_SkateBoardSkamper[player] = 0x452;
            break;
        case 6:
            i = 2;
            D_800FDD22_SkateBoardSkamper[player] = 0x453;
            break;
        case 3:
            i = 3;
            D_800FDD22_SkateBoardSkamper[player] = 0x454;
            break;
        case 4:
            i = 4;
            D_800FDD22_SkateBoardSkamper[player] = 0x455;
            break;
        default:
            i = 5;
            D_800FDD22_SkateBoardSkamper[player] = 0x456;
            break;
    }
    func_80027AC8(obj->model[9], (u8*)D_800FDB0C_SkateBoardSkamper[0], (u8*)D_800FDB0C_SkateBoardSkamper[i]);
    func_80025AD4(obj->model[9]);
}

void func_800F95B0_SkateBoardSkamper(omObjData* obj) {
    s32 file = D_800C59AC[GwPlayer[0].character].unk_04;
    s32 dir = D_800C59AC[GwPlayer[0].character].unk_00;
    s32 arg3 = D_800C59AC[GwPlayer[0].character].unk_08;

    func_800F92D0_SkateBoardSkamper(obj, dir, file, arg3, 0, -225.0f, 595.0f, 9500.0f);
    func_800090C4(obj, 0, 2);
    func_800090C4(obj, 1, 2);
    func_800090C4(obj, 2, 1);
    func_800090C4(obj, 6, 2);
    func_800090C4(obj, 7, 2);
    func_800090C4(obj, 8, 2);
    func_800090C4(obj, 9, 2);
    func_800090C4(obj, 10, 2);
    func_800090C4(obj, 11, 2);
    func_800090C4(obj, 3, 2);
    func_800090C4(obj, 4, 2);
    func_800090C4(obj, 5, 2);
}

void func_800F9708_SkateBoardSkamper(omObjData* obj) {
    s32 file = D_800C59AC[GwPlayer[1].character].unk_04;
    s32 dir = D_800C59AC[GwPlayer[1].character].unk_00;
    s32 arg3 = D_800C59AC[GwPlayer[1].character].unk_08;

    func_800F92D0_SkateBoardSkamper(obj, dir, file, arg3, 1, -75.0f, 595.0f, 9500.0f);
    func_800090C4(obj, 0, 2);
    func_800090C4(obj, 1, 2);
    func_800090C4(obj, 2, 1);
    func_800090C4(obj, 6, 2);
    func_800090C4(obj, 7, 2);
    func_800090C4(obj, 8, 2);
    func_800090C4(obj, 9, 2);
    func_800090C4(obj, 10, 2);
    func_800090C4(obj, 11, 2);
    func_800090C4(obj, 3, 2);
    func_800090C4(obj, 4, 2);
    func_800090C4(obj, 5, 2);
}

void func_800F9864_SkateBoardSkamper(omObjData* obj) {
    s32 file = D_800C59AC[GwPlayer[2].character].unk_04;
    s32 dir = D_800C59AC[GwPlayer[2].character].unk_00;
    s32 arg3 = D_800C59AC[GwPlayer[2].character].unk_08;

    func_800F92D0_SkateBoardSkamper(obj, dir, file, arg3, 2, 75.0f, 595.0f, 9500.0f);
    func_800090C4(obj, 0, 2);
    func_800090C4(obj, 1, 2);
    func_800090C4(obj, 2, 1);
    func_800090C4(obj, 6, 2);
    func_800090C4(obj, 7, 2);
    func_800090C4(obj, 8, 2);
    func_800090C4(obj, 9, 2);
    func_800090C4(obj, 10, 2);
    func_800090C4(obj, 11, 2);
    func_800090C4(obj, 3, 2);
    func_800090C4(obj, 4, 2);
    func_800090C4(obj, 5, 2);
}

void func_800F99C0_SkateBoardSkamper(omObjData* obj) {
    s32 file = D_800C59AC[GwPlayer[3].character].unk_04;
    s32 dir = D_800C59AC[GwPlayer[3].character].unk_00;
    s32 arg3 = D_800C59AC[GwPlayer[3].character].unk_08;

    func_800F92D0_SkateBoardSkamper(obj, dir, file, arg3, 3, 225.0f, 595.0f, 9500.0f);
    func_800090C4(obj, 0, 2);
    func_800090C4(obj, 1, 2);
    func_800090C4(obj, 2, 1);
    func_800090C4(obj, 6, 2);
    func_800090C4(obj, 7, 2);
    func_800090C4(obj, 8, 2);
    func_800090C4(obj, 9, 2);
    func_800090C4(obj, 10, 2);
    func_800090C4(obj, 11, 2);
    func_800090C4(obj, 3, 2);
    func_800090C4(obj, 4, 2);
    func_800090C4(obj, 5, 2);
}

/* A body at the start line (D_800EDE70): a sprite, a shadow model and a 4-byte extension. */
SbsBodyWork* func_800F9B1C_SkateBoardSkamper(omObjData* obj, s32 dir, f32 x, f32 y, f32 z, s32 arg5, s32 arg6) {
    SbsBodyWork* w;

    obj->unk_50 = func_80023684(sizeof(SbsBodyWork), 0x7918);
    func_8009B770(obj->unk_50, 0, sizeof(SbsBodyWork));
    obj->func_ptr = NULL;
    w = obj->unk_50;
    w->unk_68 = func_80023684(sizeof(s32), 0x7918);
    func_800091BC(obj, dir, 0xA89, 8);
    obj->model[1] = func_800174F4(6, 0xA99);
    func_80009340(obj, 3, 0x2A, 0xA89, 8);
    func_8001E2F8(w->unk_00[0x24], 0xF0);
    func_8001E360(w->unk_00[0x24], 0xFF, 0xFF, 0x86);
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = z;
    func_80025798(obj->model[1], obj->trans.x, 300.0f, z);
    w->unk_44 = 0.1f;
    w->unk_48 = 20.0f;
    w->unk_34 = 50.0f;
    w->unk_3C = 0.0f;
    w->unk_5C = 0.0f;
    w->unk_52 = arg5;
    w->unk_60 = 0.0f;
    w->unk_50 = arg6;
    w->unk_54 = 1;
    func_8000941C(obj, 2.0f, 2.0f, 2.0f);
    return w;
}

void func_800F9CB8_SkateBoardSkamper(omObjData* obj) {
    *func_800F9B1C_SkateBoardSkamper(obj, 0x37, 225.0f, 600.0f, 0.0f, 6, 1)->unk_68 = 0;
}

void func_800F9CF8_SkateBoardSkamper(omObjData* obj) {
    *func_800F9B1C_SkateBoardSkamper(obj, 0x37, 75.0f, 600.0f, 0.0f, 6, 2)->unk_68 = 1;
}

void func_800F9D3C_SkateBoardSkamper(omObjData* obj) {
    *func_800F9B1C_SkateBoardSkamper(obj, 0x37, -75.0f, 600.0f, 0.0f, 6, 3)->unk_68 = 2;
}

void func_800F9D80_SkateBoardSkamper(omObjData* obj) {
    *func_800F9B1C_SkateBoardSkamper(obj, 0x37, -225.0f, 600.0f, 0.0f, 6, 4)->unk_68 = 3;
}

#define SBS_TILE_Z(row, next, i) (row)[i]

/* The moving course tile: rises out of the ground in front of the boulder (D_800FDA10) and, once
   fully up, hands over to the next tile slot and moves to its next z. */
void func_800F9DC4_SkateBoardSkamper(omObjData* obj) {
    SbsFloorWork* w = obj->unk_50;
    s32 done = 0;
    s32 n;
    u8 next;
    u8 i;
    s32 dust;
    f32 z;

    if (obj->trans.z + 500.0f < D_800FDA10_SkateBoardSkamper) {
        func_800FBC38_SkateBoardSkamper(obj->model[0], 10);
        return;
    }
    n = obj->trans.z + 500.0f - D_800FDA10_SkateBoardSkamper;
    n = 10 - n / 100;
    if (n <= 0) {
        next = w->unk_05 + 1;
        if (next >= 12) {
            next = 6;
        }
        for (i = 0; i < D_800ED440; i++) {
            if (next == SBS_FLOOR(D_800F2AF8[i])->unk_05) {
                D_800F2AF8[i]->func_ptr = func_800F9DC4_SkateBoardSkamper;
                obj->func_ptr = func_800FBD7C_SkateBoardSkamper;
                func_80009058(obj, 0.0f, 100.0f, -300.0f, -500.0f, 300.0f, 500.0f);
                done = 1;
                break;
            }
        }
    }
    if (n != D_800FDB24_SkateBoardSkamper && D_800FDB24_SkateBoardSkamper > 0) {
        switch (D_800FDB28_SkateBoardSkamper) {
            case 0:
                dust = D_800FDD16_SkateBoardSkamper;
                break;
            case 1:
                dust = D_800FDD10_SkateBoardSkamper;
                break;
            case 2:
                dust = D_800FDD18_SkateBoardSkamper;
                break;
            case 3:
                dust = D_800FDD12_SkateBoardSkamper;
                break;
            case 4:
                dust = D_800FDD1A_SkateBoardSkamper;
                break;
            case 5:
            default:
                dust = D_800FDD14_SkateBoardSkamper;
                break;
        }
        if (++D_800FDB28_SkateBoardSkamper >= 6) {
            D_800FDB28_SkateBoardSkamper = 0;
        }
        func_800258EC(dust, 4, 0);
        func_80025798(dust, obj->trans.x, obj->trans.y, obj->trans.z + (D_800FDB24_SkateBoardSkamper * 100.0 - 500.0) - 50.0);
        func_80025CA8(dust, 0.0f);
        if (D_800FDA04_SkateBoardSkamper < 0) {
            D_800FDA04_SkateBoardSkamper = PlaySound(0x27A);
        }
    }
    func_800FBDA0_SkateBoardSkamper(obj);
    if (done == 0) {
        func_800FBC38_SkateBoardSkamper(obj->model[0], n);
        func_80009058(obj, 0.0f, 100.0f, -300.0f, -500.0f, 300.0f, n * 100 + -500.0f + 150.0f);
    } else {
        switch (w->unk_05) {
            case 6:
                if (D_800FDB2C_SkateBoardSkamper < 4) {
                    D_800FDB2C_SkateBoardSkamper++;
                }
                z = SBS_TILE_Z(D_800FDA24_SkateBoardSkamper, D_800FDA34_SkateBoardSkamper, D_800FDB2C_SkateBoardSkamper);
                break;
            case 7:
                z = SBS_TILE_Z(D_800FDA34_SkateBoardSkamper, D_800FDA44_SkateBoardSkamper, D_800FDB2C_SkateBoardSkamper);
                break;
            case 8:
                z = SBS_TILE_Z(D_800FDA44_SkateBoardSkamper, D_800FDA54_SkateBoardSkamper, D_800FDB2C_SkateBoardSkamper);
                break;
            case 9:
                z = SBS_TILE_Z(D_800FDA54_SkateBoardSkamper, D_800FDA64_SkateBoardSkamper, D_800FDB2C_SkateBoardSkamper);
                break;
            case 10:
                z = SBS_TILE_Z(D_800FDA64_SkateBoardSkamper, D_800FDA74_SkateBoardSkamper, D_800FDB2C_SkateBoardSkamper);
                break;
            case 11:
            default:
                z = SBS_TILE_Z(D_800FDA74_SkateBoardSkamper, D_800FDA84_SkateBoardSkamper, D_800FDB2C_SkateBoardSkamper);
                break;
        }
        if (z != 0.0f) {
            obj->trans.z = z;
        } else {
            func_800258EC(obj->model[0], 4, 4);
            for (i = 0; i < D_800F2BC0; i++) {
                func_800090C4(D_800F3FB0[i], w->unk_05, 1);
            }
        }
    }
    D_800FDB24_SkateBoardSkamper = n;
}

/* The start ramp: becomes solid once the race starts, and drops away behind the boulder. */
void func_800FA2B8_SkateBoardSkamper(omObjData* obj) {
    s32 i;
    s32 state = D_800ED430;

    if (state == 1) {
        func_80008FC4(obj, 20.0f);
        if (D_800FDB30_SkateBoardSkamper[0] == state && D_800FDA10_SkateBoardSkamper < obj->trans.z - 2000.0f) {
            for (i = 0; i < D_800F2BC0; i++) {
                func_800090C4(D_800F3FB0[i], 1, 1);
            }
            func_800258EC(obj->model[0], 4, 4);
            D_800FDB30_SkateBoardSkamper[0] = 0;
        }
    } else {
        func_80008FC4(obj, 0.0f);
    }
}

/* The goal: shown when the boulder comes within 3000. */
void func_800FA3B4_SkateBoardSkamper(omObjData* obj) {
    s32 i;

    if (D_800ED430 == 1 && D_800FDB30_SkateBoardSkamper[1] == D_800ED430 &&
        D_800FDA10_SkateBoardSkamper < obj->trans.z + 3000.0f) {
        for (i = 0; i < D_800F2BC0; i++) {
            func_800090C4(D_800F3FB0[i], 2, 2);
        }
        func_800258EC(obj->model[0], 4, 0);
        D_800FDB30_SkateBoardSkamper[1] = 0;
    }
}

/* Log row 1: the four logs fall in turn, then the row moves to its next z (D_800FDA84). */
void func_800FA498_SkateBoardSkamper(omObjData* obj) {
    SbsFloorWork* w;
    f32 d;
    s32 i;
    s32 more;

    if (D_800FDA10_SkateBoardSkamper + 50.0f < obj->trans.z) {
        if (D_800FDB34_SkateBoardSkamper > D_800B8994) {
            D_800FDB34_SkateBoardSkamper = D_800B8994;
        }
        w = obj->unk_50;
        d = D_800FDB34_SkateBoardSkamper * D_800FDB34_SkateBoardSkamper * -35.0f;
        obj->trans.y = d + obj->trans.y;
        obj->rot.x = obj->rot.x - d * 0.05f;
        if (D_800B8968 < (D_800FDB34_SkateBoardSkamper = D_800B8968 * 0.5f + D_800FDB34_SkateBoardSkamper)) {
            if (D_800FDB38_SkateBoardSkamper > D_800B8994) {
                D_800FDB38_SkateBoardSkamper = D_800B8994;
            }
            d = D_800FDB38_SkateBoardSkamper * D_800FDB38_SkateBoardSkamper * -35.0f;
            D_800FDB44_SkateBoardSkamper = d + D_800FDB44_SkateBoardSkamper;
            D_800FDB50_SkateBoardSkamper -= d * 0.05f;
            D_800FDB38_SkateBoardSkamper += D_800B8968 * 0.4f;
            func_80025798(obj->model[1], obj->trans.x - 150.0f, D_800FDB44_SkateBoardSkamper, obj->trans.z);
            func_800257E4(obj->model[1], D_800FDB50_SkateBoardSkamper, D_800FDB50_SkateBoardSkamper, obj->rot.z);
        }
        if (D_800FDB38_SkateBoardSkamper > D_800B8968) {
            if (D_800FDB3C_SkateBoardSkamper > D_800B8994) {
                D_800FDB3C_SkateBoardSkamper = D_800B8994;
            }
            d = D_800FDB3C_SkateBoardSkamper * D_800FDB3C_SkateBoardSkamper * -35.0f;
            D_800FDB48_SkateBoardSkamper = d + D_800FDB48_SkateBoardSkamper;
            D_800FDB54_SkateBoardSkamper -= d * 0.05f;
            D_800FDB3C_SkateBoardSkamper += D_800B8968 * 0.5f;
            func_80025798(obj->model[2], obj->trans.x - 300.0f, D_800FDB48_SkateBoardSkamper, obj->trans.z);
            func_800257E4(obj->model[2], D_800FDB54_SkateBoardSkamper, -D_800FDB54_SkateBoardSkamper, obj->rot.z);
        }
        if (D_800FDB3C_SkateBoardSkamper > D_800B8968) {
            if (D_800FDB40_SkateBoardSkamper > D_800B8994) {
                D_800FDB40_SkateBoardSkamper = D_800B8994;
            }
            d = D_800FDB40_SkateBoardSkamper * D_800FDB40_SkateBoardSkamper * -35.0f;
            D_800FDB4C_SkateBoardSkamper = d + D_800FDB4C_SkateBoardSkamper;
            D_800FDB58_SkateBoardSkamper -= d * 0.05f;
            D_800FDB40_SkateBoardSkamper += D_800B8968 * 0.4f;
            func_80025798(obj->model[3], obj->trans.x - 450.0f, D_800FDB4C_SkateBoardSkamper, obj->trans.z);
            func_800257E4(obj->model[3], D_800FDB58_SkateBoardSkamper, -D_800FDB58_SkateBoardSkamper, obj->rot.z);
        }
        if (obj->rot.x < -25.0f) {
            if (obj->rot.x < -90.0f) {
                obj->rot.x = -90.0f;
            }
            if (D_800FDB50_SkateBoardSkamper < -90.0f) {
                D_800FDB50_SkateBoardSkamper = -90.0f;
            }
            if (D_800FDB54_SkateBoardSkamper < -90.0f) {
                D_800FDB54_SkateBoardSkamper = -90.0f;
            }
            if (D_800FDB58_SkateBoardSkamper < -90.0f) {
                D_800FDB58_SkateBoardSkamper = -90.0f;
            }
            for (i = 0; i < D_800F2BC0; i++) {
                func_800090C4(D_800F3FB0[i], w->unk_05, 1);
            }
        }
        if (obj->trans.y < -800.0f) {
            more = 1;
            if (D_800FDB5C_SkateBoardSkamper >= 4) {
                func_800258EC(obj->model[0], 4, 4);
                func_800258EC(obj->model[1], 4, 4);
                func_800258EC(obj->model[2], 4, 4);
                func_800258EC(obj->model[3], 4, 4);
                obj->func_ptr = NULL;
                more = 0;
            } else {
                obj->trans.z = D_800FDA84_SkateBoardSkamper[D_800FDB5C_SkateBoardSkamper++];
            }
            if (more == 1) {
                D_800FDB44_SkateBoardSkamper = D_800FDB48_SkateBoardSkamper = D_800FDB4C_SkateBoardSkamper = obj->trans.y = 300.0f;
                D_800FDB38_SkateBoardSkamper = D_800FDB3C_SkateBoardSkamper = D_800FDB40_SkateBoardSkamper = D_800FDB34_SkateBoardSkamper = D_800FDB50_SkateBoardSkamper = D_800FDB54_SkateBoardSkamper = D_800FDB58_SkateBoardSkamper = obj->rot.x = 0.0f;
                func_80025798(obj->model[1], obj->trans.x - 150.0f, 300.0f, obj->trans.z);
                func_800257E4(obj->model[1], D_800FDB50_SkateBoardSkamper, obj->rot.y, obj->rot.z);
                func_80025798(obj->model[2], obj->trans.x - 300.0f, D_800FDB48_SkateBoardSkamper, obj->trans.z);
                func_800257E4(obj->model[2], D_800FDB54_SkateBoardSkamper, obj->rot.y, obj->rot.z);
                func_80025798(obj->model[3], obj->trans.x - 450.0f, D_800FDB4C_SkateBoardSkamper, obj->trans.z);
                func_800257E4(obj->model[3], D_800FDB58_SkateBoardSkamper, obj->rot.y, obj->rot.z);
                for (i = 0; i < D_800F2BC0; i++) {
                    func_800090C4(D_800F3FB0[i], w->unk_05, 2);
                }
            }
        }
    }
}

/* Log row 2 (D_800FDA94). */
void func_800FAC0C_SkateBoardSkamper(omObjData* obj) {
    SbsFloorWork* w;
    f32 d;
    s32 i;
    s32 more;

    if (D_800FDA10_SkateBoardSkamper + 50.0f < obj->trans.z) {
        if (D_800FDB60_SkateBoardSkamper > D_800B8994) {
            D_800FDB60_SkateBoardSkamper = D_800B8994;
        }
        w = obj->unk_50;
        d = D_800FDB60_SkateBoardSkamper * D_800FDB60_SkateBoardSkamper * -35.0f;
        obj->trans.y = d + obj->trans.y;
        obj->rot.x = obj->rot.x - d * 0.05f;
        if (D_800B8968 < (D_800FDB60_SkateBoardSkamper = D_800B8968 * 0.5f + D_800FDB60_SkateBoardSkamper)) {
            if (D_800FDB64_SkateBoardSkamper > D_800B8994) {
                D_800FDB64_SkateBoardSkamper = D_800B8994;
            }
            d = D_800FDB64_SkateBoardSkamper * D_800FDB64_SkateBoardSkamper * -35.0f;
            D_800FDB70_SkateBoardSkamper = d + D_800FDB70_SkateBoardSkamper;
            D_800FDB7C_SkateBoardSkamper -= d * 0.05f;
            D_800FDB64_SkateBoardSkamper += D_800B8968 * 0.4f;
            func_80025798(obj->model[1], obj->trans.x - 150.0f, D_800FDB70_SkateBoardSkamper, obj->trans.z);
            func_800257E4(obj->model[1], D_800FDB7C_SkateBoardSkamper, D_800FDB7C_SkateBoardSkamper, obj->rot.z);
        }
        if (D_800FDB64_SkateBoardSkamper > D_800B8968) {
            if (D_800FDB68_SkateBoardSkamper > D_800B8994) {
                D_800FDB68_SkateBoardSkamper = D_800B8994;
            }
            d = D_800FDB68_SkateBoardSkamper * D_800FDB68_SkateBoardSkamper * -35.0f;
            D_800FDB74_SkateBoardSkamper = d + D_800FDB74_SkateBoardSkamper;
            D_800FDB80_SkateBoardSkamper -= d * 0.05f;
            D_800FDB68_SkateBoardSkamper += D_800B8968 * 0.5f;
            func_80025798(obj->model[2], obj->trans.x - 300.0f, D_800FDB74_SkateBoardSkamper, obj->trans.z);
            func_800257E4(obj->model[2], D_800FDB80_SkateBoardSkamper, -D_800FDB80_SkateBoardSkamper, obj->rot.z);
        }
        if (D_800FDB68_SkateBoardSkamper > D_800B8968) {
            if (D_800FDB6C_SkateBoardSkamper > D_800B8994) {
                D_800FDB6C_SkateBoardSkamper = D_800B8994;
            }
            d = D_800FDB6C_SkateBoardSkamper * D_800FDB6C_SkateBoardSkamper * -35.0f;
            D_800FDB78_SkateBoardSkamper = d + D_800FDB78_SkateBoardSkamper;
            D_800FDB84_SkateBoardSkamper -= d * 0.05f;
            D_800FDB6C_SkateBoardSkamper += D_800B8968 * 0.4f;
            func_80025798(obj->model[3], obj->trans.x - 450.0f, D_800FDB78_SkateBoardSkamper, obj->trans.z);
            func_800257E4(obj->model[3], D_800FDB84_SkateBoardSkamper, -D_800FDB84_SkateBoardSkamper, obj->rot.z);
        }
        if (obj->rot.x < -25.0f) {
            if (obj->rot.x < -90.0f) {
                obj->rot.x = -90.0f;
            }
            if (D_800FDB7C_SkateBoardSkamper < -90.0f) {
                D_800FDB7C_SkateBoardSkamper = -90.0f;
            }
            if (D_800FDB80_SkateBoardSkamper < -90.0f) {
                D_800FDB80_SkateBoardSkamper = -90.0f;
            }
            if (D_800FDB84_SkateBoardSkamper < -90.0f) {
                D_800FDB84_SkateBoardSkamper = -90.0f;
            }
            for (i = 0; i < D_800F2BC0; i++) {
                func_800090C4(D_800F3FB0[i], w->unk_05, 1);
            }
        }
        if (obj->trans.y < -800.0f) {
            more = 1;
            if (D_800FDB88_SkateBoardSkamper >= 3) {
                func_800258EC(obj->model[0], 4, 4);
                func_800258EC(obj->model[1], 4, 4);
                func_800258EC(obj->model[2], 4, 4);
                func_800258EC(obj->model[3], 4, 4);
                obj->func_ptr = NULL;
                more = 0;
            } else {
                obj->trans.z = D_800FDA94_SkateBoardSkamper[D_800FDB88_SkateBoardSkamper++];
            }
            if (more == 1) {
                D_800FDB70_SkateBoardSkamper = D_800FDB74_SkateBoardSkamper = D_800FDB78_SkateBoardSkamper = obj->trans.y = 300.0f;
                D_800FDB64_SkateBoardSkamper = D_800FDB68_SkateBoardSkamper = D_800FDB6C_SkateBoardSkamper = D_800FDB60_SkateBoardSkamper = D_800FDB7C_SkateBoardSkamper = D_800FDB80_SkateBoardSkamper = D_800FDB84_SkateBoardSkamper = obj->rot.x = 0.0f;
                func_80025798(obj->model[1], obj->trans.x - 150.0f, 300.0f, obj->trans.z);
                func_800257E4(obj->model[1], D_800FDB7C_SkateBoardSkamper, obj->rot.y, obj->rot.z);
                func_80025798(obj->model[2], obj->trans.x - 300.0f, D_800FDB74_SkateBoardSkamper, obj->trans.z);
                func_800257E4(obj->model[2], D_800FDB80_SkateBoardSkamper, obj->rot.y, obj->rot.z);
                func_80025798(obj->model[3], obj->trans.x - 450.0f, D_800FDB78_SkateBoardSkamper, obj->trans.z);
                func_800257E4(obj->model[3], D_800FDB84_SkateBoardSkamper, obj->rot.y, obj->rot.z);
                for (i = 0; i < D_800F2BC0; i++) {
                    func_800090C4(D_800F3FB0[i], w->unk_05, 2);
                }
            }
        }
    }
}

/* Log row 3 (D_800FDAA0): hidden once past its table. */
void func_800FB380_SkateBoardSkamper(omObjData* obj) {
    f32 d;
    s32 i;

    if (D_800FDA10_SkateBoardSkamper + 50.0f < obj->trans.z) {
        if (D_800FDB8C_SkateBoardSkamper > D_800B8994) {
            D_800FDB8C_SkateBoardSkamper = D_800B8994;
        }
        d = D_800FDB8C_SkateBoardSkamper * D_800FDB8C_SkateBoardSkamper * -35.0f;
        obj->trans.y = d + obj->trans.y;
        obj->rot.x = obj->rot.x - d * 0.05f;
        if (D_800B8968 < (D_800FDB8C_SkateBoardSkamper = D_800B8968 * 0.5f + D_800FDB8C_SkateBoardSkamper)) {
            if (D_800FDB90_SkateBoardSkamper > D_800B8994) {
                D_800FDB90_SkateBoardSkamper = D_800B8994;
            }
            d = D_800FDB90_SkateBoardSkamper * D_800FDB90_SkateBoardSkamper * -35.0f;
            D_800FDB9C_SkateBoardSkamper = d + D_800FDB9C_SkateBoardSkamper;
            D_800FDBA8_SkateBoardSkamper -= d * 0.05f;
            D_800FDB90_SkateBoardSkamper += D_800B8968 * 0.4f;
            func_80025798(obj->model[1], obj->trans.x - 150.0f, D_800FDB9C_SkateBoardSkamper, obj->trans.z);
            func_800257E4(obj->model[1], D_800FDBA8_SkateBoardSkamper, D_800FDBA8_SkateBoardSkamper, obj->rot.z);
        }
        if (D_800FDB90_SkateBoardSkamper > D_800B8968) {
            if (D_800FDB94_SkateBoardSkamper > D_800B8994) {
                D_800FDB94_SkateBoardSkamper = D_800B8994;
            }
            d = D_800FDB94_SkateBoardSkamper * D_800FDB94_SkateBoardSkamper * -35.0f;
            D_800FDBA0_SkateBoardSkamper = d + D_800FDBA0_SkateBoardSkamper;
            D_800FDBAC_SkateBoardSkamper -= d * 0.05f;
            D_800FDB94_SkateBoardSkamper += D_800B8968 * 0.5f;
            func_80025798(obj->model[2], obj->trans.x - 300.0f, D_800FDBA0_SkateBoardSkamper, obj->trans.z);
            func_800257E4(obj->model[2], D_800FDBAC_SkateBoardSkamper, -D_800FDBAC_SkateBoardSkamper, obj->rot.z);
        }
        if (D_800FDB94_SkateBoardSkamper > D_800B8968) {
            if (D_800FDB98_SkateBoardSkamper > D_800B8994) {
                D_800FDB98_SkateBoardSkamper = D_800B8994;
            }
            d = D_800FDB98_SkateBoardSkamper * D_800FDB98_SkateBoardSkamper * -35.0f;
            D_800FDBA4_SkateBoardSkamper = d + D_800FDBA4_SkateBoardSkamper;
            D_800FDBB0_SkateBoardSkamper -= d * 0.05f;
            D_800FDB98_SkateBoardSkamper += D_800B8968 * 0.4f;
            func_80025798(obj->model[3], obj->trans.x - 450.0f, D_800FDBA4_SkateBoardSkamper, obj->trans.z);
            func_800257E4(obj->model[3], D_800FDBB0_SkateBoardSkamper, -D_800FDBB0_SkateBoardSkamper, obj->rot.z);
        }
        if (obj->rot.x < -25.0f) {
            if (obj->rot.x < -90.0f) {
                obj->rot.x = -90.0f;
            }
            if (D_800FDBA8_SkateBoardSkamper < -90.0f) {
                D_800FDBA8_SkateBoardSkamper = -90.0f;
            }
            if (D_800FDBAC_SkateBoardSkamper < -90.0f) {
                D_800FDBAC_SkateBoardSkamper = -90.0f;
            }
            if (D_800FDBB0_SkateBoardSkamper < -90.0f) {
                D_800FDBB0_SkateBoardSkamper = -90.0f;
            }
            for (i = 0; i < D_800F2BC0; i++) {
                func_800090C4(D_800F3FB0[i], 5, 1);
            }
        }
        if (obj->trans.y < -800.0f) {
            if (D_800FDBB4_SkateBoardSkamper >= 4) {
                func_800258EC(obj->model[0], 4, 4);
                func_800258EC(obj->model[1], 4, 4);
                func_800258EC(obj->model[2], 4, 4);
                func_800258EC(obj->model[3], 4, 4);
            } else {
                obj->trans.z = D_800FDAA0_SkateBoardSkamper[D_800FDBB4_SkateBoardSkamper];
                D_800FDBB4_SkateBoardSkamper++;
                D_800FDB9C_SkateBoardSkamper = D_800FDBA0_SkateBoardSkamper = D_800FDBA4_SkateBoardSkamper = obj->trans.y = 200.0f;
                D_800FDB90_SkateBoardSkamper = D_800FDB94_SkateBoardSkamper = D_800FDB98_SkateBoardSkamper = D_800FDB8C_SkateBoardSkamper = D_800FDBA8_SkateBoardSkamper = D_800FDBAC_SkateBoardSkamper = D_800FDBB0_SkateBoardSkamper = obj->rot.x = 0.0f;
                func_80025798(obj->model[1], obj->trans.x - 150.0f, 200.0f, obj->trans.z);
                func_800257E4(obj->model[1], D_800FDBA8_SkateBoardSkamper, obj->rot.y, obj->rot.z);
                func_80025798(obj->model[2], obj->trans.x - 300.0f, D_800FDBA0_SkateBoardSkamper, obj->trans.z);
                func_800257E4(obj->model[2], D_800FDBAC_SkateBoardSkamper, obj->rot.y, obj->rot.z);
                func_80025798(obj->model[3], obj->trans.x - 450.0f, D_800FDBA4_SkateBoardSkamper, obj->trans.z);
                func_800257E4(obj->model[3], D_800FDBB0_SkateBoardSkamper, obj->rot.y, obj->rot.z);
                for (i = 0; i < D_800F2BC0; i++) {
                    func_800090C4(D_800F3FB0[i], 5, 2);
                }
            }
        }
    }
}

/* A player object. */
void func_800FBAD4_SkateBoardSkamper(omObjData* obj) {
    SbsPlayerWork* w = obj->unk_50;
    s32 pl;

    switch (D_800ED430) {
        case 0:
            if (D_800FDA00_SkateBoardSkamper < 10) {
                obj->trans.z -= 10.0f;
            }
            break;
        case 1:
            if (GwPlayer[w->unk_58].flags & 1) {
                func_800FD764_SkateBoardSkamper(obj);
            }
            break;
        case 2:
            if (_CheckFlag(0x2B) == 0) {
                pl = w->unk_58;
                if (w->unk_38 == 1000.0f && CRot.x <= 215.0f) {
                    if (pl == D_800FDA0F_SkateBoardSkamper) {
                        func_800184BC(obj, 13);
                    } else if (w->unk_53 == 2) {
                        func_800184BC(obj, 14);
                    }
                }
            }
            break;
    }
    func_800FC758_SkateBoardSkamper(obj);
}

/* Raises a course tile model's far vertices (y > 400) to n steps of 10 and scrolls its texture. */
void func_800FBC38_SkateBoardSkamper(s16 model, s16 n) {
    unk2C0C0StructC0* m = D_800F2B7C[model].unk_6C;
    unk2C0C0StructB0* b;
    unk2C0C0StructE0* dst;
    s16 idx;
    s16 i;
    s16 j;

    for (i = 0; i < m->unk_74; i++) {
        b = &m->unk_D0[i];
        for (j = 0; j < b->unk_00; j++) {
            idx = b->unk_02[j];
            dst = &m->unk_08[D_800F37F0][idx];
            if (m->unk_04[idx].unk_04 > 400) {
                dst->unk_04 = n * 100 - 500;
                switch (i) {
                    case 0:
                        dst->unk_0A = (10 - n) * 512;
                        break;
                    case 2:
                        dst->unk_08 = (10 - n) * 1024;
                        break;
                }
            }
        }
    }
}

void func_800FBD7C_SkateBoardSkamper(omObjData* obj) {
    func_800FBC38_SkateBoardSkamper(obj->model[0], 10);
}

/* Hides each dust model once its animation has passed frame 60. */
void func_800FBDA0_SkateBoardSkamper(omObjData* obj) {
    s32 i;
    s16 dust;
    f32 f;

    if ((func_8005FD5C() & 0xFFFF) + D_800F64F8 != 0) {
        return;
    }
    for (i = 0; i < 6; i++) {
        switch (i) {
            case 0:
                dust = D_800FDD16_SkateBoardSkamper;
                break;
            case 1:
                dust = D_800FDD10_SkateBoardSkamper;
                break;
            case 2:
                dust = D_800FDD18_SkateBoardSkamper;
                break;
            case 3:
                dust = D_800FDD12_SkateBoardSkamper;
                break;
            case 4:
                dust = D_800FDD1A_SkateBoardSkamper;
                break;
            case 5:
            default:
                dust = D_800FDD14_SkateBoardSkamper;
                break;
        }
        if (dust > 0) {
            f = func_80025D18(dust);
            if (!(f < 30.0f) && f >= 60.0f) {
                func_800258EC(dust, 4, 4);
            }
        }
    }
}

/* Tilts a player toward the floor normal n, 4 degrees a frame. */
void func_800FBEE0_SkateBoardSkamper(omObjData* obj, Vec3f* n) {
    SbsPlayerWork* w = obj->unk_50;
    f32 ax = -(func_800B0CD8(n->y, n->z) - 90.0f);
    f32 az = func_800B0CD8(n->y, n->x) - 90.0f;
    f32 tx = w->unk_90;
    f32 tz = w->unk_98;

    if (tx < ax) {
        if ((w->unk_90 = tx + 4.0f) > ax) {
            w->unk_90 = ax;
        }
    } else if (ax < tx) {
        if ((w->unk_90 -= 4.0f) < ax) {
            w->unk_90 = ax;
        }
    }
    if (tz < az) {
        if ((w->unk_98 += 4.0f) > az) {
            w->unk_98 = az;
        }
    } else if (az < tz) {
        if ((w->unk_98 -= 4.0f) < az) {
            w->unk_98 = az;
        }
    }
    obj->rot.x = w->unk_90;
    obj->rot.z = w->unk_98;
}

/* Ground check of a rolling player (1130.c's func_80004578 for a board): returns the floor height
   when the board is on a floor, else starts the fall and returns 65536.0f. */
f32 func_800FC054_SkateBoardSkamper(omObjData* obj, f32 angle, f32 x, f32 y, f32 z) {
    Vec4f probe;
    Vec3f n;
    Vec3f n2;
    SbsPlayerWork* w;
    SbsFloorWork* gw;
    SbsFloorWork* g;
    SbsColVtx* verts;
    SbsColTri* tri;
    Vec3f* normal;
    s16 mdl;
    s8 floor;
    f32 sa;
    f32 sc;
    f32 speed;
    f32 floorY;
    f32 shadowY;
    f32 h;
    f32 nx;
    f32 nz;

    floor = -1;
    w = obj->unk_50;
    w->unk_53 = w->unk_54 = -1;
    normal = NULL;
    if (fabs(w->unk_84) > 1.0) {
        D_800ED6B8 += w->unk_84;
    }
    if (fabs(w->unk_8C) > 1.0) {
        D_800F5254 += w->unk_8C;
    }
    func_800AEAC0(angle);
    func_800AEFD0(angle);
    floorY = shadowY = -65536.0f;
    sa = w->unk_40;
    sc = w->unk_A4;
    if (w->unk_50 & 6) {
        speed = sa * 0.6f * sc;
    } else {
        speed = sa * sc;
    }
    nx = x + func_800AEAC0(angle) * speed;
    nz = z + func_800AEFD0(angle) * speed;
    probe.x = nx + D_800ED6B8;
    probe.y = y;
    probe.z = nz + D_800F5254;
    probe.w = w->unk_48;
    func_80004D1C(obj, &probe, 0);
    if (!(w->unk_00[D_800B8954] & 1)) {
        gw = D_800F2AF8[D_800B8954]->unk_50;
        if (gw->unk_01 & 0x1A) {
            if (func_8000A910(&probe, gw) == 1) {
                h = gw->unk_10;
                if (floorY < h && h < y + 150.0f) {
                    floorY = h;
                    floor = D_800B8954;
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
            verts = (SbsColVtx*)D_800F2B7C[mdl].unk_6C->unk_78;
            func_8002AE24(mdl, &D_800EDEC0, func_80002060, &probe);
            for (tri = (SbsColTri*)func_8002B3A8(&D_800EDEC0); tri != NULL; tri = (SbsColTri*)func_8002B3A8(&D_800EDEC0)) {
                h = func_80029764(nx, y, nz, verts, tri);
                if (floorY < h) {
                    floorY = h;
                    floor = D_800B8954;
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
        floor = D_800B8958;
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
        if (floor != -1) {
            w->unk_53 = floor;
        }
        if (w->unk_00[floor] & 8) {
            func_80009438();
        }
        y = floorY;
        w->unk_38 = 1000.0f;
    } else {
        func_800185A4(obj, 6);
        w->unk_38 = -D_800B8964 * 0.1f;
        w->unk_53 = -1;
        return 65536.0f;
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
        g = D_800F2AF8[w->unk_53]->unk_50;
        w->unk_84 = normal->x * g->unk_0C;
        w->unk_88 = normal->y;
        w->unk_8C = normal->z * g->unk_0C;
        func_800FBEE0_SkateBoardSkamper(obj, normal);
    } else {
        w->unk_90 = w->unk_98 = w->unk_84 = w->unk_88 = w->unk_8C = 0.0f;
        obj->rot.x = obj->rot.z = 0.0f;
    }
    return y;
}

/* A player's movement: stick steering, B (0x4000) to push, A (0x8000) to jump, falls into the
   gaps and off the course, and the finish line at z -9600. */
void func_800FC758_SkateBoardSkamper(omObjData* obj) {
    s16 sx;
    s16 sy;
    SbsPlayerWork* w = obj->unk_50;
    u8 port = w->unk_56;
    f32 zero = 0.0f;
    f32 x = obj->trans.x;
    f32 y = obj->trans.y;
    f32 z = obj->trans.z;
    u16 mdl;
    f32 rx;
    f32 shadowY;
    u16 btn;
    s32 flags;
    s32 ok;
    f32 v;
    f32 h;
    f32 spd;
    f32 lim;
    f32 v1;
    f32 vv1;
    f32 v2;
    f32 vv2;
    f32 v3;
    f32 vv3;

    func_80005A04((Object*)obj);
    mdl = obj->model[0];
    rx = obj->rot.x;
    shadowY = obj->trans.y;
    D_800ED6B8 = D_800F5254 = zero;
    D_800F370C = 0;
    w->unk_55 = -1;
    if (((D_800ED430 == 1) & ((s8)port >= 0)) && w->unk_53 != 2) {
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
        btn = 0;
        if (!(w->unk_50 & 6)) {
            btn = ContBtnTrg[(s8)port];
        }
    } else {
        sx = sy = 0;
        btn = 0;
    }
    flags = func_80017A60(obj);
    if (flags & 1) {
        ok = 1;
        if (w->unk_38 == 1000.0f) {
            if (func_800FC054_SkateBoardSkamper(obj, w->unk_3C, x, y, z) != 65536.0f && (btn & 0x8000) &&
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
            h = y + vv1 * ((w->unk_38 >= 0.0f) ? -35.0f : 35.0f);
            w->unk_38 += D_800B8968;
            if (func_800184BC(obj, 6) == 1) {
                func_80009624((unkGlobalStruct_00*)w, 3);
                ok = 0;
            }
            y = func_80004578(obj, x, h, z, y);
            if (w->unk_38 == 1000.0f) {
                if (w->unk_53 == 0) {
                    if (D_800FDA08_SkateBoardSkamper[w->unk_58] == 0) {
                        D_800FDA08_SkateBoardSkamper[w->unk_58] = D_800FDA0D_SkateBoardSkamper--;
                    }
                    func_800184BC(obj, 16);
                    func_80060618(0x45F, w->unk_58);
                    func_800258EC(obj->model[1], 4, 4);
                    func_800258EC(obj->model[9], 4, 4);
                    func_80060F04(w->unk_58, 10, 0, 10);
                } else {
                    func_800184BC(obj, 21);
                    func_80009624((unkGlobalStruct_00*)w, 4);
                }
            }
        }
        if (ok == 1) {
            func_800184BC(obj, 0);
        }
        shadowY = y;
    } else if (flags & 0x18C18) {
        v = w->unk_38;
        if (v == 1000.0f) {
            if (flags & 0x10) {
                if (w->unk_40 > D_800B8980) {
                    w->unk_3C += -(f32)sx / D_800B8970;
                } else {
                    lim = (w->unk_40 <= D_800B898C) ? D_800B898C : w->unk_40;
                    w->unk_3C += -((f32)sx / D_800B8970) * (lim / D_800B8980);
                }
            }
            h = func_800FC054_SkateBoardSkamper(obj, w->unk_3C, x, y, z);
            if (h != 65536.0f) {
                y = h;
                if (flags & 0x10000) {
                    if (btn & 0x8000) {
                        func_800184BC(obj, 6);
                        w->unk_38 = -D_800B8964;
                        D_800FDA14_SkateBoardSkamper[w->unk_58] = 0.0f;
                        func_80009624((unkGlobalStruct_00*)w, 3);
                    }
                    if (D_800FDA14_SkateBoardSkamper[w->unk_58] != 0.0f) {
                        D_800FDA14_SkateBoardSkamper[w->unk_58] *= 0.7f;
                    }
                } else if (w->unk_40 == D_800B8990) {
                    func_800184BC(obj, 0);
                } else if (w->unk_40 < D_800B8990) {
                    if ((w->unk_40 += 2.0f * D_800B8960) >= D_800B8990) {
                        w->unk_40 = D_800B8990;
                    }
                } else if (D_800B8990 <= w->unk_40) {
                    if ((w->unk_40 += 2.0f * -D_800B8960) <= D_800B8990) {
                        w->unk_40 = D_800B8990;
                    }
                }
            }
            shadowY = y;
        } else {
            if (v > D_800B8994) {
                v = D_800B8994;
            }
            h = y + v * v * ((w->unk_38 >= 0.0f) ? -35.0f : 35.0f);
            w->unk_38 += D_800B8968;
            y = func_80004578(obj, x, h, z, y);
            if (w->unk_38 == 1000.0f) {
                if (w->unk_53 == 0) {
                    if (D_800FDA08_SkateBoardSkamper[w->unk_58] == 0) {
                        D_800FDA08_SkateBoardSkamper[w->unk_58] = D_800FDA0D_SkateBoardSkamper--;
                    }
                    func_800184BC(obj, 16);
                    func_80060618(0x45F, w->unk_58);
                    func_800258EC(obj->model[1], 4, 4);
                    func_800258EC(obj->model[9], 4, 4);
                    func_80060F04(w->unk_58, 10, 0, 10);
                } else {
                    func_800184BC(obj, 0);
                    func_80009624((unkGlobalStruct_00*)w, 4);
                }
            }
            shadowY = y;
        }
    } else if (flags & 0x20) {
        if (func_80025E70(mdl) == -1.0f) {
            func_80025D18(mdl);
        }
        v2 = w->unk_38;
        if (v2 > D_800B8994) {
            v2 = D_800B8994;
        }
        vv2 = v2 * v2;
        h = y + vv2 * ((w->unk_38 >= 0.0f) ? -35.0f : 35.0f);
        w->unk_38 += D_800B8968;
        D_800FDA14_SkateBoardSkamper[w->unk_58] += 3.5f;
        if (D_800FDA14_SkateBoardSkamper[w->unk_58] > 45.0f) {
            D_800FDA14_SkateBoardSkamper[w->unk_58] = 45.0f;
        }
        rx = D_800FDA14_SkateBoardSkamper[w->unk_58];
        if ((w->unk_40 += -0.12f) < D_800B8990) {
            w->unk_40 = D_800B8990;
        }
        y = func_80004578(obj, x, h, z, y);
        if (w->unk_38 == 1000.0f) {
            if (w->unk_53 == 0) {
                if (D_800FDA08_SkateBoardSkamper[w->unk_58] == 0) {
                    D_800FDA08_SkateBoardSkamper[w->unk_58] = D_800FDA0D_SkateBoardSkamper--;
                }
                func_800184BC(obj, 16);
                func_80060618(0x45F, w->unk_58);
                func_800258EC(obj->model[1], 4, 4);
                func_800258EC(obj->model[9], 4, 4);
                func_80060F04(w->unk_58, 10, 0, 10);
            } else {
                func_800184BC(obj, 21);
                func_80009624((unkGlobalStruct_00*)w, 4);
            }
        } else if (D_800F5254 > 0.0f) {
            if (y > 350.0f) {
                func_800184BC(obj, 31);
                w->unk_40 = D_800B8984;
                w->unk_38 = -D_800B8964 * 0.8;
            }
        }
        shadowY = y;
    } else if (flags & 6) {
        func_80009C90(obj, sx, sy);
        if (w->unk_53 == 1 && D_800ED430 == 1) {
            w->unk_40 += 1.0f;
        }
        if (btn & 0x4000) {
            w->unk_40 += D_800FDAC0_SkateBoardSkamper[func_800F7BC4_SkateBoardSkamper(w->unk_58)];
            if (func_800184BC(obj, 1) == 1) {
                func_80060540(GwPlayer[w->unk_58].character + 0x274, w->unk_58);
            }
        } else if (w->unk_40 > 5.0f) {
            w->unk_40 += w->unk_40 * D_800FDAD0_SkateBoardSkamper[func_800F7BC4_SkateBoardSkamper(w->unk_58)];
        } else {
            w->unk_40 += -0.5f;
        }
        if (w->unk_40 > D_800B8980) {
            w->unk_40 = D_800B8980;
        }
        if (w->unk_40 < D_800B8990) {
            w->unk_40 = D_800B8990;
        }
        D_800FDA14_SkateBoardSkamper[w->unk_58] = 0.0f;
        h = func_800FC054_SkateBoardSkamper(obj, w->unk_3C, x, y, z);
        if (h != 65536.0f) {
            y = h;
            if (!(func_80017A60(obj) & 0xC00) && w->unk_53 != 1 && (btn & 0x8000)) {
                func_800185A4(obj, 6);
                w->unk_38 = -D_800B8964;
                func_80009624((unkGlobalStruct_00*)w, 3);
            }
        }
        shadowY = y;
    } else if (flags & 0x20000) {
        w->unk_40 = D_800B8990;
        v3 = w->unk_38;
        if (v3 > D_800B8994) {
            v3 = D_800B8994;
        }
        vv3 = v3 * v3;
        y += vv3 * ((w->unk_38 >= 0.0f) ? -35.0f : 35.0f);
        w->unk_38 += D_800B8968 / 2.0f;
        if (w->unk_40 != 0.0f) {
            w->unk_40 = D_800B8990;
        }
        if (y < 0.0f) {
            w->unk_38 = -D_800B8964;
        }
        if (D_800FDA10_SkateBoardSkamper < z - 2000.0f || fabs(x) > 2000.0) {
            func_800258EC(obj->model[0], 4, 4);
            obj->func_ptr = NULL;
        }
        if ((u8)w->unk_58 & 1) {
            x += 8.0f;
        } else {
            x -= 8.0f;
        }
        shadowY = y;
    } else if (flags & 0x1000) {
        if ((w->unk_40 += -w->unk_40 * 0.15f) < D_800B8990) {
            w->unk_40 = D_800B8990;
        }
        func_800258EC(obj->model[1], 4, 4);
        y = 320.0f;
        shadowY = 300.0f;
    }
    spd = w->unk_40;
    if (w->unk_50 & 6) {
        spd *= 0.6f;
    }
    z += func_800AEFD0(w->unk_3C) * spd + D_800F5254;
    if ((z < D_800FDA10_SkateBoardSkamper - 300.0f) & (z > -8100.0f)) {
        z = D_800FDA10_SkateBoardSkamper - 300.0f;
    }
    if (z < -9600.0f) {
        if (D_800FDA0C_SkateBoardSkamper == 0) {
            D_800FDA0F_SkateBoardSkamper = w->unk_58;
        }
        if (D_800FDA08_SkateBoardSkamper[w->unk_58] == 0) {
            D_800FDA08_SkateBoardSkamper[w->unk_58] = D_800FDA0C_SkateBoardSkamper++;
        }
    }
    func_8009ECB0(D_800F2B7C[obj->model[0]].unk7C, 0.0f, w->unk_3C, 0.0f);
    func_800093FC(obj, x, y, z);
    func_80025798(obj->model[9], obj->trans.x, shadowY, obj->trans.z);
    func_800257E4(obj->model[9], rx, obj->rot.y, obj->rot.z);
    func_8009ECB0(D_800F2B7C[obj->model[9]].unk7C, 0.0f, w->unk_3C, 0.0f);
    func_80017DB0(obj);
    w->unk_60 = CRot.y;
}

/* CPU input: push (B) at random, jump (A) over a log row 0-250 ahead or the body in front. */
void func_800FD764_SkateBoardSkamper(omObjData* obj) {
    SbsPlayerWork* w = obj->unk_50;
    u8 port = w->unk_56;
    u8 r;
    u32 th;
    s32 i;
    SbsFloorWork* g;
    omObjData* o;
    f32 d;

    ContBtnTrg[port] &= 0x3FFF;
    r = rand8();
    switch (GwPlayer[w->unk_58].cpu_difficulty) {
        case 0:
            th = 0xB8;
            if (obj->trans.z < -8100.0f) {
                th = 0xD8;
            }
            break;
        case 1:
            th = 0xB8;
            break;
        case 2:
            th = 0x90;
            break;
        default:
            th = 0x60;
            break;
    }
    if (w->unk_38 == 1000.0f) {
        for (i = 0; i < D_800ED440; i++) {
            o = D_800F2AF8[i];
            g = o->unk_50;
            d = obj->trans.z - o->trans.z;
            if (g->unk_05 == 3 || g->unk_05 == 4 || g->unk_05 == 5) {
                if (((d < 250.0f) & (d > 0.0f)) && th < r) {
                    ContBtnTrg[port] |= 0x8000;
                }
            }
        }
        d = obj->trans.z - D_800EDE70[w->unk_58]->trans.z;
        if ((d < 250.0f) & (d > 0.0f)) {
            if (th < r) {
                ContBtnTrg[port] |= 0x8000;
            }
        }
        if (th < r) {
            ContBtnTrg[port] |= 0x4000;
        }
    }
}
