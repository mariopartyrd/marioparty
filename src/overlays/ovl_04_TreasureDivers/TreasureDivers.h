#ifndef TREASUREDIVERS_H
#define TREASUREDIVERS_H

/* ovl_04 TreasureDivers: declarations shared by its units (EE9A0, F2800, F4420). */

#include "common.h"
#include "PR/gu.h"
#include "sprite65770.h"

/* A point of the sea-floor outline (D_800FE774), screen coordinates. */
typedef struct TDPoint {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
} TDPoint;

typedef struct TDVec2 {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
} TDVec2;

/* An object's extra work (HuMemDirectMalloc(0x5C), kept in D_800FED40 and in obj->work[0..3]):
   the divers' (EE9A0 func_800F78D8) and the treasures' (func_800F8B98). */
typedef struct TDWork {
    /* 0x00 */ s16 unk0; /* flags; (s8)unk0 < 0: takes part in collisions */
    /* 0x02 */ u16 unk2; /* flags */
    /* 0x04 */ s16 unk4; /* half width */
    /* 0x06 */ s16 unk6; /* half height */
    /* 0x08 */ s16 unk8; /* state */
    /* 0x0A */ s16 unkA; /* index in D_800FED40 */
    /* 0x0C */ Vec pos;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
    /* 0x3C */ s16 unk3C;
    /* 0x3E */ s16 unk3E;
    /* 0x40 */ s16 unk40; /* player */
    /* 0x42 */ s16 unk42;
    /* 0x44 */ u16 unk44;
    /* 0x46 */ s16 unk46;
    /* 0x48 */ s16 unk48;
    /* 0x4A */ u16 unk4A;
    /* 0x4C */ s16 unk4C;
    /* 0x4E */ s16 unk4E;
    /* 0x50 */ s16 unk50;
    /* 0x52 */ s16 unk52;
    /* 0x54 */ s16 unk54;
    /* 0x56 */ u16 unk56;
    /* 0x58 */ s16 unk58;
    /* 0x5A */ s16 unk5A;
} TDWork; /* size = 0x5C */

/* A player object's work (func_80023684(0xE8)): src/99E0.c's MgWork layout, the fields this
   overlay touches; its pointers sit where MgWork's do. */
typedef struct TDPlayerWork {
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
} TDPlayerWork; /* size = 0xE8 (N64) */

/* A moving 3D object with a screen box: the boats (D_800FF188[3], [2] the treasure boat) and the
   fish (D_800FFA60[2]); stride 0x40. */
typedef struct TDBoat {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2; /* half width (screen) */
    /* 0x04 */ s16 unk4; /* half height (screen) */
    /* 0x06 */ char pad6[2];
    /* 0x08 */ Vec pos;
    /* 0x14 */ Vec rot;
    /* 0x20 */ TDVec2 scr;
    /* 0x28 */ char pad28[4];
    /* 0x2C */ TDVec2 oldScr;
    /* 0x34 */ char pad34[4];
    /* 0x38 */ f32 vx;
    /* 0x3C */ s32 active;
} TDBoat; /* size = 0x40 */

/* A fish's recorded position (D_800FE7C8[2][10]; retail's records start 8 bytes earlier, at
   0x800FE7C0, with the TDBoat layout). */
typedef struct TDTrail {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec rot;
    /* 0x18 */ char pad18[0x28];
} TDTrail; /* size = 0x40 */

/* A 2D effect (D_800FF260[64]). */
typedef struct TDFx {
    /* 0x00 */ s16 active; /* 0 free; 0x8000 set once started */
    /* 0x02 */ s16 type;
    /* 0x04 */ s16 sprite;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ f32 x;
    /* 0x0C */ f32 y;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ s16 unk12;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ s16 unk18;
    /* 0x1A */ s16 unk1A;
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ s16 unk1E;
} TDFx; /* size = 0x20 */

/* Sprite file handles (D_800FED00). */
typedef struct TDSprites {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
} TDSprites;

/* Main code without a shared prototype. */
s32 func_80009C90(omObjData*, s16, s16);
s32 func_80017A60(omObjData*);
void func_80017DB0(omObjData*);
void func_80028498(s16, s16, s16);
f64 func_8009B6F0(f64);
void func_80060F04(s16, s16, s16, s16);
extern u16 ContBtn[4];
extern s8 ContStkY[4];
unk65770Anim* func_80067310(s16 animIdx); /* src/65770.c */
s16 func_80076FF4(s16);
extern u8 D_800F64F8;
void guMtxL2F(Matrix4f, Mtx*);

/* EE9A0.c */
void func_800F6B2C_TreasureDivers(omObjData*);
void func_800F6F18_TreasureDivers(omObjData*);
void func_800F7010_TreasureDivers(omObjData*);
void func_800F719C_TreasureDivers(omObjData*);
void func_800F7470_TreasureDivers(omObjData*);
void func_800F74E8_TreasureDivers(omObjData*);
void func_800F7560_TreasureDivers(omObjData*);
void func_800F75AC_TreasureDivers(omObjData*);
void func_800F92A0_TreasureDivers(s16);
void func_800F9580_TreasureDivers(s16);
void func_800F9668_TreasureDivers(s16);
void func_800F9728_TreasureDivers(s16);
void func_800F98B8_TreasureDivers(s16);
void func_800F9BAC_TreasureDivers(s16);
s16 func_800F9CB0_TreasureDivers(void);

/* F2800.c */
void func_800FA440_TreasureDivers(void);
TDWork* func_800FA4A8_TreasureDivers(omObjData*);
void func_800FA594_TreasureDivers(void);
TDWork* func_800FA614_TreasureDivers(omObjData*);
u32 func_800FA640_TreasureDivers(void);
void func_800FA678_TreasureDivers(Matrix4f);
void func_800FA7E8_TreasureDivers(Vec*, Vec*);
void func_800FA8B8_TreasureDivers(f32, f32, f32, Vec*);
void func_800FA984_TreasureDivers(s32, f32*, f32*, f32*);
void func_800FAA34_TreasureDivers(u8*);
void func_800FABD0_TreasureDivers(void);
s32 func_800FABFC_TreasureDivers(f32*, f32*, s16);
s16 func_800FB1D4_TreasureDivers(f32);
s16 func_800FB3A8_TreasureDivers(f32, f32, f32, f32);
s16 func_800FB528_TreasureDivers(TDWork*);
s16 func_800FB620_TreasureDivers(TDWork*, f32);
void func_800FB79C_TreasureDivers(TDWork*, f32, f32);
s16 func_800FBAC8_TreasureDivers(s32);
void func_800FBB0C_TreasureDivers(void);
s16 func_800FBD10_TreasureDivers(s16, f32, f32, s16);
void func_800FBE84_TreasureDivers(s16);
void func_800FBEC8_TreasureDivers(void);

/* F4420.c */
void func_800FC060_TreasureDivers(s32);
void func_800FC074_TreasureDivers(s32);
void func_800FC144_TreasureDivers(omObjData*);
void func_800FC1CC_TreasureDivers(omObjData*);
void func_800FC6AC_TreasureDivers(void);
void func_800FC6B8_TreasureDivers(void);
void func_800FC70C_TreasureDivers(omObjData*);
void func_800FC770_TreasureDivers(omObjData*);
s32 func_800FCA70_TreasureDivers(s32, s32, s32);
u16 func_800FCAF0_TreasureDivers(u32);
void func_800FCB58_TreasureDivers(omObjData*);
void func_800FCB90_TreasureDivers(omObjData*);
void func_800FCC24_TreasureDivers(omObjData*, s16);
void func_800FCF5C_TreasureDivers(omObjData*);
void func_800FD00C_TreasureDivers(omObjData*);
void func_800FD934_TreasureDivers(omObjData*);
void func_800FD96C_TreasureDivers(omObjData*);
void func_800FD98C_TreasureDivers(s16);
void func_800FDEB4_TreasureDivers(s16);
void func_800FE368_TreasureDivers(void);

/* .data (EE9A0.c) */
extern s32 D_800FE430_TreasureDivers;
extern s32 D_800FE434_TreasureDivers;
extern u32 D_800FE438_TreasureDivers; /* the seed */
extern u16 D_800FE43A_TreasureDivers; /* the seed's low half (a split label) */
extern s32 D_800FE43C_TreasureDivers;
extern s32 D_800FE440_TreasureDivers;
extern s32 D_800FE444_TreasureDivers[3];
extern s32 D_800FE450_TreasureDivers[3];
extern f32 D_800FE45C_TreasureDivers;
extern f32 D_800FE460_TreasureDivers;
extern f32 D_800FE464_TreasureDivers;

/* .bss */
extern s16 D_800FE6F0_TreasureDivers;
extern s16 D_800FE6F2_TreasureDivers;
extern s16 D_800FE6F4_TreasureDivers;
extern s16 D_800FE6F6_TreasureDivers;
extern s16 D_800FE6F8_TreasureDivers;
extern s16 D_800FE6FA_TreasureDivers;
extern s16 D_800FE6FC_TreasureDivers;
extern s16 D_800FE6FE_TreasureDivers;
extern s16 D_800FE700_TreasureDivers;
extern s16 D_800FE702_TreasureDivers;
extern u16 D_800FE704_TreasureDivers;
extern TDWork* D_800FE708_TreasureDivers[10]; /* the free treasures */
extern u16 D_800FE730_TreasureDivers;
extern TDWork* D_800FE738_TreasureDivers[10]; /* the divers carrying one */
extern s16 D_800FE760_TreasureDivers;
extern omObjData* D_800FE764_TreasureDivers;
extern s16 D_800FE768_TreasureDivers;
extern Vec D_800FE3E4_TreasureDivers[6];
extern s16 D_800FE770_TreasureDivers; /* outline point count */
extern s16 D_800FE772_TreasureDivers; /* outline index count */
extern TDPoint* D_800FE774_TreasureDivers;
extern f32 D_800FE77C_TreasureDivers[5];
extern f32 D_800FE794_TreasureDivers[11];
extern TDTrail D_800FE7C8_TreasureDivers[2][10];
extern f32 D_800FECC0_TreasureDivers[2];
extern s16 D_800FECC8_TreasureDivers[11];
extern s16 D_800FECDE_TreasureDivers[6];
extern s16 D_800FECEA_TreasureDivers;
extern f32 D_800FECEC_TreasureDivers;
extern u8* D_800FECF0_TreasureDivers;
extern s8* D_800FE778_TreasureDivers; /* point indices, < 0 breaks the line */
extern TDSprites D_800FED00_TreasureDivers;
extern omObjData* D_800FED08_TreasureDivers[];
extern s16 D_800FED30_TreasureDivers;
extern TDWork* D_800FED40_TreasureDivers[256];
extern Matrix4f D_800FF140_TreasureDivers;
extern f32 D_800FF178_TreasureDivers;
extern s16 D_800FF180_TreasureDivers;
extern TDBoat D_800FF188_TreasureDivers[3];
extern omObjData* D_800FF248_TreasureDivers;
extern omObjData* D_800FF24C_TreasureDivers[];
extern f32 D_800FF258_TreasureDivers;
extern s16 D_800FF25C_TreasureDivers;
extern TDFx D_800FF260_TreasureDivers[64];
extern TDBoat D_800FFA60_TreasureDivers[2];
extern Matrix4f D_800FFAE0_TreasureDivers;

#endif
