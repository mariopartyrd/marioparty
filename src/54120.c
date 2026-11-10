#include "common.h"
#include "engine/process.h"

extern s8 D_800F384E;


#define ABS_F(x) (((x) > 0.0f) ? (x) : 0.0f - (x))


typedef struct unkStruct4 {
    /* 0x00 */ s8 unk_00;
    /* 0x01 */ u8 unk_01[2];
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ void* unk2C;
    /* 0x30 */ s16 unk_30;
    /* 0x32 */ s16 unk_32[2];
    /* 0x36 */ s16 unk_36;
    /* 0x38 */ s16 unk_38;
    /* 0x3A */ s16 unk_3A;
    /* 0x3C */ s16 unk_3C[2];
} unkStruct4;

typedef struct unkStruct3 {
/* 0x00 */ s16 unk_00;
/* 0x02 */ char unk_02[0x52];
/* 0x54 */ unkCommonStruct0 unk_54;
} unkStruct3;
s32 D_800C54D0 = -1;
s32 D_800C54D4 = -1;
/* func_80054868 (asm) addresses entries through split labels (undefined_syms.txt). */
s16 D_800C54D8[36][2] = {
    { 24, 16 }, { 200, 16 }, { 24, 192 }, { 200, 192 }, { -192, 16 }, { 416, 16 }, { -192, 192 }, { 416, 192 },
    { 60, 76 }, { 164, 76 }, { 60, 132 }, { 164, 132 }, { 112, 118 }, { 416, 16 }, { -192, 192 }, { 416, 192 },
    { -192, 16 }, { 112, 118 }, { -192, 192 }, { 416, 192 }, { -192, 16 }, { 416, 16 }, { 112, 118 }, { 416, 192 },
    { -192, 16 }, { 416, 16 }, { -192, 192 }, { 112, 118 }, { 512, 24 }, { 512, 74 }, { 512, 124 }, { 512, 174 },
    { 200, 24 }, { 200, 74 }, { 200, 124 }, { 200, 174 }
};
s16 D_800C5568[4][2] = { { 40, 50 }, { 184, 50 }, { 40, 150 }, { 184, 150 } };
s16 D_800C5578[4][2] = { { 40, 92 }, { 184, 92 }, { 40, 184 }, { 184, 184 } };
s16 D_800C5588[4][2] = { { 184, 92 }, { 184, 138 }, { 184, 184 }, { 40, 138 } };
s16 D_800C5598[4][2] = { { 40, 92 }, { 40, 184 }, { 184, 92 }, { 184, 184 } };
s16 D_800C55A8[4][2] = { { 40, 138 }, { 184, 92 }, { 184, 138 }, { 184, 184 } };
u8 D_800C55B8[29][3] = {
    { 0x80, 0x80, 0x80 }, { 0x00, 0x00, 0xFF }, { 0xFF, 0x00, 0x00 }, { 0xFF, 0xFF, 0x00 }, { 0x00, 0xFF, 0x00 }, { 0x40, 0xC0, 0x00 }, { 0x80, 0x80, 0x00 }, { 0xC0, 0x40, 0x00 },
    { 0xFF, 0x00, 0x00 }, { 0xFF, 0x00, 0x00 }, { 0xFF, 0x00, 0x00 }, { 0xC0, 0x40, 0x00 }, { 0x80, 0x80, 0x00 }, { 0x40, 0xC0, 0x00 }, { 0x00, 0xFF, 0x00 }, { 0x00, 0xFF, 0x00 },
    { 0x00, 0xFF, 0x00 }, { 0x00, 0xC0, 0x40 }, { 0x00, 0x80, 0x80 }, { 0x00, 0x40, 0xC0 }, { 0x00, 0x00, 0xFF }, { 0x00, 0x00, 0xFF }, { 0x00, 0x00, 0xFF }, { 0x00, 0x40, 0xC0 },
    { 0x00, 0x80, 0x80 }, { 0x00, 0xC0, 0x40 }, { 0x00, 0xFF, 0x00 }, { 0x00, 0xFF, 0x00 }, { 0x00, 0xFF, 0x00 }
};
s16 D_800C5610[11][2] = { { 0, 0 }, { -26, 0 }, { -4, -16 }, { -4, 16 }, { 11, -8 }, { 21, -8 }, { 31, -8 }, { 11, 9 }, { 21, 9 }, { -26, 12 }, { 36, 8 } };
u8 D_800C563C[] = { 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x0C, 0x10, 0x14, 0x18, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x1C, 0x1C, 0x1C, 0x1C, 0x00, 0x00 };
f32 D_800C5654[] = { 1.0f, 1.0f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f };
s32 D_800C5680[] = { 0xA0037, 0xA0038, 0xA0039, 0xA003A, 0xA003B, 0xA003C };
s16 (*D_800C5698[])[2] = { D_800C5578, D_800C55A8, D_800C5598, D_800C5588, D_800C5578, D_800C5568 };
s32 D_800C56B0[] = { 0xA0183, 0xA0184, 0xA0185, 0xA0186, 0xA0187, 0xA0188 };

extern unkStruct4 D_800D83A8[4];
extern omObjData* D_800D84D0[];
extern Process* D_800D83A0;
extern s16 D_800D84A8;
extern s16 D_800D84AA;
extern s16 D_800F3750;
extern s16 D_800F329A;
extern s16 D_800D85D4;
extern s16 D_800D8654;
#define D_800D85EC_unk_00 (D_800D85EC.unk_00)
#define D_800D85EC_unk_54 (D_800D85EC.unk_54)
extern s16 D_800D84E4;
extern s16 D_800D855C;
extern unkStruct3 D_800D85EC;
extern unkCommonStruct0 D_800D85D8[];
extern unkCommonStruct0 D_800D8640[];
extern s16 D_800D85D6;
extern Process* D_800D86A8;
extern s16 D_800D84E0;
extern s16 D_800D84E2;
extern s16 D_800D84E4;
extern s16 D_800D84E6;
extern s16 D_800D84E8;
extern s16 D_800D84EA;
extern unkCommonStruct0 D_800D84F0[];
extern Process* D_800D8558;
extern s16 D_800D8504;
extern s16 D_800D855C;
extern s16 D_800D855E;
extern s16 D_800D8560;
extern s16 D_800D8562;
extern unkCommonStruct0 D_800D8568[];
extern s16 D_800D857C;
extern Process* D_800D85D0;
void func_800543D8(s32);
void func_8005456C(s32);
extern void AdjustPlayerCoins(s32, s32);
void func_8005528C(omObjData* arg0);
void func_80053A1C(void);
void func_80054758(s32, s16, s16);
void func_80053520(s32);
extern f32 D_800D84AC;
extern f32 D_800D84B0[2];
extern f32 D_800D84B8[2];
extern f32 D_800D84C0[2];
extern s16 D_800D84C8;
extern s32 D_800ECE10;
void func_80055810(s32 arg0, s32 arg1, s32);
void func_80055228(void);
void func_80067284(s16, s16, f32);

void func_80053520(s32 arg0) {
    u8 digits[3];
    s16 cur[2];
    unkStruct4* p = &D_800D83A8[arg0];
    s32 n;
    s32 i;

    func_800672DC(p->unk_06, 1, p->unk_04, 0);
    func_800672B0(p->unk_06, 1, 1);
    digits[0] = GwPlayer[arg0].coins / 100;
    digits[1] = (s16)(GwPlayer[arg0].coins / 10) % 10;
    digits[2] = GwPlayer[arg0].coins % 10;
    if (digits[0] != 0 || digits[1] != 0) {
        n = (digits[0] != 0) ? 3 : 2;
    } else {
        n = 1;
    }
    if (n == 1) {
        func_800674BC(p->unk_06, 6, 0x8000);
        digits[1] = digits[2];
    } else {
        func_80067480(p->unk_06, 6, 0x8000);
    }
    if (digits[0] == 0) {
        digits[0] = 10;
    }
    for (i = 0; i < 3; i++) {
        func_800672DC(p->unk_06, i + 4, digits[i], 0);
        func_800672B0(p->unk_06, i + 4, 1);
    }
    if (GwPlayer[arg0].stars >= 100) {
        func_800672DC(p->unk_06, 7, 9, 0);
        func_800672DC(p->unk_06, 8, 9, 0);
    } else {
        if (GwPlayer[arg0].stars >= 10) {
            func_800672DC(p->unk_06, 7, GwPlayer[arg0].stars / 10, 0);
        } else {
            func_800672DC(p->unk_06, 7, 10, 0);
        }
        func_800672DC(p->unk_06, 8, GwPlayer[arg0].stars % 10, 0);
    }
    func_800672B0(p->unk_06, 7, 1);
    func_800672B0(p->unk_06, 8, 1);
    cur[0] = GwPlayer[arg0].coins;
    cur[1] = GwPlayer[arg0].stars;
    for (i = 0; i < 2; i++) {
        if ((i != 0 && p->unk_3C[i] != cur[i]) || (i == 0 && D_800D84D0[arg0] != NULL)) {
            if (p->unk_01[i] == 0) {
                func_80067284(p->unk_06, i + 2, 1.0f);
                p->unk_01[i] = 15;
            }
        }
        if (p->unk_01[i] != 0) {
            p->unk_01[i]--;
            if (p->unk_01[i] == 0 && (i != 0 || D_800D84D0[arg0] == NULL)) {
                func_800672DC(p->unk_06, i + 2, 0, 0);
                func_80067284(p->unk_06, i + 2, 0.0f);
                func_800672B0(p->unk_06, i + 2, 1);
            }
        }
        p->unk_3C[i] = cur[i];
    }
    if (p->unk_00 != -1) {
        func_800672DC(p->unk_06, 10, p->unk_00, 0);
    } else {
        func_800672DC(p->unk_06, 10, func_8004FEBC(arg0), 0);
    }
    func_800672B0(p->unk_06, 10, 1);
    if (_CheckFlag(0x2C) != 0) {
        func_800674BC(p->unk_06, 7, 0x8000);
        func_800674BC(p->unk_06, 8, 0x8000);
        func_800674BC(p->unk_06, 3, 0x8000);
    }
}
void func_80053A1C(void) {
    unkStruct4* p;
    s32 i;
    s32 j;

    while (1) {
        if (D_800F384E == 0) {
            for (i = 0; i < 4; i++) {
                if (D_800C54D0 != -1 && D_800C54D4 != -1 && i != D_800C54D0 && i != D_800C54D4) {
                    continue;
                }
                p = &D_800D83A8[i];
                if (p->unk_05 & 1) {
                    for (j = 0; j < 11; j++) {
                        func_800674BC(p->unk_06, j, 0x8000);
                    }
                    continue;
                }
                for (j = 0; j < 11; j++) {
                    func_80067480(p->unk_06, j, 0x8000);
                }
                if ((GwPlayer[i].flags & 1) && !(p->unk_05 & 1)) {
                    func_80067480(p->unk_06, 9, 0x8000);
                } else {
                    func_800674BC(p->unk_06, 9, 0x8000);
                }
                func_80053520(i);
                if (p->unk_0A > 0) {
                    p->unk_0A--;
                    p->unk_0C += p->unk_1C;
                    p->unk_10 += p->unk_20;
                    p->unk_1C += p->unk_24;
                    p->unk_20 += p->unk_28;
                } else if (p->unk_0A == -1) {
                    p->unk_0A = -2;
                } else if (p->unk_0A != -2) {
                    p->unk_0C = p->unk_14;
                    p->unk_10 = p->unk_18;
                    p->unk_0A = -1;
                }
                func_80066DC4(p->unk_06, 0, (s32)(p->unk_0C + 0.5f) + 0x30, (s32)(p->unk_10 + 0.5f) + 0x10);
            }
            if (D_800D84A8 != -1) {
                D_800D84AC += 0.1f;
                if (D_800D84AC > 1.0f) {
                    D_800D84AC = 1.0f;
                }
                func_80067354(D_800D84A8, 0, D_800D84AC, D_800D84AC);
                if (D_800D84C8 > 0) {
                    D_800D84C8--;
                    D_800D84B0[0] += D_800D84B8[0];
                    D_800D84B0[1] += D_800D84B8[1];
                    D_800D84B8[0] += D_800D84C0[0];
                    D_800D84B8[1] += D_800D84C0[1];
                    func_80066DC4(D_800D84A8, 0, D_800D84B0[0], D_800D84B0[1]);
                }
            }
        }
        HuPrcVSleep();
    }
}
void func_80053D88(s32 arg0) {
    unkStruct4* temp_s2 = &D_800D83A8[arg0];
    s16 id = temp_s2->unk_06;
    void* file;

    file = DataRead(D_800C5680[GwPlayer[arg0].character]);
    temp_s2->unk_30 = func_800678A4(file);
    DataClose(file);
    func_80067208(id, 1, temp_s2->unk_30, 0);
    func_800672B0(id, 1, 1);
    func_80067384(id, 1, 0x4790);
    func_800674BC(id, 1, 0x1000);
    func_800672DC(id, 1, 0, 0);
    func_80066DC4(id, 1, D_800C5610[1][0], D_800C5610[1][1]);
    temp_s2->unk_04 = 0;
}
void func_80053E8C(s32 arg0) {
    s32 files[2] = { 0xA0013, 0xA0014 };
    unkStruct4* temp_s5 = &D_800D83A8[arg0];
    s16 id = temp_s5->unk_06;
    s32 i;
    void* file;

    for (i = 0; i < 2; i++) {
        file = DataRead(files[i]);
        temp_s5->unk_32[i] = func_800678A4(file);
        DataClose(file);
        func_80067208(id, i + 2, temp_s5->unk_32[i], 0);
        func_80067384(id, i + 2, 0x4790);
        func_800674BC(id, i + 2, 0x1000);
        func_80066DC4(id, i + 2, D_800C5610[i + 2][0], D_800C5610[i + 2][1]);
        func_80067354(id, i + 2, 0.5f, 0.5f);
        func_80067284(id, i + 2, 0.0f);
    }
}

void func_80053FEC(s32 arg0) {
    unkStruct4* temp_s4 = &D_800D83A8[arg0];
    void* file;
    s16 id;
    s32 i;

    file = DataRead(0xA0033);
    temp_s4->unk_36 = func_800678A4(file);
    id = temp_s4->unk_06;
    for (i = 0; i < 5; i++) {
        func_80067208(id, i + 4, temp_s4->unk_36, 0);
        func_800672B0(id, i + 4, 1);
        func_800672DC(id, i + 4, 10, 0);
        func_80067384(id, i + 4, 0x4790);
        func_800674BC(id, i + 4, 0x1000);
        func_80066DC4(id, i + 4, D_800C5610[i + 4][0], D_800C5610[i + 4][1]);
        func_800674F4(id, (s16)(i + 4), 0xFF, 0xFF, 0xFF);
    }
    DataClose(file);
}

void func_8005412C(s32 arg0) {
    unkStruct4* temp_s2 = &D_800D83A8[arg0];
    s16 id;
    void* file;

    id = temp_s2->unk_06 = func_80064EF4(11, 5);
    file = DataRead(0xA001F);
    temp_s2->unk_08 = func_800678A4(file);
    DataClose(file);
    func_80067208(id, 0, temp_s2->unk_08, 0);
    func_80067384(id, 0, 0x4790);
    func_800674BC(id, 0, 0x1000);
    func_80066DC4(id, 0, 0, 0);
}
void func_800541F0(s32 arg0) {
    unkStruct4* temp_s1 = &D_800D83A8[arg0];
    s16 id = temp_s1->unk_06;
    void* file;

    file = DataRead(0xA0034);
    temp_s1->unk_38 = func_800678A4(file);
    DataClose(file);
    func_80067208(id, 10, temp_s1->unk_38, 0);
    func_800672B0(id, 10, 1);
    func_800672DC(id, 10, 0, 0);
    func_80067384(id, 10, 0x4790);
    func_800674BC(id, 10, 0x1000);
    func_80066DC4(id, 10, D_800C5610[10][0], D_800C5610[10][1]);
}
void func_800542D0(s32 arg0) {
    unkStruct4* temp_s1 = &D_800D83A8[arg0];
    s16 id = temp_s1->unk_06;
    void* file;

    file = DataRead(0xA0032);
    temp_s1->unk_3A = func_800678A4(file);
    DataClose(file);
    func_80067208(id, 9, temp_s1->unk_3A, 0);
    func_800672B0(id, 9, 1);
    func_80067384(id, 9, 0x4790);
    func_800674BC(id, 9, 0x1000);
    func_80066DC4(id, 9, D_800C5610[9][0], D_800C5610[9][1]);
    if (!(GwPlayer[arg0].flags & 1)) {
        func_800674BC(id, 9, 0x8000);
    }
}
void func_800543D8(s32 arg0) {
    unkStruct4* temp_s2 = &D_800D83A8[arg0];
    s32 i;

    for (i = 0; i < 2; i++) {
        temp_s2->unk_01[i] = 0;
    }
    temp_s2->unk_3C[0] = GwPlayer[arg0].coins;
    temp_s2->unk_3C[1] = GwPlayer[arg0].stars;
    temp_s2->unk_05 = 0;
    temp_s2->unk_00 = -1;
    func_8005412C(arg0);
    func_800546B4(arg0, 0);
    func_80054758(arg0, D_800C54D8[arg0][0], D_800C54D8[arg0][1]);
    func_80053D88(arg0);
    func_80053E8C(arg0);
    func_80053FEC(arg0);
    func_800541F0(arg0);
    func_800542D0(arg0);
    func_80053520(arg0);
    D_800D84D0[arg0] = NULL;
    temp_s2->unk2C = NULL;
}

void func_800544E4(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_800543D8(i);
    }
    D_800D83A0 = omAddPrcObj(func_80053A1C, 0, 0x2000, 0);
    omPrcSetStatBit(D_800D83A0, 0x80);
    D_800D84AA = -1;
    D_800D84A8 = -1;
    D_800C54D0 = -1;
    D_800C54D4 = -1;
}
void func_8005456C(s32 arg0) {
    unkStruct4* temp_s1 = &D_800D83A8[arg0];
    s32 i;

    func_80067704(temp_s1->unk_30);
    for (i = 0; i < 2; i++) {
        func_80067704(temp_s1->unk_32[i]);
    }
    func_80067704(temp_s1->unk_36);
    func_80067704(temp_s1->unk_38);
    if (temp_s1->unk_3A != -1) {
        func_80067704(temp_s1->unk_3A);
    }
    func_80064D38(temp_s1->unk_06);
    func_80067704(temp_s1->unk_08);
    if (temp_s1->unk2C != NULL) {
        omDelObj(temp_s1->unk2C);
        temp_s1->unk2C = NULL;
    }
    if (D_800D84D0[arg0] != NULL) {
        omDelObj(D_800D84D0[arg0]);
        D_800D84D0[arg0] = NULL;
    }
}
s32 func_80054654(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_8005456C(i);
    }
    HuPrcKill(D_800D83A0);
    func_80055228();
    D_800C54D0 = -1;
    D_800C54D4 = -1;
    return -1;
}
void func_800546B4(s32 arg0, s32 arg1) {
    func_800674F4(D_800D83A8[arg0].unk_06, 0, D_800C55B8[arg1][0], D_800C55B8[arg1][1], D_800C55B8[arg1][2]);
    D_800D83A8[arg0].unk_03 = arg1;
}
s32 func_80054730(s32 arg0) {
    return D_800D83A8[arg0].unk_03;
}
void func_80054744(s32 arg0, s8 arg1) {
    D_800D83A8[arg0].unk_00 = arg1;
}
void func_80054758(s32 arg0, s16 arg1, s16 arg2) {
    unkStruct4* temp_a0 = &D_800D83A8[arg0];

    temp_a0->unk_0C = temp_a0->unk_14 = arg1;
    temp_a0->unk_10 = temp_a0->unk_18 = arg2;
    temp_a0->unk_1C = temp_a0->unk_20 = 0.0f;
    temp_a0->unk_0A = -2;
    func_80066DC4(temp_a0->unk_06, 0, arg1 + 0x30, arg2 + 0x10);
}
void HidePlayerHUDVisibility(s32 arg0, s32 arg1) {
    func_80054758(arg0, D_800C54D8[arg1 * 4 + arg0][0], D_800C54D8[arg1 * 4 + arg0][1]);
}
void func_80054834(s32 arg0, s32 arg1) {
    func_80054758(arg0, D_800C54D8[arg1][0], D_800C54D8[arg1][1]);
}

// loop-invariant motion: retail hoists arg0 - 10, GCC here hoists the switch range check (masked 44)
#ifdef NON_MATCHING
s32 func_80054868(s32 arg0) {
    u8 order[5];
    u8 blue[5];
    u8 red[4];
    u8 nblue = 0;
    u8 nred = 0;
    u8 n;
    unkStruct4* p;
    s32 i;

    if (arg0 == 2) {
        n = 0;
        nblue = nred;
        for (i = 0; i < 4; i++) {
            switch (D_800D83A8[i].unk_03) {
                case 1:
                    blue[nblue++] = i;
                    break;
                case 2:
                    red[nred++] = i;
                    break;
                default:
                    n++;
                    break;
            }
        }
        if (n != 0) {
            for (i = 0; i < 5; i++) {
                blue[i] = i;
            }
            nblue = 5;
            nred = 0;
        }
        n = 0;
        for (i = 0; i < nblue; i++) {
            order[blue[i]] = n++;
        }
        for (i = 0; i < nred; i++) {
            order[red[i]] = n++;
        }
    }

    for (i = 0; i < 4; i++) {
        p = &D_800D83A8[i];
        if (arg0 >= 10 && arg0 < 14 && i != arg0 - 10) {
            continue;
        }
        if (arg0 >= 14 && arg0 < 18 && i != arg0 - 14) {
            continue;
        }
        if (arg0 >= 18 && arg0 < 22 && i != arg0 - 18) {
            continue;
        }
        if (arg0 == 22 && i != D_800C54D0) {
            continue;
        }
        if (arg0 == 23 && i != D_800C54D4) {
            continue;
        }
        if (arg0 == 24 && i != D_800C54D4) {
            continue;
        }
        switch (arg0) {
            case 0:
            case 10:
            case 11:
            case 12:
            case 13:
                func_80054758(i, D_800C54D8[i + 4][0], D_800C54D8[i + 4][1]);
                break;
            case 22:
                func_80054758(D_800C54D0, D_800C54D8[4][0], D_800C54D8[4][1]);
                break;
            case 23:
                func_80054758(D_800C54D4, D_800C54D8[7][0], D_800C54D8[7][1]);
                break;
            case 24:
                func_80054758(D_800C54D4, D_800C54D8[5][0], D_800C54D8[5][1]);
                break;
        }
        p->unk_0A = 19;
        switch (arg0) {
            case 6:
            case 7:
            case 8:
            case 9:
                p->unk_0A = 15;
            case 0:
            case 1:
            case 3:
            case 4:
            case 10:
            case 11:
            case 12:
            case 13:
                p->unk_14 = D_800C54D8[D_800C563C[arg0] + i][0];
                p->unk_18 = D_800C54D8[D_800C563C[arg0] + i][1];
                break;
            case 2:
                p->unk_14 = D_800C5698[nblue][order[i]][0];
                p->unk_18 = D_800C5698[nblue][order[i]][1];
                p->unk_0A = 9;
                break;
            case 5:
                p->unk_14 = p->unk_0C;
                p->unk_18 = p->unk_10 + 480.0f;
                p->unk_0A = 19;
                break;
            case 14:
            case 15:
            case 16:
            case 17:
            case 18:
            case 19:
            case 20:
            case 21:
                p->unk_14 = D_800C54D8[D_800C563C[arg0] + i][0];
                p->unk_18 = p->unk_10;
                break;
            case 22:
                p->unk_14 = D_800C54D8[0][0];
                p->unk_18 = D_800C54D8[0][1];
                break;
            case 23:
                p->unk_14 = D_800C54D8[3][0];
                p->unk_18 = D_800C54D8[3][1];
                break;
            case 24:
                p->unk_14 = D_800C54D8[1][0];
                p->unk_18 = D_800C54D8[1][1];
                break;
        }
        p->unk_1C = p->unk_24 = (2.0f * (p->unk_14 - p->unk_0C)) / ((p->unk_0A + 1) * (p->unk_0A + 1));
        p->unk_20 = p->unk_28 = (2.0f * (p->unk_18 - p->unk_10)) / ((p->unk_0A + 1) * (p->unk_0A + 1));
        if (arg0 == 5) {
            D_800D84B8[0] = D_800D84C0[0] = p->unk_24;
            D_800D84B8[1] = D_800D84C0[1] = p->unk_28;
            D_800D84C8 = p->unk_0A;
        }
    }

    if ((arg0 == 2) & (nblue != 5)) {
        if (nblue == 4 || nblue == 0) {
            for (i = 0; i < 4; i++) {
                GwPlayer[i].group = i;
            }
        } else if (nblue == 3) {
            for (i = 0; i < nblue; i++) {
                GwPlayer[blue[i]].group = 1;
            }
            for (i = 0; i < nred; i++) {
                GwPlayer[red[i]].group = 0;
            }
        } else {
            for (i = 0; i < nblue; i++) {
                GwPlayer[blue[i]].group = 0;
            }
            for (i = 0; i < nred; i++) {
                GwPlayer[red[i]].group = 1;
            }
        }
    }
    if (arg0 == 6 || arg0 == 7 || arg0 == 8 || arg0 == 9) {
        for (i = 0; i < 4; i++) {
            if (i == arg0 - 6) {
                GwPlayer[i].group = 0;
            } else {
                GwPlayer[i].group = 1;
            }
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/54120", func_80054868);
#endif
s32 func_80054FA8(void) {
    s32 i;
    s32 ret = 0;

    for (i = 0; i < 4; i++) {
        if (D_800D83A8[i].unk_0A != -2) {
            ret = 1;
        }
    }

    return ret;
}

s32 func_80054FE4(void) {
    u8 blue[4];
    u8 red[4];
    u8 other = 0;
    u8 nred = 0;
    u8 nblue = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
        switch (D_800D83A8[i].unk_03) {
            case 1:
                blue[nblue++] = i;
                break;
            case 2:
                red[nred++] = i;
                break;
            default:
                other++;
                break;
        }
    }
    if (other != 0) {
        return -1;
    }
    if (nblue == 0 || nblue == 4) {
        return 0;
    }
    if (nblue == 1) {
        D_800ECE10 = blue[0];
        return 1;
    }
    if (nblue == 3) {
        D_800ECE10 = red[0];
        return 1;
    }
    return 2;
}
void func_800550C4(void) {
    void* file;

    if (D_800D84A8 == -1) {
        D_800D84A8 = func_80064EF4(1, 5);
        if (func_80054FE4() == -1) {
            file = DataRead(0xA0022);
            D_800D84B0[1] = 120.0f;
        } else {
            file = DataRead(0xA0021);
            D_800D84B0[1] = 158.0f;
        }
        D_800D84AA = func_800678A4(file);
        DataClose(file);
        func_80067208(D_800D84A8, 0, D_800D84AA, 0);
        func_80067384(D_800D84A8, 0, 0x4780);
        func_800674BC(D_800D84A8, 0, 0x1000);
        func_80066DC4(D_800D84A8, 0, 0xA0, D_800D84B0[1]);
        func_80067354(D_800D84A8, 0, 0.0f, 0.0f);
        D_800D84AC = 0.0f;
        D_800D84B0[0] = 160.0f;
        D_800D84B8[0] = D_800D84B8[1] = 0.0f;
        D_800D84C8 = 0;
    }
}
void func_80055228(void) {
    if (D_800D84A8 != -1) {
        func_80064D38(D_800D84A8);
        D_800D84A8 = -1;
    }
    if (D_800D84AA != -1) {
        func_80067704(D_800D84AA);
        D_800D84AA = -1;
    }
}
void func_8005528C(omObjData* arg0) {
    unkStruct4* temp_s3 = &D_800D83A8[arg0->work[0]];
    s32 i;

    for (i = 0; i < 11; i++) {
        func_80067354(temp_s3->unk_06, i,
                      ABS_F(sinf(arg0->rot.x * (M_PI / 180.0)) * 0.15f) + D_800C5654[i],
                      ABS_F(sinf(arg0->rot.x * (M_PI / 180.0)) * 0.15f) + D_800C5654[i]);
    }
    arg0->rot.x += 10.0f;
    if (arg0->rot.x >= 360.0f) {
        arg0->rot.x -= 360.0f;
    }
}
void func_8005546C(s32 arg0) {
    omObjData* temp_v0;
    unkStruct4* temp_s0;
    s32 i;
    s32 j;

    temp_s0 = &D_800D83A8[arg0];
    if (temp_s0->unk2C == NULL) {
        temp_v0 = omAddObj(-0x8000, 0, 0, -1, &func_8005528C);
        temp_s0->unk2C = temp_v0;
        temp_v0->rot.x = 0.0f;
        temp_v0->work[0] = arg0;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 0x0B; j++){
                func_80067354(D_800D83A8[i].unk_06, j, D_800C5654[j], D_800C5654[j]);
            }
            
        }
    }
}

void func_80055544(s32 arg0) {
    unkStruct4* temp_s1;
    s32 i;

    temp_s1 = &D_800D83A8[arg0];
    
    if (temp_s1->unk2C != NULL) {
        omDelObj(temp_s1->unk2C);
        temp_s1->unk2C = NULL;
        for (i = 0; i < 0xB; i++) {
            func_80067354(temp_s1->unk_06, i, D_800C5654[i], D_800C5654[i]);
        }
    }
}

void func_800555D0(omObjData* arg0) {
    u32 var_s1 = 0;

    while (arg0->scale.y <= 0.0f) {
        if (arg0->trans.x > 0.0f) {
            AdjustPlayerCoins(arg0->work[0], 1);
            if (((arg0->work[3] != 0) & (var_s1 == 0)) && (arg0->scale.z >= 3.0f)) {
                PlaySound(0x43);
                var_s1 = 1;
                arg0->scale.z -= 3.0f;
            }
            
            arg0->trans.x -= 1.0f;

        } else {
            AdjustPlayerCoins(arg0->work[0], -1);
            arg0->trans.x += 1.0f;
            
            if (arg0->work[3] != 0) {
                if ((var_s1 == 0) && (arg0->scale.z >= 3.0f)) {
                    PlaySound(0x57);
                    var_s1 = 1;
                    arg0->scale.z -= 3.0f;
                }
                if (arg0->trans.x == 0.0f || GwPlayer[arg0->work[0]].coins == 0) {
                    PlaySound(0x58);
                }
            }                
        }
        
        if (arg0->trans.x == 0.0f || GwPlayer[arg0->work[0]].coins == 0) {
            D_800D84D0[arg0->work[0]] = 0;
            omDelObj(arg0);
            return;
        }
        
        arg0->scale.y += arg0->scale.x;
    }         
    arg0->scale.y = arg0->scale.y - 1.0f;
    arg0->scale.z = arg0->scale.z + 2.0f;
}

void func_80055810(s32 arg0, s32 arg1, s32 arg2) {
    if (arg1 != 0) {
        if (D_800D84D0[arg0] != NULL) {
            AdjustPlayerCoins(arg0, arg1);
            return;
        }
        if (((GwPlayer[arg0].coins == 0) & (arg1 < 0)) == 0) {
            D_800D84D0[arg0] = omAddObj(-0x8000, 0, 0, -1, func_800555D0);
            D_800D84D0[arg0]->work[0] = arg0;
            D_800D84D0[arg0]->trans.x = arg1;
            D_800D84D0[arg0]->scale.x = 30.0f / ABS_F((f32)arg1);
            D_800D84D0[arg0]->scale.y = 0.0f;
            D_800D84D0[arg0]->scale.z = 3.0f;
            D_800D84D0[arg0]->work[3] = arg2;
        }
    }
}
void func_80055960(s32 arg0, s32 arg1) {
    func_80055810(arg0, arg1, 1);
}

s32 func_8005597C(s32 arg0) {
    if (D_800D84D0[arg0] != 0) {
        return 1;
    } else {
        return 0;
    }
}

void func_80055994(s32 arg0) {
    D_800D83A8[arg0].unk_04 = 0;
}

s32 func_800559A8(void) {
    if (D_800D83A8[0].unk_05 & 1) {
        return 0;
    } else {
        return 1;
    }
}

void func_800559BC(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_800D83A8[i].unk_05 |= 1;
    }
}

void func_800559F8(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_800D83A8[i].unk_05 &= ~1;
    }
}

void func_80055A34(s32 arg0) {
    D_800C54D4 = arg0;
}

void func_80055A40(s32 arg1) {
    s32 i;
    for (i = 0; i < MAX_PLAYERS; i++) {
        func_800543D8(i);
        func_80054758(i, D_800C54D8[i + 4][0], D_800C54D8[i + 4][1]);
        func_800546B4(i, GwPlayer[i].turn_status);
    }

    D_800D83A0 = omAddPrcObj(func_80053A1C, 0U, 0x2000, 0);
    omPrcSetStatBit(D_800D83A0, 0x80);
    D_800D84AA = -1;
    D_800D84A8 = -1;
}

void func_80055AFC(void) {
    func_8005456C(D_800C54D0);
    func_8005456C(D_800C54D4);
    HuPrcKill(D_800D83A0);
    func_80055228();
    D_800C54D0 = -1;
    D_800C54D4 = -1;
}

void func_80055B50(s32 arg0, s32 arg1) {
    D_800C54D0 = arg0;
    D_800C54D4 = arg1;
}

void func_80055B64(void) {
    func_80054868(0x16);
}

void func_80055B80(void) {
    func_80054868(0x17);
}

void func_80055B9C(void) {
    s32 i;

    while (1) {
        if ((D_800F329A == -1) || (D_800F3750 == -1)) {
            func_800674BC(D_800D85D4, 0, 0x8000);
            func_800674BC(D_800D85D4, 1, 0x8000);
            
            for (i = 0; i < 5; i++) {
                func_800674BC(D_800D85EC_unk_00, i + 1, 0x8000);
            }
            
            func_800674BC(D_800D8654, 1, 0x8000);
        } else {
            func_80067480(D_800D85D4, 0, 0x8000);
            func_80067480(D_800D85D4, 1, 0x8000);
            for (i = 0; i < 5; i++) {
                func_80067480(D_800D85EC_unk_00, i + 1, 0x8000);
            }
            func_80067480(D_800D8654, 1, 0x8000);
            func_800672B0(D_800D85D4, 0, 1);
            func_800672DC(D_800D85D4, 0, (u16) D_800F329A, 0);
            func_800672B0(D_800D85D4, 1, 1);
            func_800672DC(D_800D85D4, 1, (u16) D_800F3750, 0);
        }
        HuPrcVSleep();        
    }
}

void func_80055D28(void) {
    s32 lives;

    while (1) {
        lives = GwQuest.lifeNum;
        if (lives < 0) {
            lives = 0;
        }
        
        if (lives >= 100) {
            lives = 99;
        }
        
        func_800672B0(D_800D84E4, 0, 1);
        func_800672DC(D_800D84E4, 0, (lives / 10), 0);
        func_800672B0(D_800D84E4, 1, 1);
        func_800672DC(D_800D84E4, 1, (lives % 10), 0);
        HuPrcVSleep();      
    }
}

void func_80055E08(void) {
    s32 coins;

    while (1) {
        coins = GwQuest.coinNum;
        if (coins < 0) {
            coins = 0;
        }
        
        if (coins >= 100) {
            coins = 99;
        }
        
        func_800672B0(D_800D855C, 0, 1);
        func_800672DC(D_800D855C, 0, (coins / 10), 0);
        func_800672B0(D_800D855C, 1, 1);
        func_800672DC(D_800D855C, 1, (coins % 10), 0);
        HuPrcVSleep();      
    }
}

void func_80055EE8(void) {
    void* file;
    s32 i;

    GMesFontMesCreate(D_800D85D8, "WORLD", 0, -1, -1);
    func_80066DC4(D_800D85EC_unk_00, 0, 0xA0, 0x18);
    GMesFontMesCreate(&D_800D85EC_unk_54, "=", 0, -1, -1);
    func_80066DC4(D_800D85EC_unk_54.unk_14[0], 0, 0xA0, 0x28);
    file = DataRead(0x7C);
    D_800D85D6 = func_800678A4(file);
    DataClose(file);
    D_800D85D4 = func_80064EF4(2, 5);
    
    for (i = 0; i < 2; i++) {
        func_80067208(D_800D85D4, i, D_800D85D6, 0);
        func_800672B0(D_800D85D4, i, 1);
        func_80067384(D_800D85D4, i, 0xA);
        func_800674BC(D_800D85D4, i, 0x1000);
        if (i == 0) {
            func_80066DC4(D_800D85D4, 0, 0x90, 0x28);
        } else {
            func_80066DC4(D_800D85D4, i, 0x20, 0);
        }
    }
    
    D_800D86A8 = omAddPrcObj(&func_80055B9C, 0U, 0, 0);
    omPrcSetStatBit(D_800D86A8, 0x80);
}

void func_8005608C(void) {
    Process* process;
    void* file;
    s32 i;

    D_800D84E0 = func_80064EF4(1, 5);
    func_80066DC4(D_800D84E0, 0, 0x2A, 0x22);
    file = DataRead(D_800C56B0[GwQuest.charNo]);
    D_800D84E2 = func_800678A4(file);
    DataClose(file);
    func_80067208(D_800D84E0, 0, D_800D84E2, 0);
    func_800672B0(D_800D84E0, 0, 1);
    func_80067384(D_800D84E0, 0, 0x10);
    func_800674BC(D_800D84E0, 0, 0x1000);
    file = DataRead(0xA0163);
    D_800D84EA = func_800678A4(file);
    DataClose(file);
    D_800D84E8 = func_80064EF4(1, 5);
    func_80067208(D_800D84E8, 0, D_800D84EA, 0);
    func_800672B0(D_800D84E8, 0, 1);
    func_80067384(D_800D84E8, 0, 0x11);
    func_800674BC(D_800D84E8, 0, 0x1000);
    func_80067354(D_800D84E8, 0, 0.5f, 0.5f);
    func_80066DC4(D_800D84E8, 0, 0x2A, 0x22);
    GMesFontMesCreate(D_800D84F0, "X", 0, -1, -1);
    func_80066DC4(D_800D8504, 0, 0x44, 0x22);
    file = DataRead(0x7C);
    D_800D84E6 = func_800678A4(file);
    DataClose(file);
    D_800D84E4 = func_80064EF4(2, 5);
    
    for (i = 0; i < 2; i++) {
        func_80067208(D_800D84E4, i, D_800D84E6, 0);
        func_800672B0(D_800D84E4, i, 1);
        func_80067384(D_800D84E4, i, 0xA);
        func_800674BC(D_800D84E4, i, 0x1000);
        if (i == 0) {
            func_80066DC4(D_800D84E4, 0, 0x54, 0x22);
        } else {
            func_80066DC4(D_800D84E4, i, i * 16, 0);
        }
    }

    D_800D8558 = omAddPrcObj(&func_80055D28, 0, 0, 0);
    omPrcSetStatBit(D_800D8558, 0x80);
}

void func_80056380(void) {
    Process* process;
    void* file;
    s32 i;

    file = DataRead(0xA0013);
    D_800D8562 = func_800678A4(file);
    DataClose(file);
    D_800D8560 = func_80064EF4(1, 5);
    func_80067208(D_800D8560, 0, D_800D8562, 0);
    func_800672B0(D_800D8560, 0, 1);
    func_80067384(D_800D8560, 0, 0x11);
    func_800674BC(D_800D8560, 0, 0x1000);
    func_80066DC4(D_800D8560, 0, 0xE2, 0x22);
    func_80067284(D_800D8560, 0, 0.0f);
    GMesFontMesCreate(D_800D8568, "X", 0, -1, -1);
    func_80066DC4(D_800D857C, 0, 0xFC, 0x22);
    file = DataRead(0x7C);
    D_800D855E = func_800678A4(file);
    DataClose(file);
    D_800D855C = func_80064EF4(2, 5);
    
    for (i = 0; i < 2; i++) {
        func_80067208(D_800D855C, i, D_800D855E, 0);
        func_800672B0(D_800D855C, i, 1);
        func_80067384(D_800D855C, i, 0xA);
        func_800674BC(D_800D855C, i, 0x1000);
        if (i == 0) {
            func_80066DC4(D_800D855C, 0, 0x10C, 0x22);
        } else {
            func_80066DC4(D_800D855C, i, i * 16, 0);
        }
    }

    D_800D85D0 = omAddPrcObj(func_80055E08, 0, 0, 0);
    omPrcSetStatBit(D_800D85D0, 0x80);
}

void func_800565B4(void) {
    func_8005608C();
    func_80056380();
    func_80055EE8();
}

void func_800565E0(void) {
    func_80077044(D_800D85D8);
    func_80077044(D_800D8640);
    func_80067704(D_800D85D6);
    func_80064D38(D_800D85D4);
    EndProcess(D_800D86A8);
}

void func_80056630(void) {
    func_80067704(D_800D84E2);
    func_80064D38(D_800D84E0);
    func_80077044(D_800D84F0);
    func_80067704(D_800D84E6);
    func_80064D38(D_800D84E4);
    func_80067704(D_800D84EA);
    func_80064D38(D_800D84E8);
    EndProcess(D_800D8558);
}


void func_800566A4(void) {
    func_80077044(D_800D8568);
    func_80067704(D_800D855E);
    func_80064D38(D_800D855C);
    func_80067704(D_800D8562);
    func_80064D38(D_800D8560);
    EndProcess(D_800D85D0);
}

void func_80056700(void) {
    func_80056630();
    func_800566A4();
    func_800565E0();
}

// const char D_800CB2A4[] = "X";
const char pad_54120[] = "\0\0\0\0\0";
