#include "MusicalMushroom.h"

// register allocation: v1/v0 in the D_800FB4DC decrement (masked 0)
#ifdef NON_MATCHING
void func_800F9660_MusicalMushroom(omObjData* obj) {
    s32 i;
    s32 failed;

    func_80009468();
    func_800F71E4_MusicalMushroom();
    switch (D_800ED430) {
    case 0:
        switch (D_800FB4D0_MusicalMushroom) {
        case 0:
            if (func_80072718() != 0) {
                return;
            }
            if (D_800FB4D8_MusicalMushroom < 2) {
                if (D_800FB4D8_MusicalMushroom == 0) {
                    PlaySound(0x1A2);
                    D_800FB4D8_MusicalMushroom = 1;
                }
                if (D_800FB4DC_MusicalMushroom == 0x20) {
                    for (i = 0; i < 9; i++) {
                        func_800258EC(D_800FB680_MusicalMushroom[i]->model[0], 4, 4);
                        func_800258EC(D_800FB680_MusicalMushroom[i]->model[1], 4, 0);
                    }
                }
                if (D_800FB4DC_MusicalMushroom < 0x10) {
                    D_800FB4D4_MusicalMushroom = 1;
                }
                if (--D_800FB4DC_MusicalMushroom != 0) {
                    break;
                }
                GMesCreate(0);
                D_800FB4D8_MusicalMushroom = 2;
            }
            if (GMesStatAllGet() == 0) {
                func_80060128(0x1D);
                GMesCreate(8, 0x1E, 0xA0, 0x18);
                D_800FB4D0_MusicalMushroom = 1;
                return;
            }
            break;
        case 2:
            if (D_800FB4D0_MusicalMushroom == 2 && D_800FB778_MusicalMushroom[D_800FB648_MusicalMushroom] >= D_800FB678_MusicalMushroom) {
                func_800601D4(5);
                D_800FB4D0_MusicalMushroom = 3;
                return;
            }
            break;
        }
        break;
    case 1:
        if (D_800FB4E8_MusicalMushroom < 29) {
            if (D_800FB6A4_MusicalMushroom == -1) {
                D_800FB650_MusicalMushroom = 1;
                failed = 0;
                for (i = 0; i < D_800F2BC0; i++) {
                    if (!func_800F8830_MusicalMushroom(i)) {
                        failed = 1;
                    }
                }
                if (failed == 0 || --D_800FB4F8_MusicalMushroom == 0) {
                    D_800FB640_MusicalMushroom = 1;
                    func_80009438();
                    return;
                }
            }
        } else {
            func_80079078(D_800FB4E8_MusicalMushroom / 30);
            D_800FB4E8_MusicalMushroom--;
            if (D_800FB4EC_MusicalMushroom == 0) {
                D_800FB4EC_MusicalMushroom = 1;
                func_800258EC(obj->model[0], 0x1C00, 0x400);
                D_800F2B7C[obj->model[0]].unk_6C->unk_28 = 0;
                return;
            }
        }
        break;
    case 2:
        if (D_800FB640_MusicalMushroom != 0) {
            func_800258EC(obj->model[0], 0x1C00, 0);
            D_800F2B7C[obj->model[0]].unk_6C->unk_28 = 0;
            if (D_800FB78C_MusicalMushroom == 4) {
                func_80009730();
                for (i = 0; i < D_800F2BC0; i++) {
                    if (D_800FB6A4_MusicalMushroom == i) {
                        D_800FB78C_MusicalMushroom = i;
                        if (_CheckFlag(0x2B) == 0) {
                            func_80060128(0x32);
                            func_800184BC(D_800FB658_MusicalMushroom[i].obj, 0xD);
                        }
                    } else if (_CheckFlag(0x2B) == 0) {
                        func_800184BC(D_800FB658_MusicalMushroom[i].obj, 0xE);
                    }
                    func_80017DB0(D_800FB658_MusicalMushroom[i].obj);
                }
                if (D_800FB78C_MusicalMushroom != 4) {
                    GwPlayer[((MMPlayerWork*)D_800F3FB0[D_800FB78C_MusicalMushroom]->unk_50)->unk_58].coins_mg += 10;
                    if (_CheckFlag(0x2B) == 0) {
                        omAddObj(0xA, 0, 0, -1, &func_800F7338_MusicalMushroom);
                    }
                } else {
                    D_800FB78C_MusicalMushroom = 5;
                }
            }
            if (D_800FB78C_MusicalMushroom == 5 || ++D_800FB4E0_MusicalMushroom >= 21) {
                if (D_800FB4E4_MusicalMushroom == 0) {
                    D_800FB4E4_MusicalMushroom = 1;
                    if (D_800FB78C_MusicalMushroom != 5) {
                        if (_CheckFlag(0x2B) == 0) {
                            func_80060618(0x451, (s16)D_800FB78C_MusicalMushroom);
                            GMesCreate(4, GwPlayer[D_800FB78C_MusicalMushroom].character);
                        }
                    } else {
                        func_800790C0();
                        GMesCreate(_CheckFlag(0x2B) != 0 ? 2 : 0x10);
                    }
                }
                if (D_800FB78C_MusicalMushroom == 5) {
                    if (GMesStatAllGet() == 0 || (GMesStatAllGet() & 2)) {
                        if (D_800FB78C_MusicalMushroom == 5 && _CheckFlag(0x2B) == 0) {
                            func_80060128(0x34);
                        }
                        func_80009448();
                    }
                } else {
                    func_80009448();
                }
            }
        }
        break;
    case 3:
        switch (D_800FB4F0_MusicalMushroom) {
        case 0:
            if (_CheckFlag(0x2B) != 0) {
                if (GMesWait() == 1) {
                    break;
                }
            } else if (D_800FB78C_MusicalMushroom != 5) {
                if (++D_800FB4F4_MusicalMushroom < 84) {
                    break;
                }
            } else if (++D_800FB4F4_MusicalMushroom < 95) {
                break;
            }
            func_800726AC(0, 0x14);
            D_800FB4F0_MusicalMushroom = 1;
            break;
        case 1:
            if (func_80072718() == 0) {
                func_8002890C(0, 0, 0);
                omOvlReturnEx(1);
            }
            break;
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_MusicalMushroom/11F890", func_800F9660_MusicalMushroom);
#endif

void func_800F9D70_MusicalMushroom(omObjData* arg0) {
    u32 temp_v1_2;
    u32 temp_v1;
    u8 temp_s0;
    unkGlobalStruct_02* temp_v0;
    u32 phi_s2;
    u32 phi_s1;

    arg0->model[0] = func_800174C0(0x1D0000, 0x299);
    arg0->trans.x = arg0->trans.y = arg0->trans.z = 0;
    arg0->unk_50 = func_80023684(sizeof(unkGlobalStruct_02), 31000);
    temp_v0 = arg0->unk_50;
    func_8009B770(temp_v0, 0, sizeof(unkGlobalStruct_02));
    arg0->func_ptr = &func_800F9660_MusicalMushroom;
    temp_v1 = rand8() % 100;
    phi_s2 = 140;
    
    if (temp_v1 < 20) {
        phi_s1 = 200;
    } else {
        phi_s2 = 200;
        if (temp_v1 < 80) {
            phi_s1 = 270;
        } else {
            phi_s2 = 270;
            phi_s1 = 360;
        }
    }
    
    temp_v1_2 = (rand8() << 8) | rand8();
    temp_v1_2 = phi_s2 + (temp_v1_2 % (phi_s1 - phi_s2)); //phi_s1 - phi_s2 will always be 60, 70, or 90
    
    D_800FB678_MusicalMushroom = temp_v1_2;
    temp_v0->unk_04 = 1;
    func_80008FB8(arg0, 0.5f);
    func_80008FC4(arg0, 20.0f);
    temp_v0->unk_05 = 0;
}

/* Unused: load a sprite (file, or reuse with mode != 0) keeping D_800FB5B0 as its saved field. */
u16 func_800F9EFC_MusicalMushroom(s32 file, s32 arg1, s32 arg2, u16 mode) {
    void* data;
    s16 idx;

    if (mode == 0) {
        data = DataRead(file);
        idx = func_8001E00C(data, (u16)arg1, arg2);
        D_800FB5B0_MusicalMushroom = D_800ECDE0[idx].unk_02;
        HuMemDirectFree(data);
        return idx;
    }
    idx = func_8001E00C((void*)-1, (u16)arg1, arg2);
    if (idx != -1) {
        D_800ECDE0[idx].unk_02 = D_800FB5B0_MusicalMushroom;
    }
    return idx;
}

/* Unused: give model slot `slot` of a player the sprite func_800F9EFC loads. */
void func_800F9FE0_MusicalMushroom(omObjData* obj, u8 slot, s32 file, s32 arg3, s32 arg4, u16 mode) {
    MMPlayerWork* work = obj->unk_50;
    u8 idx = func_800F9EFC_MusicalMushroom(file, arg3, arg4, mode);

    obj->model[slot] = D_800ECDE0[idx].unk_00;
    work->unk_21[slot] = idx;
    func_80025930(D_800ECDE0[idx].unk_00, 0x70000000, 0x70000000);
    func_8001E268(idx, 4, 4);
}

void func_800FA0A0_MusicalMushroom(omObjData* obj) {
    obj->func_ptr = &func_800F9338_MusicalMushroom;
}

void func_800FA0B0_MusicalMushroom(omObjData* obj, Vec3f* pos) {
    unkGlobalStruct_02* work;

    obj->model[0] = func_800174C0(0x1D0001, 0x899);
    obj->trans.x = pos->x;
    obj->trans.y = pos->y;
    obj->trans.z = pos->z;
    obj->unk_50 = func_80023684(sizeof(unkGlobalStruct_02), 31000);
    work = obj->unk_50;
    func_8009B770(work, 0, sizeof(unkGlobalStruct_02));
    obj->func_ptr = NULL;
    func_80008FB8(obj, 0.5f);
    work->unk_04 = 1;
    work->unk_05 = 1;
    func_8000941C(obj, 1.0f, 1.0f, 1.0f);
    func_80009000(obj, 4, 0.0f);
}

void func_800FA170_MusicalMushroom(omObjData* obj, s32 i, f32 angle) {
    unkGlobalStruct_02* work;

    if (D_800FB4FC_MusicalMushroom == 0x80) {
        obj->model[0] = func_800174C0(0x1D0002, 0x899);
        D_800FB4FC_MusicalMushroom = obj->model[0];
    } else {
        obj->model[0] = func_80023FC8((s16)D_800FB4FC_MusicalMushroom);
    }
    obj->trans.x = func_800AEAC0(angle) * 390.0f;
    obj->trans.z = func_800AEFD0(angle) * 390.0f;
    obj->trans.x += 0.0f;
    obj->trans.z += 475.0f;
    D_800FB5C8_MusicalMushroom[i].x = obj->trans.x;
    D_800FB5C8_MusicalMushroom[i].y = 0.0f;
    D_800FB5C8_MusicalMushroom[i].z = obj->trans.z;
    obj->unk_50 = func_80023684(sizeof(unkGlobalStruct_02), 31000);
    work = obj->unk_50;
    func_8009B770(work, 0, sizeof(unkGlobalStruct_02));
    obj->func_ptr = NULL;
    func_80008FB8(obj, 0.5f);
    work->unk_04 = 1;
    work->unk_05 = i + 2;
    func_80009000(obj, 4, 0.0f);
}

void func_800FA2F4_MusicalMushroom(omObjData* obj, s32 dir, s32 file, s32 arg3, f32 angle) {
    u16 player = arg3;
    s32 waitMotions[6] = { 0xF, 0x38, 0x38, 0x38, 0xF, 0x38 };
    MMPlayerWork* work;

    func_80009618(0);
    func_8000979C(obj, dir, file, player, 0xA99, 0xA99);
    obj->model[3] = LoadFormFile(0x19, 0xA8D);
    obj->model[4] = LoadFormFile(0x1A, 0xA8D);
    obj->model[6] = LoadFormFile(0x1B, 0xA8D);
    obj->model[5] = LoadFormFile(0x1C, 0xA8D);
    obj->model[7] = LoadFormFile(0x1E, 0xA8D);
    obj->model[8] = LoadFormFile(0x1D, 0xA8D);
    work = obj->unk_50;
    func_800187D0(obj, 0, dir, 1, 0);
    func_800187D0(obj, 1, dir | 1, 1, 0);
    func_800187D0(obj, 2, dir | 3, 1, 0);
    func_800187D0(obj, 5, dir | 4, 0, 0);
    func_800187D0(obj, 6, dir | 5, 1, 0x13);
    func_800187D0(obj, 8, dir | 9, 1, 0x1D);
    func_800187D0(obj, 0xD, dir | waitMotions[GwPlayer[player].character], 1, 0x78);
    if (rand8() & 1) {
        func_800187D0(obj, 0xE, dir | 0x10, 1, 0x78);
    } else {
        func_800187D0(obj, 0xE, dir | 0x3C, 1, 0x78);
    }
    func_800187D0(obj, 0x11, dir | 0x18, 0, 0);
    func_800187D0(obj, 0x12, dir | 0x1C, 2, 0);
    func_800187D0(obj, 0x15, dir | 0x62, 0, 0);
    func_800187D0(obj, 3, dir | 0x60, 1, 0);
    func_800187D0(obj, 4, dir | 0x61, 1, 0);
    func_800187D0(obj, 0x1E, dir | 0x63, 2, 0);
    func_800187D0(obj, 0x1F, dir | 0x64, 0, 0);
    func_800187D0(obj, 0x20, dir | 0x67, 0, 0);
    func_800090C4(obj, 0, 2);
    func_800090C4(obj, 1, 2);
    func_800090C4(obj, 2, 2);
    func_800090C4(obj, 3, 2);
    func_800090C4(obj, 4, 2);
    func_800090C4(obj, 5, 2);
    func_800090C4(obj, 6, 2);
    func_800090C4(obj, 7, 2);
    obj->work[0] = player;
    obj->work[1] = 0;
    obj->work[2] = 0;
    func_800F76E8_MusicalMushroom(obj);
    obj->trans.x = func_800AEAC0(angle) * 600.0f;
    obj->trans.z = func_800AEFD0(angle) * 600.0f;
    obj->trans.x += 0.0f;
    obj->trans.z += 475.0f;
    func_800F7484_MusicalMushroom(obj, 1.0f, 0.0f, 1);
    obj->func_ptr = &func_800F8AC4_MusicalMushroom;
    work->unk_52 = 0;
    work->unk_38 = 1000.0f;
    work->unk_A4 = 1.0f;
    work->unk_58 = player;
    work->unk_56 = GwPlayer[player].port;
    func_80008FD0(obj, 60.0f);
    func_80008FDC(obj, 150.0f);
    func_80008FE8(obj, 20.0f);
    D_800FB658_MusicalMushroom[player].obj = obj;
    D_800FB658_MusicalMushroom[player].work = work;
    func_800184BC(obj, 2);
}

void func_800FA7C8_MusicalMushroom(omObjData* obj) {
    s16 model;
    unk2C0C0StructC0* m;
    s32 i;

    if (D_800ED430 == 0 && D_800FB4D4_MusicalMushroom != 0) {
        model = obj->model[0];
        m = D_800F2B7C[model].unk_6C;
        if (obj->work[0] != 0) {
            func_800258EC(model, 4, 0);
            for (i = 0; i < m->unk_6A; i++) {
                m->unk_80[i].unk_02 = (16.0f - obj->work[0]) / 16.0f * 255.0f;
            }
            obj->work[0]--;
            return;
        }
        for (i = 0; i < m->unk_6A; i++) {
            m->unk_80[i].unk_02 = 0xFF;
        }
    }
}

void func_800FA914_MusicalMushroom(omObjData* obj, Vec3f* pos, Vec3f* scale) {
    unkGlobalStruct_00* work;
    unk2C0C0StructC0* m;
    s32 i;

    obj->unk_50 = work = func_80023684(sizeof(unkGlobalStruct_00), 31000);
    func_8009B770(work, 0, sizeof(unkGlobalStruct_00));
    if (D_800FB500_MusicalMushroom == 0x80) {
        obj->model[0] = LoadFormFile(0x1D0005, 0x1A8D);
        D_800FB500_MusicalMushroom = obj->model[0];
        func_80025930(obj->model[0], 0x10000, 0x10000);
        m = D_800F2B7C[obj->model[0]].unk_6C;
        for (i = 0; i < m->unk_76; i++) {
            m->unk_A8[i].unk_0C |= 5;
            m->unk_A8[i].unk_0D = 0;
        }
        func_80025AD4(obj->model[0]);
        func_80025B34(obj->model[0]);
    } else {
        obj->model[0] = func_80023FC8((s16)D_800FB500_MusicalMushroom);
    }
    obj->func_ptr = &func_800FA7C8_MusicalMushroom;
    obj->trans.x = pos->x;
    obj->trans.y = pos->y;
    obj->trans.z = pos->z;
    obj->scale.x = scale->x;
    obj->scale.y = scale->y;
    obj->scale.z = scale->z;
    obj->work[0] = 16;
}

void func_800FAAA0_MusicalMushroom(omObjData* obj, Vec3f* pos) {
    unkGlobalStruct_00* work;

    obj->unk_50 = work = func_80023684(sizeof(unkGlobalStruct_00), 31000);
    func_8009B770(work, 0, sizeof(unkGlobalStruct_00));
    if (D_800FB504_MusicalMushroom == 0x80) {
        obj->model[0] = LoadFormFile(0x1D0004, 0x1E19);
        obj->model[1] = LoadFormFile(0x1D0004, 0x1E9D);
        D_800FB504_MusicalMushroom = obj->model[0];
        D_800FB508_MusicalMushroom = obj->model[1];
        obj->func_ptr = NULL;
    } else {
        obj->model[0] = func_80023FC8((s16)D_800FB504_MusicalMushroom);
        obj->model[1] = func_80023FC8((s16)D_800FB508_MusicalMushroom);
        obj->func_ptr = NULL;
    }
    obj->trans.x = pos->x;
    obj->trans.y = pos->y;
    obj->trans.z = pos->z;
    func_80025798(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    obj->scale.x = obj->scale.y = obj->scale.z = 0.7f;
    func_80025830(obj->model[1], obj->scale.x, obj->scale.y, obj->scale.z);
}

void func_800FABE8_MusicalMushroom(omObjData* obj) {
    Vec3f pos;
    Vec3f* p = &pos;

    func_800A0D00(p, 0.0f, 0.0f, 475.0f);
    func_800FA0B0_MusicalMushroom(obj, p);
}

void func_800FAC38_MusicalMushroom(omObjData* obj) {
    func_800FA170_MusicalMushroom(obj, 0, 0.0f);
}

void func_800FAC58_MusicalMushroom(omObjData* obj) {
    func_800FA170_MusicalMushroom(obj, 1, 360.0f / (D_800ED440 - 2));
}

void func_800FACA4_MusicalMushroom(omObjData* obj) {
    func_800FA170_MusicalMushroom(obj, 2, 2.0f * (360.0f / (D_800ED440 - 2)));
}

void func_800FACF4_MusicalMushroom(omObjData* obj) {
    func_800FA170_MusicalMushroom(obj, 3, 360.0f / (D_800ED440 - 2) * 3.0f);
}

void func_800FAD50_MusicalMushroom(omObjData* obj) {
    func_800FA170_MusicalMushroom(obj, 4, 360.0f / (D_800ED440 - 2) * 4.0f);
}

void func_800FADAC_MusicalMushroom(omObjData* obj) {
    func_800FA170_MusicalMushroom(obj, 5, 360.0f / (D_800ED440 - 2) * 5.0f);
}

void func_800FAE08_MusicalMushroom(omObjData* obj) {
    f32 angle = D_800FB50C_MusicalMushroom[D_800FB6B0_MusicalMushroom[0]];

    D_800FB778_MusicalMushroom[0] = angle;
    func_800FA2F4_MusicalMushroom(obj, D_800C59AC[GwPlayer[0].character].unk_00, D_800C59AC[GwPlayer[0].character].unk_04, 0, angle);
}

void func_800FAE74_MusicalMushroom(omObjData* obj) {
    f32 angle = D_800FB50C_MusicalMushroom[D_800FB6B0_MusicalMushroom[1]];

    D_800FB778_MusicalMushroom[1] = angle;
    func_800FA2F4_MusicalMushroom(obj, D_800C59AC[GwPlayer[1].character].unk_00, D_800C59AC[GwPlayer[1].character].unk_04, 1, angle);
}

void func_800FAEE0_MusicalMushroom(omObjData* obj) {
    f32 angle = D_800FB50C_MusicalMushroom[D_800FB6B0_MusicalMushroom[2]];

    D_800FB778_MusicalMushroom[2] = angle;
    func_800FA2F4_MusicalMushroom(obj, D_800C59AC[GwPlayer[2].character].unk_00, D_800C59AC[GwPlayer[2].character].unk_04, 2, angle);
}

void func_800FAF4C_MusicalMushroom(omObjData* obj) {
    f32 angle = D_800FB50C_MusicalMushroom[D_800FB6B0_MusicalMushroom[3]];

    D_800FB778_MusicalMushroom[3] = angle;
    func_800FA2F4_MusicalMushroom(obj, D_800C59AC[GwPlayer[3].character].unk_00, D_800C59AC[GwPlayer[3].character].unk_04, 3, angle);
}

void func_800FAFB8_MusicalMushroom(omObjData* obj) {
    Vec3f pos;
    Vec3f scale;
    Vec3f* p = &pos;
    Vec3f* sc;

    func_800A0D00(p, -330.0f, 0.0f, 64.0f);
    sc = &scale;
    func_800A0D00(sc, 2.0f, 1.0f, 1.0f);
    func_800FA914_MusicalMushroom(obj, p, sc);
}

void func_800FB028_MusicalMushroom(omObjData* obj) {
    Vec3f pos;
    Vec3f scale;
    Vec3f* p = &pos;
    Vec3f* sc;

    func_800A0D00(p, -160.0f, 0.0f, -100.0f);
    sc = &scale;
    func_800A0D00(sc, 1.0f, 1.0f, 1.0f);
    func_800FA914_MusicalMushroom(obj, p, sc);
}

void func_800FB098_MusicalMushroom(omObjData* obj) {
    Vec3f pos;
    Vec3f scale;
    Vec3f* p = &pos;
    Vec3f* sc;

    func_800A0D00(p, 220.0f, 0.0f, 100.0f);
    sc = &scale;
    func_800A0D00(sc, 1.0f, 1.0f, 1.0f);
    func_800FA914_MusicalMushroom(obj, p, sc);
}

void func_800FB108_MusicalMushroom(omObjData* obj) {
    Vec3f pos;
    Vec3f scale;
    Vec3f* p = &pos;
    Vec3f* sc;

    func_800A0D00(p, -570.0f, 0.0f, 621.0f);
    sc = &scale;
    func_800A0D00(sc, 1.0f, 1.0f, 1.0f);
    func_800FA914_MusicalMushroom(obj, p, sc);
}

void func_800FB180_MusicalMushroom(omObjData* obj) {
    Vec3f pos;
    Vec3f scale;
    Vec3f* p = &pos;
    Vec3f* sc;

    func_800A0D00(p, 740.0f, 0.0f, 340.0f);
    sc = &scale;
    func_800A0D00(sc, 1.0f, 1.0f, 1.0f);
    func_800FA914_MusicalMushroom(obj, p, sc);
}

void func_800FB1F0_MusicalMushroom(omObjData* obj) {
    Vec3f pos;
    Vec3f* p = &pos;

    func_800A0D00(p, -500.0f, 0.0f, 1450.0f);
    func_800FAAA0_MusicalMushroom(obj, p);
}

void func_800FB240_MusicalMushroom(omObjData* obj) {
    Vec3f pos;
    Vec3f* p = &pos;

    func_800A0D00(p, 550.0f, 0.0f, 1400.0f);
    func_800FAAA0_MusicalMushroom(obj, p);
}

void func_800FB290_MusicalMushroom(omObjData* obj) {
    Vec3f pos;
    Vec3f* p = &pos;

    func_800A0D00(p, -650.0f, 0.0f, 1250.0f);
    func_800FAAA0_MusicalMushroom(obj, p);
}

void func_800FB2E4_MusicalMushroom(omObjData* obj) {
    Vec3f pos;
    Vec3f* p = &pos;

    func_800A0D00(p, 650.0f, 0.0f, 1150.0f);
    func_800FAAA0_MusicalMushroom(obj, p);
}

void func_800FB338_MusicalMushroom(omObjData* obj) {
    Vec3f pos;
    Vec3f* p = &pos;

    func_800A0D00(p, -780.0f, 0.0f, 350.0f);
    func_800FAAA0_MusicalMushroom(obj, p);
}

void func_800FB384_MusicalMushroom(omObjData* obj) {
    Vec3f pos;
    Vec3f* p = &pos;

    func_800A0D00(p, 820.0f, 0.0f, 300.0f);
    func_800FAAA0_MusicalMushroom(obj, p);
}

void func_800FB3D0_MusicalMushroom(omObjData* obj) {
    Vec3f pos;
    Vec3f* p = &pos;

    func_800A0D00(p, 700.0f, 0.0f, 0.0f);
    func_800FAAA0_MusicalMushroom(obj, p);
}

void func_800FB41C_MusicalMushroom(omObjData* obj) {
    Vec3f pos;
    Vec3f* p = &pos;

    func_800A0D00(p, -400.0f, 0.0f, -150.0f);
    func_800FAAA0_MusicalMushroom(obj, p);
}

void func_800FB468_MusicalMushroom(omObjData* obj) {
    Vec3f pos;
    Vec3f* p = &pos;

    func_800A0D00(p, 100.0f, 0.0f, -300.0f);
    func_800FAAA0_MusicalMushroom(obj, p);
}

