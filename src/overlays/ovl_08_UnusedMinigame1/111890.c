#include "UnusedMinigame1.h"

Vec D_800F9180_UnusedMinigame1[4] = {
    { 422.5f, 298.7f, -45.0f },
    { 422.5f, 298.7f, 155.0f },
    { 422.5f, 298.7f, 355.0f },
    { 422.5f, 298.7f, 555.0f },
};

UM1Files D_800F91B0_UnusedMinigame1[5] = {
    { 0x1A0027, 0x1A0028, 0x1A0015, 0x1A0029, 0x1A002A, 0x1A002B },
    { 0x1A0010, 0x1A0011, 0x1A0015, 0x1A0012, 0x1A0013, 0x1A0014 },
    { 0x1A0021, 0x1A0022, 0x1A0026, 0x1A0023, 0x1A0024, 0x1A0025 },
    { 0x1A001B, 0x1A001C, 0x1A0020, 0x1A001D, 0x1A001E, 0x1A001F },
    { 0x1A0016, 0x1A0017, 0x1A0015, 0x1A0018, 0x1A0019, 0x1A001A },
};

void func_800F6EE0_UnusedMinigame1(void) {
    s32 i;

    D_800F9438_UnusedMinigame1 = 0;
    D_800F943C_UnusedMinigame1 = -1;
    D_800F9430_UnusedMinigame1 = -1;
    D_800F9432_UnusedMinigame1 = -1;
    D_800F9474_UnusedMinigame1 = omAddObj(4, 3, 0, -1, func_800F703C_UnusedMinigame1);
    omSetStatBit(D_800F9474_UnusedMinigame1, 0xA0);
    D_800F944A_UnusedMinigame1 = InitSprite(0x1A000D);
    D_800F9434_UnusedMinigame1 = 0;
    for (i = 0; i < 4; i++) {
        D_800F9480_UnusedMinigame1[i] = omAddObj(8, 1, 8, -1, func_800F7110_UnusedMinigame1);
    }
}

/* The mark's scrolling texture. */
void func_800F6FC8_UnusedMinigame1(omObjData* obj) {
    D_800F9444_UnusedMinigame1 += 1.5f;
    func_80027E48(D_800F9448_UnusedMinigame1, 0.0f, D_800F9444_UnusedMinigame1, D_800F943E_UnusedMinigame1.w,
                  D_800F943E_UnusedMinigame1.h, "11_sita-11m_003", 1);
}

/* The stage: the mark and its scrolling texture. */
void func_800F703C_UnusedMinigame1(omObjData* obj) {
    s16 m;

    obj->model[0] = func_800174C0(0x1A0000, 0x289);
    m = obj->model[1] = func_800174C0(0x1A0001, 0x289);
    func_80025798(m, 0.0f, 0.0f, -25.0f);
    func_80026040(m);
    m = func_800174C0(0x1A0002, 0x289);
    obj->model[2] = m;
    func_80039C48("47mt002_IA44", &D_800F943E_UnusedMinigame1);
    func_80026040(m);
    D_800F9448_UnusedMinigame1 = m;
    D_800F9444_UnusedMinigame1 = 0.0f;
    obj->func_ptr = func_800F6FC8_UnusedMinigame1;
}

/* A character at the top (one per player). */
void func_800F7110_UnusedMinigame1(omObjData* obj) {
    UM1Chara* w;
    s32 player;
    u8 row;
    Vec* pos;
    u16 mdl;
    UM1Files* files;
    void* data;
    s16 tex;

    obj->unk_50 = func_80023684(sizeof(UM1Chara), 0x7918);
    func_8009B770(obj->unk_50, 0, sizeof(UM1Chara));
    w = obj->unk_50;
    player = D_800F9434_UnusedMinigame1;
    row = 4;
    if ((s8)GwPlayer[player].character != 3) {
        row = D_800F9492_UnusedMinigame1[D_800F9438_UnusedMinigame1];
    }
    pos = &D_800F9180_UnusedMinigame1[player];
    mdl = LoadFormFile(0x1A0006, 0x289);
    obj->model[0] = mdl;
    omSetTra(obj, pos->x, pos->y, pos->z);
    omSetSca(obj, 1.5f, 1.5f, 1.5f);
    omSetRot(obj, CRot.x, 0.0f, 0.0f);
    func_80025930(mdl, 0x70000000, 0x70000000);
    func_80025EB4(mdl, 2, 2);
    func_8001775C(obj, 0, 0x1A0006);
    func_8001775C(obj, 1, 0x1A0007);
    func_8001775C(obj, 2, 0x1A0008);
    func_8001775C(obj, 3, 0x1A0009);
    files = &D_800F91B0_UnusedMinigame1[row];
    data = DataRead(files->body1);
    func_80038A9C(D_800F2B7C[(s16)mdl].unk_6C, data, 0, "body1_DEF");
    HuMemDirectFree(data);
    data = DataRead(files->body2);
    func_80038A9C(D_800F2B7C[(s16)mdl].unk_6C, data, 0, "body2_DEF");
    HuMemDirectFree(data);
    data = DataRead(files->arm);
    func_80038A9C(D_800F2B7C[(s16)mdl].unk_6C, data, 0, "arm_DEF");
    HuMemDirectFree(data);
    data = DataRead(files->face);
    tex = func_80038A9C(D_800F2B7C[(s16)mdl].unk_6C, data, 0, "face1_DEF");
    HuMemDirectFree(data);
    w->unk1E = tex;
    if (D_800F9470_UnusedMinigame1 < 0) {
        data = DataRead(0x1A000F);
        tex = func_80038A9C(D_800F2B7C[(s16)mdl].unk_6C, data, 0, "namida_IA44");
        D_800F9470_UnusedMinigame1 = tex;
        HuMemDirectFree(data);
    } else {
        tex = func_80038D5C(D_800F2B7C[(s16)mdl].unk_6C, D_800F9470_UnusedMinigame1, 0, "namida_IA44");
    }
    w->unk20 = tex;
    func_80025AD4(mdl);
    obj->work[0] = player;
    obj->work[1] = row;
    if (D_800F943C_UnusedMinigame1 < 0) {
        mdl = func_800174F4(6, 0x289);
        D_800F943C_UnusedMinigame1 = mdl;
    } else {
        mdl = func_80023FC8(D_800F943C_UnusedMinigame1);
    }
    obj->model[1] = mdl;
    func_800370D4(mdl);
    func_80025798(mdl, pos->x + 10.0f, pos->y, pos->z + -80.0f);
    w->unk1C = 1;
    w->unk24 = func_80019060(D_800F944A_UnusedMinigame1, 0, 1);
    func_80018C90(w->unk24);
    w->x = pos->x;
    w->y = pos->y;
    w->z = pos->z;
    w->unk18 = pos->y;
    w->unkC = 0.0f;
    w->unk10 = 0.0f;
    w->unk14 = 0.0f;
    D_800F9434_UnusedMinigame1++;
    D_800F9438_UnusedMinigame1++;
    obj->func_ptr = func_800F79F0_UnusedMinigame1;
}

/* Knocked off the top: spin and fall. */
void func_800F75A4_UnusedMinigame1(omObjData* obj) {
    UM1Chara* w = obj->unk_50;

    w->unk14 -= 10.0f;
    if (w->unk14 < -180.0f) {
        w->unk14 += 360.0f;
    }
    omSetRot(obj, 0.0f, 0.0f, w->unk14);
    w->unk10 -= 2.0f;
    w->y += w->unk10;
    w->x += w->unkC;
    omSetTra(obj, w->x, w->y, w->z);
    func_80025798(obj->model[1], w->x + 10.0f, w->unk18, w->z + -80.0f);
    if (w->y < -20.0f) {
        w->unk1C = (w->unk1C & ~0x10) | 8;
    }
}

/* The waiting sprite above the character ("!" bubble), pulsing. */
void func_800F76E0_UnusedMinigame1(omObjData* obj) {
    UM1Chara* w = obj->unk_50;
    f32 scr[3];

    if (w->unk2D == 0) {
        switch (w->unk2C) {
            case 0:
                w->unk2D = 30;
                func_800F8FC0_UnusedMinigame1(0, (Vec*)w, scr);
                w->unk26 = (s32)scr[0] + 0x90;
                w->unk28 = (s32)scr[1] + 0x58;
                w->unkC = 0.5f;
                w->unk2A = 0x80;
                func_80018D84(w->unk24, 0x8000);
                ShowBasicSprite(w->unk24);
                w->unk2C = 1;
                if (D_800F9430_UnusedMinigame1 < 0) {
                    D_800F9430_UnusedMinigame1 = obj->work[0];
                }
                if (D_800F9430_UnusedMinigame1 == obj->work[0]) {
                    PlaySound(0);
                }
                break;
            case 1:
                w->unk2C = 2;
                func_80018C90(w->unk24);
                w->unk2D = 15;
                break;
            case 2:
                func_800F8FC0_UnusedMinigame1(0, (Vec*)w, scr);
                w->unk26 = (s32)scr[0] + 0x90;
                w->unk28 = (s32)scr[1] + 0x58;
                w->unkC = 0.5f;
                w->unk2A = 0x80;
                w->unk2C = 1;
                w->unk2D = 30;
                if (D_800F9430_UnusedMinigame1 < 0) {
                    D_800F9430_UnusedMinigame1 = obj->work[0];
                }
                if (D_800F9430_UnusedMinigame1 == obj->work[0]) {
                    PlaySound(0);
                }
                ShowBasicSprite(w->unk24);
                break;
        }
    }
    w->unk2D--;
    if (w->unk2C == 2) {
        return;
    }
    if (w->unk2E < 6) {
        w->unkC += 0.05f;
        w->unk2A -= 8;
        if (w->unk2A > 0x100) {
            w->unk2A = 0;
        }
    } else if (w->unk2E < 8) {
        w->unkC -= 0.05f;
        w->unk2A += 4;
    } else {
        w->unk2E = 0;
    }
    w->unk2E++;
    if (w->unk2F & 1) {
        if (w->unk2F & 0x10) {
            w->unk26++;
        } else {
            w->unk26--;
        }
    }
    w->unk28--;
    w->unk2F++;
    SetBasicSpriteSize(w->unk24, w->unkC, w->unkC);
    SetBasicSpritePos(w->unk24, w->unk26, w->unk28);
    func_80018CF8(w->unk24, (s16)w->unk2A);
}

/* A character: reacts to its machine's result (D_800ED430 1 stretching, 2 result). */
void func_800F79F0_UnusedMinigame1(omObjData* obj) {
    UM1Chara* w = obj->unk_50;
    UM1Machine* m = D_800F9498_UnusedMinigame1[obj->work[0]]->unk_50;
    omObjData* mobj;
    s16 mdl;
    s32 file;
    void* data;
    s32 d;

    if (w->unk1C == 0) {
        return;
    }
    switch (D_800ED430) {
        case 1:
            if (!(w->unk1C & 1)) {
                break;
            }
            if (w->unk1C & 0x10) {
                func_800F75A4_UnusedMinigame1(obj);
                return;
            }
            if (w->unk1C & 8) {
                w->unk1C = 0;
                break;
            }
            if (m->unk10 > 346.0f) {
                if (D_800F9432_UnusedMinigame1 < 0) {
                    D_800F9432_UnusedMinigame1 = obj->work[0];
                }
                if (D_800F9432_UnusedMinigame1 == obj->work[0]) {
                    PlaySound(0);
                }
                w->unk10 = 30.0f;
                w->unkC = 12.0f;
                w->unk1C |= 0x10;
                func_80025830(obj->model[1], 0.8f, 1.0f, 0.8f);
                mdl = obj->model[0];
                func_80025BB8(mdl, obj->motion[3]);
                file = D_800F91B0_UnusedMinigame1[obj->work[1]].faceFar;
                func_800399F0(w->unk1E);
                data = DataRead(file);
                func_80038A9C(D_800F2B7C[mdl].unk_6C, data, 0, "face1_DEF");
                HuMemDirectFree(data);
                func_80025AD4(mdl);
            }
            break;
        case 2:
            if (w->unk1C & 0x10) {
                func_800F75A4_UnusedMinigame1(obj);
                return;
            }
            if (w->unk1C & 2) {
                func_800F76E0_UnusedMinigame1(obj);
                break;
            }
            if (w->unk1C & 8) {
                w->unk1C = 0;
                break;
            }
            w->unk1C = 0;
            mdl = obj->model[0];
            d = 344.0f - m->unk10;
            if (d < 2) {
                func_80025BB8(mdl, obj->motion[2]);
                mobj = D_800F9498_UnusedMinigame1[obj->work[0]];
                func_8002859C(mobj->model[5], obj->model[0], "machi-poly1");
                func_800258EC(mobj->model[5], 0x4000, 0x4000);
                file = D_800F91B0_UnusedMinigame1[obj->work[1]].faceNear;
                w->unk2C = 0;
                w->unk2D = 0;
                w->unk1C = 2;
            } else if (d >= 41) {
                func_80025BB8(mdl, obj->motion[1]);
                func_800399F0(w->unk20);
                if (D_800F9490_UnusedMinigame1 < 0) {
                    data = DataRead(0x1A000E);
                    D_800F9490_UnusedMinigame1 = func_80038A9C(D_800F2B7C[mdl].unk_6C, data, 0, "namida_IA44");
                    HuMemDirectFree(data);
                } else {
                    func_80038D5C(D_800F2B7C[mdl].unk_6C, D_800F9490_UnusedMinigame1, 0, "namida_IA44");
                }
                file = D_800F91B0_UnusedMinigame1[obj->work[1]].faceFar;
            } else {
                file = D_800F91B0_UnusedMinigame1[obj->work[1]].faceNear;
            }
            func_800399F0(w->unk1E);
            data = DataRead(file);
            func_80038A9C(D_800F2B7C[mdl].unk_6C, data, 0, "face1_DEF");
            HuMemDirectFree(data);
            func_80025AD4(mdl);
            break;
        default:
            if (w->unk1C & 2) {
                func_800F76E0_UnusedMinigame1(obj);
            }
            break;
    }
}
