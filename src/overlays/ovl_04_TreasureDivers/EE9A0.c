#include "common.h"
#include "TreasureDivers.h"

s32 func_8000C144(void);
u8 func_80067328(s16 grpIdx, s16 idx);
extern omObjData* D_800F2AF8[];

/* A treasure: its size (50, 75 or 100: 1, 3 or 5 coins) and screen x. */
typedef struct TDTreasureDef {
    /* 0x00 */ s16 size;
    /* 0x02 */ s16 x;
} TDTreasureDef;

/* .data */
s16 D_800FE390_TreasureDivers[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 0 }; /* stage model files */
s16 D_800FE3A4_TreasureDivers[4] = { 0, 1, 2, 3 };
s16 D_800FE3AC_TreasureDivers[4][3] = {
    { -112, -32, -400 },
    { -56, -32, -400 },
    { 56, -32, -400 },
    { 112, -32, -400 },
};
/* A diver's tilt (x, y) facing each quarter turn. */
f32 D_800FE3C4_TreasureDivers[4][2] = {
    { -90.0f, 0.0f },
    { 0.0f, -90.0f },
    { 90.0f, 0.0f },
    { 0.0f, 90.0f },
};
/* Where a carried treasure sits on its diver, per character. */
Vec D_800FE3E4_TreasureDivers[6] = {
    { 0.0f, 3.0f, 12.0f }, { 0.0f, 3.0f, 12.0f }, { 0.0f, 8.0f, -2.0f },
    { 0.0f, 3.0f, 4.0f },  { 0.0f, 6.0f, 8.0f },  { 0.0f, 12.0f, 0.0f },
};
f32 D_800FE42C_TreasureDivers = 0.0f;
s32 D_800FE430_TreasureDivers = 0;
s32 D_800FE434_TreasureDivers = 0;
u32 D_800FE438_TreasureDivers = 0x19971204;
s32 D_800FE43C_TreasureDivers = 0;
s32 D_800FE440_TreasureDivers = 0;
s32 D_800FE444_TreasureDivers[3] = { 0, 100, 220 };
s32 D_800FE450_TreasureDivers[3] = { 30, 30, 30 };
f32 D_800FE45C_TreasureDivers = 0.0f;
f32 D_800FE460_TreasureDivers = 9.0f;
f32 D_800FE464_TreasureDivers = 0.0f;

void func_800F65E0_TreasureDivers(void) {
    omObjData* temp_v0;
    omObjData* temp_v0_4;
    unk_Struct00* temp_s0_2;
    void* temp_v0_3;
    u8 temp_s0;
    s16 i;

    func_80029090(50);
    func_8001DE70(32);
    omInitObjMan(50, 0);
    func_80060088();

    temp_v0 = omAddObj(32730, 0, 0, -1, omOutView);
    omSetStatBit(temp_v0, 160);

    func_800178A0(1);

    temp_s0 = func_800178E8();
    func_80017660(temp_s0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(temp_s0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 45.0f, 80.0f, 8000.0f);

    D_800F2BC0 = 0;
    D_800ED440 = 0;
    D_800FE6F2_TreasureDivers = 0;
    D_800FE6F4_TreasureDivers = 45;
    D_800FE6F8_TreasureDivers = 0;
    D_800FE6F6_TreasureDivers = 1;
    D_800FE6FA_TreasureDivers = 2700;
    D_800FE6FC_TreasureDivers = _CheckFlag(0x2B);

    for (i = 0; i < ARRAY_COUNT(D_800FED40_TreasureDivers); i++) {
        D_800FED40_TreasureDivers[i] = NULL;
    }

    D_800FE702_TreasureDivers = 0;
    D_800FE700_TreasureDivers = 0;
    D_800FE6FE_TreasureDivers = 0;
    D_800FE760_TreasureDivers = -1;
    D_800FF180_TreasureDivers = 0;
    D_800FF25C_TreasureDivers = 0;
    D_800FED30_TreasureDivers = 0;

    temp_v0_3 = DataRead(0x160014);
    func_800FAA34_TreasureDivers(temp_v0_3);
    DataClose(temp_v0_3);
    func_800FA440_TreasureDivers();
    omOutView(temp_v0);

    temp_s0_2 = D_800C3110;
    D_800FF258_TreasureDivers = func_800AEAC0(temp_s0_2->unk_40 / 2.0) / func_800AEFD0(temp_s0_2->unk_40 / 2.0);

    guMtxL2F(D_800FF140_TreasureDivers, &temp_s0_2->unk_138);
    guMtxL2F(D_800FFAE0_TreasureDivers, &temp_s0_2->unk_138);
    func_800FA678_TreasureDivers(D_800FFAE0_TreasureDivers);
    func_800FBB0C_TreasureDivers();

    D_800FE768_TreasureDivers = func_80076FF4(124);
    D_800FF248_TreasureDivers = omAddObj(10, 0, 0, -1, &func_800F6B2C_TreasureDivers);

    D_800F2AF8[D_800ED440++] = temp_v0_4 = omAddObj(2, 9, 0, -1, &func_800F7010_TreasureDivers);
    omSetStatBit(temp_v0_4, 160);

    D_800F2AF8[D_800ED440++] = omAddObj(2, 6, 0, -1, &func_800F7560_TreasureDivers);

    for (i = 0; i < 4; i++) {
        D_800F3FB0[D_800F2BC0++] = omAddObj(3, 1, 50, -1, &func_800F719C_TreasureDivers);
    }

    for (i = 0; i < 10; i++) {
        D_800FED08_TreasureDivers[D_800FF25C_TreasureDivers++] = omAddObj(4, 1, 0, -1, &func_800F75AC_TreasureDivers);
    }

    D_800FF24C_TreasureDivers[D_800FED30_TreasureDivers++] = temp_v0_4 = omAddObj(5, 3, 0, -1, &func_800F7470_TreasureDivers);
    omSetStatBit(temp_v0_4, 160);

    D_800FF24C_TreasureDivers[D_800FED30_TreasureDivers++] = temp_v0_4 = omAddObj(5, 2, 0, -1, &func_800F74E8_TreasureDivers);
    omSetStatBit(temp_v0_4, 160);

    D_800FE764_TreasureDivers = omAddObj(0, 0, 0, -1, &func_800F6F18_TreasureDivers);

    func_800234B8(0, 128, 128, 128);
    func_800234B8(1, 255, 255, 255);
    func_80023504(1, 0.0f, 128.0f, 128.0f);
}

void func_800F6B60_TreasureDivers(omObjData* obj);

void func_800F6B2C_TreasureDivers(omObjData* obj) {
    obj->func_ptr = func_800F6B60_TreasureDivers;
    SetFadeInTypeAndTime(0, 16);
    func_80060128(25);
}

void func_800F6EBC_TreasureDivers(void);

/* The game's flow: intro message, play (45 s), result. */
void func_800F6B60_TreasureDivers(omObjData* obj) {
    switch (D_800FE6F2_TreasureDivers) {
        case 0:
            if (--D_800FE6F4_TreasureDivers == 0) {
                D_800FE6F2_TreasureDivers++;
                D_800FE6F4_TreasureDivers = 60;
                GMesCreate(0);
            }
            break;
        case 1:
            if (--D_800FE6F4_TreasureDivers == 0) {
                D_800FE6F2_TreasureDivers++;
                D_800FE6F6_TreasureDivers = 0;
            }
            break;
        case 2:
            if (D_800FE6F8_TreasureDivers == 0) {
                if (((s16)D_800FE704_TreasureDivers | (s16)D_800FE730_TreasureDivers) == 0) {
                    D_800FE6F8_TreasureDivers = 1;
                    D_800FE6F6_TreasureDivers = 1;
                    D_800FE6F0_TreasureDivers = 10;
                }
                if (D_800FE6F8_TreasureDivers == 0 && D_800FE6FA_TreasureDivers != 0) {
                    D_800FE6FA_TreasureDivers--;
                }
            }
            if (D_800FE6FA_TreasureDivers == 0 || D_800FE6F8_TreasureDivers != 0) {
                if (D_800FE6F0_TreasureDivers == 0) {
                    D_800FE6F6_TreasureDivers = 1;
                    if (D_800FE6FC_TreasureDivers == 0) {
                        D_800FE6F2_TreasureDivers++;
                        if (D_800FE6F8_TreasureDivers == 0) {
                            GMesCreate(16);
                        } else {
                            GMesCreate(2);
                        }
                    } else {
                        D_800FE6F2_TreasureDivers = 5;
                        GMesCreate(2);
                    }
                    func_800601D4(40);
                } else {
                    D_800FE6F0_TreasureDivers--;
                }
            }
            break;
        case 3:
            if (GMesStatAllGet() == 2) {
                D_800FE6F2_TreasureDivers++;
                if (D_800FE6F8_TreasureDivers != 0) {
                    func_80060128(0x36);
                } else if (D_800FE760_TreasureDivers >= 0) {
                    func_80060128(0x3C);
                } else {
                    func_80060128(0x34);
                }
            }
            break;
        case 4:
            if (func_8000C144() != 0x200 && func_8000C144() != 1) {
                D_800FE6F2_TreasureDivers = -1;
                D_800FE6F8_TreasureDivers = -1;
                func_800601D4(40);
                func_800726AC(0, 20);
            }
            break;
        case 5:
            if (GMesStatAllGet() == 2) {
                D_800FE6F2_TreasureDivers++;
                D_800FE6F4_TreasureDivers = 60;
            }
            break;
        case 6:
            if (--D_800FE6F4_TreasureDivers == 0) {
                D_800FE6F2_TreasureDivers = -1;
                D_800FE6F8_TreasureDivers = -1;
                func_80060398(40);
                func_800726AC(0, 20);
            }
            break;
    }
    func_800F9CB0_TreasureDivers();
    func_800FBEC8_TreasureDivers();
    if (D_800F5144 != 0) {
        D_800FE6F8_TreasureDivers = -1;
    }
    func_800F6EBC_TreasureDivers();
}

void func_800F6EBC_TreasureDivers(void) {
    if (D_800FE6F8_TreasureDivers < 0 && func_80072718() == 0) {
        func_800FA594_TreasureDivers();
        func_800FABD0_TreasureDivers();
        func_800FE368_TreasureDivers();
        func_80060198();
        omOvlReturnEx(1);
    }
}

void func_800F6F90_TreasureDivers(omObjData* obj);

/* The timer window. */
void func_800F6F18_TreasureDivers(omObjData* obj) {
    obj->work[0] = GMesCreate(8, (s16)(D_800FE6FA_TreasureDivers / 30), 160, 24);
    obj->func_ptr = func_800F6F90_TreasureDivers;
}

void func_800F6F90_TreasureDivers(omObjData* obj) {
    func_80079078((D_800FE6FA_TreasureDivers + 29) / 30);
    if (D_800FE6FA_TreasureDivers == 0 || D_800FE6F8_TreasureDivers != 0) {
        obj->func_ptr = NULL;
        func_800790C0();
    }
}

void func_800F78BC_TreasureDivers(omObjData* obj);

/* The stage. */
void func_800F7010_TreasureDivers(omObjData* obj) {
    s16 i;

    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 2.0f;
    for (i = 0; i < 9; i++) {
        obj->model[i] = func_800174C0(D_800FE390_TreasureDivers[i] | 0x160000, 0x2D9);
        func_80025798(obj->model[i], obj->trans.x, obj->trans.y, obj->trans.z);
        func_80025830(obj->model[i], obj->scale.x, obj->scale.y, obj->scale.z);
        if (i == 8 || i == 6 || i == 7) {
            func_80025EB4(obj->model[i], 2, 2);
            D_800F2B7C[obj->model[i]].unk_4C = 0.5f;
        }
    }
    func_800FD934_TreasureDivers(obj);
    obj->func_ptr = func_800F78BC_TreasureDivers;
}

void func_800F78D8_TreasureDivers(omObjData* obj);

/* A player's diver. */
void func_800F719C_TreasureDivers(omObjData* obj) {
    TDPlayerWork* pw;
    TDWork* w;
    u8 chr;
    s32 dir;

    chr = GwPlayer[D_800FE3A4_TreasureDivers[D_800FE6FE_TreasureDivers]].character;
    dir = D_800C59AC[chr].unk_00;
    obj->model[0] = LoadFormFile(dir | D_800C59AC[chr].unk_04, 0x299);
    obj->func_ptr = func_800F78D8_TreasureDivers;
    obj->trans.x = D_800FE3AC_TreasureDivers[D_800FE6FE_TreasureDivers][0];
    obj->trans.y = D_800FE3AC_TreasureDivers[D_800FE6FE_TreasureDivers][1];
    obj->trans.z = D_800FE3AC_TreasureDivers[D_800FE6FE_TreasureDivers][2];
    obj->scale.x = obj->scale.y = obj->scale.z = 1.6f;
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80025830(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    obj->unk_50 = func_80023684(0xE8, 0x7918);
    func_8009B770(obj->unk_50, 0, 0xE8);
    pw = obj->unk_50;
    pw->unk_D8 = func_80023684(obj->mtncnt * 0xE8, 0x7918);
    func_8009B770(pw->unk_D8, 0, obj->mtncnt * 0xE8);
    pw->unk_50 = 0;
    pw->unk_52 = 0;
    pw->unk_56 = GwPlayer[D_800FE6FE_TreasureDivers].port;
    pw->unk_C0 = 0xFFFF;
    pw->unk_58 = GwPlayer[D_800FE6FE_TreasureDivers].character;
    pw->unk_AE = 0;
    func_8001874C(obj, 0, dir | 0xC, 1, 0);
    func_8001874C(obj, 1, dir | 0x13, 1, 0);
    func_8001874C(obj, 2, dir | 0x14, 1, 0);
    func_8001874C(obj, 3, dir | 0x16, 2, 0);
    func_8001874C(obj, 4, dir | 0x17, 1, 0x13);
    func_8001874C(obj, 5, dir | 0x24, 2, 0);
    w = func_800FA4A8_TreasureDivers(obj);
    w->unk40 = D_800FE6FE_TreasureDivers++;
}

/* The two boats. */
void func_800F7470_TreasureDivers(omObjData* obj) {
    obj->model[0] = LoadFormFile(0x16000C, 0x299);
    obj->model[1] = LoadFormFile(0x16000D, 0x299);
    func_800FC144_TreasureDivers(obj);
    obj->func_ptr = func_800FC1CC_TreasureDivers;
    D_800FE702_TreasureDivers++;
}

/* The treasure boat. */
void func_800F74E8_TreasureDivers(omObjData* obj) {
    obj->model[0] = LoadFormFile(0x16000A, 0x299);
    obj->model[1] = LoadFormFile(0x16000B, 0x299);
    func_800FC70C_TreasureDivers(obj);
    obj->func_ptr = func_800FC770_TreasureDivers;
    D_800FE702_TreasureDivers++;
}

/* The fish. */
void func_800F7560_TreasureDivers(omObjData* obj) {
    obj->model[0] = LoadFormFile(0x16000E, 0x299);
    func_800FCF5C_TreasureDivers(obj);
    obj->func_ptr = func_800FD00C_TreasureDivers;
}

void func_800F8B98_TreasureDivers(omObjData* obj);

/* A treasure chest. */
void func_800F75AC_TreasureDivers(omObjData* obj) {
    TDTreasureDef defs[10] = {
        { 50, -140 }, { 50, -120 }, { 75, -80 }, { 50, -60 }, { 100, -35 },
        { 75, -10 },  { 100, 20 },  { 100, 55 }, { 75, 100 }, { 50, 125 },
    };
    TDWork* w;
    f32 y;

    obj->func_ptr = func_800F8B98_TreasureDivers;
    y = func_800FB1D4_TreasureDivers(defs[D_800FE700_TreasureDivers].x);
    if (D_800FE700_TreasureDivers == 0) {
        obj->model[0] = LoadFormFile(0x16000F, 0x99);
    } else {
        obj->model[0] = func_80023FC8(D_800FED08_TreasureDivers[0]->model[0]);
    }
    obj->trans.x = defs[D_800FE700_TreasureDivers].x;
    obj->trans.y = y;
    obj->trans.z = -200.0f;
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, -200.0f);
    obj->scale.x = 2.0 * ((f32)defs[D_800FE700_TreasureDivers].size / 100.0);
    obj->scale.y = 2.0 * ((f32)defs[D_800FE700_TreasureDivers].size / 100.0);
    obj->scale.z = 2.0 * ((f32)defs[D_800FE700_TreasureDivers].size / 100.0);
    func_80025830(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    D_800F2B7C[obj->model[0]].unk_4C = 0.0f;
    w = func_800FA4A8_TreasureDivers(obj);
    switch (defs[D_800FE700_TreasureDivers].size) {
        case 50:
            w->unk3E = 1;
            break;
        case 75:
            w->unk3E = 3;
            break;
        case 100:
            w->unk3E = 5;
            break;
    }
    w->unk30 = obj->scale.x;
    D_800FE700_TreasureDivers++;
}

void func_800F78BC_TreasureDivers(omObjData* obj) {
    func_800FD96C_TreasureDivers(obj);
}

s16 func_800FA084_TreasureDivers(omObjData* obj);

// NON_MATCHING: register allocation / scheduling
#ifdef NON_MATCHING
void func_800F78D8_TreasureDivers(omObjData* obj) {
    Matrix4f m;
    Vec v;
    TDPlayerWork* pw;
    TDWork* w;
    TDWork* t;
    unk2C0C0Struct50* s50;
    f32 ang;
    f32 spd;
    f32 target;
    f32 d;
    f32 frac;
    f32 f;
    s32 stick;
    s16 sx;
    s16 sy;
    s16 btn;
    s16 snd;
    s16 q;
    s16 q1;
    s16 r;
    s8 port;

    pw = obj->unk_50;
    w = func_800FA614_TreasureDivers(obj);
    if (w->unk0 >= 0) {
        w->unk0 |= 0x80C0;
        w->unk2 = 3;
        w->unk4 = w->unk6 = 10;
        w->pos.x = D_800F2B7C[obj->model[0]].unk_24;
        w->pos.y = D_800F2B7C[obj->model[0]].unk_28;
        w->pos.z = D_800F2B7C[obj->model[0]].unk_2C;
        w->pos.y = -48.0f;
        w->unk3C = -1;
        w->unk3E = 0;
        w->unk42 = 0;
        w->unk44 = 0;
        w->unk46 = 0;
        w->unk48 = 0;
        w->unk4A = 600;
        w->unk4C = 0;
        w->unk4E = 0;
        w->unk50 = 0;
        w->unk52 = 0;
        w->unk56 = 0;
        w->unk5A = -1;
        return;
    }
    ang = pw->unk_3C;
    port = pw->unk_56;
    spd = pw->unk_40;
    func_80017A60(obj);
    switch (w->unk8) {
        default:
            w->unk18 = w->pos.x;
            w->unk1C = w->pos.y;
            sy = 0;
            if (D_800FE6F6_TreasureDivers == 0) {
                sx = 0;
                if (!(GwPlayer[w->unk40].flags & 1)) {
                    stick = func_80009C90(obj, ContStkX[port], ContStkY[port]);
                    sx = stick >> 16;
                    sy = stick;
                    btn = ContBtn[port] & ~w->unk56;
                    w->unk56 = ContBtn[port];
                } else {
                    btn = func_800FA084_TreasureDivers(obj);
                }
                if (btn & 0x8000) {
                    w->unk20 += 0.4;
                    if (w->unk20 > 2.0) {
                        w->unk20 = 2.0f;
                    }
                    if (w->unk48 == 0) {
                        func_800FBD10_TreasureDivers(0, w->pos.x, w->pos.y, w->unkA);
                        w->unk48 = 4;
                        snd = 0x163;
                        if (w->unk2 & 2) {
                            snd = 0x178;
                        }
                        func_80060618(snd, w->unk40);
                        w->unk58 = 16;
                    } else {
                        w->unk48--;
                        w->unk58 = 16;
                    }
                    if (pw->unk_AE == 0) {
                        func_80060F04(w->unk40, 5, 0, 5);
                        pw->unk_AE = 16;
                    }
                } else if (w->unk58 != 0) {
                    w->unk58--;
                } else {
                    w->unk20 -= 0.1;
                    if (w->unk20 < 0.0) {
                        w->unk20 = 0.0f;
                    }
                }
                if (pw->unk_AE != 0) {
                    pw->unk_AE--;
                }
                if (w->unk5A < 0) {
                    s50 = D_800F2B7C[obj->model[0]].unk_6C->unk_A0;
                    guTranslateF(m, w->pos.x, w->pos.y, 0.0f);
                    MtxRotate(m, -(w->unk24 + s50->unk_44.x - 90.0), w->unk28 + s50->unk_44.y, 0.0f);
                    MtxTranslate(m, 0.0f, 3.0f, 12.0f);
                    w->unk5A = func_800FB3A8_TreasureDivers(m[3][0], m[3][1], 8.0f, 8.0f);
                    if (!(w->unk5A & 0x8000)) {
                        w->unk8 = 1;
                        t = func_800FA614_TreasureDivers(D_800FED08_TreasureDivers[w->unk5A]);
                        t->unk8 = 1;
                        t->unk3C = 16;
                        t->unk5A = w->unk40;
                        func_80060F04(w->unk40, 20, 0, 20);
                        func_80060540(0x344, w->unk40);
                    }
                }
            } else {
                sx = 0;
                w->unk20 = 0.0f;
            }
            if (pw->unk_40 != w->unk20) {
                if (w->unk20 < pw->unk_40) {
                    pw->unk_40 -= 0.08;
                    if (pw->unk_40 < w->unk20) {
                        pw->unk_40 = w->unk20;
                    }
                } else {
                    pw->unk_40 += 0.08;
                    if (w->unk20 < pw->unk_40) {
                        pw->unk_40 = w->unk20;
                    }
                }
            }
            if (w->unk4C != 0) {
                func_800184BC(obj, 1);
            } else if (w->unk8 == 0) {
                if (pw->unk_40 < 0.2) {
                    func_800184BC(obj, 4);
                } else {
                    func_800184BC(obj, 0);
                }
            } else if (w->unk8 == 1) {
                func_800184BC(obj, 0);
            }
            if (w->unk2 & 8) {
                func_80028498(obj->model[0], D_800F2B7C[obj->motion[5]].unk_08, 0);
            } else {
                D_800F2B7C[obj->model[0]].unk_14 = -1;
            }
            if (!(GwPlayer[w->unk40].flags & 1)) {
                target = func_800B0CD8(sx, -sy) + 180.0;
            } else {
                target = w->unk3E;
            }
            if (target >= 360.0) {
                target -= 360.0;
            }
            if (target != ang) {
                d = target - ang;
                if ((d < -180.0f && d < 0.0f) || (d < 180.0f && d > 0.0f)) {
                    ang += 10.0f;
                    d = target - ang;
                    if ((d > -180.0f && d < 0.0f) || (d > 180.0f && d > 0.0f)) {
                        ang = target;
                    }
                    if (ang > 360.0) {
                        ang -= 360.0;
                    }
                } else {
                    ang -= 10.0f;
                    d = target - ang;
                    if ((d < -180.0f && d < 0.0f) || (d < 180.0f && d > 0.0f)) {
                        ang = target;
                    }
                    if (ang < 0.0) {
                        ang += 360.0;
                    }
                }
            }
            pw->unk_3C = ang;
            q = ang / 90.0;
            frac = (ang - q * 90.0) / 90.0;
            q1 = q + 1;
            if (q1 >= 4) {
                q1 = 0;
            }
            w->unk24 = (frac * (D_800FE3C4_TreasureDivers[q1][0] - D_800FE3C4_TreasureDivers[q][0]) +
                        D_800FE3C4_TreasureDivers[q][0]) *
                       (spd / 2.0);
            w->unk28 = frac * (D_800FE3C4_TreasureDivers[q1][1] - D_800FE3C4_TreasureDivers[q][1]) +
                       D_800FE3C4_TreasureDivers[q][1];
            obj->rot.x = w->unk24;
            obj->rot.y = w->unk28;
            obj->rot.z = 0.0f;
            w->pos.x -= func_800AEAC0(ang) * pw->unk_40;
            w->pos.y -= func_800AEFD0(ang) * pw->unk_40;
            if (w->unk50 != 0) {
                if (w->unk50 > 0) {
                    w->unk50--;
                } else {
                    w->unk50++;
                }
            }
            func_800FB79C_TreasureDivers(w, w->pos.x - w->unk18, w->pos.y - w->unk1C);
            func_800FA984_TreasureDivers(0, &w->pos.x, &w->pos.y, &w->pos.z);
            func_800FABFC_TreasureDivers(&w->pos.x, &w->pos.y, 12);
            if (D_800FE6F6_TreasureDivers == 0 && (s8)w->unk0 < 0) {
                r = func_800FB528_TreasureDivers(w);
                if (!(r & 0x8000)) {
                    w->unk0 &= 0xFF3F;
                    if (w->unk8 != 1) {
                        w->unk54 = w->unk8;
                    } else {
                        w->unk54 = 0;
                    }
                    w->unk8 = 3;
                    w->unk44 = (r & 0xF00) ? 60 : 30;
                    func_800184BC(obj, 3);
                    func_80060540(0x145, w->unk40);
                    func_80060F04(w->unk40, 2, 2, 20);
                    func_80060618(0x45F, w->unk40);
                }
            }
            if (w->pos.y < -18.0) {
                if (func_8009B6F0(w->pos.y) == -48.0) {
                    w->unk4E++;
                    w->unk50 = -fabs(func_800AEAC0((s16)w->unk4E * 4.5) * 4.0);
                    if (!(w->unk2 & 2)) {
                        func_800FBD10_TreasureDivers(1, w->pos.x, w->pos.y, 0);
                        func_80060618(0x171, w->unk40);
                    }
                    w->unk2 |= 2;
                    if ((s16)(w->unk4E % 80) == 0 && D_800FE6F6_TreasureDivers == 0) {
                        func_80060618(0x171, w->unk40);
                    }
                } else {
                    w->pos.y += -0.2;
                }
                if (w->pos.y > -44.0) {
                    w->unk4E = 0;
                    if (w->unk2 & 2) {
                        func_800FBD10_TreasureDivers(1, w->pos.x, w->pos.y, 0);
                        func_80060618(0x16A, w->unk40);
                    }
                    w->unk2 &= ~2;
                }
                if (w->pos.y < -34.0) {
                    if (w->unk4C != 0) {
                        w->unk2 &= ~4;
                        w->unk8 = 0;
                        w->unk4C = 0;
                    }
                    w->unk4A = 600;
                }
            } else {
                w->pos.y -= -0.2;
                if ((s8)w->unk0 < 0 && w->unk5A >= 0) {
                    w->pos.y +=
                        (f32)func_800FA614_TreasureDivers(D_800FED08_TreasureDivers[w->unk5A])->unk4E / 96.0;
                }
                if (D_800FE6F6_TreasureDivers == 0) {
                    if (w->unk4A-- == 0) {
                        w->unk2 |= 4;
                        w->unk4C = 180;
                        func_800FBD10_TreasureDivers(3, 0.0f, 0.0f, w->unkA);
                    }
                }
            }
            if (w->unk46 != 0) {
                D_800F2B7C[obj->model[0]].unk_20 ^= 4;
                if (--w->unk46 == 0) {
                    w->unk0 |= 0x80;
                    D_800F2B7C[obj->model[0]].unk_20 &= ~4;
                }
            }
            break;
        case 3:
            if (w->unk44 & 1) {
                w->unk50 = -2;
            } else {
                w->unk50 = 2;
            }
            if (w->unk44-- == 0) {
                w->unk0 |= 0x40;
                w->unk46 = 45;
                w->unk8 = w->unk54;
            }
            break;
        case -1:
            if (w->unk42 == 0) {
                func_800184BC(obj, 2);
                D_800F2B7C[obj->model[0]].unk_20 ^= 4;
                if (w->unk24 != 0.0) {
                    if (w->unk24 > 180.0) {
                        w->unk24 += 10.0f;
                        if (w->unk24 >= 360.0) {
                            w->unk24 = 0.0f;
                        }
                    } else {
                        w->unk24 -= 10.0f;
                        if (w->unk24 < 0.0) {
                            w->unk24 = 0.0f;
                        }
                    }
                }
                w->unk28 += 4.0f;
                w->pos.y -= 0.6;
                if (func_8009B6F0(w->pos.y) == -48.0) {
                    D_800F2B7C[obj->model[0]].unk_20 &= ~4;
                    w->unk42 = 30;
                    func_800184BC(obj, 0);
                }
            } else {
                if (w->unk42 < 9) {
                    f = (f32)w->unk42 / 8.0;
                } else {
                    f = 1.0f;
                }
                w->unk24 = f * -90.0;
                w->unk28 = 0.0f;
                if (--w->unk42 == 0) {
                    w->unk0 |= 0xC0;
                    w->unk2 = (w->unk2 | 1) & ~4;
                    w->unk8 = 0;
                    w->unk46 = 0;
                    w->unk4A = 600;
                    w->unk4C = 0;
                    pw->unk_3C = 0.0f;
                    if (GwPlayer[w->unk40].flags & 1) {
                        w->unk3E = 0;
                        w->unk52 = 0;
                    }
                } else if (w->unk42 == 15) {
                    func_800FBD10_TreasureDivers(5, w->pos.x, w->pos.y, w->unk40);
                }
            }
            if (!(GwPlayer[w->unk40].flags & 1)) {
                func_80009C90(obj, ContStkX[port], ContStkY[port]);
            }
            obj->rot.x = w->unk24;
            obj->rot.y = w->unk28;
            obj->rot.z = 0.0f;
            break;
    }
    if (w->unk4C != 0) {
        if ((s16)(w->unk4C % 30) == 0) {
            func_80060618(0x17F, w->unk40);
        }
        if (--w->unk4C == 0) {
            w->unk0 &= 0xFF7F;
            w->unk2 &= ~1;
            w->unk8 = -1;
            pw->unk_C0 = 0xFFFF;
            func_800184BC(obj, 2);
            D_800F2B7C[obj->model[0]].unk_14 = -1;
            func_80060618(0x187, w->unk40);
        }
        if (!(w->unk4C & 7)) {
            func_800FBD10_TreasureDivers(0, w->pos.x, w->pos.y, w->unkA);
        }
    }
    func_800FA8B8_TreasureDivers(w->pos.x, w->unk50 + w->pos.y, w->pos.z, &v);
    obj->trans.x = v.x;
    obj->trans.y = v.y;
    obj->trans.z = v.z;
    if (w->unk5A < 0) {
        w->unk2 &= ~8;
    } else {
        w->unk2 |= 8;
    }
    func_80017DB0(obj);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_04_TreasureDivers/EE9A0", func_800F78D8_TreasureDivers);
#endif

// NON_MATCHING: register allocation / scheduling
#ifdef NON_MATCHING
void func_800F8B98_TreasureDivers(omObjData* obj) {
    Matrix4f m;
    Vec v;
    TDWork* w;
    TDWork* d;
    omObjData* dobj;
    TDPlayerWork* pw;
    unk2C0C0Struct50* s50;
    f32 oy;
    f32 t;
    f32 sc;

    w = func_800FA614_TreasureDivers(obj);
    if (w->unk0 >= 0) {
        w->unk0 |= 0x8080;
        w->pos.x = D_800F2B7C[obj->model[0]].unk_24;
        w->pos.y = D_800F2B7C[obj->model[0]].unk_28;
        w->pos.z = D_800F2B7C[obj->model[0]].unk_2C;
        sc = D_800F2B7C[obj->model[0]].unk_3C / 2.0;
        w->unk4C = sc * 4.0;
        w->unk4E = sc * sc * 64.0;
        w->unk58 = 24;
        w->unk5A = -1;
        w->unk4 = sc * 12.0;
        w->unk6 = sc * 10.0;
        return;
    }
    switch (w->unk8) {
        case 0:
            oy = w->pos.y;
            if (w->unk1C < (f32)w->unk4E / 32.0) {
                w->unk1C += (f32)w->unk4C / 128.0;
            }
            w->pos.x += w->unk18;
            w->pos.y += w->unk1C;
            t = func_800FB1D4_TreasureDivers(w->pos.x);
            if (t < w->pos.y) {
                w->pos.y = t;
            }
            if (func_800FB620_TreasureDivers(w, w->pos.y - oy) & 0x8000) {
                w->unk18 = 0.0f;
            }
            func_800FA984_TreasureDivers(0, &w->pos.x, &w->pos.y, &w->pos.z);
            w->unk58 = 24;
            obj->scale.x = obj->scale.y = obj->scale.z = w->unk30;
            break;
        case 1:
            if (w->unk58 != 0) {
                w->unk58--;
                sc = (f32)(fabs(func_800AEAC0(w->unk58 * 22.5)) * 0.5 + 1.0) * w->unk30;
                obj->scale.x = obj->scale.y = obj->scale.z = sc;
            }
            d = func_800FA614_TreasureDivers(D_800F3FB0[w->unk5A]);
            if ((u16)d->unk8 >= 3) {
                w->unk8 = 0;
                w->unk5A = -1;
                d->unk5A = -1;
            } else {
                dobj = D_800F3FB0[w->unk5A];
                s50 = D_800F2B7C[dobj->model[0]].unk_6C->unk_A0;
                pw = dobj->unk_50;
                guTranslateF(m, d->pos.x, d->pos.y, 0.0f);
                MtxRotate(m, -(d->unk24 + s50->unk_44.x - 90.0), d->unk28 + s50->unk_44.y, 0.0f);
                MtxTranslate(m, D_800FE3E4_TreasureDivers[pw->unk_58].x, D_800FE3E4_TreasureDivers[pw->unk_58].y,
                             D_800FE3E4_TreasureDivers[pw->unk_58].z);
                if (w->unk3C != 0) {
                    t = (f32)(16 - w->unk3C) / 16.0;
                    w->pos.x = t * (m[3][0] - w->pos.x) + w->pos.x;
                    w->pos.y = t * (m[3][1] - w->pos.y) + w->pos.y;
                    w->unk3C--;
                } else {
                    w->pos.x = m[3][0];
                    w->pos.y = m[3][1];
                }
            }
            if (d->pos.y <= -44.0) {
                w->unk0 &= 0xFF7F;
                w->unk8++;
                d->unk8 = 0;
                d->unk5A = -1;
                obj->scale.x = obj->scale.y = obj->scale.z = w->unk30;
            }
            func_800FA984_TreasureDivers(0, &w->pos.x, &w->pos.y, &w->pos.z);
            break;
        case 2:
            if (w->pos.y > -60.0) {
                w->pos.y -= 1.0;
            } else {
                w->unk8++;
                D_800F2B7C[obj->model[0]].unk_4C = 1.0f;
                w->unk3C = 80;
                PlaySound(0x196);
                GwPlayer[w->unk5A].coins_mg += w->unk3E;
                D_800FE760_TreasureDivers = 1;
            }
            break;
        case 3:
            if (w->unk3C-- == 0) {
                w->unk8 = -1;
            }
            if (w->unk3C < 33 && w->unk3E != 0 && !(w->unk3C & 1)) {
                func_800FBD10_TreasureDivers(4, w->pos.x, w->pos.y - obj->scale.x * 8.0f, 0);
                w->unk3E--;
            }
            if (w->unk3C < 16) {
                D_800F2B7C[obj->model[0]].unk_20 ^= 4;
            }
            break;
    }
    w->unk56 = w->unk8;
    func_800FA8B8_TreasureDivers(w->pos.x, w->pos.y, w->pos.z, &v);
    obj->trans.x = v.x;
    obj->trans.y = v.y;
    obj->trans.z = v.z;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_04_TreasureDivers/EE9A0", func_800F8B98_TreasureDivers);
#endif

/* A bubble. */
void func_800F92A0_TreasureDivers(s16 i) {
    if (D_800FF260_TreasureDivers[i].active >= 0) {
        D_800FF260_TreasureDivers[i].active |= 0x8000;
        func_800674BC(D_800FF260_TreasureDivers[i].sprite, 0, func_800FA640_TreasureDivers() & 1);
        func_80067208(D_800FF260_TreasureDivers[i].sprite, 0, D_800FED00_TreasureDivers.unk0, 0);
        func_800672B0(D_800FF260_TreasureDivers[i].sprite, 0, 0);
        func_800671DC(D_800FF260_TreasureDivers[i].sprite, 0, (func_800FA640_TreasureDivers() & 3) + 15);
    }
    D_800FF260_TreasureDivers[i].x += func_800AEAC0((D_800FF260_TreasureDivers[i].unk10 * 4) % 360);
    D_800FF260_TreasureDivers[i].y -= 1.0;
    func_80067354(D_800FF260_TreasureDivers[i].sprite, 0, 1.0f,
                  func_800AEAC0((D_800FF260_TreasureDivers[i].unk10 << 5) % 360) * 0.125 + 0.875);
    D_800FF260_TreasureDivers[i].unk10++;
    if (D_800FF260_TreasureDivers[i].unk12 != 0) {
        if (--D_800FF260_TreasureDivers[i].unk12 == 0) {
            func_800FBE84_TreasureDivers(i);
        }
        func_8006752C(D_800FF260_TreasureDivers[i].sprite, 0, D_800FF260_TreasureDivers[i].unk12 << 5);
    } else if (D_800FF260_TreasureDivers[i].y <= -32.0) {
        D_800FF260_TreasureDivers[i].unk12 = 8;
    }
}

/* A splash at the surface. */
void func_800F9580_TreasureDivers(s16 i) {
    if (D_800FF260_TreasureDivers[i].active >= 0) {
        D_800FF260_TreasureDivers[i].active |= 0x8000;
        D_800FF260_TreasureDivers[i].unk10 = 60;
        D_800FF260_TreasureDivers[i].y = -57.0f;
        func_80067208(D_800FF260_TreasureDivers[i].sprite, 0, D_800FED00_TreasureDivers.unk0, 3);
        func_80067354(D_800FF260_TreasureDivers[i].sprite, 0, 0.75f, 0.5f);
        return;
    }
    if (func_80067328(D_800FF260_TreasureDivers[i].sprite, 0) & 2) {
        func_800FBE84_TreasureDivers(i);
    }
}

/* A sprite frame shown for one second. */
void func_800F9668_TreasureDivers(s16 i) {
    if (D_800FF260_TreasureDivers[i].active >= 0) {
        D_800FF260_TreasureDivers[i].active |= 0x8000;
        D_800FF260_TreasureDivers[i].unk10 = 60;
        func_80067208(D_800FF260_TreasureDivers[i].sprite, 0, D_800FED00_TreasureDivers.unk0,
                      D_800FF260_TreasureDivers[i].unk6);
        return;
    }
    if (--D_800FF260_TreasureDivers[i].unk10 == 0) {
        func_800FBE84_TreasureDivers(i);
    }
}

/* The air countdown over a diver (unk6: its D_800FED40 index). */
void func_800F9728_TreasureDivers(s16 i) {
    TDWork* w;

    if (D_800FF260_TreasureDivers[i].active >= 0) {
        D_800FF260_TreasureDivers[i].active |= 0x8000;
        D_800FF260_TreasureDivers[i].unk10 = 180;
        if (D_800FF260_TreasureDivers[i].sprite >= 0) {
            func_80067354(D_800FF260_TreasureDivers[i].sprite, 0, 0.8f, 0.8f);
        }
        func_80067208(D_800FF260_TreasureDivers[i].sprite, 0, D_800FE768_TreasureDivers, 0);
    }
    func_800672DC(D_800FF260_TreasureDivers[i].sprite, 0, (D_800FF260_TreasureDivers[i].unk10 - 1) / 30, 0);
    w = D_800FED40_TreasureDivers[D_800FF260_TreasureDivers[i].unk6];
    D_800FF260_TreasureDivers[i].x = w->pos.x;
    D_800FF260_TreasureDivers[i].y = w->pos.y - 24.0f;
    if (--D_800FF260_TreasureDivers[i].unk10 == 0 || !(w->unk2 & 4)) {
        func_800FBE84_TreasureDivers(i);
    }
}

/* A coin jumping out of a treasure. */
// NON_MATCHING: register allocation / scheduling
#ifdef NON_MATCHING
void func_800F98B8_TreasureDivers(s16 i) {
    f32 x0;
    f32 t;
    s32 h;

    if (D_800FF260_TreasureDivers[i].active >= 0) {
        D_800FF260_TreasureDivers[i].active |= 0x8000;
        func_80067208(D_800FF260_TreasureDivers[i].sprite, 0, D_800FED00_TreasureDivers.unk2, 0);
        func_80067354(D_800FF260_TreasureDivers[i].sprite, 0, 0.5f, 0.5f);
        D_800FF260_TreasureDivers[i].unk10 = 24;
        D_800FF260_TreasureDivers[i].unk12 = -(((func_800FA640_TreasureDivers() & 3) + 10) * 8);
        D_800FF260_TreasureDivers[i].unk14 = D_800FF260_TreasureDivers[i].x;
        D_800FF260_TreasureDivers[i].unk16 = 2;
        D_800FF260_TreasureDivers[i].unk18 = D_800FF260_TreasureDivers[i].unk12;
        D_800FF260_TreasureDivers[i].unk1A = (func_800FA640_TreasureDivers() & 0x1F) - 16;
        return;
    }
    t = (24.0 - (f32)D_800FF260_TreasureDivers[i].unk10) / 24.0;
    x0 = D_800FF260_TreasureDivers[i].unk14;
    D_800FF260_TreasureDivers[i].x = x0 + (0.0 - x0) * t;
    D_800FF260_TreasureDivers[i].y += (f32)D_800FF260_TreasureDivers[i].unk12 / 16.0;
    D_800FF260_TreasureDivers[i].unk12 += 8;
    if (D_800FF260_TreasureDivers[i].unk10 != 0) {
        D_800FF260_TreasureDivers[i].unk10--;
    }
    if (D_800FF260_TreasureDivers[i].unk12 > 0 && D_800FF260_TreasureDivers[i].y >= -80.0) {
        if (--D_800FF260_TreasureDivers[i].unk16 == 0) {
            PlaySound(0xFC);
            func_800FBE84_TreasureDivers(i);
            return;
        }
        h = D_800FF260_TreasureDivers[i].unk18 / 2;
        D_800FF260_TreasureDivers[i].unk12 = D_800FF260_TreasureDivers[i].unk18 = h;
        PlaySound(0x108);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_04_TreasureDivers/EE9A0", func_800F98B8_TreasureDivers);
#endif

/* The "+N" over a diver (unk6: its D_800F3FB0 index). */
void func_800F9BAC_TreasureDivers(s16 i) {
    if (D_800FF260_TreasureDivers[i].active >= 0) {
        D_800FF260_TreasureDivers[i].active |= 0x8000;
        D_800FF260_TreasureDivers[i].unk10 = 60;
        D_800FF260_TreasureDivers[i].y = -76.0f;
        func_80067208(D_800FF260_TreasureDivers[i].sprite, 0, D_800FED00_TreasureDivers.unk4, 0);
        return;
    }
    D_800FF260_TreasureDivers[i].x =
        func_800FA614_TreasureDivers(D_800F3FB0[D_800FF260_TreasureDivers[i].unk6])->pos.x;
    if (func_80067328(D_800FF260_TreasureDivers[i].sprite, 0) & 2) {
        func_800FBE84_TreasureDivers(i);
    }
}

/* Lists the free treasures (D_800FE708) and the divers carrying one (D_800FE738). */
// NON_MATCHING: register allocation / scheduling
#ifdef NON_MATCHING
s16 func_800F9CB0_TreasureDivers(void) {
    TDWork* w;
    s16 i;

    D_800FE704_TreasureDivers = 0;
    D_800FE730_TreasureDivers = 0;
    for (i = 0; i < D_800FF25C_TreasureDivers; i++) {
        w = func_800FA614_TreasureDivers(D_800FED08_TreasureDivers[i]);
        if (w->unk8 >= 0) {
            if (w->unk5A < 0) {
                D_800FE708_TreasureDivers[D_800FE704_TreasureDivers++] =
                    func_800FA614_TreasureDivers(D_800FED08_TreasureDivers[i]);
            } else if ((s8)w->unk0 < 0) {
                D_800FE738_TreasureDivers[D_800FE730_TreasureDivers++] =
                    func_800FA614_TreasureDivers(D_800F3FB0[w->unk5A]);
            }
        }
    }
    return -(D_800FE704_TreasureDivers == 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_04_TreasureDivers/EE9A0", func_800F9CB0_TreasureDivers);
#endif

/* Whether the diver faces away (more than 90 degrees) from where its CPU wants to go. */
// NON_MATCHING: register allocation / scheduling
#ifdef NON_MATCHING
s16 func_800F9E08_TreasureDivers(omObjData* obj) {
    s32 d = (s16)((TDPlayerWork*)obj->unk_50)->unk_3C - func_800FA614_TreasureDivers(obj)->unk3E;

    if (d < 0) {
        d = -d;
    }
    d %= 360;
    return -(d > 90);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_04_TreasureDivers/EE9A0", func_800F9E08_TreasureDivers);
#endif

/* The nearest boat within a cone around angle ang (narrower when farther), or -1. */
// register allocation: retail keeps dist & 0xFFFF in one register for lim and the best test (masked 6)
#ifdef NON_MATCHING
s16 func_800F9E9C_TreasureDivers(omObjData* obj, s16 ang) {
    TDWork* w;
    u16 best;
    u16 dist;
    s16 i;
    s16 a;
    s32 lim;
    s32 da;
    f32 dx;
    f32 dy;

    best = 0xFFFF;
    w = func_800FA614_TreasureDivers(obj);
    for (i = 0; i < 3; i++) {
        dx = D_800FF188_TreasureDivers[i].scr.x - w->pos.x;
        dy = D_800FF188_TreasureDivers[i].scr.y - w->pos.y;
        a = (s32)func_800B0CD8(dx, dy) + 180;
        dist = (u32)sqrtf(dx * dx + dy * dy);
        lim = 180 - dist * 2;
        if (lim >= 0) {
            da = a - ang;
            if (da < 0) {
                da = -da;
            }
            if (da % 360 < lim) {
                if (dist < best) {
                    best = dist;
                }
            }
        }
    }
    if (best < 0xFFFF) {
        return best;
    }
    return -1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_04_TreasureDivers/EE9A0", func_800F9E9C_TreasureDivers);
#endif

/* A CPU diver's button presses: steers w->unk3E towards a treasure or a diver carrying one. */
// NON_MATCHING: register allocation / scheduling
#ifdef NON_MATCHING
s16 func_800FA084_TreasureDivers(omObjData* obj) {
    TDPlayerWork* pw;
    TDWork* w;
    TDWork* t;
    s32 btn;
    u32 r;

    btn = 0;
    w = func_800FA614_TreasureDivers(obj);
    pw = obj->unk_50;
    if (w->unk2 & 4) {
        if (w->unk3C >= 0) {
            w->unk3C = -1;
        }
        w->unk3E = 0;
        w->unk52 = 0;
    } else if (w->unk2 & 8) {
        if (w->unk3C >= 0) {
            w->unk3C = -1;
            w->unk3E = 0;
        } else {
            if (w->unk52 == 0 && w->unk46 == 0 && (u16)func_800F9E9C_TreasureDivers(obj, w->unk3E) < 64) {
                w->unk52 = (u32)(func_800FA640_TreasureDivers() & 3) + pw->unk_40 * 4.0;
            }
            if ((func_800FA640_TreasureDivers() & 0xFF) < 4) {
                r = (func_800FA640_TreasureDivers() * 90) >> 16;
                w->unk3E = r - 45;
                if (w->unk3E & 0x8000) {
                    w->unk3E = r + 315;
                }
            }
        }
    } else {
        if (w->unk3C < 0) {
            if (D_800FE704_TreasureDivers != 0) {
                w->unk3C = D_800FE708_TreasureDivers[(func_800FA640_TreasureDivers() * D_800FE704_TreasureDivers) >> 16]->unkA;
                w->unk2 |= 0x10;
            } else {
                w->unk3C = D_800FE738_TreasureDivers[(func_800FA640_TreasureDivers() * D_800FE730_TreasureDivers) >> 16]->unkA;
                w->unk2 &= ~0x10;
            }
        }
        t = D_800FED40_TreasureDivers[w->unk3C];
        if ((w->unk2 & 0x10) && t->unk5A >= 0 && t->unk5A != w->unk40) {
            w->unk3C = -1;
        } else {
            if (!(w->unk2 & 0x10) && (t->unk5A < 0 || D_800FE704_TreasureDivers != 0)) {
                w->unk3C = -1;
            }
            if (w->unk52 == 0) {
                w->unk3E = func_800B0CD8(t->pos.x - w->pos.x, t->pos.y - w->pos.y) + 180;
                if (w->unk46 == 0 && (u16)func_800F9E9C_TreasureDivers(obj, w->unk3E) < 64) {
                    w->unk52 = (u32)(func_800FA640_TreasureDivers() & 3) + pw->unk_40 * 4.0;
                }
            }
        }
    }
    if (func_800F9E08_TreasureDivers(obj) == 0 &&
        (func_800FA640_TreasureDivers() & 0xFF) < GwPlayer[w->unk40].cpu_difficulty * 4 + 28 && w->unk52 == 0) {
        btn = 0x8000;
    }
    if (w->unk52 != 0) {
        w->unk52--;
    }
    return btn;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_04_TreasureDivers/EE9A0", func_800FA084_TreasureDivers);
#endif
