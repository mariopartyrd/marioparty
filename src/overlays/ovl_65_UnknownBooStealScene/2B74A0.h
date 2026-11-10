#include "common.h"

/* a screen position / direction pair, one per player portrait corner */
typedef struct BooStealVec2f {
    f32 x;
    f32 y;
} BooStealVec2f;

extern Object* D_800F93D0_UnknownBooStealScene;
/* the choice to re-enter the scene with (0 none, 1 rules again, 2/3 a steal); retail also reads
   its low half (big-endian +2) as s16: written (s16)D_800F93D4 */
extern s32 D_800F93D4_UnknownBooStealScene;
extern void* D_800F93D8_UnknownBooStealScene;
extern u8 D_800F93DC_UnknownBooStealScene[4];
extern s32 D_800F93E0_UnknownBooStealScene[8];
extern Vec3f D_800F9400_UnknownBooStealScene[8];
extern Vec3f D_800F9460_UnknownBooStealScene[8];
extern u8 D_800F94C0_UnknownBooStealScene[4][3];
extern BooStealVec2f D_800F94CC_UnknownBooStealScene[4];
extern BooStealVec2f D_800F94EC_UnknownBooStealScene[4];
extern s32* D_800F956C_UnknownBooStealScene[6];
extern u8 D_800F9584_UnknownBooStealScene[3][4];

/* bss */
extern u8 D_800F9600_UnknownBooStealScene;  /* board index */
extern u8 D_800F9601_UnknownBooStealScene;  /* player index */
extern u8 D_800F9602_UnknownBooStealScene;  /* turn band 0-3 */
extern Object* D_800F9604_UnknownBooStealScene; /* Boo */
extern Object* D_800F9608_UnknownBooStealScene; /* player */
extern s32 D_800F9610_UnknownBooStealScene[4]; /* players by star rank (asm labels D_800F9614/18 are [1]/[2]) */
extern s32 D_800F9620_UnknownBooStealScene[4]; /* players by coin rank */
extern s32 D_800F9630_UnknownBooStealScene; /* CPU choice: 0 coins, 1 star, 2 nothing */
extern s32 D_800F9634_UnknownBooStealScene; /* CPU target player */
extern s32 D_800F9638_UnknownBooStealScene; /* CPU target rank */

s32 func_800F6734_UnknownBooStealScene(void);
void func_800F6788_UnknownBooStealScene(void);
s32 func_800F699C_UnknownBooStealScene(void);
void func_800F6B3C_UnknownBooStealScene(void);
void func_800F7278_UnknownBooStealScene(void);
s32 func_800F7648_UnknownBooStealScene(s32, u8*);
s32 func_800F78E0_UnknownBooStealScene(s32, s32, u8*);
void func_800F7B54_UnknownBooStealScene(s32, s32);
void func_800F884C_UnknownBooStealScene(void);
void func_800F8E9C_UnknownBooStealScene(omObjData*);
void func_800F8F18_UnknownBooStealScene(omObjData*);
void func_800F8F78_UnknownBooStealScene(omObjData*);
void func_800F9024_UnknownBooStealScene(void);
void func_800F91D0_UnknownBooStealScene(void);
void func_800F922C_UnknownBooStealScene(void);
void func_800F93A4_UnknownBooStealScene(void);

void func_80071788(s32, s16);
void func_8004DBD4(s32, u8);
void func_80055994(s32, s32);
void func_80055810(s32, s32, s32);
extern char* D_800C5218[]; /* character names */

/* Retail stores func_80023FC8's result without sign-extending it (an int-returning declaration). */
#define func_80023FC8_s32(id) ((s32 (*)(s16))func_80023FC8)(id)

/* Retail calls func_8006FCF0 unprototyped here: the window id and cursor are passed as s16 values
   promoted to int (sll/sra 16), not narrowed to the prototype's s8. The host calls it normally. */
#define func_8006FCF0_unproto(win, cur, arg) ((s32 (*)())func_8006FCF0)(win, cur, arg)
