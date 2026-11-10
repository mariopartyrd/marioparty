#ifndef OVL_7B_H
#define OVL_7B_H

#include "common.h"
#include "engine/process.h"
#include "engine/pad.h"

/* Mini-Game Stadium minigame results: per player a coin column (stacked coins that shift up or
   down by the minigame's coins), coins dropping in, and the totals in digits. */

/* the main process's work (D_800FB1C0) */
typedef struct ResMain {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Process* player[4]; /* func_800F9310, user_data PlayerRes */
    /* 0x14 */ Process* col[4];    /* func_800F6BEC, user_data ColWork */
    /* 0x24 */ Process* drop[4];   /* func_800F8200, user_data ColWork */
} ResMain; /* 0x34 on the N64 */

/* one player */
typedef struct PlayerRes {
    /* 0x00 */ s8 index;
    /* 0x01 */ s8 rank;
    /* 0x02 */ u16 flags;
    /* 0x04 */ s8 unk_04;   /* the jump finished */
    /* 0x06 */ s16 coins;   /* before the minigame */
    /* 0x08 */ s16 coinsMg; /* won in it (clamped) */
    /* 0x0A */ s16 total;
    /* 0x0C */ Vec3f pos;
    /* 0x18 */ Vec3f unk_18;
    /* 0x24 */ s16 model;
    /* 0x26 */ s16 model2;
    /* 0x28 */ u16 sprPlus;
    /* 0x2A */ u16 sprMinus;
    /* 0x2C */ u16 digPlus[4];
    /* 0x34 */ u16 digMinus[4];
    /* 0x3C */ s16 digits[4]; /* sign glyph, then the minigame coins' digits */
    /* 0x44 */ u16 sprTotal[3];
    /* 0x4A */ s16 digTotal[3];
    /* 0x50 */ s16 mot[5];
    /* 0x5A */ char unk_5A[0x16];
    /* 0x70 */ s32 unk_70;
    /* 0x74 */ s32 unk_74;
    /* 0x78 */ s16 unk_78;
    /* 0x7A */ u8 unk_7A;
} PlayerRes; /* 0x7C */

/* a coin column (func_800F6BEC), one of its coins (func_800F6DCC) or the dropping coins
   (func_800F8200) */
typedef struct ColWork {
    /* 0x00 */ u16 flags;
    /* 0x02 */ s8 player;
    /* 0x03 */ s8 slot;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 y[10];
    /* 0x38 */ s16 count;
    /* 0x3C */ Vec3f rot;
    /* 0x48 */ Vec3f scale;
    /* 0x54 */ s16 step;
    /* 0x56 */ u16 ids[10]; /* model ids; the drop keeps {model, sprite} pairs */
    /* 0x6A */ char unk_6A[0x1E];
    /* 0x88 */ Process* child[4];
} ColWork; /* 0x98 on the N64 */

/* the background (func_800F8A00) */
typedef struct BgWork {
    /* 0x00 */ u8 flags;
    /* 0x02 */ s16 ids[9];
    /* 0x14 */ char unk_14[0x10];
    /* 0x24 */ Vec3f scale[4];
} BgWork; /* 0x54 */

/* N64: the column's flags read as the word they start (flags << 16 | player << 8 | slot) */
#define COL_FLAGS_TEST(w, m, v) ((*(s32*)(w) & (m)) == (v))
#define RES_FLAGS_TEST(p, m, v) ((*(s32*)(p) & (m)) == (v))

/* .data */
extern f32 D_800FB000_MinigameStadiumMinigameResultsScreen[4 * 4 * 3]; /* each column's coin slots */
extern s32 D_800FB0C0_MinigameStadiumMinigameResultsScreen[4];     /* each slot's column flag */
extern f32 D_800FB0D0_MinigameStadiumMinigameResultsScreen[4];     /* each player's x */
extern f32 D_800FB0E0_MinigameStadiumMinigameResultsScreen[4];
extern s16 D_800FB0F0_MinigameStadiumMinigameResultsScreen[6];
extern u8 D_800FB0FC_MinigameStadiumMinigameResultsScreen[8];
extern f32 D_800FB104_MinigameStadiumMinigameResultsScreen;
extern f32 D_800FB108_MinigameStadiumMinigameResultsScreen;
extern f32 D_800FB10C_MinigameStadiumMinigameResultsScreen;

/* .bss */
extern ResMain* D_800FB1C0_MinigameStadiumMinigameResultsScreen;
extern PlayerRes* D_800FB1C8_MinigameStadiumMinigameResultsScreen[4];
extern ColWork* D_800FB1D8_MinigameStadiumMinigameResultsScreen[4];
extern ColWork* D_800FB1E8_MinigameStadiumMinigameResultsScreen[4];
extern Process* D_800FB1F8_MinigameStadiumMinigameResultsScreen;
extern Process* D_800FB1FC_MinigameStadiumMinigameResultsScreen;
extern PlayerRes* D_800FB200_MinigameStadiumMinigameResultsScreen[4];
extern PlayerRes* D_800FB210_MinigameStadiumMinigameResultsScreen[4];
extern ColWork* D_800FB220_MinigameStadiumMinigameResultsScreen[4];
extern s8 D_800FB230_MinigameStadiumMinigameResultsScreen;
extern u16 D_800FB232_MinigameStadiumMinigameResultsScreen;
extern s32 D_800FB234_MinigameStadiumMinigameResultsScreen;
extern s16 D_800FB238_MinigameStadiumMinigameResultsScreen;
extern s16 D_800FB23A_MinigameStadiumMinigameResultsScreen;
extern BgWork* D_800FB240_MinigameStadiumMinigameResultsScreen;
extern ResMain* D_800FB244_MinigameStadiumMinigameResultsScreen;
extern PlayerRes* D_800FB248_MinigameStadiumMinigameResultsScreen[4];
extern u16 D_800FB258_MinigameStadiumMinigameResultsScreen;
extern PlayerRes* D_800FB260_MinigameStadiumMinigameResultsScreen[4];
extern u32 D_800FB270_MinigameStadiumMinigameResultsScreen;
extern s16 D_800FB280_MinigameStadiumMinigameResultsScreen;
extern s16 D_800FB282_MinigameStadiumMinigameResultsScreen;
extern s16 D_800FB284_MinigameStadiumMinigameResultsScreen;
extern s16 D_800FB28C_MinigameStadiumMinigameResultsScreen;
extern s16 D_800FB28E_MinigameStadiumMinigameResultsScreen;
extern s16 D_800FB290_MinigameStadiumMinigameResultsScreen;
extern s16 D_800FB292_MinigameStadiumMinigameResultsScreen;
extern s16 D_800FB294_MinigameStadiumMinigameResultsScreen;
extern s32 D_800FB298_MinigameStadiumMinigameResultsScreen;
extern s8 D_800FB29C_MinigameStadiumMinigameResultsScreen;
extern s16 D_800FB29E_MinigameStadiumMinigameResultsScreen;
extern s8 D_800FB2A0_MinigameStadiumMinigameResultsScreen;
extern s8 D_800FB2A1_MinigameStadiumMinigameResultsScreen;
extern s16 D_800FB2A2_MinigameStadiumMinigameResultsScreen;
extern s32 D_800FB2A4_MinigameStadiumMinigameResultsScreen;

Process* func_8005DCD8(process_func, u16, s32, s32, Process*);
void func_80018F68(u16, u8, u8, u8);
void func_80018E0C(u16, s16);
f32 func_80025D18(s16);
f32 func_80025D40(s16);
void AdjustPlayerCoins(s32, s32);
void func_8004B1B8(void);
void func_8005049C(void);
void func_8004B7F8(s32);

/* 303E70.c */
void func_800F65E0_MinigameStadiumMinigameResultsScreen(void);
void func_800F66C0_MinigameStadiumMinigameResultsScreen(void);
void func_800F67D0_MinigameStadiumMinigameResultsScreen(void);
s32 func_800F6A3C_MinigameStadiumMinigameResultsScreen(void);
s8 func_800F6AC8_MinigameStadiumMinigameResultsScreen(void);
s8 func_800F6B0C_MinigameStadiumMinigameResultsScreen(void);
s8 func_800F6B6C_MinigameStadiumMinigameResultsScreen(void);
s8 func_800F6BAC_MinigameStadiumMinigameResultsScreen(void);
void func_800F6BEC_MinigameStadiumMinigameResultsScreen(void);
void func_800F6DCC_MinigameStadiumMinigameResultsScreen(void);
f32 func_800F7158_MinigameStadiumMinigameResultsScreen(s8 slot, s16 coins);
void func_800F72B0_MinigameStadiumMinigameResultsScreen(ColWork* w, ColWork* col);
void func_800F75C0_MinigameStadiumMinigameResultsScreen(ColWork* w, ColWork* col);
void func_800F7914_MinigameStadiumMinigameResultsScreen(ColWork* w, ColWork* col, PlayerRes* res);
void func_800F7A40_MinigameStadiumMinigameResultsScreen(ColWork* w, ColWork* col, PlayerRes* res);
void func_800F7CCC_MinigameStadiumMinigameResultsScreen(ColWork* w, ColWork* col, PlayerRes* res);
void func_800F7D94_MinigameStadiumMinigameResultsScreen(ColWork* w, ColWork* col, PlayerRes* res);
void func_800F7F0C_MinigameStadiumMinigameResultsScreen(void);
void func_800F8040_MinigameStadiumMinigameResultsScreen(omObjData* obj);
void func_800F81C0_MinigameStadiumMinigameResultsScreen(omObjData* obj);
void func_800F8200_MinigameStadiumMinigameResultsScreen(void);
/* 306290.c */
void func_800F8A00_MinigameStadiumMinigameResultsScreen(void);
void func_800F8DB4_MinigameStadiumMinigameResultsScreen(void);
void func_800F8E28_MinigameStadiumMinigameResultsScreen(void);
void func_800F8E74_MinigameStadiumMinigameResultsScreen(PlayerRes* res, s32 i);
void func_800F91CC_MinigameStadiumMinigameResultsScreen(BgWork* bg, s32 i, s8 dir);
/* 306BA0.c */
void func_800F9310_MinigameStadiumMinigameResultsScreen(void);
void func_800F9654_MinigameStadiumMinigameResultsScreen(PlayerRes* res);
void func_800F97FC_MinigameStadiumMinigameResultsScreen(PlayerRes* res);
void func_800F9A0C_MinigameStadiumMinigameResultsScreen(PlayerRes* res);
void func_800F9B34_MinigameStadiumMinigameResultsScreen(PlayerRes* res);
void func_800F9BF0_MinigameStadiumMinigameResultsScreen(void);
void func_800F9C94_MinigameStadiumMinigameResultsScreen(PlayerRes* res, ColWork* col);
void func_800F9CB8_MinigameStadiumMinigameResultsScreen(ColWork* col, PlayerRes* res);
void func_800F9F54_MinigameStadiumMinigameResultsScreen(PlayerRes* res);
void func_800F9F94_MinigameStadiumMinigameResultsScreen(PlayerRes* res);
void func_800FA020_MinigameStadiumMinigameResultsScreen(PlayerRes* res);
void func_800FA1C0_MinigameStadiumMinigameResultsScreen(PlayerRes* res, ColWork* col);
void func_800FA35C_MinigameStadiumMinigameResultsScreen(PlayerRes* res);
void func_800FA64C_MinigameStadiumMinigameResultsScreen(PlayerRes* res);
void func_800FAD74_MinigameStadiumMinigameResultsScreen(PlayerRes* unused);
void func_800FADE8_MinigameStadiumMinigameResultsScreen(PlayerRes* res);
void func_800FAE64_MinigameStadiumMinigameResultsScreen(PlayerRes* res);
void func_800FAEE0_MinigameStadiumMinigameResultsScreen(PlayerRes* res);

#endif
