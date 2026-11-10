#include "MushroomMixup.h"

u8 D_800FC700_MushroomMixup = 0;
u8 D_800FC701_MushroomMixup = 0;
u8 D_800FC702_MushroomMixup = 0;
u8 D_800FC703_MushroomMixup = 0;
s16 D_800FC704_MushroomMixup = 0;
s16 D_800FC706_MushroomMixup = 0;
s16 D_800FC708_MushroomMixup = 0;
s32 D_800FC70C_MushroomMixup = 0;
s32 D_800FC710_MushroomMixup[4] = { 0, 0, 0, 0 };

void func_800F65E0_MushroomMixup(void) {
    omObjData* obj;
    u8 cam;

    func_80029090(0x32);
    func_8002ADF0(&D_800EDEC0, 0x40);
    func_8001DE70(0x20);
    omInitObjMan(0x32, 0);
    func_80060088();
    func_8000942C();
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    func_800178A0(1);
    cam = func_800178E8();
    func_80017660(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 16.0f, 100.0f, 5000.0f);
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    func_800F6DF4_MushroomMixup();
    omAddObj(0xA, 0, 0, -1, func_800F9EC0_MushroomMixup);
    obj = omAddObj(1, 1, 0, -1, func_800FA320_MushroomMixup);
    D_800F2AF8[D_800ED440++] = obj;
    func_800090B8(D_800ED440);
    obj = omAddObj(1, 1, 0, -1, func_800FA454_MushroomMixup);
    D_800F2AF8[D_800ED440++] = obj;
    omSetStatBit(obj, 0xA0);
    obj = omAddObj(1, 1, 0, -1, func_800FBFB0_MushroomMixup);
    D_800F2AF8[D_800ED440++] = obj;
    obj = omAddObj(1, 1, 0, -1, func_800FC068_MushroomMixup);
    D_800F2AF8[D_800ED440++] = obj;
    obj = omAddObj(1, 1, 0, -1, func_800FC114_MushroomMixup);
    D_800F2AF8[D_800ED440++] = obj;
    obj = omAddObj(1, 1, 0, -1, func_800FC1C0_MushroomMixup);
    D_800F2AF8[D_800ED440++] = obj;
    obj = omAddObj(1, 1, 0, -1, func_800FC26C_MushroomMixup);
    D_800F2AF8[D_800ED440++] = obj;
    obj = omAddObj(1, 1, 0, -1, func_800FC318_MushroomMixup);
    D_800F2AF8[D_800ED440++] = obj;
    obj = omAddObj(1, 1, 0, -1, func_800FC3C4_MushroomMixup);
    D_800F2AF8[D_800ED440++] = obj;
    func_800F6CF4_MushroomMixup();
    func_80009500();
    obj = omAddObj(2, 9, 0x32, -1, func_800FBE30_MushroomMixup);
    D_800F3FB0[D_800F2BC0++] = obj;
    obj = omAddObj(2, 9, 0x32, -1, func_800FBE90_MushroomMixup);
    D_800F3FB0[D_800F2BC0++] = obj;
    obj = omAddObj(2, 9, 0x32, -1, func_800FBEEC_MushroomMixup);
    D_800F3FB0[D_800F2BC0++] = obj;
    obj = omAddObj(2, 9, 0x32, -1, func_800FBF4C_MushroomMixup);
    D_800F3FB0[D_800F2BC0++] = obj;
    omAddObj(3, 2, 0, -1, func_800FAAE8_MushroomMixup);
    omAddObj(4, 0, 0, -1, func_800FB11C_MushroomMixup);
    omSetStatBit(omAddObj(4, 6, 0, -1, func_800FC6C8_MushroomMixup), 0xA0);
    omSetStatBit(omAddObj(4, 6, 0, -1, func_800FC6E4_MushroomMixup), 0xA0);
    omAddObj(1, 1, 0, -1, func_800FC46C_MushroomMixup);
    omAddObj(1, 1, 0, -1, func_800FC4A4_MushroomMixup);
    omAddObj(1, 1, 0, -1, func_800FC4FC_MushroomMixup);
    omAddObj(1, 1, 0, -1, func_800FC554_MushroomMixup);
    omAddObj(1, 1, 0, -1, func_800FC5AC_MushroomMixup);
    omAddObj(1, 1, 0, -1, func_800FC604_MushroomMixup);
    omAddObj(1, 1, 0, -1, func_800FC65C_MushroomMixup);
    omAddObj(0xA, 0, 0, -1, func_800F9E9C_MushroomMixup);
    omAddObj(1, 0, 0, -1, func_800F6CA8_MushroomMixup);
    func_8002890C(0x20, 0xA0, 0x50);
    SetFadeInTypeAndTime(0, 0x10);
}

void func_800F6CA8_MushroomMixup(omObjData* arg0) {
    switch ((s32)((D_800F5144 ^ 1) < 1)) {
        case 0:
            break;
        default:
            func_800601D4(0x28);
            func_8002890C(0, 0, 0);
            omOvlReturnEx(1);
            break;
    }
}

/* A random order of the four players in D_800FC8AE. */
void func_800F6CF4_MushroomMixup(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 r;

    for (i = 0; i < 4; i++) {
        r = rand8() % (4 - i);
        for (j = 0; j < 4; j++) {
            for (k = i; k != 0; k--) {
                if (D_800FC8AE_MushroomMixup[k - 1] == j) {
                    break;
                }
            }
            if (k != 0) {
                continue;
            }
            if (r == 0) {
                break;
            }
            r--;
        }
        if (j >= 4) {
            j = i;
        }
        D_800FC8AE_MushroomMixup[i] = j;
    }
}

void func_800F6DF4_MushroomMixup(void) {
    f32 cam[3][4]; /* set and never read (retail keeps the stores) */
    MMPlayerState* st;
    s32 i;

    D_800FC98C_MushroomMixup = -1;
    D_800FC8AC_MushroomMixup = 0;
    D_800FC9A0_MushroomMixup = 0;
    D_800FC8A0_MushroomMixup = 0;
    D_800FC890_MushroomMixup = 0x3C;
    D_800FC9B8_MushroomMixup = 0.0f;
    D_800FC818_MushroomMixup = 1;
    D_800FC990_MushroomMixup = 0;
    D_800FC810_MushroomMixup = 1;
    D_800FC814_MushroomMixup = 0;
    D_800FC820_MushroomMixup = D_800FC81C_MushroomMixup = D_800FC824_MushroomMixup = (u8)(rand8() % 6);
    D_800FC828_MushroomMixup = (u8)(rand8() % 7);
    if (D_800FC828_MushroomMixup == D_800FC824_MushroomMixup) {
        D_800FC828_MushroomMixup++;
    }
    if (D_800FC828_MushroomMixup >= 7) {
        D_800FC828_MushroomMixup = 0;
    }
    st = D_800FC8B8_MushroomMixup;
    for (i = 0; i < 4; i++) {
        D_800FC892_MushroomMixup[i] = 0;
        st->flags = 0;
        st->state = i % 2;
        st->color = 6;
        st->wait = 0;
        st->stkX = 0;
        st->stkY = 0;
        st->btnTrg = 0;
        st->target = 0;
        st->unk_20 = 10000.0f;
        st->unk_24 = 10000.0f;
        st++;
    }
    D_800FC996_MushroomMixup = 0;
    CZoom = 2766.0f;
    CRot.x = 309.0f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    Center.x = 4.0f;
    Center.y = 188.0f;
    Center.z = -219.0f;
    cam[0][0] = 48.0f;
    cam[0][1] = 4002.0f;
    cam[0][2] = 5932.0f;
    cam[1][0] = 48.0f;
    cam[1][1] = 376.0f;
    cam[1][2] = -348.0f;
    cam[2][0] = 0.0f;
    cam[2][1] = -1.0f;
    cam[2][2] = 0.0f;
}

void func_800F7088_MushroomMixup(u16 arg0) {
    func_80025EB4(arg0, 1, 1);
    func_80026040(arg0);
}

void func_800F70C4_MushroomMixup(void) {
    LoadFormBinary(DataRead(0x2C0001), 0x20D);
}

void func_800F70F0_MushroomMixup(s16 arg0, u32 arg1) {
    MMNameTable names = D_800FC794_MushroomMixup;

    if (arg1 < 7) {
        func_80027AC8(arg0, (u8*)names.name[0], (u8*)names.name[arg1]);
        func_80025AD4(arg0);
    }
}

void func_800F7188_MushroomMixup(s16 arg0) {
    PlaySound((s32) arg0);
}

u16 func_800F71A8_MushroomMixup(u8 model, u8 phase, u8 arg2, u8 colL, u8 colR) {
    MMColorTable tbl = D_800FC7B0_MushroomMixup;
    unk_ovl_2D_struct* m;

    m = &D_800F2B7C[model];
    func_80028180(model, D_800FC7DC_MushroomMixup, tbl.c[colL].r, tbl.c[colL].g, tbl.c[colL].b, 1);
    func_80028180(model, D_800FC7EC_MushroomMixup, tbl.c[colR].r, tbl.c[colR].g, tbl.c[colR].b, 0);
    if (!arg2) {
        switch (phase) {
        case 0:
            m->unk_4C = 1.5f;
            if (D_800ED554[m->unk_08].unk_02 / 4 < m->unk_48) {
                return 0;
            }
            break;
        case 1:
            if (D_800ED554[m->unk_08].unk_02 / 2 < m->unk_48) {
                return 0;
            }
            break;
        case 2:
            m->unk_4C = 1.5f;
            if (D_800ED554[m->unk_08].unk_02 / 4 * 3 < m->unk_48) {
                return 0;
            }
            break;
        case 3:
            if (D_800ED554[m->unk_08].unk_02 <= m->unk_48) {
                return 0;
            }
            break;
        }
    } else if (phase) {
        m->unk_48 = m->unk_50;
    }
    m->unk_0A &= 0xFFFE;
    m->unk_48 = func_800369FC(&D_800ED554[m->unk_08], m->unk_0A, m->unk_48, m->unk_50, m->unk_4C);
    func_80025EB4(model, 1, 1);
    return 1;
}

u16 func_800F7574_MushroomMixup(void) {
    s32 index;
    s32 flags;

    index = 0; // goes from 0 -> 6

    // check if all flags are 1(?)
    flags = (s32) D_800FC98C_MushroomMixup; // is D_800FC98C_MushroomMixup a 1-byte array of length 6?
loop_1:
    if ((flags >> index) & 1) {
        index += 1;
        if (index >= NUM_OF_MUSHROOMS) {
            return TRUE;
        }
        goto loop_1;
    }
    return FALSE;
}


// phase flags read as u8 (retail s8: lb), register allocation; same states, calls and stores
#ifdef NON_MATCHING
void func_800F75B0_MushroomMixup(omObjData* arg0) {
    u16 model;
    u16 i;

    if (D_800ED430 != 1) {
        return;
    }
    model = arg0->model[0];
    if (D_800FC700_MushroomMixup == 0) {
        if (!func_800F7574_MushroomMixup()) {
            return;
        }
        if (D_800FC702_MushroomMixup == 0) {
            D_800FC990_MushroomMixup = 0;
            D_800FC818_MushroomMixup = 0;
            D_800FC706_MushroomMixup = 0;
            D_800FC702_MushroomMixup = 1;
            D_800FC703_MushroomMixup = 0;
        }
        if (D_800FC706_MushroomMixup++ == 5) {
            func_800F7188_MushroomMixup(0x28D);
        }
        if (func_800F71A8_MushroomMixup(model, D_800FC700_MushroomMixup, 0, (u8)D_800FC824_MushroomMixup,
                                        (u8)D_800FC828_MushroomMixup)) {
            return;
        }
        if (D_800FC703_MushroomMixup == 0 && D_800FC708_MushroomMixup != 0) {
            D_800FC703_MushroomMixup = 1;
        }
        if (D_800FC704_MushroomMixup <= 0) {
            D_800FC704_MushroomMixup++;
            return;
        }
        D_800FC820_MushroomMixup = D_800FC824_MushroomMixup;
        for (i = 0; i < 4; i++) {
            D_800FC8B8_MushroomMixup[i].color = (u16)D_800FC820_MushroomMixup;
            D_800FC8B8_MushroomMixup[i].flags &= 0xFFF9;
            switch (D_800FC8B8_MushroomMixup[i].difficulty) {
            case 0:
                D_800FC8B8_MushroomMixup[i].wait = 0x28;
                break;
            case 1:
                D_800FC8B8_MushroomMixup[i].wait = 0x19;
                break;
            case 2:
                D_800FC8B8_MushroomMixup[i].wait = 0xA;
                break;
            case 3:
                D_800FC8B8_MushroomMixup[i].wait = 0;
                break;
            }
        }
        D_800FC702_MushroomMixup = 0;
        D_800FC704_MushroomMixup = 0;
        if (D_800FC890_MushroomMixup > 0) {
            D_800FC9B8_MushroomMixup += 0.0f;
        } else {
            D_800FC9B8_MushroomMixup += 1.5f;
        }
        if (D_800FC9B8_MushroomMixup > 50.0f) {
            D_800FC9B8_MushroomMixup = 50.0f;
        }
        for (i = 0; i < 7; i++) {
            D_800FC9C0_MushroomMixup[i].speed = -5.0f - D_800FC9B8_MushroomMixup;
        }
        D_800FC700_MushroomMixup++;
    }
    if (D_800FC700_MushroomMixup == 1) {
        if (D_800FC704_MushroomMixup < D_800FC890_MushroomMixup) {
            D_800FC704_MushroomMixup++;
            return;
        }
        if (D_800FC702_MushroomMixup == 0) {
            D_800FC814_MushroomMixup = 0;
            D_800FC702_MushroomMixup = 1;
        }
        D_800FC81C_MushroomMixup = D_800FC824_MushroomMixup;
        D_800FC98C_MushroomMixup = 0;
        if (func_800F71A8_MushroomMixup(model, D_800FC700_MushroomMixup, 0, (u8)D_800FC824_MushroomMixup,
                                        (u8)D_800FC828_MushroomMixup)) {
            return;
        }
        if (D_800FC701_MushroomMixup == 0) {
            D_800FC824_MushroomMixup = D_800FC828_MushroomMixup;
            D_800FC828_MushroomMixup = (u8)(rand8() % 7);
            if (D_800FC828_MushroomMixup == D_800FC824_MushroomMixup) {
                D_800FC828_MushroomMixup++;
            }
            if (D_800FC828_MushroomMixup >= 7) {
                D_800FC828_MushroomMixup = 0;
            }
            D_800FC701_MushroomMixup = 1;
        }
        if (D_800FC890_MushroomMixup > 0) {
            D_800FC890_MushroomMixup -= 0xC;
        }
        D_800FC702_MushroomMixup = 0;
        D_800FC704_MushroomMixup = 0;
        D_800FC701_MushroomMixup = 0;
        D_800FC708_MushroomMixup++;
        D_800FC700_MushroomMixup++;
    } else if (D_800FC700_MushroomMixup == 2) {
        if (!func_800F7574_MushroomMixup()) {
            return;
        }
        if (D_800FC702_MushroomMixup == 0) {
            D_800FC990_MushroomMixup = 0;
            D_800FC818_MushroomMixup = 0;
            D_800FC706_MushroomMixup = 0;
            D_800FC702_MushroomMixup = 1;
            D_800FC703_MushroomMixup = 0;
        }
        if (D_800FC706_MushroomMixup++ == 5) {
            func_800F7188_MushroomMixup(0x28D);
        }
        if (func_800F71A8_MushroomMixup(model, D_800FC700_MushroomMixup, 0, (u8)D_800FC828_MushroomMixup,
                                        (u8)D_800FC824_MushroomMixup)) {
            return;
        }
        if (D_800FC703_MushroomMixup == 0) {
            D_800FC703_MushroomMixup = 1;
        }
        if (D_800FC704_MushroomMixup <= 0) {
            D_800FC704_MushroomMixup++;
            return;
        }
        D_800FC820_MushroomMixup = D_800FC824_MushroomMixup;
        for (i = 0; i < 4; i++) {
            D_800FC8B8_MushroomMixup[i].color = (u16)D_800FC820_MushroomMixup;
            D_800FC8B8_MushroomMixup[i].flags &= 0xFFF9;
            switch (D_800FC8B8_MushroomMixup[i].difficulty) {
            case 0:
                D_800FC8B8_MushroomMixup[i].wait = 0x28;
                break;
            case 1:
                D_800FC8B8_MushroomMixup[i].wait = 0x19;
                break;
            case 2:
                D_800FC8B8_MushroomMixup[i].wait = 0xA;
                break;
            case 3:
                D_800FC8B8_MushroomMixup[i].wait = 0;
                break;
            }
        }
        D_800FC702_MushroomMixup = 0;
        D_800FC704_MushroomMixup = 0;
        if (D_800FC890_MushroomMixup > 0) {
            D_800FC9B8_MushroomMixup += 0.0f;
        } else {
            D_800FC9B8_MushroomMixup += 1.5f;
        }
        if (D_800FC9B8_MushroomMixup > 50.0f) {
            D_800FC9B8_MushroomMixup = 50.0f;
        }
        for (i = 0; i < 7; i++) {
            D_800FC9C0_MushroomMixup[i].speed = -5.0f - D_800FC9B8_MushroomMixup;
        }
        D_800FC700_MushroomMixup++;
    }
    if (D_800FC700_MushroomMixup == 3) {
        if (D_800FC704_MushroomMixup < D_800FC890_MushroomMixup) {
            D_800FC704_MushroomMixup++;
            return;
        }
        if (D_800FC702_MushroomMixup == 0) {
            D_800FC814_MushroomMixup = 0;
            D_800FC702_MushroomMixup = 1;
        }
        D_800FC81C_MushroomMixup = D_800FC824_MushroomMixup;
        D_800FC98C_MushroomMixup = 0;
        if (func_800F71A8_MushroomMixup(model, D_800FC700_MushroomMixup, 0, (u8)D_800FC828_MushroomMixup,
                                        (u8)D_800FC824_MushroomMixup)) {
            return;
        }
        if (D_800FC701_MushroomMixup == 0) {
            D_800FC824_MushroomMixup = D_800FC828_MushroomMixup;
            D_800FC828_MushroomMixup = (u8)(rand8() % 7);
            if (D_800FC828_MushroomMixup == D_800FC824_MushroomMixup) {
                D_800FC828_MushroomMixup++;
            }
            if (D_800FC828_MushroomMixup >= 7) {
                D_800FC828_MushroomMixup = 0;
            }
            D_800FC701_MushroomMixup = 1;
        }
        func_800F71A8_MushroomMixup(model, D_800FC700_MushroomMixup, 1, (u8)D_800FC824_MushroomMixup,
                                    (u8)D_800FC828_MushroomMixup);
        if (D_800FC890_MushroomMixup > 0) {
            D_800FC890_MushroomMixup -= 0xC;
        }
        D_800FC702_MushroomMixup = 0;
        D_800FC701_MushroomMixup = 0;
        D_800FC704_MushroomMixup = 0;
        D_800FC708_MushroomMixup++;
        D_800FC700_MushroomMixup = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_MushroomMixup/1784E0", func_800F75B0_MushroomMixup);
#endif

// register allocation (masked 0, raw 9): both "D_800FC98C |= 1 << work[0]" build the bit in v0, retail in v1
#ifdef NON_MATCHING
void func_800F7FCC_MushroomMixup(omObjData* arg0) {
    MMMushroom* rec;

    if (D_800ED430 == 2) {
        func_800258EC(arg0->model[0], 0x1C00, 0x400);
        D_800F2B7C[arg0->model[0]].unk_6C->unk_28 = 1;
    } else if (D_800ED430 == 1) {
        rec = &D_800FC9C0_MushroomMixup[arg0->work[0]];
        if ((D_800FC8A0_MushroomMixup == 0 || rec->state == 2) && !((D_800FC98C_MushroomMixup >> arg0->work[0]) & 1)) {
            if ((rec->color & 7) == D_800FC81C_MushroomMixup) {
                D_800FC98C_MushroomMixup |= 1 << arg0->work[0];
                return;
            }
            if (arg0->trans.y < -620.0f) {
                if (D_800FC818_MushroomMixup == 0) {
                    D_800FC818_MushroomMixup = 1;
                    D_800FC990_MushroomMixup = 0;
                    D_800FC810_MushroomMixup = 0;
                }
                rec->speed = D_800FC9B8_MushroomMixup + 10.0f;
            }
            if (D_800FC8A0_MushroomMixup == 0 || rec->state == 2) {
                if (D_800FC810_MushroomMixup == 0 && arg0->trans.y > -520.0f) {
                    D_800FC810_MushroomMixup = 1;
                }
                if (D_800FC814_MushroomMixup == 0 && D_800FC98C_MushroomMixup == 0) {
                    D_800FC814_MushroomMixup = 1;
                    func_800F7188_MushroomMixup(0x28F);
                }
                arg0->trans.y += rec->speed;
                rec->state = 2;
                if (rec->speed > 0.0f && arg0->trans.y < -400.0f) {
                    rec->state = 1;
                }
                if (arg0->trans.y > rec->topY) {
                    D_800FC98C_MushroomMixup |= 1 << arg0->work[0];
                    arg0->trans.y = rec->topY;
                    rec->state = 0;
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_MushroomMixup/1784E0", func_800F7FCC_MushroomMixup);
#endif

u8 func_800F8260_MushroomMixup(omObjData* arg0) {
    s32 var_a1;

    var_a1 = 0;
    if ((arg0->trans.y < 50.0f) && (arg0->work[2] != 1)) {
        arg0->work[2] = 1;
    }
    if (arg0->work[2] != 0) {
        var_a1 = 1;
    }
    return var_a1;
}

// decomp-permuter
void func_800F82AC_MushroomMixup(omObjData *arg0)
{
  MMPlayerWork *work;
  s32 n;
  s32 bit;
  u8 p;
  work = arg0->unk_50;
  p = arg0->work[0];
  n = ++(*(D_800FC892_MushroomMixup + p));
  if (n == 1)
  {
    bit = n << p;
    D_800FC8A0_MushroomMixup |= bit;
    D_800FC9A0_MushroomMixup |= bit;
    func_800F7188_MushroomMixup(0x292);
    func_80060F04(work->unk_58, 0x14, 0, 0x14);
    func_800258EC(arg0->model[2], 4, 0);
    func_8001E2A8(work->unk_23, 0);
    func_8001E2F8(work->unk_23, 0xC8);
    func_8001E268(work->unk_23, 4, 4);
    func_80025798(arg0->model[2], arg0->trans.x, arg0->trans.y + 100.0f, arg0->trans.z + 180.0f);
    func_80025830(arg0->model[2], 6.0f, 6.0f, 6.0f);
    work->unk_40 = D_800B8990;
    func_800258EC(arg0->model[1], 4, 4);
  }
  if (arg0->work[1] == 0)
  {
    arg0->work[1] = 1;
    func_800185A4(arg0, 0x10);
    func_80017DB0(arg0);
  }
  if (arg0->trans.y > 50.0f)
  {
    arg0->trans.y = arg0->trans.y - 1.5f;
    func_800093FC(arg0, arg0->trans.x, arg0->trans.y, arg0->trans.z);
  }
}

s32 func_800F846C_MushroomMixup(u16 arg0) {
    MMPlayerWork* work;
    s32 res;
    s32 ret;

    if (arg0 == 4) {
        return 1;
    }
    work = D_800FC880_MushroomMixup[arg0];
    res = func_80017A60(D_800FC9A8_MushroomMixup[arg0]);
    ret = 0;
    if (work->unk_38 == 1000.0f) {
        ret = (res & 6) != 0;
    }
    return ret;
}

// loop counter widths (s8/u16) and register allocation; same decisions
/* The round's winner: a player index, 4 when nobody, -1 while undecided. */
#ifdef NON_MATCHING
s8 func_800F84F0_MushroomMixup(void) {
    omObjData* obj;
    MMPlayerWork* work;
    s8 res;
    u8 ok;
    u16 alive;
    u16 j;
    s8 i;
    u16 any;

    res = -1;
    ok = 1;
    alive = 0;
    for (j = 0; j < 4; j++) {
        if (D_800FC9A8_MushroomMixup[j]->work[2] == 0) {
            alive++;
        }
    }
    if (alive < 2) {
        for (i = 0; (u16)i < 4; i++) {
            obj = D_800FC9A8_MushroomMixup[(u16)i];
            work = D_800FC880_MushroomMixup[(u16)i];
            if (obj->work[2] == 0) {
                break;
            }
        }
        if ((u16)i < 4 && (u8)(work->unk_53 - 2) < 7 && !func_800F7574_MushroomMixup()) {
            ok = (D_800FC9C0_MushroomMixup[work->unk_53 - 2].color & 7) == D_800FC81C_MushroomMixup;
        }
        if (ok && alive == 1) {
            D_800FC996_MushroomMixup = 1;
        }
        if ((u8)func_800F846C_MushroomMixup((u16)i) & ok) {
            if ((u16)i == 4) {
                if (D_800FC9C8_MushroomMixup == 2 && D_800FC9C0_MushroomMixup[0].obj->trans.y >= -620.0f) {
                    i = -1;
                }
                res = i;
                if (D_800FC9EC_MushroomMixup == 2 && D_800FC9E4_MushroomMixup.obj->trans.y >= -620.0f) {
                    res = -1;
                }
            } else {
                work = D_800FC880_MushroomMixup[(u16)i];
                func_80008FB8(obj, 0.0f);
                work->unk_40 = 0.0f;
                if (D_800FC70C_MushroomMixup < 3) {
                    D_800FC70C_MushroomMixup++;
                    i = -1;
                }
                res = i;
            }
        } else {
            D_800FC70C_MushroomMixup = 0;
        }
    }
    if (_CheckFlag(0x2B) != 0 && res == -1 && D_800FC9A8_MushroomMixup[0]->work[2] != 0) {
        D_800FC996_MushroomMixup = 1;
        any = 0;
        if (D_800FC9C8_MushroomMixup == 2 && D_800FC9C0_MushroomMixup[0].obj->trans.y >= -620.0f) {
            any = 1;
        }
        if (D_800FC9EC_MushroomMixup == 2 && D_800FC9E4_MushroomMixup.obj->trans.y >= -620.0f) {
            any = 1;
        }
        if (any == 0) {
            res = 4;
        }
    }
    return res;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_MushroomMixup/1784E0", func_800F84F0_MushroomMixup);
#endif

void func_800F8840_MushroomMixup(void) {
}

void func_800F8848_MushroomMixup(omObjData* arg0) {
    MMPlayerState* st;
    u8 p;

    p = arg0->work[0];
    st = &D_800FC8B8_MushroomMixup[p];
    if (GwPlayer[p].flags & 1) {
        st->flags |= 1;
        st->difficulty = GwPlayer[p].cpu_difficulty;
    }
}

// register allocation (masked 2, raw 15): s0/s1/s2 hold other/arg0/dp in retail; declaration order does not move them
/* A +-45 degree detour around the player the CPU is chasing (work unk_54). */
#ifdef NON_MATCHING
f32 func_800F88AC_MushroomMixup(omObjData* arg0, f32 x, f32 z) {
    Vec3f d;
    omObjData* other;
    f32 a;
    f32 b;
    f32 off;
    f32 r;
    Vec3f* dp;

    r = 0.0f;
    if (MM_PLAYER(arg0)->unk_54 != -1) {
        dp = &d;
        other = D_800F3FB0[MM_PLAYER(arg0)->unk_54];
        func_800A0D00(dp, x, 0.0f, z);
        d.x -= arg0->trans.x;
        d.y -= 0.0f;
        d.z -= arg0->trans.z;
        a = func_80029518(func_800B0CD8(d.x, d.z));
        func_800A0D00(dp, other->trans.x, 0.0f, other->trans.z);
        d.x -= arg0->trans.x;
        d.y -= 0.0f;
        d.z -= arg0->trans.z;
        b = func_80029518(func_800B0CD8(d.x, d.z));
        if ((a - b < 0.0f ? -(a - b) : a - b) > 180.0f) {
            off = -45.0f;
        } else {
            off = 45.0f;
        }
        if (a - b < 0.0f) {
            off = -off;
        }
        r += off;
    }
    return r;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_MushroomMixup/1784E0", func_800F88AC_MushroomMixup);
#endif

// retail reaches d through a register and copies floats as words; register allocation
/* The CPU: writes the pad state its player object reads this frame. */
#ifdef NON_MATCHING
void func_800F8A58_MushroomMixup(omObjData* arg0) {
    Vec3f d;
    MMPlayerWork* work;
    MMPlayerState* st;
    u16 p;
    u16 tgt;
    u16 i;
    u16 hit;
    f32 a;

    work = arg0->unk_50;
    func_80017A60(arg0);
    p = arg0->work[0];
    st = &D_800FC8B8_MushroomMixup[p];
    if (!(st->flags & 1)) {
        return;
    }
    tgt = st->target;
    ContBtn[GwPlayer[p].port] = 0;
    ContBtnTrg[GwPlayer[p].port] = 0;
    ContStkX[GwPlayer[p].port] = 0;
    ContStkY[GwPlayer[p].port] = 0;
    if (D_800FC8A0_MushroomMixup != 0 && (st->flags & 2)) {
        st->flags &= 0xFFFD;
        st->state = 0;
        for (i = 0; i < 7; i++) {
            if ((D_800FC9C0_MushroomMixup[i].color & 7) == D_800FC81C_MushroomMixup) {
                break;
            }
        }
        st->target = i;
        tgt = i;
        st->color = D_800FC9C0_MushroomMixup[i].color & 7;
    }
    switch (st->state) {
    case 0:
        if (st->wait != 0) {
            st->wait--;
            st->stkX = 0;
            st->stkY = 0;
            break;
        }
        d.x = D_800FC9C0_MushroomMixup[tgt].pos.x;
        d.y = 0.0f;
        d.z = D_800FC9C0_MushroomMixup[tgt].pos.z;
        d.x -= arg0->trans.x;
        d.z -= arg0->trans.z;
        for (i = 0; i < 7; i++) {
            if (D_800FC9C0_MushroomMixup[i].colIdx == work->unk_53) {
                break;
            }
        }
        if (i < 7 && st->color != (D_800FC9C0_MushroomMixup[i].color & 7)) {
            for (i = 0; i < 7; i++) {
                if ((D_800FC9C0_MushroomMixup[i].color & 7) == st->color) {
                    break;
                }
            }
            st->target = i;
            tgt = i;
        } else {
            if (D_800FC810_MushroomMixup != 0 && D_800FC9C0_MushroomMixup[0].speed > 0.0f && !(st->flags & 2) &&
                D_800FC8A0_MushroomMixup == 0 && (u16)(st->difficulty - 2) < 2) {
                st->flags |= 2;
                st->target = 0;
                tgt = 0;
                st->color = D_800FC9C0_MushroomMixup[0].color & 7;
            } else {
                if (func_800A1200(&d) > 50.0f && !(st->flags & 4)) {
                    if (work->unk_54 != -1) {
                        st->flags |= 4;
                    }
                    a = func_800B0CD8(d.x, d.z) +
                        func_800F88AC_MushroomMixup(arg0, D_800FC9C0_MushroomMixup[tgt].pos.x, D_800FC9C0_MushroomMixup[tgt].pos.z);
                    st->stkX = func_800AEAC0(a) * 60.0f;
                    st->stkY = func_800AEFD0(a) * 60.0f;
                    break;
                }
                return;
            }
        }
        a = func_800B0CD8(d.x, d.z) +
            func_800F88AC_MushroomMixup(arg0, D_800FC9C0_MushroomMixup[tgt].pos.x, D_800FC9C0_MushroomMixup[tgt].pos.z);
        st->stkX = func_800AEAC0(a) * 60.0f;
        st->stkY = func_800AEFD0(a) * 60.0f;
        st->state = 1;
        break;
    case 1:
        if (st->wait != 0) {
            st->wait--;
            st->stkX = 0;
            st->stkY = 0;
            break;
        }
        d.y = 0.0f;
        d.x = D_800FC9C0_MushroomMixup[st->target].pos.x;
        d.z = D_800FC9C0_MushroomMixup[st->target].pos.z;
        d.x -= arg0->trans.x;
        d.z -= arg0->trans.z;
        a = func_800B0CD8(d.x, d.z);
        if (func_800A1200(&d) < 300.0f && arg0->trans.y < D_800FC9C0_MushroomMixup[st->target].obj->trans.y + 490.0f) {
            st->btnTrg |= 0x8000;
            st->btn |= 0x8000;
            st->timer = 0xA;
            st->unk_28 = arg0->trans.x;
            st->unk_30 = arg0->trans.z;
            st->state = 2;
        } else {
            a += func_800F88AC_MushroomMixup(arg0, D_800FC9C0_MushroomMixup[st->target].pos.x,
                                             D_800FC9C0_MushroomMixup[st->target].pos.z);
            st->state = 0;
        }
        st->stkX = func_800AEAC0(a) * 60.0f;
        st->stkY = func_800AEFD0(a) * 60.0f;
        break;
    case 2:
        d.y = 0.0f;
        hit = 100;
        for (i = 0; i < 4; i++) {
            if (i != p) {
                d.x = D_800FC9A8_MushroomMixup[i]->trans.x;
                d.z = D_800FC9A8_MushroomMixup[i]->trans.z;
                d.x -= arg0->trans.x;
                d.z -= arg0->trans.z;
                if (func_800A1200(&d) <= work->unk_48 + D_800FC880_MushroomMixup[i]->unk_48 && hit == 100) {
                    hit = i;
                    a = func_800B0CD8(d.x, d.z);
                    st->stkX = -(func_800AEAC0(a) * 60.0f);
                    st->stkY = -(func_800AEFD0(a) * 60.0f);
                }
            }
        }
        func_800A0D00(&d, arg0->trans.x, 0.0f, arg0->trans.z);
        d.x -= D_800FC9C0_MushroomMixup[st->target].obj->trans.x;
        d.y -= 0.0f;
        d.z -= D_800FC9C0_MushroomMixup[st->target].obj->trans.z;
        if (func_800A1200(&d) < 100.0f) {
            st->btnTrg |= 0x2000;
            st->state = 0;
            break;
        }
        st->unk_28 = arg0->trans.x;
        st->unk_30 = arg0->trans.z;
        st->btnTrg = 0;
        if (st->timer == 0) {
            st->btn = 0;
            if (work->unk_53 != -1) {
                st->stkX = 0;
                st->stkY = 0;
                st->state = 0;
            }
        } else {
            st->timer--;
        }
        break;
    case 4:
        st->state = 0;
        break;
    }
    ContBtn[GwPlayer[p].port] = st->btn;
    ContBtnTrg[GwPlayer[p].port] = st->btnTrg;
    ContStkX[GwPlayer[p].port] = st->stkX;
    ContStkY[GwPlayer[p].port] = -(s8)st->stkY;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_MushroomMixup/1784E0", func_800F8A58_MushroomMixup);
#endif

void func_800F9364_MushroomMixup(omObjData* arg0) {
    if (D_800FC994_MushroomMixup != 0) {
        Center.x += D_800FC89C_MushroomMixup;
        Center.y += D_800FC99C_MushroomMixup;
        Center.z += D_800FC998_MushroomMixup;
        CZoom += D_800FC988_MushroomMixup;
        D_800FC994_MushroomMixup -= 1;
    }
    else {
        arg0->func_ptr = NULL;
    }
}

void func_800F93F0_MushroomMixup(omObjData* arg0) {
    omObjData* obj;
    MMPlayerWork* work;

    obj = D_800FC9A8_MushroomMixup[(s16)D_800FCABC_MushroomMixup];
    work = D_800FC880_MushroomMixup[(s16)D_800FCABC_MushroomMixup];
    work->unk_40 = 0.0f;
    work->unk_3C = 0.0f;
    func_8009ECB0(D_800F2B7C[obj->model[0]].unk7C, work->unk_3C, work->unk_3C, work->unk_3C);
    D_800FC994_MushroomMixup = 0x1B;
    D_800FC89C_MushroomMixup = (obj->trans.x - Center.x) / 27.0f;
    D_800FC99C_MushroomMixup = (obj->trans.y - Center.y) / 27.0f;
    D_800FC998_MushroomMixup = (obj->trans.z - Center.z) / 27.0f;
    D_800FC988_MushroomMixup = (1300.0f - CZoom) / 27.0f;
    arg0->func_ptr = func_800F9364_MushroomMixup;
}

void func_800F9510_MushroomMixup(omObjData* arg0, s32 arg1) {
    func_80025798(arg0->model[arg1], arg0->trans.x, arg0->trans.y, arg0->trans.z);
}

// register allocation, u16 vs s16 load of D_800FC996 (tested != 0)
/* A player's object function during the rounds. */
// register allocation (masked 0, raw 13): retail swaps s2/s3 (st and the ContBtnTrg base); declaring st first does not move them
#ifdef NON_MATCHING
void func_800F9548_MushroomMixup(omObjData* arg0) {
    MMPlayerWork* work;
    MMPlayerState* st;
    MMMushroom* rec;
    s32 p;

    p = arg0->work[0];
    work = arg0->unk_50;
    st = &D_800FC8B8_MushroomMixup[p];
    st->savBtn = ContBtn[GwPlayer[p].port];
    st->savBtnTrg = ContBtnTrg[GwPlayer[p].port];
    st->savStkX = ContStkX[GwPlayer[p].port];
    st->savStkY = ContStkY[GwPlayer[p].port];
    if (func_800F8260_MushroomMixup(arg0) == 0) {
        func_800F8A58_MushroomMixup(arg0);
        ContBtnTrg[GwPlayer[p].port] &= 0xBFFF;
        if (D_800FC996_MushroomMixup != 0) {
            ContBtn[GwPlayer[p].port] = 0;
            ContBtnTrg[GwPlayer[p].port] = 0;
            ContStkX[GwPlayer[p].port] = 0;
            ContStkY[GwPlayer[p].port] = 0;
            work->unk_40 = 0.0f;
        }
        if ((u8)(work->unk_53 - 2) < 7) {
            rec = &D_800FC9C0_MushroomMixup[work->unk_53 - 2];
            if ((rec->color & 7) != D_800FC81C_MushroomMixup && D_800FC8A0_MushroomMixup == 0 && rec->state == 2 &&
                rec->speed < 0.0f) {
                if (D_800FC710_MushroomMixup[arg0->work[0]] == 0) {
                    D_800FC710_MushroomMixup[arg0->work[0]] = 0xC;
                    func_80060F04(work->unk_58, 2, 3, 0xA);
                } else {
                    D_800FC710_MushroomMixup[arg0->work[0]]--;
                }
            }
        }
        func_80005A28(arg0);
        ContBtn[GwPlayer[p].port] = st->savBtn;
        ContBtnTrg[GwPlayer[p].port] = st->savBtnTrg;
        ContStkX[GwPlayer[p].port] = st->savStkX;
        ContStkY[GwPlayer[p].port] = st->savStkY;
        func_800F8260_MushroomMixup(arg0);
    } else {
        func_800F82AC_MushroomMixup(arg0);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_MushroomMixup/1784E0", func_800F9548_MushroomMixup);
#endif

// retail reaches d through a register; register allocation
/* The start: each player walks to its partner (work[3]) and they turn to face each other. */
#ifdef NON_MATCHING
void func_800F9890_MushroomMixup(omObjData* arg0) {
    Vec3f d;
    MMPlayerWork* work;
    MMPlayerWork* otherWork;
    omObjData* other;
    MMPlayerState* st;
    MMPlayerState* ost;
    f32 a;
    u8 p;
    u8 q;

    p = arg0->work[0];
    work = arg0->unk_50;
    q = arg0->work[3];
    other = D_800F3FB0[q];
    otherWork = other->unk_50;
    st = &D_800FC8B8_MushroomMixup[p];
    ost = &D_800FC8B8_MushroomMixup[q];
    st->savBtn = ContBtn[GwPlayer[p].port];
    st->savBtnTrg = ContBtnTrg[GwPlayer[p].port];
    st->savStkX = ContStkX[GwPlayer[p].port];
    st->savStkY = ContStkY[GwPlayer[p].port];
    st->stkY = 0;
    st->stkX = 0;
    st->btnTrg = 0;
    switch (st->state) {
    case 0:
        func_800A0D00(&d, other->trans.x, 0.0f, other->trans.z);
        d.x -= arg0->trans.x;
        d.y -= 0.0f;
        d.z -= arg0->trans.z;
        if (func_800A1200(&d) > 100.0f) {
            a = func_80029518(func_800B0CD8(d.x, d.z));
            st->stkX = func_800AEAC0(a) * 60.0f;
            st->stkY = func_800AEFD0(a) * 60.0f;
        } else {
            st->btnTrg |= 0x4000;
            if (ost->state == 1) {
                ost->state = 2;
                ost->timer = 0xA;
            }
            st->timer = 0xA;
            st->state = 3;
        }
        break;
    case 1:
        break;
    case 2:
        if (st->timer != 0) {
            st->timer--;
        }
        if ((func_80017A60(D_800FC9A8_MushroomMixup[p]) & 2) && st->timer == 0) {
            st->state = 0;
        }
        break;
    case 3:
        if (st->timer != 0) {
            st->timer--;
        }
        if (otherWork->unk_40 == 0.0f && st->timer == 0) {
            st->state = 4;
        }
        break;
    }
    ContBtnTrg[GwPlayer[p].port] = st->btnTrg;
    ContStkX[GwPlayer[p].port] = st->stkX;
    ContStkY[GwPlayer[p].port] = -(s8)st->stkY;
    func_80009458();
    func_80009468();
    func_80005A28(arg0);
    func_8000942C();
    func_80009468();
    ContBtn[GwPlayer[p].port] = st->savBtn;
    ContBtnTrg[GwPlayer[p].port] = st->savBtnTrg;
    ContStkX[GwPlayer[p].port] = st->savStkX;
    ContStkY[GwPlayer[p].port] = st->savStkY;
    if (st->state == 4 && ost->state == 4) {
        func_8006071C(work->unk_B3);
        arg0->func_ptr = func_800F9548_MushroomMixup;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_MushroomMixup/1784E0", func_800F9890_MushroomMixup);
#endif

void func_800F9CF0_MushroomMixup(omObjData* arg0) {
    u8 temp_v0;
    u8 temp_v0_2;

    switch (arg0->work[0]) {
    case 0:
        temp_v0 = arg0->work[1];
        arg0->work[1] = temp_v0 + 1;
        if (temp_v0 >= 0x2E) {
            arg0->work[0] = 1;
            arg0->work[1] = 0;
        }
        CZoom = 2766.0f;
        CRot.x = 309.0f;
        CRot.y = 0.0f;
        CRot.z = 0.0f;
        Center.x = 4.0f;
        Center.y = 188.0f;
        Center.z = -219.0f;
        return;
    case 1:
        temp_v0_2 = arg0->work[1];
        arg0->work[1] = temp_v0_2 + 1;
        if (temp_v0_2 < 0x1E) {
            CZoom += 36.666668f;
            Center.x += 2.0f;
            return;
        }
        arg0->work[0] = 2;
    case 2:
        CZoom = 3866.0f;
        CRot.x = 309.0f;
        CRot.y = 0.0f;
        CRot.z = 0.0f;
        Center.x = 64.0f;
        Center.y = 188.0f;
        Center.z = -214.0f;
        arg0->func_ptr = NULL;
        return;
    }
}

void func_800F9E9C_MushroomMixup(omObjData* arg0) {
    arg0->work[0] = 0;
    arg0->work[1] = 0;
    arg0->func_ptr = &func_800F9CF0_MushroomMixup;
}
