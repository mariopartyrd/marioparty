#include "common.h"
#include "engine/process.h"
#include "engine/pad.h"
typedef struct unk43760 {
    s16 unk_00;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    s16 unk_0A;
} unk43760;

typedef struct unkUserData_00 {
/* 0x00 */ s32 unk_00;
/* 0x04 */ s32 unk_04;
/* 0x08 */ s32 unk_08;
/* 0x0C */ s32 unk_0C;
} unkUserData_00; //0x10 in size

extern u32 D_800F383C;
extern unk43760 D_800D6400[5];
extern omObjData* D_800D6450;
extern s16 D_800D645A;
extern s16 D_800D645C;
extern s16 D_800D645E;
extern s16 D_800D6460;
extern u16 D_800D6404;
extern s8 D_800D6459;
extern s8 D_800D6438[4][5];
extern s8 D_800D644C[4];
extern s8 D_800D6462[5];
extern s8 D_800D6467;

s32 func_80054730(s32);
s16 func_8005949C(s32);
void func_80047D48(void);
void func_80043544(void);
void func_8004367C(void);
void func_800437B8(void);
void func_800448F4(omObjData* obj);

typedef struct Rect43760 {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
    /* 0x04 */ s16 w;
    /* 0x06 */ s16 h;
} Rect43760;

/* Minigame lists by board/mode; their lengths are D_800C4E10 and D_800C4E54. */
u8 D_800C4CD0[47] = { 0x04, 0x05, 0x08, 0x0C, 0x0E, 0x0F, 0x14, 0x15, 0x17, 0x18, 0x19, 0x1B, 0x1D, 0x1F, 0x22, 0x23, 0x26, 0x27, 0x29, 0x2C, 0x2D, 0x2E, 0x2F, 0x38, 0x04, 0x05, 0x08, 0x0C, 0x0E, 0x0F, 0x14, 0x17, 0x18, 0x19, 0x1B, 0x1D, 0x1F, 0x22, 0x23, 0x26, 0x27, 0x29, 0x2C, 0x2D, 0x2E, 0x2F, 0x38 };
u8 D_800C4D00[27] = { 0x0A, 0x11, 0x12, 0x16, 0x20, 0x24, 0x33, 0x34, 0x35, 0x37, 0x0A, 0x11, 0x12, 0x16, 0x20, 0x24, 0x33, 0x34, 0x35, 0x0A, 0x11, 0x12, 0x20, 0x24, 0x33, 0x34, 0x35 };
u8 D_800C4D1C[9] = { 0x1E, 0x28, 0x2B, 0x30, 0x32, 0x1E, 0x28, 0x2B, 0x30 };
u8 D_800C4D28[19] = { 0x01, 0x03, 0x06, 0x0B, 0x0D, 0x10, 0x13, 0x1A, 0x21, 0x2A, 0x01, 0x06, 0x0B, 0x0D, 0x10, 0x13, 0x1A, 0x21, 0x2A };
u8 D_800C4D3C[] = { 5, 3, 3, 5 };
Rect43760 D_800C4D40[] = { { 60, -100, 200, 20 }, { 60, -80, 200, 20 }, { 60, -60, 200, 20 } };
Rect43760 D_800C4D58[] = { { 60, -120, 200, 20 }, { 60, -100, 200, 20 }, { 60, -80, 200, 20 }, { 60, -60, 200, 20 }, { 60, -40, 200, 20 } };
Rect43760 D_800C4D80[] = { { 60, 124, 200, 20 }, { 60, 144, 200, 20 }, { 60, 164, 200, 20 } };
Rect43760 D_800C4D98[] = { { 60, 104, 200, 20 }, { 60, 124, 200, 20 }, { 60, 144, 200, 20 }, { 60, 164, 200, 20 }, { 60, 184, 200, 20 } };
u8 D_800C4DC0[] = { 0x32, 0x1E, 0x1E, 0x32 };
u8 D_800C4DC4[] = { 0x72, 0x86, 0x86, 0x72 };
s8 D_800C4DC8[][2] = { { 1, 0 }, { 9, 15 }, { 11, 8 }, { 13, 0 } };
/* One byte per minigame id 1-60 (passed to func_8006E288); retail indexes it as D_800C4DCF[id]. */
u8 D_800C4DD0[] = {
    0x07, 0x07, 0x04, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x04,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x04, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x04, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x04, 0x07, 0x07, 0x07, 0x07, 0x07
};
u32 D_800C4E0C = 0;
u8 D_800C4E10[] = { 47, 27, 9, 19 };
u8 D_800C4E14[13] = { 0x01, 0x03, 0x06, 0x0B, 0x0D, 0x10, 0x13, 0x1A, 0x21, 0x2A, 0x1C, 0x25, 0x36 };
u8 D_800C4E24[5] = { 0x1E, 0x28, 0x2B, 0x30, 0x32 };
u8 D_800C4E2C[10] = { 0x0A, 0x11, 0x12, 0x16, 0x20, 0x24, 0x33, 0x34, 0x35, 0x37 };
u8 D_800C4E38[25] = { 0x04, 0x05, 0x08, 0x0C, 0x0E, 0x0F, 0x14, 0x15, 0x17, 0x18, 0x19, 0x1B, 0x1D, 0x1F, 0x22, 0x23, 0x27, 0x29, 0x2C, 0x2D, 0x2E, 0x2F, 0x38, 0x07, 0x09 };
u8 D_800C4E54[] = { 25, 10, 5, 13 };
extern u8 D_800C4DCF[]; /* undefined_syms.txt */

extern s32 D_800ECE10;
void func_80042BAC(omObjData* obj);
extern s8 D_800D6454[];
s32 func_80047D38(void);
void func_800550C4(void);
void func_80055228(void);

void func_80042B60(void) {
    if (D_800F383C >= (D_800C4E0C + 4)) {
        PlaySound(0x3D);
        D_800C4E0C = D_800F383C;
    }
}

void func_80042BAC(omObjData* obj) {
    s32 i;
    unk43760* p;

    switch (obj->work[0]) {
        case 0:
            obj->trans.y += 16.0f;
            for (i = 0; i < D_800C4D3C[D_800D6459]; i++) {
                p = &D_800D6400[i];
                func_8006DDC8(p->unk_00, (s16)(p->unk_04 + p->unk_08 / 2), (s32)obj->trans.y + p->unk_06 + p->unk_0A / 2);
            }
            func_80066DC4(D_800D645A, 0, 160, (s32)obj->trans.y + D_800D6404 + D_800C4DC0[D_800D6459]);
            if (obj->trans.y > 218.0f) {
                func_80042B60();
                obj->work[0] = 1;
                obj->scale.x = 1.0f;
                obj->scale.z = -1.0f;
                obj->scale.y = 0.0f;
                obj->work[1] = 0;
                obj->work[2] = rand8() % D_800C4D3C[D_800D6459];
                obj->work[3] = 0;
                func_800437B8();
            }
            break;
        case 1:
            obj->scale.z += obj->scale.x;
            if (obj->scale.z >= 1.0f) {
                if (obj->work[3] != 0 && obj->scale.x <= 0.08f) {
                    obj->work[3]--;
                }
                obj->scale.z -= 1.0f;
                if (obj->scale.y == 0.0f) {
                    obj->work[1]++;
                    obj->work[1] %= D_800C4D3C[D_800D6459];
                } else {
                    obj->work[1]--;
                    if (obj->work[1] >= 128) {
                        obj->work[1] = D_800C4D3C[D_800D6459] - 1;
                    }
                }
                func_80042B60();
            }
            for (i = 0; i < D_800C4D3C[D_800D6459]; i++) {
                p = &D_800D6400[i];
                if (i == obj->work[1]) {
                    func_800714F0(p->unk_00, 0, 200, 0);
                    func_8006E154(p->unk_00, 0x100);
                    func_8006E0A4(p->unk_00, 9000);
                } else {
                    func_800714F0(p->unk_00, 0x40, 0x40, 0x80);
                    func_8006E154(p->unk_00, 0);
                    func_8006E0A4(p->unk_00, 10000);
                }
            }
            if (obj->work[1] == obj->work[2] || obj->scale.x < 1.0f) {
                obj->scale.x -= 0.02;
            }
            if (obj->scale.x <= 0.08f) {
                obj->scale.x = 0.08f;
                if (obj->work[1] == obj->work[2] && obj->work[3] == 0 && obj->scale.z + obj->scale.x >= 1.0f) {
                    if ((rand8() & 0xF) || obj->scale.y == 1.0f || obj->work[1] == 0) {
                        PlaySound(0x3E);
                        obj->work[0] = 2;
                        obj->work[3] = 60;
                        func_8006EB80();
                        func_8006DA1C(D_800D6400[obj->work[1]].unk_00, 0, 4);
                        LoadStringIntoWindow(D_800D6400[obj->work[1]].unk_00, (void*)(D_800D6454[obj->work[1]] + 0x324), -2, 4);
                        func_8006E288(D_800D6400[obj->work[1]].unk_00, 1);
                        func_8006E2B8(D_800D6400[obj->work[1]].unk_00, 0xA0, 0xA0, 0xA0);
                        func_800714F0(D_800D6400[obj->work[1]].unk_00, 0xFE, 0xFF, 0xD0);
                        func_8006E070(D_800D6400[obj->work[1]].unk_00, 0);
                    } else {
                        obj->scale.y = 1.0f;
                        obj->work[2]--;
                        if (obj->work[2] >= 128) {
                            obj->work[2] = D_800C4D3C[D_800D6459] - 1;
                        }
                    }
                }
            }
            break;
        case 2:
            if (obj->work[3] != 0) {
                obj->work[3]--;
            } else {
                D_800D6438[D_800D6459][D_800D644C[D_800D6459]] = D_800D6454[obj->work[2]];
                if ((D_800D6459 == 3) | (D_800D6459 == 0)) {
                    D_800D644C[D_800D6459]++;
                    D_800D644C[D_800D6459] %= 5;
                }
                func_80059348(D_800D6454[obj->work[2]] - 1);
                if (GwSystem.curBoardIndex != 8) {
                    func_80047D48();
                    func_80043544();
                }
            }
            obj->rot.z += 1.0f;
            if (obj->rot.z >= 13.0f) {
                obj->rot.z -= 13.0f;
            }
            break;
    }
    if (D_800D645E != -1) {
        for (i = 0; !(obj->rot.z < (*(D_800C4DC8 + i))[0]); i++) {
        }
        func_80066DC4(D_800D645E, 0, D_800C4DC8[i][1] + 50, D_800C4DC4[D_800D6459] + obj->work[1] * 20);
    }
}

void func_80043460(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            D_800D6438[i][j] = -1;
        }
        D_800D644C[i] = 0;
    }
    for (i = 0; i < 5; i++) {
        D_800D6462[i] = -1;
    }
    D_800D6467 = 0;
}

void func_800434E4(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800D6400); i++) {
        D_800D6400[i].unk_00 = -1;
    }

    D_800D6450 = 0;
    D_800D645C = -1;
    D_800D645A = -1;
    D_800D6460 = -1;
    D_800D645E = -1;
}

void func_80043544(void) {
    s32 i;
    unk43760* p;

    for (i = 0; i < ARRAY_COUNT(D_800D6400); i++) {
        p = &D_800D6400[i];
        if (p->unk_00 != -1) {
            func_80070D90(p->unk_00);
            p->unk_00 = -1;
        }
    }
    if (D_800D6450 != NULL) {
        omDelObj(D_800D6450);
        D_800D6450 = NULL;
    }
    if (D_800D645A != -1) {
        func_80064D38(D_800D645A);
        D_800D645A = -1;
    }
    if (D_800D645C != -1) {
        func_80067704(D_800D645C);
        D_800D645C = -1;
    }
    if (D_800D645E != -1) {
        func_80064D38(D_800D645E);
        D_800D645E = -1;
    }
    if (D_800D6460 != -1) {
        func_80067704(D_800D6460);
        D_800D6460 = -1;
    }
}

void func_8004367C(void) {
    void* temp_s0;

    if (D_800D645A == -1) {
        D_800D645A = func_80064EF4(1, 5);
        temp_s0 = DataRead(0xA0023);
        D_800D645C = func_800678A4(temp_s0);
        DataClose(temp_s0);
        func_80067208(D_800D645A, 0, D_800D645C, 0);
        func_80067384(D_800D645A, 0, 0x4770);
        func_800674BC(D_800D645A, 0, 0x1000U);
        func_80066DC4(D_800D645A, 0, 0xA0, D_800C4DC0[D_800D6459] + D_800D6404);
        
        if (rand8() & 1) {
            func_800674F4(D_800D645A, 0, 0x35,  0x9D, 0xE6);
        } else {
            func_800674F4(D_800D645A, 0, 0xAD, 0x71, 0xFE);
        }
    }
}

void func_800437B8(void) {
    void* temp_s0;

    if (D_800D645E == -1) {
        D_800D645E = func_80064EF4(1, 5);
        temp_s0 = DataRead(0xA0025);
        D_800D6460 = func_800678A4(temp_s0);
        DataClose(temp_s0);
        func_80067208(D_800D645E, 0, D_800D6460, 0);
        func_80067384(D_800D645E, 0, 0x100);
        func_800674BC(D_800D645E, 0, 0x1000U);
        func_80066DC4(D_800D645E, 0, 0x32, D_800C4DC4[D_800D6459]);
    }
}


// register allocation and hoisting of sel*5 around the exclusion test (masked 13)
#ifdef NON_MATCHING
void func_8004388C(s32 arg0) {
    Rect43760* rects[4] = { D_800C4D58, D_800C4D40, D_800C4D40, D_800C4D58 };
    u8* lists[4] = { D_800C4CD0, D_800C4D00, D_800C4D1C, D_800C4D28 };
    s32 i;
    s32 j;
    s32 sel;
    unk43760* p;
    omObjData* obj;


    sel = 3;
    if (arg0 == -1) {
        sel = func_80054FE4();
        if (sel == arg0) {
            sel = 3;
        }
    }
    D_800D6459 = sel;
    for (i = 0; i < D_800C4D3C[sel]; i++) {
        p = &D_800D6400[i];
        p->unk_04 = rects[sel][i].x;
        p->unk_06 = rects[sel][i].y;
        p->unk_08 = rects[sel][i].w;
        p->unk_0A = rects[sel][i].h;
        p->unk_00 = func_8006D010(p->unk_04 + p->unk_08 / 2, p->unk_06 + p->unk_0A / 2, p->unk_08, p->unk_0A, 0, 0);
        func_8006E0A4(p->unk_00, 9000);
        func_800717C0(p->unk_00);
        func_8006DEC8(p->unk_00, p->unk_08 / 2, p->unk_0A / 2);
        func_8006E154(p->unk_00, 0);
        while (1) {
            D_800D6454[i] = lists[sel][(u8)(rand8() % D_800C4E10[sel])];
            for (j = 0; j < i; j++) {
                if (j != i && D_800D6454[j] == D_800D6454[i]) {
                    break;
                }
            }
            if (j != i) {
                continue;
            }
            if ((sel == 3) | (sel == 0)) {
                for (j = 0; j < 5; j++) {
                    if (D_800D6438[sel][j] == D_800D6454[i]) {
                        break;
                    }
                }
                if (j != 5) {
                    continue;
                }
            } else if (D_800D6454[i] == D_800D6438[sel][0]) {
                continue;
            }
            switch (D_800D6454[i]) {
                case 8:
                case 29:
                case 47:
                case 53:
                    for (j = 0; j < 4; j++) {
                        if (GwPlayer[j].coins < 15) {
                            break;
                        }
                    }
                    if (j != 4) {
                        continue;
                    }
                    break;
                case 17:
                case 32:
                case 51:
                    if (GwPlayer[D_800ECE10].coins < 15) {
                        continue;
                    }
                    break;
                case 52:
                    for (j = 0; j < 4; j++) {
                        if ((j == D_800ECE10) ? (GwPlayer[j].coins < 15) : (GwPlayer[j].coins < 5)) {
                            break;
                        }
                    }
                    if (j != 4) {
                        continue;
                    }
                    break;
            }
            break;
        }
        func_8006EB80();
        LoadStringIntoWindow(p->unk_00, (void*)(D_800D6454[i] + 0x324), -2, 4);
        func_8006E288(p->unk_00, D_800C4DCF[D_800D6454[i]]);
        func_8006E070(p->unk_00, 0);
    }
    obj = omAddObj(-0x8000, 0, 0, -1, func_80042BAC);
    D_800D6450 = obj;
    obj->work[0] = 3;
    obj->trans.y = 0.0f;
    obj->rot.z = 0.0f;
    func_8004367C();
}
#else
INCLUDE_RODATA("asm/nonmatchings/43760", D_800CAD28);

INCLUDE_RODATA("asm/nonmatchings/43760", D_800CAD38);

INCLUDE_ASM("asm/nonmatchings/43760", func_8004388C);
#endif

void func_80043D68(void) {
    D_800D6450->work[0] = 0;
}

void func_80043D78(u8* out, s32 n) {
    u8 buf[256];
    s32 i;
    s32 j;

    for (i = 0; i <= n; i++) {
        buf[i] = i;
    }
    for (i = 0; i <= n; i++) {
        j = rand8() % (n - i + 1);
        out[i] = buf[j];
        for (; j < n; j++) {
            buf[j] = buf[j + 1];
        }
    }
}

void func_80043E7C(u8* out) {
    s32 res[4];
    u8 order[4];
    s32 i;
    s32 n4;
    s32 n1;
    s32 r;

    for (i = 0; i < 4; i++) {
        res[i] = 0;
    }
    n4 = 0;
    n1 = 0;
    for (i = 0; i < 4; i++) {
        if (func_80054730(i) == 1) {
            n1++;
        } else if (func_80054730(i) != 2) {
            n4 += func_80054730(i) == 4;
        }
    }
    r = func_8005021C(100.0f);
    switch (n4) {
        case 1:
            switch (n1) {
                case 3:
                    if (r < 20) {
                        res[0] = 1;
                    }
                    break;
                case 2:
                    if (r < 40) {
                        res[0] = 1;
                    }
                    break;
                case 1:
                    if (r < 70) {
                        res[0] = 1;
                    }
                    break;
                case 0:
                    if (r < 90) {
                        res[0] = 1;
                    }
                    break;
            }
            break;
        case 2:
            switch (n1) {
                case 2:
                    if (r < 10) {
                        res[0] = res[1] = 1;
                    } else if (r < 30) {
                        res[1] = 1;
                    }
                    break;
                case 1:
                    if (r < 30) {
                        res[0] = res[1] = 1;
                    } else if (r < 70) {
                        res[1] = 1;
                    }
                    break;
                case 0:
                    if (r < 70) {
                        res[0] = res[1] = 1;
                    } else if (r < 90) {
                        res[1] = 1;
                    }
                    break;
            }
            break;
        case 3:
            switch (n1) {
                case 1:
                    if (r < 10) {
                        res[0] = res[1] = res[2] = 1;
                    } else if (r < 40) {
                        res[1] = res[2] = 1;
                    } else if (r < 50) {
                        res[2] = 1;
                    }
                    break;
                case 0:
                    if (r < 50) {
                        res[0] = res[1] = res[2] = 1;
                    } else if (r < 60) {
                        res[1] = res[2] = 1;
                    } else if (r < 90) {
                        res[2] = 1;
                    }
                    break;
            }
            break;
        case 4:
            if (r < 30) {
                res[0] = res[1] = res[2] = res[3] = 1;
            } else if (r < 40) {
                res[1] = res[2] = res[3] = 1;
            } else if (r < 70) {
                res[2] = res[3] = 1;
            } else if (r < 80) {
                res[3] = 1;
            }
            break;
    }
    func_80043D78(order, n4 - 1);
    n1 = 0;
    for (i = 0; i < 4; i++) {
        switch (func_80054730(i)) {
            case 1:
                out[i] = 1;
                break;
            case 2:
                out[i] = 2;
                break;
            case 4:
                if (res[order[n1++]] == 0) {
                    out[i] = 1;
                } else {
                    out[i] = 2;
                }
                break;
        }
    }
}

void func_800441D4(void) {
    u8 isFour[4];
    u8 saved[4];
    unkUserData_00* data;
    s32 i;
    s32 j;

    data = HuPrcCurrentGet()->user_data;
    while (1) {
        switch (data->unk_00) {
            case 0:
                func_80054868(4);
                data->unk_00 = 10;
                break;
            case 10:
                if (func_80054FA8() == 0) {
                    data->unk_00 = 11;
                }
                break;
            case 11:
                j = 0;
                for (i = 0; i < 4; i++) {
                    if (func_80054730(i) == 4) {
                        j = 1;
                        isFour[i] = 1;
                    } else {
                        isFour[i] = 0;
                    }
                }
                if (j != 0) {
                    data->unk_00 = 12;
                } else {
                    data->unk_00 = 1;
                }
                break;
            case 12:
                func_80043E7C(saved);
                PlaySound(0x77);
                for (i = 0; i < 24; i++) {
                    for (j = 0; j < 4; j++) {
                        if (isFour[j]) {
                            func_800546B4(j, i + 5);
                        }
                    }
                    HuPrcVSleep();
                }
                for (i = 0; i < 4; i++) {
                    if (func_80054730(i) != saved[i]) {
                        func_800546B4(i, saved[i]);
                    }
                }
                data->unk_00 = 1;
                break;
            case 1:
                if (func_80054FA8() == 0) {
                    HuPrcSleep(1);
                    func_80047BE0(0);
                    HuPrcSleep(5);
                    data->unk_00++;
                }
                break;
            case 2:
                func_80054868(2);
                func_800550C4();
                data->unk_00++;
                break;
            case 3:
                if (func_80054FA8() == 0) {
                    for (i = 0; i < 4; i++) {
                        if (!(GwPlayer[i].flags & 1)) {
                            break;
                        }
                    }
                    if (i != 4) {
                        for (i = 0; i < 4; i++) {
                            if ((ContBtnTrg[GwPlayer[i].port] & 0x8000) && !(GwPlayer[i].flags & 1)) {
                                break;
                            }
                        }
                        if (i == 4) {
                            break;
                        }
                    }
                    if (func_80054FE4() != -1) {
                        func_80043D68();
                        func_80054868(5);
                    } else {
                        func_80059348(-1);
                    }
                    data->unk_00++;
                }
                break;
            case 4:
                if (func_80054FE4() == -1 || func_80047D38() == 0) {
                    func_80055228();
                    EndProcess(NULL);
                }
                break;
        }
        HuPrcVSleep();
    }
}

Process* func_800444DC(void) {
    Process* process;
    s32* data;

    process = omAddPrcObj(&func_800441D4, 0, 0x2000, 0x40);
    data = HuMemMemoryAlloc(process->heap, 16);
    process->user_data = data;
    *data = 0;
    return process;
}

void func_8004452C(void) { //TODO: fix goto
    unkUserData_00* temp_s0 = HuPrcCurrentGet()->user_data;
    u16* temp = ContBtnTrg;

loop_1:
    switch (temp_s0->unk_00) {
    case 0:
        func_80054868(temp_s0->unk_04 + 6);
        func_80047BE0(1);
        temp_s0->unk_00++;
        break;
    case 1:
        if (func_80054FA8() == 0) {
            if (temp[GwPlayer[temp_s0->unk_04].port] & 0x8000) {
                if (!(GwPlayer[temp_s0->unk_04].flags & 1)) {    
                    func_80043D68();
                    func_80054868(5);
                    temp_s0->unk_00++;
                    break;
                }
            }
            
            if (GwPlayer[temp_s0->unk_04].flags & 1) {
                func_80043D68();
                func_80054868(5);
                temp_s0->unk_00++;
            }  
        }
        break;
    case 2:
        if (D_800D645A == -1) {
            EndProcess(NULL);
        }
        break;
    }
    HuPrcVSleep();
    goto loop_1;
}

Process* func_80044680(s32 arg0) {
    Process* process;
    unkUserData_00* userData;

    process = omAddPrcObj(func_8004452C, 0, 0x2000, 0x40);
    userData = HuMemMemoryAlloc(process->heap, sizeof(unkUserData_00));
    process->user_data = userData;
    userData->unk_00 = 0;
    userData->unk_04 = arg0;
    return process;
}

void func_800446E0(void) {
    u8 isFour[4];
    u8 saved[4];
    unkUserData_00* data;
    s32 i;
    s32 j;

    data = HuPrcCurrentGet()->user_data;
    while (1) {
        switch (data->unk_00) {
            case 10:
                if (func_80054FA8() == 0) {
                    data->unk_00 = 11;
                }
                break;
            case 11:
                j = 0;
                for (i = 0; i < 4; i++) {
                    if (func_80054730(i) == 4) {
                        j = 1;
                        isFour[i] = 1;
                    } else {
                        isFour[i] = 0;
                    }
                }
                if (j == 0) {
                    data->unk_00 = 1;
                } else {
                    data->unk_00 = 12;
                }
                break;
            case 12:
                func_80043E7C(saved);
                PlaySound(0x77);
                for (i = 0; i < 24; i++) {
                    for (j = 0; j < 4; j++) {
                        if (isFour[j]) {
                            func_800546B4(j, i + 5);
                        }
                    }
                    HuPrcVSleep();
                }
                for (i = 0; i < 4; i++) {
                    if (func_80054730(i) != saved[i]) {
                        func_800546B4(i, saved[i]);
                    }
                }
                data->unk_00 = 1;
                break;
            case 1:
                EndProcess(NULL);
                break;
        }
        HuPrcVSleep();
    }
}

Process* func_800448A0(s32 arg0) {
    Process* process;
    unkUserData_00* userData;

    process = omAddPrcObj(func_800446E0, 0, 0x2000, 0x40);
    userData = HuMemMemoryAlloc(process->heap, sizeof(unkUserData_00));
    process->user_data = userData;
    userData->unk_00 = 10;
    return process;
}

void func_800448F4(omObjData* obj) {
    s32 i;
    unk43760* p;

    switch (obj->work[0]) {
        case 1:
            obj->scale.z += obj->scale.x;
            if (obj->scale.z >= 1.0f) {
                if (obj->work[3] != 0 && obj->scale.x <= 0.08f) {
                    obj->work[3]--;
                }
                obj->scale.z -= 1.0f;
                if (obj->scale.y == 0.0f) {
                    obj->work[1]++;
                    obj->work[1] %= D_800C4D3C[D_800D6459];
                } else {
                    obj->work[1]--;
                    if (obj->work[1] >= 128) {
                        obj->work[1] = D_800C4D3C[D_800D6459] - 1;
                    }
                }
                func_80042B60();
            }
            for (i = 0; i < D_800C4D3C[D_800D6459]; i++) {
                p = &D_800D6400[i];
                if (i == obj->work[1]) {
                    func_800714F0(p->unk_00, 0, 200, 0);
                    func_8006E154(p->unk_00, 0x100);
                    func_8006E0A4(p->unk_00, 9000);
                } else {
                    func_800714F0(p->unk_00, 0x40, 0x40, 0x80);
                    func_8006E154(p->unk_00, 0);
                    func_8006E0A4(p->unk_00, 10000);
                }
            }
            if (obj->work[1] == obj->work[2] || obj->scale.x < 1.0f) {
                obj->scale.x -= 0.02;
            }
            if (obj->scale.x <= 0.08f) {
                obj->scale.x = 0.08f;
                if (obj->work[1] == obj->work[2] && obj->work[3] == 0 && obj->scale.z + obj->scale.x >= 1.0f) {
                    if ((rand8() & 1) || obj->scale.y == 1.0f || obj->work[1] == 0) {
                    stop:
                        PlaySound(0x3E);
                        obj->work[0] = 2;
                        obj->work[3] = 60;
                        func_8006EB80();
                        func_8006DA1C(D_800D6400[obj->work[1]].unk_00, 0, 4);
                        LoadStringIntoWindow(D_800D6400[obj->work[1]].unk_00, (void*)(D_800D6454[obj->work[1]] + 0x324), -2, 4);
                        func_8006E288(D_800D6400[obj->work[1]].unk_00, 1);
                        func_8006E2B8(D_800D6400[obj->work[1]].unk_00, 0xA0, 0xA0, 0xA0);
                        func_800714F0(D_800D6400[obj->work[1]].unk_00, 0xFE, 0xFF, 0xD0);
                        func_8006E070(D_800D6400[obj->work[1]].unk_00, 0);
                    } else {
                        for (i = 0; i < D_800C4D3C[D_800D6459]; i++) {
                            if (D_800D6454[obj->work[2] - 1] == D_800D6462[i]) {
                                break;
                            }
                        }
                        if (i != D_800C4D3C[D_800D6459]) {
                            goto stop;
                        }
                        obj->scale.y = 1.0f;
                        obj->work[2]--;
                        if (obj->work[2] >= 128) {
                            obj->work[2] = D_800C4D3C[D_800D6459] - 1;
                        }
                    }
                }
            }
            break;
        case 2:
            if (obj->work[3] != 0) {
                obj->work[3]--;
            } else {
                D_800D6462[D_800D6467] = D_800D6454[obj->work[2]];
                D_800D6467++;
                D_800D6467 %= D_800C4D3C[D_800D6459] - 1;
                func_80059348(D_800D6454[obj->work[2]] - 1);
                func_80043544();
            }
            obj->rot.z += 1.0f;
            if (obj->rot.z >= 13.0f) {
                obj->rot.z -= 13.0f;
            }
            break;
        case 3:
            break;
    }
    if (D_800D645E != -1) {
        for (i = 0; !(obj->rot.z < (*(D_800C4DC8 + i))[0]); i++) {
        }
        func_80066DC4(D_800D645E, 0, D_800C4DC8[i][1] + 50, D_800C4DC4[D_800D6459] + obj->work[1] * 20);
    }
}

void func_80045000(void) {
    func_8004501C(0);
}

void func_8004501C(s32 arg0) {
    u8 valid[56];
    Rect43760* rects[4] = { D_800C4D98, D_800C4D80, D_800C4D80, D_800C4D98 };
    u8* lists[4] = { D_800C4E38, D_800C4E2C, D_800C4E24, D_800C4E14 };
    s32 n = 0;
    s32 i;
    s32 j;
    unk43760* p;
    omObjData* obj;

    func_8006CEA0();
    func_80059348(-1);
    D_800D6459 = arg0;
    for (i = 0; i < D_800C4E54[D_800D6459]; i++) {
        if (func_8005949C(lists[D_800D6459][i] - 1) != 0) {
            valid[n++] = lists[D_800D6459][i];
        }
    }
    for (i = 0; i < D_800C4D3C[D_800D6459]; i++) {
        p = &D_800D6400[i];
        p->unk_04 = rects[D_800D6459][i].x;
        p->unk_06 = rects[D_800D6459][i].y;
        p->unk_08 = rects[D_800D6459][i].w;
        p->unk_0A = rects[D_800D6459][i].h;
        p->unk_00 = func_8006D010(p->unk_04 + p->unk_08 / 2, p->unk_06 + p->unk_0A / 2, p->unk_08, p->unk_0A, 0, 0);
        func_8006E0A4(p->unk_00, 9000);
        func_800717C0(p->unk_00);
        func_8006DEC8(p->unk_00, p->unk_08 / 2, p->unk_0A / 2);
        func_8006E154(p->unk_00, 0);
        do {
            D_800D6454[i] = valid[rand8() % n];
            for (j = 0; j < i; j++) {
                if (j != i && D_800D6454[j] == D_800D6454[i]) {
                    break;
                }
            }
        } while (j != i);
        func_8006EB80();
        LoadStringIntoWindow(p->unk_00, (void*)(D_800D6454[i] + 0x324), -2, 4);
        func_8006E288(p->unk_00, D_800C4DCF[D_800D6454[i]]);
        func_8006E070(p->unk_00, 0);
    }
    obj = omAddObj(-0x8000, 0, 0, -1, func_800448F4);
    D_800D6450 = obj;
    obj->work[0] = 1;
    obj->trans.y = 0.0f;
    obj->rot.z = 0.0f;
    obj->scale.x = 1.0f;
    obj->scale.z = -1.0f;
    obj->scale.y = 0.0f;
    obj->work[1] = 0;
    do {
        i = 0;
        obj->work[2] = rand8() % D_800C4D3C[D_800D6459];
        for (; i < D_800C4D3C[D_800D6459]; i++) {
            if (D_800D6454[obj->work[2]] == D_800D6462[i]) {
                break;
            }
        }
    } while (i != D_800C4D3C[D_800D6459]);
    obj->work[3] = 0;
    func_8004367C();
    func_800437B8();
    func_80042B60();
}

