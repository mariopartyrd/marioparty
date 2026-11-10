#include "common.h"
#include "TeeteringTowers.h"

/* .data (0x800FADD0..0x800FAFE0): the camera key lists and their players. */
f32 D_800FADD0_TeeteringTowers = 0.0f;
TTCamKey D_800FADD4_TeeteringTowers[3] = {
    { 300.0f, { 0.0f, 0.0f, -777.0f }, { 425.0f, 0.0f, 0.0f }, 60.0f, { 0, 0, 0, 0 } },
    { 2000.0f, { 0.0f, 251.0f, -1477.0f }, { 305.0f, 0.0f, 0.0f }, 3.0f, { 0, 0, 0, 0 } },
    { -1.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f, { 0, 0, 0, 0 } },
};
TTCamKey* D_800FAE40_TeeteringTowers = D_800FADD4_TeeteringTowers;
s32 D_800FAE44_TeeteringTowers = 0;
f32 D_800FAE48_TeeteringTowers = 15.0f;
s32 D_800FAE4C_TeeteringTowers = 0;
s32 D_800FAE50_TeeteringTowers = 0;
s32 D_800FAE54_TeeteringTowers = 0;
f32 D_800FAE58_TeeteringTowers = 0.0f;
TTCamKey* D_800FAE5C_TeeteringTowers = D_800FADD4_TeeteringTowers;
s32 D_800FAE60_TeeteringTowers = 0;
TTCamKey D_800FAE64_TeeteringTowers[3] = {
    { 2000.0f, { 0.0f, 251.0f, -1477.0f }, { 305.0f, 0.0f, 0.0f }, 30.0f, { 2, 0, 0, 0 } },
    { -1.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f, { 0, 0, 0, 0 } },
    { -1.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f, { 0, 0, 0, 0 } },
};
f32 D_800FAED0_TeeteringTowers = 0.0f;
TTCamKey* D_800FAED4_TeeteringTowers = D_800FAE64_TeeteringTowers;
s32 D_800FAED8_TeeteringTowers = 0;
s32 D_800FAEDC_TeeteringTowers = 0;
TTCamKey D_800FAEE0_TeeteringTowers[3] = { /* unreferenced */
    { 2000.0f, { 0.0f, 251.0f, -1477.0f }, { 305.0f, 0.0f, 0.0f }, 60.0f, { 2, 0, 0, 0 } },
    { -1.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f, { 0, 0, 0, 0 } },
    { -1.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f, { 0, 0, 0, 0 } },
};
f32 D_800FAF4C_TeeteringTowers = 0.0f;
TTCamKey* D_800FAF50_TeeteringTowers = D_800FAE64_TeeteringTowers;
s32 D_800FAF54_TeeteringTowers = 0;
s32 D_800FAF58_TeeteringTowers = 0;
TTCamKey D_800FAF5C_TeeteringTowers[3] = {
    { 2000.0f, { 0.0f, 251.0f, -1477.0f }, { 305.0f, 0.0f, 0.0f }, 30.0f, { 2, 0, 0, 0 } },
    { -1.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f, { 0, 0, 0, 0 } },
    { -1.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f, { 0, 0, 0, 0 } },
};
f32 D_800FAFC8_TeeteringTowers = 0.0f;
TTCamKey* D_800FAFCC_TeeteringTowers = D_800FAF5C_TeeteringTowers;
s32 D_800FAFD0_TeeteringTowers = 0;

void func_800F8E30_TeeteringTowers(void) {
    D_800FADD0_TeeteringTowers = 0.0f;
}

// retail keeps a second copy of the 0.0f compare operand ($f4, mov.s; masked 2)
#ifdef NON_MATCHING
void func_800F8E3C_TeeteringTowers(void) {
    f32 zero = 0.0f;
    s32 i;

    D_800FAE40_TeeteringTowers = D_800FADD4_TeeteringTowers;
    D_800FAE44_TeeteringTowers = 0;
    for (i = 0; D_800FADD4_TeeteringTowers[i].center.y > zero; i++) {
    }
    func_80009458();
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_TeeteringTowers/176130", func_800F8E3C_TeeteringTowers);
#endif

/* The intro: the player walks onto the first platform while the camera follows its keys. */
s32 func_800F8EC8_TeeteringTowers(void) {
    TTCamKey key;
    TTPlayerWork* work = TT_PLAYER(D_800FB270_TeeteringTowers);
    s32 port = work->unk_56;
    f32 t;

    if (D_800FAE50_TeeteringTowers < 4) {
        func_800FA6E8_TeeteringTowers(D_800FAE58_TeeteringTowers, D_800FAE5C_TeeteringTowers, &key);
        CZoom = key.zoom;
        CRot.x = key.rot.x;
        CRot.y = key.rot.y;
        CRot.z = key.rot.z;
        Center.x = key.center.x;
        Center.y = key.center.y;
        Center.z = key.center.z;
    }
    if (D_800FAE50_TeeteringTowers >= 3) {
        if (++D_800FAE4C_TeeteringTowers < 31) {
            t = D_800FAE4C_TeeteringTowers / 30.0f;
            func_800234B8(2, t * 255.0f, t * 255.0f, t * 140.0f);
            func_800234B8(3, t * 175.0f, t * 175.0f, t * 255.0f);
        }
    }
    if (D_800FAE50_TeeteringTowers == 0) {
        func_800258EC(D_800FB270_TeeteringTowers->model[1], 4, 4);
        ContStkX[port] = func_800AEAC0(90.0f) * 60.0f;
        ContStkY[port] = -(func_800AEFD0(90.0f) * 60.0f);
        ContBtn[port] &= 0x1FFF;
        ContBtnTrg[port] &= 0x1FFF;
        if (D_800FAE54_TeeteringTowers == 15) {
            func_80060128(0x1C);
        }
        if (D_800FAE54_TeeteringTowers >= 40) {
            D_800FAE54_TeeteringTowers = 0;
            D_800FAE50_TeeteringTowers++;
        }
    } else if (D_800FAE50_TeeteringTowers == 1) {
        func_800258EC(D_800FB270_TeeteringTowers->model[1], 4, 4);
        ContStkX[port] = (func_800AEAC0(270.0f) * 60.0f) / 2.0f;
        ContStkY[port] = -(func_800AEFD0(270.0f) * 60.0f) / 2.0f;
        ContBtn[port] &= 0x1FFF;
        ContBtnTrg[port] &= 0x1FFF;
        if (D_800FAE54_TeeteringTowers >= 27) {
            D_800FAE54_TeeteringTowers = 0;
            D_800FAE50_TeeteringTowers += 2;
        }
    } else if (D_800FAE50_TeeteringTowers == 2) {

    } else if (D_800FAE50_TeeteringTowers == 3) {
        func_800258EC(D_800FB270_TeeteringTowers->model[1], 4, 0);
        D_800FA944_TeeteringTowers = 1;
        ContStkX[port] = (func_800AEAC0(180.0f) * 60.0f) / 5.0f;
        ContStkY[port] = -(func_800AEFD0(180.0f) * 60.0f) / 5.0f;
        ContBtn[port] &= 0x1FFF;
        ContBtnTrg[port] &= 0x1FFF;
        D_800FB270_TeeteringTowers->trans.x = 0.0f;
        D_800FB270_TeeteringTowers->trans.y = 51.0f;
        D_800FB270_TeeteringTowers->trans.z = -977.0f;
        work->unk_3C = 180.0f;
        D_800FAE58_TeeteringTowers += 1.0f / D_800FAE5C_TeeteringTowers->time;
        if ((D_800FAE48_TeeteringTowers += 0.5f) > 40.0f) {
            D_800FAE48_TeeteringTowers = 40.0f;
        }
        func_8001D494(0, D_800FAE48_TeeteringTowers, 80.0f, 8000.0f);
        if (D_800FAE58_TeeteringTowers >= 1.0f) {
            TTCamKey* k;

            D_800FAE58_TeeteringTowers = 0.0f;
            k = D_800FAE5C_TeeteringTowers;
            D_800FAE5C_TeeteringTowers = k + 1;
            D_800FAE60_TeeteringTowers++;
            if (k[2].zoom <= 0.0f) {
                D_800FAE5C_TeeteringTowers = D_800FADD4_TeeteringTowers;
                D_800FAE60_TeeteringTowers = 0;
                D_800FAE54_TeeteringTowers = 0;
                D_800FAE50_TeeteringTowers = 7;
                D_800FA944_TeeteringTowers = 0;
            }
        }
    } else if (D_800FAE50_TeeteringTowers == 4) {
        ContStkX[port] = func_800AEAC0(180.0f) * 60.0f;
        ContStkY[port] = -(func_800AEFD0(180.0f) * 60.0f);
        ContBtn[port] &= 0x1FFF;
        ContBtnTrg[port] &= 0x1FFF;
        func_800FA62C_TeeteringTowers();
        if (D_800FAE54_TeeteringTowers >= 45) {
            D_800FAE54_TeeteringTowers = 0;
            D_800FAE50_TeeteringTowers++;
        }
    } else if (D_800FAE50_TeeteringTowers == 5) {
        ContStkX[port] = func_800AEAC0(180.0f) * 60.0f;
        ContStkY[port] = -(func_800AEFD0(180.0f) * 60.0f);
        ContBtn[port] &= 0x1FFF;
        ContBtnTrg[port] &= 0x1FFF;
        ContBtn[port] |= 0x8000;
        ContBtnTrg[port] |= 0x8000;
        func_800FA62C_TeeteringTowers();
        if (D_800FAE54_TeeteringTowers >= 20) {
            D_800FAE54_TeeteringTowers = 0;
            D_800FAE50_TeeteringTowers++;
        }
    } else if (D_800FAE50_TeeteringTowers == 6) {
        ContStkX[port] = func_800AEAC0(180.0f) * 60.0f;
        ContStkY[port] = -(func_800AEFD0(180.0f) * 60.0f);
        ContBtn[port] &= 0x1FFF;
        ContBtnTrg[port] &= 0x1FFF;
        func_800FA62C_TeeteringTowers();
        if (D_800FAE54_TeeteringTowers >= 5) {
            D_800FAE54_TeeteringTowers = 0;
            D_800FAE50_TeeteringTowers++;
        }
    } else if (D_800FAE50_TeeteringTowers == 7) {
        ContStkX[port] = 0;
        ContStkY[port] = 0;
        ContBtn[port] &= 0x1FFF;
        ContBtnTrg[port] &= 0x1FFF;
        func_800FA62C_TeeteringTowers();
        if (D_800FAE54_TeeteringTowers >= 15) {
            D_800FAE54_TeeteringTowers = 0;
            D_800FAE50_TeeteringTowers++;
            return 1;
        }
    }
    func_80005A28(D_800FB270_TeeteringTowers);
    D_800FAE54_TeeteringTowers++;
    return 0;
}

void func_800F9940_TeeteringTowers(void) {
    D_800FAE64_TeeteringTowers[0].center.x = Center.x;
    D_800FAE64_TeeteringTowers[0].center.y = Center.y;
    D_800FAE64_TeeteringTowers[0].center.z = Center.z;
    D_800FAE64_TeeteringTowers[0].rot.x = CRot.x;
    D_800FAE64_TeeteringTowers[0].rot.y = CRot.y;
    D_800FAE64_TeeteringTowers[0].rot.z = CRot.z;
    D_800FAE64_TeeteringTowers[0].zoom = CZoom;
    D_800FAE64_TeeteringTowers[1].zoom = 350.0f;
    D_800FAE64_TeeteringTowers[1].center.x = D_800FB270_TeeteringTowers->trans.x;
    D_800FAE64_TeeteringTowers[1].center.y = D_800FB270_TeeteringTowers->trans.y + 60.0f;
    D_800FAE64_TeeteringTowers[1].center.z = D_800FB270_TeeteringTowers->trans.z;
    D_800FAE64_TeeteringTowers[1].rot.x = 350.0f;
    D_800FAE64_TeeteringTowers[1].rot.y = CRot.y;
    D_800FAE64_TeeteringTowers[1].rot.z = CRot.z;
    D_800FAE64_TeeteringTowers[1].time = 15.0f;
}

/* The goal: the camera closes in on the player and the lights brighten. */
s32 func_800F99F4_TeeteringTowers(void) {
    TTCamKey* k;
    TTCamKey* next;

    if (D_800FAEDC_TeeteringTowers == 1) {
        return 1;
    }
    if (D_800FAED0_TeeteringTowers == 0.0) {
        func_800F9940_TeeteringTowers();
    }
    k = D_800FAED4_TeeteringTowers;
    CZoom = (1.0f - D_800FAED0_TeeteringTowers) * k[0].zoom + k[1].zoom * D_800FAED0_TeeteringTowers;
    CRot.x = (1.0f - D_800FAED0_TeeteringTowers) * k[0].rot.x + k[1].rot.x * D_800FAED0_TeeteringTowers;
    CRot.y = (1.0f - D_800FAED0_TeeteringTowers) * k[0].rot.y + k[1].rot.y * D_800FAED0_TeeteringTowers;
    CRot.z = (1.0f - D_800FAED0_TeeteringTowers) * k[0].rot.z + k[1].rot.z * D_800FAED0_TeeteringTowers;
    Center.x = (1.0f - D_800FAED0_TeeteringTowers) * k[0].center.x + k[1].center.x * D_800FAED0_TeeteringTowers;
    Center.y = (1.0f - D_800FAED0_TeeteringTowers) * k[0].center.y + k[1].center.y * D_800FAED0_TeeteringTowers;
    Center.z = (1.0f - D_800FAED0_TeeteringTowers) * k[0].center.z + k[1].center.z * D_800FAED0_TeeteringTowers;
    func_80023504(2, (1.0f - D_800FAED0_TeeteringTowers) * 0.0f + D_800FAED0_TeeteringTowers * 0.0f,
                  (1.0f - D_800FAED0_TeeteringTowers) * 100.0f + D_800FAED0_TeeteringTowers * 130.0f,
                  (1.0f - D_800FAED0_TeeteringTowers) * 65.0f + D_800FAED0_TeeteringTowers * 40.0f);
    func_800234B8(2, (1.0f - D_800FAED0_TeeteringTowers) * 255.0f + D_800FAED0_TeeteringTowers * 255.0f,
                  (1.0f - D_800FAED0_TeeteringTowers) * 255.0f + D_800FAED0_TeeteringTowers * 255.0f,
                  (1.0f - D_800FAED0_TeeteringTowers) * 140.0f + D_800FAED0_TeeteringTowers * 170.0f);
    func_80023504(3, (1.0f - D_800FAED0_TeeteringTowers) * 0.0f + D_800FAED0_TeeteringTowers * 0.0f,
                  (1.0f - D_800FAED0_TeeteringTowers) * -35.0f + D_800FAED0_TeeteringTowers * -116.0f,
                  (1.0f - D_800FAED0_TeeteringTowers) * 114.0f + D_800FAED0_TeeteringTowers * 29.0f);
    func_800234B8(3, (1.0f - D_800FAED0_TeeteringTowers) * 175.0f + D_800FAED0_TeeteringTowers * 200.0f,
                  (1.0f - D_800FAED0_TeeteringTowers) * 175.0f + D_800FAED0_TeeteringTowers * 240.0f,
                  (1.0f - D_800FAED0_TeeteringTowers) * 255.0f + D_800FAED0_TeeteringTowers * 255.0f);
    next = D_800FAED4_TeeteringTowers;
    D_800FAED0_TeeteringTowers = 1.0f / next->time + D_800FAED0_TeeteringTowers;
    if (D_800FAED0_TeeteringTowers >= 1.0f) {
        D_800FAED0_TeeteringTowers = 0.0f;
        D_800FAED4_TeeteringTowers = next + 1;
        D_800FAED8_TeeteringTowers++;
        if (next[2].zoom <= 0.0f) {
            D_800FAED4_TeeteringTowers = D_800FAE64_TeeteringTowers;
            D_800FAED8_TeeteringTowers = 0;
            D_800FAEDC_TeeteringTowers = 1;
            return 1;
        }
    }
    return 0;
}

void func_800F9FD0_TeeteringTowers(void) {
    D_800FAE64_TeeteringTowers[0].center.x = Center.x;
    D_800FAE64_TeeteringTowers[0].center.y = Center.y;
    D_800FAE64_TeeteringTowers[0].center.z = Center.z;
    D_800FAE64_TeeteringTowers[0].rot.x = CRot.x;
    D_800FAE64_TeeteringTowers[0].rot.y = CRot.y;
    D_800FAE64_TeeteringTowers[0].rot.z = CRot.z;
    D_800FAE64_TeeteringTowers[0].zoom = CZoom;
    D_800FAE64_TeeteringTowers[1].zoom = 2000.0f;
    D_800FAE64_TeeteringTowers[1].center.x = D_800FB270_TeeteringTowers->trans.x;
    D_800FAE64_TeeteringTowers[1].center.y = D_800FB270_TeeteringTowers->trans.y;
    D_800FAE64_TeeteringTowers[1].center.z = D_800FB270_TeeteringTowers->trans.z;
    D_800FAE64_TeeteringTowers[1].rot.x = 270.0f;
    D_800FAE64_TeeteringTowers[1].rot.y = 0.0f;
    D_800FAE64_TeeteringTowers[1].rot.z = 0.0f;
    D_800FAE64_TeeteringTowers[1].time = 3.0f;
}

/* The fall: the camera pulls up above the player. */
s32 func_800FA080_TeeteringTowers(void) {
    TTCamKey* k;
    f32 t;

    if (D_800FAF4C_TeeteringTowers == 0.0) {
        func_800F9FD0_TeeteringTowers();
    }
    k = D_800FAF50_TeeteringTowers;
    t = 1.0f - D_800FAF4C_TeeteringTowers;
    CZoom = t * k[0].zoom + k[1].zoom * D_800FAF4C_TeeteringTowers;
    CRot.x = t * k[0].rot.x + k[1].rot.x * D_800FAF4C_TeeteringTowers;
    CRot.y = t * k[0].rot.y + k[1].rot.y * D_800FAF4C_TeeteringTowers;
    CRot.z = t * k[0].rot.z + k[1].rot.z * D_800FAF4C_TeeteringTowers;
    Center.x = t * k[0].center.x + k[1].center.x * D_800FAF4C_TeeteringTowers;
    Center.y = t * k[0].center.y + k[1].center.y * D_800FAF4C_TeeteringTowers;
    Center.z = t * k[0].center.z + k[1].center.z * D_800FAF4C_TeeteringTowers;
    D_800FAF4C_TeeteringTowers += 1.0f / D_800FAF50_TeeteringTowers->time;
    if (D_800FAF58_TeeteringTowers == 10) {
        func_800601D4(0x28);
    }
    if (D_800FAF4C_TeeteringTowers >= 1.0f) {
        TTCamKey* k;

        D_800FAF4C_TeeteringTowers = 0.0f;
        k = D_800FAF50_TeeteringTowers;
        D_800FAF50_TeeteringTowers = k + 1;
        D_800FAF54_TeeteringTowers++;
        if (k[2].zoom <= 0.0f) {
            D_800FAF50_TeeteringTowers = D_800FAE64_TeeteringTowers;
            D_800FAF54_TeeteringTowers = 0;
            return 1;
        }
    }
    D_800FAF58_TeeteringTowers++;
    return 0;
}

void func_800FA274_TeeteringTowers(void) {
    u8 cam;

    D_800FB274_TeeteringTowers = 0;
    D_800FADD0_TeeteringTowers = -977.0f;
    func_800178A0(1);
    cam = func_800178E8();
    func_80017660(cam, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 15.0f, 80.0f, 8000.0f);
    Center.x = D_800FADD4_TeeteringTowers[0].center.x;
    Center.y = D_800FADD4_TeeteringTowers[0].center.y;
    Center.z = D_800FADD4_TeeteringTowers[0].center.z;
    CRot.x = D_800FADD4_TeeteringTowers[0].rot.x;
    CRot.y = D_800FADD4_TeeteringTowers[0].rot.y;
    CRot.z = D_800FADD4_TeeteringTowers[0].rot.z;
    CZoom = D_800FADD4_TeeteringTowers[0].zoom;
}

void func_800FA398_TeeteringTowers(void) {
    s32 idx = TT_PLAYER(D_800FB270_TeeteringTowers)->unk_53;

    D_800FAF5C_TeeteringTowers[0].center.x = Center.x;
    D_800FAF5C_TeeteringTowers[0].center.y = Center.y;
    D_800FAF5C_TeeteringTowers[0].center.z = Center.z;
    D_800FAF5C_TeeteringTowers[0].rot.x = CRot.x;
    D_800FAF5C_TeeteringTowers[0].rot.y = CRot.y;
    D_800FAF5C_TeeteringTowers[0].rot.z = CRot.z;
    D_800FAF5C_TeeteringTowers[0].zoom = CZoom;
    D_800FAF5C_TeeteringTowers[1].center.x = D_800F2AF8[idx]->trans.x + 0.0f;
    D_800FAF5C_TeeteringTowers[1].center.y = D_800F2AF8[idx]->trans.y + 200.0f;
    D_800FAF5C_TeeteringTowers[1].center.z = D_800F2AF8[idx]->trans.z + -500.0f;
    D_800FAF5C_TeeteringTowers[1].rot.x = CRot.x;
    D_800FAF5C_TeeteringTowers[1].rot.y = CRot.y;
    D_800FAF5C_TeeteringTowers[1].rot.z = CRot.z;
    D_800FAF5C_TeeteringTowers[1].zoom = CZoom;
    D_800FAF5C_TeeteringTowers[1].time = 5.0f;
}

/* Follows the player to the platform it landed on. */
s32 func_800FA480_TeeteringTowers(void) {
    TTCamKey* k;

    if (D_800FAFC8_TeeteringTowers == 0.0) {
        func_800FA398_TeeteringTowers();
    }
    k = D_800FAFCC_TeeteringTowers;
    CZoom = (1.0f - D_800FAFC8_TeeteringTowers) * k[0].zoom + k[1].zoom * D_800FAFC8_TeeteringTowers;
    CRot.x = (1.0f - D_800FAFC8_TeeteringTowers) * k[0].rot.x + k[1].rot.x * D_800FAFC8_TeeteringTowers;
    CRot.y = (1.0f - D_800FAFC8_TeeteringTowers) * k[0].rot.y + k[1].rot.y * D_800FAFC8_TeeteringTowers;
    CRot.z = (1.0f - D_800FAFC8_TeeteringTowers) * k[0].rot.z + k[1].rot.z * D_800FAFC8_TeeteringTowers;
    Center.x = (1.0f - D_800FAFC8_TeeteringTowers) * k[0].center.x + k[1].center.x * D_800FAFC8_TeeteringTowers;
    Center.y = (1.0f - D_800FAFC8_TeeteringTowers) * k[0].center.y + k[1].center.y * D_800FAFC8_TeeteringTowers;
    Center.z = (1.0f - D_800FAFC8_TeeteringTowers) * k[0].center.z + k[1].center.z * D_800FAFC8_TeeteringTowers;
    D_800FAFC8_TeeteringTowers = 1.0f / k->time + D_800FAFC8_TeeteringTowers;
    if (D_800FAFC8_TeeteringTowers >= 1.0f) {
        D_800FAFC8_TeeteringTowers = 0.0f;
        D_800FAFCC_TeeteringTowers = k + 1;
        D_800FAFD0_TeeteringTowers++;
        if (k[2].zoom <= 0.0f) {
            D_800FAFCC_TeeteringTowers = D_800FAF5C_TeeteringTowers;
            D_800FAFD0_TeeteringTowers = 0;
            return 1;
        }
    }
    return 0;
}

void func_800FA62C_TeeteringTowers(void) {
    s32 follow;

    if (D_800FA934_TeeteringTowers == 2) {
        goto follow;
    }
    if (D_800FA934_TeeteringTowers == 3) {
    follow:
        follow = D_800FB274_TeeteringTowers;
        if (follow == 1 && func_800FA480_TeeteringTowers() == follow) {
            D_800FB274_TeeteringTowers = 0;
        }
    } else {
        Center.x = D_800FB270_TeeteringTowers->trans.x + 0.0f;
        Center.y = D_800FB270_TeeteringTowers->trans.y + 200.0f;
        Center.z = D_800FB270_TeeteringTowers->trans.z + -500.0f;
    }
}

/* A quadratic B-spline through three camera keys (a list's last key is used twice). */
void func_800FA6E8_TeeteringTowers(f32 t, TTCamKey* k, TTCamKey* out) {
    f32 c0 = 1.0f - t;
    f32 a = c0;
    f32 c1;
    f32 c2;

    c0 = (c0 * c0) / 2.0f;
    c1 = a * t + 0.5f;
    c2 = (t * t) / 2.0f;

    if (k[2].zoom < 0.0f) {
        out->zoom = c0 * k[0].zoom + c1 * k[1].zoom + c2 * k[1].zoom;
        out->rot.x = c0 * k[0].rot.x + c1 * k[1].rot.x + c2 * k[1].rot.x;
        out->rot.y = c0 * k[0].rot.y + c1 * k[1].rot.y + c2 * k[1].rot.y;
        out->rot.z = c0 * k[0].rot.z + c1 * k[1].rot.z + c2 * k[1].rot.z;
        out->center.x = c0 * k[0].center.x + c1 * k[1].center.x + c2 * k[1].center.x;
        out->center.y = c0 * k[0].center.y + c1 * k[1].center.y + c2 * k[1].center.y;
        out->center.z = c0 * k[0].center.z + c1 * k[1].center.z + c2 * k[1].center.z;
        return;
    }
    out->zoom = c0 * k[0].zoom + c1 * k[1].zoom + c2 * k[2].zoom;
    out->rot.x = c0 * k[0].rot.x + c1 * k[1].rot.x + c2 * k[2].rot.x;
    out->rot.y = c0 * k[0].rot.y + c1 * k[1].rot.y + c2 * k[2].rot.y;
    out->rot.z = c0 * k[0].rot.z + c1 * k[1].rot.z + c2 * k[2].rot.z;
    out->center.x = c0 * k[0].center.x + c1 * k[1].center.x + c2 * k[2].center.x;
    out->center.y = c0 * k[0].center.y + c1 * k[1].center.y + c2 * k[2].center.y;
    out->center.z = c0 * k[0].center.z + c1 * k[1].center.z + c2 * k[2].center.z;
}
