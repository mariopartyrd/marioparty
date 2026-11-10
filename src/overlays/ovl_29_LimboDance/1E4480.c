#include "common.h"
#include "LimboDance.h"

/* gDPSetTile's mask for a texture dimension (as src/1EA70.c's TEX_MASK). */
#define LD_TEX_MASK(x) \
    ((x) < 3 ? 1 : (x) < 5 ? 2 : (x) < 9 ? 3 : (x) < 17 ? 4 : (x) < 33 ? 5 : (x) < 65 ? 6 : (x) < 129 ? 7 : (x) < 257 ? 8 : 9)

void func_800FA030_LimboDance(void) {
    D_800ED440 = 0;
    D_800F2AF8[D_800ED440++] = omAddObj(5, 8, 0, -1, func_800FA418_LimboDance);
    omAddObj(5, 0, 0, -1, func_800FA110_LimboDance);
    func_80028510(0x3A2, 0x3CA, 0, 0, 2);
    func_800FB93C_LimboDance(16);
    func_800FE3CC_LimboDance();
}

void func_800FA0DC_LimboDance(void) {
    HuMemDirectFree(D_800FF1F8_LimboDance);
    HuMemDirectFree(D_800FF220_LimboDance);
    func_800FE8C4_LimboDance();
}

/* Torch flames: flicker (a random gust now and then) and the glow billboards. */
void func_800FA110_LimboDance(omObjData* obj) {
    LDScenery* s;
    s32 i;

    if (D_800FE9BC_LimboDance >= 54.0f && D_800FE9BC_LimboDance <= 126.0f) {
        D_800FE9B8_LimboDance = func_800AEAC0((D_800FE9BC_LimboDance - 54.0f) * 2.5) * 32.0 + 8.0;
        D_800FE9BC_LimboDance += 2.0f;
    } else {
        D_800FE9BC_LimboDance += 18.0f;
    }
    if (func_8009B618(D_800FE9BC_LimboDance, 360.0) < 18.0 && !(rand8() & 7)) {
        D_800FE9BC_LimboDance = 0.0f;
    }
    for (i = 0; i < 3; i++) {
        s = &D_800FF220_LimboDance[i];
        func_800FC4FC_LimboDance(s->sub[0], D_800FE9B8_LimboDance, D_800FE9BC_LimboDance);
        func_800FDDEC_LimboDance(s->sub[1], 0xFF, 0xD0, 0x90, func_800AEAC0(2.0f * D_800FE9BC_LimboDance) * 16.0f + 236.0f);
        func_800FDDEC_LimboDance(s->sub[2], 0xFF, 0xD0, 0x90, func_800AEAC0(2.0f * D_800FE9BC_LimboDance) * 16.0f + 236.0f);
        func_800FDCBC_LimboDance(s->sub[1], func_800AEAC0(D_800FE9BC_LimboDance * 2.5) + 24.0,
                                 func_800AEAC0(2.0f * D_800FE9BC_LimboDance) + 24.0, 1.0f);
        func_800FDCBC_LimboDance(s->sub[2], func_800AEAC0(D_800FE9BC_LimboDance * 2.5) + 28.0,
                                 func_800AEAC0(2.0f * D_800FE9BC_LimboDance) + 28.0, 1.0f);
    }
    func_800FE3CC_LimboDance();
}

/* The scenery: the sea strip (a display list scrolled by func_800FB504), three torches, trees,
   bushes and rocks recycled 2100 ahead as the camera passes them. */
// NON_MATCHING: register allocation / scheduling
#ifdef NON_MATCHING
void func_800FA418_LimboDance(omObjData* obj) {
    LDSceneWork* w;
    LDScenery* s;
    Gfx* buf;
    Gfx* gfx;
    Vtx* v;
    void* data;
    s32 size;
    s16 sprGlow;
    s16 sprFlame;
    s16 sprFire;
    s32 i;
    s32 j;
    s32 k;

    obj->func_ptr = func_800FB058_LimboDance;
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    omSetStatBit(obj, 0xA0);
    obj->unk_50 = w = func_80023684(sizeof(LDSceneWork), 0x7918);
    func_8009B770(w, 0, sizeof(LDSceneWork));
    w->unk_04 = 1;
    w->unk_05 = 0;
    func_80023448(4);
    D_800EE9A0.def[0].col[0] = D_800EE9A0.def[0].col[1] = D_800EE9A0.def[0].col[2] = 0x40;
    D_800EE9A0.def[1].col[0] = D_800EE9A0.def[1].col[1] = D_800EE9A0.def[1].col[2] = 0x40;
    D_800EE9A0.def[1].dir[0] = -2;
    D_800EE9A0.def[1].dir[1] = 1;
    D_800EE9A0.def[1].dir[2] = -0x60;
    data = DataRead(0x3D000C);
    D_800FF1F4_LimboDance = func_800678A4(data);
    DataClose(data);
    buf = HuMemDirectMalloc(0x2000 * sizeof(Gfx)); /* 0x10000 bytes on the N64 */
    gfx = buf;
    func_800FB504_LimboDance(D_800FF1F4_LimboDance, &gfx, 0.0f);
    size = (u8*)gfx - (u8*)buf;
    D_800FF1F8_LimboDance = HuMemDirectMalloc(size);
    func_80023A38(buf, D_800FF1F8_LimboDance, size);
    HuMemDirectFree(buf);
    D_800FF1F0_LimboDance = func_80024198(0x19, D_800FF1F8_LimboDance, 0);
    data = DataRead(0x420006);
    sprFlame = func_800678A4(data);
    DataClose(data);
    data = DataRead(0x420007);
    sprFire = func_800678A4(data);
    DataClose(data);
    data = DataRead(0x3D000D);
    sprGlow = func_800678A4(data);
    DataClose(data);
    for (i = 0; i < 8; i++) {
        if (i == 6) {
            obj->model[6] = func_800174C0(D_800FEA00_LimboDance[6] | 0x3D0000, 0x2B9);
        } else if (D_800FEA00_LimboDance[i] != -1) {
            obj->model[i] = func_800174C0(D_800FEA00_LimboDance[i] | 0x3D0000, 0x2D9);
        }
    }
    func_80026040(obj->model[0]);
    D_800FF220_LimboDance = HuMemDirectMalloc(35 * sizeof(LDScenery));
    for (i = 0; i < 35; i++) {
        s = &D_800FF220_LimboDance[i];
        s->type = 0;
        s->unk_02 = 0;
        s->unk_08 = 0;
        s->unk_0C = 0;
        s->unk_04 = s->unk_06 = 0;
        s->unk_10.x = s->unk_10.y = s->unk_10.z = 0.0f;
        s->unk_1C.x = s->unk_1C.y = s->unk_1C.z = 0.0f;
        s->pos.x = s->pos.y = s->pos.z = 0.0f;
        s->scale.x = s->scale.y = s->scale.z = 0.0f;
        s->model = s->sub[0] = s->sub[1] = s->sub[2] = 0;
        s->model = s->sub[0] = s->sub[1] = s->sub[2] = 0;
        s->unk_48[0] = s->unk_48[1] = s->unk_48[2] = s->unk_48[3] = 0;
        s->unk_50[0] = s->unk_50[1] = s->unk_50[2] = s->unk_50[3] = 0;
        s->unk_58[0] = s->unk_58[1] = s->unk_58[2] = s->unk_58[3] = 0;
    }
    for (i = 0; i < 3; i++) {
        s = &D_800FF220_LimboDance[i];
        s->type = 2;
        s->model = func_80023FC8(obj->model[1]);
        s->pos.x = i * 7.0 * 100.0 + -700.0;
        s->pos.y = 0.0f;
        s->pos.z = -320.0f;
        func_80025798(s->model, s->pos.x, s->pos.y, -320.0f);
        func_80025830(s->model, 1.0f, 1.0f, 0.1f);
        s->sub[0] = func_800FBAF0_LimboDance(sprFire, sprFlame, 16);
        func_800FDC6C_LimboDance(s->sub[0], s->pos.x, 70.0f, s->pos.z);
        func_800FDCBC_LimboDance(s->sub[0], 4.0f, 4.0f, 1.0f);
        func_800FDDEC_LimboDance(s->sub[0], 0, 0, 0, 0xFF);
        func_800FDBEC_LimboDance(s->sub[0], i * 4);
        func_800FDC2C_LimboDance(s->sub[0], 2.7f);
        s->sub[1] = func_800FC9A0_LimboDance(sprGlow, 0x89);
        s->sub[2] = func_800FC9A0_LimboDance(sprGlow, 0x11);
        func_800FDC6C_LimboDance(s->sub[1], s->pos.x, 2.0f, s->pos.z + 30.0);
        func_800FDC6C_LimboDance(s->sub[2], s->pos.x, 100.0f, s->pos.z + 2.0);
        func_800FDCBC_LimboDance(s->sub[1], 24.0f, 24.0f, 1.0f);
        func_800FDCBC_LimboDance(s->sub[2], 24.0f, 24.0f, 1.0f);
        func_800FDD0C_LimboDance(s->sub[1], 90.0f, 0.0f, 0.0f);
        for (j = 0; j < 3; j++) {
            v = func_800FDDA0_LimboDance(s->sub[1], j);
            for (k = 0; k < 4; k++) {
                v[k] = D_800FE9C0_LimboDance[k];
            }
        }
    }
    for (i = 0; i < 3; i++) {
        s = &D_800FF220_LimboDance[3 + i];
        s->model = func_80023FC8(obj->model[6]);
        s->pos.x = i * 7.0 * 100.0 + -350.0;
        s->pos.y = 0.0f;
        s->pos.z = -350.0f;
        func_80025798(s->model, s->pos.x, s->pos.y, -350.0f);
        func_80025830(s->model, 1.5f, 1.5f, 1.5f);
        func_80025EB4(s->model, 2, 2);
    }
    for (i = 0; i < 5; i++) {
        s = &D_800FF220_LimboDance[6 + i];
        s->model = func_80023FC8(obj->model[7]);
        s->pos.x = (i * 4.2 + (rand8() & 7) * 0.2 - 0.7 + -10.5) * 100.0;
        s->pos.y = 0.0f;
        s->pos.z = -400.0f;
        func_80025798(s->model, s->pos.x, s->pos.y, -400.0f);
        s->scale.x = (f32)((rand8() & 0x1F) + 90) * 0.01;
        s->scale.y = (f32)((rand8() & 0x1F) + 100) * 0.01;
        s->scale.z = 1.0f;
        func_80025830(s->model, s->scale.x, s->scale.y, 1.0f);
    }
    for (i = 0; i < 10; i++) {
        s = &D_800FF220_LimboDance[11 + i];
        s->model = func_80023FC8(obj->model[7]);
        s->pos.x = (i * 2.1 + (rand8() & 7) * 0.075 - 0.2625 + -10.5) * 100.0;
        s->pos.y = 0.0f;
        s->pos.z = -((rand8() & 3) * 1.5 + 5.5) * 100.0;
        func_80025798(s->model, s->pos.x, s->pos.y, s->pos.z);
        s->scale.x = (f32)((rand8() & 0x1F) + 90) * 0.01;
        s->scale.y = (f32)((rand8() & 0x1F) + 110) * 0.01;
        s->scale.z = 1.0f;
        func_80025830(s->model, s->scale.x, s->scale.y, 1.0f);
    }
    for (i = 0; i < 9; i++) {
        s = &D_800FF220_LimboDance[21 + i];
        s->model = func_80023FC8(obj->model[2]);
        s->pos.x = (i * 2.3 + (rand8() & 7) * 0.1 - 0.35 + -10.5) * 100.0;
        s->pos.y = 0.0f;
        s->pos.z = -((u8)(rand8() % 3) * 1.5 + 3.9) * 100.0;
        func_80025798(s->model, s->pos.x, s->pos.y, s->pos.z);
    }
    for (i = 0; i < 5; i++) {
        s = &D_800FF220_LimboDance[30 + i];
        s->model = func_80023FC8(obj->model[3]);
        s->pos.x = (i * 4.2 + (rand8() & 7) * 0.3 - 1.05 + -10.5) * 100.0;
        s->pos.y = 0.0f;
        s->pos.z = 400.0f;
        func_80025798(s->model, s->pos.x, s->pos.y, 400.0f);
    }
    for (i = 1; i < 8; i++) {
        if (D_800FEA00_LimboDance[i] != -1) {
            func_800258EC(obj->model[i], 4, 4);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_29_LimboDance/1E4480", func_800FA418_LimboDance);
#endif

void func_800FB04C_LimboDance(f32 x) {
    D_800FE9B4_LimboDance = x;
}

/* Follows the camera: scrolls the sea, recycles scenery, lights the dancer from the torches. */
// NON_MATCHING: register allocation / scheduling
#ifdef NON_MATCHING
void func_800FB058_LimboDance(omObjData* obj) {
    LDScenery* s;
    Gfx* gfx;
    f32 scroll;
    f32 dx;
    f32 dz;
    f32 d2;
    f32 d;
    f32 l;
    s32 i;

    if (++D_800FE9B0_LimboDance >= 3) {
        D_800FE9B0_LimboDance = 0;
    }
    obj->trans.x = D_800FE9B4_LimboDance;
    scroll = D_800FE9B4_LimboDance / 100.0 * 8.0;
    func_80027C1C(obj->model[0], scroll, 0.0f, 64, 64);
    for (i = 0; i < 35; i++) {
        s = &D_800FF220_LimboDance[i];
        if (s->model != 0 && s->pos.x - D_800FE9B4_LimboDance < -1050.0) {
            s->pos.x += 2100.0;
            func_80025798(s->model, s->pos.x, s->pos.y, s->pos.z);
            switch (s->type) {
            case 1:
                func_80025798(s->sub[0], s->pos.x, s->pos.y, s->pos.z);
                break;
            case 2:
                func_800FDC6C_LimboDance(s->sub[0], s->pos.x, 70.0f, s->pos.z);
                func_800FDC6C_LimboDance(s->sub[1], s->pos.x, 2.0f, s->pos.z + 30.0);
                func_800FDC6C_LimboDance(s->sub[2], s->pos.x, 100.0f, s->pos.z + 0.5);
                break;
            }
        }
    }
    gfx = D_800FF1F8_LimboDance;
    func_800FB504_LimboDance(D_800FF1F4_LimboDance, &gfx, func_8009B618(scroll * 0.8, 256.0));
    D_800F2B7C[D_800FF1F0_LimboDance].unk_6C->unk_00 = (Gfx**)D_800FF1F8_LimboDance;
    for (i = 0; i < 3; i++) {
        s = &D_800FF220_LimboDance[i];
        dx = s->pos.x - D_800FE9B4_LimboDance;
        dz = s->pos.z;
        d2 = dx * dx + 10000.0f + dz * dz;
        l = 255.0f / d2 * 100.0 * 100.0 * 12.0;
        if (l >= 255.0f) {
            l = 255.0f;
        }
        d = func_800B1750(d2);
        D_800EE9A0.def[i + 2].col[0] = l;
        /* retail writes def[2]'s blue for every torch */
        D_800EE9A0.def[2].col[2] = D_800EE9A0.def[i + 2].col[1] = l * 0.375;
        D_800EE9A0.def[i + 2].dir[0] = dx / d * 120.0f;
        D_800EE9A0.def[i + 2].dir[1] = 100.0f / d * 120.0f;
        D_800EE9A0.def[i + 2].dir[2] = dz / d * 120.0f;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_29_LimboDance/1E4480", func_800FB058_LimboDance);
#endif

/* Appends the sea strip's display list: the sprite's first frame drawn as 320-wide texture
   rectangles, scrolled by scroll texels. */
// NON_MATCHING: register allocation / scheduling
#ifdef NON_MATCHING
void func_800FB504_LimboDance(s16 sprite, Gfx** pgfx, f32 scroll) {
    Gfx* gfx;
    unk65770Anim* anim;
    unk65770AnimC* frame;
    s32 rows;
    s32 n;
    s32 i;

    gfx = *pgfx;
    anim = func_80067310(sprite);
    frame = anim->unk0;
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPPipeSync(gfx++);
    gDPSetTexturePersp(gfx++, G_TP_NONE);
    gDPLoadTLUT_pal256(gfx++, anim->unkC);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);
    gDPSetRenderMode(gfx++, 0x442008, 0);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gDPSetColorDither(gfx++, G_CD_MAGICSQ);
    gDPSetCombine(gfx++, 0xFFFFFF, 0xFFFCF279);
    rows = 6;
    if (anim->unk0->unk6 * 5 < 33) {
        rows = anim->unk0->unk6;
    }
    n = anim->unk0->unk6 / rows;
    for (i = 0; i < n; i++) {
        gDPLoadTextureTile(gfx++, frame->unk0, G_IM_FMT_CI, G_IM_SIZ_8b, frame->unk4, 0, 0, i * rows,
                           frame->unk4 - 1, (i + 1) * rows - 1, 0, G_TX_WRAP, G_TX_WRAP, 8, G_TX_NOMASK,
                           G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gfx++, 0, (i * rows) << 2, 320 << 2, ((i + 1) * rows) << 2, G_TX_RENDERTILE,
                            scroll * 32.0f, (rows * i) << 5, 1 << 10, 1 << 10);
    }
    gSPEndDisplayList(gfx++);
    *pgfx = gfx;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_29_LimboDance/1E4480", func_800FB504_LimboDance);
#endif

/* Allocates count billboards and the per-frame display-list and matrix buffers. */
void func_800FB93C_LimboDance(u8 count) {
    LDBillboard* b;
    s16 i;

    D_800FF1FC_LimboDance = count;
    for (i = 0; i < 3; i++) {
        D_800FF200_LimboDance[i] = HuMemDirectMalloc(D_800FF1FC_LimboDance * 20 * sizeof(Gfx));
        D_800FF20C_LimboDance[i] = HuMemDirectMalloc(D_800FF1FC_LimboDance * sizeof(Mtx));
    }
    D_800FF218_LimboDance = func_80024198(0x499, D_800FF200_LimboDance[0], 4);
    D_80103298 = HuMemDirectMalloc(D_800FF1FC_LimboDance * sizeof(LDBillboard));
    for (i = 0; i < D_800FF1FC_LimboDance; i++) {
        b = &D_80103298[i];
        b->unk_00 = (Gfx*)-1;
        b->unk_20 = 0;
        b->unk_28 = 0;
        b->unk_22 = 0;
        b->unk_29 = b->unk_2A = b->unk_2B = b->unk_2C = 0xFF;
        b->unk_30 = 0.0f;
        b->unk_24 = 0;
        b->unk_26 = 0;
        b->unk_34 = 1.0f;
        b->unk_38.x = b->unk_38.y = b->unk_38.z = 0.0f;
        b->unk_44.x = b->unk_44.y = 0.0f;
        b->unk_50.x = b->unk_50.y = b->unk_50.z = 0.0f;
    }
}

/* A torch flame: sprite (CI4, the flame shape) over sprite2's first frame (CI4 32x32, the fire
   texture) on D_800FEA28's quads. Returns its id, -1 if none is free. */
// NON_MATCHING: register allocation / scheduling
#ifdef NON_MATCHING
s16 func_800FBAF0_LimboDance(s16 sprite, s16 sprite2, u8 flags) {
    LDBillboard* b;
    unk65770Anim* anim;
    unk65770AnimC* frame;
    Gfx* dl;
    Gfx* gfx;
    s32 size;
    u16 w;
    u16 h;
    s16 i;
    s16 id;

    for (id = 0; id < D_800FF1FC_LimboDance; id++) {
        if (D_80103298[id].unk_00 == (Gfx*)-1) {
            break;
        }
    }
    if (id == D_800FF1FC_LimboDance) {
        return -1;
    }
    b = &D_80103298[id];
    b->unk_22 = sprite;
    b->unk_28 = flags;
    dl = HuMemDirectMalloc(0x2000 * sizeof(Gfx)); /* 0x10000 bytes on the N64 */
    gfx = dl;
    gDPPipeSync(gfx++);
    gDPSetBlendColor(gfx++, 1, 1, 1, 1);
    gDPSetRenderMode(gfx++, 0x504A50, 0);
    gDPSetCombine(gfx++, 0xFF99FF, 0xFF30FE7F);
    frame = &D_800EC700[b->unk_22]->unk0[b->unk_24];
    w = frame->unk4;
    h = frame->unk6;
    gDPLoadTextureBlock_4b(gfx++, 0x02000000, G_IM_FMT_CI, (s16)w, (s16)h, 0, G_TX_CLAMP, G_TX_CLAMP,
                           LD_TEX_MASK((s16)w), LD_TEX_MASK((s16)h), G_TX_NOLOD, G_TX_NOLOD);
    gSPVertex(gfx++, 0x01000000, 5, 0);
    gSP2Triangles(gfx++, 0, 1, 4, 0, 1, 2, 4, 0);
    gSP2Triangles(gfx++, 0, 4, 3, 0, 4, 2, 3, 0);
    gDPSetCombine(gfx++, 0xFFFFFF, 0xFFFCF279);
    gDPSetRenderMode(gfx++, 0x443078, 0);
    anim = D_800EC700[sprite2];
    gDPLoadTLUT_pal16(gfx++, 0, anim->unkC);
    gDPLoadTextureBlock_4b(gfx++, anim->unk0->unk0, G_IM_FMT_CI, 32, 32, 0, G_TX_MIRROR, G_TX_CLAMP, 5, 5,
                           G_TX_NOLOD, G_TX_NOLOD);
    gSPVertex(gfx++, 0x01000050, 4, 5);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 5, 7, 8, 0);
    gSPEndDisplayList(gfx++);
    size = (u8*)gfx - (u8*)dl;
    for (i = 0; i < D_800F37DA; i++) {
        b->unk_10[i] = HuMemDirectMalloc(sizeof(D_800FEA28_LimboDance));
        func_80023A38(D_800FEA28_LimboDance, b->unk_10[i], sizeof(D_800FEA28_LimboDance));
    }
    b->unk_00 = HuMemDirectMalloc(size);
    func_80023A38(dl, b->unk_00, size);
    HuMemDirectFree(dl);
    dl = HuMemDirectMalloc(0x2000 * sizeof(Gfx)); /* 0x10000 bytes on the N64 */
    gfx = dl;
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, b->unk_2A, b->unk_2B, b->unk_2C, b->unk_29);
    gDPSetTextureFilter(gfx++, D_800FEA20_LimboDance[(b->unk_28 & 0x18) >> 3]);
    anim = D_800EC700[b->unk_22];
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);
    gDPLoadTLUT_pal16(gfx++, 0, anim->unkC);
    gSPSegment(gfx++, 2, osVirtualToPhysical(anim->unk0[b->unk_24].unk0));
    gSPSegment(gfx++, 1, osVirtualToPhysical(b->unk_10[0]));
    gSPDisplayList(gfx++, b->unk_00);
    gSPEndDisplayList(gfx++);
    size = (u8*)gfx - (u8*)dl;
    for (i = 0; i < D_800F37DA; i++) {
        b->unk_04[i] = HuMemDirectMalloc(size);
        func_80023A38(dl, b->unk_04[i], size);
    }
    HuMemDirectFree(dl);
    return id;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_29_LimboDance/1E4480", func_800FBAF0_LimboDance);
#endif

/* Sways a torch flame's vertices for this frame (amp: the gust strength). */
// NON_MATCHING: register allocation / scheduling
#ifdef NON_MATCHING
void func_800FC4FC_LimboDance(s32 id, f32 amp, f32 angle) {
    LDBillboard* b = &D_80103298[id];
    f64 k;

    if (amp > 8.0) {
        b->unk_10[D_800F37F0][0].v.ob[0] =
            D_800FEA28_LimboDance[0].v.ob[0] + func_800AEAC0(angle) * amp * 1.25;
        b->unk_10[D_800F37F0][0].v.ob[1] =
            D_800FEA28_LimboDance[0].v.ob[1] + func_800AEFD0(360.0f - angle) * -amp * 1.75;
        b->unk_10[D_800F37F0][1].v.ob[0] =
            D_800FEA28_LimboDance[1].v.ob[0] + func_800AEAC0(angle) * amp * 1.25;
        b->unk_10[D_800F37F0][1].v.ob[1] = D_800FEA28_LimboDance[1].v.ob[1] + func_800AEFD0(angle) * amp * 1.75;
        b->unk_10[D_800F37F0][5].v.ob[0] = D_800FEA28_LimboDance[5].v.ob[0] + func_800AEAC0(angle) * amp * (k = 0.175);
    } else {
        b->unk_10[D_800F37F0][0].v.ob[0] = D_800FEA28_LimboDance[0].v.ob[0] + func_800AEAC0(angle) * amp;
        b->unk_10[D_800F37F0][0].v.ob[1] =
            D_800FEA28_LimboDance[0].v.ob[1] + func_800AEFD0(360.0f - angle) * -amp * 2.5;
        b->unk_10[D_800F37F0][1].v.ob[0] = D_800FEA28_LimboDance[1].v.ob[0] + func_800AEAC0(-angle) * amp;
        b->unk_10[D_800F37F0][1].v.ob[1] = D_800FEA28_LimboDance[1].v.ob[1] + func_800AEFD0(angle) * amp * 2.5;
        b->unk_10[D_800F37F0][5].v.ob[0] = D_800FEA28_LimboDance[5].v.ob[0] + func_800AEAC0(angle) * amp * (k = 0.075);
    }
    b->unk_10[D_800F37F0][6].v.ob[0] = D_800FEA28_LimboDance[6].v.ob[0] + func_800AEAC0(angle) * amp * k;
    b->unk_10[D_800F37F0][4].v.ob[0] = D_800FEA28_LimboDance[4].v.ob[0] + func_800AEAC0(angle) * amp * 0.2;
    b->unk_10[D_800F37F0][4].v.cn[3] =
        D_800FEA28_LimboDance[4].v.cn[3] + (s32)(-func_800AEAC0(2.0f * angle) * 55.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_29_LimboDance/1E4480", func_800FC4FC_LimboDance);
#endif


/* Takes a free billboard for sprite and builds its display list (ovl_25's func_800FE2F0). */
// NON_MATCHING: register allocation / scheduling
#ifdef NON_MATCHING
s16 func_800FC9A0_LimboDance(s16 sprite, u8 flags) {
    LDBillboard* b;
    unk65770Anim* anim;
    unk65770AnimC* frame;
    Gfx* dl;
    Gfx* gfx;
    Vtx* vbuf;
    Vtx* v;
    s32 size;
    u16 w;
    u16 h;
    s16 x;
    s16 y;
    s16 nh;
    s16 i;
    s16 id;

    for (id = 0; id < D_800FF1FC_LimboDance; id++) {
        if (D_80103298[id].unk_00 == (Gfx*)-1) {
            break;
        }
    }
    if (id == D_800FF1FC_LimboDance) {
        return -1;
    }
    b = &D_80103298[id];
    b->unk_22 = sprite;
    b->unk_28 = flags;
    dl = HuMemDirectMalloc(0x2000 * sizeof(Gfx)); /* 0x10000 bytes on the N64 */
    vbuf = v = HuMemDirectMalloc(8 * sizeof(Vtx));
    gfx = dl;
    gDPPipeSync(gfx++);
    anim = D_800EC700[b->unk_22];
    if (anim->unk18 & 0x8000) {
        gDPSetCombine(gfx++, 0xFF97FF, 0xFF2DFEFF);
        gDPSetRenderMode(gfx++, 0x4049D8, 0);
        gDPSetBlendColor(gfx++, 1, 1, 1, 1);
    } else if (b->unk_29 == 0xFF) {
        gDPSetRenderMode(gfx++, 0x443078, 0);
        gDPSetCombine(gfx++, 0xFFFFFF, 0xFFFCF279);
    } else {
        gDPSetBlendColor(gfx++, 0, 0, 0, 1);
        gDPSetRenderMode(gfx++, 0x5049D8, 0);
        gDPSetCombine(gfx++, 0x143228, 0xFF65FEFF);
    }
    frame = &anim->unk0[b->unk_24];
    w = frame->unk4;
    h = frame->unk6;
    if (anim->unk18 & 0x8000) {
        gDPLoadTextureBlock_4b(gfx++, 0x02000000, G_IM_FMT_I, (s16)w, (s16)h, 0, G_TX_CLAMP, G_TX_CLAMP,
                               LD_TEX_MASK((s16)w), LD_TEX_MASK((s16)h), G_TX_NOLOD, G_TX_NOLOD);
    } else if (anim->unk18 < 0x11) {
        gDPLoadTextureBlock_4b(gfx++, 0x02000000, G_IM_FMT_CI, (s16)w, (s16)h, 0, G_TX_CLAMP, G_TX_CLAMP,
                               LD_TEX_MASK((s16)w), LD_TEX_MASK((s16)h), G_TX_NOLOD, G_TX_NOLOD);
    } else {
        gDPLoadTextureBlock(gfx++, 0x02000000, G_IM_FMT_CI, G_IM_SIZ_8b, (s16)w, (s16)h, 0, G_TX_CLAMP, G_TX_CLAMP,
                            LD_TEX_MASK((s16)w), LD_TEX_MASK((s16)h), G_TX_NOLOD, G_TX_NOLOD);
    }
    gSPVertex(gfx++, 0x01000000, 4, 0);
    gSP1Quadrangle(gfx++, 0, 1, 2, 3, 0);
    gSPEndDisplayList(gfx++);
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
    v->v.tc[1] = (-nh - 1) << 6;
    v->n.a = 0xFF;
    v++;
    v->v.ob[0] = (s16)w + x;
    v->v.ob[1] = nh + y;
    v->v.ob[2] = 0;
    v->n.n[0] = v->n.n[1] = v->n.n[2] = -1;
    v->v.tc[0] = ((s16)w - 1) << 6;
    v->v.tc[1] = (-nh - 1) << 6;
    v->n.a = 0xFF;
    v++;
    v->v.ob[0] = (s16)w + x;
    v->v.ob[1] = y;
    v->v.ob[2] = 0;
    v->n.n[0] = v->n.n[1] = v->n.n[2] = -1;
    v->v.tc[0] = ((s16)w - 1) << 6;
    v->v.tc[1] = 0;
    v->n.a = 0xFF;
    size = (u8*)gfx - (u8*)dl;
    for (i = 0; i < D_800F37DA; i++) {
        b->unk_10[i] = HuMemDirectMalloc(8 * sizeof(Vtx));
        func_80023A38(vbuf, b->unk_10[i], 8 * sizeof(Vtx));
    }
    b->unk_00 = HuMemDirectMalloc(size);
    func_80023A38(dl, b->unk_00, size);
    HuMemDirectFree(dl);
    HuMemDirectFree(vbuf);
    dl = HuMemDirectMalloc(0x2000 * sizeof(Gfx)); /* 0x10000 bytes on the N64 */
    gfx = dl;
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, b->unk_2A, b->unk_2B, b->unk_2C, b->unk_29);
    gDPSetTextureFilter(gfx++, D_800FEA20_LimboDance[(b->unk_28 & 0x18) >> 3]);
    if (anim->unk18 & 0x8000) {
        gDPSetTextureLUT(gfx++, G_TT_NONE);
    } else {
        gDPSetTextureLUT(gfx++, G_TT_RGBA16);
        if (anim->unk18 < 0x11) {
            gDPLoadTLUT_pal16(gfx++, 0, anim->unkC);
        } else {
            gDPLoadTLUT_pal256(gfx++, anim->unkC);
        }
    }
    gSPSegment(gfx++, 2, osVirtualToPhysical(frame->unk0));
    gSPSegment(gfx++, 1, osVirtualToPhysical(b->unk_10[0]));
    gSPDisplayList(gfx++, b->unk_00);
    gSPEndDisplayList(gfx++);
    size = (u8*)gfx - (u8*)dl;
    for (i = 0; i < D_800F37DA; i++) {
        b->unk_04[i] = HuMemDirectMalloc(size);
        func_80023A38(dl, b->unk_04[i], size);
    }
    HuMemDirectFree(dl);
    return id;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_29_LimboDance/1E4480", func_800FC9A0_LimboDance);
#endif

void func_800FDBEC_LimboDance(s16 id, s16 frame) {
    LDBillboard* b;

    if (id != -1) {
        b = &D_80103298[id];
        b->unk_24 = frame;
        b->unk_30 = 0.0f;
    }
}

void func_800FDC2C_LimboDance(s16 id, f32 speed) {
    if (id != -1) {
        LDBillboard* b = &D_80103298[id];

        b->unk_34 = speed;
    }
}

void func_800FDC6C_LimboDance(s16 id, f32 x, f32 y, f32 z) {
    LDBillboard* b;

    if (id != -1) {
        b = &D_80103298[id];
        b->unk_38.x = x;
        b->unk_38.y = y;
        b->unk_38.z = z;
    }
}

void func_800FDCBC_LimboDance(s16 id, f32 x, f32 y, f32 z) {
    LDBillboard* b;

    if (id != -1) {
        b = &D_80103298[id];
        b->unk_44.x = x;
        b->unk_44.y = y;
        b->unk_44.z = z;
    }
}

void func_800FDD0C_LimboDance(s16 id, f32 x, f32 y, f32 z) {
    LDBillboard* b;

    if (id != -1) {
        b = &D_80103298[id];
        b->unk_50.x = x;
        b->unk_50.y = y;
        b->unk_50.z = z;
    }
}

void func_800FDD5C_LimboDance(s16 id, u8 flags) {
    LDBillboard* b;

    if (id != -1) {
        b = &D_80103298[id];
        b->unk_28 |= flags;
    }
}

// NON_MATCHING: register allocation / scheduling
// decomp-permuter
Vtx *func_800FDDA0_LimboDance(s16 id, s32 frame)
{
  LDBillboard *new_var2;
  s16 new_var;
  new_var = id;
  if (new_var == (-1))
  {
    return 0;
  }
  new_var2 = &(*(&D_80103298[new_var]));
  return new_var2->unk_10[frame];
}

void func_800FDDEC_LimboDance(s16 id, u8 r, u8 g, u8 b, s32 a) {
    LDBillboard* bb;

    if (id != -1) {
        bb = &D_80103298[id];
        bb->unk_2A = r;
        bb->unk_2B = g;
        bb->unk_2C = b;
        bb->unk_29 = a;
    }
}

/* Frees a billboard's display lists and resets it. */
void func_800FDE38_LimboDance(s16 id) {
    LDBillboard* b;
    s32 i;

    if (id != -1) {
        b = &D_80103298[id];
        if (b->unk_00 != (Gfx*)-1) {
            for (i = 0; i < D_800F37DA; i++) {
                HuMemDirectFree(b->unk_10[i]);
                HuMemDirectFree(b->unk_04[i]);
            }
            HuMemDirectFree(b->unk_00);
            b->unk_00 = (Gfx*)-1;
            b->unk_1C = 0;
            b->unk_20 = 0;
            b->unk_28 = 0;
            b->unk_22 = 0;
            b->unk_29 = b->unk_2A = b->unk_2B = b->unk_2C = 0xFF;
            b->unk_30 = 0.0f;
            b->unk_24 = 0;
            b->unk_26 = 0;
            b->unk_38.x = b->unk_38.y = b->unk_38.z = 0.0f;
            b->unk_44.x = b->unk_44.y = b->unk_44.z = 0.0f;
            b->unk_34 = 1.0f;
        }
    }
}

/* Rewrites each visible billboard's material list for this frame and advances its animation. */
void func_800FDF58_LimboDance(void) {
    LDBillboard* b;
    unk65770Anim* anim;
    unk65770AnimC* frame;
    Gfx* gfx;
    unk65770Anim8* seq;
    s32 len;
    s32 count;
    s16 j;
    s16 i;

    for (i = 0; i < D_800FF1FC_LimboDance; i++) {
        b = &D_80103298[i];
        if (b->unk_00 == (Gfx*)-1 || b->unk_20 != 0 || (b->unk_28 & 0x20)) {
            continue;
        }
        gfx = b->unk_04[D_800F37F0];
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, b->unk_2A, b->unk_2B, b->unk_2C, b->unk_29);
        gDPSetTextureFilter(gfx++, D_800FEA20_LimboDance[(b->unk_28 & 0x18) >> 3]);
        anim = D_800EC700[b->unk_22];
        frame = &anim->unk0[b->unk_24];
        if (anim->unk18 & 0x8000) {
            gDPSetTextureLUT(gfx++, G_TT_NONE);
        } else {
            gDPSetTextureLUT(gfx++, G_TT_RGBA16);
            if (anim->unk18 < 0x11) {
                gDPLoadTLUT_pal16(gfx++, 0, anim->unkC);
            } else {
                gDPLoadTLUT_pal256(gfx++, anim->unkC);
            }
        }
        gSPSegment(gfx++, 2, osVirtualToPhysical(frame->unk0));
        gSPSegment(gfx++, 1, osVirtualToPhysical(b->unk_10[D_800F37F0]));
        gSPDisplayList(gfx++, b->unk_00);
        gSPEndDisplayList(gfx++);
        if (b->unk_28 & 1) {
            continue;
        }
        if (anim->unk4 != NULL) {
            seq = *anim->unk4;
            len = seq->unk4[b->unk_24].unk2;
            count = seq->unk0;
        } else {
            len = 8;
            count = anim->unk10;
        }
        for (j = 0; j < 2; j++) {
            b->unk_30 += b->unk_34;
            if (b->unk_30 > len) {
                b->unk_24++;
                b->unk_30 -= len;
                if (b->unk_24 + 1 >= count) {
                    if (b->unk_28 & 4) {
                        func_800FDD5C_LimboDance(i, 0x20);
                        break;
                    }
                    if (b->unk_28 & 0x40) {
                        func_800FDE38_LimboDance(i);
                        break;
                    }
                    if (b->unk_28 & 2) {
                        b->unk_24--;
                        break;
                    }
                    b->unk_24 = 0;
                }
            }
        }
    }
}

/* Builds this frame's billboard display list (ovl_25's func_800FFD18). */
// NON_MATCHING: register allocation / scheduling
#ifdef NON_MATCHING
void func_800FE3CC_LimboDance(void) {
    Mtx view;
    Mtx proj;
    Matrix4f mf;
    Matrix4f tmp;
    Matrix4f sc;
    Vec eye;
    Vec at;
    Vec up;
    LDBillboard* b;
    Gfx* gfx;
    Mtx* mtx;
    f32 rx;
    f32 ry;
    s32 i;

    func_800FDF58_LimboDance();
    *D_800F2B7C[D_800FF218_LimboDance].unk_6C->unk_00 = D_800FF200_LimboDance[D_800FE9B0_LimboDance];
    gfx = D_800FF200_LimboDance[D_800FE9B0_LimboDance];
    mtx = D_800FF20C_LimboDance[D_800FE9B0_LimboDance];
    proj = *(&D_800C3110->unk_138 + D_800F3FA8 * 2); /* the viewport's projection pair */
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
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gfx++, G_LIGHTING | G_FOG | G_CULL_BOTH);
    gSPSetGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH);
    gDPSetBlendColor(gfx++, 0, 0, 0, 1);
    gDPSetAlphaCompare(gfx++, G_AC_THRESHOLD);
    gSPTexture(gfx++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    for (i = 0; i < D_800FF1FC_LimboDance; i++) {
        b = &D_80103298[i];
        if (b->unk_00 == (Gfx*)-1 || (b->unk_28 & 0x20)) {
            continue;
        }
        guMtxL2F(mf, &view);
        MtxTranslate(mf, b->unk_38.x, b->unk_38.y, b->unk_38.z);
        MtxRotate(mf, b->unk_50.x, b->unk_50.y, b->unk_50.z);
        MtxScale(mf, b->unk_44.x, b->unk_44.y, b->unk_44.z);
        if (!(b->unk_28 & 0x80)) {
            sc[0][0] = b->unk_44.x;
            sc[1][1] = b->unk_44.y;
            sc[2][2] = b->unk_44.z;
            sc[3][3] = 1.0f;
            sc[0][1] = sc[0][2] = sc[0][3] = sc[1][0] = sc[1][2] = sc[1][3] = sc[2][0] = sc[2][1] = sc[2][3] =
                sc[3][0] = sc[3][1] = sc[3][2] = 0.0f;
            MtxReset(mf, tmp);
            MtxMult(sc, tmp, mf);
        }
        if (b->unk_20 != 0) {
            gSPSegment(gfx++, 1, osVirtualToPhysical(*((Vtx**)b->unk_1C + D_800F37F0 + 2)));
        }
        func_800A0A20(mf, mtx);
        gSPMatrix(gfx++, osVirtualToPhysical(mtx++), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gfx++, b->unk_04[D_800F37F0]);
    }
    gSPMatrix(gfx++, osVirtualToPhysical(&proj), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPEndDisplayList(gfx++);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_29_LimboDance/1E4480", func_800FE3CC_LimboDance);
#endif

void func_800FE8C4_LimboDance(void) {
    s32 i;

    for (i = 0; i < D_800FF1FC_LimboDance; i++) {
        func_800FDE38_LimboDance(i);
    }
    HuMemDirectFree(D_80103298);
    for (i = 0; i < 3; i++) {
        HuMemDirectFree(D_800FF200_LimboDance[i]);
        HuMemDirectFree(D_800FF20C_LimboDance[i]);
    }
}
