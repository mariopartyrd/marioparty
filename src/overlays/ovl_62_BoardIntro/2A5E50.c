#include "ovl62b.h"
#include "spaces.h"

void func_8004CD48(Object*, s16);
void FreeSpaceTexturesWrapper(void);
void func_8004F548(void);
s32 func_8004F628(s32, u16, s16, s16);
void func_8004F800(s32, s32);
void func_8004F830(s32, s32);
void func_800FA0C0_BoardIntro(void);
void func_800FA104_BoardIntro(void);

extern s16 D_800FD720_BoardIntro[4]; /* board space of each marker model */
extern s16 D_800FD728_BoardIntro[4]; /* marker motion when boardWork[15] == 0 */
extern s16 D_800FD730_BoardIntro[4]; /* marker motion otherwise */
extern Vec3f D_800FD738_BoardIntro[2]; /* camera path: start, end */
extern Object* D_800FDAC0_BoardIntro; /* bss: the first marker model (later ones copy it) */
extern Object* D_800FDAC8_BoardIntro[4]; /* bss: marker models */
extern Object* D_800FDAD8_BoardIntro; /* bss */

/* .data */

s16 D_800FD720_BoardIntro[4] = {
    71, 73, 69, 70,
};

s16 D_800FD728_BoardIntro[4] = {
    98, 95, 96, 97,
};

s16 D_800FD730_BoardIntro[4] = {
    96, 97, 98, 95,
};

Vec3f D_800FD738_BoardIntro[2] = {
    { 1035.0f, 0.0f, -1209.0f },
    { -1318.0f, 0.0f, 456.0f },
};

void func_800F9F30_BoardIntro(void) {
    LoadInitialSpaceTextures();
    LoadBoardSpaces(10, 0x48);
    D_800F3290 = 0;
    GwCommon.boardWork[15] = 0;
    func_800FA0C0_BoardIntro();
}
void func_800F9F6C_BoardIntro(void) {
    func_800FA104_BoardIntro();
    FreeBoardSpaces();
    FreeSpaceTexturesWrapper();
}
void func_800F9F98_BoardIntro(s16 idx) {
    Object* obj;

    if (D_800FDAC8_BoardIntro[idx] == NULL) {
        if (D_800FDAC0_BoardIntro == NULL) {
            obj = MBModelCreate(0x43, NULL);
            func_8003E174(obj);
            D_800FDAC0_BoardIntro = obj;
        } else {
            obj = MBModelParamCreate(D_800FDAC0_BoardIntro);
        }
        obj->unk_0A |= 2;
        D_800FDAC8_BoardIntro[idx] = obj;
        func_800A0D00((Vec3f*)&obj->xScale, 0.8f, 0.8f, 0.8f);
        func_800A0D50(&obj->coords, &BoardSpaceGet(D_800FD720_BoardIntro[idx])->coords);
        if (GwCommon.boardWork[15] == 0) {
            func_8004CD48(obj, D_800FD728_BoardIntro[idx]);
        } else {
            func_8004CD48(obj, D_800FD730_BoardIntro[idx]);
        }
    }
}
void func_800FA0C0_BoardIntro(void) {
    s32 i;

    D_800FDAC0_BoardIntro = NULL;
    for (i = 0; i < 4; i++) {
        func_800F9F98_BoardIntro(i);
    }
}
void func_800FA104_BoardIntro(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_800FDAC8_BoardIntro[i] != NULL) {
            MBModelKill(D_800FDAC8_BoardIntro[i]);
            D_800FDAC8_BoardIntro[i] = NULL;
        }
    }
}
void func_800FA168_BoardIntro(void) {
    LoadBackgroundIndex(0x1B);
    func_800F9F30_BoardIntro();
    HuPrcSleep(2);
    func_8004B5DC(&D_800FD738_BoardIntro[0]);
    func_80060128(0x3A);
    SetFadeInTypeAndTime(2, 16);
    HuPrcSleep(16);
    func_8004A520();
    HuPrcSleep(30);
    HuPrcSleep(func_8004FD68(&D_800FD738_BoardIntro[0], &D_800FD738_BoardIntro[1], 18.0f) + 20);
    func_800601D4(40);
    func_800726AC(2, 20);
    HuPrcSleep(20);
    func_8004A140();
    func_800F9F6C_BoardIntro();
}
void func_800FA214_BoardIntro(void) {
    Vec3f pos;
    Object* obj;
    s32 fx;
    s32 spr;
    s32 i;
    s32 j;

    func_8004F548();
    func_8004F8DC();
    fx = func_8004F954(0x26, 32);
    func_8004FA90(fx, 4.0f, 4.0f, 4.0f);
    spr = func_8004F628(0xA0149, 0x47EA, 60, 180);
    func_8004F800(spr, 0x8000);
    obj = D_800FDAD8_BoardIntro = MBModelCreate(0x38, NULL);
    pos.x = obj->coords.x = D_800FD3CC_BoardIntro[D_801102B0].x;
    pos.y = obj->coords.y = D_800FD3CC_BoardIntro[D_801102B0].y;
    pos.z = obj->coords.z = D_800FD3CC_BoardIntro[D_801102B0].z;
    (void)pos; /* retail keeps a copy it never reads */
    obj->coords.x += 1000.0f;
    obj->coords.y += 1000.0f;
    obj = D_800FCD70_BoardIntro = MBModelCreate(8, NULL);
    obj->coords.x = D_800FD3CC_BoardIntro[D_801102B0].x;
    obj->coords.y = D_800FD3CC_BoardIntro[D_801102B0].y;
    obj->coords.z = D_800FD3CC_BoardIntro[D_801102B0].z;
    func_8004EE14(0, &GwPlayer[0].player_obj->coords, 10, obj);
    func_8004F140(*D_800FCD70_BoardIntro->unk_3C->unk_40);
    MBModelDispOff(D_800FCD70_BoardIntro);
    func_8004E3E0(0, &D_800FD42C_BoardIntro, 20, D_800FDAD8_BoardIntro);
    HuPrcSleep(18);
    MBModelKill(D_800FDAD8_BoardIntro);
    func_8004F830(spr, 0x8000);
    for (i = 0; i < 30; i++) {
        for (j = 0; j < 2; j++) {
            func_8004F9F4(fx, (f32)(rand8() & 0x7F) + D_800FD42C_BoardIntro.x - 63.0f + 70.0f,
                          (f32)(rand8() & 0x7F) + D_800FD42C_BoardIntro.y - 63.0f - 20.0f,
                          D_800FD42C_BoardIntro.z + 100.0f, 1);
        }
        HuPrcVSleep();
    }
    func_8004F5F0();
    MBModelDispOn(D_800FCD70_BoardIntro);
    for (i = 0; i < 4; i++) {
        func_8004EE14(i, &D_800FCD70_BoardIntro->coords, 10, NULL);
        func_8004F4D4(GwPlayer[i].player_obj, 3, 0);
    }
    HuPrcSleep(10);
    for (i = 0; i < 4; i++) {
        func_8004F4D4(GwPlayer[i].player_obj, 2, 2);
    }
    HuPrcSleep(20);
    for (i = 0; i < 4; i++) {
        func_8004F4D4(GwPlayer[i].player_obj, 3, 2);
    }
    func_8004FAB8(fx);
}