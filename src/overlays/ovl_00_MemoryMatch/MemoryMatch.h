#include "common.h"

#define NUM_OF_TILES 9
extern Vec3f D_800FD7F0_MemoryMatch[NUM_OF_TILES];

// typedef struct unk_801DEC9C {
// /* 0x00 */ u16 unk_00;
// /* 0x02 */ u16 unk_02;
// /* 0x04 */ u16 unk_04;
// /* 0x06 */ u16 unk_06;
// /* 0x08 */ u16 unk_08;
// /* 0x0A */ u16 unk_0A;
// /* 0x0C */ s32 unk_0C;
// /* 0x10 */ s32 unk_10;
// /* 0x14 */ void* unk_14;
// /* 0x18 */ f32 unk_18;
// /* 0x1C */ f32 unk_1C;
// /* 0x20 */ f32 unk_20;
// /* 0x24 */ char unk_24[0x0C];
// /* 0x30 */ f32 unk_30;
// /* 0x34 */ f32 unk_34;
// /* 0x38 */ f32 unk_38;
// /* 0x3C */ s32 unk_3C;
// /* 0x40 */ s32 unk_40;
// /* 0x44 */ s32 unk_44;
// /* 0x48 */ s32 unk_48;
// /* 0x4C */ u8 unk_4C;
// /* 0x4D */ u8 unk_4D;
// /* 0x4E */ u8 unk_4E;
// /* 0x4F */ u8 unk_4F;
// /* 0x50 */ void* unk_50;
// } unk_801DEC9C; //sizeof 0x54

typedef struct unkStruct {
    s16 unk0;
    s16 unk2;
} unkStruct;

extern unkStruct D_800FE158_MemoryMatch[10];

void func_800F6858_MemoryMatch(omObjData*);
void func_800F796C_MemoryMatch(omObjData*);
void func_800F71C4_MemoryMatch(omObjData*);
void func_800F68CC_MemoryMatch(omObjData*);
void func_800F7EDC_MemoryMatch(void);
void func_800F8C38_MemoryMatch(void);
void func_800F8E38_MemoryMatch(void);
void func_800F90CC_MemoryMatch(void);
void func_800F963C_MemoryMatch(void);
void func_800FB360_MemoryMatch(void);
void func_800F7B6C_MemoryMatch(u16);
void func_800F7C08_MemoryMatch(void);
void func_800F7D74_MemoryMatch(void);
void func_800F8FEC_MemoryMatch(void);
void func_800F9178_MemoryMatch(void);
void func_800F7350_MemoryMatch(void);
void func_800F73A4_MemoryMatch(omObjData*);
void func_800F7874_MemoryMatch(omObjData*);
void func_800F7E20_MemoryMatch(void);
void func_800F8F58_MemoryMatch(void);
u16 func_800F901C_MemoryMatch(void);
s16 func_800F9BC8_MemoryMatch(omObjData*);
void func_800F830C_MemoryMatch(void);
void func_800F94E0_MemoryMatch(void);

void func_800FADDC_MemoryMatch(omObjData*);
void func_800FAD94_MemoryMatch(omObjData* arg0, s16 arg1);

extern u32 D_800FD7E0_MemoryMatch;
extern u8 D_800FD8D0_MemoryMatch[]; //sjis string
extern u8 D_800FD8DC_MemoryMatch[]; //sjis string
extern u8 D_800FD8EC_MemoryMatch[]; //sjis string
extern omObjData* D_800FDDDC_MemoryMatch;
extern Matrix4f D_800FDDE8_MemoryMatch;
extern f32 D_800FDE28_MemoryMatch;
extern u16 D_800FDE2C_MemoryMatch;
extern s16 D_800FE180_MemoryMatch;
extern s16 D_800FE2C0_MemoryMatch;
extern u16 D_800FE2C2_MemoryMatch;
extern u16 D_800FE2C4_MemoryMatch;
extern u16 D_800F5144;

extern Vec3f D_800FDDC0_MemoryMatch;
extern Vec3f D_800FDDCC_MemoryMatch;

typedef struct tikiThing {
/* 0x00 */ s16 unk_00;
/* 0x02 */ s16 unk_02;
/* 0x04 */ f32 unk_04;
/* 0x08 */ f32 unk_08;
/* 0x0C */ f32 unk_0C;
/* 0x10 */ f32 unk_10;
/* 0x14 */ f32 unk_14;
} tikiThing;

typedef struct unk_MemoryMatch_00 {
/* 0x00 */ s16 unk_00;
/* 0x02 */ s16 unk_02;
/* 0x04 */ s16 unk_04;
/* 0x06 */ s16 unk_06;
/* 0x08 */ f32 unk_08;
/* 0x0C */ f32 unk_0C;
/* 0x10 */ s16 unk_10;
/* 0x12 */ s16 unk_12;
/* 0x14 */ s16 unk_14;
/* 0x16 */ s16 unk_16;
/* 0x18 */ s16 unk_18;
/* 0x1A */ s16 unk_1A;
/* 0x1C */ s16 unk_1C;
/* 0x1E */ s16 unk_1E;
} unk_MemoryMatch_00;

typedef struct unk_MemoryMatch_01 {
/* 0x00 */ u16 unk_00;
/* 0x02 */ u16 unk_02;
/* 0x04 */ u16 unk_04;
/* 0x06 */ u16 unk_06;
/* 0x08 */ u16 unk_08;
/* 0x0A */ u16 unk_0A;
} unk_MemoryMatch_01;

u16 func_800F8DF4_MemoryMatch(u32);
extern unk_MemoryMatch_01 D_800FDE30_MemoryMatch;
extern unk_MemoryMatch_00 D_800FE318_MemoryMatch[0x10];

extern tikiThing D_800FDE50_MemoryMatch[8]; //related hitbox of tikis

extern Vec3f D_800FD7E4_MemoryMatch;
extern omObjData* D_800FE2E8_MemoryMatch[9];

typedef struct unk_MemoryMatch_02 {
/* 0x00 */ s16 unk_00;
/* 0x02 */ s16 unk_02;
/* 0x04 */ char unk_04[6];
/* 0x0A */ s16 unk_0A;
/* 0x0C */ s16 unk_0C;
/* 0x0E */ s16 unk_0E;
/* 0x10 */ s16 unk_10;
/* 0x12 */ s16 unk_12;
/* 0x14 */ s16 unk_14;
/* 0x16 */ char unk_16[2];
/* 0x18 */ f32 unk_18;
/* 0x1C */ f32 unk_1C;
/* 0x20 */ f32 unk_20;
} unk_MemoryMatch_02; //sizeof 0x24

typedef struct unk_MemoryMatch_03 {
/* 0x00 */ s16 unk_00;
/* 0x02 */ s16 unk_02;
/* 0x04 */ s16 unk_04;
/* 0x08 */ f32 unk_08;
/* 0x0C */ f32 unk_0C;
/* 0x10 */ f32 unk_10;
/* 0x14 */ f32 unk_14;
/* 0x18 */ s16 unk_18;
} unk_MemoryMatch_03; //sizeof 0x1C

extern unk_MemoryMatch_02 D_800FDF10_MemoryMatch[16];
extern unk_MemoryMatch_03 D_800FE2C8_MemoryMatch;
/* Splat labels of D_800FE2C8's fields (retail addresses each as its own symbol). */
extern s16 D_800FE2CA_MemoryMatch;
extern s16 D_800FE2CC_MemoryMatch;
extern f32 D_800FE2D0_MemoryMatch;
extern f32 D_800FE2D4_MemoryMatch;
extern f32 D_800FE2D8_MemoryMatch;
extern f32 D_800FE2DC_MemoryMatch;
extern s16 D_800FE2E0_MemoryMatch;
extern s16 D_800FDE40_MemoryMatch;
extern s16 D_800FDE42_MemoryMatch[2];
extern s16 D_800FDE46_MemoryMatch[2];
extern u16 D_800FD87A_MemoryMatch;
extern f32 D_800FD8C0_MemoryMatch[4];
extern s32 D_800FD8B0_MemoryMatch[4];
extern u16 D_800FD85C_MemoryMatch[NUM_OF_TILES];
extern u16 D_800FD87C_MemoryMatch;
extern s16 D_800FDDD8_MemoryMatch;
extern s16 D_800FDE3E_MemoryMatch[];
extern f32 D_800FD8A8_MemoryMatch;
extern s16 D_800FE30C_MemoryMatch;
extern s16 D_800FE30E_MemoryMatch;

f64 func_8009B618(f64, f64);
void func_8001E2A8(s16, u16);
f32 func_800F7994_MemoryMatch(f32, f32, f32);
f32 func_800F7B90_MemoryMatch(f32, f32);
void func_800F7DC0_MemoryMatch(s16, s16);
u16 func_800F7AFC_MemoryMatch(u16);
void func_800F8130_MemoryMatch(omObjData*);
s16 func_800F84A8_MemoryMatch(s16);
void func_800F8654_MemoryMatch(omObjData*);
void func_800F87DC_MemoryMatch(omObjData*);
void func_800F89A8_MemoryMatch(omObjData*);
void func_800F8BC0_MemoryMatch(s16);
void func_800F8C80_MemoryMatch(omObjData*);
s16 func_800F8D84_MemoryMatch(Vec3f*, Vec2f*);
s16 func_800F94E8_MemoryMatch(s32, s32, s32);
void func_800F953C_MemoryMatch(f32, f32, f32);
f32 func_800F96A8_MemoryMatch(f32, f32);
void func_800F9C50_MemoryMatch(omObjData*);
void func_800FAD18_MemoryMatch(u16);
void func_800FAEB4_MemoryMatch(omObjData*);
void func_800FD6A0_MemoryMatch(omObjData*, omObjData*);

typedef struct unk_MemoryMatch_2C {
/* 0x00 */ char unk_00[4];
/* 0x04 */ u8 unk_04;
/* 0x05 */ u8 unk_05;
/* 0x06 */ char unk_06[0x26];
} unk_MemoryMatch_2C; //sizeof 0x2C

extern s16 D_800FD880_MemoryMatch;
extern s16 D_800FD882_MemoryMatch;
extern s16 D_800FD884_MemoryMatch;
extern s16 D_800FE192_MemoryMatch;
extern s16 D_800FE310_MemoryMatch;
extern omObjData* D_800F2AF8[];
void func_80060F04(s16, s16, s16, s16);
void func_80060758(s32);
f32 func_80025E70(s16);
f32 func_80025D18(s16);
void func_800F97D0_MemoryMatch(omObjData*);
void func_800FA400_MemoryMatch(omObjData*);
void func_800FAAC4_MemoryMatch(omObjData*);
void func_800FAB80_MemoryMatch(omObjData*);
void func_800FAF9C_MemoryMatch(omObjData*);
void func_800FB0A8_MemoryMatch(omObjData*);
void func_800FB1B0_MemoryMatch(void);
void func_800FB1B8_MemoryMatch(omObjData*);
extern s16 D_800FD870_MemoryMatch;
extern s16 D_800FD872_MemoryMatch;
extern s16 D_800FD874_MemoryMatch;
extern s16 D_800FD876_MemoryMatch;
extern s16 D_800FE312_MemoryMatch;
void func_800F7318_MemoryMatch(omObjData*);
void func_800F7C70_MemoryMatch(f32);
extern s16 D_800FDD70_MemoryMatch[2][4];
extern f32 D_800FDD80_MemoryMatch[2][4];
extern f32 D_800FDDA0_MemoryMatch[2][4];
s32 func_8006503C(s16, s16, u16);
void func_800F714C_MemoryMatch(omObjData*);
void func_800090C4(omObjData* obj, u8 idx, u8 val);
void func_800FA1E4_MemoryMatch(omObjData*);
extern s16 D_800FD888_MemoryMatch[9];
extern s16 D_800FD89A_MemoryMatch;
extern s16 D_800FD89C_MemoryMatch;
extern s16 D_800FD89E_MemoryMatch;
extern s16 D_800FD8A0_MemoryMatch;
extern f32 D_800FD8A4_MemoryMatch;
extern u16 ContBtn[];
extern s8 ContStkY[];

/* Splat labels for the low bytes of D27D0.c's s16 counters D_800FE1DA/DE/E0. */
extern s16 D_800FE1DA_MemoryMatch;
extern s16 D_800FE1DE_MemoryMatch;
extern s16 D_800FE1E0_MemoryMatch;
extern u8 D_800FE1DB_MemoryMatch;
extern u8 D_800FE1DF_MemoryMatch;
extern u8 D_800FE1E1_MemoryMatch;
