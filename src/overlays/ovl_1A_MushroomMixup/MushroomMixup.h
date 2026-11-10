#ifndef MUSHROOMMIXUP_H
#define MUSHROOMMIXUP_H
/* ovl_1A Mushroom Mix-Up: declarations for its units (1784E0.c, 17BDC0.c).
   Types come from the asm's accesses; N64 offsets are in the comments. */
#include "common.h"
#include "engine/ovlman.h"
#include "engine/pad.h"

#define NUM_OF_MUSHROOMS 7

/* The players' work (omObjData::unk_50: func_8000979C allocates a MgWork, 0xE8); MgWork's layout
   (src/99E0.c) with the fields this overlay touches; its pointers sit where MgWork's do. */
typedef struct MMPlayerWork {
    /* 0x00 */ char unk_00[0x23];
    /* 0x23 */ u8 unk_23;
    /* 0x24 */ char unk_24[0x14];
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C; /* facing angle */
    /* 0x40 */ f32 unk_40; /* speed */
    /* 0x44 */ char unk_44[4];
    /* 0x48 */ f32 unk_48; /* radius */
    /* 0x4C */ char unk_4C[4];
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ s8 unk_53; /* collision object index (D_800F2AF8), -1 none */
    /* 0x54 */ s8 unk_54;
    /* 0x55 */ char unk_55;
    /* 0x56 */ s8 unk_56; /* controller port */
    /* 0x57 */ char unk_57;
    /* 0x58 */ s8 unk_58; /* player index */
    /* 0x59 */ char unk_59[0x4B];
    /* 0xA4 */ f32 unk_A4;
    /* 0xA8 */ char unk_A8[0xB];
    /* 0xB3 */ s8 unk_B3;
    /* 0xB4 */ char unk_B4[4];
    /* 0xB8 */ void* unk_B8;
    /* 0xBC */ char unk_BC[0x1C];
    /* 0xD8 */ void* unk_D8;
    /* 0xDC */ void* unk_DC;
    /* 0xE0 */ char unk_E0[4];
    /* 0xE4 */ void* unk_E4;
} MMPlayerWork; /* size = 0xE8 (N64) */

#define MM_PLAYER(obj) ((MMPlayerWork*)(obj)->unk_50)

/* The other objects' work (func_80023684(0x2C)): MgWork's first 0x2C bytes. No pointers. */
typedef struct MMGroundWork {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk_06[0x26];
} MMGroundWork; /* size = 0x2C */

#define MM_GROUND(obj) ((MMGroundWork*)(obj)->unk_50)

/* D_800FC9C0: one record per mushroom platform (func_800FBFB0 ... func_800FC3C4). */
typedef struct MMMushroom {
    /* 0x00 */ omObjData* obj;
    /* 0x04 */ s16 colIdx;  /* its collision object index (work unk_05) */
    /* 0x06 */ s16 color;   /* & 7: colour 0-6 */
    /* 0x08 */ u16 state;   /* 0 rest, 1 rising, 2 moving */
    /* 0x0C */ f32 speed;
    /* 0x10 */ f32 topY;
    /* 0x14 */ Vec pos;
    /* 0x20 */ u16 model;
} MMMushroom; /* size = 0x24 (N64) */

/* D_800FC8B8: one per player, the CPU and input state. No pointers. */
typedef struct MMPlayerState {
    /* 0x00 */ u16 flags;   /* 1 CPU, 2 target chosen, 4 turned */
    /* 0x02 */ u16 state;
    /* 0x04 */ s16 difficulty;
    /* 0x06 */ u16 color;
    /* 0x08 */ u16 wait;
    /* 0x0A */ u16 timer;
    /* 0x0C */ u16 target;
    /* 0x0E */ s16 stkX;
    /* 0x10 */ s16 stkY;
    /* 0x12 */ u16 btnTrg;
    /* 0x14 */ u16 btn;
    /* 0x16 */ s16 savStkX;
    /* 0x18 */ s16 savStkY;
    /* 0x1A */ u16 savBtnTrg;
    /* 0x1C */ u16 savBtn;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
} MMPlayerState; /* size = 0x34 */

/* D_800FC850: the two flag bearers (func_800FB238). No pointers. */
typedef struct MMFlagState {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ u16 unk_10;
} MMFlagState; /* size = 0x14 */

typedef struct MMU16Pair {
    u16 unk_00;
    u16 unk_02;
} MMU16Pair;

/* D_800FC7B0: seven colours, three halfwords each (only the low bytes are used). */
typedef struct MMColor {
    s16 r;
    s16 g;
    s16 b;
} MMColor;

typedef struct MMColorTable {
    MMColor c[NUM_OF_MUSHROOMS];
} MMColorTable;

typedef struct MMNameTable {
    char* name[NUM_OF_MUSHROOMS];
} MMNameTable;

/* ---------------------------------------------------------------------------------------------
   Main-code declarations missing from the shared headers
   --------------------------------------------------------------------------------------------- */
extern omObjData* D_800F2AF8[];
extern s16 D_800EE984;
extern u8 D_800F64F8;
extern f32 D_800B8990;
extern unk34D80Struct80* D_800ED554;
s32 func_80017A60(omObjData*);
s32 func_800185A4(omObjData*, u16);
void func_800093FC(omObjData*, f32, f32, f32);
void func_80008FDC(omObjData*, f32);
void func_80008FE8(omObjData*, f32);
void func_800090C4(omObjData* obj, u8 idx, u8 val);
void func_8001E268(s16 index, u8 arg1, u8 arg2);
void func_8001E2A8(s16, u16);
f32 func_80029518(f32);
void func_80060F04(s16, s32, s32, s32);
void func_80027AC8(s16 arg0, u8* arg1, u8* arg2);
void func_80028180(s16 arg0, char* arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5);
f32 func_800369FC(unk34D80Struct80*, s16, f32, f32, f32);

/* ---------------------------------------------------------------------------------------------
   Overlay functions
   --------------------------------------------------------------------------------------------- */
void func_800F65E0_MushroomMixup(void);
void func_800F6CA8_MushroomMixup(omObjData*);
void func_800F6CF4_MushroomMixup(void);
void func_800F6DF4_MushroomMixup(void);
void func_800F7088_MushroomMixup(u16);
void func_800F70C4_MushroomMixup(void);
void func_800F70F0_MushroomMixup(s16, u32);
void func_800F7188_MushroomMixup(s16);
u16 func_800F71A8_MushroomMixup(u8, u8, u8, u8, u8);
u16 func_800F7574_MushroomMixup(void);
void func_800F75B0_MushroomMixup(omObjData*);
void func_800F7FCC_MushroomMixup(omObjData*);
u8 func_800F8260_MushroomMixup(omObjData*);
void func_800F82AC_MushroomMixup(omObjData*);
s32 func_800F846C_MushroomMixup(u16); /* callers read the low byte */
s8 func_800F84F0_MushroomMixup(void);
void func_800F8840_MushroomMixup(void);
void func_800F8848_MushroomMixup(omObjData*);
f32 func_800F88AC_MushroomMixup(omObjData*, f32, f32);
void func_800F8A58_MushroomMixup(omObjData*);
void func_800F9364_MushroomMixup(omObjData*);
void func_800F93F0_MushroomMixup(omObjData*);
void func_800F9510_MushroomMixup(omObjData*, s32);
void func_800F9548_MushroomMixup(omObjData*);
void func_800F9890_MushroomMixup(omObjData*);
void func_800F9CF0_MushroomMixup(omObjData*);
void func_800F9E9C_MushroomMixup(omObjData*);
void func_800F9EC0_MushroomMixup(omObjData*);
void func_800FA320_MushroomMixup(omObjData*);
void func_800FA3C4_MushroomMixup(omObjData*);
void func_800FA454_MushroomMixup(omObjData*);
void func_800FA53C_MushroomMixup(omObjData*, MMMushroom*, s32, s16, Vec*);
void func_800FA664_MushroomMixup(omObjData*, s32, s32, u16, f32, s32);
void func_800FAAE8_MushroomMixup(omObjData*);
void func_800FABE4_MushroomMixup(omObjData*);
void func_800FAF90_MushroomMixup(omObjData*, Vec*, s8);
void func_800FB0FC_MushroomMixup(omObjData*);
void func_800FB11C_MushroomMixup(omObjData*);
void func_800FB238_MushroomMixup(omObjData*);
void func_800FBB8C_MushroomMixup(omObjData*, u16);
void func_800FBE30_MushroomMixup(omObjData*);
void func_800FBE90_MushroomMixup(omObjData*);
void func_800FBEEC_MushroomMixup(omObjData*);
void func_800FBF4C_MushroomMixup(omObjData*);
void func_800FBFB0_MushroomMixup(omObjData*);
void func_800FC068_MushroomMixup(omObjData*);
void func_800FC114_MushroomMixup(omObjData*);
void func_800FC1C0_MushroomMixup(omObjData*);
void func_800FC26C_MushroomMixup(omObjData*);
void func_800FC318_MushroomMixup(omObjData*);
void func_800FC3C4_MushroomMixup(omObjData*);
void func_800FC46C_MushroomMixup(omObjData*);
void func_800FC4A4_MushroomMixup(omObjData*);
void func_800FC4FC_MushroomMixup(omObjData*);
void func_800FC554_MushroomMixup(omObjData*);
void func_800FC5AC_MushroomMixup(omObjData*);
void func_800FC604_MushroomMixup(omObjData*);
void func_800FC65C_MushroomMixup(omObjData*);
void func_800FC6C8_MushroomMixup(omObjData*);
void func_800FC6E4_MushroomMixup(omObjData*);

/* ---------------------------------------------------------------------------------------------
   Data (1784E0.c, 17BDC0.c)
   --------------------------------------------------------------------------------------------- */
extern u8 D_800FC700_MushroomMixup; /* round phase 0-3 */
extern u8 D_800FC701_MushroomMixup;
extern u8 D_800FC702_MushroomMixup;
extern u8 D_800FC703_MushroomMixup;
extern s16 D_800FC704_MushroomMixup;
extern s16 D_800FC706_MushroomMixup;
extern s16 D_800FC708_MushroomMixup;
extern s32 D_800FC70C_MushroomMixup;
extern s32 D_800FC710_MushroomMixup[4];

extern u32 D_800FC720_MushroomMixup;
extern s32 D_800FC724_MushroomMixup;
extern s32 D_800FC728_MushroomMixup;
extern u32 D_800FC72C_MushroomMixup;
extern u32 D_800FC730_MushroomMixup;
extern s32 D_800FC734_MushroomMixup; /* model id, 0x80 = not loaded; (s16) reads +2 */
extern s32 D_800FC738_MushroomMixup;
extern MMNameTable D_800FC794_MushroomMixup;
extern MMColorTable D_800FC7B0_MushroomMixup;
extern char D_800FC7DC_MushroomMixup[];
extern char D_800FC7EC_MushroomMixup[];
extern char D_800FC7FC_MushroomMixup[];

/* ---------------------------------------------------------------------------------------------
   Bss (asm/data/.../ovl_1A_bss.bss.s). Blocks are reached only through their first label, so the
   host's gen_ovl.py merges the inner labels into them.
   --------------------------------------------------------------------------------------------- */
extern s32 D_800FC810_MushroomMixup;
extern s32 D_800FC814_MushroomMixup;
extern s32 D_800FC818_MushroomMixup;
extern u32 D_800FC81C_MushroomMixup; /* the colour to stand on */
extern u32 D_800FC820_MushroomMixup; /* (u16) reads +2 */
extern u32 D_800FC824_MushroomMixup; /* (u8) reads +3 */
extern u32 D_800FC828_MushroomMixup; /* (u8) reads +3 */
extern s32 D_800FC830_MushroomMixup; /* model ids; (s16) reads +2 */
extern s32 D_800FC834_MushroomMixup;
extern s32 D_800FC838_MushroomMixup;
extern s32 D_800FC83C_MushroomMixup;
extern s32 D_800FC840_MushroomMixup;
extern MMU16Pair D_800FC844_MushroomMixup;
extern f32 D_800FC848_MushroomMixup;
extern f32 D_800FC84C_MushroomMixup;
extern MMFlagState D_800FC850_MushroomMixup[2];
extern MMPlayerWork* D_800FC880_MushroomMixup[4];
extern s16 D_800FC890_MushroomMixup;
extern s16 D_800FC892_MushroomMixup[4];
extern f32 D_800FC89C_MushroomMixup;
extern u16 D_800FC8A0_MushroomMixup;
extern omObjData* D_800FC8A4_MushroomMixup[2];
extern u16 D_800FC8AC_MushroomMixup; /* the flag bearers' busy mask */
extern u16 D_800FC8AE_MushroomMixup[5]; /* a random order of the four players */
extern MMPlayerState D_800FC8B8_MushroomMixup[4];
extern f32 D_800FC988_MushroomMixup;
extern s32 D_800FC98C_MushroomMixup;
extern s32 D_800FC990_MushroomMixup;
extern u16 D_800FC994_MushroomMixup;
extern u16 D_800FC996_MushroomMixup;
extern f32 D_800FC998_MushroomMixup;
extern f32 D_800FC99C_MushroomMixup;
extern u16 D_800FC9A0_MushroomMixup;
extern omObjData* D_800FC9A8_MushroomMixup[4];
extern f32 D_800FC9B8_MushroomMixup;
extern MMMushroom D_800FC9C0_MushroomMixup[NUM_OF_MUSHROOMS];
/* The init functions (func_800FBFB0...) and a few readers address record fields as separate
   relocations, which only per-label externs reproduce on the N64; the host has the one array. */
extern s16 D_800FC9C6_MushroomMixup;
extern u16 D_800FC9C8_MushroomMixup;
extern f32 D_800FC9CC_MushroomMixup;
extern f32 D_800FC9D0_MushroomMixup;
extern f32 D_800FC9D4_MushroomMixup;
extern f32 D_800FC9D8_MushroomMixup;
extern f32 D_800FC9DC_MushroomMixup;
extern MMMushroom D_800FC9E4_MushroomMixup;
extern s16 D_800FC9EA_MushroomMixup;
extern u16 D_800FC9EC_MushroomMixup;
extern f32 D_800FC9F0_MushroomMixup;
extern f32 D_800FC9F4_MushroomMixup;
extern f32 D_800FC9F8_MushroomMixup;
extern f32 D_800FC9FC_MushroomMixup;
extern f32 D_800FCA00_MushroomMixup;
extern MMMushroom D_800FCA08_MushroomMixup;
extern s16 D_800FCA0E_MushroomMixup;
extern u16 D_800FCA10_MushroomMixup;
extern f32 D_800FCA14_MushroomMixup;
extern f32 D_800FCA18_MushroomMixup;
extern f32 D_800FCA1C_MushroomMixup;
extern f32 D_800FCA20_MushroomMixup;
extern f32 D_800FCA24_MushroomMixup;
extern MMMushroom D_800FCA2C_MushroomMixup;
extern s16 D_800FCA32_MushroomMixup;
extern u16 D_800FCA34_MushroomMixup;
extern f32 D_800FCA38_MushroomMixup;
extern f32 D_800FCA3C_MushroomMixup;
extern f32 D_800FCA40_MushroomMixup;
extern f32 D_800FCA44_MushroomMixup;
extern f32 D_800FCA48_MushroomMixup;
extern MMMushroom D_800FCA50_MushroomMixup;
extern s16 D_800FCA56_MushroomMixup;
extern u16 D_800FCA58_MushroomMixup;
extern f32 D_800FCA5C_MushroomMixup;
extern f32 D_800FCA60_MushroomMixup;
extern f32 D_800FCA64_MushroomMixup;
extern f32 D_800FCA68_MushroomMixup;
extern f32 D_800FCA6C_MushroomMixup;
extern MMMushroom D_800FCA74_MushroomMixup;
extern s16 D_800FCA7A_MushroomMixup;
extern u16 D_800FCA7C_MushroomMixup;
extern f32 D_800FCA80_MushroomMixup;
extern f32 D_800FCA84_MushroomMixup;
extern f32 D_800FCA88_MushroomMixup;
extern f32 D_800FCA8C_MushroomMixup;
extern f32 D_800FCA90_MushroomMixup;
extern MMMushroom D_800FCA98_MushroomMixup;
extern s16 D_800FCA9E_MushroomMixup;
extern u16 D_800FCAA0_MushroomMixup;
extern f32 D_800FCAA4_MushroomMixup;
extern f32 D_800FCAA8_MushroomMixup;
extern f32 D_800FCAAC_MushroomMixup;
extern f32 D_800FCAB0_MushroomMixup;
extern f32 D_800FCAB4_MushroomMixup;
extern u16 D_800FCABC_MushroomMixup; /* the winner (4 = none); read as s16 */

#endif
