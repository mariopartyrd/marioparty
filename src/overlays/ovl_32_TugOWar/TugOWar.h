#ifndef TUGOWAR_H
#define TUGOWAR_H

/* ovl_32 TugOWar: declarations shared by its units (22C9E0, 22D5F0, 231180, 231D40).
   Teams come from GwPlayer[i].group: D_800FDFAE_TugOWar[0] is the one player of group 0 (the
   solo side), [1..3] the other three, in player order. */

#include "common.h"

/* A coin flying from the pot (D_800FDE80_TugOWar[15]). */
typedef struct TWCoin {
    /* 0x00 */ s8 active;
    /* 0x01 */ s8 done;
    /* 0x02 */ char pad2[2];
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 z;
    /* 0x10 */ f32 vy;
} TWCoin; /* size = 0x14 */

/* A player's rope position (TWPlayerWork::unk_E4, 0x28 bytes). No pointers. */
typedef struct TWPull {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 z;
    /* 0x10 */ f32 dx;
    /* 0x14 */ f32 dy;
    /* 0x18 */ f32 dz;
    /* 0x1C */ f32 angle; /* last stick angle */
    /* 0x20 */ f32 pull;  /* this frame's pull strength */
    /* 0x24 */ u16 timer;
    /* 0x26 */ char pad26[2];
} TWPull; /* size = 0x28 */

/* A player object's work (func_80023684(0xE8)): src/99E0.c's MgWork layout, the fields this
   overlay touches; its pointers sit where MgWork's do. */
typedef struct TWPlayerWork {
    /* 0x00 */ char unk_00[0x38];
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ char unk_3C[0x14];
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ char unk_53[3];
    /* 0x56 */ s8 unk_56; /* controller port */
    /* 0x57 */ u8 unk_57;
    /* 0x58 */ s8 unk_58; /* player */
    /* 0x59 */ char unk_59[0x4B];
    /* 0xA4 */ f32 unk_A4;
    /* 0xA8 */ char unk_A8[0x10];
    /* 0xB8 */ void* unk_B8;
    /* 0xBC */ char unk_BC[4];
    /* 0xC0 */ u16 unk_C0;
    /* 0xC2 */ char unk_C2[0x16];
    /* 0xD8 */ void* unk_D8;
    /* 0xDC */ void* unk_DC;
    /* 0xE0 */ char unk_E0[4];
    /* 0xE4 */ TWPull* unk_E4;
} TWPlayerWork; /* size = 0xE8 (N64) */

/* Main code without a shared prototype. */
void func_80060F04(s16, s16, s16, s16);
void func_80028C64(s16, u8, u8, u8, u8);
void func_800093FC(omObjData*, f32, f32, f32);
void func_8000940C(omObjData*, f32, f32, f32);
void func_80008FDC(omObjData*, f32);
void func_80008FE8(omObjData*, f32);
void func_800090C4(omObjData* obj, u8 idx, u8 val);
void func_80025BB8(s16, s16);
void func_80020EA0(s16, char*, s16, char*);
struct unk65770Anim* func_80067310(s16 animIdx); /* src/65770.c */
f32 func_80025D18(s16);
f32 func_80025D40(s16);
s16 func_80024198(u32, Gfx*, s32); /* src/24740.c */
u16 func_8001E1D0(s16 index, s32 arg1);
void GMesSprClose(void);
void func_8006073C(void);
extern u8 D_800F64F8;
extern s8 ContStkY[];
int guRandom(void);
extern u16 D_800EE984;
extern u8 D_800C3000; /* src/engine/ovlman.c */
extern u8 D_800C3001;
extern omObjData* D_800F2AF8[]; /* D_800ED440 entries */

/* 22C9E0.c */
void func_800F65E0_TugOWar(void);
void func_800F69C0_TugOWar(omObjData*);

/* 22D5F0.c */
s16 func_800F71F0_TugOWar(s16, s16);
s16 func_800F731C_TugOWar(s16, s16);
void func_800F73F4_TugOWar(void);
void func_800F751C_TugOWar(void);
void func_800F7604_TugOWar(void);
s8 func_800F77EC_TugOWar(omObjData* rope);
void func_800F851C_TugOWar(omObjData*);
void func_800F8DA0_TugOWar(omObjData*);
void func_800F95D4_TugOWar(omObjData*);
void func_800F9688_TugOWar(omObjData*);
void func_800F9A90_TugOWar(omObjData*);
void func_800F9E34_TugOWar(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z);
void func_800FA1F4_TugOWar(omObjData*);
void func_800FA284_TugOWar(omObjData*);
void func_800FA700_TugOWar(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z);
void func_800FAA78_TugOWar(omObjData*);
void func_800FAB08_TugOWar(omObjData*);
void func_800FAB98_TugOWar(omObjData*);
void func_800FAC28_TugOWar(void);

/* 231180.c */
void func_800FAD80_TugOWar(f32 zoom, f32 rx, f32 ry, f32 rz, f32 cx, f32 cy, f32 cz);
void func_800FADC0_TugOWar(omObjData*);
u16 func_800FAE4C_TugOWar(s32 file);
void func_800FAE90_TugOWar(Gfx* gfx, s32 anim, s32 frame, s32 x, s32 y, s32 phase, s32 band, f32 amp, s32 step,
                           s32 strips, f32 scale);
void func_800FB718_TugOWar(s16 dst, s16 src, s16 arg2, f32 arg3);
f32 func_800FB7AC_TugOWar(s8 port);
void func_800FB8A4_TugOWar(s16 model, s16 motion, s16 start, s16 end, u16 attr, u16 shift);

/* 231D40.c */
void func_800FB940_TugOWar(omObjData* obj, u8 idx);
void func_800FBF18_TugOWar(omObjData* obj, f32 x, f32 z, s16 delay, u8 dir, u8 idx);
void func_800FC710_TugOWar(omObjData*);
void func_800FCB8C_TugOWar(omObjData*);
void func_800FCF10_TugOWar(omObjData*);
void func_800FD758_TugOWar(omObjData*);
void func_800FDA4C_TugOWar(void);

/* .data */
extern s8 D_800FDAE0_TugOWar[2]; /* [0] the game is over, [1] the result is being shown */
extern s8 D_800FDAE2_TugOWar;
extern s32 D_800FDAE4_TugOWar;
extern s32 D_800FDB10_TugOWar;
extern s8 D_800FDB15_TugOWar; /* the result sequence is done */
extern s8 D_800FDB16_TugOWar; /* winner: 0 the solo player, 1 the team, 2 a draw (time up) */
extern s32 D_800FDB94_TugOWar;
extern f32 D_800FDBE0_TugOWar;
extern s8 D_800FDBE4_TugOWar;
extern s8 D_800FDBE5_TugOWar;
extern s8 D_800FDBE6_TugOWar;

/* .bss (0x800FDDE0..0x800FDFC0) */
extern f32 D_800FDDE0_TugOWar[3];
extern f32 D_800FDDF0_TugOWar;
extern f32 D_800FDDF4_TugOWar;
extern f32 D_800FDDF8_TugOWar;
extern f32 D_800FDDFC_TugOWar;
extern f32 D_800FDE00_TugOWar[4];
extern f32 D_800FDE10_TugOWar[4];
extern s8 D_800FDE20_TugOWar; /* the bird's direction */
extern f32 D_800FDE24_TugOWar;
extern f32 D_800FDE28_TugOWar;
extern f32 D_800FDE2C_TugOWar;
extern f32 D_800FDE30_TugOWar;
extern f32 D_800FDE34_TugOWar;
extern f32 D_800FDE38_TugOWar;
extern s8 D_800FDE3C_TugOWar[2];
extern s8 D_800FDE3E_TugOWar[2];
extern s32 D_800FDE40_TugOWar[2];
extern f32 D_800FDE48_TugOWar[2];
extern f32 D_800FDE50_TugOWar[2];
extern f32 D_800FDE58_TugOWar[2];
extern f32 D_800FDE60_TugOWar[2];
extern f32 D_800FDE68_TugOWar[2];
extern f32 D_800FDE70_TugOWar[2];
extern Gfx* D_800FDE78_TugOWar; /* 0x1000-byte (N64) display-list buffer */
extern s16 D_800FDE7C_TugOWar;
extern u16 D_800FDE7E_TugOWar;
extern TWCoin D_800FDE80_TugOWar[15];
extern s16 D_800FDFAC_TugOWar;
extern s8 D_800FDFAE_TugOWar[4]; /* [0] the solo player, [1..3] the team of three */
extern s8 D_800FDFB2_TugOWar;
extern s8 D_800FDFB3_TugOWar;
extern s16 D_800FDFB4_TugOWar;

#endif
