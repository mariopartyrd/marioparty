#ifndef BASHNCASH_H
#define BASHNCASH_H

/* ovl_10 BashNCash (1 vs 3): one unit, 137050.c. The solo player wears the coin suit (the
   "cash" player, D_800FE690_BashNCash.obj); the other three hit it with hammers to knock coins
   out. Types come from the asm's accesses; N64 offsets are in the comments. */

#include "common.h"

/* Per-player controller snapshot and CPU input (D_800FE6A8_BashNCash[4]); no pointers. */
typedef struct BashInput {
    /* 0x00 */ u16 flags; /* 1: CPU */
    /* 0x02 */ u16 state; /* CPU state */
    /* 0x04 */ s16 difficulty;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ u16 timer;
    /* 0x0A */ s16 stickX; /* CPU stick (stored to ContStkX as its low byte) */
    /* 0x0C */ s16 stickY;
    /* 0x0E */ u16 trg;
    /* 0x10 */ u16 btn;
    /* 0x12 */ s16 saveStkX; /* the real pad, restored after the player's update */
    /* 0x14 */ s16 saveStkY;
    /* 0x16 */ u16 saveTrg;
    /* 0x18 */ u16 saveBtn;
} BashInput; /* size = 0x1A */

/* Per hammer player (D_800FE710_BashNCash[4], indexed by player). */
typedef struct BashPlayer {
    /* 0x00 */ omObjData* obj;
    /* 0x04 */ u16 unk_04; /* hammer swing frame counter */
    /* 0x06 */ u16 unk_06; /* swing cooldown */
    /* 0x08 */ u16 unk_08; /* swing timer */
    /* 0x0A */ u16 unk_0A; /* spin frames (stunned) */
    /* 0x0C */ u16 unk_0C;
    /* 0x0E */ u16 cpu;    /* CPU routine (D_800FE458_BashNCash index) */
    /* 0x10 */ u32 unk_10; /* flags */
} BashPlayer; /* size = 0x14 (N64) */

/* The cash player (D_800FE690_BashNCash). */
typedef struct BashCash {
    /* 0x00 */ omObjData* obj;
    /* 0x04 */ u16 unk_04; /* jump timer */
    /* 0x06 */ u16 unk_06; /* hit cooldown */
    /* 0x08 */ u16 coins;  /* coins left in the suit */
    /* 0x0A */ u16 unk_0A;
    /* 0x0C */ u16 order[4]; /* [0] the cash player, [1..3] the others in random order */
} BashCash; /* size = 0x14 (N64) */

/* Retail also reaches BashCash::coins through its own label. */
extern u16 D_800FE698_BashNCash;

/* A coin knocked out of the suit (D_800FE630_BashNCash[8]). */
typedef struct BashCoinSlot {
    /* 0x00 */ omObjData* obj;
    /* 0x04 */ u16 timer;
    /* 0x08 */ s32 unk_08;
} BashCoinSlot; /* size = 0xC (N64) */

/* A player's work (obj->unk_50, allocated by func_8000979C): MgWork's layout (src/99E0.c, 0xE8);
   its pointers sit where MgWork's do. */
typedef struct BashPlayerWork {
    /* 0x00 */ char unk_00[0x2C];
    /* 0x2C */ u8 unk_2C; /* func_80009340 slot 0xB's byte */
    /* 0x2D */ char unk_2D[0xB];
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C; /* facing */
    /* 0x40 */ f32 unk_40; /* speed */
    /* 0x44 */ char unk_44[4];
    /* 0x48 */ f32 unk_48; /* radius */
    /* 0x4C */ char unk_4C[4];
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ char unk_53;
    /* 0x54 */ s8 unk_54; /* CPU target */
    /* 0x55 */ char unk_55;
    /* 0x56 */ u8 unk_56; /* controller port */
    /* 0x57 */ char unk_57;
    /* 0x58 */ s8 unk_58; /* player */
    /* 0x59 */ char unk_59[0x43];
    /* 0x9C */ u16 unk_9C;
    /* 0x9E */ char unk_9E[6];
    /* 0xA4 */ f32 unk_A4;
    /* 0xA8 */ char unk_A8[0x10];
    /* 0xB8 */ void* unk_B8;
    /* 0xBC */ char unk_BC[0x1C];
    /* 0xD8 */ void* unk_D8; /* motion table */
    /* 0xDC */ void* unk_DC; /* collision callback */
    /* 0xE0 */ char unk_E0[4];
    /* 0xE4 */ void* unk_E4;
} BashPlayerWork; /* size = 0xE8 (N64) */

/* A coin's work (func_80023684(0x6C)): src/1130.c's PlayerWork prefix, no pointers. */
typedef struct BashCoinWork {
    /* 0x00 */ char unk_00[0x24];
    /* 0x24 */ u8 unk_24; /* func_80009340 slot 3's byte */
    /* 0x25 */ char unk_25[0xF];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38; /* vertical speed; 1000 on the ground */
    /* 0x3C */ f32 unk_3C; /* direction */
    /* 0x40 */ f32 unk_40; /* speed */
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48; /* radius */
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ u8 unk_52; /* coin value */
    /* 0x53 */ u8 unk_53;
    /* 0x54 */ u8 unk_54; /* in flight */
    /* 0x55 */ char unk_55[3];
    /* 0x58 */ f32 unk_58;
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ s32 unk_60;
    /* 0x64 */ char unk_64[8];
} BashCoinWork; /* size = 0x6C */

/* A collision vertex (D_800F2B7C[mdl].unk_6C->unk_78). */
typedef struct BashColVtx {
    s16 x;
    s16 y;
    s16 z;
} BashColVtx;

/* The control object's work (func_80023684(0x2C)). */
typedef struct BashCtrlWork {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk_06[0x26];
} BashCtrlWork; /* size = 0x2C */

/* ---------------------------------------------------------------------------------------------
   Main code
   --------------------------------------------------------------------------------------------- */

extern omObjData* D_800EDE70[]; /* src/1130.c's collision list, D_800EE984 entries */
extern omObjData* D_800F2AF8[];
extern u16 D_800EE984;
extern u16 ContBtn[];
extern s8 ContStkY[];
extern u16 D_800B89A4[][14];
extern u8 D_800B8954;
extern s16 D_800B8956;
extern f32 D_800B8964;
extern f32 D_800B8968;
extern f32 D_800B8984;
extern f32 D_800B8988;
extern f32 D_800ED6B8;
extern f32 D_800F5254;

f32 func_80029518(f32);
s32 func_80017A60(omObjData*);
void func_80060F04(s16, s16, s16, s16);
void func_80017C0C(omObjData*, u8, f32, f32, f32, f32, f32);
f32 func_80002C48(omObjData*, f32, f32, f32, f32);
void func_80018450(omObjData*, s32);
void func_8001E2A8(s16, u16);
void func_8001E268(s16, u8, u8);
void func_800090D8(omObjData*, u8, u8);
void func_80028498(s16, s16, s16);
void func_800284E4(s16);
void func_8002956C(Vec3f*);
s32 func_80004D1C(omObjData*, Vec4f*, f32);
void func_8002AE24(s16, s32*, void*, void*);
u16* func_8002B3A8(s32*);
f32 func_80029764(f32, f32, f32, void*, u16*);
void func_800295FC(void*, void*, void*, Vec3f*);
f32 func_800051D4(omObjData*, f32, f32, f32, Vec3f*);
void func_800091BC(omObjData*, s32, s32, s32);
void func_800090C4(omObjData* obj, u8 idx, u8 val);
void func_80008FDC(omObjData*, f32);
void func_80008FE8(omObjData*, f32);
void func_80020EA0(s16, char*, s16, char*);
void func_8002859C(s16, s16, char*);
void func_80018E0C(u16, s16);
s32 func_80002060(void*, s16*, void*, Vec3f*);
s32 func_80002080(void*, s16*, void*, void*);

/* ---------------------------------------------------------------------------------------------
   Overlay functions
   --------------------------------------------------------------------------------------------- */

void func_800F65E0_BashNCash(void);
void func_800F6B80_BashNCash(omObjData* obj);
void func_800F6BCC_BashNCash(void);
void func_800F6D20_BashNCash(omObjData* obj);
void func_800F6D6C_BashNCash(void);
void func_800F6EA0_BashNCash(omObjData* obj, u8 arg1, u32 frames);
void func_800F6EE0_BashNCash(void);
void func_800F6EE8_BashNCash(omObjData* obj, f32 scale, f32 y, s32 mdl);
void func_800F6F6C_BashNCash(omObjData* obj);
u16 func_800F6FD0_BashNCash(omObjData* obj, omObjData* target, Vec3f* ofs);
void func_800F7108_BashNCash(f32* a, f32* b);
void func_800F711C_BashNCash(f32* dist, f32* angle);
f32 func_800F7240_BashNCash(f32* angle);
omObjData* func_800F72BC_BashNCash(omObjData* obj);
s32 func_800F73F0_BashNCash(u16 player);
void func_800F7458_BashNCash(omObjData* obj);
void func_800F7A54_BashNCash(omObjData* obj);
void func_800F8240_BashNCash(omObjData* obj);
void func_800F875C_BashNCash(omObjData* obj);
void func_800F8FD4_BashNCash(omObjData* obj);
u16 func_800F99A8_BashNCash(omObjData* cash, omObjData* hitter, s32 type);
s32 func_800F9BAC_BashNCash(void);
void func_800F9BDC_BashNCash(omObjData* cash, omObjData* hitter);
void func_800F9D60_BashNCash(omObjData* obj);
void func_800F9DD0_BashNCash(omObjData* obj);
s32 func_800F9F64_BashNCash(void);
void func_800F9FD0_BashNCash(omObjData* obj, Vec3f* pos);
void func_800FA094_BashNCash(void);
void func_800FA120_BashNCash(omObjData* obj);
void func_800FA26C_BashNCash(omObjData* obj);
void func_800FA440_BashNCash(omObjData* obj);
void func_800FA5B4_BashNCash(omObjData* obj);
void func_800FAAE4_BashNCash(omObjData* obj);
void func_800FB0D8_BashNCash(omObjData* obj);
void func_800FB1D4_BashNCash(void);
void func_800FB240_BashNCash(omObjData* obj);
void func_800FB928_BashNCash(omObjData* obj);
void func_800FB940_BashNCash(omObjData* obj, Vec3f* pos);
f32 func_800FBAB8_BashNCash(omObjData* obj, f32 x, f32 y, f32 z, Vec3f* normal);
void func_800FBCC8_BashNCash(omObjData* obj);
void func_800FC240_BashNCash(void);
void func_800FC840_BashNCash(omObjData* obj);
void func_800FC904_BashNCash(omObjData* obj);
void func_800FC9D4_BashNCash(omObjData* obj, s32 file, s8 value, Vec3f* pos, s32 slot);
void func_800FCBA8_BashNCash(omObjData* obj);
void func_800FCC00_BashNCash(omObjData* obj);
void func_800FCC5C_BashNCash(omObjData* obj);
void func_800FCCB8_BashNCash(omObjData* obj);
void func_800FCD14_BashNCash(omObjData* obj);
void func_800FCD70_BashNCash(omObjData* obj);
void func_800FCDCC_BashNCash(omObjData* obj);
void func_800FCE28_BashNCash(omObjData* obj);
s32 func_800FCE84_BashNCash(void);
void func_800FCE8C_BashNCash(omObjData* obj, s32 dir, s32 file, u16 player, Vec3f* pos, u16 chr);
void func_800FD2B0_BashNCash(omObjData* obj, s32 dir, s32 file, u16 player, Vec3f* pos);
void func_800FD748_BashNCash(s32 player, s32 coins);
void func_800FD774_BashNCash(void);
void func_800FD830_BashNCash(void);
void func_800FD8E8_BashNCash(omObjData* obj);
void func_800FDBB4_BashNCash(omObjData* obj);
u16 func_800FDED0_BashNCash(void);
void func_800FDF20_BashNCash(omObjData* obj);
void func_800FE038_BashNCash(omObjData* obj);
void func_800FE158_BashNCash(omObjData* obj);
void func_800FE278_BashNCash(omObjData* obj);

#endif
