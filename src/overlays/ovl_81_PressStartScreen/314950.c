#include "common.h"
#include "engine/esprite.h"
#include "sprite65770.h"

void func_800F69C8_PressStartScreen(omObjData* arg0);
void func_800F6EB4_PressStartScreen(unk2C0C0StructC0* arg0, f32 arg1, s16 arg2);
void func_800F70C4_PressStartScreen(omObjData* arg0);
void func_800F7120_PressStartScreen(omObjData* arg0);
void func_800F717C_PressStartScreen(omObjData* arg0);
void func_800F71D8_PressStartScreen(void);
void func_800F7240_PressStartScreen(void);
void func_800F7844_PressStartScreen(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
s16 func_800F792C_PressStartScreen(void);
s16 func_800F7A94_PressStartScreen(void);
void func_800F7BFC_PressStartScreen(void);
s32 func_8005AE88(void);
s32 func_80059CB8(void);
s32 func_8000C144(void);
s16 func_80050288(void);
void func_80050338(void);
void func_80050368(void);
void func_8005038C(void);
void* func_80014614(s32);
void DataCloseTemp(void*);
s16 func_80033718(unk2C0C0StructC0*, char*);

extern s8 omSysPauseEnableFlag;
extern u8 D_800EDEB0;
extern u8 D_800C572F;
s32 D_800F7FE0_PressStartScreen = 0; /* intro phase */
s32 D_800F7FE4_PressStartScreen = 300;
Vec3f D_800F7FE8_PressStartScreen[10] = {
    { 0.0f, 100.0f, 3500.0f }, { 0.0f, -100.0f, 3500.0f }, { 0.0f, 300.0f, 3500.0f },
    { 0.0f, -300.0f, 3500.0f }, { 0.0f, 300.0f, 3500.0f }, { 0.0f, -300.0f, 3500.0f },
    { 0.0f, 300.0f, 3500.0f }, { 0.0f, 100.0f, 3500.0f }, { 0.0f, -100.0f, 3500.0f },
    { 0.0f, 100.0f, 3500.0f },
};
f32 D_800F8060_PressStartScreen[10] = { 5.0f, -5.0f, 5.0f, -5.0f, 5.0f, -5.0f, 5.0f, -5.0f, 5.0f, -5.0f };
f32 D_800F8088_PressStartScreen[10] = { 8.0f, 7.0f, 6.0f, 4.0f, 2.0f, 2.0f, 4.0f, 6.0f, 7.0f, 8.0f };
s32 D_800F80B0_PressStartScreen = 0;
f32 D_800F80B4_PressStartScreen = 0.0f;
extern Process* D_800F80D0_PressStartScreen;
extern s16 D_800F80D4_PressStartScreen;
extern s16 D_800F80D6_PressStartScreen;
extern s16 D_800F80D8_PressStartScreen;
extern omObjData* D_800F80DC_PressStartScreen;
extern omObjData* D_800F80E0_PressStartScreen;
extern omObjData* D_800F80E4_PressStartScreen;
extern Vec3f D_800F80E8_PressStartScreen[10];
extern Vec3f D_800F8160_PressStartScreen[10];
extern u32 D_800F383C;

void func_800F65E0_PressStartScreen(void) {
    s32 i;

    omSysPauseEnableFlag = 1;
    InitCameras(1);
    omInitObjMan(0x10, 4);
    func_8006CEA0();
    func_8005AD18();
    func_8002890C(0xFF, 0xFF, 0xFF);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    func_8001D494(0, 30.0f, 100.0f, 9000.0f);
    CRot.x = CRot.y = CRot.z = 0.0f;
    Center.x = 0.0f;
    Center.y = 0.0f;
    Center.z = 0.0f;
    CZoom = 3400.0f;
    func_80023504(1, 0.0f, 30.0f, 115.0f);
    func_800234B8(1, 0xFF, 0xFF, 0xFF);
    func_80023504(2, -103.0f, -32.0f, -51.0f);
    func_800234B8(2, 0x64, 0x50, 0x14);
    D_800F80D0_PressStartScreen = omAddPrcObj(func_800F7BFC_PressStartScreen, 0xA, 0, 0);
    omAddObj(0x3E8, 0, 0, -1, func_800F717C_PressStartScreen);
    func_8005AE88();
    D_800F80DC_PressStartScreen = omAddObj(1, 0xD, 0, -1, func_800F69C8_PressStartScreen);
    D_800F80DC_PressStartScreen->model[0] = LoadFormFile(0x90082, 0x2B9);
    D_800F80DC_PressStartScreen->model[1] = LoadFormFile(0x90083, 0x2B9);
    D_800F80DC_PressStartScreen->model[2] = LoadFormFile(0x90084, 0x2B9);
    func_800258EC(D_800F80DC_PressStartScreen->model[0], 4, 4);
    for (i = 0; i < 10; i++) {
        D_800F80DC_PressStartScreen->model[i + 3] = LoadFormFile((i + 0x78) | 0x90000, 0x2B9);
        func_80025798(D_800F80DC_PressStartScreen->model[i + 3], 0.0f, 0.0f, 4000.0f);
    }
    D_800F80E0_PressStartScreen = omAddObj(1, 1, 0, -1, func_800F70C4_PressStartScreen);
    D_800F80E0_PressStartScreen->model[0] = LoadFormFile(0x90085, 0x2B9);
    D_800F80E0_PressStartScreen->rot.x = 8.0f;
    D_800F80E0_PressStartScreen->rot.z = 45.0f;
    func_80026040(D_800F80E0_PressStartScreen->model[0]);
    omSetStatBit(D_800F80E0_PressStartScreen, 0xA0);
    D_800F80E4_PressStartScreen = omAddObj(1, 1, 0, -1, func_800F7120_PressStartScreen);
    D_800F80E4_PressStartScreen->model[0] = LoadFormFile(0x90085, 0x2B9);
    D_800F80E4_PressStartScreen->rot.x = 352.0f;
    D_800F80E4_PressStartScreen->rot.z = 135.0f;
    func_80026040(D_800F80E4_PressStartScreen->model[0]);
    func_800258EC(D_800F80E0_PressStartScreen->model[0], 4, 4);
    func_800258EC(D_800F80E4_PressStartScreen->model[0], 4, 4);
    if (D_800EDEB0 == 0xFF) {
        SetFadeInTypeAndTime(0xFF, 1);
    } else {
        SetFadeInTypeAndTime(0xFF, 30);
    }
}

// register allocation and scheduling; retail keeps i*2 as a second induction variable (masked 16)
#ifdef NON_MATCHING
void func_800F69C8_PressStartScreen(omObjData* arg0) {
    f32 rot;
    s32 i;

    func_80025798(arg0->model[1], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_800257E4(arg0->model[1], arg0->rot.x, arg0->rot.y, arg0->rot.z);
    func_80025798(arg0->model[2], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_800257E4(arg0->model[2], arg0->rot.x, arg0->rot.y, arg0->rot.z);
    if (D_800F7FE0_PressStartScreen != 0) {
        func_800258EC(arg0->model[1], 4, 0);
        func_800258EC(arg0->model[2], 4, 0);
    } else {
        func_800258EC(arg0->model[1], 4, 4);
        func_800258EC(arg0->model[2], 4, 4);
    }
    if (D_800F7FE0_PressStartScreen == 2) {
        if (++D_800F80B0_PressStartScreen >= 16) {
            D_800F80B0_PressStartScreen = 15;
        }
        for (i = 0; i < 10; i++) {
            func_80025798(arg0->model[i + 3],
                          (D_800F7FE8_PressStartScreen[i].x - arg0->trans.x) * (f32)(15 - D_800F80B0_PressStartScreen) / 15.0f + arg0->trans.x,
                          (D_800F7FE8_PressStartScreen[i].y - arg0->trans.y) * (f32)(15 - D_800F80B0_PressStartScreen) / 15.0f + arg0->trans.y,
                          (D_800F7FE8_PressStartScreen[i].z - arg0->trans.z) * (f32)(15 - D_800F80B0_PressStartScreen) / 15.0f + arg0->trans.z);
            if (D_800F8060_PressStartScreen[i] > 0.0f) {
                rot = D_800F8060_PressStartScreen[i] - D_800F80B0_PressStartScreen * 0.5f;
            } else {
                rot = D_800F80B0_PressStartScreen * 0.5f + D_800F8060_PressStartScreen[i];
            }
            if (rot < 0.0f) {
                rot += 360.0f;
            }
            func_800257E4(arg0->model[i + 3], 0.0f, 0.0f, rot);
        }
    }
    if (D_800F7FE0_PressStartScreen == 3) {
        for (i = 0; i < 10; i++) {
            D_800F80E8_PressStartScreen[i].x += (D_800F80DC_PressStartScreen->trans.x - D_800F80E8_PressStartScreen[i].x) / D_800F8088_PressStartScreen[i];
            D_800F80E8_PressStartScreen[i].y += (D_800F80DC_PressStartScreen->trans.y - D_800F80E8_PressStartScreen[i].y) / D_800F8088_PressStartScreen[i];
            D_800F80E8_PressStartScreen[i].z += (D_800F80DC_PressStartScreen->trans.z - D_800F80E8_PressStartScreen[i].z) / D_800F8088_PressStartScreen[i];
            D_800F8160_PressStartScreen[i].x += (D_800F80DC_PressStartScreen->rot.x - D_800F8160_PressStartScreen[i].x) / D_800F8088_PressStartScreen[i];
            D_800F8160_PressStartScreen[i].y += (D_800F80DC_PressStartScreen->rot.y - D_800F8160_PressStartScreen[i].y) / D_800F8088_PressStartScreen[i];
            D_800F8160_PressStartScreen[i].z += (D_800F80DC_PressStartScreen->rot.z - D_800F8160_PressStartScreen[i].z) / D_800F8088_PressStartScreen[i];
            func_80025798(arg0->model[i + 3], D_800F80E8_PressStartScreen[i].x, D_800F80E8_PressStartScreen[i].y, D_800F80E8_PressStartScreen[i].z);
            func_800257E4(arg0->model[i + 3], D_800F8160_PressStartScreen[i].x, D_800F8160_PressStartScreen[i].y, D_800F8160_PressStartScreen[i].z);
        }
    }
    if (D_800F7FE0_PressStartScreen != 0) {
        for (i = 0; i < 10; i++) {
            func_800258EC(arg0->model[i + 3], 4, 0);
        }
    } else {
        for (i = 0; i < 10; i++) {
            func_800258EC(arg0->model[i + 3], 4, 4);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_PressStartScreen/314950", func_800F69C8_PressStartScreen);
#endif

// scheduling of the unk_80 load: retail loads it before the index multiply (masked 2, raw 2; tried base local, pointer + index)
#ifdef NON_MATCHING
void func_800F6EB4_PressStartScreen(unk2C0C0StructC0* arg0, f32 arg1, s16 arg2) {
    unk2C0C0Struct30* obj;
    unk2C0C0StructE0* src;
    unk2C0C0StructE0* dst;
    s16 x;
    u16 y, z;
    f32 fx;
    f32 wave;
    s16 n;
    s16 i;

    obj = &arg0->unk_80[arg2];
    src = arg0->unk_04 + obj->unk_0A;
    dst = arg0->unk_08[D_800F37F0] + obj->unk_0A;
    n = obj->unk_0C;
    for (i = 0; i < n; i++) {
        y = src->unk_02;
        z = src->unk_04;
        x = src->unk_00;
        fx = x;
        wave = func_800AEFD0((fx - arg1) * 40.0f) * (40.0f - fx);
        *dst = *src;
        dst->unk_00 = x;
        dst->unk_02 = y;
        dst->unk_04 = (s16)z + wave;
        src++;
        dst++;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_PressStartScreen/314950", func_800F6EB4_PressStartScreen);
#endif

void func_800F7048_PressStartScreen(s16 arg0, f32 arg1, char* arg2) {
    unk2C0C0StructC0* model = D_800F2B7C[arg0].unk_6C;
    s8 idx = func_80033718(model, arg2);

    if (idx != -1) {
        func_800F6EB4_PressStartScreen(model, arg1, idx);
    }
}

void func_800F70C4_PressStartScreen(omObjData* arg0) {
    func_800F7048_PressStartScreen(arg0->model[0], D_800F80B4_PressStartScreen, "01a_011");
    arg0->trans.z = D_800F80DC_PressStartScreen->trans.z + 100.0f;
}

void func_800F7120_PressStartScreen(omObjData* arg0) {
    func_800F7048_PressStartScreen(arg0->model[0], D_800F80B4_PressStartScreen, "01a_011");
    arg0->trans.z = D_800F80DC_PressStartScreen->trans.z + 200.0f;
}

void func_800F717C_PressStartScreen(omObjData* arg0) {
    if (D_800F5144 != 0) {
        func_800601D4(0x28);
        func_80072724(0, 0, 0);
        func_800726AC(0, 0x1E);
        arg0->func_ptr = func_800F71D8_PressStartScreen;
    }
}

void func_800F71D8_PressStartScreen(void) {
    if (func_80072718() == 0) {
        func_80050338();
        func_80070ED4();
        if (D_800F7FE4_PressStartScreen != 0) {
            omOvlCallEx(0x69, 0, 0x91);
            return;
        }
        omOvlGotoEx(0x66, 1, 0x91);
    }
}

void func_800F7240_PressStartScreen(void) {
    f32 dy;
    s32 i;

    while (func_80072718() != 0) {
        HuPrcVSleep();
    }
    D_800F7FE0_PressStartScreen = 0;
    D_800F80DC_PressStartScreen->trans.x = 0;
    D_800F80DC_PressStartScreen->trans.y = -100.0f;
    D_800F80DC_PressStartScreen->trans.z = -5000.0f;
    PlaySound(0);
    func_800258EC(D_800F80DC_PressStartScreen->model[0], 4, 0);
    for (i = 0; i < 25; i++) {
        D_800F80DC_PressStartScreen->trans.z += 200.0f;
        D_800F80DC_PressStartScreen->rot.z += 14.4f;
        if (D_800F80DC_PressStartScreen->rot.z > 360.0f) {
            D_800F80DC_PressStartScreen->rot.z -= 360.0f;
        }
        if (func_80059CB8() & 0x1000) {
            return;
        }
        HuPrcVSleep();
    }
    D_800F80E0_PressStartScreen->trans.x = 1530.0f;
    D_800F80E0_PressStartScreen->trans.y = 1400.0f;
    D_800F80E4_PressStartScreen->trans.x = -1530.0f;
    D_800F80E4_PressStartScreen->trans.y = 1400.0f;
    func_800258EC(D_800F80E0_PressStartScreen->model[0], 4, 0);
    func_800258EC(D_800F80E4_PressStartScreen->model[0], 4, 0);
    PlaySound(3);
    for (i = 0; i < 33; i++) {
        D_800F80B4_PressStartScreen += 3.0f;
        if (D_800F80B4_PressStartScreen > 9.0f) {
            D_800F80B4_PressStartScreen -= 9.0f;
        }
        if (i < 25) {
            D_800F80DC_PressStartScreen->rot.z += 14.4f;
        }
        D_800F80E0_PressStartScreen->trans.x -= 50.0f;
        D_800F80E0_PressStartScreen->trans.y -= 50.0f;
        if (i == 5) {
            PlaySound(4);
        }
        if (i >= 5) {
            D_800F80E4_PressStartScreen->trans.x += 50.0f;
            D_800F80E4_PressStartScreen->trans.y -= 50.0f;
        }
        D_800F80DC_PressStartScreen->trans.z += 100.0f;
        if (D_800F80DC_PressStartScreen->rot.z > 360.0f) {
            D_800F80DC_PressStartScreen->rot.z -= 360.0f;
        }
        if (func_80059CB8() & 0x1000) {
            return;
        }
        HuPrcVSleep();
    }
    func_800258EC(D_800F80E0_PressStartScreen->model[0], 4, 4);
    func_800258EC(D_800F80E4_PressStartScreen->model[0], 4, 4);
    D_800F7FE0_PressStartScreen = 1;
    for (i = 0; i < 15; i++) {
        D_800F80DC_PressStartScreen->trans.z -= 100.0f;
        if (func_80059CB8() & 0x1000) {
            return;
        }
        HuPrcVSleep();
    }
    PlaySound(0x96);
    D_800F7FE0_PressStartScreen = 2;
    for (i = 0; i < 16; i++) {
        D_800F80DC_PressStartScreen->trans.z -= 100.0f;
        if (func_80059CB8() & 0x1000) {
            return;
        }
        HuPrcVSleep();
    }
    for (i = 0; i < 10; i++) {
        D_800F80E8_PressStartScreen[i].x = D_800F80DC_PressStartScreen->trans.x;
        D_800F80E8_PressStartScreen[i].y = D_800F80DC_PressStartScreen->trans.y;
        D_800F80E8_PressStartScreen[i].z = D_800F80DC_PressStartScreen->trans.z;
        D_800F8160_PressStartScreen[i].x = D_800F80DC_PressStartScreen->rot.x;
        D_800F8160_PressStartScreen[i].y = D_800F80DC_PressStartScreen->rot.y;
        D_800F8160_PressStartScreen[i].z = D_800F80DC_PressStartScreen->rot.z;
    }
    D_800F7FE0_PressStartScreen = 3;
    dy = 10.0f;
    for (i = 0; i < 16; i++) {
        if (i < 4) {
            D_800F80DC_PressStartScreen->rot.x -= 8.0f;
        } else {
            D_800F80DC_PressStartScreen->rot.x += 8.0f;
        }
        D_800F80DC_PressStartScreen->trans.z -= 100.0f;
        D_800F80DC_PressStartScreen->trans.y += dy;
        dy += 14.5f;
        if (func_80059CB8() & 0x1000) {
            return;
        }
        HuPrcVSleep();
    }
    func_8005038C();
    for (i = 1; i < 16; i++) {
        func_8006752C(D_800F80D6_PressStartScreen, 0, i * 17);
        if (func_80059CB8() & 0x1000) {
            return;
        }
        HuPrcVSleep();
    }
    for (i = 0; i < 12; i++) {
        func_80066DC4(D_800F80D4_PressStartScreen, 0, 0xA0, i * 8 - 0x2C);
        if (func_80059CB8() & 0x1000) {
            return;
        }
        HuPrcVSleep();
    }
    for (i = 0; i < 5; i++) {
        func_8006752C(D_800F80D8_PressStartScreen, 0, i * 3 * 17);
        if (func_80059CB8() & 0x1000) {
            return;
        }
        HuPrcVSleep();
    }
}

void func_800F7844_PressStartScreen(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    unk65770Obj* a = func_800675F4(arg0, arg1);
    unk65770Obj* b = func_800675F4(arg2, arg3);
    unk65770AnimC* frame = a->unk4C->unk0;
    u16 w = frame->unk4;
    u16 h = frame->unk6;
    u8* dst = frame->unk0;
    u8* src = b->unk4C->unk0->unk0;
    s16 i;

    for (i = 0; i < (s16)w * (s16)h; i++) {
        dst[3] = *src;
        dst += 4;
        src++;
    }
}

s16 func_800F792C_PressStartScreen(void) {
    s16 group;
    s16 mask;
    s16 sprite;
    void* data;

    group = func_80064EF4(1, 5);
    data = func_80014614(0x90072);
    sprite = func_800678A4(data);
    DataCloseTemp(data);
    func_80067208(group, 0, sprite, 0);
    func_80066DC4(group, 0, 0xA0, -0x2C);
    func_80067480(group, 0, 0xFFFF);
    func_800674BC(group, 0, 0x1008);
    func_8006752C(group, 0, 0xFF);
    func_80067384(group, 0, 0x8000);
    mask = func_80064EF4(1, 5);
    data = func_80014614(0x90073);
    sprite = func_800678A4(data);
    DataCloseTemp(data);
    func_80067208(mask, 0, sprite, 0);
    func_80067480(mask, 0, 0xFFFF);
    func_800674BC(mask, 0, 0x9008);
    func_800F7844_PressStartScreen(group, 0, mask, 0);
    return group;
}

s16 func_800F7A94_PressStartScreen(void) {
    s16 group;
    s16 mask;
    s16 sprite;
    void* data;

    group = func_80064EF4(1, 5);
    data = func_80014614(0x90074);
    sprite = func_800678A4(data);
    DataCloseTemp(data);
    func_80067208(group, 0, sprite, 0);
    func_80066DC4(group, 0, 0x109, 0x23);
    func_80067480(group, 0, 0xFFFF);
    func_800674BC(group, 0, 0x1008);
    func_8006752C(group, 0, 0);
    func_80067384(group, 0, 0x7000);
    mask = func_80064EF4(1, 5);
    data = func_80014614(0x90075);
    sprite = func_800678A4(data);
    DataCloseTemp(data);
    func_80067208(mask, 0, sprite, 0);
    func_80067480(mask, 0, 0xFFFF);
    func_800674BC(mask, 0, 0x9008);
    func_800F7844_PressStartScreen(group, 0, mask, 0);
    return group;
}

// retail sets up = 1 in a branch delay slot and again in the branch (masked 18)
#ifdef NON_MATCHING
void func_800F7BFC_PressStartScreen(void) {
    s32 spr0, spr1, obj0, obj1;
    u16 id0, id1, press;
    s32 alpha;
    s32 up;
    s32 i;

    D_800F80D4_PressStartScreen = func_800F792C_PressStartScreen();
    D_800F80D6_PressStartScreen = func_80050288();
    func_80050368();
    func_8006752C(D_800F80D6_PressStartScreen, 0, 0);
    D_800F80D8_PressStartScreen = func_800F7A94_PressStartScreen();
    if (D_800EDEB0 == 0xFF) {
        func_800F7240_PressStartScreen();
    }
    func_8005038C();
    func_8006752C(D_800F80D6_PressStartScreen, 0, 0xFF);
    func_8006752C(D_800F80D8_PressStartScreen, 0, 0xFF);
    func_80066DC4(D_800F80D4_PressStartScreen, 0, 0xA0, 0x2C);
    D_800F7FE0_PressStartScreen = 0;
    func_800258EC(D_800F80E0_PressStartScreen->model[0], 4, 4);
    func_800258EC(D_800F80E4_PressStartScreen->model[0], 4, 4);
    func_800258EC(D_800F80DC_PressStartScreen->model[0], 4, 4);
    spr0 = InitSprite(0x90076);
    spr1 = InitSprite(0x90077);
    obj0 = func_80019060((s16)spr0, 0, 1);
    obj1 = func_80019060((s16)spr1, 0, 1);
    id0 = obj0;
    SetBasicSpritePos(id0, 0xA0, 0xD4);
    func_80018D84(id0, 1);
    func_800674F4(D_800ED60C[(s16)obj0].unk_04, 0, 0xFF, 0xFF, 0xFF);
    id1 = obj1;
    SetBasicSpritePos(id1, 0x9F, 0xD3);
    func_80018D84(id1, 2);
    func_800674F4(D_800ED60C[(s16)obj1].unk_04, 0, 0, 0, 0);
    while (func_80072718() != 0) {
        HuPrcVSleep();
    }
    HuPrcVSleep();
    func_80060128(1);
    press = func_80019060((s16)InitSprite(0x90071), 0, 1);
    SetBasicSpritePos(press, 0xA0, 0xBC);
    up = 1;
    if (D_800C572F != 0) {
        func_80018C90(press);
        up = 1;
    }
    alpha = 0x32;
    while (1) {
        if (up != 0) {
            alpha += 10;
            if (alpha >= 0x100) {
                alpha = 0xFF;
                up = 0;
            }
        } else {
            alpha -= 10;
            if (alpha < 0x96) {
                alpha = 0x96;
                up = 1;
            }
        }
        func_80018CF8(press, (s16)alpha);
        if ((func_80059CB8() & 0x1000) && D_800C572F == 0) {
            func_80018CF8(press, 0xFF);
            break;
        }
        if (func_8000C144() == 0) {
            D_800F7FE4_PressStartScreen = 0;
            func_80018CF8(press, 0);
            break;
        }
        HuPrcVSleep();
    }
    if (D_800F7FE4_PressStartScreen != 0) {
        PlaySound(0x22);
    }
    D_800F5144 = 1;
    while (1) {
        for (i = 0; i < 10; i++) {
            if (D_800F383C & 4) {
                func_80018C90(press);
            } else {
                ShowBasicSprite(press);
            }
        }
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_PressStartScreen/314950", func_800F7BFC_PressStartScreen);
#endif
















