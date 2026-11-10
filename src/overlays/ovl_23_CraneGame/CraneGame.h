#ifndef CRANEGAME_H
#define CRANEGAME_H

/* ovl_23 CraneGame: declarations shared by its units (1B3E00, 1B9050, 1BAA60).
   Types come from the asm's accesses; N64 offsets are in the comments. Blocks the main code also
   reads keep the main code's pointer slots, so their host layout agrees. */

#include "common.h"
#include "engine/pad.h"
#include "PR/gu.h"
#include "sprite65770.h"

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* Work of the background model object (func_800F77A8, func_80023684(0x2C)). No pointers. */
typedef struct CGBgWork {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ char unk_06[0x26];
} CGBgWork; /* size = 0x2C */

/* Work of the claw-operator object (func_800F7DD0) and of the prizes in D_800EDE70
   (func_800FA154): func_80023684(0xE8), MgWork's layout (src/99E0.c), whose pointers sit at
   0xB8, 0xD8, 0xDC and 0xE4. D_800EDE70 is src/1130.c's collision list. */
typedef struct CGWork {
    /* 0x00 */ char unk_00[0x34];
    /* 0x34 */ f32 unk34; /* half width */
    /* 0x38 */ f32 unk38; /* half depth */
    /* 0x3C */ f32 unk3C; /* move angle, -1 none */
    /* 0x40 */ f32 unk40; /* speed */
    /* 0x44 */ char unk_44[0xC];
    /* 0x50 */ u16 unk50; /* state; 0xFFFF out of play (read signed in func_800F7A88) */
    /* 0x52 */ u8 unk52; /* 1: falls toward the chute */
    /* 0x53 */ s8 unk53; /* shape: 0 three contact points, 1 four */
    /* 0x54 */ char unk_54[2];
    /* 0x56 */ s8 unk56; /* controller port */
    /* 0x57 */ u8 unk_57;
    /* 0x58 */ s8 unk58; /* character */
    /* 0x59 */ char unk_59[0x53];
    /* 0xAC */ u16 unkAC;
    /* 0xAE */ u16 unkAE;
    /* 0xB0 */ s8 unkB0;
    /* 0xB1 */ char unk_B1[3];
    /* 0xB4 */ s16 unkB4; /* frames before it drops in */
    /* 0xB6 */ char unk_B6[2];
    /* 0xB8 */ void* unk_B8;
    /* 0xBC */ f32 unk_BC;
    /* 0xC0 */ u16 unkC0;
    /* 0xC2 */ char unk_C2[8];
    /* 0xCA */ u16 unkCA; /* current motion */
    /* 0xCC */ char unk_CC[0xC];
    /* 0xD8 */ void* unkD8;
    /* 0xDC */ void* unk_DC;
    /* 0xE0 */ char unk_E0[4];
    /* 0xE4 */ void* unk_E4;
} CGWork; /* size = 0xE8 */

#define CG_WORK(obj) ((CGWork*)(obj)->unk_50)

/* The claw (func_800F704C, HuMemDirectMalloc(0x5C)), kept in D_80100BC0_CraneGame. No pointers. */
typedef struct CGClaw {
    /* 0x00 */ s16 unk0; /* 1 once initialised */
    /* 0x02 */ u16 unk2; /* flags: 1/2 clamped by func_800F746C, 4 empty-handed */
    /* 0x04 */ s16 unk4; /* grab radius */
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s16 unk8; /* state */
    /* 0x0A */ u16 unkA; /* index in D_80100BC0_CraneGame */
    /* 0x0C */ f32 unkC; /* claw position */
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C; /* lowest height */
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ char pad30[0xC];
    /* 0x3C */ s16 unk3C; /* timer */
    /* 0x3E */ s16 unk3E; /* frames moving one way */
    /* 0x40 */ s16 unk40; /* grip level */
    /* 0x42 */ s16 unk42;
    /* 0x44 */ s16 unk44; /* motor sound, -1 none */
    /* 0x46 */ s16 unk46; /* motor volume step */
    /* 0x48 */ s16 unk48; /* cable sound, -1 none */
    /* 0x4A */ s16 unk4A;
    /* 0x4C */ s16 unk4C; /* grip frames left */
    /* 0x4E */ s16 unk4E; /* grip frames per level */
    /* 0x50 */ s16 unk50;
    /* 0x52 */ s16 unk52;
    /* 0x54 */ s16 unk54;
    /* 0x56 */ s16 unk56;
    /* 0x58 */ s16 unk58; /* CPU target (D_800EDE70 index) */
    /* 0x5A */ s16 unk5A; /* grabbed prize (D_800EDE70 index), -1 none */
} CGClaw; /* size = 0x5C */

/* A prize type (D_800FFC00_CraneGame, func_800FA154). */
typedef struct CGPrizeType {
    /* 0x00 */ s16 file;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 unk3; /* CGWork.unk53 */
    /* 0x04 */ s16 unk4; /* half width / 10 */
    /* 0x06 */ s16 unk6; /* half depth / 10 */
} CGPrizeType; /* size = 0x8 */

/* A model group's shadow display list (D_80100448_CraneGame, func_800FC4F4): a list of
   gSPVertex/gSP1Triangle commands that load from segment 1 (the vertex buffer of the frame). */
typedef struct CGShadowGroup {
    /* 0x00 */ Gfx* dl;
    /* 0x04 */ u16 start; /* first vertex in the buffer */
    /* 0x06 */ u16 count;
} CGShadowGroup; /* size = 0x8 (N64) */

/* Shadow opacity per shadowed model (D_800FFF48_CraneGame): eases toward target, which is reset to
   1.0 every frame (func_800FBA78 lowers it). */
typedef struct CGShadowFade {
    /* 0x00 */ f32 cur;
    /* 0x04 */ f32 target;
} CGShadowFade;

/* A face of the shadow mesh (D_801006F8_CraneGame): unique-vertex indices, bit 15 of v[0] = quad. */
typedef struct CGShadowFace {
    /* 0x00 */ u16 v[4];
} CGShadowFace;

/* Draw order of the faces (D_80100704_CraneGame). */
typedef struct CGShadowOrder {
    /* 0x00 */ s16 key;
    /* 0x02 */ s16 face;
} CGShadowOrder;

/* A collision face (func_800FD7B4): plane and corner vertex indices. No pointers. */
typedef struct CGColFace {
    /* 0x00 */ f32 nx;
    /* 0x04 */ f32 ny;
    /* 0x08 */ f32 nz;
    /* 0x0C */ f32 d;
    /* 0x10 */ s16 v[4]; /* v[3] = -1 for a triangle */
    /* 0x18 */ s16 axis; /* dominant normal axis: 0 x, 1 y, 2 z */
    /* 0x1A */ char unk_1A[2];
} CGColFace; /* size = 0x1C */

/* A model group's collision faces (CGCol.groups, func_800FD604). */
typedef struct CGColGroup {
    /* 0x00 */ s16 n;
    /* 0x02 */ s16 radius;
    /* 0x04 */ Matrix4f mtx; /* world to group space (func_800FD3D0) */
    /* 0x44 */ CGColFace* faces;
} CGColGroup; /* size = 0x48 (N64) */

/* A model registered for collision (D_80100750_CraneGame, func_800FD37C). */
typedef struct CGCol {
    /* 0x00 */ s16 model;
    /* 0x02 */ u8 unk2; /* frames before it collides */
    /* 0x03 */ u8 count; /* groups */
    /* 0x04 */ CGColGroup* groups;
    /* 0x08 */ unk2C0C0StructA0* verts;
} CGCol; /* size = 0xC (N64) */

typedef unk34D80Struct80 Temp3; /* D_800ED554 entries (common_structs.h) */

/* ---------------------------------------------------------------------------------------------
   Main-code declarations
   --------------------------------------------------------------------------------------------- */

extern Temp3* D_800ED554;
extern u8 D_800F64F8;
extern omObjData* D_800EDE70[6];
extern u16 D_800EE984;
extern omObjData* D_800F2AF8[];

void func_80027E48(s16 arg0, f32 arg1, f32 arg2, u16 arg3, u16 arg4, char* arg5, u8 arg6);
f64 func_8009B618(f64, f64);
void func_80060F04(s16, s32, s32, s32);
void func_800093FC(omObjData*, f32, f32, f32);
void func_8000940C(omObjData*, f32, f32, f32);
s32 func_80009C90(omObjData*, s16, s16);
f32 func_80025D40(s16);
void func_8006035C(s16, s8);
void func_80060440(s16, s16);
void func_80018E0C(u16, s16);
s16 func_8002451C(u32, void (*)(Gfx**, Mtx*, camera*), u8);
unk65770Anim* func_80067310(s16);
void func_800A0B90(Matrix4f, void*);
s16 MtxInv(Mat4, Mat4);
void func_8001D658(s16, Gfx**);
void func_800AC0B0(Matrix4f, Matrix4f, Matrix4f);
void func_80023A38(void*, void*, s32);

/* ---------------------------------------------------------------------------------------------
   Overlay data (.data, 1B3E00.c)
   --------------------------------------------------------------------------------------------- */

extern s16 D_800FF500_CraneGame[4][2];
extern s32 D_800FF510_CraneGame[4];
extern s16 D_800FF520_CraneGame;
extern s16 D_800FF522_CraneGame;
extern s16 D_800FF524_CraneGame[4];
extern s16 D_800FF52C_CraneGame[6];
extern f32 D_800FF538_CraneGame[6];
extern s32 D_800FF550_CraneGame[4];
extern Gfx D_800FF870_CraneGame[];
extern Vtx D_800FF8B0_CraneGame[3];
extern Vec D_800FF8E0_CraneGame[3];
extern Vec D_800FF904_CraneGame[3];
extern f32 D_800FF928_CraneGame[3];

/* ---------------------------------------------------------------------------------------------
   Overlay bss (names from the link map)
   --------------------------------------------------------------------------------------------- */

extern omObjData* D_800FFE20_CraneGame;
extern s16 D_800FFE24_CraneGame;
extern s16 D_800FFE26_CraneGame;
extern s16 D_800FFE28_CraneGame;
extern s16 D_800FFE2A_CraneGame;
extern s16 D_800FFE2C_CraneGame;
extern s16 D_800FFE2E_CraneGame;
extern s16 D_800FFE30_CraneGame;
extern s16 D_800FFE32_CraneGame; /* prizes made; func_800FA154 reads its low byte (D_800FFE33) */
extern s16 D_800FFE34_CraneGame;
extern void* D_800FFE38_CraneGame;
extern void* D_800FFE3C_CraneGame;
extern s16 D_800FFE40_CraneGame[][2];
extern f32 D_800FFE50_CraneGame[];
extern f32 D_800FFE60_CraneGame[];
extern s16 D_800FFE70_CraneGame;
extern s16 D_800FFE72_CraneGame[6];
extern s16 D_800FFE7E_CraneGame;
extern s16 D_800FFE80_CraneGame[3];
extern s16 D_800FFE86_CraneGame[];
extern u16 D_800FFE90_CraneGame[4][3];
extern u16 D_800FFEA8_CraneGame[4];
extern u16 D_800FFEB0_CraneGame[4];
extern omObjData* D_800FFEB8_CraneGame;
extern s16 D_800FFEC0_CraneGame;
extern s16 D_800FFEC2_CraneGame;
extern s16 D_800FFEC4_CraneGame;
extern s16 D_800FFEC8_CraneGame[64];
extern CGShadowFade D_800FFF48_CraneGame[64];
extern Vtx* D_80100148_CraneGame[64][3];
extern CGShadowGroup* D_80100448_CraneGame[64];
extern s16 D_80100548_CraneGame;
extern u8* D_8010054C_CraneGame;
extern s16 D_80100550_CraneGame;
extern f32 D_80100554_CraneGame;
extern Vec D_80100558_CraneGame;
extern s32 D_80100564_CraneGame;
extern s16 D_80100568_CraneGame;
extern f32 D_8010056C_CraneGame;
extern Vtx D_80100570_CraneGame[3][4];
extern Mtx D_80100630_CraneGame[3];
extern unk2C0C0StructA0* D_801006F0_CraneGame;
extern Vtx* D_801006F4_CraneGame;
extern CGShadowFace* D_801006F8_CraneGame;
extern u16* D_801006FC_CraneGame;
extern s16 D_80100700_CraneGame;
extern s16 D_80100702_CraneGame;
extern CGShadowOrder* D_80100704_CraneGame;
extern s16 D_80100708_CraneGame[33];
extern s16 D_8010074A_CraneGame;
extern s16 D_8010074C_CraneGame;
extern CGCol D_80100750_CraneGame[64];
extern s16 D_80100A50_CraneGame;
extern s16 D_80100A52_CraneGame;
extern unk2C0C0StructA0* D_80100A54_CraneGame;
extern f32 D_80100A58_CraneGame;
extern s16 D_80100A5C_CraneGame;
extern s16 D_80100A5E_CraneGame;
extern s16 D_80100A60_CraneGame;
extern s16 D_80100A62_CraneGame;
extern s16 D_80100A64_CraneGame;
extern s16 D_80100A66_CraneGame;
extern s16 D_80100A68_CraneGame;
extern f32 D_80100A6C_CraneGame[3];
extern f32 D_80100A78_CraneGame[3];
extern f32 D_80100A84_CraneGame;
extern f32 D_80100A88_CraneGame[3];
extern f32 D_80100A94_CraneGame[3];
extern f32 D_80100AA0_CraneGame[3];
extern f32 D_80100AAC_CraneGame;
extern f32 D_80100AB0_CraneGame[3];
extern f32 D_80100AC0_CraneGame[16][4];
extern CGClaw* D_80100BC0_CraneGame[256];
extern s16 D_80100FC0_CraneGame;
extern omObjData* D_80100FD0_CraneGame;

/* ---------------------------------------------------------------------------------------------
   Overlay functions
   --------------------------------------------------------------------------------------------- */

/* 1B3E00 */
void func_800F65E0_CraneGame(void);
void func_800F6B10_CraneGame(omObjData*);
void func_800F6B3C_CraneGame(void);
void func_800F6EC4_CraneGame(void);
void func_800F6EF0_CraneGame(void);
void func_800F6F54_CraneGame(omObjData*);
void func_800F6FCC_CraneGame(omObjData*);
CGClaw* func_800F704C_CraneGame(omObjData*);
void func_800F7138_CraneGame(void);
CGClaw* func_800F71B8_CraneGame(omObjData*);
s32 func_800F71E4_CraneGame(omObjData*);
s16 func_800F7290_CraneGame(f32);
s16 func_800F746C_CraneGame(f32*, f32*, f32*, f32, f32, f32, f32, s16);
void func_800F77A8_CraneGame(omObjData*);
void func_800F7964_CraneGame(omObjData*);
s16 func_800F7A88_CraneGame(f32, f32, f32, f32);
s16 func_800F7CC8_CraneGame(f32, f32, f32, s16);
void func_800F7DD0_CraneGame(omObjData*);
void func_800F82D4_CraneGame(omObjData*);
s32 func_800F9464_CraneGame(omObjData*, Vec*);
void func_800F96D8_CraneGame(s16, Vec*);
s16 func_800F97D4_CraneGame(omObjData*);
void func_800F9C94_CraneGame(omObjData*);
f32 func_800F9EEC_CraneGame(f32, f32);
void func_800F9FAC_CraneGame(f32 (*)[4], Vec*);
void func_800FA154_CraneGame(omObjData*);
void func_800FA684_CraneGame(omObjData*, s16);
void func_800FA770_CraneGame(omObjData*);
void func_800FB08C_CraneGame(omObjData*);
void func_800FB3A8_CraneGame(omObjData*);
void func_800FB674_CraneGame(void);
void func_800FB73C_CraneGame(void);
void func_800FB800_CraneGame(s32, s32);

/* 1B9050 */
void func_800FB830_CraneGame(void);
void func_800FB8E8_CraneGame(void);
void func_800FB9C4_CraneGame(s16);
void func_800FBA78_CraneGame(s16, f32);
void func_800FBAE8_CraneGame(f32);
void func_800FBB00_CraneGame(f32, f32, f32);
void func_800FBB18_CraneGame(Gfx**, Mtx*, camera*);
Gfx* func_800FC0A0_CraneGame(Gfx*, unk2C0C0StructC0*, Matrix4f);
void func_800FC4F4_CraneGame(s16);
void func_800FC800_CraneGame(unk2C0C0Struct30*, unk2C0C0StructA0*, s16);
void func_800FC9B0_CraneGame(void);
void func_800FCB78_CraneGame(Gfx**, unk2C0C0StructC0*);
Gfx* func_800FCD7C_CraneGame(Gfx*, u8 (*)[4], s16);
Gfx* func_800FCF78_CraneGame(Gfx*, Mtx*);

/* 1BAA60 */
void func_800FD240_CraneGame(void);
void func_800FD278_CraneGame(void);
void func_800FD37C_CraneGame(s16);
void func_800FD3D0_CraneGame(Gfx**, Mtx*, camera*);
void func_800FD604_CraneGame(CGCol*, s16);
void func_800FD7B4_CraneGame(unk2C0C0StructA0*, CGColFace*, unk2C0C0Struct20*, s16);
void func_800FDBF8_CraneGame(Matrix4f, f32, f32, f32, Vec*);
s32 func_800FDC94_CraneGame(Vec*, f32, f32, f32, s16);
s32 func_800FDF54_CraneGame(Vec*, Vec*, f32);
void func_800FE0A4_CraneGame(CGColFace*, s16, Vec*, Vec*);
f32 func_800FE518_CraneGame(f32, f32);
void func_800FE598_CraneGame(Vec*, Vec*);
void func_800FE620_CraneGame(void);
void func_800FE658_CraneGame(void);
void func_800FE7A0_CraneGame(void);
void func_800FE7AC_CraneGame(s16);
void func_800FE7B8_CraneGame(s16, s16);
void func_800FE80C_CraneGame(f32, f32, f32, f32);
void func_800FE874_CraneGame(void);
void func_800FEB08_CraneGame(void);

#endif
