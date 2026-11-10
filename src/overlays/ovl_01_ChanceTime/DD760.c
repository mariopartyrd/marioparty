#include "ChanceTime.h"

s32 func_80045EF8(s16 a, s16 b);
void func_80045FF4(s16 a, s16 b);


/* .data (0x80101320..0x80101360) */
s8 D_80101320_ChanceTime = 0;
s16 D_80101324_ChanceTime[2] = { 0, 0 };
s16 D_80101328_ChanceTime[2] = { 0, 0 };
s8 D_8010132C_ChanceTime = 0;
char* D_80101330_ChanceTime[6] = {
    (char*)D_80101654_ChanceTime, (char*)D_8010164C_ChanceTime, (char*)D_80101644_ChanceTime,
    (char*)D_8010163C_ChanceTime, (char*)D_80101634_ChanceTime, (char*)D_80101630_ChanceTime,
};
char* D_80101348_ChanceTime[6] = {
    (char*)D_8010166C_ChanceTime, (char*)D_80101664_ChanceTime, (char*)D_8010165C_ChanceTime,
    NULL, NULL, NULL,
};

void func_800FEB60_ChanceTime(f32 zoom, f32 rotX, f32 rotY, f32 rotZ, f32 x, f32 y, f32 z) {
    CZoom = zoom;
    CRot.x = rotX;
    CRot.y = rotY;
    CRot.z = rotZ;
    Center.x = x;
    Center.y = y;
    Center.z = z;
}

void func_800FEBA0_ChanceTime(omObjData* obj) {
    if (D_800F5144 == 1) {
        if (D_8010132C_ChanceTime == 0) {
            func_800726AC(D_801011F0_ChanceTime == 0 ? 5 : 3, 16);
            D_8010132C_ChanceTime = 1;
        } else if (func_80072718() == 0) {
            func_80054654();
            func_8004A140();
            func_80049F0C();
            GMesSprClose();
            func_80070ED4();
            func_800601D4(0x28);
            omOvlReturnEx(1);
        }
    }
}

s16 func_800FEC4C_ChanceTime(omObjData* obj, f32 size, omObjData* other) {
    Vec d;
    CTPlayerWork* work = CT_PWORK(other);
    f32 half;

    d.x = other->trans.x - obj->trans.x;
    d.y = other->trans.y + work->unk_34 + 10.0f - obj->trans.y;
    d.z = other->trans.z - obj->trans.z;
    half = size / 2.0f;
    if (-half < d.x && d.x < half && -half < d.z && d.z < half && -half < d.y && d.y < half) {
        return 1;
    }
    return 0;
}

const char D_80101630_ChanceTime[] = "DK";

const char D_80101634_ChanceTime[] = "Wario";

const char D_8010163C_ChanceTime[] = "Yoshi";

const char D_80101644_ChanceTime[] = "Peach";

const char D_8010164C_ChanceTime[] = "Luigi";

const char D_80101654_ChanceTime[] = "Mario";

const char D_8010165C_ChanceTime[] = "none";

const char D_80101664_ChanceTime[] = "Coins";

/* 7 bytes: retail has a second NUL after "Stars" (0x80101672) */
const char D_8010166C_ChanceTime[7] = "Stars";

// register allocation: coin count in a0 not a1, compare on the copy (masked 0)
#ifdef NON_MATCHING
void func_800FED28_ChanceTime(void) {
    char unused[0x30]; /* retail's frame has 0x30 unreferenced bytes */
    s32 msg;
    s32 kind;
    s8 swap;
    s16 win;
    s32 n;
    s32 c;
    s16 a;
    u8 left;
    u8 right;

    msg = 0;
    kind = 0;
    swap = 0;
    D_80101320_ChanceTime = 0;
    win = CreateTextWindow(100, 140, 17, 4);
    ShowTextWindow(win);
    n = 0;
    switch (D_801012E2_ChanceTime) {
    case 0:
        swap = 0;
        if (GwPlayer[D_801012E0_ChanceTime].stars != 0) {
            D_80101328_ChanceTime[0]--;
            D_80101328_ChanceTime[1]++;
        }
        msg = 0xEC;
        kind = 0;
        break;
    case 1:
        swap = 1;
        if (GwPlayer[D_801012E1_ChanceTime].stars != 0) {
            D_80101328_ChanceTime[0]++;
            D_80101328_ChanceTime[1]--;
        }
        msg = 0xEC;
        kind = 0;
        break;
    case 2:
        if (GwPlayer[D_801012E0_ChanceTime].coins != 0) {
            c = GwPlayer[D_801012E0_ChanceTime].coins;
            n = 10;
            if (c < 10) {
                n = c;
            }
        }
        D_80101324_ChanceTime[0] -= n;
        D_80101324_ChanceTime[1] = n + D_80101324_ChanceTime[1];
        swap = 0;
        msg = 0xEB;
        kind = 1;
        break;
    case 3:
        if (GwPlayer[D_801012E1_ChanceTime].coins != 0) {
            c = GwPlayer[D_801012E1_ChanceTime].coins;
            if (c < 10) {
                n = c;
            } else {
                n = 10;
            }
        }
        D_80101324_ChanceTime[0] = n + D_80101324_ChanceTime[0];
        D_80101324_ChanceTime[1] -= n;
        swap = 1;
        msg = 0xEB;
        kind = 1;
        break;
    case 4:
        a = GwPlayer[D_801012E0_ChanceTime].coins;
        D_80101324_ChanceTime[0] = GwPlayer[D_801012E1_ChanceTime].coins - a;
        D_80101324_ChanceTime[1] = a - GwPlayer[D_801012E1_ChanceTime].coins;
        swap = 0;
        msg = 0xEF;
        kind = 1;
        break;
    case 5:
        if (GwPlayer[D_801012E0_ChanceTime].coins != 0) {
            c = GwPlayer[D_801012E0_ChanceTime].coins;
            n = 20;
            if (c < 20) {
                n = c;
            }
        }
        D_80101324_ChanceTime[0] -= n;
        D_80101324_ChanceTime[1] = n + D_80101324_ChanceTime[1];
        swap = 0;
        msg = 0xEB;
        kind = 1;
        break;
    case 6:
        if (GwPlayer[D_801012E1_ChanceTime].coins != 0) {
            c = GwPlayer[D_801012E1_ChanceTime].coins;
            if (c < 20) {
                n = c;
            } else {
                n = 20;
            }
        }
        D_80101324_ChanceTime[0] = n + D_80101324_ChanceTime[0];
        D_80101324_ChanceTime[1] -= n;
        swap = 1;
        msg = 0xEB;
        kind = 1;
        break;
    case 7:
        if (GwPlayer[D_801012E0_ChanceTime].coins != 0) {
            c = GwPlayer[D_801012E0_ChanceTime].coins;
            n = 30;
            if (c < 30) {
                n = c;
            }
        }
        D_80101324_ChanceTime[0] -= n;
        D_80101324_ChanceTime[1] = n + D_80101324_ChanceTime[1];
        swap = 0;
        msg = 0xEB;
        kind = 1;
        break;
    case 8:
        if (GwPlayer[D_801012E1_ChanceTime].coins != 0) {
            c = GwPlayer[D_801012E1_ChanceTime].coins;
            if (c < 30) {
                n = c;
            } else {
                n = 30;
            }
        }
        D_80101324_ChanceTime[0] = n + D_80101324_ChanceTime[0];
        D_80101324_ChanceTime[1] -= n;
        swap = 1;
        msg = 0xEB;
        kind = 1;
        break;
    case 9:
        if (func_80045EF8(D_801012E0_ChanceTime, D_801012E1_ChanceTime) != 0) {
            func_80045FF4(D_801012E0_ChanceTime, D_801012E1_ChanceTime);
            msg = 0xF1;
        } else {
            msg = 0xF2;
        }
        swap = 0;
        kind = 2;
        break;
    case 10:
        a = GwPlayer[D_801012E0_ChanceTime].stars;
        D_80101328_ChanceTime[0] = GwPlayer[D_801012E1_ChanceTime].stars - a;
        D_80101328_ChanceTime[1] = a - GwPlayer[D_801012E1_ChanceTime].stars;
        swap = 0;
        msg = 0xF3;
        kind = 0;
        break;
    }
    if (swap == 0) {
        left = GwPlayer[D_801012E0_ChanceTime].character;
        right = GwPlayer[D_801012E1_ChanceTime].character;
    } else {
        right = GwPlayer[D_801012E0_ChanceTime].character;
        left = GwPlayer[D_801012E1_ChanceTime].character;
    }
    func_8006DA5C(win, D_80101330_ChanceTime[left], 0);
    func_8006DA5C(win, D_80101330_ChanceTime[right], 1);
    func_8006DA5C(win, D_80101348_ChanceTime[kind], 2);
    LoadStringIntoWindow(win, (void*)msg, -1, -1);
    func_8006E070(win, 0);
    WaitForTextConfirmation(win);
    D_80101320_ChanceTime = 1;
    HideTextWindow(win);
    while (1) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/DD760", func_800FED28_ChanceTime);
#endif
void func_800FF2B8_ChanceTime(void) {
    s16 temp_s0;

    D_80101320_ChanceTime = 0;
    temp_s0 = CreateTextWindow(100, 140, 17, 4);
    ShowTextWindow(temp_s0);
    LoadStringIntoWindow(temp_s0, (void*)0xEA, -1, -1);
    func_8006E070(temp_s0, 0);
    func_8004DBD4(temp_s0, D_80101AAE_ChanceTime[0]);
    D_80101320_ChanceTime = 1;
    HideTextWindow(temp_s0);
    while (1) {
        HuPrcVSleep();
    }
    
}

void func_800FF354_ChanceTime(void) {
    s16 temp_s0;

    D_80101320_ChanceTime = 0;
    temp_s0 = CreateTextWindow(0x1E, 0x3C, 0x12, 4);
    ShowTextWindow((s32) temp_s0);
    LoadStringIntoWindow(temp_s0, (void*)0xD0, -1, -1);
    func_8006E070(temp_s0, 0);
    func_8004DBD4(temp_s0, D_80101AAE_ChanceTime[0]);
    D_80101320_ChanceTime = 1;
    HideTextWindow((s32) temp_s0);
    while (1) {
        HuPrcVSleep();
    }
    
}

void func_800FF3F0_ChanceTime(void) {
    s32 max;
    s16 win;
    s16 n;
    s16 c;

    max = 0;
    D_80101320_ChanceTime = 0;
    win = CreateTextWindow(30, 60, 18, 4);
    ShowTextWindow(win);
    n = 0;
    switch (D_801012E2_ChanceTime) {
    case 2:
        if (GwPlayer[D_801012E0_ChanceTime].coins != 0) {
            c = GwPlayer[D_801012E0_ChanceTime].coins;
            n = 10;
            if (c < 10) {
                n = c;
            }
        }
        max = 10;
        D_80101324_ChanceTime[0] -= n;
        break;
    case 5:
        if (GwPlayer[D_801012E0_ChanceTime].coins != 0) {
            c = GwPlayer[D_801012E0_ChanceTime].coins;
            n = 20;
            if (c < 20) {
                n = c;
            }
        }
        max = 20;
        D_80101324_ChanceTime[0] -= n;
        break;
    case 7:
        if (GwPlayer[D_801012E0_ChanceTime].coins != 0) {
            c = GwPlayer[D_801012E0_ChanceTime].coins;
            n = 30;
            if (c < 30) {
                n = c;
            }
        }
        max = 30;
        D_80101324_ChanceTime[0] -= n;
        break;
    }
    func_8006DA5C(win, D_80101330_ChanceTime[GwPlayer[D_801012E0_ChanceTime].character], 0);
    sprintf(D_80101780_ChanceTime, "%d", n);
    func_8006DA5C(win, D_80101780_ChanceTime, 1);
    func_8006E070(win, 0);
    if (n >= max) {
        LoadStringIntoWindow(win, (void*)0xD1, -1, -1);
    } else {
        LoadStringIntoWindow(win, (void*)0xD2, -1, -1);
    }
    WaitForTextConfirmation(win);
    func_80055960(D_801012E0_ChanceTime, -n);
    if (n != 0 && D_801012E0_ChanceTime == D_80101AAE_ChanceTime[0]) {
        func_800184BC(D_800F3FB0[0], 0x24);
    }
    func_8006EB40(win);
    LoadStringIntoWindow(win, (void*)0xD3, -1, -1);
    WaitForTextConfirmation(win);
    D_80101320_ChanceTime = 1;
    HideTextWindow(win);
    while (1) {
        HuPrcVSleep();
    }
}

/* unreferenced, after the "%d" above (the asm carries them otherwise) */
const char D_801016A8_ChanceTime[] = "";
const char D_801016AC_ChanceTime[] = "";
