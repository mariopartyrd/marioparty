#include "common.h"
#include "ShellGame.h"
#include "engine/pad.h"

/* .data (0x800FEC40..0x800FEC60) */
omObjData* D_800FEC40_ShellGame = NULL;
omObjData* D_800FEC44_ShellGame = NULL;
s16 D_800FEC48_ShellGame = 1;
s16 D_800FEC4A_ShellGame = 0;
f32 D_800FEC4C_ShellGame = 0.0f;
f32 D_800FEC50_ShellGame = 0.0f;
u16 D_800FEC54_ShellGame = 0;
f32 D_800FEC58_ShellGame = 0.0f;
s16 D_800FEC5C_ShellGame = 0;

// NON_MATCHING: register reuse of the character index
#ifdef NON_MATCHING
void func_800FCF90_ShellGame(omObjData* obj) {
    struct {
        s16 mot[4];
        u16 len[4];
    } dizzy, cheer;
    SGPlayerWork* w;
    s32 ch;
    u16 c;
    u16 i;
    u16 pl;
    u16 r;

    dizzy.mot[0] = 15;
    dizzy.mot[1] = 56;
    dizzy.len[0] = 120;
    dizzy.len[1] = 120;
    cheer.mot[0] = 16;
    cheer.mot[1] = 60;
    cheer.len[0] = 120;
    cheer.len[1] = 120;
    D_800FEC44_ShellGame = NULL;
    D_800FF79C_ShellGame = D_800FF798_ShellGame = 0.0f;
    for (i = 0; i < 4; i++) {
        if (GwPlayer[i].group == 0) {
            break;
        }
    }
    switch (i) {
    case 0:
        pl = 0;
        break;
    case 1:
        pl = 1;
        break;
    case 2:
        pl = 2;
        break;
    case 3:
        pl = 3;
        break;
    default:
        pl = 0;
        break;
    }
    D_800FF9F0_ShellGame = pl;
    D_800FF794_ShellGame = GwPlayer[pl].port;
    D_800FF796_ShellGame = 0;
    if (GwPlayer[pl].flags & 1) {
        D_800FF792_ShellGame = 1;
    } else {
        D_800FF792_ShellGame = 0;
    }
    c = GwPlayer[pl].character;
    D_800FFA0C_ShellGame = c;
    ch = D_800C59AC[c].unk_00;
    func_80009618(1);
    func_8000979C(obj, ch, 0x9E, pl, 0x699, 0x699);
    func_80009500();
    obj->func_ptr = &func_800FD448_ShellGame;
    w = obj->unk_50;
    w->unkDC = &func_800FE87C_ShellGame;
    obj->model[3] = LoadFormFile(0x19, 0x68D);
    obj->model[4] = LoadFormFile(0x1A, 0x68D);
    obj->model[6] = LoadFormFile(0x1B, 0x68D);
    obj->model[5] = LoadFormFile(0x1C, 0x68D);
    obj->model[7] = LoadFormFile(0x1E, 0x68D);
    obj->model[8] = LoadFormFile(0x1D, 0x68D);
    func_800187D0(obj, 0, ch, 1, 0);
    func_800187D0(obj, 1, ch | 1, 1, 0);
    func_800187D0(obj, 2, ch | 3, 1, 0);
    func_800187D0(obj, 5, ch | 4, 0, 0);
    func_800187D0(obj, 6, ch | 5, 1, 0x13);
    func_800187D0(obj, 7, ch | 6, 1, 0x22);
    func_800187D0(obj, 8, ch | 9, 1, 0x1B);
    func_800187D0(obj, 0x11, ch | 0x18, 0, 0);
    func_800187D0(obj, 0x12, ch | 0x1C, 2, 0);
    func_8001874C(obj, 0x15, ch | 0x62, 0, 0);
    func_8001874C(obj, 0x14, ch | 0x5F, 0, 0);
    func_8001874C(obj, 4, ch | 0x61, 1, 0);
    func_8001874C(obj, 0x20, ch | 0x67, 0, 0);
    func_8001874C(obj, 0x21, ch | 0x68, 2, 0);
    func_8001874C(obj, 0x22, ch | 0x69, 2, 0);
    func_8001874C(obj, 0x23, ch | 0x2F, 1, 4);
    r = func_800F719C_ShellGame(2);
    func_8001874C(obj, 0x24, ch | dizzy.mot[r], 1, dizzy.len[r]);
    r = func_800F719C_ShellGame(2);
    func_8001874C(obj, 0x25, ch | cheer.mot[r], 1, cheer.len[r]);
    func_800093FC(obj, 0.0f, 0.0f, 200.0f);
    func_8000940C(obj, 0.0f, 180.0f, 0.0f);
    func_800FDD94_ShellGame(obj->work[0]);
    func_800090C4(obj, 0, 2);
    D_800ED430 = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/FD460", func_800FCF90_ShellGame);
#endif
void func_800FD448_ShellGame(omObjData* obj) {
    switch (D_800FF9EC_ShellGame) {
    case 3:
        if (D_800FF792_ShellGame != 0) {
            func_800FD538_ShellGame(obj);
        }
        func_80005A28(obj);
        func_800FE07C_ShellGame(obj);
        func_800FDF28_ShellGame(obj);
        break;
    case 2:
    case 4:
        func_800FDE50_ShellGame(obj);
        func_800FD808_ShellGame(obj);
        func_80017DB0(obj);
        break;
    default:
        func_80005A28(obj);
        func_800FDF28_ShellGame(obj);
        break;
    }
    if (D_800FEC44_ShellGame != NULL) {
        func_800FE5BC_ShellGame(obj);
    }
    func_800FE46C_ShellGame(obj);
    func_800FE7B4_ShellGame(obj);
    func_800FEB40_ShellGame(obj);
}
// NON_MATCHING: retail reloads the answer shell in each skill case
#ifdef NON_MATCHING
void func_800FD538_ShellGame(omObjData* obj) {
    omObjData* sh;
    f32 dx;
    f32 dz;
    f32 d;
    f32 a;
    f32 sx;
    f32 sy;
    s16 t;

    ContStkX[D_800FF794_ShellGame] = 0;
    ContStkY[D_800FF794_ShellGame] = 0;
    ContBtnTrg[D_800FF794_ShellGame] = 0;
    ContBtn[D_800FF794_ShellGame] = 0;
    if (D_800FEC48_ShellGame != 0) {
        switch (D_800FF9D0_ShellGame.unk0) {
        case 1:
            if (func_800F719C_ShellGame(100) < 25) {
                t = D_800FF9D0_ShellGame.unk4;
            } else {
                t = func_800F719C_ShellGame(D_800FF9D0_ShellGame.unk2);
            }
            break;
        case 2:
            if (func_800F719C_ShellGame(100) < 50) {
                t = D_800FF9D0_ShellGame.unk4;
            } else {
                t = func_800F719C_ShellGame(D_800FF9D0_ShellGame.unk2);
            }
            break;
        case 3:
            if (func_800F719C_ShellGame(100) < 75) {
                t = D_800FF9D0_ShellGame.unk4;
            } else {
                t = func_800F719C_ShellGame(D_800FF9D0_ShellGame.unk2);
            }
            break;
        case 4:
            if (func_800F719C_ShellGame(100) < 99) {
                t = D_800FF9D0_ShellGame.unk4;
            } else {
                t = func_800F719C_ShellGame(D_800FF9D0_ShellGame.unk2);
            }
            break;
        default:
            if (func_800F719C_ShellGame(100) < 50) {
                t = D_800FF9D0_ShellGame.unk4;
            } else {
                t = func_800F719C_ShellGame(D_800FF9D0_ShellGame.unk2);
            }
            break;
        }
        D_800FEC4A_ShellGame = t;
        D_800FEC48_ShellGame = 0;
    }
    sh = D_800FF9F8_ShellGame[D_800FEC4A_ShellGame];
    dx = sh->trans.x - obj->trans.x;
    dz = sh->trans.z - obj->trans.z;
    a = func_800F7398_ShellGame(dx, dz);
    d = sqrtf(dx * dx + dz * dz);
    sx = func_800AEAC0(a) * 64.0f;
    sy = -(func_800AEFD0(a) * 64.0f);
    ContStkX[D_800FF794_ShellGame] = sx;
    ContStkY[D_800FF794_ShellGame] = sy;
    if (d < 200.0) {
        ContBtnTrg[D_800FF794_ShellGame] |= 0x8000;
        ContBtn[D_800FF794_ShellGame] |= 0x8000;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/FD460", func_800FD538_ShellGame);
#endif
// NON_MATCHING: branch-likely choice in two angle wraps
#ifdef NON_MATCHING
void func_800FD808_ShellGame(omObjData* obj) {
    SGPlayer* pl;
    f32 a;
    f32 d;
    s32 show;

    pl = &D_800FFA10_ShellGame[obj->work[0]];
    func_80025798(obj->model[1], obj->trans.x, 2.0f, obj->trans.z);
    if (D_800FF9D0_ShellGame.unk8 != 0) {
        obj->rot.y = obj->rot.y + D_800FF9D0_ShellGame.unkC;
        if (obj->rot.y > 360.0) {
            obj->rot.y -= 360.0;
        } else if (obj->rot.y < 0.0) {
            obj->rot.y += 360.0;
        }
        if (D_800FF9D0_ShellGame.unk8 < 5) {
            D_800FF9D0_ShellGame.unkC = D_800FF9D0_ShellGame.unkC * 0.7;
        }
        pl->unkC = obj->rot.y;
        pl->unk8 = obj->rot.y;
        pl->unk18 = 0;
        a = func_800F7398_ShellGame(obj->trans.x, obj->trans.z) + 180.0;
        if (a > 360.0) {
            a -= 360.0;
        }
        d = sqrtf(obj->trans.x * obj->trans.x + obj->trans.z * obj->trans.z) / 5.0;
        obj->trans.x = func_800AEAC0(a) * d + obj->trans.x;
        obj->trans.z = func_800AEFD0(a) * d + obj->trans.z;
        D_800FF9D0_ShellGame.unk8--;
        func_800FDE08_ShellGame(obj, 0);
    } else {
        if (D_800FF9EC_ShellGame == 2) {
            if (D_800FEC54_ShellGame++ >= 4) {
                D_800FEC4C_ShellGame = func_800F719C_ShellGame(360);
                a = func_800AEAC0(D_800FEC4C_ShellGame) * 40.0 - obj->trans.x;
                D_800FEC4C_ShellGame =
                    func_800F7398_ShellGame(a, func_800AEFD0(D_800FEC4C_ShellGame) * 40.0 - obj->trans.z);
                D_800FEC50_ShellGame = (f32)func_800F719C_ShellGame(100) / 100.0;
                D_800FEC50_ShellGame = D_800FEC50_ShellGame * D_800B8984;
                D_800FEC54_ShellGame = 0;
            }
            obj->trans.x = func_800AEAC0(D_800FEC4C_ShellGame) * D_800FEC50_ShellGame + obj->trans.x;
            obj->trans.z = func_800AEFD0(D_800FEC4C_ShellGame) * D_800FEC50_ShellGame + obj->trans.z;
            obj->rot.y = func_800F7230_ShellGame(D_800FEC4C_ShellGame, obj->rot.y, 25.0f) + obj->rot.y;
            func_800FDE08_ShellGame(obj, 1);
        } else if (D_800FF9EC_ShellGame == 4) {
            if (D_800FFA3C_ShellGame == 0x29A) {
                obj->rot.y = func_800F7230_ShellGame(0.0f, obj->rot.y, 25.0f) + obj->rot.y;
                if (obj->rot.y > 360.0) {
                    obj->rot.y -= 360.0;
                } else if (obj->rot.y < 0.0) {
                    obj->rot.y += 360.0;
                }
                pl->unkC = pl->unk8 = obj->rot.y;
                func_800FDE08_ShellGame(obj, 0x23);
                show = 1;
            } else if (D_800FFA3C_ShellGame == 0x14D) {
                obj->rot.y = func_800F7230_ShellGame(0.0f, obj->rot.y, 25.0f) + obj->rot.y;
                if (obj->rot.y > 360.0) {
                    obj->rot.y -= 360.0;
                } else if (obj->rot.y < 0.0) {
                    obj->rot.y += 360.0;
                }
                func_800FDE08_ShellGame(obj, 0x25);
                show = 0;
            } else if (D_800FFA3C_ShellGame == 0x309) {
                obj->rot.y = func_800F7230_ShellGame(0.0f, obj->rot.y, 25.0f) + obj->rot.y;
                if (obj->rot.y > 360.0) {
                    obj->rot.y -= 360.0;
                } else if (obj->rot.y < 0.0) {
                    obj->rot.y += 360.0;
                }
                func_800FDE08_ShellGame(obj, 0x24);
                show = 0;
            } else {
                func_800FDE08_ShellGame(obj, 0);
                show = 0;
            }
            func_800F7DA8_ShellGame(obj, show);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/FD460", func_800FD808_ShellGame);
#endif
// NON_MATCHING: retail addresses each field through its own label
#ifdef NON_MATCHING
void func_800FDD94_ShellGame(u16 n) {
    if (n == 0) {
        D_800FFA10_ShellGame[0].unk0 = 0;
        D_800FFA10_ShellGame[0].unk2 = 0;
        D_800FFA10_ShellGame[0].unk4 = -1;
        D_800FFA10_ShellGame[0].unk8 = 180.0f;
        D_800FFA10_ShellGame[0].unkC = 180.0f;
        D_800FFA10_ShellGame[0].unk10 = 180.0f;
        D_800FFA10_ShellGame[0].unk14 = 0;
        D_800FFA10_ShellGame[0].unk18 = 0;
        D_800FFA10_ShellGame[0].unk1C = 0;
        D_800FFA10_ShellGame[0].unk20 = 0;
        D_800FFA10_ShellGame[0].unk28 = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/FD460", func_800FDD94_ShellGame);
#endif
void func_800FDE08_ShellGame(omObjData* obj, s16 mot) {
    if (D_800FF790_ShellGame != mot) {
        func_800184BC(obj, mot);
    }
    D_800FF790_ShellGame = mot;
}
void func_800FDE50_ShellGame(omObjData* obj) {
    SGPlayerWork* w;

    w = obj->unk_50;
    w->unk3C = func_800F7230_ShellGame(0.0f, w->unk3C, 25.0f) + w->unk3C;
    if (w->unk3C > 360.0) {
        w->unk3C -= 360.0;
    } else if (w->unk3C < 0.0) {
        w->unk3C += 360.0;
    }
    func_8009ECB0(D_800F2B7C[obj->model[0]].unk7C, 0.0f, w->unk3C, 0.0f);
}
void func_800FDF28_ShellGame(omObjData* obj) {
    SGPlayerWork* w = obj->unk_50;

    D_800FEC58_ShellGame = func_800F7230_ShellGame(w->unk3C, D_800FEC58_ShellGame, 25.0f) + D_800FEC58_ShellGame;
    if (D_800FEC58_ShellGame > 360.0) {
        D_800FEC58_ShellGame -= 360.0;
    } else if (D_800FEC58_ShellGame < 0.0) {
        D_800FEC58_ShellGame += 360.0;
    }
    func_8009ECB0(D_800F2B7C[obj->model[0]].unk7C, 0.0f, D_800FEC58_ShellGame, 0.0f);
}
// NON_MATCHING: retail reloads obj->work[0] for each use
#ifdef NON_MATCHING
void func_800FE010_ShellGame(omObjData* obj) {
    if (obj->work[0] < D_800FF9D0_ShellGame.unk2) {
        D_800FEC16_ShellGame = 0;
        D_800FF7A0_ShellGame[obj->work[0]].unk0 = 1;
        D_800FF7A0_ShellGame[obj->work[0]].unkC = 0;
        D_800FF796_ShellGame = 1;
        func_800790C0();
        D_800ED430 = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/FD460", func_800FE010_ShellGame);
#endif
// NON_MATCHING: register allocation / scheduling
#ifdef NON_MATCHING
void func_800FE07C_ShellGame(omObjData* obj) {
    SGPlayerWork* w;
    omObjData* o;
    SGShellWork* sw;
    f32 f;
    f32 reach;
    f32 dx;
    f32 dz;
    f32 d;
    f32 a;
    f32 t;
    f32 x;
    f32 z;
    f32 vz;
    u16 i;

    w = obj->unk_50;
    if ((w->unk5C == 0x40) | (w->unk5C == 0x100)) {
        f = func_80025E70(obj->model[0]);
        if (f == -1.0f) {
            f = func_80025D18(obj->model[0]);
        }
        if ((f >= 16.0f) & (f <= 20.0f)) {
            reach = w->unk64 + w->unk48;
            for (i = 0; i < (u16)D_800EE984; i++) {
                o = D_800EDE70[i];
                sw = o->unk_50;
                dx = o->trans.x - obj->trans.x;
                dz = o->trans.z - obj->trans.z;
                d = sqrtf(dx * dx + dz * dz);
                a = func_800F7398_ShellGame(dx, dz);
                if (d < reach + sw->unk48 && (t = func_800F7230_ShellGame(a, w->unk3C, 31.0f)) >= -30.0 && t <= 30.0) {
                    if (w->unk5C != 0x100 || !(sw->unk34 * 3.0f < obj->trans.y)) {
                        w->unk3C = w->unk3C;
                        w->unk40 = 0;
                        x = func_800AEAC0(a) * d + obj->trans.x;
                        z = func_800AEFD0(a) * d + obj->trans.z;
                        vz = func_800AEFD0(w->unk3C) * 60.0;
                        func_80017C0C(obj, 7, x, obj->trans.y + sw->unk34, z, vz, func_800AEAC0(w->unk3C) * 60.0);
                        PlaySound(0x1E6);
                        func_80060F04(w->unk58, 2, 3, 10);
                        func_800FE010_ShellGame(o);
                        D_800FEC44_ShellGame = o;
                        D_800FF79C_ShellGame = w->unk3C;
                    }
                    break;
                }
            }
        }
    } else if (w->unk5C == 0x200) {
        f = func_80025E70(obj->model[0]);
        if (f == -1.0f) {
            f = func_80025D18(obj->model[0]);
        }
        if (f >= 27.0f && obj->trans.y == 0.0f) {
            D_800FEC18_ShellGame = 1;
            D_800FEC1C_ShellGame = 40.0f;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/FD460", func_800FE07C_ShellGame);
#endif
void func_800FE46C_ShellGame(omObjData* obj) {
    f32 a;
    f32 d;

    if (D_800FEC16_ShellGame == 0 && D_800ED430 != 1 && obj->trans.y != 0.0f) {
        a = func_800F7398_ShellGame(obj->trans.x, obj->trans.z);
        d = sqrtf(obj->trans.x * obj->trans.x + obj->trans.z * obj->trans.z);
        if (d >= 20.0) {
            obj->trans.x = obj->trans.x - func_800AEAC0(a) * 20.0;
            obj->trans.z = obj->trans.z - func_800AEFD0(a) * 20.0;
        } else {
            obj->trans.x = obj->trans.x - func_800AEAC0(a) * d;
            obj->trans.z = obj->trans.z - func_800AEFD0(a) * d;
        }
    }
}
void func_800FE5BC_ShellGame(omObjData* obj) {
    switch (D_800FEC5C_ShellGame) {
    case 0:
        D_800FEC5C_ShellGame++;
        D_800FF798_ShellGame = 20.0f;
        break;
    case 1:
        obj->trans.x = obj->trans.x - func_800AEAC0(D_800FF79C_ShellGame) * D_800FF798_ShellGame;
        obj->trans.z = obj->trans.z - func_800AEFD0(D_800FF79C_ShellGame) * D_800FF798_ShellGame;
        D_800FF798_ShellGame = D_800FF798_ShellGame - 2.0;
        if (D_800FF798_ShellGame <= 0.0) {
            D_800FEC5C_ShellGame++;
        }
        break;
    }
}
// NON_MATCHING: retail keeps 0.0f in saved $f20 and passes it to func_80009028's arg1 with mfc1, i.e. this
// unit saw an f32 second parameter; the shared s32 prototype is right for the other callers (M1c)
#ifdef NON_MATCHING
void func_800FE6BC_ShellGame(omObjData* obj) {
    SGStageWork* w;

    obj->func_ptr = &func_800FE7AC_ShellGame;
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 5.0f;
    obj->model[0] = func_800174C0(0x170004, 0xDD);
    obj->unk_50 = w = func_80023684(sizeof(SGStageWork), 0x7918);
    func_8009B770(w, 0, sizeof(SGStageWork));
    w->unk4 = 1;
    w->unk5 = 0;
    func_80009028(obj, 0, -720.0f, -720.0f, 720.0f, 720.0f);
    func_80008FC4(obj, 20.0f);
    func_80008FB8(obj, 1.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/FD460", func_800FE6BC_ShellGame);
#endif
void func_800FE7AC_ShellGame(omObjData* arg0) {
}

void func_800FE7B4_ShellGame(omObjData* obj) {
    f32 a;

    if (obj->trans.x * obj->trans.x + obj->trans.z * obj->trans.z > 129600.0) {
        a = func_800F7398_ShellGame(obj->trans.x, obj->trans.z);
        obj->trans.x = func_800AEAC0(a) * 360.0;
        obj->trans.z = func_800AEFD0(a) * 360.0;
    }
    D_800FFA10_ShellGame[obj->work[0]].unk20 = 0;
}
// NON_MATCHING: shared return tail
#ifdef NON_MATCHING
s32 func_800FE87C_ShellGame(omObjData* obj, omObjData* other) {
    SGPlayerWork* w;
    SGShellWork* ow;
    f32 dx;
    f32 dz;
    f32 d;
    f32 a;
    f32 x;
    f32 z;
    f32 vz;

    w = obj->unk_50;
    if ((w->unk5C & 0x200) || ((w->unk5C & 0x20) && w->unk38 >= 0.0) || ((w->unk5C & 0x100) && w->unk38 >= 0.0)) {
        func_800184BC(obj, 6);
        w->unk38 = -1.2f;
        w->unk3C = func_800B0CD8(obj->trans.x, obj->trans.z);
        w->unk40 = 0;
        func_80017C0C(obj, 7, obj->trans.x, obj->trans.y, obj->trans.z, 0.0f, 0.0f);
        PlaySound(0x1E6);
        func_80060F04(w->unk58, 10, 0, 10);
        func_800FE010_ShellGame(other);
        D_800FEC44_ShellGame = other;
        D_800FF79C_ShellGame = w->unk3C;
    } else {
        if (D_800FF796_ShellGame != 0) {
            D_800FEC40_ShellGame = other;
        }
        ow = other->unk_50;
        dx = other->trans.x - obj->trans.x;
        dz = other->trans.z - obj->trans.z;
        d = sqrtf(dx * dx + dz * dz);
        a = func_800F7398_ShellGame(dx, dz);
        w->unk3C = w->unk3C;
        w->unk40 = 0;
        x = func_800AEAC0(a) * d + obj->trans.x;
        z = func_800AEFD0(a) * d + obj->trans.z;
        vz = func_800AEFD0(w->unk3C) * 60.0;
        func_80017C0C(obj, 7, x, obj->trans.y + ow->unk34, z, vz, func_800AEAC0(w->unk3C) * 60.0);
        PlaySound(0x1E6);
        func_80060F04(w->unk58, 2, 3, 10);
        func_800FE010_ShellGame(other);
        D_800FEC44_ShellGame = other;
        D_800FF79C_ShellGame = w->unk3C;
        func_800FDE08_ShellGame(obj, 0x21);
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_ShellGame/FD460", func_800FE87C_ShellGame);
#endif
void func_800FEB40_ShellGame(omObjData* obj) {
    SGPlayerWork* w;
    SGPlayerWork* ow;
    f32 a;

    if (D_800FEC40_ShellGame != NULL) {
        w = obj->unk_50;
        ow = D_800FEC40_ShellGame->unk_50;
        a = func_800F7398_ShellGame(obj->trans.x - D_800FEC40_ShellGame->trans.x,
                                    obj->trans.z - D_800FEC40_ShellGame->trans.z);
        obj->trans.x = D_800FEC40_ShellGame->trans.x + func_800AEAC0(a) * (w->unk48 + ow->unk48);
        obj->trans.z = D_800FEC40_ShellGame->trans.z + func_800AEFD0(a) * (w->unk48 + ow->unk48);
        D_800FEC40_ShellGame = NULL;
    }
}
