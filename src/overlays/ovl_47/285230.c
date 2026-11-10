#include "common.h"
#include "285230.h"

extern u8 D_800F6F20_name_47;

s32 D_800F6EE0_name_47 = 0;
Vec3f D_800F6EE4_name_47 = { -80.0f, 0.0f, 1310.0f };
Vec3f D_800F6EF0_name_47 = { -400.0f, 0.0f, 1310.0f };
Vec3f D_800F6EFC_name_47 = { 80.0f, 0.0f, 1520.0f };
s32 D_800F6F08_name_47[] = { 1, 0x68 };

void func_800F65E0_name_47(void) {
    D_800F6F20_name_47 = GwSystem.curPlayerIndex;
    omInitObjMan(50, 10);
    func_800F6E14_name_47();
    func_800F6D1C_name_47();
    func_800544E4();
    func_800546B4(0, GwPlayer[0].turn_status);
    func_800546B4(1, GwPlayer[1].turn_status);
    func_800546B4(2, GwPlayer[2].turn_status);
    func_800546B4(3, GwPlayer[3].turn_status);
    func_8006CEA0();
    omAddPrcObj(&func_800F6924_name_47, 0x300, 0, 0);
    omAddObj(0x1000, 0, 0, -1, &func_800F6CBC_name_47);
    if (D_800C597A != 0) {
        SetFadeInTypeAndTime(6, 8);
    } else {
        SetFadeInTypeAndTime(1, 16);
    }
}

// loop control: retail branches back on bnez with the decrement in the delay slot (masked 4); tried do-while(n-- != 0), break-then-decrement, a goto loop
#ifdef NON_MATCHING
s32 func_800F66D0_name_47(s32 arg0, u8* arg1) {
    s16 sp18[4];
    s32 var_s2 = 0;
    u8 sp20[] = {1, 2, 4, 8};
    s32 i;

    for (i = 0; i < 4; i++) {
        if (i == D_800F6F20_name_47) {
            if (GwPlayer[i].flags & 1) {
                var_s2 = 2;
                if (GwPlayer[i].coins >= 10) {
                    var_s2 = 1;
                }
                sp18[GwPlayer[i].port] = 0x400;
            } else {
                func_8007155C(arg0, sp20[GwPlayer[i].port]);
                sp18[GwPlayer[i].port] = -1;
            }
        } else {
            sp18[GwPlayer[i].port] = 0;
        }
    }
    if (var_s2 != 0) {
        func_8006DA1C(arg0, 2, 2);
        var_s2--;
        while (1) {
            if (var_s2 == 0) {
                sp18[GwPlayer[D_800F6F20_name_47].port] = -0x8000;
            }
            func_80070FF8(sp18[0], sp18[1], sp18[2], sp18[3], func_8004DBBC());
            if (var_s2 != 0) {
                var_s2--;
                continue;
            }
            break;
        }
    } else {
        func_800710A4(sp18[0], sp18[1], sp18[2], sp18[3]);
    }
    if (arg1[0] == 0) {
        func_80071788(arg0, 0);
    }
    i = 0;
    do {
        i = func_8006FCF0_unproto((s16)arg0, (s16)i, 1);
    } while (arg1[i] == 0);
    return i;
}
#else
/* the C's local sp20 template; an explicit section, as GCC loses track of it after INCLUDE_ASM */
const u8 D_800F6F10_name_47[] __attribute__((section(".rodata"))) = { 1, 2, 4, 8 };
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_47/285230", func_800F66D0_name_47);
#endif

void func_800F6924_name_47(void) {
    s32 win;
    s32 win2;
    u8 options[3];
    s32 choice;
    s32 i;
    s32 delay;

    delay = 8;
    if (D_800C597A == 0) {
        func_800421E0();
        HuPrcSleep(16);
        PlaySound(0x8F);
        delay = 10;
    }
    HuPrcSleep(delay);
    win = CreateTextWindow(0x78, 0x28, 0xB, 5);
    if (GwPlayer[D_800F6F20_name_47].coins < 10) {
        func_8006DA5C(win, "\x01", 0); /* D_800F6F14: message insert strings */
        options[0] = 0;
    } else {
        func_8006DA5C(win, "\x08", 0); /* D_800F6F18 */
        options[0] = 1;
    }
    options[2] = 1;
    options[1] = 1;
    LoadStringIntoWindow(win, (void*)0x187, -1, -1);
    func_8006E070(win, 0);
    ShowTextWindow(win);
    while (func_8006FCC0(win) != 0) {
        HuPrcVSleep();
    }
    choice = func_800F66D0_name_47(win, options);
    HideTextWindow(win);
    if (choice == 2) {
        D_800F6EE0_name_47 = 1;
    } else if (choice == 0) {
        func_80055960(D_800F6F20_name_47, -10);
        GwCommon.boardWork[GwCommon.boardWork[15]] = (GwCommon.boardWork[GwCommon.boardWork[15]] + 1) & 1;
        win2 = CreateTextWindow(0x82, 0x3C, 9, 1);
        LoadStringIntoWindow(win2, (void*)0x188, -1, -1);
        func_8006E070(win2, 0);
        ShowTextWindow(win2);
        func_8004DBD4(win2, D_800F6F20_name_47);
        HideTextWindow(win2);
        D_800F5144 = 1;
        MBMotionSet(D_800F6F24_name_47, 0, 2);
        func_8004EE14(0, &D_800F6EF0_name_47, 15, D_800F6F24_name_47);
        i = 0;
        do {
            if ((i + 1) % 10 == 0) {
                PlaySound(0x8A);
            }
            i++;
            HuPrcVSleep();
        } while (i < 15);
    } else {
        win2 = CreateTextWindow(0x8C, 0x3C, 8, 1);
        LoadStringIntoWindow(win2, (void*)0x189, -1, -1);
        func_8006E070(win2, 0);
        ShowTextWindow(win2);
        func_8004DBD4(win2, D_800F6F20_name_47);
        HideTextWindow(win2);
    }
    D_800F5144 = 1;
    while (TRUE) {
        HuPrcVSleep();
    }
}

void func_800F6C40_name_47(omObjData* obj) {
    if (func_80072718() == 0) {
        func_800F6EB4_name_47();
        func_800F6DE8_name_47();
        func_80054654();
        func_80070ED4();
        if (D_800F6EE0_name_47 == 0) {
            omOvlReturnEx(1);
            return;
        }
        func_8004F284();
        func_8004F28C(0x47, D_800F6EE2_name_47);
    }
}

void func_800F6CBC_name_47(omObjData* obj) {
    if (D_800F5144 != 0) {
        if (D_800F6EE0_name_47 != 0) {
            func_800726AC(6, 8);
        } else {
            func_800726AC (1, 16);
        }
        obj->func_ptr = &func_800F6C40_name_47;
    }
}

void func_800F6D1C_name_47(void) {
    MBModelInit();
    D_800F6F24_name_47 = MBModelCreate(10, &D_800F6F08_name_47);
    D_800F6F24_name_47->coords.x = D_800F6EE4_name_47.x;
    D_800F6F24_name_47->coords.y = D_800F6EE4_name_47.y;
    D_800F6F24_name_47->coords.z = D_800F6EE4_name_47.z;
    D_800F6F28_name_47 = MBModelCreate(func_80052F04(D_800F6F20_name_47), NULL);
    D_800F6F28_name_47->coords.x = D_800F6EFC_name_47.x;
    D_800F6F28_name_47->coords.y = D_800F6EFC_name_47.y;
    D_800F6F28_name_47->coords.z = D_800F6EFC_name_47.z;
    func_8004CCD0(&D_800F6F28_name_47->coords, &D_800F6F24_name_47->coords, &D_800F6F28_name_47->unk_18);
    func_8004CCD0(&D_800F6F24_name_47->coords, &D_800F6F28_name_47->coords, &D_800F6F24_name_47->unk_18);
}

void func_800F6DE8_name_47(void) {
    MBModelKill(D_800F6F28_name_47);
    MBModelKill(D_800F6F24_name_47);
}

void func_800F6E14_name_47(void) {
    func_800178A0(1);
    func_80017660(0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    LoadBackgroundData(FE2310_ROM_START);
    LoadBackgroundIndex(2);
}

void func_800F6EB4_name_47(void) {
    func_8004A140();
    func_80049F0C();
}
