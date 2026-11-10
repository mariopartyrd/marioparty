#ifndef UNUSEDMINIGAME1_H
#define UNUSEDMINIGAME1_H

/* ovl_08 UnusedMinigame1: an unused minigame (its overlay-table entry points elsewhere). Each
   player stops a stretching measuring machine as close as possible to a mark ("JUST!",
   "%d LEFT", "TOO FAR!", "TOO LATE!"); the closest get 10 coins. 110F90.c: setup and the main
   state machine; 111890.c: the characters at the top (one per player); 1127C0.c: the machines
   at the bottom (one per player) and the result; 113730.c: camera, random and projection helpers.
   Types come from the asm's accesses; N64 offsets are in the comments. */

#include "common.h"
#include "engine/pad.h"

/* A top character's work (func_80023684(0x30), memset). Also the face-sprite state of
   func_800F76E0. No pointers. */
typedef struct UM1Chara {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
    /* 0x0C */ f32 unkC;  /* x speed while knocked off; sprite scale in func_800F76E0 */
    /* 0x10 */ f32 unk10; /* y speed while knocked off */
    /* 0x14 */ f32 unk14; /* z rotation while knocked off */
    /* 0x18 */ f32 unk18; /* shadow y */
    /* 0x1C */ u16 unk1C; /* flags: 1 active, 2 sprite, 8 gone, 0x10 knocked off */
    /* 0x1E */ s16 unk1E; /* face texture */
    /* 0x20 */ s16 unk20; /* tear texture */
    /* 0x22 */ char unk22[2];
    /* 0x24 */ u16 unk24; /* sprite */
    /* 0x26 */ s16 unk26; /* sprite x */
    /* 0x28 */ s16 unk28; /* sprite y */
    /* 0x2A */ u16 unk2A; /* sprite alpha */
    /* 0x2C */ u8 unk2C;  /* sprite state */
    /* 0x2D */ u8 unk2D;  /* sprite timer */
    /* 0x2E */ u8 unk2E;
    /* 0x2F */ u8 unk2F;
} UM1Chara; /* size = 0x30 */

/* A machine's work (func_80023684(0x24), memset). No pointers. */
typedef struct UM1Machine {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
    /* 0x0C */ f32 unkC;  /* stretch */
    /* 0x10 */ f32 unk10; /* x of the arm's end */
    /* 0x14 */ s32 unk14; /* frame counter */
    /* 0x18 */ u16 unk18; /* flags: 1 stretching, 2 started, 4 result shown */
    /* 0x1A */ s16 unk1A; /* face texture */
    /* 0x1C */ s16 unk1C; /* tear texture */
    /* 0x1E */ char unk1E[2];
    /* 0x20 */ u8 unk20; /* player */
    /* 0x21 */ u8 unk21; /* face row (D_800F925C) */
    /* 0x22 */ s8 unk22; /* character */
    /* 0x23 */ s8 unk23; /* controller port */
} UM1Machine; /* size = 0x24 */

/* Texture size from func_80039C48 (D_800F943E). */
typedef struct UM1TexSize {
    /* 0x00 */ u16 w;
    /* 0x02 */ u16 h;
    /* 0x04 */ char unk4[2];
} UM1TexSize;

/* Per-character file ids (D_800F91B0[5], 0x18 each): face body1, body2, arm, face, then the
   face for "close" and for "far". */
typedef struct UM1Files {
    s32 body1;
    s32 body2;
    s32 arm;
    s32 face;
    s32 faceNear;
    s32 faceFar;
} UM1Files;

/* .data */
extern u16 D_800F9170_UnusedMinigame1;             /* 110F90.c: end request */
extern Vec D_800F9180_UnusedMinigame1[4];          /* 111890.c: character positions */
extern UM1Files D_800F91B0_UnusedMinigame1[5];     /* 111890.c */
extern f32 D_800F9230_UnusedMinigame1[6];          /* 1127C0.c: model y scale per character */
extern char* D_800F9248_UnusedMinigame1[5];        /* 1127C0.c: face texture names */
extern u8 D_800F925C_UnusedMinigame1[8];           /* 1127C0.c: face row per D_800F9492 entry */
extern Vec D_800F9264_UnusedMinigame1[4];          /* 1127C0.c: machine positions */
extern s32 D_800F92A0_UnusedMinigame1;             /* 113730.c: random seed */

/* .bss */
extern f32 D_800F9410_UnusedMinigame1;
extern f32 D_800F9414_UnusedMinigame1;
extern f32 D_800F9418_UnusedMinigame1;
extern u16 D_800F941C_UnusedMinigame1;
extern u16 D_800F941E_UnusedMinigame1;
extern u16 D_800F9420_UnusedMinigame1;
extern u16 D_800F9422_UnusedMinigame1;
extern u16 D_800F9424_UnusedMinigame1;
extern u16 D_800F9426_UnusedMinigame1;
extern s16 D_800F9430_UnusedMinigame1;
extern s16 D_800F9432_UnusedMinigame1;
extern s32 D_800F9434_UnusedMinigame1;
extern s32 D_800F9438_UnusedMinigame1;
extern s16 D_800F943C_UnusedMinigame1;
extern UM1TexSize D_800F943E_UnusedMinigame1;
extern f32 D_800F9444_UnusedMinigame1;
extern s16 D_800F9448_UnusedMinigame1;
extern s16 D_800F944A_UnusedMinigame1;
extern s16 D_800F9450_UnusedMinigame1;
extern s32 D_800F9454_UnusedMinigame1;
extern s16 D_800F9458_UnusedMinigame1[8]; /* splat labels D_800F945A/945E/9464 are [1]/[3]/[6] */
extern s16 D_800F9468_UnusedMinigame1;
extern s16 D_800F946A_UnusedMinigame1;    /* splat label D_800F946B is its low byte */
extern u16 D_800F946C_UnusedMinigame1;
extern s16 D_800F9470_UnusedMinigame1;
extern omObjData* D_800F9474_UnusedMinigame1;
extern omObjData* D_800F9480_UnusedMinigame1[4];
extern s16 D_800F9490_UnusedMinigame1;
extern u8 D_800F9492_UnusedMinigame1[4];
extern omObjData* D_800F9498_UnusedMinigame1[4];
extern s16 D_800F94A8_UnusedMinigame1;
extern f32 D_800F94AC_UnusedMinigame1;

/* main code */
extern u8 D_800C5982;
extern f32 D_800B895C;
void func_80025BB8(s16, s16);
void func_80027AC8(s16, u8*, u8*);
void func_80027E48(s16, f32, f32, u16, u16, char*, u8);
void func_8002859C(s16, s16, char*);
void func_800370D4(s16);
s16 func_80038D5C(unk2C0C0StructC0*, u16, s16, char*);
void func_8003967C(s16, u8);
void func_800399F0(s16);
f32 func_80025D18(s16);
f32 func_80025D40(s16);

/* 110F90.c */
void func_800F65E0_UnusedMinigame1(void);
void func_800F67B0_UnusedMinigame1(void);
void func_800F683C_UnusedMinigame1(omObjData* obj);
void func_800F6880_UnusedMinigame1(omObjData* obj);
u16 func_800F6A08_UnusedMinigame1(void);
void func_800F6C80_UnusedMinigame1(void);
void func_800F6D88_UnusedMinigame1(void);
void func_800F6E78_UnusedMinigame1(omObjData* obj);
void func_800F6ECC_UnusedMinigame1(void);

/* 111890.c */
void func_800F6EE0_UnusedMinigame1(void);
void func_800F6FC8_UnusedMinigame1(omObjData* obj);
void func_800F703C_UnusedMinigame1(omObjData* obj);
void func_800F7110_UnusedMinigame1(omObjData* obj);
void func_800F75A4_UnusedMinigame1(omObjData* obj);
void func_800F76E0_UnusedMinigame1(omObjData* obj);
void func_800F79F0_UnusedMinigame1(omObjData* obj);

/* 1127C0.c */
void func_800F7E10_UnusedMinigame1(omObjData* obj);
void func_800F84CC_UnusedMinigame1(void);
void func_800F85A0_UnusedMinigame1(void);
void func_800F8764_UnusedMinigame1(omObjData* obj);
void func_800F8A4C_UnusedMinigame1(omObjData* obj);
s32 func_800F8C44_UnusedMinigame1(omObjData* obj);
s32 func_800F8CD0_UnusedMinigame1(void);

/* 113730.c */
void func_800F8D80_UnusedMinigame1(f32 zoom, f32 rx, f32 ry, f32 rz, f32 cx, f32 cy, f32 cz);
s32 func_800F8E18_UnusedMinigame1(u32 seed);
void func_800F8EEC_UnusedMinigame1(void);
void func_800F8F14_UnusedMinigame1(Matrix4f m, Vec* in, Vec* out);
void func_800F8FC0_UnusedMinigame1(s16 cam, Vec* pos, f32* out);

#endif
