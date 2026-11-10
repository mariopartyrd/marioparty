#include "common.h"
#include "HotRopeJump.h"


s32 D_800FE450_HotRopeJump = 20;
s32 D_800FE454_HotRopeJump = 0;
s16 D_800FE458_HotRopeJump = 0;
s32 D_800FE45C_HotRopeJump = -1;
u16 D_800FE460_HotRopeJump = 0;
s32 D_800FE464_HotRopeJump[4] = { 0, 0, 0, 0 };
s32 D_800FE474_HotRopeJump[4] = { 0, 1, 2, 3 };
f32 D_800FE484_HotRopeJump = 0.0f;
s32 D_800FE488_HotRopeJump = 0;
s32 D_800FE48C_HotRopeJump[4][2] = { { 0xF0, 0x18 }, { 0x100, 0x18 }, { 0x110, 0x28 }, { 0x120, 0x28 } };
f32 D_800FE4AC_HotRopeJump[4] = { -2.4f, -0.8f, 0.8f, 2.4f };
omObjData* D_800FE4BC_HotRopeJump = NULL;
s32 D_800FE4C0_HotRopeJump = 0;
s32 D_800FE4C4_HotRopeJump = 0;
s32 D_800FE4C8_HotRopeJump = 0;
s32 D_800FE4CC_HotRopeJump = 150;
f32 D_800FE4D0_HotRopeJump = -360.0f;
f32 D_800FE4D4_HotRopeJump = 1.0f;
s32 D_800FE4D8_HotRopeJump = 0;
s32 D_800FE4DC_HotRopeJump = 0;
u16 D_800FE4E0_HotRopeJump[4] = { 0, 0, 0, 0 };
u16 D_800FE4E8_HotRopeJump = 0;
s16 D_800FE4EC_HotRopeJump[10] = { 0, 0x3000, 0x2000, 0, 0, 0, 0, 0, 0, 0 };

// NON_MATCHING: register allocation: retail does not hoist D_800FE464's base (masked 22)
#ifdef NON_MATCHING
void func_800F65E0_HotRopeJump(void) {
    s32* tbl;
    u8 cam;
    s16 i;
    s32 r;

    func_80029090(50);
    func_8002ADF0(&D_800EDEC0, 64);
    omInitObjMan(50, 0);
    func_80060088();
    omSetStatBit(omAddObj(32730, 0, 0, -1, omOutView), 0xA0);
    func_800178A0(1);
    cam = func_800178E8();
    func_80017660(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 30.0f, 80.0f, 8000.0f);
    func_800FA6AC_HotRopeJump(1600.0f, 0.0f, 100.0f, 100.0f, -30.0f, -50.0f, 0.0f);
    D_801004A8_HotRopeJump = 0;
    D_800ED430 = 1;
    if ((D_800FE488_HotRopeJump = _CheckFlag(0x2B)) != 0) {
        D_800FE450_HotRopeJump = 40;
    }
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    func_800090B8(0);
    D_80100320_HotRopeJump = omAddObj(1, 0, 0, -1, func_800F69A4_HotRopeJump);
    D_800F3FB0[D_800F2BC0++] = omAddObj(3, 10, 60, -1, func_800F6C9C_HotRopeJump);
    D_800F3FB0[D_800F2BC0++] = omAddObj(3, 10, 60, -1, func_800F6D30_HotRopeJump);
    D_800F3FB0[D_800F2BC0++] = omAddObj(3, 10, 60, -1, func_800F6DC4_HotRopeJump);
    D_800F3FB0[D_800F2BC0++] = omAddObj(3, 10, 60, -1, func_800F6E58_HotRopeJump);
    func_800FB260_HotRopeJump();
    D_80100310_HotRopeJump = D_800B8980;
    D_80100314_HotRopeJump = D_800B8964;
    D_80100318_HotRopeJump = D_800B8968;
    D_8010031C_HotRopeJump = D_800B8994;
    i = 0;
    tbl = D_800FE474_HotRopeJump;
    do {
    retry:
        r = rand8() & 3;
        if (tbl[r] == -1) {
            goto retry;
        }
        D_800FE464_HotRopeJump[i] = tbl[r];
        i++;
        tbl[r] = -1;
    } while (i < 4);
    D_800B8964 = 1.6f;
    D_800B8968 = 0.175f;
    SetFadeInTypeAndTime(0, 16);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HotRopeJump/207040", func_800F65E0_HotRopeJump);
#endif

void func_800F69A4_HotRopeJump(omObjData* obj) {
    void* file;
    s32 sprite;
    s32 i;

    obj->func_ptr = func_800F7210_HotRopeJump;
    func_800F8CB4_HotRopeJump(16);
    file = DataRead(0x420008);
    D_801004AC_HotRopeJump = func_800678A4(file);
    DataClose(file);
    i = 0;
    func_800FA2F4_HotRopeJump();
    file = DataRead(0x7C);
    sprite = func_800678A4(file);
    DataClose(file);
    D_801004B0_HotRopeJump = func_80064EF4(4, 0);
    do {
        func_80067208((s16)D_801004B0_HotRopeJump, i, sprite, 0);
        func_80066DC4((s16)D_801004B0_HotRopeJump, i, (s16)D_800FE48C_HotRopeJump[i][0],
                      (s16)D_800FE48C_HotRopeJump[i][1]);
        func_80067354((s16)D_801004B0_HotRopeJump, i, 1.0f, 1.0f);
        func_8006752C((s16)D_801004B0_HotRopeJump, i, 0x100);
        func_800674BC((s16)D_801004B0_HotRopeJump, i, 0x1000);
        func_800672B0((s16)D_801004B0_HotRopeJump, i, 0);
        i++;
    } while (i < 4);
    func_800671DC((s16)D_801004B0_HotRopeJump, 2, D_800FE450_HotRopeJump / 10);
    func_800671DC((s16)D_801004B0_HotRopeJump, 3, D_800FE450_HotRopeJump % 10);
    file = DataRead(0x420009);
    sprite = func_800678A4(file);
    DataClose(file);
    D_801004B4_HotRopeJump = func_80064EF4(1, 0);
    func_80067208((s16)D_801004B4_HotRopeJump, 0, sprite, 0);
    func_80066DC4((s16)D_801004B4_HotRopeJump, 0, 0x108, 0x20);
    func_80067354((s16)D_801004B4_HotRopeJump, 0, 2.0f, 2.0f);
    func_8006752C((s16)D_801004B4_HotRopeJump, 0, 0x100);
    func_800674BC((s16)D_801004B4_HotRopeJump, 0, 0x1000);
    func_800672B0((s16)D_801004B4_HotRopeJump, 0, 0);
}

void func_800F6C50_HotRopeJump(omObjData* obj) {
    func_800FA2F4_HotRopeJump();
    func_800FA9DC_HotRopeJump(obj);
    if (func_80072718() == 0) {
        func_800F8C08_HotRopeJump();
        omOvlReturnEx(1);
    }
}

/* Retail keeps two writable state pairs in .rodata (D_800FE6E0, D_800FE784); the host needs
   them writable, so only the N64 build places them there. */
#define HRJ_RODATA_RW __attribute__((section(".rodata")))

/* D_800FE500: [0] the RDP/RSP reset list, [23] the geometry/clip reset, [31] both. */
const Gfx D_800FE500_HotRopeJump[] = {
    gsSPSegment(0, 0),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPPipelineMode(G_PM_1PRIMITIVE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTileSize(0, 0, 0, 0, 0),
    gsDPSetTileSize(1, 0, 0, 0, 0),
    gsDPSetTile(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    gsDPSetTile(0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetDepthSource(G_ZS_PIXEL),
    gsDPSetRenderMode(0x0F0A4000, 0),
    gsDPNoOp(),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
    gsSPClearGeometryMode(0xFFFFFFFF),
    gsSPTexture(0, 0, 0, 0, G_OFF),
    gsSPSetGeometryMode(0x200004),
    gsSPClipRatio(FRUSTRATIO_2),
    gsSPEndDisplayList(),
    gsSPDisplayList(&D_800FE500_HotRopeJump[23]),
    gsSPDisplayList(&D_800FE500_HotRopeJump[0]),
    gsSPEndDisplayList(),
};

const Gfx D_800FE610_HotRopeJump[] = {
    gsDPPipeSync(),
    gsSPDisplayList(&D_800FE500_HotRopeJump[31]),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPSetGeometryMode(0x220401),
    gsDPSetBlendColor(0, 0, 0, 0),
    gsDPSetPrimColor(0, 0, 0, 0, 0, 0xFF),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPEndDisplayList(),
};

/* Torch flame: a five-vertex base (0-4) and a four-vertex top (5-8). */
const Vtx_t D_800FE650_HotRopeJump[9] = {
    { { -120, 300, 0 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } },
    { { 120, 300, 0 }, 0, { 0x800, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } },
    { { 100, -100, 0 }, 0, { 0x800, 0x1000 }, { 0xFF, 0xFF, 0xFF, 0x10 } },
    { { -100, -100, 0 }, 0, { 0, 0x1000 }, { 0xFF, 0xFF, 0xFF, 0x10 } },
    { { 0, 0, 0 }, 0, { 0x400, 0xC00 }, { 0xFF, 0xFF, 0xFF, 0xF0 } },
    { { -100, 50, 50 }, 0, { 0, 0 }, { 0x00, 0x00, 0x00, 0xFF } },
    { { 100, 50, 50 }, 0, { 0x1000, 0 }, { 0x00, 0x00, 0x00, 0xFF } },
    { { 100, -50, 50 }, 0, { 0x1000, 0x800 }, { 0x00, 0x00, 0x00, 0xFF } },
    { { -100, -50, 50 }, 0, { 0, 0x800 }, { 0x00, 0x00, 0x00, 0xFF } },
};

HRJSeq D_800FE6E0_HotRopeJump HRJ_RODATA_RW = { 0, 0 };
const s16 D_800FE6E4_HotRopeJump[8] = { 80, 30, 0x7800, 0x7800, 30, 0, 0, 0 };

/* Rope flame. */
const Vtx_t D_800FE6F4_HotRopeJump[9] = {
    { { -70, 150, 0 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } },
    { { 70, 150, 0 }, 0, { 0x800, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } },
    { { 50, -50, 0 }, 0, { 0x800, 0x1000 }, { 0xFF, 0xFF, 0xFF, 0x10 } },
    { { -50, -50, 0 }, 0, { 0, 0x1000 }, { 0xFF, 0xFF, 0xFF, 0x10 } },
    { { 0, 0, 0 }, 0, { 0x400, 0xC00 }, { 0xFF, 0xFF, 0xFF, 0xF0 } },
    { { -50, 25, 25 }, 0, { 0, 0 }, { 0x00, 0x00, 0x00, 0xFF } },
    { { 50, 25, 25 }, 0, { 0x1000, 0 }, { 0x00, 0x00, 0x00, 0xFF } },
    { { 50, -25, 25 }, 0, { 0x1000, 0x800 }, { 0x00, 0x00, 0x00, 0xFF } },
    { { -50, -25, 25 }, 0, { 0, 0x800 }, { 0x00, 0x00, 0x00, 0xFF } },
};

HRJSeq2 D_800FE784_HotRopeJump HRJ_RODATA_RW = { 0, 0 };
const s16 D_800FE788_HotRopeJump[4] = { 90, 128, 128, 0 };
// NON_MATCHING: retail keeps &home in a register and stores speed at -8 from it (masked 6)
#ifdef NON_MATCHING
void func_800F6C9C_HotRopeJump(omObjData* obj) {
    HRJPlayer* p;
    Vec* v;

    func_800F6EEC_HotRopeJump(obj, 0);
    func_800F8C68_HotRopeJump(obj, &D_80100328_HotRopeJump[0]);
    func_800093FC(obj, -800.0f, 0.0f, -800.0f);
    p = &D_80100328_HotRopeJump[0];
    v = &p->home;
    v->x = 0.0f;
    v->y = 0.0f;
    v->z = D_800FE4AC_HotRopeJump[D_800FE464_HotRopeJump[0]] * 100.0;
    p->speed = 20;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HotRopeJump/207040", func_800F6C9C_HotRopeJump);
#endif

// NON_MATCHING: retail keeps &home in a register and stores speed at -8 from it (masked 6)
#ifdef NON_MATCHING
void func_800F6D30_HotRopeJump(omObjData* obj) {
    HRJPlayer* p;
    Vec* v;

    func_800F6EEC_HotRopeJump(obj, 1);
    func_800F8C68_HotRopeJump(obj, &D_80100328_HotRopeJump[1]);
    func_800093FC(obj, -800.0f, 0.0f, -800.0f);
    p = &D_80100328_HotRopeJump[1];
    v = &p->home;
    v->x = 0.0f;
    v->y = 0.0f;
    v->z = D_800FE4AC_HotRopeJump[D_800FE464_HotRopeJump[1]] * 100.0;
    p->speed = 20;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HotRopeJump/207040", func_800F6D30_HotRopeJump);
#endif

// NON_MATCHING: retail keeps &home in a register and stores speed at -8 from it (masked 6)
#ifdef NON_MATCHING
void func_800F6DC4_HotRopeJump(omObjData* obj) {
    HRJPlayer* p;
    Vec* v;

    func_800F6EEC_HotRopeJump(obj, 2);
    func_800F8C68_HotRopeJump(obj, &D_80100328_HotRopeJump[2]);
    func_800093FC(obj, -800.0f, 0.0f, -800.0f);
    p = &D_80100328_HotRopeJump[2];
    v = &p->home;
    v->x = 0.0f;
    v->y = 0.0f;
    v->z = D_800FE4AC_HotRopeJump[D_800FE464_HotRopeJump[2]] * 100.0;
    p->speed = 20;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HotRopeJump/207040", func_800F6DC4_HotRopeJump);
#endif

// NON_MATCHING: retail keeps &home in a register and stores speed at -8 from it (masked 6)
#ifdef NON_MATCHING
void func_800F6E58_HotRopeJump(omObjData* obj) {
    HRJPlayer* p;
    Vec* v;

    func_800F6EEC_HotRopeJump(obj, 3);
    func_800F8C68_HotRopeJump(obj, &D_80100328_HotRopeJump[3]);
    func_800093FC(obj, -800.0f, 0.0f, -800.0f);
    p = &D_80100328_HotRopeJump[3];
    v = &p->home;
    v->x = 0.0f;
    v->y = 0.0f;
    v->z = D_800FE4AC_HotRopeJump[D_800FE464_HotRopeJump[3]] * 100.0;
    p->speed = 20;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HotRopeJump/207040", func_800F6E58_HotRopeJump);
#endif

// NON_MATCHING: register allocation of the motion pointer (masked 0)
#ifdef NON_MATCHING
void func_800F6EEC_HotRopeJump(omObjData* obj, s32 player) {
    s32 a[5] = { 0x0F, 0x38, 0x39, 0x3A, 0x3B };
    s32 b[5] = { 0x10, 0x3C, 0x3D, 0x3E, 0x3F };
    s32 dir;
    s32 file;
    s32* m;
    HRJPlayerWork* w;

    dir = D_800C59AC[GwPlayer[player].character].unk_00;
    file = D_800C59AC[GwPlayer[player].character].unk_04;
    func_80009618(0);
    func_8000979C(obj, dir, file, player, 0xD9, 0x2D9);
    obj->func_ptr = func_800F7F14_HotRopeJump;
    w = obj->unk_50;
    w->unk_DC = NULL;
    w->unk_58 = player;
    if (GwPlayer[player].flags & 1) {
        D_800FE460_HotRopeJump |= 1 << player;
    }
    obj->model[3] = LoadFormFile(0x19, 0x68D);
    obj->model[4] = LoadFormFile(0x1A, 0x68D);
    func_8001874C(obj, 0, dir, 1, 0);
    func_8001874C(obj, 1, dir | 1, 1, 0);
    func_8001874C(obj, 2, dir | 3, 1, 0);
    func_8001874C(obj, 6, dir | 5, 1, 0x13);
    m = (rand8() & 1) + a;
    func_8001874C(obj, 0xD, dir | m[0], 1, 0x78);
    func_8001874C(obj, 0xE, dir | m[6], 1, 0x78);
    func_8001874C(obj, 0x11, dir | 0x18, 0, 0);
    func_8001874C(obj, 0x15, dir | 0x62, 0, 0);
    func_8001874C(obj, 0x1E, dir | 0x63, 0, 0);
    func_8001874C(obj, 0x1F, dir | 0x64, 0, 0);
    func_8001874C(obj, 0x21, dir | 0x68, 2, 0);
    func_8001874C(obj, 0x22, dir | 0x69, 2, 0);
    func_8001874C(obj, 0x23, dir | 0x49, 1, 0);
    func_800093FC(obj, 0.0f, 0.0f, 0.0f);
    omSetTra(obj, 0.0f, 0.0f, 0.0f);
    func_800184BC(obj, 2);
    func_80017DB0(obj);
    func_800090C4(obj, 0, 2);
}
#else
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_2E_HotRopeJump/207040", D_800FE7B0_HotRopeJump);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_2E_HotRopeJump/207040", D_800FE7C4_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HotRopeJump/207040", func_800F6EEC_HotRopeJump);
#endif



/* The game's control object: intro, the rope's speed-ups and jump count, the result and coins,
   and the camera follow. */
// NON_MATCHING: register allocation and block layout
#ifdef NON_MATCHING
void func_800F7210_HotRopeJump(omObjData* obj) {
    Vec v;
    Vec out;
    f32 a;
    f32 lim;
    f32 d;
    s32 i;
    s32 n;

    D_80100324_HotRopeJump = (D_80100324_HotRopeJump + 1) % 3;
    if (D_800F5144 == 1) {
        D_801004A8_HotRopeJump = -1;
        func_80060198();
        obj->func_ptr = func_800F6C50_HotRopeJump;
    }
    switch (D_800FE454_HotRopeJump) {
        case 0:
            if (func_80072718() == 0) {
                if (D_800FE4C0_HotRopeJump != 0 && D_800FE4C0_HotRopeJump >= 60) {
                    D_800FE454_HotRopeJump = 1;
                    D_800FE4C0_HotRopeJump = 0;
                }
                D_800FE4C0_HotRopeJump++;
            }
            break;
        case 1:
            D_800FE4C0_HotRopeJump++;
            if (D_800FE458_HotRopeJump != 0) {
                D_800FE454_HotRopeJump = 2;
                D_800FE458_HotRopeJump = 0;
                D_800FE4C0_HotRopeJump = 0;
            }
            break;
        case 2:
            if (D_800FE4C0_HotRopeJump == 0) {
                GMesCreate(0);
                func_80060128(D_800FE488_HotRopeJump != 0 ? 0x1C : 0x22);
                D_800FE4C0_HotRopeJump++;
            } else if (GMesStatAllGet() == 0) {
                D_800FE454_HotRopeJump = 3;
                D_800FE4C0_HotRopeJump = 30;
                func_800FE38C_HotRopeJump();
                D_801004C0_HotRopeJump = D_801004BC_HotRopeJump = 360.0 / (D_800FE4CC_HotRopeJump * 0.5) * 0.1;
                func_800FE3A8_HotRopeJump(D_801004C0_HotRopeJump);
            }
            break;
        case 3:
            a = D_80100854_HotRopeJump[6].angle;
            if (a >= 270.0f) {
                if (D_800FE4D4_HotRopeJump == 0.0f) {
                    D_800FE4C8_HotRopeJump++;
                }
                if (D_800FE4C8_HotRopeJump == D_800FE4C8_HotRopeJump / 5 * 5 && D_800FE4C8_HotRopeJump != 0) {
                    if (D_800FE4D4_HotRopeJump != 0.0f) {
                        func_800FE3A8_HotRopeJump((D_801004C0_HotRopeJump - D_801004BC_HotRopeJump) *
                                                      func_800AEFD0(360.0f - a) +
                                                  D_801004BC_HotRopeJump);
                    } else if (D_800FE488_HotRopeJump != 0 && D_800FE4C8_HotRopeJump == 20) {
                        D_800FE4CC_HotRopeJump = 150;
                        D_801004C0_HotRopeJump = 0.48f;
                    } else if (D_800FE4CC_HotRopeJump >= 61) {
                        D_800FE4CC_HotRopeJump -= 30;
                        D_801004C0_HotRopeJump = 360.0 / (D_800FE4CC_HotRopeJump * 0.5) * 0.1;
                    }
                }
                D_800FE4D4_HotRopeJump = 1.0f;
            } else if (a < D_800FE4D0_HotRopeJump) {
                D_801004BC_HotRopeJump = D_801004C0_HotRopeJump;
                func_800FE3A8_HotRopeJump(D_801004C0_HotRopeJump);
                D_800FE4D4_HotRopeJump = 0.0f;
                if (D_800FE458_HotRopeJump == 0 && D_800FE4C8_HotRopeJump < 100) {
                    func_800671DC((s16)D_801004B0_HotRopeJump, 0, D_800FE4C8_HotRopeJump / 10);
                    func_800671DC((s16)D_801004B0_HotRopeJump, 1, D_800FE4C8_HotRopeJump % 10);
                }
                if (D_800FE4C8_HotRopeJump >= D_800FE450_HotRopeJump || D_800FE458_HotRopeJump != 0) {
                    n = 2;
                    if (D_800FE45C_HotRopeJump != -1 && D_800FE488_HotRopeJump == 0) {
                        n = 14;
                    }
                    GMesCreate(n);
                    func_800601D4(90);
                    D_800FE454_HotRopeJump = D_800FE488_HotRopeJump != 0 ? 10 : 9;
                    func_800FE39C_HotRopeJump();
                    D_800FE4C0_HotRopeJump = 30;
                    if (D_800FE4BC_HotRopeJump != NULL) {
                        func_800FA734_HotRopeJump(800.0f, D_800FE4BC_HotRopeJump->trans.x, 200.0f,
                                                  D_800FE4BC_HotRopeJump->trans.z, -30.0f, -50.0f, 0.0f, 30);
                    }
                }
            }
            D_800FE4D0_HotRopeJump = a;
            if (D_800FE45C_HotRopeJump != -1) {
                D_800FE4BC_HotRopeJump = D_800F3FB0[D_800FE45C_HotRopeJump];
            }
            break;
        case 9:
            if (D_800FE4BC_HotRopeJump != NULL && D_800FE4BC_HotRopeJump->trans.y <= 180.0) {
                func_800FA734_HotRopeJump(1800.0f, 0.0f, 100.0f, 0.0f, -30.0f, -90.0f, 0.0f, 45);
                D_800FE4BC_HotRopeJump = NULL;
            }
            func_800FA7B8_HotRopeJump(D_800FE484_HotRopeJump, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
            D_800FE484_HotRopeJump = 0.0f;
            if (D_800FE4D8_HotRopeJump == 0) {
                if (!(GMesStatAllGet() & 2)) {
                    break;
                }
                if (D_800FE45C_HotRopeJump == -1) {
                    func_80060128(0x33);
                    for (i = 0; i < 4; i++) {
                        GwPlayer[i].coins_mg += 10;
                    }
                } else {
                    func_80060128(0x34);
                }
                for (i = 0; i < 4; i++) {
                    func_800674BC((s16)D_801004B0_HotRopeJump, i, 0x8000);
                }
                func_800674BC((s16)D_801004B4_HotRopeJump, 0, 0x8000);
            } else {
                if (D_800FE45C_HotRopeJump != -1) {
                    if (D_800FE4D8_HotRopeJump == 18) {
                        GMesCreate(5, GwPlayer[D_800FE45C_HotRopeJump].character);
                        func_80060468(0x449, GwPlayer[D_800FE45C_HotRopeJump].character + 1);
                        n = GwPlayer[D_800FE45C_HotRopeJump].coins;
                        if (n >= 15) {
                            n = 15;
                        }
                        for (i = 0; i < 4; i++) {
                            if (i == D_800FE45C_HotRopeJump) {
                                GwPlayer[i].coins_mg -= n;
                            } else {
                                GwPlayer[i].coins_mg += 5;
                            }
                        }
                    } else if (D_800FE4D8_HotRopeJump >= 90) {
                        D_800FE454_HotRopeJump = 11;
                    }
                } else if (D_800FE4D8_HotRopeJump >= 95) {
                    D_800FE454_HotRopeJump = 11;
                }
                for (i = 0; i < 4; i++) {
                    if (ContBtnTrg[GwPlayer[i].port] & 0x9000) {
                        D_800FE4DC_HotRopeJump = 1;
                    }
                }
                if (D_800FE4DC_HotRopeJump != 0 && D_800FE4D8_HotRopeJump >= 60) {
                    func_80011A30(90);
                    D_800FE454_HotRopeJump = 11;
                }
            }
            D_800FE4D8_HotRopeJump++;
            break;
        case 10:
            if (D_800FE4BC_HotRopeJump != NULL) {
                if (D_800FE4BC_HotRopeJump->trans.y <= 180.0) {
                    func_800FA734_HotRopeJump(1800.0f, 0.0f, 100.0f, 0.0f, -30.0f, -90.0f, 0.0f, 45);
                    D_800FE4BC_HotRopeJump = NULL;
                }
                func_800FA7B8_HotRopeJump(D_800FE484_HotRopeJump, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
                D_800FE484_HotRopeJump = 0.0f;
            }
            if (D_800FE4D8_HotRopeJump == 0) {
                if (D_800FE45C_HotRopeJump == -1) {
                    for (i = 0; i < 4; i++) {
                        GwPlayer[i].coins_mg += 10;
                    }
                } else {
                    n = GwPlayer[D_800FE45C_HotRopeJump].coins;
                    if (n >= 15) {
                        n = 15;
                    }
                    for (i = 0; i < 4; i++) {
                        if (i == D_800FE45C_HotRopeJump) {
                            GwPlayer[i].coins_mg -= n;
                        } else {
                            GwPlayer[i].coins_mg += 5;
                        }
                    }
                }
                for (i = 0; i < 4; i++) {
                    func_800674BC((s16)D_801004B0_HotRopeJump, i, 0x8000);
                }
                func_800674BC((s16)D_801004B4_HotRopeJump, 0, 0x8000);
            } else if (D_800FE4D8_HotRopeJump >= 60) {
                D_800FE454_HotRopeJump = 11;
            }
            D_800FE4D8_HotRopeJump++;
            break;
        case 11:
            if (D_800FE488_HotRopeJump == 0) {
                func_800FA7B8_HotRopeJump(D_800FE484_HotRopeJump, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
            }
            D_800FE484_HotRopeJump = 0.0f;
            D_801004A8_HotRopeJump = -1;
            func_800601D4(90);
            if (D_800FE488_HotRopeJump != 0) {
                func_80060398(40);
            }
            func_800726AC(0, 20);
            obj->func_ptr = func_800F6C50_HotRopeJump;
            break;
    }
    if (D_800FE4BC_HotRopeJump != NULL) {
        v.x = D_800FE4BC_HotRopeJump->trans.x;
        if (D_800FE4BC_HotRopeJump->trans.y > 180.0) {
            v.y = D_800FE4BC_HotRopeJump->trans.y + 180.0;
        } else {
            v.y = 180.0f;
        }
        v.z = D_800FE4BC_HotRopeJump->trans.z;
        func_800FAB34_HotRopeJump(0, &v, &out);
        lim = 48.0f;
        if (out.y < lim || (lim = 184.0f, out.y > lim)) {
            d = -(out.y - lim) / 24.0f;
            func_800FA7B8_HotRopeJump(0.0f, 0.0f, d * 10.0f, 0.0f, d * 1.25, 0.0f, 0.0f);
        }
        if (out.x < 56.0f) {
            d = out.x - 56.0f;
        } else if (out.x > 272.0f) {
            d = out.x - 264.0f;
        } else {
            goto end;
        }
        func_800FA7B8_HotRopeJump(0.0f, 0.0f, 0.0f, d / 28.0f, 0.0f, 0.0f, 0.0f);
    }
end:
    func_800FA2F4_HotRopeJump();
    if (D_800FE454_HotRopeJump >= 3) {
        func_800FA9DC_HotRopeJump(obj);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HotRopeJump/207040", func_800F7210_HotRopeJump);
#endif

/* A player: the intro walk to its place, jumping (A) while the rope turns, getting hit, and the
   win/lose poses. */
// NON_MATCHING: register allocation and block layout
#ifdef NON_MATCHING
void func_800F7F14_HotRopeJump(omObjData* obj) {
    Vec pos;
    Vec v;
    Vec out;
    HRJPlayerWork* w;
    HRJPlayer* p;
    u16 trg;
    u16 btn;
    u16 cnt;
    u8 port;
    s32 motEnd;
    s32 r;
    f32 a;
    f32 x;
    f32 y;
    f32 z;
    f32 dy;
    f32 sc;

    trg = 0;
    w = obj->unk_50;
    btn = 0;
    p = func_800F8C88_HotRopeJump(obj);
    a = obj->rot.y;
    port = w->unk_56;
    cnt = D_800FE4E0_HotRopeJump[w->unk_58];
    motEnd = func_80017A60(obj);
    pos.x = x = obj->trans.x;
    pos.y = y = obj->trans.y;
    pos.z = z = obj->trans.z;
    if (!(GwPlayer[w->unk_58].flags & 1) && D_800FE454_HotRopeJump == 3) {
        trg = ContBtnTrg[(s8)port];
        btn = ContBtn[(s8)port];
    }
    switch (D_800FE454_HotRopeJump) {
        case 0:
            p->intro = p->unk_42 = p->unk_44 = p->unk_46 = 0;
            p->unk_00 = 0;
            p->state = 0x100;
            a = func_800B0CD8(p->home.x - obj->trans.x, p->home.z - obj->trans.z);
            break;
        case 1:
            switch (p->intro) {
                case 0:
                    if ((x - p->home.x) * (x - p->home.x) + (z - p->home.z) * (z - p->home.z) <= 22500.0) {
                        p->speed = 10;
                        p->intro = 1;
                        func_800184BC(obj, 0x11);
                        p->unk_34 = func_800AEAC0(a) * 0.7 * 100.0;
                        p->unk_3C = func_800AEFD0(a) * 0.7 * 100.0;
                        func_80060618(0x120, w->unk_58);
                    }
                    break;
                case 1:
                    func_80017C0C(obj, 4, x + p->unk_34, y, z + p->unk_3C, 0.0f, a + 180.0f);
                    if ((x - p->home.x) * (x - p->home.x) + (z - p->home.z) * (z - p->home.z) <= 100.0) {
                        p->speed = 0;
                        p->intro = 2;
                        x = p->home.x;
                        y = p->home.y;
                        z = p->home.z;
                        p->state = 1;
                        func_800184BC(obj, 0);
                    }
                    break;
                case 2:
                    func_80017B4C((u8)obj->model[4]);
                    if (fabs(a) <= 2.0) {
                        D_800FE4E8_HotRopeJump |= 1 << w->unk_58;
                        a = 0.0f;
                    } else {
                        a = a - 2.0;
                    }
                    break;
            }
            x += func_800AEAC0(a) * p->speed;
            z += func_800AEFD0(a) * p->speed;
            if (D_800FE4E8_HotRopeJump == 0xF) {
                D_800FE458_HotRopeJump = 1;
            }
            break;
        case 3:
            r = func_800F8A14_HotRopeJump(obj);
            if (r == 1 && D_800FE45C_HotRopeJump == -1) {
                w->unk_38 = 100.0f;
                p->unk_00 = 1;
                p->unk_42 = 1;
                p->hit.x = x;
                p->hit.y = 0;
                p->hit.z = z;
                p->state = 8;
                func_800184BC(obj, 0x23);
                D_800FE45C_HotRopeJump = w->unk_58;
                PlaySound(0x335);
                D_800FE458_HotRopeJump = 1;
                func_80060F04(w->unk_58, 30, 0, 30);
                func_80060468(0x45E, GwPlayer[w->unk_58].character + 1);
                break;
            }
            if (r != 0 && (GwPlayer[w->unk_58].flags & 1)) {
                if (D_800FE460_HotRopeJump != 0xF || (rand8() & 3)) {
                    trg |= 0x8000;
                }
                btn |= 0x8000;
            }
            if (btn & 0x8000) {
                if ((trg & 0x8000) && (p->state & 1)) {
                    if (func_800184BC(obj, 6) == 1) {
                        w->unk_38 = -D_800B8964 * 0.55;
                        p->state = 2;
                        func_80060618(0x127, w->unk_58);
                        cnt++;
                    }
                } else if (cnt != 0) {
                    if (cnt++ < 8) {
                        w->unk_38 = w->unk_38 - D_800B8964 * 0.075;
                    } else {
                        cnt = 0;
                    }
                }
            } else {
                cnt &= -(cnt == 0);
            }
            D_800FE4E0_HotRopeJump[w->unk_58] = cnt;
            break;
        case 9:
        case 11:
            if ((GMesStatAllGet() & 2) && p->unk_00 == 0 && (p->state & 1)) {
                if (D_800FE45C_HotRopeJump == -1) {
                    a = CRot.y;
                    w->unk_3C = a;
                    func_800184BC(obj, 0xD);
                    p->state = 0x10;
                } else {
                    func_800184BC(obj, 0xE);
                    p->state = 0x20;
                }
            }
            v.x = x;
            v.y = 0.0f;
            v.z = z;
            func_800FADDC_HotRopeJump(0, &v, &out, 0.7f, 0.7f);
            if (D_800FE484_HotRopeJump == 0.0 || D_800FE484_HotRopeJump < out.z) {
                D_800FE484_HotRopeJump = out.z;
            }
            if (D_800FE484_HotRopeJump >= 25.0) {
                D_800FE484_HotRopeJump = 25.0f;
            } else if (D_800FE484_HotRopeJump <= -25.0) {
                D_800FE484_HotRopeJump = -25.0f;
            }
            break;
    }
    switch (p->state & 0xF) {
        case 2:
            dy = 35.0f;
            if (w->unk_38 >= 0.0f) {
                dy = -35.0f;
            }
            y += w->unk_38 * w->unk_38 * dy;
            w->unk_38 += D_800B8968;
            if (y <= 0.0) {
                w->unk_38 = 1000.0f;
                func_800184BC(obj, 0x15);
                y = 0.0f;
                p->state = 4;
            }
            break;
        case 4:
            if (motEnd & 1) {
                func_800184BC(obj, 0);
                p->state = 1;
            }
            break;
        case 8:
            y += w->unk_38;
            w->unk_38 = w->unk_38 - 5.0;
            if (p->state & 0x20) {
                x = func_800AEAC0(p->unk_42 * 1.5) * 2.5 * 100.0;
                z = func_800AEAC0(p->unk_42 * 3) * 2.5 * 100.0 + p->hit.z;
                a = func_800B0CD8(x - pos.x, z - pos.z);
                w->unk_3C = a;
                p->unk_42 = (s16)(p->unk_42 + 1) % 240;
            }
            if (y <= 0.0) {
                y = 0.0f;
                w->unk_38 = 40.0f;
                p->state |= 0x20;
                func_80060540(0x33B, 3);
            }
            if (p->unk_42 & 1) {
                func_800F8968_HotRopeJump(x, y, z);
            }
            break;
    }
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = z;
    obj->rot.y = a;
    sc = 1.0 - y / 2000.0;
    func_80025798(obj->model[1], x, 0.0f, z);
    func_80025830(obj->model[1], sc, sc, sc);
    func_80017DB0(obj);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HotRopeJump/207040", func_800F7F14_HotRopeJump);
#endif

void func_800F8968_HotRopeJump(f32 x, f32 y, f32 z) {
    s16 id;

    id = func_800F8E74_HotRopeJump((s16)D_801004AC_HotRopeJump, 0x28);
    func_800F8F2C_HotRopeJump(id, x, y, z);
    func_800F8F5C_HotRopeJump(id, 3.0f, 3.0f, 1.0f);
    func_800F8FBC_HotRopeJump(id, 0xC0, 0xC0, 0xC0, 0xFF);
    func_800F8F04_HotRopeJump(id, 4.0f);
}

// NON_MATCHING: register allocation of the hit point (t/dy swap f4/f6) and ret in a2 not v0 (masked 7, 2 instructions long); tried explicit returns, declaration order
#ifdef NON_MATCHING
s32 func_800F8A14_HotRopeJump(omObjData* obj) {
    HRJSeg* seg;
    f32 t;
    f32 dx;
    f32 dy;
    f32 dz;
    s32 i;
    s32 ret;

    seg = D_80100854_HotRopeJump;
    for (i = 0; i < 12; i++, seg++) {
        t = -((seg->pos.x - obj->trans.x) * seg->dir.x + seg->dir.y * (seg->pos.y - (obj->trans.y + 50.0)) +
              (seg->pos.z - obj->trans.z) * seg->dir.z) /
            (seg->dir.x * seg->dir.x + seg->dir.y * seg->dir.y + seg->dir.z * seg->dir.z);
        if (t < 1.0 && t >= 0.0) {
            break;
        }
    }
    ret = 0;
    if (i != 12) {
        dx = t * seg->dir.x + seg->pos.x;
        dy = t * seg->dir.y + seg->pos.y;
        dz = t * seg->dir.z + seg->pos.z;
        dx -= obj->trans.x;
        dy -= obj->trans.y + 50.0;
        dz -= obj->trans.z;
        if (dx * dx + dy * dy + dz * dz <= 2500.0) {
            ret = 1;
        } else if (seg->angle >= 225.0 - D_801004BC_HotRopeJump * 7.5 && seg->angle <= 270.0f) {
            ret = 2;
        }
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HotRopeJump/207040", func_800F8A14_HotRopeJump);
#endif

void func_800F8C08_HotRopeJump(void) {
    func_800FB328_HotRopeJump();
    D_800B8980 = D_80100310_HotRopeJump;
    D_800B8964 = D_80100314_HotRopeJump;
    D_800B8968 = D_80100318_HotRopeJump;
    D_800B8994 = D_8010031C_HotRopeJump;
    func_800FA60C_HotRopeJump();
}

/* Keeps the player's HRJPlayer in omObjData::work as a big-endian word; on the host the work bytes
   cannot hold a pointer, so they hold its index (only D_80100328_HotRopeJump entries are stored). */
void func_800F8C68_HotRopeJump(omObjData* obj, HRJPlayer* p) {
    obj->work[0] = (u32)p >> 24;
    obj->work[1] = (u32)p >> 16;
    obj->work[2] = (u32)p >> 8;
    obj->work[3] = (u32)p;
}

HRJPlayer* func_800F8C88_HotRopeJump(omObjData* obj) {
    return (HRJPlayer*)((obj->work[0] << 24) | (obj->work[1] << 16) | (obj->work[2] << 8) | obj->work[3]);
}

void func_800F8CB4_HotRopeJump(u8 count) {
    HRJFx* fx;
    s16 i;

    D_801004C4_HotRopeJump = count;
    for (i = 0; i < 3; i++) {
        D_801004E4_HotRopeJump[i] = HuMemDirectMalloc(D_801004C4_HotRopeJump * (8 * sizeof(Vtx)));
        D_801004D8_HotRopeJump[i] = HuMemDirectMalloc(D_801004C4_HotRopeJump * (32 * sizeof(Gfx)));
        D_801004C8_HotRopeJump[i] = HuMemDirectMalloc(D_801004C4_HotRopeJump * (20 * sizeof(Gfx)));
    }
    D_801004D4_HotRopeJump = func_80024198(0x19, D_801004C8_HotRopeJump[0], 4);
    D_80103298 = HuMemDirectMalloc(D_801004C4_HotRopeJump * sizeof(HRJFx));
    for (i = 0; i < D_801004C4_HotRopeJump; i++) {
        fx = &D_80103298[i];
        fx->dl = (Gfx*)-1;
        fx->unk_08 = 0;
        fx->flags = 0;
        fx->sprite = 0;
        fx->a = fx->r = fx->g = fx->b = 0xFF;
        fx->timer = 0;
        fx->frame = 0;
        fx->unk_0E = 0;
        fx->speed = 1.0f;
        fx->pos.x = fx->pos.y = fx->pos.z = 0.0f;
        fx->scale.x = fx->scale.y = 0.0f;
    }
}

s16 func_800F8E74_HotRopeJump(s16 sprite, u8 flags) {
    HRJFx* fx;
    s16 i;

    for (i = 0; i < D_801004C4_HotRopeJump; i++) {
        if (D_80103298[i].dl == (Gfx*)-1) {
            break;
        }
    }
    D_80103298[i].dl = NULL;
    D_80103298[i].sprite = sprite;
    D_80103298[i].flags = flags;
    return i;
}

void func_800F8F04_HotRopeJump(s16 id, f32 speed) {
    HRJFx* fx = &D_80103298[id];

    fx->speed = speed;
}

void func_800F8F2C_HotRopeJump(s16 id, f32 x, f32 y, f32 z) {
    HRJFx* fx = &D_80103298[id];

    fx->pos.x = x;
    fx->pos.y = y;
    fx->pos.z = z;
}

void func_800F8F5C_HotRopeJump(s16 id, f32 x, f32 y, f32 z) {
    HRJFx* fx = &D_80103298[id];

    fx->scale.x = x;
    fx->scale.y = y;
    fx->scale.z = z;
}

void func_800F8F8C_HotRopeJump(s16 id, u8 flags) {
    HRJFx* fx = &D_80103298[id];

    fx->flags |= flags;
}

void func_800F8FBC_HotRopeJump(s16 id, u8 r, u8 g, u8 b, s32 a) {
    HRJFx* fx = &D_80103298[id];

    fx->r = r;
    fx->g = g;
    fx->b = b;
    fx->a = a;
}

void func_800F8FF4_HotRopeJump(s16 id) {
    HRJFx* fx = &D_80103298[id];

    fx->dl = (Gfx*)-1;
    fx->unk_04 = NULL;
    fx->unk_08 = 0;
    fx->flags = 0;
    fx->sprite = 0;
    fx->a = fx->r = fx->g = fx->b = 0xFF;
    fx->timer = 0;
    fx->frame = 0;
    fx->unk_0E = 0;
    fx->pos.x = fx->pos.y = fx->pos.z = 0.0f;
    fx->scale.x = fx->scale.y = fx->scale.z = 0.0f;
    fx->speed = 1.0f;
}

#define HRJ_TEX_MASK(x) \
    ((x) < 3 ? 1 : (x) < 5 ? 2 : (x) < 9 ? 3 : (x) < 17 ? 4 : (x) < 33 ? 5 : (x) < 65 ? 6 : (x) < 129 ? 7 : (x) < 257 ? 8 : 9)

/* Builds this frame's display list and quad of every visible billboard, then advances its
   animation. */
// NON_MATCHING: scheduling and block layout of the animation tail
#ifdef NON_MATCHING
void func_800F9080_HotRopeJump(void) {
    Vtx* v;
    Gfx* gfx;
    HRJFx* fx;
    unk65770Anim* anim;
    unk65770AnimC* frame;
    u16 w;
    u16 h;
    s16 x;
    s16 y;
    s16 nh;
    s16 len;
    u16 count;
    s16 k;
    u16 i;

    v = D_801004E4_HotRopeJump[D_80100324_HotRopeJump];
    gfx = D_801004D8_HotRopeJump[D_80100324_HotRopeJump];
    for (i = 0; (s16)i < D_801004C4_HotRopeJump; i++) {
        fx = &D_80103298[(s16)i];
        if (fx->dl == (Gfx*)-1 || fx->unk_08 != 0) {
            continue;
        }
        if (fx->flags & 0x10) {
            fx->dl = NULL;
            continue;
        }
        fx->dl = gfx;
        gDPPipeSync(gfx++);
        anim = D_800EC700[fx->sprite];
        if (anim->unk18 & 0x8000) {
            gDPSetCombine(gfx++, 0xFF97FF, 0xFF2DFEFF);
            gDPSetRenderMode(gfx++, 0x5049D8, 0);
            gDPSetBlendColor(gfx++, 0, 0, 0, 1);
            gDPSetPrimColor(gfx++, 0, 0, fx->r, fx->g, fx->b, fx->a);
        } else if (fx->a == 0xFF) {
            gDPSetRenderMode(gfx++, 0x553078, 0);
            gDPSetCombine(gfx++, 0xFFFFFF, 0xFFFCF279);
        } else {
            gDPSetBlendColor(gfx++, 0, 0, 0, 0);
            gDPSetPrimColor(gfx++, 0, 0, fx->r, fx->g, fx->b, fx->a);
            gDPSetRenderMode(gfx++, 0x5049D8, 0);
            gDPSetCombine(gfx++, 0x143228, 0xFF65FEFF);
        }
        gDPSetTextureFilter(gfx++, D_800FE4EC_HotRopeJump[(fx->flags & 0x18) >> 3]);
        frame = &anim->unk0[fx->frame];
        w = frame->unk4;
        h = frame->unk6;
        if (anim->unk18 & 0x8000) {
            gDPSetTextureLUT(gfx++, G_TT_NONE);
            gDPLoadTextureBlock_4b(gfx++, frame->unk0, G_IM_FMT_I, (s16)w, (s16)h, 0, G_TX_CLAMP, G_TX_CLAMP,
                                   HRJ_TEX_MASK((s16)w), HRJ_TEX_MASK((s16)h), G_TX_NOLOD, G_TX_NOLOD);
        } else {
            gDPSetTextureLUT(gfx++, G_TT_RGBA16);
            if (anim->unk18 < 0x11) {
                gDPLoadTLUT_pal16(gfx++, 0, anim->unkC);
                gDPLoadTextureBlock_4b(gfx++, frame->unk0, G_IM_FMT_CI, (s16)w, (s16)h, 0, G_TX_CLAMP, G_TX_CLAMP,
                                       HRJ_TEX_MASK((s16)w), HRJ_TEX_MASK((s16)h), G_TX_NOLOD, G_TX_NOLOD);
            } else {
                gDPLoadTLUT_pal256(gfx++, anim->unkC);
                gDPLoadTextureBlock(gfx++, frame->unk0, G_IM_FMT_CI, G_IM_SIZ_8b, (s16)w, (s16)h, 0, G_TX_CLAMP,
                                    G_TX_CLAMP, HRJ_TEX_MASK((s16)w), HRJ_TEX_MASK((s16)h), G_TX_NOLOD, G_TX_NOLOD);
            }
        }
        gSPVertex(gfx++, osVirtualToPhysical(v), 4, 0);
        gSP1Quadrangle(gfx++, 0, 1, 2, 3, 0);
        nh = -h;
        x = -frame->unk8;
        y = frame->unkA;
        v->v.ob[0] = x;
        v->v.ob[1] = y;
        v->v.ob[2] = 0;
        v->n.n[0] = v->n.n[1] = v->n.n[2] = -1;
        v->v.tc[0] = 0;
        v->v.tc[1] = 0;
        v->n.a = 0xFF;
        v++;
        v->v.ob[0] = x;
        v->v.ob[1] = nh + y;
        v->v.ob[2] = 0;
        v->n.n[0] = v->n.n[1] = v->n.n[2] = -1;
        v->v.tc[0] = 0;
        v->v.tc[1] = (-nh - 1) << 5;
        v->n.a = 0xFF;
        v++;
        v->v.ob[0] = (s16)w + x;
        v->v.ob[1] = nh + y;
        v->v.ob[2] = 0;
        v->n.n[0] = v->n.n[1] = v->n.n[2] = -1;
        v->v.tc[0] = ((s16)w - 1) << 5;
        v->v.tc[1] = (-nh - 1) << 5;
        v->n.a = 0xFF;
        v++;
        v->v.ob[0] = (s16)w + x;
        v->v.ob[1] = y;
        v->v.ob[2] = 0;
        v->n.n[0] = v->n.n[1] = v->n.n[2] = -1;
        v->v.tc[0] = ((s16)w - 1) << 5;
        v->v.tc[1] = 0;
        v->n.a = 0xFF;
        v++;
        gDPSetTextureFilter(gfx++, D_800FE4EC_HotRopeJump[(u8)D_800F329C]);
        gSPEndDisplayList(gfx++);
        if (fx->flags & 1) {
            continue;
        }
        if (anim->unk4 != NULL) {
            len = anim->unk4[0]->unk4[fx->frame].unk2;
            count = anim->unk4[0]->unk0;
        } else {
            len = 8;
            count = anim->unk10;
        }
        for (k = 0; k < 2; k++) {
            fx->timer += fx->speed;
            if (len < fx->timer) {
                fx->frame++;
                fx->timer -= len;
                if (fx->frame + 1 >= count) {
                    if (fx->flags & 4) {
                        func_800F8F8C_HotRopeJump(i, 0x10);
                        break;
                    }
                    if (fx->flags & 0x20) {
                        func_800F8FF4_HotRopeJump(i);
                        break;
                    }
                    if (((fx->flags >> 1) & 1) | (len != -1)) {
                        fx->frame--;
                        break;
                    }
                    fx->frame = 0;
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HotRopeJump/207040", func_800F9080_HotRopeJump);
#endif

/* Draws the billboards: each one's matrix (facing the camera unless unk_08) and display list, into
   the billboard model's list for this frame. */
// NON_MATCHING: scheduling of the view-matrix copy and the fx->unk_04 load (raw 10, masked 6); tried operand order, &D_800C3110->unk_138 + i * 2, i * 128
#ifdef NON_MATCHING
void func_800FA2F4_HotRopeJump(void) {
    Mtx view;
    Matrix4f m;
    Matrix4f m2;
    Matrix4f bb;
    Gfx* gfx;
    Mtx* mtx;
    HRJFx* fx;
    s32 i;

    func_800F9080_HotRopeJump();
    D_800F2B7C[D_801004D4_HotRopeJump].unk_6C->unk_00[0] = D_801004C8_HotRopeJump[D_80100324_HotRopeJump];
    gfx = D_801004C8_HotRopeJump[D_80100324_HotRopeJump];
    mtx = D_800FEB10_HotRopeJump[D_80100324_HotRopeJump];
    view = ((unk_Struct00*)((u8*)D_800C3110 + (D_800F3FA8 << 7)))->unk_138;
    gSPClearGeometryMode(gfx++, G_CULL_BACK | G_LIGHTING);
    gSPSetGeometryMode(gfx++, G_ZBUFFER);
    for (i = 0; i < D_801004C4_HotRopeJump; i++) {
        fx = &D_80103298[i];
        if (fx->dl != (Gfx*)-1 && !(fx->flags & 0x10)) {
            guMtxL2F(m, &view);
            MtxTranslate(m, fx->pos.x, fx->pos.y, fx->pos.z);
            MtxScale(m, fx->scale.x, fx->scale.y, fx->scale.z);
            if (fx->unk_08 == 0) {
                bb[0][0] = fx->scale.x;
                bb[1][1] = fx->scale.y;
                bb[2][2] = fx->scale.z;
                bb[3][3] = 1.0f;
                bb[0][1] = bb[0][2] = bb[0][3] = bb[1][0] = bb[1][2] = bb[1][3] = bb[2][0] = bb[2][1] = bb[2][3] =
                    bb[3][0] = bb[3][1] = bb[3][2] = 0.0f;
                MtxReset(m, m2);
                MtxMult(bb, m2, m);
            } else {
                gSPSegment(gfx++, 1, osVirtualToPhysical(fx->unk_04[D_800F37F0 + 2]));
            }
            func_800A0A20(m, mtx);
            gSPMatrix(gfx++, osVirtualToPhysical(mtx++), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(gfx++, fx->dl);
        }
    }
    gSPMatrix(gfx++, osVirtualToPhysical(&view), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPEndDisplayList(gfx++);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HotRopeJump/207040", func_800FA2F4_HotRopeJump);
#endif

void func_800FA60C_HotRopeJump(void) {
    s32 i;

    HuMemDirectFree(D_80103298);
    for (i = 0; i < 3; i++) {
        HuMemDirectFree(D_801004D8_HotRopeJump[i]);
        HuMemDirectFree(D_801004E4_HotRopeJump[i]);
        HuMemDirectFree(D_801004C8_HotRopeJump[i]);
    }
}

void func_800FA6AC_HotRopeJump(f32 zoom, f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz) {
    D_8010052A_HotRopeJump = 0;
    D_80100528_HotRopeJump = 0;
    CZoom = zoom;
    CRot.x = rx;
    CRot.y = ry;
    CRot.z = rz;
    Center.x = cx;
    Center.y = cy;
    Center.z = cz;
    D_80100520_HotRopeJump = zoom;
    D_80100508_HotRopeJump.x = rx;
    D_80100508_HotRopeJump.y = ry;
    D_80100508_HotRopeJump.z = rz;
    D_801004F0_HotRopeJump.x = cx;
    D_801004F0_HotRopeJump.y = cy;
    D_801004F0_HotRopeJump.z = cz;
}

void func_800FA734_HotRopeJump(f32 zoom, f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz, u16 frames) {
    D_80100524_HotRopeJump = zoom;
    D_801004FC_HotRopeJump.x = cx;
    D_801004FC_HotRopeJump.y = cy;
    D_801004FC_HotRopeJump.z = cz;
    D_80100514_HotRopeJump.x = rx;
    D_80100514_HotRopeJump.y = ry;
    D_80100514_HotRopeJump.z = rz;
    if (D_80100528_HotRopeJump != 0) {
        func_800FA978_HotRopeJump();
    }
    D_80100528_HotRopeJump = D_8010052A_HotRopeJump = frames;
}

void func_800FA7B8_HotRopeJump(f32 zoom, f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz) {
    CZoom += zoom;
    D_80100520_HotRopeJump += zoom;
    D_80100524_HotRopeJump += zoom;
    CRot.x += rx;
    CRot.y += ry;
    CRot.z += rz;
    D_80100508_HotRopeJump.x += rx;
    D_80100508_HotRopeJump.y += ry;
    D_80100508_HotRopeJump.z += rz;
    D_80100514_HotRopeJump.x += rx;
    D_80100514_HotRopeJump.y += ry;
    D_80100514_HotRopeJump.z += rz;
    Center.x += cx;
    Center.y += cy;
    Center.z += cz;
    D_801004F0_HotRopeJump.x += cx;
    D_801004F0_HotRopeJump.y += cy;
    D_801004F0_HotRopeJump.z += cz;
    D_801004FC_HotRopeJump.x += cx;
    D_801004FC_HotRopeJump.y += cy;
    D_801004FC_HotRopeJump.z += cz;
}

void func_800FA914_HotRopeJump(void) {
    D_80100520_HotRopeJump = D_80100524_HotRopeJump;
    D_80100508_HotRopeJump.x = D_80100514_HotRopeJump.x;
    D_80100508_HotRopeJump.y = D_80100514_HotRopeJump.y;
    D_80100508_HotRopeJump.z = D_80100514_HotRopeJump.z;
    D_801004F0_HotRopeJump.x = D_801004FC_HotRopeJump.x;
    D_801004F0_HotRopeJump.y = D_801004FC_HotRopeJump.y;
    D_801004F0_HotRopeJump.z = D_801004FC_HotRopeJump.z;
}

void func_800FA978_HotRopeJump(void) {
    D_80100520_HotRopeJump = CZoom;
    D_80100508_HotRopeJump.x = CRot.x;
    D_80100508_HotRopeJump.y = CRot.y;
    D_80100508_HotRopeJump.z = CRot.z;
    D_801004F0_HotRopeJump.x = Center.x;
    D_801004F0_HotRopeJump.y = Center.y;
    D_801004F0_HotRopeJump.z = Center.z;
}

void func_800FA9DC_HotRopeJump(omObjData* obj) {
    f32 t;

    if (D_80100528_HotRopeJump != 0) {
        if (--D_80100528_HotRopeJump == 0) {
            func_800FA914_HotRopeJump();
        }
        t = (f32)(D_8010052A_HotRopeJump - D_80100528_HotRopeJump) / D_8010052A_HotRopeJump;
        CZoom = (D_80100524_HotRopeJump - D_80100520_HotRopeJump) * t + D_80100520_HotRopeJump;
        CRot.x = D_80100508_HotRopeJump.x + (D_80100514_HotRopeJump.x - D_80100508_HotRopeJump.x) * t;
        CRot.y = D_80100508_HotRopeJump.y + (D_80100514_HotRopeJump.y - D_80100508_HotRopeJump.y) * t;
        CRot.z = D_80100508_HotRopeJump.z + (D_80100514_HotRopeJump.z - D_80100508_HotRopeJump.z) * t;
        Center.x = D_801004F0_HotRopeJump.x + (D_801004FC_HotRopeJump.x - D_801004F0_HotRopeJump.x) * t;
        Center.y = D_801004F0_HotRopeJump.y + (D_801004FC_HotRopeJump.y - D_801004F0_HotRopeJump.y) * t;
        Center.z = D_801004F0_HotRopeJump.z + (D_801004FC_HotRopeJump.z - D_801004F0_HotRopeJump.z) * t;
    }
}

/* Halfword i of an N64-layout Mtx (integer halves 0..15, fractions 16..31); see src/65770.c. */
#define HRJ_MTX_HALF(m, i) (((u16*)(m))[i])

/* World position -> screen position (x, y) and depth (z), through camera cam's view matrix. */
// NON_MATCHING: register allocation
#ifdef NON_MATCHING
void func_800FAB34_HotRopeJump(s32 cam, Vec* pos, Vec* out) {
    Mtx mtx;
    unk_Struct00* c = &D_800C3110[cam];
    Mtx* view = (Mtx*)((u8*)&c->unkF8 + D_800F3FA8 * 0x80) + 1;
    Mtx* m = &mtx;
    unk_Struct00* vp;
    f32 sx;
    f32 sy;
    f32 sz;

    guTranslate(m, pos->x, pos->y, pos->z);
    guMtxCatL(m, view, m);
    sx = (s32)((HRJ_MTX_HALF(&mtx, 12) << 16) | HRJ_MTX_HALF(&mtx, 28)) >> 16;
    sy = (s32)((HRJ_MTX_HALF(&mtx, 13) << 16) | HRJ_MTX_HALF(&mtx, 29)) >> 16;
    sz = (s32)((HRJ_MTX_HALF(&mtx, 14) << 16) | HRJ_MTX_HALF(&mtx, 30)) >> 16;
    sz *= sinf(D_800C3110[cam].unk_40 * 0.017444444444444446 / 2.0);
    sz = fabsf(sz / cosf(D_800C3110[cam].unk_40 * 0.017444444444444446 / 2.0));
    if (sz != 0.0) {
        vp = (unk_Struct00*)((u8*)c + D_800F3FA8 * 16);
        out->x = (s16)(vp->unk58 / 4.0 * sx / sz / 1.3333334f) + vp->unk60 / 4.0;
        vp = (unk_Struct00*)((u8*)c + D_800F3FA8 * 16);
        out->y = (s16)(vp->unk5A / 4.0 * -sy / sz) + vp->unk62 / 4.0;
        out->z = sz;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HotRopeJump/207040", func_800FAB34_HotRopeJump);
#endif

/* func_800FAB34 through the current CZoom/CRot/Center camera; z becomes how far the point lies
   outside a box of scaleX x scaleY around it (0 when inside). */
// NON_MATCHING: register allocation
#ifdef NON_MATCHING
void func_800FADDC_HotRopeJump(s32 cam, Vec* pos, Vec* out, f32 scaleX, f32 scaleY) {
    Mtx view;
    Mtx mtx;
    f32 sc[2];
    Vec eye;
    Vec at;
    Vec up;
    unk_Struct00* c;
    unk_Struct00* vp;
    f32 rx;
    f32 ry;
    f32 sx;
    f32 sy;
    f32 sz;
    f32 dist;

    c = &D_800C3110[cam];
    rx = CRot.x;
    ry = CRot.y;
    eye.x = func_800AEAC0(ry) * func_800AEFD0(rx) * CZoom + Center.x;
    eye.y = -func_800AEAC0(rx) * CZoom + Center.y;
    eye.z = func_800AEFD0(ry) * func_800AEFD0(rx) * CZoom + Center.z;
    at.x = Center.x;
    at.y = Center.y;
    at.z = Center.z;
    up.x = func_800AEAC0(ry) * func_800AEAC0(rx);
    up.y = func_800AEFD0(rx);
    up.z = func_800AEFD0(ry) * func_800AEAC0(rx);
    guLookAt(&view, eye.x, eye.y, eye.z, at.x, at.y, at.z, up.x, up.y, up.z);
    guTranslate(&mtx, pos->x, pos->y, pos->z);
    guMtxCatL(&mtx, &view, &mtx);
    sx = (s32)((HRJ_MTX_HALF(&mtx, 12) << 16) | HRJ_MTX_HALF(&mtx, 28)) >> 16;
    sy = (s32)((HRJ_MTX_HALF(&mtx, 13) << 16) | HRJ_MTX_HALF(&mtx, 29)) >> 16;
    sz = (s32)((HRJ_MTX_HALF(&mtx, 14) << 16) | HRJ_MTX_HALF(&mtx, 30)) >> 16;
    dist = fabsf(sz * func_800AEAC0(D_800C3110[cam].unk_40 / 2.0) / func_800AEFD0(D_800C3110[cam].unk_40 / 2.0));
    if (dist != 0.0) {
        vp = (unk_Struct00*)((u8*)c + D_800F3FA8 * 16);
        out->x = (s16)(vp->unk58 / 4.0 * sx / dist / 1.3333334f) + vp->unk60 / 4.0;
        vp = (unk_Struct00*)((u8*)c + D_800F3FA8 * 16);
        out->y = (s16)(vp->unk5A / 4.0 * -sy / dist) + vp->unk62 / 4.0;
        out->z = dist;
    }
    if (dist != 0.0f) {
        sc[0] = sx * sz / dist * (1.0f / scaleX);
        sc[1] = sy * sz / dist * (1.0f / scaleY);
        sz = fabsf(sz);
        sc[0] = fabsf(sc[0]);
        sc[1] = fabsf(sc[1]);
        if (sc[0] == 0.0f && sc[1] == 0.0f) {
            out->z = 0.0f;
        } else if (sc[1] < sc[0]) {
            out->z = sc[0] - sz;
        } else {
            out->z = sc[1] - sz;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HotRopeJump/207040", func_800FADDC_HotRopeJump);
#endif

void func_800FB260_HotRopeJump(void) {
    HRJLight* l;
    s32 i;

    l = D_80100538_HotRopeJump;
    for (i = 0; i < 32; i++, l++) {
        l->used = 0;
        l->z = 0;
        l->y = 0;
        l->x = 0;
        l->radius = l->aspect = l->radiusSq = 0;
    }
    D_801007C4_HotRopeJump = 0;
    D_801007C8_HotRopeJump = 1.0f;
    omAddObj(10, 1, 0, -1, func_800FB494_HotRopeJump);
    omAddObj(8, 2, 0, -1, func_800FC0B4_HotRopeJump);
    omAddObj(9, 13, 0, -1, func_800FCAC0_HotRopeJump);
}

void func_800FB328_HotRopeJump(void) {
    func_80023728(D_80100854_HotRopeJump);
    func_80023728(D_80100850_HotRopeJump);
}

void func_800FB354_HotRopeJump(f32 angle) {
    Matrix4f m;
    Vec v;
    unk_Struct00* c;

    c = D_800C3110;
    func_800234B8(0, 0x60, 0x50, 0x40);
    func_800234B8(2, 0xFF, 0xA0, 0x40);
    HuGuLookAtF(m, c->pos.x, c->pos.y, c->pos.z, c->unkC.x, c->unkC.y, c->unkC.z, c->unk18.x, c->unk18.y,
                c->unk18.z);
    m[3][0] = m[3][1] = m[3][2] = 0.0f;
    func_800FE3B4_HotRopeJump(m, func_800AEFD0(angle) * 100.0, func_800AEAC0(angle) * 100.0, 0.0f, &v);
    func_80023504(1, 0.0f, 0.0f, -100.0f);
    func_80023504(2, v.x, v.y, v.z);
}

void func_800FB494_HotRopeJump(omObjData* obj) {
    obj->func_ptr = func_800FB4E0_HotRopeJump;
    D_801007BC_HotRopeJump = InitSprite(0x420005);
    obj->model[0] = func_800FBABC_HotRopeJump();
}

void func_800FB4E0_HotRopeJump(omObjData* obj) {
    func_800FB354_HotRopeJump(D_80100854_HotRopeJump[6].angle);
}

s16 func_800FB504_HotRopeJump(f32 x, f32 y, f32 z, f32 radius) {
    HRJLight* l;
    s32 i;

    l = D_80100538_HotRopeJump;
    for (i = 0; i < 32; i++, l++) {
        if (l->used == 0) {
            break;
        }
    }
    if (i < 32) {
        l->used = 1;
        func_800FB5CC_HotRopeJump(i, x, y, z);
        func_800FB638_HotRopeJump(i, radius, radius);
        D_801007B8_HotRopeJump++;
    } else {
        i = -1;
    }
    return i;
}

void func_800FB5CC_HotRopeJump(s16 id, f32 x, f32 y, f32 z) {
    D_80100538_HotRopeJump[id].x = x;
    D_80100538_HotRopeJump[id].y = y;
    D_80100538_HotRopeJump[id].z = z;
}

void func_800FB638_HotRopeJump(s16 id, f32 radius, f32 h) {
    D_80100538_HotRopeJump[id].radius = radius;
    D_80100538_HotRopeJump[id].aspect = radius / h;
    D_80100538_HotRopeJump[id].radiusSq = radius * radius;
}

void func_800FB690_HotRopeJump(s16 id) {
    D_80100538_HotRopeJump[id].used = 0;
}

/* The floor grid's draw callback: lights each vertex by the rope lights, then draws it. */
// NON_MATCHING: register allocation and block layout
#ifdef NON_MATCHING
void func_800FB6B4_HotRopeJump(Gfx** gfxp) {
    HRJLight* list[33];
    unk2C0C0StructC0* m;
    unk2C0C0StructE0* v;
    HRJLight* l;
    HRJLight** lp;
    s32 n;
    s32 i;
    s32 r;
    s32 dx;
    s32 dz;
    s32 d2;
    f32 sum;
    f32 f;
    f32 inner;

    n = 0;
    for (i = 0; i < 32; i++) {
        l = &D_80100538_HotRopeJump[i];
        if (l->used != 0 && l->radius > 10.0) {
            list[n++] = l;
        }
    }
    list[n] = NULL;
    m = D_800F2B7C[D_801007BA_HotRopeJump].unk_6C;
    v = m->unk_08[D_800F37F0];
    for (i = 0; i < 0x300; i++, v++) {
        sum = 0.0f;
        l = list[0];
        lp = &list[1];
        if (l != NULL) {
            do {
                dx = l->y + 50;
                if (dx < 0) {
                    dx = -dx;
                }
                r = dx * 0.75 + l->radius;
                dx = v->unk_00 - l->x;
                if (dx < 0) {
                    dx = -dx;
                }
                if (dx < r) {
                    dz = (f32)(v->unk_04 - l->z) * l->aspect;
                    if (dz < 0) {
                        dz = -dz;
                    }
                    if (dz < r) {
                        d2 = dx * dx + dz * dz;
                        if (d2 < r * r) {
                            inner = l->radius - r * 2;
                            f = 1.0f;
                            if (inner <= 0.0f || inner * inner < (f32)d2) {
                                f = 1.0f - (sqrtf(d2) - inner) / ((f32)r - inner);
                            }
                            sum += f;
                        }
                    }
                }
                l = *lp++;
            } while (l != NULL);
        }
        if (sum > 1.0) {
            sum = 1.0f;
        }
        v->unk_0C.r = v->unk_0C.g = v->unk_0C.b = sum * 255.0f;
    }
    gSPDisplayList((*gfxp)++, osVirtualToPhysical((Gfx*)D_800FE610_HotRopeJump));
    func_8001D658(0, gfxp);
    gSPSegment((*gfxp)++, 1, osVirtualToPhysical(m->unk_08[D_800F37F0]));
    gSPDisplayList((*gfxp)++, osVirtualToPhysical(D_801007C0_HotRopeJump));
    gDPPipeSync((*gfxp)++);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HotRopeJump/207040", func_800FB6B4_HotRopeJump);
#endif

/* Builds the floor: a 2 x 12 x 32 vertex grid (per-frame copies, lit by func_800FB6B4) and its
   display list. Returns the model. */
// NON_MATCHING: retail writes the list through fixed offsets, not gfx++ (different shape)
#ifdef NON_MATCHING
s16 func_800FBABC_HotRopeJump(void) {
    unk65770Anim* tex;
    Gfx* buf;
    Gfx* gfx;
    unk2C0C0StructC0* m;
    unk2C0C0StructE0* v;
    unk2C0C0StructE0* src;
    s16 model;
    s32 step;
    s32 x0;
    s32 s0;
    s32 x;
    s32 z;
    s32 s;
    s32 t;
    s32 half;
    s32 row;
    s32 col;
    s32 i;
    s32 size;
    s32 vtx;
    s32 cur;
    s32 prev;

    step = 60;
    tex = func_80067310(D_801007BC_HotRopeJump);
    buf = func_80023668(0x2000 * sizeof(Gfx));
    model = D_801007BA_HotRopeJump = func_8002451C(0xC0, func_800FB6B4_HotRopeJump, 0);
    m = D_800F2B7C[model].unk_6C;
    m->unk_04 = m->unk_08[0] = v = func_80023684(0x364 * sizeof(Vtx), m->unk_68);
    x0 = -step * 12;
    s0 = 0;
    for (half = 0; half < 2; half++) {
        z = step * -16.0;
        t = 0;
        for (row = 0; row < 32; row++) {
            x = x0;
            s = s0;
            for (col = 0; col < 12; col++) {
                v->unk_00 = x;
                v->unk_02 = 0;
                v->unk_04 = z;
                *(s16*)v->unk_06 = 0;
                v->unk_08 = s;
                v->unk_0A = t;
                v->unk_0C.r = v->unk_0C.g = v->unk_0C.b = 0xFF;
                v->unk_0F = 0xFF;
                x += step;
                s += 0x200;
                v++;
            }
            z += step;
            t += 0x200;
        }
        x0 += step * 11;
        s0 += 0x1600;
    }
    for (i = 1; i < D_800F37DA; i++) {
        v = m->unk_08[i] = func_80023684(0x364 * sizeof(Vtx), m->unk_68);
        src = m->unk_08[0];
        for (row = 0; row < 0x300; row++) {
            *v++ = *src++;
        }
    }
    gfx = buf;
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gfx++, 0x60600);
    gSPSetGeometryMode(gfx++, 0x280004);
    gDPSetRenderMode(gfx++, 0xC084000, 0);
    gDPSetCombine(gfx++, 0x127E24, 0xFFFFF9FC);
    gDPSetColorDither(gfx++, G_CD_NOISE);
    gDPSetTexturePersp(gfx++, G_TP_PERSP);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gDPSetTextureConvert(gfx++, G_TC_FILT);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);
    gDPLoadTLUT_pal16(gfx++, 0, tex->unkC);
    gDPLoadTextureBlock_4b(gfx++, tex->unk8, G_IM_FMT_CI, 32, 32, 0, G_TX_WRAP, G_TX_WRAP, 5, 5, G_TX_NOLOD,
                           G_TX_NOLOD);
    gSPTexture(gfx++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    vtx = 0;
    for (half = 0; half < 2; half++) {
        gSPVertex(gfx++, 0x01000000 | (s16)vtx << 4, 12, 0);
        vtx += 12;
        for (row = 1; row < 32; row++) {
            cur = (row & 1) * 16;
            prev = ((row - 1) & 1) * 16;
            gSPVertex(gfx++, 0x01000000 | (s16)vtx << 4, 12, cur);
            vtx += 12;
            for (col = 1; col < 12; col++) {
                gSP2Triangles(gfx++, cur + col, prev + col - 1, cur + col - 1, 0, prev + col, prev + col - 1,
                              cur + col, 0);
            }
        }
    }
    gSPEndDisplayList(gfx++);
    size = (u8*)gfx - (u8*)buf;
    D_801007C0_HotRopeJump = func_80023684(size, m->unk_68);
    func_80023A38(buf, D_801007C0_HotRopeJump, size);
    func_80023728(buf);
    return model;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HotRopeJump/207040", func_800FBABC_HotRopeJump);
#endif


/* The two torches: flame models at the ends of the floor, each with a light. */
void func_800FC0B4_HotRopeJump(omObjData* obj) {
    s16 pos[2][4] = { { 0, 150, -600, 0 }, { 0, 150, 600, 180 } };
    HRJSeg* seg;
    unk_ovl_2D_struct* mdl;
    unk65770Anim* tex;
    s32 i;

    omSetStatBit(obj, 0xA0);
    obj->func_ptr = func_800FC428_HotRopeJump;
    D_801007CC_HotRopeJump = InitSprite(0x420006);
    D_801007CE_HotRopeJump = InitSprite(0x420007);
    seg = func_80023684(13 * sizeof(HRJSeg), 0x7918);
    obj->unk_50 = seg;
    D_80100850_HotRopeJump = seg;
    func_8009B770(seg, 0, 13 * sizeof(HRJSeg));
    for (i = 0; i < 2; i++, seg++) {
        tex = func_80067310(D_801007CC_HotRopeJump);
        obj->model[i] = seg->model = func_800FD90C_HotRopeJump(D_800FE650_HotRopeJump, tex, func_80067310(D_801007CE_HotRopeJump));
        mdl = &D_800F2B7C[seg->model];
        seg->pos.x = seg->base.x = pos[i][0];
        seg->pos.y = seg->base.y = pos[i][1];
        seg->pos.z = seg->base.z = pos[i][2];
        mdl->unk_34 = pos[i][3];
        mdl->unk_3C = mdl->unk_40 = mdl->unk_44 = 0.0f;
        seg->anim = ((rand8() << 8) | rand8()) / 1024 & 0x3C;
        func_80025798(seg->model, seg->pos.x, seg->pos.y, seg->pos.z);
        if (i == 0) {
            omSetTra(obj, seg->pos.x, seg->pos.y, seg->pos.z);
            omSetRot(obj, mdl->unk_30, mdl->unk_34, mdl->unk_38);
            omSetSca(obj, mdl->unk_3C, mdl->unk_40, mdl->unk_44);
        }
        seg->light = func_800FB504_HotRopeJump(seg->pos.x, seg->pos.y - 50.0, seg->pos.z, 10.0f);
    }
    D_80100824_HotRopeJump.x = Center.x;
    D_80100824_HotRopeJump.y = Center.y;
    D_80100824_HotRopeJump.z = Center.z;
    D_8010083C_HotRopeJump.x = CRot.x;
    D_8010083C_HotRopeJump.y = CRot.y;
    D_8010083C_HotRopeJump.z = CRot.z;
    D_8010084C_HotRopeJump = CZoom;
    D_80100818_HotRopeJump.x = Center.x = 0.0f;
    D_80100818_HotRopeJump.y = Center.y = 100.0f;
    D_80100818_HotRopeJump.z = Center.z = 0.0f;
    D_80100830_HotRopeJump.x = CRot.x = -30.0f;
    D_80100830_HotRopeJump.y = CRot.y = 0.0f;
    D_80100830_HotRopeJump.z = CRot.z = 0.0f;
    D_80100848_HotRopeJump = CZoom = 1000.0f;
}

/* The torches: the intro camera move and light, then each flame's light and list. */
// NON_MATCHING: register allocation and block layout
#ifdef NON_MATCHING
void func_800FC428_HotRopeJump(omObjData* obj) {
    HRJSeg* seg;
    unk_ovl_2D_struct* mdl;
    unk65770Anim* anim;
    s32 i;
    f32 t;

    HuGuLookAtF(D_801007D8_HotRopeJump, D_800C3110->pos.x, D_800C3110->pos.y, D_800C3110->pos.z, D_800C3110->unkC.x,
                D_800C3110->unkC.y, D_800C3110->unkC.z, D_800C3110->unk18.x, D_800C3110->unk18.y,
                D_800C3110->unk18.z);
    anim = func_80067310(D_801007CE_HotRopeJump);
    if (func_8005FD5C() + D_800F64F8 == 0 && D_800FE6E4_HotRopeJump[D_800FE6E0_HotRopeJump.state] != 0) {
        switch (D_800FE6E0_HotRopeJump.state) {
            case 0:
                t = (f32)(D_800FE6E0_HotRopeJump.timer - 40) * 0.025;
                if (t > 0.0) {
                    Center.x = (D_80100824_HotRopeJump.x - D_80100818_HotRopeJump.x) * t + D_80100818_HotRopeJump.x;
                    Center.y = (D_80100824_HotRopeJump.y - D_80100818_HotRopeJump.y) * t + D_80100818_HotRopeJump.y;
                    Center.z = (D_80100824_HotRopeJump.z - D_80100818_HotRopeJump.z) * t + D_80100818_HotRopeJump.z;
                    CRot.x = (D_8010083C_HotRopeJump.x - D_80100830_HotRopeJump.x) * t + D_80100830_HotRopeJump.x;
                    CRot.y = (D_8010083C_HotRopeJump.y - D_80100830_HotRopeJump.y) * t + D_80100830_HotRopeJump.y;
                    CRot.z = (D_8010083C_HotRopeJump.z - D_80100830_HotRopeJump.z) * t + D_80100830_HotRopeJump.z;
                    CZoom = (D_8010084C_HotRopeJump - D_80100848_HotRopeJump) * t + D_80100848_HotRopeJump;
                }
                break;
            case 2:
                if (D_801007C4_HotRopeJump != 0) {
                    D_800FE6E0_HotRopeJump.state++;
                    D_800FE6E0_HotRopeJump.timer = 0;
                }
                break;
            case 3:
                if (D_801007C4_HotRopeJump == 0) {
                    D_800FE6E0_HotRopeJump.state++;
                    D_800FE6E0_HotRopeJump.timer = 0;
                    D_80100530_HotRopeJump = func_800FB504_HotRopeJump(0.0f, 100.0f, 0.0f, 10.0f);
                }
                break;
            case 4:
                t = (f32)D_800FE6E0_HotRopeJump.timer * (1.0 / 30.0);
                func_800FB638_HotRopeJump(D_80100530_HotRopeJump, t * 400.0, t * 500.0);
                func_80023448(3);
                func_800234B8(3, t * 255.0f, t * 160.0f, t * 64.0f);
                func_80023504(3, 0.0f, 100.0f, 0.0f);
                break;
        }
        if (++D_800FE6E0_HotRopeJump.timer >= D_800FE6E4_HotRopeJump[D_800FE6E0_HotRopeJump.state]) {
            D_800FE6E0_HotRopeJump.timer = 0;
            if (++D_800FE6E0_HotRopeJump.state == 1) {
                PlaySound(0x337);
            }
        }
    }
    seg = obj->unk_50;
    for (i = 0; i < 2; i++, seg++) {
        mdl = &D_800F2B7C[seg->model];
        if (func_8005FD5C() + D_800F64F8 == 0) {
            if (D_800FE6E0_HotRopeJump.state == 1) {
                if (mdl->unk_3C < 1.0) {
                    mdl->unk_44 = mdl->unk_3C = mdl->unk_3C + 0.1;
                    mdl->unk_40 = mdl->unk_3C * 1.4;
                } else if (mdl->unk_40 > 1.0) {
                    mdl->unk_40 = mdl->unk_40 - 0.1;
                }
            }
            if (D_800FE6E0_HotRopeJump.state > 0) {
                t = (func_800AEAC0((seg->anim & 0xF) * 11.25) * 0.4 * 100.0 + 180.0) * mdl->unk_3C;
                func_800FB638_HotRopeJump(seg->light, t, t);
                seg->anim = (seg->anim + 2) & 0x3F;
                if (++seg->timer >= 0x7800) {
                    seg->timer -= 0x800;
                }
            }
        }
        if (i == 0) {
            omSetSca(obj, mdl->unk_3C, mdl->unk_40, mdl->unk_44);
        }
        func_800FDFC4_HotRopeJump(seg, D_800FE650_HotRopeJump, anim);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HotRopeJump/207040", func_800FC428_HotRopeJump);
#endif

/* The rope: 13 flame models with lights, placed at random, that then gather into the turning
   rope (func_800FCE98). */
// NON_MATCHING: retail's frame is 24 bytes larger, and f0/f2 swap in the two int-to-float conversions (masked 26); tried t = i - 6; t /= 6.0f
#ifdef NON_MATCHING
void func_800FCAC0_HotRopeJump(omObjData* obj) {
    HRJSeg* seg;
    unk_ovl_2D_struct* mdl;
    unk65770Anim* tex;
    s32 i;
    f32 t;
    s32 r;

    omSetStatBit(obj, 0xA0);
    obj->func_ptr = func_800FCE98_HotRopeJump;
    D_80100854_HotRopeJump = func_80023684(13 * sizeof(HRJSeg), 0x7918);
    func_8009B770(D_80100854_HotRopeJump, 0, 13 * sizeof(HRJSeg));
    D_801007D0_HotRopeJump = InitSprite(0x420006);
    D_801007D2_HotRopeJump = InitSprite(0x420007);
    seg = D_80100854_HotRopeJump;
    for (i = 0; i < 13;) {
        tex = func_80067310(D_801007D0_HotRopeJump);
        obj->model[i] = seg->model = func_800FD90C_HotRopeJump(D_800FE6F4_HotRopeJump, tex, func_80067310(D_801007D2_HotRopeJump));
        mdl = &D_800F2B7C[seg->model];
        mdl->unk_6C->unk_80->unk_14 |= 0x71010000;
        mdl->unk_6C->unk_80->unk_14 &= ~0x2000;
        seg->pos.x = seg->base.x = ((rand8() << 8) | rand8()) * 800.0 / 65536.0 - 400.0;
        seg->pos.y = seg->base.z = 50.0f;
        seg->pos.z = seg->base.z = ((rand8() << 8) | rand8()) * 800.0 / 65536.0 - 400.0;
        seg->size = 150.0f;
        seg->anim = ((rand8() << 8) | rand8()) / 2048 & 0x3C;
        t = (f32)(i - 6) / 6.0f;
        seg->angle = t * t * 30.0 - 15.0;
        seg->state = 0;
        seg->delay = i * 4 + 15;
        mdl->unk_3C = mdl->unk_40 = mdl->unk_44 = 0.0f;
        r = ((rand8() << 8) | rand8()) * 160;
        mdl->unk_34 = (f32)(r / 65536 - 80) + 270.0f;
        if (i == 0) {
            seg->pos.x = seg->pos.z = 0.0f;
            mdl->unk_34 = 0.0f;
        } else {
            seg->delay += 16;
        }
        func_80025798(seg->model, seg->pos.x, seg->pos.y, seg->pos.z);
        if (i == 0) {
            mdl = &D_800F2B7C[seg->model];
            omSetTra(obj, seg->pos.x, seg->pos.y, seg->pos.z);
            omSetRot(obj, mdl->unk_30, mdl->unk_34, mdl->unk_38);
            omSetSca(obj, mdl->unk_3C, mdl->unk_40, mdl->unk_44);
        }
        i++;
        seg->light = func_800FB504_HotRopeJump(seg->pos.x, seg->pos.y, seg->pos.z, 10.0f);
        rand8();
        seg++;
        rand8();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HotRopeJump/207040", func_800FCAC0_HotRopeJump);
#endif



/* The rope: each flame grows in, flies to its place, then turns with the rope (state 3) until it
   is put out (state 4). */
// NON_MATCHING: register allocation and block layout
#ifdef NON_MATCHING
void func_800FCE98_HotRopeJump(omObjData* obj) {
    Matrix4f m;
    HRJSeg* seg;
    unk_ovl_2D_struct* mdl;
    unk65770Anim* anim;
    unk_Struct00* c;
    s32 i;
    f32 t;
    f32 r;
    f32 x;
    f32 y;
    f32 z;
    f32 a;

    c = D_800C3110;
    if (func_8005FD5C() + D_800F64F8 == 0) {
        D_800FE784_HotRopeJump.timer++;
        if (D_800FE788_HotRopeJump[D_800FE784_HotRopeJump.state] != 0 &&
            D_800FE784_HotRopeJump.timer >= D_800FE788_HotRopeJump[D_800FE784_HotRopeJump.state]) {
            D_800FE784_HotRopeJump.timer = 0;
            D_800FE784_HotRopeJump.state++;
        }
    }
    HuGuLookAtF(m, c->pos.x, c->pos.y, c->pos.z, c->unkC.x, c->unkC.y, c->unkC.z, c->unk18.x, c->unk18.y, c->unk18.z);
    anim = func_80067310(D_801007CE_HotRopeJump);
    if (func_8005FD5C() + D_800F64F8 == 0) {
        seg = D_80100854_HotRopeJump;
        for (i = 0; i < 13; i++, seg++) {
            mdl = &D_800F2B7C[seg->model];
            t = (f32)(i - 6) / 6.0f;
            r = (1.0 - t * t) * 200.0 + 100.0;
            x = func_800AEFD0(seg->angle) * r;
            y = func_800AEAC0(seg->angle) * r + 150.0;
            if (y < 50.0) {
                y = 50.0f;
            }
            z = (i - 6) * 80.0;
            switch (seg->state) {
                case 0:
                    if (seg->delay != 0) {
                        if (--seg->delay == 0 && (i == 0 || i < 11)) {
                            PlaySound(0x336);
                        }
                        continue;
                    }
                    if (mdl->unk_3C < 1.0) {
                        mdl->unk_44 = mdl->unk_3C = mdl->unk_3C + 0.1;
                        mdl->unk_40 = mdl->unk_3C * 1.4;
                        func_800FB638_HotRopeJump(seg->light, seg->size * mdl->unk_3C, seg->size * mdl->unk_3C);
                        continue;
                    }
                    if (1.0 < mdl->unk_40) {
                        mdl->unk_40 = mdl->unk_40 - 0.1;
                    } else if (D_800FE784_HotRopeJump.state != 0) {
                        seg->state = 1;
                        seg->timer = 0;
                        seg->delay = ((i < 6) ? i : 12 - i) * 4 + 2;
                        seg->vel.x = (x - seg->pos.x) * 0.05;
                        seg->vel.z = (z - seg->pos.z) * 0.05;
                        seg->vel.y = 50.0f;
                    }
                    break;
                case 1:
                    if (seg->delay != 0) {
                        if (--seg->delay != 0) {
                            continue;
                        }
                        seg->timer = 0;
                        if (i == 0) {
                            func_80060540(0x339, 3);
                            continue;
                        }
                        break;
                    }
                    seg->pos.x += seg->vel.x;
                    seg->pos.y += seg->vel.y;
                    seg->pos.z += seg->vel.z;
                    seg->vel.y = seg->vel.y - 5.0;
                    if (seg->timer < 21) {
                        continue;
                    }
                    seg->state = 2;
                    seg->timer = 0;
                    break;
                case 2:
                    if (seg->timer < 31) {
                        t = seg->timer / 30.0;
                    } else {
                        t = 1.0f;
                    }
                    seg->pos.x = seg->pos.x + (x - seg->pos.x) * t * 0.2;
                    seg->pos.y = seg->pos.y + (y - seg->pos.y) * t * 0.2;
                    seg->pos.z = seg->pos.z + (z - seg->pos.z) * t * 0.2;
                    a = 270.0 - mdl->unk_34;
                    if (a <= -180.0) {
                        a = a + 360.0;
                    } else if (a > 180.0) {
                        a = a - 360.0;
                    }
                    mdl->unk_34 = mdl->unk_34 + a * t * 0.2;
                    if (mdl->unk_34 >= 360.0) {
                        mdl->unk_34 = mdl->unk_34 - 360.0;
                    } else if (mdl->unk_34 < 0.0) {
                        mdl->unk_34 = mdl->unk_34 + 360.0;
                    }
                    if (seg->light >= 0 && !(i & 1)) {
                        if (seg->timer == 30) {
                            func_800FB690_HotRopeJump(seg->light);
                            seg->light = -1;
                        } else {
                            t = (30 - seg->timer) * (1.0 / 30.0);
                            func_800FB638_HotRopeJump(seg->light, t * seg->size, t * seg->size);
                        }
                    }
                    if (D_801007C4_HotRopeJump != 0) {
                        seg->state = 3;
                    }
                    break;
                case 3:
                    seg->angle = seg->angle + D_801007C8_HotRopeJump * 10.0;
                    if (seg->angle >= 360.0) {
                        seg->angle = seg->angle - 360.0;
                    }
                    if (seg->angle < 0.0) {
                        seg->angle = seg->angle + 360.0;
                    }
                    seg->vel.x = x - seg->pos.x;
                    seg->vel.y = y - seg->pos.y;
                    seg->vel.z = z - seg->pos.z;
                    seg->pos.x = x;
                    seg->pos.y = y;
                    seg->pos.z = z;
                    if (D_801007C4_HotRopeJump != 0) {
                        continue;
                    }
                    seg->state = 4;
                    seg->delay = 4;
                    break;
                case 4:
                    if (i == 0 && seg->delay != 0 && --seg->delay == 0) {
                        PlaySound(0x33A);
                    }
                    if (!(mdl->unk_3C > 0.0)) {
                        continue;
                    }
                    seg->pos.x += seg->vel.x;
                    seg->pos.y += seg->vel.y;
                    seg->pos.z += seg->vel.z;
                    mdl->unk_44 = mdl->unk_40 = mdl->unk_3C = mdl->unk_3C - 0.1;
                    if (mdl->unk_3C > 0.05) {
                        if (seg->light >= 0) {
                            func_800FB638_HotRopeJump(seg->light, seg->size * mdl->unk_3C, seg->size * mdl->unk_3C);
                        }
                        continue;
                    }
                    if (seg->light >= 0) {
                        func_800FB690_HotRopeJump(seg->light);
                        seg->light = -1;
                    }
                    func_800258EC(seg->model, 4, 4);
                    break;
            }
        }
    }
    seg = D_80100854_HotRopeJump;
    for (i = 0; i < 13; i++, seg++) {
        if (func_8005FD5C() + D_800F64F8 == 0) {
            seg->base.x = seg->base.x - (seg->base.x - seg->pos.x) * 0.5;
            seg->base.y = seg->base.y - (seg->base.y - seg->pos.y) * 0.5;
            seg->base.z = seg->base.z - (seg->base.z - seg->pos.z) * 0.5;
            seg->anim = (seg->anim + 4) & 0x3F;
            if (++seg->timer >= 0x7800) {
                seg->timer -= 0x800;
            }
        }
        func_800FDFC4_HotRopeJump(seg, D_800FE6F4_HotRopeJump, anim);
        func_80025798(seg->model, seg->pos.x, seg->pos.y, seg->pos.z);
        if (i == 0) {
            mdl = &D_800F2B7C[seg->model];
            omSetTra(obj, seg->pos.x, seg->pos.y, seg->pos.z);
            omSetRot(obj, mdl->unk_30, mdl->unk_34, mdl->unk_38);
            omSetSca(obj, mdl->unk_3C, mdl->unk_40, mdl->unk_44);
        }
        if (seg->light >= 0) {
            func_800FB5CC_HotRopeJump(seg->light, seg->pos.x, seg->pos.y, seg->pos.z);
        }
    }
    seg = D_80100854_HotRopeJump;
    for (i = 0; i < 12; i++, seg++) {
        seg->dir.x = seg[1].pos.x - seg->pos.x;
        seg->dir.y = seg[1].pos.y - seg->pos.y;
        seg->dir.z = seg[1].pos.z - seg->pos.z;
    }
}
#else
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_2E_HotRopeJump/207040", D_800FEA30_HotRopeJump);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_2E_HotRopeJump/207040", D_800FEA34_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HotRopeJump/207040", func_800FCE98_HotRopeJump);
#endif

/* Vertices copied per frame: retail copies 10 from a 9-vertex table (the 10th is the next data,
   unused by the lists); the host copies the 9 it has. */
#define HRJ_FLAME_VTX 10

/* A flame model: a five-vertex base quad (anim's texture, segment 2) and a four-vertex top
   (tex), with per-frame display lists (func_800FDFC4). Returns the model. */
// NON_MATCHING: retail writes the lists through fixed offsets, not gfx++ (different shape)
#ifdef NON_MATCHING
s16 func_800FD90C_HotRopeJump(const Vtx_t* vtx, unk65770Anim* tex, unk65770Anim* anim) {
    Gfx* buf;
    Gfx* gfx;
    unk2C0C0StructC0* m;
    s16 model;
    s32 size;
    s32 i;
    s32 j;

    buf = func_80023668(0x2000 * sizeof(Gfx));
    model = func_80024198(0xC0, buf, 4);
    m = D_800F2B7C[model].unk_6C;
    m->unk_80->unk_14 |= 0x71010000;
    m->unk_80->unk_14 &= ~0x2000;
    func_80023728(m->unk_00);
    m->unk_00 = func_80023684(8 * sizeof(Gfx*), D_800EE32E);
    for (i = 0; i < D_800F37DA; i++) {
        m->unk_08[i] = func_80023684(10 * sizeof(Vtx), m->unk_68);
        for (j = 0; j < HRJ_FLAME_VTX; j++) {
            ((Vtx_t*)m->unk_08[i])[j] = vtx[j];
        }
    }
    gfx = buf;
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPPipeSync(gfx++);
    gSPClearGeometryMode(gfx++, 0x20600);
    gSPSetGeometryMode(gfx++, 0x280205);
    gDPSetColorDither(gfx++, G_CD_NOISE);
    gDPSetTexturePersp(gfx++, G_TP_NONE);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gDPSetTextureConvert(gfx++, G_TC_FILT);
    gDPSetAlphaDither(gfx++, G_AD_PATTERN);
    gDPSetAlphaCompare(gfx++, G_AC_THRESHOLD);
    gDPSetBlendColor(gfx++, 1, 1, 1, 1);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPSetCombine(gfx++, 0xFF99FF, 0xFF30FE7F);
    gDPSetRenderMode(gfx++, 0x404A50, 0);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);
    gDPLoadTLUT_pal16(gfx++, 0, anim->unkC);
    gDPLoadTextureBlock_4b(gfx++, 0x02000000, G_IM_FMT_CI, 32, 64, 0, G_TX_CLAMP, G_TX_CLAMP, 5, 6, G_TX_NOLOD,
                           G_TX_NOLOD);
    gSPVertex(gfx++, 0x01000000, 5, 0);
    gSP2Triangles(gfx++, 0, 1, 4, 0, 1, 2, 4, 0);
    gSP2Triangles(gfx++, 0, 4, 3, 0, 4, 2, 3, 0);
    gSPEndDisplayList(gfx++);
    size = (u8*)gfx - (u8*)buf;
    m->unk_00[0] = m->unk_00[4] = func_80023684(size, m->unk_68);
    func_80023A38(buf, m->unk_00[4], size);
    gfx = buf;
    gDPPipeSync(gfx++);
    gDPSetCombine(gfx++, 0xFFFFFF, 0xFFFCF279);
    gDPSetRenderMode(gfx++, 0x443078, 0);
    gDPLoadTLUT_pal16(gfx++, 0, tex->unkC);
    gDPLoadTextureBlock_4b(gfx++, tex->unk8, G_IM_FMT_CI, 32, 32, 0, G_TX_MIRROR, G_TX_CLAMP, 5, 5, G_TX_NOLOD,
                           G_TX_NOLOD);
    gSPVertex(gfx++, 0x01000000 + 5 * sizeof(Vtx), 4, 5);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 5, 7, 8, 0);
    gSPEndDisplayList(gfx++);
    m->unk_00[5] = func_80023684(19 * sizeof(Gfx), m->unk_68);
    func_80023A38(buf, m->unk_00[5], 19 * sizeof(Gfx));
    func_80023728(buf);
    for (i = 0; i < D_800F37DA; i++) {
        m->unk_00[i + 1] = func_80023684(32 * sizeof(Gfx), m->unk_68);
    }
    return model;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HotRopeJump/207040", func_800FD90C_HotRopeJump);
#endif

/* A flame's per-frame list: its matrix (facing the camera, D_801007D8) and its animated texture;
   the top two vertices sway with seg->anim. */
// NON_MATCHING: retail writes the list through fixed offsets, not gfx++
#ifdef NON_MATCHING
void func_800FDFC4_HotRopeJump(HRJSeg* seg, const Vtx_t* vtx, unk65770Anim* anim) {
    Matrix4f m;
    Vec d;
    unk_ovl_2D_struct* mdl;
    unk2C0C0StructC0* md;
    Gfx* gfx;
    unk2C0C0StructE0* v;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 a;
    f32 r;
    s32 i;

    mdl = &D_800F2B7C[seg->model];
    md = mdl->unk_6C;
    dx = seg->base.x - seg->pos.x;
    dy = seg->base.y - seg->pos.y;
    dz = seg->base.z - seg->pos.z;
    d.x = dx * D_801007D8_HotRopeJump[0][0] + dy * D_801007D8_HotRopeJump[1][0] + dz * D_801007D8_HotRopeJump[2][0];
    d.y = dx * D_801007D8_HotRopeJump[0][1] + dy * D_801007D8_HotRopeJump[1][1] + dz * D_801007D8_HotRopeJump[2][1];
    d.z = dx * D_801007D8_HotRopeJump[0][2] + dy * D_801007D8_HotRopeJump[1][2] + dz * D_801007D8_HotRopeJump[2][2];
    guTranslateF(m, seg->pos.x, seg->pos.y, seg->pos.z);
    MtxRotate(m, mdl->unk_30, mdl->unk_34, mdl->unk_38);
    MtxScale(m, mdl->unk_3C, mdl->unk_40, mdl->unk_44);
    guMtxCatF(m, D_801007D8_HotRopeJump, m);
    func_800A0A20(m, &seg->mtx[D_800F37F0]);
    gfx = md->unk_00[D_800F37F0 + 1];
    md->unk_00[0] = gfx;
    gDPPipeSync(gfx++);
    gSPSegment(gfx++, 2, osVirtualToPhysical(anim->unk0[(s16)seg->anim >> 2].unk0));
    gSPDisplayList(gfx++, osVirtualToPhysical(md->unk_00[4]));
    gSPMatrix(gfx++, osVirtualToPhysical(&seg->mtx[D_800F37F0]), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gfx++, osVirtualToPhysical(md->unk_00[5]));
    gDPPipeSync(gfx++);
    gSPEndDisplayList(gfx++);
    v = md->unk_08[D_800F37F0];
    a = (f32)((seg->anim & 0x3F) * 360) * 0.015625 + 90.0;
    r = fabs(vtx->ob[0] * 0.4);
    for (i = 0; i < 2; i++) {
        v->unk_00 = vtx->ob[0] + func_800AEFD0(a) * r + d.x;
        v->unk_02 = vtx->ob[1] + func_800AEAC0(a) * r + d.y;
        a += 180.0;
        if (a >= 360.0) {
            a -= 360.0;
        }
        v++;
        vtx++;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HotRopeJump/207040", func_800FDFC4_HotRopeJump);
#endif

void func_800FE38C_HotRopeJump(void) {
    D_801007C4_HotRopeJump = 1;
}

void func_800FE39C_HotRopeJump(void) {
    D_801007C4_HotRopeJump = 0;
}

void func_800FE3A8_HotRopeJump(f32 speed) {
    D_801007C8_HotRopeJump = speed;
}

// NON_MATCHING: retail keeps out + 4 in a register (masked 3)
#ifdef NON_MATCHING
void func_800FE3B4_HotRopeJump(Matrix4f m, f32 x, f32 y, f32 z, Vec* out) {
    f32* o = (f32*)out;

    *o++ = x * m[0][0] + y * m[1][0] + z * m[2][0] + m[3][0];
    o[0] = x * m[0][1] + y * m[1][1] + z * m[2][1] + m[3][1];
    o[1] = x * m[0][2] + y * m[1][2] + z * m[2][2] + m[3][2];
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2E_HotRopeJump/207040", func_800FE3B4_HotRopeJump);
#endif
