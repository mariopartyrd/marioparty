#include "common.h"

/* The end-of-game bonus stars (variant 1, a near-copy of ovl_42's 278ED0.c): the stars and
   coins are shown, the bonus stars awarded, ties broken with a dice block, a sweeping star points
   out the winner, then the players line up on a podium under YOU ARE A WINNER and overlay 0x40
   follows. */

void func_8001249C(s16, u8);
void func_80052DC8(s16, void*);
u16 func_8004F25C(void);
void func_8004FFA8(void);
void func_8003FC94(void);
void func_80040780(s32);
void func_8003FD68(s32);
void func_8004157C(void);
s32 func_800415E8(s32);
void func_800427E4(void);
extern char* D_800C5218[]; /* character names */
/* Retail called these unprototyped: their results are used as words, not narrowed to the
   definitions' u16/s16. The host calls them normally. */
#define func_8004F25C_unproto() ((s32 (*)())func_8004F25C)()
#define func_80023FC8_unproto(a) ((s32 (*)())func_80023FC8)(a)
#define GMesFontMesCreate_unproto(a, b, c, d, e) ((s32 (*)())GMesFontMesCreate)(a, b, c, d, e)

void func_800F667C_UnknownEndGameBonuses1(void);
void func_800F6730_UnknownEndGameBonuses1(void);
void func_800F6750_UnknownEndGameBonuses1(omObjData* obj);
void func_800F67EC_UnknownEndGameBonuses1(omObjData* obj);
void func_800F6FC8_UnknownEndGameBonuses1(omObjData* obj);
void func_800F70D0_UnknownEndGameBonuses1(void);
void func_800F74E4_UnknownEndGameBonuses1(void);
void func_800F7580_UnknownEndGameBonuses1(void);
void func_800F7918_UnknownEndGameBonuses1(void);
void func_800F79B4_UnknownEndGameBonuses1(s32 count, u8* flags);
void func_800F7DE0_UnknownEndGameBonuses1(void);
void func_800F9E18_UnknownEndGameBonuses1(omObjData* obj);
void func_800F9E44_UnknownEndGameBonuses1(omObjData* obj);
void func_800F9E78_UnknownEndGameBonuses1(omObjData* obj);
void func_800F9ED8_UnknownEndGameBonuses1(omObjData* obj);
void func_800F9F1C_UnknownEndGameBonuses1(void);
void func_800FA264_UnknownEndGameBonuses1(void);
void func_800FA3C0_UnknownEndGameBonuses1(void);
void func_800FA474_UnknownEndGameBonuses1(void);

/* .rodata (ahead of everything: the .data pointer below refers to it) */
const char D_800FA660_UnknownEndGameBonuses1[] = "YOU ARE A WINNER";
const char D_800FA674_UnknownEndGameBonuses1[] = ""; /* unreferenced */

/* .data */
omObjData* D_800FA4A0_UnknownEndGameBonuses1 = NULL; /* the winner's star */
void* D_800FA4A4_UnknownEndGameBonuses1[4] = { NULL, NULL, NULL, NULL };
/* the effect's model id (-1: none); retail reads its low half (big-endian +2) as s16 */
s32 D_800FA4B4_UnknownEndGameBonuses1 = -1;
omObjData* D_800FA4B8_UnknownEndGameBonuses1 = NULL;
omObjData* D_800FA4BC_UnknownEndGameBonuses1[4] = { NULL, NULL, NULL, NULL };
s32 D_800FA4CC_UnknownEndGameBonuses1[8] = { 1, 8, 19, 28, 40, 48, 57, 69 }; /* background per board */
/* each player's position (splat: D_800FA4EC, D_800FA4F0, D_800FA4F4) */
Vec3f D_800FA4EC_UnknownEndGameBonuses1[4] = {
    { -190.0f, 0.0f, 2120.0f }, { -15.0f, 0.0f, 2120.0f }, { 160.0f, 0.0f, 2120.0f }, { 335.0f, 0.0f, 2120.0f },
};
/* the podium: the winner's spot, then the others' */
Vec3f D_800FA51C_UnknownEndGameBonuses1[4] = {
    { 0.0f, 25.0f, 2500.0f }, { -200.0f, 0.0f, 2200.0f }, { 175.0f, 0.0f, 2200.0f }, { 325.0f, 0.0f, 2200.0f },
};
Vec3f D_800FA54C_UnknownEndGameBonuses1 = { 0.0f, 25.0f, 2500.0f }; /* a single winner's spot */
Vec3f D_800FA558_UnknownEndGameBonuses1 = { -345.0f, 0.0f, 2040.0f };
/* per character: the board model's file list (a count, then file ids) */
s32 D_800FA564_UnknownEndGameBonuses1[9] = { 8, 0x1003A, 0x10010, 0xA008B, 0x10000, 0x1003F, 0x10001, 0x10097, 0x1000F };
s32 D_800FA588_UnknownEndGameBonuses1[9] = { 8, 0x2003A, 0x20010, 0xA008C, 0x20000, 0x2003F, 0x20001, 0x20097, 0x2000F };
s32 D_800FA5AC_UnknownEndGameBonuses1[9] = { 8, 0x6003A, 0x60010, 0xA008D, 0x60000, 0x6003F, 0x60001, 0x60097, 0x6000F };
s32 D_800FA5D0_UnknownEndGameBonuses1[9] = { 8, 0x3003A, 0x30010, 0xA008E, 0x30000, 0x3003F, 0x30001, 0x30097, 0x3000F };
s32 D_800FA5F4_UnknownEndGameBonuses1[9] = { 8, 0x4003A, 0x40010, 0xA008F, 0x40000, 0x4003F, 0x40001, 0x40097, 0x4000F };
s32 D_800FA618_UnknownEndGameBonuses1[9] = { 8, 0x5003A, 0x50010, 0xA0090, 0x50000, 0x5003F, 0x50001, 0x50097, 0x5000F };
void* D_800FA63C_UnknownEndGameBonuses1[6] = {
    D_800FA564_UnknownEndGameBonuses1, D_800FA588_UnknownEndGameBonuses1, D_800FA5AC_UnknownEndGameBonuses1,
    D_800FA5D0_UnknownEndGameBonuses1, D_800FA5F4_UnknownEndGameBonuses1, D_800FA618_UnknownEndGameBonuses1,
};
u8 D_800FA654_UnknownEndGameBonuses1[4] = { 0x20, 0x30, 0x50, 0x60 }; /* per player: sound pan */
char* D_800FA658_UnknownEndGameBonuses1 = (char*)D_800FA660_UnknownEndGameBonuses1;
s16 D_800FA65C_UnknownEndGameBonuses1[2] = { 160, 45 }; /* its position */

/* .bss */
extern u8 D_800FA730_UnknownEndGameBonuses1; /* board index */
extern Object* D_800FA734_UnknownEndGameBonuses1;
extern Object* D_800FA738_UnknownEndGameBonuses1[4]; /* the bonus star models */
extern s32 D_800FA748_UnknownEndGameBonuses1[4];     /* their effects; read as (s16) */
extern s32 D_800FA758_UnknownEndGameBonuses1[4];     /* the digit sprites; read as (s16) */
extern s32 D_800FA768_UnknownEndGameBonuses1;        /* the digit graphic; read as (s16) */
extern s16 D_800FA76C_UnknownEndGameBonuses1;
extern s16 D_800FA76E_UnknownEndGameBonuses1;
extern unkCommonStruct0 D_800FA770_UnknownEndGameBonuses1; /* the "YOU ARE A WINNER" text (splat: D_800FA784 = unk_14) */
extern s32 D_800FA7D8_UnknownEndGameBonuses1;        /* frames since the fade-out */

#define DEG 0.017453292519943295

void func_800F65E0_UnknownEndGameBonuses1(void) {
    D_800FA730_UnknownEndGameBonuses1 = GwSystem.curBoardIndex;
    omInitObjMan(0x50, 0x50);
    func_800FA3C0_UnknownEndGameBonuses1();
    func_800F9F1C_UnknownEndGameBonuses1();
    func_8006CEA0();
    omAddPrcObj(func_800F7DE0_UnknownEndGameBonuses1, 0x300, 0x4000, 0);
    omAddObj(0x1000, 0, 0, -1, &func_800F9ED8_UnknownEndGameBonuses1);
    func_80072724(0xFF, 0xFF, 0xFF);
    SetFadeInTypeAndTime(2, 0x10);
}

/* "YOU ARE A WINNER", in the font */
void func_800F667C_UnknownEndGameBonuses1(void) {
    s32 mes;
    s32 i;

    mes = (s16)GMesFontMesCreate_unproto(&D_800FA770_UnknownEndGameBonuses1, D_800FA658_UnknownEndGameBonuses1, 0, -1, -1);
    func_80066DC4(D_800FA770_UnknownEndGameBonuses1.unk_14[mes], 0, D_800FA65C_UnknownEndGameBonuses1[0],
                  D_800FA65C_UnknownEndGameBonuses1[1]);
    for (i = 1; i < 17; i++) {
        func_80067354(D_800FA770_UnknownEndGameBonuses1.unk_14[mes], i, 1.0f, 2.0f);
    }
}

void func_800F6730_UnknownEndGameBonuses1(void) {
    func_80077044(&D_800FA770_UnknownEndGameBonuses1);
}

void func_800F6750_UnknownEndGameBonuses1(omObjData* obj) {
    obj->scale.x += 0.4f;
    obj->scale.y += 0.4f;
    obj->scale.z += 0.4f;
    if (obj->scale.x >= 5.0f) {
        func_8002456C((s16)D_800FA4B4_UnknownEndGameBonuses1);
        D_800FA4B4_UnknownEndGameBonuses1 = -1;
        D_800FA4B8_UnknownEndGameBonuses1 = NULL;
        omDelObj(obj);
    }
}

/* The sweeping star: work[0] state (0 sweep, 1 sweep until over player work[1], 4 hover over
   them, 2 move for work[2] frames, 5 hover at its trans), work[2] set once it stops, work[3]
   frames; mdlcnt the star model. */
void func_800F67EC_UnknownEndGameBonuses1(omObjData* obj) {
    f32 x;
    f32 y;

    switch (obj->work[0]) {
    case 0:
    case 1:
        func_8001249C(D_800FA76E_UnknownEndGameBonuses1, (s32)(sinf(obj->scale.x * DEG) * 32.0f) + 0x40);
        MBModelDispOn(D_800FA738_UnknownEndGameBonuses1[obj->mdlcnt]);
        x = sinf(obj->scale.x * DEG) * 350.0f + obj->trans.x;
        func_800A0D00(&D_800FA738_UnknownEndGameBonuses1[obj->mdlcnt]->coords, x,
                      sinf(2.0f * obj->scale.x * DEG) * 20.0f + obj->trans.y, obj->trans.z);
        D_800FA738_UnknownEndGameBonuses1[obj->mdlcnt]->unk_18.x = 0.0f;
        D_800FA738_UnknownEndGameBonuses1[obj->mdlcnt]->unk_18.z = 1.0f;
        if (obj->work[0] == 1
            && ((GwPlayer[obj->work[1]].player_obj->coords.x >= sinf(obj->scale.x * DEG) * 350.0f + obj->trans.x
                 && GwPlayer[obj->work[1]].player_obj->coords.x <= sinf((obj->scale.x + 5.0f) * DEG) * 350.0f + obj->trans.x)
                || (GwPlayer[obj->work[1]].player_obj->coords.x <= sinf(obj->scale.x * DEG) * 350.0f + obj->trans.x
                    && GwPlayer[obj->work[1]].player_obj->coords.x >= sinf((obj->scale.x + 5.0f) * DEG) * 350.0f + obj->trans.x))) {
            func_800A0D00(&D_800FA738_UnknownEndGameBonuses1[obj->mdlcnt]->coords, GwPlayer[obj->work[1]].player_obj->coords.x,
                          sinf(2.0f * obj->scale.x * DEG) * 20.0f + obj->trans.y, obj->trans.z);
            obj->work[0] = 4;
            obj->work[2] = 1;
            obj->scale.y = 0.0f;
            obj->rot.y = 0.0f;
            D_800FA4B4_UnknownEndGameBonuses1 = LoadFormFile(0xA0136, 0x2B9);
            func_80025798((s16)D_800FA4B4_UnknownEndGameBonuses1, GwPlayer[obj->work[1]].player_obj->coords.x,
                          sinf(2.0f * obj->scale.x * DEG) * 20.0f + obj->trans.y, obj->trans.z);
            func_80025830((s16)D_800FA4B4_UnknownEndGameBonuses1, 3.0f, 3.0f, 3.0f);
            D_800FA4B8_UnknownEndGameBonuses1 = omAddObj(-0x8000, 1, 1, -1, &func_800F6750_UnknownEndGameBonuses1);
            D_800FA4B8_UnknownEndGameBonuses1->model[0] = (s16)D_800FA4B4_UnknownEndGameBonuses1;
            D_800FA4B8_UnknownEndGameBonuses1->trans.x = GwPlayer[obj->work[1]].player_obj->coords.x;
            D_800FA4B8_UnknownEndGameBonuses1->trans.y = sinf(2.0f * obj->scale.x * DEG) * 20.0f + obj->trans.y;
            D_800FA4B8_UnknownEndGameBonuses1->trans.z = obj->trans.z;
            D_800FA4B8_UnknownEndGameBonuses1->rot.x = 90.0f;
            D_800FA4B8_UnknownEndGameBonuses1->rot.y = D_800FA4B8_UnknownEndGameBonuses1->rot.z = 0.0f;
            D_800FA4B8_UnknownEndGameBonuses1->scale.x = D_800FA4B8_UnknownEndGameBonuses1->scale.y =
                D_800FA4B8_UnknownEndGameBonuses1->scale.z = 1.0f;
            break;
        }
        if ((obj->scale.x += 5.0f) >= 360.0f) {
            obj->scale.x -= 360.0f;
        }
        obj->work[3]++;
        break;
    case 2:
        func_800A0D00(&D_800FA738_UnknownEndGameBonuses1[obj->mdlcnt]->coords,
                      D_800F2B7C[*D_800FA738_UnknownEndGameBonuses1[obj->mdlcnt]->unk_3C->unk_40].unk_24 + obj->trans.x,
                      D_800F2B7C[*D_800FA738_UnknownEndGameBonuses1[obj->mdlcnt]->unk_3C->unk_40].unk_28 + obj->trans.y,
                      D_800F2B7C[*D_800FA738_UnknownEndGameBonuses1[obj->mdlcnt]->unk_3C->unk_40].unk_2C + obj->trans.z);
        obj->work[3]++;
        obj->work[2]--;
        if (obj->work[2] == 0) {
            obj->trans.x = D_800F2B7C[*D_800FA738_UnknownEndGameBonuses1[obj->mdlcnt]->unk_3C->unk_40].unk_24;
            obj->trans.y = D_800F2B7C[*D_800FA738_UnknownEndGameBonuses1[obj->mdlcnt]->unk_3C->unk_40].unk_28;
            obj->trans.z = D_800F2B7C[*D_800FA738_UnknownEndGameBonuses1[obj->mdlcnt]->unk_3C->unk_40].unk_2C;
            obj->rot.y = 0.0f;
            obj->work[0] = 5;
        }
        break;
    case 3:
        break;
    case 4:
        y = sinf(2.0f * obj->scale.x * DEG) * 20.0f + obj->trans.y;
        func_800A0D00(&D_800FA738_UnknownEndGameBonuses1[obj->mdlcnt]->coords, GwPlayer[obj->work[1]].player_obj->coords.x,
                      y + sinf(obj->rot.y * DEG) * 8.0f, obj->trans.z);
        if ((obj->rot.y += 10.0f) >= 360.0f) {
            obj->rot.y -= 360.0f;
        }
        break;
    case 5:
        func_800A0D00(&D_800FA738_UnknownEndGameBonuses1[obj->mdlcnt]->coords, obj->trans.x,
                      sinf(obj->rot.y * DEG) * 8.0f + obj->trans.y, obj->trans.z);
        if ((obj->rot.y += 10.0f) >= 360.0f) {
            obj->rot.y -= 360.0f;
        }
        break;
    }
}

/* Pulses a leader's digits: work[0] player, work[1] digit count. */
void func_800F6FC8_UnknownEndGameBonuses1(omObjData* obj) {
    f32 s;
    s32 i;

    s = sinf(obj->rot.x * DEG) * 0.3f + 1.0;
    for (i = 0; i < obj->work[1]; i++) {
        func_80067354((s16)D_800FA758_UnknownEndGameBonuses1[obj->work[0]], i, s, s);
    }
    if ((obj->rot.x += 30.0f) >= 360.0f) {
        obj->rot.x -= 360.0f;
    }
}

/* Each player's coins in digits over their head; the leaders' digits pulse. */
void func_800F70D0_UnknownEndGameBonuses1(void) {
    s32 digits[3];
    Vec3f pos;
    Vec2f scr;
    void* file;
    s32 n;
    s32 cnt;
    s32 i;
    s32 j;
    s32 max;

    file = DataRead(0xA0129);
    D_800FA768_UnknownEndGameBonuses1 = func_800678A4(file);
    DataClose(file);
    for (i = 0; i < 4; i++) {
        D_800FA758_UnknownEndGameBonuses1[i] = func_80064EF4(3, 5);
        n = (s16)(u16)GwPlayer[i].coins; /* retail: lhu, then sign-extended */
        if (n >= 100) {
            cnt = 3;
            digits[0] = n / 100;
            n %= 100;
            digits[1] = n / 10;
            n %= 10;
            digits[2] = n;
        } else if (n >= 10) {
            cnt = 2;
            n %= 100;
            digits[0] = n / 10;
            n %= 10;
            digits[1] = n;
        } else {
            cnt = 1;
            digits[0] = n;
        }
        for (j = 0; j < cnt; j++) {
            func_80067208((s16)D_800FA758_UnknownEndGameBonuses1[i], j, (s16)D_800FA768_UnknownEndGameBonuses1, 0);
            func_800672B0((s16)D_800FA758_UnknownEndGameBonuses1[i], j, 1);
            func_800672DC((s16)D_800FA758_UnknownEndGameBonuses1[i], j, digits[j], 0);
            func_80067384((s16)D_800FA758_UnknownEndGameBonuses1[i], j, 0x4790);
            func_800674BC((s16)D_800FA758_UnknownEndGameBonuses1[i], j, 0x1000);
            func_800674F4((s16)D_800FA758_UnknownEndGameBonuses1[i], (s16)j, 0xFF, 0xFF, 0);
            if (j == 0) {
                pos.x = GwPlayer[i].player_obj->coords.x;
                pos.y = GwPlayer[i].player_obj->coords.y + 300.0f;
                pos.z = GwPlayer[i].player_obj->coords.z;
                func_8004B730(&pos, &scr);
                func_80066DC4((s16)D_800FA758_UnknownEndGameBonuses1[i], 0, scr.x - (cnt - 1) * 7, scr.y);
            } else {
                func_80066DC4((s16)D_800FA758_UnknownEndGameBonuses1[i], j, j * 14, 0);
            }
        }
        max = GwPlayer[i].coins;
        for (j = 0; j < 4; j++) {
            if (j != i && max < GwPlayer[j].coins) {
                max = GwPlayer[j].coins;
            }
        }
        if (max == GwPlayer[i].coins) {
            D_800FA4BC_UnknownEndGameBonuses1[i] = omAddObj(0x1000, 0, 0, -1, &func_800F6FC8_UnknownEndGameBonuses1);
            D_800FA4BC_UnknownEndGameBonuses1[i]->work[0] = i;
            D_800FA4BC_UnknownEndGameBonuses1[i]->work[1] = cnt;
            D_800FA4BC_UnknownEndGameBonuses1[i]->rot.x = 0.0f;
        }
    }
}

void func_800F74E4_UnknownEndGameBonuses1(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_800FA4BC_UnknownEndGameBonuses1[i] != NULL) {
            omDelObj(D_800FA4BC_UnknownEndGameBonuses1[i]);
            D_800FA4BC_UnknownEndGameBonuses1[i] = NULL;
        }
        func_80064D38((s16)D_800FA758_UnknownEndGameBonuses1[i]);
    }
    func_80067704((s16)D_800FA768_UnknownEndGameBonuses1);
    HuPrcVSleep();
}

/* Each player's stars in digits over their head; the leaders' digits pulse. */
void func_800F7580_UnknownEndGameBonuses1(void) {
    s32 digits[2];
    Vec3f pos;
    Vec2f scr;
    void* file;
    s32 n;
    s32 cnt;
    s32 i;
    s32 j;
    s32 max;

    file = DataRead(0xA0129);
    D_800FA768_UnknownEndGameBonuses1 = func_800678A4(file);
    DataClose(file);
    for (i = 0; i < 4; i++) {
        D_800FA758_UnknownEndGameBonuses1[i] = func_80064EF4(2, 5);
        n = (s16)(u16)GwPlayer[i].stars; /* retail: lhu, then sign-extended */
        if (n >= 10) {
            cnt = 2;
            n %= 100;
            digits[0] = n / 10;
            n %= 10;
            digits[1] = n;
        } else {
            cnt = 1;
            digits[0] = n;
        }
        for (j = 0; j < cnt; j++) {
            func_80067208((s16)D_800FA758_UnknownEndGameBonuses1[i], j, (s16)D_800FA768_UnknownEndGameBonuses1, 0);
            func_800672B0((s16)D_800FA758_UnknownEndGameBonuses1[i], j, 1);
            func_800672DC((s16)D_800FA758_UnknownEndGameBonuses1[i], j, digits[j], 0);
            func_80067384((s16)D_800FA758_UnknownEndGameBonuses1[i], j, 0x4790);
            func_800674BC((s16)D_800FA758_UnknownEndGameBonuses1[i], j, 0x1000);
            func_800674F4((s16)D_800FA758_UnknownEndGameBonuses1[i], (s16)j, 0xFF, 0xFF, 0);
            if (j == 0) {
                pos.x = GwPlayer[i].player_obj->coords.x;
                pos.y = GwPlayer[i].player_obj->coords.y + 300.0f;
                pos.z = GwPlayer[i].player_obj->coords.z;
                func_8004B730(&pos, &scr);
                func_80066DC4((s16)D_800FA758_UnknownEndGameBonuses1[i], 0, scr.x - (cnt - 1) * 7, scr.y);
            } else {
                func_80066DC4((s16)D_800FA758_UnknownEndGameBonuses1[i], j, j * 14, 0);
            }
        }
        max = GwPlayer[i].stars;
        for (j = 0; j < 4; j++) {
            if (j != i && max < GwPlayer[j].stars) {
                max = GwPlayer[j].stars;
            }
        }
        if (max == GwPlayer[i].stars) {
            D_800FA4BC_UnknownEndGameBonuses1[i] = omAddObj(0x1000, 0, 0, -1, &func_800F6FC8_UnknownEndGameBonuses1);
            D_800FA4BC_UnknownEndGameBonuses1[i]->work[0] = i;
            D_800FA4BC_UnknownEndGameBonuses1[i]->work[1] = cnt;
            D_800FA4BC_UnknownEndGameBonuses1[i]->rot.x = 0.0f;
        }
    }
}

void func_800F7918_UnknownEndGameBonuses1(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_800FA4BC_UnknownEndGameBonuses1[i] != NULL) {
            omDelObj(D_800FA4BC_UnknownEndGameBonuses1[i]);
            D_800FA4BC_UnknownEndGameBonuses1[i] = NULL;
        }
        func_80064D38((s16)D_800FA758_UnknownEndGameBonuses1[i]);
    }
    func_80067704((s16)D_800FA768_UnknownEndGameBonuses1);
    HuPrcVSleep();
}

/* A bonus star flies down to each flagged player (count: how many get one). */
void func_800F79B4_UnknownEndGameBonuses1(s32 count, u8* flags) {
    s16 sounds[4] = { 0x67, 0x68, 0x69, 0x67 };
    s32 n;
    s32 i;
    s32 k;
    s32 y;
    s32 snd;

    n = 0;
    for (i = 0; i < 4; i++) {
        if (flags[i] != 0) {
            GwCommon.boardWork[10 + i]++;
            func_8004F4D4(GwPlayer[i].player_obj, 7, 0);
            snd = (s16)PlaySound(sounds[n++]);
            if (count != 1) {
                func_8001249C(snd, D_800FA654_UnknownEndGameBonuses1[i]);
            }
            D_800FA4A4_UnknownEndGameBonuses1[i] = func_80042728(D_800FA738_UnknownEndGameBonuses1[i], 1);
            for (k = 0, y = 800; y >= 250; y -= 15, k++) {
                MBModelDispOn(D_800FA738_UnknownEndGameBonuses1[i]);
                func_800A0D00(&D_800FA738_UnknownEndGameBonuses1[i]->coords, GwPlayer[i].player_obj->coords.x,
                              y + GwPlayer[i].player_obj->coords.y, GwPlayer[i].player_obj->coords.z - 50.0f);
                D_800FA738_UnknownEndGameBonuses1[i]->unk_18.x = sinf((y * 2 - 160) * DEG);
                D_800FA738_UnknownEndGameBonuses1[i]->unk_18.z = cosf((y * 2 - 160) * DEG);
                if (k == 9) {
                    s32 h = (s16)func_80060618(0x451, i);

                    if (count != 1) {
                        func_8001249C(h, D_800FA654_UnknownEndGameBonuses1[i]);
                    }
                }
                HuPrcVSleep();
            }
        }
    }
    for (i = 0; i < 4; i++) {
        if (flags[i] != 0) {
            func_800427D4(D_800FA4A4_UnknownEndGameBonuses1[i]);
            D_800FA4A4_UnknownEndGameBonuses1[i] = NULL;
        }
    }
    for (y = 0; y < 4; y++) {
        if (flags[y] != 0) {
            func_8004F504(GwPlayer[y].player_obj);
        }
    }
    HuPrcSleep(10);
    do {
        for (i = 0; i < 4; i++) {
            D_800FA738_UnknownEndGameBonuses1[i]->xScale -= 0.1f;
            D_800FA738_UnknownEndGameBonuses1[i]->yScale -= 0.1f;
            D_800FA738_UnknownEndGameBonuses1[i]->zScale -= 0.1f;
            D_800FA738_UnknownEndGameBonuses1[i]->coords.y -= 20.0f;
        }
        HuPrcVSleep();
    } while (!(D_800FA738_UnknownEndGameBonuses1[0]->xScale <= 0.05f));
    for (i = 0; i < 4; i++) {
        MBModelDispOff(D_800FA738_UnknownEndGameBonuses1[i]);
        func_800A0D00((Vec3f*)&D_800FA738_UnknownEndGameBonuses1[i]->xScale, 0.75f, 0.75f, 0.75f);
        D_800FA738_UnknownEndGameBonuses1[i]->coords.y = 800.0f;
    }
    for (y = 0; y < 4; y++) {
        if (flags[y] != 0) {
            func_8004F4D4(GwPlayer[y].player_obj, 3, 2);
        }
    }
}

#define SHOW_MESSAGE(win, msg)                              \
    LoadStringIntoWindow((s16)(win), (void*)(msg), -1, -1); \
    func_8006E070((s16)(win), 0);                           \
    ShowTextWindow((s16)(win));                             \
    PlaySound(0x432);                                       \
    WaitForTextConfirmation((s16)(win));                    \
    HideTextWindow((s16)(win))

/* One bonus star: the players with the highest value get it (k of them, listed in timers[]). */
#define BONUS_STAR(field, w0, w1, w2, w3, m0)                                                        \
    for (i = 0, j = -100000; i < 4; i++) {                                                            \
        if (j < field(i)) {                                                                           \
            j = field(i);                                                                             \
        }                                                                                             \
    }                                                                                                 \
    for (i = 0, k = 0; i < 4; i++) {                                                                  \
        if (field(i) == j) {                                                                          \
            flags[i] = 1;                                                                             \
            k++;                                                                                      \
        } else {                                                                                      \
            flags[i] = 0;                                                                             \
        }                                                                                             \
    }                                                                                                 \
    {                                                                                                 \
        u8 widths[4] = { w0, w1, w2, w3 };                                                            \
        u8 heights[4] = { 2, 3, 4, 4 };                                                               \
        s32 msgs[4] = { m0, m0 + 1, m0 + 2, m0 + 3 };                                                 \
                                                                                                      \
        win2 = CreateTextWindow(30, 42, widths[k - 1], heights[k - 1]);                               \
        for (i = 0, j = 0; i < 4; i++) {                                                              \
            if (flags[i] != 0) {                                                                      \
                timers[j] = i;                                                                        \
                func_8006DA5C(win2, D_800C5218[GwPlayer[i].character], j++);                          \
            }                                                                                         \
        }                                                                                             \
        SHOW_MESSAGE(win2, (s32)msgs[k - 1]);                                               \
    }                                                                                                 \
    if (k == 1) {                                                                                     \
        func_8004EE14(timers[0], &D_800FA54C_UnknownEndGameBonuses1, 1, NULL);                        \
        func_8004E3E0(timers[0], &D_800FA54C_UnknownEndGameBonuses1, 30, NULL);                       \
        func_8004F4D4(GwPlayer[timers[0]].player_obj, 5, 2);                                          \
        HuPrcSleep(30);                                                                               \
        func_8004EE14(timers[0], D_800F32A0, 1, NULL);                                                \
    }                                                                                                 \
    if (k != 4) {                                                                                     \
        func_800F79B4_UnknownEndGameBonuses1(k, flags);                                               \
    }                                                                                                 \
    if (k == 1) {                                                                                     \
        func_8004EE14(timers[0], &D_800FA4EC_UnknownEndGameBonuses1[timers[0]], 10, NULL); \
        func_8004E3E0(timers[0], &D_800FA4EC_UnknownEndGameBonuses1[timers[0]], 30, NULL); \
        func_8004F4D4(GwPlayer[timers[0]].player_obj, 5, 2);                                          \
        HuPrcSleep(30);                                                                               \
        func_8004EE14(timers[0], D_800F32A0, 10, NULL);                                               \
        func_8004F4D4(GwPlayer[timers[0]].player_obj, 3, 2);                                          \
    }

#define MINIGAME_COINS(i) GwPlayer[i].coins_total
#define MAX_COINS(i) GwPlayer[i].coins_max
#define HAPPENINGS(i) (s8)GwPlayer[i].happening_count

/* The ceremony. */
// register allocation: the window id and an array base swap s5/s6 (masked 0)
#ifdef NON_MATCHING
void func_800F7DE0_UnknownEndGameBonuses1(void) {
    s32 timers[4]; /* also a bonus's winners, and the sort's swap temporary */
    s32 order[4];  /* also each player's stars at the start */
    s32 score[4];  /* then how many players share each rank */
    s32 rank[4];
    u8 state[4];
    u8 count[4];
    u8 flags[4];
    s32 i;
    s32 j;
    s32 k;
    s16 win;
    s32 win2;

    HuPrcSleep(16);
    func_80060128(16);
    HuPrcSleep(10);
    for (i = 0; i < 4; i++) {
        GwCommon.boardWork[10 + i] = 0;
    }
    win = CreateTextWindow(30, 42, 18, 4);
    SHOW_MESSAGE(win, 0x106);

    /* the stars */
    for (j = 0; j < 4; j++) {
        order[j] = GwPlayer[j].stars;
        flags[j] = 0;
        for (i = 0; i < 4; i++) {
            if (i != j && GwPlayer[j].stars < GwPlayer[i].stars) {
                flags[j] = 1;
            }
        }
    }
    for (j = 0; j < 4; j++) {
        if (flags[j] != 0) {
            func_8004F4D4(GwPlayer[j].player_obj, 4, 0);
        }
    }
    for (j = 0; j < 4; j++) {
        if (GwPlayer[j].stars != 0) {
            PlaySound(0x48);
            break;
        }
    }
    for (j = 0; j < 4; j++) {
        if (order[j] > 0) {
            D_800FA4A4_UnknownEndGameBonuses1[j] = func_80042728(D_800FA738_UnknownEndGameBonuses1[j], 1);
        }
    }
    for (k = 200; k < 800; k += 15) {
        for (j = 0; j < 4; j++) {
            if (order[j] > 0) {
                MBModelDispOn(D_800FA738_UnknownEndGameBonuses1[j]);
                func_800A0D00(&D_800FA738_UnknownEndGameBonuses1[j]->coords, GwPlayer[j].player_obj->coords.x,
                              k + GwPlayer[j].player_obj->coords.y, GwPlayer[j].player_obj->coords.z);
                D_800FA738_UnknownEndGameBonuses1[j]->unk_18.x = sinf((k * 2) * DEG);
                D_800FA738_UnknownEndGameBonuses1[j]->unk_18.z = cosf((k * 2) * DEG);
            }
        }
        HuPrcVSleep();
        if (k == 350) {
            func_800F7580_UnknownEndGameBonuses1();
        }
    }
    for (j = 0; j < 4; j++) {
        if (order[j] > 0) {
            func_800427D4(D_800FA4A4_UnknownEndGameBonuses1[j]);
            D_800FA4A4_UnknownEndGameBonuses1[j] = NULL;
        }
    }
    func_8004FFA8();
    func_800F7918_UnknownEndGameBonuses1();
    for (i = 0; i < 4; i++) {
        if (flags[i] != 0) {
            func_8004F4D4(GwPlayer[i].player_obj, 3, 2);
        }
    }

    /* the coins */
    win = CreateTextWindow(30, 42, 17, 4);
    SHOW_MESSAGE(win, 0xFD);
    for (j = 0; j < 4; j++) {
        if (GwPlayer[j].coins != 0) {
            PlaySound(0x65);
            break;
        }
    }
    for (k = 200, i = 0; k < 310; k += 5, i += 20) {
        for (j = 0; j < 4; j++) {
            func_800258EC((s16)D_800FA748_UnknownEndGameBonuses1[j], 4, 0);
            func_80025798((s16)D_800FA748_UnknownEndGameBonuses1[j], GwPlayer[j].player_obj->coords.x,
                          k + GwPlayer[j].player_obj->coords.y, GwPlayer[j].player_obj->coords.z);
            func_800257E4((s16)D_800FA748_UnknownEndGameBonuses1[j], 0.0f, i, 0.0f);
            func_80025830((s16)D_800FA748_UnknownEndGameBonuses1[j], 0.25f - i / 1000.0f, 0.25f - i / 1000.0f,
                          0.25f - i / 1000.0f);
        }
        HuPrcVSleep();
    }
    for (j = 0; j < 4; j++) {
        func_800258EC((s16)D_800FA748_UnknownEndGameBonuses1[j], 4, 4);
    }
    func_800F70D0_UnknownEndGameBonuses1();
    func_8004FFA8();
    func_800F74E4_UnknownEndGameBonuses1();

    /* the bonus stars */
    win = CreateTextWindow(30, 42, 18, 4);
    SHOW_MESSAGE(win, 0x107);
    win = CreateTextWindow(30, 42, 18, 4);
    SHOW_MESSAGE(win, 0x108);
    BONUS_STAR(MINIGAME_COINS, 15, 17, 17, 17, 0x109);
    win = CreateTextWindow(30, 42, 15, 4);
    SHOW_MESSAGE(win, 0x10D);
    BONUS_STAR(MAX_COINS, 15, 17, 17, 17, 0x10E);
    win = CreateTextWindow(30, 42, 16, 4);
    SHOW_MESSAGE(win, 0x112);
    BONUS_STAR(HAPPENINGS, 17, 17, 17, 19, 0x113);

    /* the ranking: stars first, then coins */
    for (j = 0; j < 4; j++) {
        score[j] = (GwPlayer[j].stars + GwCommon.boardWork[10 + j]) * 1000 + GwPlayer[j].coins;
    }
    for (i = 0; i < 4; i++) {
        for (j = 0, k = 0; j < 4; j++) {
            if (i != j) {
                k += score[i] < score[j];
            }
        }
        rank[i] = k;
    }
    for (i = 0; i < 4; i++) {
        score[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        score[rank[i]]++;
    }
    /* ties: a dice block decides */
    for (i = 0; i < 4; i++) {
        if (score[i] < 2) {
            continue;
        }
        win2 = CreateTextWindow(30, 42, 18, 4);
        for (j = 0, k = 0; j < 4; j++) {
            if (rank[j] == i) {
                func_8006DA5C(win2, D_800C5218[GwPlayer[j].character], k++);
            }
        }
        if (k == 4) {
            LoadStringIntoWindow(win2, (void*)0x101, -1, -1);
        } else if (k == 3) {
            func_8006DA5C(win2, "\xA4", 3);
            LoadStringIntoWindow(win2, (void*)0x100, -1, -1);
        } else {
            func_8006DA5C(win2, "", 2);
            func_8006DA5C(win2, "", 3);
            LoadStringIntoWindow(win2, (void*)0xFF, -1, -1);
        }
        func_8006E070(win2, 0);
        ShowTextWindow((s16)win2);
        PlaySound(0x432);
        WaitForTextConfirmation(win2);
        HideTextWindow((s16)win2);
        func_8003FCD4();
        func_8003FC94();
        for (j = 0; j < 4; j++) {
            if (rank[j] == i) {
                func_80040780(j);
                func_8003FD68(j);
                state[j] = 1;
            } else {
                state[j] = 0;
            }
            count[j] = 0;
            timers[j] = (u8)(rand8() % 30) + 5;
        }
        func_8004157C();
        HuPrcSleep(20);
        while (1) {
            for (j = 0; j < 4; j++) {
                timers[j]--;
                switch (state[j]) {
                case 1:
                    if (GwPlayer[j].flags & 1) {
                        if (timers[j] <= 0) {
                            goto press;
                        }
                    } else if (ContBtnTrg[GwPlayer[j].port] & 0x8000) {
                    press:
                        state[j] = 2;
                        MBMotionSet(GwPlayer[j].player_obj, 2, 0);
                        func_8004F40C(GwPlayer[j].player_obj, 3, 2);
                    }
                    break;
                case 2:
                    count[j]++;
                    if (count[j] == 5) {
                        func_800413B0(j);
                        state[j] = 0;
                    }
                    break;
                }
            }
            for (j = 0; j < 4; j++) {
                if (state[j] != 0) {
                    break;
                }
            }
            if (j == 4) {
                break;
            }
            HuPrcVSleep();
        }
        HuPrcSleep(20);
        for (j = 0; j < 4; j++) {
            state[j] = func_800415E8(j);
            order[j] = j;
        }
        for (k = 0; k < 4; k++) {
            for (j = k; j < 4; j++) {
                if (state[k] < state[j]) {
                    timers[0] = state[k];
                    state[k] = state[j];
                    state[j] = timers[0];
                    timers[0] = order[k];
                    order[k] = order[j];
                    order[j] = timers[0];
                }
            }
        }
        if (score[i] == 2 || score[i] == 4) {
            win2 = CreateTextWindow(30, 60, 15, 1);
            func_8006DA5C(win2, D_800C5218[GwPlayer[order[0]].character], 0);
            rank[order[1]] = i + 1;
            if (score[i] == 4) {
                rank[order[2]] = i + 2;
                rank[order[3]] = i + 3;
            }
            SHOW_MESSAGE(win2, 0x102);
        } else {
            win2 = CreateTextWindow(30, 60, 16, 2);
            for (j = 0; j < 3; j++) {
                func_8006DA5C(win2, D_800C5218[GwPlayer[order[j]].character], j);
                rank[order[j]] = i + j;
            }
            SHOW_MESSAGE(win2, 0x103);
        }
        func_80041370();
    }

    /* the winner */
    func_800601D4(130);
    HuPrcSleep(55);
    D_800FA76C_UnknownEndGameBonuses1 = PlaySound(0x479);
    D_800FA76E_UnknownEndGameBonuses1 = PlaySound(0x62);
    D_800FA4A4_UnknownEndGameBonuses1[0] = func_80042728(D_800FA738_UnknownEndGameBonuses1[0], 0);
    D_800FA4A0_UnknownEndGameBonuses1 = omAddObj(0x1000, 0, 0, -1, &func_800F67EC_UnknownEndGameBonuses1);
    D_800FA4A0_UnknownEndGameBonuses1->mdlcnt = 0;
    D_800FA4A0_UnknownEndGameBonuses1->scale.x = 0.0f;
    D_800FA4A0_UnknownEndGameBonuses1->trans.x = 0.0f;
    D_800FA4A0_UnknownEndGameBonuses1->trans.y = GwPlayer[0].player_obj->coords.y + 250.0f;
    D_800FA4A0_UnknownEndGameBonuses1->trans.z = GwPlayer[0].player_obj->coords.z - 100.0f;
    D_800FA4A0_UnknownEndGameBonuses1->work[0] = 0;
    D_800FA4A0_UnknownEndGameBonuses1->work[3] = 0;
    HuPrcSleep(60);
    win = CreateTextWindow(30, 30, 13, 4);
    SHOW_MESSAGE(win, 0x104);
    for (j = 0; j < 4; j++) {
        if (rank[j] == 0) {
            break;
        }
    }
    D_800FA4A0_UnknownEndGameBonuses1->work[0] = 1;
    D_800FA4A0_UnknownEndGameBonuses1->work[1] = j;
    D_800FA4A0_UnknownEndGameBonuses1->work[2] = 0;
    while (1) {
        if (D_800FA4A0_UnknownEndGameBonuses1->work[2] != 0) {
            break;
        }
        HuPrcVSleep();
    }
    func_8006071C(D_800FA76C_UnknownEndGameBonuses1);
    func_8006071C(D_800FA76E_UnknownEndGameBonuses1);
    PlaySound(0x64);
    func_800427D4(D_800FA4A4_UnknownEndGameBonuses1[0]);
    D_800FA4A4_UnknownEndGameBonuses1[0] = NULL;
    HuPrcSleep(10);
    func_80060128(0x3F);
    for (i = 0; i < 4; i++) {
        if (i == j) {
            MBMotionSet(GwPlayer[i].player_obj, 0, 0);
            func_8004F40C(GwPlayer[i].player_obj, 3, 2);
        } else {
            MBMotionSet(GwPlayer[i].player_obj, 1, 0);
        }
    }
    HuPrcSleep(145);
    func_80060128(0x40);
    HuPrcSleep(15);
    win = CreateTextWindow(30, 60, 7, 1);
    func_8006DA5C(win, D_800C5218[GwPlayer[j].character], 0);
    SHOW_MESSAGE(win, 0x105);
    for (i = 0; i < 4; i++) {
        GwCommon.boardWork[rank[i]] = i;
    }

    /* the podium: the star hovers over the winner, the others line up behind */
    D_800FA4A0_UnknownEndGameBonuses1->work[0] = 5;
    D_800FA4A0_UnknownEndGameBonuses1->trans.x = D_800F2B7C[*D_800FA738_UnknownEndGameBonuses1[0]->unk_3C->unk_40].unk_24;
    D_800FA4A0_UnknownEndGameBonuses1->trans.y = sinf(2.0f * D_800FA4A0_UnknownEndGameBonuses1->scale.x * DEG) * 20.0f + D_800FA4A0_UnknownEndGameBonuses1->trans.y;
    D_800FA4A0_UnknownEndGameBonuses1->trans.z = D_800F2B7C[*D_800FA738_UnknownEndGameBonuses1[0]->unk_3C->unk_40].unk_2C;
    func_8004EE14(GwCommon.boardWork[0], &D_800FA51C_UnknownEndGameBonuses1[0], 1, NULL);
    func_8004E3E0(GwCommon.boardWork[0], &D_800FA51C_UnknownEndGameBonuses1[0], 30, NULL);
    func_8004F4D4(GwPlayer[GwCommon.boardWork[0]].player_obj, 5, 2);
    HuPrcSleep(30);
    func_8004EE14(GwCommon.boardWork[0], D_800F32A0, 1, NULL);
    func_8004F4D4(GwPlayer[GwCommon.boardWork[0]].player_obj, 3, 2);
    HuPrcSleep(20);
    func_8004EE14(GwCommon.boardWork[0], &D_800FA4EC_UnknownEndGameBonuses1[GwCommon.boardWork[0]], 20, NULL);
    HuPrcSleep(20);
    D_800FA4A4_UnknownEndGameBonuses1[0] = func_80042728(D_800FA738_UnknownEndGameBonuses1[0], 0);
    D_800FA4A0_UnknownEndGameBonuses1->work[0] = 2;
    D_800FA4A0_UnknownEndGameBonuses1->trans.x = (GwPlayer[GwCommon.boardWork[0]].player_obj->coords.x - D_800F2B7C[*D_800FA738_UnknownEndGameBonuses1[0]->unk_3C->unk_40].unk_24) / 20.0f;
    D_800FA4A0_UnknownEndGameBonuses1->trans.z = (GwPlayer[GwCommon.boardWork[0]].player_obj->coords.z - 100.0f - D_800F2B7C[*D_800FA738_UnknownEndGameBonuses1[0]->unk_3C->unk_40].unk_2C) / 20.0f;
    D_800FA4A0_UnknownEndGameBonuses1->trans.y = (300.0f - D_800F2B7C[*D_800FA738_UnknownEndGameBonuses1[0]->unk_3C->unk_40].unk_28) / 20.0f;
    D_800FA4A0_UnknownEndGameBonuses1->work[2] = 20;
    for (i = 0, j = 1; i < 4; i++) {
        if (i != GwCommon.boardWork[0]) {
            func_8004EE14(i, &D_800FA51C_UnknownEndGameBonuses1[j], 5, NULL);
            func_8004E3E0(i, &D_800FA51C_UnknownEndGameBonuses1[j++], 20, NULL);
            func_8004F4D4(GwPlayer[i].player_obj, 5, 2);
        }
    }
    HuPrcSleep(20);
    func_800427D4(D_800FA4A4_UnknownEndGameBonuses1[0]);
    D_800FA4A4_UnknownEndGameBonuses1[0] = NULL;
    for (i = 0; i < 4; i++) {
        if (i != GwCommon.boardWork[0]) {
            func_8004F4D4(GwPlayer[i].player_obj, 3, 2);
            func_8004EE14(i, &GwPlayer[GwCommon.boardWork[0]].player_obj->coords, 10, NULL);
        }
    }
    /* retail passes player 0 here whoever won */
    func_8004EE14(0, &GwPlayer[GwCommon.boardWork[0]].player_obj->coords, 10, D_800FA734_UnknownEndGameBonuses1);
    func_8004EE14(GwCommon.boardWork[0], D_800F32A0, 20, NULL);
    HuPrcSleep(30);
    func_8004F4D4(GwPlayer[GwCommon.boardWork[0]].player_obj, 6, 0);
    while (1) {
        if (MBMotionCheck(GwPlayer[GwCommon.boardWork[0]].player_obj) & 1) {
            break;
        }
        HuPrcVSleep();
    }
    func_800F667C_UnknownEndGameBonuses1();
    func_8004FFA8();
    D_800F5144 = 1;
    while (1) {
        HuPrcVSleep();
    }
}
#else
/* the local arrays' templates and strings, which the asm references by name */
const u8 D_800FA6D8_UnknownEndGameBonuses1[4] __attribute__((section(".rodata"))) = { 15, 17, 17, 17 };
const u8 D_800FA6DC_UnknownEndGameBonuses1[4] __attribute__((section(".rodata"))) = { 2, 3, 4, 4 };
const s32 D_800FA6E0_UnknownEndGameBonuses1[4] __attribute__((section(".rodata"))) = { 0x109, 0x10A, 0x10B, 0x10C };
const s32 D_800FA6F0_UnknownEndGameBonuses1[4] __attribute__((section(".rodata"))) = { 0x10E, 0x10F, 0x110, 0x111 };
const u8 D_800FA700_UnknownEndGameBonuses1[4] __attribute__((section(".rodata"))) = { 17, 17, 17, 19 };
const s32 D_800FA704_UnknownEndGameBonuses1[4] __attribute__((section(".rodata"))) = { 0x113, 0x114, 0x115, 0x116 };
const char D_800FA714_UnknownEndGameBonuses1[] __attribute__((section(".rodata"))) = "\xA4";
const char D_800FA718_UnknownEndGameBonuses1[] __attribute__((section(".rodata"))) = "";
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_43_UnknownEndGameBonuses1/27CB30", func_800F7DE0_UnknownEndGameBonuses1);
#endif

void func_800F9E18_UnknownEndGameBonuses1(omObjData* obj) {
    func_80070ED4();
    omOvlGotoEx(0x40, 0, 0x1094);
}

void func_800F9E44_UnknownEndGameBonuses1(omObjData* obj) {
    if (++D_800FA7D8_UnknownEndGameBonuses1 >= 5) {
        obj->func_ptr = &func_800F9E18_UnknownEndGameBonuses1;
    }
}

void func_800F9E78_UnknownEndGameBonuses1(omObjData* obj) {
    if (func_80072718() == 0) {
        func_800FA474_UnknownEndGameBonuses1();
        func_800FA264_UnknownEndGameBonuses1();
        func_800427E4();
        func_800F6730_UnknownEndGameBonuses1();
        D_800FA7D8_UnknownEndGameBonuses1 = 0;
        obj->func_ptr = &func_800F9E44_UnknownEndGameBonuses1;
    }
}

void func_800F9ED8_UnknownEndGameBonuses1(omObjData* obj) {
    if (D_800F5144 != 0) {
        func_800726AC(0, 0x14);
        obj->func_ptr = &func_800F9E78_UnknownEndGameBonuses1;
    }
}

void func_800F9F1C_UnknownEndGameBonuses1(void) {
    s32 i;

    MBModelInit();
    func_80053020();
    func_8004F2AC();
    for (i = 0; i < 4; i++) {
        func_80052DC8(i, D_800FA63C_UnknownEndGameBonuses1[GwPlayer[i].character]);
        func_80021B14(*GwPlayer[i].player_obj->unk_3C->unk_40, GwPlayer[i].character, 0);
        GwPlayer[i].player_obj->coords.x = D_800FA4EC_UnknownEndGameBonuses1[i].x;
        GwPlayer[i].player_obj->coords.y = D_800FA4EC_UnknownEndGameBonuses1[i].y;
        GwPlayer[i].player_obj->coords.z = D_800FA4EC_UnknownEndGameBonuses1[i].z;
        GwPlayer[i].flags |= 2;
        func_8004CCD0(&GwPlayer[i].player_obj->coords, &D_800F32A0->coords, &GwPlayer[i].player_obj->unk_18);
    }
    D_800FA734_UnknownEndGameBonuses1 = MBModelCreate(8, NULL);
    D_800FA734_UnknownEndGameBonuses1->coords.x = D_800FA558_UnknownEndGameBonuses1.x;
    D_800FA734_UnknownEndGameBonuses1->coords.y = D_800FA558_UnknownEndGameBonuses1.y;
    D_800FA734_UnknownEndGameBonuses1->coords.z = D_800FA558_UnknownEndGameBonuses1.z;
    func_8004CCD0(&D_800FA734_UnknownEndGameBonuses1->coords, &D_800F32A0->coords, &D_800FA734_UnknownEndGameBonuses1->unk_18);
    func_8004F140(*D_800FA734_UnknownEndGameBonuses1->unk_3C->unk_40);
    for (i = 0; i < 4; i++) {
        if (i == 0) {
            D_800FA738_UnknownEndGameBonuses1[0] = MBModelCreate(0x40, NULL);
            MBModelDispOff(D_800FA738_UnknownEndGameBonuses1[0]);
            D_800FA748_UnknownEndGameBonuses1[0] = func_8004F25C_unproto();
            func_800258EC((s16)D_800FA748_UnknownEndGameBonuses1[0], 4, 4);
        } else {
            D_800FA738_UnknownEndGameBonuses1[i] = MBModelParamCreate(D_800FA738_UnknownEndGameBonuses1[0]);
            MBModelDispOff(D_800FA738_UnknownEndGameBonuses1[i]);
            D_800FA748_UnknownEndGameBonuses1[i] = func_80023FC8_unproto((s16)D_800FA748_UnknownEndGameBonuses1[0]);
        }
        func_800A0D00(&D_800FA738_UnknownEndGameBonuses1[i]->coords, GwPlayer[i].player_obj->coords.x,
                      GwPlayer[i].player_obj->coords.y + 800.0f, GwPlayer[i].player_obj->coords.z);
        func_800A0D00((Vec3f*)&D_800FA738_UnknownEndGameBonuses1[i]->xScale, 0.75f, 0.75f, 0.75f);
        D_800FA738_UnknownEndGameBonuses1[i]->unk_18.x = 0.0f;
        D_800FA738_UnknownEndGameBonuses1[i]->unk_18.z = 1.0f;
        func_80025798((s16)D_800FA748_UnknownEndGameBonuses1[i], GwPlayer[i].player_obj->coords.x,
                      GwPlayer[i].player_obj->coords.y + 200.0f, GwPlayer[i].player_obj->coords.z);
        func_80025830((s16)D_800FA748_UnknownEndGameBonuses1[i], 0.25f, 0.25f, 0.25f);
        func_800257E4((s16)D_800FA748_UnknownEndGameBonuses1[i], 0.0f, 0.0f, 0.0f);
    }
}

void func_800FA264_UnknownEndGameBonuses1(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_80052FD4(i);
    }
    func_8004F1D0();
    MBModelKill(D_800FA734_UnknownEndGameBonuses1);
    for (i = 0; i < 4; i++) {
        MBModelKill(D_800FA738_UnknownEndGameBonuses1[i]);
        func_8002456C((s16)D_800FA748_UnknownEndGameBonuses1[i]);
        if (D_800FA4BC_UnknownEndGameBonuses1[i] != NULL) {
            omDelObj(D_800FA4BC_UnknownEndGameBonuses1[i]);
        }
        if (D_800FA4A4_UnknownEndGameBonuses1[i] != NULL) {
            func_800427D4(D_800FA4A4_UnknownEndGameBonuses1[i]);
        }
    }
    if (D_800FA4A0_UnknownEndGameBonuses1 != NULL) {
        omDelObj(D_800FA4A0_UnknownEndGameBonuses1);
    }
    if (D_800FA4B4_UnknownEndGameBonuses1 != -1) {
        func_8002456C((s16)D_800FA4B4_UnknownEndGameBonuses1);
        D_800FA4B4_UnknownEndGameBonuses1 = -1;
    }
    if (D_800FA4B8_UnknownEndGameBonuses1 != NULL) {
        omDelObj(D_800FA4B8_UnknownEndGameBonuses1);
        D_800FA4B8_UnknownEndGameBonuses1 = NULL;
    }
    func_8004F2EC();
}

void func_800FA3C0_UnknownEndGameBonuses1(void) {
    func_800178A0(1);
    func_80017660(0, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    LoadBackgroundData(FE2310_ROM_START);
    LoadBackgroundIndex(D_800FA4CC_UnknownEndGameBonuses1[D_800FA730_UnknownEndGameBonuses1]);
}

void func_800FA474_UnknownEndGameBonuses1(void) {
    func_8004A140();
    func_80049F0C();
}
