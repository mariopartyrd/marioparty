#ifndef UNUSEDMINIGAME0_H
#define UNUSEDMINIGAME0_H

/* ovl_06 UnusedMinigame0: a 1P minigame left in the ROM but never launched (its overlay-table
   entry points at 0x25). The player walks a 8 x 6 board of 10-unit cells (x -350..350,
   z -250..250); 105EA0.c owns the board. FF570.c: setup, flow, the player. 103D80.c: camera
   keyframes, the per-object work, the board's collision outline. Types come from the asm's
   accesses; N64 offsets are in the comments. */

#include "common.h"
#include "PR/gu.h"
#include "engine/math.h"

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* An object's extra work (func_800FB568_UnusedMinigame0: 0x60 bytes, kept in D_801098C0[]).
   omObjData::work[0..3] holds a big-endian pointer to it on the N64; the host keeps the
   D_801098C0 index there (func_800FB6D0_UnusedMinigame0). */
typedef struct UM0Work {
    /* 0x00 */ s16 unk0; /* flags (bit 15: set up) */
    /* 0x02 */ u16 unk2; /* flags */
    /* 0x04 */ s16 unk4; /* collision radius / 10 */
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s16 unk8; /* state */
    /* 0x0A */ char unkA[2];
    /* 0x0C */ omObjData* obj;
    /* 0x10 */ f32 unk10; /* home position */
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C; /* last x */
    /* 0x20 */ f32 unk20; /* bounce speed */
    /* 0x24 */ f32 unk24; /* last z */
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C; /* target angle */
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
    /* 0x3C */ f32 unk3C;
    /* 0x40 */ s16 unk40; /* sub-state */
    /* 0x42 */ s16 unk42; /* timer */
    /* 0x44 */ s16 unk44; /* CPU target x (or a counter) */
    /* 0x46 */ s16 unk46; /* CPU target z */
    /* 0x48 */ s16 unk48; /* CPU move index */
    /* 0x4A */ s16 unk4A;
    /* 0x4C */ s16 unk4C;
    /* 0x4E */ s16 unk4E;
    /* 0x50 */ s16 unk50;
    /* 0x52 */ s16 unk52;
    /* 0x54 */ s16 unk54;
    /* 0x56 */ s16 unk56;
    /* 0x58 */ s16 unk58; /* D_80108C4C index reached, -1 none */
    /* 0x5A */ s16 unk5A; /* exit */
    /* 0x5C */ s16 unk5C;
    /* 0x5E */ s16 unk5E; /* exit being pushed, -1 none */
} UM0Work; /* size = 0x60 */

/* Partial views of 105EA0.h's types (checked at merge, 2026-10-15): UM0Cell is UM0Tile (its first
   field, UM0Drop* drop, is the only one read here) and UM0CellState is UM0Drop (unk8 = state,
   unk10 = timer; UM0Drop has no pointers before 0x14, so the host offsets agree too). 105EA0.h's
   own `UM0Cell` is the unrelated match-preview cell; the two headers are never included together. */
typedef struct UM0CellState {
    /* 0x00 */ char unk0[8];
    /* 0x08 */ s32 unk8;
    /* 0x0C */ char unkC[4];
    /* 0x10 */ s32 unk10;
} UM0CellState;

/* The player object's work (func_8000979C: 0xE8 bytes, MgWork's layout; main code reads it). */
typedef struct UM0MgWork {
    /* 0x00 */ char unk_00[0x38];
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ f32 unk_3C; /* facing */
    /* 0x40 */ char unk_40[0x10];
    /* 0x50 */ u16 unk_50; /* flags (0x80: landed on a block) */
    /* 0x52 */ char unk_52[4];
    /* 0x56 */ u8 unk_56; /* controller port */
    /* 0x57 */ char unk_57;
    /* 0x58 */ s8 unk_58; /* player */
    /* 0x59 */ char unk_59[3];
    /* 0x5C */ s32 unk_5C; /* flags */
    /* 0x60 */ char unk_60[0x52];
    /* 0xB2 */ s8 unk_B2;
    /* 0xB3 */ s8 unk_B3; /* sound handle */
    /* 0xB4 */ char unk_B4[4];
    /* 0xB8 */ void* unk_B8;
    /* 0xBC */ char unk_BC[0x1C];
    /* 0xD8 */ void* unk_D8; /* motion table */
    /* 0xDC */ void* unk_DC;
    /* 0xE0 */ char unk_E0[4];
    /* 0xE4 */ void* unk_E4;
} UM0MgWork; /* size = 0xE8 */

/* The board object's work (func_800F924C: 0x2C bytes, func_80009028's collision work). */
typedef struct UM0BoardWork {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk_06[0xA];
    /* 0x10 */ f32 unk_10; /* floor height under the player */
    /* 0x14 */ char unk_14[0x18];
} UM0BoardWork; /* size = 0x2C */

/* A pick-up's work (func_800F9F04: 0x6C bytes, func_800091BC's). */
typedef struct UM0ItemWork {
    /* 0x00 */ char unk_00[0x22];
    /* 0x22 */ u8 unk_22; /* light */
    /* 0x23 */ char unk_23[0x11];
    /* 0x34 */ f32 unk_34; /* orbit radius */
    /* 0x38 */ f32 unk_38; /* base height */
    /* 0x3C */ f32 unk_3C; /* orbit angle */
    /* 0x40 */ char unk_40[0x14];
    /* 0x54 */ u8 unk_54;
    /* 0x55 */ char unk_55[0x17];
} UM0ItemWork; /* size = 0x6C */

/* A search state of the CPU's sliding-block planner (D_80103DA4_UnusedMinigame0[10000]). */
typedef struct UM0State {
    /* 0x00 */ s8 cost;
    /* 0x01 */ u8 board[8][6];
    /* 0x31 */ char unk31[3];
    /* 0x34 */ struct UM0State* parent;
    /* 0x38 */ u16 children;
    /* 0x3A */ u8 x; /* the move that led here */
    /* 0x3B */ u8 z;
} UM0State; /* size = 0x3C */

typedef struct UM0Cell {
    /* 0x00 */ UM0CellState* state;
} UM0Cell;

/* A point of the board's collision outline (D_80103E28_UnusedMinigame0). */
typedef struct UM0Point {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 z;
} UM0Point;

/* A 2D point (func_800FC29C_UnusedMinigame0's list). */
typedef struct UM0Vec2 {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 z;
} UM0Vec2;

/* The camera view at D_800EE73C (its rotation is the word before), as ovl_2B. */
typedef struct UM0CameraView {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 z;
    /* 0x08 */ f32 fov;
    /* 0x0C */ f32 far;
    /* 0x10 */ f32 near;
} UM0CameraView;

/* ---------------------------------------------------------------------------------------------
   Main code
   --------------------------------------------------------------------------------------------- */

f64 func_8009B618(f64, f64); /* fmod */
extern UM0CameraView D_800EE73C;

/* ---------------------------------------------------------------------------------------------
   Overlay .bss (shared by the units)
   --------------------------------------------------------------------------------------------- */

extern s16 D_80108B80_UnusedMinigame0;              /* D_801098C0 entries */
extern UM0Cell* D_80108B88_UnusedMinigame0[8][6];   /* the board, [x][z] (105EA0.c) */
extern omObjData* D_80108C4C_UnusedMinigame0[];      /* D_8010B450 entries */
extern omObjData* D_801098A0_UnusedMinigame0;        /* the camera object */
extern omObjData* D_8010AD18_UnusedMinigame0;        /* the flow object */
extern s16 D_801098B4_UnusedMinigame0[];
extern UM0Work* D_801098C0_UnusedMinigame0[256];     /* every UM0Work allocated */
extern u8 D_8010B450_UnusedMinigame0;

/* FF570.c's .bss */
extern s16 D_80103D80_UnusedMinigame0; /* flow state */
extern s16 D_80103D82_UnusedMinigame0; /* the board is ready */
extern s16 D_80103D84_UnusedMinigame0; /* input locked */
extern s16 D_80103D86_UnusedMinigame0; /* result: 1 won, -1 leave */
extern s16 D_80103D88_UnusedMinigame0; /* time left (frames) */
extern s16 D_80103D8A_UnusedMinigame0; /* flow timer */
extern s16 D_80103D8C_UnusedMinigame0[5]; /* per exit/piece slot: 1 open, 2 close */
extern s16 D_80103D96_UnusedMinigame0;
extern omObjData* D_80103D98_UnusedMinigame0; /* the timer object */
extern s16 D_80103D9C_UnusedMinigame0; /* the player */
extern s16 D_80103D9E_UnusedMinigame0; /* the treasure was reached */
extern s16 D_80103DA0_UnusedMinigame0; /* pick-ups created */
extern s16 D_80103DA2_UnusedMinigame0; /* flag 0x2B */
extern UM0State* D_80103DA4_UnusedMinigame0;
extern s16 D_80103DA8_UnusedMinigame0; /* states used */
extern UM0State** D_80103DAC_UnusedMinigame0; /* leaf states */
extern s16 D_80103DB0_UnusedMinigame0; /* leaves */
extern s16 D_80103DB2_UnusedMinigame0; /* search depth */
extern u8 D_80103DB8_UnusedMinigame0[48][2]; /* the CPU's moves (cell x, z) */
extern s16 D_80103E18_UnusedMinigame0;    /* moves */
extern u8 D_80108B50_UnusedMinigame0[8][6];
extern s32 D_80109CC0_UnusedMinigame0[3];

/* 103D80.c's .bss */
extern s16 D_80103E20_UnusedMinigame0;           /* outline points */
extern s16 D_80103E22_UnusedMinigame0;           /* outline index-list length */
extern UM0Point D_80103E28_UnusedMinigame0[0xC0];
extern s8 D_80104128_UnusedMinigame0[0x120];     /* point indices, 0xFF ends a loop */
extern UM0Point* D_80104248_UnusedMinigame0;     /* next free point */
extern s8* D_8010424C_UnusedMinigame0;           /* next free index */
extern f32 D_80104250_UnusedMinigame0[8][3];        /* camera keys: centre */
extern f32 D_801042B0_UnusedMinigame0[8][3];        /* camera keys: rotation */
extern f32 D_80104310_UnusedMinigame0[8];        /* camera keys: zoom */
extern s16 D_80104330_UnusedMinigame0;           /* keys */
extern s16 D_80104332_UnusedMinigame0;           /* frame */
extern s16 D_80104334_UnusedMinigame0;           /* length in frames, -1 none */

/* ---------------------------------------------------------------------------------------------
   Functions
   --------------------------------------------------------------------------------------------- */

/* Main code */
void func_800096B0(void*, s32);
s16 func_80010ED4(s16, s16);
void func_80060F04(s16, s16, s16, s16);
f32 func_80025D18(s16);
void func_80008EF0(omObjData*, u16, s32, s32, f32);
void func_800093FC(omObjData*, f32, f32, f32);
void func_800090C4(omObjData*, u8, u8);
void func_800091BC(omObjData*, s32, s32, s32);
void func_8001E2A8(s16, u16);
void func_8001E268(s16, u8, u8);
extern u16 ContBtn[4];
extern s8 ContStkY[];
extern f32 D_800B897C;
extern omObjData* D_800EDE70[];
extern omObjData* D_800F2AF8[];
extern u16 D_800EE984;

/* FF570.c */
void func_800F65E0_UnusedMinigame0(void);
void func_800F6964_UnusedMinigame0(omObjData* obj);
void func_800F69A0_UnusedMinigame0(omObjData* obj);
void func_800F6D7C_UnusedMinigame0(void);
void func_800F6DD0_UnusedMinigame0(omObjData* obj);
void func_800F6E48_UnusedMinigame0(omObjData* obj);
void func_800F6EC0_UnusedMinigame0(omObjData* obj);
f32 func_800F7320_UnusedMinigame0(f32 cur, f32 target, f32 step);
void func_800F75C0_UnusedMinigame0(omObjData* obj);
void func_800F924C_UnusedMinigame0(omObjData* obj);
void func_800F95C0_UnusedMinigame0(omObjData* obj);
void func_800F9BBC_UnusedMinigame0(omObjData* obj);
void func_800F9DB4_UnusedMinigame0(omObjData* obj);
void func_800F9F04_UnusedMinigame0(omObjData* obj);
void func_800FA024_UnusedMinigame0(omObjData* obj);
void func_800FA4A4_UnusedMinigame0(void);
void func_800FA678_UnusedMinigame0(u8 src[8][6], u8 dst[8][6]);
s16 func_800FA6F8_UnusedMinigame0(u8 board[8][6], s16 x, s16 z, u8 val);
void func_800FA7A8_UnusedMinigame0(u8 board[8][6], s16* x, s16* z);
void func_800FA968_UnusedMinigame0(u8 board[8][6]);
void func_800FA9D0_UnusedMinigame0(UM0State* s);
UM0State* func_800FABF0_UnusedMinigame0(void);
s32 func_800FACA0_UnusedMinigame0(u8 board[8][6], s16* x, s16* z);

/* 103D80.c */
void func_800FADF0_UnusedMinigame0(omObjData* obj);
void func_800FAE84_UnusedMinigame0(f32 zoom, f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz);
void func_800FAEC4_UnusedMinigame0(f32 zoom, f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz, u16 frames);
void func_800FB190_UnusedMinigame0(s32 i, f32 t);
void func_800FB3B4_UnusedMinigame0(omObjData* obj);
UM0Work* func_800FB568_UnusedMinigame0(omObjData* obj);
void func_800FB650_UnusedMinigame0(void);
UM0Work* func_800FB6D0_UnusedMinigame0(omObjData* obj);
u32 func_800FB6FC_UnusedMinigame0(void);
s32 func_800FB734_UnusedMinigame0(omObjData* obj);
s16 func_800FB810_UnusedMinigame0(f32 x, f32 z, s32 mask);
s16 func_800FB904_UnusedMinigame0(s16* x, s16* z);
s32 func_800FBAA0_UnusedMinigame0(s16 x, s16 z);
void func_800FBB18_UnusedMinigame0(f32 x, f32 z);
void func_800FBFE4_UnusedMinigame0(omObjData* obj);
void func_800FC29C_UnusedMinigame0(f32* x, f32* z, f32 dist, UM0Vec2* pts, s16 n);
s16 func_800FC564_UnusedMinigame0(f32* x, f32* z, f32 radius);
f32 func_800FC944_UnusedMinigame0(f32 x, f32 z);
s16 func_800FCA40_UnusedMinigame0(omObjData* obj, f32 dx, f32 dz, f32 radius);
void func_800FCD68_UnusedMinigame0(void);

/* 105EA0.c */
void func_800FCF10_UnusedMinigame0(s32);
void func_800FD430_UnusedMinigame0(void);
s16 func_800FDCF8_UnusedMinigame0(s16);
void func_800FDC1C_UnusedMinigame0(s16 x, s16 z);
void func_801025B8_UnusedMinigame0(u8 board[8][6]);
u8 func_80102634_UnusedMinigame0(u8 board[8][6], s16 x, s16 z);

#endif
