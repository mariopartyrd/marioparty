#include "common.h"
#include "sdk_leo.h"

// libleo command execution (the leocmdex.c family): the per-command handlers the command thread
// runs on the current command (D_800E87D8), the drive's RTC, and the C2 (Reed-Solomon) error
// correction. IDO-compiled: NON_MATCHING (see sdk_leo.h).

typedef struct LEOCmdTestUnitReady {
    /* 0x00 */ LEOCmdHeader header;
    /* 0x0C */ u8 test;
} LEOCmdTestUnitReady;

typedef struct LEOCmdReadCapacity {
    /* 0x00 */ LEOCmdHeader header;
    /* 0x0C */ u32 startLBA;
    /* 0x10 */ u32 endLBA;
    /* 0x14 */ u32 nbytes;
} LEOCmdReadCapacity;

typedef struct LEOCmdModeSelect {
    /* 0x00 */ LEOCmdHeader header;
    /* 0x0C */ u8 page;
    /* 0x0D */ u8 reserve1;
    /* 0x0E */ u8 standby_time;
    /* 0x0F */ u8 sleep_time;
    /* 0x10 */ u32 led_on_time;
} LEOCmdModeSelect;

typedef struct LEOCmdReadTimer {
    /* 0x00 */ LEOCmdHeader header;
    /* 0x0C */ u8 reserve12;
    /* 0x0D */ u8 yearhi;
    /* 0x0E */ u8 yearlo;
    /* 0x0F */ u8 month;
    /* 0x10 */ u8 day;
    /* 0x11 */ u8 hour;
    /* 0x12 */ u8 minute;
    /* 0x13 */ u8 second;
} LEOCmdReadTimer;

#define LEO_CUR(type) ((type*)D_800E87D8)
#define LEO_STATUS_GOOD 0
#define LEO_STATUS_CHECK_CONDITION 2

extern void* D_800E87D8;        // LEOcur_command
extern u16 D_800E87E6;
extern OSPiHandle* D_800EA150;  // LEOPiInfo
extern u8 D_800CBDD0[];         // GF(256) exponent table (doubled)
extern u8 D_800CBECF[];         // = D_800CBDD0 + 0xFF
extern u8 D_800CBFD0[];         // GF(256) logarithm table
extern u16 D_800CBD98[];        // first user lba per disk type
extern u32 D_800CBDA8[];        // capacity in bytes per disk type

// C1 error report of the last read (80BE0.c)
typedef struct LEORwInfo {
    /* 0x00 */ u8* dram;
    /* 0x04 */ u8* c2end;
    /* 0x08 */ u8 errSector[4];
    /* 0x0C */ u8 errNum;
    /* 0x0D */ u8 secBytes;
    /* 0x0E */ u16 blkBytes;
} LEORwInfo;

extern LEORwInfo D_800EA140;
extern u8 D_800E99F8[];          // scratch sector (end) for an out-of-range erasure
extern LEOCmdRead D_800C6450;    // read command template for the system area
extern u8 D_800CC2A0[];          // system-area lbas tried in turn (2)
extern u8 D_800CC2A2[];
extern u32 D_800E9910[8];        // disk ID read from the system area
extern OSMesgQueue D_800E7A98;
extern u8 D_800CC2B0[];          // RTC field maxima
extern u8 D_800CC2B8[];          // days per month

typedef struct LEOCmdReadDiskId {
    /* 0x00 */ LEOCmdHeader header;
    /* 0x0C */ u32* buffer_pointer;
} LEOCmdReadDiskId;

typedef struct LEOCmdLBAConv {
    /* 0x00 */ LEOCmdHeader header;
    /* 0x0C */ u32 lba;
    /* 0x10 */ u32 in;  // bytes (control & 1) or lbas
    /* 0x14 */ u32 out; // lbas (control & 1) or bytes
} LEOCmdLBAConv;

extern u32 D_800E87DC;
extern u32 D_800E87E0;
extern u8 D_800E87E4;            // non-zero once the system area has been read
extern u8 D_800E87E5;
extern s32 D_800EA170;           // current command code
extern OSIoMesg D_800EA158;
extern OSMesgQueue D_800E8748;   // command queue
extern OSMesgQueue D_800E8760;
extern OSMesgQueue D_800E8790;
extern LEOCmdRead D_800C6430;    // system-area read command template
extern u8 D_800CC1F0[];          // system-area lbas
extern void (*D_800C63F0[])(void); // command handlers, by command code

u8 func_80080ADC(u32 asic_cmd);
u8 func_80081280(void);
u8 func_8008128C(void);
void func_800812C0(void);
void func_80081250(void);
void func_80081310(void);
void func_800814D0(void);
u8 func_800842DC(void);
void func_800812DC(void);
void func_800812F8(void);
u16 func_80082D60(void);
u8 func_80085504(u8* rtc);
extern OSThread D_800E7D98;      // read/write thread
extern OSMesgQueue D_800E8778;

u8 func_80080E70(u32 asic_cmd, u32 asic_data);
u8 func_80080EA8(u32 asic_cmd, u32 asic_data);
u8 func_80080FE4(void);
u8 func_80081070(void);
s32 func_80081100(u32 sense);
u8 func_80081210(void);

void func_8008499C(u32 start); // leoRead_common
u8 func_80083DC4(u8 a, u8 b); // GF(256) multiply
u8 func_80083E08(u8 a, u8 b); // GF(256) divide
void func_80082DEC(void);
void func_80082EC0(void);
void func_80083140(void);
void func_80083528(void);
u8 func_80085394(u8* rtc);     // read the RTC (6 bytes)

INCLUDE_RODATA("asm/nonmatchings/83960", D_800CBD98);

INCLUDE_RODATA("asm/nonmatchings/83960", D_800CBDA8);

INCLUDE_RODATA("asm/nonmatchings/83960", D_800CBDD0);

INCLUDE_RODATA("asm/nonmatchings/83960", D_800CBFD0);

#ifdef NON_MATCHING
// leoC2_Correction: by the number of C1 error sectors
u16 func_80082D60(void) {
    switch (D_800EA140.errNum) {
        case 0:
            return 0;
        case 1:
            func_80082DEC();
            return 0;
        case 2:
            func_80082EC0();
            return 0;
        case 3:
            func_80083140();
            return 0;
        case 4:
            func_80083528();
            return 0;
        default:
            return 0xFFFF;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_80082D60);
#endif

#ifdef NON_MATCHING
// one erroneous sector: XOR the C2 parity back in
void func_80082DEC(void) {
    u32 s = D_800EA140.errSector[0];
    u32 n;
    u8* p;
    u8* c2;

    if (s >= 0x55) {
        return;
    }
    n = D_800EA140.secBytes;
    p = D_800EA140.dram + (s + 1) * n;
    c2 = D_800EA140.c2end;
    for (; n != 0; n--) {
        c2 -= 4;
        p--;
        *p ^= *c2;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_80082DEC);
#endif

#ifdef NON_MATCHING
// two erroneous sectors: solve for both from the two C2 syndromes
void func_80082EC0(void) {
    u32 e1 = D_800EA140.errSector[0];
    u32 e2 = D_800EA140.errSector[1];
    u8* a2 = &D_800CBDD0[0x58 - e2]; // alpha^(88 - e2)
    u8 k;
    u32 n;
    u8* p1;
    u8* p2;
    u8* c2;
    u8 s0;
    u8 s1;
    u8 v;

    k = D_800CBFD0[func_80083E08(1, D_800CBDD0[0x58 - e2] ^ D_800CBDD0[0x58 - e1])];
    n = D_800EA140.secBytes;
    if (D_800EA140.errSector[1] < 0x55) {
        p2 = D_800EA140.dram + (D_800EA140.errSector[1] + 1) * n;
    } else {
        if (D_800EA140.errSector[0] >= 0x55) {
            return;
        }
        p2 = D_800E99F8;
    }
    p1 = D_800EA140.dram + (D_800EA140.errSector[0] + 1) * n;
    c2 = D_800EA140.c2end;
    for (; n != 0; n--) {
        c2 -= 4;
        p1--;
        s0 = c2[0];
        if (s0 != 0) {
            s1 = c2[1] ^ a2[D_800CBFD0[s0]];
        } else {
            s1 = c2[1];
        }
        p2--;
        if (s1 != 0) {
            v = D_800CBDD0[D_800CBFD0[s1] + k];
            *p1 ^= v;
            *p2 ^= v ^ s0;
        } else {
            *p2 ^= s0;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_80082EC0);
#endif

#ifdef NON_MATCHING
// three erroneous sectors: invert the 3x3 Vandermonde system once, then correct each byte column
void func_80083140(void) {
    u8 a = D_800CBDD0[0x58 - D_800EA140.errSector[0]];
    u8 b = D_800CBDD0[0x58 - D_800EA140.errSector[1]];
    u8 c = D_800CBDD0[0x58 - D_800EA140.errSector[2]];
    u8 a2, b2, c2sq;
    u8 m10, m11, m12; // row coefficients (logs) for sector 1
    u8 m20, m21, m22; // sector 2
    u8 m30, m31, m32; // sector 3
    u8 det;
    u8 d1, d2, d3;
    u32 n;
    u8* p1;
    u8* p2;
    u8* p3;
    u8* c2;
    u8 x, lx;
    u8 v1, v2, v3;

    c2sq = func_80083DC4(c, c);
    b2 = func_80083DC4(b, b);
    a2 = func_80083DC4(a, a);
    d1 = func_80083DC4(c, b2) ^ func_80083DC4(b, c2sq);
    d2 = func_80083DC4(a, c2sq) ^ func_80083DC4(c, a2);
    d3 = func_80083DC4(a, b2) ^ func_80083DC4(b, a2);
    det = func_80083E08(1, d1 ^ d2 ^ d3);

    m10 = D_800CBFD0[d1];
    m11 = D_800CBFD0[c2sq ^ b2];
    m12 = D_800CBFD0[b ^ c];
    m20 = D_800CBFD0[d2];
    m21 = D_800CBFD0[c2sq ^ a2];
    m22 = D_800CBFD0[c ^ a];
    m30 = D_800CBFD0[d3];
    m31 = D_800CBFD0[b2 ^ a2];
    m32 = D_800CBFD0[a ^ b];
    det = D_800CBFD0[det];

    n = D_800EA140.secBytes;
    if (D_800EA140.errSector[2] < 0x55) {
        p3 = D_800EA140.dram + (D_800EA140.errSector[2] + 1) * n;
        p2 = D_800EA140.dram + (D_800EA140.errSector[1] + 1) * n;
    } else {
        p3 = D_800E99F8;
        if (D_800EA140.errSector[1] < 0x55) {
            p2 = D_800EA140.dram + (D_800EA140.errSector[1] + 1) * n;
        } else {
            p2 = D_800E99F8;
            if (D_800EA140.errSector[0] >= 0x55) {
                return;
            }
        }
    }
    p1 = D_800EA140.dram + (D_800EA140.errSector[0] + 1) * n;
    c2 = D_800EA140.c2end;
    do {
        c2 -= 4;
        p1--;
        p2--;
        if ((x = c2[0]) != 0) {
            lx = D_800CBFD0[x];
            v1 = D_800CBDD0[lx + m10];
            v2 = D_800CBDD0[lx + m20];
            v3 = D_800CBDD0[lx + m30];
        } else {
            v1 = v2 = v3 = 0;
        }
        n--;
        if ((x = c2[1]) != 0) {
            lx = D_800CBFD0[x];
            v1 ^= D_800CBDD0[lx + m11];
            v2 ^= D_800CBDD0[lx + m21];
            v3 ^= D_800CBDD0[lx + m31];
        }
        if ((x = c2[2]) != 0) {
            lx = D_800CBFD0[x];
            v1 ^= D_800CBDD0[lx + m12];
            v2 ^= D_800CBDD0[lx + m22];
            v3 ^= D_800CBDD0[lx + m32];
        }
        p3--;
        if (v1 != 0) {
            *p1 ^= D_800CBDD0[D_800CBFD0[v1] + det];
        }
        if (v2 != 0) {
            *p2 ^= D_800CBDD0[D_800CBFD0[v2] + det];
        }
        if (v3 != 0) {
            *p3 ^= D_800CBDD0[D_800CBFD0[v3] + det];
        }
    } while (n != 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_80083140);
#endif

#define GF_MUL func_80083DC4
#define GF_DIV func_80083E08

#ifdef NON_MATCHING
// four erroneous sectors: Lagrange weights per sector, then every syndrome's contribution per byte
void func_80083528(void) {
    u8 A1 = D_800CBDD0[0x58 - D_800EA140.errSector[0]];
    u8 A2 = D_800CBDD0[0x58 - D_800EA140.errSector[1]];
    u8 A3 = D_800CBDD0[0x58 - D_800EA140.errSector[2]];
    u8 A4 = D_800CBDD0[0x58 - D_800EA140.errSector[3]];
    u8 one = D_800CBDD0[0];
    u8 iA, iB, iC, iD;
    u8 BC, CD, DB, DA, AC, AB;
    u8 q1[4]; // second-syndrome coefficient values (iB^iC^iD, ...)
    u8 r1[4]; // third-syndrome coefficient values
    u8 t1[4]; // fourth-syndrome coefficient values
    u8 W[4];  // Lagrange weights
    u8 L0[4], L1[4], L2[4], L3[4]; // logs of the weighted coefficients, per syndrome
    u32 i;
    u32 n;
    u8* p[4];
    u8* c2;
    u8 x, lx;
    u8 v[4];

    iA = GF_DIV(one, A1);
    iB = GF_DIV(one, A2);
    iC = GF_DIV(one, A3);
    iD = GF_DIV(one, A4);
    BC = GF_MUL(iB, iC);
    CD = GF_MUL(iC, iD);
    DB = GF_MUL(iD, iB);
    DA = GF_MUL(iD, iA);
    AC = GF_MUL(iA, iC);
    AB = GF_MUL(iA, iB);
    r1[0] = BC ^ CD ^ DB;
    r1[1] = CD ^ DA ^ AC;
    r1[2] = DA ^ AB ^ DB;
    r1[3] = AB ^ BC ^ AC;
    q1[0] = iB ^ iC ^ iD;
    q1[1] = iC ^ iD ^ iA;
    q1[2] = iD ^ iA ^ iB;
    q1[3] = iA ^ iB ^ iC;
    t1[0] = GF_MUL(GF_MUL(iB, iC), iD);
    t1[1] = GF_MUL(GF_MUL(iC, iD), iA);
    t1[2] = GF_MUL(GF_MUL(iD, iA), iB);
    t1[3] = GF_MUL(GF_MUL(iA, iB), iC);

    W[0] = GF_DIV(1, GF_MUL(GF_MUL(GF_DIV(A1, A2) ^ 1, GF_DIV(A1, A3) ^ 1), GF_DIV(A1, A4) ^ 1));
    W[1] = GF_DIV(1, GF_MUL(GF_MUL(GF_DIV(A2, A1) ^ 1, GF_DIV(A2, A3) ^ 1), GF_DIV(A2, A4) ^ 1));
    W[2] = GF_DIV(1, GF_MUL(GF_MUL(GF_DIV(A3, A1) ^ 1, GF_DIV(A3, A2) ^ 1), GF_DIV(A3, A4) ^ 1));
    W[3] = GF_DIV(1, GF_MUL(GF_MUL(GF_DIV(A4, A1) ^ 1, GF_DIV(A4, A2) ^ 1), GF_DIV(A4, A3) ^ 1));

    for (i = 0; i < 4; i++) {
        L1[i] = D_800CBFD0[GF_MUL(q1[i], W[i])];
        L2[i] = D_800CBFD0[GF_MUL(r1[i], W[i])];
        L3[i] = D_800CBFD0[GF_MUL(t1[i], W[i])];
        L0[i] = D_800CBFD0[W[i]];
    }

    n = D_800EA140.secBytes;
    if (D_800EA140.errSector[3] < 0x55) {
        p[3] = D_800EA140.dram + (D_800EA140.errSector[3] + 1) * n;
        goto sector3;
    }
    p[3] = D_800E99F8;
    if (D_800EA140.errSector[2] < 0x55) {
    sector3:
        p[2] = D_800EA140.dram + (D_800EA140.errSector[2] + 1) * n;
        goto sector2;
    }
    p[2] = D_800E99F8;
    if (D_800EA140.errSector[1] < 0x55) {
    sector2:
        p[1] = D_800EA140.dram + (D_800EA140.errSector[1] + 1) * n;
    } else {
        p[1] = D_800E99F8;
        if (D_800EA140.errSector[0] >= 0x55) {
            return;
        }
    }
    p[0] = D_800EA140.dram + (D_800EA140.errSector[0] + 1) * n;

    c2 = D_800EA140.c2end;
    do {
        c2 -= 4;
        p[0]--;
        p[1]--;
        if ((x = c2[0]) != 0) {
            lx = D_800CBFD0[x];
            for (i = 0; i < 4; i++) {
                v[i] = D_800CBDD0[lx + L0[i]];
            }
        } else {
            v[0] = v[1] = v[2] = v[3] = 0;
        }
        p[2]--;
        n--;
        if ((x = c2[1]) != 0) {
            lx = D_800CBFD0[x];
            for (i = 0; i < 4; i++) {
                v[i] ^= (q1[i] != 0) ? D_800CBDD0[lx + L1[i]] : 0;
            }
        }
        if ((x = c2[2]) != 0) {
            lx = D_800CBFD0[x];
            for (i = 0; i < 4; i++) {
                v[i] ^= (r1[i] != 0) ? D_800CBDD0[lx + L2[i]] : 0;
            }
        }
        if ((x = c2[3]) != 0) {
            lx = D_800CBFD0[x];
            for (i = 0; i < 4; i++) {
                v[i] ^= D_800CBDD0[lx + L3[i]];
            }
        }
        p[3]--;
        for (i = 0; i < 4; i++) {
            if (v[i] != 0) {
                *p[i] ^= v[i];
            }
        }
    } while (n != 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_80083528);
#endif

#ifdef NON_MATCHING
// GF(256) multiply
u8 func_80083DC4(u8 a, u8 b) {
    if ((a == 0) || (b == 0)) {
        return 0;
    }
    return D_800CBDD0[D_800CBFD0[b] + D_800CBFD0[a]];
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_80083DC4);
#endif

#ifdef NON_MATCHING
// GF(256) divide
u8 func_80083E08(u8 a, u8 b) {
    if ((a == 0) || (b == 0)) {
        return 0;
    }
    return D_800CBECF[D_800CBFD0[a] - D_800CBFD0[b]];
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_80083E08);
#endif

INCLUDE_RODATA("asm/nonmatchings/83960", D_800CC1F0);

#ifdef NON_MATCHING
// leomain: the 64DD command thread
void func_80083E60(void* arg) {
    u32 stat;
    u32 sense;
    u8 command;

    ((u8*)&D_800E87FC)[0] = *(vu8*)0xA0000010;
    ((u8*)&D_800E87FC)[1] = *(vu8*)0xA0000090;
    ((u8*)&D_800E87FC)[2] = *(vu8*)0xA0000110;
    ((u8*)&D_800E87FC)[3] = *(vu8*)0xA0000190;
    D_800E87E0 = 0;
    D_800E87DC = 0;
    D_800E87E4 = 0;
    D_800E87E5 = 0;
    func_80081310();
    D_800EA150 = osLeoDiskInit();
    D_800EA158.hdr.pri = OS_MESG_PRI_HIGH;
    D_800EA158.hdr.retQueue = &D_800E8790;
    osEPiReadIo(D_800EA150, 0x05000508, &stat); // LEO_STATUS
    if (!(stat & 0x400000) && (stat & 0x6800000)) {
        func_80081250();
    }

    while (TRUE) {
        osRecvMesg(&D_800E8748, (OSMesg*)&D_800E87D8, OS_MESG_BLOCK);
        D_800EA170 = LEO_CUR(LEOCmdHeader)->command;
        if (LEO_CUR(LEOCmdHeader)->command == 0) { // clear queue
            func_80081250();
            osRecvMesg(&D_800E8760, NULL, OS_MESG_NOBLOCK);
            continue;
        }

        sense = func_80080ADC(0x10001);
        stat = func_80081280();
        if (stat == 0) {
            if (sense == 0) {
                goto dispatch;
            }
        } else if ((sense != 3) && (sense != 0x25) && (sense != 0x29) && (sense != 0x2B)) {
            if (sense == 0x31) {
                if (func_8008128C() == 0x2B) {
                    sense = 0x2B;
                }
            } else {
                sense = func_8008128C();
            }
        }

        command = LEO_CUR(LEOCmdHeader)->command;
        if (sense == 0x2B) { // medium may have changed
            if ((command == 2) || (command == 0xD) || (command == 0xE)) {
                goto dispatch;
            }
            if (command == 0xF) {
                func_800812C0();
                goto dispatch;
            }
        } else if (sense == 0x2F) {
            switch (command) {
                case 2:
                case 8:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                    goto dispatch;
            }
        } else if (sense == 0x31) {
            switch (command) {
                case 2:
                case 11:
                case 13:
                case 14:
                case 15:
                    goto dispatch;
                default:
                    sense = 0x2A;
                    break;
            }
        }
        if (command == 3) { // test unit ready
            ((LEOCmdTestUnitReady*)D_800E87D8)->test = func_80081210();
        }
        LEO_CUR(LEOCmdHeader)->sense_code = sense;
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
        goto done;

    dispatch:
        if (D_800E87E4 == 0) {
            switch (LEO_CUR(LEOCmdHeader)->command) {
                case 2:
                case 3:
                case 8:
                case 11:
                case 13:
                case 14:
                case 15:
                    break;
                default:
                    // commands that need the system area: read it first
                    if (D_800E87FC == 0) {
                        osEPiReadIo(D_800EA150, 0x05000540, &stat); // ASIC_ID_REG
                        if ((stat & 0x70000) != 0x40000) {
                            while (TRUE) {
                            }
                        }
                    }
                    if (func_800842DC() != 0) {
                        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
                        goto done;
                    }
                    sense = func_80080E70(0xB0001, D_800E7B00[5] << 16);
                    LEO_CUR(LEOCmdHeader)->sense_code = sense;
                    if (sense != 0) {
                        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
                        goto done;
                    }
                    if ((D_800E7B00[5] & 0xF0) != 0x10) {
                        goto bad_disk;
                    }
                    D_800E87E8 = D_800E7B00[5] & 0xF;
                    if (D_800E87E8 >= 7) {
                    bad_disk:
                        LEO_CUR(LEOCmdHeader)->sense_code = 0xB;
                        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
                        goto done;
                    }
                    D_800E87E4 = 0xFF;
                    break;
            }
        }
        D_800C63F0[LEO_CUR(LEOCmdHeader)->command]();

    done:
        if (LEO_CUR(LEOCmdHeader)->control & 0x80) {
            osSendMesg(LEO_CUR(LEOCmdHeader)->post, (OSMesg)(u32)LEO_CUR(LEOCmdHeader)->sense_code,
                       OS_MESG_BLOCK);
        }
        if (D_800E87E5 != 0) {
            func_800814D0();
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_80083E60);
#endif

#ifdef NON_MATCHING
// leoRead_system_area: read the disk's system area into D_800E7B00, retrying
u8 func_800842DC(void) {
    LEOCmdRead* saved = D_800E87D8;
    LEOCmdRead tmp;
    u32 retry = 0;
    s32 phase = 0;
    u8 sense;

    D_800E87D8 = &tmp;
    while (TRUE) {
        tmp = D_800C6430;
        D_800E87E8 = 0;
        D_800E7B00[8] = 0;
        D_800E87E6 = 0x3000;
        if (phase == 0) {
            func_8008499C(0);
            if (tmp.header.sense_code == 0) {
                retry = 0;
                while (D_800E87FC != 0) {
                }
                phase--;
                continue;
            }
            if (tmp.header.sense_code == 0x17) {
                retry = 0;
                while (D_800E87FC == 0) {
                }
                phase--;
                continue;
            }
        } else {
            tmp.lba = D_800CC1F0[retry & 3];
            if (D_800E87FC == 0) {
                tmp.lba += 2;
            }
            func_8008499C(0);
            if (tmp.header.status == LEO_STATUS_GOOD) {
                while (D_800E87FC != *(u32*)D_800E7B00) {
                }
                break;
            }
        }
        while (TRUE) {
            if (func_80081100(tmp.header.sense_code) != 0) {
                goto end;
            }
            if (retry >= 0x40) {
                goto end;
            }
            retry++;
            if ((retry & 7) != 0) {
                break;
            }
            sense = func_80080E70(0x30001, 0);
            tmp.header.sense_code = sense;
            if (sense == 0) {
                break;
            }
        }
    }
end:
    D_800E87D8 = saved;
    saved->header.sense_code = tmp.header.sense_code;
    return tmp.header.sense_code;
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_800842DC);
#endif

#ifdef NON_MATCHING
// leoInquiry
void func_800844F0(void) {
    u32 asic_id;
    u32 asic_data;

    osEPiReadIo(D_800EA150, 0x05000540, &asic_id); // ASIC_ID_REG
    if (func_80080E70(0x1B0000, 0) == 0) {
        osEPiReadIo(D_800EA150, 0x05000500, &asic_data); // ASIC_DATA
        if (asic_data & 0x10000) {
            asic_id |= 0x100000;
        }
    }
    LEO_CUR(LEOCmdInquiry)->dev_type = 0;
    LEO_CUR(LEOCmdInquiry)->version = asic_id >> 16;
    LEO_CUR(LEOCmdInquiry)->dev_num = 1;
    LEO_CUR(LEOCmdInquiry)->leo_bios_ver = 0;
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_800844F0);
#endif

#ifdef NON_MATCHING
// leoMode_sel
void func_800845A0(void) {
    u8 sense;

    if (((sense = func_80080EA8(0x60000, LEO_CUR(LEOCmdModeSelect)->standby_time << 16)) != 0) ||
        ((sense = func_80080EA8(0x70000, LEO_CUR(LEOCmdModeSelect)->sleep_time << 16)) != 0) ||
        ((sense = func_80080EA8(0x150000, LEO_CUR(LEOCmdModeSelect)->led_on_time)) != 0)) {
        LEO_CUR(LEOCmdHeader)->sense_code = sense;
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    LEO_CUR(LEOCmdHeader)->sense_code = sense;
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_800845A0);
#endif

#ifdef NON_MATCHING
// leoStart_stop
void func_80084650(void) {
    u8 retry = 8;
    u8 sense;
    u32 cmd;
    u32 data;
    u8 control;

    while (TRUE) {
        data = 0;
        control = LEO_CUR(LEOCmdHeader)->control;
        if (control & 1) {
            cmd = 0x50001;
        } else if (control & 2) {
            cmd = 0xD0000;
        } else {
            cmd = 0x40000;
            if (control & 4) {
                data = 0x10000;
            }
        }
        sense = func_80080EA8(cmd, data);
        if (sense == 0) {
            LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
            return;
        }
        if (func_80081100(sense) != 0) {
            break;
        }
        if (retry-- == 0) {
            break;
        }
    }
    LEO_CUR(LEOCmdHeader)->sense_code = sense;
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_80084650);
#endif

#ifdef NON_MATCHING
// leoReadCapacity
void func_80084740(void) {
    LEOCmdReadCapacity* cmd = D_800E87D8;

    if (cmd->header.control & 1) {
        cmd->startLBA = D_800CBD98[D_800E87E8] - 0x18;
        LEO_CUR(LEOCmdReadCapacity)->endLBA = 0x10C3;
        LEO_CUR(LEOCmdReadCapacity)->nbytes = D_800CBDA8[D_800E87E8];
    } else {
        cmd->startLBA = 0;
        LEO_CUR(LEOCmdReadCapacity)->endLBA = 0x10C3;
        LEO_CUR(LEOCmdReadCapacity)->nbytes = 0x3D78F40;
    }
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_80084740);
#endif

#ifdef NON_MATCHING
// leoReadDiskId: read the disk ID from the first system-area lba that reads
void func_800847E0(void) {
    LEOCmdReadDiskId* saved = D_800E87D8;
    LEOCmdRead tmp;
    u8* lba = D_800CC2A0;
    u32* dst;
    u32* src;

    D_800E87D8 = &tmp;
    do {
        tmp = D_800C6450;
        D_800E87E6 = 0x2000;
        tmp.lba = *lba;
        func_8008499C(0);
        lba++;
        if (tmp.header.sense_code != 0x17) {
            break;
        }
    } while (lba < D_800CC2A2);
    D_800E87D8 = saved;
    dst = saved->buffer_pointer;
    for (src = D_800E9910; src != D_800E9910 + 8; src += 4, dst += 4) {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        dst[3] = src[3];
    }
    LEO_CUR(LEOCmdHeader)->sense_code = tmp.header.sense_code;
    LEO_CUR(LEOCmdHeader)->status = tmp.header.status;
    if (LEO_CUR(LEOCmdHeader)->status == LEO_STATUS_GOOD) {
        func_800812DC();
    } else {
        func_800812F8();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_800847E0);
#endif

#ifdef NON_MATCHING
// leoRead
void func_80084970(void) {
    D_800E87E6 = 0;
    func_8008499C(0x18);
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_80084970);
#endif

#ifdef NON_MATCHING
// leoRead_common: the read thread does the transfer; 0x80000 asks for C2 correction
void func_8008499C(u32 start) {
    LEOCmdRead* cmd = D_800E87D8;
    u32 lba = cmd->lba;
    u32 xfer = cmd->xfer_blks;
    OSMesg msg;

    if ((((lba | xfer) >> 16) != 0) || ((lba += start) + xfer > 0x10DC)) {
        goto out_of_range;
    }
    if (xfer == 0) {
        if (lba >= 0x10DC) {
            goto out_of_range;
        }
        cmd->header.sense_code = 0;
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
        return;
    }
    D_800E87F0.lba = lba;
    D_800E87E6 &= 0x3FFF;
    osSendMesg(&D_800E7A98, NULL, OS_MESG_NOBLOCK);
    osStartThread(&D_800E7D98);
    while (TRUE) {
        osRecvMesg(&D_800E8778, &msg, OS_MESG_BLOCK);
        if ((u32)msg != 0x80000) {
            break;
        }
        func_80082D60();
        D_800E87E6 &= ~0x4000;
        osSendMesg(&D_800E7A98, NULL, OS_MESG_NOBLOCK);
    }
    if ((u32)msg == 0x90000) {
        LEO_CUR(LEOCmdHeader)->sense_code = 0;
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
        return;
    }
    LEO_CUR(LEOCmdHeader)->sense_code = (u32)msg;
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
    return;

out_of_range:
    cmd->header.sense_code = 0x20;
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_8008499C);
#endif

#ifdef NON_MATCHING
// leoRezero
void func_80084B30(void) {
    u8 retry = 8;
    u8 sense;

    while (TRUE) {
        sense = func_80080FE4();
        if (sense == 0) {
            D_800E87F0.cylinder = 0;
            D_800E87F0.head = 0;
            D_800E87F0.zone = 0;
            LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
            return;
        }
        if (func_80081100(sense) != 0) {
            break;
        }
        if (retry-- == 0) {
            break;
        }
    }
    LEO_CUR(LEOCmdHeader)->sense_code = sense;
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_80084B30);
#endif

#ifdef NON_MATCHING
// leoSeek
void func_80084BD0(void) {
    u8 retry = 20;
    u8 sense;

    if (LEO_CUR(LEOCmdRead)->lba >= 0x10C4) {
        LEO_CUR(LEOCmdHeader)->sense_code = 0x20; // LBA out of range
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    func_800815F0(LEO_CUR(LEOCmdRead)->lba + 0x18);
    while (TRUE) {
        sense = func_80081070();
        if (sense == 0) {
            LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
            return;
        }
        if (func_80081100(sense) != 0) {
            break;
        }
        if (retry-- == 0) {
            break;
        }
    }
    LEO_CUR(LEOCmdHeader)->sense_code = sense;
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_80084BD0);
#endif

#ifdef NON_MATCHING
// leoTest_unit_rdy
void func_80084C90(void) {
    LEO_CUR(LEOCmdTestUnitReady)->test = func_80081210();
    LEO_CUR(LEOCmdHeader)->sense_code = 0;
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_80084C90);
#endif

#ifdef NON_MATCHING
// leoByte_to_lba / leoLba_to_byte as a command (control & 1: bytes to lbas)
void func_80084CD0(void) {
    LEOCmdLBAConv* cmd = D_800E87D8;
    u32 lba = cmd->lba;
    u32 count = 0;
    u32 bytes = 0;
    u32 n;
    u32 byte_p_blk;
    u16 vzone = 1;
    u16 zone;
    s32 flag = 1;

    if (lba >= 0x10C4) {
        cmd->header.sense_code = 0x20;
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    lba += 0x18;
    if (cmd->header.control & 1) {
        bytes = cmd->in;
        while (bytes != 0) {
            if (flag || (D_800CBC18[D_800E87E8][vzone] == lba)) {
                vzone = func_800817E4(lba);
                zone = D_800CBD18[D_800E87E8][vzone];
                if (zone >= 8) {
                    zone -= 7;
                }
                byte_p_blk = D_800CBC04[zone];
            }
            if (bytes < byte_p_blk) {
                bytes = 0;
            } else {
                bytes -= byte_p_blk;
            }
            count++;
            lba++;
            if ((bytes != 0) && (lba >= 0x10DC)) {
                LEO_CUR(LEOCmdHeader)->sense_code = 0x20;
                LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
                return;
            }
            flag = 0;
        }
        LEO_CUR(LEOCmdLBAConv)->out = count;
    } else {
        n = cmd->in;
        while (n != 0) {
            if (flag || (D_800CBC18[D_800E87E8][vzone] == lba)) {
                vzone = func_800817E4(lba);
                zone = D_800CBD18[D_800E87E8][vzone];
                if (zone >= 8) {
                    zone -= 7;
                }
                byte_p_blk = D_800CBC04[zone];
            }
            n--;
            bytes += byte_p_blk;
            lba++;
            if ((n != 0) && (lba >= 0x10DC)) {
                LEO_CUR(LEOCmdHeader)->sense_code = 0x20;
                LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
                return;
            }
            flag = 0;
        }
        LEO_CUR(LEOCmdLBAConv)->out = bytes;
    }
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_80084CD0);
#endif

#ifdef NON_MATCHING
// leoWrite
void func_80084F70(void) {
    LEOCmdRead* cmd = D_800E87D8;
    u32 lba = cmd->lba;
    u32 xfer = cmd->xfer_blks;
    OSMesg msg;

    if ((((lba | xfer) >> 16) != 0) || ((lba += 0x18) >= 0x10DC) || (lba + xfer > 0x10DC)) {
        cmd->header.sense_code = 0x20; // LBA out of range
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    if (lba < D_800CBD98[D_800E87E8]) {
        cmd->header.sense_code = 0x21; // write protect (system area)
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    if (xfer == 0) {
        cmd->header.sense_code = 0;
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
        return;
    }
    D_800E87E6 = 0x8000;
    D_800E87F0.lba = lba;
    osStartThread(&D_800E7D98);
    osRecvMesg(&D_800E8778, &msg, OS_MESG_BLOCK);
    if ((u32)msg != 0x90000) {
        LEO_CUR(LEOCmdHeader)->sense_code = (u32)msg;
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    LEO_CUR(LEOCmdHeader)->sense_code = 0;
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_80084F70);
#endif

#ifdef NON_MATCHING
// leoReadTimer
void func_800850A0(void) {
    u8 rtc[6];
    u8 sense = func_80085394(rtc);

    LEO_CUR(LEOCmdReadTimer)->yearlo = rtc[0];
    LEO_CUR(LEOCmdReadTimer)->month = rtc[1];
    LEO_CUR(LEOCmdReadTimer)->day = rtc[2];
    LEO_CUR(LEOCmdReadTimer)->hour = rtc[3];
    LEO_CUR(LEOCmdReadTimer)->minute = rtc[4];
    LEO_CUR(LEOCmdReadTimer)->second = rtc[5];
    if (sense != 0) {
        LEO_CUR(LEOCmdHeader)->sense_code = sense;
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    LEO_CUR(LEOCmdReadTimer)->yearhi = (LEO_CUR(LEOCmdReadTimer)->yearlo < 0x96) ? 0x20 : 0x19;
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_800850A0);
#endif

#ifdef NON_MATCHING
// leoSetTimer: validate the BCD date (year, month, day, hour, minute, second), write it, read it back
void func_8008515C(void) {
    LEOCmdReadTimer* cmd = D_800E87D8;
    u8* p = &cmd->yearlo;
    u8 rtc[6];
    u32 prev = 0;  // the field before this one
    u32 prev2 = 0; // the one before that
    u32 v;
    u32 i;
    u8 sense;

    for (i = 0; i < 6; i++) {
        v = p[i];
        if ((v & 0xF) >= 10) {
            goto invalid;
        }
        v -= (v >> 4) * 6;
        if (i == 2) {
            // day: 29 February only in a leap year
            if ((D_800CC2B8[prev] < v) && ((v != 29) || ((prev2 & 3) != 0))) {
                goto invalid;
            }
        }
        if (((i == 1) || (i == 2)) && (v == 0)) {
            goto invalid;
        }
        if (D_800CC2B0[i] < v) {
            goto invalid;
        }
        prev2 = prev;
        prev = v;
    }
    rtc[0] = cmd->yearlo;
    rtc[1] = cmd->month;
    rtc[2] = cmd->day;
    rtc[3] = cmd->hour;
    rtc[4] = cmd->minute;
    rtc[5] = cmd->second;
    if ((sense = func_80085504(rtc)) != 0) {
        LEO_CUR(LEOCmdHeader)->sense_code = sense;
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    if ((sense = func_80085394(rtc)) != 0) {
        LEO_CUR(LEOCmdHeader)->sense_code = sense;
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    cmd = D_800E87D8;
    if ((cmd->yearlo != rtc[0]) || (cmd->month != rtc[1]) || (cmd->day != rtc[2]) ||
        (cmd->hour != rtc[3]) || (cmd->minute != rtc[4]) || (cmd->second != rtc[5])) {
        cmd->header.sense_code = 0x24;
        LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    cmd->header.status = LEO_STATUS_GOOD;
    return;

invalid:
    cmd->header.sense_code = 0x24; // invalid field
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_8008515C);
#endif

#ifdef NON_MATCHING
// read the RTC: year, month, day, hour, minute, second
u8 func_80085394(u8* rtc) {
    u32 data;
    u8 sense;

    if ((sense = func_80080EA8(0x140000, 0)) != 0) {
        return sense;
    }
    osEPiReadIo(D_800EA150, 0x05000500, &data);
    rtc[4] = (data & 0xFF000000) >> 24;
    rtc[5] = (data & 0xFF0000) >> 16;
    if ((sense = func_80080EA8(0x130000, 0)) != 0) {
        rtc[4] &= 0xFF7F;
        return sense;
    }
    osEPiReadIo(D_800EA150, 0x05000500, &data);
    rtc[2] = (data & 0xFF000000) >> 24;
    rtc[3] = (data & 0xFF0000) >> 16;
    if ((sense = func_80080EA8(0x120000, 0)) != 0) {
        rtc[4] &= 0xFF7F;
        return sense;
    }
    osEPiReadIo(D_800EA150, 0x05000500, &data);
    rtc[0] = (data & 0xFF000000) >> 24;
    rtc[1] = (data & 0xFF0000) >> 16;
    if (rtc[4] & 0x80) {
        rtc[4] &= 0xFF7F;
        return 5;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_80085394);
#endif

#ifdef NON_MATCHING
// set the RTC from 6 bytes (year, month, day, hour, minute, second)
u8 func_80085504(u8* rtc) {
    u32 yearMonth = (rtc[0] << 24) + (rtc[1] << 16);
    u32 dayHour = (rtc[2] << 24) + (rtc[3] << 16);
    u32 minSec = (rtc[4] << 24) + (rtc[5] << 16);
    u8 sense;

    if ((sense = func_80080EA8(0xF0000, yearMonth)) != 0) {
        return sense;
    }
    if ((sense = func_80080EA8(0x100000, dayHour)) != 0) {
        return sense;
    }
    if ((sense = func_80080EA8(0x110000, minSec)) != 0) {
        return sense;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/83960", func_80085504);
#endif

INCLUDE_RODATA("asm/nonmatchings/83960", D_800CC2A0);

INCLUDE_RODATA("asm/nonmatchings/83960", D_800CC2B0);

INCLUDE_RODATA("asm/nonmatchings/83960", D_800CC2B8);
