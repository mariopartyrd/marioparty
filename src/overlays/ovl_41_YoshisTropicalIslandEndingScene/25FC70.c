#include "ending.h"

#define ENDING_BOARD D_801102B0_YoshisTropicalIslandEndingScene
/* ending.h: s32[2]; retail only ever uses it as a scalar (see the fork report) */

void func_8004F548(void);
void func_8004FB14(void);
void func_8004FBB4(void);
void func_8004FFA8(void);
void func_800427E4(void);
s32 func_8004F628(s32, u16, s16, s16);
void func_8004F584(s32);
void func_8004F7C0(s32, f32, f32);

void func_800F6658_YoshisTropicalIslandEndingScene(omObjData* arg0);
void func_800F671C_YoshisTropicalIslandEndingScene(void);
void func_800F67AC_YoshisTropicalIslandEndingScene(void);
void func_800F67EC_YoshisTropicalIslandEndingScene(void);
void func_800F697C_YoshisTropicalIslandEndingScene(omObjData* arg0);
void func_800F69B8_YoshisTropicalIslandEndingScene(omObjData* arg0);
void func_800F69EC_YoshisTropicalIslandEndingScene(omObjData* arg0);
void func_800F6A4C_YoshisTropicalIslandEndingScene(omObjData* arg0);
void func_800F6A90_YoshisTropicalIslandEndingScene(void);
void func_800F6C80_YoshisTropicalIslandEndingScene(void);
void func_800F6D18_YoshisTropicalIslandEndingScene(void);

/* .data 0x8010DC90-0x8010DDDF: shared by the scenes (ending.h) */
/* per-game-mode counts (GwSystem.unk_00); splat's D_8010DC98 is [2] */
s32 D_8010DC90_YoshisTropicalIslandEndingScene[3] = { 3, 5, 7 };
Vec3f D_8010DC9C_YoshisTropicalIslandEndingScene[8] = {
    { 0.0f, 250.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 89.0f, 0.0f, -87.0f }, { 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 250.0f, 0.0f },
};
f32 D_8010DCFC_YoshisTropicalIslandEndingScene[8] = {
    1000.0f, 750.0f, 1000.0f, 750.0f, 750.0f, 750.0f, 750.0f, 750.0f,
};
f32 D_8010DD1C_YoshisTropicalIslandEndingScene[8] = {
    3.0f, 3.0f, 1.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f,
};
s32 D_8010DD3C_YoshisTropicalIslandEndingScene[8] = {
    5, 15, 25, 37, 45, 54, 65, 75,
};
/* MBModelCreate lists (count, file ids), referenced from 262590's rodata D_8010EF18 */
s32 D_8010DD5C_YoshisTropicalIslandEndingScene[4] = { 3, 0x000A0072, 0x000A0073, 0x000A0074 };
s32 D_8010DD6C_YoshisTropicalIslandEndingScene[4] = { 3, 0x00070000, 0x00070002, 0x00070003 };
void (*D_8010DD7C_YoshisTropicalIslandEndingScene[8])(void) = {
    func_800F8848_YoshisTropicalIslandEndingScene,
    func_800FA580_YoshisTropicalIslandEndingScene,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    func_8010D06C_YoshisTropicalIslandEndingScene,
};
void (*D_8010DD9C_YoshisTropicalIslandEndingScene[8])(void) = {
    func_800F8550_YoshisTropicalIslandEndingScene,
    func_800F96E4_YoshisTropicalIslandEndingScene,
    func_800FB648_YoshisTropicalIslandEndingScene,
    func_800FD5F0_YoshisTropicalIslandEndingScene,
    func_8010329C_YoshisTropicalIslandEndingScene,
    func_80105360_YoshisTropicalIslandEndingScene,
    func_80109294_YoshisTropicalIslandEndingScene,
    func_8010CC94_YoshisTropicalIslandEndingScene,
};
s32 D_8010DDBC_YoshisTropicalIslandEndingScene[8] = {
    0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18,
};

/* .bss used only here */
extern s32 D_8010F840_YoshisTropicalIslandEndingScene[2]; /* func_8004F628 handles */
extern omObjData* D_8010F848_YoshisTropicalIslandEndingScene;
extern s32 D_8010F84C_YoshisTropicalIslandEndingScene;

void func_800F65E0_YoshisTropicalIslandEndingScene(void) {
    ENDING_BOARD = GwSystem.curBoardIndex;
    omInitObjMan(0x64, 0x64);
    func_800F6C80_YoshisTropicalIslandEndingScene();
    func_800F6A90_YoshisTropicalIslandEndingScene();
    omAddPrcObj(func_800F67EC_YoshisTropicalIslandEndingScene, 0x300, 0x2000, 0);
    omAddObj(0x1000, 0, 0, -1, func_800F6A4C_YoshisTropicalIslandEndingScene);
}

void func_800F6658_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    if (arg0->work[0] == 0) {
        arg0->trans.x += 20.0f;
        if (arg0->trans.x >= 360.0f) {
            arg0->trans.x -= 360.0f;
        }
    } else {
        arg0->work[0]--;
    }
    func_8004F7C0(D_8010F840_YoshisTropicalIslandEndingScene[1], 1.0f,
                  (sinf(arg0->trans.x * (M_PI / 180.0)) * 0.2f) + 0.9f);
}

void func_800F671C_YoshisTropicalIslandEndingScene(void) {
    omObjData* obj;

    D_8010F840_YoshisTropicalIslandEndingScene[0] = func_8004F628(0xA0011, 5, 0x4E, 0xCA);
    D_8010F840_YoshisTropicalIslandEndingScene[1] = func_8004F628(0xA0012, 4, 0xD8, 0xC9);
    obj = D_8010F848_YoshisTropicalIslandEndingScene = omAddObj(0x1000, 0, 0, -1, func_800F6658_YoshisTropicalIslandEndingScene);
    obj->trans.x = 0.0f;
    obj->work[0] = 0x3C;
}

void func_800F67AC_YoshisTropicalIslandEndingScene(void) {
    func_8004F584(D_8010F840_YoshisTropicalIslandEndingScene[0]);
    func_8004F584(D_8010F840_YoshisTropicalIslandEndingScene[1]);
    omDelObj(D_8010F848_YoshisTropicalIslandEndingScene);
}

void func_800F67EC_YoshisTropicalIslandEndingScene(void) {
    if (D_8010DD7C_YoshisTropicalIslandEndingScene[ENDING_BOARD] != NULL) {
        D_8010DD7C_YoshisTropicalIslandEndingScene[ENDING_BOARD]();
    }
    D_8010DD9C_YoshisTropicalIslandEndingScene[ENDING_BOARD]();
    {
        s32 delays[6] = { 45, 25, 30, 45, 45, 30 };

        HuPrcSleep(delays[GwPlayer[GwCommon.boardWork[0]].character]);
        func_80060468(0x99, GwPlayer[GwCommon.boardWork[0]].character);
        func_8004F504((ENDING_BOARD == 0) ? D_80110448_YoshisTropicalIslandEndingScene[0]
                                                                     : GwPlayer[GwCommon.boardWork[0]].player_obj);
    }
    func_800F671C_YoshisTropicalIslandEndingScene();
    HuPrcSleep(15);
    func_80060128(3);
    func_8004FFA8();
    SetBoardFeatureFlag(D_8010DDBC_YoshisTropicalIslandEndingScene[ENDING_BOARD]);
    D_800F5144 = 1;
    while (1) {
        HuPrcVSleep();
    }
}


void func_800F697C_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    func_8004FBB4();
    func_8004F2EC();
    func_8004F5F0();
    omOvlGotoEx(0x64, 0, 0x1094);
}

void func_800F69B8_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    if (++D_8010F84C_YoshisTropicalIslandEndingScene >= 5) {
        arg0->func_ptr = func_800F697C_YoshisTropicalIslandEndingScene;
    }
}

void func_800F69EC_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    if (func_80072718() == 0) {
        func_800F6D18_YoshisTropicalIslandEndingScene();
        func_800F6B54_YoshisTropicalIslandEndingScene();
        func_800427E4();
        func_800F67AC_YoshisTropicalIslandEndingScene();
        D_8010F84C_YoshisTropicalIslandEndingScene = 0;
        arg0->func_ptr = func_800F69B8_YoshisTropicalIslandEndingScene;
    }
}

void func_800F6A4C_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    if (D_800F5144 != 0) {
        func_800726AC(0, 0x14);
        arg0->func_ptr = func_800F69EC_YoshisTropicalIslandEndingScene;
    }
}

void func_800F6A90_YoshisTropicalIslandEndingScene(void) {
    s32 i;

    MBModelInit();
    func_80053020();
    func_8004FB14();
    func_8004F2AC();
    func_8004F548();
    func_8004F8DC();
    D_80110440_YoshisTropicalIslandEndingScene = func_8004F954(0x2A, 0x20);
    func_8004FA90(D_80110440_YoshisTropicalIslandEndingScene, 12.0f, 12.0f, 12.0f);
    for (i = 0; i < 16; i++) {
        D_801102B8_YoshisTropicalIslandEndingScene[i] = -1;
        D_80110300_YoshisTropicalIslandEndingScene[i] = NULL;
        D_80110448_YoshisTropicalIslandEndingScene[i] = NULL;
        D_80110400_YoshisTropicalIslandEndingScene[i] = NULL;
    }
}

void func_800F6B54_YoshisTropicalIslandEndingScene(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_80052FD4(i);
    }
    for (i = 0; i < 16; i++) {
        if (D_801102B8_YoshisTropicalIslandEndingScene[i] != -1) {
            func_8002456C((s16)D_801102B8_YoshisTropicalIslandEndingScene[i]);
            D_801102B8_YoshisTropicalIslandEndingScene[i] = -1;
        }
        if (D_80110300_YoshisTropicalIslandEndingScene[i] != NULL) {
            omDelObj(D_80110300_YoshisTropicalIslandEndingScene[i]);
            D_80110300_YoshisTropicalIslandEndingScene[i] = NULL;
        }
        if (D_80110448_YoshisTropicalIslandEndingScene[i] != NULL) {
            MBModelKill(D_80110448_YoshisTropicalIslandEndingScene[i]);
            D_80110448_YoshisTropicalIslandEndingScene[i] = NULL;
        }
        if (D_80110400_YoshisTropicalIslandEndingScene[i] != NULL) {
            func_800427D4(D_80110400_YoshisTropicalIslandEndingScene[i]);
            D_80110400_YoshisTropicalIslandEndingScene[i] = NULL;
        }
    }
    func_8004F1D0();
}

void func_800F6C80_YoshisTropicalIslandEndingScene(void) {
    func_800178A0(1);
    func_80017660(0, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    LoadBackgroundData(D_FE2310);
}

void func_800F6D18_YoshisTropicalIslandEndingScene(void) {
    func_8004A140();
    func_80049F0C();
}
