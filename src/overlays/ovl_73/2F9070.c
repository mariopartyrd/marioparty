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
void func_8005BD10(s32);
void func_8005BD1C(s32);
s32 func_8005B984(s32);
s32 func_8005BAB0(s32);
void func_8005CD7C(s32, s32, s32, s32);
void func_800F67BC_name_73(void);
void func_800F682C_name_73(s16);
void func_800F693C_name_73(void);
void func_800F699C_name_73(void);
void func_800F69C0_name_73(void);
void func_800F6A38_name_73(void);
void func_800F6A54_name_73(void);
void func_800F6A70_name_73(void);
void func_800F6A8C_name_73(void);
void func_800F6AB0_name_73(void);
void func_800F6AD4_name_73(void);

testStruct2 D_800F6BB0_name_73[] = {
    { 0, 0x15 }, { 1, 0x16 }, { 2, 0x17 }, { 3, 0x18 }, { -1, 0xFFFF },
};
/* board space per model */
s16 D_800F6BC4_name_73[] = { 4, 5, 6, 7, 8 };
EventListEntry D_800F6BD0_name_73[] = {
    { 1, 1, func_800F699C_name_73 },
    { 3, 2, func_800F69C0_name_73 },
    { 0, 0, NULL },
};
EventListEntry D_800F6BE8_name_73[] = {
    { 1, 1, func_800F6A38_name_73 },
    { 0, 0, NULL },
};
EventListEntry D_800F6BF8_name_73[] = {
    { 1, 1, func_800F6A54_name_73 },
    { 0, 0, NULL },
};
EventListEntry D_800F6C08_name_73[] = {
    { 1, 1, func_800F6A70_name_73 },
    { 0, 0, NULL },
};
EventListEntry D_800F6C18_name_73[] = {
    { 1, 1, func_800F6A8C_name_73 },
    { 0, 0, NULL },
};
EventListEntry D_800F6C28_name_73[] = {
    { 1, 1, func_800F6AB0_name_73 },
    { 3, 2, func_800F6AD4_name_73 },
    { 0, 0, NULL },
};
EventTableEntry D_800F6C40_name_73[] = {
    { 9, D_800F6BD0_name_73 },
    { 0, D_800F6BE8_name_73 },
    { 1, D_800F6BF8_name_73 },
    { 2, D_800F6C08_name_73 },
    { 3, D_800F6C18_name_73 },
    { 10, D_800F6C28_name_73 },
    { -1, NULL },
};

/* .bss */
extern Object* D_800F6C80_name_73;
extern Object* D_800F6C88_name_73[5];

void func_800F6610_name_73(void) {
    testStruct2* temp = D_800F6BB0_name_73;

    for (; temp->unk_00 >= 0; temp++) {
        if (func_8005CE48(temp->unk_02) != 0) {
            BoardSpaceTypeSet(temp->unk_00, 1);
        }
    }
}

void func_800F666C_name_73(void) {
    GW_PLAYER* player;

    omInitObjMan(0x50, 0x28);
    func_80060088();
    InitCameras(2);
    func_80023448(1);
    func_800234B8(0, 0x78, 0x78, 0x78);
    func_800234B8(1, 0x40, 0x40, 0x60);
    func_80023504(1, -100.0f, 100.0f, 300.0f);
    func_8005C3FC(0x50, 0x4F);
    func_80052E84(0);
    player = GetPlayerStruct(0);
    func_8003E174(player->player_obj);
    player->player_obj->unk_0A |= 2;
    func_800F693C_name_73();
    EventTableHydrate(D_800F6C40_name_73);
    func_800F6610_name_73();
    func_8005CC3C();
    func_80060128(0x45);
}

void func_800F6748_name_73(void) {
    func_800F666C_name_73();
}

void func_800F6764_name_73(void) {
    SetPlayerOntoChain(0, 0, 0);
    func_800F666C_name_73();
}

void func_800F6790_name_73(void) {
    SetPlayerOntoChain(0, 0, 0xB);
    func_800F666C_name_73();
}

/* user_data is the model Object: turn it to face the current player */
void func_800F67BC_name_73(void) {
    Object* obj = HuPrcCurrentGet()->user_data;
    GW_PLAYER* player = GetPlayerStruct(-1);
    Vec3f* rot = &obj->unk_18;

    while (1) {
        HuPrcVSleep();
        func_800A0E80(rot, &player->player_obj->coords, &obj->coords);
        func_8003D408(rot);
    }
}

void func_800F682C_name_73(s16 arg0) {
    Object* obj;

    if (D_800F6C88_name_73[arg0] != NULL) {
        return;
    }
    if (D_800F6C80_name_73 == NULL) {
        obj = MBModelCreate(0x6A, NULL);
        func_8003E174(obj);
        D_800F6C80_name_73 = obj;
    } else {
        obj = MBModelParamCreate(D_800F6C80_name_73);
    }
    D_800F6C88_name_73[arg0] = obj;
    obj->unk_0A |= 2;
    func_800A0D00(&obj->xScale, 0.6f, 0.6f, 0.6f);
    obj->unk_30 = 100.0f;
    func_800A0D50(&obj->coords, &BoardSpaceGet(D_800F6BC4_name_73[arg0])->coords);
    omAddPrcObj(func_800F67BC_name_73, 0x4800, 0, 0)->user_data = obj;
}

void func_800F693C_name_73(void) {
    s32 i;

    D_800F6C80_name_73 = NULL;
    for (i = 0; i < 5; i++) {
        D_800F6C88_name_73[i] = NULL;
        func_800F682C_name_73(i);
    }
}

void func_800F699C_name_73(void) {
    func_8005B860(-1);
    func_8005BD1C(0);
}

void func_800F69C0_name_73(void) {
    s16 temp_s0 = func_8005BAB0(0x4B0);
    s16 temp_s1 = func_8005B984(0x4A9);

    func_80070D90(temp_s0);
    if (temp_s1 == 0) {
        func_8005CD7C(0, 5, 1, 1);
        func_80058910(-1, 0);
    }
    EndProcess(NULL);
}

void func_800F6A38_name_73(void) {
    func_8005B860(0xE);
}

void func_800F6A54_name_73(void) {
    func_8005B860(0xF);
}

void func_800F6A70_name_73(void) {
    func_8005B860(0x10);
}

void func_800F6A8C_name_73(void) {
    func_8005B860(0x11);
    PlaySound(0x94);
}

void func_800F6AB0_name_73(void) {
    func_8005B860(-1);
    func_8005BD10(0);
}

void func_800F6AD4_name_73(void) {
    Vec3f sp10;
    GW_PLAYER* player = GetPlayerStruct(-1);
    s16 temp_s0 = func_8005BAB0(0x4B1);
    s16 temp_s1 = func_8005B984(0x4A9);

    func_80070D90(temp_s0);
    if (temp_s1 == 0) {
        func_8005CD7C(0, 6, 1, 1);
        func_8004CD84(&sp10);
        func_8003D514(&sp10, 230.0f);
        func_8004D1EC(&player->player_obj->unk_18, &sp10, &player->player_obj->unk_18, 8);
        func_80058910(-1, 0);
    }
    EndProcess(NULL);
}
