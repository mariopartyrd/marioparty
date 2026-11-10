#include "engine/process.h"
#include "FirstMap.h"

void func_800F694C_FirstMap(void);
void func_800F6970_FirstMap(void);
void func_800F6994_FirstMap(void);
void func_800F6A04_FirstMap(void);
s32 func_800415E8(s32);
void func_8004D6FC(s16, f32);
void func_8004068C(s32);
s32 ExecuteEventForSpace(s16, s16);
void func_80055544(s32);
void func_800550C4(void);
void func_80055228(void);
void func_800559BC(void);
void func_80043544(void);
Process* func_800448A0(); /* retail calls it without an argument (it ignores its s32) */

s16 D_800F8750_FirstMap[] = { 3, 0, 1, 2 };

EventListEntry D_800F8758_FirstMap[] = {
    { 1, 1, func_800F694C_FirstMap },
    { 0, 0, NULL },
};

EventListEntry D_800F8768_FirstMap[] = {
    { 1, 1, func_800F6970_FirstMap },
    { 0, 0, NULL },
};

EventListEntry D_800F8778_FirstMap[] = {
    { 1, 1, func_800F6994_FirstMap },
    { 0, 0, NULL },
};

/* Space list for the direction prompt: chain spaces 13 and 14. */
s16 D_800F8788_FirstMap[] = { 13, 14, -1, 0 };

/* CPU cursor moves per prompt (indexed by boardWork[0]). */
s16 D_800F8790_FirstMap[] = { 2, 1, 2, 2 };

EventListEntry D_800F8798_FirstMap[] = {
    { 1, 2, func_800F6A04_FirstMap },
    { 0, 0, NULL },
};

EventTableEntry D_800F87A8_FirstMap[] = {
    { 0x1E, D_800F8758_FirstMap },
    { 0x08, D_800F8768_FirstMap },
    { 0x11, D_800F8768_FirstMap },
    { 0x17, D_800F8798_FirstMap },
    { 0x1F, D_800F8778_FirstMap },
    { -1, NULL },
};

s32 D_800F87D8_FirstMap[] = {
    0xA0028, 0xA0029, 0xA002A, 0xA002B, 0xA002C, 0xA002D, 0xA002E, 0xA002F,
};

/* Host model's motion list for func_80048224/MBModelCreate: a count word, then file ids. */
s32 D_800F87F8_FirstMap[] = { 3, 0x70003, 0xA0079, 0xA007A };

s16 D_800F8808_FirstMap = -1;

void func_800F6610_FirstMap(void) {
    GwSystem.curBoardIndex = 8;
    omInitObjMan(0xA, 0);
    omOvlGotoEx(0x35, 0, 0x92);
}

void func_800F664C_FirstMap(void) {
    s32 i;

    omInitObjMan(0xA, 0);
    SetPlayerOntoChain(0, 0, 0);
    SetPlayerOntoChain(1, 0, 0);
    SetPlayerOntoChain(2, 0, 0);
    SetPlayerOntoChain(3, 0, 0);
    func_800F6B0C_FirstMap();
    
    for (i = 0; i < MAX_PLAYERS; i++) {
        GetPlayerStruct(i)->character = D_800F8750_FirstMap[i];
    }

    omOvlReturnEx(1);
}

void func_800F66FC_FirstMap(void) {
    Object* temp_s0;

    if (D_800F8890_FirstMap == NULL) {
        temp_s0 = MBModelCreate(0x3A, NULL);
        func_8003E174(temp_s0);
        D_800F8890_FirstMap = temp_s0;
        temp_s0->unk_0A |= 2;
        func_8004CDCC(temp_s0);
        func_800A0D50(&temp_s0->coords, &BoardSpaceGet(0x1C)->coords);
    }
}

void func_800F676C_FirstMap(void) {
    D_800F8890_FirstMap = 0;
    func_800F66FC_FirstMap();
}

void func_800F678C_FirstMap(void) {
    Object* temp_s0;

    if (D_800F8894_FirstMap == NULL) {
        temp_s0 = MBModelCreate(0x39, NULL);
        func_8003E174(temp_s0);
        D_800F8894_FirstMap = temp_s0;
        temp_s0->unk_0A |= 2;
        func_800A0D50(&temp_s0->coords, &BoardSpaceGet(0x19)->coords);
    }
}

void func_800F67F4_FirstMap(void) {
    D_800F8894_FirstMap = 0;
    func_800F678C_FirstMap();
}

void func_800F6814_FirstMap(void) {
    Object* temp_s0;

    if (D_800F8898_FirstMap == NULL) {
        temp_s0 = MBModelCreate(0x6AU, NULL);
        func_8003E174(temp_s0);
        D_800F8898_FirstMap = temp_s0;
        temp_s0->unk_0A |= 2;
        func_800A0D00(&temp_s0->xScale, 0.6f, 0.6f, 0.6f);
        temp_s0->unk_30 = 100.0f;
        func_800A0D50(&temp_s0->coords, &BoardSpaceGet(0x1B)->coords);
    }
}

void func_800F68A4_FirstMap(void) {
    D_800F8898_FirstMap = 0;
    func_800F6814_FirstMap();
}

void func_800F68C4_FirstMap(void) {
    Object* temp_s0;

    if (D_800F889C_FirstMap == NULL) {
        temp_s0 = MBModelCreate(0x3BU, NULL);
        func_8003E174(temp_s0);
        D_800F889C_FirstMap = temp_s0;
        temp_s0->unk_0A |= 2;
        func_800A0D50(&temp_s0->coords, &BoardSpaceGet(0x1A)->coords);
    }
}

void func_800F692C_FirstMap(void) {
    D_800F889C_FirstMap = 0;
    func_800F68C4_FirstMap();
}

void func_800F694C_FirstMap(void) {
    SetNextChainAndSpace(-1, 1, 0);
}

void func_800F6970_FirstMap(void) {
    SetNextChainAndSpace(-1, 3, 0);
}

void func_800F6994_FirstMap(void) {
    SetNextChainAndSpace(-1, 1, 0);
}


void func_800F69B8_FirstMap(void) {
    while (func_8004B850() != 0) {
        HuPrcVSleep();
    }
    HuPrcVSleep();
    HuPrcSleep(3);
}

void func_800F69FC_FirstMap(void) {
}

void func_800F6A04_FirstMap(void) {
    s32 temp_s0, temp_s1, temp_a0;
    unk_8003B8D4Struct* temp_s2;
    s32 i;

    SetPlayerAnimation(-1, -1, 2);
    func_800F69B8_FirstMap();
    temp_s2 = func_8003C218(-1, D_800F8788_FirstMap);
    func_8003C060(temp_s2, -1, 0);
    if (PlayerIsCPU(-1) != 0) {
        temp_a0 = GwCommon.boardWork[0]++;
        temp_s1 = D_800F8790_FirstMap[temp_a0];
        for (i = 0; i < temp_s1; i++) {
            func_8003BE84(temp_s2, -2);
        }
        func_8003BE84(temp_s2, -4);
    }
    
    temp_s0 = DirectionPrompt(temp_s2);
    func_8003B908(temp_s2);
    func_800F69FC_FirstMap();
    
    if (temp_s0 != 0) {
        SetNextChainAndSpace(-1, 2, 0);
    }
    
    EndProcess(NULL);
}

void func_800F6B0C_FirstMap(void) {
    s32 i;
    
    for (i = 0; i < 4; i++) {
        GetPlayerStruct(i)->flags |= 1;
    }
}

void func_800F6B50_FirstMap(void) {
    Process* temp_s0;

    temp_s0 = HuPrcCurrentGet();
    HuPrcChildLink(temp_s0, func_800531E8());
    HuPrcChildWatch();
}

void func_800F6B8C_FirstMap(void) {
    Process* temp_s0;

    temp_s0 = HuPrcCurrentGet();
    HuPrcChildLink(temp_s0, func_800532B4());
    HuPrcChildWatch();
}

void* func_800F6BC8_FirstMap(s16 arg0, s16 arg1, s16 arg2) {
    ovl_3E_HeapStruct* temp_s0;
    s16 temp_s1;
    void* temp_s5;


    temp_s0 = MallocTemp(8U);
    temp_s0->unk0 = func_80064EF4(3, 0);
    temp_s5 = DataRead(0xA0030);
    temp_s0->unk2 = func_800678A4(temp_s5);
    func_80067208(temp_s0->unk0, 0, temp_s0->unk2, 0);
    func_80067384(temp_s0->unk0, 0, 0xB);
    func_800674BC(temp_s0->unk0, 0, 0x1000);
    temp_s1 = arg1 + 5;
    func_80066DC4(temp_s0->unk0, 0, temp_s1, arg2);
    DataClose(temp_s5);
    temp_s5 = DataRead(0xA0031);
    temp_s0->unk4 = func_800678A4(temp_s5);
    func_80067208(temp_s0->unk0, 1, temp_s0->unk4, 0);
    func_80067384(temp_s0->unk0, 1, 0xB);
    func_800674BC(temp_s0->unk0, 1, 0x1000);
    func_80066DC4(temp_s0->unk0, 1, temp_s1, arg2);
    func_8006752C(temp_s0->unk0, 1, 0xFF);
    func_800674F4(temp_s0->unk0, 1, 0xFF, 0xD3, 0x4F);
    DataClose(temp_s5);
    temp_s5 = DataRead(D_800F87D8_FirstMap[arg0]);
    temp_s0->unk6 = func_800678A4(temp_s5);
    func_80067208(temp_s0->unk0, 2, temp_s0->unk6, 0);
    func_80067384(temp_s0->unk0, 2, 0xA);
    func_800674BC(temp_s0->unk0, 2, 0x1000);
    func_80066DC4(temp_s0->unk0, 2, arg1, arg2);
    DataClose(temp_s5);
    return temp_s0;
}

void func_800F6DD8_FirstMap(ovl_3E_HeapStruct* arg0) {
    func_80067704(arg0->unk2);
    func_80067704(arg0->unk4);
    func_80067704(arg0->unk6);
    func_80064D38(arg0->unk0);
    FreeTemp(arg0);
}


void func_800F6E20_FirstMap(void) {
    D_800F88A0_FirstMap = -1;
    
    SetFadeInTypeAndTime(2, 0x10);
    func_80072724(0xFF, 0xFF, 0xFF);
    while (func_80072718() != 0) {
        HuPrcVSleep();
    }
    
    func_8004A520();
    func_8004B5C4(3.0f);
    func_8004B838(4.0f);
    while (1) {
        if (D_800F88A0_FirstMap < 0) {
            func_8004B5DC(&GetPlayerStruct(CURRENT_PLAYER)->player_obj->coords);
        } else {
            func_8004B5DC(&BoardSpaceGet(D_800F88A0_FirstMap)->coords);
        }
        HuPrcVSleep();        
    }
}

void func_800F6EF0_FirstMap(s16 arg0) {
    D_800F88A0_FirstMap = arg0;
}

void func_800F6EFC_FirstMap(void) {
    HuPrcSleep(3);
    while (func_8004B850() != 0) {
        HuPrcVSleep();
    }
}

void func_800F6F38_FirstMap(void) {
    GW_PLAYER* player;
    s32 i;

    for (i = 0; i < 4; i++) {
        player = GetPlayerStruct(i);
        player->turn_status = 0;
        player->flags &= ~0x2;
    }
}

void func_800F6F80_FirstMap(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_800546B4(i, GetPlayerStruct(i)->turn_status);
    }

}

void func_800F6FC4_FirstMap(void) {
    GW_PLAYER* temp_s0;
    GW_SYSTEM* gameStatus = &GwSystem;
    s32 i;

    if (++gameStatus->curPlayerIndex >= 4) {
        gameStatus->curPlayerIndex = 0;
    }

    for (i = 0; i < 4; i++) {
        func_80052FD4(i);
        func_80052E84(i);
        temp_s0 = GetPlayerStruct(i);
        func_8003E174(temp_s0->player_obj);
        temp_s0->player_obj->unk_0A |= 2;
        func_8004CC8C(i, GetAbsSpaceIndexFromChainSpaceIndex(temp_s0->cur_chain, temp_s0->cur_space));
        func_8004CDA0(i);
    }
}

void func_800F7090_FirstMap(Vec3f* coords) {
    func_8005884C(coords);
}

void func_800F70AC_FirstMap(void) {
    Process* temp_s0;

    temp_s0 = HuPrcCurrentGet();
    HuPrcChildLink(temp_s0, func_80048000(GwSystem.curPlayerIndex));
    HuPrcChildWatch();
}

void func_800F70F0_FirstMap(s16 arg0) {
    Process* temp_s0;
    GW_SYSTEM* gameStatus = &GwSystem;

    func_800415CC(gameStatus->curPlayerIndex, arg0);
    temp_s0 = HuPrcCurrentGet();
    HuPrcChildLink(temp_s0, func_800419D8(gameStatus->curPlayerIndex));
    HuPrcChildWatch();
}

// retail loads the first curPlayerIndex through %hi(GwSystem + 0x1C), the rest through the
// &GwSystem register: GCC CSEs the first one too (one instruction, masked 0 otherwise); tried gs assigned after the call, no gs local
#ifdef NON_MATCHING
void func_800F714C_FirstMap(void) {
    GW_SYSTEM* gs = &GwSystem;
    GW_PLAYER* player = GetPlayerStruct(-1);
    s16 spaceIdx = 0;
    BoardSpace* space;
    s16 steps;

    steps = func_800415E8(GwSystem.curPlayerIndex);
    SetPlayerAnimation(-1, 0, 2);
    if (steps == 0) {
        goto end;
    }
loop:
    {
        BoardSpaceGet(GetAbsSpaceIndexFromChainSpaceIndex(player->next_chain, player->next_space));
        if (((BoardPlayerObj*)player->player_obj)->unk_46 != 0) {
            SetPlayerAnimation(-1, 0, 2);
        }
        func_8004D6FC(gs->curPlayerIndex, 19.0f);
        player->cur_chain = player->next_chain;
        player->cur_space = player->next_space;
        player->next_space++;
        spaceIdx = GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain, player->cur_space);
        space = BoardSpaceGet(spaceIdx);
        SetCurrentSpaceIndex(spaceIdx);
        switch (space->spaceType) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 6:
            case 8:
            case 9:
                func_8004068C(gs->curPlayerIndex);
                steps--;
                SetSpaceStepAnim(spaceIdx);
                break;
        }
        if (steps != 0) {
            switch (space->spaceType) {
                case 1:
                case 2:
                case 3:
                case 4:
                case 6:
                case 8:
                case 9:
                    PlaySound(0x2F);
                    break;
                case 5:
                    PlaySound(0x5B);
                    break;
            }
        } else {
            switch (space->spaceType) {
                case 4:
                case 6:
                    PlaySound(0x4E);
                    break;
                case 1:
                    PlaySound(0x30);
                    break;
                case 2:
                    PlaySound(0x31);
                    break;
                case 9:
                    PlaySound(0x61);
                    break;
                case 3:
                case 8:
                    PlaySound(0x60);
                    break;
                case 5:
                    PlaySound(0x5B);
                    break;
            }
        }
        ExecuteEventForSpace(spaceIdx, 1);
        if (steps != 0) {
            goto loop;
        }
    }
end:
    SetPlayerAnimation(-1, -1, 2);
    ExecuteEventForSpace(spaceIdx, 3);
    {
        Vec3f sp10;

        func_8004CD84(&sp10);
        func_8004D1EC(&player->player_obj->unk_18, &sp10, &player->player_obj->unk_18, 8);
    }
    func_80055544(gs->curPlayerIndex);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_FirstMap/257020", func_800F714C_FirstMap);
#endif
void func_800F73A0_FirstMap(void) {
    GW_SYSTEM* gameStatus = &GwSystem;
    GW_PLAYER* player = GetPlayerStruct(CURRENT_PLAYER);
    BoardSpace* space = BoardSpaceGet(GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain, player->cur_space));

    SetPlayerLandedSpaceType(-1, space->spaceType);
    func_800546B4(gameStatus->curPlayerIndex, player->turn_status);

    switch (space->spaceType) {
    case 1:
        ShowPlayerCoinChange(gameStatus->curPlayerIndex, 3);
        func_80055960(gameStatus->curPlayerIndex, 3);
        PlaySound(0x30);
        HuPrcSleep(30);
        return;
    case 2:
        ShowPlayerCoinChange(gameStatus->curPlayerIndex, -3);
        func_80055960(gameStatus->curPlayerIndex, -3);
        PlaySound(0x31);
        HuPrcSleep(30);
        return;
    }
}

void func_800F7484_FirstMap(s16 arg0) {
    Process* temp_s0;
    GW_SYSTEM* gameStatus = &GwSystem;

    func_800415CC(gameStatus->curPlayerIndex, arg0);
    temp_s0 = HuPrcCurrentGet();
    HuPrcChildLink(temp_s0, func_80041C04(gameStatus->curPlayerIndex));
    HuPrcChildWatch();
}

void func_800F74E0_FirstMap(void) {
    func_800405DC(GwSystem.curPlayerIndex);
}

void func_800F7500_FirstMap(Object* arg0, void* arg1) {
    LoadStringIntoWindow(arg0->unk_08, arg1, -1, -1);
    func_80071C8C(arg0->unk_08, 1);
    func_8004E0E8(arg0->unk_08);
    func_80071E80(arg0->unk_08, 1);
    func_8006EB40(arg0->unk_08);
}

void func_800F7560_FirstMap(Object** arg0) {
    Object* temp_v0;

    temp_v0 = *arg0;
    temp_v0->unk_34 = 20.0f;
    temp_v0->unk_38 = -3.0f;
    MBMotionSet(*arg0, 0, 0U);
    HuPrcSleep(3);

    while (!(MBMotionCheck(*arg0))) {
        HuPrcVSleep();
    }
    
    MBMotionSet(*arg0, -1, 2);
}

void func_800F75F0_FirstMap(Object* arg0, s16 arg1) {
    Object* temp_v0;
    s32 i;
    s16 temp_s1;
    s16 new_var;

    temp_s1 = arg0->unk_0A;
    temp_v0 = arg0->prev;
    temp_v0->unk_34 = 20.0f;
    temp_v0->unk_38 = -2.5f;
    MBMotionSet(arg0->prev, 0, 0);
    new_var = (arg1 - temp_s1) / 14;

    for (i = 0; i < 14; i++) {
        temp_s1 = arg0->unk_0A;
        func_800484C4(arg0, temp_s1 + new_var);
        HuPrcVSleep();
    }
    
    func_800484C4(arg0, arg1);
    
    while (!(MBMotionCheck(arg0->prev))) {
        HuPrcVSleep();
    }
    
    MBMotionSet(arg0->prev, -1, 2);
}

void func_800F7714_FirstMap(void) {
    Process* process = HuPrcCurrentGet();
    Object** temp_s0 = process->user_data;

    while (1) {
        HuPrcVSleep();
        if (D_800F8808_FirstMap == -1) {
            continue;
        }
        
        MBMotionSet(*temp_s0, D_800F8808_FirstMap, 0);
        D_800F8808_FirstMap = -1;
        
        while (!(MBMotionCheck(*temp_s0))) {
            HuPrcVSleep();
        }
        
        MBMotionSet(*temp_s0, -1, 2);
    }
}

void func_800F77A8_FirstMap(s32 arg0) {
    D_800F8808_FirstMap = arg0;
}

void func_800F77B4_FirstMap(void) {
    Process* process;
    void* tips;

    process = HuPrcCurrentGet();
    GwCommon.boardWork[0] = 0;
    func_800F6B0C_FirstMap();
    D_800F88A4_FirstMap = func_80048224(D_800F87F8_FirstMap);
    func_8003E174(D_800F88A4_FirstMap->unk0);
    func_800484C4((Object*)D_800F88A4_FirstMap, 0x4A);
    omAddPrcObj(func_800F7714_FirstMap, 0x4800, 0, 0)->user_data = D_800F88A4_FirstMap;
    func_8006DA1C(D_800F88A4_FirstMap->unk8, 0x40, 0x40);
    func_800F6F38_FirstMap();
    func_800F6F80_FirstMap();
    HuPrcSleep(3);
    while (func_80072718() != 0) {
        HuPrcVSleep();
    }
    HuPrcSleep(3);
    func_800F7560_FirstMap(&D_800F88A4_FirstMap->unk0);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x214);
    func_800F70AC_FirstMap();
    func_800F70F0_FirstMap(1);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x215);
    func_800F714C_FirstMap();
    func_800F77A8_FirstMap(1);
    HuPrcVSleep();
    tips = func_800F6BC8_FirstMap(0, 0x64, 0x64);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x216);
    func_800F6DD8_FirstMap(tips);
    func_800F73A0_FirstMap();
    func_800F6B50_FirstMap();
    func_800F6FC4_FirstMap();
    func_800F7090_FirstMap(NULL);
    func_800F6B8C_FirstMap();
    func_800F6F80_FirstMap();
    func_800F70AC_FirstMap();
    func_800F70F0_FirstMap(4);
    func_800F714C_FirstMap();
    func_800F77A8_FirstMap(1);
    HuPrcVSleep();
    tips = func_800F6BC8_FirstMap(1, 0x64, 0x64);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x217);
    func_800F6DD8_FirstMap(tips);
    func_800F73A0_FirstMap();
    func_800F6B50_FirstMap();
    func_800F6FC4_FirstMap();
    func_800F7090_FirstMap(NULL);
    func_800F6B8C_FirstMap();
    func_800F6F80_FirstMap();
    func_800F70AC_FirstMap();
    func_800F70F0_FirstMap(6);
    func_800F714C_FirstMap();
    func_800F77A8_FirstMap(1);
    HuPrcVSleep();
    tips = func_800F6BC8_FirstMap(2, 0x64, 0x64);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x218);
    func_800F6DD8_FirstMap(tips);
    func_800F73A0_FirstMap();
    func_800F6B50_FirstMap();
    func_800F6FC4_FirstMap();
    func_800F7090_FirstMap(NULL);
    func_800F6B8C_FirstMap();
    func_800F6F80_FirstMap();
    func_800F70AC_FirstMap();
    func_800F70F0_FirstMap(9);
    func_800F714C_FirstMap();
    func_800F77A8_FirstMap(1);
    HuPrcVSleep();
    tips = func_800F6BC8_FirstMap(3, 0x64, 0x64);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x219);
    func_800F6DD8_FirstMap(tips);
    func_800F73A0_FirstMap();
    HuPrcSleep(0x1E);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x21A);
    func_800F6B50_FirstMap();
    func_800F6FC4_FirstMap();
    func_800F7090_FirstMap(NULL);
    func_800F6B8C_FirstMap();
    func_800F6F38_FirstMap();
    func_800F6F80_FirstMap();
    func_800F70AC_FirstMap();
    func_800F70F0_FirstMap(7);
    func_800F714C_FirstMap();
    func_800F77A8_FirstMap(1);
    HuPrcVSleep();
    tips = func_800F6BC8_FirstMap(4, 0x64, 0x64);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x21C);
    func_800F6DD8_FirstMap(tips);
    func_800F73A0_FirstMap();
    func_800F6B50_FirstMap();
    func_800F6FC4_FirstMap();
    func_800F7090_FirstMap(NULL);
    func_800F6B8C_FirstMap();
    func_800F6F80_FirstMap();
    func_800F70AC_FirstMap();
    func_800F70F0_FirstMap(6);
    func_800F714C_FirstMap();
    func_800F77A8_FirstMap(1);
    HuPrcVSleep();
    tips = func_800F6BC8_FirstMap(7, 0x64, 0x64);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x21D);
    func_800F6DD8_FirstMap(tips);
    func_800F73A0_FirstMap();
    func_800F6B50_FirstMap();
    func_800F6FC4_FirstMap();
    func_800F7090_FirstMap(NULL);
    func_800F6B8C_FirstMap();
    func_800F6F80_FirstMap();
    func_800F70AC_FirstMap();
    func_800F70F0_FirstMap(8);
    func_800F714C_FirstMap();
    func_800F77A8_FirstMap(1);
    HuPrcVSleep();
    tips = func_800F6BC8_FirstMap(6, 0x64, 0x64);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x21E);
    func_800F6DD8_FirstMap(tips);
    func_800F73A0_FirstMap();
    func_800F7484_FirstMap(4);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x220);
    func_800F74E0_FirstMap();
    func_800F7484_FirstMap(3);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x221);
    func_800F74E0_FirstMap();
    func_800F6B50_FirstMap();
    func_800F6FC4_FirstMap();
    func_800F7090_FirstMap(NULL);
    func_800F6B8C_FirstMap();
    func_800F6F80_FirstMap();
    func_800F7560_FirstMap(&D_800F88A4_FirstMap->unk0);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x222);
    func_800F70AC_FirstMap();
    func_800F70F0_FirstMap(6);
    func_800F714C_FirstMap();
    func_800F73A0_FirstMap();
    func_80054868(4);
    func_800F75F0_FirstMap((Object*)D_800F88A4_FirstMap, -0x28);
    while (func_80054FA8() != 0) {
        HuPrcVSleep();
    }
    func_800F77A8_FirstMap(2);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x223);
    HuPrcChildLink(process, func_800448A0());
    HuPrcChildWatch();
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x224);
    func_800546B4(0, 1);
    func_800546B4(1, 1);
    func_800546B4(2, 1);
    func_800546B4(3, 1);
    func_80054868(2);
    func_800550C4();
    while (func_80054FA8() != 0) {
        HuPrcVSleep();
    }
    func_800F77A8_FirstMap(2);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x225);
    func_80055228();
    func_800546B4(0, 2);
    func_800546B4(1, 1);
    func_800546B4(2, 2);
    func_800546B4(3, 1);
    func_80054868(2);
    func_800550C4();
    while (func_80054FA8() != 0) {
        HuPrcVSleep();
    }
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x226);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x227);
    func_80055228();
    func_800546B4(0, 1);
    func_800546B4(1, 2);
    func_800546B4(2, 2);
    func_800546B4(3, 2);
    func_80054868(2);
    func_800550C4();
    while (func_80054FA8() != 0) {
        HuPrcVSleep();
    }
    func_800F77A8_FirstMap(2);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x228);
    func_800546B4(0, 1);
    func_800546B4(1, 1);
    func_800546B4(2, 1);
    func_800546B4(3, 2);
    func_80054868(2);
    func_800550C4();
    while (func_80054FA8() != 0) {
        HuPrcVSleep();
    }
    func_800F77A8_FirstMap(2);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x229);
    HuPrcSleep(0xF);
    func_800F7560_FirstMap(&D_800F88A4_FirstMap->unk0);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x22A);
    func_80055228();
    HuPrcSleep(1);
    GwSystem.unk_1E = -1;
    func_8004388C(-1);
    func_80043D68();
    func_80054868(5);
    while (GwSystem.unk_1E == -1) {
        HuPrcVSleep();
    }
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x22B);
    func_80043544();
    func_800559BC();
    func_800F75F0_FirstMap((Object*)D_800F88A4_FirstMap, 0x69);
    func_800F7560_FirstMap(&D_800F88A4_FirstMap->unk0);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x22C);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x22D);
    func_800F6EF0_FirstMap(0x1C);
    func_800F6EFC_FirstMap();
    func_800F77A8_FirstMap(1);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x22E);
    PlaySound(0x466);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x22F);
    func_800F6EF0_FirstMap(0x1B);
    func_800F6EFC_FirstMap();
    func_800F77A8_FirstMap(1);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x232);
    PlaySound(0x90);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x233);
    func_800F6EF0_FirstMap(0x19);
    func_800F6EFC_FirstMap();
    func_800F77A8_FirstMap(1);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x230);
    PlaySound(0x432);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x231);
    func_800F6EF0_FirstMap(0x1A);
    func_800F6EFC_FirstMap();
    func_800F77A8_FirstMap(1);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x234);
    PlaySound(0xA0);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x235);
    func_800F7560_FirstMap(&D_800F88A4_FirstMap->unk0);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x236);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x237);
    HuPrcSleep(0x1E);
    func_800F7560_FirstMap(&D_800F88A4_FirstMap->unk0);
    func_800F7500_FirstMap((Object*)D_800F88A4_FirstMap, (void*)0x238);
    func_800601D4(0x3C);
    func_800726AC(2, 0x10);
    func_80072724(0xFF, 0xFF, 0xFF);
    HuPrcSleep(0x10);
    func_8004847C(D_800F88A4_FirstMap);
    func_80056AF4();
    func_80056984();
    omOvlReturnEx(1);
    omOvlKill();
    HuPrcVSleep();
}
s16 func_800F81F8_FirstMap(s32 arg0) {
    s16 temp_s1;
    s16 temp_s1_2;
    void* temp_s0;
    unk_Struct02* temp_s2;

    func_80060214(0x60);
    temp_s2 = func_800533F8(1, 0);
    temp_s0 = DataRead(0xA012A);
    *temp_s2->unk_0C = func_800678A4(temp_s0);
    func_80067208(temp_s2->unk_0A, 0, *temp_s2->unk_0C, 0);
    func_80067384(temp_s2->unk_0A, 0, 9);
    func_800674BC(temp_s2->unk_0A, 0, 0x1000);
    func_80066DC4(temp_s2->unk_0A, 0, 0xA0, 0x78);
    func_80067354(temp_s2->unk_0A, 0, 40.0f, 30.0f);
    func_80067558(temp_s2->unk_0A, 0, 0, 0, 0, 0xC0);
    DataClose(temp_s0);
    temp_s1_2 = func_8006D010(0x49, 0x4B, 0xB8, 0x4C, 0, 0);
    func_8006E0A4(temp_s1_2, 5);
    func_8006E154(temp_s1_2, 0);
    func_800717C0(temp_s1_2);
    LoadStringIntoWindow(temp_s1_2, (void* )0x209, -1, -1);
    func_8006E070(temp_s1_2, 0);

    while (func_8006FCC0(temp_s1_2) != 0) {
        HuPrcVSleep();
    }
    
    func_8007155C(temp_s1_2, (0x10000 << arg0) >> 0x10);
    temp_s1 = func_8006FCF0(temp_s1_2, 0, 0);
    func_80070D90(temp_s1_2);
    func_80060214(0x7F);
    func_80053454(temp_s2);
    return temp_s1 == 1;
}

void func_800F83D4_FirstMap(void) {
    Vec2f coords;
    s32 playerIndex;
    s32 i;

    while (1) {
        HuPrcVSleep();
        if (func_80072718() != 0) {
            continue;
        }
        if (D_800ED0D2 == 3) {
            continue;
        }
    
        playerIndex = GetCurrentPlayerIndex();
    
        for (i = 0; i < 4; i++) {
            if (ContDStkTrg[i] & 0x1000) {
                func_80041F84(playerIndex);
                func_8004B6D8(&coords);
                func_8004B61C(&coords);
                D_800ECC22 = 1;
                func_8005FD7C();
                D_800F384E = 1;
                if (func_800F81F8_FirstMap(i) != 0) {
                    func_800601D4(0x5A);
                    func_800726AC(0, 0x10);
                    HuPrcSleep(0x11);
                    func_80056AF4();
                    func_80056984();
                    omOvlReturnEx(1);
                    omOvlKill();
                    HuPrcVSleep();                
                }
                
                D_800F384E = 0;
                func_8005FECC();
                D_800ECC22 = 0;
                func_80041FE0(playerIndex);
                break;
            }
        }        
    }
}

void func_800F852C_FirstMap(void) {
    GW_PLAYER* player;
    s32 i;
    s16 absSpaceIndex;

    func_80060128(0x2A);
    InitCameras(2);
    omInitObjMan(0x50, 0x28);
    func_80060088();
    func_80023448(1);
    func_800234B8(0, 0x78, 0x78, 0x78);
    func_800234B8(1, 0x40, 0x40, 0x60);
    func_80023504(1, -100.0f, 100.0f, 300.0f);
    func_80056A08(0x4D, 0x4D, 0, 0);
    func_80052E84(0);
    func_80052E84(1);
    func_80052E84(2);
    func_80052E84(3);

    for (i = 0; i < 4; i++) {
        player = GetPlayerStruct(i);
        func_8003E174(player->player_obj);
        player->player_obj->unk_0A |= 2;
        player->coins = 0xA;
    }

    func_800F676C_FirstMap();
    func_800F67F4_FirstMap();
    func_800F68A4_FirstMap();
    func_800F692C_FirstMap();
    EventTableHydrate(D_800F87A8_FirstMap);
    
    for (i = 0; i < 4; i++) {
        player = GetPlayerStruct(i);
        absSpaceIndex = GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain, player->cur_space);
        func_8004CC8C(i, absSpaceIndex);
        func_8004CDA0(i);
    }
    
    func_8004A510();
    func_8004B5C4(1.0f);
    func_8004B838(-1.0f);
    func_8004B5DC(&GetPlayerStruct(CURRENT_PLAYER)->player_obj->coords);
    omAddPrcObj(func_800F77B4_FirstMap, 0x1005, 0, 0);
    omAddPrcObj(func_800F6E20_FirstMap, 0x1005, 0, 0);
    omPrcSetStatBit(omAddPrcObj(func_800F83D4_FirstMap, 0x1005, 0, 0), 0x80);
}

