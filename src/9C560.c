#include "common.h"

/* KMC libc strcpy (word-at-a-time when both pointers share alignment). */
char* func_8009B960(char* dst, const char* src) {
    char* cursor = dst;

    if (((src - dst) & 3) != 0) {
        *dst = *src;
        src++;
        cursor = dst + 1;
        if (*dst == '\0') {
            return dst;
        }
        do {
            *cursor = *src++;
        } while (*cursor++ != '\0');
        return dst;
    }

    while (((s32)cursor & 3) != 0) {
        *cursor = *src++;
        if (*cursor++ == '\0') {
            return dst;
        }
    }

    for (;;) {
        u32 word = *(const u32*)src;

        src += 4;
        if ((word & 0xFF000000) == 0) {
            cursor[0] = '\0';
            return dst;
        }
        if ((word & 0x00FF0000) == 0) {
            *(u16*)cursor = (u16)(word >> 16);
            return dst;
        }
        if ((word & 0x0000FF00) == 0) {
            *(u16*)cursor = (u16)(word >> 16);
            cursor[2] = '\0';
            return dst;
        }

        *(u32*)cursor = word;
        cursor += 4;
        if ((word & 0xFF) == 0) {
            return dst;
        }
    }
}
