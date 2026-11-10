#include "common.h"
#include "engine/process.h"
#include "spaces.h"

/* coin-toll gate on the way to the island crossing (func_800F7754) */
typedef struct YTIGate {
    /* 0x0 */ s16 boardWorkIndex; /* GwCommon.boardWork[] index of the toll counter */
    /* 0x4 */ s16* spaces;        /* direction prompt spaces, -1 terminated */
    /* 0x8 */ DecisionTreeNonLeafNode* tree;
    /* 0xC */ s16 chain;          /* chain taken when the player does not cross */
    /* 0xE */ s16 unkE;
} YTIGate;

typedef struct YTIOffset {
    s16 x;
    s16 y;
} YTIOffset;

typedef struct YTIWaitArgs {
    /* 0x0 */ s16 index;
    /* 0x2 */ s16 player;
} YTIWaitArgs;

/* main-code functions without a shared prototype */
void func_8004DBD4(s32, s32);

/* this overlay's functions */
s32 func_800F75D8_YoshisTropicalIsland(void);
s32 func_800F75F8_YoshisTropicalIsland(void);
s32 func_800F7618_YoshisTropicalIsland(void);
s32 func_800F7638_YoshisTropicalIsland(void);
void func_800F6E6C_YoshisTropicalIsland(void);
void func_800F6F44_YoshisTropicalIsland(void);
void func_800F7020_YoshisTropicalIsland(void);
void func_800F7118_YoshisTropicalIsland(void);
void func_800F722C_YoshisTropicalIsland(void);
void func_800F72F0_YoshisTropicalIsland(void);
void func_800F73B4_YoshisTropicalIsland(void);
void func_800F7530_YoshisTropicalIsland(void);
void func_800F7A74_YoshisTropicalIsland(void);
void func_800F7A9C_YoshisTropicalIsland(void);
void func_800F7AE0_YoshisTropicalIsland(void);
void func_800F7B08_YoshisTropicalIsland(void);
void func_800F7B4C_YoshisTropicalIsland(void);
void func_800F7B80_YoshisTropicalIsland(void);
void func_800F7BA4_YoshisTropicalIsland(void);
void func_800F7BC8_YoshisTropicalIsland(void);
void func_800F7DF0_YoshisTropicalIsland(void);
void func_800F7E24_YoshisTropicalIsland(void);
void func_800F7E8C_YoshisTropicalIsland(void);
void func_800F7EF4_YoshisTropicalIsland(void);
void func_800F7F28_YoshisTropicalIsland(void);
void func_800F7F4C_YoshisTropicalIsland(void);

/* .data (0x800F8040..0x800F86E0) */
Vec4f D_800F8040_YoshisTropicalIsland = { 0.0f, 0.0f, 320.0f, 240.0f };
s32 D_800F8050_YoshisTropicalIsland[] = { 1, 0x70003 }; /* MBModelCreate motion list: words */
s16 D_800F8058_YoshisTropicalIsland[] = { 0x3A, 0x3B };
YTIOffset D_800F805C_YoshisTropicalIsland[] = { { -3, 0 }, { 3, 0 } }; /* splat's D_800F805E is [0].y */
s16 D_800F8064_YoshisTropicalIsland[] = { 0x38, 0x39 };
s16 D_800F8068_YoshisTropicalIsland[] = { 0x43, 0x42, 0x45, 0x40, 0x41, 0x44, 0x46, 0 };
f32 D_800F8078_YoshisTropicalIsland[] = { 16.0f, 70.0f, 130.0f, 50.0f, 270.0f, 300.0f, 200.0f };
DecisionTreeNonLeafNode D_800F8094_YoshisTropicalIsland[5] = {
    { 0x04000000, {(void*)0x500000}, {0xA1E} },
    { 0x05000000, {(void*)0x1}, {0x321E} },
    { 0x05000000, {(void*)0x2}, {0x3C28} },
    { 0x05000000, {(void*)0x4}, {0x5A3C} },
    { 0x00000000, {(void*)0x0}, {0x6446} },
};
DecisionTreeNonLeafNode D_800F80D0_YoshisTropicalIsland[4] = {
    { 0x05000000, {(void*)0x1}, {0x141E} },
    { 0x05000000, {(void*)0x2}, {0xA14} },
    { 0x05000000, {(void*)0x4}, {0xA} },
    { 0x00000000, {(void*)0x0}, {0xA} },
};
DecisionTreeNonLeafNode D_800F8100_YoshisTropicalIsland[5] = {
    { 0x04000000, {(void*)0x510000}, {(u32)D_800F80D0_YoshisTropicalIsland} },
    { 0x05000000, {(void*)0x1}, {0x3232} },
    { 0x05000000, {(void*)0x2}, {0x2832} },
    { 0x05000000, {(void*)0x4}, {0x1E32} },
    { 0x00000000, {(void*)0x0}, {0x1E32} },
};
DecisionTreeNonLeafNode D_800F813C_YoshisTropicalIsland[4] = {
    { 0x05000000, {(void*)0x1}, {0x1463C} },
    { 0x05000000, {(void*)0x2}, {0x15046} },
    { 0x05000000, {(void*)0x4}, {0x15A46} },
    { 0x00000000, {(void*)0x0}, {0x16450} },
};
DecisionTreeNonLeafNode D_800F816C_YoshisTropicalIsland[4] = {
    { 0x05000000, {(void*)0x1}, {0x13C50} },
    { 0x05000000, {(void*)0x2}, {0x1463C} },
    { 0x05000000, {(void*)0x4}, {0x14646} },
    { 0x00000000, {(void*)0x0}, {0x15046} },
};
DecisionTreeNonLeafNode D_800F819C_YoshisTropicalIsland[6] = {
    { 0x06000000, {(void (*)())func_800F75F8_YoshisTropicalIsland}, {(u32)D_800F813C_YoshisTropicalIsland} },
    { 0x06000000, {(void (*)())func_800F7618_YoshisTropicalIsland}, {(u32)D_800F816C_YoshisTropicalIsland} },
    { 0x05000000, {(void*)0x1}, {0x13C3C} },
    { 0x05000000, {(void*)0x2}, {0x13C32} },
    { 0x05000000, {(void*)0x4}, {0x13232} },
    { 0x00000000, {(void*)0x0}, {0x13232} },
};
DecisionTreeNonLeafNode D_800F81E4_YoshisTropicalIsland[5] = {
    { 0x04000000, {(void*)0x500000}, {(u32)D_800F819C_YoshisTropicalIsland} },
    { 0x05000000, {(void*)0x1}, {0x3C32} },
    { 0x05000000, {(void*)0x2}, {0x463C} },
    { 0x05000000, {(void*)0x4}, {0x5A46} },
    { 0x00000000, {(void*)0x0}, {0x645A} },
};
DecisionTreeNonLeafNode D_800F8220_YoshisTropicalIsland[4] = {
    { 0x05000000, {(void*)0x1}, {0x15A5A} },
    { 0x05000000, {(void*)0x2}, {0x15050} },
    { 0x05000000, {(void*)0x4}, {0x14646} },
    { 0x00000000, {(void*)0x0}, {0x14146} },
};
DecisionTreeNonLeafNode D_800F8250_YoshisTropicalIsland[4] = {
    { 0x05000000, {(void*)0x1}, {0x15A5A} },
    { 0x05000000, {(void*)0x2}, {0x15050} },
    { 0x05000000, {(void*)0x4}, {0x13C3C} },
    { 0x00000000, {(void*)0x0}, {0x1323C} },
};
DecisionTreeNonLeafNode D_800F8280_YoshisTropicalIsland[4] = {
    { 0x05000000, {(void*)0x1}, {0x15050} },
    { 0x05000000, {(void*)0x2}, {0x14646} },
    { 0x05000000, {(void*)0x4}, {0x13C3C} },
    { 0x00000000, {(void*)0x0}, {0x1323C} },
};
DecisionTreeNonLeafNode D_800F82B0_YoshisTropicalIsland[7] = {
    { 0x06000000, {(void (*)())func_800F75D8_YoshisTropicalIsland}, {(u32)D_800F8220_YoshisTropicalIsland} },
    { 0x06000000, {(void (*)())func_800F75F8_YoshisTropicalIsland}, {(u32)D_800F8250_YoshisTropicalIsland} },
    { 0x06000000, {(void (*)())func_800F7618_YoshisTropicalIsland}, {(u32)D_800F8280_YoshisTropicalIsland} },
    { 0x05000000, {(void*)0x1}, {0x1463C} },
    { 0x05000000, {(void*)0x2}, {0x13228} },
    { 0x05000000, {(void*)0x4}, {0x1281E} },
    { 0x00000000, {(void*)0x0}, {0x12D1E} },
};
DecisionTreeNonLeafNode D_800F8304_YoshisTropicalIsland[5] = {
    { 0x04000000, {(void*)0x510000}, {(u32)D_800F82B0_YoshisTropicalIsland} },
    { 0x05000000, {(void*)0x1}, {0x5555} },
    { 0x05000000, {(void*)0x2}, {0x5A5A} },
    { 0x05000000, {(void*)0x4}, {0x5F5A} },
    { 0x00000000, {(void*)0x0}, {0x645F} },
};
DecisionTreeNonLeafNode D_800F8340_YoshisTropicalIsland[4] = {
    { 0x05000000, {(void*)0x1}, {0x15F5F} },
    { 0x05000000, {(void*)0x2}, {0x1645A} },
    { 0x05000000, {(void*)0x4}, {0x16464} },
    { 0x00000000, {(void*)0x0}, {0x16464} },
};
DecisionTreeNonLeafNode D_800F8370_YoshisTropicalIsland[4] = {
    { 0x05000000, {(void*)0x1}, {0x15A5A} },
    { 0x05000000, {(void*)0x2}, {0x15F5A} },
    { 0x05000000, {(void*)0x4}, {0x15F5A} },
    { 0x00000000, {(void*)0x0}, {0x15F5A} },
};
DecisionTreeNonLeafNode D_800F83A0_YoshisTropicalIsland[11] = {
    { 0x03000000, {(void*)0x2}, {(u32)D_800F8094_YoshisTropicalIsland} },
    { 0x03000000, {(void*)0x8}, {(u32)D_800F8100_YoshisTropicalIsland} },
    { 0x03000000, {(void*)0x20}, {(u32)D_800F81E4_YoshisTropicalIsland} },
    { 0x03000000, {(void*)0x200}, {(u32)D_800F8304_YoshisTropicalIsland} },
    { 0x04000000, {(void*)0x500000}, {0x6464} },
    { 0x06000000, {(void (*)())func_800F75F8_YoshisTropicalIsland}, {(u32)D_800F8340_YoshisTropicalIsland} },
    { 0x06000000, {(void (*)())func_800F7618_YoshisTropicalIsland}, {(u32)D_800F8370_YoshisTropicalIsland} },
    { 0x05000000, {(void*)0x1}, {0x15A5A} },
    { 0x05000000, {(void*)0x2}, {0x15A5A} },
    { 0x05000000, {(void*)0x4}, {0x15A5A} },
    { 0x00000000, {(void*)0x0}, {0x15F5A} },
};
DecisionTreeNonLeafNode D_800F8424_YoshisTropicalIsland[4] = {
    { 0x05000000, {(void*)0x1}, {0x3246} },
    { 0x05000000, {(void*)0x2}, {0x3C46} },
    { 0x05000000, {(void*)0x4}, {0x4646} },
    { 0x00000000, {(void*)0x0}, {0x5046} },
};
DecisionTreeNonLeafNode D_800F8454_YoshisTropicalIsland[5] = {
    { 0x04000000, {(void*)0x510000}, {(u32)D_800F8424_YoshisTropicalIsland} },
    { 0x05000000, {(void*)0x1}, {0x281E} },
    { 0x05000000, {(void*)0x2}, {0x3228} },
    { 0x05000000, {(void*)0x4}, {0x463C} },
    { 0x00000000, {(void*)0x0}, {0x503C} },
};
DecisionTreeNonLeafNode D_800F8490_YoshisTropicalIsland[4] = {
    { 0x05000000, {(void*)0x1}, {0x15F5A} },
    { 0x05000000, {(void*)0x2}, {0x15A5A} },
    { 0x05000000, {(void*)0x4}, {0x1505A} },
    { 0x00000000, {(void*)0x0}, {0x1465A} },
};
DecisionTreeNonLeafNode D_800F84C0_YoshisTropicalIsland[7] = {
    { 0x03000000, {(void*)0x10}, {(u32)D_800F8454_YoshisTropicalIsland} },
    { 0x04000000, {(void*)0x510000}, {0x5F5F} },
    { 0x06000000, {(void (*)())func_800F7638_YoshisTropicalIsland}, {(u32)D_800F8490_YoshisTropicalIsland} },
    { 0x05000000, {(void*)0x1}, {0x15F5A} },
    { 0x05000000, {(void*)0x2}, {0x15A5A} },
    { 0x05000000, {(void*)0x4}, {0x1465A} },
    { 0x00000000, {(void*)0x0}, {0x13C5A} },
};
s16 D_800F8514_YoshisTropicalIsland[] = { 0x35, 0x32, -1, 0 };
YTIGate D_800F851C_YoshisTropicalIsland = { 0, D_800F8514_YoshisTropicalIsland, D_800F83A0_YoshisTropicalIsland, 1, 0 };
EventListEntry D_800F852C_YoshisTropicalIsland[] = {
    { 1, 2, func_800F7A74_YoshisTropicalIsland },
    { 2, 1, func_800F7A9C_YoshisTropicalIsland },
    { 0, 0, NULL },
};
s16 D_800F8544_YoshisTropicalIsland[] = { 0x2B, 0x25, -1, 0 };
YTIGate D_800F854C_YoshisTropicalIsland = { 1, D_800F8544_YoshisTropicalIsland, D_800F84C0_YoshisTropicalIsland, 3, 2 };
EventListEntry D_800F855C_YoshisTropicalIsland[] = {
    { 1, 2, func_800F7AE0_YoshisTropicalIsland },
    { 2, 1, func_800F7B08_YoshisTropicalIsland },
    { 0, 0, NULL },
};
EventListEntry D_800F8574_YoshisTropicalIsland[] = {
    { 1, 1, func_800F7B4C_YoshisTropicalIsland },
    { 0, 0, NULL },
};
EventListEntry D_800F8584_YoshisTropicalIsland[] = {
    { 1, 1, func_800F7B80_YoshisTropicalIsland },
    { 0, 0, NULL },
};
EventListEntry D_800F8594_YoshisTropicalIsland[] = {
    { 1, 1, func_800F7BA4_YoshisTropicalIsland },
    { 0, 0, NULL },
};
EventListEntry D_800F85A4_YoshisTropicalIsland[] = {
    { 1, 1, func_800F7BC8_YoshisTropicalIsland },
    { 0, 0, NULL },
};
EventListEntry D_800F85B4_YoshisTropicalIsland[] = {
    { 1, 1, func_800F7BC8_YoshisTropicalIsland },
    { 1, 2, func_800F7DF0_YoshisTropicalIsland },
    { 0, 0, NULL },
};
EventListEntry D_800F85CC_YoshisTropicalIsland[] = {
    { 1, 1, func_800F7E24_YoshisTropicalIsland },
    { 0, 0, NULL },
};
EventListEntry D_800F85DC_YoshisTropicalIsland[] = {
    { 1, 1, func_800F7E8C_YoshisTropicalIsland },
    { 0, 0, NULL },
};
EventListEntry D_800F85EC_YoshisTropicalIsland[] = {
    { 1, 1, func_800F7EF4_YoshisTropicalIsland },
    { 0, 0, NULL },
};
EventListEntry D_800F85FC_YoshisTropicalIsland[] = {
    { 3, 1, func_800F7F28_YoshisTropicalIsland },
    { 0, 0, NULL },
};
EventListEntry D_800F860C_YoshisTropicalIsland[] = {
    { 3, 1, func_800F7F4C_YoshisTropicalIsland },
    { 0, 0, NULL },
};
EventTableEntry D_800F861C_YoshisTropicalIsland[] = {
    { 0x4A, D_800F85CC_YoshisTropicalIsland },
    { 0x4C, D_800F85DC_YoshisTropicalIsland },
    { 0x48, D_800F852C_YoshisTropicalIsland },
    { 0x4D, D_800F855C_YoshisTropicalIsland },
    { 0x00, D_800F85FC_YoshisTropicalIsland },
    { 0x36, D_800F85FC_YoshisTropicalIsland },
    { 0x11, D_800F85FC_YoshisTropicalIsland },
    { 0x30, D_800F85FC_YoshisTropicalIsland },
    { 0x1A, D_800F85FC_YoshisTropicalIsland },
    { 0x22, D_800F85FC_YoshisTropicalIsland },
    { 0x29, D_800F85FC_YoshisTropicalIsland },
    { 0x2D, D_800F860C_YoshisTropicalIsland },
    { 0x0E, D_800F860C_YoshisTropicalIsland },
    { 0x32, D_800F8574_YoshisTropicalIsland },
    { 0x25, D_800F8574_YoshisTropicalIsland },
    { 0x05, D_800F8584_YoshisTropicalIsland },
    { 0x31, D_800F8594_YoshisTropicalIsland },
    { 0x47, D_800F85A4_YoshisTropicalIsland },
    { -1, NULL },
};
EventTableEntry D_800F86B4_YoshisTropicalIsland[] = {
    { 0x47, D_800F85B4_YoshisTropicalIsland },
    { -1, NULL },
};
EventTableEntry D_800F86C4_YoshisTropicalIsland[] = {
    { 0x49, D_800F85EC_YoshisTropicalIsland },
    { -1, NULL },
};

/* .bss (ovl_38_bss) */
extern Object* D_800F86F0_YoshisTropicalIsland[2]; /* crossing boats/bridges, boardWork[2] picks one */
extern Object* D_800F86F8_YoshisTropicalIsland;    /* koopa */
extern Object* D_800F86FC_YoshisTropicalIsland;    /* toad */
extern Object* D_800F8700_YoshisTropicalIsland;    /* bowser */
extern Object* D_800F8704_YoshisTropicalIsland;    /* model for D_800F86F0 */
extern Object* D_800F8708_YoshisTropicalIsland;    /* boo */
extern Object* D_800F870C_YoshisTropicalIsland;
extern Object* D_800F8710_YoshisTropicalIsland;
extern Object* D_800F8714_YoshisTropicalIsland;    /* model for D_800F8718 */
extern Object* D_800F8718_YoshisTropicalIsland[7];
extern s32 D_800F8734_YoshisTropicalIsland;   /* label windows (func_80045D84) */
extern s32 D_800F8738_YoshisTropicalIsland;
extern s32 D_800F873C_YoshisTropicalIsland;
extern s32 D_800F8740_YoshisTropicalIsland;

extern s16 D_800EE320;

void func_800F6610_YoshisTropicalIsland(void) {
    Object* obj;
    f32 scale;
    f32 rot;
    s32 i;
    BoardSpace* space;
    void* arg;

    space = HuPrcCurrentGet()->user_data;
    PlaySound(0x6D);
    obj = MBModelCreate(0x40, NULL);
    obj->unk_0A |= 4;
    func_8004CDCC(obj);
    func_800A0D50(&obj->coords, &space->coords);
    obj->unk_30 = 500.0f;
    arg = func_80042728(obj, 0);
    scale = 0.0f;
    for (i = 0; i < 6; i++) {
        func_800A0D00((Vec3f*)&obj->xScale, scale, scale, scale);
        scale += 0.4f;
        HuPrcVSleep();
    }
    for (i = 0; i < 3; i++) {
        func_800A0D00((Vec3f*)&obj->xScale, scale, scale, scale);
        scale -= 0.4f;
        HuPrcVSleep();
    }
    HuPrcSleep(30);
    PlaySound(0x44);
    rot = 0.0f;
    while (TRUE) {
        func_800A40D0(D_800F2B7C[*obj->unk_3C->unk_40].unk7C, rot);
        rot += 20.0f;
        scale -= 0.02f;
        if (scale < 0.0f) {
            break;
        }
        func_800A0D00((Vec3f*)&obj->xScale, scale, scale, scale);
        obj->unk_30 -= 6.0f;
        HuPrcVSleep();
    }
    func_800427D4(arg);
    HuPrcSleep(30);
    MBModelKill(obj);
    EndProcess(NULL);
}

void func_800F6820_YoshisTropicalIsland(mystery_struct_ret_func_80048224* a0) {
    Object* obj;

    obj = a0->unk0;
    obj->unk_34 = 20.0f;
    obj->unk_38 = -3.0f;
    MBMotionSet(a0->unk0, 0, 0);
    HuPrcSleep(3);
    while (MBMotionCheck(a0->unk0) == 0) {
        HuPrcVSleep();
    }
    MBMotionSet(a0->unk0, -1, 2);
}

void func_800F68B0_YoshisTropicalIsland(void) {
    mystery_struct_ret_func_80048224* str;
    BoardSpace* space;

    func_80060128(43);
    str = func_80048224(D_800F8050_YoshisTropicalIsland);
    SetFadeInTypeAndTime(2, 16);
    while (func_80072718() != 0) {
        HuPrcVSleep();
    }
    func_8004A520();
    func_8004B5C4(3.0f);
    func_800F6820_YoshisTropicalIsland(str);
    LoadStringIntoWindow(str->unk8, (void*)0x4E6, -1, -1);
    func_80071C8C(str->unk8, 1);
    PlaySound(0x465);
    WaitForTextConfirmation(str->unk8);
    func_80071E80(str->unk8, 1);
    func_8006EB40(str->unk8);
    space = BoardSpaceGet(0x3B);
    func_8004B5DC(&space->coords);
    func_8004B838(5.0f);
    HuPrcSleep(5);
    while (func_8004B850() != 0) {
        HuPrcVSleep();
    }
    HuPrcSleep(5);
    omAddPrcObj(func_800F6610_YoshisTropicalIsland, 0x4800, 0, 0)->user_data = space;
    HuPrcSleep(30);
    LoadStringIntoWindow(str->unk8, (void*)0x4E7, -1, -1);
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

void func_800F6A80_YoshisTropicalIsland(void) {
    GwSystem.curBoardIndex = 2;
    omInitObjMan(10, 0);
    omOvlGotoEx(53, 0, 146);
}

void func_800F6ABC_YoshisTropicalIsland(void) {
    omInitObjMan(10, 0);
    SetPlayerOntoChain(0, 6, 0);
    SetPlayerOntoChain(1, 6, 0);
    SetPlayerOntoChain(2, 6, 0);
    SetPlayerOntoChain(3, 6, 0);
    GwCommon.boardWork[0] = 0;
    GwCommon.boardWork[1] = 0;
    GwCommon.boardWork[5] = 1;
    GwCommon.boardWork[3] = 0;
    omOvlReturnEx(1);
}

void func_800F6B40_YoshisTropicalIsland(void) {
    GW_PLAYER* player;
    GW_PLAYER* cur;
    s32 i;

    omInitObjMan(0x50, 0x28);
    func_80060088();
    func_80023448(1);
    func_800234B8(0, 0x78, 0x78, 0x78);
    func_800234B8(1, 0x40, 0x40, 0x60);
    func_80023504(1, -100.0f, 100.0f, 300.0f);
    func_80056A08(0x12, 0x47, 0x19, 0);
    func_80052E84(0);
    func_80052E84(1);
    func_80052E84(2);
    func_80052E84(3);
    for (i = 0; i < 4; i++) {
        player = GetPlayerStruct(i);
        func_8003E174(player->player_obj);
        player->player_obj->unk_0A |= 2;
    }
    func_800F6F44_YoshisTropicalIsland();
    func_800F7020_YoshisTropicalIsland();
    func_800F7118_YoshisTropicalIsland();
    func_800F72F0_YoshisTropicalIsland();
    func_800F73B4_YoshisTropicalIsland();
    func_800F7530_YoshisTropicalIsland();
    if (_CheckFlag(0xE) == 0) {
        func_800F6E6C_YoshisTropicalIsland();
    }
    if (_CheckFlag(0xF) == 0) {
        func_800F722C_YoshisTropicalIsland();
    }
    if (GwCommon.boardWork[5] != 0) {
        BoardSpaceTypeSet(0x4A, 0);
        BoardSpaceTypeSet(0x4C, 5);
    } else {
        BoardSpaceTypeSet(0x4A, 5);
        BoardSpaceTypeSet(0x4C, 0);
    }
    if (GwCommon.boardWork[3] != 0) {
        D_800F86F0_YoshisTropicalIsland[GwCommon.boardWork[2]]->unk_30 = 200.0f;
        cur = GetPlayerStruct(-1);
        if (GwCommon.boardWork[2] != 0) {
            func_8003D514(&cur->player_obj->unk_18, -90.0f);
            SetPlayerOntoChain(-1, 5, 0);
        } else {
            func_8003D514(&cur->player_obj->unk_18, 90.0f);
            SetPlayerOntoChain(-1, 4, 0);
        }
    }
}

void func_800F6D4C_YoshisTropicalIsland(void) {
    func_80060128(0xA);
    InitCameras(2);
    func_800F6B40_YoshisTropicalIsland();
    EventTableHydrate(D_800F861C_YoshisTropicalIsland);
    if (_CheckFlag(0xE) == 0) {
        EventTableHydrate(D_800F86B4_YoshisTropicalIsland);
    }
    if (_CheckFlag(0xF) == 0) {
        EventTableHydrate(D_800F86C4_YoshisTropicalIsland);
    }
    func_800584F0(0);
}

void func_800F6DC4_YoshisTropicalIsland(void) {
    InitCameras(1);
    func_800F6B40_YoshisTropicalIsland();
    func_800584F0(1);
}

void func_800F6DF0_YoshisTropicalIsland(void) {
    Object* obj;

    if (D_800F86F8_YoshisTropicalIsland != NULL) {
        return;
    }
    obj = MBModelCreate(0x39, NULL);
    func_8003E174(obj);
    D_800F86F8_YoshisTropicalIsland = obj;
    obj->unk_0A |= 2;
    func_800A0D50(&obj->coords, &BoardSpaceGet(0x37)->coords);
    func_8003C314(9, obj, 2, 2);
}

void func_800F6E6C_YoshisTropicalIsland(void) {
    D_800F86F8_YoshisTropicalIsland = NULL;
    func_800F6DF0_YoshisTropicalIsland();
}

void func_800F6E8C_YoshisTropicalIsland(s16 arg0) {
    Object* obj;

    if (D_800F86FC_YoshisTropicalIsland != NULL) {
        return;
    }
    obj = MBModelCreate(0x3A, NULL);
    func_8003E174(obj);
    D_800F86FC_YoshisTropicalIsland = obj;
    obj->unk_0A |= 2;
    func_8004CDCC(obj);
    func_800A0D50(&obj->coords, &BoardSpaceGet(D_800F8058_YoshisTropicalIsland[arg0])->coords);
    func_8003C314(6, obj, D_800F805C_YoshisTropicalIsland[arg0].x, D_800F805C_YoshisTropicalIsland[arg0].y);
}

void func_800F6F44_YoshisTropicalIsland(void) {
    D_800F86FC_YoshisTropicalIsland = NULL;
    func_800F6E8C_YoshisTropicalIsland(GwCommon.boardWork[5] & 1);
}

void func_800F6F70_YoshisTropicalIsland(s16 arg0) {
    Object* obj;

    if (D_800F8700_YoshisTropicalIsland != NULL) {
        return;
    }
    obj = MBModelCreate(0x3B, NULL);
    func_8003E174(obj);
    D_800F8700_YoshisTropicalIsland = obj;
    obj->unk_0A |= 2;
    func_800A0D50(&obj->coords, &BoardSpaceGet(D_800F8058_YoshisTropicalIsland[arg0])->coords);
    func_8003C314(7, obj, D_800F805C_YoshisTropicalIsland[arg0].x, D_800F805C_YoshisTropicalIsland[arg0].y);
}

void func_800F7020_YoshisTropicalIsland(void) {
    D_800F8700_YoshisTropicalIsland = NULL;
    func_800F6F70_YoshisTropicalIsland((GwCommon.boardWork[5] & 1) ^ 1);
}

void func_800F7050_YoshisTropicalIsland(s16 arg0) {
    Object* obj;

    if (D_800F86F0_YoshisTropicalIsland[arg0] == NULL) {
        if (D_800F8704_YoshisTropicalIsland == NULL) {
            obj = MBModelCreate(0xD, NULL);
            func_8003E174(obj);
            D_800F8704_YoshisTropicalIsland = obj;
        } else {
            obj = MBModelParamCreate(D_800F8704_YoshisTropicalIsland);
        }
        obj->unk_0A |= 2;
        D_800F86F0_YoshisTropicalIsland[arg0] = obj;
        func_800A0D50(&obj->coords, &BoardSpaceGet(D_800F8064_YoshisTropicalIsland[arg0])->coords);
    }
}

void func_800F7118_YoshisTropicalIsland(void) {
    s32 i;

    D_800F8704_YoshisTropicalIsland = NULL;
    for (i = 0; i < 2; i++) {
        func_800F7050_YoshisTropicalIsland(i);
    }
}

void func_800F715C_YoshisTropicalIsland(s16 arg0) {
    Object* obj = D_800F86F0_YoshisTropicalIsland[arg0];

    obj->unk_34 = 0.0f;
    obj->unk_38 = -10.0f;
}

void func_800F7188_YoshisTropicalIsland(void) {
    Object* obj;

    if (D_800F8708_YoshisTropicalIsland != NULL) {
        return;
    }
    obj = MBModelCreate(0x6A, NULL);
    func_8003E174(obj);
    D_800F8708_YoshisTropicalIsland = obj;
    obj->unk_0A |= 2;
    func_800A0D00((Vec3f*)&obj->xScale, 0.8f, 0.8f, 0.8f);
    obj->unk_30 = 100.0f;
    func_800A0D50(&obj->coords, &BoardSpaceGet(0x3E)->coords);
    func_8003C314(8, obj, 1, 2);
}

void func_800F722C_YoshisTropicalIsland(void) {
    D_800F8708_YoshisTropicalIsland = NULL;
    func_800F7188_YoshisTropicalIsland();
}

void func_800F724C_YoshisTropicalIsland(void) {
    Object* obj;

    if (D_800F870C_YoshisTropicalIsland != NULL) {
        return;
    }
    obj = MBModelCreate(0x72, NULL);
    func_8003E174(obj);
    D_800F870C_YoshisTropicalIsland = obj;
    obj->unk_0A |= 2;
    func_800A0D50(&obj->coords, &BoardSpaceGet(0x3D)->coords);
    func_800A0D50(&obj->unk_18, &BoardSpaceGet(0x3C)->coords);
    func_800A0E80(&obj->unk_18, &obj->unk_18, &obj->coords);
    func_8003D408(&obj->unk_18);
}

void func_800F72F0_YoshisTropicalIsland(void) {
    D_800F870C_YoshisTropicalIsland = NULL;
    func_800F724C_YoshisTropicalIsland();
}

void func_800F7310_YoshisTropicalIsland(void) {
    Object* obj;

    if (D_800F8710_YoshisTropicalIsland != NULL) {
        return;
    }
    obj = MBModelCreate(0x73, NULL);
    func_8003E174(obj);
    D_800F8710_YoshisTropicalIsland = obj;
    obj->unk_0A |= 2;
    func_800A0D50(&obj->coords, &BoardSpaceGet(0x3C)->coords);
    func_800A0D50(&obj->unk_18, &BoardSpaceGet(0x3D)->coords);
    func_800A0E80(&obj->unk_18, &obj->unk_18, &obj->coords);
    func_8003D408(&obj->unk_18);
}

void func_800F73B4_YoshisTropicalIsland(void) {
    D_800F8710_YoshisTropicalIsland = NULL;
    func_800F7310_YoshisTropicalIsland();
}

void func_800F73D4_YoshisTropicalIsland(s16 arg0) {
    Object* obj;

    if (D_800F8718_YoshisTropicalIsland[arg0] == NULL) {
        if (D_800F8714_YoshisTropicalIsland == NULL) {
            obj = MBModelCreate(0x75, NULL);
            func_8003E174(obj);
            D_800F8714_YoshisTropicalIsland = obj;
        } else {
            obj = MBModelParamCreate(D_800F8714_YoshisTropicalIsland);
        }
        obj->unk_0A |= 2;
        D_800F8718_YoshisTropicalIsland[arg0] = obj;
        func_800A0D50(&obj->coords, &BoardSpaceGet(D_800F8068_YoshisTropicalIsland[arg0])->coords);
        func_8003D514(&obj->unk_18, D_800F8078_YoshisTropicalIsland[arg0]);
        func_80025EB4(*obj->unk_3C->unk_40, 1, 1);
    }
}

void func_800F74CC_YoshisTropicalIsland(void) {
    s32 i;

    while (TRUE) {
        HuPrcVSleep();
        for (i = 0; i < 7; i++) {
            func_8003D514(&D_800F8718_YoshisTropicalIsland[i]->unk_18, 12.0f);
        }
    }
}

void func_800F7530_YoshisTropicalIsland(void) {
    s32 i;

    D_800F8714_YoshisTropicalIsland = NULL;
    for (i = 0; i < 7; i++) {
        func_800F73D4_YoshisTropicalIsland(i);
    }
    omPrcSetStatBit(omAddPrcObj(func_800F74CC_YoshisTropicalIsland, 0x1005, 0, 0), 0x80);
}

s32 func_800F7598_YoshisTropicalIsland(s16 index, s16 coins) {
    return PlayerHasCoins(-1, GwCommon.boardWork[index] + coins) != 0;
}

s32 func_800F75D8_YoshisTropicalIsland(void) {
    return func_800F7598_YoshisTropicalIsland(0, 40);
}

s32 func_800F75F8_YoshisTropicalIsland(void) {
    return func_800F7598_YoshisTropicalIsland(0, 20);
}

s32 func_800F7618_YoshisTropicalIsland(void) {
    return func_800F7598_YoshisTropicalIsland(0, 10);
}

s32 func_800F7638_YoshisTropicalIsland(void) {
    return func_800F7598_YoshisTropicalIsland(1, 10);
}

void func_800F7658_YoshisTropicalIsland(void) {
    while (func_8004B850() != 0) {
        HuPrcVSleep();
    }
    HuPrcVSleep();
    D_800F8734_YoshisTropicalIsland = func_80045D84(0, 0x92, 1);
    D_800F8738_YoshisTropicalIsland = func_80045D84(1, 0xA0, 1);
    D_800F873C_YoshisTropicalIsland = func_80045D84(3, 0xAE, 1);
    D_800F8740_YoshisTropicalIsland = func_80045D84(0xB, 0xBC, 1);
    HuPrcSleep(3);
    D_800EE320 = 1;
}

void func_800F7708_YoshisTropicalIsland(void) {
    D_800EE320 = 0;
    func_80045E6C(D_800F8734_YoshisTropicalIsland);
    func_80045E6C(D_800F8738_YoshisTropicalIsland);
    func_80045E6C(D_800F873C_YoshisTropicalIsland);
    func_80045E6C(D_800F8740_YoshisTropicalIsland);
}

void func_800F7754_YoshisTropicalIsland(YTIGate* gate) {
    char buf[8];
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
    if (PlayerHasCoins(-1, GwCommon.boardWork[gate->boardWorkIndex] + 1) != 0) {
        func_800F7658_YoshisTropicalIsland();
        prompt = func_8003C218(-1, gate->spaces);
        func_8003C060(prompt, -1, 0);
        if (PlayerIsCPU(-1) != 0) {
            count = RunDecisionTree(gate->tree);
            for (i = 0; i < count; i++) {
                func_8003BE84(prompt, -2);
            }
            func_8003BE84(prompt, -4);
        }
        dir = DirectionPrompt(prompt);
        func_8003B908(prompt);
        func_800F7708_YoshisTropicalIsland();
        if (dir != 0) {
            GwCommon.boardWork[2] = gate->boardWorkIndex;
            func_800587EC(0x4D, 0, 1);
            SetEventReturnFlag(1);
            return;
        }
    } else {
        win = CreateTextWindow(0x4E, 0x3C, 0xE, 2);
        LoadStringIntoWindow(win, (void*)0x1B5, -1, -1);
        sprintf(buf, "%d", GwCommon.boardWork[gate->boardWorkIndex] + 1);
        func_8006DA5C(win, buf, 0);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        func_8004DBD4(win, GetCurrentPlayerIndex());
        HideTextWindow(win);
    }
    SetNextChainAndSpace(-1, gate->chain, 0);
}

void func_800F7954_YoshisTropicalIsland(void) {
    YTIWaitArgs* args;
    Object* obj;

    args = HuPrcCurrentGet()->user_data;
    obj = D_800F86F0_YoshisTropicalIsland[args->index];
    while (obj->unk_30 > 1.0f) {
        HuPrcVSleep();
    }
    func_80058910(args->player, 2);
    EndProcess(NULL);
}

void func_800F79F0_YoshisTropicalIsland(s16 player, s16 index) {
    Process* process;
    YTIWaitArgs* args;

    if (player == -1) {
        player = GetCurrentPlayerIndex();
    }
    process = omAddPrcObj(func_800F7954_YoshisTropicalIsland, 0x4800, 0, 0x40);
    args = HuMemMemoryAlloc(process->heap, sizeof(YTIWaitArgs));
    process->user_data = args;
    args->player = player;
    args->index = index;
}

void func_800F7A74_YoshisTropicalIsland(void) {
    func_800F7754_YoshisTropicalIsland(&D_800F851C_YoshisTropicalIsland);
    EndProcess(NULL);
}

void func_800F7A9C_YoshisTropicalIsland(void) {
    if (GwCommon.boardWork[3] != 0) {
        func_800F79F0_YoshisTropicalIsland(-1, 0);
        SetNextChainAndSpace(-1, 0, 0);
    } else {
        SetNextChainAndSpace(-1, 1, 0);
    }
}

void func_800F7AE0_YoshisTropicalIsland(void) {
    func_800F7754_YoshisTropicalIsland(&D_800F854C_YoshisTropicalIsland);
    EndProcess(NULL);
}

void func_800F7B08_YoshisTropicalIsland(void) {
    if (GwCommon.boardWork[3] != 0) {
        func_800F79F0_YoshisTropicalIsland(-1, 1);
        SetNextChainAndSpace(-1, 2, 0);
    } else {
        SetNextChainAndSpace(-1, 3, 0);
    }
}

void func_800F7B4C_YoshisTropicalIsland(void) {
    if (GwCommon.boardWork[3] != 0) {
        GwCommon.boardWork[3] = 0;
        func_800F715C_YoshisTropicalIsland(GwCommon.boardWork[2]);
    }
}

void func_800F7B80_YoshisTropicalIsland(void) {
    SetNextChainAndSpace(-1, 2, 0);
}

void func_800F7BA4_YoshisTropicalIsland(void) {
    SetNextChainAndSpace(-1, 0, 0);
}

void func_800F7BC8_YoshisTropicalIsland(void) {
    SetNextChainAndSpace(-1, 6, 1);
}

// decomp-permuter
void func_800F7BEC_YoshisTropicalIsland(void)
{
  short win;
  s16 player;
  s32 amount;
  player = GetCurrentPlayerIndex();
  func_800405DC(player);
  SetPlayerAnimation(-1, -1, 2);
  if (_CheckFlag(0x42) == 0)
  {
    win = CreateTextWindow(0x48, 0x3C, 0x10, 3);
    LoadStringIntoWindow(win, (void *) 0x239, -1, -1);
    amount = 10;
  }
  else
  {
    win = CreateTextWindow(0x41, 0x3C, 0x11, 3);
    LoadStringIntoWindow(win, (void *) 0x23A, -1, -1);
    amount = 20;
  }
  win = (s16) win;
  func_8006E070(win, 0);
  ShowTextWindow(win);
  PlaySound(0x432);
  func_8004DBD4(win, player);
  HideTextWindow(win);
  win = amount;
  func_80055960(player, win);
  ShowPlayerCoinChange(player, win);
  HuPrcSleep(30);
  func_8003FEFC(player);
}

void func_800F7D20_YoshisTropicalIsland(void) {
    GwCommon.boardWork[31]++;
    if (_CheckFlag(0x42) == 0 && (GwCommon.boardWork[31] % 10 == 0 || _CheckFlag(0x4D) == 0)) {
        if (_CheckFlag(0x4D) != 0) {
            func_80058910(-1, 1);
        }
        SetBoardFeatureFlag(0x4D);
        func_800587EC(0x5F, 0, 1);
    } else {
        func_800F7BEC_YoshisTropicalIsland();
    }
}

void func_800F7DF0_YoshisTropicalIsland(void) {
    func_8004D2A4(-1, 8, 0x37);
    func_800F7D20_YoshisTropicalIsland();
    EndProcess(NULL);
}

void func_800F7E24_YoshisTropicalIsland(void) {
    func_8004D2A4(-1, 8, 0x3A);
    if (GwCommon.boardWork[5] != 0) {
        func_800587BC(0x4F, 0, 3, 1);
    } else {
        GwSystem.unk_1A = 0x46;
        func_800587EC(0x44, 0, 2);
    }
}

void func_800F7E8C_YoshisTropicalIsland(void) {
    func_8004D2A4(-1, 8, 0x3B);
    if (GwCommon.boardWork[5] != 0) {
        GwSystem.unk_1A = 0x46;
        func_800587EC(0x44, 0, 2);
    } else {
        func_800587BC(0x4F, 0, 3, 1);
    }
}

void func_800F7EF4_YoshisTropicalIsland(void) {
    func_8004D2A4(-1, 8, 0x3E);
    func_800587EC(0x65, 0, 1);
}

void func_800F7F28_YoshisTropicalIsland(void) {
    func_800587EC(0x4E, 0, 4);
}

void func_800F7F4C_YoshisTropicalIsland(void) {
    GW_PLAYER* player;
    s32 i;

    for (i = 0; i < 4; i++) {
        player = GetPlayerStruct(i);
        player->group = i != GetCurrentPlayerIndex();
    }
    func_800587BC(1, 0, 5, 1);
}

void func_800F68B0_YoshisTropicalIsland(void);

void func_800F7FB8_YoshisTropicalIsland(void) {
    InitCameras(2);
    func_8001D4D4(1, &D_800F8040_YoshisTropicalIsland);
    func_800F6B40_YoshisTropicalIsland();
    func_800584F0(2);
    omAddPrcObj(func_800F68B0_YoshisTropicalIsland, 0x1005, 0, 0);
}
