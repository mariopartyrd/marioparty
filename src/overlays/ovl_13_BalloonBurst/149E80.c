#include "common.h"

void func_800F6DB8_BalloonBurst(omObjData *, s32, s32);
void func_800F7298_BalloonBurst(omObjData *);
void func_800F6D14_BalloonBurst(omObjData *);
void func_80027E48(s16, f32, f32, u16, u16, char *, u8);
void func_800F7E38_BalloonBurst(omObjData *, u8);
void func_800F7F94_BalloonBurst(omObjData *);
void func_800F9520_BalloonBurst(omObjData *);
void func_800F95F8_BalloonBurst(omObjData *);
void func_800F94E0_BalloonBurst(s16, s16);
void func_800F6BAC_BalloonBurst(f32, f32, f32, f32, f32, f32, f32);
void func_800F7160_BalloonBurst(void);
void func_800F6C44_BalloonBurst(omObjData *);
void func_800F71D8_BalloonBurst(omObjData *);
void func_800F70E0_BalloonBurst(omObjData *);
void func_800F7100_BalloonBurst(omObjData *);
void func_800F7120_BalloonBurst(omObjData *);
void func_800F7140_BalloonBurst(omObjData *);
void func_800289D0(s16, s16, f32);
void func_800370D4(s16);
void func_80025BB8(s16, s16);

extern Gfx **D_800FB0F8_BalloonBurst[];
extern s16 D_800F3778;
extern u16 D_800FB10C_BalloonBurst;
extern u16 D_800FB10E_BalloonBurst;
extern u16 D_800FC386_BalloonBurst;
extern f32 D_800FC380_BalloonBurst;
extern u16 D_800FC384_BalloonBurst;
extern u16 D_800FC388_BalloonBurst;
extern u16 D_800FC38A_BalloonBurst;
extern u16 D_800FC38C_BalloonBurst;
extern s16 D_800FC38E_BalloonBurst;
extern s16 D_800FC3A0_BalloonBurst;
extern volatile f32 D_800FC3A8_BalloonBurst;
extern volatile f32 D_800FC3AC_BalloonBurst;
extern omObjData *D_800FC3B0_BalloonBurst;
extern omObjData *D_800FC3B4_BalloonBurst;
extern u16 D_800FC3A2_BalloonBurst[];
extern u8 D_800F64F8;
extern unk34D80Struct80 *D_800ED554;
extern u16 D_800FB110_BalloonBurst;
extern omObjData *D_800FC394_BalloonBurst;
extern omObjData *D_800FC398_BalloonBurst;
extern omObjData **D_800FC39C_BalloonBurst;

void func_800396B0(s16, u8);

typedef struct BalloonBurstObstacle {
    Vec pos;
    Vec rot;
    Vec scale;
    Vec unk_24;
    Vec unk_30;
    u16 unk_3C;
    s16 model;
    s16 unk_40;
    s16 secondary_model;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    f32 unk_54;
    f32 unk_58;
    f32 unk_5C;
    f32 unk_60;
    f32 unk_64;
    f32 unk_68;
    s16 unk_6C;
    s16 unk_6E;
    u16 unk_70;
    s16 unk_72;
    f32 unk_74;
    f32 unk_78;
    f32 unk_7C;
    f32 unk_80;
    f32 unk_84;
    f32 unk_88;
    f32 unk_8C;
    f32 unk_90;
    f32 unk_94;
    f32 unk_98;
    f32 unk_9C;
    u16 unk_A0;
    u16 unk_A2;
    u16 unk_A4;
    s16 unk_A6;
} BalloonBurstObstacle; // sizeof 0xA8

typedef struct BalloonBurstPlayer {
    BalloonBurstObstacle obstacles[7];
} BalloonBurstPlayer;

typedef struct BalloonBurstObjectWork {
    u16 player;
    u8 port;
    u8 player_index;
    u8 unk_04;
    char unk_05[3];
    s32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    char unk_14[2];
    u16 unk_16;
    u16 unk_18;
    u16 unk_1A;
    u16 unk_1C;
    u16 unk_1E;
    u16 unk_20;
    u16 unk_22;
    s16 unk_24;
    u16 unk_26;
} BalloonBurstObjectWork; // sizeof 0x28

extern BalloonBurstPlayer D_800FB120_BalloonBurst[];

typedef struct BalloonBurstCharOffset {
    u16 unk_00[4];
    f32 unk_08;
    f32 unk_0C;
} BalloonBurstCharOffset;

extern s16 D_800FB0E2_BalloonBurst[];
extern u16 D_800FB0EA_BalloonBurst[];
extern s16 D_800FC390_BalloonBurst;
extern s16 D_800FC392_BalloonBurst;
void func_800F77D0_BalloonBurst(u8, s16, f32, f32, f32, f32, f32, f32);
void func_800F8670_BalloonBurst(omObjData *);
void func_80039644(s16, u8, u8);
void func_80060440(s16, s16);
void func_800607C4(s16, s32);
void func_800FAA6C_BalloonBurst(omObjData *, u16 *, s16 *);
extern u8 D_800C5982;
extern u16 ContBtn[4];
void func_800F8D6C_BalloonBurst(u8, f32);
void func_8005DB84(s16, s32);
void func_80018F68(u16, u8, u8, u8);
void func_80018E0C(u16, s16);
void func_80060234(s8);
void func_80060F04(s16, s16, s16, s16);

typedef struct BalloonBurstSpark {
    u16 sprite;
    u16 unk_02;
    f32 frame;
    f32 angle;
    f32 speed;
    f32 x;
    f32 y;
    f32 vx;
    f32 vy;
    f32 w;
    f32 h;
    f32 dw;
    f32 dh;
    f32 div;
    s16 alpha;
    u8 done;
    u8 unk_37;
} BalloonBurstSpark; // sizeof 0x38

extern f32 D_800FB0A0_BalloonBurst;
extern f32 D_800FB0A4_BalloonBurst;
extern f32 D_800FB0A8_BalloonBurst;
extern f32 D_800FB0AC_BalloonBurst;
extern f32 D_800FB0B0_BalloonBurst;
extern f32 D_800FB0B4_BalloonBurst;
extern f32 D_800FB0B8_BalloonBurst;
extern f32 D_800FB0BC_BalloonBurst;
extern f32 D_800FB0C0_BalloonBurst;
extern f32 D_800FB0C4_BalloonBurst;
extern f32 D_800FB0C8_BalloonBurst;
extern u16 D_800FB0CC_BalloonBurst;
extern f32 D_800FB0D0_BalloonBurst;
extern f32 D_800FB0D4_BalloonBurst;
extern f32 D_800FB0D8_BalloonBurst;
extern f32 D_800FB0DC_BalloonBurst;
extern u16 D_800FB0E0_BalloonBurst;
void func_800F9368_BalloonBurst(f32, Vec, s16, f32, Vec *);
void func_800FA9C4_BalloonBurst(f32, Vec3f *);
void func_800FA8A4_BalloonBurst(s32);
void func_800F7D9C_BalloonBurst(u16);
void func_80027AC8(s16, char *, char *);

const char D_800FAFA0_BalloonBurst[] = "24mt01d_DEF";

const char D_800FAFAC_BalloonBurst[] = "24mt02d_DEF";

const char D_800FAFB8_BalloonBurst[] = "24mt01c_DEF";

const char D_800FAFC4_BalloonBurst[] = "24mt02c_DEF";

const char D_800FAFD0_BalloonBurst[] = "24mt01b_DEF";

const char D_800FAFDC_BalloonBurst[] = "24mt02b_DEF";

const char D_800FAFE8_BalloonBurst[] = "24mt01a_DEF";

const char D_800FAFF4_BalloonBurst[] = "24mt02a_DEF";

const char D_800FB000_BalloonBurst[4] = "";

// .data
char *D_800FACA0_BalloonBurst[] = {
    (char *)D_800FB000_BalloonBurst, (char *)D_800FB000_BalloonBurst, (char *)D_800FAFF4_BalloonBurst, (char *)D_800FAFE8_BalloonBurst,
    (char *)D_800FAFDC_BalloonBurst, (char *)D_800FAFD0_BalloonBurst, (char *)D_800FAFC4_BalloonBurst, (char *)D_800FAFB8_BalloonBurst,
    (char *)D_800FAFAC_BalloonBurst, (char *)D_800FAFA0_BalloonBurst,
};
s16 D_800FACC8_BalloonBurst[] = { 1, 2, 3, 4, 3, 2, 1, 0 };
u16 D_800FACD8_BalloonBurst[] = { 1, 1, 1, 3, 1, 1, 1, 0xFFFF };
BalloonBurstSpark D_800FACE8_BalloonBurst[] = {
    { 0, 0, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.5f, 1.5f, 1.125f, 0.625f, 3.5714285373687744f, 0xA3, 0, 0 },
    { 0, 0, 1.0f, 90.0f, 7.0f, 16.0f, -16.0f, 4.0f, -2.5f, 1.0f, 1.0f, 1.0625f, 0.6875f, 4.0f, 0xB7, 0, 0 },
    { 0, 0, 1.0f, 180.0f, 7.0f, -16.0f, 16.0f, -4.0f, 2.5f, 1.0f, 1.0f, 1.0625f, 0.6875f, 4.0f, 0x99, 0, 0 },
    { 0, 0, 1.0f, 270.0f, 9.0f, 16.0f, 16.0f, 4.0f, 2.5f, 1.0f, 1.0f, 1.0625f, 0.6875f, 4.0f, 0x99, 0, 0 },
    { 0, 0, 1.0f, 0.0f, 9.0f, -16.0f, -16.0f, -4.0f, -2.5f, 1.0f, 1.0f, 1.0625f, 0.6875f, 4.0f, 0x99, 0, 0 },
    { 0, 0, 1.0f, 45.0f, 9.0f, 16.0f, -16.0f, 4.0f, -2.5f, 1.0f, 1.0f, 1.0625f, 0.6875f, 4.0f, 0x99, 0, 0 },
    { 0, 0, 1.0f, 135.0f, 9.0f, -16.0f, 16.0f, -4.0f, 2.5f, 1.0f, 1.0f, 1.0625f, 0.6875f, 4.0f, 0x99, 0, 0 },
    { 0, 0, 1.0f, 225.0f, 9.0f, 16.0f, 16.0f, 4.0f, 2.5f, 1.0f, 1.0f, 1.0625f, 0.6875f, 4.0f, 0x99, 0, 0 },
    { 0, 0, 1.0f, 315.0f, 9.0f, -16.0f, -16.0f, -4.0f, -2.5f, 1.0f, 1.0f, 1.0625f, 0.6875f, 4.0f, 0x99, 0, 0 },
};
Vec D_800FAEE0_BalloonBurst[] = {
    { -450.0f, 0.0f, 825.0f },
    { -150.0f, 0.0f, 787.5f },
    { 150.0f, 0.0f, 750.0f },
    { 450.0f, 0.0f, 712.5f },
};
s16 D_800FAF10_BalloonBurst[] = { 0x20, 0x30, 0x50, 0x60 };
BalloonBurstCharOffset D_800FAF18_BalloonBurst[] = {
    { { 1, 0, 0, 0x9F }, 35.0f, -250.0f },
    { { 2, 0, 0, 0x9F }, 40.0f, -250.0f },
    { { 6, 0, 0, 0x9F }, 40.0f, -250.0f },
    { { 3, 0, 0, 0x9F }, 50.0f, -250.0f },
    { { 4, 0, 0, 0x9F }, 65.0f, -250.0f },
    { { 5, 0, 0, 0x9F }, 100.0f, -250.0f },
};
u16 D_800FAF78_BalloonBurst[] = { 3, 2, 1, 0, 7, 6, 5, 4, 8, 0 };
u16 D_800FAF8C_BalloonBurst[] = { 0, 0, 0, 0 };
u16 D_800FAF94_BalloonBurst = 0;
u16 D_800FAF96_BalloonBurst = 1;
u16 D_800FAF98_BalloonBurst = 10;

void func_800F65E0_BalloonBurst(void) {
    s32 i;
    s8 c;

    func_8001DE70(0x18);
    omInitObjMan(0x1E, 0);
    func_80060088();
    func_800F6BAC_BalloonBurst(2200.0725f, 343.0f, 0.0f, 0.0f, 0.0f, 0.0f, -235.0f);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    func_80023448(3);
    func_800234B8(0, 0x5E, 0x5E, 0x5E);
    func_800234B8(1, 0xFA, 0xFA, 0xFF);
    func_80023504(1, 100.0f, 100.0f, 100.0f);
    func_800234B8(2, 0, 0, 0);
    func_80023504(2, 100.0f, 100.0f, 100.0f);
    func_800234B8(3, 0, 0, 0);
    func_80023504(3, 100.0f, 100.0f, 100.0f);
    func_8005D98C(0, 1);
    func_8005D98C(1, 4);
    omAddObj(4, 0, 0, -1, func_800F7160_BalloonBurst);
    omSetStatBit(omAddObj(1, 1, 0, -1, func_800F6C44_BalloonBurst), 0xA0);
    omAddObj(0, 0, 0, 0, func_800F71D8_BalloonBurst);
    omAddObj(2, 3, 0x32, 1, func_800F70E0_BalloonBurst);
    omAddObj(2, 3, 0x32, 1, func_800F7100_BalloonBurst);
    omAddObj(2, 3, 0x32, 1, func_800F7120_BalloonBurst);
    omAddObj(2, 3, 0x32, 1, func_800F7140_BalloonBurst);
    c = GwPlayer[0].character;
    func_800F77D0_BalloonBurst(0, 1, D_800FAEE0_BalloonBurst[0].x, D_800FAEE0_BalloonBurst[0].y,
                               D_800FAEE0_BalloonBurst[0].z + D_800FAF18_BalloonBurst[c].unk_08,
                               D_800FAEE0_BalloonBurst[0].x - 50.0f, 0.0f,
                               D_800FAEE0_BalloonBurst[0].z + D_800FAF18_BalloonBurst[c].unk_0C);
    c = GwPlayer[1].character;
    func_800F77D0_BalloonBurst(1, 2, D_800FAEE0_BalloonBurst[1].x, D_800FAEE0_BalloonBurst[1].y,
                               D_800FAEE0_BalloonBurst[1].z + D_800FAF18_BalloonBurst[c].unk_08,
                               D_800FAEE0_BalloonBurst[1].x - 50.0f, 0.0f,
                               D_800FAEE0_BalloonBurst[1].z + D_800FAF18_BalloonBurst[c].unk_0C);
    c = GwPlayer[2].character;
    func_800F77D0_BalloonBurst(2, 4, D_800FAEE0_BalloonBurst[2].x, D_800FAEE0_BalloonBurst[2].y,
                               D_800FAEE0_BalloonBurst[2].z + D_800FAF18_BalloonBurst[c].unk_08,
                               D_800FAEE0_BalloonBurst[2].x - 50.0f, 0.0f,
                               D_800FAEE0_BalloonBurst[2].z + D_800FAF18_BalloonBurst[c].unk_0C);
    c = GwPlayer[3].character;
    func_800F77D0_BalloonBurst(3, 8, D_800FAEE0_BalloonBurst[3].x, D_800FAEE0_BalloonBurst[3].y,
                               D_800FAEE0_BalloonBurst[3].z + D_800FAF18_BalloonBurst[c].unk_08,
                               D_800FAEE0_BalloonBurst[3].x - 50.0f, 0.0f,
                               D_800FAEE0_BalloonBurst[3].z + D_800FAF18_BalloonBurst[c].unk_0C);
    D_800FB0E2_BalloonBurst[0] = LoadFormFile(0x250004, 0x2069D);
    D_800FB0E2_BalloonBurst[1] = LoadFormFile(0x250005, 0x2069D);
    D_800FB0E2_BalloonBurst[2] = LoadFormFile(0x250006, 0x2069D);
    D_800FB0E2_BalloonBurst[3] = LoadFormFile(0x250007, 0x2069D);
    D_800FB0EA_BalloonBurst[0] = D_800FB120_BalloonBurst[0].obstacles[6].model;
    D_800FB0F8_BalloonBurst[0] = D_800F2B7C[(u16)D_800FB120_BalloonBurst[0].obstacles[6].model].unk_6C->unk_00;
    for (i = 1; i < 5; i++) {
        *(D_800FB0EA_BalloonBurst + i) = LoadFormFile(0x250001, 0x2068D);
        func_80027AC8(*(D_800FB0EA_BalloonBurst + i), "kuppa-ha_DEF", *(D_800FACA0_BalloonBurst + i * 2));
        func_80027AC8(*(D_800FB0EA_BalloonBurst + i), "kuppa-kao_DEF", *(D_800FACA0_BalloonBurst + i * 2 + 1));
        func_80025AD4(*(D_800FB0EA_BalloonBurst + i));
        *(D_800FB0F8_BalloonBurst + i) = D_800F2B7C[(s16)*(D_800FB0EA_BalloonBurst + i)].unk_6C->unk_00;
    }
    for (i = 0; i < 4; i++) {
        func_8002456C(D_800FB0E2_BalloonBurst[i]);
    }
    D_800FC39C_BalloonBurst = func_8005DB44(1);
    SetFadeInTypeAndTime(0, 0x10);
    D_800FC390_BalloonBurst = _CheckFlag(0x45);
    D_800FC392_BalloonBurst = _CheckFlag(0x2B);
}
void func_800F6BAC_BalloonBurst(f32 zoom, f32 rotX, f32 rotY, f32 rotZ, f32 centerX, f32 centerY, f32 centerZ) {
    func_800178A0(1);
    CZoom = zoom;
    CRot.x = rotX;
    CRot.y = rotY;
    CRot.z = rotZ;
    Center.x = centerX;
    Center.y = centerY;
    Center.z = centerZ;
}

void func_800F6C44_BalloonBurst(omObjData *arg0) {
    func_80017660(0, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    arg0->model[0] = LoadFormFile(0x250000, 0x299);
    func_80039C48("sora1_DEF", D_800FC3A2_BalloonBurst);
    func_80026040(arg0->model[0]);
    arg0->func_ptr = func_800F6D14_BalloonBurst;
}

void func_800F6D14_BalloonBurst(omObjData *arg0) {
    if ((func_8005FD5C() & 0xFFFF) + D_800F64F8 == 0) {
        D_800FC3A8_BalloonBurst -= 0.1f;
    }
    func_80027E48(arg0->model[0], D_800FC3A8_BalloonBurst, D_800FC3AC_BalloonBurst,
                 D_800FC3A2_BalloonBurst[0], D_800FC3A2_BalloonBurst[1], "24m_000A-grid2", 1);
}

void func_800F6DB8_BalloonBurst(omObjData *arg0, s32 arg1, s32 arg2) {
    s32 base;
    s32 file;
    s8 character;
    BalloonBurstObjectWork *work;

    character = GwPlayer[arg1].character;
    base = D_800C59AC[character].unk_00;
    file = base | D_800C59AC[character].unk_04;
    arg0->model[0] = LoadFormFile(file, 0x20699);
    arg0->model[1] = func_800174F4(6, 0x699);
    arg0->model[2] = LoadFormFile(file, 0x20699);
    func_800289D0(arg0->model[0], arg0->model[2], 600.0f);
    func_800370D4(arg0->model[1]);
    func_8001775C(arg0, 0x2E, base | 0x2E);
    if (rand8() & 1) {
        func_8001775C(arg0, 0xF, base | 0xF);
    } else {
        func_8001775C(arg0, 0xF, base | 0x38);
    }
    func_8001775C(arg0, 0x27, base | 0x27);
    func_8001775C(arg0, 0x2F, base | 0x2F);
    omSetTra(arg0, D_800FAEE0_BalloonBurst[arg1].x, D_800FAEE0_BalloonBurst[arg1].y, D_800FAEE0_BalloonBurst[arg1].z);
    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    work = arg0->unk_50 = func_80023684(sizeof(BalloonBurstObjectWork), 0x7918);
    work->player = arg1;
    work->port = GwPlayer[arg1].port;
    work->unk_1C = work->unk_1E = work->unk_20 = work->unk_22 = work->unk_26 = 0;
    switch (GwPlayer[arg1].cpu_difficulty) {
        case 0:
            work->unk_16 = 1;
            work->unk_18 = 8;
            work->unk_1A = (u8)(rand8() % 6) + 2;
            break;
        case 1:
            work->unk_16 = 3;
            work->unk_18 = 5;
            work->unk_1A = 2;
            break;
        case 2:
            work->unk_16 = 4;
            work->unk_18 = 8;
            work->unk_1A = 1;
            break;
        case 3:
            work->unk_16 = 4;
            work->unk_18 = 7;
            work->unk_1A = 1;
            break;
    }
    work->unk_04 = 0;
    work->unk_24 = -1;
    func_80025BB8(arg0->model[0], arg0->motion[46]);
    work->unk_08 = 0;
    func_800F7E38_BalloonBurst(arg0, arg2);
    func_80025CA8(arg0->model[0], work->unk_0C);
    func_80025CA8(D_800FB120_BalloonBurst[(u16)arg2].obstacles[0].model, D_800FB120_BalloonBurst[(u16)arg2].obstacles[0].unk_44);
    arg0->func_ptr = func_800F7F94_BalloonBurst;
}
void func_800F70E0_BalloonBurst(omObjData *arg0) {
    func_800F6DB8_BalloonBurst(arg0, 0, 0);
}

void func_800F7100_BalloonBurst(omObjData *arg0) {
    func_800F6DB8_BalloonBurst(arg0, 1, 1);
}

void func_800F7120_BalloonBurst(omObjData *arg0) {
    func_800F6DB8_BalloonBurst(arg0, 2, 2);
}

void func_800F7140_BalloonBurst(omObjData *arg0) {
    func_800F6DB8_BalloonBurst(arg0, 3, 3);
}

void func_800F7160_BalloonBurst(void) {
    s32 i;

    for (i = 0; i < D_800F3778; i++) {
        if (D_800F5144 == 1) {
            D_800F5144 = 0;
            func_800601D4(0x28);
            omOvlReturnEx(1);
        }
    }
}

void func_800F71D8_BalloonBurst(omObjData *arg0) {
    f32 zero;

    D_800FB10C_BalloonBurst = 0;
    D_800FB10E_BalloonBurst = 0;
    D_800FC384_BalloonBurst = 0;
    D_800FC380_BalloonBurst = 2200.0725f;
    D_800FC386_BalloonBurst = 0x1E;
    D_800FC388_BalloonBurst = 0x1E;
    zero = 0.0f;
    D_800FC3AC_BalloonBurst = zero;
    D_800FC3A8_BalloonBurst = zero;
    D_800FC38A_BalloonBurst = 0;
    D_800FC38C_BalloonBurst = 0;
    D_800FC38E_BalloonBurst = -1;
    D_800FC3B4_BalloonBurst = 0;
    D_800FC3B0_BalloonBurst = 0;
    D_800FC3A0_BalloonBurst = InitSprite(0x25000A);
    arg0->func_ptr = func_800F7298_BalloonBurst;
}

// register allocation (masked 0, raw 7: a2/a3 swapped for the lo pointer and the D_800FC39C base)
#ifdef NON_MATCHING
void func_800F7298_BalloonBurst(omObjData *arg0) {
    BalloonBurstObstacle *cur;
    BalloonBurstObstacle *hi;
    BalloonBurstObstacle *lo;
    u16 ties;
    s32 i;

    ties = 0;
    func_80079078(D_800FC386_BalloonBurst);
    for (i = 0; i < 4; i++) {
        D_800FB120_BalloonBurst[i].obstacles[6].unk_A4 = D_800FB120_BalloonBurst[i].obstacles[6].unk_A6 = 0;
    }
    switch (D_800FB10C_BalloonBurst) {
        case 0:
            if (D_800FC3B0_BalloonBurst == NULL) {
                D_800FC3B0_BalloonBurst = omAddObj(1, 0, 0, -1, func_800F9520_BalloonBurst);
            }
            break;
        case 1:
            D_800FC388_BalloonBurst--;
            if (D_800FC388_BalloonBurst == 0) {
                D_800FC386_BalloonBurst--;
                D_800FC388_BalloonBurst = 30;
            }
            D_800FC398_BalloonBurst = D_800FC394_BalloonBurst = D_800FC39C_BalloonBurst[0];
            lo = hi = &D_800FB120_BalloonBurst[0].obstacles[6];
            for (i = 1; i < 4; i++) {
                cur = &D_800FB120_BalloonBurst[i].obstacles[6];
                if (cur->unk_54 == D_800FB120_BalloonBurst[i - 1].obstacles[6].unk_54) {
                    ties++;
                }
                if (cur->unk_54 < lo->unk_54) {
                    D_800FC394_BalloonBurst = D_800FC39C_BalloonBurst[i];
                    lo = cur;
                } else if (cur->unk_54 > hi->unk_54) {
                    hi = cur;
                    D_800FC398_BalloonBurst = D_800FC39C_BalloonBurst[i];
                }
            }
            if (ties == 3) {
                D_800FC394_BalloonBurst = NULL;
                D_800FC398_BalloonBurst = NULL;
            }
            if (arg0->unk_10 & 0xF) {
                D_800FB10C_BalloonBurst = 2;
                D_800FB110_BalloonBurst = 0;
                for (i = 0; i < 4; i++) {
                    if ((1 << i) & arg0->unk_10) {
                        D_800FAF8C_BalloonBurst[D_800FAF94_BalloonBurst++] = i;
                    }
                }
                if (D_800FAF94_BalloonBurst == 1) {
                    D_800FC38E_BalloonBurst = D_800FAF8C_BalloonBurst[0];
                } else {
                    D_800FC38E_BalloonBurst = D_800FAF8C_BalloonBurst[rand8() % D_800FAF94_BalloonBurst];
                }
                GwPlayer[D_800FC38E_BalloonBurst].coins_mg += 10;
                func_800F94E0_BalloonBurst(D_800FB120_BalloonBurst[D_800FC38E_BalloonBurst].obstacles[6].model, D_800FACC8_BalloonBurst[3]);
                for (i = 0; i < 4; i++) {
                    if (D_800FB120_BalloonBurst[i].obstacles[0].unk_50 >= 5.0f) {
                        func_800396B0(D_800FB120_BalloonBurst[i].obstacles[0].unk_72, (u8)D_800FAF78_BalloonBurst[3]);
                    }
                }
            } else if (D_800FC386_BalloonBurst == 0) {
                D_800FB10C_BalloonBurst = 2;
                D_800FB110_BalloonBurst = 11;
                D_800FC38C_BalloonBurst = 1;
                D_800FC38E_BalloonBurst = -1;
                func_800601D4(0x28);
                func_800790C0();
                for (i = 0; i < 4; i++) {
                    if (D_800FB120_BalloonBurst[i].obstacles[0].unk_50 >= 5.0f) {
                        func_800396B0(D_800FB120_BalloonBurst[i].obstacles[0].unk_72, (u8)D_800FAF78_BalloonBurst[3]);
                    }
                }
            }
            break;
        case 2:
            if (D_800FC3B4_BalloonBurst == NULL) {
                D_800FC3B4_BalloonBurst = omAddObj(1, 0, 0, -1, func_800F95F8_BalloonBurst);
                omSetStatBit(D_800FC3B4_BalloonBurst, 0xA0);
            }
            break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_13_BalloonBurst/149E80", func_800F7298_BalloonBurst);
#endif
void func_800F77D0_BalloonBurst(u8 arg0, s16 arg1, f32 x, f32 y, f32 z, f32 x2, f32 y2, f32 z2) {
    BalloonBurstObstacle *p;
    omObjData *obj;
    unk_ovl_2D_struct *mdl;
    void *data;
    s16 model;
    s16 handle;
    f32 frame;
    s32 i;

    for (i = 0; i < 7; i++) {
        p = &D_800FB120_BalloonBurst[arg0].obstacles[i];
        p->pos.x = p->pos.y = p->pos.z = p->rot.x = p->rot.y = p->rot.z = 0.0f;
        p->scale.x = p->scale.y = p->scale.z = 1.0f;
        p->unk_44 = 0.0f;
        p->unk_48 = 0.0f;
        p->unk_4C = p->unk_50 = 0.0f;
        p->unk_54 = 0.0f;
        p->unk_58 = 0.0f;
        p->unk_5C = 0.5f;
        p->unk_60 = 0.0f;
        p->unk_64 = 0.5f;
        p->unk_6C = -1;
        p->unk_6E = -1;
        p->unk_70 = 0;
        p->unk_72 = -1;
        p->unk_68 = 0.0f;
        p->unk_74 = p->unk_78 = p->unk_7C = p->unk_80 = 0.0f;
        p->unk_84 = 0.0f;
        p->unk_80 = 0.0f;
    }
    p = D_800FB120_BalloonBurst[arg0].obstacles;
    obj = omAddObj(3, 1, 0, -1, func_800F8670_BalloonBurst);
    obj->work[0] = arg0;
    obj->model[0] = p[0].model = model = LoadFormFile(0x250002, 0x689);
    p[0].pos.x = x;
    p[0].pos.y = y;
    p[0].pos.z = z;
    D_800F2B7C[(u16)model].unk_0A |= 3;
    frame = D_800ED554[D_800F2B7C[(u16)model].unk_08].unk_02 - 1.0f;
    p[0].unk_44 = p[0].unk_48 = frame;
    func_80025798(model, x, y, z);
    omSetTra(obj, x, y, z);
    data = DataRead(0x250009);
    handle = func_80038A9C(D_800F2B7C[(u16)model].unk_6C, data, 0, "pump0_DEF");
    p[0].unk_72 = handle;
    func_80025AD4(model);
    func_80025B34(model);
    func_80039644(handle, 1, 1);
    func_800396B0(handle, 4);
    HuMemDirectFree(data);
    for (i = 1; i < 6; i++) {
        if (arg0 == 0 && i == 1) {
            p[i].model = LoadFormFile(0x250003, 0x699);
        } else {
            p[i].model = func_80023FC8(D_800FB120_BalloonBurst[0].obstacles[1].model);
        }
    }
    p[1].pos.x = x - 50.0f;
    p[1].pos.y = y;
    p[1].pos.z = z;
    func_80025798(D_800FB120_BalloonBurst[arg0].obstacles[1].model, x - 50.0f, y, z);
    p[6].unk_54 = 0.0f;
    model = LoadFormFile(0x250001, 0x20689);
    p[6].model = model;
    p[6].unk_24.x = p[6].pos.x = x2;
    p[6].unk_24.y = p[6].pos.y = y2;
    p[6].unk_24.z = p[6].pos.z = z2;
    D_800F2B7C[(u16)model].unk_0A |= 3;
    func_80025798(model, x2, y2, z2);
    mdl = &D_800F2B7C[(u16)model];
    p[6].unk_74 = (mdl->unk_6C->unk_80->unk_4A + mdl->unk_6C->unk_80->unk_50) / 2.0f;
    p[6].unk_78 = (mdl->unk_6C->unk_80->unk_4C + mdl->unk_6C->unk_80->unk_52) / 2.0f;
    p[6].unk_7C = (mdl->unk_6C->unk_80->unk_4E + mdl->unk_6C->unk_80->unk_54) / 2.0f;
    p[6].unk_74 = 10.0f;
    p[6].unk_78 = 10.0f;
    p[6].unk_7C = 10.0f;
    p[6].unk_80 = 190.0f;
    if (arg0 == 0) {
        model = LoadFormFile(0x250001, 0x2068D);
        p[6].unk_40 = model;
        func_80025930(model, 0x22000, 0x20000);
        func_80025AD4(model);
        func_80026040(model);
        func_80025B34(model);
    } else {
        model = func_80023FC8(D_800FB120_BalloonBurst[0].obstacles[6].unk_40);
        p[6].unk_40 = model;
    }
    D_800F2B7C[(u16)model].unk_0A |= 3;
    p[6].secondary_model = func_800174F4(6, 0x699);
    func_800370D4(p[6].secondary_model);
    p[6].unk_3C = arg1;
}
void func_800F7D9C_BalloonBurst(u16 arg0) {
    BalloonBurstPlayer *player = &D_800FB120_BalloonBurst[arg0];
    s32 i;

    for (i = 0; i < 7; i++) {
        func_800258EC(((BalloonBurstObstacle *)(i * sizeof(BalloonBurstObstacle) + (u8 *)player))->model, 4, 4);
    }
    func_800258EC(player->obstacles[6].secondary_model, 4, 4);
}

void func_800F7E38_BalloonBurst(omObjData *arg0, u8 player_index) {
    BalloonBurstObjectWork *work = arg0->unk_50;
    unk_ovl_2D_struct *model;
    BalloonBurstPlayer *player;
    f32 frame;

    work->player_index = player_index;
    model = &D_800F2B7C[arg0->model[0]];
    model->unk_0A |= 3;
    frame = D_800ED554[model->unk_08].unk_02 - 1.0f;
    work->unk_10 = frame;
    work->unk_0C = frame;
    func_80025798(arg0->model[1], arg0->trans.x, 0.0f, arg0->trans.z);
    func_80025830(arg0->model[1], 0.5f, 0.5f, 0.5f);
    player = &D_800FB120_BalloonBurst[(u8)player_index];
    player->obstacles[0].unk_50 = 5.0f;
    work->unk_0C = 0.0f;
    player->obstacles[0].unk_44 = 0.0f;
    func_800396B0(player->obstacles[0].unk_72,
                  (u8)D_800FAF78_BalloonBurst[(s32)(player->obstacles[0].unk_50 / 1.6666666f)]);
}

void func_800F7F94_BalloonBurst(omObjData *arg0) {
    u16 btn;
    s16 trg;
    BalloonBurstObjectWork *work;
    BalloonBurstObstacle *p;
    u8 port;
    u16 idx;
    u16 flags;

    if (D_800C5982 == 1) {
        return;
    }
    work = arg0->unk_50;
    port = work->port;
    idx = work->player_index;
    p = D_800FB120_BalloonBurst[idx].obstacles;
    if (!(GwPlayer[work->player].flags & 1)) {
        btn = ContBtn[(s8)port];
        trg = ContBtnTrg[(s8)port];
    } else {
        func_800FAA6C_BalloonBurst(arg0, &btn, &trg);
    }
    if (D_800FB10C_BalloonBurst == 1) {
        if (btn & 0x6000) {
            work->unk_26 = 1;
            flags = p[0].unk_70;
            if (!(flags & 1)) {
                if (!(flags & 2)) {
                    p[0].unk_70 = flags | 2;
                    if (p[0].unk_50 < 5.0f) {
                        work->unk_24 = func_80060540(0x26B, idx);
                        func_80060440(work->unk_24, (rand8() * 4 + rand8()) % 1001 - 600);
                        func_800607C4(work->unk_24, D_800FAF10_BalloonBurst[work->player]);
                    }
                }
                if (p[0].unk_50 < 5.0f) {
                    p[0].unk_50 += 1.0f;
                    work->unk_0C -= work->unk_10 / 5.0f;
                    p[0].unk_44 -= p[0].unk_48 / 5.0f;
                    func_800396B0(p[0].unk_72, (u8)D_800FAF78_BalloonBurst[(s32)(p[0].unk_50 / 1.6666666f)]);
                    if (work->unk_0C < 0.0f) {
                        work->unk_0C = 0.0f;
                    }
                    if (p[0].unk_44 < 0.0f) {
                        p[0].unk_44 = 0.0f;
                    }
                }
            }
        }
        if (p[0].unk_50 >= 5.0f && work->unk_26 == 1) {
            if (work->unk_04 ^= 1) {
                func_800396B0(p[0].unk_72, (u8)D_800FAF78_BalloonBurst[3]);
            } else {
                func_800396B0(p[0].unk_72, (u8)D_800FAF78_BalloonBurst[8]);
            }
        }
        if (btn & 0x8000) {
            work->unk_26 = 1;
            flags = p[0].unk_70;
            if (flags & 2) {
                goto clear;
            }
            if (!(flags & 1)) {
                if (p[0].unk_50 != 0.0f) {
                    work->unk_24 = func_80060540(0x26C, idx);
                    func_80060440(work->unk_24, (rand8() * 4 + rand8()) % 1001 - 600);
                    func_800607C4(work->unk_24, D_800FAF10_BalloonBurst[work->player]);
                }
                work->unk_04 = 0;
            }
            p[0].unk_70 |= 1;
            if (p[0].unk_50 > 0.0f) {
                p[0].unk_4C += 1.0f;
                if (p[0].unk_4C > 5.0f) {
                    p[0].unk_4C = 5.0f;
                }
                p[1].unk_54 = (func_800B1750(p[0].unk_4C * p[0].unk_4C + 25.0f) * 0.2f - 1.0f) * 6.5f;
                p[0].unk_50 -= 1.0f;
                if (p[0].unk_50 < 0.0f) {
                    p[0].unk_50 = 0.0f;
                }
                work->unk_0C = work->unk_10 / 5.0f + work->unk_0C;
                p[0].unk_44 = p[0].unk_48 / 5.0f + p[0].unk_44;
                func_800396B0(p[0].unk_72, (u8)D_800FAF78_BalloonBurst[(7 - (s32)(p[0].unk_50 * 1.25f / 1.6666666f))]);
                if (work->unk_0C > work->unk_10) {
                    work->unk_0C = work->unk_10;
                }
                if (p[0].unk_44 > p[0].unk_48) {
                    p[0].unk_44 = p[0].unk_48;
                }
                if (p[0].unk_50 == 0.0f) {
                    p[1].unk_70 |= 0xC;
                    p[1].unk_68 = p[1].unk_54 / 3.0f;
                    work->unk_0C = work->unk_10;
                    p[0].unk_44 = p[0].unk_48;
                    p[0].unk_4C = 0.0f;
                }
            }
        }
        if (p[0].unk_70 & 2) {
        clear:
            if (!(btn & 0x6000)) {
                p[0].unk_70 &= ~2;
            }
        }
        flags = p[0].unk_70;
        if ((flags & 1) && !(btn & 0x8000)) {
            p[0].unk_70 = flags & ~1;
            p[1].unk_70 |= 0xC;
            p[1].unk_68 = p[1].unk_54 / 3.0f;
            p[0].unk_4C = 0.0f;
        }
    } else if (D_800FB10C_BalloonBurst == 2) {
        if (p[1].unk_54 != 0.0f) {
            p[1].unk_70 |= 0xC;
            p[1].unk_68 = p[1].unk_54 / 3.0f;
        }
    }
    if (D_800FB10C_BalloonBurst == 1) {
        func_80025CA8(arg0->model[0], work->unk_0C);
        func_80025CA8(p[0].model, p[0].unk_44);
    }
}
void func_800F8670_BalloonBurst(omObjData *arg0) {
    BalloonBurstObstacle *p;
    u8 idx;
    s16 model;
    f32 d;
    f32 add;
    f32 y;
    f32 z;
    f32 ang;
    f32 rx;
    f32 rz;
    f32 t;
    s32 i;

    if (D_800C5982 == 1) {
        return;
    }
    idx = arg0->work[0];
    p = D_800FB120_BalloonBurst[idx].obstacles;
    for (i = 1; i < 6; i++) {
        func_80025830(p[i].model, p[i].unk_54 / 5.0f + 1.0f, p[i].unk_54 / 5.0f + 1.0f, p[i].unk_54 / 5.0f + 1.0f);
    }
    for (i = 1; i < 6; i++) {
        if (!(p[i].unk_70 & 4)) {
            continue;
        }
        if (!(p[i].unk_54 > 0.0f)) {
            continue;
        }
        d = p[i].unk_68;
        if (p[i].unk_54 - d < 0.0f) {
            d = p[i].unk_54;
        }
        if (arg0 == D_800FC394_BalloonBurst) {
            add = d + 9.0f;
        } else if (arg0 == D_800FC398_BalloonBurst) {
            add = d * 0.6f;
        } else {
            add = d;
        }
        if (p[i].unk_70 & 8) {
            if (i == 5) {
                p[6].unk_98 = p[5].unk_68 * 3.0f * 0.6f;
                p[6].unk_94 = 0.0f;
                p[6].unk_A0 = 5;
                p[6].unk_9C = p[6].unk_98 / 1.25f;
                p[6].unk_70 |= 0x10;
                if (p[6].unk_6E == -1) {
                    p[6].unk_6C = -1;
                    p[6].unk_6E = 1;
                }
            }
            p[i].unk_70 &= ~8;
        }
        p[i + 1].unk_54 = add + p[i + 1].unk_54;
        p[i].unk_54 -= d;
        if (p[i].unk_54 == 0.0f) {
            p[i + 1].unk_70 |= 0xC;
            p[i].unk_70 &= ~4;
            p[i + 1].unk_68 = p[i + 1].unk_54 / 3.0f;
            p[i].unk_68 = 0.0f;
        }
    }
    if (D_800FB10C_BalloonBurst == 2 && (D_800FC38C_BalloonBurst != 1 || D_800C5982 != 0)) {
        return;
    }
    if (p[6].unk_70 & 0x10) {
        p[6].unk_70 = (p[6].unk_70 | 0x20) & ~0x10;
    }
    model = D_800FB120_BalloonBurst[idx].obstacles[6].model;
    D_800F2B7C[model].unk_48 = p[6].unk_54;
    if ((D_800FC384_BalloonBurst == 0 && p[6].unk_54 >= 33.0f) || (D_800FC384_BalloonBurst == 1 && p[6].unk_54 >= 66.0f)) {
        D_800FC380_BalloonBurst += 217.5f;
        D_800FC384_BalloonBurst++;
    }
    if (CZoom < D_800FC380_BalloonBurst) {
        CZoom += 5.0f;
    }
    if (p[6].unk_54 >= 80.0f && p[6].unk_6E >= 0) {
        if (--p[6].unk_6E == 0) {
            p[6].unk_6C++;
            func_800F94E0_BalloonBurst(p[6].model, D_800FACC8_BalloonBurst[p[6].unk_6C]);
            p[6].unk_6E = D_800FACD8_BalloonBurst[p[6].unk_6C];
        }
    }
    func_80025CA8(model, p[6].unk_54);
    p[6].unk_24 = p[6].pos;
    y = func_800AEAC0(p[6].unk_54) * 300.0f;
    z = -func_800AEFD0(p[6].unk_54) * 400.0f + 850.0f;
    if (p[6].unk_54 >= 5.0f) {
        if (p[6].unk_70 & 0x20) {
            ang = p[6].unk_58;
            ang += p[6].unk_A0 * p[6].unk_5C;
            if (ang >= 360.0f) {
                ang -= 360.0f;
            }
            rz = func_800AEAC0(ang) * 10.0f;
            rx = func_800AEFD0(ang) * 10.0f;
            t = p[6].unk_94;
            t += p[6].unk_9C;
            if (fabs(t) >= p[6].unk_98) {
                p[6].unk_9C = -p[6].unk_9C;
            }
            if (--p[6].unk_A0 == 0) {
                p[6].unk_70 &= ~0x20;
            }
            p[6].unk_94 = t;
            rz += t;
        } else {
            ang = p[6].unk_58;
            ang += p[6].unk_5C;
            if (ang >= 360.0f) {
                ang -= 360.0f;
            }
            rz = func_800AEAC0(ang) * 10.0f;
            rx = func_800AEFD0(ang) * 10.0f;
        }
        p[6].unk_58 = ang;
        func_800257E4(p[6].model, rx, 0.0f, rz);
    }
    if (p[6].unk_54 >= 100.0f) {
        func_8005DB84(0, p[6].unk_3C);
        p[6].unk_70 &= ~4;
    }
    p[6].pos.y = y;
    p[6].pos.z = z;
    func_800F8D6C_BalloonBurst(idx, y / 90.0f);
}
// loop-tail branch layout (masked 7: retail beql exit / j top, this gives bne top / j exit)
#ifdef NON_MATCHING
void func_800F8D6C_BalloonBurst(u8 arg0, f32 arg1) {
    Vec pts[6];
    Vec target;
    Vec ofs;
    Vec ofs0;
    BalloonBurstObstacle *p;
    f32 angle;
    s16 hit;
    s32 i;
    f32 zero;

    zero = 0.0f;
    p = D_800FB120_BalloonBurst[arg0].obstacles;
    p[6].unk_A2 = 0;
    ofs.x = ofs.y = ofs.z = zero;
    if (D_800FB10C_BalloonBurst != 2 || D_800FC38C_BalloonBurst == 1) {
        if (p[6].unk_54 >= 5.0f) {
            angle = p[6].unk_60;
            angle += p[6].unk_64;
            if (angle >= 360.0f) {
                angle -= 360.0f;
            }
            if (angle < 0.0f) {
                angle += 360.0f;
            }
            p[6].unk_60 = angle;
            func_800FA9C4_BalloonBurst(angle, (Vec3f *)&ofs);
        }
        ofs0 = ofs;
        pts[0] = p[1].pos;
        while (1) {
            if (p[6].unk_A6 == -1) {
                break;
            }
            target.x = p[6].pos.x + ofs.x;
            target.y = p[6].pos.y - ofs.y;
            target.z = p[6].pos.z + ofs.z;
            if ((p[6].unk_A4 & 0xC) == 0xC) {
                p[6].unk_A4 |= 1;
            }
            func_800F9368_BalloonBurst(55.0f, target, 6, arg1, pts);
            if (p[6].unk_54 >= 5.0f) {
                hit = -1;
                if ((p[6].unk_A4 & 0xD) == 0xD) {
                    p[6].pos = p[6].unk_24;
                    target.x = p[6].pos.x + ofs0.x;
                    target.y = p[6].pos.y - ofs0.y;
                    target.z = p[6].pos.z + ofs0.z;
                    func_800F9368_BalloonBurst(55.0f, target, 6, arg1, pts);
                }
                if (hit == -1) {
                    break;
                }
                p[6].unk_A6 = hit;
                if (hit < arg0) {
                    p[6].unk_A4 |= 4;
                    D_800FB120_BalloonBurst[hit].obstacles[6].unk_A4 |= 8;
                } else {
                    p[6].unk_A4 |= 8;
                    D_800FB120_BalloonBurst[hit].obstacles[6].unk_A4 |= 4;
                }
                p[6].unk_A2++;
                if (p[6].unk_A4 & 8) {
                    p[6].unk_64 = fabsf(p[6].unk_64);
                }
                if (p[6].unk_A4 & 4) {
                    p[6].unk_64 = -fabs(p[6].unk_64);
                }
                if (D_800FB120_BalloonBurst[hit].obstacles[6].unk_A4 & 8) {
                    D_800FB120_BalloonBurst[hit].obstacles[6].unk_64 = fabsf(D_800FB120_BalloonBurst[hit].obstacles[6].unk_64);
                }
                if (D_800FB120_BalloonBurst[hit].obstacles[6].unk_A4 & 4) {
                    D_800FB120_BalloonBurst[hit].obstacles[6].unk_64 = -fabs(D_800FB120_BalloonBurst[hit].obstacles[6].unk_64);
                }
                angle += p[6].unk_64;
                if (angle >= 360.0f) {
                    angle -= 360.0f;
                }
                if (angle < 0.0f) {
                    angle += 360.0f;
                }
                func_800FA9C4_BalloonBurst(angle, (Vec3f *)&ofs);
            } else {
                hit = -1;
            }
            if (hit == -1) {
                break;
            }
        }
    } else {
        pts[0] = p[1].pos;
        target.x = p[6].pos.x;
        target.y = p[6].pos.y;
        target.z = p[6].pos.z;
        func_800F9368_BalloonBurst(55.0f, target, 6, arg1, pts);
    }
    for (i = 2; i < 6; i++) {
        func_80025798(p[i].model, pts[i - 1].x, pts[i - 1].y, pts[i - 1].z);
        p[i].pos.x = pts[i].x;
        p[i].pos.y = pts[i].y;
        p[i].pos.z = pts[i].z;
    }
    p[6].unk_30.x = pts[5].x;
    p[6].unk_30.y = pts[5].y;
    p[6].unk_30.z = pts[5].z + 50.0f;
    func_80025798(p[6].model, pts[5].x, pts[5].y, pts[5].z + 50.0f);
    func_80025798(p[6].secondary_model, pts[5].x, 1.0f, pts[5].z + 50.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_13_BalloonBurst/149E80", func_800F8D6C_BalloonBurst);
#endif
void func_800F9368_BalloonBurst(f32 radius, Vec start, s16 count, f32 scale, Vec *out) {
    f32 dy;
    f32 dx;
    f32 stepY;
    f32 dx2;
    f32 r2;
    f32 t;
    f32 len;
    s16 i;

    dy = (start.y - out->y) / count;
    dx = (out->x - start.x) / count;
    for (i = 1; i < count; i++) {
        t = (dy * scale) * i;
        len = func_800B1750(dx * dx + t * t + radius * radius);
        out[i].x = (dx / len) * radius + out[i - 1].x;
        out[i].y = (t / len) * radius + out[i - 1].y;
        out[i].z = out[i - 1].z - (radius / len) * radius;
    }
}
void func_800F94E0_BalloonBurst(s16 arg0, s16 arg1) {
    D_800F2B7C[arg0].unk_6C->unk_00 = D_800FB0F8_BalloonBurst[arg1];
}

void func_800F9520_BalloonBurst(omObjData *arg0) {
    switch (D_800FB10E_BalloonBurst) {
        case 0:
            if (func_80072718() == 0) {
                D_800FB10E_BalloonBurst = 1;
                func_80060128(0x26);
            }
            break;
        case 1:
            D_800FB10E_BalloonBurst = 2;
            GMesCreate(0);
            break;
        case 2:
            if (GMesStatAllGet() == 0) {
                D_800FB10C_BalloonBurst = 1;
                omDelObj(arg0);
                GMesCreate(8, D_800FC386_BalloonBurst, 0xA0, 0x20);
            }
            break;
    }
}

// register allocation (masked 2: the motion-index temp lands in a1, retail v0)
#ifdef NON_MATCHING
void func_800F95F8_BalloonBurst(omObjData *arg0) {
    Vec2f screen;
    Vec pos;
    BalloonBurstObstacle *p;
    BalloonBurstObjectWork *work;
    f32 a;
    s32 i;
    s32 j;
    s32 m;

    if ((func_8005FD5C() & 0xFFFF) + D_800F64F8 != 0 && D_800FB110_BalloonBurst != 2) {
        return;
    }
    switch (D_800FB110_BalloonBurst) {
        case 0:
            if (--D_800FAF98_BalloonBurst == 0) {
                D_800FB110_BalloonBurst = 1;
            }
            break;
        case 1:
            func_800FA8A4_BalloonBurst((u16)D_800FC38E_BalloonBurst);
            p = D_800FB120_BalloonBurst[D_800FC38E_BalloonBurst].obstacles;
            D_800C34A4 = 0.0f;
            p[6].unk_88 = 0.2f;
            p[6].unk_8C = 1.0f;
            p[6].unk_90 = 0.0f;
            pos.x = D_800FB120_BalloonBurst[D_800FC38E_BalloonBurst].obstacles[6].unk_30.x;
            pos.y = D_800FB120_BalloonBurst[D_800FC38E_BalloonBurst].obstacles[6].unk_30.y;
            pos.z = D_800FB120_BalloonBurst[D_800FC38E_BalloonBurst].obstacles[6].unk_30.z;
            Convert3DTo2D(0, (Vec3f *)&pos, &screen);
            for (i = 0; i < 9; i++) {
                D_800FACE8_BalloonBurst[i].sprite = func_80019060(D_800FC3A0_BalloonBurst, 1, 0);
                ShowBasicSprite(D_800FACE8_BalloonBurst[i].sprite);
                D_800FACE8_BalloonBurst[i].x = screen.x;
                D_800FACE8_BalloonBurst[i].y = screen.y;
                if (i != 0) {
                    D_800FACE8_BalloonBurst[i].x = func_800AEFD0(D_800FACE8_BalloonBurst[i].angle) * 16.0f + D_800FACE8_BalloonBurst[i].x;
                    D_800FACE8_BalloonBurst[i].y = func_800AEAC0(D_800FACE8_BalloonBurst[i].angle) * 16.0f + D_800FACE8_BalloonBurst[i].y;
                }
                D_800FACE8_BalloonBurst[i].vx = func_800AEFD0(D_800FACE8_BalloonBurst[i].angle) * D_800FACE8_BalloonBurst[i].speed;
                D_800FACE8_BalloonBurst[i].vy = func_800AEAC0(D_800FACE8_BalloonBurst[i].angle) * D_800FACE8_BalloonBurst[i].speed;
                func_80018F68(D_800FACE8_BalloonBurst[i].sprite, 0xF5, 0xF5, 0xFF);
            }
            PlaySound(0x26D);
            for (i = 0; i < 4; i++) {
                if (i == D_800FC38E_BalloonBurst) {
                    func_80060F04(i, 10, 0, 10);
                } else {
                    func_80060F04(i, 2, 2, 20);
                }
            }
            D_800FB110_BalloonBurst = 2;
            func_800601D4(0x28);
            break;
        case 2:
            p = D_800FB120_BalloonBurst[D_800FC38E_BalloonBurst].obstacles;
            if ((func_8005FD5C() & 0xFFFF) + D_800F64F8 != 0) {
                func_80026B8C(p[6].unk_40, p[6].unk_90, p[6].unk_8C, 1);
                break;
            }
            for (i = 0; i < 9; i++) {
                func_80018E0C(D_800FACE8_BalloonBurst[i].sprite, D_800FACE8_BalloonBurst[i].frame);
                SetBasicSpriteSize(D_800FACE8_BalloonBurst[i].sprite, (s16)D_800FACE8_BalloonBurst[i].w, (s16)D_800FACE8_BalloonBurst[i].h);
                SetBasicSpritePos(D_800FACE8_BalloonBurst[i].sprite, D_800FACE8_BalloonBurst[i].x, D_800FACE8_BalloonBurst[i].y);
                func_80018CF8(D_800FACE8_BalloonBurst[i].sprite, D_800FACE8_BalloonBurst[i].alpha);
                if (D_800FACE8_BalloonBurst[i].frame <= 7.0f) {
                    D_800FACE8_BalloonBurst[i].w += D_800FACE8_BalloonBurst[i].dw;
                    D_800FACE8_BalloonBurst[i].h += D_800FACE8_BalloonBurst[i].dh;
                } else if (i == 0 && D_800FACE8_BalloonBurst[0].done == 0) {
                    for (j = 0; j < 4; j++) {
                        func_800F7D9C_BalloonBurst(j);
                    }
                    D_800FC38A_BalloonBurst = 1;
                    for (j = 0; j < 4; j++) {
                        m = (j != D_800FC38E_BalloonBurst) ? 0x2F : 0xF;
                        func_80025BB8(D_800FC39C_BalloonBurst[j]->model[0], D_800FC39C_BalloonBurst[j]->motion[m]);
                        func_80025EB4(D_800FC39C_BalloonBurst[j]->model[0], 2, 2);
                        if (j == D_800FC38E_BalloonBurst) {
                            func_80025EB4(D_800FC39C_BalloonBurst[j]->model[0], 1, 1);
                        }
                    }
                    D_800FACE8_BalloonBurst[i].done = 1;
                }
                D_800FACE8_BalloonBurst[i].x += D_800FACE8_BalloonBurst[i].vx;
                D_800FACE8_BalloonBurst[i].y += D_800FACE8_BalloonBurst[i].vy;
                D_800FACE8_BalloonBurst[i].frame = 11.0f / D_800FACE8_BalloonBurst[i].div + D_800FACE8_BalloonBurst[i].frame;
                if (D_800FACE8_BalloonBurst[i].frame >= 11.0f) {
                    D_800FACE8_BalloonBurst[i].frame = 11.0f;
                    D_800FACE8_BalloonBurst[i].alpha -= 4;
                    if (D_800FACE8_BalloonBurst[i].alpha < 0) {
                        D_800FACE8_BalloonBurst[i].alpha = 0;
                    }
                }
            }
            D_800C34A4 += 24.0f;
            if (D_800C34A4 >= 360.0f) {
                D_800C34A4 -= 360.0f;
            }
            if (p[6].unk_90 <= 1.0f) {
                p[6].unk_90 += 0.1f;
                p[6].unk_88 -= 0.002f;
                p[6].unk_8C += p[6].unk_88;
                func_80026B8C(p[6].unk_40, p[6].unk_90, p[6].unk_8C, 2);
                p[6].unk_84 += 0.1f;
                if (D_800FC38A_BalloonBurst == 0) {
                    a = p[6].unk_54 - p[6].unk_90 * 150.0f;
                    if (a < 0.0f) {
                        a = 0.0f;
                    }
                    func_800F8D6C_BalloonBurst((u8)D_800FC38E_BalloonBurst, func_800AEAC0(a) * 300.0f / 90.0f);
                }
            } else {
                D_800FB110_BalloonBurst = 4;
            }
            break;
        case 4:
            if (D_800FAF96_BalloonBurst == 1) {
                func_8002456C(D_800FB120_BalloonBurst[D_800FC38E_BalloonBurst].obstacles[6].unk_40);
                for (i = 0; i < 9; i++) {
                    func_80018C90(D_800FACE8_BalloonBurst[i].sprite);
                }
                for (i = 0; i < 5; i++) {
                    func_8002456C(D_800FB0EA_BalloonBurst[i]);
                }
            }
            if (--D_800FAF96_BalloonBurst == 0) {
                D_800FB110_BalloonBurst = 3;
            }
            break;
        case 3:
            D_800FB0B0_BalloonBurst = CRot.x;
            D_800FB0A0_BalloonBurst = 359.0f - CRot.x;
            D_800FB0C0_BalloonBurst = 90.0f;
            D_800FB0B4_BalloonBurst = D_800FB120_BalloonBurst[D_800FC38E_BalloonBurst].obstacles[0].pos.x;
            D_800FB0A4_BalloonBurst = (D_800FB0B4_BalloonBurst + Center.x) / 15.0f;
            D_800FB0B8_BalloonBurst = D_800FB120_BalloonBurst[D_800FC38E_BalloonBurst].obstacles[0].pos.y + 50.0f;
            D_800FB0A8_BalloonBurst = 3.3333333f;
            D_800FB0BC_BalloonBurst = D_800FB120_BalloonBurst[D_800FC38E_BalloonBurst].obstacles[0].pos.z - 2302.5f;
            D_800FB0AC_BalloonBurst = (D_800FB0BC_BalloonBurst - Center.z) / 15.0f;
            D_800FB0C8_BalloonBurst = 17.0f;
            D_800FB0C4_BalloonBurst = 0.0f;
            D_800FB110_BalloonBurst = 5;
            break;
        case 5:
            CRot.x = func_800B1750(8100.0f - D_800FB0C0_BalloonBurst * D_800FB0C0_BalloonBurst) * 0.011111111f * D_800FB0A0_BalloonBurst + D_800FB0B0_BalloonBurst;
            if (D_800FB0C0_BalloonBurst > 0.0f) {
                D_800FB0C0_BalloonBurst -= 6.0f;
            } else {
                D_800FB0C0_BalloonBurst = 0.0f;
            }
            if (Center.x != D_800FB0B4_BalloonBurst) {
                Center.x += D_800FB0A4_BalloonBurst;
                if (D_800FB0A4_BalloonBurst < 0.0f) {
                    if (Center.x < D_800FB0B4_BalloonBurst) {
                        Center.x = D_800FB0B4_BalloonBurst;
                    }
                } else if (Center.x > D_800FB0B4_BalloonBurst) {
                    Center.x = D_800FB0B4_BalloonBurst;
                }
            }
            if (Center.y != D_800FB0B8_BalloonBurst) {
                Center.y += D_800FB0A8_BalloonBurst;
                if (D_800FB0A8_BalloonBurst < 0.0f) {
                    if (Center.y < D_800FB0B8_BalloonBurst) {
                        Center.y = D_800FB0B8_BalloonBurst;
                    }
                } else if (Center.y > D_800FB0B8_BalloonBurst) {
                    Center.y = D_800FB0B8_BalloonBurst;
                }
            }
            if (Center.z != D_800FB0BC_BalloonBurst) {
                Center.z += D_800FB0AC_BalloonBurst;
                if (D_800FB0AC_BalloonBurst < 0.0f) {
                    if (Center.z < D_800FB0BC_BalloonBurst) {
                        Center.z = D_800FB0BC_BalloonBurst;
                    }
                } else if (Center.z > D_800FB0BC_BalloonBurst) {
                    Center.z = D_800FB0BC_BalloonBurst;
                }
            }
            D_800FB0C4_BalloonBurst += D_800FB0C8_BalloonBurst;
            if (Center.x == D_800FB0B4_BalloonBurst && Center.z == D_800FB0BC_BalloonBurst && CRot.x == 359.0f) {
                D_800FB110_BalloonBurst = 7;
                D_800FB0E0_BalloonBurst = 5;
                D_800FB0D4_BalloonBurst = Center.z + -52.5f;
                D_800FB0D8_BalloonBurst = Center.z + 200.0f;
                D_800FB0DC_BalloonBurst = Center.z + 75.0f;
                D_800FB0D0_BalloonBurst = (D_800FB0D8_BalloonBurst - D_800FB0D4_BalloonBurst) / 2.0f;
            }
            break;
        case 6:
            D_800FB110_BalloonBurst = 7;
            D_800FB0E0_BalloonBurst = 5;
            D_800FB0D4_BalloonBurst = Center.z + -52.5f;
            D_800FB0D8_BalloonBurst = Center.z + 200.0f;
            D_800FB0DC_BalloonBurst = Center.z + 75.0f;
            D_800FB0D0_BalloonBurst = (D_800FB0D8_BalloonBurst - D_800FB0D4_BalloonBurst) / 2.0f;
            func_80060128(0x33);
            func_80060234(0x7F);
            break;
        case 7:
            if (D_800FB0D0_BalloonBurst < 0.0f) {
                Center.z += D_800FB0D0_BalloonBurst;
                if (Center.z <= D_800FB0D4_BalloonBurst) {
                    D_800FB0D0_BalloonBurst = -D_800FB0D0_BalloonBurst;
                    Center.z = D_800FB0D4_BalloonBurst;
                    D_800FB0E0_BalloonBurst--;
                }
                if (D_800FB0E0_BalloonBurst == 0 && Center.z <= D_800FB0DC_BalloonBurst) {
                    Center.z = D_800FB0DC_BalloonBurst;
                    D_800FB110_BalloonBurst = 8;
                }
            } else {
                Center.z += D_800FB0D0_BalloonBurst;
                if (D_800FB0D8_BalloonBurst <= Center.z) {
                    D_800FB0D0_BalloonBurst = -D_800FB0D0_BalloonBurst;
                    Center.z = D_800FB0D8_BalloonBurst;
                    D_800FB0E0_BalloonBurst--;
                }
                if (D_800FB0E0_BalloonBurst == 0 && Center.z >= D_800FB0DC_BalloonBurst) {
                    Center.z = D_800FB0DC_BalloonBurst;
                    D_800FB110_BalloonBurst = 8;
                }
            }
            break;
        case 8:
            GMesCreate(2);
            func_800790C0();
            if (D_800FC392_BalloonBurst != 0) {
                D_800FB110_BalloonBurst = 0x11;
            } else {
                D_800FB110_BalloonBurst = 9;
            }
            break;
        case 9:
            if (GMesStatAllGet() & 2) {
                func_80025EB4(D_800FC39C_BalloonBurst[D_800FC38E_BalloonBurst]->model[0], 3, 0);
                D_800FB0CC_BalloonBurst = 0x24;
                func_80060128(0x33);
                D_800FB110_BalloonBurst = 10;
            }
            break;
        case 10:
            if (--D_800FB0CC_BalloonBurst == 0) {
                if (D_800FC390_BalloonBurst == 0) {
                    GMesCreate(4, GwPlayer[D_800FC38E_BalloonBurst].character);
                }
                D_800FB110_BalloonBurst = 0xE;
                D_800FB0CC_BalloonBurst = 0x48;
                func_80060618(0x451, D_800FC38E_BalloonBurst);
            }
            break;
        case 11:
            if (D_800FC392_BalloonBurst == 0) {
                GMesCreate(0x10);
                D_800FB110_BalloonBurst = 0xC;
            } else {
                GMesCreate(2);
                func_800790C0();
                D_800FB110_BalloonBurst = 0x11;
            }
            break;
        case 12:
            if (GMesStatAllGet() & 2) {
                for (i = 0; i < 4; i++) {
                    work = D_800FC39C_BalloonBurst[i]->unk_50;
                    func_80025BB8(D_800FC39C_BalloonBurst[i]->model[0], D_800FC39C_BalloonBurst[i]->motion[46]);
                    D_800F2B7C[D_800FC39C_BalloonBurst[i]->model[0]].unk_48 = work->unk_0C;
                    func_80025C20(D_800FC39C_BalloonBurst[i]->model[0], func_80025E48(D_800FC39C_BalloonBurst[i]->motion[39]), 0, 30, 2);
                }
                func_80060128(0x34);
                D_800FB0CC_BalloonBurst = 0x12;
                D_800FB110_BalloonBurst = 0xD;
            }
            break;
        case 13:
            if (--D_800FB0CC_BalloonBurst == 0) {
                if (D_800FC392_BalloonBurst == 0) {
                    GMesCreate(0x11);
                    D_800FB0CC_BalloonBurst = 0x4D;
                    D_800FB110_BalloonBurst = 0xE;
                } else {
                    D_800FB110_BalloonBurst = 0x11;
                }
            }
            break;
        case 14:
            if (--D_800FB0CC_BalloonBurst == 0) {
                D_800FB110_BalloonBurst = 0xF;
            }
            break;
        case 15:
            func_800726AC(0, 0x14);
            D_800FB110_BalloonBurst = 0x10;
            break;
        case 16:
            if (func_80072718() == 0) {
                func_800601D4(0x28);
                omDelObj(arg0);
                omOvlReturnEx(1);
            }
            break;
        case 17:
            if (GMesWait() != 1) {
                D_800FB110_BalloonBurst = 0xF;
            }
            break;
    }
}

// unreferenced; pads the unit's .rodata after the jump table above (the asm path carries it)
const u32 D_800FB098_BalloonBurst[2] = { 0, 0 };
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_13_BalloonBurst/149E80", func_800F95F8_BalloonBurst);
#endif
void func_800FA8A4_BalloonBurst(s32 arg0) {
    u16 model = D_800FB120_BalloonBurst[(u16)arg0].obstacles[6].model;
    u16 copy = D_800FB120_BalloonBurst[(u16)arg0].obstacles[6].unk_40;
    unk_ovl_2D_struct *src = &D_800F2B7C[model];

    func_800258EC((s16)model, 4, 4);
    func_80025798((s16)copy, src->unk_24, src->unk_28, src->unk_2C);
    func_800257E4((s16)copy, src->unk_30, src->unk_34, src->unk_38);
    func_80025830((s16)copy, src->unk_3C, src->unk_40, src->unk_44);
    D_800F2B7C[copy].unk_48 = src->unk_48;
    func_800258EC((s16)copy, 4, 0);
    func_80025830((s16)copy, 1.5f, 1.5f, 1.5f);
}

void func_800FA9C4_BalloonBurst(f32 arg0, Vec3f *arg1) {
    f32 angle = arg0 * 2.0f;

    if (angle >= 360.0f) {
        angle -= 360.0f;
    }
    arg1->x = func_800AEAC0(arg0) * 160.0f;
    arg1->z = func_800AEFD0(arg0) * 160.0f;
    arg1->y = func_800AEAC0(angle) * 50.0f;
}

void func_800FAA6C_BalloonBurst(omObjData *arg0, u16 *arg1, s16 *arg2) {
    u16 temp_v1;
    u16 temp_v1_2;
    u16 temp_v1_3;
    u16 var_v0;
    BalloonBurstObjectWork *temp_s0;

    temp_s0 = arg0->unk_50;
    *arg1 = 0;
    *arg2 = 0;
    if (temp_s0->unk_1E == 0) {
        temp_s0->unk_1E = temp_s0->unk_16 + ((s32)(rand8() & 0xFF) % (s32)temp_s0->unk_18);
    }
    temp_v1 = temp_s0->unk_1C;
    if (temp_v1 & 4) {
        if (temp_s0->unk_22 == 0) {
            temp_s0->unk_1C = temp_v1 & 0xFFFB;
            return;
        }
        temp_s0->unk_22--;
        return;
    }
    if ((temp_s0->unk_20 < temp_s0->unk_1E) && !(temp_s0->unk_1C & 1)) {
        *arg1 |= 0x2000;
        temp_s0->unk_1C |= 2;
        var_v0 = temp_s0->unk_20 + 1;
        goto block_20;
    }
    if (temp_s0->unk_20 == temp_s0->unk_1E) {
        temp_v1_2 = temp_s0->unk_1C;
        if (temp_v1_2 & 2) {
            temp_s0->unk_1C = (temp_v1_2 & 0xFFFD) | 1;
            goto block_15;
        }
    }
    if (temp_s0->unk_20 == 0) {
        temp_v1_3 = temp_s0->unk_1C;
        if (temp_v1_3 & 1) {
            temp_s0->unk_1C = temp_v1_3 & 0xFFFE;
            temp_s0->unk_1E = temp_s0->unk_16 + ((s32)(rand8() & 0xFF) % (s32)temp_s0->unk_18);
block_15:
            if (temp_s0->unk_1A >= 2U) {
                temp_s0->unk_22 = (s32)(rand8() & 0xFF) % (s32)temp_s0->unk_1A;
                temp_s0->unk_1C |= 4;
            }
        } else if (temp_s0->unk_20 != 0) {
            goto block_18;
        }
    } else {
block_18:
        if (temp_s0->unk_1C & 1) {
            *arg1 |= 0x8000;
            var_v0 = temp_s0->unk_20 - 1;
block_20:
            temp_s0->unk_20 = var_v0;
        }
    }
}
