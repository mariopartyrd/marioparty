#include "common.h"

// Initializes all bytes of a struct (arg0) with the same value (arg1).
void* func_8009B770(void* arg0, u8 arg1, u32 size) {
    u32 var_a2 = size;
    void* var_a3;
    s32 temp_a1;
    s32 i;

    if (var_a2 == 0) {
        return arg0;
    }

    temp_a1 = arg1 | (arg1 << 8);
    temp_a1 = temp_a1 | (temp_a1 << 16);

    var_a3 = arg0;

    if ((s32) var_a3 & 1) {
        *((u8*) var_a3) = temp_a1;
        var_a3++;
        var_a2--;
    }

    if (var_a2 > 1 && (s32) var_a3 & 2) {
        *((u16*) var_a3) = temp_a1;
        var_a3 += 2;
        var_a2 -= 2;
    }

    for (i = var_a2 / 4 - 1; i != -1; i--) {
        *((u32*) var_a3) = temp_a1;
        var_a3 += 4;
    }

    if (var_a2 & 2) {
        *((u16*) var_a3) = temp_a1;
        var_a3 += 2;
    }

    if (var_a2 & 1) {
        *((u8*) var_a3) = temp_a1;
    }

    return arg0;
}

/* memset-style argument order (dst, size, value) over func_8009B770 (dst, value, size). */
void* func_8009B810(void* dst, u32 size, s32 value) {
    /* retail passes value unnarrowed: the original saw func_8009B770 with an int parameter */
    return ((void* (*)(void*, s32, u32))func_8009B770)(dst, value, size);
}