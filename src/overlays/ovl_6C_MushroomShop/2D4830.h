#ifndef MUSHROOMSHOP_H
#define MUSHROOMSHOP_H

#include "common.h"

/* One minigame for sale: its unlock flag, shelf model, optional tile-animation file, shelf
   position and yaw, the description / name / price shown when it is selected, and an optional
   extra lock test (non-zero = not on sale yet). */
typedef struct ShopItem {
    /* 0x00 */ s32 flag;
    /* 0x04 */ s32 modelFile;
    /* 0x08 */ s32 tileFile;
    /* 0x0C */ Vec3f pos;
    /* 0x18 */ f32 rotY;
    /* 0x1C */ s32 descMsg;
    /* 0x20 */ s32 nameMsg;
    /* 0x24 */ s32 price;
    /* 0x28 */ s32 (*locked)(void);
} ShopItem; /* 0x2C on the N64 */

/* The two menu choices (buy, leave): camera target, camera index and their message. */
typedef struct ShopMenuEntry {
    /* 0x00 */ u8 pos;
    /* 0x01 */ u8 cam;
    /* 0x04 */ s32 msg;
} ShopMenuEntry;

/* A minigame category (59E80.c's D_800C5730 rows): minigame ids, 1-based, and their count. */
typedef struct ShopMgGroup {
    /* 0x00 */ u8* list;
    /* 0x04 */ u8 count;
} ShopMgGroup;

void func_800F67B0_MushroomShop(void);
void func_800F688C_MushroomShop(void);
void func_800F6B68_MushroomShop(omObjData*);
void func_800F6BC4_MushroomShop(void);
void func_800F6C00_MushroomShop(omObjData*);
void func_800F6C58_MushroomShop(void);
u8 func_800F6CF8_MushroomShop(void);
s32 func_800F6E94_MushroomShop(void);
s32 func_800F6F48_MushroomShop(void);
s32 func_800F6FA8_MushroomShop(void);
s32 func_800F7008_MushroomShop(s32);
void func_800F7088_MushroomShop(omObjData*);
s16 func_800F718C_MushroomShop(s32);
void func_800F73C8_MushroomShop(void);
s16 func_800F7500_MushroomShop(s16);
void func_800F76A0_MushroomShop(void);
void func_800F6778_MushroomShop(s32);

s32 func_80059CB8(void);
s32 func_80059CE8(void* str, s16 win);
s32 func_8005A22C(s32);
s16 func_8006D93C(u8*);
void func_80039644(s16, u8, u8);
void func_8002888C(s16, s16);
void func_8005A258(s16);
void func_80039ACC(s16);
void func_800191F8(u16);
void GMesSprKill(unkCommonStruct0*);
void func_8005963C(s16, u16);
void func_80059B74(s16);
void func_80060F04(s16, s16, s16, s16);
TextWindow* func_8006DD60(s16);
s16 func_8005949C(s32);
s16 func_80038D5C(unk2C0C0StructC0*, u16, s32, char*);
void func_800396B0(s16, u8);

extern s16 D_800F384C;
extern Vec3f* D_800ED610;
extern Vec3f* D_800ED72C;
extern s16 D_800F3B74;
extern u8 D_800C4E14[], D_800C4E24[], D_800C4E2C[], D_800C4E38[];

/* .data */
extern Vec3f D_800F89A0_MushroomShop[3];
extern Vec3f D_800F89C4_MushroomShop[3];
extern Vec3f D_800F89E8_MushroomShop[2];
extern ShopMenuEntry D_800F8A00_MushroomShop[2];
extern ShopMgGroup D_800F8A10_MushroomShop[4];
extern s32 D_800F8A30_MushroomShop[8];
extern ShopItem D_800F8A50_MushroomShop[16];

/* .bss */
extern s16 D_800F8D70_MushroomShop; /* the message window */
extern Process* D_800F8D74_MushroomShop;
extern unkCommonStruct0 D_800F8D78_MushroomShop[];
/* splat labels for fields of the font objects (unk_14 at +0x14, unk_34 at +0x34 on the N64). On
   hosts the void* before them moves both, so they are views of the one object there. */
extern s16 D_800F8D8C_MushroomShop[];
extern s16 D_800F8DE0_MushroomShop;
extern s16 D_800F8DE2_MushroomShop;
extern u16 D_800F8DE4_MushroomShop;
extern omObjData* D_800F8DE8_MushroomShop;
extern omObjData* D_800F8DEC_MushroomShop; /* the shopkeeper and the 16 shelf models */
extern s16 D_800F8DF0_MushroomShop[4];     /* tile-animation ids of the last shelf model loaded */
extern s16 D_800F8DF8_MushroomShop[2];     /* description lines: font ids */
extern s16 D_800F8DFC_MushroomShop[2];     /* description lines: widths */
extern unkCommonStruct0 D_800F8E00_MushroomShop;
extern s16 D_800F8E14_MushroomShop[16];
extern s16 D_800F8E34_MushroomShop[16];

#endif
