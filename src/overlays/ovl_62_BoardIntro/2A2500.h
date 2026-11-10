#ifndef _2A2500_H
#define _2A2500_H

#include "common.h"

/* Screen position of a board-name sprite: two per board (indexed by D_801102B0 * 2 + n). */
typedef struct BoardIntroPos {
    s16 x;
    s16 y;
} BoardIntroPos;

void func_800F6660_BoardIntro(s32, s32);
void func_800F8DC8_BoardIntro(void);
void func_800F906C_BoardIntro(void);
void func_800F9200_BoardIntro(void);
s32 func_800F67F8_BoardIntro(s32);
s32 func_800F684C_BoardIntro(void);
void func_800F8FEC_BoardIntro(omObjData*);

void func_8004F584(s32);
s32 func_8004F628(s32, u16, s16, s16);
/* Defined with s16 coordinates (4E530.c); retail calls it with s32 values and no narrowing at the
   call, so the matching build declares s32 parameters. The host uses the real prototype. */
void func_8004F754(s32, s32, s32);
void func_8004F7C0(s32, f32, f32);

void func_800F677C_BoardIntro(omObjData*);
void func_8004F548(void);
void func_800F7538_BoardIntro(void);
void func_800F7B5C_BoardIntro(void);
void func_800F8090_BoardIntro(void);
void func_800F8334_BoardIntro(void);
void func_800F8F38_BoardIntro(omObjData*);
void func_800F9098_BoardIntro(void);
void func_800F9298_BoardIntro(void);
void func_800F7858_BoardIntro(omObjData*);
void func_800F7988_BoardIntro(omObjData*);
void func_80052DC8(s16, void*);
void HidePlayerHUDVisibility(s32, s32);
void func_8003FC94(void);
void func_8003FD68(s32);
void func_80040590(s32);
void func_80040780(s32);
void func_8004157C(void);
s32 func_800415E8(s32);
void func_80055810(s32, s32, s32);
extern char* D_800C5218[]; /* character names */

/* Retail passes the s32 window id unnarrowed (an unprototyped call); the host calls it normally. */
#define WaitForTextConfirmation_s32(win) ((void (*)())WaitForTextConfirmation)(win)

/* Name-letter objects (func_800F677C), indexed by letter; work[0] holds index + 1. */
extern omObjData* D_800FCD30_BoardIntro[16];
extern omObjData* D_800FCD98_BoardIntro[4]; /* splat split [1..3] off as D_800FCD9C */
extern s32 D_800FCDAC_BoardIntro;
extern s32 D_800FCDB0_BoardIntro;
/* Per board (D_801102B0). */
extern s32 D_800FCDB8_BoardIntro[8];      /* background index */
extern s32 D_800FCDD8_BoardIntro[9];      /* background index (second scene) */
extern u8 D_800FCDFC_BoardIntro[8];       /* board-name length */
extern char* D_800FCE04_BoardIntro[8];    /* board-name strings */
extern Vec3f D_800FCE24_BoardIntro[9];    /* splat split .y/.z as D_800FCE28/2C */
extern Vec3f D_800FD04C_BoardIntro[9][4]; /* per board, per player */
extern Vec3f D_800FD1FC_BoardIntro[9][4]; /* per board, per player */
extern Vec3f D_800FCE90_BoardIntro;       /* splat split .y as D_800FCE94 */
extern Vec3f D_800FCE9C_BoardIntro[9][4]; /* per board, per player; splat split .y/.z as D_800FCEA0/A4 */
/* Per-character motion lists (count word, then file ids), indexed by GwPlayer[].character. */
extern s32* D_800FD510_BoardIntro[6];
extern s32 D_800FD538_BoardIntro[4];      /* MBModelCreate motion list */
extern u8 D_800FD548_BoardIntro[12];
extern BoardIntroPos D_800FD554_BoardIntro[18];
extern s32 D_800FD59C_BoardIntro[18];
extern s32 D_800FD3AC_BoardIntro[8];      /* board message ids */
extern void (*D_800FD5E4_BoardIntro[9])(void);
extern u8 D_800FD608_BoardIntro[8];       /* text window size */
extern u8 D_800FD610_BoardIntro[8];
extern void (*D_800FD618_BoardIntro[9])(void);
extern void (*D_800FD63C_BoardIntro[9])(void);

#define BI_SPRITE(i) (D_800FCD78_BoardIntro[i])
#define BI_MODEL(i) (D_800FCD88_BoardIntro[i])

/* bss: the board-name message block (splat split its .unk_14 off as D_800FDA64). */
extern unkCommonStruct0 D_800FDA50_BoardIntro;

#endif
