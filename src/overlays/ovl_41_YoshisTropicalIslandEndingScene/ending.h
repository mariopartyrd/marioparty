#ifndef OVL41_ENDING_H
#define OVL41_ENDING_H

#include "common.h"

/* ovl_41: the story ending. 25FC70.c owns the shared state and the per-board dispatch tables
 * (D_8010DD7C, D_8010DD9C, indexed by D_801102B0); each later unit is one board's scene.
 *
 * Shared globals: these declarations are the only ones. The bss blocks below are arrays that
 * splat cut into labels (D_80110304, D_8011044C, D_801102BA, ...): write the element
 * (D_80110300_YoshisTropicalIslandEndingScene[1]), never declare an inner label. On the N64 the
 * code is the same (%lo(D_80110300+4)); on the host the elements are 8-byte pointers and a
 * separate label would be a separate object. */

/* .data (defined in 25FC70.c) */
extern s32 D_8010DC90_YoshisTropicalIslandEndingScene[3];                /* indexed (D_8010DC98 is [2]) */
extern Vec3f D_8010DC9C_YoshisTropicalIslandEndingScene[8];             /* splat's DCA0/DCA4 are [0].y/.z: write the field */
extern f32 D_8010DCFC_YoshisTropicalIslandEndingScene[8];
extern f32 D_8010DD1C_YoshisTropicalIslandEndingScene[8];
extern s32 D_8010DD3C_YoshisTropicalIslandEndingScene[8];
extern void (*D_8010DD7C_YoshisTropicalIslandEndingScene[8])(void);
extern void (*D_8010DD9C_YoshisTropicalIslandEndingScene[8])(void);

/* .bss (N64 sizes; the init loop func_800F6A90 clears 16 of each) */
extern u8 D_801102B0_YoshisTropicalIslandEndingScene;                    /* the board index: a scalar (retail never hoists its address) */
/* written as words (-1, a u16 file id), read as (s16) — lh at +2 on the N64 */
extern s32 D_801102B8_YoshisTropicalIslandEndingScene[16];
extern omObjData* D_80110300_YoshisTropicalIslandEndingScene[16]; /* omAddObj */
extern Vec3f D_80110340_YoshisTropicalIslandEndingScene[];
extern void* D_80110400_YoshisTropicalIslandEndingScene[16];      /* func_80042728 */
extern s32 D_80110440_YoshisTropicalIslandEndingScene;            /* func_8004F954; a scalar (54 uses, all at +0) */
extern Object* D_80110448_YoshisTropicalIslandEndingScene[16];    /* MBModelCreate */

/* Teardown shared by every scene (25FC70.c): deletes the objects and models of the blocks above */
void func_800F6B54_YoshisTropicalIslandEndingScene(void);

/* Per-board scenes (D_8010DD9C) and their setup (D_8010DD7C) */
void func_800F8550_YoshisTropicalIslandEndingScene(void);
void func_800F8848_YoshisTropicalIslandEndingScene(void);
void func_800F96E4_YoshisTropicalIslandEndingScene(void);
void func_800FA580_YoshisTropicalIslandEndingScene(void);
void func_800FB648_YoshisTropicalIslandEndingScene(void);
void func_800FD5F0_YoshisTropicalIslandEndingScene(void);
void func_8010329C_YoshisTropicalIslandEndingScene(void);
void func_80105360_YoshisTropicalIslandEndingScene(void);
void func_80109294_YoshisTropicalIslandEndingScene(void);
void func_8010CC94_YoshisTropicalIslandEndingScene(void);
void func_8010D06C_YoshisTropicalIslandEndingScene(void);

#endif
