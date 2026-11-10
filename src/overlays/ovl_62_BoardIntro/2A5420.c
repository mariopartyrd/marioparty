#include "ovl62b.h"

/* retail addresses the model id as D_800FCD74+2 (CSE keeps the address in a register) */
#define MDL74 (((s16*)&D_800FCD74_BoardIntro)[1])
extern Vec3f D_800FD690_BoardIntro[2]; /* camera path: start, end (+8 bytes unused) */

/* .data */

Vec3f D_800FD690_BoardIntro[2] = {
    { -482.0f, 0.0f, 0.0f },
    { -1276.0f, 0.0f, 758.0f },
};

void func_800F9500_BoardIntro(void) {
    LoadBackgroundIndex(7);
    HuPrcSleep(2);
    func_8004B5DC(&D_800FD690_BoardIntro[0]);
    func_80060128(0x3A);
    SetFadeInTypeAndTime(2, 16);
    HuPrcSleep(16);
    func_8004A520();
    HuPrcSleep(30);
    HuPrcSleep(func_8004FD68(&D_800FD690_BoardIntro[0], &D_800FD690_BoardIntro[1], 8.0f) + 20);
    func_800601D4(40);
    func_800726AC(2, 20);
    HuPrcSleep(20);
    func_8004A140();
}
void func_800F959C_BoardIntro(void) {
    Vec3f pos;
    Object* obj;
    s32 i;
    s32 h;

    pos.x = D_800FD3CC_BoardIntro[D_801102B0].x;
    pos.y = D_800FD3CC_BoardIntro[D_801102B0].y;
    pos.z = D_800FD3CC_BoardIntro[D_801102B0].z;
    obj = D_800FCD70_BoardIntro = MBModelCreate(8, NULL);
    obj->coords.x = pos.x;
    obj->coords.y = 0.0f;
    obj->coords.z = pos.z;
    obj->unk_30 = pos.y;
    func_8004CCD0(&obj->coords, &GwPlayer[0].player_obj->coords, &obj->unk_18);
    D_800FCD74_BoardIntro = LoadFormFile(0xA00A5, 0x2A9);
    func_80025798(MDL74, pos.x, pos.y, pos.z);
    func_800257E4(MDL74, 0.0f, 70.0f, 0.0f);
    func_8004F140(*D_800FCD70_BoardIntro->unk_3C->unk_40);
    for (h = D_800FCD70_BoardIntro->unk_30 / 5.0f; h >= 40; h -= 2) {
        if (h == 80) {
            for (i = 0; i < 4; i++) {
                func_8004EE14(i, &pos, 20, NULL);
                func_8004F4D4(GwPlayer[i].player_obj, 3, 0);
                func_8004F40C(GwPlayer[i].player_obj, 2, 2);
            }
        }
        pos.y = h * 5.0f;
        D_800FCD70_BoardIntro->unk_30 = pos.y;
        func_80025798(MDL74, pos.x, pos.y, pos.z);
        HuPrcVSleep();
    }
    h += 2;
    HuPrcSleep(10);
    pos.x = 0.0f;
    pos.y = 15.0f;
    pos.z = 0.0f;
    while (1) {
        D_800FCD70_BoardIntro->unk_30 = h * 5.0f + pos.x;
        func_80025798(MDL74, D_800FD3CC_BoardIntro[D_801102B0].x + pos.z, h * 5.0f,
                      D_800FD3CC_BoardIntro[D_801102B0].z);
        if (h * 5.0f + pos.x <= 0.0f) {
            break;
        }
        pos.x += pos.y;
        pos.y -= 2.0f;
        pos.z -= 10.0f;
        HuPrcVSleep();
    }
    D_800FCD70_BoardIntro->unk_30 = 0.0f;
    for (i = 0; i < 4; i++) {
        func_8004F4D4(GwPlayer[i].player_obj, 3, 2);
    }
}