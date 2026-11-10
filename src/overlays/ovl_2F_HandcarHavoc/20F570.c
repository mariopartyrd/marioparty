#include "HandcarHavoc.h"

/* .data (0x800FF3A0..0x800FF450) */
s32 D_800FF3A0_HandcarHavoc[6] = { 0x0043000F, 0x00430010, 0x00430011, 0x00430012, 0x00430013, 0x00430014 };
f32 D_800FF3B8_HandcarHavoc[2] = { -200.0f, 200.0f };
u16 D_800FF3C0_HandcarHavoc[2][2] = { { 4, 2 }, { 4, 2 } };
f32 D_800FF3C8_HandcarHavoc[6] = { 155.0f, 150.0f, 150.0f, 158.0f, 175.0f, 202.0f };
u16 D_800FF3E0_HandcarHavoc = 0;
f32 D_800FF3E4_HandcarHavoc = 0.0f;
u16 D_800FF3E8_HandcarHavoc = 4;
f32 D_800FF3EC_HandcarHavoc[5] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
u16 D_800FF400_HandcarHavoc = 0;
Vec D_800FF404_HandcarHavoc[4] = {
    { -110.0f, 10.0f, -160.0f }, { -90.0f, 10.0f, 30.0f }, { 110.0f, 10.0f, -160.0f }, { 90.0f, 10.0f, 30.0f },
};
f32 D_800FF434_HandcarHavoc[7] = { 260.0f, 200.0f, 120.0f, 200.0f, 0.0f, 0.0f, 0.0f };

const char D_800FF450_HandcarHavoc[] = "\x82\x60\x82\x61\x82\x62"; /* "ＡＢＣ" */

// NON_MATCHING: register allocation of the camera loop counter
#ifdef NON_MATCHING
void func_800F65E0_HandcarHavoc(void) {
    omObjData* obj;
    s16 i;

    omInitObjMan(20, 0);
    func_80060088();
    func_8001DE70(16);
    func_80029090(4);
    func_8002ADF0(&D_800EDEC0, 64);
    func_80017940(2);
    func_800179C0(2);
    for (i = 0; i < 2; i++) {
        CZoomM[i] = 1100.0f;
        CRotM[i].x = -27.0f;
        CRotM[i].y = 0;
        CRotM[i].z = 0;
        CenterM[i].x = 0;
        CenterM[i].y = 0;
        CenterM[i].z = 0;
        D_800C3110[i].unk_40 = 45.0f;
        func_8001D494(i, 45.0f, 80.0f, 20000.0f);
    }
    func_80017660(0, 0.0f, 0.0f, 144.0f, 240.0f);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 320.0f, 480.0f, 511.0f);
    func_80017660(1, 176.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(1, 640.0f, 480.0f, 511.0f, 960.0f, 480.0f, 511.0f);
    func_8002890C(0, 0, 0);
    func_80028510(0x3CA, 0x3E8, 0, 0, 0);
    obj = omAddObj(300, 0, 0, -1, func_800FD204_HandcarHavoc);
    omSetStatBit(obj, 0xA0);
    func_800FD204_HandcarHavoc(obj);
    func_80023448(3);
    func_800234B8(0, 0, 0, 0);
    func_800234B8(1, 0, 0, 0);
    func_80023504(1, 42.0f, -107.0f, 32.0f);
    D_800FF5E0_HandcarHavoc.x = -19;
    D_800FF5E0_HandcarHavoc.y = -114;
    D_800FF5E0_HandcarHavoc.z = 31;
    D_800FF5EC_HandcarHavoc = 215;
    func_800234B8(2, D_800FF5ED_HandcarHavoc, 0, 0);
    func_80023504(2, D_800FF5E0_HandcarHavoc.x, D_800FF5E0_HandcarHavoc.y, D_800FF5E0_HandcarHavoc.z);
    func_800234B8(3, 0xFF, 0xFF, 0);
    func_80023504(3, -114.0f, 33.0f, 16.0f);
    func_8002346C(3, 1, 1);
    func_8005D98C(0, 2);
    D_800FF618_HandcarHavoc = func_8005DB44(0);
    func_8005D98C(1, 2);
    D_800FF61C_HandcarHavoc = func_8005DB44(1);
    omAddObj(100, 5, 15, 0, func_800F7E8C_HandcarHavoc);
    omAddObj(100, 5, 15, 0, func_800F7EC8_HandcarHavoc);
    omAddObj(200, 0, 0, 1, func_800FAF64_HandcarHavoc);
    omAddObj(200, 0, 0, 1, func_800FAF80_HandcarHavoc);
    omSetStatBit(omAddObj(500, 0, 0, -1, func_800FCCA4_HandcarHavoc), 0xA0);
    D_800FF62C_HandcarHavoc = omAddObj(600, 0, 0, -1, func_800FCE3C_HandcarHavoc);
    omSetStatBit(omAddObj(1000, 0, 0, -1, func_800FD1B0_HandcarHavoc), 0x80);
    omAddObj(0, 0, 0, -1, func_800F72B0_HandcarHavoc);
    obj = omAddObj(50, 9, 0, -1, func_800F757C_HandcarHavoc);
    D_800FF620_HandcarHavoc = obj;
    omSetStatBit(obj, 0xA0);
    omAddObj(10000, 0, 0, -1, func_800FBF5C_HandcarHavoc);
    D_80101C8E_HandcarHavoc = InitSprite(0x43000D);
    D_80101CA2_HandcarHavoc = InitSprite(0x43000E);
    D_80101CA6_HandcarHavoc = InitSprite(0x43000B);
    D_80101CAC_HandcarHavoc = InitSprite(0x43000C);
    D_80101C88_HandcarHavoc = InitSprite(0x87);
    D_80101CAE_HandcarHavoc = InitSprite(0x87);
    func_8001897C(D_80101CAE_HandcarHavoc, 0.0f, 1.0f, 0.0f);
    func_8007B168((u8*)D_800FF450_HandcarHavoc, 1);
    D_800FF5D0_HandcarHavoc = _CheckFlag(0x2B);
    SetFadeInTypeAndTime(0, 16);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2F_HandcarHavoc/20F570", func_800F65E0_HandcarHavoc);
#endif

/* A COM rider's input for this frame, by difficulty. */
// NON_MATCHING: register allocation and branch layout of the difficulty switches
#ifdef NON_MATCHING
void func_800F6BBC_HandcarHavoc(omObjData* obj, HHPad* pad, u16 seat) {
    HHCar* w;
    u8 diff;
    s32 chance;
    s32 lean;
    s16 stickTime;
    s32 brake;
    s8 delay;

    pad->stkX = 0;
    pad->stkY = 0;
    pad->trg = 0;
    pad->btn = 0;
    if (D_80101C8A_HandcarHavoc == 1) {
        w = obj->unk_50;
        diff = GwPlayer[w->player[seat]].cpu_difficulty;
        if (diff != D_80101C8A_HandcarHavoc) {
            switch (diff) {
                case 0:
                    chance = 30;
                    lean = (rand8() & 7) + 12;
                    stickTime = (u8)(rand8() % 20) + 20;
                    brake = 10;
                    if (w->speed >= -5.0f) {
                        delay = rand8() % 3 + 1;
                    } else {
                        delay = 0;
                    }
                    break;
                case 2:
                    chance = 70;
                    lean = rand8() % 5 + 5;
                    stickTime = (u8)(rand8() % 10) + 10;
                    brake = 40;
                    if (w->speed >= -5.0f) {
                        delay = rand8() & 1;
                    } else {
                        delay = 0;
                    }
                    break;
                case 3:
                    chance = 92;
                    lean = rand8() % 5 + 1;
                    stickTime = (u8)(rand8() % 5) + 5;
                    brake = 90;
                    delay = 0;
                    break;
            }
        } else {
            chance = 45;
            lean = rand8() % 7 + 10;
            stickTime = (u8)(rand8() % 15) + 15;
            brake = 15;
            if (w->speed >= -5.0f) {
                delay = rand8() % 3;
            } else {
                delay = 0;
            }
        }
        if ((obj->work[0] & 8) && (u8)(rand8() % 100) < (u8)brake) {
            if (fabs(w->lean) != 18.0) {
                if (obj->work[0] & 0x20) {
                    if ((u8)lean < w->skidTimer || (u8)lean < fabs(w->tilt)) {
                        w->cpuStickTime[seat] = stickTime;
                        w->cpuStick[seat] = 80;
                    }
                } else if ((obj->work[0] & 0x40) && ((u8)lean < w->skidTimer || (u8)lean < fabs(w->tilt))) {
                    w->cpuStickTime[seat] = stickTime;
                    w->cpuStick[seat] = -80;
                }
            }
            switch (diff) {
                case 0:
                    w->cpuBrakeTime[seat] = (u8)(rand8() % 5) + 3;
                    break;
                case 1:
                    if (fabs(w->lean) >= 9.0) {
                        w->cpuBrakeTime[seat] = (u8)(rand8() & 3) + 2;
                    }
                    break;
                case 2:
                    if (fabs(w->lean) >= 9.0) {
                        w->cpuBrakeTime[seat] = (rand8() & 1) + 1;
                    }
                    break;
                case 3:
                    w->cpuBrakeTime[seat] = 0;
                    break;
            }
            if (w->cpu == 0) {
                w->cpuBrakeTime[seat] = (u16)w->cpuBrakeTime[seat] >> 1;
            }
        }
        if (w->cpuStickTime[seat] != 0) {
            w->cpuStickTime[seat]--;
            pad->stkX = w->cpuStick[seat];
        }
        if (w->cpuBrakeTime[seat] != 0) {
            w->cpuBrakeTime[seat]--;
            pad->btn |= 0x4000;
        }
        if (w->cpuDelay[seat] == 0) {
            if ((u8)(rand8() % 100) < (u8)chance && !(pad->btn & 0x4000)) {
                pad->trg |= 0x8000;
            }
            w->cpuDelay[seat] = delay;
        } else {
            w->cpuDelay[seat]--;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2F_HandcarHavoc/20F570", func_800F6BBC_HandcarHavoc);
#endif

void func_800F72B0_HandcarHavoc(omObjData* arg0) {
    D_80101C8A_HandcarHavoc = 0;
    D_800FF628_HandcarHavoc = 0;
    D_800FF624_HandcarHavoc = 0;
    D_800FF400_HandcarHavoc = 0;
    D_80101C90_HandcarHavoc = -1;
    D_80101CA0_HandcarHavoc = 0;
    D_80101CA8_HandcarHavoc = 0;
    D_800FF5D2_HandcarHavoc = 30;
    D_800FF5D4_HandcarHavoc = 300;
    arg0->func_ptr = &func_800F7314_HandcarHavoc;
}

/* The race: intro messages, the goal check, the clock. */
void func_800F7314_HandcarHavoc(void) {
    omObjData* car;
    s32 i;

    switch (D_80101C8A_HandcarHavoc) {
        case 0:
            if (D_800FF624_HandcarHavoc == NULL) {
                D_800FF624_HandcarHavoc = omAddObj(40, 0, 0, -1, func_800FBA80_HandcarHavoc);
            }
            break;
        case 1:
            for (i = 0; i < 2; i++) {
                if (((HHCar*)D_800FF618_HandcarHavoc[i]->unk_50)->goal == 1) {
                    break;
                }
            }
            if (i != 2) {
                D_80101C8A_HandcarHavoc = 2;
                D_80101CAA_HandcarHavoc = 0;
                D_80101C90_HandcarHavoc = func_800FC85C_HandcarHavoc();
                func_800FA318_HandcarHavoc(D_800FF618_HandcarHavoc[0]);
                func_800FA318_HandcarHavoc(D_800FF618_HandcarHavoc[1]);
                func_800FB7E4_HandcarHavoc(D_800FF618_HandcarHavoc[D_80101C90_HandcarHavoc]);
            }
            if (--D_800FF5D2_HandcarHavoc == 0) {
                if (--D_800FF5D4_HandcarHavoc == 30) {
                    GMesCreate(8, 30, 160, 32);
                } else if (D_800FF5D4_HandcarHavoc == 0 && D_80101C8A_HandcarHavoc == 1) {
                    D_80101C8A_HandcarHavoc = 2;
                    D_80101CAA_HandcarHavoc = 6;
                    func_800790C0();
                    for (i = 0; i < 2; i++) {
                        car = D_800FF618_HandcarHavoc[i];
                        if (!HH_DONE(car)) {
                            func_800FA318_HandcarHavoc(car);
                        }
                    }
                }
                D_800FF5D2_HandcarHavoc = 30;
            }
            func_80079078(D_800FF5D4_HandcarHavoc);
            break;
        case 2:
            if (D_800FF628_HandcarHavoc == NULL) {
                D_800FF628_HandcarHavoc = omAddObj(40, 0, 0, -1, func_800FBB78_HandcarHavoc);
            }
            break;
    }
}

/* Scenery: the scrolling backgrounds, the water planes, the track model. */
void func_800F757C_HandcarHavoc(omObjData* obj) {
    f32 zero;
    s32 i;
    s32 j;

    D_800FF5EE_HandcarHavoc = InitSprite(0x430006);
    D_800FF5F0_HandcarHavoc = func_80019060(D_800FF5EE_HandcarHavoc, 0, 1);
    func_80018C90(D_800FF5F0_HandcarHavoc);
    func_800FDE28_HandcarHavoc();
    func_800FDEC0_HandcarHavoc(D_800FF5F0_HandcarHavoc, &D_800FF630_HandcarHavoc[0], 0, 0);
    func_800FDEC0_HandcarHavoc(D_800FF5F0_HandcarHavoc, &D_800FF630_HandcarHavoc[1], 0, 0);
    D_800FF630_HandcarHavoc[0].x0 = 0;
    D_800FF630_HandcarHavoc[0].y0 = 0;
    D_800FF630_HandcarHavoc[0].x1 = 144;
    D_800FF630_HandcarHavoc[0].y1 = 240;
    D_800FF630_HandcarHavoc[0].sy = 0x266;
    D_800FF630_HandcarHavoc[0].v = -70.0f;
    D_800FF630_HandcarHavoc[1].x0 = 160;
    D_800FF630_HandcarHavoc[1].y0 = 0;
    D_800FF630_HandcarHavoc[1].x1 = 320;
    D_800FF630_HandcarHavoc[1].y1 = 240;
    D_800FF630_HandcarHavoc[1].sy = 0x266;
    D_800FF630_HandcarHavoc[1].v = -70.0f;
    func_800FE004_HandcarHavoc(D_800FF630_HandcarHavoc);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 40; j++) {
            D_800FF630_HandcarHavoc[i].angle += D_800FF630_HandcarHavoc[i].dAngle;
            if (D_800FF630_HandcarHavoc[i].angle < 0.0f) {
                D_800FF630_HandcarHavoc[i].angle += 360.0f;
            }
            if (D_800FF630_HandcarHavoc[i].angle >= 360.0f) {
                D_800FF630_HandcarHavoc[i].angle -= 360.0f;
            }
        }
    }
    obj->model[0] = LoadFormFile(0x430000, 0x689);
    func_80025F10(obj->model[0], 1);
    obj->model[1] = func_80023FC8(obj->model[0]);
    func_80025F10(obj->model[1], 2);
    obj->model[2] = LoadFormFile(0x430008, 0x689);
    func_80025F10(obj->model[2], 1);
    obj->model[3] = func_80023FC8(obj->model[2]);
    func_80025F10(obj->model[3], 2);
    obj->model[4] = LoadFormFile(0x280007, 0x689);
    func_80025F10(obj->model[4], 1);
    func_80025830(obj->model[4], 3.0f, 1.0f, 3.0f);
    obj->model[5] = LoadFormFile(0x280007, 0x689);
    func_80025F10(obj->model[5], 2);
    func_80025830(obj->model[5], 3.0f, 1.0f, 3.0f);
    func_80039C48("00mt037_DEF", D_800FF5F2_HandcarHavoc);
    func_80026040(obj->model[4]);
    func_80026040(obj->model[5]);
    zero = 0.0f;
    D_800FF5FC_HandcarHavoc = zero;
    D_800FF5F8_HandcarHavoc = zero;
    D_800FF5FC_HandcarHavoc = zero;
    D_800FF600_HandcarHavoc = zero;
    obj->model[7] = LoadFormFile(0x43000A, 0x689);
    func_80025F10(obj->model[7], 1);
    func_80025830(obj->model[7], 7.5f, 1.0f, 7.5f);
    obj->model[8] = func_80023FC8(obj->model[7]);
    func_80025F10(obj->model[8], 2);
    func_80025830(obj->model[8], 7.5f, 1.0f, 7.5f);
    D_800FF608_HandcarHavoc = LoadFormFile(0x430007, 0x80D);
    D_800FF60C_HandcarHavoc = (HHColVtx*)D_800F2B7C[D_800FF608_HandcarHavoc].unk_6C->unk_78;
    D_800FF610_HandcarHavoc = D_800F2B7C[D_800FF608_HandcarHavoc].unk_6C->unk_6E;
    func_800FC058_HandcarHavoc();
    func_800F7DD8_HandcarHavoc();
    D_800FF5E8_HandcarHavoc = zero;
    omSetObjPrio(obj, 400);
    obj->func_ptr = func_800F7998_HandcarHavoc;
}

/* Water planes follow the cameras; the sun light circles. */
void func_800F7998_HandcarHavoc(omObjData* obj) {
    f32 x;
    f32 z;

    x = CenterM[0].x + func_800AEAC0(CRotM[0].y) * -2000.0f;
    z = CenterM[0].z + func_800AEFD0(CRotM[0].y) * -2000.0f;
    func_80025798(obj->model[4], x, D_800FF5D8_HandcarHavoc[0], z);
    func_80025798(obj->model[7], x, D_800FF5D8_HandcarHavoc[0] + 20.0f, z);
    x = CenterM[1].x + func_800AEAC0(CRotM[1].y) * -2000.0f;
    z = CenterM[1].z + func_800AEFD0(CRotM[1].y) * -2000.0f;
    func_80025798(obj->model[5], x, D_800FF5D8_HandcarHavoc[1], z);
    func_80025798(obj->model[8], x, D_800FF5D8_HandcarHavoc[1] + 20.0f, z);
    func_800257E4(obj->model[4], 0.0f, CRotM[0].y, 0.0f);
    func_800257E4(obj->model[5], 0.0f, CRotM[1].y, 0.0f);
    func_800257E4(obj->model[7], 0.0f, CRotM[0].y, 0.0f);
    func_800257E4(obj->model[8], 0.0f, CRotM[1].y, 0.0f);
    if (func_8005FD5C() + D_800F64F8 == 0) {
        D_800FF5FC_HandcarHavoc += func_800AEAC0(CRotM[0].y) * 0.7f;
        D_800FF5F8_HandcarHavoc += func_800AEFD0(CRotM[0].y) * 0.7f;
        D_800FF604_HandcarHavoc += func_800AEAC0(CRotM[1].y) * 0.7f;
        D_800FF600_HandcarHavoc += func_800AEFD0(CRotM[1].y) * 0.7f;
    }
    func_80027E48(obj->model[4], D_800FF5F8_HandcarHavoc, D_800FF5FC_HandcarHavoc, D_800FF5F2_HandcarHavoc[0],
                  D_800FF5F2_HandcarHavoc[1], "00m_037", 1);
    func_80027E48(obj->model[5], D_800FF600_HandcarHavoc, D_800FF604_HandcarHavoc, D_800FF5F2_HandcarHavoc[0],
                  D_800FF5F2_HandcarHavoc[1], "00m_037", 1);
    D_800FF5E0_HandcarHavoc.x = D_800FF5E0_HandcarHavoc.x + func_800AEAC0(D_800FF5E8_HandcarHavoc) * 4.0f;
    D_800FF5E0_HandcarHavoc.z = D_800FF5E0_HandcarHavoc.z + func_800AEFD0(D_800FF5E8_HandcarHavoc) * 4.0f;
    D_800FF5E8_HandcarHavoc += 10.0f;
    if (D_800FF5E8_HandcarHavoc >= 360.0f) {
        D_800FF5E8_HandcarHavoc -= 360.0f;
    }
    D_800FF5EC_HandcarHavoc = func_800AEFD0(D_800FF5E8_HandcarHavoc) * 60.0f + 195.0f;
    func_800234B8(2, D_800FF5ED_HandcarHavoc, 0, 0);
    func_80023504(2, D_800FF5E0_HandcarHavoc.x, D_800FF5E0_HandcarHavoc.y, D_800FF5E0_HandcarHavoc.z);
}

/* The map in the middle: 16 track segments and the goal. */
void func_800F7DD8_HandcarHavoc(void) {
    u16 spr;
    s32 i;

    for (i = 0; i < 16; i++) {
        spr = func_80019060(D_80101CA6_HandcarHavoc, 0, 1);
        func_80018D44(spr, 8);
        SetBasicSpritePos(spr, 160, i * 16);
        ShowBasicSprite(spr);
    }
    spr = func_80019060(D_80101CAC_HandcarHavoc, 0, 1);
    func_80018D44(spr, 8);
    SetBasicSpritePos(spr, 160, 24);
    ShowBasicSprite(spr);
}

void func_800F7E8C_HandcarHavoc(omObjData* arg0) {
    func_800F7F04_HandcarHavoc(arg0, 0, 9870.0f, 0, 12375.0f);
}

void func_800F7EC8_HandcarHavoc(omObjData* arg0) {
    func_800F7F04_HandcarHavoc(arg0, 1, 9870.0f, 0, 12375.0f);
}

/* Builds a team's car and its two riders. */
// NON_MATCHING: 0.0f stored with swc1 in retail; register allocation
#ifdef NON_MATCHING
void func_800F7F04_HandcarHavoc(omObjData* obj, u16 team, f32 x, s32 y, f32 z) {
    Vec pos;
    Vec rot;
    HHCar* w;
    char* unused;
    u16 seat;
    u16 layer;
    u16 humans;
    s32 dir;
    u8 chr;
    s32 i;

    seat = 0;
    layer = 2;
    if (team == 0) {
        layer = 1;
    }
    w = obj->unk_50 = func_80023684(sizeof(HHCar), 0x7918);
    w->team = team;
    w->leanIn = 0;
    w->lean = 0;
    w->tilt = 0;
    w->unk00 = 0;
    w->pump = 0;
    w->seg[1] = 0;
    w->seg[0] = 0;
    w->progress = 0;
    w->goal = 0;
    w->sndOn = 0;
    w->sparkSndOn = 0;
    w->chips[0][0] = 0;
    w->chips[0][1] = 0;
    w->chips[1][0] = 0;
    w->chips[1][1] = 0;
    w->brake = 0;
    w->skidTimer = 0.0f;
    w->tipTimer = 0.0f;
    w->unk94 = 0.0f;
    w->cpuStickTime[1] = 0;
    w->cpuStickTime[0] = 0;
    w->cpuStick[1] = 0;
    w->cpuStick[0] = 0;
    w->cpuBrakeTime[1] = 0;
    w->cpuBrakeTime[0] = 0;
    w->cpuDelay[1] = 0;
    w->cpuDelay[0] = 0;
    w->unkAE = 0;
    obj->work[0] = 1;
    w->marker = func_80019060(team == 0 ? D_80101C8E_HandcarHavoc : D_80101CA2_HandcarHavoc, 0, 1);
    func_80018D44(w->marker, 8);
    ShowBasicSprite(w->marker);
    if (team == 0) {
        obj->model[0] = LoadFormFile(0x430003, 0xA99);
        obj->model[1] = LoadFormFile(0x430002, 0x20A99);
        func_80025EB4(obj->model[0], 1, 1);
        func_80025EB4(obj->model[1], 1, 1);
        LoadFormFile(0x430005, 0x2068D);
        obj->model[2] = LoadFormFile(0x430002, 0x20A8D);
        func_80027AC8(obj->model[2], "64mt001b2_DEF", "64mt001e_DEF");
        func_80025AD4(obj->model[2]);
        func_80025B34(obj->model[2]);
    } else {
        obj->model[0] = func_80023FC8(D_800FF618_HandcarHavoc[0]->model[0]);
        obj->model[1] = func_80023FC8(D_800FF618_HandcarHavoc[0]->model[1]);
        func_80025EB4(obj->model[0], 1, 1);
        func_80025EB4(obj->model[1], 1, 1);
        obj->model[2] = func_80023FC8(D_800FF618_HandcarHavoc[0]->model[2]);
    }
    unused = "";
    func_80025EB4(obj->model[2], 1, 1);
    func_80025F10(obj->model[0], layer);
    func_80025F10(obj->model[1], layer);
    func_80025F10(obj->model[2], layer);
    w->speed = 0;
    w->maxSpeed = 101.851845f;
    w->lever1Dir = 0;
    w->leverDir = 0;
    humans = 0;
    for (i = 0; i < 4; i++) {
        if (GwPlayer[i].group == team) {
            if (GwPlayer[i].flags & 1) {
                switch (GwPlayer[i].cpu_difficulty) {
                    case 0:
                        w->maxSpeed -= 3.7037037037037037;
                        break;
                    case 1:
                        w->maxSpeed -= 2.7777777777777777;
                        break;
                    case 2:
                        w->maxSpeed -= 1.8518518518518519;
                        break;
                    case 3:
                        w->maxSpeed -= 0.9259259259259259;
                        break;
                }
                humans++;
            }
            w->player[seat] = i;
            chr = GwPlayer[i].character;
            dir = D_800C59AC[chr].unk_00;
            obj->model[3 + seat] = LoadFormFile(dir | D_800C59AC[chr].unk_04, 0xA99);
            func_8001775C(obj, seat + 3, dir | 0x82);
            func_8001775C(obj, seat + 1, dir | 0x2E);
            func_8001775C(obj, seat + 5, dir);
            func_8001775C(obj, seat + 9, dir | 1);
            func_8001775C(obj, seat + 7, dir | 5);
            if (rand8() & 1) {
                func_8001775C(obj, seat + 11, dir | 0xF);
            } else {
                func_8001775C(obj, seat + 11, dir | 0x38);
            }
            if (GwPlayer[i].character != 5) {
                func_8001775C(obj, seat + 13, dir | 0x10);
            } else {
                func_8001775C(obj, seat + 13, dir | 0x3C);
            }
            func_80025BB8(obj->model[3 + seat], obj->motion[1 + seat]);
            func_80025EB4(obj->model[3 + seat], 1, 1);
            w->face[seat] = func_80019060(InitSprite(D_800FF3A0_HandcarHavoc[chr]), 0, 1);
            ShowBasicSprite(w->face[seat]);
            w->seat[seat] = D_800FF3C8_HandcarHavoc[GwPlayer[i].character];
            if (seat == 0) {
                w->front[0] = 1;
                func_80018D44(w->face[0], 8);
            } else {
                w->front[seat] = 0;
                func_80018D44(w->face[seat], 8);
                w->seat[seat] = -w->seat[seat];
            }
            func_80025F10(obj->model[3 + seat], layer);
            seat++;
        }
    }
    if (humans < 2) {
        w->maxSpeed = 101.851845f;
        w->cpu = 0;
    } else {
        w->cpu = 1;
    }
    func_800FC124_HandcarHavoc(w->seg[1], &pos);
    omSetTra(obj, pos.x, pos.y, pos.z);
    rot.x = 0;
    rot.y = 90.0f;
    rot.z = 0;
    for (i = 0; i < 2; i++) {
        w->dist[i] = func_800FC22C_HandcarHavoc(func_800AEAC0(rot.y) * D_800FF3B8_HandcarHavoc[i] + obj->trans.x,
                                                obj->trans.y,
                                                func_800AEFD0(rot.y) * D_800FF3B8_HandcarHavoc[i] + obj->trans.z,
                                                w->seg[i]);
    }
    D_800FF614_HandcarHavoc -= w->dist[0];
    func_800FC338_HandcarHavoc(obj, &rot, &pos);
    w->rot.x = w->prevRot.x = rot.x;
    w->rot.y = w->prevRot.y = rot.y;
    w->rot.z = w->prevRot.z = rot.z;
    omSetTra(obj, pos.x, pos.y, pos.z);
    func_800F93DC_HandcarHavoc(obj);
    w->prevSlope.x = w->slope.x;
    w->prevSlope.y = w->slope.y;
    w->prevSlope.z = w->slope.z;
    D_800FF5D8_HandcarHavoc[team] = obj->trans.y + -1500.0f;
    func_800FDBC8_HandcarHavoc(obj);
    func_800FCBA4_HandcarHavoc(obj);
    func_800FE8D4_HandcarHavoc(team);
    obj->func_ptr = func_800F8730_HandcarHavoc;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2F_HandcarHavoc/20F570", func_800F7F04_HandcarHavoc);
#endif

/* The race: both riders' input pumps, leans and brakes the car. */
// NON_MATCHING: retail shares the clamp stores of the speed/lean tails (cross-jumped)
#ifdef NON_MATCHING
void func_800F8730_HandcarHavoc(omObjData* obj) {
    Vec rot;
    Vec pos;
    HHPad pad[2];
    HHCar* w;
    u16 team;
    s16 i;
    u16 port;

    w = obj->unk_50;
    team = w->team;
    if (D_80101C8A_HandcarHavoc == 0) {
        return;
    }
    if (D_80101C8A_HandcarHavoc == 1) {
        for (i = 0; i < 2; i++) {
            port = GwPlayer[w->player[i]].port;
            if (!(GwPlayer[w->player[i]].flags & 1)) {
                pad[i].stkX = ContStkX[port];
                pad[i].stkY = ContStkY[port];
                pad[i].trg = ContBtnTrg[port];
                pad[i].btn = ContBtn[port];
            } else {
                func_800F6BBC_HandcarHavoc(obj, &pad[i], i);
            }
        }
        w->leanIn = 0.0f;
        for (i = 0; i < 2; i++) {
            if (pad[i].trg & 0x8000) {
                w->pump += 0.3f;
                if (w->pump > 5.0f) {
                    w->pump = 5.0f;
                }
                w->speed -= 2.5f;
            }
            w->leanIn += func_800F9774_HandcarHavoc(pad[i].stkX);
        }
        if (w->speed < 0.0f) {
            w->speed += 0.2f;
            if (w->speed > 0.0f) {
                w->speed = 0.0f;
            }
        } else {
            w->speed -= 0.2f;
            if (w->speed < 0.0f) {
                w->speed = 0.0f;
            }
        }
        w->speed = -w->slope.y * 5.0f + w->speed;
        w->brake = 0;
        for (i = 0; i < 2; i++) {
            if (pad[i].btn & 0x4000) {
                w->speed *= 0.97f;
                w->brake = 1;
            }
        }
    }
    if (w->speed > w->maxSpeed) {
        w->speed = w->maxSpeed;
    }
    if (w->speed < -w->maxSpeed) {
        w->speed = -w->maxSpeed;
    }
    if (w->speed != 0.0f && w->sndOn == 0) {
        w->snd = func_80060540(team + 0x33D, team);
        w->sndOn = 1;
    }
    if (w->sndOn == 1) {
        func_80060440(w->snd, fabs(w->speed) * 5.40000057220459);
        if (fabs(w->speed) <= 0.5) {
            func_8006071C(w->snd);
            w->sndOn = 0;
        }
    }
    if (func_800FC4B0_HandcarHavoc(obj) == 1 && D_80101C8A_HandcarHavoc != 2) {
        w->goal = 1;
    }
    func_800FC338_HandcarHavoc(obj, &rot, &pos);
    w->rot.x = rot.x;
    w->rot.y = rot.y;
    w->rot.z = rot.z;
    if (w->rot.x < 0.0f) {
        w->rot.x += 360.0f;
    }
    if (w->rot.x >= 360.0f) {
        w->rot.x -= 360.0f;
    }
    if (w->rot.y < 0.0f) {
        w->rot.y += 360.0f;
    }
    if (w->rot.y >= 360.0f) {
        w->rot.y -= 360.0f;
    }
    if (w->rot.z < 0.0f) {
        w->rot.z += 360.0f;
    }
    if (w->rot.z >= 360.0f) {
        w->rot.z -= 360.0f;
    }
    if (w->leanIn < w->lean) {
        w->lean -= 2.0f;
        if (w->lean < w->leanIn) {
            w->lean = w->leanIn;
        }
    }
    if (w->lean < w->leanIn) {
        w->lean += 2.0f;
        if (w->leanIn < w->lean) {
            w->lean = w->leanIn;
        }
    }
    func_800F8E00_HandcarHavoc(obj);
    omSetTra(obj, pos.x, pos.y, pos.z);
    func_800F93DC_HandcarHavoc(obj);
    func_800FCBA4_HandcarHavoc(obj);
    func_800FDBC8_HandcarHavoc(obj);
    if (!(w->pump >= 0.1f)) {
        w->pump = 0.0f;
    } else {
        w->pump -= 0.06f;
    }
    for (i = 0; i < 3; i++) {
        (&w->prevSlope.x)[i] = (&w->slope.x)[i];
        (&w->prevRot.x)[i] = (&w->rot.x)[i];
    }
    D_800FF5D8_HandcarHavoc[team] = obj->trans.y + -1500.0f;
    func_800FF0AC_HandcarHavoc(w);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2F_HandcarHavoc/20F570", func_800F8730_HandcarHavoc);
#endif

/* Tilt from the lean and the bend; tipping and skidding. */
void func_800F8E00_HandcarHavoc(omObjData* obj) {
    HHCar* w;
    f32 d;

    w = obj->unk_50;
    if (w->tilt != 0.0f) {
        d = w->leanIn * 0.021f;
        if (w->tilt < 0.0f) {
            if (d > 0.0f) {
                w->tilt = d + w->tilt;
                if (w->tilt > 0.0f) {
                    w->tilt = 0.0f;
                }
            }
        } else if (d < 0.0f) {
            w->tilt = d + w->tilt;
            if (w->tilt < 0.0f) {
                w->tilt = 0.0f;
            }
        }
    }
    switch (func_800F917C_HandcarHavoc(obj)) {
        case 0:
            obj->work[0] &= 0x87;
            if (w->tilt > 0.0f) {
                w->tilt -= 2.0f;
                if (w->tilt < 0.0f) {
                    w->tilt = 0.0f;
                }
            } else {
                w->tilt += 2.0f;
                if (w->tilt > 0.0f) {
                    w->tilt = 0.0f;
                }
            }
            if (w->tipTimer != 0.0f) {
                w->tipTimer -= 1.0f;
            }
            if (w->skidTimer != 0.0f) {
                w->skidTimer -= 1.0f;
            }
            break;
        case 1:
            obj->work[0] |= 8;
            if (fabs(w->tilt) >= 21.0) {
                w->tipTimer += 1.0f;
            } else {
                w->tipTimer = 0;
            }
            func_80060F04(w->player[0], 5, 0, 5);
            func_80060F04(w->player[1], 5, 0, 5);
            if (obj->work[0] & 0x20) {
                w->tilt += 1.25f;
                if (w->tilt >= 25.0f) {
                    w->tilt = 25.0f;
                }
            } else {
                w->tilt -= 1.25f;
                if (w->tilt <= -25.0f) {
                    w->tilt = -25.0f;
                }
            }
            if (w->tipTimer >= 15.0f) {
                obj->func_ptr = func_800F9844_HandcarHavoc;
            }
            break;
        case 2:
            obj->work[0] |= 0x10;
            w->skidTimer += 1.0f;
            if (w->skidTimer >= 15.0f) {
                w->speed *= 0.5f;
                w->skidTimer = 0.0f;
            }
            break;
    }
}

/* 0: straight, 1: too fast into a bend (tipping), 2: skidding at full lean. */
// NON_MATCHING: float registers of lean * 0.085f and the * 10.0f constant (raw 5, masked 0);
// float declaration order, fabsf(d) inline, and accumulating into ad tried
#ifdef NON_MATCHING
u16 func_800F917C_HandcarHavoc(omObjData* obj) {
    HHCar* w;
    f32 a;
    f32 b;
    f32 d;
    f32 ad;
    f32 lean;
    u16 r;

    w = obj->unk_50;
    if (w->speed == 0.0f) {
        return 0;
    }
    if (w->prevRot.y == w->rot.y) {
        return 0;
    }
    a = w->prevRot.y;
    b = w->rot.y;
    if (a > 180.0f) {
        a -= 360.0f;
    }
    if (b > 180.0f) {
        b -= 360.0f;
    }
    d = a - b;
    if (w->speed > 0.0f) {
        d = -d;
    }
    ad = fabsf(d);
    if (ad < 1.0f) {
        return 0;
    }
    if (d > 0.0f) {
        lean = w->lean;
    } else {
        lean = -w->lean;
    }
    ad += lean * 0.085f;
    if (ad * 10.0f + fabs(w->speed) < 80.0) {
        return 0;
    }
    if (fabs(w->lean) != 18.0) {
        r = 1;
        if (d > 0.0f) {
            func_800FCA58_HandcarHavoc(obj, 0);
            obj->work[0] |= 0x20;
        } else {
            func_800FCA58_HandcarHavoc(obj, 1);
            obj->work[0] |= 0x40;
        }
    } else {
        r = 2;
        if (w->tilt == 0.0f) {
            if (d > 0.0f) {
                func_800FCA58_HandcarHavoc(obj, 1);
                obj->work[0] |= 0x20;
            } else {
                func_800FCA58_HandcarHavoc(obj, 0);
                obj->work[0] |= 0x40;
            }
        }
    }
    return r;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2F_HandcarHavoc/20F570", func_800F917C_HandcarHavoc);
#endif

/* Places the car, levers and riders from the car's rotation, lean and tilt. */
void func_800F93DC_HandcarHavoc(omObjData* obj) {
    Vec seat;
    HHCar* w;
    f32 tx;
    f32 tz;
    f32 lx;
    f32 lz;

    w = obj->unk_50;
    tx = func_800AEAC0(w->rot.y) * w->tilt;
    tz = func_800AEFD0(w->rot.y) * w->tilt;
    lx = func_800AEAC0(w->rot.y) * w->lean + tx;
    lz = func_800AEFD0(w->rot.y) * w->lean + tz;
    omSetTra(obj, obj->trans.x, (f32)(fabs(func_800AEAC0(w->tilt)) * 75.0) + obj->trans.y, obj->trans.z);
    func_8009ECB0(D_800F2B7C[obj->model[0]].unk7C, 0.0f, w->rot.y, 0.0f);
    omSetRot(obj, tx + w->rot.x, 0.0f, tz + w->rot.z);
    func_80025798(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8009ECB0(D_800F2B7C[obj->model[1]].unk7C, 0.0f, w->rot.y, 0.0f);
    func_800257E4(obj->model[1], lx + w->rot.x, 0.0f, lz + w->rot.z);
    func_80025798(obj->model[2], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8009ECB0(D_800F2B7C[obj->model[2]].unk7C, 0.0f, w->rot.y, 0.0f);
    func_800257E4(obj->model[2], lx + w->rot.x, 0.0f, lz + w->rot.z);
    if (w->brake == 0) {
        func_800258EC(obj->model[2], 4, 4);
        func_800258EC(obj->model[1], 4, 0);
    } else {
        func_800258EC(obj->model[2], 4, 0);
        func_800258EC(obj->model[1], 4, 4);
    }
    func_800FD59C_HandcarHavoc(obj, 0, &seat);
    func_80025798(obj->model[3], seat.x, seat.y, seat.z);
    func_8009ECB0(D_800F2B7C[obj->model[3]].unk7C, 0.0f, w->rot.y + 180.0f, 0.0f);
    func_800257E4(obj->model[3], lx + w->rot.x, 0.0f, lz + w->rot.z);
    func_800FD59C_HandcarHavoc(obj, 1, &seat);
    func_80025798(obj->model[4], seat.x, seat.y, seat.z);
    func_8009ECB0(D_800F2B7C[obj->model[4]].unk7C, 0.0f, w->rot.y, 0.0f);
    func_800257E4(obj->model[4], lx + w->rot.x, 0.0f, lz + w->rot.z);
}

f32 func_800F9774_HandcarHavoc(s8 arg0) {
    s8 temp_f2 = arg0;
    f32 phi_f4_2;

    if (arg0 < 0.0f) {
        phi_f4_2 = 1.0f;
    } else {
        phi_f4_2 = -1.0f;
    }

    temp_f2 = fabs(temp_f2);

    if (temp_f2 == 0.0f) {
        phi_f4_2 = phi_f4_2 * 0.0f;
    } else {
        if (temp_f2 >= 0x46) {
            phi_f4_2 =  phi_f4_2* 9.0f;
        } else {
            phi_f4_2 = phi_f4_2 * 4.5f;
        }
    }
    return phi_f4_2;
}

/* Tipping over: the car rolls onto its side, then the riders are thrown. */
// NON_MATCHING: retail shares the lean clamp store (cross-jumped)
#ifdef NON_MATCHING
void func_800F9844_HandcarHavoc(omObjData* obj) {
    Vec rot;
    Vec pos;
    HHCar* w;
    s32 i;

    w = obj->unk_50;
    if (obj->work[0] & 0x20) {
        w->tilt += 4.0f;
        if (w->tilt >= 60.0f) {
            func_800F9B54_HandcarHavoc(obj);
            obj->func_ptr = func_800F9DD8_HandcarHavoc;
        }
    } else if (obj->work[0] & 0x40) {
        w->tilt -= 4.0f;
        if (w->tilt <= -60.0f) {
            func_800F9B54_HandcarHavoc(obj);
            obj->func_ptr = func_800F9DD8_HandcarHavoc;
        }
    }
    w->brake = 0;
    func_800FC4B0_HandcarHavoc(obj);
    func_800FC338_HandcarHavoc(obj, &rot, &pos);
    w->rot.x = rot.x;
    w->rot.y = rot.y;
    w->rot.z = rot.z;
    if (w->rot.x < 0.0f) {
        w->rot.x += 360.0f;
    }
    if (w->rot.x >= 360.0f) {
        w->rot.x -= 360.0f;
    }
    if (w->rot.y < 0.0f) {
        w->rot.y += 360.0f;
    }
    if (w->rot.y >= 360.0f) {
        w->rot.y -= 360.0f;
    }
    if (w->rot.z < 0.0f) {
        w->rot.z += 360.0f;
    }
    if (w->rot.z >= 360.0f) {
        w->rot.z -= 360.0f;
    }
    if (w->leanIn < w->lean) {
        w->lean -= 2.0f;
        if (w->lean < w->leanIn) {
            w->lean = w->leanIn;
        }
    }
    if (w->lean < w->leanIn) {
        w->lean += 2.0f;
        if (w->leanIn < w->lean) {
            w->lean = w->leanIn;
        }
    }
    omSetTra(obj, pos.x, pos.y, pos.z);
    func_800F93DC_HandcarHavoc(obj);
    func_800FCBA4_HandcarHavoc(obj);
    for (i = 0; i < 3; i++) {
        (&w->prevSlope.x)[i] = (&w->slope.x)[i];
        (&w->prevRot.x)[i] = (&w->rot.x)[i];
    }
    D_800FF5D8_HandcarHavoc[w->team] = obj->trans.y + -1500.0f;
    obj->work[0] |= 2;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2F_HandcarHavoc/20F570", func_800F9844_HandcarHavoc);
#endif

/* Throws both riders off the side the car fell to. */
// NON_MATCHING: retail stores the fall yaw once in a shared tail
#ifdef NON_MATCHING
void func_800F9B54_HandcarHavoc(omObjData* obj) {
    Vec pos;
    HHCar* w;
    omObjData* rider;
    HHFall* f;
    f32 ry;
    s32 i;

    w = obj->unk_50;
    for (i = 0; i < 2; i++) {
        rider = omAddObj(100, 1, 1, -1, func_800FA210_HandcarHavoc);
        f = rider->unk_50 = func_80023684(sizeof(HHFall), 0x7918);
        if (obj->work[0] & 0x20) {
            f->yaw = w->rot.y - 90.0f;
        }
        if (obj->work[0] & 0x40) {
            f->yaw = w->rot.y + 90.0f;
        }
        if (f->yaw < 0.0f) {
            f->yaw += 360.0f;
        }
        if (f->yaw >= 360.0f) {
            f->yaw -= 360.0f;
        }
        ry = w->rot.y;
        rider->model[0] = obj->model[3 + i];
        rider->motion[0] = obj->motion[3 + i];
        func_800FD59C_HandcarHavoc(obj, i, &pos);
        omSetTra(rider, pos.x, pos.y, pos.z);
        omSetRot(rider, 0.0f, ry, 0.0f);
        func_80025BB8(rider->model[0], rider->motion[0]);
        f->angle = 10.0f;
        f->v0 = 10.0f;
        f->t = 0.0f;
        f->g = 2.5f;
        f->side = 40.0f;
        func_80060618(0x45F, w->player[i]);
        D_800FF62C_HandcarHavoc->work[w->team] = 0;
    }
    if (w->sndOn == 1) {
        func_8006071C(w->snd);
        w->sndOn = 0;
    }
    w->fallAngle = 10.0f;
    w->fallV0 = 10.0f;
    w->fallT = 0;
    w->fallG = 2.5f;
    w->fallSide = 40.0f;
    func_800FB5DC_HandcarHavoc(obj);
    D_80101CA0_HandcarHavoc++;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2F_HandcarHavoc/20F570", func_800F9B54_HandcarHavoc);
#endif

/* The fallen car slides off and sinks; decides the race when both have fallen. */
// NON_MATCHING: only residue is retail's VR4300 mul-fix nop between the mul.s of fallG*t*t (as in
// func_800FA210); the unit-wide mul fix breaks func_800F7998, so likely a separate retail TU
#ifdef NON_MATCHING
void func_800F9DD8_HandcarHavoc(omObjData* obj) {
    HHCar* w;
    omObjData* other;
    f32 yaw;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 tx;
    f32 tz;
    f32 lx;
    f32 lz;

    func_800258EC(obj->model[2], 4, 4);
    func_800258EC(obj->model[1], 4, 0);
    w = obj->unk_50;
    if (obj->work[0] & 0x20) {
        yaw = w->rot.y - 90.0f;
        w->tilt += 1.0f;
    } else {
        yaw = w->rot.y + 90.0f;
        w->tilt -= 1.0f;
    }
    dx = func_800AEAC0(yaw) * w->fallSide;
    dy = func_800AEAC0(w->fallAngle) * w->fallV0 * w->fallT - w->fallG * w->fallT * w->fallT;
    dz = func_800AEFD0(yaw) * w->fallSide;
    omSetTra(obj, dx + obj->trans.x, dy + obj->trans.y, dz + obj->trans.z);
    func_80025798(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    tx = func_800AEAC0(w->rot.y) * w->tilt;
    tz = func_800AEFD0(w->rot.y) * w->tilt;
    lx = func_800AEAC0(w->rot.y) * w->lean + tx;
    lz = func_800AEFD0(w->rot.y) * w->lean + tz;
    func_8009ECB0(D_800F2B7C[obj->model[0]].unk7C, 0.0f, w->rot.y, 0.0f);
    omSetRot(obj, tx + w->rot.x, 0.0f, tz + w->rot.z);
    func_8009ECB0(D_800F2B7C[obj->model[1]].unk7C, 0.0f, w->rot.y, 0.0f);
    func_800257E4(obj->model[1], lx + w->rot.x, 0.0f, lz + w->rot.z);
    func_8009ECB0(D_800F2B7C[obj->model[2]].unk7C, 0.0f, w->rot.y, 0.0f);
    func_800257E4(obj->model[2], lx + w->rot.x, 0.0f, lz + w->rot.z);
    func_800FF0AC_HandcarHavoc(w);
    w->fallT += 1.0f;
    if (w->fallT >= 30.0f) {
        func_800258EC(obj->model[0], 4, 4);
        func_800258EC(obj->model[1], 4, 4);
        func_800258EC(obj->model[2], 4, 4);
        obj->func_ptr = NULL;
        if ((u16)D_80101CA0_HandcarHavoc == 2 && D_80101C8A_HandcarHavoc != (u16)D_80101CA0_HandcarHavoc &&
            D_80101CAA_HandcarHavoc != 6) {
            func_800601D4(40);
            D_80101C8A_HandcarHavoc = 2;
            D_80101CAA_HandcarHavoc = 6;
        }
        obj->work[0] |= 4;
        if ((w->player[0] == 0 || w->player[1] == 0) && D_80101C8A_HandcarHavoc != 2 &&
            D_800FF5D0_HandcarHavoc != 0) {
            D_80101C8A_HandcarHavoc = 2;
            D_80101CAA_HandcarHavoc = 8;
            other = D_800FF618_HandcarHavoc[w->team ^ 1];
            if (!HH_DONE(other)) {
                func_800FA318_HandcarHavoc(other);
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2F_HandcarHavoc/20F570", func_800F9DD8_HandcarHavoc);
#endif

/* A thrown rider's arc. */
// NON_MATCHING: retail has a VR4300 mul-fix nop between the two mul.s of g*t*t (masked 2); the
// unit-wide mul fix adds nops to func_800F7998, so this may belong to a separate retail TU
#ifdef NON_MATCHING
void func_800FA210_HandcarHavoc(omObjData* obj) {
    HHFall* f;
    f32 dy;

    f = obj->unk_50;
    dy = func_800AEAC0(f->angle) * f->v0 * f->t - f->g * f->t * f->t;
    omSetTra(obj, func_800AEAC0(f->yaw) * f->side + obj->trans.x, dy + obj->trans.y,
             func_800AEFD0(f->yaw) * f->side + obj->trans.z);
    f->t += 1.0f;
    if (f->t >= 30.0f) {
        func_800258EC(obj->model[0], 4, 4);
        omDelObj(obj);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2F_HandcarHavoc/20F570", func_800FA210_HandcarHavoc);
#endif

/* Stops a car (race over). */
void func_800FA318_HandcarHavoc(omObjData* obj) {
    HHCar* w;

    w = obj->unk_50;
    if (!HH_DONE(obj)) {
        if (fabs(w->speed) < 60.0 && w->team == D_80101C90_HandcarHavoc) {
            w->speed = -60.0f;
        }
        w->decel = fabs(w->speed) / 30.0;
        w->stopTimer = 30;
        w->leanIn = 0;
        obj->func_ptr = func_800FA3B8_HandcarHavoc;
    }
}

/* Braking to a stop at the end. */
// NON_MATCHING: retail shares the lean clamp store (cross-jumped)
#ifdef NON_MATCHING
void func_800FA3B8_HandcarHavoc(omObjData* obj) {
    Vec pos;
    Vec rot;
    HHCar* w;
    s32 i;

    w = obj->unk_50;
    if (w->speed < 0.0f) {
        w->speed += w->decel;
    } else {
        w->speed -= w->decel;
    }
    func_800FC4B0_HandcarHavoc(obj);
    if (w->speed != 0.0f && w->sndOn == 0) {
        w->snd = func_80060540(w->team + 0x33D, w->team);
        w->sndOn = 1;
    }
    if (w->sndOn == 1) {
        func_80060440(w->snd, fabs(w->speed) * 5.40000057220459);
        if (fabs(w->speed) <= 0.5) {
            func_8006071C(w->snd);
            w->sndOn = 0;
        }
    }
    func_800FC338_HandcarHavoc(obj, &rot, &pos);
    w->rot.x = rot.x;
    w->rot.y = rot.y;
    w->rot.z = rot.z;
    if (w->rot.x < 0.0f) {
        w->rot.x += 360.0f;
    }
    if (w->rot.x >= 360.0f) {
        w->rot.x -= 360.0f;
    }
    if (w->rot.y < 0.0f) {
        w->rot.y += 360.0f;
    }
    if (w->rot.y >= 360.0f) {
        w->rot.y -= 360.0f;
    }
    if (w->rot.z < 0.0f) {
        w->rot.z += 360.0f;
    }
    if (w->rot.z >= 360.0f) {
        w->rot.z -= 360.0f;
    }
    if (w->leanIn < w->lean) {
        w->lean -= 2.0f;
        if (w->lean < w->leanIn) {
            w->lean = w->leanIn;
        }
    }
    if (w->lean < w->leanIn) {
        w->lean += 2.0f;
        if (w->leanIn < w->lean) {
            w->lean = w->leanIn;
        }
    }
    if (w->tilt > 0.0f) {
        w->tilt -= 4.0f;
        if (w->tilt < 0.0f) {
            w->tilt = 0.0f;
        }
    } else {
        w->tilt += 4.0f;
        if (w->tilt > 0.0f) {
            w->tilt = 0.0f;
        }
    }
    omSetTra(obj, pos.x, pos.y, pos.z);
    func_800F93DC_HandcarHavoc(obj);
    func_800FF0AC_HandcarHavoc(w);
    func_800FCBA4_HandcarHavoc(obj);
    for (i = 0; i < 3; i++) {
        (&w->prevSlope.x)[i] = (&w->slope.x)[i];
        (&w->prevRot.x)[i] = (&w->rot.x)[i];
    }
    if (--w->stopTimer == 0) {
        if (w->sndOn == 1) {
            func_8006071C(w->snd);
            w->sndOn = 0;
        }
        if (D_800FF5D0_HandcarHavoc != 0) {
            obj->func_ptr = NULL;
            if ((u16)(D_80101CAA_HandcarHavoc - 8) >= 2 && D_80101CAA_HandcarHavoc != 6) {
                D_80101CAA_HandcarHavoc = 2;
            }
        } else {
            if (w->team != D_80101C90_HandcarHavoc) {
                obj->func_ptr = NULL;
                return;
            }
            for (i = 0; i < 2; i++) {
                func_80025C20(obj->model[3 + i], func_80025E48(obj->motion[9 + i]), 0, 20, 0);
                func_80025EB4(obj->model[3 + i], 3, 2);
            }
            obj->func_ptr = func_800FA8C0_HandcarHavoc;
        }
    } else if (w->team == D_80101C90_HandcarHavoc && fabs(w->speed) > 60.0) {
        func_800FCA58_HandcarHavoc(obj, 0);
        func_800FCA58_HandcarHavoc(obj, 1);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2F_HandcarHavoc/20F570", func_800FA3B8_HandcarHavoc);
#endif

/* The winners turn round and jump off the car. */
// NON_MATCHING: data addressed through a section base register
#ifdef NON_MATCHING
void func_800FA8C0_HandcarHavoc(omObjData* obj) {
    HHCar* w;
    f32 a;
    s32 i;

    w = obj->unk_50;
    func_800FF0AC_HandcarHavoc(w);
    switch (D_800FF3E0_HandcarHavoc) {
        case 0:
            a = D_800FF3E4_HandcarHavoc;
            for (i = 0; i < 2; i++) {
                if (i == 0) {
                    a = -a;
                }
                func_8009ECB0(D_800F2B7C[obj->model[3 + i]].unk7C, 0.0f, w->rot.y - a, 0.0f);
                if (D_800FF3E4_HandcarHavoc >= 90.0f) {
                    D_800FF3E0_HandcarHavoc = 1;
                    func_80025BB8(obj->model[3 + i], obj->motion[7 + i]);
                    func_800FD59C_HandcarHavoc(obj, i, &D_800FF598_HandcarHavoc[i]);
                    D_800FF580_HandcarHavoc[i].x = func_800AEAC0(w->rot.y - D_800FF3E4_HandcarHavoc) * 300.0f +
                                                   D_800FF598_HandcarHavoc[i].x;
                    D_800FF580_HandcarHavoc[i].y = obj->trans.y;
                    D_800FF580_HandcarHavoc[i].z = func_800AEFD0(w->rot.y - D_800FF3E4_HandcarHavoc) * 300.0f +
                                                   D_800FF598_HandcarHavoc[i].z;
                    D_800FF5C0_HandcarHavoc[i] = (D_800FF580_HandcarHavoc[i].y - D_800FF598_HandcarHavoc[i].y + 562.5f) /
                                                 (func_800AEAC0(70.0f) * 15.0f);
                    D_800FF5B0_HandcarHavoc[i] = func_800AEAC0(w->rot.y + 90.0f) * 300.0f / 15.0f;
                    D_800FF5B8_HandcarHavoc[i] = func_800AEFD0(w->rot.y + 90.0f) * 300.0f / 15.0f;
                    D_800FF5C8_HandcarHavoc = 0.0f;
                    D_800FF61C_HandcarHavoc[w->team]->func_ptr = func_800FB994_HandcarHavoc;
                }
            }
            D_800FF3E4_HandcarHavoc += 9.0f;
            break;
        case 1:
            D_800FF5C8_HandcarHavoc += 1.0f;
            for (i = 0; i < 2; i++) {
                func_80025798(obj->model[3 + i],
                              D_800FF5B0_HandcarHavoc[i] * D_800FF5C8_HandcarHavoc + D_800FF598_HandcarHavoc[i].x,
                              func_800AEAC0(70.0f) * D_800FF5C0_HandcarHavoc[i] * D_800FF5C8_HandcarHavoc -
                                  D_800FF5C8_HandcarHavoc * 2.5f * D_800FF5C8_HandcarHavoc +
                                  D_800FF598_HandcarHavoc[i].y,
                              D_800FF5B8_HandcarHavoc[i] * D_800FF5C8_HandcarHavoc + D_800FF598_HandcarHavoc[i].z);
            }
            if (D_800FF5C8_HandcarHavoc >= 15.0f) {
                for (i = 0; i < 2; i++) {
                    func_80025C20(obj->model[3 + i], func_80025E48(obj->motion[9 + i]), 0, 20, 0);
                    func_80025EB4(obj->model[3 + i], 3, 2);
                }
                D_800FF3E0_HandcarHavoc = 2;
                D_800FF3E4_HandcarHavoc = 90.0f;
            }
            break;
        case 2:
            a = D_800FF3E4_HandcarHavoc;
            for (i = 0; i < 2; i++) {
                if (i == 0) {
                    a = -a;
                }
                func_8009ECB0(D_800F2B7C[obj->model[3 + i]].unk7C, 0.0f, w->rot.y - a, 0.0f);
                if (D_800FF3E4_HandcarHavoc >= 180.0f) {
                    func_80025C20(obj->model[3 + i], func_80025E48(obj->motion[5 + i]), 0, 20, 0);
                    func_80025EB4(obj->model[3 + i], 3, 2);
                    D_80101CAA_HandcarHavoc = 2;
                    obj->func_ptr = NULL;
                }
            }
            D_800FF3E4_HandcarHavoc += 18.0f;
            break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2F_HandcarHavoc/20F570", func_800FA8C0_HandcarHavoc);
#endif

void func_800FAE64_HandcarHavoc(omObjData* obj) {
    s32 i;

    for (i = 0; i < 2; i++) {
        func_80025C20(obj->model[3 + i], func_80025E48(obj->motion[11 + i]), 0, 20, 0);
    }
    obj->func_ptr = NULL;
}

void func_800FAEE4_HandcarHavoc(omObjData* obj) {
    s32 i;

    for (i = 0; i < 2; i++) {
        func_80025C20(obj->model[3 + i], func_80025E48(obj->motion[13 + i]), 0, 20, 0);
    }
    obj->func_ptr = NULL;
}

void func_800FAF64_HandcarHavoc(omObjData* obj) {
    func_800FAF9C_HandcarHavoc(obj, 0);
}

void func_800FAF80_HandcarHavoc(omObjData* arg0) {
    func_800FAF9C_HandcarHavoc(arg0, 1);
}

/* A team's camera: behind the car. */
// NON_MATCHING: one reload of the camera yaw
#ifdef NON_MATCHING
void func_800FAF9C_HandcarHavoc(omObjData* obj, u16 team) {
    HHCam* c;
    HHCar* w;

    c = obj->unk_50 = func_80023684(sizeof(HHCam), 0x7918);
    c->cam = team;
    w = D_800FF618_HandcarHavoc[team]->unk_50;
    CRotM[team].x = c->rx = w->rot.x + w->rot.z - 25.0f;
    CRotM[team].y = c->ry = w->rot.y;
    CenterM[team].x = D_800FF618_HandcarHavoc[team]->trans.x - func_800AEAC0(c->ry) * 300.0f;
    CenterM[team].y = D_800FF618_HandcarHavoc[team]->trans.y;
    CenterM[team].z = D_800FF618_HandcarHavoc[team]->trans.z - func_800AEFD0(CRotM[team].y) * 300.0f;
    obj->func_ptr = func_800FB0EC_HandcarHavoc;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2F_HandcarHavoc/20F570", func_800FAF9C_HandcarHavoc);
#endif

/* Follows the car: pitch from the slope, yaw from the track. */
void func_800FB0EC_HandcarHavoc(omObjData* obj) {
    HHCam* c;
    omObjData* car;
    HHCar* w;
    f32 dy;
    f32 dx;
    f32 pitch;
    f32 yaw;
    f32 ry;
    u16 cam;

    c = obj->unk_50;
    cam = c->cam;
    car = D_800FF618_HandcarHavoc[cam];
    w = car->unk_50;
    pitch = -func_800FC7E0_HandcarHavoc(w->slope.y) - 25.0f;
    dx = pitch - c->rx;
    yaw = w->rot.y;
    if (yaw > 180.0f) {
        yaw -= 360.0f;
    }
    dy = yaw - c->ry;
    if (dx < 0.0f) {
        dx += 360.0f;
    }
    if (dx >= 360.0f) {
        dx -= 360.0f;
    }
    if (dy < 0.0f) {
        dy += 360.0f;
    }
    if (dy >= 360.0f) {
        dy -= 360.0f;
    }
    func_800FBFA0_HandcarHavoc(&dy, func_8009B618(fabs(w->rot.y - c->ry), 3.0) + 1.0);
    func_800FBFA0_HandcarHavoc(&dx, 1.0f);
    CRotM[cam].x += dx;
    if (dx > 0.0f) {
        if (pitch < CRotM[cam].x) {
            CRotM[cam].x = pitch;
        }
    } else if (CRotM[cam].x < pitch) {
        CRotM[cam].x = pitch;
    }
    CRotM[cam].y += dy;
    ry = CRotM[cam].y;
    if (ry > 180.0f) {
        ry -= 360.0f;
    }
    if (dy > 0.0f) {
        if (yaw < ry) {
            CRotM[cam].y = yaw;
        }
    } else if (ry < yaw) {
        CRotM[cam].y = yaw;
    }
    if (CRotM[cam].x < 0.0f) {
        CRotM[cam].x += 360.0f;
    }
    if (CRotM[cam].x >= 360.0f) {
        CRotM[cam].x -= 360.0f;
    }
    if (CRotM[cam].y < 0.0f) {
        CRotM[cam].y += 360.0f;
    }
    if (CRotM[cam].y >= 360.0f) {
        CRotM[cam].y -= 360.0f;
    }
    c->rx = CRotM[cam].x;
    c->ry = CRotM[cam].y;
    CenterM[cam].x = car->trans.x - func_800AEAC0(CRotM[cam].y) * 300.0f;
    CenterM[cam].y = car->trans.y;
    CenterM[cam].z = car->trans.z - func_800AEFD0(CRotM[cam].y) * 300.0f;
}

/* The camera of a fallen car: pulls out to the side. */
void func_800FB5DC_HandcarHavoc(omObjData* obj) {
    omObjData* cam;
    u16 team;

    team = ((HHCar*)obj->unk_50)->team;
    cam = D_800FF61C_HandcarHavoc[team];
    CZoomM[team] = 2000.0f;
    if (obj->work[0] & 0x20) {
        CRotM[team].y -= 90.0f;
    } else {
        CRotM[team].y += 90.0f;
    }
    if (CRotM[team].y < 0.0f) {
        CRotM[team].y += 360.0f;
    }
    if (CRotM[team].y >= 360.0f) {
        CRotM[team].y -= 360.0f;
    }
    CenterM[team].x = obj->trans.x - func_800AEAC0(CRotM[team].y) * 0.0f;
    CenterM[team].y = obj->trans.y;
    CenterM[team].z = obj->trans.z - func_800AEFD0(CRotM[team].y) * 0.0f;
    cam->func_ptr = func_800FB7DC_HandcarHavoc;
}

void func_800FB7DC_HandcarHavoc(omObjData* obj) {
}

void func_800FB7E4_HandcarHavoc(omObjData* arg0) {
    omObjData* temp_a0;

    temp_a0 = D_800FF61C_HandcarHavoc[((HHCar*)arg0->unk_50)->team];
    ((HHCam*)temp_a0->unk_50)->timer = 30;
    temp_a0->func_ptr = &func_800FB81C_HandcarHavoc;
}

/* The winners' camera swings round. */
void func_800FB81C_HandcarHavoc(omObjData* obj) {
    HHCam* c;
    omObjData* car;
    u16 cam;

    c = obj->unk_50;
    cam = c->cam;
    car = D_800FF618_HandcarHavoc[cam];
    CRotM[cam].y += 6.0f;
    CRotM[cam].x += 0.16666667f;
    CenterM[cam].x = car->trans.x - func_800AEAC0(CRotM[cam].y) * 300.0f;
    CenterM[cam].y = car->trans.y;
    CenterM[cam].z = car->trans.z - func_800AEFD0(CRotM[cam].y) * 300.0f;
    CZoomM[cam] += 6.6666665f;
    if (--c->timer == 0) {
        c->timer = 15;
        obj->func_ptr = NULL;
    }
}

// NON_MATCHING: retail computes the camera index once
#ifdef NON_MATCHING
void func_800FB994_HandcarHavoc(omObjData* obj) {
    HHCam* c;

    c = obj->unk_50;
    CenterM[c->cam].x = func_800AEAC0(CRotM[c->cam].y - 90.0f) * 20.0f + CenterM[c->cam].x;
    CenterM[c->cam].z = func_800AEFD0(CRotM[c->cam].y - 90.0f) * 20.0f + CenterM[c->cam].z;
    if (--c->timer == 0) {
        obj->func_ptr = NULL;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2F_HandcarHavoc/20F570", func_800FB994_HandcarHavoc);
#endif

/* Intro: instructions, then "Start". */
void func_800FBA80_HandcarHavoc(omObjData* obj) {
    s32 i;

    switch (D_80101CA4_HandcarHavoc) {
        case 0:
            if (func_80072718() == 0) {
                D_80101CA4_HandcarHavoc = 1;
                GMesCreate(13);
            }
            break;
        case 1:
            if (GMesStatAllGet() == 0 || (GMesStatAllGet() & 2)) {
                D_80101C8A_HandcarHavoc = 1;
                omDelObj(obj);
                D_800FF624_HandcarHavoc = NULL;
                for (i = 0; i < 2; i++) {
                    D_800FF62C_HandcarHavoc->work[i] = 1;
                }
            }
            break;
    }
    if (D_800FF3E8_HandcarHavoc == 0) {
        func_80060128(38);
    }
    D_800FF3E8_HandcarHavoc--;
}

/* The end: messages, coins, the record, leaving. */
// NON_MATCHING: register allocation; the winners array spills
#ifdef NON_MATCHING
void func_800FBB78_HandcarHavoc(omObjData* obj) {
    s32 pl[2];
    HHCar* loser;
    s32 i;
    s32 snd;

    switch ((u16)D_80101CAA_HandcarHavoc) {
        case 0:
            D_80101CAA_HandcarHavoc = 1;
            func_800601D4(40);
            if (D_800FF5D0_HandcarHavoc == 0) {
                GMesCreate(18);
            } else if ((u16)D_80101CA8_HandcarHavoc == 0) {
                GMesCreate(2);
            } else {
                GMesCreate(12);
            }
            break;
        case 2:
            if (GMesStatAllGet() == 0 || (GMesStatAllGet() & 2)) {
                for (i = 0; i < 2; i++) {
                    pl[i] = (u16)((HHCar*)D_800FF618_HandcarHavoc[D_80101C90_HandcarHavoc]->unk_50)->player[i];
                }
                GwPlayer[pl[0]].coins_mg += 10;
                GwPlayer[pl[1]].coins_mg += 10;
                loser = D_800FF618_HandcarHavoc[(s16)((u16)D_80101C90_HandcarHavoc ^ 1)]->unk_50;
                if (D_800FF5D0_HandcarHavoc == 0) {
                    D_800FF618_HandcarHavoc[(s16)D_80101C90_HandcarHavoc]->func_ptr = func_800FAE64_HandcarHavoc;
                    D_800FF618_HandcarHavoc[(s16)((u16)D_80101C90_HandcarHavoc ^ 1)]->func_ptr =
                        func_800FAEE4_HandcarHavoc;
                    for (i = 0; i < 2; i++) {
                        if (GwPlayer[(u16)loser->player[i]].coins < 10) {
                            GwPlayer[(u16)loser->player[i]].coins_mg -= GwPlayer[(u16)loser->player[i]].coins;
                        } else {
                            GwPlayer[(u16)loser->player[i]].coins_mg -= 10;
                        }
                    }
                    D_800FF5CC_HandcarHavoc.timer = 105;
                    if ((u16)D_80101CA8_HandcarHavoc == 1) {
                        D_800FF5CC_HandcarHavoc.delay = 30;
                        snd = 0x37;
                    } else {
                        D_800FF5CC_HandcarHavoc.delay = 0;
                        snd = 0x36;
                    }
                    func_80060128(snd);
                    D_80101CAA_HandcarHavoc = 4;
                } else {
                    D_80101CAA_HandcarHavoc = 9;
                }
            }
            break;
        case 3:
            if (GMesStatAllGet() & 2) {
                func_80060128(0x34);
                D_80101CAA_HandcarHavoc = 4;
            }
            break;
        case 4:
            if (D_800FF5CC_HandcarHavoc.delay != 0 && --D_800FF5CC_HandcarHavoc.delay == 0) {
                GMesCreate(12);
                D_800FF5CC_HandcarHavoc.timer = 120;
            }
            if (--D_800FF5CC_HandcarHavoc.timer == 0) {
                D_80101CAA_HandcarHavoc = 5;
                func_800726AC(0, 20);
            }
            break;
        case 5:
            if (func_80072718() == 0) {
                D_800FF400_HandcarHavoc = 1;
            }
            break;
        case 6:
            if (D_800FF5D0_HandcarHavoc == 0) {
                GMesCreate(17);
                D_800FF5CC_HandcarHavoc.timer = 90;
                D_80101CAA_HandcarHavoc = 3;
                break;
            }
            GMesCreate(2);
            D_80101CAA_HandcarHavoc = 9;
            break;
        case 7:
            if (D_800FF5D0_HandcarHavoc == 0) {
                GMesCreate(16);
                D_800FF5CC_HandcarHavoc.timer = 120;
                D_80101CAA_HandcarHavoc = 3;
                break;
            }
        case 8:
            GMesCreate(2);
            D_80101CAA_HandcarHavoc = 9;
            break;
        case 9:
            if (GMesWait() != 1) {
                D_80101CAA_HandcarHavoc = 5;
                func_800726AC(0, 20);
            }
            break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2F_HandcarHavoc/20F570", func_800FBB78_HandcarHavoc);
#endif

void func_800FBF5C_HandcarHavoc(omObjData* obj) {
    if ((u16)D_800FF400_HandcarHavoc != 0 || D_800F5144 != 0) {
        func_800FD1E8_HandcarHavoc(0x83);
        func_800601D4(40);
    }
}

/* Clamps an angle difference to +-step (the short way round). */
void func_800FBFA0_HandcarHavoc(f32* a, f32 step) {
    if (*a < 0.0f) {
        *a += 360.0f;
    }
    if (*a < 180.0f) {
        if (step < *a) {
            *a = step;
        }
    } else if (step < 360.0f - *a) {
        *a = -step;
    } else {
        *a = -(360.0f - *a);
    }
}

void func_800FC058_HandcarHavoc(void) {
    s32 i;

    D_800FF614_HandcarHavoc = 0.0f;
    for (i = 0; i < D_800FF610_HandcarHavoc - 1; i++) {
        D_800FF614_HandcarHavoc += func_800FC1B4_HandcarHavoc(i);
    }
}

void func_800FC0C8_HandcarHavoc(u16 i, Vec* out) {
    HHColVtx* p;

    p = &D_800FF60C_HandcarHavoc[i];
    out->x = p->x;
    out->y = p->y;
    out->z = p->z;
}

/* Midpoint of track segment i. */
void func_800FC124_HandcarHavoc(u16 i, Vec* out) {
    Vec a;
    Vec b;

    func_800FC0C8_HandcarHavoc(i, &a);
    func_800FC0C8_HandcarHavoc(i + 1, &b);
    out->x = (a.x + b.x) * 0.5f;
    out->y = (a.y + b.y) * 0.5f;
    out->z = (a.z + b.z) * 0.5f;
}

/* Length of track segment i. */
// NON_MATCHING: register allocation
// decomp-permuter
f32 func_800FC1B4_HandcarHavoc(u16 i)
{
  f32 dy;
  Vec a;
  float new_var3;
  f32 new_var2;
  float new_var;
  Vec b;
  f32 dx;
  f32 dz;
  func_800FC0C8_HandcarHavoc(i, &a);
  func_800FC0C8_HandcarHavoc(i + 1, &b);
  dx = b.x - a.x;
  new_var3 = dx * dx;
  dy = b.y - a.y;
  new_var = new_var3 + (dy * dy);
  dz = b.z - a.z;
  new_var2 = func_800B1750(new_var + (dz * dz));
  return new_var2;
}

/* Distance from (x, y, z) to track point i. */
// NON_MATCHING: register allocation
// decomp-permuter
f32 func_800FC22C_HandcarHavoc(f32 x, f32 y, f32 z, u16 i)
{
  Vec a;
  f32 dx;
  f32 dy;
  f32 dz;
  float new_var;
  func_800FC0C8_HandcarHavoc(i, &a);
  dx = a.x - x;
  ;
  new_var = (dx * dx) + ((a.y - y) * (a.y - y));
  dz = a.z - z;
  return func_800B1750(new_var + (dz * dz));
}

/* Direction of track segment i. */
void func_800FC2A0_HandcarHavoc(u16 i, Vec* out) {
    Vec a;
    Vec b;
    f32 len;

    func_800FC0C8_HandcarHavoc(i, &a);
    func_800FC0C8_HandcarHavoc(i + 1, &b);
    len = func_800FC1B4_HandcarHavoc(i);
    out->x = (b.x - a.x) / len;
    out->y = (b.y - a.y) / len;
    out->z = (b.z - a.z) / len;
}

/* The car's position (between its axles) and rotation (from the axle line). */
// NON_MATCHING: axle distances reloaded
// decomp-permuter
void func_800FC338_HandcarHavoc(omObjData *obj, Vec *rot, Vec *pos)
{
  Vec axle[2];
  Vec d;
  Vec p;
  f32 new_var;
  HHCar *w;
  f32 a;
  u16 seg;
  s32 i;
  w = obj->unk_50;
  for (i = 0; i < 2; i++)
  {
    seg = w->seg[i];
    func_800FC0C8_HandcarHavoc(seg, &p);
    func_800FC2A0_HandcarHavoc(seg, &axle[i]);
    new_var = w->dist[i];
    axle[i].x = (new_var * axle[i].x) + p.x;
    axle[i].y = (new_var * axle[i].y) + p.y;
    axle[i].z = (new_var * axle[i].z) + p.z;
  }

  for (i = 0; i < 3; i++)
  {
    (&w->slope.x)[i] = ((&d.x)[i] = ((&axle[1].x)[i] - (&axle[0].x)[i]) / 400.0f);
    (&pos->x)[i] = ((&axle[1].x)[i] + (&axle[0].x)[i]) / 2.0f;
  }

  rot->y = func_800B0CD8(d.x, d.z);
  a = func_800FC7E0_HandcarHavoc(d.y);
  rot->x = a * (-d.z);
  rot->z = a * d.x;
}

/* Moves both axles along the track by the car's speed; 1 when the front reaches the goal. */
u16 func_800FC4B0_HandcarHavoc(omObjData* obj) {
    Vec d;
    Vec p;
    HHCar* w;
    f32 speed;
    f32 len;
    u16 goal;
    s32 i;

    w = obj->unk_50;
    speed = w->speed;
    goal = 0;
    if (speed == 0.0f) {
        return 0;
    }
    w->progress -= speed;
    for (i = 0; i < 2; i++) {
        w->dist[i] -= speed;
        func_800FC2A0_HandcarHavoc(w->seg[i], &d);
        func_800FC0C8_HandcarHavoc(w->seg[i], &p);
        d.x = d.x * w->dist[i] + p.x;
        d.y = d.y * w->dist[i] + p.y;
        d.z = d.z * w->dist[i] + p.z;
        if (speed < 0.0f) {
            len = func_800FC1B4_HandcarHavoc(w->seg[i]);
            while (len < w->dist[i]) {
                w->seg[i]++;
                if (w->seg[i] == D_800FF610_HandcarHavoc - 2) {
                    D_800FF62C_HandcarHavoc->work[0] = 0;
                    D_800FF62C_HandcarHavoc->work[1] = 0;
                    goal = 1;
                }
                w->dist[i] -= len;
                len = func_800FC1B4_HandcarHavoc(w->seg[i]);
                func_800FC2A0_HandcarHavoc(w->seg[i], &d);
                func_800FC0C8_HandcarHavoc(w->seg[i], &p);
                d.x = d.x * w->dist[i] + p.x;
                d.y = d.y * w->dist[i] + p.y;
                d.z = d.z * w->dist[i] + p.z;
            }
        } else {
            len = func_800FC1B4_HandcarHavoc(w->seg[i] - 1);
            while (w->dist[i] < 0.0f) {
                w->seg[i]--;
                w->dist[i] = len + w->dist[i];
                len = func_800FC1B4_HandcarHavoc(w->seg[i]);
                func_800FC2A0_HandcarHavoc(w->seg[i], &d);
                func_800FC0C8_HandcarHavoc(w->seg[i], &p);
                d.x = d.x * w->dist[i] + p.x;
                d.y = d.y * w->dist[i] + p.y;
                d.z = d.z * w->dist[i] + p.z;
            }
        }
    }
    return goal;
}

/* asin in degrees, clamped to [-1, 1]. */
f32 func_800FC7E0_HandcarHavoc(f32 x) {
    if (x > 1.0f) {
        x = 1.0f;
    } else if (x < -1.0f) {
        x = -1.0f;
    }
    return (f32)func_8009AFD0(x) / 3.141592653589793 * 180.0;
}

/* The race's winner: the car nearer the goal; saves a new record. */
u16 func_800FC85C_HandcarHavoc(void) {
    f32 dist[2];
    HHCar* w;
    HHTimer* t;
    s16 win;
    s32 i;

    for (i = 0; i < 2; i++) {
        w = D_800FF618_HandcarHavoc[i]->unk_50;
        dist[i] = func_800FC22C_HandcarHavoc(
            D_800FF618_HandcarHavoc[i]->trans.x + func_800AEAC0(w->rot.y) * D_800FF3B8_HandcarHavoc[0],
            D_800FF618_HandcarHavoc[i]->trans.y,
            D_800FF618_HandcarHavoc[i]->trans.z + func_800AEFD0(w->rot.y) * D_800FF3B8_HandcarHavoc[0],
            D_800FF610_HandcarHavoc - 2);
        if (w->seg[0] < (s16)D_800FF610_HandcarHavoc - 2) {
            dist[i] = -dist[i];
        }
    }
    if (dist[0] > dist[1]) {
        win = 0;
    } else {
        win = 0;
        if (dist[0] < dist[1]) {
            win = 1;
        }
    }
    t = D_800FF62C_HandcarHavoc->unk_50;
    if (t->record > t->time) {
        t->record = t->time;
        w = D_800FF618_HandcarHavoc[win]->unk_50;
        if (!(GwPlayer[w->player[0]].flags & 1) || !(GwPlayer[w->player[1]].flags & 1)) {
            func_800594E4(3, t->record);
            D_80101CA8_HandcarHavoc = 1;
        }
    }
    return win;
}

/* Sparks from one side's wheels. */
void func_800FCA58_HandcarHavoc(omObjData* obj, u16 side) {
    Vec spot[2];
    HHCar* w;
    s16 mdl;
    s32 k;

    w = obj->unk_50;
    func_800FD888_HandcarHavoc(obj, side, spot);
    for (k = 0; k < 2; k++) {
        if (w->chips[side][k] < D_800FF3C0_HandcarHavoc[side][k]) {
            mdl = func_800FECF4_HandcarHavoc(w->team, side, k);
            w->chips[side][k]++;
            if (mdl != -1) {
                func_80025798(mdl, (spot + k)->x, (spot + k)->y, (spot + k)->z);
                func_8009ECB0(D_800F2B7C[mdl].unk7C, 0.0f, w->rot.y, 0.0f);
                func_800257E4(mdl, w->rot.x, 0.0f, w->rot.z);
            }
        }
    }
}

/* The car's marker and the riders' faces on the map. */
void func_800FCBA4_HandcarHavoc(omObjData* obj) {
    HHCar* w;
    s32 x;
    u32 y;

    w = obj->unk_50;
    x = 168;
    if (w->team == 0) {
        x = 152;
    }
    y = 176.0f - w->progress / D_800FF614_HandcarHavoc * 144.0f;
    SetBasicSpritePos(w->marker, x, y + 8);
    SetBasicSpritePos(w->face[0], x, y + 18);
    SetBasicSpritePos(w->face[1], x, y - 2);
}

/* The backgrounds follow the cameras' pitch. */
void func_800FCCA4_HandcarHavoc(omObjData* obj) {
    f32 a;
    s32 i;

    for (i = 0; i < 2; i++) {
        a = CRotM[i].x;
        if (a <= 180.0f) {
            a += 360.0f;
        }
        D_800FF3EC_HandcarHavoc[i] = (a - 335.0f) * 2.5f - 70.0f;
        if (D_800FF630_HandcarHavoc[i].v < D_800FF3EC_HandcarHavoc[i]) {
            D_800FF630_HandcarHavoc[i].v += 1.5f;
            if (D_800FF3EC_HandcarHavoc[i] < D_800FF630_HandcarHavoc[i].v) {
                D_800FF630_HandcarHavoc[i].v = D_800FF3EC_HandcarHavoc[i];
            }
        }
        if (D_800FF3EC_HandcarHavoc[i] < D_800FF630_HandcarHavoc[i].v) {
            D_800FF630_HandcarHavoc[i].v -= 1.5f;
        }
        if (D_800FF630_HandcarHavoc[i].v < D_800FF3EC_HandcarHavoc[i]) {
            D_800FF630_HandcarHavoc[i].v = D_800FF3EC_HandcarHavoc[i];
        }
    }
    func_800FE004_HandcarHavoc(D_800FF630_HandcarHavoc);
}

/* The race timer and the record (two rows of digits). */
void func_800FCE3C_HandcarHavoc(omObjData* obj) {
    HHTimer* t;
    s32 i;
    s16 x;

    t = obj->unk_50 = func_80023684(sizeof(HHTimer), 0x7918);
    t->record = func_800594FC(3);
    t->time = 0;
    obj->work[1] = 0;
    obj->work[0] = 0;
    x = 127;
    for (i = 0; i < 7; i++) {
        t->digit[i] = func_80019060(D_80101C88_HandcarHavoc, 0, 1);
        SetBasicSpritePos(t->digit[i], x, 220);
        func_80018DC4(t->digit[i], 0);
        t->best[i] = func_80019060(D_80101CAE_HandcarHavoc, 0, 1);
        SetBasicSpritePos(t->best[i], x, 208);
        func_80018DC4(t->best[i], 0);
        if (i == 0) {
            x += 8;
        } else {
            x += 12;
        }
    }
    func_80018E50(t->digit[1], 10, 0);
    func_80018E50(t->digit[4], 11, 0);
    func_80018E50(t->best[1], 10, 0);
    func_80018E50(t->best[4], 11, 0);
    func_800FCFFC_HandcarHavoc(t->record, t->best);
    obj->func_ptr = func_800FCFB4_HandcarHavoc;
}

void func_800FCFB4_HandcarHavoc(omObjData* obj) {
    HHTimer* t;

    t = obj->unk_50;
    if (obj->work[0] == 1 || obj->work[1] == 1) {
        t->time += 2;
        func_800FCFFC_HandcarHavoc(t->time, t->digit);
    }
}

/* m'ss"cc */
// NON_MATCHING: retail walks the digit array with pointer increments
#ifdef NON_MATCHING
void func_800FCFFC_HandcarHavoc(u16 time, u16* digit) {
    u16 rest;
    u16 sec;
    u16 cs;

    func_80018E50(digit[0], time / 3600, 0);
    rest = time % 3600;
    sec = rest / 60;
    func_80018E50(digit[2], sec / 10, 0);
    func_80018E50(digit[3], sec % 10, 0);
    cs = (u16)(rest % 60) * 1.6666666f;
    func_80018E50(digit[5], cs / 10, 0);
    func_80018E50(digit[6], cs % 10, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2F_HandcarHavoc/20F570", func_800FCFFC_HandcarHavoc);
#endif
