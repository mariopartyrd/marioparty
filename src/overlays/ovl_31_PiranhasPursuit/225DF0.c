#include "PiranhasPursuit.h"

u32 D_80100260_PiranhasPursuit = 0x19971204;
s32 D_80100264_PiranhasPursuit = 0;
Gfx D_80100268_PiranhasPursuit[] = {
    gsSPSegment(0x00, 0x00000000),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPPipelineMode(G_PM_1PRIMITIVE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0, 0),
    gsDPSetTileSize(1, 0, 0, 0, 0),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0000, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetDepthSource(G_ZS_PIXEL),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPNoOp(),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
Gfx D_80100320_PiranhasPursuit[] = {
    gsSPClearGeometryMode(0xFFFFFFFF),
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
    gsSPSetGeometryMode(G_SHADE | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};
Gfx D_80100340_PiranhasPursuit[] = {
    gsSPDisplayList(D_80100320_PiranhasPursuit),
    gsSPDisplayList(D_80100268_PiranhasPursuit),
    gsSPEndDisplayList(),
};
Gfx D_80100358_PiranhasPursuit[] = {
    gsDPPipeSync(),
    gsSPDisplayList(D_80100340_PiranhasPursuit),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPSetGeometryMode(G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x00),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0xFF),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPEndDisplayList(),
};
Gfx D_80100398_PiranhasPursuit[] = {
    gsDPPipeSync(),
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, 319, 239),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_SHADE | G_SHADING_SMOOTH),
    gsDPSetRenderMode(G_RM_AA_XLU_LINE, G_RM_AA_XLU_LINE2),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
s32 D_801003E8_PiranhasPursuit = 0;
f32 D_801003EC_PiranhasPursuit = 0.0f;
f32 D_801003F0_PiranhasPursuit = 0.72f;
s16 D_801003F4_PiranhasPursuit[2] = { 0, 0 };
f32 D_801003F8_PiranhasPursuit = 0.0f;
u16 D_801003FC_PiranhasPursuit = 0;
f32 D_80100400_PiranhasPursuit = 0.0f;
s16 D_80100404_PiranhasPursuit = 0;
s16 D_80100406_PiranhasPursuit = 0;
s16 D_80100408_PiranhasPursuit = 0;
s16 D_8010040A_PiranhasPursuit = 0;
s16 D_8010040C_PiranhasPursuit = 0;
s16 D_8010040E_PiranhasPursuit = 0;

/* A random step in [-1.75, 1.15] * 20. */
#define PP_RND() ((f32)((f32)func_800FA218_PiranhasPursuit(30) * 0.1 - 1.75) * 20.0f)

/* Turns an angle by func_800FA288 and keeps it in [0, 360]. */
#define PP_TURN(a, target, step)                                    \
    {                                                               \
        (a) = func_800FA288_PiranhasPursuit(target, a, step) + (a); \
        if ((a) > 360.0) {                                          \
            (a) = (a) - 360.0;                                      \
        } else if ((a) < 0.0) {                                     \
            (a) = (a) + 360.0;                                      \
        }                                                           \
    }

/* The course manager. */
void func_800FA0B0_PiranhasPursuit(void) {
    D_80101100_PiranhasPursuit = omAddObj(1, 0, 0, -1, func_800FA168_PiranhasPursuit);
    D_801012C8_PiranhasPursuit = 0;
    D_801012CC_PiranhasPursuit = 0;
    D_801012E6_PiranhasPursuit = 0;
    D_801012E8_PiranhasPursuit = D_801012EA_PiranhasPursuit = 1;
    D_801012CA_PiranhasPursuit = 0;
    D_8010110C_PiranhasPursuit = NULL;
    D_801012F0_PiranhasPursuit[0] = func_800FFBD8_PiranhasPursuit(0x450011);
    D_801012F0_PiranhasPursuit[2] = func_800FFBD8_PiranhasPursuit(0x450012);
    D_801012F0_PiranhasPursuit[3] = func_800FFBD8_PiranhasPursuit(0x450013);
}

void func_800FA168_PiranhasPursuit(omObjData* obj) {
    obj->func_ptr = func_800FA1B8_PiranhasPursuit;
    func_800FD6EC_PiranhasPursuit();
    func_800FA7E8_PiranhasPursuit();
    func_800FC5F0_PiranhasPursuit();
    func_800FFC1C_PiranhasPursuit();
    func_800FA4CC_PiranhasPursuit(obj);
}

void func_800FA1B8_PiranhasPursuit(omObjData* obj) {
    if (D_801012EA_PiranhasPursuit != 0) {
        func_801000A8_PiranhasPursuit();
    }
}

void func_800FA1E4_PiranhasPursuit(void) {
    func_800FB590_PiranhasPursuit();
    func_800FD674_PiranhasPursuit();
    func_801001C8_PiranhasPursuit();
    func_800FF450_PiranhasPursuit();
}

u16 func_800FA218_PiranhasPursuit(u16 n) {
    D_80100260_PiranhasPursuit = D_80100260_PiranhasPursuit * 0x19971204;
    D_80100260_PiranhasPursuit = (D_80100260_PiranhasPursuit + 0x19760831) >> 0x10;
    if (n == 0) {
        return D_80100260_PiranhasPursuit;
    } else {
        return D_80100260_PiranhasPursuit % n;
    }
}

/* The signed turn from cur towards target, at most step degrees. */
f32 func_800FA288_PiranhasPursuit(f32 target, f32 cur, f32 step) {
    f32 diff;

    if (target >= 360.0) {
        target -= 360.0;
    } else if (target < 0.0) {
        target += 360.0;
    }
    if (cur >= 360.0) {
        cur -= 360.0;
    } else if (cur < 0.0) {
        cur += 360.0;
    }
    diff = func_8009B618((target - cur) + 360.0, 360.0);
    if (diff < 180.0) {
        if (diff <= step) {
            return diff;
        }
        return step;
    }
    if (360.0 - diff <= step) {
        return -(360.0 - diff);
    }
    return -step;
}

void func_800FA3F0_PiranhasPursuit(s16 model, omObjData* obj) {
    if (!(D_800F2B7C[model].unk_20 & 4)) {
        func_80025798(model, obj->trans.x, obj->trans.y, obj->trans.z);
        func_800257E4(model, obj->rot.x, obj->rot.y, obj->rot.z);
        func_80025830(model, obj->scale.x, obj->scale.y, obj->scale.z);
    }
}

void func_800FA480_PiranhasPursuit(omObjData* dst, omObjData* src) {
    dst->trans.x = src->trans.x;
    dst->trans.y = src->trans.y;
    dst->trans.z = src->trans.z;
    dst->rot.x = src->rot.x;
    dst->rot.y = src->rot.y;
    dst->rot.z = src->rot.z;
    dst->scale.x = src->scale.x;
    dst->scale.y = src->scale.y;
    dst->scale.z = src->scale.z;
}

void func_800FA4CC_PiranhasPursuit(omObjData* obj) {
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    obj->rot.x = obj->rot.y = obj->rot.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
}

void func_800FA508_PiranhasPursuit(s16 model, s16 i, PPPlant* p, s16 end) {
    p->anim[i][0] = func_80025E48(model);
    p->anim[i][1] = func_80025D40(model);
    if (end != -1) {
        p->anim[i][2] = end;
    } else {
        p->anim[i][2] = p->anim[i][1];
    }
}

void func_800FA5DC_PiranhasPursuit(s16 model, s16* anim, s16 dir) {
    D_800F2B7C[model].unk_08 = anim[0];
    D_800F2B7C[model].unk_4C = 1.0f;
    if (dir >= 0) {
        D_800F2B7C[model].unk_0A = 0;
        D_800F2B7C[model].unk_48 = 0;
        D_800F2B7C[model].unk_50 = anim[1];
    } else {
        D_800F2B7C[model].unk_0A = 4;
        D_800F2B7C[model].unk_48 = anim[1];
        D_800F2B7C[model].unk_50 = 0;
    }
}

void func_800FA684_PiranhasPursuit(s16 model, s16* anim, s16 dir) {
    D_800F2B7C[model].unk_08 = anim[0];
    D_800F2B7C[model].unk_4C = 1.0f;
    if (dir >= 0) {
        D_800F2B7C[model].unk_0A = 2;
        D_800F2B7C[model].unk_48 = 0;
        D_800F2B7C[model].unk_50 = anim[2];
    } else {
        D_800F2B7C[model].unk_0A = 6;
        D_800F2B7C[model].unk_48 = anim[1];
        D_800F2B7C[model].unk_50 = anim[2];
    }
}

void func_800FA740_PiranhasPursuit(s16 model) {
    unk_ovl_2D_struct* m = &D_800F2B7C[model];

    if ((m->unk_0A & 2) && !(m->unk_20 & 4) && func_80025D40(model) <= m->unk_48) {
        m->unk_48 = m->unk_50;
    }
}

void func_800FA7C0_PiranhasPursuit(u16 frames) {
    D_801012E4_PiranhasPursuit = frames;
    D_801012E6_PiranhasPursuit++;
}

void func_800FA7E0_PiranhasPursuit(void) {
}

void func_800FA7E8_PiranhasPursuit(void) {
    omObjData* obj;

    D_801012D0_PiranhasPursuit = -16000.0f;
    D_801012D4_PiranhasPursuit = -16500.0f;
    D_801012DC_PiranhasPursuit = 20.1f;
    D_801012D8_PiranhasPursuit = 0;
    D_801012E0_PiranhasPursuit = 0;
    D_80101104_PiranhasPursuit = obj = omAddObj(1, 15, 0, -1, func_800FA878_PiranhasPursuit);
    omSetStatBit(obj, 0xA0);
}

/* The background: sky, two rows of trees, the course, and the scrolling horizon sprites. */
// NON_MATCHING: float constant registers, store order of the allocation
#ifdef NON_MATCHING
void func_800FA878_PiranhasPursuit(omObjData* obj) {
    PPPiece* p;
    s16 i;
    f32 f;
    unk65770AnimC* a;
    s16 g;

    obj->func_ptr = func_800FAEE8_PiranhasPursuit;
    obj->model[0] = func_800174C0(0x450000, 0x99);
    func_80026040(obj->model[0]);
    p = D_80101124_PiranhasPursuit = HuMemDirectMalloc(14 * sizeof(PPPiece));
    for (i = 0; i < 4; i++, p++) {
        if (i == 0) {
            obj->model[1] = func_800174C0(0x450006, 0x99);
        } else {
            obj->model[i + 1] = func_80023FC8(obj->model[1]);
        }
        p->unk0 = 1;
        p->unk2 = 0;
        if (i < 2) {
            p->pos.x = (i * 8.4 + (f32)func_800FA218_PiranhasPursuit(7) * 0.2 + -10.0) * 100.0 + -16000.0;
            p->pos.y = 0.0f;
            if (i & 1) {
                p->pos.z = -350.0f;
            } else {
                p->pos.z = -400.0f;
            }
            p->scale.x = (f32)(func_800FA218_PiranhasPursuit(31) + 90.0) * 0.014;
            f = func_800FA218_PiranhasPursuit(31) + 100.0;
        } else {
            p->pos.x = (i * 6.5 + (f32)func_800FA218_PiranhasPursuit(7) * 0.2 + -5.0) * 100.0 + -16000.0;
            p->pos.y = 0.0f;
            p->pos.z = -((i + 3) * 100);
            p->scale.x = (f32)(func_800FA218_PiranhasPursuit(31) + 90.0) * 0.014;
            f = func_800FA218_PiranhasPursuit(31) + 110.0;
        }
        p->scale.y = f * 0.012;
        p->scale.z = 1.0f;
        func_80025798(obj->model[i + 1], p->pos.x, p->pos.y, p->pos.z);
        func_80025830(obj->model[i + 1], p->scale.x, p->scale.y, p->scale.z);
    }
    for (i = 4; i < 14; i++, p++) {
        if (i == 4) {
            obj->model[5] = func_800174C0(0x450003, 0x99);
        } else if (i == 5) {
            obj->model[6] = func_800174C0(0x450004, 0x99);
        } else {
            obj->model[i + 1] = func_80023FC8((i & 1) ? obj->model[5] : obj->model[6]);
        }
        p->pos.x = (i * 2.8 + func_800FA218_PiranhasPursuit(7) * 0.2 + -64.0) * 100.0 + -16000.0;
        p->pos.y = 0;
        p->pos.z = -(func_800FA218_PiranhasPursuit(3) + 5.0) * 100.0 - (i - 4) * 10.0;
        p->scale.x = (f32)(func_800FA218_PiranhasPursuit(31) + 90) * 0.01;
        p->scale.y = (f32)(func_800FA218_PiranhasPursuit(31) + 110) * 0.01;
        p->scale.z = 1.0f;
    }
    D_80101130_PiranhasPursuit = HuMemDirectMalloc(30 * sizeof(s16));
    func_800FB5D4_PiranhasPursuit(D_80101130_PiranhasPursuit);
    for (i = 0; i < 2; i++) {
        g = func_80064EF4(1, 0);
        D_80101128_PiranhasPursuit[i] = g;
        func_80067208(g, 0, D_801012F0_PiranhasPursuit[0], 0);
        func_800674BC(D_80101128_PiranhasPursuit[i], 0, 0x503C);
        func_800672B0(D_80101128_PiranhasPursuit[i], 0, 0);
        func_80067354(D_80101128_PiranhasPursuit[i], 0, 2.0f, 2.2f);
        a = func_800675F4(D_80101128_PiranhasPursuit[i], 0)->unk4C->unk0;
        a->unk8 = a->unkA = 0;
    }
    func_80066DC4(D_80101128_PiranhasPursuit[0], 0, 0, 0);
    func_80066DC4(D_80101128_PiranhasPursuit[1], 0, 320, 0);
    func_800FA4CC_PiranhasPursuit(obj);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_PiranhasPursuit/225DF0", func_800FA878_PiranhasPursuit);
#endif

// NON_MATCHING: register allocation and block order
#ifdef NON_MATCHING
void func_800FAEE8_PiranhasPursuit(omObjData* obj) {
    PPPiece* p;
    f32 off;
    f32 t;
    f32 a;
    f32 v;
    f32 bx;
    s32 y;
    s32 n;
    s16 i;

    off = 0.0f;
    obj->trans.x = D_801012D0_PiranhasPursuit;
    func_80027C1C(obj->model[0], D_801012D0_PiranhasPursuit / (obj->scale.x * 24.0), 0.0f, 64, 64);
    p = D_80101124_PiranhasPursuit;
    for (i = 0; i < 14; i++, p++) {
        if (p->pos.x < obj->trans.x - 1500.0f) {
            p->pos.x = p->pos.x + 3000.0;
            func_80025798(obj->model[i + 1], p->pos.x, p->pos.y, p->pos.z);
            func_80025830(obj->model[i + 1], p->scale.x, p->scale.y, p->scale.z);
        }
    }
    func_800FBE00_PiranhasPursuit(D_80101130_PiranhasPursuit);
    if (func_8005FD5C() + D_800F64F8 == 0) {
        switch (D_801012E6_PiranhasPursuit) {
            case 0:
                y = -50;
                D_801012D4_PiranhasPursuit = -16000.0f;
                off = Center.x - -16000.0f;
                break;
            case 1:
                if (D_801003F4_PiranhasPursuit[0] < D_801012E4_PiranhasPursuit) {
                    t = (f32)(D_801003F4_PiranhasPursuit[0] + 1) / (f32)D_801012E4_PiranhasPursuit;
                    y = (s16)(-50.0f + t * (-5.0f - -50.0f)) + func_800AEAC0(t * 180.0) * 8.0;
                    D_801003F4_PiranhasPursuit[0]++;
                } else {
                    D_801012E6_PiranhasPursuit++;
                    y = -5;
                    D_801003F4_PiranhasPursuit[0] = 0;
                }
                off = Center.x - D_801012D4_PiranhasPursuit;
                break;
            case 2:
                y = -5;
                if (D_801012CA_PiranhasPursuit != 0 && D_801003F0_PiranhasPursuit >= 0.0) {
                    a = func_800AEAC0(D_801003EC_PiranhasPursuit) * D_801003F0_PiranhasPursuit * 100.0f;
                    D_801003F0_PiranhasPursuit = D_801003F0_PiranhasPursuit - 0.06;
                    D_801003E8_PiranhasPursuit++;
                    D_801003EC_PiranhasPursuit = func_8009B618(
                        D_801003EC_PiranhasPursuit + 64.0f + func_800AEAC0(D_801003E8_PiranhasPursuit * 15.0) * 96.0f,
                        360.0);
                    D_801012D4_PiranhasPursuit = a + D_8010112C_PiranhasPursuit[D_80101134_PiranhasPursuit].pos.x;
                } else if (D_8010112C_PiranhasPursuit[D_80101134_PiranhasPursuit].pos.x < D_801012D4_PiranhasPursuit) {
                    D_801012D4_PiranhasPursuit = D_8010112C_PiranhasPursuit[D_80101134_PiranhasPursuit].pos.x;
                } else {
                    off = Center.x - D_801012D4_PiranhasPursuit;
                }
                D_801003F4_PiranhasPursuit[0] = 0;
                break;
            default:
                D_801012D4_PiranhasPursuit = D_8010112C_PiranhasPursuit[D_80101134_PiranhasPursuit].pos.x;
                n = D_801012E4_PiranhasPursuit - 2;
                if (D_801003F4_PiranhasPursuit[0] < n) {
                    t = (f32)D_801003F4_PiranhasPursuit[0] / (f32)n;
                    if (t > 1.0) {
                        t = 1.0f;
                    }
                    y = -5.0f + t * (-40.0f - -5.0f);
                    D_801003F4_PiranhasPursuit[0]++;
                } else {
                    y = -40;
                }
                break;
        }
        obj->trans.x = D_801012D0_PiranhasPursuit;
        func_800F6C78_PiranhasPursuit(D_801012D4_PiranhasPursuit);
        v = off + D_801012D4_PiranhasPursuit;
        if (v < -16000.0) {
            v = v - -16000.0;
        } else if (v < 0.0) {
            v = v + 16000.0;
        }
        bx = -func_8009B618(v * 0.12, 320.0);
        if (bx < -320.0) {
            bx = -320.0f;
        } else if (bx > 0.0) {
            bx = bx - 320.0;
        }
        func_80066DC4(D_80101128_PiranhasPursuit[0], 0, bx, y);
        func_80066DC4(D_80101128_PiranhasPursuit[1], 0, bx + 320.0f, y);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_PiranhasPursuit/225DF0", func_800FAEE8_PiranhasPursuit);
#endif

void func_800FB590_PiranhasPursuit(void) {
    HuMemDirectFree(D_80101124_PiranhasPursuit);
    HuMemDirectFree(D_8010112C_PiranhasPursuit);
    HuMemDirectFree(D_80101130_PiranhasPursuit);
}

void func_800FB5C8_PiranhasPursuit(f32 x) {
    D_801012D0_PiranhasPursuit = x;
}

/* Builds the course: 23 pieces from the start (-15900) to the goal (16000). */
// NON_MATCHING: retail passes a running s16 piece index; abs() form
#ifdef NON_MATCHING
void func_800FB5D4_PiranhasPursuit(s16* models) {
    PPPiece* p;
    unk2C0C0StructE0* v;
    s32 d;
    s16 n;
    u16 i;

    n = 0;
    p = D_8010112C_PiranhasPursuit = HuMemDirectMalloc(25 * sizeof(PPPiece));
    for (i = 0; i < 25; i++, p++) {
        p->unk0 = 0;
        p->unk2 = 0;
        p->unk4 = 0;
        p->unk8 = 0;
        p->unkC = 0;
        p->pos.x = p->pos.y = p->pos.z = 0.0f;
        p->rot.x = p->rot.y = p->rot.z = 0.0f;
        p->scale.x = p->scale.y = p->scale.z = 1.0f;
        p->unk34 = p->unk38 = (&p->unk38)[1] = 0.0f;
    }
    models[0] = func_800174C0(0x450001, 0x9D);
    models[1] = func_800174C0(0x450002, 0x9D);
    models[2] = func_800174C0(0x450005, 0x9D);
    models[3] = func_800174C0(0x450007, 0x9D);
    models[4] = func_800174C0(0x3B0004, 0x9D);
    func_80026040(models[3]);
    v = D_800F2B7C[models[3]].unk_6C->unk_04;
    D_8010113C_PiranhasPursuit = 0;
    for (i = 0; i < D_800F2B7C[models[3]].unk_6C->unk_72; i++, v++) {
        d = v->unk_02;
        if (d < 0) {
            d = -d;
        }
        if (D_8010113C_PiranhasPursuit < d) {
            D_8010113C_PiranhasPursuit = d;
        }
    }
    p = D_8010112C_PiranhasPursuit;
    func_800FBB98_PiranhasPursuit(models, p++, -15900.0f, 6, n++);
    func_800FBB98_PiranhasPursuit(models, p++, -14000.0f, 1, n++);
    func_800FBB98_PiranhasPursuit(models, p++, -12000.0f, 1, n++);
    func_800FBB98_PiranhasPursuit(models, p++, -10000.0f, 3, n++);
    func_800FBB98_PiranhasPursuit(models, p++, -9000.0f, 4, n++);
    func_800FBB98_PiranhasPursuit(models, p++, -8400.0f, 1, n++);
    func_800FBB98_PiranhasPursuit(models, p++, -6000.0f, 2, n++);
    func_800FBB98_PiranhasPursuit(models, p++, -4000.0f, 3, n++);
    func_800FBB98_PiranhasPursuit(models, p++, -3400.0f, 4, n++);
    func_800FBB98_PiranhasPursuit(models, p++, -3000.0f, 2, n++);
    func_800FBB98_PiranhasPursuit(models, p++, 0.0f, 1, n++);
    func_800FBB98_PiranhasPursuit(models, p++, 1000.0f, 4, n++);
    func_800FBB98_PiranhasPursuit(models, p++, 4000.0f, 4, n++);
    func_800FBB98_PiranhasPursuit(models, p++, 4100.0f, 1, n++);
    func_800FBB98_PiranhasPursuit(models, p++, 6000.0f, 3, n++);
    func_800FBB98_PiranhasPursuit(models, p++, 8000.0f, 2, n++);
    func_800FBB98_PiranhasPursuit(models, p++, 9000.0f, 4, n++);
    func_800FBB98_PiranhasPursuit(models, p++, 12000.0f, 4, n++);
    func_800FBB98_PiranhasPursuit(models, p++, 12100.0f, 1, n++);
    func_800FBB98_PiranhasPursuit(models, p++, 14000.0f, 3, n++);
    func_800FBB98_PiranhasPursuit(models, p++, 15000.0f, 4, n++);
    func_800FBB98_PiranhasPursuit(models, p++, 15600.0f, 1, n++);
    D_80101134_PiranhasPursuit = 22;
    func_800FBB98_PiranhasPursuit(models, p, 16000.0f, 5, n);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_PiranhasPursuit/225DF0", func_800FB5D4_PiranhasPursuit);
#endif

void func_800FBB98_PiranhasPursuit(s16* models, PPPiece* p, f32 x, s16 type, s16 i) {
    p->unk0 = 1;
    p->pos.x = x;
    p->unk34 = x;
    p->unk2 = type;
    switch (type) {
        case 0:
            p->unk0 = 0;
            return;
        case 1:
            p->unk4 = 50.0f;
            models[5 + i] = func_80023FC8(models[0]);
            func_800258EC(models[5 + i], 4, 0);
            func_80025798(models[5 + i], p->pos.x, p->pos.y, p->pos.z);
            return;
        case 2:
            p->unk0 = 0;
            p->unk4 = 50.0f;
            p->pos.z = -300.0f;
            models[5 + i] = func_80023FC8(models[1]);
            func_800258EC(models[5 + i], 4, 0);
            func_80025798(models[5 + i], p->pos.x, p->pos.y, p->pos.z);
            return;
        case 3:
            p->scale.x = 0.9f;
            p->unk4 = 130.0f;
            p->unk38 = 50.0f;
            models[5 + i] = func_80023FC8(models[2]);
            func_800258EC(models[5 + i], 4, 0);
            func_80025798(models[5 + i], p->pos.x, p->pos.y, p->pos.z);
            return;
        case 4:
            p->unk4 = 5.0f;
            p->pos.y = 1070.0f;
            p->scale.x = p->scale.y = 1.3f;
            models[5 + i] = func_80023FC8(models[3]);
            func_800258EC(models[5 + i], 4, 0);
            func_80025798(models[5 + i], p->pos.x, p->pos.y, p->pos.z);
            func_80025830(models[5 + i], p->scale.x, p->scale.y, p->scale.z);
            return;
        case 5:
            p->unk4 = 0;
        case 6:
            models[5 + i] = func_80023FC8(models[4]);
            func_800258EC(models[5 + i], 4, 0);
            p->pos.y = -10.0f;
            p->rot.y = 270.0f;
            p->scale.x = 0.7f;
            p->scale.y = 0.7f;
            func_80025798(models[5 + i], p->pos.x, p->pos.y, p->pos.z);
            func_800257E4(models[5 + i], p->rot.x, p->rot.y, p->rot.z);
            func_80025830(models[5 + i], p->scale.x, p->scale.y, p->scale.z);
            return;
    }
}

/* Every frame: the logs bob on the waves, the trees fall when the runner comes near, and
   the far pieces are hidden. */
// NON_MATCHING: register allocation and loop shape
#ifdef NON_MATCHING
void func_800FBE00_PiranhasPursuit(s16* models) {
    s16 tbl[8] = { 85, 90, 85, 90, 85, 90, 87, 90 };
    f32 sx;
    f32 sy;
    f32 ang;
    unk2C0C0StructC0* c;
    unk2C0C0StructE0* src;
    unk2C0C0StructE0* dst;
    u16 n;
    u16 i;
    s16 d;
    PPPiece* p;

    if (D_801003F8_PiranhasPursuit > 0.0 && func_8005FD5C() + D_800F64F8 == 0) {
        if ((D_801003F4_PiranhasPursuit[1] += 5) >= 361) {
            D_801003F4_PiranhasPursuit[1] -= 360;
            D_801003F8_PiranhasPursuit = D_801003F8_PiranhasPursuit - 5.0;
        }
    }
    ang = func_800AEAC0(D_801003F4_PiranhasPursuit[1]) * D_801003F8_PiranhasPursuit;
    c = D_800F2B7C[models[3]].unk_6C;
    src = c->unk_04;
    dst = c->unk_08[D_800F37F0];
    n = c->unk_72;
    sx = func_800AEAC0(ang) * (f32)D_8010113C_PiranhasPursuit;
    sy = func_800AEFD0(ang) * (f32)D_8010113C_PiranhasPursuit;
    for (i = 0; i < n; i++, dst++, src++) {
        d = src->unk_02;
        if (d < 0) {
            d = -d;
        }
        dst->unk_00 = func_800AEAC0(ang) * (f32)d + (f32)src->unk_00;
        d = src->unk_02;
        if (d < 0) {
            d = -d;
        }
        dst->unk_02 = -(func_800AEFD0(ang) * (f32)d);
    }
    if (func_8005FD5C() + D_800F64F8 == 0) {
        p = D_8010112C_PiranhasPursuit;
        for (i = 0; i < 25; i++, p++) {
            if (p->unk2 == 0) {
                continue;
            }
            if (fabsf(p->pos.x - D_801012D0_PiranhasPursuit) > 1300.0f) {
                func_800258EC(models[5 + i], 4, 4);
            } else {
                func_800258EC(models[5 + i], 4, 0);
            }
            if (p->unk2 == 2) {
                if (D_8010110C_PiranhasPursuit != NULL && p->pos.x - 500.0 < D_8010110C_PiranhasPursuit->trans.x) {
                    if (p->unk8 == 0) {
                        if (p->rot.x == 0.0) {
                            p->unkC = p->unkC + 3.0;
                            p->rot.x = p->rot.x + p->unkC;
                            PlaySound(0x345);
                        } else if (p->rot.x < 90.0f) {
                            p->unkC = p->unkC + 3.0;
                            p->rot.x = p->rot.x + p->unkC;
                            if (p->rot.x > 80.0f) {
                                p->unk0 = 1;
                            }
                        } else if (p->rot.x >= 90.0f) {
                            p->unk8 = 1;
                        }
                        func_800257E4(models[5 + i], p->rot.x, p->rot.y, p->rot.z);
                    } else if (p->unk8 < 8) {
                        p->rot.x = tbl[p->unk8];
                        p->unk8++;
                        func_800257E4(models[5 + i], p->rot.x, p->rot.y, p->rot.z);
                    }
                }
            } else if (p->unk2 == 4) {
                p->unk34 = p->pos.x + sx * p->scale.x * 1.2;
                p->unk38 = p->pos.y - sy * p->scale.y * 1.2;
                p->unk8 = D_801003F4_PiranhasPursuit[1];
                if (p->unk0 == 2) {
                    D_801003F8_PiranhasPursuit = 40.0f;
                    D_801003F4_PiranhasPursuit[1] = 0;
                    p->unk0 = 3;
                } else if (p->unk0 == 3) {
                    if (p->pos.x + 1200.0 < D_801012D0_PiranhasPursuit &&
                        D_801012D0_PiranhasPursuit < p->pos.x + 1400.0) {
                        p->unk0 = 4;
                        D_801003F8_PiranhasPursuit = 0.0f;
                        D_801003F4_PiranhasPursuit[1] = 0;
                    }
                }
            }
        }
    }
}
#else
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_31_PiranhasPursuit/225DF0", D_801008A4_PiranhasPursuit);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_PiranhasPursuit/225DF0", func_800FBE00_PiranhasPursuit);
#endif

/* The nearest active piece to (x, y), never past the goal. */
PPPiece* func_800FC3F4_PiranhasPursuit(f32 x, f32 y) {
    PPPiece* p;
    f32 min;
    f32 d;
    u16 best;
    u16 i;

    best = 0;
    min = 10000.0f;
    p = D_8010112C_PiranhasPursuit;
    for (i = 0; i < 25; i++, p++) {
        d = fabs(x - p->pos.x) + fabs(y - p->pos.y);
        if (d < min && p->unk0 != 0) {
            min = d;
            best = i;
        }
    }
    if (best > D_80101134_PiranhasPursuit) {
        best = D_80101134_PiranhasPursuit;
    }
    if (D_801012CA_PiranhasPursuit != 0) {
        best = D_80101134_PiranhasPursuit;
    }
    return &D_8010112C_PiranhasPursuit[best];
}

s16 func_800FC4D0_PiranhasPursuit(omObjData* obj) {
    PPPiece* p;
    s16 i;

    p = D_8010112C_PiranhasPursuit;
    for (i = 0; (u16)i < 25; i++, p++) {
        if (p->unk0 != 0 && p->pos.x > obj->trans.x) {
            return i;
        }
    }
    return -1;
}

PPPiece* func_800FC52C_PiranhasPursuit(omObjData* obj) {
    PPPiece* p;
    f32 min;
    f32 d;
    u16 best;
    u16 i;

    best = 0;
    min = 10000.0f;
    p = D_8010112C_PiranhasPursuit;
    for (i = 0; i < 25; i++, p++) {
        d = fabsf(obj->trans.x - p->pos.x);
        if (d < min) {
            min = d;
            best = i;
        }
    }
    return &D_8010112C_PiranhasPursuit[best];
}

s16 func_800FC5A8_PiranhasPursuit(omObjData* obj) {
    D_8010110C_PiranhasPursuit = obj;
    if (D_801012C8_PiranhasPursuit == 0) {
        func_800FF470_PiranhasPursuit(obj, D_80101108_PiranhasPursuit);
    }
    return D_801012C8_PiranhasPursuit == 1;
}

/* The rain. */
void func_800FC5F0_PiranhasPursuit(void) {
    omObjData* obj;

    D_80101110_PiranhasPursuit = obj = omAddObj(3, 2, 0, -1, func_800FC638_PiranhasPursuit);
    omSetStatBit(obj, 0xA0);
}

void func_800FC638_PiranhasPursuit(omObjData* obj) {
    u16 i;

    obj->func_ptr = func_800FC7F0_PiranhasPursuit;
    D_80101120_PiranhasPursuit = HuMemDirectMalloc(64 * sizeof(PPDrop));
    for (i = 0; i < (u8)D_800F37DA; i++) {
        /* 132 commands (func_800FC9C4); 0x800 bytes on the N64 */
        D_80101114_PiranhasPursuit[i] = HuMemDirectMalloc(0x100 * sizeof(Gfx));
        func_800FCABC_PiranhasPursuit(D_80101120_PiranhasPursuit);
        func_800FC9C4_PiranhasPursuit(D_80101114_PiranhasPursuit[i], D_80101120_PiranhasPursuit, 0);
    }
    D_80101110_PiranhasPursuit->model[0] = func_80024198(0x1019, D_80101114_PiranhasPursuit[0], 4);
    D_80101110_PiranhasPursuit->model[1] = func_800174C0(0x450008, 0x99);
    func_80026040(D_80101110_PiranhasPursuit->model[1]);
    func_800258EC(D_80101110_PiranhasPursuit->model[1], 4, 4);
    func_80025830(D_80101110_PiranhasPursuit->model[1], 1.1f, 1.43f, 1.0f);
    for (i = 0; i < 4; i++) {
        D_80101110_PiranhasPursuit->work[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        D_80101140_PiranhasPursuit[i] = 0;
    }
    func_800FA4CC_PiranhasPursuit(obj);
}

void func_800FC7F0_PiranhasPursuit(omObjData* obj) {
    Gfx* g;

    obj->trans.x = D_801012D0_PiranhasPursuit;
    func_80027C1C(obj->model[1], 0.0f, D_80100400_PiranhasPursuit, 64, 64);
    if (func_8005FD5C() + D_800F64F8 == 0) {
        if (D_80101110_PiranhasPursuit->work[0] != 0) {
            func_800258EC(obj->model[1], 4, 0);
            func_80025798(obj->model[1], D_80101140_PiranhasPursuit[0] + obj->trans.x,
                          D_80101144_PiranhasPursuit + obj->trans.y, D_80101148_PiranhasPursuit + obj->trans.z);
            D_80100400_PiranhasPursuit = D_80100400_PiranhasPursuit - 5.0;
            D_80101110_PiranhasPursuit->work[0]--;
        } else {
            func_800258EC(obj->model[1], 4, 4);
        }
        D_801003FC_PiranhasPursuit++;
        if (D_801003FC_PiranhasPursuit >= (u8)D_800F37DA) {
            D_801003FC_PiranhasPursuit = 0;
        }
        g = D_80101114_PiranhasPursuit[D_801003FC_PiranhasPursuit];
        func_800FCE78_PiranhasPursuit(D_80101120_PiranhasPursuit, D_801003FC_PiranhasPursuit);
        func_800FC9C4_PiranhasPursuit(g, D_80101120_PiranhasPursuit, D_801003FC_PiranhasPursuit);
        *D_800F2B7C[obj->model[0]].unk_6C->unk_00 = g;
    }
}

void func_800FC9C4_PiranhasPursuit(Gfx* g, PPDrop* d, u16 frame) {
    s32 i;

    gSPDisplayList(g++, osVirtualToPhysical(D_80100358_PiranhasPursuit));
    gSPDisplayList(g++, osVirtualToPhysical(D_80100398_PiranhasPursuit));
    for (i = 0; i < 64; i++, d++) {
        gSPVertex(g++, d->v[frame], 2, 0);
        gSPLine3D(g++, 0, 1, 0);
    }
    gDPPipeSync(g++);
    gSPEndDisplayList(g++);
}

// NON_MATCHING: Vtx field store order
#ifdef NON_MATCHING
void func_800FCABC_PiranhasPursuit(PPDrop* d) {
    Vtx* v;
    f32 s;
    u16 i;
    u16 j;

    for (i = 0; i < 64; i++, d++) {
        d->unk0 = 1;
        d->state = 1;
        d->x = func_800FA218_PiranhasPursuit(1400) + -600.0;
        d->y = func_800FA218_PiranhasPursuit(1320) + -0.0;
        d->z = func_800FA218_PiranhasPursuit(800) + -200.0;
        d->depth = (d->z - -200.0) / 800.0;
        if (d->depth > 1.0) {
            d->depth = 1.0f;
        } else if (d->depth < 0.0) {
            d->depth = 0.0f;
        }
        d->len = (f32)func_800FA218_PiranhasPursuit(50) * 0.01 + 1.5;
        s = (f32)func_800FA218_PiranhasPursuit(40) * 0.01 + 1.0;
        d->vx = s * 20.0;
        d->vy = s * 80.0;
        for (j = 0; j < (u8)D_800F37DA; j++) {
            v = d->v[j];
            v[0].v.ob[0] = d->x;
            v[0].v.ob[1] = d->y;
            v[0].v.ob[2] = d->z;
            v[0].v.flag = 0;
            v[0].v.tc[0] = 0; /* retail leaves tc[1] */
            v[0].v.cn[0] = 0xF0;
            v[0].v.cn[1] = 0xF0;
            v[0].v.cn[2] = 0xFF;
            v[0].v.cn[3] = d->depth * 100.0 + 120.0;
            v[1].v.ob[0] = v[0].v.ob[0] + d->len * 20.0;
            v[1].v.ob[1] = v[0].v.ob[1] + d->len * 80.0;
            v[1].v.ob[2] = 0;
            v[1].v.flag = 0;
            v[1].v.tc[0] = 0; /* retail leaves tc[1] */
            v[1].v.cn[0] = 0xB4;
            v[1].v.cn[1] = 0xB4;
            v[1].v.cn[2] = 0xFF;
            v[1].v.cn[3] = 0;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_PiranhasPursuit/225DF0", func_800FCABC_PiranhasPursuit);
#endif

// NON_MATCHING: Vtx field store order, register allocation
#ifdef NON_MATCHING
void func_800FCE78_PiranhasPursuit(PPDrop* d, u16 frame) {
    Vtx* v;
    f32 s;
    f32 f;
    u16 i;

    for (i = 0; i < 64; i++, d++) {
        if (d->state == 1) {
            d->x = d->x - (d->vx + D_801012E0_PiranhasPursuit);
            d->y = d->y - d->vy;
            d->len = d->len + 0.05;
            if (d->y <= -80.0) {
                d->state = 0;
                d->len = 0.5f;
                d->y = -0.0f;
            }
        } else {
            d->x = d->x - (d->vx + D_801012E0_PiranhasPursuit);
            d->y = (f64)d->y + (f64)d->vy;
            if (d->y >= 160.0) {
                d->state = 1;
                d->x = func_800FA218_PiranhasPursuit(1400) + -600.0;
                d->y = func_800FA218_PiranhasPursuit(240) + 660.0;
                d->z = func_800FA218_PiranhasPursuit(800) + -200.0;
                d->depth = (d->z - -200.0) / 800.0;
                if (d->depth > 1.0) {
                    d->depth = 1.0f;
                } else if (d->depth < 0.0) {
                    d->depth = 0.0f;
                }
                d->len = (f32)func_800FA218_PiranhasPursuit(50) * 0.01 + 1.5;
                s = (f32)func_800FA218_PiranhasPursuit(40) * 0.01 + 1.0;
                d->vx = s * 20.0;
                d->vy = s * 80.0;
            }
        }
        v = d->v[frame];
        if (d->state == 1) {
            v[0].v.ob[0] = d->x;
            v[0].v.ob[1] = d->y;
            v[0].v.ob[2] = d->z;
            v[0].v.cn[3] = d->depth * 100.0 + 120.0;
            f = 1.0 - 0.0015151515f * d->y;
            if (f > 1.0) {
                f = 1.0f;
            } else if (f < 0.0) {
                f = 0.0f;
            }
            v[0].v.cn[3] -= (u8)(f * 100.0);
            v[1].v.ob[0] = v[0].v.ob[0] + d->len * 20.0;
            v[1].v.ob[1] = v[0].v.ob[1] + d->len * 80.0;
            v[1].v.ob[2] = v[0].v.ob[2];
            v[1].v.cn[3] = 0;
            if (v[1].v.ob[0] < v[0].v.ob[0]) {
                v[1].v.ob[0] = v[1].v.ob[0] + 2.0 * (d->len * 20.0);
            }
        } else {
            v[0].v.ob[0] = d->x;
            v[0].v.ob[1] = d->y;
            v[0].v.ob[2] = d->z;
            v[0].v.cn[3] = d->depth * 100.0 + 20.0;
            v[1].v.ob[0] = v[0].v.ob[0] + d->len * 20.0;
            v[1].v.ob[1] = v[0].v.ob[1] - d->len * 80.0;
            v[1].v.ob[2] = v[0].v.ob[2];
            v[1].v.cn[3] = 0;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_PiranhasPursuit/225DF0", func_800FCE78_PiranhasPursuit);
#endif

/* A splash where the runner lands in the water; close to the plant it makes it lunge. */
// NON_MATCHING: retail loads the plant pointer and struct address before PlaySound
#ifdef NON_MATCHING
void func_800FD4BC_PiranhasPursuit(f32 x, f32 y) {
    f32 dx;
    f32 px;

    dx = x - D_801012D0_PiranhasPursuit;
    PlaySound(0x347);
    if (D_80101110_PiranhasPursuit->work[0] == 0) {
        D_80101110_PiranhasPursuit->work[0] = 15;
        D_80101140_PiranhasPursuit[0] = dx;
        D_80101144_PiranhasPursuit = y;
        D_80101148_PiranhasPursuit = 20.0f;
        px = D_80101108_PiranhasPursuit->trans.x - D_801012D0_PiranhasPursuit;
        if ((dx <= px + (f32)(3.0 - D_80101108_PiranhasPursuit->scale.x) * 200.0) & (px < dx)) {
            if (D_8010114C_PiranhasPursuit == 0.0) {
                D_8010114C_PiranhasPursuit = 1.0f;
                if (D_80101150_PiranhasPursuit.unk1C <= 0.0) {
                    D_80101150_PiranhasPursuit.unk1C = 400.0f;
                } else {
                    D_80101150_PiranhasPursuit.unk1C = D_80101150_PiranhasPursuit.unk1C + 400.0;
                }
                if (D_80101150_PiranhasPursuit.unk1C > 600.0) {
                    D_80101150_PiranhasPursuit.unk1C = 600.0f;
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_PiranhasPursuit/225DF0", func_800FD4BC_PiranhasPursuit);
#endif

void func_800FD674_PiranhasPursuit(void) {
    u16 i;

    HuMemDirectFree(D_80101120_PiranhasPursuit);
    for (i = 0; i < (u8)D_800F37DA; i++) {
        HuMemDirectFree(D_80101114_PiranhasPursuit[i]);
    }
}

/* The Piranha Plant. */
void func_800FD6EC_PiranhasPursuit(void) {
    D_80101108_PiranhasPursuit = omAddObj(2, 8, 0, -1, func_800FD728_PiranhasPursuit);
}

// NON_MATCHING: retail addresses the plant fields by their splat labels
#ifdef NON_MATCHING
void func_800FD728_PiranhasPursuit(omObjData* obj) {
    obj->func_ptr = func_800FD9D0_PiranhasPursuit;
    obj->model[0] = LoadFormFile(0x45000A, 0x9D);
    obj->model[1] = LoadFormFile(0x45000B, 0x9D);
    obj->model[2] = LoadFormFile(0x45000C, 0x9D);
    obj->model[3] = LoadFormFile(0x45000D, 0x9D);
    obj->model[4] = LoadFormFile(0x45000E, 0x9D);
    obj->model[5] = LoadFormFile(0x45000F, 0x9D);
    obj->model[6] = LoadFormFile(0x450010, 0x9D);
    obj->model[7] = LoadFormFile(6, 0x99);
    func_800FA508_PiranhasPursuit(obj->model[0], 0, &D_80101150_PiranhasPursuit, 0);
    func_800FA508_PiranhasPursuit(obj->model[1], 1, &D_80101150_PiranhasPursuit, -1);
    func_800FA508_PiranhasPursuit(obj->model[2], 2, &D_80101150_PiranhasPursuit, 0x6E);
    func_800FA508_PiranhasPursuit(obj->model[3], 3, &D_80101150_PiranhasPursuit, -1);
    func_800FA508_PiranhasPursuit(obj->model[4], 4, &D_80101150_PiranhasPursuit, -1);
    func_800FA508_PiranhasPursuit(obj->model[5], 5, &D_80101150_PiranhasPursuit, 0);
    func_800FA508_PiranhasPursuit(obj->model[6], 6, &D_80101150_PiranhasPursuit, -1);
    func_800FEF78_PiranhasPursuit(obj, 0, 1);
    D_800F2B7C[obj->model[0]].unk_4C = 0.0f;
    D_80101150_PiranhasPursuit.state = 0;
    D_801012C4_PiranhasPursuit = func_8002040C(obj->model[4], 2, "pa_tst6-item_fook");
    func_800FA4CC_PiranhasPursuit(obj);
    obj->scale.x = obj->scale.y = obj->scale.z = 0.5f;
    obj->trans.x = -16700.0f;
    obj->trans.y = -80.0f;
    obj->rot.y = 89.0f;
    D_80101150_PiranhasPursuit.timer = 0;
    D_80101150_PiranhasPursuit.unk10 = 0;
    D_80101150_PiranhasPursuit.unk22 = 0;
    D_80101150_PiranhasPursuit.unk2E = 0;
    D_80101150_PiranhasPursuit.unk24 = D_80101150_PiranhasPursuit.unk28 = 0.5f;
    D_80101150_PiranhasPursuit.unk2C = 0;
    D_80101150_PiranhasPursuit.unk14 = obj->trans.x;
    D_80101150_PiranhasPursuit.unk18 = D_80101150_PiranhasPursuit.unk1C = 0.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_PiranhasPursuit/225DF0", func_800FD728_PiranhasPursuit);
#endif

// NON_MATCHING: retail addresses the plant fields by their splat labels; register allocation
#ifdef NON_MATCHING
void func_800FD9D0_PiranhasPursuit(omObjData* obj) {
    unk_ovl_2D_struct* m;
    unk_ovl_2D_struct* pm;
    PPWork* tw;
    omObjData* tgt;
    f32* mtx;
    f32 frame;
    f32 t;
    f32 spd;
    s32 moving;
    s32 lim;
    s16 i;
    u16 idx;

    obj->trans.x = D_80101150_PiranhasPursuit.unk14 + D_80101150_PiranhasPursuit.unk18;
    moving = 0;
    switch (D_80101150_PiranhasPursuit.state) {
        case 0:
            obj->trans.x = -16700.0f;
            D_80101150_PiranhasPursuit.unk14 = -16700.0f;
            if (D_80101150_PiranhasPursuit.timer < 10) {
                D_80101150_PiranhasPursuit.timer++;
            } else if (D_80101150_PiranhasPursuit.timer == 10) {
                func_800FEF78_PiranhasPursuit(obj, 4, 1);
                D_800F2B7C[obj->model[4]].unk_48 = 49.0f;
                D_80101150_PiranhasPursuit.timer++;
            } else if (D_80101150_PiranhasPursuit.timer < 20) {
                D_800F2B7C[obj->model[0]].unk_4C = 1.0f;
                D_80101150_PiranhasPursuit.timer++;
                if (++D_80101150_PiranhasPursuit.unk22 >= 5) {
                    D_80101150_PiranhasPursuit.unk22 = 0;
                }
                obj->rot.y = func_800AEAC0((f32)D_80101150_PiranhasPursuit.unk22 * 18.0) * 60.0 + 89.0;
                if (D_801012CC_PiranhasPursuit == 0) {
                    if (D_80101150_PiranhasPursuit.timer == 12) {
                        func_800FFCD8_PiranhasPursuit(2, obj->trans.x - 30.0, -10.0f, obj->trans.z, 8);
                        func_800FFCD8_PiranhasPursuit(2, obj->trans.x - 24.0, -10.0f, obj->trans.z, 8);
                        PlaySound(0x359);
                    } else {
                        func_800FFCD8_PiranhasPursuit(2, obj->trans.x - PP_RND(), -10.0f, obj->trans.z, 8);
                        if (D_80101150_PiranhasPursuit.timer & 1) {
                            func_800FFCD8_PiranhasPursuit(2, obj->trans.x - PP_RND(), -10.0f, obj->trans.z, 8);
                        }
                        if (D_80101150_PiranhasPursuit.timer & 3) {
                            t = PP_RND();
                            func_800FFCD8_PiranhasPursuit(3, t + obj->trans.x, -PP_RND() * 0.5, obj->trans.z, 8);
                        }
                    }
                }
            } else if (D_80101150_PiranhasPursuit.timer == 20) {
                obj->trans.y = obj->trans.y + 1.6;
                if (++D_80101150_PiranhasPursuit.unk22 >= 11) {
                    D_80101150_PiranhasPursuit.unk22 = 0;
                }
                obj->rot.y = func_800AEAC0((f32)D_80101150_PiranhasPursuit.unk22 * 18.0) * 60.0 + 89.0;
                m = &D_800F2B7C[obj->model[4]];
                if (m->unk_48 >= 124.0) {
                    m->unk_48 = 0.0f;
                    func_800FEF78_PiranhasPursuit(obj, 0, 1);
                    D_800F2B7C[obj->model[0]].unk_4C = 0.25f;
                    D_801012CC_PiranhasPursuit = 1;
                }
                if (obj->trans.y >= -30.0) {
                    obj->trans.y = -30.0f;
                    D_80101150_PiranhasPursuit.unk22 = 0;
                    D_800F2B7C[obj->model[0]].unk_4C = 1.0f;
                    D_80101150_PiranhasPursuit.timer++;
                }
                if (D_801012CC_PiranhasPursuit == 0) {
                    func_800FFCD8_PiranhasPursuit(2, PP_RND() + obj->trans.x, -10.0f, obj->trans.z, 8);
                    if (D_80101150_PiranhasPursuit.unk22 & 1) {
                        func_800FFCD8_PiranhasPursuit(2, obj->trans.x - PP_RND(), -10.0f, obj->trans.z, 8);
                    }
                    if (D_80101150_PiranhasPursuit.unk22 & 3) {
                        t = PP_RND();
                        func_800FFCD8_PiranhasPursuit(3, t + obj->trans.x, -PP_RND() * 0.5, obj->trans.z, 8);
                    }
                }
            } else {
                if (++D_80101150_PiranhasPursuit.timer == 22) {
                    if (++D_80101150_PiranhasPursuit.unk22 < 10) {
                        func_80017C0C(D_800F3FB0[0], 4, obj->trans.x - 80.0, obj->trans.y, obj->trans.z, 0.0f, 0.0f);
                    }
                } else if (D_80101150_PiranhasPursuit.timer >= 29) {
                    D_80101150_PiranhasPursuit.timer = 21;
                }
                if (D_8010110C_PiranhasPursuit != NULL && D_801012E6_PiranhasPursuit == 2) {
                    obj->trans.y = -30.0f;
                    obj->rot.y = 89.0f;
                    D_80101150_PiranhasPursuit.unk22 = 0;
                    D_80101150_PiranhasPursuit.timer = 0;
                    D_80101150_PiranhasPursuit.state = 1;
                    D_801012EA_PiranhasPursuit = 0;
                }
            }
            break;
        case 1:
            moving = 1;
            obj->trans.y = -30.0f;
            D_80101150_PiranhasPursuit.timer++;
            lim = 30;
            if (D_80101150_PiranhasPursuit.unk22 < 4) {
                lim = 60;
            }
            if (D_80101150_PiranhasPursuit.timer >= lim) {
                func_800FEF78_PiranhasPursuit(obj, 3, 0);
                D_80101150_PiranhasPursuit.state = 4;
                D_80101150_PiranhasPursuit.timer = 0;
                if (++D_80101150_PiranhasPursuit.unk22 >= 4) {
                    D_80101150_PiranhasPursuit.unk22 = 0;
                }
            }
            if (D_8010110C_PiranhasPursuit != NULL) {
                if (D_8010110C_PiranhasPursuit->trans.x < obj->trans.x) {
                    PP_TURN(obj->rot.y, 271.0f, 20.0f);
                } else if (obj->rot.y != 89.0) {
                    PP_TURN(obj->rot.y, 89.0f, 20.0f);
                }
                if (D_8010110C_PiranhasPursuit->trans.x < obj->trans.x + 100.0f) {
                    func_800FEF78_PiranhasPursuit(obj, 3, 0);
                    D_80101150_PiranhasPursuit.state = 4;
                    D_80101150_PiranhasPursuit.timer = 0;
                    if (++D_80101150_PiranhasPursuit.unk22 >= 4) {
                        D_80101150_PiranhasPursuit.unk22 = 0;
                    }
                }
            }
            func_800FF0C0_PiranhasPursuit(obj);
            break;
        case 2:
            D_80101150_PiranhasPursuit.timer++;
            obj->trans.y += D_80101150_PiranhasPursuit.unk10;
            D_80101150_PiranhasPursuit.unk10 = D_80101150_PiranhasPursuit.unk10 - 4.0;
            moving = 1;
            if (obj->trans.y < 0.0) {
                D_80101150_PiranhasPursuit.unk10 = 0.0f;
                obj->trans.y = 0.0f;
                func_800FEF78_PiranhasPursuit(obj, 0, 1);
                D_80101150_PiranhasPursuit.state = 1;
            }
            func_800FF0C0_PiranhasPursuit(obj);
            break;
        case 3:
            if (obj->trans.y > 0.0) {
                obj->trans.y = obj->trans.y - 20.0;
            } else if (obj->trans.y < 0.0) {
                obj->trans.y = 0.0f;
            }
            break;
        case 4:
            obj->trans.y = -30.0f;
            m = &D_800F2B7C[obj->model[3]];
            moving = 1;
            if (m->unk_50 <= m->unk_48) {
                func_800FEF78_PiranhasPursuit(obj, 0, 1);
                D_80101150_PiranhasPursuit.state = 1;
            }
            tgt = D_8010110C_PiranhasPursuit;
            if (tgt != NULL) {
                if (tgt->trans.x < obj->trans.x) {
                    PP_TURN(obj->rot.y, 271.0f, 20.0f);
                } else if (obj->rot.y != 89.0) {
                    PP_TURN(obj->rot.y, 89.0f, 20.0f);
                }
            }
            if (tgt != NULL && D_801012C8_PiranhasPursuit != 0) {
                func_800FEF78_PiranhasPursuit(obj, 4, 0);
                D_800F2B7C[obj->model[4]].unk_48 = 24.0f;
                D_80101150_PiranhasPursuit.state = 5;
                if (D_80100406_PiranhasPursuit == 0 && func_800184BC(D_8010110C_PiranhasPursuit, 0x23) != 0) {
                    D_80100406_PiranhasPursuit = 1;
                }
            }
            if (D_801012C8_PiranhasPursuit == 0) {
                func_800FF0C0_PiranhasPursuit(obj);
            }
            break;
        case 5:
            pm = &D_800F2B7C[D_8010110C_PiranhasPursuit->model[0]];
            tw = D_8010110C_PiranhasPursuit->unk_50;
            frame = D_800F2B7C[obj->model[4]].unk_48;
            obj->trans.y = -((obj->scale.y - 0.5) * 100.0 * 0.3);
            PP_TURN(obj->rot.y, 89.0f, 20.0f);
            if (D_80100406_PiranhasPursuit == 0 && func_800184BC(D_8010110C_PiranhasPursuit, 0x23) != 0) {
                D_80100406_PiranhasPursuit = 1;
            }
            if (frame >= 246.0f) {
                D_80101150_PiranhasPursuit.state = 6;
                func_800A2A50(pm->unk7C);
                omSetTra(D_8010110C_PiranhasPursuit, obj->trans.x + obj->scale.x * 200.0,
                         obj->trans.y + obj->scale.y * 50.0, 0.0f);
                omSetRot(D_8010110C_PiranhasPursuit, 0.0f, 90.0f, 300.0f);
                func_800FA3F0_PiranhasPursuit(D_8010110C_PiranhasPursuit->model[0], D_8010110C_PiranhasPursuit);
                D_80101150_PiranhasPursuit.unk22 = 0;
                D_80101150_PiranhasPursuit.unk10 = -100.0f;
            } else {
                if ((frame >= 96.0f) & (frame <= 98.0f)) {
                    PlaySound(0x351);
                }
                func_800FA480_PiranhasPursuit(D_8010110C_PiranhasPursuit, obj);
                omSetSca(D_8010110C_PiranhasPursuit, 1.0f, 1.0f, 1.0f);
                idx = frame * 0.5;
                func_8002C37C(pm->unk7C, D_801012C4_PiranhasPursuit->unk_08[idx]);
                switch (GwPlayer[tw->unk_58].character) {
                    case 0:
                        MtxRotateX(pm->unk7C, -45.0f);
                        break;
                    case 1:
                        MtxRotateX(pm->unk7C, -60.0f);
                        MtxTranslate(pm->unk7C, 0.0f, 40.0f, 20.0f);
                        break;
                    case 2:
                        MtxRotateX(pm->unk7C, 270.0f);
                        MtxTranslate(pm->unk7C, 0.0f, -0.0f, 40.0f);
                        break;
                    case 3:
                        MtxRotateX(pm->unk7C, -80.0f);
                        break;
                    case 4:
                        MtxRotateX(pm->unk7C, -90.0f);
                        MtxTranslate(pm->unk7C, 0.0f, 20.0f, 0.0f);
                        break;
                    case 5:
                        MtxRotateX(pm->unk7C, 250.0f);
                        MtxTranslate(pm->unk7C, 0.0f, 0.0f, 20.0f);
                        break;
                }
                pm->unk7C[3][0] *= obj->scale.x;
                pm->unk7C[3][1] *= obj->scale.y;
                pm->unk7C[3][2] *= obj->scale.z;
            }
            break;
        case 6:
            pm = &D_800F2B7C[D_8010110C_PiranhasPursuit->model[0]];
            m = &D_800F2B7C[obj->model[4]];
            tw = D_8010110C_PiranhasPursuit->unk_50;
            if (!(m->unk_20 & 4) && (f32)D_80101150_PiranhasPursuit.anim[4][1] <= m->unk_48) {
                func_800FEF78_PiranhasPursuit(obj, 5, 1);
            }
            if (D_80100406_PiranhasPursuit == 0 && func_800184BC(D_8010110C_PiranhasPursuit, 0x23) != 0) {
                D_80100406_PiranhasPursuit = 1;
            }
            PP_TURN(D_8010110C_PiranhasPursuit->rot.z, 0.0f, 10.0f);
            if (D_80100404_PiranhasPursuit != 0) {
                D_8010110C_PiranhasPursuit->trans.x = D_8010110C_PiranhasPursuit->trans.x - 10.0;
            } else {
                D_8010110C_PiranhasPursuit->trans.x = D_8010110C_PiranhasPursuit->trans.x + 10.0;
            }
            D_8010110C_PiranhasPursuit->trans.y += D_80101150_PiranhasPursuit.unk10;
            D_80101150_PiranhasPursuit.unk10 = D_80101150_PiranhasPursuit.unk10 - 10.0;
            mtx = pm->unk7C[0];
            func_800A2A50((void*)mtx);
            MtxRotateX((void*)mtx, -60.0f);
            if (D_8010110C_PiranhasPursuit->trans.y <= 0.0) {
                D_8010110C_PiranhasPursuit->trans.y = 0.0f;
                func_80017C0C(D_8010110C_PiranhasPursuit, 8, D_8010110C_PiranhasPursuit->trans.x,
                              D_8010110C_PiranhasPursuit->trans.y, D_8010110C_PiranhasPursuit->trans.z, 0.0f, 0.0f);
                PlaySound(0x34C);
                if (D_80100408_PiranhasPursuit == 0) {
                    func_80060F04(tw->unk_58, 2, 2, 20);
                    D_80100408_PiranhasPursuit = 1;
                }
                D_800F2B7C[D_8010110C_PiranhasPursuit->model[8]].unk_48 = 3.0f;
                switch (D_80101150_PiranhasPursuit.unk22) {
                    case 0:
                        D_80101150_PiranhasPursuit.unk10 = 70.0f;
                        D_80101150_PiranhasPursuit.unk22++;
                        break;
                    case 1:
                        D_80101150_PiranhasPursuit.unk10 = 50.0f;
                        D_80101150_PiranhasPursuit.unk22++;
                        break;
                    default:
                        func_800A2A50(pm->unk7C);
                        D_80101150_PiranhasPursuit.state = 7;
                        D_80101150_PiranhasPursuit.timer = 0;
                        break;
                }
            }
            if (func_800FF35C_PiranhasPursuit(D_8010110C_PiranhasPursuit) != 0) {
                D_80101150_PiranhasPursuit.unk10 = 30.0f;
                D_80101150_PiranhasPursuit.unk22 = 2;
                D_80100404_PiranhasPursuit = 1;
                func_80017C0C(D_8010110C_PiranhasPursuit, 7, D_8010110C_PiranhasPursuit->trans.x,
                              D_8010110C_PiranhasPursuit->trans.y, D_8010110C_PiranhasPursuit->trans.z, 30.0f, 30.0f);
                PlaySound(0x34C);
            }
            func_800FA3F0_PiranhasPursuit(D_8010110C_PiranhasPursuit->model[0], D_8010110C_PiranhasPursuit);
            break;
        case 7:
            D_801012C8_PiranhasPursuit = 2;
            break;
    }
    func_800FF730_PiranhasPursuit(obj);
    for (i = 0; i < 7; i++) {
        func_800FA3F0_PiranhasPursuit(obj->model[i], obj);
        func_800FA740_PiranhasPursuit(obj->model[i]);
    }
    func_80025798(obj->model[7], obj->trans.x, 0.0f, obj->trans.z);
    func_80025830(obj->model[7], obj->scale.x, obj->scale.y, obj->scale.z);
    if (moving != 0) {
        if (D_801012E8_PiranhasPursuit != 0) {
            func_800FFB28_PiranhasPursuit(obj);
        }
        spd = D_801012DC_PiranhasPursuit;
        if (D_801012D8_PiranhasPursuit < spd) {
            spd = D_801012D8_PiranhasPursuit + 0.25;
        }
        D_801012D8_PiranhasPursuit = spd;
        D_80101150_PiranhasPursuit.unk14 = D_80101150_PiranhasPursuit.unk14 + D_801012D8_PiranhasPursuit;
        D_801012D4_PiranhasPursuit = (obj->trans.x + 700.0) - D_80101150_PiranhasPursuit.unk18;
        D_801012E0_PiranhasPursuit = D_801012D8_PiranhasPursuit;
    } else {
        D_801012E0_PiranhasPursuit = 0.0f;
    }
    if (D_801012C8_PiranhasPursuit != 0 && D_801012CA_PiranhasPursuit != 0) {
        D_801012E0_PiranhasPursuit = 0.0f;
    }
}
#else
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_31_PiranhasPursuit/225DF0", D_80100A04_PiranhasPursuit);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_PiranhasPursuit/225DF0", func_800FD9D0_PiranhasPursuit);
#endif

/* Shows the model of a motion (3 and 4 have their own; the rest share model 0) and starts it. */
void func_800FEF78_PiranhasPursuit(omObjData* obj, s16 anim, s16 fwd) {
    u16 i;
    s16 m;
    PPPlant* pl = &D_80101150_PiranhasPursuit;

    D_8010117C_PiranhasPursuit = anim;
    for (i = 0; i < 7; i++) {
        func_800258EC(obj->model[i], 4, 4);
    }
    m = ((u16)(anim - 3) < 2) ? anim : 0;
    func_800258EC(obj->model[m], 4, 0);
    if (fwd != 0) {
        func_800FA684_PiranhasPursuit(obj->model[m], pl->anim[anim], 1);
    } else {
        func_800FA5DC_PiranhasPursuit(obj->model[m], pl->anim[anim], 1);
    }
}

/* The plant jumps over the piece ahead of it; at the goal it stops. */
// NON_MATCHING: register allocation
#ifdef NON_MATCHING
void func_800FF0C0_PiranhasPursuit(omObjData* obj) {
    PPPlant* pl = &D_80101150_PiranhasPursuit;
    PPPiece* p;
    s16 i;
    s32 last;

    i = func_800FC4D0_PiranhasPursuit(obj);
    last = i == D_80101134_PiranhasPursuit - 1;
    if (i != -1) {
        p = &D_8010112C_PiranhasPursuit[i];
        switch (p->unk2) {
            case 1:
            case 2:
                if (obj->trans.y <= 0.0 && p->pos.x - 100.0f < obj->trans.x) {
                    pl->unk10 = 40.0f;
                    if (last == 1) {
                        D_801012E8_PiranhasPursuit = 0;
                        if (obj->scale.y < 1.0) {
                            D_80101150_PiranhasPursuit.unk10 = D_80101150_PiranhasPursuit.unk10 * 1.2;
                        }
                    }
                    if (D_80101150_PiranhasPursuit.unk2E == 0) {
                        func_800FEF78_PiranhasPursuit(obj, 1, 0);
                    }
                    obj->trans.y = 0.0f;
                    D_80101150_PiranhasPursuit.state = 2;
                    return;
                }
                break;
            case 3:
                if (obj->trans.y <= 0.0 && p->pos.x - 120.0 < obj->trans.x) {
                    D_80101150_PiranhasPursuit.unk10 = 40.0f;
                    if (D_80101150_PiranhasPursuit.unk2E == 0) {
                        func_800FEF78_PiranhasPursuit(obj, 1, 0);
                    }
                    obj->trans.y = 0.0f;
                    D_80101150_PiranhasPursuit.state = 2;
                    return;
                }
                break;
            case 5:
                if (p->pos.x - 50.0 < obj->trans.x) {
                    D_801012CA_PiranhasPursuit = 1;
                    D_801012EA_PiranhasPursuit = 1;
                    func_800FEF78_PiranhasPursuit(obj, 2, 1);
                    D_80101150_PiranhasPursuit.state = 3;
                    D_800F2B7C[obj->model[0]].unk_48 = 24.0f;
                    PlaySound(0x34D);
                    func_80017C0C(D_8010110C_PiranhasPursuit, 7, obj->trans.x, 500.0f, obj->trans.z, 0.0f, 60.0f);
                }
                break;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_PiranhasPursuit/225DF0", func_800FF0C0_PiranhasPursuit);
#endif

/* The eaten runner bounces off a rock, stump or tree it falls on. */
s16 func_800FF35C_PiranhasPursuit(omObjData* obj) {
    PPPiece* p;
    f32 dx;
    f32 dy;

    p = func_800FC52C_PiranhasPursuit(obj);
    if (p != NULL) {
        if (p->unk2 < 4) {
            if (p->unk2 > 0) {
                if (p->unk0 == 0) {
                    return 0;
                }
                dx = obj->trans.x - p->unk34;
                dy = obj->trans.y - p->unk38;
                if (sqrtf(dx * dx + dy * dy) <= p->unk4) {
                    obj->trans.y = func_800AEFD0(dx / p->unk4 * 90.0) * p->unk4 + p->unk38;
                    return 1;
                }
                return 0;
            }
        }
    }
    return 0;
}

void func_800FF450_PiranhasPursuit(void) {
    func_80020CC4(D_801012C4_PiranhasPursuit);
}

/* While the plant snaps (motion 4) it catches the runner if it is in reach. */
// NON_MATCHING: load order of the plant fields, stack copies of x/y
#ifdef NON_MATCHING
void func_800FF470_PiranhasPursuit(omObjData* runner, omObjData* plant) {
    Vec pos;
    f32 frame;
    f32 d;
    f64 k;
    s16 se;

    if (((runner != NULL) & (plant != NULL)) && D_80101150_PiranhasPursuit.state == 4) {
        frame = D_800F2B7C[plant->model[3]].unk_48;
        if ((frame >= 15.0f) & (frame <= 17.0f)) {
            k = 200.0;
        } else if ((frame >= 63.0f) & (frame <= 65.0f)) {
            k = 200.0;
        } else if ((frame >= 40.0f) & (frame <= 42.0f)) {
            k = 250.0;
        } else {
            return;
        }
        pos.x = plant->trans.x + D_80101150_PiranhasPursuit.unk28 * k;
        PlaySound(0x34F);
        pos.y = plant->trans.y + 50.0;
        d = fabsf(pos.y - (f32)(runner->trans.y + 50.0));
        if (D_8010110C_PiranhasPursuit->trans.x < pos.x) {
            if (d < D_80101150_PiranhasPursuit.unk28 * 100.0) {
                if (D_80101150_PiranhasPursuit.unk28 <= 0.6) {
                    se = 0x349;
                } else {
                    se = 0x34B;
                    if (D_80101150_PiranhasPursuit.unk28 <= 1.3) {
                        se = 0x34A;
                    }
                }
                if (se != -1) {
                    func_80060540(se, 0);
                }
                D_801012C8_PiranhasPursuit = 1;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_PiranhasPursuit/225DF0", func_800FF470_PiranhasPursuit);
#endif

typedef struct PPScaleSteps {
    f32 v[7][2];
} PPScaleSteps;

const PPScaleSteps D_80100C00_PiranhasPursuit = {
    { { 0.0f, 0.2f }, { -0.1f, 0.2f }, { -0.2f, 0.3f }, { -0.1f, 0.3f }, { 0.0f, 0.4f }, { 0.1f, 0.4f }, { 0.0f, 0.0f } }
};

/* After a splash near it the plant grows (and speeds up) in a wobble. */
// NON_MATCHING: retail addresses the plant fields by their splat labels
#ifdef NON_MATCHING
void func_800FF730_PiranhasPursuit(omObjData* obj) {
    PPScaleSteps tbl = D_80100C00_PiranhasPursuit;
    f32 t;
    f32 a;
    f32 b;
    f32 s;
    f32 v;

    if (D_8010114C_PiranhasPursuit != 0.0) {
        if (D_8010114C_PiranhasPursuit == 1.0) {
            if ((u16)D_80101150_PiranhasPursuit.unk2C < 2) {
                func_800FEF78_PiranhasPursuit(obj, 6, 0);
            }
            if (D_80101150_PiranhasPursuit.unk28 < 1.5) {
                D_80101150_PiranhasPursuit.unk2E = 1;
                D_80101150_PiranhasPursuit.unk24 = D_80101150_PiranhasPursuit.unk28 + 0.2;
                D_8010114C_PiranhasPursuit += 1.0f;
                ++D_8010040A_PiranhasPursuit;
                s = 24.1f;
                if (D_801012DC_PiranhasPursuit < 24.1f) {
                    v = func_800AEAC0(D_8010040A_PiranhasPursuit * 18);
                    s = v * v * 4.0f + 20.1f;
                }
                D_801012DC_PiranhasPursuit = s;
                if (D_8010040A_PiranhasPursuit >= 5) {
                    D_8010040A_PiranhasPursuit = 0;
                }
            } else {
                D_80101150_PiranhasPursuit.unk2E = 1;
                D_80101150_PiranhasPursuit.unk24 = D_80101150_PiranhasPursuit.unk28;
                D_8010114C_PiranhasPursuit += 1.0f;
                ++D_8010040A_PiranhasPursuit;
                if (D_801012DC_PiranhasPursuit < 25.6f) {
                    v = func_800AEAC0(D_8010040A_PiranhasPursuit * 45);
                    D_801012DC_PiranhasPursuit = v * v * 1.5f + 24.1f;
                    return;
                }
                D_801012DC_PiranhasPursuit = 25.6f;
            }
        } else {
            t = ++D_8010040E_PiranhasPursuit * 0.2;
            if (D_8010040C_PiranhasPursuit & 1) {
                t = 1.0 - t;
            }
            a = D_80101150_PiranhasPursuit.unk28 + tbl.v[D_8010040C_PiranhasPursuit][0];
            b = D_80101150_PiranhasPursuit.unk28 + tbl.v[D_8010040C_PiranhasPursuit][1];
            if (D_8010040E_PiranhasPursuit >= 5) {
                D_8010040E_PiranhasPursuit = 0;
                if (++D_8010040C_PiranhasPursuit >= 6) {
                    D_80101150_PiranhasPursuit.unk28 = D_80101150_PiranhasPursuit.unk24;
                    t = 0.0f;
                    D_8010114C_PiranhasPursuit = 0.0f;
                    D_8010040C_PiranhasPursuit = 0;
                    D_80101150_PiranhasPursuit.unk2E = 0;
                    a = D_80101150_PiranhasPursuit.unk24;
                    if (D_80101150_PiranhasPursuit.state == 1) {
                        func_800FEF78_PiranhasPursuit(obj, 0, 1);
                    }
                }
            }
            obj->scale.x = obj->scale.y = obj->scale.z = a + t * (b - a);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_PiranhasPursuit/225DF0", func_800FF730_PiranhasPursuit);
#endif

/* The plant's lunge at a splash, and back. */
// NON_MATCHING: retail addresses the plant fields by their splat labels
#ifdef NON_MATCHING
void func_800FFB28_PiranhasPursuit(omObjData* obj) {
    if (D_80101150_PiranhasPursuit.unk1C > 0.0) {
        if (D_80101150_PiranhasPursuit.unk18 < D_80101150_PiranhasPursuit.unk1C) {
            D_80101150_PiranhasPursuit.unk18 = D_80101150_PiranhasPursuit.unk18 + 40.0 / 3.0;
        } else {
            D_80101150_PiranhasPursuit.unk1C = 0;
        }
    } else if (D_80101150_PiranhasPursuit.unk18 > 0.0) {
        D_80101150_PiranhasPursuit.unk18 = D_80101150_PiranhasPursuit.unk18 - 40.0 / 3.0;
    } else {
        D_80101150_PiranhasPursuit.unk18 = 0.0f;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_PiranhasPursuit/225DF0", func_800FFB28_PiranhasPursuit);
#endif

u16 func_800FFBD8_PiranhasPursuit(s32 file) {
    void* f;
    s16 s;

    f = DataRead(file);
    s = func_800678A4(f);
    DataClose(f);
    return s;
}

/* Splashes: 32 sprites. */
void func_800FFC1C_PiranhasPursuit(void) {
    PPSplash* p;
    u16 i;

    p = D_80101138_PiranhasPursuit = HuMemDirectMalloc(32 * sizeof(PPSplash));
    for (i = 0; i < 32; i++, p++) {
        p->x = p->y = p->z = 0.0f;
        p->unk4 = 0;
        p->state = 0;
        p->life = 0;
        p->sprite = func_80064EF4(1, 0);
        func_80067480(p->sprite, 0, -1);
        func_800674BC(p->sprite, 0, 0x9838);
        func_800672B0(p->sprite, 0, 2);
    }
}

s32 func_800FFCD8_PiranhasPursuit(u16 type, f32 x, f32 y, f32 z, u16 life) {
    PPSplash* p;
    unk65770Obj* o;
    f32 s;
    u16 i;

    p = D_80101138_PiranhasPursuit;
    for (i = 0; i < 32; i++, p++) {
        if (p->state == 0) {
            p->life = life;
            p->life0 = life;
            func_80067208(p->sprite, 0, D_801012F0_PiranhasPursuit[type], 0);
            func_800671DC(p->sprite, 0, 0);
            p->x = x;
            p->y = y;
            p->z = z;
            func_800670C4(p->sprite, 0, 0, p->x, p->y, p->z);
            o = func_800675F4(p->sprite, 0);
            switch (type) {
                case 2:
                    p->state = 2;
                    switch (func_800FA218_PiranhasPursuit(3)) {
                        case 0:
                            func_80067558(p->sprite, 0, 0xE8, 0x86, 0x33, 0xFF);
                            break;
                        case 1:
                            func_80067558(p->sprite, 0, 0xB6, 0x68, 0x25, 0xFF);
                            break;
                        default:
                            func_80067558(p->sprite, 0, 0x84, 0x4A, 0x17, 0xFF);
                            break;
                    }
                    s = (f32)func_800FA218_PiranhasPursuit(15) * 0.1 + 1.5;
                    o->unk14 = s * o->unk14;
                    o->unk18 = s * o->unk18;
                    o->unk42 -= 40;
                    func_80067284(p->sprite, 0, 1.0f);
                    break;
                case 3:
                    p->state = 3;
                    switch (func_800FA218_PiranhasPursuit(3)) {
                        case 0:
                            func_80067558(p->sprite, 0, 0xFC, 0xAE, 0x5B, 0xC8);
                            break;
                        case 1:
                            func_80067558(p->sprite, 0, 0xC0, 0x7C, 0x34, 0xC8);
                            break;
                        default:
                            func_80067558(p->sprite, 0, 0x84, 0x4A, 0x17, 0xC8);
                            break;
                    }
                    s = (f32)func_800FA218_PiranhasPursuit(6) * 0.1 + 0.5;
                    o->unk14 = s * o->unk14;
                    o->unk18 = s * o->unk18;
                    func_80067284(p->sprite, 0, 0.5f);
                    break;
                case 4:
                    p->state = 4;
                    o->unk14 = o->unk14 * 14.0;
                    o->unk18 = o->unk18 * 14.0;
                    func_80067284(p->sprite, 0, 2.0f);
                    func_800674F4(p->sprite, 0, 0xFF, 0xFF, 0xBE);
                    func_8006752C(p->sprite, 0, 0xFF);
                default:
                    p->state = 1;
                    break;
            }
            func_80067480(p->sprite, 0, 0x8000);
            return 1;
        }
    }
    return 1;
}

void func_801000A8_PiranhasPursuit(void) {
    PPSplash* p;
    unk65770Obj* o;
    u16 i;

    p = D_80101138_PiranhasPursuit;
    for (i = 0; i < 32; i++, p++) {
        if (p->state != 0) {
            if (p->state == 1) {
                goto move;
            }
            if (p->state == 4) {
                goto grow;
            }
            goto life;
        move:
            func_800670C4(p->sprite, 0, 0, p->x, p->y, p->z);
            {
            grow:
                func_800670C4(p->sprite, 0, 0, p->x, p->y, p->z);
                o = func_800675F4(p->sprite, 0);
                o->unk14 = o->unk14 * 14.0;
                o->unk18 = o->unk18 * 14.0;
            }
        life:
            if (--p->life <= 0) {
                p->state = 0;
                func_800674BC(p->sprite, 0, 0x8000);
            }
        }
    }
}

void func_801001C8_PiranhasPursuit(void) {
    HuMemDirectFree(D_80101138_PiranhasPursuit);
}
