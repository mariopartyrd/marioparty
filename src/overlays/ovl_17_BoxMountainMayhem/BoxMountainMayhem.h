#ifndef BOXMOUNTAINMAYHEM_H
#define BOXMOUNTAINMAYHEM_H

/* ovl_17 BoxMountainMayhem: declarations shared by its units (166220, 166D50, 168CA0).
   Types come from the asm's accesses. N64 offsets are in the comments; a struct with no pointers
   has the same layout on the host. Every work block is allocated with sizeof (never retail's
   literal size): the host strides pointers 8 bytes. */

#include "common.h"
#include "engine/pad.h"

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* A box stack's levels (BMMStageWork.unk_28 of the D_800FC1F8 grid objects, func_800F935C).
   Level 0 is the bottom box. No pointers. */
typedef struct BMMStackExt {
    /* 0x00 */ f32 unk_00[4]; /* drop height left per level (falls 37.5 a frame) */
    /* 0x10 */ s16 unk_10[4]; /* particle group of a broken box, -1 none */
    /* 0x18 */ s16 unk_18[4]; /* its frames left */
    /* 0x20 */ u8 unk_20[4];  /* contents per level: 1 a coin, 2 an empty flying box, 3 a box with 3 coins */
    /* 0x24 */ u8 unk_24[4];  /* hits left per level */
} BMMStackExt; /* size = 0x28 */

/* Work of the stage (D_800FC240, func_800F90A8) and of the box stacks (D_800FC1F8, func_800F935C):
   MgWork's first 0x28 bytes (src/99E0.c; D_800F2AF8's collision models), zeroed and filled by
   func_80009028/func_80009058. Only the stacks use unk_28. */
typedef struct BMMStageWork {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01; /* flags: 8 bounds on, 0x10 solid */
    /* 0x02 */ char unk_02[2];
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10; /* top */
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18; /* min x */
    /* 0x1C */ f32 unk_1C; /* min z */
    /* 0x20 */ f32 unk_20; /* max x */
    /* 0x24 */ f32 unk_24; /* max z */
    /* 0x28 */ BMMStackExt* unk_28;
} BMMStageWork; /* size = 0x2C (N64) */

#define BMM_STAGE(obj) ((BMMStageWork*)(obj)->unk_50)

/* Extension of the four thrown boxes D_800FC1E0 (func_800F719C, func_80023684(0x30)). */
typedef struct BMMBoxExt {
    /* 0x00 */ f32 unk_00; /* vertical speed */
    /* 0x04 */ f32 unk_04; /* gravity */
    /* 0x08 */ f32 unk_08; /* x speed */
    /* 0x0C */ f32 unk_0C; /* z speed */
    /* 0x10 */ f32 unk_10; /* target x */
    /* 0x14 */ f32 unk_14; /* target z */
    /* 0x18 */ omObjData* unk_18; /* thrower (a player) */
    /* 0x1C */ f32 unk_1C; /* offset from the thrower */
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28; /* thrower's motion frame */
    /* 0x2C */ f32 unk_2C; /* its speed */
} BMMBoxExt; /* size = 0x30 (N64) */

/* Extension of the twelve coins D_800FC248 (func_800F80A0, func_80023684(8)). */
typedef struct BMMCoinExt {
    /* 0x00 */ f32 unk_00; /* vertical speed */
    /* 0x04 */ f32 unk_04; /* gravity */
} BMMCoinExt; /* size = 0x8 */

/* Work of the bodies added to D_800EDE70 (src/1130.c's collision list): the thrown boxes
   D_800FC1E0 and the coins D_800FC248, func_80023684(0x6C). Fields up to 0x64 follow src/1130.c's
   PlayerWork; unk_21[slot] is the sprite of model[slot] (func_800FBE9C). */
typedef struct BMMBodyWork {
    /* 0x00 */ char unk_00[0x21];
    /* 0x21 */ u8 unk_21[4];
    /* 0x25 */ char unk_25[0xF];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C; /* facing angle */
    /* 0x40 */ f32 unk_40; /* speed */
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48; /* collision radius */
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ u8 unk_53;
    /* 0x54 */ u8 unk_54; /* state: 0 idle, 1 thrown / flying, 2 landing, 3 in the air */
    /* 0x55 */ u8 unk_55;
    /* 0x56 */ char unk_56[2];
    /* 0x58 */ f32 unk_58;
    /* 0x5C */ s32 unk_5C; /* frames of flight left */
    /* 0x60 */ s32 unk_60;
    /* 0x64 */ omObjData* unk_64; /* carrier (1130.c) */
    /* 0x68 */ union {
        BMMBoxExt* box;   /* D_800FC1E0 */
        BMMCoinExt* coin; /* D_800FC248 */
    } unk_68;
} BMMBodyWork; /* size = 0x6C (N64) */

#define BMM_BODY(obj) ((BMMBodyWork*)(obj)->unk_50)

/* The per-player extension (BMMPlayerWork.unk_E4; func_80023684(0x14) in func_800FA498). */
typedef struct BMMPlayerExt {
    /* 0x00 */ f32 unk_00; /* coin icon height */
    /* 0x04 */ s16 unk_04; /* controller port */
    /* 0x06 */ u16 unk_06; /* CPU buttons last frame */
    /* 0x08 */ u16 unk_08; /* CPU target: 0 none, 1 coin, 3 box stack */
    /* 0x0A */ char unk_0A[2];
    /* 0x0C */ u16 unk_0C; /* CPU difficulty */
    /* 0x0E */ u16 unk_0E;
    /* 0x10 */ u16 unk_10; /* coin icon state */
    /* 0x12 */ u16 unk_12;
} BMMPlayerExt; /* size = 0x14 */

/* The four player objects' work (D_800FC278[i]->unk_50: func_8000979C allocates a MgWork, 0xE8).
   MgWork's layout (src/99E0.c) with the fields this overlay touches; its pointers sit where
   MgWork's do (0xB8, 0xD8, 0xDC, 0xE4). unk_21[slot] is the sprite of model[slot]. */
typedef struct BMMPlayerWork {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ char unk_02[3];
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ u8 unk_20;
    /* 0x21 */ u8 unk_21[11];
    /* 0x2C */ char unk_2C[8];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38; /* 1000.0f = on the ground */
    /* 0x3C */ f32 unk_3C; /* facing angle */
    /* 0x40 */ f32 unk_40; /* speed */
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48; /* collision radius */
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ u8 unk_53;
    /* 0x54 */ s8 unk_54;
    /* 0x55 */ u8 unk_55;
    /* 0x56 */ s8 unk_56; /* controller port */
    /* 0x57 */ u8 unk_57;
    /* 0x58 */ s8 unk_58; /* player index */
    /* 0x59 */ char unk_59[3];
    /* 0x5C */ s32 unk_5C; /* state flags */
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ char unk_68[0x4A];
    /* 0xB2 */ s8 unk_B2;
    /* 0xB3 */ s8 unk_B3;
    /* 0xB4 */ char unk_B4[4];
    /* 0xB8 */ omObjData* unk_B8;
    /* 0xBC */ char unk_BC[0x1C];
    /* 0xD8 */ void* unk_D8;
    /* 0xDC */ void* unk_DC; /* collision callback (1130.c) */
    /* 0xE0 */ char unk_E0[4];
    /* 0xE4 */ BMMPlayerExt* unk_E4;
} BMMPlayerWork; /* size = 0xE8 (N64) */

#define BMM_PLAYER(obj) ((BMMPlayerWork*)(obj)->unk_50)

/* ---------------------------------------------------------------------------------------------
   Main-code declarations missing from include/
   --------------------------------------------------------------------------------------------- */
void func_800090C4(omObjData* obj, u8 idx, u8 val);
void func_800090D8(omObjData*, u8, u8);
void func_800093FC(omObjData*, f32, f32, f32);
void func_8001E268(s16 index, u8 arg1, u8 arg2);
void func_8001E2A8(s16, u16);
u16 func_8001E1D0(s16 index, s32 arg1);
s32 func_80018490(omObjData* obj, u16 motion);
f32 func_80025D18(s16);
f32 func_80025E70(s16);
f32 func_80029518(f32);
void func_80060F04(s16, s16, s16, s16);
void func_80066DF4(s16 grpIdx, s16 idx, s16 camIdx, f32 x, f32 y, f32 z);
void func_80067284(s16 grpIdx, s16 idx, f32 speed);

extern f32 D_800B895C; /* src/1130.c */
extern u8 D_800C5982;
extern omObjData* D_800EDE70[]; /* src/1130.c's collision list, D_800EE984 entries */
extern u16 D_800EE984;
extern omObjData* D_800F2AF8[];
extern u8 D_800F64F8;

/* ---------------------------------------------------------------------------------------------
   Overlay functions
   --------------------------------------------------------------------------------------------- */
/* 166220 */
void func_800F65E0_BoxMountainMayhem(void);
void func_800F67C0_BoxMountainMayhem(omObjData* obj);
void func_800F67F4_BoxMountainMayhem(omObjData* obj);
void func_800F691C_BoxMountainMayhem(void);
void func_800F6A00_BoxMountainMayhem(void);
void func_800F6ECC_BoxMountainMayhem(void);
void func_800F70C0_BoxMountainMayhem(omObjData* obj);
/* 166D50 */
void func_800F7110_BoxMountainMayhem(void);
void func_800F719C_BoxMountainMayhem(omObjData* obj);
void func_800F739C_BoxMountainMayhem(omObjData* obj, BMMBodyWork* work, BMMBoxExt* ext);
void func_800F76F4_BoxMountainMayhem(f32 x, f32 y, f32 z, s32 count);
void func_800F77C8_BoxMountainMayhem(omObjData* obj);
void func_800F79F4_BoxMountainMayhem(omObjData* obj);
void func_800F7C30_BoxMountainMayhem(Vec* pos, omObjData* player, s8 count);
void func_800F7E70_BoxMountainMayhem(void);
void func_800F80A0_BoxMountainMayhem(omObjData* obj);
void func_800F8350_BoxMountainMayhem(omObjData* obj, Vec* pos, f32 angle);
s32 func_800F8400_BoxMountainMayhem(Vec* from, Vec* out, f32* dist);
s32 func_800F84D0_BoxMountainMayhem(void);
f32 func_800F8548_BoxMountainMayhem(omObjData* obj, Vec* pos, f32 radius, s32* hit);
void func_800F8C94_BoxMountainMayhem(omObjData* obj);
/* 168CA0 */
void func_800F9060_BoxMountainMayhem(void);
void func_800F9068_BoxMountainMayhem(void);
void func_800F90A8_BoxMountainMayhem(omObjData* obj);
void func_800F918C_BoxMountainMayhem(omObjData* obj);
void func_800F935C_BoxMountainMayhem(omObjData* obj);
void func_800F96A4_BoxMountainMayhem(u8 x, u8 z, u8 depth);
void func_800F9840_BoxMountainMayhem(void);
void func_800F9C20_BoxMountainMayhem(omObjData* stack, s32 x, s32 level, s32 z, Vec* pos, omObjData* player);
s32 func_800FA058_BoxMountainMayhem(omObjData* obj);
s32 func_800FA2A0_BoxMountainMayhem(void);
s32 func_800FA2FC_BoxMountainMayhem(Vec* from, Vec* out, f32* dist);
void func_800FA3F0_BoxMountainMayhem(void);
void func_800FA498_BoxMountainMayhem(omObjData* obj);
s16 func_800FAB1C_BoxMountainMayhem(s16 model, s32 mask);
void func_800FAB60_BoxMountainMayhem(omObjData* obj, BMMPlayerWork* work, BMMPlayerExt* ext);
void func_800FAD84_BoxMountainMayhem(omObjData* obj);
void func_800FAF84_BoxMountainMayhem(omObjData* player);
f32 func_800FAF98_BoxMountainMayhem(Vec* from, Vec* to);
f32 func_800FAFC8_BoxMountainMayhem(BMMPlayerWork* work, Vec* from, Vec* to, f32 dist, u16* buttons);
void func_800FB1BC_BoxMountainMayhem(omObjData* obj);
void func_800FB440_BoxMountainMayhem(f32 zoom, f32 rotX, f32 rotY, f32 rotZ, f32 x, f32 y, f32 z);
f32 func_800FB4E8_BoxMountainMayhem(f32 dist);
f32 func_800FB598_BoxMountainMayhem(void);
void func_800FB788_BoxMountainMayhem(void);
void func_800FB9B4_BoxMountainMayhem(void);
u32 func_800FBC58_BoxMountainMayhem(u32 param);
u32 func_800FBD2C_BoxMountainMayhem(void);
void func_800FBD54_BoxMountainMayhem(s8 port);
void func_800FBE9C_BoxMountainMayhem(omObjData* obj, s32 file, u16 arg2, u8 arg3, s16 slot, s16* shared);

/* ---------------------------------------------------------------------------------------------
   .data
   --------------------------------------------------------------------------------------------- */
extern u16 D_800FBFC0_BoxMountainMayhem; /* 166220: 1 = leave the minigame */
extern s32 D_800FBFD0_BoxMountainMayhem; /* 166D50: last coin collision flags */
/* 168CA0 */
extern u8 D_800FBFE0_BoxMountainMayhem[16];
extern f32 D_800FBFF0_BoxMountainMayhem[4][2];
extern u8 D_800FC010_BoxMountainMayhem[16];
extern f32 D_800FC020_BoxMountainMayhem;
extern f32 D_800FC024_BoxMountainMayhem[16];
extern u8 D_800FC064_BoxMountainMayhem[6][2];
extern f32 D_800FC070_BoxMountainMayhem[6];
extern u32 D_800FC088_BoxMountainMayhem;

/* ---------------------------------------------------------------------------------------------
   .bss (ovl_17_bss.bss.s, 0x800FC0E0..0x800FC290)
   --------------------------------------------------------------------------------------------- */
extern u16 D_800FC0E0_BoxMountainMayhem; /* main state */
extern u16 D_800FC0E2_BoxMountainMayhem; /* intro state */
extern u16 D_800FC0E4_BoxMountainMayhem; /* end state */
extern u16 D_800FC0E6_BoxMountainMayhem; /* seconds left */
extern u16 D_800FC0E8_BoxMountainMayhem; /* frames to the next second */
extern u16 D_800FC0EA_BoxMountainMayhem;
extern s32 D_800FC0EC_BoxMountainMayhem;
extern s16 D_800FC0F0_BoxMountainMayhem; /* timer window */
extern s16 D_800FC100_BoxMountainMayhem;
extern s32 D_800FC110_BoxMountainMayhem; /* coins created */
extern s16 D_800FC118_BoxMountainMayhem[12]; /* coin values */
extern s16 D_800FC130_BoxMountainMayhem;
extern u8 D_800FC138_BoxMountainMayhem[4][4][5]; /* [z][x]: level count, then contents */
extern u8 D_800FC188_BoxMountainMayhem[16][2]; /* stack n's (x, z) */
extern s16 D_800FC1A8_BoxMountainMayhem; /* shared box model, -1 = not loaded */
extern s32 D_800FC1AC_BoxMountainMayhem; /* stacks created */
extern s32 D_800FC1B0_BoxMountainMayhem; /* stacks set up */
extern s16 D_800FC1C0_BoxMountainMayhem; /* players created */
extern s16 D_800FC1C2_BoxMountainMayhem[6]; /* shared player models, [0] -1 = not loaded */
extern f32 D_800FC1D0_BoxMountainMayhem; /* camera zoom */
extern omObjData* D_800FC1E0_BoxMountainMayhem[4]; /* thrown boxes */
extern s16 D_800FC1F0_BoxMountainMayhem; /* particle texture */
extern omObjData* D_800FC1F8_BoxMountainMayhem[4][4]; /* box stacks, [z][x] */
extern s16 D_800FC238_BoxMountainMayhem[3]; /* shared sprites, -1 = not loaded */
extern omObjData* D_800FC240_BoxMountainMayhem; /* stage */
extern s16 D_800FC244_BoxMountainMayhem; /* shared shadow model, -1 = not loaded */
extern omObjData* D_800FC248_BoxMountainMayhem[12]; /* coins */
extern omObjData* D_800FC278_BoxMountainMayhem[4]; /* players */
extern s16 D_800FC288_BoxMountainMayhem; /* coins thrown out */

#endif
