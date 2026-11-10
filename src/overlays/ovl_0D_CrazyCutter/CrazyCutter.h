#include "common.h"
#include "engine/esprite.h"

typedef struct CrazyCutterPoint {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
} CrazyCutterPoint;

/* One player's cutter state (omObjData.unk_50 of the func_800F731C_CrazyCutter objects). */
typedef struct CrazyCutterPlayer {
    /* 0x000 */ f32 x;
    /* 0x004 */ f32 y;
    /* 0x008 */ f32 z;
    /* 0x00C */ f32 prevX;
    /* 0x010 */ f32 prevZ;
    /* 0x014 */ f32 rotX;
    /* 0x018 */ f32 rotY;
    /* 0x01C */ f32 rotZ;
    /* 0x020 */ f32 velX;
    /* 0x024 */ f32 angle;
    /* 0x028 */ s32 unk28;
    /* 0x02C */ f32 unk2C;
    /* 0x030 */ s32 player;
    /* 0x034 */ s32 moving;
    /* 0x038 */ s32 trailX[60]; /* last positions, newest first */
    /* 0x128 */ s32 trailY[60];
    /* 0x218 */ s32 visitedX[60]; /* distinct positions (30 used) */
    /* 0x308 */ s32 visitedY[60];
    /* 0x3F8 */ s32 unk3F8;
    /* 0x3FC */ s32 unk3FC;
    /* 0x400 */ s32 unk400;
    /* 0x404 */ f32 startX;
    /* 0x408 */ f32 startZ;
    /* 0x40C */ f32 velZ;
    /* 0x410 */ s32 timer;
    /* 0x414 */ s32 state;
    /* 0x418 */ s16 unk418;
    /* 0x41A */ s16 unk41A;
    /* 0x41C */ s32 difficulty;
    /* 0x420 */ s32 visitedCount;
    /* 0x424 */ s32 pathX[30]; /* CPU route (-3: start, -2: end) */
    /* 0x49C */ s32 pathY[30];
    /* 0x514 */ s32 target;
    /* 0x518 */ s32 unk518;
} CrazyCutterPlayer; /* sizeof 0x51C */

/* One falling piece (omObjData.unk_50 of the func_800F9968_CrazyCutter objects). */
typedef struct CrazyCutterPiece {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
    /* 0x0C */ f32 rotX;
    /* 0x10 */ f32 rotY;
    /* 0x14 */ f32 rotZ;
    /* 0x18 */ f32 scaleX;
    /* 0x1C */ f32 scaleY;
    /* 0x20 */ f32 scaleZ;
    /* 0x24 */ s32 player;
    /* 0x28 */ s32 timer;
    /* 0x2C */ f32 velY;
    /* 0x30 */ s32 state;
    /* 0x34 */ f32 angle;
    /* 0x38 */ f32 dist;
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ u16 alpha; /* retail passes its low byte (lbu 0x41) */
} CrazyCutterPiece; /* sizeof 0x44 */

/* A piece's shadow model (D_800FD4E8_CrazyCutter[player]). Splat split it into D_800FD4E8 (the
   word), D_800FD4EA (its low half, which retail reads as the s16 model id), D_800FD4EC, D_800FD4F0;
   C uses only the struct. */
typedef struct CrazyCutterShadow {
    /* 0x00 */ s32 model;
    /* 0x04 */ f32 scale;
    /* 0x08 */ f32 unk8;
} CrazyCutterShadow; /* sizeof 0xC */

/* An expanding/shrinking cut ring (omObjData.unk_50 of the func_800FB778_CrazyCutter objects).
   The N64 allocation is 0x1C bytes; the host's is sizeof (the mask pointer is 8 bytes there). */
typedef struct CrazyCutterRing {
    /* 0x00 */ s32 player;
    /* 0x04 */ f32 radius;
    /* 0x08 */ f32 step;
    /* 0x0C */ f32 end;
    /* 0x10 */ s32 width;
    /* 0x14 */ u8* mask;
    /* 0x18 */ s32 frame;
} CrazyCutterRing;

extern u8 D_800F64F8;
extern s8 ContStkX[];
extern s8 ContStkY[];
void func_80025BB8(s16, s16);
void func_80039644(s16, u8, u8);
void func_80060F04(s16 player, s16 arg1, s16 arg2, s16 arg3);
f32 func_80025D18(s16);
f32 func_80025D40(s16);

void func_800F731C_CrazyCutter(omObjData* obj, s32 player);
void func_800F8144_CrazyCutter(omObjData*);
void func_800F8598_CrazyCutter(omObjData*);
s32 func_800F8F74_CrazyCutter(CrazyCutterPlayer* st, s16* cur);
void func_800F8FDC_CrazyCutter(CrazyCutterPlayer* st, s16* cur);
void func_800F90E4_CrazyCutter(omObjData*);
f32 func_800F9530_CrazyCutter(CrazyCutterPlayer* st);
void func_800F9694_CrazyCutter(Vec3f* arg0, s16 arg1[], s32 arg2);
void func_800F98B4_CrazyCutter(CrazyCutterPlayer* st);
void func_800F9968_CrazyCutter(omObjData* obj, s32 player);
s32 func_800FA38C_CrazyCutter(s32 player);
f32 func_800FAC38_CrazyCutter(s16* from, s16* to, s32 mode);
f32 func_800FAF8C_CrazyCutter(Vec3f* from, Vec3f* to, s32 mode);
f32 func_800FAB0C_CrazyCutter(f32 x);
void func_800F9D98_CrazyCutter(omObjData*);
void func_800FAA18_CrazyCutter(omObjData*);
void func_800FA808_CrazyCutter(omObjData*);
void func_800FB2B8_CrazyCutter(s32 sprite, s32 player);
void func_800FB450_CrazyCutter(s32);
void func_800FB548_CrazyCutter(s32);
void func_800FB778_CrazyCutter(omObjData*);
void func_800FB640_CrazyCutter(omObjData* parent, s32 sprite, s32 sprite2, s32 player);
s32 func_800FB944_CrazyCutter(CrazyCutterPlayer* st);
s16 func_800FBAFC_CrazyCutter(s32 idx);
s32 func_800FBEA8_CrazyCutter(s16 grpIdx, s32 idx, s32 x, s32 y);

void func_800F6938_CrazyCutter(f32, f32, f32, f32, f32, f32, f32);
void func_800F9654_CrazyCutter(omObjData*);
void func_800F69EC_CrazyCutter(omObjData*);
void func_800F6F00_CrazyCutter(omObjData*);
void func_800F7180_CrazyCutter(omObjData*);
void func_800FBFB4_CrazyCutter(void);
s16 func_800FC024_CrazyCutter(s16, s16);
void func_800FC240_CrazyCutter(s16);
void func_800FC29C_CrazyCutter(s16 grp, s16 value);
void func_800FC45C_CrazyCutter(s16, s16);

extern s8 D_800FCD10_CrazyCutter[12];
extern s8 D_800FCD1C_CrazyCutter[4];
extern s32 D_800FCD20_CrazyCutter[6];
extern s32 D_800FCD38_CrazyCutter[6];
extern s32 D_800FCD50_CrazyCutter[6];
extern s32 D_800FCD68_CrazyCutter[6];
extern s32 D_800FCD80_CrazyCutter[6];
extern s32 D_800FCD98_CrazyCutter[6];
extern s32 D_800FCDB0_CrazyCutter[6];
extern s32 D_800FCDC8_CrazyCutter[6];
extern s32 D_800FCDE0_CrazyCutter[6];
extern s32 D_800FCDF8_CrazyCutter[31];
extern s32 D_800FCE74_CrazyCutter[47];
extern s32 D_800FCF30_CrazyCutter[27];
extern s32 D_800FCF9C_CrazyCutter[3];
extern s16 D_800FCFA8_CrazyCutter[4][2];

/* .bss */
extern u16 ContBtn[4]; /* engine/pad.h */
extern s32* D_800FD130_CrazyCutter;
extern s32 D_800FD134_CrazyCutter;
extern f32 D_800FD138_CrazyCutter;
extern s32 D_800FD13C_CrazyCutter;
extern f32 D_800FD140_CrazyCutter;
extern f32 D_800FD144_CrazyCutter;
extern s32 D_800FD148_CrazyCutter;
extern s16 D_800FD14C_CrazyCutter;
extern u16 D_800FD152_CrazyCutter;
extern u16 D_800FD154_CrazyCutter;
extern s8 D_800FD156_CrazyCutter[4];
extern s8 D_800FD160_CrazyCutter[4];
extern s8 D_800FD170_CrazyCutter[80];
extern s32 D_800FD1C0_CrazyCutter[80];
extern s32 D_800FD300_CrazyCutter[80];
extern s32 D_800FD440_CrazyCutter[4];
extern s32 D_800FD450_CrazyCutter[4];
extern s32 D_800FD470_CrazyCutter[4];
extern s32 D_800FD480_CrazyCutter;
extern s32 D_800FD498_CrazyCutter;
extern s32 D_800FD49C_CrazyCutter;
extern u8* D_800FD4A0_CrazyCutter[4];
extern s32 D_800FD4B8_CrazyCutter[4];
extern s32 D_800FD4C8_CrazyCutter[4];
extern CrazyCutterShadow D_800FD4E8_CrazyCutter[4];
extern s32 D_800FD534_CrazyCutter;
extern s16 D_800FD540_CrazyCutter;
extern s16 D_800FD542_CrazyCutter;
extern f32 D_800FD53C_CrazyCutter;
extern s32 D_800FD548_CrazyCutter;
extern s16 D_800FD54A_CrazyCutter;
extern s32 D_800FD54C_CrazyCutter;
extern s32 D_800FD550_CrazyCutter;
extern s16 D_800FD588_CrazyCutter[4];
extern s16 D_800FD592_CrazyCutter[4];
extern s16 D_800FD59A_CrazyCutter;
extern omObjData* D_800FD5A0_CrazyCutter[4];
extern s16 D_800FD5B0_CrazyCutter;
extern s16 D_800FD5B2_CrazyCutter[4];
extern s16 D_800FD5BA_CrazyCutter;
extern s16 D_800FD5BC_CrazyCutter;
extern s16 D_800FD5C4_CrazyCutter;
extern s16 D_800FD5CA_CrazyCutter;
extern s16 D_800FD5C2_CrazyCutter;

void func_800FBB2C_CrazyCutter(void);
void func_800FBB94_CrazyCutter(omObjData*);
void func_800FA880_CrazyCutter(omObjData*);
void func_800FA56C_CrazyCutter(omObjData*);
void func_800F68C4_CrazyCutter(omObjData*);
void func_800F978C_CrazyCutter(void);
void func_800F97C8_CrazyCutter(omObjData*);
s32 func_800FAAB0_CrazyCutter(s32, s32);
void func_800FAACC_CrazyCutter(s32, s32, s32);
void func_800FA9D8_CrazyCutter(omObjData*);
void func_800F686C_CrazyCutter(omObjData*);
void func_800F6B04_CrazyCutter(omObjData*);
void func_800F94C0_CrazyCutter(omObjData*);
void func_800F94DC_CrazyCutter(omObjData*);
void func_800F94F8_CrazyCutter(omObjData*);
void func_800F9514_CrazyCutter(omObjData*);
u8* func_800FC4F0_CrazyCutter(s16 grpIdx, s16 idx, s32* width, s32* height);
s32 func_800FC70C_CrazyCutter(s16 grpIdx, s16 idx, s32 x0, s32 y0, s32 w, s32 h, s8* mask);
s32 func_800FC8C0_CrazyCutter(s16 grpIdx, s16 idx, s32 x, s32 y);
s32 func_800FC998_CrazyCutter(u32 arg0, s32 arg1, u32 arg2, u8* arg3, s32 arg4);
s32 func_800FC9F4_CrazyCutter(s32 arg0, s32 arg1, s32 arg2, u8* arg3, u8 arg4);
s32 func_800FCA20_CrazyCutter(u8* pal, u16 fmt);
s32 func_800FCAAC_CrazyCutter(s16 grpIdx, s16 idx, s32 x0, s32 y0, s32 w, s32 h, s8* mask);
s32 func_800FCC64_CrazyCutter(u32 arg0, s32 arg1, u32 arg2, u8* arg3, s32 arg4);
s32 func_800FCCC8_CrazyCutter(s32 arg0, s32 arg1, s32 arg2, u8* arg3, u8 arg4);
s32 D_800FCCC4_CrazyCutter(s32 arg0, s32 arg1, s32 arg2, u8* arg3, u8 arg4); /* a nop before func_800FCCC8 */
#define CC_FUNC_800FCCC4 D_800FCCC4_CrazyCutter
extern s16 D_800FD5C0_CrazyCutter;
extern u8* D_800FD51C_CrazyCutter;
extern s32 D_800FD528_CrazyCutter;
extern s32 D_800FD52C_CrazyCutter;
extern s32 D_800FD538_CrazyCutter;
extern u8* D_800FD518_CrazyCutter;
extern s32 D_800FD520_CrazyCutter;
extern s32 D_800FD524_CrazyCutter;
extern s32 D_800FD530_CrazyCutter;
extern s32 D_800FD4D8_CrazyCutter[];
extern u16 D_800FD590_CrazyCutter;
extern f32 D_800FCCF0_CrazyCutter[];
extern f32 D_800FCD00_CrazyCutter[];
extern s32 D_800FD488_CrazyCutter[];
extern f32 D_800FD558_CrazyCutter[];
extern f32 D_800FD568_CrazyCutter[];
extern f32 D_800FD578_CrazyCutter[];
extern s16 D_800FD5C8_CrazyCutter;
extern u16 D_800FD14E_CrazyCutter;
extern u16 D_800FD150_CrazyCutter;
extern s16 D_800FD5C6_CrazyCutter;
extern s16 D_800FD544_CrazyCutter;
extern s32 D_800FD554_CrazyCutter;
extern s32 D_800FD460_CrazyCutter;
extern s32 D_800FD464_CrazyCutter;
extern s32 D_800FD468_CrazyCutter;
extern s32 D_800FD4B0_CrazyCutter;
