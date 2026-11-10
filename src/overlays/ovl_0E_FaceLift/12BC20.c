#include "common.h"
#include "FaceLift.h"
#include "engine/esprite.h"
#include "engine/pad.h"

/* .rodata: the character names the .data tables point at */
const char D_800FC8C0_FaceLift[] = "DK";
const char D_800FC8C4_FaceLift[] = "WARIO";
const char D_800FC8CC_FaceLift[] = "YOSHI";
const char D_800FC8D4_FaceLift[] = "PEACH";
const char D_800FC8DC_FaceLift[] = "LUIGI";
const char D_800FC8E4_FaceLift[] = "MARIO";
const char D_800FC8EC_FaceLift[] = "\x82\x63\x82\x6A";
const char D_800FC8F4_FaceLift[] = "\x82\x76\x82\x60\x82\x71\x82\x68\x82\x6E";
const char D_800FC900_FaceLift[] = "\x82\x78\x82\x6E\x82\x72\x82\x67\x82\x68";
const char D_800FC90C_FaceLift[] = "\x82\x6F\x82\x64\x82\x60\x82\x62\x82\x67";
const char D_800FC918_FaceLift[] = "\x82\x6B\x82\x74\x82\x68\x82\x66\x82\x68";
const char D_800FC924_FaceLift[] = "\x82\x6C\x82\x60\x82\x71\x82\x68\x82\x6E";
const char D_800FC930_FaceLift[] = "\x82\x60\x82\x61\x82\x62";

/* .data */
u16 D_800FC3D0_FaceLift = 0;
u16 D_800FC3D2_FaceLift = 0;
s16 D_800FC3D4_FaceLift = 0;
Vec3f D_800FC3D8_FaceLift[5] = {
    { 320.0f, 240.0f, 511.0f }, { 320.0f, 240.0f, 511.0f }, { 320.0f, 240.0f, 511.0f },
    { 320.0f, 240.0f, 511.0f }, { 640.0f, 480.0f, 511.0f },
};
Vec3f D_800FC414_FaceLift[5] = {
    { 320.0f, 240.0f, 511.0f }, { 960.0f, 240.0f, 511.0f }, { 320.0f, 720.0f, 511.0f },
    { 960.0f, 720.0f, 511.0f }, { 640.0f, 480.0f, 511.0f },
};
Vec4f D_800FC450_FaceLift[5] = {
    { 0.0f, 0.0f, 160.0f, 120.0f }, { 160.0f, 0.0f, 320.0f, 120.0f }, { 0.0f, 120.0f, 160.0f, 240.0f },
    { 160.0f, 120.0f, 320.0f, 240.0f }, { 0.0f, 0.0f, 320.0f, 240.0f },
};
FaceLiftPos D_800FC4A0_FaceLift[4] = { { 0, 0 }, { 160, 0 }, { 0, 120 }, { 160, 120 } };
FaceLiftPart D_800FC4B0_FaceLift[8] = {
    { -39.0f, 19.0f, 0, 0, -65.0f, 48.0f, -33.0f, 7.0f, 0, 0, NULL, 40.0f },
    { 39.0f, 19.0f, 0, 0, 33.0f, 51.0f, 67.0f, 9.0f, 0, 0, NULL, 40.0f },
    { -45.0f, -19.0f, 1, 0, -84.0f, 2.0f, -36.0f, -52.0f, 0, 0, NULL, 40.0f },
    { 45.0f, -19.0f, 1, 0, 36.0f, 2.0f, 84.0f, -52.0f, 0, 0, NULL, 40.0f },
    { 0.0f, -24.0f, 1, 0, -22.0f, 6.0f, 22.0f, -44.0f, 0, 0, NULL, 28.0f },
    { 0.0f, -61.0f, 0, 0, -26.0f, -42.0f, 26.0f, -82.0f, 0, 0, NULL, 80.0f },
    { -45.0f, -19.0f, 0, 0, -74.0f, 2.0f, -36.0f, -52.0f, 0, 0, NULL, 28.0f },
    { 45.0f, -19.0f, 0, 0, 30.0f, 2.0f, 84.0f, -52.0f, 0, 0, NULL, 28.0f },
};
/* The CPU's target face: eight layouts of the six parts (D_800FC966_FaceLift picks one). */
Vec2f D_800FC5F0_FaceLift[8 * 6] = {
    { -65.0f, 48.0f }, { 67.0f, 51.0f }, { -84.0f, 2.0f }, { 84.0f, 2.0f }, { 0.0f, -24.0f }, { 0.0f, -82.0f },
    { -39.0f, 7.0f }, { 39.0f, 9.0f }, { -45.0f, -52.0f }, { 45.0f, -52.0f }, { 0.0f, -44.0f }, { 0.0f, -55.0f },
    { -65.0f, 7.0f }, { 67.0f, 9.0f }, { -84.0f, -52.0f }, { 84.0f, -52.0f }, { 0.0f, -44.0f }, { 0.0f, -61.0f },
    { -65.0f, 7.0f }, { 67.0f, 9.0f }, { -45.0f, -19.0f }, { 45.0f, -19.0f }, { 0.0f, -44.0f }, { 0.0f, -61.0f },
    { -65.0f, 48.0f }, { 67.0f, 51.0f }, { -36.0f, -19.0f }, { 36.0f, -19.0f }, { 0.0f, 6.0f }, { 0.0f, -82.0f },
    { -65.0f, 7.0f }, { 67.0f, 9.0f }, { -45.0f, -19.0f }, { 45.0f, -19.0f }, { -1.0f, -13.0f }, { 0.0f, -61.0f },
    { -33.0f, 7.0f }, { 33.0f, 9.0f }, { -36.0f, -52.0f }, { 36.0f, -52.0f }, { 0.0f, -24.0f }, { 0.0f, -82.0f },
    { -33.0f, 48.0f }, { 33.0f, 51.0f }, { -76.0f, -52.0f }, { 72.0f, -52.0f }, { 0.0f, -24.0f }, { 0.0f, -82.0f },
};
s32 D_800FC770_FaceLift[3] = { 0x21, 0x22, 0x23 };
s32 D_800FC77C_FaceLift[6] = { 0x200005, 0x200006, 0x200007, 0x200008, 0x200009, 0x20000A };
const char* D_800FC794_FaceLift[6] = {
    D_800FC8E4_FaceLift, D_800FC8DC_FaceLift, D_800FC8D4_FaceLift,
    D_800FC8CC_FaceLift, D_800FC8C4_FaceLift, D_800FC8C0_FaceLift,
};
const char* D_800FC7AC_FaceLift[6] = {
    D_800FC924_FaceLift, D_800FC918_FaceLift, D_800FC90C_FaceLift,
    D_800FC900_FaceLift, D_800FC8F4_FaceLift, D_800FC8EC_FaceLift,
};
f32 D_800FC7C4_FaceLift[4] = { 40.0f, 30.0f, 20.0f, 10.0f };
FaceLiftPos D_800FC7D4_FaceLift[4] = { { 56, 90 }, { 216, 90 }, { 56, 210 }, { 216, 210 } };
Gfx D_800FC7E8_FaceLift[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_FILL),
    gsDPSetRenderMode(G_RM_NOOP, G_RM_NOOP2),
    gsDPSetFillColor(0xFFFCFFFC),
    gsDPFillRectangle(0, 0, 319, 239),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetColorImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, 0x02000000),
    gsSPEndDisplayList(),
};
Gfx D_800FC830_FaceLift[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineLERP(TEXEL0, PRIMITIVE, TEXEL0_ALPHA, PRIMITIVE, 0, TEXEL0, PRIMITIVE, TEXEL0, TEXEL0, PRIMITIVE, TEXEL0_ALPHA, PRIMITIVE, 0, TEXEL0, PRIMITIVE, TEXEL0),
    gsDPSetRenderMode(G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2),
    gsDPSetAlphaCompare(G_AC_THRESHOLD),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsSPEndDisplayList(),
};
Gfx D_800FC870_FaceLift[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetRenderMode(G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0xC0),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetAlphaDither(G_AD_DISABLE),
    gsSPEndDisplayList(),
};

// register allocation: hoisted table bases and the D_800FC9FA store address (raw 23, masked 2; tried
// struct indexing, an s16 view, a separate store statement)
#ifdef NON_MATCHING
void func_800F65E0_FaceLift(void) {
    omObjData* obj;
    s32 i;

    InitCameras(5);
    func_80029090(1);
    func_8001DE70(0x46);
    omInitObjMan(0x65, 0);
    func_80060088();
    obj = omAddObj(0x7FDA, 0, 0, -1, func_800F9EE4_FaceLift);
    omSetStatBit(obj, 0xA0);
    omAddObj(0x2710, 0, 0, -1, func_800FA9DC_FaceLift);
    CRot.x = 0.0f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    CZoom = 2200.0f;
    Center.x = Center.y = Center.z = CRot.x;
    for (i = 0; i < 5; i++) {
        func_8001D494(i, 5.0f, 100.0f, 3000.0f);
        func_8001D520(i, &D_800FC3D8_FaceLift[i], &D_800FC414_FaceLift[i]);
        func_8001D4D4(i, &D_800FC450_FaceLift[i]);
    }
    func_800F9EE4_FaceLift(obj);
    func_80023448(3);
    func_800234B8(0, 0x78, 0x78, 0x78);
    func_800234B8(1, 0x40, 0x40, 0x60);
    func_80023504(1, -100.0f, 100.0f, 100.0f);
    func_800234B8(2, 0, 0, 0);
    func_800234B8(3, 0, 0, 0);
    D_800FC9EC_FaceLift = omAddObj(0x3E8, 0, 0, -1, func_800F8204_FaceLift);
    omSetStatBit(omAddObj(0x7D0, 0xA, 1, -1, func_800F8DC8_FaceLift), 0xA0);
    omSetStatBit(omAddObj(0x1388, 0, 0, -1, func_800F9AD4_FaceLift), 0xA0);
    func_800FBE08_FaceLift();
    for (i = 0; i < 4; i++) {
        func_800FC094_FaceLift(D_800FC9FA_FaceLift[i] = func_800FBE78_FaceLift(*(&D_800FC7D4_FaceLift[0].x + i * 2), *(&D_800FC7D4_FaceLift[0].y + i * 2)));
    }
    D_800FCA0A_FaceLift = _CheckFlag(0x45);
    D_800FCA0C_FaceLift = _CheckFlag(0x2B);
    func_8007B168((u8*)D_800FC930_FaceLift, 0);
    func_8007B168((u8*)D_800FC930_FaceLift, 1);
    D_800FC962_FaceLift = 0;
    for (i = 0; i < 4; i++) {
        D_800FCA0E_FaceLift[i] = GwPlayer[i].cpu_difficulty;
    }
    if (D_800FCA0A_FaceLift != 0) {
        for (i = 0; i < 4; i++) {
            D_800FCA0E_FaceLift[i] = (rand8() & 1) ? 3 : 2;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_FaceLift/12BC20", func_800F65E0_FaceLift);
#endif
void func_800F6974_FaceLift(omObjData* obj) {
    Vec2f pos;
    FaceLiftWork* w;
    s16 player;
    s16 i;

    w = obj->unk_50 = func_80023684(sizeof(FaceLiftWork), 0x7918);
    player = obj->work[0];
    obj->work[2] = 0;
    obj->work[1] = 0;
    func_800F80A4_FaceLift(obj, player);
    w->sprite = func_80019060((s16)InitSprite(D_800FC77C_FaceLift[GwPlayer[player].character]), 0, 1);
    func_80018C90(w->sprite);
    w->pos.x = w->pos.y = w->pos.z = 0.0f;
    Convert3DTo2D(player, &w->pos, &pos);
    pos.x = pos.x / 2.0f + D_800FC4A0_FaceLift[player].x;
    pos.y = pos.y / 2.0f + D_800FC4A0_FaceLift[player].y;
    SetBasicSpritePos(w->sprite, pos.x, pos.y);
    for (i = 0; i < 6; i++) {
        w->moving[i] = 0;
        w->pts[i].x = D_800FC4B0_FaceLift[i].x;
        w->pts[i].y = D_800FC4B0_FaceLift[i].y;
        w->pts[i].z = 0;
    }
    w->grab = 0;
    w->sel = 0;
    func_800F6B88_FaceLift(w, D_800FC7C4_FaceLift[D_800FCA0E_FaceLift[player]]);
    w->cpuRounds = 0;
    obj->func_ptr = func_800F6DBC_FaceLift;
}
void func_800F6B88_FaceLift(FaceLiftWork* w, f32 spread) {
    s16 i;
    f32 y;
    u16 t;
    s16 k;

    w->cpuIdx = 0;
    w->cpuState = 0;
    for (i = 0; i < 6; i++) {
        w->order[i] = i;
        w->cpuTarget[i].x = D_800FC5F0_FaceLift[D_800FC966_FaceLift * 6 + i].x + (((rand8() & 0xFF) * spread) / 256.0f - spread / 2.0f);
        y = D_800FC5F0_FaceLift[D_800FC966_FaceLift * 6 + i].y + (((rand8() & 0xFF) * spread) / 256.0f - spread / 2.0f);
        w->cpuTarget[i].y = y;
        if (w->cpuTarget[i].x <= D_800FC4B0_FaceLift[i].left || D_800FC4B0_FaceLift[i].right <= w->cpuTarget[i].x
            || y <= D_800FC4B0_FaceLift[i].bottom || D_800FC4B0_FaceLift[i].top <= y) {
            i--;
        }
    }
    for (i = 0; i < 20; i++) {
        k = ((rand8() & 0xFF) * 5) >> 8;
        t = w->order[k];
        w->order[k] = w->order[k + 1];
        w->order[k + 1] = t;
    }
}
// scheduling of the D_800FC9FA_FaceLift index
#ifdef NON_MATCHING
void func_800F6DBC_FaceLift(omObjData* obj) {
    Vec2f pos;
    s32 pad[2]; // frame size
    s16 i;
    s16 player;
    FaceLiftWork* w;
    f32 t;
    f32 u;
    f32 x;
    f32 y;

    player = obj->work[0];
    w = obj->unk_50;
    for (i = 0; i < 6; i++) {
        func_800FA5B4_FaceLift(obj->model[D_800FC4B0_FaceLift[i].model], i, &w->pts[i]);
    }
    func_800FA7D0_FaceLift(obj->model[D_800FC4B0_FaceLift[6].model], 6, &w->pts[2]);
    func_800FA7D0_FaceLift(obj->model[D_800FC4B0_FaceLift[7].model], 7, &w->pts[3]);
    func_800F99E8_FaceLift(&w->pts[4], &w->pts[2], obj->model[2], 0);
    func_800F99E8_FaceLift(&w->pts[4], &w->pts[3], obj->model[3], 1);
    if (D_800F384E != 0) {
        return;
    }
    if (D_800FC962_FaceLift == 2) {
        ShowBasicSprite(w->sprite);
        func_800F7444_FaceLift(player, w);
    }
    Convert3DTo2D(player, &w->pos, &pos);
    pos.x = pos.x / 2.0f + D_800FC4A0_FaceLift[player].x;
    pos.y = pos.y / 2.0f + D_800FC4A0_FaceLift[player].y;
    SetBasicSpritePos(w->sprite, pos.x, pos.y);
    if (D_800FC962_FaceLift == 3) {
        if (obj->work[1] == 0) {
            if (w->sndOn != 0) {
                func_8006071C(w->snd);
            }
            func_800601D4(40);
        }
        if (obj->work[1] == 20) {
            func_80018C90(w->sprite);
        }
        if (obj->work[1] < 20) {
            t = (20 - obj->work[1]) / 20.0f;
            SetBasicSpriteSize(w->sprite, t, t);
            obj->work[1]++;
        }
    }
    if (D_800FC3D2_FaceLift == 0) {
        return;
    }
    if (D_800FC9CA_FaceLift[player] == 0) {
        if (D_800FC9C8_FaceLift == 1) {
            func_800258EC(obj->model[0], 4, 4);
            func_800258EC(obj->model[1], 4, 4);
            func_800258EC(obj->model[2], 4, 4);
            func_800258EC(obj->model[3], 4, 4);
        } else if (obj->work[2] >= 11) {
            omSetSca(obj, 0.0f, 0.0f, 0.0f);
            func_80025830(obj->model[1], 0.0f, 0.0f, 0.0f);
            func_80025830(obj->model[2], 0.0f, 0.0f, 0.0f);
            func_80025830(obj->model[3], 0.0f, 0.0f, 0.0f);
        } else {
            t = (10.0f - obj->work[2]) / 10.0f;
            omSetSca(obj, t, t, t);
            func_80025830(obj->model[1], t, t, t);
            func_80025830(obj->model[2], t, t, t);
            func_80025830(obj->model[3], t, t, t);
            obj->work[2]++;
        }
    } else if (D_800FC9C8_FaceLift == 1) {
        func_8001D4D4(player, &D_800FC450_FaceLift[4]);
        if (obj->work[2] < 20 && (obj->unk_10 & 1)) {
            t = obj->work[2] / 20.0f;
            D_800FC968_FaceLift.x = (1.0f - t) * D_800FC3D8_FaceLift[player].x + t * D_800FC3D8_FaceLift[4].x;
            D_800FC968_FaceLift.y = (1.0f - t) * D_800FC3D8_FaceLift[player].y + t * D_800FC3D8_FaceLift[4].y;
            D_800FC968_FaceLift.z = 511.0f;
            D_800FC974_FaceLift.x = (1.0f - t) * D_800FC414_FaceLift[player].x + t * D_800FC414_FaceLift[4].x;
            D_800FC974_FaceLift.y = (1.0f - t) * D_800FC414_FaceLift[player].y + t * D_800FC414_FaceLift[4].y;
            D_800FC974_FaceLift.z = 511.0f;
            func_8001D520(player, &D_800FC968_FaceLift, &D_800FC974_FaceLift);
            x = D_800FC7D4_FaceLift[player].x + (0xE6 - D_800FC7D4_FaceLift[player].x) * t;
            y = D_800FC7D4_FaceLift[player].y + (0xAA - D_800FC7D4_FaceLift[player].y) * t;
            func_800FC39C_FaceLift(D_800FC9FA_FaceLift[player], x, y);
            obj->work[2]++;
            CZoom += 20.0f;
            if (obj->work[2] == 20 && D_800FCA0A_FaceLift == 0) {
                func_800FB0BC_FaceLift(player);
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_FaceLift/12BC20", func_800F6DBC_FaceLift);
#endif
// register allocation (port in a1, bnez for bnezl)
#ifdef NON_MATCHING
void func_800F7444_FaceLift(s16 player, FaceLiftWork* w) {
    Vec3f pos;
    Vec2f cpu;
    u16 trg;
    u16 btn;
    f32 dx;
    f32 dy;
    f32 ex;
    f32 ey;
    s16 sel;
    s16 i;
    s32 port;
    s16 snd;

    port = GwPlayer[player].port;
    sel = w->sel;
    if (!(GwPlayer[player].flags & 1)) {
        dx = (s8)(ContStkX[port] / 10);
        dy = (s8)(ContStkY[port] / 10);
        trg = ContBtnTrg[port];
        btn = ContBtn[port];
    } else {
        func_800F7D58_FaceLift(player, w, &cpu, &trg, &btn);
        dx = cpu.x;
        dy = cpu.y;
    }
    if (w->grab != 0) {
        if (dx + w->pos.x < D_800FC4B0_FaceLift[sel].left) {
            dx = 0.0f;
            w->pos.x = D_800FC4B0_FaceLift[sel].left;
        }
        if (dx + w->pos.x > D_800FC4B0_FaceLift[sel].right) {
            dx = 0.0f;
            w->pos.x = D_800FC4B0_FaceLift[sel].right;
        }
        if (dy + w->pos.y > D_800FC4B0_FaceLift[sel].top) {
            dy = 0.0f;
            w->pos.y = D_800FC4B0_FaceLift[sel].top;
        }
        if (dy + w->pos.y < D_800FC4B0_FaceLift[sel].bottom) {
            dy = 0.0f;
            w->pos.y = D_800FC4B0_FaceLift[sel].bottom;
        }
    }
    pos.x = dx + w->pos.x;
    pos.y = dy + w->pos.y;
    pos.z = w->pos.z;
    if (func_800FA058_FaceLift(player, &pos) != 0) {
        w->pos.x = dx + w->pos.x;
        w->pos.y = dy + w->pos.y;
    }
    if (trg & 0x4000) {
        for (i = 0; i < 6; i++) {
            ex = w->pos.x - w->pts[i].x;
            ey = w->pos.y - w->pts[i].y;
            if (func_800B1750(ex * ex + ey * ey) < 20.0f) {
                func_80060F04(player, 2, 3, 10);
                w->moving[i] = 1;
                break;
            }
        }
    }
    for (i = 0; i < 6; i++) {
        if (w->moving[i] == 1) {
            dx = D_800FC4B0_FaceLift[i].x - w->pts[i].x;
            dy = D_800FC4B0_FaceLift[i].y - w->pts[i].y;
            w->pts[i].x = dx / 4.0f + w->pts[i].x;
            w->pts[i].y = dy / 4.0f + w->pts[i].y;
            if (dx * dx + dy * dy < 1.0f) {
                w->pts[i].x = D_800FC4B0_FaceLift[i].x;
                w->pts[i].y = D_800FC4B0_FaceLift[i].y;
                w->moving[i] = 0;
            }
        }
    }
    if (trg & 0x8000) {
        if (!(GwPlayer[player].flags & 1)) {
            for (i = 0; i < 6; i++) {
                ex = w->pos.x - w->pts[i].x;
                ey = w->pos.y - w->pts[i].y;
                if (func_800B1750(ex * ex + ey * ey) < 20.0f) {
                    break;
                }
            }
        } else {
            i = w->order[w->cpuIdx];
        }
        if (i != 6) {
            w->sel = i;
            w->moving[i] = 0;
            w->pos = w->pts[i];
            w->grab = 1;
            w->sndOn = 0;
            func_800FB858_FaceLift(player, w->pos.x, w->pos.y, w->pos.z + 100.0f, 2);
            func_80018E50(w->sprite, 1, 0);
            func_800672B0(D_800ED60C[(s16)w->sprite].unk_04, 0, 1);
            snd = func_80060540(0x23E, player);
            func_80060F04(player, 5, 0, 5);
            func_80060440(snd, (((rand8() & 0xFF) * 35) >> 7) * 10 - 400);
        }
    } else if (btn & 0x8000) {
        if (w->grab != 0 && (w->pos.x != D_800FC4B0_FaceLift[sel].x || w->pos.y != D_800FC4B0_FaceLift[sel].y)) {
            w->pts[sel] = w->pos;
            if ((dx == 0.0f) & (dy == 0.0f)) {
                if (w->sndOn != 0) {
                    func_8006071C(w->snd);
                }
                w->sndOn = 0;
            }
            if ((dx != 0.0f) | (dy != 0.0f)) {
                if (w->sndOn == 0) {
                    w->snd = func_80060540(0x23F, player);
                    w->sndOn = 1;
                }
            }
            ex = w->pos.x - D_800FC4B0_FaceLift[sel].x;
            ey = w->pos.y - D_800FC4B0_FaceLift[sel].y;
            if ((ex != 0.0f) | (ey != 0.0f)) {
                func_80060440(w->snd, func_800B1750(ex * ex + ey * ey) * 26.666666f + -1200.0f);
            } else {
                func_80060440(w->snd, 0);
            }
        }
    } else if (w->grab != 0) {
        w->grab = 0;
        func_80018E50(w->sprite, 0, 0);
        func_800672B0(D_800ED60C[(s16)w->sprite].unk_04, 0, 1);
        func_8006071C(w->snd);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_FaceLift/12BC20", func_800F7444_FaceLift);
#endif
// register allocation: trg/btn get s3/s4 swapped (raw 6, masked 0; tried separate zero stores)
#ifdef NON_MATCHING
void func_800F7D58_FaceLift(s16 player, FaceLiftWork* w, Vec2f* stick, u16* trg, u16* btn) {
    f32 dx;
    f32 dy;
    f32 d;

    *trg = *btn = 0;
    switch (w->cpuState) {
    case 0:
        if (w->cpuRounds != 0 && !(rand8() & 0xF)) {
            func_800F6B88_FaceLift(w, D_800FC7C4_FaceLift[D_800FCA0E_FaceLift[player]] * 0.7f);
            w->cpuTimer = ((rand8() & 0xFF) >> 4) + 5;
            w->cpuState = 2;
            break;
        }
        dx = w->pts[w->order[w->cpuIdx]].x - w->pos.x;
        dy = w->pts[w->order[w->cpuIdx]].y - w->pos.y;
        d = func_800B1750(dx * dx + dy * dy);
        if (d < 4.0f) {
            stick->x = dx;
            stick->y = dy;
            w->cpuState = 1;
            *trg = 0x8000;
        } else {
            stick->x = (4.0f / d) * dx;
            stick->y = (4.0f / d) * dy;
        }
        return;
    case 1:
        dx = w->cpuTarget[w->order[w->cpuIdx]].x - w->pos.x;
        dy = w->cpuTarget[w->order[w->cpuIdx]].y - w->pos.y;
        d = func_800B1750(dx * dx + dy * dy);
        if (d <= 0.8f) {
            stick->x = dx;
            stick->y = dy;
            if (++w->cpuIdx >= 6) {
                w->cpuState = 3;
                w->cpuRounds++;
            } else {
                w->cpuState = 2;
            }
            w->cpuTimer = ((rand8() & 0xFF) >> 3) + 10;
        } else {
            stick->x = (0.8f / d) * dx;
            stick->y = (0.8f / d) * dy;
        }
        *btn = 0x8000;
        return;
    case 2:
        if (--w->cpuTimer == 0) {
            w->cpuState = 0;
        }
        break;
    case 3:
        func_800F6B88_FaceLift(w, D_800FC7C4_FaceLift[D_800FCA0E_FaceLift[player]] * 0.7f);
        w->cpuTimer = ((rand8() & 0xFF) >> 3) + 30;
        w->cpuState = 2;
        break;
    }
    stick->x = stick->y = 0.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_FaceLift/12BC20", func_800F7D58_FaceLift);
#endif
void func_800F80A4_FaceLift(omObjData* obj, s32 player) {
    obj->model[0] = LoadFormFile(0x200001, 0x299);
    func_80026040(obj->model[0]);
    func_80025F10(obj->model[0], (s16)(1 << player));
    obj->model[1] = LoadFormFile(0x200002, 0x299);
    func_80026040(obj->model[1]);
    func_80025F10(obj->model[1], (s16)(1 << player));
    obj->model[2] = LoadFormFile(0x200000, 0x299);
    func_8009EA40(D_800F2B7C[obj->model[2]].unk7C, 17.25f, 5.6f, 27.5f);
    func_80025F10(obj->model[2], (s16)(1 << player));
    obj->model[3] = LoadFormFile(0x200000, 0x299);
    func_80025F10(obj->model[3], (s16)(1 << player));
    func_8009EA40(D_800F2B7C[obj->model[3]].unk7C, -17.25f, 5.6f, 27.5f);
}
// srl for sra after the signed-division bias
// decomp-permuter
void func_800F8204_FaceLift(omObjData *obj)
{
  int new_var;
  new_var = (s16) (rand8() & 0xFF);
  D_800FC966_FaceLift = new_var / 32;
  D_800FC9E8_FaceLift = omAddObj(0x1388, 0, 0, -1, func_800FB608_FaceLift);
  obj->func_ptr = func_800F8274_FaceLift;
}
void func_800F8274_FaceLift(omObjData* obj) {
    omObjData* o;
    s16 i;

    if (obj->unk_10 & 1) {
        for (i = 0; i < 4; i++) {
            D_800FC9D8_FaceLift[i] = o = omAddObj(0x7D0, 5, 1, -1, func_800F6974_FaceLift);
            omSetStatBit(o, 0xA0);
            o->unk_10 = 0;
            o->work[0] = i;
            D_800FC9CA_FaceLift[i] = 0;
        }
        D_800FC962_FaceLift = 1;
        D_800FC964_FaceLift = 30;
        obj->func_ptr = func_800F8378_FaceLift;
    }
}













void func_800F8378_FaceLift(omObjData* obj) {
    if (D_800FC964_FaceLift != 0) {
        if (--D_800FC964_FaceLift == 0) {
            GMesCreate(6, D_800FC7AC_FaceLift[GwPlayer[0].character], 0x50, 0x50, 1.0, 1.0, 0);
            GMesCreate(6, D_800FC7AC_FaceLift[GwPlayer[1].character], 0xF0, 0x50, 1.0, 1.0, 0);
            GMesCreate(6, D_800FC7AC_FaceLift[GwPlayer[2].character], 0x50, 0xC8, 1.0, 1.0, 0);
            GMesCreate(6, D_800FC7AC_FaceLift[GwPlayer[3].character], 0xF0, 0xC8, 1.0, 1.0, 0);
            obj->func_ptr = func_800F84B4_FaceLift;
            D_800FC964_FaceLift = 30;
        }
    }
}
void func_800F84B4_FaceLift(omObjData* obj) {
    s16 stat;

    if (D_800FC964_FaceLift != 0) {
        if (--D_800FC964_FaceLift == 0) {
            GMesCreate(0);
            obj->work[0] = 0;
        }
    } else {
        stat = GMesStatAllGet();
        if (stat == 0) {
            D_800FC962_FaceLift = 2;
            D_800FC964_FaceLift = 900;
            GMesCreate(8, 30, 0xA0, 0x1C);
            obj->func_ptr = func_800F8588_FaceLift;
        }
        if (stat == 2 && obj->work[0] == 0) {
            obj->work[0] = 1;
        }
    }
}
void func_800F8588_FaceLift(omObjData* obj) {
    if (D_800FC964_FaceLift > 0) {
        if (--D_800FC964_FaceLift == 0) {
            D_800FC962_FaceLift = 3;
            func_80079078(0);
            D_800FC9C8_FaceLift = func_800FB9E8_FaceLift();
            D_800FC964_FaceLift = 15;
            obj->func_ptr = func_800F8608_FaceLift;
        }
    }
}
void func_800F8608_FaceLift(omObjData* obj) {
    if (--D_800FC964_FaceLift <= 0) {
        GMesCreate(2);
        func_800790C0();
        obj->func_ptr = func_800F8660_FaceLift;
    }
}
void func_800F8660_FaceLift(omObjData* obj) {
    if (GMesStatAllGet() == 2) {
        D_800FC964_FaceLift = 60;
        PlaySound(0x1C0);
        obj->func_ptr = func_800F86AC_FaceLift;
    }
}
void func_800F86AC_FaceLift(omObjData* obj) {
    s16 i;
    s16 r;

    if (--D_800FC964_FaceLift == 30) {
        func_80060758(0x1C0);
        if (D_800FCA0C_FaceLift == 0) {
            if (D_800FC9C8_FaceLift == 4) {
                func_80060128(0x37);
            } else if (D_800FC9C8_FaceLift == 1) {
                func_80060128(0x32);
            } else if (D_800FC9C8_FaceLift == 0) {
                func_80060128(0x34);
            } else {
                func_80060128(0x36);
            }
        } else {
            PlaySound(0x1C1);
        }
    }
    if (D_800FC964_FaceLift >= 31) {
        r = ((rand8() & 0xFF) * 101) >> 8;
        for (i = 0; i < 4; i++) {
            func_800FC14C_FaceLift(D_800FC9FA_FaceLift[i], r);
        }
    } else if (D_800FC964_FaceLift < 10) {
        for (i = 0; i < 4; i++) {
            if (D_800FC9CA_FaceLift[i] == 0) {
                func_800FC30C_FaceLift(D_800FC9FA_FaceLift[i], D_800FC964_FaceLift);
            }
        }
    } else if (D_800FC964_FaceLift > 0) {
        for (i = 0; i < 4; i++) {
            func_800FC14C_FaceLift(D_800FC9FA_FaceLift[i], D_800FCA02_FaceLift[i]);
        }
    }
    if (D_800FC964_FaceLift <= 0) {
        if (D_800FCA0C_FaceLift != 0) {
            obj->func_ptr = func_800F8D5C_FaceLift;
            D_800FC964_FaceLift = 60;
            if (D_800FC9CA_FaceLift[0] != 0) {
                GwPlayer[0].coins_mg += 10;
            }
        } else {
            D_800FC962_FaceLift = 4;
            D_800FC964_FaceLift = 30;
            if (D_800FC9C8_FaceLift == 1) {
                for (i = 0; i < 4; i++) {
                    if (D_800FC9CA_FaceLift[i] != 0) {
                        GwPlayer[i].coins_mg += 10;
                        break;
                    }
                }
                omSetStatBit(omAddObj(0x1388, 0, 0, -1, func_800FAA64_FaceLift), 0xA0);
            } else {
                for (i = 0; i < 4; i++) {
                    if (D_800FC9CA_FaceLift[i] != 0) {
                        if (D_800FCA0A_FaceLift == 0) {
                            func_800FB0BC_FaceLift(i);
                        }
                        GwPlayer[i].coins_mg += 10;
                    }
                }
            }
            obj->func_ptr = func_800F8A98_FaceLift;
        }
    }
}


const char D_800FC940_FaceLift[] = "\x82\x76\x82\x68\x82\x6D";
const char D_800FC948_FaceLift[] = "\x82\x6B\x82\x6E\x82\x72\x82\x64";

void func_800F8A98_FaceLift(omObjData* obj) {
    s16 i;
    s16 j;
    u16 t;
    s16 mes;

    if (D_800FC964_FaceLift > 0) {
        if (--D_800FC964_FaceLift == 0) {
            if (D_800FC9C8_FaceLift == 1) {
                for (j = 0; j < 4; j++) {
                    if (D_800FC9CA_FaceLift[j] != 0) {
                        break;
                    }
                }
                GMesPosSet(GMesCreate(4, GwPlayer[j].character), 160.0f, 160.0f);
            } else {
                for (i = 0; i < 4; i++) {
                    if (D_800FC9CA_FaceLift[i] != 0) {
                        mes = GMesCreate(6, D_800FC940_FaceLift, (i & 1) * 160 + 80, ((i >> 1) & 1) * 120 + 70, 1.0, 1.0, 0);
                    } else {
                        mes = GMesCreate(6, D_800FC948_FaceLift, (i & 1) * 160 + 80, ((i >> 1) & 1) * 120 + 70, 1.0, 1.0, 0);
                    }
                    GMesMaxTimeGet(mes, 32000);
                }
            }
            t = (D_800FCA0A_FaceLift == 0) ? 60 : 0;
            if (D_800FC9C8_FaceLift == 4) {
                D_800FC9F8_FaceLift = t + 60;
            } else if (D_800FC9C8_FaceLift == 1) {
                D_800FC9F8_FaceLift = t + 60;
            } else if (D_800FC9C8_FaceLift == 0) {
                D_800FC9F8_FaceLift = t / 2 + 30;
            } else {
                D_800FC9F8_FaceLift = t + 50;
            }
            D_800FC962_FaceLift = 5;
            obj->func_ptr = func_800F8CE0_FaceLift;
        }
        D_800FC3D2_FaceLift = 1;
    }
}
void func_800F8CE0_FaceLift(omObjData* obj) {
    s16 i;

    if (--D_800FC9F8_FaceLift <= 0) {
        D_800FC3D0_FaceLift = 1;
    }
    for (i = 0; i < 4; i++) {
        if (ContBtnTrg[i] & 0x8000) {
            D_800FC3D0_FaceLift = 1;
        }
    }
}
void func_800F8D5C_FaceLift(omObjData* obj) {
    if (--D_800FC964_FaceLift == 30) {
        func_80060758(0x1C0);
    }
    if (D_800FC964_FaceLift == 0 || GMesWait() == 0) {
        D_800FC3D0_FaceLift = 1;
    }
}
void func_800F8DC8_FaceLift(omObjData* arg0) {
    s16 i;

    func_800F80A4_FaceLift(arg0, 4);
    func_800FA374_FaceLift(arg0->model[0], arg0->model[1]);
    func_800258EC(arg0->model[0], 4, 4);
    func_800258EC(arg0->model[1], 4, 4);
    func_800258EC(arg0->model[2], 4, 4);
    func_800258EC(arg0->model[3], 4, 4);
    arg0->model[4] = LoadFormFile(0x200003, 0x219);
    func_80025F10(arg0->model[4], 16);
    func_80025830(arg0->model[4], 3.8f, 3.8f, 3.8f);
    
    for (i = 0; i < ARRAY_COUNT(D_800FC980_FaceLift); i++) {
        D_800FC980_FaceLift[i].x = D_800FC4B0_FaceLift[i].x;
        D_800FC980_FaceLift[i].y = D_800FC4B0_FaceLift[i].y;
        D_800FC980_FaceLift[i].z = 0;
    }
    
    func_80023504(1, 0.0f, 119.0f, 0.0f);
    func_80023504(2, 0.0f, -117.0f, 22.0f);
    func_800234B8(2, 0xFF, 0, 0);
    func_80025F10(func_8002451C(0, &func_800F9988_FaceLift, 0), 16);
    D_800FC9F0_FaceLift[0] = ((-17.25f - D_800FC4B0_FaceLift[4].x) / (D_800FC4B0_FaceLift[4].x - D_800FC4B0_FaceLift[2].x));
    D_800FC9F0_FaceLift[1] = ((-17.25f - D_800FC4B0_FaceLift[4].x) / (D_800FC4B0_FaceLift[4].x - D_800FC4B0_FaceLift[3].x));
    arg0->work[0] = 0;
    SetFadeInTypeAndTime(0, 16);
    arg0->func_ptr = &func_800F8FCC_FaceLift;
}

void func_800F8FCC_FaceLift(omObjData* obj) {
    if (func_80072718() == 0) {
        func_800258EC(obj->model[0], 4, 0);
        func_800258EC(obj->model[1], 4, 0);
        func_800258EC(obj->model[2], 4, 0);
        func_800258EC(obj->model[3], 4, 0);
        PlaySound(0x239);
        obj->func_ptr = func_800F9058_FaceLift;
    }
}
// float register allocation, one mov.s
// decomp-permuter
void func_800F9058_FaceLift(omObjData *obj)
{
  f32 s;
  f32 t;
  s = func_800AEAC0(obj->work[0] * 45.0f) * ((30.0f - obj->work[0]) / 30.0f);
  if (s < 0.0f)
  {
    t = (-s) + 1.0f;
  }
  else
  {
    t = s + 1.0f;
  }
  s = t;
  omSetSca(obj, t, s, s);
  func_80025830(obj->model[1], s, t, t);
  func_80025830(obj->model[2], s, t, s);
  func_80025830(obj->model[3], s, s, s);
  if (D_800F384E == 0)
  {
    obj->work[0]++;
  }
  if (obj->work[0] >= 31)
  {
    obj->work[0] = 0;
    PlaySound(0x23C);
    obj->func_ptr = func_800F91C0_FaceLift;
  }
}
// scheduling (one sub.s)
#ifdef NON_MATCHING
void func_800F91C0_FaceLift(omObjData* obj) {
    f32 t;
    f32 s;
    s16 i;

    if (obj->work[0] < 50) {
        for (i = 0; i < 6; i++) {
            t = obj->work[0] / 50.0f;
            D_800FC980_FaceLift[i].x = t * D_800FC5F0_FaceLift[D_800FC966_FaceLift * 6 + i].x + (1.0f - t) * D_800FC4B0_FaceLift[i].x;
            D_800FC980_FaceLift[i].y = t * D_800FC5F0_FaceLift[D_800FC966_FaceLift * 6 + i].y + (1.0f - t) * D_800FC4B0_FaceLift[i].y;
        }
        func_800F99E8_FaceLift(&D_800FC980_FaceLift[4], &D_800FC980_FaceLift[2], obj->model[2], 1);
        func_800F99E8_FaceLift(&D_800FC980_FaceLift[4], &D_800FC980_FaceLift[3], obj->model[3], 0);
    } else {
        t = (30.0f - (obj->work[0] - 50.0f)) / 30.0f * 0.7f + 0.3f;
        omSetSca(obj, t, t, t);
        func_80025830(obj->model[1], t, t, t);
        func_80025830(obj->model[2], t, t, t);
        func_80025830(obj->model[3], t, t, t);
        t = (30.0f - (obj->work[0] - 50.0f)) / 30.0f * 3.0f + 0.8f;
        func_80025830(obj->model[4], t, t, t);
        D_800FC9EC_FaceLift->unk_10 |= 1;
        s = (30.0f - (obj->work[0] - 50.0f)) / 30.0f;
        func_80023504(1, 64.0f - s * 64.0f, 119.0f - s * 55.0f, 96.0f - s * 96.0f);
        func_800234B8(2, t, 0, 0);
        t = (30.0f - (obj->work[0] - 50.0f)) / 30.0f * 255.0f;
        func_800234B8(2, t, 0, 0);
    }
    if (obj->work[0] == 50) {
        func_80060128(0x25);
    }
    if (D_800F384E == 0) {
        obj->work[0]++;
    }
    if (obj->work[0] > 80.0f) {
        omSetSca(obj, 0.3f, 0.3f, 0.3f);
        func_80025830(obj->model[1], 0.3f, 0.3f, 0.3f);
        func_80025830(obj->model[2], 0.3f, 0.3f, 0.3f);
        func_80025830(obj->model[3], 0.3f, 0.3f, 0.3f);
        func_80025830(obj->model[4], 0.8f, 0.8f, 0.8f);
        obj->func_ptr = func_800F9800_FaceLift;
    }
    for (i = 0; i < 6; i++) {
        func_800FA5B4_FaceLift(obj->model[D_800FC4B0_FaceLift[i].model], i, &D_800FC980_FaceLift[i]);
    }
    func_800FA7D0_FaceLift(obj->model[D_800FC4B0_FaceLift[6].model], 6, &D_800FC980_FaceLift[2]);
    func_800FA7D0_FaceLift(obj->model[D_800FC4B0_FaceLift[7].model], 7, &D_800FC980_FaceLift[3]);
    if (D_800FC3D2_FaceLift != 0 && D_800FC9C8_FaceLift == 1) {
        func_800258EC(obj->model[0], 4, 4);
        func_800258EC(obj->model[1], 4, 4);
        func_800258EC(obj->model[2], 4, 4);
        func_800258EC(obj->model[3], 4, 4);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_FaceLift/12BC20", func_800F91C0_FaceLift);
#endif
void func_800F9800_FaceLift(omObjData* obj) {
    s16 i;

    for (i = 0; i < 6; i++) {
        func_800FA5B4_FaceLift(obj->model[D_800FC4B0_FaceLift[i].model], i, &D_800FC980_FaceLift[i]);
    }
    func_800FA7D0_FaceLift(obj->model[D_800FC4B0_FaceLift[6].model], 6, &D_800FC980_FaceLift[2]);
    func_800FA7D0_FaceLift(obj->model[D_800FC4B0_FaceLift[7].model], 7, &D_800FC980_FaceLift[3]);
    if (D_800FC3D2_FaceLift != 0) {
        if (D_800FC9C8_FaceLift == 1) {
            func_800258EC(obj->model[0], 4, 4);
            func_800258EC(obj->model[1], 4, 4);
            func_800258EC(obj->model[2], 4, 4);
            func_800258EC(obj->model[3], 4, 4);
        }
        if (D_800FC3D2_FaceLift != 0 && D_800FC9C8_FaceLift == 1) {
            func_800258EC(obj->model[4], 4, 4);
        }
    }
}
void func_800F9988_FaceLift(Gfx** gfx) {
    gDPSetDepthImage((*gfx)++, 0x003D0800);
    gDPSetColorImage((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, 0x003D0800);
    gSPDisplayList((*gfx)++, D_800FC7E8_FaceLift);
}
// scheduling (one nop)
#ifdef NON_MATCHING
void func_800F99E8_FaceLift(Vec3f* a, Vec3f* b, s16 model, s16 side) {
    f32 k = D_800FC9F0_FaceLift[side];
    f32 x = a->x;
    f32 dx;
    f32 dy;

    if (x - b->x < 0.0f) {
        dx = -(x - b->x);
    } else {
        dx = a->x - b->x;
    }
    dx = dx * k + x;
    if (D_800FC4B0_FaceLift[4].y == a->y) {
        dy = 0.0f;
    } else {
        dy = (a->y - D_800FC4B0_FaceLift[4].y) / 2.0f;
    }
    func_8009EA40(D_800F2B7C[model].unk7C, dx, dy + 5.6f, 27.5f);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_FaceLift/12BC20", func_800F99E8_FaceLift);
#endif
void func_800F9AD4_FaceLift(omObjData* arg0) {
    s16 temp = InitSprite(0x20000B);
    
    D_800FC960_FaceLift = func_80019060(temp, 0, 1);
    func_80018C90(D_800FC960_FaceLift);
    arg0->work[1] = 0;
    arg0->func_ptr = &func_800F9B38_FaceLift;
}

void func_800F9B38_FaceLift(omObjData* obj) {
    if (D_800FC962_FaceLift == 2) {
        func_80079078((D_800FC964_FaceLift + 29) / 30);
    }
    func_800F9BC8_FaceLift();
    if (D_800FC3D2_FaceLift != 0 && obj->work[1] == 0) {
        obj->work[1] = 1;
    }
}
void func_800F9BC8_FaceLift(void) {
    unk65770Obj* spr;
    s32* img;
    s16 i;
    s16 y;
    s16 x;

    spr = func_800675F4(D_800ED60C[D_800FC960_FaceLift].unk_04, 0);
    img = (s32*)&spr->unk4C->unk0[spr->unk52];
    gSPDisplayList(D_800F37DC++, D_800FC830_FaceLift);
    gDPSetTextureLUT(D_800F37DC++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(D_800F37DC++, spr->unk4C->unkC);
    for (i = 0; i < 6; i++) {
        func_8003A060(&D_800F37DC, *img + i * 800, 2, 1, 80, 60, 0, 0, 80, 10, 0, 2, 2, 0, 0, 0, 0);
        for (y = i * 10; y < 240; y += 60) {
            for (x = 0; x < 320; x += 80) {
                gSPTextureRectangle(D_800F37DC++, x * 4, y * 4, (x + 80) * 4, (y + 10) * 4, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
            }
        }
    }
}
void func_800F9EE4_FaceLift(omObjData* obj) {
    Vec3f eye;
    Vec3f at;
    Vec3f up;
    f32 rx = CRot.x;
    f32 ry = CRot.y;
    s16 i;

    eye.x = Center.x + func_800AEAC0(ry) * func_800AEFD0(rx) * CZoom;
    eye.y = -func_800AEAC0(rx) * CZoom + Center.y;
    eye.z = func_800AEFD0(ry) * func_800AEFD0(rx) * CZoom + Center.z;
    at.x = Center.x;
    at.y = Center.y;
    at.z = Center.z;
    up.x = func_800AEAC0(ry) * func_800AEAC0(rx);
    up.y = func_800AEFD0(rx);
    up.z = func_800AEFD0(ry) * func_800AEAC0(rx);
    for (i = 0; i < 5; i++) {
        func_8001D420(i, &eye, &at, &up);
        func_8001D57C(i);
    }
}
// missing mov.s/move in the abs tests
#ifdef NON_MATCHING
s32 func_800FA058_FaceLift(s16 player, Vec3f* pos) {
    Matrix4f mtx;
    Vec2f sc;
    unk_Struct00* cam;
    f32 z;
    f32 h;
    f32 w;
    f32 x;
    f32 y;
    f32 a;

    cam = &D_800C3110[player];
    HuGuLookAtF(mtx, cam->pos.x, cam->pos.y, cam->pos.z, cam->unkC.x, cam->unkC.y, cam->unkC.z, cam->unk18.x, cam->unk18.y, cam->unk18.z);
    MtxTranslate(mtx, pos->x, pos->y, pos->z);
    x = mtx[3][0];
    y = mtx[3][1];
    z = -mtx[3][2];
    if (z < cam->unk_44 || cam->unk_48 < z) {
        return 0;
    }
    h = func_800AEAC0(cam->unk_40 / 2.0f) / func_800AEFD0(cam->unk_40 / 2.0f) * z;
    w = h * 1.3333334f;
    Convert3DTo2D(player, pos, &sc);
    sc.x = sc.x / 2.0f + D_800FC4A0_FaceLift[player].x;
    sc.y = sc.y / 2.0f + D_800FC4A0_FaceLift[player].y;
    if (sc.x < 20.0f || sc.x > 300.0f || sc.y < 16.0f || sc.y > 236.0f) {
        return 0;
    }
    a = x;
    if (a < 0.0f) {
        a = -a;
    }
    if (!(w < 0.0f ? a < -w : a < w)) {
        return 0;
    }
    a = y;
    if (a < 0.0f) {
        a = -a;
    }
    if (h < 0.0f ? a < -h : a < h) {
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_FaceLift/12BC20", func_800FA058_FaceLift);
#endif
// register allocation
#ifdef NON_MATCHING
void func_800FA374_FaceLift(s16 model0, s16 model1) {
    unk2C0C0StructC0* grp[2];
    unk2C0C0StructC0** g;
    unk2C0C0StructE0* v;
    f32 px;
    f32 py;
    f32 r2;
    f32 d;
    f32 ex;
    f32 ey;
    s16 n;
    s16 i;
    s16 j;
    s16 k;

    grp[0] = D_800F2B7C[model0].unk_6C;
    grp[1] = D_800F2B7C[model1].unk_6C;
    for (i = 0; i < 8; i++) {
        g = &grp[D_800FC4B0_FaceLift[i].model];
        n = (*g)->unk_72;
        D_800FC4B0_FaceLift[i].verts = func_80023684(n * 2, 0x7918);
        px = D_800FC4B0_FaceLift[i].x;
        py = D_800FC4B0_FaceLift[i].y;
        v = (*g)->unk_04;
        r2 = D_800FC4B0_FaceLift[i].radius;
        r2 *= r2;
        k = 0;
        for (j = 0; j < n; j++, v++) {
            ex = px - v->unk_00;
            ey = py - v->unk_02;
            d = func_800B1750(ex * ex + ey * ey);
            if ((r2 - d * d) / r2 > 0.05f) {
                D_800FC4B0_FaceLift[i].verts[k++] = j;
            }
        }
        D_800FC4B0_FaceLift[i].count = k;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_FaceLift/12BC20", func_800FA374_FaceLift);
#endif
// scheduling (model index)
#ifdef NON_MATCHING
void func_800FA5B4_FaceLift(s16 model, s16 part, Vec3f* p) {
    unk_ovl_2D_struct* m;
    unk2C0C0StructC0* g;
    unk2C0C0StructE0* src;
    unk2C0C0StructE0* dst;
    s16* verts;
    f32 ox;
    f32 oy;
    f32 dx;
    f32 dy;
    f32 r2;
    f32 d;
    f32 f;
    s16 i;
    s16 n;
    f32 ex;
    f32 ey;

    m = D_800F2B7C + model;
    g = m->unk_6C;
    ox = D_800FC4B0_FaceLift[part].x - m->unk_24;
    oy = D_800FC4B0_FaceLift[part].y - m->unk_28;
    dx = p->x - D_800FC4B0_FaceLift[part].x;
    dy = p->y - D_800FC4B0_FaceLift[part].y;
    verts = D_800FC4B0_FaceLift[part].verts;
    r2 = D_800FC4B0_FaceLift[part].radius;
    r2 *= r2;
    n = D_800FC4B0_FaceLift[part].count;
    for (i = 0; i < n; i++, verts++) {
        src = &g->unk_04[*verts];
        dst = &g->unk_08[D_800F37F0][*verts];
        ex = ox - src->unk_00;
        ey = oy - src->unk_02;
        d = func_800B1750(ex * ex + ey * ey);
        f = (r2 - d * d) / r2;
        if (f > 0.05f) {
            dst->unk_00 = src->unk_00 + dx * f;
            dst->unk_02 = src->unk_02 + dy * f;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_FaceLift/12BC20", func_800FA5B4_FaceLift);
#endif
// scheduling (vertex index)
#ifdef NON_MATCHING
void func_800FA7D0_FaceLift(s16 model, s16 part, Vec3f* p) {
    unk_ovl_2D_struct* m;
    unk2C0C0StructC0* g;
    unk2C0C0StructE0* dst;
    s16* verts;
    f32 ox;
    f32 oy;
    f32 dx;
    f32 dy;
    f32 r2;
    f32 d;
    f32 f;
    s16 i;
    s16 n;
    f32 ex;
    f32 ey;

    m = D_800F2B7C + model;
    g = m->unk_6C;
    ox = D_800FC4B0_FaceLift[part].x - m->unk_24;
    oy = D_800FC4B0_FaceLift[part].y - m->unk_28;
    dx = p->x - D_800FC4B0_FaceLift[part].x;
    dy = p->y - D_800FC4B0_FaceLift[part].y;
    verts = D_800FC4B0_FaceLift[part].verts;
    r2 = D_800FC4B0_FaceLift[part].radius;
    r2 *= r2;
    n = D_800FC4B0_FaceLift[part].count;
    for (i = 0; i < n; i++, verts++) {
        dst = *verts + g->unk_08[D_800F37F0];
        ex = ox - dst->unk_00;
        ey = oy - dst->unk_02;
        d = func_800B1750(ex * ex + ey * ey);
        f = (r2 - d * d) / r2;
        if (f > 0.05f) {
            dst->unk_00 = dst->unk_00 + dx * f;
            dst->unk_02 = dst->unk_02 + dy * f;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_FaceLift/12BC20", func_800FA7D0_FaceLift);
#endif
void func_800FA9DC_FaceLift(omObjData* arg0) {
    if (D_800FC3D0_FaceLift != 0 || D_800F5144 != 0) {
        func_800726AC(0, 0x14);
        arg0->func_ptr = &func_800FAA38_FaceLift;
        func_800601D4(40);
    }
}

void func_800FAA38_FaceLift(omObjData* obj) {
    if (func_80072718() == 0) {
        omOvlReturnEx(1);
    }
}
void func_800FAA64_FaceLift(omObjData* obj) {
    s16 i;

    obj->unk_50 = func_80023684(0x25840, 0x7918);
    D_800FCA1C_FaceLift = func_8002451C(0, func_800FACB8_FaceLift, 6);
    D_800FCA18_FaceLift = (s32)(((u32)obj->unk_50 + 0x40) & ~0x3F);
    obj->func_ptr = func_800FAB24_FaceLift;
    obj->work[0] = 0;
    for (i = 0; i < 4; i++) {
        if (D_800FC9CA_FaceLift[i] != 0) {
            D_800FC9D2_FaceLift = i;
            break;
        }
    }
}
void func_800FAB24_FaceLift(omObjData* obj) {
    func_8002456C(D_800FCA1C_FaceLift);
    gDPSetScissor(D_800F37DC++, G_SC_NON_INTERLACE, obj->work[0], obj->work[0], 320 - obj->work[0], 240 - obj->work[0]);
    func_800FAEE0_FaceLift(D_800FCA18_FaceLift);
    gDPSetScissor(D_800F37DC++, G_SC_NON_INTERLACE, 0, 0, 320, 240);
    if (D_800F384E == 0) {
        if (obj->work[0] < 120) {
            obj->work[0] += 5;
            if (obj->work[0] >= 51) {
                D_800FC9D8_FaceLift[D_800FC9D2_FaceLift]->unk_10 |= 1;
            }
        } else {
            func_80023888(obj->unk_50);
            omDelObj(obj);
        }
    }
}
void func_800FACB8_FaceLift(Gfx** gfx) {
    func_800FACD8_FaceLift(gfx, D_800FCA18_FaceLift);
}

void func_800FACD8_FaceLift(Gfx** gfx, s32 buf) {
    s16 x;
    s16 y;

    gSPDisplayList((*gfx)++, D_800FC870_FaceLift);
    gDPSetColorImage((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, buf);
    for (y = 0; y < 240; y += 16) {
        for (x = 0; x < 320; x += 64) {
            func_8003A060(gfx, (x + y * 320) * 2 + 0x02000000, 0, 2, 320, 240, 0, 0, 64, 16, 0, 2, 2, 0, 0, 0, 0);
            gSPTextureRectangle((*gfx)++, x * 4, y * 4, (x + 64) * 4, (y + 16) * 4, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
        }
    }
    gDPSetColorImage((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, 0x02000000);
}
void func_800FAEE0_FaceLift(s32 buf) {
    s16 x;
    s16 y;

    gSPDisplayList(D_800F37DC++, D_800FC870_FaceLift);
    for (y = 0; y < 240; y += 16) {
        for (x = 0; x < 320; x += 64) {
            func_8003A060(&D_800F37DC, buf + (x + y * 320) * 2, 0, 2, 320, 240, 0, 0, 64, 16, 0, 2, 2, 0, 0, 0, 0);
            gSPTextureRectangle(D_800F37DC++, x * 4, y * 4, (x + 64) * 4, (y + 16) * 4, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
        }
    }
}
void func_800FB0BC_FaceLift(s16 player) {
    omObjData* o;
    void* data;
    s16 id;
    s16 i;

    data = DataRead(D_800FC770_FaceLift[D_800FC3D4_FaceLift]);
    id = func_8001E00C(data, 0x280, 8);
    func_80025F10(D_800ECDE0[id].unk_00, (s16)(1 << player));
    HuMemDirectFree(data);
    for (i = 0; i < 10; i++) {
        o = omAddObj(0x7D0, 0, 0, -1, func_800FB1B4_FaceLift);
        o->work[0] = player;
        o->work[1] = i;
        o->work[2] = id;
    }
}
void func_800FB1B4_FaceLift(omObjData* obj) {
    FaceLiftStar* w;

    w = obj->unk_50 = func_80023684(sizeof(FaceLiftStar), 0x7918);
    w->h = 15.0f;
    w->y = 100.0f;
    w->x = w->z = 0.0f;
    w->angle = obj->work[0];
    w->count = 0;
    w->id = func_8001E1D0(obj->work[2], 8);
    func_80025F10(D_800ECDE0[w->id].unk_00, (s16)(1 << obj->work[0]));
    w->timer = obj->work[1] * 5;
    obj->func_ptr = func_800FB29C_FaceLift;
}
// non-short-circuit test shape and register allocation
#ifdef NON_MATCHING
void func_800FB29C_FaceLift(omObjData* obj) {
    FaceLiftStar* w;
    f32 x;
    f32 z;
    f32 dy;
    u16 m;
    s16 n;
    u8 r;
    u8 g;
    u8 b;
    s32 on;
    u8 k;
    s16 light;

    w = obj->unk_50;
    if (w->timer != 0) {
        w->timer--;
    }
    m = D_800ECDE0[w->id].unk_00;
    n = w->count++;
    if (n >= 3) {
        w->count = 0;
        dy = func_800AEFD0(2.0f * w->angle) * 5.0f;
        func_800FB858_FaceLift(obj->work[0], w->x, dy + w->y, w->z, 2);
    }
    w->x = x = func_800AEAC0(w->angle) * 100.0f;
    w->z = z = func_800AEFD0(w->angle) * 100.0f;
    w->angle += 3.0f;
    dy = func_800AEFD0(2.0f * w->angle) * 5.0f;
    r = 224;
    if (w->h > 0.0f) {
        r = 224.0f - w->h * 10.0f;
        g = 224.0f - w->h * 10.0f;
        b = 192.0f - w->h * 10.0f;
        w->y -= w->h;
        w->h -= 1.0f;
    } else {
        g = 224;
        b = 192;
    }
    func_80025798(m, x, dy + w->y, z);
    k = obj->work[1];
    on = k != 0;
    if (!(on & (k != 9))) {
        light = on ? 3 : 2;
        func_800234B8(light, r, g, b);
        func_80023504(light, x, dy + w->y, z);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_FaceLift/12BC20", func_800FB29C_FaceLift);
#endif
void func_800FB608_FaceLift(omObjData* obj) {
    FaceLiftFxWork* w;
    void* data;
    s16 tex;
    s16 i;
    s16 m;

    w = obj->unk_50 = func_80023684(sizeof(FaceLiftFxWork), 0x7918);
    data = DataRead(0x2A);
    tex = func_80039084(data);
    HuMemDirectFree(data);
    for (i = 0; i < 20; i++) {
        w->fx[i].model = m = func_8001E00C((void*)-1, 0x284, 8);
        func_8001E360(m, 0xFF, 0xFF, 0xBE);
        D_800ECDE0[m].unk_02 = tex;
        func_8001E268(m, 4, 4);
        w->state[i] = 0;
    }
    obj->func_ptr = func_800FB724_FaceLift;
}
void func_800FB724_FaceLift(omObjData* obj) {
    FaceLiftFxWork* w;
    FaceLiftFx* fx;
    u16 m;
    s16 i;

    w = obj->unk_50;
    for (i = 0; i < 20; i++) {
        if (w->state[i] != 0) {
            fx = &w->fx[i];
            m = D_800ECDE0[fx->model].unk_00;
            switch (w->state[i]) {
            case 1:
                break;
            case 2:
                fx->y += fx->vy;
                fx->vy -= 0.3f;
                func_80025798(m, fx->x, fx->y, fx->z);
                break;
            }
            func_8001E2F8(fx->model, fx->alpha);
            if (D_800F2B7C[(s16)m].unk_20 & 4) {
                w->state[i] = 0;
            }
        }
    }
}
void func_800FB858_FaceLift(s16 player, f32 x, f32 y, f32 z, u16 type) {
    FaceLiftFxWork* w;
    FaceLiftFx* fx;
    u16 m;
    s16 i;

    w = D_800FC9E8_FaceLift->unk_50;
    for (i = 0; i < 20; i++) {
        if (w->state[i] == 0) {
            break;
        }
    }
    if (i != 20) {
        fx = &w->fx[i];
        m = D_800ECDE0[fx->model].unk_00;
        fx->x = x;
        fx->y = y;
        fx->z = z;
        fx->vy = 2.0f;
        fx->alpha = 0xFF;
        w->state[i] = type;
        fx->player = player;
        func_8001E2F8(fx->model, 0);
        func_800258EC(m, 4, 0);
        D_800ECDE0[fx->model].unk_04 = 0;
        func_80025798(m, x, y, z);
        func_80025830(m, 2.0f, 2.0f, 2.0f);
        func_80025F10(m, (s16)(1 << player));
    }
}
// register allocation, one extra instruction
#ifdef NON_MATCHING
s16 func_800FB9E8_FaceLift(void) {
    f32 dist[4];
    FaceLiftWork* w;
    f32 dx;
    f32 dy;
    s16 i;
    s16 j;
    s16 n;
    s16 max;
    s16 th;
    s16 k;

    for (i = 0; i < 4; i++) {
        dist[i] = 0.0f;
        n = 0;
        for (j = 0; j < 6; j++) {
            w = D_800FC9D8_FaceLift[i]->unk_50;
            if (w->pts[j].x == D_800FC4B0_FaceLift[j].x && w->pts[j].y == D_800FC4B0_FaceLift[j].y) {
                n++;
            }
            dx = w->pts[j].x - D_800FC5F0_FaceLift[D_800FC966_FaceLift * 6 + j].x;
            dy = w->pts[j].y - D_800FC5F0_FaceLift[D_800FC966_FaceLift * 6 + j].y;
            dist[i] += func_800B1750(dx * dx + dy * dy);
        }
        if (n == 6) {
            dist[i] = 10000.0f;
            D_800FCA02_FaceLift[i] = 0;
        } else {
            D_800FCA02_FaceLift[i] = (300.0f - dist[i]) / 3.0f;
        }
        if (D_800FCA02_FaceLift[i] < 0) {
            D_800FCA02_FaceLift[i] = 0;
        }
    }
    max = 0;
    for (k = 0; k < 4; k++) {
        if (max < D_800FCA02_FaceLift[k]) {
            max = D_800FCA02_FaceLift[k];
        }
    }
    th = 50;
    if ((D_800FCA0A_FaceLift | D_800FCA0C_FaceLift) != 0) {
        th = 90;
    }
    if (max < th) {
        for (k = 0; k < 4; k++) {
            D_800FC9CA_FaceLift[k] = 0;
        }
        return 0;
    }
    n = 0;
    if ((D_800FCA0A_FaceLift | D_800FCA0C_FaceLift) == 0) {
        for (k = 0; k < 4; k++) {
            if (D_800FCA02_FaceLift[k] == max) {
                D_800FC9CA_FaceLift[k] = 1;
                n++;
            } else {
                D_800FC9CA_FaceLift[k] = 0;
            }
        }
    } else {
        for (k = 0; k < 4; k++) {
            if (D_800FCA02_FaceLift[k] >= 90) {
                D_800FC9CA_FaceLift[k] = 1;
                n++;
            } else {
                D_800FC9CA_FaceLift[k] = 0;
            }
        }
    }
    return n;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_FaceLift/12BC20", func_800FB9E8_FaceLift);
#endif
void func_800FBE08_FaceLift(void) {
    void* fsData;

    fsData = DataRead(0x0000007E);
    D_800FCA1E_FaceLift = func_800678A4(fsData);
    DataClose(fsData);
    fsData = DataRead(0x0020000C);
    D_800FCA2A_FaceLift = func_800678A4(fsData);
    DataClose(fsData);
    D_800FCA28_FaceLift = 0;
}

s16 func_800FBE78_FaceLift(s16 x, s16 y) {
    s16 id;
    s16 i;
    s16 xo;

    id = D_800FCA20_FaceLift[D_800FCA28_FaceLift] = func_80064EF4(4, 5);
    func_80067208(id, 0, D_800FCA1E_FaceLift, 0);
    func_80067480(id, 0, 0xFFFF);
    func_800674BC(id, 0, 0x8000);
    func_80066DC4(id, 0, x - 16, y);
    for (xo = 24, i = 1; i < 3; i++, xo += 24) {
        func_80067208(id, i, D_800FCA1E_FaceLift, 0);
        func_80066DC4(id, i, xo, 0);
        func_80067480(id, i, 0xFFFF);
        func_800674BC(id, i, 0x8000);
    }
    func_80067208(id, i, D_800FCA2A_FaceLift, 0);
    func_80066DC4(id, i, xo - 4, 6);
    func_80067480(id, i, 0xFFFF);
    func_800674BC(id, i, 0x8000);
    func_80067598(id, 1, 0);
    func_80067598(id, 2, 0);
    func_80067598(id, 3, 0);
    func_80067480(id, 2, 0x8000);
    func_80067480(id, 3, 0x8000);
    D_800FCA28_FaceLift++;
    return id;
}
void func_800FC094_FaceLift(s16 id) {
    s16 i;

    for (i = 0; i < 4; i++) {
        func_800674BC(id, i, 0x8000);
    }
}
void func_800FC0F0_FaceLift(s16 arg0) {
    s16 i;
    for (i = 0; i < 4; i++) {
        func_80067480(arg0, i, 0x8000);
    }
}

void func_800FC14C_FaceLift(s16 id, s16 val) {
    s16 hundreds;
    s16 tens;

    hundreds = 0;
    if (val >= 100) {
        func_80067480(id, 0, 0x8000);
        func_800672DC(id, 0, 1, 0);
        func_800672B0(id, 0, 1);
        val -= 100;
        hundreds = 1;
    } else {
        func_800674BC(id, 0, 0x8000);
    }
    if (hundreds != 0 || (s16)(val / 10) != 0) {
        func_80067480(id, 1, 0x8000);
        tens = val / 10;
        func_800672DC(id, 1, tens, 0);
        func_800672B0(id, 1, 1);
        val -= tens * 10;
    } else {
        func_800674BC(id, 1, 0x8000);
    }
    func_80067480(id, 2, 0x8000);
    func_800672DC(id, 2, val, 0);
    func_800672B0(id, 2, 1);
    func_80067480(id, 3, 0x8000);
}
void func_800FC30C_FaceLift(s16 arg0, s16 arg1) {
    s16 i;
    
    for (i = 0; i < 4; i++) {
        func_80067354(arg0, i, arg1 / 10.0f, arg1 / 10.0f);
    }
}

void func_800FC39C_FaceLift(s16 arg0, s16 arg1, s16 arg2) {
    func_80066DC4(arg0, 0, arg1, arg2);
}
