#ifndef BOBSLEDRUN_H
#define BOBSLEDRUN_H

/* ovl_1D BobsledRun (2 vs 2): two bobsleds race down one track, each team on its own half of the
   screen (cameras 0 and 1). Types come from the asm's accesses; N64 offsets are in the comments. */

#include "common.h"

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* One team (D_800FF2A8[2], .data): the bobsled object is D_800F3FB0[team]; the two riders are
   separate objects (func_800FB594). */
typedef struct BRTeam {
    /* 0x00 */ f32 progress;  /* 0 at the top .. 1 at the goal (from the sled's height) */
    /* 0x04 */ f32 unk04;
    /* 0x08 */ f32 unk08;     /* last wall dot product (func_800FCCE8) */
    /* 0x0C */ f32 unk0C;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 roll;      /* camera roll offset */
    /* 0x1C */ s16 state;     /* 0 start, 1 racing, 2 crashed out, 3 goal */
    /* 0x1E */ s16 timer;     /* frames in the air / after the goal */
    /* 0x20 */ s16 unk20;
    /* 0x22 */ s16 unk22;
    /* 0x24 */ u16 sprite;    /* rider 1's map marker */
    /* 0x26 */ u16 sprite2;   /* rider 2's map marker */
    /* 0x28 */ s16 unk28;
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ s16 unk2C;
    /* 0x2E */ s16 unk2E;
    /* 0x30 */ s16 sound;     /* sliding sound handle */
    /* 0x32 */ u8 unk32;      /* boost rumble started */
    /* 0x33 */ u8 boost;      /* boost frames left */
    /* 0x34 */ s8 anim;       /* rider animation request */
    /* 0x35 */ s8 player[2];  /* the two players */
    /* 0x37 */ s8 port[2];    /* their controller ports */
    /* 0x39 */ s8 mdl[10];    /* model indices (sled, riders, alternates) */
    /* 0x43 */ s8 path;       /* which CPU path table */
    /* 0x44 */ s8 unk44;      /* bump sound counter */
    /* 0x45 */ char unk45[3];
} BRTeam; /* size = 0x48 */

/* The bobsled object's work (func_800FA244: 0xE8 bytes, MgWork's layout; main code reads it). */
typedef struct BRWork {
    /* 0x00 */ char unk_00[0x38];
    /* 0x38 */ f32 unk_38;    /* vertical speed; 1000 = on the ground */
    /* 0x3C */ f32 unk_3C;    /* heading */
    /* 0x40 */ f32 unk_40;    /* speed */
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;    /* radius */
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50;    /* flags */
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ s8 unk_53;     /* ground object */
    /* 0x54 */ s8 unk_54;
    /* 0x55 */ u8 unk_55;
    /* 0x56 */ s8 unk_56;     /* controller port */
    /* 0x57 */ u8 unk_57;
    /* 0x58 */ s8 unk_58;     /* team */
    /* 0x59 */ char unk_59[3];
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ f32 unk_68;
    /* 0x6C */ s32 unk_6C[6]; /* stick samples, (x << 16) | (y & 0xFFFF) */
    /* 0x84 */ Vec3f unk_84;  /* ground normal */
    /* 0x90 */ f32 unk_90;
    /* 0x94 */ f32 unk_94;
    /* 0x98 */ f32 unk_98;
    /* 0x9C */ f32 unk_9C;
    /* 0xA0 */ f32 unk_A0;
    /* 0xA4 */ f32 unk_A4;
    /* 0xA8 */ char unk_A8[9];
    /* 0xB1 */ s8 unk_B1;
    /* 0xB2 */ s8 unk_B2;
    /* 0xB3 */ s8 unk_B3;
    /* 0xB4 */ s16 unk_B4;
    /* 0xB6 */ char unk_B6[2];
    /* 0xB8 */ void* unk_B8;  /* MgWork's held item: a pointer in every view of this work */
    /* 0xBC */ f32 unk_BC;
    /* 0xC0 */ u16 unk_C0;
    /* 0xC2 */ char unk_C2[0x16];
    /* 0xD8 */ s16 (*unk_D8)[2]; /* motion table */
    /* 0xDC */ void* unk_DC;
    /* 0xE0 */ s32 unk_E0;
    /* 0xE4 */ void* unk_E4;
} BRWork; /* size = 0xE8 */

/* A ground object's work (D_800F2AF8[i]->unk_50, 0x2C bytes; 1130.c's GroundWork). */
typedef struct BRGround {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ char unk_02[2];
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ char unk_14[0x18];
} BRGround; /* size = 0x2C */

/* Collision mesh (1130.c's ColVtx / ColTri). */
typedef struct BRColVtx {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 z;
} BRColVtx;

typedef struct BRColTri {
    /* 0x0 */ s16 flags;
    /* 0x2 */ s16 v[3];
} BRColTri;

/* Speed history of one team's camera (bss D_800FF8E8 / D_800FF9E0, 0xF8 apart). */
typedef struct BRHist {
    /* 0x00 */ s32 idx;
    /* 0x04 */ f32 unk04[40];
    /* 0xA4 */ f32 samples[20];
} BRHist; /* size = 0xF4 */

/* objmain.c's per-camera view record (D_800F2C28[]). */
typedef struct BRCameraView {
    /* 0x00 */ f32 rot;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 z;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 far;
    /* 0x14 */ f32 near;
} BRCameraView; /* size = 0x18 */

#define BR_WORK(obj) ((BRWork*)(obj)->unk_50)

/* ---------------------------------------------------------------------------------------------
   Data (.data)
   --------------------------------------------------------------------------------------------- */
extern s8 D_800FF2A0_BobsledRun; /* winning team, -1 none yet */
extern s8 D_800FF2A1_BobsledRun; /* result: -1 racing, -2 both crashed, -3 time up, else team */
extern f32 D_800FF2A4_BobsledRun; /* camera pitch */
extern BRTeam D_800FF2A8_BobsledRun[2];
extern f32 D_800FF338_BobsledRun;
extern f32 D_800FF33C_BobsledRun;
extern f32 D_800FF340_BobsledRun[2]; /* camera roll */
extern s32 D_800FF348_BobsledRun;
extern s16 D_800FF34C_BobsledRun; /* race time (frames) */
/* Sound handles kept as s32; retail reads the low half (D_800FF352 / D_800FF356). */
extern s32 D_800FF350_BobsledRun;
extern s32 D_800FF354_BobsledRun;
extern f32 D_800FF358_BobsledRun[6];
extern f32 D_800FF370_BobsledRun[6];
extern f32 D_800FF388_BobsledRun[2]; /* tunnel 1: top, bottom */
extern f32 D_800FF390_BobsledRun[2]; /* tunnel 2 */
extern u32 D_800FF398_BobsledRun;
extern s32 D_800FF39C_BobsledRun;
extern s32 D_800FF3A0_BobsledRun;
extern s32 D_800FF3A4_BobsledRun;
extern s32 D_800FF3A8_BobsledRun;
extern s32 D_800FF3AC_BobsledRun;
extern s32 D_800FF3B0_BobsledRun;
extern Vec3f D_800FF3B4_BobsledRun[44]; /* CPU steering points, path 1 */
extern Vec3f D_800FF5C4_BobsledRun[40]; /* path 0 */
extern Vec3f D_800FF7A4_BobsledRun[6];  /* CPU braking ranges, path 1 */
extern Vec3f D_800FF7EC_BobsledRun[7];  /* path 0 */

/* ---------------------------------------------------------------------------------------------
   Bss
   --------------------------------------------------------------------------------------------- */
extern Vec3f D_800FF8D0_BobsledRun[2]; /* per-team shove direction */
extern BRHist D_800FF8E8_BobsledRun;
extern BRHist D_800FF9E0_BobsledRun;
/* The progress bar's two sprite groups: track pieces, then the flag. Retail addresses the flag as
   its own label inside D_800FFAD4's 4 bytes (undefined_syms.txt); the host reads it from there. */
extern u16 D_800FFAD4_BobsledRun;
extern u16 D_800FFAD6_BobsledRun;
extern u16 D_800FFAD8_BobsledRun;
extern u16 D_800FFADA_BobsledRun;
extern u16 D_800FFADC_BobsledRun;
extern u16 D_800FFADE_BobsledRun;
extern s16 D_800FFAE0_BobsledRun;
extern s16 D_800FFAE2_BobsledRun;
extern s16 D_800FFAE4_BobsledRun[2];
extern u16 D_800FFAE8_BobsledRun;
extern u16 D_800FFAEA_BobsledRun;
extern u16 D_800FFAEC_BobsledRun;
extern BRColVtx* D_800FFAF0_BobsledRun;
extern BRColVtx* D_800FFAF4_BobsledRun;
extern BRColVtx* D_800FFAF8_BobsledRun;

/* ---------------------------------------------------------------------------------------------
   Main code
   --------------------------------------------------------------------------------------------- */
extern Vec3f CenterM[];
extern Vec3f CRotM[];
extern f32 CZoomM[];
extern BRCameraView D_800F2C28[];
extern omObjData* D_800F2AF8[];
extern u16 D_800EE984;
extern s8 ContStkY[];
extern u16 ContBtn[];
extern f32 D_800ED6B8;
extern f32 D_800F5254;
extern u16 D_800F370C;
extern u8 D_800F64F8;
extern u8 D_800B8954;
extern s16 D_800B8956;
extern u8 D_800B8958;
extern u8 D_800B8959;
extern f32 D_800B895C;
extern f32 D_800B8964;
extern f32 D_800B8968;
extern f32 D_800B896C;
extern f32 D_800B8980;
extern f32 D_800B8990;
extern f32 D_800B8994;

f32 func_800006E4(omObjData* obj, f32 y);
s32 func_80002060();
s32 func_80004D1C(omObjData*, Vec4f*, f32);
f32 func_800051D4(omObjData*, f32, f32, f32, Vec3f*);
void func_80005A04(omObjData*);
void func_80005A28(omObjData*);
void func_800078E8(f32, f32, f32);
void func_80008FA0(omObjData*, f32);
void func_80008FDC(omObjData*, f32);
void func_80008FE8(omObjData*, f32);
void func_80008FF4(omObjData*, f32);
void func_800090C4(omObjData* obj, u8 idx, u8 val);
void func_800093FC(omObjData*, f32, f32, f32);
void func_800096B0(BRWork*, s32);
s32 func_80009C90(omObjData*, s16, s16);
void func_80009D48(s16*, s16*);
s32 func_8000A910(Vec4f*, BRGround*);
s32 func_80017A60(omObjData*);
s32 func_800185A4(omObjData*, u16);
void func_8001897C(s16, f32, f32, f32);
void func_80018FBC(u16, s16, s16, s16);
f32 func_80025D18(s16);
f32 func_80025D40(s16);
f32 func_80025E70(s16);
f32 func_80029518(f32);
void func_8002956C(Vec3f*);
void func_800295FC(BRColVtx*, BRColVtx*, BRColVtx*, Vec3f*);
f32 func_80029764(f32, f32, f32, BRColVtx*, BRColTri*);
void func_8002AE24(s16, s32*, void*, void*);
BRColTri* func_8002B3A8(s32*);
void func_800370D4(s16);
void func_80037178(s16, Vec3f*);
void func_800594E4(s16, u16);
void func_80060440(s16, s16);
void func_8006073C(void);
void func_80060F04(s16, s32, s32, s32);
void func_800AF2E0(f32, f32*, f32*);

/* ---------------------------------------------------------------------------------------------
   Overlay functions
   --------------------------------------------------------------------------------------------- */
void func_800F6B60_BobsledRun(omObjData* obj);
BRGround* func_800F6D20_BobsledRun(BRWork* work);
void func_800F6D8C_BobsledRun(void);
void func_800F6DB8_BobsledRun(BRWork* work, f32 x, f32 z, f32 ox, f32 oz);
void func_800F6F20_BobsledRun(omObjData* obj);
void func_800F78F4_BobsledRun(omObjData* obj);
s32 func_800F9138_BobsledRun(omObjData* obj, f32 x, f32 y, f32 z);
f32 func_800F93C0_BobsledRun(omObjData* obj, f32 rot, f32 x, f32 y, f32 z);
f32 func_800F9A8C_BobsledRun(omObjData* obj, f32 x, f32 y, f32 z, f32 oldY);
void func_800FA15C_BobsledRun(s8 team, Vec3f* normal);
void func_800FA244_BobsledRun(omObjData* obj, s32 dir, s32 file, u16 team, u16 flags, u16 motFile);
void func_800FA484_BobsledRun(omObjData* obj, s8 player, s8 port);
void func_800FA890_BobsledRun(omObjData* obj);
void func_800FA96C_BobsledRun(omObjData* obj);
void func_800FAD64_BobsledRun(omObjData* obj);
void func_800FAE44_BobsledRun(omObjData* obj);
void func_800FAF20_BobsledRun(omObjData* obj);
void func_800FB000_BobsledRun(omObjData* obj);
void func_800FB0DC_BobsledRun(omObjData* obj);
void func_800FB1C4_BobsledRun(omObjData* obj, s32 dir, s32 file, u16 team);
void func_800FB594_BobsledRun(omObjData* obj, s32 dir, s32 file, u16 player, u16 team);
void func_800FB858_BobsledRun(omObjData* obj);
void func_800FB93C_BobsledRun(omObjData* obj);
void func_800FBA00_BobsledRun(omObjData* obj);
void func_800FBB5C_BobsledRun(omObjData* obj);
void func_800FBCB8_BobsledRun(omObjData* obj);
void func_800FBD5C_BobsledRun(omObjData* obj);
void func_800FBE04_BobsledRun(omObjData* obj, Vec3f* normal);
void func_800FBF88_BobsledRun(Mat4 m, Vec3f* pos, Vec3f* axis, f32 angle);
void func_800FC180_BobsledRun(omObjData* obj);
void func_800FC4D0_BobsledRun(BRWork* work);
void func_800FC7DC_BobsledRun(omObjData* obj);
void func_800FC918_BobsledRun(void);
void func_800FC9F8_BobsledRun(void);
f32 func_800FCA48_BobsledRun(s32 team, f32 value);
s32 func_800FCAC0_BobsledRun(omObjData* obj);
void func_800FCB44_BobsledRun(void);
void func_800FCCE8_BobsledRun(omObjData* obj, Vec3f* normal, f32 turn);
void func_800FCE2C_BobsledRun(s16 idx, s16 time);
void func_800FD124_BobsledRun(void);
void func_800FD164_BobsledRun(void);
s16 func_800FD1BC_BobsledRun(s32 x, s32 y);
void func_800FD36C_BobsledRun(s32 x, s32 y);
void func_800FD51C_BobsledRun(omObjData* obj);
void func_800FDCA8_BobsledRun(omObjData* obj, s16 force, f32 minSpeed, f32 rot, f32 x, f32 y, f32 z);
void func_800FDFC8_BobsledRun(s32 team, u8 mdl);
void func_800FE080_BobsledRun(omObjData* obj);
void func_800FEC80_BobsledRun(omObjData* obj);

#endif
