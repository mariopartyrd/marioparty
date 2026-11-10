#include "common.h"
#include "sprite65770.h"

/* One movable face part (0x28 bytes): its home position, its model slot and the box it may be
 * dragged in (D_800FC4B0_FaceLift[8]: six parts, then the two models drawn from the eyes). */
typedef struct FaceLiftPart {
/* 0x00 */ f32 x;
/* 0x04 */ f32 y;
/* 0x08 */ s16 model;
/* 0x0A */ s16 unk_0A;
/* 0x0C */ f32 left;
/* 0x10 */ f32 top;
/* 0x14 */ f32 right;
/* 0x18 */ f32 bottom;
/* 0x1C */ s16 count;    /* vertices within radius (func_800FA374_FaceLift) */
/* 0x1E */ s16 unk_1E;
/* 0x20 */ s16* verts;   /* their indices, heap-allocated at runtime */
/* 0x24 */ f32 radius;
} FaceLiftPart; // sizeof 0x28

typedef struct FaceLiftPos {
    s16 x;
    s16 y;
} FaceLiftPos;

/* Per-player work (func_80023684(0xE0, ...), omObjData.unk_50). */
typedef struct FaceLiftWork {
/* 0x00 */ u16 sprite;
/* 0x02 */ s16 grab;
/* 0x04 */ u16 sel;
/* 0x06 */ s16 sndOn;
/* 0x08 */ s16 moving[6];
/* 0x14 */ s16 snd;
/* 0x18 */ Vec3f pos;
/* 0x24 */ Vec3f pts[6];
/* 0x6C */ char unk_6C[0x18];
/* 0x84 */ s16 order[6];
/* 0x90 */ s16 cpuState;
/* 0x92 */ s16 cpuIdx;
/* 0x94 */ s16 cpuTimer;
/* 0x96 */ s16 cpuRounds;
/* 0x98 */ Vec3f cpuTarget[6];
} FaceLiftWork; // sizeof 0xE0

void func_800F9B38_FaceLift(omObjData*);
s16 func_8002451C(s32, void*, s32);
void func_80025830(s16, f32, f32, f32);
void func_800258EC(s16, s32, s32);
void func_80025F10(s16, s32);
void func_800F80A4_FaceLift(omObjData*, s32);
void func_800FA374_FaceLift(s16, s16);
void func_800F8FCC_FaceLift(omObjData*);
void func_800F9988_FaceLift(Gfx**);
void func_800FAA38_FaceLift(omObjData*);
void func_800FACD8_FaceLift(Gfx**, s32);

extern s32 D_800FCA18_FaceLift; /* 64-byte aligned colour buffer in a heap block */
extern u16 D_800FC3D0_FaceLift;
extern u16 D_800F5144;
extern s16 D_800FC960_FaceLift;
extern FaceLiftPart D_800FC4B0_FaceLift[8];
extern Vec3f D_800FC980_FaceLift[6];
extern f32 D_800FC9F0_FaceLift[2];
extern s16 D_800FCA1E_FaceLift;
extern s16 D_800FCA28_FaceLift;
extern s16 D_800FCA2A_FaceLift;

/* The rising stars of the winner screen (func_80023684(0x1C, ...)). */
typedef struct FaceLiftStar {
/* 0x00 */ f32 x;
/* 0x04 */ f32 y;
/* 0x08 */ f32 z;
/* 0x0C */ f32 angle;
/* 0x10 */ f32 h;
/* 0x14 */ s16 id;
/* 0x16 */ s16 count;
/* 0x18 */ s16 timer;
} FaceLiftStar; // sizeof 0x1C

/* Sparkle particles (func_80023684(0x294, ...)). */
typedef struct FaceLiftFx {
/* 0x00 */ s16 unk_00;
/* 0x02 */ s16 player;
/* 0x04 */ u16 alpha;
/* 0x06 */ s16 unk_06;
/* 0x08 */ f32 x;
/* 0x0C */ f32 y;
/* 0x10 */ f32 z;
/* 0x14 */ f32 unk_14;
/* 0x18 */ f32 vy;
/* 0x1C */ s16 model;
/* 0x1E */ s16 unk_1E;
} FaceLiftFx; // sizeof 0x20

typedef struct FaceLiftFxWork {
/* 0x000 */ FaceLiftFx fx[20];
/* 0x280 */ u8 state[20];
} FaceLiftFxWork; // sizeof 0x294

/* .data */
extern u16 D_800FC3D2_FaceLift;
extern Vec3f D_800FC3D8_FaceLift[5];
extern Vec3f D_800FC414_FaceLift[5];
extern Vec4f D_800FC450_FaceLift[5];
extern FaceLiftPos D_800FC4A0_FaceLift[4];
extern Vec2f D_800FC5F0_FaceLift[8 * 6];
extern s32 D_800FC770_FaceLift[3];
extern s32 D_800FC77C_FaceLift[];
extern const char* D_800FC7AC_FaceLift[6];
extern f32 D_800FC7C4_FaceLift[4];
extern FaceLiftPos D_800FC7D4_FaceLift[4];

/* .bss */
extern s16 D_800FC962_FaceLift;
extern s16 D_800FC964_FaceLift;
extern s8 D_800FC966_FaceLift;
extern Vec3f D_800FC968_FaceLift;
extern Vec3f D_800FC974_FaceLift;
extern s16 D_800FC9C8_FaceLift;
extern s16 D_800FC9CA_FaceLift[4];
extern omObjData* D_800FC9D8_FaceLift[4];
extern omObjData* D_800FC9E8_FaceLift;
extern omObjData* D_800FC9EC_FaceLift;
extern s16 D_800FC9FA_FaceLift[4];
extern s16 D_800FCA0A_FaceLift;
extern s16 D_800FCA0C_FaceLift;
extern s16 D_800FCA0E_FaceLift[4];

void func_800F65E0_FaceLift(void);
void func_800F6974_FaceLift(omObjData*);
void func_800F6B88_FaceLift(FaceLiftWork*, f32);
void func_800F6DBC_FaceLift(omObjData*);
void func_800F7444_FaceLift(s16, FaceLiftWork*);
void func_800F7D58_FaceLift(s16, FaceLiftWork*, Vec2f*, u16*, u16*);
void func_800F8204_FaceLift(omObjData*);
void func_800F8274_FaceLift(omObjData*);
void func_800F8378_FaceLift(omObjData*);
void func_800F84B4_FaceLift(omObjData*);
void func_800F8DC8_FaceLift(omObjData*);
void func_800F9AD4_FaceLift(omObjData*);
void func_800F9EE4_FaceLift(omObjData*);
void func_800FA9DC_FaceLift(omObjData*);
void func_800FB608_FaceLift(omObjData*);
void func_800FBE08_FaceLift(void);
s16 func_800FBE78_FaceLift(s16, s16);
void func_800FC094_FaceLift(s16);
void func_800F99E8_FaceLift(Vec3f*, Vec3f*, s16, s16);
void func_800FA5B4_FaceLift(s16, s16, Vec3f*);
void func_800FA7D0_FaceLift(s16, s16, Vec3f*);
void func_800FB0BC_FaceLift(s16);
void func_800FC39C_FaceLift(s16, s16, s16);
extern s8 D_800F384E;
s32 func_800FA058_FaceLift(s16, Vec3f*);
void func_800FB858_FaceLift(s16, f32, f32, f32, u16);
void func_80060F04(s16, s16, s16, s16);
void func_80060440(s16, s16);
void func_800F8588_FaceLift(omObjData*);
void func_800F8608_FaceLift(omObjData*);
void func_800F8660_FaceLift(omObjData*);
void func_800F86AC_FaceLift(omObjData*);
void func_800F8A98_FaceLift(omObjData*);
void func_800F8CE0_FaceLift(omObjData*);
void func_800F8D5C_FaceLift(omObjData*);
void func_800F9058_FaceLift(omObjData*);
void func_800F91C0_FaceLift(omObjData*);
void func_800FAA64_FaceLift(omObjData*);
s16 func_800FB9E8_FaceLift(void);
void func_800FC14C_FaceLift(s16, s16);
void func_800FC30C_FaceLift(s16, s16);
void GMesPosSet(s16, f32, f32);
void GMesMaxTimeGet(s16, s16);
s16 func_80060758(s16);
void func_800F9800_FaceLift(omObjData*);
extern s16 D_800FC9F8_FaceLift;
extern s16 D_800FCA02_FaceLift[4];
void func_800F9BC8_FaceLift(void);
extern Gfx D_800FC7E8_FaceLift[];
extern Gfx D_800FC830_FaceLift[];
extern Gfx D_800FC870_FaceLift[];
void func_8003A060(Gfx**, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_800FACB8_FaceLift(Gfx**);
void func_800FAB24_FaceLift(omObjData*);
void func_800FAEE0_FaceLift(s32);
void func_800FB1B4_FaceLift(omObjData*);
void func_800FB29C_FaceLift(omObjData*);
void func_800FB724_FaceLift(omObjData*);
u16 func_8001E1D0(s16, s32);
void func_8001E268(s16, u8, u8);
extern s16 D_800FC3D4_FaceLift;
extern s16 D_800FC9D2_FaceLift;
extern s16 D_800FCA1C_FaceLift;
extern s16 D_800FCA20_FaceLift[4];
void func_80023888(void*);
