#include "common.h"

/* Course piece (D_800FCDB4): tiles appended to the tile map. */
typedef struct PPPiece {
/* 0x00 */ s32 count;
/* 0x04 */ u8 tiles[80];
} PPPiece; /* sizeof 0x54 */

/* Course entry (D_800FD2A0) and piece template (D_800FD6D8). */
typedef struct PPPlatform {
/* 0x00 */ s32 type;  /* 0 ends the list */
/* 0x04 */ s32 state; /* falling platforms */
/* 0x08 */ void (*func)(omObjData*);
/* 0x0C */ Vec pos;
/* 0x18 */ Vec ofs;   /* model[1] offset; templates: item x range, -, item z offset */
} PPPlatform; /* sizeof 0x24 on the N64 */

/* Item on the course (D_800FD8F4). */
typedef struct PPItem {
/* 0x00 */ s32 type; /* 0 ends the list */
/* 0x04 */ void (*func)(omObjData*);
/* 0x08 */ Vec pos;
/* 0x14 */ s32 unk_14[4];
} PPItem; /* sizeof 0x24 on the N64 */

/* Platform object work (func_800F7868). */
typedef struct PPPlatWork {
/* 0x00 */ u8 unk_00[4];
/* 0x04 */ u8 unk_04;
/* 0x05 */ u8 index; /* into D_800FD2A0 */
/* 0x06 */ u8 unk_06[0x26];
} PPPlatWork; /* sizeof 0x2C */

/* Item object work (func_800F8C2C), the layout func_800091BC uses. */
typedef struct PPItemWork {
/* 0x00 */ u8 unk_00[0x24];
/* 0x24 */ u8 unk_24;
/* 0x25 */ u8 unk_25[0xF];
/* 0x34 */ f32 unk_34;
/* 0x38 */ f32 unk_38;
/* 0x3C */ f32 unk_3C;
/* 0x40 */ f32 unk_40;
/* 0x44 */ f32 unk_44;
/* 0x48 */ f32 unk_48;
/* 0x4C */ f32 unk_4C;
/* 0x50 */ u16 unk_50;
/* 0x52 */ u8 unk_52;
/* 0x53 */ u8 unk_53;
/* 0x54 */ u8 unk_54;
/* 0x55 */ u8 unk_55[7];
/* 0x5C */ s32 unk_5C;
/* 0x60 */ s32 unk_60;
/* 0x64 */ s32 unk_64[2];
} PPItemWork; /* sizeof 0x6C */

/* Camera path key (D_800FDD74, D_800FDED4): a path ends at a key with zoom <= 0. */
typedef struct PPCamKey {
/* 0x00 */ f32 zoom;
/* 0x04 */ Vec center;
/* 0x10 */ Vec rot;
/* 0x1C */ f32 time;  /* frames to the next key */
/* 0x20 */ u8 event;  /* 1: message, 2: sound */
} PPCamKey; /* sizeof 0x24 */

/* Winner sparks (D_800FE300). */
typedef struct PPSpark {
/* 0x00 */ s16 model;
/* 0x02 */ s16 sprite;
/* 0x04 */ s16 unk_04[3];
/* 0x0A */ s16 angle;
/* 0x0C */ s16 speed;
/* 0x0E */ s16 life;
/* 0x10 */ s16 active;
/* 0x12 */ s16 unk_12;
/* 0x14 */ s16 unk_14;
/* 0x18 */ f32 x;
/* 0x1C */ f32 y;
/* 0x20 */ f32 z;
} PPSpark; /* sizeof 0x24 */

//extern s32 D_800F2B7C;
/* Per player (indexed by the work's unk_58): 0 run, 1 falling, 2 goal, 3 out; -1 inactive. */
typedef struct PPPlayerState {
    s32 state;
    f32 fall; /* fall speed */
} PPPlayerState;
extern PPPlayerState D_800FE1B0_PlatformPeril[4];
extern s32 D_800FE2A0_PlatformPeril[];
void func_800FAD64_PlatformPeril(omObjData*);
void func_800F66E8_PlatformPeril(void);
void func_800F6720_PlatformPeril(omObjData*);
s32 func_800FC95C_PlatformPeril(void);
void func_800F7070_PlatformPeril(PPPlatform*);
void func_800F8C2C_PlatformPeril(omObjData*);
void func_800F94EC_PlatformPeril(omObjData*);
void func_800F9598_PlatformPeril(omObjData*);
void func_800F9644_PlatformPeril(omObjData*);
void func_800F96F0_PlatformPeril(omObjData*);
void func_800F6F68_PlatformPeril(void);
void func_800F76E4_PlatformPeril(void);
void func_800F8B7C_PlatformPeril(void);
void func_800F90C0_PlatformPeril(void);
void func_800FC1DC_PlatformPeril(void);
void func_800FC8E4_PlatformPeril(void);
void func_800F7868_PlatformPeril(omObjData*);
void func_800F6790_PlatformPeril(void);

extern s8 D_800B8955;
extern omObjData* D_800F3FB0[];
extern f32 D_800FCDA0_PlatformPeril;
extern s32 D_800FE2B0_PlatformPeril[5]; /* 1: player reached the goal */
extern omObjData* D_800EDE70[];
extern u16 D_800EE984;
extern PPItem D_800FD8F4_PlatformPeril[];
extern s32 D_800FE250_PlatformPeril;
extern omObjData* D_800FE1D8_PlatformPeril[];
extern PPCamKey D_800FDD74_PlatformPeril[];
extern s32 D_800FCD90_PlatformPeril;
extern s32 D_800FE2F8_PlatformPeril;
extern f32 D_800B895C;
extern PPPlatform D_800FD2A0_PlatformPeril[];
extern s32 D_800FE1D0_PlatformPeril;
extern s32 D_800FE1D4_PlatformPeril;
extern s32 D_800FE258_PlatformPeril[];


void func_80025BB8(s16, s16);
s32 func_800F6DF4_PlatformPeril(void);
s32 func_800F6E14_PlatformPeril(void);
void func_800FC17C_PlatformPeril(void);
void func_800FC8D4_PlatformPeril(void);
void func_800FC8DC_PlatformPeril(void);
void func_800FCB10_PlatformPeril(omObjData*);
s32 func_800FCBD4_PlatformPeril(void);
void func_800FCD44_PlatformPeril(void);
void func_800FCD50_PlatformPeril(u32);
void func_800FCD5C_PlatformPeril(void);

extern s32 D_800FCD94_PlatformPeril;
extern s32 D_800FCD98_PlatformPeril;
extern s32 D_800FE1A0_PlatformPeril;
extern s32 D_800FE2C4_PlatformPeril;
extern s32 D_800FE2C8_PlatformPeril; /* winner's player index, -1 none */
extern f32 D_800FE2CC_PlatformPeril;
extern s32 D_800FE2FC_PlatformPeril;
extern omObjData* D_800FE540_PlatformPeril[4]; /* player objects */

s32 func_800FADC8_PlatformPeril(omObjData*);
s32 func_800FAE7C_PlatformPeril(s32);
f32 func_800FAE8C_PlatformPeril(f32);
f32 func_800FAEC0_PlatformPeril(f32);
s32 func_800FAF58_PlatformPeril(f32, f32);
s32 func_800FAFA0_PlatformPeril(s32);
f32 func_800FB028_PlatformPeril(omObjData*, s32*);
f32 func_800FB3B0_PlatformPeril(omObjData*);
void func_800FB3E8_PlatformPeril(void);
s32 func_800FB544_PlatformPeril(s32);
void func_800FB60C_PlatformPeril(s32*, s32*);
s32 func_800FB620_PlatformPeril(omObjData*);
void func_800FB680_PlatformPeril(omObjData*);
void func_800FBC38_PlatformPeril(f32, f32, f32, s32*, s32*, s32*);
void func_800FBCD4_PlatformPeril(omObjData*);
void func_800FBFB0_PlatformPeril(omObjData*);
void func_800FC000_PlatformPeril(omObjData*);
s16 func_800FC438_PlatformPeril(s32, s32, s32);
void func_800FC48C_PlatformPeril(f32, f32, f32);
void func_800FC648_PlatformPeril(void);
void func_800FAAE0_PlatformPeril(f32, PPCamKey*, PPCamKey*);
void func_800FAD30_PlatformPeril(void);
void func_8001E2A8(s16, u16);

extern u16 ContBtn[4];
extern s8 ContStkY[4];
extern f32 D_800FDD40_PlatformPeril[4];
extern s32 D_800FDD50_PlatformPeril[4];
extern s32 D_800FDD60_PlatformPeril[4];
extern s32 D_800FDD70_PlatformPeril;
extern PPCamKey* D_800FDEB8_PlatformPeril;
extern s32 D_800FDEBC_PlatformPeril;
extern f32 D_800FDEC0_PlatformPeril;
extern PPCamKey* D_800FDEC4_PlatformPeril;
extern s32 D_800FDEC8_PlatformPeril;
extern s32 D_800FDECC_PlatformPeril;
extern s32 D_800FDED0_PlatformPeril;
extern PPCamKey D_800FDED4_PlatformPeril[];
extern f32 D_800FDF40_PlatformPeril;
extern PPCamKey* D_800FDF44_PlatformPeril;
extern s32 D_800FDF48_PlatformPeril;

extern void* D_800FE270_PlatformPeril;
extern s16 D_800FE274_PlatformPeril;
extern s16 D_800FE276_PlatformPeril;
extern s32 D_800FE280_PlatformPeril;
extern f32 D_800FE288_PlatformPeril[6];
extern s32 D_800FE2D8_PlatformPeril[4];
extern s32 D_800FE2E8_PlatformPeril[4];
extern PPSpark D_800FE300_PlatformPeril[16];
extern f32 D_800FE550_PlatformPeril[4][4]; /* last stick angles per CPU player */
extern s32 D_800FE590_PlatformPeril[4];    /* players ranked by layer */
extern f32 D_800FE5A0_PlatformPeril[4];    /* layer per player */
extern u8 D_800FE5B0_PlatformPeril[][12];  /* tile map, 12 columns per layer */

void func_800F6F60_PlatformPeril(void);
void func_800F8AE8_PlatformPeril(omObjData*);
void func_800F815C_PlatformPeril(omObjData*);
void func_800F8220_PlatformPeril(omObjData*);
void func_800F87A0_PlatformPeril(omObjData*);
void func_800F922C_PlatformPeril(omObjData*, s32, s32, u16, f32, f32, f32);
void func_800091BC(omObjData*, s32, s32, s32);
void func_800090C4(omObjData*, u8, u8);
extern omObjData* D_800F2AF8[];
extern PPPiece D_800FCDB4_PlatformPeril[15];
extern PPPlatform D_800FD6D8_PlatformPeril[15];
typedef struct PPOrder6 {
    s32 v[6];
} PPOrder6;
typedef struct PPKinds3 {
    s32 v[3];
} PPKinds3;
extern const s32 D_800FDFB8_PlatformPeril[6];
extern const s32 D_800FDFD0_PlatformPeril[4];
void func_800F979C_PlatformPeril(omObjData*);
