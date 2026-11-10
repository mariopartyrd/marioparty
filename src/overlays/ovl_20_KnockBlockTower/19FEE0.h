#ifndef KNOCKBLOCKTOWER_H
#define KNOCKBLOCKTOWER_H

/* ovl_20 KnockBlockTower: declarations shared by its units (19FEE0, 1A2E40, 1A42B0).
   Types come from the asm's accesses; N64 offsets are in the comments. Structs that hold pointers
   are only reached through their fields (the host strides pointers 8 bytes). */

#include "common.h"
#include "engine/pad.h"

/* One block of the tower (D_800FB650[8]): [0] is the list head, then up to 6 blocks and a
   terminator (type -1, next NULL). The list runs bottom to top through `next`. */
typedef struct KBTNode {
    /* 0x00 */ omObjData* obj;
    /* 0x04 */ struct KBTNode* next;
    /* 0x08 */ s32 id; /* collision id (index + 2), compared with the player's unk_55 */
    /* 0x0C */ s16 type; /* 0 plain, 1 bomb-like (knocked once), -1 terminator */
    /* 0x0E */ u8 unkE; /* collision id of the player that hit it */
    /* 0x0F */ char unkF;
    /* 0x10 */ u16 state; /* 0 resting, 1 landed, 2 falling */
    /* 0x14 */ f32 baseY;
    /* 0x18 */ f32 vel;
    /* 0x1C */ f32 accel;
    /* 0x20 */ f32 angle; /* wobble phase (degrees) */
    /* 0x24 */ f32 amp; /* wobble offset */
    /* 0x28 */ f32 amp0; /* wobble amplitude */
    /* 0x2C */ f32 dir; /* wobble direction (degrees) */
} KBTNode; /* size = 0x30 (N64) */

/* Per-player CPU/input state (D_800FB7E0[4]). */
typedef struct KBTCpu {
    /* 0x00 */ u16 unk0; /* flags: 1 CPU */
    /* 0x02 */ u16 unk2; /* CPU state */
    /* 0x04 */ u16 unk4; /* CPU difficulty */
    /* 0x06 */ u16 unk6;
    /* 0x08 */ u16 unk8; /* frames to wait */
    /* 0x0A */ s16 unkA; /* stick x */
    /* 0x0C */ s16 unkC; /* stick y */
    /* 0x0E */ u16 unkE; /* buttons pressed */
    /* 0x10 */ u16 unk10; /* buttons held */
    /* 0x12 */ s16 unk12; /* saved ContStkX */
    /* 0x14 */ s16 unk14; /* saved ContStkY */
    /* 0x16 */ u16 unk16; /* saved ContBtnTrg */
    /* 0x18 */ u16 unk18; /* saved ContBtn */
} KBTCpu; /* size = 0x1A */

/* Work of the stage and block objects (func_80023684(0x2C)). */
typedef struct KBTStageWork {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk_06[0x26];
} KBTStageWork; /* size = 0x2C */

/* Work of D_800EDE70's objects (func_800F7198): src/1130.c's PlayerWork layout. */
typedef struct KBTCoinWork {
    /* 0x00 */ char unk_00[0x21];
    /* 0x21 */ u8 unk_21[4];
    /* 0x25 */ char unk_25[0x2F];
    /* 0x54 */ u8 unk_54;
    /* 0x55 */ char unk_55[0x17];
} KBTCoinWork; /* size = 0x6C (N64) */

/* Thwomp work (func_800FA010, func_80023684(0x6C)). */
typedef struct KBTThwompWork {
    /* 0x00 */ char unk_00[0x38];
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ char unk_44[0x28];
} KBTThwompWork; /* size = 0x6C */

/* The player object's work (func_8000979C allocates a MgWork, 0xE8): src/99E0.c's layout with
   the fields this overlay touches; its pointers sit where MgWork's do. unk_21[slot] is the sprite
   of model[slot]. */
typedef struct KBTPlayerWork {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ char unk_02[3];
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ u8 unk_20;
    /* 0x21 */ u8 unk_21[11];
    /* 0x2C */ char unk_2C[8];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38; /* vertical speed; 1000.0f = on the ground */
    /* 0x3C */ f32 unk_3C; /* facing angle */
    /* 0x40 */ f32 unk_40; /* speed */
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48; /* radius */
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ s8 unk_53;
    /* 0x54 */ s8 unk_54;
    /* 0x55 */ s8 unk_55; /* collision id of the block touched, -1 none */
    /* 0x56 */ s8 unk_56; /* controller port */
    /* 0x57 */ u8 unk_57;
    /* 0x58 */ s8 unk_58; /* player index */
    /* 0x59 */ char unk_59[3];
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64; /* reach */
    /* 0x68 */ char unk_68[0x50];
    /* 0xB8 */ omObjData* unk_B8;
    /* 0xBC */ char unk_BC[0x1C];
    /* 0xD8 */ void* unk_D8;
    /* 0xDC */ void* unk_DC;
    /* 0xE0 */ char unk_E0[4];
    /* 0xE4 */ void* unk_E4;
} KBTPlayerWork; /* size = 0xE8 (N64) */

/* ---------------------------------------------------------------------------------------------
   Main-code declarations missing from include/
   --------------------------------------------------------------------------------------------- */
void func_800090C4(omObjData* obj, u8 idx, u8 val);
void func_800090D8(omObjData*, u8, u8);
s32 func_80017A60(omObjData* obj);
void func_80017C0C(omObjData*, u8, f32, f32, f32, f32, f32);
void func_8001E268(s16 index, u8 arg1, u8 arg2);
void func_8001E2A8(s16, u16);
f32 func_80029518(f32);
f32 func_80025D18(s16);
f32 func_80025D40(s16);
void func_8006B9B0(omObjData*, f32, f32, f32); /* src/6C470.c */
void func_8006BAD0(omObjData*, f32);           /* src/6C470.c */
void func_8006BADC(omObjData*, f32, f32, f32); /* src/6C470.c */
void func_8006BAF0(omObjData*, s32);           /* src/6C470.c */
s32 func_8006BAFC(omObjData*);                 /* src/6C470.c */
void func_80060F04(s16, s16, s16, s16);       /* src/objmain.c */

extern f32 D_800B8964; /* src/1130.c */
extern f32 D_800B8968;
extern f32 D_800B8990;
extern omObjData* D_800EDE70[]; /* src/1130.c's collision list, D_800EE984 entries */
extern u16 D_800EE984;
extern omObjData* D_800F2AF8[];
extern f32 D_800ED6B8;
extern f32 D_800F5254;

/* ---------------------------------------------------------------------------------------------
   Overlay functions
   --------------------------------------------------------------------------------------------- */
/* 19FEE0 */
void func_800F65E0_KnockBlockTower(void);
void func_800F692C_KnockBlockTower(omObjData*);
void func_800F69F8_KnockBlockTower(omObjData*);
void func_800F6A10_KnockBlockTower(void);
void func_800F6BF8_KnockBlockTower(omObjData*);
void func_800F6C4C_KnockBlockTower(void);
void func_800F6C98_KnockBlockTower(void);
void func_800F6D74_KnockBlockTower(s32, u8, u32);
void func_800F6DB4_KnockBlockTower(void);
void func_800F6DBC_KnockBlockTower(void);
void func_800F6DC4_KnockBlockTower(omObjData*);
void func_800F6F64_KnockBlockTower(omObjData*);
void func_800F702C_KnockBlockTower(omObjData* obj, f32 scale, f32 y, s32 idx);
void func_800F70B0_KnockBlockTower(omObjData*);
s32 func_800F7114_KnockBlockTower(u16 player);
void func_800F7198_KnockBlockTower(omObjData* coin, Vec3f* pos);
void func_800F725C_KnockBlockTower(void);
KBTNode* func_800F72E8_KnockBlockTower(s32 id);
void func_800F7320_KnockBlockTower(omObjData*);
void func_800F7398_KnockBlockTower(omObjData*, s32 id);
f32 func_800F74BC_KnockBlockTower(KBTNode*);
void func_800F7524_KnockBlockTower(omObjData*);
f32 func_800F79BC_KnockBlockTower(void);
s32 func_800F7A1C_KnockBlockTower(void);
s32 func_800F7ABC_KnockBlockTower(void);
void func_800F7B04_KnockBlockTower(KBTNode*);
s32 func_800F7B90_KnockBlockTower(s32);
s32 func_800F7BF8_KnockBlockTower(void);
s32 func_800F7C0C_KnockBlockTower(s32, s32);
void func_800F7D0C_KnockBlockTower(omObjData*);
void func_800F834C_KnockBlockTower(omObjData*);
void func_800F83B8_KnockBlockTower(omObjData*);
void func_800F83D0_KnockBlockTower(omObjData*);
void func_800F8BEC_KnockBlockTower(omObjData*);
void func_800F8F28_KnockBlockTower(omObjData*);
void func_800F8FE8_KnockBlockTower(omObjData*);
void func_800F9020_KnockBlockTower(omObjData*);
/* 1A2E40 */
void func_800F9540_KnockBlockTower(omObjData*);
void func_800F9BD0_KnockBlockTower(omObjData*);
void func_800F9C98_KnockBlockTower(omObjData*);
void func_800F9D3C_KnockBlockTower(omObjData*);
void func_800F9EA0_KnockBlockTower(omObjData*);
void func_800FA010_KnockBlockTower(omObjData*);
void func_800FA0C4_KnockBlockTower(omObjData*);
void func_800FA560_KnockBlockTower(omObjData*);
void func_800FA5F4_KnockBlockTower(omObjData* obj, s32 arg1, s32 arg2, u16 player, Vec3f* pos);
void func_800FA92C_KnockBlockTower(omObjData*);
/* 1A42B0 */
void func_800FA9B0_KnockBlockTower(Gfx* gfx, s16 image, u16 rowStep, s32 x, s32 y, u16 rows, f32 sx, f32 sy);
void func_800FB13C_KnockBlockTower(omObjData*);
u16 func_800FB20C_KnockBlockTower(s32 file);
void func_800FB250_KnockBlockTower(void);
void func_800FB2B4_KnockBlockTower(omObjData*);

/* ---------------------------------------------------------------------------------------------
   .data
   --------------------------------------------------------------------------------------------- */
extern s32 D_800FB500_KnockBlockTower; /* camera shake state (func_800F6DC4) */
extern s32 D_800FB510_KnockBlockTower;
extern u32 D_800FB514_KnockBlockTower; /* game timer (frames) */
extern s32 D_800FB518_KnockBlockTower;
extern s32 D_800FB51C_KnockBlockTower;
extern u32 D_800FB520_KnockBlockTower;
extern u32 D_800FB524_KnockBlockTower;
extern s32 D_800FB528_KnockBlockTower;
extern u32 D_800FB52C_KnockBlockTower;
extern s32 D_800FB530_KnockBlockTower;
extern u16 D_800FB540_KnockBlockTower;

/* ---------------------------------------------------------------------------------------------
   .bss (ovl_20_bss.bss.s, 0x800FB5B0..0x800FB900)
   --------------------------------------------------------------------------------------------- */
extern f32 D_800FB5B0_KnockBlockTower;
extern f32 D_800FB5B4_KnockBlockTower;
extern f32 D_800FB5B8_KnockBlockTower;
extern f32 D_800FB5BC_KnockBlockTower;
extern f32 D_800FB5C0_KnockBlockTower;
extern s16 D_800FB5D0_KnockBlockTower[2]; /* images: [0] scrolling background, [1] title sprite */
extern Gfx* D_800FB5D4_KnockBlockTower[3]; /* display-list buffers, one per frame buffer */
extern s16 D_800FB5E0_KnockBlockTower;
extern s32 D_800FB5E8_KnockBlockTower[11][2]; /* [i][0] speed, [i][1] offset */
extern s16 D_800FB640_KnockBlockTower;
extern KBTNode D_800FB650_KnockBlockTower[8];
extern u16 D_800FB7D0_KnockBlockTower;
extern u16 D_800FB7D8_KnockBlockTower;
extern KBTCpu D_800FB7E0_KnockBlockTower[4];
extern f32 D_800FB848_KnockBlockTower;
extern u16 D_800FB84C_KnockBlockTower;
extern s32 D_800FB850_KnockBlockTower;
extern omObjData* D_800FB8D0_KnockBlockTower; /* Thwomp */
extern u16 D_800FB8D4_KnockBlockTower; /* result: 0 won, 1 knocked by the Thwomp, 2 fell */
extern omObjData* D_800FB8D8_KnockBlockTower; /* goal (func_8006B8A4) */
extern s32 D_800FB8DC_KnockBlockTower;
extern omObjData* D_800FB8E0_KnockBlockTower;
extern f32 D_800FB8E4_KnockBlockTower;
extern f32 D_800FB8E8_KnockBlockTower;
extern u16 D_800FB8EC_KnockBlockTower; /* the solo player */
extern f32 D_800FB8F4_KnockBlockTower;

#endif
