#include "common.h"

void func_800F6C44_UnknownStarPurchaseScene0(void);
void func_800F68A0_UnknownStarPurchaseScene0(void);
void func_800F7058_UnknownStarPurchaseScene0(omObjData* obj);
void func_800F70EC_UnknownStarPurchaseScene0(omObjData* obj);
void func_800F7164_UnknownStarPurchaseScene0(void);
void func_800F7330_UnknownStarPurchaseScene0(void);
void func_800F7374_UnknownStarPurchaseScene0(void);
void func_800F74D0_UnknownStarPurchaseScene0(void);
void func_8004DBD4(s32, u8);
void func_80055994(u8, s32);
s32 func_8004D8A4(void);

/* the result as a word; retail also reads its low half (big-endian +2) as s16 */
s32 D_800F7500_UnknownStarPurchaseScene0 = 0;
void* D_800F7504_UnknownStarPurchaseScene0 = NULL;
s32 D_800F7508_UnknownStarPurchaseScene0 = 0;
s32 D_800F750C_UnknownStarPurchaseScene0[] = { 2, 0xB, 0x14, 0x1D, 0x29, 0x31, 0x3A, 0x47 };
/* per board: the host's position and the player's position */
Vec3f D_800F752C_UnknownStarPurchaseScene0[] = {
    { -80.0f, 0.0f, 1310.0f }, { -80.0f, 0.0f, 1310.0f }, { -80.0f, 0.0f, 1310.0f }, { -80.0f, 0.0f, 1310.0f },
    { -80.0f, 0.0f, 1310.0f }, { -80.0f, 0.0f, 1310.0f }, { -80.0f, 0.0f, 1310.0f }, { -80.0f, 0.0f, 1310.0f },
};
Vec3f D_800F758C_UnknownStarPurchaseScene0[] = {
    { 80.0f, 0.0f, 1520.0f }, { 80.0f, 0.0f, 1520.0f }, { 80.0f, 0.0f, 1520.0f }, { 80.0f, 0.0f, 1520.0f },
    { 80.0f, 0.0f, 1520.0f }, { 80.0f, 0.0f, 1520.0f }, { 80.0f, 0.0f, 1520.0f }, { 80.0f, 0.0f, 1520.0f },
};
/* per board: first of six message ids */
s32 D_800F75EC_UnknownStarPurchaseScene0[] = { 0x11E, 0x125, 0x12C, 0x133, 0x13A, 0x141, 0x148, 0x14F };
s32 D_800F760C_UnknownStarPurchaseScene0[] = { 1, 0x0001000F };
s32 D_800F7614_UnknownStarPurchaseScene0[] = { 1, 0x0002000F };
s32 D_800F761C_UnknownStarPurchaseScene0[] = { 1, 0x0006000F };
s32 D_800F7624_UnknownStarPurchaseScene0[] = { 1, 0x0003000F };
s32 D_800F762C_UnknownStarPurchaseScene0[] = { 1, 0x0004000F };
s32 D_800F7634_UnknownStarPurchaseScene0[] = { 1, 0x0005000F };
void* D_800F763C_UnknownStarPurchaseScene0[] = {
    D_800F760C_UnknownStarPurchaseScene0, D_800F7614_UnknownStarPurchaseScene0, D_800F761C_UnknownStarPurchaseScene0,
    D_800F7624_UnknownStarPurchaseScene0, D_800F762C_UnknownStarPurchaseScene0, D_800F7634_UnknownStarPurchaseScene0,
};
s32 D_800F7654_UnknownStarPurchaseScene0[] = { 2, 0x00070003, 0x00070000 };

extern u8 D_800F76A0_UnknownStarPurchaseScene0;
extern u8 D_800F76A1_UnknownStarPurchaseScene0;
extern Object* D_800F76A4_UnknownStarPurchaseScene0;
extern Object* D_800F76A8_UnknownStarPurchaseScene0;
extern Object* D_800F76AC_UnknownStarPurchaseScene0;

void func_800F65E0_UnknownStarPurchaseScene0(void) {
    D_800F76A0_UnknownStarPurchaseScene0 = GwSystem.curBoardIndex;
    D_800F76A1_UnknownStarPurchaseScene0 = GwSystem.curPlayerIndex;
    omInitObjMan(50, 50);
    func_800F7374_UnknownStarPurchaseScene0();
    func_800F7164_UnknownStarPurchaseScene0();
    func_800544E4();
    func_800546B4(0, GwPlayer[0].turn_status);
    func_800546B4(1, GwPlayer[1].turn_status);
    func_800546B4(2, GwPlayer[2].turn_status);
    func_800546B4(3, GwPlayer[3].turn_status);
    func_8006CEA0();
    omAddPrcObj(func_800F6C44_UnknownStarPurchaseScene0, 0x300, 0, 0);
    omAddObj(0x1000, 0, 0, -1, &func_800F70EC_UnknownStarPurchaseScene0);
    if (D_800C597A != 0) {
        SetFadeInTypeAndTime(6, 8);
    } else {
        SetFadeInTypeAndTime(2, 16);
    }
}

s32 func_800F66E0_UnknownStarPurchaseScene0(s32 win) {
    s16 sp18[4];
    s32 found = 0;
    u8 sp20[] = { 1, 2, 4, 8 };
    s32 i;

    for (i = 0; i < 4; i++) {
        if (i == D_800F76A1_UnknownStarPurchaseScene0) {
            if (GwPlayer[i].flags & 1) {
                found = 1;
                sp18[GwPlayer[i].port] = -0x8000;
            } else {
                func_8007155C(win, sp20[GwPlayer[i].port]);
                sp18[GwPlayer[i].port] = -1;
            }
        } else {
            sp18[GwPlayer[i].port] = 0;
        }
    }
    if (found) {
        func_8006DA1C(win, 2, 2);
        func_80070FF8(sp18[0], sp18[1], sp18[2], sp18[3], func_8004DBBC());
    } else {
        func_800710A4(sp18[0], sp18[1], sp18[2], sp18[3]);
    }
    return func_8006FCF0(win, 0, 1);
}

void func_800F68A0_UnknownStarPurchaseScene0(void) {
    s32 i;
    f32 y;
    f32 rad;

    i = 0;
    func_800500A4();
    PlaySound(0x44);
    PlaySound(0x6D);
    D_800F76AC_UnknownStarPurchaseScene0 = MBModelCreate(0x40, NULL);
    func_800A0D00(&D_800F76AC_UnknownStarPurchaseScene0->coords,
                  D_800F752C_UnknownStarPurchaseScene0[D_800F76A0_UnknownStarPurchaseScene0].x,
                  D_800F752C_UnknownStarPurchaseScene0[D_800F76A0_UnknownStarPurchaseScene0].y + 200.0f,
                  D_800F752C_UnknownStarPurchaseScene0[D_800F76A0_UnknownStarPurchaseScene0].z);
    func_800A0D00((Vec3f*)&D_800F76AC_UnknownStarPurchaseScene0->xScale, 0.5f, 0.5f, 0.5f);
    D_800F7504_UnknownStarPurchaseScene0 = func_80042728(D_800F76AC_UnknownStarPurchaseScene0, 0);
    do {
        y = D_800F752C_UnknownStarPurchaseScene0[D_800F76A0_UnknownStarPurchaseScene0].y + 200.0f;
        func_800A0D00(&D_800F76AC_UnknownStarPurchaseScene0->coords,
                      (D_800F758C_UnknownStarPurchaseScene0[D_800F76A0_UnknownStarPurchaseScene0].x - D_800F752C_UnknownStarPurchaseScene0[D_800F76A0_UnknownStarPurchaseScene0].x) * i / 180.0f + D_800F752C_UnknownStarPurchaseScene0[D_800F76A0_UnknownStarPurchaseScene0].x,
                      y + sinf(i * 0.017453292519943295) * 100.0f,
                      D_800F752C_UnknownStarPurchaseScene0[D_800F76A0_UnknownStarPurchaseScene0].z + (D_800F758C_UnknownStarPurchaseScene0[D_800F76A0_UnknownStarPurchaseScene0].z - D_800F752C_UnknownStarPurchaseScene0[D_800F76A0_UnknownStarPurchaseScene0].z) * i / 180.0);
        D_800F76AC_UnknownStarPurchaseScene0->unk_18.x = sinf(rad = i * 10 * 0.017453292519943295);
        D_800F76AC_UnknownStarPurchaseScene0->unk_18.z = cosf(rad);
        HuPrcVSleep();
        i += 5;
    } while (i < 181);
    PlaySound(0x474);
    func_80055994(D_800F76A1_UnknownStarPurchaseScene0, 1);
    func_800503B0(D_800F76A1_UnknownStarPurchaseScene0, 4);
    MBModelKill(D_800F76AC_UnknownStarPurchaseScene0);
    D_800F76AC_UnknownStarPurchaseScene0 = NULL;
    func_800427D4(D_800F7504_UnknownStarPurchaseScene0);
    D_800F7504_UnknownStarPurchaseScene0 = NULL;
    func_80021CDC(*D_800F76A8_UnknownStarPurchaseScene0->unk_3C->unk_40, GwPlayer[D_800F76A1_UnknownStarPurchaseScene0].character, 0x81);
    func_8004CCD0(&D_800F76A8_UnknownStarPurchaseScene0->coords, &D_800F32A0->coords, &D_800F76A8_UnknownStarPurchaseScene0->unk_18);
    MBMotionSet(D_800F76A8_UnknownStarPurchaseScene0, 0, 0);
    GwPlayer[D_800F76A1_UnknownStarPurchaseScene0].stars++;
    HuPrcSleep(36);
    func_80060468(0x443, GwPlayer[D_800F76A1_UnknownStarPurchaseScene0].character);
    HuPrcSleep(48);
    func_80050160();
    if (D_800F76A0_UnknownStarPurchaseScene0 != 1 && D_800F76A0_UnknownStarPurchaseScene0 != 2) {
        D_800F7508_UnknownStarPurchaseScene0 = 1;
    }
}

// register allocation: retail keeps the result window in s0 and the raw ids in s1, swapped here (masked 9)
#ifdef NON_MATCHING
void func_800F6C44_UnknownStarPurchaseScene0(void) {
    s32 choice;
    s32 win2;
    s16 menu;
    s32 win;
    s32 total;
    s32 i;
    s32 msg;

    if (D_800C597A != 0) {
        HuPrcSleep(8);
    } else {
        func_800421E0();
        HuPrcSleep(16);
        if (GwPlayer[D_800F76A1_UnknownStarPurchaseScene0].stars >= 99) {
            PlaySound(0x467);
        } else if (GwPlayer[D_800F76A1_UnknownStarPurchaseScene0].coins < 20) {
            PlaySound(0x467);
        } else {
            PlaySound(0x465);
        }
    }
    if (GwPlayer[D_800F76A1_UnknownStarPurchaseScene0].stars >= 99) {
        win = (s16)CreateTextWindow(120, 60, 13, 5);
        LoadStringIntoWindow(win, (void*)0x11D, -1, -1);
    } else if (GwPlayer[D_800F76A1_UnknownStarPurchaseScene0].coins < 20) {
        win = (s16)CreateTextWindow(120, 60, 11, 5);
        LoadStringIntoWindow(win, (void*)0x118, -1, -1);
    } else {
        if (D_800C597A == 0) {
            MBMotionSet(D_800F76A4_UnknownStarPurchaseScene0, 0, 0);
            func_8004F00C(D_800F76A4_UnknownStarPurchaseScene0, 40.0f, -5.0f);
            func_8004F044(D_800F76A4_UnknownStarPurchaseScene0);
            MBMotionSet(D_800F76A4_UnknownStarPurchaseScene0, 1, 2);
        }
        menu = CreateTextWindow(120, 60, 12, 7);
        LoadStringIntoWindow(menu, (void*)0x119, -1, -1);
        func_8006E070(menu, 0);
        ShowTextWindow(menu);
        while (func_8006FCC0(menu) != 0) {
            HuPrcVSleep();
        }
        choice = func_800F66E0_UnknownStarPurchaseScene0(menu);
        HideTextWindow(menu);
        if (choice == 2) {
            D_800F7500_UnknownStarPurchaseScene0 = 1;
            goto end;
        } else if (choice == 0) {
            func_80055960(D_800F76A1_UnknownStarPurchaseScene0, -20);
            func_8004D8A4();
            win = (s16)CreateTextWindow(120, 100, 13, 1);
            LoadStringIntoWindow(win, (void*)0x11B, -1, -1);
            func_8006E070(win, 0);
            ShowTextWindow(win);
            func_8004DBD4(win, D_800F76A1_UnknownStarPurchaseScene0);
            HideTextWindow(win);
            func_800F68A0_UnknownStarPurchaseScene0();
            func_80055994(D_800F76A1_UnknownStarPurchaseScene0, 1);
            win2 = CreateTextWindow(120, 60, 13, 5);
            total = 0;
            for (i = 0; i < 4; i++) {
                total += GwPlayer[i].stars;
            }
            msg = D_800F75EC_UnknownStarPurchaseScene0[D_800F76A0_UnknownStarPurchaseScene0] + (total - 1) % 6;
            if (msg != 0) {
                LoadStringIntoWindow(win2, (msg), -1, -1);
            }
            win = (s16)win2;
        } else {
            win = (s16)CreateTextWindow(120, 100, 9, 1);
            LoadStringIntoWindow(win, (void*)0x11A, -1, -1);
        }
    }
    func_8006E070(win, 0);
    ShowTextWindow(win);
    func_8004DBD4(win, D_800F76A1_UnknownStarPurchaseScene0);
    HideTextWindow(win);
end:
    D_800F5144 = 1;
    while (TRUE) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_44_UnknownStarPurchaseScene0/280C80", func_800F6C44_UnknownStarPurchaseScene0);
#endif

void func_800F7058_UnknownStarPurchaseScene0(omObjData* obj) {
    if (func_80072718() == 0) {
        func_800F74D0_UnknownStarPurchaseScene0();
        func_800F7330_UnknownStarPurchaseScene0();
        func_80054654();
        func_80070ED4();
        if (D_800F76AC_UnknownStarPurchaseScene0 != NULL) {
            MBModelKill(D_800F76AC_UnknownStarPurchaseScene0);
        }
        if (D_800F7500_UnknownStarPurchaseScene0 == 0) {
            omOvlReturnEx(1);
            return;
        }
        func_8004F284();
        func_8004F28C(0x44, (s16)D_800F7500_UnknownStarPurchaseScene0);
    }
}

void func_800F70EC_UnknownStarPurchaseScene0(omObjData* obj) {
    if (D_800F5144 != 0) {
        if (D_800F7500_UnknownStarPurchaseScene0 != 0) {
            func_800726AC(6, 8);
        } else {
            if (D_800F7508_UnknownStarPurchaseScene0 != 0) {
                func_800601D4(32);
            }
            func_800726AC(2, 16);
        }
        obj->func_ptr = &func_800F7058_UnknownStarPurchaseScene0;
    }
}

void func_800F7164_UnknownStarPurchaseScene0(void) {
    Vec3f mid;

    MBModelInit();
    D_800F76A4_UnknownStarPurchaseScene0 = MBModelCreate(7, D_800F7654_UnknownStarPurchaseScene0);
    D_800F76A4_UnknownStarPurchaseScene0->coords.x = D_800F752C_UnknownStarPurchaseScene0[D_800F76A0_UnknownStarPurchaseScene0].x;
    D_800F76A4_UnknownStarPurchaseScene0->coords.y = D_800F752C_UnknownStarPurchaseScene0[D_800F76A0_UnknownStarPurchaseScene0].y;
    D_800F76A4_UnknownStarPurchaseScene0->coords.z = D_800F752C_UnknownStarPurchaseScene0[D_800F76A0_UnknownStarPurchaseScene0].z;
    D_800F76A8_UnknownStarPurchaseScene0 = MBModelCreate(func_80052F04(D_800F76A1_UnknownStarPurchaseScene0), D_800F763C_UnknownStarPurchaseScene0[GwPlayer[D_800F76A1_UnknownStarPurchaseScene0].character]);
    D_800F76A8_UnknownStarPurchaseScene0->coords.x = D_800F758C_UnknownStarPurchaseScene0[D_800F76A0_UnknownStarPurchaseScene0].x;
    D_800F76A8_UnknownStarPurchaseScene0->coords.y = D_800F758C_UnknownStarPurchaseScene0[D_800F76A0_UnknownStarPurchaseScene0].y;
    D_800F76A8_UnknownStarPurchaseScene0->coords.z = D_800F758C_UnknownStarPurchaseScene0[D_800F76A0_UnknownStarPurchaseScene0].z;
    func_80021B14(*D_800F76A8_UnknownStarPurchaseScene0->unk_3C->unk_40, GwPlayer[D_800F76A1_UnknownStarPurchaseScene0].character, 0x80);
    mid.x = (D_800F32A0->coords.x + D_800F76A8_UnknownStarPurchaseScene0->coords.x) / 2.0f;
    mid.y = (D_800F32A0->coords.y + D_800F76A8_UnknownStarPurchaseScene0->coords.y) / 2.0f;
    mid.z = (D_800F32A0->coords.z + D_800F76A8_UnknownStarPurchaseScene0->coords.z) / 2.0f;
    func_8004CCD0(&D_800F76A4_UnknownStarPurchaseScene0->coords, &mid, &D_800F76A4_UnknownStarPurchaseScene0->unk_18);
    func_8004CCD0(&D_800F76A8_UnknownStarPurchaseScene0->coords, &D_800F76A4_UnknownStarPurchaseScene0->coords, &D_800F76A8_UnknownStarPurchaseScene0->unk_18);
}

void func_800F7330_UnknownStarPurchaseScene0(void) {
    MBModelKill(D_800F76A4_UnknownStarPurchaseScene0);
    MBModelKill(D_800F76A8_UnknownStarPurchaseScene0);
    if (D_800F7504_UnknownStarPurchaseScene0 != NULL) {
        func_800427D4(D_800F7504_UnknownStarPurchaseScene0);
    }
}

void func_800F7374_UnknownStarPurchaseScene0(void) {
    s32 bg;

    func_800178A0(1);
    func_80017660(0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    LoadBackgroundData(FE2310_ROM_START);
    switch (D_800F76A0_UnknownStarPurchaseScene0) {
    case 2:
        if (GwCommon.boardWork[5] == 0) {
            LoadBackgroundIndex(0x16);
        } else {
            LoadBackgroundIndex(0x17);
        }
        return;
    case 3:
        switch (GwPlayer[D_800F76A1_UnknownStarPurchaseScene0].cur_chain) {
        case 2:
            bg = 0x1D;
            break;
        case 3:
            bg = 0x21;
            break;
        case 8:
            bg = 0x1F;
            break;
        case 1:
            bg = 0x20;
            break;
        case 0:
        default:
            bg = 0x1E;
            break;
        }
        break;
    default:
        bg = D_800F750C_UnknownStarPurchaseScene0[D_800F76A0_UnknownStarPurchaseScene0];
        break;
    }
    LoadBackgroundIndex(bg);
}

void func_800F74D0_UnknownStarPurchaseScene0(void) {
    func_8004A140();
    func_80049F0C();
}
