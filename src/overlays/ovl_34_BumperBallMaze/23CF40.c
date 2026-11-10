#include "common.h"

/* D_800FAE10's work (func_800F6C7C, 0x48 bytes): the player's ball. */
typedef struct BumperBallMazeBallWork {
    /* 0x00 */ u16 unk_00; /* state */
    /* 0x02 */ s16 character;
    /* 0x04 */ u16 player;
    /* 0x06 */ char pad_06[2];
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ u16 unk_3C;
    /* 0x3E */ u16 unk_3E;
    /* 0x40 */ u8 unk_40[2];
    /* 0x42 */ char pad_42[2];
    /* 0x44 */ f32 unk_44;
} BumperBallMazeBallWork; /* size = 0x48 */

/* D_800FAE14's work (func_800F9050, 0x20 bytes): the timer display. */
typedef struct BumperBallMazeTimerWork {
    /* 0x00 */ u16 digits[7];     /* sprites: M, ':', S, S, '.', F, F */
    /* 0x0E */ u16 bestDigits[7];
    /* 0x1C */ u16 time;
    /* 0x1E */ u16 best;
} BumperBallMazeTimerWork; /* size = 0x20 */

typedef struct BumperBallMazeColVtx {
    s16 x;
    s16 y;
    s16 z;
} BumperBallMazeColVtx;

typedef struct BumperBallMazeHitProbe {
    f32 x;
    f32 y;
    f32 z;
    f32 radius;
} BumperBallMazeHitProbe;

/* Floor heights under the ball: eight points 55 units around pos, then pos itself (func_800F8AFC). */
typedef struct BumperBallMazeFloorProbe {
    /* 0x00 */ f32 height[8];
    /* 0x20 */ f32 centerHeight;
    /* 0x24 */ u16 attr[8];
    /* 0x34 */ u16 centerAttr;
    /* 0x36 */ char pad_36[2];
    /* 0x38 */ Vec3f pos;
} BumperBallMazeFloorProbe; /* size = 0x44 */


typedef struct BumperBallMazeCameraPreset {
    f32 cameraValue; /* func_800F96B0's first argument; the frame count for func_800F97B4 */
    f32 zoom;
    Vec3f rot;
    Vec3f center;
} BumperBallMazeCameraPreset;

typedef struct BumperBallMazeScreenPos {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
} BumperBallMazeScreenPos;

/* .bss */
extern s16 D_800FADE0_BumperBallMaze;
extern u16 D_800FADE2_BumperBallMaze; /* the player whose result is shown */
extern f32 D_800FADE4_BumperBallMaze; /* per-frame turn back to 0 degrees */
extern omObjData* D_800FADE8_BumperBallMaze;
/* Ending waits (4 bytes): D_800FADEC counts down, D_800FADEE (an undefined_syms.txt alias for
   retail's separate %lo(D_800FADEC+2) accesses) is the wait that follows. */
extern u16 D_800FADEC_BumperBallMaze;
extern u16 D_800FADEE_BumperBallMaze;
extern u16 D_800FADF0_BumperBallMaze;
extern u16 D_800FADF2_BumperBallMaze;
extern u16 D_800FADF4_BumperBallMaze;
extern u16 D_800FADF6_BumperBallMaze;
extern u16 D_800FADF8_BumperBallMaze; /* maze 0-2 */
extern u16 D_800FADFA_BumperBallMaze;
extern s16 D_800FADFC_BumperBallMaze;
extern s16 D_800FADFE_BumperBallMaze;
extern s16 D_800FAE00_BumperBallMaze;
extern s16 D_800FAE02_BumperBallMaze;
extern omObjData* D_800FAE04_BumperBallMaze; /* the maze */
extern omObjData* D_800FAE08_BumperBallMaze;
extern omObjData* D_800FAE0C_BumperBallMaze;
extern omObjData* D_800FAE10_BumperBallMaze; /* the ball */
extern omObjData* D_800FAE14_BumperBallMaze; /* the timer */
extern f32 D_800FAE18_BumperBallMaze;
extern u16 D_800FB1C0_BumperBallMaze;
extern u16 D_800FB1C2_BumperBallMaze;
extern u16 D_800FB1C4_BumperBallMaze;

extern s8 ContStkY[];

extern const char D_800FACE0_BumperBallMaze[];
extern const char D_800FACEC_BumperBallMaze[];
extern const char D_800FACF8_BumperBallMaze[];
extern const char D_800FAD04_BumperBallMaze[];
extern const char D_800FAD10_BumperBallMaze[];
extern const char D_800FAD1C_BumperBallMaze[];
extern const u8 D_800FAD28_BumperBallMaze[];

/* .data */
s32 D_800FAB00_BumperBallMaze[3] = { 0x00480000, 0x00480001, 0x00480002 }; /* maze models */
Vec3f D_800FAB0C_BumperBallMaze[3] = { /* ball start */
    { -1150.0f, 220.0f, 730.0f },
    { -1150.0f, 220.0f, 730.0f },
    { -1150.0f, 220.0f, 730.0f },
};
f32 D_800FAB30_BumperBallMaze[3] = { 90.0f, 90.0f, 135.0f }; /* ball start heading */
u16 D_800FAB3C_BumperBallMaze[4] = { 3600, 3600, 3600, 0 }; /* time limit (frames) */
BumperBallMazeScreenPos D_800FAB44_BumperBallMaze[3] = { /* best-time digits */
    { 0x2F, 0x18 }, { 0x2F, 0x18 }, { 0x2F, 0x18 },
};
BumperBallMazeScreenPos D_800FAB50_BumperBallMaze[3] = { /* current-time digits */
    { 0xCF, 0x18 }, { 0xCF, 0x18 }, { 0xCF, 0x18 },
};
BumperBallMazeCameraPreset D_800FAB5C_BumperBallMaze[3] = { /* play camera */
    { 45.0f, 1480.0f, { 319.0f, 0.0f, 0.0f }, { -965.0f, 0.0f, 375.0f } },
    { 45.0f, 1480.0f, { 319.0f, 0.0f, 0.0f }, { -965.0f, 0.0f, 375.0f } },
    { 45.0f, 1480.0f, { 319.0f, 0.0f, 0.0f }, { -965.0f, 0.0f, 375.0f } },
};
BumperBallMazeCameraPreset D_800FABBC_BumperBallMaze[3] = { /* intro camera tween */
    { 20.0f, 3400.0f, { 301.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, -35.0f } },
    { 20.0f, 3400.0f, { 301.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, -35.0f } },
    { 20.0f, 3400.0f, { 301.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, -35.0f } },
};
BumperBallMazeCameraPreset D_800FAC1C_BumperBallMaze[3] = { /* goal camera tween */
    { 20.0f, 1600.0f, { 308.0f, 0.0f, 0.0f }, { 1140.0f, 0.0f, -710.0f } },
    { 20.0f, 1600.0f, { 308.0f, 0.0f, 0.0f }, { 1140.0f, 0.0f, -710.0f } },
    { 20.0f, 1600.0f, { 308.0f, 0.0f, 0.0f }, { 1140.0f, 0.0f, -710.0f } },
};
Vec3f D_800FAC7C_BumperBallMaze[3] = { /* goal marker */
    { 1070.0f, 130.0f, -900.0f },
    { 1320.0f, 130.0f, -900.0f },
    { 1070.0f, 130.0f, -900.0f },
};
u8* D_800FACA0_BumperBallMaze[6] = { /* ball texture per character */
    (u8*) D_800FAD1C_BumperBallMaze, (u8*) D_800FAD10_BumperBallMaze, (u8*) D_800FAD04_BumperBallMaze,
    (u8*) D_800FACF8_BumperBallMaze, (u8*) D_800FACEC_BumperBallMaze, (u8*) D_800FACE0_BumperBallMaze,
};
/* Intro countdowns (func_800F827C): frames until the music, then until the start message. */
u16 D_800FACB8_BumperBallMaze = 4;
u16 D_800FACBA_BumperBallMaze = 0x2D;
u16 D_800FACBC_BumperBallMaze = 0x19; /* frames until the intro camera tween */
u16 D_800FACBE_BumperBallMaze = 0;    /* unreferenced filler */
u16 D_800FACC0_BumperBallMaze = 0;    /* set when the minigame ends */
u16 D_800FACC2_BumperBallMaze = 0;    /* unreferenced filler */
/* Water texture scroll (240010.c): s/t of the near edge, of the far edge (+1024), per-frame steps. */
f32 D_800FACC4_BumperBallMaze = 0.0f;
f32 D_800FACC8_BumperBallMaze = 0.0f;
f32 D_800FACCC_BumperBallMaze = 1024.0f;
f32 D_800FACD0_BumperBallMaze = 1024.0f;
f32 D_800FACD4_BumperBallMaze = 12.8f;
f32 D_800FACD8_BumperBallMaze = 12.8f;

/* objmain.c's objmainChr (D_800C59A8[6]); the (chr << 16 | unk06) word is D_800C59AC[c].unk_00. */
typedef struct BumperBallMazeChr {
    /* 0x00 */ s16 index;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s16 chr;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ s32 file0;
    /* 0x0C */ s32 file1;
    /* 0x10 */ f32 scale;
} BumperBallMazeChr; /* size = 0x14 */
extern BumperBallMazeChr D_800C59A8[6];

void func_800FA620_BumperBallMaze(void);
void func_800F9990_BumperBallMaze(void);
void func_800F6C28_BumperBallMaze(void);
void func_800F69F4_BumperBallMaze(omObjData*);
void func_800F9974_BumperBallMaze(s32);
void func_800F6C7C_BumperBallMaze(omObjData*);
s32 func_800F8E1C_BumperBallMaze(BumperBallMazeHitProbe*, u16*, BumperBallMazeColVtx*);
void func_800F928C_BumperBallMaze(u16, u16*);
void func_800F8220_BumperBallMaze(omObjData*);
void func_800594E4(s16, u16);
void func_8001897C(s16, f32, f32, f32);
void func_800F96B0_BumperBallMaze(f32, f32, f32, f32, f32, f32, f32, f32);
void func_800F9768_BumperBallMaze(void);
void func_800F97B4_BumperBallMaze(u16, f32, f32, f32, f32, f32, f32, f32);
void func_800F6994_BumperBallMaze(omObjData*);
void func_800F6BB8_BumperBallMaze(omObjData*);
void func_800F6C44_BumperBallMaze(omObjData*);
void func_800F8184_BumperBallMaze(omObjData*);
void func_800F8AB8_BumperBallMaze(void);
void func_800F9050_BumperBallMaze(omObjData*);
void func_800F827C_BumperBallMaze(omObjData*);
void func_800F8468_BumperBallMaze(omObjData*);
u16 func_800F9278_BumperBallMaze(void);
s32 func_800F9034_BumperBallMaze(void);
void func_800F943C_BumperBallMaze(void);
void func_800F7240_BumperBallMaze(omObjData*);
void func_8001E268(s16, u8, u8);
f32 func_800296FC(f32, f32, BumperBallMazeColVtx*, BumperBallMazeColVtx*);
f32 func_80029764(f32, f32, f32, void*, u16*);
void func_8002AE24(s16, s32*, void*, void*);
u16* func_8002B3A8(s32*);
s32 func_800F8DFC_BumperBallMaze(s32, u16*, BumperBallMazeColVtx*, BumperBallMazeHitProbe*);
u16 func_800F8AFC_BumperBallMaze(BumperBallMazeFloorProbe*);
void func_800F94A0_BumperBallMaze(omObjData*);
void func_800F7BB8_BumperBallMaze(omObjData*);
void func_800F7FE0_BumperBallMaze(omObjData*);
void func_800F8108_BumperBallMaze(omObjData*);
void func_800F7ED0_BumperBallMaze(omObjData*);
void func_800F7F60_BumperBallMaze(omObjData*);
void func_800F9610_BumperBallMaze(s32);
void func_80018DC4(u16, f32);
void func_800F923C_BumperBallMaze(omObjData*);
void func_80060F04(s16 player, s16 arg1, s16 arg2, s16 arg3);
void func_80025BB8(s16, s16);
void func_80027AC8(s16, u8*, u8*);
f32 func_80025D18(s16);
f32 func_80025D40(s16);

void func_800F65E0_BumperBallMaze(void) {
    BumperBallMazeCameraPreset* cam;
    void* data;
    s16 sprite;

    omInitObjMan(0x14, 0);
    func_80060088();
    switch (GwSystem.unk_1E) {
    case 0x24:
        D_800FADF8_BumperBallMaze = 1;
        break;
    case 0x35:
        D_800FADF8_BumperBallMaze = 2;
        break;
    case 0x23:
    default:
        D_800FADF8_BumperBallMaze = 0;
        break;
    }
    func_80029090(2);
    func_8001DE70(0xC);
    func_8002ADF0(&D_800EDEC0, 0x40);
    func_8002890C(0, 0x20, 0x80);
    func_8002578C(1);
    cam = &D_800FAB5C_BumperBallMaze[D_800FADF8_BumperBallMaze];
    func_800F96B0_BumperBallMaze(cam->cameraValue, cam->zoom, cam->rot.x, cam->rot.y, cam->rot.z,
                                 cam->center.x, cam->center.y, cam->center.z);
    func_80017660(0, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    func_80023448(3);
    func_800234B8(0, 0x2C, 0x2C, 0x40);
    func_800234B8(1, 0x60, 0x60, 0x10);
    func_80023504(1, 100.0f, 80.0f, 100.0f);
    func_800234B8(2, 0, 0, 0);
    func_80023504(2, 100.0f, 80.0f, 100.0f);
    func_800234B8(3, 0, 0, 0);
    func_80023504(3, 100.0f, 80.0f, 100.0f);
    D_800FAE10_BumperBallMaze = omAddObj(0x14, 9, 6, -1, func_800F6C44_BumperBallMaze);
    omAddObj(0x28, 1, 0, -1, func_800F8184_BumperBallMaze);
    omAddObj(0, 0, 0, -1, func_800F6994_BumperBallMaze);
    D_800FAE04_BumperBallMaze = omAddObj(6, 2, 0, -1, func_800F6BB8_BumperBallMaze);
    omAddObj(0x2710, 0, 0, -1, func_800F8AB8_BumperBallMaze);
    D_800FAE14_BumperBallMaze = omAddObj(0x28, 0, 0, -1, func_800F9050_BumperBallMaze);
    func_800F9768_BumperBallMaze();
    data = DataRead(0x25);
    D_800FADFC_BumperBallMaze = func_80039084(data);
    HuMemDirectFree(data);
    data = DataRead(0x24);
    D_800FADFE_BumperBallMaze = func_80039084(data);
    HuMemDirectFree(data);
    func_8007B168((u8*) D_800FAD28_BumperBallMaze, 1);
    D_800FAE00_BumperBallMaze = InitSprite(0x87);
    D_800FAE02_BumperBallMaze = sprite = InitSprite(0x87);
    func_8001897C(sprite, 0.0f, 1.0f, 0.0f);
    D_800FB1C4_BumperBallMaze = 0;
    SetFadeInTypeAndTime(0, 0x10);
}

void func_800F6994_BumperBallMaze(omObjData* object) {
    D_800FB1C0_BumperBallMaze = 0;
    D_800FAE0C_BumperBallMaze = NULL;
    D_800FAE08_BumperBallMaze = NULL;
    D_800FADF0_BumperBallMaze = 0;
    D_800FADF2_BumperBallMaze = 1;
    D_800FADF4_BumperBallMaze = 0;
    D_800FADF6_BumperBallMaze = 0;
    D_800FAE18_BumperBallMaze = 0.96f;
    object->func_ptr = func_800F69F4_BumperBallMaze;
}

void func_800F69F4_BumperBallMaze(omObjData* object) {
    BumperBallMazeBallWork* state;

    switch (D_800FB1C0_BumperBallMaze) {
    case 0:
        if (D_800FAE08_BumperBallMaze == NULL) {
            D_800FAE08_BumperBallMaze = omAddObj(4, 0, 0, -1, func_800F827C_BumperBallMaze);
        }
        break;
    case 1:
        D_800FADFA_BumperBallMaze = func_800F9278_BumperBallMaze();
        if (D_800FADF2_BumperBallMaze == 0
            || D_800FADFA_BumperBallMaze >= D_800FAB3C_BumperBallMaze[D_800FADF8_BumperBallMaze]
            || D_800FADF4_BumperBallMaze == 1) {
            func_800601D4(0x28);
            if ((u16) func_800F9034_BumperBallMaze() == 1) {
                D_800FB1C0_BumperBallMaze = 2;
                D_800FB1C2_BumperBallMaze = 4;
                D_800FAE14_BumperBallMaze->work[0] = 0;
            }
            if (D_800FADF4_BumperBallMaze == 1) {
                D_800FB1C0_BumperBallMaze = 2;
                D_800FB1C2_BumperBallMaze = 0xA;
                func_800F943C_BumperBallMaze();
                D_800FAE14_BumperBallMaze->work[0] = 0;
                state = D_800FAE10_BumperBallMaze->unk_50;
                if (state->unk_00 != 3 && state->unk_00 != 4 && state->unk_00 != 5) {
                    state->unk_00 = 6;
                }
            }
        }
        break;
    case 2:
        if (D_800FAE0C_BumperBallMaze == NULL) {
            D_800FAE0C_BumperBallMaze = omAddObj(4, 0, 0, -1, func_800F8468_BumperBallMaze);
        }
        break;
    }
}

void func_800F6BB8_BumperBallMaze(omObjData* object) {
    object->model[0] = LoadFormFile(D_800FAB00_BumperBallMaze[D_800FADF8_BumperBallMaze], 0x289);
    object->model[1] = LoadFormFile(0x380003, 0x48D);
    func_800F9990_BumperBallMaze();
    object->func_ptr = func_800F6C28_BumperBallMaze;
}

void func_800F6C28_BumperBallMaze(void) {
    func_800FA620_BumperBallMaze();
}

void func_800F6C44_BumperBallMaze(omObjData* object) {
    LoadFormFile(0x310002, 0x69D);
    func_800F6C7C_BumperBallMaze(object);
}

const char D_800FACE0_BumperBallMaze[] = "38mt006_DEF";

const char D_800FACEC_BumperBallMaze[] = "38mt005_DEF";

const char D_800FACF8_BumperBallMaze[] = "38mt004_DEF";

const char D_800FAD04_BumperBallMaze[] = "38mt003_DEF";

const char D_800FAD10_BumperBallMaze[] = "38mt002_DEF";

const char D_800FAD1C_BumperBallMaze[] = "38mt001_DEF";

void func_800F6C7C_BumperBallMaze(omObjData* object) {
    BumperBallMazeBallWork* work;
    s32 i;
    s16 player;
    s32 chrBase;
    s8 chr;
    f32 zero;

    for (i = 0; i < 4; i++) {
        if (GwPlayer[i].group == 0) {
            break;
        }
    }
    player = ((u16) i < 4) ? i : 0;
    work = object->unk_50 = func_80023684(0x48, 0x7918);
    work->unk_00 = 0;
    work->player = player;
    work->unk_20 = 50.0f;
    work->unk_1C = 0.0f;
    zero = work->unk_1C;
    work->unk_30 = work->unk_34 = work->unk_38 = work->unk_24 = work->unk_2C = zero;
    work->unk_3C = 0;
    work->unk_44 = zero;
    work->unk_3E = 0;
    for (i = 0; i < 2; i++) {
        work->unk_40[i] = 0;
    }
    chr = GwPlayer[(u16) player].character;
    work->character = chr;
    chrBase = D_800C59AC[chr].unk_00;
    object->model[0] = LoadFormFile(chrBase | D_800C59A8[chr].file0, 0x20699);
    omSetTra(object, D_800FAB0C_BumperBallMaze[D_800FADF8_BumperBallMaze].x,
             D_800FAB0C_BumperBallMaze[D_800FADF8_BumperBallMaze].y,
             D_800FAB0C_BumperBallMaze[D_800FADF8_BumperBallMaze].z);
    if ((u16) D_800C59A8[chr].index == 5) {
        work->unk_08 = 10.0f;
        omSetSca(object, 0.95f, 0.95f, 0.95f);
        omSetTra(object, D_800FAB0C_BumperBallMaze[D_800FADF8_BumperBallMaze].x,
                 D_800FAB0C_BumperBallMaze[D_800FADF8_BumperBallMaze].y - 10.0f,
                 D_800FAB0C_BumperBallMaze[D_800FADF8_BumperBallMaze].z);
    } else {
        work->unk_08 = 0.0f;
        omSetSca(object, 1.0f, 1.0f, 1.0f);
    }
    object->model[1] = func_800174F4(0x20, 0x689);
    func_80025830(object->model[1], 1.25f, 1.25f, 1.25f);
    func_80025798(object->model[1], object->trans.x, 125.0f, object->trans.z);
    object->model[5] = LoadFormFile(0x1A, 0x68D);
    for (i = 0; i < 2; i++) {
        if ((u16) player == 0 && i == 0) {
            object->model[6 + i] = LoadFormFile(0x19, 0x68D);
        } else {
            object->model[6 + i] = func_80023FC8(D_800FAE10_BumperBallMaze->model[6]);
        }
    }
    func_8001775C(object, 0, chrBase);
    func_8001775C(object, 1, chrBase | 1);
    func_8001775C(object, 2, chrBase | 3);
    if (rand8() & 1) {
        func_8001775C(object, 3, chrBase | 0xF);
    } else {
        func_8001775C(object, 3, chrBase | 0x38);
    }
    func_8001775C(object, 4, chrBase | 0x17);
    func_8001775C(object, 5, chrBase | 0x10);
    object->model[4] = func_8001E00C((void*) -1, 0x68D, 8);
    D_800ECDE0[object->model[4]].unk_02 = D_800FADFE_BumperBallMaze;
    func_80025930(D_800ECDE0[object->model[4]].unk_00, 0x40000000, 0x40000000);
    func_8001E268(object->model[4], 4, 4);
    object->model[3] = func_8001E00C((void*) -1, 0x68D, 8);
    D_800ECDE0[object->model[3]].unk_02 = D_800FADFC_BumperBallMaze;
    func_80025930(D_800ECDE0[object->model[3]].unk_00, 0x40000000, 0x40000000);
    func_8001E268(object->model[3], 4, 4);
    object->model[2] = LoadFormFile(0x310001, 0x20689);
    func_80027AC8(object->model[2], (u8*) D_800FAD1C_BumperBallMaze, D_800FACA0_BumperBallMaze[chr]);
    func_80025AD4(object->model[2]);
    work->unk_0C = D_800FAB30_BumperBallMaze[D_800FADF8_BumperBallMaze];
    if (work->unk_0C < 0.0f) {
        work->unk_0C += 360.0f;
    }
    work->unk_34 = work->unk_14 = work->unk_10 = work->unk_0C;
    omSetRot(object, 0.0f, work->unk_0C, 0.0f);
    func_800257E4(object->model[2], work->unk_30, work->unk_34, work->unk_38);
    func_80025798(object->model[2], object->trans.x, object->trans.y + -50.0f + work->unk_08,
                  object->trans.z);
    func_80025BB8(object->model[0], object->motion[0]);
    func_80025EB4(object->model[0], 2, 2);
    object->func_ptr = func_800F7240_BumperBallMaze;
}

/* "ＡＢＣ" (Shift-JIS) */
const u8 D_800FAD28_BumperBallMaze[] = { 0x82, 0x60, 0x82, 0x61, 0x82, 0x62, 0x00, 0x00 };

// float register allocation of the turn-step clamp (step kept apart from the 30.0f compare)
#ifdef NON_MATCHING
void func_800F7240_BumperBallMaze(omObjData* object) {
    BumperBallMazeFloorProbe probe;
    BumperBallMazeBallWork* work;
    s8 stickX;
    s8 stickY;
    u8 port;
    f32 diff;
    f32 speed;
    f32 dx;
    f32 dz;
    u16 misses;

    work = object->unk_50;
    if (D_800FB1C0_BumperBallMaze != 1) {
        return;
    }
    port = GwPlayer[work->player].port;
    stickX = ContStkX[port];
    stickY = ContStkY[port];
    if ((stickX != 0) | (stickY != 0)) {
        diff = func_800B0CD8(stickX, -stickY);
        if (diff < 0.0f) {
            diff += 360.0f;
        }
        work->unk_14 = diff;
    }
    if (work->unk_0C != work->unk_14) {
        diff = work->unk_14 - work->unk_0C;
        if (diff < 0.0f) {
            diff += 360.0f;
        }
        if (diff < 180.0f) {
            work->unk_0C = (diff > 30.0f) ? work->unk_0C + 30.0f : diff + work->unk_0C;
        } else {
            f32 step;

            if (360.0f - diff > 30.0f) {
                step = 30.0f;
            } else {
                step = 360.0f - diff;
            }
            work->unk_0C = work->unk_0C - step;
        }
        if (work->unk_0C < 0.0f) {
            work->unk_0C += 360.0f;
        }
        if (work->unk_0C >= 360.0f) {
            work->unk_0C -= 360.0f;
        }
        omSetRot(object, object->rot.x, work->unk_0C, object->rot.z);
        work->unk_34 = work->unk_0C;
        func_800257E4(object->model[2], work->unk_30, work->unk_34, work->unk_38);
    }
    speed = func_800B1750(stickX * stickX + stickY * stickY) / 100.0f;
    work->unk_24 = func_800AEAC0(work->unk_0C) * speed + work->unk_24;
    work->unk_2C = func_800AEFD0(work->unk_0C) * speed + work->unk_2C;
    work->unk_24 *= D_800FAE18_BumperBallMaze;
    if (fabs(work->unk_24) < 0.01f) {
        work->unk_24 = 0.0f;
    }
    work->unk_2C *= D_800FAE18_BumperBallMaze;
    if (fabs(work->unk_2C) < 0.01f) {
        work->unk_2C = 0.0f;
    }
    probe.pos.x = object->trans.x;
    probe.pos.y = object->trans.y + -100.0f;
    probe.pos.z = object->trans.z;
    misses = func_800F8AFC_BumperBallMaze(&probe);
    if (misses >= 6 && probe.centerHeight == -10000.0f) {
        work->unk_00 = 3;
        if (func_800B1750(work->unk_24 * work->unk_24 + work->unk_2C * work->unk_2C) < 15.0f) {
            diff = func_800B0CD8(object->trans.x, object->trans.z);
            work->unk_24 = func_800AEAC0(diff) * 9.0f + work->unk_24;
            work->unk_2C = func_800AEFD0(diff) * 9.0f + work->unk_2C;
        }
        work->unk_28 = -10.0f;
        D_800FADF2_BumperBallMaze--;
        func_800258EC(object->model[1], 4, 4);
        func_80025C20(object->model[0], func_80025E48(object->motion[4]), 0, 0x1E, 2);
        func_800F94A0_BumperBallMaze(object);
        func_80060618(0x45F, (s16) work->player);
        object->func_ptr = func_800F7BB8_BumperBallMaze;
        return;
    }
    if (misses >= 6 && probe.centerHeight < object->trans.y + -100.0f) {
        object->trans.y = object->trans.y - 10.0f;
    } else if (probe.centerAttr == 0x1200) {
        D_800FADF4_BumperBallMaze = 1;
    }
    if (object->trans.y + -100.0f < probe.centerHeight) {
        object->trans.y = probe.centerHeight - -100.0f;
    }
    if (work->unk_2C != 0.0f || work->unk_24 != 0.0f) {
        work->unk_30 = work->unk_30
            - (f32) (func_800B1750(work->unk_24 * work->unk_24 + work->unk_2C * work->unk_2C) / -50.0f
                     / 3.141592653589793 * 180.0);
        if (work->unk_30 >= 360.0f) {
            work->unk_30 -= 360.0f;
        }
        if (work->unk_30 < 0.0f) {
            work->unk_30 += 360.0f;
        }
    }
    if (fabs(work->unk_2C) + fabs(work->unk_24) > 8.0) {
        if (work->unk_00 != 2) {
            work->unk_00 = 2;
            func_80025C20(object->model[0], func_80025E48(object->motion[2]), 0, 0xA, 2);
            func_80025EB4(object->model[0], 6, 6);
        }
    } else if (fabs(work->unk_2C) + fabs(work->unk_24) > 1.0 || ((stickX != 0) | (stickY != 0))) {
        if (work->unk_00 != 1) {
            work->unk_00 = 1;
            func_80025C20(object->model[0], func_80025E48(object->motion[1]), 0, 0xA, 2);
            func_80025EB4(object->model[0], 6, 6);
        }
    } else if (work->unk_00 == 1 || work->unk_00 == 2) {
        work->unk_00 = 0;
        func_80025C20(object->model[0], func_80025E48(object->motion[0]), 0, 0x1E, 2);
    }
    if (work->unk_3C == 0) {
        if (fabs(work->unk_2C) + fabs(work->unk_24) > 8.0) {
            func_800F7FE0_BumperBallMaze(object);
            work->unk_3C = 3;
        }
    } else {
        work->unk_3C--;
    }
    if (fabs(work->unk_14 - work->unk_10) > 90.0) {
        dx = func_800AEAC0(work->unk_10) * 18.0f;
        dz = func_800AEFD0(work->unk_10) * 18.0f;
        func_800258EC(object->model[5], 4, 0);
        func_80025798(object->model[5], dx + object->trans.x, 125.0f, dz + object->trans.z);
        func_800257E4(object->model[5], object->rot.x, object->rot.y, 0.0f);
        if (D_800F2B7C[object->model[5]].unk_6C->unk_B8 != NULL) {
            D_800F2B7C[object->model[5]].unk_6C->unk_B8->unk_08 = 0;
        }
        func_80025CA8(object->model[5], 0.0f);
    }
    omSetTra(object, object->trans.x + work->unk_24, object->trans.y, object->trans.z + work->unk_2C);
    func_80025798(object->model[2], object->trans.x, object->trans.y + -50.0f + work->unk_08,
                  object->trans.z);
    func_800257E4(object->model[2], work->unk_30, work->unk_34, work->unk_38);
    func_80025798(object->model[1], object->trans.x, 125.0f, object->trans.z);
    work->unk_10 = work->unk_0C;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/23CF40", func_800F7240_BumperBallMaze);
#endif

void func_800F7BB8_BumperBallMaze(omObjData* object) {
    BumperBallMazeBallWork* work = object->unk_50;
    omObjData* obj;
    s16 model;

    if (D_800FB1C0_BumperBallMaze != 1) {
        return;
    }
    object->trans.y += work->unk_28;
    work->unk_28 = work->unk_28 - (fabs(work->unk_28 / 100.0f) + 5.0);
    omSetTra(object, object->trans.x + work->unk_24, object->trans.y, object->trans.z + work->unk_2C);
    func_80025798(object->model[2], object->trans.x, object->trans.y + -50.0f + work->unk_08,
                  object->trans.z);
    func_80025798(object->model[1], object->trans.x, 125.0f, object->trans.z);
    func_800257E4(object->model[2], work->unk_30, work->unk_34, work->unk_38);
    func_800F94A0_BumperBallMaze(object);
    if (object->trans.y < -120.0f && work->unk_3E == 0) {
        work->unk_3E = 1;
        model = D_800ECDE0[object->model[4]].unk_00;
        func_80025798(model, object->trans.x, 0.0f, object->trans.z + 90.0f);
        func_80025830(model, 5.0f, 5.0f, 5.0f);
        func_800258EC(model, 4, 0);
        func_80060F04(work->player, 0x14, 0, 0x14);
    }
    if (object->trans.y < -180.0f) {
        omSetTra(object, object->trans.x, -180.0f, object->trans.z);
        model = D_800ECDE0[object->model[3]].unk_00;
        func_80025798(model, object->trans.x, -60.0f, object->trans.z + 180.0f);
        func_80025830(model, 10.0f, 10.0f, 10.0f);
        func_800258EC(model, 4, 0);
        obj = omAddObj(0x14, 1, 0, -1, func_800F7F60_BumperBallMaze);
        obj->model[0] = object->model[2];
        omSetTra(obj, object->trans.x, object->trans.y + -50.0f + work->unk_08, object->trans.z);
        omSetRot(obj, work->unk_30, work->unk_34, work->unk_30);
        work->unk_00 = 4;
        work->unk_44 = 0.0f;
        PlaySound(0x2A8);
        object->func_ptr = func_800F7ED0_BumperBallMaze;
    }
}

void func_800F7ED0_BumperBallMaze(omObjData* object) {
    BumperBallMazeBallWork* work = object->unk_50;

    omSetTra(object, object->trans.x,
             func_800AEAC0(work->unk_44) * 2.0f + object->trans.y,
             object->trans.z);
    work->unk_44 += 8.0f;
    if (work->unk_44 >= 360.0f) {
        work->unk_44 -= 360.0f;
    }
}

void func_800F7F60_BumperBallMaze(omObjData* object) {
    omSetTra(object, object->trans.x, object->trans.y - 20.0f, object->trans.z);
    if (object->trans.y < -3000.0f) {
        func_800258EC(object->model[0], 4, 4);
        omDelObj(object);
    }
}

void func_800F7FE0_BumperBallMaze(omObjData* object) {
    BumperBallMazeBallWork* work = object->unk_50;
    omObjData* obj;
    s32 i;

    for (i = 0; i < 2; i++) {
        if (work->unk_40[i] == 0) {
            break;
        }
    }
    if (i == 2) {
        return;
    }
    work->unk_40[i] = 1;
    obj = omAddObj(0x28, 0, 0, -1, func_800F8108_BumperBallMaze);
    obj->work[0] = object->model[6 + i];
    obj->work[1] = work->player;
    obj->work[2] = i;
    func_80025798(obj->work[0], object->trans.x, 125.0f, object->trans.z);
    func_800257E4(obj->work[0], object->rot.x, object->rot.y, 0.0f);
    func_800258EC(obj->work[0], 4, 0);
    if (D_800F2B7C[obj->work[0]].unk_6C->unk_B8 != NULL) {
        D_800F2B7C[obj->work[0]].unk_6C->unk_B8->unk_08 = 0;
    }
    func_80025CA8(obj->work[0], 0.0f);
}

void func_800F8108_BumperBallMaze(omObjData* object) {
    f32 time = func_80025D18(object->work[0]);

    if (func_80025D40(object->work[0]) <= time) {
        ((BumperBallMazeBallWork*) D_800FAE10_BumperBallMaze->unk_50)->unk_40[object->work[2]] = 0;
        func_800258EC(object->work[0], 4, 4);
        omDelObj(object);
    }
}

void func_800F8184_BumperBallMaze(omObjData* object) {
    object->model[0] = LoadFormFile(0xA00FF, 0x20699);
    func_80025EB4(object->model[0], 2, 2);
    omSetTra(object,
             D_800FAC7C_BumperBallMaze[D_800FADF8_BumperBallMaze].x,
             D_800FAC7C_BumperBallMaze[D_800FADF8_BumperBallMaze].y,
             D_800FAC7C_BumperBallMaze[D_800FADF8_BumperBallMaze].z);
    object->func_ptr = func_800F8220_BumperBallMaze;
}

void func_800F8220_BumperBallMaze(omObjData* object) {
    omSetRot(object, 0.0f,
             func_800B0CD8(D_800FAE10_BumperBallMaze->trans.x - object->trans.x,
                           D_800FAE10_BumperBallMaze->trans.z - object->trans.z),
             0.0f);
}

void func_800F827C_BumperBallMaze(omObjData* object) {
    BumperBallMazeCameraPreset* cam;

    switch (D_800FB1C4_BumperBallMaze) {
    case 0:
        D_800FACBA_BumperBallMaze = D_800FACBA_BumperBallMaze - 1;
        D_800FB1C4_BumperBallMaze = 1;
        break;
    case 1:
        if (D_800FACB8_BumperBallMaze != 0) {
            if (--D_800FACB8_BumperBallMaze == 0) {
                func_80060128(0x26);
            }
        }
        if (D_800FACBC_BumperBallMaze != 0) {
            if (--D_800FACBC_BumperBallMaze == 0) {
                cam = &D_800FABBC_BumperBallMaze[D_800FADF8_BumperBallMaze];
                func_800F97B4_BumperBallMaze(cam->cameraValue, cam->zoom, cam->rot.x, cam->rot.y, cam->rot.z,
                                             cam->center.x, cam->center.y, cam->center.z);
            }
        }
        if (--D_800FACBA_BumperBallMaze == 0) {
            GMesCreate(0xD);
            D_800FB1C4_BumperBallMaze = 2;
        }
        break;
    case 2:
        if (GMesStatAllGet() == 0) {
            D_800FB1C0_BumperBallMaze = 1;
            omDelObj(object);
            D_800FAE08_BumperBallMaze = NULL;
            D_800FAE14_BumperBallMaze->work[0] = 1;
        }
        break;
    }
}

void func_800F8468_BumperBallMaze(omObjData* object) {
    BumperBallMazeBallWork* work;
    BumperBallMazeCameraPreset* cam;
    s32 i;
    f32 rot;
    s16 mes;
    omObjData* ball;

    switch (D_800FB1C2_BumperBallMaze) {
    case 10:
        work = D_800FAE10_BumperBallMaze->unk_50;
        D_800FADE2_BumperBallMaze = work->player;
        func_800F9610_BumperBallMaze(D_800FADE2_BumperBallMaze);
        cam = &D_800FAC1C_BumperBallMaze[D_800FADF8_BumperBallMaze];
        func_800F97B4_BumperBallMaze(cam->cameraValue, cam->zoom, cam->rot.x, cam->rot.y, cam->rot.z,
                                     cam->center.x, cam->center.y, cam->center.z);
        switch (D_800FADF8_BumperBallMaze) {
        case 0:
            SetBoardFeatureFlag(0x38);
            break;
        case 1:
            SetBoardFeatureFlag(0x39);
            break;
        }
        mes = 0x12;
        if (D_800FADF6_BumperBallMaze == 1) {
            mes = 0xC;
        }
        GMesCreate(mes);
        D_800FB1C2_BumperBallMaze = 0;
        break;
    case 0:
        for (i = 0; i < 4; i++) {
            work = D_800FAE10_BumperBallMaze->unk_50;
            if (work->unk_00 == 6) {
                D_800FADE8_BumperBallMaze = D_800FAE10_BumperBallMaze;
            }
        }
        work = D_800FADE8_BumperBallMaze->unk_50;
        if (work->unk_0C > 180.0f) {
            work->unk_0C -= 360.0f;
        }
        if (fabs(work->unk_0C) > 7.0) {
            if (work->unk_0C < 0.0f) {
                D_800FADE4_BumperBallMaze = 7.0f;
            } else {
                D_800FADE4_BumperBallMaze = -7.0f;
            }
        } else {
            D_800FADE4_BumperBallMaze = work->unk_0C;
        }
        D_800FB1C2_BumperBallMaze = 1;
        func_80025C20(D_800FADE8_BumperBallMaze->model[0], func_80025E48(D_800FADE8_BumperBallMaze->motion[1]),
                      0, 0xA, 2);
        func_80025EB4(D_800FADE8_BumperBallMaze->model[0], 6, 6);
        break;
    case 1:
        work = D_800FADE8_BumperBallMaze->unk_50;
        rot = work->unk_0C + D_800FADE4_BumperBallMaze;
        work->unk_0C = rot;
        if (D_800FADE4_BumperBallMaze < 0.0f) {
            if (rot <= 0.0f) {
                work->unk_0C = 0.0f;
                func_80025C20(D_800FADE8_BumperBallMaze->model[0],
                              func_80025E48(D_800FADE8_BumperBallMaze->motion[0]), 0, 0x14, 2);
                D_800FB1C2_BumperBallMaze = 0xB;
            }
        } else if (work->unk_0C >= 0.0f) {
            work->unk_0C = 0.0f;
            func_80025C20(D_800FADE8_BumperBallMaze->model[0],
                          func_80025E48(D_800FADE8_BumperBallMaze->motion[0]), 0, 0x14, 2);
            D_800FB1C2_BumperBallMaze = 0xB;
        }
        omSetRot(D_800FADE8_BumperBallMaze, 0.0f, work->unk_0C, 0.0f);
        break;
    case 11:
        if (GMesStatAllGet() & 2) {
            D_800FB1C2_BumperBallMaze = 2;
        }
        break;
    case 2:
        work = D_800FAE10_BumperBallMaze->unk_50;
        if (D_800FADF4_BumperBallMaze == 1) {
            func_80025C20(D_800FAE10_BumperBallMaze->model[0], func_80025E48(D_800FAE10_BumperBallMaze->motion[3]),
                          0, 0x1E, 0);
            D_800FADE2_BumperBallMaze = work->player;
            if (D_800FADF6_BumperBallMaze == 1) {
                func_80060128(0x37);
                D_800FADEC_BumperBallMaze = 0x30;
                D_800FADEE_BumperBallMaze = 0x46;
            } else {
                func_80060128(0x33);
                D_800FADEC_BumperBallMaze = 0x24;
                D_800FADEE_BumperBallMaze = 0x39;
            }
        } else {
            if (work->unk_00 != 3 && work->unk_00 != 4 && work->unk_00 != 5) {
                func_80025C20(D_800FAE10_BumperBallMaze->model[0],
                              func_80025E48(D_800FAE10_BumperBallMaze->motion[5]), 0, 0x1E, 0);
            }
            func_80060128(0x34);
            D_800FADEC_BumperBallMaze = 0x12;
            D_800FADEE_BumperBallMaze = 0x48;
        }
        D_800FB1C2_BumperBallMaze = 5;
        D_800FADE0_BumperBallMaze = 0;
        break;
    case 4:
        ball = D_800FAE10_BumperBallMaze;
        work = ball->unk_50;
        if (work->unk_00 != 3 && work->unk_00 != 4 && work->unk_00 != 5) {
            func_80025C20(D_800FAE10_BumperBallMaze->model[0], func_80025E48(ball->motion[0]), 0, 0x14, 2);
            mes = 0x10;
        } else {
            mes = 0xE;
        }
        GMesCreate(mes);
        D_800FB1C2_BumperBallMaze = 0xB;
        break;
    case 5:
        if (--D_800FADEC_BumperBallMaze == 0) {
            work = D_800FAE10_BumperBallMaze->unk_50;
            if (D_800FADF4_BumperBallMaze == 1) {
                func_80060618(0x451, D_800FADE2_BumperBallMaze);
            } else {
                func_80060618(0x44A, work->player);
            }
            D_800FADEC_BumperBallMaze = D_800FADEE_BumperBallMaze;
            D_800FB1C2_BumperBallMaze = 8;
        }
        break;
    case 6:
        if (GMesStatAllGet() & 2) {
            D_800FB1C2_BumperBallMaze = 7;
        }
        break;
    case 8:
        if (--D_800FADEC_BumperBallMaze == 0) {
            func_800726AC(0, 0x14);
            D_800FB1C2_BumperBallMaze = 9;
        }
        break;
    case 9:
        if (func_80072718() == 0) {
            D_800FACC0_BumperBallMaze = 1;
        }
        break;
    case 12:
        if (GMesWait() != 1) {
            D_800FADEC_BumperBallMaze = 1;
            D_800FB1C2_BumperBallMaze = 8;
        }
        break;
    case 7:
        D_800FB1C2_BumperBallMaze = 8;
        break;
    }
}

void func_800F8AB8_BumperBallMaze(void) {
    if (D_800FACC0_BumperBallMaze != 0 || D_800F5144 != 0) {
        func_800F9974_BumperBallMaze(0x83);
        func_800601D4(0x28);
    }
}

u16 func_800F8AFC_BumperBallMaze(BumperBallMazeFloorProbe* out) {
    BumperBallMazeHitProbe probe;
    unk2C0C0StructA0* verts;
    u16* tri;
    f32 x;
    f32 y;
    f32 z;
    f32 best;
    f32 h;
    f32 angle;
    u16 i;
    u16 misses;

    verts = D_800F2B7C[D_800FAE04_BumperBallMaze->model[0]].unk_6C->unk_78;
    misses = 0;
    for (i = 0; i < 8; i++) {
        angle = i * 45.0f;
        x = func_800AEAC0(angle) * 55.0f + out->pos.x;
        y = out->pos.y;
        z = func_800AEFD0(angle) * 55.0f + out->pos.z;
        best = out->height[i] = -10000.0f;
        out->attr[i] = 0xFFFF;
        probe.x = x;
        probe.y = y;
        probe.z = z;
        func_8002AE24(D_800FAE04_BumperBallMaze->model[0], &D_800EDEC0, func_800F8DFC_BumperBallMaze, &probe);
        for (tri = func_8002B3A8(&D_800EDEC0); tri != NULL; tri = func_8002B3A8(&D_800EDEC0)) {
            h = func_80029764(x, y, z, verts, tri);
            if (best < h) {
                best = h;
                out->height[i] = h;
                out->attr[i] = *tri & 0x3FFF;
            }
        }
        if (best == -10000.0f) {
            misses++;
        }
    }
    x = out->pos.x;
    y = out->pos.y;
    z = out->pos.z;
    best = out->centerHeight = -10000.0f;
    out->centerAttr = 0xFFFF;
    probe.x = x;
    probe.y = y;
    probe.z = z;
    func_8002AE24(D_800FAE04_BumperBallMaze->model[0], &D_800EDEC0, func_800F8DFC_BumperBallMaze, &probe);
    goto next;
    do {
        h = func_80029764(x, y, z, verts, tri);
        if (best < h) {
            best = h;
            out->centerHeight = h;
            out->centerAttr = *tri & 0x3FFF;
        }
    next:
        tri = func_8002B3A8(&D_800EDEC0);
    } while (tri != NULL);
    if (best == -10000.0f) {
        misses++;
    }
    return misses;
}

s32 func_800F8DFC_BumperBallMaze(s32 arg0, u16* polygon, BumperBallMazeColVtx* vertices,
                                BumperBallMazeHitProbe* probe) {
    return func_800F8E1C_BumperBallMaze(probe, polygon - 1, vertices);
}

s32 func_800F8E1C_BumperBallMaze(BumperBallMazeHitProbe* probe, u16* poly, BumperBallMazeColVtx* verts) {
    f32 x = probe->x;
    f32 z = probe->z;
    s32 cnt = (poly[0] >> 14) + 2;
    s32 i;
    s32 j;

    poly++;
    if (func_800296FC(x, z, &verts[(s16) poly[0]], &verts[(s16) poly[1]]) > 0.0f) {
        for (i = 1; i < cnt; i++) {
            j = (i + 1) % cnt;
            if (func_800296FC(x, z, &verts[(s16) poly[i]], &verts[(s16) poly[j]]) < 0.0f) {
                return 0;
            }
        }
    } else {
        for (i = 1; i < cnt; i++) {
            j = (i + 1) % cnt;
            if (func_800296FC(x, z, &verts[(s16) poly[i]], &verts[(s16) poly[j]]) > 0.0f) {
                return 0;
            }
        }
    }
    return 1;
}

s32 func_800F9034_BumperBallMaze(void) {
    return ((BumperBallMazeBallWork*) D_800FAE10_BumperBallMaze->unk_50)->unk_00 != 3;
}

void func_800F9050_BumperBallMaze(omObjData* object) {
    BumperBallMazeTimerWork* work;
    s32 i;
    u16 x;
    u16 bestX;

    work = object->unk_50 = func_80023684(0x20, 0x7918);
    work->best = func_800594FC(D_800FADF8_BumperBallMaze + 5);
    work->time = 0;
    object->work[1] = 0;
    object->work[0] = 0;
    x = D_800FAB50_BumperBallMaze[D_800FADF8_BumperBallMaze].x;
    bestX = D_800FAB44_BumperBallMaze[D_800FADF8_BumperBallMaze].x;
    for (i = 0; i < 7; i++) {
        work->digits[i] = func_80019060(D_800FAE00_BumperBallMaze, 0, 1);
        SetBasicSpritePos(work->digits[i], x, D_800FAB50_BumperBallMaze[D_800FADF8_BumperBallMaze].y);
        func_80018DC4(work->digits[i], 0.0f);
        work->bestDigits[i] = func_80019060(D_800FAE02_BumperBallMaze, 0, 1);
        SetBasicSpritePos(work->bestDigits[i], bestX, D_800FAB44_BumperBallMaze[D_800FADF8_BumperBallMaze].y);
        func_80018DC4(work->bestDigits[i], 0.0f);
        if (i == 0) {
            x += 8;
            bestX += 8;
        } else {
            x += 12;
            bestX += 12;
        }
    }
    func_80018E50(work->digits[1], 10, 0);
    func_80018E50(work->digits[4], 11, 0);
    func_80018E50(work->bestDigits[1], 10, 0);
    func_80018E50(work->bestDigits[4], 11, 0);
    func_800F928C_BumperBallMaze(work->best, work->bestDigits);
    func_800F928C_BumperBallMaze(work->time, work->digits);
    object->func_ptr = func_800F923C_BumperBallMaze;
}

void func_800F923C_BumperBallMaze(omObjData* object) {
    BumperBallMazeTimerWork* state = object->unk_50;

    if (object->work[0] == 1) {
        state->time += 2;
        func_800F928C_BumperBallMaze(state->time, state->digits);
    }
}

u16 func_800F9278_BumperBallMaze(void) {
    return ((BumperBallMazeTimerWork*) D_800FAE14_BumperBallMaze->unk_50)->time;
}

// register allocation: remainders computed in place, not in temps (raw 14, masked 0; tried explicit
// t - q * n remainders, declaration order)
#ifdef NON_MATCHING
void func_800F928C_BumperBallMaze(u16 time, u16* digits) {
    u16 rest;
    u16 sec;
    u16 frac;

    func_80018E50(*digits, time / 3600, 0);
    digits += 2;
    rest = time % 3600;
    sec = rest / 60;
    func_80018E50(*digits, sec / 10, 0);
    digits++;
    func_80018E50(*digits, sec % 10, 0);
    digits += 2;
    frac = (u16) (rest % 60) * 1.6666666f;
    func_80018E50(*digits, frac / 10, 0);
    func_80018E50(digits[1], frac % 10, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/23CF40", func_800F928C_BumperBallMaze);
#endif

void func_800F943C_BumperBallMaze(void) {
    BumperBallMazeTimerWork* state = D_800FAE14_BumperBallMaze->unk_50;

    if (state->best > state->time) {
        state->best = state->time;
        func_800594E4(D_800FADF8_BumperBallMaze + 5, state->best);
        D_800FADF6_BumperBallMaze = 1;
    }
}

void func_800F94A0_BumperBallMaze(omObjData* object) {
    BumperBallMazeFloorProbe probe;
    f32 angle;
    f32 dx;
    f32 dz;
    u16 i;
    u16 misses;
    u16 tries;

    tries = 0;
    do {
        probe.pos.x = object->trans.x;
        probe.pos.y = object->trans.y + -100.0f;
        probe.pos.z = object->trans.z;
        func_800F8AFC_BumperBallMaze(&probe);
        misses = 0;
        for (i = 0; i < 8; i++) {
            if (probe.height[i] == -10000.0f) {
                misses++;
                continue;
            }
            angle = ((u16) (i + 4) & 7) * 45.0f;
            dx = func_800AEAC0(angle) * 5.0f;
            dz = func_800AEFD0(angle) * 5.0f;
            object->trans.x = dx + object->trans.x;
            object->trans.z = dz + object->trans.z;
        }
        if (misses == 8) {
            break;
        }
    } while (++tries < 4);
}

void func_800F9610_BumperBallMaze(s32 player) {
    u16 remaining = 0xE10 - func_800F9278_BumperBallMaze();
    u16 q = remaining / 60;
    u16 reward = q;

    if ((u16) (remaining % 60) != 0) {
        reward = q + 1;
    }
    GwPlayer[(u16) player].coins_mg += reward + 10;
}
