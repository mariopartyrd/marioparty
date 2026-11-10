#ifndef PIPEMAZE_H
#define PIPEMAZE_H

#include "common.h"

/* ovl_09 PipeMaze: declarations of its one unit (113DC0). Types come from the asm's accesses;
   N64 offsets are in the comments. */

/* One pipe-drop effect (func_800F9590's work: 20 of them, then 20 state bytes). */
typedef struct PMEffect {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;   /* alpha, passed on as u8 */
    /* 0x06 */ char unk6[2];
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ u16 unk1C;  /* model */
    /* 0x1E */ char unk1E[2];
} PMEffect; /* size 0x20 */

typedef struct PMEffectWork {
    /* 0x000 */ PMEffect e[20];
    /* 0x280 */ u8 state[20];
} PMEffectWork; /* size 0x294 */

void func_800F65E0_PipeMaze(void);
void func_800F6678_PipeMaze(void);
void func_800F673C_PipeMaze(void);
void func_800F6744_PipeMaze(void);
void func_800F68BC_PipeMaze(void);
void func_800F6A38_PipeMaze(omObjData*);
void func_800F6B04_PipeMaze(omObjData*);
void func_800F6C34_PipeMaze(omObjData*);
void func_800F6DD8_PipeMaze(s16, s16);
void func_800F7100_PipeMaze(void);
void func_800F7194_PipeMaze(omObjData*);
void func_800F7368_PipeMaze(omObjData*);
void func_800F7AC8_PipeMaze(omObjData*, s32);
void func_800F7C78_PipeMaze(void);
void func_800F7CD8_PipeMaze(void);
void func_800F7E2C_PipeMaze(void);
void func_800F7E78_PipeMaze(void);
void func_800F7EA4_PipeMaze(void);
void func_800F80CC_PipeMaze(omObjData*);
void func_800F8414_PipeMaze(omObjData*);
void func_800F8F24_PipeMaze(omObjData*, s32);
void func_800F9000_PipeMaze(void);
void func_800F9134_PipeMaze(omObjData*);
void func_800F9590_PipeMaze(omObjData*);
void func_800F9678_PipeMaze(omObjData*);
s16 func_800F97C4_PipeMaze(s16, f32, f32, f32, u16);

/* main code without a shared prototype */
void func_8006B9B0(omObjData*, f32, f32, f32); /* src/6C470.c */
void func_8006B9D0(omObjData*, f32, f32, f32); /* src/6C470.c */
f32 func_80025D40(s16);
void GMesPosSet(s16, f32, f32);
s16 func_80060758(s16);
void func_8006035C(s16, s8);             /* src/objmain.c */
void func_8006BADC(omObjData*, f32, f32, f32); /* src/6C470.c */
void func_8006BAF0(omObjData*, s32);     /* src/6C470.c */
s32 func_8006BAFC(omObjData*);           /* src/6C470.c */

extern s8 omSysPauseEnableFlag;
extern omObjData* D_800EDE70[];
extern u16 D_800EE984;
extern omObjData* D_800F2AF8[];
extern u8 D_800F64F8;
extern u16 ContBtn[];

/* .data */
extern s8 D_800F9900_PipeMaze;
extern s16 D_800F9902_PipeMaze;
extern s32 D_800F9904_PipeMaze;
extern s32 D_800F9908_PipeMaze;
extern s32 D_800F990C_PipeMaze;
extern s32 D_800F9910_PipeMaze;
extern u8 D_800F9914_PipeMaze;
extern s8 D_800F9915_PipeMaze;
extern s32 D_800F9918_PipeMaze;
extern f32 D_800F991C_PipeMaze;
extern f32 D_800F9920_PipeMaze;
extern f32 D_800F9924_PipeMaze;
extern u8 D_800F9928_PipeMaze[10][8];
extern s8 D_800F9978_PipeMaze;
extern s8 D_800F9979_PipeMaze;
extern s8 D_800F997A_PipeMaze;
extern u8 D_800F997B_PipeMaze;
extern u8 D_800F997C_PipeMaze;
extern f32 D_800F9980_PipeMaze;
extern s32 D_800F9984_PipeMaze;
extern s32 D_800F9988_PipeMaze[4];
extern f32 D_800F9998_PipeMaze[4][3];
extern f32 D_800F99C8_PipeMaze;
extern f32 D_800F99CC_PipeMaze;
extern f32 D_800F99D0_PipeMaze;
extern s8 D_800F99D4_PipeMaze;
extern u8 D_800F99D5_PipeMaze;
extern s8 D_800F99D6_PipeMaze;
extern u32 D_800F99D8_PipeMaze;
extern u32 D_800F99DC_PipeMaze;
extern s32 D_800F99E0_PipeMaze;
extern s32 D_800F99E4_PipeMaze;
extern s32 D_800F99E8_PipeMaze;
extern u32 D_800F99EC_PipeMaze;
extern u8 D_800F99F0_PipeMaze;

/* .bss (ovl_09_bss) */
extern s32 D_800F9A30_PipeMaze;
extern s32 D_800F9A34_PipeMaze;
extern s32 D_800F9A38_PipeMaze[16];
extern s32 D_800F9A78_PipeMaze[16];
extern u8 D_800F9AB8_PipeMaze[16][7]; /* the maze: 1 = rung, 2 = pipe */
extern s32 D_800F9B28_PipeMaze;
extern s32 D_800F9B2C_PipeMaze;
extern f32 D_800F9B30_PipeMaze;
extern f32 D_800F9B34_PipeMaze;
extern u8 D_800F9B38_PipeMaze;
extern s32 D_800F9B3C_PipeMaze;
extern s16 D_800F9B40_PipeMaze[4];
extern s16 D_800F9B48_PipeMaze[];
extern omObjData* D_800F9B74_PipeMaze;
extern f32 D_800F9B78_PipeMaze;
extern omObjData* D_800F9B80_PipeMaze;

#endif
