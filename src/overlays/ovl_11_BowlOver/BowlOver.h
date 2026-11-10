#ifndef BOWLOVER_H
#define BOWLOVER_H

/* ovl_11 BowlOver: declarations for its two units, 13EFB0.c (setup, ball, camera) and 142EA0.c
   (alley, pins, players). Types come from the asm's accesses; N64 offsets are in the comments.
   Work blocks are allocated with retail's literal sizes only where every field keeps its N64
   offset on the host (pointers 8-aligned). */

#include "common.h"

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* A player's work (obj->unk_50 of the bowler and the three pin players): MgWork's layout
   (src/99E0.c, 0xE8). Pointers at 0xB8 and 0xD8 only, both 8-aligned: every field keeps its
   N64 offset on the host. */
typedef struct BowlPlayerWork {
    /* 0x00 */ u8 unk_00[0x38];
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ char unk_40[0x10];
    /* 0x50 */ u16 unk_50; /* flags: 0x20 holding / held, 0x40 can be picked up */
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ char unk_53[3];
    /* 0x56 */ u8 unk_56; /* controller port */
    /* 0x57 */ char unk_57;
    /* 0x58 */ s8 unk_58; /* player index */
    /* 0x59 */ char unk_59[0x47];
    /* 0xA0 */ f32 unk_A0;
    /* 0xA4 */ f32 unk_A4;
    /* 0xA8 */ char unk_A8[0x10];
    /* 0xB8 */ struct omObjData* unk_B8; /* the held ball */
    /* 0xBC */ char unk_BC[4];
    /* 0xC0 */ u16 unk_C0;
    /* 0xC2 */ char unk_C2[0x16];
    /* 0xD8 */ void* unk_D8; /* motion table */
    /* 0xDC */ char unk_DC[0xC];
} BowlPlayerWork; /* size = 0xE8 (N64) */

/* The ball's work (func_800F91D0): src/1130.c's PlayerWork prefix (0x6C), no pointers. */
typedef struct BowlBallWork {
    /* 0x00 */ char unk_00[0x34];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ char unk_40[4];
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ char unk_4C[4];
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ char unk_53;
    /* 0x54 */ u8 unk_54;
    /* 0x55 */ char unk_55[3];
    /* 0x58 */ f32 unk_58;
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ s32 unk_60;
    /* 0x64 */ char unk_64[8];
} BowlBallWork; /* size = 0x6C */

/* Alley / pin collision work (0x2C, src/1130.c's GroundWork). */
typedef struct BowlFloorWork {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk_06[0x26];
} BowlFloorWork; /* size = 0x2C */

/* Per-pin state (D_800FD880_BowlOver[6], indexed by obj->work[3]); no pointers. */
typedef struct BowlPin {
    /* 0x00 */ f32 unk_00; /* tilt */
    /* 0x04 */ f32 unk_04; /* fall direction */
    /* 0x08 */ f32 unk_08; /* tilt target */
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ u8 unk_0E; /* knocked down */
    /* 0x0F */ u8 unk_0F; /* fall finished */
    /* 0x10 */ u8 unk_10; /* coins spawned */
    /* 0x11 */ u8 unk_11;
    /* 0x14 */ f32 unk_14; /* coins lost */
    /* 0x18 */ f32 unk_18[5]; /* coin y */
    /* 0x2C */ f32 unk_2C[5]; /* coin y speed */
    /* 0x40 */ f32 unk_40[5];
    /* 0x54 */ f32 unk_54[5]; /* coin x direction */
    /* 0x68 */ f32 unk_68[5]; /* coin z direction */
    /* 0x7C */ f32 unk_7C[5]; /* coin distance */
    /* 0x90 */ f32 unk_90[5]; /* coin bounce */
} BowlPin; /* size = 0xA4 */

/* Per-pin player jump / stick state (D_800FDC60_BowlOver[6]); no pointers. */
typedef struct BowlJump {
    /* 0x00 */ f32 unk_00; /* y speed */
    /* 0x04 */ f32 unk_04; /* spin speed */
    /* 0x08 */ f32 unk_08; /* facing */
    /* 0x0C */ f32 unk_0C; /* CPU: last x */
    /* 0x10 */ f32 unk_10; /* CPU: last z */
    /* 0x14 */ s16 unk_14; /* jumping */
    /* 0x16 */ s16 unk_16; /* spin frames */
    /* 0x18 */ s16 unk_18; /* landed */
    /* 0x1A */ s16 unk_1A; /* spinning */
    /* 0x1C */ s16 unk_1C; /* spin direction */
    /* 0x1E */ char unk_1E[2];
    /* 0x20 */ u8 unk_20; /* stick history slot */
    /* 0x21 */ s8 unk_21[8]; /* stick x history */
    /* 0x29 */ s8 unk_29[8]; /* stick y history */
    /* 0x31 */ s8 unk_31; /* CPU: jump now */
    /* 0x32 */ char unk_32;
    /* 0x33 */ s8 unk_33; /* stick x */
    /* 0x34 */ s8 unk_34; /* stick y */
    /* 0x35 */ u8 unk_35; /* CPU mode */
    /* 0x36 */ char unk_36[2];
} BowlJump; /* size = 0x38 */

/* Pin-player model table (D_800FD5D8_BowlOver): character directory, file, and the two node
   names func_80020EA0 joins. */
typedef struct BowlHead {
    /* 0x00 */ s32 unk_00; /* character directory (chr << 16 >> 16) */
    /* 0x04 */ s32 unk_04; /* head file in directory 0x23 */
    /* 0x08 */ char unk_08[21];
    /* 0x1D */ char unk_1D[23];
} BowlHead; /* size = 0x34 */

/* ---------------------------------------------------------------------------------------------
   Data (.data, 13EFB0.c)
   --------------------------------------------------------------------------------------------- */

extern s16 D_800FD2D0_BowlOver[4]; /* ball out (1) */
extern u16 D_800FD2D8_BowlOver;    /* ball near the pins */
extern u16 D_800FD2DA_BowlOver;
extern u16 D_800FD2DC_BowlOver[2]; /* ball in the gutter */
extern s8 D_800FD2E0_BowlOver;
extern s8 D_800FD2E1_BowlOver;
extern f32 D_800FD2E4_BowlOver;
extern u16 D_800FD2E8_BowlOver;
extern u16 D_800FD2EA_BowlOver;
extern u32 D_800FD2EC_BowlOver; /* intro frames */
extern s8 D_800FD2F0_BowlOver;
extern s8 D_800FD2F1_BowlOver;
extern s8 D_800FD2F2_BowlOver; /* pins down */
extern s8 D_800FD2F3_BowlOver;
extern s8 D_800FD2F4_BowlOver;
extern s8 D_800FD2F5_BowlOver;
extern s8 D_800FD2F6_BowlOver;
extern s8 D_800FD2F7_BowlOver;
extern s32 D_800FD2F8_BowlOver;
extern s32 D_800FD2FC_BowlOver;
extern s32 D_800FD300_BowlOver; /* throw timer */
extern s32 D_800FD304_BowlOver; /* bowler state */
extern u16 D_800FD308_BowlOver;
extern s16 D_800FD30A_BowlOver;
extern s16 D_800FD30C_BowlOver[2];
extern f32 D_800FD310_BowlOver[3][2]; /* bowler x range per alley */
extern u8 D_800FD328_BowlOver;
extern u8 D_800FD329_BowlOver;
extern u8 D_800FD32A_BowlOver;
extern u16 D_800FD32C_BowlOver[2]; /* CPU: set up, last buttons */
extern s32 D_800FD330_BowlOver;   /* CPU frames */
extern f32 D_800FD334_BowlOver;   /* CPU stick x, -1 none */
extern u8 D_800FD338_BowlOver[4];
extern f32 D_800FD33C_BowlOver;
extern f32 D_800FD340_BowlOver;
extern f32 D_800FD344_BowlOver;
extern f32 D_800FD348_BowlOver;
extern f32 D_800FD34C_BowlOver;
extern s8 D_800FD350_BowlOver;
extern s8 D_800FD351_BowlOver;
extern Vec3f D_800FD354_BowlOver[2];
extern Vec3f D_800FD36C_BowlOver[2];
extern Vec4f D_800FD384_BowlOver[2];
extern s8 D_800FD3B0_BowlOver;
extern f32 D_800FD3B4_BowlOver;
extern s8 D_800FD3B8_BowlOver[8];
extern s8 D_800FD3C0_BowlOver[8];
extern s8 D_800FD3C8_BowlOver;
extern u32 D_800FD3CC_BowlOver; /* random seed */
extern u8 D_800FD3D0_BowlOver[4]; /* [0]: alley (0-2) */
extern s32 D_800FD3D4_BowlOver[3]; /* alley model per alley */

/* ---------------------------------------------------------------------------------------------
   Data (.data, 142EA0.c)
   --------------------------------------------------------------------------------------------- */

extern f32 D_800FD3E0_BowlOver[3][16][2]; /* alley lights (x, z) per alley */
extern u16 D_800FD560_BowlOver[2];         /* pins knocked (sound pitch) */
extern Vec3f D_800FD564_BowlOver[6];       /* pin positions */
extern s16 D_800FD5AC_BowlOver[8];         /* coins per player */
extern f32 D_800FD5BC_BowlOver[6];
extern f32 D_800FD5D4_BowlOver;
extern BowlHead D_800FD5D8_BowlOver[6];

/* ---------------------------------------------------------------------------------------------
   Bss (asm; link-map names)
   --------------------------------------------------------------------------------------------- */

extern s8 D_800FD830_BowlOver; /* the ball falls to the right */
extern f32 D_800FD834_BowlOver;
extern s16 D_800FD838_BowlOver;
extern s16 D_800FD83A_BowlOver;
extern s16 D_800FD83C_BowlOver;
extern s16 D_800FD83E_BowlOver;
extern s16 D_800FD840_BowlOver;
extern s16 D_800FD842_BowlOver[7]; /* rolling sound handles */
extern u16 D_800FD850_BowlOver[8];  /* pin slot per pin object */
extern omObjData* D_800FD860_BowlOver[6]; /* the six pins */
extern omObjData* D_800FD878_BowlOver; /* the ball */
extern BowlPin D_800FD880_BowlOver[6];
extern s16 D_800FDC58_BowlOver;
extern s8 D_800FDC5A_BowlOver[4]; /* [0] bowler, [1..3] pins */
extern s16 D_800FDC5E_BowlOver;
extern BowlJump D_800FDC60_BowlOver[6];

/* ---------------------------------------------------------------------------------------------
   Main code
   --------------------------------------------------------------------------------------------- */

extern Vec3f CenterM[];
extern Vec3f CRotM[];
extern f32 CZoomM[];
extern omObjData* D_800F2AF8[];
extern u16 D_800EE984;
extern u16 ContBtn[];
extern s8 ContStkY[];

void func_80008FDC(omObjData*, f32);
void func_80008FE8(omObjData*, f32);
void func_8000940C(omObjData*, f32, f32, f32);
void func_800093FC(omObjData*, f32, f32, f32);
void func_800090C4(omObjData* obj, u8 idx, u8 val);
void func_80025BB8(s16, s16);
f32 func_80025D18(s16);
f32 func_80025D40(s16);
void GMesSprClose(void);
void func_8006073C(void);
extern int guRandom(void);
void func_8002AE24(s16, s32*, void*, void*);
s16* func_8002B3A8(s32*);
s32 func_80002060(void*, s16*, void*, Vec3f*);
void func_800284E4(s16);
void func_80036ABC(unk2C0C0StructC0*);
void func_8006035C(s16, s8);
void func_80060440(s16, s16);
void func_8002859C(s16 arg0, s16 arg1, char* arg2);
void func_80017B4C(u8 mdl);
void func_80060F04(s16, s16, s16, s16);
void func_80020EA0(s16, char*, s16, char*);
void func_80039970(s16, f32);
void func_800AF2E0(f32, f32*, f32*);

/* ---------------------------------------------------------------------------------------------
   Overlay functions
   --------------------------------------------------------------------------------------------- */

void func_800F65E0_BowlOver(void);
s8 func_800F6A2C_BowlOver(void);
void func_800F71BC_BowlOver(omObjData* obj);
void func_800F7C24_BowlOver(omObjData* obj);
void func_800F7D14_BowlOver(omObjData* obj);
void func_800F7E20_BowlOver(omObjData* obj);
void func_800F8274_BowlOver(omObjData* obj);
void func_800F8964_BowlOver(omObjData* obj, s32 dir, s32 file, s32 player, f32 x, f32 y, f32 z);
void func_800F8C64_BowlOver(omObjData* obj);
void func_800F91D0_BowlOver(omObjData* obj);
void func_800F9450_BowlOver(void);
void func_800F9668_BowlOver(omObjData* obj);
void func_800F9838_BowlOver(s16 mdl, u8 r, u8 g, u8 b);
void func_800F9990_BowlOver(s16 mdl, u8 r, u8 g, u8 b);
void func_800F9A80_BowlOver(s16 cam, f32 zoom, f32 rx, f32 ry, f32 rz, f32 cx, f32 cy, f32 cz);
void func_800F9B00_BowlOver(omObjData* obj);
void func_800F9B78_BowlOver(omObjData* obj);
void func_800F9C0C_BowlOver(omObjData* obj, f32 x, f32 y, f32 z);
s32 func_800F9CF8_BowlOver(omObjData* obj, omObjData* ball);
f32 func_800F9DB4_BowlOver(void);
f32 func_800F9F80_BowlOver(void);
s32 func_800FA080_BowlOver(omObjData* obj, f32* dx, f32* dz);
void func_800FA1D8_BowlOver(Vec3f* pos, Vec3f* axis, f32 angle, Mat4 out);
s32 func_800FA3D0_BowlOver(u32 seed);
u32 func_800FA4A4_BowlOver(void);

void func_800FA4D0_BowlOver(omObjData* obj);
void func_800FA5A0_BowlOver(omObjData* obj);
void func_800FA8D0_BowlOver(void);
void func_800FAAF8_BowlOver(u8 mdl, f32 x, f32 y, f32 z);
void func_800FABA0_BowlOver(omObjData* obj, f32* dx, f32* dz);
void func_800FAC94_BowlOver(omObjData* obj, f32 dx, f32 dz);
void func_800FAE2C_BowlOver(omObjData* obj);
void func_800FB230_BowlOver(omObjData* obj);
void func_800FB650_BowlOver(omObjData* obj, BowlJump* jump, u8* sx, u8* sy);
void func_800FBB30_BowlOver(omObjData* obj);
void func_800FC598_BowlOver(omObjData* obj, s32 dir, s32 file, s32 player, u16 slot, u16 pin);
void func_800FC9E0_BowlOver(omObjData* obj);
void func_800FCD54_BowlOver(omObjData* obj, u16 slot, s8 pin);
void func_800FCFA0_BowlOver(void);
void func_800FD07C_BowlOver(omObjData* obj);
void func_800FD118_BowlOver(omObjData* obj);
void func_800FD1B8_BowlOver(omObjData* obj);
void func_800FD258_BowlOver(omObjData* obj);
void func_800FD27C_BowlOver(omObjData* obj);
void func_800FD2A0_BowlOver(omObjData* obj);

#endif
