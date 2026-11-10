#include "BombsAway.h"

int abs(int);
extern u8 D_800F64F8;


u16 D_800FFAC0_BombsAway = 0;
u16 D_800FFAC2_BombsAway = 0;
s16 D_800FFAC4_BombsAway = 0x36;
Vec D_800FFAC8_BombsAway = { 1000.0f, 0.0f, -1000.0f };
Vec D_800FFAD4_BombsAway = { 800.0f, 0.0f, -800.0f };
Vtx D_800FFAE0_BombsAway[4] = {
    { { { -125, 250, 0 }, 0, { 0, 0 }, { 0, 0, 0, 255 } } },
    { { { -125, 0, 0 }, 0, { 0, 0x800 }, { 0, 0, 0, 255 } } },
    { { { 125, 250, 0 }, 0, { 0x800, 0 }, { 0, 0, 0, 255 } } },
    { { { 125, 0, 0 }, 0, { 0x800, 0x800 }, { 0, 0, 0, 255 } } },
};
u16 D_800FFB20_BombsAway = 0;
u16 D_800FFB22_BombsAway = 0;
f32 D_800FFB24_BombsAway = 0.0f;
f32 D_800FFB28_BombsAway = 0.0f;
/* Random seed (func_800FE1EC); retail returns its low half through D_800FFB2E. */
s32 D_800FFB2C_BombsAway = 0x19971204;
u16 D_800FFB30_BombsAway = 0;
u16 D_800FFB32_BombsAway = 180;

void func_800FC5E0_BombsAway(void) {
    void* file;
    s16 image;

    func_800FDCA0_BombsAway();
    func_800234B8(0, 0x64, 0x64, 0x64);
    func_800234B8(1, 0xFF, 0xFF, 0xFF);
    func_80023504(1, 0.0f, 1000.0f, 5000.0f);
    func_8001D494(0, 45.0f, 80.0f, 6000.0f);
    omAddObj(0x13, 0, 0, -1, func_800FC7B0_BombsAway);
    omAddObj(0xC, 2, 0, -1, func_800FE254_BombsAway);
    omSetStatBit(omAddObj(0xC, 1, 0, -1, func_800FDB0C_BombsAway), 0xA0);
    func_800FD530_BombsAway();
    func_800FED18_BombsAway();
    func_800FCD04_BombsAway();
    func_800FC88C_BombsAway();
    file = DataRead(0x350013);
    image = func_800678A4(file);
    DataClose(file);
    D_80100B50_BombsAway = func_80064EF4(1, 0);
    func_80067208(D_80100B50_BombsAway, 0, image, 0);
    func_800674BC(D_80100B50_BombsAway, 0, 0x4000);
    func_80066DC4(D_80100B50_BombsAway, 0, 0xA0, 0x78);
    func_80067354(D_80100B50_BombsAway, 0, 2.0f, 2.2f);
    func_800674BC(D_80100B50_BombsAway, 0, 0x503C);
    D_80100780_BombsAway = 1;
    D_80100B6A_BombsAway = 0;
}
void func_800FC7B0_BombsAway(omObjData* obj) {
    obj->func_ptr = func_800FC7C0_BombsAway;
}
void func_800FC7C0_BombsAway(void) {
    func_800FCE0C_BombsAway();
    func_800FD540_BombsAway();
    func_800FEE2C_BombsAway();
    func_800FDD58_BombsAway();
}
void func_800FC7F4_BombsAway(void) {
    func_800FDC6C_BombsAway();
    func_800FD428_BombsAway();
}
void func_800FC818_BombsAway(void) {
    CRot.x = -22.0f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    Center.x = -5.0f;
    Center.y = 254.5f;
    Center.z = 1.0f;
    CZoom = 1378.0f;
}
void func_800FC88C_BombsAway(void) {
    CRot.x = 3.0f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    Center.x = -5.0f;
    Center.y = 86.5f;
    Center.z = 1.0f;
    CZoom = 2.5f;
}
void func_800FC8F8_BombsAway(omObjData* obj) {
    u16 model = obj->model[0];

    if (D_800FFAC0_BombsAway == 0) {
        D_80100790_BombsAway.unk_00.z += 25.0;
        D_80100790_BombsAway.unk_00.x -= 5.0;
        D_800FFAC2_BombsAway++;
        if (D_800FFAC2_BombsAway == 5) {
            func_800FE948_BombsAway(1500.0f, 500.0f, 1.0f, 0);
        }
        if (D_800FFAC2_BombsAway == 14) {
            func_800FE948_BombsAway(1500.0f, 500.0f, 1.0f, 0);
        }
        D_800FFAC4_BombsAway = 0x93;
        if (D_80100790_BombsAway.unk_00.z > 50.0) {
            D_80100790_BombsAway.unk_00.x = 500.0f;
            D_80100790_BombsAway.unk_00.z = -2250.0f;
            D_80100790_BombsAway.unk_0C.y = 0.0f;
            func_800FC818_BombsAway();
            CZoom = 1000.0f;
            func_800258EC(model, 4, 0);
            func_800258EC(model, 4, 0);
            D_800FFAC4_BombsAway = 0x3A;
            D_800FFAC0_BombsAway++;
            D_800FFAC2_BombsAway = 0;
        }
    } else if (D_800FFAC0_BombsAway == 1) {
        if (D_800FFAC2_BombsAway == 18) {
            func_800FD4B8_BombsAway(D_800FFAC8_BombsAway.x, D_800FFAC8_BombsAway.y, D_800FFAC8_BombsAway.z, 1.0f);
            func_800FC530_BombsAway(PlaySound(0x2B9), &D_800FFAC8_BombsAway);
        }
        if (D_800FFAC2_BombsAway == 27) {
            func_800FD4B8_BombsAway(D_800FFAD4_BombsAway.x, D_800FFAD4_BombsAway.y, D_800FFAD4_BombsAway.z, 1.0f);
            func_800FC530_BombsAway(PlaySound(0x2B9), &D_800FFAD4_BombsAway);
        }
        D_800FFAC2_BombsAway++;
        if (D_80100790_BombsAway.unk_28 > 0.0f) {
            D_80100790_BombsAway.unk_28 -= 8.0;
        }
        D_800FFAC4_BombsAway = (CZoom - 1000.0) / 378.0 * 9.0 / 1.5 + 58.0;
        if (CZoom < 1378.0) {
            CZoom += 12.5;
        } else if (CZoom > 1378.0) {
            D_800FFAC0_BombsAway++;
        }
    } else if (D_800FFAC0_BombsAway == 2) {
        if (D_80100790_BombsAway.unk_28 > 0.0f) {
            D_80100790_BombsAway.unk_28 -= 15.0;
        } else if (D_80100790_BombsAway.unk_28 <= 0.0f) {
            D_800FFAC0_BombsAway++;
        }
        D_800FFAC4_BombsAway = 0x40;
    }
    func_80066DC4(D_80100B50_BombsAway, 0, 0xA0, D_800FFAC4_BombsAway);
}
// operand order of the offset's or/addu (masked 0, raw 4; tried swapped or operands, a u16 offset local, tex += offset)
#ifdef NON_MATCHING
void func_800FCD04_BombsAway(void) {
    BaSplash* p;
    u8* file;
    u8* tex;
    u16 i;

    file = DataRead(0x35000E);
    D_80100B6C_BombsAway = file;
    /* A big-endian u16 offset at bytes 0xA/0xB: read as bytes on every host. */
    tex = ((file[0xA] << 8) | file[0xB]) + file;
    for (p = D_80100B70_BombsAway, i = 0; i < 6; i++, p++) {
        p->unk_04 = 0.0f;
        p->unk_28 = NULL;
        p->unk_04 = 0.0f;
        p->unk_08 = 0.0f;
        p->unk_02 = 0;
        p->unk_0C.x = p->unk_0C.y = p->unk_0C.z = 1.0f;
        p->unk_18.x = p->unk_18.y = p->unk_18.z = 0.0f;
        p->unk_28 = tex;
        /* 20 commands per buffered frame (func_800FCE0C): 0xA0 bytes on the N64. */
        p->unk_24 = func_80023684(D_800F37DA * (20 * sizeof(Gfx)), 0x7918);
        gSPEndDisplayList(p->unk_24);
        p->unk_00 = func_80024198(0xB1, p->unk_24, 4);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FCD04_BombsAway);
#endif
void func_800FCE0C_BombsAway(void) {
    BaSplash* p;
    Gfx* gfx;
    s16 frame;
    u16 i;

    if ((s16)++D_800FFB20_BombsAway >= D_800F37DA) {
        D_800FFB20_BombsAway = 0;
    }
    for (p = D_80100B70_BombsAway, i = 0; i < 6; i++, p++) {
        /* 20 commands per buffered frame (0xA0 bytes on the N64; func_800FCD04 allocates them). */
        gfx = &p->unk_24[(s16)D_800FFB20_BombsAway * 20];
        *D_800F2B7C[p->unk_00].unk_6C->unk_00 = gfx;
        if (p->unk_04 <= 0.0f) {
            gSPEndDisplayList(gfx++);
            continue;
        }
        if (p->unk_08 > 0.0f) {
            p->unk_04 -= p->unk_08;
        } else if (p->unk_08 < 0.0f) {
            p->unk_04 += p->unk_08;
        }
        frame = (u32)(16.0f - p->unk_04);
        if (frame < 0) {
            frame = 0;
        } else if (frame >= 16) {
            frame = 15;
        }
        func_80025798(p->unk_00, p->unk_18.x, p->unk_18.y, p->unk_18.z);
        func_80025830(p->unk_00, p->unk_0C.x, p->unk_0C.y, p->unk_0C.z);
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        gDPSetRenderMode(gfx++, 0x4049D8, 0);
        gDPSetCombine(gfx++, 0xFFFFFF, 0xFFFDF2F9);
        switch ((s16)p->unk_02) {
            case 1:
                gDPSetPrimColor(gfx++, 0, 0, 0xC8, 0xFF, 0xFF, 0xFF);
                break;
            case 2:
                gDPSetPrimColor(gfx++, 0, 0, 0x7D, 0xFF, 0xFF, 0xFF);
                break;
            case 0:
            default:
                gDPSetPrimColor(gfx++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
                break;
        }
        gDPLoadTextureBlock_4b(gfx++, p->unk_28 + (frame << 11), G_IM_FMT_I, 64, 64, 0, G_TX_CLAMP, G_TX_CLAMP,
                               G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPVertex(gfx++, D_800FFAE0_BombsAway, 4, 0);
        gSP1Triangle(gfx++, 0, 1, 2, 0);
        gSP1Triangle(gfx++, 3, 2, 1, 0);
        gDPPipeSync(gfx++);
        gSPEndDisplayList(gfx++);
        if (frame == 15) {
            func_80025798(p->unk_00, 0.0f, 0.0f, -30000.0f);
            func_80025830(p->unk_00, 0.0f, 0.0f, -30000.0f);
        }
        if (p->unk_08 > 0.0f) {
            if (p->unk_04 == 14.0f) {
                func_800FD364_BombsAway(p->unk_18.x, p->unk_18.y, p->unk_18.z - 25.0, p->unk_0C.x * 1.25, 16.0f,
                                        -p->unk_08, 1);
            }
            if (p->unk_04 == 12.0f) {
                func_800FD364_BombsAway(p->unk_18.x, p->unk_18.y, p->unk_18.z - 50.0, p->unk_0C.x * 1.5, 16.0f,
                                        -p->unk_08, 2);
            }
        }
    }
}
void func_800FD364_BombsAway(f32 x, f32 y, f32 z, f32 scale, f32 life, f32 b, u16 c) {
    BaSplash* p = D_80100B70_BombsAway;
    u16 i;

    for (i = 0; i < 6; i++, p++) {
        if (p->unk_04 <= 0.0f) {
            p->unk_04 = life;
            p->unk_08 = b;
            p->unk_02 = c;
            p->unk_18.x = x;
            p->unk_18.y = y;
            p->unk_18.z = z;
            p->unk_0C.x = scale;
            p->unk_0C.y = scale;
            p->unk_0C.z = 1.0f;
            func_80025798(p->unk_00, p->unk_18.x, p->unk_18.y, p->unk_18.z);
            func_80025830(p->unk_00, p->unk_0C.x, p->unk_0C.y, p->unk_0C.z);
            return;
        }
    }
}
void func_800FD428_BombsAway(void) {
    BaSplash* p = D_80100B70_BombsAway;
    u16 i;

    for (i = 0; i < 6; i++, p++) {
        func_800258EC(p->unk_00, 4, 4);
        func_80023728(p->unk_24);
        *D_800F2B7C[p->unk_00].unk_6C->unk_00 = NULL;
    }
    DataClose(D_80100B6C_BombsAway);
}
// decomp-permuter
void func_800FD4B8_BombsAway(f32 x, f32 y, f32 z, f32 scale)
{
  float new_var;
  new_var = ((f32) ((z + 2250.0) / 1500.0)) * scale;
  func_800FD364_BombsAway(x, y, z, new_var, 16.0f, 1.0f, 0);
}
void func_800FD530_BombsAway(void) {
    D_80100782_BombsAway = 1;
}
void func_800FD540_BombsAway(void) {
    s32 x;
    s32 x2;

    if (D_80100782_BombsAway == 1) {
        if (D_800FFAC0_BombsAway == 0) {
            return;
        }
        D_80100786_BombsAway = func_800FDE38_BombsAway(3, 0.0f, 1200.0f, 0.0f, 0.5f, -1, 0.5f);
        D_80100788_BombsAway = func_800FDE38_BombsAway(3, -500.0f, 1000.0f, 0.0f, 0.5f, -1, 0.5f);
        D_80100774_BombsAway = 90;
        D_80100776_BombsAway = 270;
        D_80100778_BombsAway = func_800FE1EC_BombsAway(360);
        D_8010077A_BombsAway = func_800FE1EC_BombsAway(360);
        if (D_80100776_BombsAway < 180) {
            D_8010077C_BombsAway = -1;
        } else {
            D_8010077C_BombsAway = 1;
        }
        if (D_80100774_BombsAway < 180) {
            D_8010077E_BombsAway = -1;
        } else {
            D_8010077E_BombsAway = 1;
        }
        D_80100770_BombsAway = 0.0f;
        D_80100782_BombsAway = 0;
    }
    if (D_800FFAC0_BombsAway == 1) {
        D_80100770_BombsAway += 0.5;
    } else {
        if ((D_80100774_BombsAway += func_800FE1EC_BombsAway(5)) > 360) {
            D_80100774_BombsAway -= 360;
        }
        if ((D_80100776_BombsAway += func_800FE1EC_BombsAway(5)) > 360) {
            D_80100776_BombsAway -= 360;
        }
        if ((D_80100778_BombsAway += func_800FE1EC_BombsAway(2)) > 360) {
            D_80100778_BombsAway -= 360;
        }
        if ((D_8010077A_BombsAway += func_800FE1EC_BombsAway(2)) > 360) {
            D_8010077A_BombsAway -= 360;
        }
    }
    if (D_8010077C_BombsAway > 0 && D_80100776_BombsAway < 180) {
        D_8010077C_BombsAway = -1;
        func_800672B0(D_80100786_BombsAway, 0, 0);
        func_800671DC(D_80100786_BombsAway, 0, 3);
    } else if (D_8010077C_BombsAway < 0 && D_80100776_BombsAway > 180) {
        D_8010077C_BombsAway = 1;
        func_800672B0(D_80100786_BombsAway, 0, 3);
    }
    if (D_8010077E_BombsAway > 0 && D_80100774_BombsAway < 180) {
        D_8010077E_BombsAway = -1;
        func_800672B0(D_80100788_BombsAway, 0, 0);
        func_800671DC(D_80100788_BombsAway, 0, 3);
    } else if (D_8010077E_BombsAway < 0 && D_80100774_BombsAway > 180) {
        D_8010077E_BombsAway = 1;
        func_800672B0(D_80100788_BombsAway, 0, 3);
    }
    x = (s16)(func_800AEAC0(D_80100774_BombsAway * 2) * 10.0f + 100.0f);
    func_80066DC4(D_80100786_BombsAway, 0, x,
                  (0.0f - func_800AEFD0(D_80100776_BombsAway) * 6.0f) + D_80100770_BombsAway);
    x2 = (s16)(func_800AEAC0(D_80100776_BombsAway * 2) * 10.0f + 140.0f);
    func_80066DC4(D_80100788_BombsAway, 0, x2,
                  (10.0f - func_800AEFD0(D_80100774_BombsAway) * 6.0f) + D_80100770_BombsAway);
    func_80067354(D_80100786_BombsAway, 0, func_800AEAC0(D_80100778_BombsAway) / 8.0f + 0.625,
                  func_800AEAC0(D_80100778_BombsAway) / 8.0f + 0.625);
    func_80067354(D_80100788_BombsAway, 0, func_800AEAC0(D_8010077A_BombsAway) / 8.0f + 0.625,
                  func_800AEAC0(D_8010077A_BombsAway) / 8.0f + 0.625);
}
void func_800FDB0C_BombsAway(omObjData* obj) {
    obj->func_ptr = func_800FDB78_BombsAway;
    *obj->model = func_800174C0(0x350001, 0x99);
    D_80100B40_BombsAway = *obj->model;
    func_80026040(*obj->model);
    func_800FF218_BombsAway(*obj->model);
}
void func_800FDB78_BombsAway(omObjData* obj) {
    func_800FF674_BombsAway(*obj->model, (u16)(D_800FFB22_BombsAway % 361), obj->model);
    func_80027C1C(*obj->model, D_800FFB24_BombsAway, D_800FFB28_BombsAway, 0x20, 0x20);
    if (func_8005FD5C() + D_800F64F8 == 0) {
        D_800FFB22_BombsAway++;
        D_800FFB24_BombsAway += 0.3;
    }
}
void func_800FDC6C_BombsAway(void) {
    func_800258EC(D_80100B40_BombsAway, 4, 4);
    func_80023728(D_80100B44_BombsAway);
}
void func_800FDCA0_BombsAway(void) {
    void* file;
    u16 i;

    for (i = 0; i < 32; i++) {
        D_80100990_BombsAway[i].unk_00 = -1;
        D_80100990_BombsAway[i].unk_02 = 0;
    }
    file = DataRead(0x35000F);
    D_80100B10_BombsAway[1] = func_800678A4(file);
    DataClose(file);
    file = DataRead(0x350011);
    D_80100B10_BombsAway[3] = func_800678A4(file);
    DataClose(file);
}
void func_800FDD58_BombsAway(void) {
    u16 i;
    s16 t;

    for (i = 0; i < 32; i++) {
        if (D_80100990_BombsAway[i].unk_04 <= 0x20) {
            if (D_80100990_BombsAway[i].unk_02 == 1) {
                func_80064D38(D_80100990_BombsAway[i].unk_00);
                D_80100990_BombsAway[i].unk_00 = -1;
            }
            if ((t = D_80100990_BombsAway[i].unk_02) > 0) {
                D_80100990_BombsAway[i].unk_02 = t - 1;
            }
        }
    }
}
// register allocation at entry: the kind test and the life argument, one nop (masked 3)
#ifdef NON_MATCHING
s16 func_800FDE38_BombsAway(s16 kind, f32 x, f32 y, f32 z, f32 scale, s16 life, f32 alpha) {
    u16 i;

    if ((u16)kind >= 33) {
        return 0;
    }
    if (alpha <= 0.0f) {
        return 0;
    }
    for (i = 0; i < 32; i++) {
        if (D_80100990_BombsAway[i].unk_02 != 0) {
            continue;
        }
        if (D_80100990_BombsAway[i].unk_00 != -1) {
            continue;
        }
        D_80100990_BombsAway[i].unk_02 = life;
        D_80100990_BombsAway[i].unk_04 = kind;
        D_80100990_BombsAway[i].unk_00 = func_80064EF4(1, 0);
        func_80067208(D_80100990_BombsAway[i].unk_00, 0, D_80100B10_BombsAway[kind], 0);
        func_80067284(D_80100990_BombsAway[i].unk_00, 0, alpha);
        if (kind != 3) {
            func_800672B0(D_80100990_BombsAway[i].unk_00, 0, 2);
        } else {
            func_800672B0(D_80100990_BombsAway[i].unk_00, 0, 3);
        }
        if (kind != 3) {
            func_800674BC(D_80100990_BombsAway[i].unk_00, 0, 0x100C);
        } else {
            func_800674BC(D_80100990_BombsAway[i].unk_00, 0, 0x503C);
        }
        if ((u16)kind < 2) {
            func_80067558(D_80100990_BombsAway[i].unk_00, 0, 0xFF, 0xFF, 0xFF, 0xFF);
        }
        func_80066DF4(D_80100990_BombsAway[i].unk_00, 0, 0, x, y, z);
        switch (kind) {
            case 0:
                D_80100990_BombsAway[i].unk_08 = scale * 0.6;
                break;
            case 1:
                D_80100990_BombsAway[i].unk_08 = scale * 0.5;
                break;
            case 2:
                D_80100990_BombsAway[i].unk_08 = scale * 0.08;
                break;
            case 3:
                D_80100990_BombsAway[i].unk_08 = scale;
                break;
        }
        func_80067354(D_80100990_BombsAway[i].unk_00, 0, D_80100990_BombsAway[i].unk_08,
                      D_80100990_BombsAway[i].unk_08);
        break;
    }
    return D_80100990_BombsAway[i].unk_00;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FDE38_BombsAway);
#endif
u16 func_800FE1EC_BombsAway(u32 n) {
    D_800FFB2C_BombsAway = (u32)(D_800FFB2C_BombsAway * 0x19971204 + 0x19760831) >> 16;
    if (n == 0) {
        return (u16)D_800FFB2C_BombsAway;
    }
    return (u32)D_800FFB2C_BombsAway % n;
}
void func_800FE254_BombsAway(omObjData* obj) {
    char names[4][8] = { "taihou1", "taihou2", "taihou3", "taihou4" };
    BaBomb* p;
    u16 i;
    s16 model;
    s16 m2;

    obj->func_ptr = func_800FE4A4_BombsAway;
    obj->model[0] = model = LoadFormFile(0x350002, 0x99);
    obj->model[1] = m2 = func_800174C0(0x350004, 0x99);
    obj->trans.x = obj->trans.z = 0.0f;
    obj->trans.y = -30.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    func_80025830(m2, obj->scale.x, obj->scale.y, obj->scale.z);
    D_80100790_BombsAway.unk_00.x = 150.0f;
    D_80100790_BombsAway.unk_00.y = -50.0f;
    D_80100790_BombsAway.unk_00.z = -2250.0f;
    D_80100790_BombsAway.unk_18 = -3.5f;
    D_80100790_BombsAway.unk_0C.x = 0.0f;
    D_80100790_BombsAway.unk_0C.y = 50.0f;
    D_80100790_BombsAway.unk_0C.z = 0.0f;
    for (p = D_801007E0_BombsAway, i = 0; i < 4; i++, p++) {
        p->unk_20 = func_800FBE34_BombsAway(model, names[i]);
        p->unk_08 = (Vec*)&p->unk_20->unk_44;
        p->unk_0C = (Vec*)&p->unk_20->unk_50;
        p->unk_00 = 3;
        p->unk_08->x = 0.0f;
        p->unk_0C->x = p->unk_0C->y = p->unk_0C->z = 1.0f;
    }
    D_800FFAC0_BombsAway = 0;
    D_800FFAC2_BombsAway = 0;
}
void func_800FE4A4_BombsAway(omObjData* obj) {
    BaBomb* p;
    unk2C0C0Struct50* n;
    f32(*m)[4];
    u16 model;
    u16 i;

    model = obj->model[1];
    func_800FC8F8_BombsAway(obj);
    if ((D_800FFB30_BombsAway += 2) >= 360) {
        D_800FFB30_BombsAway -= 360;
    }
    if ((D_800FFB32_BombsAway += 4) >= 360) {
        D_800FFB32_BombsAway -= 360;
    }
    D_80100790_BombsAway.unk_00.y = func_800AEAC0(D_800FFB30_BombsAway) * 10.0;
    D_80100790_BombsAway.unk_0C.z = func_800AEAC0(D_800FFB30_BombsAway) * 3.0f;
    if (D_800FFAC0_BombsAway != 0 && D_800FFAC0_BombsAway < 4) {
        if (D_80100790_BombsAway.unk_00.x > 300.0) {
            if (D_80100790_BombsAway.unk_00.x < 450.0) {
                D_80100790_BombsAway.unk_18 += 0.05;
            }
            if (D_80100790_BombsAway.unk_18 < 0.0f) {
                D_80100790_BombsAway.unk_00.x += D_80100790_BombsAway.unk_18;
            }
        }
    }
    omSetRot(obj, D_80100790_BombsAway.unk_0C.x, D_80100790_BombsAway.unk_0C.y, D_80100790_BombsAway.unk_0C.z);
    omSetTra(obj, D_80100790_BombsAway.unk_00.x, D_80100790_BombsAway.unk_00.y - 75.0,
             D_80100790_BombsAway.unk_00.z);
    func_800257E4(model, D_80100790_BombsAway.unk_0C.x, D_80100790_BombsAway.unk_0C.y,
                  D_80100790_BombsAway.unk_0C.z);
    func_80025798(model, D_80100790_BombsAway.unk_00.x, D_80100790_BombsAway.unk_00.y - 75.0,
                  D_80100790_BombsAway.unk_00.z);
    for (i = 0; i < 4; i++) {
        p = &D_801007E0_BombsAway[i];
        if (p->unk_08 == NULL) {
            continue;
        }
        switch (p->unk_00) {
            case 0:
                p->unk_08->x -= 2.0f;
                if (p->unk_08->x <= -30.0f) {
                    p->unk_08->x = -30.0f;
                    if (p->unk_04 == 0) {
                        if (p->unk_02 == 0) {
                            func_800FEA0C_BombsAway(i, p->unk_14, p->unk_1C, p->unk_10, 0);
                        }
                        p->unk_0C->z -= 0.1;
                        if (p->unk_02++ >= 3) {
                            p->unk_02 = 0;
                            p->unk_00 = 1;
                        }
                    } else {
                        p->unk_00 = 1;
                    }
                }
                break;
            case 1:
                if (p->unk_04 == 0) {
                    if (p->unk_0C->z < 1.0f) {
                        p->unk_0C->z += 0.1;
                    } else {
                        p->unk_00 = 2;
                        p->unk_02 = 0;
                    }
                } else {
                    func_800FEA0C_BombsAway(i, p->unk_14, p->unk_1C, p->unk_10, p->unk_04);
                    p->unk_08->x = -45.0f;
                    p->unk_00 = 2;
                }
                break;
            case 2:
                if ((p->unk_08->x += 2.0f) >= 0.0f) {
                    p->unk_08->x = 0.0f;
                    p->unk_00 = 3;
                }
                break;
            default:
                p->unk_02 = 0;
                break;
        }
    }
    for (i = 0; i < 4; i++) {
        n = D_801007E0_BombsAway[i].unk_20;
        m = n->unk_64;
        func_800A2A50(m);
        func_8009EA40(m, n->unk_08.x, n->unk_08.y, n->unk_08.z);
        MtxRotate(m, n->unk_44.x, n->unk_44.y, n->unk_44.z);
        MtxScale(m, n->unk_50.x, n->unk_50.y, n->unk_50.z);
    }
}
s32 func_800FE948_BombsAway(f32 x, f32 z, f32 y, u16 kind) {
    BaBomb* p;
    u16 i;

    for (i = 0; i < 4; i++) {
        if (++D_80100784_BombsAway >= 4) {
            D_80100784_BombsAway = 0;
        }
        p = &D_801007E0_BombsAway[D_80100784_BombsAway];
        if (p->unk_00 >= 2 && p->unk_02 == 0) {
            break;
        }
    }
    if (i < 4) {
        if (kind < 3) {
            p->unk_00 = 0;
            p->unk_02 = 0;
            p->unk_04 = kind;
            p->unk_10 = y;
            p->unk_14 = x;
            p->unk_1C = z;
            return 1;
        }
    }
    return 0;
}
// register allocation: the copy of n (masked 2)
#ifdef NON_MATCHING
void func_800FEA0C_BombsAway(s32 n, f32 tx, f32 tz, f32 speed, u16 kind) {
    BaShell* s;
    u16 i;
    f32 dx;
    f32 dz;

    for (s = D_80100870_BombsAway, i = 0; i < 6; i++, s++) {
        if ((u16)s->unk_00 == 0) {
            break;
        }
    }
    if (i < 6) {
        func_800FECA8_BombsAway(i, n);
        s->unk_1C = tx;
        s->unk_24 = tz;
        s->unk_28 = speed;
        s->unk_02 = kind;
        s->unk_04 += D_80100790_BombsAway.unk_00.x;
        s->unk_0C += D_80100790_BombsAway.unk_00.z;
        dx = s->unk_04 - s->unk_1C;
        dz = s->unk_0C - s->unk_24;
        if (dx != 0.0) {
            s->unk_10 = -(dx / 20.0f) * s->unk_28;
        } else {
            s->unk_10 = 0.0f;
        }
        s->unk_14 = 100.0f;
        if (dz != 0.0) {
            s->unk_18 = -(dz / 20.0f) * s->unk_28;
        } else {
            s->unk_18 = 0.0f;
        }
        s->unk_00 = 1;
        func_800258EC(D_80100B52_BombsAway[i], 4, 0);
        func_800258EC(D_80100B5E_BombsAway[i], 4, 0);
        PlaySound(0x2B8);
        if (s->unk_02 == 1) {
            func_800FDE38_BombsAway(1, s->unk_04 - 100.0, s->unk_08 + D_80100790_BombsAway.unk_00.y + 100.0,
                                    D_80100790_BombsAway.unk_00.z, 1.0f, 16, 1.0f);
        } else {
            func_800FDE38_BombsAway(1, s->unk_04, s->unk_08 + D_80100790_BombsAway.unk_00.y + 200.0,
                                    D_80100790_BombsAway.unk_00.z, 2.0f, 16, 1.0f);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FEA0C_BombsAway);
#endif
void func_800FECA8_BombsAway(u16 i, u16 n) {
    BaShell* s = &D_80100870_BombsAway[i];

    s->unk_00 = 0;
    s->unk_2C = 1.0f;
    s->unk_04 = n * 70.0;
    s->unk_08 = 0.0f;
    s->unk_0C = 0.0f;
    s->unk_10 = s->unk_14 = s->unk_18 = s->unk_0C;
}
void func_800FED18_BombsAway(void) {
    u16 i;

    for (i = 0; i < 6; i++) {
        if (i == 0) {
            D_80100B52_BombsAway[0] = func_800174C0(0x350005, 0x99);
            D_80100B5E_BombsAway[0] = func_800174C0(0x350007, 0x99);
        } else {
            D_80100B52_BombsAway[i] = func_80023FC8(D_80100B52_BombsAway[0]);
            D_80100B5E_BombsAway[i] = func_80023FC8(D_80100B5E_BombsAway[0]);
        }
        func_800258EC(D_80100B52_BombsAway[i], 4, 4);
        func_800258EC(D_80100B5E_BombsAway[i], 4, 4);
        func_800FECA8_BombsAway(i, 0);
    }
    D_80100784_BombsAway = 0xFF;
}
// retail computes a dead (z + 2250) / 150 that GCC deletes here, and keeps 0.0f in f22 across the loop
// (301 vs 286 instructions; calls, stores and the remaining code are identical)
#ifdef NON_MATCHING
void func_800FEE2C_BombsAway(void) {
    BaShell* s;
    f32 f;
    s32 hit;
    u16 i;

    for (i = 0; i < 6; i++) {
        s = &D_80100870_BombsAway[i];
        if ((u16)s->unk_00 != 0) {
            if (s->unk_04 > 2500.0) {
                func_800FECA8_BombsAway(i, 0);
                func_800258EC(D_80100B52_BombsAway[i], 4, 4);
                func_800258EC(D_80100B5E_BombsAway[i], 4, 4);
                continue;
            }
            if (s->unk_02 == 0 && s->unk_14 <= 0.0f) {
                func_800FECA8_BombsAway(i, 0);
                func_800258EC(D_80100B52_BombsAway[i], 4, 4);
                func_800258EC(D_80100B5E_BombsAway[i], 4, 4);
                continue;
            }
            hit = func_800FAB74_BombsAway((Vec*)&s->unk_04, (Vec*)&s->unk_10, (Vec*)&s->unk_04);
            if (hit != 0) {
                f = (s->unk_0C + 2250.0) / 150.0; /* retail computes this and never uses it */
                if (hit > 0) {
                    PlaySound(0x2BA);
                    func_800FADF4_BombsAway(s->unk_04, s->unk_0C, 1.0f);
                    func_80021EC0(2, s->unk_04, s->unk_08, s->unk_0C);
                    func_800F7850_BombsAway(8, s->unk_04, s->unk_08, s->unk_0C, 90.0f);
                } else {
                    func_800FC530_BombsAway(PlaySound(0x2B9), (Vec*)&s->unk_04);
                    func_800FADF4_BombsAway(s->unk_04, s->unk_0C, -1.0f);
                    func_800FD4B8_BombsAway(s->unk_04, 0.0f, s->unk_0C, 1.0f);
                }
                func_800FECA8_BombsAway(i, 0);
                func_800258EC(D_80100B52_BombsAway[i], 4, 4);
                func_800258EC(D_80100B5E_BombsAway[i], 4, 4);
            } else {
                s->unk_04 += s->unk_10;
                s->unk_08 += s->unk_14;
                s->unk_0C += s->unk_18;
                func_800F7850_BombsAway(1, s->unk_04, s->unk_08, s->unk_0C, 50.0f);
                if (s->unk_0C <= -750.0) {
                    s->unk_2C = -(750.0 / s->unk_0C);
                }
                s->unk_18 -= s->unk_28 * 0.1 * s->unk_28;
                s->unk_14 -= s->unk_28 * 10.0;
            }
        }
        f = s->unk_2C * 1.1 * 0.2 * 5.0;
        func_80025830(D_80100B52_BombsAway[i], f, f, f);
        func_80025830(D_80100B5E_BombsAway[i], f, f, f);
        func_80025798(D_80100B52_BombsAway[i], s->unk_04, s->unk_08, s->unk_0C);
        func_80025798(D_80100B5E_BombsAway[i], s->unk_04, 100.0f, s->unk_0C);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1B02A0", func_800FEE2C_BombsAway);
#endif
void func_800FF218_BombsAway(s16 model) {
    s16 xs[32];
    s16 zs[32];
    unk2C0C0StructC0* m;
    unk2C0C0StructE0* v;
    s16 nz;
    s16 nx;
    s16 i;
    s16 j;
    s16 n;

    m = D_800F2B7C[model].unk_6C;
    v = m->unk_04;
    nz = 0;
    nx = 0;
    i = 0;
    n = m->unk_72;
    for (i = 0; i < n; i++, v++) {
        for (j = 0; j < nx; j++) {
            if (xs[j] == v->unk_00) {
                break;
            }
        }
        if (j >= nx) {
            xs[nx] = v->unk_00;
            nx++;
        }
        for (j = 0; j < nz; j++) {
            if (zs[j] == v->unk_04) {
                break;
            }
        }
        if (j >= nz) {
            zs[nz] = v->unk_04;
            nz++;
        }
    }
    func_800FF9C4_BombsAway(xs, nx);
    func_800FF9C4_BombsAway(zs, nz);
    D_80100B44_BombsAway = func_80023684(n * 6, 0x7918);
    for (i = 0; i < n; i++) {
        D_80100B44_BombsAway[i].unk_00 = 1;
    }
    v = m->unk_04;
    for (i = 0; i < n; i++, v++) {
        for (j = 0; j < nx; j++) {
            if (xs[j] == v->unk_00) {
                break;
            }
        }
        if (j >= nx) {
            j = nx - 1;
        }
        D_80100B44_BombsAway[i].unk_02 = j;
        if (j == 0 || j == nx - 1) {
            D_80100B44_BombsAway[i].unk_00 = 0;
        }
    }
    v = m->unk_04;
    for (i = 0; i < n; i++, v++) {
        for (j = 0; j < nz; j++) {
            if (zs[j] == v->unk_04) {
                break;
            }
        }
        if (j >= nz) {
            j = nz - 1;
        }
        D_80100B44_BombsAway[i].unk_04 = j;
        if (j == 0 || j == nz - 1) {
            D_80100B44_BombsAway[i].unk_00 = 0;
        }
    }
    D_80100B48_BombsAway[0] = abs(xs[0] - xs[1]);
    D_80100B48_BombsAway[1] = abs(zs[0] - zs[1]);
}
void func_800FF674_BombsAway(s16 model, s32 angle, s16* unused) {
    unk2C0C0StructC0* m;
    BaVtxMap* map;
    unk2C0C0StructE0* src;
    unk2C0C0StructE0* dst;
    u16 n;
    s16 phase;
    u16 i;
    f32 a;
    f32 s1;
    f32 s2;
    f32 ax;
    f32 ay;
    f32 d;
    s32 pad[4]; /* unused: retail's frame is 16 bytes larger */

    phase = 0;
    m = D_800F2B7C[model].unk_6C;
    map = D_80100B44_BombsAway;
    src = m->unk_04;
    dst = m->unk_08[D_800F37F0];
    n = m->unk_72;
    a = angle;
    s1 = func_800AEAC0(a);
    s2 = func_800AEAC0(angle * 2);
    func_800AEAC0(a);
    ax = (f32)((u32)D_80100B48_BombsAway[0] / 6) * D_800F2B7C[model].unk_3C;
    ay = (f32)((u32)D_80100B48_BombsAway[0] / 10) * D_800F2B7C[model].unk_40;
    if (angle == 0) {
        phase++;
    }
    for (i = 0; i < n; src++, dst++, i++, map++) {
        if (map->unk_00 != 0) {
            d = s1 * ax;
            if (map->unk_04 & 1) {
                dst->unk_00 = src->unk_00 + d;
            } else {
                dst->unk_00 = src->unk_00 - d;
            }
            if (phase & 1) {
                if ((map->unk_02 & 1) && (map->unk_04 & 1)) {
                    dst->unk_02 = src->unk_02 + s2 * ay;
                } else if ((map->unk_02 + map->unk_04) & 1) {
                    dst->unk_02 = src->unk_02 - s2 * ay;
                } else {
                    dst->unk_02 = src->unk_02;
                }
            } else {
                if (!(map->unk_02 & 1) && !(map->unk_04 & 1)) {
                    dst->unk_02 = src->unk_02 + s2 * ay;
                } else if ((map->unk_02 & 1) && (map->unk_04 & 1)) {
                    dst->unk_02 = src->unk_02 - s2 * ay;
                } else {
                    dst->unk_02 = src->unk_02;
                }
            }
        } else {
            dst->unk_00 = src->unk_00;
            dst->unk_02 = src->unk_02;
            dst->unk_04 = src->unk_04;
        }
    }
}
void func_800FF9C4_BombsAway(s16* a, u16 n) {
    u16 i;
    u16 j;
    s16 t;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}