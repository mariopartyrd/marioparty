#include "common.h"

/* The head of 42E40.c's SpriteAnimWork (func_800429CC's result); no pointers before 0x10. */
typedef struct ResSpriteAnim {
    /* 0x00 */ u16 flags;
    /* 0x02 */ s16 frame;
    /* 0x04 */ s16 count;
    /* 0x06 */ u16 attr;
    /* 0x08 */ s16 x;
    /* 0x0A */ s16 y;
    /* 0x0C */ f32 scale;
} ResSpriteAnim;

extern TextWindow* D_800ED4B0;
extern char* D_800C5218[]; /* character names */

void* func_800429CC(s16, s16);
void func_80042B10(ResSpriteAnim*);
void func_8004DBD4(s32, s32);
void func_80059448(s16 arg0);
s16 func_8005949C(s32);
void func_8005B300(void);
void func_8005B358(u8* buf);
void func_8005C384(void);
void func_8005CE8C(s32 flag);
void func_800532E0(void);
void func_800532F4(void);
void func_80070D90(s16);
s16 func_8006D93C(u8*);

s32 func_800F667C_MinigameIslandFinish(void);
s32 func_800F66C8_MinigameIslandFinish(s32 flag);
void func_800F670C_MinigameIslandFinish(void);
void func_800F6944_MinigameIslandFinish(void);
void func_800F697C_MinigameIslandFinish(void);
void func_800F6B94_MinigameIslandFinish(s16 arg0);
s16 func_800F6BC8_MinigameIslandFinish(s16 msg);
void func_800F6D68_MinigameIslandFinish(void);
void func_800F8BF4_MinigameIslandFinish(void);
void func_800F8C94_MinigameIslandFinish(omObjData* obj);
void func_800F8CE0_MinigameIslandFinish(void);
void func_800F8F04_MinigameIslandFinish(void);
void func_800F8F48_MinigameIslandFinish(void);
void func_800F8FE8_MinigameIslandFinish(void);

/* set when the player chose to see the instructions (ovl_6F) next */
s32 D_800F9010_MinigameIslandFinish = 0;
Vec3f D_800F9014_MinigameIslandFinish = { -430.0f, 0.0f, 1400.0f };
Vec3f D_800F9020_MinigameIslandFinish = { -160.0f, 0.0f, 1400.0f };
Vec3f D_800F902C_MinigameIslandFinish = { 430.0f, 0.0f, 1400.0f };
Vec3f D_800F9038_MinigameIslandFinish = { 140.0f, 0.0f, 1400.0f };
Vec3f D_800F9044_MinigameIslandFinish = { 400.0f, 0.0f, -6200.0f };
Vec3f D_800F9050_MinigameIslandFinish = { 650.0f, 0.0f, -4400.0f };
/* boat path: [0] D_800F905C, [1] D_800F9068, [2] D_800F9074, [3] (+0x24) */
Vec3f D_800F905C_MinigameIslandFinish[4] = {
    { 75.0f, 0.0f, 500.0f },
    { 0.0f, 0.0f, 1156.0f },
    { -1000.0f, 300.0f, 1200.0f },
    { 400.0f, -200.0f, 0.0f },
};
/* MBModelCreate motion lists */
s32 D_800F908C_MinigameIslandFinish[] = { 2, 0x00070003, 0x00070004 };
s32 D_800F9098_MinigameIslandFinish[] = { 3, 0x000A0072, 0x000A0073, 0x000A0074 };
s32 D_800F90A8_MinigameIslandFinish[] = { 3, 0x00010001, 0x00010003, 0x0001000F };
s32 D_800F90B8_MinigameIslandFinish[] = { 3, 0x00020001, 0x00020003, 0x0002000F };
s32 D_800F90C8_MinigameIslandFinish[] = { 3, 0x00060001, 0x00060003, 0x0006000F };
s32 D_800F90D8_MinigameIslandFinish[] = { 3, 0x00030001, 0x00030003, 0x0003000F };
s32 D_800F90E8_MinigameIslandFinish[] = { 3, 0x00040001, 0x00040003, 0x0004000F };
s32 D_800F90F8_MinigameIslandFinish[] = { 3, 0x00050001, 0x00050003, 0x0005000F };
s32* D_800F9108_MinigameIslandFinish[] = {
    D_800F90A8_MinigameIslandFinish, D_800F90B8_MinigameIslandFinish, D_800F90C8_MinigameIslandFinish,
    D_800F90D8_MinigameIslandFinish, D_800F90E8_MinigameIslandFinish, D_800F90F8_MinigameIslandFinish,
};
/* message and window width per character */
s32 D_800F9120_MinigameIslandFinish[] = { 0x49F, 0x4A0, 0x4A1, 0x4A2, 0x4A3, 0x4A4 };
u8 D_800F9138_MinigameIslandFinish[] = { 0x10, 0x11, 0x11, 0x0D, 0x10, 0x0F };
/* window id; retail also reads its low half, D_800F9142 */
s32 D_800F9140_MinigameIslandFinish = -1;
ResSpriteAnim* D_800F9144_MinigameIslandFinish = NULL;

/* .bss */
extern Object* D_800F9170_MinigameIslandFinish;
extern Object* D_800F9174_MinigameIslandFinish;
extern Object* D_800F9178_MinigameIslandFinish;
extern Object* D_800F917C_MinigameIslandFinish;
extern Object* D_800F9180_MinigameIslandFinish;
extern GWQUEST D_800F9184_MinigameIslandFinish; /* the saved quest, read back from EEPROM */
extern s16 D_800F9194_MinigameIslandFinish[]; /* message lines: font ids */
extern s16 D_800F9198_MinigameIslandFinish[]; /* message lines: widths */
extern unkCommonStruct0 D_800F91A0_MinigameIslandFinish; /* retail labels .unk_14 / .unk_34 D_800F91B4 / D_800F91D4 */

#define WIN ((s16)D_800F9140_MinigameIslandFinish)
#define MES D_800F91A0_MinigameIslandFinish
#define HOST D_800F9170_MinigameIslandFinish
#define PLAYER D_800F9174_MinigameIslandFinish
#define BOAT D_800F9178_MinigameIslandFinish
#define BALLOON D_800F9180_MinigameIslandFinish

void func_800F65E0_MinigameIslandFinish(void) {
    omInitObjMan(0x32, 0xA);
    func_800F8F48_MinigameIslandFinish();
    func_800F8CE0_MinigameIslandFinish();
    func_8006CEA0();
    func_800532E0();
    omAddPrcObj(func_800F6D68_MinigameIslandFinish, 0x2000, 0, 0);
    omAddObj(0x1000, 0, 0, -1, func_800F8C94_MinigameIslandFinish);
    if (GwPlayer[0].coins_mg == 0) {
        func_80060128(0x13);
    }
    SetFadeInTypeAndTime(2, 0x10);
}

s32 func_800F667C_MinigameIslandFinish(void) {
    s32 i;
    s32 var_s1 = 0;

    for (i = 7; i < 57; i++) {
        var_s1 += func_8005CE48(i) != 0;
    }

    return var_s1;
}

/* func_8005CE48 on the saved quest */
s32 func_800F66C8_MinigameIslandFinish(s32 flag) {
    return (s8)D_800F9184_MinigameIslandFinish.mgFlag[flag / 8] & (1 << (flag % 8));
}

void func_800F670C_MinigameIslandFinish(void) {
    char buf0[8];
    char buf1[8];
    char buf2[16];
    s32 i;
    s32 count;
    ResSpriteAnim* spr;

    func_8005B358((u8*)&D_800F9184_MinigameIslandFinish);
    count = 0;
    for (i = 7; i < 57; i++) {
        count += func_800F66C8_MinigameIslandFinish(i) != 0;
    }
    spr = func_800429CC(D_800F9184_MinigameIslandFinish.charNo, 0);
    D_800F9144_MinigameIslandFinish = spr;
    spr->flags |= 2;
    spr->x = 0x3E;
    spr->y = 0x5A;
    spr->attr = 0x10;
    D_800F9140_MinigameIslandFinish = CreateTextWindow(0x18, 0x34, 0x18, 5);
    D_800ED4B0[D_800F9140_MinigameIslandFinish].unk_08 = 0x14;
    D_800ED4B0[D_800F9140_MinigameIslandFinish].unk_2A = 0x46;
    D_800ED4B0[D_800F9140_MinigameIslandFinish].unk_24 = 0x50;
    D_800ED4B0[D_800F9140_MinigameIslandFinish].unk_26 = 0xA;
    func_8006E154(WIN, 0x100);
    sprintf(buf0, "%2d", count);
    if (func_800F66C8_MinigameIslandFinish(0x38) != 0) {
        func_8006DA5C(WIN, "\x05", 0);
    } else {
        func_8006DA5C(WIN, "\x08", 0);
    }
    func_8006DA5C(WIN, buf0, 1);
    sprintf(buf1, "%2d", D_800F9184_MinigameIslandFinish.lifeNum);
    func_8006DA5C(WIN, buf1, 2);
    sprintf(buf2, "%2d", D_800F9184_MinigameIslandFinish.coinNum);
    func_8006DA5C(WIN, buf2, 3);
    func_8006E070(WIN, 0);
    LoadStringIntoWindow(WIN, (void*)0x4DB, 0x50, 0xA);
    while (func_8006FCC0(WIN) != 0) {
        HuPrcVSleep();
    }
}

void func_800F6944_MinigameIslandFinish(void) {
    if (D_800F9144_MinigameIslandFinish != NULL) {
        func_80042B10(D_800F9144_MinigameIslandFinish);
        func_80070D90(WIN);
    }
}

void func_800F697C_MinigameIslandFinish(void) {
    char buf0[8];
    char buf1[8];
    char buf2[16];
    s32 i;
    s32 count;
    ResSpriteAnim* spr;

    if (D_800F9144_MinigameIslandFinish != NULL) {
        count = 0;
        func_80042B10(D_800F9144_MinigameIslandFinish);
        spr = func_800429CC(GwPlayer[0].character, 0);
        D_800F9144_MinigameIslandFinish = spr;
        spr->x = 0x3E;
        spr->y = 0x5A;
        spr->attr = 0x10;
        for (i = 7; i < 57; i++) {
            count += func_8005CE48(i) != 0;
        }
        sprintf(buf0, "%2d", count);
        if (func_8005CE48(0x38) != 0) {
            func_8006DA5C(WIN, "\x05", 0);
        } else {
            func_8006DA5C(WIN, "\x08", 0);
        }
        func_8006DA5C(WIN, buf0, 1);
        sprintf(buf1, "%2d", GwQuest.lifeNum);
        func_8006DA5C(WIN, buf1, 2);
        sprintf(buf2, "%2d", GwQuest.coinNum);
        func_8006DA5C(WIN, buf2, 3);
        func_8006DA1C(WIN, 0, 4);
        LoadStringIntoWindow(WIN, (void*)0x4DC, 0xB8, 0xA);
        while (func_8006FCC0(WIN) != 0) {
            HuPrcVSleep();
        }
        LoadStringIntoWindow(WIN, (void*)0x4DD, 0x72, 0x20);
        while (func_8006FCC0(WIN) != 0) {
            HuPrcVSleep();
        }
        LoadStringIntoWindow(WIN, (void*)0x4DE, 0x76, 0x36);
        while (func_8006FCC0(WIN) != 0) {
            HuPrcVSleep();
        }
    }
}

void func_800F6B94_MinigameIslandFinish(s16 arg0) {
    s16 thing = 1 << GwPlayer[0].port;
    func_8007155C(arg0, thing);
}

/* splits message msg + 0x325 into lines (font ids/widths in D_800F9194/D_800F9198); returns the last line index */
s16 func_800F6BC8_MinigameIslandFinish(s16 msg) {
    u8* text;
    u8* line;
    u8* p;
    s16 n;

    text = func_8005B7E8(msg + 0x325);
    line = text;
    p = text;
    for (n = 0; n < 16; n++) {
        MES.unk_34[n] = MES.unk_14[n] = -1;
    }
    n = 0;
    while (*p != 0) {
        if (*p == '\n') {
            *p = 0;
            D_800F9194_MinigameIslandFinish[n] = GMesFontCreate(&MES, line, 0, -1, -1);
            D_800F9198_MinigameIslandFinish[n] = func_8006D93C(line);
            n++;
            line = p + 1;
        }
        p++;
    }
    D_800F9194_MinigameIslandFinish[n] = GMesFontCreate(&MES, line, 0, -1, -1);
    D_800F9198_MinigameIslandFinish[n] = func_8006D93C(line);
    func_8005B838(text);
    return n;
}

/* a message balloon (model 0x85) carrying msg's lines rises from (x, y, z), floats to the
   player and shrinks away */
#define BALLOON_MESSAGE(msg, px, py, pz, pos, screen, ofs)                                              \
    {                                                                                              \
        Vec3f ofs = { 0.0f, 80.0f, 0.0f };                                                         \
        f32 scale;                                                                                 \
        s16 n;                                                                                     \
        s32 i;                                                                                     \
        s16 j;                                                                                     \
        s32 k;                                                                                     \
                                                                                                   \
        n = func_800F6BC8_MinigameIslandFinish(msg);                                               \
        func_80066DC4(MES.unk_14[0], 0, 0x50, 0x78);                                               \
        BALLOON = MBModelCreate(0x85, NULL);                                                       \
        func_800A0D00(&BALLOON->coords, px, py, pz);                                                  \
        func_800A0D00(&BALLOON->unk_18, 0.0f, 0.0f, -1.0f);                                        \
        func_800258EC(*BALLOON->unk_3C->unk_40, 4, 4);                                             \
        PlaySound(0x11);                                                                           \
        scale = 0.0f;                                                                              \
        do {                                                                                       \
            func_800A0D00((Vec3f*)&BALLOON->xScale, scale / 2.0f, scale / 2.0f, scale / 2.0f);     \
            func_800A0D00(&pos, BALLOON->coords.x, BALLOON->coords.y, BALLOON->coords.z);          \
            func_8004B730(&pos, &screen);                                                          \
            for (i = 0; i < n + 1; i++) {                                                          \
                func_80066DC4(MES.unk_14[D_800F9194_MinigameIslandFinish[i]], 0, screen.x,         \
                              (i * 16 - n * 8) * scale + screen.y);                                \
                for (j = 0; j < D_800F9198_MinigameIslandFinish[i]; j++) {                         \
                    func_80067354(MES.unk_14[D_800F9194_MinigameIslandFinish[i]], j + 1, scale, scale); \
                }                                                                                  \
            }                                                                                      \
            BALLOON->coords.y += 5.0f;                                                             \
            HuPrcVSleep();                                                                         \
            func_800258EC(*BALLOON->unk_3C->unk_40, 4, 0);                                         \
            scale += 0.1f;                                                                         \
        } while (scale < 1.0f);                                                                    \
        scale = 1.0f;                                                                              \
        func_800A0D00((Vec3f*)&BALLOON->xScale, scale / 2.0f, scale / 2.0f, scale / 2.0f);         \
        func_800A0D00(&pos, BALLOON->coords.x, BALLOON->coords.y, BALLOON->coords.z);              \
        func_8004B730(&pos, &screen);                                                              \
        for (i = 0; i < n + 1; i++) {                                                              \
            func_80066DC4(MES.unk_14[D_800F9194_MinigameIslandFinish[i]], 0, screen.x,             \
                          (i * 16 - n * 8) * scale + screen.y);                                    \
            for (j = 0; j < D_800F9198_MinigameIslandFinish[i]; j++) {                             \
                func_80067354(MES.unk_14[D_800F9194_MinigameIslandFinish[i]], j + 1, scale, scale); \
            }                                                                                      \
        }                                                                                          \
        HuPrcSleep(0x14);                                                                          \
        func_800A0D00(&pos, PLAYER->coords.x, PLAYER->coords.y + 200.0f, PLAYER->coords.z);        \
        func_8004EA8C(BALLOON, &pos, 0x1E, &ofs);                                                  \
        for (k = 0; k < 0x1F; k++) {                                                               \
            func_800A0D00(&pos, BALLOON->coords.x, BALLOON->coords.y, BALLOON->coords.z);          \
            func_8004B730(&pos, &screen);                                                          \
            for (i = 0; i < n + 1; i++) {                                                          \
                func_80066DC4(MES.unk_14[D_800F9194_MinigameIslandFinish[i]], 0, screen.x,         \
                              (i * 16 - n * 8) * scale + screen.y);                                \
            }                                                                                      \
            HuPrcVSleep();                                                                         \
        }                                                                                          \
        HuPrcSleep(0x14);                                                                          \
        while (scale > 0.1f) {                                                                     \
            func_800A0D00((Vec3f*)&BALLOON->xScale, scale / 2.0f, scale / 2.0f, scale / 2.0f);     \
            func_800A0D00(&pos, BALLOON->coords.x, BALLOON->coords.y, BALLOON->coords.z);          \
            func_8004B730(&pos, &screen);                                                          \
            for (i = 0; i < n + 1; i++) {                                                          \
                func_80066DC4(MES.unk_14[D_800F9194_MinigameIslandFinish[i]], 0, screen.x,         \
                              (i * 16 - n * 8) * scale + screen.y);                                \
                for (j = 0; j < D_800F9198_MinigameIslandFinish[i]; j++) {                         \
                    func_80067354(MES.unk_14[D_800F9194_MinigameIslandFinish[i]], j + 1, scale, scale); \
                }                                                                                  \
            }                                                                                      \
            BALLOON->coords.y -= 5.0f;                                                             \
            HuPrcVSleep();                                                                         \
            scale -= 0.1f;                                                                         \
        }                                                                                          \
        func_80077044(&MES);                                                                       \
        MBModelKill(BALLOON);                                                                      \
        func_800503B0(0, 2);                                                                       \
        HuPrcVSleep();                                                                             \
    }

#define SHOW_MESSAGE(win, x, y, w, h, msg, sound)  \
    win = CreateTextWindow(x, y, w, h);            \
    LoadStringIntoWindow(win, (void*)msg, -1, -1); \
    func_8006E070(win, 0);                         \
    ShowTextWindow(win);                           \
    PlaySound(sound);                              \
    func_8004DBD4(win, 0);                         \
    HideTextWindow(win)

// register allocation in the balloon loops (n + 1 kept on the stack, i/j/k registers) and some block order (masked ~500 of 1,955)
#ifdef NON_MATCHING
void func_800F6D68_MinigameIslandFinish(void) {
    Vec3f pos;
    Vec2f screen;
    s32 win;
    s32 choice;
    s32 msg;

    HuPrcSleep(0x1A);
    if (D_800C597A == 0) {
        GwCommon.boardWork[1] = 0;
        if (func_8005CE48(6) == 0) {
            /* first visit: the boat brings the player to the island */
            func_8005CE8C(6);
            MBMotionSet(HOST, 2, 2);
            func_8004EE14(0, &D_800F9020_MinigameIslandFinish, 1, HOST);
            func_8004E3E0(0, &D_800F9020_MinigameIslandFinish, 0x1E, HOST);
            MBMotionSet(PLAYER, 0, 2);
            func_8004EE14(0, &D_800F9038_MinigameIslandFinish, 1, PLAYER);
            func_8004E3E0(0, &D_800F9038_MinigameIslandFinish, 0x1E, PLAYER);
            HuPrcSleep(0x1E);
            func_8004F4D4(HOST, -1, 2);
            func_8004F4D4(PLAYER, -1, 2);
            SHOW_MESSAGE(win, 0x1E, 0x3C, 0xA, 2, 0x48E, 0x432);
            func_8004E3E0(0, &D_800F9050_MinigameIslandFinish, 0x14, D_800F917C_MinigameIslandFinish);
            func_8004E3E0(0, &D_800F9050_MinigameIslandFinish, 0x14, BOAT);
            HuPrcSleep(0x14);
            func_8004EE14(0, &BOAT->coords, 0xA, HOST);
            func_8004EE14(0, &BOAT->coords, 0xA, PLAYER);
            HuPrcSleep(0xA);
            SHOW_MESSAGE(win, 0x1E, 0x3C, 0x10, 2, 0x48F, 0x437);
            func_8004EA8C(D_800F917C_MinigameIslandFinish, &D_800F905C_MinigameIslandFinish[0], 0x3C, &D_800F905C_MinigameIslandFinish[3]);
            func_8004EA8C(BOAT, &D_800F905C_MinigameIslandFinish[0], 0x3C, &D_800F905C_MinigameIslandFinish[3]);
            for (choice = 0; choice < 0x3C; choice++) {
                func_8004CCD0(&HOST->coords, &BOAT->coords, &HOST->unk_18);
                func_8004CCD0(&PLAYER->coords, &BOAT->coords, &PLAYER->unk_18);
                HuPrcVSleep();
            }
            func_8004E3E0(0, &D_800F905C_MinigameIslandFinish[2], 0x18, D_800F917C_MinigameIslandFinish);
            func_8004E3E0(0, &D_800F905C_MinigameIslandFinish[1], 0x18, BOAT);
            PlaySound(0x466);
            func_8004F00C(BOAT, 40.0f, -3.0f);
            MBMotionSet(BOAT, 1, 2);
            for (choice = 0; choice < 0x18; choice++) {
                func_8004CCD0(&HOST->coords, &BOAT->coords, &HOST->unk_18);
                func_8004CCD0(&PLAYER->coords, &BOAT->coords, &PLAYER->unk_18);
                HuPrcVSleep();
            }
            func_8004F4D4(BOAT, -1, 2);
            win = CreateTextWindow(0x1E, 0x3C, 0xC, 2);
            LoadStringIntoWindow(win, (void*)0x490, -1, -1);
            func_8006E070(win, 0);
            ShowTextWindow(win);
            func_8004DBD4(win, 0);
            HideTextWindow(win);
            func_8004EE14(0, &PLAYER->coords, 0xA, BOAT);
            HuPrcSleep(0xA);
            MBMotionSet(BOAT, 0, 0);
            func_8004F00C(BOAT, 40.0f, -5.0f);
            func_8004F044(BOAT);
            MBMotionSet(BOAT, -1, 2);
            win = CreateTextWindow(0x50, 0x3C, 0xF, 3);
            LoadStringIntoWindow(win, (void*)0x491, -1, -1);
            func_8006E070(win, 0);
            ShowTextWindow(win);
            func_8004DBD4(win, 0);
            PlaySound(0x465);
            func_8006EB40(win);
            LoadStringIntoWindow(win, (void*)0x492, -1, -1);
            func_8006E070(win, 0);
            func_8004DBD4(win, 0);
            HideTextWindow(win);
            D_800F9010_MinigameIslandFinish = 1;
            goto end;
        }
        if (func_8005949C(0x24) == 0 && func_800F667C_MinigameIslandFinish() == 50) {
            win = CreateTextWindow(0x50, 0x3C, 0xF, 3);
            func_8006DA5C(win, D_800C5218[GwPlayer[0].character], 0);
            LoadStringIntoWindow(win, (void*)0x4A5, -1, -1);
            func_8006E070(win, 0);
            ShowTextWindow(win);
            PlaySound(0x465);
            func_8004DBD4(win, 0);
            HideTextWindow(win);
            HuPrcVSleep();
            func_8005C384();
            goto all_cleared;
        }
        goto ask;
    }
    if (GwPlayer[0].coins_mg != 0) {
        /* won: the player's coins go to the island */
        func_8005C384();
        func_80060128(0x3F);
        HuPrcSleep(0x39);
        func_80021CDC(*PLAYER->unk_3C->unk_40, GwPlayer[0].character, 0x81);
        func_8004CCD0(&PLAYER->coords, &D_800C3110->pos, &PLAYER->unk_18);
        func_8004F4D4(PLAYER, 2, 0);
        func_80060468(0x458, GwPlayer[0].character);
        HuPrcSleep(0x58);
        func_80060128(0x40);
        MBMotionSet(BOAT, 0, 0);
        PlaySound(0x465);
        func_8004F00C(BOAT, 40.0f, -5.0f);
        func_8004F044(BOAT);
        MBMotionSet(BOAT, -1, 2);
        win = CreateTextWindow(0x50, 0x3C, 0x11, 3);
        LoadStringIntoWindow(win, (void*)0x493, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        func_8004F4D4(PLAYER, -1, 2);
        func_80021CDC(*PLAYER->unk_3C->unk_40, GwPlayer[0].character, 0x80);
        func_8004DBD4(win, 0);
        HideTextWindow(win);
        func_8004EE14(0, &PLAYER->coords, 0xA, HOST);
        HuPrcSleep(0xA);
        win = CreateTextWindow(0x1E, 0x3C, D_800F9138_MinigameIslandFinish[GwPlayer[0].character], 3);
        LoadStringIntoWindow(win, (void*)(s32)D_800F9120_MinigameIslandFinish[GwPlayer[0].character], -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        PlaySound(0x432);
        func_8004EE14(0, &HOST->coords, 0xA, PLAYER);
        func_8004DBD4(win, 0);
        HideTextWindow(win);
        func_8005CE8C(0x38);
        if (_CheckFlag(0x2E) == 0) {
            SetBoardFeatureFlag(0x2E);
            func_80059448(0x1B);
            SHOW_MESSAGE(win, 0x1E, 0x3C, 0xD, 3, 0x494, 0x437);
            HuPrcVSleep();
            BALLOON_MESSAGE(0x1B, HOST->coords.x + 20.0f + 20.0f, HOST->coords.y + 150.0f, HOST->coords.z, pos, screen, ofs);
            SHOW_MESSAGE(win, 0x1E, 0x3C, 0xC, 3, 0x495, 0x437);
        }
        win = CreateTextWindow(0x1E, 0x3C, 0x10, 3);
        func_8006DA5C(win, D_800C5218[GwPlayer[0].character], 0);
        LoadStringIntoWindow(win, (void*)0x496, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        PlaySound(0x437);
        func_8004DBD4(win, 0);
        HideTextWindow(win);
        MBMotionSet(BOAT, 0, 0);
        PlaySound(0x465);
        func_8004F00C(BOAT, 40.0f, -5.0f);
        func_8004F044(BOAT);
        MBMotionSet(BOAT, -1, 2);
        func_8004EE14(0, &BOAT->coords, 0xA, PLAYER);
        HuPrcSleep(0xA);
        if (func_8005949C(0x24) == 0 && func_800F667C_MinigameIslandFinish() == 50) {
            win = CreateTextWindow(0x50, 0x3C, 0xA, 3);
            func_8006DA5C(win, D_800C5218[GwPlayer[0].character], 0);
            LoadStringIntoWindow(win, (void*)0x4A7, -1, -1);
            func_8006E070(win, 0);
            ShowTextWindow(win);
            func_8004DBD4(win, 0);
            HideTextWindow(win);
            HuPrcVSleep();
        all_cleared:
            func_80059448(0x24);
            {
                Vec3f pos2;
                Vec2f screen2;

                BALLOON_MESSAGE(0x24, BOAT->coords.x + 20.0f, BOAT->coords.y + 150.0f, BOAT->coords.z, pos2, screen2, ofs2);
            }
            win = CreateTextWindow(0x50, 0x3C, 0xF, 3);
            LoadStringIntoWindow(win, (void*)0x4A6, -1, -1);
            func_8006E070(win, 0);
            ShowTextWindow(win);
            func_8004DBD4(win, 0);
            HideTextWindow(win);
        }
    save:
        win = CreateTextWindow(0x50, 0x3C, 0xD, 3);
        LoadStringIntoWindow(win, (void*)0x497, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        func_800F6B94_MinigameIslandFinish(win);
        choice = func_8006FCF0(win, 0, 1);
        HideTextWindow(win);
        if (choice == 0) {
            if (func_8005CE48(0) != 0) {
                func_800F670C_MinigameIslandFinish();
                win = CreateTextWindow(0x50, 0xAA, 0xE, 3);
                LoadStringIntoWindow(win, (void*)0x498, -1, -1);
                func_8006E070(win, 0);
                ShowTextWindow(win);
                func_800F6B94_MinigameIslandFinish(win);
                choice = func_8006FCF0(win, 0, 0);
                HideTextWindow(win);
                if (choice != 0) {
                    func_800F6944_MinigameIslandFinish();
                    goto save;
                }
            }
            func_8005CE8C(0);
            ClearBoardFeatureFlag(0);
            ClearBoardFeatureFlag(0x2D);
            func_8005B300();
            func_800F697C_MinigameIslandFinish();
            win = CreateTextWindow(0x64, (D_800F9144_MinigameIslandFinish == NULL) ? 0x50 : 0xAA, 9, 1);
            LoadStringIntoWindow(win, (void*)0x499, -1, -1);
            func_8006E070(win, 0);
            ShowTextWindow(win);
            func_8004DBD4(win, 0);
            func_800F6944_MinigameIslandFinish();
            HideTextWindow(win);
        }
        win = CreateTextWindow(0x50, 0x3C, 0xF, 2);
        msg = 0x49A;
    last:
        LoadStringIntoWindow(win, (void*)(s32)msg, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        func_8004DBD4(win, 0);
        HideTextWindow(win);
    } else {
        /* lost */
        GwCommon.boardWork[1]++;
        SHOW_MESSAGE(win, 0x50, 0x3C, 0x10, 2, 0x49B, 0x465);
    ask:
        win = CreateTextWindow(0x50, 0x3C, 0xE, 2);
        LoadStringIntoWindow(win, (void*)0x49C, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        func_800F6B94_MinigameIslandFinish(win);
        choice = func_8006FCF0(win, 0, 1);
        HideTextWindow(win);
        if (choice != 0) {
            win = CreateTextWindow(0x50, 0x3C, 0xB, 1);
            msg = 0x49E;
            goto last;
        }
        win = CreateTextWindow(0x5A, 0x3C, 0xB, 3);
        LoadStringIntoWindow(win, (void*)0x49D, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        PlaySound(0x468);
        func_8004DBD4(win, 0);
        HideTextWindow(win);
        D_800F9010_MinigameIslandFinish = 1;
    }
end:
    D_800F5144 = 1;
    while (1) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_77_MinigameIslandFinish/2FADB0", func_800F6D68_MinigameIslandFinish);
/* the C's local balloon offset template; an explicit section, as GCC loses track of it after INCLUDE_ASM */
const Vec3f D_800F915C_MinigameIslandFinish __attribute__((section(".rodata"))) = { 0.0f, 80.0f, 0.0f };
#endif

void func_800F8BF4_MinigameIslandFinish(void) {
    if (func_80072718() == 0) {
        func_800F8FE8_MinigameIslandFinish();
        func_800F8F04_MinigameIslandFinish();
        func_80070ED4();
        func_800532F4();
        if (D_800F9010_MinigameIslandFinish != 0) {
            SetBoardFeatureFlag(0x2D);
            func_80059348(0x25);
            omOvlCallEx(0x6F, 0, 0x94);
            omOvlHisChg(1, 0x77, 1, 0x92);
            return;
        }
        ClearBoardFeatureFlag(0x2D);
        omOvlReturnEx(1);
    }
}

void func_800F8C94_MinigameIslandFinish(omObjData* obj) {
    if (D_800F5144 != 0) {
        func_800726AC(2, 0x10);
        func_800601D4(0x20);
        obj->func_ptr = &func_800F8BF4_MinigameIslandFinish;
    }
}

void func_800F8CE0_MinigameIslandFinish(void) {
    MBModelInit();
    HOST = MBModelCreate(0x83, D_800F9098_MinigameIslandFinish);
    PLAYER = MBModelCreate(func_80052F04(0), D_800F9108_MinigameIslandFinish[GwPlayer[0].character]);
    func_80021B14(*PLAYER->unk_3C->unk_40, GwPlayer[0].character, 0x80);
    BOAT = MBModelCreate(7, D_800F908C_MinigameIslandFinish);
    D_800F917C_MinigameIslandFinish = MBModelCreate(0x12, NULL);
    func_800A0D00(&D_800F917C_MinigameIslandFinish->coords, D_800F9044_MinigameIslandFinish.x,
                  D_800F9044_MinigameIslandFinish.y, D_800F9044_MinigameIslandFinish.z);
    if (D_800C597A == 0 && func_8005CE48(6) == 0) {
        func_800A0D00(&BOAT->coords, D_800F9044_MinigameIslandFinish.x, D_800F9044_MinigameIslandFinish.y,
                      D_800F9044_MinigameIslandFinish.z);
        func_800A0D00(&HOST->coords, D_800F9014_MinigameIslandFinish.x, D_800F9014_MinigameIslandFinish.y,
                      D_800F9014_MinigameIslandFinish.z);
        func_800A0D00(&PLAYER->coords, D_800F902C_MinigameIslandFinish.x, D_800F902C_MinigameIslandFinish.y,
                      D_800F902C_MinigameIslandFinish.z);
        return;
    }
    func_800A0D00(&BOAT->coords, D_800F905C_MinigameIslandFinish[1].x, D_800F905C_MinigameIslandFinish[1].y,
                  D_800F905C_MinigameIslandFinish[1].z);
    func_800A0D00(&HOST->coords, D_800F9020_MinigameIslandFinish.x, D_800F9020_MinigameIslandFinish.y,
                  D_800F9020_MinigameIslandFinish.z);
    func_800A0D00(&PLAYER->coords, D_800F9038_MinigameIslandFinish.x, D_800F9038_MinigameIslandFinish.y,
                  D_800F9038_MinigameIslandFinish.z);
    func_8004CCD0(&HOST->coords, &BOAT->coords, &HOST->unk_18);
    func_8004CCD0(&BOAT->coords, &PLAYER->coords, &BOAT->unk_18);
    func_8004CCD0(&PLAYER->coords, &BOAT->coords, &PLAYER->unk_18);
}

void func_800F8F04_MinigameIslandFinish(void) {
    MBModelKill(HOST);
    MBModelKill(PLAYER);
    MBModelKill(BOAT);
    MBModelKill(D_800F917C_MinigameIslandFinish);
}

void func_800F8F48_MinigameIslandFinish(void) {
    func_800178A0(1);
    func_80017660(0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    LoadBackgroundData(FE2310_ROM_START);
    LoadBackgroundIndex(0x59);
}

void func_800F8FE8_MinigameIslandFinish(void) {
    func_8004A140();
    func_80049F0C();
}
