#include "common.h"

/* A hole (D_800FA318[7] kind 0, D_800FA380[9] kind 1): position, in use, D_800FA290 index. */
typedef struct unkStructGroundPound_00 {
/* 0x00 */ f32 unk_00; /* x */
/* 0x04 */ f32 unk_04; /* z */
/* 0x08 */ u16 unk_08; /* in use */
/* 0x0A */ u16 unk_0A; /* D_800FA290 index */
} unkStructGroundPound_00; /* size = 0xC */

/* A mole's work (func_800F7BB8, func_80023684(0x2C)): no pointers, same layout on the host. */
typedef struct GPMoleWork {
/* 0x00 */ Vec pos;
/* 0x0C */ Vec home;
/* 0x18 */ f32 angle;
/* 0x1C */ f32 speed;
/* 0x20 */ s16 sprite;
/* 0x22 */ s16 type; /* 0, 2, 4: D_800FA27A pair */
/* 0x24 */ u16 timer;
/* 0x26 */ s16 dir;
/* 0x28 */ u8 unk_28;
/* 0x29 */ u8 req;
/* 0x2A */ u8 state;
} GPMoleWork; /* size = 0x2C */

/* The stage object's work (func_800F8264, func_80023684(0x2C)). */
typedef struct GPStageWork {
/* 0x00 */ char unk_00[4];
/* 0x04 */ u8 unk_04;
/* 0x05 */ u8 unk_05;
/* 0x06 */ char unk_06[0x26];
} GPStageWork; /* size = 0x2C */

/* D_800FA290[16]: the holes in creation order; D_800FA2B0[col][row]: the grid. */
typedef struct GPHoleRef {
    u8 kind;
    u8 idx;
} GPHoleRef;

s32 func_800184A8(unkGlobalStruct_00*, s32);
void func_800F9870_GroundPound(omObjData*);
void func_800F9B18_GroundPound(omObjData*);
extern u16 ContBtn[4];
extern s8 ContStkY[4];
extern s32 D_800FA2D0_GroundPound;
extern s32 D_800FA2E0_GroundPound;

void func_800F7FEC_GroundPound(void);
void func_800F9E80_GroundPound(f32, f32, f32, f32, f32, f32, f32);
void func_800F67E0_GroundPound(omObjData* arg0);
void func_800F6EE4_GroundPound(void);
void func_800F8C20_GroundPound(omObjData*);
void func_800F6814_GroundPound(void);
void func_80079078(s16);
void func_800F7044_GroundPound(s16 i);
void func_800F7078_GroundPound(s16 i);
void func_800F70AC_GroundPound(Vec* home, Vec* out);
void func_800F7180_GroundPound(omObjData* obj, f32 angle, f32 speed, f32 minY, f32 maxY);
f32 func_800F7310_GroundPound(s32 fast, f32 angle, f32 dx, f32 dz);
f32 func_800F73E4_GroundPound(GPMoleWork* w, f32 angle);
void func_800F796C_GroundPound(omObjData* obj);
void func_800F7BB8_GroundPound(omObjData* obj);
void func_800F823C_GroundPound(void);
void func_800F8264_GroundPound(omObjData* obj);
s32 func_800F8480_GroundPound(omObjData* obj, s32 i, unkStructGroundPound_00* hole, s32 file, s32 heap, s32 max);
void func_800F8568_GroundPound(omObjData* obj);
void func_800F8688_GroundPound(omObjData* obj);
void func_800F86FC_GroundPound(omObjData* obj);
void func_800F8744_GroundPound(void);
u32 func_800F9FEC_GroundPound(void);
void func_80025BB8(s16, s16);
f32 func_80025D18(s16);
void func_800399F0(s16);
s16 func_80038D5C(unk2C0C0StructC0*, u16, s16, char*);
extern omObjData* D_800F2AF8[];
void func_800F6924_GroundPound(void);
void func_800F6B0C_GroundPound(void);

extern f64 D_800FA250_GroundPound;
extern f32 D_800FA2E8_GroundPound;
extern unkStructGroundPound_00 D_800FA380_GroundPound[9];
extern unkStructGroundPound_00 D_800FA318_GroundPound[7];
extern u16 D_800FA270_GroundPound;
extern s16 D_800FA272_GroundPound[2];
extern u16 D_800FA276_GroundPound;
extern u16 D_800FA278_GroundPound;
extern s16 D_800FA27A_GroundPound[6];
extern u8 D_800FA286_GroundPound[4];
extern GPHoleRef D_800FA290_GroundPound[16];
extern GPHoleRef D_800FA2B0_GroundPound[4][4];
extern Vec D_800FA36C_GroundPound;
extern u8 D_800FA378_GroundPound[7];
extern omObjData* D_800FA3F0_GroundPound[16];
extern omObjData* D_800FA430_GroundPound[3];
extern s16 D_800FA450_GroundPound;
extern unkStructGroundPound_00* D_800FA2F0_GroundPound; /* the CPU's target hole (a pointer: 8 bytes on the host) */
extern s32 D_800FA2F8_GroundPound;
extern s32 D_800FA2FC_GroundPound;
extern s32 D_800FA2F4_GroundPound;
extern u32 D_800FA1D0_GroundPound;
extern u16 D_800FA2D4_GroundPound;
extern u8 D_800FA2D6_GroundPound;
extern f32 D_800FA2E4_GroundPound;
extern f32 D_800FA2EC_GroundPound;
extern s32 D_800FA300_GroundPound;
void func_800F9094_GroundPound(omObjData* obj);
s32 func_800F9314_GroundPound(omObjData* obj);
void func_800F95D4_GroundPound(omObjData* obj);
void func_800F9908_GroundPound(omObjData* obj);
unkStructGroundPound_00* func_800F9950_GroundPound(omObjData* obj);
s32 func_800F9A24_GroundPound(omObjData* obj, f32 angle);
s32 func_800F9F18_GroundPound(u32 seed);
f32 func_80025E70(s16);
void func_800090C4(omObjData* obj, u8 idx, u8 val);
void func_80060F04(s16, s32, s32, s32);
extern s32 D_800FA2D8_GroundPound;
extern f32 D_800FA2DC_GroundPound;
extern u8 D_800C5982;
extern u16 D_800FA264_GroundPound;
extern s32 D_800FA310_GroundPound;
extern s16 D_800EE984;
extern u16 D_800FA262_GroundPound;
extern u16 D_800FA260_GroundPound;
extern u16 D_800FA266_GroundPound;
extern u16 D_800FA268_GroundPound;
extern omObjData* D_800FA43C_GroundPound;
extern s16 D_800FA26C_GroundPound;
extern u16 D_800FA26A_GroundPound;
extern u16 D_800FA020_GroundPound;
extern f32 D_800B895C;

void func_800F6A84_GroundPound(omObjData* obj);
void func_800F6F40_GroundPound(void);
s32 func_800F6FD4_GroundPound(void);
f32 func_800F8AA0_GroundPound(omObjData* obj);
void func_800F9E4C_GroundPound(f32);
