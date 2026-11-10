#include "TipsyTourney.h"

/* .data (0x800FB7B0) */
f32 D_800FB7B0_TipsyTourney = 20.0f;
s16 D_800FB7B4_TipsyTourney = 0;
s16 D_800FB7B8_TipsyTourney[4][5][5] = { { { 0 } } };
Vec3f D_800FB880_TipsyTourney[4] = { { 0 } };
s8 D_800FB8B0_TipsyTourney = -1;
s32 D_800FB8B4_TipsyTourney = 0;
s32 D_800FB8B8_TipsyTourney = 0x744;
s32 D_800FB8BC_TipsyTourney = 0;
s32 D_800FB8C0_TipsyTourney = 0;
Gfx D_800FB8C8_TipsyTourney[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineLERP(TEXEL0, PRIMITIVE, TEXEL0_ALPHA, PRIMITIVE, 0, TEXEL0, PRIMITIVE, TEXEL0, TEXEL0, PRIMITIVE,
                       TEXEL0_ALPHA, PRIMITIVE, 0, TEXEL0, PRIMITIVE, TEXEL0),
    gsDPSetRenderMode(G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2),
    gsDPSetAlphaCompare(G_AC_THRESHOLD),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsSPEndDisplayList(),
};
Vec3f D_800FB908_TipsyTourney[4] = { { 0 } };
f32 D_800FB938_TipsyTourney[4] = { 0 };
Vec3f D_800FB948_TipsyTourney[4] = { { 0 } };
f32 D_800FB978_TipsyTourney[4] = { 0 };
u16 D_800FB988_TipsyTourney[4] = { 0 };
f32 D_800FB990_TipsyTourney[4] = { 1.0f, 1.0f, -1.0f, -1.0f };
s16 D_800FB9A0_TipsyTourney[4] = { 0 };
TipsyDash D_800FB9A8_TipsyTourney[4] = { { 0 } };

void func_800F65E0_TipsyTourney(void) {
    omObjData* obj;

    func_80029090(0x32);
    func_8002ADF0(&D_800EDEC0, 0x40);
    func_8001DE70(0x20);
    omInitObjMan(0x32, 0);
    func_80060088();
    func_8002578C(0);
    func_8000942C();
    func_80017940(5);
    func_800179C0(5);
    func_80017660(0, 0.0f, 0.0f, 156.0f, 116.0f);
    func_800176C4(0, 320.0f, 240.0f, 511.0f, 320.0f, 240.0f, 511.0f);
    func_8001D494(0, 20.0f, 80.0f, 8000.0f);
    func_80017660(1, 164.0f, 0.0f, 324.0f, 120.0f);
    func_800176C4(1, 320.0f, 240.0f, 511.0f, 960.0f, 240.0f, 511.0f);
    func_8001D494(1, 20.0f, 80.0f, 8000.0f);
    func_80017660(2, 0.0f, 124.0f, 156.0f, 240.0f);
    func_800176C4(2, 320.0f, 240.0f, 511.0f, 320.0f, 720.0f, 511.0f);
    func_8001D494(2, 20.0f, 80.0f, 8000.0f);
    func_80017660(3, 164.0f, 124.0f, 320.0f, 240.0f);
    func_800176C4(3, 320.0f, 240.0f, 511.0f, 960.0f, 720.0f, 511.0f);
    func_8001D494(3, 20.0f, 80.0f, 8000.0f);
    func_80017660(4, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(4, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(4, 25.0f, 80.0f, 8000.0f);
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    func_80009500();
    D_800B8994 = 1.0f;
    func_80009618(1);
    func_800090B8(D_800ED440);
    D_800F2AF8[D_800ED440++] = omAddObj(0xC8, 1, 0, -1, func_800F7160_TipsyTourney);
    D_800F2AF8[D_800ED440++] = omAddObj(0xC8, 2, 0, -1, func_800F7354_TipsyTourney);
    D_800F2AF8[D_800ED440++] = omAddObj(0xC8, 2, 0, -1, func_800F7500_TipsyTourney);
    D_800F2AF8[D_800ED440++] = omAddObj(0xC8, 2, 0, -1, func_800F76A8_TipsyTourney);
    D_800F2AF8[D_800ED440++] = omAddObj(0xC8, 2, 0, -1, func_800F7854_TipsyTourney);
    D_800EDE70[D_800EE984++] = omAddObj(0x190, 3, 0, -1, func_800F81C8_TipsyTourney);
    D_800EDE70[D_800EE984++] = omAddObj(0x190, 3, 0, -1, func_800F8278_TipsyTourney);
    D_800EDE70[D_800EE984++] = omAddObj(0x190, 3, 0, -1, func_800F832C_TipsyTourney);
    D_800EDE70[D_800EE984++] = omAddObj(0x190, 3, 0, -1, func_800F83E4_TipsyTourney);
    D_800F3FB0[D_800F2BC0++] = omAddObj(0x12C, 0xA, 0x3C, -1, func_800F7C3C_TipsyTourney);
    D_800F3FB0[D_800F2BC0++] = omAddObj(0x12C, 0xA, 0x3C, -1, func_800F7D4C_TipsyTourney);
    D_800F3FB0[D_800F2BC0++] = omAddObj(0x12C, 0xA, 0x3C, -1, func_800F7E60_TipsyTourney);
    D_800F3FB0[D_800F2BC0++] = omAddObj(0x12C, 0xA, 0x3C, -1, func_800F7F74_TipsyTourney);
    D_800B895C = 10.0f;
    omSetStatBit(omAddObj(0x1F4, 0, 0, -1, func_800F849C_TipsyTourney), 0xA0);
    obj = omAddObj(0x7FDA, 0, 0, -1, omOutViewMulti);
    obj->work[0] = 5;
    omSetStatBit(obj, 0xA0);
    func_80028BE0(1);
}

void func_800F6CA4_TipsyTourney(void) {
    GMesCreate(8, 0x1E, 0xA0, 0x18);
}

void func_800F6CCC_TipsyTourney(void) {
    if (func_80072718() == 0) {
        omOvlReturnEx(1);
    }
}

void func_800F6CF8_TipsyTourney(omObjData* obj, u8 state, u32 time) {
    switch (state) {
    case 0:
        if (time == 0) {
            GMesCreate(0);
        }
        break;
    case 1:
        func_80079078(time / 60);
        break;
    }
}

void func_800F6D60_TipsyTourney(omObjData* obj) {
    func_80009468();
    switch (D_800ED430) {
    case 0:
        if (func_80072718() != 0) {
            return;
        }
        func_800F6CF8_TipsyTourney(obj, D_800ED433, D_800FB8B4_TipsyTourney);
        if (GMesStatAllGet() == 0 || GMesStatAllGet() & 2) {
            func_800F6CA4_TipsyTourney();
            func_80009458();
        }
        D_800FB8B4_TipsyTourney += 2;
        break;
    case 1:
        if (D_800FB8B8_TipsyTourney <= 0) {
            func_80009438();
        }
        func_800F6CF8_TipsyTourney(obj, D_800ED433, D_800FB8B8_TipsyTourney);
        D_800FB8B8_TipsyTourney -= 2;
        break;
    case 2:
        if (D_800FB8BC_TipsyTourney == 0) {
            GMesCreate(_CheckFlag(0x2B) != 0 ? 2 : (D_800FB8B8_TipsyTourney > 0 ? 2 : 0x10));
            func_80028BE0(5);
            func_800601D4(0x28);
            func_800F9800_TipsyTourney();
            func_800790C0();
        }
        func_800F6CF8_TipsyTourney(obj, D_800ED433, D_800FB8BC_TipsyTourney);
        if ((GMesStatAllGet() == 0 || GMesStatAllGet() & 2) && _CheckFlag(0x2B) == 0 &&
            D_800FB7B4_TipsyTourney == 0) {
            func_80060128(D_800FB8B8_TipsyTourney > 0 ? 0x32 : 0x34);
            D_800FB7B4_TipsyTourney++;
        }
        func_800F9898_TipsyTourney();
        D_800FB8BC_TipsyTourney += 2;
        if (D_800FB7B4_TipsyTourney != 0) {
            if (D_800FB8B8_TipsyTourney > 0) {
                if (D_800FB7B4_TipsyTourney == 0x14) {
                    GMesCreate(4, GwPlayer[D_800FB8B0_TipsyTourney].character);
                    func_80060540(GwPlayer[D_800FB8B0_TipsyTourney].character + 0x451, D_800FB8B0_TipsyTourney);
                } else if (D_800FB7B4_TipsyTourney >= 0x68 && (GMesStatAllGet() == 0 || GMesStatAllGet() & 2)) {
                    func_80009448();
                }
            } else if (D_800FB7B4_TipsyTourney == 0x5A) {
                func_80009448();
            }
            D_800FB7B4_TipsyTourney++;
        }
        if (_CheckFlag(0x2B) != 0 && (GMesStatAllGet() == 0 || GMesStatAllGet() & 2)) {
            if (D_800FB7B4_TipsyTourney >= 0x3C) {
                func_80009448();
            }
            D_800FB7B4_TipsyTourney++;
        }
        break;
    case 3:
        if (D_800FB8C0_TipsyTourney == 0) {
            func_800601D4(0x28);
        }
        func_800726AC(0, 0x14);
        obj->func_ptr = func_800F6CCC_TipsyTourney;
        func_800F6CF8_TipsyTourney(obj, D_800ED433, D_800FB8BC_TipsyTourney);
        D_800FB8C0_TipsyTourney += 2;
        break;
    }
    if (D_800F5144 == 1) {
        omOvlReturnEx(1);
        func_80009730();
        func_800601D4(0x28);
    }
}

void func_800F7160_TipsyTourney(omObjData* obj) {
    TipsyBgWork* work;

    obj->model[0] = func_800174C0(0x340002, 0x499);
    obj->unk_50 = work = func_80023684(0x2C, 0x7918);
    func_8009B770(work, 0, 0x2C);
    obj->func_ptr = func_800F6D60_TipsyTourney;
    work->unk_04 = 1;
    func_80009000(obj, 2, -400.0f);
    func_80008FB8(obj, 0.6f);
    func_80008FC4(obj, 25.0f);
    work->unk_05 = 0;
    SetFadeInTypeAndTime(0, 0x10);
    func_80060128(0x1D);
    CenterM[0].x = 1000.0f;
    CenterM[0].y = 500.0f;
    CenterM[0].z = 600.0f;
    CRotM[0].x = 320.0f;
    CRotM[0].y = 0.0f;
    CRotM[0].z = 0.0f;
    CZoomM[0] = 750.0f;
    CenterM[1].x = -1000.0f;
    CenterM[1].y = 500.0f;
    CenterM[1].z = 600.0f;
    CRotM[1].x = 320.0f;
    CRotM[1].y = 0.0f;
    CRotM[1].z = 0.0f;
    CZoomM[1] = 750.0f;
    CenterM[2].x = 3000.0f;
    CenterM[2].y = 500.0f;
    CenterM[2].z = 600.0f;
    CRotM[2].x = 320.0f;
    CRotM[2].y = 0.0f;
    CRotM[2].z = 0.0f;
    CZoomM[2] = 750.0f;
    CenterM[3].x = -3000.0f;
    CenterM[3].y = 500.0f;
    CenterM[3].z = 600.0f;
    CRotM[3].x = 320.0f;
    CRotM[3].y = 0.0f;
    CRotM[3].z = 0.0f;
    CZoomM[3] = 750.0f;
    CenterM[4].x = 0.0f;
    CenterM[4].y = 0.0f;
    CenterM[4].z = 0.0f;
    CRotM[4].x = 270.0f;
    CRotM[4].y = 0.0f;
    CRotM[4].z = 0.0f;
    CZoomM[4] = 180.0f;
    func_80025F10(obj->model[0], 0x10);
}

void func_800F7354_TipsyTourney(omObjData* obj) {
    TipsyBgWork* work;

    omSetStatBit(obj, 0xA0);
    obj->model[0] = func_800174C0(0x340000, 0x208D9);
    obj->model[1] = func_800174C0(0x340001, 0x889);
    obj->trans.x = 1000.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    obj->unk_50 = work = func_80023684(0x2C, 0x7918);
    func_8009B770(work, 0, 0x2C);
    obj->func_ptr = func_800FA074_TipsyTourney;
    work->unk_04 = 1;
    func_80009028(obj, 0x40A00000, -250.0f, -250.0f, 250.0f, 250.0f);
    func_800090A4(obj);
    func_80008FB8(obj, 0.3f);
    func_8000941C(obj, 1.0f, 1.0f, 1.0f);
    func_80008FC4(obj, 25.0f);
    work->unk_05 = 1;
    func_80025798(obj->model[1], obj->trans.x, obj->trans.y + 5.0f, obj->trans.z);
    func_80025F10(obj->model[0], 1);
    func_80025F10(obj->model[1], 1);
    func_80025930(obj->model[1], 0x20000, 0x20000);
    func_80025AD4(obj->model[1]);
    func_80026040(obj->model[1]);
    func_800F9980_TipsyTourney(obj->model[1], work->unk_05 - 1);
    func_80009090(obj);
}

void func_800F7500_TipsyTourney(omObjData* obj) {
    TipsyBgWork* work;

    omSetStatBit(obj, 0xA0);
    obj->model[0] = func_800174C0(0x340000, 0x208D9);
    obj->model[1] = func_800174C0(0x340001, 0x889);
    obj->trans.x = -1000.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    obj->unk_50 = work = func_80023684(0x2C, 0x7918);
    func_8009B770(work, 0, 0x2C);
    obj->func_ptr = func_800FA074_TipsyTourney;
    work->unk_04 = 1;
    func_80009028(obj, 0x40A00000, -250.0f, -250.0f, 250.0f, 250.0f);
    func_800090A4(obj);
    func_80008FB8(obj, 0.3f);
    func_8000941C(obj, 1.0f, 1.0f, 1.0f);
    func_80008FC4(obj, 25.0f);
    work->unk_05 = 2;
    func_80025798(obj->model[1], obj->trans.x, obj->trans.y + 5.0f, obj->trans.z);
    func_80025F10(obj->model[0], 2);
    func_80025F10(obj->model[1], 2);
    func_80025930(obj->model[1], 0x20000, 0x20000);
    func_80025AD4(obj->model[1]);
    func_80026040(obj->model[1]);
    func_800F9980_TipsyTourney(obj->model[1], work->unk_05 - 1);
    func_80009090(obj);
}

void func_800F76A8_TipsyTourney(omObjData* obj) {
    TipsyBgWork* work;

    omSetStatBit(obj, 0xA0);
    obj->model[0] = func_800174C0(0x340000, 0x208D9);
    obj->model[1] = func_800174C0(0x340001, 0x889);
    obj->trans.x = 3000.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    obj->unk_50 = work = func_80023684(0x2C, 0x7918);
    func_8009B770(work, 0, 0x2C);
    obj->func_ptr = func_800FA074_TipsyTourney;
    work->unk_04 = 1;
    func_80009028(obj, 0x40A00000, -250.0f, -250.0f, 250.0f, 250.0f);
    func_800090A4(obj);
    func_80008FB8(obj, 0.3f);
    func_8000941C(obj, 1.0f, 1.0f, 1.0f);
    func_80008FC4(obj, 25.0f);
    work->unk_05 = 3;
    func_80025798(obj->model[1], obj->trans.x, obj->trans.y + 5.0f, obj->trans.z);
    func_80025F10(obj->model[0], 4);
    func_80025F10(obj->model[1], 4);
    func_80025930(obj->model[1], 0x20000, 0x20000);
    func_80025AD4(obj->model[1]);
    func_80026040(obj->model[1]);
    func_800F9980_TipsyTourney(obj->model[1], work->unk_05 - 1);
    func_80009090(obj);
}

void func_800F7854_TipsyTourney(omObjData* obj) {
    TipsyBgWork* work;

    omSetStatBit(obj, 0xA0);
    obj->model[0] = func_800174C0(0x340000, 0x208D9);
    obj->model[1] = func_800174C0(0x340001, 0x889);
    obj->trans.x = -3000.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    obj->unk_50 = work = func_80023684(0x2C, 0x7918);
    func_8009B770(work, 0, 0x2C);
    obj->func_ptr = func_800FA074_TipsyTourney;
    work->unk_04 = 1;
    func_80009028(obj, 0x40A00000, -250.0f, -250.0f, 250.0f, 250.0f);
    func_800090A4(obj);
    func_80008FB8(obj, 0.3f);
    func_8000941C(obj, 1.0f, 1.0f, 1.0f);
    func_80008FC4(obj, 25.0f);
    work->unk_05 = 4;
    func_80025798(obj->model[1], obj->trans.x, obj->trans.y + 5.0f, obj->trans.z);
    func_80025F10(obj->model[0], 8);
    func_80025F10(obj->model[1], 8);
    func_80025930(obj->model[1], 0x20000, 0x20000);
    func_80025AD4(obj->model[1]);
    func_80026040(obj->model[1]);
    func_800F9980_TipsyTourney(obj->model[1], work->unk_05 - 1);
    func_80009090(obj);
}

void func_800F7A00_TipsyTourney(omObjData* obj, s32 dir, s32 file0, s32 file1, s32 idx, f32 x, f32 y, f32 z) {
    TipsyWork* work;
    s32 motion;
    s32 motion2;
    s32 attr = 0x20A99;

    func_8000979C(obj, dir, file0, idx, attr, attr);
    work = obj->unk_50;
    obj->model[3] = LoadFormFile(0x19, 0xA8D);
    obj->model[4] = LoadFormFile(0x1A, 0xA8D);
    obj->model[5] = LoadFormFile(0x1C, 0xA8D);
    motion = ((rand8() & 0xFF) >= 0x80U) ? 0xF : 0x38;
    motion2 = ((rand8() & 0xFF) < 0x80U) ? 0x3C | 0x10 : 0x10;
    func_800187D0(obj, 0, dir, 1, 0);
    func_800187D0(obj, 1, dir | 1, 1, 0);
    func_800187D0(obj, 2, dir | 3, 1, 0);
    func_800187D0(obj, 6, dir | 5, 1, 0x13);
    func_800187D0(obj, 0xD, dir | motion, 1, 0x78);
    func_800187D0(obj, 0xE, dir | motion2, 1, 0x78);
    func_800187D0(obj, 0x11, dir | 0x18, 0, 0);
    func_800187D0(obj, 0x15, dir | 0x62, 0, 0);
    func_800187D0(obj, 3, dir | 0x60, 1, 0);
    func_800187D0(obj, 4, dir | 0x61, 1, 0);
    func_800187D0(obj, 0x20, dir | 0x67, 0, 0);
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = z;
    obj->func_ptr = func_800F8800_TipsyTourney;
    work->unk_DC = func_800FB634_TipsyTourney;
    func_800090C4(obj, 0, 2);
}

void func_800F7C3C_TipsyTourney(omObjData* obj) {
    s32 file = D_800C59AC[GwPlayer[0].character].unk_04;
    s32 dir = D_800C59AC[GwPlayer[0].character].unk_00;

    func_800F7A00_TipsyTourney(obj, dir, file, file, 0, 1150.0f, 0.0f, 150.0f);
    func_800090C4(obj, 1, 2);
    func_800090C4(obj, 2, 1);
    func_800090C4(obj, 3, 1);
    func_800090C4(obj, 4, 1);
    func_80025F10(obj->model[0], 1);
    func_80025F10(obj->model[1], 1);
    func_80025F10(obj->model[3], 1);
    func_80025F10(obj->model[4], 1);
    func_80025F10(obj->model[5], 1);
}

void func_800F7D4C_TipsyTourney(omObjData* obj) {
    s32 file = D_800C59AC[GwPlayer[1].character].unk_04;
    s32 dir = D_800C59AC[GwPlayer[1].character].unk_00;

    func_800F7A00_TipsyTourney(obj, dir, file, file, 1, -850.0f, 0.0f, 150.0f);
    func_800090C4(obj, 1, 1);
    func_800090C4(obj, 2, 2);
    func_800090C4(obj, 3, 1);
    func_800090C4(obj, 4, 1);
    func_80025F10(obj->model[0], 2);
    func_80025F10(obj->model[1], 2);
    func_80025F10(obj->model[3], 2);
    func_80025F10(obj->model[4], 2);
    func_80025F10(obj->model[5], 2);
}

void func_800F7E60_TipsyTourney(omObjData* obj) {
    s32 file = D_800C59AC[GwPlayer[2].character].unk_04;
    s32 dir = D_800C59AC[GwPlayer[2].character].unk_00;

    func_800F7A00_TipsyTourney(obj, dir, file, file, 2, 2850.0f, 0.0f, 150.0f);
    func_800090C4(obj, 1, 1);
    func_800090C4(obj, 2, 1);
    func_800090C4(obj, 3, 2);
    func_800090C4(obj, 4, 1);
    func_80025F10(obj->model[0], 4);
    func_80025F10(obj->model[1], 4);
    func_80025F10(obj->model[3], 4);
    func_80025F10(obj->model[4], 4);
    func_80025F10(obj->model[5], 4);
}

void func_800F7F74_TipsyTourney(omObjData* obj) {
    s32 file = D_800C59AC[GwPlayer[3].character].unk_04;
    s32 dir = D_800C59AC[GwPlayer[3].character].unk_00;

    func_800F7A00_TipsyTourney(obj, dir, file, file, 3, -3150.0f, 0.0f, 150.0f);
    func_800090C4(obj, 1, 1);
    func_800090C4(obj, 2, 1);
    func_800090C4(obj, 3, 1);
    func_800090C4(obj, 4, 2);
    func_80025F10(obj->model[0], 8);
    func_80025F10(obj->model[1], 8);
    func_80025F10(obj->model[3], 8);
    func_80025F10(obj->model[4], 8);
    func_80025F10(obj->model[5], 8);
}

void func_800F8088_TipsyTourney(omObjData* obj, s32 file, f32 scale, f32 angle, f32 x, f32 y, f32 z, s32 idx) {
    TipsyBallWork* work;

    obj->unk_50 = func_80023684(0x6C, 0x7918);
    func_8009B770(obj->unk_50, 0, 0x6C);
    obj->func_ptr = func_800FA880_TipsyTourney;
    work = obj->unk_50;
    obj->model[0] = LoadFormFile(file, 0x899);
    obj->model[1] = 0;
    obj->model[2] = LoadFormFile(0x1D, 0x88D);
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = z;
    work->unk_44 = 0.1f;
    work->unk_48 = 45.0f;
    work->unk_34 = 45.0f;
    work->unk_3C = angle;
    work->unk_52 = 7;
    work->unk_5C = idx;
    work->unk_54 = 1;
    func_8000941C(obj, scale, scale, scale);
}

void func_800F81C8_TipsyTourney(omObjData* obj) {
    func_800F8088_TipsyTourney(obj, 0x340003, 1.5f, 180.0f, 1000.0f, 0.0f, 0.0f, 0);
    func_80025F10(obj->model[0], 1);
    func_80025F10(obj->model[2], 1);
    func_800090C4(obj, 1, 2);
    func_800090C4(obj, 2, 1);
    func_800090C4(obj, 3, 1);
    func_800090C4(obj, 4, 1);
}

void func_800F8278_TipsyTourney(omObjData* obj) {
    func_800F8088_TipsyTourney(obj, 0x340003, 1.5f, 180.0f, -1000.0f, 0.0f, 0.0f, 1);
    func_80025F10(obj->model[0], 2);
    func_80025F10(obj->model[2], 2);
    func_800090C4(obj, 1, 1);
    func_800090C4(obj, 2, 2);
    func_800090C4(obj, 3, 1);
    func_800090C4(obj, 4, 1);
}

void func_800F832C_TipsyTourney(omObjData* obj) {
    func_800F8088_TipsyTourney(obj, 0x340003, 1.5f, 180.0f, 3000.0f, 0.0f, 0.0f, 2);
    func_80025F10(obj->model[0], 4);
    func_80025F10(obj->model[2], 4);
    func_800090C4(obj, 1, 1);
    func_800090C4(obj, 2, 1);
    func_800090C4(obj, 3, 2);
    func_800090C4(obj, 4, 1);
}

void func_800F83E4_TipsyTourney(omObjData* obj) {
    func_800F8088_TipsyTourney(obj, 0x340003, 1.5f, 180.0f, -3000.0f, 0.0f, 0.0f, 3);
    func_80025F10(obj->model[0], 8);
    func_80025F10(obj->model[2], 8);
    func_800090C4(obj, 1, 1);
    func_800090C4(obj, 2, 1);
    func_800090C4(obj, 3, 1);
    func_800090C4(obj, 4, 2);
}

void func_800F849C_TipsyTourney(omObjData* obj) {
    D_800FBB20_TipsyTourney = func_80019060((s16)InitSprite(0x340004), 0, 1);
    func_80018C90(D_800FBB20_TipsyTourney);
    obj->work[1] = 0;
    obj->func_ptr = func_800F8500_TipsyTourney;
}

void func_800F8500_TipsyTourney(void) {
    unk65770Obj* spr;
    unk65770AnimC* frame;
    s16 i;
    s16 x;
    s16 y;

    spr = func_800675F4(D_800FBB20_TipsyTourney, 0);
    frame = &spr->unk4C->unk0[spr->unk52];
    gSPDisplayList(D_800F37DC++, D_800FB8C8_TipsyTourney);
    gDPSetTextureLUT(D_800F37DC++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(D_800F37DC++, spr->unk4C->unkC);
    for (i = 0; i < 6; i++) {
        func_8003A060(&D_800F37DC, (s32)(frame->unk0 + i * 0x320), G_IM_FMT_CI, G_IM_SIZ_8b, 80, 60, 0, 0, 80, 10,
                      0, 2, 2, 0, 0, 0, 0);
        for (y = i * 10; y < 240; y += 60) {
            for (x = 0; x < 320; x += 80) {
                gSPTextureRectangle(D_800F37DC++, x * 4, y * 4, (x + 80) * 4, (y + 10) * 4, G_TX_RENDERTILE, 0, 0,
                                    0x400, 0x400);
            }
        }
    }
}

void func_800F8800_TipsyTourney(omObjData* obj) {
    TipsyWork* work = obj->unk_50;
    u16* btn;
    u16 savedTrg;
    u16 savedBtn;
    s32 savedX;
    s32 savedY;
    s32 player;
    f32 cx;
    f32 dx;
    f32 dy;
    f32 dz;

    switch (D_800ED430) {
    case 1:
        if (GwPlayer[work->unk_58].flags & 1) {
            player = work->unk_56;
            savedTrg = ContBtnTrg[player];
            btn = &ContBtn[player];
            savedBtn = *btn;
            savedX = ContStkX[player];
            savedY = ContStkY[player];
            ContStkY[player] = 0;
            ContStkX[player] = 0;
            ContBtnTrg[player] = 0;
            *btn = 0;
            func_800FAC80_TipsyTourney(obj);
            func_80005A28(obj);
            ContBtnTrg[player] = savedTrg;
            *btn = savedBtn;
            ContStkX[player] = savedX;
            ContStkY[player] = savedY;
            return;
        }
        break;
    case 2:
        player = work->unk_58;
        if (D_800FB7B4_TipsyTourney != 0 && _CheckFlag(0x2B) == 0 && work->unk_38 == 1000.0f) {
            if (player == D_800FB8B0_TipsyTourney) {
                func_800184BC(obj, 0xD);
            } else {
                func_800184BC(obj, 0xE);
            }
        }
        work->unk_40 = D_800B8990;
        work->unk_3C = 0.0f;
        CZoomM[player] -= CZoomM[player] * 0.01f;
        if (CZoomM[player] < 600.0f) {
            CZoomM[player] = 600.0f;
        }
        cx = CenterM[player].x;
        dx = cx - obj->trans.x;
        dy = CenterM[player].y - obj->trans.y;
        dz = CenterM[player].z - obj->trans.z;
        if (dx > 20.0f) {
            CenterM[player].x = cx - dx * 0.05f;
        } else if (dx < -20.0f) {
            CenterM[player].x -= dx * 0.05f;
        }
        if (dy > 100.0f) {
            goto movey;
        }
        if (dy < -100.0f) {
        movey:
            CenterM[player].y -= dy * 0.05f;
        }
        if (dz > 100.0f) {
            goto movez;
        }
        if (dz < -100.0f) {
        movez:
            CenterM[player].z -= dz * 0.05f;
        }
        CRotM[player].x += 0.5f;
        if (CRotM[player].x > 330.0f) {
            CRotM[player].x = 330.0f;
        }
        break;
    }
    func_80005A28(obj);
}

void func_800F8C2C_TipsyTourney(omObjData* obj, f32 dx, f32 dz) {
    if (func_8005FD5C() + D_800F64F8 == 0) {
        obj->rot.x += dx;
        obj->rot.z += dz;
        if (obj->rot.x > 15.0f) {
            obj->rot.x = 15.0f;
        }
        if (obj->rot.x < -15.0f) {
            obj->rot.x = -15.0f;
        }
        if (obj->rot.z > 15.0f) {
            obj->rot.z = 15.0f;
        }
        if (obj->rot.z < -15.0f) {
            obj->rot.z = -15.0f;
        }
    }
}

f32 func_800F8D2C_TipsyTourney(omObjData* obj) {
    Matrix4f m;
    Matrix4f inv;
    Vec3f pos;
    f32 tilt;
    f32 acc;
    f32 d;
    f32 a;
    f32 x;
    f32 z;
    s16 i;
    u8 plat;
    omObjData* p;

    acc = 0.0f;
    plat = TIPSY_BG(obj)->unk_05;
    tilt = obj->rot.x;
    for (i = 0; i < D_800F2BC0; i++) {
        p = D_800F3FB0[i];
        if (TIPSY_WORK(p)->unk_53 == plat) {
            pos.x = p->trans.x;
            pos.y = p->trans.y;
            pos.z = p->trans.z;
            func_8000A1C0(m, inv, &pos, obj);
            x = pos.x;
            z = pos.z;
            d = func_800B1750(x * x + z * z);
            if (d != 0.0f) {
                a = func_800B0CD8(pos.x, -pos.z);
                if ((a > 120.0f) | (a < -120.0f)) {
                    acc += d / 400.0f;
                } else if ((a < 60.0f) & (a > -60.0f)) {
                    acc += -d / 400.0f;
                }
            }
            break;
        }
    }
    if ((fabsf(tilt) > 15.0f) & (acc != 0.0f)) {
        acc = 0.0f;
    } else if ((tilt != 0.0f) & (acc == 0.0f)) {
        acc = -tilt / 15.0f;
    }
    return acc;
}

f32 func_800F8FE0_TipsyTourney(omObjData* obj) {
    Matrix4f m;
    Matrix4f inv;
    Vec3f pos;
    f32 tilt;
    f32 acc;
    f32 d;
    f32 a;
    f32 x;
    f32 z;
    s16 i;
    u8 plat;
    omObjData* p;

    acc = 0.0f;
    plat = TIPSY_BG(obj)->unk_05;
    tilt = obj->rot.z;
    for (i = 0; i < D_800F2BC0; i++) {
        p = D_800F3FB0[i];
        if (TIPSY_WORK(p)->unk_53 == plat) {
            pos.x = p->trans.x;
            pos.y = p->trans.y;
            pos.z = p->trans.z;
            func_8000A1C0(m, inv, &pos, obj);
            x = pos.x;
            z = pos.z;
            d = func_800B1750(x * x + z * z);
            if (d != 0.0f) {
                a = func_800B0CD8(pos.x, -pos.z);
                if ((a < 150.0f) & (a > 30.0f)) {
                    acc += -d / 400.0f;
                } else if ((a > -150.0f) & (a < -30.0f)) {
                    acc += d / 400.0f;
                }
            }
            break;
        }
    }
    if ((fabs(tilt) > 15.0) & (acc != 0.0f)) {
        acc = 0.0f;
    } else if ((tilt != 0.0f) & (acc == 0.0f)) {
        acc = -tilt / 15.0f;
    }
    return acc;
}

void func_800F9290_TipsyTourney(omObjData* obj) {
    TipsyBgWork* work = obj->unk_50;
    s32 r;
    s32 c;
    s32 n;
    omObjData* ball;
    TipsyBallWork* bw;

    for (r = 0, n = 0; r < 5; r++) {
        for (c = 0; c < 5; c++) {
            n += D_800FB7B8_TipsyTourney[work->unk_05 - 1][r][c] != 0;
        }
    }
    if (n == 25) {
        func_80009438();
        if (D_800FB8B0_TipsyTourney == -1) {
            D_800FB8B0_TipsyTourney = work->unk_05 - 1;
            GwPlayer[work->unk_05 - 1].coins_mg += 10;
            for (n = 0; n < D_800EE984; n++) {
                ball = D_800EDE70[n];
                bw = ball->unk_50;
                if (bw->unk_54 != 0) {
                    bw->unk_54 = 0;
                    func_800258EC(ball->model[0], 4, 4);
                    func_800258EC(ball->model[2], 4, 0);
                    func_80025798(ball->model[2], ball->trans.x, ball->trans.y + 50.0f, ball->trans.z);
                    func_80025CA8(ball->model[2], 0.0f);
                }
            }
        }
    }
}

// address association: retail hoists D_800FB7B8 - 0x32 into a saved register and adds the tile offset to it (masked ~10, 2 instructions shorter)
#ifdef NON_MATCHING
void func_800F9454_TipsyTourney(omObjData* obj) {
    TipsyBgWork* work = obj->unk_50;
    u8 plat = work->unk_05;
    s16 i;
    omObjData* ball;
    TipsyBallWork* bw;
    Vec3f pos;
    f32 fx;
    f32 fz;
    s16 cx;
    s16 cz;
    s16* tile;

    for (i = 0; i < D_800EE984; i++) {
        ball = D_800EDE70[i];
        bw = ball->unk_50;
        if (bw->unk_53 == plat) {
            pos.x = ball->trans.x;
            pos.y = ball->trans.y;
            pos.z = ball->trans.z;
            func_8000A1C0(D_800FB9D8_TipsyTourney, D_800FBA18_TipsyTourney, &pos, obj);
            fx = (pos.x + 250.0f) / 100.0f;
            cx = fx;
            fz = (pos.z + 250.0f) / 100.0f;
            cz = fz;
            fx -= cx;
            fz -= cz;
            D_800FB880_TipsyTourney[bw->unk_5C].x = pos.x;
            D_800FB880_TipsyTourney[bw->unk_5C].y = pos.y;
            D_800FB880_TipsyTourney[bw->unk_5C].z = pos.z;
            if ((fx > 0.0f) & (fx < 1.0f)) {
                if ((fz > 0.0f) & (fz < 1.0f)) {
                    tile = &D_800FB7B8_TipsyTourney[work->unk_05 - 1][cz][cx];
                    if (*tile == 0) {
                        (*tile)++;
                        PlaySound(0x2B7);
                    }
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_21_TipsyTourney/1A4EB0", func_800F9454_TipsyTourney);
#endif

void func_800F9718_TipsyTourney(omObjData* obj) {
    TipsyBgWork* work = obj->unk_50;
    s32 r;
    s32 c;

    if (func_8005FD5C() + D_800F64F8 == 0) {
        for (r = 0; r < 5; r++) {
            for (c = 0; c < 5; c++) {
                if (D_800FB7B8_TipsyTourney[work->unk_05 - 1][r][c] > 0) {
                    D_800FB7B8_TipsyTourney[work->unk_05 - 1][r][c] += 2;
                    if (D_800FB7B8_TipsyTourney[work->unk_05 - 1][r][c] >= 0x37) {
                        D_800FB7B8_TipsyTourney[work->unk_05 - 1][r][c] = -1;
                    }
                }
            }
        }
    }
}

void func_800F9800_TipsyTourney(void) {
    s32 p;
    s32 r;
    s32 c;

    for (p = 0; p < 4; p++) {
        for (r = 0; r < 5; r++) {
            for (c = 0; c < 5; c++) {
                if (D_800FB7B8_TipsyTourney[p][r][c] == 0) {
                    D_800FB7B8_TipsyTourney[p][r][c]++;
                }
            }
        }
    }
}

void func_800F9898_TipsyTourney(void) {
    s32 p;
    s32 r;
    s32 c;
    s32 left;

    for (p = 0, left = 0; p < 4; p++) {
        for (r = 0; r < 5; r++) {
            for (c = 0; c < 5; c++) {
                if (D_800FB7B8_TipsyTourney[p][r][c] != -1) {
                    left = 1;
                }
            }
        }
        if (left == 0) {
            func_800258EC(D_800F2AF8[p + 1]->model[1], 4, 4);
        }
    }
}

// decomp-permuter
void func_800F9980_TipsyTourney(s16 model, s32 p)
{
  unk2C0C0StructC0 *m = D_800F2B7C[model].unk_6C;
  unk2C0C0StructB0 *g;
  f32 minX;
  f32 minZ;
  f32 maxX;
  f32 maxZ;
  f32 w;
  f32 h;
  f32 lx;
  f32 lz;
  s16 start;
  s16 k;
  s16 c;
  short new_var;
  minZ = 10000.0f;
  minX = 10000.0f;
  maxZ = -10000.0f;
  maxX = -10000.0f;
  new_var = m->unk_80->unk_0E;
  g = &m->unk_D0[start = new_var];
  for (k = start; k < ((s16) m->unk_80->unk_10); k++, g++)
  {
    if (g->unk_0C < minX)
    {
      minX = g->unk_0C;
    }
    if (g->unk_14 < minZ)
    {
      minZ = g->unk_14;
    }
    if (maxX < g->unk_0C)
    {
      maxX = g->unk_0C;
    }
    if (maxZ < g->unk_14)
    {
      maxZ = g->unk_14;
    }
  }

  w = (maxX - minX) / 5.0f;
  h = (maxZ - minZ) / 5.0f;
  for (new_var = 0; new_var < 5; new_var++)
  {
    for (c = 0; c < 5; c++)
    {
      g = &m->unk_D0[start = m->unk_80->unk_0E];
      for (k = start; k < ((s16) m->unk_80->unk_10); k++, g++)
      {
        lx = minX + (w * c);
        if ((lx <= g->unk_0C) && (g->unk_0C <= (lx + w)))
        {
          lz = minZ + (h * new_var);
          if ((lz <= g->unk_14) && (g->unk_14 <= (lz + h)))
          {
            if (1)
            {
              break;
            }
          }
        }
      }

      if (k != ((s16) m->unk_80->unk_10))
      {
        D_800FBA58_TipsyTourney[p][c][new_var] = k;
      }
      D_800FB7B8_TipsyTourney[p][c][new_var] = 0;
    }

  }

}

void func_800F9C48_TipsyTourney(s16 model, s32 p) {
    unk2C0C0StructC0* m = D_800F2B7C[model].unk_6C;
    unk2C0C0StructB0* g;
    unk2C0C0StructE0* dst;
    unk2C0C0StructE0* src;
    s16 r;
    s16 c;
    s16 k;
    s16 v;
    s16 idx;
    f32 spin;
    f32 scale;
    f32 a;
    f32 d;
    f32 dx;
    f32 dz;

    for (r = 0; r < 5; r++) {
        for (c = 0; c < 5; c++) {
            v = D_800FB7B8_TipsyTourney[p][r][c];
            if (v != 0) {
                g = &m->unk_D0[D_800FBA58_TipsyTourney[p][c][r]];
                if (v < 0) {
                    for (k = 0; k < g->unk_00; k++) {
                        idx = g->unk_02[k];
                        dst = &m->unk_08[D_800F37F0][idx];
                        src = &m->unk_04[idx];
                        dst->unk_08 = (u16)src->unk_08 + 0x600;
                    }
                } else {
                    spin = D_800FB7B8_TipsyTourney[p][r][c] * (((r | c) & 1) ? 10.0f : -10.0f);
                    scale = 1.0f - D_800FB7B8_TipsyTourney[p][r][c] / 54.0f;
                    for (k = 0; k < g->unk_00; k++) {
                        dst = &m->unk_08[D_800F37F0][idx = g->unk_02[k]];
                        src = &m->unk_04[idx];
                        a = func_800B0CD8(g->unk_0C - src->unk_00, g->unk_14 - src->unk_04);
                        dx = g->unk_0C - src->unk_00;
                        dz = g->unk_14 - src->unk_04;
                        d = func_800B1750(dx * dx + dz * dz) * scale;
                        a += spin;
                        dst->unk_00 = func_800AEAC0(a) * d + g->unk_0C;
                        dst->unk_04 = func_800AEFD0(a) * d + g->unk_14;
                        dst->unk_02 = (u16)src->unk_02 + 1;
                    }
                }
            }
        }
    }
}

void func_800FA074_TipsyTourney(omObjData* obj) {
    TipsyBgWork* work = obj->unk_50;
    f32 dz;

    if (D_800ED430 == 1) {
        func_800F9454_TipsyTourney(obj);
        func_800F9290_TipsyTourney(obj);
        func_80008FC4(obj, 30.0f);
        D_800FB9D0_TipsyTourney = func_800F8D2C_TipsyTourney(obj);
        D_800FB9D4_TipsyTourney = dz = func_800F8FE0_TipsyTourney(obj);
        func_800F8C2C_TipsyTourney(obj, D_800FB9D0_TipsyTourney, dz);
        func_800257E4(obj->model[1], obj->rot.x, obj->rot.y, obj->rot.z);
    } else {
        func_80008FC4(obj, 0.0f);
    }
    func_800F9718_TipsyTourney(obj);
    func_800F9C48_TipsyTourney(obj->model[1], work->unk_05 - 1);
}

f32 func_800FA14C_TipsyTourney(omObjData* obj, f32 x, f32 y, f32 z, Vec3f* normal) {
    TipsyBallWork* work = obj->unk_50;
    Vec4f s;
    f32 ret;
    f32 h;

    ret = -10000.0f;
    s.x = x;
    s.y = y;
    s.z = z;
    s.w = work->unk_48;
    if (work->unk_54 != 0) {
        func_800FB504_TipsyTourney(&s);
    }
    func_80004D1C(obj, &s, 0.0f);
    h = func_800051D4(obj, x + D_800ED6B8, y, z + D_800F5254, normal);
    if (ret < h) {
        ret = h;
    }
    return ret;
}

void func_800FA238_TipsyTourney(omObjData* obj, Vec3f* normal) {
    s32 idx = ((TipsyBallWork*)obj->unk_50)->unk_5C;
    f32 tx;
    f32 tz;
    f32 x;
    f32 z;

    tx = -(func_800B0CD8(normal->y, normal->z) - 90.0f);
    tz = func_800B0CD8(normal->y, normal->x) - 90.0f;
    x = D_800FB908_TipsyTourney[idx].x;
    z = D_800FB908_TipsyTourney[idx].z;
    if (x < tx) {
        x += 4.0f;
        if (tx < x) {
            x = tx;
        }
    } else if (tx < x) {
        x -= 4.0f;
        if (x < tx) {
            x = tx;
        }
    }
    if (z < tz) {
        z += 4.0f;
        if (tz < z) {
            z = tz;
        }
    } else if (tz < z) {
        z -= 4.0f;
        if (z < tz) {
            z = tz;
        }
    }
    obj->rot.x = D_800FB908_TipsyTourney[idx].x = x;
    obj->rot.z = D_800FB908_TipsyTourney[idx].z = z;
}

void func_800FA3C4_TipsyTourney(omObjData* obj) {
    TipsyBallWork* work = obj->unk_50;
    f32 x;
    f32 y;
    f32 z;
    f32 vy;
    f32 angle;
    f32 speed;
    f32 ground;
    f32 h;
    s32 idx;

    x = obj->trans.x;
    y = obj->trans.y;
    z = obj->trans.z;
    ground = -10000.0f;
    idx = work->unk_5C;
    vy = work->unk_38;
    angle = work->unk_3C;
    speed = work->unk_40;
    D_800ED6B8 = D_800F5254 = 0.0f;
    if (vy < 1000.0f) {
        if (vy > 1.0f) {
            vy = 1.0f;
        }
        y += vy * vy * ((vy >= 0.0f) ? -35.0f : 35.0f);
        vy += 0.04f;
        x += func_800AEAC0(angle) * speed;
        z += func_800AEFD0(angle) * speed;
        h = func_800FA14C_TipsyTourney(obj, x, y, z, &D_800FB948_TipsyTourney[idx]);
        if (h != -65536.0f) {
            ground = h;
            if (y < h) {
                y = ground;
                if (fabs(vy) < 0.6) {
                    vy = 1000.0f;
                } else {
                    vy = -vy * 0.2f;
                }
            } else {
                work->unk_53 = 0xFF;
            }
        } else {
            work->unk_53 = 0xFF;
        }
    } else {
        x += (func_800AEAC0(angle) * speed + D_800FB948_TipsyTourney[idx].x * D_800FB7B0_TipsyTourney);
        z += (func_800AEFD0(angle) * speed + D_800FB948_TipsyTourney[idx].z * D_800FB7B0_TipsyTourney);
        h = func_800FA14C_TipsyTourney(obj, x, y, z, &D_800FB948_TipsyTourney[idx]);
        if (h != -65536.0f) {
            if (y < h + 35.0f) {
                y = h;
            } else {
                vy = 0.2f;
                work->unk_53 = 0xFF;
            }
        } else {
            vy = 0.2f;
        }
        ground = y;
        angle = func_800B0CD8(x, z);
    }
    obj->trans.x = x + D_800ED6B8;
    obj->trans.y = y;
    obj->trans.z = z + D_800F5254;
    work->unk_38 = vy;
    work->unk_3C = angle;
    work->unk_40 = speed;
    D_800FB938_TipsyTourney[idx] = func_80029518(D_800FB938_TipsyTourney[idx] + 4.0f);
    if ((obj->model[1] != 0) & (ground != -10000.0f)) {
        func_80025798(obj->model[1], x + D_800ED6B8, ground, z + D_800F5254);
        func_80025830(obj->model[1], 0.3f, 0.3f, 0.3f);
        func_80037178(obj->model[1], &D_800FB948_TipsyTourney[idx]);
    }
    func_800FA238_TipsyTourney(obj, &D_800FB948_TipsyTourney[idx]);
    func_8009ECB0(D_800F2B7C[obj->model[0]].unk7C, 0.0f, D_800FB938_TipsyTourney[idx], 0.0f);
}

void func_800FA880_TipsyTourney(omObjData* obj) {
    TipsyBallWork* work;

    if (D_800ED430 < 2) {
        D_800FB7B0_TipsyTourney = 30.0f;
    } else {
        work = obj->unk_50;
        if (work->unk_54 != 0) {
            func_800258EC(obj->model[0], 4, 4);
            func_800258EC(obj->model[2], 4, 0);
            func_80025798(obj->model[2], obj->trans.x, obj->trans.y + 50.0f, obj->trans.z);
            func_80025CA8(obj->model[2], 0.0f);
            work->unk_54 = 0;
        }
        D_800FB7B0_TipsyTourney = 0.0f;
    }
    func_800FA3C4_TipsyTourney(obj);
}

// decomp-permuter
s32 func_800FA94C_TipsyTourney(s32 p)
{
  s32 i;
  s32 j;
  for (i = 0; i < 5; i++)
  {
    j = 0;
    if (D_800FB7B8_TipsyTourney[p][j][i] == 0)
    {
      return 0;
    }
  }

  for (i = 0, j = 0; i < 5; i++)
  {
    if (D_800FB7B8_TipsyTourney[p][i][j] == 0)
    {
      return 0;
    }
  }

  for (i = 0; i < 5; i++)
  {
    if (D_800FB7B8_TipsyTourney[p][4][i] == 0)
    {
      return 0;
    }
  }

  for (i = 0, j = 4; i < 5; i++)
  {
    if (D_800FB7B8_TipsyTourney[p][i][j] == 0)
    {
      return 0;
    }
  }

  return 1;
}

s32 func_800FAA9C_TipsyTourney(s32 p) {
    if (D_800FB7B8_TipsyTourney[p][1][1] == 0) {
        return 0;
    }
    if (D_800FB7B8_TipsyTourney[p][1][2] == 0) {
        return 0;
    }
    if (D_800FB7B8_TipsyTourney[p][1][3] == 0) {
        return 0;
    }
    if (D_800FB7B8_TipsyTourney[p][2][1] == 0) {
        return 0;
    }
    if (D_800FB7B8_TipsyTourney[p][2][3] == 0) {
        return 0;
    }
    if (D_800FB7B8_TipsyTourney[p][3][1] == 0) {
        return 0;
    }
    if (D_800FB7B8_TipsyTourney[p][3][2] != 0) {
        return D_800FB7B8_TipsyTourney[p][3][3] != 0;
    }
    return 0;
}

s32 func_800FABCC_TipsyTourney(s32 p) {
    s32 n;

    n = D_800FB7B8_TipsyTourney[p][1][1] == 0;
    n += D_800FB7B8_TipsyTourney[p][1][2] == 0;
    n += D_800FB7B8_TipsyTourney[p][1][3] == 0;
    n += D_800FB7B8_TipsyTourney[p][2][1] == 0;
    n += D_800FB7B8_TipsyTourney[p][2][3] == 0;
    n += D_800FB7B8_TipsyTourney[p][3][1] == 0;
    n += D_800FB7B8_TipsyTourney[p][3][2] == 0;
    n += D_800FB7B8_TipsyTourney[p][3][3] == 0;
    return n;
}

void func_800FAC80_TipsyTourney(omObjData* obj) {
    TipsyWork* work = obj->unk_50;
    TipsyBgWork* pw;
    omObjData* plat;
    Vec3f pos;
    Vec3f dir;
    f32 mul;
    f32 a;
    f32 dist;
    s32 dx;
    s32 dz;
    s32 port;
    s32 diff;
    u8 r;

    port = work->unk_56;
    switch (GwPlayer[work->unk_58].cpu_difficulty) {
    case 0:
        mul = 0.6f;
        break;
    case 1:
        mul = 0.7f;
        break;
    case 2:
        mul = 0.8f;
        break;
    default:
        mul = 0.9f;
        break;
    }
    if (work->unk_53 >= 0) {
        plat = D_800F2AF8[work->unk_53];
        pw = plat->unk_50;
        pos.x = obj->trans.x;
        pos.y = obj->trans.y;
        pos.z = obj->trans.z;
        func_8000A1C0(D_800FB9D8_TipsyTourney, D_800FBA18_TipsyTourney, &pos, plat);
        dir.y = 0.0f;
        if (func_800FA94C_TipsyTourney(pw->unk_05 - 1) == 0) {
            a = func_800B0CD8(pos.x, pos.z) + D_800FB990_TipsyTourney[work->unk_58] * 15.0f;
            dir.x = func_800AEAC0(a) * 250.0f - pos.x;
            dir.z = func_800AEFD0(a) * 250.0f - pos.z;
            func_8002956C(&dir);
            dir.x *= mul * 60.0f;
            dir.z *= mul * 60.0f;
            ContStkX[port] = dir.x;
            ContStkY[port] = -dir.z;
        } else {
            diff = GwPlayer[work->unk_58].cpu_difficulty;
            if (diff < 4) {
                if (diff >= 2 && func_800FAA9C_TipsyTourney(pw->unk_05 - 1) == 0) {
                    a = func_800B0CD8(pos.x, pos.z) + D_800FB990_TipsyTourney[work->unk_58] * 15.0f;
                    dir.x = func_800AEAC0(a) * 165.0f - pos.x;
                    dir.z = func_800AEFD0(a) * 165.0f - pos.z;
                    func_8002956C(&dir);
                    if (func_800FABCC_TipsyTourney(pw->unk_05 - 1) >= 3) {
                        dir.x *= 39.0f;
                        dir.z *= 39.0f;
                        ContStkX[port] = dir.x;
                        ContStkY[port] = -dir.z;
                        return;
                    }
                }
            }
            dx = D_800FB880_TipsyTourney[pw->unk_05 - 1].x - pos.x;
            dz = D_800FB880_TipsyTourney[pw->unk_05 - 1].z - pos.z;
            dist = func_800B1750(dx * dx + dz * dz);
            if (dist > 500.0f) {
                dist = 0.0f;
                dir.z = 0.0f;
                dir.x = 0.0f;
            } else if (dist < 150.0f && D_800FB9A0_TipsyTourney[work->unk_58] < 0) {
                ContBtnTrg[port] = 0x8000;
                D_800FB9A0_TipsyTourney[work->unk_58] = 0x5A;
                dir.x = func_800AEAC0(work->unk_3C);
                dir.z = -func_800AEFD0(work->unk_3C);
                D_800FB9A8_TipsyTourney[work->unk_58].x = dir.x *= 60.0f;
                D_800FB9A8_TipsyTourney[work->unk_58].z = dir.z *= 60.0f;
            } else {
                a = func_800B0CD8(pos.x, pos.z) + D_800FB990_TipsyTourney[work->unk_58] * 10.0f;
                dir.x = func_800AEAC0(a) * 165.0f - pos.x;
                dir.z = func_800AEFD0(a) * 165.0f - pos.z;
                func_8002956C(&dir);
                if (D_800FB988_TipsyTourney[work->unk_58] == 0.0f) {
                    r = rand8();
                    switch (r >> 6) {
                    case 0:
                        D_800FB978_TipsyTourney[work->unk_58] = mul * 0.9f;
                        D_800FB988_TipsyTourney[work->unk_58] = mul * 90.0f;
                        break;
                    case 1:
                        D_800FB978_TipsyTourney[work->unk_58] = mul * 0.8f;
                        D_800FB988_TipsyTourney[work->unk_58] = mul * 90.0f;
                        break;
                    case 2:
                        D_800FB978_TipsyTourney[work->unk_58] = mul * 0.75f;
                        D_800FB988_TipsyTourney[work->unk_58] = mul * 90.0f;
                        break;
                    default:
                        D_800FB978_TipsyTourney[work->unk_58] = 0.0f;
                        D_800FB988_TipsyTourney[work->unk_58] = 0x2D;
                        break;
                    }
                    if (r > 0x80) {
                        if (D_800FB990_TipsyTourney[work->unk_58] > 0.0) {
                            D_800FB990_TipsyTourney[work->unk_58] = -1.0f;
                        } else {
                            D_800FB990_TipsyTourney[work->unk_58] = 1.0f;
                        }
                    }
                } else {
                    D_800FB9A0_TipsyTourney[work->unk_58]--;
                    D_800FB988_TipsyTourney[work->unk_58]--;
                }
                dist = D_800FB978_TipsyTourney[work->unk_58];
            }
            dir.x *= dist * 60.0f;
            dir.z *= dist * 60.0f;
            ContStkX[port] = dir.x;
            ContStkY[port] = -dir.z;
        }
    } else {
        ContBtn[port] = 0x8000;
        ContStkX[port] = (s8)D_800FB9A8_TipsyTourney[work->unk_58].x;
        ContStkY[port] = (s8)D_800FB9A8_TipsyTourney[work->unk_58].z;
    }
}

void func_800FB504_TipsyTourney(Vec4f* s) {
    s32 i;
    omObjData* p;
    TipsyWork* pw;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 d;

    for (i = 0; i < D_800F2BC0; i++) {
        p = D_800F3FB0[i];
        pw = p->unk_50;
        dx = p->trans.x - s->x;
        dy = p->trans.y - s->y;
        dz = p->trans.z - s->z;
        d = func_800B1750(dx * dx + dy * dy + dz * dz) - (s->w + pw->unk_48);
        if (d < 0.0f && pw->unk_38 == 1000.0f) {
            func_800078E8(dx, dz, d);
        }
    }
}

s32 func_800FB634_TipsyTourney(omObjData* obj, omObjData* other) {
    TipsyWork* work = obj->unk_50;
    TipsyWork* ow = other->unk_50;
    f32 speed;
    f32 px;
    f32 pz;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 d;

    speed = work->unk_40;
    if (work->unk_50 & 6) {
        speed *= 0.6f;
    }
    px = func_800AEAC0(work->unk_3C) * speed + obj->trans.x;
    pz = func_800AEFD0(work->unk_3C) * speed + obj->trans.z;
    dx = other->trans.x - px;
    dy = other->trans.y - obj->trans.y;
    dz = other->trans.z - pz;
    d = func_800B1750(dx * dx + dy * dy + dz * dz) - (ow->unk_48 + work->unk_48);
    if (d < 0.0f) {
        if (work->unk_38 != 1000.0f) {
            func_8000A988(obj, dx, dz);
            func_80060F04(work->unk_58, 2, 3, 0xA);
        } else {
            func_800078E8(dx, dz, d);
        }
    }
    return 1;
}
