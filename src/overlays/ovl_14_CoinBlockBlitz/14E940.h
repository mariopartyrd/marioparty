#ifndef COINBLOCKBLITZ_H
#define COINBLOCKBLITZ_H

/* ovl_14 CoinBlockBlitz: declarations shared by its units (14E940, 150E30).
   Types come from the asm's accesses. N64 offsets are in the comments. Work blocks that hold a
   pointer are allocated with sizeof (the host strides pointers 8 bytes). */

#include "common.h"
#include "engine/pad.h"

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* Per-player CPU/input state (D_800FAA80[4]). unkC/unkE are the CPU's stick (only their low
   bytes reach ContStkX/Y); unk14..unk1A save the real pad state around func_80005A28. */
typedef struct unkCoinBlockBlitzStruct1 {
/* 0x00 */ u16 unk0; /* flags: 1 CPU, 2 retargeted once */
/* 0x02 */ u16 unk2; /* CPU state */
/* 0x04 */ u16 unk4; /* CPU difficulty */
/* 0x06 */ u16 unk6; /* jumps left on the current block */
/* 0x08 */ s16 unk8; /* target block (D_800FA950 index), -1 none */
/* 0x0A */ u16 unkA; /* frames until the next jump */
/* 0x0C */ s16 unkC; /* stick x */
/* 0x0E */ s16 unkE; /* stick y */
/* 0x10 */ u16 unk10; /* buttons pressed */
/* 0x12 */ u16 unk12; /* buttons held */
/* 0x14 */ s16 unk14; /* saved ContStkX */
/* 0x16 */ s16 unk16; /* saved ContStkY */
/* 0x18 */ u16 unk18; /* saved ContBtnTrg */
/* 0x1A */ u16 unk1A; /* saved ContBtn */
} unkCoinBlockBlitzStruct1; //sizeof 0x1C

/* D_800FA8F0[4] (func_800F6D08 only). */
typedef struct unkCoinBlockBlitzStruct2 {
s32 unk0;
s32 unk4;
s16 unk8;
s16 unkA;
s16 unkC;
s16 unkE;
s16 unk10;
s16 unk12;
} unkCoinBlockBlitzStruct2;

/* One coin block (D_800FA950[9]). */
typedef struct BlockData {
    /* 0x00 */ omObjData* block;
    /* 0x04 */ u16 timerType; /* 0 timed, 1 short timer, 2 one hit */
    /* 0x06 */ u16 timerDuration;
    /* 0x08 */ u16 unk_08; /* frames before it drops in */
    /* 0x0A */ u16 unk_0A; /* state: 1 waiting, 2 bouncing, 3/4 spent */
    /* 0x0C */ f32 unk_0C; /* bounce height */
    /* 0x10 */ f32 unk_10; /* bounce speed */
    /* 0x14 */ f32 unk_14; /* fall speed */
    /* 0x18 */ f32 unk_18; /* gravity */
    /* 0x1C */ f32 unk_1C;
} BlockData; // sizeof 0x20 (N64)

/* A coin of D_800FA898 (D_800EDE70's collision list): func_800F98F8. */
typedef struct CBBCoinSlot {
    /* 0x00 */ omObjData* obj;
    /* 0x04 */ char unk_04[4];
    /* 0x08 */ s32 unk_08; /* only sw $zero */
} CBBCoinSlot; /* size = 0xC (N64) */

/* The block and the stage work (func_800F93E0, func_800F9208): MgWork's first 0x2C bytes. */
typedef struct CBBStageWork {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk_06[0x26];
} CBBStageWork; /* size = 0x2C */

/* Work of the coins added to D_800EDE70 (func_800F98F8, func_80023684(0x6C)); src/1130.c's
   PlayerWork / KeyPaWay's KPWBodyWork layout. unk_21[slot] is the sprite of model[slot]
   (func_800F9838). */
typedef struct CBBCoinWork {
    /* 0x00 */ char unk_00[0x21];
    /* 0x21 */ u8 unk_21[4];
    /* 0x25 */ char unk_25[0xF];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38; /* vertical speed */
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ char unk_53;
    /* 0x54 */ u8 unk_54; /* 1 = flying */
    /* 0x55 */ u8 unk_55; /* sprite */
    /* 0x56 */ char unk_56[2];
    /* 0x58 */ f32 unk_58;
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ omObjData* unk_64; /* carrier (1130.c) */
    /* 0x68 */ void* unk_68;
} CBBCoinWork; /* size = 0x6C (N64) */

/* The four player objects' work (D_800F3FB0[i]->unk_50: func_8000979C allocates a MgWork, 0xE8).
   MgWork's layout (src/99E0.c) with the fields this overlay touches; its pointers sit where
   MgWork's do (0xB8, 0xD8, 0xDC, 0xE4). unk_21[slot] is the sprite of model[slot]. */
typedef struct CBBPlayerWork {
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
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ s8 unk_53;
    /* 0x54 */ s8 unk_54; /* rival player index, -1 none */
    /* 0x55 */ u8 unk_55;
    /* 0x56 */ s8 unk_56; /* controller port */
    /* 0x57 */ u8 unk_57;
    /* 0x58 */ s8 unk_58; /* player index */
    /* 0x59 */ char unk_59[3];
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ char unk_60[0x53];
    /* 0xB3 */ s8 unk_B3; /* sound handle (func_8006071C) */
    /* 0xB4 */ char unk_B4[4];
    /* 0xB8 */ omObjData* unk_B8;
    /* 0xBC */ char unk_BC[0x1C];
    /* 0xD8 */ void* unk_D8;
    /* 0xDC */ void* unk_DC;
    /* 0xE0 */ char unk_E0[4];
    /* 0xE4 */ void* unk_E4;
} CBBPlayerWork; /* size = 0xE8 (N64) */

/* ---------------------------------------------------------------------------------------------
   Main-code declarations missing from include/
   --------------------------------------------------------------------------------------------- */
void func_800090C4(omObjData* obj, u8 idx, u8 val);
void func_800090D8(omObjData*, u8, u8);
s32 func_80017A60(omObjData* obj);
void func_80017C0C(omObjData*, u8, f32, f32, f32, f32, f32);
void func_8001E268(s16 index, u8 arg1, u8 arg2);
void func_8001E2A8(s16, u16);
f32 func_80029518(f32);

extern f32 D_800B8964; /* src/1130.c */
extern f32 D_800B8968;
extern f32 D_800B8984;
extern f32 D_800B8990;
extern omObjData* D_800EDE70[]; /* src/1130.c's collision list, D_800EE984 entries */
extern u16 D_800EE984;
extern omObjData* D_800F2AF8[];
extern f32 D_800ED6B8;
extern f32 D_800F5254;

/* ---------------------------------------------------------------------------------------------
   Overlay functions
   --------------------------------------------------------------------------------------------- */
/* 14E940 */
void func_800F65E0_CoinBlockBlitz(void);
void func_800F6CB4_CoinBlockBlitz(omObjData*);
void func_800F6D08_CoinBlockBlitz(void);
void func_800F6E1C_CoinBlockBlitz(void);
void func_800F6F1C_CoinBlockBlitz(void);
void func_800F6F24_CoinBlockBlitz(omObjData* obj, f32 scale, f32 y, s32 idx);
void func_800F6FA8_CoinBlockBlitz(omObjData* obj);
u16 func_800F700C_CoinBlockBlitz(s32 block);
u16 func_800F702C_CoinBlockBlitz(s32 block, s32 player, f32 dist);
s16 func_800F713C_CoinBlockBlitz(omObjData* obj, s32 skip, s32 difficulty);
s32 func_800F73F4_CoinBlockBlitz(u16 player);
f32 func_800F745C_CoinBlockBlitz(omObjData* obj, omObjData* block);
void func_800F7604_CoinBlockBlitz(omObjData* obj);
void func_800F7B00_CoinBlockBlitz(s32 player);
u16 func_800F7C30_CoinBlockBlitz(omObjData* from, omObjData* player, s32 unused);
void func_800F7D98_CoinBlockBlitz(omObjData* coin, Vec3f* pos);
void func_800F7E5C_CoinBlockBlitz(void);
void func_800F7EE8_CoinBlockBlitz(omObjData* obj);
void func_800F81F0_CoinBlockBlitz(omObjData* obj);
void func_800F83A8_CoinBlockBlitz(omObjData* obj);
void func_800F859C_CoinBlockBlitz(omObjData* block);
void func_800F8614_CoinBlockBlitz(omObjData* block, omObjData* player, BlockData* data);
void func_800F86F4_CoinBlockBlitz(omObjData* obj);
/* 150E30 */
s32 func_800F8AD0_CoinBlockBlitz(void);
void func_800F8B18_CoinBlockBlitz(void);
void func_800F8BE4_CoinBlockBlitz(omObjData*);
void func_800F9208_CoinBlockBlitz(omObjData*);
void func_800F92A0_CoinBlockBlitz(omObjData*);
void func_800F93E0_CoinBlockBlitz(omObjData* block, Vec* position, s32 blockIndex, s16 arg3);
u16 func_800F9754_CoinBlockBlitz(s32 file, s32 arg1, s32 arg2, u16 shared);
void func_800F9838_CoinBlockBlitz(omObjData* obj, u8 slot, s32 file, s32 arg3, s32 arg4, u16 shared);
void func_800F98F8_CoinBlockBlitz(omObjData* obj, s32 file, s32 arg2, Vec3f* pos, s32 index);
void func_800F9BCC_CoinBlockBlitz(omObjData* obj, s32 arg1, s32 arg2, u16 player, Vec3f* pos, u16 arg5);
void func_800F9FB8_CoinBlockBlitz(omObjData*);
void func_800FA068_CoinBlockBlitz(omObjData*);
void func_800FA118_CoinBlockBlitz(omObjData*);
void func_800FA1C8_CoinBlockBlitz(omObjData*);
void func_800FA278_CoinBlockBlitz(omObjData*);
void func_800FA2D0_CoinBlockBlitz(omObjData*);
void func_800FA32C_CoinBlockBlitz(omObjData*);
void func_800FA388_CoinBlockBlitz(omObjData*);
void func_800FA3E4_CoinBlockBlitz(omObjData*);
void func_800FA440_CoinBlockBlitz(omObjData*);
void func_800FA49C_CoinBlockBlitz(omObjData*);
void func_800FA500_CoinBlockBlitz(omObjData*);
void func_800FA554_CoinBlockBlitz(omObjData*);
void func_800FA5A8_CoinBlockBlitz(omObjData*);
void func_800FA5FC_CoinBlockBlitz(omObjData*);
void func_800FA65C_CoinBlockBlitz(omObjData*);
void func_800FA6B0_CoinBlockBlitz(omObjData*);
void func_800FA704_CoinBlockBlitz(omObjData*);
void func_800FA758_CoinBlockBlitz(omObjData*);

/* ---------------------------------------------------------------------------------------------
   .data (14E940.c)
   --------------------------------------------------------------------------------------------- */
extern f32 D_800FA7C0_CoinBlockBlitz[4][2]; /* (x, z) per quadrant (func_800F7EE8) */
extern s32 D_800FA7E4_CoinBlockBlitz; /* func_800F8BE4 intro state */
extern s32 D_800FA7E8_CoinBlockBlitz; /* intro delay */
extern u32 D_800FA7EC_CoinBlockBlitz; /* game timer (frames) */
extern u32 D_800FA7F0_CoinBlockBlitz;
extern s32 D_800FA7F4_CoinBlockBlitz;
extern s32 D_800FA7F8_CoinBlockBlitz;
extern s32 D_800FA7FC_CoinBlockBlitz;
extern u16 D_800FA800_CoinBlockBlitz;
extern s32 D_800FA804_CoinBlockBlitz; /* shared block models (0x80 = not loaded) */
extern s32 D_800FA808_CoinBlockBlitz;
extern s32 D_800FA80C_CoinBlockBlitz[]; /* block timer-type weights, -1 terminated */
extern u16 D_800FA81C_CoinBlockBlitz; /* coins created */
extern s16 D_800FA81E_CoinBlockBlitz; /* shared coin sprite image, -1 = not loaded */
extern u16 D_800FA820_CoinBlockBlitz; /* players created */
extern Vec3f D_800FA824_CoinBlockBlitz[5]; /* player start positions */

/* ---------------------------------------------------------------------------------------------
   .bss (ovl_14_bss.bss.s, 0x800FA880..0x800FAAF0)
   --------------------------------------------------------------------------------------------- */
extern u16 D_800FA880_CoinBlockBlitz;
extern u16 D_800FA882_CoinBlockBlitz; /* shared sprite image (func_800F9754) */
extern CBBCoinSlot D_800FA898_CoinBlockBlitz[6];
extern u16 D_800FA8E0_CoinBlockBlitz[8]; /* [1..4]: start position per player */
extern unkCoinBlockBlitzStruct2 D_800FA8F0_CoinBlockBlitz[4];
extern u16 D_800FA94C_CoinBlockBlitz; /* result: 1 all blocks spent, 2 time up */
extern BlockData D_800FA950_CoinBlockBlitz[9];
extern s16 D_800FAA78_CoinBlockBlitz;
extern unkCoinBlockBlitzStruct1 D_800FAA80_CoinBlockBlitz[4];

#endif
