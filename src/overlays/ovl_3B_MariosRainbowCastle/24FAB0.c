#include "common.h"
#include "engine/process.h"
#include "spaces.h"

void func_800F6610_MariosRainbowCastle(void);
void func_800F68B0_MariosRainbowCastle(void);
void func_800F6B2C_MariosRainbowCastle(void);
void func_800F6D2C_MariosRainbowCastle(void);
void func_800F6D8C_MariosRainbowCastle(void);
void func_800F6DE8_MariosRainbowCastle(void);
void func_800F6E08_MariosRainbowCastle(void);
void func_800F6E84_MariosRainbowCastle(void);
void func_800F6EA4_MariosRainbowCastle(void);
void func_800F6F50_MariosRainbowCastle(void);
void func_800F6F70_MariosRainbowCastle(s16 arg0);
void func_800F7078_MariosRainbowCastle(void);
void func_800F71B4_MariosRainbowCastle(void);
void func_800F72BC_MariosRainbowCastle(void);
void func_800F72E0_MariosRainbowCastle(void);
void func_800F73E8_MariosRainbowCastle(void);
void func_800F740C_MariosRainbowCastle(void);
void func_800F7430_MariosRainbowCastle(void);
void func_800F76F0_MariosRainbowCastle(void);
void func_800F7774_MariosRainbowCastle(void);
void func_800F7C04_MariosRainbowCastle(void);
void func_800F7C28_MariosRainbowCastle(void);
void func_800F7D5C_MariosRainbowCastle(void);
void func_800F7E2C_MariosRainbowCastle(void);
void func_800F7E60_MariosRainbowCastle(void);
void func_800F7E94_MariosRainbowCastle(void);
void func_80056E48(Vec3f*);
void func_80056E30(s16);
void func_8004A7A4(void);
void func_8004A7DC(void);
f32 func_8004B5D0(void);
f32 func_8004B844(void);
void func_8004DBD4(s32, s32);
extern s16 D_800EE320;

/* .data (0x800F7F90..0x800F8430) */
Vec4f D_800F7F90_MariosRainbowCastle = { 0.0f, 0.0f, 320.0f, 240.0f };
s32 D_800F7FA0_MariosRainbowCastle[] = { 1, 0x70003 }; /* MBModelCreate motion list: words */
s16 D_800F7FA8_MariosRainbowCastle[] = { 1, 0 };
DecisionTreeNonLeafNode D_800F7FAC_MariosRainbowCastle[2] = {
    { 0x07000000, { (void*)0xB }, { 0x3C3C } },
    { 0x0, { (void*)0x0 }, { 0x4646 } },
};
DecisionTreeNonLeafNode D_800F7FC4_MariosRainbowCastle[3] = {
    { 0x04000000, { (void*)0x0 }, { (u32)D_800F7FAC_MariosRainbowCastle } },
    { 0x07000000, { (void*)0xB }, { 0x2828 } },
    { 0x0, { (void*)0x0 }, { 0x3232 } },
};
DecisionTreeNonLeafNode D_800F7FE8_MariosRainbowCastle[3] = {
    { 0x05000000, { (void*)0x1 }, { 0x1E14 } },
    { 0x05000000, { (void*)0x6 }, { 0x3228 } },
    { 0x0, { (void*)0x0 }, { 0x463C } },
};
DecisionTreeNonLeafNode D_800F800C_MariosRainbowCastle[4] = {
    { 0x07000000, { (void*)0xB }, { (u32)D_800F7FE8_MariosRainbowCastle } },
    { 0x05000000, { (void*)0x1 }, { 0x2828 } },
    { 0x05000000, { (void*)0x6 }, { 0x3C3C } },
    { 0x0, { (void*)0x0 }, { 0x5046 } },
};
DecisionTreeNonLeafNode D_800F803C_MariosRainbowCastle[3] = {
    { 0x05000000, { (void*)0x1 }, { 0x1E28 } },
    { 0x05000000, { (void*)0x6 }, { 0x3232 } },
    { 0x0, { (void*)0x0 }, { 0x463C } },
};
DecisionTreeNonLeafNode D_800F8060_MariosRainbowCastle[6] = {
    { 0x03000000, { (void*)0x1 }, { (u32)D_800F7FC4_MariosRainbowCastle } },
    { 0x03000000, { (void*)0x8 }, { (u32)D_800F800C_MariosRainbowCastle } },
    { 0x07000000, { (void*)0xB }, { (u32)D_800F803C_MariosRainbowCastle } },
    { 0x05000000, { (void*)0x1 }, { 0x1E28 } },
    { 0x05000000, { (void*)0x6 }, { 0x3C3C } },
    { 0x0, { (void*)0x0 }, { 0x5046 } },
};
DecisionTreeNonLeafNode D_800F80A8_MariosRainbowCastle[3] = {
    { 0x05000000, { (void*)0x1 }, { 0x1E28 } },
    { 0x05000000, { (void*)0x6 }, { 0x3232 } },
    { 0x0, { (void*)0x0 }, { 0x463C } },
};
DecisionTreeNonLeafNode D_800F80CC_MariosRainbowCastle[3] = {
    { 0x05000000, { (void*)0x1 }, { 0x3232 } },
    { 0x05000000, { (void*)0x6 }, { 0x1E28 } },
    { 0x0, { (void*)0x0 }, { 0x141E } },
};
DecisionTreeNonLeafNode D_800F80F0_MariosRainbowCastle[4] = {
    { 0x04000000, { (void*)0x10000 }, { (u32)D_800F80CC_MariosRainbowCastle } },
    { 0x05000000, { (void*)0x1 }, { 0x2832 } },
    { 0x05000000, { (void*)0x6 }, { 0x463C } },
    { 0x0, { (void*)0x0 }, { 0x5A46 } },
};
DecisionTreeNonLeafNode D_800F8120_MariosRainbowCastle[2] = {
    { 0x04000000, { (void*)0x0 }, { 0x504B } },
    { 0x0, { (void*)0x0 }, { 0x1423 } },
};
DecisionTreeNonLeafNode D_800F8138_MariosRainbowCastle[2] = {
    { 0x07000000, { (void*)0xB }, { 0x504B } },
    { 0x0, { (void*)0x0 }, { 0x3C3C } },
};
DecisionTreeNonLeafNode D_800F8150_MariosRainbowCastle[3] = {
    { 0x04000000, { (void*)0x10000 }, { (u32)D_800F8138_MariosRainbowCastle } },
    { 0x07000000, { (void*)0xB }, { 0x1423 } },
    { 0x0, { (void*)0x0 }, { 0xA1E } },
};
DecisionTreeNonLeafNode D_800F8174_MariosRainbowCastle[3] = {
    { 0x05000000, { (void*)0x1 }, { 0x1E28 } },
    { 0x05000000, { (void*)0x6 }, { 0x141E } },
    { 0x0, { (void*)0x0 }, { 0xA } },
};
DecisionTreeNonLeafNode D_800F8198_MariosRainbowCastle[5] = {
    { 0x04000000, { (void*)0x10000 }, { (u32)D_800F8174_MariosRainbowCastle } },
    { 0x07000000, { (void*)0xB }, { 0x2828 } },
    { 0x05000000, { (void*)0x1 }, { 0x3C3C } },
    { 0x05000000, { (void*)0x6 }, { 0x2828 } },
    { 0x0, { (void*)0x0 }, { 0x1E1E } },
};
DecisionTreeNonLeafNode D_800F81D4_MariosRainbowCastle[5] = {
    { 0x04000000, { (void*)0x10000 }, { 0x5F50 } },
    { 0x07000000, { (void*)0xB }, { 0x514 } },
    { 0x05000000, { (void*)0x1 }, { 0xA1E } },
    { 0x05000000, { (void*)0x6 }, { 0x514 } },
    { 0x0, { (void*)0x0 }, { 0x14 } },
};
DecisionTreeNonLeafNode D_800F8210_MariosRainbowCastle[8] = {
    { 0x03000000, { (void*)0x1 }, { (u32)D_800F80A8_MariosRainbowCastle } },
    { 0x03000000, { (void*)0x4 }, { (u32)D_800F80F0_MariosRainbowCastle } },
    { 0x03000000, { (void*)0x10 }, { (u32)D_800F8120_MariosRainbowCastle } },
    { 0x03000000, { (void*)0x40 }, { (u32)D_800F8150_MariosRainbowCastle } },
    { 0x03000000, { (void*)0x80 }, { (u32)D_800F8198_MariosRainbowCastle } },
    { 0x03000000, { (void*)0x200 }, { (u32)D_800F81D4_MariosRainbowCastle } },
    { 0x04000000, { (void*)0x0 }, { 0x514 } },
    { 0x0, { (void*)0x0 }, { 0x5F50 } },
};
s16 D_800F8270_MariosRainbowCastle[] = { 0xB, 0x18, -1, 0x0 };
EventListEntry D_800F8278_MariosRainbowCastle[] = {
    { 1, 2, func_800F71B4_MariosRainbowCastle },
    { 0, 0, NULL },
};
EventListEntry D_800F8288_MariosRainbowCastle[] = {
    { 1, 1, func_800F72BC_MariosRainbowCastle },
    { 0, 0, NULL },
};
s16 D_800F8298_MariosRainbowCastle[] = { 0x27, 0x2D, -1, 0x0 };
EventListEntry D_800F82A0_MariosRainbowCastle[] = {
    { 1, 2, func_800F72E0_MariosRainbowCastle },
    { 0, 0, NULL },
};
EventListEntry D_800F82B0_MariosRainbowCastle[] = {
    { 1, 1, func_800F73E8_MariosRainbowCastle },
    { 0, 0, NULL },
};
EventListEntry D_800F82C0_MariosRainbowCastle[] = {
    { 3, 1, func_800F740C_MariosRainbowCastle },
    { 0, 0, NULL },
};
s32 D_800F82D0_MariosRainbowCastle[] = { 2, 0x0001001E, 0x0001001D };
s32 D_800F82DC_MariosRainbowCastle[] = { 2, 0x0002001E, 0x0002001D };
s32 D_800F82E8_MariosRainbowCastle[] = { 2, 0x0003001E, 0x0003001D };
s32 D_800F82F4_MariosRainbowCastle[] = { 2, 0x0004001E, 0x0004001D };
s32 D_800F8300_MariosRainbowCastle[] = { 2, 0x0005001E, 0x0005001D };
s32 D_800F830C_MariosRainbowCastle[] = { 2, 0x0006001E, 0x0006001D };
/* per character; MBModelCreate motion lists */
s32* D_800F8318_MariosRainbowCastle[] = {
    D_800F82D0_MariosRainbowCastle, D_800F82DC_MariosRainbowCastle, D_800F830C_MariosRainbowCastle,
    D_800F82E8_MariosRainbowCastle, D_800F82F4_MariosRainbowCastle, D_800F8300_MariosRainbowCastle,
};
EventListEntry D_800F8330_MariosRainbowCastle[] = {
    { 1, 2, func_800F7430_MariosRainbowCastle },
    { 2, 2, func_800F7774_MariosRainbowCastle },
    { 0, 0, NULL },
};
EventListEntry D_800F8348_MariosRainbowCastle[] = {
    { 1, 1, func_800F7C04_MariosRainbowCastle },
    { 0, 0, NULL },
};
EventListEntry D_800F8358_MariosRainbowCastle[] = {
    { 1, 1, func_800F7C04_MariosRainbowCastle },
    { 1, 2, func_800F7E2C_MariosRainbowCastle },
    { 0, 0, NULL },
};
EventListEntry D_800F8370_MariosRainbowCastle[] = {
    { 1, 1, func_800F7E60_MariosRainbowCastle },
    { 0, 0, NULL },
};
EventListEntry D_800F8380_MariosRainbowCastle[] = {
    { 3, 1, func_800F7E94_MariosRainbowCastle },
    { 0, 0, NULL },
};
EventTableEntry D_800F8390_MariosRainbowCastle[] = {
    { 0x0E, D_800F8380_MariosRainbowCastle },
    { 0x34, D_800F8380_MariosRainbowCastle },
    { 0x3D, D_800F8278_MariosRainbowCastle },
    { 0x3E, D_800F82A0_MariosRainbowCastle },
    { 0x3F, D_800F8348_MariosRainbowCastle },
    { 0x17, D_800F8288_MariosRainbowCastle },
    { 0x19, D_800F8288_MariosRainbowCastle },
    { 0x2C, D_800F82B0_MariosRainbowCastle },
    { 0x30, D_800F82B0_MariosRainbowCastle },
    { 0x3C, D_800F8330_MariosRainbowCastle },
    { 0x36, D_800F82C0_MariosRainbowCastle },
    { 0x18, D_800F82C0_MariosRainbowCastle },
    { 0x23, D_800F82C0_MariosRainbowCastle },
    { 0x2B, D_800F82C0_MariosRainbowCastle },
    { 0x32, D_800F82C0_MariosRainbowCastle },
    { -1, NULL },
};
EventTableEntry D_800F8410_MariosRainbowCastle[] = {
    { 0x3F, D_800F8358_MariosRainbowCastle },
    { -1, NULL },
};
EventTableEntry D_800F8420_MariosRainbowCastle[] = {
    { 0x3B, D_800F8370_MariosRainbowCastle },
    { -1, NULL },
};

/* .bss */
extern Object* D_800F8430_MariosRainbowCastle;
extern Object* D_800F8434_MariosRainbowCastle;
extern Object* D_800F8438_MariosRainbowCastle;
extern Object* D_800F843C_MariosRainbowCastle;
extern Object* D_800F8440_MariosRainbowCastle[];
extern s32 D_800F8444_MariosRainbowCastle;
extern s32 D_800F8448_MariosRainbowCastle;
extern s32 D_800F844C_MariosRainbowCastle;
extern s32 D_800F8450_MariosRainbowCastle;

void func_800F6610_MariosRainbowCastle(void) {
    Object* temp_v0;
    f32 var_f20;
    f32 var_f22;
    s32 var_s0;
    BoardSpace* temp_s0;
    void* temp_s2;

    temp_s0 = HuPrcCurrentGet()->user_data;
    PlaySound(0x6D);
    temp_v0 = MBModelCreate(0x40U, NULL);
    temp_v0->unk_0A |= 4;
    func_8004CDCC(temp_v0);
    func_800A0D50(&temp_v0->coords, &temp_s0->coords);
    temp_v0->unk_30 = 500.0f;
    temp_s2 = func_80042728(temp_v0, 0);
    var_f20 = 0.0f;
    for(var_s0 = 0; var_s0 < 6; var_s0++) {
        func_800A0D00((Vec3f*)&temp_v0->xScale, var_f20, var_f20, var_f20);
        var_f20 += 0.4f;
        HuPrcVSleep();
    }
    for(var_s0 = 0; var_s0 < 3; var_s0++) {
        func_800A0D00((Vec3f*)&temp_v0->xScale, var_f20, var_f20, var_f20);
        var_f20 -= 0.4f;
        HuPrcVSleep();
    }
    HuPrcSleep(0x1E);
    PlaySound(0x44);
    var_f22 = 0.0f;
    while (TRUE) {
        func_800A40D0(D_800F2B7C[*temp_v0->unk_3C->unk_40].unk7C, var_f22);
        var_f22 += 20.0f;
        var_f20 -= 0.02f;
        if (var_f20 < 0.0f) {
            break;
        }
        func_800A0D00((Vec3f*)&temp_v0->xScale, var_f20, var_f20, var_f20);
        temp_v0->unk_30 -= 6.0f;
        HuPrcVSleep();
    }
    func_800427D4(temp_s2);
    HuPrcSleep(0x1E);
    MBModelKill(temp_v0);
    EndProcess(NULL);
}


void func_800F6820_MariosRainbowCastle(mystery_struct_ret_func_80048224* arg0) {
    Object* obj;

    obj = arg0->unk0;
    obj->unk_34 = 20.0f;
    obj->unk_38 = -3.0f;
    MBMotionSet(arg0->unk0, 0, 0);
    HuPrcSleep(3);
    while (MBMotionCheck(arg0->unk0) == 0) {
        HuPrcVSleep();
    }
    MBMotionSet(arg0->unk0, -1, 2);
}

void func_800F68B0_MariosRainbowCastle(void) {
    mystery_struct_ret_func_80048224* str;
    BoardSpace* space;

    func_80060128(43);
    str = func_80048224(D_800F7FA0_MariosRainbowCastle);
    SetFadeInTypeAndTime(2, 16);
    while (func_80072718() != 0) {
        HuPrcVSleep();
    }
    func_8004A520();
    func_8004B5C4(3.0f);
    func_800F6820_MariosRainbowCastle(str);
    LoadStringIntoWindow(str->unk8, (void*)0x4E6, -1, -1);
    func_80071C8C(str->unk8, 1);
    PlaySound(0x465);
    WaitForTextConfirmation(str->unk8);
    func_80071E80(str->unk8, 1);
    func_8006EB40(str->unk8);
    space = BoardSpaceGet(2);
    func_8004B5DC(&space->coords);
    func_8004B838(5.0f);
    HuPrcSleep(5);
    while (func_8004B850() != 0) {
        HuPrcVSleep();
    }
    HuPrcSleep(5);
    omAddPrcObj(func_800F6610_MariosRainbowCastle, 0x4800, 0, 0)->user_data = space;
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

void func_800F6A80_MariosRainbowCastle(void) {
    GwSystem.curBoardIndex = 5;
    omInitObjMan(10, 0);
    omOvlGotoEx(53, 0, 146);
}

void func_800F6ABC_MariosRainbowCastle(void) {
    omInitObjMan(10, 0);
    SetPlayerOntoChain(0, 0, 0);
    SetPlayerOntoChain(1, 0, 0);
    SetPlayerOntoChain(2, 0, 0);
    SetPlayerOntoChain(3, 0, 0);
    GwCommon.boardWork[0] = 0;
    omOvlReturnEx(1);
}

void func_800F6B2C_MariosRainbowCastle(void) {
    GW_PLAYER* player;
    s32 i;

    omInitObjMan(80, 40);
    func_80060088();
    func_80023448(1);
    func_800234B8(0, 0x78, 0x78, 0x78);
    func_800234B8(1, 0x40, 0x40, 0x60);
    func_80023504(1, -100.0f, 100.0f, 300.0f);
    func_80056A08(0x2F, 0x4A, 0x35, 0);
    func_80052E84(0);
    func_80052E84(1);
    func_80052E84(2);
    func_80052E84(3);
    for (i = 0; i < 4; i++) {
        player = GetPlayerStruct(i);
        func_8003E174(player->player_obj);
        player->player_obj->unk_0A |= 2;
    }
    func_800F6F50_MariosRainbowCastle();
    func_800F6DE8_MariosRainbowCastle();
    if (_CheckFlag(0xE) == 0) {
        func_800F6E84_MariosRainbowCastle();
    }
    if (_CheckFlag(0xF) == 0) {
        func_800F7078_MariosRainbowCastle();
    }
}

void func_800F6C50_MariosRainbowCastle(void) {
    func_80060128(0xD);
    InitCameras(2);
    func_800F6B2C_MariosRainbowCastle();
    EventTableHydrate(D_800F8390_MariosRainbowCastle);
    if (_CheckFlag(0xE) == 0) {
        EventTableHydrate(D_800F8410_MariosRainbowCastle);
    }
    if (_CheckFlag(0xF) == 0) {
        EventTableHydrate(D_800F8420_MariosRainbowCastle);
    }
    func_800584F0(0);
    if (_CheckFlag(0x4F) != 0) {
        ClearBoardFeatureFlag(0x4F);
        func_800F6D2C_MariosRainbowCastle();
    }
}

void func_800F6CE8_MariosRainbowCastle(void) {
    InitCameras(1);
    func_800F6B2C_MariosRainbowCastle();
    func_800584F0(1);
    if (_CheckFlag(0x4F) != 0) {
        func_800F6D2C_MariosRainbowCastle();
    }
}

void func_800F6D2C_MariosRainbowCastle(void) {
    GW_PLAYER* player;
    Object* obj;

    player = GetPlayerStruct(-1);
    obj = D_800F8430_MariosRainbowCastle;
    BoardSpaceGet(GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain, player->cur_space));
    func_800A0D50(&obj->coords, &player->player_obj->coords);
}

void func_800F6D8C_MariosRainbowCastle(void) {
    Object* obj;

    if (D_800F8430_MariosRainbowCastle == NULL) {
        obj = MBModelCreate(0x12, NULL);
        func_8003E174(obj);
        D_800F8430_MariosRainbowCastle = obj;
        func_800A0D50(&obj->coords, &BoardSpaceGet(3)->coords);
    }
}

void func_800F6DE8_MariosRainbowCastle(void) {
    D_800F8430_MariosRainbowCastle = NULL;
    func_800F6D8C_MariosRainbowCastle();
}

void func_800F6E08_MariosRainbowCastle(void) {
    Object* obj;

    if (D_800F8434_MariosRainbowCastle == NULL) {
        obj = MBModelCreate(0x39, NULL);
        func_8003E174(obj);
        D_800F8434_MariosRainbowCastle = obj;
        obj->unk_0A |= 2;
        func_800A0D50(&obj->coords, &BoardSpaceGet(0)->coords);
        func_8003C314(9, obj, 0, 0);
    }
}

void func_800F6E84_MariosRainbowCastle(void) {
    D_800F8434_MariosRainbowCastle = NULL;
    func_800F6E08_MariosRainbowCastle();
}

void func_800F6EA4_MariosRainbowCastle(void) {
    Object* obj;

    if (D_800F8438_MariosRainbowCastle == NULL) {
        if (GwCommon.boardWork[0] == 0) {
            obj = MBModelCreate(0x3A, NULL);
            func_8004CDCC(obj);
            func_8003C314(6, obj, 0, 0);
        } else {
            obj = MBModelCreate(0x3B, NULL);
            func_8003C314(7, obj, 0, 0);
        }
        obj->unk_0A |= 2;
        D_800F8438_MariosRainbowCastle = obj;
        func_8003E174(obj);
        func_800A0D50(&obj->coords, &BoardSpaceGet(2)->coords);
    }
}

void func_800F6F50_MariosRainbowCastle(void) {
    D_800F8438_MariosRainbowCastle = NULL;
    func_800F6EA4_MariosRainbowCastle();
}

void func_800F6F70_MariosRainbowCastle(s16 arg0) {
    Object* obj;

    if (D_800F8440_MariosRainbowCastle[arg0] == 0) {
        if (D_800F843C_MariosRainbowCastle == NULL) {
            obj = MBModelCreate(0x6A, NULL);
            func_8003E174(obj);
            D_800F843C_MariosRainbowCastle = obj;
        } else {
            obj = MBModelParamCreate(D_800F843C_MariosRainbowCastle);
        }
        D_800F8440_MariosRainbowCastle[arg0] = obj;
        obj->unk_0A |= 2;
        func_800A0D00((Vec3f*)&obj->xScale, 0.6f, 0.6f, 0.6f);
        obj->unk_30 = 100.0f;
        func_800A0D50(&obj->coords, &BoardSpaceGet(D_800F7FA8_MariosRainbowCastle[arg0])->coords);
        func_8003C314(8, obj, 0, 0);
    }
}

void func_800F7078_MariosRainbowCastle(void) {
    s32 i;

    D_800F843C_MariosRainbowCastle = NULL;
    for (i = 0; i < 1; i++) {
        func_800F6F70_MariosRainbowCastle(i);
    }
}

void func_800F70B8_MariosRainbowCastle(void) {
    while (func_8004B850() != 0) {
        HuPrcVSleep();
    }
    HuPrcVSleep();
    D_800F8444_MariosRainbowCastle = func_80045D84(0, 0x92, 1);
    D_800F8448_MariosRainbowCastle = func_80045D84(1, 0xA0, 1);
    D_800F844C_MariosRainbowCastle = func_80045D84(3, 0xAE, 1);
    D_800F8450_MariosRainbowCastle = func_80045D84(0xB, 0xBC, 1);
    HuPrcSleep(3);
    D_800EE320 = 1;
}

void func_800F7168_MariosRainbowCastle(void) {
    D_800EE320 = 0;
    func_80045E6C(D_800F8444_MariosRainbowCastle);
    func_80045E6C(D_800F8448_MariosRainbowCastle);
    func_80045E6C(D_800F844C_MariosRainbowCastle);
    func_80045E6C(D_800F8450_MariosRainbowCastle);
}

void func_800F71B4_MariosRainbowCastle(void) {
    unk_8003B8D4Struct* prompt;
    s32 dir;
    s32 i;
    s32 n;

    SetPlayerAnimation(-1, -1, 2);
    HuPrcVSleep();
    func_800F70B8_MariosRainbowCastle();
    prompt = func_8003C218(GwSystem.curPlayerIndex, D_800F8270_MariosRainbowCastle);
    func_8003C060(prompt, GwSystem.curPlayerIndex, 0);
    if (PlayerIsCPU(-1) != 0) {
        n = RunDecisionTree(D_800F8060_MariosRainbowCastle);
        for (i = 0; i < n; i++) {
            func_8003BE84(prompt, -2);
        }
        func_8003BE84(prompt, -4);
    }
    dir = DirectionPrompt(prompt);
    func_8003B908(prompt);
    func_800F7168_MariosRainbowCastle();
    if (dir == 0) {
        SetNextChainAndSpace(-1, 1, 0);
    } else {
        SetNextChainAndSpace(-1, 2, 0);
    }
    EndProcess(NULL);
}

void func_800F72BC_MariosRainbowCastle(void) {
    SetNextChainAndSpace(-1, 3, 0);
}

void func_800F72E0_MariosRainbowCastle(void) {
    unk_8003B8D4Struct* prompt;
    s32 dir;
    s32 i;
    s32 n;

    SetPlayerAnimation(-1, -1, 2);
    HuPrcVSleep();
    func_800F70B8_MariosRainbowCastle();
    prompt = func_8003C218(GwSystem.curPlayerIndex, D_800F8298_MariosRainbowCastle);
    func_8003C060(prompt, GwSystem.curPlayerIndex, 0);
    if (PlayerIsCPU(-1) != 0) {
        n = RunDecisionTree(D_800F8210_MariosRainbowCastle);
        for (i = 0; i < n; i++) {
            func_8003BE84(prompt, -2);
        }
        func_8003BE84(prompt, -4);
    }
    dir = DirectionPrompt(prompt);
    func_8003B908(prompt);
    func_800F7168_MariosRainbowCastle();
    if (dir == 0) {
        SetNextChainAndSpace(-1, 4, 0);
    } else {
        SetNextChainAndSpace(-1, 5, 0);
    }
    EndProcess(NULL);
}

void func_800F73E8_MariosRainbowCastle(void) {
    SetNextChainAndSpace(-1, 6, 0);
}

void func_800F740C_MariosRainbowCastle(void) {
    func_800587EC(0x56, 0, 4);
}

// decomp-permuter
void func_800F7430_MariosRainbowCastle(void)
{
  Vec3f dir;
  Object *obj;
  GW_PLAYER *player;
  Object *model;
  Vec3f *pos;
  Vec3f *modelPos;
  Vec3f *dest;
  BoardSpace *space;
  player = GetPlayerStruct(-1);
  obj = player->player_obj;
 do { model = D_800F8430_MariosRainbowCastle; pos = &obj->coords; func_8004B838(4.0f); func_80056E30(2); func_80056E48(&BoardSpaceGet(2)->coords); func_800A0E80(&dir, &BoardSpaceGet(3)->coords, pos); func_8004D1EC(&obj->unk_18, &dir, &obj->unk_18, 8); HuPrcSleep(8); modelPos = &model->coords; func_800405DC(player->player_index); space = BoardSpaceGet(3); SetPlayerAnimation(-1, -1, 2); obj->unk_34 = 40.0f; obj->unk_38 = -10.0f; func_8004D3F4(pos, &space->coords, pos, 8); HuPrcSleep(16); dest = &BoardSpaceGet(4)->coords; func_8004D3F4(pos, dest, pos, 40); } while (0);
  func_8004D3F4(modelPos, dest, modelPos, 40);
  HuPrcSleep(55);
  SetPlayerOntoChain(-1, 7, 0);
  GwSystem.unk_1A = 0x46;
  if (GwCommon.boardWork[0] == 0)
  {
    func_800587EC(0x57, 0, 2);
  }
  else
  {
    func_800587BC(0x57, 0, 3, 1);
  }
  SetEventReturnFlag(1);
  SetBoardFeatureFlag(0x4F);
  EndProcess(0);
}

void func_800F75E4_MariosRainbowCastle(Object* obj, Vec3f* target, Vec3f* vel, f32 accel, f32 maxSpeed) {
    Vec3f dir;
    Vec3f pos;

    pos.x = obj->coords.x;
    pos.y = obj->unk_30;
    pos.z = obj->coords.z;
    func_800A0E80(&dir, target, &pos);
    func_8003D408(&dir);
    func_800A0F00(&dir, accel, &dir);
    func_800A0E00(vel, &dir, vel);
    if (maxSpeed <= func_800A1200(vel)) {
        func_8003D408(vel);
        func_800A0F00(vel, maxSpeed, vel);
    }
    vel->y *= 0.7f;
    func_800A0E00(&pos, vel, &pos);
    obj->coords.x = pos.x;
    obj->unk_30 = pos.y;
    obj->coords.z = pos.z;
}

void func_800F76F0_MariosRainbowCastle(void) {
    s32 i;
    Object* obj;

    obj = D_800F8430_MariosRainbowCastle;
    HuPrcSleep(8);
    for (i = 0; i < 40; i++) {
        obj->coords.x -= 30.0f;
        HuPrcVSleep();
    }
    func_800A0D50(&obj->coords, &BoardSpaceGet(3)->coords);
    EndProcess(NULL);
}

void func_800F7774_MariosRainbowCastle(void) {
    Vec3f target;
    Vec3f vel;
    Vec3f offset;
    GW_PLAYER* player;
    Object* cloud;
    Object* model;
    Vec3f* dest;
    f32 zoom;
    f32 speed;
    s32 i;
    s32 first;
    u8 chr;

    player = GetPlayerStruct(-1);
    HuPrcVSleep();
    omAddPrcObj(func_800F76F0_MariosRainbowCastle, 0x4800, 0, 0);
    cloud = MBModelCreate(0x13, NULL);
    func_800A0D50(&cloud->coords, &BoardSpaceGet(0x3D)->coords);
    func_80056E30(0);
    player->player_obj->unk_0A &= ~2;
    MBModelDispOff(player->player_obj);
    chr = player->character;
    model = MBModelCreate(chr, D_800F8318_MariosRainbowCastle[chr]);
    func_800A0D50(&model->coords, &player->player_obj->coords);
    func_800A0D50(&model->unk_18, &player->player_obj->unk_18);
    model->unk_30 = model->coords.y + 500.0f;
    model->coords.y = -500.0f;
    HuPrcSleep(8);
    MBMotionShiftSet(model, 0, 0, 8, 0);
    model->unk_34 = 0.0f;
    model->unk_38 = -3.0f;
    HuPrcSleep(24);
    model->unk_34 = 0.0f;
    model->unk_38 = 0.0f;
    model->unk_30 = 0.0f;
    func_800A0D50(&target, &BoardSpaceGet(4)->coords);
    target.y += 2000.0f;
    func_800A0D00(&vel, -20.0f, 40.0f, 0.0f);
    func_800A0D00(&offset, 0.0f, 60.0f, -60.0f);
    PlaySound(0xE5);
    for (i = 0; i < 35; i++) {
        func_800F75E4_MariosRainbowCastle(model, &target, &vel, 20.0f, 80.0f);
        func_800A0E00(&cloud->coords, &model->coords, &offset);
        cloud->coords.y += model->unk_30;
        HuPrcVSleep();
    }
    func_800726AC(1, 8);
    HuPrcSleep(8);
    func_8004A7DC();
    func_8004A7A4();
    zoom = func_8004B844();
    func_8004B838(-1.0f);
    speed = func_8004B5D0();
    func_8004B5C4(1.0f);
    func_8004A510();
    dest = &BoardSpaceGet(GetAbsSpaceIndexFromChainSpaceIndex(8, 0))->coords;
    func_8004B5DC(dest);
    HuPrcVSleep();
    func_8004A520();
    func_8004B5C4(speed);
    func_8004B838(zoom);
    SetFadeInTypeAndTime(1, 8);
    func_800A0D50(&model->coords, dest);
    model->unk_30 = 300.0f;
    model->unk_34 = 0.0f;
    model->unk_38 = -3.0f;
    func_800A0D50(&cloud->coords, &model->coords);
    func_800A0E00(&cloud->coords, &model->coords, &offset);
    cloud->coords.y += model->unk_30;
    cloud->coords.x -= 230.0f;
    cloud->coords.z -= 230.0f;
    func_800A0D50(&target, dest);
    target.z += 1000.0f;
    func_800A0D00(&vel, 40.0f, 7.0f, 40.0f);
    first = 1;
    for (i = 0; i < 35; i++) {
        if (first != 0 && model->unk_30 == 0.0f) {
            func_80058910(-1, 0);
            first = 0;
        }
        func_800F75E4_MariosRainbowCastle(cloud, &target, &vel, 4.0f, 60.0f);
        HuPrcVSleep();
    }
    MBMotionShiftSet(model, 1, 0, 3, 0);
    HuPrcSleep(10);
    do {
        HuPrcVSleep();
    } while (!(MBMotionCheck(model) & 1));
    SetPlayerOntoChain(-1, 8, 0);
    func_800A0D50(&player->player_obj->coords, &model->coords);
    MBModelKill(model);
    MBModelKill(cloud);
    MBModelDispOn(player->player_obj);
    player->player_obj->unk_0A |= 2;
    func_80056E30(1);
    EndProcess(NULL);
}

void func_800F7C04_MariosRainbowCastle(void) {
    SetNextChainAndSpace(-1, 0, 1);
}

void func_800F7C28_MariosRainbowCastle(void) {
    s16 player;
    s16 win;
    s32 coins;

    player = GetCurrentPlayerIndex();
    func_800405DC(player);
    SetPlayerAnimation(-1, -1, 2);
    if (_CheckFlag(0x42) == 0) {
        win = CreateTextWindow(0x48, 0x3C, 0x10, 3);
        LoadStringIntoWindow(win, (void*)0x239, -1, -1);
        coins = 10;
    } else {
        win = CreateTextWindow(0x41, 0x3C, 0x11, 3);
        LoadStringIntoWindow(win, (void*)0x23A, -1, -1);
        coins = 20;
    }
    func_8006E070(win, 0);
    ShowTextWindow(win);
    PlaySound(0x432);
    func_8004DBD4(win, player);
    HideTextWindow(win);
    win = coins;
    func_80055960(player, win);
    ShowPlayerCoinChange(player, win);
    HuPrcSleep(30);
    func_8003FEFC(player);
}

void func_800F7D5C_MariosRainbowCastle(void) {
    GwCommon.boardWork[31]++;
    if (_CheckFlag(0x42) == 0 && (GwCommon.boardWork[31] % 10 == 0 || _CheckFlag(0x4D) == 0)) {
        if (_CheckFlag(0x4D) != 0) {
            func_80058910(-1, 1);
        }
        SetBoardFeatureFlag(0x4D);
        func_800587EC(0x5F, 0, 1);
        return;
    }
    func_800F7C28_MariosRainbowCastle();
}

void func_800F7E2C_MariosRainbowCastle(void) {
    func_8004D2A4(-1, 8, 0);
    func_800F7D5C_MariosRainbowCastle();
    EndProcess(NULL);
}

void func_800F7E60_MariosRainbowCastle(void) {
    func_8004D2A4(-1, 8, 1);
    func_800587EC(0x65, 0, 1);
}

void func_800F7E94_MariosRainbowCastle(void) {
    GW_PLAYER* player;
    s32 i;

    for (i = 0; i < 4; i++) {
        player = GetPlayerStruct(i);
        player->group = i != GetCurrentPlayerIndex();
    }
    func_800587BC(1, 0, 5, 1);
}

void func_800F7F00_MariosRainbowCastle(void) {
    InitCameras(2);
    func_8001D4D4(1, &D_800F7F90_MariosRainbowCastle);
    func_800F6B2C_MariosRainbowCastle();
    func_800584F0(2);
    omAddPrcObj(func_800F68B0_MariosRainbowCastle, 0x1005, 0, 0);
}
