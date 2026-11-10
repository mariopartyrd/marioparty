#include "common.h"

extern s8 D_800B8955;
extern f32 D_800B895C;
extern s32 D_800B899C;
extern omObjData* D_800EDE70[];
extern u16 D_800EE984;
extern omObjData* D_800F2AF8[];
extern omObjData* D_800F3FB0[];
extern f32 D_800F33F0;
extern u32 D_800F9490_TestingRoom;
extern u32 D_800F9494_TestingRoom;
extern s32 D_800F9498_TestingRoom;
extern u32 D_800F949C_TestingRoom;
extern s32 D_800F94A0_TestingRoom;
extern f32 D_800F94A4_TestingRoom;
extern f32 D_800F94D0_TestingRoom;
extern f32 D_800F94D4_TestingRoom;
extern s16 ContBtn[];
extern u8 D_800F32E4;

extern u8 D_800B8954;
extern f32 D_800B8960;
extern f32 D_800B8964;
extern f32 D_800B8968;
extern f32 D_800B8984;
extern f32 D_800B8988;
extern f32 D_800B8990;
extern f32 D_800ED6B8;
extern f32 D_800F5254;

/* Work of the test room's balls and players (obj->unk_50): the leading 0x6C bytes of the
   main-code player work (no pointers there, so host offsets agree). */
typedef struct TRWork {
    /* 0x00 */ char unk_00[0x34];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38; /* vertical speed; >= 1000 on the ground */
    /* 0x3C */ f32 unk_3C; /* heading */
    /* 0x40 */ f32 unk_40; /* speed */
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48; /* radius */
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50; /* flags */
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ u8 unk_53; /* ground id (unkGlobalStruct_02.unk_05), 0xFF none */
    /* 0x54 */ u8 unk_54;
    /* 0x55 */ char unk_55[3];
    /* 0x58 */ f32 unk_58;
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ s32 unk_60;
    /* 0x64 */ char unk_64[8];
} TRWork; /* size = 0x6C */

/* Retail tests the big-endian word at 0x50 (flags, unk_52, unk_53) in one load. */
#define TR_WORD50(w) (*(u32*)&(w)->unk_50)

typedef struct TRColVtx {
    s16 x, y, z;
} TRColVtx;

typedef struct TRColTri {
    s16 flags;
    s16 v[3];
} TRColTri;

void func_800090C4(omObjData*, u8, u8);
void func_800093FC(omObjData*, f32, f32, f32);
void func_800090D8(omObjData*, u8, u8);
f32 func_80029518(f32);
s32 func_80004D1C(omObjData*, Vec4f*, f32);
f32 func_800051D4(omObjData*, f32, f32, f32, Vec3f*);
f32 func_80029764(f32, f32, f32, TRColVtx*, TRColTri*);
void func_800295FC(TRColVtx*, TRColVtx*, TRColVtx*, Vec3f*);
void func_8002AE24(s16, s32*, void*, void*);
TRColTri* func_8002B3A8(s32*);
s32 func_8002956C(Vec3f*);
void func_80037178(s16, Vec3f*);
s16 func_80010C4C(s16);
s32 func_80002060(void*, s16*, void*, Vec3f*);

void func_800F72DC_TestingRoom(omObjData*, s32, s32, s32, f32, f32, f32);
void func_800F7690_TestingRoom(omObjData*, s32, f32, f32, f32, s32);
void func_800F77BC_TestingRoom(omObjData*, s32, f32, f32, s32, s32);
void func_800F9400_TestingRoom(omObjData*);
void func_800F7EDC_TestingRoom(omObjData*);
void func_800F6A44_TestingRoom(void);
void func_800F6BD8_TestingRoom(omObjData*);
void func_800F6D04_TestingRoom(omObjData*);
void func_800F6E38_TestingRoom(omObjData*);
void func_800F6F1C_TestingRoom(omObjData*);
void func_800F7010_TestingRoom(omObjData*);
void func_800F7970_TestingRoom(omObjData*);
void func_800F7A44_TestingRoom(omObjData*);
void func_800F7AFC_TestingRoom(omObjData*);
void func_800F7B78_TestingRoom(omObjData*);
void func_800F7BF4_TestingRoom(omObjData*);
void func_800F7C38_TestingRoom(omObjData*);
void func_800F7C68_TestingRoom(omObjData*, f32, f32);
void func_800F7F50_TestingRoom(void);
void func_800F7F58_TestingRoom(omObjData*);
void func_800F8360_TestingRoom(omObjData*);
void func_800F846C_TestingRoom(omObjData*, Vec4f*);
f32 func_800F85E4_TestingRoom(omObjData*, f32, f32, f32, Vec3f*);
void func_800F8804_TestingRoom(omObjData*);
void func_800F8A60_TestingRoom(Matrix4f, Vec3f*, omObjData*);
void func_800F8C6C_TestingRoom(omObjData*, f32, f32);
f32 func_800F8D18_TestingRoom(omObjData*);
f32 func_800F908C_TestingRoom(omObjData*);
