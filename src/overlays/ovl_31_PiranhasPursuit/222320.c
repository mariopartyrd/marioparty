#include "PiranhasPursuit.h"

s32 D_801001F0_PiranhasPursuit = 0;
s16 D_801001F4_PiranhasPursuit = 0;
s32 D_801001F8_PiranhasPursuit = 0;
f32 D_801001FC_PiranhasPursuit = -16000.0f;
f32 D_80100200_PiranhasPursuit = 0.0f;
f32 D_80100204_PiranhasPursuit = 0.0f;
f32 D_80100208_PiranhasPursuit = 0.0f;
s32 D_8010020C_PiranhasPursuit = -1;
s32 D_80100210_PiranhasPursuit = 0;
s32 D_80100214_PiranhasPursuit = 0;
f32 D_80100218_PiranhasPursuit = 0.0f;
s32 D_8010021C_PiranhasPursuit = 0;
f32 D_80100220_PiranhasPursuit = 0.0f;
s32 D_80100224_PiranhasPursuit = 42;
const char* D_80100228_PiranhasPursuit[6] = {
    D_801004EC_PiranhasPursuit, D_801004E0_PiranhasPursuit, D_801004D4_PiranhasPursuit,
    D_801004C8_PiranhasPursuit, D_801004BC_PiranhasPursuit, D_801004B0_PiranhasPursuit,
};
s32 D_80100240_PiranhasPursuit = 42;
s32 D_80100244_PiranhasPursuit = 0;
s32 D_80100248_PiranhasPursuit = 0;
f32 D_8010024C_PiranhasPursuit = 0.0f;
u32 D_80100250_PiranhasPursuit = 0x41C64E6D;

void func_800F65E0_PiranhasPursuit(void) {
    u8 cam;
    s16 i;

    func_80029090(50);
    func_8002ADF0(&D_800EDEC0, 64);
    omInitObjMan(50, 0);
    func_80060088();
    omSetStatBit(omAddObj(32730, 0, 0, -1, omOutView), 0xA0);
    func_800178A0(1);
    cam = func_800178E8();
    func_80017660(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 45.0f, 80.0f, 8000.0f);
    D_80100E60_PiranhasPursuit = 0;
    D_800ED430 = 0;
    D_8010021C_PiranhasPursuit = _CheckFlag(0x2B);
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    D_80100CD8_PiranhasPursuit = omAddObj(4, 0, 0, -1, func_800F6AA8_PiranhasPursuit);
    func_800090B8(D_800ED440);
    D_800F2AF8[D_800ED440++] = omAddObj(2, 0, 0, -1, func_800F6BB0_PiranhasPursuit);
    omAddObj(2, 0, 0, -1, func_800F6C84_PiranhasPursuit);
    D_800F3FB0[D_800F2BC0++] = omAddObj(3, 10, 60, -1, func_800F70D0_PiranhasPursuit);
    D_800F3FB0[D_800F2BC0++] = omAddObj(3, 10, 60, -1, func_800F7158_PiranhasPursuit);
    D_800F3FB0[D_800F2BC0++] = omAddObj(3, 10, 60, -1, func_800F71F0_PiranhasPursuit);
    D_800F3FB0[D_800F2BC0++] = omAddObj(3, 10, 60, -1, func_800F7298_PiranhasPursuit);
    for (i = 0; i < 4; i++) {
        if (GwPlayer[i].group == 0) {
            D_8010020C_PiranhasPursuit = i;
            break;
        }
    }
    func_800F9D08_PiranhasPursuit();
    func_800FA0B0_PiranhasPursuit();
    D_80100CAC_PiranhasPursuit = D_800B897C;
    D_80100CB0_PiranhasPursuit = D_800B895C;
    D_80100CCC_PiranhasPursuit = D_800B8964;
    D_80100CD0_PiranhasPursuit = D_800B8968;
    D_80100CB4_PiranhasPursuit = D_800B8960;
    D_80100CC8_PiranhasPursuit = D_800B8980;
    D_80100CB8_PiranhasPursuit = D_800B8984;
    D_80100CBC_PiranhasPursuit = D_800B8988;
    D_80100CC0_PiranhasPursuit = D_800B896C;
    D_80100CC4_PiranhasPursuit = D_800B8970;
    D_80100CD4_PiranhasPursuit = D_800B8994;
    D_800B897C = 3.3333333f;
    D_800B895C = 15.0f;
    D_800B8960 = 0.5f;
    D_800B896C = 7.0f;
    D_800B8970 = 30.0f;
    D_800B8984 = 13.5f;
    D_800B8988 = 9.0f;
    D_800B8964 = 1.47f;
    D_800B8968 = 0.2f;
    D_800B8980 = 32.0f;
    D_800B8994 = 1.85f;
    SetFadeInTypeAndTime(0, 16);
}

void func_800F6AA8_PiranhasPursuit(omObjData* obj) {
    obj->func_ptr = func_800F7AA0_PiranhasPursuit;
    func_80023448(1);
    D_800EE9A0.def[0].col[0] = D_800EE9A0.def[0].col[1] = D_800EE9A0.def[0].col[2] = 0x80;
    D_800EE9A0.def[1].col[0] = D_800EE9A0.def[1].col[1] = D_800EE9A0.def[1].col[2] = 0x80;
    D_800EE9A0.def[1].dir[0] = -2;
    D_800EE9A0.def[1].dir[1] = 1;
    D_800EE9A0.def[1].dir[2] = 0x60;
    func_8007B168((u8*)"\x82\x65\x82\x6D\x82\x68\x82\x72\x82\x67", 1);
    D_80100E64_PiranhasPursuit = func_800174C0(0x450009, 0x459);
    func_80025EB4(D_80100E66_PiranhasPursuit, 2, 2);
    func_80025830(D_80100E66_PiranhasPursuit, 1.4f, 0.8f, 1.0f);
}

void func_800F6B74_PiranhasPursuit(omObjData* obj) {
    func_800F9F4C_PiranhasPursuit(obj);
    if (func_80072718() == 0) {
        func_800F9BF0_PiranhasPursuit();
        omOvlReturnEx(1);
    }
}

typedef struct PPGround {
    /* 0x00 */ char unk0[4];
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ char unk6[0x26];
} PPGround; /* size = 0x2C */

void func_800F6BB0_PiranhasPursuit(omObjData* obj) {
    PPGround* work;

    obj->func_ptr = NULL;
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 0.0f;
    obj->unk_50 = work = func_80023684(0x2C, 0x7918);
    func_8009B770(work, 0, 0x2C);
    work->unk4 = 1;
    work->unk5 = 0;
    func_80009028(obj, 0x44228000, -175.0f, -175.0f, 175.0f, 175.0f);
    func_80009090(obj);
    func_80008FC4(obj, 10.0f);
    func_80008FB8(obj, 20.0f);
}

void func_800F6C78_PiranhasPursuit(f32 x) {
    D_801001FC_PiranhasPursuit = x;
}

/* The camera: the intro pans along the course, then it follows the scroll. */
// NON_MATCHING: retail passes the camera timer's low half with lh to a u16 parameter (masked 2)
#ifdef NON_MATCHING
void func_800F6C84_PiranhasPursuit(omObjData* obj) {
    omObjData* solo;

    switch (D_801001F0_PiranhasPursuit) {
        case 0:
            func_800F9D78_PiranhasPursuit(320.0f, D_801001FC_PiranhasPursuit + -700.0, 50.0f, 0.0f, -6.25f, 0.0f,
                                          0.0f);
            if (func_80072718() == 0) {
                if (--D_80100224_PiranhasPursuit == 0) {
                    D_80100224_PiranhasPursuit = 42;
                    func_800F9E00_PiranhasPursuit(1280.0f, D_801001FC_PiranhasPursuit - 300.0, 375.0f, 0.0f, -6.25f,
                                                  0.0f, 0.0f, (s16)D_80100224_PiranhasPursuit);
                    func_800FA7C0_PiranhasPursuit((u16)D_80100224_PiranhasPursuit);
                }
            }
            break;
        case 1:
            if (D_80100224_PiranhasPursuit != 0) {
                D_80100224_PiranhasPursuit--;
            }
            break;
        case 2:
            D_80100224_PiranhasPursuit = 0x80;
            break;
        case 3:
        case 4:
        case 5:
            if (D_80100224_PiranhasPursuit != 0) {
                D_80100224_PiranhasPursuit--;
            }
            if (D_801001F0_PiranhasPursuit == 3) {
                D_80100220_PiranhasPursuit = func_8009B618(D_80100220_PiranhasPursuit + 2.0, 360.0);
            }
            if (D_80100208_PiranhasPursuit < D_800B8980 * 0.8) {
                D_80100208_PiranhasPursuit = D_80100208_PiranhasPursuit + 0.5;
            } else {
                D_80100208_PiranhasPursuit = D_800B8980 * 0.8;
            }
            if (D_80100224_PiranhasPursuit == 0 && D_801001F0_PiranhasPursuit == 5) {
                solo = D_800F3FB0[D_8010020C_PiranhasPursuit];
                if (D_8010021C_PiranhasPursuit == 0) {
                    D_801001F0_PiranhasPursuit = 6;
                    D_80100224_PiranhasPursuit = 27;
                    func_800F9E00_PiranhasPursuit(640.0f, solo->trans.x, 100.0f,
                                                  0.0f, -6.25f, 0.0f, 0.0f, (s16)D_80100224_PiranhasPursuit);
                    func_800FA7C0_PiranhasPursuit((u16)D_80100224_PiranhasPursuit);
                } else {
                    D_801001F0_PiranhasPursuit = 9;
                }
                D_80100214_PiranhasPursuit++;
            } else {
                if (D_80100218_PiranhasPursuit > 1.0) {
                    D_80100218_PiranhasPursuit = 1.0f;
                }
                func_800F9D78_PiranhasPursuit((D_80100218_PiranhasPursuit * 0.2 + 0.8) * 1600.0,
                                              D_801001FC_PiranhasPursuit - (1.0f - D_80100218_PiranhasPursuit) * 300.0,
                                              375.0f, 0.0f, -6.25f, 0.0f, 0.0f);
            }
            break;
        case 6:
            if (D_80100224_PiranhasPursuit != 0) {
                D_80100224_PiranhasPursuit--;
            } else {
                D_801001F0_PiranhasPursuit = 8;
            }
            break;
    }
    D_80100204_PiranhasPursuit = D_80100200_PiranhasPursuit;
    D_80100200_PiranhasPursuit =
        D_801001FC_PiranhasPursuit - (func_800AEAC0(D_80100220_PiranhasPursuit) * 1.25 + 3.0) * 100.0;
    func_800F9F4C_PiranhasPursuit(obj);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_PiranhasPursuit/222320", func_800F6C84_PiranhasPursuit);
#endif

void func_800F70D0_PiranhasPursuit(omObjData* obj) {
    func_800F9CBC_PiranhasPursuit(obj, &D_80100CE0_PiranhasPursuit[0]);
    if (GwPlayer[0].group != 0) {
        func_800093FC(obj, -100.0f, 650.0f, 0.0f);
        func_800F782C_PiranhasPursuit(obj, 0);
    } else {
        func_800093FC(obj, -16000.0f, 0.0f, 0.0f);
        func_800F7320_PiranhasPursuit(obj, 0);
    }
    D_80100D20_PiranhasPursuit = 0;
}

// NON_MATCHING: retail selects the float x in a GPR (bnezl)
#ifdef NON_MATCHING
void func_800F7158_PiranhasPursuit(omObjData* obj) {
    f32 x;

    func_800F9CBC_PiranhasPursuit(obj, &D_80100D40_PiranhasPursuit);
    if (GwPlayer[1].group != 0) {
        x = -100.0f;
        if (D_8010020C_PiranhasPursuit != 0) {
            x = 0.0f;
        }
        func_800093FC(obj, x, 650.0f, 0.0f);
        func_800F782C_PiranhasPursuit(obj, 1);
    } else {
        func_800093FC(obj, -16000.0f, 0.0f, 0.0f);
        func_800F7320_PiranhasPursuit(obj, 1);
    }
    D_80100D80_PiranhasPursuit = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_PiranhasPursuit/222320", func_800F7158_PiranhasPursuit);
#endif

// NON_MATCHING: retail selects the float x in a GPR
#ifdef NON_MATCHING
void func_800F71F0_PiranhasPursuit(omObjData* obj) {
    f32 x;

    func_800F9CBC_PiranhasPursuit(obj, &D_80100DA0_PiranhasPursuit);
    if (GwPlayer[2].group != 0) {
        if (D_8010020C_PiranhasPursuit == 3) {
            x = 100.0f;
        } else {
            x = 0.0f;
        }
        func_800093FC(obj, x, 650.0f, 0.0f);
        func_800F782C_PiranhasPursuit(obj, 2);
    } else {
        func_800093FC(obj, -16000.0f, 0.0f, 0.0f);
        func_800F7320_PiranhasPursuit(obj, 2);
    }
    D_80100DE0_PiranhasPursuit = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_PiranhasPursuit/222320", func_800F71F0_PiranhasPursuit);
#endif

void func_800F7298_PiranhasPursuit(omObjData* obj) {
    func_800F9CBC_PiranhasPursuit(obj, &D_80100E00_PiranhasPursuit);
    if (GwPlayer[3].group != 0) {
        func_800093FC(obj, 100.0f, 650.0f, 0.0f);
        func_800F782C_PiranhasPursuit(obj, 3);
    } else {
        func_800093FC(obj, -16000.0f, 0.0f, 0.0f);
        func_800F7320_PiranhasPursuit(obj, 3);
    }
    D_80100E40_PiranhasPursuit = 0;
}

const char D_801004B0_PiranhasPursuit[] = "27mt008_DEF";
const char D_801004BC_PiranhasPursuit[] = "27mt007_DEF";
const char D_801004C8_PiranhasPursuit[] = "27mt006_DEF";
const char D_801004D4_PiranhasPursuit[] = "27mt005_DEF";
const char D_801004E0_PiranhasPursuit[] = "27mt004_DEF";
const char D_801004EC_PiranhasPursuit[] = "27mt003_DEF";

/* Motion file ids (two alternatives each), copied to the stack by both player setups. */
typedef struct PPMotIds {
    s32 v[5];
} PPMotIds;

const PPMotIds D_801004F8_PiranhasPursuit = { { 0x0F, 0x38, 0x39, 0x3A, 0x3B } };
const PPMotIds D_8010050C_PiranhasPursuit = { { 0x10, 0x3C, 0x3D, 0x3E, 0x3F } };

/* The solo runner. */
// NON_MATCHING: retail sign-extends the sprite ids at assignment (s32-returning prototypes)
#ifdef NON_MATCHING
void func_800F7320_PiranhasPursuit(omObjData* obj, s32 player) {
    PPMotIds a = D_801004F8_PiranhasPursuit;
    PPMotIds b = D_8010050C_PiranhasPursuit;
    s32 tex;
    s32 dir;
    s32 file;
    PPWork* w;
    s32* m;
    s16 i;
    s16 grp;
    s16 coin;
    s16 star;
    void* f;

    tex = 0;
    dir = D_800C59AC[GwPlayer[player].character].unk_00;
    file = D_800C59AC[GwPlayer[player].character].unk_04;
    func_80009618(0);
    func_8000979C(obj, dir, file, player, 0xD9, 0xD9);
    obj->func_ptr = func_800F8114_PiranhasPursuit;
    w = obj->unk_50;
    w->unk_DC = NULL;
    w->unk_58 = player;
    obj->model[3] = LoadFormFile(0x19, 0x68D);
    obj->model[4] = LoadFormFile(0x1A, 0x68D);
    obj->model[6] = LoadFormFile(0x1B, 0x68D);
    obj->model[7] = LoadFormFile(0x1E, 0x68D);
    obj->model[8] = LoadFormFile(0x1D, 0x68D);
    obj->model[9] = LoadFormFile(0x280003, 0x689);
    LoadFormFile(0x280006, 0xA8D);
    switch ((u32)dir >> 16) {
        case 1:
            tex = 0;
            break;
        case 2:
            tex = 1;
            break;
        case 6:
            tex = 2;
            break;
        case 3:
            tex = 3;
            break;
        case 4:
            tex = 4;
            break;
        case 5:
            tex = 5;
            break;
    }
    func_80027AC8(obj->model[9], (u8*)D_80100228_PiranhasPursuit[0], (u8*)D_80100228_PiranhasPursuit[tex]);
    func_80025AD4(obj->model[9]);
    func_800258EC(obj->model[9], 16, 16);
    func_800187D0(obj, 0, dir | 0x4A, 1, 0);
    func_800187D0(obj, 1, dir | 0x4B, 2, 0);
    func_800187D0(obj, 6, dir | 0x4C, 1, 0x18);
    func_800187D0(obj, 0xA, dir | 0x1E, 1, 0x27);
    func_800187D0(obj, 0x15, dir | 0x6E, 0, 0);
    func_800187D0(obj, 0x23, dir | 0x56, 1, 0x13);
    m = &a.v[rand8() & 1];
    func_800187D0(obj, 0xD, dir | m[0], 1, 0x78);
    func_800187D0(obj, 0xE, dir | m[6], 1, 0x78);
    omSetRot(obj, 0.0f, 90.0f, 0.0f);
    func_800184BC(obj, 0);
    func_80017DB0(obj);
    func_800090C4(obj, 0, 2);
    f = DataRead(0x21);
    coin = func_800678A4(f);
    D_801012F0_PiranhasPursuit[1] = coin;
    DataClose(f);
    f = DataRead(0x2A);
    star = func_800678A4(f);
    D_801012F0_PiranhasPursuit[4] = star;
    DataClose(f);
    for (i = 0; i < 15; i++) {
        D_80100E68_PiranhasPursuit[i].sprite = grp = func_80064EF4(2, 0);
        func_80067208(grp, 0, coin, 0);
        func_800674BC(grp, 0, 0x9000);
        func_800672B0(grp, 0, 1);
        func_80067354(grp, 0, 0.8f, 0.8f);
        func_80067208(grp, 1, star, 0);
        func_800674BC(grp, 1, 0x900C);
        func_800672B0(grp, 1, 0);
        func_800674F4(grp, 1, 0xFF, 0xFF, 0xBE);
        func_80067354(grp, 1, 1.5f, 1.5f);
        D_80100E68_PiranhasPursuit[i].state = 0;
        D_80100E68_PiranhasPursuit[i].timer = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_PiranhasPursuit/222320", func_800F7320_PiranhasPursuit);
#endif

/* A watcher on the shore. */
void func_800F782C_PiranhasPursuit(omObjData* obj, s32 player) {
    PPMotIds a = D_801004F8_PiranhasPursuit;
    s32 dir;
    s32 file;
    PPWork* w;
    PPPlayer* p;

    dir = D_800C59AC[GwPlayer[player].character].unk_00;
    file = D_800C59AC[GwPlayer[player].character].unk_04;
    func_80009618(1);
    func_8000979C(obj, dir, file, player, 0xD9, 0xD9);
    obj->func_ptr = func_800F9854_PiranhasPursuit;
    w = obj->unk_50;
    w->unk_DC = NULL;
    w->unk_58 = player;
    obj->model[7] = LoadFormFile(0x1E, 0x60D);
    func_80025830(obj->model[7], 0.75f, 0.75f, 0.25f);
    func_8001874C(obj, 0, dir, 1, 0);
    func_8001874C(obj, 1, dir | 1, 1, 0);
    func_8001874C(obj, 2, dir | 3, 1, 0);
    func_8001874C(obj, 6, dir | 5, 1, 0x13);
    func_800187D0(obj, 8, dir | 9, 1, 0x1D);
    func_8001874C(obj, 0x11, dir | 0x18, 0, 0);
    func_800187D0(obj, 0x12, dir | 0x1C, 2, 0);
    func_8001874C(obj, 0x15, dir | 0x62, 0, 0);
    func_800187D0(obj, 0xD, dir | a.v[rand8() & 1], 1, 0x78);
    func_800090C4(obj, 0, 2);
    omSetRot(obj, 0.0f, 0.0f, 0.0f);
    p = func_800F9CDC_PiranhasPursuit(obj);
    p->unk1C = obj->trans.x;
    p->unk20 = obj->trans.y;
    p->unk24 = obj->trans.z;
    func_800184BC(obj, 0);
    func_80017DB0(obj);
}

/* The game's control object: intro messages, the end, coins and the result messages. */
void func_800F7AA0_PiranhasPursuit(omObjData* obj) {
    s32 i;

    D_80100CDC_PiranhasPursuit = (D_80100CDC_PiranhasPursuit + 1) % 3;
    if (D_800F5144 == 1) {
        D_80100E60_PiranhasPursuit = -1;
        func_800601D4(60);
        obj->func_ptr = func_800F6B74_PiranhasPursuit;
    }
    {
        switch (D_801001F0_PiranhasPursuit) {
            case 0:
                if (func_80072718() == 0) {
                    if (--D_80100240_PiranhasPursuit == 0) {
                        D_801001F0_PiranhasPursuit = 1;
                        func_80060128(0x21);
                        D_80100240_PiranhasPursuit = 42;
                    }
                }
                break;
            case 1:
                if (--D_80100240_PiranhasPursuit == 0) {
                    D_801001F0_PiranhasPursuit = 2;
                    D_80100240_PiranhasPursuit = 16;
                }
                break;
            case 2:
                if (D_80100248_PiranhasPursuit != 0) {
                    if (GMesStatAllGet() == 0) {
                        D_801001F0_PiranhasPursuit = 3;
                        D_80100248_PiranhasPursuit = 0;
                        D_80100240_PiranhasPursuit = 0;
                    }
                } else {
                    GMesCreate(0);
                    D_80100248_PiranhasPursuit = 1;
                }
                break;
            case 3:
                if (D_801001F4_PiranhasPursuit != 0) {
                    func_800FD4BC_PiranhasPursuit(D_80100200_PiranhasPursuit, 600.0f);
                    D_801001F4_PiranhasPursuit = 0;
                    D_8010024C_PiranhasPursuit = 0.2f;
                }
                break;
            case 4:
            case 5:
                if (D_80100248_PiranhasPursuit == 0) {
                    GMesCreate(2);
                    func_800601D4(90);
                    for (i = 0; i < 4; i++) {
                        if (i == D_8010020C_PiranhasPursuit) {
                            GwPlayer[i].coins_mg += 15;
                        } else if (GwPlayer[i].coins >= 5) {
                            GwPlayer[i].coins_mg -= 5;
                        } else {
                            GwPlayer[i].coins_mg -= GwPlayer[i].coins;
                        }
                    }
                    D_80100248_PiranhasPursuit = 1;
                }
            case 7:
                if (D_80100248_PiranhasPursuit == 0) {
                    if (++D_80100240_PiranhasPursuit == 0x60) {
                        if (D_8010021C_PiranhasPursuit == 0) {
                            GMesCreate(14);
                        } else {
                            GMesCreate(2);
                        }
                        func_800601D4(90);
                        D_80100248_PiranhasPursuit = 1;
                        for (i = 0; i < 4; i++) {
                            if (i == D_8010020C_PiranhasPursuit) {
                                if (GwPlayer[i].coins >= 15) {
                                    GwPlayer[i].coins_mg -= 15;
                                } else {
                                    GwPlayer[D_8010020C_PiranhasPursuit].coins_mg -=
                                        GwPlayer[D_8010020C_PiranhasPursuit].coins;
                                }
                            } else {
                                GwPlayer[i].coins_mg += 5;
                            }
                        }
                    }
                }
            case 6:
            case 8:
                if (D_80100214_PiranhasPursuit != 0) {
                    D_80100214_PiranhasPursuit++;
                }
                if (D_801001F8_PiranhasPursuit != 0) {
                    if (D_80100214_PiranhasPursuit == 2) {
                        func_80060128(0x33);
                    } else if (D_80100214_PiranhasPursuit == 0x24) {
                        func_80060468(0x450, GwPlayer[D_8010020C_PiranhasPursuit].character + 1);
                    } else if (D_80100214_PiranhasPursuit == 0x5D) {
                        D_801001F0_PiranhasPursuit = 9;
                    }
                } else if (D_80100214_PiranhasPursuit == 2) {
                    if (D_8010021C_PiranhasPursuit == 0) {
                        func_80060128(0x34);
                    }
                } else if (D_80100214_PiranhasPursuit == 0x14) {
                    if (D_8010021C_PiranhasPursuit == 0) {
                        func_80060468(0x449, GwPlayer[D_8010020C_PiranhasPursuit].character + 1);
                    }
                } else if (D_80100214_PiranhasPursuit == 0x3C) {
                    if (D_8010021C_PiranhasPursuit != 0) {
                        D_801001F0_PiranhasPursuit = 9;
                    }
                } else if (D_80100214_PiranhasPursuit == 0x5C) {
                    D_801001F0_PiranhasPursuit = 9;
                }
                break;
            case 9:
                D_80100248_PiranhasPursuit = 0;
                D_80100E60_PiranhasPursuit = -1;
                if (D_8010021C_PiranhasPursuit != 0) {
                    func_80060398(0x28);
                }
                func_800726AC(0, 20);
                obj->func_ptr = func_800F6B74_PiranhasPursuit;
                break;
        }
    }
    func_800FB5C8_PiranhasPursuit(D_801001FC_PiranhasPursuit);
    D_80100244_PiranhasPursuit = (D_80100244_PiranhasPursuit + 20) % 360;
    if (D_8010024C_PiranhasPursuit >= 0.0) {
        D_8010024C_PiranhasPursuit = D_8010024C_PiranhasPursuit - 0.01;
    }
    func_80025798(D_80100E66_PiranhasPursuit, D_80100200_PiranhasPursuit,
                  650.0 - (2.0f * D_8010024C_PiranhasPursuit + 0.35) * 100.0, 300.0f);
    func_80025830(D_80100E66_PiranhasPursuit, 1.0f, 1.0 - D_8010024C_PiranhasPursuit, 0.75f);
}

/* The solo runner: input (or the CPU), running, jumping over the course pieces, riding a log,
   being caught at the end, and the coin shower. */
// NON_MATCHING: register allocation, CSE of the clamp/landing speed reloads, branchless index (masked 117 of 1779; calls, stores and constants equal)
#ifdef NON_MATCHING
void func_800F8114_PiranhasPursuit(omObjData* obj) {
    Vec pos;
    PPWork* w;
    u16 btn;
    PPPlayer* p;
    f32 ry;
    u8 port;
    s32 flags;
    f32 x;
    f32 y;
    f32 z;
    PPPiece* piece;
    f32 dx;
    f32 dist;
    f32 vy;
    f32 k;
    f32 speed;
    f32 s;
    u32 r;
    s16 mot;
    s16 caught;
    PPCoin* c;
    omObjData* o;
    s32 i;
    s32 j;
    s32 n;

    w = obj->unk_50;
    btn = 0;
    p = func_800F9CDC_PiranhasPursuit(obj);
    ry = obj->rot.y;
    port = w->unk_56;
    flags = func_80017A60(obj);
    pos.x = x = obj->trans.x;
    pos.y = y = obj->trans.y;
    pos.z = z = obj->trans.z;
    if (D_801001F0_PiranhasPursuit == 3) {
        D_800ED430 = 1;
        if (GwPlayer[w->unk_58].flags & 1) {
            if (w->unk_40 < D_800B8980 * 0.4) {
                if (func_800F9D40_PiranhasPursuit() % (5 - GwPlayer[w->unk_58].cpu_difficulty) == 0) {
                    btn |= 0x4000;
                }
            } else if (func_800F9D40_PiranhasPursuit() % (7 - GwPlayer[w->unk_58].cpu_difficulty) == 0) {
                btn |= 0x4000;
            }
            if (D_80100CA8_PiranhasPursuit != 0) {
                D_80100CA8_PiranhasPursuit = 0;
                btn |= 0x8000;
            }
        } else {
            btn = ContBtnTrg[(s8)port];
        }
    } else {
        D_800ED430 = 2;
    }
    switch (D_801001F0_PiranhasPursuit) {
        case 0:
            p->unk40 = p->unk42 = p->unk44 = p->unk46 = 0;
            p->unk0 = 0;
            p->unk2 = 1;
        case 1:
        case 2:
        case 9:
            p->unk38 = ry;
            break;
        case 3:
        case 4:
            if (p->unk2 == 2) {
                x = D_80100CA0_PiranhasPursuit->unk34 + D_80100CA4_PiranhasPursuit;
                y = D_80100CA0_PiranhasPursuit->unk38 + 20.0;
                if (D_80100CA0_PiranhasPursuit->unk8 >= 0x50) {
                    p->unk2 |= 1;
                    w->unk_38 = -D_800B8964 * 0.625;
                    w->unk_40 = D_800B8980;
                }
            } else if (flags & 7) {
                if (btn & 0x4000) {
                    w->unk_40 += 2.8;
                    if (func_800184BC(obj, 1) != 0) {
                        PlaySound(0x273);
                        func_80017C0C(obj, 4, x + w->unk_40, y, z, 0.0f, 0.0f);
                    }
                } else {
                    w->unk_40 += -0.32;
                    if (flags & 1) {
                        func_800184BC(obj, 0);
                    }
                }
                if (btn & 0x8000) {
                    func_800185A4(obj, 6);
                    w->unk_38 = -D_800B8964;
                    func_80060468(0x127, GwPlayer[w->unk_58].character);
                }
                speed = w->unk_40;
                if (D_800B8980 < speed) {
                    w->unk_40 = D_800B8980;
                } else if (speed < D_800B8990) {
                    w->unk_40 = D_800B8990;
                }
            } else if (flags & 0x820) {
                vy = w->unk_38;
                if (D_800B8994 < vy) {
                    vy = D_800B8994;
                }
                vy = vy * vy;
                k = 35.0f;
                if (w->unk_38 >= 0.0f) {
                    k = -35.0f;
                }
                y += vy * k;
                w->unk_38 += D_800B8968 * 0.75;
                if (flags & 0x20) {
                    p->unk40 = p->unk40 - 3.5;
                    if (p->unk40 < -45.0) {
                        p->unk40 = -45;
                    }
                } else {
                    p->unk40 = p->unk40 + 9.0;
                    if (p->unk40 > 100.0) {
                        p->unk40 = 100;
                    }
                    p->unk42 = p->unk42 + 7.0;
                    if (p->unk42 > 85.0) {
                        p->unk42 = 85;
                    }
                }
                if (y <= 0.0) {
                    y = 0.0f;
                    if (p->unk2 & 2) {
                        func_80060F04(w->unk_58, 10, 0, 10);
                    }
                    p->unk2 = 1;
                    p->unk40 = 0;
                    p->unk42 = 0;
                    func_80060468(0x12E, GwPlayer[w->unk_58].character);
                    func_80017C0C(obj, 8, x + w->unk_40, y, z, 0.0f, 0.0f);
                    if (flags & 0x800) {
                        w->unk_40 = D_800B8980 * 0.25;
                        D_800F2B7C[obj->model[0]].unk_4C = 1.0f;
                        func_800184BC(obj, 0);
                    } else {
                        func_800184BC(obj, 0x15);
                    }
                }
            }
            x += w->unk_40;
            if (x - D_801001FC_PiranhasPursuit >= 250.0) {
                if (D_801001F0_PiranhasPursuit == 3) {
                    x = D_801001FC_PiranhasPursuit + 250.0;
                }
            } else if (x - D_801001FC_PiranhasPursuit <= -800.0) {
                x = D_801001FC_PiranhasPursuit - 800.0;
            }
            if (x - D_801001FC_PiranhasPursuit >= 0.0) {
                D_80100218_PiranhasPursuit = (x - D_801001FC_PiranhasPursuit) / 250.0;
            } else {
                D_80100218_PiranhasPursuit = 0.0f;
            }
            piece = func_800FC3F4_PiranhasPursuit(obj->trans.x, obj->trans.y);
            if (func_800FC5A8_PiranhasPursuit(obj) != 0) {
                D_801001F0_PiranhasPursuit = 7;
                p->unk2 |= 8;
                D_801001F8_PiranhasPursuit = 0;
                func_80060618(0x45F, w->unk_58);
                p->unk1C = x;
                p->unk20 = 0.0f;
                p->unk24 = z;
                p->unk34 = 0.0f;
                p->unk38 = ry;
                p->unk3C = 0.0f;
                p->unk40 = p->unk42 = 0;
                p->unk38 = ry;
                break;
            }
            dist = sqrtf((piece->unk34 - obj->trans.x) * (piece->unk34 - obj->trans.x) +
                         (piece->unk38 - obj->trans.y) * (piece->unk38 - obj->trans.y));
            if (piece->unk4 + 50.0 >= dist) {
                switch (piece->unk2) {
                    case 2:
                        if (piece->unk0 == 0) {
                            break;
                        }
                    case 1:
                        if (!(flags & 0x800)) {
                            func_800185A4(obj, 10);
                            w->unk_38 = -D_800B8964 * 0.75;
                            w->unk_40 = D_800B8980 * 0.5;
                            func_80060468(0x127, GwPlayer[w->unk_58].character);
                            func_80017C0C(obj, 7, x, y, 0.0f, 70.0f, 270.0f);
                            func_80060540(0x350, 0);
                            func_80060F04(w->unk_58, 20, 0, 20);
                        }
                        break;
                    case 3:
                        if (flags & 0x20) {
                            if (w->unk_38 > 0.0) {
                                func_800185A4(obj, 6);
                                w->unk_38 = -D_800B8964 * 0.75;
                                w->unk_40 = D_800B8980 * 0.6;
                                func_80060468(0x127, GwPlayer[w->unk_58].character);
                                func_80017C0C(obj, 6, x, y, 0.0f, 0.0f, 180.0f);
                            }
                        } else {
                            x = pos.x;
                        }
                        break;
                    case 4:
                        if (!(p->unk2 & 2)) {
                            p->unk2 = 2;
                            D_80100CA0_PiranhasPursuit = piece;
                            piece->unk0 = 2;
                            w->unk_40 = 0.0f;
                            if (piece->unk34 <= x) {
                                D_80100CA4_PiranhasPursuit = x - piece->unk34;
                            } else {
                                D_80100CA4_PiranhasPursuit = (x - piece->unk34) * 0.5;
                            }
                        }
                        break;
                    case 5:
                        D_801001F0_PiranhasPursuit = 4;
                        break;
                }
            } else if (piece->unk2 == 5) {
                if (dist >= 400.0 && (flags & 7)) {
                    D_801001F0_PiranhasPursuit = 5;
                    D_801001F8_PiranhasPursuit = 1;
                    w->unk_40 = 0.0f;
                    obj->rot.z = 20.0f;
                    func_80017C0C(obj, 4, x + 150.0, y, z, 0.0f, 180.0f);
                } else {
                    D_801001F0_PiranhasPursuit = 4;
                    w->unk_40 = D_800B8980 * 0.8;
                }
            } else if (GwPlayer[w->unk_58].flags & 1) {
                if ((u32)(piece->unk2 - 5) >= 2) {
                    r = func_800F9D40_PiranhasPursuit() % (GwPlayer[w->unk_58].cpu_difficulty * 2 + 6);
                    if (dist <= (f32)((f32)(0.8f + (r + w->unk_40 * 0.075) * 0.1) * 100.0) + piece->unk4) {
                        if (piece->unk34 - obj->trans.x >= 0.0f) {
                            D_80100CA8_PiranhasPursuit = 1;
                        }
                    }
                }
            }
            p->unk38 = ry;
            break;
        case 5:
        case 6:
            if (ry > 0.0) {
                ry -= 18.0f;
                x += 20.0;
                p->unk38 -= 12.0f;
            } else {
                if (D_801001F0_PiranhasPursuit == 6) {
                    y = 20.0f;
                    func_800184BC(obj, 13);
                    p->unk2 |= 4;
                    p->unk34 = p->unk40;
                    p->unk38 = 30.0f;
                    p->unk3C = 0.0f;
                }
                obj->rot.z = 0.0f;
            }
            for (i = 0; i < 15; i++) {
                c = &D_80100E68_PiranhasPursuit[i];
                switch (c->state) {
                    case 0:
                        j = i % 3;
                        o = D_800F3FB0[j + (j >= D_8010020C_PiranhasPursuit)];
                        func_80066DF4(c->sprite, 0, 0, o->trans.x, o->trans.y + 100.0, o->trans.z);
                        func_80067354(c->sprite, 0, 0.8f, 0.8f);
                        c->timer = 16;
                        c->x = o->trans.x;
                        c->y = o->trans.y + 100.0;
                        c->z = o->trans.z;
                        c->vy = 60.0f;
                        c->vx = ((obj->trans.x + 100.0) - o->trans.x) / c->timer;
                        c->state++;
                        break;
                    case 1:
                        if (p->unk44 >= i * 4 + 24) {
                            func_80067480(c->sprite, 0, 0x8000);
                            c->state++;
                        }
                        break;
                    case 2:
                        c->vy -= 12.0f;
                        c->x += c->vx;
                        c->y += c->vy;
                        func_80066DF4(c->sprite, 0, 0, c->x, c->y, c->z);
                        if (--c->timer == 0) {
                            c->state++;
                        }
                        break;
                    case 3:
                        func_800674BC(c->sprite, 0, 0x8000);
                        func_80067480(c->sprite, 1, 0x8000);
                        func_800672B0(c->sprite, 1, 2);
                        func_80067284(c->sprite, 1, 1.0f);
                        func_800672DC(c->sprite, 1, 0, 0);
                        func_80066DF4(c->sprite, 1, 0, c->x, c->y, c->z);
                        c->sound = func_80060540(0xFC, i + 1);
                        c->sound = func_80060540(0xFC, i + 1);
                        c->state++;
                        break;
                    case 4:
                        if (func_80067328(c->sprite, 1) & 4) {
                            func_800674BC(c->sprite, 1, 0x8000);
                            c->state++;
                        }
                        break;
                }
            }
            p->unk44++;
            break;
        case 7:
            caught = func_800FC5A8_PiranhasPursuit(obj);
            if (p->unk0 != 0) {
                for (i = 0; i < 15; i++) {
                    c = &D_80100E68_PiranhasPursuit[i];
                    switch (c->state) {
                        case 0:
                            if (p->unk44 >= i * 4) {
                                func_80067480(c->sprite, 0, 0x8000);
                                c->state++;
                            }
                            break;
                        case 1:
                            c->vy -= 10.0f;
                            c->x += c->vx;
                            c->y += c->vy;
                            func_80066DF4(c->sprite, 0, 0, c->x, c->y, c->z);
                            if (--c->timer == 0) {
                                c->state++;
                            }
                            break;
                        case 2:
                            func_800674BC(c->sprite, 0, 0x8000);
                            func_80067480(c->sprite, 1, 0x8000);
                            func_800672B0(c->sprite, 1, 2);
                            func_80067284(c->sprite, 1, 1.0f);
                            func_800672DC(c->sprite, 1, 0, 0);
                            func_80066DF4(c->sprite, 1, 0, c->x, c->y, c->z);
                            c->sound = func_80060540(0xFC, i + 1);
                            c->sound = func_80060540(0xFC, i + 1);
                            c->state++;
                            break;
                        case 3:
                            if (func_80067328(c->sprite, 1) & 4) {
                                if (i == 14) {
                                    D_801001F0_PiranhasPursuit = 8;
                                }
                                func_800674BC(c->sprite, 1, 0x8000);
                                c->state++;
                            }
                            break;
                    }
                }
                p->unk44++;
            } else if (caught == 0) {
                y = 0.0f;
                ry = 0.0f;
                func_800184BC(obj, 14);
                D_80100214_PiranhasPursuit++;
                if (D_8010021C_PiranhasPursuit == 0) {
                    D_80100210_PiranhasPursuit = 5;
                } else {
                    D_80100210_PiranhasPursuit = 0;
                }
                if (D_80100210_PiranhasPursuit == 0) {
                    D_801001F0_PiranhasPursuit = 8;
                } else {
                    p->unk0 = 1;
                    p->unk44 = 0;
                }
                n = 0;
                for (i = 0; i < 4; i++) {
                    if (i != D_8010020C_PiranhasPursuit) {
                        o = D_800F3FB0[i];
                        for (j = 0; j < 5; j++) {
                            c = &D_80100E68_PiranhasPursuit[n + j * 3];
                            func_80066DF4(c->sprite, 0, 0, obj->trans.x, obj->trans.y, obj->trans.z);
                            func_80067354(c->sprite, 0, 0.8f, 0.8f);
                            c->timer = 16;
                            c->x = obj->trans.x;
                            c->y = obj->trans.y;
                            c->z = obj->trans.z;
                            c->vy = 130.0f;
                            c->vx = (o->trans.x - obj->trans.x) / (f32)c->timer;
                        }
                        n++;
                    }
                }
            }
        case 8:
            piece = func_800FC3F4_PiranhasPursuit(p->unk1C, 0.0f);
            dx = piece->unk34 - p->unk1C;
            if (sqrtf(dx * dx) <= piece->unk4 + 150.0) {
                switch (piece->unk2) {
                    case 2:
                        if (piece->unk0 == 0) {
                            break;
                        }
                    case 1:
                    case 3:
                        if (p->unk40 == 0) {
                            p->unk40 = 20;
                            p->unk1C = (piece->unk34 - piece->unk4) - 75.0;
                        } else if (p->unk40 >= 180) {
                            p->unk40 = 180;
                        } else {
                            p->unk40 = p->unk40 + p->unk40 * 0.25;
                            p->unk1C = p->unk1C - 2.5;
                        }
                        p->unk34 = p->unk20 = func_800AEAC0(p->unk40) * 30.0f;
                        break;
                    case 4:
                    case 5:
                        p->unk1C += D_800B8980 * 0.8;
                        break;
                }
            } else if (p->unk2 & 8) {
                p->unk1C += D_800B8980 * 0.8;
            }
            break;
    }
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = z;
    obj->rot.y = ry;
    if (!(p->unk2 & 0xC)) {
        p->unk1C = x - p->unk42;
        p->unk20 = y;
        p->unk24 = z;
        p->unk34 = p->unk40;
        p->unk3C = obj->rot.z;
    }
    func_80025798(obj->model[9], p->unk1C, p->unk20, p->unk24);
    func_800257E4(obj->model[9], p->unk34, p->unk38, p->unk3C);
    s = 1.0 - y / 2000.0;
    func_80025798(obj->model[1], x, 0.0f, z);
    func_80025830(obj->model[1], s, s, s);
    func_80017DB0(obj);
    func_80017BB0(obj);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_PiranhasPursuit/222320", func_800F8114_PiranhasPursuit);
#endif

/* A watcher: CPU input, and keeps the watchers in place while the course scrolls. */
// NON_MATCHING: register allocation (flags kept in a0)
#ifdef NON_MATCHING
void func_800F9854_PiranhasPursuit(omObjData* obj) {
    PPWork* w;
    PPPlayer* p;
    u8 port;
    s32 flags;
    Vec pos;
    u16* trg;
    s32 i;
    s16 m;

    w = obj->unk_50;
    p = func_800F9CDC_PiranhasPursuit(obj);
    port = w->unk_56;
    flags = func_80017A60(obj);
    pos.x = obj->trans.x;
    pos.y = obj->trans.y;
    pos.z = obj->trans.z;
    if (D_801001F0_PiranhasPursuit == 3 && (GwPlayer[w->unk_58].flags & 1)) {
        ContStkX[(s8)port] = 0;
        ContStkY[(s8)port] = 0;
        ContBtn[(s8)port] = 0;
        trg = &ContBtnTrg[(s8)port];
        *trg = 0;
        if ((flags & 0x20) && w->unk_38 > 0.0) {
            *trg = 0x2000;
        } else if (func_800F9D40_PiranhasPursuit() % (26 - GwPlayer[w->unk_58].cpu_difficulty * 4) == 0) {
            ContBtnTrg[(s8)port] |= 0x8000;
        }
    }
    for (i = 0; i < 4; i++) {
        if (i != D_8010020C_PiranhasPursuit) {
            D_800F3FB0[i]->trans.x = D_80100CE0_PiranhasPursuit[i].unk1C;
        }
    }
    for (i = 3; i < 9; i++) {
        m = obj->model[i];
        if (m != 0) {
            D_800F2B7C[m].unk_24 -= D_80100204_PiranhasPursuit;
        }
    }
    func_80005A28(obj);
    if ((flags & 0x200) && (w->unk_50 & 0x80) && obj->trans.y <= 660.0) {
        D_801001F4_PiranhasPursuit = 1;
    }
    p->unk1C = obj->trans.x;
    if (D_801001F0_PiranhasPursuit == 8 && D_801001F8_PiranhasPursuit == 0 && D_8010021C_PiranhasPursuit == 0) {
        func_800184BC(obj, 13);
    }
    for (i = 0; i < 4; i++) {
        if (i != D_8010020C_PiranhasPursuit) {
            D_800F3FB0[i]->trans.x += D_80100200_PiranhasPursuit;
        }
    }
    for (i = 3; i < 9; i++) {
        m = obj->model[i];
        if (m != 0) {
            D_800F2B7C[m].unk_24 += D_80100200_PiranhasPursuit;
        }
    }
    if (w->unk_B2 == 11) {
        func_8006071C(w->unk_B3);
        w->unk_B3 = func_80060618(0x352, w->unk_58);
        w->unk_B2 = 14;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_PiranhasPursuit/222320", func_800F9854_PiranhasPursuit);
#endif

void func_800F9BF0_PiranhasPursuit(void) {
    func_800FA1E4_PiranhasPursuit();
    D_800B897C = D_80100CAC_PiranhasPursuit;
    D_800B895C = D_80100CB0_PiranhasPursuit;
    D_800B8960 = D_80100CB4_PiranhasPursuit;
    D_800B8984 = D_80100CB8_PiranhasPursuit;
    D_800B8988 = D_80100CBC_PiranhasPursuit;
    D_800B896C = D_80100CC0_PiranhasPursuit;
    D_800B8970 = D_80100CC4_PiranhasPursuit;
    D_800B8980 = D_80100CC8_PiranhasPursuit;
    D_800B8964 = D_80100CCC_PiranhasPursuit;
    D_800B8968 = D_80100CD0_PiranhasPursuit;
    D_800B8994 = D_80100CD4_PiranhasPursuit;
}

/* Keeps the player's PPPlayer in omObjData::work as a big-endian word; on the host the work bytes
   cannot hold a pointer, so they hold its index (only D_80100CE0 entries are stored). */
void func_800F9CBC_PiranhasPursuit(omObjData* obj, PPPlayer* p) {
    obj->work[0] = (u32)p >> 24;
    obj->work[1] = (u32)p >> 16;
    obj->work[2] = (u32)p >> 8;
    obj->work[3] = (u32)p;
}

PPPlayer* func_800F9CDC_PiranhasPursuit(omObjData* obj) {
    return (PPPlayer*)((obj->work[0] << 24) | (obj->work[1] << 16) | (obj->work[2] << 8) | obj->work[3]);
}

void func_800F9D08_PiranhasPursuit(void) {
    D_80100250_PiranhasPursuit *= rand8();
}

u32 func_800F9D40_PiranhasPursuit(void) {
    D_80100250_PiranhasPursuit = D_80100250_PiranhasPursuit * 0x41C64E6D + 0x3039;
    return (D_80100250_PiranhasPursuit >> 16) + ((D_80100250_PiranhasPursuit << 16) >> 31);
}

void func_800F9D78_PiranhasPursuit(f32 zoom, f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz) {
    D_801010FA_PiranhasPursuit = 0;
    D_801010F8_PiranhasPursuit = 0;
    CZoom = zoom;
    CRot.x = rx;
    CRot.y = ry;
    CRot.z = rz;
    Center.x = cx;
    Center.y = cy;
    Center.z = cz;
    D_801010F0_PiranhasPursuit = zoom;
    D_801010D8_PiranhasPursuit.x = rx;
    D_801010D8_PiranhasPursuit.y = ry;
    D_801010D8_PiranhasPursuit.z = rz;
    D_801010C0_PiranhasPursuit.x = cx;
    D_801010C0_PiranhasPursuit.y = cy;
    D_801010C0_PiranhasPursuit.z = cz;
}

void func_800F9E00_PiranhasPursuit(f32 zoom, f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz, u16 frames) {
    D_801010F4_PiranhasPursuit = zoom;
    D_801010CC_PiranhasPursuit.x = cx;
    D_801010CC_PiranhasPursuit.y = cy;
    D_801010CC_PiranhasPursuit.z = cz;
    D_801010E4_PiranhasPursuit.x = rx;
    D_801010E4_PiranhasPursuit.y = ry;
    D_801010E4_PiranhasPursuit.z = rz;
    if (D_801010F8_PiranhasPursuit != 0) {
        func_800F9EE8_PiranhasPursuit();
    }
    D_801010F8_PiranhasPursuit = D_801010FA_PiranhasPursuit = frames;
}

void func_800F9E84_PiranhasPursuit(void) {
    D_801010F0_PiranhasPursuit = D_801010F4_PiranhasPursuit;
    D_801010D8_PiranhasPursuit.x = D_801010E4_PiranhasPursuit.x;
    D_801010D8_PiranhasPursuit.y = D_801010E4_PiranhasPursuit.y;
    D_801010D8_PiranhasPursuit.z = D_801010E4_PiranhasPursuit.z;
    D_801010C0_PiranhasPursuit.x = D_801010CC_PiranhasPursuit.x;
    D_801010C0_PiranhasPursuit.y = D_801010CC_PiranhasPursuit.y;
    D_801010C0_PiranhasPursuit.z = D_801010CC_PiranhasPursuit.z;
}

void func_800F9EE8_PiranhasPursuit(void) {
    D_801010F0_PiranhasPursuit = CZoom;
    D_801010D8_PiranhasPursuit.x = CRot.x;
    D_801010D8_PiranhasPursuit.y = CRot.y;
    D_801010D8_PiranhasPursuit.z = CRot.z;
    D_801010C0_PiranhasPursuit.x = Center.x;
    D_801010C0_PiranhasPursuit.y = Center.y;
    D_801010C0_PiranhasPursuit.z = Center.z;
}

void func_800F9F4C_PiranhasPursuit(omObjData* obj) {
    f32 t;

    if (D_801010F8_PiranhasPursuit != 0) {
        if (--D_801010F8_PiranhasPursuit == 0) {
            func_800F9E84_PiranhasPursuit();
        }
        t = (f32)((s16)D_801010FA_PiranhasPursuit - D_801010F8_PiranhasPursuit) / (s16)D_801010FA_PiranhasPursuit;
        CZoom = D_801010F0_PiranhasPursuit + (D_801010F4_PiranhasPursuit - D_801010F0_PiranhasPursuit) * t;
        CRot.x = D_801010D8_PiranhasPursuit.x + (D_801010E4_PiranhasPursuit.x - D_801010D8_PiranhasPursuit.x) * t;
        CRot.y = D_801010D8_PiranhasPursuit.y + (D_801010E4_PiranhasPursuit.y - D_801010D8_PiranhasPursuit.y) * t;
        CRot.z = D_801010D8_PiranhasPursuit.z + (D_801010E4_PiranhasPursuit.z - D_801010D8_PiranhasPursuit.z) * t;
        Center.x = D_801010C0_PiranhasPursuit.x + (D_801010CC_PiranhasPursuit.x - D_801010C0_PiranhasPursuit.x) * t;
        Center.y = D_801010C0_PiranhasPursuit.y + (D_801010CC_PiranhasPursuit.y - D_801010C0_PiranhasPursuit.y) * t;
        Center.z = D_801010C0_PiranhasPursuit.z + (D_801010CC_PiranhasPursuit.z - D_801010C0_PiranhasPursuit.z) * t;
    }
}
