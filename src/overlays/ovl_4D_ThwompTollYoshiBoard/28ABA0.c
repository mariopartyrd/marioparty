#include "common.h"
#include "28ABA0.h"
#include "engine/process.h"

typedef struct unkStruct_ovl4D_0 {
    /* 0x00 */ u8 unk_00[4];
} unkStruct_ovl4D_0;

void func_8004DBD4(s32, u8);
s32 func_800F68C8_ThwompTollYoshiBoard(void);
extern u16 D_800F2CF0[4];

s32 D_800F7620_ThwompTollYoshiBoard = 0;
Vec3f D_800F7624_ThwompTollYoshiBoard = {-80.0f, 0.0f, 1310.0f};
/* [1] is the Thwomp's raised position; its y (D_800F7640) is the rise height */
Vec3f D_800F7630_ThwompTollYoshiBoard[] = {{80.0f, 0.0f, 1520.0f}, {-80.0f, 200.0f, 1310.0f}};
s32 D_800F7648_ThwompTollYoshiBoard[] = {0x00000001, 0x00010001};
s32 D_800F7650_ThwompTollYoshiBoard[] = {0x00000001, 0x00020001};
s32 D_800F7658_ThwompTollYoshiBoard[] = {0x00000001, 0x00060001};
s32 D_800F7660_ThwompTollYoshiBoard[] = {0x00000001, 0x00030001};
s32 D_800F7668_ThwompTollYoshiBoard[] = {0x00000001, 0x00040001};
s32 D_800F7670_ThwompTollYoshiBoard[] = {0x00000001, 0x00050001};
s32* D_800F7678_ThwompTollYoshiBoard[] = {
    D_800F7648_ThwompTollYoshiBoard, D_800F7650_ThwompTollYoshiBoard,
    D_800F7658_ThwompTollYoshiBoard, D_800F7660_ThwompTollYoshiBoard,
    D_800F7668_ThwompTollYoshiBoard, D_800F7670_ThwompTollYoshiBoard
};

void func_800F65E0_ThwompTollYoshiBoard(void) {
    D_800F76B0_ThwompTollYoshiBoard = GwSystem.curPlayerIndex;
    omInitObjMan(50, 10);
    func_800F7550_ThwompTollYoshiBoard();
    func_800F741C_ThwompTollYoshiBoard();
    func_800544E4();
    func_800546B4(0, GwPlayer[0].turn_status);
    func_800546B4(1, GwPlayer[1].turn_status);
    func_800546B4(2, GwPlayer[2].turn_status);
    func_800546B4(3, GwPlayer[3].turn_status);
    func_8006CEA0();
    omAddPrcObj(&func_800F6A98_ThwompTollYoshiBoard, 0x300, 0, 0);
    omAddObj(0x1000, 0, 0, -1, &func_800F73BC_ThwompTollYoshiBoard);
    if (D_800C597A != 0) {
        SetFadeInTypeAndTime(6, 8);
    } else {
        SetFadeInTypeAndTime(1, 16);
    }
}

s32 func_800F66D0_ThwompTollYoshiBoard(s32 arg0) {
    s16 sp18[4];
    s32 var_s3 = 0;
    unkStruct_ovl4D_0 sp20 = {{0x01, 0x02, 0x04, 0x08}};
    s32 i;

    GwCommon.boardWork[3] = 0;
    for (i = 0; i < 4; i++) {
        if (i == D_800F76B0_ThwompTollYoshiBoard) {
            if (GwPlayer[i].flags & 1) {
                var_s3 = 1;
                sp18[GwPlayer[i].port] = 0x400;
            } else {
                func_8007155C(arg0, sp20.unk_00[GwPlayer[i].port]);
                sp18[GwPlayer[i].port] = -1;
            }
        } else {
            sp18[GwPlayer[i].port] = 0;
        }
    }

    if (var_s3 != 0) {
        func_8006DA1C(arg0, 2, 2);
        sp18[GwPlayer[D_800F76B0_ThwompTollYoshiBoard].port] = -0x8000;
        func_80070FF8(sp18[0], sp18[1], sp18[2], sp18[3], func_8004DBBC());
    } else {
        func_800710A4(sp18[0], sp18[1], sp18[2], sp18[3]);
    }

    return func_8006FCF0(arg0, 0, 1);
}
s32 func_800F68C8_ThwompTollYoshiBoard(void) { //slightly odd match with assignments in elseif statement
    s32 temp_v0;
    s32 var_v0;

    temp_v0 = func_8005021C(100.0f);
    if ((GwCommon.boardWork[GwCommon.boardWork[2]] + 40) < GwPlayer[D_800F76B0_ThwompTollYoshiBoard].coins) {
        if (GwPlayer[D_800F76B0_ThwompTollYoshiBoard].cpu_difficulty_copy == 0) {
            var_v0 = 1;
            if (temp_v0 >= 80) {
                var_v0 = (-(temp_v0 >= 95) & 3) | 2;
            }
        } else {
            if (temp_v0 >= 60) {
                if (temp_v0 < 80) {
                    var_v0 = 2;
                } else {
                    var_v0 = 4;
                    if (temp_v0 < 90) {
                        var_v0 = 3;
                    }
                }
            } else {
                var_v0 = 1;
            }   
        }

    } else {
        if ((GwCommon.boardWork[GwCommon.boardWork[2]] + 20) < GwPlayer[D_800F76B0_ThwompTollYoshiBoard].coins) {
            if (GwPlayer[D_800F76B0_ThwompTollYoshiBoard].cpu_difficulty_copy != 0) {
                if (temp_v0 >= 70) {
                    var_v0 = (-(temp_v0 >= 90) & 3) | 2;
                } else {
                    var_v0 = 1;
                }
            } else {
                var_v0 = 1;
                if (temp_v0 >= 80) {
                    var_v0 = (-(temp_v0 >= 95) & 3) | 2;
                }
            }
        } else if ((GwPlayer[D_800F76B0_ThwompTollYoshiBoard].cpu_difficulty_copy == 0) || (var_v0 = temp_v0 < 95, ((temp_v0 < 80) != 0))) {
            var_v0 = 1;
        } else {
            var_v0 = (-(temp_v0 >= 95) & 3) | 2;
        }
    }
    
    var_v0 += GwCommon.boardWork[GwCommon.boardWork[2]];
    
    if (var_v0 >= 51) {
        var_v0 = 50;
    }
    
    if (GwPlayer[D_800F76B0_ThwompTollYoshiBoard].coins < var_v0) {
        var_v0 = GwPlayer[D_800F76B0_ThwompTollYoshiBoard].coins;
    }
    
    return var_v0;
}


void func_800F6A98_ThwompTollYoshiBoard(void) {
    char sp10[8];
    s32 sp1C;
    s32 window;
    s32 choice;
    s32 amount;
    s32 result;
    s32 frames;
    s32 cpuWait;
    s32 prev;

    sp1C = 0;
    if (D_800C597A == 0) {
        func_800421E0();
        HuPrcSleep(0x10);
        PlaySound(0xAA);
        HuPrcSleep(0xA);
    } else {
        HuPrcSleep(8);
    }
    sprintf(sp10, "%d", GwCommon.boardWork[GwCommon.boardWork[2]] + 1);
    if (GwPlayer[D_800F76B0_ThwompTollYoshiBoard].coins < GwCommon.boardWork[GwCommon.boardWork[2]] + 1) {
        if (GwCommon.boardWork[GwCommon.boardWork[2]] + 1 == 1000) {
            window = CreateTextWindow(0x64, 0x28, 0x10, 5);
            func_8006DA5C(window, sp10, 0);
            LoadStringIntoWindow(window, (void*)0x1B4, -1, -1);
            func_8006E070(window, 0);
            ShowTextWindow(window);
            func_8004DBD4(window, D_800F76B0_ThwompTollYoshiBoard);
            HideTextWindow(window);
        } else {
            window = CreateTextWindow(0x78, 0x3C, 0xE, 2);
            func_8006DA5C(window, sp10, 0);
            if (GwCommon.boardWork[GwCommon.boardWork[2]] + 1 == 50) {
                LoadStringIntoWindow(window, (void*)0x1B8, -1, -1);
            } else {
                LoadStringIntoWindow(window, (void*)0x1B5, -1, -1);
            }
            func_8006E070(window, 0);
            ShowTextWindow(window);
            func_8004DBD4(window, D_800F76B0_ThwompTollYoshiBoard);
            HideTextWindow(window);
        }
    } else {
retry:
            window = CreateTextWindow(0x78, 0x28, 0xD, 6);
            sprintf(sp10, "%d", GwCommon.boardWork[GwCommon.boardWork[2]] + 1);
            func_8006DA5C(window, sp10, 0);
            if (GwCommon.boardWork[GwCommon.boardWork[2]] + 1 == 50) {
                LoadStringIntoWindow(window, (void*)0x1B7, -1, -1);
            } else {
                LoadStringIntoWindow(window, (void*)0x1AF, -1, -1);
            }
            func_8006E070(window, 0);
            ShowTextWindow(window);
            while (func_8006FCC0(window) != 0) {
                HuPrcVSleep();
            }
            choice = func_800F66D0_ThwompTollYoshiBoard(window);
            HideTextWindow(window);
            if (choice == 2) {
                D_800F7620_ThwompTollYoshiBoard = 1;
            } else if (choice == 1) {
                window = CreateTextWindow(0x8C, 0x3C, 8, 2);
                LoadStringIntoWindow(window, (void*)0x1B3, -1, -1);
                func_8006E070(window, 0);
                ShowTextWindow(window);
                func_8004DBD4(window, D_800F76B0_ThwompTollYoshiBoard);
                HideTextWindow(window);
            } else {
                window = CreateTextWindow(0x78, 0x3C, 0xE, 5);
                LoadStringIntoWindow(window, (void*)0x1B0, -1, -1);
                func_8006E070(window, 0);
                ShowTextWindow(window);
                amount = GwCommon.boardWork[GwCommon.boardWork[2]] + 1;
                sprintf(sp10, "%-3d", amount);
                func_8006DA5C(window, sp10, 0);
                func_8006DA1C(window, 0, 4);
                while (func_8006FCC0(window) != 0) {
                    HuPrcVSleep();
                }
                frames = 0;
                result = -1;
                prev = -1;
                if (GwPlayer[D_800F76B0_ThwompTollYoshiBoard].flags & 1) {
                    sp1C = func_800F68C8_ThwompTollYoshiBoard();
                }
                cpuWait = 0;
                while (1) {
                    if (prev != amount) {
                        sprintf(sp10, "\x06%-3d", amount);
                        LoadStringIntoWindow(window, sp10, 0x3D, 0x20);
                        prev = amount;
                    }
                    if (GwPlayer[D_800F76B0_ThwompTollYoshiBoard].flags & 1) {
                        if (cpuWait == 0) {
                            HuPrcSleep(func_8004DBBC());
                        }
                        cpuWait++;
                        if (frames == 16) {
                            if (sp1C == amount) {
                                result = 1;
                                PlaySound(0xF7);
                                frames = 0;
                            } else {
                                amount++;
                                frames = 0;
                            }
                        }
                    } else {
                        if (ContBtnTrg[GwPlayer[D_800F76B0_ThwompTollYoshiBoard].port] & 0x8000) {
                            result = 1;
                            PlaySound(0xF7);
                        } else if (ContBtnTrg[GwPlayer[D_800F76B0_ThwompTollYoshiBoard].port] & 0x4000) {
                            result = 0;
                            PlaySound(0xF8);
                        } else if (D_800F2CF0[GwPlayer[D_800F76B0_ThwompTollYoshiBoard].port] & 0x800) {
                            if (GwPlayer[D_800F76B0_ThwompTollYoshiBoard].coins >= amount + 1) {
                                amount++;
                            }
                        } else if (D_800F2CF0[GwPlayer[D_800F76B0_ThwompTollYoshiBoard].port] & 0x100) {
                            if (GwPlayer[D_800F76B0_ThwompTollYoshiBoard].coins >= amount + 10) { amount += 10; } else { amount = GwPlayer[D_800F76B0_ThwompTollYoshiBoard].coins; }
                        } else if (D_800F2CF0[GwPlayer[D_800F76B0_ThwompTollYoshiBoard].port] & 0x400) {
                            if (GwCommon.boardWork[GwCommon.boardWork[2]] + 1 <= amount - 1) {
                                amount--;
                            }
                        } else if (D_800F2CF0[GwPlayer[D_800F76B0_ThwompTollYoshiBoard].port] & 0x200) {
                            if (amount - 10 >= GwCommon.boardWork[GwCommon.boardWork[2]] + 1) { amount -= 10; } else { amount = GwCommon.boardWork[GwCommon.boardWork[2]] + 1; }
                        }
                        if (amount >= 51) {
                            amount = 50;
                        }
                    }
                    if (result != -1) {
                        break;
                    }
                    if (prev != amount) {
                        PlaySound(0xF5);
                    }
                    frames++;
                    HuPrcVSleep();
                }
                HideTextWindow(window);
                if (result == 0) {
                    goto retry;
                }
                func_80055960(D_800F76B0_ThwompTollYoshiBoard, -amount);
                HuPrcSleep(0x1E);
                GwCommon.boardWork[3] = 1;
                if (amount == 50) {
                    GwCommon.boardWork[GwCommon.boardWork[2]] = 0x31;
                } else {
                    GwCommon.boardWork[GwCommon.boardWork[2]] = amount;
                }
                window = CreateTextWindow(0x8C, 0x3C, 0xB, 1);
                LoadStringIntoWindow(window, (void*)0x1B1, -1, -1);
                func_8006E070(window, 0);
                ShowTextWindow(window);
                func_8004DBD4(window, D_800F76B0_ThwompTollYoshiBoard);
                HideTextWindow(window);
                for (result = 0; result < 20; result++) {
                    D_800F76B4_ThwompTollYoshiBoard->unk_30 += D_800F7630_ThwompTollYoshiBoard[1].y / 20.0f;
                    HuPrcVSleep();
                }
            }
    }
    D_800F5144 = 1;
    while (1) {
        HuPrcVSleep();
    }
}
void func_800F7340_ThwompTollYoshiBoard(void) {
    if (func_80072718() == 0) {
        func_800F75F0_ThwompTollYoshiBoard();
        func_800F7524_ThwompTollYoshiBoard();
        func_80054654();
        func_80070ED4();
        if (D_800F7620_ThwompTollYoshiBoard == 0) {
            omOvlReturnEx(1);
            return;
        }
        func_8004F284();
        func_8004F28C(0x4D, (s16)D_800F7620_ThwompTollYoshiBoard);
    }
}

void func_800F73BC_ThwompTollYoshiBoard(omObjData* arg0) {
    if (D_800F5144 != 0) {
        if (D_800F7620_ThwompTollYoshiBoard != 0) {
            func_800726AC(6, 8);
        } else {
            func_800726AC(1, 16);
        }
        arg0->func_ptr = &func_800F7340_ThwompTollYoshiBoard;
    }
}

void func_800F741C_ThwompTollYoshiBoard(void) {
    MBModelInit();
    D_800F76B4_ThwompTollYoshiBoard = MBModelCreate(13, NULL);
    D_800F76B4_ThwompTollYoshiBoard->coords.x = D_800F7624_ThwompTollYoshiBoard.x;
    D_800F76B4_ThwompTollYoshiBoard->coords.y = D_800F7624_ThwompTollYoshiBoard.y;
    D_800F76B4_ThwompTollYoshiBoard->coords.z = D_800F7624_ThwompTollYoshiBoard.z;
    func_800A0D00((Vec3f*)&D_800F76B4_ThwompTollYoshiBoard->xScale, 2.0f, 2.0f, 2.0f);
    D_800F76B8_ThwompTollYoshiBoard = MBModelCreate(func_80052F04(D_800F76B0_ThwompTollYoshiBoard), D_800F7678_ThwompTollYoshiBoard[GwPlayer[D_800F76B0_ThwompTollYoshiBoard].character]);
    D_800F76B8_ThwompTollYoshiBoard->coords.x = D_800F7630_ThwompTollYoshiBoard[0].x;
    D_800F76B8_ThwompTollYoshiBoard->coords.y = D_800F7630_ThwompTollYoshiBoard[0].y;
    D_800F76B8_ThwompTollYoshiBoard->coords.z = D_800F7630_ThwompTollYoshiBoard[0].z;
    func_8004CCD0(&D_800F76B8_ThwompTollYoshiBoard->coords, &D_800F76B4_ThwompTollYoshiBoard->coords, &D_800F76B8_ThwompTollYoshiBoard->unk_18);
    func_8004CCD0(&D_800F76B4_ThwompTollYoshiBoard->coords, &D_800F76B8_ThwompTollYoshiBoard->coords, &D_800F76B4_ThwompTollYoshiBoard->unk_18);
}

void func_800F7524_ThwompTollYoshiBoard(void) {
    MBModelKill(D_800F76B8_ThwompTollYoshiBoard);
    MBModelKill(D_800F76B4_ThwompTollYoshiBoard);
}

void func_800F7550_ThwompTollYoshiBoard(void) {
    func_800178A0(1);
    func_80017660(0U, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0U, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    LoadBackgroundData(FE2310_ROM_START);
    LoadBackgroundIndex(0x15);
}

void func_800F75F0_ThwompTollYoshiBoard(void) {
    func_8004A140();
    func_80049F0C();
}
