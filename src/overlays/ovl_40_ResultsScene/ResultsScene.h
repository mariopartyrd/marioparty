#ifndef RESULTSSCENE_H
#define RESULTSSCENE_H

#include "common.h"
#include "PR/os.h"

void func_8004F548(void);
void func_800532E0(void);
void func_8004B7F8(s32);

void func_800F678C_ResultsScene(omObjData*);
void func_800F6988_ResultsScene(void);
void func_800F6C70_ResultsScene(void);
void func_800F7324_ResultsScene(void);
void func_800F7C28_ResultsScene(void);
void func_800F7D94_ResultsScene(void);
void func_800F7F1C_ResultsScene(void);
void func_800F8990_ResultsScene(void);
void func_800F8CFC_ResultsScene(void);
void func_800F8EB8_ResultsScene(void);
void func_800F9250_ResultsScene(void);
void func_800F95F8_ResultsScene(void);
void func_800F972C_ResultsScene(void);
void func_800F9860_ResultsScene(omObjData*);
void func_800F9C74_ResultsScene(omObjData*);
void func_800FA08C_ResultsScene(omObjData*);
void func_800FA200_ResultsScene(omObjData*);
void func_800FA3A4_ResultsScene(omObjData*);
void func_800FA5E0_ResultsScene(s32);
void func_800FA61C_ResultsScene(void);
void func_800FB054_ResultsScene(void);
void func_800FB71C_ResultsScene(omObjData*);
void func_800FB87C_ResultsScene(omObjData*);
void func_800FB8C8_ResultsScene(void);
void func_800FBDF0_ResultsScene(void);
void func_800FBF10_ResultsScene(void);
void func_800FC028_ResultsScene(void);

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
extern s32 D_800FC050_ResultsScene; /* sound pacing for the falling coins */
extern Vec3f D_800FC054_ResultsScene; /* the star pile centre */
extern Vec3f D_800FC06C_ResultsScene[3]; /* coin start points (x used; [0].y = the reset height) */
extern s32 D_800FC300_ResultsScene; /* next coin model (0..19) */
extern Vec3f D_800FC090_ResultsScene;
extern s32 D_800FC304_ResultsScene[3];
extern s32 D_800FC0C8_ResultsScene[4];
extern Vec3f D_800FC060_ResultsScene; /* the roulette's three message ids */
extern const char D_800FC354_ResultsScene[];
extern s32 D_800FC0E0_ResultsScene; /* first stats row shown (0..7) */
extern s32 D_800FC0E4_ResultsScene;
extern f32 D_800FC0D8_ResultsScene[2];
extern s16 D_800FC0E8_ResultsScene[4][2];
extern s16 D_800FC0F8_ResultsScene[4][2];
extern s16 D_800FC108_ResultsScene[4][2];
extern s16 D_800FC118_ResultsScene[4][2];
extern s16 D_800FC128_ResultsScene[4][2];
extern s16 D_800FC138_ResultsScene[2];
extern s16 D_800FC13C_ResultsScene[2];
extern s16 D_800FC140_ResultsScene[2][2];
extern f32 D_800FC148_ResultsScene[11];
extern s32 D_800FC174_ResultsScene[11];
extern s32 D_800FC1A0_ResultsScene[2];
extern s32 D_800FC1A8_ResultsScene[3];
extern s32 D_800FC1B4_ResultsScene[8];
extern s32 D_800FC1D4_ResultsScene[6];
extern s32 D_800FC1EC_ResultsScene[6];
extern s32 D_800FC204_ResultsScene[11];
extern s32 D_800FC09C_ResultsScene[];
extern char* D_800FC230_ResultsScene;
extern s16 D_800FC234_ResultsScene[2];
extern s16 D_800FC238_ResultsScene[4][2];
extern s16 D_800FC248_ResultsScene[4][2];
extern s16 D_800FC258_ResultsScene[4][2];
extern s16 D_800FC268_ResultsScene[4][2];
extern s16 D_800FC278_ResultsScene[4][2];
extern s16 D_800FC288_ResultsScene[4][2];
extern s16 D_800FC298_ResultsScene[4][2];
extern s16 D_800FC2A8_ResultsScene[8][2];
extern s16 D_800FC2C8_ResultsScene[8][2];
extern s32 D_800FC2E8_ResultsScene[6];

/* .bss. The s32 sprite/window id slots are read as their low half, (s16)X. */
extern Object* D_800FC3A0_ResultsScene;
extern Object* D_800FC3A8_ResultsScene[0x14];
extern Object* D_800FC3F8_ResultsScene[7];
extern Process* D_800FC418_ResultsScene[2];
extern s32 D_800FC430_ResultsScene[4];
extern s32 D_800FC440_ResultsScene;
extern s32 D_800FC444_ResultsScene;
extern s32 D_800FC448_ResultsScene;
extern s32 D_800FC44C_ResultsScene[3];
extern s32 D_800FC458_ResultsScene[2];
extern s32 D_800FC470_ResultsScene[1];
extern void* D_800FC478_ResultsScene[7];
extern s32 D_800FC498_ResultsScene[4]; /* the stars before the bonus stars */
extern unkCommonStruct0 D_800FC4A8_ResultsScene[2]; /* splat: D_800FC4A8, D_800FC510 */
extern s32 D_800FC578_ResultsScene;
extern s32 D_800FC580_ResultsScene[4];
extern s32 D_800FC590_ResultsScene;
extern s32 D_800FC598_ResultsScene[4];
extern s32 D_800FC5A8_ResultsScene;
extern s32 D_800FC5AC_ResultsScene;
extern s32 D_800FC5B0_ResultsScene;
extern s32 D_800FC5B4_ResultsScene;
extern s32 D_800FC5B8_ResultsScene;
extern s32 D_800FC5BC_ResultsScene;
extern s32 D_800FC5C0_ResultsScene;
extern s32 D_800FC5C4_ResultsScene[2];
extern s32 D_800FC5CC_ResultsScene;
extern s32 D_800FC5D0_ResultsScene[11];
extern mystery_struct_ret_func_80048224* D_800FC5FC_ResultsScene;
extern s32 D_800FC600_ResultsScene[11];
extern u8 D_800FC630_ResultsScene[11][4][8]; /* the stats table's digits */
extern omObjData* D_800FC790_ResultsScene;
extern unkCommonStruct0 D_800FC798_ResultsScene;
extern s32 D_800FC800_ResultsScene;
extern s32 D_800FC808_ResultsScene[4];
extern ResSpriteAnim* D_800FC818_ResultsScene[4];
extern s32 D_800FC828_ResultsScene[4];
extern s32 D_800FC838_ResultsScene[4];
extern s32 D_800FC848_ResultsScene;
extern s32 D_800FC84C_ResultsScene;
extern s32 D_800FC850_ResultsScene;
extern s32 D_800FC854_ResultsScene;
extern unkCommonStruct0 D_800FC858_ResultsScene[8];
extern s32 D_800FCB98_ResultsScene;

extern TextWindow* D_800ED4B0;
extern u16 D_800F2CF0[4];
void func_80067284(s16, s16, f32);
void func_80071DE0(s32);
void func_80072108(s16, s32);

#endif
