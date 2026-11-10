#ifndef RESULTSETERNALSTAR2_H
#define RESULTSETERNALSTAR2_H

#include "common.h"
#include "PR/os.h"

void func_8004F548(void);
void func_800532E0(void);
void func_8004B7F8(s32);

void func_800F678C_ResultsEternalStar2(omObjData*);
void func_800F6988_ResultsEternalStar2(void);
void func_800F6C70_ResultsEternalStar2(void);
void func_800F7324_ResultsEternalStar2(void);
void func_800F7C28_ResultsEternalStar2(void);
void func_800F7D94_ResultsEternalStar2(void);
void func_800F7F1C_ResultsEternalStar2(void);
void func_800F8990_ResultsEternalStar2(void);
void func_800F8CFC_ResultsEternalStar2(void);
void func_800F8EB8_ResultsEternalStar2(void);
void func_800F9250_ResultsEternalStar2(void);
void func_800F95F8_ResultsEternalStar2(void);
void func_800F972C_ResultsEternalStar2(void);
void func_800F9860_ResultsEternalStar2(omObjData*);
void func_800F9C74_ResultsEternalStar2(omObjData*);
void func_800FA08C_ResultsEternalStar2(omObjData*);
void func_800FA200_ResultsEternalStar2(omObjData*);
void func_800FA3A4_ResultsEternalStar2(omObjData*);
void func_800FA5E0_ResultsEternalStar2(s32);
void func_800FA61C_ResultsEternalStar2(void);
void func_800FB0A4_ResultsEternalStar2(void);
void func_800FB76C_ResultsEternalStar2(omObjData*);
void func_800FB8E4_ResultsEternalStar2(omObjData*);
void func_800FB930_ResultsEternalStar2(void);
void func_800FBE58_ResultsEternalStar2(void);
void func_800FBF78_ResultsEternalStar2(void);
void func_800FC090_ResultsEternalStar2(void);

/* The head of 42E40.c's SpriteAnimWork (func_800429CC's result); no pointers before 0x10. */
typedef struct ResSpriteAnim {
    /* 0x00 */ u16 flags;
    /* 0x02 */ s16 frame;
    /* 0x04 */ s16 count;
    /* 0x06 */ u16 attr;
    /* 0x08 */ s16 x;
    /* 0x0A */ s16 y;
    /* 0x0C */ f32 scale;
} ResSpriteAnim;

void* func_800429CC(s16, s16);
s32 func_8004F628(s32, u16, s16, s16);
void func_8004F7C0(s32, f32, f32);
void func_80042B10(ResSpriteAnim*);
void func_8004F584(s32);
void func_8004F754(s32, s16, s16);
void func_8004F860(s32, s32);
void func_80054744(s32, s8);
void func_800596DC(s16, s16);
void func_80059578(s16);
s16 GetSumOfPlayerStars(void);
void func_800532F4(void);
void MBModelClose(void);
/* Retail called these unprototyped (arguments arrive promoted, not narrowed to the definition's
   s16/s8: func_8004F754's x, func_80054744's index, func_800596DC's u16 value); the host calls
   them normally. */
#define func_8004F754_unproto(spr, x, y) ((void (*)())func_8004F754)(spr, x, y)
#define func_80054744_unproto(a, b) ((void (*)())func_80054744)(a, b)
#define func_800596DC_unproto(a, b) ((void (*)())func_800596DC)(a, b)

/* .data */
extern s32 D_800FC0C0_ResultsEternalStar2; /* sound pacing for the falling coins */
extern Vec3f D_800FC0C4_ResultsEternalStar2; /* the star pile centre */
extern Vec3f D_800FC0DC_ResultsEternalStar2[3]; /* coin start points (x used; [0].y = the reset height) */
extern s32 D_800FC370_ResultsEternalStar2; /* next coin model (0..19) */
extern Vec3f D_800FC100_ResultsEternalStar2;
extern s32 D_800FC374_ResultsEternalStar2[3];
extern s32 D_800FC138_ResultsEternalStar2[4];
extern Vec3f D_800FC0D0_ResultsEternalStar2; /* the roulette's three message ids */
extern const char D_800FC3C4_ResultsEternalStar2[];
extern s32 D_800FC150_ResultsEternalStar2; /* first stats row shown (0..7) */
extern s32 D_800FC154_ResultsEternalStar2;
extern f32 D_800FC148_ResultsEternalStar2[2];
extern s16 D_800FC158_ResultsEternalStar2[4][2];
extern s16 D_800FC168_ResultsEternalStar2[4][2];
extern s16 D_800FC178_ResultsEternalStar2[4][2];
extern s16 D_800FC188_ResultsEternalStar2[4][2];
extern s16 D_800FC198_ResultsEternalStar2[4][2];
extern s16 D_800FC1A8_ResultsEternalStar2[2];
extern s16 D_800FC1AC_ResultsEternalStar2[2];
extern s16 D_800FC1B0_ResultsEternalStar2[2][2];
extern f32 D_800FC1B8_ResultsEternalStar2[11];
extern s32 D_800FC1E4_ResultsEternalStar2[11];
extern s32 D_800FC210_ResultsEternalStar2[2];
extern s32 D_800FC218_ResultsEternalStar2[3];
extern s32 D_800FC224_ResultsEternalStar2[8];
extern s32 D_800FC244_ResultsEternalStar2[6];
extern s32 D_800FC25C_ResultsEternalStar2[6];
extern s32 D_800FC274_ResultsEternalStar2[11];
extern s32 D_800FC10C_ResultsEternalStar2[];
extern char* D_800FC2A0_ResultsEternalStar2;
extern s16 D_800FC2A4_ResultsEternalStar2[2];
extern s16 D_800FC2A8_ResultsEternalStar2[4][2];
extern s16 D_800FC2B8_ResultsEternalStar2[4][2];
extern s16 D_800FC2C8_ResultsEternalStar2[4][2];
extern s16 D_800FC2D8_ResultsEternalStar2[4][2];
extern s16 D_800FC2E8_ResultsEternalStar2[4][2];
extern s16 D_800FC2F8_ResultsEternalStar2[4][2];
extern s16 D_800FC308_ResultsEternalStar2[4][2];
extern s16 D_800FC318_ResultsEternalStar2[8][2];
extern s16 D_800FC338_ResultsEternalStar2[8][2];
extern s32 D_800FC358_ResultsEternalStar2[6];

/* .bss. The s32 sprite/window id slots are read as their low half, (s16)X. */
extern Object* D_800FC410_ResultsEternalStar2;
extern Object* D_800FC418_ResultsEternalStar2[0x14];
extern Object* D_800FC468_ResultsEternalStar2[7];
extern Process* D_800FC488_ResultsEternalStar2[2];
extern s32 D_800FC4A0_ResultsEternalStar2[4];
extern s32 D_800FC4B0_ResultsEternalStar2;
extern s32 D_800FC4B4_ResultsEternalStar2;
extern s32 D_800FC4B8_ResultsEternalStar2;
extern s32 D_800FC4BC_ResultsEternalStar2[3];
extern s32 D_800FC4C8_ResultsEternalStar2[2];
extern s32 D_800FC4E0_ResultsEternalStar2[1];
extern void* D_800FC4E8_ResultsEternalStar2[7];
extern s32 D_800FC508_ResultsEternalStar2[4]; /* the stars before the bonus stars */
extern unkCommonStruct0 D_800FC518_ResultsEternalStar2[2]; /* splat: D_800FC4A8, D_800FC510 */
extern s32 D_800FC5E8_ResultsEternalStar2;
extern s32 D_800FC5F0_ResultsEternalStar2[4];
extern s32 D_800FC600_ResultsEternalStar2;
extern s32 D_800FC608_ResultsEternalStar2[4];
extern s32 D_800FC618_ResultsEternalStar2;
extern s32 D_800FC61C_ResultsEternalStar2;
extern s32 D_800FC620_ResultsEternalStar2;
extern s32 D_800FC624_ResultsEternalStar2;
extern s32 D_800FC628_ResultsEternalStar2;
extern s32 D_800FC62C_ResultsEternalStar2;
extern s32 D_800FC630_ResultsEternalStar2;
extern s32 D_800FC634_ResultsEternalStar2[2];
extern s32 D_800FC63C_ResultsEternalStar2;
extern s32 D_800FC640_ResultsEternalStar2[11];
extern mystery_struct_ret_func_80048224* D_800FC66C_ResultsEternalStar2;
extern s32 D_800FC670_ResultsEternalStar2[11];
extern u8 D_800FC6A0_ResultsEternalStar2[11][4][8]; /* the stats table's digits */
extern omObjData* D_800FC800_ResultsEternalStar2;
extern unkCommonStruct0 D_800FC808_ResultsEternalStar2;
extern s32 D_800FC870_ResultsEternalStar2;
extern s32 D_800FC878_ResultsEternalStar2[4];
extern ResSpriteAnim* D_800FC888_ResultsEternalStar2[4];
extern s32 D_800FC898_ResultsEternalStar2[4];
extern s32 D_800FC8A8_ResultsEternalStar2[4];
extern s32 D_800FC8B8_ResultsEternalStar2;
extern s32 D_800FC8BC_ResultsEternalStar2;
extern s32 D_800FC8C0_ResultsEternalStar2;
extern s32 D_800FC8C4_ResultsEternalStar2;
extern unkCommonStruct0 D_800FC8C8_ResultsEternalStar2[8];
extern s32 D_800FCC08_ResultsEternalStar2;

extern TextWindow* D_800ED4B0;
extern u16 D_800F2CF0[4];
void func_80067284(s16, s16, f32);
void func_80071DE0(s32);
void func_80072108(s16, s32);

#endif
