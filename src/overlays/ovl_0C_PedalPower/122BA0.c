#include "common.h"
#include "PedalPower.h"

/* .data (0x800F9E20) */
u8 D_800F9E20_PedalPower = 0;    /* cars placed so far (func_800F8D34) */
u8 D_800F9E21_PedalPower = 0xFF; /* light texture alpha */
s32 D_800F9E24_PedalPower = 0;   /* frame counter */
u8 D_800F9E28_PedalPower = 0;    /* sounds started */
s32 D_800F9E2C_PedalPower = 0;
s32 D_800F9E30_PedalPower = 0;
u8 D_800F9E34_PedalPower = 0;
f32 D_800F9E38_PedalPower[3] = { -480.0f, -300.0f, -120.0f };

extern omObjData* D_800F2AF8[];
extern unk2C0C0Struct70* D_800F37AC;
extern u8 D_800F64F8;
f32 func_80025D18(s16);
void func_80027E48(s16 arg0, f32 arg1, f32 arg2, u16 arg3, u16 arg4, char* arg5, u8 arg6);

void func_800F7AEC_PedalPower(omObjData* arg0);
void func_800F7C04_PedalPower(omObjData* arg0);
void func_800F886C_PedalPower(omObjData* arg0);
void func_800F89F0_PedalPower(omObjData* arg0);
void func_800F8D34_PedalPower(omObjData* arg0);
void func_800F8E08_PedalPower(omObjData* arg0);

void func_800F79B0_PedalPower(void) {
    s32 i;

    D_800ED440 = 0;
    func_800090B8(0);
    D_800F2AF8[D_800ED440++] = omAddObj(1, 4, 0, -1, func_800F7AEC_PedalPower);
    omAddObj(1, 6, 0, -1, func_800F7C04_PedalPower);
    omAddObj(1, 1, 0, -1, func_800F886C_PedalPower);
    for (i = 0; i < 3; i++) {
        D_800F2AF8[D_800ED440++] = omAddObj(1, 1, 0, -1, func_800F8D34_PedalPower);
    }
    omAddObj(1, 1, 0, -1, func_800F8E08_PedalPower);
}

void func_800F7AEC_PedalPower(omObjData* arg0) {
    unkGlobalStruct_02* temp_s1;

    arg0->model[0] = func_800174C0(0x1E0002, 0x99);
    arg0->model[1] = func_800174C0(0x1E0003, 0x99);
    arg0->model[2] = func_800174C0(0x14, 0x99);
    arg0->model[3] = func_800174C0(0x1E0008, 0x99);
    arg0->trans.x = arg0->trans.y = arg0->trans.z = 0.0f;
    arg0->rot.x = 0.0f;
    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_80025798(arg0->model[3], arg0->trans.x, arg0->trans.y - 25.0f, arg0->trans.z);
    temp_s1 = func_80023684(sizeof(unkGlobalStruct_02), 0x7918);
    arg0->unk_50 = temp_s1;
    func_8009B770(temp_s1, 0, sizeof(unkGlobalStruct_02));
    temp_s1->unk_04 = 1;
    temp_s1->unk_05 = 0;
    arg0->func_ptr = &func_800F6944_PedalPower;
}

void func_800F7C04_PedalPower(omObjData* arg0) {
    unkGlobalStruct_02* temp_s0;

    D_800F9EFA_PedalPower = arg0->model[3] = func_800174C0(0x1E0004, 0x99);
    D_800F9EF6_PedalPower = arg0->model[2] = func_800174C0(0x1E0006, 0x99);
    D_800F9EF8_PedalPower = arg0->model[0] = func_800174C0(0x1E0000, 0x99);
    D_800F9EFC_PedalPower = arg0->model[1] = func_800174C0(0x1E0001, 0x699);
    arg0->model[4] = func_800174C0(0x1E0009, 0x99);
    arg0->model[5] = func_800174C0(0x1E000A, 0x99);
    func_80025CA8(D_800F9EF6_PedalPower, D_800FA720_PedalPower);
    func_80025EB4(D_800F9EF8_PedalPower, 2, 1);
    func_80025EB4(D_800F9EF6_PedalPower, 2, 1);
    func_80026040(D_800F9EFA_PedalPower);
    func_80039C48("15mt001_DEF", D_800F9EFE_PedalPower);
    D_800F9F04_PedalPower = 0.0f;
    arg0->trans.x = arg0->trans.y = arg0->trans.z = 0.0f;
    arg0->rot.x = 0.0f;
    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_80025798(arg0->model[5], arg0->trans.x, arg0->trans.y, arg0->trans.z + 100.0f);
    temp_s0 = func_80023684(sizeof(unkGlobalStruct_02), 0x7918);
    arg0->unk_50 = temp_s0;
    func_8009B770(temp_s0, 0, sizeof(unkGlobalStruct_02));
    temp_s0->unk_04 = 1;
    temp_s0->unk_05 = 0;
    arg0->func_ptr = &func_800F7DD4_PedalPower;
}

#define PP_SOUND_OFF() (func_8005FD5C() + D_800F64F8)

// register allocation of the light colour at the end (masked 2)
#ifdef NON_MATCHING
void func_800F7DD4_PedalPower(omObjData* arg0) {
    unk_ovl_2D_struct* s1;
    unk_ovl_2D_struct* s0;
    unk2C0C0Struct70* p;
    unk2C0C0StructC0* tex;
    u32* pix;
    s32 i;
    s32 j;
    u8 c;
    s32 c2;
    f32 zero;

    s1 = &D_800F2B7C[(s16)D_800F9EF8_PedalPower];
    s0 = &D_800F2B7C[(s16)D_800F9EF6_PedalPower];
    D_800FA720_PedalPower = func_80025D18(D_800F9EF6_PedalPower);
    switch (D_800ED430) {
    case 0:
        func_80025EB4(D_800F9EF6_PedalPower, 1, 1);
        func_80025EB4(D_800F9EF8_PedalPower, 1, 1);
        func_80027E48(D_800F9EFA_PedalPower, 0.0f, 0.0f, D_800F9EFE_PedalPower[0], D_800F9EFE_PedalPower[1], "15m_002b-1", 0);
        func_80027E48(D_800F9EFA_PedalPower, 0.0f, 0.0f, D_800F9EFE_PedalPower[0], D_800F9EFE_PedalPower[1], "15m_002b-1_1", 0);
        func_80027E48(D_800F9EFA_PedalPower, 0.0f, 0.0f, D_800F9EFE_PedalPower[0], D_800F9EFE_PedalPower[1], "15m_002b-1_2", 0);
        func_80027E48(D_800F9EFA_PedalPower, 0.0f, 0.0f, D_800F9EFE_PedalPower[0], D_800F9EFE_PedalPower[1], "15m_002b-1_3", 0);
        break;
    case 1:
        func_80025EB4(D_800F9EF6_PedalPower, 3, 2);
        func_80025EB4(D_800F9EF8_PedalPower, 3, 2);
        if (D_800F9E28_PedalPower == 0) {
            D_800F9EF2_PedalPower = PlaySound(0x22E);
            D_800F9EF4_PedalPower = PlaySound(0x22C);
            D_800F9E28_PedalPower = 1;
        }
        if (D_800FA738_PedalPower == 0 || PP_SOUND_OFF() != 0) {
            D_800F9EF0_PedalPower = 0;
        } else {
            D_800F9EF0_PedalPower = (D_800FA738_PedalPower * 120) / 70 + 32;
            if (D_800F9EF0_PedalPower > 120) {
                D_800F9EF0_PedalPower = 120;
            }
        }
        func_8006035C(D_800F9EF2_PedalPower, D_800F9EF0_PedalPower);
        switch (D_800FA72D_PedalPower) {
        case 0:
            D_800F9F04_PedalPower = s1->unk_4C = s0->unk_4C = 0.0f;
            if (PP_SOUND_OFF() == 0) {
                D_800F9EF1_PedalPower -= 10;
            }
            if (D_800F9EF1_PedalPower < 10) {
                D_800F9EF1_PedalPower = 0;
            }
            if (PP_SOUND_OFF() == 0) {
                func_8006035C(D_800F9EF4_PedalPower, D_800F9EF1_PedalPower);
            } else {
                func_8006035C(D_800F9EF4_PedalPower, 0);
            }
            func_80060440(D_800F9EF4_PedalPower, 0);
            break;
        case 1:
            s1->unk_4C = s0->unk_4C = 0.5f;
            D_800F9F04_PedalPower += 1.0f;
            if (PP_SOUND_OFF() == 0) {
                D_800F9EF1_PedalPower += 10;
            }
            if (D_800F9EF1_PedalPower > 100) {
                D_800F9EF1_PedalPower = 100;
            }
            if (PP_SOUND_OFF() == 0) {
                func_8006035C(D_800F9EF4_PedalPower, D_800F9EF1_PedalPower);
            } else {
                func_8006035C(D_800F9EF4_PedalPower, 0);
            }
            func_80060440(D_800F9EF4_PedalPower, 200);
            break;
        case 2:
            s1->unk_4C = s0->unk_4C = 1.0f;
            D_800F9F04_PedalPower += 2.0f;
            if (PP_SOUND_OFF() == 0) {
                D_800F9EF1_PedalPower += 10;
            }
            if (D_800F9EF1_PedalPower > 120) {
                D_800F9EF1_PedalPower = 120;
            }
            if (PP_SOUND_OFF() == 0) {
                func_8006035C(D_800F9EF4_PedalPower, D_800F9EF1_PedalPower);
            } else {
                func_8006035C(D_800F9EF4_PedalPower, 0);
            }
            func_80060440(D_800F9EF4_PedalPower, 400);
            break;
        case 3:
            s1->unk_4C = s0->unk_4C = 2.0f;
            D_800F9F04_PedalPower += 4.0f;
            D_800F9EF1_PedalPower = 0x7F;
            if (PP_SOUND_OFF() == 0) {
                func_8006035C(D_800F9EF4_PedalPower, D_800F9EF1_PedalPower);
            } else {
                func_8006035C(D_800F9EF4_PedalPower, 0);
            }
            func_80060440(D_800F9EF4_PedalPower, 600);
            break;
        }
        zero = 0.0f; /* retail: assigned in the last argument, evaluated first by GCC */
        func_80023504(3, zero, D_800FA738_PedalPower * 138.0f / 70.0f + -18.0f, zero);
        func_80025EB4(D_800F9EF6_PedalPower, 2, 2);
        func_80025EB4(D_800F9EF8_PedalPower, 2, 2);
        omSetStatBit(arg0, 0x20);
        if (PP_SOUND_OFF() != 0) {
            D_800F9F04_PedalPower = zero;
        }
        goto belts;
    case 2:
    case 3:
        if (D_800FA72C_PedalPower == 1) {
            s1->unk_4C = s0->unk_4C = 1.0f;
            D_800F9F04_PedalPower += 2.0f;
            omSetStatBit(arg0, 0x20);
            if (PP_SOUND_OFF() != 0) {
                D_800F9F04_PedalPower = 0.0f;
            }
        } else {
            if ((D_800F9E24_PedalPower & 3) == 0 && D_800FA738_PedalPower > 0) {
                D_800FA738_PedalPower--;
            }
            zero = 0.0f; /* retail: assigned in the last argument, evaluated first by GCC */
            func_80023504(3, zero, D_800FA738_PedalPower * 138.0f / 70.0f + -18.0f, zero);
            func_80060758(0x22C);
            func_80025EB4(D_800F9EF6_PedalPower, 2, 1);
            func_80025EB4(D_800F9EF8_PedalPower, 2, 1);
            D_800F9F04_PedalPower = zero;
        }
    belts:
        func_80027E48(D_800F9EFA_PedalPower, D_800F9F04_PedalPower, 0.0f, D_800F9EFE_PedalPower[0], D_800F9EFE_PedalPower[1], "15m_002b-1", 0);
        func_80027E48(D_800F9EFA_PedalPower, D_800F9F04_PedalPower, 0.0f, D_800F9EFE_PedalPower[0], D_800F9EFE_PedalPower[1], "15m_002b-1_1", 0);
        func_80027E48(D_800F9EFA_PedalPower, -D_800F9F04_PedalPower, 0.0f, D_800F9EFE_PedalPower[0], D_800F9EFE_PedalPower[1], "15m_002b-1_2", 0);
        func_80027E48(D_800F9EFA_PedalPower, -D_800F9F04_PedalPower, 0.0f, D_800F9EFE_PedalPower[0], D_800F9EFE_PedalPower[1], "15m_002b-1_3", 0);
        break;
    }
    tex = D_800F2B7C[(s16)D_800F9EFC_PedalPower].unk_6C;
    for (i = 0; i != 128; i++) {
        if (D_800F37AC[i].unk_28 == tex) {
            p = &D_800F37AC[i];
            pix = (u32*)p->unk_24;
            if (D_800FA72C_PedalPower == 2) {
                if (D_800F9E21_PedalPower != 0) {
                    D_800F9E21_PedalPower--;
                }
            } else if (D_800FA738_PedalPower < 70) {
                D_800F9E21_PedalPower = D_800FA738_PedalPower * 3 + 45;
            } else {
                D_800F9E21_PedalPower = 0xFF;
            }
            for (j = 0; j < p->unk_1A * p->unk_1B; j++) {
                *pix = ((*pix >> 8) << 8) | D_800F9E21_PedalPower;
                pix++;
            }
        }
    }
    c = (D_800FA738_PedalPower * 255) / 70;
    func_800234B8(2, c, c, c);
    func_800234B8(3, c, c, c);
    c2 = (c >> 1) + 16;
    if ((c >> 1) >= 0xF0) {
        c2 = 0x80;
    }
    func_800234B8(0, c2, c2, c2);
    D_800F9E24_PedalPower++;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_PedalPower/122BA0", func_800F7DD4_PedalPower);
#endif

void func_800F886C_PedalPower(omObjData* arg0) {
    unkGlobalStruct_02* work;
    unk2C0C0Struct70* p;
    unk2C0C0StructC0* tex;
    s32 i;
    s32 j;

    arg0->func_ptr = func_800F89F0_PedalPower;
    arg0->model[0] = func_800174C0(0x1E0005, 0x689);
    arg0->trans.x = -405.0f;
    arg0->trans.y = -350.0f;
    arg0->trans.z = 125.0f;
    arg0->scale.z = 2.0f;
    arg0->scale.y = 2.0f;
    arg0->scale.x = 2.0f;
    work = func_80023684(sizeof(unkGlobalStruct_02), 0x7918);
    arg0->unk_50 = work;
    func_8009B770(work, 0, sizeof(unkGlobalStruct_02));
    work->unk_04 = 1;
    work->unk_05 = 0;
    tex = D_800F2B7C[arg0->model[0]].unk_6C;
    for (i = 0; i != 128; i++) {
        if (D_800F37AC[i].unk_28 == tex) {
            p = &D_800F37AC[i];
            for (j = 0; j < p->unk_1A * p->unk_1B * 2; j++) {
                D_800F9F10_PedalPower[j] = p->unk_24[j];
            }
        }
    }
}

void func_800F89F0_PedalPower(omObjData* arg0) {
    unk2C0C0Struct70* p;
    unk2C0C0StructC0* tex;
    s32 i;
    s32 j;
    s32 lim;
    u8 orig;
    u8 v;

    if (D_800FA738_PedalPower == 70) {
        if (D_800F9E34_PedalPower == 0) {
            func_8006035C(PlaySound(0x22D), 0x7F);
            D_800F9E34_PedalPower = 1;
        }
    }
    lim = (D_800FA738_PedalPower < 31) ? 0 : (D_800FA738_PedalPower - 31) * 255 / 40;
    tex = D_800F2B7C[arg0->model[0]].unk_6C;
    for (i = 0; i != 128; i++) {
        if (D_800F37AC[i].unk_28 == tex) {
            p = &D_800F37AC[i];
            for (j = 0; j < p->unk_1A * p->unk_1B * 2; j++) {
                if (j & 1) {
                    v = p->unk_24[j];
                    orig = (D_800F9E30_PedalPower != 0) ? v : 0;
                    v = orig;
                    if (D_800FA738_PedalPower >= 30 && D_800FA72D_PedalPower != 0.0f) {
                        if (v < D_800F9F10_PedalPower[j] && D_800F9F10_PedalPower[j] >= 255 - D_800F9E2C_PedalPower
                            && v < D_800F9E2C_PedalPower) {
                            v = orig + 2;
                        }
                    }
                    if (D_800FA72D_PedalPower == 0.0f || D_800FA72C_PedalPower == 2) {
                        if (v >= 3) {
                            v -= 2;
                        } else {
                            v = 0;
                        }
                    }
                    p->unk_24[j] = v;
                }
            }
        }
    }
    if (D_800FA738_PedalPower >= 31) {
        if (D_800FA72D_PedalPower != 0.0f) {
            if (D_800F9E2C_PedalPower < 0xFE) {
                D_800F9E2C_PedalPower += 2;
            } else {
                D_800F9E2C_PedalPower = 0xFF;
            }
        }
        if (lim < D_800F9E2C_PedalPower) {
            D_800F9E2C_PedalPower = lim;
        }
    }
    if (D_800FA72D_PedalPower == 0.0f) {
        if (D_800F9E2C_PedalPower >= 3) {
            D_800F9E2C_PedalPower -= 2;
        } else {
            D_800F9E2C_PedalPower = 0;
        }
        if (D_800F9E2C_PedalPower < lim) {
            D_800F9E2C_PedalPower = lim;
        }
    }
    D_800F9E30_PedalPower++;
}

void func_800F8D34_PedalPower(omObjData* arg0) {
    unkGlobalStruct_02* temp_s0;

    arg0->model[0]= func_800174C0(0x190002, 0x99);
    arg0->trans.x = D_800F9E38_PedalPower[D_800F9E20_PedalPower];
    arg0->trans.y = 0.0f;
    arg0->trans.z = -50.0f;
    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, -50.0f);
    temp_s0 = func_80023684(sizeof(unkGlobalStruct_02), 0x7918);
    arg0->unk_50 = temp_s0;
    func_8009B770(temp_s0, 0, sizeof(unkGlobalStruct_02));
    temp_s0->unk_04 = 1;
    temp_s0->unk_05 = 0;
    arg0->func_ptr = NULL;
    D_800F9E20_PedalPower += 1;
}


void func_800F8E08_PedalPower(omObjData* arg0) {
    unkGlobalStruct_02* temp_s0;

    arg0->model[0]= func_800174C0(0x1E000B, 0x99);
    arg0->trans.x = -25.0f;
    arg0->trans.y = 0.0f;
    arg0->trans.z = 75.0f;
    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, 75.0f);
    func_80025830(arg0->model[0], 2.5f, 1.0f, 1.0f);
    temp_s0 = func_80023684(sizeof(unkGlobalStruct_02), 0x7918);
    arg0->unk_50 = temp_s0;
    func_8009B770(temp_s0, 0, sizeof(unkGlobalStruct_02));
    temp_s0->unk_04 = 1;
    temp_s0->unk_05 = 0;
    arg0->func_ptr = NULL;
}
