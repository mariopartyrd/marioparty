#include "ovl62b.h"

extern Vec3f D_800FD660_BoardIntro[2]; /* camera path: start, end */
extern Vec3f D_800FD678_BoardIntro;

/* .data */

Vec3f D_800FD660_BoardIntro[2] = {
    { -1440.0f, 0.0f, -978.0f },
    { 849.0f, 0.0f, 704.0f },
};

Vec3f D_800FD678_BoardIntro = { -109.5459976196289f, -167.447998046875f, -1129.89501953125f };

void func_800F92C0_BoardIntro(void) {
    LoadBackgroundIndex(0);
    HuPrcSleep(2);
    func_8004B5DC(&D_800FD660_BoardIntro[0]);
    func_80060128(0x3A);
    SetFadeInTypeAndTime(2, 16);
    HuPrcSleep(16);
    func_8004A520();
    HuPrcSleep(30);
    HuPrcSleep(func_8004FD68(&D_800FD660_BoardIntro[0], &D_800FD660_BoardIntro[1], 19.0f) + 20);
    func_800601D4(40);
    func_800726AC(2, 20);
    HuPrcSleep(20);
    func_8004A140();
    D_800FCD78_BoardIntro[0] = LoadFormFile(0xA009C, 0x2B9);
    func_80025798(D_800FCD7A_BoardIntro, D_800FD678_BoardIntro.x, D_800FD678_BoardIntro.y, D_800FD678_BoardIntro.z);
    func_80025EB4(D_800FCD7A_BoardIntro, 2, 1);
}
void func_800F93AC_BoardIntro(void) {
    Object* obj;
    s32 i;

    obj = D_800FCD70_BoardIntro = MBModelCreate(8, D_800FD528_BoardIntro);
    obj->coords.x = D_800FD3CC_BoardIntro[D_801102B0].x;
    obj->coords.y = D_800FD3CC_BoardIntro[D_801102B0].y;
    obj->coords.z = D_800FD3CC_BoardIntro[D_801102B0].z;
    func_8004CCD0(&obj->coords, &GwPlayer[0].player_obj->coords, &obj->unk_18);
    func_8004F140(*D_800FCD70_BoardIntro->unk_3C->unk_40);
    MBMotionSet(D_800FCD70_BoardIntro, 2, 2);
    func_8004E3E0(0, &D_800FD42C_BoardIntro, 10, D_800FCD70_BoardIntro);
    HuPrcSleep(10);
    func_8004F4D4(D_800FCD70_BoardIntro, 0, 2);
    for (i = 0; i < 4; i++) {
        func_8004EE14(i, &D_800FD42C_BoardIntro, 10, NULL);
        func_8004F4D4(GwPlayer[i].player_obj, 3, 2);
    }
    HuPrcSleep(10);
}