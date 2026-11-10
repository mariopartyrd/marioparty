#include "ovl62b.h"

void func_8004F1D0(void);
/* Retail passes the window id unextended here (it was called without the s16 prototype). */
#define WAIT_TEXT(w) ((void (*)())WaitForTextConfirmation)(w)
void func_800FC018_BoardIntro(void);
s32 func_800415E8(s32);
void func_80040590(s32);
void HidePlayerHUDVisibility(s32, s32);
extern char* D_800C5218[]; /* character names */
void func_800FC620_BoardIntro(void);
void func_800FC64C_BoardIntro(void);

extern Vec3f D_800FD850_BoardIntro[3]; /* camera path; splat split it at D_800FD85C ([1]) */
extern Vec3f D_800FD874_BoardIntro[2]; /* sign positions; splat split it at D_800FD880 ([1]) */
extern Vec3f D_800FD88C_BoardIntro;
extern Vec3f D_800FD898_BoardIntro;
extern Vec3f D_800FD8A4_BoardIntro;
extern Vec3f D_800FD8B0_BoardIntro;
extern Vec3f D_800FD8BC_BoardIntro;
extern Vec3f D_800FD8C8_BoardIntro[4]; /* one per player */
extern Vec3f D_800FD8F8_BoardIntro;
extern Vec3f D_800FD904_BoardIntro;
extern s32 D_800FD910_BoardIntro[]; /* MBModelCreate motion lists: a count, then file ids */
extern s32 D_800FD920_BoardIntro[];
extern s16 D_800FDB80_BoardIntro; /* bss: the message window */

/* .data */

Vec3f D_800FD850_BoardIntro[3] = {
    { -1033.0f, 0.0f, -1058.0f },
    { 1114.0f, 0.0f, -796.0f },
    { 886.0f, 0.0f, 1067.0f },
};

Vec3f D_800FD874_BoardIntro[2] = {
    { 525.0f, 185.0f, -3100.0f },
    { 200.0f, 215.0f, -3350.0f },
};

Vec3f D_800FD88C_BoardIntro = { -400.0f, 20.0f, 1475.0f };

Vec3f D_800FD898_BoardIntro = { -370.0f, 180.0f, 1125.0f };

Vec3f D_800FD8A4_BoardIntro = { -145.0f, 0.0f, 1390.0f };

Vec3f D_800FD8B0_BoardIntro = { 865.0f, 180.0f, 820.0f };

Vec3f D_800FD8BC_BoardIntro = { -1605.0f, 180.0f, 5930.0f };

Vec3f D_800FD8C8_BoardIntro[4] = {
    { -25.0f, 0.0f, 2160.0f },
    { 160.0f, 0.0f, 1665.0f },
    { 270.0f, 0.0f, 1865.0f },
    { 375.0f, 0.0f, 2035.0f },
};

Vec3f D_800FD8F8_BoardIntro = { 752.0f, 0.0f, 1443.0f };

Vec3f D_800FD904_BoardIntro = { -145.0f, 0.0f, 1390.0f };

s32 D_800FD910_BoardIntro[4] = {
    3, 0xA0068, 0xA006B, 0xA006E,
};

s32 D_800FD920_BoardIntro[4] = {
    1, 0xA00EC, 0, 0,
};

char D_800FD930_BoardIntro[12] = {
    0x94, 0x92, 0x94, 0xBD, 0xA9, 0xDD, 0xE0, 0x84,
    0x00, 0x00, 0x00, 0x00,
};

char D_800FD93C_BoardIntro[12] = {
    0xD8, 0xCF, 0xEA, 0x81, 0xA9, 0x96, 0x9B, 0x80,
    0xBD, 0x00, 0x00, 0x00,
};

char D_800FD948_BoardIntro[12] = {
    0xEF, 0xF8, 0xD5, 0xA9, 0xA6, 0x9C, 0x80, 0xA9,
    0x9C, 0xBB, 0x00, 0x00,
};

char D_800FD954_BoardIntro[12] = {
    0xF9, 0xD2, 0x84, 0xDC, 0x80, 0xA9, 0x97, 0x96,
    0xBD, 0x9C, 0xA2, 0x00,
};

char D_800FD960_BoardIntro[12] = {
    0xFC, 0xF8, 0xD5, 0xA9, 0x9E, 0xBD, 0x9C, 0x80,
    0x8E, 0x93, 0x00, 0x00,
};

char D_800FD96C_BoardIntro[8] = {
    0xF6, 0xCF, 0xDC, 0x84, 0xA9, 0x9C, 0xAF, 0x00,
};

char D_800FD974_BoardIntro[12] = {
    0xEB, 0x81, 0x84, 0xE1, 0xA9, 0xD9, 0x84, 0xD7,
    0x00, 0x00, 0x00, 0x00,
};

char D_800FD980_BoardIntro[16] = {
    0xE4, 0x80, 0xFD, 0xD7, 0x84, 0xA9, 0xDC, 0x80,
    0xCC, 0xFD, 0xD8, 0x80, 0xF9, 0x00, 0x00, 0x00,
};

void func_800FB7C0_BoardIntro(void) {
    Object* obj;

    LoadBackgroundIndex(0x44);
    HuPrcSleep(2);
    func_8004B5DC(&D_800FD850_BoardIntro[0]);
    func_80060128(0x3A);
    SetFadeInTypeAndTime(2, 16);
    HuPrcSleep(16);
    func_8004A520();
    HuPrcSleep(30);
    HuPrcSleep(func_8004FEA0(&D_800FD850_BoardIntro[0], &D_800FD850_BoardIntro[1]) + 20);
    HuPrcSleep(func_8004FEA0(&D_800FD850_BoardIntro[1], &D_800FD850_BoardIntro[2]) + 30);
    func_800601D4(40);
    func_800726AC(2, 20);
    HuPrcSleep(20);
    func_8004A140();
    MDL88_0 = MBModelCreate(6, D_800FD910_BoardIntro);
    MDL88_1 = MBModelCreate(6, D_800FD910_BoardIntro);
    MDL88_0->coords.x = MDL88_1->coords.x = D_800FD874_BoardIntro[0].x;
    MDL88_0->coords.y = MDL88_1->coords.y = D_800FD874_BoardIntro[0].y;
    MDL88_0->coords.z = MDL88_1->coords.z = D_800FD874_BoardIntro[0].z;
    MDL88_0->unk_18.x = MDL88_1->unk_18.x = -1.0f;
    /* retail sets MDL88_1's x three times: its y and z keep their values */
    MDL88_0->unk_18.y = MDL88_1->unk_18.x = 0.0f;
    MDL88_0->unk_18.z = MDL88_1->unk_18.x = 0.0f;
    MDL88_0->xScale = MDL88_0->yScale = MDL88_0->zScale = 1.5f;
    MDL88_1->xScale = MDL88_1->yScale = MDL88_1->zScale = 1.5f;
    MBModelDispOff(MDL88_1);
    obj = MDL88_2 = MBModelCreate(0x78, D_800FD920_BoardIntro);
    func_800A0D00(&obj->coords, D_800FD8F8_BoardIntro.x, D_800FD8F8_BoardIntro.y, D_800FD8F8_BoardIntro.z);
}
void func_800FB9CC_BoardIntro(void) {
    s32 id;
    s32 i;

    id = LoadFormFile(0xA015F, 0x2B9);
    func_80025798(id, MDL88_0->coords.x, MDL88_0->coords.y, MDL88_0->coords.z);
    func_80025830(id, 3.0f, 3.0f, 3.0f);
    for (i = 0; i < 256; i += 8) {
        func_800211BC(MDL88_0->unk_3C->unk_40[0], i);
        func_800211BC(MDL88_0->unk_40->unk_40[0], ~i);
        HuPrcVSleep();
    }
    MBModelDispOff(MDL88_0);
    func_8002456C(id);
}
void func_800FBAA8_BoardIntro(void) {
    s32 id;
    s32 i;

    id = LoadFormFile(0xA015F, 0x2B9);
    func_80025798(id, MDL88_0->coords.x, MDL88_0->coords.y, MDL88_0->coords.z);
    func_80025830(id, 3.0f, 3.0f, 3.0f);
    MBModelDispOn(MDL88_0);
    for (i = 255; i >= 0; i -= 8) {
        func_800211BC(MDL88_0->unk_3C->unk_40[0], i);
        func_800211BC(MDL88_0->unk_40->unk_40[0], ~i);
        HuPrcVSleep();
    }
    func_800211BC(MDL88_0->unk_3C->unk_40[0], 0);
    func_800211BC(MDL88_0->unk_40->unk_40[0], 255);
    func_8002456C(id);
}
void func_800FBBB8_BoardIntro(void) {
    s32 win;
    s32 i;
    s32 j;

    func_8004F4D4(MDL88_1, 1, 0);
    HuPrcSleep(15);
    PlaySound(0x6C);
    HuPrcSleep(5);
    PlaySound(0xD0);
    func_8004E3E0(0, &D_800FD8B0_BoardIntro, 20, D_800FCD70_BoardIntro);
    for (i = 0; i < 4; i++) {
        func_8004E3E0(i, &D_800FD8C8_BoardIntro[i], 20, NULL);
        func_8004F4D4(GwPlayer[i].player_obj, 3, 0);
    }
    for (i = 0; i < 20; i++) {
        D_800FCD70_BoardIntro->unk_18.x = sinf((i * 100) * 0.017453292519943295);
        D_800FCD70_BoardIntro->unk_18.z = cosf((i * 100) * 0.017453292519943295);
        for (j = 0; j < 4; j++) {
            func_8004CCD0(&GwPlayer[j].player_obj->coords, &MDL88_0->coords, &GwPlayer[j].player_obj->unk_18);
        }
        HuPrcVSleep();
    }
    func_8004F1D0();
    MBModelKill(D_800FCD70_BoardIntro);
    D_800FCD70_BoardIntro = NULL;
    func_8004F4D4(MDL88_1, 0, 2);
    for (i = 0; i < 4; i++) {
        func_8004EE14(i, &MDL88_0->coords, 10, NULL);
        func_8004F4D4(GwPlayer[i].player_obj, 2, 2);
    }
    HuPrcSleep(10);
    func_80060128(0x12);
    win = CreateTextWindow(30, 42, 19, 4);
    LoadStringIntoWindow(win, (void*)0x245, -1, -1);
    func_8006E070(win, 0);
    ShowTextWindow(win);
    PlaySound(0x46A);
    WAIT_TEXT(win);
    HideTextWindow(win);
    func_8004CCD0(&MDL88_2->coords, &D_800FD904_BoardIntro, &MDL88_2->unk_18);
    func_8004E3E0(0, &D_800FD904_BoardIntro, 30, MDL88_2);
    func_8004F4D4(MDL88_2, 0, 2);
    HuPrcSleep(30);
    func_8004F4D4(MDL88_2, -1, 2);
    func_8004EE14(0, &GwPlayer[0].player_obj->coords, 10, MDL88_2);
    HuPrcSleep(10);
    win = CreateTextWindow(30, 42, 19, 4);
    LoadStringIntoWindow(win, (void*)0x246, -1, -1);
    func_8006E070(win, 0);
    ShowTextWindow(win);
    PlaySound(0x46C);
    WAIT_TEXT(win);
    HideTextWindow(win);
    func_800FC018_BoardIntro();
    func_8004EE14(0, &D_800FD88C_BoardIntro, 10, MDL88_2);
    func_8004F4D4(MDL88_2, 0, 2);
    HuPrcSleep(10);
    func_8004E3E0(0, &D_800FD88C_BoardIntro, 10, MDL88_2);
    HuPrcSleep(10);
    func_8004F4D4(MDL88_2, -1, 2);
    func_8004EE14(0, &GwPlayer[0].player_obj->coords, 10, MDL88_2);
    HuPrcSleep(10);
    win = CreateTextWindow(30, 42, 19, 4);
    LoadStringIntoWindow(win, (void*)0x247, -1, -1);
    func_8006E070(win, 0);
    ShowTextWindow(win);
    PlaySound(0xF0);
    WAIT_TEXT(win);
    HideTextWindow(win);
}
void func_800FC018_BoardIntro(void) {
    MBModelDispOff(MDL88_1);
    MBModelDispOn(MDL88_0);
    PlaySound(0x47);
    func_800FB9CC_BoardIntro();
    MDL88_0->coords.x = MDL88_1->coords.x = D_800FD874_BoardIntro[1].x;
    MDL88_0->coords.y = MDL88_1->coords.y = D_800FD874_BoardIntro[1].y;
    MDL88_0->coords.z = MDL88_1->coords.z = D_800FD874_BoardIntro[1].z;
    MDL88_0->unk_18.x = MDL88_1->unk_18.x = 1.0f;
    MDL88_0->unk_18.y = MDL88_1->unk_18.y = 0.0f;
    MDL88_0->unk_18.z = MDL88_1->unk_18.z = 0.0f;
    func_800FBAA8_BoardIntro();
    MBModelDispOff(MDL88_0);
    MBModelDispOn(MDL88_1);
    func_8004F4D4(MDL88_1, 2, 2);
    func_8004E3E0(0, &D_800FD874_BoardIntro[0], 20, MDL88_0);
    func_8004E3E0(0, &D_800FD874_BoardIntro[0], 20, MDL88_1);
    HuPrcSleep(20);
    func_8004EE14(0, &GwPlayer[0].player_obj->coords, 10, MDL88_0);
    func_8004EE14(0, &GwPlayer[0].player_obj->coords, 10, MDL88_1);
    HuPrcSleep(10);
    func_8004F4D4(MDL88_1, 0, 2);
    HuPrcSleep(20);
}
void func_800FC1CC_BoardIntro(void) {
    Object* obj;
    Object* mdl;
    s32 i;

    obj = D_800FCD70_BoardIntro = MBModelCreate(8, NULL);
    obj->coords.x = D_800FD3CC_BoardIntro[D_801102B0].x;
    obj->coords.y = D_800FD3CC_BoardIntro[D_801102B0].y;
    obj->coords.z = D_800FD3CC_BoardIntro[D_801102B0].z;
    func_8004CCD0(&obj->coords, &D_800F32A0->coords, &obj->unk_18);
    func_8004F140(*D_800FCD70_BoardIntro->unk_3C->unk_40);
    mdl = MBModelCreate(0x41, NULL);
    mdl->coords.x = D_800FD3CC_BoardIntro[D_801102B0].x;
    mdl->coords.y = D_800FD3CC_BoardIntro[D_801102B0].y;
    mdl->coords.z = D_800FD3CC_BoardIntro[D_801102B0].z;
    /* retail passes D_800FCD70's rotation, not mdl's */
    func_8004CCD0(&mdl->coords, &D_800F32A0->coords, &D_800FCD70_BoardIntro->unk_18);
    func_8004E3E0(0, &D_800FD898_BoardIntro, 40, D_800FCD70_BoardIntro);
    func_8004E3E0(0, &D_800FD8BC_BoardIntro, 80, mdl);
    HuPrcSleep(39);
    func_8004F00C(D_800FCD70_BoardIntro, 15.0f, -2.0f);
    D_800FCD70_BoardIntro->unk_30 = D_800FCD70_BoardIntro->coords.y;
    D_800FCD70_BoardIntro->coords.y = 0.0f;
    func_8004E3E0(0, &D_800FD8A4_BoardIntro, 20, D_800FCD70_BoardIntro);
    func_8004F044(D_800FCD70_BoardIntro);
    for (i = 0; i < 4; i++) {
        func_8004EE14(i, &D_800FD8A4_BoardIntro, 10, NULL);
        func_8004F4D4(GwPlayer[i].player_obj, 3, 2);
    }
    func_8004EE14(0, &GwPlayer[0].player_obj->coords, 10, D_800FCD70_BoardIntro);
    HuPrcSleep(10);
    for (i = 0; i < 4; i++) {
        func_8004F4D4(GwPlayer[i].player_obj, 2, 2);
    }
    HuPrcSleep(10);
    MBModelKill(mdl);
    for (i = 0; i < 4; i++) {
        func_8004F4D4(GwPlayer[i].player_obj, 3, 2);
    }
}
void func_800FC460_BoardIntro(void) {
    func_8004F4D4(MDL88_0, 2, 2);
    func_8004E3E0(0, &D_800FD874_BoardIntro[1], 20, MDL88_0);
    func_8004E3E0(0, &D_800FD874_BoardIntro[1], 20, MDL88_1);
    HuPrcSleep(20);
    func_8004F4D4(MDL88_0, 0, 2);
    func_80025930(MDL88_0->unk_3C->unk_40[0], 0, 0x8000);
    func_80025930(MDL88_0->unk_40->unk_40[0], 0, 0x8000);
    func_80021240(MDL88_0->unk_3C->unk_40[0]);
    func_80021240(MDL88_0->unk_40->unk_40[0]);
    func_800FB9CC_BoardIntro();
    MDL88_0->coords.x = MDL88_1->coords.x = D_800FD88C_BoardIntro.x;
    MDL88_0->coords.y = MDL88_1->coords.y = D_800FD88C_BoardIntro.y;
    MDL88_0->coords.z = MDL88_1->coords.z = D_800FD88C_BoardIntro.z;
    func_8004CCD0(&MDL88_0->coords, &GwPlayer[0].player_obj->coords, &MDL88_0->unk_18);
    func_8004CCD0(&MDL88_1->coords, &GwPlayer[0].player_obj->coords, &MDL88_1->unk_18);
    PlaySound(0x47);
    func_800FBAA8_BoardIntro();
    MBModelDispOff(MDL88_0);
    MBModelDispOn(MDL88_1);
    D_800FCDB4_BoardIntro = NULL;
    EndProcess(NULL);
}
void func_800FC620_BoardIntro(void) {
    D_800FDB80_BoardIntro = func_8007194C(80, 182, 3);
}
void func_800FC64C_BoardIntro(void) {
    func_80071E80(D_800FDB80_BoardIntro, 1);
    func_80072080(D_800FDB80_BoardIntro);
}
void func_800FC67C_BoardIntro(void) {
    void* msgs[2];
    u32 i;

    msgs[0] = (void*)0x210;
    msgs[1] = (void*)0x211;
    func_800FC620_BoardIntro();
    LoadStringIntoWindow(D_800FDB80_BoardIntro, msgs[0], -1, -1);
    func_8006E070(D_800FDB80_BoardIntro, 0);
    func_80071C8C(D_800FDB80_BoardIntro, 1);
    for (i = 0; i < 2; i++) {
        func_8004E0E8(D_800FDB80_BoardIntro);
        if (i == 1) {
            break;
        }
        func_8006EB40(D_800FDB80_BoardIntro);
        LoadStringIntoWindow(D_800FDB80_BoardIntro, msgs[i + 1], -1, -1);
        func_8006E070(D_800FDB80_BoardIntro, 0);
    }
    func_800FC64C_BoardIntro();
}
void func_800FC768_BoardIntro(void) {
    s32 timer[4];
    u8 state[4];
    u8 count[4];
    u8 order[4];
    s32 i;
    s32 j;
    s32 n;

    func_800FC620_BoardIntro();
    LoadStringIntoWindow(D_800FDB80_BoardIntro, (void*)0x212, -1, -1);
    func_8006E070(D_800FDB80_BoardIntro, 0);
    func_80071C8C(D_800FDB80_BoardIntro, 1);
    func_8004E0E8(D_800FDB80_BoardIntro);
    func_8006EB40(D_800FDB80_BoardIntro);
    LoadStringIntoWindow(D_800FDB80_BoardIntro, (void*)0x213, -1, -1);
    func_8006E070(D_800FDB80_BoardIntro, 0);
    func_8004E0E8(D_800FDB80_BoardIntro);
    func_800FC64C_BoardIntro();
    for (i = 0; i < 4; i++) {
        switch (GwPlayer[i].character) {
            case 0:
                n = 10;
                break;
            case 1:
                n = (rand8() & 3) + 6;
                break;
            case 2:
                n = (rand8() & 3) + 2;
                break;
            case 3:
                n = 1;
                break;
            default:
                n = 5;
                break;
        }
        func_800415CC(i, n);
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
    func_800F66E8_BoardIntro();
    func_800544E4();
    D_800FCDA8_BoardIntro = 1;
    for (i = 0; i < 4; i++) {
        HidePlayerHUDVisibility(i, 1);
    }
    HuPrcSleep(5);
    for (i = 0; i < 4; i++) {
        func_800FC620_BoardIntro();
        func_8006DA5C(D_800FDB80_BoardIntro, D_800C5218[GwPlayer[i].character], i);
        LoadStringIntoWindow(D_800FDB80_BoardIntro, (void*)(s32)(i + 0x249), -1, -1);
        func_8006E070(D_800FDB80_BoardIntro, 0);
        func_80071C8C(D_800FDB80_BoardIntro, 1);
        func_8004E0E8(D_800FDB80_BoardIntro);
        func_800FC64C_BoardIntro();
        func_8004F4D4(GwPlayer[i].player_obj, 6, 0);
        func_8004F40C(GwPlayer[i].player_obj, 2, 2);
        func_80060468(0x451, GwPlayer[i].character);
        func_800405DC(order[i]);
        func_80054868(i + 10);
        while (func_80054FA8() != 0) {
            HuPrcVSleep();
        }
        HuPrcSleep(20);
    }
    func_80041370();
}
/* Not a function: the two nops padding .text to its 16-byte end. 2A2500's asm addresses a .data
   table at 0x800FCD30 from index 1 (base 0x800FCD2C), and splat named that address after the
   second nop. Emit the padding with the label so the address and the text size stay retail's. */
__asm__(".section .text\n"
        "    .set noreorder\n"
        "    nop\n"
        "    .globl func_800FCD2C_BoardIntro\n"
        "    .type func_800FCD2C_BoardIntro, @function\n"
        "func_800FCD2C_BoardIntro:\n"
        "    nop\n"
        "    .size func_800FCD2C_BoardIntro, . - func_800FCD2C_BoardIntro\n"
        "    .set reorder\n");
