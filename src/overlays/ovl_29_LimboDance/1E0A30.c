#include "common.h"
#include "LimboDance.h"

/* .data */
u32 D_800FE980_LimboDance = 0x19971204; /* RNG seed (func_800F7628) */
u16 D_800FE984_LimboDance = 0;
s16 D_800FE986_LimboDance = 0;
s16 D_800FE988_LimboDance = 0x3A2;
s16 D_800FE98A_LimboDance = 0x3CA;
u16 D_800FE98C_LimboDance = 0;
s16 D_800FE98E_LimboDance = 0;
s16 D_800FE990_LimboDance = 0;
s16 D_800FE992_LimboDance = 0;
s16 D_800FE994_LimboDance = 0;
s16 D_800FE996_LimboDance = 0;
u16 D_800FE998_LimboDance = 0;
u16 D_800FE99A_LimboDance = 0;
s16 D_800FE99C_LimboDance = 3;
u16 D_800FE99E_LimboDance = 0;
s16 D_800FE9A0_LimboDance = 0;
s16 D_800FE9A2_LimboDance = 1;
s16 D_800FE9A4_LimboDance = 9;
f32 D_800FE9A8_LimboDance = 0.0f;
f32 D_800FE9AC_LimboDance = 0.0f;
s32 D_800FE9B0_LimboDance = 0;
f32 D_800FE9B4_LimboDance = 0.0f;
f32 D_800FE9B8_LimboDance = 8.0f;
f32 D_800FE9BC_LimboDance = 0.0f;
Vtx D_800FE9C0_LimboDance[4] = {
    { { { -8, 8, 0 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xFF } } },
    { { { -8, 0, 0 }, 0, { 0, 0x200 }, { 0xFF, 0xFF, 0xFF, 0xFF } } },
    { { { 8, 0, 0 }, 0, { 0x400, 0x200 }, { 0xFF, 0xFF, 0xFF, 0xFF } } },
    { { { 8, 8, 0 }, 0, { 0x400, 0 }, { 0xFF, 0xFF, 0xFF, 0xFF } } },
};
/* Scenery model files (| 0x3D0000), -1: none. */
s32 D_800FEA00_LimboDance[8] = { 0, 1, 2, 3, -1, -1, 10, 11 };
/* Texture filters by billboard flags & 0x18. */
s16 D_800FEA20_LimboDance[4] = { G_TF_POINT, G_TF_AVERAGE, G_TF_BILERP, G_TF_POINT };
/* A torch's flame quads (func_800FBAF0); func_800FC4FC sways [0..1], [4..6] per frame. */
Vtx D_800FEA28_LimboDance[9] = {
    { { { -20, 64, 0 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 20, 64, 0 }, 0, { 0x800, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 16, 0, 0 }, 0, { 0x800, 0x1000 }, { 0xFF, 0xFF, 0xFF, 0x10 } } },
    { { { -16, 0, 0 }, 0, { 0, 0x1000 }, { 0xFF, 0xFF, 0xFF, 0x10 } } },
    { { { 0, 16, 0 }, 0, { 0x400, 0xC00 }, { 0xFF, 0xFF, 0xFF, 0xC8 } } },
    { { { -16, 24, 8 }, 0, { 0, 0 }, { 0x00, 0x00, 0x00, 0xFF } } },
    { { { 16, 24, 8 }, 0, { 0x1000, 0 }, { 0x00, 0x00, 0x00, 0xFF } } },
    { { { 16, 8, 8 }, 0, { 0x1000, 0x800 }, { 0x00, 0x00, 0x00, 0xFF } } },
    { { { -16, 8, 8 }, 0, { 0, 0x800 }, { 0x00, 0x00, 0x00, 0xFF } } },
};

void func_800F65E0_LimboDance(void) {
    u8 cam;
    u8 hi;

    func_80029090(50);
    omInitObjMan(50, 0);
    func_80060088();
    func_8001DE70(64);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    func_800234B8(0, 0xFF, 0xFF, 0xFF);
    func_800234B8(1, 0xFF, 0xFF, 0xFF);
    func_80023504(1, -96.0f, 100.0f, 26.0f);
    func_800178A0(1);
    cam = func_800178E8();
    func_80017660(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 45.0f, 80.0f, 8000.0f);
    func_800F72B8_LimboDance();
    hi = rand8();
    func_800F7698_LimboDance((hi << 8) | rand8());
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    D_800EE984 = 0;
    D_800FEFF6_LimboDance = 0;
    D_800FEFF8_LimboDance = 0;
    D_800FEFFC_LimboDance = 0;
    D_800FEFF4_LimboDance = 0;
    D_800FF1BC_LimboDance = 0;
    D_800FF1BE_LimboDance = 0;
    D_800FF1C0_LimboDance = 0;
    D_800FF000_LimboDance = 0;
    D_800FF1C2_LimboDance = 0;
    D_800FEFF0_LimboDance = omAddObj(32, 0, 0, -1, func_800F67D4_LimboDance);
}

void func_800F67D4_LimboDance(omObjData* obj) {
    obj->func_ptr = func_800F6844_LimboDance;
    func_800FA030_LimboDance();
    func_80028510(0xFA, 0x3CA, 0, 0, 2);
    func_800F7984_LimboDance();
    func_800F922C_LimboDance();
    func_800F74C0_LimboDance();
    if (_CheckFlag(0x2B) != 0) {
        D_800FF1C2_LimboDance = 1;
    }
}

/* Intro: fade in, then the camera pans across the course. */
void func_800F6844_LimboDance(omObjData* obj) {
    f32 t;

    switch (D_800FE984_LimboDance) {
    case 0:
        func_80028510(0xFA, 0x3CA, 0, 0, 2);
        SetFadeInTypeAndTime(0, 16);
        D_800FE984_LimboDance++;
        break;
    case 1:
        if (func_80072718() == 0) {
            D_800FE984_LimboDance++;
        }
        func_80060128(0x22);
        break;
    case 2:
        D_800FE986_LimboDance++;
        t = (f32)D_800FE986_LimboDance / 60.0;
        func_800F7328_LimboDance(t);
        D_800FE988_LimboDance = t * 680.0f + 250.0f + func_800AEAC0(t * 180.0) * 200.0;
        if (D_800FE986_LimboDance < 30) {
            D_800FE988_LimboDance += func_800AEAC0((f32)D_800FE986_LimboDance / 30.0 * 180.0) * 100.0f;
        }
        func_80028510(D_800FE988_LimboDance, D_800FE98A_LimboDance, 0, 0, 2);
        if (D_800FE986_LimboDance > 60) {
            D_800FE984_LimboDance++;
        }
        break;
    case 3:
        obj->func_ptr = func_800F6AB8_LimboDance;
        func_80028510(0x3A2, 0x3CA, 0, 0, 2);
        func_800F7264_LimboDance();
        break;
    }
    func_800F756C_LimboDance();
    func_800F723C_LimboDance(obj);
}

/* "Start", then the timer runs until the dancer finishes or fails. */
void func_800F6AB8_LimboDance(omObjData* obj) {
    switch (D_800FE98C_LimboDance) {
    case 0:
        D_800FE98C_LimboDance++;
        break;
    case 1:
        if (func_80072718() == 0) {
            D_800FE98C_LimboDance++;
        }
        break;
    case 2:
        GMesCreate(0);
        D_800FE98C_LimboDance++;
        break;
    case 3:
        if (GMesStatAllGet() == 0) {
            D_800FEFF6_LimboDance = 2;
            D_800FEFFC_LimboDance = 929;
            GMesCreate(8, 10, 0xA0, 0x20);
            func_80079078(D_800FEFFC_LimboDance / 30);
            D_800FE98C_LimboDance++;
        }
        break;
    default:
        if (D_800FEFFC_LimboDance >= 29 && D_800FF000_LimboDance == 0) {
            D_800FEFFC_LimboDance--;
        } else {
            if (D_800FEFFC_LimboDance < 29) {
                D_800FEFFC_LimboDance = 0;
                func_800601D4(0x28);
            }
            func_800790C0();
            if (D_800FF1C2_LimboDance == 0) {
                obj->func_ptr = func_800F6C7C_LimboDance;
            } else {
                obj->func_ptr = func_800F70C0_LimboDance;
            }
        }
        func_80079078(D_800FEFFC_LimboDance / 30);
        break;
    }
    func_800F756C_LimboDance();
    func_800F723C_LimboDance(obj);
}

/* Result: coins (+10 cleared, -5 failed), the zoom on the dancer, the voice, then the exit. */
// NON_MATCHING: register allocation / scheduling
#ifdef NON_MATCHING
void func_800F6C7C_LimboDance(omObjData* obj) {
    s16 cleared[6] = { 0x451, 0x452, 0x453, 0x454, 0x455, 0x456 };
    s16 failed[6] = { 0x44A, 0x44B, 0x44C, 0x44D, 0x44E, 0x44F };
    f32 t;
    s32 go;
    s32 msg;

    if (D_800FE992_LimboDance != 0) {
        if (D_800FF1BC_LimboDance != 0) {
            t = (f32)D_800FE994_LimboDance / 30.0;
        } else {
            t = (f32)D_800FE994_LimboDance / 45.0;
        }
        if (t > 1.0) {
            t = 1.0f;
            D_800FE992_LimboDance = 0;
        }
        func_800F7424_LimboDance(t);
        D_800FE994_LimboDance++;
    }
    switch (D_800FE98E_LimboDance) {
    case 0:
        if (D_800FE990_LimboDance == 0 || D_800FE990_LimboDance < 0) {
            D_800FE990_LimboDance++;
        } else {
            if (D_800FF1BC_LimboDance != 0) {
                GMesCreate(2);
                GwPlayer[D_800FF060_LimboDance].coins_mg += 10;
            } else {
                msg = 0x10;
                if (D_800FEFFC_LimboDance != 0) {
                    msg = 0xE;
                }
                GMesCreate(msg);
                GwPlayer[D_800FF060_LimboDance].coins_mg -= 5;
            }
            D_800FE990_LimboDance = 0;
            D_800FE98E_LimboDance = 1;
        }
        break;
    case 1:
        if (++D_800FE990_LimboDance >= 0 && GMesStatAllGet() == 2) {
            msg = 0x34;
            if (D_800FF1BC_LimboDance != 0) {
                msg = 0x33;
            }
            func_80060128(msg);
            D_800FE992_LimboDance = 1;
            D_800FE990_LimboDance = 0;
            D_800FE98E_LimboDance = 2;
        }
        break;
    case 2:
        if (++D_800FE990_LimboDance >= 0) {
            D_800FF1C0_LimboDance = 1;
            D_800FE990_LimboDance = 0;
            D_800FE98E_LimboDance = 3;
        }
        break;
    case 3:
        D_800FE990_LimboDance++;
        if (D_800FF1BC_LimboDance != 0) {
            go = D_800FE990_LimboDance > 35;
        } else {
            go = D_800FE990_LimboDance >= 18;
        }
        if (go) {
            if (D_800FF1BC_LimboDance != 0) {
                msg = cleared[D_800FF062_LimboDance];
            } else {
                msg = failed[D_800FF062_LimboDance];
            }
            PlaySound(msg);
            D_800FE990_LimboDance = 0;
            D_800FE98E_LimboDance = 4;
        }
        break;
    case 4:
        D_800FE990_LimboDance++;
        if (D_800FF1BC_LimboDance != 0) {
            go = D_800FE990_LimboDance > 56;
        } else {
            go = D_800FE990_LimboDance >= 72;
        }
        if (go && GMesWait() == 0) {
            func_800726AC(0, 20);
            func_800601D4(0x28);
            D_800FE990_LimboDance = 0;
            D_800FE98E_LimboDance = 5;
        }
        break;
    case 5:
        if (func_80072718() == 0) {
            obj->func_ptr = func_800F7210_LimboDance;
        }
        break;
    }
    func_800F756C_LimboDance();
    func_800F723C_LimboDance(obj);
}
#else
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_29_LimboDance/1E0A30", D_800FEAE0_LimboDance);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_29_LimboDance/1E0A30", D_800FEAEC_LimboDance);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_29_LimboDance/1E0A30", func_800F6C7C_LimboDance);
#endif

/* Practice result (_CheckFlag(0x2B)). */
void func_800F70C0_LimboDance(omObjData* obj) {
    switch (D_800FE996_LimboDance) {
    case 0:
        GMesCreate(2);
        if (D_800FF1BC_LimboDance != 0) {
            GwPlayer[D_800FF060_LimboDance].coins_mg += 10;
        } else {
            GwPlayer[D_800FF060_LimboDance].coins_mg -= 5;
        }
        D_800FE996_LimboDance++;
        break;
    case 1:
        if (GMesStatAllGet() == 2) {
            D_800FE996_LimboDance++;
        }
        break;
    case 2:
        if (GMesWait() == 0) {
            func_800726AC(0, 20);
            func_80060398(0x28);
            D_800FE996_LimboDance++;
        }
        break;
    default:
        if (func_80072718() == 0) {
            obj->func_ptr = func_800F7210_LimboDance;
        }
        break;
    }
    func_800F756C_LimboDance();
    func_800F723C_LimboDance(obj);
}

void func_800F7210_LimboDance(omObjData* obj) {
    func_800FA0DC_LimboDance();
    func_80060198();
    omOvlReturnEx(1);
}

void func_800F723C_LimboDance(omObjData* obj) {
    if (D_800F5144 == 1) {
        obj->func_ptr = func_800F7210_LimboDance;
    }
}

void func_800F7264_LimboDance(void) {
    CRot.x = -10.0f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    Center.x = 0.0f;
    Center.y = 150.0f;
    Center.z = 0.0f;
    CZoom = 900.0f;
}

void func_800F72B8_LimboDance(void) {
    CRot.x = -3.0f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    Center.x = 350.0f;
    Center.y = 25.0f;
    Center.z = -1050.0f;
    CZoom = 900.0f;
}

/* The intro pan, t = 0..1. */
void func_800F7328_LimboDance(f32 t) {
    f64 d;

    if (t > 1.0) {
        t = 1.0f;
    }
    d = t;
    CRot.x = d * -7.0 + -3.0;
    CRot.y = d * 0.0 + 0.0;
    CRot.z = d * 0.0 + 0.0;
    Center.x = d * -350.0 + 350.0;
    Center.y = d * 125.0 + 25.0;
    Center.z = d * 1050.0 + -1050.0;
    CZoom = d * 0.0 + 900.0;
}

/* The result zoom, t = 0..1. */
void func_800F7424_LimboDance(f32 t) {
    f64 d;

    CZoom = t * -300.0 + 900.0;
    d = t * 15.0;
    func_80028510(930.0 - d, 970.0 - d, 0, 0, 2);
}

void func_800F74C0_LimboDance(void) {
    s16 i;

    for (i = 0; i < 10; i++) {
        D_800FF1C8_LimboDance[i].id = -1;
        D_800FF1C8_LimboDance[i].delay = 0;
    }
}

void func_800F750C_LimboDance(s16 id, s16 delay) {
    s16 i;

    for (i = 0; i < 10; i++) {
        if (D_800FF1C8_LimboDance[i].id == -1) {
            D_800FF1C8_LimboDance[i].id = id;
            D_800FF1C8_LimboDance[i].delay = delay;
            return;
        }
    }
}

// NON_MATCHING: register allocation / scheduling
#ifdef NON_MATCHING
void func_800F756C_LimboDance(void) {
    s16 i;

    for (i = 0; i < 10; i++) {
        if (D_800FF1C8_LimboDance[i].id != -1) {
            if ((D_800FF1C8_LimboDance[i].delay = D_800FF1C8_LimboDance[i].delay - 1) <= 0) {
                PlaySound(D_800FF1C8_LimboDance[i].id);
                D_800FF1C8_LimboDance[i].id = -1;
                D_800FF1C8_LimboDance[i].delay = 0;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_29_LimboDance/1E0A30", func_800F756C_LimboDance);
#endif

/* Random number below n (0: the whole low half of the seed). */
// NON_MATCHING: register allocation / scheduling
#ifdef NON_MATCHING
u16 func_800F7628_LimboDance(u16 n) {
    D_800FE980_LimboDance = (D_800FE980_LimboDance * 0x19971204 + 0x19760831) >> 16;
    if (n != 0) {
        return D_800FE980_LimboDance % n;
    } else {
        return (u16)D_800FE980_LimboDance;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_29_LimboDance/1E0A30", func_800F7628_LimboDance);
#endif

void func_800F7698_LimboDance(u16 seed) {
    D_800FE980_LimboDance = seed + seed * D_800FE980_LimboDance;
}

/* Signed step (at most step) turning cur towards target, in degrees. */
f32 func_800F76BC_LimboDance(f32 target, f32 cur, f32 step) {
    f32 d;

    if (target >= 360.0) {
        target -= 360.0;
    } else if (target < 0.0) {
        target += 360.0;
    }
    if (cur >= 360.0) {
        cur -= 360.0;
    } else if (cur < 0.0) {
        cur += 360.0;
    }
    d = func_8009B618(target - cur + 360.0, 360.0);
    if (d < 180.0) {
        if (d <= step) {
            return d;
        }
        return step;
    }
    if (360.0 - d <= step) {
        return -(360.0 - d);
    }
    return -step;
}

void func_800F7824_LimboDance(omObjData* obj, u16 slot, s32 file) {
    LDPlayer* p = &D_800FF008_LimboDance[obj->work[0]];

    obj->motion[slot] = func_8001755C(file);
    p->mot[slot].id = func_80025E48(obj->motion[slot]);
    p->mot[slot].len = func_80025D40(obj->motion[slot]);
}

void func_800F78DC_LimboDance(s16 model, LDMot* mot, s16 loop) {
    D_800F2B7C[model].unk_08 = mot->id;
    D_800F2B7C[model].unk_4C = 1.0f;
    if (loop >= 0) {
        D_800F2B7C[model].unk_0A = 0;
        D_800F2B7C[model].unk_48 = 0.0f;
        D_800F2B7C[model].unk_50 = mot->len;
    } else {
        D_800F2B7C[model].unk_0A = 4;
        D_800F2B7C[model].unk_48 = mot->len;
        D_800F2B7C[model].unk_50 = 0.0f;
    }
}

void func_800F7984_LimboDance(void) {
    omObjData* obj;
    s16 i;
    s32 pl;

    obj = D_800F3FB0[D_800F2BC0] = omAddObj(1, 10, 10, -1, func_800F7B08_LimboDance);
    obj->work[0] = 0;
    for (i = 0; i < 4; i++) {
        if (GwPlayer[i].group == 0) {
            break;
        }
    }
    switch (i) {
    case 1:
        pl = 1;
        break;
    case 2:
        pl = 2;
        break;
    case 3:
        pl = 3;
        break;
    case 0:
    default:
        pl = 0;
        break;
    }
    switch (GwPlayer[pl].cpu_difficulty) {
    case 0:
        D_800FEFF4_LimboDance = 0;
        break;
    case 1:
        D_800FEFF4_LimboDance = 1;
        break;
    case 2:
        D_800FEFF4_LimboDance = 2;
        break;
    case 3:
        D_800FEFF4_LimboDance = 3;
        break;
    default:
        D_800FEFF4_LimboDance = 1;
        break;
    }
    D_800FF062_LimboDance = GwPlayer[pl].character;
    D_800F2BC0++;
}

void func_800F7B08_LimboDance(omObjData* obj) {
    s16 stepA[2] = { 15, 56 };
    s16 stepB[2] = { 16, 60 };
    LDPlayer* p;
    s32 chr;
    u16 i;
    s16 pl;

    obj->func_ptr = func_800F7E40_LimboDance;
    p = &D_800FF008_LimboDance[obj->work[0]];
    for (i = 0; i < 4; i++) {
        if (GwPlayer[i].group == 0) {
            break;
        }
    }
    switch (i) {
    case 1:
        pl = 1;
        break;
    case 2:
        pl = 2;
        break;
    case 3:
        pl = 3;
        break;
    case 0:
    default:
        pl = 0;
        break;
    }
    D_800FF060_LimboDance = pl;
    chr = D_800C59AC[GwPlayer[(u16)pl].character].unk_00;
    obj->model[0] = LoadFormFile(chr | 0x9E, 0x299);
    obj->model[1] = LoadFormFile(6, 0x299);
    obj->model[3] = LoadFormFile(0x19, 0x2BD);
    obj->model[4] = LoadFormFile(0x1A, 0x2BD);
    obj->model[6] = LoadFormFile(0x1B, 0x2BD);
    obj->model[5] = LoadFormFile(0x1C, 0x2BD);
    obj->model[7] = LoadFormFile(0x1E, 0x2BD);
    obj->model[8] = LoadFormFile(0x1D, 0x2BD);
    func_800F9080_LimboDance(obj);
    p->port = GwPlayer[(u16)pl].port;
    if (GwPlayer[(u16)pl].flags & 1) {
        p->port = -1;
    }
    func_800F7824_LimboDance(obj, 0, chr | 0x6F);
    func_800F7824_LimboDance(obj, 1, chr | 0x70);
    func_800F7824_LimboDance(obj, 2, chr | 0x71);
    func_800F7824_LimboDance(obj, 3, chr | 0x92);
    func_800F7824_LimboDance(obj, 4, chr);
    func_800F7824_LimboDance(obj, 5, chr | stepA[func_800F7628_LimboDance(2)]);
    func_800F7824_LimboDance(obj, 6, chr | stepB[func_800F7628_LimboDance(2)]);
    func_800F78DC_LimboDance(obj->model[0], &p->mot[4], 1);
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    obj->rot.x = obj->rot.y = obj->rot.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    obj->rot.y = 90.0f;
    D_800F2B7C[obj->model[0]].unk_4C = 1.0f;
}

/* The dancer: lean back with A (CPU: func_800F8CA0), step under the bars, fall on a miss. */
// NON_MATCHING: register allocation / scheduling
#ifdef NON_MATCHING
void func_800F7E40_LimboDance(omObjData* obj) {
    LDPlayer* p;
    unk_ovl_2D_struct* m;
    f32 k;
    s16 r;
    s16 hit;
    s16 i;

    r = 0;
    p = &D_800FF008_LimboDance[obj->work[0]];
    m = &D_800F2B7C[obj->model[0]];
    hit = 0;
    switch (D_800FEFF6_LimboDance) {
    case 0:
        m->unk_12 = 0;
        goto anim_loop;
    case 2:
        if (obj->trans.y == 0.0f && D_800FF1BC_LimboDance == 0 && D_800FEFFC_LimboDance != 0) {
            r = func_800F8CA0_LimboDance(obj);
        }
        if (r > 0) {
            func_80017C0C(obj, 4, obj->trans.x + 20.0f, 0.0f, obj->trans.z, 0.0f, 0.0f);
            D_800F2B7C[obj->model[4]].unk_4C = 2.0f;
        }
        if (p->lean == 0.0) {
            k = 1.5f;
        } else if (p->lean < 35.0) {
            k = 1.0f;
        } else if (p->lean < 50.0) {
            k = 0.8f;
        } else {
            k = 0.7f;
        }
        switch (r) {
        case 1:
            p->vel = 10.0f;
            p->lean += k * 3.0;
            break;
        case 2:
            p->vel = 10.0f;
            p->lean += k * 6.0;
            break;
        case 3:
            p->vel = 10.0f;
            p->lean += k * 10.0;
            break;
        }
        if (D_800FE998_LimboDance != 0 && D_800FF1BC_LimboDance == 0) {
            p->vel = 0.0f;
            obj->trans.y = 0.0f;
            p->lean += 20.0;
        } else if (D_800FEFFC_LimboDance == 0 && D_800FF1BE_LimboDance == 0) {
            if (p->lean > 5.0) {
                p->lean -= 5.0;
            }
            hit = 0;
            if (D_800FE99C_LimboDance == 2 || D_800FE99C_LimboDance == 3) {
                D_800FEFF6_LimboDance = 10;
            }
        }
        if (func_800F9D48_LimboDance(obj->trans.x, p->lean) != 0) {
            func_800F750C_LimboDance(0x100, 5);
            func_80060540(0x305, 0);
            if (p->port != -1) {
                func_80060F04(D_800FF060_LimboDance, 20, 0, 20);
            }
            func_800601D4(0x28);
            D_800FF1BE_LimboDance = 1;
            D_800FE998_LimboDance = 1;
        }
        if (p->lean < 55.0f) {
            for (i = 0; i < 10; i++) {
                if (p->input[i] != 0) {
                    hit = 1;
                }
            }
            if (D_800FEFFC_LimboDance == 0) {
                hit = 0;
            }
            p->hist[D_800FE99E_LimboDance] = hit;
            D_800FE99E_LimboDance++;
            if (D_800FE99E_LimboDance >= 10) {
                D_800FE99E_LimboDance = 0;
            }
            switch (D_800FE99C_LimboDance) {
            case 0:
                if (D_800FE99A_LimboDance == 1 || m->unk_0C == -1) {
                    func_800F78DC_LimboDance(obj->model[0], &p->mot[1], 1);
                    func_80025C20(obj->model[0], p->mot[0].id, 0, 0x37, 0);
                }
                m->unk_12 = p->lean;
                D_800FE99A_LimboDance = 0;
                if ((p->lean == 0.0f) & (hit == 0)) {
                    m->unk_0C = -1;
                    D_800FE99C_LimboDance = 1;
                }
                break;
            case 1:
                func_800F78DC_LimboDance(obj->model[0], &p->mot[1], 1);
                func_80025C20(obj->model[0], p->mot[4].id, 0, 5, 0);
                D_800FE99C_LimboDance++;
                break;
            case 2:
                if (m->unk_0C == -1) {
                    func_800F78DC_LimboDance(obj->model[0], &p->mot[4], 1);
                    D_800FE99C_LimboDance++;
                }
                break;
            case 3:
                if (hit != 0) {
                    func_800F78DC_LimboDance(obj->model[0], &p->mot[4], 1);
                    func_80025C20(obj->model[0], p->mot[1].id, 0, 5, 0);
                    D_800FE99C_LimboDance++;
                }
                if (m->unk_50 <= m->unk_48) {
                    m->unk_48 = 0.0f;
                }
                break;
            case 4:
                if (m->unk_0C == -1) {
                    D_800FE99C_LimboDance++;
                }
                break;
            case 5:
                D_800FE99C_LimboDance = 0;
                D_800FE99A_LimboDance = 1;
                break;
            }
        } else if (p->lean < 60.0f) {
            m->unk_0C = -1;
            if (D_800FE99A_LimboDance == 0 || m->unk_50 <= m->unk_48) {
                func_80060540(0x307, 0);
                func_800F78DC_LimboDance(obj->model[0], &p->mot[3], 1);
            }
            D_800FE99A_LimboDance = 1;
        } else {
            m->unk_0C = -1;
            func_800F78DC_LimboDance(obj->model[0], &p->mot[0], 1);
            D_800FEFF6_LimboDance = 3;
            D_800FEFF8_LimboDance = 0;
            obj->trans.y = p->vel = 0.0f;
        }
        obj->trans.y += p->vel;
        if (obj->trans.y > 0.0f) {
            p->vel -= 4.0;
            if (D_800FEFFC_LimboDance == 0) {
                obj->trans.y = 0.0f;
                p->vel = 0.0f;
            } else {
                obj->trans.x += 20.0;
                if (func_800F9CFC_LimboDance(obj->trans.x) != 0) {
                    D_800FF1BC_LimboDance = 1;
                }
            }
        }
        if (obj->trans.y == 0.0f) {
            if (D_800FF1BC_LimboDance != 0) {
                if (m->unk_0C == -1) {
                    func_800F78DC_LimboDance(obj->model[0], &p->mot[1], 1);
                    func_80025C20(obj->model[0], p->mot[0].id, 0, 0x37, 0);
                }
                m->unk_12 = p->lean;
                D_800FEFF8_LimboDance = 0;
                D_800FEFF6_LimboDance = 7;
                func_800601D4(0x28);
                p->vel = 20.0f;
            } else {
                hit = 0;
                if (p->lean > 0.0f) {
                    for (i = 0; i < 10; i++) {
                        hit |= p->hist[i];
                    }
                    if (hit == 0) {
                        p->lean -= 1.0;
                    } else {
                        p->lean -= 0.5;
                    }
                }
                if (p->lean <= 0.0f) {
                    p->lean = 0.0f;
                }
            }
        } else if (obj->trans.y < 0.0f) {
            obj->trans.y = 0.0f;
            p->vel = 0.0f;
        }
        break;
    case 3:
        if (D_800FEFF8_LimboDance == 0) {
            if (D_800FF1BE_LimboDance == 0) {
                func_800F750C_LimboDance(0x100, 5);
                func_80060540(0x306, 0);
                if (p->port != -1) {
                    func_80060F04(D_800FF060_LimboDance, 10, 0, 10);
                }
                func_800601D4(0x28);
            }
            func_80017C0C(obj, 8, obj->trans.x, 0.0f, obj->trans.z, 0.0f, 0.0f);
            func_800F78DC_LimboDance(obj->model[0], &p->mot[0], 1);
            func_80025C20(obj->model[0], p->mot[2].id, 0, 5, 0);
            D_800FEFF8_LimboDance++;
        } else if (D_800FEFF8_LimboDance >= 6) {
            func_800F78DC_LimboDance(obj->model[0], &p->mot[2], 1);
            D_800FEFF6_LimboDance = 4;
            if (func_800F9C98_LimboDance() != 0) {
                D_800FF000_LimboDance = 1;
            }
        } else {
            D_800FEFF8_LimboDance++;
        }
        break;
    case 4:
    anim_loop:
        if (m->unk_50 <= m->unk_48) {
            m->unk_48 = 0.0f;
        }
        break;
    case 5:
        if (D_800FEFF8_LimboDance == 0) {
            func_80025C20(obj->model[0], p->mot[1].id, 0, 10, 0);
            D_800FEFF8_LimboDance++;
        } else if (D_800FEFF8_LimboDance >= 11) {
            D_800F2B7C[obj->model[0]].unk_4C = 0.0f;
            func_80025C20(obj->model[0], p->mot[0].id, 0, 0x37, 0);
            D_800FEFF6_LimboDance = 2;
            func_800F9D48_LimboDance(obj->trans.x, 0.0f);
            p->lean = 0.0f;
        } else {
            D_800FEFF8_LimboDance++;
        }
        break;
    case 6:
        if (D_800FF1C2_LimboDance == 0) {
            obj->rot.y += func_800F76BC_LimboDance(0.0f, obj->rot.y, 10.0f);
        }
        if (D_800FEFF8_LimboDance == 0) {
            D_800FF000_LimboDance = 1;
            if (p->mot[4].len <= m->unk_48) {
                m->unk_48 = 0.0f;
            }
            if (D_800FF1C0_LimboDance != 0) {
                func_80025C20(obj->model[0], p->mot[5].id, 0, 30, 0);
                D_800FEFF8_LimboDance++;
            }
        } else if (D_800FEFF8_LimboDance == 1 && m->unk_0C == -1) {
            D_800FEFF8_LimboDance = 2;
        } else if (D_800FEFF8_LimboDance == 2 && m->unk_0C == -1) {
            if (obj->rot.y == 0.0f) {
                D_800FEFF8_LimboDance = 3;
            }
        } else if (D_800FEFF8_LimboDance == 3) {
            D_800FEFF6_LimboDance = 9;
            D_800FEFF8_LimboDance = 0;
        }
        break;
    case 7:
        switch (D_800FEFF8_LimboDance) {
        case 0:
            obj->trans.y += p->vel;
            p->vel -= 4.0;
            obj->trans.x += 20.0;
            func_800F9CFC_LimboDance(obj->trans.x);
            m->unk_12 = p->lean;
            if (obj->trans.y <= 0.0f) {
                D_800FEFF8_LimboDance = 1;
            }
            break;
        case 1:
            if (m->unk_0C == -1) {
                func_800F78DC_LimboDance(obj->model[0], &p->mot[1], 1);
                func_80025C20(obj->model[0], p->mot[0].id, 0, 0x37, 0);
            }
            m->unk_12 = p->lean;
            p->lean -= 3.0;
            if (p->lean <= 0.0f) {
                p->lean = 0.0f;
                D_800FEFF8_LimboDance = 2;
            }
            break;
        case 2:
            m->unk_0C = -1;
            func_800F78DC_LimboDance(obj->model[0], &p->mot[4], 1);
            obj->trans.y = 0.0f;
            D_800FEFF8_LimboDance = 0;
            D_800FEFF6_LimboDance = 6;
            break;
        }
        break;
    case 10:
        if (p->mot[4].len <= m->unk_48) {
            m->unk_48 = 0.0f;
        }
        if (D_800FF1C0_LimboDance != 0) {
            obj->trans.y = 0.0f;
            D_800FEFF6_LimboDance = 8;
            func_80025C20(obj->model[0], p->mot[6].id, 0, 10, 0);
        }
        break;
    }
    func_80025830(obj->model[4], 0.5f, 0.5f, 0.5f);
    func_80025798(obj->model[1], obj->trans.x, 0.0f, 0.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_29_LimboDance/1E0A30", func_800F7E40_LimboDance);
#endif

/* Input: 2 when A was pressed (a human), else the CPU's choice (0..3); -1 for a CPU between
   decisions. Pushes it into the input ring. */
// register allocation (masked 0, raw 3): $f0/$f2 swapped in the volume cvt.s.d/trunc.w.s; an s16 cast, h or a new f32 local do not fix it
#ifdef NON_MATCHING
s16 func_800F8CA0_LimboDance(omObjData* obj) {
    LDPlayer* p;
    LDBar* b;
    f32 h;
    s16 r;
    s16 in;
    s16 i;

    h = 0.0f;
    p = &D_800FF008_LimboDance[obj->work[0]];
    r = 0;
    if (p->port != -1) {
        if (D_800FE9A2_LimboDance != 0) {
            for (i = 0; i < 10; i++) {
                p->input[i] = 0;
            }
            D_800FE9A2_LimboDance = 0;
            goto end;
        }
        in = 0x15;
        if (ContBtnTrg[p->port] & 0x8000) {
            r = 2;
        } else {
            in = 0;
            r = 0;
        }
        p->input[D_800FE9A0_LimboDance] = in;
        D_800FE9A0_LimboDance++;
        if (D_800FE9A0_LimboDance >= 10) {
            D_800FE9A0_LimboDance = 0;
        }
    } else {
        r = -1;
        if (D_800FE9A0_LimboDance >= D_800FE9A4_LimboDance) {
            b = D_800FF068_LimboDance;
            for (i = 0; i < D_800FF064_LimboDance; i++, b++) {
                if (b->active != 0 && obj->trans.x - 100.0f < b->x0 && b->x0 < obj->trans.x + 500.0) {
                    if (h < b->height) {
                        h = b->height;
                    }
                }
            }
            h += D_800FEFF4_LimboDance * 2 + 5;
            if (h > 40.0f) {
                if (p->bold != 0) {
                    if (p->seed & 1) {
                        h += 10.0;
                    } else {
                        h -= 10.0;
                    }
                }
                h += func_800F7628_LimboDance(5) - func_800F7628_LimboDance(15 - p->skill);
            } else {
                h += func_800F7628_LimboDance(15 - p->skill);
            }
            if (p->lean < h) {
                r = 2;
                if (p->lean < 43.0) {
                    r = 3;
                }
            } else {
                r = 0;
                if (p->lean < 43.0) {
                    r = 1;
                }
            }
            if (r == 0 && (func_800F7628_LimboDance(0) & 7)) {
                r = 1;
            }
        }
        p->input[D_800FE9A0_LimboDance] = r;
        D_800FE9A0_LimboDance++;
        if (D_800FE9A0_LimboDance >= 10) {
            D_800FE9A0_LimboDance = 0;
        }
    }
end:
    if (r > 0) {
        i = func_80060540(D_800FF062_LimboDance + 0x2FF, 0);
        if (i != -1) {
            func_80060440(i, (f32)(p->lean / 60.0 * 500.0));
        }
    }
    return r;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_29_LimboDance/1E0A30", func_800F8CA0_LimboDance);
#endif

// NON_MATCHING: register allocation / scheduling
#ifdef NON_MATCHING
void func_800F9080_LimboDance(omObjData* obj) {
    LDPlayer* p = &D_800FF008_LimboDance[obj->work[0]];
    s16 i;

    func_8009B770(p, 0, sizeof(LDPlayer));
    p->active = 1;
    p->port = -1;
    p->vel = 0.0f;
    p->lean = 0.0f;
    p->skill = func_800F7628_LimboDance(10) + 1;
    p->skill -= D_800FEFF4_LimboDance * 2;
    if (p->skill <= 0) {
        p->skill = 1;
    }
    switch (D_800FEFF4_LimboDance) {
    case 0:
        if (func_800F7628_LimboDance(100) < 26) {
            p->bold = 0;
        } else {
            p->bold = 1;
        }
        break;
    case 1:
        if (func_800F7628_LimboDance(100) < 51) {
            p->bold = 0;
        } else {
            p->bold = 1;
        }
        break;
    case 2:
        if (func_800F7628_LimboDance(100) < 76) {
            p->bold = 0;
        } else {
            p->bold = 1;
        }
        break;
    case 3:
        if (func_800F7628_LimboDance(100) < 101) {
            p->bold = 0;
        } else {
            p->bold = 1;
        }
        break;
    }
    p->seed = func_800F7628_LimboDance(0);
    for (i = 0; i < 10; i++) {
        p->input[i] = 0;
        p->hist[i] = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_29_LimboDance/1E0A30", func_800F9080_LimboDance);
#endif

void func_800F922C_LimboDance(void) {
    D_800F2AF8[D_800ED440] = omAddObj(2, 31, 0, -1, func_800F929C_LimboDance);
    D_800ED440++;
    D_800FF064_LimboDance = 0;
    D_800FF1C4_LimboDance = 0;
}

/* The bars: two courses (5 or 12 bars, heights 20..50), and the goal. */
// NON_MATCHING: register allocation / scheduling
#ifdef NON_MATCHING
void func_800F929C_LimboDance(omObjData* obj) {
    LDBar* b;
    f32 x;
    s32 n;
    u16 i;

    n = 0;
    obj->func_ptr = func_800F9A28_LimboDance;
    obj->model[0] = LoadFormFile(0x3D0004, 0xBD);
    obj->model[1] = LoadFormFile(0x3D0007, 0xBD);
    obj->model[2] = LoadFormFile(0x3D0005, 0xBD);
    obj->model[3] = LoadFormFile(0x3D0008, 0xBD);
    obj->model[4] = LoadFormFile(0x3D0006, 0xBD);
    obj->model[5] = LoadFormFile(0x3D0009, 0xBD);
    b = D_800FF068_LimboDance;
    for (i = 0; i < 12; i++, b++) {
        b->active = 0;
    }
    x = 50.0f;
    if (rand8() & 1) {
        func_800F97B8_LimboDance(n++, &obj->model[6], obj->model, 650.0f, 20);
        func_800F97B8_LimboDance(n++, &obj->model[6], obj->model, 1250.0f, 35);
        func_800F97B8_LimboDance(n++, &obj->model[6], obj->model, 1850.0f, 20);
        func_800F97B8_LimboDance(n++, &obj->model[6], obj->model, 2450.0f, 35);
        func_800F97B8_LimboDance(n++, &obj->model[6], obj->model, 3050.0f, 50);
        x = 3650.0f;
    } else {
        x += 500.0;
        func_800F97B8_LimboDance(n++, &obj->model[6], obj->model, x, 20);
        x += 400.0;
        func_800F97B8_LimboDance(n++, &obj->model[6], obj->model, x, 35);
        x += 400.0;
        func_800F97B8_LimboDance(n++, &obj->model[6], obj->model, x, 35);
        x += 600.0;
        func_800F97B8_LimboDance(n++, &obj->model[6], obj->model, x, 50);
        x += 600.0;
        func_800F97B8_LimboDance(n++, &obj->model[6], obj->model, x, 35);
        x += 400.0;
        func_800F97B8_LimboDance(n++, &obj->model[6], obj->model, x, 50);
        x += 400.0;
        func_800F97B8_LimboDance(n++, &obj->model[6], obj->model, x, 50);
        x += 600.0;
        func_800F97B8_LimboDance(n++, &obj->model[6], obj->model, x, 20);
        x += 200.0;
        func_800F97B8_LimboDance(n++, &obj->model[6], obj->model, x, 50);
        x += 200.0;
        func_800F97B8_LimboDance(n++, &obj->model[6], obj->model, x, 50);
        x += 200.0;
        func_800F97B8_LimboDance(n++, &obj->model[6], obj->model, x, 50);
        x += 200.0;
        func_800F97B8_LimboDance(n++, &obj->model[6], obj->model, x, 50);
        x += 300.0;
    }
    D_800FF1B8_LimboDance = x;
    obj->model[30] = LoadFormFile(0x3B0004, 0x99);
    func_80025798(obj->model[30], D_800FF1B8_LimboDance, -40.0f, 0.0f);
    func_800257E4(obj->model[30], 0.0f, 270.0f, 0.0f);
    func_80025830(obj->model[30], 0.65f, 0.65f, 0.65f);
    obj->trans.x = D_800FF068_LimboDance[0].x0;
    obj->trans.y = D_800FF068_LimboDance[0].y0;
    obj->trans.z = 0.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_29_LimboDance/1E0A30", func_800F929C_LimboDance);
#endif

/* Bar i at x, height (cm): its posts' heights come from the dancer's character. */
void func_800F97B8_LimboDance(s16 i, s16* models, s16* src, f32 x, u16 height) {
    f32 tbl[6][7] = {
        { -80.0f, -70.0f, -60.0f, -55.0f, -40.0f, -40.0f, -35.0f },
        { -105.0f, -85.0f, -75.0f, -65.0f, -55.0f, -45.0f, -30.0f },
        { -100.0f, -90.0f, -70.0f, -60.0f, -50.0f, -40.0f, -30.0f },
        { -100.0f, -90.0f, -60.0f, -45.0f, -30.0f, -30.0f, -30.0f },
        { -95.0f, -80.0f, -70.0f, -60.0f, -50.0f, -35.0f, -30.0f },
        { -100.0f, -75.0f, -55.0f, -40.0f, -30.0f, -30.0f, -30.0f },
    };
    LDBar* b;
    s32 k;
    s16 row;

    b = &D_800FF068_LimboDance[i];
    b->active = 1;
    b->height = (s16)height;
    row = 6 - (s16)height / 10;
    b->x0 = x - 20.0;
    b->x1 = b->x0 + 20.0;
    b->y0 = tbl[D_800FF062_LimboDance][row] / 20.0 * 20.0;
    b->y1 = b->y0 + 200.0;
    if ((s16)height < 21) {
        k = 0;
    } else {
        k = 4;
        if (b->height <= 40.0f) {
            k = 2;
        }
    }
    models[D_800FF064_LimboDance * 2] = func_80023FC8(src[k]);
    models[D_800FF064_LimboDance * 2 + 1] = func_80023FC8(src[k + 1]);
    func_800258EC(models[D_800FF064_LimboDance * 2], 4, 0);
    func_800258EC(models[D_800FF064_LimboDance * 2 + 1], 4, 0);
    func_80025798(models[D_800FF064_LimboDance * 2], b->x0, b->y0, 0.0f);
    func_80025798(models[D_800FF064_LimboDance * 2 + 1], b->x1, b->y1, 0.0f);
    D_800FF064_LimboDance++;
}

void func_800F9A28_LimboDance(omObjData* obj) {
    LDBar* b;
    u16 i;

    b = D_800FF068_LimboDance;
    for (i = 0; i < D_800FF064_LimboDance; i++, b++) {
        if (b->active != 0) {
            switch (b->state) {
            case 0:
                break;
            case 1:
                b->x1 += 10.0;
                b->y1 += b->vel;
                b->vel -= 4.0;
                if (b->y1 <= 25.0) {
                    b->y1 = 25.0f;
                    b->vel = 80.0f;
                    b->state++;
                    D_800FF000_LimboDance = 1;
                }
                break;
            case 2:
                b->x1 += 10.0;
                b->y1 -= b->vel;
                b->vel -= 4.0;
                if (b->y1 <= 25.0) {
                    b->y1 = 25.0f;
                    b->vel = 40.0f;
                    b->state++;
                    b->active = 0;
                }
                break;
            }
        }
        func_80025798(obj->model[6 + i * 2], b->x0, b->y0, 0.0f);
        func_80025798(obj->model[7 + i * 2], b->x1, b->y1, 0.0f);
    }
    func_80025798(obj->model[30], D_800FF1B8_LimboDance, -40.0f, 0.0f);
    func_800257E4(obj->model[30], 0.0f, 270.0f, 0.0f);
    func_80025830(obj->model[30], 0.65f, 0.65f, 0.65f);
}

/* 1 when every bar is still up and untouched. */
s16 func_800F9C98_LimboDance(void) {
    LDBar* b;
    u16 i;

    b = D_800FF068_LimboDance;
    for (i = 0; i < D_800FF064_LimboDance; i++, b++) {
        /* retail tests active and state as one word */
        if (*(s32*)&b->active != 0x10000) {
            break;
        }
    }
    return i == D_800FF064_LimboDance;
}

s16 func_800F9CFC_LimboDance(f32 x) {
    func_800FB04C_LimboDance(x);
    Center.x = x;
    return D_800FF1B8_LimboDance < x;
}

/* Knocks off the bar the dancer at x (leaning back lean) hits; 1 on a hit. */
// NON_MATCHING: register allocation / scheduling
#ifdef NON_MATCHING
s16 func_800F9D48_LimboDance(f32 x, f32 lean) {
    LDBar* b;
    s32 still;
    s16 i;

    if (D_800FF1BE_LimboDance != 0) {
        return 0;
    }
    still = 0;
    if (D_800FE9A8_LimboDance == x) {
        still = 1;
    }
    if (D_800FF062_LimboDance == 5) {
        x -= (lean / 20.0 + 0.3) * 100.0;
    }
    b = D_800FF068_LimboDance;
    for (i = 0; i < D_800FF064_LimboDance; i++, b++) {
        if (b->active != 0 && b->x0 <= x && D_800FE9A8_LimboDance < b->x0) {
            if (D_800FF062_LimboDance == 5) {
                x += (lean / 20.0 + 0.3) * 100.0;
            }
            if (!(b->x0 + 100.0f <= x) && lean < b->height) {
                D_800FE9A8_LimboDance = x;
                D_800FE9AC_LimboDance = lean;
                b->state = 1;
                b->vel = 10.0f;
                return 1;
            }
        }
    }
    b = D_800FF068_LimboDance;
    for (i = 0; i < D_800FF064_LimboDance; i++, b++) {
        if (b->active != 0 && ((b->height >= 40.0f) & still) && lean < D_800FE9AC_LimboDance &&
            x - 100.0f <= b->x0 && b->x0 < x && lean < b->height - 10.0f) {
            D_800FE9A8_LimboDance = x;
            D_800FE9AC_LimboDance = lean;
            b->state = 1;
            b->vel = 20.0f;
            return 1;
        }
    }
    D_800FE9A8_LimboDance = x;
    D_800FE9AC_LimboDance = lean;
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_29_LimboDance/1E0A30", func_800F9D48_LimboDance);
#endif
