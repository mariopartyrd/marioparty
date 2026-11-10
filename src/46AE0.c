#include "common.h"
#include "spaces.h"

extern s16 D_800D6480;
extern s16 D_800D6482;

void func_80056E30(s16);
void SwapPlayerLocationData(s16, s16);
void func_8004A7A4(void);
void func_8004A7DC(void);
f32 func_8004B5D0(void);
f32 func_8004B844(void);
s32 func_80045EF8(s16 a, s16 b);
void func_80046180(void);

void func_80045EE0(void) {
    D_800D6480 = -1;
    D_800D6482 = -1;
}

// delay slot: bne+li filled as bnel (masked 1)
#ifdef NON_MATCHING
s32 func_80045EF8(s16 a, s16 b) {
    GW_PLAYER* p0;
    GW_PLAYER* p1;
    s32 i;
    s32 ret;

    for (i = 0; i < 4; i++) {
        p0 = GetPlayerStruct(i);
        switch (BoardSpaceGet(GetAbsSpaceIndexFromChainSpaceIndex(p0->cur_chain, p0->cur_space))->spaceType) {
            case 0:
            case 5:
            case 7:
                return 0;
        }
    }
    p0 = GetPlayerStruct(a);
    p1 = GetPlayerStruct(b);
    return (p0->cur_chain != p1->cur_chain) ? 1 : ((s16)p0->cur_space != (s16)p1->cur_space);
}
#else
INCLUDE_ASM("asm/nonmatchings/46AE0", func_80045EF8);
#endif

void func_80045FF4(s16 a, s16 b) {
    if (b == GetCurrentPlayerIndex()) {
        D_800D6480 = b;
        D_800D6482 = a;
    } else {
        D_800D6480 = a;
        D_800D6482 = b;
    }
}

s32 func_8004606C(void) {
    s16 order[4];
    GW_PLAYER* cur;
    s32 i;
    s32 b;
    s32 a;
    u16 tmp;

    cur = GetPlayerStruct(-1);
    for (i = 0; i < 4; i++) {
        order[i] = i;
    }
    for (i = 0; i < 30; i++) {
        a = rand8() & 3;
        b = rand8() & 3;
        tmp = order[a];
        order[a] = order[b];
        order[b] = tmp;
    }
    for (i = 0; i < 4; i++) {
        a = order[i];
        if (cur->player_index != a && func_80045EF8(cur->player_index, a) != 0) {
            break;
        }
    }
    if (i == 4) {
        return 0;
    }
    func_80045FF4(cur->player_index, a);
    return 1;
}

// decomp-permuter
void func_80046180(void)
{
  GW_PLAYER *p0;
  GW_PLAYER *p1;
  Object *o0;
  Object *o1;
  Object *fx;
  s32 i;
  f32 f;
  f32 g;
  f32 h;
  f32 camA;
  f32 camB;
  func_80056E30(0);
  p0 = GetPlayerStruct(D_800D6480);
  p1 = GetPlayerStruct(D_800D6482);
  p0->flags |= 4;
  p1->flags |= 4;
  o0 = p0->player_obj;
  o1 = p1->player_obj;
  PlaySound(0x47);
  fx = MBModelCreate(0x64, 0);
  MBMotionSet(fx, -1, 0);
  func_800A0D50(&fx->coords, &o0->coords);
  for (i = 0; i < 15; i++)
  {
    f = i / 15.0f;
    g = 1.0f - f;
    h = f + 1.0f;
    o0->xScale = g;
    o0->yScale = h;
    o0->zScale = g;
    o0->unk_30 += 6.0f;
    HuPrcVSleep();
  }

  o0->xScale = 0.0f;
  o0->yScale = 0.0f;
  o0->zScale = 0.0f;
  HuPrcVSleep();
  o0->unk_0A &= ~2;
  MBModelDispOff(o0);
  MBModelKill(fx);
  PlaySound(0x47);
  fx = MBModelCreate(0x64, 0);
  MBMotionSet(fx, -1, 0);
  func_800A0D50(&fx->coords, &o1->coords);
  for (i = 0; i < 15; i++)
  {
    f = i / 15.0f;
    g = 1.0f - f;
    h = f + 1.0f;
    o1->xScale = g;
    o1->yScale = h;
    o1->zScale = g;
    o1->unk_30 += 6.0f;
    HuPrcVSleep();
  }

  MBModelKill(fx);
  SwapPlayerLocationData(D_800D6480, D_800D6482);
  func_8004CC8C(D_800D6480, GetAbsSpaceIndexFromChainSpaceIndex(p0->cur_chain, p0->cur_space));
  func_8004CC8C(D_800D6482, GetAbsSpaceIndexFromChainSpaceIndex(p1->cur_chain, p1->cur_space));
  PlaySound(0x47);
  fx = MBModelCreate(0x64, 0);
  MBMotionSet(fx, -1, 0);
  func_800A0D50(&fx->coords, &o1->coords);
  for (i = 14; i >= 0; i--)
  {
    f = i / 15.0f;
    g = 1.0f - f;
    h = f + 1.0f;
    o1->xScale = g;
    o1->yScale = h;
    o1->zScale = g;
    o1->unk_30 -= 6.0f;
    HuPrcVSleep();
  }

  MBModelKill(fx);
  func_800726AC(6, 16);
  HuPrcSleep(16);
  func_8004A7DC();
  func_8004A7A4();
  camA = func_8004B844();
  func_8004B838(-1.0f);
  camB = func_8004B5D0();
  func_8004B5C4(1.0f);
  func_8004A510();
  func_8004B5DC(&o0->coords);
  HuPrcVSleep();
  func_8004A520();
  func_8004B5C4(camB);
  func_8004B838(camA);
  SetFadeInTypeAndTime(6, 16);
  HuPrcSleep(16);
  PlaySound(0x47);
  o0->unk_0A |= 2;
  MBModelDispOn(o0);
  fx = MBModelCreate(0x64, 0);
  MBMotionSet(fx, -1, 0);
  func_800A0D50(&fx->coords, &o0->coords);
  for (i = 14; i >= 0; i--)
  {
    if (p0)
    {
      f = i / 15.0f;
      g = 1.0f - f;
      h = f + 1.0f;
      o0->xScale = g;
      o0->yScale = h;
      o0->zScale = g;
      o0->unk_30 -= 6.0f;
      HuPrcVSleep();
    }
    else
    {
      f = i / 15.0f;
      g = 1.0f - f;
      h = f + 1.0f;
      o0->xScale = g;
      o0->yScale = h;
      o0->zScale = g;
      o0->unk_30 -= 6.0f;
      HuPrcVSleep();
    }
  }

  MBModelKill(fx);
  p0->flags &= ~4;
  p1->flags &= ~4;
  if (D_800D6480 != GetCurrentPlayerIndex())
  {
    HuPrcSleep(15);
    func_800726AC(6, 16);
    HuPrcSleep(16);
    func_8004A7DC();
    func_8004A7A4();
    camA = func_8004B844();
    func_8004B838(-1.0f);
    camB = func_8004B5D0();
    func_8004B5C4(1.0f);
    func_8004A510();
    func_8004B5DC(&GetPlayerStruct(-1)->player_obj->coords);
    HuPrcVSleep();
    func_8004A520();
    func_8004B5C4(camB);
    func_8004B838(camA);
    SetFadeInTypeAndTime(6, 16);
    HuPrcSleep(16);
  }
  HuPrcSleep(15);
  func_80056E30(1);
  func_80045EE0();
  EndProcess(0);
}

void func_800466C0(void) {
    HuPrcChildLink(HuPrcCurrentGet(), omAddPrcObj(func_80046180, 0x1003, 0, 0));
    HuPrcChildWatch();
}

s16 func_80046710(void) {
    return D_800D6480;
}
