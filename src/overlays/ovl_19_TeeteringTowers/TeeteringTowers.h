#ifndef TEETERINGTOWERS_H
#define TEETERINGTOWERS_H

/* ovl_19 TeeteringTowers: declarations for its units (1738E0.c, 176130.c).
   Types come from the asm's accesses; N64 offsets are in the comments. */

#include "common.h"
#include "engine/pad.h"

enum {
    PLATFORM_ITEM_NONE = 0,
    PLATFORM_ITEM_COIN = 1,
    PLATFORM_ITEM_MONEY_BAG = 2
};

/* D_800FA958: one record per platform object (func_800F7A94), ended by unk_00 == 0. */
typedef struct UnkTeeteringTowers0 {
    /* 0x00 */ s32 unk_00; /* 1 platform, 2 start, 3 goal, 4 stage */
    /* 0x04 */ s32 unk_04; /* may hold an item; set to 1 when it got one */
    /* 0x08 */ void (*func)(omObjData*);
    /* 0x0C */ Vec pos;
    /* 0x18 */ s32 unk_18[3];
} UnkTeeteringTowers0; /* size = 0x24 (N64) */

typedef struct ItemOnPlatform {
    /* 0x00 */ s32 type; /* 0 none, 1 coin, 2 money bag */
    /* 0x04 */ Vec pos;
} ItemOnPlatform; /* size = 0x10 */

/* The item objects' work (func_800F8AF4, func_80023684(0x6C)). No pointers. */
typedef struct UnkTeeteringTowers1 {
    /* 0x00 */ char unk_00[0x24];
    /* 0x24 */ u8 unk_24;
    /* 0x25 */ char unk_25[0xF];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ char unk_38[4];
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ char unk_40[4];
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ char unk_4C[6];
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ char unk_53[1];
    /* 0x54 */ u8 unk_54;
    /* 0x55 */ char unk_55[7];
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ s32 unk_60;
    /* 0x64 */ char unk_64[8];
} UnkTeeteringTowers1; /* size = 0x6C */

/* The platforms' work (func_800F7A94, func_80023684(0x2C)): MgWork's first 0x2C bytes
   (src/1130.c's GroundWork). No pointers. */
typedef struct TTPlatformWork {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05; /* platform index */
    /* 0x06 */ char unk_06[0x26];
} TTPlatformWork; /* size = 0x2C */

/* The player's work (D_800FB270->unk_50: func_8000979C allocates a MgWork, 0xE8); MgWork's
   layout (src/99E0.c) with the fields this overlay touches; its pointers sit where MgWork's do. */
typedef struct TTPlayerWork {
    /* 0x00 */ char unk_00[0x3C];
    /* 0x3C */ f32 unk_3C; /* facing angle */
    /* 0x40 */ f32 unk_40; /* speed */
    /* 0x44 */ char unk_44[0xC];
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ s8 unk_53; /* platform object index (D_800F2AF8), -1 none */
    /* 0x54 */ s8 unk_54;
    /* 0x55 */ u8 unk_55;
    /* 0x56 */ s8 unk_56; /* controller port */
    /* 0x57 */ char unk_57[5];
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ char unk_60[0x58];
    /* 0xB8 */ void* unk_B8;
    /* 0xBC */ char unk_BC[0x1C];
    /* 0xD8 */ void* unk_D8;
    /* 0xDC */ void* unk_DC;
    /* 0xE0 */ char unk_E0[4];
    /* 0xE4 */ void* unk_E4;
} TTPlayerWork; /* size = 0xE8 (N64) */

#define TT_PLAYER(obj) ((TTPlayerWork*)(obj)->unk_50)
#define TT_PLATFORM(obj) ((TTPlatformWork*)(obj)->unk_50)

/* A camera key (176130.c): interpolated towards the next key over unk_1C frames; a list ends
   two keys after the last one with a zoom <= 0. No pointers. */
typedef struct TTCamKey {
    /* 0x00 */ f32 zoom;
    /* 0x04 */ Vec center;
    /* 0x10 */ Vec rot;
    /* 0x1C */ f32 time;
    /* 0x20 */ u8 unk_20[4];
} TTCamKey; /* size = 0x24 */

/* ---------------------------------------------------------------------------------------------
   Main-code declarations missing from the shared headers
   --------------------------------------------------------------------------------------------- */

extern omObjData* D_800EDE70[]; /* src/1130.c's collision list, D_800EE984 entries */
extern u16 D_800EE984;
extern omObjData* D_800F2AF8[];
extern f32 D_800B8964; /* src/1130.c */

void func_800090C4(omObjData* obj, u8 idx, u8 val);
void func_800091BC(omObjData*, s32, s32, s32);
void func_8002346C(s32, s32, s32);
void func_80060F04(s16, s16, s16, s16);

/* ---------------------------------------------------------------------------------------------
   Overlay functions, data and bss
   --------------------------------------------------------------------------------------------- */

void func_800F65E0_TeeteringTowers(void);
void func_800F6748_TeeteringTowers(omObjData*);
void func_800F6780_TeeteringTowers(omObjData*);
void func_800F6C20_TeeteringTowers(void);
void func_800F6C44_TeeteringTowers(s32*, s32*);
void func_800F6C58_TeeteringTowers(omObjData*);
void func_800F6CA0_TeeteringTowers(omObjData*);
void func_800F6CE4_TeeteringTowers(omObjData*);
u8 func_800F773C_TeeteringTowers(f32, f32);
void func_800F77E4_TeeteringTowers(s8*, s8*);
void func_800F7864_TeeteringTowers(void);
void func_800F7A94_TeeteringTowers(omObjData*);
void func_800F7EE4_TeeteringTowers(omObjData*);
void func_800F7FF0_TeeteringTowers(void);
void func_800F8094_TeeteringTowers(omObjData*, s32, s32, u16, f32, f32, f32);
void func_800F8330_TeeteringTowers(omObjData*);
void func_800F83F4_TeeteringTowers(omObjData*);
void func_800F85EC_TeeteringTowers(omObjData*);
void func_800F8AF4_TeeteringTowers(omObjData*);
void func_800F8DC0_TeeteringTowers(omObjData*);
s32 func_800F8E20_TeeteringTowers(void);

void func_800F8E30_TeeteringTowers(void);
void func_800F8E3C_TeeteringTowers(void);
s32 func_800F8EC8_TeeteringTowers(void);
void func_800F9940_TeeteringTowers(void);
s32 func_800F99F4_TeeteringTowers(void);
void func_800F9FD0_TeeteringTowers(void);
s32 func_800FA080_TeeteringTowers(void);
void func_800FA274_TeeteringTowers(void);
void func_800FA398_TeeteringTowers(void);
s32 func_800FA480_TeeteringTowers(void);
void func_800FA62C_TeeteringTowers(void);
void func_800FA6E8_TeeteringTowers(f32, TTCamKey*, TTCamKey*);

/* 1738E0.c .data */
extern s32 D_800FA930_TeeteringTowers; /* frame counter */
extern s32 D_800FA934_TeeteringTowers; /* game state */
extern s32 D_800FA938_TeeteringTowers; /* player index (retail reads its low half, D_800FA93A) */
extern s32 D_800FA93C_TeeteringTowers;
extern s32 D_800FA940_TeeteringTowers; /* result: 1 goal, 2 fell */
extern s32 D_800FA944_TeeteringTowers;
extern s32 D_800FA948_TeeteringTowers; /* platform being set up */
extern s32 D_800FA954_TeeteringTowers;
extern UnkTeeteringTowers0 D_800FA958_TeeteringTowers[];
extern s32 D_800FAD6C_TeeteringTowers;
extern s32 D_800FAD70_TeeteringTowers[14];
extern s32 D_800FADA8_TeeteringTowers; /* retail reads its low byte, D_800FADAB */
extern s32 D_800FADAC_TeeteringTowers;
extern s32 D_800FADB0_TeeteringTowers;
extern s32 D_800FADB4_TeeteringTowers;
extern s32 D_800FADB8_TeeteringTowers; /* retail reads its low half, D_800FADBA */
extern s32 D_800FADBC_TeeteringTowers;
extern s32 D_800FADC0_TeeteringTowers;

/* 176130.c .data */
extern f32 D_800FADD0_TeeteringTowers;
extern TTCamKey D_800FADD4_TeeteringTowers[3];
extern TTCamKey* D_800FAE40_TeeteringTowers;
extern s32 D_800FAE44_TeeteringTowers;
extern f32 D_800FAE48_TeeteringTowers;
extern s32 D_800FAE4C_TeeteringTowers;
extern s32 D_800FAE50_TeeteringTowers;
extern s32 D_800FAE54_TeeteringTowers;
extern f32 D_800FAE58_TeeteringTowers;
extern TTCamKey* D_800FAE5C_TeeteringTowers;
extern s32 D_800FAE60_TeeteringTowers;
extern TTCamKey D_800FAE64_TeeteringTowers[3];
extern f32 D_800FAED0_TeeteringTowers;
extern TTCamKey* D_800FAED4_TeeteringTowers;
extern s32 D_800FAED8_TeeteringTowers;
extern s32 D_800FAEDC_TeeteringTowers;
extern TTCamKey D_800FAEE0_TeeteringTowers[3];
extern f32 D_800FAF4C_TeeteringTowers;
extern TTCamKey* D_800FAF50_TeeteringTowers;
extern s32 D_800FAF54_TeeteringTowers;
extern s32 D_800FAF58_TeeteringTowers;
extern TTCamKey D_800FAF5C_TeeteringTowers[3];
extern f32 D_800FAFC8_TeeteringTowers;
extern TTCamKey* D_800FAFCC_TeeteringTowers;
extern s32 D_800FAFD0_TeeteringTowers;

/* bss */
extern ItemOnPlatform D_800FB1E0_TeeteringTowers[9];
extern omObjData* D_800FB270_TeeteringTowers; /* the player */
extern s32 D_800FB274_TeeteringTowers;

#endif
