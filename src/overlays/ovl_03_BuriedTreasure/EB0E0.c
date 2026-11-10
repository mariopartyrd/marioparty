#include "common.h"
#include "BuriedTreasure.h"

/* Unreferenced: the bytes splat put between this unit's data objects (an f32 -2^63, then zero). */
u32 D_800FBAB0_BuriedTreasure[2] = { 0xDF000000, 0 };
/* Per-pixel-pair masks of a 24x24 brush (12 bytes per row, values 0x0F/0xF0/0xFF). */
u16 D_800FBAB8_BuriedTreasure[24 * 12] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x000F, 0x00FF, 0x0000, 0x00FF, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x000F, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00F0, 0x0000, 0x0000,
    0x0000, 0x0000, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x0000, 0x0000,
    0x0000, 0x000F, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00F0, 0x0000,
    0x0000, 0x000F, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x0000,
    0x0000, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00F0,
    0x0000, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00F0,
    0x000F, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF,
    0x000F, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF,
    0x0000, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF,
    0x000F, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00F0,
    0x000F, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF,
    0x000F, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF,
    0x000F, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00F0,
    0x0000, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00F0,
    0x0000, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00F0,
    0x0000, 0x000F, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x0000,
    0x0000, 0x000F, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00F0, 0x0000,
    0x0000, 0x0000, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x0000, 0x0000,
    0x0000, 0x0000, 0x000F, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00F0, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x000F, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x00FF, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x000F, 0x00F0, 0x00FF, 0x00F0, 0x0000, 0x0000, 0x0000, 0x0000,
};
u32 D_800FBCF8_BuriedTreasure[2] = { 0xDF000000, 0 };
u8 D_800FBD00_BuriedTreasure[24 * 12] = {
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,
    0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xFF,
    0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
    0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
    0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
    0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
    0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
    0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
    0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
    0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
    0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xFF,
    0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
};
u8 D_800FBE20_BuriedTreasure[2] = { 0xF0, 0x0F };
s8 D_800FBE24_BuriedTreasure[2] = { 0xF0, 0x0F };
u32 D_800FBE28_BuriedTreasure[2] = { 0, 0 }; /* unreferenced */
unkStructSize4 D_800FBE30_BuriedTreasure[9] = {
    { 0, 0 }, { 0, 1 }, { 0, -1 }, { 1, 0 }, { 1, 1 }, { 1, -1 }, { -1, 0 }, { -1, 1 }, { -1, -1 },
};
u32 D_800FBE54_BuriedTreasure = 0x19971204; //rng sub seed
s16 D_800FBE58_BuriedTreasure = 0;

void func_800F8760_BuriedTreasure(void) {
    CZoom = 2000.0f;
    CRot.x = 0.0f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    Center.x = 0.0f;
    Center.y = 0.0f;
    Center.z = -100.0f;
}

unkStructSize0x5C* func_800F87A8_BuriedTreasure(omObjData* arg0) {
    unkStructSize0x5C* temp_v0;

    D_800FC188_BuriedTreasure[D_800FC140_BuriedTreasure] = temp_v0 = HuMemDirectMalloc(sizeof(unkStructSize0x5C));

    arg0->work[0] = ((u32) temp_v0 >> 24);
    arg0->work[1] = ((u32) temp_v0 >> 16);
    arg0->work[2] = ((u32) temp_v0 >> 8);
    arg0->work[3] = (u32) temp_v0;

    temp_v0->unk_00 = 0;
    temp_v0->unk_02 = 0;
    temp_v0->unk_08 = 0;
    temp_v0->unk_0A = D_800FC140_BuriedTreasure;
    temp_v0->unk_0C = temp_v0->unk_10 = temp_v0->unk_14 = 0.0f;
    temp_v0->unk_18 = temp_v0->unk_1C = temp_v0->unk_20 = 0.0f;
    temp_v0->unk_24 = temp_v0->unk_28 = temp_v0->unk_2C = 0.0f;
    temp_v0->unk_3C = temp_v0->unk_3E = temp_v0->unk_40 = temp_v0->unk_42 = 0;
    temp_v0->unk_44 = temp_v0->unk_46 = temp_v0->unk_48 = temp_v0->unk_4A = 0;
    temp_v0->unk_4C = temp_v0->unk_4E = temp_v0->unk_50 = temp_v0->unk_52 = 0;
    temp_v0->unk_54 = temp_v0->unk_56 = temp_v0->unk_58 = temp_v0->unk_5A = 0;

    D_800FC140_BuriedTreasure++;
    return temp_v0;
}

void func_800F8894_BuriedTreasure(void) {
    s16 i;

    for (i = 0; i < D_800FC140_BuriedTreasure; i++) {
        if (D_800FC188_BuriedTreasure[i] != NULL) {
            HuMemDirectFree(D_800FC188_BuriedTreasure[i]);
        }
    }
}

unkStructSize0x5C* func_800F8914_BuriedTreasure(omObjData* arg0) {
    return (unkStructSize0x5C*) ((arg0->work[0] << 24) | (arg0->work[1] << 16) | (arg0->work[2] << 8) | arg0->work[3]);
}

u32 func_800F8940_BuriedTreasure(void) {
    return (rand8() << 8) | rand8();
}

void func_800F8978_BuriedTreasure(Matrix4f arg0) {
    f32 temp_f4;
    f32 temp_f6;
    s32 i;
    s32 j;
    s32 k;

    for (i = 0; i < 4; i++) {
        temp_f6 = arg0[i][i];
        for (k = 0; k < 4; k++) {
            if (temp_f6 != 0.0f) {
                arg0[i][k] /= temp_f6;
            } else {
                arg0[i][k] = 0.0f;
            }
        }

        if (temp_f6 != 0.0f) {
            arg0[i][i] = 1.0f / temp_f6;
        } else {
            arg0[i][i] = 0.0f;
        }

        for (j = 0; j < 4; j++) {
            if (j == i) {
                continue;
            }

            temp_f4 = arg0[j][i];
            for (k = 0; k < 4; k++) {
                if (k != i) {
                    arg0[j][k] -= temp_f4 * arg0[i][k];
                } else if (temp_f6 != 0.0f) {
                    arg0[j][k] = -temp_f4 / temp_f6;
                } else {
                    arg0[j][k] = 0.0f;
                }
            }
        }
    }
}

void func_800F8AE8_BuriedTreasure(f32* arg0, f32* arg1) {
    Matrix4f sp10;
    f32 temp_f4;
    f32 temp_f0;

    guTranslateF(sp10, arg0[0], arg0[1], arg0[2]);
    guMtxCatF(sp10, D_800FC0C0_BuriedTreasure, sp10);

    temp_f0 = sp10[3][2] * D_800FC5F0_BuriedTreasure;
    temp_f4 = fabsf(temp_f0);

    if (temp_f4 != 0.0) {
        arg1[0] = sp10[3][0] * 160.0f / temp_f4 / 1.3333334f;
        arg1[1] = -sp10[3][1] * 120.0f / temp_f4;
    }
}

void func_800F8BB8_BuriedTreasure(f32 arg0, f32 arg1, f32 arg2, Vec3f* arg3) {
    Matrix4f sp10;
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f2;
    f32 temp_f6;

    temp_f6 = arg2 + D_800FC0C0_BuriedTreasure[3][2];
    temp_f2 = fabsf(temp_f6 * D_800FC5F0_BuriedTreasure);

    guTranslateF(sp10, 2.0f * arg0 * temp_f2 * 1.3333334f / 320.0f, -(2.0f * arg1 * temp_f2 / 240.0f), temp_f6);
    guMtxCatF(sp10, D_800FC148_BuriedTreasure, sp10);

    arg3->x = sp10[3][0];
    arg3->y = sp10[3][1];
    arg3->z = sp10[3][2];
}

void func_800F8C84_BuriedTreasure(s16 arg0, f32* arg1, f32* arg2, f32* arg3) {
    if (*arg1 < -144.0f) {
        *arg1 = -144.0f;
    }
    if (*arg1 > 144.0f) {
        *arg1 = 144.0f;
    }
    if (*arg2 < -104.0f) {
        *arg2 = -104.0f;
    }
    if (*arg2 > 104.0f) {
        *arg2 = 104.0f;
    }
}

void func_800F8D1C_BuriedTreasure(unkStructSize0x5C* arg0) {
    unkStructSize0x5C* temp_v0;
    f32 var_f20;
    f32 var_f22;
    f32 var_f24;
    f32 var_f26;
    f32 var_f4;
    s16 i;

    if (arg0->unk_04 > arg0->unk_06) {
        var_f26 = arg0->unk_04;
    } else {
        var_f26 = arg0->unk_06;
    }

    for (i = 0; i < D_800F2BC0; i++) {
        temp_v0 = func_800F8914_BuriedTreasure(D_800F3FB0[i]);

        if (temp_v0 == arg0 || temp_v0->unk_08 < 0) {
            continue;
        }

        var_f22 = temp_v0->unk_0C - arg0->unk_0C;
        var_f24 = temp_v0->unk_10 - arg0->unk_10;

        if (temp_v0->unk_04 > temp_v0->unk_06) {
            var_f20 = temp_v0->unk_04;
        } else {
            var_f20 = temp_v0->unk_06;
        }

        var_f4 = sqrtf(SQ(var_f22) + SQ(var_f24));
        if (var_f4 < var_f26 + var_f20) {
            if (var_f4 != 0.0) {
                var_f22 /= var_f4;
                var_f24 /= var_f4;
            }
            arg0->unk_0C -= var_f22 * (var_f26 + var_f20 - var_f4);
            arg0->unk_10 -= var_f24 * (var_f26 + var_f20 - var_f4);
        }
    }
}

s16 func_800F8EF0_BuriedTreasure(f32* arg0, f32* arg1, s16 arg2) {
    unk65770AnimC* temp_s6;
    u8* temp_s5;
    f64 incr;
    f32 var_f20;
    f32 var_f22;
    f32 var_f24;
    f32 var_f26;
    f32 var_f28;
    f32 var_f4;
    s16 temp_s7;
    s16 var_s2;
    s16 i;
    s16 j;

    var_s2 = 0;
    var_f24 = 0.0f;
    var_f28 = 0.0f;
    var_f26 = 65535.0f;
    temp_s6 = D_800EC700[D_800FC198_BuriedTreasure[3]]->unk0;
    temp_s5 = temp_s6->unk0 + ((s16) *arg0 + 148) / 2 + ((s16) *arg1 + 108) * temp_s6->unk4 / 2;

    var_f22 = -12.0f;
    for (i = 0, temp_s7 = ((s16) *arg0) & 1; i < 24; i++) {
        var_f20 = -12.0f;
        for (j = 0; j < 24; j++) {
            if ((*(temp_s5 + (j + temp_s7) / 2 + i * temp_s6->unk4 / 2) & D_800FBE20_BuriedTreasure[(j + temp_s7) & 1])
                && !(D_800FBD00_BuriedTreasure[i * 12 + j / 2] & D_800FBE20_BuriedTreasure[j & 1])) {
                var_f4 = sqrtf(SQ(var_f20) + SQ(var_f22));
                var_s2++;
                if (var_f4 < var_f26) {
                    var_f28 = var_f20;
                    var_f24 = var_f22;
                    var_f26 = var_f4;
                }
            }
            var_f20 += incr = 1.0; // necessary to match
        }
        var_f22 += incr;
    }

    if (var_s2 != 0 && var_f26 < arg2) {
        var_f4 = sqrtf(SQ(var_f28) + SQ(var_f24));
        if (var_f4 != 0.0) {
            var_f28 /= var_f4;
            var_f24 /= var_f4;
            *arg0 -= var_f28 * (arg2 - var_f26);
            *arg1 -= var_f24 * (arg2 - var_f26);
        }
        return 1;
    }

    return 0;
}

s16 func_800F9260_BuriedTreasure(f32* arg0, f32* arg1, s16 arg2) {
    s16 i;

    for (i = 0; func_800F8EF0_BuriedTreasure(arg0, arg1, arg2) != 0 && i < 8; i++);

    return 1;
}

u16 func_800F92D4_BuriedTreasure(f32 arg0, f32 arg1, s16 arg2, void* arg3, s16* arg4) {
    unk65770AnimC* temp_t3;
    unk65770AnimC* temp_t7;
    s16 sp10[574];
    s32 temp_a0;
    s32 temp_a1;
    s16 var_s1;
    s16 var_a1;
    s16 var_s0;
    s16 temp_f0;
    u8* temp_t5;
    u8* temp_t9;
    u8* var_a3;
    s16* temp_s5;
    s16* var_a0;
    s16 i;
    s16 j;

    var_a3 = arg3;
    var_s0 = 0;
    var_s1 = 0;
    temp_t3 = D_800EC700[D_800FC198_BuriedTreasure[1]]->unk0;
    temp_t7 = D_800EC700[D_800FC198_BuriedTreasure[3]]->unk0;
    temp_t9 = temp_t7->unk0 + ((s16) arg0 + 148 + ((s16) arg1 + 108) * temp_t7->unk4) / 2;
    temp_t5 = temp_t3->unk0 + ((s16) arg0 + 148 + ((s16) arg1 + 108) * temp_t3->unk4) * 2;
    temp_f0 = (s16) arg0;
    *arg4 = 0;

    for (i = 0; i < 24; i++) {
        for (j = 0; j < 24; j++) {
            if (arg0 + j - 12.0f >= -160.0f && arg0 + j - 12.0f < 160.0f
                && arg1 + i - 12.0f >= -120.0f && arg1 + i - 12.0f < 120.0f) {
                if (!(D_800FBD00_BuriedTreasure[i * 12 + j / 2] & D_800FBE24_BuriedTreasure[j & 1])) {
                    temp_a1 = j + (temp_f0 & 1);
                    var_a3 = temp_t9 + temp_a1 / 2 + i * temp_t7->unk4 / 2;
                    if (*var_a3 & D_800FBE24_BuriedTreasure[temp_a1 & 1]) {
                        if (!(temp_a1 & 1)) {
                            var_a1 = *var_a3 >> 4;
                        } else {
                            var_a1 = *var_a3 & 0xF;
                        }
                        if (var_a1 == 4) {
                            var_s0 |= 2;
                        }
                        var_a1 -= arg2;
                        if (var_a1 <= 0) {
                            var_a1 = 0;
                            (*arg4)++;
                        }
                        temp_a0 = (j + (temp_f0 & 1)) & 1;
                        *var_a3 &= D_800FBE24_BuriedTreasure[temp_a0 ^ 1];
                        *var_a3 |= (temp_a0 == 0) ? (var_a1 << 4) : var_a1;
                        var_s0 |= 1;
                    }
                }

                if (D_800FBAB8_BuriedTreasure[i * 12 + j / 2] & D_800FBE24_BuriedTreasure[j & 1]) {
                    sp10[var_s1++] = (temp_t5[(j + i * temp_t3->unk4) * 2] << 8) + temp_t5[(j + i * temp_t3->unk4) * 2 + 1];
                    temp_t5[(j + i * temp_t3->unk4) * 2 + 1] &= 0xFE;
                }
            }
        }
    }

    if (var_s0 != 0) {
        *((s16*) arg3) = sp10[(func_800F8940_BuriedTreasure() * var_s1) >> 16];
    } else {
        *((s16*) arg3) = 0;
    }

    return var_s0;
}

void func_800F9700_BuriedTreasure(Gfx* arg0) {
    u8* timg = D_800EC700[D_800FC198_BuriedTreasure[1]]->unk0->unk0;
    s16 i;

    gDPPipeSync(arg0++);
    gDPSetCycleType(arg0++, G_CYC_1CYCLE);
    gSPSetGeometryMode(arg0++, G_TEXTURE_GEN_LINEAR);
    gDPSetCombineMode(arg0++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(arg0++, G_RM_ZB_XLU_SURF, G_RM_NOOP2);
    gDPSetTextureFilter(arg0++, G_TF_POINT);
    gDPSetTexturePersp(arg0++, G_TP_NONE);
    gDPSetColorDither(arg0++, G_CD_DISABLE);

    for (i = 0; i < 61; i++) {
        gDPLoadTextureTile(arg0++, timg, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, 0, 0, i * 4, 319, i * 4 + 3, 0,
            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, 2, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(arg0++, 0, (i * 4) * 4, 320 * 4, (i * 4 + 4) * 4, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
    }

    gSPEndDisplayList(arg0++);
}

void func_800F9990_BuriedTreasure(void) {
    s16 i;

    D_800FC198_BuriedTreasure[0] = InitSprite(0x150000);
    D_800FC198_BuriedTreasure[1] = InitSprite(0x150001);
    D_800FC198_BuriedTreasure[2] = InitSprite(0x150002);
    D_800FC198_BuriedTreasure[3] = InitSprite(0x150003);
    D_800FC198_BuriedTreasure[4] = InitSprite(0x150004);
    D_800FC198_BuriedTreasure[5] = InitSprite(0x34);

    for (i = 0; i < ARRAY_COUNT(D_800FC040_BuriedTreasure); i++) {
        D_800FC040_BuriedTreasure[i] = func_80064EF4(1, 0);

        func_80067208(D_800FC040_BuriedTreasure[i], 0, D_800FC198_BuriedTreasure[2 - i], 0);
        func_800672B0(D_800FC040_BuriedTreasure[i], 0, 0);

        if (i == 0) {
            func_800674BC(D_800FC040_BuriedTreasure[i], 0, 0x4000);
        } else {
            func_800674BC(D_800FC040_BuriedTreasure[i], 0, 0x1000);
        }

        func_80066DC4(D_800FC040_BuriedTreasure[i], 0, 0xA0, 0x78);
        func_80067354(D_800FC040_BuriedTreasure[i], 0, 1.0f, 1.0f);
        func_800671DC(D_800FC040_BuriedTreasure[i], 0, 0);
        func_80067384(D_800FC040_BuriedTreasure[i], 0, 0x8000);
    }

    D_800FC5E8_BuriedTreasure = HuMemDirectMalloc(1024 * sizeof(Gfx));
    func_800F9700_BuriedTreasure(D_800FC5E8_BuriedTreasure);
    func_80024198(0xC0, D_800FC5E8_BuriedTreasure, 4);

    for (i = 0; i < ARRAY_COUNT(D_800FC1C0_BuriedTreasure); i++) {
        D_800FC1C0_BuriedTreasure[i].unk_00 = 0;
        D_800FC1C0_BuriedTreasure[i].unk_02 = 0;
        D_800FC1C0_BuriedTreasure[i].unk_04 = func_80064EF4(1, 0);

        func_80067480(D_800FC1C0_BuriedTreasure[i].unk_04, 0, -1);
        func_800674BC(D_800FC1C0_BuriedTreasure[i].unk_04, 0, 0xC000);

        D_800FC1C0_BuriedTreasure[i].unk_06 = 0;
        D_800FC1C0_BuriedTreasure[i].unk_08 = 0.0f;
        D_800FC1C0_BuriedTreasure[i].unk_0C = 0.0f;
        D_800FC1C0_BuriedTreasure[i].unk_10 = D_800FC1C0_BuriedTreasure[i].unk_12 = D_800FC1C0_BuriedTreasure[i].unk_14 = D_800FC1C0_BuriedTreasure[i].unk_16 = 0;
        D_800FC1C0_BuriedTreasure[i].unk_18 = D_800FC1C0_BuriedTreasure[i].unk_1A = D_800FC1C0_BuriedTreasure[i].unk_1C = D_800FC1C0_BuriedTreasure[i].unk_1E = 0;
    }
}

s16 func_800F9C40_BuriedTreasure(s16 arg0, f32 arg1, f32 arg2, s16 arg3) {
    s16 i;

    for (i = 0; i < ARRAY_COUNT(D_800FC1C0_BuriedTreasure); i++) {
        if (D_800FC1C0_BuriedTreasure[i].unk_00 != 0) {
            continue;
        }

        D_800FC1C0_BuriedTreasure[i].unk_00 = 1;
        D_800FC1C0_BuriedTreasure[i].unk_02 = arg0;
        D_800FC1C0_BuriedTreasure[i].unk_06 = arg3;
        D_800FC1C0_BuriedTreasure[i].unk_08 = arg1;
        D_800FC1C0_BuriedTreasure[i].unk_0C = arg2;

        if (D_800FC1C0_BuriedTreasure[i].unk_04 >= 0) {
            func_8006752C(D_800FC1C0_BuriedTreasure[i].unk_04, 0, 0x100);
            func_80067480(D_800FC1C0_BuriedTreasure[i].unk_04, 0, 0xFFFF);
            func_800674BC(D_800FC1C0_BuriedTreasure[i].unk_04, 0, 0x1000);
            func_80067354(D_800FC1C0_BuriedTreasure[i].unk_04, 0, 1.0f, 1.0f);
            func_800672B0(D_800FC1C0_BuriedTreasure[i].unk_04, 0, 1);
            func_800673B0(D_800FC1C0_BuriedTreasure[i].unk_04, 0, 0.0f);
        }

        D_800FC1C0_BuriedTreasure[i].unk_10 = D_800FC1C0_BuriedTreasure[i].unk_12 = D_800FC1C0_BuriedTreasure[i].unk_14 = D_800FC1C0_BuriedTreasure[i].unk_16 = 0;
        D_800FC1C0_BuriedTreasure[i].unk_18 = D_800FC1C0_BuriedTreasure[i].unk_1A = D_800FC1C0_BuriedTreasure[i].unk_1C = D_800FC1C0_BuriedTreasure[i].unk_1E = 0;

        return i;
    }

    return -1;
}

void func_800F9DCC_BuriedTreasure(s16 arg0) {
    D_800FC1C0_BuriedTreasure[arg0].unk_00 = 0;

    if (D_800FC1C0_BuriedTreasure[arg0].unk_04 >= 0) {
        func_800674BC(D_800FC1C0_BuriedTreasure[arg0].unk_04, 0, 0x8000);
    }
}

void func_800F9E10_BuriedTreasure(void) {
    s16 i;

    for (i = 0; i < ARRAY_COUNT(D_800FC1C0_BuriedTreasure); i++) {
        if (D_800FC1C0_BuriedTreasure[i].unk_00 == 0) {
            continue;
        }

        switch (D_800FC1C0_BuriedTreasure[i].unk_02) {
            case 0:
                func_800F7D50_BuriedTreasure(i);
                break;
            case 1:
                func_800F7E48_BuriedTreasure(i);
                break;
            case 2:
                func_800FB918_BuriedTreasure(i);
                break;
            case 3:
                func_800FB920_BuriedTreasure(i);
                break;
            case 4:
                func_800F815C_BuriedTreasure(i);
                break;
        }

        if (D_800FC1C0_BuriedTreasure[i].unk_00 != 0 && D_800FC1C0_BuriedTreasure[i].unk_04 >= 0) {
            func_80066DC4(D_800FC1C0_BuriedTreasure[i].unk_04, 0, D_800FC1C0_BuriedTreasure[i].unk_08 + 160.0, D_800FC1C0_BuriedTreasure[i].unk_0C + 120.0);
        }
    }
}

void func_800F9F90_BuriedTreasure(void) {
    unk65770AnimC* var_a0;
    u16 i;

    D_800FC05C_BuriedTreasure = omAddObj(5, 0, 0, -1, &func_800FA090_BuriedTreasure);
    func_800FB998_BuriedTreasure(rand8());

    D_800FC0B8_BuriedTreasure[0] = InitSprite(0x150000);
    D_800FC0B8_BuriedTreasure[1] = InitSprite(0x150004);
    D_800FC0B8_BuriedTreasure[2] = InitSprite(0x21);
    D_800FC0B8_BuriedTreasure[3] = InitSprite(0x2A);

    var_a0 = D_800EC700[D_800FC0B8_BuriedTreasure[2]]->unk0;
    for (i = 0; i < D_800EC700[D_800FC0B8_BuriedTreasure[2]]->unk10; i++) {
        var_a0->unk8 = 16;
        var_a0->unkA = 16;
        var_a0++;
    }

    D_800FC5EC_BuriedTreasure = -1;
}

void func_800FA090_BuriedTreasure(omObjData* arg0) {
    arg0->func_ptr = &func_800FA0B4_BuriedTreasure;
    func_800FA138_BuriedTreasure();
}

void func_800FA0B4_BuriedTreasure(void) {
    func_800FA90C_BuriedTreasure();

    if (D_800FC5EC_BuriedTreasure < 0 && func_800FB780_BuriedTreasure() == 2) {
        GwPlayer[D_800FC5EC_BuriedTreasure].coins_mg += 10;
        func_80060F04(D_800FC5EC_BuriedTreasure, 20, 0, 20);
    }
}

void func_800FA138_BuriedTreasure(void) {
    Vec3f sp18;
    unkStructSize0x28* var_s2;
    f32 temp_f12;
    f32 temp_f14;
    s16 temp_s0;
    s16 temp_f2;
    s16 i;
    s16 j;

    D_800FC060_BuriedTreasure = omAddObj(0, 3, 2, -1, NULL);

    var_s2 = D_800FC5C0_BuriedTreasure;
    for (i = 0; i < ARRAY_COUNT(D_800FC5C0_BuriedTreasure); i++) {
        if (func_800FB928_BuriedTreasure(0) & 1) {
            var_s2->unk_0C = func_800FB928_BuriedTreasure(64) + 128;
            var_s2->unk_0E = func_800FB928_BuriedTreasure(176) + 32;
        } else {
            var_s2->unk_0C = func_800FB928_BuriedTreasure(256) + 32;
            var_s2->unk_0E = func_800FB928_BuriedTreasure(40) + 100;
        }

        var_s2->unk_10 = 16;
        var_s2->unk_09 = 0;
        var_s2->unk_0A = 1;

        if (func_800FB520_BuriedTreasure(var_s2->unk_0C, var_s2->unk_0E) == 0) {
            i--;
            continue;
        }

        var_s2->unk_08 = 0;
        var_s2->unk_12 = 0;
        var_s2->unk_1C = NULL;

        if (i & 1) {
            var_s2->unk_00 = HuMemDirectMalloc(sizeof(u16));
            var_s2->unk_04 = 1;

            *var_s2->unk_00 = func_800F9C40_BuriedTreasure(2, var_s2->unk_0C - 160, var_s2->unk_0E - 120, 0);
            temp_s0 = D_800FC1C0_BuriedTreasure[*var_s2->unk_00].unk_04;

            func_80067384(temp_s0, 0, 0x7FFE);
            func_80067208(temp_s0, 0, D_800FC0B8_BuriedTreasure[0], 3);
            func_800672B0(temp_s0, 0, 0);
            func_800674BC(temp_s0, 0, 0x4000);
            func_800671DC(temp_s0, 0, 2);
            func_80067354(temp_s0, 0, 0.65f, 0.65f);
        } else {
            var_s2->unk_00 = HuMemDirectMalloc(10 * sizeof(u16));
            var_s2->unk_04 = 10;

            for (j = 0; j < var_s2->unk_04; j++) {
                var_s2->unk_00[j] = func_800F9C40_BuriedTreasure(2, var_s2->unk_0C - 160, var_s2->unk_0E - 120, 0);
                temp_s0 = D_800FC1C0_BuriedTreasure[var_s2->unk_00[j]].unk_04;

                func_80067384(temp_s0, 0, 0x7FFE);
                func_80067208(temp_s0, 0, D_800FC0B8_BuriedTreasure[0], 3);
                func_800672B0(temp_s0, 0, 0);
                func_800674BC(temp_s0, 0, 0x4000);
                func_80067208(temp_s0, 0, D_800FC0B8_BuriedTreasure[2], 0);
                func_800672B0(temp_s0, 0, 0);
                func_80067354(temp_s0, 0, 0.65f, 0.65f);
                func_800674BC(temp_s0, 0, 0xC80C);
            }

            var_s2->unk_24 = 0;
            var_s2->unk_25 = var_s2->unk_04;

            D_800FC060_BuriedTreasure->model[0] = LoadFormFile(0x150005, 0x99);
            D_800FC060_BuriedTreasure->model[1] = LoadFormFile(0x150006, 0x9D);
            D_800FC060_BuriedTreasure->model[2] = LoadFormFile(0x150005, 0x49D);

            D_800F2B7C[D_800FC060_BuriedTreasure->model[0]].unk_4C = 0.0f;
            D_800F2B7C[D_800FC060_BuriedTreasure->model[2]].unk_4C = 0.0f;

            func_800F8BB8_BuriedTreasure(var_s2->unk_0C - 160, var_s2->unk_0E - 120, -400.0f, &sp18);

            D_800FC060_BuriedTreasure->trans.x = sp18.x;
            D_800FC060_BuriedTreasure->trans.y = sp18.y;
            D_800FC060_BuriedTreasure->trans.z = sp18.z;
            D_800FC060_BuriedTreasure->scale.z = 0.25f;
            D_800FC060_BuriedTreasure->scale.y = 0.25f;
            D_800FC060_BuriedTreasure->scale.x = 0.25f;
            D_800FC060_BuriedTreasure->rot.x = 0.0f;
            D_800FC060_BuriedTreasure->rot.y = -30.0f;
            D_800FC060_BuriedTreasure->rot.z = 0.0f;

            for (j = 0; j < 2; j++) {
                if (j == 0) {
                    func_80025798(D_800FC060_BuriedTreasure->model[1], D_800FC060_BuriedTreasure->trans.x, D_800FC060_BuriedTreasure->trans.y, D_800FC060_BuriedTreasure->trans.z);
                } else {
                    func_800F8BB8_BuriedTreasure(var_s2->unk_0C - 160, var_s2->unk_0E - 120, 0.0f, &sp18);
                    func_80025798(D_800FC060_BuriedTreasure->model[j + 1], sp18.x, sp18.y, sp18.z);
                }
                func_80025830(D_800FC060_BuriedTreasure->model[j + 1], D_800FC060_BuriedTreasure->scale.x, D_800FC060_BuriedTreasure->scale.y, D_800FC060_BuriedTreasure->scale.z);
                func_800257E4(D_800FC060_BuriedTreasure->model[j + 1], D_800FC060_BuriedTreasure->rot.x, D_800FC060_BuriedTreasure->rot.y, D_800FC060_BuriedTreasure->rot.z);
            }

            var_s2->unk_20 = D_800FC060_BuriedTreasure;
            D_800FC060_BuriedTreasure->work[0] = 0;
            var_s2->unk_06 = D_800FC060_BuriedTreasure->model[0];
            var_s2->unk_08 = 2;
        }

        var_s2++;
    }

    var_s2 = D_800FC068_BuriedTreasure;
    for (i = 0; i < ARRAY_COUNT(D_800FC068_BuriedTreasure); i++) {
        var_s2->unk_0C = func_800FB928_BuriedTreasure(208) + 56;
        var_s2->unk_0E = func_800FB928_BuriedTreasure(128) + 56;

        if (func_800FB520_BuriedTreasure(var_s2->unk_0C, var_s2->unk_0E) == 0) {
            i--;
            continue;
        }

        var_s2->unk_00 = HuMemDirectMalloc(sizeof(u16));
        var_s2->unk_04 = 1;

        *var_s2->unk_00 = func_800F9C40_BuriedTreasure(3, var_s2->unk_0C - 160, var_s2->unk_0E - 120, 0);
        var_s2->unk_08 = 0;
        temp_s0 = D_800FC1C0_BuriedTreasure[*var_s2->unk_00].unk_04;

        func_80067384(temp_s0, 0, 0x7FFE);
        func_80067208(temp_s0, 0, D_800FC198_BuriedTreasure[0], 0);
        func_800672B0(temp_s0, 0, 0);
        func_800674BC(temp_s0, 0, 0x4008);
        func_80067354(temp_s0, 0, 0.65f, 0.65f);

        temp_f12 = var_s2->unk_0E - D_800FC5C0_BuriedTreasure[0].unk_0E;
        temp_f14 = D_800FC5C0_BuriedTreasure[0].unk_0C - var_s2->unk_0C;
        var_s2++;

        temp_f2 = func_8009B618(func_800B0CD8(temp_f12, temp_f14) + 360.0 + 22.5, 360.0) / 45.0;
        func_800673B0(temp_s0, 0, temp_f2 / 2 * 90.0 - 90.0);
        func_800671DC(temp_s0, 0, temp_f2 & 1);
    }
}

void func_800FA90C_BuriedTreasure(void) {
    unkStructSize0x28* var_s1;
    omObjData* temp_s0;
    unkStructSize0x5C* var_s4;
    f32 sp18[3];
    f32 sp28[3];
    f32 temp_f20_2;
    f32 temp_f22_2;
    f32 temp_f20_3;
    u16 temp_s3;
    u16 var_v0;
    u16 i;
    u16 j;

    var_s4 = NULL;
    var_s1 = D_800FC5C0_BuriedTreasure;

    for (i = 0; i < 1; i++) {
        if (var_s1->unk_1C != NULL) {
            var_s4 = func_800F8914_BuriedTreasure(var_s1->unk_1C);
        }

        switch (i) {
            case 0:
                if (var_s1->unk_0A == 1) {
                    temp_s0 = var_s1->unk_20;
                    if (temp_s0->work[0] & 7) {
                        D_800F2B7C[temp_s0->model[0]].unk_20 &= ~4;
                        D_800F2B7C[temp_s0->model[1]].unk_20 |= 4;
                    } else {
                        D_800F2B7C[temp_s0->model[0]].unk_20 |= 4;
                        D_800F2B7C[temp_s0->model[1]].unk_20 &= ~4;
                    }
                    temp_s0->work[0]++;
                }

                if (var_s1->unk_0A >= 2 && var_s1->unk_0A < 32) {
                    if (var_s1->unk_0A == 2) {
                        PlaySound(0x196);
                    }
                    var_s1->unk_0A++;
                    temp_s0 = var_s1->unk_20;
                    var_v0 = var_s1->unk_0A;
                    temp_f20_3 = func_800AEAC0((var_v0 - 2) * 5.625) * 0.1;
                    func_80025830(temp_s0->model[2], temp_f20_3 + temp_s0->scale.x, temp_f20_3 + temp_s0->scale.y, temp_f20_3 + temp_s0->scale.z);
                } else if (var_s1->unk_0A >= 32) {
                    if (var_s1->unk_0A == 32) {
                        temp_f22_2 = var_s1->unk_0C - 160 - var_s4->unk_0C;
                        temp_f20_2 = var_s1->unk_0E - 120 - 46.0 - var_s4->unk_10;

                        var_s1->unk_14 = sqrtf(SQ(temp_f22_2) + SQ(temp_f20_2));
                        var_s1->unk_18 = func_800B0CD8(temp_f22_2, temp_f20_2) - 90.0;

                        if (var_s1->unk_18 < 0.0f) {
                            var_s1->unk_18 += 360.0f;
                        }
                    }

                    if ((var_s1->unk_0A & 1) == 0 && var_s1->unk_24 < var_s1->unk_04) {
                        for (j = 0; j < var_s1->unk_24 + 1; j++) {
                            temp_s3 = var_s1->unk_00[j];
                            func_80067480(D_800FC1C0_BuriedTreasure[temp_s3].unk_04, 0, 0xC000);
                            func_800672B0(D_800FC1C0_BuriedTreasure[temp_s3].unk_04, 0, 1);
                            func_80067284(D_800FC1C0_BuriedTreasure[temp_s3].unk_04, 0, 1.0f);
                        }
                        var_s1->unk_24++;
                    }

                    for (j = 0; j < var_s1->unk_24; j++) {
                        temp_s3 = var_s1->unk_00[j];
                        if (!(D_800FC1C0_BuriedTreasure[temp_s3].unk_00 & 0x80)) {
                            if (D_800FC1C0_BuriedTreasure[temp_s3].unk_10 < 16) {
                                temp_f20_3 = D_800FC1C0_BuriedTreasure[temp_s3].unk_10 / 16.0;
                                func_80067354(D_800FC1C0_BuriedTreasure[temp_s3].unk_04, 0, temp_f20_3 * 0.25 + 0.5, temp_f20_3 * 0.25 + 0.5);
                                D_800FC1C0_BuriedTreasure[temp_s3].unk_08 = var_s1->unk_0C - 160;
                                D_800FC1C0_BuriedTreasure[temp_s3].unk_0C = var_s1->unk_0E - 120 - temp_f20_3 * 46.0;
                            } else if (D_800FC1C0_BuriedTreasure[temp_s3].unk_10 < 32) {
                                temp_f20_3 = (D_800FC1C0_BuriedTreasure[temp_s3].unk_10 - 16) / 16.0;
                                func_80067354(D_800FC1C0_BuriedTreasure[temp_s3].unk_04, 0, 0.75 - temp_f20_3 * 0.25, 0.75 - temp_f20_3 * 0.25);
                                D_800FC1C0_BuriedTreasure[temp_s3].unk_08 = func_800AEFD0(temp_f20_3 * 360.0 - var_s1->unk_18) * (var_s1->unk_14 - temp_f20_3 * var_s1->unk_14) + var_s4->unk_0C;
                                D_800FC1C0_BuriedTreasure[temp_s3].unk_0C = func_800AEAC0(temp_f20_3 * 360.0 - var_s1->unk_18) * (var_s1->unk_14 - temp_f20_3 * var_s1->unk_14) + var_s4->unk_10;
                            }

                            D_800FC1C0_BuriedTreasure[temp_s3].unk_10++;
                            if (D_800FC1C0_BuriedTreasure[temp_s3].unk_10 == 32) {
                                func_80067208(D_800FC1C0_BuriedTreasure[temp_s3].unk_04, 0, D_800FC0B8_BuriedTreasure[3], 0);
                                func_800674F4(D_800FC1C0_BuriedTreasure[temp_s3].unk_04, 0, 255, 255, 190);
                                func_800672B0(D_800FC1C0_BuriedTreasure[temp_s3].unk_04, 0, 2);
                                func_80067354(D_800FC1C0_BuriedTreasure[temp_s3].unk_04, 0, 2.0f, 2.0f);
                                PlaySound(0xFC);
                            } else if (D_800FC1C0_BuriedTreasure[temp_s3].unk_10 > 32 && func_80067328(D_800FC1C0_BuriedTreasure[temp_s3].unk_04, 0) & 4) {
                                func_800674BC(D_800FC1C0_BuriedTreasure[temp_s3].unk_04, 0, 0x8000);
                                D_800FC1C0_BuriedTreasure[temp_s3].unk_00 |= 0x80;
                                var_s1->unk_25--;
                            }
                        }
                    }

                    if (var_s1->unk_0A < 63) {
                        temp_s0 = var_s1->unk_20;
                        D_800F2B7C[temp_s0->model[2]].unk_20 ^= 4;
                    }

                    var_s1->unk_0A++;
                    if (var_s1->unk_25 == 0) {
                        var_s1->unk_0A = 0;
                        for (j = 0; j < var_s1->unk_04; j++) {
                            func_800F9DCC_BuriedTreasure(var_s1->unk_00[j]);
                        }
                    }
                }

                break;
            case 1:
                if (var_s1->unk_0A >= 2) {
                    func_80067480(D_800FC1C0_BuriedTreasure[*var_s1->unk_00].unk_04, 0, 0x4000);

                    var_s4 = func_800F8914_BuriedTreasure(var_s1->unk_1C);
                    sp28[0] = var_s4->unk_0C;
                    sp28[1] = var_s4->unk_10;
                    sp28[2] = var_s4->unk_14;

                    func_800F8AE8_BuriedTreasure(sp28, sp18);

                    if (var_s1->unk_0A >= 2 && var_s1->unk_0A <= 16) {
                        temp_f20_3 = (var_s1->unk_0A - 2) * 0.07;
                        if (1.0 < temp_f20_3) {
                            temp_f20_3 = 1.0f;
                        }

                        func_80067354(D_800FC1C0_BuriedTreasure[*var_s1->unk_00].unk_04, 0, temp_f20_3 + 1.0, temp_f20_3 + 1.0);

                        D_800FC1C0_BuriedTreasure[*var_s1->unk_00].unk_08 = var_s1->unk_0C - 160 + temp_f20_3 * (sp28[0] - (var_s1->unk_0C - 160));
                        D_800FC1C0_BuriedTreasure[*var_s1->unk_00].unk_0C = var_s1->unk_0E - 120 + temp_f20_3 * (sp28[1] - 32.0f - (var_s1->unk_0E - 120));

                        var_s1->unk_0A++;
                    } else if (var_s1->unk_0A > 16 && var_s1->unk_0A < 32) {
                        temp_f20_3 = (var_s1->unk_0A - 17) * 0.0666;

                        func_80067354(D_800FC1C0_BuriedTreasure[*var_s1->unk_00].unk_04, 0, 1.966 - 2.0f * temp_f20_3, 1.966 - 2.0f * temp_f20_3);

                        D_800FC1C0_BuriedTreasure[*var_s1->unk_00].unk_08 = func_800AEFD0(temp_f20_3 * 360.0 - 90.0) * (32.0f - temp_f20_3 * 32.0f) + sp28[0];
                        D_800FC1C0_BuriedTreasure[*var_s1->unk_00].unk_0C = func_800AEAC0(temp_f20_3 * 360.0 - 90.0) * (32.0f - temp_f20_3 * 32.0f) + sp28[1];

                        var_s1->unk_0A++;
                    } else if (var_s1->unk_0A >= 32) {
                        var_s1->unk_0A = 0;
                        func_800F9DCC_BuriedTreasure(*var_s1->unk_00);
                    }
                }
                break;
        }

        var_s1++;
    }
}

s16 func_800FB380_BuriedTreasure(u16 arg0, u8* arg1) {
    unkStructSize0x28* temp_t0;
    u32 temp_a0;
    s16 temp_v1;
    s16 var_a2;
    s16 var_a3;
    s16 i;

    temp_t0 = &D_800FC5C0_BuriedTreasure[arg0];
    var_a3 = 0;

    if (temp_t0->unk_0A != 1) {
        return 0;
    }

    for (i = 0; i < 9; i++) {
        temp_v1 = temp_t0->unk_0C + D_800FBE30_BuriedTreasure[i].unk_00 * (temp_t0->unk_10 / 2 - 1);
        var_a2 = temp_t0->unk_0E + D_800FBE30_BuriedTreasure[i].unk_02 * (temp_t0->unk_10 / 2 - 1);

        if (temp_v1 < 0) {
            temp_v1 = 0;
        } else if (temp_v1 > 319) {
            temp_v1 = 319;
        }

        if (var_a2 < 0) {
            var_a2 = 0;
        } else if (var_a2 > 239) {
            var_a2 = 239;
        }

        temp_a0 = temp_v1 + var_a2 * 320;

        if (temp_a0 & 1) {
            if ((arg1[temp_a0 / 2] & 0xF) == 0) {
                var_a3++;
            }
        } else {
            if (arg1[temp_a0 / 2] >> 4 == 0) {
                var_a3++;
            }
        }

    }

    if (var_a3 > 3 && arg0 == 1) {
        temp_t0->unk_0A = 0;
        temp_t0->unk_12 = 0;
        return 1;
    }

    if (var_a3 > 6 && arg0 == 0) {
        temp_t0->unk_0A = 0;
        temp_t0->unk_12 = 0;
        return 1;
    }

    temp_t0->unk_12 = var_a3;
    return 0;
}

s16 func_800FB520_BuriedTreasure(u16 arg0, u16 arg1) {
    s32 temp_v1;
    s32 var_v0;
    s16 var_a2;
    s16 var_v1;
    u16 i;

    for (i = 0; i < D_800FBE58_BuriedTreasure; i++) {
        temp_v1 = D_800FC050_BuriedTreasure[i].unk_00 - arg0;
        var_v1 = (temp_v1 >= 0) ? temp_v1 : -temp_v1;

        var_v0 = D_800FC050_BuriedTreasure[i].unk_02 - arg1;
        var_a2 = (var_v0 >= 0) ? var_v0 : -var_v0;

        if (var_v1 < 16) {
            return 0;
        }

        if (var_a2 < 16) {
            return 0;
        }

        if (SQ(var_v1) + SQ(var_a2) < 2500) {
            return 0;
        }
    }

    D_800FC050_BuriedTreasure[i].unk_00 = arg0;
    D_800FC050_BuriedTreasure[i].unk_02 = arg1;

    D_800FBE58_BuriedTreasure++;
    return 1;
}

omObjData* func_800FB62C_BuriedTreasure(unkStructSize0x28* arg0) {
    unkStructSize0x5C* temp_v0;
    omObjData* var_s1;
    s32 temp_f0;
    s32 var_s2;
    s16 i;

    var_s2 = 9999;
    var_s1 = NULL;

    for (i = 0; i < D_800F2BC0; i++) {
        temp_v0 = func_800F8914_BuriedTreasure(D_800F3FB0[i]);
        temp_f0 = sqrtf(SQ(arg0->unk_0C - 160.0 - temp_v0->unk_0C)
            + SQ(arg0->unk_0E - 120.0 - temp_v0->unk_10));

        if (temp_f0 < var_s2) {
            var_s2 = temp_f0;
            var_s1 = D_800F3FB0[i];
        }
    }

    return var_s1;
}

s16 func_800FB780_BuriedTreasure(void) {
    unkStructSize0x5C* temp_a3;
    omObjData* temp_v0;
    u8* temp_s3;
    s16 i;

    temp_s3 = D_800EC700[D_800FC198_BuriedTreasure[3]]->unk0->unk0;

    for (i = 0; i < 1; i++) {
        if (func_800FB380_BuriedTreasure(i, temp_s3) != 1) {
            continue;
        }

        temp_v0 = func_800FB62C_BuriedTreasure(&D_800FC5C0_BuriedTreasure[i]);
        temp_a3 = func_800F8914_BuriedTreasure(temp_v0);

        if (i == 0) {
            D_800FC5C0_BuriedTreasure[i].unk_0A = 2;
            D_800FC5C0_BuriedTreasure[i].unk_1C = temp_v0;
            D_800F2B7C[D_800FC060_BuriedTreasure->model[0]].unk_20 |= 4;
            D_800F2B7C[D_800FC060_BuriedTreasure->model[1]].unk_20 |= 4;
            D_800F2B7C[D_800FC060_BuriedTreasure->model[2]].unk_20 &= ~4;
            D_800F2B7C[D_800FC060_BuriedTreasure->model[2]].unk_4C = 1.0f;
            D_800FC5EC_BuriedTreasure = temp_a3->unk_40;
            return 2;
        }
    }

    return 0;
}

void func_800FB918_BuriedTreasure(s16 arg0) {
}

void func_800FB920_BuriedTreasure(s16 arg0) {
}

u16 func_800FB928_BuriedTreasure(u16 arg0) { //shared overlay func
    D_800FBE54_BuriedTreasure = (D_800FBE54_BuriedTreasure * 0x19971204 + 0x19760831) >> 16;

    if (arg0 == 0) {
        return D_800FBE54_BuriedTreasure;
    } else {
        return (D_800FBE54_BuriedTreasure % arg0);
    }
}

void func_800FB998_BuriedTreasure(u16 randByte) {
    u16 i;
    
    for (i = 0; i < randByte; i++) {
        func_800FB928_BuriedTreasure(0); //pass 0 to getRand function to shuffle rng
    }
}

void func_800FB9E8_BuriedTreasure(void) {
    unkStructSize0x28* var_s0;
    s16 i;

    var_s0 = D_800FC5C0_BuriedTreasure;
    for (i = 0; i < ARRAY_COUNT(D_800FC5C0_BuriedTreasure); i++) {
        HuMemDirectFree(var_s0->unk_00);
        var_s0++;
    }

    var_s0 = D_800FC068_BuriedTreasure;
    for (i = 0; i < ARRAY_COUNT(D_800FC068_BuriedTreasure); i++) {
        HuMemDirectFree(var_s0->unk_00);
        var_s0++;
    }
}
