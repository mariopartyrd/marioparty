#include "common.h"

void func_80052CCC(s32, s32);
s32 D_800C52D0[] = { 0xA0114, 0xA0115, 0xA0116, 0xA0117, 0xA0118, 0xA0119, 0xA011A, 0xA011B, 0, 0xA0100 };
s16 D_800C52F8 = 0;
/* Button sequence for func_8003EDDC: up up down down left right left right B A. */
u16 D_800C52FC[] = { 0x0800, 0x0800, 0x0400, 0x0400, 0x0200, 0x0100, 0x0200, 0x0100, 0x4000, 0x8000, 0, 0 };
s32 D_800C5314[] = { 0xA011D, 0xA011E, 0xA011F };
s16 D_800C5320[] = { 0x73, 0x73 };
s16 D_800C5324[] = { 0x8C, 0x8C };
s32 D_800C5328[] = { 1, 0x70003 }; /* MBModelCreate motion list: a count word, then file ids */
s32 D_800C5330[6] = { 0x157, 0x158, 0x159, 0x15A, 0x15B, 0x15C };
s32 D_800C5348[6] = { 0x16B, 0x16C, 0x16D, 0x16E, 0x16F, 0x170 };
s32 D_800C5360[2] = { 0x161, 0x162 };
s32 D_800C5368[2] = { 0x175, 0x176 };
s32 D_800C5370[] = { 0x166, 0x165, 0x164 };
s32 D_800C537C[] = { 0xA010C, 0xA010D, 0xA010E, 0xA010F, 0xA0110, 0xA0111 };
s32 D_800C5394[] = { 0x6E, 0x6F, 0x70, 0x71, 0x72, 0x73 };
s16 D_800C53AC[] = { 0x64, 0xDC, 0x64, 0xDC };
s16 D_800C53B4[] = { 0x28, 0x28, 0x68, 0x68 };
s16 D_800C53BC[][4] = { { 0, 2, 0, 1 }, { 0, 2, -1, 0 }, { -2, 0, 0, 1 }, { -2, 0, -1, 0 } };

/* Show message `a` (normal) or `b` (when flag 0x2C is set) in the menu's text window, once. */
#define SET_MENU_MESSAGE(msg, a, b)                                  \
    if (_CheckFlag(0x2C) == 0) {                                     \
        if (msg != (a)) {                                            \
            msg = (a);                                               \
            func_80050D1C(D_800D8370->unk8, (a));                    \
        }                                                            \
    } else {                                                         \
        if (msg != (b)) {                                            \
            msg = (b);                                               \
            func_80050D1C(D_800D8370->unk8, (b));                    \
        }                                                            \
    }


void func_8003EE68(s16, s16);
void func_8003EF98(s16, s16);
void func_8003F008(s16, s16);
void func_8003F07C(s16, s16);
void func_8003F1C0(s16, s16);
void func_8003F384(s16, s16);
s32 func_800559A8(void);
void func_800559BC(void);
void func_800559F8(void);
void func_800244C4(s16, u8);
s32 func_80051198(s32);
s32 func_80051428(s32);
s32 func_80051AE0(s32);
s32 func_80052614(s32);
extern s8 D_800F384E;
extern s16 D_800F329E;


s32 func_800141FC(s16);
extern s16 D_800D8378;


void func_8004D0B0(s16);

/* The menu windows below called func_8006D010 unprototyped (int return: no sign extension after
   the call). Every use passes the id on as an s16, so the s16 the function returns survives. */
#define CreateMenuWindow ((s32 (*)(s16, s16, s16, s16, s32, s16))func_8006D010)


typedef struct unk51200 {
/* 0x00 */ Object* obj;
/* 0x04 */ u16 unk4;
/* 0x06 */ s16 unk6;
/* 0x08 */ s16 unk8;
/* 0x0A */ s16 unkA;
} unk51200;

typedef struct unkMallocStruct {
/* 0x00 */ s32* unk0;
/* 0x04 */ s16 unk4;
} unkMallocStruct;

extern unk51200* D_800D8370;

void func_80050600(unk_Struct02* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    u8 asciiChar;
    void* temp_s6;
    s32 i;

    temp_s6 = DataRead(0x000A0122);
    sprintf(pfStrBuf, "%2d", arg2);
    for (i = 0; i < 2; i++, arg3 += 0x10) {
        asciiChar = pfStrBuf[i];
        if (asciiChar != ' ') {
            arg0->unk_0C[arg1] = func_800678A4(temp_s6);
            func_80067208(arg0->unk_0A, arg1, arg0->unk_0C[arg1], ASCII_DIGIT_TO_INT(asciiChar));
            func_80067384(arg0->unk_0A, arg1, 7U);
            func_800674BC(arg0->unk_0A, arg1, 0x01001000);
            func_80066DC4(arg0->unk_0A, arg1, arg3, arg4);
            func_80067558(arg0->unk_0A, arg1, 0xFF, 0xFF, 0xFF, 0xFF);
            arg1++;
        }        
    }
    DataClose(temp_s6);
}

unk_Struct02* func_8005077C(s16 arg0) {
    unk_Struct02* temp_s3;
    void* temp_v0;
    void* temp_v0_2;
    void* temp_v0_3;

    temp_s3 = func_800533F8(7, 0);
    temp_v0 = DataRead(D_800C5314[GwSystem.playType]);
    temp_s3->unk_0C[0] = func_800678A4(temp_v0);
    func_80067208(temp_s3->unk_0A, 0, temp_s3->unk_0C[0], 0);
    func_80067384(temp_s3->unk_0A, 0, 7);
    func_800674BC(temp_s3->unk_0A, 0, 0x1000);
    func_80066DC4(temp_s3->unk_0A, 0, 0xA0, D_800C5320[arg0]);
    func_80067558(temp_s3->unk_0A, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    DataClose(temp_v0);
    temp_v0 = DataRead(0xA0120);
    temp_s3->unk_0C[1] = func_800678A4(temp_v0);
    func_80067208(temp_s3->unk_0A, 1, temp_s3->unk_0C[1], 0);
    func_80067384(temp_s3->unk_0A, 1, 7);
    func_800674BC(temp_s3->unk_0A, 1, 0x1000);
    func_80066DC4(temp_s3->unk_0A, 1, 0x8C, D_800C5324[arg0]);
    func_80067558(temp_s3->unk_0A, 1, 0xFF, 0xFF, 0xFF, 0xFF);
    DataClose(temp_v0);
    switch (GwSystem.playType) {
    case 1:
        func_80050600(temp_s3, 2, GwSystem.maxTurns, 0xCA, D_800C5320[arg0]);
        break;
    case 0:
    case 2:
        func_80050600(temp_s3, 2, GwSystem.maxTurns, 0xAD, D_800C5320[arg0]);
    }
    func_80050600(temp_s3, 4, GwSystem.currentTurn, 0xB6, D_800C5324[arg0]);
    temp_v0 = DataRead(D_800C52D0[GwSystem.curBoardIndex]);
    temp_s3->unk_0C[6] = func_800678A4(temp_v0);
    func_80067208(temp_s3->unk_0A, 6, temp_s3->unk_0C[6], 0);
    func_80067384(temp_s3->unk_0A, 6, 7U);
    func_800674BC(temp_s3->unk_0A, 6, 0x1000);
    func_80066DC4(temp_s3->unk_0A, 6, 0xA0, 0x3C);
    DataClose(temp_v0);
    return temp_s3;
}


void func_80050A7C(unk_Struct02* arg0) {
    func_80053454(arg0);
}

s32 func_80050A98(s32 arg0) {
    s32 var_s0;
    s32 temp_s1;
    unk_Struct02* temp_s3;
    s32 temp_s4;
    s32 temp_s5;
    u16* temp_s0;

    temp_s1 = func_8003EDDC((s32*)D_800C52FC);
    temp_s5 = func_80045D84(9, 0xAE, 0);
    temp_s4 = func_80045D84(5, 0xBC, 0);
    temp_s3 = func_8005077C(0);
    HuPrcVSleep();
    temp_s0 = &ContBtnTrg[arg0];

    while (1) {
        HuPrcVSleep();
        if (D_800C52F8 != 0) {
            if ((*temp_s0 & 2) != 0) {
            var_s0 = 3;
            break;
            }
        } else  {
             if (func_8003EE58(temp_s1) != 0) {
                PlaySound(0x466);
                D_800C52F8 = 1;
                continue;
            }  
        }

        if (*temp_s0 & 0x8000) {
            var_s0 = 4;
            break;
        } else if (*temp_s0 & 0x1000) {
            var_s0 = 0;
            break;
        }
    }

    func_80050A7C(temp_s3);
    func_80045E6C(temp_s5);
    func_80045E6C(temp_s4);
    func_8003EE3C(temp_s1);
    return var_s0;
}

void func_80050BE0(Object* arg0, s16 arg1) {
    Object* temp_v0;
    s16 temp_s1;
    s32 i;
    s16 new_var;

    temp_s1 = arg0->unk_0A;
    temp_v0 = arg0->prev;
    temp_v0->unk_34 = 20.0f;
    temp_v0->unk_38 = -2.5f;
    
    
    if (_CheckFlag(0x2C) == 0) {
        MBMotionSet(arg0->prev, 0, 0);
    }

    new_var = (arg1 - temp_s1) / 14;

    for (i = 0; i < 14; i++, HuPrcVSleep()) {
        temp_s1 = arg0->unk_0A;
        func_800484C4(arg0, temp_s1 + new_var);
    }

    func_800484C4(arg0, arg1);
    if (_CheckFlag(0x2C) == 0) {
        while (!(MBMotionCheck(arg0->prev))) {
            HuPrcVSleep();
        }
        MBMotionSet(arg0->prev, -1, 2);
    }
}

void func_80050D1C(s16 arg0, s32 arg1) {
    func_8006EB40(arg0);
    LoadStringIntoWindow(arg0, (void*)arg1, -1, -1);
}

void func_80050D68(void) {
    s16 temp_v0_2;
    s16 var_s0;
    s32* temp_s2;
    s16 temp;
    Process* process = HuPrcCurrentGet();

    //TODO: sort out types here
    temp_s2 = ((unk51200*)process->user_data)->obj;
    temp = ((unk51200*)process->user_data)->unk4;
    var_s0 = -1;
    while (1) {
        temp_v0_2 = func_8007186C(temp);
        if ((temp_v0_2 != var_s0) & (~temp_v0_2 != 0)) {
            var_s0 = temp_v0_2;
            func_80050D1C(D_800D8370->unk8, temp_s2[temp_v0_2]);
        }
        HuPrcVSleep();        
    }
}

Process* func_80050E10(s16 arg0, s32* arg1) {
    Process* process;
    unkMallocStruct* processUserData;

    process = omAddPrcObj(&func_80050D68, 0x1005, 0, 0x40);
    processUserData = HuMemMemoryAlloc(process->heap, sizeof(unkMallocStruct));
    process->user_data = processUserData;
    processUserData->unk0 = arg1;
    processUserData->unk4 = arg0;
    return process;
}

void func_800484C4(Object*, s16);
Process* func_80050E10(s16, s32*);
void func_80071788(s16, s32);
void func_80072108(s16, s32);
extern s16 D_800D8374;
extern s16 D_800D8376;

s32 func_80050E7C(s32 arg0) {
    Process* var_s2;
    s16 var_s1;
    s32 temp_a0;
    s16 temp_v0_2;
    s16 var_s0;
    s32 var_v0;
    Object* temp_v1;
    s32 temp_v1_2;
    unk51200* temp_v0;
    void* var_a1;
    s32 temp;

    var_s0 = 0;
    var_s1 = -1;
    var_s2 = NULL;
    if (D_800D8376 == 0) {
        var_s1 = func_8006D010(0x6E, 0x32, 0x81, 0x5A, 0, 0);
        func_8006E0A4(var_s1, 5);
        func_8006E154(var_s1, 0);
        if (_CheckFlag(0x2C) == 0) {
            LoadStringIntoWindow(var_s1, (void* )0x156, -1, -1);
        } else {
            LoadStringIntoWindow(var_s1, (void* )0x16A, -1, -1);
        }
        func_8006E070(var_s1, 0);
        while (func_8006FCC0(var_s1) != 0) {
            HuPrcVSleep();
        }
        if (D_800D8370 == NULL) {
            HuPrcVSleep();
            temp_v0 = func_80048224(D_800C5328);
            D_800D8370 = temp_v0;
            func_8003E174(temp_v0->obj);
            func_800258EC(D_800D8370->obj->unk_3C->unk_40[0], 0x8000, 0x8000);
            temp_v1 = D_800D8370->obj;
            temp_v1->unk_0A |= 0x10;
            func_800484C4(D_800D8370, 0x104);
            func_80050BE0(D_800D8370, 0x69);
            func_80072108(D_800D8370->unk8, 5);
            func_80071C8C(D_800D8370->unk8, 1);
        }
        if (_CheckFlag(0x2C) == 0) {
            var_s2 = func_80050E10(var_s1, D_800C5330);
        } else {
            var_s2 = func_80050E10(var_s1, D_800C5348);
        }
        func_8007155C(var_s1, (0x10000 << arg0) >> 0x10);
        if (_CheckFlag(0x2C) != 0) {
            func_80071788(var_s1, 2);
        }
        /* retail passes the full s16 here (lh): this caller saw an s32 parameter, the callee takes s8 */
        temp_v0_2 = ((s32 (*)(s16, s32, s32)) func_8006FCF0)(var_s1, D_800D8374, 0);
        if (temp_v0_2 >= 0) {
            D_800D8374 = temp_v0_2;
        }
        switch (temp_v0_2) {
        case 0:
            var_s0 = 2;
            break;
        case 1:
            var_s0 = 5;
            break;
        case 2:
            var_s0 = 6;
            break;
        case 3:
            var_s0 = 7;
            break;
        case 4:
            var_s0 = 8;
            break;
        default:
            var_s0 = 1;
            break;
        }
    }
    if (var_s0 < 2) {
        if (var_s0 >= 0) {
            if (D_800D8370 != NULL) {
                func_80071E80(D_800D8370->unk8, 1);
                func_80050BE0(D_800D8370, 0x104);
                func_8004847C((mystery_struct_ret_func_80048224* ) D_800D8370);
                D_800D8370 = NULL;
            }
        }
    }
    if (var_s2 != NULL) {
        EndProcess(var_s2);
    }
    if (var_s1 != -1) {
        func_80070D90(var_s1);
    }
    return var_s0;
}

Process* func_80050E10(s16, s32*);



// decomp-permuter
s32 func_80051198(s32 arg0)
{
  Process *proc;
  s16 v;
  s32 win;
  GW_SYSTEM *system = &GwSystem;
  win = ((s32 (*)(s16, s16, s16, s16, s32, s16)) func_8006D010)(0x5A, 0x50, 0xA2, 0x22, 0, 0);
  func_8006E0A4(win, 5);
  func_8006E154(win, 0);
  LoadStringIntoWindow(win, (void *) 0x160, -1, -1);
  func_8006E070(win, 0);
  while (func_8006FCC0(win) != 0)
  {
    HuPrcVSleep();
  }

  if (_CheckFlag(0x2C) == 0)
  {
    proc = func_80050E10(win, D_800C5360);
  }
  else
  {
    proc = func_80050E10(win, D_800C5368);
  }
  func_8007155C(win, (s16) (1 << arg0));
  v = func_8006FCF0(win, system->minigameExplanation, 0);
  if (v >= 0)
  {
    if ((v && v) && v)
    {
    }
    system->minigameExplanation = v;
  }
  EndProcess(proc);
  func_80070D90(win);
  return 4;
}

s32 func_800512F4(s32 arg0) {
    Process* proc;
    s16 v;
    s32 win;
    GW_SYSTEM* system = &GwSystem;

    win = CreateMenuWindow(0x69, 0x46, 0x8C, 0x30, 0, 0);
    func_8006E0A4(win, 5);
    func_8006E154(win, 0);
    LoadStringIntoWindow(win, (void*)0x163, -1, -1);
    func_8006E070(win, 0);
    while (func_8006FCC0(win) != 0) {
        HuPrcVSleep();
    }
    proc = func_80050E10(win, D_800C5370);
    func_8007155C(win, (s16)(1 << arg0));
    v = func_8006FCF0(win, (s8)system->saveSetting, 0);
    if (v >= 0) {
        system->saveSetting = v;
    }
    EndProcess(proc);
    func_80070D90(win);
    return 4;
}
// decomp-permuter
s32 func_80051428(s32 arg0)
{
  short v;
  s32 win;
  s8 new_var;
  GW_SYSTEM *system = &GwSystem;
  win = ((s32 (*)(s16, s16, s16, s16, s32, s16)) func_8006D010)(0x87, 0x46, 0x34, 0x30, 0, 0);
  func_8006E0A4(win, 5);
  func_8006E154(win, 0);
  LoadStringIntoWindow(win, (void *) 0x169, -1, -1);
  func_8006E070(win, 0);
  while (func_8006FCC0(win) != 0)
  {
    HuPrcVSleep();
  }

  func_8007155C(win, (s16) (1 << arg0));
  v = func_8006FCF0(win, (s8) system->messageSpeed, 0);
  if (((s16) v) >= 0)
  {
    new_var = (s8) v;
    system->messageSpeed = v;
    func_8004D0B0(new_var);
  }
  func_80070D90(win);
  return 4;
}
s32 func_80051548(s32 arg0) {
    s32 win;

    win = CreateMenuWindow(0x5F, 0x46, 0x8C, 0x30, 0, 0);
    func_8006E0A4(win, 5);
    func_8006E154(win, 0);
    LoadStringIntoWindow(win, (void*)0x168, -1, -1);
    func_8006E070(win, 0);
    while (func_8006FCC0(win) != 0) {
        HuPrcVSleep();
    }
    func_8007155C(win, (s16)(1 << arg0));
    if ((s16)func_8006FCF0(win, 0, 0) == 1) {
        D_800D8376 = 1;
    }
    func_80070D90(win);
    return 4;
}
s32 func_8005165C(s16 arg0) {
    GW_PLAYER* player;
    s32 i;

    for (i = 0; i < 4; i++) {
        player = GetPlayerStruct(i);
        if (!(player->flags & 1) && player->port == arg0) {
            return 1;
        }
    }
    return 0;
}
void func_800516C8(GW_PLAYER* arg0, s16 arg1) {
    GW_PLAYER* player;
    u8 port = arg0->port;
    s32 i;

    if (arg1 < 4) {
        for (i = 0; i < 4; i++) {
            player = GetPlayerStruct(i);
            if (player->port == arg1) {
                player->port = port;
                arg0->port = arg1;
                arg0->flags &= ~1;
                return;
            }
        }
    } else {
        arg0->flags |= 1;
    }
}
// decomp-permuter
s32 func_80051778(GW_PLAYER *arg0, s16 arg1)
{
  s16 step = arg1;
  s32 tries;
  u32 port;
  if (PlayerIsCPU(arg0->player_index) != 0)
  {
    tries = 4;
    port = (step > 0) ? (0) : (3);
    do
    {
      if ((func_8005165C(port) == 0) && (func_800141FC(port) != 0))
      {
        return port;
      }
      port += arg1;
    }
    while ((--tries) != 0);
    return -1;
  }
  if (arg1 > 0)
  {
    port = arg0->port + 1;
  }
  else
  {
    port = arg0->port - 1;
  }
  for (; port < 4; port += arg1)
  {
    if ((func_8005165C(port) == 0) && (func_800141FC(port) != 0))
    {
      return port;
    }
  }

  return 4;
}
void func_8005188C(s16 arg0) {
    D_800D8378 = arg0;
}
void func_80051898(unk_Struct02* arg0, s16 arg1) {
    func_80066DC4(arg0->unk_0A, 0, D_800C53AC[arg1], D_800C53B4[arg1]);
    func_80066DC4(arg0->unk_0A, 1, D_800C53AC[arg1] + 32, D_800C53B4[arg1] + 27);
    func_80066DC4(arg0->unk_0A, 2, D_800C53AC[arg1] - 32, D_800C53B4[arg1] + 27);
}
void func_80051954(void) {
    unk_Struct02* sprite = HuPrcCurrentGet()->user_data;
    f32 angle = 0.0f;
    s16 alpha;

    while (1) {
        HuPrcVSleep();
        if (D_800D8378 != 0) {
            alpha = func_800AEAC0(angle) * 255.0f;
            alpha = (alpha < 0) ? -alpha : alpha;
            angle += 6.0f;
            if (angle > 360.0f) {
                angle -= 360.0f;
            }
            func_80067558(sprite->unk_0A, 0, 0xFF, alpha, 0, 0xC0);
            func_80067558(sprite->unk_0A, 1, 0xFF, alpha, 0, 0xC0);
            func_80067558(sprite->unk_0A, 2, 0xFF, alpha, 0, 0xC0);
            func_80067480(sprite->unk_0A, 1, 0x8000);
            func_80067480(sprite->unk_0A, 2, 0x8000);
        } else {
            angle = 0.0f;
            func_80067558(sprite->unk_0A, 0, 0, 0, 0xFF, 0xC0);
            func_800674BC(sprite->unk_0A, 1, 0x8000);
            func_800674BC(sprite->unk_0A, 2, 0x8000);
        }
    }
}
// register allocation and stack spills only; retail spills the sprite groups and keeps stk in s8 (masked 103 of 872)
#ifdef NON_MATCHING
s32 func_80051AE0(s32 arg0) {
    s32 msg = 0;
    s16 sel = 0;
    u16* stk;
    u16* btn;
    unk_Struct02* faces;
    unk_Struct02* ports;
    unk_Struct02* cursor;
    unk_Struct02* box;
    Process* proc;
    GW_PLAYER* player;
    void* data;
    s32 i;
    s16 dir;
    s32 port;
    s16 v;
    s32 win;

    for (i = 0; i < 4; i++) {
        if (PlayerIsCPU(i) == 0 && GwPlayer[i].port == arg0) {
            sel = i;
            break;
        }
    }
    faces = func_800533F8(8, 0);
    for (i = 0; i < 4; i++) {
        player = GetPlayerStruct(i);
        data = DataRead(D_800C537C[player->character]);
        faces->unk_0C[i] = func_800678A4(data);
        func_80067208(faces->unk_0A, i, faces->unk_0C[i], 0);
        func_80067384(faces->unk_0A, i, 7);
        func_800674BC(faces->unk_0A, i, 0x1000);
        func_80066DC4(faces->unk_0A, i, D_800C53AC[i] - 30, D_800C53B4[i]);
        DataClose(data);
        data = DataRead(D_800C5394[player->character]);
        faces->unk_0C[i + 4] = func_800678A4(data);
        func_80067208(faces->unk_0A, i + 4, faces->unk_0C[i + 4], 0);
        func_80067384(faces->unk_0A, i + 4, 7);
        func_800674BC(faces->unk_0A, i + 4, 0x1000);
        func_80066DC4(faces->unk_0A, i + 4, D_800C53AC[i] + 8, D_800C53B4[i]);
        DataClose(data);
    }
    data = DataRead(0x90024);
    ports = func_800533F8(4, 0);
    for (i = 0; i < 4; i++) {
        ports->unk_0C[i] = func_800678A4(data);
        if (PlayerIsCPU(i) != 0) {
            func_80067208(ports->unk_0A, i, ports->unk_0C[i], 4);
        } else {
            func_80067208(ports->unk_0A, i, ports->unk_0C[i], GwPlayer[i].port);
        }
        func_80067384(ports->unk_0A, i, 7);
        func_800674BC(ports->unk_0A, i, 0x01001000);
        func_80066DC4(ports->unk_0A, i, D_800C53AC[i] - 16, D_800C53B4[i] + 46);
    }
    DataClose(data);
    cursor = func_800533F8(3, 0);
    data = DataRead(0xA0020);
    cursor->unk_0C[0] = func_800678A4(data);
    func_80067208(cursor->unk_0A, 0, cursor->unk_0C[0], 0);
    func_800674BC(cursor->unk_0A, 0, 0x1808);
    func_80067384(cursor->unk_0A, 0, 8);
    func_80067558(cursor->unk_0A, 0, 0, 0, 0xFF, 0x80);
    DataClose(data);
    data = DataRead(0xA0113);
    cursor->unk_0C[1] = func_800678A4(data);
    func_80067208(cursor->unk_0A, 1, cursor->unk_0C[1], 0);
    func_800674BC(cursor->unk_0A, 1, 0x9808);
    func_80067384(cursor->unk_0A, 1, 8);
    func_80067558(cursor->unk_0A, 1, 0xFF, 0, 0, 0x80);
    DataClose(data);
    data = DataRead(0xA0112);
    cursor->unk_0C[2] = func_800678A4(data);
    func_80067208(cursor->unk_0A, 2, cursor->unk_0C[2], 0);
    func_800674BC(cursor->unk_0A, 2, 0x9808);
    func_80067384(cursor->unk_0A, 2, 8);
    func_80067558(cursor->unk_0A, 2, 0xFF, 0, 0, 0x80);
    DataClose(data);
    func_80051898(cursor, sel);
    func_8005188C(0);
    proc = omAddPrcObj(func_80051954, 0x1005, 0, 0);
    proc->user_data = cursor;
    stk = &ContDStkTrg[arg0];
    btn = &ContBtnTrg[arg0];
    do {
        SET_MENU_MESSAGE(msg, 0x15D, 0x171);
        HuPrcVSleep();
        dir = -1;
        if (*stk & 0x800) {
            dir = 0;
        }
        if (*stk & 0x400) {
            dir = 1;
        }
        if (*stk & 0x200) {
            dir = 2;
        }
        if (*stk & 0x100) {
            dir = 3;
        }
        if (dir != -1) {
            sel += D_800C53BC[sel][dir];
            func_80051898(cursor, sel);
            PlaySound(0xF5);
        } else if (*btn & 0x8000) {
            PlaySound(0xF6);
            player = GetPlayerStruct(sel);
            func_8005188C(1);
            while (1) {
                HuPrcVSleep();
                SET_MENU_MESSAGE(msg, 0x15E, 0x172);
                port = -1;
                if (*stk & 0x200) {
                    port = func_80051778(player, -1);
                    PlaySound(0xF5);
                } else if (*stk & 0x100) {
                    port = func_80051778(player, 1);
                    PlaySound(0xF5);
                }
                if (port >= 0) {
                    func_800516C8(player, port);
                    if (PlayerIsCPU(sel) != 0) {
                        func_80067208(ports->unk_0A, sel, ports->unk_0C[sel], 4);
                    } else {
                        func_80067208(ports->unk_0A, sel, ports->unk_0C[sel], GwPlayer[sel].port);
                    }
                    continue;
                }
                if (*stk & 0x8000) {
                    PlaySound(0xF6);
                    if (PlayerIsCPU(sel) != 0) {
                        v = player->cpu_difficulty_copy;
                        SET_MENU_MESSAGE(msg, 0x15F, 0x173);
                        box = func_800533F8(1, 0);
                        data = DataRead(0xA0123);
                        box->unk_0C[0] = func_800678A4(data);
                        func_80067208(box->unk_0A, 0, box->unk_0C[0], 0);
                        func_800674BC(box->unk_0A, 0, 0x1808);
                        func_80067384(box->unk_0A, 0, 6);
                        func_80066DC4(box->unk_0A, 0, D_800C53AC[sel] + 44, D_800C53B4[sel] + 40);
                        DataClose(data);
                        win = CreateMenuWindow(D_800C53AC[sel] + 14, D_800C53B4[sel] + 10, 0x3F, 0x3E, 0, 0);
                        func_8006E0A4(win, 5);
                        func_8006E154(win, 0);
                        func_8006E2B8(win, 0xC0, 0xC0, 0xC0);
                        LoadStringIntoWindow(win, (void*)0x167, -1, -1);
                        func_8006E070(win, 0);
                        while (func_8006FCC0(win) != 0) {
                            HuPrcVSleep();
                        }
                        func_8007155C(win, (s16)(1 << arg0));
                        v = func_8006FCF0(win, v, 0);
                        if (v >= 0) {
                            func_80052CCC(sel, v & 0xFF);
                            HuPrcSleep(10);
                        }
                        func_80070D90(win);
                        func_80053454(box);
                        if (v < 0) {
                            continue;
                        }
                    }
                    break;
                }
                if (*stk & 0x4000) {
                    PlaySound(0xF8);
                    break;
                }
            }
            func_8005188C(0);
            HuPrcVSleep();
        }
    } while (!(*btn & 0x4000));
    PlaySound(0xF8);
    EndProcess(proc);
    func_80053454(cursor);
    func_80053454(ports);
    func_80053454(faces);
    return 4;
}
#else
INCLUDE_ASM("asm/nonmatchings/51200", func_80051AE0);
#endif
// retail holds the return value 1 in s2 across the loop; this returns it with li (masked 5)
#ifdef NON_MATCHING
s32 func_80052614(s32 arg0) {
    s32 id = func_80045D84(8, 0xBC, 0);

    do {
        HuPrcVSleep();
        func_8003F384(3, 3);
        func_8003EE68(3, 5);
        func_8003F008(3, 11);
        func_8003F07C(3, 13);
        func_8003EF98(3, 18);
        func_8003F1C0(13, 11);
    } while (!(ContBtnTrg[arg0] & 0x4000));
    func_80045E6C(id);
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/51200", func_80052614);
#endif
s16 func_800526D8(s16 arg0, s32 arg1) {
    switch (arg0) {
    case 1:
        return func_80050A98(arg1);
    case 2:
        return func_80051AE0(arg1);
    case 4:
        return func_80050E7C(arg1);
    case 5:
        return func_80051198(arg1);
    case 6:
        return func_800512F4(arg1);
    case 7:
        return func_80051428(arg1);
    case 8:
        return func_80051548(arg1);
    case 3:
        return func_80052614(arg1);
    }
    return 0;
}
void func_800527A0(void) {
    s32 arg = (s32)(HuPrcCurrentGet()->user_data);
    s16 state = 1;
    s16 paused = func_800559A8();
    unk_Struct02* sprite;
    void* data;

    if (paused != 0) {
        func_800559BC();
    }
    HuPrcVSleep();
    D_800F384E = 1;
    sprite = func_800533F8(1, 0);
    data = DataRead(0xA012A);
    sprite->unk_0C[0] = func_800678A4(data);
    func_80067208(sprite->unk_0A, 0, sprite->unk_0C[0], 0);
    func_80067384(sprite->unk_0A, 0, 9);
    func_800674BC(sprite->unk_0A, 0, 0x1000);
    func_80066DC4(sprite->unk_0A, 0, 0xA0, 0x78);
    func_80067354(sprite->unk_0A, 0, 40.0f, 30.0f);
    func_80067558(sprite->unk_0A, 0, 0, 0, 0, 0xC0);
    DataClose(data);
    do {
        HuPrcVSleep();
        state = func_800526D8(state, arg);
    } while (state != 0);
    if (D_800D8376 == 0) {
        D_800F384E = 0;
    }
    func_80053454(sprite);
    if (paused != 0) {
        func_800559F8();
    }
    EndProcess(NULL);
}
void func_80052934(s32 arg0) {
    Process* parent;
    Process* proc;

    D_800ECC22 = 1;
    func_8005FD7C();
    func_80060214(0x60);
    func_800244C4(D_800F329E, 2);
    func_80025F10(D_800F329E, 1);
    D_800D8370 = NULL;
    D_800D8374 = 0;
    D_800D8376 = 0;
    parent = HuPrcCurrentGet();
    proc = omAddPrcObj(func_800527A0, 0xEFFF, 0, 0);
    proc->user_data = (void*)arg0;
    omPrcSetStatBit(proc, 0x80);
    HuPrcChildLink(parent, proc);
    HuPrcChildWatch();
    func_800244C4(D_800F329E, 6);
    func_80060214(0x7F);
    if (D_800D8376 != 0) {
        func_800601D4(0x5A);
        func_800726AC(0, 0x10);
        HuPrcSleep(0x11);
        func_80056AF4();
        func_80056984();
        omOvlReturnEx(1);
        omOvlKill();
        HuPrcVSleep();
    }
    func_8005FECC();
    D_800ECC22 = 0;
}