#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H

/* ovl_02 SlotMachine: declarations shared by its units (E02F0, E13F0, E5DA0).
   Types come from the asm's accesses. N64 offsets are in the comments; a struct with no pointers
   has the same layout on the host. Allocate every work block with sizeof (never retail's literal
   size): the host strides pointers 8 bytes. */

#include "common.h"
#include "sprite65770.h"
#include "engine/math.h"

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* An actor's state block (func_800FBE84: HuMemDirectMalloc(0x60), kept in D_800FFCC8[] and found
   again through the object's work[0..3] by func_800FBFEC), and the 20 coins of D_800FF250
   (func_800F7750), which use the same layout without unk_0C.
   Slot machine (func_800F99E0): unk_40 = intro step / lever angle, unk_42 = timer, unk_44 / unk_46
   = lamp indices. Player (func_800FAE34): unk_00 flags (0x80C0 set on the first frame, sign bit =
   not yet started), unk_08 = phase, unk_10..18 = position, unk_1C/20 = previous x/y, unk_40 =
   step, unk_42 = CPU timer, unk_44 = angle counter, unk_5E = initial rot.x (func_800F71EC).
   Coin (func_800F7750): unk_00 active, unk_02 step, unk_10..18 position, unk_1C..24 start,
   unk_28..30 target, unk_40 model, unk_42 sprite group, unk_44 timer (u16 arithmetic). */
typedef struct SlotWork {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ char unk_0A[2];
    /* 0x0C */ omObjData* unk_0C; /* the owner (func_800FBE84) */
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ char unk_34[0xC];
    /* 0x40 */ s16 unk_40;
    /* 0x42 */ s16 unk_42;
    /* 0x44 */ s16 unk_44;
    /* 0x46 */ s16 unk_46;
    /* 0x48 */ s16 unk_48;
    /* 0x4A */ s16 unk_4A;
    /* 0x4C */ s16 unk_4C;
    /* 0x4E */ s16 unk_4E;
    /* 0x50 */ s16 unk_50;
    /* 0x52 */ s16 unk_52;
    /* 0x54 */ s16 unk_54;
    /* 0x56 */ s16 unk_56;
    /* 0x58 */ s16 unk_58;
    /* 0x5A */ s16 unk_5A;
    /* 0x5C */ s16 unk_5C;
    /* 0x5E */ s16 unk_5E;
} SlotWork; /* size = 0x60 (N64), 0x68 (host) */

/* The slot machine object's work (func_800F69D0: func_80023684(0x2C), zeroed with func_8009B770,
   filled by func_80009028/func_80009090): MgWork's first 0x2C bytes (src/1130.c's GroundWork).
   No pointers. */
typedef struct SlotGroundWork {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01; /* flags */
    /* 0x02 */ char unk_02[2];
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ s8 unk_05;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18; /* box min x */
    /* 0x1C */ f32 unk_1C; /* box min z */
    /* 0x20 */ f32 unk_20; /* box max x */
    /* 0x24 */ f32 unk_24; /* box max z */
    /* 0x28 */ char unk_28[4];
} SlotGroundWork; /* size = 0x2C */

/* The player object's work (func_800F71EC: func_8000979C allocates a MgWork, 0xE8). MgWork's layout
   (src/99E0.c) with the fields this overlay touches; its pointers sit where MgWork's do (0xB8, 0xD8,
   0xDC, 0xE4) so the host layout agrees with the allocator's. */
typedef struct SlotPlayerWork {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01; /* flags */
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
    /* 0x34 */ f32 unk_34; /* 220.0f for character 5 (func_800F71EC) */
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ char unk_53[2];
    /* 0x55 */ u8 unk_55;
    /* 0x56 */ s8 unk_56; /* controller port (lbu, used as s8) */
    /* 0x57 */ u8 unk_57;
    /* 0x58 */ s8 unk_58; /* player index (lb) */
    /* 0x59 */ char unk_59[3];
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ char unk_60[0x58];
    /* 0xB8 */ omObjData* unk_B8;
    /* 0xBC */ char unk_BC[0x1C];
    /* 0xD8 */ s16 (*unk_D8)[2];
    /* 0xDC */ void* unk_DC; /* collision callback: func_800F71EC clears it (NULL) */
    /* 0xE0 */ char unk_E0[4];
    /* 0xE4 */ void* unk_E4;
} SlotPlayerWork; /* size = 0xE8 (N64) */

#define SLOT_PLAYER(obj) ((SlotPlayerWork*)(obj)->unk_50)

/* One reel (D_800FFA70[3], stride 0x20; func_800FC090 sets it up, func_800FCC98 runs it). */
typedef struct SlotReel {
    /* 0x00 */ u8 unk_00; /* state: 0 stopped, 1 spinning, 2 stopping (lbu/sb) */
    /* 0x01 */ u8 unk_01; /* index of the face showing (0..7, func_800FC7A8) */
    /* 0x02 */ u8 unk_02; /* that face's symbol (func_800FC8C8; sb only) */
    /* 0x03 */ u8 unk_03; /* target face */
    /* 0x04 */ s16 unk_04; /* delay frames (lh/sh) */
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ f32 unk_08; /* angle, degrees, kept in [0, 360) */
    /* 0x0C */ f32 unk_0C; /* angle offset */
    /* 0x10 */ f32 unk_10; /* speed */
    /* 0x14 */ f32 unk_14; /* acceleration */
    /* 0x18 */ f32 unk_18; /* top speed */
    /* 0x1C */ unk2C0C0Struct50* unk_1C; /* the reel's model part (func_80026A0C(model, "r1".."r3")) */
} SlotReel; /* size = 0x20 (N64), 0x28 (host) */

/* One effect sprite (D_800FFAD8[6], stride 0x48; func_800FD248/func_800FD420/func_800FD590).
   No pointers. */
typedef struct SlotFx {
    /* 0x00 */ u8 unk_00; /* flags: 0xC0 = visible */
    /* 0x01 */ u8 unk_01; /* kind (D_800FED8C[].unk_00 / unk_01) */
    /* 0x02 */ u8 unk_02; /* phase (D_800FFADA = D_800FFAD8[0].unk_02) */
    /* 0x03 */ u8 unk_03; /* sprite frame */
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10; /* x (screen, from the centre) */
    /* 0x14 */ f32 unk_14; /* y */
    /* 0x18 */ f32 unk_18; /* scale x */
    /* 0x1C */ f32 unk_1C; /* scale y */
    /* 0x20 */ f32 unk_20; /* rotation */
    /* 0x24 */ f32 unk_24; /* alpha (0..1) */
    /* 0x28 */ f32 unk_28; /* start x */
    /* 0x2C */ f32 unk_2C; /* start y */
    /* 0x30 */ f32 unk_30; /* start scale x */
    /* 0x34 */ f32 unk_34; /* start scale y */
    /* 0x38 */ s16 unk_38; /* symbol (D_800FFC96) */
    /* 0x3A */ s16 unk_3A; /* frame counter */
    /* 0x3C */ s16 unk_3C;
    /* 0x3E */ s16 unk_3E;
    /* 0x40 */ s16 unk_40;
    /* 0x42 */ s16 unk_42;
    /* 0x44 */ s16 unk_44;
    /* 0x46 */ char unk_46[2];
} SlotFx; /* size = 0x48 */

/* D_800FED8C[8]: per winning symbol (D_800FFC96). Asm-only labels D_800FED8D / D_800FED8F are
   fields of entry 0. */
typedef struct SlotSymFx {
    /* 0x00 */ u8 unk_00; /* effect kind: row of D_800FEDAC / D_800FEDBC */
    /* 0x01 */ u8 unk_01; /* SlotFx.unk_01 after the burst */
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03; /* sprite frame */
} SlotSymFx; /* size = 0x4 */

/* D_800FEDAC[4]: per effect kind. Asm-only labels D_800FEDAD..D_800FEDAF are fields of entry 0. */
typedef struct SlotFxKind {
    /* 0x00 */ u8 unk_00; /* sprite count */
    /* 0x01 */ u8 unk_01; /* alpha * 10 */
    /* 0x02 */ u8 unk_02; /* scale x * 10 */
    /* 0x03 */ u8 unk_03; /* scale y * 10 */
} SlotFxKind; /* size = 0x4 */

/* A random number in [0, n): a 16-bit value from two rand8() calls, scaled. Retail's shape for
   (u8 >> 5) after a discarded second rand8() (n = 8), "* 5 >> 15" (n = 10), "* 0x19 >> 15" (n = 50). */
#define SLOT_RAND(n) ((((rand8() << 8) | rand8()) * (n)) >> 16)

/* ---------------------------------------------------------------------------------------------
   Main-code declarations missing from include/ (signatures from their definitions)
   --------------------------------------------------------------------------------------------- */
void func_800090C4(omObjData* obj, u8 idx, u8 val);
s16 func_80010ED4(s16 id, s16 chanOfs);
void func_80011A30(s16 frames);
s32 func_80017A60(omObjData* obj);
u16 func_8001E1D0(s16 index, s32 arg1);
unk2C0C0Struct50* func_80026A0C(s16, char*);
void func_80060F04(s16 player, s16 arg1, s16 arg2, s16 arg3);
void func_80066DF4(s16 grpIdx, s16 idx, s16 camIdx, f32 x, f32 y, f32 z);
void func_80067284(s16 grpIdx, s16 idx, f32 speed);
u8 func_80067328(s16 grpIdx, s16 idx);
void func_8006765C(s16 grpIdx, s16 idx, f32 arg2, f32 arg3);
void func_8006768C(s16 grpIdx, s16 idx, s16 arg2, s16 arg3);

extern f32 D_800B895C; /* src/1130.c's tuning floats (func_800F65E0 sets them) */
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
extern f32 D_800B8990;
extern f32 D_800B8994;
extern f32 D_800B8998;
extern f32 D_800B899C;
extern u16 D_800EE984;
extern omObjData* D_800F2AF8[]; /* D_800ED440 entries */
extern unk2C0C0Struct70* D_800F37AC; /* src/388E0.c: 128 texture records */
extern u8 D_800F64F8;
extern s8 omSysPauseEnableFlag;

#define D_80360000 ((u16*)0x80360000)

/* ---------------------------------------------------------------------------------------------
   Overlay .data (definitions in the owning unit)
   --------------------------------------------------------------------------------------------- */
/* E02F0 */
extern s32 D_800FE100_SlotMachine;     /* _CheckFlag(0x2B) */
extern s16 D_800FE104_SlotMachine[16]; /* model file ids (| 0x140000), func_800F69D0 */
extern s16 D_800FE124_SlotMachine[6];  /* [0] only: model file id; the rest pads to 0x800FE130 */

/* E13F0 */
extern u8 D_800FE130_SlotMachine[76][38]; /* 76 x 76 I4 mask (two texels per byte), func_800F9534 */
extern s16 D_800FEC78_SlotMachine;  /* SlotWork count in D_800FFCC8 (lhu/sh, lh) */
extern s32 D_800FEC7C_SlotMachine;  /* reel timer */
extern s32 D_800FEC80_SlotMachine;  /* game state (-1 intro .. 0x11) */
extern s32 D_800FEC84_SlotMachine;  /* spins left */
extern s32 D_800FEC88_SlotMachine;  /* lever animation flag */
extern s32 D_800FEC8C_SlotMachine;  /* lever angle: s32 (lw/sw; lwc1 + cvt.d.w) */
extern s32 D_800FEC90_SlotMachine;  /* coins won; read as (u16) at +2 (asm label D_800FEC92) */
extern s32 D_800FEC94_SlotMachine;  /* end-sequence frame counter */
extern s32 D_800FEC98_SlotMachine;  /* coins set up */
extern s32 D_800FEC9C_SlotMachine;  /* coins collected */
extern s32 D_800FECA0_SlotMachine;
extern s32 D_800FECA4_SlotMachine;
extern u8 D_800FECA8_SlotMachine;   /* sb only */
extern s16 D_800FECAC_SlotMachine[3]; /* file ids (| 0x140000), func_800F8580 */
extern f32 D_800FECB4_SlotMachine;
extern s32 D_800FECB8_SlotMachine;
extern f32 D_800FECBC_SlotMachine;
extern f32 D_800FECC0_SlotMachine;
extern s32 D_800FECC4_SlotMachine;
extern f32 D_800FECC8_SlotMachine;
extern u32 D_800FECCC_SlotMachine;  /* LCG seed (func_800FC018 / func_800FC050). func_800FC804's
                                       D_800FECD0[i - 1] also relocates against this address. */

/* E5DA0 */
extern f32 D_800FECD0_SlotMachine[8];    /* face angles: 45 .. 360 */
extern f32 D_800FECF0_SlotMachine[3][8]; /* symbol on each reel face (whole numbers 1..7) */
extern u8 D_800FED50_SlotMachine[10];    /* spin-pattern pool, copied to D_800FFA60 */
extern u8 D_800FED5C_SlotMachine[4][3];  /* per-reel start delays */
extern Vec3f D_800FED68_SlotMachine;     /* reel 1..3 world positions (func_800FCA34) */
extern Vec3f D_800FED74_SlotMachine;
extern Vec3f D_800FED80_SlotMachine;
extern SlotSymFx D_800FED8C_SlotMachine[8];
extern SlotFxKind D_800FEDAC_SlotMachine[4];
extern s8 D_800FEDBC_SlotMachine[4][3][2]; /* per kind and reel: x, y / 10; 0x7F = use the reel */

/* ---------------------------------------------------------------------------------------------
   Overlay .bss (ovl_02_bss, 0x800FF250..0x800FFCF0). An s32 that retail also reads as its low
   half (asm labels at +2: D_800FFA0E, 1E, 2E, 32, 36, 3A, D_800FFAD2, D_800FFCBA, C2, DA, E2,
   E6) is declared s32 here: write (s16)x / (u16)x, never the +2 label (wrong on the host).
   --------------------------------------------------------------------------------------------- */
extern SlotWork D_800FF250_SlotMachine[20]; /* coins */
extern s32 D_800FF9D0_SlotMachine[3];       /* func_800F9534's previous rectangles, per buffer */
extern s32 D_800FF9DC_SlotMachine[3];
extern s32 D_800FF9E8_SlotMachine[3];
extern s32 D_800FF9F4_SlotMachine[3];
extern f32 D_800FFA00_SlotMachine;          /* saved lever translation (func_800F99E0) */
extern f32 D_800FFA04_SlotMachine;
extern f32 D_800FFA08_SlotMachine;
extern s32 D_800FFA0C_SlotMachine;          /* CPU difficulty; (u16) read at +2 */
extern u16* D_800FFA10_SlotMachine;         /* 320 x 240 copy of the framebuffer (0x25800) */
extern u8* D_800FFA14_SlotMachine;          /* saved sprite image pointer (func_800FBD60 restores) */
extern u8* D_800FFA18_SlotMachine;          /* saved sprite image pointer */
extern s32 D_800FFA1C_SlotMachine;          /* sprite group ids (func_80064EF4), s16 at +2 */
extern s16 D_800FFA22_SlotMachine;          /* low half of an s32 at 0x800FFA20 nothing writes: lh only */
extern s32 D_800FFA24_SlotMachine;          /* frame % 3: current D_800FFA54 buffer */
extern s32 D_800FFA28_SlotMachine;          /* func_800FC2CC's result */
extern s32 D_800FFA2C_SlotMachine;
extern s32 D_800FFA30_SlotMachine;
extern s32 D_800FFA34_SlotMachine;
extern s32 D_800FFA38_SlotMachine;          /* sprite id (func_800678A4) */
extern void* D_800FFA3C_SlotMachine[3];     /* only freed (func_800FBD60) */
extern void* D_800FFA48_SlotMachine[3];     /* only freed (func_800FBD60) */
extern u8* D_800FFA54_SlotMachine[3];       /* three 0x9600-byte I4 buffers (func_800F8580) */
extern u8 D_800FFA60_SlotMachine[10];       /* shuffled spin patterns */
extern s16 D_800FFA6A_SlotMachine;          /* next pattern */
extern SlotReel D_800FFA70_SlotMachine[3];  /* asm labels D_800FFA71..D_800FFA88: fields of [0] */
extern s32 D_800FFAD0_SlotMachine;          /* sound handle (func_80060540), -1 none; s16 at +2 */
extern SlotFx D_800FFAD8_SlotMachine[6];    /* asm label D_800FFADA = [0].unk_02 */
extern s16 D_800FFC88_SlotMachine;          /* sprite id */
extern s16 D_800FFC8A_SlotMachine;          /* sprite group */
extern s16 D_800FFC8C_SlotMachine;          /* previous D_800FFC90 */
extern s16 D_800FFC8E_SlotMachine;          /* slot machine model */
extern s16 D_800FFC90_SlotMachine;          /* reel state: 0 stopped, 1 spinning, 2 stopping, 3 */
extern s16 D_800FFC92_SlotMachine;
extern s16 D_800FFC94_SlotMachine;          /* result symbol, -1 none */
extern s16 D_800FFC96_SlotMachine;
extern s16 D_800FFC98_SlotMachine;
extern s16 D_800FFC9A_SlotMachine;
extern s16 D_800FFC9C_SlotMachine;
extern s16 D_800FFC9E_SlotMachine;
extern s16 D_800FFCA0_SlotMachine;
extern s16 D_800FFCB0_SlotMachine;          /* 3600 */
extern omObjData* D_800FFCB4_SlotMachine;   /* func_800F6980's object */
extern s32 D_800FFCB8_SlotMachine;          /* player index; (s16) read at +2 */
extern s32 D_800FFCC0_SlotMachine;          /* sprite group; (s16) read at +2 */
extern SlotWork* D_800FFCC8_SlotMachine[4]; /* func_800FBE84's blocks, D_800FEC78 of them */
extern s32 D_800FFCD8_SlotMachine;          /* sprite id; (s16) read at +2 */
extern s16 D_800FFCDC_SlotMachine;          /* < 0: leave the minigame */
extern s32 D_800FFCE0_SlotMachine;          /* sprite id; (s16) read at +2 */
extern s32 D_800FFCE4_SlotMachine;          /* digit sprite group; (s16) read at +2 */

/* ---------------------------------------------------------------------------------------------
   Overlay functions. Process callbacks take the omObjData* the object manager passes.
   --------------------------------------------------------------------------------------------- */
/* E02F0 */
void func_800F65E0_SlotMachine(void);
void func_800F6980_SlotMachine(omObjData*);
void func_800F699C_SlotMachine(void);
void func_800F69D0_SlotMachine(omObjData*);
void func_800F70A8_SlotMachine(s32 model, f32 scale); /* model indexes D_800F2B7C unextended: s32 */
void func_800F71EC_SlotMachine(omObjData*);

/* E13F0 */
void func_800F76E0_SlotMachine(void);
SlotWork* func_800F7734_SlotMachine(omObjData* unused, omObjData* obj); /* no callers */
void func_800F7750_SlotMachine(omObjData*);
void func_800F8554_SlotMachine(omObjData*);
void func_800F8580_SlotMachine(void);
void func_800F89E8_SlotMachine(void);
void func_800F91C4_SlotMachine(s32 arg0, s32 arg1, s32 x, s32 y, s32 z);
void func_800F9534_SlotMachine(s32 grp, s32 size, s32 x0, s32 y0, s32 x1, s32 y1, f32 scale);
void func_800F99E0_SlotMachine(omObjData*);
void func_800FAC10_SlotMachine(s16 model, f32 x, f32 y, s32 mode);
void func_800FAE34_SlotMachine(omObjData*);
void func_800FBD60_SlotMachine(void);
SlotWork* func_800FBE84_SlotMachine(omObjData*);
void func_800FBF6C_SlotMachine(void);
SlotWork* func_800FBFEC_SlotMachine(omObjData*);
void func_800FC018_SlotMachine(void);
s32 func_800FC050_SlotMachine(void);

/* E5DA0 */
void func_800FC090_SlotMachine(s16 model);
s16 func_800FC2CC_SlotMachine(void);
void func_800FC3F4_SlotMachine(void);
void func_800FC5C4_SlotMachine(void);
s16 func_800FC664_SlotMachine(void);
s16 func_800FC684_SlotMachine(void);
f32 func_800FC790_SlotMachine(s16 face);
s16 func_800FC7A8_SlotMachine(f32 angle);
s16 func_800FC804_SlotMachine(f32 angle);
s16 func_800FC8C8_SlotMachine(s16 reel, s16 face);
s16 func_800FC904_SlotMachine(s16 reel, s16 symbol);
void func_800FC9A8_SlotMachine(unk2C0C0Struct50* part);
void func_800FCA34_SlotMachine(s16 camera, Vec3f* pos, f32* out);
void func_800FCBFC_SlotMachine(Matrix4f m, f32 x, f32 y, f32 z, f32* out); /* out[3]: m * (x, y, z, 1) */
void func_800FCC98_SlotMachine(void);
void func_800FD248_SlotMachine(void);
void func_800FD420_SlotMachine(void);
void func_800FD590_SlotMachine(void);

#endif /* SLOTMACHINE_H */
