#include "common.h"

void func_8001DE70(s16 arg0) {
    s16 i;
    unk_800ECDE0* temp_v1;

    D_800EE312 = arg0;
    for (i = 0; i < D_800F37DA; i++) {
        *(&D_800ED0A0 + i) = func_80023684(arg0 << 7, 0x7530);
        *(&D_800F33A8 + i) = func_80023684(arg0 << 8, 0x7530);
    }
    D_800ECDE0 = func_80023684(arg0 * 0x24, 0x7530);
    for (i = 0; i < arg0; i++) {
        temp_v1 = &D_800ECDE0[i];
        temp_v1->unk_00 = -1;
    }
    D_800C31E0 = 1;
    func_8001DFC0();
}

void func_8001DFC0() {
    u8 temp_v0;

    if (D_800C31E0 != 0) {
        temp_v0 = D_800F37F0;
        D_800EE318 = *(&D_800ED0A0 + temp_v0);
        D_800F3714 = *(&D_800F33A8 + temp_v0);
    }
}

INCLUDE_ASM("asm/nonmatchings/1EA70", func_8001E00C);

u16 func_8001E1D0(s16 index, s32 arg1) {
    s16 temp_v0;

    temp_v0 = func_8001E00C((void*) -1, D_800F2B7C[D_800ECDE0[index].unk_00].unk_20, arg1);
    D_800ECDE0[temp_v0].unk_02 = D_800ECDE0[index].unk_02;
    return temp_v0;
}

void func_8001E268(s16 index, u8 arg1, u8 arg2) {
    unk_800ECDE0* temp_v1;

    temp_v1 = &D_800ECDE0[index];
    temp_v1->unk_10 = temp_v1->unk_10 & ~arg1;
    temp_v1->unk_10 = arg2 | temp_v1->unk_10;
}

void func_8001E2A8(s16 index, u16 arg1) {
    D_800ECDE0[index].unk_04 = arg1;
}

u16 func_8001E2D0(s16 index) {
    return D_800ECDE0[index].unk_04;
}

void func_8001E2F8(s16 index, u8 arg1) {
    s32 unk_var;

    if (index != -1) {
        D_800ECDE0[index].unk_12 = arg1;
        unk_var = (arg1 != 0xFF) << 0x10;
        func_80025930(D_800ECDE0[index].unk_00, 0x10000, unk_var);
    }
}

void func_8001E360(s16 index, u8 arg1, u8 arg2, u8 arg3) {
    if (index != -1) {
        D_800ECDE0[index].unk_13 = arg1;
        D_800ECDE0[index].unk_14 = arg2;
        D_800ECDE0[index].unk_15 = arg3;
    }
}

void func_8001E3B4(s16 index) {
    unk_800ECDE0* temp_v1;

    temp_v1 = &D_800ECDE0[index];
    temp_v1->unk_0A = 0;
    temp_v1->unk_04 = 0;
    temp_v1->unk_10 = temp_v1->unk_10 & 0xFF7F;
    func_800258EC(temp_v1->unk_00, 4, 0);
}

void func_8001E40C(s16 index, s8 arg1, s8 arg2, s8 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8) {
    if (index != -1) {
        func_8001E268(index, 0x40, 0x40);
        D_800ECDE0[index].unk_16 = arg1;
        D_800ECDE0[index].unk_17 = arg2;
        D_800ECDE0[index].unk_18 = arg3;
        D_800ECDE0[index].unk_19 = arg4;
        D_800ECDE0[index].unk_1A = arg5;
        D_800ECDE0[index].unk_1B = arg6;
        D_800ECDE0[index].unk_1C = arg7;
        D_800ECDE0[index].unk_1D = arg8;
    }
}

void func_8001E534(s16 index, s32 arg1) {
    if (index != -1) {
        func_8001E268(index, 0x40, 0x40);
        D_800ECDE0[index].unk_20 = arg1;
        D_800ECDE0[index].unk_0E = 0;
        D_800ECDE0[index].unk_0C = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/1EA70", func_8001E5A0);

void func_8002019C(s32 index) {
    if (D_800C31E0 != 0) {
        if ((u16) D_800ECDE0[index].unk_02 != 0xFFFF) {
            func_80039A4C(D_800ECDE0[index].unk_02);
        }
        func_8002456C(D_800ECDE0[index].unk_00);
        D_800ECDE0[index].unk_00 = -1;
    }
}

void func_80020234() {
    s16 i;

    if (D_800C31E0 != 0) {
        for (i = 0; i < D_800EE312; i++) {
            if (D_800ECDE0[i].unk_00 != -1) {
                func_80039A4C(D_800ECDE0[i].unk_02);
            }
        }
        func_800238F0(0x7530);
        D_800C31E0 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/1EA70", func_800202E8);

INCLUDE_ASM("asm/nonmatchings/1EA70", func_8002040C);

INCLUDE_ASM("asm/nonmatchings/1EA70", func_80020544);

INCLUDE_ASM("asm/nonmatchings/1EA70", func_80020654);

INCLUDE_ASM("asm/nonmatchings/1EA70", func_80020958);

INCLUDE_ASM("asm/nonmatchings/1EA70", func_80020ACC);

INCLUDE_ASM("asm/nonmatchings/1EA70", func_80020CC4);

INCLUDE_ASM("asm/nonmatchings/1EA70", func_80020CFC);

INCLUDE_ASM("asm/nonmatchings/1EA70", func_80020DCC);

INCLUDE_ASM("asm/nonmatchings/1EA70", func_80020EA0);

void func_800211BC(s16 index, u8 arg1) {
    s16 i;
    unk2C0C0StructC0* temp_a3;

    temp_a3 = D_800F2B7C[index].unk_6C;
    for (i = 0; i < temp_a3->unk_6A; i++) {
        temp_a3->unk_80[i].unk_02 = arg1;
    }
}

void func_80021240(s16 index) {
    s16 i;
    unk2C0C0Struct90* temp_v1;
    unk2C0C0StructC0* temp_s0;

    temp_s0 = D_800F2B7C[index].unk_6C;
    func_80025930(index, 0x110000, 0x110000);
    for (i = 0; i < temp_s0->unk_76; i++) {
        temp_s0->unk_A8[i].unk_0D = 0xFF;
        temp_v1 = &temp_s0->unk_A8[i];
        temp_v1->unk_0C = temp_v1->unk_0C | 5;
    }
    func_80025AD4(index);
}

INCLUDE_ASM("asm/nonmatchings/1EA70", func_80021308);

INCLUDE_ASM("asm/nonmatchings/1EA70", func_80021474);

INCLUDE_ASM("asm/nonmatchings/1EA70", func_800214FC);

INCLUDE_ASM("asm/nonmatchings/1EA70", func_80021794);

INCLUDE_ASM("asm/nonmatchings/1EA70", func_80021A00);

INCLUDE_ASM("asm/nonmatchings/1EA70", func_80021AF4);

INCLUDE_ASM("asm/nonmatchings/1EA70", func_80021B04);

INCLUDE_ASM("asm/nonmatchings/1EA70", func_80021B14);

INCLUDE_ASM("asm/nonmatchings/1EA70", func_80021C50);

INCLUDE_ASM("asm/nonmatchings/1EA70", func_80021CDC);

INCLUDE_ASM("asm/nonmatchings/1EA70", func_80021E58);

void func_80021EA0() {
    func_800214FC(D_800ED4A8);
}

INCLUDE_ASM("asm/nonmatchings/1EA70", func_80021EC0);
