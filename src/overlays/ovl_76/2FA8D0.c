#include "common.h"
#include "spaces.h"

typedef struct testStruct2 {
s16 unk_00;
u16 unk_02;
} testStruct2;

s32 func_8005B984(s32);
s32 func_8005BAB0(s32);
void func_8005CD7C(s32, s32, s32, s32);
void func_8005B860(s32);
void func_8005C3FC(s32, s32);
void func_8005CC3C(void);
void func_800F6610_name_76(void);
void func_8005B860(s32);
void func_8005BD1C(s32);
void func_8005B860(s32);
void func_8005BD10(s32);
void func_8005B860(s32);
void func_8005B860(s32);
void func_800F67B8_name_76(void);
void func_800F67DC_name_76(void);
void func_800F6854_name_76(void);
void func_800F687C_name_76(void);
void func_800F6898_name_76(void);
void func_800F68B4_name_76(void);
void func_800F68D0_name_76(void);
void func_800F68EC_name_76(void);
void func_800F6908_name_76(void);
void func_800F6924_name_76(void);
void func_800F6948_name_76(void);

testStruct2 D_800F69E0_name_76[] = {
    { 1, 0x2D }, { 2, 0x2E }, { 3, 0x2F }, { 4, 0x30 }, { 5, 0x31 }, { 6, 0x32 }, { -1, 0xFFFF },
};
EventListEntry D_800F69FC_name_76[] = {
    { 1, 1, func_800F67B8_name_76 },
    { 3, 2, func_800F67DC_name_76 },
    { 0, 0, NULL },
};
EventListEntry D_800F6A14_name_76[] = {
    { 1, 1, func_800F6854_name_76 },
    { 0, 0, NULL },
};
EventListEntry D_800F6A24_name_76[] = {
    { 1, 1, func_800F687C_name_76 },
    { 0, 0, NULL },
};
EventListEntry D_800F6A34_name_76[] = {
    { 1, 1, func_800F6898_name_76 },
    { 0, 0, NULL },
};
EventListEntry D_800F6A44_name_76[] = {
    { 1, 1, func_800F68B4_name_76 },
    { 0, 0, NULL },
};
EventListEntry D_800F6A54_name_76[] = {
    { 1, 1, func_800F68D0_name_76 },
    { 0, 0, NULL },
};
EventListEntry D_800F6A64_name_76[] = {
    { 1, 1, func_800F68EC_name_76 },
    { 0, 0, NULL },
};
EventListEntry D_800F6A74_name_76[] = {
    { 1, 1, func_800F6908_name_76 },
    { 0, 0, NULL },
};
EventListEntry D_800F6A84_name_76[] = {
    { 1, 1, func_800F6924_name_76 },
    { 3, 2, func_800F6948_name_76 },
    { 0, 0, NULL },
};
EventTableEntry D_800F6A9C_name_76[] = {
    { 7, D_800F69FC_name_76 },
    { 0, D_800F6A14_name_76 },
    { 1, D_800F6A24_name_76 },
    { 2, D_800F6A34_name_76 },
    { 3, D_800F6A44_name_76 },
    { 4, D_800F6A54_name_76 },
    { 5, D_800F6A64_name_76 },
    { 6, D_800F6A74_name_76 },
    { 8, D_800F6A84_name_76 },
    { -1, NULL },
};

void func_800F6610_name_76(void) {
    testStruct2* temp = D_800F69E0_name_76;

    for (; temp->unk_00 >= 0; temp++) {
        if (func_8005CE48(temp->unk_02) != 0) {
            BoardSpaceTypeSet(temp->unk_00, 1);
        }
    }
}

void func_800F666C_name_76(void) {
    GW_PLAYER* player;

    omInitObjMan(0x50, 0x28);
    func_80060088();
    InitCameras(2);
    func_80023448(1);
    func_800234B8(0U, 0x78U, 0x78U, 0x78U);
    func_800234B8(1U, 0x40U, 0x40U, 0x60U);
    func_80023504(1, -100.0f, 100.0f, 300.0f);
    func_8005C3FC(0x53, 0x52);
    func_80052E84(0);
    player = GetPlayerStruct(0);
    func_8003E174(player->player_obj);
    player->player_obj->unk_0A |= 2;
    EventTableHydrate(D_800F6A9C_name_76);
    func_800F6610_name_76();
    func_8005CC3C();
    func_80060128(0x47);
}

void func_800F6744_name_76(void) {
    func_800F666C_name_76();
}

void func_800F6760_name_76(void) {
    SetPlayerOntoChain(0, 0, 0);
    func_800F666C_name_76();
}

void func_800F678C_name_76(void) {
    SetPlayerOntoChain(0, 0, 8);
    func_800F666C_name_76();
}

void func_800F67B8_name_76(void) {
    func_8005B860(-1);
    func_8005BD1C(0);
}

void func_800F67DC_name_76(void) {
    s32 temp_s0 = func_8005BAB0(0x4B7);
    s16 temp_s1 = func_8005B984(0);

    func_80070D90(temp_s0);
    if (temp_s1 == 0) {
        func_8005CD7C(3, 6, 1, 1);
        func_80058910(-1, 0);
    }
    EndProcess(NULL);
}

void func_800F6854_name_76(void) {
    GwCommon.boardWork[0] = 7;
    func_8005B860(-2);
}

void func_800F687C_name_76(void) {
    func_8005B860(0x26);
}

void func_800F6898_name_76(void) {
    func_8005B860(0x27);
}

void func_800F68B4_name_76(void) {
    func_8005B860(0x28);
}

void func_800F68D0_name_76(void) {
    func_8005B860(0x29);
}

void func_800F68EC_name_76(void) {
    func_8005B860(0x2A);
}

void func_800F6908_name_76(void) {
    func_8005B860(0x2B);
}

void func_800F6924_name_76(void) {
    func_8005B860(-1);
    func_8005BD10(0);
}

void func_800F6948_name_76(void) {
    s32 temp_s0 = func_8005BAB0(0x4B8);
    s16 temp_s1 = func_8005B984(0x4A9);

    func_80070D90(temp_s0);
    if (temp_s1 == 0) {
        func_8005CD7C(0, 8, 1, 1);
        func_80058910(-1, 0);
    }
    EndProcess(NULL);
}
