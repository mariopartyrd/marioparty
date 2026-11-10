#ifndef BUMPERBALLS_H
#define BUMPERBALLS_H

#include "common.h"

/* A player's ball work (func_800F6EBC, 0x5C bytes on the N64). */
typedef struct BumperBallsWork {
    /* 0x00 */ u16 unk_00; /* state: 0 idle, 1 roll, 2 fast, 3 falling, 4 floating, 5 rescued, 6 winner */
    /* 0x02 */ s16 character;
    /* 0x04 */ u16 player;
    /* 0x06 */ char pad_06[2];
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C; /* heading */
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14; /* wanted heading */
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20; /* radius */
    /* 0x24 */ f32 unk_24; /* velocity x */
    /* 0x28 */ f32 unk_28; /* velocity y */
    /* 0x2C */ f32 unk_2C; /* velocity z */
    /* 0x30 */ f32 unk_30; /* ball rotation */
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ u16 unk_3C;
    /* 0x3E */ u16 unk_3E;
    /* 0x40 */ u8 unk_40[2];
    /* 0x42 */ u16 unk_42; /* CPU mode (func_800FA510) */
    /* 0x44 */ u16 unk_44;
    /* 0x46 */ u16 unk_46;
    /* 0x48 */ u16 unk_48;
    /* 0x4A */ u16 unk_4A;
    /* 0x4C */ u16 unk_4C;
    /* 0x4E */ char pad_4E[2];
    /* 0x50 */ f32 unk_50; /* CPU heading (bob phase once floating) */
    /* 0x54 */ omObjData* unk_54; /* CPU target */
    /* 0x58 */ u16 unk_58;
    /* 0x5A */ u16 unk_5A;
} BumperBallsWork; /* size = 0x5C on the N64 */

/* The rescue boats' work (func_800F85A8, 0x20 bytes). */
typedef struct BumperBallsBoatWork {
    /* 0x00 */ u16 player;
    /* 0x02 */ u16 state;
    /* 0x04 */ u16 side;
    /* 0x06 */ u16 model;
    /* 0x08 */ u16 model2;
    /* 0x0A */ char pad_0A[2];
    /* 0x0C */ f32 angle;
    /* 0x10 */ f32 speed;
    /* 0x14 */ f32 dx;
    /* 0x18 */ f32 dy;
    /* 0x1C */ f32 endX;
} BumperBallsBoatWork; /* size = 0x20 */

typedef struct BumperBallsColVtx {
    s16 x;
    s16 y;
    s16 z;
} BumperBallsColVtx;

typedef struct BumperBallsHitProbe {
    f32 x;
    f32 y;
    f32 z;
} BumperBallsHitProbe;

/* objmain.c's objmainChr (D_800C59A8[6]); the (chr << 16 | unk06) word is D_800C59AC[c].unk_00. */
typedef struct BumperBallsChr {
    /* 0x00 */ s16 index;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s16 chr;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ s32 file0;
    /* 0x0C */ s32 file1;
    /* 0x10 */ f32 scale;
} BumperBallsChr; /* size = 0x14 */
extern BumperBallsChr D_800C59A8[6];

extern s8 ContStkY[];
extern u8 D_800F64F8;
extern s16 D_800F3778;
extern s32 D_800EDEC0;

/* .bss */
extern u16 D_800FCD00_BumperBalls;
extern u16 D_800FCD02_BumperBalls; /* the winner */
extern f32 D_800FCD04_BumperBalls;
extern omObjData* D_800FCD08_BumperBalls; /* the winner's ball */
extern u16 D_800FCD0C_BumperBalls;
extern s16 D_800FCD0E_BumperBalls;
extern u16 D_800FCD10_BumperBalls; /* balls still on the island */
extern s16 D_800FCD12_BumperBalls;
extern u16 D_800FCD14_BumperBalls;
extern u16 D_800FCD16_BumperBalls; /* seconds left */
extern s16 D_800FCD18_BumperBalls;
extern s16 D_800FCD1A_BumperBalls;
extern s16 D_800FCD1C_BumperBalls;
extern s16 D_800FCD1E_BumperBalls; /* humans still on the island */
extern omObjData* D_800FCD20_BumperBalls; /* the island */
extern omObjData* D_800FCD24_BumperBalls;
extern omObjData* D_800FCD28_BumperBalls;
extern omObjData** D_800FCD2C_BumperBalls; /* the balls */
extern omObjData** D_800FCD30_BumperBalls; /* the boats */
extern u16 D_800FCFF0_BumperBalls;
extern u16 D_800FCFF2_BumperBalls;
extern u16 D_800FCFF4_BumperBalls;

void func_800FB1E0_BumperBalls(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
void func_800FB298_BumperBalls(void);
void func_800FB2D0_BumperBalls(s32 arg0);
void func_800FB2EC_BumperBalls(void);
void func_800FC618_BumperBalls(void);

void func_800F6A60_BumperBalls(omObjData* arg0);
void func_800F6AB4_BumperBalls(omObjData*);
void func_800F6D98_BumperBalls(omObjData* arg0);
void func_800F6E10_BumperBalls(omObjData*);
void func_800F6E2C_BumperBalls(omObjData* arg0);
void func_800F6E68_BumperBalls(omObjData* arg0);
void func_800F6E84_BumperBalls(omObjData* arg0);
void func_800F6EA0_BumperBalls(omObjData* arg0);
void func_800F6EBC_BumperBalls(omObjData*, s32);
void func_800F74E8_BumperBalls(omObjData*);
void func_800F7EC4_BumperBalls(omObjData*);
void func_800F821C_BumperBalls(omObjData*);
void func_800F8304_BumperBalls(omObjData*);
void func_800F8384_BumperBalls(omObjData*);
void func_800F84AC_BumperBalls(omObjData*);
void func_800F8538_BumperBalls(omObjData* arg0);
void func_800F8554_BumperBalls(omObjData* arg0);
void func_800F8570_BumperBalls(omObjData* arg0);
void func_800F858C_BumperBalls(omObjData* arg0);
void func_800F85A8_BumperBalls(omObjData*, s32);
void func_800F87F4_BumperBalls(omObjData*);
void func_800F8D68_BumperBalls(omObjData*);
void func_800F8E40_BumperBalls(omObjData*);
void func_800F9588_BumperBalls(void);
u16 func_800F95CC_BumperBalls(omObjData*);
void func_800F98CC_BumperBalls(f32, u16);
f32 func_800F9A7C_BumperBalls(f32, f32, f32);
u16 func_800F9B70_BumperBalls(omObjData*);
s32 func_800F9CA8_BumperBalls(s32, u16*, BumperBallsColVtx*, BumperBallsHitProbe*);
s32 func_800F9CC8_BumperBalls(BumperBallsHitProbe*, u16*, BumperBallsColVtx*);
u16 func_800F9EE0_BumperBalls(void);
void func_800F9F30_BumperBalls(omObjData*);
u16 func_800FA36C_BumperBalls(omObjData*);
u16 func_800FA3A0_BumperBalls(omObjData*, f32);
void func_800FA510_BumperBalls(omObjData*, s8*, s8*);
void func_800FA5A4_BumperBalls(omObjData*, s8*, s8*);
void func_800FA950_BumperBalls(omObjData*, s8*, s8*);
void func_800FAB54_BumperBalls(omObjData*, s8*, s8*);
void func_800FAE60_BumperBalls(omObjData*, s8*, s8*);

/* main-code helpers (prototypes as the twins ovl_34 declare them) */
void func_8001E268(s16, u8, u8);
void func_800370D4(s16);
void func_80025BB8(s16, s16);
void func_80027AC8(s16, u8*, u8*);
f32 func_80025D18(s16);
f32 func_80025D40(s16);
f32 func_800296FC(f32, f32, BumperBallsColVtx*, BumperBallsColVtx*);
f32 func_80029764(f32, f32, f32, void*, u16*);
void func_8002AE24(s16, s32*, void*, void*);
u16* func_8002B3A8(s32*);
void func_80060F04(s16 player, s16 arg1, s16 arg2, s16 arg3);
void func_80060440(s16, s16);
void func_8006035C(s16, s8);

/* Water mesh (196300.c). */
typedef struct BumperBallsAnglePair {
    f32 first;
    f32 second;
} BumperBallsAnglePair;

/* Wave phases of the 6 x 6 water mesh (bss): per row, the near edge's 6 pairs then the far
   edge's 6. func_800FB2EC indexes the far pairs as half-rows of 6 from the splat label D_800FCD70
   (= D_800FCD40 + 0x30; far edge of row r = D_800FCD70[2r]), which on the host is a view of
   D_800FCD40; func_800FC618 uses BB_WAVE_FAR (rows of 12 from the same address). */
extern BumperBallsAnglePair D_800FCD40_BumperBalls[6][12];
extern BumperBallsAnglePair D_800FCD70_BumperBalls[][6];
#define BB_WAVE_FAR ((BumperBallsAnglePair(*)[12]) &D_800FCD40_BumperBalls[0][6])
extern unk2C0C0Struct70* D_800FCF80_BumperBalls; /* 47mt003_DEF (water) */
extern unk2C0C0Struct70* D_800FCF84_BumperBalls; /* 47mt002_IA44 (under-layer) */
extern Gfx* D_800FCF88_BumperBalls[8];           /* per-screen display lists */
extern Vtx* D_800FCFA8_BumperBalls[8];           /* per-screen water vertices (6 x 24) */
extern Vtx* D_800FCFC8_BumperBalls[8];           /* per-screen under-layer vertices */
extern s32 D_800FCFE8_BumperBalls;

extern u16 D_800FCBC0_BumperBalls;

#endif
