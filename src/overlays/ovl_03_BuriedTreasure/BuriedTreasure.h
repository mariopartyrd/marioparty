#include "common.h"
#include "sprite65770.h" /* D_800EC700: the sprite animations (pointer fields: host layout differs) */

typedef struct unkStructSize4 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
} unkStructSize4; //sizeof 4

typedef struct unkStructSize4_2 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
} unkStructSize4_2; //sizeof 4

typedef struct unkStructSize6 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
} unkStructSize6; //sizeof 6

typedef struct unkStructSize0x20 {
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
} unkStructSize0x20; //sizeof 0x20

typedef struct unkStructSize0x28 {
    /* 0x00 */ u16* unk_00;
    /* 0x04 */ u16 unk_04; // counts how many elements are in unk_00
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s8 unk_08;
    /* 0x09 */ s8 unk_09;
    /* 0x0A */ u8 unk_0A;
    /* 0x0B */ char unk_0B[1];
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ u16 unk_10;
    /* 0x12 */ u16 unk_12;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ omObjData* unk_1C;
    /* 0x20 */ omObjData* unk_20;
    /* 0x24 */ u8 unk_24;
    /* 0x25 */ u8 unk_25;
    /* 0x26 */ char unk_26[2];
} unkStructSize0x28; //sizeof 0x28

typedef struct unkStructSize0x5C {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ char unk_30[0xC];
    /* 0x3C */ s16 unk_3C;
    /* 0x3E */ s16 unk_3E;
    /* 0x40 */ s16 unk_40;
    /* 0x42 */ s16 unk_42;
    /* 0x44 */ s16 unk_44;
    /* 0x46 */ s16 unk_46;
    /* 0x48 */ s16 unk_48;
    /* 0x4A */ s16 unk_4A;
    /* 0x4C */ s16 unk_4C;
    /* 0x4E */ s16 unk_4E;
    /* 0x50 */ s16 unk_50;
    /* 0x52 */ s16 unk_52;
    /* 0x54 */ s16 unk_54;
    /* 0x56 */ s16 unk_56;
    /* 0x58 */ s16 unk_58;
    /* 0x5A */ s16 unk_5A;
} unkStructSize0x5C; //sizeof 0x5C

void func_800F692C_BuriedTreasure(omObjData*);
void func_800F6958_BuriedTreasure(void);
void func_800F6D6C_BuriedTreasure(void);
void func_800F6DCC_BuriedTreasure(omObjData*);
void func_800F6E44_BuriedTreasure(omObjData*);
void func_800F6EC4_BuriedTreasure(omObjData*);
void func_800F7164_BuriedTreasure(omObjData*);
void func_800F7D50_BuriedTreasure(s16);
void func_800F7E48_BuriedTreasure(s16);
void func_800F815C_BuriedTreasure(s16);
s32 func_800F85B4_BuriedTreasure(omObjData*);
void func_800F8760_BuriedTreasure(void);
unkStructSize0x5C* func_800F87A8_BuriedTreasure(omObjData*);
void func_800F8894_BuriedTreasure(void);
unkStructSize0x5C* func_800F8914_BuriedTreasure(omObjData*);
u32 func_800F8940_BuriedTreasure(void);
void func_800F8978_BuriedTreasure(Matrix4f);
void func_800F8BB8_BuriedTreasure(f32, f32, f32, Vec3f*);
void func_800F8C84_BuriedTreasure(s16, f32*, f32*, f32*);
void func_800F8D1C_BuriedTreasure(unkStructSize0x5C*);
s16 func_800F8EF0_BuriedTreasure(f32*, f32*, s16);
s16 func_800F9260_BuriedTreasure(f32*, f32*, s16);
void func_800F9990_BuriedTreasure(void);
u16 func_800F92D4_BuriedTreasure(f32, f32, s16, void*, s16*);
s16 func_800F9C40_BuriedTreasure(s16, f32, f32, s16);
void func_800F9DCC_BuriedTreasure(s16);
void func_800F9E10_BuriedTreasure(void);
void func_800F9F90_BuriedTreasure(void);
void func_800FA090_BuriedTreasure(omObjData*);
void func_800FA0B4_BuriedTreasure(void);
void func_800FA138_BuriedTreasure(void);
void func_800FA90C_BuriedTreasure(void);
s16 func_800FB520_BuriedTreasure(u16, u16);
s16 func_800FB780_BuriedTreasure(void);
void func_800FB918_BuriedTreasure(s16);
void func_800FB920_BuriedTreasure(s16);
u16 func_800FB928_BuriedTreasure(u16);
void func_800FB998_BuriedTreasure(u16);
void func_800FB9E8_BuriedTreasure(void);

void guMtxCatF(Matrix4f, Matrix4f, Matrix4f);
void guMtxL2F(Matrix4f, Mtx*);
void guTranslateF(Matrix4f, f32, f32, f32);
u32 func_80009C90(omObjData*, s8, s8);
void func_80017A60(omObjData*);
void func_80024198(s32, void*, s32);
void func_80060440(s16, s16);
void func_80060F04(s16, s32, s32, s32);
void func_80067284(s16, s32, f32);
s32 func_80067328(s16, s16);
f64 func_8009B618(f64, f64);

extern unk65770Anim* D_800EC700[256];
extern s16 ContBtn[];
extern s8 ContStkY[];
extern omObjData* D_800F3FB0[];
extern s16 D_800FBA70_BuriedTreasure;
extern s16 D_800FBA72_BuriedTreasure;
extern s16 D_800FBA74_BuriedTreasure[4];
extern unkStructSize6 D_800FBA7C_BuriedTreasure[4];
extern f32 D_800FBA94_BuriedTreasure[4];
extern u16 D_800FBAB8_BuriedTreasure[24 * 12];
extern u8 D_800FBD00_BuriedTreasure[24 * 12];
extern u8 D_800FBE20_BuriedTreasure[2];
extern s8 D_800FBE24_BuriedTreasure[2];
extern unkStructSize4 D_800FBE30_BuriedTreasure[9];
extern u32 D_800FBE54_BuriedTreasure; //rng sub seed
extern s16 D_800FBE58_BuriedTreasure;
extern s16 D_800FC020_BuriedTreasure;
extern s16 D_800FC022_BuriedTreasure;
extern s16 D_800FC024_BuriedTreasure;
extern s16 D_800FC026_BuriedTreasure;
extern s16 D_800FC028_BuriedTreasure;
extern s16 D_800FC02A_BuriedTreasure;
extern s16 D_800FC02C_BuriedTreasure;
extern omObjData* D_800FC030_BuriedTreasure;
extern s16 D_800FC034_BuriedTreasure;
extern s16 D_800FC040_BuriedTreasure[1];
extern unkStructSize4_2 D_800FC050_BuriedTreasure[3]; // one per placed object (0x800FC050..5C)
extern omObjData* D_800FC05C_BuriedTreasure;
extern omObjData* D_800FC060_BuriedTreasure;
extern unkStructSize0x28 D_800FC068_BuriedTreasure[2];
extern u16 D_800FC0B8_BuriedTreasure[4];
extern Matrix4f D_800FC0C0_BuriedTreasure;
extern s32 D_800FC100_BuriedTreasure[16];
extern s16 D_800FC140_BuriedTreasure;
extern omObjData* D_800FC144_BuriedTreasure;
extern Matrix4f D_800FC148_BuriedTreasure;
extern unkStructSize0x5C* D_800FC188_BuriedTreasure[4];
extern s16 D_800FC198_BuriedTreasure[6]; // length >= 6
extern unkStructSize0x20 D_800FC1C0_BuriedTreasure[32];
extern unkStructSize0x28 D_800FC5C0_BuriedTreasure[1];
extern Gfx* D_800FC5E8_BuriedTreasure;
extern s16 D_800FC5EC_BuriedTreasure;
extern f32 D_800FC5F0_BuriedTreasure;
