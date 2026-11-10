#include "common.h"

/* 42E40.c's sprite-animation work (func_800429CC's result) */
typedef struct SpriteAnimWork {
    /* 0x00 */ u16 flags;
    /* 0x02 */ s16 frame;
    /* 0x04 */ s16 count;
    /* 0x06 */ u16 attr;
    /* 0x08 */ s16 x;
    /* 0x0A */ s16 y;
    /* 0x0C */ f32 scale;
    /* 0x10 */ s32 file;
    /* 0x14 */ Process* process;
    /* 0x18 */ unk_Struct02* sprite;
} SpriteAnimWork; /* size = 0x1C */

typedef struct MISPos {
    u16 x;
    u16 y;
} MISPos;

typedef struct MISCursor {
    s16 x;
    s16 y;
} MISCursor;

typedef struct MISOffset {
    f32 x;
    f32 y;
} MISOffset;

extern u16 D_800F2CF0[4]; /* pressed buttons per port */
extern char* D_800C5218[]; /* character names */

void* func_800429CC(s16, s16);
void func_80042B10(SpriteAnimWork*);
void func_8004DBD4(s32, s32);
void func_8004E154(void);
s32 func_8004E184(void);
void func_8004B1B8(void);
void func_8004F548(void);
void func_8004F584(s32);
s32 func_8004F628(s32, u16, s16, s16);
/* Defined with s16 coordinates (4E530.c); retail calls it with s32 values and no narrowing at the
   call, so the matching build declares s32 parameters. The host uses the real prototype. */
void func_8004F754(s32, s32, s32);
void func_8004F790(s32 arg0, u8 arg1);
void func_8004F800(s32, s32);
void func_8004F898(s32, u8, u8, u8);
void func_800532E0(void);
void func_800532F4(void);
void func_8005608C(void);
void func_80056380(void);
void func_80056630(void);
void func_800566A4(void);
void func_8005C384(void);
void func_80070D90(s16);
s32 func_800141FC(s16);

void func_800F66F4_MinigameIslandStart(s16 arg0);
void func_800F6728_MinigameIslandStart(omObjData* obj);
void func_800F689C_MinigameIslandStart(omObjData* obj);
void func_800F69D4_MinigameIslandStart(omObjData* obj);
void func_800F6C18_MinigameIslandStart(omObjData* obj);
void func_800F6C90_MinigameIslandStart(s32 i);
void func_800F6D68_MinigameIslandStart(void);
void func_800F6F2C_MinigameIslandStart(void);
s32 func_800F6FB8_MinigameIslandStart(void);
void func_800F7A48_MinigameIslandStart(void);
void func_800F8908_MinigameIslandStart(void);
void func_800F8954_MinigameIslandStart(omObjData* obj);
void func_800F89A0_MinigameIslandStart(void);
void func_800F8CF4_MinigameIslandStart(void);
void func_800F8E54_MinigameIslandStart(void);
void func_800F8EC0_MinigameIslandStart(void);
void func_800F9084_MinigameIslandStart(void);

Object* D_800F90D0_MinigameIslandStart = NULL;
Object* D_800F90D4_MinigameIslandStart = NULL;
Object* D_800F90D8_MinigameIslandStart[6] = { NULL };
Object* D_800F90F0_MinigameIslandStart[2] = { NULL };
Object* D_800F90F8_MinigameIslandStart = NULL;
Object* D_800F90FC_MinigameIslandStart = NULL;
Object* D_800F9100_MinigameIslandStart = NULL;
omObjData* D_800F9104_MinigameIslandStart = NULL;
omObjData* D_800F9108_MinigameIslandStart = NULL;
omObjData* D_800F910C_MinigameIslandStart = NULL;
/* the chosen characters (player, partner) */
s32 D_800F9110_MinigameIslandStart = -1;
s32 D_800F9114_MinigameIslandStart = -1;
Vec3f D_800F9118_MinigameIslandStart = { -174.0f, 0.0f, 1247.0f };
Vec3f D_800F9124_MinigameIslandStart = { 1800.0f, 0.0f, -9000.0f };
Vec3f D_800F9130_MinigameIslandStart = { 1200.0f, 0.0f, -4000.0f };
Vec3f D_800F913C_MinigameIslandStart = { 900.0f, 0.0f, -3800.0f };
Vec3f D_800F9148_MinigameIslandStart = { 250.0f, 0.0f, 600.0f };
Vec3f D_800F9154_MinigameIslandStart = { 1800.0f, 0.0f, -3800.0f };
Vec3f D_800F9160_MinigameIslandStart = { 10.0f, 0.0f, 1291.0f };
Vec3f D_800F916C_MinigameIslandStart = { 146.0f, 0.0f, 1353.0f };
/* MBModelCreate motion lists */
s32 D_800F9178_MinigameIslandStart[] = { 2, 0x000A0073, 0x000A0074 };
s32 D_800F9184_MinigameIslandStart[] = { 2, 0x00010005, 0x00010001 };
s32 D_800F9190_MinigameIslandStart[] = { 2, 0x00020005, 0x00020001 };
s32 D_800F919C_MinigameIslandStart[] = { 2, 0x00060005, 0x00060001 };
s32 D_800F91A8_MinigameIslandStart[] = { 2, 0x00030005, 0x00030001 };
s32 D_800F91B4_MinigameIslandStart[] = { 2, 0x00040005, 0x00040001 };
s32 D_800F91C0_MinigameIslandStart[] = { 2, 0x00050005, 0x00050001 };
s32* D_800F91CC_MinigameIslandStart[] = {
    D_800F9184_MinigameIslandStart, D_800F9190_MinigameIslandStart, D_800F919C_MinigameIslandStart,
    D_800F91A8_MinigameIslandStart, D_800F91B4_MinigameIslandStart, D_800F91C0_MinigameIslandStart,
};
/* character portraits on screen (D_800F91E6 = .y) */
MISPos D_800F91E4_MinigameIslandStart[] = {
    { 0x5A, 0x4A }, { 0xA0, 0x4A }, { 0xE6, 0x4A }, { 0x5A, 0x90 }, { 0xA0, 0x90 }, { 0xE6, 0x90 },
};
/* yes / no cursor positions (D_800F91FE = .y) */
MISPos D_800F91FC_MinigameIslandStart[] = { { 0x42, 0xCE }, { 0x60, 0xCE } };
Process* D_800F9204_MinigameIslandStart = NULL;

/* .bss */
extern s32 D_800F9250_MinigameIslandStart; /* window id; retail also reads its low half, D_800F9252 */
extern s32 D_800F9254_MinigameIslandStart; /* window id; retail also reads its low half, D_800F9256 */
extern unkCommonStruct0 D_800F9258_MinigameIslandStart;
extern SpriteAnimWork* D_800F92C0_MinigameIslandStart[6];
extern s32 D_800F92D8_MinigameIslandStart;
extern s32 D_800F92DC_MinigameIslandStart; /* cursor */
extern omObjData* D_800F92E0_MinigameIslandStart;
extern MISOffset D_800F92E4_MinigameIslandStart;
extern MISCursor D_800F92EC_MinigameIslandStart;
extern MISCursor D_800F92F0_MinigameIslandStart;
extern MISCursor D_800F92F4_MinigameIslandStart;
extern Vec3f D_800F92F8_MinigameIslandStart;
extern Vec3f D_800F9304_MinigameIslandStart;
extern Vec3f D_800F9310_MinigameIslandStart;
extern f32 D_800F931C_MinigameIslandStart;
extern f32 D_800F9320_MinigameIslandStart;
extern f32 D_800F9324_MinigameIslandStart;

#define WIN0 ((s16)D_800F9250_MinigameIslandStart)
#define WIN1 ((s16)D_800F9254_MinigameIslandStart)
#define BTN (D_800F2CF0[GwPlayer[0].port])
#define DEG2RAD 0.017453292519943295

void func_800F65E0_MinigameIslandStart(void) {
    s32 i;
    s32 j;
    s32 k;

    for (i = 0; i < 4; i++) {
        if (func_800141FC(i) != 0) {
            break;
        }
    }
    i = (i == 4) ? 0 : i;
    GwPlayer[0].port = i;
    for (j = 0, k = 1; j < 4; j++) {
        if (i != j) {
            GwPlayer[k].port = j;
            k++;
        }
    }
    GwPlayer[0].flags = 0;
    omInitObjMan(0x32, 0xA);
    func_800F8EC0_MinigameIslandStart();
    func_800F89A0_MinigameIslandStart();
    func_8006CEA0();
    func_800532E0();
    omAddPrcObj(func_800F7A48_MinigameIslandStart, 0x300, 0x2000, 0);
    omAddObj(0x1000, 0, 0, -1, func_800F8954_MinigameIslandStart);
    func_80060128(0x11);
    SetFadeInTypeAndTime(2, 0x10);
}

void func_800F66F4_MinigameIslandStart(s16 arg0) {
    s16 thing = 1 << GwPlayer[0].port;
    func_8007155C(arg0, thing);
}

void func_800F6728_MinigameIslandStart(omObjData* obj) {
    Object* models[8] = {
        D_800F90D8_MinigameIslandStart[0], D_800F90D8_MinigameIslandStart[1], D_800F90D8_MinigameIslandStart[2],
        D_800F90D8_MinigameIslandStart[3], D_800F90D8_MinigameIslandStart[4], D_800F90D8_MinigameIslandStart[5],
        D_800F90F0_MinigameIslandStart[0], D_800F90F0_MinigameIslandStart[1],
    };

    D_800F90D4_MinigameIslandStart->unk_30 = sinf(obj->trans.x * DEG2RAD) * 10.0f;
    obj->trans.x += 5.0f;
    if (obj->trans.x >= 360.0f) {
        obj->trans.x -= 360.0f;
    }
    if (D_800F9108_MinigameIslandStart != NULL) {
        models[D_800F9108_MinigameIslandStart->mdlcnt]->unk_30 = D_800F90D4_MinigameIslandStart->unk_30;
        models[D_800F9108_MinigameIslandStart->mtncnt]->unk_30 = D_800F90D4_MinigameIslandStart->unk_30;
    }
}

void func_800F689C_MinigameIslandStart(omObjData* obj) {
    D_800F90FC_MinigameIslandStart->unk_18.x = sinf(obj->trans.x * DEG2RAD);
    D_800F90FC_MinigameIslandStart->unk_18.z = cosf(obj->trans.x * DEG2RAD);
    D_800F9100_MinigameIslandStart->unk_18.x = sinf(obj->trans.y * DEG2RAD);
    D_800F9100_MinigameIslandStart->unk_18.z = cosf(obj->trans.y * DEG2RAD);
    obj->trans.x += 1.0f;
    obj->trans.y -= 1.0f;
    if (obj->trans.x >= 360.0f) {
        obj->trans.x -= 360.0f;
    }
    if (obj->trans.y <= -360.0f) {
        obj->trans.y += 360.0f;
    }
}

/* the two shown characters (mdlcnt, mtncnt) circle the boat */
void func_800F69D4_MinigameIslandStart(omObjData* obj) {
    Object* pair[2];
    Object* models[8] = {
        D_800F90D8_MinigameIslandStart[0], D_800F90D8_MinigameIslandStart[1], D_800F90D8_MinigameIslandStart[2],
        D_800F90D8_MinigameIslandStart[3], D_800F90D8_MinigameIslandStart[4], D_800F90D8_MinigameIslandStart[5],
        D_800F90F0_MinigameIslandStart[0], D_800F90F0_MinigameIslandStart[1],
    };
    f32 angle;
    f32 a;
    f32 b;
    s32 i;

    pair[0] = models[obj->mdlcnt];
    pair[1] = models[obj->mtncnt];
    for (i = 0; i < 2; i++) {
        pair[i]->unk_18.x = D_800F90D4_MinigameIslandStart->unk_18.x;
        pair[i]->unk_18.y = D_800F90D4_MinigameIslandStart->unk_18.y;
        pair[i]->unk_18.z = D_800F90D4_MinigameIslandStart->unk_18.z;
    }
    angle = func_8003D2B0(&D_800F90D4_MinigameIslandStart->unk_18);
    pair[0]->coords.x = D_800F90D4_MinigameIslandStart->coords.x + sinf(a = angle * DEG2RAD) * 100.0f;
    pair[0]->coords.y = D_800F90D4_MinigameIslandStart->coords.y;
    pair[0]->coords.z = D_800F90D4_MinigameIslandStart->coords.z + cosf(a) * 100.0f;
    pair[1]->coords.x = D_800F90D4_MinigameIslandStart->coords.x + sinf(b = (angle + 180.0f) * DEG2RAD) * 100.0f;
    pair[1]->coords.y = D_800F90D4_MinigameIslandStart->coords.y;
    pair[1]->coords.z = D_800F90D4_MinigameIslandStart->coords.z + cosf(b) * 100.0f;
}

/* cursor bob */
void func_800F6C18_MinigameIslandStart(omObjData* obj) {
    obj->trans.x += 20.0f;
    if (obj->trans.x > 360.0f) {
        obj->trans.x = 0.0f;
    }
    D_800F92E4_MinigameIslandStart.x += func_800AEAC0(obj->trans.x) * 0.75f;
}

void func_800F6C90_MinigameIslandStart(s32 i) {
    if (i == D_800F9110_MinigameIslandStart) {
        D_800F92C0_MinigameIslandStart[i] = func_800429CC(i, 0x80);
        func_8006752C(D_800F92C0_MinigameIslandStart[i]->sprite->unk_0A, 0, 0x40);
    } else {
        D_800F92C0_MinigameIslandStart[i] = func_800429CC(i, 0);
    }
    D_800F92C0_MinigameIslandStart[i]->flags |= 2;
    D_800F92C0_MinigameIslandStart[i]->x = D_800F91E4_MinigameIslandStart[i].x;
    D_800F92C0_MinigameIslandStart[i]->y = D_800F91E4_MinigameIslandStart[i].y;
    D_800F92C0_MinigameIslandStart[i]->attr = 0x10;
}

void func_800F6D68_MinigameIslandStart(void) {
    omObjData* obj;
    s32 i;

    D_800F9250_MinigameIslandStart = CreateTextWindow(0x2E, 0x14, 0x14, 0xB);
    func_8006E154(WIN0, 0xFF);
    D_800F9254_MinigameIslandStart = CreateTextWindow(0x3C, 0xB8, 0x11, 2);
    if (D_800F9110_MinigameIslandStart == -1) {
        LoadStringIntoWindow(WIN1, (void*)0x4BD, -1, -1);
    } else {
        LoadStringIntoWindow(WIN1, (void*)0x4C1, -1, -1);
    }
    func_8006E070(WIN1, 0);
    if (D_800F9110_MinigameIslandStart == -1) {
        GMesFontMesCreate(&D_800F9258_MinigameIslandStart, "PLAYER  SELECT", 0, -1, -1);
    } else {
        GMesFontMesCreate(&D_800F9258_MinigameIslandStart, "COM  SELECT", 0, -1, -1);
    }
    func_80066DC4(D_800F9258_MinigameIslandStart.unk_14[0], 0, 0xA0, 0x1E);
    for (i = 0; i < 6; i++) {
        func_800F6C90_MinigameIslandStart(i);
    }
    D_800F92DC_MinigameIslandStart = 0;
    if (D_800F9110_MinigameIslandStart == 0) {
        D_800F92DC_MinigameIslandStart = 1;
    }
    D_800F92D8_MinigameIslandStart = func_8004F628(0x85, 2, D_800F91E4_MinigameIslandStart[D_800F92DC_MinigameIslandStart].x - 0x22,
                                                   D_800F91E4_MinigameIslandStart[D_800F92DC_MinigameIslandStart].y + 2);
    obj = omAddObj(0x1000, 0, 0, -1, func_800F6C18_MinigameIslandStart);
    D_800F92E0_MinigameIslandStart = obj;
    obj->trans.x = 0.0f;
}

void func_800F6F2C_MinigameIslandStart(void) {
    s32 i;

    func_80070D90(WIN0);
    func_80070D90(WIN1);
    func_80077044(&D_800F9258_MinigameIslandStart);
    for (i = 0; i < 6; i++) {
        func_80042B10(D_800F92C0_MinigameIslandStart[i]);
    }
    func_8004F584(D_800F92D8_MinigameIslandStart);
    omDelObj(D_800F92E0_MinigameIslandStart);
}

#define CUR D_800F92DC_MinigameIslandStart
#define POS D_800F91E4_MinigameIslandStart
#define YN D_800F91FC_MinigameIslandStart
#define AT D_800F92EC_MinigameIslandStart
#define TO D_800F92F0_MinigameIslandStart
#define STEP D_800F92F4_MinigameIslandStart
#define BOB D_800F92E4_MinigameIslandStart

// block layout (A/B handler and message tails placed differently) and s8 vs s7 register use (masked ~30)
#ifdef NON_MATCHING
/* character select cursor: returns 1 when a character was confirmed, 0 when cancelled */
s32 func_800F6FB8_MinigameIslandStart(void) {
    s32 prev;
    s32 cancel;
    s32 sel;

    BOB.x = 0.0f;
    BOB.y = 0.0f;
    AT.x = POS[CUR].x - 0x22;
    AT.y = POS[CUR].y + 2;
retarget:
    TO.x = POS[CUR].x - 0x22;
    TO.y = POS[CUR].y + 2;
    STEP.x = (TO.x - AT.x) / 5;
    STEP.y = (TO.y - AT.y) / 5;
    while (1) {
        if (AT.x != TO.x || AT.y != TO.y) {
            AT.x += STEP.x;
            AT.y += STEP.y;
        } else {
            if (BTN & 0x8000) {
                PlaySound(0xF6);
                cancel = 0;
                goto setup;
            }
            if (BTN & 0x4000) {
                PlaySound(0xF8);
                cancel = 1;
                goto setup;
            }
            prev = CUR;
            if (BTN & 0x800) {
            up:
                CUR -= 3;
                if (CUR < 0) {
                    CUR += 6;
                }
                if (CUR == D_800F9110_MinigameIslandStart) {
                    goto up;
                }
            } else if (BTN & 0x400) {
            down:
                CUR += 3;
                if (CUR >= 6) {
                    CUR -= 6;
                }
                if (CUR == D_800F9110_MinigameIslandStart) {
                    goto down;
                }
            }
            if (BTN & 0x200) {
            left:
                CUR--;
                if (CUR == 2) {
                    CUR += 3;
                }
                if (CUR < 0) {
                    CUR += 3;
                }
                if (CUR == D_800F9110_MinigameIslandStart) {
                    goto left;
                }
            } else if (BTN & 0x100) {
            right:
                CUR++;
                if (CUR == 3) {
                    CUR -= 3;
                }
                if (CUR >= 6) {
                    CUR -= 3;
                }
                if (CUR == D_800F9110_MinigameIslandStart) {
                    goto right;
                }
            }
            if (prev != CUR) {
                TO.x = POS[CUR].x - 0x22;
                TO.y = POS[CUR].y + 2;
                STEP.x = (TO.x - AT.x) / 5;
                STEP.y = (TO.y - AT.y) / 5;
                PlaySound(0xF5);
            }
        }
        func_8004F754(D_800F92D8_MinigameIslandStart, AT.x + BOB.x, AT.y + BOB.y);
        HuPrcVSleep();
    }
check:
    if (cancel != 0) {
        if (D_800F9110_MinigameIslandStart != -1) {
            return 0;
        }
        func_8006EB40(WIN1);
        LoadStringIntoWindow(WIN1, (void*)0x4CB, -1, -1);
        func_8006E070(WIN1, 0);
        while (1) {
            if (AT.x != TO.x || AT.y != TO.y) {
                AT.x += STEP.x;
                AT.y += STEP.y;
            } else {
                if (BTN & 0x8000) {
                    PlaySound(0xF6);
                    if (sel == 0) {
                        return 0;
                    }
                    goto back;
                }
                if (BTN & 0x4000) {
                    PlaySound(0xF8);
                back:
                    func_8006EB40(WIN1);
                    if (D_800F9110_MinigameIslandStart == -1) {
                        LoadStringIntoWindow(WIN1, (void*)0x4BD, -1, -1);
                    } else {
                        LoadStringIntoWindow(WIN1, (void*)0x4C1, -1, -1);
                    }
                    goto retarget;
                }
                if (BTN & 0x300) {
                    sel = (sel + 1) & 1;
                    TO.x = YN[sel].x;
                    TO.y = YN[sel].y;
                    STEP.x = (TO.x - AT.x) / 5;
                    STEP.y = (TO.y - AT.y) / 5;
                    PlaySound(0xF5);
                }
            }
            func_8004F754(D_800F92D8_MinigameIslandStart, AT.x + BOB.x, AT.y + BOB.y);
            HuPrcVSleep();
        }
    }
    if (0) {
    setup:
        sel = 0;
        TO.x = YN[0].x;
        TO.y = YN[0].y;
        STEP.x = (TO.x - AT.x) / 5;
        STEP.y = (TO.y - AT.y) / 5;
        goto check;
    }
    {
        SpriteAnimWork** spr = &D_800F92C0_MinigameIslandStart[CUR];

        (*spr)->flags &= ~2;
        (*spr)->flags &= ~4;
    }
    func_8006EB40(WIN1);
    LoadStringIntoWindow(WIN1, (void*)0x4BE, -1, -1);
    func_8006E070(WIN1, 0);
    while (1) {
        if (AT.x != TO.x || AT.y != TO.y) {
            AT.x += STEP.x;
            AT.y += STEP.y;
        } else {
            if (BTN & 0x8000) {
                PlaySound(0xF6);
                if (sel != 0) {
                    goto again;
                }
                if (D_800F9110_MinigameIslandStart == -1) {
                    func_800503B0(0, 2);
                }
                return 1;
            }
            if (BTN & 0x4000) {
                PlaySound(0xF8);
            again:
                D_800F92C0_MinigameIslandStart[CUR]->flags |= 4;
                func_8006EB40(WIN1);
                if (D_800F9110_MinigameIslandStart == -1) {
                    LoadStringIntoWindow(WIN1, (void*)0x4BD, -1, -1);
                } else {
                    LoadStringIntoWindow(WIN1, (void*)0x4C1, -1, -1);
                }
                goto retarget;
            }
            if (BTN & 0x300) {
                PlaySound(0xF5);
                sel = (sel + 1) & 1;
                TO.x = YN[sel].x;
                TO.y = YN[sel].y;
                STEP.x = (TO.x - AT.x) / 5;
                STEP.y = (TO.y - AT.y) / 5;
            }
        }
        func_8004F754(D_800F92D8_MinigameIslandStart, AT.x + BOB.x, AT.y + BOB.y);
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_78_MinigameIslandStart/2FD940", func_800F6FB8_MinigameIslandStart);
#endif

#define P1 D_800F9110_MinigameIslandStart
#define P2 D_800F9114_MinigameIslandStart
#define CHR D_800F90D8_MinigameIslandStart
#define BOAT D_800F90D4_MinigameIslandStart
#define GUIDE D_800F90D0_MinigameIslandStart

void func_800F7A48_MinigameIslandStart(void) {
    s32 spr[3];
    s16 win;
    s32 i;
    s32 result;

    HuPrcSleep(0x33);
loop:
    func_8004CCD0(&BOAT->coords, &D_800F9130_MinigameIslandStart, &BOAT->unk_18);
    func_8004E3E0(0, &D_800F9130_MinigameIslandStart, 0x46, BOAT);
    MBModelDispOn(D_800F90F0_MinigameIslandStart[0]);
    MBModelDispOn(D_800F90F0_MinigameIslandStart[1]);
    D_800F9108_MinigameIslandStart->mdlcnt = 6;
    D_800F9108_MinigameIslandStart->mtncnt = 7;
    HuPrcSleep(0x28);
    func_8004EE14(0, &BOAT->coords, 0x1E, GUIDE);
    func_8004F4D4(GUIDE, 0, 2);
    HuPrcSleep(0x1E);
    func_8004F4D4(GUIDE, -1, 2);
    win = CreateTextWindow(0x50, 0x3C, 0xD, 2);
    LoadStringIntoWindow(win, (void*)0x4BC, -1, -1);
    func_8006E070(win, 0);
    ShowTextWindow(win);
    PlaySound(0x432);
    func_8004DBD4(win, 0);
    HideTextWindow(win);
    func_800F6D68_MinigameIslandStart();
    result = func_800F6FB8_MinigameIslandStart();
    func_800F6F2C_MinigameIslandStart();
    if (result == 0) {
        func_8004EE14(0, &D_800F9124_MinigameIslandStart, 0x32, BOAT);
        HuPrcSleep(0x32);
        func_8004E3E0(0, &D_800F9124_MinigameIslandStart, 0x46, BOAT);
        win = CreateTextWindow(0x50, 0x3C, 0xB, 1);
        LoadStringIntoWindow(win, (void*)0x4CC, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        PlaySound(0x437);
        func_8004DBD4(win, 0);
        HideTextWindow(win);
        func_8005C384();
    } else {
        P1 = CUR;
        GwPlayer[0].character = GwQuest.charNo = P1;
        MBModelDispOff(D_800F90F0_MinigameIslandStart[0]);
        MBModelDispOn(CHR[P1]);
        D_800F9108_MinigameIslandStart->mdlcnt = P1;
        func_800A0D00(&CHR[P1]->coords, D_800F90F0_MinigameIslandStart[0]->coords.x,
                      D_800F90F0_MinigameIslandStart[0]->coords.y, D_800F90F0_MinigameIslandStart[0]->coords.z);
        CHR[P1]->unk_18.x = D_800F90F0_MinigameIslandStart[0]->unk_18.x;
        CHR[P1]->unk_18.z = D_800F90F0_MinigameIslandStart[0]->unk_18.z;
        win = CreateTextWindow(0x50, 0x3C, 0xF, 2);
        func_8006DA5C(win, D_800C5218[P1], 0);
        LoadStringIntoWindow(win, (void*)0x4BF, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        PlaySound(0x437);
        func_8004DBD4(win, 0);
        HideTextWindow(win);
        func_8004EE14(0, &D_800F913C_MinigameIslandStart, 0xF, BOAT);
        func_8004E3E0(0, &D_800F913C_MinigameIslandStart, 0x1E, BOAT);
        for (i = 0; i < 0x1E; i++) {
            func_8004CCD0(&GUIDE->coords, &CHR[P1]->coords, &GUIDE->unk_18);
            HuPrcVSleep();
        }
        win = CreateTextWindow(0x50, 0x3C, 0xC, 3);
        func_8006DA5C(win, D_800C5218[P1], 0);
        LoadStringIntoWindow(win, (void*)0x4C0, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        PlaySound(0x437);
        func_8004DBD4(win, 0);
        HideTextWindow(win);
        func_800F6D68_MinigameIslandStart();
        result = func_800F6FB8_MinigameIslandStart();
        func_800F6F2C_MinigameIslandStart();
        if (result == 0) {
            func_8004EE14(0, &D_800F9154_MinigameIslandStart, 0x1E, BOAT);
            HuPrcSleep(0x1E);
            func_8004E3E0(0, &D_800F9154_MinigameIslandStart, 0x14, BOAT);
            win = CreateTextWindow(0x50, 0x3C, 8, 1);
            LoadStringIntoWindow(win, (void*)0x4CD, -1, -1);
            func_8006E070(win, 0);
            ShowTextWindow(win);
            PlaySound(0x437);
            func_8004DBD4(win, 0);
            HideTextWindow(win);
            MBModelDispOff(CHR[P1]);
            MBModelDispOn(D_800F90F0_MinigameIslandStart[0]);
            D_800F9108_MinigameIslandStart->mdlcnt = 6;
            P1 = -1;
            func_800A0D00(&BOAT->coords, D_800F9124_MinigameIslandStart.x, D_800F9124_MinigameIslandStart.y,
                          D_800F9124_MinigameIslandStart.z);
            goto loop;
        }
        P2 = CUR;
        GwPlayer[1].character = GwQuest.charNoTeam = P2;
        MBModelDispOff(D_800F90F0_MinigameIslandStart[1]);
        MBModelDispOn(CHR[P2]);
        D_800F9108_MinigameIslandStart->mtncnt = P2;
        func_800A0D00(&CHR[P2]->coords, D_800F90F0_MinigameIslandStart[1]->coords.x,
                      D_800F90F0_MinigameIslandStart[1]->coords.y, D_800F90F0_MinigameIslandStart[1]->coords.z);
        CHR[P2]->unk_18.x = D_800F90F0_MinigameIslandStart[1]->unk_18.x;
        CHR[P2]->unk_18.z = D_800F90F0_MinigameIslandStart[1]->unk_18.z;
        win = CreateTextWindow(0x50, 0x3C, 0xB, 2);
        func_8006DA5C(win, D_800C5218[P1], 0);
        func_8006DA5C(win, D_800C5218[P2], 1);
        LoadStringIntoWindow(win, (void*)0x4C2, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        PlaySound(0x432);
        func_8004DBD4(win, 0);
        HideTextWindow(win);
        func_8004EE14(0, &D_800F9148_MinigameIslandStart, 0x14, BOAT);
        func_8004E3E0(0, &D_800F9148_MinigameIslandStart, 0x3C, BOAT);
        for (i = 0; i < 0x3C; i++) {
            func_8004CCD0(&GUIDE->coords, &CHR[P1]->coords, &GUIDE->unk_18);
            HuPrcVSleep();
        }
        omDelObj(D_800F9108_MinigameIslandStart);
        D_800F9108_MinigameIslandStart = NULL;
        func_80060618(0x451, 0);
        func_80060618(0x451, 1);
        CHR[P1]->unk_0A &= ~1;
        CHR[P2]->unk_0A &= ~1;
        func_8004F00C(CHR[P1], 40.0f, -3.0f);
        func_8004F00C(CHR[P2], 40.0f, -3.0f);
        func_8004E3E0(0, &D_800F9160_MinigameIslandStart, 0x18, CHR[P1]);
        func_8004E3E0(0, &D_800F916C_MinigameIslandStart, 0x18, CHR[P2]);
        func_8004F4D4(CHR[P1], 0, 0);
        func_8004F4D4(CHR[P2], 0, 0);
        for (i = 0; i < 0x18; i++) {
            func_8004CCD0(&GUIDE->coords, &CHR[P1]->coords, &GUIDE->unk_18);
            HuPrcVSleep();
        }
        func_800503B0(0, 1);
        func_8004F4D4(CHR[P1], 1, 2);
        func_8004F4D4(CHR[P2], 1, 2);
        func_8004EE14(0, &GUIDE->coords, 0x14, CHR[P1]);
        func_8004EE14(0, &GUIDE->coords, 0x14, CHR[P2]);
        HuPrcSleep(0x14);
        func_8004F4D4(CHR[P1], -1, 2);
        func_8004F4D4(CHR[P2], -1, 2);
        win = CreateTextWindow(0x50, 0x3C, 0xA, 3);
        LoadStringIntoWindow(win, (void*)0x4C3, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        PlaySound(0x437);
        func_8004DBD4(win, 0);
        func_8006EB40(win);
        LoadStringIntoWindow(win, (void*)0x4C4, -1, -1);
        func_8006E070(win, 0);
        while (func_8006FCC0(win) != 0) {
            HuPrcVSleep();
        }
        func_800F66F4_MinigameIslandStart(win);
        result = func_8006FCF0(win, 0, 1);
        HideTextWindow(win);
        if (result == 0) {
            win = CreateTextWindow(0x50, 0x3C, 0xD, 4);
            LoadStringIntoWindow(win, (void*)0x4C5, -1, -1);
            func_8006E070(win, 0);
            ShowTextWindow(win);
            PlaySound(0x437);
            func_8004DBD4(win, 0);
            HideTextWindow(win);
            spr[0] = func_8004F628(0xA00FC, 0x20, 0x64, 0x50);
            spr[2] = func_8004F628(0xA00FD, 0x20, 0x64, 0x50);
            func_8004F790(spr[2], 0xFF);
            func_8004F800(spr[2], 0x1000);
            func_8004F898(spr[2], 0xFF, 0xD3, 0x4F);
            spr[1] = func_8004F628(0xA00F9, 0x10, 0x64, 0x4B);
            win = CreateTextWindow(0x50, 0xA0, 0xE, 3);
            LoadStringIntoWindow(win, (void*)0x4C6, -1, -1);
            func_8006E070(win, 0);
            ShowTextWindow(win);
            PlaySound(0x437);
            func_8004DBD4(win, 0);
            func_8004F584(spr[0]);
            func_8004F584(spr[1]);
            func_8004F584(spr[2]);
            HideTextWindow(win);
            func_8005608C();
            win = CreateTextWindow(0x50, 0xA0, 0xF, 3);
            LoadStringIntoWindow(win, (void*)0x4C7, -1, -1);
            func_8006E070(win, 0);
            ShowTextWindow(win);
            PlaySound(0x437);
            func_8004DBD4(win, 0);
            func_80056630();
            HideTextWindow(win);
            func_80056380();
            win = CreateTextWindow(0x46, 0xA0, 0x11, 4);
            LoadStringIntoWindow(win, (void*)0x4C8, -1, -1);
            func_8006E070(win, 0);
            ShowTextWindow(win);
            PlaySound(0x437);
            func_8004DBD4(win, 0);
            func_800566A4();
            HideTextWindow(win);
            spr[0] = func_8004F628(0xA00FC, 0x20, 0x64, 0x50);
            spr[2] = func_8004F628(0xA00FD, 0x20, 0x64, 0x50);
            func_8004F790(spr[2], 0xFF);
            func_8004F800(spr[2], 0x1000);
            func_8004F898(spr[2], 0xFF, 0xD3, 0x4F);
            spr[1] = func_8004F628(0xA00FB, 0x10, 0x64, 0x4B);
            win = CreateTextWindow(0x50, 0xA0, 0x12, 3);
            LoadStringIntoWindow(win, (void*)0x4C9, -1, -1);
            func_8006E070(win, 0);
            ShowTextWindow(win);
            PlaySound(0x437);
            func_8004DBD4(win, 0);
            func_8004F584(spr[0]);
            func_8004F584(spr[1]);
            func_8004F584(spr[2]);
            HideTextWindow(win);
        }
        win = CreateTextWindow(0x50, 0x3C, 0xD, 3);
        LoadStringIntoWindow(win, (void*)0x4CA, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        PlaySound(0x432);
        func_8004DBD4(win, 0);
        HideTextWindow(win);
    }
    D_800F5144 = 1;
    while (1) {
        HuPrcVSleep();
    }
}

void func_800F8908_MinigameIslandStart(void) {
    if (func_80072718() == 0) {
        func_800F9084_MinigameIslandStart();
        func_800F8CF4_MinigameIslandStart();
        func_80070ED4();
        func_800532F4();
        omOvlReturnEx(1);
    }
}

void func_800F8954_MinigameIslandStart(omObjData* obj) {
    if (D_800F5144 != 0) {
        func_800726AC(2, 0x10);
        func_800601D4(0x20);
        obj->func_ptr = &func_800F8908_MinigameIslandStart;
    }
}

void func_800F89A0_MinigameIslandStart(void) {
    s32 i;

    MBModelInit();
    func_8004F2AC();
    func_8004F548();
    func_8004E154();
    D_800F524C = 0.0f;
    D_800F5028 = 0.0f;
    for (i = 0; i < 2; i++) {
        GwPlayer[0].character = 0;
        D_800F90F0_MinigameIslandStart[i] = MBModelCreate(0, NULL);
        MBModelDispOff(D_800F90F0_MinigameIslandStart[i]);
        func_8003E174(D_800F90F0_MinigameIslandStart[i]);
    }
    D_800F524C = 1.0f;
    D_800F5028 = 1.0f;
    for (i = 0; i < 6; i++) {
        GwPlayer[0].character = i;
        CHR[i] = MBModelCreate(func_80052F04(0), D_800F91CC_MinigameIslandStart[i]);
        MBModelDispOff(CHR[i]);
        CHR[i]->unk_0A |= 1;
        func_80021B14(*CHR[i]->unk_3C->unk_40, i, 0x80);
    }
    HuPrcSleep(5);
    GUIDE = MBModelCreate(0x83, D_800F9178_MinigameIslandStart);
    func_800A0D00(&GUIDE->coords, D_800F9118_MinigameIslandStart.x, D_800F9118_MinigameIslandStart.y,
                  D_800F9118_MinigameIslandStart.z);
    BOAT = MBModelCreate(0x84, NULL);
    func_800A0D00(&BOAT->coords, D_800F9124_MinigameIslandStart.x, D_800F9124_MinigameIslandStart.y,
                  D_800F9124_MinigameIslandStart.z);
    BOAT->unk_0A |= 1;
    D_800F90FC_MinigameIslandStart = MBModelCreate(0x71, NULL);
    func_800A0D00(&D_800F90FC_MinigameIslandStart->coords, 0.0f, -20.0f, -4000.0f);
    func_800A0D00((Vec3f*)&D_800F90FC_MinigameIslandStart->xScale, 10.0f, 0.5f, 10.0f);
    D_800F9100_MinigameIslandStart = MBModelCreate(0x71, NULL);
    func_800A0D00(&D_800F9100_MinigameIslandStart->coords, 250.0f, -20.0f, 600.0f);
    func_800A0D00((Vec3f*)&D_800F9100_MinigameIslandStart->xScale, 1.0f, 0.5f, 1.0f);
    func_800258EC(*D_800F90FC_MinigameIslandStart->unk_3C->unk_40, 0x80000, 0x80000);
    func_80025AD4(*D_800F90FC_MinigameIslandStart->unk_3C->unk_40);
    func_800258EC(*D_800F9100_MinigameIslandStart->unk_3C->unk_40, 0x80000, 0x80000);
    func_80025AD4(*D_800F9100_MinigameIslandStart->unk_3C->unk_40);
    D_800F9104_MinigameIslandStart = omAddObj(0x1000, 0, 0, -1, func_800F689C_MinigameIslandStart);
    D_800F9104_MinigameIslandStart->trans.x = 0.0f;
    D_800F9104_MinigameIslandStart->trans.y = 0.0f;
    D_800F9108_MinigameIslandStart = omAddObj(-0x8000, 0, 0, -1, func_800F69D4_MinigameIslandStart);
    D_800F9108_MinigameIslandStart->mdlcnt = 6;
    D_800F9108_MinigameIslandStart->mtncnt = 7;
    D_800F910C_MinigameIslandStart = omAddObj(0x1000, 0, 0, -1, func_800F6728_MinigameIslandStart);
    D_800F910C_MinigameIslandStart->trans.x = 0.0f;
}

void func_800F8CF4_MinigameIslandStart(void) {
    s32 i;

    if (GUIDE != NULL) {
        MBModelKill(GUIDE);
    }
    if (BOAT != NULL) {
        MBModelKill(BOAT);
    }
    if (D_800F90F8_MinigameIslandStart != NULL) {
        MBModelKill(D_800F90F8_MinigameIslandStart);
    }
    if (D_800F90FC_MinigameIslandStart != NULL) {
        MBModelKill(D_800F90FC_MinigameIslandStart);
    }
    if (D_800F9100_MinigameIslandStart != NULL) {
        MBModelKill(D_800F9100_MinigameIslandStart);
    }
    if (D_800F9104_MinigameIslandStart != NULL) {
        omDelObj(D_800F9104_MinigameIslandStart);
    }
    if (D_800F9108_MinigameIslandStart != NULL) {
        omDelObj(D_800F9108_MinigameIslandStart);
    }
    if (D_800F910C_MinigameIslandStart != NULL) {
        omDelObj(D_800F910C_MinigameIslandStart);
    }
    for (i = 0; i < 6; i++) {
        if (CHR[i] != NULL) {
            MBModelKill(CHR[i]);
        }
    }
    for (i = 0; i < 2; i++) {
        if (D_800F90F0_MinigameIslandStart[i] != NULL) {
            MBModelKill(D_800F90F0_MinigameIslandStart[i]);
        }
    }
    func_8004F2EC();
    func_8004F5F0();
    func_8004E184();
}

void func_800F8E54_MinigameIslandStart(void) {
    while (1) {
        func_8001D494(0, D_800F9324_MinigameIslandStart, D_800F931C_MinigameIslandStart, D_800F9320_MinigameIslandStart);
        func_8001D420(0, &D_800F92F8_MinigameIslandStart, &D_800F9304_MinigameIslandStart, &D_800F9310_MinigameIslandStart);
        func_8001D57C(0);
        HuPrcVSleep();
    }
}

void func_800F8EC0_MinigameIslandStart(void) {
    Process* proc;

    func_800178A0(1);
    func_80017660(0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    LoadBackgroundData(FE2310_ROM_START);
    LoadBackgroundIndex(0x54);
    func_8004B1B8();
    D_800F92F8_MinigameIslandStart.x = 0.0f;
    D_800F92F8_MinigameIslandStart.y = 230.0f;
    D_800F92F8_MinigameIslandStart.z = 2500.0f;
    D_800F9304_MinigameIslandStart.x = 0.0f;
    D_800F9304_MinigameIslandStart.y = 0.0f;
    D_800F9304_MinigameIslandStart.z = 0.0f;
    D_800F9310_MinigameIslandStart.x = 0.0f;
    D_800F9310_MinigameIslandStart.y = 1.0f;
    D_800F9310_MinigameIslandStart.z = 0.0f;
    D_800F9324_MinigameIslandStart = 20.0f;
    D_800F931C_MinigameIslandStart = 80.0f;
    D_800F9320_MinigameIslandStart = 10000.0f;
    proc = omAddPrcObj(func_800F8E54_MinigameIslandStart, 0x1001, 0, 0);
    D_800F9204_MinigameIslandStart = proc;
    omPrcSetStatBit(proc, 0x80);
    func_8001D494(0, 20.0f, 80.0f, 4000.0f);
    func_8001D420(0, &D_800F92F8_MinigameIslandStart, &D_800F9304_MinigameIslandStart, &D_800F9310_MinigameIslandStart);
    func_8001D57C(0);
}

void func_800F9084_MinigameIslandStart(void) {
    func_8004A140();
    func_80049F0C();
    if (D_800F9204_MinigameIslandStart != NULL) {
        EndProcess(D_800F9204_MinigameIslandStart);
        D_800F9204_MinigameIslandStart = NULL;
    }
}
