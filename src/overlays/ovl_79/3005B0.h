#include "common.h"

/* The head of 42E40.c's SpriteAnimWork (func_800429CC's result); no pointers before 0x10. */
typedef struct ResSpriteAnim {
    /* 0x00 */ u16 flags;
    /* 0x02 */ s16 frame;
    /* 0x04 */ s16 count;
    /* 0x06 */ u16 attr;
    /* 0x08 */ s16 x;
    /* 0x0A */ s16 y;
    /* 0x0C */ f32 scale;
} ResSpriteAnim;

void* func_800429CC(s16, s16);
void func_80042B10(ResSpriteAnim*);
void func_80070D90(s16);
/* window id: an s32 whose low half retail also reads as D_800F74CE */
extern s32 D_800F74CC_name_79;
extern ResSpriteAnim* D_800F74D0_name_79;
