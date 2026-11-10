#include "OptionsHouse.h"

typedef struct OptionsMenuEntry {
    /* 0x00 */ u8 pos;
    /* 0x01 */ u8 cam;
    /* 0x04 */ s32 msg;
} OptionsMenuEntry; // sizeof 0x08

typedef struct OptionsSongEntry {
    /* 0x00 */ s16 song;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 msg;
    /* 0x08 */ s8 unk_08;
    /* 0x09 */ s8 unk_09;
} OptionsSongEntry; // sizeof 0x0C

extern Addr D_15396A0;
extern Addr D_1778BC0;
extern Addr D_1832AE0;
extern Addr D_1BB8460;

s32 func_80059550(s16 index);
s32 func_80059CE8(void* str, s16 win);
void func_8005B648(s8 vol, s16 time);
s32 func_8000C144(void);
void func_8006073C(void);
void func_80010C30(Addr*, s32, s32, s32);
void func_8000BE98(Addr*, Addr*, s32, s32, s32);
void func_800F66FC_OptionsHouse(void* arg0);
/* retail's prototype returned an int: the result is re-extended at every use */
#define func_8006D010_s32 ((s32 (*)(s16, s16, s16, s16, s32, s16))func_8006D010)
void func_800F7020_OptionsHouse(void);
void func_800F73B0_OptionsHouse(s16 arg0, s16 arg1);
void func_800F74C0_OptionsHouse(void);
void func_800F752C_OptionsHouse(s32 arg0);
void func_800F75D4_OptionsHouse(void);
void func_800F7604_OptionsHouse(void);
void func_800F7ACC_OptionsHouse(void);
void func_800F7CE0_OptionsHouse(void);

Vec3f D_800F7EA0_OptionsHouse[] = {
    {0.0f, 190.0f, 0.0f}, {0.0f, 190.0f, 0.0f}, {0.0f, 190.0f, 0.0f}, {0.0f, 190.0f, 0.0f},
    {0.0f, 190.0f, 0.0f}, {0.0f, 160.0f, -140.0f}, {140.0f, 175.0f, 0.0f}, {312.0f, 233.0f, -5.0f},
    {-215.0f, 265.0f, 145.0f}, {-280.0f, 320.0f, 125.0f}, {167.0f, 285.0f, 217.0f},
};
Vec3f D_800F7F24_OptionsHouse[] = {
    {12.0f, 180.0f, 0.0f}, {6.0f, 90.0f, 0.0f}, {4.0f, 0.0f, 0.0f}, {0.0f, 295.0f, 0.0f},
    {348.0f, 257.0f, 0.0f}, {12.0f, 180.0f, 0.0f}, {6.0f, 90.0f, 0.0f}, {30.0f, 89.5f, 0.0f},
    {0.0f, 290.0f, 0.0f}, {9.0f, 215.0f, 0.0f}, {6.0f, 68.5f, 0.0f},
};
Vec3f D_800F7FA8_OptionsHouse[] = {
    {0.0f, 120.0f, -323.0f}, {470.0f, 150.0f, 0.0f}, {0.0f, 150.0f, 520.0f}, {-400.0f, 280.0f, 210.0f},
    {-420.0f, 250.0f, -100.0f},
};
OptionsMenuEntry D_800F7FE4_OptionsHouse[] = {
    {0, 0, 0x44A}, {1, 1, 0x44E}, {2, 2, 0x44C}, {3, 3, 0x44B}, {4, 4, 0x44F},
};
s32 D_800F800C_OptionsHouse = 0;
s16 D_800F8010_OptionsHouse = -1;
s16 D_800F8012_OptionsHouse = 0;
Vec3f D_800F8014_OptionsHouse[] = {
    {426.0f, 199.0f, -42.5f}, {421.0f, 189.79999f, -42.5f}, {415.0f, 180.65001f, -42.5f},
    {409.4f, 171.04999f, -42.5f}, {404.0f, 160.8f, -42.5f}, {397.59998f, 150.9f, -42.5f},
};
OptionsSongEntry D_800F805C_OptionsHouse[] = {
    {6, 0, 0x487, 1, 0}, {1, 0, 0x45C, 1, 0}, {42, 0, 0x485, 0, 0},
    {2, 0, 0x45D, 0, 0}, {4, 0, 0x45F, 0, 0}, {5, 0, 0x460, 0, 0},
    {6, 0, 0x461, 0, 0}, {7, 0, 0x462, 0, 0}, {3, 0, 0x45E, 0, 0},
    {17, 0, 0x46C, 0, 0}, {43, 0, 0x486, 0, 0}, {8, 0, 0x463, 0, 0},
    {9, 0, 0x464, 0, 0}, {10, 0, 0x465, 0, 0}, {11, 0, 0x466, 0, 0},
    {12, 0, 0x467, 0, 1}, {13, 0, 0x468, 0, 0}, {21, 0, 0x470, 0, 0},
    {26, 0, 0x475, 0, 0}, {27, 0, 0x476, 0, 0}, {28, 0, 0x477, 0, 0},
    {25, 0, 0x474, 0, 0}, {29, 0, 0x478, 0, 0}, {30, 0, 0x479, 0, 0},
    {35, 0, 0x47E, 0, 0}, {38, 0, 0x481, 0, 0}, {31, 0, 0x47A, 0, 0},
    {32, 0, 0x47B, 0, 0}, {37, 0, 0x480, 0, 0}, {33, 0, 0x47C, 0, 0},
    {39, 0, 0x482, 0, 0}, {34, 0, 0x47D, 0, 0}, {36, 0, 0x47F, 0, 0},
    {19, 0, 0x46E, 0, 0}, {18, 0, 0x46D, 0, 0}, {16, 0, 0x46B, 0, 0},
    {14, 0, 0x469, 0, 1}, {2, 0, 0x483, 1, 0}, {3, 0, 0x484, 1, 0},
    {49, 0, 0x48C, 0, 0}, {65, 0, 0x48D, 0, 0}, {47, 0, 0x48A, 0, 0},
    {48, 0, 0x48B, 0, 0}, {15, 0, 0x46A, 0, 1}, {5, 0, 0x46F, 1, 0},
};
s16 D_800F8278_OptionsHouse[] = {
    0x41A, 0x41B, 0x41C, 0x41D, 0x41E, 0x420, 0x421, 0x422, 0x423, 0x425, 0x43A, 0x43B, 0x465,
    0x466, 0x467, 0x468, 0x469, 0x46A, 0x46B, 0x44A, 0x44B, 0x44C, 0x44D, 0x44E, 0x44F, 0x451,
    0x452, 0x453, 0x454, 0x455, 0x456, 0x45F, 0x460, 0x461, 0x462, 0x463, 0x464, 0x443, 0x444,
    0x445, 0x446, 0x447, 0x448, 0x458, 0x459, 0x45A, 0x45B, 0x45C, 0x45D, 0, 0, 0,
};

void func_800F65E0_OptionsHouse() {
    InitCameras(1);
    omInitObjMan(0x20, 4);
    omSetStatBit(omAddObj(0x7FDA, 0U, 0U, -1, func_80059EBC), 0xA0);
    D_800F384C = 0;
    func_8006CEA0();
    func_800234B8(0U, 0U, 0U, 0U);
    func_800234B8(1U, 0U, 0U, 0U);
    func_800F6BFC_OptionsHouse();
    func_800F6C90_OptionsHouse();
    D_800F8314_OptionsHouse = omAddPrcObj(func_800F6750_OptionsHouse, 0xAU, 0, 0);
    SetFadeInTypeAndTime(0xFF, 8);
    func_8005AF60();
    D_800F8310_OptionsHouse = func_80059C28();
    func_80060128(5);
}

void func_800F66C4_OptionsHouse(s32 arg0) {
    D_800ED610 = &D_800F7EA0_OptionsHouse[arg0];
    D_800ED72C = &D_800F7F24_OptionsHouse[arg0];
}

void func_800F66FC_OptionsHouse(void* arg0) {
    func_8006EB40(D_800F8310_OptionsHouse);
    func_8006E288(D_800F8310_OptionsHouse, 7);
    LoadStringIntoWindow(D_800F8310_OptionsHouse, arg0, -1, -1);
}

void func_800F6750_OptionsHouse(void) {
    Vec2f pos;
    s32 sprite;
    s32 msg;
    s32 cur;
    s32 btn;
    s32 max;

    msg = -1;
    cur = 0;
    sprite = func_80019060((s16)InitSprite(0x85), 1, 1);
    ShowBasicSprite((u16)sprite);
    func_80018D84((u16)sprite, 0xFFFF);
    while (TRUE) {
        btn = func_80059CB8();
        D_800ECC22 = 1;
        if (btn & 0x8000) {
            D_800F384C = 0;
            D_800ECC22 = 0;
            PlaySound(0xF6);
            func_80018C90(sprite);
            switch (cur) {
            case 0:
                func_800F7020_OptionsHouse();
                break;
            case 1:
                func_800F7604_OptionsHouse();
                break;
            case 4:
                func_800F7CE0_OptionsHouse();
                break;
            case 3:
                func_800F7ACC_OptionsHouse();
                break;
            case 2:
                if (func_80059CE8((void*)0x44D, D_800F8310_OptionsHouse) != 0) {
                    D_800F5144 = 1;
                    while (TRUE) {
                        HuPrcVSleep();
                    }
                }
                break;
            }
            if (D_800F5144 != 1) {
                msg = -1;
                ShowBasicSprite((u16)sprite);
            }
        }
        if (((u32)btn >> 14) & 1 & (cur != 2)) {
            PlaySound(0xF8);
            cur = 2;
        }
        if (func_8006FCC0(D_800F8310_OptionsHouse) == 0) {
            if (_CheckFlag(0x23) != 0) {
                max = 4;
            } else {
                max = 3;
            }
            if (btn & 0x100) {
                PlaySound(0xF5);
                cur++;
                if (cur == 1) {
                    cur += (_CheckFlag(0x22) == 0);
                }
                if (cur > max) {
                    cur = 0;
                }
            }
            if (btn & 0x200) {
                cur--;
                if (cur == 1) {
                    cur -= (_CheckFlag(0x22) == 0);
                }
                if (cur < 0) {
                    cur = max;
                }
            }
        }
        if (msg != D_800F7FE4_OptionsHouse[cur].msg) {
            D_800F384C = btn;
            if (msg != -1) {
                PlaySound(0xF5);
            }
            func_800F66FC_OptionsHouse((void*)(s32)D_800F7FE4_OptionsHouse[cur].msg);
        }
        msg = D_800F7FE4_OptionsHouse[cur].msg;
        func_800F66C4_OptionsHouse(D_800F7FE4_OptionsHouse[cur].cam);
        Convert3DTo2D(0, &D_800F7FA8_OptionsHouse[D_800F7FE4_OptionsHouse[cur].pos], &pos);
        SetBasicSpritePos((u16)sprite, pos.x - 24.0f, pos.y);
        HuPrcVSleep();
    }
}
void func_800F6A78_OptionsHouse(omObjData* arg0) {
    if ((D_800F5144 != 0) || (D_800F800C_OptionsHouse != 0)) {
        func_80072724(0xFF, 0xFF, 0xFF);
        func_800601D4(0x1E);
        if (D_800F800C_OptionsHouse != 0) {
            func_800726AC(0, 0x28);
        } else {
            func_800726AC(0, 4);
        }
        arg0->func_ptr = &func_800F6AFC_OptionsHouse;
    }
}

void func_800F6AFC_OptionsHouse() {
    s16 var_a0;

    if (func_80072718() == 0) {
        func_80070ED4();
        if (D_800F800C_OptionsHouse != 0) {
            func_8005B060();
            var_a0 = 2;
        } else {
            func_8005B244();
            var_a0 = 1;
        }
        omOvlReturnEx(var_a0);
    }
}

void func_800F6B5C_OptionsHouse(omObjData* arg0) {
    arg0->model[0] = func_800174C0(0x90056, 0x2B9);
    arg0->model[1] = func_800174C0(0x90057, 0x2B9);
    arg0->model[2] = func_800174C0(0x90058, 0x2B9);

    arg0->trans.x = arg0->trans.y = arg0->trans.z = 0.0f;
    func_80025798((s16) arg0->model[0], 0.0f, arg0->trans.y, arg0->trans.z);
    arg0->func_ptr = &func_800F6A78_OptionsHouse;
}

void func_800F6BFC_OptionsHouse() {
    CRot.x = 0.0f;
    CRot.y = 180.0f;
    CRot.z = 0.0f;
    Center.x = 0.0f;
    Center.y = 180.0f;
    Center.z = 650.0f;

    func_800F66C4_OptionsHouse(0);
    func_80023504(1, -10.0f, 69.0f, 69.0f);
    omAddObj(1, 4U, 0U, -1, func_800F6B5C_OptionsHouse);
}

void func_800F6C90_OptionsHouse() {
    omObjData* temp_v0;
    s16 var_a0;
    s16 var_a1;

    temp_v0 = omAddObj(1, 1U, 3U, -1, NULL);
    D_800F8318_OptionsHouse = temp_v0;
    *temp_v0->model = LoadFormFile(0x9005E, 0x2B9);
    func_80025EB4(*temp_v0->model, 2, 2);
    temp_v0->motion[0] = func_80025E48(*temp_v0->model);
    temp_v0->motion[1] = func_8005A22C(0x9005F);
    temp_v0->motion[2] = func_8005A22C(0x90060);
    temp_v0->trans.x = 0.0f;
    temp_v0->trans.y = 80.0f;
    temp_v0->trans.z = -323.0f;
    temp_v0->scale.x = temp_v0->scale.y = temp_v0->scale.z = 1.0f;
    temp_v0->rot.x = 0.0f;
    temp_v0->rot.y = 0.0f;
    temp_v0->rot.z = 0.0f;

    temp_v0 = omAddObj(1, 1U, 2U, -1, NULL);
    D_800F831C_OptionsHouse = temp_v0;
    *temp_v0->model = LoadFormFile(0x90061, 0x2B9);
    func_80025EB4(*temp_v0->model, 2, 2);
    temp_v0->motion[0] = func_80025E48(*temp_v0->model);
    temp_v0->motion[1] = func_8005A22C(0x90062);
    if (_CheckFlag(0x23) == 0) {
        func_800258EC(*temp_v0->model, 4, 4);
    }
    temp_v0->trans.x = -430.0f;
    temp_v0->trans.y = 240.0f;
    temp_v0->trans.z = -100.0f;
    temp_v0->scale.x = temp_v0->scale.y = temp_v0->scale.z = 1.0f;
    temp_v0->rot.x = 0.0f;
    temp_v0->rot.y = 0.0f;
    temp_v0->rot.z = 0.0f;

    temp_v0 = omAddObj(1, 1U, 2U, -1, NULL);
    D_800F8320_OptionsHouse = temp_v0;
    *temp_v0->model = LoadFormFile(0x9005C, 0x2B9);
    temp_v0->motion[0] = func_80025E48(*temp_v0->model);
    temp_v0->motion[1] = func_8005A22C(0x9005D);
    if (_CheckFlag(0x10) != 0) {
        func_8002888C(*temp_v0->model, temp_v0->motion[0]);
    } else {
        func_8002888C(*temp_v0->model, temp_v0->motion[1]);
    }
    func_80025EB4(*temp_v0->model, 0, 0);
    temp_v0->trans.x = temp_v0->trans.y = temp_v0->trans.z = 0.0f;
    temp_v0->scale.x = temp_v0->scale.y = temp_v0->scale.z = 1.0f;
    temp_v0->rot.x = temp_v0->rot.y = temp_v0->rot.z = 0.0f;

    temp_v0 = omAddObj(1, 1U, 2U, -1, NULL);
    D_800F8324_OptionsHouse = temp_v0;
    *temp_v0->model = LoadFormFile(0x9005A, 0x2B9);
    temp_v0->motion[0] = func_80025E48(*temp_v0->model);
    temp_v0->motion[1] = func_8005A22C(0x9005B);
    func_8002888C(*temp_v0->model, temp_v0->motion[1]);
    func_80025EB4(*temp_v0->model, 0, 0);
    temp_v0->trans.x = temp_v0->trans.y = temp_v0->trans.z = 0.0f;
    temp_v0->scale.x = temp_v0->scale.y = temp_v0->scale.z = 1.0f;
    temp_v0->rot.x = temp_v0->rot.y = temp_v0->rot.z = 0.0f;
}

void func_800F7020_OptionsHouse() {
    TextWindow* temp_v0_2;
    s16 temp_v0;
    s32 temp_v0_3;

    func_800F66C4_OptionsHouse(5);
    func_80025C20(*D_800F8318_OptionsHouse->model, D_800F8318_OptionsHouse->motion[1], 0, 0xA, 0);
    func_800F66FC_OptionsHouse((void*)0x450);
    HuPrcSleep(0x1E);
    func_80025C20(*D_800F8318_OptionsHouse->model, *D_800F8318_OptionsHouse->motion, 0, 0xA, 2);

    while (func_8006FCC0(D_800F8310_OptionsHouse) != 0) {
        HuPrcVSleep();
    }

    if (func_8006FCF0(D_800F8310_OptionsHouse, 0, 0) != 1) {
        func_80025C20(*D_800F8318_OptionsHouse->model, D_800F8318_OptionsHouse->motion[1], 0, 0xA, 0);
        func_800F66FC_OptionsHouse((void*)0x451);
        HuPrcSleep(0x1E);
        func_80025C20(*D_800F8318_OptionsHouse->model, *D_800F8318_OptionsHouse->motion, 0, 0xA, 2);

        while (func_8006FCC0(D_800F8310_OptionsHouse) != 0) {
            HuPrcVSleep();
        }

    } else {
        func_80025C20(*D_800F8318_OptionsHouse->model, D_800F8318_OptionsHouse->motion[2], 0, 0xA, 1);
        HuPrcSleep(5);
        func_8002888C(*D_800F8318_OptionsHouse->model, D_800F8318_OptionsHouse->motion[2]);
        func_8005A258(*D_800F8318_OptionsHouse->model);
        HuPrcSleep(5);
        func_800F66C4_OptionsHouse(0xA);
        HuPrcSleep(0x28);
        func_8002888C(*D_800F8324_OptionsHouse->model, *D_800F8324_OptionsHouse->motion);
        PlaySound(0x1E);
        func_80060F04(0, 5, 0, 5);
        func_8005A258(*D_800F8324_OptionsHouse->model);
        temp_v0 = func_8006D010(0x39, 0x38, 0xCE, 0x5A, 0, 0);
        temp_v0_2 = func_8006DD60(temp_v0);
        temp_v0_2->unk_04 = 0;
        temp_v0_2->unk_03 = 0;
        LoadStringIntoWindow(temp_v0, (void*)0x452, -1, -1);
        func_800F66FC_OptionsHouse((void*)0x453);

        while (func_8006FCC0(D_800F8310_OptionsHouse) != 0) {
            HuPrcVSleep();
        }

        if (func_8006FCF0(D_800F8310_OptionsHouse, 0, 0) == 1) {
            func_80070D90(temp_v0);
            func_800F66FC_OptionsHouse((void*)0x454);

            while (func_8006FCC0(D_800F8310_OptionsHouse) != 0) {
                HuPrcVSleep();
            }

            while (!((temp_v0_3 = func_80059CB8()) & 0x4000)) {
                if (temp_v0_3 & 0x1000) {
                    PlaySound(0x20);
                    D_800F800C_OptionsHouse = 1;
                    while (TRUE) {
                        HuPrcVSleep();
                    }
                }
                HuPrcVSleep();
            }
            func_8002888C(*D_800F8324_OptionsHouse->model, D_800F8324_OptionsHouse->motion[1]);
            func_80025C20(*D_800F8318_OptionsHouse->model, *D_800F8318_OptionsHouse->motion, 0, 0xA, 2);
        } else {
            func_80070D90(temp_v0);
            func_8002888C(*D_800F8324_OptionsHouse->model, D_800F8324_OptionsHouse->motion[1]);
            func_80025C20(*D_800F8318_OptionsHouse->model, *D_800F8318_OptionsHouse->motion, 0, 0xA, 2);
        }
    }
}

void func_800F73B0_OptionsHouse(s16 arg0, s16 arg1) {
    file_1ACF0_struct* data;

    D_800F8012_OptionsHouse = arg0;
    func_80060198();
    func_8006073C();
    HuPrcSleep(5);
    while (func_8000B198() != 0) {
        HuPrcVSleep();
    }
    HuPrcSleep(1);
    data = func_8000B2BC();
    data->unk_40 = arg1 + 20;
    if (D_800F8012_OptionsHouse == 0) {
        func_80010C30(&D_1832AE0, 0, 0, 0);
        func_8000BE98(&D_15396A0, &D_1778BC0, 0, 0, 0);
    } else {
        func_80010C30(&D_1BB8460, 0, 0, 0);
        func_8000BE98(&D_1778BC0, &D_1832AE0, 0, 0, 0);
    }
    func_8000B13C();
    if (_CheckFlag(0x10) != 0) {
        func_8000B364(0);
    } else {
        func_8000B364(1);
    }
}
void func_800F74C0_OptionsHouse() {
    s32 temp_s0;

    D_800F8010_OptionsHouse = -1;
    func_80060198();

    if (D_800F8012_OptionsHouse == 0) {
        temp_s0 = PlaySound(0x23);
    } else {
        temp_s0 = PlaySound(0xA3);
    }

    while (func_800115C8(temp_s0) != 0) {
        HuPrcVSleep();
    }
}

void func_800F752C_OptionsHouse(s32 arg0) {
    s16 snd;

    func_800F74C0_OptionsHouse();
    if (D_800F8012_OptionsHouse == 0) {
        snd = PlaySound(0x24);
    } else {
        snd = PlaySound(0xA4);
    }
    while (func_800115C8(snd) != 0) {
        HuPrcVSleep();
    }
    func_800F73B0_OptionsHouse(D_800F805C_OptionsHouse[arg0].unk_08, D_800F805C_OptionsHouse[arg0].unk_09);
    func_80060128(D_800F805C_OptionsHouse[arg0].song);
    D_800F8010_OptionsHouse = arg0;
}
void func_800F75D4_OptionsHouse() {
    if (D_800F8012_OptionsHouse == 0) {
        PlaySound(0xF5);
    } else {
        PlaySound(0x21);
    }
}

void func_800F7604_OptionsHouse(void) {
    char buf[24];
    s16 win;
    s32 prevCol;
    s32 i;
    s32 count;
    s32 maxRow;
    s32 row;
    s32 col;
    s32 prevRow;
    s32 btn;
    omObjData* obj;

    prevRow = -1;
    for (i = 0; i < 6; i++) {
        if (func_80059550(i) & 0xFFFF) {
            break;
        }
    }
    count = 8;
    if (i != 6) {
        count = 0x25;
    }
    if (_CheckFlag(0x17) != 0) {
        count = 0x29;
    }
    if (_CheckFlag(0x18) != 0) {
        count = 0x2D;
    }
    maxRow = (count + 5) / 6 - 1;
    func_800F66C4_OptionsHouse(6);
    row = 0;
    col = 0;
    prevCol = 0;
    if (func_80059CE8((void*)0x459, D_800F8310_OptionsHouse) == 0) {
        return;
    }
    func_8005B648(0x5A, 0x12);
    func_800F66C4_OptionsHouse(7);
    func_80070D90(D_800F8310_OptionsHouse);
    HuPrcSleep(0x28);
    win = func_8006D010(0x70, 0x28, 0xB8, 0xA2, 0, 0);
    {
        TextWindow* tw = func_8006DD60(win);
        tw->unk_04 = 0;
        tw->unk_03 = 0;
        tw->unk_0A = 0x10;
        func_800674BC(tw->unk_44, 0, 0x8000);
    }
    obj = omAddObj(1, 1, 0, -1, NULL);
    *obj->model = LoadFormFile(0x90059, 0x2B9);
    obj->scale.x = obj->scale.y = obj->scale.z = 0.2f;
    obj->rot.x = 0.0f;
    obj->rot.y = 178.923f;
    obj->rot.z = 60.3816f;
    while (TRUE) {
        btn = func_80059CB8();
        if (btn & 0x8000) {
            prevRow = -1;
            if (row * 6 + col < count) {
                func_800F752C_OptionsHouse(row * 6 + col);
            }
        }
        if (btn & 0x4000) {
            break;
        }
        if (btn & 0x400) {
            col++;
            if (col >= 6) {
                row++;
                col = 5;
                if (row > maxRow) {
                    row = maxRow;
                } else {
                    col = 0;
                }
            }
        }
        if (btn & 0x800) {
            col--;
            if (col < 0) {
                row--;
                col = 5;
                if (row < 0) {
                    row = 0;
                    col = 0;
                }
            }
        }
        if (btn & 0x100) {
            row++;
            if (row > maxRow) {
                row = maxRow;
            }
        }
        if (btn & 0x200) {
            row--;
            if (row < 0) {
                row = 0;
            }
        }
        if (prevCol != col) {
            func_800F75D4_OptionsHouse();
        }
        prevCol = col;
        if (prevRow != row) {
            if (prevRow != -1) {
                func_800F75D4_OptionsHouse();
            }
            func_8006EB40(win);
            sprintf(buf, "\x08\x11\x0A\x08\x12\x0A\x08\x13\x0A\x08\x14\x0A\x08\x15\x0A\x08\x16");
            for (i = 0; i < 6; i++) {
                if (row * 6 + i < count) {
                    func_8006DA5C(win, (void*)(s32)D_800F805C_OptionsHouse[row * 6 + i].msg, i);
                } else {
                    func_8006DA5C(win, "", i);
                }
                if (row * 6 + i == D_800F8010_OptionsHouse) {
                    buf[i * 3] = 7;
                }
            }
            LoadStringIntoWindow(win, buf, -1, -1);
        }
        obj->trans.x = D_800F8014_OptionsHouse[col].x;
        obj->trans.y = D_800F8014_OptionsHouse[col].y;
        obj->trans.z = D_800F8014_OptionsHouse[col].z;
        prevRow = row;
        if (D_800F8010_OptionsHouse >= 0 && func_8000C144() == 0) {
            func_800F74C0_OptionsHouse();
            func_800F73B0_OptionsHouse(0, 0);
            func_80060128(5);
            func_80060214(0x5A);
        }
        HuPrcVSleep();
    }
    if (D_800F8010_OptionsHouse != -1) {
        func_800F74C0_OptionsHouse();
        func_800F73B0_OptionsHouse(0, 0);
        func_80060128(5);
    } else {
        func_8005B648(0x7F, 0x12);
    }
    func_80070D90(win);
    D_800F8310_OptionsHouse = func_80059C28();
    func_8002456C(*obj->model);
    omDelObj(obj);
}
void func_800F7ACC_OptionsHouse(void) {
    s32 win;
    s32 prev;
    s32 btn;
    s32 sel;
    TextWindow* tw;

    prev = -1;
    func_800F66C4_OptionsHouse(8);
    func_800F66FC_OptionsHouse((void*)0x458);
    while (func_8006FCC0(D_800F8310_OptionsHouse) != 0) {
        HuPrcVSleep();
    }
    win = func_8006D010_s32(0x4F, 0x2C, 0xA2, 0x14, 0, 0);
    func_800717C0((s16)win);
    tw = func_8006DD60(win);
    tw->unk_04 = 0;
    tw->unk_03 = 0;
    while (TRUE) {
        btn = func_80059CB8();
        sel = _CheckFlag(0x10) == 0;
        if (prev != sel) {
            func_8006EB40(win);
            func_8006DA5C(win, (void*)(s32)(sel + 0x456), 0);
            LoadStringIntoWindow(win, (void*)0x455, -1, -1);
        }
        prev = sel;
        if (btn & 0x4000) {
            break;
        }
        if (btn & 0x8000) {
            func_80025C20(*D_800F8320_OptionsHouse->model, *(sel != 0 ? D_800F8320_OptionsHouse->motion : D_800F8320_OptionsHouse->motion + 1), 0, 0x28, 1);
            HuPrcSleep(0x14);
            func_8002888C(*D_800F8320_OptionsHouse->model, *(sel != 0 ? D_800F8320_OptionsHouse->motion : D_800F8320_OptionsHouse->motion + 1));
            HuPrcSleep(0x14);
            func_80060F04(0, 5, 0, 5);
            func_8005A258(*D_800F8320_OptionsHouse->model);
            if (_CheckFlag(0x10) != 0) {
                ClearBoardFeatureFlag(0x10);
                func_8000B364(1);
            } else {
                SetBoardFeatureFlag(0x10);
                func_8000B364(0);
            }
            PlaySound(0x1B);
        }
        HuPrcVSleep();
    }
    PlaySound(0xF8);
    func_80070D90(win);
}
void func_800F7CE0_OptionsHouse(void) {
    s32 btn;
    s32 snd;

    func_800F66C4_OptionsHouse(9);
    func_8005B648(0x5A, 0x12);
    func_800F66FC_OptionsHouse((void*)0x45A);
    while (func_8006FCC0(D_800F8310_OptionsHouse) != 0) {
        HuPrcVSleep();
    }
    while (TRUE) {
        btn = func_80059CB8();
        if (btn & 0x4000) {
            break;
        }
        if (btn & 0x8000) {
            snd = PlaySound(D_800F8278_OptionsHouse[(u8)(rand8() % 49)]);
            if ((s16)snd != -1) {
                func_80025C20(*D_800F831C_OptionsHouse->model, D_800F831C_OptionsHouse->motion[1], 0, 0xA, 2);
                while (TRUE) {
                    btn = func_80059CB8();
                    if (func_800115C8(snd) == 0) {
                        break;
                    }
                    if (btn & 0x4000) {
                        func_8006073C();
                        break;
                    }
                    HuPrcVSleep();
                }
                func_80025C20(*D_800F831C_OptionsHouse->model, *D_800F831C_OptionsHouse->motion, 0, 0xA, 2);
            }
        }
        HuPrcVSleep();
    }
    func_8006073C();
    PlaySound(0xF8);
    func_8005B648(0x7F, 0x12);
}
