#include "common.h"
#include "engine/process.h"
#include "spaces.h"

void func_8004DBD4(s32, s32);

void func_800F6610_PeachsBirthdayCake(void);
void func_800F68B0_PeachsBirthdayCake(void);
void func_800F6DD4_PeachsBirthdayCake(void);
void func_800F6E78_PeachsBirthdayCake(void);
void func_800F6F00_PeachsBirthdayCake(void);
void func_800F6F9C_PeachsBirthdayCake(void);
void func_800F70E0_PeachsBirthdayCake(void);
void func_800F7330_PeachsBirthdayCake(void);
void func_800F73F4_PeachsBirthdayCake(void);
void func_800F7430_PeachsBirthdayCake(void);
void func_800F7468_PeachsBirthdayCake(void);
void func_800F74A0_PeachsBirthdayCake(void);
void func_800F76C8_PeachsBirthdayCake(void);
void func_800F76FC_PeachsBirthdayCake(void);
void func_800F773C_PeachsBirthdayCake(void);
void func_800F79BC_PeachsBirthdayCake(void);

/* .data (0x800F7AB0..0x800F7D30) */
Vec4f D_800F7AB0_PeachsBirthdayCake = { 0.0f, 0.0f, 320.0f, 240.0f };
s32 D_800F7AC0_PeachsBirthdayCake[] = { 1, 0x70003 }; /* MBModelCreate motion list: words */
/* cake space per cake slot (boardWork[0..13]) */
s16 D_800F7AC8_PeachsBirthdayCake[] = { 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 0x40, 0x41, 0x42 };
/* cake model rotation per slot */
s16 D_800F7AE4_PeachsBirthdayCake[] = { 0, 60, 100, 20, 40, 10, 50, 110, 30, 50, 20, 70, 90, 10, 45, 0 };
/* marker model per character (read as u8 for MBModelCreate; splat's D_800F7B05 is the low byte of entry 0) */
s16 D_800F7B04_PeachsBirthdayCake[] = { 0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22 };
Vec3f D_800F7B10_PeachsBirthdayCake[] = {
    { -80.0f, 0.0f, 70.0f }, { -80.0f, 0.0f, 70.0f }, { -80.0f, 0.0f, 70.0f },
    { -80.0f, 0.0f, 70.0f }, { -80.0f, 0.0f, 70.0f }, { -80.0f, 0.0f, 70.0f },
    { 80.0f, 0.0f, 70.0f },  { 80.0f, 0.0f, 70.0f },  { 70.0f, 0.0f, 70.0f },
    { 80.0f, 0.0f, 70.0f },  { 80.0f, 0.0f, 70.0f },  { 80.0f, 0.0f, 70.0f },
    { 80.0f, 0.0f, 70.0f },  { 80.0f, 0.0f, 70.0f },
};
f32 D_800F7BB8_PeachsBirthdayCake[] = {
    15.0f, 6.0f, 10.0f, 15.0f, 10.0f, 13.0f, -10.0f,
    -15.0f, -10.0f, -15.0f, -10.0f, -10.0f, 10.0f, -10.0f,
};
EventListEntry D_800F7BF0_PeachsBirthdayCake[] = {
    { 1, 1, func_800F73F4_PeachsBirthdayCake },
    { 2, 1, func_800F7430_PeachsBirthdayCake },
    { 0, 0, NULL },
};
EventListEntry D_800F7C08_PeachsBirthdayCake[] = {
    { 1, 1, func_800F7468_PeachsBirthdayCake },
    { 0, 0, NULL },
};
EventListEntry D_800F7C18_PeachsBirthdayCake[] = {
    { 1, 1, func_800F74A0_PeachsBirthdayCake },
    { 0, 0, NULL },
};
EventListEntry D_800F7C28_PeachsBirthdayCake[] = {
    { 1, 1, func_800F74A0_PeachsBirthdayCake },
    { 1, 2, func_800F76C8_PeachsBirthdayCake },
    { 0, 0, NULL },
};
EventListEntry D_800F7C40_PeachsBirthdayCake[] = {
    { 1, 1, func_800F76FC_PeachsBirthdayCake },
    { 0, 0, NULL },
};
EventListEntry D_800F7C50_PeachsBirthdayCake[] = {
    { 3, 2, func_800F773C_PeachsBirthdayCake },
    { 0, 0, NULL },
};
EventListEntry D_800F7C60_PeachsBirthdayCake[] = {
    { 3, 1, func_800F79BC_PeachsBirthdayCake },
    { 0, 0, NULL },
};
EventTableEntry D_800F7C70_PeachsBirthdayCake[] = {
    { 0x54, D_800F7C18_PeachsBirthdayCake },
    { 0x50, D_800F7C40_PeachsBirthdayCake },
    { 0x51, D_800F7BF0_PeachsBirthdayCake },
    { 0x16, D_800F7C50_PeachsBirthdayCake },
    { 0x21, D_800F7C50_PeachsBirthdayCake },
    { 0x37, D_800F7C50_PeachsBirthdayCake },
    { 0x38, D_800F7C50_PeachsBirthdayCake },
    { 0x2, D_800F7C50_PeachsBirthdayCake },
    { 0x3, D_800F7C50_PeachsBirthdayCake },
    { 0x6, D_800F7C50_PeachsBirthdayCake },
    { 0x7, D_800F7C50_PeachsBirthdayCake },
    { 0xC, D_800F7C50_PeachsBirthdayCake },
    { 0xD, D_800F7C50_PeachsBirthdayCake },
    { 0xE, D_800F7C50_PeachsBirthdayCake },
    { 0xF, D_800F7C50_PeachsBirthdayCake },
    { 0x12, D_800F7C50_PeachsBirthdayCake },
    { 0x13, D_800F7C50_PeachsBirthdayCake },
    { 0x1F, D_800F7C60_PeachsBirthdayCake },
    { 0x33, D_800F7C60_PeachsBirthdayCake },
    { -1, NULL },
};
EventTableEntry D_800F7D10_PeachsBirthdayCake[] = {
    { 0x54, D_800F7C28_PeachsBirthdayCake },
    { -1, NULL },
};
EventTableEntry D_800F7D20_PeachsBirthdayCake[] = {
    { 0x55, D_800F7C08_PeachsBirthdayCake },
    { -1, NULL },
};

/* bss */
extern Object* D_800F7E10_PeachsBirthdayCake;
extern Object* D_800F7E14_PeachsBirthdayCake;
extern Object* D_800F7E18_PeachsBirthdayCake;
extern Object* D_800F7E1C_PeachsBirthdayCake;
extern s32 D_800F7E20_PeachsBirthdayCake;
extern Object* D_800F7E24_PeachsBirthdayCake;     /* cake template model */
extern Object* D_800F7E28_PeachsBirthdayCake[14]; /* cake per slot */
extern s16 D_800F7E60_PeachsBirthdayCake[4];      /* cakes per player */
extern Object* D_800F7E68_PeachsBirthdayCake[4];  /* marker template per player */
extern Object* D_800F7E78_PeachsBirthdayCake[14]; /* marker per slot */

void func_800F6610_PeachsBirthdayCake(void) {
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

void func_800F6820_PeachsBirthdayCake(mystery_struct_ret_func_80048224* a0) {
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

void func_800F68B0_PeachsBirthdayCake(void) {
    mystery_struct_ret_func_80048224 *str;
    BoardSpace* spacedata;

    func_80060128(43);
    str = func_80048224(D_800F7AC0_PeachsBirthdayCake);
    SetFadeInTypeAndTime(2, 16);

    while (func_80072718() != 0) {
        HuPrcVSleep();
    }

    func_8004A520();
    func_8004B5C4(3.0f);
    func_800F6820_PeachsBirthdayCake(str);

    LoadStringIntoWindow(str->unk8, (void*)0x4E6, -1, -1);
    func_80071C8C(str->unk8, 1);
    PlaySound(1125);
    WaitForTextConfirmation(str->unk8);
    func_80071E80(str->unk8, 1);
    func_8006EB40(str->unk8);

    spacedata = BoardSpaceGet(0x44);
    func_8004B5DC(&spacedata->coords);
    func_8004B838(5.0f);
    HuPrcSleep(5);

    while (func_8004B850() != 0) {
        HuPrcVSleep();
    }

    HuPrcSleep(5);
    omAddPrcObj(func_800F6610_PeachsBirthdayCake, 0x4800, 0, 0)->user_data = spacedata;
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

void func_800F6A80_PeachsBirthdayCake(void) {
    GwSystem.curBoardIndex = 1;
    omInitObjMan(10, 0);
    omOvlGotoEx(53, 0, 146);
}

void func_800F6ABC_PeachsBirthdayCake(void) {
    omInitObjMan(10, 0);
    SetPlayerOntoChain(0, 1, 0);
    SetPlayerOntoChain(1, 1, 0);
    SetPlayerOntoChain(2, 1, 0);
    SetPlayerOntoChain(3, 1, 0);
    GwCommon.boardWork[0] = -1;
    GwCommon.boardWork[1] = -1;
    GwCommon.boardWork[2] = -1;
    GwCommon.boardWork[3] = -1;
    GwCommon.boardWork[4] = -1;
    GwCommon.boardWork[5] = -1;
    GwCommon.boardWork[6] = -1;
    GwCommon.boardWork[7] = -1;
    GwCommon.boardWork[8] = -1;
    GwCommon.boardWork[9] = -1;
    GwCommon.boardWork[10] = -1;
    GwCommon.boardWork[11] = -1;
    GwCommon.boardWork[12] = -1;
    GwCommon.boardWork[13] = -1;
    GwCommon.boardWork[18] = 4;
    GwCommon.boardWork[24] = 0;
    GwCommon.boardWork[15] = 5;
    GwCommon.boardWork[17] = 0;
    omOvlReturnEx(1);
}

void func_800F6B80_PeachsBirthdayCake(void) {
    GW_PLAYER* player;
    s32 i;

    omInitObjMan(0x50, 0x28);
    func_80060088();
    func_80023448(1);
    func_800234B8(0, 0x78, 0x78, 0x78);
    func_800234B8(1, 0x40, 0x40, 0x60);
    func_80023504(1, -100.0f, 100.0f, 300.0f);
    func_80056A08(7, 0x46, 0xE, 0);
    func_80052E84(0);
    func_80052E84(1);
    func_80052E84(2);
    func_80052E84(3);

    for (i = 0; i < 4; i++) {
        player = GetPlayerStruct(i);
        func_8003E174(player->player_obj);
        player->player_obj->unk_0A |= 2;
    }

    func_800F6E78_PeachsBirthdayCake();
    func_800F70E0_PeachsBirthdayCake();
    func_800F7330_PeachsBirthdayCake();

    if (_CheckFlag(0xE) == 0) {
        func_800F6DD4_PeachsBirthdayCake();
    }
    if (_CheckFlag(0xD) == 0) {
        func_800F6F9C_PeachsBirthdayCake();
    }
    func_800F6F00_PeachsBirthdayCake();
}

void func_800F6CB4_PeachsBirthdayCake(void) {
    func_80060128(9);
    InitCameras(2);
    func_800F6B80_PeachsBirthdayCake();
    EventTableHydrate(D_800F7C70_PeachsBirthdayCake);
    if (_CheckFlag(0xE) == 0) {
        EventTableHydrate(D_800F7D10_PeachsBirthdayCake);
    }
    if (_CheckFlag(0xD) == 0) {
        EventTableHydrate(D_800F7D20_PeachsBirthdayCake);
    }
    func_800584F0(0);
}

void func_800F6D2C_PeachsBirthdayCake(void) {
    InitCameras(1);
    func_800F6B80_PeachsBirthdayCake();
    func_800584F0(1);
}

void func_800F6D58_PeachsBirthdayCake(void) {
    Object *ptr;

    if (D_800F7E10_PeachsBirthdayCake != NULL) {
        return;
    }

    ptr = MBModelCreate(0x39, NULL);
    func_8003E174(ptr);
    D_800F7E10_PeachsBirthdayCake = ptr;
    ptr->unk_0A |= 0x2;
    func_800A0D50(&ptr->coords, &BoardSpaceGet(0x3A)->coords);
    func_8003C314(9, ptr, 0, 0);
}

void func_800F6DD4_PeachsBirthdayCake(void) {
    D_800F7E10_PeachsBirthdayCake = NULL;
    func_800F6D58_PeachsBirthdayCake();
}

void func_800F6DF4_PeachsBirthdayCake(void) {
    Object *ptr;

    if (D_800F7E14_PeachsBirthdayCake != NULL) {
        return;
    }

    ptr = MBModelCreate(0x3A, NULL);
    func_8003E174(ptr);
    ptr->unk_0A |= 0x2;
    D_800F7E14_PeachsBirthdayCake = ptr;
    func_8004CDCC(ptr);
    func_800A0D50(&ptr->coords, &BoardSpaceGet(0x44)->coords);
    func_8003C314(6, ptr, 0, 0);
}

void func_800F6E78_PeachsBirthdayCake(void) {
    D_800F7E14_PeachsBirthdayCake = NULL;
    func_800F6DF4_PeachsBirthdayCake();
}

void func_800F6E98_PeachsBirthdayCake(void) {
    Object *ptr;

    if (D_800F7E18_PeachsBirthdayCake != NULL) {
        return;
    }

    ptr = MBModelCreate(0xB, NULL);
    func_8003E174(ptr);
    ptr->unk_0A |= 0x2;
    D_800F7E18_PeachsBirthdayCake = ptr;
    func_800A0D50(&ptr->coords, &BoardSpaceGet(0x45)->coords);
}

void func_800F6F00_PeachsBirthdayCake(void) {
    D_800F7E18_PeachsBirthdayCake = NULL;
    func_800F6E98_PeachsBirthdayCake();
}

void func_800F6F20_PeachsBirthdayCake(void) {
    Object *ptr;

    if (D_800F7E1C_PeachsBirthdayCake != NULL) {
        return;
    }

    ptr = MBModelCreate(0x3B, NULL);
    func_8003E174(ptr);
    D_800F7E1C_PeachsBirthdayCake = ptr;
    ptr->unk_0A |= 0x2;
    func_800A0D50(&ptr->coords, &BoardSpaceGet(0x43)->coords);
    func_8003C314(7, ptr, 0, 0);
}

void func_800F6F9C_PeachsBirthdayCake(void) {
    D_800F7E1C_PeachsBirthdayCake = NULL;
    func_800F6F20_PeachsBirthdayCake();
}

void func_800F6FBC_PeachsBirthdayCake(s16 arg0) {
    Object* obj;

    if (D_800F7E28_PeachsBirthdayCake[arg0] == NULL) {
        D_800F7E20_PeachsBirthdayCake += 2;
        if (D_800F7E24_PeachsBirthdayCake == NULL) {
            obj = MBModelCreate(0x23, NULL);
            func_8003E174(obj);
            D_800F7E24_PeachsBirthdayCake = obj;
        } else {
            obj = MBModelParamCreate(D_800F7E24_PeachsBirthdayCake);
        }
        obj->unk_0A |= 2;
        D_800F7E28_PeachsBirthdayCake[arg0] = obj;
        func_800A0D00(&obj->xScale, 0.8f, 0.8f, 0.8f);
        func_800A0D50(&obj->coords, &BoardSpaceGet(D_800F7AC8_PeachsBirthdayCake[arg0])->coords);
        func_80025CA8(*obj->unk_3C->unk_40, D_800F7AE4_PeachsBirthdayCake[arg0]);
    }
}

void func_800F70E0_PeachsBirthdayCake(void) {
    s32 i;

    D_800F7E20_PeachsBirthdayCake = 0;
    D_800F7E24_PeachsBirthdayCake = NULL;
    for (i = 0; i < 14; i++) {
        D_800F7E28_PeachsBirthdayCake[i] = NULL;
        if (GwCommon.boardWork[i] != -1) {
            func_800F6FBC_PeachsBirthdayCake(i);
        }
    }
}

void func_800F7178_PeachsBirthdayCake(s16 arg0) {
    Vec3f offset;
    Object* obj;
    BoardSpace* space;
    s16 player;

    player = GwCommon.boardWork[arg0];
    if ((D_800F7E78_PeachsBirthdayCake[arg0] == NULL) & (player >= 0)) {
        D_800F7E60_PeachsBirthdayCake[player]++;
        if (D_800F7E68_PeachsBirthdayCake[player] == NULL) {
            obj = MBModelCreate(D_800F7B04_PeachsBirthdayCake[GwPlayer[player].character], NULL);
            func_8003E174(obj);
            D_800F7E68_PeachsBirthdayCake[player] = obj;
        } else {
            obj = MBModelParamCreate(D_800F7E68_PeachsBirthdayCake[player]);
        }
        obj->unk_0A |= 2;
        D_800F7E78_PeachsBirthdayCake[arg0] = obj;
        func_800A0D00(&obj->xScale, 0.8f, 0.8f, 0.8f);
        space = BoardSpaceGet(D_800F7AC8_PeachsBirthdayCake[arg0]);
        func_800A0D50(&offset, &D_800F7B10_PeachsBirthdayCake[arg0]);
        func_800A0E00(&obj->coords, &space->coords, &offset);
        obj->unk_3C->unk_24 = -30.0f;
        obj->unk_3C->unk_2C = D_800F7BB8_PeachsBirthdayCake[arg0];
    }
}

void func_800F7330_PeachsBirthdayCake(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_800F7E60_PeachsBirthdayCake[i] = 0;
        D_800F7E68_PeachsBirthdayCake[i] = NULL;
    }
    for (i = 0; i < 14; i++) {
        D_800F7E78_PeachsBirthdayCake[i] = NULL;
        if (GwCommon.boardWork[i] != -1) {
            func_800F7178_PeachsBirthdayCake(i);
        }
    }
}

void func_800F73F4_PeachsBirthdayCake(void) {
    func_8004D2A4(-1, 8, 0x45);
    func_800587EC(0x4B, 0, 1);
    SetEventReturnFlag(1);
}

void func_800F7430_PeachsBirthdayCake(void) {
    if (GwCommon.boardWork[24] != 0) {
        SetNextChainAndSpace(-1, 2, 0);
    } else {
        SetNextChainAndSpace(-1, 0, 0);
    }
}

void func_800F7468_PeachsBirthdayCake(void) {
    func_8004D2A4(-1, 8, 0x43);
    func_800587BC(0x49, 0, 3, 1);
}

void func_800F74A0_PeachsBirthdayCake(void) {
    SetNextChainAndSpace(-1, 1, 1);
}

// decomp-permuter
void func_800F74C4_PeachsBirthdayCake(void)
{
  s16 player;
  unsigned short win;
  s32 coins;
  player = GetCurrentPlayerIndex();
  func_800405DC(player);
  SetPlayerAnimation(-1, -1, 2);
  if (_CheckFlag(0x42) == 0)
  {
    win = CreateTextWindow(0x48, 0x3C, 0x10, 3);
    LoadStringIntoWindow((s16) win, (void *) 0x239, -1, -1);
    coins = 10;
  }
  else
  {
    win = CreateTextWindow(0x41, 0x3C, 0x11, 3);
    LoadStringIntoWindow((s16) win, (void *) 0x23A, -1, -1);
    coins = 20;
  }
  func_8006E070((s16) win, 0);
  ShowTextWindow((s16) win);
  PlaySound(0x432);
  func_8004DBD4((s16) win, player);
  HideTextWindow((s16) win);
  win = coins;
  func_80055960(player, win);
  ShowPlayerCoinChange(player, win);
  HuPrcSleep(30);
  func_8003FEFC(player);
}

void func_800F75F8_PeachsBirthdayCake(void) {
    GwCommon.boardWork[31]++;
    if (_CheckFlag(0x42) == 0 && (GwCommon.boardWork[31] % 10 == 0 || _CheckFlag(0x4D) == 0)) {
        if (_CheckFlag(0x4D) != 0) {
            func_80058910(-1, 1);
        }
        SetBoardFeatureFlag(0x4D);
        func_800587EC(0x5F, 0, 1);
        return;
    }
    func_800F74C4_PeachsBirthdayCake();
}

void func_800F76C8_PeachsBirthdayCake(void) {
    func_8004D2A4(-1, 8, 0x3A);
    func_800F75F8_PeachsBirthdayCake();
    EndProcess(NULL);
}

void func_800F76FC_PeachsBirthdayCake(void) {
    GwSystem.unk_1A = 0x4C;
    func_8004D2A4(-1, 8, 0x44);
    func_800587EC(0x44, 0, 2);
}

void func_800F773C_PeachsBirthdayCake(void) {
    GW_PLAYER* player;
    s16 space;
    s16 slot;
    s16 win;

    space = GetCurrentSpaceIndex();
    player = GetPlayerStruct(-1);
    switch (space) {
    case 0x16: slot = 0; break;
    case 0x21: slot = 1; break;
    case 0x37: slot = 2; break;
    case 0x38: slot = 3; break;
    case 0x2: slot = 4; break;
    case 0x3: slot = 5; break;
    case 0x6: slot = 6; break;
    case 0x7: slot = 7; break;
    case 0xC: slot = 8; break;
    case 0xD: slot = 9; break;
    case 0xE: slot = 10; break;
    case 0xF: slot = 11; break;
    case 0x12: slot = 12; break;
    case 0x13: slot = 13; break;
    default:
        return;
    }

    if (GwCommon.boardWork[slot] < 0) {
        if (PlayerHasCoins(-1, 30) != 0) {
            GwCommon.boardWork[14] = slot;
            func_800587EC(0x4A, 0, 4);
        } else {
            while (func_8004B850() != 0) {
                HuPrcVSleep();
            }
            HuPrcVSleep();
            win = CreateTextWindow(0x3C, 0x40, 0x11, 1);
            LoadStringIntoWindow(win, (void*)0x1A4, -1, -1);
            func_8006E070(win, 0);
            ShowTextWindow(win);
            func_8004DBD4(win, player->player_index);
            HideTextWindow(win);
        }
    } else if (GwSystem.curPlayerIndex == GwCommon.boardWork[slot]) {
        while (func_8004B850() != 0) {
            HuPrcVSleep();
        }
        HuPrcVSleep();
        win = CreateTextWindow(0x50, 0x40, 0xD, 2);
        LoadStringIntoWindow(win, (void*)0x1A6, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        func_8004DBD4(win, player->player_index);
        HideTextWindow(win);
    } else if (player->stars == 0) {
        while (func_8004B850() != 0) {
            HuPrcVSleep();
        }
        HuPrcVSleep();
        win = CreateTextWindow(0x41, 0x40, 0x10, 2);
        LoadStringIntoWindow(win, (void*)0x1A5, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        func_8004DBD4(win, player->player_index);
        HideTextWindow(win);
    } else {
        GwCommon.boardWork[14] = slot;
        func_800587EC(0x4C, 0, 4);
    }
    EndProcess(NULL);
}

void func_800F79BC_PeachsBirthdayCake(void) {
    GW_PLAYER* player;
    s32 i;

    for (i = 0; i < 4; i++) {
        player = GetPlayerStruct(i);
        player->group = i != GetCurrentPlayerIndex();
    }
    func_800587BC(1, 0, 5, 1);
}

void func_800F7A28_PeachsBirthdayCake(void) {
    InitCameras(2);
    func_8001D4D4(1, &D_800F7AB0_PeachsBirthdayCake);
    func_800F6B80_PeachsBirthdayCake();
    func_800584F0(2);
    omAddPrcObj(func_800F68B0_PeachsBirthdayCake, 0x1005, 0, 0);
}
