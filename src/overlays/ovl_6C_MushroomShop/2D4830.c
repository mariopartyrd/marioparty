#include "common.h"
#include "2D4830.h"

/* .data */
Vec3f D_800F89A0_MushroomShop[3] = { { 0.0f, 100.0f, 555.0f }, { 0.0f, 105.0f, 380.0f }, { -50.0f, 100.0f, 380.0f } };
Vec3f D_800F89C4_MushroomShop[3] = { { 2.0f, 225.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 3.0f, 270.0f, 0.0f } };
Vec3f D_800F89E8_MushroomShop[2] = { { -330.0f, 150.0f, 380.0f }, { 0.0f, 100.0f, 800.0f } };
ShopMenuEntry D_800F8A00_MushroomShop[2] = { { 0, 0, 0xA3 }, { 1, 1, 0xA4 } };
ShopMgGroup D_800F8A10_MushroomShop[4] = { { D_800C4E14, 10 }, { D_800C4E24, 5 }, { D_800C4E2C, 10 }, { D_800C4E38, 25 } };
s32 D_800F8A30_MushroomShop[8] = { 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18 };
ShopItem D_800F8A50_MushroomShop[16] = {
    { 0x19, 0x9002F, 0, { -540.0f, 176.0f, -310.0f }, 70.0f, 0xAB, 0x85, 200, NULL },
    { 0x1A, 0x90030, 0, { -493.0f, 176.0f, -437.0f }, 70.0f, 0xAC, 0x86, 100, NULL },
    { 0x1B, 0x90031, 0, { -350.0f, 176.0f, -580.0f }, 21.0f, 0xAD, 0x87, 200, NULL },
    { 0x1C, 0x90032, 0, { -230.0f, 176.0f, -630.0f }, 21.0f, 0xAE, 0x88, 100, NULL },
    { 0x1D, 0x90033, 0, { -103.0f, 176.0f, -680.0f }, 21.0f, 0xAF, 0x89, 200, NULL },
    { 0x1F, 0x9004E, 0, { 95.0f, 176.0f, -675.0f }, 338.0f, 0xB1, 0x8B, 100, NULL },
    { 0x22, 0x9002D, 0, { 220.0f, 177.0f, -615.0f }, 338.0f, 0xB4, 0x8E, 50, NULL },
    { 0x23, 0x90061, 0, { 350.0f, 176.0f, -570.0f }, 338.0f, 0xB5, 0x8F, 50, NULL },
    { 0x24, 0x90027, 0, { 488.0f, 176.0f, -431.0f }, 290.0f, 0xB6, 0x90, 400, NULL },
    { 0x25, 0x90028, 0, { 535.0f, 176.0f, -331.0f }, 290.0f, 0xB7, 0x91, 300, NULL },
    { 0x1E, 0x90034, 0, { -350.0f, 335.0f, -580.0f }, 21.0f, 0xB0, 0x8A, 200, NULL },
    { 0x20, 0x90025, 0, { -230.0f, 335.0f, -630.0f }, 21.0f, 0xB2, 0x8C, 500, func_800F6F48_MushroomShop },
    { 0x21, 0x90026, 0, { -102.0f, 335.0f, -680.0f }, 21.0f, 0xB3, 0x8D, 500, func_800F6F48_MushroomShop },
    { 0x26, 0x90029, 0, { 95.0f, 335.0f, -675.0f }, 338.0f, 0xB8, 0x92, 300, func_800F6E94_MushroomShop },
    { 0x27, 0x9002B, 0, { 210.0f, 335.0f, -600.0f }, 338.0f, 0xB9, 0x93, 980, func_800F6FA8_MushroomShop },
    { 0x28, 0x9002C, 0, { 350.0f, 335.0f, -570.0f }, 338.0f, 0xBA, 0x94, 100, func_800F6F48_MushroomShop },
};

void func_800F65E0_MushroomShop(void) {
    InitCameras(1);
    omInitObjMan(0x20, 4);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, &func_80059EBC), 0xA0);
    D_800F384C = 0;
    func_8006CEA0();
    func_800F6C58_MushroomShop();
    func_800F73C8_MushroomShop();
    D_800F8D74_MushroomShop = omAddPrcObj(func_800F688C_MushroomShop, 0xA, 0, 0);
    func_8007B168("\x82\xA0\x83\x41\x81\x49\x00", 0);
    D_800F8DE2_MushroomShop = InitSprite(0xA0013);
    D_800F8DE4_MushroomShop = func_80019060(D_800F8DE2_MushroomShop, 0, 1);
    SetBasicSpriteSize(D_800F8DE4_MushroomShop, 0.5f, 0.5f);
    SetBasicSpritePos(D_800F8DE4_MushroomShop, 0x20, 0x18);
    D_800F8DE0_MushroomShop = GMesFontCreate(D_800F8D78_MushroomShop, "00000", 0, -1, -1);
    omAddObj(1, 0, 0, -1, &func_800F67B0_MushroomShop);
    func_80066DC4(D_800F8D8C_MushroomShop[D_800F8DE0_MushroomShop], 0, 0x4C, 0x18);
    SetFadeInTypeAndTime(0xFF, 8);
    func_8005AF60();
    D_800F8D70_MushroomShop = func_80059C28();
    func_80060128(6);
}

void func_800F6778_MushroomShop(s32 arg0) {
    D_800ED610 = &D_800F89A0_MushroomShop[arg0];
    D_800ED72C = &D_800F89C4_MushroomShop[arg0];
}

void func_800F67B0_MushroomShop(void) {
    s32 i;
    s32 var_s0;
    s32 var_s1;

    var_s1 = 0x2710;
    var_s0 = GwCommon.coinNum;
    
    for (i = 1; i < 6; i++) {
        func_80067208(D_800F8D8C_MushroomShop[D_800F8DE0_MushroomShop], i, D_800F3B74, var_s0 / var_s1);
        var_s0 = var_s0 % var_s1;
        var_s1 /= 0xA;
    }
}

void func_800F688C_MushroomShop(void) {
    Vec2f pos;
    s32 cur;
    s32 prevMsg;
    s32 spr;
    u32 btn;

    prevMsg = -1;
    cur = 0;
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
            switch (cur) {
            case 0:
                func_800F76A0_MushroomShop();
                break;
            case 1:
                if (func_80059CE8((void*)0xA5, D_800F8D70_MushroomShop) != 0) {
                    func_80025EB4(D_800F8DE8_MushroomShop->model[0], 1, 0);
                    HuPrcSleep(15);
                    D_800F5144 = 1;
                    while (1) {
                        HuPrcVSleep();
                    }
                }
                break;
            }
            if (D_800F5144 != 1) {
                prevMsg = -1;
                ShowBasicSprite((u16)spr);
            }
        }
        if ((btn >> 14) & 1 & (cur != 1)) {
            PlaySound(0xF8);
            cur = 1;
        }
        if (func_8006FCC0(D_800F8D70_MushroomShop) == 0) {
            if (btn & 0x100) {
                cur++;
                if (cur >= 2) {
                    cur = 0;
                }
            }
            if (btn & 0x200) {
                cur--;
                if (cur < 0) {
                    cur = 1;
                }
            }
        }
        if (prevMsg != D_800F8A00_MushroomShop[cur].msg) {
            D_800F384C = btn;
            if (prevMsg != -1) {
                PlaySound(0xF5);
            }
            func_8006EB40(D_800F8D70_MushroomShop);
            func_8006E288(D_800F8D70_MushroomShop, 7);
            LoadStringIntoWindow(D_800F8D70_MushroomShop, (void*)(s32)D_800F8A00_MushroomShop[cur].msg, -1, -1);
        }
        prevMsg = D_800F8A00_MushroomShop[cur].msg;
        func_800F6778_MushroomShop(D_800F8A00_MushroomShop[cur].cam);
        Convert3DTo2D(0, &D_800F89E8_MushroomShop[D_800F8A00_MushroomShop[cur].pos], &pos);
        SetBasicSpritePos((u16)spr, pos.x - 24.0f, pos.y);
        HuPrcVSleep();
    }
}
void func_800F6B68_MushroomShop(omObjData* arg0) {
    if (D_800F5144 != 0) {
        func_800601D4(0x1E);
        func_80072724(0xFF, 0xFF, 0xFF);
        func_800726AC(0, 4);
        arg0->func_ptr = &func_800F6BC4_MushroomShop;
    }
}

void func_800F6BC4_MushroomShop(void) {
    if (func_80072718() == 0) {
        func_80070ED4();
        func_8005B244();
        omOvlReturnEx(1);
    }
}

void func_800F6C00_MushroomShop(omObjData* arg0) {
    arg0->model[0] = func_800174C0(0x90051, 0x2B9);
    func_80025EB4(arg0->model[0], 1, 1);
    arg0->func_ptr = &func_800F6B68_MushroomShop;
}

void func_800F6C58_MushroomShop(void) {
    CRot.x = 0.0f;
    CRot.y = 180.0f;
    CRot.z = 0.0f;
    Center.x = 0.0f;
    Center.y = 130.0f;
    Center.z = 800.0f;
    func_800F6778_MushroomShop(0);
    func_8002890C(0xFF, 0xFF, 0xFF);
    D_800F8DE8_MushroomShop = omAddObj(1, 1, 0, -1, &func_800F6C00_MushroomShop);
}

u8 func_800F6CF8_MushroomShop(void) {
    s32 n;
    s32 i;
    s32 j;

    n = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < D_800F8A10_MushroomShop[i].count; j++) {
            n += func_8005949C(D_800F8A10_MushroomShop[i].list[j] - 1) == 0;
        }
    }
    if (n == 0) {
        return 0;
    }
    n = rand8() % n;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < D_800F8A10_MushroomShop[i].count; j++) {
            if (func_8005949C(D_800F8A10_MushroomShop[i].list[j] - 1) == 0) {
                if (n == 0) {
                    return D_800F8A10_MushroomShop[i].list[j] - 1;
                }
                n--;
            }
        }
    }
    return 0;
}
s32 func_800F6E94_MushroomShop(void) {
    s32 n;
    s32 i;
    s32 j;

    n = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < D_800F8A10_MushroomShop[i].count; j++) {
            n += func_8005949C(D_800F8A10_MushroomShop[i].list[j] - 1) != 0;
        }
    }
    return n < 30;
}
s32 func_800F6F48_MushroomShop(void) {
    s32 i;
    
    for (i = 0; i < 8; i++) {
        if (_CheckFlag(D_800F8A30_MushroomShop[i]) == 0) {
            return 1;
        }  
    }

    return 0;
}

s32 func_800F6FA8_MushroomShop(void) {
    s32 i;
    
    for (i = 0; i < 6; i++) {
        if (_CheckFlag(D_800F8A30_MushroomShop[i]) == 0) {
            return 1;
        }  
    }
    return 0;
}

s32 func_800F7008_MushroomShop(s32 arg0) {
    if (D_800F8A50_MushroomShop[arg0].locked != NULL && D_800F8A50_MushroomShop[arg0].locked() ) {
        return 0;
    }
    return _CheckFlag(D_800F8A50_MushroomShop[arg0].flag) == 0;
}

void func_800F7088_MushroomShop(omObjData* obj) {
    s32 i;

    for (i = 0; i < 16; i++) {
        func_80025798(obj->model[i + 1], D_800F8A50_MushroomShop[i].pos.x, D_800F8A50_MushroomShop[i].pos.y,
                      D_800F8A50_MushroomShop[i].pos.z);
        func_800257E4(obj->model[i + 1], 0.0f, D_800F8A50_MushroomShop[i].rotY, 0.0f);
        if (func_800F7008_MushroomShop(i) != 0) {
            func_800258EC(obj->model[i + 1], 4, 0);
        } else {
            func_800258EC(obj->model[i + 1], 4, 4);
        }
    }
}
s16 func_800F718C_MushroomShop(s32 i) {
    s16 model;
    void* file;
    s32 j;

    model = LoadFormFile(D_800F8A50_MushroomShop[i].modelFile, 0x2C9);
    if (i == 7) {
        func_80025EB4(model, 2, 2);
    } else {
        func_80025EB4(model, 1, 1);
    }
    if (i == 5) {
        func_80025830(model, 0.8f, 0.8f, 0.8f);
    }
    if (D_800F8A50_MushroomShop[i].tileFile != 0) {
        file = DataRead(D_800F8A50_MushroomShop[i].tileFile);
        D_800F8DF0_MushroomShop[0] = func_80038A9C(D_800F2B7C[model].unk_6C, file, 0, "tile01_DEF");
        D_800F8DF0_MushroomShop[1] = func_80038D5C(D_800F2B7C[model].unk_6C, D_800F8DF0_MushroomShop[0], 0, "tile02_DEF");
        D_800F8DF0_MushroomShop[2] = func_80038D5C(D_800F2B7C[model].unk_6C, D_800F8DF0_MushroomShop[0], 0, "tile04_DEF");
        D_800F8DF0_MushroomShop[3] = func_80038D5C(D_800F2B7C[model].unk_6C, D_800F8DF0_MushroomShop[0], 0, "tile06_DEF");
        func_80025AD4(model);
        DataClose(file);
        func_800396B0(D_800F8DF0_MushroomShop[1], 1);
        func_800396B0(D_800F8DF0_MushroomShop[2], 2);
        for (j = 0; j < 4; j++) {
            func_80039644(D_800F8DF0_MushroomShop[j], 1, 1);
        }
    } else {
        for (j = 0; j < 4; j++) {
            D_800F8DF0_MushroomShop[j] = -1;
        }
    }
    return model;
}
void func_800F73C8_MushroomShop(void) {
    omObjData* obj;
    s32 i;

    obj = omAddObj(1, 17, 3, -1, func_800F7088_MushroomShop);
    D_800F8DEC_MushroomShop = obj;
    obj->model[0] = LoadFormFile(0x90053, 0x2B9);
    obj->motion[0] = func_80025E48(obj->model[0]);
    obj->motion[1] = func_8005A22C(0x90054);
    obj->motion[2] = func_8005A22C(0x90055);
    func_80025EB4(obj->model[0], 2, 2);
    obj->trans.x = -330.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 380.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    obj->rot.x = 0.0f;
    obj->rot.y = 90.0f;
    obj->rot.z = 0.0f;
    for (i = 0; i < 16; i++) {
        obj->model[i + 1] = func_800F718C_MushroomShop(i);
    }
}
s16 func_800F7500_MushroomShop(s16 item) {
    u8* text;
    u8* line;
    u8* p;
    s16 n;

    text = func_8005B7E8(item + 0x325);
    line = text;
    p = text;
    for (n = 0; n < 16; n++) {
        D_800F8E34_MushroomShop[n] = D_800F8E14_MushroomShop[n] = -1;
    }
    n = 0;
    while (*p != 0) {
        if (*p == '\n') {
            *p = 0;
            D_800F8DF8_MushroomShop[n] = GMesFontCreate(&D_800F8E00_MushroomShop, line, 0, -1, -1);
            D_800F8DFC_MushroomShop[n] = func_8006D93C(line);
            n++;
            line = p + 1;
        }
        p++;
    }
    D_800F8DF8_MushroomShop[n] = GMesFontCreate(&D_800F8E00_MushroomShop, line, 0, -1, -1);
    D_800F8DFC_MushroomShop[n] = func_8006D93C(line);
    func_8005B838(text);
    return n;
}

/* The shop: pick a shelf item with the D-pad (two shelves of 10 and 6), A buys it. The surprise
   box (name 0x92) instead opens a box and gives a random unbought minigame. Retail points the
   camera globals at this frame's camPos/camRot while an item is selected; they are re-aimed
   (func_800F6778) before the next sleep after this returns. */
// register choice of one temporary at the first call (masked 0, raw 2)
#ifdef NON_MATCHING
void func_800F76A0_MushroomShop(void) {
    char buf[8];
    Vec3f pos;
    Vec3f camPos;
    Vec3f camRot;
    Vec2f scr;
    s16 win;
    s16 winSpr;
    u16 spr;
    s16 sprFile;
    TextWindow* tw;
    omObjData* item;
    omObjData* box;
    omObjData* card;
    s32 sel;
    s32 prev;
    s32 msg;
    s32 i;
    s32 j;
    s32 k;
    s32 start;
    u32 btn;
    u8 mg;
    f32 a;
    f32 x;
    f32 vy;
    f32 scale;

    sel = 0;
    prev = -1;
    msg = 0xA6;
    func_800F6778_MushroomShop(2);
    sprFile = InitSprite(0x85);
    spr = func_80019060(sprFile, 1, 1);
    func_80018C90(spr);
    func_80018D84(spr, 0xFFFF);
top:
    func_80025C20(D_800F8DEC_MushroomShop->model[0], D_800F8DEC_MushroomShop->motion[1], 0, 10, 2);
        for (i = 0, k = 0; i < 16; i++) {
            k += _CheckFlag(D_800F8A50_MushroomShop[i].flag) == 0;
        }
        if (k == 0) {
            func_8006EB40(D_800F8D70_MushroomShop);
            LoadStringIntoWindow(D_800F8D70_MushroomShop, (void*)0xA8, -1, -1);
            while (func_8006FCC0(D_800F8D70_MushroomShop) != 0) {
                HuPrcVSleep();
            }
            goto exit;
        }
        for (i = 0; i < 16; i++) {
            if (func_800F7008_MushroomShop(sel) != 0) {
                break;
            }
            sel++;
            if (sel >= 16) {
                sel = 0;
            }
        }
        if (i == 16) {
            func_8006EB40(D_800F8D70_MushroomShop);
            LoadStringIntoWindow(D_800F8D70_MushroomShop, (void*)0xA7, -1, -1);
            while (func_8006FCC0(D_800F8D70_MushroomShop) != 0) {
                HuPrcVSleep();
            }
            goto exit;
        }
        if (_CheckFlag(0x27) == 0 && func_800F6FA8_MushroomShop() == 0 && msg == 0xA6) {
            func_8006EB40(D_800F8D70_MushroomShop);
            LoadStringIntoWindow(D_800F8D70_MushroomShop, (void*)0xBB, -1, -1);
            while (func_8006FCC0(D_800F8D70_MushroomShop) != 0) {
                HuPrcVSleep();
            }
            sel = 14;
        }
        if (func_80059CE8((void*)(s32)msg, D_800F8D70_MushroomShop) == 0) {
        exit:
            func_800191F8(spr);
            func_80067704(sprFile);
            func_80025C20(D_800F8DEC_MushroomShop->model[0], D_800F8DEC_MushroomShop->motion[0], 0, 10, 2);
            return;
        }
        HuPrcVSleep();
        win = func_8006D010(0x6E, 0x20, 0x64, 0x22, 0, 0);
        tw = func_8006DD60(win);
        tw->unk_04 = 0;
        tw->unk_03 = 0;
        winSpr = tw->unk_44;
        ShowBasicSprite(spr);
        while (!((btn = func_80059CB8()) & 0x4000)) {
            if (btn & 0x100) {
                i = sel;
                sel++;
                while (((sel == 10) | (sel == 16)) == 0) {
                    if (func_800F7008_MushroomShop(sel) != 0) {
                        goto right_done;
                    }
                    sel++;
                }
                sel = i;
            }
        right_done:
            if (btn & 0x200) {
                i = sel;
                sel--;
                while (((sel == 9) | (sel == -1)) == 0) {
                    if (func_800F7008_MushroomShop(sel) != 0) {
                        goto left_done;
                    }
                    sel--;
                }
                sel = i;
            }
        left_done:
            if ((btn >> 11) & 1 & (sel < 10)) {
                start = sel;
                if (sel == 8 || sel == 9) {
                    sel = 7;
                }
                if (sel < 2) {
                    sel = 2;
                }
                sel += 8;
                for (i = 0; i < 6; i++) {
                    if (func_800F7008_MushroomShop(sel) != 0) {
                        break;
                    }
                    sel++;
                    if (sel >= 16) {
                        sel = 10;
                    }
                }
                if (i == 6) {
                    sel = start;
                }
            }
            if ((btn >> 10) & 1 & (sel >= 10)) {
                start = sel;
                sel -= 8;
                for (i = 0; i < 10; i++) {
                    if (func_800F7008_MushroomShop(sel) != 0) {
                        break;
                    }
                    sel++;
                    if (sel >= 10) {
                        sel = 0;
                    }
                }
                if (i == 10) {
                    sel = start;
                }
            }
            if (prev != sel) {
                if (prev != -1) {
                    PlaySound(0xF5);
                }
                func_80070D90(D_800F8D70_MushroomShop);
                a = (D_800F8A50_MushroomShop[sel].rotY + 180.0f) * M_DTOR;
                camPos.x = D_800F8A50_MushroomShop[sel].pos.x - sinf(a) * 370.0f;
                camPos.y = D_800F8A50_MushroomShop[sel].pos.y + 120.0f;
                camPos.z = D_800F8A50_MushroomShop[sel].pos.z - cosf(a) * 370.0f;
                camRot.x = 10.0f;
                camRot.y = D_800F8A50_MushroomShop[sel].rotY + 180.0f;
                camRot.z = 0.0f;
                D_800ED610 = &camPos;
                D_800ED72C = &camRot;
                D_800F8D70_MushroomShop = func_80059C28();
                LoadStringIntoWindow(D_800F8D70_MushroomShop, (void*)(s32)D_800F8A50_MushroomShop[sel].descMsg, -1, -1);
                func_8006EB40(win);
                func_8006DA5C(win, (void*)(s32)D_800F8A50_MushroomShop[sel].nameMsg, 0);
                sprintf(buf, "%5d", D_800F8A50_MushroomShop[sel].price);
                func_8006DA5C(win, buf, 1);
                LoadStringIntoWindow(win, "\x11\x0A\x20\x29\x78\x12", -1, -1);
            }
            prev = sel;
            if (btn & 0x8000) {
                if (D_800F8A50_MushroomShop[sel].price > GwCommon.coinNum) {
                    PlaySound(0xF9);
                    HuPrcVSleep();
                    continue;
                }
                PlaySound(0xF6);
                func_80070D90(D_800F8D70_MushroomShop);
                func_80066DC4(winSpr, 0, 320, tw->unk_16);
                func_80018C90(spr);
                func_800F6778_MushroomShop(2);
                HuPrcSleep(50);
                item = omAddObj(1, 1, 0, -1, NULL);
                item->model[0] = func_800F718C_MushroomShop(sel);
                item->trans.x = -240.0f;
                item->trans.y = 66.0f;
                item->trans.z = 240.0f;
                if (sel == 5) {
                    item->scale.x = item->scale.y = item->scale.z = 0.42f;
                } else {
                    item->scale.x = item->scale.y = item->scale.z = 0.6f;
                }
                item->rot.x = 0.0f;
                item->rot.y = 90.0f;
                item->rot.z = 0.0f;
                x = 320.0f;
                for (i = 0; i < 10; i++) {
                    x -= 14.0f;
                    func_80066DC4(winSpr, 0, x, 24);
                    item->trans.z += 10.0f;
                    HuPrcVSleep();
                }
                D_800F8D70_MushroomShop = func_80059C28();
                sprintf(buf, "%d", D_800F8A50_MushroomShop[sel].price);
                func_8006DA5C(D_800F8D70_MushroomShop, buf, 0);
                if (func_80059CE8((void*)0xA9, D_800F8D70_MushroomShop) != 0) {
                    func_80070D90(win);
                    func_80070D90(D_800F8D70_MushroomShop);
                    GwCommon.coinNum -= D_800F8A50_MushroomShop[sel].price;
                    switch (D_800F8A50_MushroomShop[sel].nameMsg) {
                    case 0x92:
                        func_80025EB4(item->model[0], 1, 0);
                        HuPrcSleep(10);
                        PlaySound(9);
                        HuPrcSleep(40);
                        box = omAddObj(1, 1, 0, -1, NULL);
                        box->model[0] = LoadFormFile(0x9002A, 0x2B9);
                        func_80025EB4(box->model[0], 1, 1);
                        box->trans.x = item->trans.x + 10.0f;
                        box->trans.y = item->trans.y + 4.87f + 15.0f;
                        box->trans.z = item->trans.z;
                        box->rot.y = 90.0f;
                        box->scale.x = box->scale.y = box->scale.z = 0.2f;
                        PlaySound(0xC);
                        for (i = 0; i < 5; i++) {
                            box->trans.y -= 3.0f;
                            HuPrcVSleep();
                        }
                        vy = 3.0f;
                        for (i = 0; i < 10; i++) {
                            box->trans.x += 3.0f;
                            vy -= 0.5f;
                            box->trans.y = vy + box->trans.y;
                            if (box->trans.y < item->trans.y + 4.87f) {
                                box->trans.y = item->trans.y + 4.87f;
                                vy -= vy * 0.6f;
                            }
                            HuPrcVSleep();
                        }
                        func_80025EB4(box->model[0], 1, 0);
                        card = omAddObj(1, 1, 0, -1, NULL);
                        card->model[0] = LoadFormFile(0x90006, 0x2B9);
                        func_80025EB4(card->model[0], 2, 2);
                        card->trans.x = box->trans.x;
                        card->trans.y = box->trans.y;
                        card->trans.z = box->trans.z;
                        card->rot.y = 270.0f;
                        scale = 0.05f;
                        card->scale.x = card->scale.y = card->scale.z = 0.0125f;
                        HuPrcSleep(10);
                        PlaySound(0xD);
                        HuPrcSleep(10);
                        mg = func_800F6CF8_MushroomShop();
                        func_80059B74(mg);
                        winSpr = func_800F7500_MushroomShop(mg);
                        PlaySound(0x11);
                        for (i = 0; i < 20; i++) {
                            card->scale.x = card->scale.y = card->scale.z = scale * 0.25f;
                            card->trans.y += 3.0f;
                            card->trans.z += 0.25f;
                            pos.x = card->trans.x;
                            pos.y = card->trans.y;
                            pos.z = card->trans.z;
                            Convert3DTo2D(0, &pos, &scr);
                            for (j = 0; j < winSpr + 1; j++) {
                                func_80066DC4(D_800F8E14_MushroomShop[D_800F8DF8_MushroomShop[j]], 0, scr.x,
                                              (j * 16 - winSpr * 8) * scale + scr.y);
                                for (k = 0; k < D_800F8DFC_MushroomShop[j]; k++) {
                                    func_80067354(D_800F8E14_MushroomShop[D_800F8DF8_MushroomShop[j]], k + 1, scale, scale);
                                }
                            }
                            scale += 0.05f;
                            HuPrcVSleep();
                        }
                        while (!(func_80059CB8() & 0x8000)) {
                            HuPrcVSleep();
                        }
                        PlaySound(0x46);
                        for (i = 0; i < 20; i++) {
                            card->scale.x = card->scale.y = card->scale.z = scale * 0.25f;
                            card->trans.y -= 3.0f;
                            card->trans.z -= 0.25f;
                            pos.x = card->trans.x;
                            pos.y = card->trans.y;
                            pos.z = card->trans.z;
                            Convert3DTo2D(0, &pos, &scr);
                            for (j = 0; j < winSpr + 1; j++) {
                                func_80066DC4(D_800F8E14_MushroomShop[D_800F8DF8_MushroomShop[j]], 0, scr.x,
                                              (j * 16 - winSpr * 8) * scale + scr.y);
                                for (k = 0; k < D_800F8DFC_MushroomShop[j]; k++) {
                                    func_80067354(D_800F8E14_MushroomShop[D_800F8DF8_MushroomShop[j]], k + 1, scale, scale);
                                }
                            }
                            scale -= 0.05f;
                            HuPrcVSleep();
                        }
                        GMesSprKill(&D_800F8E00_MushroomShop);
                        func_80025EB4(box->model[0], 1, 4);
                        PlaySound(0xF);
                        for (i = 0; i < 12; i++) {
                            item->trans.z -= 10.0f;
                            HuPrcVSleep();
                        }
                        HuPrcSleep(30);
                        func_8002456C(card->model[0]);
                        omDelObj(card);
                        vy = 6.0f;
                        for (i = 0; i < 12; i++) {
                            box->trans.x += 10.0f;
                            box->trans.y = vy + box->trans.y;
                            box->trans.z += 3.0f;
                            vy -= 2.0f;
                            HuPrcVSleep();
                        }
                        func_8002456C(box->model[0]);
                        omDelObj(box);
                        break;
                    case 0x93:
                        func_8005963C(6, 0x8000);
                    default:
                        SetBoardFeatureFlag(D_800F8A50_MushroomShop[sel].flag);
                        vy = 6.0f;
                        for (i = 0; i < 12; i++) {
                            item->trans.x += 10.0f;
                            item->trans.y = vy + item->trans.y;
                            item->trans.z += 3.0f;
                            vy -= 2.0f;
                            HuPrcVSleep();
                        }
                        break;
                    }
                    func_80060F04(0, 10, 0, 10);
                    for (i = 0; i < 4; i++) {
                        if (D_800F8DF0_MushroomShop[i] != -1) {
                            func_80039ACC(D_800F8DF0_MushroomShop[i]);
                        }
                    }
                    prev = -1;
                    func_8002456C(item->model[0]);
                    omDelObj(item);
                    msg = 0xAA;
                    func_80025C20(D_800F8DEC_MushroomShop->model[0], D_800F8DEC_MushroomShop->motion[2], 0, 10, 1);
                    HuPrcSleep(5);
                    func_8002888C(D_800F8DEC_MushroomShop->model[0], D_800F8DEC_MushroomShop->motion[2]);
                    func_8005A258(D_800F8DEC_MushroomShop->model[0]);
                    D_800F8D70_MushroomShop = func_80059C28();
                    goto top;
                }
                for (i = 0; i < 11; i++) {
                    item->trans.z -= 10.0f;
                    HuPrcVSleep();
                }
                HuPrcSleep(10);
                func_80066DC4(winSpr, 0, tw->unk_14, tw->unk_16);
                for (i = 0; i < 4; i++) {
                    if (D_800F8DF0_MushroomShop[i] != -1) {
                        func_80039ACC(D_800F8DF0_MushroomShop[i]);
                    }
                }
                prev = -1;
                func_8002456C(item->model[0]);
                omDelObj(item);
                ShowBasicSprite(spr);
            }
            pos.x = D_800F8A50_MushroomShop[sel].pos.x;
            pos.y = D_800F8A50_MushroomShop[sel].pos.y;
            pos.z = D_800F8A50_MushroomShop[sel].pos.z;
            Convert3DTo2D(0, &pos, &scr);
            SetBasicSpritePos(spr, scr.x - 32.0f, scr.y - 48.0f);
            HuPrcVSleep();
        }
        PlaySound(0xF8);
        func_80025C20(D_800F8DEC_MushroomShop->model[0], D_800F8DEC_MushroomShop->motion[0], 0, 10, 2);
        func_80070D90(win);
        func_800191F8(spr);
        func_80067704(sprFile);
        return;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6C_MushroomShop/2D4830", func_800F76A0_MushroomShop);
#endif
