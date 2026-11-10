#include "common.h"
#include "TugOWar.h"

/* .data (0x800FDBE0..0x800FDC30) */
f32 D_800FDBE0_TugOWar = 2.5f; /* the title sprite's scale */
s8 D_800FDBE4_TugOWar = 0;
s8 D_800FDBE5_TugOWar = 0;
s8 D_800FDBE6_TugOWar = 0;
s8 D_800FDBE7_TugOWar = 0;
s8 D_800FDBE8_TugOWar = 0;
s32 D_800FDBEC_TugOWar = 0;
s8 D_800FDBF0_TugOWar[2] = { 0, 0 };
s8 D_800FDBF4_TugOWar[2] = { 0, 0 };
s8 D_800FDBF8_TugOWar[2] = { 0, 0 };
s32 D_800FDBFC_TugOWar[2] = { 0, 0 };
s8 D_800FDC04_TugOWar = 0;
s8 D_800FDC05_TugOWar = 0;
f32 D_800FDC08_TugOWar = 0.0f;
f32 D_800FDC0C_TugOWar = 0.0f;
f32 D_800FDC10_TugOWar = 0.0f;
f32 D_800FDC14_TugOWar = 0.0f;
f32 D_800FDC18_TugOWar = 14.0f;
f32 D_800FDC1C_TugOWar = 16.0f;
f32 D_800FDC20_TugOWar = 0.0f;
s8 D_800FDC24_TugOWar = 0; /* coins to throw */
s8 D_800FDC25_TugOWar = 0; /* coins thrown */
s8 D_800FDC26_TugOWar = 0;
s8 D_800FDC27_TugOWar = 0;
s32 D_800FDC28_TugOWar = 0;

/* A bird crossing the sky (models idx + 2 and its shadow idx + 5), every 211 frames. */
// scheduling of the model-pointer load (masked 4)
#ifdef NON_MATCHING
void func_800FB940_TugOWar(omObjData* obj, u8 idx) {
    s16* mp;
    s16 m2;
    s16 m;

    if (++D_800FDBEC_TugOWar >= 211 && D_800FDBE8_TugOWar != 1) {
        D_800FDBE7_TugOWar = 1;
    }
    if (D_800FDBE7_TugOWar == 1) {
        D_800FDBE7_TugOWar = 0;
        D_800FDBE8_TugOWar = 1;
        D_800FDE20_TugOWar = guRandom() & 1;
        D_800FDE24_TugOWar = 0.0f;
        D_800FDE28_TugOWar = 0.0f;
        D_800FDE2C_TugOWar = 0.0f;
        D_800FDE30_TugOWar = 14.0f;
        D_800FDE34_TugOWar = 16.0f;
        D_800FDE38_TugOWar = 0.0f;
        if (D_800FDE20_TugOWar == 1) {
            func_80025798(obj->model[idx + 2], 900.0f, 450.0f, 130.0f);
        } else {
            func_80025798(obj->model[idx + 2], -900.0f, 450.0f, 130.0f);
        }
        func_800258EC(obj->model[idx + 2], 4, 0);
        func_800258EC(obj->model[idx + 5], 4, 0);
    }
    if (D_800FDBE8_TugOWar == 1) {
        if (D_800FDE20_TugOWar == D_800FDBE8_TugOWar) {
            func_800257E4(obj->model[idx + 2], 0.0f, 0.0f, D_800FDE24_TugOWar += 12.2);
            D_800F2B7C[obj->model[idx + 2]].unk_24 -= D_800FDE30_TugOWar;
            if (D_800FDE38_TugOWar >= 0.0f) {
                D_800F2B7C[obj->model[idx + 2]].unk_28 = D_800FDE2C_TugOWar + D_800FDE38_TugOWar + 450.0f;
            } else {
                D_800F2B7C[obj->model[idx + 2]].unk_28 = D_800FDE2C_TugOWar - D_800FDE38_TugOWar + 450.0f;
            }
            mp = &obj->model[idx];
            if (D_800F2B7C[mp[2]].unk_24 < 230.0f) {
                goto fall;
            }
            goto wave;
        }
        func_800257E4(obj->model[idx + 2], 0.0f, 0.0f, D_800FDE24_TugOWar -= 12.2);
        D_800F2B7C[obj->model[idx + 2]].unk_24 += D_800FDE30_TugOWar;
        if (D_800FDE38_TugOWar >= 0.0f) {
            D_800F2B7C[obj->model[idx + 2]].unk_28 = D_800FDE2C_TugOWar + D_800FDE38_TugOWar + 450.0f;
        } else {
            D_800F2B7C[obj->model[idx + 2]].unk_28 = D_800FDE2C_TugOWar - D_800FDE38_TugOWar + 450.0f;
        }
        mp = obj->model + idx;
        if (D_800F2B7C[mp[2]].unk_24 > -230.0f) {
        fall:
            func_800258EC(mp[5], 4, 4);
            D_800FDE30_TugOWar *= 0.94f;
            D_800FDE2C_TugOWar -= D_800FDE34_TugOWar;
            D_800FDE34_TugOWar += 1.2f;
        } else {
        wave:
            D_800FDE38_TugOWar = func_800AEAC0(D_800FDE28_TugOWar / 100.0f * 360.0f) * 25.0f;
            D_800FDE28_TugOWar += 4.0f;
        }
        m = obj->model[idx + 2];
        if (D_800F2B7C[m].unk_28 < 0.0f) {
            func_800258EC(m, 4, 4);
            D_800FDBE8_TugOWar = 0;
            D_800FDBEC_TugOWar = 0;
        }
        func_80025798(obj->model[idx + 5], D_800F2B7C[obj->model[idx + 2]].unk_24, 400.0f,
                      D_800F2B7C[obj->model[idx + 2]].unk_2C);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_32_TugOWar/231D40", func_800FB940_TugOWar);
#endif

/* Bird `idx` (models idx + 3, shadow idx + 6): circles at (x, z), leaves after `delay` frames. */
// CSE of idx in the fall branch, scheduling (masked 15)
#ifdef NON_MATCHING
void func_800FBF18_TugOWar(omObjData* obj, f32 x, f32 z, s16 delay, u8 dir, u8 idx) {
    s16* mp;
    s16 m;

    if (D_800FDBF0_TugOWar[idx] == 0) {
        D_800FDBF0_TugOWar[idx] = 1;
        D_800FDE3C_TugOWar[idx] = dir;
        D_800FDE3E_TugOWar[idx] = 0;
        D_800FDE48_TugOWar[idx] = guRandom() % 40 - 20;
        D_800FDE50_TugOWar[idx] = 0.0f;
        D_800FDE58_TugOWar[idx] = 0.0f;
        D_800FDE60_TugOWar[idx] = 14.0f;
        D_800FDE68_TugOWar[idx] = 16.0f;
        D_800FDE70_TugOWar[idx] = 0.0f;
        D_800FDE40_TugOWar[idx] = delay;
        func_80025798(obj->model[idx + 3], x, 450.0f, z);
        func_800258EC(obj->model[idx + 3], 4, 0);
        func_800258EC(obj->model[idx + 6], 4, 0);
    }
    if (D_800FDBF8_TugOWar[idx] == 0) {
        if (D_800FDE40_TugOWar[idx] < ++D_800FDBFC_TugOWar[idx] && D_800FDBF4_TugOWar[idx] != 1) {
            D_800FDBF4_TugOWar[idx] = 1;
        }
        if (D_800FDE3E_TugOWar[idx] == 0) {
            if ((D_800FDE48_TugOWar[idx] += 0.4f) > 2.0f) {
                D_800FDE3E_TugOWar[idx] = 1;
            }
        } else {
            if ((D_800FDE48_TugOWar[idx] -= 0.4f) < -2.0f) {
                D_800FDE3E_TugOWar[idx] = 0;
            }
        }
        func_800257E4(obj->model[idx + 3], 0.0f, 0.0f, D_800FDE48_TugOWar[idx]);
    }
    if (D_800FDBF4_TugOWar[idx] == 1) {
        if (D_800FDE3C_TugOWar[idx] == D_800FDBF4_TugOWar[idx]) {
            func_800257E4(obj->model[idx + 3], 0.0f, 0.0f, D_800FDE48_TugOWar[idx] += 12.2);
            D_800F2B7C[obj->model[idx + 3]].unk_24 -= D_800FDE60_TugOWar[idx];
            if (D_800FDE70_TugOWar[idx] >= 0.0f) {
                D_800F2B7C[obj->model[idx + 3]].unk_28 =
                    D_800FDE58_TugOWar[idx] + D_800FDE70_TugOWar[idx] + 450.0f;
            } else {
                D_800F2B7C[obj->model[idx + 3]].unk_28 =
                    D_800FDE58_TugOWar[idx] - D_800FDE70_TugOWar[idx] + 450.0f;
            }
            mp = obj->model + idx;
            if (D_800F2B7C[mp[3]].unk_24 < 230.0f) {
                goto fall;
            }
            goto wave;
        }
        func_800257E4(obj->model[idx + 3], 0.0f, 0.0f, D_800FDE48_TugOWar[idx] -= 12.2);
        D_800F2B7C[obj->model[idx + 3]].unk_24 += D_800FDE60_TugOWar[idx];
        if (D_800FDE70_TugOWar[idx] >= 0.0f) {
            D_800F2B7C[obj->model[idx + 3]].unk_28 = D_800FDE58_TugOWar[idx] + D_800FDE70_TugOWar[idx] + 450.0f;
        } else {
            D_800F2B7C[obj->model[idx + 3]].unk_28 = D_800FDE58_TugOWar[idx] - D_800FDE70_TugOWar[idx] + 450.0f;
        }
        mp = obj->model + idx;
        if (D_800F2B7C[mp[3]].unk_24 > -230.0f) {
        fall:
            func_800258EC(mp[6], 4, 4);
            D_800FDE60_TugOWar[idx] *= 0.94f;
            D_800FDE58_TugOWar[idx] -= D_800FDE68_TugOWar[idx];
            D_800FDE68_TugOWar[idx] += 1.2f;
        } else {
        wave:
            D_800FDE70_TugOWar[idx] = func_800AEAC0(D_800FDE50_TugOWar[idx] / 100.0f * 360.0f) * 25.0f;
            D_800FDE50_TugOWar[idx] += 4.0f;
        }
        m = obj->model[idx + 3];
        if (D_800F2B7C[m].unk_28 < 0.0f) {
            func_800258EC(m, 4, 4);
            D_800FDBF4_TugOWar[idx] = 0;
            D_800FDBF8_TugOWar[idx] = 1;
            D_800FDBFC_TugOWar[idx] = 0;
        }
        func_80025798(obj->model[idx + 6], D_800F2B7C[obj->model[idx + 3]].unk_24, 400.0f,
                      D_800F2B7C[obj->model[idx + 3]].unk_2C);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_32_TugOWar/231D40", func_800FBF18_TugOWar);
#endif

/* The sky: scrolls the title in, then the birds; redraws the wavy title sprite. */
void func_800FC710_TugOWar(omObjData* obj) {
    s16 m2;
    s16 m;

    if (func_8005FD5C() + D_800F64F8 == 0) {
        D_800FDC08_TugOWar += 0.25f;
        if (D_800FDBE5_TugOWar == 0) {
            if (D_800FDC04_TugOWar == 0) {
                Center.z += 24.466f;
                D_800FDBE0_TugOWar -= 0.016666211f;
                if (Center.z > 636.0f) {
                    Center.z = 636.0f;
                    D_800FDC04_TugOWar = 1;
                }
            }
            if (D_800FDC04_TugOWar == 1) {
                if (D_800FDC05_TugOWar == 0) {
                    func_80060128(0x22);
                    D_800FDC05_TugOWar = 1;
                }
                func_800257E4(obj->model[2], 0.0f, 0.0f, D_800FDC0C_TugOWar += 16.2);
                D_800F2B7C[obj->model[2]].unk_24 -= D_800FDC18_TugOWar;
                if (D_800FDC20_TugOWar >= 0.0f) {
                    D_800F2B7C[obj->model[2]].unk_28 = D_800FDC14_TugOWar + D_800FDC20_TugOWar + 450.0f;
                } else {
                    D_800F2B7C[obj->model[2]].unk_28 = D_800FDC14_TugOWar - D_800FDC20_TugOWar + 450.0f;
                }
                if (D_800F2B7C[obj->model[2]].unk_24 < 230.0f) {
                    func_800258EC(obj->model[5], 4, 4);
                    D_800FDC18_TugOWar *= 0.94f;
                    D_800FDC14_TugOWar -= D_800FDC1C_TugOWar;
                    D_800FDC1C_TugOWar += 1.2f;
                } else {
                    D_800FDC20_TugOWar = func_800AEAC0(D_800FDC10_TugOWar / 100.0f * 360.0f) * 25.0f;
                    D_800FDC10_TugOWar += 4.0f;
                }
                m = obj->model[2];
                if (D_800F2B7C[m].unk_28 < 0.0f) {
                    func_800258EC(m, 4, 4);
                    D_800FDBE5_TugOWar = 1;
                }
                func_80025798(obj->model[5], D_800F2B7C[obj->model[2]].unk_24, 400.0f,
                              D_800F2B7C[obj->model[2]].unk_2C);
            }
        } else {
            func_800FB940_TugOWar(obj, 0);
        }
        func_800FBF18_TugOWar(obj, 420.0f, -120.0f, 420, 1, 0);
        func_800FBF18_TugOWar(obj, -360.0f, 135.0f, 630, 0, 1);
    }
    func_800FAE90_TugOWar(D_800FDE78_TugOWar, D_800FDE7E_TugOWar, 0, 160, 75, D_800FDC08_TugOWar, 1, 0.75f, 40, 1,
                          D_800FDBE0_TugOWar);
}

/* The sky object: backdrop models, three birds and their shadows, the title sprite. */
void func_800FCB8C_TugOWar(omObjData* obj) {
    unkGlobalStruct_02* w;
    void* data;
    s16 anim;
    s16 spr;
    s16 i;
    s16 first;

    obj->unk_50 = w = func_80023684(sizeof(unkGlobalStruct_02), 0x7918);
    func_8009B770(w, 0, sizeof(unkGlobalStruct_02));
    w->unk_04 = 1;
    w->unk_05 = 0;
    obj->model[0] = -1;
    obj->model[0] = func_800174C0(0x460000, 0x299);
    obj->model[1] = func_800174C0(0x46000D, 0x299);
    first = 0;
    for (i = 0; i < 3; i++) {
        if (first == 0) {
            obj->model[2] = func_800174C0(0x46000E, 0x689);
            first = 1;
        } else {
            obj->model[i + 2] = func_80023FC8(obj->model[2]);
        }
        func_80021240(obj->model[i + 2]);
        func_800211BC(obj->model[i + 2], 0x40);
        func_80025B34(obj->model[i + 2]);
    }
    first = 0;
    for (i = 0; i < 3; i++) {
        if (first == 0) {
            obj->model[5] = func_800174F4(6, 0x699);
            first = 1;
        } else {
            obj->model[i + 5] = func_80023FC8(obj->model[5]);
        }
    }
    obj->trans.x = obj->trans.y = 0.0f;
    obj->trans.z = -100.0f;
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, -100.0f);
    func_80025798(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80025798(obj->model[2], 600.0f, 450.0f, 130.0f);
    data = DataRead(0x460024);
    if (data != NULL) {
        anim = func_800678A4(data);
        if (anim != -1) {
            spr = func_80064EF4(1, 0);
            func_80067208(spr, 0, anim, 0);
            func_800674BC(spr, 0, 0x4000);
            func_80066DC4(spr, 0, 160, 120);
            func_80067354(spr, 0, 2.0f, 2.0f);
            func_800674BC(spr, 0, 0x503C);
        }
        DataClose(data);
    }
    D_800FDE7E_TugOWar = func_800FAE4C_TugOWar(0x3B000E);
    /* 0x1000 bytes on the N64: 0x200 commands (a host Gfx is 16 bytes) */
    D_800FDE78_TugOWar = func_80023684(0x200 * sizeof(Gfx), 0x7918);
    if (D_800FDE78_TugOWar != NULL) {
        func_8009B770(D_800FDE78_TugOWar, 0, 0x200 * sizeof(Gfx));
        D_800FDE7C_TugOWar = func_80024198(160, D_800FDE78_TugOWar, 0);
        func_800FAE90_TugOWar(D_800FDE78_TugOWar, D_800FDE7E_TugOWar, 0, 160, 75, 0, 1, 0.75f, 40, 1,
                              D_800FDBE0_TugOWar);
    }
    obj->func_ptr = func_800FC710_TugOWar;
}

/* The coin pot: on the result, moves coins between the sides and throws them. */
void func_800FCF10_TugOWar(omObjData* obj) {
    f32 t;
    s8 i;

    if (D_800FDB15_TugOWar == 1) {
        if (D_800FDC26_TugOWar == 0) {
            PlaySound(0x35B);
            func_800258EC(obj->model[0], 4, 4);
            func_800258EC(obj->model[1], 4, 0);
            if (D_800FDFB2_TugOWar == 0) {
                for (i = 0; i < 3; i++) {
                    func_800258EC(D_800F3FB0[i + 1]->model[0], 4, 4);
                }
            } else {
                func_800258EC(D_800F3FB0[0]->model[0], 4, 4);
            }
            D_800FDC24_TugOWar = 0;
            switch (D_800FDB16_TugOWar) {
            case 0:
                for (i = 1; i < 4; i++) {
                    if (GwPlayer[D_800FDFAE_TugOWar[i]].coins >= 5) {
                        GwPlayer[D_800FDFAE_TugOWar[0]].coins_mg += 5;
                        GwPlayer[D_800FDFAE_TugOWar[i]].coins_mg -= 5;
                    } else {
                        GwPlayer[D_800FDFAE_TugOWar[0]].coins_mg += 5;
                        GwPlayer[D_800FDFAE_TugOWar[i]].coins_mg -= GwPlayer[D_800FDFAE_TugOWar[i]].coins;
                    }
                }
                D_800FDC24_TugOWar = (u8)GwPlayer[D_800FDFAE_TugOWar[0]].coins_mg;
                break;
            case 1:
                if (GwPlayer[D_800FDFAE_TugOWar[0]].coins >= 15) {
                    GwPlayer[D_800FDFAE_TugOWar[0]].coins_mg -= 15;
                } else {
                    GwPlayer[D_800FDFAE_TugOWar[0]].coins_mg -= GwPlayer[D_800FDFAE_TugOWar[0]].coins;
                }
                for (i = 1; i < 4; i++) {
                    GwPlayer[D_800FDFAE_TugOWar[i]].coins_mg += 5;
                    D_800FDC24_TugOWar += (u8)GwPlayer[D_800FDFAE_TugOWar[i]].coins_mg;
                }
                break;
            }
            D_800FDC26_TugOWar = 1;
        }
        if (D_800FDBE4_TugOWar == 0) {
            t = func_80025D18(obj->model[1]);
            if (t > 130.0f) {
                D_800FDC27_TugOWar = 1;
            }
            if (func_80025D40(obj->model[1]) <= t) {
                func_800258EC(obj->model[0], 4, 0);
                func_800258EC(obj->model[1], 4, 4);
                D_800FDBE4_TugOWar = 1;
            }
        }
        if (D_800FDFB3_TugOWar == 0) {
            if (D_800FDBE6_TugOWar != 1) {
                if (D_800FDC27_TugOWar == 1 && D_800FDC25_TugOWar < D_800FDC24_TugOWar) {
                    if (D_800FDC28_TugOWar % 3 == 0) {
                        PlaySound(0x35D);
                        D_800FDE80_TugOWar[D_800FDC25_TugOWar].active = 1;
                        D_800FDC25_TugOWar++;
                    }
                    D_800FDC28_TugOWar++;
                }
                for (i = 0; i < D_800FDC24_TugOWar; i++) {
                    if (D_800FDE80_TugOWar[i].active == 1) {
                        func_800258EC(obj->model[i + 3], 4, 0);
                        func_80025798(obj->model[i + 3], D_800FDE80_TugOWar[i].x, D_800FDE80_TugOWar[i].y,
                                      D_800FDE80_TugOWar[i].z);
                        if (D_800FDFB2_TugOWar == 0) {
                            D_800FDE80_TugOWar[i].x -= 11.8f;
                        } else {
                            D_800FDE80_TugOWar[i].x += (s8)(i % 3) * 1.1 + 12.8f;
                        }
                        if ((D_800FDE80_TugOWar[i].z -= 10.0f) < -100.0f) {
                            D_800FDE80_TugOWar[i].z = -100.0f;
                        }
                        D_800FDE80_TugOWar[i].vy += -1.4f;
                        D_800FDE80_TugOWar[i].y += D_800FDE80_TugOWar[i].vy + 38.0f;
                        if (D_800FDE80_TugOWar[i].vy + 38.0f < 0.0f && D_800FDE80_TugOWar[i].y < 450.0f) {
                            func_800258EC(obj->model[i + 3], 4, 4);
                            PlaySound(0x43);
                            D_800FDE80_TugOWar[i].active = 0;
                            D_800FDE80_TugOWar[i].done = 1;
                        }
                    }
                }
                if (D_800FDC24_TugOWar == 0) {
                    D_800FDBE6_TugOWar = 1;
                } else if (D_800FDE80_TugOWar[D_800FDC24_TugOWar - 1].done == 1) {
                    D_800FDBE6_TugOWar = 1;
                }
            }
        } else {
            D_800FDBE6_TugOWar = 1;
        }
    }
}

/* The coin pot object: the pot, its lid, and 15 coin sprites. */
// register allocation of img/first (masked 1)
#ifdef NON_MATCHING
void func_800FD758_TugOWar(omObjData* obj) {
    unkGlobalStruct_00* w;
    u16 img;
    u16 tex;
    s16 i;
    s16 first;

    first = 0;
    img = 0;
    obj->unk_50 = w = func_80023684(0x6C, 0x7918);
    func_8009B770(w, 0, 0x6C);
    w->unk_52 = 1;
    obj->model[0] = func_800174F4(0x460021, 0x299);
    func_80025EB4(obj->model[0], 2, 2);
    obj->model[1] = func_800174F4(0x460022, 0x299);
    func_80025EB4(obj->model[1], 2, 0);
    func_800258EC(obj->model[1], 4, 4);
    obj->model[2] = func_800174F4(0x460023, 0x299);
    func_80025EB4(obj->model[2], 2, 2);
    for (i = 0; i < 15; i++) {
        if (first == 0) {
            tex = img = ReadImgPackand(0x21, 0x299, 8);
            first = 1;
        } else {
            tex = func_8001E1D0(img, 8);
        }
        obj->model[i + 3] = D_800ECDE0[tex].unk_00;
        func_80025930(obj->model[i + 3], 0x70000000, 0x70000000);
        func_80025798(obj->model[i + 3], 0.0f, 0.0f, 0.0f);
        func_80025830(obj->model[i + 3], 2.0f, 2.0f, 2.0f);
        func_800258EC(obj->model[i + 3], 4, 4);
    }
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    func_80025798(obj->model[0], 0.0f, obj->trans.y, obj->trans.z);
    func_80025798(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    for (i = 0; i < 15; i++) {
        D_800FDE80_TugOWar[i].active = 0;
        D_800FDE80_TugOWar[i].done = 0;
        D_800FDE80_TugOWar[i].x = 0.0f;
        D_800FDE80_TugOWar[i].y = 360.0f;
        D_800FDE80_TugOWar[i].z = 0.0f;
        D_800FDE80_TugOWar[i].vy = 0.0f;
    }
    obj->func_ptr = func_800FCF10_TugOWar;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_32_TugOWar/231D40", func_800FD758_TugOWar);
#endif

void func_800FDA4C_TugOWar(void) {
    omObjData* obj;

    obj = D_800F2AF8[D_800ED440] = omAddObj(10, 10, 0, -1, func_800FCB8C_TugOWar);
    omSetStatBit(obj, 0xA0);
    D_800ED440++;
    omAddObj(20, 30, 0, -1, func_800FD758_TugOWar);
}
