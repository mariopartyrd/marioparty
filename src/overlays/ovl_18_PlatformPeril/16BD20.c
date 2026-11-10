#include "common.h"
#include "PlatformPeril.h"

s32 D_800FCD90_PlatformPeril = 0;
s32 D_800FCD94_PlatformPeril = 0;
s32 D_800FCD98_PlatformPeril = 0xFFFF;

void func_800F65E0_PlatformPeril(void) {
    func_8001DE70(0x20);
    omInitObjMan(0x32, 0);
    func_80060088();
    func_8000942C();
    func_8007B168((u8*)"\x82\x72\x82\x73\x82\x60\x82\x71\x82\x73", 1); /* "START" in full-width SJIS */
    func_8007B168((u8*)"\x82\x63\x82\x71\x82\x60\x82\x76", 1); /* "DRAW" */
    func_8007B168((u8*)"\x82\x65\x82\x68\x82\x6D\x82\x68\x82\x72\x82\x67", 1); /* "FINISH" */
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    omAddObj(4, 0, 0, -1, &func_800F66E8_PlatformPeril);
    omAddObj(1, 0, 0, 1, &func_800F6720_PlatformPeril);
    D_800B895C = 10.0f;
    SetFadeInTypeAndTime(0, 0x10);
}


void func_800F66E8_PlatformPeril(void) {
    if (D_800F5144 == 1) {
        func_800601D4(0x28);
        omOvlReturnEx(1);
    }
}

void func_800F6720_PlatformPeril(omObjData* arg0) {
    D_800FE2F8_PlatformPeril = 0;
    D_800FCD90_PlatformPeril = 0;
    func_800FC1DC_PlatformPeril();
    func_80009468();
    func_800F6F68_PlatformPeril();
    func_800F90C0_PlatformPeril();
    func_800F76E4_PlatformPeril();
    func_800F8B7C_PlatformPeril();
    func_800FC8E4_PlatformPeril();
    arg0->func_ptr = &func_800F6790_PlatformPeril;
}


// register allocation (masked 0): retail keeps the winner index in s0 from its load
#ifdef NON_MATCHING
void func_800F6790_PlatformPeril(void) {
    s32 w;
    omObjData** players;

    func_80009468();
    switch (D_800FE2F8_PlatformPeril) {
    case 0:
        D_800FE2F8_PlatformPeril = 1;
        break;
    case 1:
        if (func_800F6DF4_PlatformPeril() == 1) {
            func_80009458();
            func_80009468();
            D_800FE2F8_PlatformPeril = 2;
            D_800FE2FC_PlatformPeril = 0;
            D_800FCD90_PlatformPeril = 0;
        }
        break;
    case 2:
        if (D_800FCD90_PlatformPeril >= 0x2E) {
            func_800FCD44_PlatformPeril();
            D_800FE2F8_PlatformPeril = 3;
        }
        break;
    case 3:
        D_800FE2F8_PlatformPeril = 4;
        break;
    case 4:
        func_800FC17C_PlatformPeril();
        if (func_800F6E14_PlatformPeril() == 1) {
            GMesCreate(2);
            D_800FE2F8_PlatformPeril = 5;
            D_800FCD90_PlatformPeril = 0;
            func_800601D4(0x28);
        }
        break;
    case 5:
        func_800FC17C_PlatformPeril();
        if (D_800FCD90_PlatformPeril == 3) {
            func_800FC8D4_PlatformPeril();
        } else if (D_800FE540_PlatformPeril[D_800FE2C8_PlatformPeril]->trans.z < D_800FE2CC_PlatformPeril) {
            D_800FE2F8_PlatformPeril = 6;
            D_800FCD90_PlatformPeril = 0;
        }
        break;
    case 6:
        func_800FC17C_PlatformPeril();
        if (D_800FCD90_PlatformPeril == 1) {
            func_800FCB10_PlatformPeril(func_8005DB44(2)[D_800FE2C8_PlatformPeril]);
            GwPlayer[D_800FE2C8_PlatformPeril].coins_mg += 10;
            D_800FE1A0_PlatformPeril = 0;
        } else if (D_800FCD90_PlatformPeril >= 2) {
            if (D_800FE1A0_PlatformPeril == 0) {
                D_800FE1A0_PlatformPeril = func_800FCBD4_PlatformPeril();
            } else if (D_800FCD90_PlatformPeril >= 2) {
                if (_CheckFlag(0x2B) != 0) {
                    D_800FE2F8_PlatformPeril = 9;
                } else {
                    D_800FE2F8_PlatformPeril = 7;
                    D_800FCD94_PlatformPeril = 0;
                    D_800FCD98_PlatformPeril = 0xFFFF;
                }
            }
        }
        break;
    case 7:
        if (D_800FCD98_PlatformPeril == 0xFFFF) {
            func_80060128(0x32);
            players = func_8005DB44(2);
            w = D_800FE2C8_PlatformPeril;
            func_80025BB8(players[w]->model[0], players[w]->motion[13]);
            func_80025BB8(players[(w + 1) % 4]->model[0], players[(w + 1) % 4]->motion[14]);
            func_80025BB8(players[(w + 2) % 4]->model[0], players[(w + 2) % 4]->motion[14]);
            func_80025BB8(players[(w + 3) % 4]->model[0], players[(w + 3) % 4]->motion[14]);
            D_800FCD98_PlatformPeril = D_800FCD94_PlatformPeril;
        } else if (D_800FCD94_PlatformPeril == D_800FCD98_PlatformPeril + 0x2A) {
            GMesCreate(4, GwPlayer[D_800FE2C8_PlatformPeril].character);
            PlaySound(GwPlayer[D_800FE2C8_PlatformPeril].character + 0x451);
        } else if (D_800FCD94_PlatformPeril == D_800FCD98_PlatformPeril + 0xA8) {
            func_800726AC(0, 0x14);
        } else if (func_80072718() == 0 && D_800FCD98_PlatformPeril + 0xA8 < D_800FCD94_PlatformPeril) {
            omOvlReturnEx(1);
        }
        D_800FCD94_PlatformPeril++;
        break;
    case 8:
        if (D_800FCD94_PlatformPeril == 0) {
            func_800601D4(0x19);
        } else if (D_800FCD94_PlatformPeril == 0x1E) {
            GMesCreate(0x11);
        } else if (GMesStatAllGet() == 2 && D_800FCD98_PlatformPeril == 0xFFFF && D_800FCD94_PlatformPeril >= 0x1F) {
            func_80060128(0x34);
            D_800FCD98_PlatformPeril = D_800FCD94_PlatformPeril;
        } else if (D_800FCD94_PlatformPeril == D_800FCD98_PlatformPeril + 0xB4) {
            func_800726AC(0, 0x14);
        }
        if (func_80072718() == 0 && D_800FCD98_PlatformPeril + 0xB4 < D_800FCD94_PlatformPeril) {
            omOvlReturnEx(1);
        }
        D_800FCD94_PlatformPeril++;
        break;
    case 9:
        func_800FC17C_PlatformPeril();
        if (GMesWait() == 0) {
            func_80060398(0x28);
            func_800726AC(0, 0x14);
            D_800FE2F8_PlatformPeril = 10;
        }
        break;
    case 10:
        func_800FC17C_PlatformPeril();
        if (func_80072718() == 0) {
            omOvlReturnEx(1);
        }
        break;
    }
    D_800FCD90_PlatformPeril++;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_18_PlatformPeril/16BD20", func_800F6790_PlatformPeril);
#endif

s32 func_800F6DF4_PlatformPeril(void) {
    if (func_800FC95C_PlatformPeril()) {
        return 1;
    } else {
        return 0;
    }
}

/* 1 when every player has landed (work[2] != 0) and none is in state 4. */
s32 func_800F6E14_PlatformPeril(void) {
    s32 all = 1;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_800FE540_PlatformPeril[i]->work[2] == 0) {
            all = 0;
            break;
        }
        all &= -(D_800FE540_PlatformPeril[i]->work[2] != 4);
    }
    D_800FE2C4_PlatformPeril &= 0xF;
    if (D_800FE2C8_PlatformPeril != -1) {
        return 1;
    }
    if (all == 1) {
        D_800FE2F8_PlatformPeril = 8;
        return 0;
    }
    if (_CheckFlag(0x2B) != 0) {
        for (i = 0; i < 4; i++) {
            if (!(GwPlayer[i].flags & 1) && D_800FE540_PlatformPeril[i]->work[2] == 0xFF) {
                D_800FE2F8_PlatformPeril = 9;
                func_800601D4(0x28);
                GMesCreate(2);
                return 0;
            }
        }
    }
    return 0;
}

/* Used by func_800F7070 (16C6A0.c). */
const s32 D_800FDFB8_PlatformPeril[] __attribute__((aligned(8))) = { 5, 6, 7, 8, 9, 10 };
