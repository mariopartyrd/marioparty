#include "BumperBalls.h"

/* .data */
Vec3f D_800FCB30_BumperBalls[4] = { /* start positions */
    { -300.0f, 220.0f, -300.0f },
    { 300.0f, 220.0f, -300.0f },
    { -300.0f, 220.0f, 300.0f },
    { 300.0f, 220.0f, 300.0f },
};
char* D_800FCB60_BumperBalls[6] = { /* ball texture per character */
    "38mt001_DEF", "38mt002_DEF", "38mt003_DEF", "38mt004_DEF", "38mt005_DEF", "38mt006_DEF",
};
u8 D_800FCB78_BumperBalls[4] = { 0, 0, 0, 0 }; /* start positions taken */
u8 D_800FCB7C_BumperBalls = 0; /* 3: take the start positions in order */
u8 D_800FCB7D_BumperBalls = 0; /* unreferenced filler */
u16 D_800FCB7E_BumperBalls = 0; /* entries in D_800FCB80 */
u16 D_800FCB80_BumperBalls[4] = { 10, 10, 10, 10 }; /* winners */
/* CPU mode tables (func_800F9F30): rand8() & 7 picks the mode. */
u16 D_800FCB88_BumperBalls[8] = { 1, 2, 3, 4, 1, 2, 3, 4 };
u16 D_800FCB98_BumperBalls[8] = { 1, 2, 3, 4, 1, 2, 3, 2 };
u16 D_800FCBA8_BumperBalls[8] = { 1, 3, 3, 4, 1, 1, 3, 4 };

/* "ＡＢＣ" (Shift-JIS) */
const u8 D_800FCC28_BumperBalls[] = { 0x82, 0x60, 0x82, 0x61, 0x82, 0x62, 0x00, 0x00 };

void func_800F65E0_BumperBalls(void) {
    void* temp_s0;
    void* temp_s0_2;
    s32 i;

    omInitObjMan(32, 0);
    func_80060088();
    D_800FCD1E_BumperBalls = 4;
    
    for (i = 0; i < 4; i++) {
        if (GwPlayer[i].flags & 1) {
            D_800FCD1E_BumperBalls--;
        }
    }
    
    func_80029090(2);
    func_8001DE70(24);
    func_8002ADF0(&D_800EDEC0, 64);
    func_8002890C(0, 32, 128);
    func_8002578C(1);
    func_800FB1E0_BumperBalls(20.0f, 3000.0f, 328.0f, 0, 0, 0, 0, -140.0f);
    func_80017660(0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, &omOutView), 160);
    func_80023448(3);
    func_800234B8(0, 44, 44, 64);
    func_800234B8(1, 96, 96, 16);
    func_80023504(1, 100.0f, 80.0f, 100.0f);
    func_800234B8(2, 0, 0, 0);
    func_80023504(2, 100.0f, 80.0f, 100.0f);
    func_800234B8(3, 0, 0, 0);
    func_80023504(3, 100.0f, 80.0f, 100.0f);
    func_8005D98C(0, 4);
    D_800FCD2C_BumperBalls = func_8005DB44(0);
    func_8005D98C(1, 4);
    D_800FCD30_BumperBalls = func_8005DB44(1);
    omSetStatBit(omAddObj(100, 0, 0, -1, &func_800FB298_BumperBalls), 160);
    omAddObj(20, 9, 7, 0, &func_800F6E2C_BumperBalls);
    omAddObj(20, 9, 7, 0, &func_800F6E68_BumperBalls);
    omAddObj(20, 9, 7, 0, &func_800F6E84_BumperBalls);
    omAddObj(20, 9, 7, 0, &func_800F6EA0_BumperBalls);
    omAddObj(10, 7, 0, 1, &func_800F8538_BumperBalls);
    omAddObj(10, 7, 0, 1, &func_800F8554_BumperBalls);
    omAddObj(10, 7, 0, 1, &func_800F8570_BumperBalls);
    omAddObj(10, 7, 0, 1, &func_800F858C_BumperBalls);
    omAddObj(0, 0, 0, -1, &func_800F6A60_BumperBalls);
    D_800FCD20_BumperBalls = omAddObj(6, 3, 0, -1, &func_800F6D98_BumperBalls);
    omAddObj(0x2710, 0, 0, -1, &func_800F9588_BumperBalls);
    D_800FCD18_BumperBalls = InitSprite(117);
    temp_s0 = DataRead(37);
    D_800FCD1A_BumperBalls = func_80039084(temp_s0);
    HuMemDirectFree(temp_s0);
    temp_s0_2 = DataRead(36);
    D_800FCD1C_BumperBalls = func_80039084(temp_s0_2);
    HuMemDirectFree(temp_s0_2);
    func_8007B168((u8*) D_800FCC28_BumperBalls, 1);
    D_800FCD12_BumperBalls = _CheckFlag(MINIGAME_ISLAND_ENDING);
    D_800FCFF0_BumperBalls = 0;
    SetFadeInTypeAndTime(0, 16);
}

void func_800F6A60_BumperBalls(omObjData* arg0) {
    D_800FCFF4_BumperBalls = 0;
    D_800FCD28_BumperBalls = 0;
    D_800FCD24_BumperBalls = 0;
    D_800FCD16_BumperBalls = 60;
    D_800FCD14_BumperBalls = 30;
    D_800FCD0E_BumperBalls = 0;
    D_800FCD10_BumperBalls = 4;
    arg0->func_ptr = &func_800F6AB4_BumperBalls;
}


void func_800F6AB4_BumperBalls(omObjData* arg0) {
    BumperBallsWork* work;
    s32 i;

    func_80079078(D_800FCD16_BumperBalls);
    switch (D_800FCFF4_BumperBalls) {
    case 0:
        if (D_800FCD24_BumperBalls == NULL) {
            D_800FCD24_BumperBalls = omAddObj(4, 0, 0, -1, func_800F8D68_BumperBalls);
        }
        break;
    case 1:
        if (D_800FCD10_BumperBalls >= 2) {
            D_800FCD14_BumperBalls--;
        }
        if (D_800FCD14_BumperBalls == 0) {
            if (D_800FCD16_BumperBalls != 0) {
                D_800FCD16_BumperBalls--;
            }
            D_800FCD14_BumperBalls = 30;
        }
        if (D_800FCD10_BumperBalls < 2 || D_800FCD16_BumperBalls == 0) {
            func_800601D4(0x28);
            if (func_800F9EE0_BumperBalls() == 1) {
                if (D_800FCD10_BumperBalls == 0) {
                    D_800FCFF4_BumperBalls = 2;
                    D_800FCFF2_BumperBalls = 4;
                } else {
                    D_800FCFF4_BumperBalls = 2;
                    D_800FCFF2_BumperBalls = 10;
                    for (i = 0; i < 4; i++) {
                        work = D_800FCD2C_BumperBalls[i]->unk_50;
                        if (work->unk_00 != 3 && work->unk_00 != 4 && work->unk_00 != 5) {
                            work->unk_00 = 6;
                        }
                    }
                }
            }
        }
        if (D_800FCD12_BumperBalls != 0 && func_800F9EE0_BumperBalls() == 1) {
            work = D_800FCD2C_BumperBalls[0]->unk_50;
            if (work->player == 0 && (work->unk_00 == 3 || work->unk_00 == 4 || work->unk_00 == 5)) {
                func_800601D4(0x28);
                D_800FCFF4_BumperBalls = 2;
                D_800FCFF2_BumperBalls = 10;
                for (i = 1; i < 4; i++) {
                    work = D_800FCD2C_BumperBalls[i]->unk_50;
                    if (work->unk_00 != 3 && work->unk_00 != 4 && work->unk_00 != 5) {
                        work->unk_00 = 6;
                    }
                }
            }
        }
        break;
    case 2:
        if (D_800FCD28_BumperBalls == NULL) {
            D_800FCD28_BumperBalls = omAddObj(4, 0, 0, -1, func_800F8E40_BumperBalls);
        }
        break;
    }
}

void func_800F6D98_BumperBalls(omObjData* arg0) {
    arg0->model[0] = LoadFormFile(0x310000, 0x20289);
    arg0->model[1] = LoadFormFile(0x380002, 0x48D);
    arg0->model[2] = LoadFormFile(0x380003, 0x48D);
    func_800FB2EC_BumperBalls();
    arg0->func_ptr = &func_800F6E10_BumperBalls;
}

void func_800F6E10_BumperBalls(omObjData* arg0) {
    func_800FC618_BumperBalls();
}

void func_800F6E2C_BumperBalls(omObjData* arg0) {
    LoadFormFile(0x310002, 0x69D);
    func_800F6EBC_BumperBalls(arg0, 0);
}

void func_800F6E68_BumperBalls(omObjData* arg0) {
    func_800F6EBC_BumperBalls(arg0, 1);
}

void func_800F6E84_BumperBalls(omObjData* arg0) {
    func_800F6EBC_BumperBalls(arg0, 2);
}

void func_800F6EA0_BumperBalls(omObjData* arg0) {
    func_800F6EBC_BumperBalls(arg0, 3);
}

void func_800F6EBC_BumperBalls(omObjData* object, s32 player) {
    BumperBallsWork* work;
    s32 i;
    s32 chrBase;
    u8 pos;
    s8 chr;
    f32 zero;

    if (D_800FCB7C_BumperBalls == 3) {
        for (i = 0; i < 4; i++) {
            if (D_800FCB78_BumperBalls[i] == 0) {
                pos = i;
                break;
            }
        }
    } else {
        do {
            pos = rand8() & 3;
        } while (D_800FCB78_BumperBalls[pos] != 0);
    }
    D_800FCB78_BumperBalls[pos] = 1;
    work = object->unk_50 = func_80023684(sizeof(BumperBallsWork), 0x7918);
    work->unk_00 = 0;
    work->player = player;
    work->unk_20 = 50.0f;
    work->unk_1C = 0.0f;
    zero = work->unk_1C;
    work->unk_30 = work->unk_34 = work->unk_38 = work->unk_24 = work->unk_2C = zero;
    work->unk_3C = 0;
    work->unk_42 = 0;
    work->unk_54 = NULL;
    work->unk_48 = work->unk_4C = work->unk_44 = work->unk_4A = work->unk_46 = 0;
    work->unk_50 = zero;
    work->unk_3E = 0;
    work->unk_58 = 1;
    work->unk_5A = 0;
    for (i = 0; i < 2; i++) {
        work->unk_40[i] = 0;
    }
    chr = GwPlayer[player].character;
    work->character = chr;
    chrBase = D_800C59AC[chr].unk_00;
    object->model[0] = LoadFormFile(chrBase | D_800C59A8[chr].file0, 0x20699);
    omSetTra(object, D_800FCB30_BumperBalls[pos].x, D_800FCB30_BumperBalls[pos].y, D_800FCB30_BumperBalls[pos].z);
    if ((u16) D_800C59A8[chr].index == 5) {
        work->unk_08 = 10.0f;
        omSetSca(object, 0.95f, 0.95f, 0.95f);
        omSetTra(object, D_800FCB30_BumperBalls[pos].x, D_800FCB30_BumperBalls[pos].y - 10.0f,
                 D_800FCB30_BumperBalls[pos].z);
    } else {
        work->unk_08 = 0.0f;
        omSetSca(object, 1.0f, 1.0f, 1.0f);
    }
    object->model[1] = func_800174F4(0x20, 0x689);
    func_800370D4(object->model[1]);
    func_80025830(object->model[1], 1.25f, 1.25f, 1.25f);
    func_80025798(object->model[1], object->trans.x, 120.0f, object->trans.z);
    object->model[5] = LoadFormFile(0x1A, 0x68D);
    for (i = 0; i < 2; i++) {
        if (player == 0 && i == 0) {
            object->model[6 + i] = LoadFormFile(0x19, 0x68D);
        } else {
            object->model[6 + i] = func_80023FC8(D_800FCD2C_BumperBalls[0]->model[6]);
        }
    }
    func_8001775C(object, 0, chrBase);
    func_8001775C(object, 1, chrBase | 1);
    func_8001775C(object, 2, chrBase | 3);
    if (rand8() & 1) {
        func_8001775C(object, 3, chrBase | 0xF);
    } else {
        func_8001775C(object, 3, chrBase | 0x38);
    }
    func_8001775C(object, 4, chrBase | 0x17);
    func_8001775C(object, 5, chrBase | 0x11);
    func_8001775C(object, 6, chrBase | 0x10);
    object->model[4] = func_8001E00C((void*) -1, 0x68D, 8);
    D_800ECDE0[object->model[4]].unk_02 = D_800FCD1C_BumperBalls;
    func_80025930(D_800ECDE0[object->model[4]].unk_00, 0x40000000, 0x40000000);
    func_8001E268(object->model[4], 4, 4);
    object->model[3] = func_8001E00C((void*) -1, 0x68D, 8);
    D_800ECDE0[object->model[3]].unk_02 = D_800FCD1A_BumperBalls;
    func_80025930(D_800ECDE0[object->model[3]].unk_00, 0x40000000, 0x40000000);
    func_8001E268(object->model[3], 4, 4);
    object->model[2] = LoadFormFile(0x310001, 0x20689);
    func_80027AC8(object->model[2], (u8*) "38mt001_DEF", (u8*) D_800FCB60_BumperBalls[chr]);
    func_80025AD4(object->model[2]);
    work->unk_0C = func_800B0CD8(-object->trans.x, -object->trans.z);
    if (work->unk_0C < 0.0f) {
        work->unk_0C += 360.0f;
    }
    work->unk_34 = work->unk_14 = work->unk_10 = work->unk_0C;
    omSetRot(object, 0.0f, work->unk_0C, 0.0f);
    func_800257E4(object->model[2], work->unk_30, work->unk_34, work->unk_38);
    func_80025798(object->model[2], object->trans.x, object->trans.y + -50.0f + work->unk_08,
                  object->trans.z);
    func_80025BB8(object->model[0], object->motion[0]);
    func_80025EB4(object->model[0], 2, 2);
    object->func_ptr = func_800F74E8_BumperBalls;
}

// float register allocation of the turn-step clamp and the port copy (masked ~6, one instruction short)
#ifdef NON_MATCHING
void func_800F74E8_BumperBalls(omObjData* object) {
    BumperBallsWork* work;
    s8 stickX;
    s8 stickY;
    s32 port;
    f32 diff;
    f32 speed;
    f32 height;
    f32 dx;
    f32 dz;

    work = object->unk_50;
    if (D_800FCFF4_BumperBalls != 1) {
        return;
    }
    port = GwPlayer[work->player].port;
    if (!(GwPlayer[work->player].flags & 1)) {
        stickX = ContStkX[port];
        stickY = ContStkY[port];
    } else {
        if (work->unk_42 == 0) {
            func_800F9F30_BumperBalls(object);
        }
        func_800FA510_BumperBalls(object, &stickX, &stickY);
    }
    if (stickX != 0 || stickY != 0) {
        diff = func_800B0CD8(stickX, -stickY);
        if (diff < 0.0f) {
            diff += 360.0f;
        }
        work->unk_14 = diff;
    }
    if (work->unk_0C != work->unk_14) {
        diff = work->unk_14 - work->unk_0C;
        if (diff < 0.0f) {
            diff += 360.0f;
        }
        if (diff < 180.0f) {
            work->unk_0C = (diff > 30.0f) ? work->unk_0C + 30.0f : diff + work->unk_0C;
        } else {
            f32 step;

            if (360.0f - diff > 30.0f) {
                step = 30.0f;
            } else {
                step = 360.0f - diff;
            }
            work->unk_0C = work->unk_0C - step;
        }
        if (work->unk_0C < 0.0f) {
            work->unk_0C += 360.0f;
        }
        if (work->unk_0C >= 360.0f) {
            work->unk_0C -= 360.0f;
        }
        omSetRot(object, object->rot.x, work->unk_0C, object->rot.z);
        work->unk_34 = work->unk_0C;
        func_800257E4(object->model[2], work->unk_30, work->unk_34, work->unk_38);
    }
    speed = func_800B1750(stickX * stickX + stickY * stickY) / 100.0f;
    work->unk_24 = func_800AEAC0(work->unk_0C) * speed + work->unk_24;
    work->unk_2C = func_800AEFD0(work->unk_0C) * speed + work->unk_2C;
    work->unk_24 *= 0.96f;
    if (fabs(work->unk_24) < 0.01f) {
        work->unk_24 = 0.0f;
    }
    work->unk_2C *= 0.96f;
    if (fabs(work->unk_2C) < 0.01f) {
        work->unk_2C = 0.0f;
    }
    height = func_800F9A7C_BumperBalls(object->trans.x, object->trans.y + -100.0f, object->trans.z);
    if (height == -10000.0f) {
        work->unk_00 = 3;
        work->unk_24 *= 1.2f;
        work->unk_2C *= 1.2f;
        if (func_800B1750(work->unk_24 * work->unk_24 + work->unk_2C * work->unk_2C) < 15.0f) {
            diff = func_800B0CD8(object->trans.x, object->trans.z);
            work->unk_24 = func_800AEAC0(diff) * 9.0f + work->unk_24;
            work->unk_2C = func_800AEFD0(diff) * 9.0f + work->unk_2C;
        }
        work->unk_28 = -10.0f;
        D_800FCD10_BumperBalls--;
        func_800258EC(object->model[1], 4, 4);
        func_80025C20(object->model[0], func_80025E48(object->motion[4]), 0, 0x1E, 2);
        func_80060618(0x45F, (s16) work->player);
        if (!(GwPlayer[work->player].flags & 1)) {
            D_800FCD1E_BumperBalls--;
        }
        object->func_ptr = func_800F7EC4_BumperBalls;
        return;
    }
    if (height < object->trans.y + -100.0f) {
        object->trans.y = object->trans.y - 10.0f;
    }
    if (object->trans.y + -100.0f < height) {
        object->trans.y = height - -100.0f;
    }
    if (func_800F95CC_BumperBalls(object) == 1) {
        work->unk_42 = 0;
    }
    if (work->unk_2C != 0.0f || work->unk_24 != 0.0f) {
        work->unk_30 = work->unk_30
            - (f32) (func_800B1750(work->unk_24 * work->unk_24 + work->unk_2C * work->unk_2C) / -50.0f
                     / 3.141592653589793 * 180.0);
        if (work->unk_30 >= 360.0f) {
            work->unk_30 -= 360.0f;
        }
        if (work->unk_30 < 0.0f) {
            work->unk_30 += 360.0f;
        }
    }
    if (fabs(work->unk_2C) + fabs(work->unk_24) > 8.0) {
        if (work->unk_00 != 2) {
            work->unk_00 = 2;
            func_80025C20(object->model[0], func_80025E48(object->motion[2]), 0, 0xA, 2);
            func_80025EB4(object->model[0], 6, 6);
        }
    } else if (fabs(work->unk_2C) + fabs(work->unk_24) > 1.0 || stickX != 0 || stickY != 0) {
        if (work->unk_00 != 1) {
            work->unk_00 = 1;
            func_80025C20(object->model[0], func_80025E48(object->motion[1]), 0, 0xA, 2);
            func_80025EB4(object->model[0], 6, 6);
        }
    } else if (work->unk_00 == 1 || work->unk_00 == 2) {
        work->unk_00 = 0;
        func_80025C20(object->model[0], func_80025E48(object->motion[0]), 0, 0x1E, 2);
    }
    if (work->unk_3C == 0) {
        if (fabs(work->unk_2C) + fabs(work->unk_24) > 8.0) {
            func_800F8384_BumperBalls(object);
            work->unk_3C = 3;
        }
    } else {
        work->unk_3C--;
    }
    if (fabs(work->unk_14 - work->unk_10) > 90.0) {
        dx = func_800AEAC0(work->unk_10) * 18.0f;
        dz = func_800AEFD0(work->unk_10) * 18.0f;
        func_800258EC(object->model[5], 4, 0);
        func_80025798(object->model[5], dx + object->trans.x, 120.0f, dz + object->trans.z);
        func_800257E4(object->model[5], object->rot.x, object->rot.y, 0.0f);
        if (D_800F2B7C[object->model[5]].unk_6C->unk_B8 != NULL) {
            D_800F2B7C[object->model[5]].unk_6C->unk_B8->unk_08 = 0;
        }
        func_80025CA8(object->model[5], 0.0f);
    }
    omSetTra(object, object->trans.x + work->unk_24, object->trans.y, object->trans.z + work->unk_2C);
    func_80025798(object->model[2], object->trans.x, object->trans.y + -50.0f + work->unk_08,
                  object->trans.z);
    func_800257E4(object->model[2], work->unk_30, work->unk_34, work->unk_38);
    func_80025798(object->model[1], object->trans.x, 120.0f, object->trans.z);
    work->unk_10 = work->unk_0C;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1E_BumperBalls/191700", func_800F74E8_BumperBalls);
#endif

void func_800F7EC4_BumperBalls(omObjData* object) {
    BumperBallsWork* work = object->unk_50;
    omObjData* obj;
    s16 model;

    if (D_800FCFF4_BumperBalls != 1) {
        return;
    }
    object->trans.y += work->unk_28;
    work->unk_28 = work->unk_28 - (fabs(work->unk_28 / 100.0f) + 5.0);
    omSetTra(object, object->trans.x + work->unk_24, object->trans.y, object->trans.z + work->unk_2C);
    func_80025798(object->model[2], object->trans.x, object->trans.y + -50.0f + work->unk_08,
                  object->trans.z);
    func_80025798(object->model[1], object->trans.x, 120.0f, object->trans.z);
    func_800257E4(object->model[2], work->unk_30, work->unk_34, work->unk_38);
    if (func_800F9B70_BumperBalls(object) == 1) {
        work->unk_28 = -work->unk_28;
        work->unk_24 *= 1.1f;
        work->unk_2C *= 1.1f;
    }
    if (object->trans.y < -20.0f && work->unk_3E == 0) {
        work->unk_3E = 1;
        model = D_800ECDE0[object->model[4]].unk_00;
        func_80025798(model, object->trans.x, 0.0f, object->trans.z + 80.0f);
        func_80025830(model, 5.0f, 5.0f, 5.0f);
        func_800258EC(model, 4, 0);
        func_80060F04(work->player, 0x14, 0, 0x14);
    }
    if (object->trans.y < -80.0f) {
        omSetTra(object, object->trans.x, -80.0f, object->trans.z);
        model = D_800ECDE0[object->model[3]].unk_00;
        func_80025798(model, object->trans.x, -60.0f, object->trans.z + 160.0f);
        func_80025830(model, 10.0f, 10.0f, 10.0f);
        func_800258EC(model, 4, 0);
        obj = omAddObj(0x14, 1, 0, -1, func_800F8304_BumperBalls);
        obj->model[0] = object->model[2];
        omSetTra(obj, object->trans.x, object->trans.y + -50.0f + work->unk_08, object->trans.z);
        omSetRot(obj, work->unk_30, work->unk_34, work->unk_30);
        work->unk_00 = 4;
        work->unk_50 = 0.0f;
        PlaySound(0x2A8);
        object->func_ptr = func_800F821C_BumperBalls;
    }
}

void func_800F821C_BumperBalls(omObjData* arg0) {
    BumperBallsWork* temp_s1 = arg0->unk_50;
    s32 temp_v1 = arg0->unk_10;

    if (temp_v1 != 0) {
        arg0->unk_10 = 0;
        if (temp_v1 == 1) {
            temp_s1->unk_00 = 5;
            func_80025C20(arg0->model[0], func_80025E48(arg0->motion[5]), 0, 15, 0);
        }
    }
    if (temp_s1->unk_00 != 5) {
        omSetTra(arg0, arg0->trans.x, (2.0f * func_800AEAC0(temp_s1->unk_50)) + arg0->trans.y, arg0->trans.z);
        temp_s1->unk_50 = temp_s1->unk_50 + 8.0f;

        if (temp_s1->unk_50 >= 360.0f) {
            temp_s1->unk_50 = temp_s1->unk_50 - 360.0f;
        }
    }
}

void func_800F8304_BumperBalls(omObjData* object) {
    omSetTra(object, object->trans.x, object->trans.y - 20.0f, object->trans.z);
    if (object->trans.y < -3000.0f) {
        func_800258EC(object->model[0], 4, 4);
        omDelObj(object);
    }
}

void func_800F8384_BumperBalls(omObjData* object) {
    BumperBallsWork* work = object->unk_50;
    omObjData* obj;
    s32 i;

    for (i = 0; i < 2; i++) {
        if (work->unk_40[i] == 0) {
            break;
        }
    }
    if (i == 2) {
        return;
    }
    work->unk_40[i] = 1;
    obj = omAddObj(0x28, 0, 0, -1, func_800F84AC_BumperBalls);
    obj->work[0] = object->model[6 + i];
    obj->work[1] = work->player;
    obj->work[2] = i;
    func_80025798(obj->work[0], object->trans.x, 120.0f, object->trans.z);
    func_800257E4(obj->work[0], object->rot.x, object->rot.y, 0.0f);
    func_800258EC(obj->work[0], 4, 0);
    if (D_800F2B7C[obj->work[0]].unk_6C->unk_B8 != NULL) {
        D_800F2B7C[obj->work[0]].unk_6C->unk_B8->unk_08 = 0;
    }
    func_80025CA8(obj->work[0], 0.0f);
}

void func_800F84AC_BumperBalls(omObjData* object) {
    f32 time = func_80025D18(object->work[0]);

    if (func_80025D40(object->work[0]) <= time) {
        ((BumperBallsWork*) D_800FCD2C_BumperBalls[object->work[1]]->unk_50)->unk_40[object->work[2]] = 0;
        func_800258EC(object->work[0], 4, 4);
        omDelObj(object);
    }
}

void func_800F8538_BumperBalls(omObjData* arg0) {
    func_800F85A8_BumperBalls(arg0, 0);
}

void func_800F8554_BumperBalls(omObjData* arg0) {
    func_800F85A8_BumperBalls(arg0, 1);
}

void func_800F8570_BumperBalls(omObjData* arg0) {
    func_800F85A8_BumperBalls(arg0, 2);
}

void func_800F858C_BumperBalls(omObjData* arg0) {
    func_800F85A8_BumperBalls(arg0, 3);
}

void func_800F85A8_BumperBalls(omObjData* object, s32 player) {
    BumperBallsBoatWork* work;
    s32 i;

    omSetStatBit(object, 0xA0);
    work = object->unk_50 = func_80023684(sizeof(BumperBallsBoatWork), 0x7918);
    work->player = player;
    work->state = 0;
    work->model = 1;
    work->model2 = 2;
    work->angle = 0.0f;
    work->speed = 10.0f;
    object->model[0] = -1;
    if (player == 0) {
        object->model[1] = LoadFormFile(0x310003, 0x69D);
        object->model[2] = LoadFormFile(0x310004, 0x69D);
        object->model[3] = LoadFormFile(0x310005, 0x69D);
        object->model[4] = LoadFormFile(0x310006, 0x69D);
        object->model[5] = LoadFormFile(0x310007, 0x69D);
        object->model[6] = LoadFormFile(0x310008, 0x69D);
    } else {
        object->model[1] = func_80023FC8(D_800FCD30_BumperBalls[0]->model[1]);
        object->model[2] = func_80023FC8(D_800FCD30_BumperBalls[0]->model[2]);
        object->model[3] = func_80023FC8(D_800FCD30_BumperBalls[0]->model[3]);
        object->model[4] = func_80023FC8(D_800FCD30_BumperBalls[0]->model[4]);
        object->model[5] = func_80023FC8(D_800FCD30_BumperBalls[0]->model[5]);
        object->model[6] = func_80023FC8(D_800FCD30_BumperBalls[0]->model[6]);
    }
    for (i = 1; i < 7; i++) {
        func_80025830(object->model[i], 0.7f, 0.7f, 0.7f);
    }
    func_80026040(object->model[1]);
    func_80026040(object->model[3]);
    func_80026040(object->model[5]);
    object->func_ptr = func_800F87F4_BumperBalls;
}

// delay-slot scheduling around the ball omSetTra calls (8 instructions long; logic-equivalent)
#ifdef NON_MATCHING
void func_800F87F4_BumperBalls(omObjData* object) {
    BumperBallsBoatWork* work = object->unk_50;
    omObjData* ball = D_800FCD2C_BumperBalls[work->player];
    BumperBallsWork* ballWork = ball->unk_50;
    f32 x;

    if (ballWork->unk_00 != 4 && ballWork->unk_00 != 5) {
        return;
    }
    if (func_8005FD5C() + D_800F64F8 != 0) {
        func_80026174(object->model[work->model], object->model[work->model2], func_800AEAC0(work->angle));
        return;
    }
    switch (work->state) {
    case 0:
        work->state = 1;
        if (ball->trans.x < 0.0f) {
            work->side = 1;
            work->dx = 10.0f;
            x = -1200.0f;
            if (ball->trans.x <= -1200.0f) {
                x = -1360.0f;
            }
        } else {
            work->side = 0;
            work->dx = -10.0f;
            x = 1200.0f;
            if (ball->trans.x >= 1200.0f) {
                x = 1360.0f;
            }
        }
        omSetTra(object, x, -150.0f, ball->trans.z);
        work->endX = x;
        func_800258EC(object->model[work->model], 4, 0);
        break;
    case 1:
        object->trans.x = func_800AEAC0(work->angle) * 4.0f + work->dx + object->trans.x;
        if (func_800B1750((ball->trans.x - object->trans.x) * (ball->trans.x - object->trans.x)
                          + (ball->trans.z - object->trans.z) * (ball->trans.z - object->trans.z)) <= 80.0f) {
            work->state = 3;
            if (work->side == 1) {
                work->model2 = 3;
            } else {
                work->model2 = 5;
            }
            work->angle = 0.0f;
            work->speed = 5.0f;
            func_8005DC18(ball, 1);
            work->dy = (ball->trans.y - object->trans.y) / (90.0f / work->speed);
        }
        break;
    case 3:
        omSetTra(ball, (work->side == 1) ? object->trans.x + 80.0f : object->trans.x - 80.0f,
                 object->trans.y + work->dy, object->trans.z);
        if (work->angle + work->speed >= 90.0f) {
            work->state = 2;
            func_800258EC(object->model[work->model], 4, 4);
            if (work->side == 1) {
                work->model = 3;
                work->model2 = 4;
            } else {
                work->model = 5;
                work->model2 = 6;
            }
            work->angle = 0.0f;
            work->speed = 15.0f;
            object->trans.y += 20.0f;
            func_800258EC(object->model[work->model], 4, 0);
        }
        break;
    case 2:
        work->state = 4;
        omSetTra(ball, (work->side == 1) ? object->trans.x + 80.0f : object->trans.x - 80.0f,
                 object->trans.y, object->trans.z);
        break;
    case 4:
        object->trans.x = object->trans.x - (func_800AEAC0(work->angle) * 4.0f + work->dx);
        omSetTra(ball, (work->side == 1) ? object->trans.x + 80.0f : object->trans.x - 80.0f,
                 object->trans.y, object->trans.z);
        if (work->side == 1) {
            if (object->trans.x < work->endX) {
                goto arrived;
            }
        } else if (object->trans.x > work->endX) {
        arrived:
            func_800258EC(object->model[work->model], 4, 4);
            work->state = 5;
        }
        break;
    case 5:
        return;
    }
    func_80026174(object->model[work->model], object->model[work->model2], func_800AEAC0(work->angle));
    func_80025798(object->model[work->model], object->trans.x, object->trans.y, object->trans.z);
    work->angle += work->speed;
    if (work->angle >= 360.0f) {
        work->angle -= 360.0f;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1E_BumperBalls/191700", func_800F87F4_BumperBalls);
#endif

void func_800F8D68_BumperBalls(omObjData* arg0) {
    switch (D_800FCFF0_BumperBalls) {
    case 0:
        D_800FCFF0_BumperBalls = 1;
        break;
    case 1:
        if (func_80072718() == 0) {
            D_800FCFF0_BumperBalls = 2;
            GMesCreate(0);
            func_80060128(0x1B);
        }
        break;
    case 2:
        if (GMesStatAllGet() == 0) {
            D_800FCFF4_BumperBalls = 1;
            omDelObj(arg0);
            D_800FCD24_BumperBalls = NULL;
            GMesCreate(8, D_800FCD16_BumperBalls, 0xA0, 0x20);
        }
        break;
    }
}

void func_800F8E40_BumperBalls(omObjData* arg0) {
    BumperBallsWork* work;
    s32 i;

    switch (D_800FCFF2_BumperBalls) {
    case 10:
        if (D_800FCD10_BumperBalls == 1) {
            for (i = 0; i < 4; i++) {
                work = D_800FCD2C_BumperBalls[i]->unk_50;
                if (work->unk_00 == 6) {
                    D_800FCD02_BumperBalls = i;
                }
            }
            GwPlayer[D_800FCD02_BumperBalls].coins_mg += 10;
            GMesCreate(2);
            if (D_800FCD12_BumperBalls == 0) {
                D_800FCFF2_BumperBalls = 0;
            } else {
                D_800FCFF2_BumperBalls = 12;
                func_80025C20(D_800FCD2C_BumperBalls[D_800FCD02_BumperBalls]->model[0],
                              func_80025E48(D_800FCD2C_BumperBalls[D_800FCD02_BumperBalls]->motion[0]), 0, 0x14, 2);
            }
        } else {
            if (D_800FCD12_BumperBalls == 0) {
                GMesCreate(0x11);
                D_800FCFF2_BumperBalls = 11;
            } else {
                GMesCreate(2);
                D_800FCFF2_BumperBalls = 12;
            }
            for (i = 0; i < 4; i++) {
                omObjData* ball = D_800FCD2C_BumperBalls[i];

                work = ball->unk_50;
                if (work->unk_00 == 6) {
                    func_80025C20(D_800FCD2C_BumperBalls[i]->model[0], func_80025E48(ball->motion[0]), 0, 0x14, 2);
                }
            }
        }
        func_800790C0();
        break;
    case 0:
        for (i = 0; i < 4; i++) {
            omObjData* ball = D_800FCD2C_BumperBalls[i];

            work = ball->unk_50;
            if (work->unk_00 == 6) {
                D_800FCD08_BumperBalls = ball;
            }
        }
        work = D_800FCD08_BumperBalls->unk_50;
        if (work->unk_0C > 180.0f) {
            work->unk_0C -= 360.0f;
        }
        if (fabs(work->unk_0C) > 7.0) {
            if (work->unk_0C < 0.0f) {
                D_800FCD04_BumperBalls = 7.0f;
            } else {
                D_800FCD04_BumperBalls = -7.0f;
            }
        } else {
            D_800FCD04_BumperBalls = work->unk_0C;
        }
        D_800FCFF2_BumperBalls = 1;
        func_80025C20(D_800FCD08_BumperBalls->model[0], func_80025E48(D_800FCD08_BumperBalls->motion[1]), 0, 0xA, 2);
        func_80025EB4(D_800FCD08_BumperBalls->model[0], 6, 6);
        break;
    case 1:
        work = D_800FCD08_BumperBalls->unk_50;
        work->unk_0C += D_800FCD04_BumperBalls;
        if (D_800FCD04_BumperBalls < 0.0f) {
            if (work->unk_0C <= 0.0f) {
                work->unk_0C = 0.0f;
                func_80025C20(D_800FCD08_BumperBalls->model[0], func_80025E48(D_800FCD08_BumperBalls->motion[0]), 0, 0x14, 2);
                D_800FCFF2_BumperBalls = 11;
            }
        } else if (work->unk_0C >= 0.0f) {
            work->unk_0C = 0.0f;
            func_80025C20(D_800FCD08_BumperBalls->model[0], func_80025E48(D_800FCD08_BumperBalls->motion[0]), 0, 0x14, 2);
            D_800FCFF2_BumperBalls = 11;
        }
        omSetRot(D_800FCD08_BumperBalls, 0.0f, work->unk_0C, 0.0f);
        break;
    case 11:
        if (GMesStatAllGet() & 2) {
            D_800FCFF2_BumperBalls = 2;
        }
        break;
    case 2:
        for (i = 0; i < 4; i++) {
            omObjData* ball = D_800FCD2C_BumperBalls[i];

            work = ball->unk_50;
            if (work->unk_00 == 6) {
                if (D_800FCD10_BumperBalls == 1) {
                    func_80025C20(D_800FCD2C_BumperBalls[i]->model[0], func_80025E48(ball->motion[3]), 0, 0x1E, 0);
                    D_800FCD02_BumperBalls = work->player;
                } else {
                    func_80025C20(D_800FCD2C_BumperBalls[i]->model[0],
                                  func_80025E48(D_800FCD2C_BumperBalls[i]->motion[6]), 0, 0x1E, 0);
                }
                D_800FCB80_BumperBalls[D_800FCB7E_BumperBalls++] = work->player;
            }
        }
        if (D_800FCD10_BumperBalls == 1) {
            func_80060128(0x32);
            D_800FCFF2_BumperBalls = 5;
            D_800FCD0C_BumperBalls = 0x15;
        } else {
            func_80060128(0x35);
            D_800FCD0C_BumperBalls = 0x5A;
            D_800FCFF2_BumperBalls = 8;
        }
        D_800FCD00_BumperBalls = 0;
        break;
    case 4:
        if (D_800FCD12_BumperBalls == 0) {
            GMesCreate(0x11);
            D_800FCFF2_BumperBalls = 11;
        } else {
            GMesCreate(2);
            D_800FCFF2_BumperBalls = 12;
        }
        func_800790C0();
        break;
    case 5:
        if (--D_800FCD0C_BumperBalls == 0) {
            GMesCreate(4, GwPlayer[D_800FCD02_BumperBalls].character);
            D_800FCD0C_BumperBalls = 0x54;
            D_800FCFF2_BumperBalls = 8;
            func_80060618(0x451, D_800FCD02_BumperBalls);
        }
        break;
    case 6:
        if (GMesStatAllGet() & 2) {
            D_800FCFF2_BumperBalls = 7;
        }
        break;
    case 8:
        if (--D_800FCD0C_BumperBalls == 0) {
            func_800726AC(0, 0x14);
            D_800FCFF2_BumperBalls = 9;
        }
        break;
    case 9:
        if (func_80072718() == 0) {
            D_800FCBC0_BumperBalls = 1;
        }
        break;
    case 12:
        if (GMesWait() != 1) {
            D_800FCD0C_BumperBalls = 1;
            D_800FCFF2_BumperBalls = 8;
        }
        break;
    case 7:
        D_800FCFF2_BumperBalls = 8;
        break;
    }
}

void func_800F9588_BumperBalls(void) {
    if (D_800FCBC0_BumperBalls != 0 || D_800F5144 != 0) {
        func_800FB2D0_BumperBalls(0x83);
        func_800601D4(0x28);
    }
}

u16 func_800F95CC_BumperBalls(omObjData* object) {
    BumperBallsWork* work = object->unk_50;
    BumperBallsWork* otherWork;
    omObjData* other;
    f32 x;
    f32 z;
    f32 dist;
    f32 otherSpeed;
    f32 len;
    f32 nx;
    f32 nz;
    s32 i;

    x = object->trans.x + work->unk_24;
    z = object->trans.z + work->unk_2C;
    for (i = 0; i < 4; i++) {
        other = D_800FCD2C_BumperBalls[i];
        if (other == object) {
            continue;
        }
        otherWork = other->unk_50;
        if (otherWork->unk_00 != 1 && otherWork->unk_00 != 2) {
            continue;
        }
        dist = func_800B1750((other->trans.x - x) * (other->trans.x - x) + (other->trans.z - z) * (other->trans.z - z));
        if (!(dist <= func_800B1750((work->unk_20 + otherWork->unk_20) * (work->unk_20 + otherWork->unk_20)))) {
            continue;
        }
        dist = func_800B1750(work->unk_24 * work->unk_24 + work->unk_2C * work->unk_2C);
        otherSpeed = func_800B1750(otherWork->unk_24 * otherWork->unk_24 + otherWork->unk_2C * otherWork->unk_2C);
        if (otherSpeed <= dist) {
            func_800F98CC_BumperBalls(dist, work->player);
        } else {
            func_800F98CC_BumperBalls(otherSpeed, otherWork->player);
        }
        func_80060F04(work->player, 0xA, 0, 0xA);
        func_80060F04(otherWork->player, 0xA, 0, 0xA);
        x = otherWork->unk_24;
        z = otherWork->unk_2C;
        otherWork->unk_24 = work->unk_24 * 1.1f - x * 0.4f;
        otherWork->unk_2C = work->unk_2C * 1.1f - otherWork->unk_2C * 0.4f;
        work->unk_24 = x * 1.1f - work->unk_24 * 0.4f;
        work->unk_2C = z * 1.1f - work->unk_2C * 0.4f;
        if (D_800FCD1E_BumperBalls == 0) {
            otherWork->unk_24 *= 1.01f;
            otherWork->unk_2C *= 1.01f;
        }
        len = func_800B1750(otherWork->unk_24 * otherWork->unk_24 + otherWork->unk_2C * otherWork->unk_2C);
        if (len > 22.0f) {
            nx = otherWork->unk_24 / len;
            nz = otherWork->unk_2C / len;
            otherWork->unk_24 = nx * 22.0f;
            otherWork->unk_2C = nz * 22.0f;
        }
        len = func_800B1750(work->unk_24 * work->unk_24 + work->unk_2C * work->unk_2C);
        if (len > 22.0f) {
            nx = work->unk_24 / len;
            nz = work->unk_2C / len;
            work->unk_24 = nx * 22.0f;
            work->unk_2C = nz * 22.0f;
        }
        return 1;
    }
    return 0;
}

void func_800F98CC_BumperBalls(f32 speed, u16 player) {
    s16 sound;
    s16 pitch;
    s16 volume;

    if (speed < 8.0f) {
        sound = func_80060540(0x2A7, player);
        if (speed < 4.0f) {
            pitch = speed * -25.0f;
        } else {
            pitch = (speed - 4.0f) * 75.0f;
        }
        if (pitch > 300) {
            pitch = 300;
        }
    } else {
        sound = func_80060540(0x2A6, player);
        if (speed < 12.0f) {
            pitch = (speed - 8.0f) * -25.0f;
        } else {
            pitch = (speed - 12.0f) * 150.0f;
        }
        if (pitch > 600) {
            pitch = 600;
        }
    }
    volume = speed * 1.9375f;
    if (volume > 31) {
        volume = 31;
    }
    func_80060440(sound, pitch);
    func_8006035C(sound, volume + 0x60);
}

f32 func_800F9A7C_BumperBalls(f32 x, f32 y, f32 z) {
    BumperBallsHitProbe probe;
    void* verts;
    u16* tri;
    f32 best;
    f32 h;
    s16 model;

    best = -10000.0f;
    probe.x = x;
    probe.y = y;
    probe.z = z;
    model = D_800FCD20_BumperBalls->model[0];
    verts = D_800F2B7C[model].unk_6C->unk_78;
    func_8002AE24(model, &D_800EDEC0, func_800F9CA8_BumperBalls, &probe);
    goto next;
    do {
        h = func_80029764(x, y, z, verts, tri);
        if (best < h) {
            best = h;
        }
    next:
        tri = func_8002B3A8(&D_800EDEC0);
    } while (tri != NULL);
    return best;
}

u16 func_800F9B70_BumperBalls(omObjData* object) {
    omObjData* other;
    BumperBallsWork* otherWork;
    f32 top;
    f32 dx;
    f32 dz;
    f32 dist;
    s32 i;

    for (i = 0; i < 4; i++) {
        other = D_800FCD2C_BumperBalls[i];
        if (object == other) {
            continue;
        }
        otherWork = other->unk_50;
        if (otherWork->unk_00 != 4 && otherWork->unk_00 != 5) {
            continue;
        }
        dx = other->trans.x;
        top = other->trans.y;
        dz = other->trans.z;
        dx -= object->trans.x;
        dx *= dx;
        dz -= object->trans.z;
        dist = func_800B1750(dx + dz * dz);
        if (dist <= func_800B1750(10000.0f)) {
            if (top + 50.0f >= object->trans.y + -50.0f) {
                object->trans.y = object->trans.y + fabs(top + 50.0f - (object->trans.y + -50.0f));
                return 1;
            }
        }
    }
    return 0;
}

s32 func_800F9CA8_BumperBalls(s32 arg0, u16* polygon, BumperBallsColVtx* vertices, BumperBallsHitProbe* probe) {
    return func_800F9CC8_BumperBalls(probe, polygon - 1, vertices);
}

s32 func_800F9CC8_BumperBalls(BumperBallsHitProbe* probe, u16* poly, BumperBallsColVtx* verts) {
    f32 x = probe->x;
    f32 z = probe->z;
    s32 cnt = (poly[0] >> 14) + 2;
    s32 i;
    s32 j;

    poly++;
    if (func_800296FC(x, z, &verts[(s16) poly[0]], &verts[(s16) poly[1]]) > 0.0f) {
        for (i = 1; i < cnt; i++) {
            j = (i + 1) % cnt;
            if (func_800296FC(x, z, &verts[(s16) poly[i]], &verts[(s16) poly[j]]) < 0.0f) {
                return 0;
            }
        }
    } else {
        for (i = 1; i < cnt; i++) {
            j = (i + 1) % cnt;
            if (func_800296FC(x, z, &verts[(s16) poly[i]], &verts[(s16) poly[j]]) > 0.0f) {
                return 0;
            }
        }
    }
    return 1;
}

u16 func_800F9EE0_BumperBalls(void) {
    u16 phi_a0_2 = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (((BumperBallsWork*) D_800FCD2C_BumperBalls[i]->unk_50)->unk_00 != 3) {
            phi_a0_2++;
        }
    }

    return (phi_a0_2 < 4) ^ 1;
}

// register allocation: work/table in s0/s1 swapped (raw 44, masked 0); declaration order, a
// separate work assignment and the unk_58 block order tried
#ifdef NON_MATCHING
void func_800F9F30_BumperBalls(omObjData* object) {
    u16* table;
    BumperBallsWork* work = object->unk_50;
    u16 candidates[4];
    s32 bias;
    u16 count;
    s32 i;

    work->unk_46 = 0;
    if (D_800FCD1E_BumperBalls != 0) {
        switch (GwPlayer[work->player].cpu_difficulty) {
        case 0:
            table = D_800FCB88_BumperBalls;
            bias = 5;
            break;
        case 1:
            table = D_800FCB88_BumperBalls;
            bias = 4;
            break;
        case 2:
            table = D_800FCBA8_BumperBalls;
            bias = 3;
            break;
        case 3:
            table = D_800FCBA8_BumperBalls;
            bias = 2;
            break;
        }
    } else {
        switch (GwPlayer[work->player].cpu_difficulty) {
        case 0:
            table = D_800FCB98_BumperBalls;
            bias = 4;
            break;
        case 1:
            table = D_800FCB98_BumperBalls;
            bias = 3;
            break;
        case 2:
            table = D_800FCBA8_BumperBalls;
            bias = 2;
            break;
        case 3:
            table = D_800FCBA8_BumperBalls;
            bias = 2;
            break;
        }
    }
    if (work->unk_58 == 1) {
        work->unk_58 = 0;
        table = D_800FCBA8_BumperBalls;
    }
    work->unk_42 = table[rand8() & 7];
    while (1) {
        switch (work->unk_42) {
        case 1:
            work->unk_48 = ((u8) (rand8() % 180) + 180) >> 1;
            work->unk_44 = bias;
            work->unk_4A = 1;
            work->unk_5A = 0;
            return;
        case 2:
            if (work->unk_5A < 3) {
                work->unk_48 = ((u8) (rand8() % 21) + 20) >> 1;
                work->unk_5A++;
                return;
            }
            work->unk_42 = 1;
            continue;
        case 3:
            count = 0;
            work->unk_48 = ((u8) (rand8() % 180) + 180) >> 1;
            for (i = 0; i < 4; i++) {
                omObjData* other = D_800FCD2C_BumperBalls[i];
                BumperBallsWork* otherWork;

                if (object == other) {
                    continue;
                }
                otherWork = other->unk_50;
                if (otherWork->unk_00 == 3 || otherWork->unk_00 == 4) {
                    continue;
                }
                if (otherWork->unk_00 == 5 || otherWork->unk_00 == 6) {
                    continue;
                }
                candidates[count++] = i;
            }
            work->unk_5A = 0;
            if (count == 0) {
                work->unk_42 = 2;
                continue;
            }
            work->unk_54 = D_800FCD2C_BumperBalls[candidates[rand8() % count]];
            work->unk_44 = bias;
            work->unk_4A = 1;
            return;
        case 4:
            work->unk_48 = ((u8) (rand8() % 180) + 60) >> 1;
            work->unk_5A = 0;
            return;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1E_BumperBalls/191700", func_800F9F30_BumperBalls);
#endif

u16 func_800FA36C_BumperBalls(omObjData* arg0) {
    BumperBallsWork* temp_v1 = arg0->unk_50;

    if (temp_v1->unk_00 == 3 || temp_v1->unk_00 == 4 || temp_v1->unk_00 == 5) {
        return 1;
    } else {
        return 0;
    }
}

u16 func_800FA3A0_BumperBalls(omObjData* object, f32 scale) {
    BumperBallsWork* work = object->unk_50;
    f32 t;
    f32 x;
    f32 z;

    switch (GwPlayer[work->player].cpu_difficulty) {
    case 0:
        scale *= 0.65f;
        break;
    case 1:
        scale *= 0.8f;
        break;
    case 2:
        scale *= 0.95f;
        break;
    }
    if (D_800FCD1E_BumperBalls == 0) {
        scale *= 0.8f;
    }
    t = func_800B1750(work->unk_24 * work->unk_24 + work->unk_2C * work->unk_2C) * scale;
    x = t * work->unk_24 + object->trans.x;
    z = t * work->unk_2C + object->trans.z;
    if (func_800F9A7C_BumperBalls(x, object->trans.y + -100.0f, z) == -10000.0f) {
        return 0;
    }
    return 1;
}

void func_800FA510_BumperBalls(omObjData* arg0, s8* stickX, s8* stickY) {
    switch (((BumperBallsWork*) arg0->unk_50)->unk_42) {
    case 1:
        func_800FA5A4_BumperBalls(arg0, stickX, stickY);
        return;
    case 2:
        func_800FA950_BumperBalls(arg0, stickX, stickY);
        return;
    case 3:
        func_800FAB54_BumperBalls(arg0, stickX, stickY);
        return;
    case 4:
        func_800FAE60_BumperBalls(arg0, stickX, stickY);
        return;
    }
}

/* Retreat from the edge: true when the ball would leave the island (func_800FA3A0 is 0). */
#define BB_FLEE_EDGE(object, work, stickX, stickY)                                                  \
    {                                                                                                \
        work->unk_50 = func_800B0CD8(-object->trans.z, -object->trans.x) - 45.0f;                  \
        work->unk_50 = (u8) (rand8() % 90) + work->unk_50;                                           \
        *stickX = func_800AEFD0(work->unk_50) * 80.0f;                                               \
        *stickY = -func_800AEAC0(work->unk_50) * 80.0f;                                              \
        work->unk_46 = (u8) (rand8() % 15) + 15;                                                     \
    }

void func_800FA5A4_BumperBalls(omObjData* object, s8* stickX, s8* stickY) {
    BumperBallsWork* work;
    omObjData* other;
    omObjData* target;
    BumperBallsWork* otherWork;
    f32 best;
    f32 dist;
    s32 i;

    best = -100000.0f;
    work = object->unk_50;
    if (work->unk_46 != 0) {
        *stickX = func_800AEFD0(work->unk_50) * 80.0f;
        *stickY = -func_800AEAC0(work->unk_50) * 80.0f;
        work->unk_46--;
        return;
    }
    if (--work->unk_48 == 0) {
        work->unk_42 = 0;
        func_800F9F30_BumperBalls(object);
        return;
    }
    for (i = 0; i < 4; i++) {
        other = D_800FCD2C_BumperBalls[i];
        if (other == object) {
            continue;
        }
        otherWork = other->unk_50;
        if (otherWork->unk_00 == 3 || otherWork->unk_00 == 4) {
            continue;
        }
        if (otherWork->unk_00 == 5) {
            continue;
        }
        dist = func_800B1750(other->trans.x * other->trans.x + other->trans.z * other->trans.z);
        if (best < dist) {
            target = other;
            best = dist;
        }
    }
    if (best == -100000.0f) {
        *stickX = *stickY = 0;
        return;
    }
    if (--work->unk_4A == 0) {
        work->unk_50 = func_800B0CD8(target->trans.z - object->trans.z, target->trans.x - object->trans.x);
        if (work->unk_44 < 2) {
            work->unk_4A = 1;
        } else {
            work->unk_4A = rand8() % work->unk_44 + 1;
        }
    }
    if (func_800FA3A0_BumperBalls(object, 1.05f) == 0) {
        BB_FLEE_EDGE(object, work, stickX, stickY);
        return;
    }
    *stickX = func_800AEFD0(work->unk_50) * 80.0f;
    *stickY = -func_800AEAC0(work->unk_50) * 80.0f;
}

void func_800FA950_BumperBalls(omObjData* object, s8* stickX, s8* stickY) {
    BumperBallsWork* work = object->unk_50;

    if (work->unk_46 != 0) {
        *stickX = func_800AEFD0(work->unk_50) * 80.0f;
        *stickY = -func_800AEAC0(work->unk_50) * 80.0f;
        if (--work->unk_46 == 0) {
            work->unk_42 = 0;
        }
        return;
    }
    if (--work->unk_48 == 0) {
        work->unk_42 = 0;
        func_800F9F30_BumperBalls(object);
        return;
    }
    if (func_800FA3A0_BumperBalls(object, 1.2f) == 0) {
        BB_FLEE_EDGE(object, work, stickX, stickY);
    } else {
        *stickX = *stickY = 0;
    }
}

void func_800FAB54_BumperBalls(omObjData* object, s8* stickX, s8* stickY) {
    BumperBallsWork* work = object->unk_50;
    omObjData* target;

    if (work->unk_46 != 0) {
        *stickX = func_800AEFD0(work->unk_50) * 80.0f;
        *stickY = -func_800AEAC0(work->unk_50) * 80.0f;
        work->unk_46--;
        return;
    }
    if (--work->unk_48 == 0) {
        work->unk_42 = 0;
        func_800F9F30_BumperBalls(object);
        return;
    }
    if (func_800FA36C_BumperBalls(work->unk_54) == 1) {
        func_800F9F30_BumperBalls(object);
        func_800FA510_BumperBalls(object, stickX, stickY);
        return;
    }
    if (--work->unk_4A == 0) {
        target = work->unk_54;
        work->unk_50 = func_800B0CD8(target->trans.z - object->trans.z, target->trans.x - object->trans.x);
        if (work->unk_44 < 2) {
            work->unk_4A = 1;
        } else {
            work->unk_4A = rand8() % work->unk_44 + 1;
        }
    }
    if (func_800FA3A0_BumperBalls(object, 1.1f) == 0) {
        BB_FLEE_EDGE(object, work, stickX, stickY);
        return;
    }
    *stickX = func_800AEFD0(work->unk_50) * 80.0f;
    *stickY = -func_800AEAC0(work->unk_50) * 80.0f;
}

void func_800FAE60_BumperBalls(omObjData* object, s8* stickX, s8* stickY) {
    BumperBallsWork* work = object->unk_50;
    omObjData* other;
    f32 angles[4];
    u16 count;
    u16 i;
    u16 j;

    if (work->unk_46 != 0) {
        *stickX = func_800AEFD0(work->unk_50) * 80.0f;
        *stickY = -func_800AEAC0(work->unk_50) * 80.0f;
        work->unk_46--;
        return;
    }
    if (--work->unk_48 == 0) {
        work->unk_42 = 0;
        func_800F9F30_BumperBalls(object);
        return;
    }
    count = 0;
    for (i = 0; i < 4; i++) {
        other = D_800FCD2C_BumperBalls[i];
        if (object != other) {
            u16 state = ((BumperBallsWork*) other->unk_50)->unk_00;

            if (state == 1 || state == 2) {
                angles[count++] = func_800B0CD8(other->trans.z - object->trans.z, other->trans.x - object->trans.x);
            }
        }
    }
    if (count == 0) {
        work->unk_42 = 0;
        return;
    }
    j = 0;
    do {
        for (i = 0; i < count; i++) {
            if (fabsf(angles[i] - work->unk_50) <= 20.0f) {
                break;
            }
        }
        if (i == count) {
            break;
        }
        work->unk_50 += 20.0f;
    } while (++j < 18);
    if (func_800FA3A0_BumperBalls(object, 1.3f) == 0) {
        BB_FLEE_EDGE(object, work, stickX, stickY);
        return;
    }
    *stickX = func_800AEFD0(work->unk_50) * 80.0f;
    *stickY = -func_800AEAC0(work->unk_50) * 80.0f;
}
