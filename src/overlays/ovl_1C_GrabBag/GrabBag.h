#include "common.h"

extern omObjData* D_800EDE70[6];   // Array of omObjData pointers?
extern u16 D_800EE984;                   // Offset into D_800EDE70 array.

/* The four player objects' work (D_800F3FB0[i]->unk_50, 0x100 bytes from func_800F7EDC). The
   fields through 0xE4 are main code's MgWork/PlayerWork layout (src/99E0.c, src/1130.c), which
   main-code helpers read through the same object: its pointers sit where MgWork's do (0xB8, 0xD8,
   0xDC, 0xE4) so the host layout agrees. 0xE8 on is this overlay's extension. */
typedef struct GrabBagPlayerWork {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ char unk_02[3];
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ char unk_28[0xC];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38; /* 1000.0f after a collision */
    /* 0x3C */ f32 angle;  /* facing angle (degrees) */
    /* 0x40 */ f32 speed;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 radius; /* collision radius */
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ s8 unk_53;
    /* 0x54 */ s8 unk_54;
    /* 0x55 */ u8 unk_55;
    /* 0x56 */ s8 port;   /* controller port */
    /* 0x57 */ u8 unk_57;
    /* 0x58 */ s8 player; /* player index */
    /* 0x59 */ char unk_59[3];
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 radius_offset;
    /* 0x68 */ f32 unk_68;
    /* 0x6C */ s32 unk_6C[6];
    /* 0x84 */ char unk_84[0xC];
    /* 0x90 */ f32 unk_90;
    /* 0x94 */ f32 unk_94;
    /* 0x98 */ f32 unk_98;
    /* 0x9C */ char unk_9C[4];
    /* 0xA0 */ f32 unk_A0;
    /* 0xA4 */ f32 unk_A4;
    /* 0xA8 */ char unk_A8[9];
    /* 0xB1 */ s8 unk_B1;
    /* 0xB2 */ s8 unk_B2;
    /* 0xB3 */ s8 unk_B3;
    /* 0xB4 */ char unk_B4[4];
    /* 0xB8 */ omObjData* unk_B8;
    /* 0xBC */ f32 unk_BC;
    /* 0xC0 */ u16 unk_C0;
    /* 0xC2 */ char unk_C2[0x16];
    /* 0xD8 */ s16 (*unk_D8)[2]; /* one pair per motion */
    /* 0xDC */ void* unk_DC;
    /* 0xE0 */ char unk_E0[4];
    /* 0xE4 */ void* unk_E4;
    /* 0xE8 */ s8 unk_E8; /* -1: CPU player */
    /* 0xE9 */ s8 unk_E9;
    /* 0xEA */ s8 unk_EA;
    /* 0xEB */ u8 unk_EB;
    /* 0xEC */ s8 unk_EC;
    /* 0xED */ s8 unk_ED;
    /* 0xEE */ s8 button_press_count;
    /* 0xEF */ u8 unk_EF;
    /* 0xF0 */ u8 unk_F0;
    /* 0xF1 */ u8 unk_F1;
    /* 0xF2 */ s16 score;
    /* 0xF4 */ s16 unk_F4;
    /* 0xF6 */ s16 unk_F6;
    /* 0xF8 */ s16 total; /* score + unk_F4 + unk_F6 */
    /* 0xFA */ s16 start_score;
    /* 0xFC */ s16 start_total;
    /* 0xFE */ s16 unk_FE;
} GrabBagPlayerWork; /* size = 0x100 on the N64 */

typedef struct GrabBagPos {
    s16 x;
    s16 y;
} GrabBagPos;

#define GB_PLAYER(obj) ((GrabBagPlayerWork*)(obj)->unk_50)

/* The six bags' work (D_800EDE70[i]->unk_50, 0x70 bytes from func_800F6C98). Main code's item
   collision (src/1130.c) reads it through its PlayerWork view below 0x60; no pointers, so the
   host layout is the N64 one. */
typedef struct GrabBagBagWork {
    /* 0x00 */ char unk_00[0x22];
    /* 0x22 */ u8 unk_22; /* image of model 1 (func_80009340) */
    /* 0x23 */ char unk_23[0x11];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ s8 unk_52;
    /* 0x53 */ char unk_53;
    /* 0x54 */ u8 unk_54;
    /* 0x55 */ char unk_55[3];
    /* 0x58 */ f32 unk_58;
    /* 0x5C */ s32 unk_5C; /* frames since grabbed; nonzero: not available */
    /* 0x60 */ s32 unk_60;
    /* 0x64 */ char unk_64[8];
    /* 0x6C */ s8 unk_6C;
    /* 0x6D */ s8 unk_6D; /* grabbing player (D_800F3FB0 index), -1 none */
    /* 0x6E */ s8 unk_6E;
    /* 0x6F */ char unk_6F;
} GrabBagBagWork; /* size = 0x70 */

#define GB_BAG(obj) ((GrabBagBagWork*)(obj)->unk_50)

void func_800F6C98_GrabBag(omObjData*);
void func_800F6E90_GrabBag(omObjData*);
void func_800091BC(omObjData*, s32, s32, s32);
void func_800F66F8_GrabBag(void);
void func_800F67BC_GrabBag(void);
void func_800F6C08_GrabBag(void);
void func_800F7260_GrabBag(void);
void func_800F7680_GrabBag(void);
void func_80017C0C(omObjData* obj, u8 idx, f32 x, f32 y, f32 z, f32 a, f32 b);
void func_80008FA0(omObjData* obj, f32 arg1);
void func_80008FDC(omObjData* obj, f32 arg1);
void func_80008FE8(omObjData* obj, f32 arg1);
void func_800370D4(s16);
void func_8002859C(s16 arg0, s16 arg1, char* arg2);
void func_800090C4(omObjData* obj, u8 idx, u8 val);
void func_80060F04(s16 player, s16 arg1, s16 arg2, s16 arg3);
void func_8006035C(s16 arg0, s8 arg1);
