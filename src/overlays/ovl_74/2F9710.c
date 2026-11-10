#include "common.h"
#include "spaces.h"
#include "engine/process.h"

typedef struct testStruct2 {
s16 unk_00;
u16 unk_02;
} testStruct2;

void func_8005B860(s32);
void func_8005C3FC(s32, s32);
void func_8005CC3C(void);
void func_800F6610_name_74(void);
void func_800F68E8_name_74(void);
void func_800F6988_name_74(void);
void func_800F6C88_name_74(void);
void func_800F666C_name_74(void);
void func_800F683C_name_74(void);
void func_800F67CC_name_74(void);
extern Object* D_800F7020_name_74;
extern Object* D_800F7024_name_74;
void func_800F6908_name_74(void);
void func_8005BD10(s32);
void func_8005BD1C(s32);
s32 func_8005B984(s32);
s32 func_8005BAB0(s32);
void func_8005CD7C(s32, s32, s32, s32);
void func_800F69A8_name_74(void);
void func_800F6B7C_name_74(s16);
void func_800F6CE8_name_74(void);
void func_800F6D0C_name_74(void);
void func_800F6D84_name_74(void);
void func_800F6DA0_name_74(void);
void func_800F6DC4_name_74(void);
void func_800F6DE0_name_74(void);
void func_800F6E04_name_74(void);
void func_800F6E20_name_74(void);
void func_800F6E3C_name_74(void);
void func_800F6E60_name_74(void);

testStruct2 D_800F6F00_name_74[] = {
    { 4, 0x21 }, { 5, 0x22 }, { 6, 0x23 }, { 7, 0x24 }, { 8, 0x25 }, { 9, 0x26 }, { -1, 0xFFFF },
};
/* board space per model */
s16 D_800F6F1C_name_74[] = { 3, 2 };
s16 D_800F6F20_name_74[] = { 10, 14, 20 };
f32 D_800F6F28_name_74[] = { 40.0f, 42.0f, 40.0f };
f32 D_800F6F34_name_74[] = { -8.0f, -6.0f, -4.0f };
EventListEntry D_800F6F40_name_74[] = {
    { 1, 1, func_800F6CE8_name_74 },
    { 3, 2, func_800F6D0C_name_74 },
    { 0, 0, NULL },
};
EventListEntry D_800F6F58_name_74[] = {
    { 1, 1, func_800F6D84_name_74 },
    { 0, 0, NULL },
};
EventListEntry D_800F6F68_name_74[] = {
    { 1, 1, func_800F6DA0_name_74 },
    { 0, 0, NULL },
};
EventListEntry D_800F6F78_name_74[] = {
    { 1, 1, func_800F6DC4_name_74 },
    { 0, 0, NULL },
};
EventListEntry D_800F6F88_name_74[] = {
    { 1, 1, func_800F6DE0_name_74 },
    { 0, 0, NULL },
};
EventListEntry D_800F6F98_name_74[] = {
    { 1, 1, func_800F6E04_name_74 },
    { 0, 0, NULL },
};
EventListEntry D_800F6FA8_name_74[] = {
    { 1, 1, func_800F6E20_name_74 },
    { 0, 0, NULL },
};
EventListEntry D_800F6FB8_name_74[] = {
    { 1, 1, func_800F6E3C_name_74 },
    { 3, 2, func_800F6E60_name_74 },
    { 0, 0, NULL },
};
EventTableEntry D_800F6FD0_name_74[] = {
    { 10, D_800F6F40_name_74 },
    { 4, D_800F6F58_name_74 },
    { 5, D_800F6F68_name_74 },
    { 6, D_800F6F78_name_74 },
    { 7, D_800F6F88_name_74 },
    { 8, D_800F6F98_name_74 },
    { 9, D_800F6FA8_name_74 },
    { 11, D_800F6FB8_name_74 },
    { -1, NULL },
};

/* .bss */
extern Object* D_800F7028_name_74;
extern Object* D_800F702C_name_74[2];

void func_800F6610_name_74(void) {
    testStruct2* temp = D_800F6F00_name_74;
    for (; temp->unk_00 >= 0; temp++) {
        if (func_8005CE48(temp->unk_02) != 0) {
            BoardSpaceTypeSet(temp->unk_00, 1);
        }
    }
}

void func_800F666C_name_74(void) {
    Object* temp_v1;
    GW_PLAYER* player;

    omInitObjMan(0x50, 0x28);
    func_80060088();
    InitCameras(2);
    func_80023448(1);
    func_800234B8(0, 0x78, 0x78, 0x78);
    func_800234B8(1, 0x40, 0x40, 0x60);
    func_80023504(1, -100.0f, 100.0f, 300.0f);
    func_8005C3FC(0x51, 0x50);
    func_80052E84(0);
    player = GetPlayerStruct(0);
    func_8003E174(player->player_obj);
    player->player_obj->unk_0A |= 2;
    func_800F68E8_name_74();
    func_800F6988_name_74();
    func_800F6C88_name_74();
    EventTableHydrate(D_800F6FD0_name_74);
    func_800F6610_name_74();
    func_8005CC3C();
    func_80060128(0x46);
}

void func_800F6758_name_74(void) {
    func_800F666C_name_74();
}

void func_800F6774_name_74(void) {
    SetPlayerOntoChain(0, 0, 0);
    func_800F666C_name_74();
}

void func_800F67A0_name_74(void) {
    SetPlayerOntoChain(0, 0, 7);
    func_800F666C_name_74();
}

void func_800F67CC_name_74(void) {
    Object* temp_s1 = HuPrcCurrentGet()->user_data;
    GW_PLAYER* temp_s2 = GetPlayerStruct(-1);
    Vec3f* vec = &temp_s1->unk_18;

    while (1) {
        HuPrcVSleep();
        func_800A0E80(vec, &temp_s2->player_obj->coords, &temp_s1->coords);
        func_8003D408(vec);        
    }
}

void func_800F683C_name_74(void) {
    Object* obj;

    if (D_800F7020_name_74 == NULL) {
        obj = MBModelCreate(0x6AU, NULL);
        func_8003E174(obj);
        D_800F7020_name_74 = obj;
        obj->unk_0A |= 2;
        func_800A0D00(&obj->xScale, 0.6f, 0.6f, 0.6f);
        obj->unk_30 = 100.0f;
        func_800A0D50(&obj->coords, &BoardSpaceGet(0)->coords);
        omAddPrcObj(func_800F67CC_name_74, 0x4800, 0, 0)->user_data = obj;
    }
}

void func_800F68E8_name_74(void) {
    D_800F7020_name_74 = 0;
    func_800F683C_name_74();
}

void func_800F6908_name_74(void) {
    Object* temp_v0;

    if (D_800F7024_name_74 == NULL) {
        temp_v0 = MBModelCreate(0xEU, NULL);
        func_8003E174(temp_v0);
        D_800F7024_name_74 = temp_v0;
        temp_v0->unk_0A |= 2;
        func_800A0D00(&temp_v0->xScale, 1.4f, 1.4f, 1.4f);
        func_800A0D50(&temp_v0->coords, &BoardSpaceGet(1)->coords);
    }
}

void func_800F6988_name_74(void) {
    D_800F7024_name_74 = 0;
    func_800F6908_name_74();
}

/* user_data is the model index (0..1) */
void func_800F69A8_name_74(void) {
    Vec3f sp10;
    s32 idx = (s32)(s32)HuPrcCurrentGet()->user_data;
    Object* obj = D_800F702C_name_74[idx];
    u8 r;

    while (1) {
        HuPrcSleep((u8)(rand8() % 20) + 10);
        func_800A0D50(&sp10, &BoardSpaceGet(D_800F6F1C_name_74[idx])->coords);
        sp10.x += (u8)(rand8() % 80) - 40;
        sp10.z += (u8)(rand8() % 80) - 40;
        r = rand8() % 3;
        obj->unk_34 = *(D_800F6F28_name_74 + r);
        obj->unk_38 = D_800F6F34_name_74[r];
        func_8004D1EC(&obj->coords, &sp10, &obj->coords, D_800F6F20_name_74[r]);
        HuPrcSleep(r + 3);
    }
}

void func_800F6B7C_name_74(s16 arg0) {
    Object* obj;

    if (D_800F702C_name_74[arg0] != NULL) {
        return;
    }
    if (D_800F7028_name_74 == NULL) {
        obj = MBModelCreate(0x8D, NULL);
        func_8003E174(obj);
        D_800F7028_name_74 = obj;
    } else {
        obj = MBModelParamCreate(D_800F7028_name_74);
    }
    D_800F702C_name_74[arg0] = obj;
    obj->unk_0A |= 2;
    if (arg0 > 0) {
        func_800A0D00(&obj->xScale, 0.6f, 0.6f, 0.6f);
    }
    func_800A0D50(&obj->coords, &BoardSpaceGet(D_800F6F1C_name_74[arg0])->coords);
    omAddPrcObj(func_800F69A8_name_74, 0x4800, 0, 0)->user_data = (void*)(s32)arg0;
}

void func_800F6C88_name_74(void) {
    s32 i;

    D_800F7028_name_74 = NULL;
    for (i = 0; i < 2; i++) {
        D_800F702C_name_74[i] = NULL;
        func_800F6B7C_name_74(i);
    }
}

void func_800F6CE8_name_74(void) {
    func_8005B860(-1);
    func_8005BD1C(0);
}

void func_800F6D0C_name_74(void) {
    s16 temp_s0 = func_8005BAB0(0x4B3);
    s16 temp_s1 = func_8005B984(0x4A9);

    func_80070D90(temp_s0);
    if (temp_s1 == 0) {
        func_8005CD7C(0, 7, 1, 1);
        func_80058910(-1, 0);
    }
    EndProcess(NULL);
}

void func_800F6D84_name_74(void) {
    func_8005B860(0x1A);
}

void func_800F6DA0_name_74(void) {
    func_8005B860(0x1B);
    PlaySound(0x94);
}

void func_800F6DC4_name_74(void) {
    func_8005B860(0x1C);
}

void func_800F6DE0_name_74(void) {
    func_8005B860(0x1D);
    PlaySound(0xBF);
}

void func_800F6E04_name_74(void) {
    func_8005B860(0x1E);
}

void func_800F6E20_name_74(void) {
    func_8005B860(0x1F);
}

void func_800F6E3C_name_74(void) {
    func_8005B860(-1);
    func_8005BD10(0);
}

void func_800F6E60_name_74(void) {
    s16 temp_s0 = func_8005BAB0(0x4B4);
    s16 temp_s1 = func_8005B984(0);

    func_80070D90(temp_s0);
    if (temp_s1 == 0) {
        func_8005CD7C(3, 5, 1, 0);
        func_80058910(-1, 0);
    }
    EndProcess(NULL);
}
