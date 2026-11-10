#include "EternalStar.h"


Vec4f D_800F8BB0_EternalStar = {0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT};
s16 D_800F8BC0_EternalStar[] = {0x0046, 0x0047, 0x0048, 0x0049, 0x004A, 0x004B, 0x004C};
s16 D_800F8BD0_EternalStar[] = {0x0055, 0x0054, 0x0053, 0x0052, 0x0051, 0x0050, 0x004F};
s16 D_800F8BE0_EternalStar[] = {0x0001, 0x0009, 0x0008, 0x0007, 0x0006, 0x0005, 0x0004};
s32 D_800F8BF0_EternalStar[] = {0x00000001, 0x000A00E8};
s16 D_800F8BF8_EternalStar[] = {0x0001, 0x0009, 0x0008, 0x0007, 0x0006, 0x0005, 0x0004, 0x0000};
s16 D_800F8C08_EternalStar[] = {0x0046, 0x0047, 0x0048, 0x0049, 0x004A, 0x004B, 0x004C};
my_struct D_800F8C18_EternalStar[] = {
    {2, 8},
    {-2, 2},
    {3, -1},
    {5, 0},
    {7, 0},
    {0, -5},
    {4, -5}
};
s16 D_800F8C34_EternalStar[] = {0};
s32 D_800F8C38_EternalStar[] = {0x00000001, 0x000A006C};
DecisionTreeNonLeafNode D_800F8C40_EternalStar[4] = { { 0x05000000, {(void*) 0x00000001}, {0x00005541} }, { 0x05000000, {(void*) 0x00000002}, {0x00005A46} }, {0x05000000, { (void*) 0x00000004}, {0x00005F4B} }, { 0x00000000, {0x00000000}, {0x00006450} } };
DecisionTreeNonLeafNode D_800F8C70_EternalStar[4] = { { 0x05000000, {(void*) 0x00000001}, {0x00005041} }, { 0x05000000, {(void*) 0x00000002}, {0x00005546} }, {0x05000000, { (void*) 0x00000004}, {0x00005A4B} }, { 0x00000000, {0x00000000}, {0x00005F55} } };
DecisionTreeNonLeafNode D_800F8CA0_EternalStar[4] = { { 0x05000000, {(void*) 0x00000001}, {0x00004650} }, { 0x05000000, {(void*) 0x00000002}, {0x00004B55} }, {0x05000000, { (void*) 0x00000004}, {0x0000505A} }, { 0x00000000, {0x00000000}, {0x0000555F} } };
DecisionTreeNonLeafNode D_800F8CD0_EternalStar[4] = { { 0x05000000, {(void*) 0x00000001}, {0x00005541} }, { 0x05000000, {(void*) 0x00000002}, {0x00005041} }, {0x05000000, { (void*) 0x00000004}, {0x00004B3C} }, { 0x00000000, {0x00000000}, {0x00004637} } };
DecisionTreeNonLeafNode D_800F8D00_EternalStar[4] = { { 0x05000000, {(void*) 0x00000001}, {0x00004B5A} }, { 0x05000000, {(void*) 0x00000002}, {0x00004650} }, {0x05000000, { (void*) 0x00000004}, {0x00004146} }, { 0x00000000, {0x00000000}, {0x00003C3C} } };
DecisionTreeNonLeafNode D_800F8D30_EternalStar[4] = { { 0x05000000, {(void*) 0x00000001}, {0x0000141E} }, { 0x05000000, {(void*) 0x00000002}, {0x00000A1E} }, {0x05000000, { (void*) 0x00000004}, {0x00000514} }, { 0x00000000, {0x00000000}, {0x0000000A} } };
DecisionTreeNonLeafNode D_800F8D60_EternalStar[1] = { { 0x00000000, {0x00000000}, {0x00003232} } };
s16 (*D_800F8D6C_EternalStar[16])() = {func_800F753C_EternalStar, func_800F7564_EternalStar, func_800F758C_EternalStar, func_800F75B4_EternalStar, func_800F75DC_EternalStar, func_800F753C_EternalStar, func_800F7608_EternalStar, func_800F7630_EternalStar, func_800F7658_EternalStar, func_800F7684_EternalStar, func_800F753C_EternalStar, func_800F76B0_EternalStar, func_800F76D8_EternalStar, func_800F7704_EternalStar, func_800F7730_EternalStar, func_800F753C_EternalStar};
/* Was a flat s32[]; it is walked as decision-tree nodes (RunDecisionTree), which are wider on
   the host. Same bytes on the N64. */
DecisionTreeNonLeafNode D_800F8DAC_EternalStar[4] = { { 0x05000000, {(void*) 0x00000001}, {0x00015541} }, { 0x05000000, {(void*) 0x00000002}, {0x00015A46} }, { 0x05000000, {(void*) 0x00000004}, {0x00015F4B} }, { 0x00000000, {0x00000000}, {0x00016450} } };
DecisionTreeNonLeafNode D_800F8DDC_EternalStar[2] = { { 0x06000000, {func_800F7B6C_EternalStar}, {0x00016464} },               { 0x00000000, {0x00000000},           {0x00006464} } };
DecisionTreeNonLeafNode D_800F8DF4_EternalStar[3] = { { 0x02000000, {(void*) 0x00000004},   {(u32) D_800F8DAC_EternalStar} },  { 0x06000000, {func_800F7BA0_EternalStar}, {0x00016464} }, { 0x00000000, {0x00000000}, {0x00006464} } };
DecisionTreeNonLeafNode D_800F8E18_EternalStar[2] = { { 0x06000000, {func_800F7BD4_EternalStar}, {0x00016464} },               { 0x00000000, {0x00000000},           {0x00006464} } };
DecisionTreeNonLeafNode D_800F8E30_EternalStar[3] = { { 0x02000000, {(void*) 0x00000010},   {(u32) D_800F8DAC_EternalStar} },  { 0x06000000, {func_800F7C08_EternalStar}, {0x00016464} }, { 0x00000000, {0x00000000}, {0x00006464} } };
DecisionTreeNonLeafNode D_800F8E54_EternalStar[3] = { { 0x02000000, {(void*) 0x00000040},   {(u32) D_800F8DAC_EternalStar} },  { 0x06000000, {func_800F7C3C_EternalStar}, {0x00016464} }, { 0x00000000, {0x00000000}, {0x00006464} } };
s16 D_800F8E78_EternalStar[] = {0x0002, 0x0002, 0x0002, 0x0000};
s16 D_800F8E80_EternalStar[] = {0x000D, 0x000D, 0x000D, 0x0000};
s16 D_800F8E88_EternalStar[] = {0x0005, 0x000A, 0x0013, 0x0000};
s16 D_800F8E90_EternalStar[] = {0x0013, 0x0005, 0x0006, 0x0000};
s16 D_800F8E98_EternalStar[] = {0x000A, 0x0014, 0x0011, 0x0000};
s16 D_800F8EA0_EternalStar[] = {0x0010, 0x0013, 0x000A, 0x0000};
s16 D_800F8EA8_EternalStar[] = {0x0014, 0x0010, 0x0014, 0x0000};
s16 D_800F8EB0_EternalStar[] = {0x0011, 0x0011, 0x0010, 0x0000};
s16 D_800F8EB8_EternalStar[] = {0x0013, 0x0006, 0x0005, 0x0000};
s16 D_800F8EC0_EternalStar[] = {0x0006, 0x0013, 0x0013, 0x0000};
s16 D_800F8EC8_EternalStar[] = {0x0013, 0x0013, 0x0013, 0x0000};
s16 D_800F8ED0_EternalStar[] = {0x0013, 0x0013, 0x0013, 0x0000};
s16* D_800F8ED8_EternalStar[] = {D_800F8E78_EternalStar, D_800F8E80_EternalStar, D_800F8E88_EternalStar, D_800F8E90_EternalStar, D_800F8E98_EternalStar, D_800F8EA0_EternalStar, D_800F8EA8_EternalStar, D_800F8EB0_EternalStar, D_800F8EB8_EternalStar, D_800F8EC0_EternalStar, D_800F8EC8_EternalStar, D_800F8ED0_EternalStar};
s16 D_800F8F08_EternalStar[] = {0x0042, 0x004D, 0x0044, 0x0045, 0x0049, 0x004A, 0x0062, 0x0063, 0x005E, 0x005F, 0x0060, 0x004B};

EventListEntry D_800F8F20_EternalStar[] = {
    {1, 2, func_800F8130_EternalStar},
    {0, 0, 0}
};

EventListEntry D_800F8F30_EternalStar[] = {
    {1, 2, func_800F8240_EternalStar},
    {2, 2, func_800F8298_EternalStar},
    {0, 0, 0}
};

EventListEntry D_800F8F48_EternalStar[] = {
    {3, 1, func_800F8514_EternalStar},
    {4, 2, func_800F8588_EternalStar},
    {0, 0, 0}
};

s16 D_800F8F60_EternalStar[] = {0x0027, 0x003E, -1, 0};
EventTableUnkStruct D_800F8F68_EternalStar = {D_800F8F60_EternalStar, D_800F8DDC_EternalStar, 0x0001, 0x0000};

EventListEntry D_800F8F74_EternalStar[] = {
    {1, 2, func_800F88EC_EternalStar},
    {0, 0, 0}
};

s16 D_800F8F84_EternalStar[] = {0x0029, 0x0026, -1, 0};
EventTableUnkStruct D_800F8F8C_EternalStar = {D_800F8F84_EternalStar, D_800F8DF4_EternalStar, 3, 4};

EventListEntry D_800F8F98_EternalStar[] = {
    {1, 2, func_800F8914_EternalStar},
    {0, 0, 0}
};

s16 D_800F8FA8_EternalStar[] = {0x0049, 0x0036, -1, 0};
EventTableUnkStruct D_800F8FB0_EternalStar = {D_800F8FA8_EternalStar, D_800F8E18_EternalStar, 0x0009, 0x0008};


EventListEntry D_800F8FBC_EternalStar[] = {
    {1, 2, func_800F893C_EternalStar},
    {0, 0, 0}
};

s16 D_800F8FCC_EternalStar[] = {0x0063, 0x001F, -1, 0};
EventTableUnkStruct D_800F8FD4_EternalStar = {D_800F8FCC_EternalStar, D_800F8E30_EternalStar, 0x000C, 0x000B};

EventListEntry D_800F8FE0_EternalStar[] = {
    {1, 2, func_800F8964_EternalStar},
    {0, 0, 0}
};

s16 D_800F8FF0_EternalStar[] = {16, 15, -1, 0};
EventTableUnkStruct D_800F8FF8_EternalStar = {D_800F8FF0_EternalStar, D_800F8E54_EternalStar, 0x000F, 0x000E};

EventListEntry D_800F9004_EternalStar[] = {
    {1, 2, func_800F898C_EternalStar},
    {0, 0, 0}
};

EventListEntry D_800F9014_EternalStar[] = {
    {1, 1, func_800F89B4_EternalStar},
    {0, 0, 0}
};

EventListEntry D_800F9024_EternalStar[] = {
    {1, 1, func_800F89D8_EternalStar},
    {0, 0, 0}
};

EventListEntry D_800F9034_EternalStar[] = {
    {1, 1, func_800F89FC_EternalStar},
    {0, 0, 0}
};

EventListEntry D_800F9044_EternalStar[] = {
    {1, 1, func_800F8A30_EternalStar},
    {3, 1, func_800F8A94_EternalStar},
    {0, 0, 0}
};

EventTableEntry D_800F905C_EternalStar[] = {
    {0x0055, D_800F9044_EternalStar},
    {0x0054, D_800F9044_EternalStar},
    {0x0053, D_800F9044_EternalStar},
    {0x0052, D_800F9044_EternalStar},
    {0x0051, D_800F9044_EternalStar},
    {0x0050, D_800F9044_EternalStar},
    {0x004F, D_800F9044_EternalStar},
    {0x0042, D_800F8F20_EternalStar},
    {0x004D, D_800F8F20_EternalStar},
    {0x0044, D_800F8F20_EternalStar},
    {0x0045, D_800F8F20_EternalStar},
    {0x0049, D_800F8F20_EternalStar},
    {0x004A, D_800F8F20_EternalStar},
    {0x0062, D_800F8F20_EternalStar},
    {0x0063, D_800F8F20_EternalStar},
    {0x005E, D_800F8F20_EternalStar},
    {0x005F, D_800F8F20_EternalStar},
    {0x0060, D_800F8F20_EternalStar},
    {0x004B, D_800F8F20_EternalStar},
    {0x002A, D_800F8F48_EternalStar},
    {0x0034, D_800F8F48_EternalStar},
    {0x000E, D_800F8F48_EternalStar},
    {0x001A, D_800F8F48_EternalStar},
    {0x0059, D_800F8F74_EternalStar},
    {0x005C, D_800F8F98_EternalStar},
    {0x0035, D_800F8FBC_EternalStar},
    {0x005B, D_800F8FE0_EternalStar},
    {0x005A, D_800F9004_EternalStar},
    {0x000A, D_800F9014_EternalStar},
    {0x002C, D_800F9024_EternalStar},
    {0x002E, D_800F9024_EternalStar},
    {0x0057, D_800F8F30_EternalStar},
    {0xFFFF, 0x00000000}
};

EventTableEntry D_800F9164_EternalStar[] = {
    {0x0056, D_800F9034_EternalStar},
    {0xFFFF, 0x00000000},
    {0x0000, 0x00000000}
};

void func_8004DBD4(s32, u8);

s16 func_800F6610_EternalStar(void) {
    s16 cur_space = GetCurrentSpaceIndex();
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800F8BE0_EternalStar); i++) {
        if (cur_space == D_800F8BD0_EternalStar[i]) {
            return D_800F8BE0_EternalStar[i];
        }
    }
    return D_800F8BE0_EternalStar[0];
}

void func_800F667C_EternalStar(void) {
    ClearBoardFeatureFlag(0x46);
    ClearBoardFeatureFlag(0x47);
    ClearBoardFeatureFlag(0x48);
    ClearBoardFeatureFlag(0x49);
    ClearBoardFeatureFlag(0x4A);
    ClearBoardFeatureFlag(0x4B);
    ClearBoardFeatureFlag(0x4C);
}

void func_800F66C8_EternalStar(void) {
    GW_SYSTEM* gameStatus = &GwSystem;
    if (++gameStatus->chosenStarSpaceIndex >= ARRAY_COUNT(gameStatus->starSpaces)) {
        gameStatus->chosenStarSpaceIndex = 0;
        SetBoardFeatureFlag(0x44);
        func_800F667C_EternalStar();
    }
}

void func_800F671C_EternalStar(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800F8BD0_EternalStar); i++) {
        if (_CheckFlag(D_800F8BC0_EternalStar[i])) {
            BoardSpaceTypeSet(D_800F8BD0_EternalStar[i], 6);
        } else {
            BoardSpaceTypeSet(D_800F8BD0_EternalStar[i], 5);
        }
    }
}

s16 func_800F67AC_EternalStar(s16 arg0) {
    GW_SYSTEM* gameStatus = &GwSystem;
    s32 i;
    
    for (i = 0; i < ARRAY_COUNT(D_800F8BD0_EternalStar); i++) {
        if (arg0 != D_800F8BD0_EternalStar[i]) {
            continue;
        } else {
            if (_CheckFlag(D_800F8BC0_EternalStar[i]) != 0) {
                return 2;
            } else {
                gameStatus->unk_1A = D_800F8BC0_EternalStar[i];
                return 1;
            }
        }
    }
    return 0;
}

void func_800F6850_EternalStar(void) {
    func_8001D494(1, 40.0f, 80.0f, 8000.0f);
    func_8001D420(1, &D_800F9180_EternalStar, &D_800F918C_EternalStar, &D_800F9198_EternalStar);
    func_8001D57C(1);
    func_8001D520(1, &D_800F91A4_EternalStar, &D_800F91B0_EternalStar);
}

void func_800F68B8_EternalStar(void) {
    while (1) {
        func_800F6850_EternalStar();
        HuPrcVSleep();   
    }
}

ProcessHeader* func_800F68E4_EternalStar(s32* arg0) {
    Process* process;
    Object* temp_v0;
    ProcessHeader* temp_s0;

    temp_s0 = (ProcessHeader*)MallocTemp(sizeof(ProcessHeader));
    if (temp_s0 != NULL) {
        temp_v0 = MBModelCreate(0x7B, arg0);
        temp_s0->prev = temp_v0;
        func_800A0D00(&temp_v0->xScale, 0.5f, 0.5f, 0.5f);
        func_80025F10(*temp_s0->prev->unk_3C->unk_40, 2);
        process = omAddPrcObj(&func_800F68B8_EternalStar, 0x4000, 0, 0);
        temp_s0->process = process;
        process->user_data = temp_s0;
        temp_s0->unk_0A = 0x69;
        D_800F9180_EternalStar.x = 0;
        D_800F9180_EternalStar.y = 0;
        D_800F9180_EternalStar.z = 600.0f;
        D_800F918C_EternalStar.x = 0;
        D_800F918C_EternalStar.y = 0;
        D_800F918C_EternalStar.z = 0;
        D_800F9198_EternalStar.x = 0;
        D_800F9198_EternalStar.y = 1.0f;
        D_800F9198_EternalStar.z = 0;
        D_800F91A4_EternalStar.x = 1280.0f;
        D_800F91A4_EternalStar.y = 960.0f;
        D_800F91A4_EternalStar.z = 511.0f;
        D_800F91B0_EternalStar.x = 240.0f;
        D_800F91B0_EternalStar.y =  temp_s0->unk_0A * 4.0f + 480.0f;
        D_800F91B0_EternalStar.z = 511.5f;
        func_800F6850_EternalStar();
        temp_s0->unk_08 = func_8007194C(0x4B, temp_s0->unk_0A + 0x5A, 3);
        func_8006E070(temp_s0->unk_08, 0);
    }
    return temp_s0;
}

void func_800F6AA0_EternalStar(ProcessHeader* arg0) {
    if (arg0 != NULL) {
        MBModelKill(arg0->prev);
        EndProcess(arg0->process);
        func_80072080(arg0->unk_08);
        FreeTemp(arg0);
    }
}

void func_800F6AE8_EternalStar(ProcessHeader* arg0, s16 arg1) {
    arg0->unk_0A = arg1;
    D_800F91B4_EternalStar = (arg1 * 4.0f) + 480.0f;
    func_8006DDC8(arg0->unk_08, 0x4B, (arg0->unk_0A + 0x5A));
}

void func_800F6B58_EternalStar(ProcessHeader* arg0) {
    MBMotionShiftSet(arg0->prev, 0, 0, 6, 0);
    HuPrcSleep(3);
    while (1) {
        if (!(MBMotionCheck(arg0->prev))) {
            HuPrcVSleep();
        } else {
            break;
        }
    }
    MBMotionShiftSet(arg0->prev, -1, 0, 6, 2);
}

void func_800F6BD8_EternalStar(void) {
    s32 var_a1;
    s32 var_a1_2;
    ProcessHeader* temp_s0;

    func_80060128(0x30);
    temp_s0 = func_800F68E4_EternalStar(D_800F8BF0_EternalStar);
    SetFadeInTypeAndTime(2, 0x10);

    while (func_80072718() != 0) {
        HuPrcVSleep();
    }
    
    func_800F6B58_EternalStar(temp_s0);
    
    if (_CheckFlag(0x44) == 0) {
        var_a1 = 0x4EE;
    } else {
        var_a1 = 0x4F0;
    }

    LoadStringIntoWindow(temp_s0->unk_08, (void*)(s32)var_a1, -1, -1);
    func_80071C8C(temp_s0->unk_08, 1);
    PlaySound(0xF0);
    WaitForTextConfirmation(temp_s0->unk_08);
    func_80071E80(temp_s0->unk_08, 1);
    func_8006EB40(temp_s0->unk_08);
    
    if (_CheckFlag(0x44) == 0) {
        var_a1_2 = 0x4EF;
    } else {
        var_a1_2 = 0x4F1;
    }

    LoadStringIntoWindow(temp_s0->unk_08, (void*)(s32)var_a1_2, -1, -1);
    func_80071C8C(temp_s0->unk_08, 1);
    WaitForTextConfirmation(temp_s0->unk_08);
    func_80071E80(temp_s0->unk_08, 1);
    func_800601D4(0x5A);
    HuPrcSleep(5);
    func_800726AC(2, 0x10);
    HuPrcSleep(0x11);
    func_800F6AA0_EternalStar(temp_s0);
    func_80056AF4();
    omOvlReturnEx(1);
    omOvlKill();
    HuPrcVSleep();
}

void func_800F6D30_EternalStar(void) {
    GwSystem.curBoardIndex = 7;
    omInitObjMan(0xA, 0);
    omOvlGotoEx(0x35, 0, 0x92);
}

void InitBoard(void) {
    omInitObjMan(0xA, 0);
    SetPlayerOntoChain(0, 0x12, 0);
    SetPlayerOntoChain(1, 0x12, 0);
    SetPlayerOntoChain(2, 0x12, 0);
    SetPlayerOntoChain(3, 0x12, 0);
    SetBoardFeatureFlag(0x43);
    func_800F667C_EternalStar();
    GwCommon.boardWork[15] = rand8() % 3;
    ClearBoardFeatureFlag(0x4F);
    ClearBoardFeatureFlag(0x50);
    func_800F7F4C_EternalStar();
    omOvlReturnEx(1);
}

void func_800F6E34_EternalStar(void) {
    GW_PLAYER* temp_s0;
    s32 i;

    omInitObjMan(0x50, 0x28);
    func_80060088();
    func_80023448(1);
    func_800234B8(0, 0x78, 0x78, 0x78);
    func_800234B8(1, 0x40, 0x40, 0x60);
    func_80023504(1, -100.0f, 100.0f, 300.0f);
    func_80056A08(0x44, 0x4C, 0x48, 0);
    func_80052E84(0);
    func_80052E84(1);
    func_80052E84(2);
    func_80052E84(3);
    
    for (i = 0; i < 4; i++) {
        temp_s0 = GetPlayerStruct(i);
        func_8003E174(temp_s0->player_obj);
        temp_s0->player_obj->unk_0A |= 2;
    }

    if (_CheckFlag(0x4E) != 0) {
        ClearBoardFeatureFlag(0x4E);
        func_800F66C8_EternalStar();
    }

    func_800F671C_EternalStar();
    func_800F74D4_EternalStar();
    func_800F719C_EternalStar();

    if (_CheckFlag(0xF) == 0) {
        func_800F732C_EternalStar();
    }
}

void func_800F6F68_EternalStar(void) {
    GW_PLAYER* playerNoFeatureFlag;
    GW_PLAYER* playerFeatureFlag;
    s32 i;

    func_80060128(0xF);
    InitCameras(2);
    func_800F6E34_EternalStar();
    EventTableHydrate(D_800F905C_EternalStar);
    
    if (_CheckFlag(0xF) == 0) {
        EventTableHydrate(D_800F9164_EternalStar);
    }
    
    func_800584F0(0);
    
    if (_CheckFlag(0x4F) != 0) {
        playerNoFeatureFlag = GetPlayerStruct(-1);
        ClearBoardFeatureFlag(0x4F);
        func_800A0D50(&playerNoFeatureFlag->player_obj->coords, &BoardSpaceGet(0x4E)->coords);
        func_800A0E80(&playerNoFeatureFlag->player_obj->unk_18, &BoardSpaceGet(2)->coords, &playerNoFeatureFlag->player_obj->coords);
    }
    
    if (_CheckFlag(0x50) != 0) {
        ClearBoardFeatureFlag(0x50);
        for (i = 0; i < 4; i++) {
            playerFeatureFlag = GetPlayerStruct(i);
            playerFeatureFlag->player_obj->unk_0A &= ~2;
            MBModelDispOff(playerFeatureFlag->player_obj);
        }
    }
}

void func_800F7070_EternalStar(void) {
    InitCameras(1);
    func_800F6E34_EternalStar();
    func_800584F0(1);
}

void func_800F709C_EternalStar(s16 arg0) {
    Object* var_s2;
    BoardSpace* space;

    if (D_800F91C0_EternalStar[arg0] == 0) {
        if (D_800F91BC_EternalStar == NULL) {
            var_s2 = MBModelCreate(0x79, NULL);
            func_8003E174(var_s2);
            D_800F91BC_EternalStar = var_s2;
        } else {
            var_s2 = MBModelParamCreate(D_800F91BC_EternalStar);
        }
        
        var_s2->unk_0A |= 2;

        D_800F91C0_EternalStar[arg0] = var_s2;
        func_8004CDCC(var_s2);
        space = BoardSpaceGet(D_800F8BF8_EternalStar[arg0]);
        func_800A0D50(&var_s2->coords, &space->coords);
        func_8003C314(0xA, var_s2, D_800F8C18_EternalStar[arg0].unk0, D_800F8C18_EternalStar[arg0].unk2);
    }
}

void func_800F719C_EternalStar(void) {
    s32 i;
    D_800F91BC_EternalStar = 0;

    for (i = 0; i < ARRAY_COUNT(D_800F8C08_EternalStar); i++) {
        D_800F91C0_EternalStar[i] = NULL;
        if (_CheckFlag(D_800F8C08_EternalStar[i]) == 0) {
            func_800F709C_EternalStar(i);
        }
    }
}

void func_800F7224_EternalStar(s16 arg0) {
    Object* var_s1;

    if (D_800F91E0_EternalStar[arg0] == 0) {
        if (D_800F91DC_EternalStar == NULL) {
            var_s1 = MBModelCreate(0x6A, NULL);
            func_8003E174(var_s1);
            D_800F91DC_EternalStar = var_s1;
        } else {
            var_s1 = MBModelParamCreate(D_800F91DC_EternalStar);
        }
        D_800F91E0_EternalStar[arg0] = var_s1;
        var_s1->unk_0A |= 2;
        func_800A0D00(&var_s1->xScale, 0.6f, 0.6f, 0.6f);
        var_s1->unk_30 = 100.0f;
        func_800A0D50(&var_s1->coords, &(BoardSpaceGet(D_800F8C34_EternalStar[arg0])->coords) );
        func_8003C314(8, var_s1, 0, 0);
    }
}

void func_800F732C_EternalStar(void) {
    s32 i;
    D_800F91DC_EternalStar = 0;
    
    for (i = 0; i < ARRAY_COUNT(D_800F8C34_EternalStar); i++) {
        func_800F7224_EternalStar(i);
    }
}

void func_800F736C_EternalStar(void) {
    Object* temp_s0;

    if (D_800F91E4_EternalStar == NULL) {
        temp_s0 = MBModelCreate(0x3B, &D_800F8C38_EternalStar);
        func_8003E174(temp_s0);
        D_800F91E4_EternalStar = temp_s0;
        temp_s0->unk_0A |= 2;
        func_800A0D50(&temp_s0->coords, &BoardSpaceGet(2)->coords);
        func_8003C314(7, temp_s0, 0, 0);
    }
}


void func_800F73F0_EternalStar(void) {
    Process* process;
    Vec3f sp10;
    
    while (func_80072718() != 0) {
        HuPrcVSleep();
    }
    
    HuPrcSleep(0x1E);
    MBMotionSet(D_800F91E4_EternalStar, 0, 0);
    PlaySound(0x4D);

    while ((MBMotionCheck(D_800F91E4_EternalStar) & 1) == 0) {
        HuPrcVSleep();
    }

    MBMotionSet(D_800F91E4_EternalStar, -1, 2);
    func_8004CD84(&sp10);
    process = HuPrcCurrentGet();
    HuPrcChildLink(process, func_8004D1EC(&D_800F91E4_EternalStar->unk_18, &sp10, &D_800F91E4_EternalStar->unk_18, 0x14));
    HuPrcChildWatch();
    EndProcess(NULL);
}

void func_800F74D4_EternalStar(void) {
    D_800F91E4_EternalStar = 0;
    func_800F736C_EternalStar();
    
    if (_CheckFlag(0x4F)) {
        func_800A0E80(&D_800F91E4_EternalStar->unk_18, &(BoardSpaceGet(0x4E)->coords), &D_800F91E4_EternalStar->coords);
        omAddPrcObj(func_800F73F0_EternalStar, 0x1005, 0, 0);
    }
}

s16 func_800F753C_EternalStar(void) {
    return RunDecisionTree(D_800F8D60_EternalStar);
}

s16 func_800F7564_EternalStar(void) {
    return RunDecisionTree(D_800F8C40_EternalStar);
}

s16 func_800F758C_EternalStar(void) {
    return RunDecisionTree(D_800F8C70_EternalStar);
}

s16 func_800F75B4_EternalStar(void) {
    return RunDecisionTree(D_800F8CA0_EternalStar);
}

s16 func_800F75DC_EternalStar(void) {
    return RunDecisionTree(D_800F8C40_EternalStar) ^ 1;
}

s16 func_800F7608_EternalStar(void) {
    return RunDecisionTree(D_800F8CD0_EternalStar);
}

s16 func_800F7630_EternalStar(void) {
    return RunDecisionTree(D_800F8D00_EternalStar);
}

s16 func_800F7658_EternalStar(void) {
    return RunDecisionTree(D_800F8C70_EternalStar) ^ 1;
}

s16 func_800F7684_EternalStar(void) {
    return RunDecisionTree(D_800F8CD0_EternalStar) ^ 1;
}

s16 func_800F76B0_EternalStar(void) {
    return RunDecisionTree(D_800F8D30_EternalStar);
}

s16 func_800F76D8_EternalStar(void) {
    return RunDecisionTree(D_800F8CA0_EternalStar) ^ 1;
}

s16 func_800F7704_EternalStar(void) {
    return RunDecisionTree(D_800F8D00_EternalStar) ^ 1;
}

s16 func_800F7730_EternalStar(void) {
    return RunDecisionTree(D_800F8D30_EternalStar) ^ 1;
}

s32 func_800F775C_EternalStar(void) {
    if (GwCommon.boardWork[0] != 0) {
        if (!(_CheckFlag(0x48))) {
            return 0;
        }
    }
    return 1;
}

s32 func_800F7794_EternalStar(void) {
    if (GwCommon.boardWork[1] != 0) {
        if (!(_CheckFlag(0x4C))) {
            return 0;
        }
    }
    return 1;
}

s32 func_800F77CC_EternalStar(void) {
    if (GwCommon.boardWork[2] != 0) {
        switch (GwCommon.boardWork[15]) {
        case 0:
            if (!(_CheckFlag(0x46)) || !(_CheckFlag(0x47))) {
                return 0;
            }
            break;
        case 1:
            if (!(_CheckFlag(0x49)) || !(_CheckFlag(0x4A))) {
                return 0;
            }
            break;
        default:
            return 2;
        }
    }
    return 1;
}

s32 func_800F784C_EternalStar(void) {
    if (GwCommon.boardWork[3] != 0) {
        switch (GwCommon.boardWork[15]) {
        case 0:
            return 2;
        case 1:
            if (_CheckFlag(0x46) == 0 || _CheckFlag(0x47) == 0) {
                return 0;
            }
            break;
        case 2:
            if (_CheckFlag(0x46) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

s32 func_800F78CC_EternalStar(void) {
    if (GwCommon.boardWork[4] != 0) {
        switch (GwCommon.boardWork[15]) {
        case 0:
            if (_CheckFlag(0x49) == 0 || _CheckFlag(0x4A) == 0) {
                return 0;
            }
            break;
        case 1:
            if (_CheckFlag(0x4B) == 0) {
                return 0;
            }
            break;
        }
    }
    return 1;
}


s32 func_800F7934_EternalStar(void) {
    if (GwCommon.boardWork[5] != 0) {
        switch (GwCommon.boardWork[15]) {
        case 0:
            return 3;
        case 1:
            return 2;
        case 2:
            if ( _CheckFlag(0x49) == 0 || _CheckFlag(0x4A) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

s32 func_800F79BC_EternalStar(void) {
    if (GwCommon.boardWork[6] != 0) {
        switch (GwCommon.boardWork[15]) {
        case 0:
            if (_CheckFlag(0x4B) == 0) {
                return 0;
            }
            break;
        case 2:
            if (_CheckFlag(0x4B) == 0) {
                return 0;
            }
            break;
        case 1:
            return 3;
        }
    }
    return 1;
}

s32 func_800F7A2C_EternalStar(void) {
    if (GwCommon.boardWork[7] != 0 && GwCommon.boardWork[15] == 2) {
        return 3;
    } else {
        return 1;
    }
}

s32 func_800F7A60_EternalStar(void) {
    if (GwCommon.boardWork[8] != 0) {
        switch (GwCommon.boardWork[15]) {
            case 0:
                return 2;
            case 1:
                if (_CheckFlag(0x46) == 0) {
                    return 0;
                }
                break;
            case 2:
                if (_CheckFlag(0x46) == 0 || _CheckFlag(0x47) == 0) {
                    return 0;
                }
            break;
        }
    }
    return 1;
}

s32 func_800F7AE8_EternalStar(void) {
    if (GwCommon.boardWork[9] != 0) {
        if (GwCommon.boardWork[15] == 0) {
            if (_CheckFlag(0x46) == 0) {
                return 0;
            }
        } else {
            return 2;
        }
    }
    return 1;
}

void func_800F7B30_EternalStar(s32 arg0, s32 arg1) {
    D_800F8D6C_EternalStar[((arg0 & 3) << 2 | (arg1 & 3))]();
}

void func_800F7B6C_EternalStar(void) {
    func_800F7B30_EternalStar(func_800F775C_EternalStar(), func_800F7794_EternalStar());
}

void func_800F7BA0_EternalStar(void) {
    func_800F7B30_EternalStar(func_800F784C_EternalStar(), func_800F77CC_EternalStar());
}

void func_800F7BD4_EternalStar(void) {
    func_800F7B30_EternalStar(func_800F78CC_EternalStar(), func_800F7934_EternalStar());
}

void func_800F7C08_EternalStar(void) {
    func_800F7B30_EternalStar(func_800F7A2C_EternalStar(), func_800F79BC_EternalStar());
}

void func_800F7C3C_EternalStar(void) {
    func_800F7B30_EternalStar(func_800F7AE8_EternalStar(), func_800F7A60_EternalStar());
}


void func_800F7C70_EternalStar(void) {
    while (func_8004B850() != 0) {
        HuPrcVSleep();
    }
    HuPrcVSleep();
    D_800F91E8_EternalStar = func_80045D84(0, 0x92, 1);
    D_800F91EC_EternalStar = func_80045D84(1, 0xA0, 1);
    D_800F91F0_EternalStar = func_80045D84(3, 0xAE, 1);
    D_800F91F4_EternalStar = func_80045D84(0xB, 0xBC, 1);
    HuPrcSleep(3);
    D_800EE320 = 1;
}

void func_800F7D20_EternalStar(void) {
    D_800EE320 = 0;
    func_80045E6C(D_800F91E8_EternalStar);
    func_80045E6C(D_800F91EC_EternalStar);
    func_80045E6C(D_800F91F0_EternalStar);
    func_80045E6C(D_800F91F4_EternalStar);
}

Object* func_800F7D6C_EternalStar(s16 arg0) {
    Object* temp_s0;
    GW_PLAYER* temp_s1 = GetPlayerStruct(arg0);

    if (temp_s1->player_index == GetCurrentPlayerIndex()) {
        temp_s0 = MBModelCreate(temp_s1->character, NULL);
    } else {
        temp_s0 = MBModelCreate(func_80052F6C(arg0), NULL);
    }
    func_800A0D50(&temp_s0->coords, &temp_s1->player_obj->coords);
    func_800A0D50(&temp_s0->unk_18, &temp_s1->player_obj->unk_18);
    func_80025930(*temp_s0->unk_3C->unk_40, 0, 0x8000);
    func_80025930(*temp_s0->unk_40->unk_40, 0, 0x8000);
    func_80021240(*temp_s0->unk_3C->unk_40);
    func_80021240(*temp_s0->unk_40->unk_40);
    return temp_s0;
}

void func_800F7E5C_EternalStar(Object* arg0) {
    MBModelKill(arg0);
}

void func_800F7E78_EternalStar(Object* arg0) {
    s32 i;

    for (i = 255; i >= 0; i = i - 8) {
        func_800211BC(*arg0->unk_3C->unk_40, i);
        func_800211BC(*arg0->unk_40->unk_40, ~i); 
        HuPrcVSleep();
    }
}

void func_800F7EE0_EternalStar(Object* arg0) {
    s32 i;

    for (i = 0; i <= 255; i = i + 8) {
        func_800211BC(*arg0->unk_3C->unk_40, i);
        func_800211BC(*arg0->unk_40->unk_40, ~i); 
        HuPrcVSleep();
    }
}

void func_800F7F4C_EternalStar(void) {
    s32 i;

    for (i = 0; i < 12; i++) {
        GwCommon.boardWork[i] = 0;
    }
}

void func_800F7F7C_EternalStar(void) {
    Object* temp_s1;
    Object* temp_s3;
    Process* process;
    BoardSpace* space;
    GW_PLAYER* player = GetPlayerStruct(-1);

    player->player_obj->unk_0A &= ~2;
    MBModelDispOff(player->player_obj);
    temp_s3 = func_800F7D6C_EternalStar(-1);
    temp_s1 = MBModelCreate(0x4C, NULL);
    func_80025EB4(*temp_s1->unk_3C->unk_40, 2, 0);
    func_800A0D50(&temp_s1->coords, &player->player_obj->coords);
    func_80058910(-1, 3);
    PlaySound(0x47);
    func_800F7EE0_EternalStar(temp_s3);
    MBModelKill(temp_s1);
    space = BoardSpaceGet(GetAbsSpaceIndexFromChainSpaceIndex(player->next_chain, player->next_space));
    process = HuPrcCurrentGet();
    HuPrcChildLink(process, func_8004D648(&player->player_obj->coords, &space->coords, &player->player_obj->coords, 25.0f));
    HuPrcChildWatch();
    SetPlayerOntoChain(-1, player->next_chain, player->next_space);
    temp_s1 = MBModelCreate(0x4C, NULL);
    func_80025EB4(*temp_s1->unk_3C->unk_40, 2, 0);
    func_800A0D50(&temp_s1->coords, &player->player_obj->coords);
    PlaySound(0x47);
    func_800A0D50(&temp_s3->coords, &player->player_obj->coords);
    func_800A0D50(&temp_s3->unk_18, &player->player_obj->unk_18);
    func_800F7E78_EternalStar(temp_s3);
    MBModelKill(temp_s1);
    func_800F7E5C_EternalStar(temp_s3);
    MBModelDispOn(player->player_obj);
    player->player_obj->unk_0A |= 2;
}

void func_800F8130_EternalStar(void) {
    GW_PLAYER* player = GetPlayerStruct(-1);
    s16 cur_space = GetCurrentSpaceIndex();
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800F8F08_EternalStar); i++) {
        if (D_800F8F08_EternalStar[i] != cur_space) {
            continue;
        } else {
            while (func_8004B850() != 0) {
                HuPrcSleep(1);
            }
            
            GwCommon.boardWork[i] = 1;

            SetNextChainAndSpace(-1, D_800F8ED8_EternalStar[i][GwCommon.boardWork[15]], 0);
            func_800405DC(player->player_index);
            func_800F7F7C_EternalStar();
            func_8003FEFC(player->player_index);
            break;
        }        
    }

    EndProcess(NULL);
}

void func_800F8240_EternalStar(void) {
    SetPlayerAnimation(-1, -1, 2);
    HuPrcSleep(30);
    SetBoardFeatureFlag(0x4F);
    func_800587BC(0x5D, 0, 3, 1);
    SetEventReturnFlag(1);
    EndProcess(NULL);
}

void func_800F8298_EternalStar(void) {
    Vec3f sp10;
    GW_PLAYER* player;
    s16 textWindowID;
    BoardSpace* temp_s0;
    s32 tempVar;

    player = GetPlayerStruct(-1);

    while (func_80072718() != 0) {
        HuPrcVSleep();
    }
    
    HuPrcSleep(0x32);
    SetNextChainAndSpace(-1, 0x13, 0);
    func_800F7F7C_EternalStar();
    SetPlayerAnimation(-1, 0, 2);
    temp_s0 = BoardSpaceGet(GetAbsSpaceIndexFromChainSpaceIndex(0x12, 1));
    func_800A0E80(&player->player_obj->unk_18, &temp_s0->coords, &player->player_obj->coords);
    func_8004D3F4(&player->player_obj->coords, &temp_s0->coords, &player->player_obj->coords, 0xF);
    HuPrcSleep(0xF);
    SetPlayerOntoChain(-1, 0x12, 1);
    SetPlayerAnimation(-1, -1, 2);
    HuPrcSleep(0xF);
    func_800A0D50(&sp10, &player->player_obj->unk_18);
    func_8003D514(&sp10, -90.0f);
    func_8004D1EC(&player->player_obj->unk_18, &sp10, &player->player_obj->unk_18, 4);
    HuPrcSleep(4);
    func_8003D514(&sp10, 170.0f);
    func_8004D1EC(&player->player_obj->unk_18, &sp10, &player->player_obj->unk_18, 8);
    HuPrcSleep(8);
    func_8003D514(&sp10, -80.0f);
    func_8004D1EC(&player->player_obj->unk_18, &sp10, &player->player_obj->unk_18, 4);
    HuPrcSleep(4);
    tempVar = GwCommon.boardWork[15];
    
    while (1) {
        GwCommon.boardWork[15] =  rand8() % 3;
        if (tempVar != GwCommon.boardWork[15]) {
            break;
        }
    }

    func_800F7F4C_EternalStar();
    textWindowID = CreateTextWindow(0x4C, 0x3C, 0xE, 3);
    
    switch (GwCommon.boardWork[15]) {
    case 0:
        LoadStringIntoWindow(textWindowID, (void*)0x1FD, -1, -1);
        break;
    case 1:
        LoadStringIntoWindow(textWindowID, (void*)0x1FE, -1, -1);
        break;
    default:
        LoadStringIntoWindow(textWindowID, (void*)0x1FF, -1, -1);
        break;
    }
    
    func_8006E070(textWindowID, 0);
    ShowTextWindow(textWindowID);
    func_8004DBD4(textWindowID, player->player_index);
    HideTextWindow(textWindowID);
    EndProcess(NULL);
}

void func_800F8514_EternalStar(void) {
    SetBoardFeatureFlag(0x50);
    func_800587EC(0x5C, 0, 4);
    SetEventReturnFlag(1);
    SetPlayerOntoChain(0, 0x12, 1);
    SetPlayerOntoChain(1, 0x12, 1);
    SetPlayerOntoChain(2, 0x12, 1);
    SetPlayerOntoChain(3, 0x12, 1);
}

void func_800F8588_EternalStar(void) {
    GW_PLAYER* temp_s0_3;
    GW_PLAYER* curPlayer;
    s32 playerIndex;
    Object* objectStructs[4];
    s32 i;
    s32 j;

    curPlayer = GetPlayerStruct(-1);
    
    while (func_80072718() != 0) {
        HuPrcVSleep();
    }
    
    HuPrcSleep(5);
    playerIndex = curPlayer->player_index;
    objectStructs[playerIndex] = func_800F7D6C_EternalStar(playerIndex);
    PlaySound(0x47);

    for (i = 255; i >= 0; i = i - 8) { 
        func_800211BC(*objectStructs[playerIndex]->unk_3C->unk_40, i & 0xFF);
        func_800211BC(*objectStructs[playerIndex]->unk_40->unk_40, ~i & 0xFF);
        HuPrcVSleep();
    }

    func_800F7E5C_EternalStar(objectStructs[playerIndex]);
    curPlayer->player_obj->unk_0A |= 2;
    MBModelDispOn(curPlayer->player_obj);
    HuPrcSleep(0xA);

    for (j = 0; j < 4; j++) {
        temp_s0_3 = GetPlayerStruct(j);
        if (temp_s0_3 != curPlayer) {
            objectStructs[j] = func_800F7D6C_EternalStar(j);
            func_800A0D00(&objectStructs[j]->xScale, 0.7f, 0.7f, 0.7f);
        }
    }

    PlaySound(0x47);

    for (i = 255; i >= 0; i = i - 8) {
        for (j = 0; j < 4; j++) {
            temp_s0_3 = GetPlayerStruct(j);
            if (temp_s0_3 != curPlayer) {
                func_800211BC(*objectStructs[j]->unk_3C->unk_40, i);
                func_800211BC(*objectStructs[j]->unk_40->unk_40, ~i); 
            }       
        }
        HuPrcVSleep();
    }

    for (j = 0; j < 4; j++) {
        temp_s0_3 = GetPlayerStruct(j);
        if (temp_s0_3 != curPlayer) {
            func_800F7E5C_EternalStar(objectStructs[j]);
            temp_s0_3->player_obj->unk_0A |= 2;
            MBModelDispOn(temp_s0_3->player_obj);            
        }
    }
        
    EndProcess(NULL);
}

void func_800F87E4_EternalStar(EventTableUnkStruct* arg0) {
    s32 directionResult;
    unk_8003B8D4Struct* temp_s2;
    s32 i;
    s32 tempVar;

    SetPlayerAnimation(-1, -1, 2);
    HuPrcVSleep();
    func_800F7C70_EternalStar();
    temp_s2 = func_8003C218(GwSystem.curPlayerIndex, arg0->spaceIDs);
    func_8003C060(temp_s2, GwSystem.curPlayerIndex, 0);
    
    if (PlayerIsCPU(-1) != 0) {
        tempVar = RunDecisionTree(arg0->decisionTree);

        for (i = 0; i < tempVar; i++) {
            func_8003BE84(temp_s2, -2);
        }
        
        func_8003BE84(temp_s2, -4);
    }
    
    directionResult = DirectionPrompt(temp_s2);
    
    func_8003B908(temp_s2);
    func_800F7D20_EternalStar();
    
    if (directionResult == 0) {
        SetNextChainAndSpace(-1, arg0->unk_08, 0);
    } else {
        SetNextChainAndSpace(-1, arg0->unk_0A, 0);
    }
}

void func_800F88EC_EternalStar(void) {
    func_800F87E4_EternalStar(&D_800F8F68_EternalStar);
    EndProcess(NULL);
}

void func_800F8914_EternalStar(void) {
    func_800F87E4_EternalStar(&D_800F8F8C_EternalStar);
    EndProcess(NULL);
}

void func_800F893C_EternalStar(void) {
    func_800F87E4_EternalStar(&D_800F8FB0_EternalStar);
    EndProcess(NULL);
}

void func_800F8964_EternalStar(void) {
    func_800F87E4_EternalStar(&D_800F8FD4_EternalStar);
    EndProcess(NULL);
}

void func_800F898C_EternalStar(void) {
    func_800F87E4_EternalStar(&D_800F8FF8_EternalStar);
    EndProcess(NULL);
}

void func_800F89B4_EternalStar(void) {
    SetNextChainAndSpace(-1, 0x12, 2);
}

void func_800F89D8_EternalStar(void) {
    SetNextChainAndSpace(-1, 7, 0);
}

void func_800F89FC_EternalStar(void) {
    func_8004D2A4(-1, 8, 0);
    func_800587EC(0x65, 0, 1);
}

void func_800F8A30_EternalStar(void) {
    if (func_800F67AC_EternalStar(GetCurrentSpaceIndex()) == 1) {
        func_800587EC(0x5E, 0, 2);
        func_8004D2A4(-1, 8, func_800F6610_EternalStar());
    }
}

void func_800F8A94_EternalStar(void) {
    GW_PLAYER* temp_s0;
    s32 i;

    if (func_800F67AC_EternalStar(GetCurrentSpaceIndex()) == 2) {
        for (i = 0; i < 4; i++) {
            temp_s0 = GetPlayerStruct(i);
            temp_s0->group = i != GetCurrentPlayerIndex();
        }
        func_800587BC(1, 0, 5, 1);
    }
}

void func_800F8B20_EternalStar(void) {
    InitCameras(2);
    func_8001D4D4(1, &D_800F8BB0_EternalStar);
    func_800F6E34_EternalStar();
    func_800584F0(2);
    omAddPrcObj(&func_800F6BD8_EternalStar, 0x1005, 0, 0);
}
