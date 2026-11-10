#ifndef HOTROPEJUMP_H
#define HOTROPEJUMP_H

/* ovl_2E HotRopeJump (4P): one unit, 207040.c. A flaming rope (a chain of 13 flame models,
   D_80100854) turns and the four players jump it; the first player it touches loses.
   Types come from the asm's accesses; N64 offsets are in the comments. */

#include "common.h"
#include "sprite65770.h"
#include "PR/gu.h"

/* A billboard slot D_80103298[D_801004C4] (func_800F8E74 takes one, func_800F9080 builds its
   display list every frame into D_801004D8/D_801004E4, func_800FA2F4 draws it). The pointer fields
   shift every later field on the host: use names, never offsets. */
typedef struct HRJFx {
    /* 0x00 */ Gfx* dl;      /* (Gfx*)-1 = free, NULL = nothing this frame */
    /* 0x04 */ void** unk_04; /* used when unk_08 != 0 ([2 + frame] is a segment); nothing sets it */
    /* 0x08 */ s8 unk_08;
    /* 0x09 */ char unk_09;
    /* 0x0A */ u16 sprite;   /* D_800EC700 index */
    /* 0x0C */ s16 frame;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ u8 flags;     /* 1 no animation, 2 hold, 4 hide at end, 0x10 hidden, 0x18 filter,
                                0x20 free at end */
    /* 0x11 */ u8 a;
    /* 0x12 */ u8 r;
    /* 0x13 */ u8 g;
    /* 0x14 */ u8 b;
    /* 0x15 */ char unk_15[3];
    /* 0x18 */ f32 timer;
    /* 0x1C */ f32 speed;
    /* 0x20 */ Vec pos;
    /* 0x2C */ Vec scale;
} HRJFx; /* size = 0x38 (N64) */

/* A player's rope state (D_80100328_HotRopeJump[4]; omObjData::work holds a pointer to it on the
   N64, see func_800F8C68). No pointers. */
typedef struct HRJPlayer {
    /* 0x00 */ s16 unk_00; /* 1: hit by the rope */
    /* 0x02 */ u16 state;  /* 1 stand, 2 jump, 4 land, 8 hit, 0x10 win, 0x20 lose */
    /* 0x04 */ char unk_04[4];
    /* 0x08 */ s16 speed;  /* walk speed in the intro */
    /* 0x0A */ char unk_0A[6];
    /* 0x10 */ Vec home;
    /* 0x1C */ Vec hit;
    /* 0x28 */ char unk_28[0xC];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ char unk_38[4];
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ s16 intro;  /* intro walk step */
    /* 0x42 */ s16 unk_42;
    /* 0x44 */ s16 unk_44;
    /* 0x46 */ s16 unk_46;
    /* 0x48 */ char unk_48[0x18];
} HRJPlayer; /* size = 0x60 */

/* A player's work (obj->unk_50, allocated by func_8000979C): MgWork's layout (src/99E0.c, 0xE8);
   its pointers sit where MgWork's do. */
typedef struct HRJPlayerWork {
    /* 0x00 */ char unk_00[0x38];
    /* 0x38 */ f32 unk_38; /* vertical speed; 1000 on the ground */
    /* 0x3C */ f32 unk_3C; /* facing */
    /* 0x40 */ char unk_40[0x16];
    /* 0x56 */ u8 unk_56;  /* controller port */
    /* 0x57 */ char unk_57;
    /* 0x58 */ s8 unk_58;  /* player */
    /* 0x59 */ char unk_59[0x5F];
    /* 0xB8 */ void* unk_B8;
    /* 0xBC */ char unk_BC[0x1C];
    /* 0xD8 */ void* unk_D8; /* motion table */
    /* 0xDC */ void* unk_DC; /* collision callback */
    /* 0xE0 */ char unk_E0[4];
    /* 0xE4 */ void* unk_E4;
} HRJPlayerWork; /* size = 0xE8 (N64) */

/* A rope light (D_80100538_HotRopeJump[32]): lights the floor grid (func_800FB6B4). */
typedef struct HRJLight {
    /* 0x00 */ s16 used;
    /* 0x02 */ s16 x;
    /* 0x04 */ s16 y;
    /* 0x06 */ s16 z;
    /* 0x08 */ s32 radius;
    /* 0x0C */ f32 aspect;
    /* 0x10 */ s32 radiusSq;
} HRJLight; /* size = 0x14 */

/* A flame model: the rope's 13 (D_80100854) and the two torches (D_80100850), both
   func_80023684(0xD68) blocks of 13 (the torch block uses 2). */
typedef struct HRJSeg {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec dir;   /* rope: the segment to the next one */
    /* 0x18 */ Vec vel;
    /* 0x24 */ Vec base;
    /* 0x30 */ f32 angle; /* rope turn angle */
    /* 0x34 */ f32 size;
    /* 0x38 */ s16 light;
    /* 0x3A */ s16 model;
    /* 0x3C */ u16 anim;
    /* 0x3E */ u16 state;
    /* 0x40 */ s16 timer;
    /* 0x42 */ s16 delay;
    /* 0x44 */ char unk_44[4];
    /* 0x48 */ Mtx mtx[3];
} HRJSeg; /* size = 0x108 */

/* ---------------------------------------------------------------------------------------------
   Main code
   --------------------------------------------------------------------------------------------- */

extern unk65770Anim* D_800EC700[];
extern omObjData* D_800F2AF8[];
extern u16 D_800EE984;
extern s32 D_800EDEC0;
extern s16 D_800EE32E;
extern u8 D_800F64F8;
extern u16 ContBtn[];
extern f32 D_800B8964;
extern f32 D_800B8968;
extern f32 D_800B8980;
extern f32 D_800B8994;
extern HRJFx* D_80103298; /* main-code bss; other overlays give it their own type */

void func_8002ADF0(s32*, s32);
void func_800093FC(omObjData*, f32, f32, f32);
void func_800090C4(omObjData* obj, u8 idx, u8 val);
void func_80017C0C(omObjData*, u8, f32, f32, f32, f32, f32);
void func_80017B4C(s16);
s32 func_80017A60(omObjData*);
void func_80060F04(s16, s16, s16, s16);
s32 func_80024198(u32, Gfx*, s32);
s16 func_8002451C(u32, void*, s32);
unk65770Anim* func_80067310(s16);
void MtxRotate(Matrix4f, f32, f32, f32);
void func_80023A38(void*, void*, s32);
void func_8001D658(s32, Gfx**);
void func_80011A30(s32);

/* ---------------------------------------------------------------------------------------------
   Overlay
   --------------------------------------------------------------------------------------------- */

void func_800F65E0_HotRopeJump(void);
void func_800F69A4_HotRopeJump(omObjData* obj);
void func_800F6C50_HotRopeJump(omObjData* obj);
void func_800F6C9C_HotRopeJump(omObjData* obj);
void func_800F6D30_HotRopeJump(omObjData* obj);
void func_800F6DC4_HotRopeJump(omObjData* obj);
void func_800F6E58_HotRopeJump(omObjData* obj);
void func_800F6EEC_HotRopeJump(omObjData* obj, s32 player);
void func_800F7210_HotRopeJump(omObjData* obj);
void func_800F7F14_HotRopeJump(omObjData* obj);
void func_800F8968_HotRopeJump(f32 x, f32 y, f32 z);
s32 func_800F8A14_HotRopeJump(omObjData* obj);
void func_800F8C08_HotRopeJump(void);
void func_800F8C68_HotRopeJump(omObjData* obj, HRJPlayer* p);
HRJPlayer* func_800F8C88_HotRopeJump(omObjData* obj);
void func_800F8CB4_HotRopeJump(u8 count);
s16 func_800F8E74_HotRopeJump(s16 sprite, u8 flags);
void func_800F8F04_HotRopeJump(s16 id, f32 speed);
void func_800F8F2C_HotRopeJump(s16 id, f32 x, f32 y, f32 z);
void func_800F8F5C_HotRopeJump(s16 id, f32 x, f32 y, f32 z);
void func_800F8F8C_HotRopeJump(s16 id, u8 flags);
void func_800F8FBC_HotRopeJump(s16 id, u8 r, u8 g, u8 b, s32 a);
void func_800F8FF4_HotRopeJump(s16 id);
void func_800F9080_HotRopeJump(void);
void func_800FA2F4_HotRopeJump(void);
void func_800FA60C_HotRopeJump(void);
void func_800FA6AC_HotRopeJump(f32 zoom, f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz);
void func_800FA734_HotRopeJump(f32 zoom, f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz, u16 frames);
void func_800FA7B8_HotRopeJump(f32 zoom, f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz);
void func_800FA914_HotRopeJump(void);
void func_800FA978_HotRopeJump(void);
void func_800FA9DC_HotRopeJump(omObjData* obj);
void func_800FAB34_HotRopeJump(s32 cam, Vec* pos, Vec* out);
void func_800FADDC_HotRopeJump(s32 cam, Vec* pos, Vec* out, f32 sx, f32 sy);
void func_800FB260_HotRopeJump(void);
void func_800FB328_HotRopeJump(void);
void func_800FB354_HotRopeJump(f32 angle);
void func_800FB494_HotRopeJump(omObjData* obj);
void func_800FB4E0_HotRopeJump(omObjData* obj);
s16 func_800FB504_HotRopeJump(f32 x, f32 y, f32 z, f32 radius);
void func_800FB5CC_HotRopeJump(s16 id, f32 x, f32 y, f32 z);
void func_800FB638_HotRopeJump(s16 id, f32 radius, f32 h);
void func_800FB690_HotRopeJump(s16 id);
void func_800FB6B4_HotRopeJump(Gfx** gfx);
s16 func_800FBABC_HotRopeJump(void);
void func_800FC0B4_HotRopeJump(omObjData* obj);
void func_800FC428_HotRopeJump(omObjData* obj);
void func_800FCAC0_HotRopeJump(omObjData* obj);
void func_800FCE98_HotRopeJump(omObjData* obj);
s16 func_800FD90C_HotRopeJump(const Vtx_t* vtx, unk65770Anim* tex, unk65770Anim* anim);
void func_800FDFC4_HotRopeJump(HRJSeg* seg, const Vtx_t* vtx, unk65770Anim* anim);
void func_800FE38C_HotRopeJump(void);
void func_800FE39C_HotRopeJump(void);
void func_800FE3A8_HotRopeJump(f32 speed);
void func_800FE3B4_HotRopeJump(Matrix4f m, f32 x, f32 y, f32 z, Vec* out);

/* .data */
extern s32 D_800FE450_HotRopeJump; /* jumps to win */
extern s32 D_800FE454_HotRopeJump; /* game state */
extern s16 D_800FE458_HotRopeJump; /* someone was hit / all in place */
extern s32 D_800FE45C_HotRopeJump; /* the player hit, -1 none */
extern u16 D_800FE460_HotRopeJump; /* CPU players (bits) */
extern s32 D_800FE464_HotRopeJump[4];
extern s32 D_800FE474_HotRopeJump[4];
extern f32 D_800FE484_HotRopeJump;
extern s32 D_800FE488_HotRopeJump; /* _CheckFlag(0x2B) */
extern s32 D_800FE48C_HotRopeJump[4][2]; /* sprite positions (read as s16) */
extern f32 D_800FE4AC_HotRopeJump[4];
extern omObjData* D_800FE4BC_HotRopeJump;
extern s32 D_800FE4C0_HotRopeJump;
extern s32 D_800FE4C8_HotRopeJump; /* jumps */
extern s32 D_800FE4CC_HotRopeJump; /* frames per turn */
extern f32 D_800FE4D0_HotRopeJump;
extern f32 D_800FE4D4_HotRopeJump;
extern s32 D_800FE4D8_HotRopeJump;
extern s32 D_800FE4DC_HotRopeJump;
extern u16 D_800FE4E0_HotRopeJump[4];
extern u16 D_800FE4E8_HotRopeJump;
extern s16 D_800FE4EC_HotRopeJump[10];

/* .rodata (written: retail keeps these two state pairs there) */
typedef struct HRJSeq {
    /* 0x00 */ s16 state;
    /* 0x02 */ s16 timer;
} HRJSeq;
extern HRJSeq D_800FE6E0_HotRopeJump;  /* torch/camera intro */
extern const s16 D_800FE6E4_HotRopeJump[8]; /* its state durations, 0 = last */
typedef struct HRJSeq2 {
    /* 0x00 */ s16 timer;
    /* 0x02 */ s16 state;
} HRJSeq2;
extern HRJSeq2 D_800FE784_HotRopeJump; /* rope */
extern const s16 D_800FE788_HotRopeJump[4]; /* its state durations */

extern const Gfx D_800FE610_HotRopeJump[]; /* the floor's setup list */
extern const Vtx_t D_800FE650_HotRopeJump[9]; /* torch flame */
extern const Vtx_t D_800FE6F4_HotRopeJump[9]; /* rope flame */

/* .bss */
extern Mtx D_800FEB10_HotRopeJump[3][32];
extern f32 D_80100310_HotRopeJump;
extern f32 D_80100314_HotRopeJump;
extern f32 D_80100318_HotRopeJump;
extern f32 D_8010031C_HotRopeJump;
extern omObjData* D_80100320_HotRopeJump;
extern s32 D_80100324_HotRopeJump; /* frame buffer index, 0..2 */
extern HRJPlayer D_80100328_HotRopeJump[4];
extern s16 D_801004A8_HotRopeJump;
extern s32 D_801004AC_HotRopeJump; /* sprite ids: s32 slots read as s16 (low half) */
extern s32 D_801004B0_HotRopeJump;
extern s32 D_801004B4_HotRopeJump;
extern f32 D_801004BC_HotRopeJump;
extern f32 D_801004C0_HotRopeJump;
extern s32 D_801004C4_HotRopeJump; /* billboard slots */
extern Gfx* D_801004C8_HotRopeJump[3];
extern s32 D_801004D4_HotRopeJump; /* billboard model */
extern Gfx* D_801004D8_HotRopeJump[3];
extern Vtx* D_801004E4_HotRopeJump[3];
extern Vec D_801004F0_HotRopeJump;
extern Vec D_801004FC_HotRopeJump;
extern Vec D_80100508_HotRopeJump;
extern Vec D_80100514_HotRopeJump;
extern f32 D_80100520_HotRopeJump;
extern f32 D_80100524_HotRopeJump;
extern s16 D_80100528_HotRopeJump;
extern s16 D_8010052A_HotRopeJump;
extern s16 D_80100530_HotRopeJump;
extern HRJLight D_80100538_HotRopeJump[32];
extern s16 D_801007B8_HotRopeJump;
extern s16 D_801007BA_HotRopeJump;
extern s16 D_801007BC_HotRopeJump;
extern Gfx* D_801007C0_HotRopeJump;
extern s16 D_801007C4_HotRopeJump;
extern f32 D_801007C8_HotRopeJump;
extern s16 D_801007CC_HotRopeJump;
extern s16 D_801007CE_HotRopeJump;
extern s16 D_801007D0_HotRopeJump;
extern s16 D_801007D2_HotRopeJump;
extern Matrix4f D_801007D8_HotRopeJump;
extern Vec D_80100818_HotRopeJump;
extern Vec D_80100824_HotRopeJump;
extern Vec D_80100830_HotRopeJump;
extern Vec D_8010083C_HotRopeJump;
extern f32 D_80100848_HotRopeJump;
extern f32 D_8010084C_HotRopeJump;
extern HRJSeg* D_80100850_HotRopeJump; /* torches */
extern HRJSeg* D_80100854_HotRopeJump; /* rope */

#endif
