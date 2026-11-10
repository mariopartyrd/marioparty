#ifndef GHOSTGUESS_H
#define GHOSTGUESS_H

/* ovl_0A GhostGuess: declarations shared by its units (117210, 11BFE0). N64 offsets in comments. */

#include "common.h"
#include "engine/pad.h"
#include "sprite65770.h"

/* A ghost (D_800FBC18[8]): its object reaches it through func_800FB224/func_800FB244. */
typedef struct GGGhost {
/* 0x00 */ omObjData* obj;
/* 0x04 */ u8 unk_04; /* 1: the ghost to find */
/* 0x05 */ u8 unk_05; /* index */
/* 0x06 */ u16 unk_06; /* state */
/* 0x08 */ u16 unk_08; /* texture index */
/* 0x0A */ s16 unk_0A;
/* 0x0C */ s16 unk_0C;
/* 0x0E */ s16 unk_0E;
/* 0x10 */ Vec pos;
/* 0x1C */ Vec rot;
/* 0x28 */ Vec scale;
/* 0x34 */ Vec unk_34;
/* 0x40 */ f32 unk_40;
/* 0x44 */ f32 unk_44;
/* 0x48 */ f32 unk_48;
/* 0x4C */ f32 unk_4C;
/* 0x50 */ f32 unk_50;
} GGGhost; /* size = 0x54 on the N64 */

/* A ghost object's work (func_800F789C, 0x6C bytes): the head of the player work's layout
   (unkGlobalStruct_00), which has no pointer before 0x6C. */
typedef struct GGGhostWork {
/* 0x00 */ char unk_00[0x34];
/* 0x34 */ f32 unk_34;
/* 0x38 */ char unk_38[4];
/* 0x3C */ f32 unk_3C;
/* 0x40 */ char unk_40[4];
/* 0x44 */ f32 unk_44;
/* 0x48 */ f32 unk_48;
/* 0x4C */ char unk_4C[4];
/* 0x50 */ s16 unk_50;
/* 0x52 */ s8 unk_52;
/* 0x53 */ char unk_53[1];
/* 0x54 */ u8 unk_54;
/* 0x55 */ char unk_55[7];
/* 0x5C */ s32 unk_5C;
/* 0x60 */ f32 unk_60;
/* 0x64 */ char unk_64[8];
} GGGhostWork; /* size = 0x6C */

/* D_800FBED0[11]: [0] is the camera/target state (its unk_0C holds the object func_800F6E78
   creates), [1..10] the sprites func_800F80E4 animates. */
typedef struct GGRec {
/* 0x00 */ s16 unk_00;
/* 0x02 */ s16 unk_02; /* state */
/* 0x04 */ s16 unk_04;
/* 0x06 */ s16 unk_06;
/* 0x08 */ s16 unk_08; /* timer */
/* 0x0A */ s16 unk_0A;
/* 0x0C */ omObjData* unk_0C;
/* 0x10 */ Vec pos;
/* 0x1C */ f32 unk_1C;
/* 0x20 */ f32 unk_20;
/* 0x24 */ f32 unk_24;
/* 0x28 */ f32 unk_28;
/* 0x2C */ f32 unk_2C;
/* 0x30 */ f32 unk_30;
/* 0x34 */ Vec scale;
/* 0x40 */ s16 unk_40; /* model / image id */
/* 0x42 */ s16 unk_42;
/* 0x44 */ s16 unk_44;
/* 0x46 */ s16 unk_46;
/* 0x48 */ s16 unk_48;
/* 0x4A */ char unk_4A[0x16];
} GGRec; /* size = 0x60 on the N64 */

extern f32 D_800B895C;
extern f32 D_800B8960;
extern f32 D_800B8964;
extern f32 D_800B8968;
extern f32 D_800B896C;
extern f32 D_800B8970;
extern f32 D_800B897C;
extern f32 D_800B8980;
extern f32 D_800B8984;
extern f32 D_800B8988;
extern f32 D_800B898C;
extern f32 D_800B8990;
extern f32 D_800B8994;
extern f32 D_800B8998;
extern f32 D_800B899C;
extern u16 D_800EE984;
extern omObjData* D_800F2AF8[];
extern omObjData* D_800EDE70[];
extern unk2C0C0Struct70* D_800F37AC;

/* .data (117210.c) */
extern s32 D_800FB670_GhostGuess; /* game state */
extern s32 D_800FB67C_GhostGuess[8]; /* sound handles; read as (s16) */
extern s32 D_800FB6D0_GhostGuess; /* 1: the player found the ghost */
extern s32 D_800FB6DC_GhostGuess;
extern s32 D_800FB6E0_GhostGuess;
extern s32 D_800FB6E4_GhostGuess;
extern s32 D_800FB6E8_GhostGuess;
extern s32 D_800FB6EC_GhostGuess; /* a sound handle; read as (s16) */
extern s32 D_800FB6F0_GhostGuess;
extern f32 D_800FB6F4_GhostGuess; /* the CPU's heading */
extern f32 D_800FB6F8_GhostGuess;
extern s32 D_800FB6A4_GhostGuess; /* the ghost nearest the player */
extern s32 D_800FB6A8_GhostGuess; /* spin direction */
extern f32 D_800FB6B0_GhostGuess[4]; /* spin speed by CPU difficulty */
extern f32 D_800FB6C0_GhostGuess[4]; /* by CPU difficulty */
extern s32 D_800FB6D4_GhostGuess;
extern f32 D_800FB6FC_GhostGuess;
extern f32 D_800FB700_GhostGuess;
extern s32 D_800FB704_GhostGuess; /* timer */
extern s32 D_800FB708_GhostGuess;
f32 func_80025E70(s16);
f32 func_80025D18(s16);
void func_80066DF4(s16 grpIdx, s16 idx, s16 camIdx, f32 x, f32 y, f32 z);
void func_800670C4(s16 grpIdx, s16 idx, s16 camIdx, f32 x, f32 y, f32 z);
void func_8006035C(s16, s8);
extern s32 D_800FB678_GhostGuess;
extern f32 D_800FB674_GhostGuess;
extern s32 D_800FB69C_GhostGuess; /* the ghost to find (the CPU reads its low byte) */
extern s32 D_800FB6A0_GhostGuess; /* the ghost the player touched */
extern s32 D_800FB6AC_GhostGuess;
f64 func_8009B618(f64, f64);
extern s16 D_800FB6D8_GhostGuess[2];
f32 func_80025D40(s16);
void func_800093FC(omObjData*, f32, f32, f32);
void func_800090C4(omObjData* obj, u8 idx, u8 val);

/* .bss */
extern omObjData* D_800FBBE0_GhostGuess;
extern omObjData* D_800FBBE4_GhostGuess;
extern omObjData* D_800FBBE8_GhostGuess;
extern omObjData* D_800FBBEC_GhostGuess;
extern s32 D_800FBBF0_GhostGuess[4]; /* model ids (u16 results); read as (s16) */
extern s32 D_800FBC00_GhostGuess;
extern s32 D_800FBC04_GhostGuess;
extern s32 D_800FBC08_GhostGuess;    /* the player's index; read as (s16) */
extern s32 D_800FBC0C_GhostGuess;
extern s16 D_800FBC10_GhostGuess;
extern s16 D_800FBC12_GhostGuess;
extern GGGhost D_800FBC18_GhostGuess[8];
extern s32 D_800FBEB8_GhostGuess; /* sprite group ids (s16 results); read as (s16) */
extern s32 D_800FBEBC_GhostGuess;
extern s32 D_800FBEC0_GhostGuess;
extern GGRec D_800FBED0_GhostGuess[11];
u16 func_8001E1D0(s16 index, s32 arg1);
/* Record 0's fields: retail addresses them as separate globals (splat's labels); the host
   views them in the one array. */
extern s16 D_800FBED2_GhostGuess;
extern s16 D_800FBEDA_GhostGuess;
extern omObjData* D_800FBEDC_GhostGuess;
extern f32 D_800FBEE0_GhostGuess;
extern f32 D_800FBEE4_GhostGuess;
extern f32 D_800FBEE8_GhostGuess;
extern f32 D_800FBEEC_GhostGuess;
extern f32 D_800FBEF0_GhostGuess;
extern f32 D_800FBEF4_GhostGuess;
extern f32 D_800FBEF8_GhostGuess;
extern f32 D_800FBEFC_GhostGuess;
extern f32 D_800FBF00_GhostGuess;
extern s16 D_800FBF10_GhostGuess;
extern s16 D_800FBF12_GhostGuess;


void func_800F65E0_GhostGuess(void);
void func_800F69DC_GhostGuess(omObjData* arg0);
void func_800F6AAC_GhostGuess(void);
void func_800F6AE0_GhostGuess(omObjData* arg0);
void func_800F6BA4_GhostGuess(omObjData* arg0);
void func_800F6E78_GhostGuess(omObjData* arg0);
void func_800F6FF4_GhostGuess(omObjData* arg0);
void func_800F73E0_GhostGuess(omObjData* arg0);
void func_800F789C_GhostGuess(omObjData* arg0);
void func_800F79D4_GhostGuess(omObjData* arg0);
void func_800F7FD8_GhostGuess(f32 x, f32 y, f32 z, s32 arg3);
void func_800F80E4_GhostGuess(omObjData* arg0);
s32 func_800F86CC_GhostGuess(omObjData* arg0, omObjData* arg1);
void func_80017C0C(omObjData* obj, u8 idx, f32 x, f32 y, f32 z, f32 a, f32 b);
void func_800F8888_GhostGuess(omObjData* arg0);
void func_800F9400_GhostGuess(omObjData* arg0, f32 max);
s32 func_80017A60(omObjData* obj);
s16 func_80010ED4(s16 id, s16 chanOfs);
void func_80060F04(s16, s32, s32, s32);
void func_800F948C_GhostGuess(omObjData* arg0);
void func_800FA764_GhostGuess(omObjData* arg0);
void func_800FB21C_GhostGuess(void);
void func_800FB224_GhostGuess(omObjData* arg0, u32 arg1);
s32 func_800FB244_GhostGuess(omObjData* arg0);
void func_800FB270_GhostGuess(s16 arg0, s16 arg1);
void func_800FB2D0_GhostGuess(s32 arg0, s32 arg1);
void func_800FB3B0_GhostGuess(void);
void func_800FB448_GhostGuess(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, u16 arg7);
void func_800FB4B0_GhostGuess(void);
void func_800FB514_GhostGuess(void);

/* A ghost record kept in its object's work[]: the N64 stores the pointer's bytes, the host the
   record's index (a pointer does not fit in four bytes). */
#define GG_GHOST_SET(obj, g) func_800FB224_GhostGuess((obj), (u32)(g))
#define GG_GHOST(obj) ((GGGhost*)func_800FB244_GhostGuess(obj))

extern Vec3f D_800FC2F0_GhostGuess;
extern Vec3f D_800FC2FC_GhostGuess;
extern Vec3f D_800FC308_GhostGuess;
extern Vec3f D_800FC314_GhostGuess;
extern f32 D_800FC320_GhostGuess;
extern f32 D_800FC324_GhostGuess;
extern s16 D_800FC328_GhostGuess;
extern u16 D_800FC32A_GhostGuess;

#endif
