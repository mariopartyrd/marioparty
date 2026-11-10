#include "common.h"

/* Controller-port bit per port (as 4E530.c's PortMasks). */
typedef struct {
    u8 bit[4];
} PortMasks_57;

void func_800F7768_name_57(void);
void func_800F7A08_name_57(omObjData* obj);
void func_800F798C_name_57(omObjData* obj);
void func_800F7A78_name_57(void);
void func_800F7D5C_name_57(void);
void func_800F7DF4_name_57(void);
void func_800F7E94_name_57(void);
void func_800F68B8_name_57(void);
void func_800F6D48_name_57(void);
void func_800F6FA4_name_57(void);
void func_800F74E8_name_57(f32 angle);
void func_8004DBD4(s32, u8);
s32 func_8004D8A4(void);
void func_80055994(u8, s32);

Object* D_800F7EC0_name_57 = NULL; /* star flying to the player */
Object* D_800F7EC4_name_57 = NULL; /* coin bag flying to Bowser */
s32 D_800F7EC8_name_57 = 0;        /* 1: the player declined; low half is passed on as s16 */
void* D_800F7ECC_name_57 = NULL;   /* func_80042728 handle */
Vec3f D_800F7ED0_name_57 = { -225.0f, -45.5f, 350.0f };
Vec3f D_800F7EDC_name_57 = { -225.0f, -45.5f, 350.0f };
Vec3f D_800F7EE8_name_57 = { 175.0f, -75.0f, 750.0f };
s32 D_800F7EF4_name_57 = 0x141;
s32 D_800F7EF8_name_57[] = { 2, 0x000A006A, 0x000A0068 };
s32 D_800F7F04_name_57[] = { 2, 0x00070003, 0x00070000 };
s32 D_800F7F10_name_57[] = { 3, 0x0001000F, 0x0001003E, 0x00010095 };
s32 D_800F7F20_name_57[] = { 3, 0x0002000F, 0x0002003E, 0x00020095 };
s32 D_800F7F30_name_57[] = { 3, 0x0006000F, 0x0006003E, 0x00060095 };
s32 D_800F7F40_name_57[] = { 3, 0x0003000F, 0x0003003E, 0x00030095 };
s32 D_800F7F50_name_57[] = { 3, 0x0004000F, 0x0004003E, 0x00040095 };
s32 D_800F7F60_name_57[] = { 3, 0x0005000F, 0x0005003E, 0x00050095 };
s32* D_800F7F70_name_57[] = {
    D_800F7F10_name_57, D_800F7F20_name_57, D_800F7F30_name_57,
    D_800F7F40_name_57, D_800F7F50_name_57, D_800F7F60_name_57, NULL, NULL,
};
const PortMasks_57 D_800F7F90_name_57 = { { 1, 2, 4, 8 } };

extern u8 D_800F7FC0_name_57;
extern Object* D_800F7FC4_name_57;
extern Object* D_800F7FC8_name_57;
extern Object* D_800F7FCC_name_57;
extern Object* D_800F7FD0_name_57;
extern Object* D_800F7FD4_name_57;

void func_800F65E0_name_57(void) {
    D_800F7FC0_name_57 = GwSystem.curPlayerIndex;
    omInitObjMan(50, 50);
    func_800F7DF4_name_57();
    func_800F7A78_name_57();
    func_800544E4();
    func_800546B4(0, GwPlayer[0].turn_status);
    func_800546B4(1, GwPlayer[1].turn_status);
    func_800546B4(2, GwPlayer[2].turn_status);
    func_800546B4(3, GwPlayer[3].turn_status);
    func_8006CEA0();
    omAddPrcObj(func_800F7768_name_57, 0x300, 0, 0);
    omAddObj(0x1000, 0, 0, -1, &func_800F7A08_name_57);
    if (GwCommon.boardWork[0] != 0) {
        func_80060128(0x12);
    }
    if (D_800C597A != 0) {
        SetFadeInTypeAndTime(6, 8);
    } else if (GwCommon.boardWork[0] != 0) {
        SetFadeInTypeAndTime(3, 16);
    } else {
        SetFadeInTypeAndTime(2, 16);
    }
}

s32 func_800F66F8_name_57(s16 win) {
    s32 cpu = 0;
    s16 colors[4];
    PortMasks_57 masks = D_800F7F90_name_57;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (i == D_800F7FC0_name_57) {
            if (GwPlayer[i].flags & 1) {
                cpu = 1;
                colors[GwPlayer[i].port] = -0x8000;
            } else {
                func_8007155C(win, masks.bit[GwPlayer[i].port]);
                colors[GwPlayer[i].port] = -1;
            }
        } else {
            colors[GwPlayer[i].port] = 0;
        }
    }
    if (cpu != 0) {
        func_8006DA1C(win, 2, 2);
        func_80070FF8(colors[0], colors[1], colors[2], colors[3], func_8004DBBC());
    } else {
        func_800710A4(colors[0], colors[1], colors[2], colors[3]);
    }
    return func_8006FCF0(win, 0, 1);
}

void func_800F68B8_name_57(void) {
    s32 i = 0;

    func_800500A4();
    PlaySound(0x44);
    PlaySound(0x6D);
    D_800F7EC0_name_57 = MBModelCreate(0x40, NULL);
    D_800F7EC0_name_57->coords.x = D_800F7FC8_name_57->coords.x;
    D_800F7EC0_name_57->coords.y = D_800F7FC8_name_57->coords.y + 200.0f;
    D_800F7EC0_name_57->coords.z = D_800F7FC8_name_57->coords.z;
    D_800F7EC0_name_57->xScale = 0.5f;
    D_800F7EC0_name_57->yScale = 0.5f;
    D_800F7EC0_name_57->zScale = 0.5f;
    D_800F7ECC_name_57 = func_80042728(D_800F7EC0_name_57, 0);
    do {
        D_800F7EC0_name_57->coords.x =
            (D_800F7EE8_name_57.x - D_800F7FC8_name_57->coords.x) * i / 180.0f + D_800F7FC8_name_57->coords.x;
        D_800F7EC0_name_57->coords.y =
            D_800F7FC8_name_57->coords.y + 200.0f + sinf(i * 0.017453292519943295) * 100.0f;
        D_800F7EC0_name_57->coords.z =
            (D_800F7EE8_name_57.z - D_800F7FC8_name_57->coords.z) * i / 180.0f + D_800F7FC8_name_57->coords.z;
        D_800F7EC0_name_57->unk_18.x = sinf(i * 10 * 0.017453292519943295);
        D_800F7EC0_name_57->unk_18.z = cosf(i * 10 * 0.017453292519943295);
        HuPrcVSleep();
        i += 5;
    } while (i < 181);
    PlaySound(0x474);
    func_80055994(D_800F7FC0_name_57, 1);
    func_800503B0(D_800F7FC0_name_57, 4);
    MBModelKill(D_800F7EC0_name_57);
    D_800F7EC0_name_57 = NULL;
    func_800427D4(D_800F7ECC_name_57);
    D_800F7ECC_name_57 = NULL;
    func_80021CDC(*D_800F7FD0_name_57->unk_3C->unk_40, GwPlayer[D_800F7FC0_name_57].character, 0x81);
    func_8004CCD0(&D_800F7FD0_name_57->coords, &D_800F32A0->coords, &D_800F7FD0_name_57->unk_18);
    MBMotionSet(D_800F7FD0_name_57, 0, 0);
    GwPlayer[D_800F7FC0_name_57].stars++;
    HuPrcSleep(36);
    func_80060468(0x443, GwPlayer[D_800F7FC0_name_57].character);
    HuPrcSleep(48);
    func_80050160();
}

void func_800F6BD0_name_57(void) {
    s16 win;

    if (GwPlayer[D_800F7FC0_name_57].stars >= 99) {
        PlaySound(0x467);
        win = CreateTextWindow(120, 60, 13, 5);
        LoadStringIntoWindow(win, (void*)0x11D, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        func_8004DBD4(win, D_800F7FC0_name_57);
        HideTextWindow(win);
    } else if (GwPlayer[D_800F7FC0_name_57].coins < 20) {
        PlaySound(0x467);
        win = CreateTextWindow(120, 60, 11, 5);
        LoadStringIntoWindow(win, (void*)0x118, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        func_8004DBD4(win, D_800F7FC0_name_57);
        HideTextWindow(win);
    } else {
        if (D_800C597A == 0) {
            PlaySound(0x465);
            MBMotionSet(D_800F7FC8_name_57, 0, 0);
            func_8004F00C(D_800F7FC8_name_57, 40.0f, -5.0f);
            func_8004F044(D_800F7FC8_name_57);
            MBMotionSet(D_800F7FC8_name_57, 1, 2);
        }
        func_800F6D48_name_57();
    }
}

// decomp-permuter
void func_800F6D48_name_57(void)
{
  s16 win;
  s32 choice;
  s32 total;
  s32 i;
  win = CreateTextWindow(120, 60, 13, 7);
  LoadStringIntoWindow(win, (void *) 0x119, -1, -1);
  func_8006E070(win, 0);
  ShowTextWindow(win);
  while (func_8006FCC0(win) != 0)
  {
    HuPrcVSleep();
  }

  choice = func_800F66F8_name_57(win);
  HideTextWindow(win);
  if (choice == 2)
  {
    D_800F7EC8_name_57 = 1;
  }
  else
    if (choice == 0)
  {
    func_80055960(D_800F7FC0_name_57, -20);
    func_8004D8A4();
    win = CreateTextWindow(120, 100, 13, 1);
    LoadStringIntoWindow(win, (void *) 0x11B, -1, -1);
    func_8006E070(win, 0);
    ShowTextWindow(win);
    func_8004DBD4(win, D_800F7FC0_name_57);
    HideTextWindow(win);
    func_800F68B8_name_57();
    func_80055994(D_800F7FC0_name_57, 1);
    choice = CreateTextWindow(120, 60, 13, 5);
    for (i = 0, total = 0; i <= (4 - 1); i++)
    {
      total += GwPlayer[i].stars;
    }

    ;
    if ((((total - 1) % 6) + D_800F7EF4_name_57) != 0)
    {
      LoadStringIntoWindow(choice, (void *) ((s32) (((total - 1) % 6) + D_800F7EF4_name_57)), -1, -1);
    }
    win = choice;
    func_8006E070(win, 0);
    ShowTextWindow(win);
    func_8004DBD4(win, D_800F7FC0_name_57);
    HideTextWindow(win);
  }
  else
  {
    win = CreateTextWindow(120, 100, 10, 1);
    LoadStringIntoWindow(win, (void *) 0x11A, -1, -1);
    func_8006E070(win, 0);
    ShowTextWindow(win);
    func_8004DBD4(win, D_800F7FC0_name_57);
    HideTextWindow(win);
  }
}

void func_800F6FA4_name_57(void) {
    s32 i = 72;

    func_800500A4();
    PlaySound(0x44);
    D_800F7EC4_name_57 = MBModelCreate(0x15, NULL);
    D_800F7EC4_name_57->coords.x = D_800F7FC4_name_57->coords.x;
    D_800F7EC4_name_57->coords.y = D_800F7FC4_name_57->coords.y + 200.0f;
    D_800F7EC4_name_57->coords.z = D_800F7FC4_name_57->coords.z;
    D_800F7EC4_name_57->unk_3C->unk_24 = 90.0f;
    D_800F7EC4_name_57->zScale = 0.5f;
    D_800F7EC4_name_57->yScale = 0.5f;
    D_800F7EC4_name_57->xScale = 0.5f;
    D_800F7ECC_name_57 = func_80042728(D_800F7EC4_name_57, 0);
    do {
        D_800F7EC4_name_57->coords.x =
            (D_800F7EE8_name_57.x - D_800F7FC4_name_57->coords.x) * i / 180.0f + D_800F7FC4_name_57->coords.x;
        D_800F7EC4_name_57->coords.y =
            D_800F7FC4_name_57->coords.y + 200.0f + sinf(i * 0.017453292519943295) * 100.0f;
        D_800F7EC4_name_57->coords.z =
            (D_800F7EE8_name_57.z - D_800F7FC4_name_57->coords.z) * i / 180.0f + D_800F7FC4_name_57->coords.z;
        D_800F7EC4_name_57->unk_18.x = sinf(i * 10 * 0.017453292519943295);
        D_800F7EC4_name_57->unk_18.z = cosf(i * 10 * 0.017453292519943295);
        HuPrcVSleep();
        i += 3;
    } while (i < 181);
    PlaySound(0x476);
    D_800F7EC4_name_57->unk_18.x = 0.0f;
    D_800F7EC4_name_57->unk_18.z = 1.0f;
    func_800427D4(D_800F7ECC_name_57);
    D_800F7ECC_name_57 = NULL;
    func_8004F4D4(D_800F7FD0_name_57, 2, 0);
    HuPrcSleep(70);
    func_80050160();
}

void func_800F71F8_name_57(void) {
    s16 win;
    s32 coins;

    if (GwPlayer[D_800F7FC0_name_57].coins == 0) {
        win = CreateTextWindow(60, 60, 19, 3);
        LoadStringIntoWindow(win, (void*)0x1E5, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        func_8004DBD4(win, D_800F7FC0_name_57);
        HideTextWindow(win);
        return;
    }
    if (GwPlayer[D_800F7FC0_name_57].coins < 40) {
        win = CreateTextWindow(60, 60, 19, 2);
        LoadStringIntoWindow(win, (void*)0x1E3, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        func_8004DBD4(win, D_800F7FC0_name_57);
        HideTextWindow(win);
        win = CreateTextWindow(60, 60, 17, 2);
        LoadStringIntoWindow(win, (void*)0x1E4, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        PlaySound(0x469);
        func_8004DBD4(win, D_800F7FC0_name_57);
        HideTextWindow(win);
        coins = -GwPlayer[D_800F7FC0_name_57].coins;
    } else {
        win = CreateTextWindow(60, 60, 19, 3);
        LoadStringIntoWindow(win, (void*)0x1E1, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        func_8004DBD4(win, D_800F7FC0_name_57);
        HideTextWindow(win);
        func_800F6FA4_name_57();
        win = CreateTextWindow(30, 60, 18, 2);
        LoadStringIntoWindow(win, (void*)0x1E2, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        PlaySound(0x469);
        func_8004DBD4(win, D_800F7FC0_name_57);
        HideTextWindow(win);
        coins = -40;
    }
    MBMotionSet(D_800F7FC4_name_57, 0, 0);
    func_8004F4D4(D_800F7FD0_name_57, 1, 0);
    func_80055960(D_800F7FC0_name_57, coins);
    func_800503B0(D_800F7FC0_name_57, 5);
    func_80060618(0x44A, D_800F7FC0_name_57);
    HuPrcSleep(45);
    MBMotionSet(D_800F7FC4_name_57, 1, 2);
}

/* Bowser and the star giver swap places: one turns around the pivot D_800F7EDC opposite the other. */
// register allocation / scheduling: retail keeps the angle and radians in f20, 200.0f in f22, and loads &D_800F7EDC before the constant (masked 8); tried angle reused for radians, d *= then rad = d
#ifdef NON_MATCHING
void func_800F74E8_name_57(f32 angle) {
    f32 rad;
    f64 d = angle;
    Object* o;

    if (GwCommon.boardWork[0] != 0) {
        o = D_800F7FC4_name_57;
        rad = d * 0.017453292519943295;
        o->coords.x = sinf(rad) * 200.0f + D_800F7EDC_name_57.x;
        D_800F7FC4_name_57->coords.z = cosf(rad) * 200.0f + D_800F7EDC_name_57.z;
        D_800F7FC4_name_57->unk_18.x = sinf(rad);
        D_800F7FC4_name_57->unk_18.z = cosf(rad);
        D_800F7FCC_name_57->unk_18.x = sinf(rad);
        D_800F7FCC_name_57->unk_18.z = cosf(rad);
        D_800F7FC8_name_57->coords.x = D_800F7EDC_name_57.x - sinf(rad) * 200.0f;
        D_800F7FC8_name_57->coords.z = D_800F7EDC_name_57.z - cosf(rad) * 200.0f;
        D_800F7FC8_name_57->unk_18.x = -sinf(rad);
        o = D_800F7FC8_name_57;
    } else {
        o = D_800F7FC8_name_57;
        rad = d * 0.017453292519943295;
        o->coords.x = sinf(rad) * 200.0f + D_800F7EDC_name_57.x;
        D_800F7FC8_name_57->coords.z = cosf(rad) * 200.0f + D_800F7EDC_name_57.z;
        D_800F7FC8_name_57->unk_18.x = sinf(rad);
        D_800F7FC8_name_57->unk_18.z = cosf(rad);
        D_800F7FCC_name_57->unk_18.x = sinf(rad);
        D_800F7FCC_name_57->unk_18.z = cosf(rad);
        D_800F7FC4_name_57->coords.x = D_800F7EDC_name_57.x - sinf(rad) * 200.0f;
        D_800F7FC4_name_57->coords.z = D_800F7EDC_name_57.z - cosf(rad) * 200.0f;
        D_800F7FC4_name_57->unk_18.x = -sinf(rad);
        o = D_800F7FC4_name_57;
    }
    o->unk_18.z = -cosf(rad);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_57_BowserVisitMarioBoard/293A70", func_800F74E8_name_57);
#endif

void func_800F7768_name_57(void) {
    f32 scale;
    f32 angle;
    s32 wait;

    wait = 8;
    if (D_800C597A == 0) {
        if (GwCommon.boardWork[0] == 0) {
            func_800421E0();
            wait = 26;
        } else {
            HuPrcSleep(16);
            PlaySound(0x46A);
            wait = 10;
        }
    }
    HuPrcSleep(wait);
    if (GwCommon.boardWork[0] == 0) {
        func_800F6BD0_name_57();
        if (D_800F7EC0_name_57 != NULL) {
            MBModelKill(D_800F7EC0_name_57);
        }
        D_800F7EC0_name_57 = NULL;
    } else {
        func_800F71F8_name_57();
        if (D_800F7EC4_name_57 != NULL) {
            scale = 0.5f;
            do {
                D_800F7EC4_name_57->xScale = D_800F7EC4_name_57->yScale = D_800F7EC4_name_57->zScale = scale;
                D_800F7EC4_name_57->coords.y -= 20.0f;
                HuPrcVSleep();
                scale -= 0.1f;
            } while (scale > 0.0f);
            MBModelKill(D_800F7EC4_name_57);
            D_800F7EC4_name_57 = NULL;
            func_800503B0(D_800F7FC0_name_57, 5);
        }
    }
    HuPrcSleep(5);
    if (D_800F7EC8_name_57 == 0) {
        MBModelDispOn(D_800F7FC4_name_57);
        MBModelDispOn(D_800F7FC8_name_57);
        if (GwCommon.boardWork[0] != 0) {
            func_800601D4(40);
        }
        PlaySound(0xE2);
        angle = 45.0f;
        do {
            func_800F74E8_name_57(angle);
            HuPrcVSleep();
            angle -= 5.0f;
        } while (angle >= -135.0f);
        PlaySound(0xE4);
        GwCommon.boardWork[0] = (GwCommon.boardWork[0] + 1) & 1;
        HuPrcSleep(10);
    }
    D_800F5144 = 1;
    while (TRUE) {
        HuPrcVSleep();
    }
}

void func_800F798C_name_57(omObjData* obj) {
    if (func_80072718() == 0) {
        func_800F7E94_name_57();
        func_800F7D5C_name_57();
        func_80054654();
        func_80070ED4();
        if (D_800F7EC8_name_57 == 0) {
            omOvlReturnEx(1);
            return;
        }
        func_8004F284();
        func_8004F28C(0x57, (s16)D_800F7EC8_name_57);
    }
}

void func_800F7A08_name_57(omObjData* obj) {
    if (D_800F5144 != 0) {
        if (D_800F7EC8_name_57 != 0) {
            func_800726AC(6, 8);
        } else if (GwCommon.boardWork[0] != 0) {
            func_800726AC(3, 16);
        } else {
            func_800726AC(2, 16);
        }
        obj->func_ptr = &func_800F798C_name_57;
    }
}

void func_800F7A78_name_57(void) {
    Object* m1;
    Object* m2;
    Object* m3;
    Object* m4;
    Object* m;

    MBModelInit();
    m1 = MBModelCreate(0x14, NULL);
    D_800F7FCC_name_57 = m1;
    m1->coords.x = D_800F7ED0_name_57.x;
    m1->coords.y = D_800F7ED0_name_57.y;
    m1->coords.z = D_800F7ED0_name_57.z;
    m1->xScale = m1->yScale = m1->zScale = 1.5f;
    func_80025F60(*m1->unk_3C->unk_40, 0);
    m2 = MBModelCreate(func_80052F04(D_800F7FC0_name_57),
                                           D_800F7F70_name_57[GwPlayer[D_800F7FC0_name_57].character]);
    D_800F7FD0_name_57 = m2;
    func_80021B14(*m2->unk_3C->unk_40, GwPlayer[D_800F7FC0_name_57].character, 0x80);
    D_800F7FD0_name_57->coords.x = D_800F7EE8_name_57.x;
    D_800F7FD0_name_57->coords.y = D_800F7EE8_name_57.y;
    D_800F7FD0_name_57->coords.z = D_800F7EE8_name_57.z;
    m3 = MBModelCreate(0x12, NULL);
    D_800F7FD4_name_57 = m3;
    m3->coords.x = D_800F7EE8_name_57.x;
    m3->coords.y = D_800F7EE8_name_57.y;
    m3->coords.z = D_800F7EE8_name_57.z;
    m4 = MBModelCreate(0x6C, D_800F7EF8_name_57);
    D_800F7FC4_name_57 = m4;
    m4->coords.x = D_800F7EDC_name_57.x;
    m4->coords.y = D_800F7EDC_name_57.y;
    m4->coords.z = D_800F7EDC_name_57.z + 200.0f;
    m4->xScale = m4->yScale = m4->zScale = 1.5f;
    func_80025F60(*m4->unk_3C->unk_40, 0);
    m = MBModelCreate(7, D_800F7F04_name_57);
    D_800F7FC8_name_57 = m;
    m->coords.x = D_800F7EDC_name_57.x;
    m->coords.y = D_800F7EDC_name_57.y;
    m->coords.z = D_800F7EDC_name_57.z + 200.0f;
    if (GwCommon.boardWork[0] == 0) {
        m = D_800F7FC4_name_57;
    }
    MBModelDispOff(m);
    func_800258EC(*D_800F7FC4_name_57->unk_40->unk_40, 0x180, 0x80);
    func_800258EC(*D_800F7FC8_name_57->unk_40->unk_40, 0x180, 0x80);
    func_80025AD4(*D_800F7FC4_name_57->unk_40->unk_40);
    func_80025AD4(*D_800F7FC8_name_57->unk_40->unk_40);
    func_800F74E8_name_57(45.0f);
    func_8004CCD0(&D_800F7FD0_name_57->coords, &D_800F7FC4_name_57->coords, &D_800F7FD0_name_57->unk_18);
    func_8004CCD0(&D_800F7FD4_name_57->coords, &D_800F7FC4_name_57->coords, &D_800F7FD4_name_57->unk_18);
}

void func_800F7D5C_name_57(void) {
    MBModelKill(D_800F7FC4_name_57);
    MBModelKill(D_800F7FC8_name_57);
    MBModelKill(D_800F7FCC_name_57);
    MBModelKill(D_800F7FD0_name_57);
    MBModelKill(D_800F7FD4_name_57);
    if (D_800F7EC0_name_57 != NULL) {
        MBModelKill(D_800F7EC0_name_57);
    }
    if (D_800F7EC4_name_57 != NULL) {
        MBModelKill(D_800F7EC4_name_57);
    }
    if (D_800F7ECC_name_57 != NULL) {
        func_800427D4(D_800F7ECC_name_57);
    }
}

void func_800F7DF4_name_57(void) {
    func_800178A0(1);
    func_80017660(0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    LoadBackgroundData(FE2310_ROM_START);
    LoadBackgroundIndex(0x32);
}

void func_800F7E94_name_57(void) {
    func_8004A140();
    func_80049F0C();
}
