#include "common.h"
#include "spaces.h"

s32 ExecuteEventForSpace(s16, s16);
s16 GetRandomChanceSpace(void);
void func_8004068C(s32);
s32 func_800415E8(s32);
s32 func_80041644(s32);
s32 func_80041664(s32);
Process* func_80041F24(s32);
Process* func_800444DC(void);
Process* func_80044680(s32);
void func_800466C0(void);
s32 func_80046710(void);
Process* func_80047E54(void);
void func_8004D4A8(s16, s32);
void func_8004D6FC(s16, f32);
void func_8004DBD4(s32, u8);
void func_80052C44(s32, s32, s32, s32, s32);
s32 func_80054730(s32);
extern s32 D_800D86E8;
void func_80056F40(void);
s32 func_80056FA8(void);

s32 D_800C56D0[] = { 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x7F };


void func_8005727C(void);
void func_8005700C(void);
void func_8005835C(void);
void func_800530E4(void);
void func_8004220C(void);
void func_800559BC(void);
s8 func_8000C4A0(void);


extern s16 D_800EE320;
extern s16 D_800F2A78;
void func_8003D20C(s32);
void func_80052934(s32);


void func_8004D0B0(s16);
void func_80056B78(void);
s16 GetSumOfPlayerStars(void);


void func_800591E0(void* arg0);
void func_80043460(void);                                  /* extern */
void func_80045EE0(void);                                  /* extern */
extern s32 D_800D86E4;
extern s16 D_800ECC20;
extern s16 D_800ED3C0;
extern s16 D_800EE986;
extern s16 D_800F2CDC;
extern s16 D_800F3180;
extern s16 D_800F3298;
extern s16 D_800F37A8;
extern s16 D_800F37E8;
extern s32 D_800F3FF0;
extern s16 D_800F64C6;
extern s16 D_800F65B8;
extern s16 D_800F65D8;
extern s16 omovlhisidx;
extern s16 D_800D86B2;
extern omOvlHisData D_800D86B8[];
extern s16 D_800D86B0;
extern s16 D_800D86EC;
extern s16 D_800D86EE;
extern s16 D_800D86F0;
extern s16 D_800D86E0;
extern s16 D_800D86E2;
extern s16 D_800D86FA;
extern Vec3f D_800D86FC;
extern s32 D_800D86F4;
extern s16 D_800D86F8;

void func_8003C2D0(s32);
void func_800434E4(void);
void func_80045680(void);
void func_80046720(void);
void func_80053064(void);
void func_80053080(void);
void func_800532E0(void);
void FreeSpaceTexturesWrapper(void);
void func_8003C30C(void);
void MBModelClose(void);
void func_80043544(void);
void func_80046760(void);
void func_80053074(void);
void func_800532F4(void);
void func_8004A510(void);
void func_8004A520(void);
void func_8004A7A4(void);
void func_8004A7DC(void);
void func_8004B5C4(f32);
f32 func_8004B5D0(void);
void func_8004B838(f32);
f32 func_8004B844(void);

void func_80056730(s32 arg0, s16 arg1, s16 arg2) {
    omOvlHisData* history; //is this the correct struct??

    history = &D_800D86B8[D_800D86B2++];
    
    if (arg0 != -2) {
        if (arg0 == -1) {
            arg0 = omovlhis[omovlhisidx].overlayID;
        }
    } else {
        arg0 = D_800C56D0[GwSystem.curBoardIndex];
    }
    
    history->overlayID = arg0;
    history->event = arg1;
    history->stat = arg2;
    
    if (D_800D86B2 >= 5) {
        D_800D86B2 = 4;
    }
}

void func_800567D4(void) {
    D_800D86B0 = 1;
    D_800D86B2 = 0;
    if (_CheckFlag(0x41) == 0) {
        if (GwSystem.curBoardIndex < 10) {
            if (GwSystem.curBoardIndex < 8) {
                func_80056730(-2, 4, 0x92);
            }
        } else {
            func_80056730(-2, 4, 0x92);
        }
        if (GwSystem.curBoardIndex == 9) {
            func_80056730(0x82, 0, 0x92);
        } else {
            func_80056730(0x62, 0, 0x92);
        }
        func_80056730(-2, 1, 0x92);
    }
    GwSystem.unk_00 = 2;
    func_80056B78();
    func_8004D0B0((s8)GwSystem.messageSpeed);
    ClearBoardFeatureFlag(0x36);
    D_800D86E2 = 0;
}
void func_800568A4(void) {
    omOvlHisData* history;

    D_800D86E0 = 1;
    if (D_800D86B2 != 0) {
        history = &D_800D86B8[--D_800D86B2];
        omOvlCallEx(history->overlayID, history->event, history->stat);
        return;
    }
    if (D_800D86B0 != 0) {
        D_800D86E0 = 0;
        omOvlCallEx(D_800C56D0[GwSystem.curBoardIndex], 2, 0x92);
        return;
    }
    
    ClearBoardFeatureFlag(0x2C);
    
    if (D_800D86E2 != 0) {
        SetBoardFeatureFlag(0x36);
    } else {
        ClearBoardFeatureFlag(0x36);
    }
    omOvlReturnEx(1);
}

void func_80056984(void) {
    D_800D86B0 = 0;
}

s16 func_80056990(void) {
    return D_800D86E0;
}

void func_8005699C(s32 arg0) {
    D_800D86B8[D_800D86B2].event = arg0;
    D_800D86B2++;
    if (D_800D86B2 >= 5) {
        D_800D86B2 = 4;
    }
    func_80056730(-2, 3, 0x92);
    omOvlReturnEx(1);
}

void func_80056A08(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    LoadBackgroundData(FE2310_ROM_START);
    if (arg0 >= 0) {
        LoadBackgroundIndex(arg0);
    }

    LoadInitialSpaceTextures();

    if (arg1 >= 0) {
        LoadBoardSpaces(0xA, arg1);
    }

    func_8003C2D0(arg2);
    MBModelInit();
    func_80053020();
    func_80053064();
    func_800532E0();
    func_800544E4();
    func_80045680();
    func_800434E4();
    func_80046720();
    func_8003FCD4();
    func_8006CEA0();
    D_800D86EC = -1;
    D_800D86EE = 0;
    D_800D86F0 = 0;
    func_80053080();
}

void func_80056AF4(void) {
    func_80041370();
    func_80046760();
    func_80043544();
    func_800456C4();
    func_80054654();
    func_80070ED4();
    func_800532F4();
    func_80053074();
    MBModelClose();
    func_8003C30C();
    FreeBoardSpaces();
    FreeSpaceTexturesWrapper();
    func_8004A140();
    func_80049F0C();
}

void func_80056B78(void) {
    GW_PLAYER* temp_v0;
    GW_SYSTEM* gameStatus = &GwSystem;
    s32 i;

    D_800F65B8 = 0;
    D_800F37A8 = 0;
    D_800EE986 = 0;
    D_800F64C6 = 0;
    D_800F3298 = 0;
    D_800F3180 = 0;
    D_800ECC20 = 0;
    D_800ED3C0 = 0;
    D_800F65D8 = 0;
    D_800F37E8 = 0;
    D_800D86E4 = 0;
    D_800F3FF0 = 0;
    D_800F2CDC = -1;
    func_80043460();
    func_80045EE0();
    if (_CheckFlag(0x41) == 0) {
        gameStatus->chosenStarSpaceIndex = 0;
        gameStatus->currentTurn = 1;
        gameStatus->curPlayerIndex = 0;
        gameStatus->unk_1E = 0;
        if (_CheckFlag(0x2C) == 0) {
            switch (gameStatus->playType) {
                case 0:
                    gameStatus->maxTurns = 20;
                    break;
                case 1:
                    gameStatus->maxTurns = 35;
                    break;
                case 2:
                    gameStatus->maxTurns = 50;
                    break;
            }
        } else {
            switch (gameStatus->playType) {
                case 0:
                    gameStatus->maxTurns = 10;
                    break;
                case 1:
                    gameStatus->maxTurns = 20;
                    break;
                case 2:
                    gameStatus->maxTurns = 30;
                    break;
            }            
        }
        gameStatus->saveSetting = 0;
        gameStatus->minigameExplanation = 0;
        gameStatus->messageSpeed = 1;
        
        for (i = 0; i < MAX_PLAYERS; i++) {
            temp_v0 = GetPlayerStruct(i);
            temp_v0->stars = 0;
            temp_v0->poisoned_flag = 0;
            temp_v0->coins_total = 0;
            temp_v0->coins_max = 0;
            temp_v0->happening_count = 0;
            temp_v0->red_count = 0;
            temp_v0->blue_count = 0;
            temp_v0->minigame_count = 0;
            temp_v0->chance_count = 0;
            temp_v0->mushroom_count = 0;
            temp_v0->bowser_count = 0;
        }
        
        for (i = 0; i < ARRAY_COUNT(GwCommon.boardWork); i++) {
            GwCommon.boardWork[i] = 0;
        }

        ClearBoardFeatureFlag(0x46);
        ClearBoardFeatureFlag(0x47);
        ClearBoardFeatureFlag(0x48);
        ClearBoardFeatureFlag(0x49);
        ClearBoardFeatureFlag(0x4A);
        ClearBoardFeatureFlag(0x4B);
        ClearBoardFeatureFlag(0x4C);
        ClearBoardFeatureFlag(0x4F);
        ClearBoardFeatureFlag(0x50);
        ClearBoardFeatureFlag(0x51);
        ClearBoardFeatureFlag(0x52);
        ClearBoardFeatureFlag(0x53);
        ClearBoardFeatureFlag(0x54);
        ClearBoardFeatureFlag(0x55);
        ClearBoardFeatureFlag(0x56);
        ClearBoardFeatureFlag(0x57);
        ClearBoardFeatureFlag(0x58);
        ClearBoardFeatureFlag(0x59);
        ClearBoardFeatureFlag(0x5A);
        ClearBoardFeatureFlag(0x5B);
        ClearBoardFeatureFlag(0x5C);
        ClearBoardFeatureFlag(0x5D);
        ClearBoardFeatureFlag(0x42);
        ClearBoardFeatureFlag(0x43);
        ClearBoardFeatureFlag(0x4D);
        ClearBoardFeatureFlag(0x44);
        ClearBoardFeatureFlag(0x4E);
        ClearBoardFeatureFlag(0x41);
    }
}


void func_80056E30(s16 arg0) {
    D_800D86FA = arg0;
}

s16 func_80056E3C(void) {
    return D_800D86FA;
}

void func_80056E48(Vec3f* arg0) {
    D_800D86FC = *arg0;
}

void func_80056E6C(void) {
    Vec2f sp10;
    while (1) {
        switch (D_800D86FA) {
        case 1:
            func_8004B5DC(&GwPlayer[GwSystem.curPlayerIndex].player_obj->coords);
            break;
        case 2:
            func_8004B5DC(&D_800D86FC);
            break;
        case 3:
            func_8004B6D8(&sp10);
            func_8004B61C(&sp10);
            break;
        }
        HuPrcVSleep();    
    }
}

// GCC keeps &GwSystem+0x1C in a register; retail addresses each field as a constant (masked 24)
#ifdef NON_MATCHING
void func_80056F40(void) {
    if (++GwSystem.curPlayerIndex >= 4) {
        GwSystem.curPlayerIndex = 0;
        if (++GwSystem.currentTurn >= 99) {
            GwSystem.currentTurn = 99;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/57330", func_80056F40);
#endif

// register allocation: ret lives in a0 instead of v0 (masked 3)
#ifdef NON_MATCHING
s32 func_80056FA8(void) {
    GW_SYSTEM* gs = &GwSystem;
    s32 ret;

    if (_CheckFlag(0x2C) != 0) {
        ret = 0;
    } else {
        ret = 0;
        if (gs->curPlayerIndex == 3 && gs->maxTurns >= 0) {
            ret = (gs->maxTurns - gs->currentTurn) == 5;
        }
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/57330", func_80056FA8);
#endif

// decomp-permuter
void func_8005700C(void)
{
  s32 ovl;
  s16 *new_var;
  do
  {
    HuPrcVSleep();
  }
  while (func_80072718() != 0);
  loop:
  do
  {
    HuPrcVSleep();
  }
  while ((D_800F5144 == 0) && (D_800D86EC < 0));

  while (func_80072718() != 0)
  {
    HuPrcVSleep();
  }

  new_var = &GwSystem.curBoardIndex;
  if (D_800D86F0 != 0)
  {
    func_800601D4(0x5A);
  }
  func_800726AC(D_800D86EE, 0x10);
  HuPrcSleep(0x11);
  func_80056AF4();
  if (D_800D86EC & 0x20)
  {
    ovl = 0x80;
    if (GwSystem.curBoardIndex != 9)
    {
      if (GetSumOfPlayerStars() != 0)
      {
        D_800D86E2 = 1;
        if (((*new_var) == 7) && (_CheckFlag(0x2A) == 0))
        {
          func_80056730(0x63, 0, 0x94);
        }
        func_80056730(0x41, 0, 0x92);
        ovl = 0x42;
      }
      else
      {
        ovl = 0x43;
      }
    }
    func_80056730(ovl, 0, 0x92);
    func_80056984();
  }
  if (D_800D86EC & 1)
  {
    if (func_80056FA8() != 0)
    {
      func_80056730(0x3F, 0, 0x92);
    }
    func_80056F40();
  }
  if (D_800D86EC & 2)
  {
    func_80056730(0x6F, 0, 0x94);
  }
  if (D_800D86EC & 8)
  {
    func_80056730(D_800D86F4, D_800D86F8, 0x92);
  }
  ClearBoardFeatureFlag(0x45);
  omOvlReturnEx(1);
  omOvlKill();
  HuPrcVSleep();
  goto loop;
}

void func_80057208(s16 arg0) {
    switch (--arg0) {
    case 3:
    case 5:
        PlaySound(0x4E);
        break;
    case 0:
        PlaySound(0x30);
        break;
    case 1:
        PlaySound(0x31);
        break;
    case 8:
        PlaySound(0x61);
        break;
    case 2:
    case 7:
        PlaySound(0x60);
        break;
    case 4:
        PlaySound(0x5B);
        break;
    }
}

void func_8005727C(void) {
    Vec3f sp18;
    Process* proc;
    GW_SYSTEM* gs = &GwSystem;
    GW_PLAYER* player;
    BoardSpace* spc;
    s16 spaceIdx;
    s16 win;
    s32 h1;
    s32 h2;
    s32 h3;
    s32 n;
    s32 j;
    s32 i;
    s32 mult;
    s16 remain;

    proc = HuPrcCurrentGet();
    while (1) {
        if ((u32)D_800D86E4 < 2 && gs->curPlayerIndex == 0) {
            for (i = 0; i < 4; i++) {
                player = GetPlayerStruct(i);
                player->turn_status = 0;
                player->flags &= ~2;
            }
            if (gs->maxTurns >= 0) {
                remain = gs->maxTurns - gs->currentTurn + 1;
                if (remain < 6) {
                    if (remain > 0 && _CheckFlag(0x2C) == 0) {
                        SetBoardFeatureFlag(0x42);
                    }
                }
            }
            if (_CheckFlag(0x41) == 0) {
                switch ((s8)gs->saveSetting) {
                    case 1:
                        gs->saveSetting = 0;
                    case 2:
                        SetBoardFeatureFlag(0);
                        SetBoardFeatureFlag(0x40);
                        win = CreateTextWindow(0x58, 0x6C, 0xD, 1);
                        func_8006E154(win, 0);
                        LoadStringIntoWindow(win, (void*)0x178, -1, -1);
                        func_8006E070(win, 0);
                        while (func_8006FCC0(win) != 0) {
                            HuPrcVSleep();
                        }
                        func_8005B3B0();
                        func_8006EB40(win);
                        LoadStringIntoWindow(win, (void*)0x179, -1, -1);
                        func_8006E070(win, 0);
                        WaitForTextConfirmation(win);
                        func_80070D90(win);
                        break;
                }
            }
            ClearBoardFeatureFlag(0x41);
            D_800D86E8 = ExecuteEventForSpace(-2, 7);
        }
        for (i = 0; i < 4; i++) {
            player = GetPlayerStruct(i);
            func_800546B4(i, player->turn_status);
            if ((s8)player->poisoned_flag != 0) {
                SetPlayerAnimation(i, 4, 2);
            }
        }
        if (_CheckFlag(0x2C) == 0 && _CheckFlag(0xC) != 0 && D_800F2CDC == -1) {
            D_800F2CDC = GetRandomChanceSpace();
        }
        player = GetPlayerStruct(gs->curPlayerIndex);
        spaceIdx = GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain, player->cur_space);
        spc = BoardSpaceGet(spaceIdx);
        if ((u32)D_800D86E4 >= 2) {
            while (func_80072718() != 0) {
                HuPrcVSleep();
            }
            func_8004A520();
            func_8004B5C4(3.0f);
            D_800F2A78 = 1;
            switch (D_800D86E4) {
                case 2:
                    goto state2;
                case 3:
                    goto state3;
                case 4:
                    goto state4;
                case 5:
                    goto state5;
                case 6:
                    goto state6;
                case 7:
                    goto state7;
                case 8:
                    goto state8;
                case 9:
                    goto state9;
            }
        } else {
            func_8004A520();
            func_8004B5C4(3.0f);
            ExecuteEventForSpace(-4, 7);
            HuPrcChildLink(proc, func_800532B4());
            HuPrcChildWatch();
        }
        HuPrcSleep(4);
        func_80058910(-1, 3);
        HuPrcChildLink(proc, func_80048000(gs->curPlayerIndex));
        HuPrcChildWatch();
        ExecuteEventForSpace(-5, 7);
        if ((s8)player->poisoned_flag != 0) {
            player->poisoned_flag--;
            win = CreateTextWindow(0x1E, 0x3C, 0x17, 1);
            LoadStringIntoWindow(win, (void*)0x17C, -1, -1);
            func_8006E070(win, 0);
            PlaySound(0x100);
            ShowTextWindow(win);
            func_8004DBD4(win, player->player_index);
            HideTextWindow(win);
            SetPlayerLandedSpaceType(-1, spc->spaceType);
            func_800546B4(gs->curPlayerIndex, player->turn_status);
            goto turn_end;
        }
    roll:
        h1 = func_80045D84(2, 0xA0, 1);
        h2 = func_80045D84(3, 0xAE, 1);
        h3 = func_80045D84(0xB, 0xBC, 1);
        D_800EE320 = 1;
        D_800F2A78 = 1;
        func_80045EE0();
        HuPrcChildLink(proc, func_800419D8(gs->curPlayerIndex));
        HuPrcChildWatch();
        D_800EE320 = 0;
        func_80045E6C(h1);
        func_80045E6C(h2);
        func_80045E6C(h3);
        D_800F3FF0 = func_800415E8(gs->curPlayerIndex);
        if (func_80046710() != -1) {
            func_800466C0();
            func_80057208(BoardSpaceGet(GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain, player->cur_space))->spaceType);
            goto landed;
        }
        SetPlayerAnimation(-1, 0, 2);
        while (D_800F3FF0 != 0) {
            if ((u16)BoardSpaceGet(GetAbsSpaceIndexFromChainSpaceIndex(player->next_chain, player->next_space))->unk2 & 0x8000) {
                func_80060468(0x127, 0);
                SetPlayerAnimation(-1, 2, 0);
                player->player_obj->unk_34 = 40.0f;
                player->player_obj->unk_38 = -4.0f;
                func_8004D4A8(gs->curPlayerIndex, 20);
            } else {
                if (((BoardPlayerObj*)player->player_obj)->unk_46 != 0) {
                    SetPlayerAnimation(-1, 0, 2);
                }
                func_8004D6FC(gs->curPlayerIndex, 19.0f);
            }
            player->cur_chain = player->next_chain;
            player->cur_space = player->next_space;
            player->next_space++;
            spaceIdx = GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain, player->cur_space);
            spc = BoardSpaceGet(spaceIdx);
            SetCurrentSpaceIndex(spaceIdx);
            switch (spc->spaceType) {
                case 1:
                case 2:
                case 3:
                case 4:
                case 6:
                case 8:
                case 9:
                    func_8004068C(gs->curPlayerIndex);
                    D_800F3FF0--;
                    SetSpaceStepAnim(spaceIdx);
                    break;
            }
            if (D_800F3FF0 != 0) {
                switch (spc->spaceType) {
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
                func_80057208(spc->spaceType);
            }
            D_800D86E8 = ExecuteEventForSpace(spaceIdx, 1);
            if (D_800D86EC < 0) {
                continue;
            }
            SetPlayerAnimation(-1, -1, 2);
            D_800D86E4 = 2;
            HuPrcSleep(-1);
        state2:
            if (D_800D86E8 & 1) {
                D_800D86E8 = ExecuteEventForSpace(GetCurrentSpaceIndex(), 2);
                if (D_800D86EC >= 0) {
                    D_800D86E4 = 3;
                    HuPrcSleep(-1);
                }
            }
        state3:
            if (D_800D86E8 & 2) {
                D_800F3FF0 = 0;
            } else {
                func_8003FEFC(gs->curPlayerIndex);
            }
        }
    landed:
        SetPlayerAnimation(-1, -1, 2);
        spaceIdx = GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain, player->cur_space);
        switch (BoardSpaceGet(spaceIdx)->spaceType) {
            case 4:
                func_80058910(-1, 0);
                player->happening_count++;
                break;
            case 2:
                player->red_count++;
                break;
            case 1:
                player->blue_count++;
                break;
            case 3:
                player->minigame_count++;
                break;
            case 6:
                func_80058910(-1, 0);
                player->chance_count++;
                break;
            case 8:
                player->mushroom_count++;
                break;
            case 9:
                player->bowser_count++;
                break;
        }
        func_80045EE0();
        D_800D86E4 = 4;
        D_800D86E8 = ExecuteEventForSpace(spaceIdx, 3);
        if (D_800D86EC >= 0) {
            HuPrcSleep(-1);
        state4:
            if (D_800D86E8 & 1) {
                D_800D86E8 = ExecuteEventForSpace(GetCurrentSpaceIndex(), 4);
                if (D_800D86EC >= 0) {
                    D_800D86E4 = 5;
                    HuPrcSleep(-1);
                }
            }
        state5:
            HuPrcSleep(30);
        }
        if (func_80046710() != -1) {
            func_800466C0();
        }
        func_8004CD84(&sp18);
        func_8004D1EC(&player->player_obj->unk_18, &sp18, &player->player_obj->unk_18, 8);
        spaceIdx = GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain, player->cur_space);
        spc = BoardSpaceGet(spaceIdx);
        if (D_800F2CDC == spaceIdx) {
            D_800F37E8++;
            win = CreateTextWindow(0x38, 0x3C, 0x12, 1);
            LoadStringIntoWindow(win, (void*)0x180, -1, -1);
            func_8006E070(win, 0);
            ShowTextWindow(win);
            func_8004DBD4(win, player->player_index);
            HideTextWindow(win);
            h1 = func_80045D84(2, 0xA0, 1);
            HuPrcChildLink(proc, func_80041F24(gs->curPlayerIndex));
            HuPrcChildWatch();
            func_80045E6C(h1);
            switch (func_80041664(gs->curPlayerIndex)) {
                case 0:
                    func_800587EC(0x65, 0, 1);
                    break;
                case 1:
                    func_800587EC(0x60, 0, 1);
                    break;
                case 2:
                    func_800587BC(0x45, 0, 3, 1);
                    break;
            }
            D_800F2CDC = -1;
            D_800D86E4 = 7;
            HuPrcSleep(-1);
        }
    state7:
        SetPlayerLandedSpaceType(-1, spc->spaceType);
        func_800546B4(gs->curPlayerIndex, player->turn_status);
        switch (spc->spaceType) {
            case 1:
                if (_CheckFlag(0x2C) != 0) {
                    HuPrcSleep(20);
                } else {
                    if (_CheckFlag(0x42) != 0) {
                        mult = 2;
                    } else {
                        mult = 1;
                    }
                    ShowPlayerCoinChange(gs->curPlayerIndex, mult * 3);
                    func_80055960(gs->curPlayerIndex, mult * 3);
                    HuPrcSleep(30);
                }
                break;
            case 2:
                if (_CheckFlag(0x2C) == 0) {
                    func_80058910(-1, 2);
                    if (_CheckFlag(0x42) != 0) {
                        mult = 2;
                    } else {
                        mult = 1;
                    }
                    ShowPlayerCoinChange(gs->curPlayerIndex, -(mult * 3));
                    func_80055960(gs->curPlayerIndex, -(mult * 3));
                    HuPrcSleep(30);
                } else {
                    HuPrcSleep(20);
                }
                break;
            case 3:
                D_800F2A78 = 0;
                HuPrcSleep(8);
                HuPrcChildLink(proc, func_80044680(gs->curPlayerIndex));
                HuPrcChildWatch();
                D_800D86E4 = 6;
                D_800D86EC = 2;
                D_800D86F0 = 1;
                D_800F65B8++;
                HuPrcSleep(-1);
            state6:
                HuPrcSleep(30);
                break;
            case 9:
                func_80058910(-1, 3);
                D_800D86E4 = 8;
                func_800587BC(0x46, 0, 3, 1);
                HuPrcSleep(-1);
            state8:
                HuPrcSleep(30);
                break;
            case 8:
                if ((s8)player->poisoned_flag != 0) {
                    break;
                }
                h1 = func_80045D84(2, 0xA0, 1);
                HuPrcChildLink(proc, func_80041C04(gs->curPlayerIndex));
                HuPrcChildWatch();
                func_80045E6C(h1);
                if (func_80041644(gs->curPlayerIndex) == 1) {
                    func_80052C44(-1, 5, 0, 6, 0);
                    HuPrcSleep(12);
                    func_80060618(0x451, player->player_index);
                    while (MBMotionCheck(player->player_obj) == 0) {
                        HuPrcVSleep();
                    }
                    func_800405DC(gs->curPlayerIndex);
                    goto roll;
                }
                win = CreateTextWindow(0x3C, 0x96, 0x12, 1);
                LoadStringIntoWindow(win, (void*)0x17B, -1, -1);
                func_8006E070(win, 0);
                ShowTextWindow(win);
                func_8004DBD4(win, player->player_index);
                HideTextWindow(win);
                func_80052C44(-1, 3, 0, 6, 0);
                HuPrcSleep(9);
                func_80060618(0x44A, player->player_index);
                player->poisoned_flag = 1;
                func_800405DC(gs->curPlayerIndex);
                HuPrcSleep(40);
                break;
        }
        D_800D86E4 = 9;
        D_800D86E8 = ExecuteEventForSpace(spaceIdx, 5);
        if (D_800D86EC >= 0) {
            HuPrcSleep(-1);
        state9:
            HuPrcSleep(30);
        }
    turn_end:
        D_800F2A78 = 0;
        if (gs->curPlayerIndex >= 3) {
            HuPrcChildLink(proc, func_800444DC());
            HuPrcChildWatch();
            if (gs->unk_1E >= 0) {
                D_800D86E4 = 0;
                if (gs->maxTurns >= 0 && gs->currentTurn >= gs->maxTurns) {
                    D_800D86EC = 0x23;
                } else {
                    D_800D86EC = 3;
                }
                D_800D86F0 = 1;
                n = 0;
                for (j = 0; j < 4; j++) {
                    n += func_80054730(j) == 1;
                }
                switch (n) {
                    case 0:
                    case 4:
                        D_800F64C6++;
                        break;
                    case 1:
                    case 3:
                        D_800F37A8++;
                        break;
                    case 2:
                        D_800EE986++;
                        break;
                }
                HuPrcSleep(-1);
            }
            func_80054868(3);
            while (func_80054FA8() != 0) {
                HuPrcVSleep();
            }
            if (gs->maxTurns >= 0 && gs->currentTurn >= gs->maxTurns) {
                D_800F2A78 = 0;
                HuPrcChildLink(proc, func_80047E54());
                HuPrcChildWatch();
                D_800D86EC = 0x20;
                D_800D86F0 = 1;
                HuPrcSleep(-1);
            }
        }
        if (func_80056FA8() != 0) {
            D_800D86E4 = 0;
            D_800D86EC = 1;
            HuPrcSleep(-1);
        }
        HuPrcSleep(4);
        HuPrcChildLink(proc, func_800531E8());
        HuPrcChildWatch();
        func_80056F40();
        for (i = 0; i < 4; i++) {
            func_80052FD4(i);
            func_80052E84(i);
            player = GetPlayerStruct(i);
            func_8003E174(player->player_obj);
            player->player_obj->unk_0A |= 2;
            func_8004CC8C(i, GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain, player->cur_space));
            func_8004CDA0(i);
        }
        func_8005884C(NULL);
        D_800D86E4 = 1;
    }
}
void func_800582E4(void) {
    HuPrcVSleep();
    func_8004A520();
    func_8004B5C4(3.0f);
    func_800591E0(((GwPlayer[GwSystem.curPlayerIndex].port))); //TODO: what arg type should this take?
    func_80056AF4();
    omOvlReturnEx(1);
    omOvlKill();
    HuPrcVSleep();
}

// CSE keeps i * 2 across PlayerIsCPU and re-tests i == cur before the second button test (masked 11)
#ifdef NON_MATCHING
void func_8005835C(void) {
    Vec2f sp10;
    s32 cur;
    s32 i;
    s32 port;

    while (1) {
        HuPrcVSleep();
        if (func_80072718() != 0 || D_800F2A78 == 0 || D_800ED0D2 == 3) {
            continue;
        }
        cur = GetCurrentPlayerIndex();
        for (i = 0; i < 4; i++) {
            if (ContDStkTrg[i] & 0x1000) {
                goto stick;
            }
            if (PlayerIsCPU(i) == 0) {
                port = GwPlayer[i].port;
                if (i == cur && D_800EE320 != 0 && (ContDStkTrg[port] & 0x4000)) {
                    goto start;
                }
                if (i == cur && D_800EE320 != 0 && (ContDStkTrg[port] & 0x10)) {
                    goto view;
                }
            }
        }
        continue;
    view:
        func_80041F84(cur);
        func_8003D20C((port));
        goto done;
    start:
        func_80041F84(i);
        func_800591E0((void*)port);
        func_80041FE0(i);
        continue;
    stick:
        func_80041F84(cur);
        func_8004B6D8(&sp10);
        func_8004B61C(&sp10);
        func_80052934(i);
    done:
        func_80041FE0(cur);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/57330", func_8005835C);
#endif

void func_800584F0(s32 arg0) {
    GW_PLAYER* player;
    s32 space;
    s32 i;

    for (i = 0; i < 4; i++) {
        player = GetPlayerStruct(i);
        space = GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain, player->cur_space);
        func_8004CC8C(i, space);
    }
    func_8004A510();
    func_8004B5C4(1.0f);
    func_8004B838(-1.0f);
    func_8002578C(1);
    switch ((u32)arg0) {
        case 0:
            switch (D_800D86E4) {
                case 0:
                case 1:
                    SetFadeInTypeAndTime(0, 0);
                    func_800530E4();
                    break;
                default:
                    SetFadeInTypeAndTime(0xFF, 0x10);
                    break;
            }
            func_8004B5DC(&GwPlayer[GwSystem.curPlayerIndex].player_obj->coords);
            omAddPrcObj(func_8005727C, 0xEFFF, 0, 0);
            omAddPrcObj(func_8005700C, 0x1005, 0, 0);
            omPrcSetStatBit(omAddPrcObj(func_8005835C, 0x1005, 0, 0), 0x80);
            D_800EE320 = 0;
            D_800F2A78 = 0;
            omAddPrcObj(func_80056E6C, 0x1005, 0, 0);
            func_80056E30(1);
            if (func_8000C4A0() < 0x7F) {
                func_8004220C();
            }
            break;
        case 1:
            func_8004B5DC(&GwPlayer[GwSystem.curPlayerIndex].player_obj->coords);
            for (i = 0; i < 4; i++) {
                func_800546B4(i, GetPlayerStruct(i)->turn_status);
            }
            omPrcSetStatBit(omAddPrcObj(func_800582E4, 0x1005, 0, 0), 0x80);
            D_800EE320 = 1;
            break;
        case 2:
            func_800559BC();
            func_80056E30(0);
            break;
    }
}
void ExecBoardScene(board_overlay_entrypoint* arg0, s16 arg1) {
    if (arg0->index < 0) {
        return;
    }
    for (; arg0->index >= 0; arg0++) {
        if (arg0->index == arg1) {
            arg0->fn();
        }
    }       
}

void func_800587BC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_800D86F4 = arg0;
    D_800D86F8 = arg1;
    D_800D86EC = 8;
    D_800D86EE = arg2;
    D_800D86F0 = arg3;
}

void func_800587EC(s32 arg0, s16 arg1, s16 arg2) {
    func_800587BC(arg0, arg1,  arg2, 0);
}

void func_80058818(s16 arg0, s16 arg1) {
    D_800D86EC = 0x10;
    D_800D86EE = arg0;
    D_800D86F0 = arg1;
    func_80056984();
}

void func_8005884C(Vec3f *coords) {
    f32 temp_f20;
    f32 temp_f22;

    func_8004A7DC();
    func_8004A7A4();
    temp_f22 = func_8004B844();
    func_8004B838(-1.0f);
    temp_f20 = func_8004B5D0();
    func_8004B5C4(1.0f);
    func_8004A510();

    if (coords == NULL) {
        coords = &GetPlayerStruct(-1)->player_obj->coords;
    }

    func_8004B5DC(coords);
    HuPrcVSleep();
    func_8004A520();
    func_8004B5C4(temp_f20);
    func_8004B838(temp_f22);
}
