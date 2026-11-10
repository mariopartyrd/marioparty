#ifndef RUNNINGOFTHEBULB_H
#define RUNNINGOFTHEBULB_H

/* ovl_2D RunningOfTheBulb: declarations for its units (1FF1E0.c, 206C90.c).
   Types come from the asm's accesses; N64 offsets are in the comments. A struct with no pointers
   has the same layout on the host. Every block is allocated with sizeof (never retail's literal
   size): the host strides pointers 8 bytes. */

#include "common.h"

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* D_800EE738 (camera parameters, func_800FE194). No pointers. */
typedef struct unkfloatStruct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    char unk18[4];
} unkfloatStruct;

/* The four players' work (D_800FE460[i]->unk_50: func_8000979C allocates a MgWork, 0xE8). This is
   MgWork's layout (src/99E0.c) with the fields this overlay touches; its pointers sit where
   MgWork's do (0xB8, 0xD8, 0xDC, 0xE4) so the host layout agrees with the allocator's. */
typedef struct RotbPlayerWork {
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
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ char unk_28[0xC];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38; /* 1000.0f = on the ground */
    /* 0x3C */ f32 unk_3C; /* facing angle */
    /* 0x40 */ f32 unk_40; /* speed */
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48; /* collision radius */
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50; /* flags */
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ s8 unk_53; /* floor object index (D_800F2AF8), -1 none */
    /* 0x54 */ s8 unk_54; /* player touched (D_800F3FB0), -1 none */
    /* 0x55 */ u8 unk_55;
    /* 0x56 */ s8 unk_56; /* controller port */
    /* 0x57 */ u8 unk_57;
    /* 0x58 */ s8 unk_58; /* player index */
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
    /* 0x9C */ s16 unk_9C;
    /* 0x9E */ char unk_9E[2];
    /* 0xA0 */ f32 unk_A0;
    /* 0xA4 */ f32 unk_A4;
    /* 0xA8 */ char unk_A8[6];
    /* 0xAE */ u16 unk_AE;
    /* 0xB0 */ u8 unk_B0;
    /* 0xB1 */ s8 unk_B1; /* stomped player, -1 none */
    /* 0xB2 */ s8 unk_B2;
    /* 0xB3 */ s8 unk_B3;
    /* 0xB4 */ char unk_B4[4];
    /* 0xB8 */ omObjData* unk_B8; /* held item */
    /* 0xBC */ f32 unk_BC;
    /* 0xC0 */ u16 unk_C0;
    /* 0xC2 */ char unk_C2[0x16];
    /* 0xD8 */ s16 (*unk_D8)[2]; /* one pair per motion */
    /* 0xDC */ s32 (*unk_DC)(omObjData*, omObjData*); /* collision callback (src/1130.c) */
    /* 0xE0 */ s16 unk_E0; /* PlayerWork's unk_E0 (1130.c), read with lh */
    /* 0xE2 */ char unk_E2[2];
    /* 0xE4 */ struct RotbPlayerExt* unk_E4;
} RotbPlayerWork; /* size = 0xE8 */

#define ROTB_PLAYER(obj) ((RotbPlayerWork*)(obj)->unk_50)

/* The overlay's per-player extension (RotbPlayerWork.unk_E4; func_80023684(0x68) in
   func_800F7B5C). Flags unk_00: 1 set up, 2 landed on a block, 4 carrying a bulb, 8 bulb carried
   off, 0x10 caught by the big bulb, 0x20 out, 0x40 carry motion, 0x80 stick cleared, 0x100 turned. */
typedef struct RotbPlayerExt {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ s16 unk_02; /* player index */
    /* 0x04 */ char unk_04[0x10];
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16;
    /* 0x18 */ char unk_18[0x10];
    /* 0x28 */ omObjData* unk_28; /* the floor stood on */
    /* 0x2C */ omObjData* unk_2C; /* the bulb carried */
    /* 0x30 */ omObjData* unk_30; /* the bulb chased (CPU) */
    /* 0x34 */ char unk_34[2];
    /* 0x36 */ s16 unk_36; /* func_80038A9C's result */
    /* 0x38 */ f32 unk_38; /* carry scale */
    /* 0x3C */ f32 unk_3C; /* shadow scale (D_800FE240) */
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44; /* shadow offset (D_800FE270) */
    /* 0x48 */ f32 unk_48; /* shadow height */
    /* 0x4C */ u16 unk_4C; /* turn frames */
    /* 0x4E */ char unk_4E[2];
    /* 0x50 */ f32 unk_50; /* turn step */
    /* 0x54 */ u16 unk_54; /* frames since caught */
    /* 0x56 */ char unk_56[2];
    /* 0x58 */ f32 unk_58; /* scale while caught */
    /* 0x5C */ f32 unk_5C; /* velocity while caught */
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
} RotbPlayerExt; /* size = 0x68 (N64) */

/* A bulb's extension (RotbBodyWork.unk_68.bulb; func_80023684(0x44) in func_800F9724). Flags
   unk_00: 1 active, 2 carried, 4 chased, 8 carried off, 0x10 thrown, 0x20 flying sound. */
typedef struct RotbBulbExt {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u16 unk_02; /* frame counter */
    /* 0x04 */ u16 unk_04; /* alpha (func_800211BC takes its low byte) */
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ omObjData* unk_08; /* the CPU player chasing it */
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ omObjData* unk_14; /* the player carrying it */
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C; /* bob angle */
    /* 0x20 */ f32 unk_20; /* heading */
    /* 0x24 */ f32 unk_24; /* thrown direction x */
    /* 0x28 */ f32 unk_28; /* thrown direction z */
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38; /* scale */
    /* 0x3C */ f32 unk_3C; /* wobble angle */
    /* 0x40 */ s16 unk_40; /* sparkle sprite (func_8001E00C) */
    /* 0x42 */ s16 unk_42; /* its model */
} RotbBulbExt; /* size = 0x44 (N64) */

/* The big bulb D_800FE478's extension (func_800FAB8C, func_80023684(4)). No pointers. */
typedef struct RotbBossExt {
    /* 0x00 */ s16 unk_00; /* sparkle sprite */
    /* 0x02 */ s16 unk_02; /* its model */
} RotbBossExt;

/* D_800FE4AC's extension (func_800FB28C, func_80023684(0x24)). No pointers. */
typedef struct RotbJumpExt {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04; /* step x */
    /* 0x08 */ f32 unk_08; /* start y */
    /* 0x0C */ f32 unk_0C; /* step z */
    /* 0x10 */ char unk_10[4];
    /* 0x14 */ f32 unk_14; /* frame */
    /* 0x18 */ char unk_18[4];
    /* 0x1C */ f32 unk_1C; /* launch speed */
    /* 0x20 */ f32 unk_20; /* scale */
} RotbJumpExt; /* size = 0x24 */

/* Work of the bodies added to D_800EDE70 (src/1130.c's collision list), func_80023684(0x6C): the
   bulbs D_800FE49C[i] (func_800F9724), the big bulb D_800FE478 (func_800FAB8C) and D_800FE4AC
   (func_800FB28C). Fields up to 0x64 follow src/1130.c's PlayerWork and 99E0.c's MgItemWork. */
typedef struct RotbBodyWork {
    /* 0x00 */ char unk_00[0x34];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40; /* speed */
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48; /* radius */
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50; /* flags: 0x20 carried, 0x40 can be picked up */
    /* 0x52 */ u8 unk_52; /* kind: 3 an item, 7 a bulb */
    /* 0x53 */ char unk_53;
    /* 0x54 */ u8 unk_54;
    /* 0x55 */ char unk_55[3];
    /* 0x58 */ f32 unk_58;
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ omObjData* unk_64; /* carrier */
    /* 0x68 */ union {
        RotbBulbExt* bulb;
        RotbBossExt* boss;
        RotbJumpExt* jump;
    } unk_68;
} RotbBodyWork; /* size = 0x6C (N64) */

#define ROTB_BODY(obj) ((RotbBodyWork*)(obj)->unk_50)

/* A falling block's extension (D_800FE480[i]; RotbFloorWork.unk_28, func_80023684(0x18)). */
typedef struct RotbBlockExt {
    /* 0x00 */ s16 unk_00; /* slot in RotbBlockList */
    /* 0x02 */ u16 unk_02; /* state: 0 wait, 1 fall, 2 landed, 3 rise */
    /* 0x04 */ u16 unk_04; /* frames */
    /* 0x06 */ u16 unk_06; /* wait frames */
    /* 0x08 */ u16 unk_08; /* landed frames */
    /* 0x0A */ char unk_0A[2];
    /* 0x0C */ f32 unk_0C; /* y speed */
    /* 0x10 */ f32 unk_10; /* rest height */
    /* 0x14 */ f32 unk_14; /* camera z that drops it */
} RotbBlockExt; /* size = 0x18 */

/* Work of the floors in D_800F2AF8 (MgWork's first 0x2C bytes, zeroed with func_8009B770 and
   filled by func_80009028/func_80009058; src/1130.c's GroundWork). Only the falling blocks use
   unk_28, a pointer past everything the main code reads. */
typedef struct RotbFloorWork {
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
    /* 0x28 */ RotbBlockExt* unk_28;
} RotbFloorWork; /* size = 0x2C (N64) */

#define ROTB_FLOOR(obj) ((RotbFloorWork*)(obj)->unk_50)

/* D_800FE47C's work (func_800F7034, func_80023684(0x1C)): the next drop record and the six
   block objects. */
typedef struct RotbBlockList {
    /* 0x00 */ u16 unk_00; /* next record in D_800FE2D0 */
    /* 0x04 */ omObjData* unk_04[6];
} RotbBlockList; /* size = 0x1C (N64) */

/* A drop record (D_800FE2D0[5]): when the camera passes unk_00, a block falls at unk_08..10. */
typedef struct RotbDrop {
    /* 0x00 */ f32 unk_00; /* camera z */
    /* 0x04 */ f32 unk_04; /* camera z that releases it (RotbBlockExt.unk_14) */
    /* 0x08 */ f32 unk_08; /* x */
    /* 0x0C */ f32 unk_0C; /* y */
    /* 0x10 */ f32 unk_10; /* z */
    /* 0x14 */ f32 unk_14; /* rest height */
    /* 0x18 */ u16 unk_18; /* first state */
} RotbDrop; /* size = 0x1C */

/* ---------------------------------------------------------------------------------------------
   Main-code declarations missing from the shared headers
   --------------------------------------------------------------------------------------------- */

/* engine/pad.h declares ContBtn u16; retail reads it with lh here, and that header is not included. */
extern s16 ContBtn[];
extern s8 ContStkY[];

extern s16 D_800F3778;
extern u16 D_800EE984;
extern omObjData* D_800EDE70[]; /* src/1130.c's collision list, D_800EE984 entries */
extern omObjData* D_800F2AF8[];
extern unkfloatStruct D_800EE738;

void func_80008FF4(omObjData* obj, f32 arg1);
void func_800090C4(omObjData* obj, u8 idx, u8 val);
void func_8003967C(s16, u8);
void func_80060F04(s16, s16, s16, s16);
void func_8000A534(omObjData* obj, f32 speed);
s32 func_8000A634(omObjData* obj, omObjData* item);
void func_8000A6F4(omObjData* obj);
u16 func_80017A50(omObjData* obj);
s32 func_80017A60(omObjData* obj);
void func_80017D1C(omObjData* obj);
s32 func_800185A4(omObjData* obj, u16 motion);
void func_8001E268(s16, u8, u8);
void func_8001E2A8(s16, u16);
f64 func_8009B618(f64, f64);

/* ---------------------------------------------------------------------------------------------
   Overlay data (1FF1E0.c) and bss
   --------------------------------------------------------------------------------------------- */

extern f32 D_800FE240_RunningOfTheBulb[6][2];
extern f32 D_800FE270_RunningOfTheBulb[6][2];
extern Vec D_800FE2A0_RunningOfTheBulb[4];
extern RotbDrop D_800FE2D0_RunningOfTheBulb[5];
extern s32 D_800FE35C_RunningOfTheBulb;
extern s32 D_800FE360_RunningOfTheBulb;
extern f32 D_800FE364_RunningOfTheBulb[4][2];
extern u16 D_800FE384_RunningOfTheBulb;
extern f32 D_800FE388_RunningOfTheBulb;
extern f32 D_800FE38C_RunningOfTheBulb;
extern u16 D_800FE390_RunningOfTheBulb;
extern f32 D_800FE394_RunningOfTheBulb;
extern f32 D_800FE398_RunningOfTheBulb;
extern u16 D_800FE39C_RunningOfTheBulb;
extern u16 D_800FE3A0_RunningOfTheBulb[8];
extern char D_800FE3B0_RunningOfTheBulb[];
extern char D_800FE3C0_RunningOfTheBulb[];

extern s16 D_800FE440_RunningOfTheBulb;
extern void* D_800FE444_RunningOfTheBulb;
extern u16 D_800FE448_RunningOfTheBulb;
extern u16 D_800FE44A_RunningOfTheBulb;
extern s16 D_800FE44C_RunningOfTheBulb[4];
extern s16 D_800FE454_RunningOfTheBulb;
extern u16 D_800FE456_RunningOfTheBulb;
extern s16 D_800FE458_RunningOfTheBulb;
extern u16 D_800FE45A_RunningOfTheBulb;
extern omObjData** D_800FE460_RunningOfTheBulb; /* func_8005DB44(0): the four players */
extern u16 D_800FE464_RunningOfTheBulb; /* 0 intro, 1 play, 2 end */
extern Vec2f D_800FE468_RunningOfTheBulb;
extern omObjData* D_800FE470_RunningOfTheBulb[2]; /* [1] the stage (retail's D_800FE474) */
extern omObjData* D_800FE478_RunningOfTheBulb; /* the big bulb */
extern omObjData* D_800FE47C_RunningOfTheBulb; /* the block list (RotbBlockList) */
extern omObjData** D_800FE480_RunningOfTheBulb; /* func_8005DB44(2): the six falling blocks */
extern Vec3f D_800FE484_RunningOfTheBulb;
extern omObjData* D_800FE490_RunningOfTheBulb;
extern omObjData* D_800FE494_RunningOfTheBulb;
extern omObjData* D_800FE498_RunningOfTheBulb;
extern omObjData** D_800FE49C_RunningOfTheBulb; /* func_8005DB44(1): the four bulbs */
extern omObjData* D_800FE4A0_RunningOfTheBulb; /* the leading player */
extern u16 D_800FE4A4_RunningOfTheBulb; /* ending state */
extern omObjData* D_800FE4A8_RunningOfTheBulb;
extern omObjData* D_800FE4AC_RunningOfTheBulb;
extern u16 D_800FE4B4_RunningOfTheBulb;
extern Vec3f D_800FE4B8_RunningOfTheBulb;
extern omObjData* D_800FE4C4_RunningOfTheBulb;

/* ---------------------------------------------------------------------------------------------
   Functions
   --------------------------------------------------------------------------------------------- */

void func_800F65E0_RunningOfTheBulb(void);
void func_800F6AC0_RunningOfTheBulb(omObjData*);
void func_800F6B28_RunningOfTheBulb(void);
void func_800F6BE4_RunningOfTheBulb(omObjData*);
void func_800F6DF4_RunningOfTheBulb(omObjData*);
void func_800F6E80_RunningOfTheBulb(omObjData*);
void func_800F6F04_RunningOfTheBulb(omObjData*);
void func_800F6FF4_RunningOfTheBulb(omObjData*);
void func_800F7034_RunningOfTheBulb(omObjData*);
void func_800F7278_RunningOfTheBulb(omObjData*);
void func_800F7364_RunningOfTheBulb(u16, u16);
void func_800F7478_RunningOfTheBulb(omObjData*);
omObjData* func_800F77B4_RunningOfTheBulb(omObjData*);
void func_800F7A0C_RunningOfTheBulb(Vec*, Vec*, Vec*, Vec*);
void func_800F7AEC_RunningOfTheBulb(omObjData*);
void func_800F7B08_RunningOfTheBulb(omObjData*);
void func_800F7B24_RunningOfTheBulb(omObjData*);
void func_800F7B40_RunningOfTheBulb(omObjData*);
void func_800F7B5C_RunningOfTheBulb(omObjData*, s32);
void func_800F8210_RunningOfTheBulb(omObjData*);
void func_800F82F4_RunningOfTheBulb(omObjData*);
void func_800F8D80_RunningOfTheBulb(omObjData*);
void func_800F8EA0_RunningOfTheBulb(omObjData*);
void func_800F9094_RunningOfTheBulb(omObjData*);
void func_800F947C_RunningOfTheBulb(omObjData*, f32);
void func_800F9550_RunningOfTheBulb(omObjData*);
void func_800F960C_RunningOfTheBulb(omObjData*);
void func_800F9648_RunningOfTheBulb(omObjData*);
u16 func_800F9650_RunningOfTheBulb(void);
void func_800F9724_RunningOfTheBulb(omObjData*);
void func_800F98F0_RunningOfTheBulb(omObjData*);
void func_800F9C2C_RunningOfTheBulb(omObjData*);
void func_800FA2B8_RunningOfTheBulb(omObjData*);
void func_800FA36C_RunningOfTheBulb(omObjData*);
void func_800FA41C_RunningOfTheBulb(omObjData*);
void func_800FA44C_RunningOfTheBulb(omObjData*, f32);
void func_800FA5B8_RunningOfTheBulb(RotbBulbExt*);
void func_800FA5EC_RunningOfTheBulb(omObjData*);
void func_800FA78C_RunningOfTheBulb(omObjData*);
u16 func_800FAA40_RunningOfTheBulb(omObjData*);
void func_800FAB8C_RunningOfTheBulb(omObjData*);
void func_800FAD68_RunningOfTheBulb(omObjData*);
void func_800FAE18_RunningOfTheBulb(omObjData*);
void func_800FB0D8_RunningOfTheBulb(omObjData*);
void func_800FB180_RunningOfTheBulb(omObjData*);
void func_800FB28C_RunningOfTheBulb(omObjData*);
void func_800FB3F8_RunningOfTheBulb(omObjData*);
void func_800FB540_RunningOfTheBulb(omObjData*);
void func_800FB738_RunningOfTheBulb(omObjData*);
s32 func_800FB8EC_RunningOfTheBulb(omObjData*, omObjData*);
void func_800FBAA4_RunningOfTheBulb(omObjData*);
void func_800FBB5C_RunningOfTheBulb(omObjData*);
void func_800FBF30_RunningOfTheBulb(void);
void func_800FBF74_RunningOfTheBulb(omObjData*);
void func_800FC0F4_RunningOfTheBulb(omObjData*);
f32 func_800FCEA0_RunningOfTheBulb(omObjData*, omObjData*, f32, f32, f32, f32);
f32 func_800FD394_RunningOfTheBulb(omObjData*, omObjData*, f32, f32, f32);
f32 func_800FD9BC_RunningOfTheBulb(u16, f32*);
u16 func_800FDAC4_RunningOfTheBulb(omObjData*, omObjData**, f32*);
f32 func_800FDB84_RunningOfTheBulb(f32, f32);
omObjData* func_800FDCAC_RunningOfTheBulb(omObjData*, f32*);
s32 func_800FDDC0_RunningOfTheBulb(omObjData*);

void func_800FE090_RunningOfTheBulb(f32, f32, f32, f32, f32, f32, f32, f32);
void func_800FE140_RunningOfTheBulb(void);
void func_800FE178_RunningOfTheBulb(s32);
void func_800FE194_RunningOfTheBulb(void);

#endif
