#include "common.h"
#include "engine/process.h"
#include "spaces.h"
Vec2f D_800C51C0[] = { { -60.0f, -60.0f }, { 60.0f, -60.0f }, { -60.0f, 60.0f }, { 60.0f, 60.0f } };
Vec2f D_800C51E0[] = { { -40.0f, -40.0f }, { 40.0f, -40.0f }, { -40.0f, 40.0f }, { 40.0f, 40.0f } };
s32 D_800C5200[] = { 60, 25, 10 };

typedef struct unkProcessUserDataStruct {
    Vec3f unk_00;
    Vec3f unk_0C;
    Vec3f* unk_18;
    union {
        f32 floatUnk1C;
        s32 signed32Unk1C;
    } unk_1C;
} unkProcessUserDataStruct;

extern s8 ContStkY[];

void func_8004CB70(s16 arg0, s16 arg1, Vec3f* arg2) {
    BoardSpace* temp_v0;

    temp_v0 = BoardSpaceGet(arg1);
    arg2->x = temp_v0->coords.x;
    arg2->y = temp_v0->coords.y;
    arg2->z = temp_v0->coords.z;
    if (arg0 != -1) {
        if (PlayerIsCurrent(arg0) == 0) {
            arg2->x = arg2->x + D_800C51C0[arg0].x;
            arg2->z = arg2->z + D_800C51C0[arg0].y;
        }
    }
}

void func_8004CC14(s16 arg0, s16 arg1, Vec3f* arg2) {
    BoardSpace* space;

    space = BoardSpaceGet(arg1);
    arg2->x = (space->coords.x + D_800C51E0[arg0].x);
    arg2->y = space->coords.y;
    arg2->z = (space->coords.z + D_800C51E0[arg0].y);
}

void func_8004CC8C(s16 arg0, s16 arg1) {
    func_8004CB70(arg0, arg1, &GwPlayer[arg0].player_obj->coords);
}

void func_8004CCD0(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2) {
    func_800A0E80(arg2, arg1, arg0);
    func_8003D408(arg2);
}

void func_8004CD08(s16 arg0, Vec3f* arg1) {
    Object* playerObject;

    playerObject = GetPlayerStruct(arg0)->player_obj;
    func_8004CCD0(&playerObject->coords, arg1, &playerObject->unk_18);
}

void func_8004CD48(Object* arg0, s16 arg1) {
    func_8004CCD0(&arg0->coords, &BoardSpaceGet(arg1)->coords, &arg0->unk_18);
}

void func_8004CD84(Vec3f* arg0) {
    arg0->x = 0.0f;
    arg0->y = 0.0f;
    arg0->z = 1.0f;
}

void func_8004CDA0(s16 arg0) {
    func_8004CD84(&GetPlayerStruct(arg0)->player_obj->unk_18);
}

void func_8004CDCC(Object* unk) {
    Vec3f sp10;
    Vec3f sp20;
    Vec3f* temp_s2;

    temp_s2 = &unk->coords;
    func_800A0E80(&sp10, &D_800C3110->pos, temp_s2);
    func_800A0D00(&sp20, sp10.x, 0.0f, sp10.z);
    unk->unk_3C->unk_24 = -func_8003D8CC(&sp10, &sp20);
    func_8004CCD0(temp_s2, &D_800C3110->pos, &sp10);
    unk->unk_3C->unk28 = func_8003D2B0(&sp10);
    unk->unk_3C->unk_2C = 0.0f;
}

void SwapPlayerLocationData(s16 arg0, s16 arg1) {
    GW_PLAYER* player1;
    GW_PLAYER* player2;
    u16 temp;

    player1 = GetPlayerStruct(arg0);
    player2 = GetPlayerStruct(arg1);
    temp = player1->cur_chain;
    player1->cur_chain = player2->cur_chain;
    player2->cur_chain = temp;
    temp = player1->cur_space;
    player1->cur_space = player2->cur_space;
    player2->cur_space = temp;
    temp = player1->next_chain;
    player1->next_chain = player2->next_chain;
    player2->next_chain = temp;
    temp = player1->next_space;
    player1->next_space = player2->next_space;
    player2->next_space = temp;
}

void SetPlayerLandedSpaceType(s16 playerIndex, s16 spaceType) {
    GW_PLAYER* player = GetPlayerStruct(playerIndex);
    s32 spaceTemp;
    
    switch(--spaceType) {
        case 0:
        case 2:
        case 5:
        case 6:
        case 7:
            spaceTemp = 1;
            break;
        case 1:
        case 8:
            spaceTemp = 2;
            break;

        case 3:
            spaceTemp = 4;
            break;
        default:
            spaceTemp = 0;
            break;
    }
    
    player->turn_status = spaceTemp;
}

s16 GetSumOfPlayerStars(void) {
    s32 starTotal = 0;
    s32 i;

    for (i = 0; i < MAX_PLAYERS; i++) {
        starTotal += GetPlayerStruct(i)->stars;
    }
    
    return starTotal;
}

s16 RNGPercentChance(s8 arg0) {
    return arg0 > ((rand8() * 99) >> 8);
}

s16 GetTurnsElapsed(void) {
    GW_SYSTEM* gameStatus = &GwSystem;
    return gameStatus->maxTurns - gameStatus->currentTurn + 1;
}

s32 func_8004D02C(s16 arg0, f32 arg1) {
    Vec3f sp10;

    sp10.x = ContStkX[arg0];
    sp10.y = 0.0f;
    sp10.z = ContStkY[arg0];
    
    if ((arg1 <= func_800A1200(&sp10))) {
        return 1;
    } else {
        return 0;
    }
}

void func_8004D0B0(s16 arg0) {
    func_8004DB9C(D_800C5200[arg0]);
}

void func_8004D0DC(void) {
    unkProcessUserDataStruct *temp_s0 = HuPrcCurrentGet()->user_data;
    s32 temp_s1 = temp_s0->unk_1C.signed32Unk1C;
    f32 temp_f20 = func_8003D2B0(&temp_s0->unk_00);
    f32 new_var = func_8003D2B0(&temp_s0->unk_0C) - temp_f20;
    f32 var_f2;
    
    
    if (new_var < 0.0f) {
        new_var += 360.0f;
    }
    
    var_f2 = func_8003D8CC(&temp_s0->unk_00, &temp_s0->unk_0C) / temp_s1;
    
    if (!(new_var < 180.0f)) {
        var_f2 = -var_f2;
    }
    
    new_var = var_f2;
    temp_f20 = 0.0f;
    
    while (temp_s0->unk_1C.signed32Unk1C != 0) {
        func_800A0D50(temp_s0->unk_18, &temp_s0->unk_00);
        temp_f20 += new_var;
        func_8003D514(temp_s0->unk_18, temp_f20);
        temp_s0->unk_1C.signed32Unk1C = temp_s0->unk_1C.signed32Unk1C - 1;
        HuPrcVSleep();
    }
    
    EndProcess(0);
}

Process* func_8004D1EC(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2, s32 arg3) {
    Process* temp_s1;
    unkProcessUserDataStruct* temp_s0;

    temp_s1 = omAddPrcObj(func_8004D0DC, 0x4001, 0, 0x50);
    temp_s0 = HuMemMemoryAlloc(temp_s1->heap, sizeof(unkProcessUserDataStruct));
    temp_s1->user_data = temp_s0;
    func_800A0D00(temp_s0, arg0->x, 0.0f, arg0->z);
    func_800A0D00(&temp_s0->unk_0C, arg1->x, 0.0f, arg1->z);
    temp_s0->unk_18 = arg2;
    temp_s0->unk_1C.signed32Unk1C = arg3;
    return temp_s1;
}

void func_8004D2A4(s16 arg0, s32 arg1, s16 arg2) {
    Vec3f sp10;
    Vec3f* temp_a2;
    GW_PLAYER* temp_s1;

    temp_s1 = GetPlayerStruct(arg0);
    func_800A0E80(&sp10, &BoardSpaceGet(arg2)->coords, &temp_s1->player_obj->coords);
    func_8003D408(&sp10);
    temp_a2 = &temp_s1->player_obj->unk_18;
    func_8004D1EC(temp_a2, &sp10, temp_a2, arg1);
}

void func_8004D328(void) {
    unkProcessUserDataStruct* temp_s0 = HuPrcCurrentGet()->user_data;
    s32 temp_s1 = temp_s0->unk_1C.signed32Unk1C;

    while (temp_s0->unk_1C.signed32Unk1C != 0) {
        func_800A0E80(temp_s0->unk_18, &temp_s0->unk_0C, &temp_s0->unk_00);
        func_800A0F00(temp_s0->unk_18, 1.0f - (1.0f / temp_s1) * (temp_s0->unk_1C.signed32Unk1C - 1), temp_s0->unk_18);
        func_800A0E00(temp_s0->unk_18, temp_s0->unk_18, &temp_s0->unk_00);
        temp_s0->unk_1C.signed32Unk1C = temp_s0->unk_1C.signed32Unk1C - 1;
        HuPrcVSleep();        
    }
    EndProcess(NULL);
}

Process* func_8004D3F4(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2, s32 arg3) {
    Process* temp_s1;
    unkProcessUserDataStruct* temp_s0;

    temp_s1 = omAddPrcObj(func_8004D328, 0x4001, 0, 0x50);
    temp_s0 = HuMemMemoryAlloc(temp_s1->heap, sizeof(*temp_s0)); /* 0x20 on the N64; a pointer field */
    temp_s1->user_data = temp_s0;
    temp_s0->unk_00 = *arg0;
    temp_s0->unk_0C = *arg1;
    temp_s0->unk_18 = arg2;
    temp_s0->unk_1C.signed32Unk1C = arg3;
    return temp_s1;
}


void func_8004D4A8(s16 arg0, s32 arg1) {
    Vec3f sp10;
    Vec3f sp20;
    GW_PLAYER* temp_v0;
    Process* process;

    temp_v0 = GetPlayerStruct(arg0);
    func_8004CB70(arg0, GetAbsSpaceIndexFromChainSpaceIndex(temp_v0->cur_chain, temp_v0->cur_space), &sp10);
    func_8004CB70(arg0, GetAbsSpaceIndexFromChainSpaceIndex(temp_v0->next_chain, temp_v0->next_space), &sp20);
    func_8004CCD0(&sp10, &sp20, &temp_v0->player_obj->unk_18);
    process = func_8004D3F4(&sp10, &sp20, &temp_v0->player_obj->coords, arg1);
    HuPrcChildLink(HuPrcCurrentGet(), process);
    HuPrcChildWatch();
}

void func_8004D580(void) {
    unkProcessUserDataStruct* temp_s0 = HuPrcCurrentGet()->user_data;
    Vec3f* temp_s1;
    f32 temp_f20;
    
    temp_f20 = temp_s0->unk_1C.floatUnk1C;
    temp_s1 = &temp_s0->unk_0C;
    
    while (!(func_800A13C0(&temp_s0->unk_00, temp_s1) < temp_f20)) {
        func_800A0E80(temp_s0->unk_18, temp_s1, &temp_s0->unk_00);
        func_8003D408(temp_s0->unk_18);
        func_800A0F00(temp_s0->unk_18, temp_f20, temp_s0->unk_18);
        func_800A0E00(temp_s0->unk_18, temp_s0->unk_18, &temp_s0->unk_00);
        func_800A0D50(&temp_s0->unk_00, temp_s0->unk_18);
        HuPrcVSleep();
    }
    func_800A0D50(temp_s0->unk_18, &temp_s0->unk_0C);
    EndProcess(NULL);
}

Process* func_8004D648(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2, f32 arg3) {
    Process* temp_s1;
    unkProcessUserDataStruct* temp_s0;

    temp_s1 = omAddPrcObj(func_8004D580, 0x4001, 0, 0x50);
    temp_s0 = HuMemMemoryAlloc(temp_s1->heap, sizeof(*temp_s0)); /* 0x20 on the N64; a pointer field */
    temp_s1->user_data = temp_s0;
    temp_s0->unk_00 = *arg0;
    temp_s0->unk_0C = *arg1;
    temp_s0->unk_18 = arg2;
    temp_s0->unk_1C.floatUnk1C = arg3;
    return temp_s1;
}

void func_8004D6FC(s16 arg0, f32 arg1) {
    Vec3f sp10;
    Vec3f sp20;
    GW_PLAYER* temp_v0;
    Process* process;

    temp_v0 = GetPlayerStruct(arg0);
    func_8004CB70(arg0, GetAbsSpaceIndexFromChainSpaceIndex(temp_v0->cur_chain, temp_v0->cur_space), &sp10);
    func_8004CB70(arg0, GetAbsSpaceIndexFromChainSpaceIndex(temp_v0->next_chain, temp_v0->next_space), &sp20);
    func_8004CCD0(&sp10, &sp20, &temp_v0->player_obj->unk_18);
    process = func_8004D648(&sp10, &sp20, &temp_v0->player_obj->coords, arg1);
    HuPrcChildLink(HuPrcCurrentGet(), process);
    HuPrcChildWatch();
}

void SetPlayerOntoChain(s16 player, s16 chain_index, s16 space_index) {
    GW_PLAYER* temp_v1 = GetPlayerStruct(player);

    if (chain_index >= 0) {
        temp_v1->cur_chain = chain_index;
        temp_v1->next_chain = chain_index;
    }
    if (space_index >= 0) {
        temp_v1->cur_space = space_index;
        temp_v1->next_space = space_index + 1;
    }
}

void SetNextChainAndSpace(s16 arg0, s16 arg1, s16 arg2) {
    GW_PLAYER* temp_v0 = GetPlayerStruct(arg0);

    if (arg1 >= 0) {
        temp_v0->next_chain = arg1;
    }
    if (arg2 >= 0) {
        temp_v0->next_space = arg2;
    }
}

s32 func_8004D8A4(void) {
    GW_SYSTEM* gameStatus = &GwSystem;
    s32 var_s0 = 0;
    
    SetBoardFeatureFlag(GwSystem.unk_1A);
    SetBoardFeatureFlag(0x4E);
    if (_CheckFlag(0x43) != 0) {
        if ((gameStatus->curBoardIndex != 7) || GwSystem.chosenStarSpaceIndex == 6) {
            func_80056730(-2, 4, 0x92);
            var_s0 = 1;
        }
    }
    return var_s0;
}

const char pad_4d770[] = "\0\0\0\0\0\0\0"; //TODO: this is required likely because of a bad split