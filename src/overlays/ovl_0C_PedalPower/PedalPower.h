#include "common.h"

typedef struct UnkPedalPowerStruct {
    /* 0x00 */ char unk_00[0x22];
    /* 0x22 */ u8 unk_22;
    /* 0x23 */ char unk_23[0x49];
} UnkPedalPowerStruct; //sizeof 0x6C

/* The player's work block (func_800F8F9C, 0xEC bytes on the N64): MgWork's layout (src/99E0.c)
   with its pointers where MgWork has them, so the host layout agrees with the framework's view,
   plus the overlay's own byte at 0xE8 (1 = human, 0 = CPU). */
typedef struct PPWork {
    /* 0x00 */ char unk_00[0x56];
    /* 0x56 */ s8 unk_56; /* controller port */
    /* 0x57 */ char unk_57[0x61];
    /* 0xB8 */ void* unk_B8;
    /* 0xBC */ char unk_BC[0x1C];
    /* 0xD8 */ void* unk_D8; /* one s16 pair per motion */
    /* 0xDC */ void* unk_DC;
    /* 0xE0 */ char unk_E0[4];
    /* 0xE4 */ void* unk_E4;
    /* 0xE8 */ u8 unk_E8;
} PPWork; /* size = 0xEC */


void func_800F7DD4_PedalPower(omObjData*);
void func_800F6944_PedalPower(omObjData*);
void func_800F6ED0_PedalPower(omObjData*);
void func_800F6D2C_PedalPower(omObjData*);
void func_800F67AC_PedalPower(void);
void func_800F6870_PedalPower(void);
void func_800F6CF8_PedalPower(void);
void func_800F79B0_PedalPower(void);
void func_800F8EE0_PedalPower(void);

/* Main-code helpers (prototypes as in the linked minigames). */
void func_8006073C(void);
void func_8006035C(s16, s8);
void func_80060440(s16, s16);
s16 func_80060758(s16);
void func_80060F04(s16, s16, s16, s16);
void func_800090C4(omObjData* obj, u8 idx, u8 val);
void func_8000A6F4(omObjData* obj);
s16 func_80009E4C(s16 player, s16 limit, s8 x, s8 y);
f32 func_80025D90(s16);
f32 func_80025DD8(s16);
void func_80028498(s16, s16, s16);
void func_80028928(s16 arg0, s16 arg1, s16 arg2, s16 arg3);

/* .data */
extern u8 D_800F9E20_PedalPower;
extern f32 D_800F9E38_PedalPower[];
extern u16 D_800F9E50_PedalPower;
extern u8 D_800F9E52_PedalPower;

/* .rodata */
extern s32 D_800F9E90_PedalPower;

/* .bss */
extern s8 D_800F9EE0_PedalPower;
extern s8 D_800F9EE1_PedalPower;
extern f32 D_800F9EE4_PedalPower;
extern s32 D_800F9EE8_PedalPower;
extern s8 D_800F9EF0_PedalPower;
extern s8 D_800F9EF1_PedalPower;
extern s16 D_800F9EF2_PedalPower;
extern s16 D_800F9EF4_PedalPower;
extern u8 D_800F9F10_PedalPower[0x800];
extern s8 ContStkY[];
extern u16 D_800F9EF6_PedalPower;
extern u16 D_800F9EF8_PedalPower;
extern u16 D_800F9EFA_PedalPower;
extern u16 D_800F9EFC_PedalPower;
extern u16 D_800F9EFE_PedalPower[]; /* "15mt001_DEF" (func_80039C48) */
extern f32 D_800F9F04_PedalPower; /* belt scroll */
extern u8 D_800FA710_PedalPower;
extern f32 D_800FA720_PedalPower;
extern u16 D_800FA724_PedalPower;
extern s32 D_800FA728_PedalPower; /* player index; splat's D_800FA72A is its low half: (s16)D_800FA728 */
extern s8 D_800FA72C_PedalPower;
extern s8 D_800FA72D_PedalPower;
extern Vec2f D_800FA730_PedalPower;
extern s8 D_800FA738_PedalPower;
extern Vec3f D_800FA73C_PedalPower;
