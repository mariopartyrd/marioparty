#include "common.h"
#include "engine/process.h"
#include "spaces.h"

/* A coin-gate direction event (func_800F7608 / func_800F77F4). */
typedef struct MagmaGateEvent {
    /* 0x00 */ s16 boardWork0;
    /* 0x04 */ s16* spaceIDs;
    /* 0x08 */ DecisionTreeNonLeafNode* decisionTree;
    /* 0x0C */ s16 chain0;
    /* 0x0E */ s16 space0;
    /* 0x10 */ s16 chain1;
    /* 0x12 */ s16 space1;
    /* 0x14 */ s16 gateDir;
} MagmaGateEvent; // N64 size 0x18

/* One falling rock of the eruption (func_800F7C8C's user_data). */
typedef struct MagmaRock {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ f32 scale;
    /* 0x08 */ f32 dx;
    /* 0x0C */ BoardSpace* space; // filled at run time
} MagmaRock; // N64 size 0x10

struct MagmaTuple {
    s16 one;
    s16 two;
};

// main-code functions without a shared prototype
void func_8004DBD4(s32, s32);
void* func_80058A4C(s16 player, s16 type, s32 delay); // RumbleLoop*
void func_80058AD0(void* r);
void func_80056E30(s16);
void func_80056E48(Vec3f*);
f32 func_8004B844(void);
void func_8004220C(void);
void BoardSetSpaceTypeInChain(u16 chainIndex, u16 oldType, u8 newType);

// this overlay's functions
s16 func_800F6610_BowsersMagmaMountain(void);
void func_800F663C_BowsersMagmaMountain(void);
void func_800F66DC_BowsersMagmaMountain(void);
void func_800F6768_BowsersMagmaMountain(void);
s16 func_800F6890_BowsersMagmaMountain(s32);
void func_800F6970_BowsersMagmaMountain(void);
void func_800F6C10_BowsersMagmaMountain(void);
void func_800F6F08_BowsersMagmaMountain(void);
void func_800F7114_BowsersMagmaMountain(void);
void func_800F7198_BowsersMagmaMountain(void);
void func_800F71B8_BowsersMagmaMountain(void);
void func_800F7234_BowsersMagmaMountain(void);
void func_800F7254_BowsersMagmaMountain(s16);
void func_800F7354_BowsersMagmaMountain(void);
void func_800F73DC_BowsersMagmaMountain(void);
void func_800F7480_BowsersMagmaMountain(void);
void func_800F74A0_BowsersMagmaMountain(void);
void func_800F7550_BowsersMagmaMountain(void);
void func_800F759C_BowsersMagmaMountain(void);
void func_800F75D0_BowsersMagmaMountain(void);
void func_800F7608_BowsersMagmaMountain(MagmaGateEvent*);
void func_800F77F4_BowsersMagmaMountain(MagmaGateEvent*);
void func_800F7858_BowsersMagmaMountain(void);
void func_800F7880_BowsersMagmaMountain(void);
void func_800F78A0_BowsersMagmaMountain(void);
void func_800F78C8_BowsersMagmaMountain(void);
void func_800F78E8_BowsersMagmaMountain(void);
void func_800F7910_BowsersMagmaMountain(void);
void func_800F7930_BowsersMagmaMountain(void);
void func_800F7954_BowsersMagmaMountain(void);
void func_800F7978_BowsersMagmaMountain(void);
void func_800F799C_BowsersMagmaMountain(void);
void func_800F79D4_BowsersMagmaMountain(void);
void func_800F7B50_BowsersMagmaMountain(void);
void func_800F7C8C_BowsersMagmaMountain(void);
void func_800F7D60_BowsersMagmaMountain(void);
void func_800F7EB8_BowsersMagmaMountain(void);
void func_800F819C_BowsersMagmaMountain(void);
void func_800F826C_BowsersMagmaMountain(void);
void func_800F8290_BowsersMagmaMountain(void);
void func_800F83C4_BowsersMagmaMountain(void);
void func_800F8494_BowsersMagmaMountain(void);
void func_800F84C8_BowsersMagmaMountain(void);
void func_800F84FC_BowsersMagmaMountain(void);
void func_800F8560_BowsersMagmaMountain(void);
void func_800F85EC_BowsersMagmaMountain(void);
void func_800F8664_BowsersMagmaMountain(void);

/* .data (0x800F8790..0x800F9160) */
Vec4f D_800F8790_BowsersMagmaMountain = { 0.0f, 0.0f, 320.0f, 240.0f };
s16 D_800F87A0_BowsersMagmaMountain = 14; // star order rows
s16 D_800F87A4_BowsersMagmaMountain[14][7] = {
    { 3, 0, 4, 1, 5, 2, 6 },
    { 4, 0, 3, 1, 5, 2, 6 },
    { 3, 0, 3, 1, 5, 2, 6 },
    { 4, 0, 3, 1, 6, 2, 5 },
    { 3, 1, 4, 0, 5, 2, 6 },
    { 4, 1, 3, 0, 5, 2, 6 },
    { 3, 1, 4, 0, 6, 2, 5 },
    { 4, 1, 3, 0, 6, 2, 5 },
    { 3, 1, 4, 2, 5, 0, 6 },
    { 3, 1, 4, 2, 6, 0, 5 },
    { 3, 0, 4, 2, 5, 1, 6 },
    { 3, 0, 4, 2, 6, 1, 5 },
    { 4, 2, 6, 0, 3, 1, 5 },
    { 4, 2, 6, 1, 3, 0, 5 },
};
s16 D_800F8868_BowsersMagmaMountain[] = { 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0 }; // star flags
s16 D_800F8878_BowsersMagmaMountain[] = { 0x43, 0x4A, 0x4C, 0x4E, 0x50, 0x45, 0x46, 0 }; // star spaces
s16 D_800F8888_BowsersMagmaMountain[] = { 0x38, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 0 }; // toad spaces
s32 D_800F8898_BowsersMagmaMountain[] = { 1, 0x70003 }; /* MBModelCreate motion list: words */
s32 D_800F88A0_BowsersMagmaMountain[] = { 1, 0xA006A }; /* MBModelCreate motion list: words */
s16 D_800F88A8_BowsersMagmaMountain[] = { 0x38, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 0 };
s16 D_800F88B8_BowsersMagmaMountain[] = { 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0 };
/* splat's D_800F88CA is the .two half of entry 0 onwards */
struct MagmaTuple D_800F88C8_BowsersMagmaMountain[] = {
    { 0, -4 }, { 0, -4 }, { 0, -4 }, { 0, -3 }, { -4, 0 }, { 0, -2 }, { 4, 0 },
};
DecisionTreeNonLeafNode D_800F88E4_BowsersMagmaMountain[4] = {
    { 0x05000000, { (void*)0x1 }, { 0x00010500 } },
    { 0x05000000, { (void*)0x2 }, { 0x00010A05 } },
    { 0x05000000, { (void*)0x4 }, { 0x00011E0A } },
    { 0x00000000, { (void*)0x0 }, { 0x00012814 } },
};
DecisionTreeNonLeafNode D_800F8914_BowsersMagmaMountain[5] = {
    { 0x01000000, { (void*)0x1E }, { (u32)D_800F88E4_BowsersMagmaMountain } },
    { 0x05000000, { (void*)0x1 }, { 0x00010000 } },
    { 0x05000000, { (void*)0x2 }, { 0x00010505 } },
    { 0x05000000, { (void*)0x4 }, { 0x00010A05 } },
    { 0x00000000, { (void*)0x0 }, { 0x0001140A } },
};
DecisionTreeNonLeafNode D_800F8950_BowsersMagmaMountain[4] = {
    { 0x05000000, { (void*)0x1 }, { 0x00010514 } },
    { 0x05000000, { (void*)0x2 }, { 0x0001050A } },
    { 0x05000000, { (void*)0x4 }, { 0x00010005 } },
    { 0x00000000, { (void*)0x0 }, { 0x00010000 } },
};
DecisionTreeNonLeafNode D_800F8980_BowsersMagmaMountain[4] = {
    { 0x05000000, { (void*)0x1 }, { 0x00013C14 } },
    { 0x05000000, { (void*)0x2 }, { 0x0001461E } },
    { 0x05000000, { (void*)0x4 }, { 0x00015A32 } },
    { 0x00000000, { (void*)0x0 }, { 0x00015F3C } },
};
DecisionTreeNonLeafNode D_800F89B0_BowsersMagmaMountain[4] = {
    { 0x05000000, { (void*)0x1 }, { 0x00012814 } },
    { 0x05000000, { (void*)0x2 }, { 0x0001321E } },
    { 0x05000000, { (void*)0x4 }, { 0x00014632 } },
    { 0x00000000, { (void*)0x0 }, { 0x0001503C } },
};
DecisionTreeNonLeafNode D_800F89E0_BowsersMagmaMountain[6] = {
    { 0x01000000, { (void*)0x1E }, { (u32)D_800F8980_BowsersMagmaMountain } },
    { 0x03000000, { (void*)0x3 }, { (u32)D_800F89B0_BowsersMagmaMountain } },
    { 0x05000000, { (void*)0x1 }, { 0x00011E28 } },
    { 0x05000000, { (void*)0x2 }, { 0x0001141E } },
    { 0x05000000, { (void*)0x4 }, { 0x00010A14 } },
    { 0x00000000, { (void*)0x0 }, { 0x0001050A } },
};
DecisionTreeNonLeafNode D_800F8A28_BowsersMagmaMountain[2] = {
    { 0x05000000, { (void*)0x1 }, { 0x0001281E } },
    { 0x00000000, { (void*)0x0 }, { 0x00011E0A } },
};
DecisionTreeNonLeafNode D_800F8A40_BowsersMagmaMountain[6] = {
    { 0x02000000, { (void*)0x1 }, { (u32)D_800F8914_BowsersMagmaMountain } },
    { 0x02000000, { (void*)0x2 }, { (u32)D_800F8950_BowsersMagmaMountain } },
    { 0x02000000, { (void*)0x4 }, { (u32)D_800F89E0_BowsersMagmaMountain } },
    { 0x01000000, { (void*)0x1E }, { (u32)D_800F8A28_BowsersMagmaMountain } },
    { 0x05000000, { (void*)0x1 }, { 0x00012814 } },
    { 0x00000000, { (void*)0x0 }, { 0x00011E0A } },
};
DecisionTreeNonLeafNode D_800F8A88_BowsersMagmaMountain[4] = {
    { 0x05000000, { (void*)0x1 }, { 0x00003228 } },
    { 0x05000000, { (void*)0x2 }, { 0x00003228 } },
    { 0x05000000, { (void*)0x4 }, { 0x00003C32 } },
    { 0x00000000, { (void*)0x0 }, { 0x00003C32 } },
};
DecisionTreeNonLeafNode D_800F8AB8_BowsersMagmaMountain[5] = {
    { 0x01000000, { (void*)0x1E }, { (u32)D_800F8A88_BowsersMagmaMountain } },
    { 0x05000000, { (void*)0x1 }, { 0x0000281E } },
    { 0x05000000, { (void*)0x2 }, { 0x00002814 } },
    { 0x05000000, { (void*)0x4 }, { 0x00003214 } },
    { 0x00000000, { (void*)0x0 }, { 0x00003214 } },
};
DecisionTreeNonLeafNode D_800F8AF4_BowsersMagmaMountain[4] = {
    { 0x05000000, { (void*)0x1 }, { 0x00000514 } },
    { 0x05000000, { (void*)0x2 }, { 0x0000050A } },
    { 0x05000000, { (void*)0x4 }, { 0x00000005 } },
    { 0x00000000, { (void*)0x0 }, { 0x00000000 } },
};
DecisionTreeNonLeafNode D_800F8B24_BowsersMagmaMountain[4] = {
    { 0x05000000, { (void*)0x1 }, { 0x00002814 } },
    { 0x05000000, { (void*)0x2 }, { 0x0000321E } },
    { 0x05000000, { (void*)0x4 }, { 0x00004632 } },
    { 0x00000000, { (void*)0x0 }, { 0x0000503C } },
};
DecisionTreeNonLeafNode D_800F8B54_BowsersMagmaMountain[4] = {
    { 0x05000000, { (void*)0x1 }, { 0x00003C14 } },
    { 0x05000000, { (void*)0x2 }, { 0x0000461E } },
    { 0x05000000, { (void*)0x4 }, { 0x00005A32 } },
    { 0x00000000, { (void*)0x0 }, { 0x0000643C } },
};
DecisionTreeNonLeafNode D_800F8B84_BowsersMagmaMountain[6] = {
    { 0x01000000, { (void*)0x1E }, { (u32)D_800F8B54_BowsersMagmaMountain } },
    { 0x03000000, { (void*)0xF }, { (u32)D_800F8B24_BowsersMagmaMountain } },
    { 0x05000000, { (void*)0x1 }, { 0x00001428 } },
    { 0x05000000, { (void*)0x2 }, { 0x0000141E } },
    { 0x05000000, { (void*)0x4 }, { 0x00000A14 } },
    { 0x00000000, { (void*)0x0 }, { 0x0000050A } },
};
DecisionTreeNonLeafNode D_800F8BCC_BowsersMagmaMountain[2] = {
    { 0x05000000, { (void*)0x1 }, { 0x0000281E } },
    { 0x00000000, { (void*)0x0 }, { 0x00003228 } },
};
DecisionTreeNonLeafNode D_800F8BE4_BowsersMagmaMountain[6] = {
    { 0x02000000, { (void*)0x3 }, { (u32)D_800F8AB8_BowsersMagmaMountain } },
    { 0x02000000, { (void*)0xC }, { (u32)D_800F8AF4_BowsersMagmaMountain } },
    { 0x02000000, { (void*)0x10 }, { (u32)D_800F8B84_BowsersMagmaMountain } },
    { 0x01000000, { (void*)0x1E }, { (u32)D_800F8BCC_BowsersMagmaMountain } },
    { 0x05000000, { (void*)0x1 }, { 0x00002814 } },
    { 0x00000000, { (void*)0x0 }, { 0x00001E0A } },
};
DecisionTreeNonLeafNode D_800F8C2C_BowsersMagmaMountain[4] = {
    { 0x05000000, { (void*)0x1 }, { 0x00013C14 } },
    { 0x05000000, { (void*)0x2 }, { 0x0001461E } },
    { 0x05000000, { (void*)0x4 }, { 0x00015A32 } },
    { 0x00000000, { (void*)0x0 }, { 0x0001643C } },
};
DecisionTreeNonLeafNode D_800F8C5C_BowsersMagmaMountain[4] = {
    { 0x05000000, { (void*)0x1 }, { 0x00012814 } },
    { 0x05000000, { (void*)0x2 }, { 0x0001321E } },
    { 0x05000000, { (void*)0x4 }, { 0x00014632 } },
    { 0x00000000, { (void*)0x0 }, { 0x0001503C } },
};
DecisionTreeNonLeafNode D_800F8C8C_BowsersMagmaMountain[6] = {
    { 0x01000000, { (void*)0x1E }, { (u32)D_800F8C2C_BowsersMagmaMountain } },
    { 0x03000000, { (void*)0x7 }, { (u32)D_800F8C5C_BowsersMagmaMountain } },
    { 0x05000000, { (void*)0x1 }, { 0x00011428 } },
    { 0x05000000, { (void*)0x2 }, { 0x0001141E } },
    { 0x05000000, { (void*)0x4 }, { 0x00010A14 } },
    { 0x00000000, { (void*)0x0 }, { 0x0001050A } },
};
DecisionTreeNonLeafNode D_800F8CD4_BowsersMagmaMountain[4] = {
    { 0x05000000, { (void*)0x1 }, { 0x00013214 } },
    { 0x05000000, { (void*)0x2 }, { 0x0001320A } },
    { 0x05000000, { (void*)0x4 }, { 0x00010005 } },
    { 0x00000000, { (void*)0x0 }, { 0x00010000 } },
};
DecisionTreeNonLeafNode D_800F8D04_BowsersMagmaMountain[4] = {
    { 0x05000000, { (void*)0x1 }, { 0x0001321E } },
    { 0x05000000, { (void*)0x2 }, { 0x0001321E } },
    { 0x05000000, { (void*)0x4 }, { 0x00012828 } },
    { 0x00000000, { (void*)0x0 }, { 0x00012828 } },
};
DecisionTreeNonLeafNode D_800F8D34_BowsersMagmaMountain[7] = {
    { 0x02000000, { (void*)0x40 }, { (u32)D_800F8C8C_BowsersMagmaMountain } },
    { 0x02000000, { (void*)0x38 }, { (u32)D_800F8CD4_BowsersMagmaMountain } },
    { 0x01000000, { (void*)0x1E }, { (u32)D_800F8D04_BowsersMagmaMountain } },
    { 0x05000000, { (void*)0x1 }, { 0x0001281E } },
    { 0x05000000, { (void*)0x2 }, { 0x00012814 } },
    { 0x05000000, { (void*)0x4 }, { 0x00013214 } },
    { 0x00000000, { (void*)0x0 }, { 0x00013214 } },
};
EventListEntry D_800F8D88_BowsersMagmaMountain[] = {
    { 1, 1, func_800F759C_BowsersMagmaMountain },
    { 2, 1, func_800F75D0_BowsersMagmaMountain },
    { 0, 0, NULL },
};
s16 D_800F8DA0_BowsersMagmaMountain[] = { 0x2C, 0x07, -1, 0 };
MagmaGateEvent D_800F8DA8_BowsersMagmaMountain = { 0, D_800F8DA0_BowsersMagmaMountain, D_800F8A40_BowsersMagmaMountain, 1, 0, 3, 0, 1 };
EventListEntry D_800F8DC0_BowsersMagmaMountain[] = {
    { 1, 2, func_800F7858_BowsersMagmaMountain },
    { 2, 1, func_800F7880_BowsersMagmaMountain },
    { 0, 0, NULL },
};
s16 D_800F8DD8_BowsersMagmaMountain[] = { 0x14, 0x05, -1, 0 };
MagmaGateEvent D_800F8DE0_BowsersMagmaMountain = { 1, D_800F8DD8_BowsersMagmaMountain, D_800F8BE4_BowsersMagmaMountain, 5, 0, 2, 0, 0 };
EventListEntry D_800F8DF8_BowsersMagmaMountain[] = {
    { 1, 2, func_800F78A0_BowsersMagmaMountain },
    { 2, 1, func_800F78C8_BowsersMagmaMountain },
    { 0, 0, NULL },
};
s16 D_800F8E10_BowsersMagmaMountain[] = { 0x10, 0x23, -1, 0 };
MagmaGateEvent D_800F8E18_BowsersMagmaMountain = { 2, D_800F8E10_BowsersMagmaMountain, D_800F8D34_BowsersMagmaMountain, 4, 0, 8, 1, 1 };
EventListEntry D_800F8E30_BowsersMagmaMountain[] = {
    { 1, 2, func_800F78E8_BowsersMagmaMountain },
    { 2, 1, func_800F7910_BowsersMagmaMountain },
    { 0, 0, NULL },
};
EventListEntry D_800F8E48_BowsersMagmaMountain[] = {
    { 1, 1, func_800F7930_BowsersMagmaMountain },
    { 0, 0, NULL },
};
EventListEntry D_800F8E58_BowsersMagmaMountain[] = {
    { 1, 1, func_800F7954_BowsersMagmaMountain },
    { 0, 0, NULL },
};
EventListEntry D_800F8E68_BowsersMagmaMountain[] = {
    { 1, 1, func_800F7978_BowsersMagmaMountain },
    { 0, 0, NULL },
};
EventListEntry D_800F8E78_BowsersMagmaMountain[] = {
    { 1, 1, func_800F799C_BowsersMagmaMountain },
    { 0, 0, NULL },
};
/* splat's D_800F8E94 is D_800F8E88[0].space onwards */
MagmaRock D_800F8E88_BowsersMagmaMountain[22] = {
    { 0xF, 0x4F, 3.0f, 0.0f, NULL },
    { 0xF, 0x4F, 3.0f, -10.0f, NULL },
    { 0xF, 0x4F, 3.0f, -5.0f, NULL },
    { 0xF, 0x4F, 3.0f, -7.0f, NULL },
    { 0xF, 0x4F, 3.0f, 0.0f, NULL },
    { 0xF, 0x4F, 3.0f, -7.0f, NULL },
    { 0xF, 0x4F, 3.0f, -5.0f, NULL },
    { 0xF, 0x4F, 3.0f, 1.0f, NULL },
    { 0xF, 0x4F, 3.0f, -4.0f, NULL },
    { 0xF, 0x4F, 3.0f, -3.0f, NULL },
    { 0xF, 0x4F, 3.0f, 7.0f, NULL },
    { 0xF, 0x4F, 3.0f, 10.0f, NULL },
    { 0xF, 0x4F, 3.0f, 6.0f, NULL },
    { 0xF, 0x4F, 3.0f, 4.0f, NULL },
    { 0xF, 0x4F, 3.0f, -6.0f, NULL },
    { 0xF, 0x4F, 3.0f, 6.0f, NULL },
    { 0xF, 0x4F, 3.0f, 10.0f, NULL },
    { 0xF, 0x4F, 3.0f, 7.0f, NULL },
    { 0xF, 0x4F, 3.0f, 4.0f, NULL },
    { 0xF, 0x4F, 3.0f, 3.0f, NULL },
    { 0xF, 0x4F, 3.0f, -5.0f, NULL },
    { 0xF, 0x4F, 3.0f, 3.0f, NULL },
};
EventListEntry D_800F8FE8_BowsersMagmaMountain[] = {
    { 3, 2, func_800F819C_BowsersMagmaMountain },
    { 0, 0, NULL },
};
EventListEntry D_800F8FF8_BowsersMagmaMountain[] = {
    { 3, 2, func_800F819C_BowsersMagmaMountain },
    { 1, 1, func_800F7978_BowsersMagmaMountain },
    { 0, 0, NULL },
};
EventListEntry D_800F9010_BowsersMagmaMountain[] = {
    { 1, 1, func_800F826C_BowsersMagmaMountain },
    { 0, 0, NULL },
};
EventListEntry D_800F9020_BowsersMagmaMountain[] = {
    { 1, 1, func_800F826C_BowsersMagmaMountain },
    { 1, 2, func_800F8494_BowsersMagmaMountain },
    { 0, 0, NULL },
};
EventListEntry D_800F9038_BowsersMagmaMountain[] = {
    { 1, 1, func_800F84C8_BowsersMagmaMountain },
    { 0, 0, NULL },
};
EventListEntry D_800F9048_BowsersMagmaMountain[] = {
    { 1, 1, func_800F84FC_BowsersMagmaMountain },
    { 3, 1, func_800F8560_BowsersMagmaMountain },
    { 0, 0, NULL },
};
EventListEntry D_800F9060_BowsersMagmaMountain[] = {
    { 7, 1, func_800F85EC_BowsersMagmaMountain },
    { 0, 0, NULL },
};
EventListEntry D_800F9070_BowsersMagmaMountain[] = {
    { 7, 2, func_800F8664_BowsersMagmaMountain },
    { 0, 0, NULL },
};
EventTableEntry D_800F9080_BowsersMagmaMountain[] = {
    { -4, D_800F9060_BowsersMagmaMountain },
    { -5, D_800F9070_BowsersMagmaMountain },
    { 0x43, D_800F9048_BowsersMagmaMountain },
    { 0x4A, D_800F9048_BowsersMagmaMountain },
    { 0x4C, D_800F9048_BowsersMagmaMountain },
    { 0x4E, D_800F9048_BowsersMagmaMountain },
    { 0x50, D_800F9048_BowsersMagmaMountain },
    { 0x45, D_800F9048_BowsersMagmaMountain },
    { 0x46, D_800F9048_BowsersMagmaMountain },
    { 0x51, D_800F8D88_BowsersMagmaMountain },
    { 0x49, D_800F8DC0_BowsersMagmaMountain },
    { 0x4B, D_800F8DF8_BowsersMagmaMountain },
    { 0x4D, D_800F8E30_BowsersMagmaMountain },
    { 0x48, D_800F9010_BowsersMagmaMountain },
    { 0x06, D_800F8E48_BowsersMagmaMountain },
    { 0x13, D_800F8E58_BowsersMagmaMountain },
    { 0x20, D_800F8E68_BowsersMagmaMountain },
    { 0x01, D_800F8FE8_BowsersMagmaMountain },
    { 0x0A, D_800F8FE8_BowsersMagmaMountain },
    { 0x15, D_800F8FE8_BowsersMagmaMountain },
    { 0x33, D_800F8FF8_BowsersMagmaMountain },
    { 0x27, D_800F8FE8_BowsersMagmaMountain },
    { 0x47, D_800F8E78_BowsersMagmaMountain },
    { -1, NULL },
};
EventTableEntry D_800F9140_BowsersMagmaMountain[] = {
    { 0x48, D_800F9020_BowsersMagmaMountain },
    { -1, NULL },
};
EventTableEntry D_800F9150_BowsersMagmaMountain[] = {
    { 0x44, D_800F9038_BowsersMagmaMountain },
    { -1, NULL },
};

/* .bss (asm, ovl_3C_bss.bss.s) */
extern Object* D_800F9160_BowsersMagmaMountain;    // bowser
extern Object* D_800F9164_BowsersMagmaMountain;    // koopa
extern Object* D_800F9168_BowsersMagmaMountain;    // toad model
extern Object* D_800F9170_BowsersMagmaMountain[7]; // toads
extern Object* D_800F918C_BowsersMagmaMountain;    // boo
extern s32 D_800F9190_BowsersMagmaMountain;
extern s32 D_800F9194_BowsersMagmaMountain;
extern s32 D_800F9198_BowsersMagmaMountain;
extern s32 D_800F919C_BowsersMagmaMountain;
extern Object* D_800F91A0_BowsersMagmaMountain;    // rock model

extern s16 D_800EE320;

s16 func_800F6610_BowsersMagmaMountain(void) {
    return D_800F8888_BowsersMagmaMountain[GwSystem.starSpaces[GwSystem.chosenStarSpaceIndex]];
}

void func_800F663C_BowsersMagmaMountain(void) {
    s32 i;
    s32 row;
    GW_SYSTEM* ed5c0 = &GwSystem;

    row = rand8() % D_800F87A0_BowsersMagmaMountain;
    for (i = 0; i < 7; i++) {
        ed5c0->starSpaces[i] = D_800F87A4_BowsersMagmaMountain[row][i];
    }
}

void func_800F66DC_BowsersMagmaMountain(void) {
    s32 starSpaceTemp;
    GW_SYSTEM* ed5c0;

    ed5c0 = &GwSystem;

    if (++ed5c0->chosenStarSpaceIndex < 7) {
        return;
    }

    starSpaceTemp = ed5c0->starSpaces[6];
    ed5c0->chosenStarSpaceIndex = 0;

    SetBoardFeatureFlag(0x44);
    func_800F663C_BowsersMagmaMountain();

    if (starSpaceTemp != ed5c0->starSpaces[0]) {
        return;
    }

    starSpaceTemp = ed5c0->starSpaces[0];
    ed5c0->starSpaces[0] = ed5c0->starSpaces[6];
    ed5c0->starSpaces[6] = starSpaceTemp;
}

void func_800F6768_BowsersMagmaMountain(void) {
    s32 s0, s1;
    GW_SYSTEM* ed5c0 = &GwSystem;

    for (s1 = 0; s1 < 7; s1++) {
        BoardSpaceTypeSet(D_800F8878_BowsersMagmaMountain[s1], 1);
        SetBoardFeatureFlag(D_800F8868_BowsersMagmaMountain[s1]);
    }

    if (_CheckFlag(0x44)) {
        s0 = 7;
    } else {
        s0 = ed5c0->chosenStarSpaceIndex;
    }

    for (s1 = 0; s1 < s0; s1++) {
        BoardSpaceTypeSet(D_800F8878_BowsersMagmaMountain[ed5c0->starSpaces[s1]], 6);
    }

    BoardSpaceTypeSet(D_800F8878_BowsersMagmaMountain[ed5c0->starSpaces[ed5c0->chosenStarSpaceIndex]], 5);

    ClearBoardFeatureFlag(D_800F8868_BowsersMagmaMountain[ed5c0->starSpaces[ed5c0->chosenStarSpaceIndex]]);
}

s16 func_800F6890_BowsersMagmaMountain(s32 current_space_index) {
    s32 i;
    s32 j;
    s16* star_spaces;
    GW_SYSTEM* ed5c0 = &GwSystem;

    i = 0;

    star_spaces = D_800F8878_BowsersMagmaMountain;

    current_space_index = (s16)current_space_index;

    for (; i < 7; i++) {
        if (current_space_index == star_spaces[i]) {
            if (i == ed5c0->starSpaces[ed5c0->chosenStarSpaceIndex]) {
                ed5c0->unk_1A = D_800F8868_BowsersMagmaMountain[i];
                return 1;
            }

            if (_CheckFlag(68)) {
                current_space_index = 7;
            } else {
                current_space_index = ed5c0->chosenStarSpaceIndex;
            }

            for (j = 0; j < current_space_index; j++) {
                if (i == ed5c0->starSpaces[j]) {
                    return 2;
                }
            }

            return 0;
        }
    }
    return 0;
}

void func_800F6970_BowsersMagmaMountain(void) {
    BoardSpace* space_data;
    Object* ptr;
    void* ret;
    s32 s0;
    f32 ftemp;
    f32 ftt;
    f32 const20;

    space_data = (HuPrcCurrentGet())->user_data;

    PlaySound(109);
    ptr = MBModelCreate(64, NULL);
    ptr->unk_0A |= 4;
    func_8004CDCC(ptr);
    func_800A0D50(&ptr->coords, &space_data->coords);

    ptr->unk_30 = 500.0f;

    ret = func_80042728(ptr, 0);

    ftemp = 0.0f;
    for (s0 = 0; s0 < 6; s0++) {
        func_800A0D00(&ptr->xScale, ftemp, ftemp, ftemp);
        ftemp += 0.4f;
        HuPrcVSleep();
    }

    for (s0 = 0; s0 < 3; s0++) {
        func_800A0D00(&ptr->xScale, ftemp, ftemp, ftemp);
        ftemp -= 0.4f;
        HuPrcVSleep();
    }

    HuPrcSleep(30);
    PlaySound(68);

    ftt = 0.0f;
    const20 = 20.0f;
    while (TRUE) {
        func_800A40D0(D_800F2B7C[*ptr->unk_3C->unk_40].unk7C, ftt); /* the typed field: a raw 0x7C view is wrong on the host */
        ftemp -= 0.02f;

        ftt += const20;
        if (ftemp < 0) {
            break;
        }

        func_800A0D00(&ptr->xScale, ftemp, ftemp, ftemp);
        ptr->unk_30 -= 6.0f;
        HuPrcVSleep();
    }

    func_800427D4(ret);
    HuPrcSleep(30);
    MBModelKill(ptr);
    EndProcess(NULL);
}

void func_800F6B80_BowsersMagmaMountain(mystery_struct_ret_func_80048224* a0) {
    Object* unk0ptr;

    unk0ptr = a0->unk0;
    unk0ptr->unk_34 = 20.0f;
    unk0ptr->unk_38 = -3.0f;

    MBMotionSet(a0->unk0, 0, 0);
    HuPrcSleep(3);

    while (MBMotionCheck(a0->unk0) == 0) {
        HuPrcVSleep();
    }

    MBMotionSet(a0->unk0, -1, 2);
}

void func_800F6C10_BowsersMagmaMountain(void) {
    GW_SYSTEM* ed5c0;
    mystery_struct_ret_func_80048224* str;
    BoardSpace* spacedata;
    Process* proc_struct;
    s32 string_id;

    ed5c0 = &GwSystem;

    func_80060128(43);
    str = func_80048224(D_800F8898_BowsersMagmaMountain);
    SetFadeInTypeAndTime(2, 16);

    while (func_80072718() != 0) {
        HuPrcVSleep();
    }

    func_8004A520();
    func_8004B5C4(3.0f);
    func_800F6B80_BowsersMagmaMountain(str);

    if (ed5c0->chosenStarSpaceIndex == 0 && !_CheckFlag(68)) {
        string_id = 1256;
    } else {
        string_id = 1258;
    }

    LoadStringIntoWindow(str->unk8, (void*)(s32)string_id, -1, -1);
    func_80071C8C(str->unk8, 1);
    PlaySound(1125);
    WaitForTextConfirmation(str->unk8);
    func_80071E80(str->unk8, 1);
    func_8006EB40(str->unk8);

    spacedata = BoardSpaceGet(D_800F8888_BowsersMagmaMountain[ed5c0->starSpaces[ed5c0->chosenStarSpaceIndex]]);
    func_8004B5DC(&spacedata->coords);
    func_8004B838(5.0f);
    HuPrcSleep(5);

    while (func_8004B850() != 0) {
        HuPrcVSleep();
    }

    HuPrcSleep(5);

    proc_struct = omAddPrcObj(&func_800F6970_BowsersMagmaMountain, 18432, 0, 0);
    proc_struct->user_data = spacedata;

    HuPrcSleep(30);

    if (ed5c0->chosenStarSpaceIndex == 0 && !_CheckFlag(68)) {
        string_id = 1257;
    } else {
        string_id = 1259;
    }

    LoadStringIntoWindow(str->unk8, (void*)(s32)string_id, -1, -1);
    func_80071C8C(str->unk8, 1);
    WaitForTextConfirmation(str->unk8);
    func_80071E80(str->unk8, 1);
    func_800601D4(90);
    HuPrcSleep(30);
    func_800726AC(2, 16);
    HuPrcSleep(17);
    func_8004847C(str);
    func_80056AF4();
    omOvlReturnEx(1);
    omOvlKill();
    HuPrcVSleep();
}

void func_800F6E44_BowsersMagmaMountain(void) {
    GW_SYSTEM* gameStatus = &GwSystem;

    gameStatus->curBoardIndex = 6;
    omInitObjMan(10, 0);
    omOvlGotoEx(53, 0, 146);
}

void func_800F6E80_BowsersMagmaMountain(void) {
    omInitObjMan(10, 0);

    SetPlayerOntoChain(0, 0, 0);
    SetPlayerOntoChain(1, 0, 0);
    SetPlayerOntoChain(2, 0, 0);
    SetPlayerOntoChain(3, 0, 0);

    SetBoardFeatureFlag(0x43);

    func_800F663C_BowsersMagmaMountain();

    GwCommon.boardWork[2] = 0;
    GwCommon.boardWork[4] = 0;

    omOvlReturnEx(1);
}

void func_800F6F08_BowsersMagmaMountain(void) {
    GW_PLAYER* player;
    s32 i;

    omInitObjMan(0x50, 0x28);
    func_80060088();
    func_80023448(1);
    func_800234B8(0, 0x78, 0x78, 0x78);
    func_800234B8(1, 0x40, 0x40, 0x60);
    func_80023504(1, -100.0f, 100.0f, 300.0f);
    func_80056A08(0x38, 0x4B, 0x40, 0);
    func_80052E84(0);
    func_80052E84(1);
    func_80052E84(2);
    func_80052E84(3);

    for (i = 0; i < 4; i++) {
        player = GetPlayerStruct(i);
        func_8003E174(player->player_obj);
        player->player_obj->unk_0A |= 2;
    }

    if (_CheckFlag(0x4E) != 0) {
        ClearBoardFeatureFlag(0x4E);
        func_800F66DC_BowsersMagmaMountain();
    }

    func_800F6768_BowsersMagmaMountain();
    func_800F7354_BowsersMagmaMountain();
    func_800F7198_BowsersMagmaMountain();

    if (_CheckFlag(0xE) == 0) {
        func_800F7234_BowsersMagmaMountain();
    }
    if (_CheckFlag(0xF) == 0) {
        func_800F7480_BowsersMagmaMountain();
    }
    if (GwCommon.boardWork[2] != 0) {
        BoardSetSpaceTypeInChain(0xA, 1, 2);
    }
}

void func_800F7070_BowsersMagmaMountain(void) {
    func_80060128(0xE);
    InitCameras(2);
    func_800F6F08_BowsersMagmaMountain();
    EventTableHydrate(D_800F9080_BowsersMagmaMountain);
    if (_CheckFlag(0xE) == 0) {
        EventTableHydrate(D_800F9140_BowsersMagmaMountain);
    }
    if (_CheckFlag(0xF) == 0) {
        EventTableHydrate(D_800F9150_BowsersMagmaMountain);
    }
    func_800584F0(0);
}

void func_800F70E8_BowsersMagmaMountain(void) {
    InitCameras(1);
    func_800F6F08_BowsersMagmaMountain();
    func_800584F0(1);
}

void func_800F7114_BowsersMagmaMountain(void) {
    Object* ptr;

    if (D_800F9160_BowsersMagmaMountain != NULL) {
        return;
    }

    ptr = MBModelCreate(0x3B, D_800F88A0_BowsersMagmaMountain);
    func_8003E174(ptr);
    D_800F9160_BowsersMagmaMountain = ptr;

    ptr->unk_0A |= 0x2;

    func_800A0D50(&ptr->coords, &BoardSpaceGet(0x41)->coords);
    func_8003C314(7, ptr, 0, 0);
}

void func_800F7198_BowsersMagmaMountain(void) {
    D_800F9160_BowsersMagmaMountain = 0;
    func_800F7114_BowsersMagmaMountain();
}

void func_800F71B8_BowsersMagmaMountain(void) {
    Object* ptr;

    if (D_800F9164_BowsersMagmaMountain != NULL) {
        return;
    }

    ptr = MBModelCreate(0x39, NULL);
    func_8003E174(ptr);
    D_800F9164_BowsersMagmaMountain = ptr;

    ptr->unk_0A |= 0x2;

    func_800A0D50(&ptr->coords, &BoardSpaceGet(0x39)->coords);
    func_8003C314(9, ptr, 0, 3);
}

void func_800F7234_BowsersMagmaMountain(void) {
    D_800F9164_BowsersMagmaMountain = NULL;
    func_800F71B8_BowsersMagmaMountain();
}

void func_800F7254_BowsersMagmaMountain(s16 arg0) {
    Object* obj;

    if (D_800F9170_BowsersMagmaMountain[arg0] == NULL) {
        if (D_800F9168_BowsersMagmaMountain == NULL) {
            obj = MBModelCreate(0x3A, NULL);
            func_8003E174(obj);
            D_800F9168_BowsersMagmaMountain = obj;
        } else {
            obj = MBModelParamCreate(D_800F9168_BowsersMagmaMountain);
        }
        obj->unk_0A |= 2;
        D_800F9170_BowsersMagmaMountain[arg0] = obj;
        func_8004CDCC(obj);
        func_800A0D50(&obj->coords, &BoardSpaceGet(D_800F88A8_BowsersMagmaMountain[arg0])->coords);
        func_8003C314(6, obj, D_800F88C8_BowsersMagmaMountain[arg0].one, D_800F88C8_BowsersMagmaMountain[arg0].two);
    }
}

void func_800F7354_BowsersMagmaMountain(void) {
    s32 i;

    D_800F9168_BowsersMagmaMountain = NULL;
    for (i = 0; i < 7; i++) {
        D_800F9170_BowsersMagmaMountain[i] = NULL;
        if (_CheckFlag(D_800F88B8_BowsersMagmaMountain[i]) == 0) {
            func_800F7254_BowsersMagmaMountain(i);
        }
    }
}

void func_800F73DC_BowsersMagmaMountain(void) {
    Object* ptr;

    if (D_800F918C_BowsersMagmaMountain != NULL) {
        return;
    }

    ptr = MBModelCreate(0x6A, NULL);
    func_8003E174(ptr);
    D_800F918C_BowsersMagmaMountain = ptr;

    ptr->unk_0A |= 0x2;

    func_800A0D00(&ptr->xScale, 0.6f, 0.6f, 0.6f);
    ptr->unk_30 = 100.0f;
    func_800A0D50(&ptr->coords, &BoardSpaceGet(0x40)->coords);
    func_8003C314(8, ptr, -1, 0);
}

void func_800F7480_BowsersMagmaMountain(void) {
    D_800F918C_BowsersMagmaMountain = NULL;
    func_800F73DC_BowsersMagmaMountain();
}

void func_800F74A0_BowsersMagmaMountain(void) {
    while (func_8004B850() != 0) {
        HuPrcVSleep();
    }
    HuPrcVSleep();
    D_800F9190_BowsersMagmaMountain = func_80045D84(0, 0x92, 1);
    D_800F9194_BowsersMagmaMountain = func_80045D84(1, 0xA0, 1);
    D_800F9198_BowsersMagmaMountain = func_80045D84(3, 0xAE, 1);
    D_800F919C_BowsersMagmaMountain = func_80045D84(0xB, 0xBC, 1);
    HuPrcSleep(3);
    D_800EE320 = 1;
}

void func_800F7550_BowsersMagmaMountain(void) {
    D_800EE320 = 0;
    func_80045E6C(D_800F9190_BowsersMagmaMountain);
    func_80045E6C(D_800F9194_BowsersMagmaMountain);
    func_80045E6C(D_800F9198_BowsersMagmaMountain);
    func_80045E6C(D_800F919C_BowsersMagmaMountain);
}

void func_800F759C_BowsersMagmaMountain(void) {
    GwCommon.boardWork[0] = 0;
    func_800587EC(0x59, 0, 1);
    SetEventReturnFlag(1);
}

void func_800F75D0_BowsersMagmaMountain(void) {
    if (GwCommon.boardWork[1] != 0) {
        SetNextChainAndSpace(-1, 7, 0);
    } else {
        SetNextChainAndSpace(-1, 6, 0);
    }
}

void func_800F7608_BowsersMagmaMountain(MagmaGateEvent* arg0) {
    unk_8003B8D4Struct* prompt;
    s32 dir;
    s32 i;
    s32 count;
    s16 win;

    SetPlayerAnimation(-1, -1, 2);
    while (func_8004B850() != 0) {
        HuPrcVSleep();
    }
    HuPrcVSleep();
    GwCommon.boardWork[1] = 0;
    GwCommon.boardWork[0] = arg0->boardWork0;
    if (PlayerHasCoins(-1, 10) != 0) {
        func_800F74A0_BowsersMagmaMountain();
        prompt = func_8003C218(-1, arg0->spaceIDs);
        func_8003C060(prompt, -1, 0);
        if (PlayerIsCPU(-1) != 0) {
            count = RunDecisionTree(arg0->decisionTree);
            for (i = 0; i < count; i++) {
                func_8003BE84(prompt, -2);
            }
            func_8003BE84(prompt, -4);
        }
        dir = DirectionPrompt(prompt);
        func_8003B908(prompt);
        func_800F7550_BowsersMagmaMountain();
        if (dir == arg0->gateDir) {
            func_800587EC(0x5A, 0, 1);
            SetEventReturnFlag(1);
            return;
        }
        if (dir != 0) {
            SetNextChainAndSpace(-1, arg0->chain1, arg0->space1);
        } else {
            SetNextChainAndSpace(-1, arg0->chain0, arg0->space0);
        }
    } else {
        win = CreateTextWindow(0x5E, 0x3C, 0xB, 2);
        LoadStringIntoWindow(win, (void*)0x1F7, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        func_8004DBD4(win, GetCurrentPlayerIndex());
        HideTextWindow(win);
        if (arg0->gateDir == 0) {
            SetNextChainAndSpace(-1, arg0->chain1, arg0->space1);
        } else {
            SetNextChainAndSpace(-1, arg0->chain0, arg0->space0);
        }
    }
}

void func_800F77F4_BowsersMagmaMountain(MagmaGateEvent* arg0) {
    if (GwCommon.boardWork[1] != 0) {
        if (arg0->gateDir != 0) {
            SetNextChainAndSpace(-1, arg0->chain1, arg0->space1);
        } else {
            SetNextChainAndSpace(-1, arg0->chain0, arg0->space0);
        }
    } else {
        if (arg0->gateDir == 0) {
            SetNextChainAndSpace(-1, arg0->chain1, arg0->space1);
        } else {
            SetNextChainAndSpace(-1, arg0->chain0, arg0->space0);
        }
    }
}

void func_800F7858_BowsersMagmaMountain(void) {
    func_800F7608_BowsersMagmaMountain(&D_800F8DA8_BowsersMagmaMountain);
    EndProcess(NULL);
}

void func_800F7880_BowsersMagmaMountain(void) {
    func_800F77F4_BowsersMagmaMountain(&D_800F8DA8_BowsersMagmaMountain);
}

void func_800F78A0_BowsersMagmaMountain(void) {
    func_800F7608_BowsersMagmaMountain(&D_800F8DE0_BowsersMagmaMountain);
    EndProcess(NULL);
}

void func_800F78C8_BowsersMagmaMountain(void) {
    func_800F77F4_BowsersMagmaMountain(&D_800F8DE0_BowsersMagmaMountain);
}

void func_800F78E8_BowsersMagmaMountain(void) {
    func_800F7608_BowsersMagmaMountain(&D_800F8E18_BowsersMagmaMountain);
    EndProcess(NULL);
}

void func_800F7910_BowsersMagmaMountain(void) {
    func_800F77F4_BowsersMagmaMountain(&D_800F8E18_BowsersMagmaMountain);
}

void func_800F7930_BowsersMagmaMountain(void) {
    SetNextChainAndSpace(-1, 3, 0);
}

void func_800F7954_BowsersMagmaMountain(void) {
    SetNextChainAndSpace(-1, 5, 0);
}

void func_800F7978_BowsersMagmaMountain(void) {
    SetNextChainAndSpace(-1, 8, 0);
}

void func_800F799C_BowsersMagmaMountain(void) {
    func_8004D2A4(-1, 8, 0x41);
    func_800587BC(0x5B, 0, 3, 1);
}

void func_800F79D4_BowsersMagmaMountain(void) {
    void* data;
    s16 sprite;
    s16 tex;
    s16 alpha;

    data = DataRead(0xA012A);
    sprite = func_80064EF4(1, 0);
    tex = func_800678A4(data);
    func_80067208(sprite, 0, tex, 0);
    func_80067384(sprite, 0, 0x100);
    func_800674BC(sprite, 0, 0x1000);
    func_80066DC4(sprite, 0, 0xA0, 0x78);
    func_80067354(sprite, 0, 39.0f, 29.0f);
    DataClose(data);
    for (alpha = 0; alpha < 0x90; alpha += 4) {
        func_80067558(sprite, 0, 0xFF, 0, 0, alpha);
        HuPrcVSleep();
    }
    for (alpha = 0x90; alpha > 0; alpha -= 4) {
        func_80067558(sprite, 0, 0xFF, 0, 0, alpha);
        HuPrcVSleep();
    }
    func_80067704(tex);
    func_80064D38(sprite);
    EndProcess(NULL);
}

void func_800F7B50_BowsersMagmaMountain(void) {
    Process* process;
    f32 speed;

    process = HuPrcCurrentGet();
    while (func_80072718() != 0) {
        HuPrcVSleep();
    }
    HuPrcSleep(30);
    speed = func_8004B844();
    func_8004B838(2.0f);
    func_80056E48(&BoardSpaceGet(0x4F)->coords);
    do {
        HuPrcSleep(2);
    } while (func_8004B850() != 0);
    HuPrcChildLink(process, omAddPrcObj(func_800F79D4_BowsersMagmaMountain, 0x4800, 0, 0));
    HuPrcChildWatch();
    HuPrcChildLink(process, omAddPrcObj(func_800F79D4_BowsersMagmaMountain, 0x4800, 0, 0));
    HuPrcChildWatch();
    BoardSetSpaceTypeInChain(0xA, 1, 2);
    HuPrcSleep(60);
    func_80056E48(&BoardSpaceGet(0x41)->coords);
    do {
        HuPrcSleep(2);
    } while (func_8004B850() != 0);
    func_8004B838(speed);
    EndProcess(NULL);
}

void func_800F7C8C_BowsersMagmaMountain(void) {
    MagmaRock* rock;
    Object* obj;
    f32 step;
    f32 zero;

    rock = HuPrcCurrentGet()->user_data;
    obj = MBModelParamCreate(D_800F91A0_BowsersMagmaMountain);
    func_800A0D00(&obj->xScale, rock->scale, rock->scale, rock->scale);
    func_800A0D50(&obj->coords, &rock->space->coords);
    obj->unk_30 = 1400.0f;
    step = 100.0f;
    zero = 0.0f;
    do {
        HuPrcVSleep();
        obj->coords.x += rock->dx;
    } while (!((obj->unk_30 -= step) <= zero));
    obj->unk_30 = zero;
    MBModelKill(obj);
    EndProcess(NULL);
}

void func_800F7D60_BowsersMagmaMountain(void) {
    s32 sound;
    s32 i;
    s32 j;

    sound = 0;
    D_800F91A0_BowsersMagmaMountain = MBModelCreate(0x4F, NULL);
    HuPrcSleep(40);
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 14; i++) {
            switch (sound) {
            case 0:
                PlaySound(0xEB);
                sound++;
                break;
            case 1:
                PlaySound(0xEC);
                sound++;
                break;
            case 2:
                PlaySound(0xED);
                sound = 0;
                break;
            }
            D_800F8E88_BowsersMagmaMountain[i].space = BoardSpaceGet(GetAbsSpaceIndexFromChainSpaceIndex(9, i));
            omAddPrcObj(func_800F7C8C_BowsersMagmaMountain, 0x4800, 0, 0)->user_data = &D_800F8E88_BowsersMagmaMountain[i];
            HuPrcSleep(6);
        }
    }
    MBModelKill(D_800F91A0_BowsersMagmaMountain);
    EndProcess(NULL);
}

void func_800F7EB8_BowsersMagmaMountain(void) {
    Vec3f* pos;
    Object* obj;
    void* rumble0;
    void* rumble1;
    void* rumble2;
    void* rumble3;
    s16 win;

    func_800726AC(4, 16);
    while (func_80072718() != 0) {
        HuPrcVSleep();
    }
    func_80056E30(2);
    pos = &BoardSpaceGet(0x41)->coords;
    func_80056E48(pos);
    func_8005884C(pos);
    SetFadeInTypeAndTime(4, 16);
    while (func_80072718() != 0) {
        HuPrcVSleep();
    }
    func_800421E0();
    omAddPrcObj(func_800F7B50_BowsersMagmaMountain, 0x4800, 0, 0);
    omAddPrcObj(func_800F7D60_BowsersMagmaMountain, 0x4800, 0, 0);
    PlaySound(0xE8);
    PlaySound(0xEE);
    rumble0 = func_80058A4C(0, 4, 30);
    rumble1 = func_80058A4C(1, 4, 30);
    rumble2 = func_80058A4C(2, 4, 30);
    rumble3 = func_80058A4C(3, 4, 30);
    obj = MBModelCreate(0x56, NULL);
    func_800A0D50(&obj->coords, &BoardSpaceGet(0x4F)->coords);
    MBMotionSet(D_800F9160_BowsersMagmaMountain, 0, 0);
    HuPrcSleep(10);
    while (!(MBMotionCheck(D_800F9160_BowsersMagmaMountain) & 1)) {
        HuPrcVSleep();
    }
    MBMotionSet(D_800F9160_BowsersMagmaMountain, -1, 2);
    HuPrcSleep(300);
    MBModelKill(obj);
    func_80058AD0(rumble0);
    func_80058AD0(rumble1);
    func_80058AD0(rumble2);
    func_80058AD0(rumble3);
    win = CreateTextWindow(0x46, 0x78, 0xF, 2);
    LoadStringIntoWindow(win, (void*)0x1ED, -1, -1);
    func_8006E070(win, 0);
    ShowTextWindow(win);
    func_8004DBD4(win, GwSystem.curPlayerIndex);
    HideTextWindow(win);
    GwCommon.boardWork[3] = GetCurrentPlayerIndex();
    GwCommon.boardWork[2] = 2;
    func_8004220C();
    func_800726AC(4, 16);
    while (func_80072718() != 0) {
        HuPrcVSleep();
    }
    func_80056E30(1);
    func_8005884C(NULL);
    SetFadeInTypeAndTime(4, 16);
    while (func_80072718() != 0) {
        HuPrcVSleep();
    }
    HuPrcSleep(15);
}

void func_800F819C_BowsersMagmaMountain(void) {
    s16 win;

    if (GwCommon.boardWork[2] != 0) {
        while (func_8004B850() != 0) {
            HuPrcVSleep();
        }
        HuPrcVSleep();
        win = CreateTextWindow(0x50, 0x40, 0xD, 1);
        LoadStringIntoWindow(win, (void*)0x1EC, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        func_8004DBD4(win, GetCurrentPlayerIndex());
        HideTextWindow(win);
    } else {
        func_800F7EB8_BowsersMagmaMountain();
    }
    EndProcess(NULL);
}

void func_800F826C_BowsersMagmaMountain(void) {
    SetNextChainAndSpace(-1, 0, 1);
}

// decomp-permuter
void func_800F8290_BowsersMagmaMountain(void)
{
  s16 player;
  s16 win;
  s32 coins;
  s32 new_var;
  player = GetCurrentPlayerIndex();
  func_800405DC(player);
  SetPlayerAnimation(-1, -1, 2);
  if (0 == _CheckFlag(0x42))
  {
    win = CreateTextWindow(0x48, 0x3C, 0x10, 3);
    LoadStringIntoWindow(win, (void *) 0x239, -1, -1);
    coins = 10;
  }
  else
  {
    new_var = 1;
    win = CreateTextWindow(0x41, 0x3C, 0x11, 3);
    LoadStringIntoWindow(win, (void *) 0x23A, -new_var, -1);
    coins = 20;
  }
  func_8006E070(win, 0);
  ShowTextWindow(win);
  PlaySound(0x432);
  func_8004DBD4(win, player);
  HideTextWindow(win);
  new_var = coins;
  func_80055960(player, new_var);
  ShowPlayerCoinChange(player, new_var);
  HuPrcSleep(30);
  func_8003FEFC(player);
}

void func_800F83C4_BowsersMagmaMountain(void) {
    GwCommon.boardWork[31]++;
    if (_CheckFlag(0x42) == 0 && (GwCommon.boardWork[31] % 10 == 0 || _CheckFlag(0x4D) == 0)) {
        if (_CheckFlag(0x4D) != 0) {
            func_80058910(-1, 1);
        }
        SetBoardFeatureFlag(0x4D);
        func_800587EC(0x5F, 0, 1);
        return;
    }
    func_800F8290_BowsersMagmaMountain();
}

void func_800F8494_BowsersMagmaMountain(void) {
    func_8004D2A4(-1, 8, 0x39);
    func_800F83C4_BowsersMagmaMountain();
    EndProcess(NULL);
}

void func_800F84C8_BowsersMagmaMountain(void) {
    func_8004D2A4(-1, 8, 0x40);
    func_800587EC(0x65, 0, 1);
}

void func_800F84FC_BowsersMagmaMountain(void) {
    if (func_800F6890_BowsersMagmaMountain(GetCurrentSpaceIndex()) == 1) {
        func_800587EC(0x44, 0, 2);
        func_8004D2A4(-1, 8, func_800F6610_BowsersMagmaMountain());
    }
}

void func_800F8560_BowsersMagmaMountain(void) {
    GW_PLAYER* player;
    s32 i;

    if (func_800F6890_BowsersMagmaMountain(GetCurrentSpaceIndex()) == 2) {
        for (i = 0; i < 4; i++) {
            player = GetPlayerStruct(i);
            player->group = i != GetCurrentPlayerIndex();
        }
        func_800587BC(1, 0, 5, 1);
    }
}

void func_800F85EC_BowsersMagmaMountain(void) {
    if (GwCommon.boardWork[2] != 0 && GwCommon.boardWork[3] == GetCurrentPlayerIndex()) {
        if (--GwCommon.boardWork[2] == 0) {
            BoardSetSpaceTypeInChain(0xA, 2, 1);
            GwCommon.boardWork[4] = 1;
        }
    }
}

void func_800F8664_BowsersMagmaMountain(void) {
    s16 win;

    if (GwCommon.boardWork[4] != 0) {
        GwCommon.boardWork[4] = 0;
        win = CreateTextWindow(0x3C, 0x5A, 0x12, 2);
        LoadStringIntoWindow(win, (void*)0x1EB, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        func_8004DBD4(win, GetCurrentPlayerIndex());
        HideTextWindow(win);
    }
    EndProcess(NULL);
}

void func_800F8700_BowsersMagmaMountain(void) {
    InitCameras(2);
    func_8001D4D4(1, &D_800F8790_BowsersMagmaMountain);
    func_800F6F08_BowsersMagmaMountain();
    func_800584F0(2);
    omAddPrcObj(func_800F6C10_BowsersMagmaMountain, 0x1005, 0, 0);
}
