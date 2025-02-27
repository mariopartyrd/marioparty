#include "common.h"

void* func_8003B820() {
    Object* temp_v0_2;
    unk_ProcessUserData08* temp_v0;

    temp_v0 = MallocTemp(0x8);
    temp_v0->unk00 = 0;
    temp_v0_2 = CreateObject(0x24, NULL);
    temp_v0->unk04 = temp_v0_2;
    func_800258EC(*temp_v0_2->unk_3C->unk_40, 0x180, 0);
    func_80025AD4(*temp_v0->unk04->unk_3C->unk_40);
    func_80025F60(*temp_v0->unk04->unk_3C->unk_40, 0x1400);
    return temp_v0;
}

void func_8003B8A4(unk_ProcessUserData08* arg0) {
    DestroyObject(arg0->unk04);
    FreeTemp(arg0);
}

void func_8003B8D4() {
    unk_8003B8D4Struct* temp_v0;

    temp_v0 = MallocTemp(0x6C);
    temp_v0->unk00 = 0;
    temp_v0->unk02 = 0;
    temp_v0->unk04 = 0;
    temp_v0->unk08 = 0;
    temp_v0->unk0C = 0;
    temp_v0->unk68 = 0;
}

void func_8003B908(unk_8003B8D4Struct* arg0) {
    Process* temp_a0_2;
    s16 temp_v0;
    s32 var_s0;
    unk_ProcessUserData08** var_s1;
    unk_ProcessUserData08* temp_a0;

    temp_v0 = arg0->unk02;
    if (temp_v0 != 0) {
        var_s1 = arg0->unk04;
        for (var_s0 = 0; var_s0 < arg0->unk02; var_s0++) {
            temp_a0 = *var_s1;
            var_s1++;
            func_8003B8A4(temp_a0);
        }
        FreeTemp(arg0->unk04);
    }
    temp_a0_2 = arg0->unk08;
    if (temp_a0_2 != NULL) {
        EndProcess(temp_a0_2);
    }
    FreeTemp(arg0);
}

void func_8003B994(unk_8003B8D4Struct* arg0, s16* arg1, s16 arg2) {
    s16** temp_a0_2;
    s16** temp_v0;
    s16** temp_v0_2;
    s16** var_a0;
    s16** var_a1;
    s32 var_v1;
    u16 temp_a0;

    temp_a0 = arg0->unk02 + 1;
    arg0->unk02 = temp_a0;
    temp_v0 = MallocTemp((temp_a0 << 0x10) >> 0xE);
    temp_v0_2 = arg0->unk04;
    var_a0 = temp_v0;
    if (temp_v0_2 != NULL) {
        var_a1 = temp_v0_2;
        for (var_v1 = 0; var_v1 < (arg0->unk02 - 1); var_v1++) {
            *var_a0 = *var_a1;
            var_a1++;
            var_a0++;
        }
    }
    *var_a0 = arg1;
    temp_a0_2 = arg0->unk04;
    if (temp_a0_2 != NULL) {
        FreeTemp(temp_a0_2);
    }
    arg0->unk04 = temp_v0;
    *arg1 = arg2;
    if (arg2 & 1) {
        arg0->unk0C = arg0->unk02 - 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/3C420", func_8003BA68);

INCLUDE_ASM("asm/nonmatchings/3C420", func_8003BB30);

INCLUDE_ASM("asm/nonmatchings/3C420", func_8003BB48);

INCLUDE_ASM("asm/nonmatchings/3C420", func_8003BE84);

INCLUDE_ASM("asm/nonmatchings/3C420", func_8003BEB4);

INCLUDE_ASM("asm/nonmatchings/3C420", func_8003C060);

INCLUDE_ASM("asm/nonmatchings/3C420", DirectionPrompt);

INCLUDE_ASM("asm/nonmatchings/3C420", func_8003C198);

INCLUDE_ASM("asm/nonmatchings/3C420", func_8003C218);
