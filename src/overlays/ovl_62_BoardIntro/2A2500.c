#include "common.h"
#include "ovl62.h"
#include "2A2500.h"

/* .data */

void func_800F6854_BoardIntro(void);
void func_800F69F8_BoardIntro(void);
void func_800F6B18_BoardIntro(void);
void func_800F6BE4_BoardIntro(void);
void func_800F6DAC_BoardIntro(void);
void func_800F7054_BoardIntro(void);
void func_800F7330_BoardIntro(void);
void func_800F73FC_BoardIntro(void);
void func_800F92C0_BoardIntro(void);
void func_800F9500_BoardIntro(void);
void func_800F9920_BoardIntro(void);
void func_800FA168_BoardIntro(void);
void func_800FAD50_BoardIntro(void);
void func_800FAF80_BoardIntro(void);
void func_800FB5D0_BoardIntro(void);
void func_800FB7C0_BoardIntro(void);
void func_800F93AC_BoardIntro(void);
void func_800F959C_BoardIntro(void);
void func_800F9BCC_BoardIntro(void);
void func_800FA214_BoardIntro(void);
void func_800FADFC_BoardIntro(void);
void func_800FB20C_BoardIntro(void);
void func_800FB66C_BoardIntro(void);
void func_800FC1CC_BoardIntro(void);
void func_800FC67C_BoardIntro(void);
extern char D_800FD930_BoardIntro[];
extern char D_800FD93C_BoardIntro[];
extern char D_800FD948_BoardIntro[];
extern char D_800FD954_BoardIntro[];
extern char D_800FD960_BoardIntro[];
extern char D_800FD96C_BoardIntro[];
extern char D_800FD974_BoardIntro[];
extern char D_800FD980_BoardIntro[];

omObjData* D_800FCD30_BoardIntro[16] = {
    NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL,
};

Object* D_800FCD70_BoardIntro = NULL;

s32 D_800FCD74_BoardIntro = -1;

s32 D_800FCD78_BoardIntro[4] = {
    -1, -1, -1, -1,
};

Object* D_800FCD88_BoardIntro[4] = {
    NULL, NULL, NULL, NULL,
};

omObjData* D_800FCD98_BoardIntro[4] = {
    NULL, NULL, NULL, NULL,
};

s32 D_800FCDA8_BoardIntro = 0;

s32 D_800FCDAC_BoardIntro = 0;

s32 D_800FCDB0_BoardIntro = 0;

Process* D_800FCDB4_BoardIntro = NULL;

s32 D_800FCDB8_BoardIntro[8] = {
    6, 17, 26, 38,
    46, 55, 67, 76,
};

s32 D_800FCDD8_BoardIntro[9] = {
    1, 8, 19, 28,
    40, 48, 57, 69,
    78,
};

u8 D_800FCDFC_BoardIntro[8] = {
    0x0A, 0x07, 0x07, 0x09, 0x0A, 0x09, 0x07, 0x08,
};

char* D_800FCE04_BoardIntro[8] = {
    D_800FD980_BoardIntro, D_800FD974_BoardIntro, D_800FD96C_BoardIntro, D_800FD960_BoardIntro,
    D_800FD954_BoardIntro, D_800FD948_BoardIntro, D_800FD93C_BoardIntro, D_800FD930_BoardIntro,
};

Vec3f D_800FCE24_BoardIntro[9] = {
    { 0.0f, 0.0f, 2040.0f },
    { 0.0f, 0.0f, 2040.0f },
    { 0.0f, 0.0f, 2040.0f },
    { 0.0f, 0.0f, 2040.0f },
    { 0.0f, 0.0f, 2040.0f },
    { 0.0f, 0.0f, 2040.0f },
    { 0.0f, 0.0f, 2040.0f },
    { 0.0f, 0.0f, 2040.0f },
    { 0.0f, 0.0f, 2040.0f },
};

Vec3f D_800FCE90_BoardIntro = { -134.0f, 200.0f, 3263.0f };

Vec3f D_800FCE9C_BoardIntro[9][4] = {
    { { -105.0f, 0.0f, 2360.0f }, { 10.0f, 0.0f, 1725.0f }, { 205.0f, 0.0f, 1875.0f }, { 315.0f, 0.0f, 2300.0f } },
    { { -105.0f, 0.0f, 2360.0f }, { 10.0f, 0.0f, 1725.0f }, { 205.0f, 0.0f, 1875.0f }, { 315.0f, 0.0f, 2300.0f } },
    { { -105.0f, 0.0f, 2360.0f }, { 10.0f, 0.0f, 1725.0f }, { 205.0f, 0.0f, 1875.0f }, { 315.0f, 0.0f, 2300.0f } },
    { { -105.0f, 0.0f, 2360.0f }, { 10.0f, 0.0f, 1725.0f }, { 205.0f, 0.0f, 1875.0f }, { 315.0f, 0.0f, 2300.0f } },
    { { -105.0f, 0.0f, 2360.0f }, { 10.0f, 0.0f, 1725.0f }, { 205.0f, 0.0f, 1875.0f }, { 315.0f, 0.0f, 2300.0f } },
    { { -105.0f, 0.0f, 2360.0f }, { 10.0f, 0.0f, 1725.0f }, { 205.0f, 0.0f, 1875.0f }, { 315.0f, 0.0f, 2300.0f } },
    { { -105.0f, 0.0f, 2360.0f }, { 10.0f, 0.0f, 1725.0f }, { 205.0f, 0.0f, 1875.0f }, { 315.0f, 0.0f, 2300.0f } },
    { { -105.0f, 0.0f, 2360.0f }, { 10.0f, 0.0f, 1725.0f }, { 205.0f, 0.0f, 1875.0f }, { 315.0f, 0.0f, 2300.0f } },
    { { -105.0f, 0.0f, 2360.0f }, { 10.0f, 0.0f, 1725.0f }, { 205.0f, 0.0f, 1875.0f }, { 315.0f, 0.0f, 2300.0f } },
};

Vec3f D_800FD04C_BoardIntro[9][4] = {
    { { -130.0f, 0.0f, 2175.0f }, { -35.0f, 0.0f, 1930.0f }, { 125.0f, 0.0f, 2045.0f }, { 220.0f, 0.0f, 2230.0f } },
    { { -130.0f, 0.0f, 2175.0f }, { -35.0f, 0.0f, 1930.0f }, { 125.0f, 0.0f, 2045.0f }, { 220.0f, 0.0f, 2230.0f } },
    { { -130.0f, 0.0f, 2175.0f }, { -35.0f, 0.0f, 1930.0f }, { 125.0f, 0.0f, 2045.0f }, { 220.0f, 0.0f, 2230.0f } },
    { { -130.0f, 0.0f, 2175.0f }, { -35.0f, 0.0f, 1930.0f }, { 125.0f, 0.0f, 2045.0f }, { 220.0f, 0.0f, 2230.0f } },
    { { -130.0f, 0.0f, 2175.0f }, { -35.0f, 0.0f, 1930.0f }, { 125.0f, 0.0f, 2045.0f }, { 220.0f, 0.0f, 2230.0f } },
    { { -130.0f, 0.0f, 2175.0f }, { -35.0f, 0.0f, 1930.0f }, { 125.0f, 0.0f, 2045.0f }, { 220.0f, 0.0f, 2230.0f } },
    { { -130.0f, 0.0f, 2175.0f }, { -35.0f, 0.0f, 1930.0f }, { 125.0f, 0.0f, 2045.0f }, { 220.0f, 0.0f, 2230.0f } },
    { { -205.0f, 0.0f, 1925.0f }, { 40.0f, 0.0f, 1605.0f }, { 175.0f, 0.0f, 1770.0f }, { 245.0f, 0.0f, 1980.0f } },
    { { -130.0f, 0.0f, 2175.0f }, { -35.0f, 0.0f, 1930.0f }, { 125.0f, 0.0f, 2045.0f }, { 220.0f, 0.0f, 2230.0f } },
};

Vec3f D_800FD1FC_BoardIntro[9][4] = {
    { { -190.0f, 0.0f, 2120.0f }, { -15.0f, 0.0f, 2120.0f }, { 160.0f, 0.0f, 2120.0f }, { 335.0f, 0.0f, 2120.0f } },
    { { -190.0f, 0.0f, 2120.0f }, { -15.0f, 0.0f, 2120.0f }, { 160.0f, 0.0f, 2120.0f }, { 335.0f, 0.0f, 2120.0f } },
    { { -190.0f, 0.0f, 2120.0f }, { -15.0f, 0.0f, 2120.0f }, { 160.0f, 0.0f, 2120.0f }, { 335.0f, 0.0f, 2120.0f } },
    { { -190.0f, 0.0f, 2120.0f }, { -15.0f, 0.0f, 2120.0f }, { 160.0f, 0.0f, 2120.0f }, { 335.0f, 0.0f, 2120.0f } },
    { { -190.0f, 0.0f, 2120.0f }, { -15.0f, 0.0f, 2120.0f }, { 160.0f, 0.0f, 2120.0f }, { 335.0f, 0.0f, 2120.0f } },
    { { -190.0f, 0.0f, 2120.0f }, { -15.0f, 0.0f, 2120.0f }, { 160.0f, 0.0f, 2120.0f }, { 335.0f, 0.0f, 2120.0f } },
    { { -190.0f, 0.0f, 2120.0f }, { -15.0f, 0.0f, 2120.0f }, { 160.0f, 0.0f, 2120.0f }, { 335.0f, 0.0f, 2120.0f } },
    { { -190.0f, 0.0f, 2120.0f }, { -15.0f, 0.0f, 2120.0f }, { 160.0f, 0.0f, 2120.0f }, { 335.0f, 0.0f, 2120.0f } },
    { { -190.0f, 0.0f, 2120.0f }, { -15.0f, 0.0f, 2120.0f }, { 160.0f, 0.0f, 2120.0f }, { 335.0f, 0.0f, 2120.0f } },
};

s32 D_800FD3AC_BoardIntro[8] = {
    0x23B, 0x23C, 0x23D, 0x23E,
    0x23F, 0x240, 0x241, 0x242,
};

Vec3f D_800FD3CC_BoardIntro[8] = {
    { -590.0f, 0.0f, 2040.0f },
    { -345.0f, 600.0f, 2040.0f },
    { -2250.0f, 0.0f, -5000.0f },
    { -345.0f, 0.0f, 2040.0f },
    { -45.0f, 0.0f, 4080.0f },
    { 760.0f, 935.0f, -355.0f },
    { -590.0f, 0.0f, 2040.0f },
    { 865.0f, 180.0f, -3680.0f },
};

Vec3f D_800FD42C_BoardIntro = { -345.0f, 0.0f, 2040.0f };

s32 D_800FD438_BoardIntro[9] = {
    8, 0x1001E, 0x1001C, 0x10000,
    0x10001, 0x10003, 0xA008B, 0x1003B,
    0x10039,
};

s32 D_800FD45C_BoardIntro[9] = {
    8, 0x2001E, 0x2001C, 0x20000,
    0x20001, 0x20003, 0xA008C, 0x2003B,
    0x20039,
};

s32 D_800FD480_BoardIntro[9] = {
    8, 0x6001E, 0x6001C, 0x60000,
    0x60001, 0x60003, 0xA008D, 0x6003B,
    0x60039,
};

s32 D_800FD4A4_BoardIntro[9] = {
    8, 0x3001E, 0x3001C, 0x30000,
    0x30001, 0x30003, 0xA008E, 0x3003B,
    0x30039,
};

s32 D_800FD4C8_BoardIntro[9] = {
    8, 0x4001E, 0x4001C, 0x40000,
    0x40001, 0x40003, 0xA008F, 0x4003B,
    0x40039,
};

s32 D_800FD4EC_BoardIntro[9] = {
    8, 0x5001E, 0x5001C, 0x50000,
    0x50001, 0x50003, 0xA0090, 0x5003B,
    0x50039,
};

s32* D_800FD510_BoardIntro[6] = {
    D_800FD438_BoardIntro, D_800FD45C_BoardIntro, D_800FD480_BoardIntro, D_800FD4A4_BoardIntro,
    D_800FD4C8_BoardIntro, D_800FD4EC_BoardIntro,
};

s32 D_800FD528_BoardIntro[4] = {
    3, 0xA0072, 0xA0073, 0xA0074,
};

s32 D_800FD538_BoardIntro[4] = {
    3, 0x70000, 0x70002, 0x70003,
};

u8 D_800FD548_BoardIntro[12] = {
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x00, 0x00, 0x00, 0x00,
};

BoardIntroPos D_800FD554_BoardIntro[18] = {
    { 160, 84 }, { 160, 84 }, { -161, 80 }, { 162, 102 },
    { 160, 84 }, { 161, 97 }, { 156, -79 }, { 161, 99 },
    { 165, -73 }, { 485, 87 }, { 160, 100 }, { 160, 111 },
    { 160, 93 }, { 161, 103 }, { 160, 88 }, { 811, -80 },
    { 160, 100 }, { 160, 100 },
};

s32 D_800FD59C_BoardIntro[18] = {
    0xA0164, 0xA0165, 0xA0167, 0xA0168,
    0xA016A, 0xA016B, 0xA016D, 0xA016E,
    0xA0170, 0xA0171, 0xA0173, 0xA0174,
    0xA0176, 0xA0177, 0xA0179, 0xA017A,
    0xA0164, 0xA0165,
};

void (*D_800FD5E4_BoardIntro[9])(void) = {
    func_800F6854_BoardIntro, func_800F69F8_BoardIntro, func_800F6B18_BoardIntro, func_800F6BE4_BoardIntro,
    func_800F6DAC_BoardIntro, func_800F7054_BoardIntro, func_800F7330_BoardIntro, func_800F73FC_BoardIntro,
    NULL,
};

u8 D_800FD608_BoardIntro[8] = {
    0x12, 0x13, 0x11, 0x11, 0x10, 0x11, 0x12, 0x11,
};

u8 D_800FD610_BoardIntro[8] = {
    0x04, 0x04, 0x03, 0x04, 0x04, 0x03, 0x04, 0x04,
};

void (*D_800FD618_BoardIntro[9])(void) = {
    func_800F92C0_BoardIntro, func_800F9500_BoardIntro, func_800F9920_BoardIntro, func_800FA168_BoardIntro,
    func_800FAD50_BoardIntro, func_800FAF80_BoardIntro, func_800FB5D0_BoardIntro, func_800FB7C0_BoardIntro,
    NULL,
};

void (*D_800FD63C_BoardIntro[9])(void) = {
    func_800F93AC_BoardIntro, func_800F959C_BoardIntro, func_800F9BCC_BoardIntro, func_800FA214_BoardIntro,
    func_800FADFC_BoardIntro, func_800FB20C_BoardIntro, func_800FB66C_BoardIntro, func_800FC1CC_BoardIntro,
    func_800FC67C_BoardIntro,
};

void func_800F65E0_BoardIntro(void) {
    D_801102B0 = GwSystem.curBoardIndex;
    omInitObjMan(50, 10);
    func_800F9200_BoardIntro();
    func_800F906C_BoardIntro();
    func_8006CEA0();
    omAddPrcObj(func_800F8DC8_BoardIntro, 0x300, 0x2000, 0);
    omAddObj(0x1000, 0, 0, -1, func_800F8FEC_BoardIntro);
}
void func_800F6660_BoardIntro(s32 arg0, s32 arg1) {
    GW_PLAYER* temp_s1;
    GW_PLAYER* temp_s2;
    GW_PLAYER* temp_v0;

    temp_s1 = GetPlayerStruct(arg0);
    temp_s2 = GetPlayerStruct(arg1);
    temp_v0 = HuMemDirectMalloc(sizeof(GW_PLAYER));
    bcopy(temp_s1, temp_v0, sizeof(GW_PLAYER));
    bcopy(temp_s2, temp_s1, sizeof(GW_PLAYER));
    bcopy(temp_v0, temp_s2, sizeof(GW_PLAYER));
    HuMemDirectFree(temp_v0);
}

void func_800F66E8_BoardIntro(void) {
    s32 i;
    s32 j;

    for (i = 3; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (GwPlayer[j].player_index > GwPlayer[j + 1].player_index) {
                func_800F6660_BoardIntro(j, j + 1);
            }
        }
    }
}
void func_800F677C_BoardIntro(omObjData* obj) {
    func_80066DC4(D_800FDA50_BoardIntro.unk_14[0], obj->work[0], obj->work[1], obj->work[2] * 5 - 0x50);
    obj->work[2] += 2;
    if (obj->work[2] > 0x20) {
        D_800FCD30_BoardIntro[obj->work[0] - 1] = NULL;
        omDelObj(obj);
    }
}
s32 func_800F67F8_BoardIntro(s32 arg0) {
    return func_8004F628(D_800FD59C_BoardIntro[D_801102B0 * 2 + arg0], 10,
                         D_800FD554_BoardIntro[D_801102B0 * 2 + arg0].x,
                         D_800FD554_BoardIntro[D_801102B0 * 2 + arg0].y);
}
s32 func_800F684C_BoardIntro(void) {
    return 0;
}

void func_800F6854_BoardIntro(void) {
    s32 sp10[2];
    f32 t;
    f32 scale;
    f32 angle;

    func_80060128(57);
    HuPrcSleep(30);
    sp10[0] = func_800F67F8_BoardIntro(0);
    for (t = 0.0f; t <= 1.0f; t += 0.2f) {
        func_8004F7C0(sp10[0], t, t);
        HuPrcVSleep();
    }
    HuPrcSleep(34);
    func_8004F584(sp10[0]);
    sp10[1] = func_800F67F8_BoardIntro(1);
    scale = 0.5f;
    angle = 180.0f;
    while (1) {
        t = sinf(angle * (M_PI / 180)) * scale + 1.0f;
        angle += 30.0f;
        scale -= 0.033;
        if (scale <= 0.0f) {
            break;
        }
        func_8004F7C0(sp10[1], t, t);
        HuPrcVSleep();
    }
    t = 1.0f;
    func_8004F7C0(sp10[1], t, t);
    HuPrcSleep(12);
    func_800F684C_BoardIntro();
    HuPrcSleep(60);
}
void func_800F69F8_BoardIntro(void) {
    s32 sp10[2];
    f32 t;
    s32 x;

    HuPrcSleep(10);
    func_80060128(57);
    sp10[0] = func_800F67F8_BoardIntro(0);
    for (x = D_800FD554_BoardIntro[D_801102B0 * 2].x; x < 0xA0; x += 8) {
        func_8004F754(sp10[0], x, D_800FD554_BoardIntro[D_801102B0 * 2].y);
        HuPrcVSleep();
    }
    HuPrcSleep(30);
    sp10[1] = func_800F67F8_BoardIntro(1);
    for (t = 0.0f; t <= 1.0f; t += 0.1f) {
        func_8004F7C0(sp10[1], t, 1.0f);
        HuPrcVSleep();
    }
    HuPrcSleep(20);
    func_800F684C_BoardIntro();
    HuPrcSleep(60);
}
void func_800F6B18_BoardIntro(void) {
    s32 sp10[2];
    f32 var_f20;

    func_80060128(57);
    HuPrcSleep(10);
    sp10[0] = func_800F67F8_BoardIntro(0);
    
    for (var_f20 = 0.0f; var_f20 <= 1.0f; var_f20 += 0.1f) {
        func_8004F7C0(sp10[0], 1.0f, var_f20);
        HuPrcVSleep();
    }
    
    func_8004F7C0(sp10[0], 1.0f, 1.0f);
    HuPrcSleep(34);
    sp10[1] = func_800F67F8_BoardIntro(1);
    HuPrcSleep(42);
    func_800F684C_BoardIntro();
    HuPrcSleep(60);
}

void func_800F6BE4_BoardIntro(void) {
    s32 sp10[2];
    f32 amp;
    f32 angle;
    f32 t;
    s32 y;

    func_80060128(57);
    HuPrcSleep(10);
    sp10[0] = func_800F67F8_BoardIntro(0);
    for (y = D_800FD554_BoardIntro[D_801102B0 * 2].y; y < 0x51; y += 0x10) {
        func_8004F754(sp10[0], D_800FD554_BoardIntro[D_801102B0 * 2].x, y);
        HuPrcVSleep();
    }
    amp = 16.0f;
    angle = 5.0f;
    while (1) {
        t = sinf(angle * (M_PI / 180)) * amp;
        angle += 50.0f;
        amp -= 0.4;
        if (amp <= 1.0f) {
            break;
        }
        func_8004F754(sp10[0], D_800FD554_BoardIntro[D_801102B0 * 2].x, y + t);
        HuPrcVSleep();
    }
    func_8004F754(sp10[0], D_800FD554_BoardIntro[D_801102B0 * 2].x, y);
    HuPrcSleep(12);
    sp10[1] = func_800F67F8_BoardIntro(1);
    HuPrcSleep(27);
    func_800F684C_BoardIntro();
    HuPrcSleep(60);
}
void func_800F6DAC_BoardIntro(void) {
    s32 sp10[2];
    f32 amp;
    f32 angle;
    f32 t;
    s32 y;
    s32 x;

    func_80060128(57);
    HuPrcSleep(10);
    sp10[0] = func_800F67F8_BoardIntro(0);
    for (y = D_800FD554_BoardIntro[D_801102B0 * 2].y; y < 0x58; y += 0x10) {
        func_8004F754(sp10[0], D_800FD554_BoardIntro[D_801102B0 * 2].x, y);
        HuPrcVSleep();
    }
    y -= 0x10;
    HuPrcSleep(23);
    sp10[1] = func_800F67F8_BoardIntro(1);
    for (x = D_800FD554_BoardIntro[D_801102B0 * 2 + 1].x; x >= 0xA6; x -= 0x10) {
        func_8004F754(sp10[1], x, D_800FD554_BoardIntro[D_801102B0 * 2 + 1].y);
        HuPrcVSleep();
    }
    amp = 16.0f;
    angle = 180.0f;
    while (1) {
        t = sinf(angle * (M_PI / 180)) * amp;
        angle += 50.0f;
        amp -= 2.0;
        if (amp <= 1.0f) {
            break;
        }
        func_8004F754(sp10[0], D_800FD554_BoardIntro[D_801102B0 * 2].x + t, y);
        func_8004F754(sp10[1], x + t, D_800FD554_BoardIntro[D_801102B0 * 2 + 1].y);
        HuPrcVSleep();
    }
    func_8004F754(sp10[0], D_800FD554_BoardIntro[D_801102B0 * 2].x, y);
    func_8004F754(sp10[1], x, D_800FD554_BoardIntro[D_801102B0 * 2 + 1].y);
    HuPrcSleep(25);
    func_800F684C_BoardIntro();
    HuPrcSleep(60);
}
void func_800F7054_BoardIntro(void) {
    s32 sp10[2];
    f32 x0;
    f32 y0;
    f32 angle;
    f32 scale;
    f32 t;
    s32 x;

    HuPrcSleep(10);
    func_80060128(57);
    sp10[0] = func_800F67F8_BoardIntro(0);
    x0 = 164.0f;
    y0 = 54.0f;
    for (angle = -90.0f; angle <= 450.0f; angle += 10.0f) {
        x = D_800FD554_BoardIntro[D_801102B0 * 2].x - sinf(angle * (M_PI / 180)) * 110.0f + x0;
        func_8004F754(sp10[0], x, D_800FD554_BoardIntro[D_801102B0 * 2].y + cosf(angle * (M_PI / 180)) * 70.0f + y0);
        x0 -= 1.0f;
        y0 -= 1.0f;
        HuPrcVSleep();
    }
    HuPrcSleep(20);
    sp10[1] = func_800F67F8_BoardIntro(1);
    for (t = 0.0f; t < 1.0f; t += 0.2f) {
        func_8004F7C0(sp10[1], t, t);
        HuPrcVSleep();
    }
    scale = 0.3f;
    angle = 0.0f;
    while (1) {
        t = sinf(angle * (M_PI / 180)) * scale + 1.0f;
        angle += 30.0f;
        scale -= 0.01;
        if (scale <= 0.0f) {
            break;
        }
        func_8004F7C0(sp10[1], t, t);
        HuPrcVSleep();
    }
    t = 1.0f;
    func_8004F7C0(sp10[1], t, t);
    func_800F684C_BoardIntro();
    HuPrcSleep(60);
}
void func_800F7330_BoardIntro(void) {
    s32 sp10[2];
    f32 t;

    func_80060128(57);
    HuPrcSleep(10);
    sp10[0] = func_800F67F8_BoardIntro(0);
    for (t = 0.0f; t <= 1.0f; t += 0.1f) {
        func_8004F7C0(sp10[0], t, 1.0f);
        HuPrcVSleep();
    }
    func_8004F7C0(sp10[0], 1.0f, 1.0f);
    HuPrcSleep(34);
    sp10[1] = func_800F67F8_BoardIntro(1);
    HuPrcSleep(42);
    func_800F684C_BoardIntro();
    HuPrcSleep(60);
}
void func_800F73FC_BoardIntro(void) {
    s32 sp10[2];
    f32 t;
    s32 x;
    s32 y;

    func_80060128(57);
    HuPrcSleep(18);
    sp10[1] = func_800F67F8_BoardIntro(1);
    sp10[0] = func_800F67F8_BoardIntro(0);
    for (t = 0.0f; t <= 1.0f; t += 0.1f) {
        func_8004F7C0(sp10[0], t, t);
        HuPrcVSleep();
    }
    func_8004F7C0(sp10[0], 1.0f, 1.0f);
    HuPrcSleep(25);
    x = D_800FD554_BoardIntro[D_801102B0 * 2 + 1].x;
    y = D_800FD554_BoardIntro[D_801102B0 * 2 + 1].y;
    while ((x >= 0xAB) & (y < 0x51)) {
        func_8004F754(sp10[1], x, y);
        x -= 0x40;
        HuPrcVSleep();
        y += 0x10;
    }
    HuPrcSleep(30);
    func_800F684C_BoardIntro();
    HuPrcSleep(60);
}
void func_800F7538_BoardIntro(void) {
    s32 i;
    s16 mes;
    s32 len;

    LoadBackgroundIndex(D_800FCDB8_BoardIntro[D_801102B0]);
    func_80072724(0xFF, 0xFF, 0xFF);
    SetFadeInTypeAndTime(2, 16);
    HuPrcSleep(16);
    if (D_800FD548_BoardIntro[D_801102B0] != 0) {
        func_8004F548();
        if (D_800FD5E4_BoardIntro[D_801102B0] != NULL) {
            D_800FD5E4_BoardIntro[D_801102B0]();
        }
        func_800726AC(2, 20);
        HuPrcSleep(20);
        func_8004A140();
        func_8004F5F0();
        return;
    }
    len = D_800FCDFC_BoardIntro[D_801102B0];
    mes = GMesFontMesCreate(&D_800FDA50_BoardIntro, D_800FCE04_BoardIntro[D_801102B0], 0, -1, -1);
    D_800FCDAC_BoardIntro = 1;
    func_80066DC4(D_800FDA50_BoardIntro.unk_14[mes], 0, 0, 0);
    for (i = 0; i < len; i++) {
        func_80066DC4(D_800FDA50_BoardIntro.unk_14[mes], i + 1, (10 - len) * 3 + 30 + i * ((10 - len) * 2 + 17), -80);
        func_80067354(D_800FDA50_BoardIntro.unk_14[mes], i + 1, 1.5f, 1.5f);
    }
    for (i = 0; i < len; i++) {
        D_800FCD30_BoardIntro[i] = omAddObj(0x1000, 0, 0, -1, func_800F677C_BoardIntro);
        D_800FCD30_BoardIntro[i]->work[0] = i + 1;
        D_800FCD30_BoardIntro[i]->work[1] = (10 - len) * 3 + 30 + i * ((10 - len) * 2 + 17);
        D_800FCD30_BoardIntro[i]->work[2] = 0;
        HuPrcSleep(5);
    }
    HuPrcSleep(30);
    for (i = 0; i < 320; i += 10) {
        func_80066DC4(D_800FDA50_BoardIntro.unk_14[mes], 0, i, 0);
        HuPrcVSleep();
    }
    func_800726AC(2, 20);
    HuPrcSleep(20);
    func_80077044(&D_800FDA50_BoardIntro);
    D_800FCDAC_BoardIntro = 0;
    func_8004A140();
}
/* Retail reloads D_800FCD88 after each store through it: the original read it as a struct member
   (a store into a struct may alias another struct's field, not a scalar global). The matching
   build reaches the same symbol through a one-field struct; the host reads the global directly. */
typedef struct ObjectRef {
    Object* p;
} ObjectRef;
extern ObjectRef D_800FCD88_ref __asm__("D_800FCD88_BoardIntro");
#define D_800FCD88_RELOAD (D_800FCD88_ref.p)

void func_800F7858_BoardIntro(omObjData* obj) {
    obj->trans.y += obj->scale.y;
    D_800FCD88_RELOAD->unk_30 = obj->trans.y;
    if (obj->scale.y > 0.0f) {
        obj->scale.y -= 4.0f;
    } else {
        obj->scale.y -= 1.5f;
    }
    if (obj->scale.y <= 0.0f) {
        D_800FCD88_RELOAD->coords.x = D_800FCE90_BoardIntro.x;
        D_800FCD88_RELOAD->coords.z = D_800FCE90_BoardIntro.z;
        func_8004CCD0(&D_800FCD88_RELOAD->coords, &D_800F32A0->coords, &D_800FCD88_RELOAD->unk_18);
    }
    if (obj->scale.y <= 0.0f && obj->trans.y < D_800FCE90_BoardIntro.y) {
        D_800FCD88_RELOAD->unk_30 = D_800FCE90_BoardIntro.y;
        omDelObj(obj);
    }
}
void func_800F7988_BoardIntro(omObjData* obj) {
    obj->work[1]++;
    if (obj->work[1] == 40) {
        MBMotionSet(GwPlayer[obj->work[0]].player_obj, 1, 0);
    }
    obj->trans.y += obj->scale.y;
    GwPlayer[obj->work[0]].player_obj->unk_30 = obj->trans.y;
    if (obj->scale.y > 0.0f) {
        obj->scale.y -= 4.0f;
    } else {
        obj->scale.y -= 1.5f;
    }
    if (obj->scale.y <= 0.0f) {
        GwPlayer[obj->work[0]].player_obj->coords.x = D_800FCE9C_BoardIntro[D_801102B0][obj->work[0]].x;
        GwPlayer[obj->work[0]].player_obj->coords.z = D_800FCE9C_BoardIntro[D_801102B0][obj->work[0]].z;
    }
    if (obj->trans.y < D_800FCE9C_BoardIntro[D_801102B0][obj->work[0]].y) {
        GwPlayer[obj->work[0]].player_obj->unk_30 = D_800FCE9C_BoardIntro[D_801102B0][obj->work[0]].y;
        omDelObj(obj);
    }
}
void func_800F7B5C_BoardIntro(void) {
    Object* model;
    omObjData* obj;
    s32 i;

    LoadBackgroundIndex(D_800FCDD8_BoardIntro[D_801102B0]);
    model = MBModelCreate(0x16, NULL);
    model->coords.x = D_800FCE24_BoardIntro[D_801102B0].x;
    model->coords.y = D_800FCE24_BoardIntro[D_801102B0].y;
    model->coords.z = D_800FCE24_BoardIntro[D_801102B0].z;
    model->xScale = model->yScale = model->zScale = 0.0f;
    if (D_801102B0 == 8) {
        func_80072724(0xFF, 0xFF, 0xFF);
    }
    SetFadeInTypeAndTime(2, 16);
    HuPrcSleep(16);
    PlaySound(0x40);
    for (i = 0; i < 90; i += 10) {
        model->zScale = 1.0f;
        model->xScale = 1.0f;
        model->yScale = sinf(i * (M_PI / 180));
        HuPrcVSleep();
    }
    if (D_801102B0 == 8) {
        D_800FCD88_RELOAD = MBModelCreate(7, D_800FD538_BoardIntro);
        D_800FCD88_RELOAD->unk_0A |= 1;
        D_800FCD88_RELOAD->coords.x = D_800FCE24_BoardIntro[D_801102B0].x;
        D_800FCD88_RELOAD->coords.y = D_800FCE24_BoardIntro[D_801102B0].y;
        D_800FCD88_RELOAD->coords.z = D_800FCE24_BoardIntro[D_801102B0].z;
        func_8004CCD0(&D_800FCD88_RELOAD->coords, &D_800F32A0->coords, &D_800FCD88_RELOAD->unk_18);
    }
    for (i = 0; i < 4; i++) {
        func_80052DC8(i, D_800FD510_BoardIntro[GwPlayer[i].character]);
        func_80021B14(*GwPlayer[i].player_obj->unk_3C->unk_40, GwPlayer[i].character, 0);
        GwPlayer[i].player_obj->coords.x = D_800FCE24_BoardIntro[D_801102B0].x;
        GwPlayer[i].player_obj->coords.y = D_800FCE24_BoardIntro[D_801102B0].y;
        GwPlayer[i].player_obj->coords.z = D_800FCE24_BoardIntro[D_801102B0].z;
        GwPlayer[i].flags |= 2;
        func_8004CCD0(&GwPlayer[i].player_obj->coords, &D_800F32A0->coords, &GwPlayer[i].player_obj->unk_18);
        MBMotionSet(GwPlayer[i].player_obj, 0, 0);
        MBModelDispOff(GwPlayer[i].player_obj);
        func_80025EB4(*GwPlayer[i].player_obj->unk_3C->unk_40, 2, 1);
    }
    if (D_801102B0 == 8) {
        obj = omAddObj(0x1000, 0, 0, -1, func_800F7858_BoardIntro);
        obj->work[1] = 0;
        obj->trans.y = D_800FCE24_BoardIntro[D_801102B0].y;
        obj->scale.y = 80.0f;
        PlaySound(0x42);
        HuPrcSleep(5);
    }
    for (i = 0; i < 4; i++) {
        obj = omAddObj(0x1000, 0, 0, -1, func_800F7988_BoardIntro);
        obj->work[0] = i;
        obj->work[1] = 0;
        obj->trans.y = D_800FCE24_BoardIntro[D_801102B0].y;
        obj->scale.y = 80.0f;
        MBModelDispOn(GwPlayer[i].player_obj);
        PlaySound(0x42);
        HuPrcSleep(5);
    }
    PlaySound(0x41);
    for (i = 90; i >= 0; i -= 10) {
        model->yScale = sinf(i * (M_PI / 180));
        HuPrcVSleep();
    }
    MBModelKill(model);
    HuPrcSleep(20);
    for (i = 0; i < 4; i++) {
        func_800503B0(i, 1);
        HuPrcSleep(5);
    }
    for (i = 0; i < 4; i++) {
        func_8004F4D4(GwPlayer[i].player_obj, 2, 2);
    }
}
void func_800F8090_BoardIntro(void) {
    s32 i;
    s32 j;
    s32 win;

    for (i = 0; i < 4; i++) {
        func_8004E3E0(i, &D_800FD04C_BoardIntro[D_801102B0][i], 20, NULL);
    }
    for (j = 0; j < 20; j++) {
        for (i = 0; i < 4; i++) {
            func_8004CCD0(&GwPlayer[i].player_obj->coords, &D_800FCD70_BoardIntro->coords, &GwPlayer[i].player_obj->unk_18);
        }
        HuPrcVSleep();
    }
    for (i = 0; i < 4; i++) {
        func_8004F4D4(GwPlayer[i].player_obj, 2, 2);
    }
    win = CreateTextWindow(30, 42, D_800FD608_BoardIntro[D_801102B0], D_800FD610_BoardIntro[D_801102B0]);
    LoadStringIntoWindow(win, (void*)(s32)D_800FD3AC_BoardIntro[D_801102B0], -1, -1);
    func_8006E070(win, 0);
    ShowTextWindow(win);
    PlaySound(0x432);
    WaitForTextConfirmation_s32(win);
    if (D_801102B0 == 7) {
        HideTextWindow(win);
        if ((D_800FCDB4_BoardIntro = omAddPrcObj(func_800FC460_BoardIntro, 0x300, 0x2000, 0)) != NULL) {
            do {
                HuPrcVSleep();
            } while (D_800FCDB4_BoardIntro != NULL);
        }
        win = CreateTextWindow(30, 42, D_800FD608_BoardIntro[D_801102B0], D_800FD610_BoardIntro[D_801102B0]);
        LoadStringIntoWindow(win, (void*)0x243, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        WaitForTextConfirmation_s32(win);
        func_8004EE14(0, &D_800FCD88_BoardIntro[0]->coords, 10, D_800FCD70_BoardIntro);
        LoadStringIntoWindow(win, (void*)0x244, -1, -1);
        func_8006E070(win, 0);
        WaitForTextConfirmation_s32(win);
        func_800601D4(90);
    }
    HideTextWindow(win);
}
void func_800F8334_BoardIntro(void) {
    s32 timers[4];
    u8 state[4];
    u8 count[4];
    u8 order[4];
    s32 delay[4] = { 20, 30, 25, 20 };
    s32 i;
    s32 j;
    s32 win;
    s32 sound;

    for (i = 0; i < 4; i++) {
        func_8004E3E0(i, &D_800FD1FC_BoardIntro[D_801102B0][i], delay[i], NULL);
        func_8004EE14(i, D_800F32A0, delay[i], NULL);
        func_8004F4D4(GwPlayer[i].player_obj, 3, 2);
        if (D_801102B0 == 8 && ((i == 0) | (i == 3))) {
            func_80025EB4(*GwPlayer[i].player_obj->unk_3C->unk_40, 0, 6);
            D_800F2B7C[*GwPlayer[i].player_obj->unk_3C->unk_40].unk_4C = 0.5f;
        }
    }
    for (i = 0; i < 31; i++) {
        for (j = 0; j < 4; j++) {
            if (delay[j] == i) {
                if (D_801102B0 == 8 && ((j == 0) | (j == 3))) {
                    func_80025EB4(*GwPlayer[j].player_obj->unk_3C->unk_40, 4, 0);
                    D_800F2B7C[*GwPlayer[j].player_obj->unk_3C->unk_40].unk_4C = 1.0f;
                }
                func_8004F4D4(GwPlayer[j].player_obj, 2, 2);
            }
        }
        HuPrcVSleep();
    }
    HuPrcSleep(10);
    D_800FCDB0_BoardIntro = 1;
    func_8003FCD4();
    func_8003FC94();
    for (i = 0; i < 4; i++) {
        func_80040780(i);
        func_8003FD68(i);
    }
    func_8004157C();
    HuPrcSleep(20);
    if (D_801102B0 == 8) {
        return;
    }
    if (D_801102B0 == 7) {
        win = CreateTextWindow(0x4C, 30, 16, 2);
        LoadStringIntoWindow(win, (void*)0x256, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        sound = 0xF2;
    } else {
        win = CreateTextWindow(0x46, 30, 16, 2);
        LoadStringIntoWindow(win, (void*)0x248, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        sound = 0x437;
    }
    PlaySound(sound);
    while (func_8006FCC0(win) != 0) {
        HuPrcVSleep();
    }
    for (i = 0; i < 4; i++) {
        state[i] = 1;
        count[i] = 0;
        timers[i] = (u8)(rand8() % 30) + 5;
    }
    while (1) {
        for (i = 0; i < 4; i++) {
            timers[i]--;
            if (state[i] == 1) {
                if (GwPlayer[i].flags & 1) {
                    if (timers[i] <= 0) {
                        goto press;
                    }
                } else if (ContBtnTrg[GwPlayer[i].port] & 0x8000) {
                press:
                    state[i] = 2;
                    MBMotionSet(GwPlayer[i].player_obj, 5, 0);
                    func_8004F40C(GwPlayer[i].player_obj, 2, 2);
                }
            } else if (state[i] == 2) {
                count[i]++;
                if (count[i] == 5) {
                    func_800413B0(i);
                    state[i] = 0;
                }
            }
        }
        for (i = 0; i < 4; i++) {
            if (state[i] != 0) {
                break;
            }
        }
        if (i == 4) {
            break;
        }
        HuPrcVSleep();
    }
    HuPrcSleep(20);
    HideTextWindow(win);
    HuPrcSleep(5);
    for (i = 0; i < 4; i++) {
        state[i] = func_800415E8(i);
        order[i] = i;
    }
    for (i = 0; i < 4; i++) {
        for (j = i; j < 4; j++) {
            if (state[i] < state[j]) {
                timers[0] = state[i];
                state[i] = state[j];
                state[j] = timers[0];
                timers[0] = order[i];
                order[i] = order[j];
                order[j] = timers[0];
            }
        }
    }
    for (i = 0; i < 4; i++) {
        GwPlayer[order[i]].player_index = i;
        func_80040590(i);
    }
    func_800F66E8_BoardIntro();
    func_800544E4();
    D_800FCDA8_BoardIntro = 1;
    for (i = 0; i < 4; i++) {
        HidePlayerHUDVisibility(i, 1);
    }
    HuPrcSleep(5);
    for (i = 0; i < 4; i++) {
        if (i == 0) {
            win = CreateTextWindow(30, 70, 14, 2);
        } else {
            win = CreateTextWindow(30, 70, 8, 1);
        }
        func_8006DA5C(win, D_800C5218[GwPlayer[i].character], i);
        if (D_801102B0 == 7) {
            LoadStringIntoWindow(win, (void*)(s32)(i + 0x257), -1, -1);
        } else {
            LoadStringIntoWindow(win, (void*)(s32)(i + 0x249), -1, -1);
        }
        func_8006E070(win, 0);
        ShowTextWindow(win);
        PlaySound(D_801102B0 == 7 ? 0xF2 : 0x437);
        WaitForTextConfirmation_s32(win);
        HideTextWindow(win);
        func_8004F4D4(GwPlayer[i].player_obj, 6, 0);
        func_8004F40C(GwPlayer[i].player_obj, 2, 2);
        func_80060468(0x451, GwPlayer[i].character);
        func_800405DC(order[i]);
        func_80054868(i + 10);
        while (func_80054FA8() != 0) {
            HuPrcVSleep();
        }
        func_800503B0(i, 4);
        HuPrcSleep(20);
    }
    if (D_801102B0 == 7) {
        win = CreateTextWindow(30, 70, 18, 2);
        LoadStringIntoWindow(win, (void*)0x25B, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        sound = 0xF2;
    } else {
        win = CreateTextWindow(30, 70, 17, 3);
        LoadStringIntoWindow(win, (void*)0x24D, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        sound = 0x432;
    }
    PlaySound(sound);
    WaitForTextConfirmation_s32(win);
    HideTextWindow(win);
    for (i = 0; i < 4; i++) {
        if (i == 0) {
            func_80055960(0, 10);
        } else {
            func_80055810(i, 10, 0);
        }
        func_8004F4D4(GwPlayer[i].player_obj, 7, 0);
        func_8004F40C(GwPlayer[i].player_obj, 2, 2);
    }
    HuPrcSleep(30);
    if (D_801102B0 == 7) {
        win = CreateTextWindow(30, 70, 20, 4);
        LoadStringIntoWindow(win, (void*)0x25C, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        sound = 0xF2;
    } else {
        win = CreateTextWindow(30, 70, 12, 3);
        LoadStringIntoWindow(win, (void*)0x24E, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        sound = 0x432;
    }
    PlaySound(sound);
    WaitForTextConfirmation_s32(win);
    HideTextWindow(win);
    func_80041370();
    D_800FCDB0_BoardIntro = 0;
}
void func_800F8DC8_BoardIntro(void) {
    if (D_801102B0 == 8) {
        func_80023448(1);
        func_800234B8(0, 0x78, 0x78, 0x78);
        func_800234B8(1, 0x40, 0x40, 0x60);
        func_80023504(1, -100.0f, 100.0f, 300.0f);
    }
    if (D_801102B0 != 8) {
        func_800F7538_BoardIntro();
    }
    if (D_800FD618_BoardIntro[D_801102B0] != NULL) {
        D_800FD618_BoardIntro[D_801102B0]();
    }
    func_800F7B5C_BoardIntro();
    func_80060128(D_801102B0 == 8 ? 0x2A : 0x11);
    D_800FD63C_BoardIntro[D_801102B0]();
    if (D_801102B0 != 8) {
        func_800F8090_BoardIntro();
    }
    if (D_801102B0 == 7) {
        func_800FBBB8_BoardIntro();
    }
    func_800F8334_BoardIntro();
    if (D_801102B0 == 8) {
        func_800FC768_BoardIntro();
    }
    D_800F5144 = 1;
    while (1) {
        HuPrcVSleep();
    }
}
void func_800F8F38_BoardIntro(omObjData* obj) {
    s32 i;

    if (func_80072718() == 0) {
        func_800F9298_BoardIntro();
        func_800F9098_BoardIntro();
        func_80070ED4();
        if (D_800FCDA8_BoardIntro != 0) {
            func_80054654();
        }
        if (D_800FCDAC_BoardIntro != 0) {
            func_80077044(&D_800FDA50_BoardIntro);
        }
        for (i = 0; i < 16; i++) {
            if (D_800FCD30_BoardIntro[i] != NULL) {
                omDelObj(D_800FCD30_BoardIntro[i]);
            }
        }
        omOvlReturnEx(1);
    }
}
void func_800F8FEC_BoardIntro(omObjData* obj) {
    if (D_800F5144 != 0) {
        if (D_801102B0 != 8) {
            func_800726AC(2, 20);
            func_800601D4(30);
        } else {
            func_80072724(0xFF, 0xFF, 0xFF);
            func_800726AC(2, 20);
        }
        obj->func_ptr = func_800F8F38_BoardIntro;
    }
}
void func_800F906C_BoardIntro(void) {
    MBModelInit();
    func_80053020();
    func_8004F2AC();
}
void func_800F9098_BoardIntro(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_80052FD4(i);
    }
    func_8004F1D0();
    if (D_800FCD70_BoardIntro != NULL) {
        MBModelKill(D_800FCD70_BoardIntro);
    }
    if (D_800FCD74_BoardIntro != -1) {
        func_8002456C(D_800FCD76_BoardIntro);
    }
    for (i = 0; i < 4; i++) {
        if (BI_SPRITE(i) != -1) {
            func_8002456C((s16)BI_SPRITE(i));
            BI_SPRITE(i) = -1;
        }
        if (BI_MODEL(i) != NULL) {
            MBModelKill(BI_MODEL(i));
            BI_MODEL(i) = NULL;
        }
        if (D_800FCD98_BoardIntro[i] != NULL) {
            omDelObj(D_800FCD98_BoardIntro[i]);
            D_800FCD98_BoardIntro[i] = NULL;
        }
    }
    if (D_800FCDB0_BoardIntro != 0) {
        func_80041370();
    }
    if (D_800FCDB4_BoardIntro != NULL) {
        EndProcess(D_800FCDB4_BoardIntro);
    }
    func_8004F2EC();
}
void func_800F9200_BoardIntro(void) {
    func_800178A0(1);
    func_80017660(0, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    LoadBackgroundData(FE2310_ROM_START);
}
void func_800F9298_BoardIntro(void) {
    func_8004A140();
    func_80049F0C();
}
