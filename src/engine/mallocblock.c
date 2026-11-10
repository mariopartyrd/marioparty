#include "common.h"
#include "engine/mallocblock.h"

s16 D_800C32A0 = 0;

void func_800235F0(void* (*arg0)(s32), void (*arg1)(void*)) {
    unkMallocBlockStruct* temp_v0;

    D_800F546C = arg0;
    D_800F33A4 = arg1;

    if (D_800C32A0 != 0) {
        func_80023974();
    }

    temp_v0 = (unkMallocBlockStruct*) D_800F546C(sizeof(unkMallocBlockStruct));
    D_800F2B78 = temp_v0;
    D_800F65DC = temp_v0;

    temp_v0->unk_00 = NULL;
    temp_v0->unk_06 = -1;
    temp_v0->unk_10 = temp_v0;
    temp_v0->unk_14 = temp_v0;

    D_800ECB10 = 0;
}

void* func_80023668(s32 size) {
    return func_800236A4(size, 0);
}

void* func_80023684(s32 size, s16 arg1) {
    return func_800236A4(size, arg1);
}

void* func_800236A4(s32 size, s16 arg1) {
    void* temp_v0;
    unkMallocBlockStruct* temp_v1;

    size = (size + 7) & ~7;

    temp_v0 = D_800F546C(size + sizeof(unkMallocBlockStruct));
    temp_v1 = (unkMallocBlockStruct*) (temp_v0 + size);

    temp_v1->unk_10 = D_800F65DC;
    temp_v1->unk_14 = D_800F65DC->unk_14;

    D_800F65DC->unk_14->unk_10 = temp_v1;
    D_800F65DC->unk_14 = temp_v1;

    temp_v1->unk_06 = arg1;
    temp_v1->unk_08 = size;
    temp_v1->unk_00 = temp_v0;
    temp_v1->unk_0C = D_800F3848;

    return temp_v1->unk_00;
}

void func_80023728(void* arg0) {
    unkMallocBlockStruct* var_a0 = D_800F65DC->unk_14;

    while (arg0 != var_a0->unk_00) {
        var_a0 = var_a0->unk_14;

        if (var_a0 == D_800F2B78) {
            return;
        }
    }

    func_80023780(var_a0);
}

void func_80023780(unkMallocBlockStruct* arg0) {
    arg0->unk_14->unk_10 = arg0->unk_10;
    arg0->unk_10->unk_14 = arg0->unk_14;

    D_800F33A4(arg0->unk_00);
}

void func_800237BC(s16 arg0) {
    unkMallocBlockStruct* var_a0 = D_800F65DC->unk_14;
    unkMallocBlockStruct* temp_s0;

    while (var_a0 != D_800F2B78) {
        if (var_a0->unk_06 == arg0) {
            if (var_a0->unk_06 != -1) {
                temp_s0 = var_a0->unk_10;
                func_80023780(var_a0);
                var_a0 = temp_s0;
            } else {
                var_a0->unk_04--;

                if (!(var_a0->unk_04 & 0xFF)) {
                    temp_s0 = var_a0->unk_10;
                    func_80023780(var_a0);
                    var_a0 = temp_s0;

                    D_800ECB10--;
                    if (D_800ECB10 <= 0) {
                        break;
                    }
                }
            }
        }

        var_a0 = var_a0->unk_14;
    }
}

void func_80023888(void* arg0) {
    unkMallocBlockStruct* var_v1 = D_800F65DC->unk_14;

    while (arg0 != var_v1->unk_00) {
        var_v1 = var_v1->unk_14;

        if (var_v1 == D_800F2B78) {
            return;
        }
    }

    var_v1->unk_06 = -1;
    var_v1->unk_04 = D_800F37DA + 1;
    D_800ECB10++;
}

void func_800238F0(s16 arg0) {
    unkMallocBlockStruct* var_v1 = D_800F65DC->unk_14;

    while (var_v1 != D_800F2B78) {
        if (var_v1->unk_06 == arg0) {
            var_v1->unk_06 = -1;
            var_v1->unk_04 = D_800F37DA + 1;
            D_800ECB10++;
        }

        var_v1 = var_v1->unk_14;
    }
}

void func_80023964(void) {
    D_800C32A0 = 1;
}

void func_80023974(void) {
    unkMallocBlockStruct* var_a0 = D_800F65DC->unk_14;

    while (var_a0 != D_800F2B78) {
        unkMallocBlockStruct* temp_s0 = var_a0->unk_10;
        func_80023780(var_a0);
        var_a0 = temp_s0->unk_14;
    }

    D_800F33A4(D_800F2B78);

    D_800ECB10 = 0;
    D_800C32A0 = 0;
}

void func_800239EC(void) {
    if (D_800C32A0 != 0) {
        func_80023974();
    } else if (D_800ECB10 != 0) {
        func_800237BC(-1);
    }
}

void func_80023A38(void* arg0, void* arg1, s32 arg2) {
    for (; arg2 != 0; arg2--) {
        *((u8*) arg1) = *((u8*) arg0);
        arg0++;
        arg1++;
    }
}

s32 func_80023A60(s16 arg0) {
    unkMallocBlockStruct* var_v1 = D_800F65DC->unk_14;
    s32 var_a1 = 0;

    while (var_v1 != D_800F2B78) {
        if (var_v1->unk_06 == arg0) {
            var_a1 += var_v1->unk_08;
        }

        var_v1 = var_v1->unk_14;
    }

    return var_a1;
}

s32 func_80023AB4(void) {
    unkMallocBlockStruct* var_v1 = D_800F65DC->unk_14;
    s32 var_a0 = 0;

    while (var_v1 != D_800F2B78) {
        var_a0 += var_v1->unk_08;
        var_v1 = var_v1->unk_14;
    }

    return var_a0;
}

void func_80023AF0(void* arg0, s16 arg1) {
    unkMallocBlockStruct* var_v1 = D_800F65DC->unk_14;

    while (arg0 != var_v1->unk_00) {
        var_v1 = var_v1->unk_14;

        if (var_v1 == D_800F2B78) {
            return;
        }
    }

    var_v1->unk_06 = arg1;
}
