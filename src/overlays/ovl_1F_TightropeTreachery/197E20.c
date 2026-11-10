#include "common.h"
#include "TightropeTreachery.h"

/* .data (0x800FE2B0..0x800FE300) */
s16 D_800FE2B0_TightropeTreachery = 0; /* the game is over */
s8 D_800FE2B2_TightropeTreachery = 0;  /* the start message is done (the timer runs) */
s8 D_800FE2B3_TightropeTreachery = 0;  /* the walker reached its start */
s8 D_800FE2B4_TightropeTreachery = 1;  /* the walker cannot be hit */
s8 D_800FE2B5_TightropeTreachery = 0;  /* result: 1 fell, 2 time up, 3 reached the goal */
s8 D_800FE2B6_TightropeTreachery = 0;  /* the timer is stopped */
s8 D_800FE2B7_TightropeTreachery = 0;  /* the rope is being pulled forward */
f32 D_800FE2B8_TightropeTreachery = 0.0f; /* this frame's camera advance */
s8 D_800FE2BC_TightropeTreachery = 0;
s8 D_800FE2BD_TightropeTreachery = 0;
s8 D_800FE2BE_TightropeTreachery = 0; /* the walker leans sideways */
s8 D_800FE2BF_TightropeTreachery = 0;
s8 D_800FE2C0_TightropeTreachery = 0; /* the walker is falling */
s8 D_800FE2C1_TightropeTreachery = 0; /* the walker reached the goal */
s8 D_800FE2C2_TightropeTreachery = 0; /* the splash is shown */
s8 D_800FE2C3_TightropeTreachery = 0; /* the music is stopped */
s8 D_800FE2C4_TightropeTreachery = 0;
s8 D_800FE2C5_TightropeTreachery = 0;
s8 D_800FE2C6_TightropeTreachery = 0;
s32 D_800FE2C8_TightropeTreachery = 0;
f32 D_800FE2CC_TightropeTreachery = 950.0f; /* z of the next rope pull */
s32 D_800FE2D0_TightropeTreachery = 0;
f32 D_800FE2D4_TightropeTreachery = 5.0f;
s16 D_800FE2D8_TightropeTreachery = 0; /* rope pulls so far */
u32 D_800FE2DC_TightropeTreachery = 0;
s8 D_800FE2E0_TightropeTreachery = 0;
s8 D_800FE2E1_TightropeTreachery = 0;
s32 D_800FE2E4_TightropeTreachery = 1829; /* time left, frames */
s32 D_800FE2E8_TightropeTreachery = 0;
s8 D_800FE2EC_TightropeTreachery = 0;
s32 D_800FE2F0_TightropeTreachery = 0;
s32 D_800FE2F4_TightropeTreachery = 0;
s8 D_800FE2F8_TightropeTreachery = 0;

/* "ＳＴＡＲＴ" */
const char D_800FE500_TightropeTreachery[] __attribute__((section(".rodata"))) = "\x82\x72\x82\x73\x82\x60\x82\x71\x82\x73";

/* Minigame setup: the player of group 0 walks the rope, the other three are the team. */
void func_800F65E0_TightropeTreachery(void) {
    s16 i;
    s16 j;
    omObjData* obj;

    for (i = 0; i < 4; i++) {
        if (GwPlayer[i].group == 0) {
            break;
        }
    }
    switch (i) {
    case 1:
        D_800FE8A0_TightropeTreachery[0] = 1;
        break;
    case 2:
        D_800FE8A0_TightropeTreachery[0] = 2;
        break;
    case 3:
        D_800FE8A0_TightropeTreachery[0] = 3;
        break;
    case 0:
    default:
        D_800FE8A0_TightropeTreachery[0] = 0;
        break;
    }
    for (i = 1, j = 0; i < 4; i++) {
        if (D_800FE8A0_TightropeTreachery[0] == j) {
            j++;
        }
        D_800FE8A0_TightropeTreachery[i] = j;
        j++;
    }
    func_80029090(10);
    func_8002ADF0(&D_800EDEC0, 0x40);
    func_8001DE70(0x40);
    omInitObjMan(0x1E, 0);
    func_80060088();
    func_80009500();
    D_800B896C = 100.0f;
    func_80009618(1);
    InitCameras(1);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    func_80017660(0, 0.0f, 0.0f, 319.0f, 239.0f);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 53.0f, 80.0f, 8000.0f);
    func_800F8B20_TightropeTreachery(1900.0f, 310.5f, 0.0f, 0.0f, 0.0f, -1000.0f, 85.0f);
    func_8000942C();
    func_80009468();
    func_8007B168((u8*)D_800FE500_TightropeTreachery, 1);
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    func_8002890C(0x8C, 0xFF, 0xFF);
    func_800090B8(D_800ED440);
    obj = D_800F2AF8[D_800ED440++] = omAddObj(0x1E, 10, 0, -1, func_800FAF34_TightropeTreachery);
    omSetStatBit(obj, 0xA0);
    obj = D_800F2AF8[D_800ED440++] = omAddObj(2, 3, 0, -1, func_800FB170_TightropeTreachery);
    omSetStatBit(obj, 0xA0);
    omAddObj(0, 0, 0, -1, func_800F8CA8_TightropeTreachery);
    omAddObj(0, 0, 0, -1, func_800F83E0_TightropeTreachery);
    D_800F3FB0[D_800F2BC0++] = omAddObj(3, 10, 0x46, -1, func_800F6BC8_TightropeTreachery);
    func_800FBDB8_TightropeTreachery();
    D_800F3FB0[D_800F2BC0++] = D_800FE700_TightropeTreachery[0] = omAddObj(3, 5, 8, -1, func_800FE040);
    D_800F3FB0[D_800F2BC0++] = D_800FE700_TightropeTreachery[1] = omAddObj(3, 5, 8, -1, func_800FE10C_TightropeTreachery);
    D_800F3FB0[D_800F2BC0++] = D_800FE700_TightropeTreachery[2] = omAddObj(3, 5, 8, -1, func_800FE1DC_TightropeTreachery);
    D_800EDE70[D_800EE984++] = D_800FE8B8_TightropeTreachery[0] = omAddObj(0x14, 8, 0, -1, func_800FCCDC_TightropeTreachery);
    D_800EDE70[D_800EE984++] = D_800FE8B8_TightropeTreachery[1] = omAddObj(0x14, 8, 0, -1, func_800FCCF8_TightropeTreachery);
    D_800EDE70[D_800EE984++] = D_800FE8B8_TightropeTreachery[2] = omAddObj(0x14, 8, 0, -1, func_800FCD14_TightropeTreachery);
    omAddObj(10, 1, 0, -1, func_800FBBD0_TightropeTreachery);
    SetFadeInTypeAndTime(0, 0x10);
}

void func_800F6BC8_TightropeTreachery(omObjData* obj) {
    u8 chr = GwPlayer[D_800FE8A0_TightropeTreachery[0]].character;
    s32 dir = D_800C59AC[chr].unk_00;
    s32 file = D_800C59AC[chr].unk_04;

    func_800F6E80_TightropeTreachery(obj, dir, file, D_800FE8A0_TightropeTreachery[0], 0.0f, 0.0f, 1270.0f);
}

/* The walker's collision callback: a bomb hit knocks it back and the bomb explodes. */
s32 func_800F6C44_TightropeTreachery(omObjData* obj, omObjData* other) {
    TTPlayerWork* w = obj->unk_50;
    TTBomb* bomb = ((TTItemWork*)other->unk_50)->bomb;
    s16 i;

    if (w->unk_AE != 0) {
        return 1;
    }
    w->unk_AE = 60;
    w->unk_50 &= 0x200;
    if (D_800FE2B4_TightropeTreachery == 1) {
        return 1;
    }
    if (D_800FE2B7_TightropeTreachery == 1) {
        return 1;
    }
    {
        f32 s = func_800AEAC0(w->angle);

        if (func_8000A72C(s, func_800AEFD0(w->angle), other->trans.x - obj->trans.x, other->trans.z - obj->trans.z) > 0.0f) {
            w->angle = func_800B0CD8(other->trans.x - obj->trans.x, other->trans.z - obj->trans.z);
            func_800184BC(obj, 9);
            w->speed = -4.55f;
        } else {
            w->angle = func_800B0CD8(other->trans.x - obj->trans.x, other->trans.z - obj->trans.z);
            func_800184BC(obj, 10);
            w->speed = 4.55f;
        }
    }
    func_80060F04(w->player, 30, 0, 30);
    PlaySound(0x2AC);
    bomb->active = 0;
    bomb->lit = 0;
    for (i = 0; i < 6; i++) {
        func_800258EC(other->model[i], 4, 4);
    }
    func_8001E2A8(bomb->mdl[2], 0);
    func_800258EC(other->model[5], 4, 0);
    func_80025798(other->model[5], other->trans.x, other->trans.y - 50.0f, other->trans.z);
    other->trans.x = other->trans.y = other->trans.z = 1000.0f;
    return 1;
}

/* The walker (the player of group 0). */
void func_800F6E80_TightropeTreachery(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z) {
    TTPlayerWork* w;
    void* data;
    u16 id;
    s16 i;

    func_8000979C(obj, dir, file, player, 0x299, 0x299);
    w = obj->unk_50;
    w->angle = 180.0f;
    w->radius = 60.0f;
    D_800B89A4[w->player][0] = 0xF4;
    D_800B89A4[w->player][1] = 0xF4;
    D_800B89A4[w->player][2] = 0xF4;
    D_800B89A4[w->player][3] = 0xF4;
    D_800B89A4[w->player][4] = 0xF4;
    D_800B89A4[w->player][5] = 0xF4;
    D_800B89A4[w->player][6] = 0xF4;
    D_800B89A4[w->player][7] = 0xF4;
    D_800B89A4[w->player][8] = 0x145;
    D_800B89A4[w->player][9] = 0x146;
    D_800B89A4[w->player][10] = 0xF4;
    D_800B89A4[w->player][11] = 0xF4;
    D_800B89A4[w->player][12] = 0xF4;
    D_800B897C = 26.666666f;
    D_800B895C = 1.0f;
    D_800B8964 = 0.65333337f;
    D_800B8968 = 0.06666667f;
    D_800B8960 = 0.25f;
    D_800B8980 = 2.25f;
    D_800B8984 = 1.6875f;
    D_800B8988 = 1.125f;
    D_800B898C = 0.5625f;
    obj->func_ptr = func_800F7818_TightropeTreachery;
    D_800B8970 = 30.0f;
    w->unk_DC = func_800F6C44_TightropeTreachery;
    data = DataRead(0x24);
    id = func_8001E00C(data, 0x1E99, 8);
    HuMemDirectFree(data);
    func_8001E2F8(id, 0x96);
    obj->model[9] = D_800ECDE0[id].unk_00;
    func_80025930(obj->model[9], 0x70000000, 0x70000000);
    func_8001E268(id, 4, 4);
    func_80025830(obj->model[9], 5.5f, 5.5f, 5.5f);
    func_800258EC(obj->model[9], 4, 4);
    func_8001874C(obj, 0, dir | 0x79, 1, 0);
    func_8001874C(obj, 1, dir | 0x4D, 1, 0);
    func_8001874C(obj, 2, dir | 0x4D, 1, 0);
    func_8001874C(obj, 0x23, dir | 0x4E, 1, 0);
    func_800187D0(obj, 6, dir | 5, 1, 0x13);
    func_800187D0(obj, 9, dir | 0xA, 1, 0x27);
    func_800187D0(obj, 0xA, dir | 0x1E, 1, 0x27);
    func_800187D0(obj, 0x10, dir | 0x17, 1, 0);
    func_800187D0(obj, 0x12, dir | 0x1C, 2, 0);
    func_800187D0(obj, 0x13, dir | 0x1D, 2, 0);
    func_800187D0(obj, 0x16, dir | 0x24, 1, 0);
    func_8001874C(obj, 0x15, dir | 0x62, 0, 0);
    func_8001874C(obj, 0x1E, dir | 0x63, 0, 0);
    func_8001874C(obj, 0x1F, dir | 0x64, 0, 0);
    func_8001874C(obj, 0x21, dir | 0x68, 2, 0);
    func_8001874C(obj, 0x22, dir | 0x69, 2, 0);
    guRandom();
    func_8001874C(obj, 0xE, dir | 0x10, 1, 0x78);
    func_8001874C(obj, 0xD, dir | 0xF, 1, 0x78);
    func_800093FC(obj, x, y, z);
    func_80025798(obj->model[0], x, y, z);
    func_800090C4(obj, 0, 2);
    func_800090C4(obj, 1, 2);
    for (i = 2; i < 10; i++) {
        func_800090C4(obj, i, 1);
    }
}

/* A CPU walker: steer back to the rope, slow down near the bombs. */
// register allocation (switch operands copied), one mul-fix nop after sqrtf (masked ~40)
#ifdef NON_MATCHING
void func_800F7450_TightropeTreachery(omObjData* obj) {
    TTPlayerWork* w = obj->unk_50;
    s32 pace;
    s32 side;
    s8 near;
    s16 i;
    f32 rope;

    ContStkX[w->port] = 0;
    ContStkY[w->port] = 0;
    pace = 0;
    rope = D_800FE384_TightropeTreachery;
    if (rope + 40.0f <= obj->trans.x) {
        side = 1;
    } else if (rope + 15.0f <= obj->trans.x) {
        side = 2;
    } else if (rope + -15.0f <= obj->trans.x) {
        side = 0;
    } else if (rope + -40.0f <= obj->trans.x) {
        side = 4;
    } else {
        side = 3;
    }
    near = 0;
    for (i = 0; i < 3; i++) {
        omObjData* bomb = D_800EDE70[i];
        f32 dx = bomb->trans.x;
        f32 dy = bomb->trans.y;
        f32 dz = bomb->trans.z;
        f32 d;

        dx -= obj->trans.x;
        dy -= obj->trans.y;
        dz -= obj->trans.z;
        d = sqrtf(dx * dx + dy * dy);
        if (d * d + dz * dz < 10000.0f) {
            near++;
        }
    }
    switch (near) {
    case 3:
        pace = 4;
        break;
    case 0:
        pace = 1;
        if ((side == 1) | (side == 3)) {
            pace = 2;
        }
        break;
    case 1:
        pace = 2;
        break;
    case 2:
        pace = 2;
        break;
    }
    switch (side) {
    case 1:
        ContStkX[w->port] = -80;
        break;
    case 2:
        ContStkX[w->port] = -40;
        break;
    case 3:
        ContStkX[w->port] = 80;
        break;
    case 4:
        ContStkX[w->port] = 40;
        break;
    default:
        ContStkX[w->port] = 0;
        break;
    }
    switch (pace) {
    case 1:
        ContStkY[w->port] = 80;
        break;
    case 2:
        ContStkY[w->port] = 40;
        break;
    case 3:
        ContStkY[w->port] = -80;
        break;
    case 4:
        ContStkY[w->port] = -40;
        break;
    default:
        ContStkY[w->port] = 0;
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_TightropeTreachery/197E20", func_800F7450_TightropeTreachery);
#endif

/* The walker's update. */
void func_800F7818_TightropeTreachery(omObjData* obj) {
    TTPlayerWork* w;
    s16 i;

    D_800FE2B8_TightropeTreachery = 0.0f;
    w = obj->unk_50;
    if (D_800FE2C0_TightropeTreachery == 1) {
        if (D_800FE2C8_TightropeTreachery++ > 60) {
            D_800FE2B0_TightropeTreachery = 1;
            D_800FE2B5_TightropeTreachery = 1;
            D_800FE2B6_TightropeTreachery = 1;
        }
    }
    if (D_800FE2B2_TightropeTreachery == 1) {
        if (D_800FE2B0_TightropeTreachery != 1 && obj->trans.y >= D_800FE388_TightropeTreachery + -50.0) {
            D_800FE2BE_TightropeTreachery = 0;
            if (obj->trans.x < D_800FE384_TightropeTreachery + -12.0f && w->angle < -45.0 && w->angle > -135.0f) {
                D_800FE2BE_TightropeTreachery = 1;
            }
            if (D_800FE384_TightropeTreachery + 12.0f < obj->trans.x && w->angle > 45.0f && w->angle < 135.0f) {
                D_800FE2BE_TightropeTreachery = 1;
            }
            if (D_800FE2BF_TightropeTreachery != D_800FE2BE_TightropeTreachery) {
                func_800186E4(obj, 0, 0x23);
                func_800185A4(obj, 0);
            }
            D_800FE2BF_TightropeTreachery = D_800FE2BE_TightropeTreachery;
        }
        if (D_800FE2C0_TightropeTreachery != 1 && D_800FE2C1_TightropeTreachery != 1) {
            if (D_800FE2B7_TightropeTreachery == 0) {
                if (obj->trans.z + 120.0f < D_800FE2CC_TightropeTreachery && D_800FE2D8_TightropeTreachery++ < 5) {
                    D_800FE2CC_TightropeTreachery -= 350.0f;
                    D_800FE2B7_TightropeTreachery = 1;
                    D_800FE2D0_TightropeTreachery = 0;
                }
                if (D_800FE2B0_TightropeTreachery != 1) {
                    obj->trans.x += D_800FE714_TightropeTreachery[0] / 12.0f;
                    obj->trans.z += D_800FE714_TightropeTreachery[1] / 12.0f;
                }
            } else if (D_800FE2D0_TightropeTreachery++ >= 15.0f) {
                func_800F9204_TightropeTreachery(D_800F2AF8[0], 350.0f);
                D_800FE2B7_TightropeTreachery = 0;
                D_800FE300_TightropeTreachery = 1;
                D_800FE2D0_TightropeTreachery = 0;
                D_800FE2D4_TightropeTreachery = 5.0f;
            } else {
                D_800FE7C0_TightropeTreachery -= 23.333334f;
                D_800FE2B8_TightropeTreachery = 23.333334f;
            }
        }
        if (D_800FE300_TightropeTreachery == 1) {
            if (D_800FE2D0_TightropeTreachery++ < 15.0f) {
                D_800FE2D4_TightropeTreachery -= 0.22222f;
                for (i = 0; i < 3; i++) {
                    if (D_800FE700_TightropeTreachery[i] != NULL) {
                        f32 d = D_800FE2D4_TightropeTreachery + 20.0f;

                        D_800FE700_TightropeTreachery[i]->trans.z -= d;
                        D_800F2B7C[D_800FE700_TightropeTreachery[i]->model[1]].unk_2C -= d;
                    }
                }
            } else {
                D_800FE300_TightropeTreachery = 0;
            }
        }
        if (GwPlayer[w->player].flags & 1) {
            func_800F7450_TightropeTreachery(obj);
        }
        if (D_800FE2C0_TightropeTreachery == 1) {
            func_800F9168_TightropeTreachery(obj->unk_50);
        }
    } else {
        if (obj->trans.z < 1100.0f) {
            D_800FE2B3_TightropeTreachery = 1;
            ContStkY[w->port] = 0;
            func_800090C4(obj, 0, 2);
        } else {
            D_800FE2B4_TightropeTreachery = 1;
            ContStkY[w->port] = 50;
            func_800090C4(obj, 0, 1);
        }
        ContStkX[w->port] = 0;
    }
    if ((obj->trans.z <= -900.0f && obj->trans.y >= D_800FE388_TightropeTreachery + -20.0 &&
         obj->trans.x < D_800FE384_TightropeTreachery + 60.0f && D_800FE384_TightropeTreachery + -60.0f < obj->trans.x) ||
        D_800FE2C1_TightropeTreachery == 1) {
        if (D_800FE35D_TightropeTreachery == 0) {
            if (D_800FE2C3_TightropeTreachery == 0) {
                func_800601D4(40);
                D_800FE2C3_TightropeTreachery = 1;
            }
            D_800FE2B6_TightropeTreachery = 1;
            D_800FE2B4_TightropeTreachery = 1;
            D_800FE2C1_TightropeTreachery = 1;
            func_800B0CD8(-50.0f, -obj->trans.x + D_800FE384_TightropeTreachery);
            FUNC_80009028_F(D_800F2AF8[1], D_800FE388_TightropeTreachery, -4000.0f, -4000.0f, 4000.0f, 4000.0f);
            func_80009090(D_800F2AF8[1]);
            func_800090C4(obj, 0, 1);
            func_800090C4(obj, 1, 2);
            D_800F2B7C[D_800F3FB0[0]->model[1]].unk_24 = D_800FE384_TightropeTreachery;
            ContStkX[w->port] = 0;
            ContStkY[w->port] = 0;
            if (obj->trans.z < -350.0f) {
                w->angle = 0.0f;
                w->speed = 0.0f;
                D_800FE35D_TightropeTreachery = 1;
            }
        } else {
            ContStkX[w->port] = 0;
            ContStkY[w->port] = 0;
            D_800FE2B0_TightropeTreachery = 1;
            D_800FE2B5_TightropeTreachery = 3;
            if (D_800FE2BC_TightropeTreachery == 1) {
                if (D_800FE2C4_TightropeTreachery == 0) {
                    if (D_800FE2C5_TightropeTreachery++ < 20) {
                        D_800FE8B4_TightropeTreachery += 0.11111111f;
                        D_800FE8B0_TightropeTreachery -= 3.6666667f;
                        D_800FE7C0_TightropeTreachery -= 11.074074f;
                        D_800F2B7C[D_800F2AF8[1]->model[1]].unk_28 += 3.7037036f;
                    } else {
                        D_800FE2C4_TightropeTreachery = 1;
                    }
                } else if (_CheckFlag(0x2B) == 0) {
                    func_800184BC(D_800F3FB0[0], 0xD);
                    func_80017DB0(D_800F3FB0[0]);
                    w->angle = 0.0f;
                    w->speed = 0.0f;
                }
            }
        }
    }
    if (w->unk_AE == 0) {
        if (w->speed >= D_800B8980) {
            w->speed = D_800B8980;
        }
    } else if (D_800FE2C1_TightropeTreachery != 1) {
        ContStkX[w->port] = 0;
    }
    ContBtn[w->port] &= 0x7FFF;
    ContBtnTrg[w->port] &= 0x7FFF;
    D_800F338C[w->port] &= 0x7FFF;
    func_80005A28(obj);
    func_800258EC(obj->model[1], 4, 4);
    if (D_800FE2C1_TightropeTreachery != 1 && obj->trans.y < D_800FE388_TightropeTreachery + -50.0) {
        if (D_800FE2C3_TightropeTreachery == 0) {
            func_800601D4(40);
            D_800FE2C3_TightropeTreachery = 1;
        }
        if (D_800FE2C6_TightropeTreachery == 0) {
            func_80060618(0x45F, D_800FE8A0_TightropeTreachery[0]);
            D_800FE2C0_TightropeTreachery = 1;
            D_800FE2BD_TightropeTreachery = 1;
            D_800FE2B6_TightropeTreachery = 1;
            D_800FE2B4_TightropeTreachery = 1;
            D_800FE2C6_TightropeTreachery = 1;
            D_800B896C = 7.0f;
        }
        if (obj->trans.x > 0.0f) {
            ContStkX[w->port] = 60;
        } else {
            ContStkX[w->port] = -60;
        }
    }
    if (D_800FE2C2_TightropeTreachery == 0 && obj->trans.y <= -600.0f) {
        func_80025798(obj->model[9], obj->trans.x, -600.0f, obj->trans.z + 50.0f);
        func_800258EC(obj->model[9], 4, 0);
        func_800185A4(obj, 0x10);
        D_800FE2B5_TightropeTreachery = 1;
        PlaySound(0x2AF);
        func_80060F04(D_800FE8A0_TightropeTreachery[0], 20, 0, 20);
        D_800FE2C2_TightropeTreachery = 1;
    }
}

/* The game flow: instructions, the timer, the coins and the exit. */
void func_800F83E0_TightropeTreachery(void) {
    TTPlayerWork* w;
    s8 i;

    func_80009468();
    w = D_800F3FB0[0]->unk_50;
    switch (D_800ED430) {
    case 0:
        func_80060128(0x27);
        func_80009458();
        break;
    case 1:
        if (D_800FE2B0_TightropeTreachery == 0) {
            if (D_800FE2B2_TightropeTreachery == 0) {
                if (D_800FE2DC_TightropeTreachery == 43) {
                    GMesCreate(0);
                }
                if (D_800FE2DC_TightropeTreachery >= 44 && D_800FE2B3_TightropeTreachery == 1 &&
                    (GMesStatAllGet() == 0 || (GMesStatAllGet() & 2))) {
                    GMesCreate(8, 60, 160, 24);
                    func_80079078(60);
                    D_800FE2B2_TightropeTreachery = 1;
                    D_800FE2B4_TightropeTreachery = 0;
                }
                D_800FE2DC_TightropeTreachery++;
            } else if (D_800FE2B6_TightropeTreachery == 0) {
                func_80079078(D_800FE2E4_TightropeTreachery / 30);
                if (--D_800FE2E4_TightropeTreachery == 0 && D_800FE2B0_TightropeTreachery != 1) {
                    D_800FE2B4_TightropeTreachery = 1;
                    D_800FE2B5_TightropeTreachery = 2;
                    D_800FE2B0_TightropeTreachery = 1;
                    func_800601D4(40);
                }
            }
        }
        if (D_800FE2B0_TightropeTreachery == 1) {
            func_80009438();
        }
        break;
    case 2:
        if (D_800FE2E1_TightropeTreachery == 0) {
            if (D_800FE2B5_TightropeTreachery == 3) {
                /* the walker made it: 15 coins, 5 from each of the team */
                GwPlayer[D_800FE8A0_TightropeTreachery[0]].coins_mg += 15;
                for (i = 1; i < 4; i++) {
                    if (GwPlayer[D_800FE8A0_TightropeTreachery[i]].coins >= 5) {
                        GwPlayer[D_800FE8A0_TightropeTreachery[i]].coins_mg -= 5;
                    } else {
                        GwPlayer[D_800FE8A0_TightropeTreachery[i]].coins_mg -= GwPlayer[D_800FE8A0_TightropeTreachery[i]].coins;
                    }
                }
            } else {
                for (i = 1; i < 4; i++) {
                    GwPlayer[D_800FE8A0_TightropeTreachery[i]].coins_mg += 5;
                }
                if (GwPlayer[D_800FE8A0_TightropeTreachery[0]].coins >= 15) {
                    GwPlayer[D_800FE8A0_TightropeTreachery[0]].coins_mg -= 15;
                } else {
                    GwPlayer[D_800FE8A0_TightropeTreachery[0]].coins_mg -= GwPlayer[D_800FE8A0_TightropeTreachery[0]].coins;
                }
            }
            func_800790C0();
            D_800FE35D_TightropeTreachery = 1;
            if (D_800FE35C_TightropeTreachery == 1) {
                func_8006071C(D_800FE710_TightropeTreachery);
            }
            switch (D_800FE2B5_TightropeTreachery) {
            case 1:
                if (_CheckFlag(0x2B) == 0) {
                    GMesCreate(0xE);
                    D_800FE2F0_TightropeTreachery = 90;
                } else {
                    GMesCreate(2);
                    D_800FE2F0_TightropeTreachery = 57;
                }
                break;
            case 2:
                if (_CheckFlag(0x2B) == 0) {
                    GMesCreate(0x10);
                    D_800FE2F0_TightropeTreachery = 90;
                } else {
                    GMesCreate(2);
                    D_800FE2F0_TightropeTreachery = 57;
                }
                break;
            case 3:
                GMesCreate(2);
                D_800FE2F0_TightropeTreachery = 57;
                break;
            }
            D_800FE2F4_TightropeTreachery = 0;
            D_800FE2F8_TightropeTreachery = 1;
            D_800FE2E1_TightropeTreachery = 1;
        } else if (GMesStatAllGet() == 0 || (GMesStatAllGet() & 2)) {
            D_800FE2BC_TightropeTreachery = 1;
            if (_CheckFlag(0x2B) == 0) {
                switch (D_800FE2B5_TightropeTreachery) {
                case 1:
                    func_80060128(0x34);
                    break;
                case 2:
                    func_80060128(0x34);
                    func_800185A4(D_800F3FB0[0], 0xE);
                    func_80017DB0(D_800F3FB0[0]);
                    w->angle = 0.0f;
                    w->speed = 0.0f;
                    break;
                case 3:
                    func_80060128(0x33);
                    break;
                }
            }
            func_80009448();
            D_800FE2E8_TightropeTreachery = 0;
        }
        break;
    case 3:
        if (D_800FE2EC_TightropeTreachery == 0) {
            if (_CheckFlag(0x2B) == 0) {
                switch (D_800FE2B5_TightropeTreachery) {
                case 1:
                    if (D_800FE2E8_TightropeTreachery > 90) {
                        D_800FE2EC_TightropeTreachery = 1;
                    }
                    break;
                case 2:
                    if (D_800FE2E8_TightropeTreachery == 18) {
                        func_80060618(0x44A, D_800FE8A0_TightropeTreachery[0]);
                    }
                    if (D_800FE2E8_TightropeTreachery > 90) {
                        D_800FE2EC_TightropeTreachery = 1;
                    }
                    break;
                case 3:
                    if (D_800FE2E8_TightropeTreachery == 56) {
                        func_80060618(0x451, D_800FE8A0_TightropeTreachery[0]);
                    }
                    if (D_800FE2E8_TightropeTreachery > 77) {
                        D_800FE2EC_TightropeTreachery = 1;
                    }
                    break;
                }
            } else {
                D_800FE2EC_TightropeTreachery = 1;
            }
            D_800FE2E8_TightropeTreachery++;
        } else if (D_800FE2E0_TightropeTreachery != 1) {
            if (D_800FE2F4_TightropeTreachery > D_800FE2F0_TightropeTreachery) {
                func_800726AC(0, 20);
                D_800FE2E0_TightropeTreachery = 1;
            }
        } else if (func_80072718() == 0) {
            func_800601D4(40);
            GMesSprClose();
            omOvlReturnEx(1);
        }
        break;
    }
    if (D_800FE2F8_TightropeTreachery == 1) {
        D_800FE2F4_TightropeTreachery++;
    }
}
