#ifndef KEYPAWAY_H
#define KEYPAWAY_H

/* ovl_2C KeyPaWay: declarations shared by its units (1F62C0, 1FDF10).
   Types come from the asm's accesses. N64 offsets are in the comments; a struct with no pointers
   has the same layout on the host. Allocate every work block with sizeof (never retail's literal
   size): the host strides pointers 8 bytes. */

#include "common.h"
#include "engine/pad.h"

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

typedef struct unk_ovl3C_struct {
/* 0x00 */ f32 unk_00;
/* 0x04 */ f32 unk_04;
/* 0x08 */ f32 unk_08;
/* 0x0C */ f32 unk_0C;
/* 0x10 */ f32 unk_10;
/* 0x14 */ f32 unk_14;
} unk_ovl3C_struct;

/* D_800FF55C's work (func_800F6D98/func_800F6E04/func_800F6E6C). */
typedef struct unkKeyPaWayStruct {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ char unk_02[2];
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
} unkKeyPaWayStruct; //sizeof 0x10

/* objmain.c's private objmainChr (D_800C59A8[6]); func_800F8CC4 reads .index (lhu) and .file0
   (retail's D_800C59B0). The (chr << 16 | unk06) word is D_800C59AC[c].unk_00 (the host view). */
typedef struct KPWChr {
    /* 0x00 */ s16 index;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s16 chr;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ s32 file0;
    /* 0x0C */ s32 file1;
    /* 0x10 */ f32 scale;
} KPWChr; /* size = 0x14 */

/* The four player objects' work (D_800FF594[i]->unk_50: func_8000979C allocates a MgWork, 0xE8).
   This is MgWork's layout (src/99E0.c) with the fields this overlay touches; its pointers sit
   where MgWork's do (0xB8, 0xD8, 0xE4) so the host layout agrees with the allocator's.
   unk_DC is the collision callback src/1130.c calls (func_800FB748 here). */
typedef struct KPWPlayerWork {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01; /* flags */
    /* 0x02 */ char unk_02[3];
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ char unk_28[0xC];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38; /* 1000.0f = out of play (func_800F6F10) */
    /* 0x3C */ f32 unk_3C; /* facing angle */
    /* 0x40 */ f32 unk_40; /* speed */
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48; /* collision radius */
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50; /* flags: 0x20 holding an item */
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ s8 unk_53; /* lb */
    /* 0x54 */ s8 unk_54;
    /* 0x55 */ u8 unk_55;
    /* 0x56 */ s8 unk_56; /* controller port (lb and lbu) */
    /* 0x57 */ u8 unk_57;
    /* 0x58 */ s8 unk_58; /* player index (lb) */
    /* 0x59 */ char unk_59[3];
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ f32 unk_68;
    /* 0x6C */ s32 unk_6C[6];
    /* 0x84 */ char unk_84[0xC];
    /* 0x90 */ f32 unk_90;
    /* 0x94 */ f32 unk_94;
    /* 0x98 */ f32 unk_98;
    /* 0x9C */ s16 unk_9C; /* sh only */
    /* 0x9E */ char unk_9E[2];
    /* 0xA0 */ f32 unk_A0;
    /* 0xA4 */ f32 unk_A4;
    /* 0xA8 */ char unk_A8[6];
    /* 0xAE */ u16 unk_AE;
    /* 0xB0 */ u8 unk_B0;
    /* 0xB1 */ s8 unk_B1;
    /* 0xB2 */ s8 unk_B2;
    /* 0xB3 */ s8 unk_B3;
    /* 0xB4 */ char unk_B4[4];
    /* 0xB8 */ omObjData* unk_B8; /* held item */
    /* 0xBC */ f32 unk_BC;
    /* 0xC0 */ u16 unk_C0;
    /* 0xC2 */ char unk_C2[0x16];
    /* 0xD8 */ s16 (*unk_D8)[2]; /* one pair per motion */
    /* 0xDC */ s32 (*unk_DC)(omObjData*, omObjData*);
    /* 0xE0 */ char unk_E0[4]; /* PlayerWork's u16 unk_E0 (1130.c) */
    /* 0xE4 */ struct KPWPlayerExt* unk_E4;
} KPWPlayerWork; /* size = 0xE8 */

#define KPW_PLAYER(obj) ((KPWPlayerWork*)(obj)->unk_50)

/* The overlay's per-player extension (KPWPlayerWork.unk_E4; func_80023684(0x3C) in
   func_800F8CC4). No pointers. */
typedef struct KPWPlayerExt {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ char unk_02[2];
    /* 0x04 */ f32 unk_04; /* not accessed */
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ u16 unk_14;
    /* 0x16 */ u16 unk_16; /* row into D_800FF310 (func_800FCCB0) */
    /* 0x18 */ u16 unk_18; /* column into D_800FF310 */
    /* 0x1A */ char unk_1A[2];
    /* 0x1C */ f32 unk_1C; /* target x (D_800FF310[..][..][0]) */
    /* 0x20 */ f32 unk_20; /* target z */
    /* 0x24 */ u16 unk_24;
    /* 0x26 */ u16 unk_26;
    /* 0x28 */ u16 unk_28;
    /* 0x2A */ char unk_2A[2];
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ u16 unk_30;
    /* 0x32 */ u16 unk_32;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
} KPWPlayerExt; /* size = 0x3C */

/* The key's extension (D_800FF590's KPWBodyWork.unk_68.key; func_80023684(0x28) in func_800F76C8). */
typedef struct KPWKeyExt {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ char unk_02[2];
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18; /* x offset from the carrier */
    /* 0x1C */ f32 unk_1C; /* z offset */
    /* 0x20 */ u16 unk_20;
    /* 0x22 */ u16 unk_22;
    /* 0x24 */ omObjData* unk_24; /* last carrier (KPWBodyWork.unk_64) */
} KPWKeyExt; /* size = 0x28 (N64) */

/* The five group-1 objects' extension (D_800FF548[i]; KPWBodyWork.unk_68.enemy; func_80023684(0x38)
   in func_800FA59C). */
typedef struct KPWEnemyExt {
    /* 0x00 */ char unk_00[2];
    /* 0x02 */ u16 unk_02; /* own index into D_800FF548 (func_800FA450's arg1) */
    /* 0x04 */ u16 unk_04; /* state */
    /* 0x06 */ u16 unk_06; /* func_800FA59C's arg1 */
    /* 0x08 */ u16 unk_08;
    /* 0x0A */ u16 unk_0A;
    /* 0x0C */ omObjData* unk_0C; /* chase target: a player, D_800FF590 or D_800FF57C */
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C; /* only sw $zero */
    /* 0x20 */ char unk_20[4];
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ u16 unk_28;
    /* 0x2A */ s16 unk_2A; /* sprite id (func_8001E00C) */
    /* 0x2C */ s16 unk_2C; /* its model (D_800ECDE0[unk_2A].unk_00) */
    /* 0x2E */ char unk_2E[2];
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ u16 unk_34;
    /* 0x36 */ char unk_36[2];
} KPWEnemyExt; /* size = 0x38 (N64) */

/* Work of the bodies added to D_800EDE70 (src/1130.c's collision list): the key D_800FF590
   (func_800F76C8) and the five group-1 objects (func_800FA450), func_80023684(0x6C). Fields up to
   0x64 follow src/1130.c's PlayerWork and 99E0.c's MgItemWork (0x64 = carrier). */
typedef struct KPWBodyWork {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ char unk_02[2];
    /* 0x04 */ char unk_04[0x30];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C; /* facing angle (func_800FB38C) */
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50; /* flags: 0x20 carried, 0x40 can be picked up */
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ char unk_53;
    /* 0x54 */ u8 unk_54;
    /* 0x55 */ char unk_55[3];
    /* 0x58 */ f32 unk_58;
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ f32 unk_60; /* only sw $zero */
    /* 0x64 */ omObjData* unk_64; /* carrier */
    /* 0x68 */ union {
        KPWKeyExt* key;     /* D_800FF590 */
        KPWEnemyExt* enemy; /* D_800FF548[i] */
    } unk_68;
} KPWBodyWork; /* size = 0x6C (N64) */

#define KPW_BODY(obj) ((KPWBodyWork*)(obj)->unk_50)

/* Work of D_800FF53C (func_800F747C) and D_800FF560 (func_800FB9D4): MgWork's first 0x2C bytes,
   zeroed with func_8009B770 and filled by func_80009028/func_80009058. */
typedef struct KPWStageWork {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ char unk_02[2];
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ char unk_28[4];
} KPWStageWork; /* size = 0x2C */

/* The camera process D_800FF574's work (func_800FE710: func_80023684(0x40)). func_800FE744 sets a
   move of unk_00 frames toward eye unk_10..18 / target unk_1C..24; unk_28..3C are the per-frame
   steps func_800FE858 adds to D_800FF564/D_800FF584. */
typedef struct KPWCameraWork {
    /* 0x00 */ u16 unk_00; /* frames left */
    /* 0x02 */ char unk_02[2];
    /* 0x04 */ f32 unk_04; /* func_800FE82C */
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
} KPWCameraWork; /* size = 0x40 */

/* D_800FF550 (func_800F842C): three busy flags, one per effect slot; its model[1 + slot * 3 + k]
   are the slot's three models (model[0] = -1). */
typedef struct KPWFxSlots {
    /* 0x00 */ u16 busy[3];
} KPWFxSlots; /* size = 0x6 */

/* One effect (func_800F8514 -> func_800F8678; func_80023684(0x10)). */
typedef struct KPWFxWork {
    /* 0x00 */ u16 slot;
    /* 0x02 */ u16 timer;
    /* 0x04 */ u16 count; /* func_800F8514's arg1 (lhu; loop bound) */
    /* 0x06 */ u16 mode;  /* func_800F8514's arg0: switch 0..2 */
    /* 0x08 */ f32 radius;
    /* 0x0C */ f32 scale;
} KPWFxWork; /* size = 0x10 */

/* D_800FF554 (func_800F8918): ten busy flags and their sprite ids. */
typedef struct KPWSparkSlots {
    /* 0x00 */ u16 busy[10];
    /* 0x14 */ s16 sprite[10];
} KPWSparkSlots; /* size = 0x28 */

/* One spark (func_800F8A28 -> func_800F8B94; func_80023684(8)). */
typedef struct KPWSparkWork {
    /* 0x00 */ u16 timer;
    /* 0x02 */ u16 slot;
    /* 0x04 */ f32 vy;
} KPWSparkWork; /* size = 0x8 */

/* ---------------------------------------------------------------------------------------------
   Main-code declarations missing from include/ (signatures from their definitions)
   --------------------------------------------------------------------------------------------- */
void func_800090C4(omObjData* obj, u8 idx, u8 val);
void func_8000A534(omObjData* obj, f32 speed);
s32 func_8000A634(omObjData* obj, omObjData* item);
void func_8000A6F4(omObjData* obj);
s32 func_80017A60(omObjData* obj);
void func_80017D1C(omObjData* obj);
s32 func_800185A4(omObjData* obj, u16 motion);
void func_8001E268(s16 index, u8 arg1, u8 arg2);
void func_8001E2A8(s16 index, u16 arg1);
void func_80025BB8(s16, s16);
f32 func_80025D18(s16);
f32 func_80025D40(s16);
void func_8002859C(s16, s16, char*);
f32 func_80029518(f32);
void func_80039644(s16, u8, u8);
void func_8003967C(s16, u8);
void func_80060F04(s16 player, s16 arg1, s16 arg2, s16 arg3);
f64 func_8009B618(f64, f64); /* fmod */

extern f32 D_800B8964; /* src/1130.c */
extern f32 D_800B8980;
extern f32 D_800B8988;
extern KPWChr D_800C59A8[6]; /* src/objmain.c (objmainChr) */
extern omObjData* D_800EDE70[]; /* src/1130.c's collision list, D_800EE984 entries */
extern u16 D_800EE984;
extern omObjData* D_800F2AF8[]; /* D_800ED440 entries */
extern unk_ovl3C_struct D_800EE738;
extern u8 D_800F64F8;

/* ---------------------------------------------------------------------------------------------
   Overlay functions. Process callbacks take the omObjData* the object manager passes.
   --------------------------------------------------------------------------------------------- */
/* 1F62C0 */
void func_800F65E0_KeyPaWay(void);
void func_800F6BD8_KeyPaWay(omObjData*);
void func_800F6C58_KeyPaWay(omObjData*); /* its argument is unused */
void func_800F6D98_KeyPaWay(omObjData*);
void func_800F6E04_KeyPaWay(u16 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_800F6E6C_KeyPaWay(omObjData*);
void func_800F6F10_KeyPaWay(omObjData* obj, u8 port); /* CPU stick: ContStkX/Y[port] */
f32 func_800F7134_KeyPaWay(omObjData* obj, f32 x, f32 z, f32 angle, f32 dist);
void func_800F747C_KeyPaWay(omObjData*);
void func_800F76C8_KeyPaWay(omObjData*);
void func_800F7840_KeyPaWay(omObjData*);
void func_800F7AE0_KeyPaWay(omObjData*);
void func_800F842C_KeyPaWay(omObjData*);
void func_800F8514_KeyPaWay(s16 mode, s16 count, f32 scale, f32 x, f32 y, f32 z);
void func_800F8678_KeyPaWay(omObjData*);
void func_800F8918_KeyPaWay(omObjData*);
void func_800F8A28_KeyPaWay(f32 vy, f32 x, f32 y, f32 z);
void func_800F8B94_KeyPaWay(omObjData*);
void func_800F8C54_KeyPaWay(omObjData*);
void func_800F8C70_KeyPaWay(omObjData*);
void func_800F8C8C_KeyPaWay(omObjData*);
void func_800F8CA8_KeyPaWay(omObjData*);
void func_800F8CC4_KeyPaWay(omObjData* obj, s32 player); /* uses arg1 & 0xFFFF: maybe u16 */
void func_800F92B8_KeyPaWay(omObjData*);
void func_800F9620_KeyPaWay(omObjData*);
void func_800F9A90_KeyPaWay(omObjData*);
void func_800FA3B0_KeyPaWay(omObjData*);
void func_800FA3D0_KeyPaWay(omObjData*);
void func_800FA3F0_KeyPaWay(omObjData*);
void func_800FA410_KeyPaWay(omObjData*);
void func_800FA430_KeyPaWay(omObjData*);
void func_800FA450_KeyPaWay(omObjData* obj, u16 index, u16 kind); /* uncertain: arg2 & 0xFFFF'd */
void func_800FA59C_KeyPaWay(omObjData* obj, u16 kind); /* uncertain: m2c says s16 */
void func_800FA7E0_KeyPaWay(omObjData*);
void func_800FA7F4_KeyPaWay(omObjData*);
void func_800FAAF4_KeyPaWay(omObjData* obj, omObjData* target);
void func_800FAF28_KeyPaWay(omObjData*);
f32 func_800FB38C_KeyPaWay(KPWBodyWork* work, f32 angle);
u16 func_800FB498_KeyPaWay(omObjData* obj, f32 x, f32 z, f32* out); /* callers mask & 0xFFFF */
s32 func_800FB748_KeyPaWay(omObjData* obj, omObjData* other); /* KPWPlayerWork.unk_DC */
void func_800FB9D4_KeyPaWay(omObjData*);
void func_800FBAD4_KeyPaWay(omObjData*);
void func_800FBC98_KeyPaWay(omObjData*);
void func_800FCC6C_KeyPaWay(void);
void func_800FCCB0_KeyPaWay(omObjData*);
f32 func_800FDA7C_KeyPaWay(omObjData* obj, f32 x, f32 z, f32 angle, f32 dist);
u16 func_800FDE64_KeyPaWay(f32 x, f32 z, f32 range, omObjData* out[]);
omObjData* func_800FDFAC_KeyPaWay(omObjData*);
omObjData* func_800FE06C_KeyPaWay(omObjData*);
s32 func_800FE134_KeyPaWay(f32 arg0, f32 arg1, f32 arg2, f32 arg3); /* callers mask & 0xFFFF */
f32 func_800FE1F0_KeyPaWay(f32 arg0, f32 arg1);
/* 1FDF10 */
void func_800FE230_KeyPaWay(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
void func_800FE2E8_KeyPaWay(void);
void func_800FE320_KeyPaWay(s32);
void func_800FE33C_KeyPaWay(void);
void func_800FE3DC_KeyPaWay(Vec3f* out); /* func_800FBC98 passes a stack Vec3f */
void func_800FE710_KeyPaWay(omObjData*);
void func_800FE744_KeyPaWay(u16 frames, f32 eyeX, f32 eyeY, f32 eyeZ, f32 atX, f32 atY, f32 atZ); /* m2c: s16 */
void func_800FE814_KeyPaWay(void);
void func_800FE82C_KeyPaWay(f32 arg0, f32 arg1);
void func_800FE858_KeyPaWay(omObjData*);
void func_800FE8EC_KeyPaWay(omObjData*);
void func_800FEA28_KeyPaWay(omObjData*);

extern f32 D_800FF270_KeyPaWay[5][2]; /* (x, z) start per group-1 object (func_800FA450 arg1) */
extern Vec3f D_800FF298_KeyPaWay[4];  /* func_800F8CC4 start positions */
extern Vec3f D_800FF2C8_KeyPaWay[4];  /* indexed by D_800FF50C[i] (func_800F92B8) */
extern s32 D_800FF2F8_KeyPaWay[6];    /* form file per character (| 0x400000) */
extern f32 D_800FF310_KeyPaWay[3][3][2]; /* (x, z) grid: [KPWPlayerExt.unk_16][unk_18] */
extern f32 D_800FF274_KeyPaWay;
extern f32 D_800FF29C_KeyPaWay;
extern f32 D_800FF2A0_KeyPaWay;
extern f32 D_800FF314_KeyPaWay;
extern f32 D_800FF318_KeyPaWay;
extern f32 D_800FF31C_KeyPaWay;
extern f32 D_800FF330_KeyPaWay;
/* func_800F7840 (the key) */
extern f32 D_800FF358_KeyPaWay;
extern f32 D_800FF35C_KeyPaWay;
extern f32 D_800FF360_KeyPaWay;
extern u16 D_800FF364_KeyPaWay; /* = 1 (0x800FF366 = 0 unreferenced) */
extern f32 D_800FF368_KeyPaWay;
extern f32 D_800FF36C_KeyPaWay;
extern u16 D_800FF370_KeyPaWay[2]; /* {30, 30}; [1] is %lo(D_800FF370 + 2) */
/* func_800F8CC4: a word counter (lw/sw, = 1) whose low half retail reads as D_800FF376 (lhu). */
extern s32 D_800FF374_KeyPaWay;
extern u16 D_800FF376_KeyPaWay;
extern u16 D_800FF378_KeyPaWay; /* func_800F9A90 */
extern u16 D_800FF37A_KeyPaWay;
extern omObjData* D_800FF37C_KeyPaWay; /* first group-1 object that loaded the shared model */
extern u16 D_800FF380_KeyPaWay; /* func_800FA7F4 */
extern u16 D_800FF382_KeyPaWay; /* = 1 */
extern f32 D_800FF384_KeyPaWay; /* func_800FBC98 */
extern f32 D_800FF388_KeyPaWay;
extern f32 D_800FF38C_KeyPaWay;
extern f32 D_800FF390_KeyPaWay; /* = 1.0f; four unreferenced f32 0s follow */
extern u16 D_800FF3A4_KeyPaWay; /* five unreferenced halfwords follow */

/* .rodata (1F62C0, INCLUDE_RODATA): SJIS string passed to func_8007B168. */
extern const u8 D_800FF3B0_KeyPaWay[];

extern u16 D_800FF500_KeyPaWay; /* func_800FBAD4 */
extern u16 D_800FF502_KeyPaWay;
extern u16 D_800FF504_KeyPaWay; /* func_800FBC98 timer; func_800FE744 frames */
extern u16 D_800FF506_KeyPaWay;
extern f32 D_800FF508_KeyPaWay;
extern u16 D_800FF50C_KeyPaWay[4]; /* per D_800F2BC0 index into D_800FF2C8 */
extern u16 D_800FF514_KeyPaWay;
extern u16 D_800FF516_KeyPaWay[4]; /* per player flag */
extern u16 D_800FF51E_KeyPaWay; /* func_800F7134/func_800FDA7C: no free direction */
extern u16 D_800FF520_KeyPaWay; /* func_800FDE64: nearest distance (converted to f32) */
extern u16 D_800FF522_KeyPaWay; /* func_800F7134/func_800FDA7C: tries */
extern s16 D_800FF524_KeyPaWay; /* message id (GMesCreate) */
extern s16 D_800FF526_KeyPaWay; /* _CheckFlag(43) */
extern f32 D_800FF528_KeyPaWay; /* x, passed in a GPR (lw) */
extern f32 D_800FF52C_KeyPaWay; /* z */
extern u16 D_800FF530_KeyPaWay;
extern s16 D_800FF532_KeyPaWay; /* countdown: lh (func_80079078) and lhu */
extern u16 D_800FF534_KeyPaWay; /* func_80039084 results */
extern u16 D_800FF536_KeyPaWay;
extern u16 D_800FF538_KeyPaWay; /* human player count */
extern s16 D_800FF53A_KeyPaWay; /* func_80038A9C result */
extern omObjData* D_800FF53C_KeyPaWay;
extern omObjData* D_800FF540_KeyPaWay; /* omAddObj results (sw/lw) */
extern omObjData* D_800FF544_KeyPaWay;
extern omObjData** D_800FF548_KeyPaWay; /* func_8005DB44(1): the five group-1 objects */
extern omObjData* D_800FF54C_KeyPaWay; /* a player object (compared with D_800FF594[i]) */
extern omObjData* D_800FF550_KeyPaWay; /* KPWFxSlots work */
extern omObjData* D_800FF554_KeyPaWay; /* KPWSparkSlots work */
extern omObjData* D_800FF558_KeyPaWay;
extern omObjData* D_800FF55C_KeyPaWay; /* unkKeyPaWayStruct work */
extern omObjData* D_800FF560_KeyPaWay; /* KPWStageWork work */
/* Camera eye: D_800FF568/D_800FF56C are its y/z (retail takes their addresses: &D_800FF564.y). */
extern Vec3f D_800FF564_KeyPaWay;
extern f32 D_800FF568_KeyPaWay;
extern f32 D_800FF56C_KeyPaWay;
extern f32 D_800FF570_KeyPaWay;
extern omObjData* D_800FF574_KeyPaWay; /* camera process, KPWCameraWork */
extern u16 D_800FF578_KeyPaWay; /* game state */
extern omObjData* D_800FF57C_KeyPaWay; /* the key's carrier (a player object) */
extern u16 D_800FF580_KeyPaWay;
/* Camera target: D_800FF588 is its y. */
extern Vec3f D_800FF584_KeyPaWay;
extern f32 D_800FF588_KeyPaWay;
extern omObjData* D_800FF590_KeyPaWay; /* the key (KPWBodyWork, unk_68.key) */
extern omObjData** D_800FF594_KeyPaWay; /* func_8005DB44(0): the four players (KPWPlayerWork) */
extern Vec3f D_800FF598_KeyPaWay; /* camera up */
extern u16 D_800FF5A4_KeyPaWay; /* func_800FBAD4 state (switch) */

#endif
