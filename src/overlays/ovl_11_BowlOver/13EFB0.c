#include "BowlOver.h"

/* Collision probe for func_8002AE24 (position and a result word). */
typedef struct BowlProbe {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ s32 hit;
} BowlProbe;

#define BALL_WORK(obj) ((BowlBallWork*)(obj)->unk_50)
#define PLAYER_WORK(obj) ((BowlPlayerWork*)(obj)->unk_50)
#define BOWL_ABS(x) ((x) < 0.0f ? -(x) : (x))

/* ---------------------------------------------------------------------------------------------
   .data
   --------------------------------------------------------------------------------------------- */

s16 D_800FD2D0_BowlOver[4] = { 0, 0, 0, 0 };
u16 D_800FD2D8_BowlOver = 0;
u16 D_800FD2DA_BowlOver = 0;
u16 D_800FD2DC_BowlOver[2] = { 0, 0 };
s8 D_800FD2E0_BowlOver = 0;
s8 D_800FD2E1_BowlOver = 0;
s8 D_800FD2E2_BowlOver = 0; /* unreferenced */
s8 D_800FD2E3_BowlOver = 0; /* unreferenced */
f32 D_800FD2E4_BowlOver = 0.0f;
u16 D_800FD2E8_BowlOver = 0;
u16 D_800FD2EA_BowlOver = 0;
u32 D_800FD2EC_BowlOver = 0;
s8 D_800FD2F0_BowlOver = 0;
s8 D_800FD2F1_BowlOver = 0;
s8 D_800FD2F2_BowlOver = 0;
s8 D_800FD2F3_BowlOver = 0;
s8 D_800FD2F4_BowlOver = 0;
s8 D_800FD2F5_BowlOver = 0;
s8 D_800FD2F6_BowlOver = 0;
s8 D_800FD2F7_BowlOver = 0;
s32 D_800FD2F8_BowlOver = 0;
s32 D_800FD2FC_BowlOver = 0;
s32 D_800FD300_BowlOver = 929;
s32 D_800FD304_BowlOver = 0;
u16 D_800FD308_BowlOver = 0;
s16 D_800FD30A_BowlOver = 0;
s16 D_800FD30C_BowlOver[2] = { 0, 0 };
f32 D_800FD310_BowlOver[3][2] = { { -100.0f, 200.0f }, { -200.0f, 100.0f }, { -250.0f, 50.0f } };
u8 D_800FD328_BowlOver = 0;
u8 D_800FD329_BowlOver = 0;
u8 D_800FD32A_BowlOver = 1;
u8 D_800FD32B_BowlOver = 0; /* unreferenced */
u16 D_800FD32C_BowlOver[2] = { 0, 0 };
s32 D_800FD330_BowlOver = 0;
f32 D_800FD334_BowlOver = -1.0f;
u8 D_800FD338_BowlOver[4] = { 0, 0, 0, 0 };
f32 D_800FD33C_BowlOver = 2.0f;
f32 D_800FD340_BowlOver = 0.0f;
f32 D_800FD344_BowlOver = 0.0f;
f32 D_800FD348_BowlOver = 0.0f;
f32 D_800FD34C_BowlOver = 0.0f;
s8 D_800FD350_BowlOver = 0;
s8 D_800FD351_BowlOver = 0;
s8 D_800FD352_BowlOver = 0; /* unreferenced */
s8 D_800FD353_BowlOver = 0; /* unreferenced */
Vec3f D_800FD354_BowlOver[2] = { { 640.0f, 480.0f, 511.0f }, { 640.0f, 480.0f, 511.0f } };
Vec3f D_800FD36C_BowlOver[2] = { { 640.0f, 480.0f, 511.0f }, { 640.0f, 480.0f, 511.0f } };
Vec4f D_800FD384_BowlOver[2] = { { 0.0f, 0.0f, 320.0f, 120.0f }, { 0.0f, 120.0f, 320.0f, 240.0f } };
s32 D_800FD3A4_BowlOver[3] = { 0, 0, 0 }; /* unreferenced */
s8 D_800FD3B0_BowlOver = 0;
s8 D_800FD3B1_BowlOver = 0; /* unreferenced */
s8 D_800FD3B2_BowlOver = 0; /* unreferenced */
s8 D_800FD3B3_BowlOver = 0; /* unreferenced */
f32 D_800FD3B4_BowlOver = 1.47f;
s8 D_800FD3B8_BowlOver[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
s8 D_800FD3C0_BowlOver[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
s8 D_800FD3C8_BowlOver = 0;
s8 D_800FD3C9_BowlOver = 0; /* unreferenced */
s8 D_800FD3CA_BowlOver = 0; /* unreferenced */
s8 D_800FD3CB_BowlOver = 0; /* unreferenced */
u32 D_800FD3CC_BowlOver = 0;
u8 D_800FD3D0_BowlOver[4] = { 0, 0, 0, 0 };
s32 D_800FD3D4_BowlOver[3] = { 0x230003, 0x230004, 0x230005 };

/* ---------------------------------------------------------------------------------------------
   Code
   --------------------------------------------------------------------------------------------- */

void func_800F65E0_BowlOver(void) {
    omObjData* obj;
    s16 i;
    s16 k;

    for (i = 0; i < 4; i++) {
        if (GwPlayer[i].group == 0) {
            break;
        }
    }
    switch (i) {
        case 1:
            D_800FDC5A_BowlOver[0] = 1;
            break;
        case 2:
            D_800FDC5A_BowlOver[0] = 2;
            break;
        case 3:
            D_800FDC5A_BowlOver[0] = 3;
            break;
        case 0:
        default:
            D_800FDC5A_BowlOver[0] = 0;
            break;
    }
    for (i = 1, k = 0; i < 4; i++, k++) {
        if (D_800FDC5A_BowlOver[0] == k) {
            k++;
        }
        D_800FDC5A_BowlOver[i] = k;
    }
    func_80029090(5);
    func_8002ADF0(&D_800EDEC0, 8);
    func_8001DE70(0x20);
    omInitObjMan(0x14, 0);
    func_80060088();
    func_800F9450_BowlOver();
    func_80017660(0, 0.0f, 0.0f, 0.0f, 0.0f);
    func_80017660(1, 0.0f, 0.0f, 319.0f, 239.0f);
    func_800234B8(1, 0x40, 0x40, 0x60);
    func_80023504(1, 42.0f, 90.0f, 51.0f);
    func_8000942C();
    func_80009468();
    func_8007B168((u8*)"\x82\x72\x82\x73\x82\x60\x82\x71\x82\x73", 1);
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    func_800FA4A4_BowlOver();
    func_800FA4A4_BowlOver();
    D_800FD3D0_BowlOver[0] = func_800FA4A4_BowlOver() % 3;
    D_800FD878_BowlOver = omAddObj(0xF, 8, 0, -1, func_800F91D0_BowlOver);
    func_800090B8(D_800ED440);
    obj = omAddObj(0xA, 0x23, 0, -1, func_800FA5A0_BowlOver);
    D_800F2AF8[D_800ED440++] = obj;
    func_800FA8D0_BowlOver();
    func_800FCFA0_BowlOver();
    D_800FD860_BowlOver[0] = omAddObj(0x14, 0x14, 0, -1, func_800FD07C_BowlOver);
    D_800FD860_BowlOver[1] = omAddObj(0x14, 0x14, 0, -1, func_800FD118_BowlOver);
    D_800FD860_BowlOver[2] = omAddObj(0x14, 0x14, 0, -1, func_800FD1B8_BowlOver);
    D_800FD860_BowlOver[3] = omAddObj(0x19, 0xA, 0, -1, func_800FD258_BowlOver);
    D_800FD860_BowlOver[4] = omAddObj(0x19, 0xA, 0, -1, func_800FD27C_BowlOver);
    D_800FD860_BowlOver[5] = omAddObj(0x19, 0xA, 0, -1, func_800FD2A0_BowlOver);
    omAddObj(0, 0, 0, -1, func_800F71BC_BowlOver);
    omAddObj(0, 0, 0, -1, func_800F9B00_BowlOver);
    obj = omAddObj(0xA, 2, 5, -1, func_800F7C24_BowlOver);
    D_800F3FB0[D_800F2BC0++] = obj;
    SetFadeInTypeAndTime(0, 0x10);
    D_800FDC58_BowlOver = 3;
    D_800FDC5E_BowlOver = 2;
}

// scheduling and register allocation
#ifdef NON_MATCHING
s8 func_800F6A2C_BowlOver(void) {
    BowlProbe probe;
    s16 i;
    f32 x;

    if (D_800FD2DC_BowlOver[0] == 1) {
        if (D_800FD2E1_BowlOver == 0) {
            func_800F9A80_BowlOver(0, 1900.0f, 348.5f, 0.0f, 0.0f, D_800FD878_BowlOver->trans.x, -180.0f,
                                   D_800FD878_BowlOver->trans.z - 1438.0f);
            D_800FDC5E_BowlOver = 1;
            D_800FDC58_BowlOver = 1;
            func_80025F10(D_800F3FB0[0]->model[0], 1);
            func_80025F10(D_800F3FB0[0]->model[1], D_800FDC5E_BowlOver);
            for (i = 0; i < 7; i++) {
                func_80025F10(D_800FD878_BowlOver->model[i], D_800FDC5E_BowlOver);
            }
            func_80017660(0, 0.0f, 0.0f, 319.0f, 239.0f);
            func_80017660(1, 0.0f, 0.0f, 0.0f, 0.0f);
            func_8001D494(0, 45.0f, 80.0f, 8000.0f);
            D_800FD2EA_BowlOver = 0;
            D_800FD2E8_BowlOver = 0;
            D_800FD2E1_BowlOver = 1;
            func_80025798(D_800FD878_BowlOver->model[2], D_800FD878_BowlOver->trans.x,
                          D_800FD878_BowlOver->trans.y, D_800FD878_BowlOver->trans.z);
            func_800257E4(D_800FD878_BowlOver->model[2], D_800FD878_BowlOver->rot.x,
                          D_800FD878_BowlOver->rot.y, D_800FD878_BowlOver->rot.z);
            func_80025798(D_800FD878_BowlOver->model[3], D_800FD878_BowlOver->trans.x,
                          D_800FD878_BowlOver->trans.y + 70.0f, D_800FD878_BowlOver->trans.z + 50.0f);
            func_80025830(D_800FD878_BowlOver->model[3], 6.0f, 6.0f, 6.0f);
            func_800258EC(D_800FD878_BowlOver->model[3], 4, 0);
            probe.pos.x = D_800FD878_BowlOver->trans.x - 100.0f;
            probe.pos.y = D_800FD878_BowlOver->trans.y;
            probe.pos.z = D_800FD878_BowlOver->trans.z;
            probe.hit = 0;
            func_8002AE24(D_800F2AF8[0]->model[0], &D_800EDEC0, func_80002060, &probe);
            if (func_8002B3A8(&D_800EDEC0) == 0) {
                D_800FD830_BowlOver = 0;
            } else {
                D_800FD830_BowlOver = 1;
            }
            PlaySound(0x25B);
        }
        if (D_800FD2E0_BowlOver != 0) {
            return 0;
        }
        D_800FD2EA_BowlOver++;
        if ((s16)D_800FD2EA_BowlOver < 0x21) {
            if (D_800FD2EA_BowlOver & 2) {
                func_800258EC(D_800FD878_BowlOver->model[0], 4, 0);
                func_800258EC(D_800FD878_BowlOver->model[2], 4, 4);
            } else {
                func_800258EC(D_800FD878_BowlOver->model[0], 4, 4);
                func_800258EC(D_800FD878_BowlOver->model[2], 4, 0);
            }
            if ((s16)D_800FD2EA_BowlOver == 0x19) {
                func_80025798(D_800FD878_BowlOver->model[4], D_800FD878_BowlOver->trans.x,
                              D_800FD878_BowlOver->trans.y, D_800FD878_BowlOver->trans.z);
                func_80025830(D_800FD878_BowlOver->model[4], 5.0f, 5.0f, 5.0f);
                func_800258EC(D_800FD878_BowlOver->model[4], 4, 0);
            }
        }
        if ((s16)D_800FD2EA_BowlOver == 0x21) {
            func_800258EC(D_800FD878_BowlOver->model[0], 4, 4);
            func_800258EC(D_800FD878_BowlOver->model[2], 4, 4);
            func_800258EC(D_800FD878_BowlOver->model[3], 4, 4);
            func_800258EC(D_800FD878_BowlOver->model[4], 4, 4);
            func_800258EC(D_800FD878_BowlOver->model[5], 4, 0);
            D_800FD878_BowlOver->trans.y = 0.0f;
            func_80025798(D_800FD878_BowlOver->model[5], D_800FD878_BowlOver->trans.x,
                          D_800FD878_BowlOver->trans.y, D_800FD878_BowlOver->trans.z);
            PlaySound(0x264);
        }
        if ((s16)D_800FD2EA_BowlOver == 0x3F) {
            func_800258EC(D_800FD878_BowlOver->model[5], 4, 4);
            func_800258EC(D_800FD878_BowlOver->model[6], 4, 0);
            func_80025798(D_800FD878_BowlOver->model[6], D_800FD878_BowlOver->trans.x,
                          D_800FD878_BowlOver->trans.y, D_800FD878_BowlOver->trans.z);
        }
        if ((s16)D_800FD2EA_BowlOver >= 0x40) {
            D_800FD2E4_BowlOver += 4.0f;
            if (D_800FD830_BowlOver == 0) {
                D_800FD878_BowlOver->rot.y = 90.0f;
                x = D_800FD878_BowlOver->trans.x + D_800FD2E4_BowlOver;
            } else {
                D_800FD878_BowlOver->rot.y = 270.0f;
                x = D_800FD878_BowlOver->trans.x - D_800FD2E4_BowlOver;
            }
            D_800FD878_BowlOver->trans.x = x;
            if (BOWL_ABS(D_800FD878_BowlOver->trans.x) > 835.0f) {
                D_800FD878_BowlOver->rot.y = 180.0f;
                if (D_800FD830_BowlOver == 0) {
                    D_800FD878_BowlOver->trans.x = 835.0f;
                } else {
                    D_800FD878_BowlOver->trans.x = -835.0f;
                }
                D_800FD878_BowlOver->trans.z += D_800FD2E4_BowlOver;
            }
            func_800257E4(D_800FD878_BowlOver->model[6], D_800FD878_BowlOver->rot.x, D_800FD878_BowlOver->rot.y,
                          D_800FD878_BowlOver->rot.z);
            func_80025798(D_800FD878_BowlOver->model[6], D_800FD878_BowlOver->trans.x,
                          D_800FD878_BowlOver->trans.y, D_800FD878_BowlOver->trans.z);
            if ((s16)D_800FD2E8_BowlOver++ >= 0x4A) {
                func_800258EC(D_800FD878_BowlOver->model[0], 4, 4);
                func_800258EC(D_800FD878_BowlOver->model[1], 4, 4);
                func_800258EC(D_800FD878_BowlOver->model[6], 4, 4);
                D_800FD2E0_BowlOver = 1;
            }
        }
        func_800F9B78_BowlOver(D_800FD878_BowlOver);
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_11_BowlOver/13EFB0", func_800F6A2C_BowlOver);
#endif

// block layout and register allocation
#ifdef NON_MATCHING
void func_800F71BC_BowlOver(omObjData* obj) {
    s16 h;
    s16 i;
    u16 found;
    s16 msg;
    s32 t;
    s16 p;

    func_80009468();
    switch (D_800ED430) {
        case 0:
            if (D_800FD2F5_BowlOver == 0) {
                func_80060128(0x1E);
                D_800FD2F5_BowlOver = 1;
            }
            if (D_800FD2EC_BowlOver < 30) {
                func_800F9A80_BowlOver(1, 1900.0f, 360.5f, 0.0f, 0.0f, 0.0f,
                                       1240.0 - (f32)D_800FD2EC_BowlOver * (890.0 / 30.0),
                                       (f32)D_800FD2EC_BowlOver * 150.0 + -5360.0);
            }
            if (D_800FD2EC_BowlOver == 30) {
                func_800F9A80_BowlOver(1, 1900.0f, 360.5f, 0.0f, 0.0f, 0.0f, 350.0f, -860.0f);
            }
            if (D_800FD2EC_BowlOver == 43) {
                GMesCreate(0);
            }
            if (D_800FD2EC_BowlOver - 30 < 60) {
                h = (D_800FD2EC_BowlOver - 30) * 2.0;
                func_80017660(0, 0.0f, 0.0f, 319.0f, h);
                func_80017660(1, 0.0f, h + 1, 319.0f, 239.0f);
            }
            if (D_800FD2EC_BowlOver >= 90) {
                func_80017660(0, 0.0f, 0.0f, 319.0f, 119.0f);
                func_80017660(1, 0.0f, 121.0f, 319.0f, 239.0f);
                if (GMesStatAllGet() == 0 || (GMesStatAllGet() & 2)) {
                    GMesCreate(8, 0x1E, 0xA0, 0x18);
                    func_80079078(0x1E);
                    func_80009458();
                    D_800FD2F3_BowlOver = 0;
                    D_800FD2F4_BowlOver = 0;
                }
            }
            D_800FD2EC_BowlOver++;
            break;
        case 1:
            if (D_800FD2D8_BowlOver == 1 && D_800FD2DA_BowlOver == 0) {
                func_80017660(0, 0.0f, 0.0f, 319.0f, 239.0f);
                func_80017660(1, 0.0f, 0.0f, 0.0f, 0.0f);
                D_800FDC58_BowlOver = 1;
                D_800FD2DA_BowlOver = 1;
            }
            found = 0;
            if (D_800FD2D0_BowlOver[0] == 1) {
                for (i = 0; i < 6; i++) {
                    if ((D_800FD880_BowlOver[i].unk_0E == 1 && D_800FD880_BowlOver[i].unk_0F == 0) ||
                        D_800FDC60_BowlOver[i].unk_1A != 0 || D_800FDC60_BowlOver[i].unk_14 != 0) {
                        found = 1;
                        break;
                    }
                }
                if (found != 1) {
                    for (i = 0; i < 6; i++) {
                        if (D_800FD880_BowlOver[i].unk_0E == 1) {
                            D_800FD2F2_BowlOver++;
                        }
                    }
                    if (D_800FD2DC_BowlOver[0] == 1 || D_800FD2F2_BowlOver == 0) {
                        if (_CheckFlag(0x2B) != 0) {
                            msg = 2;
                        } else {
                            msg = 0xE;
                        }
                    } else {
                        msg = 2;
                        if (D_800FD2F2_BowlOver >= 6) {
                            if (_CheckFlag(0x2B) != 0) {
                                msg = 2;
                            } else {
                                msg = 0xB;
                            }
                        }
                    }
                    GMesCreate(msg);
                    func_800601D4(0x28);
                    func_8006073C();
                    func_80009438();
                }
            }
            break;
        case 2:
            if (func_800F6A2C_BowlOver() != 0) {
                break;
            }
            if (D_800FD2F3_BowlOver == 0) {
                if (D_800FD2F4_BowlOver == 0) {
                    func_800F9A80_BowlOver(0, 1900.0f, 350.5f, 0.0f, 0.0f, D_800F3FB0[0]->trans.x, 20.0f, -830.0f);
                    D_800FDC5E_BowlOver = 1;
                    D_800FDC58_BowlOver = 1;
                    func_80025F10(D_800F3FB0[0]->model[0], 1);
                    func_80025F10(D_800F3FB0[0]->model[1], D_800FDC5E_BowlOver);
                    func_80017660(0, 0.0f, 0.0f, 319.0f, 239.0f);
                    func_80017660(1, 0.0f, 0.0f, 0.0f, 0.0f);
                    func_8001D494(0, 20.0f, 80.0f, 8000.0f);
                    D_800F3FB0[0]->rot.y = 0.0f;
                    D_800FD2F4_BowlOver = 1;
                    func_80025BB8(D_800F3FB0[0]->model[0], D_800F3FB0[0]->motion[4]);
                    break;
                }
                for (i = 0; i < 4; i++) {
                    p = D_800FDC5A_BowlOver[i];
                    GwPlayer[p].coins_mg += D_800FD5AC_BowlOver[p] - GwPlayer[p].coins;
                }
                if (D_800FD2DC_BowlOver[0] == 1 || D_800FD2F2_BowlOver == 0) {
                    D_800FD2F7_BowlOver = 0;
                } else {
                    D_800FD2F7_BowlOver = (D_800FD2F2_BowlOver >= 6) ? 1 : 2;
                }
                D_800FD2F3_BowlOver = 1;
                break;
            }
            if (D_800FD2F1_BowlOver == 0) {
                if (GMesStatAllGet() == 0 || (GMesStatAllGet() & 2)) {
                    if (_CheckFlag(0x2B) == 0) {
                        switch (D_800FD2F7_BowlOver) {
                            case 1:
                                func_80025BB8(D_800F3FB0[0]->model[0], D_800F3FB0[0]->motion[1]);
                                func_80060128(0x37);
                                t = 0x48;
                                goto set;
                            case 2:
                                func_80025BB8(D_800F3FB0[0]->model[0], D_800F3FB0[0]->motion[1]);
                                func_80060128(0x33);
                                t = 0x39;
                                goto set;
                            case 0:
                                func_80060128(0x34);
                                func_80025BB8(D_800F3FB0[0]->model[0], D_800F3FB0[0]->motion[0]);
                                t = 0x4D;
                                goto set;
                        }
                    } else {
                        t = 0x39;
                    set:
                        D_800FD2F8_BowlOver = t;
                        D_800FD2F1_BowlOver = 1;
                    }
                    D_800FD2FC_BowlOver = 0;
                }
            } else if (D_800FD2FC_BowlOver < D_800FD2F8_BowlOver) {
                if (_CheckFlag(0x2B) == 0) {
                    switch (D_800FD2F7_BowlOver) {
                        case 0:
                            if (D_800FD2FC_BowlOver == 0x12) {
                                func_80060618(0x44A, D_800FDC5A_BowlOver[0]);
                            }
                            break;
                        case 1:
                        case 2:
                            if (GwPlayer[D_800FDC5A_BowlOver[0]].coins_mg >= 10 && D_800FD2FC_BowlOver == 0x24) {
                                func_80060618(0x451, D_800FDC5A_BowlOver[0]);
                            }
                            break;
                    }
                }
                D_800FD2FC_BowlOver++;
            } else if (_CheckFlag(0x2B) != 0 ||
                       func_80025D18(D_800F3FB0[0]->model[0]) >= func_80025D40(D_800F3FB0[0]->model[0])) {
                func_80009448();
            }
            break;
        case 3:
            if (D_800FD2F0_BowlOver == 0) {
                if (GMesWait() == 0) {
                    D_800FD2F0_BowlOver = 1;
                }
            } else if (D_800FD2F6_BowlOver == 0) {
                func_800726AC(0, 0x14);
                D_800FD2F6_BowlOver = 1;
            } else if (func_80072718() == 0) {
                GMesSprClose();
                omOvlReturnEx(1);
            }
            break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_11_BowlOver/13EFB0", func_800F71BC_BowlOver);
#endif

// argument conversion of the player index (lbu/sll/sra/andi)
#ifdef NON_MATCHING
void func_800F7C24_BowlOver(omObjData* obj) {
    f32 x;
    u8 chr;
    s32 dir;
    s32 file;

    x = 0.0f;
    chr = GwPlayer[D_800FDC5A_BowlOver[0]].character;
    dir = D_800C59AC[chr].unk_00;
    file = D_800C59AC[chr].unk_08;
    switch (D_800FD3D0_BowlOver[0]) {
        case 0:
            x = 35.0f;
            break;
        case 1:
            x = -200.0f;
            break;
        case 2:
            x = -235.0f;
            break;
    }
    func_800F8964_BowlOver(obj, dir, file, D_800FDC5A_BowlOver[0], x, 0.0f, 300.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_11_BowlOver/13EFB0", func_800F7C24_BowlOver);
#endif

void func_800F7D14_BowlOver(omObjData* obj) {
    f32 s;

    s = 0.0f;
    switch ((u16)(D_800C59AC[GwPlayer[D_800FDC5A_BowlOver[0]].character].unk_00 >> 16)) {
        case 1:
        case 2:
            s = 0.6f;
            break;
        case 5:
            s = 1.0f;
            break;
        case 3:
            s = 0.9f;
            break;
        case 4:
        case 6:
            s = 0.8f;
            break;
    }
    func_80025830(obj->model[1], s * 2.5, 1.0f, s * 2.5);
    func_80025798(obj->model[1], obj->trans.x, 8.0f, obj->trans.z);
}

void func_800F7E20_BowlOver(omObjData* obj) {
    u8 port;
    f32 lim;

    if (D_800FD30A_BowlOver == 0) {
        func_800F9CF8_BowlOver(obj, D_800FD878_BowlOver);
        D_800FD30A_BowlOver = 1;
    }
    func_800F7D14_BowlOver(obj);
    func_80025F10(D_800F3FB0[0]->model[0], D_800FDC5E_BowlOver);
    func_80025F10(D_800F3FB0[0]->model[1], D_800FDC5E_BowlOver);
    if (D_800ED430 != 1) {
        return;
    }
    if (CenterM[1].z < -1900.0f) {
        func_80025F10(obj->model[0], 0);
        func_80025F10(obj->model[1], 0);
    }
    port = PLAYER_WORK(obj)->unk_56;
    switch (D_800FD304_BowlOver) {
        case 0:
            func_80079078(D_800FD300_BowlOver / 30);
            if (D_800FD300_BowlOver > 0) {
                D_800FD300_BowlOver--;
            }
            if (ContStkX[(s8)port] > 50) {
                obj->trans.x += 5.0f;
                lim = D_800FD310_BowlOver[D_800FD3D0_BowlOver[0]][1];
                if (lim < obj->trans.x) {
                    obj->trans.x = lim;
                }
                D_800FD30C_BowlOver[0] = 1;
            } else if (ContStkX[(s8)port] < -50) {
                obj->trans.x -= 5.0f;
                lim = D_800FD310_BowlOver[D_800FD3D0_BowlOver[0]][0];
                if (obj->trans.x < lim) {
                    obj->trans.x = lim;
                }
                D_800FD30C_BowlOver[0] = 1;
            } else {
                D_800FD30C_BowlOver[0] = 0;
            }
            if (D_800FD30C_BowlOver[0] == 0) {
                if (D_800FD328_BowlOver == 0) {
                    func_80025BB8(obj->model[0], obj->motion[2]);
                    func_80025EB4(obj->model[0], 1, 1);
                    D_800FD328_BowlOver = 1;
                    D_800FD329_BowlOver = 0;
                }
            } else if (D_800FD329_BowlOver == 0) {
                func_80025BB8(obj->model[0], obj->motion[2]);
                func_80025EB4(obj->model[0], 2, 2);
                D_800FD328_BowlOver = 0;
                D_800FD329_BowlOver = 1;
            }
            if ((ContBtnTrg[(s8)port] & 0x8000) || D_800FD300_BowlOver == 0) {
                func_80025BB8(obj->model[0], obj->motion[3]);
                D_800FD304_BowlOver++;
                D_800FD308_BowlOver = 0;
                func_800790C0();
            }
            func_80036ABC(D_800F2B7C[obj->model[0]].unk_6C);
            break;
        case 1:
            if (D_800FD32A_BowlOver == 1) {
                obj->trans.z -= 6.0f;
                func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
            } else {
                D_800FD304_BowlOver++;
            }
            if ((s16)D_800FD308_BowlOver++ == 0x37) {
                D_800FD32A_BowlOver = 0;
                func_800F9C0C_BowlOver(obj, obj->trans.x + 100.0f, obj->trans.y + 50.0f, obj->trans.z - 10.0f);
                PlaySound(0x257);
            }
            break;
    }
}

// switch shapes and register allocation
#ifdef NON_MATCHING
void func_800F8274_BowlOver(omObjData* obj) {
    BowlPlayerWork* w;
    u8 port;
    u16 btn;
    s16 i;
    f32 sum;
    f32 avg;
    u16* trg;

    w = PLAYER_WORK(obj);
    port = w->unk_56;
    btn = 0;
    if (GwPlayer[w->unk_58].flags & 1) {
        if (D_800FD32C_BowlOver[0] == 0) {
            switch (GwPlayer[w->unk_58].cpu_difficulty) {
                case 0:
                    D_800FD834_BowlOver = -10.0f;
                    break;
                case 1:
                    D_800FD834_BowlOver = 0.0f;
                    break;
                case 2:
                    D_800FD834_BowlOver = 3.0f;
                    break;
                case 3:
                    D_800FD834_BowlOver = 5.0f;
                    break;
            }
            switch (D_800FD3D0_BowlOver[0]) {
                case 0:
                    D_800FD838_BowlOver = 0x5A;
                    D_800FD83A_BowlOver = 0x64;
                    D_800FD83C_BowlOver = 0x78;
                    D_800FD83E_BowlOver = 0x118;
                    D_800FD840_BowlOver = 0x15E;
                    break;
                case 1:
                    D_800FD838_BowlOver = 0x64;
                    D_800FD83A_BowlOver = 0x78;
                    D_800FD83C_BowlOver = 0x7D;
                    D_800FD83E_BowlOver = 0xCD;
                    D_800FD840_BowlOver = 0x122;
                    break;
                case 2:
                    D_800FD838_BowlOver = 0x5A;
                    D_800FD83A_BowlOver = 0x76;
                    D_800FD83C_BowlOver = 0x78;
                    D_800FD83E_BowlOver = 0xC2;
                    D_800FD840_BowlOver = 0x15A;
                    break;
            }
            switch (GwPlayer[w->unk_58].cpu_difficulty) {
                case 0:
                    D_800FD83E_BowlOver -= guRandom() % 30;
                    break;
                case 1:
                    D_800FD83E_BowlOver -= guRandom() % 10;
                    break;
            }
            D_800FD32C_BowlOver[0] = 1;
        }
        sum = 0.0f;
        for (i = 0; i < 3; i++) {
            sum += D_800FD860_BowlOver[i]->trans.x;
        }
        avg = sum / 3.0f;
        if (D_800FD330_BowlOver == D_800FD838_BowlOver) {
            switch (D_800FD3D0_BowlOver[0]) {
                case 0:
                    D_800FD334_BowlOver = 0.0f;
                    break;
                case 1:
                case 2:
                    D_800FD334_BowlOver = -50.0f;
                    break;
            }
        }
        if (D_800FD330_BowlOver == D_800FD83A_BowlOver) {
            D_800FD334_BowlOver = 0.0f;
        }
        if (D_800FD330_BowlOver == D_800FD83C_BowlOver) {
            btn = 0x8000;
        }
        if (D_800FD83E_BowlOver < D_800FD330_BowlOver && D_800FD330_BowlOver < D_800FD83E_BowlOver + 10) {
            switch (D_800FD3D0_BowlOver[0]) {
                case 0:
                    D_800FD334_BowlOver = -5.0f;
                    break;
                case 1:
                    D_800FD334_BowlOver = -20.0f;
                    break;
                case 2:
                    D_800FD334_BowlOver = -10.0f;
                    break;
            }
        }
        switch (D_800FD3D0_BowlOver[0]) {
            case 0:
                if (D_800FD330_BowlOver == 0x11A) {
                    D_800FD334_BowlOver = 0.0f;
                }
                break;
            case 1:
                if (D_800FD330_BowlOver == 0xDC) {
                    D_800FD334_BowlOver = 0.0f;
                }
                break;
            case 2:
                if ((u32)(D_800FD330_BowlOver - 0xE7) < 0x12) {
                    D_800FD334_BowlOver = 70.0f;
                }
                if ((u32)(D_800FD330_BowlOver - 0x109) < 0x23) {
                    D_800FD334_BowlOver = -70.0f;
                }
                if (D_800FD330_BowlOver == 0x12D) {
                    D_800FD334_BowlOver = 0.0f;
                }
                break;
        }
        if (D_800FD840_BowlOver < D_800FD330_BowlOver) {
            switch (D_800FD3D0_BowlOver[0]) {
                case 0:
                case 2:
                    if (D_800FD878_BowlOver->trans.x < avg) {
                        D_800FD334_BowlOver = D_800FD834_BowlOver + 40.0f;
                    } else {
                        D_800FD334_BowlOver = -40.0f - D_800FD834_BowlOver;
                    }
                    break;
                case 1:
                    if (D_800FD878_BowlOver->trans.x < avg) {
                        D_800FD334_BowlOver = D_800FD834_BowlOver + 16.0f;
                    } else {
                        D_800FD334_BowlOver = -16.0f - D_800FD834_BowlOver;
                    }
                    break;
            }
        }
        if (ContBtn[(s8)port] & 0x1000) {
            btn |= 0x1000;
        }
        trg = &ContBtnTrg[(s8)port];
        ContBtn[(s8)port] = btn;
        *trg = btn;
        *trg = btn & (btn ^ D_800FD32C_BowlOver[1]);
        D_800FD32C_BowlOver[1] = btn;
        if (D_800FD334_BowlOver == -1.0f) {
            ContStkX[(s8)port] = 0;
            ContStkY[(s8)port] = 0;
        } else {
            ContStkX[(s8)port] = D_800FD334_BowlOver;
            ContStkY[(s8)port] = 0;
        }
    }
    D_800FD330_BowlOver++;
    func_800F7E20_BowlOver(obj);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_11_BowlOver/13EFB0", func_800F8274_BowlOver);
#endif

// argument register copy order
// decomp-permuter
void func_800F8964_BowlOver(omObjData *obj, s32 dir, s32 file, s32 player, f32 x, f32 y, f32 z)
{
  BowlPlayerWork *w;
  unsigned short new_var;
  u32 chr;
  new_var = player;
  obj->unk_50 = func_80023684(sizeof(BowlPlayerWork), 0x7918);
  func_8009B770(obj->unk_50, 0, sizeof(BowlPlayerWork));
  w = (BowlPlayerWork *) obj->unk_50;
  w->unk_D8 = func_80023684(obj->mtncnt * 4, 0x7918);
  w->unk_56 = GwPlayer[(u16) new_var].port;
  obj->model[0] = LoadFormFile(dir | file, 0x699);
  obj->model[1] = func_800174F4(6, 0x699);
  guRandom();
  func_8001775C(obj, 0, dir | 0x10);
  guRandom();
  func_8001775C(obj, 1, dir | 0xF);
  func_8001775C(obj, 2, dir | 0x75);
  func_8001775C(obj, 3, dir | 0x6A);
  func_8001775C(obj, 4, dir);
  func_800093FC(obj, x, y, z);
  chr = ((u32) dir) >> 16;
  func_80025798(obj->model[0], x, y, z);
  func_8000940C(obj, 0.0f, 180.0f, 0.0f);
  obj->scale.x = 1.5f;
  obj->scale.y = 1.5f;
  obj->scale.z = 1.5f;
  obj->func_ptr = func_800F8274_BowlOver;
  w->unk_52 = 0;
  w->unk_A4 = 1.0f;
  w->unk_C0 = 0xFFFF;
  w->unk_38 = 1000.0f;
  w->unk_50 = 0;
  func_80008FD0(obj, 60.0f);
  func_80008FDC(obj, 150.0f);
  func_80008FE8(obj, 20.0f);
  func_800090C4(obj, 0, 2);
  switch (chr)
  {
    case 5:
      w->unk_A0 = 0.7f;
      break;

    case 3:
      w->unk_A0 = 0.9f;
      break;

    case 4:
      w->unk_A0 = 0.8f;
      break;

    default:
      w->unk_A0 = 1.0f;
      break;

  }

  w->unk_58 = new_var;
  func_80025BB8(obj->model[0], obj->motion[2]);
  func_80025EB4(obj->model[0], 1, 1);
  D_800FD5AC_BowlOver[D_800FDC5A_BowlOver[0]] = GwPlayer[D_800FDC5A_BowlOver[0]].coins;
}

// register allocation and float temporaries
#ifdef NON_MATCHING
void func_800F8C64_BowlOver(omObjData* obj) {
    f32 turn;
    s8 vol;
    s16 pitch;
    s32 t;
    s16 snd;
    u8 v;
    s8 a;

    if (D_800ED430 != 1) {
        return;
    }
    if (BALL_WORK(obj)->unk_50 & 0x20) {
        return;
    }
    func_80025F10(obj->model[1], D_800FDC58_BowlOver);
    func_800F9B78_BowlOver(obj);
    if (D_800FD2D0_BowlOver[0] == 1) {
        return;
    }
    if (obj->trans.z > -5450.0f) {
        if (obj->trans.y <= 0.0f) {
            obj->trans.y = 0.0f;
            if (D_800FD351_BowlOver == 0) {
                D_800FD842_BowlOver[0] = PlaySound(0x258);
                D_800FD842_BowlOver[1] = snd = PlaySound(0x25A);
                func_8006035C(snd, 0);
                D_800FD351_BowlOver = 1;
            }
        } else {
            obj->trans.y -= D_800FD33C_BowlOver;
            D_800FD33C_BowlOver *= 1.2f;
        }
        D_800FD348_BowlOver = 25.0f;
        D_800FD340_BowlOver = ContStkX[(s8)PLAYER_WORK(D_800F3FB0[0])->unk_56] * 1.6;
        D_800FD34C_BowlOver -= D_800FD340_BowlOver;
        turn = D_800FD34C_BowlOver / 9.0f;
        if (!(BOWL_ABS(turn) < 263.0f)) {
            turn = 263.0f;
        }
        obj->rot.y = turn + obj->rot.y;
        D_800FD344_BowlOver -= D_800FD34C_BowlOver / 1700.0f;
        D_800FD34C_BowlOver *= 0.9;
        t = fabs((turn / 263.0f) * 200.0f);
        vol = t;
        if (vol > 0x5E) {
            vol = 0x5E;
        }
        t = fabs(turn / 120.0f) * 500.0 + -500.0;
        pitch = t;
        if (pitch > 0) {
            pitch = 0;
        }
        if (D_800FD350_BowlOver == 0) {
            if (D_800FD2D8_BowlOver == 1) {
                v = D_800FD338_BowlOver[0];
                D_800FD338_BowlOver[0] = v - 2;
                a = v + 0x7D;
                if (a < 0) {
                    a = 0;
                }
                func_8006035C(D_800FD842_BowlOver[0], a);
                vol += D_800FD338_BowlOver[0];
                if (vol < 0) {
                    vol = 0;
                }
                func_8006035C(D_800FD842_BowlOver[1], vol);
            } else {
                func_8006035C(D_800FD842_BowlOver[1], vol);
            }
            func_80060440(D_800FD842_BowlOver[1], pitch);
        }
        obj->trans.x += D_800FD344_BowlOver;
        D_800FD348_BowlOver *= 0.95;
        obj->trans.z -= D_800FD348_BowlOver;
        CenterM[1].z -= D_800FD348_BowlOver;
        CenterM[1].x += D_800FD344_BowlOver;
        func_800FA080_BowlOver(obj, &D_800FD344_BowlOver, &D_800FD348_BowlOver);
        if (D_800FD2DC_BowlOver[0] == 0) {
            if (D_800FD2D8_BowlOver == 0 && obj->trans.z < -4300.0f) {
                D_800FD2D8_BowlOver = 1;
            }
        } else if (D_800FD350_BowlOver == 0) {
            func_8006071C(D_800FD842_BowlOver[0]);
            func_8006071C(D_800FD842_BowlOver[1]);
            D_800FD350_BowlOver = 1;
        }
    } else {
        D_800FD348_BowlOver = 25.0f;
        obj->trans.y -= 10.0f;
        if (obj->trans.y < -100.0f) {
            if (D_800FD350_BowlOver == 0) {
                func_8006071C(D_800FD842_BowlOver[0]);
                func_8006071C(D_800FD842_BowlOver[1]);
                D_800FD350_BowlOver = 1;
            }
            D_800FD2D0_BowlOver[0] = 1;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_11_BowlOver/13EFB0", func_800F8C64_BowlOver);
#endif

void func_800F91D0_BowlOver(omObjData* obj) {
    BowlBallWork* w;
    u16 img;

    obj->unk_50 = w = func_80023684(sizeof(BowlBallWork), 0x7918);
    func_8009B770(w, 0, sizeof(BowlBallWork));
    obj->model[0] = func_800174F4(0x11, 0x499);
    obj->model[1] = func_800174F4(6, 0x699);
    obj->model[2] = func_800174F4(0x11, 0x489);
    func_800F9838_BowlOver(obj->model[2], 0xFF, 0xC0, 0x20);
    func_80025B34(obj->model[2]);
    func_800258EC(obj->model[2], 4, 4);
    img = ReadImgPackand(0x23000F, 0xA89, 8);
    obj->model[3] = D_800ECDE0[img].unk_00;
    func_80025930(obj->model[3], 0x70000000, 0x70000000);
    func_8001E360(img, 0xB4, 0xC8, 0xFF);
    func_800258EC(obj->model[3], 4, 4);
    obj->model[4] = func_800174F4(0x19, 0x68D);
    func_800258EC(obj->model[4], 4, 4);
    obj->model[5] = func_800174F4(0x230007, 0x68D);
    func_800258EC(obj->model[5], 4, 4);
    obj->model[6] = func_800174F4(0x230008, 0x68D);
    func_800258EC(obj->model[6], 4, 4);
    w->unk_60 = 0;
    w->unk_54 = 1;
    w->unk_44 = 0.1f;
    w->unk_48 = 30.0f;
    w->unk_34 = 50.0f;
    w->unk_3C = 0.0f;
    w->unk_5C = 0;
    w->unk_38 = 1000.0f;
    w->unk_52 = 3;
    w->unk_58 = 0.5f;
    w->unk_50 = 0x40;
    obj->trans.x = 0.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80025F10(obj->model[1], 0);
    obj->func_ptr = func_800F8C64_BowlOver;
}

void func_800F9450_BowlOver(void) {
    omObjData* obj;
    s16 i;

    InitCameras(2);
    obj = omAddObj(0x7FDA, 0, 0, -1, func_800F9668_BowlOver);
    omSetStatBit(obj, 0xA0);
    for (i = 0; i < 2; i++) {
        func_8001D494(i, 53.0f, 80.0f, 8000.0f);
        func_8001D520(i, &D_800FD354_BowlOver[i], &D_800FD36C_BowlOver[i]);
        func_8001D4D4(i, &D_800FD384_BowlOver[i]);
    }
    func_800F9A80_BowlOver(0, 939.0f, 326.0f, 0.0f, 0.0f, 0.0f, -86.8f, -4828.6f);
    func_800F9A80_BowlOver(1, 1900.0f, 360.5f, 0.0f, 0.0f, 0.0f, 350.0f, -860.0f);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_800176C4(1, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_800F9668_BowlOver(obj);
}

void func_800F9668_BowlOver(omObjData* obj) {
    Vec3f eye;
    Vec3f at;
    Vec3f up;
    f32 rx;
    f32 ry;
    s16 i;

    for (i = 0; i < 2; i++) {
        rx = CRotM[i].x;
        ry = CRotM[i].y;
        eye.x = func_800AEAC0(ry) * func_800AEFD0(rx) * CZoomM[i] + CenterM[i].x;
        eye.y = -func_800AEAC0(rx) * CZoomM[i] + CenterM[i].y;
        eye.z = func_800AEFD0(ry) * func_800AEFD0(rx) * CZoomM[i] + CenterM[i].z;
        at.x = CenterM[i].x;
        at.y = CenterM[i].y;
        at.z = CenterM[i].z;
        up.x = func_800AEAC0(ry) * func_800AEAC0(rx);
        up.y = func_800AEFD0(rx);
        up.z = func_800AEFD0(ry) * func_800AEAC0(rx);
        func_8001D420(i, &eye, &at, &up);
        func_8001D57C(i);
    }
}

void func_800F9838_BowlOver(s16 mdl, u8 r, u8 g, u8 b) {
    unk2C0C0StructC0* m;
    unk2C0C0Struct30* grp;
    s16 i;
    s16 j;

    m = D_800F2B7C[mdl].unk_6C;
    for (i = 0; i < m->unk_6A; i++) {
        grp = &m->unk_80[i];
        for (j = 0; j < (s16)grp->unk_04; j++) {
            grp->unk_34[j].unk_00 |= 0x80;
            grp->unk_34[j].unk_2C[0] = grp->unk_34[j].unk_2C[1] = grp->unk_34[j].unk_2C[2] =
                grp->unk_34[j].unk_2C[3] = 0;
        }
    }
    func_80025AD4(mdl);
    func_800F9990_BowlOver(mdl, r, g, b);
}

void func_800F9990_BowlOver(s16 mdl, u8 r, u8 g, u8 b) {
    unk2C0C0StructC0* m;
    unk2C0C0StructE0* v;
    s16 i;
    s16 j;
    s16 n;

    m = D_800F2B7C[mdl].unk_6C;
    if (m == NULL) {
        return;
    }
    for (i = 0; i < m->unk_6A; i++) {
        n = m->unk_80[i].unk_0C;
        v = &m->unk_08[D_800F37F0][m->unk_80[i].unk_0A];
        for (j = 0; j < n; j++) {
            v->unk_0C.r = r;
            v->unk_0C.g = g;
            v->unk_0C.b = b;
            v++;
        }
    }
}

void func_800F9A80_BowlOver(s16 cam, f32 zoom, f32 rx, f32 ry, f32 rz, f32 cx, f32 cy, f32 cz) {
    CZoomM[cam] = zoom;
    CRotM[cam].x = rx;
    CRotM[cam].y = ry;
    CRotM[cam].z = rz;
    CenterM[cam].x = cx;
    CenterM[cam].y = cy;
    CenterM[cam].z = cz;
}

void func_800F9B00_BowlOver(omObjData* obj) {
    if (D_800F5144 == 1) {
        if (D_800FD3B0_BowlOver == 0) {
            func_800726AC(0, 0x14);
            D_800FD3B0_BowlOver = 1;
        } else if (func_80072718() == 0) {
            func_800601D4(0x28);
            GMesSprClose();
            omOvlReturnEx(1);
        }
    }
}

// decomp-permuter
void func_800F9B78_BowlOver(omObjData *obj)
{
  f32 s;
  omObjData *new_var2;
  float new_var;
  s = 0.4f - (obj->trans.y * 0.0015f);
  ;
  new_var = 1.0f;
  func_80025830(obj->model[1], s * 2.5, new_var, s * 2.5);
  new_var2 = obj;
  func_80025798(obj->model[1], new_var2->trans.x, (float) 3.0f, obj->trans.z);
}

void func_800F9C0C_BowlOver(omObjData* obj, f32 x, f32 y, f32 z) {
    BowlPlayerWork* w;
    omObjData* ball;
    BowlBallWork* bw;

    w = PLAYER_WORK(obj);
    ball = w->unk_B8;
    bw = BALL_WORK(ball);
    w->unk_50 &= ~0x20;
    bw->unk_50 &= ~0x20;
    func_800258EC(ball->model[0], 0x4000, 0);
    func_800284E4(obj->model[0]);
    bw->unk_38 = -D_800FD3B4_BowlOver * 0.8f;
    bw->unk_3C = w->unk_3C;
    ball->trans.x = x;
    ball->trans.y = y;
    ball->trans.z = z;
    w->unk_B8 = NULL;
    w->unk_A4 = 1.0f;
}

s32 func_800F9CF8_BowlOver(omObjData* obj, omObjData* ball) {
    BowlPlayerWork* w;
    BowlBallWork* bw;
    u16 f;

    w = PLAYER_WORK(obj);
    bw = BALL_WORK(ball);

    if (bw->unk_50 & 0x40) {
        if (!(((volatile BowlBallWork*)bw)->unk_50 & 0x20)) { /* retail reloads the flags */
            f = w->unk_50;
            if (f & 0x20) {
                return 0;
            }
            w->unk_50 = f | 0x20;
            bw->unk_50 |= 0x20;
            w->unk_B8 = ball;
            func_8002859C(ball->model[0], obj->model[0], "item_hook");
            func_800258EC(ball->model[0], 0x4000, 0x4000);
            w->unk_A4 = bw->unk_58;
            return 1;
        }
    }
    return 0;
}

f32 func_800F9DB4_BowlOver(void) {
    s8 x;
    s8 y;
    s8 port;
    f32 ret;
    s16 i;
    f32 sx;
    f32 sy;

    port = PLAYER_WORK(D_800F3FB0[0])->unk_56;
    y = ContStkY[port];
    x = ContStkX[port];
    if (x > 60) {
        x = 60;
    }
    if (y > 60) {
        y = 60;
    }
    if (x < -60) {
        x = -60;
    }
    if (y < -60) {
        y = -60;
    }
    D_800FD3B8_BowlOver[D_800FD3C8_BowlOver] = (f32)x;
    D_800FD3C0_BowlOver[D_800FD3C8_BowlOver] = (f32)y;
    D_800FD3C8_BowlOver = ((u8)D_800FD3C8_BowlOver + 1) & 7;
    sx = 0.0f;
    sy = 0.0f;
    for (i = 0; i < 8; i++) {
        sx += D_800FD3B8_BowlOver[i];
        sy += D_800FD3C0_BowlOver[i];
    }
    sx /= 8.0f;
    sy /= 8.0f;
    if (sx * sx + sy * sy > 100.0f) {
        ret = func_800B0CD8(sx, -sy) + 180.0f;
    } else {
        ret = -1.0f;
    }
    return ret;
}

f32 func_800F9F80_BowlOver(void) {
    s8 x;
    s8 y;
    s8 port;
    f32 ret;
    f32 sx;
    f32 sy;

    port = PLAYER_WORK(D_800F3FB0[0])->unk_56;
    y = ContStkY[port];
    x = ContStkX[port];
    if (x > 60) {
        x = 60;
    }
    if (y > 60) {
        y = 60;
    }
    if (x < -60) {
        x = -60;
    }
    if (y < -60) {
        y = -60;
    }
    sx = x;
    sy = y;
    if (sx * sx + sy * sy > 100.0f) {
        ret = func_800B0CD8(sx, -sy) + 180.0f;
    } else {
        ret = -1.0f;
    }
    return ret;
}

s32 func_800FA080_BowlOver(omObjData* obj, f32* dx, f32* dz) {
    BowlProbe probe;
    s32 hit;

    hit = 0;
    if (obj->trans.z > -4700.0f) {
        probe.pos.x = obj->trans.x;
        probe.pos.y = obj->trans.y;
        probe.pos.z = obj->trans.z;
        probe.hit = 0;
        func_8002AE24(D_800F2AF8[0]->model[0], &D_800EDEC0, func_80002060, &probe);
        if (func_8002B3A8(&D_800EDEC0) == 0) {
            D_800FD2D0_BowlOver[0] = 1;
            D_800FD2DC_BowlOver[0] = 1;
            PlaySound(0x25B);
        }
    } else {
        if (obj->trans.x < -250.0f) {
            obj->trans.x = -250.0f;
            *dx = 20.0f;
            hit = 1;
            PlaySound(0x265);
        }
        if (obj->trans.x > 250.0f) {
            obj->trans.x = 250.0f;
            *dx = -20.0f;
            hit = 1;
            PlaySound(0x265);
        }
    }
    return hit;
}

/* Rotation of angle about axis, translated (retail uses pos->z where pos->x would be expected). */
// float register allocation
#ifdef NON_MATCHING
void func_800FA1D8_BowlOver(Vec3f* pos, Vec3f* axis, f32 angle, Mat4 m) {
    f32 s;
    f32 c;
    f32 t;
    f32 x;
    f32 y;
    f32 z;
    f32 xx;
    f32 yy;
    f32 zz;
    f32 xs;
    f32 ys;
    f32 zs;
    f32 xy;
    f32 xz;
    f32 yz;
    f32 py;
    f32 pz;

    func_800AF2E0(angle, &s, &c);
    t = 1.0f - c;
    pz = pos->z;
    py = pos->y;
    x = axis->x;
    y = axis->y;
    z = axis->z;
    xx = x * x;
    yy = y * y;
    zz = z * z;
    xs = x * s;
    ys = y * s;
    zs = z * s;
    m[3][3] = 1.0f;
    m[2][3] = 0.0f;
    m[1][3] = 0.0f;
    m[0][3] = 0.0f;
    m[0][0] = t * xx + c;
    xy = t * (x * y);
    m[0][1] = xy + zs;
    xz = t * (z * x);
    m[0][2] = xz - ys;
    m[1][0] = xy - zs;
    m[1][1] = t * yy + c;
    yz = t * (y * z);
    m[1][2] = yz + xs;
    m[2][0] = xz + ys;
    m[2][1] = yz - xs;
    m[2][2] = t * zz + c;
    m[3][0] = pz * t * (1.0f - xx) + py * (zs - xy) - pz * (xz + ys);
    m[3][1] = -pz * (xy + zs) + py * t * (1.0f - yy) + pz * (xs - yz);
    m[3][2] = pz * (ys - xz) - py * (yz + xs) + pz * t * (1.0f - zz);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_11_BowlOver/13EFB0", func_800FA1D8_BowlOver);
#endif

// register allocation (masked 2, raw 30): rand8 result copied to s0 before its andi, hi in a0 not a1;
// tried lo local, seed % 127773 (M1c)
#ifdef NON_MATCHING
s32 func_800FA3D0_BowlOver(u32 seed) {
    u32 hi;

    if (seed == 0) {
        seed = rand8() ^ guRandom() ^ 0xD826BC89;
    }
    hi = seed / 127773;
    seed -= hi * 127773;
    return hi * 2836 - seed * 16807;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_11_BowlOver/13EFB0", func_800FA3D0_BowlOver);
#endif

u32 func_800FA4A4_BowlOver(void) {
    return D_800FD3CC_BowlOver = func_800FA3D0_BowlOver(D_800FD3CC_BowlOver);
}

/* Trailing zero words of the unit's .rodata (retail pads it to the next unit's 16-byte start). */
const s32 D_800FD7B8_BowlOver[2] = { 0, 0 };
