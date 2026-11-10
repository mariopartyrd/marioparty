#ifndef HANDCARHAVOC_H
#define HANDCARHAVOC_H

/* ovl_2F HandcarHavoc (2v2): units 20F570 and 216140. Two teams pump a handcar each along a
   track (two viewports, one camera per team); a car that takes a bend too fast leans, tips over
   and throws its riders. Types come from the asm's accesses; N64 offsets are in the comments. */

#include "common.h"
#include "sprite65770.h"
#include "PR/gu.h"

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* A handcar (D_800FF618_HandcarHavoc[team]->unk_50, func_80023684(0xF8)). Overlay-only; no
   pointers. Model slots: [0] car, [1] lever, [2] lever (pumping), [3+seat] riders. */
typedef struct HHCar {
    /* 0x00 */ f32 unk00;
    /* 0x04 */ f32 pump;      /* pump power, +0.3 per A press (max 5) */
    /* 0x08 */ f32 speed;     /* along the track (negative = forward) */
    /* 0x0C */ f32 maxSpeed;
    /* 0x10 */ f32 leanIn;    /* both riders' stick lean */
    /* 0x14 */ f32 lean;      /* follows leanIn by 2 per frame */
    /* 0x18 */ f32 tilt;      /* side tilt; +-25 tipping, +-60 fallen */
    /* 0x1C */ char unk1C[0x10];
    /* 0x2C */ Vec rot;
    /* 0x38 */ Vec prevRot;
    /* 0x44 */ Vec slope;
    /* 0x50 */ Vec prevSlope;
    /* 0x5C */ char unk5C[0xC];
    /* 0x68 */ f32 dist[2];   /* each axle's distance into its track segment */
    /* 0x70 */ char unk70[8];
    /* 0x78 */ f32 progress;
    /* 0x7C */ char unk7C[4];
    /* 0x80 */ f32 decel;
    /* 0x84 */ f32 seat[2];   /* riders' side offsets (D_800FF3C8 by character) */
    /* 0x8C */ f32 tipTimer;
    /* 0x90 */ f32 skidTimer;
    /* 0x94 */ f32 unk94;
    /* 0x98 */ f32 fallV0;    /* fall arc: v0, t, g, angle, side speed */
    /* 0x9C */ f32 fallT;
    /* 0xA0 */ f32 fallG;
    /* 0xA4 */ f32 fallAngle;
    /* 0xA8 */ f32 fallSide;
    /* 0xAC */ u16 cpu;       /* 1: both riders are COMs (max speed by difficulty) */
    /* 0xAE */ s16 unkAE;
    /* 0xB0 */ u16 team;
    /* 0xB2 */ u16 player[2];
    /* 0xB6 */ char unkB6[4];
    /* 0xBA */ u16 leverDir;
    /* 0xBC */ u16 lever1Dir;
    /* 0xBE */ u16 lever2Dir;
    /* 0xC0 */ s16 front[2];
    /* 0xC4 */ u16 seg[2];    /* each axle's track segment */
    /* 0xC8 */ u16 chips[2][2]; /* sparks per side and wheel (max D_800FF3C0) */
    /* 0xD0 */ u16 brake;
    /* 0xD2 */ u16 sndOn;
    /* 0xD4 */ s16 snd;
    /* 0xD6 */ u16 sparkSndOn;
    /* 0xD8 */ s16 sparkSnd;
    /* 0xDA */ char unkDA[2];
    /* 0xDC */ u16 marker;    /* map marker sprite */
    /* 0xDE */ u16 face[2];   /* riders' faces on the map */
    /* 0xE2 */ u16 goal;
    /* 0xE4 */ u16 stopTimer;
    /* 0xE6 */ char unkE6[4];
    /* 0xEA */ u16 cpuStickTime[2];
    /* 0xEE */ u16 cpuBrakeTime[2];
    /* 0xF2 */ s8 cpuStick[2];
    /* 0xF4 */ u8 cpuDelay[2];
    /* 0xF6 */ char unkF6[2];
} HHCar; /* size = 0xF8 */

/* One frame's input for a rider (stick x/y, pressed, held). */
typedef struct HHPad {
    /* 0x00 */ s8 stkX;
    /* 0x01 */ s8 stkY;
    /* 0x02 */ u16 trg;
    /* 0x04 */ u16 btn;
} HHPad; /* size = 6 */

/* A team camera object's work (func_80023684(0x10)). */
typedef struct HHCam {
    /* 0x00 */ u16 cam;
    /* 0x02 */ u16 timer;
    /* 0x04 */ f32 rx;
    /* 0x08 */ f32 ry;
    /* 0x0C */ char unkC[4];
} HHCam; /* size = 0x10 */

/* A thrown rider's arc (func_80023684(0x18)). */
typedef struct HHFall {
    /* 0x00 */ f32 yaw;
    /* 0x04 */ f32 v0;
    /* 0x08 */ f32 t;
    /* 0x0C */ f32 g;
    /* 0x10 */ f32 angle;
    /* 0x14 */ f32 side;
} HHFall; /* size = 0x18 */

/* The race timer's work (func_80023684(0x20)): two rows of 7 digit sprites. */
typedef struct HHTimer {
    /* 0x00 */ u16 digit[7];  /* this race */
    /* 0x0E */ u16 best[7];   /* record */
    /* 0x1C */ u16 time;
    /* 0x1E */ u16 record;
} HHTimer; /* size = 0x20 */

/* A scrolling background (D_800FF630_HandcarHavoc[2], one per viewport): a sprite's texture
   drawn in 40x40 tiles (func_800FE004). */
typedef struct HHScroll {
    /* 0x00 */ s16 sprite;
    /* 0x02 */ s16 x0;
    /* 0x04 */ s16 y0;
    /* 0x06 */ u16 x1;
    /* 0x08 */ u16 y1;
    /* 0x0A */ u16 cols;
    /* 0x0C */ u16 rows;
    /* 0x0E */ u16 w;
    /* 0x10 */ u16 h;
    /* 0x12 */ s16 sx;
    /* 0x14 */ s16 sy;
    /* 0x16 */ char unk16[2];
    /* 0x18 */ f32 u;
    /* 0x1C */ f32 v;
    /* 0x20 */ f32 angle;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 dAngle;
    /* 0x2C */ u8 unk2C;
    /* 0x2D */ char unk2D[3];
} HHScroll; /* size = 0x30 */

/* A spark: two corners of a triangle drawn from the wheel. */
typedef struct HHChip {
    /* 0x00 */ f32 unk00[3];
    /* 0x0C */ Vec a;
    /* 0x18 */ Vec b;
} HHChip; /* size = 0x24 */

/* A spark burst (D_800FFCC0_HandcarHavoc[team][12]): four triangles, model D_80101C40. */
typedef struct HHSparks {
    /* 0x00 */ u16 active;
    /* 0x02 */ u16 timer;
    /* 0x04 */ u16 unk4;
    /* 0x06 */ u16 side;
    /* 0x08 */ u16 wheel;
    /* 0x0A */ char unkA[2];
    /* 0x0C */ HHChip chip[9];
} HHSparks; /* size = 0x150 */

/* A collision vertex of the track model (unk_6C->unk_78). */
typedef struct HHColVtx {
    s16 x;
    s16 y;
    s16 z;
} HHColVtx;

/* A collision face: three vertex indices from +2. */
typedef struct HHColFace {
    s16 unk0;
    s16 v[3];
} HHColFace;

typedef struct HHLightDir {
    s16 x;
    s16 y;
    s16 z;
} HHLightDir;

/* objmain.c's per-camera view record (omCameraView). */
typedef struct HHCameraView {
    /* 0x00 */ f32 rot;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 z;
    /* 0x0C */ f32 fov;
    /* 0x10 */ f32 far;
    /* 0x14 */ f32 near;
} HHCameraView; /* size = 0x18 */

typedef struct HHCount {
    u16 timer;
    u16 delay;
} HHCount;

/* obj->work[0..3] tested as one big-endian word (retail: lw + and 0x06000000 = work[0] & 6). */
#define HH_DONE(obj) (*(u32*)(obj)->work & 0x06000000)

/* ---------------------------------------------------------------------------------------------
   Main code
   --------------------------------------------------------------------------------------------- */

extern Vec3f CRotM[];
extern Vec3f CenterM[];
extern f32 CZoomM[];
extern HHCameraView D_800F2C28[];
extern s16 D_800F3778;
extern s32 D_800EDEC0;
extern u8 D_800F64F8;
extern s8 ContStkX[];
extern s8 ContStkY[];
extern u16 ContBtnTrg[];
extern u16 ContBtn[];

void omInitObjMan(s32, s32);
void omSetObjPrio(omObjData*, s16);
void MtxRotate(Matrix4f, f32, f32, f32);
void func_80017940(s32);
void func_8001897C(s16, f32, f32, f32);
void func_80018DC4(u16, f32);
void func_8002346C(s32, s32, s32);
s32 func_80024198(u32, Gfx*, s32);
void func_80025BB8(s16, s16);
f32 func_80025D18(s16);
f32 func_80025D40(s16);
void func_80027AC8(s16, u8*, u8*);
void func_80027E48(s16, f32, f32, u16, u16, char*, u8);
void func_800295FC(void*, void*, void*, Vec3f*);
void func_800594E4(s16, u16);
void func_80060440(s16, s16);
void func_80060F04(s16, s16, s16, s16);
f64 func_8009AFD0(f64);
f64 func_8009B618(f64, f64);

/* ---------------------------------------------------------------------------------------------
   Overlay
   --------------------------------------------------------------------------------------------- */

void func_800F65E0_HandcarHavoc(void);
void func_800F6BBC_HandcarHavoc(omObjData* obj, HHPad* pad, u16 seat);
void func_800F72B0_HandcarHavoc(omObjData* obj);
void func_800F7314_HandcarHavoc(void);
void func_800F757C_HandcarHavoc(omObjData* obj);
void func_800F7998_HandcarHavoc(omObjData* obj);
void func_800F7DD8_HandcarHavoc(void);
void func_800F7E8C_HandcarHavoc(omObjData* obj);
void func_800F7EC8_HandcarHavoc(omObjData* obj);
void func_800F7F04_HandcarHavoc(omObjData* obj, u16 team, f32 x, s32 y, f32 z); /* x, y, z unused */
void func_800F8730_HandcarHavoc(omObjData* obj);
void func_800F8E00_HandcarHavoc(omObjData* obj);
u16 func_800F917C_HandcarHavoc(omObjData* obj);
void func_800F93DC_HandcarHavoc(omObjData* obj);
f32 func_800F9774_HandcarHavoc(s8 stk);
void func_800F9844_HandcarHavoc(omObjData* obj);
void func_800F9B54_HandcarHavoc(omObjData* obj);
void func_800F9DD8_HandcarHavoc(omObjData* obj);
void func_800FA210_HandcarHavoc(omObjData* obj);
void func_800FA318_HandcarHavoc(omObjData* obj);
void func_800FA3B8_HandcarHavoc(omObjData* obj);
void func_800FA8C0_HandcarHavoc(omObjData* obj);
void func_800FAE64_HandcarHavoc(omObjData* obj);
void func_800FAEE4_HandcarHavoc(omObjData* obj);
void func_800FAF64_HandcarHavoc(omObjData* obj);
void func_800FAF80_HandcarHavoc(omObjData* obj);
void func_800FAF9C_HandcarHavoc(omObjData* obj, u16 team);
void func_800FB0EC_HandcarHavoc(omObjData* obj);
void func_800FB5DC_HandcarHavoc(omObjData* obj);
void func_800FB7DC_HandcarHavoc(omObjData* obj);
void func_800FB7E4_HandcarHavoc(omObjData* obj);
void func_800FB81C_HandcarHavoc(omObjData* obj);
void func_800FB994_HandcarHavoc(omObjData* obj);
void func_800FBA80_HandcarHavoc(omObjData* obj);
void func_800FBB78_HandcarHavoc(omObjData* obj);
void func_800FBF5C_HandcarHavoc(omObjData* obj);
void func_800FBFA0_HandcarHavoc(f32* a, f32 step);
void func_800FC058_HandcarHavoc(void);
void func_800FC0C8_HandcarHavoc(u16 i, Vec* out);
void func_800FC124_HandcarHavoc(u16 i, Vec* out);
f32 func_800FC1B4_HandcarHavoc(u16 i);
f32 func_800FC22C_HandcarHavoc(f32 x, f32 y, f32 z, u16 i);
void func_800FC2A0_HandcarHavoc(u16 i, Vec* out);
void func_800FC338_HandcarHavoc(omObjData* obj, Vec* rot, Vec* pos);
u16 func_800FC4B0_HandcarHavoc(omObjData* obj);
f32 func_800FC7E0_HandcarHavoc(f32 x);
u16 func_800FC85C_HandcarHavoc(void);
void func_800FCA58_HandcarHavoc(omObjData* obj, u16 side);
void func_800FCBA4_HandcarHavoc(omObjData* obj);
void func_800FCCA4_HandcarHavoc(omObjData* obj);
void func_800FCE3C_HandcarHavoc(omObjData* obj);
void func_800FCFB4_HandcarHavoc(omObjData* obj);
void func_800FCFFC_HandcarHavoc(u16 time, u16* digit);

void func_800FD1B0_HandcarHavoc(omObjData* obj);
void func_800FD1E8_HandcarHavoc(s32 arg0);
void func_800FD204_HandcarHavoc(omObjData* obj);
f32 func_800FD464_HandcarHavoc(f32 x, f32 y, f32 z, HHColVtx* vtx, HHColFace* face);
void func_800FD59C_HandcarHavoc(omObjData* obj, u16 seat, Vec* out);
void func_800FD888_HandcarHavoc(omObjData* obj, u16 side, Vec* out);
void func_800FDBC8_HandcarHavoc(omObjData* obj);
u16 func_800FDCEC_HandcarHavoc(s16 mdl, u16 dir, f32 step);
void func_800FDE28_HandcarHavoc(void);
void func_800FDEC0_HandcarHavoc(u16 sprite, HHScroll* s, f32 u, f32 v);
void func_800FE004_HandcarHavoc(HHScroll* s);
void func_800FE8D4_HandcarHavoc(s32 team);
void func_800FEB4C_HandcarHavoc(s32 team, s32 i, s32 buf);
s16 func_800FECF4_HandcarHavoc(s32 team, s32 side, u16 wheel);
void func_800FF0AC_HandcarHavoc(HHCar* w);

/* .data */
extern s32 D_800FF3A0_HandcarHavoc[6];   /* map face sprite per character */
extern f32 D_800FF3B8_HandcarHavoc[2];   /* axle offsets */
extern u16 D_800FF3C0_HandcarHavoc[2][2]; /* sparks allowed per side and wheel */
extern f32 D_800FF3C8_HandcarHavoc[6];   /* seat offset per character */
extern u16 D_800FF3E0_HandcarHavoc;      /* rider jump-out state */
extern f32 D_800FF3E4_HandcarHavoc;
extern u16 D_800FF3E8_HandcarHavoc;
extern f32 D_800FF3EC_HandcarHavoc[5];   /* scroll targets per viewport */
extern u16 D_800FF400_HandcarHavoc;      /* 1: leave */
extern Vec D_800FF404_HandcarHavoc[4];   /* wheel spots per side */
extern f32 D_800FF434_HandcarHavoc[7];   /* spark lengths */

/* .bss */
extern Vec D_800FF580_HandcarHavoc[2];
extern Vec D_800FF598_HandcarHavoc[2];
extern f32 D_800FF5B0_HandcarHavoc[2];
extern f32 D_800FF5B8_HandcarHavoc[2];
extern f32 D_800FF5C0_HandcarHavoc[2];
extern f32 D_800FF5C8_HandcarHavoc;
extern HHCount D_800FF5CC_HandcarHavoc;
extern s16 D_800FF5D0_HandcarHavoc;      /* _CheckFlag(0x2B): story/board mode */
extern s16 D_800FF5D2_HandcarHavoc;
extern s16 D_800FF5D4_HandcarHavoc;
extern f32 D_800FF5D8_HandcarHavoc[2];
extern HHLightDir D_800FF5E0_HandcarHavoc;
extern f32 D_800FF5E8_HandcarHavoc;
extern s16 D_800FF5EC_HandcarHavoc;
extern u8 D_800FF5ED_HandcarHavoc;
extern s16 D_800FF5EE_HandcarHavoc;
extern u16 D_800FF5F0_HandcarHavoc;
extern u16 D_800FF5F2_HandcarHavoc[2];   /* "00mt037_DEF" (func_80039C48) */
extern f32 D_800FF5F8_HandcarHavoc;
extern f32 D_800FF5FC_HandcarHavoc;
extern f32 D_800FF600_HandcarHavoc;
extern f32 D_800FF604_HandcarHavoc;
extern s16 D_800FF608_HandcarHavoc;      /* track model */
extern HHColVtx* D_800FF60C_HandcarHavoc; /* track points */
extern s16 D_800FF610_HandcarHavoc;      /* track point count */
extern f32 D_800FF614_HandcarHavoc;      /* track length */
extern omObjData** D_800FF618_HandcarHavoc; /* the two cars */
extern omObjData** D_800FF61C_HandcarHavoc; /* the two cameras */
extern omObjData* D_800FF620_HandcarHavoc;
extern omObjData* D_800FF624_HandcarHavoc;
extern omObjData* D_800FF628_HandcarHavoc;
extern omObjData* D_800FF62C_HandcarHavoc; /* race timer */
extern HHScroll D_800FF630_HandcarHavoc[2];
extern Gfx* D_800FF690_HandcarHavoc[8];
extern s16 D_800FF6B0_HandcarHavoc;
extern Vtx* D_800FF6B8_HandcarHavoc[2][12][8];
extern Gfx* D_800FF9B8_HandcarHavoc[2][12][8];
extern HHSparks D_800FFCC0_HandcarHavoc[2][12];
extern s16 D_80101C40_HandcarHavoc[2][12];
extern s16 D_80101C88_HandcarHavoc;
extern u16 D_80101C8A_HandcarHavoc;      /* race state: 0 intro, 1 race, 2 over */
extern s16 D_80101C8E_HandcarHavoc;
extern s16 D_80101C90_HandcarHavoc;      /* winning team */
extern u16 D_80101CA0_HandcarHavoc;      /* cars fallen */
extern s16 D_80101CA2_HandcarHavoc;
extern u16 D_80101CA4_HandcarHavoc;
extern s16 D_80101CA6_HandcarHavoc;
extern u16 D_80101CA8_HandcarHavoc;      /* 1: new record */
extern u16 D_80101CAA_HandcarHavoc;      /* end state */
extern s16 D_80101CAC_HandcarHavoc;
extern s16 D_80101CAE_HandcarHavoc;

#endif
