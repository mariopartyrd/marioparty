#include "common.h"
#include "TugOWar.h"

/* .data (0x800FDB00..0x800FDBD0), in definition order */
s16 D_800FDB00_TugOWar = -1; /* team's motion */
s16 D_800FDB02_TugOWar = -1; /* solo player's motion */
s16 D_800FDB04_TugOWar = -1;
s16 D_800FDB06_TugOWar = -1;
f32 D_800FDB08_TugOWar = 1.0f; /* solo player's pull factor */
f32 D_800FDB0C_TugOWar = 1.0f; /* team's pull factor */
s32 D_800FDB10_TugOWar = 0;    /* wobble phase (degrees) */
s8 D_800FDB14_TugOWar = 0;     /* pulling paused */
s8 D_800FDB15_TugOWar = 0;
s8 D_800FDB16_TugOWar = -1;
s8 D_800FDB17_TugOWar = 0; /* rope sound playing */
s8 D_800FDB18_TugOWar = 0;
s8 D_800FDB19_TugOWar = 0;
f32 D_800FDB1C_TugOWar = 0.0f; /* solo player's force */
f32 D_800FDB20_TugOWar = 0.0f; /* team's force */
f32 D_800FDB24_TugOWar = 0.0f;
s32 D_800FDB28_TugOWar = 1000;
s8 D_800FDB2C_TugOWar = 0;
s8 D_800FDB2D_TugOWar = 0; /* a side is far ahead: 1 the solo player, 2 the team */
s32 D_800FDB30_TugOWar = 0;
s32 D_800FDB34_TugOWar = 0;
s8 D_800FDB38_TugOWar[3] = { 0, 0, 0 }; /* team member in the water */
s8 D_800FDB3B_TugOWar = 0;
s8 D_800FDB3C_TugOWar = 0;
s8 D_800FDB3D_TugOWar = 0;
s8 D_800FDB3E_TugOWar = 0;
s8 D_800FDB3F_TugOWar = 0;
s8 D_800FDB40_TugOWar = 0;
s8 D_800FDB44_TugOWar[8] = { 0, 2, 3, 4, 5, 6, 0, 0 };
s8 D_800FDB4C_TugOWar[10] = { 6, 12, 14, 15, 16, 17, 18, 19, 20, 21 };
u16 D_800FDB56_TugOWar = 0;
f32 D_800FDB58_TugOWar = 0.0f;
f32 D_800FDB5C_TugOWar = 0.0f;
u16 D_800FDB60_TugOWar = 0;
u16 D_800FDB62_TugOWar = 0;
s8 D_800FDB64_TugOWar = 0;
s8 D_800FDB65_TugOWar = 0;
s8 D_800FDB66_TugOWar = 0;
s8 D_800FDB67_TugOWar = 0;
s8 D_800FDB68_TugOWar = 0;
s32 D_800FDB6C_TugOWar = 0;
f32 D_800FDB70_TugOWar = 0.0f;
s8 D_800FDB74_TugOWar[8] = { 0, 7, 8, 9, 10, 11, 0, 0 };
s8 D_800FDB7C_TugOWar[10] = { 11, 13, 22, 23, 24, 25, 26, 27, 28, 29 };
u16 D_800FDB86_TugOWar = 0;
f32 D_800FDB88_TugOWar = 0.0f;
f32 D_800FDB8C_TugOWar = 0.0f;
u16 D_800FDB90_TugOWar = 0;
s32 D_800FDB94_TugOWar = 2; /* the pull's state: func_800F77EC_TugOWar's result */
f32 D_800FDB98_TugOWar = 0.0f;

/* Sets the team's motion on all three members (when it changes). */
s16 func_800F71F0_TugOWar(s16 motion, s16 attr) {
    s16 changed;
    s8 i;

    changed = D_800FDB00_TugOWar != motion;
    if (changed == 0 && D_800FDB04_TugOWar != attr) {
        changed = 1;
    }
    if (changed == 1) {
        for (i = 1; i < 4; i++) {
            func_80025C20(D_800F3FB0[i]->model[0], func_80025E48(D_800F3FB0[i]->motion[motion]), 0, 50, attr);
        }
        D_800FDB04_TugOWar = attr;
        D_800FDB00_TugOWar = motion;
    }
    return D_800FDB00_TugOWar;
}

/* Sets the solo player's motion (when it changes). */
s16 func_800F731C_TugOWar(s16 motion, s16 attr) {
    s16 changed;

    changed = D_800FDB02_TugOWar != motion;
    if (changed == 0 && D_800FDB06_TugOWar != attr) {
        changed = 1;
    }
    if (changed == 1) {
        func_80025C20(D_800F3FB0[0]->model[0], func_80025E48(D_800F3FB0[0]->motion[motion]), 0, 50, attr);
        D_800FDB06_TugOWar = attr;
        D_800FDB02_TugOWar = motion;
    }
    return D_800FDB02_TugOWar;
}

/* Starts the team's strain effects (model 4 of each member). */
void func_800F73F4_TugOWar(void) {
    unk2C0C0StructB8* e;
    s16 m;
    s8 i;

    if (D_800FDB18_TugOWar == 0) {
        for (i = 1; i < 4; i++) {
            m = D_800F3FB0[i]->model[4];
            e = D_800F2B7C[m].unk_6C->unk_B8;
            if (e != NULL) {
                e->unk_08 = 0.0f;
            }
            func_80025CA8(m, 0.0f);
            func_800258EC(m, 4, 0);
            func_80025798(m, D_800F3FB0[i]->trans.x - 50.0f, D_800F3FB0[i]->trans.y - 20.0f, D_800F3FB0[i]->trans.z);
        }
        D_800FDB18_TugOWar = 1;
    }
}

/* Starts the solo player's strain effect (model 4). */
void func_800F751C_TugOWar(void) {
    unk2C0C0StructB8* e;
    s16 m;

    if (D_800FDB19_TugOWar == 0) {
        m = D_800F3FB0[0]->model[4];
        e = D_800F2B7C[m].unk_6C->unk_B8;
        if (e != NULL) {
            e->unk_08 = 0.0f;
        }
        func_80025CA8(m, 0.0f);
        func_80025830(m, 1.5f, 1.5f, 1.5f);
        func_800258EC(m, 4, 0);
        func_80025798(m, D_800F3FB0[0]->trans.x + 100.0f, D_800F3FB0[0]->trans.y - 20.0f, D_800F3FB0[0]->trans.z);
        D_800FDB19_TugOWar = 1;
    }
}

/* Moves the strain effects with their players; hides them when their animation ends. */
// register allocation (masked 0)
#ifdef NON_MATCHING
void func_800F7604_TugOWar(void) {
    f32 t;
    s16 m;
    s8 i;

    if (D_800FDB19_TugOWar == 1) {
        m = D_800F3FB0[0]->model[4];
        t = func_80025D18(m);
        if (func_80025D40(m) <= t) {
            func_800258EC(m, 4, 4);
            D_800FDB19_TugOWar = 0;
        } else {
            func_80025798(m, D_800F3FB0[0]->trans.x + 100.0f, D_800F3FB0[0]->trans.y - 20.0f,
                          D_800F3FB0[0]->trans.z);
        }
    }
    if (D_800FDB18_TugOWar == 1) {
        m = D_800F3FB0[1]->model[4];
        t = func_80025D18(m);
        if (func_80025D40(m) <= t) {
            for (i = 1; i < 4; i++) {
                func_800258EC(D_800F3FB0[i]->model[4], 4, 4);
            }
            D_800FDB18_TugOWar = 0;
            return;
        }
        for (i = 1; i < 4; i++) {
            func_80025798(D_800F3FB0[i]->model[4], D_800F3FB0[i]->trans.x - 50.0f, D_800F3FB0[i]->trans.y - 20.0f,
                          D_800F3FB0[i]->trans.z);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_32_TugOWar/22D5F0", func_800F7604_TugOWar);
#endif

/* The pull: sums the players' forces and moves the rope (`rope` is func_800F95D4's object; retail
   leaves it in a0). Returns 0 when the solo player has won, 1 when the team has, 2 while it goes on. */
// logic-equivalent rewrite of the pull; block layout and temporaries differ (masked 226)
#ifdef NON_MATCHING
s8 func_800F77EC_TugOWar(omObjData* rope) {
    TWPull* p[4];
    f32 pull[4];
    f32 dist;
    f32 f;
    f32 t;
    f32 speed;
    s32 strain0;
    s32 strain1;
    s16 i;

    strain0 = 0;
    strain1 = 0;
    if (D_800ED430 == 1) {
        if (D_800FDB2C_TugOWar == 0) {
            func_800F731C_TugOWar(0, 1);
            func_800F71F0_TugOWar(0, 1);
            D_800FDB04_TugOWar = 0;
            D_800FDB06_TugOWar = 0;
            D_800FDB2C_TugOWar = 1;
        }
        if (func_8005FD5C() + D_800F64F8 == 0) {
            D_800FDB14_TugOWar = 0;
        } else {
            D_800FDB14_TugOWar = 1;
        }
    } else {
        D_800FDB14_TugOWar = 1;
    }
    if (D_800FDAE0_TugOWar[0] == 1) {
        D_800FDB14_TugOWar = 1;
    }
    for (i = 0; i < 4; i++) {
        p[i] = ((TWPlayerWork*)D_800F3FB0[i]->unk_50)->unk_E4;
        pull[i] = p[i]->pull;
    }
    if (D_800FDB14_TugOWar != 1) {
        dist = p[1]->x - p[0]->x;
        D_800FDB20_TugOWar = 0.0f;
        for (i = 1; i < 4; i++) {
            D_800FDB20_TugOWar += pull[i];
        }
        D_800FDB1C_TugOWar = pull[0] * 3.0f;
        D_800FDB1C_TugOWar = D_800FDB1C_TugOWar * D_800FDB08_TugOWar;
        D_800FDB20_TugOWar = D_800FDB20_TugOWar * D_800FDB0C_TugOWar;
        if (D_800FDFB4_TugOWar == 1) {
            D_800FDB20_TugOWar *= 0.75;
        }
        if (D_800FDFB4_TugOWar == 0) {
            D_800FDB1C_TugOWar *= 0.75;
        }
        if (D_800FDB2D_TugOWar == 0) {
            if (D_800FDB34_TugOWar < 30) {
                D_800FDDF0_TugOWar += D_800FDB1C_TugOWar;
                D_800FDDF4_TugOWar += D_800FDB20_TugOWar;
            } else {
                D_800FDDF4_TugOWar = 0.0f;
                D_800FDDF0_TugOWar = 0.0f;
                D_800FDB34_TugOWar = 0;
            }
            D_800FDB34_TugOWar++;
            if (D_800FDDF4_TugOWar + 720.0f < D_800FDDF0_TugOWar) {
                D_800FDB2D_TugOWar = 1;
                D_800FDB30_TugOWar = 0;
            } else if (D_800FDDF0_TugOWar + 720.0f < D_800FDDF4_TugOWar) {
                D_800FDB2D_TugOWar = 2;
                D_800FDB30_TugOWar = 0;
            }
        } else if (D_800FDB30_TugOWar < 40) {
            if (D_800FDB2D_TugOWar == 1) {
                D_800FDB1C_TugOWar = 200.0f;
                D_800FDB20_TugOWar = 0.0f;
                func_80060F04(D_800FDFAE_TugOWar[1], 20, 0, 20);
                func_80060F04(D_800FDFAE_TugOWar[2], 20, 0, 20);
                func_80060F04(D_800FDFAE_TugOWar[3], 20, 0, 20);
            } else if (D_800FDB2D_TugOWar == 2) {
                D_800FDB1C_TugOWar = 0.0f;
                D_800FDB20_TugOWar = 200.0f;
                func_80060F04(D_800FDFAE_TugOWar[0], 20, 0, 20);
            }
            D_800FDB30_TugOWar++;
        } else {
            D_800FDB2D_TugOWar = 0;
            D_800FDDF4_TugOWar = 0.0f;
            D_800FDDF0_TugOWar = 0.0f;
        }
        if (D_800FDB1C_TugOWar != D_800FDB20_TugOWar) {
            if (!(D_800FDB1C_TugOWar < D_800FDB20_TugOWar)) {
                /* the solo player pulls harder */
                f = D_800FDB1C_TugOWar - D_800FDB20_TugOWar;
                if (f > 500.0f) {
                    f = 500.0f;
                }
                p[0]->x -= f / 100.0f;
                rope->trans.x -= f / 100.0f;
                if (dist >= 600.0f) {
                    if (f / 100.0f > 1.0) {
                        strain0 = 1;
                    }
                    for (i = 0; i < 3; i++) {
                        p[i + 1]->x -= f / 100.0f;
                    }
                    if (D_800FDB28_TugOWar > 20) {
                        func_800F71F0_TugOWar(D_800FDB2D_TugOWar != 0 ? 14 : 35, 2);
                        func_800F731C_TugOWar(0, 2);
                        D_800FDB28_TugOWar = 0;
                    }
                } else if (D_800FDB28_TugOWar > 20) {
                    func_800F731C_TugOWar(0, 2);
                    D_800FDB28_TugOWar = 0;
                }
            } else {
                /* the team pulls harder */
                f = D_800FDB20_TugOWar - D_800FDB1C_TugOWar;
                if (f > 500.0f) {
                    f = 500.0f;
                }
                for (i = 1; i < 4; i++) {
                    p[i]->x += f / 100.0f;
                }
                rope->trans.x += f / 100.0f;
                if (dist >= 600.0f) {
                    if (f / 100.0f > 1.0) {
                        strain1 = 1;
                    }
                    p[0]->x += f / 100.0f;
                    if (D_800FDB28_TugOWar > 20) {
                        func_800F71F0_TugOWar(0, 2);
                        func_800F731C_TugOWar(D_800FDB2D_TugOWar != 0 ? 2 : 35, 2);
                        D_800FDB28_TugOWar = 0;
                    }
                } else if (D_800FDB28_TugOWar > 20) {
                    func_800F71F0_TugOWar(0, 2);
                    D_800FDB28_TugOWar = 0;
                }
            }
        } else {
            if (dist < 600.0f) {
                p[0]->x -= D_800FDB1C_TugOWar / 100.0f;
                for (i = 0; i < 3; i++) {
                    p[i + 1]->x += D_800FDB20_TugOWar / 100.0f;
                }
            }
            if (D_800FDB1C_TugOWar == 0.0f) {
                func_800F731C_TugOWar(0, 0);
                p[0]->timer = 60;
            }
            if (D_800FDB20_TugOWar == 0.0f) {
                func_800F71F0_TugOWar(0, 0);
                for (i = 1; i < 4; i++) {
                    p[i]->timer = 60;
                }
            }
        }
        D_800FDB28_TugOWar++;
    }
    if (D_800FDB20_TugOWar != D_800FDB1C_TugOWar) {
        if (D_800FDB17_TugOWar == 0) {
            D_800FDFAC_TugOWar = PlaySound(0x35C);
            D_800FDB17_TugOWar = 1;
        }
    } else if (D_800FDB17_TugOWar == 1) {
        func_8006071C(D_800FDFAC_TugOWar);
        D_800FDB17_TugOWar = 0;
    }
    /* keep the rope taut: at most 600 apart */
    dist = p[1]->x - p[0]->x;
    if (dist > 600.0f) {
        p[0]->x += (dist - 600.0f) / 2.0f;
        for (i = 1; i < 4; i++) {
            p[i]->x -= (dist - 600.0f) / 2.0f;
        }
    }
    speed = 0.8 - (600.0f - (p[1]->x - p[0]->x)) / 20.0f * 0.8;
    t = func_80025D18(D_800F3FB0[1]->model[0]);
    if (D_800FDB14_TugOWar == 0) {
        if (!(t < 19.0f)) {
            f = 1.0f - (t - 19.0f) / 19.0f;
        } else {
            f = t / 19.0f;
        }
        D_800FDB24_TugOWar = f * 0.2;
    }
    func_800FB718_TugOWar(rope->model[0], rope->model[0], rope->model[1], speed + D_800FDB24_TugOWar);
    func_800F7604_TugOWar();
    if (D_800FDB14_TugOWar != 0) {
        return 2;
    }
    if (p[0]->x >= -210.0f) {
        /* the solo player is dragged to the edge */
        rope->trans.x -= p[0]->x + 210.0f;
        p[0]->x = -210.0f;
        p[0]->dx = 0.0f;
        for (i = 0; i < 3; i++) {
            p[i + 1]->timer = 60;
        }
        if ((s16)p[0]->timer-- <= 0) {
            return 1;
        }
        for (i = 0; i < 3; i++) {
            p[i + 1]->x = p[0]->x + 600.0f + i * 90.0f;
        }
        D_800FDB08_TugOWar -= 0.01;
        if (D_800FDB08_TugOWar < 0.5f) {
            D_800FDB08_TugOWar = 0.5f;
        }
        return 2;
    }
    if (p[1]->x <= 210.0f) {
        /* the team is dragged to the edge */
        rope->trans.x += 210.0f - p[1]->x;
        p[1]->x = 210.0f;
        p[2]->x = 300.0f;
        p[3]->x = 390.0f;
        p[1]->dx = 0.0f;
        p[2]->dx = 0.0f;
        p[3]->dx = 0.0f;
        p[0]->timer = 60;
        if ((s16)p[1]->timer-- <= 0) {
            return 0;
        }
        p[0]->x = p[1]->x - 600.0f;
        D_800FDB0C_TugOWar -= 0.01f;
        if (D_800FDB0C_TugOWar < 0.5f) {
            D_800FDB0C_TugOWar = 0.5f;
        }
        return 2;
    }
    for (i = 0; i < 4; i++) {
        p[i]->timer = 60;
    }
    if (strain0 == 1) {
        func_800F73F4_TugOWar();
    }
    if (strain1 == 1) {
        func_800F751C_TugOWar();
    }
    return 2;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_32_TugOWar/22D5F0", func_800F77EC_TugOWar);
#endif

/* The solo player won: the team is pulled into the water. */
// logic-equivalent; temporaries and branch layout differ (masked 26)
#ifdef NON_MATCHING
void func_800F851C_TugOWar(omObjData* obj) {
    TWPlayerWork* w[4];
    TWPull* p[4];
    f32 t;
    s8 i;

    for (i = 0; i < 4; i++) {
        w[i] = D_800F3FB0[i]->unk_50;
        p[i] = w[i]->unk_E4;
    }
    if (D_800FDB3B_TugOWar == 0) {
        D_800FDB3B_TugOWar = 1;
        D_800FDB60_TugOWar = 0;
        D_800FDB58_TugOWar = 0.0f;
        func_800F71F0_TugOWar(10, 0);
        for (i = 1; i < 4; i++) {
            func_800258EC(D_800F3FB0[i]->model[1], 4, 4);
        }
        func_800F731C_TugOWar(0, 2);
        if (D_800FDB17_TugOWar == 1) {
            func_8006071C(D_800FDFAC_TugOWar);
            D_800FDB17_TugOWar = 0;
        }
        D_800FDB16_TugOWar = 0;
        func_800601D4(40);
        func_80060618(0x45F, D_800FDFAE_TugOWar[1]);
        func_80060618(0x45F, D_800FDFAE_TugOWar[2]);
        func_80060618(0x45F, D_800FDFAE_TugOWar[3]);
    }
    if (func_8005FD5C() + D_800F64F8 != 0) {
        if (D_800FDB3C_TugOWar == 0) {
            func_800FB718_TugOWar(obj->model[0], obj->model[D_800FDB44_TugOWar[D_800FDB60_TugOWar + 1]],
                                  obj->model[D_800FDB44_TugOWar[D_800FDB60_TugOWar]], D_800FDB58_TugOWar);
        }
        if (D_800FDBE4_TugOWar == 0) {
            func_800FB718_TugOWar(obj->model[0], obj->model[6], obj->model[5], 1.0f);
        }
        func_800FB718_TugOWar(obj->model[0], obj->model[D_800FDB4C_TugOWar[D_800FDB56_TugOWar + 1]],
                              obj->model[D_800FDB4C_TugOWar[D_800FDB56_TugOWar]], D_800FDB5C_TugOWar);
    }
    if (D_800FDB3C_TugOWar == 0) {
        obj->trans.x -= 8.0f;
        p[0]->x -= 8.0f;
        func_800FB718_TugOWar(obj->model[0], obj->model[D_800FDB44_TugOWar[D_800FDB60_TugOWar + 1]],
                              obj->model[D_800FDB44_TugOWar[D_800FDB60_TugOWar]], D_800FDB58_TugOWar);
        if ((D_800FDB58_TugOWar += 0.2) >= 1.0) {
            D_800FDB58_TugOWar = 0.0f;
            if (++D_800FDB60_TugOWar >= 5) {
                D_800FDB3C_TugOWar = 1;
            }
        }
    } else if (D_800FDBE4_TugOWar == 0) {
        func_800FB718_TugOWar(obj->model[0], obj->model[6], obj->model[5], 1.0f);
        func_80025C20(D_800F3FB0[0]->model[0], func_80025E48(D_800F3FB0[0]->motion[0]), 0, 30, 1);
    } else {
        func_800FB718_TugOWar(obj->model[0], obj->model[D_800FDB4C_TugOWar[D_800FDB56_TugOWar + 1]],
                              obj->model[D_800FDB4C_TugOWar[D_800FDB56_TugOWar]], D_800FDB5C_TugOWar);
        if ((D_800FDB5C_TugOWar += 0.1) >= 1.0) {
            D_800FDB5C_TugOWar = 1.0f;
            if (D_800FDB56_TugOWar >= 8) {
                D_800FDB56_TugOWar = 8;
            } else {
                D_800FDB56_TugOWar++;
                D_800FDB5C_TugOWar = 0.0f;
            }
        }
        D_800FDAE0_TugOWar[0] = 1;
        D_800FDB16_TugOWar = 0;
        if (D_800FDAE2_TugOWar == 1 && D_800FDBE6_TugOWar == D_800FDAE2_TugOWar) {
            if (p[0]->x < -290.0f) {
                /* the winner walks back to the line */
                if (D_800FDB62_TugOWar == 0) {
                    D_800FDB64_TugOWar = PlaySound(0x35E);
                }
                if (++D_800FDB62_TugOWar >= 18) {
                    D_800FDB62_TugOWar = 0;
                }
                p[0]->x += 5.0f;
                if (D_800FDB3D_TugOWar == 0) {
                    func_800F731C_TugOWar(1, 2);
                    D_800FDB3D_TugOWar = 1;
                }
            } else if (D_800FDB3F_TugOWar == 0) {
                func_80025BB8(D_800F3FB0[0]->model[0], D_800F3FB0[0]->motion[13]);
                func_80025EB4(D_800F3FB0[0]->model[0], 2, 0);
                func_8006071C(D_800FDB64_TugOWar);
                D_800FDB3F_TugOWar = 1;
            } else if (D_800FDB3E_TugOWar == 0) {
                t = func_80025D18(D_800F3FB0[0]->model[0]);
                if (func_80025D40(D_800F3FB0[0]->model[0]) <= t) {
                    D_800FDB3E_TugOWar = 1;
                }
            } else if (D_800FDB40_TugOWar == 0) {
                func_80025BB8(D_800F3FB0[0]->model[0], D_800F3FB0[0]->motion[14]);
                func_80025EB4(D_800F3FB0[0]->model[0], 2, 2);
                D_800FDAE0_TugOWar[0] = 1;
                D_800FDB16_TugOWar = 0;
                D_800FDB40_TugOWar = 1;
            }
        }
    }
    /* the team falls into the water one by one */
    for (i = 0; i < 3; i++) {
        if (D_800FDB38_TugOWar[i] == 0) {
            p[i + 1]->z /= 5.0f;
            p[i + 1]->x -= 25.5f;
            if (p[i + 1]->x < 50.0f) {
                p[i + 1]->x = 50.0f;
            }
            if (p[i + 1]->x <= 100.0f) {
                p[i + 1]->y -= 20.0f;
                if (p[i + 1]->y > 100.0f) {
                    D_800F3FB0[i + 1]->rot.z += 5.0f;
                } else {
                    p[i + 1]->y = 100.0f;
                    D_800FDB38_TugOWar[i] = 1;
                }
            }
        }
    }
    if (D_800FDB38_TugOWar[0] == 1 && D_800FDB38_TugOWar[1] == D_800FDB38_TugOWar[0] &&
        D_800FDB38_TugOWar[2] == D_800FDB38_TugOWar[1]) {
        D_800FDB15_TugOWar = 1;
        D_800FDFB2_TugOWar = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_32_TugOWar/22D5F0", func_800F851C_TugOWar);
#endif

/* The team won: the solo player is pulled into the water. */
// logic-equivalent; temporaries and branch layout differ (masked 37)
#ifdef NON_MATCHING
void func_800F8DA0_TugOWar(omObjData* obj) {
    TWPlayerWork* w[4];
    TWPull* p[4];
    f32 t;
    s8 i;

    for (i = 0; i < 4; i++) {
        w[i] = D_800F3FB0[i]->unk_50;
        p[i] = w[i]->unk_E4;
    }
    if (D_800FDB66_TugOWar == 0) {
        D_800FDB66_TugOWar = 1;
        D_800FDB90_TugOWar = 0;
        D_800FDB88_TugOWar = 0.0f;
        func_800F731C_TugOWar(10, 0);
        func_800258EC(D_800F3FB0[0]->model[1], 4, 4);
        func_800F71F0_TugOWar(0, 2);
        if (D_800FDB17_TugOWar == 1) {
            func_8006071C(D_800FDFAC_TugOWar);
            D_800FDB17_TugOWar = 0;
        }
        D_800FDB16_TugOWar = 1;
        func_800601D4(40);
        func_80060618(0x45F, D_800FDFAE_TugOWar[0]);
    }
    if (func_8005FD5C() + D_800F64F8 != 0) {
        if (D_800FDB67_TugOWar == 0) {
            func_800FB718_TugOWar(obj->model[0], obj->model[D_800FDB74_TugOWar[D_800FDB90_TugOWar + 1]],
                                  obj->model[D_800FDB74_TugOWar[D_800FDB90_TugOWar]], D_800FDB88_TugOWar);
        }
        if (D_800FDBE4_TugOWar == 0) {
            func_800FB718_TugOWar(obj->model[0], obj->model[D_800FDB74_TugOWar[5]],
                                  obj->model[D_800FDB74_TugOWar[4]], 1.0f);
        }
        func_800FB718_TugOWar(obj->model[0], obj->model[D_800FDB7C_TugOWar[D_800FDB86_TugOWar + 1]],
                              obj->model[D_800FDB7C_TugOWar[D_800FDB86_TugOWar]], D_800FDB8C_TugOWar);
    }
    if (D_800FDB67_TugOWar == 0) {
        obj->trans.x += 8.0f;
        for (i = 0; i < 3; i++) {
            p[i + 1]->x += 8.0f;
        }
        func_800FB718_TugOWar(obj->model[0], obj->model[D_800FDB74_TugOWar[D_800FDB90_TugOWar + 1]],
                              obj->model[D_800FDB74_TugOWar[D_800FDB90_TugOWar]], D_800FDB88_TugOWar);
        if ((D_800FDB88_TugOWar += 0.2) >= 1.0) {
            D_800FDB88_TugOWar = 0.0f;
            if (++D_800FDB90_TugOWar >= 5) {
                D_800FDB67_TugOWar = 1;
            }
        }
    } else if (D_800FDBE4_TugOWar == 0) {
        func_800FB718_TugOWar(obj->model[0], obj->model[D_800FDB74_TugOWar[5]], obj->model[D_800FDB74_TugOWar[4]],
                              1.0f);
        for (i = 1; i < 4; i++) {
            func_80025C20(D_800F3FB0[i]->model[0], func_80025E48(D_800F3FB0[i]->motion[0]), 0, 30, 1);
        }
    } else {
        func_800FB718_TugOWar(obj->model[0], obj->model[D_800FDB7C_TugOWar[D_800FDB86_TugOWar + 1]],
                              obj->model[D_800FDB7C_TugOWar[D_800FDB86_TugOWar]], D_800FDB8C_TugOWar);
        if ((D_800FDB8C_TugOWar += 0.1) >= 1.0) {
            D_800FDB8C_TugOWar = 1.0f;
            if (D_800FDB86_TugOWar >= 8) {
                D_800FDB86_TugOWar = 8;
            } else {
                D_800FDB86_TugOWar++;
                D_800FDB8C_TugOWar = 0.0f;
            }
        }
        if (D_800FDB6C_TugOWar++ >= 6) {
            D_800FDAE0_TugOWar[0] = 1;
            D_800FDB16_TugOWar = 1;
            if (D_800FDAE2_TugOWar == 1 && D_800FDBE6_TugOWar == D_800FDAE2_TugOWar) {
                if (D_800FDB70_TugOWar < 90.0f) {
                    /* the team turns to face the camera */
                    if ((D_800FDB70_TugOWar += 10.0f) > 90.0f) {
                        D_800FDB70_TugOWar = 90.0f;
                    }
                    for (i = 1; i < 4; i++) {
                        func_8000940C(D_800F3FB0[i], 0.0f, D_800FDB70_TugOWar + -90.0f, 0.0f);
                    }
                } else if (D_800FDB68_TugOWar == 0) {
                    for (i = 1; i < 4; i++) {
                        func_80025BB8(D_800F3FB0[i]->model[0], D_800F3FB0[i]->motion[13]);
                        func_80025EB4(D_800F3FB0[i]->model[0], 2, 0);
                    }
                    D_800FDB68_TugOWar = 1;
                } else {
                    t = func_80025D18(D_800F3FB0[1]->model[0]);
                    if (func_80025D40(D_800F3FB0[1]->model[0]) <= t) {
                        D_800FDAE0_TugOWar[0] = 1;
                        D_800FDB16_TugOWar = 1;
                    }
                }
            }
        }
    }
    /* the solo player falls into the water */
    if (D_800FDB65_TugOWar == 0) {
        p[0]->z /= 5.0f;
        p[0]->x += 25.5f;
        if (p[0]->x >= -80.0f) {
            p[0]->x = -80.0f;
        }
        if (p[0]->x >= -100.0f) {
            p[0]->y -= 20.0f;
            if (!(p[0]->y > 100.0f)) {
                p[0]->y = 100.0f;
                D_800FDB65_TugOWar = 1;
            } else {
                D_800F3FB0[0]->rot.z -= 5.0f;
            }
        }
    }
    if (D_800FDB65_TugOWar == 1) {
        D_800FDB15_TugOWar = 1;
        D_800FDFB2_TugOWar = 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_32_TugOWar/22D5F0", func_800F8DA0_TugOWar);
#endif

void func_800F95D4_TugOWar(omObjData* arg0) {
    if (D_800FDB94_TugOWar == 2) {
        D_800FDB94_TugOWar = func_800F77EC_TugOWar(arg0);
    }
    switch (D_800FDB94_TugOWar) {
    case 0:
        D_800FDAE0_TugOWar[1] = 1;
        func_800F851C_TugOWar(arg0);
        break;
    case 1:
        D_800FDAE0_TugOWar[1] = 1;
        func_800F8DA0_TugOWar(arg0);
        break;
    }
    if (D_800ED430 == 1) {
        Center.x = arg0->trans.x;
    }
}

/* The rope object: 30 rope models (the pull and fall animation frames). */
void func_800F9688_TugOWar(omObjData* obj) {
    unkGlobalStruct_00* w;
    s16 i;

    obj->unk_50 = w = func_80023684(0x6C, 0x7918);
    func_8009B770(w, 0, 0x6C);
    w->unk_52 = 1;
    obj->model[0] = func_800174F4(0x460001, 0x688);
    obj->model[1] = func_800174F4(0x460002, 0x688);
    obj->model[2] = func_800174F4(0x460003, 0x688);
    obj->model[3] = func_800174F4(0x460004, 0x688);
    obj->model[4] = func_800174F4(0x460005, 0x688);
    obj->model[5] = func_800174F4(0x460006, 0x688);
    obj->model[6] = func_800174F4(0x460007, 0x688);
    obj->model[7] = func_800174F4(0x460008, 0x688);
    obj->model[8] = func_800174F4(0x460009, 0x688);
    obj->model[9] = func_800174F4(0x46000A, 0x688);
    obj->model[10] = func_800174F4(0x46000B, 0x688);
    obj->model[11] = func_800174F4(0x46000C, 0x688);
    obj->model[12] = func_800174F4(0x460010, 0x688);
    obj->model[13] = func_800174F4(0x46000F, 0x688);
    obj->model[14] = func_800174F4(0x460011, 0x688);
    obj->model[15] = func_800174F4(0x460012, 0x688);
    obj->model[16] = func_800174F4(0x460013, 0x688);
    obj->model[17] = func_800174F4(0x460014, 0x688);
    obj->model[18] = func_800174F4(0x460015, 0x688);
    obj->model[19] = func_800174F4(0x460016, 0x688);
    obj->model[20] = func_800174F4(0x460017, 0x688);
    obj->model[21] = func_800174F4(0x460018, 0x688);
    obj->model[22] = func_800174F4(0x460019, 0x688);
    obj->model[23] = func_800174F4(0x46001A, 0x688);
    obj->model[24] = func_800174F4(0x46001B, 0x688);
    obj->model[25] = func_800174F4(0x46001C, 0x688);
    obj->model[26] = func_800174F4(0x46001D, 0x688);
    obj->model[27] = func_800174F4(0x46001E, 0x688);
    obj->model[28] = func_800174F4(0x46001F, 0x688);
    obj->model[29] = func_800174F4(0x460020, 0x688);
    for (i = 0; i < 30; i++) {
        func_80025930(obj->model[i], 0x20000, 0x20000);
        func_80025AD4(obj->model[i]);
        func_80025B34(obj->model[i]);
    }
    func_80026040(obj->model[0]);
    for (i = 1; i < 30; i++) {
        func_800258EC(obj->model[i], 4, 4);
    }
    obj->trans.z = -80.0f;
    obj->trans.x = 0.0f;
    obj->trans.y = -5.0f;
    obj->func_ptr = func_800F95D4_TugOWar;
}

/* The solo player's pull: the stick angle's change (or the CPU's), as a pull strength. */
// logic-equivalent; the angle-wrap test is written once (retail: two branches) (masked 22)
#ifdef NON_MATCHING
void func_800F9A90_TugOWar(omObjData* obj) {
    TWPlayerWork* w;
    TWPull* p;
    f32 t;
    f32 d;

    w = obj->unk_50;
    p = w->unk_E4;
    if (D_800ED430 == 1) {
        if (!(GwPlayer[w->unk_58].flags & 1)) {
            D_800FDDF8_TugOWar = func_800FB7AC_TugOWar(w->unk_56);
        } else {
            D_800FDB98_TugOWar += guRandom() % 14 + 48;
            D_800FDDF8_TugOWar = D_800FDB98_TugOWar * 1.23;
            switch (GwPlayer[w->unk_58].cpu_difficulty) {
            case 0:
                D_800FDDF8_TugOWar = D_800FDDF8_TugOWar * 0.85;
                break;
            case 1:
                D_800FDDF8_TugOWar = D_800FDDF8_TugOWar * 0.9;
                break;
            case 2:
                D_800FDDF8_TugOWar = D_800FDDF8_TugOWar * 0.95;
                break;
            }
        }
        if (D_800FDDF8_TugOWar >= 0.0f) {
            D_800FDDFC_TugOWar = D_800FDDF8_TugOWar - p->angle;
            d = D_800FDDFC_TugOWar;
            if (d < 0.0f) {
                d = -d;
            }
            if (d >= 180.0f) {
                if (D_800FDDFC_TugOWar <= 0.0f) {
                    D_800FDDFC_TugOWar += 360.0f;
                } else {
                    D_800FDDFC_TugOWar -= 360.0f;
                }
            }
        } else {
            D_800FDDFC_TugOWar = 0.0f;
        }
        d = D_800FDDFC_TugOWar;
        if (d < 0.0f) {
            d = -d;
        }
        p->pull = d;
        t = func_800AEFD0(D_800FDB10_TugOWar);
        d = D_800FDDFC_TugOWar;
        if (d < 0.0f) {
            d = -d;
        }
        p->pull = t / 5.0f * (f64)d + d;
        p->angle = D_800FDDF8_TugOWar;
    }
    obj->trans.x = p->x + p->dx;
    obj->trans.y = p->y + p->dy;
    obj->trans.z = p->z + p->dz;
    func_80025830(obj->model[1], 1.6f, 1.6f, 3.0f);
    func_80025798(obj->model[1], obj->trans.x + 20.0f, obj->trans.y, obj->trans.z + 30.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_32_TugOWar/22D5F0", func_800F9A90_TugOWar);
#endif

/* Head-swap part of each character (func_80020EA0), by GwPlayer.character. */
char* D_800FDB9C_TugOWar[6] = {
    "atama_2", "Luigi1-atama_2", "C002_000b-bmerge10_1", "c003_000-head_1", "Luigi1-atama_1", "c005_000-bmerge1",
};
f32 D_800FDBB4_TugOWar[4] = { 0.0f, 0.0f, 0.0f, 0.0f }; /* the CPUs' stick angles */

/* The solo player's object: character model, rope hands and the pull work. */
void func_800F9E34_TugOWar(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z) {
    TWPlayerWork* w;
    TWPull* p;

    obj->unk_50 = func_80023684(sizeof(TWPlayerWork), 0x7918); /* 0xE8 on the N64 */
    func_8009B770(obj->unk_50, 0, sizeof(TWPlayerWork));
    w = obj->unk_50;
    w->unk_D8 = func_80023684(obj->mtncnt * 4, 0x7918);
    w->unk_56 = GwPlayer[player].port;
    w->unk_E4 = func_80023684(sizeof(TWPull), 0x7918);
    func_8009B770(w->unk_E4, 0, sizeof(TWPull));
    p = w->unk_E4;
    obj->model[0] = LoadFormFile(0x46002B, 0x689);
    obj->model[1] = func_800174F4(6, 0x699);
    obj->model[10] = LoadFormFile(dir | file, 0x689);
    obj->model[3] = LoadFormFile(0x19, 0x699);
    func_800258EC(obj->model[3], 4, 4);
    obj->model[4] = LoadFormFile(0x1A, 0x689);
    func_800258EC(obj->model[4], 4, 4);
    func_80028C64(obj->model[4], 0x3F, 0x1F, 0, 0x3F);
    func_80020EA0(obj->model[10], D_800FDB9C_TugOWar[GwPlayer[player].character], obj->model[0],
                  "21_kimoti_1b-atama_3");
    func_800258EC(obj->model[10], 4, 4);
    func_80025B34(obj->model[0]);
    func_80025B34(obj->model[10]);
    func_80025B34(obj->model[4]);
    func_8001775C(obj, 0, 0x460025);
    func_8001775C(obj, 0x23, 0x460026);
    func_8001775C(obj, 1, 0x220005);
    func_8001775C(obj, 2, 0x46002A);
    func_8001775C(obj, 0xA, 0x460027);
    func_8001775C(obj, 0xD, 0x460028);
    func_8001775C(obj, 0xE, 0x460029);
    func_800093FC(obj, x, y, z);
    func_80025798(obj->model[0], x, y, z);
    func_8000940C(obj, 0.0f, 90.0f, 0.0f);
    w->unk_58 = player;
    w->unk_52 = 0;
    w->unk_A4 = 1.0f;
    w->unk_C0 = 0xFFFF;
    w->unk_38 = 1000.0f;
    w->unk_50 = 0;
    p->unk0 = 0;
    p->angle = 0.0f;
    p->pull = 0.0f;
    p->x = obj->trans.x;
    p->y = obj->trans.y;
    p->z = obj->trans.z;
    p->dx = 0.0f;
    p->dy = 0.0f;
    p->dz = 0.0f;
    p->timer = 60;
    func_80008FD0(obj, 60.0f);
    func_80008FDC(obj, 150.0f);
    func_80008FE8(obj, 20.0f);
    func_800090C4(obj, 0, 1);
    func_80025BB8(obj->model[0], obj->motion[0]);
    func_80025EB4(obj->model[0], 1, 1);
    obj->func_ptr = func_800F9A90_TugOWar;
}

// instruction order of the character lookup (masked 12)
#ifdef NON_MATCHING
void func_800FA1F4_TugOWar(omObjData* obj) {
    func_800F9E34_TugOWar(obj, D_800C59AC[GwPlayer[D_800FDFAE_TugOWar[0]].character].unk_00, D_800C59AC[GwPlayer[D_800FDFAE_TugOWar[0]].character].unk_04, D_800FDFAE_TugOWar[0], -340.0f,
                          400.0f, -80.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_32_TugOWar/22D5F0", func_800FA1F4_TugOWar);
#endif

/* A team member's pull (player w->unk_58): as func_800F9A90_TugOWar, per player. */
// logic-equivalent; the angle-wrap test is written once (retail: two branches) (masked 28)
#ifdef NON_MATCHING
void func_800FA284_TugOWar(omObjData* obj) {
    TWPlayerWork* w;
    TWPull* p;
    f32 t;
    f32 d;

    w = obj->unk_50;
    p = w->unk_E4;
    if (D_800ED430 == 1) {
        if (!(GwPlayer[w->unk_58].flags & 1)) {
            D_800FDE00_TugOWar[w->unk_58] = func_800FB7AC_TugOWar(w->unk_56);
        } else {
            D_800FDBB4_TugOWar[w->unk_58] += guRandom() % 14 + 48;
            D_800FDE00_TugOWar[w->unk_58] = D_800FDBB4_TugOWar[w->unk_58] * 1.23;
            switch (GwPlayer[w->unk_58].cpu_difficulty) {
            case 0:
                D_800FDE00_TugOWar[w->unk_58] = D_800FDE00_TugOWar[w->unk_58] * 0.85;
                break;
            case 1:
                D_800FDE00_TugOWar[w->unk_58] = D_800FDE00_TugOWar[w->unk_58] * 0.9;
                break;
            case 2:
                D_800FDE00_TugOWar[w->unk_58] = D_800FDE00_TugOWar[w->unk_58] * 0.95;
                break;
            case 3:
                D_800FDE00_TugOWar[w->unk_58] = D_800FDE00_TugOWar[w->unk_58];
                break;
            }
        }
        if (D_800FDE00_TugOWar[w->unk_58] >= 0.0f) {
            D_800FDE10_TugOWar[w->unk_58] = D_800FDE00_TugOWar[w->unk_58] - p->angle;
            d = D_800FDE10_TugOWar[w->unk_58];
            if (d < 0.0f) {
                d = -d;
            }
            if (d >= 180.0f) {
                if (D_800FDE10_TugOWar[w->unk_58] <= 0.0f) {
                    D_800FDE10_TugOWar[w->unk_58] += 360.0f;
                } else {
                    D_800FDE10_TugOWar[w->unk_58] -= 360.0f;
                }
            }
        } else {
            D_800FDE10_TugOWar[w->unk_58] = 0.0f;
        }
        t = func_800AEAC0(D_800FDB10_TugOWar);
        d = D_800FDE10_TugOWar[w->unk_58];
        if (d < 0.0f) {
            d = -d;
        }
        p->pull = t / 5.0f * (f64)d + d;
        p->angle = D_800FDE00_TugOWar[w->unk_58];
    }
    obj->trans.x = p->x + p->dx;
    obj->trans.y = p->y + p->dy;
    obj->trans.z = p->z + p->dz;
    func_80025830(obj->model[1], 1.1f, 1.1f, 2.5f);
    func_80025798(obj->model[1], obj->trans.x - 20.0f, obj->trans.y, obj->trans.z + 30.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_32_TugOWar/22D5F0", func_800FA284_TugOWar);
#endif

/* A team member's object. */
void func_800FA700_TugOWar(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z) {
    TWPlayerWork* w;
    TWPull* p;

    obj->unk_50 = func_80023684(sizeof(TWPlayerWork), 0x7918); /* 0xE8 on the N64 */
    func_8009B770(obj->unk_50, 0, sizeof(TWPlayerWork));
    w = obj->unk_50;
    w->unk_D8 = func_80023684(obj->mtncnt * 4, 0x7918);
    w->unk_56 = GwPlayer[player].port;
    w->unk_E4 = func_80023684(sizeof(TWPull), 0x7918);
    func_8009B770(w->unk_E4, 0, sizeof(TWPull));
    p = w->unk_E4;
    obj->model[0] = LoadFormFile(dir | file, 0x699);
    obj->model[1] = func_800174F4(6, 0x699);
    obj->model[3] = LoadFormFile(0x19, 0x699);
    func_800258EC(obj->model[3], 4, 4);
    obj->model[4] = LoadFormFile(0x1A, 0x689);
    func_800258EC(obj->model[4], 4, 4);
    func_80028C64(obj->model[4], 0x3F, 0x1F, 0, 0x3F);
    func_80025B34(obj->model[4]);
    func_8001775C(obj, 0, dir | 0x7E);
    func_8001775C(obj, 1, dir | 1);
    func_8001775C(obj, 2, dir | 3);
    func_8001775C(obj, 0x23, dir | 0x7F);
    func_8001775C(obj, 0xA, dir | 0x1E);
    func_8001775C(obj, 0xE, dir | 0x98);
    func_8001775C(obj, 0xD, dir | 0x39);
    func_800093FC(obj, x, y, z);
    func_80025798(obj->model[0], x, y, z);
    func_8000940C(obj, 0.0f, -90.0f, 0.0f);
    func_80025798(obj->model[1], x, y, z);
    func_80025798(obj->model[3], x, y, z);
    func_80025798(obj->model[4], x, y, z);
    w->unk_58 = player;
    w->unk_52 = 0;
    w->unk_A4 = 1.0f;
    w->unk_C0 = 0xFFFF;
    w->unk_38 = 1000.0f;
    w->unk_50 = 0;
    p->unk0 = 0;
    p->angle = 0.0f;
    p->pull = 0.0f;
    p->x = obj->trans.x;
    p->y = obj->trans.y;
    p->z = obj->trans.z;
    p->dx = 0.0f;
    p->dy = 0.0f;
    p->dz = 0.0f;
    p->timer = 60;
    func_80008FD0(obj, 60.0f);
    func_80008FDC(obj, 150.0f);
    func_80008FE8(obj, 20.0f);
    func_800090C4(obj, 0, 1);
    func_80025BB8(obj->model[0], obj->motion[0]);
    func_80025EB4(obj->model[0], 1, 1);
    obj->func_ptr = func_800FA284_TugOWar;
}

// instruction order of the character lookup (masked 12)
#ifdef NON_MATCHING
void func_800FAA78_TugOWar(omObjData* obj) {
    func_800FA700_TugOWar(obj, D_800C59AC[GwPlayer[D_800FDFAE_TugOWar[1]].character].unk_00, D_800C59AC[GwPlayer[D_800FDFAE_TugOWar[1]].character].unk_04, D_800FDFAE_TugOWar[1], 340.0f,
                          400.0f, -80.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_32_TugOWar/22D5F0", func_800FAA78_TugOWar);
#endif

// instruction order of the character lookup (masked 12)
#ifdef NON_MATCHING
void func_800FAB08_TugOWar(omObjData* obj) {
    func_800FA700_TugOWar(obj, D_800C59AC[GwPlayer[D_800FDFAE_TugOWar[2]].character].unk_00, D_800C59AC[GwPlayer[D_800FDFAE_TugOWar[2]].character].unk_04, D_800FDFAE_TugOWar[2], 430.0f,
                          400.0f, -80.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_32_TugOWar/22D5F0", func_800FAB08_TugOWar);
#endif

// instruction order of the character lookup (masked 12)
#ifdef NON_MATCHING
void func_800FAB98_TugOWar(omObjData* obj) {
    func_800FA700_TugOWar(obj, D_800C59AC[GwPlayer[D_800FDFAE_TugOWar[3]].character].unk_00, D_800C59AC[GwPlayer[D_800FDFAE_TugOWar[3]].character].unk_04, D_800FDFAE_TugOWar[3], 520.0f,
                          400.0f, -80.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_32_TugOWar/22D5F0", func_800FAB98_TugOWar);
#endif

void func_800FAC28_TugOWar(void) {
    omSetStatBit(omAddObj(25, 40, 10, -1, func_800F9688_TugOWar), 0xA0);
    D_800F3FB0[D_800F2BC0++] = omAddObj(20, 10, 80, -1, func_800FA1F4_TugOWar);
    D_800F3FB0[D_800F2BC0++] = omAddObj(20, 10, 80, -1, func_800FAA78_TugOWar);
    D_800F3FB0[D_800F2BC0++] = omAddObj(20, 10, 80, -1, func_800FAB08_TugOWar);
    D_800F3FB0[D_800F2BC0++] = omAddObj(20, 10, 80, -1, func_800FAB98_TugOWar);
}
