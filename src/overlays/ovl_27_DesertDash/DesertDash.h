#ifndef DESERTDASH_H
#define DESERTDASH_H

/* ovl_27 DesertDash: declarations shared by its units (1D3990, 1D6E30).
   Types come from the asm's accesses; N64 offsets are in the comments. Structs that hold pointers
   are only reached through their fields (the host strides pointers 8 bytes). */

#include "common.h"
#include "sprite65770.h"

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* One team of two (D_800FC318[2]): the pair pulls one shared sled. */
typedef struct DDTeam {
    /* 0x00 */ omObjData* obj[2]; /* the two players' objects */
    /* 0x08 */ s8 unk8;           /* both players' input flags (bit per member; 3 = both) */
    /* 0x09 */ u8 player[2];      /* player index of each member */
    /* 0x0B */ u8 unkB[2];        /* character byte (D_800C59A9) of each member */
    /* 0x0E */ s16 unkE;          /* model */
    /* 0x10 */ s16 unk10;         /* model (func_80023FC8 copy) */
    /* 0x12 */ s16 unk12;         /* shadow model */
    /* 0x14 */ u16 unk14;         /* state */
    /* 0x16 */ u16 unk16;         /* obstacle ahead (func_800F8A80) */
    /* 0x18 */ s16 unk18;         /* state timer */
    /* 0x1A */ s16 unk1A;
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ char unk1E[0xA];
    /* 0x28 */ f32 unk28;         /* sled z: the members' mean */
    /* 0x2C */ char unk2C[8];
    /* 0x34 */ f32 unk34;         /* speed factor */
    /* 0x38 */ char unk38[0x14];
} DDTeam; /* size = 0x4C (N64) */

/* The player object's work (func_80023684(0xE8)): src/99E0.c's MgWork layout with the fields this
   overlay touches; its pointers sit where MgWork's do. */
typedef struct DDPlayerWork {
    /* 0x00 */ char unk_00[0x56];
    /* 0x56 */ s8 unk_56; /* controller port */
    /* 0x57 */ char unk_57;
    /* 0x58 */ s8 unk_58; /* player index */
    /* 0x59 */ char unk_59[0x5F];
    /* 0xB8 */ void* unk_B8;
    /* 0xBC */ char unk_BC[4];
    /* 0xC0 */ u16 unk_C0;
    /* 0xC2 */ char unk_C2[0x16];
    /* 0xD8 */ void* unk_D8;
    /* 0xDC */ void* unk_DC;
    /* 0xE0 */ char unk_E0[4];
    /* 0xE4 */ void* unk_E4;
} DDPlayerWork; /* size = 0xE8 (N64) */

/* objmain.c's per-character entries (D_800C59A8[6]); retail reads index's low byte (D_800C59A9). */
typedef struct DDChr {
    /* 0x00 */ s16 index;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s16 chr;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ s32 file0;
    /* 0x0C */ s32 file1;
    /* 0x10 */ f32 scale;
} DDChr; /* size = 0x14 */

/* An obstacle on the course (D_800FC670[5]): a block that rises and slams down. No pointers. */
typedef struct DDObstacle {
    /* 0x00 */ s16 unk0;  /* active */
    /* 0x02 */ s16 unk2;  /* held up (cleared at random frames) */
    /* 0x04 */ s16 unk4;  /* phase: 0 rising, 1 falling, 2 down, 3 up */
    /* 0x06 */ s16 unk6;  /* model */
    /* 0x08 */ s16 unk8;  /* shadow model */
    /* 0x0A */ s16 unkA;  /* dust model */
    /* 0x0C */ f32 unkC;  /* phase timer */
    /* 0x10 */ f32 unk10; /* height */
    /* 0x14 */ f32 unk14; /* z */
} DDObstacle; /* size = 0x18 */

/* A scenery model's position (D_800FC4F8[16]). */
typedef struct DDScenery {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ u16 unk2; /* model kind 0..2 */
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 z;
} DDScenery; /* size = 0x10 */

/* A team's banner sprite (D_800FC620[2]). No pointers. */
typedef struct DDBanner {
    /* 0x00 */ f32 unk0;  /* y */
    /* 0x04 */ f32 unk4;  /* y step */
    /* 0x08 */ f32 unk8;  /* frames left */
    /* 0x0C */ f32 unkC;  /* x */
    /* 0x10 */ f32 unk10; /* x scale */
    /* 0x14 */ f32 unk14; /* y scale */
} DDBanner; /* size = 0x18 */

/* ---------------------------------------------------------------------------------------------
   Data (.data)
   --------------------------------------------------------------------------------------------- */
/* 1D3990 */
extern s32 D_800FC000_DesertDash; /* game state */
extern s32 D_800FC004_DesertDash; /* obstacle count; 1D6E30 reads its low half (D_800FC006) */
extern s32 D_800FC008_DesertDash;
extern s32 D_800FC00C_DesertDash;
extern s32 D_800FC014_DesertDash;
extern s32 D_800FC018_DesertDash;
extern s32 D_800FC01C_DesertDash;
extern u8 D_800FC020_DesertDash; /* bit per team at the goal */
/* 1D6E30 */
extern u32 D_800FC030_DesertDash; /* random seed; func_800FA1A0 reads its low half */
extern u32 D_800FC034_DesertDash;
extern u32 D_800FC038_DesertDash;
extern s16 D_800FC03C_DesertDash;
extern s16 D_800FC03E_DesertDash;
extern s16 D_800FC040_DesertDash;
extern s16 D_800FC042_DesertDash;
extern f64 D_800FC048_DesertDash;

/* ---------------------------------------------------------------------------------------------
   Bss (asm; link-map names)
   --------------------------------------------------------------------------------------------- */
extern s32 D_800FC2E0_DesertDash[2];
extern s32 D_800FC2E8_DesertDash[2];
extern s32 D_800FC2F0_DesertDash[2]; /* player sprite ids; read as s16 (D_800FC2F2, +6) */
extern omObjData* D_800FC2F8_DesertDash;
extern omObjData* D_800FC2FC_DesertDash;
extern s32 D_800FC300_DesertDash;
extern s32 D_800FC308_DesertDash[4];
extern DDTeam D_800FC318_DesertDash[2];
extern s16 D_800FC3B0_DesertDash;
extern s16 D_800FC3B2_DesertDash;
extern s32 D_800FC3B4_DesertDash; /* sprite group, read as s16 (D_800FC3B6) */
extern s32 D_800FC3B8_DesertDash; /* sprite group, read as s16 (D_800FC3BA) */
extern s32 D_800FC3C0_DesertDash[4]; /* team * 2 + member slot of each player */
extern s32 D_800FC3D0_DesertDash;
extern s32 D_800FC3D4_DesertDash;
/* Camera tweening (func_800F94F8 .. func_800F983C), per screen. */
extern Vec3f D_800FC3D8_DesertDash[4]; /* start CenterM */
extern Vec3f D_800FC408_DesertDash[4]; /* target CenterM */
extern Vec3f D_800FC438_DesertDash[4]; /* start CRotM */
extern Vec3f D_800FC468_DesertDash[4]; /* target CRotM */
extern f32 D_800FC498_DesertDash[4];   /* start CZoomM */
extern f32 D_800FC4A8_DesertDash[4];   /* target CZoomM */
extern s16 D_800FC4B8_DesertDash[4];   /* frames left */
extern s16 D_800FC4C0_DesertDash[8];   /* frames total */
extern u16 D_800FC4D0_DesertDash[8];
extern omObjData* D_800FC4E0_DesertDash[3]; /* the two track objects and the scenery object */
extern DDScenery D_800FC4F8_DesertDash[16];
extern s16 D_800FC5F8_DesertDash[3];   /* sprite animations */
extern s16 D_800FC5FE_DesertDash[2];   /* per-team sprite groups */
extern s16 D_800FC602_DesertDash[2]; /* [0] the start banner's group, [1] the team markers' (D_800FC604) */
extern Gfx* D_800FC608_DesertDash[2];  /* per-team banner display lists */
extern s16 D_800FC614_DesertDash[2];   /* their models */
extern DDBanner D_800FC620_DesertDash[2];
extern s16 D_800FC650_DesertDash;
extern s16 D_800FC652_DesertDash;
extern s16 D_800FC654_DesertDash;
extern f64 D_800FC658_DesertDash[2];   /* each team's z */
extern DDObstacle D_800FC670_DesertDash[5];

/* ---------------------------------------------------------------------------------------------
   Main code
   --------------------------------------------------------------------------------------------- */
extern Vec3f CenterM[];
extern Vec3f CRotM[];
extern f32 CZoomM[];
extern omObjData* D_800F2AF8[];
extern u16 D_800EE984;
extern DDChr D_800C59A8[];
extern s8 ContStkY[4];
void omOutViewMulti(omObjData* obj);

void func_80008EF0(omObjData* obj, u16 idx, s32 dir, s32 file, f32 arg4);
void func_800093FC(omObjData*, f32, f32, f32);
void func_80017940(s32);
u16 func_80017A50(omObjData* obj);
s32 func_80017A60(omObjData* obj);
void func_80017C0C(omObjData*, u8, f32, f32, f32, f32, f32);
f32 func_80025D18(s16);
f32 func_80025D40(s16);
void func_8006035C(s16, s8);
void func_800607C4(s16, s16);
void func_80060F04(s16, s16, s16, s16);
void func_80066DF4(s16 grpIdx, s16 idx, s16 camIdx, f32 x, f32 y, f32 z);
/* src/65770.c defines arg4/arg5 as u16; retail called it with s16 (sign-extended) values. */
void func_8006761C(s16 grpIdx, s16 idx, s16 arg2, s16 arg3, s16 arg4, s16 arg5);
void omInitObjMan(s32 maxObjects, s32 maxProcesses);
s16 func_80024198(u32, Gfx*, s32); /* src/24740.c */
unk65770Anim* func_80067310(s16 animIdx);
f32 func_800AEAC0(f32);
extern unk65770Anim* D_800EC700[256]; /* src/65770.c */
extern u8 D_800F64F8;

/* ---------------------------------------------------------------------------------------------
   Overlay functions
   --------------------------------------------------------------------------------------------- */
/* 1D3990 */
void func_800F65E0_DesertDash(void);
void func_800F6A9C_DesertDash(omObjData* obj);
void func_800F6B38_DesertDash(omObjData* obj);
void func_800F6E00_DesertDash(omObjData* obj);
void func_800F6E34_DesertDash(omObjData* obj);
void func_800F6E68_DesertDash(omObjData* obj);
void func_800F6E9C_DesertDash(omObjData* obj);
void func_800F6ED0_DesertDash(omObjData* obj);
void func_800F6F04_DesertDash(omObjData* obj, s32 player);
void func_800F707C_DesertDash(omObjData* obj, s32 player);
void func_800F7430_DesertDash(omObjData* obj);
void func_800F7C6C_DesertDash(omObjData* obj);
u16 func_800F8A80_DesertDash(f32 z);
void func_800F8C34_DesertDash(omObjData* obj);
void func_800F91C8_DesertDash(omObjData* obj, s16* stkX, s16* stkY);
void func_800F9434_DesertDash(void);
void func_800F9450_DesertDash(omObjData* obj, DDTeam* team);
DDTeam* func_800F9470_DesertDash(omObjData* obj);
void func_800F949C_DesertDash(omObjData* obj, s32 motion, f32 speed);
void func_800F94F8_DesertDash(s32 cam, f32 zoom, f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz);
void func_800F95E8_DesertDash(s32 cam, f32 zoom, f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz,
                              u16 frames);
void func_800F96C4_DesertDash(s32 cam);
void func_800F9780_DesertDash(s32 cam);
s32 func_800F983C_DesertDash(omObjData* obj, s32 count);
/* 1D6E30 */
void func_800F9A80_DesertDash(omObjData* obj);
void func_800F9B2C_DesertDash(omObjData* obj);
void func_800F9C68_DesertDash(void);
void func_800F9C9C_DesertDash(s16 x);
u16 func_800FA1A0_DesertDash(u16 range);
void func_800FA210_DesertDash(u8 seed);
s16 func_800FAD98_DesertDash(u16 team, f32 z);
void func_800FAE1C_DesertDash(u16 team, f32 frames);
u16 func_800FA258_DesertDash(s32 file);
void func_800FA29C_DesertDash(void);
void func_800FA234_DesertDash(DDObstacle* o);
void func_800FA460_DesertDash(omObjData* obj);
void func_800FA724_DesertDash(omObjData* obj);
void func_800FA9E0_DesertDash(omObjData* obj);
void func_800FACD0_DesertDash(omObjData* obj);
void func_800FAE60_DesertDash(void);
void func_800FAFD4_DesertDash(void);
void func_800FB3F8_DesertDash(u16 n);
void func_800FB4F8_DesertDash(u16 team, f32 z);
void func_800FB610_DesertDash(s16 mdl);
void func_800FB6B8_DesertDash(void);
void func_800FB750_DesertDash(Gfx** buf, s16 anim, s32 frame, s32 x, s32 y, s32 phase, s32 rows, f32 amp, s32 step,
                              s32 strips, f32 sx, f32 sy);

#endif
