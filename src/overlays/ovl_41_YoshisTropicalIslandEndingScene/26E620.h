#ifndef OVL41_26E620_H
#define OVL41_26E620_H

#include "ending.h"

/* bss camera block at D_801101C0 (only 26E620.c uses it). Retail reads the last three floats
 * both as splat's separate labels D_801101E4/E8/EC and through the block's base; the host makes
 * them views of the one object (gen_ovl.py then sizes D_801101C0 to cover them). */
typedef struct EndingCamera {
    /* 0x00 */ Vec3f eye;
    /* 0x0C */ Vec3f at;
    /* 0x18 */ Vec3f up;
    /* 0x24 */ f32 near;
    /* 0x28 */ f32 far;
    /* 0x2C */ f32 fov;
} EndingCamera;
extern EndingCamera D_801101C0_YoshisTropicalIslandEndingScene;
extern f32 D_801101E4_YoshisTropicalIslandEndingScene;
extern f32 D_801101E8_YoshisTropicalIslandEndingScene;
extern f32 D_801101EC_YoshisTropicalIslandEndingScene;

/* 26E620.c's last .rodata word, read by 2721F0.c (func_80109294) */

void func_80107660_YoshisTropicalIslandEndingScene(void);
void func_801088C4_YoshisTropicalIslandEndingScene(s16 model, f32 len, f32 pos, Vec3f* out);

#endif
