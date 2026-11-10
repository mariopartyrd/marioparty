#include "common.h"
#include "engine/process.h"
#include "spaces.h"

#define LUIGI_STAR_COUNT 7

/* One engine-room pipe: open when its target scale reaches 1 (func_800F7668). */
typedef struct LuigiPipe {
    /* 0x0 */ s16 open;
    /* 0x4 */ f32 target;
} LuigiPipe; // size 0x8

/* One steam puff of the pipe ride (func_800F857C / func_800F8450). */
typedef struct LuigiSteam {
    /* 0x00 */ s16 active;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ Vec3f vel;
} LuigiSteam; // size 0x1C

struct LuigiTuple {
    s16 one;
    s16 two;
};

extern s16 D_800EE320;

// .bss (asm, ovl_3A_bss.bss.s)
extern Object* D_800F9CD0_LuigisEngineRoom;
extern Object* D_800F9CD4_LuigisEngineRoom;
extern Object* D_800F9CD8_LuigisEngineRoom;
extern Object* D_800F9CE0_LuigisEngineRoom[5];
extern Object* D_800F9CF4_LuigisEngineRoom[3];
extern Object* D_800F9D00_LuigisEngineRoom[12];
extern LuigiPipe D_800F9D30_LuigisEngineRoom[11]; // splat: D_800F9D34 = [0].target
extern LuigiPipe D_800F9D88_LuigisEngineRoom[11]; // splat: D_800F9D8C = [0].target
extern Object* D_800F9DE0_LuigisEngineRoom;    // toad model
extern Object* D_800F9DE8_LuigisEngineRoom[7]; // toads
extern Object* D_800F9E04_LuigisEngineRoom;    // boo model
extern Object* D_800F9E08_LuigisEngineRoom[1]; // boo
extern s32 D_800F9E0C_LuigisEngineRoom;
extern s32 D_800F9E10_LuigisEngineRoom;
extern s32 D_800F9E14_LuigisEngineRoom;
extern s32 D_800F9E18_LuigisEngineRoom;
extern LuigiSteam D_800F9E20_LuigisEngineRoom[20]; // splat: D_800F9E30/34/38 = [0].pos.z/vel.x/vel.y...
extern Object* D_800FA050_LuigisEngineRoom;
extern Process* D_800FA054_LuigisEngineRoom;

// main-code functions without a shared prototype
void func_8004DBD4(s32, s32);
void func_80056E30(s16);
void func_80056E48(Vec3f*);

// this overlay's functions
void func_800F663C_LuigisEngineRoom(void);
void func_800F6830_LuigisEngineRoom(void);
void func_800F6C48_LuigisEngineRoom(mystery_struct_ret_func_80048224* a0);
void func_800F6F48_LuigisEngineRoom(void);
void func_800F7258_LuigisEngineRoom(void);
void func_800F7284_LuigisEngineRoom(void);
void func_800F7300_LuigisEngineRoom(void);
void func_800F739C_LuigisEngineRoom(void);
void func_800F8CA0_LuigisEngineRoom(void);
s16 func_800F6610_LuigisEngineRoom(void);
void func_800F67A4_LuigisEngineRoom(void);
void func_800F6A38_LuigisEngineRoom(void);
s16 func_800F6958_LuigisEngineRoom(s32 current_space_index);
void func_800F7E70_LuigisEngineRoom(void);
void func_800F7488_LuigisEngineRoom(void);
void func_800F8E08_LuigisEngineRoom(void);
void func_800F73BC_LuigisEngineRoom(s16 arg0);
void func_800F7320_LuigisEngineRoom(void);
void func_800F8ADC_LuigisEngineRoom(void);
void func_800F8114_LuigisEngineRoom(void);
void func_800F7E24_LuigisEngineRoom(void);
void func_800F80CC_LuigisEngineRoom(void);
void func_800F7D20_LuigisEngineRoom(void);
void func_800F6F0C_LuigisEngineRoom(void);
void func_800F80F0_LuigisEngineRoom(void);
void func_800F8DA4_LuigisEngineRoom(void);
void func_800F9474_LuigisEngineRoom(void);
void func_800F8CA0_LuigisEngineRoom(void);
void func_800F7C18_LuigisEngineRoom(s16 arg0);
void func_800F7028_LuigisEngineRoom(void);
void func_800F7A90_LuigisEngineRoom(s16 arg0);
void func_800F8B6C_LuigisEngineRoom(void);
void func_800F7D74_LuigisEngineRoom(void);
void func_800F80A8_LuigisEngineRoom(void);
void func_800F8D70_LuigisEngineRoom(void);
void func_800F6CD8_LuigisEngineRoom(void);
void func_800F8B10_LuigisEngineRoom(void);
void func_800F9388_LuigisEngineRoom(void);
void func_800F7B90_LuigisEngineRoom(void);
void func_800F8B48_LuigisEngineRoom(void);
void func_800F719C_LuigisEngineRoom(void);
void func_800F74CC_LuigisEngineRoom(s16 arg0);
void func_800F7600_LuigisEngineRoom(void);
void func_800F7668_LuigisEngineRoom(LuigiPipe* p, s16 mode);
void func_800F78C8_LuigisEngineRoom(s16 arg0, f32 arg1);
void func_800F790C_LuigisEngineRoom(void);
void func_800F796C_LuigisEngineRoom(void);
Process* func_800F7A24_LuigisEngineRoom(s32 arg0);
s32 func_800F7D60_LuigisEngineRoom(void);
void func_800F7F78_LuigisEngineRoom(void);
void func_800F8138_LuigisEngineRoom(void);
void func_800F817C_LuigisEngineRoom(void);
void func_800F81C8_LuigisEngineRoom(void);
void func_800F820C_LuigisEngineRoom(void);
void func_800F8258_LuigisEngineRoom(void);
void func_800F8450_LuigisEngineRoom(void);
void func_800F8508_LuigisEngineRoom(void);
void func_800F855C_LuigisEngineRoom(void);
void func_800F857C_LuigisEngineRoom(Vec3f* pos);
void func_800F873C_LuigisEngineRoom(void);
void func_800F87A4_LuigisEngineRoom(s16 arg0);
void func_800F8A94_LuigisEngineRoom(void);
void func_800F8AB8_LuigisEngineRoom(void);
void func_800F8E94_LuigisEngineRoom(void);
void func_800F8FE8_LuigisEngineRoom(void);
void func_800F9118_LuigisEngineRoom(void);
void func_800F917C_LuigisEngineRoom(void);
void func_800F9260_LuigisEngineRoom(void);
void func_800F93AC_LuigisEngineRoom(void);

Vec4f D_800F9500_LuigisEngineRoom = { 0.0f, 0.0f, 320.0f, 240.0f };
s16 D_800F9510_LuigisEngineRoom[] = { 0, 2, 3, 5, 1, 4, 6, 0 };
s16 D_800F9520_LuigisEngineRoom[] = { 0, 0, 1, 1, 2, 2, 4, 0 };
s16 D_800F9530_LuigisEngineRoom[] = { 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x0 };
s16 D_800F9540_LuigisEngineRoom[] = { 0x72, 0x74, 0x5F, 0x61, 0x76, 0x73, 0x75, 0x0 };
s16 D_800F9550_LuigisEngineRoom[] = { 0x58, 0x5A, 0x47, 0x49, 0x5C, 0x59, 0x5B, 0x0 };
s32 D_800F9560_LuigisEngineRoom[] = { 1, 0x70003 }; /* MBModelCreate motion list: words */
s16 D_800F9568_LuigisEngineRoom[] = { 0x62, 0x66, 0x65, 0x63, 0x64, 0x0 };
s16 D_800F9574_LuigisEngineRoom[] = { 0x4A, 0x4C, 0x4B, 0x4D, 0x4E, 0x4F, 0x50, 0x52, 0x53, 0x55, 0x56, 0x0 };
s16 D_800F958C_LuigisEngineRoom[] = { 0x77, 0x33 };
s16 D_800F9590_LuigisEngineRoom[] = { 0x0, 0x1, 0x0, 0x0, 0x1, 0x0, 0x1, 0x0, 0x1, 0x0, 0x1, 0x0 };
f32 D_800F95A8_LuigisEngineRoom[] = { 90.0f, 0.0f, 90.0f, 0.0f, 90.0f, 90.0f, 90.0f, 90.0f, 90.0f, 0.0f, 90.0f };
s16 D_800F95D4_LuigisEngineRoom[] = { 0x58, 0x5A, 0x47, 0x49, 0x5C, 0x59, 0x5B, 0x0 };
s16 D_800F95E4_LuigisEngineRoom[] = { 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x0 };
/* splat: D_800F95F6 = [0].two */
struct LuigiTuple D_800F95F4_LuigisEngineRoom[] = {
    { 0, -2 }, { 0, 0 }, { 0, 0 }, { -3, -1 }, { 0, -3 }, { -3, 0 }, { 0, -3 },
};
s16 D_800F9610_LuigisEngineRoom[] = { 0x51, 0x0 };
DecisionTreeNonLeafNode D_800F9614_LuigisEngineRoom[4] = {
    { 0x03000000, { (void*)0x1F }, { 0x10A1E } },
    { 0x03000000, { (void*)0xE0 }, { 0x15F46 } },
    { 0x01000000, { (void*)0x14 }, { 0x15F46 } },
    { 0x00000000, { (void*)0x0 }, { 0x10A1E } },
};
DecisionTreeNonLeafNode D_800F9644_LuigisEngineRoom[4] = {
    { 0x03000000, { (void*)0x1F }, { 0x13C50 } },
    { 0x03000000, { (void*)0xE0 }, { 0x10514 } },
    { 0x01000000, { (void*)0x14 }, { 0x10A1E } },
    { 0x00000000, { (void*)0x0 }, { 0x15F46 } },
};
DecisionTreeNonLeafNode D_800F9674_LuigisEngineRoom[5] = {
    { 0x03000000, { (void*)0x1F }, { 0x10A1E } },
    { 0x03000000, { (void*)0x60 }, { 0x15F46 } },
    { 0x03000000, { (void*)0x80 }, { 0x11428 } },
    { 0x01000000, { (void*)0x14 }, { 0x15F46 } },
    { 0x00000000, { (void*)0x0 }, { 0x13C3C } },
};
DecisionTreeNonLeafNode D_800F96B0_LuigisEngineRoom[2] = {
    { 0x03000000, { (void*)0x1F }, { 0x11432 } },
    { 0x00000000, { (void*)0x0 }, { 0x15A46 } },
};
DecisionTreeNonLeafNode D_800F96C8_LuigisEngineRoom[6] = {
    { 0x02000000, { (void*)0x1 }, { (u32)D_800F9614_LuigisEngineRoom } },
    { 0x02000000, { (void*)0x2 }, { (u32)D_800F9644_LuigisEngineRoom } },
    { 0x02000000, { (void*)0x4 }, { (u32)D_800F9674_LuigisEngineRoom } },
    { 0x02000000, { (void*)0x28 }, { (u32)D_800F96B0_LuigisEngineRoom } },
    { 0x03000000, { (void*)0x1F }, { 0x11446 } },
    { 0x00000000, { (void*)0x0 }, { 0x15A5F } },
};
DecisionTreeNonLeafNode D_800F9710_LuigisEngineRoom[4] = {
    { 0x03000000, { (void*)0x1F }, { 0x15A5F } },
    { 0x03000000, { (void*)0xE0 }, { 0x10A1E } },
    { 0x01000000, { (void*)0x14 }, { 0x13C5A } },
    { 0x00000000, { (void*)0x0 }, { 0x15F50 } },
};
DecisionTreeNonLeafNode D_800F9740_LuigisEngineRoom[3] = {
    { 0x03000000, { (void*)0x1F }, { 0x10A1E } },
    { 0x03000000, { (void*)0x1E0 }, { 0x15F50 } },
    { 0x00000000, { (void*)0x0 }, { 0x1051E } },
};
DecisionTreeNonLeafNode D_800F9764_LuigisEngineRoom[4] = {
    { 0x03000000, { (void*)0x1F }, { 0x15A5F } },
    { 0x03000000, { (void*)0x60 }, { 0x10A1E } },
    { 0x01000000, { (void*)0x14 }, { 0x13C5A } },
    { 0x00000000, { (void*)0x0 }, { 0x15F50 } },
};
DecisionTreeNonLeafNode D_800F9794_LuigisEngineRoom[2] = {
    { 0x03000000, { (void*)0x1F }, { 0x15A5F } },
    { 0x00000000, { (void*)0x0 }, { 0x10A1E } },
};
DecisionTreeNonLeafNode D_800F97AC_LuigisEngineRoom[8] = {
    { 0x06000000, { (void (*)())func_800F7D60_LuigisEngineRoom }, { (u32)D_800F96C8_LuigisEngineRoom } },
    { 0x02000000, { (void*)0x1 }, { (u32)D_800F9710_LuigisEngineRoom } },
    { 0x02000000, { (void*)0x2 }, { (u32)D_800F9740_LuigisEngineRoom } },
    { 0x02000000, { (void*)0x4 }, { (u32)D_800F9764_LuigisEngineRoom } },
    { 0x02000000, { (void*)0x28 }, { (u32)D_800F9794_LuigisEngineRoom } },
    { 0x03000000, { (void*)0x1F }, { 0x15A5F } },
    { 0x03000000, { (void*)0x1E0 }, { 0x10A1E } },
    { 0x00000000, { (void*)0x0 }, { 0x1051E } },
};
DecisionTreeNonLeafNode D_800F980C_LuigisEngineRoom[5] = {
    { 0x03000000, { (void*)0x7 }, { 0x15F5F } },
    { 0x05000000, { (void*)0x1 }, { 0x15046 } },
    { 0x05000000, { (void*)0x2 }, { 0x1554B } },
    { 0x05000000, { (void*)0x4 }, { 0x15A50 } },
    { 0x00000000, { (void*)0x0 }, { 0x15F5F } },
};
DecisionTreeNonLeafNode D_800F9848_LuigisEngineRoom[4] = {
    { 0x05000000, { (void*)0x1 }, { 0x5A50 } },
    { 0x05000000, { (void*)0x2 }, { 0x5F55 } },
    { 0x05000000, { (void*)0x4 }, { 0x645A } },
    { 0x00000000, { (void*)0x0 }, { 0x645F } },
};
DecisionTreeNonLeafNode D_800F9878_LuigisEngineRoom[4] = {
    { 0x05000000, { (void*)0x1 }, { 0x5046 } },
    { 0x05000000, { (void*)0x2 }, { 0x554B } },
    { 0x05000000, { (void*)0x4 }, { 0x5A50 } },
    { 0x00000000, { (void*)0x0 }, { 0x645F } },
};
DecisionTreeNonLeafNode D_800F98A8_LuigisEngineRoom[6] = {
    { 0x03000000, { (void*)0x3 }, { (u32)D_800F9848_LuigisEngineRoom } },
    { 0x01000000, { (void*)0x14 }, { (u32)D_800F9878_LuigisEngineRoom } },
    { 0x05000000, { (void*)0x1 }, { 0x3250 } },
    { 0x05000000, { (void*)0x2 }, { 0x283C } },
    { 0x05000000, { (void*)0x4 }, { 0x1428 } },
    { 0x00000000, { (void*)0x0 }, { 0xA14 } },
};
DecisionTreeNonLeafNode D_800F98F0_LuigisEngineRoom[4] = {
    { 0x05000000, { (void*)0x1 }, { 0x5046 } },
    { 0x05000000, { (void*)0x2 }, { 0x554B } },
    { 0x05000000, { (void*)0x4 }, { 0x5A50 } },
    { 0x00000000, { (void*)0x0 }, { 0x645F } },
};
DecisionTreeNonLeafNode D_800F9920_LuigisEngineRoom[5] = {
    { 0x03000000, { (void*)0xFF }, { (u32)D_800F98F0_LuigisEngineRoom } },
    { 0x05000000, { (void*)0x1 }, { 0x2850 } },
    { 0x05000000, { (void*)0x2 }, { 0x1E3C } },
    { 0x05000000, { (void*)0x4 }, { 0x1428 } },
    { 0x00000000, { (void*)0x0 }, { 0xA14 } },
};
DecisionTreeNonLeafNode D_800F995C_LuigisEngineRoom[5] = {
    { 0x02000000, { (void*)0x1 }, { (u32)D_800F980C_LuigisEngineRoom } },
    { 0x02000000, { (void*)0x4 }, { (u32)D_800F98A8_LuigisEngineRoom } },
    { 0x02000000, { (void*)0x8 }, { (u32)D_800F9920_LuigisEngineRoom } },
    { 0x02000000, { (void*)0x20 }, { 0x16450 } },
    { 0x00000000, { (void*)0x0 }, { 0x15A46 } },
};
s16 D_800F9998_LuigisEngineRoom[] = { 1, 0x43, -1, 0 };
EventListEntry D_800F99A0_LuigisEngineRoom[] = {
    { 1, 2, func_800F7E70_LuigisEngineRoom },
    { 0, 0, NULL },
};
s16 D_800F99B0_LuigisEngineRoom[] = { 0x31, 9, -1, 0 };
EventListEntry D_800F99B8_LuigisEngineRoom[] = {
    { 1, 2, func_800F7F78_LuigisEngineRoom },
    { 0, 0, NULL },
};
EventListEntry D_800F99C8_LuigisEngineRoom[] = {
    { 1, 1, func_800F80A8_LuigisEngineRoom },
    { 0, 0, NULL },
};
EventListEntry D_800F99D8_LuigisEngineRoom[] = {
    { 1, 1, func_800F80CC_LuigisEngineRoom },
    { 0, 0, NULL },
};
EventListEntry D_800F99E8_LuigisEngineRoom[] = {
    { 1, 1, func_800F80F0_LuigisEngineRoom },
    { 0, 0, NULL },
};
EventListEntry D_800F99F8_LuigisEngineRoom[] = {
    { 1, 1, func_800F8114_LuigisEngineRoom },
    { 0, 0, NULL },
};
EventListEntry D_800F9A08_LuigisEngineRoom[] = {
    { 1, 1, func_800F8138_LuigisEngineRoom },
    { 0, 0, NULL },
};
EventListEntry D_800F9A18_LuigisEngineRoom[] = {
    { 1, 1, func_800F817C_LuigisEngineRoom },
    { 0, 0, NULL },
};
EventListEntry D_800F9A28_LuigisEngineRoom[] = {
    { 1, 1, func_800F81C8_LuigisEngineRoom },
    { 0, 0, NULL },
};
EventListEntry D_800F9A38_LuigisEngineRoom[] = {
    { 1, 1, func_800F820C_LuigisEngineRoom },
    { 0, 0, NULL },
};
EventListEntry D_800F9A48_LuigisEngineRoom[] = {
    { 1, 2, func_800F8258_LuigisEngineRoom },
    { 0, 0, NULL },
};
s32 D_800F9A58_LuigisEngineRoom[] = { 0x3E, 0x3D }; /* splat: D_800F9A5A = low half of [0] */
s32 D_800F9A60_LuigisEngineRoom[] = { 0x00000002, 0x00010049, 0x00010068 }; /* MBModelCreate motion list: words */
s32 D_800F9A6C_LuigisEngineRoom[] = { 0x00000002, 0x00020049, 0x00020068 }; /* MBModelCreate motion list: words */
s32 D_800F9A78_LuigisEngineRoom[] = { 0x00000002, 0x00030049, 0x00030068 }; /* MBModelCreate motion list: words */
s32 D_800F9A84_LuigisEngineRoom[] = { 0x00000002, 0x00040049, 0x00040068 }; /* MBModelCreate motion list: words */
s32 D_800F9A90_LuigisEngineRoom[] = { 0x00000002, 0x00050049, 0x00050068 }; /* MBModelCreate motion list: words */
s32 D_800F9A9C_LuigisEngineRoom[] = { 0x00000002, 0x00060049, 0x00060068 }; /* MBModelCreate motion list: words */
s32* D_800F9AA8_LuigisEngineRoom[] = { D_800F9A60_LuigisEngineRoom, D_800F9A6C_LuigisEngineRoom, D_800F9A9C_LuigisEngineRoom, D_800F9A78_LuigisEngineRoom, D_800F9A84_LuigisEngineRoom, D_800F9A90_LuigisEngineRoom };
EventListEntry D_800F9AC0_LuigisEngineRoom[] = {
    { 3, 2, func_800F8A94_LuigisEngineRoom },
    { 0, 0, NULL },
};
EventListEntry D_800F9AD0_LuigisEngineRoom[] = {
    { 3, 2, func_800F8AB8_LuigisEngineRoom },
    { 0, 0, NULL },
};
EventListEntry D_800F9AE0_LuigisEngineRoom[] = {
    { 1, 1, func_800F8ADC_LuigisEngineRoom },
    { 0, 0, NULL },
};
EventListEntry D_800F9AF0_LuigisEngineRoom[] = {
    { 1, 1, func_800F8B10_LuigisEngineRoom },
    { 0, 0, NULL },
};
EventListEntry D_800F9B00_LuigisEngineRoom[] = {
    { 1, 1, func_800F8B48_LuigisEngineRoom },
    { 0, 0, NULL },
};
EventListEntry D_800F9B10_LuigisEngineRoom[] = {
    { 1, 1, func_800F8B48_LuigisEngineRoom },
    { 1, 2, func_800F8D70_LuigisEngineRoom },
    { 0, 0, NULL },
};
EventListEntry D_800F9B28_LuigisEngineRoom[] = {
    { 1, 1, func_800F8DA4_LuigisEngineRoom },
    { 3, 1, func_800F8E08_LuigisEngineRoom },
    { 0, 0, NULL },
};
EventListEntry D_800F9B40_LuigisEngineRoom[] = {
    { 1, 2, func_800F8E94_LuigisEngineRoom },
    { 2, 2, func_800F917C_LuigisEngineRoom },
    { 0, 0, NULL },
};
EventListEntry D_800F9B58_LuigisEngineRoom[] = {
    { 3, 2, func_800F9260_LuigisEngineRoom },
    { 0, 0, NULL },
};
EventListEntry D_800F9B68_LuigisEngineRoom[] = {
    { 1, 1, func_800F9388_LuigisEngineRoom },
    { 3, 2, func_800F9260_LuigisEngineRoom },
    { 0, 0, NULL },
};
EventListEntry D_800F9B80_LuigisEngineRoom[] = {
    { 7, 2, func_800F93AC_LuigisEngineRoom },
    { 0, 0, NULL },
};
EventTableEntry D_800F9B90_LuigisEngineRoom[] = {
    { -0x2, D_800F9B80_LuigisEngineRoom },
    { 0x72, D_800F9B28_LuigisEngineRoom },
    { 0x74, D_800F9B28_LuigisEngineRoom },
    { 0x5F, D_800F9B28_LuigisEngineRoom },
    { 0x61, D_800F9B28_LuigisEngineRoom },
    { 0x76, D_800F9B28_LuigisEngineRoom },
    { 0x73, D_800F9B28_LuigisEngineRoom },
    { 0x75, D_800F9B28_LuigisEngineRoom },
    { 0x71, D_800F9B40_LuigisEngineRoom },
    { 0x6D, D_800F9B40_LuigisEngineRoom },
    { 0x5E, D_800F9B00_LuigisEngineRoom },
    { 0x5, D_800F99C8_LuigisEngineRoom },
    { 0x41, D_800F99C8_LuigisEngineRoom },
    { 0x10, D_800F9B68_LuigisEngineRoom },
    { 0x19, D_800F99D8_LuigisEngineRoom },
    { 0x23, D_800F99E8_LuigisEngineRoom },
    { 0x3B, D_800F99F8_LuigisEngineRoom },
    { 0x6E, D_800F99A0_LuigisEngineRoom },
    { 0x6B, D_800F9A08_LuigisEngineRoom },
    { 0x68, D_800F9A18_LuigisEngineRoom },
    { 0x6A, D_800F9A28_LuigisEngineRoom },
    { 0x6F, D_800F9A38_LuigisEngineRoom },
    { 0x67, D_800F99B8_LuigisEngineRoom },
    { 0x66, D_800F9A48_LuigisEngineRoom },
    { 0x65, D_800F9A48_LuigisEngineRoom },
    { 0x63, D_800F9A48_LuigisEngineRoom },
    { 0x64, D_800F9A48_LuigisEngineRoom },
    { 0x3D, D_800F9AC0_LuigisEngineRoom },
    { 0x3E, D_800F9AD0_LuigisEngineRoom },
    { 0x17, D_800F9B58_LuigisEngineRoom },
    { 0x38, D_800F9B58_LuigisEngineRoom },
    { -0x1, NULL },
};
EventTableEntry D_800F9C90_LuigisEngineRoom[] = {
    { 0x5E, D_800F9B10_LuigisEngineRoom },
    { -0x1, NULL },
};
EventTableEntry D_800F9CA0_LuigisEngineRoom[] = {
    { 0x69, D_800F9AE0_LuigisEngineRoom },
    { -0x1, NULL },
};
EventTableEntry D_800F9CB0_LuigisEngineRoom[] = {
    { 0x60, D_800F9AF0_LuigisEngineRoom },
    { -0x1, NULL },
};


s16 func_800F6610_LuigisEngineRoom(void) {
    return D_800F9550_LuigisEngineRoom[GwSystem.starSpaces[GwSystem.chosenStarSpaceIndex]];
}

void func_800F663C_LuigisEngineRoom(void) { //ov054_func_800F663C
    s32 s1;
    s32 rand1;
    s32 rand2;
    s32 swap1;
    GW_SYSTEM* ed5c0;

    ed5c0 = &GwSystem;
    for (s1 = 0; s1 < 30; s1++) {
        rand1 = rand8() % 7;
        rand2 = rand8() % 7;
        if (rand1 == rand2) {
            continue;
        }

        if (rand1 < D_800F9520_LuigisEngineRoom[rand2]) {
            continue;
        }

        if (rand2 < D_800F9520_LuigisEngineRoom[rand1]) {
            continue;
        }

        swap1 = D_800F9510_LuigisEngineRoom[rand1];
        D_800F9510_LuigisEngineRoom[rand1] = D_800F9510_LuigisEngineRoom[rand2];
        D_800F9510_LuigisEngineRoom[rand2] = swap1;

        swap1 = D_800F9520_LuigisEngineRoom[rand1];
        D_800F9520_LuigisEngineRoom[rand1] = D_800F9520_LuigisEngineRoom[rand2];
        D_800F9520_LuigisEngineRoom[rand2] = swap1;
    }

    for (s1 = 0; s1 < LUIGI_STAR_COUNT; s1++) {
        ed5c0->starSpaces[s1] = D_800F9510_LuigisEngineRoom[s1];
    }
}

void func_800F67A4_LuigisEngineRoom(void) {
    s32 starSpaceTemp;
    GW_SYSTEM* ed5c0;

    ed5c0 = &GwSystem;

    if (++ed5c0->chosenStarSpaceIndex < LUIGI_STAR_COUNT) {
        return;
    }

    starSpaceTemp = ed5c0->starSpaces[6];
    ed5c0->chosenStarSpaceIndex = 0;

    SetBoardFeatureFlag(0x44);
    func_800F663C_LuigisEngineRoom();

    if (starSpaceTemp != ed5c0->starSpaces[0]) {
        return;
    }

    starSpaceTemp = ed5c0->starSpaces[0];
    ed5c0->starSpaces[0] = ed5c0->starSpaces[6];
    ed5c0->starSpaces[6] = starSpaceTemp;
}

void func_800F6830_LuigisEngineRoom(void) { //ov054_func_800F6830
    s32 s0, s1;
    GW_SYSTEM* ed5c0 = &GwSystem;

    for (s1 = 0; s1 < LUIGI_STAR_COUNT; s1++) {
        BoardSpaceTypeSet(D_800F9540_LuigisEngineRoom[s1], 1);
        SetBoardFeatureFlag(D_800F9530_LuigisEngineRoom[s1]);
    }

    if (_CheckFlag(0x44)) {
        s0 = LUIGI_STAR_COUNT;
    } else {
        s0 = ed5c0->chosenStarSpaceIndex;
    }

    for (s1 = 0; s1 < s0; s1++) {
        BoardSpaceTypeSet(D_800F9540_LuigisEngineRoom[ed5c0->starSpaces[s1]], 6);
    }

    BoardSpaceTypeSet(D_800F9540_LuigisEngineRoom[ed5c0->starSpaces[ed5c0->chosenStarSpaceIndex]], 5);

    ClearBoardFeatureFlag(D_800F9530_LuigisEngineRoom[ed5c0->starSpaces[ed5c0->chosenStarSpaceIndex]]);
}

s16 func_800F6958_LuigisEngineRoom(s32 current_space_index) {
    s32 i;
    s32 j;
    s16* ov054_star_space_indicesptr;
    GW_SYSTEM* ed5c0 = &GwSystem;

    i = 0;

    ov054_star_space_indicesptr = D_800F9540_LuigisEngineRoom;

    // This feels a bit odd, but the match was difficult.
    current_space_index = (s16)current_space_index;

    for (; i < LUIGI_STAR_COUNT; i++) {
        if (current_space_index == ov054_star_space_indicesptr[i]) {
            if (i == ed5c0->starSpaces[ed5c0->chosenStarSpaceIndex]) {
                ed5c0->unk_1A = D_800F9530_LuigisEngineRoom[i];
                return 1;
            }

            if (_CheckFlag(68)) {
                current_space_index = LUIGI_STAR_COUNT;
            }
            else {
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

void func_800F6A38_LuigisEngineRoom(void) {
    BoardSpace* space_data;
    Object* ptr;
    void *ret;
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
        func_800A0D00((Vec3f*)&ptr->xScale, ftemp, ftemp, ftemp);
        ftemp += 0.4f;
        HuPrcVSleep();
    }

    for (s0 = 0; s0 < 3; s0++) {
        func_800A0D00((Vec3f*)&ptr->xScale, ftemp, ftemp, ftemp);
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

        func_800A0D00((Vec3f*)&ptr->xScale, ftemp, ftemp, ftemp);
        ptr->unk_30 -= 6.0f;
        HuPrcVSleep();
    }

    func_800427D4(ret);
    HuPrcSleep(30);
    MBModelKill(ptr);
    EndProcess(NULL);
}

void func_800F6C48_LuigisEngineRoom(mystery_struct_ret_func_80048224* a0) { //ov054_ShowNextStarSpotInner
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

void func_800F6CD8_LuigisEngineRoom(void) {
    GW_SYSTEM* ed5c0;
    mystery_struct_ret_func_80048224 *str;
    BoardSpace* spacedata;
    Process* proc_struct;
    s32 string_id;

    ed5c0 = &GwSystem;

    func_80060128(43);
    str = func_80048224(D_800F9560_LuigisEngineRoom);
    SetFadeInTypeAndTime(2, 16);

    while (func_80072718() != 0) {
        HuPrcVSleep();
    }

    func_8004A520();
    func_8004B5C4(3.0f);
    func_800F6C48_LuigisEngineRoom(str);

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

    spacedata = BoardSpaceGet(D_800F9550_LuigisEngineRoom[ed5c0->starSpaces[ed5c0->chosenStarSpaceIndex]]);
    func_8004B5DC(&spacedata->coords);
    func_8004B838(5.0f);
    HuPrcSleep(5);

    while (func_8004B850() != 0) {
        HuPrcVSleep();
    }

    HuPrcSleep(5);

    proc_struct = omAddPrcObj(&func_800F6A38_LuigisEngineRoom, 18432, 0, 0);
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

void func_800F6F0C_LuigisEngineRoom(void) {
    GwSystem.curBoardIndex = 4;
    omInitObjMan(10, 0);
    omOvlGotoEx(53, 0, 146);
}

void func_800F6F48_LuigisEngineRoom(void) {
    GW_SYSTEM* ed5c0;
    ed5c0 = &GwSystem;

    omInitObjMan(10, 0);

    SetPlayerOntoChain(0, 8, 0);
    SetPlayerOntoChain(1, 8, 0);
    SetPlayerOntoChain(2, 8, 0);
    SetPlayerOntoChain(3, 8, 0);

    switch (ed5c0->unk_00) {
        case 0:
            SetBoardFeatureFlag(0x46);
            SetBoardFeatureFlag(0x47);
            SetBoardFeatureFlag(0x48);
            SetBoardFeatureFlag(0x4A);
            break;

        case 1:
            SetBoardFeatureFlag(0x47);
            SetBoardFeatureFlag(0x48);
            break;
    }

    SetBoardFeatureFlag(0x43);

    func_800F663C_LuigisEngineRoom();

    GwCommon.boardWork[2] = 1;
    GwCommon.boardWork[1] = 0;

    omOvlReturnEx(1);
}

void func_800F7028_LuigisEngineRoom(void) {
    GW_PLAYER* player;
    s32 i;

    omInitObjMan(0x50, 0x28);
    func_80060088();
    func_80023448(1);
    func_800234B8(0, 0x78, 0x78, 0x78);
    func_800234B8(1, 0x40, 0x40, 0x60);
    func_80023504(1, -100.0f, 100.0f, 300.0f);
    func_80056A08(39, 73, 44, 0);
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
        func_800F67A4_LuigisEngineRoom();
    }

    func_800F6830_LuigisEngineRoom();
    func_800F7B90_LuigisEngineRoom();
    func_800F7488_LuigisEngineRoom();
    func_800F7600_LuigisEngineRoom();
    func_800F790C_LuigisEngineRoom();

    if (_CheckFlag(0xE) == 0) {
        func_800F739C_LuigisEngineRoom();
    }
    if (_CheckFlag(0xF) == 0) {
        func_800F7D20_LuigisEngineRoom();
    }
    if (_CheckFlag(0xD) == 0) {
        func_800F7300_LuigisEngineRoom();
    }
}

void func_800F719C_LuigisEngineRoom(void) {
    func_80060128(0xC);
    InitCameras(2);
    func_800F7028_LuigisEngineRoom();
    EventTableHydrate(D_800F9B90_LuigisEngineRoom);
    if (_CheckFlag(0xE) == 0) {
        EventTableHydrate(D_800F9C90_LuigisEngineRoom);
    }
    if (_CheckFlag(0xF) == 0) {
        EventTableHydrate(D_800F9CA0_LuigisEngineRoom);
    }
    if (_CheckFlag(0xD) == 0) {
        EventTableHydrate(D_800F9CB0_LuigisEngineRoom);
    }
    func_800584F0(0);
    if (GwCommon.boardWork[1] != 0) {
        func_80056E48(&BoardSpaceGet(0x67)->coords);
        func_80056E30(2);
    }
}

void func_800F7258_LuigisEngineRoom(void) { //ov054_Entrypoint3
    InitCameras(1);
    func_800F7028_LuigisEngineRoom();
    func_800584F0(1);
}

void func_800F7284_LuigisEngineRoom(void) { //ov054_DrawBowserInner
    Object *ptr;

    if (D_800F9CD0_LuigisEngineRoom != NULL) {
        return;
    }

    ptr = MBModelCreate(0x3B, NULL);
    func_8003E174(ptr);
    D_800F9CD0_LuigisEngineRoom = ptr;

    ptr->unk_0A |= 0x2;

    func_800A0D50(&ptr->coords, &BoardSpaceGet(72)->coords);
    func_8003C314(7, ptr, 0, 0);
}

void func_800F7300_LuigisEngineRoom(void) { //ov054_DrawBowserOuter
    D_800F9CD0_LuigisEngineRoom = 0;
    func_800F7284_LuigisEngineRoom();
}

void func_800F7320_LuigisEngineRoom(void) {
    Object* obj;

    if (D_800F9CD4_LuigisEngineRoom == NULL) {
        obj = MBModelCreate(0x39, NULL);
        func_8003E174(obj);
        D_800F9CD4_LuigisEngineRoom = obj;
        obj->unk_0A |= 2;
        func_800A0D50(&obj->coords, &BoardSpaceGet(70)->coords);
        func_8003C314(9, obj, 0, 0);
    }
}

void func_800F739C_LuigisEngineRoom(void) { //ov054_DrawBowserOuter
    D_800F9CD4_LuigisEngineRoom = 0;
    func_800F7320_LuigisEngineRoom();
}

void func_800F73BC_LuigisEngineRoom(s16 arg0) {
    Object* obj;

    if (D_800F9CE0_LuigisEngineRoom[arg0] == NULL) {
        if (D_800F9CD8_LuigisEngineRoom == NULL) {
            obj = MBModelCreate(0x16, NULL);
            func_8003E174(obj);
            D_800F9CD8_LuigisEngineRoom = obj;
        } else {
            obj = MBModelParamCreate(D_800F9CD8_LuigisEngineRoom);
        }
        obj->unk_0A |= 2;
        D_800F9CE0_LuigisEngineRoom[arg0] = obj;
        func_800A0D50(&obj->coords, &BoardSpaceGet(D_800F9568_LuigisEngineRoom[arg0])->coords);
        obj->coords.y = 0.0f;
    }
}

void func_800F7488_LuigisEngineRoom(void) {
    s32 i;

    D_800F9CD8_LuigisEngineRoom = NULL;
    for (i = 0; i < 5; i++) {
        func_800F73BC_LuigisEngineRoom(i);
    }
}

void func_800F74CC_LuigisEngineRoom(s16 arg0) {
    Object* obj;
    s16 kind;
    u16 id;

    if (D_800F9D00_LuigisEngineRoom[arg0] == NULL) {
        kind = D_800F9590_LuigisEngineRoom[arg0];
        id = D_800F958C_LuigisEngineRoom[kind];
        if (D_800F9CF4_LuigisEngineRoom[kind] == NULL) {
            obj = MBModelCreate(id, NULL);
            func_8003E174(obj);
            D_800F9CF4_LuigisEngineRoom[kind] = obj;
        } else {
            obj = MBModelParamCreate(D_800F9CF4_LuigisEngineRoom[kind]);
        }
        obj->unk_0A |= 2;
        D_800F9D00_LuigisEngineRoom[arg0] = obj;
        func_800A0D00((Vec3f*)&obj->xScale, 1.0f, 2.0f, 1.0f);
        func_8003D514(&obj->unk_18, D_800F95A8_LuigisEngineRoom[arg0]);
        func_800A0D50(&obj->coords, &BoardSpaceGet(D_800F9574_LuigisEngineRoom[arg0])->coords);
        obj->coords.y = 0.0f;
    }
}

void func_800F7600_LuigisEngineRoom(void) {
    s32 i;

    D_800F9CF4_LuigisEngineRoom[0] = NULL;
    D_800F9CF4_LuigisEngineRoom[1] = NULL;
    for (i = 0; i < 11; i++) {
        D_800F9D00_LuigisEngineRoom[i] = NULL;
        func_800F74CC_LuigisEngineRoom(i);
    }
}

void func_800F7668_LuigisEngineRoom(LuigiPipe* p, s16 mode) {
    s32 i;

    switch (mode & 1) {
    case 0:
        p[0].target = 0.1f;
        p[1].target = 1.0f;
        p[2].target = 0.1f;
        break;
    case 1:
        p[0].target = 1.0f;
        p[1].target = 0.1f;
        p[2].target = 1.0f;
        break;
    }
    switch (mode & 1) {
    case 0:
        p[3].target = 0.1f;
        p[4].target = 1.0f;
        break;
    case 1:
        p[3].target = 1.0f;
        p[4].target = 0.1f;
        break;
    }
    switch (mode & 1) {
    case 0:
        p[5].target = 0.1f;
        p[6].target = 1.0f;
        break;
    case 1:
        p[5].target = 1.0f;
        p[6].target = 0.1f;
        break;
    }
    switch (mode & 1) {
    case 0:
        p[7].target = 0.1f;
        p[8].target = 1.0f;
        break;
    case 1:
        p[7].target = 1.0f;
        p[8].target = 0.1f;
        break;
    }
    switch (mode & 1) {
    case 0:
        p[9].target = 0.1f;
        p[10].target = 1.0f;
        break;
    case 1:
        p[9].target = 1.0f;
        p[10].target = 0.1f;
        break;
    }
    for (i = 0; i < 11; i++) {
        if (p[i].target >= 1.0f) {
            p[i].open = 1;
        } else {
            p[i].open = 0;
        }
    }
}

void func_800F78C8_LuigisEngineRoom(s16 arg0, f32 arg1) {
    func_800A0D00((Vec3f*)&D_800F9D00_LuigisEngineRoom[arg0]->xScale, 1.0f, arg1, 1.0f);
}

void func_800F790C_LuigisEngineRoom(void) {
    s32 i;

    func_800F7668_LuigisEngineRoom(D_800F9D30_LuigisEngineRoom, GwCommon.boardWork[2]);
    for (i = 0; i < 11; i++) {
        func_800F78C8_LuigisEngineRoom(i, D_800F9D30_LuigisEngineRoom[i].target);
    }
}

void func_800F796C_LuigisEngineRoom(void) {
    s32 idx;
    f32 start;
    f32 cur;
    f32 step;
    s32 i;

    idx = (s32)HuPrcCurrentGet()->user_data;
    start = D_800F9D30_LuigisEngineRoom[idx].target;
    step = (start - D_800F9D88_LuigisEngineRoom[idx].target) / 10.0f;
    cur = start;
    PlaySound(0xD5);
    for (i = 0; i < 10; i++) {
        func_800F78C8_LuigisEngineRoom(idx, cur);
        cur -= step;
        HuPrcVSleep();
    }
    PlaySound(0xD6);
    EndProcess(NULL);
}

Process* func_800F7A24_LuigisEngineRoom(s32 arg0) {
    Process* proc;

    if (D_800F9D30_LuigisEngineRoom[arg0].target == D_800F9D88_LuigisEngineRoom[arg0].target) {
        return NULL;
    }
    proc = omAddPrcObj(func_800F796C_LuigisEngineRoom, 0x4800, 0, 0);
    proc->user_data = (void*)(s32)arg0;
    return proc;
}

void func_800F7A90_LuigisEngineRoom(s16 arg0) {
    Object* obj;

    if (D_800F9DE8_LuigisEngineRoom[arg0] == NULL) {
        if (D_800F9DE0_LuigisEngineRoom == NULL) {
            obj = MBModelCreate(0x3A, NULL);
            func_8003E174(obj);
            D_800F9DE0_LuigisEngineRoom = obj;
        } else {
            obj = MBModelParamCreate(D_800F9DE0_LuigisEngineRoom);
        }
        obj->unk_0A |= 2;
        D_800F9DE8_LuigisEngineRoom[arg0] = obj;
        func_8004CDCC(obj);
        func_800A0D50(&obj->coords, &BoardSpaceGet(D_800F95D4_LuigisEngineRoom[arg0])->coords);
        func_8003C314(6, obj, D_800F95F4_LuigisEngineRoom[arg0].one, D_800F95F4_LuigisEngineRoom[arg0].two);
    }
}

void func_800F7B90_LuigisEngineRoom(void) {
    s32 i;

    D_800F9DE0_LuigisEngineRoom = NULL;
    for (i = 0; i < LUIGI_STAR_COUNT; i++) {
        D_800F9DE8_LuigisEngineRoom[i] = NULL;
        if (_CheckFlag(D_800F95E4_LuigisEngineRoom[i]) == 0) {
            func_800F7A90_LuigisEngineRoom(i);
        }
    }
}

void func_800F7C18_LuigisEngineRoom(s16 arg0) {
    Object* obj;

    if (D_800F9E08_LuigisEngineRoom[arg0] == NULL) {
        if (D_800F9E04_LuigisEngineRoom == NULL) {
            obj = MBModelCreate(0x6A, NULL);
            func_8003E174(obj);
            D_800F9E04_LuigisEngineRoom = obj;
        } else {
            obj = MBModelParamCreate(D_800F9E04_LuigisEngineRoom);
        }
        D_800F9E08_LuigisEngineRoom[arg0] = obj;
        obj->unk_0A |= 2;
        func_800A0D00((Vec3f*)&obj->xScale, 0.6f, 0.6f, 0.6f);
        obj->unk_30 = 100.0f;
        func_800A0D50(&obj->coords, &BoardSpaceGet(D_800F9610_LuigisEngineRoom[arg0])->coords);
        func_8003C314(8, obj, 0, 0);
    }
}

void func_800F7D20_LuigisEngineRoom(void) {
    s32 i;

    D_800F9E04_LuigisEngineRoom = NULL;
    for (i = 0; i < 1; i++) {
        func_800F7C18_LuigisEngineRoom(i);
    }
}

s32 func_800F7D60_LuigisEngineRoom(void) {
    return (GwCommon.boardWork[2] ^ 1) & 1;
}

void func_800F7D74_LuigisEngineRoom(void) {
    while (func_8004B850() != 0) {
        HuPrcVSleep();
    }
    HuPrcVSleep();
    D_800F9E0C_LuigisEngineRoom = func_80045D84(0, 0x92, 1);
    D_800F9E10_LuigisEngineRoom = func_80045D84(1, 0xA0, 1);
    D_800F9E14_LuigisEngineRoom = func_80045D84(3, 0xAE, 1);
    D_800F9E18_LuigisEngineRoom = func_80045D84(0xB, 0xBC, 1);
    HuPrcSleep(3);
    D_800EE320 = 1;
}

void func_800F7E24_LuigisEngineRoom(void) {
    D_800EE320 = 0;
    func_80045E6C(D_800F9E0C_LuigisEngineRoom);
    func_80045E6C(D_800F9E10_LuigisEngineRoom);
    func_80045E6C(D_800F9E14_LuigisEngineRoom);
    func_80045E6C(D_800F9E18_LuigisEngineRoom);
}

void func_800F7E70_LuigisEngineRoom(void) {
    unk_8003B8D4Struct* prompt;
    s32 dir;
    s32 i;
    s32 n;

    SetPlayerAnimation(-1, -1, 2);
    HuPrcVSleep();
    func_800F7D74_LuigisEngineRoom();
    prompt = func_8003C218(GwSystem.curPlayerIndex, D_800F9998_LuigisEngineRoom);
    func_8003C060(prompt, GwSystem.curPlayerIndex, 0);
    if (PlayerIsCPU(-1) != 0) {
        n = RunDecisionTree(D_800F97AC_LuigisEngineRoom);
        for (i = 0; i < n; i++) {
            func_8003BE84(prompt, -2);
        }
        func_8003BE84(prompt, -4);
    }
    dir = DirectionPrompt(prompt);
    func_8003B908(prompt);
    func_800F7E24_LuigisEngineRoom();
    if (dir == 0) {
        SetNextChainAndSpace(-1, 9, 0);
    } else {
        SetNextChainAndSpace(-1, 10, 0);
    }
    EndProcess(NULL);
}

void func_800F7F78_LuigisEngineRoom(void) {
    unk_8003B8D4Struct* prompt;
    s32 dir;
    s32 i;
    s32 n;

    func_800F7668_LuigisEngineRoom(D_800F9D30_LuigisEngineRoom, GwCommon.boardWork[2]);
    if (D_800F9D30_LuigisEngineRoom[0].open == 0) {
        SetPlayerAnimation(-1, -1, 2);
        HuPrcVSleep();
        func_800F7D74_LuigisEngineRoom();
        prompt = func_8003C218(GwSystem.curPlayerIndex, D_800F99B0_LuigisEngineRoom);
        func_8003C060(prompt, GwSystem.curPlayerIndex, 0);
        if (PlayerIsCPU(-1) != 0) {
            n = (s16)RunDecisionTree(D_800F995C_LuigisEngineRoom);
            for (i = 0; i < n; i++) {
                func_8003BE84(prompt, -2);
            }
            func_8003BE84(prompt, -4);
        }
        dir = DirectionPrompt(prompt);
        func_8003B908(prompt);
        func_800F7E24_LuigisEngineRoom();
        if (dir == 0) {
            SetNextChainAndSpace(-1, 13, 0);
        } else {
            SetNextChainAndSpace(-1, 11, 0);
        }
    } else {
        SetNextChainAndSpace(-1, 7, 0);
    }
    EndProcess(NULL);
}

void func_800F80A8_LuigisEngineRoom(void) {
    SetNextChainAndSpace(-1, 12, 0);
}

void func_800F80CC_LuigisEngineRoom(void) {
    SetNextChainAndSpace(-1, 0, 0);
}

void func_800F80F0_LuigisEngineRoom(void) {
    SetNextChainAndSpace(-1, 6, 1);
}

void func_800F8114_LuigisEngineRoom(void) {
    SetNextChainAndSpace(-1, 14, 1);
}

void func_800F8138_LuigisEngineRoom(void) {
    func_800F7668_LuigisEngineRoom(D_800F9D30_LuigisEngineRoom, GwCommon.boardWork[2]);
    if (D_800F9D30_LuigisEngineRoom[3].open == 0) {
        SetNextChainAndSpace(-1, 1, 0);
    }
}

void func_800F817C_LuigisEngineRoom(void) {
    func_800F7668_LuigisEngineRoom(D_800F9D30_LuigisEngineRoom, GwCommon.boardWork[2]);
    if (D_800F9D30_LuigisEngineRoom[5].open == 0) {
        SetNextChainAndSpace(-1, 2, 0);
    } else {
        SetNextChainAndSpace(-1, 6, 0);
    }
}

void func_800F81C8_LuigisEngineRoom(void) {
    func_800F7668_LuigisEngineRoom(D_800F9D30_LuigisEngineRoom, GwCommon.boardWork[2]);
    if (D_800F9D30_LuigisEngineRoom[7].open == 0) {
        SetNextChainAndSpace(-1, 3, 0);
    }
}

void func_800F820C_LuigisEngineRoom(void) {
    func_800F7668_LuigisEngineRoom(D_800F9D30_LuigisEngineRoom, GwCommon.boardWork[2]);
    if (D_800F9D30_LuigisEngineRoom[9].open == 0) {
        SetNextChainAndSpace(-1, 14, 0);
    } else {
        SetNextChainAndSpace(-1, 15, 0);
    }
}

void func_800F8258_LuigisEngineRoom(void) {
    Vec3f sp10;
    GW_PLAYER* player;
    Process* proc;
    BoardSpace* space;

    player = GetPlayerStruct(-1);
    proc = HuPrcCurrentGet();
    func_800405DC(player->player_index);
    SetPlayerAnimation(-1, -1, 2);
    func_8004CD84(&sp10);
    HuPrcChildLink(proc, func_8004D1EC(&player->player_obj->unk_18, &sp10, &player->player_obj->unk_18, 8));
    HuPrcChildWatch();
    PlaySound(0xD4);
    while (1) {
        player->player_obj->coords.y -= 10.0;
        if (player->player_obj->coords.y <= 0.0f) {
            break;
        }
        HuPrcVSleep();
    }
    player->player_obj->coords.y = 0.0f;
    player->player_obj->unk_0A &= ~2;
    MBModelDispOff(player->player_obj);
    HuPrcVSleep();
    space = BoardSpaceGet(0x62);
    func_800A0D50(&sp10, &space->coords);
    sp10.y = 0.0f;
    HuPrcChildLink(proc, func_8004D648(&player->player_obj->coords, &sp10, &player->player_obj->coords, 20.0f));
    HuPrcChildWatch();
    HuPrcVSleep();
    MBModelDispOn(player->player_obj);
    player->player_obj->unk_0A |= 2;
    PlaySound(0xD4);
    while (1) {
        player->player_obj->coords.y += 10.0;
        if (player->player_obj->coords.y >= space->coords.y) {
            break;
        }
        HuPrcVSleep();
    }
    player->player_obj->coords.y = space->coords.y;
    SetPlayerOntoChain(-1, 5, 0);
    func_8003FEFC(player->player_index);
    EndProcess(NULL);
}

void func_800F8450_LuigisEngineRoom(void) {
    LuigiSteam* steam;
    Object* obj;
    s32 alpha;

    steam = HuPrcCurrentGet()->user_data;
    obj = MBModelCreate(0x57, NULL);
    func_800A0D50(&obj->coords, &steam->pos);
    alpha = 255;
    func_80021240(*obj->unk_3C->unk_40);
    do {
        func_800211BC(*obj->unk_3C->unk_40, alpha);
        func_800A0E00(&obj->coords, &obj->coords, &steam->vel);
        alpha -= 10;
        HuPrcVSleep();
    } while (alpha > 0);
    steam->active = 0;
    MBModelKill(obj);
    EndProcess(NULL);
}

void func_800F8508_LuigisEngineRoom(void) {
    s32 i;

    D_800FA050_LuigisEngineRoom = MBModelCreate(0x57, NULL);
    for (i = 0; i < 20; i++) {
        D_800F9E20_LuigisEngineRoom[i].active = 0;
    }
}

void func_800F855C_LuigisEngineRoom(void) {
    MBModelKill(D_800FA050_LuigisEngineRoom);
}

// register allocation around the random velocity stores (masked 4)
#ifdef NON_MATCHING
void func_800F857C_LuigisEngineRoom(Vec3f* pos) {
    s32 i;
    f32 r;

    for (i = 0; i < 20; i++) {
        if (D_800F9E20_LuigisEngineRoom[i].active == 0) {
            break;
        }
    }
    if (i != 20) {
        D_800F9E20_LuigisEngineRoom[i].active = -1;
        omAddPrcObj(func_800F8450_LuigisEngineRoom, 0x4800, 0, 0)->user_data = &D_800F9E20_LuigisEngineRoom[i];
        func_800A0D50(&D_800F9E20_LuigisEngineRoom[i].pos, pos);
        r = (u8)(rand8() % 5) * 1.5f;
        D_800F9E20_LuigisEngineRoom[i].vel.x = (rand8() & 1) ? r : -r;
        D_800F9E20_LuigisEngineRoom[i].vel.y = 9.0f;
        r = (u8)(rand8() % 5) * 1.5f;
        D_800F9E20_LuigisEngineRoom[i].vel.z = (rand8() & 1) ? r : -r;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3A_LuigisEngineRoom/24C3C0", func_800F857C_LuigisEngineRoom);
#endif

void func_800F873C_LuigisEngineRoom(void) {
    Vec3f pos;
    s32 i;

    func_800A0D50(&pos, &GetPlayerStruct(-1)->player_obj->coords);
    for (i = 0; i < 20; i++) {
        func_800F857C_LuigisEngineRoom(&pos);
        HuPrcSleep(2);
    }
    D_800FA054_LuigisEngineRoom = NULL;
    EndProcess(NULL);
}

void func_800F87A4_LuigisEngineRoom(s16 arg0) {
    Vec3f sp18;
    GW_PLAYER* player;
    Process* proc;
    Object* obj;
    Vec3f* dest;
    Process* move;

    player = GetPlayerStruct(-1);
    proc = HuPrcCurrentGet();
    while (func_8004B850() != 0) {
        HuPrcVSleep();
    }
    HuPrcVSleep();
    player->player_obj->unk_0A &= ~2;
    MBModelDispOff(player->player_obj);
    obj = MBModelCreate(player->character, D_800F9AA8_LuigisEngineRoom[player->character]);
    func_800A0D50(&obj->coords, &player->player_obj->coords);
    func_800A0D50(&obj->unk_18, &player->player_obj->unk_18);
    func_800F8508_LuigisEngineRoom();
    HuPrcSleep(5);
    SetSpaceDisappearAnim(D_800F9A58_LuigisEngineRoom[arg0]);
    PlaySound(0xDF);
    D_800FA054_LuigisEngineRoom = omAddPrcObj(func_800F873C_LuigisEngineRoom, 0x4800, 0, 0);
    HuPrcSleep(10);
    func_8004CD84(&sp18);
    func_8003D514(&sp18, 180.0f);
    func_8004D1EC(&obj->unk_18, &sp18, &obj->unk_18, 8);
    func_80060468(0x45E, 0);
    func_80058910(-1, 4);
    MBMotionSet(obj, 0, 0);
    obj->unk_34 = 45.0f;
    obj->unk_38 = -3.0f;
    dest = &BoardSpaceGet(GetAbsSpaceIndexFromChainSpaceIndex(4, arg0))->coords;
    move = func_8004D3F4(&obj->coords, dest, &obj->coords, 30);
    func_8004D3F4(&player->player_obj->coords, dest, &player->player_obj->coords, 30);
    HuPrcChildLink(proc, move);
    HuPrcChildWatch();
    MBMotionShiftSet(obj, 1, 0, 15, 0);
    HuPrcSleep(15);
    while (!(MBMotionCheck(obj) & 1)) {
        HuPrcVSleep();
    }
    MBMotionShiftSet(obj, -1, 0, 15, 2);
    SetPlayerOntoChain(-1, 4, arg0);
    while (D_800FA054_LuigisEngineRoom != NULL) {
        HuPrcVSleep();
    }
    func_800F855C_LuigisEngineRoom();
    MBModelDispOn(player->player_obj);
    player->player_obj->unk_0A |= 2;
    func_800A0D50(&player->player_obj->unk_18, &obj->unk_18);
    MBModelKill(obj);
    SetSpaceSpawnAnim(D_800F9A58_LuigisEngineRoom[arg0]);
}

void func_800F8A94_LuigisEngineRoom(void) {
    func_800F87A4_LuigisEngineRoom(1);
    EndProcess(NULL);
}

void func_800F8AB8_LuigisEngineRoom(void) {
    func_800F87A4_LuigisEngineRoom(0);
    EndProcess(NULL);
}

void func_800F8ADC_LuigisEngineRoom(void) {
    func_8004D2A4(-1, 8, 81);
    func_800587EC(0x65, 0, 1);
}

void func_800F8B10_LuigisEngineRoom(void) {
    func_8004D2A4(-1, 8, 72);
    func_800587BC(84, 0, 3, 1);
}

void func_800F8B48_LuigisEngineRoom(void) {
    SetNextChainAndSpace(-1, 8, 1);
}

// decomp-permuter
void func_800F8B6C_LuigisEngineRoom(void)
{
  short new_var;
  s16 player;
  s16 win;
  s32 coins;
  player = GetCurrentPlayerIndex();
  func_800405DC(player);
  SetPlayerAnimation(-1, -1, 2);
  if (_CheckFlag(0x42) == 0)
  {
    win = CreateTextWindow(0x48, 0x3C, 0x10, 3);
    LoadStringIntoWindow(win, (void *) 0x239, -1, -1);
    coins = 10;
  }
  else
  {
    win = CreateTextWindow(0x41, 0x3C, 0x11, 3);
    LoadStringIntoWindow(win, (void *) 0x23A, -1, -1);
    coins = 20;
  }
  func_8006E070(win, 0);
  ShowTextWindow(win);
  PlaySound(0x432);
  func_8004DBD4(win, player);
  new_var = coins;
  HideTextWindow(win);
  func_80055960(player, new_var);
  ShowPlayerCoinChange(player, new_var);
  HuPrcSleep(30);
  func_8003FEFC(player);
}

void func_800F8CA0_LuigisEngineRoom(void) {
    GwCommon.boardWork[31]++;
    if (_CheckFlag(0x42) == 0 && (GwCommon.boardWork[31] % 10 == 0 || _CheckFlag(0x4D) == 0)) {
        if (_CheckFlag(0x4D) != 0) {
            func_80058910(-1, 1);
        }
        SetBoardFeatureFlag(0x4D);
        func_800587EC(0x5F, 0, 1);
        return;
    }
    func_800F8B6C_LuigisEngineRoom();
}

void func_800F8D70_LuigisEngineRoom(void) {
    func_8004D2A4(-1, 8, 70);
    func_800F8CA0_LuigisEngineRoom();
    EndProcess(NULL);
}

void func_800F8DA4_LuigisEngineRoom(void) {
    if (func_800F6958_LuigisEngineRoom(GetCurrentSpaceIndex()) == 1) {
        func_800587EC(0x44, 0, 2);
        func_8004D2A4(-1, 8, func_800F6610_LuigisEngineRoom());
    }
}

void func_800F8E08_LuigisEngineRoom(void) {
    GW_PLAYER* player;
    s32 i;

    if (func_800F6958_LuigisEngineRoom(GetCurrentSpaceIndex()) == 2) {
        for (i = 0; i < 4; i++) {
            player = GetPlayerStruct(i);
            player->group = i != GetCurrentPlayerIndex();
        }
        func_800587BC(1, 0, 5, 1);
    }
}

void func_800F8E94_LuigisEngineRoom(void) {
    s16 win;

    if (GetCurrentSpaceIndex() == 0x71) {
        func_8004D2A4(-1, 8, 0x57);
        GwCommon.boardWork[0] = 0;
    } else {
        func_8004D2A4(-1, 8, 0x54);
        GwCommon.boardWork[0] = 1;
    }
    SetPlayerAnimation(-1, -1, 2);
    HuPrcVSleep();
    if (PlayerHasCoins(-1, 20) != 0) {
        GwCommon.boardWork[1] = 0;
        func_800587EC(0x55, 0, 1);
        SetEventReturnFlag(1);
    } else {
        while (func_8004B850() != 0) {
            HuPrcVSleep();
        }
        HuPrcVSleep();
        win = CreateTextWindow(0x54, 0x82, 0xD, 2);
        LoadStringIntoWindow(win, (void*)0x1D8, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        PlaySound(0xDA);
        func_8004DBD4(win, GetCurrentPlayerIndex());
        HideTextWindow(win);
    }
    EndProcess(NULL);
}

void func_800F8FE8_LuigisEngineRoom(void) {
    s16 win;
    s32 msg;

    func_800F7668_LuigisEngineRoom(D_800F9D30_LuigisEngineRoom, GwCommon.boardWork[2] + 1);
    msg = 0x1E0;
    func_800F7668_LuigisEngineRoom(D_800F9D88_LuigisEngineRoom, GwCommon.boardWork[2]);
    func_800F7A24_LuigisEngineRoom(0);
    func_800F7A24_LuigisEngineRoom(1);
    func_800F7A24_LuigisEngineRoom(2);
    func_800F7A24_LuigisEngineRoom(3);
    func_800F7A24_LuigisEngineRoom(4);
    func_800F7A24_LuigisEngineRoom(5);
    func_800F7A24_LuigisEngineRoom(6);
    func_800F7A24_LuigisEngineRoom(7);
    func_800F7A24_LuigisEngineRoom(8);
    func_800F7A24_LuigisEngineRoom(9);
    func_800F7A24_LuigisEngineRoom(10);
    HuPrcSleep(12);
    if (!(GwCommon.boardWork[2] & 1)) {
        msg = 0x1DF;
    }
    win = CreateTextWindow(0x46, 0x8C, 0xF, 2);
    LoadStringIntoWindow(win, (void*)(s32)msg, -1, -1);
    func_8006E070(win, 0);
    ShowTextWindow(win);
    WaitForTextConfirmation(win);
    HideTextWindow(win);
    HuPrcSleep(5);
    EndProcess(NULL);
}

void func_800F9118_LuigisEngineRoom(void) {
    Process* proc;

    proc = HuPrcCurrentGet();
    GwCommon.boardWork[2]++;
    HuPrcChildLink(proc, omAddPrcObj(func_800F8FE8_LuigisEngineRoom, 0x1007, 0, 0));
    HuPrcChildWatch();
}

void func_800F917C_LuigisEngineRoom(void) {
    if (GwCommon.boardWork[1] != 0) {
        GwCommon.boardWork[1] = 0;
        func_80056E30(2);
        func_80056E48(&BoardSpaceGet(0x67)->coords);
        while (func_80072718() != 0) {
            HuPrcVSleep();
        }
        func_800F9118_LuigisEngineRoom();
        func_800726AC(6, 16);
        while (func_80072718() != 0) {
            HuPrcVSleep();
        }
        func_80056E30(1);
        func_8005884C(NULL);
        SetFadeInTypeAndTime(6, 16);
        while (func_80072718() != 0) {
            HuPrcVSleep();
        }
        HuPrcSleep(15);
    }
    EndProcess(NULL);
}

void func_800F9260_LuigisEngineRoom(void) {
    Vec3f* pos;

    SetPlayerAnimation(-1, -1, 2);
    func_800726AC(4, 16);
    while (func_80072718() != 0) {
        HuPrcVSleep();
    }
    func_80056E30(2);
    pos = &BoardSpaceGet(0x67)->coords;
    func_80056E48(pos);
    func_8005884C(pos);
    SetFadeInTypeAndTime(4, 16);
    while (func_80072718() != 0) {
        HuPrcVSleep();
    }
    func_800F9118_LuigisEngineRoom();
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
    EndProcess(NULL);
}

void func_800F9388_LuigisEngineRoom(void) {
    SetNextChainAndSpace(-1, 0, 0);
}

void func_800F93AC_LuigisEngineRoom(void) {
    Process* proc;
    Vec3f* pos;

    if (_CheckFlag(0x4F) != 0) {
        func_80056E30(2);
        pos = &BoardSpaceGet(0x67)->coords;
        func_80056E48(pos);
        func_8005884C(pos);
        proc = HuPrcCurrentGet();
        HuPrcChildLink(proc, func_800532B4());
        HuPrcChildWatch();
        func_8004A510();
        func_800F9118_LuigisEngineRoom();
        func_8004A520();
        HuPrcChildLink(proc, func_800531E8());
        HuPrcChildWatch();
        func_80056E30(1);
        func_8005884C(NULL);
    }
    SetBoardFeatureFlag(0x4F);
    EndProcess(NULL);
}

void func_800F9474_LuigisEngineRoom(void) {
    InitCameras(2);
    func_8001D4D4(1, &D_800F9500_LuigisEngineRoom);
    func_800F7028_LuigisEngineRoom();
    func_800584F0(2);
    omAddPrcObj(func_800F6CD8_LuigisEngineRoom, 0x1005, 0, 0);
}
