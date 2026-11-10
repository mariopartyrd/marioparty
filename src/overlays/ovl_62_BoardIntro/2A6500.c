#include "ovl62b.h"
#include "spaces.h"

/* One gate model's state: shown when its y scale is 1.0 (0.1 = lowered). */
typedef struct GateState {
    /* 0x00 */ s16 on;
    /* 0x04 */ f32 scale;
} GateState; /* size = 0x08 */

void FreeSpaceTexturesWrapper(void);
void func_800FA72C_BoardIntro(void);
void func_800FA770_BoardIntro(void);
void func_800FA908_BoardIntro(void);
void func_800FA970_BoardIntro(void);
void func_800FACF0_BoardIntro(void);

extern s16 D_800FD750_BoardIntro[5]; /* board space of each 0x16 model */
extern s16 D_800FD75C_BoardIntro[9]; /* board space of each gate */
extern f32 D_800FD770_BoardIntro[9]; /* gate y rotation */
extern u16 D_800FD794_BoardIntro[2]; /* gate model per kind */
extern s16 D_800FD798_BoardIntro[9]; /* gate kind (0/1) */
extern Vec3f D_800FD7B0_BoardIntro[2]; /* camera path: start, end */
extern Object* D_800FDAE0_BoardIntro; /* bss: the first 0x16 model (later ones copy it) */
extern Object* D_800FDAE8_BoardIntro[5]; /* bss */
extern Object* D_800FDAFC_BoardIntro[2]; /* bss: the first gate model of each kind */
extern Object* D_800FDB08_BoardIntro[9]; /* bss: gate models */
/* bss: gate states; splat split it into D_800FDB30 (.on of [0]) and D_800FDB34 (from .scale of [0]). */
extern GateState D_800FDB30_BoardIntro[9];

/* .data */

s16 D_800FD750_BoardIntro[5] = {
    98, 102, 101, 99, 100,
};

s16 D_800FD75C_BoardIntro[9] = {
    74, 76, 75, 77, 78, 79, 80, 82,
    83,
};

f32 D_800FD770_BoardIntro[9] = {
    90.0f, 0.0f, 90.0f, 0.0f,
    90.0f, 90.0f, 90.0f, 90.0f,
    90.0f,
};

u16 D_800FD794_BoardIntro[2] = {
    0x77, 0x33,
};

s16 D_800FD798_BoardIntro[9] = {
    0, 1, 0, 0, 1, 0, 1, 0,
    1,
};

/* Three more gate-kind halfwords past the nine gates (unread); scalars keep halfword alignment. */
s16 D_800FD7AA_BoardIntro = 0;
s16 D_800FD7AC_BoardIntro = 1;
s16 D_800FD7AE_BoardIntro = 0;

Vec3f D_800FD7B0_BoardIntro[2] = {
    { 0.0f, 0.0f, -1078.0f },
    { 1193.0f, 0.0f, 1014.0f },
};

void func_800FA5E0_BoardIntro(void) {
    LoadInitialSpaceTextures();
    LoadBoardSpaces(10, 0x49);
    D_800F3290 = 0;
    func_800FA72C_BoardIntro();
    GwCommon.boardWork[2] = 3;
    func_800FA908_BoardIntro();
    func_800FACF0_BoardIntro();
}
void func_800FA62C_BoardIntro(void) {
    func_800FA770_BoardIntro();
    func_800FA970_BoardIntro();
    FreeBoardSpaces();
    FreeSpaceTexturesWrapper();
}
void func_800FA660_BoardIntro(s16 idx) {
    Object* obj;

    if (D_800FDAE8_BoardIntro[idx] == NULL) {
        if (D_800FDAE0_BoardIntro == NULL) {
            obj = MBModelCreate(0x16, NULL);
            func_8003E174(obj);
            D_800FDAE0_BoardIntro = obj;
        } else {
            obj = MBModelParamCreate(D_800FDAE0_BoardIntro);
        }
        obj->unk_0A |= 2;
        D_800FDAE8_BoardIntro[idx] = obj;
        func_800A0D50(&obj->coords, &BoardSpaceGet(D_800FD750_BoardIntro[idx])->coords);
        obj->coords.y = 0.0f;
    }
}
void func_800FA72C_BoardIntro(void) {
    s32 i;

    D_800FDAE0_BoardIntro = NULL;
    for (i = 0; i < 5; i++) {
        func_800FA660_BoardIntro(i);
    }
}
void func_800FA770_BoardIntro(void) {
    s32 i;

    for (i = 0; i < 5; i++) {
        if (D_800FDAE8_BoardIntro[i] != NULL) {
            MBModelKill(D_800FDAE8_BoardIntro[i]);
            D_800FDAE8_BoardIntro[i] = NULL;
        }
    }
}
void func_800FA7D4_BoardIntro(s16 idx) {
    Object* obj;
    s16 kind;
    u16 model;

    if (D_800FDB08_BoardIntro[idx] == NULL) {
        kind = D_800FD798_BoardIntro[idx];
        model = D_800FD794_BoardIntro[kind];
        if (D_800FDAFC_BoardIntro[kind] == NULL) {
            obj = MBModelCreate(model, NULL);
            func_8003E174(obj);
            D_800FDAFC_BoardIntro[kind] = obj;
        } else {
            obj = MBModelParamCreate(D_800FDAFC_BoardIntro[kind]);
        }
        obj->unk_0A |= 2;
        D_800FDB08_BoardIntro[idx] = obj;
        func_800A0D00((Vec3f*)&obj->xScale, 1.0f, 2.0f, 1.0f);
        func_8003D514(&obj->unk_18, D_800FD770_BoardIntro[idx]);
        func_800A0D50(&obj->coords, &BoardSpaceGet(D_800FD75C_BoardIntro[idx])->coords);
        obj->coords.y = 0.0f;
    }
}
void func_800FA908_BoardIntro(void) {
    s32 i;

    D_800FDAFC_BoardIntro[0] = NULL;
    D_800FDAFC_BoardIntro[1] = NULL;
    for (i = 0; i < 9; i++) {
        D_800FDB08_BoardIntro[i] = NULL;
        func_800FA7D4_BoardIntro(i);
    }
}
void func_800FA970_BoardIntro(void) {
    s32 i;

    for (i = 0; i < 9; i++) {
        if (D_800FDB08_BoardIntro[i] != NULL) {
            MBModelKill(D_800FDB08_BoardIntro[i]);
            D_800FDB08_BoardIntro[i] = NULL;
        }
    }
}
void func_800FA9D4_BoardIntro(GateState* gates, s16 n) {
    s32 i;

    switch ((s16)(n % 4)) {
        case 0:
            gates[0].scale = 1.0f;
            gates[1].scale = 1.0f;
            gates[2].scale = 0.1f;
            break;
        case 1:
        case 3:
            gates[0].scale = 1.0f;
            gates[1].scale = 0.1f;
            gates[2].scale = 1.0f;
            break;
        case 2:
            gates[0].scale = 0.1f;
            gates[1].scale = 1.0f;
            gates[2].scale = 1.0f;
            break;
    }
    switch ((s16)(n % 2)) {
        case 0:
            gates[3].scale = 0.1f;
            gates[4].scale = 1.0f;
            break;
        case 1:
            gates[3].scale = 1.0f;
            gates[4].scale = 0.1f;
            break;
    }
    switch ((s16)(n % 2)) {
        case 0:
            gates[5].scale = 0.1f;
            gates[6].scale = 1.0f;
            break;
        case 1:
            gates[5].scale = 1.0f;
            gates[6].scale = 0.1f;
            break;
    }
    switch ((s16)(n % 2)) {
        case 0:
            gates[7].scale = 0.1f;
            gates[8].scale = 1.0f;
            break;
        case 1:
            gates[7].scale = 1.0f;
            gates[8].scale = 0.1f;
            break;
    }
    for (i = 0; i < 9; i++) {
        if (gates[i].scale >= 1.0f) {
            gates[i].on = 1;
        } else {
            gates[i].on = 0;
        }
    }
}
void func_800FACAC_BoardIntro(s16 idx, f32 scale) {
    func_800A0D00((Vec3f*)&D_800FDB08_BoardIntro[idx]->xScale, 1.0f, scale, 1.0f);
}
void func_800FACF0_BoardIntro(void) {
    s32 i;

    func_800FA9D4_BoardIntro(D_800FDB30_BoardIntro, GwCommon.boardWork[2]);
    for (i = 0; i < 9; i++) {
        func_800FACAC_BoardIntro(i, D_800FDB30_BoardIntro[i].scale);
    }
}
void func_800FAD50_BoardIntro(void) {
    LoadBackgroundIndex(0x27);
    func_800FA5E0_BoardIntro();
    HuPrcSleep(2);
    func_8004B5DC(&D_800FD7B0_BoardIntro[0]);
    func_80060128(0x3A);
    SetFadeInTypeAndTime(2, 16);
    HuPrcSleep(16);
    func_8004A520();
    HuPrcSleep(30);
    HuPrcSleep(func_8004FD68(&D_800FD7B0_BoardIntro[0], &D_800FD7B0_BoardIntro[1], 20.0f) + 20);
    func_800601D4(40);
    func_800726AC(2, 20);
    HuPrcSleep(20);
    func_8004A140();
    func_800FA62C_BoardIntro();
}
void func_800FADFC_BoardIntro(void) {
    Object* obj;
    s32 i;

    obj = D_800FCD70_BoardIntro = MBModelCreate(8, D_800FD528_BoardIntro);
    obj->coords.x = D_800FD3CC_BoardIntro[D_801102B0].x;
    obj->coords.y = D_800FD3CC_BoardIntro[D_801102B0].y;
    obj->coords.z = D_800FD3CC_BoardIntro[D_801102B0].z;
    func_8004CCD0(&obj->coords, &D_800FD42C_BoardIntro, &obj->unk_18);
    func_8004F140(*D_800FCD70_BoardIntro->unk_3C->unk_40);
    MBMotionSet(D_800FCD70_BoardIntro, 2, 2);
    func_8004E3E0(0, &D_800FD42C_BoardIntro, 20, D_800FCD70_BoardIntro);
    HuPrcSleep(5);
    HuPrcSleep(10);
    func_8004F4D4(D_800FCD70_BoardIntro, 0, 2);
    for (i = 0; i < 4; i++) {
        func_8004EE14(i, &D_800FD42C_BoardIntro, 10, NULL);
        func_8004F4D4(GwPlayer[i].player_obj, 3, 2);
    }
    HuPrcSleep(5);
    func_8004EE14(0, &GwPlayer[0].player_obj->coords, 10, D_800FCD70_BoardIntro);
    HuPrcSleep(10);
}