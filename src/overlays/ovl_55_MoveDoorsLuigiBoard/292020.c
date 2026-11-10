#include "engine/process.h"
#include "292020.h"

void func_80071788(s32, s16);
s32 func_800415E8(s32);

s32 D_800F7720_MoveDoorsLuigiBoard = 0;
Vec3f D_800F7724_MoveDoorsLuigiBoard = {-80.0f, 0.0f, 1310.0f};
Vec3f D_800F7730_MoveDoorsLuigiBoard = {80.0f, 0.0f, 1520.0f};
s32 D_800F773C_MoveDoorsLuigiBoard[] = {0x00000002, 0x000A00CF, 0x000A00D0};
/* CPU odds (percent) of paying for the doors, indexed [row][case] in func_800F66D0 */
u8 D_800F7748_MoveDoorsLuigiBoard[] = {
    0x00, 0x32, 0x50, 0x05, 0x5A, 0x05, 0x32, 0x5A, 0x05, 0x5A, 0x05, 0x32,
    0x50, 0x5A, 0x05, 0x50, 0x4B, 0x5A, 0x64, 0x50, 0x4B, 0x5A, 0x64, 0x05,
};
u8 D_800F7760_MoveDoorsLuigiBoard[] = {
    0x05, 0x3C, 0x3C, 0x1E, 0x3C, 0x14, 0x3C, 0x3C, 0x1E, 0x3C, 0x14, 0x3C,
    0x3C, 0x3C, 0x14, 0x3C, 0x3C, 0x46, 0x50, 0x3C, 0x3C, 0x46, 0x50, 0x0A,
};
u8 D_800F7778_MoveDoorsLuigiBoard[] = {
    0x32, 0x50, 0x00, 0x32, 0x50, 0x5A, 0x00, 0x46, 0x50, 0x00, 0x00, 0x50,
    0x4B, 0x5A, 0x64, 0x00, 0x50, 0x4B, 0x5A, 0x64, 0x0F, 0x05, 0x00, 0x00,
};
u8 D_800F7790_MoveDoorsLuigiBoard[] = {
    0x3C, 0x3C, 0x05, 0x3C, 0x3C, 0x3C, 0x05, 0x3C, 0x46, 0x05, 0x05, 0x3C,
    0x3C, 0x46, 0x50, 0x05, 0x3C, 0x3C, 0x46, 0x50, 0x1E, 0x14, 0x0A, 0x00,
};
u8 D_800F77A8_MoveDoorsLuigiBoard[] = {0x05, 0x28, 0x4B, 0x5A, 0x64, 0x05, 0x05, 0x00};
u8 D_800F77B0_MoveDoorsLuigiBoard[] = {0x14, 0x3C, 0x3C, 0x46, 0x50, 0x0A, 0x0A, 0x00};
u8 D_800F77B8_MoveDoorsLuigiBoard[] = {0x3C, 0x4B, 0x5A, 0x64, 0x05, 0x3C, 0x4B, 0x5A, 0x64, 0x05};
u8 D_800F77C4_MoveDoorsLuigiBoard[] = {0x28, 0x3C, 0x46, 0x50, 0x0A, 0x28, 0x3C, 0x46, 0x50, 0x0A};

typedef struct {
    u8 unk_00[4];
} unkStruct_ovl55_0;

/* func_8006FCF0 is called unprototyped in retail: the s16 cursor reaches it promoted to int
   (sll/sra 16), not narrowed to the prototype's s8. The host calls it normally. */
#define func_8006FCF0_unproto(win, cur, arg) ((s32 (*)())func_8006FCF0)(win, cur, arg)

void func_800F65E0_MoveDoorsLuigiBoard(void) {
    D_800F7820_MoveDoorsLuigiBoard = GwSystem.curPlayerIndex;
    omInitObjMan(50, 10);
    func_800F765C_MoveDoorsLuigiBoard();
    func_800F7528_MoveDoorsLuigiBoard();
    func_800544E4();
    func_800546B4(0, GwPlayer[0].turn_status);
    func_800546B4(1, GwPlayer[1].turn_status);
    func_800546B4(2, GwPlayer[2].turn_status);
    func_800546B4(3, GwPlayer[3].turn_status);
    func_8006CEA0();
    omAddPrcObj(func_800F7198_MoveDoorsLuigiBoard, 0x300, 0, 0);
    omAddObj(0x1000, 0, 0, -1, &func_800F74C8_MoveDoorsLuigiBoard);

    if (D_800C597A != 0) {
        SetFadeInTypeAndTime(6, 8);
    } else {
        SetFadeInTypeAndTime(1, 16);
    }
}


/* Retail's shape: the short arm of each test comes first (a label starts the long arm, so the
   player index and coins are reloaded there). */
#define P_ D_800F7820_MoveDoorsLuigiBoard
#define COINS GwPlayer[P_].coins
#define CPU_PICK(c, k0, k3, kx) \
    switch (func_8004FEBC(P_)) { \
    case 0:                     \
        c = k0;                 \
        break;                  \
    case 3:                     \
        c = k3;                 \
        break;                  \
    default:                    \
        c = kx;                 \
        break;                  \
    }

s32 func_800F66D0_MoveDoorsLuigiBoard(void) {
    s32 door = GwSystem.starSpaces[GwSystem.chosenStarSpaceIndex] + 1;
    u8* tbl[8] = {
        D_800F7748_MoveDoorsLuigiBoard, D_800F7760_MoveDoorsLuigiBoard, D_800F7778_MoveDoorsLuigiBoard,
        D_800F7790_MoveDoorsLuigiBoard, D_800F77A8_MoveDoorsLuigiBoard, D_800F77B0_MoveDoorsLuigiBoard,
        D_800F77B8_MoveDoorsLuigiBoard, D_800F77C4_MoveDoorsLuigiBoard,
    };
    s32 col;
    s32 row;
    s32 r;
    u8* p;

    col = 0;
    if (COINS < 20) {
        return 2;
    }
    if (GwCommon.boardWork[0] == 0) {
        if (GwCommon.boardWork[2] == 1) {
            row = GwPlayer[P_].cpu_difficulty_copy == 0;
            switch (door) {
            case 1:
                if (func_800415E8(P_) < 5) {
                    col = 0;
                } else if (func_800415E8(P_) < 8) {
                    if (COINS < 40) {
                        col = 1;
                    } else {
                        col = 2;
                    }
                } else if (COINS < 40) {
                    col = 3;
                } else {
                    col = 4;
                }
                break;
            case 3:
                if (func_800415E8(P_) < 5) {
                    col = 5;
                } else if (func_800415E8(P_) < 7) {
                    col = (COINS >= 40) ? 7 : 6;
                } else {
                    col = (COINS >= 40) ? 9 : 8;
                }
                break;
            case 4:
                if (func_800415E8(P_) < 5) {
                    col = 10;
                } else if (COINS < 40) {
                    col = 11;
                } else {
                    col = (COINS >= 59) ? 13 : 12;
                }
                break;
            case 6:
                if (func_800415E8(P_) < 5) {
                    col = 14;
                } else if (COINS < 40) {
                    col = 15;
                } else {
                    CPU_PICK(col, 16, 18, 17);
                }
                break;
            default:
                if (func_800415E8(P_) >= 5) {
                    col = 23;
                } else if (COINS < 40) {
                    col = 19;
                } else {
                    CPU_PICK(col, 20, 22, 21);
                }
                break;
            }
        } else {
            row = (GwPlayer[P_].cpu_difficulty_copy == 0) ? 3 : 2;
            switch (door) {
            case 1:
            case 3:
                if (func_800415E8(P_) < 5) {
                    col = COINS >= 40;
                } else {
                    col = 2;
                }
                break;
            case 4:
                if (func_800415E8(P_) < 5) {
                    if (COINS < 40) {
                        col = 3;
                    } else {
                        col = (COINS >= 59) ? 5 : 4;
                    }
                } else {
                    col = 6;
                }
                break;
            case 6:
                if (func_800415E8(P_) >= 5) {
                    col = 9;
                } else if (COINS < 40) {
                    col = 7;
                } else {
                    col = 8;
                }
                break;
            case 2:
                if (func_800415E8(P_) < 5) {
                    col = 10;
                } else if (COINS < 40) {
                    col = 11;
                } else {
                    CPU_PICK(col, 12, 14, 13);
                }
                break;
            case 5:
            case 7:
                if (func_800415E8(P_) < 5) {
                    col = 15;
                } else if (func_800415E8(P_) < 9) {
                    if (COINS < 40) {
                        col = 16;
                    } else {
                        CPU_PICK(col, 17, 19, 18);
                    }
                } else {
                    CPU_PICK(col, 20, 22, 21);
                }
                break;
            }
        }
    } else if (GwCommon.boardWork[2] == 1) {
        row = (GwPlayer[P_].cpu_difficulty_copy == 0) ? 5 : 4;
        if (door == 6) {
            if (func_800415E8(P_) < 2) {
                col = 0;
            } else if (func_800415E8(P_) >= 4) {
                col = 5;
            } else if (COINS < 40) {
                col = 1;
            } else {
                CPU_PICK(col, 2, 4, 3);
            }
        } else {
            col = 6;
        }
    } else {
        row = (GwPlayer[P_].cpu_difficulty_copy == 0) ? 7 : 6;
        if (door == 6) {
            if (func_800415E8(P_) < 2) {
                if (COINS < 40) {
                    col = 0;
                } else {
                    CPU_PICK(col, 1, 3, 2);
                }
            } else if (func_800415E8(P_) < 4) {
                col = 4;
            } else if (COINS < 40) {
                col = 5;
            } else {
                CPU_PICK(col, 6, 8, 7);
            }
        } else {
            col = 9;
        }
    }
    p = tbl[row];
    if (func_8005021C(100.0f) < p[col]) {
        return 1;
    }
    return 2;
}

#undef CPU_PICK
#undef COINS
#undef P_

// loop-invariant hoisting picks -1 instead of 0x400 for fp (masked 5, raw 7); swapping the flags arms hoists
// 0x400 but reorders the whole loop
#ifdef NON_MATCHING
s32 func_800F6F14_MoveDoorsLuigiBoard(s32 arg0, u8* arg1) {
    s16 sp18[4];
    s32 count = 0;
    unkStruct_ovl55_0 sp20 = {{0x01, 0x02, 0x04, 0x08}};
    s32 i;
    s32 j;

    for (i = 0; i < 4; i++) {
        if (i == D_800F7820_MoveDoorsLuigiBoard) {
            if (GwPlayer[i].flags & 1) {
                count = func_800F66D0_MoveDoorsLuigiBoard();
                sp18[GwPlayer[i].port] = 0x400;
            } else {
                func_8007155C(arg0, sp20.unk_00[GwPlayer[i].port]);
                sp18[GwPlayer[i].port] = -1;
            }
        } else {
            sp18[GwPlayer[i].port] = 0;
        }
    }

    if (count != 0) {
        func_8006DA1C(arg0, 2, 2);
        j = 0;
        do {
            if (--count == 0) {
                sp18[GwPlayer[D_800F7820_MoveDoorsLuigiBoard].port] = -0x8000;
            }
            if (j == 0) {
                func_80070FF8(sp18[0], sp18[1], sp18[2], sp18[3], func_8004DBBC());
            } else {
                func_80070FF8(sp18[0], sp18[1], sp18[2], sp18[3], 16);
            }
            j++;
        } while (count != 0);
    } else {
        func_800710A4(sp18[0], sp18[1], sp18[2], sp18[3]);
    }

    for (i = 0; i < 1; i++) {
        if (arg1[i] == 0) {
            func_80071788(arg0, i);
        }
    }

    i = 0;
    do {
        i = func_8006FCF0_unproto((s16)arg0, (s16)i, 1);
    } while (arg1[i] == 0);
    return i;
}
#else
/* the C path's local initialiser; named for the asm */
const unkStruct_ovl55_0 D_800F780C_MoveDoorsLuigiBoard __attribute__((section(".rodata"))) = {{0x01, 0x02, 0x04, 0x08}};
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_MoveDoorsLuigiBoard/292020", func_800F6F14_MoveDoorsLuigiBoard);
#endif

void func_800F7198_MoveDoorsLuigiBoard(void) {
    u8 sp10[3];
    s32 temp_v0;
    s32 temp_s0;

    if (D_800C597A == 0) {
        func_800421E0();
        HuPrcSleep(0x10);
        PlaySound(0xDA);
        HuPrcSleep(10);
    } else {
        HuPrcSleep(8);
    }
    
    temp_v0 = CreateTextWindow(0x3C, 0x28, 0x11, 7);
    
    if (GwPlayer[D_800F7820_MoveDoorsLuigiBoard].coins < 0x14) {
        func_8006DA5C(temp_v0, "\x01", 0);
        sp10[0] = 0;
    } else {
        func_8006DA5C(temp_v0, "\x08", 0);
        sp10[0] = 1;
    }
    sp10[2] = 1;
    sp10[1] = 1;
    LoadStringIntoWindow(temp_v0, (void* )0x1D5, -1, -1);
    func_8006E070(temp_v0, 0);
    ShowTextWindow(temp_v0);

    while (func_8006FCC0(temp_v0) != 0) {
        HuPrcVSleep();
    }
    
    temp_s0 = func_800F6F14_MoveDoorsLuigiBoard(temp_v0, sp10);
    
    HideTextWindow(temp_v0);
    if (temp_s0 == 2) {
        D_800F7720_MoveDoorsLuigiBoard = 1;
    } else if (temp_s0 == 1) {
        temp_v0 = CreateTextWindow(80, 60, 15, 3);
        LoadStringIntoWindow(temp_v0, (void* )0x1D7, -1, -1);
        func_8006E070(temp_v0, 0);
        ShowTextWindow(temp_v0);
        func_8004DBD4(temp_v0, D_800F7820_MoveDoorsLuigiBoard);
        HideTextWindow(temp_v0);
        GwCommon.boardWork[1] = 0;
    } else {
        func_80055960(D_800F7820_MoveDoorsLuigiBoard, -0x14);
        HuPrcSleep(30);
        GwCommon.boardWork[1] = 1;
        temp_v0 = CreateTextWindow(0x50, 0x3C, 0xD, 3);
        LoadStringIntoWindow(temp_v0, (void* )0x1D6, -1, -1);
        func_8006E070(temp_v0, 0);
        ShowTextWindow(temp_v0);
        func_8004DBD4(temp_v0, D_800F7820_MoveDoorsLuigiBoard);
        HideTextWindow(temp_v0);
        func_8004F4D4(D_800F7824_MoveDoorsLuigiBoard, 0, 0);
        func_800503B0(D_800F7820_MoveDoorsLuigiBoard, 1);
        PlaySound(0xE1);
        HuPrcSleep(15);
    }
    
    D_800F5144 = 1;
    
    while (1) {
        HuPrcVSleep();
    }
}

void func_800F744C_MoveDoorsLuigiBoard(void) {
    if (func_80072718() == 0) {
        func_800F76FC_MoveDoorsLuigiBoard();
        func_800F7630_MoveDoorsLuigiBoard();
        func_80054654();
        func_80070ED4();
        if (D_800F7720_MoveDoorsLuigiBoard == 0) {
            omOvlReturnEx(1);
            return;
        }
        func_8004F284();
        func_8004F28C(85, D_800F7720_MoveDoorsLuigiBoard);
    }
}

void func_800F74C8_MoveDoorsLuigiBoard(omObjData* arg0) {
    if (D_800F5144 != 0) {
        if (D_800F7720_MoveDoorsLuigiBoard != 0) {
            func_800726AC(6, 8);
        } else {
            func_800726AC(1, 16);
        }
        arg0->func_ptr = &func_800F744C_MoveDoorsLuigiBoard;
    }
}

void func_800F7528_MoveDoorsLuigiBoard(void) {
    MBModelInit();
    D_800F7824_MoveDoorsLuigiBoard = MBModelCreate(0x11, D_800F773C_MoveDoorsLuigiBoard);
    D_800F7824_MoveDoorsLuigiBoard->coords.x = D_800F7724_MoveDoorsLuigiBoard.x;
    D_800F7824_MoveDoorsLuigiBoard->coords.y = D_800F7724_MoveDoorsLuigiBoard.y;
    D_800F7824_MoveDoorsLuigiBoard->coords.z = D_800F7724_MoveDoorsLuigiBoard.z;
    MBMotionSet(D_800F7824_MoveDoorsLuigiBoard, 1, 2);
    D_800F7828_MoveDoorsLuigiBoard = MBModelCreate(func_80052F04(D_800F7820_MoveDoorsLuigiBoard), D_800C5490[GwPlayer[D_800F7820_MoveDoorsLuigiBoard].character]);
    D_800F7828_MoveDoorsLuigiBoard->coords.x = D_800F7730_MoveDoorsLuigiBoard.x;
    D_800F7828_MoveDoorsLuigiBoard->coords.y = D_800F7730_MoveDoorsLuigiBoard.y;
    D_800F7828_MoveDoorsLuigiBoard->coords.z = D_800F7730_MoveDoorsLuigiBoard.z;
    func_8004CCD0(&D_800F7828_MoveDoorsLuigiBoard->coords, &D_800F7824_MoveDoorsLuigiBoard->coords, &D_800F7828_MoveDoorsLuigiBoard->unk_18);
    func_8004CCD0(&D_800F7824_MoveDoorsLuigiBoard->coords, &D_800F7828_MoveDoorsLuigiBoard->coords, &D_800F7824_MoveDoorsLuigiBoard->unk_18);
}

void func_800F7630_MoveDoorsLuigiBoard(void) {
    MBModelKill(D_800F7828_MoveDoorsLuigiBoard);
    MBModelKill(D_800F7824_MoveDoorsLuigiBoard);
}

void func_800F765C_MoveDoorsLuigiBoard(void) {
    func_800178A0(1);
    func_80017660(0U, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0U, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    LoadBackgroundData(FE2310_ROM_START);
    LoadBackgroundIndex(41);
}

void func_800F76FC_MoveDoorsLuigiBoard(void) {
    func_8004A140();
    func_80049F0C();
}
