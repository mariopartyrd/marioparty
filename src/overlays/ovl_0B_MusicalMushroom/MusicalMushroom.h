#ifndef MUSICALMUSHROOM_H
#define MUSICALMUSHROOM_H

/* ovl_0B MusicalMushroom: declarations shared by its units (11C810, 11F890).
   Types come from the asm's accesses; N64 offsets are in the comments. */

#include "common.h"
#include "engine/pad.h"

/* Per-player CPU/input state (D_800FB6B8[4]). */
typedef struct MMCpu {
    /* 0x00 */ u16 unk0; /* flags: 1 CPU */
    /* 0x02 */ u16 unk2; /* CPU state */
    /* 0x04 */ u16 unk4; /* CPU difficulty */
    /* 0x06 */ u16 unk6; /* strategy (index into the CPU routine table) */
    /* 0x08 */ u16 unk8; /* timer */
    /* 0x0A */ u16 unkA; /* reaction delay */
    /* 0x0C */ u16 unkC; /* delay counter */
    /* 0x0E */ u16 unkE; /* target mushroom (D_800FB5C8 index), 100 none */
    /* 0x10 */ f32 unk10; /* target distance */
    /* 0x14 */ s16 unk14; /* stick x */
    /* 0x16 */ s16 unk16; /* stick y */
    /* 0x18 */ u16 unk18; /* buttons pressed */
    /* 0x1A */ u16 unk1A; /* buttons held */
    /* 0x1C */ s16 unk1C; /* saved ContStkX */
    /* 0x1E */ s16 unk1E; /* saved ContStkY */
    /* 0x20 */ u16 unk20; /* saved ContBtnTrg */
    /* 0x22 */ u16 unk22; /* saved ContBtn */
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ u16 unk2C; /* frames in state 1 */
} MMCpu; /* size = 0x30 */

/* A player's work (obj->unk_50): the first 0xB4 bytes of MgWork (99E0.c), which hold no
   pointer, so this view agrees with the host layout. */
typedef struct MMPlayerWork {
    /* 0x00 */ char unk_00[0x21];
    /* 0x21 */ u8 unk_21[4]; /* sprite of model[i] */
    /* 0x25 */ char unk_25[0x13];
    /* 0x38 */ f32 unk_38; /* vertical speed; 1000.0f on the ground */
    /* 0x3C */ f32 unk_3C; /* heading */
    /* 0x40 */ f32 unk_40; /* speed */
    /* 0x44 */ char unk_44[4];
    /* 0x48 */ f32 unk_48; /* radius */
    /* 0x4C */ char unk_4C[4];
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ s8 unk_53; /* mushroom stood on, -1 none */
    /* 0x54 */ s8 unk_54;
    /* 0x55 */ char unk_55[1];
    /* 0x56 */ u8 unk_56; /* controller port */
    /* 0x57 */ char unk_57[1];
    /* 0x58 */ s8 unk_58; /* GwPlayer index */
    /* 0x59 */ char unk_59[0x4B];
    /* 0xA4 */ f32 unk_A4;
    /* 0xA8 */ char unk_A8[0xB];
    /* 0xB3 */ s8 unk_B3;
} MMPlayerWork;

/* D_800FB658[4]: a player object and its work. */
typedef struct MMPlayer {
    /* 0x00 */ omObjData* obj;
    /* 0x04 */ MMPlayerWork* work;
} MMPlayer; /* size = 0x8 (N64) */

/* 11C810 .data */
extern s32 D_800FB4C0_MusicalMushroom;
extern u32 D_800FB4D0_MusicalMushroom;
extern s32 D_800FB4D4_MusicalMushroom;
extern u32 D_800FB4D8_MusicalMushroom;
extern u32 D_800FB4DC_MusicalMushroom;
extern u32 D_800FB4E0_MusicalMushroom;
extern s32 D_800FB4E4_MusicalMushroom;
extern u32 D_800FB4E8_MusicalMushroom;
extern s32 D_800FB4EC_MusicalMushroom;
extern s32 D_800FB4F0_MusicalMushroom;
extern u32 D_800FB4F4_MusicalMushroom;
extern s32 D_800FB4F8_MusicalMushroom;
extern s32 D_800FB4FC_MusicalMushroom; /* shared model ids; 0x80 until loaded */
extern s32 D_800FB500_MusicalMushroom;
extern s32 D_800FB504_MusicalMushroom;
extern s32 D_800FB508_MusicalMushroom;
extern f32 D_800FB50C_MusicalMushroom[5];

/* .bss */
extern f32 D_800FB5A0_MusicalMushroom;
extern f32 D_800FB5A4_MusicalMushroom;
extern f32 D_800FB5C0_MusicalMushroom;
extern Vec3f D_800FB5C8_MusicalMushroom[10];
extern u16 D_800FB5B0_MusicalMushroom;
extern s32 D_800FB640_MusicalMushroom;
extern omObjData* D_800FB644_MusicalMushroom;
extern s32 D_800FB648_MusicalMushroom;
extern f32 D_800FB64C_MusicalMushroom;
extern u16 D_800FB650_MusicalMushroom;
extern u16 D_800FB652_MusicalMushroom;
extern MMPlayer D_800FB658_MusicalMushroom[4];
extern f32 D_800FB678_MusicalMushroom;
extern omObjData* D_800FB680_MusicalMushroom[9];
extern s32 D_800FB6A4_MusicalMushroom; /* player on the bell mushroom, -1 none */
extern f32 D_800FB6A8_MusicalMushroom;
extern f32 D_800FB6AC_MusicalMushroom;
extern u16 D_800FB6B0_MusicalMushroom[4]; /* player order (shuffled) */
extern MMCpu D_800FB6B8_MusicalMushroom[4];
extern f32 D_800FB778_MusicalMushroom[4];
extern f32 D_800FB788_MusicalMushroom;
extern s32 D_800FB78C_MusicalMushroom; /* winner, 4 none yet, 5 nobody */
extern f32 D_800FB790_MusicalMushroom;

extern u16 D_800EE984;
extern f32 D_800B8968;
extern f32 D_800B8980;
extern f32 D_800ED6B8;
extern f32 D_800F5254;
extern omObjData* D_800F2AF8[];

/* Engine functions without a shared prototype. */
void func_80009458(void);
void func_80009624(unkGlobalStruct_00*, s32);
void func_80017DB0(omObjData*);
f32 func_80029518(f32);
void func_8006B9B0(omObjData*, f32, f32, f32);
void func_8006BAD0(omObjData*, f32);
void func_8006BADC(omObjData*, f32, f32, f32);
void func_8006BAF0(omObjData*, s32);
s32 func_8006BAFC(omObjData*);
s32 func_80017A60(omObjData*);
void func_800090D8(omObjData*, u8, u8);
void func_8001E268(s16, u8, u8);
void func_8001E2A8(s16, u16);
void func_80008FDC(omObjData*, f32);
void func_80008FE8(omObjData*, f32);
void func_800090C4(omObjData* obj, u8 idx, u8 val);
void func_80060F04(s16, s16, s16, s16);
f32 func_80025D18(s16);
f32 func_80025D40(s16);

/* 11C810 */
void func_800F65E0_MusicalMushroom(void);
void func_800F6D40_MusicalMushroom(omObjData*);
void func_800F6D8C_MusicalMushroom(void);
void func_800F6E98_MusicalMushroom(void);
void func_800F6F60_MusicalMushroom(omObjData*);
void func_800F71C8_MusicalMushroom(omObjData*);
void func_800F71E4_MusicalMushroom(void);
void func_800F71EC_MusicalMushroom(omObjData*);
void func_800F7338_MusicalMushroom(omObjData*);
void func_800F7484_MusicalMushroom(omObjData*, f32, f32, s32);
void func_800F7508_MusicalMushroom(omObjData*, f32*);
void func_800F75D8_MusicalMushroom(omObjData*);
void func_800F76E8_MusicalMushroom(omObjData*);
void func_800F78A8_MusicalMushroom(omObjData*, MMCpu*);
s32 func_800F79FC_MusicalMushroom(omObjData*, MMPlayerWork*);
f32 func_800F7B84_MusicalMushroom(omObjData*, f32, f32, f32, f32, f32);
void func_800F7D1C_MusicalMushroom(omObjData*);
void func_800F83BC_MusicalMushroom(omObjData*);
u8 func_800F8830_MusicalMushroom(u16);
s32 func_800F8898_MusicalMushroom(u16, s32); /* callers test its low byte */
void func_800F8910_MusicalMushroom(omObjData*);
void func_800F8AC4_MusicalMushroom(omObjData*);
s32 func_800F8D20_MusicalMushroom(s32);
void func_800F8EE0_MusicalMushroom(omObjData*);
void func_800F91C8_MusicalMushroom(omObjData*);
void func_800F9338_MusicalMushroom(omObjData*);

/* 11F890 */
void func_800F9660_MusicalMushroom(omObjData*);
u16 func_800F9EFC_MusicalMushroom(s32, s32, s32, u16);
void func_800F9D70_MusicalMushroom(omObjData*);
void func_800F9FE0_MusicalMushroom(omObjData*, u8, s32, s32, s32, u16);
void func_800FA0A0_MusicalMushroom(omObjData*);
void func_800FA0B0_MusicalMushroom(omObjData*, Vec3f*);
void func_800FA170_MusicalMushroom(omObjData*, s32, f32);
void func_800FA2F4_MusicalMushroom(omObjData*, s32, s32, s32, f32);
void func_800FA7C8_MusicalMushroom(omObjData*);
void func_800FA914_MusicalMushroom(omObjData*, Vec3f*, Vec3f*);
void func_800FAAA0_MusicalMushroom(omObjData*, Vec3f*);
void func_800FABE8_MusicalMushroom(omObjData*);
void func_800FAC38_MusicalMushroom(omObjData*);
void func_800FAC58_MusicalMushroom(omObjData*);
void func_800FACA4_MusicalMushroom(omObjData*);
void func_800FACF4_MusicalMushroom(omObjData*);
void func_800FAD50_MusicalMushroom(omObjData*);
void func_800FADAC_MusicalMushroom(omObjData*);
void func_800FAE08_MusicalMushroom(omObjData*);
void func_800FAE74_MusicalMushroom(omObjData*);
void func_800FAEE0_MusicalMushroom(omObjData*);
void func_800FAF4C_MusicalMushroom(omObjData*);
void func_800FAFB8_MusicalMushroom(omObjData*);
void func_800FB028_MusicalMushroom(omObjData*);
void func_800FB098_MusicalMushroom(omObjData*);
void func_800FB108_MusicalMushroom(omObjData*);
void func_800FB180_MusicalMushroom(omObjData*);
void func_800FB1F0_MusicalMushroom(omObjData*);
void func_800FB240_MusicalMushroom(omObjData*);
void func_800FB290_MusicalMushroom(omObjData*);
void func_800FB2E4_MusicalMushroom(omObjData*);
void func_800FB338_MusicalMushroom(omObjData*);
void func_800FB384_MusicalMushroom(omObjData*);
void func_800FB3D0_MusicalMushroom(omObjData*);
void func_800FB41C_MusicalMushroom(omObjData*);
void func_800FB468_MusicalMushroom(omObjData*);

#endif
