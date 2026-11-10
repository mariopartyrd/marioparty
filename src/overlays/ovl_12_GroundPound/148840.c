#include "GroundPound.h"

/* CPU chance (of 256) to aim at a kind-1 hole, and (of 1024) to give up a dash, by difficulty. */
u8 D_800FA1C0_GroundPound[4] = { 0x80, 0x54, 0x2A, 0x00 };
u8 D_800FA1C4_GroundPound[4] = { 0x00, 0x2A, 0x54, 0x80 };
u8 D_800FA1C8_GroundPound[8] = { 0 }; /* unreferenced */
u32 D_800FA1D0_GroundPound = 0; /* func_800F9F18's seed */

/* NON_MATCHING: register allocation only (obj and file1/anim swap s1/s2); masked 0. */
#ifdef NON_MATCHING
void func_800F8C20_GroundPound(omObjData* obj) {
    unkGlobalStruct_00* w;
    s32 dir;
    s32 file1; /* also the animation id below */
    s32 player; /* also the random value below */
    u8 chr;

    D_800FA2D0_GroundPound = 0;
    D_800FA310_GroundPound = 0;
    D_800FA2D8_GroundPound = 0;
    for (player = 0; player < 4; player++) {
        if (GwPlayer[player].group == 0) {
            break;
        }
    }
    if (!(player < 4)) {
        player = 0;
    }
    chr = GwPlayer[player].character;
    dir = D_800C59AC[chr].unk_00;
    file1 = D_800C59AC[chr].unk_08;
    func_80009618(1);
    func_8000979C(obj, dir, file1, player, 0x699, 0x689);
    obj->scale.x *= 1.3f;
    obj->scale.y *= 1.3f;
    obj->scale.z *= 1.3f;
    obj->model[3] = LoadFormFile(0x19, 0x68D);
    obj->model[4] = LoadFormFile(0x1A, 0x68D);
    obj->model[5] = LoadFormFile(0x1C, 0x68D);
    obj->model[7] = LoadFormFile(0x1E, 0x68D);
    obj->model[8] = LoadFormFile(0x1D, 0x68D);
    w = obj->unk_50;
    omSetTra(obj, D_800FA36C_GroundPound.x, D_800FA36C_GroundPound.y, D_800FA36C_GroundPound.z);
    D_800B895C = 10.0f;
    func_8001874C(obj, 0, dir, 1, 0);
    func_8001874C(obj, 1, dir | 1, 1, 0);
    func_8001874C(obj, 2, dir | 3, 1, 0);
    func_8001874C(obj, 6, dir | 5, 1, 0x13);
    func_8001874C(obj, 8, dir | 9, 1, 0x1D);
    func_8001874C(obj, 9, dir | 0xA, 1, 0x27);
    func_8001874C(obj, 0x11, dir | 0x18, 0, 0xE);
    func_8001874C(obj, 0x12, dir | 0x1C, 2, 0);
    func_8001874C(obj, 0x13, dir | 0x1D, 2, 0);
    func_8001874C(obj, 0xA, dir | 0x1E, 1, 0x27);
    func_8001874C(obj, 0x15, dir | 0x62, 0, 0);
    func_8001874C(obj, 3, dir | 0x60, 1, 0);
    func_8001874C(obj, 4, dir | 0x61, 1, 0);
    func_8001874C(obj, 0x10, dir | 0x17, 1, 0);
    func_8001874C(obj, 0x1E, dir | 0x63, 0, 0);
    func_8001874C(obj, 0x1F, dir | 0x64, 0, 0);
    file1 = 0x38;
    player = func_800F9FEC_GroundPound();
    if (player & 1) {
        file1 = 0xF;
    }
    func_8001874C(obj, 0xD, dir | file1, 1, 0x77);
    file1 = (player & 8) ? 0x10 : 0x3C;
    func_8001874C(obj, 0xE, dir | file1, 1, 0x78);
    func_8001874C(obj, 0x17, dir | 0x49, 1, 0);
    func_800090C4(obj, 0, 2);
    D_800F3FB0[D_800F2BC0++] = obj;
    func_800184BC(obj, 1);
    if (GwPlayer[w->unk_58].flags & 1) {
        D_800FA2D6_GroundPound = w->unk_56;
        D_800FA2D4_GroundPound = 0;
        func_800F9908_GroundPound(obj);
    }
    w->unk_DC = NULL;
    D_800FA2E0_GroundPound = 10;
    obj->func_ptr = &func_800F9094_GroundPound;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_12_GroundPound/148840", func_800F8C20_GroundPound);
#endif

void func_800F9094_GroundPound(omObjData* obj) {
    unkGlobalStruct_00* w = obj->unk_50;

    if (D_800ED430 == 1 && D_800FA2D0_GroundPound != 0) {
        if (--D_800FA2D0_GroundPound == 0) {
            func_800184BC(obj, 0);
        }
    }
    if ((GwPlayer[w->unk_58].flags & 1) && D_800ED430 == 1) {
        func_800F9B18_GroundPound(obj);
    }
    switch (D_800FA2D8_GroundPound) {
    case 1:
        ContBtnTrg[w->unk_56] &= 0x1030;
        ContBtn[w->unk_56] &= 0x1030;
        ContStkX[w->unk_56] = 0;
        ContStkY[w->unk_56] = 0;
        if (obj->trans.x > D_800FA2DC_GroundPound) {
            if (obj->trans.x - D_800FA2DC_GroundPound < 10.0f) {
                D_800FA2D8_GroundPound = 2;
            } else {
                ContStkX[w->unk_56] = -127;
            }
        } else if (D_800FA2DC_GroundPound - obj->trans.x < 10.0f) {
            D_800FA2D8_GroundPound = 2;
        } else {
            ContStkX[w->unk_56] = 127;
        }
        break;
    case 2:
        ContBtnTrg[w->unk_56] &= 0x1030;
        ContBtn[w->unk_56] &= 0x1030;
        ContStkX[w->unk_56] = 0;
        ContStkY[w->unk_56] = 0;
        if (D_800FA2E0_GroundPound != 0) {
            D_800FA2E0_GroundPound--;
        } else if (func_800184A8(w, 0) != 0 && D_800ED430 != 2) {
            D_800ED430 = 2;
        }
        break;
    }
    func_80005A28(obj);
    func_800F9870_GroundPound(obj);
}

s32 func_800F9314_GroundPound(omObjData* obj) {
    unkGlobalStruct_00* w = obj->unk_50;
    unkStructGroundPound_00* hole = D_800FA318_GroundPound;
    s32 all = 1;
    s32 i;
    f32 dx;
    f32 dz;
    f32 d;
    f32 a;
    f32 k;
    s16 frame;

    for (i = 0; i < 7; i++, hole++) {
        if (hole->unk_08 == 0) {
            break;
        }
        dx = hole->unk_00 - obj->trans.x;
        dz = hole->unk_04 - obj->trans.z;
        d = dx * dx + dz * dz;
        if (d < D_800FA2EC_GroundPound && !(hole->unk_08 & 2)) {
            if (obj->trans.y < 125.0f) {
                frame = func_80025E70(obj->model[0]);
                if (frame == -1.0f) {
                    frame = func_80025D18(obj->model[0]);
                }
                if (D_800FA2D8_GroundPound == 0 && d < D_800FA2EC_GroundPound
                    && (((u32)w->unk_5C >> 9) & 1) & (frame > 17)) {
                    D_800FA378_GroundPound[i] = 10;
                    hole->unk_08 |= 2;
                    func_80060540(0x19C, 0);
                    func_800F7044_GroundPound(hole->unk_0A);
                } else if (d < D_800FA2E8_GroundPound) {
                    if (d != 0.0f) {
                        k = D_800FA2E4_GroundPound / func_800B1750(d);
                        obj->trans.x = hole->unk_00 - dx * k;
                        obj->trans.z = hole->unk_04 - dz * k;
                    } else {
                        a = w->unk_3C;
                        obj->trans.x = func_800AEAC0(a) * D_800FA2E4_GroundPound + hole->unk_00;
                        obj->trans.z = func_800AEFD0(a) * D_800FA2E4_GroundPound + hole->unk_04;
                    }
                }
            } else if (d < D_800FA2EC_GroundPound) {
                func_800F7078_GroundPound(hole->unk_0A);
            }
        }
        if (!(hole->unk_08 & 2)) {
            all = 0;
        }
    }
    return all;
}

void func_800F95D4_GroundPound(omObjData* obj) {
    unkGlobalStruct_00* w = obj->unk_50;
    unkStructGroundPound_00* hole = D_800FA380_GroundPound;
    s32 i;
    f32 dx;
    f32 dz;
    f32 d;
    f32 a;
    f32 k;
    s16 frame;

    for (i = 9; i != 0; i--, hole++) {
        if (hole->unk_08 == 0) {
            break;
        }
        dx = hole->unk_00 - obj->trans.x;
        dz = hole->unk_04 - obj->trans.z;
        d = dx * dx + dz * dz;
        if (obj->trans.y < 125.0f) {
            frame = func_80025E70(obj->model[0]);
            if (frame == -1.0f) {
                frame = func_80025D18(obj->model[0]);
            }
            if (d < D_800FA2EC_GroundPound && (((u32)w->unk_5C >> 9) & 1) & (frame > 17)) {
                func_800184BC(obj, 0x17);
                w->unk_38 = -1.029f;
                D_800FA2D0_GroundPound = 60;
                PlaySound(0x268);
                func_80060618(0x45F, w->unk_58);
                func_800F7044_GroundPound(hole->unk_0A);
                func_80060F04(w->unk_58, 20, 0, 20);
                hole->unk_08 |= 2;
            }
            if (d < D_800FA2E8_GroundPound) {
                if (d != 0.0f) {
                    k = D_800FA2E4_GroundPound / func_800B1750(d);
                    obj->trans.x = hole->unk_00 - dx * k;
                    obj->trans.z = hole->unk_04 - dz * k;
                } else {
                    a = w->unk_3C;
                    obj->trans.x = func_800AEAC0(a) * D_800FA2E4_GroundPound + hole->unk_00;
                    obj->trans.z = func_800AEFD0(a) * D_800FA2E4_GroundPound + hole->unk_04;
                }
            }
        } else if (d < D_800FA2EC_GroundPound) {
            func_800F7078_GroundPound(hole->unk_0A);
        }
    }
}

void func_800F9870_GroundPound(omObjData* obj) {
    unkGlobalStruct_00* w = obj->unk_50;

    D_800FA2E4_GroundPound = w->unk_48 + 49.4;
    D_800FA2EC_GroundPound = D_800FA2E4_GroundPound * D_800FA2E4_GroundPound;
    D_800FA2E4_GroundPound = w->unk_48 + 45.5;
    D_800FA2E8_GroundPound = D_800FA2E4_GroundPound * D_800FA2E4_GroundPound;
    func_800F95D4_GroundPound(obj);
    if (func_800F9314_GroundPound(obj) != 0) {
        D_800FA310_GroundPound = 1;
    }
}

void func_800F9908_GroundPound(omObjData* obj) {
    unkGlobalStruct_00* w = obj->unk_50;

    D_800FA2F4_GroundPound = -1;
    D_800FA2F8_GroundPound = 0;
    D_800FA2FC_GroundPound = GwPlayer[w->unk_58].cpu_difficulty;
    D_800FA2F0_GroundPound = NULL;
}

unkStructGroundPound_00* func_800F9950_GroundPound(omObjData* obj) {
    unkStructGroundPound_00* hole;
    unkStructGroundPound_00* best;
    f32 bestD;
    f32 dx;
    f32 dz;
    f32 d;
    s32 i;

    i = func_800F9FEC_GroundPound() & 0xFF;
    if (i < D_800FA1C0_GroundPound[D_800FA2FC_GroundPound]) {
        hole = D_800FA380_GroundPound;
    } else {
        hole = D_800FA318_GroundPound;
    }
    bestD = 2560000.0f;
    best = NULL;
    for (i = 0; i < 7; i++, hole++) {
        if (hole->unk_08 == 0) {
            break;
        }
        if (!(hole->unk_08 & 2)) {
            dx = obj->trans.x - hole->unk_00;
            dz = obj->trans.z - hole->unk_04;
            d = dx * dx + dz * dz;
            if (d < bestD) {
                bestD = d;
                best = hole;
            }
        }
    }
    return best;
}

s32 func_800F9A24_GroundPound(omObjData* obj, f32 angle) {
    unkStructGroundPound_00* hole = D_800FA380_GroundPound;
    s32 res = -1;
    s32 i;
    f32 dx;
    f32 dz;

    for (i = 0; i < 9; i++, hole++) {
        if (hole->unk_08 == 0) {
            break;
        }
        dx = hole->unk_00 - obj->trans.x;
        dz = hole->unk_04 - obj->trans.z;
        if (dx * dx + dz * dz < D_800FA2E8_GroundPound && fabs(angle - func_800B0CD8(dz, dx)) < 45.0) {
            res = i;
            break;
        }
    }
    return res;
}

void func_800F9B18_GroundPound(omObjData* obj) {
    unkGlobalStruct_00* w = obj->unk_50;
    unkStructGroundPound_00* hole;
    f32 dx;
    f32 dz;
    f32 angle;
    f32 d;
    u16 btn;

    D_800FA2E8_GroundPound = 16900.0f;
    D_800FA2E4_GroundPound = w->unk_48 + 0.0f;
    D_800FA2EC_GroundPound = D_800FA2E4_GroundPound * D_800FA2E4_GroundPound;
    D_800FA300_GroundPound++;
    btn = 0;
    if (D_800FA2F0_GroundPound == NULL) {
        D_800FA2F0_GroundPound = func_800F9950_GroundPound(obj);
        if (D_800FA2F0_GroundPound == NULL) {
            return;
        }
    }
    dx = D_800FA2F0_GroundPound->unk_00 - obj->trans.x;
    dz = D_800FA2F0_GroundPound->unk_04 - obj->trans.z;
    angle = func_800B0CD8(dz, dx);
    d = dx * dx + dz * dz;
    if (d < D_800FA2E8_GroundPound) {
        if (d < D_800FA2EC_GroundPound) {
            D_800FA2F0_GroundPound = NULL;
            D_800FA2F8_GroundPound = 0;
            btn |= 0x2000;
        } else if (D_800FA300_GroundPound & 3) {
            btn |= 0x8000;
        }
    }
    if (D_800FA2F4_GroundPound < 0) {
        if (D_800FA2F8_GroundPound == 0) {
            D_800FA2F4_GroundPound = func_800F9A24_GroundPound(obj, angle);
            if (D_800FA2F4_GroundPound >= 0) {
                if (((s32)func_800F9FEC_GroundPound() & 0x3FF) < D_800FA1C4_GroundPound[D_800FA2FC_GroundPound]) {
                    D_800FA2F4_GroundPound = -1;
                }
                D_800FA2F8_GroundPound = 15;
            }
        } else {
            D_800FA2F8_GroundPound--;
        }
    } else {
        hole = &D_800FA380_GroundPound[D_800FA2F4_GroundPound];
        dx = hole->unk_00 - obj->trans.x;
        dz = hole->unk_04 - obj->trans.z;
        d = dx * dx + dz * dz;
        if (d < D_800FA2EC_GroundPound) {
            if (!(hole->unk_08 & 2)) {
                btn |= 0x2000;
            }
            D_800FA2F4_GroundPound = -1;
            D_800FA2F8_GroundPound = 15;
        } else if (d < D_800FA2E8_GroundPound) {
            if (D_800FA300_GroundPound & 3) {
                btn |= 0x8000;
            }
        } else {
            D_800FA2F4_GroundPound = -1;
            D_800FA2F8_GroundPound = 15;
        }
    }
    ContBtnTrg[w->unk_56] = ContBtn[w->unk_56] = btn;
    ContBtnTrg[w->unk_56] = btn & (btn ^ D_800FA2D4_GroundPound);
    D_800FA2D4_GroundPound = btn;
    ContStkX[w->unk_56] = func_800AEFD0(angle) * 80.0f;
    ContStkY[w->unk_56] = -func_800AEAC0(angle) * 80.0f;
}

void func_800F9E4C_GroundPound(f32 x) {
    s32 v;

    D_800FA2DC_GroundPound = x;
    v = 2;
    if (x != 0.0f) {
        v = 1;
    }
    D_800FA2D8_GroundPound = v;
}

void func_800F9E80_GroundPound(f32 zoom, f32 rx, f32 ry, f32 rz, f32 cx, f32 cy, f32 cz) {
    func_800178A0(1);
    CZoom = zoom;
    CRot.x = rx;
    CRot.y = ry;
    CRot.z = rz;
    Center.x = cx;
    Center.y = cy;
    Center.z = cz;
}

/* Park-Miller minimal standard generator (Schrage's method), seeded from the count register. */
s32 func_800F9F18_GroundPound(u32 x) {
    u32 hi;
    u32 lo;

    if (x == 0) {
        x = rand8();
        x ^= osGetCount();
        x ^= 0xD826BC89;
    }
    hi = x / 127773;
    lo = x % 127773;
    x = hi * 2836 - lo * 16807;
    return x;
}

u32 func_800F9FEC_GroundPound(void) {
    return D_800FA1D0_GroundPound = func_800F9F18_GroundPound(D_800FA1D0_GroundPound);
}
