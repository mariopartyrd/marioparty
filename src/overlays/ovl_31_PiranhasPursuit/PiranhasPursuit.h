#ifndef PIRANHASPURSUIT_H
#define PIRANHASPURSUIT_H

/* ovl_31 PiranhasPursuit (1 vs 3): the solo player runs right along a side-scrolling course
   (222320.c); a giant Piranha Plant chases from the left. The three others watch from the
   shore and throw coins at the end. 225DF0.c builds the course (obstacles, water, the plant).
   Types come from the asm's accesses; N64 offsets are in the comments. */

#include "common.h"
#include "sprite65770.h"
#include "PR/gu.h"

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* A player's state (D_80100CE0_PiranhasPursuit[4], 0x60 each). On the N64 the player object's
   omObjData::work holds a big-endian pointer to it; the host keeps the index there. No pointers. */
typedef struct PPPlayer {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2; /* flags: 1 running, 2 on a log, 4 caught, 8 eaten */
    /* 0x04 */ char unk4[0x18];
    /* 0x1C */ f32 unk1C; /* plant model position */
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ char unk28[0xC];
    /* 0x34 */ f32 unk34; /* plant model rotation */
    /* 0x38 */ f32 unk38;
    /* 0x3C */ f32 unk3C;
    /* 0x40 */ s16 unk40;
    /* 0x42 */ s16 unk42;
    /* 0x44 */ s16 unk44;
    /* 0x46 */ s16 unk46;
    /* 0x48 */ char unk48[0x18];
} PPPlayer; /* size = 0x60 */

/* A player object's work (func_8000979C: 0xE8 bytes, MgWork's layout; main code reads it). */
typedef struct PPWork {
    /* 0x00 */ char unk_00[0x38];
    /* 0x38 */ f32 unk_38; /* vertical speed */
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40; /* forward speed */
    /* 0x44 */ char unk_44[0xC];
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ char unk_52[4];
    /* 0x56 */ s8 unk_56; /* controller port */
    /* 0x57 */ char unk_57;
    /* 0x58 */ s8 unk_58; /* player */
    /* 0x59 */ char unk_59[0x59];
    /* 0xB2 */ s8 unk_B2;
    /* 0xB3 */ s8 unk_B3; /* sound handle */
    /* 0xB4 */ char unk_B4[4];
    /* 0xB8 */ void* unk_B8;
    /* 0xBC */ char unk_BC[0x1C];
    /* 0xD8 */ void* unk_D8; /* motion table */
    /* 0xDC */ void* unk_DC;
    /* 0xE0 */ char unk_E0[4];
    /* 0xE4 */ void* unk_E4;
} PPWork; /* size = 0xE8 */

#define PP_WORK(obj) ((PPWork*)(obj)->unk_50)

/* A coin thrown at the end (D_80100E68_PiranhasPursuit[15], 0x28 each). */
typedef struct PPCoin {
    /* 0x00 */ s16 sprite;
    /* 0x02 */ s16 state;
    /* 0x04 */ s16 timer;
    /* 0x06 */ s16 sound;
    /* 0x08 */ f32 vy;
    /* 0x0C */ f32 vx;
    /* 0x10 */ f32 x;
    /* 0x14 */ f32 y;
    /* 0x18 */ f32 z;
    /* 0x1C */ char unk1C[0xC];
} PPCoin; /* size = 0x28 */

/* A course piece or a background tree (D_8010112C_PiranhasPursuit: 25 pieces,
   D_80101124_PiranhasPursuit: 14 trees; 0x3C each). Types: 1 rock, 2 falling tree, 3 stump,
   4 log on the water, 5 goal, 6 start. */
typedef struct PPPiece {
    /* 0x00 */ s16 unk0; /* active; logs: 2 ridden, 3 sinking, 4 gone */
    /* 0x02 */ s16 unk2; /* type */
    /* 0x04 */ f32 unk4; /* radius */
    /* 0x08 */ s16 unk8;
    /* 0x0A */ char unkA[2];
    /* 0x0C */ f32 unkC;
    /* 0x10 */ Vec pos;
    /* 0x1C */ Vec rot;
    /* 0x28 */ Vec scale;
    /* 0x34 */ f32 unk34; /* collision x */
    /* 0x38 */ f32 unk38; /* collision y */
} PPPiece; /* size = 0x3C */

/* The Piranha Plant's state (D_80101150_PiranhasPursuit; retail also names its fields
   D_80101152 .. D_8010117E). anim[] holds each model's motion (start, end, loop end). */
typedef struct PPPlant {
    /* 0x000 */ s16 unk0;
    /* 0x002 */ s16 state;
    /* 0x004 */ char unk4[0xC];
    /* 0x010 */ f32 unk10; /* vertical speed */
    /* 0x014 */ f32 unk14; /* x */
    /* 0x018 */ f32 unk18; /* lunge offset */
    /* 0x01C */ f32 unk1C; /* lunge target */
    /* 0x020 */ s16 timer;
    /* 0x022 */ s16 unk22;
    /* 0x024 */ f32 unk24; /* scale to grow to */
    /* 0x028 */ f32 unk28; /* scale */
    /* 0x02C */ s16 unk2C; /* current motion */
    /* 0x02E */ s16 unk2E; /* growing */
    /* 0x030 */ char unk30[0x118];
    /* 0x148 */ s16 anim[7][3];
    /* 0x172 */ char unk172[2];
} PPPlant; /* size = 0x174 */

/* A rain drop (D_80101120_PiranhasPursuit: 64 of them, 0x80 each): a line per frame buffer. */
typedef struct PPDrop {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 state; /* 1 falling, 0 bouncing */
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 z;
    /* 0x10 */ f32 vx;
    /* 0x14 */ f32 vy;
    /* 0x18 */ f32 len;
    /* 0x1C */ f32 depth;
    /* 0x20 */ Vtx v[3][2];
} PPDrop; /* size = 0x80 */

/* A splash sprite (D_80101138_PiranhasPursuit: 32 of them, 0x18 each). */
typedef struct PPSplash {
    /* 0x00 */ s16 sprite;
    /* 0x02 */ s16 state;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ char unk6[2];
    /* 0x08 */ f32 x;
    /* 0x0C */ f32 y;
    /* 0x10 */ f32 z;
    /* 0x14 */ s16 life;
    /* 0x16 */ s16 life0;
} PPSplash; /* size = 0x18 */

/* func_8002040C's result (src/1EA70.c unk1EA70StructC). */
typedef struct PPAnimMtx {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16* unk_04;
    /* 0x08 */ Matrix4f* unk_08;
} PPAnimMtx;

/* ---------------------------------------------------------------------------------------------
   Data (.data)
   --------------------------------------------------------------------------------------------- */
extern s32 D_801001F0_PiranhasPursuit; /* game state */
extern s16 D_801001F4_PiranhasPursuit;
extern s32 D_801001F8_PiranhasPursuit;
extern f32 D_801001FC_PiranhasPursuit; /* scroll x */
extern f32 D_80100200_PiranhasPursuit;
extern f32 D_80100204_PiranhasPursuit;
extern f32 D_80100208_PiranhasPursuit;
extern s32 D_8010020C_PiranhasPursuit; /* the solo player */
extern s32 D_80100210_PiranhasPursuit;
extern s32 D_80100214_PiranhasPursuit;
extern f32 D_80100218_PiranhasPursuit;
extern s32 D_8010021C_PiranhasPursuit; /* _CheckFlag(0x2B) */
extern f32 D_80100220_PiranhasPursuit;
extern s32 D_80100224_PiranhasPursuit; /* camera timer; retail also reads its low half */
extern const char* D_80100228_PiranhasPursuit[6];
extern s32 D_80100240_PiranhasPursuit;
extern s32 D_80100244_PiranhasPursuit;
extern s32 D_80100248_PiranhasPursuit;
extern f32 D_8010024C_PiranhasPursuit;
extern u32 D_80100250_PiranhasPursuit; /* random seed */

extern u32 D_80100260_PiranhasPursuit; /* random seed; retail also reads its low half */
extern s32 D_801003E8_PiranhasPursuit;
extern f32 D_801003EC_PiranhasPursuit;
extern f32 D_801003F0_PiranhasPursuit;
extern s16 D_801003F4_PiranhasPursuit[2];
extern f32 D_801003F8_PiranhasPursuit;
extern u16 D_801003FC_PiranhasPursuit;
extern f32 D_80100400_PiranhasPursuit;
extern s16 D_80100404_PiranhasPursuit;
extern s16 D_80100406_PiranhasPursuit;
extern s16 D_80100408_PiranhasPursuit;
extern s16 D_8010040A_PiranhasPursuit;
extern s16 D_8010040C_PiranhasPursuit;
extern s16 D_8010040E_PiranhasPursuit;

extern const char D_801004B0_PiranhasPursuit[];
extern const char D_801004BC_PiranhasPursuit[];
extern const char D_801004C8_PiranhasPursuit[];
extern const char D_801004D4_PiranhasPursuit[];
extern const char D_801004E0_PiranhasPursuit[];
extern const char D_801004EC_PiranhasPursuit[];

/* ---------------------------------------------------------------------------------------------
   Bss
   --------------------------------------------------------------------------------------------- */
extern PPPiece* D_80100CA0_PiranhasPursuit;
extern f32 D_80100CA4_PiranhasPursuit;
extern s32 D_80100CA8_PiranhasPursuit;
extern f32 D_80100CAC_PiranhasPursuit; /* saved D_800B89xx tuning, restored on exit */
extern f32 D_80100CB0_PiranhasPursuit;
extern f32 D_80100CB4_PiranhasPursuit;
extern f32 D_80100CB8_PiranhasPursuit;
extern f32 D_80100CBC_PiranhasPursuit;
extern f32 D_80100CC0_PiranhasPursuit;
extern f32 D_80100CC4_PiranhasPursuit;
extern f32 D_80100CC8_PiranhasPursuit;
extern f32 D_80100CCC_PiranhasPursuit;
extern f32 D_80100CD0_PiranhasPursuit;
extern f32 D_80100CD4_PiranhasPursuit;
extern omObjData* D_80100CD8_PiranhasPursuit;
extern s32 D_80100CDC_PiranhasPursuit;
extern PPPlayer D_80100CE0_PiranhasPursuit[4];
/* Labels inside D_80100CE0: [0].unk1C, and [n].unk40. */
#define D_80100CFC_PiranhasPursuit (D_80100CE0_PiranhasPursuit[0].unk1C)
#define D_80100D20_PiranhasPursuit (D_80100CE0_PiranhasPursuit[0].unk40)
#define D_80100D40_PiranhasPursuit (D_80100CE0_PiranhasPursuit[1])
#define D_80100D80_PiranhasPursuit (D_80100CE0_PiranhasPursuit[1].unk40)
#define D_80100DA0_PiranhasPursuit (D_80100CE0_PiranhasPursuit[2])
#define D_80100DE0_PiranhasPursuit (D_80100CE0_PiranhasPursuit[2].unk40)
#define D_80100E00_PiranhasPursuit (D_80100CE0_PiranhasPursuit[3])
#define D_80100E40_PiranhasPursuit (D_80100CE0_PiranhasPursuit[3].unk40)
extern s16 D_80100E60_PiranhasPursuit;
/* func_800174C0's u16 model kept as s32; retail reads its low half (D_80100E66). */
extern s32 D_80100E64_PiranhasPursuit;
#define D_80100E66_PiranhasPursuit ((s16)D_80100E64_PiranhasPursuit)
extern PPCoin D_80100E68_PiranhasPursuit[15];
extern Vec D_801010C0_PiranhasPursuit; /* camera move: center from */
extern Vec D_801010CC_PiranhasPursuit; /* center to */
extern Vec D_801010D8_PiranhasPursuit; /* rotation from */
extern Vec D_801010E4_PiranhasPursuit; /* rotation to */
extern f32 D_801010F0_PiranhasPursuit; /* zoom from */
extern f32 D_801010F4_PiranhasPursuit; /* zoom to */
extern s16 D_801010F8_PiranhasPursuit; /* frames left */
extern u16 D_801010FA_PiranhasPursuit; /* frames */
extern omObjData* D_80101100_PiranhasPursuit;
extern omObjData* D_80101104_PiranhasPursuit; /* background */
extern omObjData* D_80101108_PiranhasPursuit; /* the plant */
extern omObjData* D_8010110C_PiranhasPursuit; /* the runner it chases */
extern omObjData* D_80101110_PiranhasPursuit; /* rain; work[0]: splash frames */
extern Gfx* D_80101114_PiranhasPursuit[3];
extern PPDrop* D_80101120_PiranhasPursuit;
extern PPPiece* D_80101124_PiranhasPursuit;
extern s16 D_80101128_PiranhasPursuit[2];
extern PPPiece* D_8010112C_PiranhasPursuit;
extern s16* D_80101130_PiranhasPursuit; /* course models: 5 originals, then one per piece */
extern s16 D_80101134_PiranhasPursuit; /* the goal piece */
extern PPSplash* D_80101138_PiranhasPursuit;
extern s16 D_8010113C_PiranhasPursuit;
/* Splash offset x, y, z, then the plant's grow step: one f32[4] that retail also addresses by
   its splat labels; the host has only the array. */
extern f32 D_80101140_PiranhasPursuit[4];
extern f32 D_80101144_PiranhasPursuit;
extern f32 D_80101148_PiranhasPursuit;
extern f32 D_8010114C_PiranhasPursuit;
extern PPPlant D_80101150_PiranhasPursuit;
extern s16 D_8010117C_PiranhasPursuit; /* D_80101150.unk2C */
extern PPAnimMtx* D_801012C4_PiranhasPursuit;
extern s16 D_801012C8_PiranhasPursuit; /* 1: runner caught, 2: done */
extern s16 D_801012CA_PiranhasPursuit; /* plant reached the goal */
extern s16 D_801012CC_PiranhasPursuit;
extern f32 D_801012D0_PiranhasPursuit;
extern f32 D_801012D4_PiranhasPursuit;
extern f32 D_801012D8_PiranhasPursuit;
extern f32 D_801012DC_PiranhasPursuit;
extern f32 D_801012E0_PiranhasPursuit;
extern u16 D_801012E4_PiranhasPursuit;
extern u16 D_801012E6_PiranhasPursuit;
extern s16 D_801012E8_PiranhasPursuit;
extern s16 D_801012EA_PiranhasPursuit;
extern s16 D_801012F0_PiranhasPursuit[5]; /* sprite files */

/* ---------------------------------------------------------------------------------------------
   Main code
   --------------------------------------------------------------------------------------------- */
extern s32 D_800EDEC0;
extern u16 D_800EE984;
extern u8 D_800F64F8;
extern omObjData* D_800F2AF8[];
extern u16 ContBtn[];
extern s8 ContStkY[];
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
extern f32 D_800B8990;
extern f32 D_800B8994;

void func_800090C4(omObjData* obj, u8 idx, u8 val);
void func_800093FC(omObjData*, f32, f32, f32);
s32 func_80017A60(omObjData*);
void func_80017BB0(omObjData*);
void func_80017C0C(omObjData*, u8, f32, f32, f32, f32, f32);
s32 func_800185A4(omObjData*, u16);
void func_80027AC8(s16, u8*, u8*);
void func_80060F04(s16, s16, s16, s16);
void func_80066DF4(s16, s16, s16, f32, f32, f32);
void func_80067284(s16, s16, f32);
s32 func_80067328(s16, s16);
f64 func_8009B618(f64, f64);
f32 func_80025D40(s16);
void func_800670C4(s16, s16, s16, f32, f32, f32);
s16 func_80024198(s32, void*, s32);
PPAnimMtx* func_8002040C(s16, s16, char*);
void func_80020CC4(PPAnimMtx*);
void MtxRotateX(Matrix4f mtx, f32 angle);

/* ---------------------------------------------------------------------------------------------
   Overlay functions
   --------------------------------------------------------------------------------------------- */
void func_800F6AA8_PiranhasPursuit(omObjData* obj);
void func_800F6B74_PiranhasPursuit(omObjData* obj);
void func_800F6BB0_PiranhasPursuit(omObjData* obj);
void func_800F6C78_PiranhasPursuit(f32 x);
void func_800F6C84_PiranhasPursuit(omObjData* obj);
void func_800F70D0_PiranhasPursuit(omObjData* obj);
void func_800F7158_PiranhasPursuit(omObjData* obj);
void func_800F71F0_PiranhasPursuit(omObjData* obj);
void func_800F7298_PiranhasPursuit(omObjData* obj);
void func_800F7320_PiranhasPursuit(omObjData* obj, s32 player);
void func_800F782C_PiranhasPursuit(omObjData* obj, s32 player);
void func_800F7AA0_PiranhasPursuit(omObjData* obj);
void func_800F8114_PiranhasPursuit(omObjData* obj);
void func_800F9854_PiranhasPursuit(omObjData* obj);
void func_800F9BF0_PiranhasPursuit(void);
void func_800F9CBC_PiranhasPursuit(omObjData* obj, PPPlayer* p);
PPPlayer* func_800F9CDC_PiranhasPursuit(omObjData* obj);
void func_800F9D08_PiranhasPursuit(void);
u32 func_800F9D40_PiranhasPursuit(void);
void func_800F9D78_PiranhasPursuit(f32 zoom, f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz);
void func_800F9E00_PiranhasPursuit(f32 zoom, f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz, u16 frames);
void func_800F9E84_PiranhasPursuit(void);
void func_800F9EE8_PiranhasPursuit(void);
void func_800F9F4C_PiranhasPursuit(omObjData* obj); /* obj unused */

void func_800FA0B0_PiranhasPursuit(void);
void func_800FA168_PiranhasPursuit(omObjData* obj);
void func_800FA1B8_PiranhasPursuit(omObjData* obj);
void func_800FA1E4_PiranhasPursuit(void);
u16 func_800FA218_PiranhasPursuit(u16 n);
f32 func_800FA288_PiranhasPursuit(f32 target, f32 cur, f32 step);
void func_800FA3F0_PiranhasPursuit(s16 model, omObjData* obj);
void func_800FA480_PiranhasPursuit(omObjData* dst, omObjData* src);
void func_800FA4CC_PiranhasPursuit(omObjData* obj);
void func_800FA508_PiranhasPursuit(s16 model, s16 i, PPPlant* p, s16 end);
void func_800FA5DC_PiranhasPursuit(s16 model, s16* anim, s16 dir);
void func_800FA684_PiranhasPursuit(s16 model, s16* anim, s16 dir);
void func_800FA740_PiranhasPursuit(s16 model);
void func_800FA7C0_PiranhasPursuit(u16 frames);
void func_800FA7E0_PiranhasPursuit(void);
void func_800FA7E8_PiranhasPursuit(void);
void func_800FA878_PiranhasPursuit(omObjData* obj);
void func_800FAEE8_PiranhasPursuit(omObjData* obj);
void func_800FB590_PiranhasPursuit(void);
void func_800FB5C8_PiranhasPursuit(f32 x);
void func_800FB5D4_PiranhasPursuit(s16* models);
void func_800FBB98_PiranhasPursuit(s16* models, PPPiece* p, f32 x, s16 type, s16 i);
void func_800FBE00_PiranhasPursuit(s16* models);
PPPiece* func_800FC3F4_PiranhasPursuit(f32 x, f32 y);
s16 func_800FC4D0_PiranhasPursuit(omObjData* obj);
PPPiece* func_800FC52C_PiranhasPursuit(omObjData* obj);
s16 func_800FC5A8_PiranhasPursuit(omObjData* obj);
void func_800FC5F0_PiranhasPursuit(void);
void func_800FC638_PiranhasPursuit(omObjData* obj);
void func_800FC7F0_PiranhasPursuit(omObjData* obj);
void func_800FC9C4_PiranhasPursuit(Gfx* g, PPDrop* d, u16 frame);
void func_800FCABC_PiranhasPursuit(PPDrop* d);
void func_800FCE78_PiranhasPursuit(PPDrop* d, u16 frame);
void func_800FD4BC_PiranhasPursuit(f32 x, f32 y);
void func_800FD674_PiranhasPursuit(void);
void func_800FD6EC_PiranhasPursuit(void);
void func_800FD728_PiranhasPursuit(omObjData* obj);
void func_800FD9D0_PiranhasPursuit(omObjData* obj);
void func_800FEF78_PiranhasPursuit(omObjData* obj, s16 anim, s16 fwd);
void func_800FF0C0_PiranhasPursuit(omObjData* obj);
s16 func_800FF35C_PiranhasPursuit(omObjData* obj);
void func_800FF450_PiranhasPursuit(void);
void func_800FF470_PiranhasPursuit(omObjData* runner, omObjData* plant);
void func_800FF730_PiranhasPursuit(omObjData* obj);
void func_800FFB28_PiranhasPursuit(omObjData* obj);
u16 func_800FFBD8_PiranhasPursuit(s32 file);
void func_800FFC1C_PiranhasPursuit(void);
s32 func_800FFCD8_PiranhasPursuit(u16 type, f32 x, f32 y, f32 z, u16 life);
void func_801000A8_PiranhasPursuit(void);
void func_801001C8_PiranhasPursuit(void);

#endif
