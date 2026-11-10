#include "common.h"

/* Mini-Game Stadium results: the players' coins decide the ranking, ties are broken with a dice
   block, a sweeping star points out the winner, then the players line up under YOU ARE A WINNER
   (a near-copy of ovl_43's ceremony). */

void func_8001249C(s16, u8);
void func_80052DC8(s16, void*);
void func_8004FFA8(void);
void func_8003FC94(void);
void func_80040780(s32);
void func_8003FD68(s32);
void func_8004157C(void);
s32 func_800415E8(s32);
void func_800427E4(void);
extern char* D_800C5218[]; /* character names */
/* Retail called it unprototyped: the result is used as a word, not narrowed to s16. */
#define GMesFontMesCreate_unproto(a, b, c, d, e) ((s32 (*)())GMesFontMesCreate)(a, b, c, d, e)

void func_800F666C_MinigameStadiumResults(void);
void func_800F6720_MinigameStadiumResults(void);
void func_800F6740_MinigameStadiumResults(omObjData* obj);
void func_800F67DC_MinigameStadiumResults(omObjData* obj);
void func_800F6F30_MinigameStadiumResults(omObjData* obj);
void func_800F70A0_MinigameStadiumResults(void);
void func_800F8050_MinigameStadiumResults(omObjData* obj);
void func_800F80A4_MinigameStadiumResults(omObjData* obj);
void func_800F80E8_MinigameStadiumResults(void);
void func_800F82F8_MinigameStadiumResults(void);
void func_800F83F8_MinigameStadiumResults(void);
void func_800F8498_MinigameStadiumResults(void);

/* .rodata (ahead of everything: the .data pointer below refers to it) */
const char D_800F8650_MinigameStadiumResults[] = "YOU ARE A WINNER";
const char D_800F8664_MinigameStadiumResults[] = ""; /* unreferenced */

/* .data */
omObjData* D_800F84C0_MinigameStadiumResults = NULL; /* the spotlight's process */
omObjData* D_800F84C4_MinigameStadiumResults = NULL; /* the sweeping star */
void* D_800F84C8_MinigameStadiumResults = NULL;
/* the effect's model id (-1: none); retail reads its low half (big-endian +2) as s16 */
s32 D_800F84CC_MinigameStadiumResults = -1;
omObjData* D_800F84D0_MinigameStadiumResults = NULL;
/* each player's position (splat: D_800F84D4, D_800F84D8, D_800F84DC) */
Vec3f D_800F84D4_MinigameStadiumResults[4] = {
    { -190.0f, 0.0f, 2120.0f }, { -15.0f, 0.0f, 2120.0f }, { 160.0f, 0.0f, 2120.0f }, { 335.0f, 0.0f, 2120.0f },
};
/* the podium: the winner's spot, then the others' */
Vec3f D_800F8504_MinigameStadiumResults[4] = {
    { 0.0f, 25.0f, 2500.0f }, { -200.0f, 0.0f, 2200.0f }, { 175.0f, 0.0f, 2200.0f }, { 325.0f, 0.0f, 2200.0f },
};
Vec3f D_800F8534_MinigameStadiumResults = { 0.0f, 600.0f, 2250.0f };
Vec3f D_800F8540_MinigameStadiumResults = { 0.0f, 300.0f, 2250.0f };
Vec3f D_800F854C_MinigameStadiumResults = { -345.0f, 0.0f, 2040.0f };
/* per character: the board model's file list (a count, then file ids) */
s32 D_800F8558_MinigameStadiumResults[9] = { 8, 0x1003A, 0x10010, 0xA008B, 0x10000, 0x1003F, 0x10001, 0x10097, 0x1000F };
s32 D_800F857C_MinigameStadiumResults[9] = { 8, 0x2003A, 0x20010, 0xA008C, 0x20000, 0x2003F, 0x20001, 0x20097, 0x2000F };
s32 D_800F85A0_MinigameStadiumResults[9] = { 8, 0x6003A, 0x60010, 0xA008D, 0x60000, 0x6003F, 0x60001, 0x60097, 0x6000F };
s32 D_800F85C4_MinigameStadiumResults[9] = { 8, 0x3003A, 0x30010, 0xA008E, 0x30000, 0x3003F, 0x30001, 0x30097, 0x3000F };
s32 D_800F85E8_MinigameStadiumResults[9] = { 8, 0x4003A, 0x40010, 0xA008F, 0x40000, 0x4003F, 0x40001, 0x40097, 0x4000F };
s32 D_800F860C_MinigameStadiumResults[9] = { 8, 0x5003A, 0x50010, 0xA0090, 0x50000, 0x5003F, 0x50001, 0x50097, 0x5000F };
void* D_800F8630_MinigameStadiumResults[6] = {
    D_800F8558_MinigameStadiumResults, D_800F857C_MinigameStadiumResults, D_800F85A0_MinigameStadiumResults,
    D_800F85C4_MinigameStadiumResults, D_800F85E8_MinigameStadiumResults, D_800F860C_MinigameStadiumResults,
};
char* D_800F8648_MinigameStadiumResults = (char*)D_800F8650_MinigameStadiumResults;
s16 D_800F864C_MinigameStadiumResults[2] = { 160, 45 }; /* its position */

/* .bss */
extern Object* D_800F86E0_MinigameStadiumResults;
extern Object* D_800F86E4_MinigameStadiumResults; /* the star */
extern Object* D_800F86E8_MinigameStadiumResults; /* the spotlight */
extern s16 D_800F86EC_MinigameStadiumResults;
extern s16 D_800F86EE_MinigameStadiumResults;
extern unkCommonStruct0 D_800F86F0_MinigameStadiumResults; /* the "YOU ARE A WINNER" text (splat: D_800F8704 = unk_14) */

#define DEG 0.017453292519943295

#define SHOW_MESSAGE(win, msg)                              \
    LoadStringIntoWindow((s16)(win), (void*)(msg), -1, -1); \
    func_8006E070((s16)(win), 0);                           \
    ShowTextWindow((s16)(win));                             \
    PlaySound(0x432);                                       \
    WaitForTextConfirmation((s16)(win));                    \
    HideTextWindow((s16)(win))

void func_800F65E0_MinigameStadiumResults(void) {
    omInitObjMan(0x50, 0x50);
    func_800F83F8_MinigameStadiumResults();
    func_800F80E8_MinigameStadiumResults();
    func_8006CEA0();
    omAddPrcObj(func_800F70A0_MinigameStadiumResults, 0x300, 0x4000, 0);
    omAddObj(0x1000, 0, 0, -1, &func_800F80A4_MinigameStadiumResults);
    func_80072724(0xFF, 0xFF, 0xFF);
    SetFadeInTypeAndTime(2, 0x10);
}

/* "YOU ARE A WINNER", in the font */
void func_800F666C_MinigameStadiumResults(void) {
    s32 mes;
    s32 i;

    mes = (s16)GMesFontMesCreate_unproto(&D_800F86F0_MinigameStadiumResults, D_800F8648_MinigameStadiumResults, 0, -1, -1);
    func_80066DC4(D_800F86F0_MinigameStadiumResults.unk_14[mes], 0, D_800F864C_MinigameStadiumResults[0],
                  D_800F864C_MinigameStadiumResults[1]);
    for (i = 1; i < 17; i++) {
        func_80067354(D_800F86F0_MinigameStadiumResults.unk_14[mes], i, 1.0f, 2.0f);
    }
}

void func_800F6720_MinigameStadiumResults(void) {
    func_80077044(&D_800F86F0_MinigameStadiumResults);
}

void func_800F6740_MinigameStadiumResults(omObjData* obj) {
    obj->scale.x += 0.4f;
    obj->scale.y += 0.4f;
    obj->scale.z += 0.4f;
    if (obj->scale.x >= 5.0f) {
        func_8002456C((s16)D_800F84CC_MinigameStadiumResults);
        D_800F84CC_MinigameStadiumResults = -1;
        D_800F84D0_MinigameStadiumResults = NULL;
        omDelObj(obj);
    }
}

/* The sweeping star: work[0] state (0 sweep, 1 sweep until over player work[1], 4 hover over
   them, 2 move for work[2] frames, 5 hover at its trans), work[2] set once it stops, work[3]
   frames. */
void func_800F67DC_MinigameStadiumResults(omObjData* obj) {
    f32 x;
    f32 y;

    switch (obj->work[0]) {
    case 0:
    case 1:
        func_8001249C(D_800F86EE_MinigameStadiumResults, (s32)(sinf(obj->scale.x * DEG) * 32.0f) + 0x40);
        MBModelDispOn(D_800F86E4_MinigameStadiumResults);
        x = sinf(obj->scale.x * DEG) * 350.0f + obj->trans.x;
        func_800A0D00(&D_800F86E4_MinigameStadiumResults->coords, x,
                      sinf(2.0f * obj->scale.x * DEG) * 20.0f + obj->trans.y, obj->trans.z);
        D_800F86E4_MinigameStadiumResults->unk_18.x = 0.0f;
        D_800F86E4_MinigameStadiumResults->unk_18.z = 1.0f;
        if (obj->work[0] == 1
            && ((GwPlayer[obj->work[1]].player_obj->coords.x >= sinf(obj->scale.x * DEG) * 350.0f + obj->trans.x
                 && GwPlayer[obj->work[1]].player_obj->coords.x <= sinf((obj->scale.x + 5.0f) * DEG) * 350.0f + obj->trans.x)
                || (GwPlayer[obj->work[1]].player_obj->coords.x <= sinf(obj->scale.x * DEG) * 350.0f + obj->trans.x
                    && GwPlayer[obj->work[1]].player_obj->coords.x >= sinf((obj->scale.x + 5.0f) * DEG) * 350.0f + obj->trans.x))) {
            func_800A0D00(&D_800F86E4_MinigameStadiumResults->coords, GwPlayer[obj->work[1]].player_obj->coords.x,
                          sinf(2.0f * obj->scale.x * DEG) * 20.0f + obj->trans.y, obj->trans.z);
            obj->work[0] = 4;
            obj->work[2] = 1;
            obj->scale.y = 0.0f;
            obj->rot.y = 0.0f;
            D_800F84CC_MinigameStadiumResults = LoadFormFile(0xA0136, 0x2B9);
            func_80025798((s16)D_800F84CC_MinigameStadiumResults, GwPlayer[obj->work[1]].player_obj->coords.x,
                          sinf(2.0f * obj->scale.x * DEG) * 20.0f + obj->trans.y + 80.0f, obj->trans.z);
            func_80025830((s16)D_800F84CC_MinigameStadiumResults, 4.0f, 4.0f, 4.0f);
            D_800F84D0_MinigameStadiumResults = omAddObj(-0x8000, 1, 1, -1, &func_800F6740_MinigameStadiumResults);
            D_800F84D0_MinigameStadiumResults->model[0] = (s16)D_800F84CC_MinigameStadiumResults;
            D_800F84D0_MinigameStadiumResults->trans.x = GwPlayer[obj->work[1]].player_obj->coords.x;
            D_800F84D0_MinigameStadiumResults->trans.y = sinf(2.0f * obj->scale.x * DEG) * 20.0f + obj->trans.y + 80.0f;
            D_800F84D0_MinigameStadiumResults->trans.z = obj->trans.z;
            D_800F84D0_MinigameStadiumResults->rot.x = 90.0f;
            D_800F84D0_MinigameStadiumResults->rot.y = D_800F84D0_MinigameStadiumResults->rot.z = 0.0f;
            D_800F84D0_MinigameStadiumResults->scale.x = D_800F84D0_MinigameStadiumResults->scale.y =
                D_800F84D0_MinigameStadiumResults->scale.z = 1.0f;
            break;
        }
        if ((obj->scale.x += 5.0f) >= 360.0f) {
            obj->scale.x -= 360.0f;
        }
        obj->work[3]++;
        break;
    case 2:
        func_800A0D00(&D_800F86E4_MinigameStadiumResults->coords,
                      D_800F2B7C[*D_800F86E4_MinigameStadiumResults->unk_3C->unk_40].unk_24 + obj->trans.x,
                      D_800F2B7C[*D_800F86E4_MinigameStadiumResults->unk_3C->unk_40].unk_28 + obj->trans.y,
                      D_800F2B7C[*D_800F86E4_MinigameStadiumResults->unk_3C->unk_40].unk_2C + obj->trans.z);
        obj->work[3]++;
        obj->work[2]--;
        if (obj->work[2] == 0) {
            obj->trans.x = D_800F2B7C[*D_800F86E4_MinigameStadiumResults->unk_3C->unk_40].unk_24;
            obj->trans.y = D_800F2B7C[*D_800F86E4_MinigameStadiumResults->unk_3C->unk_40].unk_28;
            obj->trans.z = D_800F2B7C[*D_800F86E4_MinigameStadiumResults->unk_3C->unk_40].unk_2C;
            obj->rot.y = 0.0f;
            obj->work[0] = 5;
        }
        break;
    case 3:
        break;
    case 4:
        y = sinf(2.0f * obj->scale.x * DEG) * 20.0f + obj->trans.y;
        func_800A0D00(&D_800F86E4_MinigameStadiumResults->coords, GwPlayer[obj->work[1]].player_obj->coords.x,
                      y + sinf(obj->rot.y * DEG) * 8.0f, obj->trans.z);
        if ((obj->rot.y += 10.0f) >= 360.0f) {
            obj->rot.y -= 360.0f;
        }
        break;
    case 5:
        func_800A0D00(&D_800F86E4_MinigameStadiumResults->coords, obj->trans.x,
                      sinf(obj->rot.y * DEG) * 8.0f + obj->trans.y, obj->trans.z);
        if ((obj->rot.y += 10.0f) >= 360.0f) {
            obj->rot.y -= 360.0f;
        }
        break;
    }
}

/* The spotlight: waits work[0] frames, then bobs at its trans while it turns. */
void func_800F6F30_MinigameStadiumResults(omObjData* obj) {
    if (obj->work[0] != 0) {
        obj->work[0]--;
    } else {
        func_800A0D00(&D_800F86E8_MinigameStadiumResults->coords, obj->trans.x,
                      sinf(obj->rot.y * DEG) * 8.0f + obj->trans.y, obj->trans.z);
        if ((obj->rot.y += 5.0f) >= 360.0f) {
            obj->rot.y -= 360.0f;
        }
    }
    D_800F86E8_MinigameStadiumResults->unk_3C->unk_2C = -10.0f;
    D_800F86E8_MinigameStadiumResults->unk_18.x = sinf(obj->rot.x * DEG);
    D_800F86E8_MinigameStadiumResults->unk_18.z = cosf(obj->rot.x * DEG);
    if ((obj->rot.x += 2.0f) >= 360.0f) {
        obj->rot.x -= 360.0f;
    }
}

/* The ceremony. */
// register allocation: the 0x50D window lives in s1, retail s3 (masked 0)
#ifdef NON_MATCHING
void func_800F70A0_MinigameStadiumResults(void) {
    s32 timers[4]; /* also the sort's swap temporary */
    s32 order[4];
    s32 score[4]; /* coins, then how many players share each rank */
    s32 rank[4];
    u8 state[4];
    u8 count[4];
    s32 i;
    s32 j;
    s32 k;
    s16 win;
    s32 win2;

    HuPrcSleep(16);
    func_80060128(16);
    HuPrcSleep(10);
    win = CreateTextWindow(30, 42, 13, 3);
    SHOW_MESSAGE(win, 0x508);
    for (j = 0; j < 4; j++) {
        score[j] = GwPlayer[j].coins;
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
        win2 = CreateTextWindow(30, 42, 17, 4);
        for (j = 0, k = 0; j < 4; j++) {
            if (rank[j] == i) {
                func_8006DA5C(win2, D_800C5218[GwPlayer[j].character], k++);
            }
        }
        if (k == 4) {
            LoadStringIntoWindow(win2, (void*)0x50C, -1, -1);
        } else if (k == 3) {
            func_8006DA5C(win2, "\xA4", 3);
            LoadStringIntoWindow(win2, (void*)0x50B, -1, -1);
        } else {
            func_8006DA5C(win2, "", 2);
            func_8006DA5C(win2, "", 3);
            LoadStringIntoWindow(win2, (void*)0x50A, -1, -1);
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
            win = CreateTextWindow(30, 60, 15, 1);
            func_8006DA5C(win, D_800C5218[GwPlayer[order[0]].character], 0);
            rank[order[1]] = i + 1;
            if (score[i] == 4) {
                rank[order[2]] = i + 2;
                rank[order[3]] = i + 3;
            }
            SHOW_MESSAGE(win, 0x50D);
        } else {
            win2 = CreateTextWindow(30, 60, 16, 2);
            for (j = 0; j < 3; j++) {
                func_8006DA5C(win2, D_800C5218[GwPlayer[order[j]].character], j);
                rank[order[j]] = i + j;
            }
            SHOW_MESSAGE(win2, 0x50E);
        }
        func_80041370();
    }

    /* the winner */
    func_800601D4(130);
    HuPrcSleep(55);
    D_800F86EC_MinigameStadiumResults = PlaySound(0x479);
    D_800F86EE_MinigameStadiumResults = PlaySound(0x62);
    D_800F84C4_MinigameStadiumResults = omAddObj(0x1000, 0, 0, -1, &func_800F67DC_MinigameStadiumResults);
    D_800F84C4_MinigameStadiumResults->mdlcnt = 0;
    D_800F84C4_MinigameStadiumResults->scale.x = 0.0f;
    D_800F84C4_MinigameStadiumResults->trans.x = 0.0f;
    D_800F84C4_MinigameStadiumResults->trans.y = GwPlayer[0].player_obj->coords.y + 200.0f;
    D_800F84C4_MinigameStadiumResults->trans.z = GwPlayer[0].player_obj->coords.z - 100.0f;
    D_800F84C4_MinigameStadiumResults->work[0] = 0;
    D_800F84C4_MinigameStadiumResults->work[3] = 0;
    HuPrcSleep(60);
    win = CreateTextWindow(30, 30, 13, 2);
    SHOW_MESSAGE(win, 0x50F);
    for (j = 0; j < 4; j++) {
        if (rank[j] == 0) {
            break;
        }
    }
    D_800F84C4_MinigameStadiumResults->work[0] = 1;
    D_800F84C4_MinigameStadiumResults->work[1] = j;
    D_800F84C4_MinigameStadiumResults->work[2] = 0;
    while (1) {
        if (D_800F84C4_MinigameStadiumResults->work[2] != 0) {
            break;
        }
        HuPrcVSleep();
    }
    func_8006071C(D_800F86EC_MinigameStadiumResults);
    func_8006071C(D_800F86EE_MinigameStadiumResults);
    PlaySound(0x64);
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
    SHOW_MESSAGE(win, 0x510);
    D_800F84C4_MinigameStadiumResults->work[0] = 2;
    D_800F84C4_MinigameStadiumResults->work[2] = 60;
    D_800F84C4_MinigameStadiumResults->trans.x = 0.0f;
    D_800F84C4_MinigameStadiumResults->trans.y = 10.0f;
    D_800F84C4_MinigameStadiumResults->trans.z = 0.0f;
    HuPrcSleep(60);
    omDelObj(D_800F84C4_MinigameStadiumResults);
    for (i = 0; i < 4; i++) {
        GwCommon.boardWork[rank[i]] = i;
        GwCommon.boardWork[10 + i] = 0;
    }
    win = CreateTextWindow(30, 42, 12, 2);
    func_8006DA5C(win, D_800C5218[GwPlayer[j].character], 0);
    SHOW_MESSAGE(win, 0x511);

    /* the podium: the spotlight on the winner, the others line up behind */
    MBModelDispOn(D_800F86E8_MinigameStadiumResults);
    D_800F84C8_MinigameStadiumResults = func_80042728(D_800F86E8_MinigameStadiumResults, 1);
    func_8004E3E0(0, &D_800F8540_MinigameStadiumResults, 120, D_800F86E8_MinigameStadiumResults);
    D_800F84C0_MinigameStadiumResults = omAddObj(0x1000, 0, 0, -1, &func_800F6F30_MinigameStadiumResults);
    D_800F84C0_MinigameStadiumResults->trans.x = D_800F8540_MinigameStadiumResults.x;
    D_800F84C0_MinigameStadiumResults->trans.y = D_800F8540_MinigameStadiumResults.y;
    D_800F84C0_MinigameStadiumResults->trans.z = D_800F8540_MinigameStadiumResults.z;
    D_800F84C0_MinigameStadiumResults->rot.y = 0.0f;
    D_800F84C0_MinigameStadiumResults->rot.x = 0.0f;
    D_800F84C0_MinigameStadiumResults->work[0] = 120;
    HuPrcSleep(90);
    func_8004EE14(GwCommon.boardWork[0], &D_800F8504_MinigameStadiumResults[0], 1, NULL);
    func_8004E3E0(GwCommon.boardWork[0], &D_800F8504_MinigameStadiumResults[0], 30, NULL);
    func_8004F4D4(GwPlayer[GwCommon.boardWork[0]].player_obj, 5, 2);
    HuPrcSleep(30);
    func_8004EE14(GwCommon.boardWork[0], D_800F32A0, 1, NULL);
    func_8004F4D4(GwPlayer[GwCommon.boardWork[0]].player_obj, 3, 2);
    HuPrcSleep(20);
    for (i = 0, j = 1; i < 4; i++) {
        if (i != GwCommon.boardWork[0]) {
            func_8004EE14(i, &D_800F8504_MinigameStadiumResults[j], 5, NULL);
            func_8004E3E0(i, &D_800F8504_MinigameStadiumResults[j++], 20, NULL);
            func_8004F4D4(GwPlayer[i].player_obj, 5, 2);
        }
    }
    HuPrcSleep(20);
    for (i = 0; i < 4; i++) {
        if (i != GwCommon.boardWork[0]) {
            func_8004F4D4(GwPlayer[i].player_obj, 3, 2);
            func_8004EE14(i, &GwPlayer[GwCommon.boardWork[0]].player_obj->coords, 10, NULL);
        }
    }
    /* retail passes player 0 here whoever won */
    func_8004EE14(0, &GwPlayer[GwCommon.boardWork[0]].player_obj->coords, 10, D_800F86E0_MinigameStadiumResults);
    func_8004EE14(GwCommon.boardWork[0], D_800F32A0, 20, NULL);
    HuPrcSleep(30);
    func_8004F4D4(GwPlayer[GwCommon.boardWork[0]].player_obj, 6, 0);
    {
        s32 delay[6] = { 45, 25, 30, 45, 45, 30 }; /* per character */

        HuPrcSleep(delay[GwPlayer[GwCommon.boardWork[0]].character]);
    }
    func_80060468(0x458, GwPlayer[GwCommon.boardWork[0]].character);
    func_8004F504(GwPlayer[GwCommon.boardWork[0]].player_obj);
    func_800F666C_MinigameStadiumResults();
    func_8004FFA8();
    D_800F5144 = 1;
    HuPrcSleep(15);
    if (D_800F84C8_MinigameStadiumResults != NULL) {
        func_800427D4(D_800F84C8_MinigameStadiumResults);
        func_800427E4();
        D_800F84C8_MinigameStadiumResults = NULL;
    }
    while (1) {
        HuPrcVSleep();
    }
}

#else
/* the function's string literals and local array template, which the asm references by name */
const char D_800F86B8_MinigameStadiumResults[] __attribute__((section(".rodata"))) = "\xA4";
const char D_800F86BC_MinigameStadiumResults[] __attribute__((section(".rodata"))) = "";
const s32 D_800F86C0_MinigameStadiumResults[6] __attribute__((section(".rodata"))) = { 45, 25, 30, 45, 45, 30 };
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_MinigameStadiumResults/312850", func_800F70A0_MinigameStadiumResults);
#endif

void func_800F8050_MinigameStadiumResults(omObjData* obj) {
    if (func_80072718() == 0) {
        func_800F8498_MinigameStadiumResults();
        func_800F82F8_MinigameStadiumResults();
        func_800F6720_MinigameStadiumResults();
        func_80070ED4();
        omOvlGotoEx(0x40, 0, 0x1094);
    }
}

void func_800F80A4_MinigameStadiumResults(omObjData* obj) {
    if (D_800F5144 != 0) {
        func_800726AC(0, 0x14);
        obj->func_ptr = &func_800F8050_MinigameStadiumResults;
    }
}

void func_800F80E8_MinigameStadiumResults(void) {
    s32 i;

    MBModelInit();
    func_80053020();
    func_8004F2AC();
    for (i = 0; i < 4; i++) {
        func_80052DC8(i, D_800F8630_MinigameStadiumResults[GwPlayer[i].character]);
        func_80021B14(*GwPlayer[i].player_obj->unk_3C->unk_40, GwPlayer[i].character, 0);
        GwPlayer[i].player_obj->coords.x = D_800F84D4_MinigameStadiumResults[i].x;
        GwPlayer[i].player_obj->coords.y = D_800F84D4_MinigameStadiumResults[i].y;
        GwPlayer[i].player_obj->coords.z = D_800F84D4_MinigameStadiumResults[i].z;
        GwPlayer[i].flags |= 2;
        func_8004CCD0(&GwPlayer[i].player_obj->coords, &D_800F32A0->coords, &GwPlayer[i].player_obj->unk_18);
    }
    D_800F86E0_MinigameStadiumResults = MBModelCreate(0x83, NULL);
    D_800F86E0_MinigameStadiumResults->coords.x = D_800F854C_MinigameStadiumResults.x;
    D_800F86E0_MinigameStadiumResults->coords.y = D_800F854C_MinigameStadiumResults.y;
    D_800F86E0_MinigameStadiumResults->coords.z = D_800F854C_MinigameStadiumResults.z;
    func_8004CCD0(&D_800F86E0_MinigameStadiumResults->coords, &D_800F32A0->coords, &D_800F86E0_MinigameStadiumResults->unk_18);
    D_800F86E4_MinigameStadiumResults = MBModelCreate(0x88, NULL);
    MBModelDispOff(D_800F86E4_MinigameStadiumResults);
    func_800A0D00(&D_800F86E4_MinigameStadiumResults->coords, D_800F8534_MinigameStadiumResults.x,
                  D_800F8534_MinigameStadiumResults.y, D_800F8534_MinigameStadiumResults.z);
    D_800F86E8_MinigameStadiumResults = MBModelCreate(0x8B, NULL);
    MBModelDispOff(D_800F86E8_MinigameStadiumResults);
    func_800A0D00(&D_800F86E8_MinigameStadiumResults->coords, D_800F8534_MinigameStadiumResults.x,
                  D_800F8534_MinigameStadiumResults.y, D_800F8534_MinigameStadiumResults.z);
}

void func_800F82F8_MinigameStadiumResults(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_80052FD4(i);
    }
    MBModelKill(D_800F86E0_MinigameStadiumResults);
    MBModelKill(D_800F86E8_MinigameStadiumResults);
    if (D_800F84C0_MinigameStadiumResults != NULL) {
        omDelObj(D_800F84C0_MinigameStadiumResults);
    }
    MBModelKill(D_800F86E4_MinigameStadiumResults);
    if (D_800F84C8_MinigameStadiumResults != NULL) {
        func_800427D4(D_800F84C8_MinigameStadiumResults);
        func_800427E4();
    }
    if (D_800F84C4_MinigameStadiumResults != NULL) {
        omDelObj(D_800F84C4_MinigameStadiumResults);
    }
    if (D_800F84CC_MinigameStadiumResults != -1) {
        func_8002456C((s16)D_800F84CC_MinigameStadiumResults);
        D_800F84CC_MinigameStadiumResults = -1;
    }
    if (D_800F84D0_MinigameStadiumResults != NULL) {
        omDelObj(D_800F84D0_MinigameStadiumResults);
        D_800F84D0_MinigameStadiumResults = NULL;
    }
    func_8004F2EC();
}

void func_800F83F8_MinigameStadiumResults(void) {
    func_800178A0(1);
    func_80017660(0, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    LoadBackgroundData(D_FE2310);
    LoadBackgroundIndex(0x64);
}

void func_800F8498_MinigameStadiumResults(void) {
    func_8004A140();
    func_80049F0C();
}
