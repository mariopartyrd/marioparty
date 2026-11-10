#ifndef TIGHTROPETREACHERY_H
#define TIGHTROPETREACHERY_H

/* ovl_1F TightropeTreachery (1 vs 3): declarations shared by its units (197E20, 19A360, 19ACC0,
   19D510). D_800FE8A0_TightropeTreachery[0] is the player of group 0 (the one on the rope),
   [1..3] the other three, in player order. */

#include "common.h"

/* A player object's work (func_80023684(0xE8)): src/99E0.c's MgWork layout; its pointers sit
   where MgWork's do (0xB8, 0xD8, 0xDC, 0xE4) so main code reads the same fields on the host. */
typedef struct TTPlayerWork {
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
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 angle; /* facing angle (degrees) */
    /* 0x40 */ f32 speed;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 radius;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ s8 unk_53;
    /* 0x54 */ s8 unk_54;
    /* 0x55 */ u8 unk_55;
    /* 0x56 */ s8 port;   /* controller port */
    /* 0x57 */ u8 unk_57;
    /* 0x58 */ s8 player; /* player index */
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
    /* 0x9C */ char unk_9C[4];
    /* 0xA0 */ f32 unk_A0;
    /* 0xA4 */ f32 unk_A4;
    /* 0xA8 */ char unk_A8[6];
    /* 0xAE */ u16 unk_AE; /* stun timer after a hit */
    /* 0xB0 */ char unk_B0;
    /* 0xB1 */ s8 unk_B1;
    /* 0xB2 */ s8 unk_B2;
    /* 0xB3 */ s8 unk_B3;
    /* 0xB4 */ char unk_B4[4];
    /* 0xB8 */ omObjData* unk_B8;
    /* 0xBC */ f32 unk_BC;
    /* 0xC0 */ u16 unk_C0;
    /* 0xC2 */ char unk_C2[0x16];
    /* 0xD8 */ s16 (*unk_D8)[2]; /* one pair per motion */
    /* 0xDC */ void* unk_DC;     /* collision callback */
    /* 0xE0 */ char unk_E0[4];
    /* 0xE4 */ void* unk_E4;
} TTPlayerWork; /* size = 0xE8 on the N64 */

#define TT_WORK(obj) ((TTPlayerWork*)(obj)->unk_50)

/* The water's and the rope's work (func_80023684(0x2C)): src/1130.c's GroundWork; no pointers. */
typedef struct TTGroundWork {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ char unk_02[2];
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ s8 unk_05;
    /* 0x06 */ char unk_06[0x26];
} TTGroundWork; /* size = 0x2C */

/* A start angle for a team member (D_800FE4D0_TightropeTreachery[4]). */
typedef struct TTSpot {
    /* 0x00 */ f32 angle;
    /* 0x04 */ s8 used;
} TTSpot; /* size = 0x8 */

/* func_80039C48's output: a texture's size. */
typedef struct TTTexSize {
    /* 0x00 */ u16 w;
    /* 0x02 */ u16 h;
} TTTexSize;

/* A bomb's state (D_800FE720_TightropeTreachery[3], TTItemWork::bomb). No pointers. */
typedef struct TTBomb {
    /* 0x00 */ s8 active; /* the team member pressed A */
    /* 0x01 */ s8 lit;    /* thrown */
    /* 0x02 */ u16 idx;   /* the team member (D_800FE700 index) */
    /* 0x04 */ u16 mdl[3]; /* 3D sprite ids (func_8001E00C): fuse, splash, explosion */
    /* 0x0A */ char unk_0A[2];
    /* 0x0C */ f32 ang;
    /* 0x10 */ f32 dir[3];
    /* 0x1C */ f32 pos[3];
    /* 0x28 */ f32 vy;
    /* 0x2C */ s32 timer;
    /* 0x30 */ f32 speed;
} TTBomb; /* size = 0x34 */

/* A team member's state (D_800FE7C8_TightropeTreachery[3], TTPlayerWork::unk_E4). No pointers. */
typedef struct TTTeamWork {
    /* 0x00 */ f32 push[2]; /* wind drift */
    /* 0x08 */ f32 angle;
    /* 0x0C */ f32 target;  /* CPU stick angle, < 0: none */
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 aim;     /* CPU aim error (degrees) */
    /* 0x1C */ s32 timer;
    /* 0x20 */ s32 straight; /* frames walked straight on */
    /* 0x24 */ u16 btn;     /* CPU buttons */
    /* 0x26 */ u16 prevBtn;
    /* 0x28 */ u16 idx;     /* 0..2 */
    /* 0x2A */ s16 flash;   /* stunned (hit by a bomb) */
    /* 0x2C */ u8 unk_2C[8];
    /* 0x34 */ u8 unk_34[8];
    /* 0x3C */ s8 port;
    /* 0x3D */ s8 player;
    /* 0x3E */ s8 unk_3E;
    /* 0x3F */ char unk_3F;
    /* 0x40 */ s8 sway;
    /* 0x41 */ s8 swayDir;
    /* 0x42 */ s8 noCtrl;
    /* 0x43 */ s8 hasSpot;
    /* 0x44 */ s8 spot;     /* D_800FE4D0_TightropeTreachery index */
    /* 0x45 */ s8 aimed;
    /* 0x46 */ s8 done;
} TTTeamWork; /* size = 0x48 */

/* A bomb object's work (func_80023684(0x6C)): main code's item view (src/1130.c) below 0x60, no
   pointers there; the bomb state pointer follows. */
typedef struct TTItemWork {
    /* 0x00 */ char unk_00[0x34];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ char unk_38[4];
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ char unk_40[4];
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ char unk_4C[6];
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ char unk_53;
    /* 0x54 */ u8 unk_54;
    /* 0x55 */ char unk_55[7];
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ s32 unk_60;
    /* 0x64 */ char unk_64[4];
    /* 0x68 */ TTBomb* bomb;
} TTItemWork; /* size = 0x6C on the N64 */

/* ---------------------------------------------------------------------------------------------
   Main code
   --------------------------------------------------------------------------------------------- */

extern omObjData* D_800F2AF8[];
extern omObjData* D_800EDE70[];
extern u16 D_800EE984;
extern u16 ContBtn[];
extern s8 ContStkY[];
extern u16 D_800F338C[];
extern f32 D_800B895C;
extern f32 D_800B8960;
extern f32 D_800B8964;
extern f32 D_800B8968;
extern f32 D_800B896C;
extern f32 D_800B8970;
extern f32 D_800B897C;
extern f32 D_800B8980;
extern f32 D_800B8984;
extern f32 D_800B8988;
extern f32 D_800B898C;
extern u16 D_800B89A4[][14];

void func_80008FDC(omObjData*, f32);
void func_80008FE8(omObjData*, f32);
void func_8000940C(omObjData*, f32, f32, f32);
void func_800093FC(omObjData*, f32, f32, f32);
void func_800090C4(omObjData* obj, u8 idx, u8 val);
void func_8001E268(s16, u8, u8);
void func_8001E2A8(s16, u16);
void func_800185A4(omObjData*, s32);
void GMesSprClose(void);
extern int guRandom(void);
void func_80060F04(s16, s16, s16, s16);
void func_800AF2E0(f32, f32*, f32*);
void func_80023A38(void* src, void* dst, s32 size);
void func_80025BB8(s16, s16);
void func_8006035C(s16, s8);
/* func_80009028 with its s32 argument given as a float: retail passed an f32 there (O32 puts it in
   a1); the host passes the same bits as the s32 the definition takes. */
#define FUNC_80009028_F(obj, y, x0, z0, x1, z1)                                                  \
    ((void (*)(omObjData*, f32, f32, f32, f32, f32))(void*)func_80009028)((obj), (y), (x0), (z0), (x1), (z1))

/* ---------------------------------------------------------------------------------------------
   Overlay functions
   --------------------------------------------------------------------------------------------- */

/* 197E20.c */
void func_800F65E0_TightropeTreachery(void);
void func_800F6BC8_TightropeTreachery(omObjData*);
s32 func_800F6C44_TightropeTreachery(omObjData*, omObjData*);
void func_800F6E80_TightropeTreachery(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z);
void func_800F7450_TightropeTreachery(omObjData*);
void func_800F7818_TightropeTreachery(omObjData*);
void func_800F83E0_TightropeTreachery(void);

/* 19A360.c */
void func_800F8B20_TightropeTreachery(f32 zoom, f32 rx, f32 ry, f32 rz, f32 cx, f32 cy, f32 cz);
void func_800F8BA0_TightropeTreachery(void);
void func_800F8CA8_TightropeTreachery(void);
void func_800F8D20_TightropeTreachery(omObjData*);
f32 func_800F8DA4_TightropeTreachery(void);
void func_800F8F70_TightropeTreachery(Vec3f* pos, Vec3f* axis, f32 angle, Mat4 m);
void func_800F9168_TightropeTreachery(TTPlayerWork*);
void func_800F9204_TightropeTreachery(omObjData*, f32);
void func_800F927C_TightropeTreachery(omObjData*, f32*, f32*);
s32 func_800F937C_TightropeTreachery(u32);
s32 func_800F9450_TightropeTreachery(void);

/* 19ACC0.c */
void func_800F9480_TightropeTreachery(s16 model);
void func_800F9508_TightropeTreachery(s16 model);
void func_800F9BA0_TightropeTreachery(void);
void func_800F9FD8_TightropeTreachery(omObjData*);
void func_800FA838_TightropeTreachery(s16 model, f32 u, f32 v, s32 w, s32 h, char* name);
void func_800FAAD8_TightropeTreachery(omObjData*);
void func_800FAE54_TightropeTreachery(omObjData*);
void func_800FAF34_TightropeTreachery(omObjData*);
void func_800FB150_TightropeTreachery(omObjData*);
void func_800FB170_TightropeTreachery(omObjData*);
f32 func_800FB2E0_TightropeTreachery(f32 dx, f32 dz);
void func_800FB360_TightropeTreachery(s16 model, s16 src, s16 arg2, f32 t);
void func_800FB3F4_TightropeTreachery(omObjData*);
void func_800FBAB4_TightropeTreachery(void);
void func_800FBBD0_TightropeTreachery(omObjData*);

/* 19D510.c */
s8 func_800FBCD0_TightropeTreachery(omObjData*);
void func_800FBDB8_TightropeTreachery(void);
void func_800FBF38_TightropeTreachery(omObjData*);
void func_800FC180_TightropeTreachery(omObjData*);
void func_800FC598_TightropeTreachery(omObjData*);
void func_800FC65C_TightropeTreachery(omObjData*);
void func_800FCCDC_TightropeTreachery(omObjData*);
void func_800FCCF8_TightropeTreachery(omObjData*);
void func_800FCD14_TightropeTreachery(omObjData*);
void func_800FCD30_TightropeTreachery(omObjData* obj, f32 dx, f32 dz);
void func_800FCEDC_TightropeTreachery(omObjData*);
void func_800FD70C_TightropeTreachery(omObjData*);
void func_800FDCE8_TightropeTreachery(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z, u16 idx);
void func_800FE040(omObjData*);
void func_800FE10C_TightropeTreachery(omObjData*);
void func_800FE1DC_TightropeTreachery(omObjData*);

/* ---------------------------------------------------------------------------------------------
   .data
   --------------------------------------------------------------------------------------------- */

/* 197E20.c */
extern s16 D_800FE2B0_TightropeTreachery;
extern s8 D_800FE2B2_TightropeTreachery;
extern s8 D_800FE2B3_TightropeTreachery;
extern s8 D_800FE2B4_TightropeTreachery;
extern s8 D_800FE2B5_TightropeTreachery;
extern s8 D_800FE2B6_TightropeTreachery;
extern s8 D_800FE2B7_TightropeTreachery;
extern f32 D_800FE2B8_TightropeTreachery;
extern s8 D_800FE2BC_TightropeTreachery;
extern s8 D_800FE2BD_TightropeTreachery;
extern s8 D_800FE2C0_TightropeTreachery;
extern s8 D_800FE2C1_TightropeTreachery;

/* 19A360.c */
extern s8 D_800FE300_TightropeTreachery;
extern s8 D_800FE301_TightropeTreachery;
extern s16 D_800FE302_TightropeTreachery;
extern f32 D_800FE304_TightropeTreachery;
extern s8 D_800FE328_TightropeTreachery;
extern s8 D_800FE32C_TightropeTreachery[8];
extern s8 D_800FE334_TightropeTreachery[8];
extern s8 D_800FE33C_TightropeTreachery;
extern u16 D_800FE33E_TightropeTreachery;
extern s32 D_800FE340_TightropeTreachery;

/* 19ACC0.c */
extern s8 D_800FE35C_TightropeTreachery;
extern s8 D_800FE35D_TightropeTreachery;
extern f32 D_800FE384_TightropeTreachery; /* x of the rope */
extern TTSpot D_800FE4D0_TightropeTreachery[4];
extern s8 D_800FE4F0_TightropeTreachery[4];
extern u16 D_800FE4F4_TightropeTreachery;
extern Vec3f D_800FE4A0_TightropeTreachery[4];
extern f32 D_800FE388_TightropeTreachery; /* y of the rope */

/* ---------------------------------------------------------------------------------------------
   .bss (0x800FE6A0..0x800FE8D0)
   --------------------------------------------------------------------------------------------- */

extern s16 D_800FE6A0_TightropeTreachery; /* the wind sound */
extern s16 D_800FE6E0_TightropeTreachery[8]; /* model / sprite caches of the bombs: [0] bomb, [1] shadow, [2..4] sprites */
extern s16 D_800FE6F0_TightropeTreachery[8]; /* [0] the team's model cache */
extern f32 D_800FE6A4_TightropeTreachery;
extern TTTexSize D_800FE6A8_TightropeTreachery;
extern unk2C0C0StructA0* D_800FE6AC_TightropeTreachery; /* the rope's base vertices */
extern u16 D_800FE6B0_TightropeTreachery[8];
extern s32 D_800FE6C0_TightropeTreachery[4];
extern s32 D_800FE6D0_TightropeTreachery[4];
extern omObjData* D_800FE700_TightropeTreachery[3]; /* the team */
extern f32 D_800FE70C_TightropeTreachery;
extern s16 D_800FE710_TightropeTreachery;
extern f32 D_800FE714_TightropeTreachery[3];
extern TTBomb D_800FE720_TightropeTreachery[3];
extern TTTeamWork D_800FE7C8_TightropeTreachery[3];

extern f32 D_800FE7C0_TightropeTreachery;
extern f32 D_800FE7C4_TightropeTreachery;
extern s8 D_800FE8A0_TightropeTreachery[4]; /* [0] the walker, [1..3] the team */
extern f32 D_800FE8A4_TightropeTreachery;
extern u8 D_800FE8AC_TightropeTreachery[4]; /* the team's start spots (shuffled) */
extern f32 D_800FE8A8_TightropeTreachery;
extern f32 D_800FE8B0_TightropeTreachery;
extern f32 D_800FE8B4_TightropeTreachery;
extern omObjData* D_800FE8B8_TightropeTreachery[3]; /* the bombs */
extern f32 D_800FE8C4_TightropeTreachery;

#endif
