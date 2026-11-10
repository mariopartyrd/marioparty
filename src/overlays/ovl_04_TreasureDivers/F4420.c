#include "common.h"
#include "TreasureDivers.h"

void func_800FC060_TreasureDivers(s32 i) {
    D_800FF188_TreasureDivers[i].active = 0;
}

// NON_MATCHING: register allocation / scheduling
#ifdef NON_MATCHING
void func_800FC074_TreasureDivers(s32 i) {
    TDBoat* b = D_800FF188_TreasureDivers;

    b[i].active = 1;
    if (i == 0) {
        b[0].pos.x = -300.0f;
        b[0].pos.y = 600.0f;
        b[0].pos.z = -200.0f;
        b[0].vx = 10.0f;
    } else if (i == 1) {
        b[1].pos.x = 300.0f;
        b[1].pos.y = 800.0f;
        b[1].pos.z = -200.0f;
        b[1].vx = -10.0f;
    }
    D_800FF188_TreasureDivers[i].rot.x = 0;
    D_800FF188_TreasureDivers[i].rot.y = 0;
    D_800FF188_TreasureDivers[i].rot.z = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_04_TreasureDivers/F4420", func_800FC074_TreasureDivers);
#endif

void func_800FC144_TreasureDivers(omObjData* obj) {
    func_800FC074_TreasureDivers(0);
    func_800FC074_TreasureDivers(1);
    func_80026040(obj->model[0]);
    func_800258EC(obj->model[1], 4, 4);
    obj->model[2] = func_80023FC8(obj->model[0]);
    D_800FF188_TreasureDivers[0].unk0 = 0;
    D_800FF188_TreasureDivers[0].unk2 = 6;
    D_800FF188_TreasureDivers[0].unk4 = 6;
    D_800FF188_TreasureDivers[1].unk0 = 0;
    D_800FF188_TreasureDivers[1].unk2 = 6;
    D_800FF188_TreasureDivers[1].unk4 = 6;
}

/* The two boats on the surface. */
// NON_MATCHING: register allocation / scheduling
#ifdef NON_MATCHING
void func_800FC1CC_TreasureDivers(omObjData* obj) {
    Vec v;
    Vec s;

    D_800FF188_TreasureDivers[0].oldScr.x = D_800FF188_TreasureDivers[0].scr.x;
    D_800FF188_TreasureDivers[0].oldScr.y = D_800FF188_TreasureDivers[0].scr.y;
    D_800FF188_TreasureDivers[1].oldScr.x = D_800FF188_TreasureDivers[1].scr.x;
    D_800FF188_TreasureDivers[1].oldScr.y = D_800FF188_TreasureDivers[1].scr.y;
    func_80026174(obj->model[0], obj->model[1], func_800AEAC0(D_800FE430_TreasureDivers));
    if (func_8005FD5C() + D_800F64F8 == 0) {
        D_800FE430_TreasureDivers += 6;
        if (D_800FE430_TreasureDivers >= 361) {
            D_800FE430_TreasureDivers = 0;
        }
        if (D_800FF188_TreasureDivers[0].active == 1) {
            if (D_800FF188_TreasureDivers[0].pos.x > 1100.0f) {
                D_800FF188_TreasureDivers[0].vx -= 1.0f;
            } else if (D_800FF188_TreasureDivers[0].pos.x < -200.0f) {
                D_800FF188_TreasureDivers[0].vx += 1.0f;
            }
        } else if (D_800FF188_TreasureDivers[0].pos.x > 2200.0f || D_800FF188_TreasureDivers[0].pos.x < -400.0f) {
            D_800FF188_TreasureDivers[0].vx = 0.0f;
        }
        if (D_800FF188_TreasureDivers[1].active == 1) {
            if (D_800FF188_TreasureDivers[1].pos.x > 200.0f) {
                D_800FF188_TreasureDivers[1].vx -= 1.0f;
            } else if (D_800FF188_TreasureDivers[1].pos.x < -1100.0f) {
                D_800FF188_TreasureDivers[1].vx += 1.0f;
            }
        } else if (D_800FF188_TreasureDivers[1].pos.x > 2200.0f || D_800FF188_TreasureDivers[1].pos.x < -400.0f) {
            D_800FF188_TreasureDivers[1].vx = 0.0f;
        }
        if (D_800FF188_TreasureDivers[0].vx > 10.0f) {
            D_800FF188_TreasureDivers[0].vx = 10.0f;
        } else if (D_800FF188_TreasureDivers[0].vx < -10.0f) {
            D_800FF188_TreasureDivers[0].vx = -10.0f;
        }
        if (D_800FF188_TreasureDivers[1].vx > 10.0f) {
            D_800FF188_TreasureDivers[1].vx = 10.0f;
        } else if (D_800FF188_TreasureDivers[1].vx < -10.0f) {
            D_800FF188_TreasureDivers[1].vx = -10.0f;
        }
        D_800FF188_TreasureDivers[0].pos.x += D_800FF188_TreasureDivers[0].vx;
        D_800FF188_TreasureDivers[1].pos.x += D_800FF188_TreasureDivers[1].vx;
        D_800FF188_TreasureDivers[0].pos.y += (s32)(func_800AEAC0(D_800FE430_TreasureDivers) * 6.0f);
        D_800FF188_TreasureDivers[1].pos.y += (s32)(func_800AEAC0(D_800FE430_TreasureDivers) * 6.0f);
        obj->trans.x = D_800FF188_TreasureDivers[0].pos.x;
        obj->trans.y = D_800FF188_TreasureDivers[0].pos.y;
        obj->trans.z = D_800FF188_TreasureDivers[0].pos.z;
        func_80025798(obj->model[2], D_800FF188_TreasureDivers[1].pos.x, D_800FF188_TreasureDivers[1].pos.y,
                      D_800FF188_TreasureDivers[1].pos.z);
        obj->scale.x = 1.6f;
        obj->scale.y = 1.6f;
        obj->scale.z = 1.6f;
        func_80025830(obj->model[2], 1.6f, 1.6f, 1.6f);
        v.x = D_800FF188_TreasureDivers[0].pos.x;
        v.y = D_800FF188_TreasureDivers[0].pos.y;
        v.z = D_800FF188_TreasureDivers[0].pos.z;
        func_800FA7E8_TreasureDivers(&v, &s);
        D_800FF188_TreasureDivers[0].scr.x = s.x;
        D_800FF188_TreasureDivers[0].scr.y = s.y;
        v.x = D_800FF188_TreasureDivers[1].pos.x;
        v.y = D_800FF188_TreasureDivers[1].pos.y;
        v.z = D_800FF188_TreasureDivers[1].pos.z;
        func_800FA7E8_TreasureDivers(&v, &s);
        D_800FF188_TreasureDivers[1].scr.x = s.x;
        D_800FF188_TreasureDivers[1].scr.y = s.y;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_04_TreasureDivers/F4420", func_800FC1CC_TreasureDivers);
#endif

void func_800FC6AC_TreasureDivers(void) {
    D_800FF188_TreasureDivers[2].active = 0;
}

void func_800FC6B8_TreasureDivers(void) {
    D_800FF188_TreasureDivers[2].active = 1;
    D_800FF188_TreasureDivers[2].pos.x = 0;
    D_800FF188_TreasureDivers[2].pos.y = 1000.0f;
    D_800FF188_TreasureDivers[2].pos.z = -500.0f;
    D_800FF188_TreasureDivers[2].rot.x = 0;
    D_800FF188_TreasureDivers[2].rot.y = 0;
    D_800FF188_TreasureDivers[2].rot.z = 0;
    D_800FF188_TreasureDivers[2].vx = 30.0f;
}

void func_800FC70C_TreasureDivers(omObjData* obj) {
    func_800FC6B8_TreasureDivers();
    func_80026040(obj->model[0]);
    func_800258EC(obj->model[1], 4, 4);
    D_800FF188_TreasureDivers[2].unk0 = 1;
    D_800FF188_TreasureDivers[2].unk2 = 30;
    D_800FF188_TreasureDivers[2].unk4 = 4;
}

/* The treasure boat (Koopa's). */
// NON_MATCHING: register allocation / scheduling
#ifdef NON_MATCHING
void func_800FC770_TreasureDivers(omObjData* obj) {
    Vec v;
    Vec s;
    s32 target;

    D_800FF188_TreasureDivers[2].oldScr.x = D_800FF188_TreasureDivers[2].scr.x;
    D_800FF188_TreasureDivers[2].oldScr.y = D_800FF188_TreasureDivers[2].scr.y;
    func_80026174(obj->model[0], obj->model[1], func_800AEAC0(D_800FE434_TreasureDivers));
    if (func_8005FD5C() + D_800F64F8 == 0) {
        if (D_800FF188_TreasureDivers[2].active == 1) {
            target = 90;
            if (D_800FF188_TreasureDivers[2].pos.x > 800.0f) {
                D_800FF188_TreasureDivers[2].vx -= 1.0f;
                D_800FF188_TreasureDivers[2].rot.y += 3.0f;
            } else if (D_800FF188_TreasureDivers[2].pos.x < -800.0f) {
                D_800FF188_TreasureDivers[2].vx += 1.0f;
                D_800FF188_TreasureDivers[2].rot.y += 3.0f;
            } else {
                target = D_800FF188_TreasureDivers[2].pos.x / 2.0f;
                if (target < 0) {
                    target = -target;
                }
            }
            D_800FE434_TreasureDivers += func_800FCA70_TreasureDivers(target, D_800FE434_TreasureDivers, 12);
        } else if (D_800FF188_TreasureDivers[2].pos.x > 1600.0f || D_800FF188_TreasureDivers[2].pos.x < -1600.0f) {
            D_800FF188_TreasureDivers[2].rot.y = 0.0f;
            D_800FF188_TreasureDivers[2].vx = 0.0f;
        }
        D_800FF188_TreasureDivers[2].pos.x += D_800FF188_TreasureDivers[2].vx;
        if (D_800FF188_TreasureDivers[2].rot.y >= 360.0f) {
            D_800FF188_TreasureDivers[2].rot.y -= 360.0f;
        } else if (D_800FF188_TreasureDivers[2].rot.y < 0.0f) {
            D_800FF188_TreasureDivers[2].rot.y += 360.0f;
        }
        obj->scale.x = 1.0f;
        obj->scale.y = 1.0f;
        obj->scale.z = 1.0f;
        obj->rot.x = D_800FF188_TreasureDivers[2].rot.x;
        obj->rot.y = D_800FF188_TreasureDivers[2].rot.y + 100.0f;
        obj->rot.z = D_800FF188_TreasureDivers[2].rot.z;
        obj->trans.x = D_800FF188_TreasureDivers[2].pos.x;
        obj->trans.y = D_800FF188_TreasureDivers[2].pos.y;
        obj->trans.z = D_800FF188_TreasureDivers[2].pos.z;
        v.x = D_800FF188_TreasureDivers[2].pos.x;
        v.y = D_800FF188_TreasureDivers[2].pos.y;
        v.z = D_800FF188_TreasureDivers[2].pos.z;
        func_800FA7E8_TreasureDivers(&v, &s);
        D_800FF188_TreasureDivers[2].scr.x = s.x;
        D_800FF188_TreasureDivers[2].scr.y = s.y;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_04_TreasureDivers/F4420", func_800FC770_TreasureDivers);
#endif

/* A step of `step` degrees from cur towards target the short way round, or 0 when within step. */
s32 func_800FCA70_TreasureDivers(s32 target, s32 cur, s32 step) {
    s32 d;
    s32 dir;

    d = target - cur;
    if (d < 0) {
        d = -d;
    }
    dir = 1;
    if ((u32)d < (u32)step) {
        return 0;
    }
    if ((target - cur + 360) % 360 < 181) {
        dir = -dir;
    }
    return step * dir;
}

/* The overlay's own random number in [0, n) (n = 0: the whole low half of the seed). */
u16 func_800FCAF0_TreasureDivers(u32 n) {
    D_800FE438_TreasureDivers = (D_800FE438_TreasureDivers * 0x19971204 + 0x19760831) >> 16;
    return n != 0 ? D_800FE438_TreasureDivers % n : D_800FE43A_TreasureDivers;
}

void func_800FCB58_TreasureDivers(omObjData* obj) {
    func_80026040(obj->model[6]);
    func_80026040(obj->model[7]);
}

void func_800FCB90_TreasureDivers(omObjData* obj) {
    D_800FE43C_TreasureDivers += 6;
    if (D_800FE43C_TreasureDivers >= 361) {
        D_800FE43C_TreasureDivers = 0;
    }
    func_80026174(obj->model[6], obj->model[7], func_800AEAC0(D_800FE43C_TreasureDivers));
    func_80026174(obj->model[7], obj->model[6], func_800AEAC0(D_800FE43C_TreasureDivers));
}

/* Starts fish i from one side, with a random size and speed. */
void func_800FCC24_TreasureDivers(omObjData* obj, s16 i) {
    s32 j;

    if (i & 1) {
        D_800FFA60_TreasureDivers[i].pos.x = 1690.0f;
        D_800FFA60_TreasureDivers[i].vx = -(func_800FCAF0_TreasureDivers(10) + 15.0f);
    } else {
        D_800FFA60_TreasureDivers[i].pos.x = -1690.0f;
        D_800FFA60_TreasureDivers[i].vx = func_800FCAF0_TreasureDivers(10) + 15.0f;
    }
    D_800FECC0_TreasureDivers[i] = 2.0 * ((f32)(func_800FCAF0_TreasureDivers(5) + 3) / 10.0f);
    D_800FFA60_TreasureDivers[i].pos.y = 500 - i * 300;
    D_800FFA60_TreasureDivers[i].pos.z = -800.0f - D_800FECC0_TreasureDivers[i] * 250.0f;
    D_800FFA60_TreasureDivers[i].rot.x = D_800FFA60_TreasureDivers[i].rot.y = D_800FFA60_TreasureDivers[i].rot.z = 0.0f;
    if (D_800FFA60_TreasureDivers[i].vx < 0.0f) {
        D_800FFA60_TreasureDivers[i].rot.y = 0.0f;
    } else {
        D_800FFA60_TreasureDivers[i].rot.y = 180.0f;
    }
    for (j = 0; j < 10; j++) {
        D_800FE7C8_TreasureDivers[i][j].pos.x = D_800FFA60_TreasureDivers[i].pos.x;
        D_800FE7C8_TreasureDivers[i][j].pos.y = D_800FFA60_TreasureDivers[i].pos.y;
        D_800FE7C8_TreasureDivers[i][j].pos.z = D_800FFA60_TreasureDivers[i].pos.z;
        D_800FE7C8_TreasureDivers[i][j].rot.x = D_800FFA60_TreasureDivers[i].rot.x;
        D_800FE7C8_TreasureDivers[i][j].rot.y = D_800FFA60_TreasureDivers[i].rot.y;
        D_800FE7C8_TreasureDivers[i][j].rot.z = D_800FFA60_TreasureDivers[i].rot.z;
    }
    if (func_800FCAF0_TreasureDivers(2) == 0) {
        func_800258EC(obj->model[i * 3 + 2], 4, 0);
    } else {
        func_800258EC(obj->model[i * 3 + 2], 4, 4);
    }
}

void func_800FCF5C_TreasureDivers(omObjData* obj) {
    s32 i;
    s32 j;

    for (j = 1, i = 0; i < 5; i++, j++) {
        obj->model[j] = func_80023FC8(obj->model[0]);
    }
    func_800258EC(obj->model[2], 4, 4);
    func_800258EC(obj->model[5], 4, 4);
    for (i = 0; i < 2; i++) {
        func_800FCC24_TreasureDivers(obj, i);
    }
}

/* The two fish, each followed by two models replaying its recorded positions. */
// NON_MATCHING: register allocation / scheduling
#ifdef NON_MATCHING
void func_800FD00C_TreasureDivers(omObjData* obj) {
    s32 i;
    s32 k;
    f32 v;
    f32 off;

    for (i = 0; i < 2; i++) {
        if (D_800FE450_TreasureDivers[i] < D_800FFA60_TreasureDivers[i].vx) {
            D_800FE450_TreasureDivers[i]++;
        }
        if (D_800FFA60_TreasureDivers[i].vx < D_800FE450_TreasureDivers[i]) {
            D_800FE450_TreasureDivers[i]--;
        }
        D_800FE7C8_TreasureDivers[i][D_800FE440_TreasureDivers].pos.x = D_800FFA60_TreasureDivers[i].pos.x;
        D_800FE7C8_TreasureDivers[i][D_800FE440_TreasureDivers].pos.y = D_800FFA60_TreasureDivers[i].pos.y;
        D_800FE7C8_TreasureDivers[i][D_800FE440_TreasureDivers].pos.z = D_800FFA60_TreasureDivers[i].pos.z;
        D_800FE7C8_TreasureDivers[i][D_800FE440_TreasureDivers].rot.y = D_800FFA60_TreasureDivers[i].rot.y;
        D_800FE7C8_TreasureDivers[i][D_800FE440_TreasureDivers].rot.z = D_800FFA60_TreasureDivers[i].rot.z;
        D_800FE444_TreasureDivers[i] += 2 + func_800FCAF0_TreasureDivers(3);
        if (D_800FE444_TreasureDivers[i] >= 361) {
            D_800FE444_TreasureDivers[i] = 0;
        }
        D_800FFA60_TreasureDivers[i].pos.x +=
            (func_800AEAC0(D_800FE444_TreasureDivers[i]) + 1.0f) * D_800FFA60_TreasureDivers[i].vx;
        if (D_800FE444_TreasureDivers[i] < 180) {
            D_800FFA60_TreasureDivers[i].pos.y += 3.0f;
        } else {
            D_800FFA60_TreasureDivers[i].pos.y -= 3.0f;
        }
        if (D_800FE444_TreasureDivers[i] == 180 || D_800FE444_TreasureDivers[i] == 0) {
            if (func_800FCAF0_TreasureDivers(0) & 1) {
                D_800FFA60_TreasureDivers[i].vx = -D_800FFA60_TreasureDivers[i].vx;
                if (D_800FFA60_TreasureDivers[i].vx < 0.0f) {
                    D_800FFA60_TreasureDivers[i].rot.y = 0.0f;
                } else {
                    D_800FFA60_TreasureDivers[i].rot.y = 180.0f;
                }
            }
        }
        if (D_800FFA60_TreasureDivers[i].pos.y > 900.0f) {
            D_800FFA60_TreasureDivers[i].pos.y = 890.0f;
        } else if (D_800FFA60_TreasureDivers[i].pos.y < 200.0f) {
            D_800FFA60_TreasureDivers[i].pos.y = 210.0f;
        }
        if (D_800FFA60_TreasureDivers[i].pos.x > 1700.0f || D_800FFA60_TreasureDivers[i].pos.x < -1700.0f) {
            D_800FECC0_TreasureDivers[i] = 2.0 * ((f32)(func_800FCAF0_TreasureDivers(5) + 3) / 10.0f);
            D_800FFA60_TreasureDivers[i].pos.z = -800.0f - D_800FECC0_TreasureDivers[i] * 250.0f;
            D_800FFA60_TreasureDivers[i].pos.y = 800.0f - func_800FCAF0_TreasureDivers(600);
            if (!(func_800FCAF0_TreasureDivers(0) & 1)) {
                D_800FFA60_TreasureDivers[i].pos.x = -1690.0f;
                v = (func_800FCAF0_TreasureDivers(5) + 8) + D_800FECC0_TreasureDivers[i] * 10.0f;
            } else {
                D_800FFA60_TreasureDivers[i].pos.x = 1690.0f;
                v = -((func_800FCAF0_TreasureDivers(5) + 8) + D_800FECC0_TreasureDivers[i] * 10.0f);
            }
            D_800FFA60_TreasureDivers[i].vx = v;
            if (D_800FFA60_TreasureDivers[i].vx < 0.0f) {
                D_800FFA60_TreasureDivers[i].rot.y = 0.0f;
            } else {
                D_800FFA60_TreasureDivers[i].rot.y = 180.0f;
            }
            if (func_800FCAF0_TreasureDivers(2) == 0) {
                func_800258EC(obj->model[i * 3 + 2], 4, 0);
            } else {
                func_800258EC(obj->model[i * 3 + 2], 4, 4);
            }
        }
        if (i == 0) {
            obj->scale.x = D_800FECC0_TreasureDivers[0];
            obj->scale.y = D_800FECC0_TreasureDivers[0];
            obj->scale.z = D_800FECC0_TreasureDivers[0];
            obj->rot.x = D_800FFA60_TreasureDivers[0].rot.x;
            obj->rot.y = D_800FFA60_TreasureDivers[0].rot.y;
            obj->rot.z = D_800FFA60_TreasureDivers[0].rot.z;
            obj->trans.x = D_800FFA60_TreasureDivers[0].pos.x;
            obj->trans.y = D_800FFA60_TreasureDivers[0].pos.y;
            obj->trans.z = D_800FFA60_TreasureDivers[0].pos.z;
        } else {
            func_80025830(obj->model[i * 3], D_800FECC0_TreasureDivers[i], D_800FECC0_TreasureDivers[i],
                          D_800FECC0_TreasureDivers[i]);
            func_800257E4(obj->model[i * 3], D_800FFA60_TreasureDivers[i].rot.x, D_800FFA60_TreasureDivers[i].rot.y,
                          D_800FFA60_TreasureDivers[i].rot.z);
            func_80025798(obj->model[i * 3], D_800FFA60_TreasureDivers[i].pos.x, D_800FFA60_TreasureDivers[i].pos.y,
                          D_800FFA60_TreasureDivers[i].pos.z);
        }
    }
    D_800FE440_TreasureDivers++;
    if (D_800FE440_TreasureDivers >= 10) {
        D_800FE440_TreasureDivers = 0;
    }
    for (i = 0; i < 2; i++) {
        k = D_800FE440_TreasureDivers - 5;
        if (k < 0) {
            k = D_800FE440_TreasureDivers + 5;
        }
        func_80025830(obj->model[i * 3 + 1], D_800FECC0_TreasureDivers[i], D_800FECC0_TreasureDivers[i],
                      D_800FECC0_TreasureDivers[i]);
        func_800257E4(obj->model[i * 3 + 1], D_800FE7C8_TreasureDivers[i][k].rot.x,
                      D_800FE7C8_TreasureDivers[i][k].rot.y, D_800FE7C8_TreasureDivers[i][k].rot.z);
        off = D_800FE450_TreasureDivers[i] * 3;
        func_80025798(obj->model[i * 3 + 1], off + D_800FE7C8_TreasureDivers[i][k].pos.x,
                      off + D_800FE7C8_TreasureDivers[i][k].pos.y, off + D_800FE7C8_TreasureDivers[i][k].pos.z);
    }
    for (i = 0; i < 2; i++) {
        k = D_800FE440_TreasureDivers - 7;
        if (k < 0) {
            k = D_800FE440_TreasureDivers + 3;
        }
        func_80025830(obj->model[i * 3 + 2], D_800FECC0_TreasureDivers[i], D_800FECC0_TreasureDivers[i],
                      D_800FECC0_TreasureDivers[i]);
        func_800257E4(obj->model[i * 3 + 2], D_800FE7C8_TreasureDivers[i][k].rot.x,
                      D_800FE7C8_TreasureDivers[i][k].rot.y, D_800FE7C8_TreasureDivers[i][k].rot.z);
        off = D_800FE450_TreasureDivers[i] * 3;
        func_80025798(obj->model[i * 3 + 2], D_800FE7C8_TreasureDivers[i][k].pos.x - off,
                      D_800FE7C8_TreasureDivers[i][k].pos.y - off, D_800FE7C8_TreasureDivers[i][k].pos.z - off);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_04_TreasureDivers/F4420", func_800FD00C_TreasureDivers);
#endif

void func_800FD934_TreasureDivers(omObjData* obj) {
    func_800FD98C_TreasureDivers(obj->model[5]);
    func_80026040(obj->model[5]);
}

void func_800FD96C_TreasureDivers(omObjData* obj) {
    func_800FDEB4_TreasureDivers(obj->model[5]);
}

/* Grids model m's vertices: each vertex's column (x rank) and row (y rank) go to D_800FECF0. */
// NON_MATCHING: register allocation / scheduling
#ifdef NON_MATCHING
void func_800FD98C_TreasureDivers(s16 m) {
    u16 d[3];
    unk_ovl_2D_struct* mp;
    s32 u;
    unk2C0C0StructE0* v;
    u8* out;
    s16 nx;
    s16 ny;
    s16 i;
    s16 j;
    s16 n;
    s16 t;
    s32 a;

    nx = 0;
    D_800FECEA_TreasureDivers = m;
    mp = &D_800F2B7C[m];
    a = mp->unk_6C->unk_04[0].unk_00 - mp->unk_6C->unk_04[1].unk_00;
    if (a < 0) {
        a = -a;
    }
    d[0] = a;
    a = mp->unk_6C->unk_04[0].unk_02 - mp->unk_6C->unk_04[1].unk_02;
    if (a < 0) {
        a = -a;
    }
    d[1] = a;
    a = mp->unk_6C->unk_04[0].unk_04 - mp->unk_6C->unk_04[1].unk_04;
    if (a < 0) {
        a = -a;
    }
    d[2] = a;
    ny = 0;
    if ((u = d[0]) != 0 || (u = d[1]) != 0 || (u = d[2]) != 0) {
        D_800FECEC_TreasureDivers = (f32)u / 228.0;
    }
    D_800FECF0_TreasureDivers = HuMemDirectMalloc(400);
    v = D_800F2B7C[m].unk_6C->unk_04;
    n = D_800F2B7C[m].unk_6C->unk_72;
    for (i = 0; i < n; i++) {
        for (j = 0; j < nx; j++) {
            if (v->unk_00 == D_800FECC8_TreasureDivers[j]) {
                break;
            }
        }
        if (j >= nx) {
            D_800FECC8_TreasureDivers[nx++] = v->unk_00;
        }
        for (j = 0; j < ny; j++) {
            if (v->unk_02 == D_800FECDE_TreasureDivers[j]) {
                break;
            }
        }
        if (j >= ny) {
            D_800FECDE_TreasureDivers[ny++] = v->unk_02;
        }
        v++;
    }
    for (i = 0; i < nx - 1; i++) {
        for (j = i; j < nx; j++) {
            if (D_800FECC8_TreasureDivers[j] < D_800FECC8_TreasureDivers[i]) {
                t = D_800FECC8_TreasureDivers[i];
                D_800FECC8_TreasureDivers[i] = D_800FECC8_TreasureDivers[j];
                D_800FECC8_TreasureDivers[j] = t;
            }
        }
    }
    for (i = 0; i < ny - 1; i++) {
        for (j = i; j < ny; j++) {
            if (D_800FECDE_TreasureDivers[j] < D_800FECDE_TreasureDivers[i]) {
                t = D_800FECDE_TreasureDivers[i];
                D_800FECDE_TreasureDivers[i] = D_800FECDE_TreasureDivers[j];
                D_800FECDE_TreasureDivers[j] = t;
            }
        }
    }
    v = D_800F2B7C[m].unk_6C->unk_04;
    out = D_800FECF0_TreasureDivers;
    for (i = 0; i < n; i++) {
        for (j = 0; j < nx; j++) {
            if (D_800FECC8_TreasureDivers[j] == v->unk_00) {
                break;
            }
        }
        out[0] = j;
        /* Retail bounds the row search by the column count too. */
        for (j = 0; j < nx; j++) {
            if (D_800FECDE_TreasureDivers[j] == v->unk_02) {
                break;
            }
        }
        out[1] = j;
        v++;
        out += 2;
    }
    D_800FE45C_TreasureDivers = D_800FE460_TreasureDivers = D_800FE464_TreasureDivers = 0.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_04_TreasureDivers/F4420", func_800FD98C_TreasureDivers);
#endif

/* Waves model m's vertices (the sea surface) and scrolls its texture. */
// NON_MATCHING: register allocation / scheduling
#ifdef NON_MATCHING
void func_800FDEB4_TreasureDivers(s16 m) {
    unk2C0C0StructC0* c;
    unk2C0C0StructE0* src;
    unk2C0C0StructE0* dst;
    u8* p;
    f32 s;
    f32 x;
    f32 y;
    s16 i;
    s16 n;

    if (D_800FE45C_TreasureDivers == 0.0f) {
        for (i = 0; i < 4; i++) {
            D_800FE77C_TreasureDivers[i + 1] =
                (D_800FECEC_TreasureDivers * 45.0f + D_800FECEC_TreasureDivers * 20.0f) - 1.0f;
        }
        for (i = 0; i < 10; i++) {
            D_800FE794_TreasureDivers[i + 1] =
                (D_800FECEC_TreasureDivers * 45.0f / 3.0f + D_800FECEC_TreasureDivers * 6.0f) - 1.0f;
        }
    }
    s = func_800AEAC0((s32)D_800FE45C_TreasureDivers);
    p = D_800FECF0_TreasureDivers;
    c = D_800F2B7C[m].unk_6C;
    src = c->unk_04;
    dst = c->unk_08[D_800F37F0];
    n = c->unk_72;
    for (i = 0; i < n; i++) {
        *dst = *src;
        if (!(p[0] == 0 || p[0] == 10) && !(p[1] == 0 || p[1] == 5)) {
            if (p[1] & 1) {
                if (!((p[0] >> 1) & 1)) {
                    x = src->unk_00 - s * D_800FE77C_TreasureDivers[p[1]];
                } else {
                    x = src->unk_00 + s * D_800FE77C_TreasureDivers[p[1]];
                }
            } else if ((p[0] >> 1) & 1) {
                x = src->unk_00 - s * D_800FE77C_TreasureDivers[p[1]];
            } else {
                x = src->unk_00 + s * D_800FE77C_TreasureDivers[p[1]];
            }
            dst->unk_00 = x;
            if (p[0] & 1) {
                y = src->unk_02 - s * D_800FE794_TreasureDivers[p[0]];
            } else {
                y = src->unk_02 + s * D_800FE794_TreasureDivers[p[0]];
            }
            dst->unk_02 = y;
        }
        src++;
        dst++;
        p += 2;
    }
    if (D_800FE464_TreasureDivers > 32.0) {
        D_800FE464_TreasureDivers -= 32.0;
    }
    func_80027C1C(m, -D_800FE464_TreasureDivers, 0.0f, 16, 16);
    if (func_8005FD5C() + D_800F64F8 == 0) {
        D_800FE45C_TreasureDivers += D_800FECEC_TreasureDivers * 2.5f;
        if (D_800FE45C_TreasureDivers > 360.0f) {
            D_800FE45C_TreasureDivers = 0.0f;
        }
        D_800FE464_TreasureDivers += D_800FECEC_TreasureDivers * 3.1736112f * 0.1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_04_TreasureDivers/F4420", func_800FDEB4_TreasureDivers);
#endif

void func_800FE368_TreasureDivers(void) {
    HuMemDirectFree(D_800FECF0_TreasureDivers);
}
