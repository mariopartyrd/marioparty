#include "ovl62b.h"

/* 2A2500 .data: the sign-turning object. Declared as an array: retail reloads it after its own store. */
/* D_800FCD98_BoardIntro[1..3] (2A2500's data), split off by splat. */
extern omObjData* D_800FCD9C_BoardIntro[1];
/* Camera path points; splat split it into D_800FD7D0 ([0]) and D_800FD7DC ([1]..[3]). [3] is unused. */
extern Vec3f D_800FD7D0_BoardIntro[4];
extern Vec3f D_800FD800_BoardIntro;
extern Vec3f D_800FD80C_BoardIntro;
extern Vec3f D_800FD818_BoardIntro; /* (+12 bytes unused) */

/* .data */

Vec3f D_800FD7D0_BoardIntro[4] = {
    { -1182.0f, 0.0f, 726.0f },
    { -4.0f, 0.0f, -1249.0f },
    { 1244.0f, 0.0f, 727.0f },
    { 510.0f, 410.0f, 450.0f },
};

Vec3f D_800FD800_BoardIntro = { -345.0f, 260.0f, 1800.0f };

Vec3f D_800FD80C_BoardIntro = { -895.0f, 260.0f, 1800.0f };

Vec3f D_800FD818_BoardIntro = { -413.0f, 210.0f, 1368.0f };

/* Unreferenced position after D_800FD818. */
Vec3f D_800FD824_BoardIntro = { 70.0f, 150.0f, 2834.0f };

Vec3f D_800FD830_BoardIntro[2] = {
    { 4.0f, 0.0f, -1335.0f },
    { 1326.0f, 0.0f, 982.0f },
};

void func_800FAF80_BoardIntro(void) {
    LoadBackgroundIndex(0x2F);
    HuPrcSleep(2);
    func_8004B5DC(&D_800FD7D0_BoardIntro[0]);
    func_80060128(0x3A);
    SetFadeInTypeAndTime(2, 16);
    HuPrcSleep(16);
    func_8004A520();
    HuPrcSleep(30);
    HuPrcSleep(func_8004FEA0(&D_800FD7D0_BoardIntro[0], &D_800FD7D0_BoardIntro[1]) + 20);
    HuPrcSleep(func_8004FEA0(&D_800FD7D0_BoardIntro[1], &D_800FD7D0_BoardIntro[2]) + 30);
    func_800601D4(40);
    func_800726AC(2, 20);
    HuPrcSleep(20);
    func_8004A140();
}
void func_800FB030_BoardIntro(omObjData* obj) {
    switch (obj->work[0]) {
        case 0:
        case 2:
            obj->work[1]--;
            if (obj->work[1] == 0) {
                obj->work[2]--;
                if (obj->work[2] == 0) {
                    obj->work[0]++;
                }
            }
            break;
        case 1:
            obj->rot.y += 1.0f;
            MDL88_1->unk_18.x = -sinf(obj->rot.y * 0.017453292519943295);
            MDL88_1->unk_18.z = -cosf(obj->rot.y * 0.017453292519943295);
            if (obj->rot.y >= 180.0f) {
                obj->work[0] = 2;
                obj->work[2] = 1;
            }
            break;
        case 3:
            obj->rot.y += 1.0f;
            MDL88_1->unk_18.x = -sinf(obj->rot.y * 0.017453292519943295);
            MDL88_1->unk_18.z = -cosf(obj->rot.y * 0.017453292519943295);
            if (obj->rot.y >= 360.0f) {
                obj->work[0] = 0;
                obj->work[2] = 5;
                obj->rot.y = 0.0f;
            }
            break;
    }
}
void func_800FB20C_BoardIntro(void) {
    Object* obj;
    s32 i;

    obj = D_800FCD70_BoardIntro = MBModelCreate(8, NULL);
    obj->coords.x = D_800FD3CC_BoardIntro[D_801102B0].x;
    obj->coords.y = D_800FD3CC_BoardIntro[D_801102B0].y;
    obj->coords.z = D_800FD3CC_BoardIntro[D_801102B0].z;
    func_8004CCD0(&obj->coords, &D_800F32A0->coords, &obj->unk_18);
    func_8004F140(*D_800FCD70_BoardIntro->unk_3C->unk_40);
    MDL88_0 = MBModelCreate(0x12, NULL);
    MDL88_0->coords.x = D_800FD3CC_BoardIntro[D_801102B0].x;
    MDL88_0->coords.y = D_800FD3CC_BoardIntro[D_801102B0].y;
    MDL88_0->coords.z = D_800FD3CC_BoardIntro[D_801102B0].z;
    func_8004CCD0(&MDL88_0->coords, &D_800F32A0->coords, &MDL88_0->unk_18);
    MDL88_1 = MBModelCreate(0x12, NULL);
    MDL88_1->coords.x = D_800FD818_BoardIntro.x;
    MDL88_1->coords.y = D_800FD818_BoardIntro.y;
    MDL88_1->coords.z = D_800FD818_BoardIntro.z;
    MDL88_1->unk_18.z = -1.0f;
    MDL88_1->unk_3C->unk_24 = 15.0f;
    func_800A0D00((Vec3f*)&MDL88_1->xScale, 0.8f, 0.8f, 0.8f);
    MBModelDispOff(MDL88_1);
    D_800FCD9C_BoardIntro[0] = omAddObj(0x1000, 0, 0, -1, func_800FB030_BoardIntro);
    D_800FCD9C_BoardIntro[0]->work[0] = 0;
    D_800FCD9C_BoardIntro[0]->work[1] = 0;
    D_800FCD9C_BoardIntro[0]->work[2] = 5;
    D_800FCD9C_BoardIntro[0]->rot.y = 0.0f;
    {
        Vec3f rot1 = { 0.0f, -450.0f, 0.0f };
        Vec3f rot2 = { 0.0f, 100.0f, 0.0f };

        func_8004EA8C(D_800FCD70_BoardIntro, &D_800FD800_BoardIntro, 50, &rot1);
        func_8004EA8C(MDL88_0, &D_800FD800_BoardIntro, 50, &rot1);
        HuPrcSleep(49);
        func_8004EA8C(MDL88_0, &D_800FD80C_BoardIntro, 20, &rot2);
    }
    MBModelDispOn(MDL88_1);
    func_8004F00C(D_800FCD70_BoardIntro, 15.0f, -2.0f);
    D_800FCD70_BoardIntro->unk_30 = D_800FCD70_BoardIntro->coords.y;
    D_800FCD70_BoardIntro->coords.y = 0.0f;
    func_8004E3E0(0, &D_800FD42C_BoardIntro, 20, D_800FCD70_BoardIntro);
    func_8004F044(D_800FCD70_BoardIntro);
    for (i = 0; i < 4; i++) {
        func_8004EE14(i, &D_800FD42C_BoardIntro, 10, NULL);
        func_8004F4D4(GwPlayer[i].player_obj, 3, 2);
    }
    func_8004EE14(0, &GwPlayer[0].player_obj->coords, 10, D_800FCD70_BoardIntro);
    HuPrcSleep(10);
    MBModelKill(MDL88_0);
    MDL88_0 = NULL;
}

