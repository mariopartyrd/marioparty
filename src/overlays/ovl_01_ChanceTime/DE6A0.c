#include "ChanceTime.h"

/* defined as func_80055994(s32) in 54120.c; retail passes a second argument (1), as ovl_65 does */
void func_80055994(s32, s32);


/* .data (0x80101370..0x80101380) */
s8 D_80101370_ChanceTime = 0;
void* D_80101374_ChanceTime = NULL;
s8 D_80101378_ChanceTime = 0;
s8 D_80101379_ChanceTime = 0;

void func_800FFAA0_ChanceTime(void) {
    s8 idx[2];
    Vec mid;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_8010183C_ChanceTime == D_80101AAE_ChanceTime[i]) {
            break;
        }
    }
    idx[0] = i;
    for (i = 0; i < 4; i++) {
        if (D_8010183D_ChanceTime == D_80101AAE_ChanceTime[i]) {
            break;
        }
    }
    idx[1] = i;
    D_80101824_ChanceTime.x = D_800F3FB0[idx[1]]->trans.x;
    D_80101824_ChanceTime.y = D_800F3FB0[idx[1]]->trans.y;
    D_80101824_ChanceTime.z = D_800F3FB0[idx[1]]->trans.z;
    D_80101830_ChanceTime.x = D_800F3FB0[idx[0]]->trans.x;
    D_80101830_ChanceTime.y = D_800F3FB0[idx[0]]->trans.y;
    D_80101830_ChanceTime.z = D_800F3FB0[idx[0]]->trans.z;
    D_8010179C_ChanceTime[0].x = D_80101824_ChanceTime.x;
    D_8010179C_ChanceTime[0].y = D_80101824_ChanceTime.y;
    D_8010179C_ChanceTime[0].z = D_80101824_ChanceTime.z;
    D_801017E4_ChanceTime[0].x = D_80101830_ChanceTime.x;
    D_801017E4_ChanceTime[0].y = D_80101830_ChanceTime.y;
    D_801017E4_ChanceTime[0].z = D_80101830_ChanceTime.z;
    mid.x = (D_800F32A0->coords.x + D_80101830_ChanceTime.x) / 2.0f;
    mid.y = (D_800F32A0->coords.y + D_80101830_ChanceTime.y) / 2.0f;
    mid.z = (D_800F32A0->coords.z + D_80101830_ChanceTime.z) / 2.0f;
    func_8004CCD0((Vec3f*)&D_8010179C_ChanceTime[0], (Vec3f*)&mid, (Vec3f*)&D_8010179C_ChanceTime[1]);
    func_8004CCD0((Vec3f*)&D_801017E4_ChanceTime[0], (Vec3f*)&D_8010179C_ChanceTime[0],
                  (Vec3f*)&D_801017E4_ChanceTime[1]);
    func_80060F04(D_8010183D_ChanceTime, 2, 2, 20);
    func_800500A4();
    PlaySound(0x44);
    MBModelInit();
    D_80101820_ChanceTime = MBModelCreate(0x40, NULL);
    func_800A0D00(&D_80101820_ChanceTime->coords, D_80101824_ChanceTime.x, D_80101824_ChanceTime.y + 200.0f,
                  D_80101824_ChanceTime.z);
    func_800A0D00((Vec3f*)&D_80101820_ChanceTime->xScale, 0.5f, 0.5f, 0.5f);
    D_80101374_ChanceTime = func_80042728(D_80101820_ChanceTime, 0);
    for (i = 0; i < 181; i += 5) {
        func_800A0D00(&D_80101820_ChanceTime->coords,
                      D_80101824_ChanceTime.x + (D_80101830_ChanceTime.x - D_80101824_ChanceTime.x) * i / 180.0f,
                      D_80101824_ChanceTime.y + 200.0f + sinf(i * 0.017453292519943295) * 100.0f,
                      D_80101824_ChanceTime.z + (D_80101830_ChanceTime.z - D_80101824_ChanceTime.z) * i / 180.0);
        D_80101820_ChanceTime->unk_18.x = sinf(i * 10 * 0.017453292519943295);
        D_80101820_ChanceTime->unk_18.z = cosf(i * 10 * 0.017453292519943295);
        HuPrcVSleep();
    }
    PlaySound(0x474);
    func_80055994(D_8010183C_ChanceTime, 1);
    MBModelKill(D_80101820_ChanceTime);
    D_80101820_ChanceTime = NULL;
    func_800427D4(D_80101374_ChanceTime);
    D_80101374_ChanceTime = NULL;
    func_8004CCD0((Vec3f*)&D_801017E4_ChanceTime[0], &D_800F32A0->coords, (Vec3f*)&D_801017E4_ChanceTime[1]);
    D_80101370_ChanceTime = 1;
    GwPlayer[D_8010183C_ChanceTime].stars++;
    GwPlayer[D_8010183D_ChanceTime].stars--;
    HuPrcSleep(36);
    func_80060468(0x443, GwPlayer[D_8010183C_ChanceTime].character);
    HuPrcSleep(48);
    func_80050160();
    D_801011F9_ChanceTime = 1;
    while (1) {
        HuPrcVSleep();
    }
}
s8 func_800FFF4C_ChanceTime(s8 arg0, s8 arg1) {
    if (D_80101378_ChanceTime == 0) {
        D_8010183C_ChanceTime = arg0;
        D_8010183D_ChanceTime = arg1;
        D_801011F9_ChanceTime = 0;
        omAddPrcObj(&func_800FFAA0_ChanceTime, 0x300, 0x800, 0);
        D_80101378_ChanceTime = 1;
    }
    return D_80101370_ChanceTime;
}

// loop-invariant motion: the coin loop's 0.0f arguments are hoisted into an FPR; the tie loop's
// (f32)i is computed before the call (retail: inside its arguments, which the host may order
// differently) - masked 5 besides the address shift
#ifdef NON_MATCHING
void func_800FFFB0_ChanceTime(void) {
    s8 idx[2];
    s8 pl[2];
    Vec mid;
    f32 prog[2];
    s16 stars[2];
    s16 step[2];
    CTCoin* coins[2];
    s8 tie;
    s32 i;
    s32 side;
    s16 count;
    s32 v;
    CTCoin* c;
    CTCoin* p;
    f32 rot;
    f32 rad;
    f32 t;

    HuPrcSleep(20);
    if (GwPlayer[D_801012E0_ChanceTime].stars == GwPlayer[D_801012E1_ChanceTime].stars) {
        tie = 1;
        pl[0] = D_801012E0_ChanceTime;
        pl[1] = D_801012E1_ChanceTime;
    } else {
        tie = 0;
        if (GwPlayer[D_801012E0_ChanceTime].stars < GwPlayer[D_801012E1_ChanceTime].stars) {
            pl[0] = D_801012E0_ChanceTime;
            pl[1] = D_801012E1_ChanceTime;
        } else {
            pl[0] = D_801012E1_ChanceTime;
            pl[1] = D_801012E0_ChanceTime;
        }
    }
    stars[0] = GwPlayer[D_801012E0_ChanceTime].stars;
    stars[1] = GwPlayer[D_801012E1_ChanceTime].stars;
    for (i = 0; i < 4; i++) {
        if (pl[0] == D_80101AAE_ChanceTime[i]) {
            break;
        }
    }
    idx[0] = i;
    for (i = 0; i < 4; i++) {
        if (pl[1] == D_80101AAE_ChanceTime[i]) {
            break;
        }
    }
    idx[1] = i;
    D_80101824_ChanceTime.x = D_800F3FB0[idx[1]]->trans.x;
    D_80101824_ChanceTime.y = D_800F3FB0[idx[1]]->trans.y;
    D_80101824_ChanceTime.z = D_800F3FB0[idx[1]]->trans.z;
    D_80101830_ChanceTime.x = D_800F3FB0[idx[0]]->trans.x;
    D_80101830_ChanceTime.y = D_800F3FB0[idx[0]]->trans.y;
    D_80101830_ChanceTime.z = D_800F3FB0[idx[0]]->trans.z;
    D_8010179C_ChanceTime[0].x = D_80101824_ChanceTime.x;
    D_8010179C_ChanceTime[0].y = D_80101824_ChanceTime.y;
    D_8010179C_ChanceTime[0].z = D_80101824_ChanceTime.z;
    D_801017E4_ChanceTime[0].x = D_80101830_ChanceTime.x;
    D_801017E4_ChanceTime[0].y = D_80101830_ChanceTime.y;
    D_801017E4_ChanceTime[0].z = D_80101830_ChanceTime.z;
    mid.x = (D_800F32A0->coords.x + D_80101830_ChanceTime.x) / 2.0f;
    mid.y = (D_800F32A0->coords.y + D_80101830_ChanceTime.y) / 2.0f;
    mid.z = (D_800F32A0->coords.z + D_80101830_ChanceTime.z) / 2.0f;
    func_8004CCD0((Vec3f*)&D_8010179C_ChanceTime[0], (Vec3f*)&mid, (Vec3f*)&D_8010179C_ChanceTime[1]);
    func_8004CCD0((Vec3f*)&D_801017E4_ChanceTime[0], (Vec3f*)&D_8010179C_ChanceTime[0],
                  (Vec3f*)&D_801017E4_ChanceTime[1]);
    for (i = 0; i < D_8010183E_ChanceTime[0]; i++) {
        D_80101868_ChanceTime[i].unk_00 = D_80101AD8_ChanceTime->model[21 + i];
        D_80101868_ChanceTime[i].unk_04 = D_800F3FB0[D_80101AA4_ChanceTime[0]]->trans.x;
        D_80101868_ChanceTime[i].unk_08 = D_800F3FB0[D_80101AA4_ChanceTime[0]]->trans.y + 140.0f;
        D_80101868_ChanceTime[i].unk_0C = D_800F3FB0[D_80101AA4_ChanceTime[0]]->trans.z;
        D_80101868_ChanceTime[i].unk_10 = 0.0f;
        D_80101868_ChanceTime[i].unk_14 = 0.0f;
        D_80101868_ChanceTime[i].unk_18 = 1;
        D_80101868_ChanceTime[i].unk_19 = 0;
    }
    for (i = 0; i < D_8010183E_ChanceTime[1]; i++) {
        D_80101868_ChanceTime[D_8010183E_ChanceTime[0] + i].unk_00 =
            D_80101AD8_ChanceTime->model[21 + D_8010183E_ChanceTime[0] + i];
        D_80101868_ChanceTime[D_8010183E_ChanceTime[0] + i].unk_04 = D_800F3FB0[D_80101AA4_ChanceTime[1]]->trans.x;
        D_80101868_ChanceTime[D_8010183E_ChanceTime[0] + i].unk_08 =
            D_800F3FB0[D_80101AA4_ChanceTime[1]]->trans.y + 140.0f;
        D_80101868_ChanceTime[D_8010183E_ChanceTime[0] + i].unk_0C = D_800F3FB0[D_80101AA4_ChanceTime[1]]->trans.z;
        D_80101868_ChanceTime[D_8010183E_ChanceTime[0] + i].unk_10 = 0.0f;
        D_80101868_ChanceTime[D_8010183E_ChanceTime[0] + i].unk_14 = 0.0f;
        D_80101868_ChanceTime[D_8010183E_ChanceTime[0] + i].unk_18 = 1;
        D_80101868_ChanceTime[D_8010183E_ChanceTime[0] + i].unk_19 = 0;
    }
    prog[0] = prog[1] = 0.0f;
    if (GwPlayer[D_801012E0_ChanceTime].stars <= D_8010183E_ChanceTime[0]) { v = 1; } else { v = GwPlayer[D_801012E0_ChanceTime].stars / D_8010183E_ChanceTime[0]; }
    step[0] = v;
    if (GwPlayer[D_801012E1_ChanceTime].stars <= D_8010183E_ChanceTime[1]) { v = 1; } else { v = GwPlayer[D_801012E1_ChanceTime].stars / D_8010183E_ChanceTime[1]; }
    step[1] = v;
    if (tie != 1) {
        func_80060F04(pl[1], 30, 0, 30);
    }
    coins[0] = D_80101868_ChanceTime;
    coins[1] = &D_80101868_ChanceTime[D_8010183E_ChanceTime[0]];
    do {
        count = 0;
        for (side = 0; side < 2; side++) {
            c = coins[side];
            i = 0;
            while (i < (s32)prog[side]) {
                p = &c[i];
                if (p->unk_19 == 0) {
                    if (p->unk_18 == 1) {
                        func_800258EC(p->unk_00, 4, 0);
                        p->unk_08 += 10.0f;
                        if (D_800F3FB0[idx[side]]->trans.y + 200.0f <= p->unk_08) {
                            p->unk_19 = 1;
                        }
                        p = &c[i++];
                        func_80025798(p->unk_00, p->unk_04, p->unk_08, p->unk_0C);
                        func_800257E4(p->unk_00, 90.0f, 0.0f, 0.0f);
                        continue;
                    }
                } else {
                    count++;
                }
                i++;
            }
            GwPlayer[D_801012E0_ChanceTime].stars -= step[0];
            GwPlayer[D_801012E1_ChanceTime].stars -= step[1];
            if (GwPlayer[D_801012E0_ChanceTime].stars < 0) {
                GwPlayer[D_801012E0_ChanceTime].stars = 0;
            }
            if (GwPlayer[D_801012E1_ChanceTime].stars < 0) {
                GwPlayer[D_801012E1_ChanceTime].stars = 0;
            }
            prog[side] += 0.4;
            if ((s32)prog[side] > D_8010183E_ChanceTime[side]) {
                prog[side] = D_8010183E_ChanceTime[side];
            }
        }
        HuPrcVSleep();
    } while (count < D_8010183E_ChanceTime[0] + D_8010183E_ChanceTime[1]);
    GwPlayer[D_801012E0_ChanceTime].stars = 0;
    GwPlayer[D_801012E1_ChanceTime].stars = 0;
    HuPrcSleep(20);
    if (tie == 0) {
        func_800500A4();
        PlaySound(0x44);
        MBModelInit();
        D_80101820_ChanceTime = MBModelCreate(0x40, NULL);
        func_800A0D00(&D_80101820_ChanceTime->coords, D_80101824_ChanceTime.x, D_80101824_ChanceTime.y + 200.0f,
                      D_80101824_ChanceTime.z);
        func_800A0D00((Vec3f*)&D_80101820_ChanceTime->xScale, 0.5f, 0.5f, 0.5f);
        D_80101374_ChanceTime = func_80042728(D_80101820_ChanceTime, 0);
        for (i = 0; i < D_8010183E_ChanceTime[0] + D_8010183E_ChanceTime[1]; i++) {
            func_800258EC(D_80101868_ChanceTime[i].unk_00, 4, 4);
        }
        if (D_8010183E_ChanceTime[0] != 0 && D_8010183E_ChanceTime[1] != 0) {
            func_800258EC(D_80101868_ChanceTime[0].unk_00, 4, 0);
            func_800257E4(D_80101868_ChanceTime[0].unk_00, 90.0f, 0.0f, 0.0f);
        }
        rot = 0.0f;
        for (i = 0; i < 181; i += 5) {
            func_800A0D00(&D_80101820_ChanceTime->coords,
                          (D_80101830_ChanceTime.x - D_80101824_ChanceTime.x) * i / 180.0f + D_80101824_ChanceTime.x,
                          D_80101824_ChanceTime.y + 200.0f + sinf(i * 0.017453292519943295) * 100.0f,
                          D_80101824_ChanceTime.z + (D_80101830_ChanceTime.z - D_80101824_ChanceTime.z) * i / 180.0);
            func_80025798(D_80101868_ChanceTime[0].unk_00,
                          (D_80101824_ChanceTime.x - D_80101830_ChanceTime.x) * i / 180.0f + D_80101830_ChanceTime.x,
                          D_80101830_ChanceTime.y + 200.0f + sinf(i * 0.017453292519943295) * 50.0f,
                          D_80101830_ChanceTime.z + (D_80101824_ChanceTime.z - D_80101830_ChanceTime.z) * i / 180.0);
            rot += 20.0f;
            func_800257E4(D_80101868_ChanceTime[0].unk_00, 90.0f, rot, 0.0f);
            D_80101820_ChanceTime->unk_18.x = sinf(i * 10 * 0.017453292519943295);
            D_80101820_ChanceTime->unk_18.z = cosf(i * 10 * 0.017453292519943295);
            HuPrcVSleep();
        }
        PlaySound(0x474);
        func_80055994(pl[0], 1);
        MBModelKill(D_80101820_ChanceTime);
        D_80101820_ChanceTime = NULL;
        func_800427D4(D_80101374_ChanceTime);
        D_80101374_ChanceTime = NULL;
        if (D_8010183E_ChanceTime[0] != 0 && D_8010183E_ChanceTime[1] != 0) {
            func_800258EC(D_80101868_ChanceTime[0].unk_00, 4, 4);
        }
        func_8004CCD0((Vec3f*)&D_801017E4_ChanceTime[0], &D_800F32A0->coords, (Vec3f*)&D_801017E4_ChanceTime[1]);
        D_80101370_ChanceTime = 1;
        GwPlayer[D_801012E0_ChanceTime].stars = stars[1];
        GwPlayer[D_801012E1_ChanceTime].stars = stars[0];
        HuPrcSleep(36);
        func_80060468(0x443, GwPlayer[pl[0]].character);
        HuPrcSleep(48);
        func_80050160();
    } else {
        for (i = 0; i < D_8010183E_ChanceTime[0] + D_8010183E_ChanceTime[1]; i++) {
            func_800258EC(D_80101868_ChanceTime[i].unk_00, 4, 4);
        }
        for (i = 0; i < 2; i++) {
            func_800258EC(D_80101868_ChanceTime[i].unk_00, 4, 0);
            func_800257E4(D_80101868_ChanceTime[i].unk_00, 90.0f, 0.0f, 0.0f);
        }
        rot = 0.0f;
        i = 0;
        do {
            t = i;
            func_80025798(D_80101868_ChanceTime[0].unk_00,
                          (D_80101830_ChanceTime.x - D_80101824_ChanceTime.x) * t / 180.0f + D_80101824_ChanceTime.x,
                          D_80101824_ChanceTime.y + 200.0f + sinf(rad = i * 0.017453292519943295) * 100.0f,
                          D_80101824_ChanceTime.z + (D_80101830_ChanceTime.z - D_80101824_ChanceTime.z) * t / 180.0);
            i += 5;
            func_80025798(D_80101868_ChanceTime[1].unk_00,
                          (D_80101824_ChanceTime.x - D_80101830_ChanceTime.x) * t / 180.0f + D_80101830_ChanceTime.x,
                          D_80101830_ChanceTime.y + 200.0f + sinf(rad) * 50.0f,
                          D_80101830_ChanceTime.z + (D_80101824_ChanceTime.z - D_80101830_ChanceTime.z) * t / 180.0);
            func_800257E4(D_80101868_ChanceTime[0].unk_00, 90.0f, rot, 0.0f);
            rot += 20.0f;
            func_800257E4(D_80101868_ChanceTime[1].unk_00, 90.0f, rot, 0.0f);
            HuPrcVSleep();
        } while (i < 181);
        for (i = 0; i < 2; i++) {
            func_800258EC(D_80101868_ChanceTime[i].unk_00, 4, 4);
            func_800257E4(D_80101868_ChanceTime[i].unk_00, 90.0f, 0.0f, 0.0f);
        }
        D_80101370_ChanceTime = 1;
        GwPlayer[D_801012E0_ChanceTime].stars = stars[1];
        GwPlayer[D_801012E1_ChanceTime].stars = stars[0];
        HuPrcSleep(36);
        HuPrcSleep(48);
    }
    D_801011F9_ChanceTime = 1;
    while (1) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/DE6A0", func_800FFFB0_ChanceTime);
#endif
s8 func_80101180_ChanceTime(s16 a, s16 b) {
    if (D_80101379_ChanceTime == 0) {
        D_8010183E_ChanceTime[0] = a;
        D_8010183E_ChanceTime[1] = b;
        D_801011F9_ChanceTime = 0;
        omAddPrcObj(&func_800FFFB0_ChanceTime, 0x300, 0x800, 0);
        D_80101379_ChanceTime = 1;
    }
    return D_80101370_ChanceTime;
}
