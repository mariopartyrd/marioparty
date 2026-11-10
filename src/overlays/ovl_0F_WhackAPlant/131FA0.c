#include "common.h"
#include "WhackAPlant.h"

/* .data */
f32 D_800FB580_WhackAPlant[9][2] = {
    { -240.0f, -240.0f }, { 0.0f, -240.0f }, { 240.0f, -240.0f },
    { -240.0f, 0.0f },    { 0.0f, 0.0f },    { 240.0f, 0.0f },
    { -240.0f, 240.0f },  { 0.0f, 240.0f },  { 240.0f, 240.0f },
};
WAPWave D_800FB5C8_WhackAPlant[8] = {
    { 1, 30, 68, 30 }, { 2, 30, 68, 30 }, { 3, 30, 75, 30 }, { 4, 30, 75, 30 },
    { 5, 30, 85, 30 }, { 6, 30, 95, 30 }, { 7, 30, 105, 30 }, { 8, 30, 120, 30 },
};
u16 D_800FB608_WhackAPlant = 0;
u16 D_800FB60A_WhackAPlant = 0;
f32 D_800FB60C_WhackAPlant = 0.0f;
f32 D_800FB610_WhackAPlant = 50.0f;
f32 D_800FB614_WhackAPlant = 0.0f;
f32 D_800FB618_WhackAPlant = 0.0f;
u16 D_800FB61C_WhackAPlant = 0;
u16 D_800FB61E_WhackAPlant = 0;
u16 D_800FB620_WhackAPlant = 15;
s16 D_800FB622_WhackAPlant = 0;
s16 D_800FB624_WhackAPlant = 0;


void func_800F65E0_WhackAPlant(void) {
    omObjData* obj;
    WAPPlantWork* w;
    void* data;
    s32 i;

    omInitObjMan(0x32, 0);
    i = 0;
    func_80060088();
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    func_80029090(1);
    func_8001DE70(0x33);
    func_80009500();
    func_8002578C(1);
    func_8005D98C(0, 9);
    func_8005D98C(1, 9);
    for (i = 0; i < 4; i++) {
        if (GwPlayer[i].group == 0) {
            D_800FB720_WhackAPlant = i;
        }
    }
    func_800178A0(1);
    D_800FB724_WhackAPlant.x = 0.0f;
    D_800FB724_WhackAPlant.y = 270.0f;
    D_800FB724_WhackAPlant.z = 50.0f;
    D_800FB714_WhackAPlant.x = 0.0f;
    D_800FB714_WhackAPlant.y = 270.0f;
    D_800FB714_WhackAPlant.z = -120.0f;
    D_800FB734_WhackAPlant.x = 0.0f;
    D_800FB734_WhackAPlant.y = 1.0f;
    D_800FB734_WhackAPlant.z = 0.0f;
    func_80017660(0, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_800FB4DC_WhackAPlant), 0xA0);
    func_80023448(3);
    func_800234B8(0, 0x2C, 0x2C, 0x40);
    func_800234B8(1, 0x60, 0x60, 0x10);
    func_80023504(1, 100.0f, 80.0f, 100.0f);
    func_800234B8(2, 0, 0, 0);
    func_80023504(2, 100.0f, 80.0f, 100.0f);
    func_800234B8(3, 0, 0, 0);
    func_80023504(3, 100.0f, 80.0f, 100.0f);
    omAddObj(0x64, 0, 0, -1, func_800F6B8C_WhackAPlant);
    omAddObj(0, 0, 0, -1, func_800F6BC4_WhackAPlant);
    D_800FB6F8_WhackAPlant = omAddObj(4, 0x14, 0, -1, func_800F6DBC_WhackAPlant);
    D_800FB700_WhackAPlant = omAddObj(6, 0xA, 0x64, -1, func_800F70AC_WhackAPlant);
    D_800FB708_WhackAPlant = omAddObj(7, 5, 0, -1, func_800F8134_WhackAPlant);
    D_800FB6FC_WhackAPlant = omAddObj(8, 0x21, 0x6C, -1, func_800F8614_WhackAPlant);
    D_800FB704_WhackAPlant = omAddObj(0xD, 0, 0, -1, func_800F9D38_WhackAPlant);
    for (i = 0; i < 9; i++) {
        obj = omAddObj(0xA, 0, 0, 0, NULL);
        w = func_80023684(sizeof(WAPPlantWork), 0x7918);
        obj->unk_50 = w;
        w->unk44 = 0.1f;
        w->unk48 = 0.0f;
        w->unk34 = 0.0f;
        w->unk3C = 0.0f;
        w->unk5C = 0;
        w->unk52 = 3;
        w->unk60 = 0.0f;
        w->unk50 = 0x40;
        w->unk54 = 1;
        w->unk68 = func_80023684(sizeof(WAPPlant), 0x7918);
        w->unk38 = 1000.0f;
        w->unk40 = 0.0f;
        omSetTra(obj, 1000.0f, 1000.0f, 1000.0f);
        D_800EDE70[D_800EE984++] = obj;
    }
    omAddObj(5, 0, 0, -1, func_800F6FE4_WhackAPlant);
    omAddObj(0x2710, 0, 0, -1, func_800FA668_WhackAPlant);
    D_800FB69C_WhackAPlant = InitSprite(0x7C);
    D_800FB6A2_WhackAPlant = InitSprite(0x74);
    for (i = 0; i < 9; i++) {
        D_800FB6A8_WhackAPlant[i] = func_80019060(D_800FB69C_WhackAPlant, 0, 1);
        func_80018D84(D_800FB6A8_WhackAPlant[i], 0x8000);
        func_80018CF8(D_800FB6A8_WhackAPlant[i], 0xA0);
        func_80018C90(D_800FB6A8_WhackAPlant[i]);
    }
    data = DataRead(0x2A);
    D_800FB6BC_WhackAPlant = func_80039084(data);
    HuMemDirectFree(data);
    data = DataRead(0x21);
    D_800FB6BA_WhackAPlant = func_80039084(data);
    HuMemDirectFree(data);
    D_800FB698_WhackAPlant = _CheckFlag(0x2B);
    SetFadeInTypeAndTime(0, 0x10);
    D_800FB710_WhackAPlant = 0;
}
void func_800F6B8C_WhackAPlant(void) {
    s32 i = 0;
    
    for (i = 0; i < D_800F3778; i++) {}

}

void func_800F6BC4_WhackAPlant(omObjData* arg0) {
    s16 temp_s2;
    s32 i;

    D_800FB740_WhackAPlant = 0;
    D_800FB69A_WhackAPlant = 0;
    D_800FB6F4_WhackAPlant = 0;
    D_800FB712_WhackAPlant = 0;

    for (i = 0; i < 9; i++) {
        temp_s2 = func_8001E00C((void*)-1, 0x68D, 8);
        D_800ECDE0[temp_s2].unk_02 = D_800FB6BA_WhackAPlant;
        func_80025930(D_800ECDE0[temp_s2].unk_00, 0x60000000, 0x60000000);
        D_800FB6C0_WhackAPlant[i] = temp_s2;
        D_800FB6EA_WhackAPlant[i] = 0;
    }

    for (i = 0; i < 9; i++) {
        temp_s2 = func_8001E00C((void*)-1, 0x68D, 8);
        D_800ECDE0[temp_s2].unk_02 = D_800FB6BC_WhackAPlant;
        func_80025930(D_800ECDE0[temp_s2].unk_00, 0x60000000, 0x60000000);
        D_800FB6D8_WhackAPlant[i] = temp_s2;
        func_8001E2F8(temp_s2, 0xE0);
        func_8001E360(temp_s2, 0xFF, 0xFF, 0xBE);
    }

    D_800ED430 = 1;
    arg0->func_ptr = &func_800F6D54_WhackAPlant;
}

void func_800F6D54_WhackAPlant(void) {
    switch (D_800FB740_WhackAPlant) {
    case 0:
        func_800FA078_WhackAPlant();
        break;
    case 1:
        break;
    case 2:
        func_800FA1E0_WhackAPlant();
        break;
    }
}

void func_800F6DBC_WhackAPlant(omObjData* arg0) {
    unkGlobalStruct_02* w;
    s32 i;
    s32 j;

    arg0->model[0] = LoadFormFile(0x210000, 0x20299);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            arg0->model[i * 3 + j + 1] = LoadFormFile(0x15, 0x20699);
            if ((i == 0) & (j == 0)) {
                arg0->model[10] = LoadFormFile(0x210001, 0x499);
            } else {
                arg0->model[i * 3 + j + 10] = func_80023FC8(arg0->model[10]);
            }
            func_80025798(arg0->model[i * 3 + j + 1], D_800FB580_WhackAPlant[i * 3 + j][0], 0.0f, D_800FB580_WhackAPlant[i * 3 + j][1]);
            func_80025798(arg0->model[i * 3 + j + 10], D_800FB580_WhackAPlant[i * 3 + j][0], 1.0f, D_800FB580_WhackAPlant[i * 3 + j][1]);
            func_800258EC(arg0->model[i * 3 + j + 10], 4, 4);
            func_80026040(arg0->model[i * 3 + j + 1]);
        }
    }
    func_800090B8(D_800ED440);
    D_800F2AF8[D_800ED440++] = arg0;
    w = func_80023684(sizeof(unkGlobalStruct_02), 0x7918);
    arg0->unk_50 = w;
    func_8009B770(w, 0, sizeof(unkGlobalStruct_02));
    w->unk_04 = 1;
    w->unk_05 = 0;
    func_80009028(arg0, 0, -550.0f, -550.0f, 550.0f, 550.0f);
    arg0->func_ptr = NULL;
}
void func_800F6FE4_WhackAPlant(omObjData* arg0) {
    unkGlobalStruct_02* temp_s0;
    
    D_800F2AF8[D_800ED440++] = arg0;
    temp_s0 = func_80023684(sizeof(unkGlobalStruct_02), 0x7918);
    arg0->unk_50 = temp_s0;
    func_8009B770(temp_s0, 0, sizeof(unkGlobalStruct_02));
    temp_s0->unk_04 = 1;
    temp_s0->unk_05 = 1;
    func_80009058(arg0, 170.0f, 170.0f, -320.0f, -320.0f, 320.0f, 320.0f);
    func_80008FB8(arg0, 0.5f);
    arg0->func_ptr = NULL;
}

void func_800F70AC_WhackAPlant(omObjData* arg0) {
    WAPPlayerWork* w;
    WAPCpu* cpu;
    s32 dir;
    s32 file;
    s32 mot;
    u8 chr;

    chr = GwPlayer[D_800FB720_WhackAPlant].character;
    dir = D_800C59AC[chr].unk_00;
    file = D_800C59AC[chr].unk_04;
    mot = D_800C59AC[chr].unk_08;
    func_8000979C(arg0, dir, file, D_800FB720_WhackAPlant, 0x20A99, 0xA99);
    omSetTra(arg0, 0.0f, 0.0f, 480.0f);
    func_80008EF0(arg0, 9, dir | mot, 0x20A99, 600.0f);
    w = arg0->unk_50;
    w->unkE4 = func_80023684(sizeof(WAPCpu), 0x7918);
    w->unk48 = 70.0f;
    cpu = w->unkE4;
    arg0->model[3] = LoadFormFile(0x19, 0xA8D);
    arg0->model[4] = LoadFormFile(0x1A, 0xA8D);
    func_8001874C(arg0, 0, dir, 1, 0);
    func_8001874C(arg0, 1, dir | 1, 1, 0);
    func_8001874C(arg0, 2, dir | 3, 1, 0);
    func_8001874C(arg0, 6, dir | 5, 1, 0x13);
    func_8001874C(arg0, 9, dir | 0xA, 1, 0x27);
    func_8001874C(arg0, 0x10, dir | 0x17, 1, 0);
    func_8001874C(arg0, 0x11, dir | 0x18, 0, 0xE);
    func_8001874C(arg0, 0x12, dir | 0x1C, 2, 0);
    func_8001874C(arg0, 0x13, dir | 0x1D, 2, 0);
    func_8001874C(arg0, 0xA, dir | 0x1E, 1, 0x27);
    func_8001874C(arg0, 0xD, dir | 0xF, 0, 0x18);
    func_8001874C(arg0, 0xE, dir | 0x10, 0, 0x78);
    func_8001874C(arg0, 0x15, dir | 0x62, 0, 0);
    func_8001874C(arg0, 3, dir | 0x60, 1, 0);
    func_8001874C(arg0, 4, dir | 0x61, 1, 0);
    func_8001874C(arg0, 0x1E, dir | 0x63, 0, 0);
    func_8001874C(arg0, 0x1F, dir | 0x64, 0, 0);
    func_8001874C(arg0, 0x20, dir | 0x67, 0, 0);
    w->unk38 = 1000.0f;
    w->unk3C = 180.0f;
    func_800090C4(arg0, 0, 2);
    func_800090C4(arg0, 1, 2);
    if ((u32)dir >> 16 == 5) {
        arg0->scale.x = arg0->scale.y = arg0->scale.z = 0.95f;
    }
    if ((u32)dir >> 16 == 3) {
        arg0->scale.x = arg0->scale.y = arg0->scale.z = 1.1f;
    }
    if ((u32)dir >> 16 == 4) {
        arg0->scale.x = arg0->scale.y = arg0->scale.z = 0.9f;
    }
    w->unk58 = D_800FB720_WhackAPlant;
    D_800F3FB0[D_800F2BC0++] = arg0;
    func_800184BC(arg0, 0);
    w->unkDC = func_800F92FC_WhackAPlant;
    cpu->unk0 = 0;
    cpu->unk2 = -1;
    cpu->unk6 = 0;
    cpu->unk14 = 0;
    cpu->unk18 = (rand8() * rand8()) % 360;
    cpu->unk1C = 10000.0f;
    cpu->unk20 = 0.0f;
    D_800B895C = 8.0f;
    cpu->unk24 = 0;
    omSetTra(arg0, 0.0f, -160.0f, 0.0f);
    arg0->func_ptr = func_800F7570_WhackAPlant;
}
void func_800F7570_WhackAPlant(omObjData* arg0) {
    unkGlobalStruct_00* temp_s1 = arg0->unk_50;

    if (D_800FB60A_WhackAPlant < 0x69) {
        omSetTra(arg0, arg0->trans.x, arg0->trans.y + PI, arg0->trans.z);
        func_80017DB0(arg0);
    } else {
        D_800FB710_WhackAPlant = 3;
        arg0->func_ptr = &func_800F7714_WhackAPlant;
        func_800258EC(D_800FB6F8_WhackAPlant->model[0], 0x1C00, 0x400);
        temp_s1->unk_3C = 0.0f;
    }

    D_800FB60A_WhackAPlant += 1;
    D_800FB724_WhackAPlant.x = func_800AEAC0(D_800FB60C_WhackAPlant) * D_800FB610_WhackAPlant;
    D_800FB724_WhackAPlant.z = func_800AEFD0(D_800FB60C_WhackAPlant) * D_800FB610_WhackAPlant;
    D_800FB724_WhackAPlant.y = D_800FB614_WhackAPlant + 270.0f;
    D_800FB718_WhackAPlant = D_800FB618_WhackAPlant + 270.0f;
    D_800FB60C_WhackAPlant -= 3.4285715f;
    D_800FB610_WhackAPlant = D_800FB610_WhackAPlant + 7.561905f;
    D_800FB614_WhackAPlant = D_800FB614_WhackAPlant + 7.6190476f;
    D_800FB618_WhackAPlant = D_800FB618_WhackAPlant + -2.5714285f;
}

void func_800F7714_WhackAPlant(omObjData* arg0) {
    WAPPlayerWork* w;
    WAPCpu* cpu;
    s16 hit;
    s32 i;
    u8 port;
    u16 btn;
    u16 trg;
    s8 stkx;
    s8 stky;

    w = arg0->unk_50;
    cpu = w->unkE4;
    hit = -1;
    if (w->unk38 == 1000.0f) {
        cpu->unk24 = 0;
    }
    port = GwPlayer[D_800FB720_WhackAPlant].port;
    btn = ContBtn[port];
    trg = ContBtnTrg[port];
    stkx = ContStkX[port];
    stky = ContStkY[port];
    if (GwPlayer[D_800FB720_WhackAPlant].flags & 1) {
        func_800FA760_WhackAPlant(arg0);
    }
    func_80005A28(arg0);
    i = 0;
    if ((u16)func_80017A60(arg0) != 0x20) {
        switch (cpu->unk0) {
        case 1:
        case 2:
            cpu->unk0 = 0;
            cpu->unk6 = 0;
            D_800B896C = 7.0f;
            D_800B8968 = 0.15f;
        case 0:
        default:
            cpu->unk0 = 0;
            break;
        }
    }
    for (i = 0; i < 9; i++) {
        if ((u16)func_800FB3E8_WhackAPlant(arg0->trans.x, arg0->trans.z, w->unk48, D_800FB580_WhackAPlant[i][0], D_800FB580_WhackAPlant[i][1], 70.0f) == 1) {
            hit = i;
            break;
        }
    }
    if (arg0->trans.y <= 80.0f) {
        cpu->unk24 = 0;
        func_80060F04(D_800FB720_WhackAPlant, 2, 3, 0xA);
        arg0->trans.y = 80.0f;
        D_800B896C = 6.5f;
        w->unk38 = -1.6f;
        D_800B8968 = 0.13f;
        cpu->unk0 = 1;
        w->unk3C = func_800B0CD8(-arg0->trans.x, -arg0->trans.z);
        func_80009E20(arg0);
        if (w->unk40 < 0.0f) {
            w->unk40 = -w->unk40;
        }
        w->unk50 &= ~0x10;
        func_80060540(0x240, 0);
        if (arg0->trans.z < -320.0f) {
            D_800FB708_WhackAPlant->work[0] = 0;
        } else if (arg0->trans.z > 320.0f) {
            D_800FB708_WhackAPlant->work[0] = 1;
        } else if (arg0->trans.x > 320.0f) {
            D_800FB708_WhackAPlant->work[0] = 2;
        } else if (arg0->trans.x < -320.0f) {
            D_800FB708_WhackAPlant->work[0] = 3;
        }
        cpu->unk6 = 0;
    }
    cpu->unk2 = hit;
    ContBtn[port] = btn;
    ContBtnTrg[port] = trg;
    ContStkX[port] = stkx;
    ContStkY[port] = stky;
}
void func_800F7AE0_WhackAPlant(omObjData* arg0) {
    WAPPlayerWork* w;
    WAPCpu* cpu;
    f32 dist;
    f32 speed;
    f32 angle;
    s8 btn;
    s8 trg;
    s8 stkx;
    s8 stky;

    w = arg0->unk_50;
    cpu = w->unkE4;
    dist = func_800B1750(arg0->trans.x * arg0->trans.x + arg0->trans.z * arg0->trans.z);
    btn = ContBtn[w->unk56];
    trg = ContBtnTrg[w->unk56];
    stkx = ContStkX[w->unk56];
    stky = ContStkY[w->unk56];
    ContBtn[w->unk56] &= 0x1FF0;
    ContBtnTrg[w->unk56] &= 0x1FF0;
    ContStkX[w->unk56] = ContStkY[w->unk56] = 0;
    if (dist <= 10.0f && w->unk38 == 1000.0f) {
        arg0->func_ptr = func_800F7F90_WhackAPlant;
        cpu->unk8 = (0.0 - fabs(w->unk3C)) / 15.0;
        if (w->unk3C < 0.0f) {
            cpu->unk8 = -cpu->unk8;
        }
        cpu->unkC = -arg0->trans.x / 15.0f;
        cpu->unk10 = -arg0->trans.z / 15.0f;
        ContStkX[w->unk56] = ContStkY[w->unk56] = 0;
        func_80005A28(arg0);
        func_80009730();
        omSetTra(arg0, 0.0f, arg0->trans.y, 0.0f);
    } else {
        if (dist > 150.0f) {
            speed = 80.0f;
        } else if (dist > 70.0f) {
            speed = 20.0f;
        } else {
            speed = 15.0f;
        }
        angle = func_800B0CD8(-arg0->trans.z, arg0->trans.x);
        ContStkX[w->unk56] = -func_800AEFD0(angle) * speed;
        ContStkY[w->unk56] = -func_800AEAC0(angle) * speed;
        func_80005A28(arg0);
        if (arg0->trans.y <= 80.0f) {
            arg0->trans.y = 80.0f;
            D_800B896C = 6.5f;
            w->unk38 = -1.6f;
            D_800B8968 = 0.13f;
            cpu->unk0 = 1;
            w->unk3C = func_800B0CD8(-arg0->trans.x, -arg0->trans.z);
            func_80009E20(arg0);
            if (w->unk40 < 0.0f) {
                w->unk40 = -w->unk40;
            }
            w->unk50 &= ~0x10;
            func_80060540(0x240, 0);
            if (arg0->trans.z < -320.0f) {
                D_800FB708_WhackAPlant->work[0] = 0;
            } else if (arg0->trans.z > 320.0f) {
                D_800FB708_WhackAPlant->work[0] = 1;
            } else if (arg0->trans.x > 320.0f) {
                D_800FB708_WhackAPlant->work[0] = 2;
            } else if (arg0->trans.x < -320.0f) {
                D_800FB708_WhackAPlant->work[0] = 3;
            }
        }
    }
    ContStkY[w->unk56] = stky;
    ContStkX[w->unk56] = stkx;
    ContBtn[w->unk56] = btn;
    ContBtnTrg[w->unk56] = trg;
}
void func_800F7F90_WhackAPlant(omObjData* arg0) {
    unkGlobalStruct_00* temp_s1 = arg0->unk_50;
    unk_Struct01* temp_v1 = temp_s1->unk_E4;

    if (D_800FB61C_WhackAPlant < 0xF) {
        temp_s1->unk_3C += temp_v1->unk_08;
        arg0->trans.x += temp_v1->unk_0C;
        arg0->trans.z += temp_v1->unk_10;
        D_800FB61C_WhackAPlant += 1;
        if (D_800FB61C_WhackAPlant == 0xF) {
            func_800184BC(arg0, 0);
            arg0->trans.x = arg0->trans.z = 0.0f;
            if (D_800FB698_WhackAPlant == 0) {
                D_800FB730_WhackAPlant = 1;
            }
        }
    }
    func_80017DB0(arg0);
    func_8009ECB0(&D_800F2B7C[arg0->model[0]].unk7C, 0.0f, temp_s1->unk_3C, 0.0f);
}

void func_800F8098_WhackAPlant(omObjData* arg0) {
    if (++D_800FB61E_WhackAPlant < 0x5A) {
        arg0->trans.y += -2.7777777f;
    }
    if (D_800FB620_WhackAPlant != 0) {
        if (--D_800FB620_WhackAPlant == 0) {
            func_80060540(0x24B, 0);
        }
    }
    func_80017DB0(arg0);
}
void func_800F8134_WhackAPlant(omObjData* arg0) {
    WAPFence* w;
    s32 i;

    arg0->unk_50 = func_80023684(sizeof(WAPFence), 0x7918);
    w = arg0->unk_50;
    arg0->work[0] = 0xFF;
    arg0->model[0] = -1;
    arg0->model[1] = LoadFormFile(0x210002, 0x699);
    for (i = 2; i < 5; i++) {
        arg0->model[i] = func_80023FC8(arg0->model[1]);
    }
    w->unk0[0] = -430.0f;
    w->unk0[1] = 430.0f;
    w->unk0[2] = 430.0f;
    w->unk0[3] = -430.0f;
    w->unk10[0] = -430.0f;
    w->unk10[1] = 430.0f;
    w->unk10[2] = -430.0f;
    w->unk10[3] = 430.0f;
    for (i = 0; i < 4; i++) {
        func_80025798(arg0->model[i + 1], w->unk0[i], 0.0f, w->unk10[i]);
        w->unk20[i] = 1.0f;
        w->unk30[i] = 0.0f;
        w->unk40[i] = 0;
    }
    func_800257E4(arg0->model[3], 0.0f, 270.0f, 0.0f);
    func_800257E4(arg0->model[4], 0.0f, 90.0f, 0.0f);
    arg0->func_ptr = func_800F82B4_WhackAPlant;
}
void func_800F82B4_WhackAPlant(omObjData* arg0) {
    WAPFence* w;
    s32 i;
    f32 d;
    f32 dx;

    w = arg0->unk_50;
    if (arg0->work[0] != 0xFF) {
        w->unk20[arg0->work[0]] = 0.5f;
        w->unk40[arg0->work[0]] = 1;
        arg0->work[0] = 0xFF;
    }
    i = 0;
    if (D_800FB740_WhackAPlant != 0 || D_800FB710_WhackAPlant >= 3) {
        for (i = 0; i < 2; i++) {
            dx = D_800FB700_WhackAPlant->trans.x - w->unk0[i];
            if (fabs(dx) > 20.0) {
                dx = (dx > 0.0f) ? 20.0f : -20.0f;
            }
            w->unk0[i] += dx;
        }
        for (i = 2; i < 4; i++) {
            d = D_800FB700_WhackAPlant->trans.z - w->unk10[i];
            if (d + w->unk10[i] > 280.0f) {
                d = 280.0f - w->unk10[i];
            } else if (d + w->unk10[i] < -280.0f) {
                d = -280.0f - w->unk10[i];
            }
            if (fabs(d) > 20.0) {
                d = (d > 0.0f) ? 20.0f : -20.0f;
            }
            w->unk10[i] += d;
        }
        i = 0;
    }
    for (i = 0; i < 4; i++) {
        func_80025798(arg0->model[i + 1], w->unk0[i], 0.0f, w->unk10[i]);
        w->unk30[i] += 15.0f;
        if (w->unk30[i] >= 360.0f) {
            w->unk30[i] -= 360.0f;
        }
        if (w->unk40[i] == 1) {
            w->unk20[i] += 0.1f;
            if (w->unk20[i] > 1.0f) {
                w->unk20[i] = 1.0f;
                w->unk40[i] = 0;
            }
            func_80025830(arg0->model[i + 1], 1.0f, w->unk20[i], 1.0f);
        } else {
            func_80025830(arg0->model[i + 1], 1.0f, w->unk20[i] - func_800AEAC0(w->unk30[i]) / 30.0f, 1.0f);
        }
    }
}
void func_800F8614_WhackAPlant(omObjData* arg0) {
    WAPPots* w;
    s32 i;

    arg0->unk_50 = func_80023684(sizeof(WAPPots), 0x7918);
    w = arg0->unk_50;
    arg0->work[0] = 2;
    arg0->work[1] = 0;
    arg0->work[2] = 0;
    for (i = 0; i < 9; i++) {
        if (i == 0) {
            arg0->model[0] = LoadFormFile(0x49, 0xA99);
        } else {
            arg0->model[i] = func_80023FC8(arg0->model[0]);
        }
        func_800258EC(arg0->model[i], 4, 4);
    }
    func_8001775C(arg0, 0, 0x49);
    func_8001775C(arg0, 1, 0x4A);
    func_8001775C(arg0, 2, 0x4B);
    func_8001775C(arg0, 3, 0x4C);
    for (i = 0; i < 24; i++) {
        if (i == 0) {
            arg0->model[9] = LoadFormFile(3, 0x899);
        } else {
            arg0->model[i + 9] = func_80023FC8(arg0->model[9]);
        }
        func_800258EC(arg0->model[i + 9], 4, 4);
    }
    for (i = 0; i < 9; i++) {
        w->unk2[i] = 0;
        w->unk1C[i] = 0.5f;
    }
    w->unk14 = 0x1E;
    for (i = 0; i < 3; i++) {
        w->unk16[i] = 0;
    }
    w->unk0 = 0;
    arg0->func_ptr = func_800F87EC_WhackAPlant;
    omSetStatBit(arg0, 0xA0);
}
void func_800F87EC_WhackAPlant(omObjData* arg0) {
    WAPPots* w;
    WAPCpu* cpu;
    s32 i;
    s32 bits;
    u16 n;
    u16 pot;

    w = arg0->unk_50;
    cpu = ((WAPPlayerWork*)D_800FB700_WhackAPlant->unk_50)->unkE4;
    for (i = 0; i < 9; i++) {
        func_800FA6AC_WhackAPlant(D_800FB6F8_WhackAPlant->model[i + 1], w->unk1C[i]);
    }
    if (func_8005FD5C() + D_800F64F8 != 1) {
        bits = arg0->unk_10;
        if (bits != 0) {
            arg0->unk_10 = 0;
            if (bits == 1) {
                w->unk0 = 0;
            }
        }
        if (D_800FB740_WhackAPlant == 1 && w->unk0 == 0) {
            if (D_800FB69A_WhackAPlant == 8) {
                D_800FB740_WhackAPlant = 2;
                D_800FB730_WhackAPlant = 0;
                func_800258EC(D_800FB700_WhackAPlant->model[1], 4, 4);
                D_800FB700_WhackAPlant->model[1] = 0;
                D_800FB700_WhackAPlant->func_ptr = func_800F7AE0_WhackAPlant;
                return;
            }
            w->unk0 = 1;
            cpu->unk6 = 0;
            n = D_800FB5C8_WhackAPlant[D_800FB69A_WhackAPlant].count;
            for (i = 0; i < n; i++) {
                pot = rand8() % 9;
                while (1) {
                    if (w->unk2[pot] == 0) {
                        break;
                    }
                    if (++pot >= 9) {
                        pot -= 9;
                    }
                }
                func_800F8A58_WhackAPlant(arg0, pot, func_800F8BE8_WhackAPlant);
                func_800258EC(D_800FB6F8_WhackAPlant->model[pot + 10], 4, 0);
                D_800FB6F4_WhackAPlant++;
            }
            func_80060540(0x241, 0);
            arg0->work[1] = n;
            D_800FB69A_WhackAPlant++;
        }
    }
}
omObjData* func_800F8A58_WhackAPlant(omObjData* arg0, u16 arg1, void* arg2) {
    omObjData* obj;
    WAPPlantWork* w;
    WAPPlant* p;
    s16 mdl;

    ((WAPPots*)arg0->unk_50)->unk2[arg1] = 1;
    obj = func_8005DB5C(0, arg1);
    obj->func_ptr = arg2;
    w = obj->unk_50;
    p = w->unk68;
    p->unk0 = 0;
    p->unk4 = arg1;
    p->unk8 = D_800FB5C8_WhackAPlant[D_800FB69A_WhackAPlant].rise;
    p->unkA = D_800FB5C8_WhackAPlant[D_800FB69A_WhackAPlant].snap;
    p->unkC = D_800FB5C8_WhackAPlant[D_800FB69A_WhackAPlant].sink;
    p->unk6 = p->unk8;
    w->unk48 = 10.0f;
    mdl = arg0->model[arg1];
    func_800FB308_WhackAPlant(arg0, arg1, D_800FB580_WhackAPlant[arg1][0], 0.0f, D_800FB580_WhackAPlant[arg1][1]);
    omSetTra(obj, D_800FB580_WhackAPlant[arg1][0], 0.0f, D_800FB580_WhackAPlant[arg1][1]);
    func_80025BB8(mdl, arg0->motion[3]);
    func_80025EB4(mdl, 2, 0);
    func_800258EC(mdl, 4, 0);
    p->unk2 = mdl;
    return obj;
}
// NON_MATCHING: register allocation; the rise-end model id is sign-extended once per branch in retail (masked 26, 559/558)
#ifdef NON_MATCHING
void func_800F8BE8_WhackAPlant(omObjData* arg0) {
    WAPPlantWork* w;
    WAPPlant* p;
    u16 pot;
    s16 mdl;
    WAPPots* pots;
    f32 y;
    f32 a;
    s16 m;

    w = arg0->unk_50;
    p = w->unk68;
    pot = p->unk4;
    mdl = D_800FB6FC_WhackAPlant->model[pot];
    pots = D_800FB6FC_WhackAPlant->unk_50;
    switch (p->unk0) {
    case 0:
        p->unk6--;
        y = (170.0f / p->unk8) * (p->unk8 - p->unk6);
        func_800FB308_WhackAPlant(D_800FB6FC_WhackAPlant, pot, D_800FB580_WhackAPlant[pot][0], y, D_800FB580_WhackAPlant[pot][1]);
        omSetTra(arg0, D_800FB580_WhackAPlant[pot][0], y, D_800FB580_WhackAPlant[pot][1]);
        a = func_800FB43C_WhackAPlant(D_800FB580_WhackAPlant[pot][0], D_800FB580_WhackAPlant[pot][1], D_800FB700_WhackAPlant->trans.x, D_800FB700_WhackAPlant->trans.z);
        if (a != 1000.0f) {
            func_800FB378_WhackAPlant(D_800FB6FC_WhackAPlant, pot, 0.0f, a, 0.0f);
            omSetRot(arg0, 0.0f, a, 0.0f);
        }
        w->unk34 = w->unk48 = (((f32)p->unk8 - p->unk6) / p->unk8) * 55.0f;
        func_80025830(D_800FB6F8_WhackAPlant->model[pot + 10], (f32)(p->unk8 - p->unk6) / p->unk8, 0.7f, (f32)(p->unk8 - p->unk6) / p->unk8);
        pots->unk1C[pot] = ((f32)(p->unk8 - p->unk6) / p->unk8) * 0.5f + 0.5f;
        if (p->unk6 == 0) {
            p->unk6 = p->unkA;
            p->unk0 = 1;
            m = mdl;
            if (rand8() & 1) {
                func_80025BB8(m, (s16)D_800FB6FC_WhackAPlant->motion[1]);
            } else {
                func_80025BB8(m, (s16)D_800FB6FC_WhackAPlant->motion[0]);
            }
            func_80025EB4(m, 2, 2);
        }
        break;
    case 1:
        a = func_800FB43C_WhackAPlant(D_800FB580_WhackAPlant[pot][0], D_800FB580_WhackAPlant[pot][1], D_800FB700_WhackAPlant->trans.x, D_800FB700_WhackAPlant->trans.z);
        if (a != 1000.0f) {
            func_800FB378_WhackAPlant(D_800FB6FC_WhackAPlant, pot, 0.0f, a, 0.0f);
            omSetRot(arg0, 0.0f, a, 0.0f);
        }
        if (--p->unk6 == 5) {
            func_80025C20(mdl, func_80025E48(D_800FB6FC_WhackAPlant->motion[2]), 0, 5, 0);
        }
        if (p->unk6 == 0) {
            p->unk6 = p->unkC;
            p->unk0 = 2;
        }
        break;
    case 2:
    case 3:
        p->unk6--;
        y = (170.0f / p->unkC) * p->unk6;
        func_800FB308_WhackAPlant(D_800FB6FC_WhackAPlant, pot, D_800FB580_WhackAPlant[pot][0], y, D_800FB580_WhackAPlant[pot][1]);
        omSetTra(arg0, D_800FB580_WhackAPlant[pot][0], y, D_800FB580_WhackAPlant[pot][1]);
        func_80025830(D_800FB6F8_WhackAPlant->model[pot + 10], (f32)p->unk6 / p->unkC, 0.7f, (f32)p->unk6 / p->unkC);
        pots->unk1C[pot] = ((f32)p->unk6 / p->unkC) * 0.5f + 0.5f;
        if (p->unk6 == 0) {
            func_800258EC(D_800FB6FC_WhackAPlant->model[pot], 4, 4);
            func_800258EC(D_800FB6F8_WhackAPlant->model[pot + 10], 4, 4);
            pots->unk2[p->unk4] = 0;
            D_800FB6FC_WhackAPlant->work[1]--;
            if (D_800FB6FC_WhackAPlant->work[1] == 0) {
                if (D_800ED618[1].num == 0) {
                    func_8005DC18(D_800FB6FC_WhackAPlant, 1);
                } else {
                    func_8005DB84(1, 1);
                }
            }
            omSetTra(arg0, 1000.0f, 1000.0f, 1000.0f);
            arg0->func_ptr = NULL;
            if (p->unk0 != 3) {
                D_800FB6F4_WhackAPlant--;
                if (D_800FB6F4_WhackAPlant == 0 && D_800FB69A_WhackAPlant == 8) {
                    func_800601D4(0x28);
                    D_800FB740_WhackAPlant = 2;
                    D_800FB730_WhackAPlant = 0;
                    func_800258EC(D_800FB700_WhackAPlant->model[1], 4, 4);
                    D_800FB700_WhackAPlant->model[1] = 0;
                    D_800FB700_WhackAPlant->func_ptr = func_800F7AE0_WhackAPlant;
                }
            }
        } else {
            w->unk34 = w->unk48 = (p->unk6 * 55.0f) / p->unkC;
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0F_WhackAPlant/131FA0", func_800F8BE8_WhackAPlant);
#endif
// NON_MATCHING: register allocation and beql/bc1fl vs beq/bc1f on the early returns (masked 7); arg0/arg1 and cpu/p s-register pairs swapped; tried early return 0, declaration order, no state local
#ifdef NON_MATCHING
s32 func_800F92FC_WhackAPlant(omObjData* arg0, omObjData* arg1) {
    WAPPlayerWork* w;
    WAPCpu* cpu;
    WAPPlant* p;
    s16 mdl;
    s32 state;

    w = arg0->unk_50;
    cpu = w->unkE4;
    p = ((WAPPlantWork*)arg1->unk_50)->unk68;
    mdl = D_800FB6FC_WhackAPlant->model[p->unk4];
    state = p->unk0;
    if (state == 3) {
        return 1;
    }
    if (w->unk38 >= 0.0f && w->unk38 < 1000.0f) {
        if (state != 2) {
            func_80025BB8(mdl, D_800FB6FC_WhackAPlant->motion[2]);
            func_80025EB4(mdl, 2, 0);
        }
        if (p->unk0 == 0 || p->unk0 == 1 || p->unk0 == 2) {
            D_800FB6F4_WhackAPlant--;
            if (D_800FB6F4_WhackAPlant == 0 && D_800FB69A_WhackAPlant == 8) {
                func_800601D4(0x28);
                D_800FB740_WhackAPlant = 2;
                D_800FB730_WhackAPlant = 0;
                func_800258EC(D_800FB700_WhackAPlant->model[1], 4, 4);
                D_800FB700_WhackAPlant->model[1] = 0;
                D_800FB700_WhackAPlant->func_ptr = func_800F7AE0_WhackAPlant;
            }
        }
        p->unk0 = 3;
        p->unk6 = p->unkC;
        func_80060F04(D_800FB720_WhackAPlant, 5, 0, 5);
        D_800FB712_WhackAPlant++;
        func_800184BC(arg0, 6);
        w->unk40 = 0.0f;
        cpu->unk24 = 1;
        if (ContStkX[w->unk56] != 0 || ContStkY[w->unk56] != 0) {
            w->unk3C = func_800B0CD8(-(f32)ContStkX[w->unk56], ContStkY[w->unk56]) + 180.0f;
            func_80009E20(arg0);
        }
        if (ContBtn[w->unk56] & 0x8000) {
            D_800B896C = 3.0f;
            D_800B8968 = 0.13f;
            w->unk38 = -1.35f;
            cpu->unk0 = 2;
        } else {
            D_800B896C = 4.0f;
            w->unk38 = -1.2f;
            D_800B8968 = 0.14f;
            cpu->unk0 = 1;
        }
        cpu->unk6++;
        func_800F968C_WhackAPlant(8, cpu->unk6 * 0.5f + 0.5f, arg1->trans.x, arg0->trans.y, arg1->trans.z);
        func_80060540(cpu->unk6 + 0x241, 0);
        func_800F998C_WhackAPlant(p->unk4);
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0F_WhackAPlant/131FA0", func_800F92FC_WhackAPlant);
#endif
void func_800F968C_WhackAPlant(s16 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    omObjData* obj;
    WAPRing* r;
    s16* mdl;
    s32 i;
    WAPPots* pots;
    s16 slot;

    pots = D_800FB6FC_WhackAPlant->unk_50;
    for (i = 0; i < 3; i++) {
        if (pots->unk16[i] == 0) {
            slot = i;
            pots->unk16[i] = 1;
            break;
        }
    }
    if (i != 3) {
        obj = omAddObj(0xC, 0, 0, -1, func_800F97F8_WhackAPlant);
        r = func_80023684(sizeof(WAPRing), 0x7918);
        obj->unk_50 = r;
        omSetTra(obj, arg2, arg3, arg4);
        r->unk8 = 0xA;
        r->unk4 = 20.0f;
        r->unk0 = slot;
        r->unkC = arg1;
        r->unk10 = 0.0f;
        r->unk14 = 1.72f;
        r->unk18 = arg0;
        mdl = &D_800FB6FC_WhackAPlant->model[(u16)slot * 8 + 9];
        for (i = 0; i < 8; i++) {
            func_800258EC(*mdl, 4, 0);
            mdl++;
        }
    }
}
void func_800F97F8_WhackAPlant(omObjData* arg0) {
    WAPRing* r;
    s16* mdl;
    WAPPots* pots;
    s32 i;
    f32 a;
    f32 x;
    f32 z;

    r = arg0->unk_50;
    mdl = &D_800FB6FC_WhackAPlant->model[r->unk0 * 8 + 9];
    pots = D_800FB6FC_WhackAPlant->unk_50;
    i = 0;
    if (--r->unk8 == 0) {
        for (i = 0; i < 8; i++) {
            func_800258EC(*mdl++, 4, 4);
        }
        pots->unk16[r->unk0] = 0;
        omDelObj(arg0);
        return;
    }
    arg0->trans.y -= r->unk10;
    r->unk10 *= r->unk14;
    for (i = 0; i < 8; i++) {
        a = i * 45.0f;
        x = func_800AEFD0(a) * r->unk4;
        z = func_800AEAC0(a) * r->unk4;
        func_80025798(*mdl, x + arg0->trans.x, arg0->trans.y, z + arg0->trans.z);
        func_80025830(*mdl, r->unkC, r->unkC, r->unkC);
        mdl++;
    }
    r->unk4 += 25.0f;
}
void func_800F998C_WhackAPlant(u16 arg0) {
    omObjData* obj;
    WAPCoin* c;
    s32 i;
    u16 mdl;

    for (i = 0; i < 9; i++) {
        if (D_800FB6EA_WhackAPlant[i] == 0) {
            break;
        }
    }
    if (i != 9) {
        obj = omAddObj(0xC, 1, 0, 1, func_800F9AF4_WhackAPlant);
        obj->unk_50 = func_80023684(sizeof(WAPCoin), 0x7918);
        omSetTra(obj, D_800FB580_WhackAPlant[arg0][0], 370.0f, D_800FB580_WhackAPlant[arg0][1]);
        omSetSca(obj, 2.0f, 2.0f, 2.0f);
        c = obj->unk_50;
        c->unk2 = 0;
        c->unk4 = 20.0f;
        c->unk8 = 0;
        c->unk0 = i;
        D_800FB6EA_WhackAPlant[i] = 1;
        obj->model[0] = mdl = D_800ECDE0[D_800FB6C0_WhackAPlant[i]].unk_00;
        func_800258EC(mdl, 4, 0);
        func_8001E268(D_800FB6C0_WhackAPlant[i], 3, 0);
        func_8001E2A8(D_800FB6C0_WhackAPlant[i], 0);
    }
}
void func_800F9AF4_WhackAPlant(omObjData* arg0) {
    WAPCoin* c;
    s32 bits;

    c = arg0->unk_50;
    bits = arg0->unk_10;
    if (bits != 0) {
        arg0->unk_10 = 0;
        if (bits == 1 && c->unk2 != 1) {
            c->unk8 = 0xF;
        }
    }
    c->unk8++;
    switch (c->unk2) {
    case 0:
        omSetTra(arg0, arg0->trans.x, arg0->trans.y + c->unk4, arg0->trans.z);
        c->unk4 *= 0.85f;
        if (c->unk8 == 0x10) {
            c->unk2 = 1;
            c->unk8 = 0;
            func_800258EC(arg0->model[0], 4, 4);
            arg0->model[0] = D_800ECDE0[D_800FB6D8_WhackAPlant[c->unk0]].unk_00;
            func_800258EC(arg0->model[0], 4, 0);
            omSetSca(arg0, 4.0f, 4.0f, 4.0f);
            func_8001E268(D_800FB6D8_WhackAPlant[c->unk0], 3, 0);
            func_8001E2A8(D_800FB6D8_WhackAPlant[c->unk0], 0);
            D_800FB704_WhackAPlant->work[3]++;
            func_8005DC18(D_800FB704_WhackAPlant, 1);
            GwPlayer[D_800FB720_WhackAPlant].coins_mg++;
            func_80060540(0xFC, 0);
        }
        break;
    case 1:
        if (c->unk8 == 0x10) {
            func_800258EC(arg0->model[0], 4, 4);
            D_800FB6EA_WhackAPlant[c->unk0] = 0;
            omDelObj(arg0);
            if (D_800FB6FC_WhackAPlant->work[1] == 0 && D_800ED618[1].num == 0) {
                func_8005DC18(D_800FB6FC_WhackAPlant, 1);
            }
        }
        break;
    }
}
void func_800F9D38_WhackAPlant(omObjData* arg0) {
    D_800FB6A4_WhackAPlant = func_80019060(D_800FB6A2_WhackAPlant, 0, 1);
    func_80018D84(D_800FB6A4_WhackAPlant, 0x8000);
    D_800FB69E_WhackAPlant = func_80019060(D_800FB69C_WhackAPlant, 0, 1);
    D_800FB6A0_WhackAPlant = func_80019060(D_800FB69C_WhackAPlant, 0, 1);
    func_80018D84(D_800FB69E_WhackAPlant, 0x8000);
    func_80018D84(D_800FB6A0_WhackAPlant, 0x8000);
    SetBasicSpritePos(D_800FB6A4_WhackAPlant, 0x8E, 0x20);
    SetBasicSpritePos(D_800FB69E_WhackAPlant, 0xA2, 0x20);
    SetBasicSpritePos(D_800FB6A0_WhackAPlant, 0xAA, 0x20);
    arg0->work[0] = 0;
    arg0->work[1] = 0;
    arg0->work[2] = 0;
    arg0->work[3] = 0;
    arg0->scale.y = 1.0f;
    arg0->func_ptr = &func_800F9E44_WhackAPlant;
}

void func_800F9E44_WhackAPlant(omObjData* arg0) {
    s32 temp_v1;
    u32 temp_s0;
    s32 temp_s1;
    
    temp_v1 = arg0->unk_10;
    
    if (temp_v1 != 0) {
        arg0->unk_10 = 0;
        if (temp_v1 == 1) {
            arg0->work[0] += arg0->work[3];
            arg0->work[3] = 0;
            arg0->work[1] = 2;
            arg0->scale.y = 1.0f;
        }
    }
    
    switch (arg0->work[1]) {
    case 2:
        arg0->scale.y += 0.3f;
        if (arg0->scale.y >= 2.4f) {
            arg0->work[1] = 4;
            arg0->scale.y = 2.4f;
        }
        break;

    case 4:
        arg0->scale.y -= 0.3f;
        if (arg0->scale.y <= 1.0f) {
            arg0->work[1] = 0;
            arg0->scale.y = 1.0f;
        }
        break;
    }

    temp_s1 = arg0->work[0];
    temp_s0 = arg0->work[0];
    temp_s0 = temp_s0 / 10;
    func_80018E50(D_800FB69E_WhackAPlant, temp_s0, 0);
    func_80018E50(D_800FB6A0_WhackAPlant, temp_s1 - (temp_s0 * 0xA), 0);
    SetBasicSpriteSize(D_800FB69E_WhackAPlant, 1.0f, arg0->scale.y);
    SetBasicSpriteSize(D_800FB6A0_WhackAPlant, 1.0f, arg0->scale.y);
    SetBasicSpritePos(D_800FB69E_WhackAPlant, 0xA0, 32.0f - ((arg0->scale.y - 1.0f) * 6.0f));
    SetBasicSpritePos(D_800FB6A0_WhackAPlant, 0xB0, 32.0f - ((arg0->scale.y - 1.0f) * 6.0f));
}


void func_800FA078_WhackAPlant(void) {
    switch (D_800FB710_WhackAPlant) {
    case 0:
        D_800FB710_WhackAPlant = 1;
        break;
    case 1:
        if (func_80072718() == 0) {
            D_800FB710_WhackAPlant = 2;
            func_80060128(0x1F);
            D_800FB690_WhackAPlant = 0x3C;
        }
        break;
    case 2:
        if (D_800FB690_WhackAPlant != 0) {
            if (--D_800FB690_WhackAPlant == 0) {
                func_80060540(0x24B, 0);
            }
        }
        break;
    case 3:
        if (D_800FB690_WhackAPlant != 0) {
            if (--D_800FB690_WhackAPlant == 0) {
                func_80060540(0x24B, 0);
            }
        }
        D_800FB710_WhackAPlant = 4;
        GMesCreate(0);
        break;
    case 4:
        if (D_800FB690_WhackAPlant != 0) {
            if (--D_800FB690_WhackAPlant == 0) {
                func_80060540(0x24B, 0);
            }
        }
        if (GMesStatAllGet() == 0 || (GMesStatAllGet() & 2)) {
            D_800FB740_WhackAPlant = 1;
            D_800ED430 = 1;
            D_800FB700_WhackAPlant->func_ptr = func_800F7714_WhackAPlant;
        }
        break;
    }
}
void func_800FA1E0_WhackAPlant(void) {
    switch (D_800FB730_WhackAPlant) {
    case 0:
        if (D_800FB622_WhackAPlant == 0) {
            if (D_800FB698_WhackAPlant == 0) {
                if (D_800FB704_WhackAPlant->work[0] == 0) {
                    GMesCreate(0xE);
                } else {
                    GMesCreate(2);
                }
            } else {
                GMesCreate(2);
                D_800FB730_WhackAPlant = 0xB;
            }
            D_800FB622_WhackAPlant = 1;
        }
        break;
    case 1:
        D_800FB694_WhackAPlant = 0x1E;
        D_800FB730_WhackAPlant = 2;
        break;
    case 2:
        D_800FB724_WhackAPlant.x += 0.0f;
        D_800FB724_WhackAPlant.y += -26.666666f;
        D_800FB724_WhackAPlant.z += -14.8f;
        D_800FB714_WhackAPlant.x += 0.0f;
        D_800FB714_WhackAPlant.y += 9.0f;
        D_800FB714_WhackAPlant.z += -9.333333f;
        D_800FB734_WhackAPlant.x += 0.0f;
        D_800FB734_WhackAPlant.y += 0.011028979f;
        D_800FB734_WhackAPlant.z += 0.024771493f;
        if (--D_800FB694_WhackAPlant == 0) {
            D_800FB730_WhackAPlant = 5;
        }
        break;
    case 5:
        if (GMesStatAllGet() == 0 || (GMesStatAllGet() & 2)) {
            if (D_800FB712_WhackAPlant == 0) {
                func_800184BC(D_800FB700_WhackAPlant, 0xE);
                func_80060128(0x34);
                D_800FB694_WhackAPlant = 0x60;
                D_800FB730_WhackAPlant = 0xA;
                D_800FB696_WhackAPlant = 0x44A;
                D_800FB624_WhackAPlant = 0x12;
            } else if (D_800FB712_WhackAPlant < 0xA) {
                func_800184BC(D_800FB700_WhackAPlant, 0xD);
                D_800FB694_WhackAPlant = 0x60;
                D_800FB730_WhackAPlant = 0xA;
                func_80060128(0x35);
                D_800FB696_WhackAPlant = -1;
                D_800FB624_WhackAPlant = 0;
            } else if (D_800FB712_WhackAPlant != 0x24) {
                func_800184BC(D_800FB700_WhackAPlant, 0xD);
                func_80060128(0x33);
                D_800FB694_WhackAPlant = 0x60;
                D_800FB730_WhackAPlant = 0xA;
                D_800FB696_WhackAPlant = 0x451;
                D_800FB624_WhackAPlant = 0x24;
            } else {
                func_800184BC(D_800FB700_WhackAPlant, 0xD);
                func_80060128(0x37);
                D_800FB694_WhackAPlant = 0x60;
                D_800FB730_WhackAPlant = 0xA;
                D_800FB696_WhackAPlant = 0x451;
                D_800FB624_WhackAPlant = 0x30;
            }
        }
        break;
    case 10:
        if (D_800FB624_WhackAPlant != 0) {
            if (--D_800FB624_WhackAPlant == 0) {
                func_80060540(GwPlayer[D_800FB720_WhackAPlant].character + D_800FB696_WhackAPlant, 0);
            }
        }
        if (--D_800FB694_WhackAPlant == 0) {
            D_800FB730_WhackAPlant = 7;
            func_800184BC(D_800FB700_WhackAPlant, 0);
            D_800FB694_WhackAPlant = 0x5A;
            D_800FB700_WhackAPlant->func_ptr = func_800F8098_WhackAPlant;
        }
        break;
    case 7:
        if (--D_800FB694_WhackAPlant == 0) {
            D_800FB730_WhackAPlant = 8;
            func_800726AC(0, 0x14);
        }
        break;
    case 8:
        if (func_80072718() == 0) {
            D_800FB608_WhackAPlant = 1;
        }
        break;
    case 11:
        if (GMesWait() != 1) {
            D_800FB730_WhackAPlant = 8;
            func_800726AC(0, 0x14);
        }
        break;
    }
}
void func_800FA668_WhackAPlant(void) {
    if ((D_800FB608_WhackAPlant != 0) || (D_800F5144 != 0)) {
        func_800FB4C0_WhackAPlant(131);
        func_800601D4(40);
    }
}

void func_800FA6AC_WhackAPlant(s16 arg0, f32 arg1) {
    unk2C0C0StructC0* c0;
    unk2C0C0StructE0* v;
    s16 i;
    u16 n;
    s32 rb;
    s32 g;

    c0 = D_800F2B7C[arg0].unk_6C;
    n = c0->unk_72;
    v = c0->unk_08[D_800F37F0];
    for (i = 0; i < (s16)n; i++) {
        rb = arg1 * 210.0f;
        g = arg1 * 255.0f;
        v->unk_0C.r = rb;
        v->unk_0C.g = g;
        v->unk_0C.b = rb;
        v++;
    }
}
// NON_MATCHING: w/cpu in swapped saved registers, one load/store order (masked 2)
#ifdef NON_MATCHING
void func_800FA760_WhackAPlant(omObjData* arg0) {
    f32 dist;
    u16 pot;
    f32 dist2;
    u16 pot2;
    WAPCpu* cpu;
    WAPPlayerWork* w;
    f32 x;
    f32 z;
    f32 angle;
    u16 diff;
    u16 r;
    u16 inside;
    s32 mot;
    omObjData* plant;
    s32 port;

    w = arg0->unk_50;
    cpu = w->unkE4;
    x = arg0->trans.x;
    z = arg0->trans.z;
    port = w->unk56;
    ContBtnTrg[port] = 0;
    ContStkX[port] = ContStkY[port] = 0;
    diff = GwPlayer[D_800FB720_WhackAPlant].cpu_difficulty;
    inside = 0;
    switch (diff) {
    case 0:
        r = 20;
        break;
    case 1:
        r = (u8)(rand8() % 90);
        break;
    case 2:
        r = (u8)(rand8() % 50);
        break;
    case 3:
        r = (u8)(rand8() % 30);
        break;
    }
    if ((x > -320.0f) & (x < 320.0f)) {
        if ((z > -320.0f) & (z < 320.0f)) {
            inside = 1;
        }
    }
    if (!inside) {
        angle = func_800B0CD8(-z, x);
        ContStkX[w->unk56] = -func_800AEFD0(angle) * 80.0f;
        ContStkY[w->unk56] = -func_800AEAC0(angle) * 80.0f;
        ContBtnTrg[w->unk56] |= 0x8000;
        ContBtn[w->unk56] |= 0x8000;
        return;
    }
    mot = func_80017A60(arg0);
    if (cpu->unk14 == 0) {
        angle = func_800FAF34_WhackAPlant(x, z, 0xFFFF, &dist, &pot);
        cpu->unk18 = angle;
        cpu->unk14 = func_800FB138_WhackAPlant();
        cpu->unk1C = dist;
        cpu->unk20 = pot;
    } else {
        angle = cpu->unk18;
        dist = cpu->unk1C;
        pot = cpu->unk20;
        cpu->unk14--;
    }
    if (angle >= 1000.0f) {
        return;
    }
    if (func_800FAF34_WhackAPlant(D_800FB580_WhackAPlant[pot][0], D_800FB580_WhackAPlant[pot][1], pot, &dist2, &pot2) != 1000.0f) {
        if (((dist2 > 450.0f) & ((u16)mot == 0x20)) && r < 10) {
            ContBtn[w->unk56] |= 0x8000;
        }
    }
    if (dist < 150.0f) {
        if (cpu->unk2 != pot || (plant = func_8005DB5C_s16(0, cpu->unk2), ((WAPPlantWork*)plant->unk_50)->unk68->unk0 != 0) || plant->trans.y > 70.0f) {
            ContBtnTrg[w->unk56] |= 0x8000;
        }
    }
    switch (diff) {
    case 0:
        dist = 2.0f * dist;
        if (dist > 80.0f) {
            dist = (u8)(rand8() % 20) + 0x10;
        }
        if (cpu->unk24 != 0) {
            ContStkX[w->unk56] = ContStkY[w->unk56] = 0;
            return;
        }
        break;
    case 1:
        dist = 2.0f * dist;
        if (dist > 80.0f) {
            dist = (u8)(rand8() % 30) + 0x10;
        }
        if (cpu->unk24 != 0) {
            ContStkX[w->unk56] = ContStkY[w->unk56] = 0;
            if ((u8)(rand8() % 10) >= 8) {
                cpu->unk24 = 0;
            }
            return;
        }
        break;
    case 2:
        dist = 2.0f * dist;
        if (dist > 80.0f) {
            dist = (u8)(rand8() % 26) + 0x1E;
        }
        break;
    case 3:
        dist = 2.0f * dist;
        if (dist > 80.0f) {
            dist = 80.0f;
        }
        break;
    }
    ContStkX[w->unk56] = func_800AEFD0(angle) * dist;
    ContStkY[w->unk56] = -func_800AEAC0(angle) * dist;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0F_WhackAPlant/131FA0", func_800FA760_WhackAPlant);
#endif
// decomp-permuter
f32 func_800FAF34_WhackAPlant(f32 arg0, f32 arg1, u16 arg2, f32 *arg3, u16 *arg4)
{
  omObjData **objs;
  f32 dx;
  f32 dz;
  f32 d;
  s32 i;
  u16 j;
  u16 found;
  WAPPots *pots;
 do { pots = D_800FB6FC_WhackAPlant->unk_50; } while (0);
  *arg4 = 9;
  *arg3 = 10000.0f;
  found = 0;
  if (pots->unk0 != 0)
  {
    objs = func_8005DB44(0);
    j = ((u8) (rand8() % 9)) - 1;
    for (i = 0; i < 9; i++)
    {
      j++;
      if (j == 9)
      {
        j = j - 9;
      }
      if ((j != arg2) && (pots->unk2[j] != 0))
      {
        if (((WAPPlantWork *) objs[j]->unk_50)->unk68->unk0 != 3)
        {
          dx = D_800FB580_WhackAPlant[j][0] - arg0;
          dz = D_800FB580_WhackAPlant[j][1] - arg1;
          d = func_800B1750((dx * dx) + (dz * dz));
          if (d < (*arg3))
          {
            *arg3 = d;
            *arg4 = j;
            found = 1;
          }
        }
      }
    }

    if (found == 1)
    {
      return func_800B0CD8(D_800FB580_WhackAPlant[*arg4][1] - arg1, D_800FB580_WhackAPlant[*arg4][0] - arg0);
    }
  }
  return 1000.0f;
}
u16 func_800FB138_WhackAPlant(void) {
    u16 n;

    switch (GwPlayer[D_800FB720_WhackAPlant].cpu_difficulty) {
    case 0:
        n = 15;
        break;
    case 1:
        n = 10;
        break;
    case 2:
        n = (u8)(rand8() % 10) + 5;
        break;
    case 3:
        rand8();
        return 0;
    }
    return rand8() % n;
}