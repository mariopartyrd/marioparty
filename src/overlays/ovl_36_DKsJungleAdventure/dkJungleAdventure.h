#include "common.h"
#include "spaces.h"

extern s16 D_800F9910_DKsJungleAdventure[];

extern board_overlay_entrypoint D_800F9890_DKsJungleAdventure[];

//extern mpSource_f2b7cstruct *D_800F2B7C;

#define DK_STAR_COUNT 7
#define DK_BOO_COUNT 2
#define DK_COIN_GATE_COUNT 2
#define DK_THWOMP_COUNT 3

extern s16 D_800F98D0_DKsJungleAdventure[]; //ov054_func_800F663C_data0
    //3, 5, 6, 0, 1, 2, 4

extern s16 D_800F98E0_DKsJungleAdventure[]; //ov054_func_800F663C_data1
    //0, 0, 0, 1, 1, 1, 3

extern s16 D_800F98F0_DKsJungleAdventure[]; //ov054_data_mystery_40s
    //0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C

extern s16 D_800F9900_DKsJungleAdventure[]; //ov054_star_space_indices
    //0x77, 0x80, 0x7F, 0x84, 0x83, 0x75, 0x76

extern s16 D_800F9910_DKsJungleAdventure[]; //ov054_toad_space_indices
    //0x61, 0x6E, 0x6D, 0x72, 0x71, 0x5F, 0x60

extern s32 D_800F9920_DKsJungleAdventure[]; //ov054_data_star_related_800F9920
    //0, 1, 7, 3

extern s16 D_800F9928_DKsJungleAdventure[]; //ov054_toad_space_indices_repeat
    //0x61, 0x6E, 0x6D, 0x72, 0x71, 0x5F, 0x60

extern s16 D_800F9938_DKsJungleAdventure[]; //ov054_data_mystery_40s_2
    //0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C

struct D_800F9948_tuple {
    s16 one;
    s16 two;
};

extern struct D_800F9948_tuple D_800F9948_DKsJungleAdventure[];
    // { 6, 0 },
    // { 0, -3 },
    // { 0, -8 },
    // { -3, 0 },
    // { -2, 0 },
    // { -2, 0 },
    // { -3, 0 },

extern s16 D_800ED172;
extern s16 D_800EE320;

extern EventTableEntry main_event_table[]; //800FA0CC
extern EventTableEntry koopa_event_table[]; //800FA1FC
extern EventTableEntry boo_event_table[]; //800FA20C
extern EventTableEntry bowser_event_table[]; //800FA224

// board_overlay_entrypoint D_800F9890_DKsJungleAdventure[] = {
//     {0, &func_800F6F0C_DKsJungleAdventure },
//     {1, &func_800F6F44_DKsJungleAdventure },
//     {2, &func_800F7190_DKsJungleAdventure },
//     {3, &func_800F7224_DKsJungleAdventure },
//     {4, &func_800F983C_DKsJungleAdventure },
//     {-1, 0},
// }; 
// .data (asm, 2418D0.data.s)
extern Vec4f D_800F98C0_DKsJungleAdventure;
extern s16 D_800F9964_DKsJungleAdventure[]; // boardWork index per thwomp
extern s16 D_800F996C_DKsJungleAdventure[]; // thwomp space (boardWork clear)
extern s16 D_800F9974_DKsJungleAdventure[]; // thwomp space (boardWork set)
extern s16 D_800F997C_DKsJungleAdventure[]; // thwomp facing space
extern s32 D_800F9984_DKsJungleAdventure[]; // MBModelCreate motion list (words)
extern s16 D_800F998C_DKsJungleAdventure[]; // boo spaces
extern s16 D_800F9990_DKsJungleAdventure[]; // coin gate spaces
extern s16 D_800F9994_DKsJungleAdventure[]; // coin gate facing
extern DecisionTreeNonLeafNode D_800F9ADC_DKsJungleAdventure[];
extern DecisionTreeNonLeafNode D_800F9C74_DKsJungleAdventure[];
extern DecisionTreeNonLeafNode D_800F9D7C_DKsJungleAdventure[];
extern DecisionTreeNonLeafNode D_800F9E30_DKsJungleAdventure[];
extern DecisionTreeNonLeafNode D_800F9F38_DKsJungleAdventure[];
extern s16 D_800F9F5C_DKsJungleAdventure[];
extern s16 D_800F9F7C_DKsJungleAdventure[];
extern s16 D_800F9F9C_DKsJungleAdventure[];
extern s16 D_800F9FCC_DKsJungleAdventure[]; // boulder path, -1 terminated
extern s16 D_800F9FEC_DKsJungleAdventure[];
extern s16 D_800FA004_DKsJungleAdventure[];
extern EventTableEntry D_800FA0CC_DKsJungleAdventure[];
extern EventTableEntry D_800FA1FC_DKsJungleAdventure[];
extern EventTableEntry D_800FA20C_DKsJungleAdventure[];
extern EventTableEntry D_800FA224_DKsJungleAdventure[];

// .bss (asm, ovl_36_bss.bss.s): only the labels below are named in C, so the host
// generator folds splat's split labels (D_800FA318/D_800FA320 = toads [2]/[4],
// D_800FA350 = gates [1]) into these arrays.
extern Object* D_800FA308_DKsJungleAdventure;    // toad model
extern Object* D_800FA310_DKsJungleAdventure[7]; // toads
extern Object* D_800FA32C_DKsJungleAdventure;    // thwomp model
extern Object* D_800FA330_DKsJungleAdventure[3]; // thwomps
extern Object* D_800FA33C_DKsJungleAdventure;    // boo model
extern Object* D_800FA340_DKsJungleAdventure[2]; // boos
extern Object* D_800FA348_DKsJungleAdventure;    // coin gate model
extern Object* D_800FA34C_DKsJungleAdventure[2]; // coin gates
extern s32 D_800FA354_DKsJungleAdventure;
extern s32 D_800FA358_DKsJungleAdventure;
extern s32 D_800FA35C_DKsJungleAdventure;
extern s32 D_800FA360_DKsJungleAdventure;
extern f32 D_800FA364_DKsJungleAdventure;
extern f32 D_800FA368_DKsJungleAdventure;
extern s16 D_800FA36C_DKsJungleAdventure;
extern Object* D_800FA370_DKsJungleAdventure;    // boulder

typedef struct DKThwompMove {
    /* 0x0 */ Object* obj;
    /* 0x4 */ BoardSpace* dest;
    /* 0x8 */ BoardSpace* facing;
} DKThwompMove;

// main-code functions without a shared prototype
void func_8004DBD4(s32, s32);
void* func_80058A4C(s16 player, s16 type, s32 delay); // RumbleLoop*
void func_80058AD0(void* r);
void func_8004CD48(Object*, s16);
void func_80056E30(s16);
s16 func_80056E3C(void);
void func_8004A7A4(void);
void func_8004A7DC(void);
f32 func_8004B5D0(void);
f32 func_8004B844(void);
s16 func_80060758(s16);
void func_80060BC8(s16, s16);
s16 GetChainSpaceIndexFromAbsSpaceIndex(s16 absIndex, s32 chainIndex);
s16 BoardGetChainLength(u16 chainIndex);
void func_8004220C(void);

// this overlay's functions (2418D0.c)
void func_800F72CC_DKsJungleAdventure(void);
void func_800F72EC_DKsJungleAdventure(void);
void func_800F7368_DKsJungleAdventure(void);
void func_800F7388_DKsJungleAdventure(s16);
void func_800F748C_DKsJungleAdventure(void);
void func_800F7514_DKsJungleAdventure(s16);
void func_800F766C_DKsJungleAdventure(void);
void func_800F76B0_DKsJungleAdventure(s16);
void func_800F77B8_DKsJungleAdventure(void);
void func_800F77FC_DKsJungleAdventure(s16);
void func_800F78DC_DKsJungleAdventure(void);
void func_800F7920_DKsJungleAdventure(void);
void func_800F79D0_DKsJungleAdventure(void);
void func_800F8114_DKsJungleAdventure(void);
void func_800F83B0_DKsJungleAdventure(void);
void func_800F8448_DKsJungleAdventure(void);
void func_800F84E0_DKsJungleAdventure(void);
void func_800F85BC_DKsJungleAdventure(void);
void func_800F869C_DKsJungleAdventure(void);
void func_800F8978_DKsJungleAdventure(void);
void func_800F8DC8_DKsJungleAdventure(void);
Process* func_800F8E80_DKsJungleAdventure(Object*);
void func_800F8EBC_DKsJungleAdventure(void);
Process* func_800F8F88_DKsJungleAdventure(Object*);
void func_800F9470_DKsJungleAdventure(void);
void func_800F95A4_DKsJungleAdventure(void);
s16 func_800F6958_DKsJungleAdventure(s32);
s16 func_800F6610_DKsJungleAdventure(void);
void func_800F6CD8_DKsJungleAdventure(void);
