#ifndef UNUSEDMINIGAME0_105EA0_H
#define UNUSEDMINIGAME0_105EA0_H

/* ovl_06 UnusedMinigame0, unit 105EA0.c: an 8 x 6 grid of coloured blocks (shapes chosen by
   which same-coloured neighbours they touch), a chain-match on a picked block that drops the
   blocks above it and shifts empty columns, the sparkles of matched blocks, and the 48 "drop"
   actors that fall onto the board at the start. Declarations for this unit only; the
   coordinator unifies them with UnusedMinigame0.h (FF570.c / 103D80.c) at merge.
   Pointer fields shift every later field on the host: use names, never offsets. */

#include "common.h"
#include "PR/gu.h"

/* A falling block actor (D_80108C60_UnusedMinigame0[48]), size 0x40 (N64). */
typedef struct UM0Drop {
    /* 0x00 */ s32 tile;   /* its index in D_8010A040_UnusedMinigame0 */
    /* 0x04 */ s32 skin;   /* row of D_8010B070_UnusedMinigame0 */
    /* 0x08 */ s32 state;
    /* 0x0C */ s32 wait;
    /* 0x10 */ s32 timer;
    /* 0x14 */ f32 fromX;
    /* 0x18 */ f32 fromZ;
    /* 0x1C */ f32 x;
    /* 0x20 */ f32 z;
    /* 0x24 */ f32 y;
    /* 0x28 */ f32 speed;
    /* 0x2C */ f32 vx;
    /* 0x30 */ f32 vz;
    /* 0x34 */ f32 angle;
    /* 0x38 */ f32 dir;
    /* 0x3C */ f32 spin;
} UM0Drop; /* size = 0x40 (N64) */

/* A grid block (D_8010A040_UnusedMinigame0[48]), size 0x44 (N64). */
typedef struct UM0Tile {
    /* 0x00 */ UM0Drop* drop;
    /* 0x04 */ s32 col;   /* 0..7 */
    /* 0x08 */ s32 row;   /* 0..5 */
    /* 0x0C */ f32 x;
    /* 0x10 */ f32 z;
    /* 0x14 */ s32 color; /* 0..4 */
    /* 0x18 */ s32 shape; /* row of D_80109CD8_UnusedMinigame0 / D_8010AD00_UnusedMinigame0 */
    /* 0x1C */ s32 rot;   /* quarter turns */
    /* 0x20 */ u8 links;  /* same-colour neighbour bits (D_8010372C_UnusedMinigame0) */
    /* 0x21 */ char unk_21[3];
    /* 0x24 */ s32 flags;
    /* 0x28 */ s32 fade;
    /* 0x2C */ struct UM0Tile* match; /* the block that reached it in a chain match */
    /* 0x30 */ s32 state; /* 0 on the board, 1 matched, 2 gone */
    /* 0x34 */ s32 visited;
    /* 0x38 */ s32 moveTimer;
    /* 0x3C */ f32 dx;    /* columns to move left */
    /* 0x40 */ f32 dy;    /* rows to move down */
} UM0Tile; /* size = 0x44 (N64) */

/* The match-preview grid cell (D_8010B150_UnusedMinigame0[8][6]), size 0x10. */
typedef struct UM0Cell {
    /* 0x00 */ s32 color; /* low byte = colour + 1, 0 empty */
    /* 0x04 */ u16 done;
    /* 0x06 */ u16 seen;
    /* 0x08 */ s32 shiftCols;
    /* 0x0C */ s32 shiftRows;
} UM0Cell;

/* A sparkle of a matched block (D_8010AD60_UnusedMinigame0[32]), size 0x10. */
typedef struct UM0Spark {
    /* 0x00 */ s32 active;
    /* 0x04 */ s32 color;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 timer;
} UM0Spark;

/* (shape, rot) for each 4-bit neighbour mask. */
typedef struct UM0ShapeRot {
    s32 shape;
    s32 rot;
} UM0ShapeRot;

/* .data (FF570's data subsegment) */
extern Vtx D_80102D20_UnusedMinigame0[];
extern Gfx D_80102F20_UnusedMinigame0[];
extern Vtx D_80102F30_UnusedMinigame0[];
extern Gfx D_801030C8_UnusedMinigame0[];
extern Vtx D_801030D8_UnusedMinigame0[];
extern Gfx D_80103220_UnusedMinigame0[];
extern Vtx D_80103230_UnusedMinigame0[];
extern Gfx D_80103350_UnusedMinigame0[];
extern Vtx D_80103360_UnusedMinigame0[];
extern Gfx D_80103428_UnusedMinigame0[];
extern Vtx D_80103438_UnusedMinigame0[];
extern Gfx D_80103498_UnusedMinigame0[];
extern Vtx D_801034A8_UnusedMinigame0[17];
extern Gfx D_801035B8_UnusedMinigame0[];
extern UM0ShapeRot D_80103608_UnusedMinigame0[16];
extern u32 D_801036A0_UnusedMinigame0[3][8];
/* Seed row r: splat's D_80103640[r] (inside D_80103608, rows 3..5 = D_801036A0). */
extern s32 D_80103640_UnusedMinigame0[][8];
#define UM0_SEED_ROW(r) D_80103640_UnusedMinigame0[r]
extern s32 D_80103688_UnusedMinigame0[6];
extern s32 D_80103700_UnusedMinigame0;
extern s32 D_80103704_UnusedMinigame0;
extern u32 D_80103708_UnusedMinigame0;
extern s16 D_8010370C_UnusedMinigame0[4][2];
extern s16 D_8010371C_UnusedMinigame0[4][2];
typedef struct UM0LinkBit {
    u8 unk_00;
    u8 bit;
} UM0LinkBit;
extern UM0LinkBit D_8010372C_UnusedMinigame0[4];
extern s16 D_80103734_UnusedMinigame0;
extern s32 D_80103738_UnusedMinigame0;
/* A sound handle kept as a word; the code reads its low half (split label D_8010373E). */
extern s32 D_8010373C_UnusedMinigame0;
#define UM0_SOUND ((s16)D_8010373C_UnusedMinigame0)
extern s16 D_80103740_UnusedMinigame0;
extern s32 D_80103748_UnusedMinigame0;
extern s32 D_8010374C_UnusedMinigame0;
/* A sound handle kept as a word; read through its low half (split label D_80103752). */
extern s32 D_80103750_UnusedMinigame0;
#define UM0_SOUND2 ((s16)D_80103750_UnusedMinigame0)
extern f32 D_80103754_UnusedMinigame0;
extern s16 D_80103758_UnusedMinigame0[4][2];
extern s16 D_80103768_UnusedMinigame0[6][2];

/* .bss */
extern s32 D_80104340_UnusedMinigame0;
extern f32 D_80104344_UnusedMinigame0;
extern Mtx D_80104350_UnusedMinigame0[3][48];
extern Mtx D_80106750_UnusedMinigame0[3][48];
extern u8 D_80108B50_UnusedMinigame0[8][6];
extern UM0Tile* D_80108B88_UnusedMinigame0[8][6];
extern Gfx* D_80108C50_UnusedMinigame0[3];
extern UM0Drop D_80108C60_UnusedMinigame0[48];
extern Gfx* D_801098A8_UnusedMinigame0[3];
/* Model ids returned as words; the code reads their low halves (D_80109CC2.., split labels). */
extern s32 D_80109CC0_UnusedMinigame0[3];
extern s32 D_80109CCC_UnusedMinigame0;
extern s32 D_80109CD0_UnusedMinigame0;
extern s32 D_80109CD4_UnusedMinigame0;
/* [shape][0][0][0] is the source vertex list, [shape][1..2][k][frame] the animated copies. */
extern Vtx* D_80109CD8_UnusedMinigame0[6][3][4][3];
extern UM0Tile D_8010A040_UnusedMinigame0[48];
extern Gfx* D_8010AD00_UnusedMinigame0[6];
extern UM0Spark D_8010AD60_UnusedMinigame0[32];
extern s32 D_8010AF60_UnusedMinigame0[4][17];
extern Vtx* D_8010B070_UnusedMinigame0[4][3];
extern s32 D_8010B0A0_UnusedMinigame0[4][3];
/* [8][3]: rows 4..7 are splat's D_8010B100_UnusedMinigame0 (never named in C). */
extern Vtx* D_8010B0D0_UnusedMinigame0[8][3];
extern UM0Cell D_8010B150_UnusedMinigame0[8][6];
extern s32 D_8010B458_UnusedMinigame0[4][17];

/* The model ids' low halves (split labels D_80109CC2/C6/CA/CE/D2/D6 on the N64). */
#define UM0_MODEL(i) ((s16)D_80109CC0_UnusedMinigame0[i])
#define UM0_MODEL_DROP ((s16)D_80109CCC_UnusedMinigame0)
#define UM0_SPRITE ((s16)D_80109CD0_UnusedMinigame0)
#define UM0_SPRGRP ((s16)D_80109CD4_UnusedMinigame0)

/* main code */
s32 func_80024198(s32, void*, s32);
void func_80067284(s16, s16, f32);
void func_80066DF4(s16, s16, s16, f32, f32, f32);
s32 func_800115C8(s16);

/* this unit */
void func_800FCF10_UnusedMinigame0(s16 arg0);
void func_800FCFB4_UnusedMinigame0(s32 arg0);
void func_800FD430_UnusedMinigame0(void);
void func_800FD5E0_UnusedMinigame0(void);
s32 func_800FD800_UnusedMinigame0(s32 col, s32 row);
void func_800FDA50_UnusedMinigame0(UM0Tile* t, s32 match);
s32 func_800FDC1C_UnusedMinigame0(s32 col, s32 row);
s32 func_800FDCF8_UnusedMinigame0(s16 arg0);
void func_800FE168_UnusedMinigame0(UM0Tile* t);
void func_800FE1FC_UnusedMinigame0(UM0Tile* t);
void func_800FE360_UnusedMinigame0(void);
void func_800FE3CC_UnusedMinigame0(s32 arg0);
void func_800FEBF0_UnusedMinigame0(s16 arg0);
void func_800FF284_UnusedMinigame0(void);
void func_800FF488_UnusedMinigame0(void);
void func_800FFA64_UnusedMinigame0(void);
s32 func_80100850_UnusedMinigame0(void);
u32 func_80102568_UnusedMinigame0(u32 n);
void func_801025B8_UnusedMinigame0(u8 (*out)[6]);
s32 func_80102634_UnusedMinigame0(u8 (*grid)[6], s32 col, s32 row);
void func_8010298C_UnusedMinigame0(s32 col, s32 row);

#endif
