#ifndef BOMBSAWAY_H
#define BOMBSAWAY_H

/* ovl_22 BombsAway: declarations for its units (1AA2A0.c, 1AF980.c, 1B02A0.c).
   Types come from the asm's accesses; N64 offsets are in the comments. A struct with no pointers
   has the same layout on the host. Records with pointers are reached through their fields only
   (never a literal stride): the host strides pointers 8 bytes. */

#include "common.h"

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* D_80100140: the game state. Retail reaches unk_04/unk_06 through the labels D_80100144 and
   D_80100146; field accesses relocate against D_80100140+4/+6 (same address). */
typedef struct BaGame {
    /* 0x00 */ s16 unk_00; /* state: 0 intro, 1 play, 2 finish, 3 results */
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04; /* frames in the state (wraps below 0x7800; func_800F6B98) */
    /* 0x06 */ s16 unk_06; /* time left in frames (900 at start) */
} BaGame; /* size = 0x8 */

/* D_80100150[4]: one per player, 0x70 each (zeroed with func_8009B770(.., 0x70)). Splat labels
   inside: D_80100152 (= [0].unk_02, lh), D_80100198 (= [0].unk_48, lw). unk_48 is a pointer, so
   the host record is larger: index the array, never step 0x70. Flags unk_00: 1 set up,
   2 fallen off, 0x10 ?, 0x80 first frame done. States unk_02: 3 stunned (sparkles), 5 falling,
   7 out, 9 hit by a shock wave. */
typedef struct BaPlayer {
    /* 0x00 */ u16 unk_00; /* flags */
    /* 0x02 */ s16 unk_02; /* state */
    /* 0x04 */ char unk_04;
    /* 0x05 */ u8 unk_05; /* 1: scripted (func_800F8D48), 0: player/CPU control (func_800F8538) */
    /* 0x06 */ u8 unk_06; /* player index (stored with sb from an s16) */
    /* 0x07 */ char unk_07;
    /* 0x08 */ f32 unk_08; /* radius (50.0) */
    /* 0x0C */ f32 unk_0C; /* velocity x */
    /* 0x10 */ f32 unk_10; /* velocity y */
    /* 0x14 */ f32 unk_14; /* velocity z */
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ char unk_24[0xC];
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ s16 unk_34; /* toggles 0/1: which of unk_36/unk_38 takes the next motion */
    /* 0x36 */ s16 unk_36; /* motion kept (func_800F791C/func_800F7A14) */
    /* 0x38 */ s16 unk_38; /* motion kept */
    /* 0x3A */ s16 unk_3A;
    /* 0x3C */ s16 unk_3C; /* frames in the state */
    /* 0x3E */ s16 unk_3E;
    /* 0x40 */ char unk_40[2];
    /* 0x42 */ s16 unk_42; /* 12 at setup */
    /* 0x44 */ s16 unk_44; /* -1 at setup */
    /* 0x46 */ char unk_46[2];
    /* 0x48 */ omObjData* unk_48; /* the player's object */
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ f32 unk_50;
    /* 0x54 */ s16 unk_54;
    /* 0x56 */ char unk_56[2];
    /* 0x58 */ f32 unk_58; /* CPU target x (D_80100360 + D_800FFA7C[unk_68][0]) */
    /* 0x5C */ f32 unk_5C;
    /* 0x60 */ f32 unk_60; /* CPU target z */
    /* 0x64 */ char unk_64[4];
    /* 0x68 */ s16 unk_68; /* corner slot (1..5, D_801004BE) */
    /* 0x6A */ s16 unk_6A;
    /* 0x6C */ char unk_6C[4];
} BaPlayer; /* size = 0x70 (N64) */

/* D_80100328: the tilting platform, 0x194 bytes (zeroed in func_800F65E0). Splat split it into
   labels; each is a field: D_80100344 (+0x1C), D_80100354 (+0x2C), D_80100358 (+0x30),
   D_8010035C (+0x34), D_80100360/64/68 (+0x38 pos), D_8010036C (+0x44 rot), D_801003B8 (+0x90),
   D_80100438/3C/40/44 (+0x110 plane), D_80100458 (+0x130). No pointers. */
typedef struct BaWeight {
    /* 0x00 */ f32 unk_00; /* x */
    /* 0x04 */ f32 unk_04; /* weight (func_800FADA8's third argument) */
    /* 0x08 */ f32 unk_08; /* z */
} BaWeight;

typedef struct BaStage {
    /* 0x000 */ f32 unk_00; /* bob angle (+2/frame) */
    /* 0x004 */ f32 unk_04; /* wobble angle (+2/frame) */
    /* 0x008 */ f32 unk_08; /* wobble angle (+1/frame) */
    /* 0x00C */ f32 unk_0C; /* tilt direction (degrees) */
    /* 0x010 */ f32 unk_10; /* tilt amount (0..1) */
    /* 0x014 */ f32 unk_14; /* hit direction */
    /* 0x018 */ f32 unk_18; /* hit wobble angle */
    /* 0x01C */ f32 unk_1C; /* hit strength */
    /* 0x020 */ f32 unk_20; /* hit sign (+1/-1) */
    /* 0x024 */ char unk_24[4];
    /* 0x028 */ f32 unk_28; /* shake */
    /* 0x02C */ s16 unk_2C; /* hit frames (15) */
    /* 0x02E */ char unk_2E[2];
    /* 0x030 */ f32 unk_30; /* surface height (160.0) */
    /* 0x034 */ f32 unk_34; /* slide factor (0.8) */
    /* 0x038 */ Vec unk_38; /* position (= the stage object's trans) */
    /* 0x044 */ Vec unk_44; /* rotation */
    /* 0x050 */ Matrix4f unk_50; /* platform matrix */
    /* 0x090 */ Matrix4f unk_90; /* its inverse */
    /* 0x0D0 */ Matrix4f unk_D0; /* last frame's inverse */
    /* 0x110 */ f32 unk_110[4]; /* surface plane a, b, c, d */
    /* 0x120 */ f32 unk_120; /* 1 / |normal| */
    /* 0x124 */ Vec unk_124; /* unit normal */
    /* 0x130 */ s32 unk_130; /* weights this frame */
    /* 0x134 */ BaWeight unk_134[8];
} BaStage; /* size = 0x194 */

/* D_801004E0: bomb-carrier slots (func_800FB0D0/func_800FB120/func_800FB19C). unk_00[i]: NULL
   free, (omObjData*)1 taken, else the player waiting; unk_10[i] (splat's D_801004F0): the player
   holding it. func_800FB19C addresses unk_10 from D_801004E0's base. */
typedef struct BaSlots {
    /* 0x00 */ omObjData* unk_00[4];
    /* 0x10 */ omObjData* unk_10[4];
} BaSlots; /* size = 0x20 (N64) */

/* D_80100500[8]: shock waves (func_800F7850 adds, func_800F7604 ages). */
typedef struct BaShock {
    /* 0x00 */ s16 unk_00; /* frames left, 0 = free */
    /* 0x02 */ char unk_02[2];
    /* 0x04 */ f32 unk_04; /* x */
    /* 0x08 */ f32 unk_08; /* y */
    /* 0x0C */ f32 unk_0C; /* z */
    /* 0x10 */ f32 unk_10; /* radius */
} BaShock; /* size = 0x14 */

/* D_801005A0[12]: stun sparkles, three per player (func_800FB988; sprite group D_801006FC). */
typedef struct BaSparkle {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02; /* phase */
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
} BaSparkle; /* size = 0x14 */

/* D_80100698[8]: bomb landing marks (func_800F723C). */
typedef struct BaMark {
    /* 0x00 */ s16 unk_00; /* age, 0 = free */
    /* 0x02 */ s16 unk_02; /* frames to impact (60) */
    /* 0x04 */ f32 unk_04; /* x */
    /* 0x08 */ f32 unk_08; /* z */
} BaMark; /* size = 0xC */

/* D_80100790: the cannon (func_800FE254 sets it up). Splat labels: D_80100794 (+4), D_80100798
   (+8), D_8010079C (+0xC rot), D_801007A8 (+0x18), D_801007B8 (+0x28). No pointers. */
typedef struct BaCannon {
    /* 0x00 */ Vec unk_00; /* position (150, -50, -2250) */
    /* 0x0C */ Vec unk_0C; /* rotation (0, 50, 0) */
    /* 0x18 */ f32 unk_18; /* velocity (-3.5) */
    /* 0x1C */ char unk_1C[0xC];
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ char unk_2C[0x24];
} BaCannon; /* size = 0x50 (to D_801007E0) */

/* D_801007E0[4]: bombs in flight (func_800FE948 fires one). Splat label D_80100800 = [0].unk_20.
   Three pointers: index the array on the host. */
typedef struct BaBomb {
    /* 0x00 */ u16 unk_00; /* state (< 2 busy) */
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ u16 unk_04; /* kind (< 3) */
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ Vec* unk_08; /* &unk_20->unk_44 (rotation) */
    /* 0x0C */ Vec* unk_0C; /* &unk_20->unk_50 (scale) */
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14; /* target x */
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C; /* target z */
    /* 0x20 */ unk2C0C0Struct50* unk_20; /* the model node (func_800FBE34) */
} BaBomb; /* size = 0x24 (N64) */

/* D_80100870[6]: falling bombs (func_800FEA0C/func_800FECA8/func_800FEE2C). No pointers. */
typedef struct BaShell {
    /* 0x00 */ s16 unk_00; /* 0 free, 1 falling */
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ f32 unk_04; /* x */
    /* 0x08 */ f32 unk_08; /* y */
    /* 0x0C */ f32 unk_0C; /* z */
    /* 0x10 */ f32 unk_10; /* velocity x */
    /* 0x14 */ f32 unk_14; /* velocity y */
    /* 0x18 */ f32 unk_18; /* velocity z */
    /* 0x1C */ f32 unk_1C; /* target x */
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24; /* target z */
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C; /* scale */
} BaShell; /* size = 0x30 */

/* D_80100990[32]: effect sprites (func_800FDE38 makes one). Splat labels D_80100992/94/98 are
   [0]'s fields. No pointers. */
typedef struct BaEffect {
    /* 0x00 */ s16 unk_00; /* sprite group, -1 free */
    /* 0x02 */ s16 unk_02; /* frames to live */
    /* 0x04 */ u8 unk_04; /* kind (< 0x21) */
    /* 0x05 */ char unk_05[3];
    /* 0x08 */ f32 unk_08; /* scale */
} BaEffect; /* size = 0xC */

/* D_80100B44: func_80023684(n * 6), one per vertex of the water model (func_800FF218). */
typedef struct BaVtxMap {
    /* 0x00 */ s16 unk_00; /* 1 moves, 0 edge */
    /* 0x02 */ s16 unk_02; /* column */
    /* 0x04 */ s16 unk_04; /* row */
} BaVtxMap; /* size = 0x6 */

/* D_80100B70[6]: splashes (func_800FCD04). Two pointers: index the array on the host. */
typedef struct BaSplash {
    /* 0x00 */ s16 unk_00; /* model (func_80024198) */
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ f32 unk_04; /* life, <= 0 free */
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ Vec unk_0C; /* scale */
    /* 0x18 */ Vec unk_18; /* position */
    /* 0x24 */ Gfx* unk_24; /* display list, func_80023684(D_800F37DA * 0xA0) */
    /* 0x28 */ u8* unk_28; /* into D_80100B6C's file */
} BaSplash; /* size = 0x2C (N64) */

/* ---------------------------------------------------------------------------------------------
   Main-code declarations missing from (or wrong in) the shared headers for these units
   --------------------------------------------------------------------------------------------- */

s16 MtxInv(Matrix4f, Matrix4f);
void func_800090C4(omObjData* obj, u8 idx, u8 val);
u16 func_80017A50(omObjData* obj);
void func_8001802C(omObjData*);
s32 func_80018490(omObjData* obj, u8 motion); /* retail masks the argument with 0xFF (shared definition: u16) */
void func_80021E58(void);
void func_80021EC0(s16, f32, f32, f32);
s16 func_80024198(u32, Gfx*, s32);
void func_800607C4(s16, s16);
void func_80060F04(s16, s16, s16, s16);
void func_80066DF4(s16 grpIdx, s16 idx, s16 camIdx, f32 x, f32 y, f32 z);
void func_80067284(s16, s16, f32);
s32 func_8009B850(const void*, const void*);
void func_8009E060(Matrix4f, f32 angle, f32 x, f32 y, f32 z);
void func_800AC0B0(Matrix4f, Matrix4f, Matrix4f);

/* ---------------------------------------------------------------------------------------------
   Overlay data (1AA2A0.c, 1B02A0.c)
   --------------------------------------------------------------------------------------------- */

extern s16 D_800FFA70_BombsAway[6];
extern f32 D_800FFA7C_BombsAway[6][2]; /* asm also reads D_800FFA80 = [0][1] */
extern u8 D_800FFAAC_BombsAway[10][2]; /* asm also reads D_800FFAAD = [0][1] */
extern u16 D_800FFAC0_BombsAway;
extern u16 D_800FFAC2_BombsAway;
extern s16 D_800FFAC4_BombsAway;
extern Vec D_800FFAC8_BombsAway;
extern Vec D_800FFAD4_BombsAway;
extern Vtx D_800FFAE0_BombsAway[4];
extern u16 D_800FFB20_BombsAway;
extern u16 D_800FFB22_BombsAway;
extern f32 D_800FFB24_BombsAway;
extern f32 D_800FFB28_BombsAway;
extern s32 D_800FFB2C_BombsAway; /* random seed; retail returns its low half (lhu D_800FFB2E) */
extern u16 D_800FFB30_BombsAway;
extern u16 D_800FFB32_BombsAway;

/* ---------------------------------------------------------------------------------------------
   Overlay bss (ovl_22_bss, 0x80100140..0x80100C80)
   --------------------------------------------------------------------------------------------- */

extern BaGame D_80100140_BombsAway;
extern s16 D_80100148_BombsAway; /* _CheckFlag(0x2B) != 0 */
extern s16 D_8010014A_BombsAway;
extern BaPlayer D_80100150_BombsAway[4];
extern s32 D_80100310_BombsAway; /* players set up */
extern s32 D_80100314_BombsAway; /* players left */
extern s32 D_80100318_BombsAway; /* frames to the next bomb */
extern s32 D_8010031C_BombsAway;
extern s32 D_80100320_BombsAway;
extern s16 D_80100324_BombsAway; /* model */
extern BaStage D_80100328_BombsAway;
extern s16 D_801004BC_BombsAway;
extern s16 D_801004BE_BombsAway[6]; /* corner slots, bits 1/2 */
extern s16 D_801004D0_BombsAway[8]; /* models (func_800FAFB4) */
extern BaSlots D_801004E0_BombsAway;
extern BaShock D_80100500_BombsAway[8];
extern BaSparkle D_801005A0_BombsAway[12];
extern s16 D_80100690_BombsAway;
extern s16 D_80100692_BombsAway;
extern s16 D_80100694_BombsAway;
extern BaMark D_80100698_BombsAway[8];
extern s16 D_801006F8_BombsAway; /* newest mark, -1 none */
extern s16 D_801006FA_BombsAway;
extern s16 D_801006FC_BombsAway; /* sprite group (func_80064EF4(12, 0)) */
extern s16 D_80100700_BombsAway[9]; /* [3..5] = D_80100706: shared player motions */
extern Matrix4f D_80100720_BombsAway; /* camera look-at (func_800FC39C) */
extern f32 D_80100760_BombsAway;
extern f32 D_80100770_BombsAway;
/* Two s16 pairs (4 bytes each); retail addresses each half with its own lui/%lo, so they are
   scalars here with split labels for the second halves (D_80100776, D_8010077A). */
extern s16 D_80100774_BombsAway;
extern s16 D_80100778_BombsAway;
extern s16 D_8010077C_BombsAway;
extern s16 D_8010077E_BombsAway;
extern u8 D_80100780_BombsAway;
extern u16 D_80100782_BombsAway;
extern u16 D_80100784_BombsAway;
extern s16 D_80100786_BombsAway;
extern s16 D_80100788_BombsAway;
extern BaCannon D_80100790_BombsAway;
extern BaBomb D_801007E0_BombsAway[4];
extern BaShell D_80100870_BombsAway[6];
extern BaEffect D_80100990_BombsAway[32];
extern s16 D_80100B10_BombsAway[4]; /* images per effect kind ([1] and [3] = D_80100B12/B16) */
extern s16 D_80100B40_BombsAway; /* water model */
extern BaVtxMap* D_80100B44_BombsAway;
extern s32 D_80100B48_BombsAway[2];
extern s16 D_80100B50_BombsAway;
extern s16 D_80100B52_BombsAway[6];
extern s16 D_80100B5E_BombsAway[6];
extern s16 D_80100B6A_BombsAway;
extern void* D_80100B6C_BombsAway; /* DataRead(0x35000E) */
extern BaSplash D_80100B70_BombsAway[6];

/* Splat labels inside the objects above. Retail addresses these scalars with their own lui/%lo
   (no shared base register), which field access through the block may not reproduce: the N64
   build declares the labels (splat defines them in the bss), the host views the block. Record
   fields (D_80100152, D_80100504, ...) have no N64 declaration: index the record arrays. */
extern s16 D_80100144_BombsAway;
extern s16 D_80100146_BombsAway;
extern f32 D_80100344_BombsAway;
extern s16 D_80100354_BombsAway;
extern f32 D_80100358_BombsAway;
extern f32 D_8010035C_BombsAway;
extern Vec D_80100360_BombsAway;
extern f32 D_80100364_BombsAway;
extern f32 D_80100368_BombsAway;
extern Vec D_8010036C_BombsAway;
extern Matrix4f D_801003B8_BombsAway;
extern f32 D_80100438_BombsAway;
extern f32 D_8010043C_BombsAway;
extern f32 D_80100440_BombsAway;
extern f32 D_80100444_BombsAway;
extern s32 D_80100458_BombsAway;
extern omObjData* D_801004F0_BombsAway[4];
extern s16 D_80100706_BombsAway[3];
extern f32 D_80100794_BombsAway;
extern f32 D_80100798_BombsAway;
extern Vec D_8010079C_BombsAway;
extern f32 D_801007A8_BombsAway;
extern f32 D_801007B8_BombsAway;
extern s16 D_80100B12_BombsAway;
extern s16 D_80100776_BombsAway; /* undefined_syms.txt: D_80100774 + 2 */
extern s16 D_8010077A_BombsAway; /* undefined_syms.txt: D_80100778 + 2 */

/* ---------------------------------------------------------------------------------------------
   Functions
   --------------------------------------------------------------------------------------------- */

/* 1AA2A0.c */
void func_800F65E0_BombsAway(void);
void func_800F6B28_BombsAway(void);
void func_800F6B88_BombsAway(omObjData*);
void func_800F6B98_BombsAway(omObjData*);
void func_800F71E4_BombsAway(omObjData*);
void func_800F7218_BombsAway(void);
void func_800F723C_BombsAway(void);
void func_800F7604_BombsAway(void);
void func_800F7850_BombsAway(s16, f32, f32, f32, f32);
BaPlayer* func_800F78D4_BombsAway(omObjData*);
void func_800F791C_BombsAway(omObjData*, s32);
void func_800F7A14_BombsAway(omObjData*, s32, s32);
void func_800F7B00_BombsAway(void);
void func_800F7C24_BombsAway(omObjData*);
void func_800F7C40_BombsAway(omObjData*);
void func_800F7C5C_BombsAway(omObjData*);
void func_800F7C78_BombsAway(omObjData*);
void func_800F7C94_BombsAway(omObjData*);
void func_800F8100_BombsAway(omObjData*, s16);
void func_800F8538_BombsAway(omObjData*);
void func_800F8D48_BombsAway(omObjData*);
void func_800F9824_BombsAway(omObjData*);
void func_800F997C_BombsAway(omObjData*);
f32 func_800FA47C_BombsAway(Vec*);
f32 func_800FA4B4_BombsAway(Vec*);
s32 func_800FA514_BombsAway(Vec*, Vec*);
s32 func_800FA5D8_BombsAway(Vec*);
s32 func_800FA664_BombsAway(Vec*);
s32 func_800FA6FC_BombsAway(Vec*, Vec*);
s32 func_800FA7E8_BombsAway(Vec*, Vec*, Vec*, s16);
s32 func_800FAB74_BombsAway(Vec*, Vec*, Vec*);
void func_800FADA8_BombsAway(f32, f32, f32);
void func_800FADF4_BombsAway(f32, f32, f32);
void func_800FAFB4_BombsAway(void);
void func_800FB0D0_BombsAway(omObjData*);
s16 func_800FB120_BombsAway(void);
void func_800FB19C_BombsAway(s16);
void func_800FB1C4_BombsAway(omObjData*);
void func_800FB1E0_BombsAway(omObjData*);
void func_800FB1FC_BombsAway(omObjData*, u8);
void func_800FB2E4_BombsAway(omObjData*);
void func_800FB988_BombsAway(void);

/* 1AF980.c */
s16 func_800FBCC0_BombsAway(unk2C0C0StructC0*, const char*);
unk2C0C0Struct50* func_800FBD40_BombsAway(unk2C0C0StructC0*, s16, s32);
unk2C0C0Struct50* func_800FBE34_BombsAway(s16, const char*);
Vec3f* func_800FBEB0_BombsAway(s16, const char*);
Vec3f* func_800FBEDC_BombsAway(s16, const char*);
void func_800FBF08_BombsAway(s16, s16, s16, f32);
void func_800FBF9C_BombsAway(Matrix4f, f32, f32, f32, f32*);
void func_800FC038_BombsAway(Vec*);
f32 func_800FC0EC_BombsAway(f32, f32);
void func_800FC16C_BombsAway(Vec*, Vec*);
void func_800FC1F4_BombsAway(Matrix4f, Vec*);
void func_800FC39C_BombsAway(s16);
void func_800FC478_BombsAway(Vec*, Vec*);
void func_800FC530_BombsAway(s16, Vec*);

/* 1B02A0.c */
void func_800FC5E0_BombsAway(void);
void func_800FC7B0_BombsAway(omObjData*);
void func_800FC7C0_BombsAway(void);
void func_800FC7F4_BombsAway(void);
void func_800FC818_BombsAway(void);
void func_800FC88C_BombsAway(void);
void func_800FC8F8_BombsAway(omObjData*);
void func_800FCD04_BombsAway(void);
void func_800FCE0C_BombsAway(void);
void func_800FD364_BombsAway(f32, f32, f32, f32, f32, f32, u16);
void func_800FD428_BombsAway(void);
void func_800FD4B8_BombsAway(f32, f32, f32, f32);
void func_800FD530_BombsAway(void);
void func_800FD540_BombsAway(void);
void func_800FDB0C_BombsAway(omObjData*);
void func_800FDB78_BombsAway(omObjData*);
void func_800FDC6C_BombsAway(void);
void func_800FDCA0_BombsAway(void);
void func_800FDD58_BombsAway(void);
s16 func_800FDE38_BombsAway(s16, f32, f32, f32, f32, s16, f32);
u16 func_800FE1EC_BombsAway(u32);
void func_800FE254_BombsAway(omObjData*);
void func_800FE4A4_BombsAway(omObjData*);
s32 func_800FE948_BombsAway(f32, f32, f32, u16);
void func_800FEA0C_BombsAway(s32, f32, f32, f32, u16);
void func_800FECA8_BombsAway(u16, u16);
void func_800FED18_BombsAway(void);
void func_800FEE2C_BombsAway(void);
void func_800FF218_BombsAway(s16);
void func_800FF674_BombsAway(s16, s32, s16*);
void func_800FF9C4_BombsAway(s16*, u16);

#endif
