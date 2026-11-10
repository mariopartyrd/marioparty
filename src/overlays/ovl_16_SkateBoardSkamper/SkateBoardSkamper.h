#ifndef SKATEBOARDSKAMPER_H
#define SKATEBOARDSKAMPER_H

/* ovl_16 SkateBoardSkamper: declarations for its one unit, 15EAF0.c.
   Types come from the asm's accesses; N64 offsets are in the comments. Work blocks are allocated
   with sizeof (never retail's literal size): the host strides pointers 8 bytes. */

#include "common.h"

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* A player's work (obj->unk_50, func_8000979C): MgWork's layout (src/99E0.c); pointers only at
   0xB8, 0xD8, 0xDC and 0xE4, so every field the overlay reads is at its N64 offset on the host. */
typedef struct SbsPlayerWork {
    /* 0x00 */ u8 unk_00[0x34]; /* per-floor flags (indexed by a D_800F2AF8 slot) and main-code fields */
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38; /* y speed; 1000.0f = on the ground */
    /* 0x3C */ f32 unk_3C; /* facing angle */
    /* 0x40 */ f32 unk_40; /* speed */
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48; /* collision radius */
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50; /* flags */
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ s8 unk_53; /* floor stood on (D_800F2AF8 slot), -1 none */
    /* 0x54 */ s8 unk_54;
    /* 0x55 */ s8 unk_55;
    /* 0x56 */ s8 unk_56; /* controller port */
    /* 0x57 */ u8 unk_57;
    /* 0x58 */ s8 unk_58; /* player index */
    /* 0x59 */ char unk_59[3];
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ f32 unk_60; /* camera yaw (CRot.y) */
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ f32 unk_68;
    /* 0x6C */ s32 unk_6C[6];
    /* 0x84 */ f32 unk_84; /* floor push x */
    /* 0x88 */ f32 unk_88;
    /* 0x8C */ f32 unk_8C; /* floor push z */
    /* 0x90 */ f32 unk_90; /* tilt x */
    /* 0x94 */ f32 unk_94;
    /* 0x98 */ f32 unk_98; /* tilt z */
    /* 0x9C */ char unk_9C[4];
    /* 0xA0 */ f32 unk_A0;
    /* 0xA4 */ f32 unk_A4;
    /* 0xA8 */ char unk_A8[0x10];
    /* 0xB8 */ void* unk_B8;
    /* 0xBC */ f32 unk_BC;
    /* 0xC0 */ u16 unk_C0;
    /* 0xC2 */ char unk_C2[0x16];
    /* 0xD8 */ void* unk_D8;
    /* 0xDC */ void* unk_DC;
    /* 0xE0 */ char unk_E0[4];
    /* 0xE4 */ void* unk_E4;
} SbsPlayerWork; /* size = 0xE8 (N64) */

#define SBS_PLAYER(obj) ((SbsPlayerWork*)(obj)->unk_50)

/* Work of the course objects in D_800F2AF8 (MgWork's first 0x2C bytes, src/1130.c's GroundWork;
   zeroed with func_8009B770 and filled by func_80009058). No pointers. */
typedef struct SbsFloorWork {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01; /* kind flags (0x1A: a box) */
    /* 0x02 */ char unk_02[2];
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05; /* course slot: 0 start, 1 goal ramp, 2 goal, 3-5 log rows, 6-11 tiles */
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C; /* push factor */
    /* 0x10 */ f32 unk_10; /* height */
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ char unk_28[4];
} SbsFloorWork; /* size = 0x2C */

#define SBS_FLOOR(obj) ((SbsFloorWork*)(obj)->unk_50)

/* Work of the four bodies added to D_800EDE70 (func_800F9B1C, func_80023684(0x6C)): fields up to
   0x64 follow src/1130.c's PlayerWork (no pointers there). unk_68 is the overlay's 4-byte extension
   (the body's index), past everything the main code reads. */
typedef struct SbsBodyWork {
    /* 0x00 */ u8 unk_00[0x34]; /* main-code fields; func_80009340 keeps a byte at 0x21 + slot */
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ s16 unk_50;
    /* 0x52 */ s8 unk_52;
    /* 0x53 */ char unk_53;
    /* 0x54 */ u8 unk_54;
    /* 0x55 */ char unk_55[7];
    /* 0x5C */ f32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ s32* unk_68; /* 8-aligned on the host too: every field keeps its N64 offset */
} SbsBodyWork; /* size = 0x6C (N64) */

/* ---------------------------------------------------------------------------------------------
   Data (.data, 15EAF0.c)
   --------------------------------------------------------------------------------------------- */

extern u32 D_800FDA00_SkateBoardSkamper; /* intro frames */
extern s16 D_800FDA04_SkateBoardSkamper; /* rolling sound handle, -1 none */
extern u8 D_800FDA08_SkateBoardSkamper[4]; /* finishing place + 1 per player, 0 still racing */
extern u8 D_800FDA0C_SkateBoardSkamper; /* players through the goal */
extern u8 D_800FDA0D_SkateBoardSkamper; /* players still in (counts down from 4) */
extern u8 D_800FDA0E_SkateBoardSkamper;
extern s8 D_800FDA0F_SkateBoardSkamper; /* winner, -1 none */
extern f32 D_800FDA10_SkateBoardSkamper; /* the chasing boulder's z */
extern f32 D_800FDA14_SkateBoardSkamper[4]; /* per-player jump tilt */
extern f32 D_800FDA24_SkateBoardSkamper[4]; /* tile row z positions per course slot (0 = none) */
extern f32 D_800FDA34_SkateBoardSkamper[4];
extern f32 D_800FDA44_SkateBoardSkamper[4];
extern f32 D_800FDA54_SkateBoardSkamper[4];
extern f32 D_800FDA64_SkateBoardSkamper[4];
extern f32 D_800FDA74_SkateBoardSkamper[4];
extern f32 D_800FDA84_SkateBoardSkamper[4]; /* log row z positions */
extern f32 D_800FDA94_SkateBoardSkamper[3];
extern f32 D_800FDAA0_SkateBoardSkamper[4];
extern s32 D_800FDAB0_SkateBoardSkamper[4]; /* players ordered by z (func_800F7C08) */
extern f32 D_800FDAC0_SkateBoardSkamper[4]; /* boost per place */
extern f32 D_800FDAD0_SkateBoardSkamper[4]; /* drag per place */
extern Vec D_800FDAE0_SkateBoardSkamper; /* the leader's position at the goal */
extern s32 D_800FDAEC_SkateBoardSkamper;
extern f32 D_800FDAF0_SkateBoardSkamper;
extern f32 D_800FDAF4_SkateBoardSkamper;
extern f32 D_800FDAF8_SkateBoardSkamper;
extern u32 D_800FDAFC_SkateBoardSkamper;
extern u32 D_800FDB00_SkateBoardSkamper;
extern s32 D_800FDB04_SkateBoardSkamper;
extern u8 D_800FDB08_SkateBoardSkamper;
extern char* D_800FDB0C_SkateBoardSkamper[6];
extern s32 D_800FDB24_SkateBoardSkamper;
extern s32 D_800FDB28_SkateBoardSkamper;
extern s32 D_800FDB2C_SkateBoardSkamper;
extern u8 D_800FDB30_SkateBoardSkamper[4];

/* ---------------------------------------------------------------------------------------------
   Bss (asm; link-map names)
   --------------------------------------------------------------------------------------------- */

extern s16 D_800FDD10_SkateBoardSkamper; /* six dust models */
extern s16 D_800FDD12_SkateBoardSkamper;
extern s16 D_800FDD14_SkateBoardSkamper;
extern s16 D_800FDD16_SkateBoardSkamper;
extern s16 D_800FDD18_SkateBoardSkamper;
extern s16 D_800FDD1A_SkateBoardSkamper;
extern u16 D_800FDD1C_SkateBoardSkamper[2]; /* "00mt037_DEF" (func_80039C48); [1] is splat's D_800FDD1E */
extern s16 D_800FDD20_SkateBoardSkamper;
extern s16 D_800FDD22_SkateBoardSkamper[4]; /* per-player voice id */

/* ---------------------------------------------------------------------------------------------
   Main code
   --------------------------------------------------------------------------------------------- */

extern omObjData* D_800EDE70[];
extern u16 D_800EE984;
extern omObjData* D_800F2AF8[];
extern u8 D_800F64F8;
extern u8 D_800F37F0;
extern f32 D_800EE738[];
extern f32 D_800B8960;
extern f32 D_800B8964;
extern f32 D_800B8968;
extern f32 D_800B8970;
extern f32 D_800B8980;
extern f32 D_800B8984;
extern f32 D_800B8988;
extern f32 D_800B898C;
extern f32 D_800B8990;
extern f32 D_800B8994;
extern f32 D_800B8998;
extern u8 D_800B8954;
extern u8 D_800B8958;
extern u8 D_800B8959;
extern f32 D_800ED6B8;
extern f32 D_800F5254;
extern s16 D_800F370C;
extern s8 ContStkY[4];

void func_80005A04(Object*);
f32 func_80004578(omObjData*, f32, f32, f32, f32);
s32 func_80004D1C(omObjData*, Vec4f*, f32);
f32 func_800051D4(omObjData*, f32, f32, f32, Vec3f*);
s32 func_80002060(void*, s16*, void*, Vec3f*);
void func_80008EF0(omObjData* obj, u16 idx, s32 dir, s32 file, f32 arg4);
void func_800090C4(omObjData* obj, u8 idx, u8 val);
void func_800091BC(omObjData* obj, s32 dir, s32 file, s32 arg3);
void func_800093FC(omObjData*, f32, f32, f32);
s32 func_80009C90(omObjData*, s16, s16);
void func_80009D48(s16*, s16*);
s32 func_8000A910(Vec4f*, void*);
s32 func_80017A60(omObjData*);
s32 func_800185A4(omObjData* obj, u16 motion);
f32 func_80025D18(s16);
f32 func_80025E70(s16);
void func_80027AC8(s16 arg0, u8* arg1, u8* arg2);
void func_80027E48(s16 arg0, f32 arg1, f32 arg2, u16 arg3, u16 arg4, char* arg5, u8 arg6);
void func_800295FC(void*, void*, void*, Vec3f*);
f32 func_80029764(f32, f32, f32, void*, void*);
void func_8002AE24(s16, s32*, void*, void*);
s16* func_8002B3A8(s32*);
void func_80037178(s16, Vec3f*);
void func_80060F04(s16, s16, s16, s16);
void func_8006073C(void);

/* ---------------------------------------------------------------------------------------------
   15EAF0.c
   --------------------------------------------------------------------------------------------- */

void func_800F65E0_SkateBoardSkamper(void);
void func_800F6CE4_SkateBoardSkamper(omObjData* obj);
void func_800F6EC8_SkateBoardSkamper(omObjData* obj);
void func_800F6F1C_SkateBoardSkamper(omObjData* obj, u8 state, u32 t);
void func_800F71B8_SkateBoardSkamper(omObjData* obj);
void func_800F7758_SkateBoardSkamper(omObjData* obj);
s32 func_800F7B7C_SkateBoardSkamper(s32 n, s32 player);
s32 func_800F7BC4_SkateBoardSkamper(s32 player);
void func_800F7C08_SkateBoardSkamper(void);
void func_800F7D50_SkateBoardSkamper(omObjData* obj);
void func_800F8158_SkateBoardSkamper(omObjData* obj);
void func_800F83C4_SkateBoardSkamper(omObjData* obj);
void func_800F849C_SkateBoardSkamper(omObjData* obj);
void func_800F85AC_SkateBoardSkamper(omObjData* obj);
void func_800F86F4_SkateBoardSkamper(omObjData* obj);
void func_800F8828_SkateBoardSkamper(omObjData* obj);
void func_800F895C_SkateBoardSkamper(omObjData* obj);
void func_800F8A90_SkateBoardSkamper(omObjData* obj);
void func_800F8BC4_SkateBoardSkamper(omObjData* obj);
void func_800F8CF8_SkateBoardSkamper(omObjData* obj);
void func_800F8EE8_SkateBoardSkamper(omObjData* obj);
void func_800F90D8_SkateBoardSkamper(omObjData* obj);
void func_800F92D0_SkateBoardSkamper(omObjData* obj, s32 dir, s32 file, s32 arg3, u16 player, f32 x, f32 y, f32 z);
void func_800F95B0_SkateBoardSkamper(omObjData* obj);
void func_800F9708_SkateBoardSkamper(omObjData* obj);
void func_800F9864_SkateBoardSkamper(omObjData* obj);
void func_800F99C0_SkateBoardSkamper(omObjData* obj);
SbsBodyWork* func_800F9B1C_SkateBoardSkamper(omObjData* obj, s32 dir, f32 x, f32 y, f32 z, s32 arg5, s32 arg6);
void func_800F9CB8_SkateBoardSkamper(omObjData* obj);
void func_800F9CF8_SkateBoardSkamper(omObjData* obj);
void func_800F9D3C_SkateBoardSkamper(omObjData* obj);
void func_800F9D80_SkateBoardSkamper(omObjData* obj);
void func_800F9DC4_SkateBoardSkamper(omObjData* obj);
void func_800FA2B8_SkateBoardSkamper(omObjData* obj);
void func_800FA3B4_SkateBoardSkamper(omObjData* obj);
void func_800FA498_SkateBoardSkamper(omObjData* obj);
void func_800FAC0C_SkateBoardSkamper(omObjData* obj);
void func_800FB380_SkateBoardSkamper(omObjData* obj);
void func_800FBAD4_SkateBoardSkamper(omObjData* obj);
void func_800FBC38_SkateBoardSkamper(s16 model, s16 n);
void func_800FBD7C_SkateBoardSkamper(omObjData* obj);
void func_800FBDA0_SkateBoardSkamper(omObjData* obj);
void func_800FBEE0_SkateBoardSkamper(omObjData* obj, Vec3f* n);
f32 func_800FC054_SkateBoardSkamper(omObjData* obj, f32 angle, f32 x, f32 y, f32 z);
void func_800FC758_SkateBoardSkamper(omObjData* obj);
void func_800FD764_SkateBoardSkamper(omObjData* obj);

#endif
