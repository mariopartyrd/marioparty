#include "common.h"

//800FD9C4 game state?
//800FD9A8 turns

typedef struct unkStructShyGuySays_03 {
/* 0x00 */ s16 unk_00;
/* 0x02 */ s16 unk_02;
} unkStructShyGuySays_03; //sizeof 4

typedef struct unkStruct_ShyGuySays_01 {
/* 0x00 */ s16 unk_00;
/* 0x02 */ s16 unk_02;
/* 0x04 */ s32 unk_04;
/* 0x08 */ s16 unk_08;
/* 0x0A */ s16 unk_0A;
/* 0x0C */ s16 unk_0C;
/* 0x0E */ s16 unk_0E;
/* 0x10 */ s32 unk_10;
/* 0x14 */ s32 unk_14;
/* 0x18 */ u32 unk_18;
/* 0x1C */ unkStructShyGuySays_03 unk_1C;
/* 0x20 */ unkStructShyGuySays_03 unk_20;
/* 0x24 */ unkStructShyGuySays_03 unk_24;
/* 0x28 */ unkStructShyGuySays_03 unk_28;
/* 0x2C */ Vec3f unk_2C;
/* 0x38 */ Vec3f unk_38;
/* 0x44 */ Vec3f unk_44;
/* 0x50 */ Vec3f unk_50;
/* 0x5C */ Vec3f unk_5C;
/* 0x68 */ Vec3f unk_68;
/* 0x74 */ Vec3f unk_74;
/* 0x80 */ u32 unk_80;
/* 0x84 */ f32 unk_84;
/* 0x88 */ s16 unk_88;
/* 0x8A */ s16 unk_8A;
/* 0x8C */ s16 unk_8C;
/* 0x8E */ s16 unk_8E;
/* 0x90 */ s16 unk_90;
/* 0x92 */ s16 unk_92;
} unkStruct_ShyGuySays_01; //0x94 in size

typedef struct unkShyGuySaysStruct {
    /* 0x000 */ s16 unk0;
    /* 0x004 */ s32 unk4;                           /* inferred */
    /* 0x008 */ s16 unk8;                           /* inferred */
    /* 0x00A */ s16 unkA;                           /* inferred */
    /* 0x00C */ s16 unkC;                           /* inferred */
    /* 0x00E */ s16 unkE;                           /* inferred */
    /* 0x010 */ s32 unk10;                          /* inferred */
    /* 0x014 */ s32 unk14;                          /* inferred */
    /* 0x018 */ s32 unk18;                          /* inferred */
    /* 0x01C */ char pad1C[0x10];                   /* maybe part of unk18[5]? */
    /* 0x02C */ f32 unk2C;                          /* inferred */
    /* 0x030 */ f32 unk30;                          /* inferred */
    /* 0x034 */ f32 unk34;                          /* inferred */
    /* 0x038 */ char pad38[0xC];                    /* maybe part of unk34[4]? */
    /* 0x044 */ f32 unk44;                          /* inferred */
    /* 0x048 */ f32 unk48;                          /* inferred */
    /* 0x04C */ f32 unk4C;                          /* inferred */
    /* 0x050 */ char pad50[0x30];                   /* maybe part of unk4C[0xD]? */
    /* 0x080 */ s32 unk80;                          /* inferred */
    /* 0x084 */ s32 unk84;                          /* inferred */
    /* 0x088 */ u16 unk88;                          /* inferred */
    /* 0x08A */ s16 unk8A;                          /* inferred */
    /* 0x08C */ s16 unk8C;                          /* inferred */
    /* 0x08E */ s16 unk8E;                          /* inferred */
    /* 0x090 */ s16 unk90;                          /* inferred */
    /* 0x092 */ s16 unk92;                          /* inferred */
    /* 0x094 */ char pad94[0x70];                   /* maybe part of unk92[0x39]? */
} unkShyGuySaysStruct;                                /* size = 0x104 */

typedef struct unkStruct_ShyGuySays_05 {
/* 0x00 */ f32 unk_00[100];
} unkStruct_ShyGuySays_05;

typedef struct unkStruct_ShyGuySays_04 {
/* 0x00 */ unkStruct_ShyGuySays_05* unk_00;
/* 0x04 */ f32 unk_04;
/* 0x08 */ f32 unk_08;
/* 0x0C */ char unk_0C[0x184];
} unkStruct_ShyGuySays_04;

typedef struct UnknownBlock8 {
    /* 0x00 */ u16 unk_00[4];
} UnknownBlock8;

typedef struct UnknownBlock36 {
    /* 0x00 */ u16 unk_00[18];
} UnknownBlock36;

typedef struct UnknownBlockCombo48 {
    /* 0x00 */ UnknownBlock8  unk_00;
    /* 0x08 */ UnknownBlock36 unk_08;
} UnknownBlockCombo48;

typedef struct UnknownBlock24 {
    /* 0x00 */ char unk_00[24];
} UnknownBlock24;

extern u8 D_800F64F8;
extern unkStruct_ShyGuySays_05* D_800FDC64_ShyGuySays;
extern unkStruct_ShyGuySays_01 D_800FD9CE_ShyGuySays[];
extern u16 D_800F5144;
extern s16 D_800FD5CC_ShyGuySays;
extern s16 D_800FD5CE_ShyGuySays;
extern unkStructShyGuySays_03 D_800FDCE8_ShyGuySays[];
extern unkStruct_ShyGuySays_01 D_800FD9C0_ShyGuySays[];
extern s32 D_800FDC4C_ShyGuySays;
extern f32 D_800FDC54_ShyGuySays;
extern s16 D_800EE984;
extern u32 D_800FD5E0_ShyGuySays;
extern u32 D_800FD5E4_ShyGuySays;
extern s16 D_800FD5E8_ShyGuySays;
extern u16 D_800FD5EA_ShyGuySays;
extern f32 D_800FD5EC_ShyGuySays;
extern s32 D_800FD5F0_ShyGuySays;
extern omObjData* D_800FD998_ShyGuySays;
extern s32 D_800FD99C_ShyGuySays;
extern s32 D_800FD9A0_ShyGuySays;
extern u16 D_800FD9A4_ShyGuySays;
extern s16 D_800FD9A6_ShyGuySays;
extern s16 D_800FD9A8_ShyGuySays;
extern s16 D_800FDC10_ShyGuySays[];
extern s16 D_800FDC1A_ShyGuySays;
extern s16 D_800FDC1C_ShyGuySays;
extern s16 D_800FDC1E_ShyGuySays;
extern omObjData* D_800F2AF8[]; //object ptr array
extern s32 D_800FD9A0_ShyGuySays;
extern s16 D_800FDD10_ShyGuySays;
extern u16 D_800F2BC0;
extern u32 D_800FD5C0_ShyGuySays;
extern f64 D_800FD630_ShyGuySays;
extern f64 D_800FD638_ShyGuySays;
extern f64 D_800FD640_ShyGuySays;
extern f64 D_800FD648_ShyGuySays;
extern f64 D_800FD650_ShyGuySays;
typedef struct ShyGuyMotPair {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u16 unk_02;
} ShyGuyMotPair;

typedef struct ShyGuyMotTbl {
    /* 0x00 */ ShyGuyMotPair unk_00[6];
} ShyGuyMotTbl; /* sizeof 0x18 */

extern const ShyGuyMotTbl D_800FD6C8_ShyGuySays;
extern Vec3f D_800FD980_ShyGuySays;
extern Vec3f D_800FD98C_ShyGuySays;
extern omObjData* D_800FDC20_ShyGuySays;
extern s16 D_800FDC50_ShyGuySays[2];
extern u16 D_800FD5DC_ShyGuySays[2];
extern f64 D_800FD818_ShyGuySays; //BSS
extern f64 D_800FD820_ShyGuySays; //BSS
extern const UnknownBlock8 D_800FD850_ShyGuySays;
extern const UnknownBlock8 D_800FD858_ShyGuySays;
extern const UnknownBlock36 D_800FD860_ShyGuySays;
extern f64 func_800FD658_ShyGuySays; //BSS

void func_800FB424_ShyGuySays(void);
extern u16 D_800FD5C4_ShyGuySays;

void func_800607C4(s16, s16);
f64 func_8009B618(f64, f64);
void func_800F69F8_ShyGuySays(void);
void func_800F6A38_ShyGuySays(omObjData*);
void func_800F6E50_ShyGuySays(omObjData*);
void func_800F6F98_ShyGuySays(omObjData*);
void func_800F72A4_ShyGuySays(void);
f32 func_800F7720_ShyGuySays(f32, f32, f32, f32);
f32 func_800F781C_ShyGuySays(f32, f32, f32, f32);
f32 func_800F7AF8_ShyGuySays(f32, f32, f32);
void func_800F8D58_ShyGuySays(omObjData*);
void func_800F69F8_ShyGuySays(void);
void func_80060268(s16);
void func_800F73EC_ShyGuySays(void);
void func_800FA308_ShyGuySays(omObjData*, s16*, u16);
void func_800FA8D4_ShyGuySays(void);
void func_800F9118_ShyGuySays(omObjData*, s16);
void func_800F94A8_ShyGuySays(void);
void func_800F95BC_ShyGuySays(void);
void func_800F96D4_ShyGuySays(void);
s16 func_800F97A8_ShyGuySays(void);
s16 func_800F9828_ShyGuySays(void);
void func_800F98EC_ShyGuySays(void);
s16 func_800F9A7C_ShyGuySays(u16, s16);
void func_800F9AFC_ShyGuySays(u16);
void func_800F9F60_ShyGuySays(omObjData*, s16*, u16);
f32 func_800FD1D0_ShyGuySays(void);
s16 func_800FD200_ShyGuySays(void);
u16 func_800F740C_ShyGuySays(u16 arg0);
void func_800F6930_ShyGuySays(omObjData*);
void func_800FA77C_ShyGuySays(omObjData*);
void func_800FB6E0_ShyGuySays(omObjData*);
void func_800FBAE4_ShyGuySays(omObjData*);
void func_800FCA8C_ShyGuySays(omObjData*, u16);
s16 func_800FD124_ShyGuySays(omObjData*);
void func_800FD274_ShyGuySays(s16, s16, f32, u16*, u16*);
void func_800F71F4_ShyGuySays(void);
void func_800F736C_ShyGuySays(void);
void func_800F8068_ShyGuySays(void);
void func_800F81A4_ShyGuySays(void);
f32 func_800FB190_ShyGuySays(f32, f32);
void func_800FB30C_ShyGuySays(void);
void func_800F67F8_ShyGuySays(omObjData* arg0);
void func_800F747C_ShyGuySays(u16 arg0);
void func_800F6FC0_ShyGuySays(void);
