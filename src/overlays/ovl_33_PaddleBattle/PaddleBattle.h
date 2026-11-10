#ifndef PADDLEBATTLE_H
#define PADDLEBATTLE_H

/* ovl_33 PaddleBattle: declarations shared by its units (2341E0, 234F80).
   One player (seat 0, GwPlayer group 0) paddles against the other three (seats 1-3) on one raft
   going down a river (D_800FFF10_PaddleBattle): the stronger side steers it toward the far bank,
   and the side whose bank the raft bumps loses coins to the other. Types come from the asm's
   accesses; N64 offsets are in the comments. */

#include "common.h"
#include "PR/gu.h"
#include "sprite65770.h"

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* The raft (D_800FFF10_PaddleBattle, zeroed as one 0x90-byte block). */
typedef struct PBRaft {
    /* 0x00 */ omObjData* obj;
    /* 0x04 */ s8 seat[4];     /* player in each seat, -1 when empty */
    /* 0x08 */ Matrix4f mtx;   /* the raft's world matrix (the riders are placed through it) */
    /* 0x48 */ f32 y;          /* ground height under the raft */
    /* 0x4C */ f32 drift;      /* lateral current */
    /* 0x50 */ f32 dist;       /* distance down the river, 0..2000 */
    /* 0x54 */ f32 speed;
    /* 0x58 */ f32 lateral;    /* 0 left bank .. 1 right bank */
    /* 0x5C */ f32 turn;
    /* 0x60 */ f32 rotX;
    /* 0x64 */ f32 rotY;
    /* 0x68 */ f32 weight[4];  /* paddle weight per seat */
    /* 0x78 */ s16 strokes[4]; /* paddle strokes per seat */
    /* 0x80 */ s16 timer;
    /* 0x82 */ s16 side;       /* the side nearer the bank: 1 = right */
    /* 0x84 */ s16 state;
    /* 0x86 */ s16 unk86;      /* 2: the raft bumped (the riders lose a coin) */
    /* 0x88 */ s16 unk88;
    /* 0x8A */ s16 shake;
    /* 0x8C */ u16 unk8C;
    /* 0x8E */ s16 unk8E;
} PBRaft; /* size = 0x90 (N64) */

/* A rider (D_800FFFA0_PaddleBattle[4], indexed by player). */
typedef struct PBPlayer {
    /* 0x00 */ omObjData* obj;
    /* 0x04 */ s16 seat;
    /* 0x06 */ s16 state;
    /* 0x08 */ u16 timer;
    /* 0x0A */ char pad0A[2];
    /* 0x0C */ s16 hit;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 power;      /* paddling strength, eased */
    /* 0x18 */ f32 unk18;      /* paddle-sound accumulator */
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ u8 stroke;      /* paddled this frame */
    /* 0x1F */ char pad1F[1];
    /* 0x20 */ u8 lastDir;     /* last stick direction (1-4) */
    /* 0x21 */ u8 ringIdx;
    /* 0x22 */ u8 ring[64];    /* stick-direction history (a circle is a stroke) */
    /* 0x62 */ char pad62[2];
} PBPlayer; /* size = 0x64 (N64) */

/* A coin sprite (D_800FF3B0_PaddleBattle[32]). No pointers. */
typedef struct PBCoin {
    /* 0x00 */ s16 flags;      /* 0x80 used, 1 visible, 2 screen coordinates */
    /* 0x02 */ s16 player;
    /* 0x04 */ s16 type;       /* 0 flying coin, 1 sparkle */
    /* 0x06 */ char pad06[2];
    /* 0x08 */ Vec pos;
    /* 0x14 */ Vec vel;
    /* 0x20 */ Vec ref;        /* the player's last position (the coin follows it) */
    /* 0x2C */ f32 scale;
    /* 0x30 */ u16 sprite;
    /* 0x32 */ u16 frame;
    /* 0x34 */ s16 bounces;
    /* 0x36 */ s16 life;
    /* 0x38 */ u16 anim;
    /* 0x3A */ char pad3A[2];
} PBCoin; /* size = 0x3C */

/* A coin type (D_800FEA58_PaddleBattle[2]). */
typedef struct PBCoinType {
    /* 0x00 */ s16 sprite;
    /* 0x02 */ s16 frame;
    /* 0x04 */ s16 scale;      /* percent */
    /* 0x06 */ s16 life;
    /* 0x08 */ s16 flags;
    /* 0x0A */ char pad0A[2];
} PBCoinType; /* size = 0xC */

/* A collision face (func_800FD714): plane and corner vertex indices. No pointers. */
typedef struct PBColFace {
    /* 0x00 */ f32 nx;
    /* 0x04 */ f32 ny;
    /* 0x08 */ f32 nz;
    /* 0x0C */ f32 d;
    /* 0x10 */ s16 v[4];       /* v[3] = -1 for a triangle */
    /* 0x18 */ s16 axis;       /* dominant normal axis: 0 x, 1 y, 2 z */
    /* 0x1A */ char pad1A[2];
} PBColFace; /* size = 0x1C */

/* A model group's collision faces (PBCol.groups). */
typedef struct PBColGroup {
    /* 0x00 */ s16 n;
    /* 0x02 */ s16 radius;
    /* 0x04 */ PBColFace* faces;
} PBColGroup; /* size = 0x8 (N64) */

/* A model registered for collision (D_800FFBF0_PaddleBattle[64]). */
typedef struct PBCol {
    /* 0x00 */ s16 model;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 count;       /* groups */
    /* 0x04 */ PBColGroup* groups;
    /* 0x08 */ unk2C0C0StructA0* verts;
} PBCol; /* size = 0xC (N64) */

/* A rock in the river (D_800FEA80_PaddleBattle[4]). */
typedef struct PBRock {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 z;
} PBRock;

/* A range of river distance (D_800FE1F4 / D_800FE9FC). */
typedef struct PBRange {
    /* 0x00 */ s16 start;
    /* 0x02 */ s16 end;
} PBRange;

/* The bystanders' stretches of river and the stick-circle patterns (D_800FE9FC_PaddleBattle).
   func_800F9A00 reads range[] past its 4 entries once the raft is through (into ccw[]); the
   struct keeps those reads inside the object on the host too. */
typedef struct PBTables {
    /* 0x00 */ PBRange range[4];
    /* 0x10 */ u8 ccw[10];     /* counter-clockwise stick sequence, indexed from 4 - dir */
    /* 0x1A */ u8 cw[10];      /* clockwise, indexed from dir */
} PBTables; /* size = 0x24 */

/* A placed scenery model (D_800FEAA0_PaddleBattle[15]). */
typedef struct PBScenery {
    /* 0x00 */ Vec scale;
    /* 0x0C */ Vec rot;
    /* 0x18 */ Vec pos;
} PBScenery; /* size = 0x24 */

/* A paddler/oar object's work (func_80023684(0xE8)): src/99E0.c's MgWork layout, the fields
   this overlay touches; its pointers sit where MgWork's do, so main code reads it correctly. */
typedef struct PBMgWork {
    /* 0x00 */ char unk_00[0xB8];
    /* 0xB8 */ void* unk_B8;
    /* 0xBC */ char unk_BC[4];
    /* 0xC0 */ u16 unk_C0;
    /* 0xC2 */ char unk_C2[0x16];
    /* 0xD8 */ void* unk_D8;
    /* 0xDC */ void* unk_DC;
    /* 0xE0 */ char unk_E0[8];
} PBMgWork; /* size = 0xE8 (N64) */

/* A light-ring object's work (func_800FC39C, func_80023684(0x2C)). No pointers. */
typedef struct PBRingWork {
    /* 0x00 */ char pad00[5];
    /* 0x05 */ u8 idx;
    /* 0x06 */ char pad06[2];
    /* 0x08 */ f32 scale;
    /* 0x0C */ char pad0C[8];
    /* 0x14 */ f32 height;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ char pad28[4];
} PBRingWork; /* size = 0x2C */

/* Game flow (D_800FFF02_PaddleBattle). */
typedef struct PBFlow {
    /* 0x00 */ s16 state;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 timer;
    /* 0x06 */ s16 timer2;
} PBFlow;

/* ---------------------------------------------------------------------------------------------
   Main code without a shared prototype
   --------------------------------------------------------------------------------------------- */

extern u8 D_800F64F8;
extern u16 D_800EE984;
extern s8 ContStkY[];
extern u8 D_800F37DA;
void omInitObjMan(s32, s32);
void MtxRotateY(Matrix4f, f32);
void MtxRotateZ(Matrix4f, f32);
void MtxRotate(Matrix4f, f32, f32, f32);
void guMtxCatF(Matrix4f, Matrix4f, Matrix4f);
void guRotateF(Matrix4f, f32, f32, f32, f32);
void guTranslateF(Matrix4f, f32, f32, f32);
void func_80017BB0(omObjData*);
void func_80017C0C(omObjData*, u8, f32, f32, f32, f32, f32);
s32 func_800185A4(omObjData*, u16);
void func_80023A38(void*, void*, s32);
s16 func_80024198(u32, Gfx*, s32); /* src/24740.c */
s16 func_80024464(s16, s8);
void func_80027E48(s16, f32, f32, u16, u16, char*, u8);
void func_8006035C(s16, s8);
void func_80060F04(s16, s16, s16, s16);
unk65770Anim* func_80067310(s16);
f64 func_8009B618(f64, f64); /* fmod */
f64 func_8009B6F0(f64);      /* floor */

/* ---------------------------------------------------------------------------------------------
   Overlay functions
   --------------------------------------------------------------------------------------------- */

void func_800F65E0_PaddleBattle(void);
void func_800F687C_PaddleBattle(omObjData*);
void func_800F68B4_PaddleBattle(omObjData*);
s16 func_800F68E8_PaddleBattle(s16, s16);
void func_800F695C_PaddleBattle(omObjData*);
void func_800F6DB0_PaddleBattle(void);
void func_800F7310_PaddleBattle(void);
void func_800F732C_PaddleBattle(void);
void func_800F7380_PaddleBattle(void);
void func_800F74F4_PaddleBattle(omObjData*);
void func_800F76B8_PaddleBattle(omObjData*);
void func_800F86A8_PaddleBattle(s16, f32);
void func_800F86D0_PaddleBattle(omObjData*);
s16 func_800F89F0_PaddleBattle(u8*, u8, u8, u8);
void func_800F8B0C_PaddleBattle(omObjData*);
void func_800F94B8_PaddleBattle(omObjData*);
void func_800F9620_PaddleBattle(omObjData*);
void func_800F98AC_PaddleBattle(omObjData*);
void func_800F9A00_PaddleBattle(omObjData*);
void func_800FA108_PaddleBattle(void);
void func_800FA288_PaddleBattle(omObjData*);
void func_800FA298_PaddleBattle(f32, f32, f32, s16);
void func_800FA308_PaddleBattle(s16, Vec*, s16);
void func_800FA5EC_PaddleBattle(omObjData*);
s16 func_800FABAC_PaddleBattle(f32, f32*);
void func_800FAC70_PaddleBattle(f32, f32, Vec*);
f32 func_800FAE48_PaddleBattle(f32);
void func_800FAFEC_PaddleBattle(f32, f32, Vec*);
s16 func_800FB1E8_PaddleBattle(Vec*, Vec*, f32, Matrix4f);
f32 func_800FB554_PaddleBattle(f32, f32, Vec*);
s16 func_800FB704_PaddleBattle(s32);
f32 func_800FB74C_PaddleBattle(f32, f32, f32);
void func_800FB868_PaddleBattle(s16, Vec*, Vec*);
void func_800FBA44_PaddleBattle(Matrix4f, f32, f32, f32, Vec*);
void func_800FBAE0_PaddleBattle(void);
void func_800FBBD8_PaddleBattle(void);
void func_800FBC00_PaddleBattle(omObjData*);
void func_800FBEE8_PaddleBattle(omObjData*);
void func_800FC39C_PaddleBattle(omObjData*);
void func_800FC784_PaddleBattle(omObjData*);
s16 func_800FCC04_PaddleBattle(Vtx*, unk65770Anim*);
void func_800FD0B0_PaddleBattle(omObjData*);
void func_800FD29C_PaddleBattle(omObjData*);
void func_800FD3A8_PaddleBattle(omObjData*);
void func_800FD418_PaddleBattle(void);
void func_800FD424_PaddleBattle(void);
void func_800FD51C_PaddleBattle(s16);
void func_800FD570_PaddleBattle(PBCol*, s16);
s16 func_800FD714_PaddleBattle(unk2C0C0StructA0*, PBColFace*, unk2C0C0Struct20*, s16);
s32 func_800FDBB8_PaddleBattle(Vec*, f32, f32, f32, s16);
void func_800FDE08_PaddleBattle(PBColFace*, s16, Vec*, Vec*);

/* ---------------------------------------------------------------------------------------------
   .data (2341E0: 0x800FE1F0..0x800FE210; 234F80: 0x800FE210..0x800FEDB0)
   --------------------------------------------------------------------------------------------- */

extern s16 D_800FE1F0_PaddleBattle;          /* delay before the winners' voice */
extern PBRange D_800FE1F4_PaddleBattle[3];   /* rapids (the water-noise volume rises there) */
extern f32 D_800FE200_PaddleBattle;          /* paddle-noise volume */

extern Vec D_800FE210_PaddleBattle[84];      /* left bank, spline control points */
extern Vec D_800FE600_PaddleBattle[84];      /* right bank */
extern s16 D_800FE9F8_PaddleBattle;          /* control points */
extern PBTables D_800FE9FC_PaddleBattle;
extern Vec D_800FEA20_PaddleBattle[4];       /* seat offsets on the raft */
extern u16 D_800FEA50_PaddleBattle;        /* paddle objects created */
extern s16 D_800FEA52_PaddleBattle;
extern s16 D_800FEA54_PaddleBattle[2];
extern PBCoinType D_800FEA58_PaddleBattle[2];
extern u8 D_800FEA70_PaddleBattle[8];
extern s16 D_800FEA78_PaddleBattle[4];
extern PBRock D_800FEA80_PaddleBattle[4];
extern PBScenery D_800FEAA0_PaddleBattle[15];
extern f32 D_800FECBC_PaddleBattle;
extern f32 D_800FECC0_PaddleBattle;
extern char D_800FECC4_PaddleBattle[21][8];
extern Vtx_t D_800FED6C_PaddleBattle[4]; /* Vtx_t: word-aligned, as in the ROM */

/* ---------------------------------------------------------------------------------------------
   .bss
   --------------------------------------------------------------------------------------------- */

extern s16 D_800FF340_PaddleBattle;          /* leave the minigame */
extern s16 D_800FF342_PaddleBattle[4];       /* coins per player */
extern s16 D_800FF34A_PaddleBattle;          /* sound handles */
extern s16 D_800FF34C_PaddleBattle;
extern s16 D_800FF34E_PaddleBattle;
extern s16 D_800FF350_PaddleBattle;
extern s16 D_800FF352_PaddleBattle;
extern Vec D_800FF360_PaddleBattle[6];       /* func_800FB1E8: three (current, target) pairs */
extern PBCoin D_800FF3B0_PaddleBattle[32];
extern s16 D_800FFB30_PaddleBattle;
extern s16 D_800FFB32_PaddleBattle;
extern s16 D_800FFB34_PaddleBattle;
extern s16 D_800FFB36_PaddleBattle;
extern s16 D_800FFB38_PaddleBattle;
extern s16 D_800FFB3A_PaddleBattle;
extern s16 D_800FFB3C_PaddleBattle;
extern s16 D_800FFB40_PaddleBattle[8];
extern s16 D_800FFB50_PaddleBattle;
extern s16 D_800FFB52_PaddleBattle;
extern s16 D_800FFB60_PaddleBattle;
extern s16 D_800FFB62_PaddleBattle;
extern s16 D_800FFB64_PaddleBattle;
extern u16 D_800FFB68_PaddleBattle[8][2];    /* func_80039C48("sin_dmy_DEF") */
extern f32 D_800FFB88_PaddleBattle[8];
extern f32 D_800FFBA8_PaddleBattle[8];
extern omObjData* D_800FFBC8_PaddleBattle[8];
extern s16 D_800FFBE8_PaddleBattle;
extern s16 D_800FFBEA_PaddleBattle;          /* light rings created (the ring's index is its low byte) */
extern omObjData* D_800FFBEC_PaddleBattle;
extern PBCol D_800FFBF0_PaddleBattle[64];
extern s16 D_800FFEF0_PaddleBattle;
extern unk2C0C0StructA0* D_800FFEF4_PaddleBattle;
extern f32 D_800FFEF8_PaddleBattle;
extern s16 D_800FFF00_PaddleBattle;          /* demo play (no voices, no coins) */
extern PBFlow D_800FFF02_PaddleBattle;
extern PBRaft D_800FFF10_PaddleBattle;
extern PBPlayer D_800FFFA0_PaddleBattle[4];
extern s16 D_80100130_PaddleBattle[4];       /* coins won per player */

#endif
