#include "ending.h"
#include "2643A0.h"

/* 2643A0: one board's ending scene (func_800FB648) and its object functions */

s32 func_8004FD68(Vec3f* arg0, Vec3f* arg1, f32 arg2);
void func_80052DC8(s16 index, void* list);
void func_80052F34(s16 index);
void func_8004FAB8(s32);

void func_800FAD10_YoshisTropicalIslandEndingScene(omObjData* obj);
void func_800FAD64_YoshisTropicalIslandEndingScene(omObjData* obj);
void func_800FB1E4_YoshisTropicalIslandEndingScene(omObjData* obj);
void func_800FB460_YoshisTropicalIslandEndingScene(omObjData* obj);
void func_800FB514_YoshisTropicalIslandEndingScene(omObjData* obj);


#define BOARD D_801102B0_YoshisTropicalIslandEndingScene

/* .data */
/* splat's D_8010E2BC/E2C8 are [1]/[2] */
Vec3f D_8010E2B0_YoshisTropicalIslandEndingScene[3] = {
    { 89.0f, 0.0f, -87.0f },
    { -500.0f, 0.0f, -87.0f },
    { -179.0f, 0.0f, -87.0f },
};
/* splat's D_8010E2F8 is [3] (read with [2] through one base) */
Vec3f D_8010E2D4_YoshisTropicalIslandEndingScene[4] = {
    { 103.0f, 0.0f, -65.0f },
    { -220.0f, 0.0f, -65.0f },
    { 89.0f, 0.0f, -87.0f },
    { -500.0f, 0.0f, -87.0f },
};
Vec3f D_8010E304_YoshisTropicalIslandEndingScene[2] = {
    { -275.0f, 20.0f, -1246.0f },
    { -88.0f, 20.0f, 1200.0f },
};
/* model lists (count, then file ids) per character */
s32 D_8010E31C_YoshisTropicalIslandEndingScene[6] = { 5, 0x00010000, 0x00010001, 0x00010097, 0x00010003, 0x00010018 };
s32 D_8010E334_YoshisTropicalIslandEndingScene[6] = { 5, 0x00020000, 0x00020001, 0x00020097, 0x00020003, 0x00020018 };
s32 D_8010E34C_YoshisTropicalIslandEndingScene[6] = { 5, 0x00060000, 0x00060001, 0x00060097, 0x00060003, 0x00060018 };
s32 D_8010E364_YoshisTropicalIslandEndingScene[6] = { 5, 0x00030000, 0x00030001, 0x00030097, 0x00030003, 0x00030018 };
s32 D_8010E37C_YoshisTropicalIslandEndingScene[6] = { 5, 0x00040000, 0x00040001, 0x00040097, 0x00040003, 0x00040018 };
s32 D_8010E394_YoshisTropicalIslandEndingScene[6] = { 5, 0x00050000, 0x00050001, 0x00050097, 0x00050003, 0x00050018 };
s32* D_8010E3AC_YoshisTropicalIslandEndingScene[6] = {
    D_8010E31C_YoshisTropicalIslandEndingScene, D_8010E334_YoshisTropicalIslandEndingScene,
    D_8010E34C_YoshisTropicalIslandEndingScene, D_8010E364_YoshisTropicalIslandEndingScene,
    D_8010E37C_YoshisTropicalIslandEndingScene, D_8010E394_YoshisTropicalIslandEndingScene,
};
s32 D_8010E3C4_YoshisTropicalIslandEndingScene[6] = { 5, 0x00030000, 0x00030001, 0x00030097, 0x00030039, 0x0003003B };
s32 D_8010E3DC_YoshisTropicalIslandEndingScene[4] = { 3, 0x00010000, 0x00010001, 0x00010097 };
s32 D_8010E3EC_YoshisTropicalIslandEndingScene[4] = { 3, 0x00020000, 0x00020001, 0x00020097 };
s32 D_8010E3FC_YoshisTropicalIslandEndingScene[4] = { 3, 0x00060000, 0x00060001, 0x00060097 };
s32 D_8010E40C_YoshisTropicalIslandEndingScene[4] = { 3, 0x00030000, 0x00030001, 0x00030097 };
s32 D_8010E41C_YoshisTropicalIslandEndingScene[4] = { 3, 0x00040000, 0x00040001, 0x00040097 };
s32 D_8010E42C_YoshisTropicalIslandEndingScene[4] = { 3, 0x00050000, 0x00050001, 0x00050097 };
s32* D_8010E43C_YoshisTropicalIslandEndingScene[6] = {
    D_8010E3DC_YoshisTropicalIslandEndingScene, D_8010E3EC_YoshisTropicalIslandEndingScene,
    D_8010E3FC_YoshisTropicalIslandEndingScene, D_8010E40C_YoshisTropicalIslandEndingScene,
    D_8010E41C_YoshisTropicalIslandEndingScene, D_8010E42C_YoshisTropicalIslandEndingScene,
};

/* .rodata */
/* scene models (file ids), -1 ends */
const s32 D_8010EF50_YoshisTropicalIslandEndingScene[8] = { 0x65, 0x66, 0x40, 0x07, 0x08, 0x6D, 0x0D, -1 };
const Vec3f D_8010EF70_YoshisTropicalIslandEndingScene[7] = {
    { -115.0f, 0.0f, 2150.0f }, { 115.0f, 0.0f, 2150.0f }, { 0.0f, 850.0f, 2210.0f },  { 385.0f, 0.0f, 2075.0f },
    { -360.0f, 0.0f, 2090.0f }, { -215.0f, 186.5f, 2006.5f }, { 200.0f, 0.0f, 1785.0f },
};
const Vec3f D_8010EFC4_YoshisTropicalIslandEndingScene[5] = {
    { 0.0f, 0.0f, 2165.0f },     { -235.0f, 0.0f, 2140.0f }, { 260.0f, 0.0f, 2120.0f },
    { -1200.0f, 200.0f, 200.0f }, { 1350.0f, 200.0f, 200.0f },
};
const Vec3f D_8010F000_YoshisTropicalIslandEndingScene[3] = {
    { 0.0f, 0.0f, 1750.0f },
    { -235.0f, 0.0f, 1750.0f },
    { 260.0f, 0.0f, 1750.0f },
};
const Vec3f D_8010F024_YoshisTropicalIslandEndingScene = { 0.0f, 0.0f, 2500.0f };
const Vec3f D_8010F030_YoshisTropicalIslandEndingScene = { 0.0f, 350.0f, 2210.0f };

void func_800FAD10_YoshisTropicalIslandEndingScene(omObjData* obj) {
    func_800264F8(*D_80110448_YoshisTropicalIslandEndingScene[10]->unk_3C->unk_40,
                  (s16)D_801102B8_YoshisTropicalIslandEndingScene[10], obj->trans.x, "pukuSa-bmerge1",
                  "pukuSa-bmerge2", 0);
}

/* Named so the unit's .rodata stays 8-byte aligned: a li.d literal makes the KMC assembler pad
 * .rodata to 16 bytes, and 266C80's .rodata starts 8 bytes after this unit's. */
#define DTOR_RODATA __attribute__((section(".rodata")))
const f64 D_8010F060_YoshisTropicalIslandEndingScene DTOR_RODATA = M_DTOR;
const f64 D_8010F068_YoshisTropicalIslandEndingScene DTOR_RODATA = M_DTOR;

void func_800FAD64_YoshisTropicalIslandEndingScene(omObjData* obj) {
    s32 count = D_8010DC90_YoshisTropicalIslandEndingScene[GwSystem.unk_00];
    s32 i;
    f32 angle;
    f32 x;
    f32 angle2;
    f32 x2;

    switch (obj->work[3]) {
        case 0:
            for (i = 0; i < obj->trans.y; i++) {
                angle = (360 / count) * i;
                x = sinf((angle + obj->rot.y) * D_8010F060_YoshisTropicalIslandEndingScene) * obj->trans.x + D_8010DC9C_YoshisTropicalIslandEndingScene[BOARD].x;
                func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[8 + i]->coords, x,
                              D_8010DC9C_YoshisTropicalIslandEndingScene[BOARD].y,
                              cosf((angle + obj->rot.y) * D_8010F060_YoshisTropicalIslandEndingScene) * obj->trans.x +
                                  D_8010DC9C_YoshisTropicalIslandEndingScene[BOARD].z);
                func_800A0D00((Vec3f*)&D_80110448_YoshisTropicalIslandEndingScene[8 + i]->xScale, obj->scale.x,
                              obj->scale.x, obj->scale.x);
            }
            obj->rot.y -= 2.0f;
            if (obj->rot.y <= 0.0f) {
                obj->rot.y += 360.0f;
            }
            obj->work[0]++;
            break;
        case 1:
            for (i = 0; i < obj->trans.y; i++) {
                angle2 = (360 / count) * i;
                x2 = sinf((angle2 + obj->rot.y) * D_8010F068_YoshisTropicalIslandEndingScene) * obj->trans.x + D_8010DC9C_YoshisTropicalIslandEndingScene[BOARD].x;
                func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[8 + i]->coords, x2,
                              D_8010DC9C_YoshisTropicalIslandEndingScene[BOARD].y,
                              cosf((angle2 + obj->rot.y) * D_8010F068_YoshisTropicalIslandEndingScene) * obj->trans.x +
                                  D_8010DC9C_YoshisTropicalIslandEndingScene[BOARD].z + obj->scale.z);
                func_800A0D00((Vec3f*)&D_80110448_YoshisTropicalIslandEndingScene[8 + i]->xScale, obj->scale.x,
                              obj->scale.x, obj->scale.x);
                D_80110448_YoshisTropicalIslandEndingScene[8 + i]->unk_18.x =
                    sinf(sinf(obj->rot.z * D_8010F068_YoshisTropicalIslandEndingScene) * 10.0f * D_8010F068_YoshisTropicalIslandEndingScene);
                D_80110448_YoshisTropicalIslandEndingScene[8 + i]->unk_18.z =
                    cosf(sinf(obj->rot.z * D_8010F068_YoshisTropicalIslandEndingScene) * 10.0f * D_8010F068_YoshisTropicalIslandEndingScene);
            }
            obj->rot.z += 5.0f;
            if (obj->rot.z >= 360.0f) {
                obj->rot.z -= 360.0f;
            }
            break;
    }
}

const f64 D_8010F070_YoshisTropicalIslandEndingScene DTOR_RODATA = M_DTOR;
const f64 D_8010F078_YoshisTropicalIslandEndingScene DTOR_RODATA = M_DTOR;

void func_800FB1E4_YoshisTropicalIslandEndingScene(omObjData* obj) {
    switch (obj->work[0]) {
        case 0:
        case 1:
            obj->rot.x += 5.0f;
            if (obj->rot.x >= 360.0f) {
                if (obj->work[0] == 1) {
                    obj->work[0] = 2;
                }
                obj->rot.x -= 360.0f;
            }
            D_80110448_YoshisTropicalIslandEndingScene[2]->coords.x =
                sinf(obj->rot.x * D_8010F070_YoshisTropicalIslandEndingScene) * 70.0f * 5.0f + obj->trans.x;
            D_80110448_YoshisTropicalIslandEndingScene[2]->coords.y = obj->trans.y;
            D_80110448_YoshisTropicalIslandEndingScene[2]->coords.z =
                (obj->trans.z - 150.0f) + cosf(obj->rot.x * D_8010F070_YoshisTropicalIslandEndingScene) * 30.0f * 5.0f;
            if (!(obj->work[3] & 1)) {
                func_8004FA90(D_80110440_YoshisTropicalIslandEndingScene, 3.0f, 3.0f, 3.0f);
                func_8004F9F4(D_80110440_YoshisTropicalIslandEndingScene, D_80110448_YoshisTropicalIslandEndingScene[2]->coords.x,
                              D_80110448_YoshisTropicalIslandEndingScene[2]->coords.y - 40.0f,
                              D_80110448_YoshisTropicalIslandEndingScene[2]->coords.z, 3);
            }
            obj->work[3]++;
            break;
        case 2:
            obj->rot.x += 5.0f;
            if (obj->rot.x >= 360.0f) {
                obj->rot.x -= 360.0f;
            }
            D_80110448_YoshisTropicalIslandEndingScene[2]->unk_3C->unk_24 = 0.0f;
            D_80110448_YoshisTropicalIslandEndingScene[2]->unk_3C->unk28 = 0.0f;
            D_80110448_YoshisTropicalIslandEndingScene[2]->unk_3C->unk_2C = sinf(obj->rot.x * D_8010F078_YoshisTropicalIslandEndingScene) * 10.0f;
            break;
    }
}

const f64 D_8010F080_YoshisTropicalIslandEndingScene DTOR_RODATA = M_DTOR;

void func_800FB460_YoshisTropicalIslandEndingScene(omObjData* obj) {
    D_80110448_YoshisTropicalIslandEndingScene[5]->coords.y = 0.0f;
    D_80110448_YoshisTropicalIslandEndingScene[5]->unk_30 =
        sinf(obj->rot.y * D_8010F080_YoshisTropicalIslandEndingScene) * 20.0f + D_8010EF70_YoshisTropicalIslandEndingScene[5].y;
    obj->rot.y += 2.0f;
    if (obj->rot.y >= 360.0f) {
        obj->rot.y -= 360.0f;
    }
}

void func_800FB514_YoshisTropicalIslandEndingScene(omObjData* obj) {
    switch (obj->work[0]) {
        case 0:
            D_80110448_YoshisTropicalIslandEndingScene[6]->unk_30 += 10.0f;
            if (D_80110448_YoshisTropicalIslandEndingScene[6]->unk_30 >= 200.0f) {
                obj->work[0] = 1;
                obj->work[1] = 20;
            }
            break;
        case 1:
            obj->work[1]--;
            if (obj->work[1] == 0) {
                obj->work[0] = 2;
            }
            break;
        case 2:
            D_80110448_YoshisTropicalIslandEndingScene[6]->unk_30 -= 40.0f;
            if (D_80110448_YoshisTropicalIslandEndingScene[6]->unk_30 <= 0.0f) {
                obj->work[0] = 3;
                obj->work[1] = 40;
            }
            break;
        case 3:
            obj->work[1]--;
            if (obj->work[1] == 0) {
                obj->work[0] = 0;
            }
            break;
    }
}

// EF50 model loop: 2.0f hoisted to an FPR, branch layout of the 0xD test (masked 24); calls, constants and strides identical
#ifdef NON_MATCHING
void func_800FB648_YoshisTropicalIslandEndingScene(void) {
    Object* stones[7];
    Vec3f step;
    s32 count = D_8010DC90_YoshisTropicalIslandEndingScene[GwSystem.unk_00];
    f32 radius = D_8010DCFC_YoshisTropicalIslandEndingScene[BOARD];
    omObjData* ring;
    f32 angle;
    f32 x;
    f32 speed;
    f32 scale;
    f32 n;
    s32 i;
    s32 j;
    s32 t;

    func_8004FA90(D_80110440_YoshisTropicalIslandEndingScene, 4.0f, 4.0f, 4.0f);
    for (i = 0; i < count; i++) {
        D_80110448_YoshisTropicalIslandEndingScene[8 + i] = MBModelCreate(0x25, NULL);
        angle = (360 / count) * i * M_DTOR;
        x = sinf(angle) * radius + D_8010DC9C_YoshisTropicalIslandEndingScene[BOARD].x;
        func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[8 + i]->coords, x,
                      D_8010DC9C_YoshisTropicalIslandEndingScene[BOARD].y,
                      cosf(angle) * radius + D_8010DC9C_YoshisTropicalIslandEndingScene[BOARD].z);
        func_800A0D00((Vec3f*)&D_80110448_YoshisTropicalIslandEndingScene[8 + i]->xScale,
                      D_8010DD1C_YoshisTropicalIslandEndingScene[BOARD], D_8010DD1C_YoshisTropicalIslandEndingScene[BOARD],
                      D_8010DD1C_YoshisTropicalIslandEndingScene[BOARD]);
        D_80110400_YoshisTropicalIslandEndingScene[8 + i] = func_80042728(D_80110448_YoshisTropicalIslandEndingScene[8 + i], 2);
    }
    ring = omAddObj(0x1000, 0, 0, -1, func_800FAD64_YoshisTropicalIslandEndingScene);
    D_80110300_YoshisTropicalIslandEndingScene[0] = ring;
    ring->rot.y = 0.0f;
    ring->rot.z = 0.0f;
    ring->trans.x = radius;
    ring->trans.y = count;
    ring->scale.x = D_8010DD1C_YoshisTropicalIslandEndingScene[BOARD];
    ring->work[0] = 0;
    ring->work[3] = 0;
    for (i = 0; i < 7; i++) {
        stones[i] = MBModelCreate(0x75, NULL);
        angle = (i * 51 + 30) * M_DTOR;
        x = sinf(angle) * 270.0f + D_8010DC9C_YoshisTropicalIslandEndingScene[BOARD].x;
        func_800A0D00(&stones[i]->coords, x, D_8010DC9C_YoshisTropicalIslandEndingScene[BOARD].y - 20.0f,
                      cosf(angle) * 270.0f + D_8010DC9C_YoshisTropicalIslandEndingScene[BOARD].z);
        func_80021240(*stones[i]->unk_3C->unk_40);
        func_800211BC(*stones[i]->unk_3C->unk_40, 0xFF);
    }
    LoadBackgroundIndex(0x12);
    func_8004B5DC(D_8010E2D4_YoshisTropicalIslandEndingScene);
    D_80110448_YoshisTropicalIslandEndingScene[0] = MBModelCreate(0x65, D_8010E3C4_YoshisTropicalIslandEndingScene);
    D_80110448_YoshisTropicalIslandEndingScene[0]->coords.x = D_8010E2B0_YoshisTropicalIslandEndingScene[0].x;
    D_80110448_YoshisTropicalIslandEndingScene[0]->coords.y = D_8010E2B0_YoshisTropicalIslandEndingScene[0].y;
    D_80110448_YoshisTropicalIslandEndingScene[0]->coords.z = D_8010E2B0_YoshisTropicalIslandEndingScene[0].z;
    D_80110448_YoshisTropicalIslandEndingScene[1] = MBModelCreate(0x66, D_8010E3C4_YoshisTropicalIslandEndingScene);
    D_80110448_YoshisTropicalIslandEndingScene[1]->coords.x = D_8010E2B0_YoshisTropicalIslandEndingScene[1].x;
    D_80110448_YoshisTropicalIslandEndingScene[1]->coords.y = D_8010E2B0_YoshisTropicalIslandEndingScene[1].y;
    D_80110448_YoshisTropicalIslandEndingScene[1]->coords.z = D_8010E2B0_YoshisTropicalIslandEndingScene[1].z;
    func_8004CCD0(&D_80110448_YoshisTropicalIslandEndingScene[0]->coords, &D_80110448_YoshisTropicalIslandEndingScene[1]->coords,
                  &D_80110448_YoshisTropicalIslandEndingScene[0]->unk_18);
    func_8004CCD0(&D_80110448_YoshisTropicalIslandEndingScene[1]->coords, &D_80110448_YoshisTropicalIslandEndingScene[0]->coords,
                  &D_80110448_YoshisTropicalIslandEndingScene[1]->unk_18);
    func_80072724(0xFF, 0xFF, 0xFF);
    SetFadeInTypeAndTime(2, 0x10);
    PlaySound(0x48);
    HuPrcSleep(0x10);
    speed = -7.5f;
    while (ring->trans.x >= 270.0f) {
        ring->trans.x += speed;
        if (ring->trans.x <= 300.0f) {
            speed += 0.5;
        }
        HuPrcVSleep();
    }
    HuPrcSleep(0x17);
    for (i = 0; i < count; i++) {
        func_800427D4(D_80110400_YoshisTropicalIslandEndingScene[8 + i]);
        D_80110400_YoshisTropicalIslandEndingScene[8 + i] = NULL;
    }
    ring->work[3] = 1;
    ring->scale.z = 0.0f;
    func_80072724(0xFF, 0xFF, 0xFF);
    func_800726AC(0, 0);
    PlaySound(0x59);
    HuPrcSleep(0xF);
    SetFadeInTypeAndTime(0, 0xA);
    HuPrcSleep(0x1E);
    for (scale = ring->scale.x; scale >= 0.0f; scale -= 0.05f) {
        ring->scale.x = scale;
        HuPrcVSleep();
    }
    ring->scale.x = 0.0f;
    for (j = 0; j < 20; j++) {
        for (i = 0; i < 7; i++) {
            func_800211BC(*stones[i]->unk_3C->unk_40, ~((j * 255) / 20));
        }
        HuPrcVSleep();
    }
    for (i = 0; i < 7; i++) {
        MBModelKill(stones[i]);
    }
    func_8004EE14(0, D_800F32A0, 0x14, D_80110448_YoshisTropicalIslandEndingScene[0]);
    HuPrcSleep(0xA);
    HuPrcSleep(func_8004FD68(&D_8010E2D4_YoshisTropicalIslandEndingScene[0], &D_8010E2D4_YoshisTropicalIslandEndingScene[1], 10.0f) / 2);
    omDelObj(D_80110300_YoshisTropicalIslandEndingScene[0]);
    D_80110300_YoshisTropicalIslandEndingScene[0] = NULL;
    step.x = (D_8010E2D4_YoshisTropicalIslandEndingScene[3].x - D_8010E2D4_YoshisTropicalIslandEndingScene[2].x) / 5.0f;
    step.y = (D_8010E2D4_YoshisTropicalIslandEndingScene[3].y - D_8010E2D4_YoshisTropicalIslandEndingScene[2].y) / 5.0f;
    step.z = (D_8010E2D4_YoshisTropicalIslandEndingScene[3].z - D_8010E2D4_YoshisTropicalIslandEndingScene[2].z) / 5.0f;
    for (i = 0; i < 4; i++) {
        if (i == 0) {
            PlaySound(0x5B);
        } else if (i == 1) {
            PlaySound(0x5D);
        }
        for (scale = 0.0f, angle = 45.0f; scale <= D_8010DD1C_YoshisTropicalIslandEndingScene[BOARD]; ) {
            func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[8 + i]->coords,
                          D_8010E2D4_YoshisTropicalIslandEndingScene[3].x - (f32)(i + 1) * step.x,
                          D_8010E2D4_YoshisTropicalIslandEndingScene[3].y - (f32)(i + 1) * step.y,
                          D_8010E2D4_YoshisTropicalIslandEndingScene[3].z - (f32)(i + 1) * step.z);
            func_800A0D00((Vec3f*)&D_80110448_YoshisTropicalIslandEndingScene[8 + i]->xScale, scale, scale, scale);
            D_80110448_YoshisTropicalIslandEndingScene[8 + i]->unk_18.x = sinf(x = angle * M_DTOR);
            D_80110448_YoshisTropicalIslandEndingScene[8 + i]->unk_18.z = cosf(x);
            HuPrcVSleep();
            scale += 0.05;
            angle += 36.0f;
        }
        if (i == 1) {
            func_8004EE14(0, &D_80110448_YoshisTropicalIslandEndingScene[1]->coords, 0x14, D_80110448_YoshisTropicalIslandEndingScene[0]);
            func_80060128(2);
        }
    }
    func_8004F4D4(D_80110448_YoshisTropicalIslandEndingScene[0], 4, 0);
    func_8004F40C(D_80110448_YoshisTropicalIslandEndingScene[0], 0, 2);
    func_8004F4D4(D_80110448_YoshisTropicalIslandEndingScene[1], 1, 2);
    func_8004E3E0(0, &D_8010E2B0_YoshisTropicalIslandEndingScene[0], 0x1E, D_80110448_YoshisTropicalIslandEndingScene[1]);
    HuPrcSleep(5);
    func_800726AC(0, 0xF);
    HuPrcSleep(0x14);
    func_8004A140();
    for (i = 0; i < count; i++) {
        MBModelKill(D_80110448_YoshisTropicalIslandEndingScene[8 + i]);
        D_80110448_YoshisTropicalIslandEndingScene[8 + i] = NULL;
    }
    func_8004FAB8(D_80110440_YoshisTropicalIslandEndingScene);
    D_80110440_YoshisTropicalIslandEndingScene = func_8004F954(0x26, 0x20);
    func_8004FA90(D_80110440_YoshisTropicalIslandEndingScene, 2.0f, 2.0f, 2.0f);
    HuPrcSleep(7);

    /* the players watch the two meet */
    LoadBackgroundIndex(0x18);
    for (i = 0; i < 4; i++) {
        if (GwCommon.boardWork[3] != i) {
            func_80052DC8(i, D_8010E3AC_YoshisTropicalIslandEndingScene[GwPlayer[i].character]);
            func_80052F34(i);
            func_80021B14(*GwPlayer[i].player_obj->unk_3C->unk_40, GwPlayer[i].character, 0x80);
            GwPlayer[i].flags |= 2;
        }
    }
    for (i = 0; i < 3; i++) {
        s16* p = &GwCommon.boardWork[i];
        func_800A0D00(&GwPlayer[*p].player_obj->coords, 600.0f, D_8010F000_YoshisTropicalIslandEndingScene[i].y,
                      D_8010F000_YoshisTropicalIslandEndingScene[i].z);
        func_8004CCD0(&GwPlayer[*p].player_obj->coords, &D_800F32A0->coords, &GwPlayer[*p].player_obj->unk_18);
    }
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[0]->coords, D_8010EF70_YoshisTropicalIslandEndingScene[0].x,
                  D_8010EF70_YoshisTropicalIslandEndingScene[0].y, D_8010EF70_YoshisTropicalIslandEndingScene[0].z);
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[0]->unk_18, 1.0f, 0.0f, 0.0f);
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[1]->coords, 600.0f, D_8010EF70_YoshisTropicalIslandEndingScene[1].y,
                  D_8010EF70_YoshisTropicalIslandEndingScene[1].z);
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[1]->unk_18, -1.0f, 0.0f, 0.0f);
    func_8004CCD0(&D_80110448_YoshisTropicalIslandEndingScene[0]->coords, &D_80110448_YoshisTropicalIslandEndingScene[1]->coords,
                  &D_80110448_YoshisTropicalIslandEndingScene[0]->unk_18);
    SetFadeInTypeAndTime(0, 0x10);
    HuPrcSleep(0x10);
    func_8004E3E0(0, (Vec3f*)&D_8010EF70_YoshisTropicalIslandEndingScene[1], 0x32, D_80110448_YoshisTropicalIslandEndingScene[1]);
    func_8004F4D4(D_80110448_YoshisTropicalIslandEndingScene[1], 2, 0);
    HuPrcSleep(0x64);
    MBMotionSet(D_80110448_YoshisTropicalIslandEndingScene[1], 4, 2);
    func_8004F4D4(D_80110448_YoshisTropicalIslandEndingScene[0], 4, 2);
    MBMotionSet(GwPlayer[GwCommon.boardWork[0]].player_obj, 3, 2);
    func_8004E3E0(0, (Vec3f*)&D_8010F000_YoshisTropicalIslandEndingScene[0], 0x28, GwPlayer[GwCommon.boardWork[0]].player_obj);
    func_8004CCD0(&GwPlayer[GwCommon.boardWork[0]].player_obj->coords, (Vec3f*)&D_8010F000_YoshisTropicalIslandEndingScene[0],
                  &GwPlayer[GwCommon.boardWork[0]].player_obj->unk_18);
    HuPrcSleep(0x1E);
    func_8004F4D4(GwPlayer[GwCommon.boardWork[0]].player_obj, 4, 0);
    func_8004F40C(GwPlayer[GwCommon.boardWork[0]].player_obj, 0, 2);
    func_8004EE14(0, D_800F32A0, 0xF, GwPlayer[GwCommon.boardWork[0]].player_obj);
    for (i = 0; i < 5; i++) {
        func_8004F9F4(D_80110440_YoshisTropicalIslandEndingScene, GwPlayer[GwCommon.boardWork[0]].player_obj->coords.x - 20.0f,
                      GwPlayer[GwCommon.boardWork[0]].player_obj->coords.y - 50.0f,
                      GwPlayer[GwCommon.boardWork[0]].player_obj->coords.z + 100.0f, 1);
        HuPrcSleep(1);
    }
    HuPrcSleep(5);
    func_8004EE14(0, &GwPlayer[GwCommon.boardWork[0]].player_obj->coords, 0xA, D_80110448_YoshisTropicalIslandEndingScene[0]);
    func_8004EE14(0, &GwPlayer[GwCommon.boardWork[0]].player_obj->coords, 0xA, D_80110448_YoshisTropicalIslandEndingScene[1]);
    HuPrcSleep(0x14);
    func_8004EE14(0, D_800F32A0, 0x28, D_80110448_YoshisTropicalIslandEndingScene[0]);
    func_8004EE14(0, D_800F32A0, 0x28, D_80110448_YoshisTropicalIslandEndingScene[1]);
    func_8004F4D4(GwPlayer[GwCommon.boardWork[0]].player_obj, 1, 2);
    func_8004E3E0(0, (Vec3f*)&D_8010EFC4_YoshisTropicalIslandEndingScene[0], 0x14, GwPlayer[GwCommon.boardWork[0]].player_obj);
    HuPrcSleep(0x14);
    func_8004F4D4(GwPlayer[GwCommon.boardWork[0]].player_obj, 0, 2);
    MBMotionSet(GwPlayer[GwCommon.boardWork[1]].player_obj, 3, 2);
    func_8004E3E0(0, (Vec3f*)&D_8010F000_YoshisTropicalIslandEndingScene[1], 0x28, GwPlayer[GwCommon.boardWork[1]].player_obj);
    func_8004CCD0(&GwPlayer[GwCommon.boardWork[1]].player_obj->coords, (Vec3f*)&D_8010F000_YoshisTropicalIslandEndingScene[1],
                  &GwPlayer[GwCommon.boardWork[1]].player_obj->unk_18);
    HuPrcSleep(0x14);
    func_8004F4D4(GwPlayer[GwCommon.boardWork[1]].player_obj, 4, 0);
    func_8004EE14(0, D_800F32A0, 0x14, GwPlayer[GwCommon.boardWork[1]].player_obj);
    for (i = 0; i < 10; i++) {
        func_8004F9F4(D_80110440_YoshisTropicalIslandEndingScene, GwPlayer[GwCommon.boardWork[1]].player_obj->coords.x - 20.0f,
                      GwPlayer[GwCommon.boardWork[1]].player_obj->coords.y - 50.0f,
                      GwPlayer[GwCommon.boardWork[1]].player_obj->coords.z + 100.0f, 1);
        HuPrcSleep(1);
    }
    MBMotionSet(GwPlayer[GwCommon.boardWork[2]].player_obj, 1, 2);
    func_8004E3E0(0, (Vec3f*)&D_8010EFC4_YoshisTropicalIslandEndingScene[2], 0x14, GwPlayer[GwCommon.boardWork[2]].player_obj);
    func_8004CCD0(&GwPlayer[GwCommon.boardWork[2]].player_obj->coords, (Vec3f*)&D_8010EFC4_YoshisTropicalIslandEndingScene[2],
                  &GwPlayer[GwCommon.boardWork[2]].player_obj->unk_18);
    func_8004EE14(0, D_800F32A0, 0x14, D_80110448_YoshisTropicalIslandEndingScene[1]);
    func_8004F4D4(GwPlayer[GwCommon.boardWork[1]].player_obj, 1, 2);
    func_8004E3E0(0, (Vec3f*)&D_8010EFC4_YoshisTropicalIslandEndingScene[1], 0x14, GwPlayer[GwCommon.boardWork[1]].player_obj);
    HuPrcSleep(0x14);
    func_8004F4D4(GwPlayer[GwCommon.boardWork[2]].player_obj, 0, 2);
    func_8004EE14(0, D_800F32A0, 0x14, GwPlayer[GwCommon.boardWork[2]].player_obj);
    func_8004F4D4(GwPlayer[GwCommon.boardWork[1]].player_obj, 0, 2);
    func_8004EE14(0, D_800F32A0, 0x14, D_80110448_YoshisTropicalIslandEndingScene[0]);
    HuPrcSleep(0x14);
    func_800726AC(1, 0x10);
    HuPrcSleep(0x10);
    func_8004A140();
    for (i = 0; i < 4; i++) {
        func_80052FD4(i);
    }
    MBMotionSet(D_80110448_YoshisTropicalIslandEndingScene[0], 0, 2);
    MBMotionSet(D_80110448_YoshisTropicalIslandEndingScene[1], 0, 2);
    func_8004FAB8(D_80110440_YoshisTropicalIslandEndingScene);
    HuPrcSleep(5);

    /* the winner rides off */
    LoadBackgroundIndex(0x12);
    func_80052DC8(GwCommon.boardWork[3], D_8010E3AC_YoshisTropicalIslandEndingScene[GwPlayer[GwCommon.boardWork[3]].character]);
    func_80052F34(GwCommon.boardWork[3]);
    GwPlayer[GwCommon.boardWork[3]].flags |= 2;
    func_800A0D00(&GwPlayer[GwCommon.boardWork[3]].player_obj->coords, D_8010E2B0_YoshisTropicalIslandEndingScene[1].x,
                  D_8010E2B0_YoshisTropicalIslandEndingScene[1].y, D_8010E2B0_YoshisTropicalIslandEndingScene[1].z);
    func_8004CCD0(&GwPlayer[GwCommon.boardWork[3]].player_obj->coords, &D_8010E2B0_YoshisTropicalIslandEndingScene[0],
                  &GwPlayer[GwCommon.boardWork[3]].player_obj->unk_18);
    step.x = (D_8010E2D4_YoshisTropicalIslandEndingScene[3].x - D_8010E2D4_YoshisTropicalIslandEndingScene[2].x) / 5.0f;
    step.y = (D_8010E2D4_YoshisTropicalIslandEndingScene[3].y - D_8010E2D4_YoshisTropicalIslandEndingScene[2].y) / 5.0f;
    step.z = (D_8010E2D4_YoshisTropicalIslandEndingScene[3].z - D_8010E2D4_YoshisTropicalIslandEndingScene[2].z) / 5.0f;
    for (i = 0; i < 4; i++) {
        D_80110448_YoshisTropicalIslandEndingScene[8 + i] = MBModelCreate(0x25, NULL);
        for (scale = 0.0f, angle = 45.0f; scale <= D_8010DD1C_YoshisTropicalIslandEndingScene[BOARD]; ) {
            func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[8 + i]->coords,
                          D_8010E2D4_YoshisTropicalIslandEndingScene[3].x - (f32)(i + 1) * step.x,
                          D_8010E2D4_YoshisTropicalIslandEndingScene[3].y - (f32)(i + 1) * step.y,
                          D_8010E2D4_YoshisTropicalIslandEndingScene[3].z - (f32)(i + 1) * step.z);
            func_800A0D00((Vec3f*)&D_80110448_YoshisTropicalIslandEndingScene[8 + i]->xScale, scale, scale, scale);
            D_80110448_YoshisTropicalIslandEndingScene[8 + i]->unk_18.x = sinf(x = angle * M_DTOR);
            D_80110448_YoshisTropicalIslandEndingScene[8 + i]->unk_18.z = cosf(x);
            scale += 0.05;
            angle += 36.0f;
        }
    }
    D_80110448_YoshisTropicalIslandEndingScene[4] = MBModelCreate(0x5C, NULL);
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[4]->coords, D_8010E304_YoshisTropicalIslandEndingScene[0].x,
                  D_8010E304_YoshisTropicalIslandEndingScene[0].y, D_8010E304_YoshisTropicalIslandEndingScene[0].z);
    SetFadeInTypeAndTime(1, 0x10);
    MBMotionSet(GwPlayer[GwCommon.boardWork[3]].player_obj, 1, 2);
    func_8004E3E0(0, &D_8010E2B0_YoshisTropicalIslandEndingScene[2], 0x28, GwPlayer[GwCommon.boardWork[3]].player_obj);
    HuPrcSleep(0xC);
    func_8004E3E0(0, &D_8010E304_YoshisTropicalIslandEndingScene[1], 0x3C, D_80110448_YoshisTropicalIslandEndingScene[4]);
    HuPrcSleep(0x1F);
    MBModelDispOff(GwPlayer[GwCommon.boardWork[3]].player_obj);
    HuPrcSleep(0x10);
    func_800726AC(1, 0x10);
    HuPrcSleep(0x10);
    func_8004A140();
    func_800F6B54_YoshisTropicalIslandEndingScene();
    HuPrcSleep(5);

    /* everyone at the finale */
    LoadBackgroundIndex(0x18);
    for (i = 0; i < 4; i++) {
        func_80052DC8(i, D_8010E43C_YoshisTropicalIslandEndingScene[GwPlayer[i].character]);
        func_80052F34(i);
        func_80021B14(*GwPlayer[i].player_obj->unk_3C->unk_40, GwPlayer[i].character, 0x80);
        GwPlayer[i].flags |= 2;
    }
    for (i = 0; i < 4; i++) {
        func_800A0D00(&GwPlayer[GwCommon.boardWork[i]].player_obj->coords, D_8010EFC4_YoshisTropicalIslandEndingScene[i].x,
                      D_8010EFC4_YoshisTropicalIslandEndingScene[i].y, D_8010EFC4_YoshisTropicalIslandEndingScene[i].z);
        if (i == 3) {
            GwPlayer[GwCommon.boardWork[3]].player_obj->unk_18.x = 1.0f;
            GwPlayer[GwCommon.boardWork[3]].player_obj->unk_18.z = 0.0f;
            GwPlayer[GwCommon.boardWork[3]].player_obj->unk_3C->unk_24 = 90.0f;
            GwPlayer[GwCommon.boardWork[3]].player_obj->unk_0A |= 1;
            GwPlayer[GwCommon.boardWork[3]].player_obj->unk_30 = 50.0f;
        } else {
            func_8004CCD0(&GwPlayer[GwCommon.boardWork[i]].player_obj->coords, (Vec3f*)&D_8010EFC4_YoshisTropicalIslandEndingScene[3],
                          &GwPlayer[GwCommon.boardWork[i]].player_obj->unk_18);
        }
    }
    for (i = 0; D_8010EF50_YoshisTropicalIslandEndingScene[i] != -1; ) {
        const s32* id = &D_8010EF50_YoshisTropicalIslandEndingScene[i];
        Object** m = &D_80110448_YoshisTropicalIslandEndingScene[i];

        *m = MBModelCreate(*id, NULL);
        func_800A0D00(&(*m)->coords, D_8010EF70_YoshisTropicalIslandEndingScene[i].x,
                      D_8010EF70_YoshisTropicalIslandEndingScene[i].y, D_8010EF70_YoshisTropicalIslandEndingScene[i].z);
        func_8004CCD0(&(*m)->coords, (Vec3f*)&D_8010EFC4_YoshisTropicalIslandEndingScene[3], &(*m)->unk_18);
        func_80025B34(*(*m)->unk_3C->unk_40);
        if (*id == 0xD) {
            func_800A0D00((Vec3f*)&(*m)->xScale, 2.0f, 2.0f, 2.0f);
            i++;
            MBModelDispOff(*m);
        } else {
            i++;
        }
    }
    func_8004F140(*D_80110448_YoshisTropicalIslandEndingScene[4]->unk_3C->unk_40);
    D_80110300_YoshisTropicalIslandEndingScene[5] = omAddObj(0x1000, 0, 0, -1, func_800FB460_YoshisTropicalIslandEndingScene);
    D_80110300_YoshisTropicalIslandEndingScene[5]->rot.y = 0.0f;
    D_80110300_YoshisTropicalIslandEndingScene[2] = omAddObj(0x1000, 0, 0, -1, func_800FB1E4_YoshisTropicalIslandEndingScene);
    D_80110300_YoshisTropicalIslandEndingScene[2]->trans.x = D_8010EF70_YoshisTropicalIslandEndingScene[2].x;
    D_80110300_YoshisTropicalIslandEndingScene[2]->trans.y = D_8010EF70_YoshisTropicalIslandEndingScene[2].y;
    D_80110300_YoshisTropicalIslandEndingScene[2]->trans.z = D_8010EF70_YoshisTropicalIslandEndingScene[2].z;
    D_80110300_YoshisTropicalIslandEndingScene[2]->rot.x = 360.0f;
    D_80110300_YoshisTropicalIslandEndingScene[2]->work[0] = 2;
    D_80110448_YoshisTropicalIslandEndingScene[10] = MBModelCreate(0x5C, NULL);
    D_80110448_YoshisTropicalIslandEndingScene[10]->unk_0A |= 1;
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[10]->coords, D_8010EFC4_YoshisTropicalIslandEndingScene[3].x,
                  D_8010EFC4_YoshisTropicalIslandEndingScene[3].y, D_8010EFC4_YoshisTropicalIslandEndingScene[3].z);
    D_80110448_YoshisTropicalIslandEndingScene[10]->unk_18.x = 1.0f;
    D_80110448_YoshisTropicalIslandEndingScene[10]->unk_18.z = 0.0f;
    func_80025930(*D_80110448_YoshisTropicalIslandEndingScene[10]->unk_3C->unk_40, 0x20000, 0x20000);
    func_80025AD4(*D_80110448_YoshisTropicalIslandEndingScene[10]->unk_3C->unk_40);
    D_801102B8_YoshisTropicalIslandEndingScene[10] = LoadFormFile(0xA00B1, 0x2AD);
    func_80025930((s16)D_801102B8_YoshisTropicalIslandEndingScene[10], 0x20000, 0x20000);
    func_80025AD4((s16)D_801102B8_YoshisTropicalIslandEndingScene[10]);
    func_80026040(*D_80110448_YoshisTropicalIslandEndingScene[10]->unk_3C->unk_40);
    D_80110300_YoshisTropicalIslandEndingScene[10] = omAddObj(0x1000, 0, 0, -1, func_800FAD10_YoshisTropicalIslandEndingScene);
    D_80110300_YoshisTropicalIslandEndingScene[10]->trans.x = 0.0f;
    SetFadeInTypeAndTime(1, 0x10);
    HuPrcSleep(0x1A);
    func_8004E3E0(0, (Vec3f*)&D_8010EFC4_YoshisTropicalIslandEndingScene[4], 0x3C, D_80110448_YoshisTropicalIslandEndingScene[10]);
    func_8004E3E0(0, (Vec3f*)&D_8010EFC4_YoshisTropicalIslandEndingScene[4], 0x3C, GwPlayer[GwCommon.boardWork[3]].player_obj);
    for (t = 0; t < 0x3C; t++) {
        for (j = 0; j < 3; j++) {
            func_8004CCD0(&GwPlayer[GwCommon.boardWork[j]].player_obj->coords, &D_80110448_YoshisTropicalIslandEndingScene[10]->coords,
                          &GwPlayer[GwCommon.boardWork[j]].player_obj->unk_18);
        }
        for (j = 0; D_8010EF50_YoshisTropicalIslandEndingScene[j] != -1; j++) {
            if (D_8010EF50_YoshisTropicalIslandEndingScene[j] != 0x40) {
                func_8004CCD0(&D_80110448_YoshisTropicalIslandEndingScene[j]->coords, &D_80110448_YoshisTropicalIslandEndingScene[10]->coords,
                              &D_80110448_YoshisTropicalIslandEndingScene[j]->unk_18);
            }
        }
        HuPrcVSleep();
        if (t == 0x28) {
            func_8004CCD0(&D_80110448_YoshisTropicalIslandEndingScene[2]->coords, &D_800F32A0->coords,
                          &D_80110448_YoshisTropicalIslandEndingScene[2]->unk_18);
            func_8004E3E0(0, (Vec3f*)&D_8010F030_YoshisTropicalIslandEndingScene, 0x3C, D_80110448_YoshisTropicalIslandEndingScene[2]);
        }
    }
    MBModelKill(D_80110448_YoshisTropicalIslandEndingScene[10]);
    D_80110448_YoshisTropicalIslandEndingScene[10] = NULL;
    omDelObj(D_80110300_YoshisTropicalIslandEndingScene[10]);
    D_80110300_YoshisTropicalIslandEndingScene[10] = NULL;
    func_8002456C((s16)D_801102B8_YoshisTropicalIslandEndingScene[10]);
    D_801102B8_YoshisTropicalIslandEndingScene[10] = -1;
    func_80052FD4(GwCommon.boardWork[3]);
    for (i = 0; i < 3; i++) {
        func_8004EE14(GwCommon.boardWork[i], (Vec3f*)&D_8010F024_YoshisTropicalIslandEndingScene, 0x1E, NULL);
    }
    for (i = 0; D_8010EF50_YoshisTropicalIslandEndingScene[i] != -1; i++) {
        if ((i != 2) & (i != 6)) {
            func_8004EE14(0, (Vec3f*)&D_8010F024_YoshisTropicalIslandEndingScene, 0x1E, D_80110448_YoshisTropicalIslandEndingScene[i]);
        }
    }
    HuPrcSleep(5);
    D_80110400_YoshisTropicalIslandEndingScene[2] = func_80042728(D_80110448_YoshisTropicalIslandEndingScene[2], 1);
    HuPrcSleep(0x23);
    HuPrcSleep(0x14);
    D_80110448_YoshisTropicalIslandEndingScene[6]->unk_30 = 800.0f;
    func_8004F00C(D_80110448_YoshisTropicalIslandEndingScene[6], 10.0f, -2.0f);
    MBModelDispOn(D_80110448_YoshisTropicalIslandEndingScene[6]);
    func_8004CCD0(&D_80110448_YoshisTropicalIslandEndingScene[6]->coords, &D_800F32A0->coords,
                  &D_80110448_YoshisTropicalIslandEndingScene[6]->unk_18);
    func_8004F4D4(GwPlayer[GwCommon.boardWork[0]].player_obj, 1, 2);
    func_8004E3E0(0, (Vec3f*)&D_8010F024_YoshisTropicalIslandEndingScene, 0x28, GwPlayer[GwCommon.boardWork[0]].player_obj);
    for (j = 0; j < 0x28; j++) {
        HuPrcVSleep();
    }
    D_80110300_YoshisTropicalIslandEndingScene[6] = omAddObj(0x1000, 0, 0, -1, func_800FB514_YoshisTropicalIslandEndingScene);
    D_80110300_YoshisTropicalIslandEndingScene[6]->work[0] = 3;
    D_80110300_YoshisTropicalIslandEndingScene[6]->work[1] = 20;
    func_8004F4D4(GwPlayer[GwCommon.boardWork[0]].player_obj, 0, 2);
    HuPrcSleep(0xA);
    func_8004F4D4(GwPlayer[GwCommon.boardWork[0]].player_obj, 2, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/2643A0", func_800FB648_YoshisTropicalIslandEndingScene);
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/2643A0", D_8010F0B8_YoshisTropicalIslandEndingScene);
/* INCLUDE_RODATA leaves the assembler in .text while GCC believes it is still in .rodata: return there
 * for D_8010F114 below */
asm(".section .rodata");
/* the asm names the tables' inner labels */
asm(".globl D_8010E2BC_YoshisTropicalIslandEndingScene\nD_8010E2BC_YoshisTropicalIslandEndingScene = D_8010E2B0_YoshisTropicalIslandEndingScene + 0xC\n"
    ".globl D_8010E2C8_YoshisTropicalIslandEndingScene\nD_8010E2C8_YoshisTropicalIslandEndingScene = D_8010E2B0_YoshisTropicalIslandEndingScene + 0x18\n"
    ".globl D_8010E2F8_YoshisTropicalIslandEndingScene\nD_8010E2F8_YoshisTropicalIslandEndingScene = D_8010E2D4_YoshisTropicalIslandEndingScene + 0x24\n"
    ".globl D_8010EF74_YoshisTropicalIslandEndingScene\nD_8010EF74_YoshisTropicalIslandEndingScene = D_8010EF70_YoshisTropicalIslandEndingScene + 0x4\n"
    ".globl D_8010EF78_YoshisTropicalIslandEndingScene\nD_8010EF78_YoshisTropicalIslandEndingScene = D_8010EF70_YoshisTropicalIslandEndingScene + 0x8\n"
    ".globl D_8010EF88_YoshisTropicalIslandEndingScene\nD_8010EF88_YoshisTropicalIslandEndingScene = D_8010EF70_YoshisTropicalIslandEndingScene + 0x18\n"
    ".globl D_8010EFC8_YoshisTropicalIslandEndingScene\nD_8010EFC8_YoshisTropicalIslandEndingScene = D_8010EFC4_YoshisTropicalIslandEndingScene + 0x4\n"
    ".globl D_8010EFCC_YoshisTropicalIslandEndingScene\nD_8010EFCC_YoshisTropicalIslandEndingScene = D_8010EFC4_YoshisTropicalIslandEndingScene + 0x8\n"
    ".globl D_8010EFD0_YoshisTropicalIslandEndingScene\nD_8010EFD0_YoshisTropicalIslandEndingScene = D_8010EFC4_YoshisTropicalIslandEndingScene + 0xC\n"
    ".globl D_8010EFDC_YoshisTropicalIslandEndingScene\nD_8010EFDC_YoshisTropicalIslandEndingScene = D_8010EFC4_YoshisTropicalIslandEndingScene + 0x18\n"
    ".globl D_8010EFE8_YoshisTropicalIslandEndingScene\nD_8010EFE8_YoshisTropicalIslandEndingScene = D_8010EFC4_YoshisTropicalIslandEndingScene + 0x24\n"
    ".globl D_8010F004_YoshisTropicalIslandEndingScene\nD_8010F004_YoshisTropicalIslandEndingScene = D_8010F000_YoshisTropicalIslandEndingScene + 0x4\n"
    ".globl D_8010F008_YoshisTropicalIslandEndingScene\nD_8010F008_YoshisTropicalIslandEndingScene = D_8010F000_YoshisTropicalIslandEndingScene + 0x8\n"
    ".globl D_8010F00C_YoshisTropicalIslandEndingScene\nD_8010F00C_YoshisTropicalIslandEndingScene = D_8010F000_YoshisTropicalIslandEndingScene + 0xC\n");
#endif

#ifdef NON_MATCHING
/* unreferenced */
const Vec3f D_8010F0C0_YoshisTropicalIslandEndingScene[7] = {
    { 0.0f, 410.0f, 1210.0f },   { -142.5f, 0.0f, 1485.0f }, { -345.0f, 0.0f, 1532.5f }, { -150.0f, 130.0f, 1410.0f },
    { 135.0f, 0.0f, 1610.0f },   { -240.0f, 0.0f, 1485.0f }, { -100.0f, 0.0f, 1387.5f },
};
#endif
/* read by 266C80 (2643A0.h) */
const Vec3f D_8010F114_YoshisTropicalIslandEndingScene[4] = {
    { 0.0f, 0.0f, 1475.0f },
    { 212.5f, 0.0f, 1485.0f },
    { 312.5f, 0.0f, 1635.0f },
    { 0.0f, 820.0f, 1135.0f },
};
/* Bridge until 266C80 is C: its asm names the table's .y/.z columns by splat's labels. Remove when
 * func_8010151C reads D_8010F114_..[i].y/.z. */
asm(".globl D_8010F118_YoshisTropicalIslandEndingScene\n"
    "D_8010F118_YoshisTropicalIslandEndingScene = D_8010F114_YoshisTropicalIslandEndingScene + 4\n"
    ".globl D_8010F11C_YoshisTropicalIslandEndingScene\n"
    "D_8010F11C_YoshisTropicalIslandEndingScene = D_8010F114_YoshisTropicalIslandEndingScene + 8\n");
