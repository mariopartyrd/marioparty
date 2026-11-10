#include "UnusedMinigame0.h"

/* .data (0x80102AF0..0x80102BF4) */

/* The two idle motions the player picks from (character file suffixes). */
u32 D_80102AF0_UnusedMinigame0[5] = { 0x0F, 0x38, 0x39, 0x3A, 0x3B };
u32 D_80102B04_UnusedMinigame0[5] = { 0x10, 0x3C, 0x3D, 0x3E, 0x3F };
/* Per exit: the push direction, the facing, and the CPU's approach point / 10. */
UM0Vec2 D_80102B18_UnusedMinigame0[5] = {
    { 0.0f, -1.0f }, { -1.0f, 0.0f }, { 0.0f, -1.0f }, { 0.0f, -1.0f }, { 1.0f, 0.0f },
};
f32 D_80102B40_UnusedMinigame0[5] = { 180.0f, 90.0f, 0.0f, 0.0f, 270.0f };
UM0Vec2 D_80102B54_UnusedMinigame0[5] = {
    { 0.0f, 0.0f }, { 20.0f, 0.0f }, { 10.0f, 10.0f }, { 0.0f, 0.0f }, { -20.0f, 0.0f },
};
/* Per character: the intro motion and its length. */
s16 D_80102B7C_UnusedMinigame0[6][2] = {
    { 1, 0x20 }, { 1, 0x20 }, { 1, 0x2A }, { 1, 0x2A }, { 1, 0x20 }, { 1, 0x2C },
};
/* The stage models. */
s16 D_80102B94_UnusedMinigame0[10] = { 0, 1, 3, 4, 5, 2, 9, 10, 11, 12 };
/* The three pick-ups: x / 10, z / 10, facing. */
s16 D_80102BA8_UnusedMinigame0[3][3] = {
    { 45, 0, 90 },
    { 10, 35, 180 },
    { -45, 0, 270 },
};
/* Per gate: the two cells ({x, z}, {x, z}) that must be empty for it to open. */
s16 D_80102BBC_UnusedMinigame0[5][4] = {
    { 0, 0, 0, 0 },
    { 7, 2, 7, 3 },
    { 4, 5, 5, 5 },
    { 0, 0, 0, 0 },
    { 0, 2, 0, 3 },
};
/* The four neighbours (dx, dz). */
s16 D_80102BE4_UnusedMinigame0[4][2] = { { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } };

void func_800F65E0_UnusedMinigame0(void) {
    s16 i;
    u8 cam;

    func_80029090(0x32);
    func_8002ADF0(&D_800EDEC0, 0x40);
    func_8001DE70(0x20);
    omInitObjMan(0x32, 0);
    func_80060088();
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    func_800178A0(1);
    cam = func_800178E8();
    func_80017660(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 45.0f, 80.0f, 8000.0f);
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    D_80103D80_UnusedMinigame0 = 0;
    D_80103D82_UnusedMinigame0 = 0;
    D_80103D8A_UnusedMinigame0 = 0x78;
    D_80103D86_UnusedMinigame0 = 0;
    D_80103D84_UnusedMinigame0 = 1;
    D_80103D88_UnusedMinigame0 = 0x708;
    D_80103D96_UnusedMinigame0 = 0;
    D_80103D9E_UnusedMinigame0 = 0;
    D_80103DA2_UnusedMinigame0 = _CheckFlag(0x2B);
    D_80108B80_UnusedMinigame0 = 0;
    D_8010B450_UnusedMinigame0 = 0;
    for (i = 0; i < 256; i++) {
        D_801098C0_UnusedMinigame0[i] = NULL;
    }
    D_80103DA0_UnusedMinigame0 = 0;
    D_800ED440 = 0;
    D_8010AD18_UnusedMinigame0 = omAddObj(1, 0, 0, -1, func_800F6964_UnusedMinigame0);
    D_801098A0_UnusedMinigame0 = omAddObj(2, 0, 0, -1, func_800FADF0_UnusedMinigame0);
    func_800090B8(D_800ED440);
    D_800F2AF8[D_800ED440++] = omAddObj(3, 10, 0, -1, func_800F924C_UnusedMinigame0);
    D_800F3FB0[D_800F2BC0++] = omAddObj(4, 10, 0x32, -1, func_800F6EC0_UnusedMinigame0);
    D_80108C4C_UnusedMinigame0[D_8010B450_UnusedMinigame0++] = omAddObj(5, 1, 0, -1, func_800F9BBC_UnusedMinigame0);
    D_80103D98_UnusedMinigame0 = omAddObj(0, 0, 0, -1, func_800F6DD0_UnusedMinigame0);
    func_800FCF10_UnusedMinigame0(3);
    func_800234B8(0, 0x80, 0x80, 0x80);
    func_800234B8(1, 0xFF, 0xFF, 0xFF);
    func_80023504(1, 0.0f, 64.0f, 192.0f);
    func_8007B168((u8*)"\x82\x65\x82\x68\x82\x6D\x82\x68\x82\x72\x82\x67", 1); /* "ＦＩＮＩＳＨ" (Shift-JIS) */
}

void func_800F6964_UnusedMinigame0(omObjData* obj) {
    obj->func_ptr = func_800F69A0_UnusedMinigame0;
    D_800ED430 = 0;
    SetFadeInTypeAndTime(0, 0x10);
    func_80060128(0x1F);
}

/* The flow: start, play, the time-up / goal messages, coins, and the return. */
void func_800F69A0_UnusedMinigame0(omObjData* obj) {
    s16 mes;

    switch (D_80103D80_UnusedMinigame0) {
        case 0:
            if (--D_80103D8A_UnusedMinigame0 == 0) {
                D_80103D80_UnusedMinigame0++;
                D_80103D8A_UnusedMinigame0 = 0;
            }
            break;
        case 1:
            if (D_80103D82_UnusedMinigame0 != 0) {
                if (D_80103D8A_UnusedMinigame0 == 0) {
                    GMesCreate(0);
                    D_80103D8A_UnusedMinigame0 = 0x3C;
                } else if (--D_80103D8A_UnusedMinigame0 == 0) {
                    D_80103D80_UnusedMinigame0++;
                    D_80103D84_UnusedMinigame0 = 0;
                    D_800ED430 = 1;
                }
            }
            break;
        case 2:
            if (D_80103D84_UnusedMinigame0 == 0) {
                D_80103D88_UnusedMinigame0--;
            }
            if (D_80103D88_UnusedMinigame0 == 0 || D_80103D86_UnusedMinigame0 != 0) {
                if (D_80103DA2_UnusedMinigame0 == 0) {
                    D_80103D80_UnusedMinigame0++;
                    mes = 2;
                    if (D_80103D86_UnusedMinigame0 == 0) {
                        mes = 0x10;
                    }
                } else {
                    D_80103D80_UnusedMinigame0 = 6;
                    mes = 2;
                }
                GMesCreate(mes);
                if (D_80103D9E_UnusedMinigame0 == 0) {
                    func_800601D4(0x28);
                }
                D_800ED430 = 2;
            }
            break;
        case 3:
            if (GMesStatAllGet() == 2) {
                D_80103D80_UnusedMinigame0++;
                if (D_80103D86_UnusedMinigame0 != 0) {
                    if (D_80103D9E_UnusedMinigame0 != 0) {
                        func_80060128(0x33);
                        D_80103D8A_UnusedMinigame0 = 0x24;
                    } else {
                        GwPlayer[D_80103D9C_UnusedMinigame0].coins_mg++;
                        func_80060128(0x35);
                        D_80103D8A_UnusedMinigame0 = 0x5A;
                        D_80103D80_UnusedMinigame0++;
                    }
                } else {
                    func_80060128(0x34);
                    D_80103D8A_UnusedMinigame0 = 0x12;
                }
            }
            break;
        case 4:
            if (--D_80103D8A_UnusedMinigame0 == 0) {
                if (D_80103D86_UnusedMinigame0 != 0) {
                    func_80060468(0x450, GwPlayer[D_80103D9C_UnusedMinigame0].character + 1);
                    D_80103D8A_UnusedMinigame0 = 0x5A;
                } else {
                    func_80060468(0x449, GwPlayer[D_80103D9C_UnusedMinigame0].character + 1);
                    D_80103D8A_UnusedMinigame0 = 0x48;
                }
                D_80103D80_UnusedMinigame0++;
            }
            break;
        case 5:
            if (--D_80103D8A_UnusedMinigame0 == 0) {
                D_80103D80_UnusedMinigame0 = -1;
                D_80103D86_UnusedMinigame0 = -1;
                if (D_80103DA2_UnusedMinigame0 != 0) {
                    func_80060398(0x28);
                }
                func_800726AC(0, 0x14);
            }
            break;
        case 6:
            if (GMesStatAllGet() == 2) {
                D_80103D80_UnusedMinigame0 = 5;
                D_80103D8A_UnusedMinigame0 = 0x3C;
            }
            break;
    }
    if (D_80103D80_UnusedMinigame0 != 0) {
        D_80103D82_UnusedMinigame0 = func_800FDCF8_UnusedMinigame0(D_80103D96_UnusedMinigame0);
    }
    if (D_800F5144 != 0) {
        D_80103D86_UnusedMinigame0 = -1;
    }
    func_800F6D7C_UnusedMinigame0();
}

void func_800F6D7C_UnusedMinigame0(void) {
    if (D_80103D86_UnusedMinigame0 < 0 && func_80072718() == 0) {
        func_800FB650_UnusedMinigame0();
        func_800FD430_UnusedMinigame0();
        func_80060198();
        omOvlReturnEx(1);
    }
}

/* The timer. */
void func_800F6DD0_UnusedMinigame0(omObjData* obj) {
    obj->work[0] = GMesCreate(8, (s16)(D_80103D88_UnusedMinigame0 / 30), 0xA0, 0x18);
    obj->func_ptr = func_800F6E48_UnusedMinigame0;
}

void func_800F6E48_UnusedMinigame0(omObjData* obj) {
    if (D_80103D88_UnusedMinigame0 == 0 || D_80103D86_UnusedMinigame0 != 0) {
        obj->func_ptr = NULL;
        func_800790C0();
        return;
    }
    func_80079078((D_80103D88_UnusedMinigame0 + 29) / 30);
}

/* The player. */
void func_800F6EC0_UnusedMinigame0(omObjData* obj) {
    UM0Work* w;
    s16 i;
    s32 dir;
    s32 file;
    s32 file2;
    u8 chr;
    s32 r;

    for (i = 0; GwPlayer[i].group != 0; i++) {
    }
    D_80103D9C_UnusedMinigame0 = i;
    if (GwPlayer[i].flags & 1) {
        func_800FA4A4_UnusedMinigame0();
    }
    chr = GwPlayer[D_80103D9C_UnusedMinigame0].character;
    dir = D_800C59AC[chr].unk_00;
    file = D_800C59AC[chr].unk_04;
    file2 = D_800C59AC[chr].unk_08;
    func_80009618(1);
    func_8000979C(obj, dir, file, D_80103D9C_UnusedMinigame0, 0x699, 0x699);
    func_80009500();
    func_80008EF0(obj, 9, dir | file2, 0x699, 600.0f);
    func_8009EA40(D_800F2B7C[obj->model[1]].unk7C, 0.0f, 15.0f, 0.0f);
    func_80009340(obj, 2, 0x25, 0x289, 0);
    obj->model[3] = LoadFormFile(0x19, 0x289);
    obj->model[4] = LoadFormFile(0x1A, 0x289);
    obj->model[7] = LoadFormFile(0x1E, 0xA8D);
    obj->model[8] = LoadFormFile(0x1D, 0xA8D);
    func_8001874C(obj, 0, dir, 1, 0);
    func_8001874C(obj, 1, dir | 1, 1, 0);
    func_8001874C(obj, 2, dir | 3, 1, 0);
    func_8001874C(obj, 6, dir | 5, 1, 0x13);
    func_8001874C(obj, 8, dir | 9, 1, 0x1D);
    func_8001874C(obj, 9, dir | 0xA, 1, 0x27);
    func_8001874C(obj, 0x11, dir | 0x18, 0, 0);
    func_8001874C(obj, 0x12, dir | 0x1C, 2, 0);
    func_8001874C(obj, 0x15, dir | 0x62, 0, 0);
    func_8001874C(obj, 3, dir | 0x60, 1, 0);
    func_8001874C(obj, 4, dir | 0x61, 1, 0);
    func_8001874C(obj, 0x20, dir | 0x67, 0, 0);
    r = (s16)((func_800FB6FC_UnusedMinigame0() * 2) >> 16);
    func_8001874C(obj, 0xD, dir | D_80102AF0_UnusedMinigame0[r], 2, 0);
    func_8001874C(obj, 0xE, dir | D_80102B04_UnusedMinigame0[r], 1, 0x78);
    func_8001874C(obj, 0xB, dir | 0xB, 1, 0);
    func_8001874C(obj, 0x23, dir | 0x93, 1, 0);
    obj->func_ptr = func_800F75C0_UnusedMinigame0;
    func_800093FC(obj, 300.0f, 0.0f, -400.0f);
    func_8000941C(obj, 1.0f, 1.0f, 1.0f);
    func_800090C4(obj, 0, 2);
    ((UM0MgWork*)obj->unk_50)->unk_50 |= 0x8000;
    func_800258EC(obj->model[3], 4, 4);
    func_800258EC(obj->model[4], 4, 4);
    w = func_800FB568_UnusedMinigame0(obj);
    w->unk10 = obj->trans.x;
    w->unk14 = obj->trans.y;
    w->unk18 = obj->trans.z;
    D_800B897C = 4.0f;
}

/* cur turned by step towards target (degrees, the short way); target once within step. */
// NON_MATCHING: GCC folds the three fmod-normalise tests differently (one compare fewer); same branches
#ifdef NON_MATCHING
f32 func_800F7320_UnusedMinigame0(f32 cur, f32 target, f32 step) {
    f32 v;

    if (cur == target) {
        return cur;
    }
    if ((func_8009B618(cur - target, 360.0) < 0.0 ? func_8009B618(cur - target, 360.0) + 360.0
                                                  : func_8009B618(cur - target, 360.0)) <= 180.0) {
        v = cur - step;
        if (v < 0.0) {
            v += 360.0;
        }
        if ((func_8009B618(v - target, 360.0) < 0.0 ? func_8009B618(v - target, 360.0) + 360.0
                                                    : func_8009B618(v - target, 360.0)) > 180.0) {
            return target;
        }
        return v;
    }
    v = cur + step;
    if (v >= 360.0) {
        v -= 360.0;
    }
    if ((func_8009B618(v - target, 360.0) < 0.0 ? func_8009B618(v - target, 360.0) + 360.0
                                                : func_8009B618(v - target, 360.0)) <= 180.0) {
        return target;
    }
    return v;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_UnusedMinigame0/FF570", func_800F7320_UnusedMinigame0);
#endif

/* Hides the player's shadows and starts the end camera parts shared by the three endings. */
#define UM0_HIDE_SHADOWS()                                                  \
    {                                                                       \
        s16 k;                                                              \
        for (k = 0; k < 3; k++) {                                           \
            D_800F2B7C[D_80109CC0_UnusedMinigame0[k]].unk_6C->unk_80->unk_14 |= 0x10000; \
            D_800F2B7C[D_80109CC0_UnusedMinigame0[k]].unk_20 |= 0x80;       \
        }                                                                   \
    }

/* The player: intro, walking (or the CPU's moves), pushing an exit gate, reaching the treasure. */
// NON_MATCHING: register allocation and addressing forms (labels vs struct offsets); stores and loads checked against retail
#ifdef NON_MATCHING
void func_800F75C0_UnusedMinigame0(omObjData* obj) {
    UM0MgWork* mg = obj->unk_50;
    UM0Work* w = func_800FB6D0_UnusedMinigame0(obj);
    u8 port;
    u16 prev;
    s16 k;
    s16 e;
    u8 edges;
    f32 dx;
    f32 dz;
    f32 d;
    f32 s;
    f32 a;
    f32 h;
    UM0BoardWork* board;
    Vec2f p;

    if (w->unk0 >= 0) {
        w->unk0 |= 0x80C0;
        w->unk2 = 1;
        w->unk4 = w->unk6 = 4;
        w->unk10 = D_800F2B7C[obj->model[0]].unk_24;
        w->unk14 = D_800F2B7C[obj->model[0]].unk_28;
        w->unk18 = D_800F2B7C[obj->model[0]].unk_2C;
        w->unk40 = 0;
        w->unk42 = D_80102B7C_UnusedMinigame0[GwPlayer[mg->unk_58].character][1];
        w->unk44 = w->unk46 = 0;
        w->unk48 = 0;
        w->unk4A = 0;
        w->unk58 = -1;
        w->unk5C = 0;
        w->unk5E = 0;
        mg->unk_38 = 0;
        func_800184BC(obj, D_80102B7C_UnusedMinigame0[GwPlayer[mg->unk_58].character][0]);
        func_800096B0(mg, 0);
        return;
    }
    port = mg->unk_56;
    switch (w->unk8) {
        case 0:
            switch (w->unk40) {
                case 0:
                    obj->trans.x += -D_80102B18_UnusedMinigame0[0].x * 0.4 * 10.0;
                    obj->trans.z += -D_80102B18_UnusedMinigame0[0].z * 0.4 * 10.0;
                    if (func_80025D18(obj->model[0]) == 0.0f) {
                        func_800096B0(mg, 0);
                    }
                    if (--w->unk42 == 0) {
                        w->unk40++;
                        w->unk42 = 0x10;
                        w->unk44 = 2;
                        D_80103D8C_UnusedMinigame0[0] = 2;
                        func_800184BC(obj, 0);
                    } else {
                        func_800FAE84_UnusedMinigame0(300.0f, obj->trans.x, obj->trans.y + 80.0, obj->trans.z, -10.0f,
                                                      obj->rot.y + 180.0, 0.0f);
                    }
                    break;
                case 1:
                    if (w->unk42 != 0) {
                        if (--w->unk42 == 0) {
                            w->unk20 = w->unk38 = 24.0f;
                            func_800184BC(obj, 9);
                            func_80060540(0x145, 0);
                            func_800FAEC4_UnusedMinigame0(300.0f, 0.0f, 0.0f, 200.0f, -90.0f, 0.0f, 0.0f, 0x20);
                            func_800FAEC4_UnusedMinigame0(1006.0f, 0.0f, 0.0f, 0.0f, -90.0f, 0.0f, 0.0f, 0x20);
                            func_80060F04(D_80103D9C_UnusedMinigame0, 2, 2, 0x14);
                        }
                    } else {
                        obj->trans.z += 4.0;
                        obj->trans.y += w->unk20;
                        w->unk20 += -4.0;
                        if (w->unk20 < 0.0 && obj->trans.y < 0.0) {
                            w->unk14 = 0.0f; /* retail: the work's home y, not trans.y */
                            if (--w->unk44 == 0) {
                                w->unk40++;
                                w->unk42 = 0x20;
                                w->unk1C = w->unk10;
                                w->unk24 = w->unk18;
                                func_800184BC(obj, 0xB);
                                w->unk2C = func_800B0CD8(0.0 - w->unk10, 0.0 - w->unk18);
                            } else {
                                w->unk20 = w->unk38 = w->unk38 / 2.0;
                            }
                        }
                    }
                    break;
                case 2:
                    if (obj->rot.y != w->unk2C) {
                        if (w->unk2C < obj->rot.y) {
                            obj->rot.y -= 4.0;
                            if (obj->rot.y < w->unk2C) {
                                obj->rot.y = w->unk2C;
                            }
                        } else {
                            obj->rot.y += 4.0;
                            if (w->unk2C < obj->rot.y) {
                                obj->rot.y = w->unk2C;
                            }
                        }
                    }
                    if (--w->unk42 == 0) {
                        w->unk40++;
                        func_800184BC(obj, 0x23);
                    }
                    break;
                case 3:
                    if (D_80103D82_UnusedMinigame0 != 0) {
                        w->unk8++;
                        mg->unk_3C = obj->rot.y;
                        func_8009ECB0(D_800F2B7C[obj->model[0]].unk7C, 0.0f, obj->rot.y, 0.0f);
                        obj->rot.y = 0.0f;
                        func_800184BC(obj, 0);
                    }
                    break;
            }
            break;
        case 1:
            prev = mg->unk_50;
            w->unk1C = obj->trans.x;
            w->unk24 = obj->trans.z;
            if (GwPlayer[D_80103D9C_UnusedMinigame0].flags & 1) {
                ContStkY[(s8)port] = 0;
                ContStkX[(s8)port] = 0;
                ContBtnTrg[(s8)port] = 0;
                ContBtn[(s8)port] = 0;
                if (!(w->unk2 & 2)) {
                    if (!(w->unk2 & 8)) {
                        k = w->unk48++;
                        if (w->unk48 > D_80103E18_UnusedMinigame0) {
                            w->unk2 |= 8;
                            w->unk5A = func_800FB904_UnusedMinigame0(&w->unk44, &w->unk46);
                        } else {
                            w->unk44 = (D_80103DB8_UnusedMinigame0[k][0] - 4) * 10.0 * 10.0 + 50.0;
                            w->unk46 = (D_80103DB8_UnusedMinigame0[k][1] - 3) * 10.0 * 10.0 + 50.0;
                        }
                    }
                    w->unk2 |= 2;
                } else if (w->unk2 & 4) {
                    if ((w->unk0 & 0xC) == 4) {
                        if (!(mg->unk_5C & 0x20)) {
                            ContBtnTrg[(s8)port] = ContBtn[(s8)port] = 0x8000;
                        } else if (!(mg->unk_5C & 0x200) && obj->trans.y >= 200.0) {
                            ContBtnTrg[(s8)port] = ContBtn[(s8)port] = 0x2000;
                        }
                    }
                } else {
                    if (!(w->unk2 & 0x80) && w->unk4A < 0x10) {
                        p.x = w->unk44 - obj->trans.x;
                        p.y = w->unk46 - obj->trans.z;
                    } else if (!(w->unk2 & 8)) {
                        if (w->unk44 > 0) {
                            p.x = 100.0f;
                        } else {
                            p.x = -100.0f;
                        }
                        p.x -= obj->trans.x;
                        p.y = 0.0 - obj->trans.z;
                    } else {
                        p.x = D_80102B54_UnusedMinigame0[w->unk5A].x * 10.0 - obj->trans.x;
                        p.y = D_80102B54_UnusedMinigame0[w->unk5A].z * 10.0 - obj->trans.z;
                    }
                    d = sqrtf(p.x * p.x + p.y * p.y) / 10.0;
                    if (d > 8.0) {
                        d = 8.0f;
                    }
                    s = d * 6.0 + 24.0;
                    a = func_800B0CD8(p.x, -p.y);
                    ContStkX[(s8)port] = func_800AEAC0(a) * s;
                    ContStkY[(s8)port] = func_800AEFD0(a) * s;
                    if (d < 2.0) {
                        w->unk2 |= 4;
                    }
                    if (w->unk2 & 0x10) {
                        ContBtnTrg[(s8)port] = ContBtn[(s8)port] = 0x8000;
                    }
                    if (!(w->unk2 & 0x80)) {
                        w->unk4A = 0;
                    } else {
                        w->unk4A++;
                    }
                }
            }
            func_80005A28(obj);
            if (obj->trans.y >= 100.0 && (u8)mg->unk_B2 < 2) {
                func_8006071C(mg->unk_B3);
                if (mg->unk_B2 == 0) {
                    mg->unk_B3 = func_80010ED4(GwPlayer[D_80103D9C_UnusedMinigame0].character + 0x1F7, 0);
                } else {
                    mg->unk_B3 = func_80010ED4(GwPlayer[D_80103D9C_UnusedMinigame0].character + 0x1FE, 0);
                }
                mg->unk_B2 = 14;
            }
            if (~prev & mg->unk_50 & 0x80) {
                if (D_80103D84_UnusedMinigame0 != 0) {
                    goto skip;
                }
                func_800FDC1C_UnusedMinigame0(obj->trans.x / 100.0 + 4.0, obj->trans.z / 100.0 + 3.0);
                w->unk2 &= 0xFFF9;
            }
            if (D_80103D84_UnusedMinigame0 == 0 && D_80103D88_UnusedMinigame0 == 0) {
                w->unk2 |= 0x40;
                D_80103D84_UnusedMinigame0 = 1;
            }
        skip:
            if ((w->unk2 & 0x40) && !(mg->unk_5C & 0x220)) {
                w->unk8 = 4;
                w->unk40 = 0;
                w->unk42 = 0;
                D_80103D96_UnusedMinigame0 = 1;
                func_80025F60(obj->model[0], 0);
                func_80025F60(obj->model[9], 0);
                UM0_HIDE_SHADOWS();
                func_800A2A50(D_800F2B7C[obj->model[0]].unk7C);
                obj->rot.y = mg->unk_3C;
                if (obj->rot.y < 0.0f) {
                    obj->rot.y += 360.0;
                }
                a = func_800B0CD8(0.0 - obj->trans.x, 0.0 - obj->trans.z);
                h = (func_800FC944_UnusedMinigame0(obj->trans.x / 10.0, obj->trans.z / 10.0) + 8.0) * 10.0;
                func_800FAEC4_UnusedMinigame0(300.0f, 0.0f, h, 0.0f, -90.0f, 0.0f, 0.0f, 0x20);
                func_800FAEC4_UnusedMinigame0(300.0f, obj->trans.x, h, obj->trans.z, -20.0f, a, 0.0f, 0);
            }
            edges = func_800FB734_UnusedMinigame0(obj);
            if (edges != 0 && !(mg->unk_5C & 0x220) && obj->trans.y == 0.0) {
                e = func_800FB810_UnusedMinigame0(obj->trans.x, obj->trans.z, edges);
                if (e > 0 && D_801098B4_UnusedMinigame0[e] != 0) {
                    if (w->unk5E < 0) {
                        w->unk5C = 0;
                        w->unk5E = e;
                    } else if (D_80103D84_UnusedMinigame0 == 0 && ++w->unk5C >= 4) {
                        w->unk8 = 2;
                        w->unk40 = 1;
                        w->unk42 = 0x10;
                        w->unk5A = e;
                        func_800184BC(obj, 1);
                        func_800096B0(mg, 0);
                        D_800ED430 = 2;
                        func_800A2A50(D_800F2B7C[obj->model[0]].unk7C);
                        obj->rot.x = 0.0f;
                        obj->rot.y = D_80102B40_UnusedMinigame0[e];
                        obj->rot.z = 0.0f;
                        func_800FAEC4_UnusedMinigame0(300.0f, 0.0f, 0.0f, 0.0f, -90.0f, 0.0f, 0.0f, 0x14);
                        func_800FAEC4_UnusedMinigame0(400.0f, obj->trans.x, obj->trans.y + 80.0, obj->trans.z, -5.0f,
                                                      obj->rot.y - 180.0, 0.0f, 0);
                        D_80103D84_UnusedMinigame0 = 1;
                        D_80103D96_UnusedMinigame0 = 1;
                        func_80025F60(obj->model[0], 0);
                        func_80025F60(obj->model[9], 0);
                        UM0_HIDE_SHADOWS();
                        D_80103D86_UnusedMinigame0 = 1;
                    }
                } else {
                    w->unk5E = -1;
                }
            } else {
                w->unk5E = -1;
            }
            if (D_80103D84_UnusedMinigame0 == 0 && obj->trans.y < 100.0) {
                k = func_800FCA40_UnusedMinigame0(obj, obj->trans.x - w->unk1C, obj->trans.z - w->unk24, w->unk4 * 10.0);
                if (k >= 0 && D_80108C4C_UnusedMinigame0[k]->work[0] == 0 && w->unk58 < 0 && obj->trans.y < 100.0) {
                    w->unk2 |= 0x20;
                    w->unk58 = k;
                    GwPlayer[D_80103D9C_UnusedMinigame0].coins_mg += 10;
                    D_80103D9E_UnusedMinigame0 = 1;
                    D_80103D84_UnusedMinigame0 = 1;
                    func_80060F04(D_80103D9C_UnusedMinigame0, 0x14, 0, 0x14);
                }
            }
            if ((w->unk2 & 0x20) && !(mg->unk_5C & 0x220)) {
                D_80103D8C_UnusedMinigame0[1] = D_80103D8C_UnusedMinigame0[2] = D_80103D8C_UnusedMinigame0[4] = 2;
                func_800FAEC4_UnusedMinigame0(300.0f, 0.0f, 0.0f, 0.0f, -90.0f, 0.0f, 0.0f, 0x28);
                func_800FAEC4_UnusedMinigame0(400.0f, -300.0f, 80.0f, 200.0f, -5.0f, 180.0f, 0.0f, 0);
                D_80103D96_UnusedMinigame0 = 1;
                func_800A2A50(D_800F2B7C[obj->model[0]].unk7C);
                func_80025F60(obj->model[0], 0);
                func_80025F60(obj->model[9], 0);
                UM0_HIDE_SHADOWS();
                w->unk8 = 3;
                w->unk40 = 0;
                w->unk42 = 0x10;
            }
            break;
        case 2:
            switch (w->unk40) {
                case 0:
                    obj->trans.x += D_80102B18_UnusedMinigame0[w->unk5A].x * 0.8 * 10.0;
                    obj->trans.z += D_80102B18_UnusedMinigame0[w->unk5A].z * 0.8 * 10.0;
                    obj->rot.y = func_800F7320_UnusedMinigame0(obj->rot.y, D_80102B40_UnusedMinigame0[w->unk5E], 20.0f);
                    if (--w->unk42 == 0) {
                        w->unk40++;
                        w->unk42 = 0x10;
                        func_800184BC(obj, 0);
                    }
                    if (func_80025D18(obj->model[0]) == 0.0f) {
                        func_800096B0(mg, 0);
                    }
                    break;
                case 1:
                    if (--w->unk42 == 0) {
                        w->unk40++;
                        w->unk42 = 0x78;
                        if (D_80103D9E_UnusedMinigame0 == 0) {
                            w->unk42 = 0x20;
                        }
                        func_800184BC(obj, 1);
                        func_800096B0(mg, 0);
                    }
                    break;
                case 2:
                    obj->trans.x += -D_80102B18_UnusedMinigame0[w->unk5A].x * 0.4 * 10.0;
                    obj->trans.z += -D_80102B18_UnusedMinigame0[w->unk5A].z * 0.4 * 10.0;
                    if (--w->unk42 == 0) {
                        func_800184BC(obj, 0);
                        w->unk40++;
                        w->unk42 = 0x20;
                        w->unk56 = func_8009B618(D_80102B40_UnusedMinigame0[w->unk5E] + 180.0, 360.0);
                    }
                    if (func_80025D18(obj->model[0]) == 0.0f) {
                        func_800096B0(mg, 0);
                    }
                    break;
                case 3:
                    obj->rot.y = func_800F7320_UnusedMinigame0(obj->rot.y, w->unk56, 20.0f);
                    if (--w->unk42 == 0) {
                        w->unk40++;
                        w->unk42 = 8;
                        D_80103D8C_UnusedMinigame0[w->unk5A] = 2;
                    }
                    break;
                case 4:
                    if (--w->unk42 == 0) {
                        w->unk40 = -1;
                        D_800F2B7C[obj->model[0]].unk_20 |= 4;
                    }
                    break;
            }
            break;
        case 3:
            switch (w->unk40) {
                case 0:
                    p.x = -300.0 - obj->trans.x;
                    p.y = 200.0 - obj->trans.z;
                    d = sqrtf(p.x * p.x + p.y * p.y);
                    if (d < 10.0) {
                        func_800184BC(obj, 0);
                        if (--w->unk42 == 0) {
                            w->unk40++;
                            D_80108C4C_UnusedMinigame0[w->unk58]->work[2] = 1;
                            func_800601D4(0x28);
                        }
                    } else {
                        obj->trans.x += p.x / d * 6.0;
                        obj->trans.z += p.y / d * 6.0;
                        func_800184BC(obj, 1);
                        func_800096B0(mg, 0);
                    }
                    p.x = D_80108C4C_UnusedMinigame0[0]->trans.x - obj->trans.x;
                    p.y = D_80108C4C_UnusedMinigame0[0]->trans.z - obj->trans.z;
                    func_800B0CD8(p.x, p.y);
                    obj->rot.y = func_800F7320_UnusedMinigame0(obj->rot.y, 0.0f, 10.0f);
                    break;
                case 1:
                    if (D_80103D80_UnusedMinigame0 == 4) {
                        w->unk40++;
                        w->unk42 = 0x42;
                        w->unk56 = 8;
                        func_800184BC(obj, 0xD);
                        w->unk2C = obj->rot.y;
                    }
                    break;
                case 2:
                    if (w->unk56 != 0) {
                        w->unk56--;
                        obj->rot.y = w->unk2C + (f32)(s16)(8 - w->unk56) / 8.0 * (180.0 - w->unk2C);
                    }
                    if (--w->unk42 == 0) {
                        w->unk8 = 2;
                        w->unk40 = 0;
                        w->unk42 = 0x18;
                        w->unk44 = 3;
                        D_80103D8C_UnusedMinigame0[3] = 1;
                        func_800184BC(obj, 1);
                        func_800096B0(mg, 0);
                        w->unk5E = 3;
                    }
                    break;
            }
            break;
        case 4:
            obj->rot.y = func_800F7320_UnusedMinigame0(obj->rot.y, func_800B0CD8(0.0 - obj->trans.x, 0.0 - obj->trans.z), 20.0f);
            func_800184BC(obj, 0xE);
            break;
    }
    w->unk2 &= 0xFF6F;
    board = D_800F2AF8[0]->unk_50;
    p.x = obj->trans.x / 10.0;
    p.y = obj->trans.z / 10.0;
    func_800FBFE4_UnusedMinigame0(D_800F2AF8[0]);
    if (func_800FC564_UnusedMinigame0(&p.x, &p.y, w->unk4)) {
        w->unk2 |= 0x80;
    }
    obj->trans.x = p.x * 10.0;
    obj->trans.z = p.y * 10.0;
    if (obj->trans.y < 100.0) {
        func_800FBB18_UnusedMinigame0(p.x, p.y);
        if (func_800FC564_UnusedMinigame0(&p.x, &p.y, func_800AEAC0((100.0 - obj->trans.y) / 100.0 * 90.0) * w->unk4)) {
            w->unk2 |= 0x10;
        }
        obj->trans.x = p.x * 10.0;
        obj->trans.z = p.y * 10.0;
    }
    h = func_800FC944_UnusedMinigame0(p.x, p.y);
    board->unk_10 = h * 10.0;
    if (obj->trans.y < h * 10.0) {
        obj->trans.y = h * 10.0;
    }
    func_80025798(obj->model[1], obj->trans.x, h * 10.0, obj->trans.z);
    func_800258EC(obj->model[1], 4, 0);
    if (w->unk8 != 1) {
        func_80017DB0(obj);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_UnusedMinigame0/FF570", func_800F75C0_UnusedMinigame0);
#endif

/* The stage: the room models, the gates (models 1..4), and the three pick-ups. */
void func_800F924C_UnusedMinigame0(omObjData* obj) {
    UM0BoardWork* bw;
    omObjData* o;
    s16 i;

    obj->func_ptr = func_800F95C0_UnusedMinigame0;
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    for (i = 0; i < 10; i++) {
        obj->model[i] = func_800174C0(D_80102B94_UnusedMinigame0[i] | 0x180000, 0xA9);
        func_80025798(obj->model[i], obj->trans.x, obj->trans.y, obj->trans.z);
        func_80025830(obj->model[i], obj->scale.x, obj->scale.y, obj->scale.z);
        if (i == 1) {
            func_80025798(obj->model[1], 0.0f, 400.0f, 0.0f);
        }
        if (i >= 6) {
            func_80021240(obj->model[i]);
            func_800211BC(obj->model[i], 0);
            D_800F2B7C[obj->model[i]].unk_20 |= 4;
        }
        func_80025B34(obj->model[i]);
    }
    D_80103D8C_UnusedMinigame0[0] = 1;
    D_801098B4_UnusedMinigame0[0] = 1;
    for (i = 1; i < 5; i++) {
        D_80103D8C_UnusedMinigame0[i] = 0;
        D_801098B4_UnusedMinigame0[i] = 0;
    }
    bw = obj->unk_50 = func_80023684(0x2C, 0x7918);
    func_8009B770(bw, 0, 0x2C);
    bw->unk_04 = 1;
    bw->unk_05 = 0;
    func_80009028(obj, 0, -2000.0f, -2000.0f, 2000.0f, 2000.0f);
    for (i = 0; i < 3; i++) {
        o = omAddObj(5, 2, 0, -1, func_800F9F04_UnusedMinigame0);
        D_800EDE70[D_800EE984++] = o;
        o->trans.x = D_80102BA8_UnusedMinigame0[i][0] * 10.0;
        o->trans.y = 40.0f;
        o->trans.z = D_80102BA8_UnusedMinigame0[i][1] * 10.0;
        o->rot.y = D_80102BA8_UnusedMinigame0[i][2];
        o->work[3] = 0;
    }
}

/* Opens (state 1) and closes (state 2) the entrance lift (slot 0) and the gates (slots 1..4). */
// NON_MATCHING: switch compare tree and register allocation
#ifdef NON_MATCHING
void func_800F95C0_UnusedMinigame0(omObjData* obj) {
    s16 i;
    u8 m;
    unk2C0C0Struct50* node;
    f32 v;

    for (i = 0; i < 5; i++) {
        m = obj->model[i + 1];
        node = D_800F2B7C[m].unk_6C->unk_A0;
        if ((D_80103D84_UnusedMinigame0 == 0) & (i != 0) && i != 3) {
            if (D_80108B50_UnusedMinigame0[D_80102BBC_UnusedMinigame0[i][0]][D_80102BBC_UnusedMinigame0[i][1]] == 0 &&
                D_80108B50_UnusedMinigame0[D_80102BBC_UnusedMinigame0[i][2]][D_80102BBC_UnusedMinigame0[i][3]] == 0) {
                D_80103D8C_UnusedMinigame0[i] = 1;
            } else {
                D_80103D8C_UnusedMinigame0[i] = 2;
            }
        }
        switch (D_80103D8C_UnusedMinigame0[i]) {
            case 1:
                if (i == 0) {
                    v = D_800F2B7C[m].unk_28;
                    if (v == 0.0) {
                        PlaySound(0x19A);
                    }
                    if (v < 400.0) {
                        v += 25.0;
                        if (v >= 400.0) {
                            v = 400.0f;
                            D_80103D8C_UnusedMinigame0[i] = 0;
                        }
                        func_80025798(m, 0.0f, v, 0.0f);
                    }
                } else {
                    if (D_801098B4_UnusedMinigame0[i] == 0) {
                        D_800F2B7C[obj->model[i + 5]].unk_20 &= ~4;
                    }
                    v = node->unk_44.y;
                    if (v == 0.0) {
                        PlaySound(i != 3 ? 0x1F2 : 0x198);
                    }
                    if (v < 120.0) {
                        v += 10.0;
                        if (v >= 100.0) {
                            v = 100.0f;
                            D_80103D8C_UnusedMinigame0[i] = 0;
                        }
                        node->unk_44.y = v;
                        guTranslateF(node->unk_64, node->unk_08.x, node->unk_08.y, node->unk_08.z);
                        MtxRotate(node->unk_64, 0.0f, node->unk_44.y, 0.0f);
                    }
                    func_800211BC(obj->model[i + 5], (u32)(v * 2.125));
                }
                D_801098B4_UnusedMinigame0[i] = 1;
                break;
            case 2:
                if (i == 0) {
                    v = D_800F2B7C[m].unk_28;
                    if (v > 0.0) {
                        v -= 25.0;
                        if (v <= 0.0) {
                            v = 0.0f;
                            D_80103D8C_UnusedMinigame0[0] = 0;
                            PlaySound(0x19E);
                        }
                        func_80025798(m, 0.0f, v, 0.0f);
                    }
                } else {
                    v = node->unk_44.y;
                    if (v > 0.0) {
                        v -= 10.0;
                        if (v <= 0.0) {
                            v = 0.0f;
                            D_80103D8C_UnusedMinigame0[i] = 0;
                            PlaySound(0x1F4);
                        }
                        node->unk_44.y = v;
                        guTranslateF(node->unk_64, node->unk_08.x, node->unk_08.y, node->unk_08.z);
                        MtxRotate(node->unk_64, 0.0f, node->unk_44.y, 0.0f);
                        D_800F2B7C[obj->model[i + 5]].unk_20 |= 4;
                    }
                    func_800211BC(obj->model[i + 5], (u32)(v * 2.125));
                }
                D_801098B4_UnusedMinigame0[i] = 0;
                break;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_UnusedMinigame0/FF570", func_800F95C0_UnusedMinigame0);
#endif

/* The treasure chest. */
void func_800F9BBC_UnusedMinigame0(omObjData* obj) {
    omObjData* o;
    s16 i;
    UM0Vec2 p;

    p.x = -35.0f;
    p.z = 25.0f;
    obj->func_ptr = func_800F9DB4_UnusedMinigame0;
    obj->trans.x = p.x * 10.0;
    obj->trans.y = 0.0f;
    obj->trans.z = p.z * 10.0;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    obj->rot.y = 180.0f;
    obj->model[0] = func_800174C0(0x180006, 0x99);
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80025830(obj->model[0], 2.0f, 2.0f, 2.0f);
    D_800F2B7C[obj->model[0]].unk_4C = 0.0f;
    obj->work[0] = 0;
    obj->work[2] = 0;
    obj->work[3] = (u8)D_80103DA0_UnusedMinigame0;
    for (i = 0; i < 10; i++) {
        o = omAddObj(5, 2, 0, -1, func_800F9F04_UnusedMinigame0);
        D_800EDE70[D_800EE984++] = o;
        o->trans.x = obj->trans.x;
        o->trans.y = obj->trans.y + 40.0;
        o->trans.z = obj->trans.z;
        o->work[1] = i * 4;
        o->work[3] = 1;
    }
}

void func_800F9DB4_UnusedMinigame0(omObjData* obj) {
    switch (obj->work[0]) {
        case 0:
            if (obj->work[2] != 0) {
                obj->work[0]++;
                obj->work[1] = 0x20;
                D_800F2B7C[obj->model[0]].unk_4C = 1.0f;
                PlaySound(0x196);
            }
            break;
        case 1:
            if (--obj->work[1] == 0) {
                obj->work[0]++;
                obj->work[1] = 0x10;
                obj->work[2] |= 0x80;
            }
            break;
        case 2:
            if (--obj->work[1] == 0) {
                obj->work[0] = 0xFF;
            } else {
                D_800F2B7C[obj->model[0]].unk_20 ^= 4;
            }
            if (obj->work[1] == 6) {
                D_80103D86_UnusedMinigame0 = 1;
            }
            break;
    }
}

/* A coin: the three on the floor (work[3] 0) and the ten in the chest (work[3] 1). */
void func_800F9F04_UnusedMinigame0(omObjData* obj) {
    UM0ItemWork* iw;

    obj->unk_50 = func_80023684(0x6C, 0x7918);
    func_8009B770(obj->unk_50, 0, 0x6C);
    obj->func_ptr = func_800FA024_UnusedMinigame0;
    iw = obj->unk_50;
    func_800091BC(obj, 0x21, 0x289, 8);
    if (obj->work[3] != 0) {
        D_800F2B7C[obj->model[0]].unk_20 |= 4;
    } else {
        func_80025930(obj->model[0], 0x70000000, 0);
    }
    func_80009340(obj, 1, 0x2A, 0x68D, 8);
    func_8001E2F8(iw->unk_22, 0xC0);
    func_8001E360(iw->unk_22, 0xFF, 0xFF, 0xBE);
    func_8000941C(obj, 1.5f, 1.5f, 1.5f);
    obj->work[0] = 0;
    D_80103DA0_UnusedMinigame0++;
}

// NON_MATCHING: register allocation; GCC drops some double conversions
#ifdef NON_MATCHING
void func_800FA024_UnusedMinigame0(omObjData* obj) {
    UM0ItemWork* iw = obj->unk_50;
    omObjData* pl = D_800F3FB0[0];
    f32 dx;
    f32 dy;
    f32 dz;
    f32 r;
    s16 light;

    if (obj->work[3] == 0) {
        dx = D_800C3110->pos.x - obj->trans.x;
        dy = D_800C3110->pos.y - obj->trans.y;
        dz = D_800C3110->pos.z - obj->trans.z;
        obj->rot.x = func_800B0CD8(dy, sqrtf(dx * dx + dz * dz));
    }
    switch (obj->work[0]) {
        case 0:
            if (obj->work[3] == 0) {
                dx = pl->trans.x - obj->trans.x;
                dz = pl->trans.z - obj->trans.z;
                if (sqrtf(dx * dx + dz * dz) < 100.0) {
                    obj->work[0]++;
                    obj->work[1] = 0x20;
                    dx = pl->trans.x - obj->trans.x;
                    dz = pl->trans.z - obj->trans.z;
                    iw->unk_3C = -func_800B0CD8(dz, -dx);
                    iw->unk_34 = sqrtf(dx * dx + dz * dz);
                    iw->unk_38 = obj->trans.y;
                }
            } else if (D_80108C4C_UnusedMinigame0[0]->work[2] & 0x80) {
                if (obj->work[1] == 0) {
                    obj->work[0]++;
                    obj->work[1] = 0x20;
                    dx = pl->trans.x - obj->trans.x;
                    dz = pl->trans.z - obj->trans.z;
                    iw->unk_3C = -func_800B0CD8(dz, -dx);
                    iw->unk_34 = sqrtf(dx * dx + dz * dz);
                    iw->unk_38 = obj->trans.y;
                    D_800F2B7C[obj->model[0]].unk_20 &= ~4;
                } else {
                    obj->work[1]--;
                }
            }
            break;
        case 1:
            r = (f32)obj->work[1] / 32.0 * iw->unk_34;
            obj->trans.x = func_800AEFD0(iw->unk_3C) * r + pl->trans.x;
            obj->trans.z = func_800AEAC0(iw->unk_3C) * r + pl->trans.z;
            obj->trans.y = iw->unk_38 + func_800AEAC0((f32)(0x20 - obj->work[1]) * 4.21875) * 10.0 * 10.0;
            iw->unk_3C += 22.5;
            if (--obj->work[1] == 0) {
                obj->work[0]++;
                PlaySound(0xFC);
                D_800F2B7C[obj->model[0]].unk_20 |= 4;
                D_800F2B7C[obj->model[1]].unk_20 &= ~4;
                light = iw->unk_22;
                func_8001E2A8(light, 0);
                func_8001E268(light, 6, 6);
                func_80025798(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
                func_80025830(obj->model[1], 3.0f, 3.0f, 3.0f);
                func_80025830(obj->model[1], 6.0f, 6.0f, 6.0f);
                iw->unk_54 = 0;
            }
            break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_UnusedMinigame0/FF570", func_800FA024_UnusedMinigame0);
#endif

/* The CPU's plan: (5 - difficulty / 2) random moves, then a search for the treasure's way out. */
// NON_MATCHING: register allocation; move bytes stored through the DB9 label
#ifdef NON_MATCHING
void func_800FA4A4_UnusedMinigame0(void) {
    u8 board[8][6];
    s16 x;
    s16 z;
    s16 n = 5 - (GwPlayer[D_80103D9C_UnusedMinigame0].cpu_difficulty >> 1);
    s16 i;
    UM0State* st;

    D_80103DA4_UnusedMinigame0 = HuMemDirectMalloc(0x927C0);
    D_80103DAC_UnusedMinigame0 = HuMemDirectMalloc(0x9C40);
    func_801025B8_UnusedMinigame0(board);
    for (i = 0; i < n; i++) {
        if (!func_800FACA0_UnusedMinigame0(board, &x, &z)) {
            break;
        }
        func_80102634_UnusedMinigame0(board, x, z);
        D_80103DB8_UnusedMinigame0[D_80103E18_UnusedMinigame0][0] = x;
        D_80103DB8_UnusedMinigame0[D_80103E18_UnusedMinigame0][1] = z;
        D_80103E18_UnusedMinigame0++;
    }
    if (i == n) {
        while (TRUE) {
            func_800FA968_UnusedMinigame0(board);
            st = func_800FABF0_UnusedMinigame0();
            if (st == NULL) {
                break;
            }
            D_80103DB8_UnusedMinigame0[D_80103E18_UnusedMinigame0][0] = st->x;
            D_80103DB8_UnusedMinigame0[D_80103E18_UnusedMinigame0][1] = st->z;
            func_800FA678_UnusedMinigame0(st->board, board);
            D_80103E18_UnusedMinigame0++;
        }
    }
    HuMemDirectFree(D_80103DA4_UnusedMinigame0);
    HuMemDirectFree(D_80103DAC_UnusedMinigame0);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_UnusedMinigame0/FF570", func_800FA4A4_UnusedMinigame0);
#endif

/* Copies a board, clearing the visited bits. */
void func_800FA678_UnusedMinigame0(u8 src[8][6], u8 dst[8][6]) {
    s16 i;
    s16 j;

    for (j = 0; j < 6; j++) {
        for (i = 0; i < 8; i++) {
            dst[i][j] = src[i][j] & 0x7F;
        }
    }
}

/* The direction of a neighbour of (x, z) that holds val, or -1. */
// NON_MATCHING: branch layout of the neighbour test
#ifdef NON_MATCHING
s16 func_800FA6F8_UnusedMinigame0(u8 board[8][6], s16 x, s16 z, u8 val) {
    s16 d;
    u32 nx;
    u32 nz;

    if (val != 0 && !(val & 0x80)) {
        for (d = 0; d < 4; d++) {
            nx = x + D_80102BE4_UnusedMinigame0[d][0];
            if (nx < 8) {
                nz = z + D_80102BE4_UnusedMinigame0[d][1];
                if (nz < 6 && board[nx][nz] == val) {
                    return d;
                }
            }
        }
    }
    return -1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_UnusedMinigame0/FF570", func_800FA6F8_UnusedMinigame0);
#endif

/* Walks the piece at (x, z) (marking it) and returns a random other cell of it in (x, z). */
// NON_MATCHING: branch layout of the stack pop
#ifdef NON_MATCHING
void func_800FA7A8_UnusedMinigame0(u8 board[8][6], s16* x, s16* z) {
    u8 stack[48][2];
    u8 cells[48][2];
    u8 val = board[*x][*z];
    s16 n = 0;
    s16 sp = 1;
    u16 cx;
    u16 cz;
    s16 d;
    u8* c;

    stack[0][0] = *x;
    stack[0][1] = *z;
    cx = *x;
    cz = *z;
    do {
        board[(s16)cx][(s16)cz] |= 0x80;
        d = func_800FA6F8_UnusedMinigame0(board, cx, cz, val);
        if (d >= 0) {
            cx += D_80102BE4_UnusedMinigame0[d][0];
            cz += D_80102BE4_UnusedMinigame0[d][1];
            stack[sp][0] = cx;
            stack[sp][1] = cz;
            sp++;
            cells[n][0] = cx;
            cells[n][1] = cz;
            n++;
        } else if (--sp >= 0) {
            cx = stack[sp][0];
            cz = stack[sp][1];
        }
    } while (sp >= 0);
    c = cells[(s32)(func_800FB6FC_UnusedMinigame0() * n) >> 16];
    *x = c[0];
    *z = c[1];
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_UnusedMinigame0/FF570", func_800FA7A8_UnusedMinigame0);
#endif

void func_800FA968_UnusedMinigame0(u8 board[8][6]) {
    UM0State* s;

    D_80103DA8_UnusedMinigame0 = 0;
    D_80103DB0_UnusedMinigame0 = 0;
    D_80103DB2_UnusedMinigame0 = 0;
    D_80103DA8_UnusedMinigame0 = 1;
    s = D_80103DA4_UnusedMinigame0;
    s->parent = NULL;
    s->children = 0;
    s->cost = 0x30;
    func_800FA678_UnusedMinigame0(board, s->board);
    func_800FA9D0_UnusedMinigame0(s);
}

/* Expands s by every possible move, 4 deep; the leaves are kept for func_800FABF0. */
void func_800FA9D0_UnusedMinigame0(UM0State* s) {
    UM0State* n = NULL;
    s16 i;
    s16 j;
    s16 x;
    s16 z;

    D_80103DB2_UnusedMinigame0++;
    for (j = 0; j < 6; j++) {
        for (i = 0; i < 8; i++) {
            if (func_800FA6F8_UnusedMinigame0(s->board, i, j, s->board[i][j]) >= 0) {
                n = &D_80103DA4_UnusedMinigame0[D_80103DA8_UnusedMinigame0++];
                func_800FA678_UnusedMinigame0(s->board, n->board);
                n->cost = func_80102634_UnusedMinigame0(n->board, i, j);
                x = i;
                z = j;
                func_800FA7A8_UnusedMinigame0(s->board, &x, &z);
                n->x = x;
                n->z = z;
                n->parent = s;
                n->children = 0;
                s->children++;
                if (D_80103DB2_UnusedMinigame0 < 4) {
                    func_800FA9D0_UnusedMinigame0(n);
                } else {
                    D_80103DAC_UnusedMinigame0[D_80103DB0_UnusedMinigame0++] = n;
                }
            }
        }
    }
    if (n == NULL) {
        D_80103DAC_UnusedMinigame0[D_80103DB0_UnusedMinigame0++] = s;
    }
    D_80103DB2_UnusedMinigame0--;
}

/* The first move towards the cheapest leaf, or NULL at the root. */
// NON_MATCHING: register allocation of the table base/index after the search loop (masked 0, raw 5); tried s reuse in the loop, *(base + bi)
#ifdef NON_MATCHING
UM0State* func_800FABF0_UnusedMinigame0(void) {
    u8 best = 0xFF;
    s32 bi = 0;
    s32 i;
    s8 c;
    UM0State* s;
    UM0State* parent;

    for (i = 0; i < D_80103DB0_UnusedMinigame0; i++) {
        s = D_80103DAC_UnusedMinigame0[i];
        c = s->cost;
        if (c < best) {
            best = c;
            bi = i;
        }
    }
    s = D_80103DAC_UnusedMinigame0[bi];
    parent = s->parent;
    if (parent == NULL) {
        return NULL;
    }
    while (parent->parent != NULL) {
        s = s->parent;
        parent = s->parent;
    }
    return s;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_UnusedMinigame0/FF570", func_800FABF0_UnusedMinigame0);
#endif

/* A random movable cell. */
s32 func_800FACA0_UnusedMinigame0(u8 board[8][6], s16* x, s16* z) {
    u8 cand[48][2];
    s16 n = 0;
    s16 i;
    s16 j;
    u8* c;

    for (j = 0; j < 6; j++) {
        for (i = 0; i < 8; i++) {
            if (func_800FA6F8_UnusedMinigame0(board, i, j, board[i][j]) >= 0) {
                cand[n][0] = i;
                cand[n][1] = j;
                n++;
            }
        }
    }
    if (n != 0) {
        c = cand[(s32)(func_800FB6FC_UnusedMinigame0() * n) >> 16];
        *x = c[0];
        *z = c[1];
        return 1;
    }
    return 0;
}
