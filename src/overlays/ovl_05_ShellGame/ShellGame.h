#ifndef SHELLGAME_H
#define SHELLGAME_H

/* ovl_05 ShellGame: declarations shared by its units (F6AB0, FD460).
   Types come from the asm's accesses; N64 offsets in the comments. Records that hold a pointer are
   reached through their fields only (the host strides pointers 8 bytes). */

#include "common.h"
#include "PR/gu.h"
#include "sprite65770.h"

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* A sprite slot (D_800FF190[32] and the D_800FF714[10] ring sprites), 0x2C bytes, no pointers. */
typedef struct SGSprite {
    /* 0x00 */ s16 unk0; /* in use (ring sprites: 1 drop, 2 spiral) */
    /* 0x02 */ s16 unk2; /* sprite group */
    /* 0x04 */ u16 unk4; /* flags: 2 3D position, 4 additive, 8 timed */
    /* 0x06 */ s16 unk6; /* image slot */
    /* 0x08 */ u16 unk8; /* frames left */
    /* 0x0A */ char unkA[2];
    /* 0x0C */ f32 unkC; /* scale */
    /* 0x10 */ f32 unk10; /* x */
    /* 0x14 */ f32 unk14; /* y */
    /* 0x18 */ f32 unk18; /* z */
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ s16 unk20;
    /* 0x22 */ s16 unk22;
    /* 0x24 */ s16 unk24;
    /* 0x26 */ s16 unk26;
    /* 0x28 */ s16 unk28;
    /* 0x2A */ s16 unk2A;
} SGSprite; /* size = 0x2C */

/* A coin of the payout burst (D_800FF710[10], HuMemDirectMalloc(0x2A8)), 0x44 bytes. */
typedef struct SGCoin {
    /* 0x00 */ s16 unk0; /* -1 no model, 0 idle, 1 flying */
    /* 0x02 */ char unk2[2];
    /* 0x04 */ s16 unk4; /* image */
    /* 0x06 */ s16 unk6; /* model */
    /* 0x08 */ s16 unk8;
    /* 0x0A */ char unkA[2];
    /* 0x0C */ f32 unkC; /* x */
    /* 0x10 */ f32 unk10; /* y */
    /* 0x14 */ f32 unk14; /* z */
    /* 0x18 */ f32 unk18; /* scale */
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ s16 unk24; /* delay */
    /* 0x26 */ s16 unk26;
    /* 0x28 */ s16 unk28;
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ s16 unk2C;
    /* 0x2E */ char unk2E[2];
    /* 0x30 */ f32 unk30; /* direction */
    /* 0x34 */ f32 unk34; /* speed */
    /* 0x38 */ f32 unk38; /* vertical speed */
    /* 0x3C */ f32 unk3C;
    /* 0x40 */ f32 unk40;
} SGCoin; /* size = 0x44 */

/* A shell (D_800FF7A0[5]), 0x70 bytes, no pointers. Splat labels inside: D_800FF7A4 (+4),
   D_800FF7AC (+0xC), D_800FF80C ([0].unk6C). */
typedef struct SGShell {
    /* 0x00 */ s16 unk0; /* lifting */
    /* 0x02 */ s16 unk2;
    /* 0x04 */ f32 unk4; /* angle on the ring */
    /* 0x08 */ s32 unk8;
    /* 0x0C */ u16 unkC; /* frames in the state */
    /* 0x0E */ char unkE[2];
    /* 0x10 */ Vec unk10; /* home position */
    /* 0x1C */ Vec unk1C; /* the ball / item position */
    /* 0x28 */ Vec unk28; /* swap: start */
    /* 0x34 */ Vec unk34; /* swap: end */
    /* 0x40 */ Vec unk40; /* swap: control point */
    /* 0x4C */ Vec unk4C; /* swap: current */
    /* 0x58 */ f32 unk58; /* step */
    /* 0x5C */ f32 unk5C; /* step direction */
    /* 0x60 */ f32 unk60; /* hop speed */
    /* 0x64 */ f32 unk64; /* item distance */
    /* 0x68 */ f32 unk68; /* item height */
    /* 0x6C */ s16 unk6C; /* contents: 2 ball, 5 empty */
    /* 0x6E */ s16 unk6E; /* sprite slot, -1 none */
} SGShell; /* size = 0x70 */

/* One swap of two shells (D_800FF0D0[2]), 0x14 bytes. */
typedef struct SGSwap {
    /* 0x00 */ u16 unk0; /* direction, 1 or 0xFFFF */
    /* 0x02 */ u16 unk2; /* shell a */
    /* 0x04 */ u16 unk4; /* shell b */
    /* 0x06 */ char unk6[2];
    /* 0x08 */ f32 unk8; /* angle of a */
    /* 0x0C */ f32 unkC; /* angle of b */
    /* 0x10 */ f32 unk10; /* midpoint angle */
} SGSwap; /* size = 0x14 */

/* The game's settings and state (D_800FF9D0). Retail reaches its fields through the splat labels
   D_800FF9D2/D4/D6/D8/E0/E2/E4/E6/E8 and through one base register (func_800FB120). */
typedef struct SGGame {
    /* 0x00 */ u16 unk0; /* CPU skill (1..4) */
    /* 0x02 */ u16 unk2; /* shells */
    /* 0x04 */ u16 unk4; /* the shell with the ball */
    /* 0x06 */ s16 unk6; /* result: -1 none, 2 won, 5 lost */
    /* 0x08 */ u16 unk8; /* spin frames */
    /* 0x0A */ char unkA[2];
    /* 0x0C */ f32 unkC; /* spin speed */
    /* 0x10 */ u16 unk10; /* shuffle frames */
    /* 0x12 */ u16 unk12; /* shuffle ramp */
    /* 0x14 */ u16 unk14; /* swap frames */
    /* 0x16 */ u16 unk16; /* jump frames */
    /* 0x18 */ u16 unk18; /* moves */
    /* 0x1A */ char unk1A[2];
} SGGame; /* size = 0x1C */

/* The player's extra state (D_800FFA10[1], indexed by obj->work[0]), 0x2C bytes. */
typedef struct SGPlayer {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ char unk6[2];
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ char unk24[4];
    /* 0x28 */ s32 unk28;
} SGPlayer; /* size = 0x2C */

/* The player object's work (func_8000979C allocates MgWork, 0xE8; src/99E0.c layout). */
typedef struct SGPlayerWork {
    /* 0x00 */ char unk_00[0x34];
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38; /* vertical speed */
    /* 0x3C */ f32 unk3C; /* facing */
    /* 0x40 */ f32 unk40; /* speed */
    /* 0x44 */ f32 unk44;
    /* 0x48 */ f32 unk48; /* radius */
    /* 0x4C */ char unk4C[0xC];
    /* 0x58 */ s8 unk58; /* player */
    /* 0x59 */ char unk59[3];
    /* 0x5C */ s32 unk5C; /* action flags */
    /* 0x60 */ char unk60[4];
    /* 0x64 */ f32 unk64; /* reach */
    /* 0x68 */ char unk68[0x50];
    /* 0xB8 */ void* unkB8; /* MgWork's held item: a pointer, so the host offsets agree */
    /* 0xBC */ char unkBC[0x1C];
    /* 0xD8 */ void* unkD8; /* MgWork's motion pair table */
    /* 0xDC */ void* unkDC; /* collision callback */
    /* 0xE0 */ char unkE0[4];
    /* 0xE4 */ void* unkE4;
} SGPlayerWork; /* size = 0xE8 (N64) */

/* A shell's collision work (D_800EDE70's list, func_80023684(0x6C)): src/1130.c's PlayerWork
   prefix, no pointers. */
typedef struct SGShellWork {
    /* 0x00 */ char unk_00[0x34];
    /* 0x34 */ f32 unk34; /* height */
    /* 0x38 */ f32 unk38;
    /* 0x3C */ f32 unk3C;
    /* 0x40 */ f32 unk40;
    /* 0x44 */ f32 unk44;
    /* 0x48 */ f32 unk48; /* radius */
    /* 0x4C */ f32 unk4C;
    /* 0x50 */ u16 unk50;
    /* 0x52 */ u8 unk52;
    /* 0x53 */ char unk53;
    /* 0x54 */ u8 unk54;
    /* 0x55 */ char unk55[7];
    /* 0x5C */ s32 unk5C;
    /* 0x60 */ f32 unk60;
    /* 0x64 */ char unk64[8];
} SGShellWork; /* size = 0x6C */

/* The stage and backdrop objects' work (func_80023684(0x2C), zeroed). */
typedef struct SGStageWork {
    /* 0x00 */ char unk0[4];
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ char unk6[0x26];
} SGStageWork; /* size = 0x2C */

/* ---------------------------------------------------------------------------------------------
   Main-code declarations not in include/
   --------------------------------------------------------------------------------------------- */

extern unk65770Anim* D_800EC700[256]; /* src/65770.c */
extern omObjData* D_800EDE70[];
extern omObjData* D_800F2AF8[]; /* src/1130.c's collision list, D_800EE984 entries */
extern s16 D_800EE984;
extern u8 D_800F37DA;
extern f32 D_800B8984;
void func_800093FC(omObjData*, f32, f32, f32);
void func_8000940C(omObjData*, f32, f32, f32);
void func_800090C4(omObjData* obj, u8 idx, u8 val);
void func_80017C0C(omObjData*, u8, f32, f32, f32, f32, f32);
void func_80060F04(s16, s16, s16, s16);
void func_80025FC8(s16, f32);
f32 func_80025D18(s16);
f32 func_80025E70(s16);
void func_80060758(s32);
void func_80060440(s16, s16);
s16 func_80024198(u32, Gfx*, s32);
void func_8001E2A8(s16, u16);
f64 func_8009B618(f64, f64);
void func_80066DF4(s16 grpIdx, s16 idx, s16 camIdx, f32 x, f32 y, f32 z);
void func_80067284(s16, s16, f32);

/* ---------------------------------------------------------------------------------------------
   Data (F6AB0.c, then FD460.c)
   --------------------------------------------------------------------------------------------- */

extern u32 D_800FEC10_ShellGame; /* random seed */
extern s16 D_800FEC14_ShellGame;
extern s16 D_800FEC16_ShellGame;
extern s16 D_800FEC18_ShellGame;
extern f32 D_800FEC1C_ShellGame;
extern s16 D_800FEC20_ShellGame;
extern s16 D_800FEC22_ShellGame;
extern s16 D_800FEC24_ShellGame;
extern s16 D_800FEC26_ShellGame;
extern s16 D_800FEC28_ShellGame;
extern u16 D_800FEC2A_ShellGame;
extern u16 D_800FEC2C_ShellGame;
extern s16 D_800FEC2E_ShellGame;
extern s16 D_800FEC30_ShellGame;
extern s16 D_800FEC32_ShellGame;
extern u32 D_800FEC34_ShellGame;
extern f32 D_800FEC38_ShellGame;
extern f32 D_800FEC3C_ShellGame;
extern omObjData* D_800FEC40_ShellGame;
extern omObjData* D_800FEC44_ShellGame;
extern s16 D_800FEC48_ShellGame;
extern s16 D_800FEC4A_ShellGame;
extern f32 D_800FEC4C_ShellGame;
extern f32 D_800FEC50_ShellGame;
extern u16 D_800FEC54_ShellGame;
extern f32 D_800FEC58_ShellGame;
extern s16 D_800FEC5C_ShellGame;

/* ---------------------------------------------------------------------------------------------
   .bss
   --------------------------------------------------------------------------------------------- */

extern Vec D_800FF0A0_ShellGame; /* camera centre at the start of the zoom */
extern Vec D_800FF0AC_ShellGame; /* camera centre at its end */
extern s16 D_800FF0B8_ShellGame[3]; /* the three dizzy stars' sprite slots */
extern f32 D_800FF0C0_ShellGame[3]; /* their angles */
extern SGSwap D_800FF0D0_ShellGame[2];
extern omObjData* D_800FF0F8_ShellGame; /* the game's main object */
extern omObjData* D_800FF0FC_ShellGame; /* the shells' controller */
extern s32 D_800FF100_ShellGame; /* controller state */
extern s32 D_800FF104_ShellGame; /* frames in the state */
extern omObjData* D_800FF108_ShellGame; /* the backdrop */
extern s32 D_800FF10C_ShellGame; /* time left */
extern u16 D_800FF110_ShellGame[12]; /* move list: 0 spin, 1 swap, 2 shuffle */
extern Matrix4f D_800FF128_ShellGame;
extern f32 D_800FF168_ShellGame;
extern s16 D_800FF170_ShellGame[9]; /* sprite images, [1..8] loaded by func_800F7550 */
extern s16 D_800FF182_ShellGame; /* backdrop image */
extern s16 D_800FF184_ShellGame; /* title image */
extern s16 D_800FF188_ShellGame; /* title sprite group */
extern SGSprite D_800FF190_ShellGame[32];
extern SGCoin* D_800FF710_ShellGame;
extern SGSprite* D_800FF714_ShellGame;
extern Gfx* D_800FF718_ShellGame[3]; /* backdrop display lists, one per frame buffer */
extern s16 D_800FF724_ShellGame;
extern s32 D_800FF728_ShellGame[11][2]; /* backdrop rows: speed, offset */
extern s16 D_800FF780_ShellGame;
extern s16 D_800FF782_ShellGame;
extern s16 D_800FF784_ShellGame;
extern s16 D_800FF790_ShellGame; /* the player's motion */
extern s16 D_800FF792_ShellGame; /* the player is a CPU */
extern s16 D_800FF794_ShellGame; /* its controller port */
extern s16 D_800FF796_ShellGame;
extern f32 D_800FF798_ShellGame;
extern f32 D_800FF79C_ShellGame;
extern SGShell D_800FF7A0_ShellGame[5];
extern SGGame D_800FF9D0_ShellGame;
extern s32 D_800FF9EC_ShellGame; /* phase */
extern s16 D_800FF9F0_ShellGame; /* the player */
extern omObjData* D_800FF9F8_ShellGame[5]; /* the shells */
extern s16 D_800FFA0C_ShellGame; /* the player's character */
extern SGPlayer D_800FFA10_ShellGame[1];
extern s32 D_800FFA3C_ShellGame;

/* ---------------------------------------------------------------------------------------------
   Functions
   --------------------------------------------------------------------------------------------- */

/* F6AB0.c */
void func_800F65E0_ShellGame(void);
void func_800F689C_ShellGame(omObjData*);
void func_800F68E8_ShellGame(omObjData*);
void func_800F6A14_ShellGame(omObjData*);
void func_800F6A98_ShellGame(omObjData*);
void func_800F6AC0_ShellGame(omObjData*);
void func_800F6EE4_ShellGame(omObjData*);
void func_800F6FFC_ShellGame(omObjData*);
void func_800F7034_ShellGame(void);
void func_800F7098_ShellGame(f32);
u16 func_800F719C_ShellGame(u16);
void func_800F720C_ShellGame(u8);
f32 func_800F7230_ShellGame(f32, f32, f32);
f32 func_800F7398_ShellGame(f32, f32);
f32 func_800F7410_ShellGame(f32, f32, f32, f32);
void func_800F7470_ShellGame(f32, f32*, f32*, f32*, f32*);
u16 func_800F750C_ShellGame(s32);
void func_800F7550_ShellGame(void);
void func_800F76C4_ShellGame(void);
s16 func_800F7840_ShellGame(s16, f32, f32, f32, u16);
void func_800F79FC_ShellGame(omObjData*, u16);
void func_800F7AE8_ShellGame(f32, f32, f32);
void func_800F7BDC_ShellGame(void);
void func_800F7DA8_ShellGame(omObjData*, s32);
s16 func_800F8154_ShellGame(void);
s16 func_800F8238_ShellGame(s32, s32, s32);
void func_800F828C_ShellGame(void);
void func_800F83BC_ShellGame(f32, f32, f32);
void func_800F85B4_ShellGame(void);
void func_800F87AC_ShellGame(void);
void func_800F87CC_ShellGame(void);
void func_800F88E8_ShellGame(omObjData*, omObjData*, s16, s16);
void func_800F8CF8_ShellGame(void);
void func_800F913C_ShellGame(void);
void func_800F915C_ShellGame(void);
void func_800F91DC_ShellGame(omObjData*);
void func_800F94A0_ShellGame(omObjData*);
void func_800F9570_ShellGame(omObjData*);
void func_800F9618_ShellGame(void);
void func_800F9738_ShellGame(void);
void func_800F9A8C_ShellGame(omObjData*);
void func_800F9E24_ShellGame(omObjData*);
void func_800FA038_ShellGame(omObjData*);
void func_800FA0EC_ShellGame(void);
void func_800FA664_ShellGame(void);
void func_800FA954_ShellGame(void);
void func_800FAA44_ShellGame(void);
void func_800FAC34_ShellGame(void);
void func_800FB030_ShellGame(void);
void func_800FB120_ShellGame(void);
void func_800FB4A4_ShellGame(void);
void func_800FBB44_ShellGame(s16);
void func_800FBBC8_ShellGame(omObjData*);
void func_800FBDB8_ShellGame(u16*);
void func_800FBEF0_ShellGame(SGSwap*, u16*);
void func_800FC17C_ShellGame(SGSwap*);
void func_800FC3F4_ShellGame(SGSwap*, f32);
void func_800FC55C_ShellGame(SGSwap*);
void func_800FC6E0_ShellGame(omObjData*);
void func_800FC714_ShellGame(omObjData*);
void func_800FC748_ShellGame(omObjData*);
void func_800FC77C_ShellGame(omObjData*);
void func_800FC7B0_ShellGame(s16);
void func_800FC800_ShellGame(Gfx*, s16, u16, s32, s32, u16, f32, f32);

/* FD460.c */
void func_800FCF90_ShellGame(omObjData*);
void func_800FD448_ShellGame(omObjData*);
void func_800FD538_ShellGame(omObjData*);
void func_800FD808_ShellGame(omObjData*);
void func_800FDD94_ShellGame(u16);
void func_800FDE08_ShellGame(omObjData*, s16);
void func_800FDE50_ShellGame(omObjData*);
void func_800FDF28_ShellGame(omObjData*);
void func_800FE010_ShellGame(omObjData*);
void func_800FE07C_ShellGame(omObjData*);
void func_800FE46C_ShellGame(omObjData*);
void func_800FE5BC_ShellGame(omObjData*);
void func_800FE6BC_ShellGame(omObjData*);
void func_800FE7AC_ShellGame(omObjData*);
void func_800FE7B4_ShellGame(omObjData*);
s32 func_800FE87C_ShellGame(omObjData*, omObjData*);
void func_800FEB40_ShellGame(omObjData*);

#endif
