#include "ovl62b.h"

extern Vec3f D_800FD6B0_BoardIntro[2]; /* camera path: start, end */
extern Vec3f D_800FD6C8_BoardIntro[2]; /* positions of models 0x66 and 0x65 */
extern Vec3f D_800FD6E0_BoardIntro;
extern Vec3f D_800FD6EC_BoardIntro;
extern Vec3f D_800FD6F8_BoardIntro; /* centre of the star ring */
extern s32 D_800FD704_BoardIntro[]; /* MBModelCreate motion list: count, file ids */

/* .data */

Vec3f D_800FD6B0_BoardIntro[2] = {
    { -220.0f, 0.0f, -65.0f },
    { -1303.0f, 0.0f, 579.0f },
};

Vec3f D_800FD6C8_BoardIntro[2] = {
    { -500.0f, 0.0f, -87.0f },
    { 89.0f, 0.0f, -87.0f },
};

Vec3f D_800FD6E0_BoardIntro = { -1750.0f, 0.0f, -5000.0f };

Vec3f D_800FD6EC_BoardIntro = { -650.0f, 0.0f, 350.0f };

Vec3f D_800FD6F8_BoardIntro = { 89.0f, 0.0f, -87.0f };

s32 D_800FD704_BoardIntro[5] = {
    4, 0xA0072, 0xA0073, 0xA0074,
    0xA00B6,
};

void func_800F9920_BoardIntro(void) {
    Object* stars[7];
    f32 angle;
    f32 x;
    s32 i;

    LoadBackgroundIndex(0x12);
    HuPrcSleep(2);
    func_8004B5DC(&D_800FD6B0_BoardIntro[0]);
    MDL88_0 = MBModelCreate(0x66, NULL);
    MDL88_1 = MBModelCreate(0x65, NULL);
    MDL88_0->coords.x = D_800FD6C8_BoardIntro[0].x;
    MDL88_0->coords.y = D_800FD6C8_BoardIntro[0].y;
    MDL88_0->coords.z = D_800FD6C8_BoardIntro[0].z;
    MDL88_1->coords.x = D_800FD6C8_BoardIntro[1].x;
    MDL88_1->coords.y = D_800FD6C8_BoardIntro[1].y;
    MDL88_1->coords.z = D_800FD6C8_BoardIntro[1].z;
    func_8004CCD0(&MDL88_0->coords, &MDL88_1->coords, &MDL88_0->unk_18);
    func_8004CCD0(&MDL88_1->coords, &MDL88_0->coords, &MDL88_1->unk_18);
    for (i = 0; i < 7; i++) {
        stars[i] = MBModelCreate(0x75, NULL);
        angle = (i * 51 + 30) * 0.017453292519943295;
        x = sinf(angle) * 270.0f + D_800FD6F8_BoardIntro.x;
        func_800A0D00(&stars[i]->coords, x, D_800FD6F8_BoardIntro.y - 20.0f,
                      cosf(angle) * 270.0f + D_800FD6F8_BoardIntro.z);
    }
    func_80060128(0x3A);
    SetFadeInTypeAndTime(2, 20);
    HuPrcSleep(20);
    func_8004A520();
    HuPrcSleep(30);
    HuPrcSleep(func_8004FD68(&D_800FD6B0_BoardIntro[0], &D_800FD6B0_BoardIntro[1], 10.0f) + 20);
    func_800601D4(40);
    func_800726AC(2, 20);
    HuPrcSleep(20);
    func_8004A140();
    MBModelKill(MDL88_0);
    MBModelKill(MDL88_1);
    MDL88_0 = NULL;
    MDL88_1 = NULL;
    for (i = 0; i < 7; i++) {
        MBModelKill(stars[i]);
    }
}
void func_800F9BCC_BoardIntro(void) {
    s32 fx;
    s32 i;

    func_8004F8DC();
    fx = func_8004F954(0xA0146, 32);
    func_8004FA90(fx, 4.0f, 4.0f, 4.0f);
    D_800FCD70_BoardIntro = MBModelCreate(8, D_800FD704_BoardIntro);
    func_800A0D00(&D_800FCD70_BoardIntro->coords, D_800FD3CC_BoardIntro[D_801102B0].x,
                  D_800FD3CC_BoardIntro[D_801102B0].y, D_800FD3CC_BoardIntro[D_801102B0].z);
    func_8004CCD0(&D_800FCD70_BoardIntro->coords, &D_800F32A0->coords, &D_800FCD70_BoardIntro->unk_18);
    func_8004F140(*D_800FCD70_BoardIntro->unk_3C->unk_40);
    MBMotionSet(D_800FCD70_BoardIntro, 3, 2);
    MDL88_0 = MBModelCreate(0x6F, NULL);
    MDL88_0->unk_0A |= 1;
    func_800A0D00(&MDL88_0->coords, D_800FD3CC_BoardIntro[D_801102B0].x,
                  D_800FD3CC_BoardIntro[D_801102B0].y, D_800FD3CC_BoardIntro[D_801102B0].z);
    func_8004E3E0(0, &D_800FD6E0_BoardIntro, 10, D_800FCD70_BoardIntro);
    func_8004E3E0(0, &D_800FD6E0_BoardIntro, 10, MDL88_0);
    HuPrcSleep(10);
    func_8004E3E0(0, &D_800FD6EC_BoardIntro, 40, D_800FCD70_BoardIntro);
    func_8004E3E0(0, &D_800FD6EC_BoardIntro, 40, MDL88_0);
    for (i = 0; i < 40; i++) {
        if ((i & 1) == 0) {
            func_8004F9F4(fx, D_800FCD70_BoardIntro->coords.x, D_800FCD70_BoardIntro->coords.y,
                          D_800FCD70_BoardIntro->coords.z, 1);
        }
        HuPrcVSleep();
    }
    func_8004F4D4(D_800FCD70_BoardIntro, 0, 2);
    func_8004E3E0(0, &D_800FD42C_BoardIntro, 20, D_800FCD70_BoardIntro);
    func_8004F00C(D_800FCD70_BoardIntro, 20.0f, -2.0f);
    HuPrcSleep(10);
    for (i = 0; i < 4; i++) {
        func_8004EE14(i, &D_800FD42C_BoardIntro, 10, NULL);
        func_8004F4D4(GwPlayer[i].player_obj, 3, 2);
    }
    HuPrcSleep(10);
    for (i = 0; i < 4; i++) {
        func_8004F4D4(GwPlayer[i].player_obj, 2, 2);
    }
    func_8004EE14(0, &GwPlayer[0].player_obj->coords, 10, D_800FCD70_BoardIntro);
    for (i = 0; i < 4; i++) {
        func_8004F4D4(GwPlayer[i].player_obj, 3, 2);
    }
    func_8004FAB8(fx);
}