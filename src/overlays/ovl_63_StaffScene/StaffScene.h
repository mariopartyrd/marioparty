#ifndef OVL63_STAFFSCENE_H
#define OVL63_STAFFSCENE_H

#include "common.h"

/* ovl_63: the staff credits after the final story board (the game's last scene).
 * 2A9970.c is the overlay entry (setup, the scene process, the skip/exit objects); 2A9CA0.c the
 * scenes and the credits roll, and it owns every .data object (2A9970 has none). */

typedef struct StaffCtl {
    /* 0x00 */ s16 cmd;  /* written by the scene: 4 start, 5 continue, 1 stop... */
    /* 0x02 */ s16 stat; /* the process's state; < 0 once it has finished */
} StaffCtl;

/* func_800F7684's squash keys: the scale reached after `frames` frames; 0 frames ends */
typedef struct StaffScaleKey {
    /* 0x00 */ f32 scale;
    /* 0x04 */ s32 frames;
} StaffScaleKey;

typedef struct StaffXY {
    s16 x;
    s16 y;
} StaffXY;

/* One page of the credits roll (D_800FD4C0, ended by names == NULL) */
typedef struct StaffCredit {
    /* 0x00 */ s16* names; /* message ids */
    /* 0x04 */ s16 count;
    /* 0x08 */ s16* rows;  /* names per row, 0 ends */
    /* 0x0C */ s16 title;  /* message id */
} StaffCredit; /* N64 size 0x10 */

/* A model of the final scene (D_800FD6A0) */
typedef struct StaffObjDef {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ s32 file;
    /* 0x0C */ s32 file2; /* -1: none */
} StaffObjDef;

/* The control block func_800F91E0 shares with each credits process (8380 title, 8894 names, 94E0 coin) */
typedef struct StaffRoll {
    /* 0x00 */ s16* names; /* message ids (the title process: one) */
    /* 0x04 */ s16* rows;  /* names per row, 0 ends */
    /* 0x08 */ s16 count;
    /* 0x0A */ s16 slot;   /* the screen corner, 0-3 */
    /* 0x0C */ s16 tex;
    /* 0x0E */ s16 stat;
    /* 0x10 */ s16 cmd;
    /* 0x12 */ u8 unk_12[6];
} StaffRoll; /* N64 size 0x18 */

/* A camera setting (func_800FC554) */
typedef struct StaffCamera {
    /* 0x00 */ Vec3f center;
    /* 0x0C */ Vec3f rot;
    /* 0x18 */ f32 zoom;
    /* 0x1C */ f32 fov;
} StaffCamera;

/* A model run by its own process (func_800FC998 creates it, func_800FC864 runs it) */
typedef struct StaffModel {
    /* 0x00 */ Process* proc;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ Vec3f scale;
    /* 0x1C */ Vec3f rot;
    /* 0x28 */ s16 cmd;  /* 1 delete, 3 show, 4 hide */
    /* 0x2A */ s16 stat; /* -1 once deleted */
    /* 0x2C */ s16 model;
} StaffModel; /* N64 size 0x30 */

/* The sparkles that follow a StaffModel (func_800FD0F0 creates them, func_800FCAF4 runs them) */
typedef struct StaffSparkle {
    /* 0x00 */ Process* proc;
    /* 0x04 */ StaffModel* target;
    /* 0x08 */ u8 unk_08[0xC];
    /* 0x14 */ s16 type;
    /* 0x16 */ u16 cmd;
    /* 0x18 */ s16 stat; /* -1 once deleted */
} StaffSparkle; /* N64 size 0x1C */

/* One sparkle particle (an array of them per StaffSparkle) */
typedef struct StaffSparkleDot {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ f32 angle;
    /* 0x10 */ s16 model;
    /* 0x12 */ s16 timer;
} StaffSparkleDot; /* size 0x14 */

/* .bss (2A9970.c's users) */
extern u16 D_800FE2E0_StaffScene; /* the saved D_800C597C */
extern s32 D_800FE2F0_StaffScene;
extern s32 D_800FE2F4_StaffScene; /* set when a player skipped the credits with Start */

/* .data (defined in 2A9CA0.c) */
extern void (*D_800FD920_StaffScene[])(void); /* the scenes, run in order; NULL ends */

void func_800F9F70_StaffScene(void);
void func_800FA4F4_StaffScene(void);
void func_800F6AA0_StaffScene(void);
void func_800F6F00_StaffScene(void);
void func_800FC480_StaffScene(void);

#endif
