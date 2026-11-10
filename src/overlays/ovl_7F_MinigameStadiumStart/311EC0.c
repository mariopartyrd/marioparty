#include "common.h"
#include "engine/process.h"
#include "spaces.h"

void func_8004DBD4(s32, s32);
void func_800F66BC_MinigameStadiumStart(void);
void func_800F6824_MinigameStadiumStart(void);
void func_800F6888_MinigameStadiumStart(void);
void func_800F69CC_MinigameStadiumStart(void);
void func_800F6A48_MinigameStadiumStart(void);
void func_800F6A68_MinigameStadiumStart(void);
void func_800F6AEC_MinigameStadiumStart(void);
void func_800F6B0C_MinigameStadiumStart(s16 index);
void func_800F6C04_MinigameStadiumStart(void);
void func_800F6C64_MinigameStadiumStart(void);
void func_800F6C88_MinigameStadiumStart(void);
void func_800F6DBC_MinigameStadiumStart(void);
void func_800F6E8C_MinigameStadiumStart(void);

// bss
extern Object* D_800F6FA0_MinigameStadiumStart;
extern Object* D_800F6FA4_MinigameStadiumStart;
extern Object* D_800F6FA8_MinigameStadiumStart;
extern Object* D_800F6FB0_MinigameStadiumStart[];

const s16 D_800F6F40_MinigameStadiumStart[] = { 10, 14, 20 };
const f32 D_800F6F48_MinigameStadiumStart[] = { 20.0f, 11.0f, 20.0f };
const f32 D_800F6F54_MinigameStadiumStart[] = { -4.0f, -3.0f, -2.0f };
const s16 D_800F6F60_MinigameStadiumStart[] = { 0x2A, 0x28, 0x2C, 0x2B, 0x2E, 0x2F, 0x1F };
const EventListEntry D_800F6F70_MinigameStadiumStart[] = {
    { 1, 1, func_800F6C64_MinigameStadiumStart },
    { 1, 2, func_800F6E8C_MinigameStadiumStart },
    { 0, 0, NULL },
};
const EventTableEntry D_800F6F88_MinigameStadiumStart[] = {
    { 0x32, (EventListEntry*)D_800F6F70_MinigameStadiumStart },
    { -1, NULL },
};

void func_800F6610_MinigameStadiumStart(void) {
    GwSystem.curBoardIndex = 9;
    SetBoardFeatureFlag(0x2C);
    omInitObjMan(0xA, 0);
    omOvlGotoEx(0x35, 0, 0x92);
}

void func_800F6654_MinigameStadiumStart(void) {
    omInitObjMan(0xA, 0);
    SetPlayerOntoChain(0, 0, 0);
    SetPlayerOntoChain(1, 0, 0);
    SetPlayerOntoChain(2, 0, 0);
    SetPlayerOntoChain(3, 0, 0);
    omOvlReturnEx(1);
}

void func_800F66BC_MinigameStadiumStart(void) {
    GW_PLAYER* player;
    s32 i;

    omInitObjMan(0x50, 0x28);
    i = 0;
    func_80060088();
    func_80023448(1);
    func_800234B8(0, 0x78, 0x78, 0x78);
    func_800234B8(1, 0x40, 0x40, 0x60);
    func_80023504(1, -100.0f, 100.0f, 300.0f);
    func_80056A08(0x63, 0x53, 0x67, 0);
    func_80052E84(0);
    func_80052E84(1);
    func_80052E84(2);
    func_80052E84(3);
    do {
        player = GetPlayerStruct(i);
        i++;
        func_8003E174(player->player_obj);
        player->player_obj->unk_0A |= 2;
    } while (i < 4);
    func_800F6A48_MinigameStadiumStart();
    func_800F6AEC_MinigameStadiumStart();
    func_800F6C04_MinigameStadiumStart();
}

void func_800F67B8_MinigameStadiumStart(void) {
    func_80060128(0x31);
    InitCameras(2);
    func_800F66BC_MinigameStadiumStart();
    EventTableHydrate((EventTableEntry*)D_800F6F88_MinigameStadiumStart);
    func_800584F0(0);
}

void func_800F67F8_MinigameStadiumStart(void) {
    InitCameras(1);
    func_800F66BC_MinigameStadiumStart();
    func_800584F0(1);
}

void func_800F6824_MinigameStadiumStart(void) {
    Object* obj = HuPrcCurrentGet()->user_data;
    Vec3f* rot = &obj->unk_18;

    while (TRUE) {
        HuPrcVSleep();
        func_800A0E80(rot, &GetPlayerStruct(-1)->player_obj->coords, &obj->coords);
        func_8003D408(rot);
    }
}

void func_800F6888_MinigameStadiumStart(void) {
    Object* obj = HuPrcCurrentGet()->user_data;
    s32 timer = 0;
    s32 i;

    while (TRUE) {
        HuPrcVSleep();
        if (timer == 0) {
            i = (u8)(rand8() % 3);
            timer = (u8)(rand8() % 30) + D_800F6F40_MinigameStadiumStart[i];
            obj->unk_34 = D_800F6F48_MinigameStadiumStart[i];
            obj->unk_38 = D_800F6F54_MinigameStadiumStart[i];
        }
        timer--;
        func_800A0E80(&obj->unk_18, &GetPlayerStruct(-1)->player_obj->coords, &obj->coords);
        func_8003D408(&obj->unk_18);
    }
}

void func_800F69CC_MinigameStadiumStart(void) {
    Object* obj;

    if (D_800F6FA0_MinigameStadiumStart == NULL) {
        obj = MBModelCreate(0x89, NULL);
        func_8003E174(obj);
        D_800F6FA0_MinigameStadiumStart = obj;
        obj->unk_0A |= 2;
        func_800A0D50(&obj->coords, &BoardSpaceGet(0x1D)->coords);
        func_8003C314(9, obj, 0, 2);
    }
}

void func_800F6A48_MinigameStadiumStart(void) {
    D_800F6FA0_MinigameStadiumStart = NULL;
    func_800F69CC_MinigameStadiumStart();
}

void func_800F6A68_MinigameStadiumStart(void) {
    Object* obj;

    if (D_800F6FA4_MinigameStadiumStart == NULL) {
        obj = MBModelCreate(0x39, NULL);
        func_8003E174(obj);
        D_800F6FA4_MinigameStadiumStart = obj;
        obj->unk_0A |= 2;
        func_800A0D50(&obj->coords, &BoardSpaceGet(0x2D)->coords);
        omAddPrcObj(func_800F6824_MinigameStadiumStart, 0x4800, 0, 0)->user_data = obj;
    }
}

void func_800F6AEC_MinigameStadiumStart(void) {
    D_800F6FA4_MinigameStadiumStart = NULL;
    func_800F6A68_MinigameStadiumStart();
}

void func_800F6B0C_MinigameStadiumStart(s16 index) {
    Object* obj;
    void (*func)(void);

    if (D_800F6FB0_MinigameStadiumStart[index] == NULL) {
        if (D_800F6FA8_MinigameStadiumStart == NULL) {
            obj = MBModelCreate(7, NULL);
            func_8003E174(obj);
            D_800F6FA8_MinigameStadiumStart = obj;
        } else {
            obj = MBModelParamCreate(D_800F6FA8_MinigameStadiumStart);
        }
        D_800F6FB0_MinigameStadiumStart[index] = obj;
        obj->unk_0A |= 2;
        func_800A0D50(&obj->coords, &BoardSpaceGet(((s16*)D_800F6F60_MinigameStadiumStart)[index])->coords);
        if (index & 1) {
            func = func_800F6888_MinigameStadiumStart;
        } else {
            func = func_800F6824_MinigameStadiumStart;
        }
        omAddPrcObj(func, 0x4800, 0, 0)->user_data = obj;
    }
}

void func_800F6C04_MinigameStadiumStart(void) {
    s32 i;

    D_800F6FA8_MinigameStadiumStart = NULL;
    for (i = 0; i < 7; i++) {
        D_800F6FB0_MinigameStadiumStart[i] = NULL;
        func_800F6B0C_MinigameStadiumStart(i);
    }
}

void func_800F6C64_MinigameStadiumStart(void) {
    SetNextChainAndSpace(-1, 0, 3);
}

void func_800F6C88_MinigameStadiumStart(void) {
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

void func_800F6DBC_MinigameStadiumStart(void) {
    GwCommon.boardWork[31]++;
    if (_CheckFlag(0x42) == 0 && (GwCommon.boardWork[31] % 10 == 0 || _CheckFlag(0x4D) == 0)) {
        if (_CheckFlag(0x4D) != 0) {
            func_80058910(-1, 1);
        }
        SetBoardFeatureFlag(0x4D);
        func_800587EC(0x5F, 0, 1);
        return;
    }
    func_800F6C88_MinigameStadiumStart();
}

void func_800F6E8C_MinigameStadiumStart(void) {
    func_8004D2A4(-1, 8, 0x1D);
    GwCommon.boardWork[31]++;
    if (_CheckFlag(0x4D) == 0) {
        SetBoardFeatureFlag(0x4D);
        func_800587EC(0x5F, 0, 1);
    } else {
        func_800F6C88_MinigameStadiumStart();
    }
    EndProcess(NULL);
}
