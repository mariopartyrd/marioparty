#include "common.h"
#include "spaces.h"
#include "engine/process.h"

typedef struct testStruct2 {
s16 unk_00;
u16 unk_02;
} testStruct2;

void func_8005B860(s32);
void func_8005BCC8(s16 chain, s16 space);
void func_8005BD10(s32);
void func_8005BD1C(s32);
s32 func_8005B984(s32);
s32 func_8005BAB0(s32);
void func_8005BC28(void);
void func_8005C3FC(s32, s32);
void func_8005CC3C(void);
void func_8005CD4C(s32 overlay, s16 event, s16 fade, s16 music);
void func_8005CD7C(s32, s32, s32, s32);
void func_8005CE8C(s32 flag);
void func_8005CEDC(s32 flag);
void func_800F66D4_MinigameIslandOverworldCopy(void);
void func_800F6B18_MinigameIslandOverworldCopy(void);
void func_800F6D34_MinigameIslandOverworldCopy(void);
void func_800F6E28_MinigameIslandOverworldCopy(void);
void func_800F6EDC_MinigameIslandOverworldCopy(void);
void func_800F6F10_MinigameIslandOverworldCopy(Object* obj, Vec3f* target, Vec3f* vel, f32 accel, f32 maxSpeed);
void func_800F7210_MinigameIslandOverworldCopy(void);
void func_800F72AC_MinigameIslandOverworldCopy(void);
void func_800F72E0_MinigameIslandOverworldCopy(void);
void func_800F73A8_MinigameIslandOverworldCopy(void);
void func_800F74C0_MinigameIslandOverworldCopy(void);
void func_800F7574_MinigameIslandOverworldCopy(void);
void func_800F768C_MinigameIslandOverworldCopy(void);
void func_800F7740_MinigameIslandOverworldCopy(void);
void func_800F775C_MinigameIslandOverworldCopy(void);
void func_800F7778_MinigameIslandOverworldCopy(void);
void func_800F7794_MinigameIslandOverworldCopy(void);
void func_800F77B0_MinigameIslandOverworldCopy(void);
void func_800F77D8_MinigameIslandOverworldCopy(void);
void func_800F77F4_MinigameIslandOverworldCopy(void);
void func_800F7810_MinigameIslandOverworldCopy(void);
void func_800F782C_MinigameIslandOverworldCopy(void);
void func_800F7848_MinigameIslandOverworldCopy(void);
void func_800F7864_MinigameIslandOverworldCopy(void);
void func_800F78B4_MinigameIslandOverworldCopy(void);
void func_800F78E4_MinigameIslandOverworldCopy(void);
void func_800F7900_MinigameIslandOverworldCopy(void);
void func_800F791C_MinigameIslandOverworldCopy(void);
void func_800F7938_MinigameIslandOverworldCopy(void);
void func_800F7954_MinigameIslandOverworldCopy(void);
void func_800F797C_MinigameIslandOverworldCopy(void);
void func_800F79A0_MinigameIslandOverworldCopy(void);
void func_800F7A58_MinigameIslandOverworldCopy(void);
void func_800F7A88_MinigameIslandOverworldCopy(void);
void func_800F7AA4_MinigameIslandOverworldCopy(void);
void func_800F7AC0_MinigameIslandOverworldCopy(void);
void func_800F7ADC_MinigameIslandOverworldCopy(void);
void func_800F7AF8_MinigameIslandOverworldCopy(void);
void func_800F7B14_MinigameIslandOverworldCopy(void);
void func_800F7B30_MinigameIslandOverworldCopy(void);
void func_800F7B60_MinigameIslandOverworldCopy(void);
void func_800F7B84_MinigameIslandOverworldCopy(void);
void func_800F7BFC_MinigameIslandOverworldCopy(void);
void func_800F7C9C_MinigameIslandOverworldCopy(void);
void func_800F7CC0_MinigameIslandOverworldCopy(void);
void func_800F7D78_MinigameIslandOverworldCopy(void);
void func_800F7D9C_MinigameIslandOverworldCopy(void);
void func_800F7E54_MinigameIslandOverworldCopy(void);
void func_800F7F2C_MinigameIslandOverworldCopy(void);
void func_800F7F5C_MinigameIslandOverworldCopy(void);
void func_800F7F8C_MinigameIslandOverworldCopy(void);
void func_800F7FA8_MinigameIslandOverworldCopy(void);
void func_800F7FC4_MinigameIslandOverworldCopy(void);
void func_800F7FE0_MinigameIslandOverworldCopy(void);
void func_800F7FFC_MinigameIslandOverworldCopy(void);
void func_800F8018_MinigameIslandOverworldCopy(void);
void func_800F803C_MinigameIslandOverworldCopy(void);

testStruct2 D_800F80F0_MinigameIslandOverworldCopy[] = {
    { 0x0, 0x7 }, { 0xB, 0x8 }, { 0x16, 0x9 }, { 0x1A, 0xA }, { 0x1C, 0xB }, { 0x1D, 0xC },
    { 0x1E, 0xD }, { 0x1F, 0xE }, { 0x1, 0xF }, { 0x3, 0x10 }, { 0x4, 0x11 }, { 0x5, 0x12 },
    { 0x6, 0x13 }, { 0x7, 0x14 }, { 0x9, 0x19 }, { 0xA, 0x1A }, { 0xC, 0x1B }, { 0xD, 0x1C },
    { 0xE, 0x1D }, { 0xF, 0x1E }, { 0x10, 0x1F }, { 0x11, 0x20 }, { 0x14, 0x33 }, { 0x15, 0x34 },
    { 0x17, 0x35 }, { 0x18, 0x36 }, { 0x19, 0x37 },
    { -1, 0xFFFF },
};
s32 D_800F8160_MinigameIslandOverworldCopy[] = { 1, 0x4A };
/* board spaces of the two model pairs */
s16 D_800F8168_MinigameIslandOverworldCopy[] = { 0x28, 0x26 };
s16 D_800F816C_MinigameIslandOverworldCopy[] = { 0x22, 0x20 };
EventListEntry D_800F8170_MinigameIslandOverworldCopy[] = {
    { 1, 2, func_800F72E0_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F8180_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F73A8_MinigameIslandOverworldCopy },
    { 3, 2, func_800F74C0_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F8198_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F7574_MinigameIslandOverworldCopy },
    { 3, 2, func_800F768C_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F81B0_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F7740_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F81C0_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F775C_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F81D0_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F7778_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F81E0_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F7794_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F81F0_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F77B0_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F8200_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F77D8_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F8210_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F77F4_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F8220_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F7810_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F8230_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F782C_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F8240_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F7848_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F8250_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F7864_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F8260_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F78B4_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F8270_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F78E4_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F8280_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F7900_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F8290_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F791C_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F82A0_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F7938_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F82B0_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F7954_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F82C0_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F797C_MinigameIslandOverworldCopy },
    { 3, 2, func_800F79A0_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F82D8_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F7A58_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F82E8_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F7A88_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F82F8_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F7AA4_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F8308_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F7AC0_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F8318_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F7ADC_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F8328_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F7AF8_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F8338_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F7B14_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F8348_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F7B30_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F8358_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F7B60_MinigameIslandOverworldCopy },
    { 3, 2, func_800F7B84_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F8370_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F7BFC_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F8380_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F7C9C_MinigameIslandOverworldCopy },
    { 3, 2, func_800F7CC0_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F8398_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F7D78_MinigameIslandOverworldCopy },
    { 3, 2, func_800F7D9C_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F83B0_MinigameIslandOverworldCopy[] = {
    { 1, 2, func_800F7E54_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F83C0_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F7F2C_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F83D0_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F7F5C_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F83E0_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F7F8C_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F83F0_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F7FA8_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F8400_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F7FC4_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F8410_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F7FE0_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F8420_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F7FFC_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventListEntry D_800F8430_MinigameIslandOverworldCopy[] = {
    { 1, 1, func_800F8018_MinigameIslandOverworldCopy },
    { 3, 2, func_800F803C_MinigameIslandOverworldCopy },
    { 0, 0, NULL },
};
EventTableEntry D_800F8448_MinigameIslandOverworldCopy[] = {
    { 0x29, D_800F8170_MinigameIslandOverworldCopy },
    { 0x0, D_800F81B0_MinigameIslandOverworldCopy },
    { 0xB, D_800F81C0_MinigameIslandOverworldCopy },
    { 0x16, D_800F81D0_MinigameIslandOverworldCopy },
    { 0x1A, D_800F81E0_MinigameIslandOverworldCopy },
    { 0x1B, D_800F81F0_MinigameIslandOverworldCopy },
    { 0x1C, D_800F8200_MinigameIslandOverworldCopy },
    { 0x1D, D_800F8210_MinigameIslandOverworldCopy },
    { 0x1E, D_800F8220_MinigameIslandOverworldCopy },
    { 0x1F, D_800F8230_MinigameIslandOverworldCopy },
    { 0x1, D_800F8240_MinigameIslandOverworldCopy },
    { 0x2, D_800F8250_MinigameIslandOverworldCopy },
    { 0x3, D_800F8260_MinigameIslandOverworldCopy },
    { 0x4, D_800F8270_MinigameIslandOverworldCopy },
    { 0x5, D_800F8280_MinigameIslandOverworldCopy },
    { 0x6, D_800F8290_MinigameIslandOverworldCopy },
    { 0x7, D_800F82A0_MinigameIslandOverworldCopy },
    { 0x8, D_800F82B0_MinigameIslandOverworldCopy },
    { 0x2A, D_800F82C0_MinigameIslandOverworldCopy },
    { 0x9, D_800F82D8_MinigameIslandOverworldCopy },
    { 0xA, D_800F82E8_MinigameIslandOverworldCopy },
    { 0xC, D_800F82F8_MinigameIslandOverworldCopy },
    { 0xD, D_800F8308_MinigameIslandOverworldCopy },
    { 0xE, D_800F8318_MinigameIslandOverworldCopy },
    { 0xF, D_800F8328_MinigameIslandOverworldCopy },
    { 0x10, D_800F8338_MinigameIslandOverworldCopy },
    { 0x11, D_800F8348_MinigameIslandOverworldCopy },
    { 0x2B, D_800F8358_MinigameIslandOverworldCopy },
    { 0x12, D_800F8370_MinigameIslandOverworldCopy },
    { 0x2C, D_800F8380_MinigameIslandOverworldCopy },
    { 0x2F, D_800F8398_MinigameIslandOverworldCopy },
    { 0x13, D_800F83B0_MinigameIslandOverworldCopy },
    { 0x14, D_800F83E0_MinigameIslandOverworldCopy },
    { 0x15, D_800F83F0_MinigameIslandOverworldCopy },
    { 0x17, D_800F8400_MinigameIslandOverworldCopy },
    { 0x18, D_800F8410_MinigameIslandOverworldCopy },
    { 0x19, D_800F8420_MinigameIslandOverworldCopy },
    { 0x2E, D_800F8430_MinigameIslandOverworldCopy },
    { 0x2D, D_800F83C0_MinigameIslandOverworldCopy },
    { 0x30, D_800F83D0_MinigameIslandOverworldCopy },
    { 0x23, D_800F8198_MinigameIslandOverworldCopy },
    { 0x24, D_800F8180_MinigameIslandOverworldCopy },
    { -1, NULL },
};

/* .bss */
extern Object* D_800F85A0_MinigameIslandOverworldCopy;
extern Object* D_800F85A4_MinigameIslandOverworldCopy;
extern Object* D_800F85A8_MinigameIslandOverworldCopy[2];
extern Object* D_800F85B0_MinigameIslandOverworldCopy;
extern Object* D_800F85B4_MinigameIslandOverworldCopy[2];
extern Object* D_800F85BC_MinigameIslandOverworldCopy;
extern Object* D_800F85C0_MinigameIslandOverworldCopy;
extern Object* D_800F85C4_MinigameIslandOverworldCopy;
extern Object* D_800F85C8_MinigameIslandOverworldCopy;

void func_800F6610_MinigameIslandOverworldCopy(void) {
    testStruct2* temp = D_800F80F0_MinigameIslandOverworldCopy;

    for (; temp->unk_00 >= 0; temp++) {
        if (func_8005CE48(temp->unk_02) != 0) {
            BoardSpaceTypeSet(temp->unk_00, 1);
        }
    }
}

void func_800F666C_MinigameIslandOverworldCopy(void) {
    omInitObjMan(0xA, 0);
    omOvlGotoEx(0x71, 0, 0x92);
}

void func_800F669C_MinigameIslandOverworldCopy(void) {
    omInitObjMan(0xA, 0);
    SetPlayerOntoChain(0, 1, 0);
    omOvlReturnEx(1);
}

void func_800F66D4_MinigameIslandOverworldCopy(void) {
    GW_PLAYER* player;

    omInitObjMan(0x50, 0x28);
    func_80060088();
    InitCameras(2);
    func_80023448(1);
    func_800234B8(0, 0x78, 0x78, 0x78);
    func_800234B8(1, 0x40, 0x40, 0x60);
    func_80023504(1, -100.0f, 100.0f, 300.0f);
    func_8005C3FC(0x4F, 0x4E);
    func_80052E84(0);
    player = GetPlayerStruct(0);
    func_8003E174(player->player_obj);
    player->player_obj->unk_0A |= 2;
    func_800F6B18_MinigameIslandOverworldCopy();
    func_800F6D34_MinigameIslandOverworldCopy();
    func_800F6E28_MinigameIslandOverworldCopy();
    func_800F6EDC_MinigameIslandOverworldCopy();
    func_800F7210_MinigameIslandOverworldCopy();
    func_800F72AC_MinigameIslandOverworldCopy();
    EventTableHydrate(D_800F8448_MinigameIslandOverworldCopy);
    func_800F6610_MinigameIslandOverworldCopy();
    func_8005CC3C();
    if (func_8005CE48(0x32) != 0) {
        func_80060128(0x48);
    } else if (func_8005CE48(0xF) != 0) {
        func_80060128(0x44);
    } else if (func_8005CE48(0xA) != 0) {
        func_80060128(0x43);
    } else {
        func_80060128(0x42);
    }
}

void func_800F6814_MinigameIslandOverworldCopy(void) {
    func_800F66D4_MinigameIslandOverworldCopy();
}

void func_800F6830_MinigameIslandOverworldCopy(void) {
    SetPlayerOntoChain(0, 2, 6);
    func_800F66D4_MinigameIslandOverworldCopy();
}

void func_800F685C_MinigameIslandOverworldCopy(void) {
    SetPlayerOntoChain(0, 3, 0);
    func_800F66D4_MinigameIslandOverworldCopy();
}

void func_800F6888_MinigameIslandOverworldCopy(void) {
    SetPlayerOntoChain(0, 3, 2);
    func_800F66D4_MinigameIslandOverworldCopy();
}

void func_800F68B4_MinigameIslandOverworldCopy(void) {
    SetPlayerOntoChain(0, 5, 0);
    func_800F66D4_MinigameIslandOverworldCopy();
}

/* user_data is the model Object: turn it to face the current player */
void func_800F68E0_MinigameIslandOverworldCopy(void) {
    Object* obj = HuPrcCurrentGet()->user_data;
    GW_PLAYER* player = GetPlayerStruct(-1);
    Vec3f* rot = &obj->unk_18;

    while (1) {
        HuPrcVSleep();
        func_800A0E80(rot, &player->player_obj->coords, &obj->coords);
        func_8003D408(rot);
    }
}

void func_800F6950_MinigameIslandOverworldCopy(void) {
    Object* obj;
    GW_PLAYER* player;

    obj = HuPrcCurrentGet()->user_data;
    player = GetPlayerStruct(-1);
    HuPrcSleep(0x28);

    while (1) {
        HuPrcVSleep();
        if (GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain, player->cur_space) != 1) {
            continue;
        }

        MBMotionShiftSet(obj, 0, 0, 6, 0);
        HuPrcSleep(0xC);
        PlaySound(0x9D);
        HuPrcSleep(0xC);
        PlaySound(0x9D);
        HuPrcSleep(0x12);
        PlaySound(0x9D);

        while (!(MBMotionCheck(obj) & 1)) {
            HuPrcVSleep();
        }

        MBMotionShiftSet(obj, -1, 0, 6, 2);
        HuPrcSleep(0xA);
        continue;
    }
}

void func_800F6A58_MinigameIslandOverworldCopy(void) {
    Object* obj;

    if (D_800F85A0_MinigameIslandOverworldCopy == NULL) {
        obj = MBModelCreate(0xC, D_800F8160_MinigameIslandOverworldCopy);
        func_8003E174(obj);
        D_800F85A0_MinigameIslandOverworldCopy = obj;
        obj->unk_0A |= 2;
        func_800A0D00(&obj->xScale, 0.8f, 0.8f, 0.8f);
        func_800A0D50(&obj->coords, &BoardSpaceGet(0x25)->coords);
        omAddPrcObj(func_800F68E0_MinigameIslandOverworldCopy, 0x4800, 0, 0)->user_data = obj;
        omAddPrcObj(func_800F6950_MinigameIslandOverworldCopy, 0x4800, 0, 0)->user_data = obj;
    }
}

void func_800F6B18_MinigameIslandOverworldCopy(void) {
    D_800F85A0_MinigameIslandOverworldCopy = NULL;
    func_800F6A58_MinigameIslandOverworldCopy();
}

void func_800F6B38_MinigameIslandOverworldCopy(void) {
    Object* obj;
    GW_PLAYER* player;
    s16 space;

    obj = HuPrcCurrentGet()->user_data;
    player = GetPlayerStruct(-1);
    HuPrcSleep(0x28);

    while (1) {
        HuPrcVSleep();
        space = GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain, player->cur_space);
        if (((space == 5) | (space == 0x18)) == 0) {
            continue;
        }
        do {
            HuPrcVSleep();
        } while (!((obj->unk_30 += 5.0f) >= 200.0f));
        HuPrcSleep(0xA);
        obj->unk_34 = 0.0f;
        obj->unk_38 = -10.0f;
        do {
            HuPrcVSleep();
        } while (!(obj->unk_30 <= 0.0f));
        PlaySound(0xAA);
        HuPrcSleep(0x3C);
    }
}

void func_800F6C50_MinigameIslandOverworldCopy(s16 arg0) {
    Object* obj;

    if (D_800F85A8_MinigameIslandOverworldCopy[arg0] != NULL) {
        return;
    }
    if (D_800F85A4_MinigameIslandOverworldCopy == NULL) {
        obj = MBModelCreate(0xD, NULL);
        func_8003E174(obj);
        D_800F85A4_MinigameIslandOverworldCopy = obj;
    } else {
        obj = MBModelParamCreate(D_800F85A4_MinigameIslandOverworldCopy);
    }
    obj->unk_0A |= 2;
    D_800F85A8_MinigameIslandOverworldCopy[arg0] = obj;
    func_800A0D50(&obj->coords, &BoardSpaceGet(D_800F8168_MinigameIslandOverworldCopy[arg0])->coords);
    omAddPrcObj(func_800F6B38_MinigameIslandOverworldCopy, 0x4800, 0, 0)->user_data = obj;
}

void func_800F6D34_MinigameIslandOverworldCopy(void) {
    D_800F85A4_MinigameIslandOverworldCopy = NULL;
    func_800F6C50_MinigameIslandOverworldCopy(0);
    func_800F6C50_MinigameIslandOverworldCopy(1);
}

void func_800F6D60_MinigameIslandOverworldCopy(s16 arg0) {
    Object* obj;

    if (D_800F85B4_MinigameIslandOverworldCopy[arg0] != NULL) {
        return;
    }
    if (D_800F85B0_MinigameIslandOverworldCopy == NULL) {
        obj = MBModelCreate(0x86, NULL);
        func_8003E174(obj);
        D_800F85B0_MinigameIslandOverworldCopy = obj;
    } else {
        obj = MBModelParamCreate(D_800F85B0_MinigameIslandOverworldCopy);
    }
    obj->unk_0A |= 2;
    D_800F85B4_MinigameIslandOverworldCopy[arg0] = obj;
    func_800A0D50(&obj->coords, &BoardSpaceGet(D_800F816C_MinigameIslandOverworldCopy[arg0])->coords);
}

void func_800F6E28_MinigameIslandOverworldCopy(void) {
    D_800F85B0_MinigameIslandOverworldCopy = NULL;
    if (func_8005CE48(0x18) == 0) {
        func_800F6D60_MinigameIslandOverworldCopy(0);
    }
    if (func_8005CE48(0x32) == 0) {
        func_800F6D60_MinigameIslandOverworldCopy(1);
    }
}

void func_800F6E74_MinigameIslandOverworldCopy(void) {
    Object* obj;

    if (D_800F85BC_MinigameIslandOverworldCopy == NULL) {
        obj = MBModelCreate(0x8A, NULL);
        func_8003E174(obj);
        D_800F85BC_MinigameIslandOverworldCopy = obj;
        obj->unk_0A |= 2;
        func_800A0D50(&obj->coords, &BoardSpaceGet(0x21)->coords);
    }
}

void func_800F6EDC_MinigameIslandOverworldCopy(void) {
    D_800F85BC_MinigameIslandOverworldCopy = NULL;
    if (func_8005CE48(0x20) != 0) {
        func_800F6E74_MinigameIslandOverworldCopy();
    }
}

/* steer obj towards target: vel += accel * dir, clamped to maxSpeed; obj->coords += vel */
void func_800F6F10_MinigameIslandOverworldCopy(Object* obj, Vec3f* target, Vec3f* vel, f32 accel, f32 maxSpeed) {
    Vec3f sp10;

    func_800A0E80(&sp10, target, &obj->coords);
    func_8003D408(&sp10);
    func_800A0F00(&sp10, accel, &sp10);
    func_800A0E00(vel, &sp10, vel);
    if (func_800A1200(vel) >= maxSpeed) {
        func_8003D408(vel);
        func_800A0F00(vel, maxSpeed, vel);
    }
    func_800A0E00(&obj->coords, vel, &obj->coords);
}

void func_800F6FD4_MinigameIslandOverworldCopy(void) {
    Vec3f vel;
    Object* obj = D_800F85C0_MinigameIslandOverworldCopy;
    Object* obj2 = D_800F85C4_MinigameIslandOverworldCopy;
    BoardSpace* space = BoardSpaceGet(0x27);
    GW_PLAYER* player = GetPlayerStruct(-1);

    func_800A0D00(&vel, 0.0f, 0.0f, 0.0f);
    while (1) {
        HuPrcVSleep();
        func_800F6F10_MinigameIslandOverworldCopy(obj, &space->coords, &vel, 0.1f, 2.0f);
        func_800A0D50(&obj2->coords, &obj->coords);
        func_800A0E80(&obj->unk_18, &player->player_obj->coords, &obj->coords);
        func_8003D408(&obj->unk_18);
        func_800A0D50(&obj2->unk_18, &obj->unk_18);
    }
}

void func_800F70CC_MinigameIslandOverworldCopy(void) {
    Object* obj;

    if (D_800F85C0_MinigameIslandOverworldCopy == NULL) {
        obj = MBModelCreate(0x8C, NULL);
        func_8003E174(obj);
        D_800F85C0_MinigameIslandOverworldCopy = obj;
        obj->unk_0A |= 2;
        func_800A0D50(&obj->coords, &BoardSpaceGet(0x27)->coords);
        obj->coords.x += 30.0f;
        obj->coords.y += 3.0f;
        obj->coords.z += 10.0f;
        obj = MBModelCreate(0x85, NULL);
        func_8003E174(obj);
        D_800F85C4_MinigameIslandOverworldCopy = obj;
        obj->unk_0A |= 2;
        func_800A0D50(&obj->coords, &BoardSpaceGet(0x27)->coords);
        obj->coords.x += 30.0f;
        obj->coords.y += 3.0f;
        obj->coords.z += 10.0f;
        omAddPrcObj(func_800F6FD4_MinigameIslandOverworldCopy, 0x4800, 0, 0);
    }
}

void func_800F7210_MinigameIslandOverworldCopy(void) {
    D_800F85C0_MinigameIslandOverworldCopy = NULL;
    func_800F70CC_MinigameIslandOverworldCopy();
}

void func_800F7230_MinigameIslandOverworldCopy(void) {
    Object* obj;

    if (D_800F85C8_MinigameIslandOverworldCopy == NULL) {
        obj = MBModelCreate(0x12, NULL);
        func_8003E174(obj);
        D_800F85C8_MinigameIslandOverworldCopy = obj;
        obj->unk_0A |= 2;
        func_800A0D50(&obj->coords, &BoardSpaceGet(func_8005CE48(2) != 0 ? 0x24 : 0x23)->coords);
    }
}

void func_800F72AC_MinigameIslandOverworldCopy(void) {
    D_800F85C8_MinigameIslandOverworldCopy = NULL;
    if (func_8005CE48(0x38) != 0) {
        func_800F7230_MinigameIslandOverworldCopy();
    }
}

void func_800F72E0_MinigameIslandOverworldCopy(void) {
    Object* obj;
    BoardSpace* space;
    Process* proc;
    Vec3f* pos;

    GwCommon.boardWork[0] = 0;
    func_8005B860(-2);
    func_8005BD1C(0);
    if (func_8005CE48(0x38) != 0) {
        if (func_8005CE48(2) == 0) {
            func_8005CE8C(2);
            obj = D_800F85C8_MinigameIslandOverworldCopy;
            space = BoardSpaceGet(0x24);
            proc = HuPrcCurrentGet();
            pos = &obj->coords;
            HuPrcChildLink(proc, func_8004D3F4(pos, &space->coords, pos, 0x1E));
            HuPrcChildWatch();
        }
        func_8005BCC8(6, 0);
    }
    EndProcess(NULL);
}

void func_800F73A8_MinigameIslandOverworldCopy(void) {
    func_8005B860(-1);
    func_8005BD10(0);
    func_8005BD1C(0);
    func_8005BCC8(1, 0);
}

void func_800F73E0_MinigameIslandOverworldCopy(void) {
    Vec3f sp10;
    GW_PLAYER* player = GetPlayerStruct(-1);
    Object* obj = D_800F85C8_MinigameIslandOverworldCopy;
    BoardSpace* space;
    Process* proc;
    Process* child;
    Vec3f* dest;

    SetPlayerAnimation(-1, -1, 2);
    func_8004CD84(&sp10);
    func_8004D1EC(&player->player_obj->unk_18, &sp10, &player->player_obj->unk_18, 8);
    space = BoardSpaceGet(0x23);
    proc = HuPrcCurrentGet();
    child = func_8004D648(&player->player_obj->coords, dest = &space->coords, &player->player_obj->coords, 20.0f);
    func_8004D648(&obj->coords, dest, &obj->coords, 20.0f);
    HuPrcChildLink(proc, child);
    HuPrcChildWatch();
    EndProcess(NULL);
}

void func_800F74C0_MinigameIslandOverworldCopy(void) {
    s16 temp_s0 = func_8005BAB0(0x4BA);
    s16 temp_s1 = func_8005B984(0x4B9);
    Process* proc;

    func_80070D90(temp_s0);
    if (temp_s1 == 0) {
        proc = HuPrcCurrentGet();
        HuPrcChildLink(proc, omAddPrcObj(func_800F73E0_MinigameIslandOverworldCopy, 0x4800, 0, 0));
        HuPrcChildWatch();
        func_8005CEDC(2);
        SetPlayerOntoChain(-1, 7, 0);
        SetEventReturnFlag(1);
    }
    EndProcess(NULL);
}

void func_800F7574_MinigameIslandOverworldCopy(void) {
    func_8005B860(-1);
    func_8005BD10(0);
    func_8005BD1C(0);
    func_8005BCC8(5, 1);
}

void func_800F75AC_MinigameIslandOverworldCopy(void) {
    Vec3f sp10;
    GW_PLAYER* player = GetPlayerStruct(-1);
    Object* obj = D_800F85C8_MinigameIslandOverworldCopy;
    BoardSpace* space;
    Process* proc;
    Process* child;
    Vec3f* dest;

    SetPlayerAnimation(-1, -1, 2);
    func_8004CD84(&sp10);
    func_8004D1EC(&player->player_obj->unk_18, &sp10, &player->player_obj->unk_18, 8);
    space = BoardSpaceGet(0x24);
    proc = HuPrcCurrentGet();
    child = func_8004D648(&player->player_obj->coords, dest = &space->coords, &player->player_obj->coords, 20.0f);
    func_8004D648(&obj->coords, dest, &obj->coords, 20.0f);
    HuPrcChildLink(proc, child);
    HuPrcChildWatch();
    EndProcess(NULL);
}

void func_800F768C_MinigameIslandOverworldCopy(void) {
    s16 temp_s0 = func_8005BAB0(0x4BB);
    s16 temp_s1 = func_8005B984(0x4B9);
    Process* proc;

    func_80070D90(temp_s0);
    if (temp_s1 == 0) {
        proc = HuPrcCurrentGet();
        HuPrcChildLink(proc, omAddPrcObj(func_800F75AC_MinigameIslandOverworldCopy, 0x4800, 0, 0));
        HuPrcChildWatch();
        func_8005CE8C(2);
        SetPlayerOntoChain(-1, 6, 0);
        SetEventReturnFlag(1);
    }
    EndProcess(NULL);
}

void func_800F7740_MinigameIslandOverworldCopy(void) {
    func_8005B860(0);
}

void func_800F775C_MinigameIslandOverworldCopy(void) {
    func_8005B860(1);
}

void func_800F7778_MinigameIslandOverworldCopy(void) {
    func_8005B860(2);
}

void func_800F7794_MinigameIslandOverworldCopy(void) {
    func_8005B860(3);
}


void func_800F77B0_MinigameIslandOverworldCopy(void) {
    GwCommon.boardWork[0] = 1;
    func_8005B860(-2);
}

void func_800F77D8_MinigameIslandOverworldCopy(void) {
    func_8005B860(4);
}

void func_800F77F4_MinigameIslandOverworldCopy(void) {
    func_8005B860(5);
}

void func_800F7810_MinigameIslandOverworldCopy(void) {
    func_8005B860(6);
}

void func_800F782C_MinigameIslandOverworldCopy(void) {
    func_8005B860(7);
}

void func_800F7848_MinigameIslandOverworldCopy(void) {
    func_8005B860(8);
}


void func_800F7864_MinigameIslandOverworldCopy(void) {
    GwCommon.boardWork[0] = 2;
    func_8005B860(-2);
    func_8005BD10(0);
    func_8005BCC8(2, 0);
    func_8005BCC8(0, 0);
    SetEventReturnFlag(2);
}

void func_800F78B4_MinigameIslandOverworldCopy(void) {
    func_8005B860(9);
    func_8005BD1C(0);
    func_8005BCC8(1, 0xB);
}

void func_800F78E4_MinigameIslandOverworldCopy(void) {
    func_8005B860(0xA);
}

void func_800F7900_MinigameIslandOverworldCopy(void) {
    func_8005B860(0xB);
}

void func_800F791C_MinigameIslandOverworldCopy(void) {
    func_8005B860(0xC);
}

void func_800F7938_MinigameIslandOverworldCopy(void) {
    func_8005B860(0xD);
}


void func_800F7954_MinigameIslandOverworldCopy(void) {
    GwCommon.boardWork[0] = 3;
    func_8005B860(-2);
}

void func_800F797C_MinigameIslandOverworldCopy(void) {
    func_8005B860(-1);
    func_8005BD10(0);
}

void func_800F79A0_MinigameIslandOverworldCopy(void) {
    Vec3f sp10;
    GW_PLAYER* player = GetPlayerStruct(-1);
    s16 temp_s0 = func_8005BAB0(0x4AF);
    s16 temp_s1 = func_8005B984(0);

    func_80070D90(temp_s0);
    if (temp_s1 == 0) {
        func_8005CD7C(1, 5, 1, 1);
        func_8004CD84(&sp10);
        func_8003D514(&sp10, 180.0f);
        func_8004D1EC(&player->player_obj->unk_18, &sp10, &player->player_obj->unk_18, 8);
        func_80058910(-1, 0);
    }
    EndProcess(NULL);
}

void func_800F7A58_MinigameIslandOverworldCopy(void) {
    func_8005B860(0x12);
    func_8005BD1C(0);
    func_8005BCC8(1, 0xB);
}

void func_800F7A88_MinigameIslandOverworldCopy(void) {
    func_8005B860(0x13);
}

void func_800F7AA4_MinigameIslandOverworldCopy(void) {
    func_8005B860(0x14);
}

void func_800F7AC0_MinigameIslandOverworldCopy(void) {
    func_8005B860(0x15);
}

void func_800F7ADC_MinigameIslandOverworldCopy(void) {
    func_8005B860(0x16);
}

void func_800F7AF8_MinigameIslandOverworldCopy(void) {
    func_8005B860(0x17);
}

void func_800F7B14_MinigameIslandOverworldCopy(void) {
    func_8005B860(0x18);
}


void func_800F7B30_MinigameIslandOverworldCopy(void) {
    func_8005B860(0x19);
    func_8005BD10(0);
    func_8005BCC8(3, 1);
}

void func_800F7B60_MinigameIslandOverworldCopy(void) {
    func_8005B860(-1);
    func_8005BD1C(0);
}

void func_800F7B84_MinigameIslandOverworldCopy(void) {
    s16 temp_s0 = func_8005BAB0(0x4AF);
    s16 temp_s1 = func_8005B984(0);

    func_80070D90(temp_s0);
    if (temp_s1 == 0) {
        func_8005CD7C(1, 6, 1, 1);
        func_80058910(-1, 0);
    }
    EndProcess(NULL);
}

void func_800F7BFC_MinigameIslandOverworldCopy(void) {
    s16 count = 0;

    GwCommon.boardWork[0] = 4;
    func_8005B860(-2);
    if (func_8005CE48(0x18) == 0) {
        func_8005BD1C(0);
    } else {
        count++;
    }
    if (func_8005CE48(0x20) != 0) {
        func_8005BCC8(0, 7);
        count++;
    }
    if (func_8005CE48(0x32) != 0) {
        func_8005BCC8(4, 0);
        count++;
    }
    if (count >= 2) {
        SetEventReturnFlag(2);
    }
}

void func_800F7C9C_MinigameIslandOverworldCopy(void) {
    func_8005B860(-1);
    func_8005BD10(0);
}

void func_800F7CC0_MinigameIslandOverworldCopy(void) {
    Vec3f sp10;
    GW_PLAYER* player = GetPlayerStruct(-1);
    s16 temp_s0 = func_8005BAB0(0x4B2);
    s16 temp_s1 = func_8005B984(0);

    func_80070D90(temp_s0);
    if (temp_s1 == 0) {
        func_8005CD7C(2, 5, 1, 1);
        func_8004CD84(&sp10);
        func_8003D514(&sp10, 180.0f);
        func_8004D1EC(&player->player_obj->unk_18, &sp10, &player->player_obj->unk_18, 8);
        func_80058910(-1, 0);
    }
    EndProcess(NULL);
}

void func_800F7D78_MinigameIslandOverworldCopy(void) {
    func_8005B860(-1);
    func_8005BD1C(0);
}

void func_800F7D9C_MinigameIslandOverworldCopy(void) {
    Vec3f sp10;
    GW_PLAYER* player = GetPlayerStruct(-1);
    s16 temp_s0 = func_8005BAB0(0x4B2);
    s16 temp_s1 = func_8005B984(0);

    func_80070D90(temp_s0);
    if (temp_s1 == 0) {
        func_8005CD7C(4, 6, 1, 1);
        func_8004CD84(&sp10);
        func_8003D514(&sp10, 180.0f);
        func_8004D1EC(&player->player_obj->unk_18, &sp10, &player->player_obj->unk_18, 8);
        func_80058910(-1, 0);
    }
    EndProcess(NULL);
}

void func_800F7E54_MinigameIslandOverworldCopy(void) {
    Object* obj;
    BoardSpace* space;
    Process* proc;
    Vec3f* pos;

    GwCommon.boardWork[0] = 5;
    func_8005B860(-2);
    func_8005BCC8(4, 1);
    if (func_8005CE48(0x38) != 0) {
        if (func_8005CE48(2) != 0) {
            func_8005CEDC(2);
            obj = D_800F85C8_MinigameIslandOverworldCopy;
            space = BoardSpaceGet(0x23);
            proc = HuPrcCurrentGet();
            pos = &obj->coords;
            HuPrcChildLink(proc, func_8004D3F4(pos, &space->coords, pos, 0x1E));
            HuPrcChildWatch();
        }
        func_8005BCC8(7, 0);
    }
    SetEventReturnFlag(2);
    EndProcess(NULL);
}

void func_800F7F2C_MinigameIslandOverworldCopy(void) {
    func_8005B860(-1);
    func_8005BD10(0);
    func_8005BCC8(5, 1);
}

void func_800F7F5C_MinigameIslandOverworldCopy(void) {
    func_8005B860(-1);
    func_8005BD1C(0);
    func_8005BCC8(3, 1);
}

void func_800F7F8C_MinigameIslandOverworldCopy(void) {
    func_8005B860(0x2C);
}

void func_800F7FA8_MinigameIslandOverworldCopy(void) {
    func_8005B860(0x2D);
}

void func_800F7FC4_MinigameIslandOverworldCopy(void) {
    func_8005B860(0x2E);
}

void func_800F7FE0_MinigameIslandOverworldCopy(void) {
    func_8005B860(0x2F);
}

void func_800F7FFC_MinigameIslandOverworldCopy(void) {
    func_8005B860(0x30);
}


void func_800F8018_MinigameIslandOverworldCopy(void) {
    func_8005B860(-1);
    func_8005BD10(0);
}

void func_800F803C_MinigameIslandOverworldCopy(void) {
    s16 temp_s0 = func_8005BAB0(0x4AE);
    s16 temp_s1 = func_8005B984(0);

    func_80070D90(temp_s0);
    if (temp_s1 == 0) {
        func_8005CD4C(0x77, 0, 1, 1);
        func_8005BC28();
    }
    EndProcess(NULL);
}
