#ifndef COINBLOCKBASH_H
#define COINBLOCKBASH_H

/* ovl_15 CoinBlockBash (4P): units 152BE0.c (game) and 15AC50.c (coin blocks, billboards).
   Types come from the asm's accesses; N64 offsets are in the comments. */

#include "common.h"
#include "sprite65770.h"
#include "PR/gu.h"

/* Main state (D_801024F0, one object: splat's D_801024F4/D_801024F6 are its timer/time). */
typedef struct CBBMain {
    /* 0x00 */ s16 state; /* 0 intro, 1 play, 2 end, 3 results */
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 timer; /* frames in this state */
    /* 0x06 */ s16 time;  /* frames left */
} CBBMain; /* size = 0x8 */

/* A spark/digit effect (D_80102870_CoinBlockBash[40]; eight per player, 32.. for the rest). */
typedef struct CBBFx {
    /* 0x00 */ s16 flags; /* 0x80 live, 1 drawn, 2 fixed size */
    /* 0x02 */ s16 type;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ Vec pos;
    /* 0x14 */ Vec vel;
    /* 0x20 */ f32 rot;   /* turns */
    /* 0x24 */ f32 scale;
    /* 0x28 */ f32 alpha;
    /* 0x2C */ s16 unk_2C;
    /* 0x2E */ s16 unk_2E;
    /* 0x30 */ s16 unk_30;
    /* 0x32 */ s16 sound;
    /* 0x34 */ s16 unk_34;
    /* 0x36 */ s16 timer;
    /* 0x38 */ s16 unk_38;
    /* 0x3A */ s16 unk_3A;
} CBBFx; /* size = 0x3C */

/* An effect type (D_80101B24_CoinBlockBash[8], .data): what func_800F81E0 spawns. */
typedef struct CBBFxDef {
    /* 0x00 */ s16 count; /* < 0: take slots even if in use */
    /* 0x02 */ u16 sprite;
    /* 0x04 */ u16 frame;
    /* 0x06 */ s16 scale; /* percent */
    /* 0x08 */ s16 alpha; /* percent */
    /* 0x0A */ u16 timer;
    /* 0x0C */ u16 flags;
    /* 0x0E */ s16 unk_0E;
} CBBFxDef; /* size = 0x10 */

/* A hammer swing (D_80101BD4_CoinBlockBash[2], .data). */
typedef struct CBBSwing {
    /* 0x00 */ u16 timer;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 motion;
} CBBSwing;

/* A coin popped out of a block (D_80103290_CoinBlockBash[9], allocated by 15AC50.c). Pointers at
   0x00/0x04: use names, never offsets. */
typedef struct CBBDrop {
    /* 0x00 */ struct CBBCoin* coin; /* the block it came from */
    /* 0x04 */ omObjData* obj;       /* the player collecting it */
    /* 0x08 */ u8 state;  /* 0 none, 1 rising, 2 on the floor, 3 blinking, 4 collected, 5 gone */
    /* 0x09 */ u8 type;   /* D_80101B20_CoinBlockBash row: 0 coin, 1 big coin */
    /* 0x0A */ s8 active; /* can be collected */
    /* 0x0B */ char unk_0B;
    /* 0x0C */ s16 bb;     /* billboard */
    /* 0x0E */ s16 shadow; /* shadow billboard */
    /* 0x10 */ s32 timer;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ f32 radius;
    /* 0x1C */ Vec pos;
    /* 0x28 */ f32 unk_28; /* scale x */
    /* 0x2C */ f32 unk_2C; /* scale y */
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ Vec vel;
    /* 0x40 */ f32 unk_40; /* angle while collected */
} CBBDrop; /* size = 0x44 (N64) */

/* A coin block (D_80103294_CoinBlockBash[9], allocated by 15AC50.c). Pointers at 0x00..0x08. */
typedef struct CBBCoin {
    /* 0x00 */ unk2C0C0Struct50* blk;    /* model part "blNN" */
    /* 0x04 */ unk2C0C0Struct50* shadow; /* model part "kgNN" */
    /* 0x08 */ CBBDrop* drop;
    /* 0x0C */ u8 state;  /* 0 idle, 1 hit, 2 settling, 3 broken (flying), 4 gone */
    /* 0x0D */ s8 hittable;
    /* 0x0E */ s16 bb;     /* effect billboard, -1 none */
    /* 0x10 */ s16 unk_10; /* hits left */
    /* 0x12 */ char unk_12[2];
    /* 0x14 */ s32 timer;
    /* 0x18 */ f32 angle;  /* flight direction, -361 none */
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ Vec pos;
} CBBCoin; /* size = 0x2C (N64) */



/* Facing per quadrant (D_80101D18). */
typedef struct CBBQuad {
    f32 v[4];
} CBBQuad;

/* Main code's model matrix set (src/1EA70.c, func_8002040C). */
typedef struct CBBMtxSet {
    /* 0x00 */ s16 count;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16* unk_04;
    /* 0x08 */ Matrix4f* mtx;
} CBBMtxSet;

/* A player (D_801025B0_CoinBlockBash[4]; obj->work[0] is the index). Pointers at 0x70/0x78: use
   names, never offsets. Splat's D_801025B3, D_801025F0, D_80102612, D_80102628 are fields of [0]. */
typedef struct CBBPlayer {
    /* 0x00 */ u8 flags;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 state;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ Vec pos;
    /* 0x14 */ Vec unk_14;  /* last frame's push */
    /* 0x20 */ Vec vel;
    /* 0x2C */ f32 unk_2C;  /* facing target */
    /* 0x30 */ f32 unk_30;  /* speed */
    /* 0x34 */ char unk_34[4];
    /* 0x38 */ f32 unk_38;  /* gravity */
    /* 0x3C */ f32 unk_3C;  /* friction */
    /* 0x40 */ s16 unk_40;
    /* 0x42 */ s16 unk_42;
    /* 0x44 */ s16 unk_44;
    /* 0x46 */ s16 unk_46;
    /* 0x48 */ s16 unk_48;
    /* 0x4A */ s16 unk_4A;
    /* 0x4C */ s16 unk_4C;
    /* 0x4E */ s16 unk_4E; /* squash timer */
    /* 0x50 */ s16 unk_50;
    /* 0x52 */ char unk_52[4];
    /* 0x56 */ s16 unk_56;
    /* 0x58 */ s16 unk_58;
    /* 0x5A */ s16 unk_5A; /* queued motion */
    /* 0x5C */ u16 unk_5C; /* its timer */
    /* 0x5E */ s16 unk_5E; /* current motion */
    /* 0x60 */ u16 unk_60;
    /* 0x62 */ s16 unk_62;
    /* 0x64 */ s16 unk_64;
    /* 0x66 */ s16 unk_66; /* hammer swing (mtx set) */
    /* 0x68 */ s16 unk_68; /* its frame */
    /* 0x6A */ s16 mtxCount[2];
    /* 0x6E */ char unk_6E[2];
    /* 0x70 */ Matrix4f* mtx[2];
    /* 0x78 */ omObjData* obj;
    /* 0x7C */ f32 unk_7C; /* stick direction */
    /* 0x80 */ f32 unk_80; /* stick strength */
    /* 0x84 */ s16 unk_84; /* A pressed */
    /* 0x86 */ s16 unk_86; /* Z/B pressed */
    /* 0x88 */ s16 unk_88; /* B pressed */
    /* 0x8A */ char unk_8A[2];
    /* 0x8C */ Vec unk_8C; /* CPU target */
    /* 0x98 */ s16 unk_98; /* CPU goal: 1 block, 2 coin, 3 hammer */
    /* 0x9A */ s16 unk_9A;
    /* 0x9C */ s16 unk_9C; /* CPU target index */
    /* 0x9E */ s16 unk_9E;
    /* 0xA0 */ char unk_A0[0x10];
} CBBPlayer; /* size = 0xB0 (N64) */

/* A player's work (obj->unk_50, func_80023684(0x828)): MgWork's layout (src/99E0.c) at the
   start; its pointers sit where MgWork's do. */
typedef struct CBBPlayerWork {
    /* 0x00 */ char unk_00[0x56];
    /* 0x56 */ s8 unk_56; /* controller port */
    /* 0x57 */ char unk_57;
    /* 0x58 */ s8 unk_58; /* player */
    /* 0x59 */ char unk_59[0x5F];
    /* 0xB8 */ void* unk_B8;
    /* 0xBC */ char unk_BC[4];
    /* 0xC0 */ u16 unk_C0;
    /* 0xC2 */ char unk_C2[0x16];
    /* 0xD8 */ void* unk_D8; /* motion table */
    /* 0xDC */ void* unk_DC;
    /* 0xE0 */ char unk_E0[4];
    /* 0xE4 */ void* unk_E4;
    /* 0xE8 */ char unk_E8[0x740];
} CBBPlayerWork; /* size = 0x828 (N64) */

/* The hammer/block state (D_80102538, one 0x74 object: memset whole; splat's D_8010253A..
   D_8010256C are its fields). */
typedef struct CBBBlock {
    /* 0x00 */ s16 model;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ u8 unk_0C;
    /* 0x0D */ u8 unk_0D;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ Vec unk_10; /* position */
    /* 0x1C */ Vec unk_1C; /* velocity */
    /* 0x28 */ Vec unk_28; /* rotation */
    /* 0x34 */ Matrix4f unk_34;
} CBBBlock; /* size = 0x74 */

/* ---------------------------------------------------------------------------------------------
   Main code
   --------------------------------------------------------------------------------------------- */

extern u16 D_800EE984;
extern u8 D_800F64F8;
extern u16 D_800F5144;
extern omObjData* D_800F3FB0[];
extern omObjData* D_800F2AF8[];
extern unk_ovl_2D_struct* D_800F2B7C;
extern f32 D_800B8980;

u16 func_80017A50(omObjData* obj);
s32 func_80018490(omObjData* obj, u16 motion);
CBBMtxSet* func_8002040C(s16, s16, char*);
void func_80020CC4(CBBMtxSet*);
void func_80025BB8(s16, s16);
void func_80017C0C(omObjData*, u8, f32, f32, f32, f32, f32);
void MtxRotate(Matrix4f, f32, f32, f32);
void func_80060F04(s16, s16, s16, s16);
s16 MtxInv(Matrix4f, Matrix4f);
int abs(int);
f64 func_8009B618(f64, f64);
void func_8009E060(Matrix4f mf, f32 a, f32 x, f32 y, f32 z);
extern s8 ContStkY[];
void func_8002859C(s16 arg0, s16 arg1, char* arg2);
void func_80028498(s16, s16, s16);
s16 func_80060618(s16, s16);
s16 func_80060468(s16, u8);
s16 func_80060540(s16, s16);
void func_80017BB0(omObjData*);
void func_800284E4(s16);

/* ---------------------------------------------------------------------------------------------
   Overlay
   --------------------------------------------------------------------------------------------- */

extern u8 D_80101B20_CoinBlockBash[2][2];
extern CBBFxDef D_80101B24_CoinBlockBash[8];
extern CBBSwing D_80101BD4_CoinBlockBash[2];
extern u8 D_80101BDC_CoinBlockBash[12][2];
extern Vec D_80101BA4_CoinBlockBash[3];
extern f32 D_80101BC8_CoinBlockBash[3];
extern CBBMain D_801024F0_CoinBlockBash;
extern s16 D_801024F8_CoinBlockBash;
extern Vec D_801024FC_CoinBlockBash;
extern Vec D_80102508_CoinBlockBash;
extern Vec D_80102514_CoinBlockBash;
extern Vec D_80102520_CoinBlockBash;
extern f32 D_8010252C_CoinBlockBash;
extern f32 D_80102530_CoinBlockBash;
extern f32 D_80102534_CoinBlockBash;
extern CBBBlock D_80102538_CoinBlockBash;
/* Retail addresses the block's fields as separate symbols (no shared base): the N64 build keeps
   splat's labels, the host views the one object. */
extern s16 D_8010253A_CoinBlockBash;
extern s16 D_8010253C_CoinBlockBash;
extern s16 D_8010253E_CoinBlockBash;
extern s16 D_80102540_CoinBlockBash;
extern s16 D_80102542_CoinBlockBash;
extern u8 D_80102544_CoinBlockBash;
extern u8 D_80102545_CoinBlockBash;
extern s16 D_80102546_CoinBlockBash;
extern f32 D_80102548_CoinBlockBash;
extern f32 D_8010254C_CoinBlockBash;
extern f32 D_80102550_CoinBlockBash;
extern f32 D_80102554_CoinBlockBash;
extern f32 D_80102558_CoinBlockBash;
extern f32 D_8010255C_CoinBlockBash;
extern Matrix4f D_8010256C_CoinBlockBash;
extern s16 D_801025AC_CoinBlockBash;
extern CBBPlayer D_801025B0_CoinBlockBash[4];
extern CBBFx D_80102870_CoinBlockBash[40];
extern s16 D_801031D0_CoinBlockBash[8];
extern s16 D_801031E0_CoinBlockBash;
extern s16 D_801031E2_CoinBlockBash;
extern s16 D_801031E4_CoinBlockBash;
extern s16 D_801031E8_CoinBlockBash[9];
extern s32 D_801031FC_CoinBlockBash;
extern s16 D_80103200_CoinBlockBash[4];
extern s32 D_80103208_CoinBlockBash;
extern s16 D_8010320C_CoinBlockBash;
extern CBBDrop* D_80103290_CoinBlockBash;
extern CBBCoin* D_80103294_CoinBlockBash;
extern u8 D_8010320E_CoinBlockBash[];

void func_800F66F8_CoinBlockBash(omObjData* obj);
void func_800F6770_CoinBlockBash(omObjData* obj);
void func_800F6C20_CoinBlockBash(omObjData* obj);
void func_800F6C54_CoinBlockBash(void);
s16 func_800F6C80_CoinBlockBash(s32 id);
void func_800F6CC8_CoinBlockBash(void);
void func_800F6EA0_CoinBlockBash(void);
void func_800F7048_CoinBlockBash(omObjData* obj);
s32 func_800F7148_CoinBlockBash(s32 self, Vec* pos, f32 dx, f32 vy, f32 dz);
CBBPlayer* func_800F7644_CoinBlockBash(omObjData* obj);
void* func_800F766C_CoinBlockBash(omObjData* obj);
s16 func_800F7674_CoinBlockBash(omObjData* obj);
void func_800F7680_CoinBlockBash(omObjData* obj, s16 motion, char* name);
void func_800F77BC_CoinBlockBash(omObjData* obj, s32 motion);
void func_800F78DC_CoinBlockBash(omObjData* obj, s32 a, s32 b);
void func_800F78E8_CoinBlockBash(void);
void func_800F7A5C_CoinBlockBash(void);
void func_800F8014_CoinBlockBash(void);
void func_800F8184_CoinBlockBash(s16 type, f32 x, f32 y, f32 z, s16 arg);
void func_800F81E0_CoinBlockBash(omObjData* obj, s16 type, Vec* pos, Vec* rot, s16 arg);
void func_800F8CD0_CoinBlockBash(void);
void func_800F8D98_CoinBlockBash(void);
void func_800F96A0_CoinBlockBash(omObjData* obj, Matrix4f parent);
s32 func_800F9814_CoinBlockBash(f32 x, f32 y, f32 z, f32 r);
void func_800F99A0_CoinBlockBash(void);
void func_800F9A98_CoinBlockBash(void);
s32 func_800F9CF0_CoinBlockBash(CBBPlayer* p, Vec* pos, Vec* vel, Vec* out);
void func_800F9FE4_CoinBlockBash(void);
s32 func_800FA388_CoinBlockBash(CBBPlayer* self, Vec* pos, Vec* rot, Vec* off, f32 r);
s32 func_800FA600_CoinBlockBash(f32 x, f32 z, f32* best);
s32 func_800FA7AC_CoinBlockBash(f32 x, f32 z, f32* best);
s16 func_800FA944_CoinBlockBash(CBBPlayer* self, f32* best);
void func_800FAA7C_CoinBlockBash(void);
void func_800FB4F4_CoinBlockBash(omObjData* obj);
void func_800FB71C_CoinBlockBash(omObjData* obj, CBBPlayer* p);
void func_800FACEC_CoinBlockBash(omObjData* obj);
void func_800FB490_CoinBlockBash(void);
void func_800FBF70_CoinBlockBash(omObjData* obj);
void func_800FC2AC_CoinBlockBash(omObjData* obj);
s32 func_800FD8CC_CoinBlockBash(omObjData* obj, CBBPlayer* p, s16 big);
void func_800FDC5C_CoinBlockBash(void);
void func_800FDCB4_CoinBlockBash(omObjData* obj);
void func_800FDCF8_CoinBlockBash(omObjData* obj);
void func_800FDDEC_CoinBlockBash(Vec* v);
s32 func_800FE294_CoinBlockBash(Vec* pos, Vec* vel, Vec* out, Vec* n, s32 unused);
void func_800FDD50_CoinBlockBash(Matrix4f m, f32 x, f32 y, f32 z, Vec* out);
f32 func_800FDEA0_CoinBlockBash(f32 x, f32 z);
void func_800FDF20_CoinBlockBash(Matrix4f m, Vec* out);
void func_800FE0AC_CoinBlockBash(Vec* n, Vec* e, Vec* c, Vec* rot);
f32 func_800FE284_CoinBlockBash(Vec* pos);
void func_800FE470_CoinBlockBash(s16 cam, Vec* pos, Vec* out);
void func_800FE650_CoinBlockBash(void);
s16 func_800FF904_CoinBlockBash(omObjData* obj, s32 arg, CBBCoin* c);
void func_800FFD78_CoinBlockBash(CBBDrop* d, omObjData* obj);
void func_800FEE04_CoinBlockBash(void);
void func_800FFBA8_CoinBlockBash(void);
s16 func_800FFD60_CoinBlockBash(void);
s16 func_800FFD6C_CoinBlockBash(void);
void func_800FFE30_CoinBlockBash(void);

#endif
