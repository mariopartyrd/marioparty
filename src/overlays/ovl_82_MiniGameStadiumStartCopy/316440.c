#include "PR/os.h"
#include "316440.h"
#include "engine/process.h"

/* Retail passes the window id unextended here (it was called without the s16 prototype). */
#define WAIT_TEXT(w) ((void (*)())WaitForTextConfirmation)(w)

void func_80052DC8(s16, void*);
void func_8003FC94(void);
void func_80040780(s32);
void func_8003FD68(s32);
void func_8004157C(void);
s32 func_800415E8(s32);
void func_80040590(s32);
void HidePlayerHUDVisibility(s32, s32);
void func_80055810(s32, s32, s32);
extern char* D_800C5218[]; /* character names */

void func_800F6650_MiniGameStadiumStartCopy(s32 arg0, s32 arg1);
void func_800F66D8_MiniGameStadiumStartCopy(void);
void func_800F676C_MiniGameStadiumStartCopy(void);
void func_800F6880_MiniGameStadiumStartCopy(omObjData* obj);
void func_800F6A20_MiniGameStadiumStartCopy(void);
void func_800F6DA0_MiniGameStadiumStartCopy(void);
void func_800F6EF0_MiniGameStadiumStartCopy(void);
void func_800F7738_MiniGameStadiumStartCopy(omObjData* obj);
void func_800F780C_MiniGameStadiumStartCopy(void);
void func_800F7918_MiniGameStadiumStartCopy(void);

Object* D_800F7940_MiniGameStadiumStartCopy = NULL;
s32 D_800F7944_MiniGameStadiumStartCopy = 0;
s32 D_800F7948_MiniGameStadiumStartCopy = 0;
Vec3f D_800F794C_MiniGameStadiumStartCopy = { 0.0f, 0.0f, 2040.0f };
/* landing spots, one per player */
Vec3f D_800F7958_MiniGameStadiumStartCopy[4] = {
    { -105.0f, 0.0f, 2360.0f },
    { 10.0f, 0.0f, 1725.0f },
    { 205.0f, 0.0f, 1875.0f },
    { 315.0f, 0.0f, 2300.0f },
};
Vec3f D_800F7988_MiniGameStadiumStartCopy[4] = {
    { -130.0f, 0.0f, 2175.0f },
    { -35.0f, 0.0f, 1930.0f },
    { 125.0f, 0.0f, 2045.0f },
    { 220.0f, 0.0f, 2230.0f },
};
Vec3f D_800F79B8_MiniGameStadiumStartCopy[4] = {
    { -190.0f, 0.0f, 2120.0f },
    { -15.0f, 0.0f, 2120.0f },
    { 160.0f, 0.0f, 2120.0f },
    { 335.0f, 0.0f, 2120.0f },
};
Vec3f D_800F79E8_MiniGameStadiumStartCopy = { -590.0f, 0.0f, 2040.0f };
Vec3f D_800F79F4_MiniGameStadiumStartCopy = { -345.0f, 0.0f, 2040.0f };
/* MBModelCreate motion lists: a count, then file ids (one per character) */
s32 D_800F7A00_MiniGameStadiumStartCopy[9] = { 8, 0x1001E, 0x1001C, 0x10000, 0x10001, 0x10003, 0xA008B, 0x1003B, 0x10039 };
s32 D_800F7A24_MiniGameStadiumStartCopy[9] = { 8, 0x2001E, 0x2001C, 0x20000, 0x20001, 0x20003, 0xA008C, 0x2003B, 0x20039 };
s32 D_800F7A48_MiniGameStadiumStartCopy[9] = { 8, 0x6001E, 0x6001C, 0x60000, 0x60001, 0x60003, 0xA008D, 0x6003B, 0x60039 };
s32 D_800F7A6C_MiniGameStadiumStartCopy[9] = { 8, 0x3001E, 0x3001C, 0x30000, 0x30001, 0x30003, 0xA008E, 0x3003B, 0x30039 };
s32 D_800F7A90_MiniGameStadiumStartCopy[9] = { 8, 0x4001E, 0x4001C, 0x40000, 0x40001, 0x40003, 0xA008F, 0x4003B, 0x40039 };
s32 D_800F7AB4_MiniGameStadiumStartCopy[9] = { 8, 0x5001E, 0x5001C, 0x50000, 0x50001, 0x50003, 0xA0090, 0x5003B, 0x50039 };
s32* D_800F7AD8_MiniGameStadiumStartCopy[6] = {
    D_800F7A00_MiniGameStadiumStartCopy, D_800F7A24_MiniGameStadiumStartCopy, D_800F7A48_MiniGameStadiumStartCopy,
    D_800F7A6C_MiniGameStadiumStartCopy, D_800F7A90_MiniGameStadiumStartCopy, D_800F7AB4_MiniGameStadiumStartCopy,
};
s32 D_800F7AF0_MiniGameStadiumStartCopy[4] = { 3, 0xA0072, 0xA0073, 0xA0074 };

void func_800F65E0_MiniGameStadiumStartCopy(void) {
    omInitObjMan(50, 10);
    func_800F7880_MiniGameStadiumStartCopy();
    func_800F77E0_MiniGameStadiumStartCopy();
    func_8006CEA0();
    omAddPrcObj(&func_800F76E0_MiniGameStadiumStartCopy, 0x300, 0x2000, 0);
    omAddObj(0x1000, 0, 0, -1, &func_800F7794_MiniGameStadiumStartCopy);
}

void func_800F6650_MiniGameStadiumStartCopy(s32 arg0, s32 arg1) {
    GW_PLAYER* temp_s0;
    GW_PLAYER* temp_s1;
    void* temp_s2;

    temp_s1 = GetPlayerStruct(arg0);
    temp_s2 = GetPlayerStruct(arg1);
    temp_s0 = HuMemDirectMalloc(sizeof(GW_PLAYER));
    bcopy(temp_s1, temp_s0, sizeof(GW_PLAYER));
    bcopy(temp_s2, temp_s1, sizeof(GW_PLAYER));
    bcopy(temp_s0, temp_s2, sizeof(GW_PLAYER));
    HuMemDirectFree(temp_s0);
}

void func_800F66D8_MiniGameStadiumStartCopy(void) {
    s32 i;
    s32 j;

    for (i = 3; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (GwPlayer[j].player_index > GwPlayer[j + 1].player_index) {
                func_800F6650_MiniGameStadiumStartCopy(j, j + 1);
            }
        }
    }
}

void func_800F676C_MiniGameStadiumStartCopy(void) {
    s32 i;

    D_800F7940_MiniGameStadiumStartCopy = MBModelCreate(0x83, D_800F7AF0_MiniGameStadiumStartCopy);
    func_800A0D00(&D_800F7940_MiniGameStadiumStartCopy->coords, D_800F79E8_MiniGameStadiumStartCopy.x,
                  D_800F79E8_MiniGameStadiumStartCopy.y, D_800F79E8_MiniGameStadiumStartCopy.z);
    func_8004CCD0(&D_800F7940_MiniGameStadiumStartCopy->coords, &GwPlayer[0].player_obj->coords,
                  &D_800F7940_MiniGameStadiumStartCopy->unk_18);
    MBMotionSet(D_800F7940_MiniGameStadiumStartCopy, 2, 2);
    func_8004E3E0(0, &D_800F79F4_MiniGameStadiumStartCopy, 10, D_800F7940_MiniGameStadiumStartCopy);
    HuPrcSleep(10);
    func_8004F4D4(D_800F7940_MiniGameStadiumStartCopy, 0, 2);
    for (i = 0; i < 4; i++) {
        func_8004EE14(i, &D_800F79F4_MiniGameStadiumStartCopy, 10, NULL);
        func_8004F4D4(GwPlayer[i].player_obj, 3, 2);
    }
    HuPrcSleep(10);
}

void func_800F6880_MiniGameStadiumStartCopy(omObjData* obj) {
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
        GwPlayer[obj->work[0]].player_obj->coords.x = D_800F7958_MiniGameStadiumStartCopy[obj->work[0]].x;
        GwPlayer[obj->work[0]].player_obj->coords.z = D_800F7958_MiniGameStadiumStartCopy[obj->work[0]].z;
    }
    if (obj->trans.y < D_800F7958_MiniGameStadiumStartCopy[obj->work[0]].y) {
        GwPlayer[obj->work[0]].player_obj->unk_30 = D_800F7958_MiniGameStadiumStartCopy[obj->work[0]].y;
        omDelObj(obj);
    }
}

void func_800F6A20_MiniGameStadiumStartCopy(void) {
    Object* obj;
    omObjData* o;
    s32 i;

    LoadBackgroundIndex(0x64);
    obj = MBModelCreate(0x87, NULL);
    func_800A0D00(&obj->coords, D_800F794C_MiniGameStadiumStartCopy.x, D_800F794C_MiniGameStadiumStartCopy.y,
                  D_800F794C_MiniGameStadiumStartCopy.z + 50.0f);
    func_800A0D00((Vec3f*)&obj->xScale, 0.0f, 0.0f, 0.0f);
    SetFadeInTypeAndTime(2, 0x10);
    HuPrcSleep(0x10);
    PlaySound(0x40);
    for (i = 0; i < 90; i += 10) {
        obj->xScale = obj->zScale = 1.2f;
        obj->yScale = sinf(i * (M_PI / 180)) * 1.2f;
        HuPrcVSleep();
    }
    for (i = 0; i < 4; i++) {
        func_80052DC8(i, D_800F7AD8_MiniGameStadiumStartCopy[GwPlayer[i].character]);
        func_80021B14(*GwPlayer[i].player_obj->unk_3C->unk_40, GwPlayer[i].character, 0);
        func_800A0D00(&GwPlayer[i].player_obj->coords, D_800F794C_MiniGameStadiumStartCopy.x,
                      D_800F794C_MiniGameStadiumStartCopy.y, D_800F794C_MiniGameStadiumStartCopy.z);
        GwPlayer[i].flags |= 2;
        func_8004CCD0(&GwPlayer[i].player_obj->coords, &D_800F32A0->coords, &GwPlayer[i].player_obj->unk_18);
        MBMotionSet(GwPlayer[i].player_obj, 0, 0);
        MBModelDispOff(GwPlayer[i].player_obj);
        func_80025EB4(*GwPlayer[i].player_obj->unk_3C->unk_40, 2, 1);
    }
    for (i = 0; i < 4; i++) {
        o = omAddObj(0x1000, 0, 0, -1, &func_800F6880_MiniGameStadiumStartCopy);
        o->work[0] = i;
        o->work[1] = 0;
        o->trans.y = D_800F794C_MiniGameStadiumStartCopy.y;
        o->scale.y = 80.0f;
        MBModelDispOn(GwPlayer[i].player_obj);
        PlaySound(0x42);
        HuPrcSleep(5);
    }
    PlaySound(0x41);
    for (i = 90; i >= 0; i -= 10) {
        obj->yScale = sinf(i * (M_PI / 180)) * 1.2f;
        HuPrcVSleep();
    }
    MBModelKill(obj);
    HuPrcSleep(0x14);
    for (i = 0; i < 4; i++) {
        func_800503B0(i, 1);
        HuPrcSleep(5);
    }
    for (i = 0; i < 4; i++) {
        func_8004F4D4(GwPlayer[i].player_obj, 2, 2);
    }
}

void func_800F6DA0_MiniGameStadiumStartCopy(void) {
    s32 i;
    s32 j;
    s32 win;

    for (i = 0; i < 4; i++) {
        func_8004E3E0(i, &D_800F7988_MiniGameStadiumStartCopy[i], 20, NULL);
    }
    for (j = 0; j < 20; j++) {
        for (i = 0; i < 4; i++) {
            func_8004CCD0(&GwPlayer[i].player_obj->coords, &D_800F7940_MiniGameStadiumStartCopy->coords,
                          &GwPlayer[i].player_obj->unk_18);
        }
        HuPrcVSleep();
    }
    for (i = 0; i < 4; i++) {
        func_8004F4D4(GwPlayer[i].player_obj, 2, 2);
    }
    win = CreateTextWindow(0x1E, 0x2A, 0x11, 3);
    LoadStringIntoWindow(win, (void*)0x500, -1, -1);
    func_8006E070(win, 0);
    ShowTextWindow(win);
    PlaySound(0x432);
    WAIT_TEXT(win);
    HideTextWindow(win);
}

void func_800F6EF0_MiniGameStadiumStartCopy(void) {
    s32 timer[4];
    u8 state[4];
    u8 count[4];
    u8 order[4];
    s32 delay[4] = { 20, 30, 25, 20 };
    s32 i;
    s32 j;
    s32 win;

    for (i = 0; i < 4; i++) {
        func_8004E3E0(i, &D_800F79B8_MiniGameStadiumStartCopy[i], delay[i], NULL);
        func_8004EE14(i, D_800F32A0, delay[i], NULL);
        func_8004F4D4(GwPlayer[i].player_obj, 3, 2);
    }
    for (i = 0; i < 31; i++) {
        for (j = 0; j < 4; j++) {
            if (delay[j] == i) {
                func_8004F4D4(GwPlayer[j].player_obj, 2, 2);
            }
        }
        HuPrcVSleep();
    }
    HuPrcSleep(10);
    D_800F7948_MiniGameStadiumStartCopy = 1;
    func_8003FCD4();
    func_8003FC94();
    for (i = 0; i < 4; i++) {
        func_80040780(i);
        func_8003FD68(i);
    }
    func_8004157C();
    HuPrcSleep(20);
    win = CreateTextWindow(0x46, 0x1E, 0x10, 2);
    LoadStringIntoWindow(win, (void*)0x501, -1, -1);
    func_8006E070(win, 0);
    ShowTextWindow(win);
    PlaySound(0x437);
    while (func_8006FCC0(win) != 0) {
        HuPrcVSleep();
    }
    for (i = 0; i < 4; i++) {
        state[i] = 1;
        count[i] = 0;
        timer[i] = (u8)(rand8() % 30) + 5;
    }
    while (1) {
        for (i = 0; i < 4; i++) {
            timer[i]--;
            if (state[i] == 1) {
                if (GwPlayer[i].flags & 1) {
                    if (timer[i] <= 0) {
                        goto press;
                    }
                    continue;
                }
                if (ContBtnTrg[GwPlayer[i].port] & 0x8000) {
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
                timer[0] = state[i];
                state[i] = state[j];
                state[j] = timer[0];
                timer[0] = order[i];
                order[i] = order[j];
                order[j] = timer[0];
            }
        }
    }
    for (i = 0; i < 4; i++) {
        GwPlayer[order[i]].player_index = i;
        func_80040590(i);
    }
    func_800F66D8_MiniGameStadiumStartCopy();
    func_800544E4();
    D_800F7944_MiniGameStadiumStartCopy = 1;
    for (i = 0; i < 4; i++) {
        HidePlayerHUDVisibility(i, 1);
    }
    HuPrcSleep(5);
    for (i = 0; i < 4; i++) {
        if (i == 0) {
            win = CreateTextWindow(0x1E, 0x46, 0xD, 2);
        } else {
            win = CreateTextWindow(0x1E, 0x46, 8, 1);
        }
        func_8006DA5C(win, D_800C5218[GwPlayer[i].character], i);
        LoadStringIntoWindow(win, (void*)(s32)(i + 0x502), -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        PlaySound(0x437);
        WAIT_TEXT(win);
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
    win = CreateTextWindow(0x1E, 0x46, 0x11, 2);
    LoadStringIntoWindow(win, (void*)0x506, -1, -1);
    func_8006E070(win, 0);
    ShowTextWindow(win);
    PlaySound(0x432);
    WAIT_TEXT(win);
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
    win = CreateTextWindow(0x1E, 0x46, 0xE, 3);
    LoadStringIntoWindow(win, (void*)0x507, -1, -1);
    func_8006E070(win, 0);
    ShowTextWindow(win);
    PlaySound(0x432);
    WAIT_TEXT(win);
    HideTextWindow(win);
    func_80041370();
    D_800F7948_MiniGameStadiumStartCopy = 0;
}

void func_800F76E0_MiniGameStadiumStartCopy(void) {
    func_800F6A20_MiniGameStadiumStartCopy();
    func_80060128(0x11);
    func_800F676C_MiniGameStadiumStartCopy();
    func_800F6DA0_MiniGameStadiumStartCopy();
    func_800F6EF0_MiniGameStadiumStartCopy();
    D_800F5144 = 1;
    while (TRUE) {
        HuPrcVSleep();
    }
}

void func_800F7738_MiniGameStadiumStartCopy(omObjData* obj) {
    if (func_80072718() == 0) {
        func_800F7918_MiniGameStadiumStartCopy();
        func_800F780C_MiniGameStadiumStartCopy();
        func_80070ED4();
        if (D_800F7944_MiniGameStadiumStartCopy != 0) {
            func_80054654();
        }
        omOvlReturnEx(1);
    }
}

void func_800F7794_MiniGameStadiumStartCopy(omObjData* obj) {
    if (D_800F5144 != 0) {
        func_800726AC(2, 0x14);
        func_800601D4(0x1E);
        obj->func_ptr = &func_800F7738_MiniGameStadiumStartCopy;
    }
}

void func_800F77E0_MiniGameStadiumStartCopy(void) {
    MBModelInit();
    func_80053020();
    func_8004F2AC();
}

void func_800F780C_MiniGameStadiumStartCopy(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_80052FD4(i);
    }
    if (D_800F7940_MiniGameStadiumStartCopy != NULL) {
        MBModelKill(D_800F7940_MiniGameStadiumStartCopy);
    }
    if (D_800F7948_MiniGameStadiumStartCopy != 0) {
        func_80041370();
    }
    func_8004F2EC();
}

void func_800F7880_MiniGameStadiumStartCopy(void) {
    func_800178A0(1);
    func_80017660(0, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    LoadBackgroundData(D_FE2310);
}

void func_800F7918_MiniGameStadiumStartCopy(void) {
    func_8004A140();
    func_80049F0C();
}
