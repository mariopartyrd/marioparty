#include "common.h"
#include "3005B0.h"

/* retail calls func_8006FCF0 unprototyped here: the s16 cursor is passed as is, not narrowed to
   the prototype's s8. The host calls it normally. */
#define func_8006FCF0_unproto(win, cur, arg) ((s32 (*)())func_8006FCF0)(win, cur, arg)

extern TextWindow* D_800ED4B0;

void func_8004DBD4(s32, s32);
void func_8005B300(void);
void func_8005B358(u8* buf);
void func_8005C384(void);
void func_8005CE8C(s32 flag);
s16 func_8005949C(s32);
void func_800532E0(void);
void func_800532F4(void);
void func_800565B4(void);
void func_80056700(void);

s32 func_800F6800_name_79(s32 flag);
void func_800F6844_name_79(void);
void func_800F6A7C_name_79(void);
s32 func_800F6AB4_name_79(void);
void func_800F6B00_name_79(void);
void func_800F6D18_name_79(s16 arg0);
void func_800F6D4C_name_79(void);
void func_800F7174_name_79(void);
void func_800F71F4_name_79(omObjData* arg0);
void func_800F7238_name_79(void);
void func_800F7318_name_79(void);
void func_800F735C_name_79(void);
void func_800F7410_name_79(void);

Object* D_800F7440_name_79 = NULL;
Object* D_800F7444_name_79 = NULL;
/* the menu choice; retail reads its low half (D_800F744A) back as the next cursor */
s32 D_800F7448_name_79 = 0;
/* background per progress rank (D_800F74F0) */
s32 D_800F744C_name_79[] = { 0x54, 0x55, 0x55, 0x56, 0x56, 0x56, 0x57, 0x58 };
Vec3f D_800F746C_name_79 = { -144.0f, 0.0f, 1576.0f };
Vec3f D_800F7478_name_79 = { 144.0f, 0.0f, 1576.0f };
Vec3f D_800F7484_name_79 = { 0.0f, 0.0f, 2000.0f };
/* message and window width per progress rank (D_800F74F4) */
s32 D_800F7490_name_79[] = { 0x4D2, 0x4D3, 0x4D4, 0x4D5, 0x4D6, 0x4D7, 0x4D8, 0x4D9, 0x4DA, 0x4DF, 0x4E0, 0x4E4 };
u8 D_800F74C0_name_79[] = { 0x12, 0x10, 0x11, 0x0E, 0x10, 0x0E, 0x12, 0x12, 0x11, 0x0F, 0x0F, 0x0D };
s32 D_800F74CC_name_79 = -1;
ResSpriteAnim* D_800F74D0_name_79 = NULL;

/* .bss */
extern s32 D_800F74F0_name_79;
extern s32 D_800F74F4_name_79;
extern GWQUEST D_800F74F8_name_79; /* the saved quest, read back from EEPROM */

void func_800F65E0_name_79(void) {
    D_800F74F0_name_79 = GwCommon.boardWork[0];
    if (func_8005CE48(0x38) != 0) {
        if (func_800F6AB4_name_79() == 50) {
            D_800F74F4_name_79 = 0xB;
        } else if (func_800F6AB4_name_79() == 49) {
            D_800F74F4_name_79 = 0xA;
        } else {
            D_800F74F4_name_79 = 9;
        }
    } else if (func_8005CE48(0x32) != 0) {
        D_800F74F4_name_79 = 8;
    } else if (func_8005CE48(0x2C) != 0) {
        D_800F74F4_name_79 = 7;
    } else if (func_8005CE48(0x26) != 0) {
        D_800F74F4_name_79 = 6;
    } else if (func_8005CE48(0x20) != 0 || func_8005CE48(0x18) != 0) {
        D_800F74F4_name_79 = 5;
    } else if (func_8005CE48(0x14) != 0) {
        D_800F74F4_name_79 = 4;
    } else if (func_8005CE48(0xF) != 0) {
        D_800F74F4_name_79 = 3;
    } else if (func_8005CE48(0xA) != 0) {
        D_800F74F4_name_79 = 2;
    } else if (func_8005CE48(7) != 0) {
        D_800F74F4_name_79 = 1;
    } else {
        D_800F74F4_name_79 = 0;
    }
    omInitObjMan(0x32, 0xA);
    func_800F735C_name_79();
    func_800F7238_name_79();
    func_8006CEA0();
    func_800532E0();
    func_800565B4();
    omAddPrcObj(func_800F6D4C_name_79, 0x300, 0x2000, 0);
    omAddObj(0x1000, 0, 0, -1, func_800F71F4_name_79);
    SetFadeInTypeAndTime(2, 0x10);
}

/* func_8005CE48 on the saved quest */
s32 func_800F6800_name_79(s32 flag) {
    return (s8)D_800F74F8_name_79.mgFlag[flag / 8] & (1 << (flag % 8));
}

void func_800F6844_name_79(void) {
    char buf0[8];
    char buf1[8];
    char buf2[16];
    s32 i;
    s32 count;
    ResSpriteAnim* spr;

    func_8005B358((u8*)&D_800F74F8_name_79);
    count = 0;
    for (i = 7; i < 57; i++) {
        count += func_800F6800_name_79(i) != 0;
    }
    spr = func_800429CC(D_800F74F8_name_79.charNo, 0);
    D_800F74D0_name_79 = spr;
    spr->flags |= 2;
    spr->x = 0x3E;
    spr->y = 0x5A;
    spr->attr = 0x10;
    D_800F74CC_name_79 = CreateTextWindow(0x18, 0x34, 0x18, 5);
    D_800ED4B0[D_800F74CC_name_79].unk_08 = 0x14;
    D_800ED4B0[D_800F74CC_name_79].unk_2A = 0x46;
    D_800ED4B0[D_800F74CC_name_79].unk_24 = 0x50;
    D_800ED4B0[D_800F74CC_name_79].unk_26 = 0xA;
    func_8006E154((s16)D_800F74CC_name_79, 0x100);
    sprintf(buf0, "%2d", count);
    if (func_800F6800_name_79(0x38) != 0) {
        func_8006DA5C((s16)D_800F74CC_name_79, "\x05", 0);
    } else {
        func_8006DA5C((s16)D_800F74CC_name_79, "\x08", 0);
    }
    func_8006DA5C((s16)D_800F74CC_name_79, buf0, 1);
    sprintf(buf1, "%2d", D_800F74F8_name_79.lifeNum);
    func_8006DA5C((s16)D_800F74CC_name_79, buf1, 2);
    sprintf(buf2, "%2d", D_800F74F8_name_79.coinNum);
    func_8006DA5C((s16)D_800F74CC_name_79, buf2, 3);
    func_8006E070((s16)D_800F74CC_name_79, 0);
    LoadStringIntoWindow((s16)D_800F74CC_name_79, (void*)0x4DB, 0x50, 0xA);
    while (func_8006FCC0((s16)D_800F74CC_name_79) != 0) {
        HuPrcVSleep();
    }
}

void func_800F6A7C_name_79(void) {
    if (D_800F74D0_name_79 != NULL) {
        func_80042B10(D_800F74D0_name_79);
        func_80070D90((s16)D_800F74CC_name_79);
    }
}

s32 func_800F6AB4_name_79(void) {
    s32 i;
    s32 var_s1 = 0;
    
    for (i = 7; i < 57; i++) {
        var_s1 += func_8005CE48(i) != 0;   
    }
    
    return var_s1;
}

void func_800F6B00_name_79(void) {
    char buf0[8];
    char buf1[8];
    char buf2[16];
    s32 i;
    s32 count;
    ResSpriteAnim* spr;

    if (D_800F74D0_name_79 != NULL) {
        count = 0;
        func_80042B10(D_800F74D0_name_79);
        spr = func_800429CC(GwQuest.charNo, 0);
        D_800F74D0_name_79 = spr;
        spr->x = 0x3E;
        spr->y = 0x5A;
        spr->attr = 0x10;
        for (i = 7; i < 57; i++) {
            count += func_8005CE48(i) != 0;
        }
        sprintf(buf0, "%2d", count);
        if (func_8005CE48(0x38) != 0) {
            func_8006DA5C((s16)D_800F74CC_name_79, "\x05", 0);
        } else {
            func_8006DA5C((s16)D_800F74CC_name_79, "\x08", 0);
        }
        func_8006DA5C((s16)D_800F74CC_name_79, buf0, 1);
        sprintf(buf1, "%2d", GwQuest.lifeNum);
        func_8006DA5C((s16)D_800F74CC_name_79, buf1, 2);
        sprintf(buf2, "%2d", GwQuest.coinNum);
        func_8006DA5C((s16)D_800F74CC_name_79, buf2, 3);
        func_8006DA1C((s16)D_800F74CC_name_79, 0, 4);
        LoadStringIntoWindow((s16)D_800F74CC_name_79, (void*)0x4DC, 0xB8, 0xA);
        while (func_8006FCC0((s16)D_800F74CC_name_79) != 0) {
            HuPrcVSleep();
        }
        LoadStringIntoWindow((s16)D_800F74CC_name_79, (void*)0x4DD, 0x72, 0x20);
        while (func_8006FCC0((s16)D_800F74CC_name_79) != 0) {
            HuPrcVSleep();
        }
        LoadStringIntoWindow((s16)D_800F74CC_name_79, (void*)0x4DE, 0x76, 0x36);
        while (func_8006FCC0((s16)D_800F74CC_name_79) != 0) {
            HuPrcVSleep();
        }
    }
}

void func_800F6D18_name_79(s16 arg0) {
    s16 thing = 1 << GwPlayer[0].port;
    func_8007155C(arg0, thing);
}

void func_800F6D4C_name_79(void) {
    s16 win1;
    s16 win2;
    s32 choice;

    func_800421E0();
    HuPrcSleep(0x1A);
    win1 = CreateTextWindow(0x4A, 0xAA, 0x10, 3);
    LoadStringIntoWindow(win1, (void*)0x4CF, -1, -1);
    func_8006E070(win1, 0);
    ShowTextWindow(win1);
    PlaySound(0x432);
    win2 = CreateTextWindow(0x3C, 0x36, 0x12, 4);
    LoadStringIntoWindow(win2, (void*)0x4CE, -1, -1);
    func_8006E070(win2, 0);
    while (func_8006FCC0(win2) != 0) {
        HuPrcVSleep();
    }
loop:
    {
        func_800F6D18_name_79(win2);
        D_800F7448_name_79 = func_8006FCF0_unproto(win2, (s16)D_800F7448_name_79, 0);
        if (D_800F7448_name_79 == -1) {
            goto end;
        }
        if (D_800F7448_name_79 < 2) {
            if (func_8005CE48(0) != 0) {
                func_800F6844_name_79();
                func_8006EB40(win1);
                LoadStringIntoWindow(win1, (void*)0x4D0, -1, -1);
                func_8006E070(win1, 0);
                while (func_8006FCC0(win1) != 0) {
                    HuPrcVSleep();
                }
                func_800F6D18_name_79(win1);
                if (func_8006FCF0(win1, 0, 0) != 0) {
                    func_8006EB40(win1);
                    LoadStringIntoWindow(win1, (void*)0x4CF, -1, -1);
                    func_800F6A7C_name_79();
                    goto loop;
                }
            }
            func_8006EB40(win1);
            func_8005CE8C(0);
            ClearBoardFeatureFlag(0);
            func_8005B300();
            func_800F6B00_name_79();
            LoadStringIntoWindow(win1, (void*)0x4D1, -1, -1);
            func_8006E070(win1, 0);
            func_8004DBD4(win1, 0);
            func_800F6A7C_name_79();
        }
    }
    func_80070D90(win2);
    HideTextWindow(win1);
    if ((D_800F7448_name_79 != 1) & (D_800F7448_name_79 != 3)) {
        win1 = CreateTextWindow(0x32, 0x3C, D_800F74C0_name_79[D_800F74F4_name_79], 3);
        LoadStringIntoWindow(win1, (void*)(s32)D_800F7490_name_79[D_800F74F4_name_79], -1, -1);
        func_8006E070(win1, 0);
        ShowTextWindow(win1);
        PlaySound(0x437);
        func_8004DBD4(win1, 0);
        if (D_800F74F4_name_79 == 0xA) {
            func_8006EB40(win1);
            LoadStringIntoWindow(win1, (void*)0x4E1, -1, -1);
            while (func_8006FCC0(win1) != 0) {
                HuPrcVSleep();
            }
            choice = func_8006FCF0(win1, 0, 1);
            func_8006EB40(win1);
            if (choice == 0) {
                LoadStringIntoWindow(win1, (void*)0x4E2, -1, -1);
            } else {
                LoadStringIntoWindow(win1, (void*)0x4E3, -1, -1);
            }
            func_8004DBD4(win1, 0);
        } else if (D_800F74F4_name_79 == 0xB) {
            if (func_8005949C(0x24) == 0) {
                func_8006EB40(win1);
                LoadStringIntoWindow(win1, (void*)0x4E5, -1, -1);
                func_8004DBD4(win1, 0);
            }
        }
        HideTextWindow(win1);
    }
end:
    D_800F5144 = 1;
    while (1) {
        HuPrcVSleep();
    }
}

void func_800F7174_name_79(void) {
    if (func_80072718() == 0) {
        func_800F7410_name_79();
        func_800F7318_name_79();
        func_80070ED4();
        func_80056700();
        func_800532F4();
        if ((D_800F7448_name_79 == 1) | (D_800F7448_name_79 == 3)) {
            func_8005C384();
        }
        omOvlReturnEx(1);
    }
}

void func_800F71F4_name_79(omObjData* arg0) {
    if (D_800F5144 != 0) {
        func_800726AC(2, 0x10);
        arg0->func_ptr = &func_800F7174_name_79;
    }
}

void func_800F7238_name_79(void) {
    MBModelInit();
    D_800F7444_name_79 = MBModelCreate(func_80052F04(0), NULL);
    func_800A0D00(&D_800F7444_name_79->coords, D_800F7478_name_79.x, D_800F7478_name_79.y, D_800F7478_name_79.z);
    func_8004CCD0(&D_800F7444_name_79->coords, &D_800F7484_name_79, &D_800F7444_name_79->unk_18);
    func_80021B14(*D_800F7444_name_79->unk_3C->unk_40, GwQuest.charNo, 0x80);
    D_800F7440_name_79 = MBModelCreate(0x83, NULL);
    func_800A0D00(&D_800F7440_name_79->coords, D_800F746C_name_79.x, D_800F746C_name_79.y, D_800F746C_name_79.z);
    func_8004CCD0(&D_800F7440_name_79->coords, &D_800F7484_name_79, &D_800F7440_name_79->unk_18);
}

void func_800F7318_name_79(void) {
    if (D_800F7440_name_79 != NULL) {
        MBModelKill(D_800F7440_name_79);
    }
    if (D_800F7444_name_79 != NULL) {
        MBModelKill(D_800F7444_name_79);
    }
}

void func_800F735C_name_79(void) {
    func_800178A0(1);
    func_80017660(0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    LoadBackgroundData(FE2310_ROM_START);
    LoadBackgroundIndex(D_800F744C_name_79[D_800F74F0_name_79]);
}

void func_800F7410_name_79(void) {
    func_8004A140();
    func_80049F0C();
}
