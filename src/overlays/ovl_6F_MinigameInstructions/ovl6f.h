#ifndef OVL6F_H
#define OVL6F_H

/* ovl_6F MinigameInstructions: declarations shared by its units (2DB2D0, 2DF200, 2E8220).
   Types come from the asm's accesses. N64 offsets are in the comments; a struct with no pointers
   has the same layout on the host. */

#include "common.h"

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* One demo character's work (0xC0, func_80023684(0xC0) in func_800F9110): the user_data of each
   func_800FA540 process, passed to every D_8010E970 table function. Each minigame demo reads the
   fields its own way; the float block is positions/angles, the s16 block model/form ids, sound
   handles and counters. No pointers, so the host layout is the N64 one (sizeof stays 0xC0). */
typedef struct Ovl6FPlayerWork {
    /* 0x00 */ f32 unk_00; /* x (screen-space start; -50.0f in most setups) */
    /* 0x04 */ f32 unk_04; /* y */
    /* 0x08 */ f32 unk_08; /* z / lane: (player * 0x23) + 0x19 */
    /* 0x0C */ f32 unk_0C; /* world x from func_8001DD24 */
    /* 0x10 */ f32 unk_10; /* world y */
    /* 0x14 */ f32 unk_14; /* world z / depth */
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ s16 unk_38; /* player index 0..3 */
    /* 0x3A */ s16 unk_3A;
    /* 0x3C */ s16 unk_3C;
    /* 0x3E */ s16 unk_3E; /* team/side index (0..1) into the per-minigame bss arrays */
    /* 0x40 */ s16 unk_40; /* GwPlayer[unk_38].character */
    /* 0x42 */ u16 unk_42; /* frame counter: only lhu/sh in the asm */
    /* 0x44 */ s16 unk_44; /* sound handles, -1 = none (func_800FA630) */
    /* 0x46 */ s16 unk_46;
    /* 0x48 */ s16 unk_48;
    /* 0x4A */ s16 unk_4A;
    /* 0x4C */ s16 unk_4C;
    /* 0x4E */ s16 unk_4E; /* main model (LoadFormFile result) */
    /* 0x50 */ s16 unk_50;
    /* 0x52 */ s16 unk_52; /* form/motion ids */
    /* 0x54 */ s16 unk_54;
    /* 0x56 */ s16 unk_56;
    /* 0x58 */ s16 unk_58;
    /* 0x5A */ s16 unk_5A;
    /* 0x5C */ s16 unk_5C;
    /* 0x5E */ s16 unk_5E;
    /* 0x60 */ s16 unk_60;
    /* 0x62 */ s16 unk_62;
    /* 0x64 */ s16 unk_64[6];
    /* 0x70 */ s16 unk_70; /* second model */
    /* 0x72 */ s16 unk_72;
    /* 0x74 */ s16 unk_74;
    /* 0x76 */ s16 unk_76;
    /* 0x78 */ s16 unk_78[12];
    /* 0x90 */ s16 unk_90; /* sprite/anim id (func_8001E00C, func_80038A9C) */
    /* 0x92 */ s16 unk_92[15];
    /* 0xB0 */ s16 unk_B0; /* start delay: (3 - unk_38) * 4 */
    /* 0xB2 */ s16 unk_B2;
    /* 0xB4 */ s16 unk_B4;
    /* 0xB6 */ s16 unk_B6; /* another player's index (D_8010F750[unk_B6]) */
    /* 0xB8 */ s16 unk_B8;
    /* 0xBA */ s16 unk_BA;
    /* 0xBC */ s16 unk_BC;
    /* 0xBE */ s16 unk_BE;
} Ovl6FPlayerWork; /* size = 0xC0 */

/* Two halfwords: the func_800F9110 process's user_data (4 bytes: [0] state, [1] count of
   finished players), and the D_8010F50C pairs. */
typedef struct Ovl6FPairS16 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
} Ovl6FPairS16;

/* func_800F8ED4's user_data (func_80023684(0x14) in func_800F6B14). */
typedef struct Ovl6FSpriteWork {
    /* 0x00 */ f32 unk_00; /* x */
    /* 0x04 */ f32 unk_04; /* y */
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A; /* sprite id (func_80019060) */
    /* 0x0C */ char unk_0C[8];
} Ovl6FSpriteWork; /* size = 0x14 */

/* D_8010E4F0: one record per minigame (indexed by D_8010F766 = GwSystem.unk_1E). */
typedef struct Ovl6FMinigameInfo {
    /* 0x00 */ s32 overlay;  /* omOvlCallEx/omOvlGotoEx overlay id */
    /* 0x04 */ u8 unk_04;    /* D_8010F760 (0 = one player, else four) */
    /* 0x08 */ s32 unk_08;   /* DataRead id of the preview image (func_800F94E8) */
    /* 0x0C */ u16 unk_0C;   /* message id: (void*)(s32) for LoadStringIntoWindow */
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ u8 unk_10;    /* lbu (func_800F6B14) */
} Ovl6FMinigameInfo; /* size = 0x14 */

/* D_8010E970: four demo functions per minigame and a flags word (the table's data starts with the
   functions; splat put the flags of entry 0 at its own label D_8010E980). Host stride 0x28. */
typedef struct Ovl6FMinigameFuncs {
    /* 0x00 */ void (*fn[4])(Ovl6FPlayerWork*); /* setup, start, per-frame, end (func_800FA540/630) */
    /* 0x10 */ s32 flags;
} Ovl6FMinigameFuncs; /* size = 0x14 */

/* D_8010EF70: per-minigame player setup (func_8010E090). */
typedef struct Ovl6FTeamEntry {
    /* 0x00 */ u8 group;    /* GwPlayer[0].group */
    /* 0x01 */ s8 unk_01;   /* compared with -1 */
    /* 0x02 */ s8 unk_02;
    /* 0x03 */ u8 unk_03;   /* cpu_difficulty for all four */
} Ovl6FTeamEntry; /* size = 0x4 */

/* Mirrors of src/1EA70.c's private structs (func_80021308's billboard set). */
typedef struct unk1EA70Struct20 {
    /* 0x00 */ char unk_00[2];
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ char unk_14[4];
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ s16 unk_1C; /* D_800ECDE0 index */
    /* 0x1E */ char unk_1E[2];
} unk1EA70Struct20; /* size = 0x20 */

typedef struct unk1EA70Struct1C {
    /* 0x00 */ unk1EA70Struct20* unk_00;
    /* 0x04 */ u8* unk_04;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ u8 unk_09;
    /* 0x0A */ u8 unk_0A;
    /* 0x0B */ char unk_0B;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ u16 unk_18;
    /* 0x1A */ char unk_1A[2];
} unk1EA70Struct1C; /* size = 0x1C (N64) */

/* ---------------------------------------------------------------------------------------------
   Main-code functions without a declaration in include/ (signatures from their definitions)
   --------------------------------------------------------------------------------------------- */
void GMesMaxTimeGet(s16, s16);
s16 func_80009E4C(s16 player, s16 limit, s8 x, s8 y);
void func_8001DD24(s16 index, f32 arg1, Vec3f* arg2, Vec3f* arg3);
void func_80020EA0(s16, u8*, s16, u8*);
unk1EA70Struct1C* func_80021308(s32 file, s16 count);
void func_800214FC(unk1EA70Struct1C*);
s16 func_80021794(unk1EA70Struct1C*, s16, f32, f32, f32, u16);
void func_80021B04(unk1EA70Struct1C*, u8, u8, u8);
void func_80025BB8(s16, s16);
f32 func_80025D18(s16);
f32 func_80025D40(s16);
f32 func_80025D90(s16);
f32 func_80025DD8(s16);
unk2C0C0Struct50* func_80026A0C(s16, char*);
void func_80027AC8(s16, u8*, u8*);
void func_80028498(s16, s16, s16);
void func_8002859C(s16, s16, char*);
void func_80039644(s16, u8, u8);
void func_800396B0(s16, u8); /* callers andi 0xFF */
void func_8003A060(Gfx** arg0, s32 timg, s32 fmt, s32 siz, s32 width, s32 height, s32 uls,
                   s32 ult, s32 lrs, s32 lrt, s32 pal, s32 cms, s32 cmt, s32 masks, s32 maskt,
                   s32 shifts, s32 shiftt);
void func_800593AC(s32); /* as func_800F6610 matched with it */
Process* func_8005DCD8(process_func, u16, s32, s32, Process*);
void func_8006035C(s16, s8);
void func_80060440(s16, s16);
s16 func_80060758(s16);
void func_80060BC8(s16, s16);
void func_80060F04(s16, s16, s16, s16);
s16 func_8006D93C(u8*);
s16 func_8006DB3C(s16, s32, s16, s16, s16);
void func_8007F54C(void* code, u16* outbuf, u32 outbufWidth, u16* workbuf);
void func_8007FAC0(void);
extern s8 omSysPauseEnableFlag;
extern TextWindow* D_800ED4B0; /* src/72D90.c; func_800F7C58 indexes it by D_8010F408 */

/* ---------------------------------------------------------------------------------------------
   .data (still asm in 2DB2D0/2DF200/2E8220.data.s)
   --------------------------------------------------------------------------------------------- */
/* 2DB2D0 */
/* 56 records; splat labels inside record 0: D_8010E4F4 (.unk_04), D_8010E4F8 (.unk_08),
   D_8010E4FC (.unk_0C), D_8010E4FE (.unk_0E), D_8010E500 (.unk_10). Write D_8010E4F0[i].field. */
extern Ovl6FMinigameInfo D_8010E4F0_MinigameInstructions[56];
extern u8 D_8010E950_MinigameInstructions;
/* 2DF200 */
extern unk1EA70Struct1C* D_8010E960_MinigameInstructions; /* created once by func_800FA77C */
extern s16 D_8010E964_MinigameInstructions[6];             /* per character: form-file bank */
/* 56 entries; splat labels D_8010E974/78/7C (.fn[1..3] of entry 0) and D_8010E980 (.flags).
   Write D_8010E970[i].fn[n](work). */
extern Ovl6FMinigameFuncs D_8010E970_MinigameInstructions[56];
extern s32 D_8010EDD0_MinigameInstructions[6]; /* DataRead ids per character */
extern s32 D_8010EDE8_MinigameInstructions[6]; /* LoadFormFile ids */
extern u8* D_8010EE00_MinigameInstructions[6][2]; /* string pairs (func_80020EA0); host stride 16 */
extern u8* D_8010EE30_MinigameInstructions[6];    /* strings (func_80027AC8) */
/* [6][2]; D_8010EE4A is splat's label for [0][1] */
extern s16 D_8010EE48_MinigameInstructions[6][2];
/* [6][2]; D_8010EE64 is splat's label for [0][1] */
extern s32 D_8010EE60_MinigameInstructions[6][2];
extern s32 D_8010EE90_MinigameInstructions[6];
extern char* D_8010EEA8_MinigameInstructions[6]; /* strings (func_8002859C) */
extern s32 D_8010EEC0_MinigameInstructions[8];
/* 2E8220 */
extern s32 D_8010EEE0_MinigameInstructions[6];
extern u8* D_8010EEF8_MinigameInstructions[6]; /* strings (func_80027AC8) */
/* LoadFormFile id pairs at 0x8010EF10, which has no splat label (it sits at the end of
   D_8010EEF8's label; retail addresses it as D_8010EF14 - 4). D_8010EF10 is an
   undefined_syms.txt alias; D_8010EF14 is [0][1]. */
extern s32 D_8010EF10_MinigameInstructions[6][2];
extern u16 D_8010EF40_MinigameInstructions[4]; /* lhu, converted to f32 */
extern s32 D_8010EF48_MinigameInstructions[4];
extern u16 D_8010EF58_MinigameInstructions[4]; /* lhu, converted to f32 */
extern u8 D_8010EF60_MinigameInstructions;
extern Ovl6FTeamEntry D_8010EF70_MinigameInstructions[56];

/* .rodata referenced as objects (string/array templates stay INCLUDE_RODATA) */
extern const u8 D_8010F050_MinigameInstructions[]; /* SJIS string passed to func_8007B168 */
extern const char D_8010F268_MinigameInstructions[]; /* "item_hook" (2DF200 rodata) */
extern const char D_8010F360_MinigameInstructions[]; /* "item_hook" (2E8220 rodata) */

extern s16 D_8010F400_MinigameInstructions;
extern s16 D_8010F402_MinigameInstructions;
extern omObjData* D_8010F404_MinigameInstructions;
extern s16 D_8010F408_MinigameInstructions; /* text window id, -1 = none */
extern u16 D_8010F40A_MinigameInstructions; /* sprite id: only lhu */
/* Two message blocks (0x68 apart; func_800F8980 builds one per text line). On hosts the void* at
   0x10 moves unk_14 and widens the stride, so the inner labels are views. */
extern unkCommonStruct0 D_8010F410_MinigameInstructions[2];
extern s16 D_8010F418_MinigameInstructions;
extern s16 D_8010F424_MinigameInstructions[16];
extern f32 D_8010F464_MinigameInstructions;
extern f32 D_8010F468_MinigameInstructions;
extern s16 D_8010F480_MinigameInstructions;
extern s16 D_8010F4E0_MinigameInstructions; /* _CheckFlag(0x45) */
extern s16 D_8010F4E2_MinigameInstructions;
extern void* D_8010F4E4_MinigameInstructions; /* func_80023684(0x1040) work buffer */
extern s16 D_8010F4E8_MinigameInstructions;
extern s16 D_8010F4EA_MinigameInstructions; /* func_800F7C58 state */
/* One minigame's state (range func_80104320..: indexed by work->unk_3E or unk_38). */
extern s16 D_8010F4F0_MinigameInstructions[2]; /* models; D_8010F4F2 is [1] */
extern s16 D_8010F4F2_MinigameInstructions;
extern s16 D_8010F4F4_MinigameInstructions;
extern s16 D_8010F4F6_MinigameInstructions[4]; /* per player state */
extern s16 D_8010F4FE_MinigameInstructions[3]; /* per side (2 used) */
extern f32 D_8010F504_MinigameInstructions[2];
/* Another minigame's state (range F). */
extern Ovl6FPairS16 D_8010F50C_MinigameInstructions[2]; /* model pairs; D_8010F50E is [0].unk_02 */
extern s16 D_8010F50E_MinigameInstructions;
extern f32 D_8010F514_MinigameInstructions[2];
extern f32 D_8010F51C_MinigameInstructions[2];
extern f32 D_8010F524_MinigameInstructions[2];
extern f32 D_8010F52C_MinigameInstructions;
extern f32 D_8010F530_MinigameInstructions[2];
/* Per player stick value, stored as a word (sw) and read back as its low half (lh at +2). */
extern s32 D_8010F538_MinigameInstructions[4];
#define D_8010F538_LO16(i) (((s16*)&D_8010F538_MinigameInstructions[i])[1])
/* A model id kept as a word (LoadFormFile() & 0xFFFF); retail reads its low half as D_8010F54A. */
extern s32 D_8010F548_MinigameInstructions;
extern s16 D_8010F54A_MinigameInstructions;
extern Ovl6FPlayerWork* D_8010F750_MinigameInstructions[4]; /* four-player demos only */
extern s16 D_8010F760_MinigameInstructions; /* D_8010E4F0[].unk_04: 0 = one player */
extern s16 D_8010F762_MinigameInstructions;
extern s16 D_8010F764_MinigameInstructions; /* sound enable: func_800FA284 etc. play only if != 0 */
extern u16 D_8010F766_MinigameInstructions; /* minigame index; read as (s16) everywhere */
extern u8 D_8010F768_MinigameInstructions;
extern s16 D_8010F76A_MinigameInstructions[4]; /* per player */
extern s16 D_8010F772_MinigameInstructions; /* first player with group 0 */

/* ---------------------------------------------------------------------------------------------
   Overlay functions
   --------------------------------------------------------------------------------------------- */
/* 2DB2A0 */
void func_800F65E0_MinigameInstructions(void);
/* 2DB2D0 */
void func_800F6610_MinigameInstructions(void);
void func_800F6924_MinigameInstructions(void);
void func_800F692C_MinigameInstructions(omObjData* obj);
void func_800F6948_MinigameInstructions(omObjData* obj);
void func_800F6990_MinigameInstructions(void);
void func_800F6B14_MinigameInstructions(void);
void func_800F7398_MinigameInstructions(void);
void func_800F785C_MinigameInstructions(void);
void func_800F7C58_MinigameInstructions(void);
void func_800F84B0_MinigameInstructions(void);
s16 func_800F885C_MinigameInstructions(s16 idx); /* returns a message id */
s16 func_800F8910_MinigameInstructions(s16 idx); /* returns a message id */
void func_800F8980_MinigameInstructions(s16 idx);
void func_800F8DD0_MinigameInstructions(void);
void func_800F8E3C_MinigameInstructions(void);
void func_800F8ED4_MinigameInstructions(void);
void func_800F9078_MinigameInstructions(Ovl6FSpriteWork* work);
void func_800F9110_MinigameInstructions(void);
void func_800F9264_MinigameInstructions(void);
void func_800F92D4_MinigameInstructions(omObjData* obj);
void func_800F9440_MinigameInstructions(omObjData* obj);
void func_800F949C_MinigameInstructions(omObjData* obj);
void func_800F94E8_MinigameInstructions(s16 model, s16 idx);
void func_800F9E64_MinigameInstructions(s16 idx);
s16 func_800FA284_MinigameInstructions(s16 sound);
s16 func_800FA2C0_MinigameInstructions(s16 sound, Ovl6FPlayerWork* work);
s16 func_800FA300_MinigameInstructions(s16 sound, Ovl6FPlayerWork* work); /* m2c: s32 arg0 */
void func_800FA350_MinigameInstructions(s16 handle, s16 arg1);
void func_800FA380_MinigameInstructions(s16 handle);
void func_800FA3AC_MinigameInstructions(s16 kind, Ovl6FPlayerWork* work);
void func_800FA470_MinigameInstructions(void);
/* 2DF200 */
void func_800FA540_MinigameInstructions(void);
void func_800FA630_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FA77C_MinigameInstructions(s32 file); /* a0 goes straight to func_80021308 */
void func_800FA7C8_MinigameInstructions(void);
void func_800FA7F8_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FA9EC_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FAC2C_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FADF4_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FB4DC_MinigameInstructions(s16 model);
void func_800FB590_MinigameInstructions(Ovl6FPlayerWork* work, s16 motion);
void func_800FB60C_MinigameInstructions(Ovl6FPlayerWork* work, s16 motion);
void func_800FB688_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FB7D8_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FBA14_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FBBA8_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FC008_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FC190_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FC3B0_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FC558_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FC9F8_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FCB50_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FCC54_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FCD20_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FCED0_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FD130_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FD408_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FD674_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FD954_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FDBF8_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FDEA4_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FE0E8_MinigameInstructions(Ovl6FPlayerWork* work);
f32 func_800FE8D8_MinigameInstructions(s16 port); /* stick magnitude squared */
void func_800FE924_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FEB5C_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FEE08_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FF010_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FF23C_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FF3CC_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FF68C_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FF884_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FFA08_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FFB88_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FFCD0_MinigameInstructions(Ovl6FPlayerWork* work);
void func_800FFECC_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80100090_MinigameInstructions(Ovl6FPlayerWork* work);
void func_801001B0_MinigameInstructions(Ovl6FPlayerWork* work);
void func_801001D0_MinigameInstructions(Ovl6FPlayerWork* work);
void func_801004EC_MinigameInstructions(Ovl6FPlayerWork* work);
void func_8010078C_MinigameInstructions(Ovl6FPlayerWork* work);
void func_801009B4_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80100CCC_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80100F6C_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80101188_MinigameInstructions(s16 model0, s16 model1, u16 arg2); /* callee andi 0xFFFF */
void func_80101304_MinigameInstructions(Ovl6FPlayerWork* work);
void func_8010143C_MinigameInstructions(Ovl6FPlayerWork* work);
void func_8010165C_MinigameInstructions(Ovl6FPlayerWork* work);
void func_801018BC_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80101A90_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80102048_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80102334_MinigameInstructions(Ovl6FPlayerWork* work);
void func_801024FC_MinigameInstructions(Ovl6FPlayerWork* work);
void func_801027CC_MinigameInstructions(Ovl6FPlayerWork* work);
void func_801029BC_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80102C9C_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80102FC4_MinigameInstructions(Ovl6FPlayerWork* work);
void func_801031BC_MinigameInstructions(Ovl6FPlayerWork* work);
/* 2E8220 */
void func_80103560_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80103788_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80103E48_MinigameInstructions(Ovl6FPlayerWork* work);
void func_801040AC_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80104320_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80104688_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80104988_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80104DF0_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80105148_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80105464_MinigameInstructions(Ovl6FPlayerWork* work);
void func_8010574C_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80105984_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80105B24_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80105D08_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80105E64_MinigameInstructions(Ovl6FPlayerWork* work);
void func_801060DC_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80106358_MinigameInstructions(Ovl6FPlayerWork* work);
void func_801064A4_MinigameInstructions(Ovl6FPlayerWork* work);
void func_801066C4_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80106948_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80106B2C_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80106F90_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80106FE0_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80107018_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80107050_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80107088_MinigameInstructions(Ovl6FPlayerWork* work);
void func_8010732C_MinigameInstructions(Ovl6FPlayerWork* work);
void func_801075B8_MinigameInstructions(Ovl6FPlayerWork* work);
void func_801077C8_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80107F4C_MinigameInstructions(Ovl6FPlayerWork* work);
void func_801080E4_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80108280_MinigameInstructions(Ovl6FPlayerWork* work);
void func_801083DC_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80108624_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80108A90_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80108FE4_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80109600_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80109BFC_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80109DB0_MinigameInstructions(Ovl6FPlayerWork* work);
void func_80109F68_MinigameInstructions(Ovl6FPlayerWork* work);
void func_8010A0D4_MinigameInstructions(Ovl6FPlayerWork* work);
void func_8010A43C_MinigameInstructions(Ovl6FPlayerWork* work);
void func_8010A5D4_MinigameInstructions(Ovl6FPlayerWork* work);
void func_8010A75C_MinigameInstructions(Ovl6FPlayerWork* work);
void func_8010A938_MinigameInstructions(Ovl6FPlayerWork* work);
void func_8010ABA4_MinigameInstructions(Ovl6FPlayerWork* work);
void func_8010AD60_MinigameInstructions(Ovl6FPlayerWork* work);
void func_8010AEA0_MinigameInstructions(Ovl6FPlayerWork* work);
void func_8010B44C_MinigameInstructions(Ovl6FPlayerWork* work);
void func_8010B7EC_MinigameInstructions(Ovl6FPlayerWork* work);
void func_8010BB04_MinigameInstructions(Ovl6FPlayerWork* work);
void func_8010BF20_MinigameInstructions(Ovl6FPlayerWork* work);
void func_8010C3A4_MinigameInstructions(Ovl6FPlayerWork* work);
void func_8010C8CC_MinigameInstructions(Ovl6FPlayerWork* work);
void func_8010CC54_MinigameInstructions(Ovl6FPlayerWork* work);
void func_8010D200_MinigameInstructions(Ovl6FPlayerWork* work);
void func_8010D5E4_MinigameInstructions(Ovl6FPlayerWork* work);
void func_8010DB24_MinigameInstructions(Ovl6FPlayerWork* work);
void func_8010DF34_MinigameInstructions(Ovl6FPlayerWork* work);
void func_8010E090_MinigameInstructions(s16 idx);

#endif
