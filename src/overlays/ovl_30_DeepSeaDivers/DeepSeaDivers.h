#ifndef DEEPSEADIVERS_H
#define DEEPSEADIVERS_H

/* ovl_30 DeepSeaDivers (2v2: per team a pumper on the boat and a diver on its rope). */

#include "common.h"
#include "PR/gu.h"
#include "sprite65770.h"

/* An object's extra work (HuMemDirectMalloc(0x60), kept in D_801017B0 and, on the N64, as a
   big-endian pointer in obj->work[0..3]; the host keeps the table index there). */
typedef struct DSDWork {
    /* 0x00 */ s16 unk0; /* flags; its low byte's 0x80: a treasure that is being carried */
    /* 0x02 */ u16 unk2; /* flags */
    /* 0x04 */ s16 unk4; /* half width */
    /* 0x06 */ s16 unk6; /* half height */
    /* 0x08 */ s16 unk8; /* state; < 0: gone */
    /* 0x0A */ s16 unkA; /* index in D_801017B0 */
    /* 0x0C */ s16 unkC; /* team */
    /* 0x0E */ s16 unkE;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
    /* 0x3C */ f32 unk3C;
    /* 0x40 */ s16 unk40;
    /* 0x42 */ s16 unk42;
    /* 0x44 */ s16 unk44; /* player */
    /* 0x46 */ s16 unk46;
    /* 0x48 */ s16 unk48;
    /* 0x4A */ s16 unk4A;
    /* 0x4C */ s16 unk4C;
    /* 0x4E */ s16 unk4E;
    /* 0x50 */ s16 unk50;
    /* 0x52 */ s16 unk52;
    /* 0x54 */ s16 unk54;
    /* 0x56 */ s16 unk56;
    /* 0x58 */ s16 unk58;
    /* 0x5A */ s16 unk5A;
    /* 0x5C */ s16 unk5C;
    /* 0x5E */ s16 unk5E;
} DSDWork; /* size = 0x60 */

/* The low byte of DSDWork.unk0 / DSDFx.flags, read by retail as a byte at offset 1. */
#define DSD_LO8(f) (((s8*)&(f))[1])

/* A player object's work (func_80023684(0xE8)): src/99E0.c's MgWork layout, the fields this
   overlay touches; its pointers sit where MgWork's do. */
typedef struct DSDPlayerWork {
    /* 0x00 */ char unk_00[0x3C];
    /* 0x3C */ f32 unk_3C; /* facing */
    /* 0x40 */ f32 unk_40; /* speed */
    /* 0x44 */ char unk_44[0xC];
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ char unk_53[3];
    /* 0x56 */ s8 unk_56; /* controller port */
    /* 0x57 */ u8 unk_57;
    /* 0x58 */ s8 unk_58; /* character */
    /* 0x59 */ char unk_59[0x55];
    /* 0xAE */ u16 unk_AE;
    /* 0xB0 */ char unk_B0[8];
    /* 0xB8 */ void* unk_B8;
    /* 0xBC */ char unk_BC[4];
    /* 0xC0 */ u16 unk_C0;
    /* 0xC2 */ char unk_C2[0x16];
    /* 0xD8 */ void* unk_D8;
    /* 0xDC */ void* unk_DC;
    /* 0xE0 */ char unk_E0[4];
    /* 0xE4 */ void* unk_E4;
} DSDPlayerWork; /* size = 0xE8 (N64) */

/* A team's two objects (D_80101780[2]). */
typedef struct DSDTeamObj {
    /* 0x00 */ omObjData* boat; /* the pumper (func_800F7968) */
    /* 0x04 */ omObjData* diver; /* func_800F8680 */
} DSDTeamObj;

/* A rope's ends (D_80100478[2]). */
typedef struct DSDRopeEnds {
    /* 0x00 */ Vec top;
    /* 0x0C */ Vec bottom;
} DSDRopeEnds;

/* A rope node (DSDRope.nodes[5], 0x20 each). */
typedef struct DSDRopeNode {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ f32 unk4; /* length */
    /* 0x08 */ Vec pos;
    /* 0x14 */ char pad14[0xC];
} DSDRopeNode;

/* A rope (D_80100610[4], stride 0x30). */
typedef struct DSDRope {
    /* 0x00 */ s16 active;
    /* 0x02 */ s16 model;
    /* 0x04 */ s16 n;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ f32 unk8; /* length */
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ Vec top;
    /* 0x20 */ Vec bottom;
    /* 0x2C */ DSDRopeNode* nodes;
} DSDRope;

/* A 2D effect (D_80100C80[64], stride 0x2C). */
typedef struct DSDFx {
    /* 0x00 */ s16 flags;
    /* 0x02 */ s16 type;
    /* 0x04 */ s16 sprite;
    /* 0x06 */ s16 target;
    /* 0x08 */ f32 x;
    /* 0x0C */ f32 y;
    /* 0x10 */ f32 z;
    /* 0x14 */ f32 sx;
    /* 0x18 */ f32 sy;
    /* 0x1C */ s16 timer;
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ s16 unk20;
    /* 0x22 */ s16 unk22;
    /* 0x24 */ s16 unk24;
    /* 0x26 */ s16 unk26;
    /* 0x28 */ s16 unk28;
    /* 0x2A */ s16 unk2A;
} DSDFx;

/* A treasure's placement (func_800F9AF4's table, in fifths). */
typedef struct DSDTreasureDef {
    /* 0x00 */ s16 scale;
    /* 0x02 */ s16 x;
    /* 0x04 */ s16 y;
    /* 0x06 */ s16 value;
} DSDTreasureDef;

/* A fish (D_801006D8[2]) and its recorded positions (D_80100758[2][10]), stride 0x40. */
typedef struct DSDFish {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec rot;
    /* 0x18 */ char pad18[0x18];
    /* 0x30 */ f32 vx;
    /* 0x34 */ char pad34[0xC];
} DSDFish;

/* A camera point to look at (D_80100508[16]). */
typedef struct DSDFocus {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
    /* 0x0C */ f32 w;
} DSDFocus;

/* Main code without a shared prototype. */
void func_800093FC(omObjData*, f32, f32, f32);
s16 func_80024198(s32, void*, s32);
void* func_80023668(s32);
s32 func_8002451C(s32, void*, s32);
s16 func_80064EF4(s32, s32);
void func_80067208(s16, s16, s16, u16);
void func_800674BC(s16, s16, s32);
void func_80066DF4(s16, s16, s16, f32, f32, f32);
void func_800670C4(s16, s16, s16, f32, f32, f32);
s32 func_80067328(s16, s16);
void func_800672DC(s16, s16, u16, s32);
f64 func_8009B618(f64, f64);
void func_80025BB8(s16, s16);
void func_8001D658(s16, Gfx**);
extern u16 D_800ED728;
s32 func_80009C90(omObjData*, s16, s16);
void func_80028498(s16, s16, s16);
void func_80060F04(s16, s16, s16, s16);
void func_80027E48(s16, f32, f32, u16, u16, char*, u8);
unk65770Anim* func_80067310(s16 animIdx); /* src/65770.c */
s16 func_80076FF4(s16);
extern s8 ContStkY[4];
extern u16 ContBtn[4];
extern omObjData* D_800F2AF8[];
s32 func_8000C144(void);

/* 218510.c */
void func_800F6B1C_DeepSeaDivers(omObjData*);
void func_800F6B48_DeepSeaDivers(void);
void func_800F6BDC_DeepSeaDivers(omObjData*);
void func_800F6F7C_DeepSeaDivers(void);
void func_800F7000_DeepSeaDivers(omObjData*);
void func_800F7074_DeepSeaDivers(omObjData*);
void func_800F70F4_DeepSeaDivers(omObjData*);
void func_800F72D0_DeepSeaDivers(omObjData*);
void func_800F72EC_DeepSeaDivers(void);
void func_800F7470_DeepSeaDivers(Gfx*, s16);
void func_800F791C_DeepSeaDivers(omObjData*);
void func_800F7968_DeepSeaDivers(omObjData*);
void func_800F7C9C_DeepSeaDivers(omObjData*);
void func_800F8680_DeepSeaDivers(omObjData*);
void func_800F88E0_DeepSeaDivers(omObjData*);
void func_800F9AF4_DeepSeaDivers(omObjData*);
void func_800F9DD8_DeepSeaDivers(omObjData*);
void func_800FA62C_DeepSeaDivers(s16);
void func_800FA9A4_DeepSeaDivers(s16);
void func_800FAABC_DeepSeaDivers(s16);
void func_800FAC68_DeepSeaDivers(s16);
void func_800FB010_DeepSeaDivers(s16);
s16 func_800FB130_DeepSeaDivers(void);
s32 func_800FB27C_DeepSeaDivers(omObjData*);
s16 func_800FB310_DeepSeaDivers(omObjData*);
void func_800FB860_DeepSeaDivers(void);
void func_800FB8C8_DeepSeaDivers(Matrix4f, f32, f32, f32, Vec*);
void func_800FB964_DeepSeaDivers(void);
void func_800FB984_DeepSeaDivers(void);
void func_800FBABC_DeepSeaDivers(void);
void func_800FBAC8_DeepSeaDivers(f32, f32, f32, f32);
void func_800FBB30_DeepSeaDivers(void);
DSDWork* func_800FC058_DeepSeaDivers(omObjData*);
void func_800FC148_DeepSeaDivers(void);
DSDWork* func_800FC1C8_DeepSeaDivers(omObjData*);
u32 func_800FC1F4_DeepSeaDivers(void);
void func_800FC22C_DeepSeaDivers(omObjData*, f32*, f32*, f32*);
void func_800FC2F8_DeepSeaDivers(f32*, f32*, f32, Vec2f*, s16, u16, f32*, f32*);
s16 func_800FC644_DeepSeaDivers(f32*, f32*, s16, u16, f32*, f32*);
f32 func_800FCAE8_DeepSeaDivers(f32, f32);
s16 func_800FCDC8_DeepSeaDivers(f32, f32, f32, f32);
void func_800FCF54_DeepSeaDivers(omObjData*, f32, f32);
s16 func_800FD28C_DeepSeaDivers(omObjData*);
s16 func_800FD450_DeepSeaDivers(s32);
void func_800FD494_DeepSeaDivers(void);
s16 func_800FD680_DeepSeaDivers(s16, f32, f32, f32, s16);
void func_800FD870_DeepSeaDivers(s16);
void func_800FD8C8_DeepSeaDivers(void);
void func_800FDBA0_DeepSeaDivers(void);
void func_800FDBC4_DeepSeaDivers(void);
s16 func_800FDBEC_DeepSeaDivers(void);
void func_800FDD84_DeepSeaDivers(s16);
void func_800FDE04_DeepSeaDivers(s16, f32, Vec*);
void func_800FDE44_DeepSeaDivers(s16, Vec*, Vec*);
void func_800FE170_DeepSeaDivers(s16, Vec*, Vec*);
s16 func_800FE2C0_DeepSeaDivers(s16);
void func_800FE378_DeepSeaDivers(Gfx**);
void func_800FEA00_DeepSeaDivers(omObjData*);
void func_800FEAC4_DeepSeaDivers(s16, s16);
void func_800FED88_DeepSeaDivers(omObjData*, s16);
void func_800FEF34_DeepSeaDivers(omObjData*);
void func_800FF6E0_DeepSeaDivers(omObjData*);
void func_800FF730_DeepSeaDivers(omObjData*);

/* .data */
extern s32 D_800FF960_DeepSeaDivers[2];
extern s16 D_800FF968_DeepSeaDivers[2];
extern s32 D_800FF96C_DeepSeaDivers[2];
extern Vec* D_800FFC80_DeepSeaDivers[9]; /* the sea floor's outlines */
extern s16 D_800FFCA4_DeepSeaDivers[14];
extern Gfx D_800FFDD0_DeepSeaDivers[];
extern Gfx D_800FFE10_DeepSeaDivers[];
extern f32 D_800FF974_DeepSeaDivers[4][2]; /* the diver's tilt (x, y) per quarter turn */
extern Vec D_800FF994_DeepSeaDivers[6]; /* the hook's offset in each character's hand */
extern s32 D_800FFE60_DeepSeaDivers[3];
extern s32 D_800FFE6C_DeepSeaDivers[5];

/* .bss */
extern s16 D_801003F0_DeepSeaDivers;
extern Gfx* D_801003F4_DeepSeaDivers;
extern Vtx* D_801003F8_DeepSeaDivers;
extern s16 D_801003FC_DeepSeaDivers;
extern s16 D_801003FE_DeepSeaDivers;
extern s16 D_80100400_DeepSeaDivers;
extern s16 D_80100402_DeepSeaDivers;
extern s16 D_80100404_DeepSeaDivers;
extern s16 D_80100406_DeepSeaDivers;
extern s16 D_80100408_DeepSeaDivers;
extern s16 D_8010040A_DeepSeaDivers;
extern s16 D_8010040C_DeepSeaDivers;
extern s16 D_8010040E_DeepSeaDivers;
extern s16 D_80100410_DeepSeaDivers; /* team 0's treasures */
extern DSDWork* D_80100418_DeepSeaDivers[8];
extern s16 D_80100438_DeepSeaDivers; /* team 1's */
extern DSDWork* D_80100440_DeepSeaDivers[8];
extern omObjData* D_80100460_DeepSeaDivers;
extern s16 D_80100464_DeepSeaDivers;
extern s16 D_80100466_DeepSeaDivers[2];
extern s16 D_8010046A_DeepSeaDivers[4]; /* players by team: [2t] the pumper, [2t + 1] the diver */
extern DSDRopeEnds D_80100478_DeepSeaDivers[2];
extern s16 D_801004A8_DeepSeaDivers[2];
extern s16 D_801004B0_DeepSeaDivers;
extern s16 D_801004B2_DeepSeaDivers;
extern s16 D_801004B4_DeepSeaDivers;
extern Vec D_801004B8_DeepSeaDivers;
extern Vec D_801004C4_DeepSeaDivers;
extern f32 D_801004D0_DeepSeaDivers;
extern Vec D_801004D4_DeepSeaDivers;
extern Vec D_801004E0_DeepSeaDivers;
extern Vec D_801004EC_DeepSeaDivers;
extern f32 D_801004F8_DeepSeaDivers;
extern Vec D_801004FC_DeepSeaDivers;
extern DSDFocus D_80100508_DeepSeaDivers[16];
extern DSDRope D_80100610_DeepSeaDivers[4];
extern DSDFish D_801006D8_DeepSeaDivers[2];
extern DSDFish D_80100758_DeepSeaDivers[2][10];
extern s16 D_80100C50_DeepSeaDivers;
extern f32 D_80100C54_DeepSeaDivers[2];
extern f32 D_80100C5C_DeepSeaDivers;
extern s16 D_80100C60_DeepSeaDivers[2];
extern f32 D_80100C64_DeepSeaDivers;
extern f32 D_80100C68_DeepSeaDivers;
extern s16 D_80100C70_DeepSeaDivers[3]; /* the sprite file; pumpers and divers made so far */
extern DSDFx D_80100C80_DeepSeaDivers[64];
extern DSDTeamObj D_80101780_DeepSeaDivers[2];
extern s16 D_80101790_DeepSeaDivers[3];
extern f32 D_80101798_DeepSeaDivers;
extern s16 D_8010179E_DeepSeaDivers;
extern s16 D_801017A0_DeepSeaDivers;
extern DSDWork* D_801017B0_DeepSeaDivers[256];
extern omObjData* D_80101BB0_DeepSeaDivers[8];
extern omObjData* D_80101BD0_DeepSeaDivers;
extern s16 D_80101BD4_DeepSeaDivers;

#endif
