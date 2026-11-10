#include "CrazyCutter.h"

/* .data (0x800FCCF0) */
f32 D_800FCCF0_CrazyCutter[4] = { -690.0f, 140.0f, -690.0f, 140.0f };
f32 D_800FCD00_CrazyCutter[4] = { -530.0f, -530.0f, 95.0f, 95.0f };
/* 3x3 and 1x1 cut masks for func_800FC70C_CrazyCutter / func_800FCAAC_CrazyCutter */
s8 D_800FCD10_CrazyCutter[12] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0 };
s8 D_800FCD1C_CrazyCutter[4] = { -1, 0, 0, 0 };
/* per character: model directory, then model and motion file ids */
s32 D_800FCD20_CrazyCutter[6] = { 1, 2, 6, 3, 4, 5 };
s32 D_800FCD38_CrazyCutter[6] = { 0x9F, 0x9F, 0x9F, 0x9F, 0x9F, 0x9F };
s32 D_800FCD50_CrazyCutter[6] = { 0, 0, 0, 0, 0, 0 };
s32 D_800FCD68_CrazyCutter[6] = { 0xF, 0xF, 0xF, 0xF, 0xF, 0xF };
s32 D_800FCD80_CrazyCutter[6] = { 0x38, 0x38, 0x38, 0x38, 0x38, 0x38 };
s32 D_800FCD98_CrazyCutter[6] = { 0x10, 0x10, 0x10, 0x10, 0x10, 0x10 };
s32 D_800FCDB0_CrazyCutter[6] = { 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C };
s32 D_800FCDC8_CrazyCutter[6] = { 5, 5, 5, 5, 5, 5 };
s32 D_800FCDE0_CrazyCutter[6] = { 0x62, 0x62, 0x62, 0x62, 0x62, 0x62 };
/* CPU routes per shape: (x, y) pairs; (-3, -3) start, (-2, -2) end, -1 terminator */
s32 D_800FCDF8_CrazyCutter[31] = {
    0x2E, 0x1B, 0x33, 0x1E, 0x2D, 0x24, 0x26, 0x28, 0x1A, 0x28, 0x14, 0x26, 0x0E, 0x1F, 0x12, 0x1B,
    0x13, 0x15, 0x18, 0x0C, 0x1D, 0x0A, 0x20, 0x09, 0x28, 0x0D, -3, -3, -2, -2, -1,
};
s32 D_800FCE74_CrazyCutter[47] = {
    0x2F, 0x15, 0x2F, 0x18, 0x2B, 0x1C, 0x26, 0x1C, 0x28, 0x27, 0x27, 0x29, 0x23, 0x29, 0x23, 0x27,
    0x1F, 0x25, 0x1C, 0x27, 0x1C, 0x29, 0x19, 0x29, 0x17, 0x28, 0x19, 0x1C, 0x14, 0x1C, 0x10, 0x18,
    0x10, 0x12, 0x15, 0x0D, 0x17, 0x0B, 0x20, 0x09, 0x29, 0x0B, -3, -3, -2, -2, -1,
};
s32 D_800FCF30_CrazyCutter[27] = {
    0x2C, 0x19, 0x2C, 0x21, 0x28, 0x27, 0x22, 0x2A, 0x1C, 0x2A, 0x15, 0x26, 0x12, 0x21, 0x12, 0x18,
    0x1C, 0x0A, 0x1F, 0x09, 0x22, 0x0A, -3, -3, -2, -2, -1,
};
s32 D_800FCF9C_CrazyCutter[3] = { 7, 6, 10 };
s16 D_800FCFA8_CrazyCutter[4][2] = { { 0x38, 0x5A }, { 0xD8, 0x5A }, { 0x38, 0xD2 }, { 0xD8, 0xD2 } };
/* Unreferenced. */
s32 D_800FCFB8_CrazyCutter[6] = { 0x29E, 0x29E, 0x23A, 0, 0, 0 };
u8 D_800FCFD0_CrazyCutter[0x40] = {
    0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
    0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0,
    0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x00,
};

// register allocation: retail keeps i * 2 for the D_800FD588 store live across the call in a fifth
// saved register (raw 32, masked 10; tried an s32 return for func_800FC024, D[i] = temp = call,
// the call nested in func_800FC240's argument)
#ifdef NON_MATCHING
void func_800F65E0_CrazyCutter(void) {
    s32 i;
    s16 temp;

    func_80029090(20);
    func_8001DE70(66);
    omInitObjMan(40, 0);
    func_80060088();
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    D_800FD464_CrazyCutter = 0;
    D_800FD548_CrazyCutter = 0;
    func_800F6938_CrazyCutter(7000.0f, 270.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
    func_8005D98C(4, 4);
    omAddObj(10, 0, 0, -1, func_800F9654_CrazyCutter);
    D_800FD480_CrazyCutter = (u8)(rand8() % 3);
    if (ContBtn[0] & 0x8000) {
        D_800FD480_CrazyCutter = 0;
    }
    if (ContBtn[0] & 0x4000) {
        D_800FD480_CrazyCutter = 1;
    }
    if (ContBtn[0] & 4) {
        D_800FD480_CrazyCutter = 2;
    }
    D_800FD53C_CrazyCutter = 2.0f;
    D_800FD4B0_CrazyCutter = 0;
    D_800FD530_CrazyCutter = -1;
    D_800FD534_CrazyCutter = -1;
    D_800FD538_CrazyCutter = -1;
    D_800FD460_CrazyCutter = 71;
    omAddObj(12, 0, 0, -1, func_800F69EC_CrazyCutter);
    D_800FD468_CrazyCutter = 1;
    func_8002890C(0, 0, 0);
    func_800FBFB4_CrazyCutter();
    for (i = 0; i < 4; i++) {
        temp = func_800FC024_CrazyCutter((*(D_800FCFA8_CrazyCutter + i))[0], (*(D_800FCFA8_CrazyCutter + i))[1]);
        D_800FD588_CrazyCutter[i] = temp;
        func_800FC240_CrazyCutter(temp);
    }
    D_800FD590_CrazyCutter = 0;
    D_800FD14E_CrazyCutter = 30;
    D_800FD554_CrazyCutter = _CheckFlag(0x2B);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_CrazyCutter/1250D0", func_800F65E0_CrazyCutter);
#endif
void func_800F686C_CrazyCutter(omObjData* arg0) {
    D_800FD460_CrazyCutter--;
    if (D_800FD460_CrazyCutter == 0) {
        D_800FD460_CrazyCutter = 20;
        GMesCreate(0);
        arg0->func_ptr = &func_800F68C4_CrazyCutter;
    }
}

void func_800F68C4_CrazyCutter(omObjData* arg0) {
    if (GMesStatAllGet() == 0 || GMesStatAllGet() & 2) {
        D_800FD460_CrazyCutter--;
        if (D_800FD460_CrazyCutter == 0) {
            D_800FD4B0_CrazyCutter = 1;
            func_800F978C_CrazyCutter();
            arg0->func_ptr = &func_800F97C8_CrazyCutter;
        }
    }
}

void func_800F6938_CrazyCutter(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    func_800178A0(1);
    CZoom = arg0;
    CRot.x = arg1;
    CRot.y = arg2;
    CRot.z = arg3;
    Center.x = arg4;
    Center.y = arg5;
    Center.z = arg6;
    func_8001D494(0, 10.0f, D_800C3110->unk_44, D_800C3110->unk_48);
}

void func_800F69EC_CrazyCutter(omObjData* arg0) {
    D_800FD468_CrazyCutter--;
    if (D_800FD468_CrazyCutter == 0) {
        D_800FD464_CrazyCutter = 1;
        omAddObj(4, 10, 10, 4, &func_800F94C0_CrazyCutter);
        omAddObj(4, 10, 10, 4, &func_800F94DC_CrazyCutter);
        omAddObj(4, 10, 10, 4, &func_800F94F8_CrazyCutter);
        omAddObj(4, 10, 10, 4, &func_800F9514_CrazyCutter);
        omAddObj(0, 0, 0, -1, &func_800F686C_CrazyCutter);
        omAddObj(2, 1, 1, -1, &func_800F6B04_CrazyCutter);
        SetFadeInTypeAndTime(0, 16);
        omDelObj(arg0);
    }
}

// sprite ids: retail lbu+sign-extend+andi 0xFFFF, C lb (callees mask the id); masked 39
#ifdef NON_MATCHING
void func_800F6B04_CrazyCutter(omObjData* obj) {
    s32 kinds[3] = { 9, 10, 11 };
    Vec3f* pos;
    s32 i;
    s32 x;
    s32 y;
    s8 sprite;
    u16 model;
    void* data;

    func_80017660(0, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    sprite = InitSprite(0x1F0019);
    i = 0;
    for (y = 0; y < 8; y++) {
        for (x = 0; x < 10; x++) {
            D_800FD170_CrazyCutter[i] = func_80019060(sprite, 0, 1);
            func_80018D44(D_800FD170_CrazyCutter[i], 0x4008);
            D_800FD1C0_CrazyCutter[i] = x * 32 + 16;
            D_800FD300_CrazyCutter[i] = y * 32 + 16;
            SetBasicSpritePos(D_800FD170_CrazyCutter[i], D_800FD1C0_CrazyCutter[i], D_800FD300_CrazyCutter[i]);
            ShowBasicSprite(D_800FD170_CrazyCutter[i]);
            SetBasicSpriteSize(D_800FD170_CrazyCutter[i], 1.0f, 1.0f);
            i++;
        }
    }
    for (y = 0; y < 2; y++) {
        for (x = 0; x < 2; x++) {
            D_800FD156_CrazyCutter[y * 2 + x] = InitSprite(kinds[D_800FD480_CrazyCutter] | 0x1F0000);
            D_800FD160_CrazyCutter[y * 2 + x] = func_80019060(D_800FD156_CrazyCutter[y * 2 + x], 0, 1);
            func_80018D44(D_800FD160_CrazyCutter[y * 2 + x], 0x4008);
            D_800FD440_CrazyCutter[y * 2 + x] = x * 160 + 80;
            D_800FD450_CrazyCutter[y * 2 + x] = y * 120 + 60;
            SetBasicSpritePos(D_800FD160_CrazyCutter[y * 2 + x], D_800FD440_CrazyCutter[y * 2 + x], D_800FD450_CrazyCutter[y * 2 + x]);
            ShowBasicSprite(D_800FD160_CrazyCutter[y * 2 + x]);
            SetBasicSpriteSize(D_800FD160_CrazyCutter[y * 2 + x], 1.0f, 1.0f);
        }
    }
    pos = func_80023684(sizeof(Vec3f), 0x7918);
    obj->unk_50 = pos;
    *obj->model = LoadFormFile(0x1F0006, 0x689);
    model = *obj->model;
    pos->x = 0.0f;
    pos->y = 0.0f;
    pos->z = 0.0f;
    omSetTra(obj, pos->x, pos->y, pos->z);
    omSetRot(obj, 0.0f, 0.0f, 0.0f);
    data = DataRead(0x1F000F);
    func_80038A9C(D_800F2B7C[model].unk_6C, data, 0, "16mt013_DEF");
    func_80025AD4(model);
    func_80025B34(model);
    HuMemDirectFree(data);
    obj->func_ptr = &func_800F6F00_CrazyCutter;
}
#else
/* GCC cannot see the previous INCLUDE_ASM switch to .text */
__asm__(".section .rodata");
const s32 D_800FD010_CrazyCutter[3] __attribute__((section(".rodata"))) = { 9, 10, 11 };
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_CrazyCutter/1250D0", func_800F6B04_CrazyCutter);
#endif
// sprite ids as in func_800F6B04 (lb vs lbu+extend+mask); masked 65
#ifdef NON_MATCHING
void func_800F6F00_CrazyCutter(omObjData* obj) {
    Vec3f* pos = obj->unk_50;
    s32 i;

    if (D_800FD548_CrazyCutter == 1 || D_800FD548_CrazyCutter == 2) {
        if (D_800FD54C_CrazyCutter & 1) {
            for (i = 0; i < 80; i++) {
                SetBasicSpritePos(D_800FD170_CrazyCutter[i], D_800FD1C0_CrazyCutter[i], D_800FD300_CrazyCutter[i] + D_800FD54A_CrazyCutter);
            }
            for (i = 0; i < 4; i++) {
                SetBasicSpritePos(D_800FD160_CrazyCutter[i], D_800FD440_CrazyCutter[i], D_800FD450_CrazyCutter[i] + D_800FD54A_CrazyCutter);
            }
            omSetTra(obj, pos->x, pos->y, pos->z + D_800FD548_CrazyCutter * 5.0f);
        } else {
            for (i = 0; i < 80; i++) {
                SetBasicSpritePos(D_800FD170_CrazyCutter[i], D_800FD1C0_CrazyCutter[i], D_800FD300_CrazyCutter[i]);
            }
            for (i = 0; i < 4; i++) {
                SetBasicSpritePos(D_800FD160_CrazyCutter[i], D_800FD440_CrazyCutter[i], D_800FD450_CrazyCutter[i]);
            }
            omSetTra(obj, pos->x, pos->y, pos->z);
        }
    }
    if (D_800FD548_CrazyCutter == 3) {
        func_8006071C(D_800FD5C2_CrazyCutter);
        omAddObj(12, 0, 0, -1, &func_800F7180_CrazyCutter);
        D_800FD460_CrazyCutter = 0;
        omDelObj(obj);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_CrazyCutter/1250D0", func_800F6F00_CrazyCutter);
#endif
// branch layout, retail reloads the counter (masked 37)
#ifdef NON_MATCHING
void func_800F7180_CrazyCutter(omObjData* arg0) {
    s32 i;
    s32 end;

    if (D_800FD554_CrazyCutter == 0) {
        D_800FD460_CrazyCutter++;
        if (D_800FD544_CrazyCutter == 4) {
            if (D_800FD460_CrazyCutter == 15) {
                func_80060128(55);
            }
            end = 90;
            if (D_800FD460_CrazyCutter == 55) {
                for (i = 0; i < 4; i++) {
                    func_800FAACC_CrazyCutter(i, 2, 1);
                }
                end = 90;
            }
        } else if (D_800FD544_CrazyCutter == 0) {
            end = 90;
            if (D_800FD460_CrazyCutter == 1) {
                func_80060128(52);
                for (i = 0; i < 4; i++) {
                    func_800FAACC_CrazyCutter(i, 4, 1);
                }
                end = 90;
            }
        } else {
            if (D_800FD460_CrazyCutter == 15) {
                func_80060128(60);
            }
            if (D_800FD460_CrazyCutter == 55) {
                for (i = 0; i < 4; i++) {
                    func_800FAACC_CrazyCutter(i, func_800FAAB0_CrazyCutter(i, 0x10000) ? 2 : 4, 1);
                }
            }
            end = 80;
        }
        if (D_800FD460_CrazyCutter == end) {
            arg0->func_ptr = &func_800FA9D8_CrazyCutter;
        }
    } else {
        arg0->func_ptr = &func_800FA9D8_CrazyCutter;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_CrazyCutter/1250D0", func_800F7180_CrazyCutter);
#endif

// register pressure: spills/reloads and loop layout (masked 224)
#ifdef NON_MATCHING
void func_800F731C_CrazyCutter(omObjData* obj, s32 player) {
    s32 px[30];
    s32 py[30];
    s32 motions[6] = { 0x54, 0x54, 0x54, 0x54, 0x54, 0x54 };
    Vec3f pos;
    s32 chance[4] = { 10, 7, 4, 1 };
    s32 offset[4] = { 4, 3, 2, 1 };
    s16 from[2];
    s16 to[2];
    CrazyCutterPlayer* st;
    s32 i;
    s32 count;
    s32 dx;
    s32 dy;
    s32 done;
    s32 dir;
    s16 model;
    void* data;
    f32 prevAngle;
    f32 angle;
    f32 diff1;
    f32 diff2;
    s32 n;

    if (D_800FD464_CrazyCutter == 0) {
        return;
    }
    D_800FD5A0_CrazyCutter[player] = obj;
    obj->unk_50 = func_80023684(sizeof(CrazyCutterPlayer), 0x7918);
    for (i = 0; i < 4; i++) {
        obj->work[i] = 0;
    }
    st = obj->unk_50;
    st->x = 620.0f;
    st->y = 0.0f;
    st->z = 150.0f;
    st->rotX = 290.0f;
    st->rotY = 0.0f;
    st->rotZ = 0.0f;
    st->velX = 0;
    st->angle = 0;
    st->unk28 = 0;
    st->unk3F8 = -1;
    st->unk3FC = -1;
    st->player = player;
    st->unk2C = 0;
    st->unk518 = 1;
    for (i = 0; i < 60; i++) {
        st->trailX[i] = 0;
        st->trailY[i] = 0;
        st->visitedX[i] = 0;
        st->visitedY[i] = 0;
    }
    st->visitedCount = 0;
    D_800FD4D8_CrazyCutter[player] = 0;
    D_800FD4B8_CrazyCutter[player] = 0;
    D_800FD4C8_CrazyCutter[player] = 0;
    st->state = 0;
    if (GwPlayer[player].flags & 1) {
        switch (GwPlayer[player].cpu_difficulty) {
            case 0:
                st->difficulty = 0;
                break;
            case 1:
                st->difficulty = 1;
                break;
            case 2:
                st->difficulty = 2;
                break;
            case 3:
                st->difficulty = 3;
                break;
        }
    } else {
        st->difficulty = 1;
    }
    st->prevX = 0;
    st->prevZ = 0;
    st->unk400 = 0;
    D_800FD470_CrazyCutter[player] = func_800FA38C_CrazyCutter(player);
    st->startX = st->x;
    st->startZ = st->z;
    do {
        st->startX -= 1.0f;
        pos.x = D_800FCCF0_CrazyCutter[player] + st->startX - 8.0f;
        pos.y = st->y + 10.0f;
        pos.z = D_800FCD00_CrazyCutter[player] + st->z - 8.0f;
        func_800F9694_CrazyCutter(&pos, from, player);
    } while (D_800FD4A0_CrazyCutter[player][from[1] * D_800FD498_CrazyCutter + from[0]] == 0);
    st->startX -= 15.0f;
    if (D_800FD480_CrazyCutter == 1) {
        st->startX -= 15.0f;
    }
    dir = D_800FCD20_CrazyCutter[GwPlayer[player].character] << 16;
    *obj->model = LoadFormFile(dir | D_800FCD38_CrazyCutter[GwPlayer[player].character], 0x699);
    omSetTra(obj, D_800FCCF0_CrazyCutter[player] + st->x, st->y, D_800FCD00_CrazyCutter[player] + st->z + -4.0f);
    omSetRot(obj, st->rotX, st->rotY, st->rotZ);
    func_80025798(*obj->model, st->x, st->y, st->z);
    func_8001775C(obj, 1, dir | motions[player]);
    func_8001775C(obj, 0, dir | D_800FCD50_CrazyCutter[player]);
    if (rand8() & 1) {
        func_8001775C(obj, 2, dir | D_800FCD68_CrazyCutter[player]);
    } else {
        func_8001775C(obj, 2, dir | D_800FCD80_CrazyCutter[player]);
    }
    if (rand8() & 1) {
        func_8001775C(obj, 3, dir | D_800FCD98_CrazyCutter[player]);
    } else {
        func_8001775C(obj, 3, dir | D_800FCDB0_CrazyCutter[player]);
    }
    func_8001775C(obj, 4, dir | D_800FCDC8_CrazyCutter[player]);
    func_8001775C(obj, 5, dir | D_800FCDE0_CrazyCutter[player]);
    func_80025BB8(obj->model[0], obj->motion[0]);
    func_80025EB4(obj->model[0], 2, 2);

    obj->model[1] = LoadFormFile(0x1F0000, 0x689);
    model = obj->model[1];
    func_80025798(model, D_800FCCF0_CrazyCutter[player] + st->startX, st->y + 30.0f, D_800FCD00_CrazyCutter[player] + st->startZ - 10.0f);
    func_800257E4(obj->model[1], st->rotX, st->rotY, st->rotZ);
    func_80025830(obj->model[1], 1.0f, 1.0f, 1.0f);
    data = DataRead(0x1F0008);
    st->unk418 = func_80038A9C(D_800F2B7C[(u16)model].unk_6C, data, 0, "16mt000_DEF");
    func_80025AD4(model);
    func_80025B34(model);
    HuMemDirectFree(data);
    func_80039644(st->unk418, 1, 1);

    obj->model[2] = LoadFormFile(0x1F0000, 0x68D);
    model = obj->model[2];
    func_80025798(model, D_800FCCF0_CrazyCutter[player] + st->startX, st->y + 20.0f, D_800FCD00_CrazyCutter[player] + st->startZ + 10.0f);
    func_800257E4(obj->model[2], st->rotX, st->rotY, st->rotZ);
    func_80025830(obj->model[2], 1.5f, 1.0f, 1.5f);
    data = DataRead(0x1F0007);
    st->unk41A = func_80038A9C(D_800F2B7C[(u16)model].unk_6C, data, 0, "16mt000_DEF");
    func_80025AD4(model);
    func_80025B34(model);
    HuMemDirectFree(data);
    func_80039644(st->unk41A, 1, 1);

    st->moving = 0;
    st->target = 0;
    count = 0;
    switch (D_800FD480_CrazyCutter) {
        case 0:
            D_800FD130_CrazyCutter = D_800FCDF8_CrazyCutter;
            D_800FD59A_CrazyCutter = 6;
            break;
        case 1:
            D_800FD130_CrazyCutter = D_800FCE74_CrazyCutter;
            D_800FD59A_CrazyCutter = 6;
            break;
        case 2:
            D_800FD130_CrazyCutter = D_800FCF30_CrazyCutter;
            D_800FD59A_CrazyCutter = 8;
            break;
    }
    dx = 0;
    dy = 0;
    while (*D_800FD130_CrazyCutter != -1) {
        px[count] = *D_800FD130_CrazyCutter++;
        py[count] = *D_800FD130_CrazyCutter++;
        if (px[count] > 0 && (GwPlayer[player].flags & 1)) {
            done = 0;
            do {
                if ((rand8() & 0x1F) < chance[st->difficulty]) {
                    if ((D_800FD480_CrazyCutter == 1) & (count >= 4) && count < 13) {
                        dx = (u8)(rand8() % 3) - 1;
                        dy = (u8)(rand8() % 3) - 1;
                    } else {
                        dx = rand8() % (8 - st->difficulty * 2) - offset[st->difficulty];
                        dy = rand8() % (8 - st->difficulty * 2) - offset[st->difficulty];
                    }
                    px[count] += dx;
                    py[count] += dy;
                    if (px[count] < 10) {
                        px[count] = 10;
                    }
                    if (px[count] > 52) {
                        px[count] = 52;
                    }
                    if (py[count] < 8) {
                        py[count] = 8;
                    }
                    if (py[count] > 44) {
                        py[count] = 44;
                    }
                }
                if (count > 0) {
                    if (px[count] < px[count - 1] - 1 || px[count - 1] + 1 < px[count]
                        || py[count] < py[count - 1] - 1 || py[count - 1] + 1 < py[count]) {
                        if (count == 1) {
                            prevAngle = 5.0f;
                        } else {
                            from[0] = px[count - 2];
                            from[1] = py[count - 2];
                            to[0] = px[count - 1];
                            to[1] = py[count - 1];
                            prevAngle = func_800FAC38_CrazyCutter(from, to, 0);
                        }
                        from[0] = px[count - 1];
                        from[1] = py[count - 1];
                        to[0] = px[count] + dx;
                        to[1] = py[count] + dy;
                        angle = func_800FAC38_CrazyCutter(from, to, 0);
                        diff1 = prevAngle - angle;
                        while (diff1 < 0.0f) {
                            diff1 += 360.0f;
                        }
                        while (diff1 > 360.0f) {
                            diff1 -= 360.0f;
                        }
                        diff2 = angle - prevAngle;
                        while (diff2 < 0.0f) {
                            diff2 += 360.0f;
                        }
                        while (diff2 > 360.0f) {
                            diff2 -= 360.0f;
                        }
                        if (diff2 < diff1) {
                            diff1 = diff2;
                        }
                        if (diff1 <= 160.0f) {
                            done++;
                        }
                    }
                } else {
                    done++;
                }
            } while (done == 0);
        }
        count++;
    }
    D_800FD130_CrazyCutter -= 2;
    px[count] = D_800FD130_CrazyCutter[0];
    py[count] = D_800FD130_CrazyCutter[0];
    if (!(rand8() & 1)) {
        n = count - 1;
        for (i = 0; i < n; i++) {
            st->pathX[i] = px[count - i - 2];
            st->pathY[i] = py[count - i - 2];
        }
    } else {
        for (i = 0; i < count; i++) {
            st->pathX[i] = px[i];
            st->pathY[i] = py[i];
        }
    }
    st->pathX[count - 1] = px[count - 1];
    st->pathY[count - 1] = py[count - 1];
    func_800FAACC_CrazyCutter(st->player, 0x400, 1);
    st->timer = 1;
    func_800F9968_CrazyCutter(obj, player);
    obj->func_ptr = &func_800F8144_CrazyCutter;
}
#else
/* GCC cannot see the previous INCLUDE_ASM switch to .text */
__asm__(".section .rodata");
const s32 D_800FD028_CrazyCutter[6] __attribute__((section(".rodata"))) = { 0x54, 0x54, 0x54, 0x54, 0x54, 0x54 };
const s32 D_800FD040_CrazyCutter[4] __attribute__((section(".rodata"))) = { 10, 7, 4, 1 };
const s32 D_800FD050_CrazyCutter[4] __attribute__((section(".rodata"))) = { 4, 3, 2, 1 };
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_CrazyCutter/1250D0", func_800F731C_CrazyCutter);
#endif
// route search loop rotated (masked 23)
#ifdef NON_MATCHING
void func_800F8144_CrazyCutter(omObjData* obj) {
    CrazyCutterPlayer* st = obj->unk_50;
    s16 cur[2];
    s16 next[2];
    Vec3f pos;
    s32 i;

    if (func_800FAAB0_CrazyCutter(st->player, 0x400) != 0) {
        if (--st->timer == 0) {
            func_80025BB8(obj->model[0], obj->motion[4]);
            func_800FAACC_CrazyCutter(st->player, 0x400, 0);
            func_800FAACC_CrazyCutter(st->player, 0x200, 1);
            st->velZ = -7.0f;
            st->timer = 20;
            st->velX = (st->startX - st->x) / 30.0f;
            st->rotZ = 90.0f;
            omSetRot(obj, st->rotX, st->rotY, 90.0f);
            st->state = 4;
            D_800FD5C4_CrazyCutter = func_80060128(0x1D);
        }
    }
    if (func_800FAAB0_CrazyCutter(st->player, 0x200) != 0) {
        st->x += st->velX;
        st->z += st->velZ;
        st->timer--;
        omSetTra(obj, D_800FCCF0_CrazyCutter[st->player] + st->x, st->y, D_800FCD00_CrazyCutter[st->player] + st->z + -4.0f);
        st->velZ += 0.49f;
        if (st->velZ >= 0.0f && st->state == 4) {
            func_80025BB8(obj->model[0], obj->motion[5]);
            st->state = 5;
        }
        if (st->x <= st->startX + 40.0f) {
            st->x = st->startX;
            st->z = st->startZ;
            st->rotZ = 0.0f;
            func_80025BB8(obj->model[0], obj->motion[1]);
            func_80025EB4(obj->model[0], 2, 2);
            omSetTra(obj, D_800FCCF0_CrazyCutter[st->player] + st->x, st->y, D_800FCD00_CrazyCutter[st->player] + st->z + -4.0f);
            omSetRot(obj, st->rotX, st->rotY, st->rotZ);
            func_800FAACC_CrazyCutter(st->player, 0x200, 0);
            func_80039644(st->unk418, 1, 0);
            func_800258EC(obj->model[2], 4, 0);
            func_80039644(st->unk41A, 1, 0);
            func_80039644(st->unk41A, 2, 0);
            pos.x = D_800FCCF0_CrazyCutter[st->player] + st->x - 8.0f;
            pos.y = st->y + 10.0f;
            pos.z = D_800FCD00_CrazyCutter[st->player] + st->z - 8.0f;
            func_800F9694_CrazyCutter(&pos, cur, st->player);
            for (i = 0; st->pathX[i] != -3; i++) {
            }
            st->pathX[i] = cur[0] + 1;
            st->pathY[i] = cur[1];
            D_800FD550_CrazyCutter = i;
            if (GwPlayer[st->player].flags & 1) {
                next[0] = st->pathX[st->target];
                next[1] = st->pathY[st->target];
                st->angle = func_800FAC38_CrazyCutter(cur, next, 0);
            }
            obj->func_ptr = &func_800F8598_CrazyCutter;
            if (st->player == 0) {
                D_800FD5C6_CrazyCutter = PlaySound(0x234);
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_CrazyCutter/1250D0", func_800F8144_CrazyCutter);
#endif
// float temporaries and register allocation (masked 90)
#ifdef NON_MATCHING
void func_800F8598_CrazyCutter(omObjData* obj) {
    CrazyCutterPlayer* st = obj->unk_50;
    Vec3f pos;
    s16 cur[2];
    Vec2f screen;
    s32 sx;
    s16 grp;
    s32 hits;
    s32 i;
    s32 gx;
    s32 gy;
    s8 port;
    s8 stickX;
    s8 stickY;
    f32 fx;
    f32 fy;
    f32 angle;
    f32 mag;
    f32 dx;
    f32 dz;

    omSetTra(obj, D_800FCCF0_CrazyCutter[st->player] + st->x, st->y, D_800FCD00_CrazyCutter[st->player] + st->z + st->unk2C + -4.0f);
    omSetRot(obj, st->rotX, st->rotY, st->rotZ);
    func_80025798(obj->model[1], D_800FCCF0_CrazyCutter[st->player] + st->x, st->y + 30.0f, D_800FCD00_CrazyCutter[st->player] + st->z + st->unk2C - 10.0f);
    func_800257E4(obj->model[1], st->rotX, st->rotY, st->rotZ);
    func_80025798(obj->model[2], D_800FCCF0_CrazyCutter[st->player] + st->x, st->y + 20.0f, D_800FCD00_CrazyCutter[st->player] + st->z + st->unk2C - 12.0f);
    func_800257E4(obj->model[2], st->rotX, st->rotY, st->rotZ);
    pos.x = D_800FCCF0_CrazyCutter[st->player] + st->x - 8.0f;
    pos.y = st->y + 10.0f;
    pos.z = D_800FCD00_CrazyCutter[st->player] + st->z - 8.0f;
    Convert3DTo2D(0, &pos, &screen);
    sx = screen.x;
    cur[0] = sx;
    cur[1] = screen.y;
    if (st->player & 1) {
        cur[0] = sx - 160;
    }
    if (st->player / 2) {
        cur[1] -= 120;
    }
    grp = func_800FBAFC_CrazyCutter(D_800FD160_CrazyCutter[st->player]);
    hits = func_800FC70C_CrazyCutter(grp, 0, cur[0], cur[1], 3, 3, D_800FCD10_CrazyCutter);
    if (st->moving != 0 && (hits == 0 || func_800FBEA8_CrazyCutter(grp, 0, cur[0], cur[1]) == 0)
        && func_800F8F74_CrazyCutter(st, cur) == 0) {
        if (GwPlayer[st->player].flags & 1) {
            if (D_800FD14E_CrazyCutter < D_800FCF9C_CrazyCutter[D_800FD480_CrazyCutter]) {
                func_800FAACC_CrazyCutter(st->player, 1, 1);
            }
            for (i = 0; i < 30; i++) {
                if (cur[0] >= st->visitedX[i] - 10 && st->visitedX[i] + 10 >= cur[0]
                    && cur[1] >= st->visitedY[i] - 10 && st->visitedY[i] + 10 >= cur[1]) {
                    func_800FAACC_CrazyCutter(st->player, 1, 1);
                    func_800FAACC_CrazyCutter(st->player, 0x800, 1);
                }
            }
        } else {
            if (D_800FD14E_CrazyCutter < D_800FCF9C_CrazyCutter[D_800FD480_CrazyCutter]) {
                func_800FAACC_CrazyCutter(st->player, 1, 1);
            }
            for (i = 0; i < 30; i++) {
                if (cur[0] >= st->visitedX[i] - 5 && st->visitedX[i] + 5 >= cur[0]
                    && cur[1] >= st->visitedY[i] - 5 && st->visitedY[i] + 5 >= cur[1]) {
                    func_800FAACC_CrazyCutter(st->player, 1, 1);
                    func_800FAACC_CrazyCutter(st->player, 0x800, 1);
                }
            }
        }
    }
    gx = cur[0] * 0.4f;
    gy = cur[1] * 0.4f;
    func_800FAACC_CrazyCutter(st->player, 0x40, 0);
    if (func_800FAAB0_CrazyCutter(st->player, 0x8000) != 0) {
        if (func_800FB944_CrazyCutter(st) != 0) {
            D_800FD4B8_CrazyCutter[st->player]++;
            func_800FAACC_CrazyCutter(st->player, 0x40, 1);
        } else {
            D_800FD4C8_CrazyCutter[st->player]++;
        }
    }
    if (gx >= st->pathX[D_800FD59A_CrazyCutter] - 3 && st->pathX[D_800FD59A_CrazyCutter] + 3 >= gx
        && gy >= st->pathY[D_800FD59A_CrazyCutter] - 3 && st->pathY[D_800FD59A_CrazyCutter] + 3 >= gy) {
        func_800FAACC_CrazyCutter(st->player, 0x1000, 1);
    }
    if (gx >= st->pathX[D_800FD550_CrazyCutter] - 3 && st->pathX[D_800FD550_CrazyCutter] + 3 >= gx
        && gy >= st->pathY[D_800FD550_CrazyCutter] - 3 && st->pathY[D_800FD550_CrazyCutter] + 3 >= gy) {
        func_800FAACC_CrazyCutter(st->player, 0x2000, 1);
    }
    func_800F8FDC_CrazyCutter(st, cur);
    if (func_800FAAB0_CrazyCutter(st->player, 1) != 0 || D_800FD14E_CrazyCutter == 0) {
        func_8002456C(obj->model[1]);
        func_800258EC(obj->model[2], 4, 4);
        func_80025BB8(obj->model[0], obj->motion[0]);
        func_80025EB4(obj->model[0], 2, 2);
        obj->func_ptr = &func_800F90E4_CrazyCutter;
    }
    st->prevX = st->x;
    st->prevZ = st->z;
    port = GwPlayer[st->player].port;
    stickX = 0;
    stickY = 0;
    if (!(GwPlayer[st->player].flags & 1)) {
        if (D_800FD4B0_CrazyCutter != 0) {
            stickX = ContStkX[port];
            stickY = ContStkY[port];
        }
        fx = stickX;
        fy = stickY;
        angle = func_800B0CD8(fy, fx) + 90.0f;
        if (angle < 0.0f) {
            angle += 360.0f;
        }
        mag = fabsf(fx * func_800AEAC0(angle)) + fabsf(fy * func_800AEFD0(angle));
    } else if (D_800FD4B0_CrazyCutter != 0) {
        mag = 40.0f;
        angle = func_800F9530_CrazyCutter(st);
    } else {
        angle = 0.0f;
        mag = 0.0f;
    }
    if (mag < 40.0f) {
        angle = st->angle;
    } else {
        func_800FAACC_CrazyCutter(st->player, 0x8000, 1);
        st->moving = 1;
        st->angle = angle;
    }
    if (--st->unk518 == 0) {
        func_80060F04(st->player, 2, 3, 10);
        st->unk518 = 10;
    }
    dx = 0.0f;
    dz = 0.0f;
    if (st->moving != 0) {
        dx = func_800AEAC0(angle) * D_800FD53C_CrazyCutter;
        dz = func_800AEFD0(angle) * D_800FD53C_CrazyCutter;
    }
    st->x += dx;
    st->z += dz;
    pos.x = D_800FCCF0_CrazyCutter[st->player] + st->x;
    pos.y = st->y;
    pos.z = D_800FCD00_CrazyCutter[st->player] + st->z;
    Convert3DTo2D(0, &pos, &screen);
    if (st->x > 550.0f || st->x < 0.0f) {
        st->x -= dx;
    }
    if (st->z > 490.0f || st->z < 25.0f) {
        st->z -= dz;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_CrazyCutter/1250D0", func_800F8598_CrazyCutter);
#endif
// loop shape: retail has an unused 56-byte frame and the bound 10 in a register tested before the
// loop (a local array or variable bound in the source); masked 14, not attempted further
#ifdef NON_MATCHING
s32 func_800F8F74_CrazyCutter(CrazyCutterPlayer* st, s16* cur) {
    s32 i;

    D_800FD134_CrazyCutter = 0;
    for (i = 0; i < 10; i++) {
        if (cur[0] == st->trailX[i] && cur[1] == st->trailY[i]) {
            D_800FD134_CrazyCutter = 1;
        }
    }
    return D_800FD134_CrazyCutter;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_CrazyCutter/1250D0", func_800F8F74_CrazyCutter);
#endif
void func_800F8FDC_CrazyCutter(CrazyCutterPlayer* st, s16* cur) {
    s32 i;
    s32 found;

    if (st->trailX[0] != cur[0] || st->trailY[0] != cur[1]) {
        for (i = 1; i < 60; i++) {
            st->trailX[60 - i] = st->trailX[59 - i];
            st->trailY[60 - i] = st->trailY[59 - i];
        }
        st->trailX[0] = cur[0];
        st->trailY[0] = cur[1];
    }
    found = 0;
    if (st->visitedCount < 30) {
        for (i = 0; i < 30; i++) {
            if (st->visitedX[i] == cur[0] && st->visitedY[i] == cur[1]) {
                found++;
                break;
            }
        }
        if (found == 0) {
            st->visitedX[st->visitedCount] = cur[0];
            st->visitedY[st->visitedCount] = cur[1];
            st->visitedCount++;
        }
    }
}
void func_800F90E4_CrazyCutter(omObjData* obj) {
    s32 motions[3] = { 0x16, 0x17, 0x18 };
    s32 sprites[3] = { 0x13, 0x14, 0x15 };
    CrazyCutterPlayer* st = obj->unk_50;
    s32 count;
    s32 i;
    f32 end;

    if (D_800FD554_CrazyCutter == 0) {
        if (func_800FAAB0_CrazyCutter(st->player, 2) != 0) {
            func_80025BB8(obj->model[0], obj->motion[2]);
            func_800FAACC_CrazyCutter(st->player, 0x10, 1);
            func_800FAACC_CrazyCutter(st->player, 2, 0);
        }
        if (D_800FD554_CrazyCutter == 0) {
            if (func_800FAAB0_CrazyCutter(st->player, 4) != 0) {
                count = 0;
                for (i = 0; i < 4; i++) {
                    count += func_800FAAB0_CrazyCutter(i, 0x80);
                }
                if (count == 0) {
                    func_80025BB8(obj->model[0], obj->motion[3]);
                    func_800FAACC_CrazyCutter(st->player, 0x10, 1);
                    func_800FAACC_CrazyCutter(st->player, 4, 0);
                    if (D_800FD590_CrazyCutter == 0) {
                        func_800FBB2C_CrazyCutter();
                        D_800FD590_CrazyCutter++;
                    }
                }
            }
        }
    }
    if (func_800FAAB0_CrazyCutter(st->player, 8) != 0) {
        func_800FB640_CrazyCutter(obj, sprites[D_800FD480_CrazyCutter], motions[D_800FD480_CrazyCutter], st->player);
        func_800FAACC_CrazyCutter(st->player, 8, 0);
    }
    if (func_800FAAB0_CrazyCutter(st->player, 0x100) != 0 && D_800FD548_CrazyCutter < 2) {
        D_800FD548_CrazyCutter = 2;
        D_800FD54C_CrazyCutter = 30;
    }
    if (D_800FD548_CrazyCutter > 0 && D_800FD548_CrazyCutter < 3) {
        if (--st->unk518 == 0) {
            func_80060F04(st->player, 10, 0, 10);
            st->unk518 = 5;
        }
        if (D_800FD54C_CrazyCutter & 1) {
            omSetTra(obj, D_800FCCF0_CrazyCutter[st->player] + st->x, st->y,
                     D_800FCD00_CrazyCutter[st->player] + st->z + st->unk2C + -4.0f + D_800FD548_CrazyCutter * 5.0f);
        } else {
            omSetTra(obj, D_800FCCF0_CrazyCutter[st->player] + st->x, st->y,
                     D_800FCD00_CrazyCutter[st->player] + st->z + st->unk2C + -4.0f);
        }
    }
    if (D_800FD548_CrazyCutter == 3 && func_800FAAB0_CrazyCutter(st->player, 0x100) != 0) {
        func_800FAACC_CrazyCutter(st->player, 0x100, 0);
        func_800F98B4_CrazyCutter(st);
    }
    end = func_80025D18(obj->model[0]);
    if (func_80025D40(obj->model[0]) <= end && func_800FAAB0_CrazyCutter(st->player, 0x10) != 0) {
        func_800FAACC_CrazyCutter(st->player, 0x10, 0);
        func_800FAACC_CrazyCutter(st->player, 0x20, 1);
        omDelObj(obj);
    }
}
void func_800F94C0_CrazyCutter(omObjData* arg0) {
    func_800F731C_CrazyCutter(arg0, 0);
}

void func_800F94DC_CrazyCutter(omObjData* arg0) {
    func_800F731C_CrazyCutter(arg0, 1);
}

void func_800F94F8_CrazyCutter(omObjData* arg0) {
    func_800F731C_CrazyCutter(arg0, 2);
}

void func_800F9514_CrazyCutter(omObjData* arg0) {
    func_800F731C_CrazyCutter(arg0, 3);
}

f32 func_800F9530_CrazyCutter(CrazyCutterPlayer* st) {
    Vec3f pos;
    s16 cur[2];
    s16 next[2];

    pos.x = D_800FCCF0_CrazyCutter[st->player] + st->x - 8.0f;
    pos.y = st->y + 10.0f;
    pos.z = D_800FCD00_CrazyCutter[st->player] + st->z - 8.0f;
    func_800F9694_CrazyCutter(&pos, cur, st->player);
    if (cur[0] == st->pathX[st->target] && cur[1] == st->pathY[st->target]) {
        st->target++;
        if (st->pathX[st->target] == -2) {
            st->target = 0;
        }
    }
    next[0] = st->pathX[st->target];
    next[1] = st->pathY[st->target];
    D_800FD138_CrazyCutter = func_800FAC38_CrazyCutter(cur, next, 0);
    return D_800FD138_CrazyCutter;
}
void func_800F9654_CrazyCutter(omObjData* arg0) {
    if (D_800F5144 != 0) {
        func_8006071C(D_800FD5C6_CrazyCutter);
        func_800601D4(40);
        omOvlReturnEx(1);
    }
}

void func_800F9694_CrazyCutter(Vec3f* arg0, s16 arg1[], s32 arg2) {
    Vec2f sp10;

    Convert3DTo2D(0, arg0, &sp10);
    arg1[0] = sp10.x;
    arg1[1] = sp10.y;
    
    if (arg2 & 1) {
        arg1[0] = arg1[0] - 160;
    }
    
    if (arg2 / 2) {
        arg1[1] = arg1[1] - 120;
    }
    
    arg1[0] = arg1[0] * 0.4f;
    arg1[1] = arg1[1] * 0.4f;
}

void func_800F978C_CrazyCutter(void) {
    D_800FD14E_CrazyCutter = 30;
    D_800FD150_CrazyCutter = 30;
    GMesCreate(8, 30, 160, 32);
}

void func_800F97C8_CrazyCutter(omObjData* arg0) {
    s32 i;
    s32 temp;

    D_800FD150_CrazyCutter -= 1;
    if (D_800FD150_CrazyCutter == 0) {
        D_800FD150_CrazyCutter = 30;
        D_800FD14E_CrazyCutter--;
    }

    func_80079078(D_800FD14E_CrazyCutter);
    temp = 0;
    for (i = 0; i < 4; i++) {
        temp += func_800FAAB0_CrazyCutter(i, 1);
    }

    if ((D_800FD14E_CrazyCutter == 0) | (temp == 4)) {
        func_800790C0();
        func_800601D4(40);
        func_8006071C(D_800FD5C6_CrazyCutter);
        arg0->func_ptr = &func_800FA56C_CrazyCutter;
    }
}

void func_800F98B4_CrazyCutter(CrazyCutterPlayer* arg0) {
    D_800FD488_CrazyCutter[arg0->player] = 1;
    D_800FD558_CrazyCutter[arg0->player] = D_800FCCF0_CrazyCutter[arg0->player] + arg0->x;
    D_800FD568_CrazyCutter[arg0->player] = arg0->y;
    D_800FD578_CrazyCutter[arg0->player] = D_800FCD00_CrazyCutter[arg0->player] + arg0->z + -4.0f;
    D_800FD5C8_CrazyCutter = PlaySound(0x237);
}

// register allocation (masked 27)
#ifdef NON_MATCHING
void func_800F9968_CrazyCutter(omObjData* parent, s32 player) {
    f32 xs[4] = { -400.0f, 400.0f, -400.0f, 400.0f };
    f32 zs[4] = { -250.0f, -250.0f, 350.0f, 350.0f };
    f32 sx[3] = { 2.2f, 4.0f, 4.5f };
    f32 sy[3] = { 2.2f, 4.0f, 4.5f };
    f32 sz[3] = { 2.2f, 4.0f, 4.5f };
    f32 zoff[3] = { -30.0f, 50.0f, 0.0f };
    s32 files[3] = { 0x1E0007, 0x1F0005, 0x1F0004 };
    omObjData* obj;
    CrazyCutterPiece* st;
    s32 i;

    obj = omAddObj(12, 5, 2, -1, &func_800F9D98_CrazyCutter);
    omSetStatBit(obj, 0xA0);
    obj->unk_50 = func_80023684(sizeof(CrazyCutterPiece), 0x7918);
    for (i = 0; i < 4; i++) {
        obj->work[i] = 0;
    }
    st = obj->unk_50;
    st->x = xs[player];
    st->y = 0.0f;
    st->z = zs[player] + zoff[D_800FD480_CrazyCutter];
    st->rotX = 270.0f;
    st->rotY = 0.0f;
    st->rotZ = 0.0f;
    st->scaleX = sx[D_800FD480_CrazyCutter];
    st->scaleY = sy[D_800FD480_CrazyCutter];
    st->scaleZ = sz[D_800FD480_CrazyCutter];
    st->player = player;
    st->timer = 60;
    st->velY = 200.0f;
    st->state = 1;
    st->unk3C = 0;
    st->alpha = 0;
    D_800FD488_CrazyCutter[player] = 0;
    if (D_800FD534_CrazyCutter != files[D_800FD480_CrazyCutter]) {
        *obj->model = LoadFormFile(files[D_800FD480_CrazyCutter], 0x68D);
        D_800FD540_CrazyCutter = *obj->model;
        D_800FD4E8_CrazyCutter[st->player].model = LoadFormFile(0x250001, 0x68D);
        D_800FD542_CrazyCutter = D_800FD4E8_CrazyCutter[st->player].model;
        D_800FD534_CrazyCutter = files[D_800FD480_CrazyCutter];
    } else {
        *obj->model = func_80023FC8(D_800FD540_CrazyCutter);
        D_800FD4E8_CrazyCutter[st->player].model = func_80023FC8(D_800FD542_CrazyCutter);
    }
    func_80021240(*obj->model);
    omSetTra(obj, st->x, st->y + 300.0f, st->z);
    omSetRot(obj, st->rotX, st->rotY, st->rotZ);
    omSetSca(obj, st->scaleX, st->scaleY, st->scaleZ);
    func_80025930(D_800FD4E8_CrazyCutter[st->player].model, 0x22000, 0x20000);
    func_80025AD4(D_800FD4E8_CrazyCutter[st->player].model);
    func_80026040(D_800FD4E8_CrazyCutter[st->player].model);
    func_80025798(D_800FD4E8_CrazyCutter[st->player].model, st->x, st->y, st->z);
    D_800FD4E8_CrazyCutter[st->player].scale = 0.1f;
    D_800FD4E8_CrazyCutter[st->player].unk8 = 0.0f;
}
#else
/* GCC cannot see the previous INCLUDE_ASM switch to .text */
__asm__(".section .rodata");
const f32 D_800FD084_CrazyCutter[4] __attribute__((section(".rodata"))) = { -400.0f, 400.0f, -400.0f, 400.0f };
const f32 D_800FD094_CrazyCutter[4] __attribute__((section(".rodata"))) = { -250.0f, -250.0f, 350.0f, 350.0f };
const f32 D_800FD0A4_CrazyCutter[3] __attribute__((section(".rodata"))) = { 2.2f, 4.0f, 4.5f };
const f32 D_800FD0B0_CrazyCutter[3] __attribute__((section(".rodata"))) = { -30.0f, 50.0f, 0.0f };
const s32 D_800FD0BC_CrazyCutter[3] __attribute__((section(".rodata"))) = { 0x1E0007, 0x1F0005, 0x1F0004 };
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_CrazyCutter/1250D0", func_800F9968_CrazyCutter);
#endif
// switch tail layout and register allocation (masked 96)
#ifdef NON_MATCHING
void func_800F9D98_CrazyCutter(omObjData* obj) {
    s32 sprites[3] = { 0x10, 0x11, 0x12 };
    CrazyCutterPiece* st = obj->unk_50;
    Vec3f from;
    Vec3f to;
    s16 a[2];
    s16 b[2];

    if (D_800FD488_CrazyCutter[st->player] == 0) {
        return;
    }
    if (func_8005FD5C() + D_800F64F8 != 0) {
        func_80026B8C(D_800FD4E8_CrazyCutter[st->player].model, D_800FD4E8_CrazyCutter[st->player].scale, D_800FD4E8_CrazyCutter[st->player].unk8, 1);
        return;
    }
    func_800211BC(*obj->model, (u8)st->alpha);
    st->alpha += 4;
    if (st->alpha >= 0x100) {
        st->alpha = 0xFF;
    }
    switch (st->state) {
        case 1:
            if (D_800FD488_CrazyCutter[st->player] == st->player * 2 + 2) {
                func_800FB2B8_CrazyCutter(sprites[D_800FD480_CrazyCutter], st->player);
            }
            D_800FD488_CrazyCutter[st->player]++;
            omSetTra(obj, st->x, st->y, st->z);
            omSetRot(obj, st->rotX, st->rotY, st->rotZ);
            func_800258EC(*obj->model, 4, 0);
            func_800258EC(D_800FD4E8_CrazyCutter[st->player].model, 4, 0);
            st->y += st->velY;
            st->velY += -4.9f;
            if (st->velY <= 0.0f) {
                st->state = 2;
                a[0] = D_800FD558_CrazyCutter[st->player];
                a[1] = D_800FD578_CrazyCutter[st->player];
                b[0] = st->x;
                b[1] = st->z;
                st->angle = func_800FAC38_CrazyCutter(a, b, 1);
                from.x = D_800FD558_CrazyCutter[st->player];
                from.y = D_800FD568_CrazyCutter[st->player];
                from.z = D_800FD578_CrazyCutter[st->player];
                to.x = st->x;
                to.y = st->y;
                to.z = st->z;
                st->dist = func_800FAF8C_CrazyCutter(&from, &to, 0);
                from.y = to.y;
                st->angle = func_800FAF8C_CrazyCutter(&from, &to, 1);
                func_8002456C(D_800FD4E8_CrazyCutter[st->player].model);
            }
            func_80026B8C(D_800FD4E8_CrazyCutter[st->player].model, D_800FD4E8_CrazyCutter[st->player].scale, D_800FD4E8_CrazyCutter[st->player].unk8, 1);
            if (D_800FD4E8_CrazyCutter[st->player].scale < 1.0f) {
                D_800FD4E8_CrazyCutter[st->player].scale += 0.02f;
            }
            D_800FD4E8_CrazyCutter[st->player].unk8 += 1.0f;
            break;
        case 2:
            omSetTra(obj, st->x, st->y, st->z);
            st->y += st->velY;
            st->velY += -4.9f;
            if (st->y < 0.0f) {
                func_8002456C(*obj->model);
                st->state = 0;
                func_800FAACC_CrazyCutter(st->player, 0x80, 0);
                omDelObj(obj);
            }
            break;
    }
    if (st->velY <= 0.0f) {
        st->state = 2;
        a[0] = D_800FD558_CrazyCutter[st->player];
        a[1] = D_800FD578_CrazyCutter[st->player];
        b[0] = st->x;
        b[1] = st->z;
        st->angle = func_800FAC38_CrazyCutter(a, b, 1);
        from.x = D_800FD558_CrazyCutter[st->player];
        from.y = D_800FD568_CrazyCutter[st->player];
        from.z = D_800FD578_CrazyCutter[st->player];
        to.x = st->x;
        to.y = st->y;
        to.z = st->z;
        st->dist = func_800FAF8C_CrazyCutter(&from, &to, 0);
        from.y = to.y;
        st->angle = func_800FAF8C_CrazyCutter(&from, &to, 1);
    }
}
#else
/* GCC cannot see the previous INCLUDE_ASM switch to .text */
__asm__(".section .rodata");
const s32 D_800FD0C8_CrazyCutter[3] __attribute__((section(".rodata"))) = { 0x10, 0x11, 0x12 };
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_CrazyCutter/1250D0", func_800F9D98_CrazyCutter);
#endif
s32 func_800FA38C_CrazyCutter(s32 player) {
    s32 sprites[3] = { 0xC, 0xD, 0xE };
    s8 sprite;
    s8 grp;
    u32 x;
    u32 y;

    sprite = InitSprite(sprites[D_800FD480_CrazyCutter] | 0x1F0000);
    grp = func_80064EF4(1, 0);
    func_8006752C(grp, 0, 0xFF);
    func_80067480(grp, 0, 0xFFFF);
    func_800674BC(grp, 0, 0x9000);
    func_80067354(grp, 0, 1.0f, 1.0f);
    func_800672B0(grp, 0, 1);
    func_80067208(grp, 0, sprite, 0);
    D_800FD4A0_CrazyCutter[player] = func_800FC4F0_CrazyCutter(grp, 0, &D_800FD498_CrazyCutter, &D_800FD49C_CrazyCutter);
    D_800FD13C_CrazyCutter = 0;
    for (y = 0; y < D_800FD49C_CrazyCutter; y++) {
        for (x = 0; x < D_800FD498_CrazyCutter; x++) {
            if (*(D_800FD4A0_CrazyCutter[player] + y * D_800FD498_CrazyCutter + x) != 0) {
                D_800FD13C_CrazyCutter++;
            }
        }
    }
    func_80064D38(grp);
    return D_800FD13C_CrazyCutter;
}
void func_800FA56C_CrazyCutter(omObjData* obj) {
    s32 i;
    s32 total;
    f32 rate;

    SetBasicSpritePos(D_800FD152_CrazyCutter, 146, 120);
    SetBasicSpritePos(D_800FD154_CrazyCutter, 158, 120);
    func_80018E50(D_800FD152_CrazyCutter, D_800FD14E_CrazyCutter / 10, 0);
    func_80018E50(D_800FD154_CrazyCutter, D_800FD14E_CrazyCutter % 10, 0);
    GMesCreate(2);
    D_800FD4B0_CrazyCutter = 0;
    for (i = 0; i < 4; i++) {
        total = D_800FD4B8_CrazyCutter[i] + D_800FD4C8_CrazyCutter[i];
        if (total < 500) {
            total = 500;
        }
        rate = D_800FD4B8_CrazyCutter[i] * 100.0f / total + 0.5f;
        if (func_800FAAB0_CrazyCutter(i, 0x1000) != 0 && func_800FAAB0_CrazyCutter(i, 0x2000) == 0) {
            rate = 0.0f;
        }
        if ((func_800FAAB0_CrazyCutter(i, 0x1000) == 0 || func_800FAAB0_CrazyCutter(i, 0x2000) == 0) && rate >= 80.0f) {
            rate = 79.0f;
        }
        if (func_800FAAB0_CrazyCutter(i, 1) == 0) {
            rate = 0.0f;
        }
        if (func_800FAAB0_CrazyCutter(i, 0x800) == 0) {
            rate = 0.0f;
        }
        if (GwPlayer[i].flags & 1) {
            rate -= 5.0f;
        }
        if (rate > 100.0f) {
            rate = 100.0f;
        }
        if (rate < 0.0f) {
            rate = 0.0f;
        }
        D_800FD592_CrazyCutter[i] = rate;
    }
    obj->func_ptr = func_800FA808_CrazyCutter;
}
void func_800FA808_CrazyCutter(omObjData* arg0) {
    if (GMesStatAllGet() == 0 || GMesStatAllGet() & 2) {
        if (D_800FD590_CrazyCutter == 0) {
            func_800FBB2C_CrazyCutter();
            D_800FD590_CrazyCutter += 1;
        }
        arg0->func_ptr = &func_800FA880_CrazyCutter;
    }
}

void func_800FA880_CrazyCutter(omObjData* obj) {
    s32 i;
    s32 j;

    j = 0;
    for (i = 0; i < 4; i++) {
        j += func_800FAAB0_CrazyCutter(i, 0x20);
    }
    if (j == 4 && D_800FD544_CrazyCutter != 0) {
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 2; j++) {
                if (func_800FAAB0_CrazyCutter(i * 2 + j, 0x4000) != 0) {
                    GMesCreate(6, "\x82\x6C\x82\x68\x82\x72\x82\x72\x81\x49", j * 160 + 80, i * 120 + 60, 1.0, 1.0, 0);
                }
            }
        }
        omDelObj(obj);
    }
    if (D_800FD548_CrazyCutter > 0 && D_800FD548_CrazyCutter < 3) {
        if (--D_800FD54C_CrazyCutter == 0 && D_800FD548_CrazyCutter == 2) {
            D_800FD548_CrazyCutter = 3;
        }
    }
}
void func_800FA9D8_CrazyCutter(omObjData* obj) {
    if (GMesWait() == 0) {
        func_800726AC(0, 20);
        obj->func_ptr = func_800FAA18_CrazyCutter;
    }
}
void func_800FAA18_CrazyCutter(omObjData* arg0) {
    s32 i;

    if (func_80072718() == 0) {
        for (i = 0; i < 4; i++) {
            if (func_800FAAB0_CrazyCutter(i, 0x4000) == 0) {
                GwPlayer[i].coins_mg += 10; 
            }
        }
        func_800601D4(0x28);
        omOvlReturnEx(1);
        omDelObj(arg0);
    }
}

s32 func_800FAAB0_CrazyCutter(s32 arg0, s32 arg1) {
    return (arg1 & D_800FD4D8_CrazyCutter[arg0]) != 0;
}

void func_800FAACC_CrazyCutter(s32 arg0, s32 arg1, s32 arg2) {
    if (arg2 != 0) {
        D_800FD4D8_CrazyCutter[arg0] = arg1 | D_800FD4D8_CrazyCutter[arg0];
    } else {
        D_800FD4D8_CrazyCutter[arg0] = ~arg1 & D_800FD4D8_CrazyCutter[arg0];
    }
}
// register allocation: f0/f2 swapped around the f64 constants (raw 12, masked 0; tried goto tail,
// f32 frac, direct returns)
#ifdef NON_MATCHING
f32 func_800FAB0C_CrazyCutter(f32 x) {
    f32 a;
    f32 b;
    f32 sum;
    f32 ret;
    s32 sign;
    s32 i;

    sign = 1;
    if (x > 1.0f) {
        x = 1.0f / x;
    } else {
        sign = -1;
        if (x < -1.0f) {
            x = 1.0f / x;
        } else {
            sign = 0;
        }
    }
    sum = 0.0f;
    i = 6;
    do {
        a = (f32)(i * i) * x * x;
        b = (f32)(i * 2 + 1) + sum;
        i--;
        sum = a / b;
    } while (i > 0);
    if (sign > 0) {
        ret = 1.5707963267948966 - x / (sum + 1.0f);
    } else if (sign >= 0) {
        ret = x / (sum + 1.0f);
    } else {
        ret = -1.5707963267948966 - x / (sum + 1.0f);
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_CrazyCutter/1250D0", func_800FAB0C_CrazyCutter);
#endif
// float registers; dead pitch compares folded (masked 81)
#ifdef NON_MATCHING
f32 func_800FAC38_CrazyCutter(s16* from, s16* to, s32 mode) {
    Vec3f fromV;
    Vec3f toV;
    Vec3f delta;
    f32 horizontal;
    f32 pitch;
    f32 yaw;
    f32 length;
    s32 nearPositive;
    s32 nearNegative;

    fromV.x = from[0];
    fromV.y = 0.0f;
    fromV.z = from[1];
    toV.x = to[0];
    toV.y = 0;
    toV.z = to[1];
    delta.x = toV.x - fromV.x;
    delta.y = toV.y - fromV.y;
    delta.z = toV.z - fromV.z;
    horizontal = sqrtf(delta.x * delta.x + delta.z * delta.z);
    nearPositive = horizontal <= 0.002f;
    nearNegative = horizontal >= -0.002f;
    if (nearPositive & nearNegative) {
        horizontal = 0.0f;
        pitch = 180.0f;
        yaw = 0.0f;
        if (!(delta.y > 0.0001f) && delta.y < 0.0001f) {
            pitch = 0.0f;
        }
    } else {
        yaw = func_800FAB0C_CrazyCutter(delta.x / delta.z) * 57.29577951308232;
        if (delta.z < 0.0f) {
            yaw -= 180.0f;
        }
        pitch = func_800FAB0C_CrazyCutter(delta.y / horizontal) * 57.29577951308232;
        if (yaw >= 360.0f) {
            yaw -= 360.0f;
        } else if (yaw < 0.0f) {
            yaw += 360.0f;
        }
        pitch += 90.0f;
        if (pitch >= 360.0f) {
            pitch -= 360.0f;
        } else if (pitch < 0.0f) {
            pitch += 360.0f;
        }
    }
    nearPositive = pitch <= 0.002f;
    nearNegative = pitch >= -0.002f;
    length = sqrtf(delta.y * delta.y + horizontal * horizontal);
    if (mode == 0) {
        D_800FD140_CrazyCutter = yaw;
    } else {
        D_800FD140_CrazyCutter = length;
    }
    return D_800FD140_CrazyCutter;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_CrazyCutter/1250D0", func_800FAC38_CrazyCutter);
#endif
// Control flow: retail keeps the dead pitch <= 0.002f / >= -0.002f tests that GCC drops here (as
// func_800F9E98_HammerDrop; 205 vs 189 instructions, masked 42; tried wrap ternaries and Vec order,
// both kept, and yaw = 0 after the pitch test)
#ifdef NON_MATCHING
f32 func_800FAF8C_CrazyCutter(Vec3f* from, Vec3f* to, s32 mode) {
    Vec3f delta;
    Vec3f fromV;
    Vec3f toV;
    f32 horizontal;
    f32 pitch;
    f32 yaw;
    f32 length;
    s32 nearPositive;
    s32 nearNegative;

    fromV.x = from->x;
    fromV.y = from->y;
    fromV.z = from->z;
    toV.x = to->x;
    toV.y = to->y;
    toV.z = to->z;
    delta.x = toV.x - fromV.x;
    delta.y = toV.y - fromV.y;
    delta.z = toV.z - fromV.z;
    horizontal = sqrtf(delta.x * delta.x + delta.z * delta.z);
    nearPositive = horizontal <= 0.002f;
    nearNegative = horizontal >= -0.002f;
    if (nearPositive & nearNegative) {
        horizontal = 0.0f;
        pitch = 180.0f;
        yaw = 0.0f;
        if (!(delta.y > 0.0001f) && delta.y < 0.0001f) {
            pitch = 0.0f;
        }
    } else {
        yaw = func_800FAB0C_CrazyCutter(delta.x / delta.z) * 57.29577951308232;
        if (delta.z < 0.0f) {
            yaw -= 180.0f;
        }
        pitch = func_800FAB0C_CrazyCutter(delta.y / horizontal) * 57.29577951308232;
        yaw = (yaw >= 360.0f) ? yaw - 360.0f : (yaw < 0.0f) ? yaw + 360.0f : yaw;
        pitch = (pitch + 90.0f >= 360.0f) ? pitch + 90.0f - 360.0f
              : (pitch + 90.0f < 0.0f)    ? pitch + 90.0f + 360.0f
                                          : pitch + 90.0f;
    }
    nearPositive = pitch <= 0.002f;
    nearNegative = pitch >= -0.002f;
    length = sqrtf(delta.y * delta.y + horizontal * horizontal);
    if (mode == 0) {
        D_800FD144_CrazyCutter = yaw;
    } else {
        D_800FD144_CrazyCutter = length;
    }
    return D_800FD144_CrazyCutter;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_CrazyCutter/1250D0", func_800FAF8C_CrazyCutter);
#endif
// register allocation, mask read lb vs lbu (masked 16)
#ifdef NON_MATCHING
void func_800FB2B8_CrazyCutter(s32 sprite, s32 player) {
    s32 x;
    s32 y;

    func_800FB450_CrazyCutter(sprite);
    if ((sprite < 12 || sprite > 13) & (sprite != 14)) {
        func_800FC70C_CrazyCutter(func_800FBAFC_CrazyCutter(D_800FD160_CrazyCutter[player]), 0, 0, 0, D_800FD520_CrazyCutter, D_800FD524_CrazyCutter, (s8*)D_800FD518_CrazyCutter);
    }
    for (y = 0; y < 120; y++) {
        for (x = 0; x < 160; x++) {
            if (D_800FD518_CrazyCutter[(s32)(y * 0.4f) * D_800FD520_CrazyCutter + (s32)(x * 0.4f)] != 0) {
                func_800FC70C_CrazyCutter(func_800FBAFC_CrazyCutter(D_800FD160_CrazyCutter[player]), 0, x, y, 1, 1, D_800FCD1C_CrazyCutter);
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_CrazyCutter/1250D0", func_800FB2B8_CrazyCutter);
#endif
void func_800FB450_CrazyCutter(s32 arg0) {
    s8 temp_s1;
    s8 temp_s0;

    if (arg0 != D_800FD530_CrazyCutter) {
        D_800FD530_CrazyCutter = arg0;
        temp_s1 = InitSprite(arg0 | 0x1F0000);
        temp_s0 = func_80064EF4(1, 0);
        func_8006752C(temp_s0, 0, 0xFF);
        func_80067480(temp_s0, 0, 0xFFFF);
        func_800674BC(temp_s0, 0, 0x9000);
        func_80067354(temp_s0, 0, 1.0f, 1.0f);
        func_800672B0(temp_s0, 0, 1);
        func_80067208(temp_s0, 0, temp_s1, 0);
        D_800FD518_CrazyCutter = func_800FC4F0_CrazyCutter(temp_s0, 0, &D_800FD520_CrazyCutter, &D_800FD524_CrazyCutter);
        func_80064D38(temp_s0);
    }
}

void func_800FB548_CrazyCutter(s32 arg0) {
    s8 temp_s1;
    s8 temp_s0;

    if (arg0 != D_800FD538_CrazyCutter) {
        D_800FD538_CrazyCutter = arg0;
        temp_s1 = InitSprite(arg0 | 0x1F0000);
        temp_s0 = func_80064EF4(1, 0);
        func_8006752C(temp_s0, 0, 0xFF);
        func_80067480(temp_s0, 0, 0xFFFF);
        func_800674BC(temp_s0, 0, 0x9000);
        func_80067354(temp_s0, 0, 1.0f, 1.0f);
        func_800672B0(temp_s0, 0, 1);
        func_80067208(temp_s0, 0, temp_s1, 0);
        D_800FD51C_CrazyCutter = func_800FC4F0_CrazyCutter(temp_s0, 0, &D_800FD528_CrazyCutter, &D_800FD52C_CrazyCutter);
        func_80064D38(temp_s0);
    }
}

// decomp-permuter
void func_800FB640_CrazyCutter(omObjData *parent, s32 sprite, s32 sprite2, s32 player)
{
  CrazyCutterRing *ring;
  func_800FB450_CrazyCutter(sprite);
  parent = omAddObj(13, 0, 0, -1, &func_800FB778_CrazyCutter);
  parent->unk_50 = (ring = func_80023684(sizeof(CrazyCutterRing), 0x7918));
  ring->radius = 0;
  ring->step = 1.0f;
  ring->end = 80.0f;
  ring->mask = D_800FD518_CrazyCutter;
  ring->width = D_800FD520_CrazyCutter;
  ring->player = player;
  func_800FB548_CrazyCutter(sprite2);
  parent = omAddObj(13, 0, 0, -1, &func_800FB778_CrazyCutter);
  parent->unk_50 = (ring = func_80023684(sizeof(CrazyCutterRing), 0x7918));
  ring->radius = 80.0f;
  ring->step = -1.0f;
  ring->end = 0;
  ring->mask = D_800FD51C_CrazyCutter;
  ring->width = D_800FD528_CrazyCutter;
  ring->player = player;
  ring->frame = 0;
  D_800FD5CA_CrazyCutter = -1;
}
// register allocation, mask read lb vs lbu (masked 17)
#ifdef NON_MATCHING
void func_800FB778_CrazyCutter(omObjData* obj) {
    CrazyCutterRing* ring = obj->unk_50;
    f32 angle;
    s32 x;
    s32 y;

    for (angle = 0.0f; angle <= 360.0f; angle += 1.0f) {
        x = func_800AEAC0(angle) * ring->radius + 80.0f;
        y = func_800AEFD0(angle) * ring->radius + 68.0f;
        if (((u32)x < 160) & (y >= 0) && y < 120 && ring->mask[y * ring->width + x] != 0
            && func_800FC70C_CrazyCutter(func_800FBAFC_CrazyCutter(D_800FD160_CrazyCutter[ring->player]), 0, x, y, 1, 1, D_800FCD1C_CrazyCutter) != 0
            && D_800FD5CA_CrazyCutter == -1) {
            D_800FD5CA_CrazyCutter = PlaySound(0x236);
        }
    }
    ring->radius += ring->step;
    if (ring->radius == ring->end) {
        func_800FAACC_CrazyCutter(ring->player, 0x100, 1);
        omDelObj(obj);
    }
    ring->frame++;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_CrazyCutter/1250D0", func_800FB778_CrazyCutter);
#endif
// scheduling: retail loads cur[0] and cur[1] before the grid row pointer (raw 4, masked 4; tried
// cur[0] + cur[1] * w)
#ifdef NON_MATCHING
s32 func_800FB944_CrazyCutter(CrazyCutterPlayer* st) {
    Vec3f pos;
    s16 cur[2];
    f32 d;
    f32 x;
    f32 z;

    if (func_800FAAB0_CrazyCutter(st->player, 0x8000) == 0) {
        return 0;
    }
    D_800FD148_CrazyCutter = 0;
    for (d = 0.0f; d <= D_800FD53C_CrazyCutter; d += 0.5f) {
        x = d * func_800AEAC0(st->angle);
        z = d * func_800AEFD0(st->angle);
        x += st->prevX;
        z += st->prevZ;
        pos.x = x + D_800FCCF0_CrazyCutter[st->player] - 8.0f;
        pos.y = st->y + 10.0f;
        pos.z = z + D_800FCD00_CrazyCutter[st->player] - 8.0f;
        func_800F9694_CrazyCutter(&pos, cur, st->player);
        if ((D_800FD4A0_CrazyCutter[st->player] + cur[1] * D_800FD498_CrazyCutter)[cur[0]] != 0) {
            D_800FD148_CrazyCutter = 1;
            break;
        }
    }
    return D_800FD148_CrazyCutter;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_CrazyCutter/1250D0", func_800FB944_CrazyCutter);
#endif
// decomp-permuter
s16 func_800FBAFC_CrazyCutter(s32 idx)
{
  unkSpriteStruct *new_var;
  new_var = &D_800ED60C[idx];
  return D_800FD14C_CrazyCutter = (*new_var).unk_04;
}
void func_800FBB2C_CrazyCutter(void) {
    omObjData* temp_s0;
    s32* temp_v0;

    temp_s0 = omAddObj(0xC, 0, 0, -1, &func_800FBB94_CrazyCutter);
    temp_v0 = func_80023684(sizeof(s32), 0x7918);
    temp_s0->unk_50 = temp_v0;
    *temp_v0 = 90;
    D_800FD5C0_CrazyCutter = PlaySound(0x1C0);
}

void func_800FBB94_CrazyCutter(omObjData* obj) {
    s32* counter = obj->unk_50;
    s32 i;
    s16 r;
    f32 rate;

    if (--*counter > 60) {
        r = (rand8() * 101) >> 8;
        for (i = 0; i < 4; i++) {
            func_800FC29C_CrazyCutter(D_800FD588_CrazyCutter[i], r);
        }
    } else {
        if (*counter == 60) {
            func_8006071C(D_800FD5C0_CrazyCutter);
            PlaySound(0x1C1);
        }
        if (*counter < 10) {
            for (i = 0; i < 4; i++) {
                func_800FC45C_CrazyCutter(D_800FD588_CrazyCutter[i], (s16)*counter);
            }
        } else if (*counter > 0) {
            for (i = 0; i < 4; i++) {
                func_800FC29C_CrazyCutter(D_800FD588_CrazyCutter[i], D_800FD592_CrazyCutter[i]);
            }
        }
    }
    if (*counter == 0) {
        D_800FD544_CrazyCutter = 0;
        for (i = 0; i < 4; i++) {
            rate = D_800FD592_CrazyCutter[i];
            if (func_800FAAB0_CrazyCutter(i, 1) != 0 && func_800FAAB0_CrazyCutter(i, 0x800) != 0
                && func_800FAAB0_CrazyCutter(i, 0x1000) != 0 && func_800FAAB0_CrazyCutter(i, 0x2000) != 0
                && rate >= 80.0f) {
                func_800FAACC_CrazyCutter(i, 8, 1);
                func_800FAACC_CrazyCutter(i, 0x80, 1);
                func_800FAACC_CrazyCutter(i, 0x10000, 1);
                D_800FD544_CrazyCutter++;
            } else {
                func_800FAACC_CrazyCutter(i, 0x4000, 1);
            }
        }
        if (D_800FD544_CrazyCutter == 0) {
            omAddObj(12, 0, 0, -1, &func_800F7180_CrazyCutter);
        } else if (D_800FD548_CrazyCutter <= 0) {
            D_800FD548_CrazyCutter = 1;
            D_800FD54C_CrazyCutter = 30;
            D_800FD5C2_CrazyCutter = PlaySound(0x235);
            for (i = 0; i < 4; i++) {
                ((CrazyCutterPlayer*)D_800FD5A0_CrazyCutter[i]->unk_50)->unk518 = 1;
            }
        }
        omDelObj(obj);
    }
}
s32 func_800FBEA8_CrazyCutter(s16 grpIdx, s32 idx, s32 x, s32 y) {
    s32 a;
    s32 b;
    s32 c;

    a = func_800FCAAC_CrazyCutter(grpIdx, 0, x + 3, y, 3, 3, D_800FCD10_CrazyCutter);
    b = func_800FCAAC_CrazyCutter(grpIdx, 0, x - 3, y, 3, 3, D_800FCD10_CrazyCutter);
    c = func_800FCAAC_CrazyCutter(grpIdx, 0, x, y + 3, 3, 3, D_800FCD10_CrazyCutter);
    return a + b + c + func_800FCAAC_CrazyCutter(grpIdx, 0, x, y - 3, 3, 3, D_800FCD10_CrazyCutter) >= 18;
}
void func_800FBFB4_CrazyCutter(void) {
    void* data;

    data = DataRead(0x7E);
    D_800FD5B0_CrazyCutter = func_800678A4(data);
    DataClose(data);
    data = DataRead(0x20000C);
    D_800FD5BC_CrazyCutter = func_800678A4(data);
    DataClose(data);
    D_800FD5BA_CrazyCutter = 0;
}
s16 func_800FC024_CrazyCutter(s16 x, s16 y) {
    s16 grp;
    s16 i;
    s16 px;

    grp = D_800FD5B2_CrazyCutter[D_800FD5BA_CrazyCutter] = func_80064EF4(4, 5);
    func_80067208(grp, 0, D_800FD5B0_CrazyCutter, 0);
    func_80067480(grp, 0, 0xFFFF);
    func_800674BC(grp, 0, 0x8000);
    func_80066DC4(grp, 0, x - 16, y);
    px = 24;
    for (i = 1; i < 3; i++) {
        func_80067208(grp, i, D_800FD5B0_CrazyCutter, 0);
        func_80066DC4(grp, i, px, 0);
        func_80067480(grp, i, 0xFFFF);
        func_800674BC(grp, i, 0x8000);
        px += 24;
    }
    func_80067208(grp, i, D_800FD5BC_CrazyCutter, 0);
    func_80066DC4(grp, i, px - 4, 6);
    func_80067480(grp, i, 0xFFFF);
    func_800674BC(grp, i, 0x8000);
    func_80067598(grp, 1, 0);
    func_80067598(grp, 2, 0);
    func_80067598(grp, 3, 0);
    func_80067480(grp, 2, 0x8000);
    func_80067480(grp, 3, 0x8000);
    D_800FD5BA_CrazyCutter++;
    return grp;
}
void func_800FC240_CrazyCutter(s16 arg0) {
    s16 i;
    
    for (i = 0; i < 4; i++) {
        func_800674BC(arg0, i, 0x8000);
    }
}


void func_800FC29C_CrazyCutter(s16 grp, s16 value) {
    s16 hundreds;
    s16 tens;

    hundreds = 0;
    if (value >= 100) {
        func_80067480(grp, 0, 0x8000);
        func_800672DC(grp, 0, 1, 0);
        func_800672B0(grp, 0, 1);
        value -= 100;
        hundreds = 1;
    } else {
        func_800674BC(grp, 0, 0x8000);
    }
    if (hundreds != 0 || (s16)(value / 10) != 0) {
        func_80067480(grp, 1, 0x8000);
        tens = value / 10;
        func_800672DC(grp, 1, tens, 0);
        func_800672B0(grp, 1, 1);
        value -= tens * 10;
    } else {
        func_800674BC(grp, 1, 0x8000);
    }
    func_80067480(grp, 2, 0x8000);
    func_800672DC(grp, 2, value, 0);
    func_800672B0(grp, 2, 1);
    func_80067480(grp, 3, 0x8000);
}
void func_800FC45C_CrazyCutter(s16 arg0, s16 arg1) {
    s16 i = 0;
    
    for (i = 0; i < 4; i++) {
        func_80067354(arg0, i, arg1 / 10.0f, arg1 / 10.0f);
    }
}
