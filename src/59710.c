#include "common.h"

typedef struct {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
} MapIconPos;
MapIconPos D_800C5700[4] = { { 34, 128 }, { 286, 128 }, { 160, 24 }, { 160, 216 } };
f32 D_800C5710[4] = { 90.0f, -90.0f, 0.0f, 180.0f };

extern Object* D_800D8710[4];
extern s16 D_800EE320;
extern u16 ContDStk[];

void func_8004CC14(s16, s16, Vec3f*);
void func_8004B7F8(s32);
void func_800559BC(void);
void func_800559F8(void);
f32 func_8004B844(void);
s16 func_80056990(void);
void func_800406E4(s32);
void func_80040724(s32);
void func_8004A7A4(void);
void func_8004A7DC(void);
f32 func_8004B5D0(void);

unk_Struct02* func_80058B10(void) {
    unk_Struct02* icons = func_800533F8(4, 0);
    void* data = DataRead(0xA010A);
    s32 i;

    for (i = 0; i < 4; i++) {
        icons->unk_0C[i] = func_800678A4(data);
        func_80067208(icons->unk_0A, i, icons->unk_0C[i], 0);
        func_80067384(icons->unk_0A, i, 0);
        func_800674BC(icons->unk_0A, i, 0x9800);
        func_80066DC4(icons->unk_0A, i, D_800C5700[i].x, D_800C5700[i].y);
        func_800673B0(icons->unk_0A, i, D_800C5710[i]);
    }
    DataClose(data);
    return icons;
}

void func_80058C28(unk_Struct02* icons) {
    func_80053454(icons);
}

void func_80058C44(unk_Struct02* icons, u16 mask) {
    s32 i;

    i = 0;
    do {
        if ((mask >> i) & 1) {
            func_800674BC(icons->unk_0A, i, 0x8000);
            i++;
        } else {
            func_80067480(icons->unk_0A, i, 0x8000);
            i++;
        }
    } while (i < 4);
}

void func_80058CC4(void) {
    s32 i;
    GW_PLAYER* player;
    s16 idx;

    for (i = 0; i < 4; i++) {
        player = GetPlayerStruct(i);
        MBModelDispOff(player->player_obj);
        idx = i;
        D_800D8710[i] = MBModelCreate(func_80052F6C(idx), NULL);
        func_8004CC14(idx, GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain, player->cur_space), &D_800D8710[i]->coords);
        func_800A0D00(&D_800D8710[i]->xScale, 1.2f, 1.2f, 1.2f);
    }
}

void func_80058DB0(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        MBModelDispOn(GetPlayerStruct(i)->player_obj);
        MBModelKill(D_800D8710[i]);
    }
}

void func_80058E14(void) {
    func_80058CC4();
    func_8004B7F8(0xA0);
}

void func_80058E38(void) {
    func_80058DB0();
    func_8004B7F8(0xFF);
    func_800559F8();
}

// decomp-permuter
void func_80058E64(omObjData *arg0)
{
  unsigned short step;
  Vec2f saved;
  Vec2f cam;
  f32 zoom;
  f32 scale;
  s32 port;
  s32 label2;
  unk_Struct02 *icons;
  s32 label1;
  s16 moved;
  label2 = 0;
  port = (s32) (HuPrcCurrentGet()->user_data);
  moved = 0;
  zoom = func_8004B844();
  if (func_80056990() == 0)
  {
    func_800726AC(6, 8);
    HuPrcSleep(8);
    func_800405DC(GwSystem.curPlayerIndex);
    func_800406E4(GwSystem.curPlayerIndex);
    func_80060214(0x60);
  }
  func_80058E14();
  SetFadeInTypeAndTime(6, 8);
  HuPrcSleep(7);
  icons = func_80058B10();
  label1 = func_80045D84(4, 0xA0, 0);
  if (D_800F3FF0 != 0)
  {
    label2 = func_80045D84(6, 0x3C, 0);
  }
  func_8004B6D8(&saved);
  func_8004B838(4.0f);
  do
  {
    HuPrcVSleep();
    func_8004B6D8(&cam);
    func_80058C44(icons, func_8004B61C(&cam));
    step = 16;
    if (ContDStk[port] & 0x200)
    {
      cam.x -= 16.0f;
      moved = 15;
    }
    if (ContDStk[port] & 0x100)
    {
      cam.x += step;
      moved = 15;
    }
    if (ContDStk[port] & 0x800)
    {
      cam.y -= step;
      moved = 15;
    }
    if (ContDStk[port] & 0x400)
    {
      cam.y += step;
      moved = 15;
    }
    func_8004B61C(&cam);
    if (moved != 0)
    {
      moved--;
      func_800559BC();
    }
    else
    {
      func_800559F8();
    }
  }
  while ((D_800EE320 != 0) && (!(ContDStkTrg[port] & 0xE010)));
  func_80045E6C(label1);
  if (label2 != 0)
  {
    func_80045E6C(label2);
  }
  func_80058C28(icons);
  func_800726AC(6, 8);
  HuPrcSleep(8);
  if (func_80056990() == 0)
  {
    func_8004A7DC();
    func_8004A7A4();
    func_8004B838(-1.0f);
    scale = func_8004B5D0();
    func_8004B5C4(1.0f);
    func_8004A510();
    func_8004B61C(&saved);
    HuPrcVSleep();
    func_8004A520();
    func_8004B5C4(scale);
    func_8003FEFC(GwSystem.curPlayerIndex);
    func_80040724(GwSystem.curPlayerIndex);
    func_80058E38();
    func_80060214(0x7F);
    SetFadeInTypeAndTime(6, 8);
    HuPrcSleep(7);
  }
  else
  {
    func_80058E38();
  }
  func_8004B838(zoom);
  EndProcess(0);
}

//TODO: typing of arg is strange
void func_800591E0(void* arg0) { 
    Process* process;
    Process* process_child;

    D_800ECC22 = 1;
    func_8005FD7C();
    process = HuPrcCurrentGet();
    process_child = omAddPrcObj(func_80058E64, 0x1005U, 0, 0);
    process_child->user_data = arg0;
    omPrcSetStatBit(process_child, 0x80);
    HuPrcChildLink(process, process_child);
    HuPrcChildWatch();
    func_8005FECC();
    D_800ECC22 = 0;
}

