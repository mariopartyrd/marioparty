#ifndef MARIOBANDSTAND_H
#define MARIOBANDSTAND_H

/* ovl_26 MarioBandstand: declarations shared by its three units (1CCCF0.c, 1CD680.c, 1D3040.c).
   Types come from the asm's accesses; N64 offsets are in the comments. Labels splat cut inside an
   object (D_800FD2E2 in D_800FD2D8, D_800FD5BA in D_800FD598, D_800FD6A8 in D_800FD6A0, ...) are
   never named in C: the code indexes the real object, so the host has one object per array. */

#include "common.h"
#include "engine/pad.h"

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* A band member's prop on the stage (D_800FD2D8[16]): a model that wobbles. No pointers. */
typedef struct MBProp {
    /* 0x00 */ s16 model;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ u16 state;
    /* 0x06 */ u16 timer;
    /* 0x08 */ s16 sub;
    /* 0x0A */ s16 x;
    /* 0x0C */ s16 y;
    /* 0x0E */ s16 z;
    /* 0x10 */ u16 dx;
    /* 0x12 */ u16 dy;
} MBProp; /* size = 0x14 */

/* A flying coin (D_800FD418[8]). No pointers. */
typedef struct MBCoin {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec vel;
    /* 0x18 */ s16 timer;
    /* 0x1A */ s16 state;
    /* 0x1C */ s16 model;
    /* 0x1E */ s16 pad1E;
} MBCoin; /* size = 0x20 */

/* A thrown item (the item object's unk_50: 8 of them, 0x160 bytes). No pointers. */
typedef struct MBItem {
    /* 0x00 */ Vec vel;
    /* 0x0C */ f32 rotX;
    /* 0x10 */ f32 rotY;
    /* 0x14 */ f32 rotZ;
    /* 0x18 */ Vec pos;
    /* 0x24 */ s16 model;
    /* 0x26 */ s16 model2;
    /* 0x28 */ s8 state;
    /* 0x29 */ u8 kind; /* low nibble: kind, high nibble (signed): player */
    /* 0x2A */ u8 type;
    /* 0x2B */ s8 timer;
} MBItem; /* size = 0x2C */

/* A player's CPU/score block (MBPlayerWork.unk_E4, 0x14 bytes). No pointers. */
typedef struct MBPlayerCpu {
    /* 0x00 */ u16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s32 score;
    /* 0x08 */ u8 port;
    /* 0x09 */ u8 level;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ s32 unk10;
} MBPlayerCpu; /* size = 0x14 */

/* The player object's work (unk_50: 0xE8 bytes, the minigame player layout). Pointers at 0xD8
   and 0xE4 as in every view of this work. */
typedef struct MBPlayerWork {
    /* 0x00 */ char unk_00[0x56];
    /* 0x56 */ s8 unk_56; /* controller port */
    /* 0x57 */ char unk_57;
    /* 0x58 */ s8 unk_58; /* player index */
    /* 0x59 */ char unk_59[0x47];
    /* 0xA0 */ f32 unk_A0;
    /* 0xA4 */ char unk_A4[0x14];
    /* 0xB8 */ void* unk_B8; /* MgWork's pointer: keeps unk_D8 where ActorWork.table is on the host */
    /* 0xBC */ char unk_BC[0x1C];
    /* 0xD8 */ s16 (*unk_D8)[2];
    /* 0xDC */ s32 unk_DC;
    /* 0xE0 */ char unk_E0[4];
    /* 0xE4 */ MBPlayerCpu* unk_E4;
} MBPlayerWork; /* size = 0xE8 (N64) */

/* One instrument's note track (D_800FD598[4]), filled from the audio driver's channel state. */
typedef struct MBTrack {
    /* 0x00 */ u8 ev[16][2]; /* {note, time} */
    /* 0x20 */ s16 count;
    /* 0x22 */ s16 timer;
    /* 0x24 */ s16 idx;
    /* 0x26 */ u16 unk26;
    /* 0x28 */ u16 unk28;
    /* 0x2A */ s16 note;
    /* 0x2C */ s16 base;
    /* 0x2E */ s16 unk2E;
    /* 0x30 */ s16 unk30;
    /* 0x32 */ s16 unk32;
    /* 0x34 */ s16 unk34;
    /* 0x36 */ u16 flags;
} MBTrack; /* size = 0x38 */

/* A song's beat list entry and its per-instrument table (D_800FCE7C and friends). */
typedef struct MBBeat {
    /* 0x00 */ u16 time;
    /* 0x02 */ s16 note;
} MBBeat;

typedef struct MBSong {
    /* 0x00 */ MBBeat* beats;
    /* 0x04 */ s32 count;
} MBSong;

/* A song's two per-track byte strings (D_800FCD94 and friends). */
typedef struct MBLoop {
    /* 0x00 */ u8* start;
    /* 0x04 */ u8* ev;
} MBLoop;

/* What func_800FB99C reports for a track. */
typedef struct MBBeatInfo {
    /* 0x00 */ s16 diff;
    /* 0x02 */ u16 len;
    /* 0x04 */ s32 idx;
    /* 0x08 */ s16 unk8;
} MBBeatInfo;

/* N64 sizes the asm allocates and strides by. */
typedef char MBSizeCheck[(sizeof(MBProp) == 0x14 && sizeof(MBCoin) == 0x20 && sizeof(MBItem) == 0x2C &&
                          sizeof(MBPlayerCpu) == 0x14 && sizeof(MBPlayerWork) == 0xE8 &&
                          sizeof(MBTrack) == 0x38 && sizeof(MBBeatInfo) == 0xC) ? 1 : -1];

/* ---------------------------------------------------------------------------------------------
   Main-code declarations missing from include/
   --------------------------------------------------------------------------------------------- */

typedef struct B980ChlInfo {
    /* 0x00 */ s32 program;
    /* 0x04 */ u8 vol;
    /* 0x05 */ u8 pan;
    /* 0x06 */ u8 fxmix;
} B980ChlInfo;

s32 func_8000C144(void);
void func_8000C5C4(void);
void func_8000C64C(s16);
void func_8000C748(u8, B980ChlInfo*);
u16 func_8001E1D0(s16, s32);
void func_80025BB8(s16, s16);
f32 func_80025D18(s16);
f32 func_80025D40(s16);
void func_8002859C(s16, s16, char*);
void func_800370D4(s16);
unk2C0C0Struct70* func_80038178(unk2C0C0StructC0*, u8*);
void func_80060440(s16, s16);
void func_80060F04(s16, s16, s16, s16);
extern u8 D_800F64F8;
extern u16 D_800C597C;
extern u8 D_800C5982;

/* ---------------------------------------------------------------------------------------------
   Functions
   --------------------------------------------------------------------------------------------- */

void func_800F6808_MarioBandstand(omObjData*);
void func_800F6828_MarioBandstand(void);
void func_800F68D4_MarioBandstand(void);
void func_800F6B04_MarioBandstand(void);
void func_800F6F10_MarioBandstand(void);
void func_800F6F70_MarioBandstand(void);
void func_800F7000_MarioBandstand(void);
s16 func_800F7090_MarioBandstand(omObjData*, s16);
void func_800F73E8_MarioBandstand(void);
void func_800F7458_MarioBandstand(void);
void func_800F74C8_MarioBandstand(omObjData*);
void func_800F7760_MarioBandstand(omObjData*);
void func_800F7B88_MarioBandstand(s32);
void func_800F7C1C_MarioBandstand(s32);
s32 func_800F7D58_MarioBandstand(void);
void func_800F7F7C_MarioBandstand(omObjData*);
void func_800F80B0_MarioBandstand(s16);
s16 func_800F81C0_MarioBandstand(s32);
void func_800F853C_MarioBandstand(void);
void func_800F87EC_MarioBandstand(omObjData*);
void func_800F8940_MarioBandstand(omObjData*);
void func_800F8C14_MarioBandstand(MBItem*);
void func_800F8FCC_MarioBandstand(MBItem*);
void func_800F92B4_MarioBandstand(omObjData*);
void func_800F93A4_MarioBandstand(omObjData*);
void func_800F9430_MarioBandstand(f32, f32, f32, s32);
void func_800F97D0_MarioBandstand(void);
void func_800F98C4_MarioBandstand(omObjData*);
void func_800FA028_MarioBandstand(omObjData*, s32);
s32 func_800FA448_MarioBandstand(omObjData*);
void func_800FA4F8_MarioBandstand(omObjData*);
void func_800FA790_MarioBandstand(s16, s16, s16, f32);
void func_800FA7EC_MarioBandstand(omObjData*, s32, s32);
void func_800FAA58_MarioBandstand(omObjData*);
void func_800FAC2C_MarioBandstand(omObjData*);
s32 func_800FAFEC_MarioBandstand(omObjData*, s32, s32);
s32 func_800FB0D8_MarioBandstand(omObjData*, s32, s32);
void func_800FB1D0_MarioBandstand(void);
void func_800FB214_MarioBandstand(void);
void func_800FB4D8_MarioBandstand(void);
s16 func_800FB8EC_MarioBandstand(s32);
s32 func_800FB99C_MarioBandstand(s32, MBBeatInfo*);
void func_800FBB14_MarioBandstand(void);
void func_800FBD1C_MarioBandstand(void);
void func_800FBD8C_MarioBandstand(void);
void func_800FBF68_MarioBandstand(omObjData*);
void func_800FC4E0_MarioBandstand(void);
void func_800FC744_MarioBandstand(omObjData*);
s8 func_800FC854_MarioBandstand(s8);
void func_800FC870_MarioBandstand(s32);
void func_800FC880_MarioBandstand(s32);
s32 func_800FC8A8_MarioBandstand(s32);
void func_800FC8B8_MarioBandstand(s32, MBBeatInfo*);
void func_800FC930_MarioBandstand(f32, f32, f32, f32, f32, f32, f32);
u32 func_800FC9D8_MarioBandstand(u32);
u32 func_800FCAAC_MarioBandstand(void);
#ifndef MB_1D3040
s16 func_800FCAD4_MarioBandstand(omObjData*, s32, s32, s32, u16, s16);
#endif

/* ---------------------------------------------------------------------------------------------
   .data
   --------------------------------------------------------------------------------------------- */

extern u16 D_800FCBF0_MarioBandstand;
extern u32 D_800FD190_MarioBandstand;

/* ---------------------------------------------------------------------------------------------
   .bss (ovl_26_bss)
   --------------------------------------------------------------------------------------------- */

extern u16 D_800FD280_MarioBandstand;
extern u16 D_800FD282_MarioBandstand;
extern u16 D_800FD284_MarioBandstand;
extern u16 D_800FD286_MarioBandstand;
extern s16 D_800FD288_MarioBandstand;
extern s32 D_800FD28C_MarioBandstand;
extern s32 D_800FD290_MarioBandstand;
extern s32 D_800FD294_MarioBandstand;
extern u16 D_800FD296_MarioBandstand;
extern f32 D_800FD2A0_MarioBandstand;
extern f32 D_800FD2A4_MarioBandstand;
extern s16 D_800FD2A8_MarioBandstand[4][2];
extern s16 D_800FD2B8_MarioBandstand;
extern s16 D_800FD2BA_MarioBandstand;
extern s16 D_800FD2BC_MarioBandstand[4];
extern s16 D_800FD2C4_MarioBandstand[4];
extern f32 D_800FD2CC_MarioBandstand;
extern s32 D_800FD2D0_MarioBandstand;
extern MBProp D_800FD2D8_MarioBandstand[16];
extern MBCoin D_800FD418_MarioBandstand[8];
extern s16 D_800FD518_MarioBandstand;
extern s16 D_800FD51A_MarioBandstand;
extern s16 D_800FD51C_MarioBandstand;
extern u16 D_800FD51E_MarioBandstand;
/* The best players of a round (ids, then their count): one object, retail indexes the count from
   the ids' base. */
typedef struct MBBest {
    /* 0x00 */ s16 id[4];
    /* 0x08 */ s16 count;
} MBBest;
extern MBBest D_800FD520_MarioBandstand;
extern s16 D_800FD530_MarioBandstand;
extern u8 D_800FD532_MarioBandstand[4];
extern s32 D_800FD538_MarioBandstand;
extern s32 D_800FD53C_MarioBandstand;
extern s32 D_800FD540_MarioBandstand;
extern s32 D_800FD544_MarioBandstand;
extern s32 D_800FD548_MarioBandstand;
extern s16 D_800FD54C_MarioBandstand[6];
extern s32 D_800FD558_MarioBandstand;
extern s32 D_800FD55C_MarioBandstand;
extern s16 D_800FD560_MarioBandstand;
extern s16 D_800FD562_MarioBandstand;
extern s16 D_800FD564_MarioBandstand;
extern MBSong* D_800FD568_MarioBandstand;
extern u8* D_800FD570_MarioBandstand[4];
extern u8* D_800FD580_MarioBandstand[4];
extern s8* D_800FD590_MarioBandstand;
extern MBTrack D_800FD598_MarioBandstand[4];
extern s32 D_800FD678_MarioBandstand;
extern s32 D_800FD67C_MarioBandstand;
extern s32 D_800FD680_MarioBandstand;
extern s16 D_800FD688_MarioBandstand[5];
extern s16 D_800FD6A0_MarioBandstand[9];
extern s32 D_800FD6B4_MarioBandstand;
extern u8 D_800FD6B8_MarioBandstand;
extern u8 D_800FD6B9_MarioBandstand;
extern f32 D_800FD6C0_MarioBandstand;
extern omObjData* D_800FD6D0_MarioBandstand[4];
extern s16 D_800FD6E0_MarioBandstand[16];
extern s16 D_800FD700_MarioBandstand[4];
extern omObjData* D_800FD708_MarioBandstand;
extern s16 D_800FD70C_MarioBandstand[4];
extern s16 D_800FD714_MarioBandstand;
extern omObjData* D_800FD718_MarioBandstand;
extern omObjData* D_800FD71C_MarioBandstand;

#endif
