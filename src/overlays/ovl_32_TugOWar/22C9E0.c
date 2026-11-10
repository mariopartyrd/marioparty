#include "common.h"
#include "TugOWar.h"

/* .data (0x800FDAE0..0x800FDB00) */
s8 D_800FDAE0_TugOWar[2] = { 0, 0 };
s8 D_800FDAE2_TugOWar = 0; /* result jingle started */
s32 D_800FDAE4_TugOWar = 929; /* time left, frames */
s32 D_800FDAE8_TugOWar = 0;
s8 D_800FDAEC_TugOWar = 0;
s8 D_800FDAED_TugOWar = 0;
s8 D_800FDAEE_TugOWar = 0;
s8 D_800FDAEF_TugOWar = 0;
s8 D_800FDAF0_TugOWar = 0;
s8 D_800FDAF1_TugOWar = 0;
s8 D_800FDAF2_TugOWar = 0;
u16 D_800FDAF4_TugOWar = 0;
s8 D_800FDAF6_TugOWar = 0;
f32 D_800FDAF8_TugOWar = 0.0f;
f32 D_800FDAFC_TugOWar = 0.0f;

/* "ＳＴＡＲＴ" */
const char D_800FDC30_TugOWar[] __attribute__((section(".rodata"))) = "\x82\x72\x82\x73\x82\x60\x82\x71\x82\x73";

/* Minigame setup: the solo player is the one of group 0, the other three are the team. */
void func_800F65E0_TugOWar(void) {
    s16 i;
    s16 j;
    s16 human;

    D_800FDFB3_TugOWar = _CheckFlag(0x45);
    for (i = 0; i < 4; i++) {
        if (GwPlayer[i].group == 0) {
            break;
        }
    }
    switch (i) {
    case 1:
        D_800FDFAE_TugOWar[0] = 1;
        break;
    case 2:
        D_800FDFAE_TugOWar[0] = 2;
        break;
    case 3:
        D_800FDFAE_TugOWar[0] = 3;
        break;
    case 0:
    default:
        D_800FDFAE_TugOWar[0] = 0;
        break;
    }
    for (i = 1, j = 0; i < 4; i++) {
        if (D_800FDFAE_TugOWar[0] == j) {
            j++;
        }
        D_800FDFAE_TugOWar[i] = j;
        j++;
    }
    func_80029090(0x14);
    func_8002ADF0(&D_800EDEC0, 0x40);
    func_8001DE70(0x20);
    omInitObjMan(0x1E, 0);
    func_80060088();
    D_800C3000 = 1;
    InitCameras(1);
    D_800C3110->unk_40 = 53.0f;
    D_800C3001 = 0;
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    func_80017660(0, 0.0f, 0.0f, 319.0f, 239.0f);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 53.0f, 80.0f, 8000.0f);
    func_800FAD80_TugOWar(225.0f, 349.5f, 0.0f, 0.0f, 0.0f, 625.0f, -730.0f);
    func_8000942C();
    func_80009468();
    func_80009500();
    func_80009618(0);
    func_8007B168((u8*)D_800FDC30_TugOWar, 1);
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    func_800FDA4C_TugOWar();
    func_800FAC28_TugOWar();
    omAddObj(0x32, 0, 0, -1, func_800F69C0_TugOWar);
    omAddObj(0, 0, 0, -1, func_800FADC0_TugOWar);
    if (D_800FDFB3_TugOWar == 0) {
        SetFadeInTypeAndTime(0, 0x10);
    } else {
        SetFadeInTypeAndTime(3, 0x10);
    }
    /* with no human player, one side (at random) pulls at 3/4 strength */
    if (guRandom() & 1) {
        D_800FDFB4_TugOWar = 0;
    } else {
        D_800FDFB4_TugOWar = 1;
    }
    human = 0;
    for (i = 0; i < 4; i++) {
        if (!(GwPlayer[i].flags & 1)) {
            human = 1;
        }
    }
    if (human != 0) {
        D_800FDFB4_TugOWar = 2;
    }
}

/* The game flow: instructions, the timer, the result and the exit. */
// logic-equivalent; branch layout of the result cases differs (masked 34)
#ifdef NON_MATCHING
void func_800F69C0_TugOWar(omObjData* obj) {
    s16 i;

    /* retail first copies each player's work and pull pointers to the stack, unused */
    func_80009468();
    switch (D_800ED430) {
    case 0:
        if (D_800FDBE5_TugOWar == 1 && D_800FDAED_TugOWar == 0) {
            GMesCreate(0);
            D_800FDAED_TugOWar = 1;
        }
        if (D_800FDAED_TugOWar == 1) {
            if (GMesStatAllGet() == 0 || (GMesStatAllGet() & 2)) {
                GMesCreate(8, 60, 160, 24);
                func_80079078(30);
                func_80009458();
            }
        }
        break;
    case 1:
        if (D_800FDAE0_TugOWar[0] != 1) {
            if (D_800FDAE0_TugOWar[1] != 1) {
                func_80079078(D_800FDAE4_TugOWar / 30);
                if (--D_800FDAE4_TugOWar == 0) {
                    D_800FDAE0_TugOWar[0] = 1;
                    D_800FDB16_TugOWar = 2;
                }
            }
            if (D_800FDAE0_TugOWar[0] != 1) {
                break;
            }
        }
        if (D_800FDB16_TugOWar == 2 && D_800FDAEE_TugOWar == 0) {
            /* time up: everyone stops */
            for (i = 0; i < 4; i++) {
                func_80025EB4(D_800F3FB0[i]->model[0], 2, 0);
                func_80025C20(D_800F3FB0[i]->model[0], func_80025E48(D_800F3FB0[i]->motion[0]), 0, 10, 1);
            }
            D_800FDAE8_TugOWar = 13;
            D_800FDAEE_TugOWar = 1;
        }
        if (D_800FDAE8_TugOWar++ >= 13) {
            func_8006073C();
            if (D_800FDB16_TugOWar == 2) {
                if (_CheckFlag(0x2B) == 0) {
                    GMesCreate(0x11);
                    D_800FDAFC_TugOWar = 90.0f;
                } else {
                    GMesCreate(2);
                    D_800FDAFC_TugOWar = 105.0f;
                }
            } else if (D_800FDB16_TugOWar >= 0 && D_800FDB16_TugOWar < 2) {
                GMesCreate(2);
                D_800FDAFC_TugOWar = 105.0f;
            }
            func_800790C0();
            D_800FDAF6_TugOWar = 1;
            func_80009438();
        }
        break;
    case 2:
        if (_CheckFlag(0x2B) == 0) {
            if (GMesStatAllGet() == 0 || (GMesStatAllGet() & 2)) {
                if (D_800FDAE2_TugOWar == 0) {
                    switch (D_800FDB16_TugOWar) {
                    case 0:
                        func_80060128(0x32);
                        break;
                    case 1:
                        func_80060128(0x36);
                        break;
                    case 2:
                        func_80060128(0x35);
                        break;
                    }
                    D_800FDAE2_TugOWar = 1;
                }
                if (D_800FDAF1_TugOWar == 0) {
                    if (D_800FDB16_TugOWar != 2) {
                        /* the camera moves to the winner in 27 steps */
                        if (D_800FDAF2_TugOWar == 0) {
                            D_800FDAF4_TugOWar = 0;
                            D_800FDDE0_TugOWar[0] = Center.z - 256.0f;
                            D_800FDDE0_TugOWar[1] = Center.y - 595.0f;
                            if (D_800FDB16_TugOWar == 0) {
                                D_800FDDE0_TugOWar[2] = Center.x - -290.0f;
                            } else {
                                D_800FDDE0_TugOWar[2] = Center.x - 640.0f;
                            }
                            for (i = 0; i < 3; i++) {
                                D_800FDDE0_TugOWar[i] /= 27.0f;
                            }
                            D_800FDAF2_TugOWar = 1;
                        }
                        Center.z -= D_800FDDE0_TugOWar[0];
                        Center.y -= D_800FDDE0_TugOWar[1];
                        Center.x -= D_800FDDE0_TugOWar[2];
                        D_800FDBE0_TugOWar += 0.01;
                        D_800FDAF4_TugOWar++;
                        if ((s16)D_800FDAF4_TugOWar > 27.0f) {
                            D_800FDAF1_TugOWar = 1;
                        }
                    } else if (GMesWait() == 0) {
                        func_80009448();
                    }
                }
                if (D_800FDAF1_TugOWar == 1 && GMesWait() == 0) {
                    if (D_800FDAEF_TugOWar == 0) {
                        if (D_800FDB16_TugOWar != D_800FDAF1_TugOWar) {
                            switch (D_800FDB16_TugOWar) {
                            case 0:
                                GMesCreate(4, GwPlayer[D_800FDFAE_TugOWar[0]].character);
                                break;
                            case 2:
                                GMesCreate(0x10);
                                break;
                            }
                        } else {
                            GMesCreate(0x13, GwPlayer[D_800FDFAE_TugOWar[1]].character,
                                       GwPlayer[D_800FDFAE_TugOWar[2]].character,
                                       GwPlayer[D_800FDFAE_TugOWar[3]].character);
                        }
                        D_800FDAEF_TugOWar = 1;
                    }
                    func_80009448();
                }
            }
        } else if (GMesWait() == 0) {
            func_80009448();
        }
        break;
    case 3:
        if (D_800FDAEC_TugOWar == 0) {
            if (GMesWait() == 0) {
                D_800FDAEC_TugOWar = 1;
            }
        } else if (D_800FDAF0_TugOWar == 0) {
            if (D_800FDAFC_TugOWar < D_800FDAF8_TugOWar) {
                func_800726AC(D_800FDFB3_TugOWar != 0 ? 3 : 0, 0x14);
                func_800601D4(0x28);
                D_800FDAF0_TugOWar = 1;
            }
        } else if (func_80072718() == 0) {
            GMesSprClose();
            omOvlReturnEx(1);
        }
        break;
    }
    if (D_800FDAF6_TugOWar == 1) {
        D_800FDAF8_TugOWar += 1.0f;
    }
    if ((D_800FDB10_TugOWar += 4) > 360) {
        D_800FDB10_TugOWar -= 360;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_32_TugOWar/22C9E0", func_800F69C0_TugOWar);
#endif
