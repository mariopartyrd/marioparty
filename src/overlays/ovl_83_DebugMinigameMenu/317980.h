#include "common.h"
#include "engine/pad.h"

/* One entry of the debug minigame menu (9 pages of 10), as ovl_7A/7E's DebugMg. */
typedef struct DebugMgEntry {
    /* 0x00 */ u8 skip;  /* 1: not selectable */
    /* 0x01 */ u8 num;   /* minigame number (1-based) */
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ s32 ovl;
    /* 0x08 */ u32 mes; /* message id << 16 */
    /* 0x0C */ char* name;
} DebugMgEntry;

/* Per entry: the team of each player, and unknown bytes. */
typedef struct DebugMgTeams {
    /* 0x00 */ u8 group[4];
    /* 0x04 */ u8 unk4[4];
    /* 0x08 */ s16 unk8[4];
} DebugMgTeams;

/* A menu sound: the sound id and its volume (s16 pairs). */
typedef struct DebugSe {
    s16 id;
    s16 vol;
} DebugSe;

/* .data */
extern DebugMgEntry D_800F98B0_DebugMinigameMenu[90];
extern DebugMgTeams D_800F9E50_DebugMinigameMenu[90];
extern DebugSe D_800FA3F0_DebugMinigameMenu[5];
extern s16 D_800FA404_DebugMinigameMenu[2][2]; /* text colours: plain, selected (and shadow) */
extern DebugMgEntry D_800FA40C_DebugMinigameMenu[6]; /* option rows: format strings */
extern char* D_800FA46C_DebugMinigameMenu[2];
extern char* D_800FA474_DebugMinigameMenu[4];
extern char* D_800FA484_DebugMinigameMenu[6];
extern char* D_800FA49C_DebugMinigameMenu[3];
extern s32 D_800FA4A8_DebugMinigameMenu;
extern s32 D_800FA4AC_DebugMinigameMenu;
/* D_800FA4AE: the low half of s32 D_800FA4AC. */
extern s16 D_800FA4AE_DebugMinigameMenu;
extern s32 D_800FA4B0_DebugMinigameMenu;
extern s32 D_800FA4B4_DebugMinigameMenu;

/* .bss */
extern s16 D_800FAC40_DebugMinigameMenu; /* page */
extern s16 D_800FAC42_DebugMinigameMenu; /* entry on the page */
extern s16 D_800FAC48_DebugMinigameMenu[9]; /* last entry per page */
extern s16 D_800FAC5A_DebugMinigameMenu; /* option row */
extern s16 D_800FAC5C_DebugMinigameMenu; /* option player */
extern s16 D_800FAC5E_DebugMinigameMenu; /* option state: 0 player, 1 row */
extern GW_PLAYER D_800FAC60_DebugMinigameMenu[4];
extern u8 D_800FAD50_DebugMinigameMenu[4]; /* player ready */
extern u8 D_800FAD54_DebugMinigameMenu[6]; /* character taken */
extern s16 D_800FAD5A_DebugMinigameMenu[6]; /* character models */
extern s16 D_800FAD68_DebugMinigameMenu[6];
extern s16 D_800FAD74_DebugMinigameMenu[6];
extern s16 D_800FAD80_DebugMinigameMenu[4];
extern s8 D_800FAD88_DebugMinigameMenu[4]; /* last stick x */
extern s8 D_800FAD8C_DebugMinigameMenu[4]; /* last stick y */
extern u8 D_800FAD90_DebugMinigameMenu;
extern s16 D_800FAD92_DebugMinigameMenu;
extern s16 D_800FAD94_DebugMinigameMenu;
extern u16 D_800FAD96_DebugMinigameMenu; /* cursor sprite */
extern s16 D_800FAD98_DebugMinigameMenu;
extern u16 D_800FADA0_DebugMinigameMenu[40];
extern f32 D_800FADF0_DebugMinigameMenu[4];
extern u8 D_800FAE00_DebugMinigameMenu[4]; /* menu keys this frame */
extern u16 D_800FAE04_DebugMinigameMenu[4]; /* held direction */
extern u16 D_800FAE0C_DebugMinigameMenu[4]; /* hold time */
extern u16 D_800FAE14_DebugMinigameMenu[4]; /* repeat delay */

/* D_800F3779: the low byte of s16 D_800F3778 (the number of controllers). */
extern u8 D_800F3779;

extern u32 D_800C5968;
extern s16 D_800C596C;
extern u8 D_800C5970;
extern s16 D_800F370E;
extern s32 fontcolor;

void func_8001897C(s16, f32, f32, f32);
void func_80059280(void);
void func_80018DC4(u16, f32);
void func_80018F68(u16, u8, u8, u8);
u8 func_80018ED8(u16);
void func_800191F8(u16);
void func_80025BB8(s16, s16);
void func_8006035C(s16, s8);

void func_800F65E0_DebugMinigameMenu(void);
void func_800F6B14_DebugMinigameMenu(f32, f32, f32, f32, f32, f32, f32);
void func_800F6BAC_DebugMinigameMenu(omObjData*);
void func_800F7350_DebugMinigameMenu(omObjData*);
void func_800F75CC_DebugMinigameMenu(omObjData*);
void func_800F79E0_DebugMinigameMenu(omObjData*);
void func_800F7BD4_DebugMinigameMenu(omObjData*);
void func_800F855C_DebugMinigameMenu(omObjData*);
void func_800F8A24_DebugMinigameMenu(omObjData*);
void func_800F8A34_DebugMinigameMenu(omObjData*);
void func_800F9400_DebugMinigameMenu(u16);
void func_800F944C_DebugMinigameMenu(s16);
void func_800F94C8_DebugMinigameMenu(s16);
void func_800F95F8_DebugMinigameMenu(u16, u16, char*, u16, u16);
void func_800F9678_DebugMinigameMenu(void);
void func_800F96DC_DebugMinigameMenu(void);
void func_800F9744_DebugMinigameMenu(void);
void func_800F9810_DebugMinigameMenu(void);
