#include "common.h"
#include "PedalPower.h"

/* .data (0x800F9E50) */
u16 D_800F9E50_PedalPower = 0; /* players skipped before the pedalling one */
u8 D_800F9E52_PedalPower = 0;  /* coins handed out */
u16 D_800F9E54_PedalPower = 0;
u16 D_800F9E56_PedalPower = 0;
u16 D_800F9E58_PedalPower = 0;
u16 D_800F9E5A_PedalPower = 0;
u16 D_800F9E5C_PedalPower = 0;
s8 D_800F9E5E_PedalPower = 0;

void func_800F8F9C_PedalPower(omObjData* arg0);
void func_800F9200_PedalPower(omObjData* arg0);
void func_800F9728_PedalPower(omObjData* arg0);

void func_800F8EE0_PedalPower(void) {
    s32 i;

    D_800F2BC0 = 0;
    for (i = 0; i < 4; i++) {
        if (GwPlayer[i].group == 0) {
            D_800FA728_PedalPower = i;
            D_800F3FB0[D_800F2BC0++] = omAddObj(2, 2, 0x32, -1, func_800F8F9C_PedalPower);
            return;
        }
        D_800F9E50_PedalPower++;
    }
}

void func_800F8F9C_PedalPower(omObjData* arg0) {
    PPWork* work;
    s32 dir;
    s8 chr;

    arg0->unk_50 = func_80023684(sizeof(PPWork), 0x7918);
    func_8009B770(arg0->unk_50, 0, sizeof(PPWork));
    work = arg0->unk_50;
    work->unk_D8 = func_80023684(arg0->mtncnt * 4, 0x7918);
    func_8009B770(work->unk_D8, 0, arg0->mtncnt * 4);
    chr = GwPlayer[D_800FA728_PedalPower].character;
    dir = D_800C59AC[chr].unk_00;
    D_800FA724_PedalPower = (u32)dir >> 16;
    arg0->model[0] = LoadFormFile(dir | D_800C59AC[chr].unk_04, 0xD9);
    arg0->model[1] = func_800174F4(6, 0xD9);
    arg0->trans.x = -180.0f;
    arg0->trans.y = 0.0f;
    arg0->trans.z = 500.0f;
    arg0->scale.z = 1.2f;
    arg0->scale.y = 1.2f;
    arg0->scale.x = 1.2f;
    arg0->rot.y = -90.0f;
    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_800257E4(arg0->model[0], arg0->rot.x, arg0->rot.y, arg0->rot.z);
    func_80025830(arg0->model[0], arg0->scale.x, arg0->scale.y, arg0->scale.z);
    work->unk_56 = GwPlayer[D_800FA728_PedalPower].port;
    if (GwPlayer[D_800FA728_PedalPower].flags & 1) {
        work->unk_E8 = 0;
    } else {
        work->unk_E8 = 1;
    }
    arg0->func_ptr = func_800F9200_PedalPower;
    func_800090C4(arg0, 0, 2);
    func_8001874C(arg0, 0x16, dir | 0x66, 0, 0);
    func_8001874C(arg0, 0x23, dir | 0x53, 0, 0);
    func_8001874C(arg0, 0x25, dir | 0x76, 0, 0);
    func_8001874C(arg0, 0x26, dir | 0x77, 1, 0);
}

void func_800F9200_PedalPower(omObjData* arg0) {
    unk_ovl_2D_struct* s1;
    f32 t;

    s1 = &D_800F2B7C[arg0->model[0]];
    D_800FA730_PedalPower.x = arg0->trans.x;
    D_800FA730_PedalPower.y = arg0->trans.y;
    switch (D_800ED430) {
    case 0:
        s1->unk_4C = 0.0f;
        func_800184BC(arg0, 0x23);
        func_80025CA8(arg0->model[0], D_800FA720_PedalPower);
        func_80017DB0(arg0);
        break;
    case 1:
        func_80025CA8(arg0->model[0], D_800FA720_PedalPower);
        func_800F9728_PedalPower(arg0);
        break;
    case 2:
    case 3:
        if (D_800FA72C_PedalPower == 1) {
            if (D_800F9E52_PedalPower == 0) {
                GwPlayer[D_800FA728_PedalPower].coins_mg += 10;
                D_800F9E52_PedalPower = 1;
            }
            func_80025CA8(arg0->model[0], D_800FA720_PedalPower);
            func_800184BC(arg0, 0x23);
        } else if (D_800FA72C_PedalPower == 2) {
            if (D_800F9E52_PedalPower == 0) {
                GwPlayer[D_800FA728_PedalPower].coins_mg -= 5;
                D_800F9E52_PedalPower = 1;
            }
        }
        s1->unk_4C = 1.0f;
        if (D_800FA72C_PedalPower == 1) {
            if (_CheckFlag(0x2B) == 0) {
                t = func_80025D90(arg0->model[0]);
                if (func_80025DD8(arg0->model[0]) <= t) {
                    func_80028928(arg0->model[0], 1, 1, 0);
                    func_8000A6F4(arg0);
                    D_800F2B7C[arg0->model[0]].unk_60 = 0.0f;
                }
                if (func_80025D90(arg0->model[0]) == 0.0f) {
                    func_80028498(arg0->model[0], func_80025E48(arg0->motion[0x25] & 0x3FFF), 0);
                    func_80028928(arg0->model[0], 1, 1, 0);
                    func_80028928(arg0->model[0], 4, 1, 0);
                }
                func_80025CA8(arg0->model[0], D_800FA720_PedalPower);
                func_800184BC(arg0, 0x23);
            }
        } else {
            func_8000A6F4(arg0);
            func_800184BC(arg0, 0x26);
            if ((D_800FA710_PedalPower & 1) && (D_800FA710_PedalPower & 2)) {
                if (D_800FA724_PedalPower == 1) {
                    arg0->trans.x = D_800FA73C_PedalPower.x - 10.0f;
                    arg0->trans.y = D_800FA73C_PedalPower.y - 130.0f;
                } else {
                    arg0->trans.x = D_800FA73C_PedalPower.x + 20.0f;
                    arg0->trans.y = D_800FA73C_PedalPower.y - 120.0f;
                }
                arg0->trans.z = D_800FA73C_PedalPower.z;
            } else if (D_800FA724_PedalPower == 1) {
                if (arg0->trans.x < D_800FA73C_PedalPower.x - 10.0f) {
                    arg0->trans.x += 2.0f;
                } else {
                    D_800FA710_PedalPower |= 1;
                }
                if (arg0->trans.y < D_800FA73C_PedalPower.y - 130.0f) {
                    arg0->trans.y += 2.0f;
                } else {
                    D_800FA710_PedalPower |= 2;
                }
            } else {
                if (arg0->trans.x < D_800FA73C_PedalPower.x + 20.0f) {
                    arg0->trans.x += 2.0f;
                } else {
                    D_800FA710_PedalPower |= 1;
                }
                if (arg0->trans.y < D_800FA73C_PedalPower.y - 120.0f) {
                    arg0->trans.y += 2.0f;
                } else {
                    D_800FA710_PedalPower |= 2;
                }
            }
        }
        func_80017DB0(arg0);
        break;
    }
}

void func_800F9728_PedalPower(omObjData* arg0) {
    PPWork* work;
    unk_ovl_2D_struct* s3;
    s16 stick;
    f32 t;

    work = arg0->unk_50;
    s3 = &D_800F2B7C[arg0->model[0]];
    stick = 0;
    if (work->unk_E8 == 0) {
        if (D_800F9E5E_PedalPower == 0) {
            if (GwPlayer[D_800FA728_PedalPower].cpu_difficulty == 0) {
                if (rand8() >> 6) {
                    D_800F9E5E_PedalPower = -1;
                } else {
                    D_800F9E5E_PedalPower = 1;
                }
            } else if (GwPlayer[D_800FA728_PedalPower].cpu_difficulty == 1) {
                if (rand8() >> 7) {
                    D_800F9E5E_PedalPower = -1;
                } else {
                    D_800F9E5E_PedalPower = 1;
                }
            } else if (GwPlayer[D_800FA728_PedalPower].cpu_difficulty == 2) {
                if ((s32)((u32)(rand8() * 5) >> 7) < 8) {
                    D_800F9E5E_PedalPower = 1;
                } else {
                    D_800F9E5E_PedalPower = -1;
                }
            } else if (GwPlayer[D_800FA728_PedalPower].cpu_difficulty == 3) {
                if (((rand8() * 255) >> 8) < 0xFE) {
                    D_800F9E5E_PedalPower = 1;
                } else {
                    D_800F9E5E_PedalPower = -1;
                }
            }
        }
        if (D_800F9E5E_PedalPower == 1) {
            if (((rand8() * 7) >> 8) == 1) {
                goto pedal;
            }
        } else if (D_800F9E5E_PedalPower == -1) {
            if (((u32)(rand8() * 5) >> 7) == 1) {
                goto pedal;
            }
        }
    } else {
        stick = func_80009E4C((s16)D_800FA728_PedalPower, 0x20, ContStkX[GwPlayer[D_800FA728_PedalPower].port],
                              ContStkY[GwPlayer[D_800FA728_PedalPower].port]);
        if ((stick == -2) | (stick == 2)) {
        pedal:
            D_800F9E54_PedalPower++;
            D_800FA738_PedalPower++;
        }
    }
    if (D_800F9E5A_PedalPower >= 5 && D_800FA738_PedalPower > 0) {
        D_800FA738_PedalPower--;
        if (D_800FA738_PedalPower < 0) {
            D_800FA738_PedalPower = 0;
        }
        D_800F9E5A_PedalPower = 0;
    }
    if ((u16)(D_800F9E56_PedalPower % 30) == 0 || D_800FA72D_PedalPower == 0) {
        if ((D_800F9E54_PedalPower == 0) & (stick != 0)) {
            s3->unk_4C = 0.5f;
            D_800FA72D_PedalPower = 1;
            D_800F9E5A_PedalPower++;
        } else if (D_800F9E54_PedalPower == 0) {
            s3->unk_4C = 0.0f;
            D_800FA72D_PedalPower = 0;
            D_800F9E5A_PedalPower++;
        } else if (D_800F9E54_PedalPower < 2) {
            s3->unk_4C = 1.0f;
            D_800FA72D_PedalPower = 2;
        } else {
            s3->unk_4C = 2.0f;
            D_800FA72D_PedalPower = 3;
        }
        if ((u16)(D_800F9E56_PedalPower % 30) == 0) {
            D_800F9E54_PedalPower = 0;
        }
    }
    if ((s8)(D_800FA738_PedalPower % 10) == 0 && D_800FA738_PedalPower > 0 && D_800FA738_PedalPower < 70
        && D_800F9E5C_PedalPower < D_800FA738_PedalPower) {
        D_800F9E58_PedalPower = 1;
        D_800F9E5C_PedalPower = D_800FA738_PedalPower;
    }
    if (D_800F9E56_PedalPower == 0x383) {
        if (D_800FA738_PedalPower >= 70) {
            D_800FA72C_PedalPower = 1;
        } else {
            D_800FA72C_PedalPower = 2;
        }
    }
    if (D_800F9E58_PedalPower != 0) {
        s3->unk_4C = 1.0f;
        t = func_80025D90(arg0->model[0]);
        if (t >= 40.0f) {
            func_80028928(arg0->model[0], 1, 1, 0);
            func_8000A6F4(arg0);
            D_800F9E58_PedalPower = 0;
            D_800F2B7C[arg0->model[0]].unk_60 = 0.0f;
        } else if (t == 0.0f) {
            func_80028498(arg0->model[0], func_80025E48(arg0->motion[0x16] & 0x3FFF), 0);
            if (D_800FA72D_PedalPower == 0.0f) {
                func_80028928(arg0->model[0], 1, 1, 1);
            } else {
                func_80028928(arg0->model[0], 1, 1, 0);
            }
            func_80028928(arg0->model[0], 4, 1, 0);
        }
    }
    func_800184BC(arg0, 0x23);
    func_80017DB0(arg0);
    if (D_800FA738_PedalPower >= 70) {
        D_800FA72C_PedalPower = 1;
        func_80009438();
    }
    if (D_800FA72C_PedalPower == 2) {
        func_80009438();
    }
    D_800F9E56_PedalPower++;
}
