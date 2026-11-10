#include "SlotMachine.h"

s32 D_800FE100_SlotMachine = 0;
s16 D_800FE104_SlotMachine[16] = { 1, 0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
s16 D_800FE124_SlotMachine[6] = { 16 };

void func_800F65E0_SlotMachine(void) {
    u8 cam;
    s16 i;

    func_80029090(50);
    omInitObjMan(50, 0);
    func_80060088();
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    D_800ED430 = 1;
    func_800178A0(1);
    cam = func_800178E8();
    func_80017660(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 45.0f, 80.0f, 8000.0f);
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    D_800FFCDC_SlotMachine = 0;
    D_800FFCB0_SlotMachine = 3600;
    D_800FE100_SlotMachine = _CheckFlag(0x2B);
    for (i = 0; i < 4; i++) {
        D_800FFCC8_SlotMachine[i] = NULL;
    }
    for (i = 0; i < 4; i++) {
        if (GwPlayer[i].group == 0) {
            break;
        }
    }
    D_800FFCB8_SlotMachine = i;
    D_800B895C = 15.0f;
    D_800B8960 = 0.5f;
    D_800B8964 = 1.47f;
    D_800B8968 = 0.15f;
    D_800B896C = 7.0f;
    D_800B8970 = 30.0f;
    D_800B897C = 3.3333333f;
    D_800B8980 = 18.0f;
    D_800B8984 = 13.5f;
    D_800B8988 = 9.0f;
    D_800B898C = 4.5f;
    D_800B8990 = 0.0f;
    D_800B8994 = 1.7f;
    D_800B8998 = 0.5f;
    D_800B899C = 0.147f;
    func_800090B8(0);
    D_800ED440 = 0;
    D_800F2BC0 = 0;
    D_800FFCB4_SlotMachine = omAddObj(1, 0, 0, -1, func_800F6980_SlotMachine);
    D_800F2AF8[D_800ED440++] = omAddObj(2, 20, 0, -1, func_800F69D0_SlotMachine);
    D_800F3FB0[D_800F2BC0++] = omAddObj(3, 10, 60, -1, func_800F71EC_SlotMachine);
    func_800F76E0_SlotMachine();
    func_800F8580_SlotMachine();
    osViBlack(1);
}
void func_800F6980_SlotMachine(omObjData* obj) {
    obj->func_ptr = func_800F7750_SlotMachine;
    obj->work[0] = 0;
    obj->work[1] = 0x30;
}
void func_800F699C_SlotMachine(void) {
    if (D_800FFCDC_SlotMachine < 0) {
        func_800FBD60_SlotMachine();
        omOvlReturnEx(1);
    }
}
void func_800F69D0_SlotMachine(omObjData* obj) {
    SlotGroundWork* work;
    void* file;
    s16 i;

    obj->func_ptr = func_800F99E0_SlotMachine;
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    omSetStatBit(obj, 0xA0);
    obj->unk_50 = work = func_80023684(sizeof(SlotGroundWork), 0x7918);
    func_8009B770(work, 0, sizeof(SlotGroundWork));
    work->unk_04 = 1;
    work->unk_05 = 0;
    func_800FBE84_SlotMachine(obj);
    D_800EE9A0.def[0].col[0] = D_800EE9A0.def[0].col[1] = D_800EE9A0.def[0].col[2] = 0xFF;
    D_800EE9A0.def[1].col[0] = D_800EE9A0.def[1].col[1] = D_800EE9A0.def[1].col[2] = 0xFF;
    D_800EE9A0.def[1].dir[0] = 1;
    D_800EE9A0.def[1].dir[1] = 0x40;
    D_800EE9A0.def[1].dir[2] = 0x40;
    file = DataRead(0x140013);
    D_800FFCE0_SlotMachine = func_800678A4(file);
    DataClose(file);
    D_800FFCC0_SlotMachine = func_80064EF4(1, 0);
    func_80067208((s16)D_800FFCC0_SlotMachine, 0, (s16)D_800FFCE0_SlotMachine, 0);
    func_800674BC((s16)D_800FFCC0_SlotMachine, 0, 0x404000);
    func_80067354((s16)D_800FFCC0_SlotMachine, 0, 45.0f, 1.0f);
    func_80066DC4((s16)D_800FFCC0_SlotMachine, 0, 160, 120);
    file = DataRead(0x7E);
    D_800FFCD8_SlotMachine = func_800678A4(file);
    DataClose(file);
    D_800FFCE4_SlotMachine = func_80064EF4(2, 0);
    for (i = 0; i < 2; i++) {
        func_80067208((s16)D_800FFCE4_SlotMachine, i, (s16)D_800FFCD8_SlotMachine, 0);
        func_800674BC((s16)D_800FFCE4_SlotMachine, i, 0x9000);
        func_80067354((s16)D_800FFCE4_SlotMachine, i, 1.0f, 1.0f);
        func_80066DC4((s16)D_800FFCE4_SlotMachine, i, 278 - i * 22, 192);
        func_800672B0((s16)D_800FFCE4_SlotMachine, i, 0);
    }
    for (i = 0; i < 14; i++) {
        obj->model[i] = func_800174C0(D_800FE104_SlotMachine[i] | 0x140000, 0xB9);
        func_80025798(obj->model[i], obj->trans.x, obj->trans.y, obj->trans.z);
        func_80025830(obj->model[i], obj->scale.x, obj->scale.y, obj->scale.z);
    }
    for (i = 14; i < 16; i++) {
        obj->model[i] = func_800174C0(D_800FE104_SlotMachine[i] | 0x140000, 0x419);
        obj->model[i + 2] = func_800174C0(D_800FE104_SlotMachine[i] | 0x140000, 0x419);
        func_80025798(obj->model[i], obj->trans.x, obj->trans.y, obj->trans.z);
        func_80025798(obj->model[i + 2], obj->trans.x, obj->trans.y, obj->trans.z);
        func_80025830(obj->model[i], obj->scale.x, obj->scale.y, obj->scale.z);
        func_80025830(obj->model[i + 2], obj->scale.x, obj->scale.y, obj->scale.z);
    }
    obj->model[18] = func_800174C0(D_800FE124_SlotMachine[0] | 0x140000, 0xD9);
    obj->model[19] = func_800174C0(D_800FE124_SlotMachine[0] | 0x140000, 0xD9);
    /* Retail passed an f32 1.0f (func_80009028 stores the bits into a float field): call it that
       way on the N64 only; the host passes the same bits to the s32 definition. */
    ((void (*)(omObjData*, f32, f32, f32, f32, f32))func_80009028)(obj, 1.0f, -450.0f, -1000.0f, 450.0f, 1000.0f);
    func_80009090(obj);
    func_800FC090_SlotMachine(obj->model[1]);
    func_80025798(obj->model[3], 0.0f, 280.0f, -70.0f);
    func_80025830(obj->model[3], 1.2f, 1.2f, 1.0f);
    func_80025798(obj->model[5], 0.0f, 1.25f, 0.0f);
    func_80025830(obj->model[5], 0.35f, 1.0f, 0.35f);
    func_80025798(obj->model[12], 0.0f, 0.0f, 50.0f);
    func_800258EC(obj->model[6], 4, 4);
    func_800258EC(obj->model[7], 4, 4);
    func_800258EC(obj->model[9], 4, 4);
    func_800258EC(obj->model[10], 4, 4);
    func_800258EC(obj->model[11], 4, 4);
    func_80026040(obj->model[14]);
    func_80026040(obj->model[16]);
    func_800258EC(obj->model[15], 4, 4);
    func_800258EC(obj->model[17], 4, 4);
    func_80026174(obj->model[14], obj->model[15], 0.0f);
    func_80026174(obj->model[16], obj->model[17], 0.0f);
    func_800257E4(obj->model[14], 0.0f, 180.0f, 0.0f);
    func_80025798(obj->model[16], 500.0f, 0.0f, 300.0f);
    func_80025798(obj->model[14], -500.0f, 0.0f, 300.0f);
    func_80026040(obj->model[18]);
    func_80026040(obj->model[19]);
    func_800258EC(obj->model[18], 4, 4);
    func_800258EC(obj->model[19], 4, 4);
    func_80025798(obj->model[18], 400.0f, 0.0f, -450.0f);
    func_80025798(obj->model[19], -400.0f, 0.0f, -450.0f);
    func_80025830(obj->model[18], 1.0f, 1.375f, 1.0f);
    func_80025830(obj->model[19], 1.0f, 1.375f, 1.0f);
    func_800F70A8_SlotMachine(obj->model[18], 1.5f);
}
void func_800F70A8_SlotMachine(s32 model, f32 scale) {
    unk2C0C0Struct70* tex;
    unk2C0C0StructC0* target;
    u8* px;
    s32 i;
    u8 hi;
    u8 v;

    target = D_800F2B7C[model].unk_6C;
    for (i = 0; i < 128; i++) {
        if (D_800F37AC[i].unk_28 == target) {
            break;
        }
    }
    tex = &D_800F37AC[i];
    px = tex->unk_24;
    for (i = 0; i < tex->unk_1A * tex->unk_1B; i++, px++) {
        hi = *px >> 4;
        v = (*px & 0xF) * scale;
        if (v >= 15) {
            v = 15;
        }
        *px = v + hi * 16;
    }
}
void func_800F71EC_SlotMachine(omObjData* obj) {
    s32 idle[5] = { 0x0F, 0x38, 0x39, 0x3A, 0x3B };
    s32 idle2[5] = { 0x10, 0x3C, 0x3D, 0x3E, 0x3F };
    SlotWork* work;
    SlotPlayerWork* pw;
    s32 dir;
    s32 file0;
    u8 chr;

    chr = GwPlayer[D_800FFCB8_SlotMachine].character;
    dir = D_800C59AC[chr].unk_00;
    file0 = D_800C59AC[chr].unk_04;
    work = func_800FBE84_SlotMachine(obj);
    func_80009618(1);
    func_8000979C(obj, dir, file0, (u16)D_800FFCB8_SlotMachine, 0x6D9, 0x2D9);
    obj->func_ptr = func_800FAE34_SlotMachine;
    pw = SLOT_PLAYER(obj);
    pw->unk_DC = NULL;
    obj->model[3] = LoadFormFile(0x19, 0x68D);
    obj->model[4] = LoadFormFile(0x1A, 0x68D);
    obj->model[6] = LoadFormFile(0x1B, 0x68D);
    obj->model[5] = LoadFormFile(0x1C, 0x68D);
    obj->model[7] = LoadFormFile(0x1E, 0x68D);
    obj->model[8] = LoadFormFile(0x1D, 0x68D);
    func_800187D0(obj, 0, dir, 1, 0);
    func_800187D0(obj, 1, dir | 1, 1, 0);
    func_800187D0(obj, 2, dir | 3, 1, 0);
    func_800187D0(obj, 6, dir | 5, 1, 0x13);
    func_800187D0(obj, 9, dir | 0xA, 1, 0x27);
    func_8001874C(obj, 0xB, dir | 0xB, 1, 0);
    func_8001874C(obj, 0xD, dir | idle[rand8() & 1], 1, 0x78);
    func_8001874C(obj, 0xE, dir | idle2[1], 1, 0x78);
    func_800187D0(obj, 0x11, dir | 0x18, 0, 0);
    func_800187D0(obj, 0x12, dir | 0x1C, 2, 0);
    func_800187D0(obj, 0x13, dir | 0x1D, 2, 0);
    func_800187D0(obj, 0xA, dir | 0x1E, 1, 0x27);
    func_800187D0(obj, 0x16, dir | 0x24, 1, 0);
    func_8001874C(obj, 0x14, dir | 0x5F, 2, 0);
    func_8001874C(obj, 3, dir | 0x60, 1, 0);
    func_8001874C(obj, 4, dir | 0x61, 1, 0);
    func_8001874C(obj, 0x15, dir | 0x62, 0, 0);
    func_8001874C(obj, 0x1E, dir | 0x63, 0, 0);
    func_8001874C(obj, 0x1F, dir | 0x64, 0, 0);
    func_8001874C(obj, 0x20, dir | 0x67, 0, 0);
    func_8001874C(obj, 0x21, dir | 0x68, 2, 0);
    func_8001874C(obj, 0x22, dir | 0x69, 2, 0);
    switch ((u32)dir >> 16) {
        case 4:
            func_8001874C(obj, 0x23, dir | 0x24, 1, 0);
            break;
        case 5:
            func_8001874C(obj, 0x23, dir | 0x28, 1, 0);
            work->unk_5E = -90;
            pw->unk_34 = 220.0f;
            break;
        case 1:
        case 2:
            func_8001874C(obj, 0x23, dir | 0x24, 1, 0);
            break;
        case 3:
        case 6:
            func_8001874C(obj, 0x23, dir | 0x5F, 1, 0);
            break;
    }
    obj->trans.x = -400.0f;
    obj->trans.y = 1400.0f;
    obj->trans.z = -350.0f;
    work->unk_10 = obj->trans.x;
    work->unk_14 = obj->trans.y;
    work->unk_18 = obj->trans.z;
    func_800090C4(obj, 0, 2);
}