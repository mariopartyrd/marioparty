#include "MushroomMixup.h"

u32 D_800FC720_MushroomMixup = 0;
s32 D_800FC724_MushroomMixup = 0x4B;
s32 D_800FC728_MushroomMixup = 0;
u32 D_800FC72C_MushroomMixup = 0;
u32 D_800FC730_MushroomMixup = 0;
s32 D_800FC734_MushroomMixup = 0x80;
s32 D_800FC738_MushroomMixup = 0x80;
s32 D_800FC73C_MushroomMixup = 0;
char D_800FC740_MushroomMixup[] = "32mt001_DEF";
char D_800FC74C_MushroomMixup[] = "32mt002_DEF";
char D_800FC758_MushroomMixup[] = "32mt004_DEF";
char D_800FC764_MushroomMixup[] = "32mt003_DEF";
char D_800FC770_MushroomMixup[] = "32mt005_DEF";
char D_800FC77C_MushroomMixup[] = "32mt006_DEF";
char D_800FC788_MushroomMixup[] = "32mt009_DEF";
MMNameTable D_800FC794_MushroomMixup = { {
    D_800FC740_MushroomMixup, D_800FC74C_MushroomMixup, D_800FC758_MushroomMixup, D_800FC764_MushroomMixup,
    D_800FC770_MushroomMixup, D_800FC77C_MushroomMixup, D_800FC788_MushroomMixup,
} };
MMColorTable D_800FC7B0_MushroomMixup = { {
    { 0xA4, 0x0C, 0x0C },
    { 0x2C, 0x21, 0xBC },
    { 0x5A, 0xCC, 0x1D },
    { 0xDC, 0xBE, 0x12 },
    { 0x88, 0xB7, 0xE2 },
    { 0xDC, 0x6E, 0x80 },
    { 0x05, 0x05, 0x05 },
} };
char D_800FC7DC_MushroomMixup[] = "c100_001-hata_L";
char D_800FC7EC_MushroomMixup[] = "c100_001-hata_R";
char D_800FC7FC_MushroomMixup[] = "05mt001_DEF";

void func_800F9EC0_MushroomMixup(omObjData* arg0) {
    s16 mes;
    u16 w;

    func_80009468();
    switch (D_800ED430) {
    case 0:
        if (func_80072718() != 0) {
            return;
        }
        if (D_800FC720_MushroomMixup < 2) {
            if (D_800FC720_MushroomMixup == 0) {
                D_800FC720_MushroomMixup = 1;
            }
            if (D_800FC724_MushroomMixup == 0x30) {
                func_80060128(0x27);
            }
            if (D_800FC724_MushroomMixup-- != 0) {
                break;
            }
            GMesCreate(0);
            D_800FC720_MushroomMixup = 2;
        }
        if (GMesStatAllGet() == 0) {
            func_80009458();
            return;
        }
        break;
    case 1:
        if ((s16)(D_800FCABC_MushroomMixup = func_800F84F0_MushroomMixup()) != -1 &&
            (u8)func_800F846C_MushroomMixup(D_800FCABC_MushroomMixup)) {
            func_80009438();
            return;
        }
        break;
    case 2:
        if (D_800FC728_MushroomMixup == 0) {
            if ((w = D_800FCABC_MushroomMixup) >= 4 || !(MM_PLAYER(D_800F3FB0[(s16)w])->unk_50 & 7)) {
                D_800FC728_MushroomMixup = 1;
                func_800601D4(0x28);
                if ((w = D_800FCABC_MushroomMixup) < 4) {
                    GwPlayer[MM_PLAYER(D_800F3FB0[(s16)w])->unk_58].coins_mg += 10;
                    mes = 2;
                } else if (_CheckFlag(0x2B) != 0) {
                    mes = 2;
                } else {
                    mes = 0x11;
                }
                GMesCreate(mes);
            } else {
                break;
            }
        }
        if (GMesStatAllGet() == 0 || (GMesStatAllGet() & 2)) {
            if ((s16)D_800FCABC_MushroomMixup != 4) {
                if (_CheckFlag(0x2B) == 0) {
                    omAddObj(0xA, 0, 0, -1, func_800F93F0_MushroomMixup);
                    func_800184BC(D_800FC9A8_MushroomMixup[(s16)D_800FCABC_MushroomMixup], 0xD);
                    func_80017DB0(D_800FC9A8_MushroomMixup[(s16)D_800FCABC_MushroomMixup]);
                    func_80060128(0x32);
                }
            } else if (_CheckFlag(0x2B) == 0) {
                func_80060128(0x34);
            }
            func_80009448();
            return;
        }
        break;
    case 3:
        switch (D_800FC72C_MushroomMixup) {
        case 0:
            if ((s16)D_800FCABC_MushroomMixup != 4 && _CheckFlag(0x2B) == 0) {
                if (D_800FC730_MushroomMixup++ >= 0x16) {
                    func_80060618(0x451, (s16)D_800FCABC_MushroomMixup);
                    D_800FC730_MushroomMixup = 0;
                    D_800FC72C_MushroomMixup = 1;
                    return;
                }
            } else {
                D_800FC72C_MushroomMixup = 1;
                return;
            }
            break;
        case 1:
            if (_CheckFlag(0x2B) == 0) {
                if ((s16)D_800FCABC_MushroomMixup != 4) {
                    if (D_800FC730_MushroomMixup++ < 0x54) {
                        break;
                    }
                } else if (D_800FC730_MushroomMixup++ < 0x5A) {
                    break;
                }
            } else if (D_800FC730_MushroomMixup++ < 0x1E) {
                break;
            }
            if (_CheckFlag(0x2B) == 0 || GMesWait() != 1) {
                func_800726AC(0, 0x14);
                D_800FC72C_MushroomMixup = 2;
                return;
            }
            break;
        case 2:
            if (func_80072718() == 0) {
                func_8002890C(0, 0, 0);
                omOvlReturnEx(1);
            }
            break;
        }
        break;
    }
}

void func_800FA320_MushroomMixup(omObjData* arg0) {
    MMGroundWork* work;

    arg0->model[0] = func_800174C0(0x2C0002, 0x899);
    arg0->trans.x = 500.0f;
    arg0->trans.y = 100.0f;
    arg0->trans.z = -250.0f;
    work = func_80023684(0x2C, 0x7918);
    arg0->unk_50 = work;
    func_8009B770(work, 0, 0x2C);
    arg0->func_ptr = NULL;
    work->unk_04 = 2;
    work->unk_05 = 0;
}

void func_800FA3C4_MushroomMixup(omObjData* arg0) {
    if (func_8005FD5C() + D_800F64F8 == 0) {
        D_800FC848_MushroomMixup += 0.1f;
    }
    func_80027C1C(arg0->model[0], D_800FC848_MushroomMixup, D_800FC84C_MushroomMixup, D_800FC844_MushroomMixup.unk_00,
                  D_800FC844_MushroomMixup.unk_02);
}

void func_800FA454_MushroomMixup(omObjData* arg0) {
    MMGroundWork* work;

    arg0->model[0] = func_800174C0(0x2C0003, 0x1899);
    arg0->trans.x = 0.0f;
    arg0->trans.y = 150.0f;
    arg0->trans.z = -300.0f;
    work = func_80023684(0x2C, 0x7918);
    arg0->unk_50 = work;
    func_8009B770(work, 0, 0x2C);
    arg0->func_ptr = func_800FA3C4_MushroomMixup;
    work->unk_04 = 2;
    work->unk_05 = 1;
    func_80009000(arg0, 2, 70.0f);
    func_80026040(arg0->model[0]);
    func_80039C48(D_800FC7FC_MushroomMixup, &D_800FC844_MushroomMixup);
    D_800FC848_MushroomMixup = D_800FC84C_MushroomMixup = 0.0f;
}

void func_800FA53C_MushroomMixup(omObjData* arg0, MMMushroom* rec, s32 file, s16 idx, Vec* pos) {
    MMGroundWork* work;

    arg0->model[0] = func_800174C0(file, 0x889);
    rec->model = arg0->model[0];
    arg0->trans.x = pos->x;
    arg0->trans.y = pos->y;
    arg0->trans.z = pos->z;
    arg0->scale.x = arg0->scale.z = 0.95f;
    work = func_80023684(0x2C, 0x7918);
    arg0->unk_50 = work;
    func_8009B770(work, 0, 0x2C);
    arg0->func_ptr = func_800F7FCC_MushroomMixup;
    arg0->work[0] = idx;
    func_80008FB8(arg0, 0.5f);
    func_80008FC4(arg0, 0.0f);
    work->unk_04 = 1;
    work->unk_05 = idx + 2;
    rec->colIdx = work->unk_05;
    func_80009000(arg0, 4, 0.0f);
    /* retail passed the id as a u16 (lhu): this unit's declaration differed from the definition */
    ((void (*)(u16, u32))func_800F70F0_MushroomMixup)(arg0->model[0], rec->color & 7);
    func_80025B34(arg0->model[0]);
}

void func_800FA664_MushroomMixup(omObjData* arg0, s32 arg1, s32 arg2, u16 arg3, f32 arg4, s32 arg5) {
    Vec3f sp18;
    MMPlayerWork* work;
    omObjData* other;

    func_80009618(1);
    func_8000979C(arg0, arg1, arg2, arg3, 0xA99, 0xA89);
    work = arg0->unk_50;
    func_80009340(arg0, 2, 0x25, 0x1689, 0);
    arg0->model[3] = LoadFormFile(0x19, 0xA8D);
    arg0->model[4] = LoadFormFile(0x1A, 0xA8D);
    arg0->model[7] = LoadFormFile(0x1E, 0xA8D);
    arg0->model[8] = LoadFormFile(0x1D, 0xA8D);
    func_800187D0(arg0, 0, arg1, 1, 0);
    func_800187D0(arg0, 1, arg1 | 1, 1, 0);
    func_800187D0(arg0, 2, arg1 | 3, 1, 0);
    func_800187D0(arg0, 5, arg1 | 4, 0, 0);
    func_800187D0(arg0, 6, arg1 | 5, 1, 0x13);
    func_800187D0(arg0, 8, arg1 | 9, 1, 0x1D);
    if (rand8() & 1) {
        func_800187D0(arg0, 0xD, arg1 | 0xF, 1, 0x78);
    } else {
        func_800187D0(arg0, 0xD, arg1 | 0x38, 1, 0x78);
    }
    func_800187D0(arg0, 0xF, arg1 | 0x11, 1, 0);
    func_800187D0(arg0, 0x10, arg1 | 0x17, 1, 0);
    func_800187D0(arg0, 0x11, arg1 | 0x18, 0, 0);
    func_800187D0(arg0, 0x12, arg1 | 0x1C, 2, 0);
    func_800187D0(arg0, 0x15, arg1 | 0x62, 0, 0);
    func_800187D0(arg0, 3, arg1 | 0x60, 1, 0);
    func_800187D0(arg0, 4, arg1 | 0x61, 1, 0);
    func_800187D0(arg0, 0x1E, arg1 | 0x63, 0, 0);
    arg0->work[0] = arg3;
    arg0->work[1] = 0;
    arg0->work[2] = 0;
    arg0->work[3] = arg5;
    D_800FC880_MushroomMixup[(u16)arg3] = arg0->unk_50;
    D_800FC9A8_MushroomMixup[(u16)arg3] = arg0;
    func_800F8848_MushroomMixup(arg0);
    arg0->trans.x = func_800AEAC0(arg4) * 100.0f;
    arg0->trans.y = 499.0f;
    arg0->trans.z = func_800AEFD0(arg4) * 100.0f;
    other = D_800F3FB0[arg5];
    func_800A0D00(&sp18, other->trans.x, 0.0f, other->trans.z);
    sp18.x -= arg0->trans.x;
    sp18.y -= 0.0f;
    sp18.z -= arg0->trans.z;
    work->unk_3C = 0.0f;
    func_800F9510_MushroomMixup(arg0, 1);
    arg0->func_ptr = func_800F9548_MushroomMixup;
    work->unk_52 = 0;
    work->unk_38 = 1000.0f;
    work->unk_A4 = 1.0f;
    work->unk_58 = arg3;
    work->unk_56 = GwPlayer[(u16)arg3].port;
    func_80008FD0(arg0, 35.5f);
    func_80008FDC(arg0, 150.0f);
    func_80008FE8(arg0, 50.0f);
    func_800090C4(arg0, 0, 1);
    func_800090C4(arg0, 1, 1);
    func_800090C4(arg0, 2, 2);
    func_800090C4(arg0, 3, 2);
    func_800090C4(arg0, 4, 2);
    func_800090C4(arg0, 5, 2);
    func_800090C4(arg0, 6, 2);
    func_800090C4(arg0, 7, 2);
    func_800090C4(arg0, 8, 2);
}

void func_800FAAE8_MushroomMixup(omObjData* arg0) {
    arg0->model[0] = LoadFormFile(0x5A, 0xA99);
    arg0->model[1] = func_800174F4(6, 0xA89);
    func_80025930(arg0->model[1], 0x80000000, 0);
    func_80025AD4(arg0->model[1]);
    func_80025B34(arg0->model[1]);
    func_8009EA40(D_800F2B7C[arg0->model[1]].unk7C, 0.0f, 15.0f, 0.0f);
    arg0->func_ptr = func_800F75B0_MushroomMixup;
    arg0->trans.x = 500.0f;
    arg0->trans.y = 600.0f;
    arg0->trans.z = -210.0f;
    func_800F9510_MushroomMixup(arg0, 1);
    func_800F7088_MushroomMixup(arg0->model[0]);
}

void func_800FABE4_MushroomMixup(omObjData* arg0) {
    omObjData* mush;
    unk2C0C0StructC0* m;
    s32 i;
    u16 hit;
    s16 sound;

    mush = D_800FC9C0_MushroomMixup[arg0->work[0]].obj;
    if (arg0->work[1] != 0) {
        func_800258EC(arg0->model[0], 4, 0);
        arg0->scale.x += 0.03f;
        arg0->scale.z += 0.03f;
        m = D_800F2B7C[arg0->model[0]].unk_6C;
        for (i = 0; i < m->unk_6A; i++) {
            m->unk_80[i].unk_02 = (1.0f - func_800AEAC0(arg0->work[2])) * 255.0f;
        }
        arg0->work[2] += 2.6999998f;
        if (arg0->scale.x > 2.0f) {
            arg0->work[1] = 0;
            func_800258EC(arg0->model[0], 4, 4);
        }
    } else {
        hit = 0;
        if (D_800FC9C0_MushroomMixup[arg0->work[0]].speed < 0.0f) {
            if (mush->trans.y > -250.0f) {
                arg0->work[3] = 0;
            }
            if (mush->trans.y <= -250.0f && arg0->work[3] == 0) {
                if (D_800FC990_MushroomMixup == 0) {
                    D_800FC990_MushroomMixup = 1;
                    func_800F7188_MushroomMixup(0x290);
                }
                hit = 1;
            }
        } else {
            if (mush->trans.y < -360.0f) {
                arg0->work[3] = 0;
            }
            if (mush->trans.y >= -360.0f && arg0->work[3] == 0) {
                if (D_800FC990_MushroomMixup == 0) {
                    D_800FC990_MushroomMixup = 1;
                    func_800F7188_MushroomMixup(0x291);
                }
                hit = 1;
            }
        }
        if (hit) {
            arg0->work[1] = 1;
            arg0->work[3] = 1;
            arg0->scale.x = 1.0f;
            arg0->scale.z = 1.0f;
            arg0->work[2] = 0;
            m = D_800F2B7C[arg0->model[0]].unk_6C;
            for (i = 0; i < m->unk_76; i++) {
                m->unk_A8[i].unk_0D = 0xFF;
            }
        }
    }
}

void func_800FAF90_MushroomMixup(omObjData* arg0, Vec* pos, s8 idx) {
    void* work;
    unk2C0C0StructC0* m;
    s32 i;

    work = func_80023684(0xE8, 0x7918);
    arg0->unk_50 = work;
    func_8009B770(work, 0, 0xE8);
    if (D_800FC734_MushroomMixup == 0x80) {
        arg0->model[0] = LoadFormFile(0x1F, 0x1A8D);
        D_800FC734_MushroomMixup = arg0->model[0];
    } else {
        arg0->model[0] = func_80023FC8((s16)D_800FC734_MushroomMixup);
    }
    arg0->func_ptr = func_800FABE4_MushroomMixup;
    arg0->work[0] = idx;
    arg0->work[1] = 0;
    arg0->work[2] = 0;
    arg0->work[3] = 0;
    arg0->trans.x = pos->x;
    arg0->trans.y = pos->y;
    arg0->trans.z = pos->z;
    func_80025930(arg0->model[0], 0x10000, 0x10000);
    m = D_800F2B7C[arg0->model[0]].unk_6C;
    for (i = 0; i < m->unk_76; i++) {
        m->unk_A8[i].unk_0C |= 5;
        m->unk_A8[i].unk_0D = 0xFF;
    }
    func_80025AD4(arg0->model[0]);
}

void func_800FB0FC_MushroomMixup(omObjData* arg0) {
    func_80025B34(arg0->model[0]);
}

void func_800FB11C_MushroomMixup(omObjData* arg0) {
    s32 bit;
    s32 j;
    s32 i;

    i = 0;
    if (D_800FC9A0_MushroomMixup != 0) {
        for (bit = 1; i < 4; i++, bit <<= 1) {
            if (bit & D_800FC9A0_MushroomMixup) {
                break;
            }
        }
        if (i < 4) {
            for (j = 0, bit = 1; j < 2; j++, bit <<= 1) {
                if (!(bit & D_800FC8AC_MushroomMixup)) {
                    break;
                }
            }
            if (j < 2) {
                if ((D_800FC9C8_MushroomMixup != 2 || !(D_800FC9C0_MushroomMixup[0].obj->trans.y >= -620.0f)) &&
                    (D_800FC9EC_MushroomMixup != 2 || !(D_800FC9E4_MushroomMixup.obj->trans.y >= -620.0f))) {
                    D_800FC8A4_MushroomMixup[j]->work[1] = i;
                    D_800FC8AC_MushroomMixup = bit | D_800FC8AC_MushroomMixup;
                }
            }
        }
    }
}

void func_800FB238_MushroomMixup(omObjData* arg0) {
    MMFlagState* st;
    u8 p;
    f32 t;
    f32 lim;

    p = arg0->work[1];
    st = &D_800FC850_MushroomMixup[arg0->work[0]];
    if (!((D_800FC8AC_MushroomMixup >> arg0->work[0]) & 1)) {
        return;
    }
    D_800FC9A0_MushroomMixup &= ~(1 << arg0->work[1]);
    switch (arg0->work[2]) {
    case 0:
        func_800258EC(arg0->model[0], 4, 0);
        if (D_800FC9A8_MushroomMixup[p]->trans.x > 0.0f) {
            st->unk_0C = -30.0f;
            arg0->trans.x = 1000.0f;
        } else {
            st->unk_0C = 30.0f;
            arg0->trans.x = -1000.0f;
        }
        arg0->trans.z = D_800FC9A8_MushroomMixup[p]->trans.z;
        arg0->work[2] = 1;
        st->unk_00 = 0.0f;
        st->unk_04 = 0.0f;
        st->unk_10 = 0;
        st->unk_08 = 0.0f;
    case 1:
        if (st->unk_10 != 2) {
            if (func_8005FD5C() + D_800F64F8 == 0) {
                st->unk_00 += 10.0f;
            }
            if (st->unk_00 > 360.0f) {
                st->unk_00 -= 360.0f;
            }
            t = 1.0f - func_800AEFD0(st->unk_00);
            if (t == 1.0f && st->unk_10 == 1) {
                st->unk_10 = 2;
            }
        } else {
            t = 1.0f;
        }
        func_80026174(arg0->model[0], arg0->model[1], t);
        if (func_8005FD5C() + D_800F64F8 == 0) {
            st->unk_04 += 5.0f;
            if (st->unk_04 > 180.0f) {
                st->unk_04 -= 180.0f;
            }
            arg0->trans.x += func_800AEAC0(st->unk_04) * st->unk_0C;
            if (st->unk_0C < 0.0f) {
                if (arg0->trans.x < D_800FC9A8_MushroomMixup[p]->trans.x + 80.0f + 200.0f) {
                    st->unk_10 = 1;
                }
                lim = D_800FC9A8_MushroomMixup[p]->trans.x + 80.0f;
                if (!(arg0->trans.x <= lim)) {
                    break;
                }
            } else {
                if (D_800FC9A8_MushroomMixup[p]->trans.x - 80.0f - 200.0f < arg0->trans.x) {
                    st->unk_10 = 1;
                }
                lim = D_800FC9A8_MushroomMixup[p]->trans.x - 80.0f;
                if (!(lim <= arg0->trans.x)) {
                    break;
                }
            }
            arg0->trans.x = lim;
            if (t == 1.0f) {
                arg0->work[2] = 2;
                return;
            }
        }
        break;
    case 2:
        t = 1.0f - func_800AEFD0(st->unk_00);
        if (func_8005FD5C() + D_800F64F8 == 0) {
            st->unk_00 += 30.0f;
        }
        if (st->unk_00 > 360.0f) {
            st->unk_00 -= 360.0f;
        }
        if (st->unk_0C < 0.0f) {
            func_80026174(arg0->model[0], arg0->model[4], t);
        } else {
            func_80026174(arg0->model[0], arg0->model[2], t);
        }
        if (t == 0.0f) {
            omObjData* pl;
            MMPlayerWork* work;

            arg0->work[2] = 3;
            st->unk_08 = 0.0f;
            func_800184BC(D_800FC9A8_MushroomMixup[p], 0xF);
            func_80017DB0(D_800FC9A8_MushroomMixup[p]);
            pl = D_800FC9A8_MushroomMixup[p];
            work = pl->unk_50;
            if (st->unk_0C < 0.0f) {
                work->unk_3C = 270.0f;
            } else {
                work->unk_3C = 90.0f;
            }
            func_8009ECB0(D_800F2B7C[pl->model[0]].unk7C, 0.0f, work->unk_3C, 0.0f);
            return;
        }
        break;
    case 3: {
        s32 done;

        func_800258EC(arg0->model[0], 4, 4);
        if (st->unk_0C < 0.0f) {
            func_800258EC(arg0->model[4], 4, 0);
        } else {
            func_800258EC(arg0->model[2], 4, 0);
        }
        if (func_8005FD5C() + D_800F64F8 == 0) {
            st->unk_04 += 5.0f;
            if (st->unk_04 > 180.0f) {
                st->unk_04 -= 180.0f;
            }
            arg0->trans.x -= func_800AEAC0(st->unk_04) * st->unk_0C;
            arg0->trans.y += func_800AEAC0(st->unk_08) * 5.0f;
            st->unk_08 += 10.0f;
            if (st->unk_08 > 360.0f) {
                st->unk_08 -= 360.0f;
            }
            if (st->unk_0C < 0.0f) {
                func_80025798(arg0->model[4], arg0->trans.x, arg0->trans.y + 50.0f, arg0->trans.z);
            } else {
                func_80025798(arg0->model[2], arg0->trans.x, arg0->trans.y, arg0->trans.z);
            }
            done = 0;
            if (st->unk_0C < 0.0f) {
                D_800FC9A8_MushroomMixup[p]->trans.x = arg0->trans.x - 80.0f;
                if (arg0->trans.x >= 1000.0f) {
                    done = 1;
                }
            } else {
                D_800FC9A8_MushroomMixup[p]->trans.x = arg0->trans.x + 80.0f;
                if (arg0->trans.x <= -1000.0f) {
                    done = 1;
                }
            }
            if ((u16)done) {
                func_800258EC(D_800FC9A8_MushroomMixup[p]->model[0], 4, 4);
                func_800258EC(D_800FC9A8_MushroomMixup[p]->model[1], 4, 4);
                if (st->unk_0C < 0.0f) {
                    func_800258EC(arg0->model[4], 4, 4);
                } else {
                    func_800258EC(arg0->model[2], 4, 4);
                }
                D_800FC8A0_MushroomMixup &= ~(1 << p);
                D_800FC8AC_MushroomMixup &= ~(1 << arg0->work[0]);
                arg0->work[2] = 0;
            }
        }
        t = 1.0f - func_800AEFD0(st->unk_00);
        if (func_8005FD5C() + D_800F64F8 == 0) {
            st->unk_00 += 10.0f;
        }
        if (st->unk_00 > 360.0f) {
            st->unk_00 -= 360.0f;
        }
        if (st->unk_0C < 0.0f) {
            func_80026174(arg0->model[4], arg0->model[5], t);
        } else {
            func_80026174(arg0->model[2], arg0->model[3], t);
        }
        break;
    }
    }
}

void func_800FBB8C_MushroomMixup(omObjData* arg0, u16 arg1) {
    void* work;

    work = func_80023684(0xE8, 0x7918);
    arg0->unk_50 = work;
    func_8009B770(work, 0, 0xE8);
    if (D_800FC738_MushroomMixup == 0x80) {
        arg0->model[0] = LoadFormFile(0x38, 0xA9D);
        arg0->model[1] = LoadFormFile(0x39, 0xA9D);
        arg0->model[2] = LoadFormFile(0x3A, 0xA9D);
        arg0->model[3] = LoadFormFile(0x3B, 0xA9D);
        arg0->model[4] = LoadFormFile(0x3C, 0xA9D);
        arg0->model[5] = LoadFormFile(0x3D, 0xA9D);
        D_800FC738_MushroomMixup = arg0->model[0];
        D_800FC830_MushroomMixup = arg0->model[1];
        D_800FC834_MushroomMixup = arg0->model[2];
        D_800FC838_MushroomMixup = arg0->model[3];
        D_800FC83C_MushroomMixup = arg0->model[4];
        D_800FC840_MushroomMixup = arg0->model[5];
    } else {
        arg0->model[0] = func_80023FC8((s16)D_800FC738_MushroomMixup);
        arg0->model[1] = func_80023FC8((s16)D_800FC830_MushroomMixup);
        arg0->model[2] = func_80023FC8((s16)D_800FC834_MushroomMixup);
        arg0->model[3] = func_80023FC8((s16)D_800FC838_MushroomMixup);
        arg0->model[4] = func_80023FC8((s16)D_800FC83C_MushroomMixup);
        arg0->model[5] = func_80023FC8((s16)D_800FC840_MushroomMixup);
    }
    func_80026040(arg0->model[0]);
    func_80026040(arg0->model[2]);
    func_80026040(arg0->model[4]);
    arg0->func_ptr = func_800FB238_MushroomMixup;
    arg0->work[0] = arg1;
    arg0->work[2] = 0;
    arg0->trans.x = 1000.0f;
    arg0->trans.y = -50.0f;
    arg0->trans.z = 0.0f;
    func_80025798(arg0->model[2], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_80025798(arg0->model[4], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    arg0->scale.x = 0.8f;
    arg0->scale.y = 0.8f;
    arg0->scale.z = 0.8f;
    func_80025830(arg0->model[2], arg0->scale.x, arg0->scale.y, arg0->scale.z);
    func_80025830(arg0->model[4], arg0->scale.x, arg0->scale.y, arg0->scale.z);
    arg0->rot.y = 0.0f;
    D_800FC8A4_MushroomMixup[arg1] = arg0;
}

void func_800FBE30_MushroomMixup(omObjData* arg0) {
    func_800FA664_MushroomMixup(arg0, D_800C59AC[GwPlayer[0].character].unk_00, D_800C59AC[GwPlayer[0].character].unk_04, 0, 45.0f, 1);
}

void func_800FBE90_MushroomMixup(omObjData* arg0) {
    func_800FA664_MushroomMixup(arg0, D_800C59AC[GwPlayer[1].character].unk_00, D_800C59AC[GwPlayer[1].character].unk_04, 1, 135.0f, 0);
}

void func_800FBEEC_MushroomMixup(omObjData* arg0) {
    func_800FA664_MushroomMixup(arg0, D_800C59AC[GwPlayer[2].character].unk_00, D_800C59AC[GwPlayer[2].character].unk_04, 2, 225.0f, 3);
}

void func_800FBF4C_MushroomMixup(omObjData* arg0) {
    func_800FA664_MushroomMixup(arg0, D_800C59AC[GwPlayer[3].character].unk_00, D_800C59AC[GwPlayer[3].character].unk_04, 3, 315.0f, 2);
}

/* Retail addresses each record's fields through their own labels (MushroomMixup.h). */
void func_800FBFB0_MushroomMixup(omObjData* arg0) {
    Vec pos;
    Vec* pp;
    MMMushroom* rec;

    pp = &pos;
    rec = &D_800FC9C0_MushroomMixup[0];
    D_800FC9B8_MushroomMixup = 0.0f;
    rec->obj = arg0;
    D_800FC9C6_MushroomMixup = 6;
    D_800FC9CC_MushroomMixup = -5.0f - D_800FC9B8_MushroomMixup;
    D_800FC9C8_MushroomMixup = 0;
    pp->x = D_800FC9D4_MushroomMixup = D_800FC9D0_MushroomMixup = 0.0f;
    pp->y = D_800FC9D8_MushroomMixup = 0.0f;
    pp->z = D_800FC9DC_MushroomMixup = 0.0f;
    func_800F70C4_MushroomMixup();
    func_800FA53C_MushroomMixup(arg0, rec, 0x2C0000, 0, pp);
}

void func_800FC068_MushroomMixup(omObjData* arg0) {
    Vec pos;
    Vec* pp;

    pp = &pos;
    D_800FC9E4_MushroomMixup.obj = arg0;
    D_800FC9EA_MushroomMixup = 2;
    D_800FC9F0_MushroomMixup = -5.0f - D_800FC9B8_MushroomMixup;
    D_800FC9EC_MushroomMixup = 0;
    D_800FC9F4_MushroomMixup = 0.0f;
    pp->x = D_800FC9F8_MushroomMixup = 333.4375f;
    pp->y = D_800FC9FC_MushroomMixup = 0.0f;
    pp->z = D_800FCA00_MushroomMixup = 4.21876f;
    func_800FA53C_MushroomMixup(arg0, &D_800FC9E4_MushroomMixup, 0x2C0000, 1, pp);
}

void func_800FC114_MushroomMixup(omObjData* arg0) {
    Vec pos;
    Vec* pp;

    pp = &pos;
    D_800FCA08_MushroomMixup.obj = arg0;
    D_800FCA0E_MushroomMixup = 5;
    D_800FCA14_MushroomMixup = -5.0f - D_800FC9B8_MushroomMixup;
    D_800FCA10_MushroomMixup = 0;
    D_800FCA18_MushroomMixup = 0.0f;
    pp->x = D_800FCA1C_MushroomMixup = 167.5f;
    pp->y = D_800FCA20_MushroomMixup = 0.0f;
    pp->z = D_800FCA24_MushroomMixup = 291.875f;
    func_800FA53C_MushroomMixup(arg0, &D_800FCA08_MushroomMixup, 0x2C0000, 2, pp);
}

void func_800FC1C0_MushroomMixup(omObjData* arg0) {
    Vec pos;
    Vec* pp;

    pp = &pos;
    D_800FCA2C_MushroomMixup.obj = arg0;
    D_800FCA32_MushroomMixup = 1;
    D_800FCA38_MushroomMixup = -5.0f - D_800FC9B8_MushroomMixup;
    D_800FCA34_MushroomMixup = 0;
    D_800FCA3C_MushroomMixup = 0.0f;
    pp->x = D_800FCA40_MushroomMixup = -161.96877f;
    pp->y = D_800FCA44_MushroomMixup = 0.0f;
    pp->z = D_800FCA48_MushroomMixup = 293.375f;
    func_800FA53C_MushroomMixup(arg0, &D_800FCA2C_MushroomMixup, 0x2C0000, 3, pp);
}

void func_800FC26C_MushroomMixup(omObjData* arg0) {
    Vec pos;
    Vec* pp;

    pp = &pos;
    D_800FCA50_MushroomMixup.obj = arg0;
    D_800FCA56_MushroomMixup = 4;
    D_800FCA5C_MushroomMixup = -5.0f - D_800FC9B8_MushroomMixup;
    D_800FCA58_MushroomMixup = 0;
    D_800FCA60_MushroomMixup = 0.0f;
    pp->x = D_800FCA64_MushroomMixup = -330.9375f;
    pp->y = D_800FCA68_MushroomMixup = 0.0f;
    pp->z = D_800FCA6C_MushroomMixup = 0.46876f;
    func_800FA53C_MushroomMixup(arg0, &D_800FCA50_MushroomMixup, 0x2C0000, 4, pp);
}

void func_800FC318_MushroomMixup(omObjData* arg0) {
    Vec pos;
    Vec* pp;

    pp = &pos;
    D_800FCA74_MushroomMixup.obj = arg0;
    D_800FCA7A_MushroomMixup = 3;
    D_800FCA80_MushroomMixup = -5.0f - D_800FC9B8_MushroomMixup;
    D_800FCA7C_MushroomMixup = 0;
    D_800FCA84_MushroomMixup = 0.0f;
    pp->x = D_800FCA88_MushroomMixup = -156.09377f;
    pp->y = D_800FCA8C_MushroomMixup = 0.0f;
    pp->z = D_800FCA90_MushroomMixup = -284.0625f;
    func_800FA53C_MushroomMixup(arg0, &D_800FCA74_MushroomMixup, 0x2C0000, 5, pp);
}

void func_800FC3C4_MushroomMixup(omObjData* arg0) {
    Vec pos;
    Vec* pp;

    pp = &pos;
    D_800FCA98_MushroomMixup.obj = arg0;
    D_800FCA9E_MushroomMixup = 0;
    D_800FCAA4_MushroomMixup = -5.0f - D_800FC9B8_MushroomMixup;
    D_800FCAA0_MushroomMixup = 0;
    D_800FCAA8_MushroomMixup = 0.0f;
    pp->x = D_800FCAAC_MushroomMixup = 166.40627f;
    pp->y = D_800FCAB0_MushroomMixup = 0.0f;
    pp->z = D_800FCAB4_MushroomMixup = -282.65625f;
    func_800FA53C_MushroomMixup(arg0, &D_800FCA98_MushroomMixup, 0x2C0000, 6, pp);
}

#define MM_FLAG_INIT(n, px, pz)                  \
    Vec pos;                                     \
                                                 \
    pos.x = px;                                  \
    pos.y = 160.0f;                              \
    pos.z = pz;                                  \
    func_800FAF90_MushroomMixup(arg0, &pos, n);

void func_800FC46C_MushroomMixup(omObjData* arg0) {
    MM_FLAG_INIT(0, 0.0f, 0.0f)
}

void func_800FC4A4_MushroomMixup(omObjData* arg0) {
    MM_FLAG_INIT(1, 333.4375f, 4.21876f)
}

void func_800FC4FC_MushroomMixup(omObjData* arg0) {
    MM_FLAG_INIT(2, 167.5f, 291.875f)
}

void func_800FC554_MushroomMixup(omObjData* arg0) {
    MM_FLAG_INIT(3, -161.96877f, 293.375f)
}

void func_800FC5AC_MushroomMixup(omObjData* arg0) {
    MM_FLAG_INIT(4, -330.9375f, 0.46876f)
}

void func_800FC604_MushroomMixup(omObjData* arg0) {
    MM_FLAG_INIT(5, -156.09377f, -284.0625f)
}

void func_800FC65C_MushroomMixup(omObjData* arg0) {
    MM_FLAG_INIT(6, 166.40627f, -282.65625f)
    func_800FB0FC_MushroomMixup(arg0);
}

void func_800FC6C8_MushroomMixup(omObjData* arg0) {
    func_800FBB8C_MushroomMixup(arg0, 0);
}

void func_800FC6E4_MushroomMixup(omObjData* arg0) {
    func_800FBB8C_MushroomMixup(arg0, 1);
}
