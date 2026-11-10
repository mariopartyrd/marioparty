#include "common.h"
#include "2D6FC0.h"

/* .data */
Vec3f D_800F88C0_MushroomBank[7] = { { 0.0f, 225.0f, 550.0f },  { 0.0f, 320.0f, -50.0f },   { 20.0f, 225.0f, 120.0f },
                                     { -20.0f, 225.0f, 120.0f }, { 0.0f, 185.0f, 570.0f },   { 200.0f, 315.0f, 585.0f },
                                     { -20.0f, 135.0f, 460.0f } };
Vec3f D_800F8914_MushroomBank[7] = { { 6.0f, 180.0f, 0.0f }, { 9.0f, 0.0f, 0.0f },  { 6.0f, 215.0f, 0.0f }, { 6.0f, 145.0f, 0.0f },
                                     { 4.0f, 180.0f, 0.0f }, { 19.0f, 193.0f, 0.0f }, { 0.0f, 140.0f, 0.0f } };
Vec3f D_800F8968_MushroomBank[4] = { { -300.0f, 200.0f, -350.0f }, { 300.0f, 200.0f, -350.0f }, { 0.0f, 130.0f, 480.0f }, { 230.0f, 200.0f, 235.0f } };
BankMenuEntry D_800F8998_MushroomBank[4] = { { 0, 0, 0x0B }, { 1, 0, 0x0C }, { 2, 1, 0x0D }, { 3, 5, -1 } };
s32 D_800F89B8_MushroomBank = 0;
s32 D_800F89BC_MushroomBank = 0;
BankPrize D_800F89C0_MushroomBank[12] = {
    { -1, 0x2E, { -96.0f, 232.0f, 100.0f }, -3, 0x1C, 0x95 },
    { 36, 0x27, { -32.0f, 232.0f, 100.0f }, -2, 0x1D, 0x90 },
    { 37, 0x28, { 32.0f, 232.0f, 100.0f }, -1, 0x1E, 0x91 },
    { 40, 0x2C, { 96.0f, 232.0f, 100.0f }, -4, 0x1F, 0x94 },
    { 29, 0x33, { -96.0f, 136.0f, 100.0f }, 11, 0x18, 0x89 },
    { 30, 0x34, { -32.0f, 136.0f, 100.0f }, 12, 0x19, 0x8A },
    { 32, 0x25, { 32.0f, 136.0f, 100.0f }, 14, 0x1A, 0x8C },
    { 33, 0x26, { 96.0f, 136.0f, 100.0f }, 15, 0x1B, 0x8D },
    { 25, 0x2F, { -96.0f, 40.0f, 100.0f }, 7, 0x14, 0x85 },
    { 26, 0x30, { -32.0f, 40.0f, 100.0f }, 8, 0x15, 0x86 },
    { 27, 0x31, { 32.0f, 40.0f, 100.0f }, 9, 0x16, 0x87 },
    { 28, 0x32, { 96.0f, 40.0f, 100.0f }, 10, 0x17, 0x88 },
};

void func_800F65E0_MushroomBank(void) {
    InitCameras(1);
    func_8001DE70(1);
    omInitObjMan(0x20, 4);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80059EBC), 0xA0);
    D_800F384C = 0;
    func_8006CEA0();
    func_8004F8DC();
    D_800F8B90_MushroomBank = func_8004F954(0x26, 0x20);
    
    if (_CheckFlag(4) != 0) {
        D_800F89B8_MushroomBank = 1;
    }
    
    ClearBoardFeatureFlag(4);
    func_800F7528_MushroomBank();
    func_800F7754_MushroomBank();
    
    if (D_800F89B8_MushroomBank != 0) {
        D_800F8B98_MushroomBank = omAddPrcObj(func_800F6E38_MushroomBank, 0xAU, 0, 0);
    } else {
        D_800F8B98_MushroomBank = omAddPrcObj(func_800F67B0_MushroomBank, 0xAU, 0, 0);
    }
    
    SetFadeInTypeAndTime(0xFF, 8);
    func_8005AF60();
}

void func_800F66DC_MushroomBank(s32 arg0) {
    D_800ED610 = &D_800F88C0_MushroomBank[arg0];
    D_800ED72C = &D_800F8914_MushroomBank[arg0];
}

void func_800F6714_MushroomBank(u16* arg0, s8* arg1, s16 arg2) {
    s32 var_a1;
    s32 i;

    for (i = 0; i < 6; i++) {
        var_a1 = arg1[i] - 0x30;
        if (var_a1 < 0) {
            var_a1 = 0xA;
        }
        
        arg0[i] = func_80019060(arg2, var_a1, 1);
        ShowBasicSprite(arg0[i]);
        func_80018D84(arg0[i], 0xFFFF);
    }
}

void func_800F67B0_MushroomBank(void) {
    Vec3f pos;
    Vec2f scr;
    char buf[8];
    u16 digits[2][6];
    s32 prevCam;
    s32 sprFile;
    s32 spr;
    s32 cur;
    s32 prev;
    s32 delay;
    u32 btn;
    s32 i;
    s32 j;

    prev = -1;
    cur = 0;
    prevCam = 0;
    delay = 0;
    func_80060128(4);
    D_800F8B94_MushroomBank = func_80059C28();
    sprFile = InitSprite(0x9003F);
    if (_CheckFlag(3) != 0 && _CheckFlag(0x17) != 0 && _CheckFlag(0x18) == 0) {
        sprintf(buf, " ;  0 ");
    } else {
        sprintf(buf, " ;%3d ", GwCommon.starNum);
    }
    func_800F6714_MushroomBank(digits[0], (s8*)buf, sprFile);
    sprintf(buf, "<%5d", GwCommon.coinNum);
    func_800F6714_MushroomBank(digits[1], (s8*)buf, sprFile);
    pos.x = 0.0f;
    pos.y = 350.0f;
    pos.z = -480.0f;
    spr = func_80019060((s16)InitSprite(0x85), 1, 1);
    ShowBasicSprite((u16)spr);
    func_80018D84((u16)spr, 0xFFFF);
    while (1) {
        btn = func_80059CB8();
        D_800ECC22 = 1;
        if (btn & 0x8000) {
            D_800F384C = 0;
            D_800ECC22 = 0;
            PlaySound(0xF6);
            func_80018C90((u16)spr);
            for (i = 0; i < 2; i++) {
                for (j = 0; j < 6; j++) {
                    func_80018C90(digits[i][j]);
                }
            }
            switch (cur) {
            case 0:
                func_800F7BC0_MushroomBank();
                break;
            case 1:
                func_800F85D8_MushroomBank();
                break;
            case 2:
                if (func_80059CE8((void*)0xE, D_800F8B94_MushroomBank) != 0) {
                    func_80025EB4(D_800F8B9C_MushroomBank->model[0], 1, 0);
                    HuPrcSleep(20);
                    D_800F5144 = 1;
                    while (1) {
                        HuPrcVSleep();
                    }
                }
                break;
            }
            if (D_800F5144 != 1) {
                prev = -1;
                prevCam = -1;
                ShowBasicSprite((u16)spr);
                for (i = 0; i < 2; i++) {
                    for (j = 0; j < 6; j++) {
                        ShowBasicSprite(digits[i][j]);
                    }
                }
            }
        }
        if ((btn >> 14) & 1 & (cur != 2)) {
            PlaySound(0xF8);
            cur = 2;
        }
        if (delay == 0) {
            if (btn & 0x100) {
                cur++;
                if (cur >= 3) {
                    cur = 0;
                }
            }
            if (btn & 0x200) {
                cur--;
                if (cur < 0) {
                    cur = 2;
                }
            }
        } else {
            delay--;
        }
        if (CRot.y < 175.0f || CRot.y > 185.0f) {
            for (i = 0; i < 2; i++) {
                for (j = 0; j < 6; j++) {
                    func_80018C90(digits[i][j]);
                }
            }
        } else {
            for (i = 0; i < 2; i++) {
                for (j = 0; j < 6; j++) {
                    ShowBasicSprite(digits[i][j]);
                }
            }
        }
        if (prev != cur) {
            if (prev != -1) {
                PlaySound(0xF5);
            }
            func_8006EB40(D_800F8B94_MushroomBank);
            LoadStringIntoWindow(D_800F8B94_MushroomBank, (void*)(s32)D_800F8998_MushroomBank[cur].msg, -1, -1);
            if ((cur == 2) | (prev == 2)) {
                delay = 12;
            }
        }
        prev = cur;
        if (prevCam != D_800F8998_MushroomBank[cur].cam) {
            func_800F66DC_MushroomBank(D_800F8998_MushroomBank[cur].cam);
            D_800F384C = btn;
        }
        prevCam = D_800F8998_MushroomBank[cur].cam;
        Convert3DTo2D(0, &D_800F8968_MushroomBank[D_800F8998_MushroomBank[cur].pos], &scr);
        SetBasicSpritePos((u16)spr, scr.x - 24.0f, scr.y);
        Convert3DTo2D(0, &pos, &scr);
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 6; j++) {
                SetBasicSpritePos(digits[i][j], j * 15 + scr.x - 37.0f, i * 24 + scr.y);
            }
        }
        HuPrcVSleep();
    }
}
/* The bank after a payout trip (D_800F89B8 set on entry): the cursor starts on "leave" (3);
   leaving plays the deposit scene once and opens the menu (choices 2 and 3). Retail's B check
   compares the cursor with 1, which it never is here, so B always sounds. */
void func_800F6E38_MushroomBank(void) {
    Vec2f scr;
    s32 spr;
    s32 cur;
    s32 prevMsg;
    u32 btn;
    s16 snd;
    s32 posIdx;

    prevMsg = -1;
    cur = 3;
    spr = func_80019060((s16)InitSprite(0x85), 1, 1);
    ShowBasicSprite((u16)spr);
    func_80018D84((u16)spr, 0xFFFF);
    while (1) {
        btn = func_80059CB8();
        D_800ECC22 = 1;
        if (btn & 0x8000) {
            D_800ECC22 = 0;
            PlaySound(0xF6);
            func_80018C90((u16)spr);
            switch (cur) {
            case 3:
                if (D_800F89B8_MushroomBank == 1) {
                    func_800601D4(30);
                }
                D_800F8B94_MushroomBank = func_80059C28();
                func_800F66DC_MushroomBank(6);
                LoadStringIntoWindow(D_800F8B94_MushroomBank, (void*)0x22, -1, -1);
                while (func_8006FCC0(D_800F8B94_MushroomBank) != 0) {
                    HuPrcVSleep();
                }
                func_8005963C(7, 0x8000);
                if (D_800F89B8_MushroomBank == 1) {
                    func_80060128(0x38);
                    HuPrcSleep(105);
                    snd = PlaySound(0xE6);
                    while (func_800115C8(snd) != 0) {
                        HuPrcVSleep();
                    }
                    func_80060128(0x2F);
                } else {
                    while (!((btn = func_80059CB8()) & 0x8000)) {
                        HuPrcVSleep();
                    }
                    PlaySound(0x46);
                }
                D_800F89B8_MushroomBank = 2;
                break;
            case 2:
                if (func_80059CE8((void*)0xE, D_800F8B94_MushroomBank) != 0) {
                    func_80025EB4(D_800F8B9C_MushroomBank->model[0], 1, 0);
                    HuPrcSleep(20);
                    D_800F5144 = 1;
                    while (1) {
                        HuPrcVSleep();
                    }
                }
                break;
            }
            func_80070D90(D_800F8B94_MushroomBank);
            if (D_800F5144 != 1) {
                prevMsg = -1;
                ShowBasicSprite((u16)spr);
            }
        }
        if (D_800F89B8_MushroomBank == 2) {
            if ((btn >> 14) & 1 & (cur != 1)) {
                PlaySound(0xF8);
                cur = 2;
            }
            if (btn & 0x100) {
                PlaySound(0xF5);
                cur++;
                if (cur >= 4) {
                    cur = 2;
                }
            }
            if (btn & 0x200) {
                PlaySound(0xF5);
                cur--;
                if (cur < 2) {
                    cur = 3;
                }
            }
        }
        posIdx = D_800F8998_MushroomBank[cur].pos;
        func_800F66DC_MushroomBank(D_800F8998_MushroomBank[cur].cam);
        if (prevMsg != D_800F8998_MushroomBank[cur].msg) {
            if (D_800F8998_MushroomBank[cur].msg < 0) {
                func_80070D90(D_800F8B94_MushroomBank);
            } else {
                D_800F8B94_MushroomBank = func_80059C28();
                LoadStringIntoWindow(D_800F8B94_MushroomBank, (void*)(s32)D_800F8998_MushroomBank[cur].msg, -1, -1);
            }
        }
        prevMsg = D_800F8998_MushroomBank[cur].msg;
        Convert3DTo2D(0, &D_800F8968_MushroomBank[posIdx], &scr);
        SetBasicSpritePos((u16)spr, scr.x - 24.0f, scr.y);
        HuPrcVSleep();
    }
}
void func_800F722C_MushroomBank(omObjData* arg0) {
    if ((D_800F5144 != 0) || (D_800F89BC_MushroomBank != 0)) {
        if (D_800F89B8_MushroomBank == 0) {
            func_800601D4(0x1E);
        }
        func_80072724(255, 255, 255);
        func_800726AC(0, 4);
        arg0->func_ptr = &func_800F72A8_MushroomBank;
    }
}

void func_800F72A8_MushroomBank(void) {
    if (func_80072718() == 0) {
        func_80070ED4();
        func_8005B244();
        if (D_800F89BC_MushroomBank != 0) {
            omOvlCallEx(0x63, 0, 0x91);
            return;
        }
        omOvlReturnEx(1);
    }
}

void func_800F7308_MushroomBank(omObjData* arg0) {
    unk_ovl_2D_struct* temp_s0;
    void* file;

    arg0->model[0] = func_800174C0(0x90035, 0x2A9);
    func_80025EB4(arg0->model[0], 1, 1);
    temp_s0 = &D_800F2B7C[arg0->model[0]];
    file = DataRead(0x90042);
    func_80038A9C(temp_s0->unk_6C, file, 0, "41tt000o_DEF");
    DataClose(file);
    func_80025AD4(arg0->model[0]);
    arg0->func_ptr = &func_800F722C_MushroomBank;
    if (D_800F89B8_MushroomBank != 0) {
        arg0->model[1] = func_800174C0(0x9003A, 0x2B9);
        func_80025798(arg0->model[1], 0.0f, 1.0f, 0.0f);
        arg0->model[2] = func_800174C0(0x90039, 0x2B9);
        func_80025798(arg0->model[2], 0.0f, 0.0f, -100.0f);
        func_800257E4(arg0->model[2], 10.0f, 0.0f, 4.0f);
        arg0->model[3] = func_800174C0(0x90037, 0x2B9);
        func_80025798(arg0->model[3], 150.0f, 0.0f, 220.0f);
        arg0->model[4] = func_800174C0(0x90038, 0x2B9);
        func_80025798(arg0->model[4], -50.0f, 0.0f, 230.0f);
        arg0->model[5] = func_800174C0(0x9003B, 0x2B9);
        func_80025798(arg0->model[5], -70.0f, 0.0f, 200.0f);
        func_800257E4(arg0->model[5], 0.0f, 90.0f, 0.0f);
        arg0->model[6] = func_800174C0(0x9003B, 0x2B9);
        func_80025798(arg0->model[6], -280.0f, 0.0f, 30.0f);
    }
}

void func_800F7528_MushroomBank(void) {
    CRot.x = 0.0f;
    CRot.y = 180.0f;
    CRot.z = 0.0f;
    Center.x = 0.0f;
    Center.y = 225.0f;
    Center.z = 480.0f;
    func_800F66DC_MushroomBank(0);
    func_8002890C(255, 255, 255);
    D_800F8B9C_MushroomBank = omAddObj(1, 7, 0, -1, &func_800F7308_MushroomBank);
}


void func_800F75C8_MushroomBank(s32 arg0) {
    if (arg0 < 0) {
        if (arg0 >= -3) {
            GwCommon.boardItem = arg0 + 3;
        }
    } else {
        SetBoardFeatureFlag(arg0);
    }
}

void func_800F7600_MushroomBank(s32 arg0) {
    if (arg0 >= 0) {
        ClearBoardFeatureFlag(arg0);
    }
}


// scheduling: the model id load comes before the shelf offsets (masked 14 with the unit shift)
#ifdef NON_MATCHING
void func_800F7620_MushroomBank(omObjData* obj) {
    s32 i;

    for (i = 0; i < 12; i++) {
        func_80025798((obj->model + 1)[i], obj->trans.x + D_800F89C0_MushroomBank[i].pos.x,
                      obj->trans.y + D_800F89C0_MushroomBank[i].pos.y, obj->trans.z + D_800F89C0_MushroomBank[i].pos.z);
        if (func_80059B48(D_800F89C0_MushroomBank[i].unlock) == 0 || D_800F89B8_MushroomBank != 0) {
            func_800258EC(obj->model[i + 1], 4, 4);
        } else if (func_80059B10(D_800F89C0_MushroomBank[i].reward) != 0) {
            func_800211BC(obj->model[i + 1], 200);
        } else {
            func_800211BC(obj->model[i + 1], 0);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6D_MushroomBank/2D6FC0", func_800F7620_MushroomBank);
#endif
// register: the shelf model id is sign-extended at each use instead of once (masked 19 with the unit shift)
#ifdef NON_MATCHING
void func_800F7754_MushroomBank(void) {
    omObjData* obj;
    unk_ovl_2D_struct* m;
    void* file;
    s16 model;
    u16 file16;
    s32 i;

    obj = omAddObj(1, 13, 0, -1, func_800F7620_MushroomBank);
    D_800F8BA8_MushroomBank = obj;
    obj->model[0] = LoadFormFile(0x90036, 0x2D9);
    func_80025EB4(obj->model[0], 1, 1);
    if (D_800F89B8_MushroomBank != 0) {
        func_80025CA8(obj->model[0], func_80025D40(obj->model[0]));
    }
    if (D_800F89B8_MushroomBank != 0) {
        obj->trans.x = 0.0f;
        obj->trans.y = 0.0f;
        obj->trans.z = -100.0f;
    } else {
        obj->trans.x = 0.0f;
        obj->trans.y = 400.0f;
        obj->trans.z = 0.0f;
    }
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    if (D_800F89B8_MushroomBank != 0) {
        obj->rot.x = 10.0f;
        obj->rot.y = 0.0f;
        obj->rot.z = 4.0f;
    } else {
        obj->rot.x = 0.0f;
        obj->rot.y = 0.0f;
        obj->rot.z = 0.0f;
    }
    for (i = 0; i < 12; i++) {
        file16 = LoadFormFile(D_800F89C0_MushroomBank[i].model | 0x90000, 0x2A9);
        obj->model[i + 1] = file16;
        model = file16;
        func_80025830(model, 0.6f, 0.6f, 0.6f);
        if (func_80059B48(D_800F89C0_MushroomBank[i].unlock) == 0 || D_800F89B8_MushroomBank != 0) {
            func_800258EC(model, 4, 4);
        }
        if (i != 3) {
            func_80021240(model);
        }
    }
    obj = omAddObj(1, 1, 3, -1, NULL);
    D_800F8BA4_MushroomBank = obj;
    obj->model[0] = LoadFormFile(0x9003C, 0x2A9);
    func_80025EB4(obj->model[0], 2, 2);
    obj->motion[0] = func_80025E48(obj->model[0]);
    obj->motion[1] = func_8005A22C(0x9003D);
    obj->motion[2] = func_8005A22C(0x9003E);
    m = &D_800F2B7C[obj->model[0]];
    file = DataRead(0x90041);
    func_80038A9C(m->unk_6C, file, 0, "coin_DEF");
    DataClose(file);
    func_80025AD4(obj->model[0]);
    obj->trans.x = -290.0f;
    obj->trans.y = 50.0f;
    obj->trans.z = -340.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 2.5f;
    obj->rot.x = 0.0f;
    obj->rot.y = 37.0f;
    obj->rot.z = 0.0f;
    obj = omAddObj(1, 1, 3, -1, NULL);
    D_800F8BA0_MushroomBank = obj;
    obj->model[0] = LoadFormFile(0x9003C, 0x2B9);
    func_80025EB4(obj->model[0], 2, 2);
    obj->motion[0] = func_80025E48(obj->model[0]);
    obj->motion[1] = func_8005A22C(0x9003D);
    obj->motion[2] = func_8005A22C(0x9003E);
    obj->trans.x = 290.0f;
    obj->trans.y = 50.0f;
    obj->trans.z = -340.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 2.5f;
    obj->rot.x = 0.0f;
    obj->rot.y = 323.0f;
    obj->rot.z = 0.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6D_MushroomBank/2D6FC0", func_800F7754_MushroomBank);
#endif
/* Whether prize arg0 is on the shelf. Retail's callers test the result. */
s32 func_800F7B98_MushroomBank(s32 arg0) {
    BankPrize* temp = &D_800F89C0_MushroomBank[arg0];
    return func_80059B48(temp->unlock);
}

/* The vault: the bank opens and the prize shelves come down; pick a prize with the D-pad (three
   rows of four), A takes it (or puts back one already taken), B closes the vault. Retail starts
   and cancels the teller's animation with D_800F8BA4's model and D_800F8BA0's motions (both load
   the same model file). */
// cursor-search loops rotated and registers differ (masked 105); logic checked against the asm
#ifdef NON_MATCHING
void func_800F7BC0_MushroomBank(void) {
    Vec3f pos;
    Vec3f camPos;
    Vec3f camRot;
    Vec2f scr;
    s16 win;
    s16 sprFile;
    s16 tagFile;
    s32 spr;
    s32 tag;
    s32 sel;
    s32 prev;
    s32 row;
    s32 i;
    u32 btn;
    f32 a;
    f32 x;

    prev = -1;
    sel = 0;
    func_800F66DC_MushroomBank(2);
    func_80025C20(D_800F8BA4_MushroomBank->model[0], D_800F8BA0_MushroomBank->motion[1], 0, 10, 2);
    if (func_80059CE8((_CheckFlag(3) != 0 && _CheckFlag(0x17) != 0 && _CheckFlag(0x18) == 0) ? (void*)0x2A : (void*)0xF,
                      D_800F8B94_MushroomBank) == 0) {
        func_80025C20(D_800F8BA4_MushroomBank->model[0], D_800F8BA0_MushroomBank->motion[0], 0, 10, 2);
        return;
    }
    func_80070D90(D_800F8B94_MushroomBank);
    func_80025C20(D_800F8BA4_MushroomBank->model[0], D_800F8BA4_MushroomBank->motion[2], 0, 5, 1);
    HuPrcSleep(5);
    func_8002888C(D_800F8BA4_MushroomBank->model[0], D_800F8BA4_MushroomBank->motion[2]);
    func_8005A258(D_800F8BA4_MushroomBank->model[0]);
    func_80025C20(D_800F8BA4_MushroomBank->model[0], D_800F8BA4_MushroomBank->motion[0], 0, 20, 2);
    func_800F66DC_MushroomBank(4);
    HuPrcSleep(30);
    for (i = 0; i < 10; i++) {
        D_800F8BA8_MushroomBank->trans.y -= 40.0f;
        HuPrcVSleep();
    }
    PlaySound(0x19);
    func_80060F04(0, 10, 0, 10);
    func_8004FA90(D_800F8B90_MushroomBank, 3.0f, 3.0f, 3.0f);
    for (i = 0; i < 32; i++) {
        a = i * 11.25;
        x = func_800AEAC0(a) * 280.0f;
        func_8004F9F4(D_800F8B90_MushroomBank, x, -70.0f, func_800AEFD0(a) * 280.0f, 4);
    }
    HuPrcSleep(10);
    func_80025EB4(D_800F8BA8_MushroomBank->model[0], 5, 0);
    PlaySound(0x12);
    HuPrcSleep(10);
    PlaySound(0x14);
    func_8005A258(D_800F8BA8_MushroomBank->model[0]);
    sprFile = InitSprite(0x85);
    spr = func_80019060(sprFile, 1, 1);
    func_80018D84((u16)spr, 0xFFFF);
    tagFile = InitSprite(0x90040);
    tag = func_80019060(tagFile, 0, 1);
    func_80018D84((u16)tag, 0xFFFF);
    win = func_8006D010(0x6E, 0x20, 0x64, 0x14, 0, 0);
    func_8006E070(win, 0);
    D_800F8B94_MushroomBank = func_80059C28();
    ShowBasicSprite((u16)spr);
    func_80018C90((u16)tag);
    while (!((btn = func_80059CB8()) & 0x4000)) {
        if (btn & 0x100) {
            i = sel;
            do {
                sel++;
                if ((sel == 4) | (sel == 8)) {
                    sel = i;
                    break;
                }
                if (sel == 12) {
                    sel = i;
                    break;
                }
            } while (func_800F7B98_MushroomBank(sel) == 0);
        }
        if (btn & 0x200) {
            i = sel;
            do {
                sel--;
                if ((sel == 7) | (sel == 3)) {
                    sel = i;
                    break;
                }
                if (sel == -1) {
                    sel = i;
                    break;
                }
            } while (func_800F7B98_MushroomBank(sel) == 0);
        }
        if ((btn >> 10) & 1 & (sel < 8)) {
            i = sel;
            for (sel = i + 4; sel < 12; sel += 4) {
                row = sel;
                do {
                    if (func_800F7B98_MushroomBank(sel) != 0) {
                        break;
                    }
                    sel++;
                    if (sel == 8) {
                        sel = 4;
                    }
                    if (sel == 12) {
                        sel = 8;
                    }
                } while (row != sel);
                if (func_800F7B98_MushroomBank(sel) != 0) {
                    goto down_done;
                }
            }
            sel = i;
        }
    down_done:
        if ((btn >> 11) & 1 & (sel >= 4)) {
            i = sel;
            for (sel = i - 4; sel >= 0; sel -= 4) {
                row = sel;
                do {
                    if (func_800F7B98_MushroomBank(sel) != 0) {
                        break;
                    }
                    sel--;
                    if (sel == 3) {
                        sel = 7;
                    }
                    if (sel == -1) {
                        sel = 3;
                    }
                } while (row != sel);
                if (func_800F7B98_MushroomBank(sel) != 0) {
                    goto up_done;
                }
            }
            sel = i;
        }
    up_done:
        if (btn & 0x8000) {
            if (func_80059B10(D_800F89C0_MushroomBank[sel].reward) != 0) {
                PlaySound(0xF8);
                prev = -1;
                func_800F7600_MushroomBank(D_800F89C0_MushroomBank[sel].reward);
            } else {
                PlaySound(0xF6);
                func_80018C90((u16)spr);
                camPos.x = D_800F8BA8_MushroomBank->trans.x + D_800F89C0_MushroomBank[sel].pos.x;
                camPos.y = D_800F8BA8_MushroomBank->trans.y + D_800F89C0_MushroomBank[sel].pos.y + 35.0f;
                camPos.z = D_800F8BA8_MushroomBank->trans.z + D_800F89C0_MushroomBank[sel].pos.z + 170.0f;
                D_800ED610 = &camPos;
                D_800ED72C = &D_800F8914_MushroomBank[4];
                func_8006E288(D_800F8B94_MushroomBank, 7);
                if (sel == 3) {
                    if (func_80059CE8((void*)0x20, D_800F8B94_MushroomBank) != 0) {
                        D_800F89BC_MushroomBank = 1;
                        while (1) {
                            HuPrcVSleep();
                        }
                    }
                } else if (func_80059CE8((void*)0x12, D_800F8B94_MushroomBank) != 0) {
                    func_800F75C8_MushroomBank(D_800F89C0_MushroomBank[sel].reward);
                }
                ShowBasicSprite((u16)spr);
                prev = -1;
            }
        }
        if (prev != sel) {
            if (prev != -1) {
                PlaySound(0xF5);
            }
            func_80070D90(D_800F8B94_MushroomBank);
            prev = sel;
            D_800F8B94_MushroomBank = func_80059C28();
            LoadStringIntoWindow(D_800F8B94_MushroomBank, (void*)(s32)D_800F89C0_MushroomBank[sel].nameMsg, -1, -1);
            func_8006EB40(win);
            LoadStringIntoWindow(win, (void*)(s32)D_800F89C0_MushroomBank[sel].descMsg, -1, -1);
        }
        pos.x = D_800F8BA8_MushroomBank->trans.x + D_800F89C0_MushroomBank[sel].pos.x;
        pos.y = D_800F8BA8_MushroomBank->trans.y + D_800F89C0_MushroomBank[sel].pos.y;
        pos.z = D_800F8BA8_MushroomBank->trans.z + D_800F89C0_MushroomBank[sel].pos.z;
        Convert3DTo2D(0, &pos, &scr);
        SetBasicSpritePos((u16)spr, scr.x - 24.0f, scr.y - 8.0f);
        SetBasicSpritePos((u16)tag, scr.x - 38.0f, scr.y - 24.0f);
        if (func_80059B10(D_800F89C0_MushroomBank[sel].reward) != 0) {
            ShowBasicSprite((u16)tag);
        } else {
            func_80018C90((u16)tag);
        }
        camRot.x = (sel / 4) * 5.0f + D_800F8914_MushroomBank[4].x - 5.0f;
        camRot.y = D_800F8914_MushroomBank[4].y;
        camRot.z = D_800F8914_MushroomBank[4].z;
        D_800ED610 = &D_800F88C0_MushroomBank[4];
        D_800ED72C = &camRot;
        HuPrcVSleep();
    }
    func_800F66DC_MushroomBank(4);
    PlaySound(0xF8);
    func_80070D90(win);
    func_80070D90(D_800F8B94_MushroomBank);
    func_800191F8((u16)spr);
    func_80067704(tagFile);
    func_800191F8((u16)tag);
    func_80067704(sprFile);
    func_80025EB4(D_800F8BA8_MushroomBank->model[0], 4, 4);
    HuPrcSleep(10);
    PlaySound(0x16);
    HuPrcSleep(10);
    PlaySound(0x17);
    HuPrcSleep(20);
    for (i = 0; i < 20; i++) {
        D_800F8BA8_MushroomBank->trans.y += 20.0f;
        HuPrcVSleep();
    }
    D_800F8B94_MushroomBank = func_80059C28();
    func_800F66DC_MushroomBank(0);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6D_MushroomBank/2D6FC0", func_800F7BC0_MushroomBank);
#endif
/* The star count talk: coins, stars and stars still needed for 100, then a message by count. */
void func_800F85D8_MushroomBank(void) {
    char coins[8];
    char stars[8];
    char left[8];

    func_800F66DC_MushroomBank(3);
    func_80025C20(D_800F8BA0_MushroomBank->model[0], D_800F8BA0_MushroomBank->motion[1], 0, 10, 2);
    func_8006EB40(D_800F8B94_MushroomBank);
    sprintf(coins, "%d", GwCommon.coinNum);
    func_8006DA5C(D_800F8B94_MushroomBank, coins, 0);
    sprintf(stars, "%d", GwCommon.starNum);
    func_8006DA5C(D_800F8B94_MushroomBank, stars, 1);
    sprintf(left, "%d", 100 - GwCommon.starNum);
    func_8006DA5C(D_800F8B94_MushroomBank, left, 2);
    if (GwCommon.starNum >= 100) {
        if (_CheckFlag(3) != 0 && _CheckFlag(0x17) != 0) {
            if (_CheckFlag(0x18) != 0) {
                LoadStringIntoWindow(D_800F8B94_MushroomBank, (void*)0x28, -1, -1);
            } else {
                sprintf(stars, "0");
                func_8006DA5C(D_800F8B94_MushroomBank, stars, 1);
                LoadStringIntoWindow(D_800F8B94_MushroomBank, (void*)0x29, -1, -1);
            }
        } else {
            LoadStringIntoWindow(D_800F8B94_MushroomBank, (void*)0x2B, -1, -1);
        }
    } else {
        if (GwCommon.starNum < 21) {
            func_8006DA5C(D_800F8B94_MushroomBank, (void*)0x23, 3);
        } else if (GwCommon.starNum < 41) {
            func_8006DA5C(D_800F8B94_MushroomBank, (void*)0x24, 3);
        } else if (GwCommon.starNum < 61) {
            func_8006DA5C(D_800F8B94_MushroomBank, (void*)0x25, 3);
        } else if (GwCommon.starNum < 81) {
            func_8006DA5C(D_800F8B94_MushroomBank, (void*)0x26, 3);
        } else {
            func_8006DA5C(D_800F8B94_MushroomBank, (void*)0x27, 3);
        }
        LoadStringIntoWindow(D_800F8B94_MushroomBank, (void*)0x13, -1, -1);
    }
    while (func_8006FCC0(D_800F8B94_MushroomBank) != 0) {
        HuPrcVSleep();
    }
    func_80025C20(D_800F8BA0_MushroomBank->model[0], D_800F8BA0_MushroomBank->motion[2], 0, 5, 1);
    HuPrcSleep(5);
    func_8002888C(D_800F8BA0_MushroomBank->model[0], D_800F8BA0_MushroomBank->motion[2]);
    func_8005A258(D_800F8BA0_MushroomBank->model[0]);
    func_80025C20(D_800F8BA0_MushroomBank->model[0], D_800F8BA0_MushroomBank->motion[0], 0, 20, 2);
}