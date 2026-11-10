#ifndef MUSHROOMBANK_H
#define MUSHROOMBANK_H

#include "common.h"

/* One prize on the bank's shelves: shown when `unlock` is set (negative = always), its model
   (file 0x90000 | model), shelf offset, what it gives (negative: board item reward + 3, else a
   board feature flag) and its name / description messages. */
typedef struct BankPrize {
    /* 0x00 */ s32 unlock;
    /* 0x04 */ s32 model;
    /* 0x08 */ Vec3f pos;
    /* 0x14 */ s32 reward;
    /* 0x18 */ s32 nameMsg;
    /* 0x1C */ s32 descMsg;
} BankPrize;

/* The counter menu: cursor target (D_800F8968), camera index and message (-1: none) per choice. */
typedef struct BankMenuEntry {
    /* 0x00 */ u8 pos;
    /* 0x01 */ u8 cam;
    /* 0x04 */ s32 msg;
} BankMenuEntry;

s32 func_80059B48(s32);
s32 func_80059B10(s32);
s32 func_80059CB8(void);
s32 func_80059CE8(void* str, s16 win);
s32 func_8005A22C(s32);
s32 func_8004F954(s32, s32);
void func_8004F8DC(void);
s32 func_800115C8(s16);
void func_8005963C(s16, u16);
f32 func_80025D40(s16);
void func_8002888C(s16, s16);
void func_8005A258(s16);
TextWindow* func_8006DD60(s16);
void func_800191F8(u16);
void func_80060F04(s16, s16, s16, s16);

extern s16 D_800F384C;
extern Vec3f* D_800ED610;
extern Vec3f* D_800ED72C;

/* .data */
extern Vec3f D_800F88C0_MushroomBank[7]; /* camera positions */
extern Vec3f D_800F8914_MushroomBank[7]; /* camera rotations */
extern Vec3f D_800F8968_MushroomBank[4];
extern BankMenuEntry D_800F8998_MushroomBank[4];
extern s32 D_800F89B8_MushroomBank; /* the bank is open (flag 4 was set on entry) */
extern s32 D_800F89BC_MushroomBank;
extern BankPrize D_800F89C0_MushroomBank[12];

/* .bss */
extern s32 D_800F8B90_MushroomBank;
extern s16 D_800F8B94_MushroomBank; /* the message window */
extern Process* D_800F8B98_MushroomBank;
extern omObjData* D_800F8B9C_MushroomBank;
extern omObjData* D_800F8BA0_MushroomBank;
extern omObjData* D_800F8BA4_MushroomBank;
extern omObjData* D_800F8BA8_MushroomBank;

void func_800F66DC_MushroomBank(s32);
void func_800F6714_MushroomBank(u16*, s8*, s16);
void func_800F67B0_MushroomBank(void);
void func_800F6E38_MushroomBank(void);
void func_800F722C_MushroomBank(omObjData*);
void func_800F72A8_MushroomBank(void);
void func_800F7308_MushroomBank(omObjData*);
void func_800F7528_MushroomBank(void);
void func_800F75C8_MushroomBank(s32);
void func_800F7600_MushroomBank(s32);
void func_800F7620_MushroomBank(omObjData*);
void func_800F7754_MushroomBank(void);
s32 func_800F7B98_MushroomBank(s32);
void func_800F7BC0_MushroomBank(void);
void func_800F85D8_MushroomBank(void);

#endif
