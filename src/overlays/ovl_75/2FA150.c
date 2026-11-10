#include "common.h"
#include "spaces.h"
#include "engine/process.h"

typedef struct testStruct2 {
s16 unk_00;
u16 unk_02;
} testStruct2;

void func_8005CC3C(void);
void func_8005C3FC(s32, s32);
void func_8005B860(s32);
void func_800F67BC_name_75(void);
void func_800F682C_name_75(void);
extern Object* D_800F6D60_name_75;
void func_800F6934_name_75(void);
void func_800F69F4_name_75(void);
s32 func_8005B984(s32);
s32 func_8005BAB0(s32);
void func_8005CD7C(s32, s32, s32, s32);
void func_8005BD10(s32);
void func_800F6A14_name_75(void);
void func_800F6A38_name_75(void);
void func_800F6AB0_name_75(void);
void func_800F6AD8_name_75(void);
void func_800F6AF4_name_75(void);
void func_800F6B10_name_75(void);
void func_800F6B2C_name_75(void);
void func_800F6B48_name_75(void);
void func_800F6B64_name_75(void);
void func_800F6B80_name_75(void);
void func_800F6BA4_name_75(void);

testStruct2 D_800F6C40_name_75[] = {
    { 2, 0x27 }, { 3, 0x28 }, { 4, 0x29 }, { 5, 0x2A }, { 6, 0x2B }, { 7, 0x2C }, { -1, 0xFFFF },
};
s32 D_800F6C5C_name_75[] = { 1, 0x4A };
EventListEntry D_800F6C64_name_75[] = {
    { 1, 1, func_800F6A14_name_75 },
    { 3, 2, func_800F6A38_name_75 },
    { 0, 0, NULL },
};
EventListEntry D_800F6C7C_name_75[] = {
    { 1, 1, func_800F6AB0_name_75 },
    { 0, 0, NULL },
};
EventListEntry D_800F6C8C_name_75[] = {
    { 1, 1, func_800F6AD8_name_75 },
    { 0, 0, NULL },
};
EventListEntry D_800F6C9C_name_75[] = {
    { 1, 1, func_800F6AF4_name_75 },
    { 0, 0, NULL },
};
EventListEntry D_800F6CAC_name_75[] = {
    { 1, 1, func_800F6B10_name_75 },
    { 0, 0, NULL },
};
EventListEntry D_800F6CBC_name_75[] = {
    { 1, 1, func_800F6B2C_name_75 },
    { 0, 0, NULL },
};
EventListEntry D_800F6CCC_name_75[] = {
    { 1, 1, func_800F6B48_name_75 },
    { 0, 0, NULL },
};
EventListEntry D_800F6CDC_name_75[] = {
    { 1, 1, func_800F6B64_name_75 },
    { 0, 0, NULL },
};
EventListEntry D_800F6CEC_name_75[] = {
    { 1, 1, func_800F6B80_name_75 },
    { 3, 2, func_800F6BA4_name_75 },
    { 0, 0, NULL },
};
EventTableEntry D_800F6D04_name_75[] = {
    { 8, D_800F6C64_name_75 },
    { 1, D_800F6C7C_name_75 },
    { 2, D_800F6C8C_name_75 },
    { 3, D_800F6C9C_name_75 },
    { 4, D_800F6CAC_name_75 },
    { 5, D_800F6CBC_name_75 },
    { 6, D_800F6CCC_name_75 },
    { 7, D_800F6CDC_name_75 },
    { 9, D_800F6CEC_name_75 },
    { -1, NULL },
};

void func_800F6610_name_75(void) {
    testStruct2* temp = D_800F6C40_name_75;

    for (; temp->unk_00 >= 0; temp++) {
        if (func_8005CE48(temp->unk_02) != 0) {
            BoardSpaceTypeSet(temp->unk_00, 1);
        }
    }
}

void func_800F666C_name_75(void) {
    Object* temp_v1;
    GW_PLAYER* player;

    omInitObjMan(0x50, 0x28);
    func_80060088();
    InitCameras(2);
    func_80023448(1);
    func_800234B8(0, 0x78, 0x78, 0x78);
    func_800234B8(1, 0x40, 0x40, 0x60);
    func_80023504(1, -100.0f, 100.0f, 300.0f);
    func_8005C3FC(0x52, 0x51);
    func_80052E84(0);
    player = GetPlayerStruct(0);
    func_8003E174(player->player_obj);
    player->player_obj->unk_0A |= 2;
    func_800F69F4_name_75();
    EventTableHydrate(D_800F6D04_name_75);
    func_800F6610_name_75();
    func_8005CC3C();
    func_80060128(0x46);
}

void func_800F6748_name_75(void) {
    func_800F666C_name_75();
}

void func_800F6764_name_75(void) {
    SetPlayerOntoChain(0, 0, 0);
    func_800F666C_name_75();
}

void func_800F6790_name_75(void) {
    SetPlayerOntoChain(0, 0, 8);
    func_800F666C_name_75();
}

void func_800F67BC_name_75(void) {
    Object* temp_s1 = HuPrcCurrentGet()->user_data;
    GW_PLAYER* temp_s2 = GetPlayerStruct(-1);
    Vec3f* vec = &temp_s1->unk_18;

    while (1) {
        HuPrcVSleep();
        func_800A0E80(vec, &temp_s2->player_obj->coords, &temp_s1->coords);
        func_8003D408(vec);        
    }
}

void func_800F682C_name_75(void) {
    Object* temp_s0;
    GW_PLAYER* temp_s1;

    temp_s0 = HuPrcCurrentGet()->user_data;
    temp_s1 = GetPlayerStruct(-1);
    HuPrcSleep(0x28);
    
    while (1) {
        HuPrcVSleep();
        if (GetAbsSpaceIndexFromChainSpaceIndex(temp_s1->cur_chain, temp_s1->cur_space) != 6) {
            continue;
        }
        
        MBMotionShiftSet(temp_s0, 0, 0, 6, 0);
        HuPrcSleep(0xC);
        PlaySound(0x9D);
        HuPrcSleep(0xC);
        PlaySound(0x9D);
        HuPrcSleep(0x12);
        PlaySound(0x9D);
        
        while (!(MBMotionCheck(temp_s0) & 1)) {
            HuPrcVSleep();
        }
        
        MBMotionShiftSet(temp_s0, -1, 0, 6, 2);
        HuPrcSleep(0xA);
        continue;    
    }
}

void func_800F6934_name_75(void) {
    Object* temp_v0;

    if (D_800F6D60_name_75 == NULL) {
        temp_v0 = MBModelCreate(0xC, D_800F6C5C_name_75);
        func_8003E174(temp_v0);
        D_800F6D60_name_75 = temp_v0;
        temp_v0->unk_0A |= 2;
        func_800A0D00(&temp_v0->xScale, 1.2f, 1.2f, 1.2f);
        func_800A0D50(&temp_v0->coords, &BoardSpaceGet(0)->coords);
        omAddPrcObj(func_800F67BC_name_75, 0x4800, 0, 0)->user_data = temp_v0;
        omAddPrcObj(func_800F682C_name_75, 0x4800, 0, 0)->user_data = temp_v0;
    }
}

void func_800F69F4_name_75(void) {
    D_800F6D60_name_75 = 0;
    func_800F6934_name_75();
}

void func_8005B860(s32);
void func_8005BD1C(s32);

void func_800F6A14_name_75(void) {
    func_8005B860(-1);
    func_8005BD1C(0);
}

void func_800F6A38_name_75(void) {
    s32 temp_s0 = func_8005BAB0(0x4B5);
    s16 temp_s1 = func_8005B984(0);

    func_80070D90(temp_s0);
    if (temp_s1 == 0) {
        func_8005CD7C(2, 6, 1, 0);
        func_80058910(-1, 0);
    }
    EndProcess(NULL);
}

void func_800F6AB0_name_75(void) {
    GwCommon.boardWork[0] = 6;
    func_8005B860(-2);
}

void func_800F6AD8_name_75(void) {
    func_8005B860(0x20);
}

void func_800F6AF4_name_75(void) {
    func_8005B860(0x21);
}

void func_800F6B10_name_75(void) {
    func_8005B860(0x22);
}

void func_800F6B2C_name_75(void) {
    func_8005B860(0x23);
}

void func_800F6B48_name_75(void) {
    func_8005B860(0x24);
}

void func_800F6B64_name_75(void) {
    func_8005B860(0x25);
}

void func_800F6B80_name_75(void) {
    func_8005B860(-1);
    func_8005BD10(0);
}

void func_800F6BA4_name_75(void) {
    s16 temp_s0 = func_8005BAB0(0x4B6);
    s16 temp_s1 = func_8005B984(0);

    func_80070D90(temp_s0);

    if (temp_s1 == 0) {
        func_8005CD7C(4, 5, 1, 1);
        func_80058910(-1, 0);
    }

    EndProcess(NULL);
}
