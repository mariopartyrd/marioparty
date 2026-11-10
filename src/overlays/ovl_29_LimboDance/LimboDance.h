#ifndef LIMBODANCE_H
#define LIMBODANCE_H

/* ovl_29 LimboDance (1P): units 1E0A30.c (game flow, the dancer, the limbo bars) and 1E4480.c
   (scenery, torches and the billboard system shared in shape with ovl_25 SlotCarDerby).
   Types come from the asm's accesses; N64 offsets are in the comments. */

#include "common.h"
#include "sprite65770.h"

/* A motion slot of the dancer (obj->motion[i]): its id and length in frames. */
typedef struct LDMot {
    /* 0x00 */ s16 id;
    /* 0x02 */ s16 len;
} LDMot;

/* The dancer (D_800FF008_LimboDance[obj->work[0]], 0x58). No pointers. */
typedef struct LDPlayer {
    /* 0x00 */ s16 active;
    /* 0x02 */ s16 port; /* -1: CPU */
    /* 0x04 */ LDMot mot[7];
    /* 0x20 */ f32 lean; /* how far back the dancer leans (0..60) */
    /* 0x24 */ s16 skill; /* CPU */
    /* 0x26 */ s16 bold;  /* CPU */
    /* 0x28 */ s16 seed;  /* CPU */
    /* 0x2A */ char unk_2A[2];
    /* 0x2C */ f32 vel;
    /* 0x30 */ s16 input[10];
    /* 0x44 */ s16 hist[10];
} LDPlayer; /* size = 0x58 */

/* A limbo bar (D_800FF068_LimboDance[12], 0x1C). No pointers. */
typedef struct LDBar {
    /* 0x00 */ s16 active;
    /* 0x02 */ s16 state; /* 1, 2: knocked off */
    /* 0x04 */ f32 vel;
    /* 0x08 */ f32 x0; /* left post */
    /* 0x0C */ f32 y0;
    /* 0x10 */ f32 x1; /* right post */
    /* 0x14 */ f32 y1;
    /* 0x18 */ f32 height;
} LDBar; /* size = 0x1C */

/* A delayed sound (D_800FF1C8_LimboDance[10]). */
typedef struct LDSound {
    /* 0x00 */ s16 id; /* -1: free */
    /* 0x02 */ s16 delay;
} LDSound;

/* A scenery record (D_800FF220_LimboDance, HuMemDirectMalloc(0xD20): 35). No pointers. */
typedef struct LDScenery {
    /* 0x00 */ s16 type; /* 1: two models, 2: a torch (model + billboards) */
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ char unk_0A[2];
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ Vec unk_10;
    /* 0x1C */ Vec unk_1C;
    /* 0x28 */ Vec pos;
    /* 0x34 */ Vec scale;
    /* 0x40 */ s16 model;
    /* 0x42 */ s16 sub[3]; /* a second model (type 1) or billboards (type 2) */
    /* 0x48 */ s16 unk_48[4];
    /* 0x50 */ s16 unk_50[4];
    /* 0x58 */ s16 unk_58[4];
} LDScenery; /* size = 0x60 */

/* A billboard D_80103298[D_800FF1FC_LimboDance] (func_800FB93C allocates them; func_800FBAF0 and
   func_800FC9A0 build one): ovl_25 SlotCarDerby's SCDBillboard. The pointer fields shift every
   later field on the host: use names, never offsets. */
typedef struct LDBillboard {
    /* 0x00 */ Gfx* unk_00;    /* display list, (Gfx*)-1 = free */
    /* 0x04 */ Gfx* unk_04[3]; /* per-frame material lists (D_800F37F0 picks one) */
    /* 0x10 */ Vtx* unk_10[3]; /* per-frame vertices */
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s8 unk_20;
    /* 0x21 */ char unk_21;
    /* 0x22 */ u16 unk_22; /* sprite (D_800EC700 index) */
    /* 0x24 */ s16 unk_24; /* frame */
    /* 0x26 */ s16 unk_26;
    /* 0x28 */ u8 unk_28; /* flags (see SlotCarDerby.h) */
    /* 0x29 */ u8 unk_29; /* alpha */
    /* 0x2A */ u8 unk_2A; /* r */
    /* 0x2B */ u8 unk_2B; /* g */
    /* 0x2C */ u8 unk_2C; /* b */
    /* 0x2D */ char unk_2D[3];
    /* 0x30 */ f32 unk_30; /* frame timer */
    /* 0x34 */ f32 unk_34; /* animation speed */
    /* 0x38 */ Vec unk_38; /* position */
    /* 0x44 */ Vec unk_44; /* scale */
    /* 0x50 */ Vec unk_50; /* rotation */
} LDBillboard; /* size = 0x5C (N64) */

/* The scenery object's work (func_80023684(0x2C)). */
typedef struct LDSceneWork {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk_06[0x26];
} LDSceneWork; /* size = 0x2C */


/* ---------------------------------------------------------------------------------------------
   Overlay data and bss
   --------------------------------------------------------------------------------------------- */

extern u32 D_800FE980_LimboDance; /* RNG seed */
extern u16 D_800FE984_LimboDance; /* intro state */
extern s16 D_800FE986_LimboDance; /* intro timer */
extern s16 D_800FE988_LimboDance;
extern s16 D_800FE98A_LimboDance;
extern u16 D_800FE98C_LimboDance;
extern s16 D_800FE98E_LimboDance;
extern s16 D_800FE990_LimboDance;
extern s16 D_800FE992_LimboDance;
extern s16 D_800FE994_LimboDance;
extern s16 D_800FE996_LimboDance;
extern u16 D_800FE998_LimboDance;
extern u16 D_800FE99A_LimboDance;
extern s16 D_800FE99C_LimboDance;
extern u16 D_800FE99E_LimboDance;
extern s16 D_800FE9A0_LimboDance;
extern s16 D_800FE9A2_LimboDance;
extern s16 D_800FE9A4_LimboDance;
extern f32 D_800FE9A8_LimboDance;
extern f32 D_800FE9AC_LimboDance;
extern s32 D_800FE9B0_LimboDance;
extern f32 D_800FE9B4_LimboDance;
extern f32 D_800FE9B8_LimboDance;
extern f32 D_800FE9BC_LimboDance;
extern Vtx D_800FE9C0_LimboDance[4];
extern s32 D_800FEA00_LimboDance[8];
extern s16 D_800FEA20_LimboDance[4];
extern Vtx D_800FEA28_LimboDance[9];

extern omObjData* D_800FEFF0_LimboDance;
extern s16 D_800FEFF4_LimboDance;
extern s16 D_800FEFF6_LimboDance;
extern u32 D_800FEFF8_LimboDance;
extern u32 D_800FEFFC_LimboDance;
extern s16 D_800FF000_LimboDance;
extern LDPlayer D_800FF008_LimboDance[1];
extern s16 D_800FF060_LimboDance;
extern s16 D_800FF062_LimboDance;
extern s16 D_800FF064_LimboDance;
extern LDBar D_800FF068_LimboDance[12];
extern f32 D_800FF1B8_LimboDance;
extern s16 D_800FF1BC_LimboDance;
extern s16 D_800FF1BE_LimboDance;
extern s16 D_800FF1C0_LimboDance;
extern s16 D_800FF1C2_LimboDance;
extern s32 D_800FF1C4_LimboDance;
extern LDSound D_800FF1C8_LimboDance[10];
extern s32 D_800FF1F0_LimboDance;
extern s32 D_800FF1F4_LimboDance;
extern Gfx* D_800FF1F8_LimboDance;
extern s32 D_800FF1FC_LimboDance;
extern Gfx* D_800FF200_LimboDance[3];
extern Mtx* D_800FF20C_LimboDance[3];
extern s32 D_800FF218_LimboDance;
extern LDScenery* D_800FF220_LimboDance;

/* ovl_25's bss label, reused here (retail reaches past this overlay's own bss). */
extern LDBillboard* D_80103298;

/* ---------------------------------------------------------------------------------------------
   Main code
   --------------------------------------------------------------------------------------------- */

extern omObjData* D_800F2AF8[];
extern s16 D_800EE984;
extern u8 D_800F37DA;
extern unk65770Anim* D_800EC700[256];

void func_80023A38(void* src, void* dst, s32 size); /* copy */
s32 func_80024198(u32, Gfx*, s32);
s16 func_8001755C(s32);
f32 func_80025D40(s16);
void func_80060440(s16, s16);
void func_80060F04(s16, s16, s16, s16);
void func_80017C0C(omObjData*, u8, f32, f32, f32, f32, f32);
unk65770Anim* func_80067310(s16);
f64 func_8009B618(f64, f64); /* fmod */
void guMtxL2F(float mf[4][4], Mtx* m);

/* ---------------------------------------------------------------------------------------------
   Overlay functions
   --------------------------------------------------------------------------------------------- */

void func_800F65E0_LimboDance(void);
void func_800F67D4_LimboDance(omObjData* obj);
void func_800F6844_LimboDance(omObjData* obj);
void func_800F6AB8_LimboDance(omObjData* obj);
void func_800F6C7C_LimboDance(omObjData* obj);
void func_800F70C0_LimboDance(omObjData* obj);
void func_800F7210_LimboDance(omObjData* obj);
void func_800F723C_LimboDance(omObjData* obj);
void func_800F7264_LimboDance(void);
void func_800F72B8_LimboDance(void);
void func_800F7328_LimboDance(f32 t);
void func_800F7424_LimboDance(f32 t);
void func_800F74C0_LimboDance(void);
void func_800F750C_LimboDance(s16 id, s16 delay);
void func_800F756C_LimboDance(void);
u16 func_800F7628_LimboDance(u16 n);
void func_800F7698_LimboDance(u16 seed);
f32 func_800F76BC_LimboDance(f32 target, f32 cur, f32 step);
void func_800F7824_LimboDance(omObjData* obj, u16 slot, s32 file);
void func_800F78DC_LimboDance(s16 model, LDMot* mot, s16 loop);
void func_800F7984_LimboDance(void);
void func_800F7B08_LimboDance(omObjData* obj);
void func_800F7E40_LimboDance(omObjData* obj);
s16 func_800F8CA0_LimboDance(omObjData* obj);
void func_800F9080_LimboDance(omObjData* obj);
void func_800F922C_LimboDance(void);
void func_800F929C_LimboDance(omObjData* obj);
void func_800F97B8_LimboDance(s16 i, s16* models, s16* src, f32 x, u16 height);
void func_800F9A28_LimboDance(omObjData* obj);
s16 func_800F9C98_LimboDance(void);
s16 func_800F9CFC_LimboDance(f32 x);
s16 func_800F9D48_LimboDance(f32 x, f32 lean);

void func_800FA030_LimboDance(void);
void func_800FA0DC_LimboDance(void);
void func_800FA110_LimboDance(omObjData* obj);
void func_800FA418_LimboDance(omObjData* obj);
void func_800FB04C_LimboDance(f32 x);
void func_800FB058_LimboDance(omObjData* obj);
void func_800FB504_LimboDance(s16 sprite, Gfx** gfx, f32 scroll);
void func_800FB93C_LimboDance(u8 count);
s16 func_800FBAF0_LimboDance(s16 sprite, s16 sprite2, u8 flags);
void func_800FC4FC_LimboDance(s32 id, f32 amp, f32 angle);
s16 func_800FC9A0_LimboDance(s16 sprite, u8 flags);
void func_800FDBEC_LimboDance(s16 id, s16 frame);
void func_800FDC2C_LimboDance(s16 id, f32 speed);
void func_800FDC6C_LimboDance(s16 id, f32 x, f32 y, f32 z);
void func_800FDCBC_LimboDance(s16 id, f32 x, f32 y, f32 z);
void func_800FDD0C_LimboDance(s16 id, f32 x, f32 y, f32 z);
void func_800FDD5C_LimboDance(s16 id, u8 flags);
Vtx* func_800FDDA0_LimboDance(s16 id, s32 frame);
void func_800FDDEC_LimboDance(s16 id, u8 r, u8 g, u8 b, s32 a);
void func_800FDE38_LimboDance(s16 id);
void func_800FDF58_LimboDance(void);
void func_800FE3CC_LimboDance(void);
void func_800FE8C4_LimboDance(void);

#endif
