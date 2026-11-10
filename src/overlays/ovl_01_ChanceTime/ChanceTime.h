#ifndef CHANCETIME_H
#define CHANCETIME_H

/* ovl_01 ChanceTime (the Chance Time board event): declarations shared by its five units
   (D51E0.c, DAF90.c, DD760.c, DE2D0.c, DE6A0.c).

   Types come from the asm's accesses; N64 offsets are in the comments. A struct with no pointers
   has the same layout on the host; the pointer fields below shift every later field there, so use
   names, never offsets. Every block is allocated with sizeof (never retail's literal size).

   .data is C (each unit defines its own part, in link order); .bss stays asm (ovl_01_bss.bss.s).
   Split splat labels inside an object (D_80101AAF inside D_80101AAE, D_8010186C inside
   D_80101868...) are #defined below as views of the real object, so C never names a second host
   object for them; the asm keeps its labels (.data aliases are in undefined_syms.txt). */

#include "common.h"
#include "engine/pad.h"

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* omObjData::unk_50 of the players' objects (func_800F78C4/func_800F7E08 create them through
   func_8000979C, which allocates MgWork, src/99E0.c): the shared slot layout, pointers only at
   0xB8, 0xD8, 0xDC and 0xE4. */
typedef struct CTPlayerWork {
    /* 0x00 */ char unk_00[0x34];
    /* 0x34 */ f32 unk_34; /* height offset (func_800FEC4C adds it to trans.y) */
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C; /* speed; retail clears it with sw $zero */
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ char unk_44[0x12];
    /* 0x56 */ s8 unk_56; /* controller port */
    /* 0x57 */ char unk_57;
    /* 0x58 */ s8 unk_58; /* player index (GwPlayer) */
    /* 0x59 */ char unk_59[3];
    /* 0x5C */ s32 unk_5C; /* flags (& 6 tested) */
    /* 0x60 */ char unk_60[0x58];
    /* 0xB8 */ void* unk_B8;
    /* 0xBC */ char unk_BC[0x1C];
    /* 0xD8 */ void* unk_D8;
    /* 0xDC */ void* unk_DC;
    /* 0xE0 */ char unk_E0[4];
    /* 0xE4 */ void* unk_E4;
} CTPlayerWork; /* size = 0xE8 (N64) */

#define CT_PWORK(obj) ((CTPlayerWork*)(obj)->unk_50)

/* A reel of the Chance Time block (the three panels: left player, right player, what happens).
   CTObjWork::unk_28 of the panel objects (func_800FCC18/func_800FD7DC/func_800FE554 allocate it,
   0x3C bytes, and the panel functions func_800FC3D0/func_800FD0AC/func_800FDDD4 spin it).
   No pointers: same layout on the host.
   Endian hazard: retail reads the low byte of unk_0A (lbu 0xB) and of each unk_0C[i]
   (lbu 0xD + 2i) as a u8 argument (func_8003967C): write (u8)r->unk_0A / (u8)r->unk_0C[i],
   never a byte field at +1. */
typedef struct CTReel {
    /* 0x00 */ s8 unk_00;      /* face shown, 0..3 (& 3); read with lb as an index */
    /* 0x01 */ char unk_01;
    /* 0x02 */ s16 unk_02[4];  /* sprite (model part) per face */
    /* 0x0A */ s16 unk_0A;     /* current entry of unk_0C */
    /* 0x0C */ s16 unk_0C[21]; /* entries: characters (GwPlayer[i].character) or outcome ids */
    /* 0x36 */ s16 unk_36;     /* entry count (unk_0A wraps at it) */
    /* 0x38 */ f32 unk_38;     /* spin angle */
} CTReel; /* size = 0x3C */

/* omObjData::unk_50 of the scenery/panel objects: unkGlobalStruct_02's layout with the reel
   typed (func_80023684(sizeof), zeroed). Pointer last, so every offset is the host's too. */
typedef struct CTObjWork {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;      /* kind: 0 board, 1 backdrop, 2/3 reels */
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ char unk_0C[0x1C];
    /* 0x28 */ CTReel* unk_28;
} CTObjWork; /* size = 0x2C (N64) */

#define CT_WORK(obj) ((CTObjWork*)(obj)->unk_50)

/* A coin/star that flies between the two players (D_80101868[20]; func_800F9E74 resets them,
   func_800F9D60 launches one, func_800F9F30/func_800FA458 move them). No pointers. */
typedef struct CTCoin {
    /* 0x00 */ s16 unk_00; /* model (obj->model[1 + i] of the coin object) */
    /* 0x02 */ char unk_02[2];
    /* 0x04 */ f32 unk_04; /* x */
    /* 0x08 */ f32 unk_08; /* y */
    /* 0x0C */ f32 unk_0C; /* z */
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ s8 unk_18;  /* 1 flying */
    /* 0x19 */ s8 unk_19;  /* 1 free */
    /* 0x1A */ char unk_1A[2];
} CTCoin; /* size = 0x1C */

/* ---------------------------------------------------------------------------------------------
   Main-code declarations missing from include/ (signatures from their definitions)
   --------------------------------------------------------------------------------------------- */
void GMesSprClose(void);
void func_8003967C(s16, u8);
void func_80039644(s16, u8, u8);
s16 func_80038D5C(unk2C0C0StructC0*, u16, s16, char*);
void func_800559F8(void);
void func_80060F04(s16, s16, s16, s16);
void func_8004DBD4(s16, s8);
int guRandom(void);
extern unkCommonStruct0 GMesData[];

/* ---------------------------------------------------------------------------------------------
   Overlay functions
   --------------------------------------------------------------------------------------------- */
/* D51E0.c */
void func_800F65E0_ChanceTime(void); /* overlay entry */
void func_800F6B00_ChanceTime(omObjData* obj); /* event flow object (obj unused) */
void func_800F7108_ChanceTime(omObjData* obj); /* player func_ptr (func_800F78C4) */
void func_800F7818_ChanceTime(omObjData* obj);
void func_800F78C4_ChanceTime(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z);
void func_800F7C7C_ChanceTime(omObjData* obj); /* player func_ptr (func_800F7E08) */
void func_800F7E08_ChanceTime(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z);
void func_800F80D8_ChanceTime(omObjData* obj);
void func_800F8168_ChanceTime(omObjData* obj);
void func_800F81F8_ChanceTime(omObjData* obj);
void func_800F8288_ChanceTime(void); /* process (CPU input) */
void func_800F84B4_ChanceTime(void); /* process */
void func_800F8700_ChanceTime(s16 i);
void func_800F87CC_ChanceTime(void); /* process */
void func_800F8A6C_ChanceTime(omObjData* obj); /* func_ptr (func_800F99D8) */
void func_800F988C_ChanceTime(omObjData* obj);
void func_800F9948_ChanceTime(s32 model);
void func_800F99D8_ChanceTime(omObjData* obj);
void func_800F9B50_ChanceTime(void); /* process (message) */
s16 func_800F9D60_ChanceTime(s8 side); /* launch a coin at D_80101AA4[side]; -1 none free */
void func_800F9E74_ChanceTime(omObjData* obj);
s32 func_800F9F30_ChanceTime(omObjData* obj, s8 dir, s16 count); /* dir 0: D_801012E0 to D_801012E1, 1: back */
s32 func_800FA458_ChanceTime(omObjData* obj, s16 a, s16 b);
s8 func_800FAE60_ChanceTime(omObjData* obj);
void func_800FB00C_ChanceTime(omObjData* obj);
void func_800FB950_ChanceTime(omObjData* obj);
void func_800FBBC4_ChanceTime(omObjData* obj);
void func_800FC1C8_ChanceTime(omObjData* obj);
/* DAF90.c */
void func_800FC390_ChanceTime(void);
void func_800FC3D0_ChanceTime(omObjData* obj);
void func_800FCC18_ChanceTime(omObjData* obj);
void func_800FD0AC_ChanceTime(omObjData* obj);
void func_800FD7DC_ChanceTime(omObjData* obj);
void func_800FDDD4_ChanceTime(omObjData* obj);
void func_800FE554_ChanceTime(omObjData* obj);
void func_800FE97C_ChanceTime(omObjData* obj);
void func_800FE9D8_ChanceTime(omObjData* obj);
/* DD760.c */
void func_800FEB60_ChanceTime(f32 zoom, f32 rotX, f32 rotY, f32 rotZ, f32 x, f32 y, f32 z);
void func_800FEBA0_ChanceTime(omObjData* obj);
s16 func_800FEC4C_ChanceTime(omObjData* obj, f32 size, omObjData* other); /* returns 0/1; callers test (s16) */
void func_800FED28_ChanceTime(void); /* process */
void func_800FF2B8_ChanceTime(void); /* process */
void func_800FF354_ChanceTime(void); /* process */
void func_800FF3F0_ChanceTime(void); /* process */
/* DE2D0.c */
void func_800FF6D0_ChanceTime(omObjData* obj);
void func_800FF780_ChanceTime(omObjData* obj);
void func_800FF820_ChanceTime(void);
void func_800FF8A4_ChanceTime(omObjData* obj);
void func_800FF930_ChanceTime(omObjData* obj);
/* DE6A0.c */
void func_800FFAA0_ChanceTime(void); /* process (started by func_800FFF4C) */
s8 func_800FFF4C_ChanceTime(s8 a, s8 b);
void func_800FFFB0_ChanceTime(void); /* process (started by func_80101180) */
s8 func_80101180_ChanceTime(s16 a, s16 b); /* the caller passes lh values unextended */

/* ---------------------------------------------------------------------------------------------
   .data, by owning unit (link order). Retail reads some s16/s32 globals by their low part:
   write (u8)X / (u16)X, never the +1/+2 label.
   --------------------------------------------------------------------------------------------- */
/* D51E0.c (0x801011F0) */
extern s8 D_801011F0_ChanceTime;
extern s8 D_801011F1_ChanceTime;
extern s8 D_801011F2_ChanceTime;
extern s8 D_801011F3_ChanceTime;
extern s8 D_801011F4_ChanceTime;
extern s8 D_801011F5_ChanceTime;    /* message finished (func_800F9B50) */
extern s8 D_801011F6_ChanceTime;    /* 0 coins, 1 stars */
extern s8 D_801011F7_ChanceTime;
extern s8 D_801011F8_ChanceTime;
extern s8 D_801011F9_ChanceTime;
extern Vec D_801011FC_ChanceTime;   /* read as D_80101208[-1] (func_800FBBC4) */
extern Vec D_80101208_ChanceTime;
extern Vec D_80101214_ChanceTime;
extern Vec D_80101220_ChanceTime;
extern Vec D_8010122C_ChanceTime;
extern Vec D_80101238_ChanceTime;
extern Vec D_80101244_ChanceTime;
extern u32 D_80101250_ChanceTime;   /* func_800F6B00 state */
extern s32 D_80101254_ChanceTime;
extern s8 D_80101258_ChanceTime;
extern s8 D_80101259_ChanceTime;
extern s8 D_8010125A_ChanceTime;
extern s8 D_8010125B_ChanceTime;
extern s8 D_8010125C_ChanceTime;
extern f32 D_80101260_ChanceTime;
extern s16 D_80101264_ChanceTime;   /* 0xFF: message alpha; retail reads (u8) as D_80101265 */
extern u16 D_80101266_ChanceTime;
extern u16 D_80101268_ChanceTime;   /* func_800F7108: last button word */
extern u8 D_8010126A_ChanceTime;    /* asm: D_80101268 + 2 */
extern u16 D_8010126C_ChanceTime;
extern s8 D_8010126E_ChanceTime;    /* asm: D_8010126C + 2 (func_800F8288 state) */
extern s8 D_8010126F_ChanceTime;    /* asm: D_8010126C + 3 (func_800F84B4 state) */
extern s8 D_80101270_ChanceTime;    /* func_800F87CC state */
extern s32 D_80101274_ChanceTime;
extern s32 D_80101278_ChanceTime;   /* func_800F8A6C frame counter */
extern u32 D_8010127C_ChanceTime;   /* func_800F8A6C state */
extern s8 D_80101280_ChanceTime;
extern s8 D_80101281_ChanceTime;
extern omObjData* D_80101284_ChanceTime; /* flag object (func_800F9948) */
extern u32 D_80101288_ChanceTime;   /* -1; retail reads (u16) as D_8010128A */
extern s8 D_8010128C_ChanceTime;    /* func_800F9F30 */
extern f32 D_80101290_ChanceTime;
extern s8 D_80101294_ChanceTime;    /* func_800FA458 */
extern s8 D_80101298_ChanceTime[2]; /* an array: word-aligned after D_80101294 */
extern f32 D_8010129C_ChanceTime;
extern s8 D_801012A0_ChanceTime;    /* func_800FB00C */
extern s32 D_801012A4_ChanceTime;
extern s32 D_801012A8_ChanceTime;   /* func_800FBBC4 frame counter */
extern u32 D_801012AC_ChanceTime;   /* func_800FBBC4 state */
/* DAF90.c (0x801012B0): [0..2] = the three reels (func_800FC3D0, func_800FD0AC, func_800FDDD4) */
extern s16 D_801012B0_ChanceTime[3];
extern s8 D_801012B6_ChanceTime;
extern s16 D_801012B8_ChanceTime[3];
extern s8 D_801012C0_ChanceTime[3];
extern s16 D_801012C4_ChanceTime[3];
extern s16 D_801012CC_ChanceTime[3];
extern s8 D_801012D2_ChanceTime;
extern f32 D_801012D4_ChanceTime[2];
extern f32 D_801012DC_ChanceTime;
extern u8 D_801012E0_ChanceTime;    /* the two players (GwPlayer index), 0xFF none */
extern u8 D_801012E1_ChanceTime;
extern u8 D_801012E2_ChanceTime;    /* outcome 0..10 */
extern char* D_801012E4_ChanceTime[4]; /* "tex0_DEF".."tex3_DEF" */
extern s16 D_801012F4_ChanceTime;
extern s16 D_801012F6_ChanceTime;
extern s16 D_801012F8_ChanceTime;
extern s16 D_801012FA_ChanceTime;
extern u8 D_801012FC_ChanceTime[20]; /* outcome reel order */
extern u8 D_80101310_ChanceTime[6];
extern s16 D_80101316_ChanceTime;
extern s16 D_80101318_ChanceTime;
extern s16 D_8010131A_ChanceTime;
/* DAF90.c .rodata (0x801015D0) */
extern const char D_801015D0_ChanceTime[];
extern const char D_801015DC_ChanceTime[];
extern const char D_801015E8_ChanceTime[];
extern const char D_801015F4_ChanceTime[];
/* DD760.c (0x80101320) */
extern s8 D_80101320_ChanceTime;    /* message process done */
extern s16 D_80101324_ChanceTime[2]; /* coins/stars to move */
extern s16 D_80101328_ChanceTime[2];
extern s8 D_8010132C_ChanceTime;
extern char* D_80101330_ChanceTime[6]; /* [character]: name */
extern char* D_80101348_ChanceTime[6]; /* "Stars", "Coins", "none", 0, 0, 0 */
/* DD760.c .rodata (0x80101630) */
extern const char D_80101630_ChanceTime[];
extern const char D_80101634_ChanceTime[];
extern const char D_8010163C_ChanceTime[];
extern const char D_80101644_ChanceTime[];
extern const char D_8010164C_ChanceTime[];
extern const char D_80101654_ChanceTime[];
extern const char D_8010165C_ChanceTime[];
extern const char D_80101664_ChanceTime[];
extern const char D_8010166C_ChanceTime[];
/* DE2D0.c (0x80101360) */
extern s8 D_80101360_ChanceTime;
/* DE6A0.c (0x80101370) */
extern s8 D_80101370_ChanceTime;    /* result of the swap process */
extern void* D_80101374_ChanceTime; /* func_80042728 result, freed by func_800427D4 */
extern s8 D_80101378_ChanceTime;    /* func_800FFF4C started */
extern s8 D_80101379_ChanceTime;    /* func_80101180 started */

/* Labels inside those objects (the asm's are undefined_syms.txt aliases) */
#define D_80101265_ChanceTime ((u8)D_80101264_ChanceTime)
#define D_8010128A_ChanceTime ((u16)D_80101288_ChanceTime)
#define D_80101299_ChanceTime (D_80101298_ChanceTime[1])
#define D_801012B2_ChanceTime (D_801012B0_ChanceTime[1])
#define D_801012B4_ChanceTime (D_801012B0_ChanceTime[2])
#define D_801012BA_ChanceTime (D_801012B8_ChanceTime[1])
#define D_801012BC_ChanceTime (D_801012B8_ChanceTime[2])
#define D_801012C1_ChanceTime (D_801012C0_ChanceTime[1])
#define D_801012C2_ChanceTime (D_801012C0_ChanceTime[2])
#define D_801012C6_ChanceTime (D_801012C4_ChanceTime[1])
#define D_801012C8_ChanceTime (D_801012C4_ChanceTime[2])
#define D_801012CE_ChanceTime (D_801012CC_ChanceTime[1])
#define D_801012D0_ChanceTime (D_801012CC_ChanceTime[2])
#define D_80101326_ChanceTime (D_80101324_ChanceTime[1])

/* ---------------------------------------------------------------------------------------------
   .bss (ovl_01_bss.bss.s, 0x801016F0..0x80101AE0)
   --------------------------------------------------------------------------------------------- */
extern s16 D_801016F0_ChanceTime;
extern s32 D_801016F4_ChanceTime;
extern u8 D_801016F8_ChanceTime[4]; /* [0..1] player order (indexed by D_8010126A); func_800F7108
                                       writes [2] through D_801016FA and [1] at its -1 */
extern s16 D_801016FC_ChanceTime;
extern CTPlayerWork* D_80101700_ChanceTime; /* D_800F3FB0[0]'s work (func_800F8288) */
extern CTPlayerWork* D_80101704_ChanceTime; /* (func_800F84B4) */
extern CTPlayerWork* D_80101708_ChanceTime; /* (func_800F87CC) */
extern s16 D_8010170C_ChanceTime;   /* sound handle (PlaySound); 0x32 unreferenced bytes follow */
extern s8 D_80101740_ChanceTime;    /* func_800F9F30 */
extern s8 D_80101741_ChanceTime;
extern s16 D_80101742_ChanceTime;
extern s16 D_80101744_ChanceTime;
extern s16 D_80101746_ChanceTime;
extern f32 D_80101748_ChanceTime;
extern s16 D_8010174C_ChanceTime[2]; /* func_800FA458 */
extern f32 D_80101750_ChanceTime[2];
extern s16 D_80101758_ChanceTime[2];
extern s8 D_8010175C_ChanceTime;    /* message order */
extern s16 D_80101760_ChanceTime;   /* model (func_800FC390); 0x1E unreferenced bytes follow */
extern char D_80101780_ChanceTime[0x1C]; /* sprintf buffer (func_800FF3F0) */
extern Vec D_8010179C_ChanceTime[6]; /* func_8004CCD0 path (func_800FFAA0/func_800FFFB0) */
extern Vec D_801017E4_ChanceTime[5];
extern Object* D_80101820_ChanceTime; /* MBModelCreate */
extern Vec D_80101824_ChanceTime;
extern Vec D_80101830_ChanceTime;
extern s8 D_8010183C_ChanceTime;    /* func_800FFF4C's two players */
extern s8 D_8010183D_ChanceTime;
extern s8 D_8010183E_ChanceTime[2]; /* func_80101180's two values */
extern omObjData* D_80101840_ChanceTime[2]; /* the side panels' objects */
extern omObjData* D_80101848_ChanceTime; /* 0x1C unreferenced bytes follow */
extern CTCoin D_80101868_ChanceTime[20];
/* Saved and CPU controller state, [controller port] */
extern u8 D_80101A98_ChanceTime[4];  /* saved ContStkY */
extern u16 D_80101A9C_ChanceTime[4]; /* CPU ContBtn */
extern s8 D_80101AA4_ChanceTime[2];  /* the two players' D_800F3FB0 indices */
extern u16 D_80101AA6_ChanceTime[4]; /* saved ContBtn */
extern s8 D_80101AAE_ChanceTime[4];  /* player index of each D_800F3FB0 object */
extern u8 D_80101AB2_ChanceTime[4];  /* CPU ContStkY */
extern u16 D_80101AB6_ChanceTime;    /* reel texture (func_80038A9C) */
extern u8 D_80101AB8_ChanceTime[4];  /* CPU ContStkX */
extern u16 D_80101ABC_ChanceTime[2];
extern u16 D_80101AC0_ChanceTime;
extern u16 D_80101AC2_ChanceTime[4]; /* saved ContBtnTrg */
extern u8 D_80101ACA_ChanceTime[4];  /* saved ContStkX */
extern u16 D_80101ACE_ChanceTime[4]; /* CPU ContBtnTrg (2 bytes follow) */
extern omObjData* D_80101AD8_ChanceTime;

/* Views of the split .bss labels: write these as elements/fields, never as separate objects */
#define D_801016FA_ChanceTime (D_801016F8_ChanceTime[2])
#define D_8010174E_ChanceTime (D_8010174C_ChanceTime[1])
#define D_80101754_ChanceTime (D_80101750_ChanceTime[1])
#define D_8010175A_ChanceTime (D_80101758_ChanceTime[1])
#define D_80101828_ChanceTime (D_80101824_ChanceTime.y)
#define D_8010183F_ChanceTime (D_8010183E_ChanceTime[1])
#define D_8010186C_ChanceTime (D_80101868_ChanceTime[0].unk_04)
#define D_80101870_ChanceTime (D_80101868_ChanceTime[0].unk_08)
#define D_80101874_ChanceTime (D_80101868_ChanceTime[0].unk_0C)
#define D_80101878_ChanceTime (D_80101868_ChanceTime[0].unk_10)
#define D_8010187C_ChanceTime (D_80101868_ChanceTime[0].unk_14)
#define D_80101880_ChanceTime (D_80101868_ChanceTime[0].unk_18)
#define D_80101881_ChanceTime (D_80101868_ChanceTime[0].unk_19)
#define D_80101AA5_ChanceTime (D_80101AA4_ChanceTime[1])
#define D_80101AAF_ChanceTime (D_80101AAE_ChanceTime[1])
#define D_80101AB0_ChanceTime (D_80101AAE_ChanceTime[2])
#define D_80101AB1_ChanceTime (D_80101AAE_ChanceTime[3])

#endif
