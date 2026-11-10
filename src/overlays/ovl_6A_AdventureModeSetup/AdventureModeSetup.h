#include "common.h"

typedef struct unkAMSetupStruct01 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
} unkAMSetupStruct01;

typedef struct unk_D80102450_AdventureModeSetup {
    /* 0x00 */ char unk00[0x18];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ char unk20[4];
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ char unk30[4];
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
    /* 0x3C */ s32 unk3C; // a counter (retail loads/stores it as int)
} unk_D80102450_AdventureModeSetup;

extern s8 omSysPauseEnableFlag;
// extern void* D_800C59B0[];
extern u8 D_800F64F8;

extern board_overlay_entrypoint D_80101840_AdventureModeSetup[];
void func_800F6610_AdventureModeSetup();
void func_800F6630_AdventureModeSetup();
void func_800F6654_AdventureModeSetup();
void func_800F6678_AdventureModeSetup();
extern const char D_80101DB0_AdventureModeSetup[];
extern const char D_80101DB4_AdventureModeSetup[];
extern const char D_80101DB8_AdventureModeSetup[];
extern const char D_80101DBC_AdventureModeSetup[];
extern const char D_80101DC0_AdventureModeSetup[];
extern s32 D_80101870_AdventureModeSetup[][4];
extern s32 D_801018B0_AdventureModeSetup[][8]; /* neighbour table */
extern s32 D_80101A40_AdventureModeSetup;
extern s32 D_80101ADC_AdventureModeSetup;
extern u16 D_80101ADE_AdventureModeSetup; /* the low half of D_80101ADC (undefined_syms alias) */
extern s32 D_80101AE4_AdventureModeSetup;
extern s32 D_80101E4C_AdventureModeSetup;
extern f32 D_80101E50_AdventureModeSetup;
extern Vec3f D_80101E54_AdventureModeSetup;
extern Vec3f D_80101E60_AdventureModeSetup;
extern f32 D_80101E6C_AdventureModeSetup;
extern f32 D_80101F10_AdventureModeSetup;
extern f32 D_80101F14_AdventureModeSetup;
extern f32 D_80101F18_AdventureModeSetup;
extern f32 D_80101F1C_AdventureModeSetup;
extern f32 D_80101F60_AdventureModeSetup[];
extern s32 D_80101F74_AdventureModeSetup;
extern s32 D_80101F78_AdventureModeSetup;
extern omObjData* D_80101F88_AdventureModeSetup[];
extern s32 D_80101F70_AdventureModeSetup;
extern omObjData* D_80101F7C_AdventureModeSetup;
extern omObjData* D_80101FA0_AdventureModeSetup;
extern omObjData* D_80101FA4_AdventureModeSetup;
extern omObjData* D_80101FA8_AdventureModeSetup;
extern omObjData* D_80101FB0_AdventureModeSetup[];
extern omObjData* D_80101FC0_AdventureModeSetup;
extern omObjData* D_80101FC4_AdventureModeSetup;
extern omObjData* D_80101FC8_AdventureModeSetup[];
extern omObjData* D_80101FD8_AdventureModeSetup[];
extern omObjData* D_80101FE8_AdventureModeSetup[];
extern omObjData* D_80101FFC_AdventureModeSetup;
extern omObjData* D_80101FF8_AdventureModeSetup;
/* Two Vec3f at D_80102000 and D_8010200C; splat's D_80102004/D_80102010/D_80102014 are their
   .y/.z, read as overlapping Vec3f views. On the host those labels are views of the two objects. */
extern Vec3f D_80102000_AdventureModeSetup;
extern Vec3f D_8010200C_AdventureModeSetup;
extern Vec3f D_80102004_AdventureModeSetup;
extern Vec3f D_80102010_AdventureModeSetup;
extern Vec3f D_80102018_AdventureModeSetup;
extern unk_Struct00 D_80102410_AdventureModeSetup;
extern unk_D80102450_AdventureModeSetup D_80102450_AdventureModeSetup;
/* D_80102410 is a 0x40 record (fields to unk30.z) and D_80102450 a 0x40 struct: splat's
   D_80102448, D_80102474 and D_80102478 are their fields. On the host they are views. */
extern f32 D_80102448_AdventureModeSetup;
extern f32 D_80102474_AdventureModeSetup;
extern f32 D_80102478_AdventureModeSetup;
extern s16 D_801025B4_AdventureModeSetup;
extern s32 D_801025B8_AdventureModeSetup;
extern s32 D_801025BC_AdventureModeSetup;
extern s32 D_801025C0_AdventureModeSetup;
extern s32 D_801025C4_AdventureModeSetup;
extern s32 D_801025C8_AdventureModeSetup;
extern s32 D_801025CC_AdventureModeSetup;
extern void* D_801025D0_AdventureModeSetup;
extern unk_Struct02* D_801025D4_AdventureModeSetup;
extern u16 D_801025D8_AdventureModeSetup[];     // seems wrong... used as u16, s16*
extern s16 D_801025DA_AdventureModeSetup;
extern f32 D_801025DC_AdventureModeSetup;
extern f32 D_801025E0_AdventureModeSetup;
extern f32 D_801025E4_AdventureModeSetup;
extern Object* D_801025E8_AdventureModeSetup;
extern void* D_801025EC_AdventureModeSetup;
extern f32 D_801025F0_AdventureModeSetup;
extern u16 D_801025F4_AdventureModeSetup[];
extern u16 D_801025FA_AdventureModeSetup[];
extern omObjData* D_80102610_AdventureModeSetup;

f32 func_80029518(f32);
void MBModelClose();
void func_800427E4();
void func_800532E0();
void func_800532F4();
void func_8006CE64(s16, s16, s16, s16);
void func_800A1250(Vec3f*);

void func_800F66A8_AdventureModeSetup();
void func_800F6EEC_AdventureModeSetup();
void func_80101338_AdventureModeSetup();
void func_801014C0_AdventureModeSetup(omObjData*);
void func_801014F8_AdventureModeSetup(omObjData*);
void func_8010179C_AdventureModeSetup();

// temp:
void func_800F6F34_AdventureModeSetup(omObjData*);
void func_800F70E4_AdventureModeSetup();
void func_800F71DC_AdventureModeSetup();
s32 func_800F70CC_AdventureModeSetup(s32);
void func_800F72E0_AdventureModeSetup();
void func_800F86F8_AdventureModeSetup(omObjData*);
void func_800F88EC_AdventureModeSetup(omObjData*);
void func_800F8D90_AdventureModeSetup(omObjData*);
void func_800F8FD8_AdventureModeSetup(omObjData*);
void func_800F9090_AdventureModeSetup();
void func_800FB30C_AdventureModeSetup(omObjData*);
void func_800FBBE8_AdventureModeSetup(omObjData*);
void func_800FBD98_AdventureModeSetup();
void func_800FBEC0_AdventureModeSetup(omObjData*);
void func_800FC924_AdventureModeSetup(omObjData*);
void func_800FCAB8_AdventureModeSetup();
void func_800FD3D8_AdventureModeSetup();
void func_800FD804_AdventureModeSetup();
void func_800FE68C_AdventureModeSetup(omObjData*);
void func_800FF064_AdventureModeSetup();
void func_800FF0A0_AdventureModeSetup();
void func_800FF328_AdventureModeSetup();
// void func_80100198_AdventureModeSetup(omObjData*);
void func_8010042C_AdventureModeSetup(omObjData*);
void func_80100528_AdventureModeSetup();
void func_80100564_AdventureModeSetup(omObjData*);
void func_80100744_AdventureModeSetup(omObjData*);
void func_801008B4_AdventureModeSetup();
void func_80100BF8_AdventureModeSetup(omObjData*);
void func_80100C88_AdventureModeSetup(omObjData*);
void func_80100D84_AdventureModeSetup();
void func_80100E48_AdventureModeSetup(omObjData*);
void func_801010E0_AdventureModeSetup(omObjData*);
void func_80101170_AdventureModeSetup(omObjData*);

/* ---- fork A ---- */
/* omObjData::unk_50 work block (same layout as MgWork in src/99E0.c). */
typedef struct AMSObjWork {
    /* 0x00 */ char unk_00[0x4C];
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ char unk_53[3];
    /* 0x56 */ s8 unk_56;
    /* 0x57 */ char unk_57[9];
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ char unk_64[0x2C];
    /* 0x90 */ f32 unk_90;
    /* 0x94 */ f32 unk_94;
    /* 0x98 */ f32 unk_98;
    /* 0x9C */ char unk_9C[8];
    /* 0xA4 */ f32 unk_A4;
    /* 0xA8 */ char unk_A8[9];
    /* 0xB1 */ s8 unk_B1;
    /* 0xB2 */ char unk_B2[6];
    /* 0xB8 */ omObjData* unk_B8;
    /* 0xBC */ f32 unk_BC;
    /* 0xC0 */ u16 unk_C0;
    /* 0xC2 */ char unk_C2[0x16];
    /* 0xD8 */ s16 (*unk_D8)[2];
    /* 0xDC */ void* unk_DC; /* as MgWork */
    /* 0xE0 */ char unk_E0[4];
    /* 0xE4 */ void* unk_E4; /* as MgWork */
} AMSObjWork; /* size = 0xE8 */



extern f32 D_80101E40_AdventureModeSetup;
extern f32 D_80101E44_AdventureModeSetup;
extern f32 D_80101E48_AdventureModeSetup;
extern f32 D_80102014_AdventureModeSetup;

s32 func_8005B470(s16); /* retail's call has no extension of the result (an int return) */
void func_80071FF4(s32, u8);
void func_801015D0_AdventureModeSetup(void);
void func_80101274_AdventureModeSetup();
void func_80101374_AdventureModeSetup();
void func_800F88C0_AdventureModeSetup(omObjData*);
void func_800F88D4_AdventureModeSetup(omObjData*);
void func_80008FA0(omObjData*, f32);
void func_80008FDC(omObjData*, f32);
void func_80008FE8(omObjData*, f32);
void func_80008FF4(omObjData*, f32);
/* ---- end fork A ---- */
/* ---- fork B ---- */
extern u8 D_80101E88_AdventureModeSetup[];
extern s32 D_80101E90_AdventureModeSetup[];
extern f32 D_80101EA8_AdventureModeSetup[];
extern f32 D_80101EC0_AdventureModeSetup[];
extern f32 D_80101ED8_AdventureModeSetup[];
extern f32 D_801019D0_AdventureModeSetup[][2]; /* 4 (x, y) pairs; splat split it at D_801019D4 */
extern f32 D_80101A20_AdventureModeSetup[];
extern f32 D_80101A30_AdventureModeSetup[];
void func_800F6958_AdventureModeSetup(omObjData*, Vec3f*);
typedef struct AMSWork {
    u8 w0, w1, w2, w3;
} AMSWork; /* omObjData.work[] as fields: retail tests two of them in one word */
#define AMS_WORK(o) ((AMSWork*)(o)->work)
extern f32 D_80101970_AdventureModeSetup[][4];
extern s32 D_80101A10_AdventureModeSetup[];
extern s32 D_80101E70_AdventureModeSetup;
extern s32 D_80101E74_AdventureModeSetup;
extern s32 D_80101E78_AdventureModeSetup;
extern s32 D_80101E7C_AdventureModeSetup;
extern f32 D_80101E80_AdventureModeSetup;
extern f32 D_80101E84_AdventureModeSetup;
s32 func_800F9030_AdventureModeSetup(s32, s32);
void func_80052CCC(s32, s32);
/* ---- end fork B ---- */
/* ---- fork C ---- */
extern s32 D_80101A64_AdventureModeSetup;
extern s32 D_80101A68_AdventureModeSetup;
typedef struct AMSetup3C {
    /* 0x00 */ f32 unk00;
    /* 0x04 */ f32 unk04;
    /* 0x08 */ char unk08[0x1C];
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ char unk38[4];
} AMSetup3C; /* sizeof 0x3C */
typedef struct AMSetupVec2 {
    f32 x;
    f32 y;
} AMSetupVec2;
extern AMSetupVec2 D_801019F0_AdventureModeSetup[];
extern s32 D_80101A44_AdventureModeSetup[];
extern f32 D_80101A54_AdventureModeSetup[];
extern s32 D_80101EF0_AdventureModeSetup;
extern f32 D_80101EF4_AdventureModeSetup;
extern f32 D_80101EF8_AdventureModeSetup;
extern f32 D_80101EFC_AdventureModeSetup;
extern f32 D_80101F00_AdventureModeSetup;
extern f32 D_80101F04_AdventureModeSetup;
extern f32 D_80101F08_AdventureModeSetup;
extern AMSetup3C D_80102320_AdventureModeSetup[];
s32 func_800FCA78_AdventureModeSetup(s32, s32, s32);
extern s32 D_80101F0C_AdventureModeSetup;
s32 func_800141FC(s16);
extern s32 D_80101A6C_AdventureModeSetup;
extern s32 D_80101F20_AdventureModeSetup;
extern f32 D_80101F24_AdventureModeSetup;
extern f32 D_80101F28_AdventureModeSetup;
extern f32 D_80101F2C_AdventureModeSetup;
extern f32 D_80101F30_AdventureModeSetup;
extern f32 D_80101F34_AdventureModeSetup;
extern f32 D_80101F38_AdventureModeSetup;
extern f32 D_80101F3C_AdventureModeSetup;
extern f32 D_80101F40_AdventureModeSetup;
/* ---- end fork C ---- */
/* ---- fork D ---- */
typedef struct unkAMSetupSprites3 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s16 sprite[3];
} unkAMSetupSprites3; // sizeof 0xC

typedef struct unkAMSetupSprites5 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s16 sprite[5];
} unkAMSetupSprites5; // sizeof 0x10

extern f32 D_80101F50_AdventureModeSetup[];
extern s32 D_80101AE0_AdventureModeSetup;
void func_80100958_AdventureModeSetup(omObjData*);
extern s8 ContStkY[];
extern s32 D_80101F44_AdventureModeSetup;
extern f32 D_80101F48_AdventureModeSetup;
extern f32 D_80101F4C_AdventureModeSetup;
extern void* D_80101A70_AdventureModeSetup[8][3]; /* [board][answer - 1]: message string */
extern void* D_80101AD0_AdventureModeSetup[]; /* retail indexes it from D_80101ACC: [n - 1], n = 1..3 */
#define AMSD_ABS(x) (((x) < 0.0f) ? -(x) : (x))
/* ---- end fork D ---- */

/* ---- bss blocks that retail indexes across splat's labels ----
   Each block is one object: the C names its base label, and the labels inside it are views of the
   base. The N64 build keeps splat's separate symbols (same addresses, same codegen); on the host the
   inner labels are macros over the base object, so gen_ovl.py emits one object per block and the
   cross-label indexing (count at D_801025A4 - 0x20, [4] of D_80102570, pieces 2..6) stays inside it.
   The blocks hold no pointers, so the host layout is the N64 layout. */

/* D_80102028: 7 records of 0x6C, indexed by omObjData::work[0] (splat split it at D_8010206C). */
typedef struct AMSPiece {
    /* 0x00 */ char unk00[0xC];
    /* 0x0C */ Vec3f unkC;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ Vec3f unk24;
    /* 0x30 */ Vec3f unk30;
    /* 0x3C */ f32 unk3C;
    /* 0x40 */ f32 unk40;
    /* 0x44 */ f32 unk44;
    /* 0x48 */ f32 unk48;
    /* 0x4C */ f32 unk4C;
    /* 0x50 */ f32 unk50;
    /* 0x54 */ f32 unk54;
    /* 0x58 */ s32 unk58;
    /* 0x5C */ char unk5C[0x10];
} AMSPiece; /* size = 0x6C */
extern AMSPiece D_80102028_AdventureModeSetup[7];
#define AMS_PIECES D_80102028_AdventureModeSetup
#define AMSD_CHAR D_80102028_AdventureModeSetup

/* D_80102570..0x801025B3: the selection state. Retail addresses it as one object (one base
   register for D_80102584 and D_8010259C, D_80102570 reached as D_80102584 - 0x14). */
typedef struct AMSSelect {
    /* 0x00 */ s32 joined[4]; /* D_80102570: per controller port, nonzero = human */
    /* 0x10 */ s32 port;      /* D_80102580 (its low half is D_80102582) */
    /* 0x14 */ s32 count;     /* D_80102584: humans */
    /* 0x18 */ s32 unk18[4];  /* D_80102588: character per port */
    /* 0x28 */ s32 unk28;     /* board index */
    /* 0x2C */ s32 unk2C;     /* D_8010259C */
    /* 0x30 */ s32 unk30;     /* D_801025A0: mode; low half (D_801025A2) = play type */
    /* 0x34 */ s32 coins[4];  /* D_801025A4: low half = start coins */
} AMSSelect; /* size = 0x44 */
extern AMSSelect D_80102570_AdventureModeSetup;
#define AMS_SEL D_80102570_AdventureModeSetup

/* The same block from D_80102580 (fork D's view). */
typedef struct unkAMSetupState {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 count;    /* humans */
    /* 0x08 */ s32 order[4]; /* character per port */
    /* 0x18 */ s32 sel;      /* board index */
    /* 0x1C */ s32 mode;     /* low half = play type */
    /* 0x20 */ s32 coins[4]; /* low half = start coins */
} unkAMSetupState;

extern s32 D_8010206C_AdventureModeSetup;
extern unkAMSetupStruct01 D_80102580_AdventureModeSetup;
extern s32 D_80102584_AdventureModeSetup;
extern s32 D_80102588_AdventureModeSetup;
extern unkAMSetupStruct01 D_8010259C_AdventureModeSetup;
extern s32 D_801025A0_AdventureModeSetup;
extern u16 D_801025A2_AdventureModeSetup;
extern s32 D_801025A4_AdventureModeSetup;

#define AMS_ACTIVE (AMS_SEL.joined)
#define AMSD_ACTIVE (AMS_SEL.joined)
#define AMS_SLOTS ((s32*)&D_80102588_AdventureModeSetup)
#define AMSD_ORDER ((s32*)&D_80102588_AdventureModeSetup)  /* s32[4]: character per port */
#define AMSD_COINS ((s32*)&D_801025A4_AdventureModeSetup)  /* s32[4]: low half = start coins */
#define AMS_A4 ((s32*)&D_801025A4_AdventureModeSetup)
#define AMSD_AR ((s32*)&D_80102584_AdventureModeSetup) /* [0] humans, [1..4] character per port */
#define AMSD_S (*(unkAMSetupState*)&D_80102580_AdventureModeSetup)
#define AMS_CUR (D_80102580_AdventureModeSetup.unk00)
#define AMS_COUNT (D_80102580_AdventureModeSetup.unk04)
#define AMSD_MODE D_801025A0_AdventureModeSetup

/* D_80102490: per-player camera/cursor moves. */
typedef struct unkAMSetupMove {
    /* 0x00 */ Vec3f target;
    /* 0x0C */ s32 frames;
    /* 0x10 */ Vec3f step;
} unkAMSetupMove; /* size = 0x1C */
extern unkAMSetupMove D_80102490_AdventureModeSetup[];

extern unkAMSetupSprites3 D_80102500_AdventureModeSetup[];
#define AMS_2500 D_80102500_AdventureModeSetup
extern unkAMSetupSprites5 D_80102530_AdventureModeSetup[];
#define AMS_2530 D_80102530_AdventureModeSetup
#define AMSD_SPR5 D_80102530_AdventureModeSetup
#define AMSD_ALPHA5 D_80101F60_AdventureModeSetup
#define AMS_NEIGHBORS D_801018B0_AdventureModeSetup
