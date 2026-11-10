#include "common.h"
#include "DesertDash.h"

/* .data (0x800FC000..0x800FC030) */
s32 D_800FC000_DesertDash = 0;
s32 D_800FC004_DesertDash = 1;
s32 D_800FC008_DesertDash = 0;
s32 D_800FC00C_DesertDash = 1;
s32 D_800FC010_DesertDash = 0; /* unreferenced */
s32 D_800FC014_DesertDash = 210;
s32 D_800FC018_DesertDash = 9000;
s32 D_800FC01C_DesertDash = 0;
u8 D_800FC020_DesertDash = 0;

void func_800F65E0_DesertDash(void) {
    s16 i;
    s16 j;
    s32 slot;

    func_80029090(0x32);
    func_8002ADF0(&D_800EDEC0, 0x40);
    func_8001DE70(0x20);
    omInitObjMan(0x32, 0);
    func_80060088();
    D_800FC2FC_DesertDash = omAddObj(0x7FDA, 0, 0, -1, omOutViewMulti);
    omSetStatBit(D_800FC2FC_DesertDash, 0xA0);
    D_800FC2FC_DesertDash->work[0] = 2;
    func_80017940(2);
    func_800179C0(2);
    func_80017660(0, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80017660(1, 320.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(1, 640.0f, 480.0f, 511.0f, 960.0f, 480.0f, 511.0f);
    func_8001D494(0, 45.0f, 80.0f, 8000.0f);
    func_8001D494(1, 45.0f, 80.0f, 8000.0f);
    D_800FC3B0_DesertDash = 0;
    D_800FC3B2_DesertDash = 3600;
    D_800ED430 = 1;
    D_800FC3D4_DesertDash = _CheckFlag(0x2B);
    D_800FC3D0_DesertDash = 0;
    for (i = 0; i < 4; i++) {
        D_800FC308_DesertDash[i] = 0;
    }
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    func_800090B8(0);
    D_800FC2F8_DesertDash = omAddObj(1, 0, 0, -1, func_800F6A9C_DesertDash);
    D_800F2AF8[D_800ED440++] = omAddObj(2, 0, 0, -1, func_800F9A80_DesertDash);
    omAddObj(2, 0, 0, -1, func_800F6B38_DesertDash);
    D_800F3FB0[D_800F2BC0++] = omAddObj(3, 10, 60, -1, func_800F6E34_DesertDash);
    D_800F3FB0[D_800F2BC0++] = omAddObj(3, 10, 60, -1, func_800F6E68_DesertDash);
    D_800F3FB0[D_800F2BC0++] = omAddObj(3, 10, 60, -1, func_800F6E9C_DesertDash);
    D_800F3FB0[D_800F2BC0++] = omAddObj(3, 10, 60, -1, func_800F6ED0_DesertDash);
    for (i = 0; i < 4; i++) {
        D_800FC3C0_DesertDash[i] = -1;
    }
    for (i = 0; i < 4; i++) {
        slot = GwPlayer[i].group * 2 + (rand8() & 1);
        for (j = 0; j < 4; j++) {
            if (D_800FC3C0_DesertDash[j] == slot) {
                slot ^= 1;
            }
        }
        D_800FC3C0_DesertDash[i] = slot;
    }
    SetFadeInTypeAndTime(0, 0x10);
}

void func_800F6A9C_DesertDash(omObjData* obj) {
    obj->func_ptr = func_800F7430_DesertDash;
    func_800F94F8_DesertDash(0, 415.0f, 0.0f, 500.0f, -6900.0f, 17.25f, 0.0f, 0.0f);
    func_800F94F8_DesertDash(1, 415.0f, 0.0f, 500.0f, -6900.0f, 17.25f, 0.0f, 0.0f);
}

void func_800F6B38_DesertDash(omObjData* obj) {
    u8 files[2];
    s32 anim0;
    s32 anim1;
    s32 i;
    void* data;
    DDTeam* team;

    files[0] = 7;
    files[1] = 8;
    obj->func_ptr = func_800F7C6C_DesertDash;
    data = DataRead(0x3B000D);
    anim0 = (s16)func_800678A4(data);
    DataClose(data);
    D_800FC3B4_DesertDash = func_80064EF4(2, 0);
    data = DataRead(0x3B000F);
    anim1 = (s16)func_800678A4(data);
    DataClose(data);
    D_800FC3B8_DesertDash = func_80064EF4(2, 0);
    for (i = 0; i < 2; i++) {
        team = &D_800FC318_DesertDash[i];
        team->unk14 = 0;
        team->unk18 = 0;
        team->unk8 = 0;
        team->unkE = func_800174C0(files[i] | 0x3B0000, 0x2D9);
        team->unk10 = func_80023FC8(team->unkE);
        team->unk12 = func_800174F4(0x3B0009, 0x2D9);
        func_80067208((s16)D_800FC3B4_DesertDash, i, anim0, 0);
        func_800672B0((s16)D_800FC3B4_DesertDash, i, 0);
        func_800674BC((s16)D_800FC3B4_DesertDash, i, 0x9800);
        func_80067208((s16)D_800FC3B8_DesertDash, i, anim1, 0);
        func_800672B0((s16)D_800FC3B8_DesertDash, i, 0);
        func_800674BC((s16)D_800FC3B8_DesertDash, i, 0x9000);
        func_80067558((s16)D_800FC3B8_DesertDash, (s16)i, 200, 0, 0, 0x100);
        func_80067354((s16)D_800FC3B8_DesertDash, i, 1.2f, 1.2f);
    }
    func_80025798(D_800FC318_DesertDash[0].unkE, -75.0f, 0.0f, 75.0f);
    func_80025798(D_800FC318_DesertDash[0].unk10, -125.0f, 0.0f, 75.0f);
    func_80025798(D_800FC318_DesertDash[1].unkE, 125.0f, 0.0f, 75.0f);
    func_80025798(D_800FC318_DesertDash[1].unk10, 75.0f, 0.0f, 75.0f);
    func_80025798(D_800FC318_DesertDash[0].unk12, -100.0f, 16.0f, 0.0f);
    func_800257E4(D_800FC318_DesertDash[0].unk12, 0.0f, 180.0f, 0.0f);
    func_80025798(D_800FC318_DesertDash[1].unk12, 100.0f, 16.0f, 0.0f);
    func_800257E4(D_800FC318_DesertDash[1].unk12, 0.0f, 180.0f, 0.0f);
}

void func_800F6E00_DesertDash(omObjData* obj) {
    if (func_80072718() == 0) {
        func_800F9434_DesertDash();
        omOvlReturnEx(1);
    }
}

void func_800F6E34_DesertDash(omObjData* obj) {
    func_800F6F04_DesertDash(obj, 0);
    func_800F707C_DesertDash(obj, 0);
}

void func_800F6E68_DesertDash(omObjData* obj) {
    func_800F6F04_DesertDash(obj, 1);
    func_800F707C_DesertDash(obj, 1);
}

void func_800F6E9C_DesertDash(omObjData* obj) {
    func_800F6F04_DesertDash(obj, 2);
    func_800F707C_DesertDash(obj, 2);
}

void func_800F6ED0_DesertDash(omObjData* obj) {
    func_800F6F04_DesertDash(obj, 3);
    func_800F707C_DesertDash(obj, 3);
}

/* Puts the player into its team slot (D_800FC3C0) and at its start position. */
void func_800F6F04_DesertDash(omObjData* obj, s32 player) {
    s32 member;
    s32 t;
    DDTeam* team;

    member = D_800FC3C0_DesertDash[player];
    t = member >> 1;
    member &= 1;
    team = &D_800FC318_DesertDash[t];
    func_800F9450_DesertDash(obj, team);
    team->obj[member] = obj;
    D_800FC318_DesertDash[t].player[member] = player;
    D_800FC318_DesertDash[t].unkB[member] = (u8)D_800C59A8[GwPlayer[player].character].index;
    switch (D_800FC3C0_DesertDash[player]) {
        case 0:
            func_800093FC(obj, -100.0f, 0.0f, 0.0f);
            break;
        case 1:
            func_800093FC(obj, -100.0f, 0.0f, 150.0f);
            break;
        case 2:
            func_800093FC(obj, 100.0f, 0.0f, 0.0f);
            break;
        case 3:
            func_800093FC(obj, 100.0f, 0.0f, 150.0f);
            break;
    }
}

void func_800F707C_DesertDash(omObjData* obj, s32 player) {
    s32 idle[5] = { 0x0F, 0x38, 0x39, 0x3A, 0x3B };
    s32 win[5] = { 0x10, 0x3C, 0x3D, 0x3E, 0x3F };
    s32 dir;
    s32 file0;
    s32 file1;
    u8 chr;
    DDPlayerWork* work;

    chr = GwPlayer[player].character;
    dir = D_800C59AC[chr].unk_00;
    file0 = D_800C59AC[chr].unk_04;
    file1 = D_800C59AC[chr].unk_08;
    obj->model[0] = LoadFormFile(dir | file0, 0x2D9);
    func_80025F10(obj->model[0], 1);
    obj->func_ptr = func_800F8C34_DesertDash;
    obj->rot.x = 0.0f;
    obj->rot.y = 180.0f;
    obj->rot.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80025830(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    obj->unk_50 = func_80023684(sizeof(DDPlayerWork), 0x7918);
    func_8009B770(obj->unk_50, 0, sizeof(DDPlayerWork));
    work = obj->unk_50;
    work->unk_D8 = func_80023684(obj->mtncnt * sizeof(DDPlayerWork), 0x7918);
    func_8009B770(work->unk_D8, 0, obj->mtncnt * sizeof(DDPlayerWork));
    work->unk_56 = GwPlayer[player].port;
    work->unk_58 = player;
    work->unk_C0 = 0xFFFF;
    obj->model[3] = LoadFormFile(0x19, 0x68D);
    obj->model[4] = LoadFormFile(0x1A, 0x68D);
    obj->model[7] = LoadFormFile(0x1E, 0x68D);
    obj->model[8] = LoadFormFile(0x1D, 0x68D);
    func_80025830(obj->model[8], 1.0f, 1.0f, 2.0f);
    func_8001874C(obj, 0, dir, 1, 0);
    func_8001874C(obj, 1, dir | 0x5A, 0, 0);
    func_8001874C(obj, 2, dir | 0x5B, 0, 0);
    func_8001874C(obj, 5, dir | 0xA, 1, 0x27);
    func_8001874C(obj, 6, dir | 0x1E, 1, 0x27);
    func_8001874C(obj, 7, dir | 0x68, 2, 0);
    func_8001874C(obj, 8, dir | 0x69, 2, 0);
    func_8001874C(obj, 3, dir | idle[rand8() & 1], 1, 0x78);
    func_8001874C(obj, 4, dir | win[0], 1, 0x78);
    func_80008EF0(obj, 9, dir | file1, 0x2D9, 623.33f);
    func_800184BC(obj, 0);
}

void func_800F7430_DesertDash(omObjData* obj) {
    s32 i;
    s32 w;
    f32 fw;
    DDTeam* team;

    D_800FC300_DesertDash = (D_800FC300_DesertDash + 1) % 3;
    if (D_800F5144 == 1) {
        obj->func_ptr = func_800F6E00_DesertDash;
        func_80060198();
    }
    switch (D_800FC000_DesertDash) {
        case 0:
            func_800FAD98_DesertDash(0, CenterM[0].z);
            func_800FAD98_DesertDash(1, CenterM[1].z);
            func_800F9C9C_DesertDash(320);
            if (func_80072718() != 0) {
                return;
            }
            if (D_800FC008_DesertDash == 20) {
                func_80060128(0x22);
            }
            if (D_800FC008_DesertDash == 0) {
                func_800F95E8_DesertDash(0, 415.0f, 0.0f, 300.0f, -2250.0f, 0.0f, 0.0f, 0.0f, 60);
                func_800F95E8_DesertDash(1, 415.0f, 0.0f, 300.0f, -2250.0f, 0.0f, 0.0f, 0.0f, 60);
            } else if (D_800FC008_DesertDash == 59) {
                func_800F95E8_DesertDash(0, 830.0f, -100.0f, 280.0f, 0.0f, -17.25f, 0.0f, 0.0f, 20);
                func_800F95E8_DesertDash(1, 830.0f, 100.0f, 280.0f, 0.0f, -17.25f, 0.0f, 0.0f, 20);
                D_800FC000_DesertDash = 1;
                D_800FC008_DesertDash = 19;
                for (i = 0; i < D_800F2BC0; i++) {
                    func_80025F10(D_800F3FB0[i]->model[0], 3);
                }
            }
            D_800FC008_DesertDash++;
            break;
        case 1:
            func_800FAD98_DesertDash(0, CenterM[0].z);
            func_800FAD98_DesertDash(1, CenterM[1].z);
            if (D_800FC008_DesertDash == 0) {
                D_800FC000_DesertDash = 2;
                break;
            }
            w = (D_800FC008_DesertDash - 1) * 160.0 / 20.0 + 160.0;
            fw = w;
            func_80017660(0, 0.0f, 0.0f, fw, 240.0f);
            func_800176C4(0, 640.0f, 480.0f, 511.0f, w * 2, 480.0f, 511.0f);
            func_80017660(1, fw, 0.0f, 320.0f, 240.0f);
            func_800F9C9C_DesertDash(w);
            D_800FC008_DesertDash--;
            break;
        case 2:
            if (D_800FC008_DesertDash == 0) {
                GMesCreate(0);
                D_800FC008_DesertDash = -1;
            } else if (GMesStatAllGet() == 0) {
                D_800FC000_DesertDash = 3;
            }
            break;
        case 3:
            if (--D_800FC018_DesertDash == 0) {
                D_800FC000_DesertDash = 4;
            }
            break;
        case 4:
            if (D_800FC3D0_DesertDash == 0) {
                func_800601D4(60);
                GMesCreate(0x11);
                D_800FC3D0_DesertDash++;
                D_800FC014_DesertDash = 90;
            } else if (GMesStatAllGet() & 2) {
                D_800FC000_DesertDash = 7;
                func_80060128(0x34);
            }
            break;
        case 5:
            if (D_800FC3D0_DesertDash == 0) {
                func_800601D4(60);
                if (D_800FC3D4_DesertDash == 0) {
                    GMesCreate(0x12);
                } else {
                    GMesCreate(2);
                }
                for (i = 0; i < 2; i++) {
                    team = &D_800FC318_DesertDash[i];
                    if (team->unk14 == 11) {
                        GwPlayer[team->player[0]].coins_mg += 10;
                        GwPlayer[team->player[1]].coins_mg += 10;
                    } else {
                        if (GwPlayer[team->player[0]].coins >= 10) {
                            GwPlayer[team->player[0]].coins_mg -= 10;
                        } else {
                            GwPlayer[team->player[0]].coins_mg -= GwPlayer[team->player[0]].coins;
                        }
                        if (GwPlayer[team->player[1]].coins >= 10) {
                            GwPlayer[team->player[1]].coins_mg -= 10;
                        } else {
                            GwPlayer[team->player[1]].coins_mg -= GwPlayer[team->player[1]].coins;
                        }
                    }
                }
                D_800FC3D0_DesertDash++;
                D_800FC014_DesertDash = 105;
            } else if ((GMesStatAllGet() & 2) && D_800FC3D4_DesertDash == 0) {
                D_800FC000_DesertDash = 6;
                func_80060128(0x36);
            }
            if (D_800FC3D4_DesertDash != 0) {
                if (++D_800FC3D0_DesertDash >= 60) {
                    D_800FC000_DesertDash = 8;
                }
            }
            break;
        case 6:
            if (D_800FC3D0_DesertDash == 8) {
                D_800FC000_DesertDash = 7;
            }
            D_800FC3D0_DesertDash++;
            break;
        case 7:
            for (i = 0; i < 4; i++) {
                if (ContBtnTrg[GwPlayer[i].port] & 0x9000) {
                    D_800FC01C_DesertDash = 1;
                }
            }
            if (D_800FC01C_DesertDash != 0) {
                D_800FC014_DesertDash = 60;
            }
            if (++D_800FC3D0_DesertDash >= D_800FC014_DesertDash) {
                D_800FC000_DesertDash = 8;
            }
            break;
        case 8:
            func_800726AC(0, 20);
            func_80060398(D_800FC3D4_DesertDash != 0 ? 40 : 90);
            D_800FC3B0_DesertDash = -1;
            obj->func_ptr = func_800F6E00_DesertDash;
            break;
    }
    D_800FC00C_DesertDash = func_800F983C_DesertDash(obj, 2);
}

// register allocation only (masked 2: fabsf operand and a pointer temp)
#ifdef NON_MATCHING
/* Per-frame driver of both teams' sleds, cameras and sprites. */
void func_800F7C6C_DesertDash(omObjData* obj) {
    s32 i;
    s32 prev;
    f32 z;
    f32 d;
    f32 v;
    DDTeam* team;
    unk65770Obj* spr;
    omObjData* o;

    if (D_800FC000_DesertDash < 3) {
        return;
    }
    for (i = 0; i < 2; i++) {
        team = &D_800FC318_DesertDash[i];
        prev = team->unk14;
        z = (team->obj[0]->trans.z + team->obj[1]->trans.z) * 0.5;
        team->unk28 = z;
        switch (team->unk14) {
            case 0:
                team->unk14 = 1;
                func_80067480((s16)D_800FC3B4_DesertDash, (s16)i, 0x8000);
                func_800671DC((s16)D_800FC3B4_DesertDash, (s16)i, 0);
                D_800FC2E0_DesertDash[i] = 80;
                if (i != 0) {
                    func_80060540(0x2E7, i);
                } else {
                    func_80060540(0x2E6, i);
                }
                break;
            case 1:
                if (team->unk8 == 3) {
                    func_800F949C_DesertDash(team->obj[0], 1, 3.0f);
                    func_800F949C_DesertDash(team->obj[1], 1, 3.0f);
                    team->unk14 = 3;
                    if (i != 0) {
                        D_800FC2E8_DesertDash[i] = func_80060540(0x2ED, i);
                    } else {
                        D_800FC2E8_DesertDash[i] = func_80060540(0x2EC, i);
                    }
                } else if (team->unk1A >= 9) {
                    team->unk14 = 7;
                } else if (team->unk8 != 0) {
                    team->unk1A++;
                }
                break;
            case 3:
                D_800F2B7C[team->unkE].unk_2C = z + (0.14 - team->unk18 * 0.03) * 100.0;
                D_800F2B7C[team->unk10].unk_2C = z + (team->unk18 * 0.03 + -0.14) * 100.0;
                if (team->unk1A == 0) {
                    if (team->unk8 == 3) {
                        team->unk14 = 4;
                        func_800671DC((s16)D_800FC3B4_DesertDash, (s16)i, 1);
                        D_800FC2E0_DesertDash[i] = -80;
                        if (i != 0) {
                            func_80060540(0x2E7, i);
                        } else {
                            func_80060540(0x2E6, i);
                        }
                    }
                } else {
                    team->unk14 = 7;
                    func_8006071C((s16)D_800FC2E8_DesertDash[i]);
                }
                break;
            case 4:
                if (team->unk8 == 3) {
                    func_800F949C_DesertDash(team->obj[0], 2, 3.0f);
                    func_800F949C_DesertDash(team->obj[1], 2, 3.0f);
                    team->unk14 = 6;
                    if (i != 0) {
                        D_800FC2E8_DesertDash[i] = func_80060540(0x2F0, i);
                    } else {
                        D_800FC2E8_DesertDash[i] = func_80060540(0x2EF, i);
                    }
                } else if (team->unk1A >= 9) {
                    team->unk14 = 7;
                } else if (team->unk8 != 0) {
                    team->unk1A++;
                }
                break;
            case 6:
                D_800F2B7C[team->unkE].unk_2C = z + (team->unk18 * 0.03 + -0.14) * 100.0;
                D_800F2B7C[team->unk10].unk_2C = z + (0.14 - team->unk18 * 0.03) * 100.0;
                if (team->unk1A != 0) {
                    team->unk14 = 7;
                    func_8006071C((s16)D_800FC2E8_DesertDash[i]);
                } else if (team->unk8 == 3) {
                    team->unk14 = 1;
                    func_800671DC((s16)D_800FC3B4_DesertDash, (s16)i, 0);
                    D_800FC2E0_DesertDash[i] = 80;
                    if (i != 0) {
                        func_80060540(0x2E7, i);
                    } else {
                        func_80060540(0x2E6, i);
                    }
                }
                break;
            case 7:
                if (team->unk18 == 0) {
                    func_800F949C_DesertDash(team->obj[0], 6, 2.0f);
                    func_800F949C_DesertDash(team->obj[1], 6, 2.0f);
                    func_80060540(0x157, i);
                    func_80067480((s16)D_800FC3B8_DesertDash, (s16)i, 0x8000);
                    if (i != 0) {
                        func_80060540(0x2F5, i);
                    } else {
                        func_80060540(0x2F4, i);
                    }
                    D_800F2B7C[team->unkE].unk_2C = D_800F2B7C[team->unk10].unk_2C = z;
                    D_800FC2F0_DesertDash[0] = func_80060618(0x45F, team->player[0]);
                    D_800FC2F0_DesertDash[1] = func_80060618(0x45F, team->player[1]);
                    if (i != 0) {
                        func_800607C4((s16)D_800FC2F0_DesertDash[0], 0x50);
                        func_800607C4((s16)D_800FC2F0_DesertDash[1], 0x60);
                    } else {
                        func_800607C4((s16)D_800FC2F0_DesertDash[0], 0x20);
                        func_800607C4((s16)D_800FC2F0_DesertDash[1], 0x30);
                    }
                    func_80060F04(team->player[0], 20, 0, 20);
                    func_80060F04(team->player[1], 20, 0, 20);
                }
                if (team->unk18 < 8) {
                    func_800671DC((s16)D_800FC3B8_DesertDash, (s16)i, team->unk18);
                }
                if (team->unk8 == 3) {
                    func_800674BC((s16)D_800FC3B4_DesertDash, (s16)i, 0x8000);
                    func_800674BC((s16)D_800FC3B8_DesertDash, (s16)i, 0x8000);
                    func_800671DC((s16)D_800FC3B8_DesertDash, (s16)i, 0);
                    team->unk14 = 8;
                }
                break;
            case 8:
                if (team->unk8 == 3) {
                    team->unk14 = 0;
                }
                break;
            case 9:
                D_800F2B7C[team->unkE].unk_2C = z;
                D_800F2B7C[team->unk10].unk_2C = z;
                if (team->unk18 == 0) {
                    func_800184BC(team->obj[0], 0);
                    func_800184BC(team->obj[1], 0);
                    func_800674BC((s16)D_800FC3B4_DesertDash, (s16)i, 0x8000);
                    func_800674BC((s16)D_800FC3B8_DesertDash, (s16)i, 0x8000);
                    func_80060F04(team->player[0], 2, 2, 20);
                    func_80060F04(team->player[1], 2, 2, 20);
                    D_800FC2F0_DesertDash[0] = func_80060618(0x45F, team->player[0]);
                    D_800FC2F0_DesertDash[1] = func_80060618(0x45F, team->player[1]);
                    if (i != 0) {
                        func_800607C4((s16)D_800FC2F0_DesertDash[0], 0x50);
                        func_800607C4((s16)D_800FC2F0_DesertDash[1], 0x60);
                    } else {
                        func_800607C4((s16)D_800FC2F0_DesertDash[0], 0x20);
                        func_800607C4((s16)D_800FC2F0_DesertDash[1], 0x30);
                    }
                } else if (team->unk18 >= 67) {
                    team->unk14 = 10;
                    if (i != 0) {
                        func_80060540(0x2F8, i);
                    } else {
                        func_80060540(0x2F7, i);
                    }
                }
                D_800F2B7C[team->obj[0]->model[0]].unk_4C = 0.0f;
                D_800F2B7C[team->obj[1]->model[0]].unk_4C = 0.0f;
                break;
            case 10:
                team->unk1A += 2;
                if (team->unk8 == 3) {
                    D_800F2B7C[team->obj[0]->model[0]].unk_4C = 1.0f;
                    D_800F2B7C[team->obj[1]->model[0]].unk_4C = 1.0f;
                    team->unk14 = 0;
                }
                break;
            case 11:
                switch (D_800FC000_DesertDash) {
                    case 6:
                        if (team->unk18 == 0) {
                            func_800F95E8_DesertDash(i, 622.5f, (i * 2 - 1) * 100.0, 177.5f, z, -27.6f, 0.0f, 0.0f, 6);
                            func_800FAE1C_DesertDash(i, 6.0f);
                        } else if (team->unk18 == 6) {
                            func_800F95E8_DesertDash(i, 415.0f, (i * 2 - 1) * 100.0, 75.0f, z, -27.6f,
                                                     (i * 2 - 1) * 210.0, 0.0f, 20);
                        }
                        team->unk18++;
                        break;
                    case 7:
                        o = team->obj[0];
                        o->rot.y = v = -((i * 2 - 1) * 150);
                        team->obj[1]->rot.y = v;
                        break;
                }
            case 12:
                func_800674BC((s16)D_800FC3B4_DesertDash, (s16)i, 0x8000);
                func_800674BC((s16)D_800FC3B8_DesertDash, (s16)i, 0x8000);
                break;
        }
        if (D_800FC000_DesertDash >= 5) {
            if (((team->unk14 != 11) & (team->unk14 != 9)) && team->unk14 != 10) {
                team->unk14 = 12;
            }
        }
        if (D_800FC000_DesertDash == 3) {
            team->unk18++;
            if (func_800FAD98_DesertDash(i, team->obj[0]->trans.z) != 0) {
                team->unk14 = 11;
                D_800FC020_DesertDash |= 1 << i;
            }
            if (D_800FC000_DesertDash == 4) {
                team->unk14 = 12;
            }
            team->unk16 = func_800F8A80_DesertDash(team->obj[0]->trans.z);
            if (team->unk16 == 3) {
                team->unk14 = 9;
            }
            func_80025798(team->unk12, team->obj[0]->trans.x, 16.0f, team->obj[0]->trans.z);
            if (prev != team->unk14) {
                team->unk8 = 0;
                team->unk1A = 0;
                team->unk18 = 0;
                team->unk1C = (rand8() & 7) + 4;
            }
            func_800F95E8_DesertDash(i, 830.0f, (i * 2 - 1) * 100.0, 280.0f, team->obj[0]->trans.z, -17.25f,
                                     0.0f, 0.0f, 1);
            func_80066DF4((s16)D_800FC3B4_DesertDash, (s16)i, (s16)i, D_800FC2E0_DesertDash[i] + team->obj[0]->trans.x,
                          team->obj[0]->trans.y + 160.0, team->obj[0]->trans.z);
            spr = func_800675F4((s16)D_800FC3B4_DesertDash, (s16)i);
            func_80066DC4((s16)D_800FC3B8_DesertDash, (s16)i, spr->unk4, spr->unk6);
        }
    }
    v = D_800FC318_DesertDash[0].unk28 - D_800FC318_DesertDash[1].unk28;
    d = fabsf(v);
    if (d < 300.0) {
        D_800FC318_DesertDash[0].unk34 = 1.0f;
        D_800FC318_DesertDash[1].unk34 = 1.0f;
    } else if (d < 800.0) {
        if (D_800FC318_DesertDash[0].unk28 - D_800FC318_DesertDash[1].unk28 > 0.0f) {
            D_800FC318_DesertDash[0].unk34 = d / 100.0 * 0.1 + 0.8;
            D_800FC318_DesertDash[1].unk34 = 1.0f;
        } else {
            D_800FC318_DesertDash[0].unk34 = 1.0f;
            D_800FC318_DesertDash[1].unk34 = d / 100.0 * 0.1 + 0.8;
        }
    } else if (D_800FC318_DesertDash[0].unk28 - D_800FC318_DesertDash[1].unk28 > 0.0f) {
        D_800FC318_DesertDash[0].unk34 = 1.6f;
        D_800FC318_DesertDash[1].unk34 = 1.0f;
    } else {
        D_800FC318_DesertDash[0].unk34 = 1.0f;
        D_800FC318_DesertDash[1].unk34 = 1.6f;
    }
    if (D_800FC020_DesertDash != 0) {
        if (D_800FC020_DesertDash == 3) {
            D_800FC318_DesertDash[rand8() & 1].unk14 = 12;
        }
        D_800FC000_DesertDash = 5;
        D_800FC020_DesertDash = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_DesertDash/1D3990", func_800F7C6C_DesertDash);
#endif

// branch layout only (case 0 test: bc1f/j where retail has bc1tl/j; masked 19); tried if (!(..)) break;
#ifdef NON_MATCHING
/* What lies ahead of z: 0 nothing, 1 an obstacle to wait for, 2 jump now, 3 hit; -1 unknown. */
u16 func_800F8A80_DesertDash(f32 z) {
    s32 i;
    DDObstacle* o;

    i = 0;
    o = NULL;
    for (; i < D_800FC004_DesertDash; i++) {
        o = &D_800FC670_DesertDash[i];
        if (o->unk14 - z >= -290.0 && o->unk14 - z <= 200.0) {
            break;
        }
    }
    if (i == D_800FC004_DesertDash) {
        return 0;
    }
    switch (o->unk4) {
        case 0:
            if (o->unk10 >= 150.0) {
                return 1;
            }
            break;
        case 1:
            if (!(o->unk14 - z >= -114.99999999999999)) {
                return 1;
            }
            if (o->unk10 >= 150.0) {
                return 1;
            }
            return 3;
        case 2:
            break;
        case 3:
            return 1;
        default:
            return -1;
    }
    if (o->unk14 - z >= -135.0 && o->unk14 - z <= 0.0) {
        return 2;
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_DesertDash/1D3990", func_800F8A80_DesertDash);
#endif

// register allocation only (s0..s3 permuted; masked 0)
#ifdef NON_MATCHING
/* A player's per-frame update: pull input (stick pushes and shakes) and squash-and-stretch. */
void func_800F8C34_DesertDash(omObjData* obj) {
    Vec pos; /* written, never read */
    s16 stkX;
    s16 stkY;
    f32 x;
    f32 y;
    f32 z;
    DDTeam* team;
    s32 m;
    DDPlayerWork* work;
    s8 port;
    f32 f;
    s32 sy;

    stkX = 0;
    stkY = 0;
    work = obj->unk_50;
    m = 0;
    team = func_800F9470_DesertDash(obj);
    if (team->obj[0] != obj && team->obj[1] == obj) {
        m = 1;
    }
    port = work->unk_56;
    if (D_800FC000_DesertDash == 3) {
        stkX = ContStkX[port];
        stkY = ContStkY[port];
        if (GwPlayer[work->unk_58].flags & 1) {
            func_800F91C8_DesertDash(obj, &stkX, &stkY);
        }
    } else {
        stkX = 0;
        stkY = 0;
    }
    func_80017A50(obj);
    x = obj->trans.x;
    pos.x = x;
    y = obj->trans.y;
    pos.y = y;
    z = obj->trans.z;
    pos.z = z;
    switch (team->unk14) {
        case 0:
            break;
        case 1:
            if (stkX >= 30) {
                goto push;
            }
            goto shake;
        case 4:
            if (stkX < -29) {
                goto push;
            }
        shake:
            sy = stkY;
            if (sy < 0) {
                sy = -sy;
            }
            if (sy >= 50) {
                team->unk1A += 9;
            }
            break;
        case 3:
        case 6:
            if (team->unk16 != 2 && D_800FC000_DesertDash == 3) {
                z -= team->unk34 * 16.0;
            }
            if (work->unk_C0 != 0xFFFF) {
                break;
            }
            goto push;
        case 7:
            if (team->unk18 == 10) {
                if (m == 0) {
                    func_80017C0C(obj, 8, x, y, z + 75.0, 0.0f, 0.0f);
                }
                break;
            }
            if (team->unk18 < 30) {
                break;
            }
            func_800258EC(obj->model[8], 4, 4);
            func_800F949C_DesertDash(obj, 8, 2.0f);
            goto push;
        case 8:
            if (work->unk_C0 != 0xFFFF) {
                break;
            }
            func_800F949C_DesertDash(obj, 0, 1.0f);
            goto push;
        case 9:
            if (team->unk16 != 0) {
                z -= 5.0;
            }
            obj->scale.y = 0.2f;
            obj->scale.x = obj->scale.z = 1.6f;
            break;
        case 10:
            if (team->unk1A < 11) {
                f = team->unk1A;
                obj->scale.y = f * 0.05f + 0.2;
                obj->scale.z = obj->scale.x = 1.8 - f * 0.08f;
            } else if (team->unk1A < 21) {
                f = team->unk1A - 10;
                obj->scale.y = 0.9 - f * 0.05f;
                obj->scale.z = obj->scale.x = f * 0.05f + 1.0;
            } else if (team->unk1A < 31) {
                f = team->unk1A - 20;
                obj->scale.y = f * 0.05f + 0.7;
                obj->scale.z = obj->scale.x = 1.4 - f * 0.04f;
            } else if (team->unk1A < 39) {
                f = team->unk1A - 30;
                obj->scale.y = 1.3 - f * 0.1f;
                obj->scale.z = obj->scale.x = f * 0.02f + 1.0;
            } else if (team->unk1A < 47) {
                f = team->unk1A - 38;
                obj->scale.y = f * 0.1f + 0.3;
                obj->scale.z = obj->scale.x = 1.1 - f * 0.01f;
            } else {
                func_800F949C_DesertDash(obj, 0, 1.0f);
            push:
                team->unk8 |= 1 << m;
            }
            break;
        case 11:
            if (D_800FC000_DesertDash == 6) {
                func_800F949C_DesertDash(obj, 3, 1.0f);
                break;
            }
            goto idle;
        case 12:
            if (D_800FC000_DesertDash == 6) {
                func_800F949C_DesertDash(obj, 4, 1.0f);
                break;
            }
        idle:
            if (D_800FC000_DesertDash < 6) {
                func_800F949C_DesertDash(obj, 0, 1.0f);
            }
            break;
    }
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = z;
    func_80017DB0(obj);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_DesertDash/1D3990", func_800F8C34_DesertDash);
#endif

/* CPU input: push the stick when the partner does (human) or at random (CPU partner). */
void func_800F91C8_DesertDash(omObjData* obj, s16* stkX, s16* stkY) {
    u16 x;
    s32 m;
    u16 push;
    DDTeam* team;
    s32 diff;

    x = 0;
    m = 0;
    push = 0;
    team = func_800F9470_DesertDash(obj);
    if (team->obj[0] == obj) {
        m = 0;
    } else if (team->obj[1] == obj) {
        m = 1;
    }
    diff = GwPlayer[team->player[m]].cpu_difficulty;
    func_80017A60(obj);
    if (team->unk14 == 1) {
        push = 60;
    } else if (team->unk14 == 4) {
        push = -60;
    }
    switch (team->unk16) {
        case 0:
            if (!(GwPlayer[team->player[m ^ 1]].flags & 1)) {
                goto human;
            }
            if ((rand8() % (6 - diff)) == 0) {
                x = push;
            }
            break;
        case 1:
            if (!(GwPlayer[team->player[m ^ 1]].flags & 1)) {
                goto human;
            }
            if ((team->unk18 & 1) && (rand8() % (4 - diff)) == 0) {
                x = push;
            }
            break;
        case 2:
            if (!(GwPlayer[team->player[m ^ 1]].flags & 1)) {
            human:
                if (team->unk8 != 0) {
                    x = push;
                }
            }
            break;
    }
    *stkX = x;
    *stkY = 0;
}

void func_800F9434_DesertDash(void) {
    func_800F9C68_DesertDash();
}

/* The player object keeps its team in work[0..3]: the pointer, big-endian, on the N64; the host
   keeps the team index there (a pointer does not fit). */
void func_800F9450_DesertDash(omObjData* obj, DDTeam* team) {
    obj->work[0] = (u32)team >> 24;
    obj->work[1] = (u32)team >> 16;
    obj->work[2] = (u32)team >> 8;
    obj->work[3] = (u32)team;
}

DDTeam* func_800F9470_DesertDash(omObjData* obj) {
    return (DDTeam*)((obj->work[0] << 24) | (obj->work[1] << 16) | (obj->work[2] << 8) | obj->work[3]);
}

void func_800F949C_DesertDash(omObjData* obj, s32 motion, f32 speed) {
    unk_ovl_2D_struct* m;

    func_800184BC(obj, motion);
    m = &D_800F2B7C[obj->model[0]];
    m->unk_4C = speed;
}

void func_800F94F8_DesertDash(s32 cam, f32 zoom, f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz) {
    D_800FC4C0_DesertDash[cam] = 0;
    D_800FC4B8_DesertDash[cam] = 0;
    CZoomM[cam] = zoom;
    CenterM[cam].x = cx;
    CenterM[cam].y = cy;
    CenterM[cam].z = cz;
    CRotM[cam].x = rx;
    CRotM[cam].y = ry;
    CRotM[cam].z = rz;
    D_800FC498_DesertDash[cam] = zoom;
    D_800FC3D8_DesertDash[cam].x = cx;
    D_800FC3D8_DesertDash[cam].y = cy;
    D_800FC3D8_DesertDash[cam].z = cz;
    D_800FC438_DesertDash[cam].x = rx;
    D_800FC438_DesertDash[cam].y = ry;
    D_800FC438_DesertDash[cam].z = rz;
}

void func_800F95E8_DesertDash(s32 cam, f32 zoom, f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz,
                              u16 frames) {
    D_800FC4A8_DesertDash[cam] = zoom;
    D_800FC408_DesertDash[cam].x = cx;
    D_800FC408_DesertDash[cam].y = cy;
    D_800FC408_DesertDash[cam].z = cz;
    D_800FC468_DesertDash[cam].x = rx;
    D_800FC468_DesertDash[cam].y = ry;
    D_800FC468_DesertDash[cam].z = rz;
    if (D_800FC4B8_DesertDash[cam] != 0) {
        func_800F9780_DesertDash(cam);
    }
    D_800FC4C0_DesertDash[cam] = frames;
    D_800FC4B8_DesertDash[cam] = frames;
}

void func_800F96C4_DesertDash(s32 cam) {
    D_800FC498_DesertDash[cam] = D_800FC4A8_DesertDash[cam];
    D_800FC438_DesertDash[cam].x = D_800FC468_DesertDash[cam].x;
    D_800FC438_DesertDash[cam].y = D_800FC468_DesertDash[cam].y;
    D_800FC438_DesertDash[cam].z = D_800FC468_DesertDash[cam].z;
    D_800FC3D8_DesertDash[cam].x = D_800FC408_DesertDash[cam].x;
    D_800FC3D8_DesertDash[cam].y = D_800FC408_DesertDash[cam].y;
    D_800FC3D8_DesertDash[cam].z = D_800FC408_DesertDash[cam].z;
}

void func_800F9780_DesertDash(s32 cam) {
    D_800FC498_DesertDash[cam] = CZoomM[cam];
    D_800FC438_DesertDash[cam].x = CRotM[cam].x;
    D_800FC438_DesertDash[cam].y = CRotM[cam].y;
    D_800FC438_DesertDash[cam].z = CRotM[cam].z;
    D_800FC3D8_DesertDash[cam].x = CenterM[cam].x;
    D_800FC3D8_DesertDash[cam].y = CenterM[cam].y;
    D_800FC3D8_DesertDash[cam].z = CenterM[cam].z;
}

/* Steps every camera tween; returns the last camera whose tween ran. */
s32 func_800F983C_DesertDash(omObjData* obj, s32 count) {
    s32 i;
    s32 last;
    f32 t;

    i = 0;
    last = 0;
    for (; i < count; i++) {
        if (D_800FC4B8_DesertDash[i] != 0) {
            last = i;
            if (--D_800FC4B8_DesertDash[i] == 0) {
                func_800F96C4_DesertDash(last);
            }
            t = (f32)(D_800FC4C0_DesertDash[i] - D_800FC4B8_DesertDash[i]) / D_800FC4C0_DesertDash[i];
            CZoomM[i] = (D_800FC4A8_DesertDash[i] - D_800FC498_DesertDash[i]) * t + D_800FC498_DesertDash[i];
            CRotM[i].x = (D_800FC468_DesertDash[i].x - D_800FC438_DesertDash[i].x) * t + D_800FC438_DesertDash[i].x;
            CRotM[i].y = (D_800FC468_DesertDash[i].y - D_800FC438_DesertDash[i].y) * t + D_800FC438_DesertDash[i].y;
            CRotM[i].z = (D_800FC468_DesertDash[i].z - D_800FC438_DesertDash[i].z) * t + D_800FC438_DesertDash[i].z;
            CenterM[i].x = (D_800FC408_DesertDash[i].x - D_800FC3D8_DesertDash[i].x) * t + D_800FC3D8_DesertDash[i].x;
            CenterM[i].y = (D_800FC408_DesertDash[i].y - D_800FC3D8_DesertDash[i].y) * t + D_800FC3D8_DesertDash[i].y;
            CenterM[i].z = (D_800FC408_DesertDash[i].z - D_800FC3D8_DesertDash[i].z) * t + D_800FC3D8_DesertDash[i].z;
        }
    }
    return last;
}
