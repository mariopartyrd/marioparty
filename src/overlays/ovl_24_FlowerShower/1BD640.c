#include "common.h"

void func_800370D4(s16);

typedef struct FlowerShowerBodyWork {
    /* 0x00 */ u8 unk_00[0x23];
    /* 0x23 */ u8 unk_23;
    /* 0x24 */ u8 unk_24;
    /* 0x25 */ u8 unk_25[0xF];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ u8 unk_53;
    /* 0x54 */ u8 unk_54;
    /* 0x55 */ char unk_55;
    /* 0x56 */ s8 unk_56;
    /* 0x57 */ char unk_57;
    /* 0x58 */ s8 unk_58;
    /* 0x59 */ char unk_59[3];
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ s32 unk_60;
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ s32* unk_68;
} FlowerShowerBodyWork;

/* A player object's work (func_8000979C / func_800F761C allocate it, 0xE8): MgWork's layout
 * (src/99E0.c), with every pointer member where MgWork has one so the host offsets agree. */
typedef struct FlowerShowerPlayerWork {
    /* 0x00 */ char unk_00[0x23];
    /* 0x23 */ u8 unk_23;
    /* 0x24 */ char unk_24[0x14];
    /* 0x38 */ f32 unk_38; /* vertical speed, 1000 = on the ground */
    /* 0x3C */ f32 unk_3C; /* facing */
    /* 0x40 */ f32 unk_40; /* speed */
    /* 0x44 */ char unk_44[0xC];
    /* 0x50 */ u16 unk_50; /* flags */
    /* 0x52 */ char unk_52;
    /* 0x53 */ s8 unk_53; /* platform it stands on (FlowerShowerModelWork::unk_05) */
    /* 0x54 */ char unk_54[2];
    /* 0x56 */ s8 unk_56; /* controller port */
    /* 0x57 */ char unk_57;
    /* 0x58 */ s8 unk_58; /* player */
    /* 0x59 */ char unk_59[3];
    /* 0x5C */ s32 unk_5C; /* motion flags */
    /* 0x60 */ char unk_60[0x40];
    /* 0xA0 */ f32 unk_A0;
    /* 0xA4 */ char unk_A4[0xA];
    /* 0xAE */ u16 unk_AE;
    /* 0xB0 */ char unk_B0[8];
    /* 0xB8 */ omObjData* unk_B8; /* MgWork's held item */
    /* 0xBC */ char unk_BC[0x1C];
    /* 0xD8 */ s16 (*unk_D8)[2]; /* one pair per motion */
    /* 0xDC */ void* unk_DC; /* collision callback */
    /* 0xE0 */ char unk_E0[4];
    /* 0xE4 */ void* unk_E4;
} FlowerShowerPlayerWork; /* size = 0xE8 (N64) */

typedef struct FlowerShowerModelWork {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk_06[0x26];
} FlowerShowerModelWork;

typedef struct FlowerShowerNpcWork {
    /* 0x00 */ u8 unk_00[0x3C];
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ u8 unk_40[0x13];
    /* 0x53 */ u8 unk_53;
} FlowerShowerNpcWork;

FlowerShowerBodyWork* func_800F7A28_FlowerShower(omObjData*, s32, f32, f32, s32, s32, s32, s32);
f32 func_800051D4(omObjData*, f32, f32, f32, Vec3f*);
f32 func_80029518(f32);
f32 func_800288D8(s16);
void func_80008FDC(omObjData*, f32);
void func_80008FA0(omObjData*, f32);
void func_80008FE8(omObjData*, f32);
f32 func_800FA5B8_FlowerShower(omObjData*);
f32 func_800FA92C_FlowerShower(omObjData*);
void func_80027E48(s16, f32, f32, u16, u16, char*, u8);
void func_800090D8(omObjData*, u8, u8);
void func_800090C4(omObjData*, u8, u8);
void func_800091BC(omObjData*, s32, s32, s32);
void func_800093FC(omObjData*, f32, f32, f32);
void func_80060F04(s16, s16, s16, s16);
void func_800FACA0_FlowerShower(omObjData*);
void func_800F6FF4_FlowerShower(omObjData*);
void func_800F712C_FlowerShower(omObjData*);
void func_800F726C_FlowerShower(omObjData*);
void func_800F7BD0_FlowerShower(omObjData*);
void func_800F7CE0_FlowerShower(omObjData*);
void func_800F7DF0_FlowerShower(omObjData*);
void func_800F7F00_FlowerShower(omObjData*);
void func_800F8010_FlowerShower(omObjData*);
void func_800F8058_FlowerShower(omObjData*);
void func_800F80A8_FlowerShower(omObjData*);
void func_800F80F4_FlowerShower(omObjData*);
void func_800F8148_FlowerShower(omObjData*);
void func_800F7348_FlowerShower(omObjData*, s32, s32, s32);
void func_800F761C_FlowerShower(omObjData*, s32, s32, s32, f32, f32, f32);
void func_800F8280_FlowerShower(omObjData*);
void func_800F870C_FlowerShower(Matrix4f, Vec3f*, omObjData*);
void func_800F898C_FlowerShower(omObjData*, u16*);
void func_800F6A90_FlowerShower(omObjData*);
void func_800F90AC_FlowerShower(omObjData*);
void func_800F95F4_FlowerShower(omObjData*);
void func_800F9ACC_FlowerShower(omObjData*);
void func_8002956C(Vec3f*);
void func_8001E2A8(s16, u16);
f32 func_8000A72C(f32, f32, f32, f32);
s32 func_8000947C(s32);
void func_80037178(s16, Vec3f*);
f32 func_800F8918_FlowerShower(omObjData*, f32, f32, f32, Vec3f*);
void func_8001E268(s16, u8, u8);
void func_800F6A64_FlowerShower(void);
void func_800F8620_FlowerShower(void);
void func_800F8648_FlowerShower(omObjData*, u8, u32);
int abs(int);
s32 func_80009C90(omObjData*, s16, s16);
s32 func_80000F3C(omObjData*, f32, f32, f32);
void func_8001802C(omObjData*);
void func_800F9224_FlowerShower(omObjData*, s16*, s16*, s32*);
void func_800FA178_FlowerShower(omObjData*);
void func_800FA2B0_FlowerShower(omObjData*, f32);
void func_800FA4EC_FlowerShower(omObjData*);

extern f32 D_800FAE50_FlowerShower;
extern f32 D_800FAE54_FlowerShower;
extern u16 D_800FAE60_FlowerShower[];
extern u16 ContBtn[];
extern s8 ContStkY[];
extern omObjData* D_800EDE70[];
extern u16 D_800EE984;
extern omObjData* D_800F2AF8[];
extern f32 D_800B8964;
extern f32 D_800B8960;
extern f32 D_800B8990;
extern f32 D_800ED6B8;
extern f32 D_800F5254;
extern f32 D_800B8984;
extern u8 D_800F64F8;

/* .data (800FAD30), in address order */
s32 D_800FAD30_FlowerShower = 0;
u32 D_800FAD34_FlowerShower = 0;
u32 D_800FAD38_FlowerShower = 0x744;
u32 D_800FAD3C_FlowerShower = 0;
s32 D_800FAD40_FlowerShower = 0;
s32 D_800FAD44_FlowerShower = 0;
s32 D_800FAD48_FlowerShower = 0;
s32 D_800FAD4C_FlowerShower = 0;
f32 D_800FAD50_FlowerShower[3] = { 30.0f, 120.0f, -60.0f };
s32 D_800FAD5C_FlowerShower = 0;
s32 D_800FAD60_FlowerShower = 0; /* splat's D_800FAD62 half has no users */
s32 D_800FAD64_FlowerShower = 0;
s32 D_800FAD68_FlowerShower = 0;
Vec3f D_800FAD6C_FlowerShower[8] = { 0 }; /* per-flower drift, indexed by *unk_68 */
f32 D_800FADCC_FlowerShower = 0.0f;

void func_800F65E0_FlowerShower(void) {
    u8 cam;

    func_80029090(0x32);
    func_8002ADF0(&D_800EDEC0, 0x40);
    func_8001DE70(0x20);
    omInitObjMan(0x32, 0);
    func_80060088();
    func_800178A0(1);
    cam = func_800178E8();
    func_80017660(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 25.0f, 80.0f, 8000.0f);
    func_80009500();
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    func_800090B8(0);
    D_800F2AF8[D_800ED440++] = omAddObj(1, 1, 0, -1, func_800F6FF4_FlowerShower);
    D_800F2AF8[D_800ED440++] = omAddObj(1, 1, 0, -1, func_800F712C_FlowerShower);
    D_800F2AF8[D_800ED440++] = omAddObj(1, 1, 0, -1, func_800F726C_FlowerShower);
    D_800F3FB0[D_800F2BC0++] = omAddObj(2, 9, 0x32, -1, func_800F7BD0_FlowerShower);
    D_800F3FB0[D_800F2BC0++] = omAddObj(2, 9, 0x32, -1, func_800F7CE0_FlowerShower);
    D_800F3FB0[D_800F2BC0++] = omAddObj(2, 9, 0x32, -1, func_800F7DF0_FlowerShower);
    D_800F3FB0[D_800F2BC0++] = omAddObj(2, 9, 0x32, -1, func_800F7F00_FlowerShower);
    D_800EDE70[D_800EE984++] = omAddObj(3, 5, 0, -1, func_800F8010_FlowerShower);
    D_800EDE70[D_800EE984++] = omAddObj(3, 5, 0, -1, func_800F8058_FlowerShower);
    D_800EDE70[D_800EE984++] = omAddObj(3, 5, 0, -1, func_800F80A8_FlowerShower);
    D_800EDE70[D_800EE984++] = omAddObj(3, 5, 0, -1, func_800F80F4_FlowerShower);
    D_800EDE70[D_800EE984++] = omAddObj(3, 5, 0, -1, func_800F8148_FlowerShower);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    func_8007B168((u8*)"\x82\x72\x82\x73\x82\x60\x82\x71\x82\x73\x82\x6C\x82\x68\x82\x65\x82\x68\x82\x6D\x82\x67\x81\x49", 1);
    PlaySound(0x1BF);
}
void func_800F6A64_FlowerShower(void) {
    if (func_80072718() == 0) {
        omOvlReturnEx(1);
    }
}

void func_800F6A90_FlowerShower(omObjData* arg0) {
    omObjData* obj;
    omObjData* player;
    FlowerShowerBodyWork* flower;
    FlowerShowerPlayerWork* work;
    s32 i;
    u8 light;
    u8 model;

    func_80009468();
    switch (D_800ED430) {
        case 0:
            if (func_80072718() != 0) {
                return;
            }
            if (D_800FAD34_FlowerShower >= 121) {
                func_800F8620_FlowerShower();
                func_80009458();
            }
            func_800F8648_FlowerShower(arg0, (u8)D_800ED430, D_800FAD34_FlowerShower);
            D_800FAD34_FlowerShower += 2;
            break;
        case 1:
            if (D_800FAD38_FlowerShower == 0) {
                func_80009438();
            }
            func_800F8648_FlowerShower(arg0, (u8)D_800ED430, D_800FAD38_FlowerShower);
            D_800FAD38_FlowerShower -= 2;
            break;
        case 2:
            if (D_800FAD3C_FlowerShower == 0) {
                func_800601D4(0x28);
                for (i = 0; i < D_800EE984; i++) {
                    obj = D_800EDE70[i];
                    flower = obj->unk_50;
                    if (flower->unk_54 != 0) {
                        light = flower->unk_24;
                        model = obj->model[3];
                        func_800258EC(model, 4, 0);
                        func_8001E2A8(light, 0);
                        func_8001E268(light, 4, 4);
                        func_80025798(model, obj->trans.x, obj->trans.y, obj->trans.z);
                        func_80025830(model, 5.0f, 5.0f, 5.0f);
                        flower->unk_54 = 0;
                        func_800090D8(obj, 0, 0);
                        func_800090D8(obj, 1, 0);
                    }
                }
            }
            player = D_800F3FB0[D_800FAD60_FlowerShower];
            work = player->unk_50;
            if (work->unk_38 == 1000.0f && D_800FAD30_FlowerShower == 0) {
                work->unk_40 = D_800B8990;
                D_800FAD30_FlowerShower = 1;
            }
            func_800F8648_FlowerShower(arg0, (u8)D_800ED430, D_800FAD3C_FlowerShower);
            if (D_800FAD44_FlowerShower == 0) {
            if (GMesStatAllGet() == 0 || (GMesStatAllGet() & 2)) {
                if (_CheckFlag(0x2B) != 0) {
                    work->unk_3C *= 0.9f;
                    if (D_800FAD48_FlowerShower >= 60) {
                        func_80009448();
                    }
                    D_800FAD48_FlowerShower += 2;
                } else if (D_800FAD64_FlowerShower == 0) {
                    work->unk_3C = 0.0f;
                    if (D_800FAD68_FlowerShower == 0) {
                        func_80060128(0x37);
                        D_800FAD44_FlowerShower = 1;
                        func_800184BC(player, 0xD);
                    } else if (D_800FAD68_FlowerShower < GwPlayer[D_800FAD60_FlowerShower].coins_mg) {
                        func_80060128(0x33);
                        D_800FAD44_FlowerShower = 2;
                        func_800184BC(player, 0xD);
                    } else {
                        func_80060128(0x35);
                        D_800FAD44_FlowerShower = 3;
                    }
                } else if (D_800FAD68_FlowerShower < GwPlayer[D_800FAD60_FlowerShower].coins_mg) {
                    func_80060128(0x35);
                    D_800FAD44_FlowerShower = 4;
                } else {
                    func_80060128(0x34);
                    D_800FAD44_FlowerShower = 5;
                }
            }
            } else {
            switch (D_800FAD44_FlowerShower) {
                case 1:
                    if (D_800FAD48_FlowerShower == 0x60) {
                        goto voice;
                    }
                    if (D_800FAD48_FlowerShower == 0x8C) {
                        func_80009448();
                    }
                    D_800FAD48_FlowerShower += 2;
                    break;
                case 2:
                    if (D_800FAD48_FlowerShower == 0x48) {
                    voice:
                        func_80060618(0x451, (s16)D_800FAD60_FlowerShower);
                    } else if (D_800FAD48_FlowerShower == 0x72) {
                        func_80009448();
                    }
                    D_800FAD48_FlowerShower += 2;
                    break;
                case 3:
                default:
                    if (D_800FAD48_FlowerShower == 0xB4) {
                        func_80009448();
                    }
                    D_800FAD48_FlowerShower += 2;
                    break;
            }
            }
            D_800FAD3C_FlowerShower += 2;
            break;
        case 3:
            if (GMesWait() != 1) {
                func_800726AC(0, 0x14);
                arg0->func_ptr = func_800F6A64_FlowerShower;
            }
            func_800F8648_FlowerShower(arg0, (u8)D_800ED430, D_800FAD3C_FlowerShower);
            D_800FAD40_FlowerShower += 2;
            break;
    }
    if (D_800F5144 == 1) {
        omOvlReturnEx(1);
        func_800601D4(0x28);
    }
}
void func_800F6FF4_FlowerShower(omObjData* arg0) {
    FlowerShowerModelWork* work;

    arg0->model[0] = func_800174C0(0x380001, 0x99);
    arg0->trans.x = arg0->trans.y = arg0->trans.z = 0.0f;
    func_80025798(arg0->model[0], 0.0f, arg0->trans.y, arg0->trans.z);
    work = func_80023684(sizeof(FlowerShowerModelWork), 0x7918);
    arg0->unk_50 = work;
    func_8009B770(work, 0, sizeof(FlowerShowerModelWork));
    arg0->func_ptr = NULL;
    work->unk_04 = 1;
    Center.x = 8.0f;
    Center.y = 310.0f;
    Center.z = 23.0f;
    CRot.x = 322.9f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    CZoom = 1000.0f;
    func_80008FB8(arg0, 2.0f);
    func_80008FC4(arg0, 20.0f);
    work->unk_05 = 0;
    SetFadeInTypeAndTime(0, 0x10);
}

void func_800F712C_FlowerShower(omObjData* arg0) {
    FlowerShowerModelWork* work;

    arg0->model[0] = func_800174C0(0x380002, 0x499);
    arg0->model[1] = func_800174C0(0x380003, 0x499);
    arg0->trans.x = arg0->trans.y = arg0->trans.z = 0.0f;
    func_80025798(arg0->model[0], 0.0f, arg0->trans.y, arg0->trans.z);
    work = func_80023684(sizeof(FlowerShowerModelWork), 0x7918);
    arg0->unk_50 = work;
    func_8009B770(work, 0, sizeof(FlowerShowerModelWork));
    arg0->func_ptr = func_800FA4EC_FlowerShower;
    work->unk_04 = 2;
    func_80008FB8(arg0, 0.5f);
    func_80009000(arg0, 2, 0.0f);
    work->unk_05 = 1;
    omSetStatBit(arg0, 0xA0);
    func_80039C48("47mt003_DEF", D_800FAE60_FlowerShower);
    func_80026040(arg0->model[0]);
    func_80026040(arg0->model[1]);
    func_80025798(arg0->model[1], 0.0f, -5.0f, 0.0f);
}

void func_800F726C_FlowerShower(omObjData* arg0) {
    FlowerShowerModelWork* work;

    arg0->model[0] = func_800174C0(0x380000, 0x99);
    arg0->trans.x = 0.0f;
    arg0->trans.y = 80.0f;
    arg0->trans.z = 0.0f;
    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    work = func_80023684(sizeof(FlowerShowerModelWork), 0x7918);
    arg0->unk_50 = work;
    func_8009B770(work, 0, sizeof(FlowerShowerModelWork));
    arg0->func_ptr = func_800FACA0_FlowerShower;
    work->unk_04 = 1;
    func_80009000(arg0, 4, 0.0f);
    func_80008FB8(arg0, 0.5f);
    func_8000941C(arg0, 1.0f, 1.0f, 1.0f);
    work->unk_05 = 2;
}

void func_800F7348_FlowerShower(omObjData* arg0, s32 arg1, s32 arg2, s32 arg3) {
    FlowerShowerPlayerWork* work;
    s32 motion;
    s32 temp_v0;
    s32 temp_v1;

    temp_v0 = 0x699;
    temp_v1 = 0x289;
    func_8000979C(arg0, arg1, arg2, arg3 & 0xFFFF, temp_v0, temp_v1);
    func_80025930(arg0->model[1], 0x80000000, 0);
    motion = 0x38;
    func_80025AD4(arg0->model[1]);
    func_80025B34(arg0->model[1]);
    func_8009EA40(D_800F2B7C[arg0->model[1]].unk7C, 0.0f, 15.0f, 0.0f);
    func_80009340(arg0, 2, 0x25, 0x289, 0);
    arg0->model[3] = LoadFormFile(0x19, 0x289);
    arg0->model[4] = LoadFormFile(0x1A, 0x289);
    if ((rand8() & 0xFF) >= 0x80U) {
        motion = 0xF;
    }
    func_8001874C(arg0, 0, arg1, 1, 0);
    func_8001874C(arg0, 1, arg1 | 1, 1, 0);
    func_8001874C(arg0, 2, arg1 | 3, 1, 0);
    func_8001874C(arg0, 6, arg1 | 5, 1, 0x13);
    func_8001874C(arg0, 0x10, arg1 | 0x17, 1, 0);
    func_8001874C(arg0, 0x11, arg1 | 0x18, 0, 0);
    func_8001874C(arg0, 0x15, arg1 | 0x62, 0, 0);
    func_8001874C(arg0, 3, arg1 | 0x60, 1, 0);
    func_8001874C(arg0, 4, arg1 | 0x61, 1, 0);
    func_8001874C(arg0, 0x20, arg1 | 0x67, 0, 0);
    func_8001874C(arg0, 0xD, arg1 | motion, 1, 0x78);
    arg0->func_ptr = func_800F8280_FlowerShower;
    func_800093FC(arg0, 80.0f, 640.0f, 5.0f);
    func_800090C4(arg0, 0, 2);
    func_800090C4(arg0, 1, 2);
    func_800090C4(arg0, 2, 2);
    work = arg0->unk_50;
    work->unk_50 |= 0x8000;
    func_800258EC(arg0->model[3], 4, 4);
    func_800258EC(arg0->model[4], 4, 4);
    D_800FAD60_FlowerShower = arg3 & 0xFFFF;
    func_8001E2F8(work->unk_23, 0xFF);
    func_8001E360(work->unk_23, 0xFF, 0xFF, 0xFF);
}

void func_800F761C_FlowerShower(omObjData* arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    FlowerShowerPlayerWork* work;
    f32 scale;
    u16 i;
    s16 motion;
    u16 len;

    scale = 1.0f;
    arg0->unk_50 = func_80023684(sizeof(FlowerShowerPlayerWork), 0x7918);
    func_8009B770(arg0->unk_50, 0, sizeof(FlowerShowerPlayerWork));
    work = arg0->unk_50;
    /* retail sizes the motion pair table by the work size (0xE8 per motion), not 4 */
    work->unk_D8 = func_80023684(arg0->mtncnt * sizeof(FlowerShowerPlayerWork), 0x7918);
    for (i = 0; i < arg0->mtncnt; i++) {
        arg0->motion[i] = -1;
        work->unk_D8[i][0] = 0;
        work->unk_D8[i][1] = 0;
    }
    for (i = 0; i < arg0->mdlcnt; i++) {
        arg0->model[i] = 0;
    }
    arg0->model[0] = LoadFormFile(arg1 | arg2, 0x699);
    arg0->model[1] = func_800174F4(7, 0x699);
    func_800370D4(arg0->model[1]);
    func_800187D0(arg0, 0, arg1 | 0x99, 1, 0);
    func_800187D0(arg0, 1, arg1 | 0x2D, 2, 0);
    work = arg0->unk_50;
    work->unk_56 = GwPlayer[arg3 & 0xFFFF].port;
    arg0->func_ptr = NULL;
    func_800093FC(arg0, arg4, arg5, arg6);
    func_80008FD0(arg0, 60.0f);
    func_80008FDC(arg0, 150.0f);
    func_80008FA0(arg0, 1000.0f);
    func_80008FE8(arg0, 50.0f);
    func_800090C4(arg0, 0, 6);
    func_800090C4(arg0, 1, 1);
    func_800090C4(arg0, 2, 2);
    work->unk_58 = arg3;
    switch ((u32)arg1 >> 16) {
        case 1:
            work->unk_A0 = 1.0f;
            scale = 0.56f;
            break;
        case 2:
            work->unk_A0 = 1.0f;
            scale = 0.54f;
            break;
        case 6:
            work->unk_A0 = 1.0f;
            scale = 0.6f;
            break;
        case 4:
            work->unk_A0 = 0.8f;
            scale = 0.7f;
            break;
        case 3:
            work->unk_A0 = 0.9f;
            scale = 0.45f;
            break;
        case 5:
            work->unk_A0 = 0.7f;
            scale = 0.8f;
            break;
    }
    func_80025830(arg0->model[1], scale, scale, scale);
    motion = arg0->motion[0] & 0x3FFF;
    len = func_800288D8(motion) / 5.0f;
    func_80025C20(arg0->model[0], motion, 0, len, 2);
    work->unk_50 |= 0x8000;
    func_80025798(arg0->model[1], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_800257E4(arg0->model[1], 0.0f, arg0->rot.y, 0.0f);
}
FlowerShowerBodyWork* func_800F7A28_FlowerShower(omObjData* arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    FlowerShowerBodyWork* work;

    arg0->unk_50 = func_80023684(sizeof(FlowerShowerBodyWork), 0x7918);
    func_8009B770(arg0->unk_50, 0, sizeof(FlowerShowerBodyWork));
    arg0->func_ptr = NULL;
    work = arg0->unk_50;
    work->unk_68 = func_80023684(sizeof(s32), 0x7918);
    func_800091BC(arg0, arg1, 0x689, 8);
    arg0->model[1] = func_800174F4(0x20, 0x299);
    func_80009340(arg0, 2, 0x25, 0x289, 8);
    func_80009340(arg0, 3, 0x2A, 0x689, 8);
    func_8001E2F8(work->unk_24, 0xF0);
    func_8001E360(work->unk_24, 0xFF, 0xFF, 0x86);
    arg0->trans.x = arg0->trans.y = arg0->trans.z = 0.0f;
    work->unk_44 = 0.1f;
    work->unk_48 = 20.0f;
    work->unk_34 = 50.0f;
    work->unk_3C = arg3;
    work->unk_5C = arg4;
    work->unk_52 = arg6;
    work->unk_60 = arg5;
    work->unk_50 = arg7;
    func_8000941C(arg0, arg2, arg2, arg2);
    return work;
}

void func_800F7BD0_FlowerShower(omObjData* arg0) {
    f32 angle;
    f32 x;
    s32 dir;
    s32 file;

    file = D_800C59AC[GwPlayer[0].character].unk_04;
    dir = D_800C59AC[GwPlayer[0].character].unk_00;
    if (GwPlayer[0].group == 0) {
        func_800F7348_FlowerShower(arg0, dir, file, 0);
        return;
    }
    angle = D_800FAD50_FlowerShower[D_800FAD4C_FlowerShower];
    x = func_800AEAC0(angle) * 550.0f;
    func_800F761C_FlowerShower(arg0, dir, file, 0, x, 0.0f, func_800AEFD0(angle) * 550.0f);
    D_800FAD4C_FlowerShower++;
}

void func_800F7CE0_FlowerShower(omObjData* arg0) {
    f32 angle;
    f32 x;
    s32 dir;
    s32 file;

    file = D_800C59AC[GwPlayer[1].character].unk_04;
    dir = D_800C59AC[GwPlayer[1].character].unk_00;
    if (GwPlayer[1].group == 0) {
        func_800F7348_FlowerShower(arg0, dir, file, 1);
        return;
    }
    angle = D_800FAD50_FlowerShower[D_800FAD4C_FlowerShower];
    x = func_800AEAC0(angle) * 550.0f;
    func_800F761C_FlowerShower(arg0, dir, file, 1, x, 0.0f, func_800AEFD0(angle) * 550.0f);
    D_800FAD4C_FlowerShower++;
}

void func_800F7DF0_FlowerShower(omObjData* arg0) {
    f32 angle;
    f32 x;
    s32 dir;
    s32 file;

    file = D_800C59AC[GwPlayer[2].character].unk_04;
    dir = D_800C59AC[GwPlayer[2].character].unk_00;
    if (GwPlayer[2].group == 0) {
        func_800F7348_FlowerShower(arg0, dir, file, 2);
        return;
    }
    angle = D_800FAD50_FlowerShower[D_800FAD4C_FlowerShower];
    x = func_800AEAC0(angle) * 550.0f;
    func_800F761C_FlowerShower(arg0, dir, file, 2, x, 0.0f, func_800AEFD0(angle) * 550.0f);
    D_800FAD4C_FlowerShower++;
}

void func_800F7F00_FlowerShower(omObjData* arg0) {
    f32 angle;
    f32 x;
    s32 dir;
    s32 file;

    file = D_800C59AC[GwPlayer[3].character].unk_04;
    dir = D_800C59AC[GwPlayer[3].character].unk_00;
    if (GwPlayer[3].group == 0) {
        func_800F7348_FlowerShower(arg0, dir, file, 3);
        return;
    }
    angle = D_800FAD50_FlowerShower[D_800FAD4C_FlowerShower];
    x = func_800AEAC0(angle) * 550.0f;
    func_800F761C_FlowerShower(arg0, dir, file, 3, x, 0.0f, func_800AEFD0(angle) * 550.0f);
    D_800FAD4C_FlowerShower++;
}

void func_800F8010_FlowerShower(omObjData* arg0) {
    *func_800F7A28_FlowerShower(arg0, 0x21, 2.0f, 0.0f, 0, 0x3C, 3, 1)->unk_68 = 0;
}

void func_800F8058_FlowerShower(omObjData* arg0) {
    *func_800F7A28_FlowerShower(arg0, 0x21, 2.0f, 120.0f, 0x14, 0x3C, 3, 2)->unk_68 = 1;
}

void func_800F80A8_FlowerShower(omObjData* arg0) {
    *func_800F7A28_FlowerShower(arg0, 0x21, 2.0f, 240.0f, 0x28, 0x3C, 3, 3)->unk_68 = 2;
}

void func_800F80F4_FlowerShower(omObjData* arg0) {
    *func_800F7A28_FlowerShower(arg0, 0x21, 2.0f, 90.0f, 0x1E, 0x3C, 3, 4)->unk_68 = 3;
}

void func_800F8148_FlowerShower(omObjData* arg0) {
    *func_800F7A28_FlowerShower(arg0, 0x21, 2.0f, 270.0f, 0x3B, 0x3C, 3, 5)->unk_68 = 4;
}

void func_800F8198_FlowerShower(omObjData* arg0) {
    *func_800F7A28_FlowerShower(arg0, 0x21, 2.0f, 180.0f, 0xA, 0x3C, 3, 6)->unk_68 = 5;
}

void func_800F81E8_FlowerShower(omObjData* arg0) {
    *func_800F7A28_FlowerShower(arg0, 0x22, 3.0f, 90.0f, 0, 0xB4, 4, 7)->unk_68 = 6;
}

void func_800F8234_FlowerShower(omObjData* arg0) {
    *func_800F7A28_FlowerShower(arg0, 0x23, 2.0f, 180.0f, 0, 0xB4, 5, 8)->unk_68 = 7;
}

// register allocation (masked 2): the D_800F2AF8/loop registers differ; for-loops over D_800EE984 / D_800F2BC0 drop pad[4] but not the residue
#ifdef NON_MATCHING
void func_800F8280_FlowerShower(omObjData* arg0) {
    f32 temp_f0;
    f32 temp_f0_2;
    omObjData* temp_a0;
    s32 count;
    s32 var_a1;
    s32 var_a1_2;
    s32 controller;
    s32 saved_stick_x;
    s32 saved_stick_y;
    volatile s32 pad[4]; /* retail reserves 16 otherwise-unused stack bytes */
    u8 temp_v0;
    u16* button_trg;
    u16 saved_button;
    u16 saved_button_trg;
    FlowerShowerBodyWork* temp_s1;

    temp_s1 = arg0->unk_50;
    controller = temp_s1->unk_56;
    temp_v0 = ((volatile u8*)ContStkX)[controller];
    saved_stick_x = (s8)temp_v0;
    temp_v0 = ((volatile u8*)ContStkY)[controller];
    saved_stick_y = (s8)temp_v0;
    saved_button = ContBtn[controller];
    saved_button_trg = ContBtnTrg[controller];
    if (D_800FAD5C_FlowerShower < 90) {
        temp_f0 = Center.y * 0.97f;
        Center.y = temp_f0;
        if (temp_f0 < 110.0f) {
            Center.y = 110.0f;
        }
        temp_f0_2 = CZoom * 1.02f;
        CZoom = temp_f0_2;
        if (temp_f0_2 > 2256.0f) {
            CZoom = 2256.0f;
        }
    } else if (D_800FAD5C_FlowerShower == 90) {
        D_800ED430 = 1;
    } else if (D_800FAD5C_FlowerShower >= 91) {
        ContBtn[controller] = 0;
        ContStkY[controller] = 0;
        ContStkX[controller] = 0;
        button_trg = &ContBtnTrg[controller];
        *button_trg &= 0x1000;
        if (D_800FAD5C_FlowerShower >= 171) {
            if (D_800FAD5C_FlowerShower >= 271) {
                if (D_800FAD5C_FlowerShower >= 311) {
                    ContStkX[controller] = 30;
                    ContStkY[controller] = -18;
                } else if (D_800FAD5C_FlowerShower < 291) {
                    ContStkX[controller] = 46;
                } else {
                    ContStkX[controller] = 36;
                }
            } else {
                ContStkX[controller] = -48;
            }
            if (D_800FAD5C_FlowerShower == 240) {
                func_80060128(0x1D);
            }
        }
        func_80005A28(arg0);
        if (D_800FAD5C_FlowerShower == 320) {
            D_800F2AF8[0]->func_ptr = func_800F6A90_FlowerShower;
            arg0->func_ptr = func_800F90AC_FlowerShower;
            arg0->rot.y = 0.0f;
            temp_s1->unk_3C = 0.0f;
            func_80009E20(arg0);
            count = D_800EE984;
            if (count > 0) {
                var_a1 = 0;
                do {
                    temp_a0 = D_800EDE70[var_a1];
                    var_a1++;
                    temp_a0->func_ptr = func_800FA178_FlowerShower;
                } while (var_a1 < count);
            }
            var_a1_2 = 0;
            count = D_800F2BC0;
            if (count > 0) {
                do {
                    temp_a0 = D_800F3FB0[var_a1_2];
                    temp_s1 = temp_a0->unk_50;
                    if (GwPlayer[temp_s1->unk_58].group != 0) {
                        temp_a0->func_ptr = func_800F95F4_FlowerShower;
                    }
                    var_a1_2++;
                } while (var_a1_2 < (s32)D_800F2BC0);
            }
            func_8000942C();
        }
    }
    D_800FAD5C_FlowerShower += 2;
    if (D_800F5144 == 1) {
        omOvlReturnEx(1);
        func_800601D4(0x28);
    }
    ContStkX[controller] = saved_stick_x;
    ContStkY[controller] = saved_stick_y;
    ContBtn[controller] = saved_button;
    ContBtnTrg[controller] = saved_button_trg;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F8280_FlowerShower);
#endif

void func_800F8620_FlowerShower(void) {
    GMesCreate(8, 0x1E, 0xA0, 0x18);
}

void func_800F8648_FlowerShower(omObjData* arg0, u8 arg1, u32 arg2) {
    switch (arg1) {
        case 0:
            if (arg2 == 0) {
                GMesCreate(0);
            }
            break;
        case 1:
            func_80079078(arg2 / 60);
            break;
        case 2:
            if (arg2 == 0) {
                if (_CheckFlag(0x2B) == 0 && D_800FAD64_FlowerShower != 0) {
                    GMesCreate(0xE);
                } else {
                    GMesCreate(2);
                }
                func_800790C0();
            }
            break;
    }
}

void func_800F870C_FlowerShower(Matrix4f m, Vec3f* pos, omObjData* obj) {
    f32 rx = obj->rot.x;
    f32 ry = obj->rot.y;
    f32 rz = obj->rot.z;
    f32 tx = obj->trans.x;
    f32 ty = obj->trans.y;
    f32 tz = obj->trans.z;
    f32 x = pos->x;
    f32 y = pos->y;
    f32 z = pos->z;

    if (((tx != 0.0f) | (ty != 0.0f)) || tz != 0.0f) {
        func_8009EA40(m, tx, ty, tz);
    } else {
        func_800A2A50(m);
    }
    if (((rx != 0.0f) | (ry != 0.0f)) || rz != 0.0f) {
        MtxRotate(m, rx, ry, rz);
    }
    pos->x = x * m[0][0] + y * m[1][0] + z * m[2][0] + m[3][0];
    pos->y = x * m[0][1] + y * m[1][1] + z * m[2][1] + m[3][1];
    pos->z = x * m[0][2] + y * m[1][2] + z * m[2][2] + m[3][2];
}

f32 func_800F8918_FlowerShower(omObjData* arg0, f32 arg1, f32 arg2, f32 arg3, Vec3f* arg4) {
    Vec4f sp18;
    f32 temp_f0;
    f32 var_f20 = -10000.0f;

    sp18.x = arg1;
    sp18.y = arg2;
    sp18.z = arg3;
    sp18.w = 10.0f;
    temp_f0 = func_800051D4(arg0, arg1, arg2, arg3, arg4);
    if (temp_f0 > -10000.0f) {
        var_f20 = temp_f0;
    }
    return var_f20;
}

// branch tails merged differently, register allocation (masked 28)
#ifdef NON_MATCHING
void func_800F898C_FlowerShower(omObjData* arg0, u16* arg1) {
    Vec3f dir;
    FlowerShowerPlayerWork* work;
    FlowerShowerBodyWork* flower;
    omObjData* obj;
    omObjData* board;
    omObjData* target;
    omObjData* other;
    f32 skill;
    f32 best;
    f32 bestR;
    f32 d;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 a;
    f32 s;
    s32 i;
    s32 moved;
    s8 port;

    moved = 0;
    work = arg0->unk_50;
    bestR = best = 10000.0f;
    port = work->unk_56;
    ContStkX[port] = ContStkY[port] = 0;
    board = D_800F2AF8[2];
    dir.y = 0.0f;
    target = NULL;
    other = NULL; /* never set: retail keeps the dead branch below */
    switch (GwPlayer[work->unk_58].cpu_difficulty) {
        case 0:
            skill = 0.55f;
            break;
        case 1:
            skill = 0.7f;
            break;
        case 2:
            skill = 0.8f;
            break;
        default:
            skill = 1.0f;
            break;
    }
    if (D_800ED430 != 1) {
        return;
    }
    for (i = 0; i < D_800EE984; i++) {
        obj = D_800EDE70[i];
        flower = obj->unk_50;
        if (flower->unk_54 == 0) {
            continue;
        }
        dx = arg0->trans.x - obj->trans.x;
        dy = arg0->trans.y - obj->trans.y;
        dz = arg0->trans.z - obj->trans.z;
        d = func_800B1750(dx * dx + dy * dy + dz * dz);
        if (work->unk_38 != 1000.0f) {
            ContBtn[port] = 0x8000;
            a = work->unk_3C;
            dir.x = func_800AEAC0(a);
            dir.z = func_800AEFD0(a);
            dir.x *= 60.0f;
            dir.z *= 60.0f;
            ContStkX[port] = dir.x;
            ContStkY[port] = -dir.z;
            continue;
        }
        if (fabs(board->rot.x) >= 19.0 || fabs(board->rot.z) >= 19.0) {
            if (func_8000A72C(func_800AEAC0(work->unk_3C), func_800AEFD0(work->unk_3C), arg0->trans.x,
                              arg0->trans.z) < 0.0f &&
                !(work->unk_5C & 0x6000)) {
                ContBtnTrg[port] = 0x8000;
            } else {
                dir.x = -arg0->trans.x;
                dir.z = -arg0->trans.z;
                func_8002956C(&dir);
                dir.x *= 36.0f;
                dir.z *= 36.0f;
                ContStkX[port] = dir.x;
                ContStkY[port] = -dir.z;
            }
            moved = 1;
            break;
        }
        if (d < best && flower->unk_38 == 1000.0f) {
            target = obj;
            best = d;
            bestR = func_800B1750(target->trans.x * target->trans.x + target->trans.z * target->trans.z);
        }
    }
    if (other != NULL) {
        a = func_800B0CD8(arg0->trans.x, arg0->trans.z) - 90.0f;
        a = func_8000A72C(func_800AEAC0(a), func_800AEFD0(a), other->trans.x, other->trans.z);
        a = func_800B0CD8(arg0->trans.x, arg0->trans.z) + a * 15.0f;
        dir.x = func_800AEAC0(a) * 220.0f - arg0->trans.x;
        dir.z = func_800AEFD0(a) * 220.0f - arg0->trans.z;
        func_8002956C(&dir);
        s = skill * 45.0f;
        dir.x = s * dir.x;
        dir.z = s * dir.z;
        ContStkX[port] = dir.x;
        ContStkY[port] = -dir.z;
    } else if ((moved == 0) & (target != NULL)) {
        if (best < skill * 750.0f && bestR < skill * 260.0f) {
            dir.x = target->trans.x - arg0->trans.x;
            dir.z = target->trans.z - arg0->trans.z;
            dir.y = 0.0f;
            func_8002956C(&dir);
            dir.x *= 60.0f;
            dir.z *= 60.0f;
            ContStkX[port] = dir.x;
            ContStkY[port] = -dir.z;
        } else {
            dir.x = -arg0->trans.x;
            dir.z = -arg0->trans.z;
            func_8002956C(&dir);
            dir.x *= 30.0f;
            dir.z *= 30.0f;
            ContStkX[port] = dir.x;
            ContStkY[port] = -dir.z;
        }
    } else {
        a = func_800B0CD8(arg0->trans.x, arg0->trans.z) + 15.0f;
        dir.x = func_800AEAC0(a) * 150.0f - arg0->trans.x;
        dir.z = func_800AEFD0(a) * 150.0f - arg0->trans.z;
        func_8002956C(&dir);
        s = skill * 48.0f;
        dir.x = s * dir.x;
        dir.z = s * dir.z;
        ContStkX[port] = dir.x;
        ContStkY[port] = -dir.z;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F898C_FlowerShower);
#endif
void func_800F90AC_FlowerShower(omObjData* arg0) {
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s3;
    s32 temp_s4;
    u16* temp_a0;
    u16* temp_a1;
    u16* temp_v0;
    u16 temp_s5;
    u16 temp_s6;
    FlowerShowerPlayerWork* temp_s2;

    temp_s2 = arg0->unk_50;
    temp_s0 = temp_s2->unk_56;
    temp_v0 = ContBtnTrg;
    temp_a1 = &temp_v0[temp_s0];
    temp_s5 = *temp_a1;
    temp_a0 = &ContBtn[temp_s0];
    temp_s6 = *temp_a0;
    temp_s4 = ContStkX[temp_s0];
    temp_s3 = ContStkY[temp_s0];
    if (GwPlayer[temp_s2->unk_58].flags & 1) {
        ContStkY[temp_s0] = 0;
        ContStkX[temp_s0] = 0;
        *temp_a0 = 0;
        *temp_a1 = 0;
        func_800F898C_FlowerShower(arg0, temp_a1);
    }
    func_80005A28(arg0);
    ContBtnTrg[temp_s0] = temp_s5;
    ContBtn[temp_s0] = temp_s6;
    ContStkX[temp_s0] = temp_s4;
    ContStkY[temp_s0] = temp_s3;
    temp_s0_2 = temp_s2->unk_53;
    if (temp_s0_2 == 1) {
        func_800258EC(arg0->model[1], 4, 4);
        if (D_800FAD64_FlowerShower == 0) {
            func_80060540(0x2CD, temp_s2->unk_58);
            D_800FAD64_FlowerShower = temp_s0_2;
            func_80060F04(temp_s2->unk_58, 20, 0, 20);
        }
    }
}

void func_800F9224_FlowerShower(omObjData* arg0, s16* stickX, s16* stickY, s32* buttons) {
    Vec3f dir;
    FlowerShowerPlayerWork* work;
    FlowerShowerBodyWork* flower;
    omObjData* obj;
    omObjData* target;
    f32 skill;
    f32 best;
    f32 dist;
    f32 dx;
    f32 dz;
    f32 angle;
    f32 radius;
    s32 i;

    work = arg0->unk_50;
    switch (GwPlayer[work->unk_58].cpu_difficulty) {
        case 0:
            skill = 0.75f;
            break;
        case 1:
            skill = 0.8f;
            break;
        case 2:
            skill = 0.9f;
            break;
        default:
            skill = 1.0f;
            break;
    }
    best = skill * 500.0f;
    target = NULL;
    for (i = 0; i < D_800EE984; i++) {
        obj = D_800EDE70[i];
        flower = obj->unk_50;
        if (flower->unk_52 == 7) {
            continue;
        }
        if (obj->trans.y < -40.0f) {
            continue;
        }
        if (flower->unk_54 == 0) {
            continue;
        }
        if (!(func_800B1750(obj->trans.x * obj->trans.x + obj->trans.z * obj->trans.z) > 420.0f)) {
            continue;
        }
        dx = obj->trans.x - arg0->trans.x;
        dz = obj->trans.z - arg0->trans.z;
        dist = func_800B1750(dx * dx + dz * dz);
        if (dist < best) {
            target = obj;
            best = dist;
        }
    }
    if (target != NULL) {
        dir.x = target->trans.x - arg0->trans.x;
        dir.y = 0.0f;
        dir.z = target->trans.z - arg0->trans.z;
        if (func_800B1750(dir.x * dir.x + dir.z * dir.z) < 500.0) {
            func_8002956C(&dir);
            *stickX = skill * 60.0f * dir.x;
            *stickY = -(skill * 60.0f * dir.z);
            return;
        }
    }
    if (work->unk_40 < skill * 10.0f) {
        angle = func_800B0CD8(arg0->trans.x, arg0->trans.z) - 15.0f;
        dir.x = func_800AEAC0(angle) * (radius = skill * 600.0f) - arg0->trans.x;
        dir.z = func_800AEFD0(angle) * radius - arg0->trans.z;
        dir.y = 0.0f;
        func_8002956C(&dir);
        *stickX = dir.x * 60.0f * (skill * 0.8f);
        *stickY = -dir.z * 60.0f * (skill * 0.8f);
        return;
    }
    *stickX = 0;
    *stickY = 0;
}

// multiply operand order (masked 0, raw 2): v.x * r comes out r * v.x; r * v.x, px *= r and declaring r first do not fix it
#ifdef NON_MATCHING
void func_800F95F4_FlowerShower(omObjData* arg0) {
    s16 sx;
    s16 sy;
    s32 btn;
    FlowerShowerPlayerWork* work;
    f32 py;
    f32 angle;
    f32 px;
    f32 pz;
    f32 d;
    f32 h;
    f32 r;
    s32 stick;
    s16 x;
    s16 y;
    s8 port;

    work = arg0->unk_50;
    angle = work->unk_3C;
    port = work->unk_56;
    px = arg0->trans.x;
    py = arg0->trans.y;
    pz = arg0->trans.z;
    D_800ED6B8 = D_800F5254 = 0.0f;
    sx = sy = 0;
    btn = 0;
    if (work->unk_AE == 0) {
        if (GwPlayer[work->unk_58].flags & 1) {
            if (D_800ED430 == 1) {
                func_800F9224_FlowerShower(arg0, &sx, &sy, &btn);
            }
        } else if (D_800ED430 == 1) {
            sx = ContStkX[port];
            sy = ContStkY[port];
            if (sx >= 61) {
                sx = 60;
            }
            if (sy >= 61) {
                sy = 60;
            }
            if (sx < -60) {
                sx = -60;
            }
            if (sy < -60) {
                sy = -60;
            }
            btn = ContBtnTrg[port];
        }
    }
    stick = func_80009C90(arg0, sx, sy);
    x = stick >> 16;
    y = stick;
    if ((work->unk_40 += func_800B1750(x * x + y * y) / 100.0f) < 0.0f) {
        work->unk_40 = D_800B8960 * 0.6f + work->unk_40;
    } else {
        work->unk_40 = work->unk_40 - D_800B8960 * 0.6f;
    }
    if (work->unk_40 > 10.0f) {
        work->unk_40 = 10.0f;
    }
    if (work->unk_40 < D_800B8990) {
        work->unk_40 = D_800B8990;
    }
    if (abs(x) >= 9 || abs(y) >= 9) {
        angle = func_800B0CD8(x, -y);
    }
    if (work->unk_40 == D_800B8990) {
        func_800184BC(arg0, 0);
    } else if (func_800184BC(arg0, 1) == 1) {
        func_80060540(0x2D0, work->unk_58);
    }
    if (func_80000F3C(arg0, px, py, pz) != 2) {
        Vec3f v;

        d = func_800B1750(px * px + pz * pz);
        v.x = px;
        v.y = py;
        v.z = pz;
        func_8002956C(&v);
        if (d < (r = 400.0f) || (r = 560.0f) < d) {
            px = v.x * r;
            pz = v.z * r;
        }
    }
    work->unk_53 = 1;
    px += func_800AEAC0(angle) * work->unk_40 + D_800ED6B8;
    pz += func_800AEFD0(angle) * work->unk_40 + D_800F5254;
    h = D_800F2B7C[arg0->model[1]].unk_28;
    arg0->trans.x = px;
    arg0->trans.y = h;
    arg0->trans.z = pz;
    func_80025798(arg0->model[1], px, h, pz);
    func_800257E4(arg0->model[1], 0.0f, angle, 0.0f);
    arg0->rot.y = work->unk_3C = func_80029518(angle);
    func_80017DB0(arg0);
    func_8001802C(arg0);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_FlowerShower/1BD640", func_800F95F4_FlowerShower);
#endif
void func_800F9ACC_FlowerShower(omObjData* arg0) {
    Vec3f normal;
    Vec3f dir;
    FlowerShowerBodyWork* work;
    f32 x;
    f32 y;
    f32 z;
    f32 ground;
    f32 vy;
    f32 angle;
    f32 speed;
    f32 g;
    f32 d;
    s32 idx;
    u8 light;
    u8 model;

    work = arg0->unk_50;
    idx = *work->unk_68;
    if (work->unk_54 == 0) {
        return;
    }
    x = arg0->trans.x;
    y = arg0->trans.y;
    z = arg0->trans.z;
    ground = -10000.0f;
    vy = work->unk_38;
    angle = work->unk_3C;
    speed = work->unk_40;
    if (vy < 1000.0f) {
        if (y > 0.0f) {
            if (vy > 1.0f) {
                vy = 1.0f;
            }
            y += vy * vy * ((vy >= 0.0f) ? -35.0f : 35.0f);
            vy += 0.04f;
            x += func_800AEAC0(angle) * speed;
            z += func_800AEFD0(angle) * speed;
            g = func_800F8918_FlowerShower(arg0, x, y, z, &normal);
            if (g != -65536.0f) {
                ground = g;
                if (y < g) {
                    y = ground;
                    if (fabs(vy) < 0.6) {
                        vy = 1000.0f;
                    } else {
                        vy = -vy * 0.2f;
                    }
                    speed -= work->unk_44;
                } else {
                    work->unk_53 = 0xFF;
                }
                if (work->unk_53 == 2) {
                    PlaySound(0x108);
                }
            } else {
                work->unk_53 = 0xFF;
            }
        } else if (y <= 2.0f) {
            light = work->unk_23;
            model = arg0->model[2];
            if (y == 0.0f) {
                work->unk_5C = 0;
                func_800258EC(arg0->model[1], 4, 4);
                work->unk_53 = func_8000947C(2);
                func_800258EC(model, 4, 0);
                func_8001E2A8(light, 0);
                func_8001E268(light, 4, 4);
                func_80025798(model, x, -64.0f, z);
                func_80025830(model, 6.0f, 6.0f, 6.0f);
                y -= 5.0f;
                PlaySound(0x2CF);
                work->unk_53 = 1;
            } else if (work->unk_5C < 720) {
                y = func_800AEAC0(work->unk_5C) * 10.0f - 20.0f;
                work->unk_5C += 8;
                work->unk_53 = 1;
                func_80025798(model, x, -64.0f, z);
            } else {
                y -= 15.0f;
            }
        }
    } else {
        x += func_800AEAC0(angle) * speed + D_800FAD6C_FlowerShower[idx].x * 30.0f;
        z += func_800AEFD0(angle) * speed + D_800FAD6C_FlowerShower[idx].z * 30.0f;
        g = func_800F8918_FlowerShower(arg0, x, y, z, &normal);
        if (g != -65536.0f) {
            if (y < g + 35.0f) {
                y = g;
            } else {
                vy = normal.y * 0.3f;
                work->unk_53 = 0xFF;
                D_800FAD68_FlowerShower++;
            }
        } else {
            vy = normal.y * 0.3f;
        }
        ground = y;
        speed += normal.y * 0.1f;
        D_800FAD6C_FlowerShower[idx].x = normal.x;
        D_800FAD6C_FlowerShower[idx].z = normal.z;
        angle = func_80029518(func_800B0CD8(x, z));
        func_800B1750(x * x + z * z);
    }
    if (y < -400.0f) {
        work->unk_54 = 0;
        func_800090D8(arg0, 0, 0);
        func_800090D8(arg0, 1, 0);
    }
    d = func_800B1750(x * x + z * z);
    dir.x = x;
    dir.y = y;
    dir.z = z;
    func_8002956C(&dir);
    if (d > 600.0f) {
        x = dir.x * 620.0f;
        z = dir.z * 620.0f;
    }
    arg0->trans.x = x;
    arg0->trans.y = y;
    arg0->trans.z = z;
    work->unk_38 = vy;
    work->unk_3C = angle;
    work->unk_40 = speed;
    if ((arg0->model[1] != 0) & (ground != -10000.0f)) {
        func_80025798(arg0->model[1], x, ground + 5.0f, z);
        func_80025830(arg0->model[1], 0.7f, 0.7f, 0.7f);
        func_80037178(arg0->model[1], &normal);
    }
}
void func_800FA178_FlowerShower(omObjData* arg0) {
    FlowerShowerBodyWork* work = arg0->unk_50;
    f32 speed;

    if (work->unk_54 == 0) {
        if (D_800ED430 == 1) {
            if (work->unk_5C > work->unk_60) {
                func_800093FC(arg0, 0.0f, 1000.0f, 0.0f);
                work->unk_3C = func_80029518(work->unk_3C);
                speed = work->unk_50;
                work->unk_40 = speed;
                if (speed > 3.3f) {
                    work->unk_40 = 3.3f;
                }
                work->unk_38 = 0.0f;
                work->unk_54 = 1;
                work->unk_5C = 0;
                func_800090D8(arg0, 0, 1);
                func_800090D8(arg0, 1, 1);
                func_800F9ACC_FlowerShower(arg0);
                work->unk_60--;
                if (work->unk_60 < 10) {
                    work->unk_60 = 10;
                }
            }
            work->unk_5C++;
            work->unk_3C -= work->unk_50;
        }
    } else {
        func_800F9ACC_FlowerShower(arg0);
    }
}

void func_800FA2B0_FlowerShower(omObjData* arg0, f32 arg1) {
    FlowerShowerModelWork* model_work = arg0->unk_50;
    FlowerShowerPlayerWork* body_work;
    FlowerShowerNpcWork* npc_work;
    omObjData* obj;
    f32 dx;
    f32 dz;
    f32 distance;
    f32 angle;
    s16 i;

    arg0->rot.y += arg1;
    i = 0;
    if (D_800F2BC0 != 0) {
        do {
            obj = D_800F3FB0[i];
            body_work = obj->unk_50;
            if (body_work->unk_53 == model_work->unk_05) {
                dx = arg0->trans.x - obj->trans.x;
                dz = arg0->trans.z - obj->trans.z;
                distance = func_800B1750(dx * dx + dz * dz);
                angle = func_800B0CD8(obj->trans.x, obj->trans.z) + arg1;
                if (arg1 != 0.0f) {
                    obj->trans.x = func_800AEAC0(angle) * distance;
                    obj->trans.z = func_800AEFD0(angle) * distance;
                    body_work->unk_3C += arg1;
                }
            }
            i++;
        } while (i < D_800F2BC0);
    }
    i = 0;
    if (D_800EE984 != 0) {
        do {
            obj = D_800EDE70[i];
            npc_work = obj->unk_50;
            if (npc_work->unk_53 == model_work->unk_05) {
                dx = arg0->trans.x - obj->trans.x;
                dz = arg0->trans.z - obj->trans.z;
                distance = func_800B1750(dx * dx + dz * dz);
                angle = func_800B0CD8(obj->trans.x, obj->trans.z) + arg1;
                if (arg1 != 0.0f) {
                    obj->trans.x = func_800AEAC0(angle) * distance;
                    obj->trans.z = func_800AEFD0(angle) * distance;
                    npc_work->unk_3C += arg1;
                }
            }
            i++;
        } while (i < D_800EE984);
    }
}

void func_800FA4EC_FlowerShower(omObjData* arg0) {
    if (((func_8005FD5C() & 0xFFFF) + D_800F64F8) == 0) {
        D_800FADCC_FlowerShower += 0.2f;
    }
    func_80027E48(arg0->model[0], D_800FADCC_FlowerShower, 0.0f, D_800FAE60_FlowerShower[0],
                  D_800FAE60_FlowerShower[1], "No47happy-47m_002", 1);
}

void func_800FA58C_FlowerShower(omObjData* arg0, f32 arg1, f32 arg2) {
    arg0->rot.x += arg1;
    arg0->rot.z += arg2;
}

f32 func_800FA5B8_FlowerShower(omObjData* arg0) {
    Matrix4f matrix;
    Vec3f pos;
    FlowerShowerModelWork* model_work;
    FlowerShowerPlayerWork* body_work;
    omObjData* obj;
    f32 result = 0.0f;
    f32 original_rot;
    f32 dx;
    f32 dz;
    f32 distance;
    f32 angle;
    s16 i;
    u8 team;

    model_work = arg0->unk_50;
    team = model_work->unk_05;
    original_rot = arg0->rot.x;
    i = 0;
    if (D_800F2BC0 != 0) {
        do {
            obj = D_800F3FB0[i];
            body_work = obj->unk_50;
            if (body_work->unk_53 == team) {
                pos.x = arg0->trans.x;
                pos.y = 310.0f;
                pos.z = arg0->trans.z;
                func_800F870C_FlowerShower(matrix, &pos, arg0);
                dx = pos.x - obj->trans.x;
                dz = pos.z - obj->trans.z;
                distance = func_800B1750(dx * dx + dz * dz);
                if (distance != 0.0f) {
                    angle = func_800B0CD8(obj->trans.x, -obj->trans.z);
                    if (distance > 360.0f) {
                        body_work->unk_38 = -D_800B8964 * 0.5f;
                        body_work->unk_3C = func_800B0CD8(obj->trans.x, obj->trans.z);
                        func_800184BC(obj, 6);
                        body_work->unk_40 = D_800B8984;
                        body_work->unk_50 |= 0x10;
                    }
                    if ((angle > 120.0f) | (angle < -120.0f)) {
                        result += distance / 400.0f;
                        break;
                    }
                    if ((angle < 60.0f) & (angle > -60.0f)) {
                        result += -distance / 400.0f;
                        break;
                    }
                }
            }
            i++;
        } while (i < D_800F2BC0);
    }
    if ((fabs((f64)original_rot) > 20.0) & (result != 0.0f)) {
        result = 0.0f;
        goto done;
    }
    if ((original_rot != 0.0f) & (result == 0.0f)) {
        result = -original_rot / 20.0f;
    }
done:
    return result;
}

f32 func_800FA92C_FlowerShower(omObjData* arg0) {
    Matrix4f matrix;
    Vec3f pos;
    FlowerShowerModelWork* model_work;
    FlowerShowerPlayerWork* body_work;
    omObjData* obj;
    f32 result = 0.0f;
    f32 original_rot;
    f32 dx;
    f32 dz;
    f32 distance;
    f32 angle;
    s16 i;
    u8 team;

    model_work = arg0->unk_50;
    team = model_work->unk_05;
    original_rot = arg0->rot.z;
    i = 0;
    if (D_800F2BC0 != 0) {
        do {
            obj = D_800F3FB0[i];
            body_work = obj->unk_50;
            if (body_work->unk_53 == team) {
                pos.x = arg0->trans.x;
                pos.y = 310.0f;
                pos.z = arg0->trans.z;
                func_800F870C_FlowerShower(matrix, &pos, arg0);
                dx = pos.x - obj->trans.x;
                dz = pos.z - obj->trans.z;
                distance = func_800B1750(dx * dx + dz * dz);
                if (distance != 0.0f) {
                    angle = func_800B0CD8(obj->trans.x, -obj->trans.z);
                    if (distance > 360.0f) {
                        body_work->unk_38 = -D_800B8964 * 0.5f;
                        body_work->unk_3C = func_800B0CD8(obj->trans.x, obj->trans.z);
                        func_800184BC(obj, 6);
                        body_work->unk_40 = D_800B8984;
                        body_work->unk_50 |= 0x10;
                    }
                    if ((angle < 150.0f) & (angle > 30.0f)) {
                        result += -distance / 400.0f;
                        break;
                    }
                    if ((angle > -150.0f) & (angle < -30.0f)) {
                        result += distance / 400.0f;
                        break;
                    }
                }
            }
            i++;
        } while (i < D_800F2BC0);
    }
    if ((fabs((f64)original_rot) > 20.0) & (result != 0.0f)) {
        result = 0.0f;
        goto done;
    }
    if ((original_rot != 0.0f) & (result == 0.0f)) {
        result = -original_rot / 20.0f;
    }
done:
    return result;
}

void func_800FACA0_FlowerShower(omObjData* arg0) {
    f32 temp_f0;

    if (D_800ED430 == 1) {
        func_80008FC4(arg0, 30.0f);
        D_800FAE50_FlowerShower = func_800FA5B8_FlowerShower(arg0);
        temp_f0 = func_800FA92C_FlowerShower(arg0);
        D_800FAE54_FlowerShower = temp_f0;
        func_800FA58C_FlowerShower(arg0, D_800FAE50_FlowerShower, temp_f0);
        return;
    }
    func_80008FC4(arg0, 0.0f);
}
