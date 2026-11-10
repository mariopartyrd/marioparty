#ifndef WHACKAPLANT_H
#define WHACKAPLANT_H

/* ovl_0F WhackAPlant: declarations shared by its units (131FA0, 136C10).
   Types come from the asm's accesses; N64 offsets in the comments. Work blocks that hold a
   pointer are allocated with sizeof (the host strides pointers 8 bytes). */

#include "common.h"
#include "engine/pad.h"

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* The player's CPU/state block (WAPPlayerWork::unkE4, 0x28 bytes). */
typedef struct WAPCpu {
    /* 0x00 */ u16 unk0; /* jump state */
    /* 0x02 */ s16 unk2; /* pot under the player, -1 none */
    /* 0x04 */ char unk4[2];
    /* 0x06 */ u16 unk6; /* stomp combo */
    /* 0x08 */ f32 unk8; /* end-of-game turn speed */
    /* 0x0C */ f32 unkC; /* end-of-game x step */
    /* 0x10 */ f32 unk10; /* end-of-game z step */
    /* 0x14 */ u16 unk14; /* CPU frames until it re-targets */
    /* 0x16 */ char unk16[2];
    /* 0x18 */ f32 unk18; /* CPU target angle */
    /* 0x1C */ f32 unk1C; /* CPU target distance */
    /* 0x20 */ f32 unk20; /* CPU target pot */
    /* 0x24 */ u16 unk24; /* bounced off a plant */
    /* 0x26 */ char unk26[2];
} WAPCpu; /* size = 0x28 */

/* The player object's work (func_8000979C allocates MgWork, 0xE8; src/99E0.c layout). */
typedef struct WAPPlayerWork {
    /* 0x00 */ char unk_00[0x38];
    /* 0x38 */ f32 unk38; /* vertical speed, 1000 = on the ground */
    /* 0x3C */ f32 unk3C; /* facing */
    /* 0x40 */ f32 unk40; /* speed */
    /* 0x44 */ f32 unk44;
    /* 0x48 */ f32 unk48; /* radius */
    /* 0x4C */ f32 unk4C;
    /* 0x50 */ u16 unk50; /* flags */
    /* 0x52 */ char unk52[4];
    /* 0x56 */ s8 unk56; /* controller port */
    /* 0x57 */ char unk57;
    /* 0x58 */ u8 unk58;
    /* 0x59 */ char unk59[0x5F];
    /* 0xB8 */ omObjData* unkB8; /* MgWork's held item: a pointer, so the host offsets agree */
    /* 0xBC */ char unkBC[0x1C];
    /* 0xD8 */ void* unkD8; /* MgWork's motion pair table */
    /* 0xDC */ void* unkDC; /* collision callback */
    /* 0xE0 */ char unkE0[4];
    /* 0xE4 */ WAPCpu* unkE4;
} WAPPlayerWork; /* size = 0xE8 (N64) */

/* A plant's state (WAPPlantWork::unk68, 0x1C bytes). */
typedef struct WAPPlant {
    /* 0x00 */ u16 unk0; /* 0 rising, 1 snapping, 2 sinking, 3 stomped */
    /* 0x02 */ s16 unk2; /* model */
    /* 0x04 */ u16 unk4; /* pot */
    /* 0x06 */ u16 unk6; /* frames left in the state */
    /* 0x08 */ u16 unk8; /* rise time */
    /* 0x0A */ u16 unkA; /* snap time */
    /* 0x0C */ u16 unkC; /* sink time */
    /* 0x0E */ char unkE[0xE];
} WAPPlant; /* size = 0x1C */

/* The work of the nine plant collision objects (D_800EDE70's list; src/1130.c's PlayerWork /
   CoinBlockBlitz's CBBCoinWork layout). */
typedef struct WAPPlantWork {
    /* 0x00 */ char unk_00[0x34];
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
    /* 0x3C */ f32 unk3C;
    /* 0x40 */ f32 unk40;
    /* 0x44 */ f32 unk44;
    /* 0x48 */ f32 unk48;
    /* 0x4C */ f32 unk4C;
    /* 0x50 */ u16 unk50;
    /* 0x52 */ u8 unk52;
    /* 0x53 */ char unk53;
    /* 0x54 */ u8 unk54;
    /* 0x55 */ char unk55[7];
    /* 0x5C */ s32 unk5C;
    /* 0x60 */ f32 unk60;
    /* 0x64 */ char unk64[4];
    /* 0x68 */ WAPPlant* unk68;
} WAPPlantWork; /* size = 0x6C (N64) */

/* The pots object's work (D_800FB6FC, 0xC0 bytes). */
typedef struct WAPPots {
    /* 0x00 */ u16 unk0; /* a wave is up */
    /* 0x02 */ u16 unk2[9]; /* plant up in pot i */
    /* 0x14 */ u16 unk14;
    /* 0x16 */ u16 unk16[3]; /* shock ring in use */
    /* 0x1C */ f32 unk1C[9]; /* pot brightness */
    /* 0x40 */ char unk40[0x80];
} WAPPots; /* size = 0xC0 */

/* The fence object's work (D_800FB708, 0x44 bytes): four fence models. */
typedef struct WAPFence {
    /* 0x00 */ f32 unk0[4]; /* x */
    /* 0x10 */ f32 unk10[4]; /* z */
    /* 0x20 */ f32 unk20[4]; /* y scale */
    /* 0x30 */ f32 unk30[4]; /* wobble phase */
    /* 0x40 */ u8 unk40[4]; /* recovering from a bump */
} WAPFence; /* size = 0x44 */

/* A shock ring (func_800F968C, 0x1C bytes). */
typedef struct WAPRing {
    /* 0x00 */ u16 unk0; /* ring slot */
    /* 0x04 */ f32 unk4; /* radius */
    /* 0x08 */ u16 unk8; /* frames left */
    /* 0x0C */ f32 unkC; /* scale */
    /* 0x10 */ f32 unk10; /* fall speed */
    /* 0x14 */ f32 unk14; /* fall acceleration */
    /* 0x18 */ s16 unk18;
} WAPRing; /* size = 0x1C */

/* A coin (func_800F998C, 0xC bytes). */
typedef struct WAPCoin {
    /* 0x00 */ u16 unk0; /* sprite slot */
    /* 0x02 */ u16 unk2; /* 0 rising, 1 collected */
    /* 0x04 */ f32 unk4; /* rise speed */
    /* 0x08 */ u16 unk8; /* frames */
} WAPCoin; /* size = 0xC */

/* One wave of plants (D_800FB5C8). */
typedef struct WAPWave {
    /* 0x00 */ u16 count;
    /* 0x02 */ u16 rise;
    /* 0x04 */ u16 snap;
    /* 0x06 */ u16 sink;
} WAPWave;

/* objmain.c's group table (D_800ED618): only group 1's count is read here. */
typedef struct WAPGrpData {
    /* 0x00 */ u16 next;
    /* 0x02 */ u16 max;
    /* 0x04 */ u16 num;
    /* 0x08 */ u16* nextIdx;
    /* 0x0C */ omObjData** obj;
} WAPGrpData;

/* ---------------------------------------------------------------------------------------------
   Functions
   --------------------------------------------------------------------------------------------- */

void func_800F6B8C_WhackAPlant(void);
void func_800F6BC4_WhackAPlant(omObjData* arg0);
void func_800F6D54_WhackAPlant(void);
void func_800F6DBC_WhackAPlant(omObjData* arg0);
void func_800F6FE4_WhackAPlant(omObjData* arg0);
void func_800F70AC_WhackAPlant(omObjData* arg0);
void func_800F7570_WhackAPlant(omObjData* arg0);
void func_800F7714_WhackAPlant(omObjData* arg0);
void func_800F7AE0_WhackAPlant(omObjData* arg0);
void func_800F7F90_WhackAPlant(omObjData* arg0);
void func_800F8098_WhackAPlant(omObjData* arg0);
void func_800F8134_WhackAPlant(omObjData* arg0);
void func_800F82B4_WhackAPlant(omObjData* arg0);
void func_800F8614_WhackAPlant(omObjData* arg0);
void func_800F87EC_WhackAPlant(omObjData* arg0);
omObjData* func_800F8A58_WhackAPlant(omObjData* arg0, u16 arg1, void* arg2);
void func_800F8BE8_WhackAPlant(omObjData* arg0);
s32 func_800F92FC_WhackAPlant(omObjData* arg0, omObjData* arg1);
void func_800F968C_WhackAPlant(s16 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
void func_800F97F8_WhackAPlant(omObjData* arg0);
void func_800F998C_WhackAPlant(u16 arg0);
void func_800F9AF4_WhackAPlant(omObjData* arg0);
void func_800F9D38_WhackAPlant(omObjData* arg0);
void func_800F9E44_WhackAPlant(omObjData* arg0);
void func_800FA078_WhackAPlant(void);
void func_800FA1E0_WhackAPlant(void);
void func_800FA668_WhackAPlant(void);
void func_800FA6AC_WhackAPlant(s16 arg0, f32 arg1);
void func_800FA760_WhackAPlant(omObjData* arg0);
f32 func_800FAF34_WhackAPlant(f32 arg0, f32 arg1, u16 arg2, f32* arg3, u16* arg4);
u16 func_800FB138_WhackAPlant(void);
void func_800FB250_WhackAPlant(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
void func_800FB308_WhackAPlant(omObjData* arg0, s16 arg1, f32 arg2, f32 arg3, f32 arg4);
void func_800FB378_WhackAPlant(omObjData* arg0, s16 arg1, f32 arg2, f32 arg3, f32 arg4);
s32 func_800FB3E8_WhackAPlant(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
f32 func_800FB43C_WhackAPlant(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_800FB4C0_WhackAPlant(s32);
void func_800FB4DC_WhackAPlant(void);

void func_80008EF0(omObjData* obj, u16 idx, s32 dir, s32 file, f32 arg4);
void func_800090C4(omObjData* obj, u8 idx, u8 val);
void func_80060F04(s16, s16, s16, s16);
s32 func_80017A60(omObjData* obj);
void func_80025BB8(s16, s16);
omObjData* func_8005DB5C(s16 grp, u16 idx);
/* Retail calls it with an s16 pot index (no zero-extension of the lh); same value on the host. */
#define func_8005DB5C_s16(grp, idx) ((omObjData* (*)(s16, s16))func_8005DB5C)((grp), (idx))
void func_8005DB84(s16 grp, s32 bit);
void func_8001E268(s16, u8, u8);
void func_8001E2A8(s16, u16);
u16 func_8001E00C(void*, s32, u8);
void func_80025930(s16, s32, s32);
void func_8001E2F8(s16, u8);
void func_8001E360(s16, u8, u8, u8);

/* ---------------------------------------------------------------------------------------------
   Data (131FA0.c) and .bss
   --------------------------------------------------------------------------------------------- */

extern f32 D_800FB580_WhackAPlant[9][2]; /* pot x, z */
extern WAPWave D_800FB5C8_WhackAPlant[8];
extern u16 D_800FB608_WhackAPlant;
extern u16 D_800FB60A_WhackAPlant;
extern f32 D_800FB60C_WhackAPlant;
extern f32 D_800FB610_WhackAPlant;
extern f32 D_800FB614_WhackAPlant;
extern f32 D_800FB618_WhackAPlant;
extern u16 D_800FB61C_WhackAPlant;
extern u16 D_800FB61E_WhackAPlant;
extern u16 D_800FB620_WhackAPlant;
extern s16 D_800FB622_WhackAPlant;
extern s16 D_800FB624_WhackAPlant;

extern s32 D_800FB690_WhackAPlant;
extern u16 D_800FB694_WhackAPlant; /* frame timer */
/* The voice clip base sits in the same splat label (retail's %lo(D_800FB694 + 2)). */
#define D_800FB696_WhackAPlant (((s16*)&D_800FB694_WhackAPlant)[1])
extern s16 D_800FB698_WhackAPlant;
extern u16 D_800FB69A_WhackAPlant;
extern s16 D_800FB69C_WhackAPlant;
extern u16 D_800FB69E_WhackAPlant;
extern u16 D_800FB6A0_WhackAPlant;
extern s16 D_800FB6A2_WhackAPlant;
extern u16 D_800FB6A4_WhackAPlant;
extern u16 D_800FB6A8_WhackAPlant[9];
extern u16 D_800FB6BA_WhackAPlant;
extern u16 D_800FB6BC_WhackAPlant;
extern s16 D_800FB6C0_WhackAPlant[];
extern s16 D_800FB6D8_WhackAPlant[];
extern u8 D_800FB6EA_WhackAPlant[];
extern u16 D_800FB6F4_WhackAPlant;
extern omObjData* D_800FB6F8_WhackAPlant;
extern omObjData* D_800FB6FC_WhackAPlant;
extern omObjData* D_800FB700_WhackAPlant;
extern omObjData* D_800FB704_WhackAPlant;
extern omObjData* D_800FB708_WhackAPlant;
extern u16 D_800FB710_WhackAPlant;
extern u16 D_800FB712_WhackAPlant;
/* Camera block: D_800FB714 is a Vec3f over splat's D_800FB714/D_800FB718 labels. */
extern Vec3f D_800FB714_WhackAPlant;
extern f32 D_800FB718_WhackAPlant;
extern u16 D_800FB720_WhackAPlant; /* player index; its low byte read as u8 */
extern Vec3f D_800FB724_WhackAPlant;
extern u16 D_800FB730_WhackAPlant;
extern Vec3f D_800FB734_WhackAPlant;
extern u16 D_800FB740_WhackAPlant;

extern f32 D_800EE738[];
extern omObjData* D_800F2AF8[];
extern s16 D_800F3778;
extern omObjData* D_800EDE70[];
extern u16 D_800EE984;
extern omObjData* D_800F3FB0[];
extern WAPGrpData D_800ED618[10];
extern u8 D_800F64F8;
extern f32 D_800B895C;
extern f32 D_800B8968;
extern f32 D_800B896C;

#endif
