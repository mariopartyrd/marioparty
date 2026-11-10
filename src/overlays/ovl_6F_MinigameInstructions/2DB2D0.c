#include "ovl6f.h"


void func_800F6610_MinigameInstructions(void) {
    omObjData* obj;
    s32 i;

    InitCameras(1);
    func_80029090(1);
    func_8001DE70(0x19);
    omInitObjMan(0x32, 0x14);
    func_80060088();
    func_8006CEA0();
    omSysPauseEnableFlag = 1;
    D_8010F766_MinigameInstructions = GwSystem.unk_1E;
    D_8010F760_MinigameInstructions = D_8010E4F0_MinigameInstructions[GwSystem.unk_1E].unk_04;
    if (_CheckFlag(0x2B) != 0) {
        func_8010E090_MinigameInstructions((s16) D_8010F766_MinigameInstructions);
    } else {
        func_800F9E64_MinigameInstructions((s16) D_8010F766_MinigameInstructions);
    }
    func_800593AC(-1);
    D_8010F4E0_MinigameInstructions = _CheckFlag(0x45);
    if (GwSystem.minigameExplanation == 1) {
        func_800F6990_MinigameInstructions();
        return;
    }
    obj = omAddObj(0x7FDA, 0U, 0U, -1, func_800F92D4_MinigameInstructions);
    omSetStatBit(obj, 0xA0);
    omAddObj(0x2710, 0U, 0U, -1, &func_800F9440_MinigameInstructions);
    CRot.x = 0.0f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    CZoom = 2000.0f;
    Center.x = Center.y = Center.z = 0.0f;
    func_8001D494(0, 10.0f, 80.0f, 8000.0f);
    func_800F92D4_MinigameInstructions(obj);
    func_80023448(3);
    func_800234B8(0U, 0x78U, 0x78U, 0x78U);
    func_800234B8(1U, 0x40U, 0x40U, 0x60U);
    func_80023504(1, -100.0f, 100.0f, 100.0f);
    func_800234B8(2U, 0U, 0U, 0U);
    func_800234B8(3U, 0U, 0U, 0U);
    D_8010F404_MinigameInstructions = omAddObj(0x3E8, 0xAU, 0xAU, -1, &func_800F692C_MinigameInstructions);
    omAddPrcObj(func_800F6B14_MinigameInstructions, 0x3F00U, 0x800, 0);
    omAddPrcObj(func_800FA470_MinigameInstructions, 0x3F00U, 0x800, 0);
    D_8010F400_MinigameInstructions = 0;
    D_8010F402_MinigameInstructions = 0;
    D_8010F764_MinigameInstructions = -1;
    D_8010F408_MinigameInstructions = -1;
    D_8010F4E2_MinigameInstructions = -1;

    for (i = 0; i < MAX_PLAYERS; i++) {
        if (GwPlayer[i].group == 0) {
            break;
        }
    }
    D_8010F772_MinigameInstructions = i;
    omAddPrcObj(func_800F9110_MinigameInstructions, 0x3F00, 0x800, 0);
    func_8007B168(D_8010F050_MinigameInstructions, 0);
    func_8007FAC0();
    D_8010F4E4_MinigameInstructions = func_80023684(0x1040, 0x7918);
}


void func_800F6924_MinigameInstructions(void) {
}

void func_800F692C_MinigameInstructions(omObjData* obj) {
    *obj->model = -1;
    obj->func_ptr = func_800F6948_MinigameInstructions;
}
void func_800F6948_MinigameInstructions(omObjData* obj) {
    if (D_8010F400_MinigameInstructions == 1) {
        if (D_8010F408_MinigameInstructions != -1) {
            func_80072080(D_8010F408_MinigameInstructions);
        }
        func_800F6990_MinigameInstructions();
    }
}
void func_800F6990_MinigameInstructions(void) {
    func_80070ED4();
    if (_CheckFlag(0x2B) != 0) {
        if (_CheckFlag(0x2D) == 0) {
            omOvlCallEx(D_8010E4F0_MinigameInstructions[(s16) D_8010F766_MinigameInstructions].overlay, 0, 0x14);
            omOvlHisChg(1, 0x7D, 0, 0x92);
            return;
        }
    } else if (_CheckFlag(0x2C) != 0 || _CheckFlag(0x30) != 0) {
        if (D_8010F4E0_MinigameInstructions == 0 && _CheckFlag(0x29) == 0) {
            omOvlCallEx(D_8010E4F0_MinigameInstructions[(s16) D_8010F766_MinigameInstructions].overlay, 0, 0x14);
            omOvlHisChg(1, 0x7B, 0, 0x92);
            return;
        }
    } else if (D_8010F4E0_MinigameInstructions == 0 && _CheckFlag(0x29) == 0) {
        omOvlCallEx(D_8010E4F0_MinigameInstructions[(s16) D_8010F766_MinigameInstructions].overlay, 0, 0x14);
        omOvlHisChg(1, 0x7C, 0, 0x14);
        return;
    }
    omOvlGotoEx(D_8010E4F0_MinigameInstructions[(s16) D_8010F766_MinigameInstructions].overlay, 0, 0x14);
}
const u8 D_8010F050_MinigameInstructions[] __attribute__((section(".rodata"))) = { 0x82, 0xA0, 0x83, 0x41, 0x81, 0x49, 0x00 };

// one delay slot: retail's branch to count = 37 is bnez, this is bnezl (masked 1)
#ifdef NON_MATCHING
void func_800F6B14_MinigameInstructions(void) {
    Vec2f in;
    Vec3f out;
    Process* proc;
    u16 model;
    u16 deco;
    s16 count;
    s16 alpha;
    s16 i;
    s16 j;
    f32 scale;
    f32 rot;
    f32 step;
    f32 t;

    scale = 0.0f;
    model = 0;
    if (D_8010F4E0_MinigameInstructions == 0 && _CheckFlag(0x2D) == 0) {
        model = LoadFormFile(0x90006, 0x289);
        func_80021240(model);
        func_80025B34(model);
        func_800211BC(model, 0xFF);
        func_80025EB4(model, 2, 2);
        func_80025930(model, 0x600, 0x200);
        SetFadeInTypeAndTime(0, 16);
        scale = 0.1f;
        func_80025830(model, scale, scale, scale);
        PlaySound(0x38);
        count = 0;
        do {
            count++;
            HuPrcVSleep();
            scale += 0.2f;
            func_80025830(model, scale, scale, scale);
        } while (scale < 2.0f);
        step = 1.0f;
        rot = 0.0f;
        do {
            count++;
            HuPrcVSleep();
            scale += 0.1f;
            rot += step;
            step += 1.0f;
            func_80025830(model, scale, scale, scale);
            func_800257E4(model, -rot, 0.0f, 0.0f);
        } while (rot < 180.0f);
    } else {
        count = 37;
    }
    HuPrcSleep(38 - count);
    func_80060128(0x15);
    D_8010F40A_MinigameInstructions = func_80019060((s16) InitSprite(0xB0002), 0, 1);
    SetBasicSpritePos(D_8010F40A_MinigameInstructions, 160, 120);
    SetBasicSpriteSize(D_8010F40A_MinigameInstructions, 2.0f, 2.0f);
    func_80018D44(D_8010F40A_MinigameInstructions, 0x4008);
    deco = LoadFormFile(0xB000A, 0x299);
    in.x = 160.0f;
    in.y = 281.0f;
    func_8001DD24(0, CZoom, (Vec3f*) &in, &out);
    func_80025798(deco, out.x, out.y, 57.0f);
    func_80025830(deco, 2.1f, 2.1f, 2.1f);
    deco = LoadFormFile(0xB000B, 0x299);
    in.x = 160.0f;
    in.y = 280.0f;
    func_8001DD24(0, CZoom + -130.0f, (Vec3f*) &in, &out);
    func_80025798(deco, out.x, out.y, -130.0f);
    func_80025830(deco, 2.2f, 2.2f, 2.2f);
    if (D_8010F4E0_MinigameInstructions == 0 && _CheckFlag(0x2D) == 0) {
        alpha = 255;
        do {
            HuPrcVSleep();
            scale += 0.2f;
            func_80025830(model, scale, scale, scale);
            alpha -= 20;
            func_800211BC(model, alpha);
        } while (alpha > 0);
        func_8002456C(model);
    } else {
        if (_CheckFlag(0x2D) != 0) {
            SetFadeInTypeAndTime(0, 16);
        } else {
            SetFadeInTypeAndTime(3, 16);
        }
    }
    model = LoadFormFile(0xB0004, 0x289);
    func_80025EB4(model, 2, 2);
    func_80025830(model, 0.0f, 0.0f, 0.0f);
    omAddPrcObj(func_800F7398_MinigameInstructions, 0x3F00, 0x800, 0);
    omAddPrcObj(func_800F785C_MinigameInstructions, 0x3F00, 0x800, 0);
    omAddPrcObj(func_800F7C58_MinigameInstructions, 0x3F00, 0x800, 0);
    proc = omAddPrcObj(func_800F8ED4_MinigameInstructions, 0x3F00, 0x800, 0);
    proc->user_data = func_80023684(0x14, 0x7918);
    func_800F8980_MinigameInstructions(D_8010F766_MinigameInstructions);
    HuPrcVSleep();
    D_8010F4E8_MinigameInstructions = 0;
    for (i = 0; i < 16; i++) {
        HuPrcVSleep();
        in.x = 80.0f;
        in.y = 55.0f;
        func_8001DD24(0, CZoom, (Vec3f*) &in, &out);
        t = i;
        t /= 15.0f;
        out.x = t * out.x;
        out.y = t * out.y;
        func_80025798(model, out.x, out.y, 0.0f);
        t *= 0.3f;
        func_80025830(model, t, t, t);
    }
    while (D_8010F4E8_MinigameInstructions < 2) {
        HuPrcVSleep();
    }
    rot = 0.0f;
    do {
        HuPrcVSleep();
        rot += 18.0f;
        func_800257E4(model, 0.0f, rot, 0.0f);
    } while (rot <= 180.0);
    HuPrcSleep(4);
    func_800F8E3C_MinigameInstructions();
    if (D_8010E4F0_MinigameInstructions[(s16) D_8010F766_MinigameInstructions].unk_10 == 0) {
        GMesMaxTimeGet(GMesCreate(6, "\x82\xA9\x82\xA2\x82\xCD\x82\xC2\x82\xBF\x82\xE3\x82\xA4" /* kaihatsu-chuu */, 0xA0, 0x78, 2.0, 2.0, 0), 0x7D00);
    }
    do {
        HuPrcVSleep();
    } while (D_8010F764_MinigameInstructions != 0);
    in.x = 90.0f;
    in.y = 50.0f;
    for (i = 0; i < 10; i++) {
        HuPrcVSleep();
        for (j = 0; j < 2; j++) {
            if (D_8010F410_MinigameInstructions[j].unk_08 != -1) {
                D_8010F410_MinigameInstructions[j].unk_54 -= 0.4f;
                D_8010F410_MinigameInstructions[j].unk_58 -= 1.6f;
                func_80066DC4(D_8010F410_MinigameInstructions[j].unk_14[D_8010F410_MinigameInstructions[j].unk_08], 0,
                              D_8010F410_MinigameInstructions[j].unk_54, D_8010F410_MinigameInstructions[j].unk_58);
            }
        }
        in.x -= 0.4f;
        in.y -= 1.6f;
        func_8001DD24(0, CZoom, (Vec3f*) &in, &out);
        func_80025798(model, out.x, out.y, 0.0f);
    }
    while (1) {
        HuPrcVSleep();
    }
}
#else
/* the string the C version above emits as a literal */
const char D_8010F058_MinigameInstructions[] __attribute__((section(".rodata"))) =
    "\x82\xA9\x82\xA2\x82\xCD\x82\xC2\x82\xBF\x82\xE3\x82\xA4";
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F6B14_MinigameInstructions);
#endif
// loop-invariant order: (s16)model is hoisted before the float constants (masked 2)
#ifdef NON_MATCHING
void func_800F7398_MinigameInstructions(void) {
    Vec2f in;
    Vec3f out;
    u16 model;
    s16 i;
    s16 j;
    f32 t;
    f32 u;
    f32 z;

    model = LoadFormFile(0xB0008, 0x289);
    func_80025830(model, 0.0f, 0.0f, 0.0f);
    func_80025EB4(model, 2, 2);
    func_800F94E8_MinigameInstructions(model, D_8010F766_MinigameInstructions);
    HuPrcSleep(13);
    for (i = 0; i < 16; i++) {
        HuPrcVSleep();
        func_800211BC(model, 0xFF);
        in.x = 290.0f;
        in.y = 54.0f;
        func_8001DD24(0, CZoom - 300.0f, (Vec3f*) &in, &out);
        t = i;
        t /= 15.0f;
        out.x = t * out.x;
        out.y = t * out.y;
        func_80025798(model, out.x, out.y, -300.0f);
        z = t * 0.8f;
        func_80025830(model, z, z, z);
    }
    D_8010F4E8_MinigameInstructions++;
    while (D_8010F4E8_MinigameInstructions < 2) {
        HuPrcVSleep();
    }
    for (i = 0; i < 11; i++) {
        HuPrcVSleep();
        u = i / 10.0f;
        func_800257E4(model, u * -10.0f, u * 149.0f, 0.0f);
    }
    do {
        HuPrcVSleep();
    } while (D_8010F764_MinigameInstructions != 0);
    if (D_8010F760_MinigameInstructions == 0) {
        func_80060F04(D_8010F772_MinigameInstructions, 10, 0, 10);
    } else {
        for (j = 0; j < 4; j++) {
            func_80060F04(j, 10, 0, 10);
        }
    }
    z = -300.0f;
    for (i = 0; i < 30; i++) {
        HuPrcVSleep();
        t = i;
        u = ((30.0f - t) / 40.0f) * -10.0f;
        t /= 30.0f;
        func_800257E4(model, u, t * 31.0f + 149.0f, 0.0f);
        in.x = t * -130.0f + 290.0f;
        t = t * 66.0f + 54.0f;
        in.y = t;
        func_8001DD24(0, CZoom - 300.0f, (Vec3f*) &in, &out);
        z += 20.0f;
        func_80025798(model, out.x, out.y, z);
        if (i == 10) {
            func_80060398(20);
        }
    }
    func_800726AC(0, 20);
    func_80072724(0xFF, 0xFF, 0xFF);
    func_800601D4(40);
    while (func_80072718() != 0) {
        z += 20.0f;
        func_80025798(model, out.x, out.y, z);
        HuPrcVSleep();
    }
    D_8010F400_MinigameInstructions = 1;
    while (1) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F7398_MinigameInstructions);
#endif
void func_800F785C_MinigameInstructions(void) {
    s16 mot[3];
    Vec2f in;
    Vec3f out;
    u16 model;
    s16 i;
    f32 t;
    f32 rot;
    unk2C0C0Struct50* part;

    model = LoadFormFile(0x7000A, 0x2B9);
    mot[0] = func_80023FC8(model);
    func_800258EC(mot[0], 4, 4);
    mot[1] = LoadFormFile(0x70008, 0x19);
    mot[2] = LoadFormFile(0x70009, 0x19);
    func_80025BB8(model, mot[2]);
    func_80025EB4(model, 2, 2);
    func_80025830(model, 0.0f, 0.0f, 0.0f);
    D_8010E950_MinigameInstructions = 0;
    HuPrcSleep(3);
    PlaySound(0x466);
    HuPrcSleep(2);
    PlaySound(0x50);
    for (i = 0; i < 15; i++) {
        HuPrcVSleep();
        in.x = 64.0f;
        in.y = 224.0f;
        func_8001DD24(0, CZoom, (Vec3f*) &in, &out);
        t = i / 15.0f;
        out.x = t * out.x;
        out.y = t * out.y;
        func_80025798(model, out.x, func_800AEAC0(t * 180.0f) * 50.0f + out.y, 0.0f);
        t *= 0.8f;
        func_80025830(model, t, t, t);
    }
    func_80025BB8(model, mot[1]);
    for (i = 0; i < 11; i++) {
        HuPrcVSleep();
        in.x = 64.0f;
        in.y = 224.0f;
        func_8001DD24(0, CZoom, (Vec3f*) &in, &out);
        func_80025798(model, out.x, func_800AEAC0((i / 10.0f) * 180.0f) * 50.0f + out.y, 0.0f);
    }
    func_80025BB8(model, mot[0]);
    func_80025EB4(model, 2, 2);
    D_8010F4E8_MinigameInstructions++;
    while (D_8010F4E8_MinigameInstructions < 2) {
        HuPrcVSleep();
    }
    rot = 0.0f;
    do {
        HuPrcVSleep();
        rot += 30.0f;
        func_800257E4(model, 10.0f, -rot, 0.0f);
    } while (rot < 360.0);
    part = func_80026A0C(model, "c100_1-atama");
    part->unk_44.x = -5.0f;
    part->unk_44.y = 5.0f;
    D_8010E950_MinigameInstructions = 1;
    HuPrcSleep(3);
    while (1) {
        HuPrcVSleep();
    }
}
// registers in the team loop; retail reuses one load of D_8010F4EA for the range check (masked 12)
#ifdef NON_MATCHING
void func_800F7C58_MinigameInstructions(void) {
    s32 win;
    s16 i;
    s16 max;
    s32 a;
    s32 b;
    s32 t;
    s32 chr;
    s16 allcpu;
    s16 timer;
    s16 extra;
    s16 prev;
    s16 cur;
    u8 port;

    D_8010F408_MinigameInstructions = win = func_8007194C(0x50, 0xC6, 4);
    if (D_8010F760_MinigameInstructions == 2) {
        for (i = 0, max = 0; i < 4; i++) {
            if (max < GwPlayer[i].group) {
                max = GwPlayer[i].group;
            }
        }
        if (max < 2) {
            a = 0;
            b = 2;
            for (i = 0; i < 4; i++) {
                if (GwPlayer[i].group == 0) {
                    func_8006DA5C(win, (void*) (s32) (GwPlayer[i].character + 0x2C), a);
                } else {
                    func_8006DA5C(win, (void*) (s32) (GwPlayer[i].character + 0x2C), b);
                }
            }
        } else {
            for (i = 0; i < 4; i++) {
                func_8006DA5C(win, (void*) (s32) (GwPlayer[i].character + 0x2C), GwPlayer[i].group);
            }
        }
    } else if (D_8010F760_MinigameInstructions == 3) {
        a = 0;
        b = 1;
        for (i = 0; i < 4; i++) {
            if (GwPlayer[i].group == 0) {
                chr = GwPlayer[i].character;
                t = a++;
            } else {
                chr = GwPlayer[i].character;
                t = b++;
            }
            func_8006DA5C(win, (void*) (s32) (chr + 0x2C), t);
        }
    } else {
        for (i = 0; i < 4; i++) {
            func_8006DA5C(win, (void*) (s32) (GwPlayer[i].character + 0x2C), GwPlayer[i].group);
        }
    }
    if (D_8010F760_MinigameInstructions != 0) {
        for (i = 0; i < 4; i++) {
            if (!(GwPlayer[i].flags & 1)) {
                break;
            }
        }
        allcpu = (i == 4);
    } else {
        allcpu = GwPlayer[D_8010F772_MinigameInstructions].flags & 1;
    }
    D_8010F4EA_MinigameInstructions = 1;
    omAddPrcObj(func_800F84B0_MinigameInstructions, 0x3F00, 0x800, 0);
    HuPrcSleep(30);
    func_8006E288(win, 1);
    LoadStringIntoWindow(win, (void*) (s32) func_800F885C_MinigameInstructions(D_8010F766_MinigameInstructions), -1, -1);
    while (D_8010E950_MinigameInstructions == 0) {
        HuPrcVSleep();
    }
    func_80071C8C((s16) win, 1);
    extra = D_8010E4F0_MinigameInstructions[(s16) D_8010F766_MinigameInstructions].unk_0E;
    timer = 60;
    while (1) {
        HuPrcVSleep();
        if (D_8010F400_MinigameInstructions == 1) {
            break;
        }
        prev = D_8010F4EA_MinigameInstructions;
        if (D_8010F760_MinigameInstructions == 0) {
            port = GwPlayer[D_8010F772_MinigameInstructions].port;
            if (ContBtnTrg[port] & 2) {
                cur = D_8010F4EA_MinigameInstructions;
                D_8010F4EA_MinigameInstructions = cur - 1;
                if (extra != 0 && D_8010F4EA_MinigameInstructions == 2) {
                    D_8010F4EA_MinigameInstructions = cur - 2;
                }
            } else if (ContBtnTrg[port] & 1) {
                cur = D_8010F4EA_MinigameInstructions;
                D_8010F4EA_MinigameInstructions = cur + 1;
                if (extra != 0 && D_8010F4EA_MinigameInstructions == 2) {
                    D_8010F4EA_MinigameInstructions = cur + 2;
                }
            }
            if (ContBtnTrg[port] & 0x1000) {
                D_8010F764_MinigameInstructions = 0;
            }
        } else {
            for (i = 0; i < 4; i++) {
                if (ContBtnTrg[i] & 2) {
                    cur = D_8010F4EA_MinigameInstructions;
                    D_8010F4EA_MinigameInstructions = cur - 1;
                    if (extra != 0 && D_8010F4EA_MinigameInstructions == 2) {
                        D_8010F4EA_MinigameInstructions = cur - 2;
                    }
                    break;
                }
                if (ContBtnTrg[i] & 1) {
                    cur = D_8010F4EA_MinigameInstructions;
                    D_8010F4EA_MinigameInstructions = cur + 1;
                    if (extra != 0 && D_8010F4EA_MinigameInstructions == 2) {
                        D_8010F4EA_MinigameInstructions = cur + 2;
                    }
                    break;
                }
                if (ContBtnTrg[i] & 0x1000) {
                    D_8010F764_MinigameInstructions = 0;
                }
            }
        }
        if (allcpu != 0) {
            timer--;
            if (timer <= 0) {
                D_8010F764_MinigameInstructions = 0;
            }
        }
        if (D_8010F764_MinigameInstructions == 0) {
            break;
        }
        if (D_8010F4EA_MinigameInstructions < 0) {
            if (extra != 0) {
                D_8010F4EA_MinigameInstructions = 4;
            } else {
                D_8010F4EA_MinigameInstructions = 2;
            }
        }
        if (extra == 0) {
            if (D_8010F4EA_MinigameInstructions >= 3) {
                D_8010F4EA_MinigameInstructions = 0;
            }
        } else if (D_8010F4EA_MinigameInstructions >= 5) {
            D_8010F4EA_MinigameInstructions = 0;
        }
        if (D_8010F4EA_MinigameInstructions != prev) {
            func_8006EB40(win);
            if (D_8010F4EA_MinigameInstructions == 0) {
                LoadStringIntoWindow(win, (void*) (s32) func_800F8910_MinigameInstructions(D_8010F766_MinigameInstructions), -1, -1);
            }
            if (D_8010F4EA_MinigameInstructions == 1) {
                LoadStringIntoWindow(win, (void*) (s32) func_800F885C_MinigameInstructions(D_8010F766_MinigameInstructions), -1, -1);
            }
            if (extra == 0) {
                if (D_8010F4EA_MinigameInstructions == 2) {
                    LoadStringIntoWindow(win, (void*) (s32) D_8010E4F0_MinigameInstructions[(s16) D_8010F766_MinigameInstructions].unk_0C, -1, -1);
                }
            } else {
                if (D_8010F4EA_MinigameInstructions == 3) {
                    LoadStringIntoWindow(win, (void*) (s32) D_8010E4F0_MinigameInstructions[(s16) D_8010F766_MinigameInstructions].unk_0C, -1, -1);
                }
                if (D_8010F4EA_MinigameInstructions == 4) {
                    LoadStringIntoWindow(win, (void*) (s32) (u16) D_8010E4F0_MinigameInstructions[(s16) D_8010F766_MinigameInstructions].unk_0E, -1, -1);
                }
            }
            while (func_8006FCC0(win) != 0) {
                HuPrcVSleep();
            }
        }
    }
    func_80071E80((s16) win, 1);
    while (1) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F7C58_MinigameInstructions);
#endif
void func_800F84B0_MinigameInstructions(void) {
    s16 ids[4];
    s32 pad[2]; /* retail frame is 8 bytes larger */
    TextWindow* win;
    f32 scale;
    f32 angle;
    f32 ofs;
    s16 i;
    s16 prev;
    s16 state;

    scale = 1.0f;
    win = &D_800ED4B0[D_8010F408_MinigameInstructions];
    ids[0] = func_8006DB3C(D_8010F408_MinigameInstructions, 0xB0055, 0x74, -0x2F, 0);
    ids[1] = func_8006DB3C(D_8010F408_MinigameInstructions, 0xB0056, 0x36, -0x2F, 0);
    ids[2] = func_8006DB3C(D_8010F408_MinigameInstructions, 0xB0056, 0xB2, -0x2F, 1);
    ids[3] = func_8006DB3C(D_8010F408_MinigameInstructions, 0xB0057, 0x74, -0x2F, 1);
    func_800674BC(win->unk_44, ids[3], 0x1000);
    func_8006752C(win->unk_44, ids[3], 0x100);
    func_800674F4(win->unk_44, ids[3], 0x20, 0xE, 0x71);
    for (i = 0; i < 4; i++) {
        func_80067354(win->unk_44, ids[i], win->unk_EC, win->unk_F0);
    }
    angle = 0.0f;
    while (1) {
        prev = D_8010F4EA_MinigameInstructions;
        HuPrcVSleep();
        for (i = 0; i < 4; i++) {
            func_80067354(win->unk_44, ids[i], win->unk_EC, win->unk_F0);
        }
        if (D_8010F764_MinigameInstructions == 0) {
            break;
        }
        if (prev != D_8010F4EA_MinigameInstructions) {
            state = D_8010F4EA_MinigameInstructions;
            if (state >= 3) {
                state = 2;
            }
            func_800672DC(win->unk_44, ids[3], state, 0);
            func_800672B0(win->unk_44, ids[3], 1);
        }
        angle += 15.0f;
        ofs = 2.0f * func_800AEAC0(angle);
        func_80066DC4(win->unk_44, ids[1], ofs + 54.0f, -0x2F);
        func_80066DC4(win->unk_44, ids[2], 180.0f - ofs, -0x2F);
    }
    while (scale >= 0.0f) {
        for (i = 0; i < 4; i++) {
            func_80067354(win->unk_44, ids[i], scale, scale);
        }
        scale -= 0.1f;
        HuPrcVSleep();
    }
    for (i = 0; i < 4; i++) {
        func_80067354(win->unk_44, ids[i], 0.0f, 0.0f);
    }
    while (1) {
        HuPrcVSleep();
    }
}
s16 func_800F885C_MinigameInstructions(s16 idx) {
    s16 msg;

    if (_CheckFlag(0x2B) != 0) {
        return idx + 0x35F;
    }
    msg = idx + 0x2E8;
    if (D_8010F4E0_MinigameInstructions != 0) {
        switch (idx + 1) {
        case 15:
            msg = 0x321;
            break;
        case 17:
            msg = 0x322;
            break;
        case 20:
            msg = 0x323;
            break;
        case 52:
            msg = 0x324;
            break;
        }
    }
    return msg;
}
s16 func_800F8910_MinigameInstructions(s16 idx) {
    s16 msg;

    msg = idx + 0x2AB;
    if (D_8010F4E0_MinigameInstructions != 0) {
        switch (idx + 1) {
        case 15:
            msg = 0x2E4;
            break;
        case 17:
            msg = 0x2E5;
            break;
        case 20:
            msg = 0x2E6;
            break;
        case 52:
            msg = 0x2E7;
            break;
        }
    }
    return msg;
}
// retail reaches unk_14 through its own label D_8010F424, so &D_8010F410 is not hoisted; registers differ (masked 27)
#ifdef NON_MATCHING
void func_800F8980_MinigameInstructions(s16 idx) {
    s16 cnt[4];
    s16 ids[4];
    u8* text;
    u8* start;
    u8* p;
    unkCommonStruct0* blk;
    s16 lines;
    s16 n;
    s16 font;
    s16 i;
    s16 j;
    s32 msg;

    if ((D_8010F4E0_MinigameInstructions != 0) & (idx == 0x33)) {
        msg = 0x35E;
    } else {
        msg = idx + 0x325;
    }
    lines = 0;
    text = func_8005B7E8(msg);
    start = text;
    for (p = start; *p != 0; p++) {
        if (*p == '\n') {
            lines++;
        }
    }
    D_8010F410_MinigameInstructions[0].unk_08 = D_8010F410_MinigameInstructions[1].unk_08 = -1;
    n = 0;
    cnt[0] = cnt[1] = 0;
    for (p = start; *p != 0; p++) {
        if (*p == '\n') {
            if ((p[-1] == 0x10) | (p[-1] == 0x20)) {
                p[-1] = 0;
            }
            *p = 0;
            blk = &D_8010F410_MinigameInstructions[n];
            ids[n] = font = blk->unk_08 = GMesFontCreate(blk, start, 0, -1, -1);
            D_8010F410_MinigameInstructions[n].unk_54 = 82.0f;
            D_8010F410_MinigameInstructions[n].unk_58 = 40.0f;
            func_80066DC4(D_8010F410_MinigameInstructions[n].unk_14[font], 0, D_8010F410_MinigameInstructions[n].unk_54, 40);
            cnt[n] = func_8006D93C(start);
            n++;
            start = p + 1;
        }
    }
    blk = &D_8010F410_MinigameInstructions[n];
    ids[n] = font = blk->unk_08 = GMesFontCreate(blk, start, 0, -1, -1);
    D_8010F410_MinigameInstructions[n].unk_54 = 82.0f;
    D_8010F410_MinigameInstructions[n].unk_58 = (lines != 0) ? 60.0f : 50.0f;
    func_80066DC4(D_8010F410_MinigameInstructions[n].unk_14[font], 0, D_8010F410_MinigameInstructions[n].unk_54,
                  D_8010F410_MinigameInstructions[n].unk_58);
    func_8005B838(text);
    cnt[n] = func_8006D93C(start);
    n++;
    if (cnt[0] >= 10 || cnt[1] >= 10) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < cnt[i] + 1; j++) {
                func_80067354(D_8010F410_MinigameInstructions[i].unk_14[ids[i]], j, 0.8f, 1.0f);
            }
        }
    }
    func_800F8DD0_MinigameInstructions();
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F8980_MinigameInstructions);
#endif
void func_800F8DD0_MinigameInstructions(void) {
    func_80066DC4(D_8010F410_MinigameInstructions[0].unk_14[D_8010F410_MinigameInstructions[0].unk_08], 0, 0, -200);
    if (D_8010F410_MinigameInstructions[1].unk_08 != -1) {
        func_80066DC4(D_8010F410_MinigameInstructions[1].unk_14[D_8010F410_MinigameInstructions[1].unk_08], 0, 0, -200);
    }
}
void func_800F8E3C_MinigameInstructions(void) {
    if (D_8010F410_MinigameInstructions[1].unk_08 != -1) {
        func_80066DC4(D_8010F410_MinigameInstructions[0].unk_14[D_8010F410_MinigameInstructions[0].unk_08], 0, 0x52, 0x28);
        func_80066DC4(D_8010F410_MinigameInstructions[1].unk_14[D_8010F410_MinigameInstructions[1].unk_08], 0, 0x52, 0x3C);
    } else {
        func_80066DC4(D_8010F410_MinigameInstructions[0].unk_14[D_8010F410_MinigameInstructions[0].unk_08], 0, 0x52, 0x32);
    }
}
void func_800F8ED4_MinigameInstructions(void) {
    Ovl6FSpriteWork* work = HuPrcCurrentGet()->user_data;
    f32 scale;
    f32 x;

    work->unk_0A = func_80019060((s16) InitSprite(0xB0054), 0, 1);
    work->unk_00 = 160.0f;
    work->unk_04 = 116.0f;
    SetBasicSpritePos((u16) work->unk_0A, work->unk_00, 116);
    scale = 0.0f;
    SetBasicSpriteSize(work->unk_0A, 0.0f, 0.0f);
    HuPrcSleep(0x2D);
    do {
        HuPrcVSleep();
        SetBasicSpriteSize(work->unk_0A, scale, scale);
        scale += 0.2f;
    } while (scale <= 1.0f);
    SetBasicSpriteSize(work->unk_0A, 1.0f, 1.0f);
    if (D_8010F760_MinigameInstructions != 0) {
        x = 160.0f;
        do {
            HuPrcVSleep();
            SetBasicSpritePos((u16) work->unk_0A, x, 116);
            x += 2.5f;
        } while (x <= 185.0f);
    }
    while (1) {
        if (D_8010F764_MinigameInstructions == 0) {
            func_800F9078_MinigameInstructions(work);
        }
        HuPrcVSleep();
    }
}
void func_800F9078_MinigameInstructions(Ovl6FSpriteWork* work) {
    f32 scale;

    scale = 1.0f;
    do {
        HuPrcVSleep();
        SetBasicSpriteSize(work->unk_0A, scale, scale);
        scale -= 0.1f;
    } while (scale > 0.0f);
    func_80018C90(work->unk_0A);
    while (1) {
        HuPrcVSleep();
    }
}
void func_800F9110_MinigameInstructions(void) {
    Process* proc;
    Process* child;
    Ovl6FPairS16* state;
    Ovl6FPlayerWork* work;
    s16 i;

    proc = HuPrcCurrentGet();
    state = func_80023684(4, 0x7918);
    proc->user_data = state;
    D_8010F76A_MinigameInstructions[0] = D_8010F76A_MinigameInstructions[1] = D_8010F76A_MinigameInstructions[2] =
        D_8010F76A_MinigameInstructions[3] = 0;
    if (D_8010F760_MinigameInstructions == 0) {
        child = func_8005DCD8(func_800FA540_MinigameInstructions, 0x3F00, 0x800, 0, proc);
        work = func_80023684(0xC0, 0x7918);
        child->user_data = work;
        work->unk_38 = D_8010F772_MinigameInstructions;
    } else {
        for (i = 0; i < 4; i++) {
            child = func_8005DCD8(func_800FA540_MinigameInstructions, 0x3F00, 0x800, 0, proc);
            work = D_8010F750_MinigameInstructions[i] = func_80023684(0xC0, 0x7918);
            child->user_data = work;
            work->unk_38 = i;
        }
    }
    state->unk_00 = 0;
    HuPrcSleep(0x3C);
    func_800F9264_MinigameInstructions();
    while (1) {
        HuPrcVSleep();
    }
}
void func_800F9264_MinigameInstructions(void) {
    Ovl6FPairS16* work = HuPrcCurrentGet()->user_data;

    work->unk_00 = 1;
    work->unk_02 = 0;
    do {
        HuPrcVSleep();
    } while (work->unk_02 < 4 && (D_8010F760_MinigameInstructions != 0 || work->unk_02 == 0));
    while (1) {
        HuPrcVSleep();
    }
}
void func_800F92D4_MinigameInstructions(omObjData* obj) {
    Vec3f eye;
    Vec3f at;
    Vec3f up;
    f32 rx;
    f32 ry;
    s16 i;

    rx = CRot.x;
    ry = CRot.y;
    eye.x = Center.x + func_800AEAC0(ry) * func_800AEFD0(rx) * CZoom;
    eye.y = -func_800AEAC0(rx) * CZoom + Center.y;
    eye.z = func_800AEFD0(ry) * func_800AEFD0(rx) * CZoom + Center.z;
    at.x = Center.x;
    at.y = Center.y;
    at.z = Center.z;
    up.x = func_800AEAC0(ry) * func_800AEAC0(rx);
    up.y = func_800AEFD0(rx);
    up.z = func_800AEFD0(ry) * func_800AEAC0(rx);
    for (i = 0; i < 1; i++) {
        func_8001D420(i, &eye, &at, &up);
        func_8001D57C(i);
    }
}
void func_800F9440_MinigameInstructions(omObjData* obj) {
    if (D_8010F402_MinigameInstructions != 0 || D_800F5144 != 0) {
        func_800726AC(0xFE, 4);
        obj->func_ptr = func_800F949C_MinigameInstructions;
        func_800601D4(0x28);
    }
}
void func_800F949C_MinigameInstructions(omObjData* obj) {
    if (func_80072718() == 0) {
        if (D_8010F408_MinigameInstructions != -1) {
            func_80072080(D_8010F408_MinigameInstructions);
        }
        func_80070ED4();
        omOvlReturnEx(1);
    }
}
// loop-invariant hoisting: retail keeps 32.0f, 255 and the 2^31 conversion constant inside the outer loop (masked 86)
#ifdef NON_MATCHING
void func_800F94E8_MinigameInstructions(s16 model, s16 idx) {
    Gfx* gfx;
    void* data;
    u16* img;
    unk2C0C0StructC0* mdl;
    unk2C0C0Struct30* mesh;
    Vtx* vtx;
    Vtx* vtxStart;
    s16 n;
    s16 i;
    s16 j;
    s16 k;
    s32 w;
    s16 h;
    f32 minX;
    f32 maxX;
    f32 minY;
    f32 maxY;
    f32 rangeX;
    f32 rangeY;
    f32 baseX;
    f32 baseY;
    f32 x;
    f32 y;
    f32 sLo;
    f32 sHi;
    f32 tLo;
    f32 tHi;
    s32 id;

    if (idx == 0x35) {
        if (_CheckFlag(0x33) != 0) {
            id = 0xB0051;
        } else {
            id = _CheckFlag(0x34) ? 0xB0052 : 0xB0053;
        }
    } else {
        id = D_8010E4F0_MinigameInstructions[idx].unk_08;
    }
    w = 160;
    data = DataRead(id);
    h = 128;
    img = func_80023684(0xA000, 0x7918);
    func_8007F54C(data, img, 160, D_8010F4E4_MinigameInstructions);
    DataClose(data);
    mdl = D_800F2B7C[model].unk_6C;
    n = func_80033718(mdl, "00s_012-tv");
    mesh = &mdl->unk_80[n];
    vtx = func_80023684(0x500, 0x7918);
    gfx = func_80023684(0x200 * sizeof(Gfx), 0x7918); /* 0x1000 on N64; host Gfx is 16 bytes */
    mdl->unk_00[n] = gfx;
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(gfx++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    gSPClearGeometryMode(gfx++, G_LIGHTING);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);

    maxY = maxX = -100000.0f;
    minY = minX = 100000.0f;
    for (i = 0; i < (s16) mesh->unk_04; i++) {
        for (j = 0; j < mesh->unk_34[i].unk_00; j++) {
            k = mesh->unk_34[i].unk_04[j];
            x = mdl->unk_78[k].unk_00;
            if (x < minX) {
                minX = x;
            }
            x = mdl->unk_78[k].unk_00;
            if (maxX < x) {
                maxX = x;
            }
            y = mdl->unk_78[k].unk_02;
            if (y < minY) {
                minY = y;
            }
            y = mdl->unk_78[k].unk_02;
            if (maxY < y) {
                maxY = y;
            }
        }
    }
    rangeX = maxX - minX;
    rangeY = maxY - minY;
    baseX = minX;
    baseY = minY;
    vtxStart = vtx;
    for (i = 0; i < (s16) mesh->unk_04; i++) {
        maxY = maxX = -100000.0f;
        minY = minX = 100000.0f;
        for (j = 0; j < mesh->unk_34[i].unk_00; j++) {
            k = mesh->unk_34[i].unk_04[j];
            x = (vtx->v.ob[0] = mdl->unk_78[k].unk_00);
            y = (vtx->v.ob[1] = mdl->unk_78[k].unk_02);
            vtx->v.ob[2] = mdl->unk_78[k].unk_04;
            if (x < minX) {
                minX = x;
            }
            if (maxX < x) {
                maxX = x;
            }
            if (y < minY) {
                minY = y;
            }
            if (maxY < y) {
                maxY = y;
            }
            vtx->v.cn[0] = vtx->v.cn[1] = vtx->v.cn[2] = -1;
            vtx->v.tc[0] = w * ((-x - baseX) / rangeX) * 32.0f;
            vtx->v.tc[1] = h * ((-y - baseY) / rangeY) * 32.0f;
            vtx->v.cn[3] = 0xFF;
            vtx++;
        }
        sLo = w - ((minX - baseX) / rangeX) * w;
        sHi = w - ((maxX - baseX) / rangeX) * w;
        tLo = h - ((minY - baseY) / rangeY) * h;
        if (tLo == h) {
            tLo = h - 0.1f;
        }
        tHi = h - ((maxY - baseY) / rangeY) * h;
        gDPSetTextureLUT(gfx++, G_TT_NONE);
        func_8003A060(&gfx, (s32) img, G_IM_FMT_RGBA, G_IM_SIZ_16b, w, h, (u32) sHi, (u32) tHi, (u32) sLo,
                      (u32) tLo, 0, 2, 2, 0, 0, 0, 0);
        gSPVertex(gfx++, vtxStart, mesh->unk_34[i].unk_00, 0);
        if (mesh->unk_34[i].unk_00 == 3) {
            gSP1Triangle(gfx++, 0, 1, 2, 0);
        } else {
            gSP1Quadrangle(gfx++, 0, 1, 2, 3, 0);
        }
        vtxStart = vtx;
    }
    gSPEndDisplayList(gfx++);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DB2D0", func_800F94E8_MinigameInstructions);
#endif

void func_800F9E64_MinigameInstructions(s16 idx) {
    s16 order[4] = { 0, 1, 2, 3 };
    s16 i;
    s16 tmp;
    s16 r;
    u8 g;
    u8 next;
    s16 j;
    s16 k;

    switch ((s16) (idx - 6)) {
    case 31:
        if (_CheckFlag(0x30) == 0) {
            if (rand8() & 1) {
                SetBoardFeatureFlag(0x31);
                ClearBoardFeatureFlag(0x32);
                func_800593AC(6);
            } else {
                SetBoardFeatureFlag(0x32);
                ClearBoardFeatureFlag(0x31);
                func_800593AC(8);
            }
        }
        break;
    case 0:
        SetBoardFeatureFlag(0x31);
        ClearBoardFeatureFlag(0x32);
        break;
    case 2:
        SetBoardFeatureFlag(0x32);
        ClearBoardFeatureFlag(0x31);
        break;
    case 21:
        SetBoardFeatureFlag(0x33);
        ClearBoardFeatureFlag(0x34);
        ClearBoardFeatureFlag(0x35);
        break;
    case 30:
        ClearBoardFeatureFlag(0x33);
        SetBoardFeatureFlag(0x34);
        ClearBoardFeatureFlag(0x35);
        break;
    case 47:
        ClearBoardFeatureFlag(0x33);
        ClearBoardFeatureFlag(0x34);
        SetBoardFeatureFlag(0x35);
        break;
    case 38:
    case 39:
        r = (u8) (rand8() & 3);
        next = 1;
        for (i = 0; i < 4; i++) {
            if (i == r) {
                GwPlayer[i].group = 0;
            } else {
                GwPlayer[i].group = next++;
            }
        }
        break;
    case 32:
        for (i = 0; i < 12; i++) {
            r = (u8) (rand8() & 3);
            tmp = order[r];
            order[r] = order[i & 3];
            order[i & 3] = tmp;
        }
        for (i = 0; i < 4; i++) {
            GwPlayer[i].group = order[i];
        }
        break;
    case 43:
        j = 0;
        k = 2;
        for (i = 0; i < 4; i++) {
            if (GwPlayer[i].group == 0) {
                order[j] = i;
                GwPlayer[i].group = j++;
            } else {
                order[k] = i;
                GwPlayer[i].group = k++;
            }
        }
        if (rand8() & 1) {
            g = GwPlayer[order[0]].group;
            GwPlayer[order[0]].group = GwPlayer[order[1]].group;
            GwPlayer[order[1]].group = g;
        }
        if (rand8() & 1) {
            g = GwPlayer[order[2]].group;
            GwPlayer[order[2]].group = GwPlayer[order[3]].group;
            GwPlayer[order[3]].group = g;
        }
        break;
    }
}
s16 func_800FA284_MinigameInstructions(s16 sound) {
    if (D_8010F764_MinigameInstructions == 0) {
        return -1;
    }
    return PlaySound(sound);
}
s16 func_800FA2C0_MinigameInstructions(s16 sound, Ovl6FPlayerWork* work) {
    if (D_8010F764_MinigameInstructions == 0) {
        return -1;
    }
    return func_80060540(sound, work->unk_38);
}
s16 func_800FA300_MinigameInstructions(s16 sound, Ovl6FPlayerWork* work) {
    if (D_8010F764_MinigameInstructions == 0) {
        return -1;
    }
    return func_80060540(sound + work->unk_40 + 1, work->unk_38);
}
void func_800FA350_MinigameInstructions(s16 handle, s16 arg1) {
    if (handle != -1) {
        func_80060440(handle, arg1);
    }
}
void func_800FA380_MinigameInstructions(s16 handle) {
    if (handle != -1) {
        func_8006071C(handle);
    }
}
void func_800FA3AC_MinigameInstructions(s16 kind, Ovl6FPlayerWork* work) {
    if (D_8010F764_MinigameInstructions != 0) {
        switch (kind) {
        case 0:
            func_80060F04(work->unk_38, 5, 0, 5);
            break;
        case 1:
            func_80060F04(work->unk_38, 2, 3, 10);
            break;
        case 2:
            func_80060F04(work->unk_38, 10, 0, 10);
            break;
        case 3:
            func_80060F04(work->unk_38, 20, 0, 20);
            break;
        case 4:
            func_80060F04(work->unk_38, 2, 2, 20);
            break;
        case 5:
            func_80060F04(work->unk_38, 30, 0, 30);
            break;
        }
    }
}
extern u16 ContBtn[4]; /* engine/pad.h */
extern s8 ContStkY[4];

void func_800FA470_MinigameInstructions(void) {
    s16 i;
    u8 port;

    while (1) {
        HuPrcVSleep();
        for (i = 0; i < 4; i++) {
            if (GwPlayer[i].flags & 1) {
                port = GwPlayer[i].port;
                ContBtn[port] = ContBtnTrg[port] = ContStkX[port] = ContStkY[port] = 0;
            }
        }
    }
}

/* .data */
Ovl6FMinigameInfo D_8010E4F0_MinigameInstructions[56] = {
    { 0, 0, 0xB001E, 0x39A, 0, 1 },
    { 1, 0, 0xB001F, 0x39B, 0, 1 },
    { 2, 0, 0xB0020, 0x39C, 0, 1 },
    { 3, 1, 0xB0021, 0x39D, 0, 1 },
    { 4, 1, 0xB0022, 0x39E, 0, 1 },
    { 5, 0, 0xB0023, 0x39F, 0, 1 },
    { 0x25, 1, 0xB0042, 0x3C4, 0, 1 },
    { 7, 1, 0xB0025, 0x3A1, 0, 1 },
    { 0x25, 1, 0xB0042, 0x3C4, 0, 1 },
    { 9, 3, 0xB0026, 0x3A3, 0, 1 },
    { 0xA, 0, 0xB0027, 0x3A4, 0, 1 },
    { 0xB, 1, 0xB0028, 0x3A5, 0, 1 },
    { 0xC, 0, 0xB0029, 0x3A6, 0, 1 },
    { 0xD, 1, 0xB002A, 0x3A7, 0, 1 },
    { 0xE, 1, 0xB002B, 0x3A8, 0, 1 },
    { 0xF, 0, 0xB002C, 0x3A9, 0, 1 },
    { 0x10, 3, 0xB002D, 0x3AA, 939, 1 },
    { 0x11, 3, 0xB002E, 0x3AC, 941, 1 },
    { 0x12, 0, 0xB002F, 0x3AE, 0, 1 },
    { 0x13, 1, 0xB0030, 0x3AF, 0, 1 },
    { 0x14, 1, 0xB0031, 0x3B0, 0, 1 },
    { 0x15, 3, 0xB0032, 0x3B1, 946, 1 },
    { 0x16, 1, 0xB0033, 0x3B3, 0, 1 },
    { 0x17, 1, 0xB0034, 0x3B4, 0, 1 },
    { 0x18, 1, 0xB0035, 0x3B5, 0, 1 },
    { 0x19, 0, 0xB0036, 0x3B6, 0, 1 },
    { 0x1A, 1, 0xB0037, 0x3B7, 0, 1 },
    { 0x34, 0, 0xB0051, 0x3D8, 0, 1 },
    { 0x1C, 1, 0xB0039, 0x3B9, 0, 1 },
    { 0x1D, 2, 0xB003A, 0x3BA, 0, 1 },
    { 0x1E, 1, 0xB003B, 0x3BB, 0, 1 },
    { 0x1F, 3, 0xB003C, 0x3BC, 957, 1 },
    { 0x20, 0, 0xB003D, 0x3BE, 0, 1 },
    { 0x21, 1, 0xB003E, 0x3BF, 0, 1 },
    { 0x22, 1, 0xB003F, 0x3C0, 0, 1 },
    { 0x23, 3, 0xB0040, 0x3C1, 962, 1 },
    { 0x34, 0, 0xB0052, 0x3D8, 0, 1 },
    { 0x25, 1, 0xB0042, 0x3C4, 0, 1 },
    { 0x26, 1, 0xB0043, 0x3C5, 0, 1 },
    { 0x27, 2, 0xB0044, 0x3C6, 0, 1 },
    { 0x28, 1, 0xB0045, 0x3C7, 0, 1 },
    { 0x29, 0, 0xB0046, 0x3C8, 0, 1 },
    { 0x2A, 2, 0xB0047, 0x3C9, 970, 1 },
    { 0x2B, 1, 0xB0048, 0x3CB, 0, 1 },
    { 0x2C, 1, 0xB0049, 0x3CC, 0, 1 },
    { 0x2D, 1, 0xB004A, 0x3CD, 974, 1 },
    { 0x2E, 1, 0xB004B, 0x3CF, 0, 1 },
    { 0x2F, 2, 0xB004C, 0x3D0, 0, 1 },
    { 0x34, 1, 0xB001D, 0x3D1, 0, 0 },
    { 0x30, 2, 0xB004D, 0x3D2, 979, 1 },
    { 0x31, 3, 0xB004E, 0x3D4, 981, 1 },
    { 0x32, 3, 0xB004F, 0x3D6, 0, 1 },
    { 0x33, 3, 0xB0050, 0x3D7, 0, 1 },
    { 0x34, 0, 0xB0053, 0x3D8, 0, 1 },
    { 0x24, 3, 0xB0041, 0x3D9, 986, 1 },
    { 0x1B, 1, 0xB0038, 0x3DB, 0, 1 },
};
u8 D_8010E950_MinigameInstructions = 0;
