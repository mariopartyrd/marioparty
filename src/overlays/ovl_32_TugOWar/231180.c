#include "common.h"
#include "TugOWar.h"
#include "sprite65770.h"

/* .data (0x800FDBD0) */
s8 D_800FDBD0_TugOWar = 0; /* fade-out started */

void func_800FAD80_TugOWar(f32 zoom, f32 rx, f32 ry, f32 rz, f32 cx, f32 cy, f32 cz) {
    CZoom = zoom;
    CRot.x = rx;
    CRot.y = ry;
    CRot.z = rz;
    Center.x = cx;
    Center.y = cy;
    Center.z = cz;
}

void func_800FADC0_TugOWar(omObjData* obj) {
    if (D_800F5144 == 1) {
        if (D_800FDBD0_TugOWar == 0) {
            if (D_800FDFB3_TugOWar == 0) {
                func_800726AC(0, 0x14);
            } else {
                func_800726AC(3, 0x14);
            }
            D_800FDBD0_TugOWar = 1;
            return;
        }
        if (func_80072718() == 0) {
            func_800601D4(0x28);
            GMesSprClose();
            omOvlReturnEx(1);
        }
    }
}

u16 func_800FAE4C_TugOWar(s32 file) {
    void* data;
    u16 ret;

    data = DataRead(file);
    ret = func_800678A4(data);
    DataClose(data);
    return ret;
}

/* Builds a wavy sprite's display list into gfx: frame `frame` of sprite animation `anim` (an I4
   image) at (x, y) scaled by `scale`, `strips` texture loads, every `band` lines a rectangle shifted
   sideways by sin(phase) * amp (DesertDash func_800FB750 with one scale). */
// logic-equivalent gbi-macro rewrite (DesertDash func_800FB750's shape); retail interleaves the writes
#ifdef NON_MATCHING
void func_800FAE90_TugOWar(Gfx* gfx, s32 anim, s32 frame, s32 x, s32 y, s32 phase, s32 band, f32 amp, s32 step,
                           s32 strips, f32 scale) {
    unk65770AnimC* f;
    s32 ang;
    s32 rows;
    s32 x0;
    s32 x1;
    s32 y0;
    s32 i;
    s32 j;
    s32 wave;
    f32 top;
    f32 h;

    ang = step * phase;
    f = &func_80067310(anim)->unk0[frame];
    rows = f->unk6 / strips;
    x0 = x - (u16)f->unk8 * scale;
    x1 = x0 + f->unk4 * scale;
    y0 = y - (u16)f->unkA * scale;
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPPipeSync(gfx++);
    gDPSetTexturePersp(gfx++, G_TP_NONE);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gSPSetOtherMode(gfx++, G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, 0x004041C8);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gSPSetOtherMode(gfx++, G_SETOTHERMODE_H, G_MDSFT_RGBDITHER, 2, 0x40);
    gDPSetCombine(gfx++, 0xFFFFFF, 0xFFFDF2F9);
    gDPSetPrimColor(gfx++, 0, 0, 0xFF, 0xFF, 0x00, 0xFF);
    for (i = 0; i < strips; i++) {
        gDPSetTextureImage(gfx++, G_IM_FMT_I, G_IM_SIZ_8b, f->unk4 >> 1, f->unk0);
        gDPSetTile(gfx++, G_IM_FMT_I, G_IM_SIZ_8b, ((f->unk4 >> 1) + 7) >> 3, 0, G_TX_LOADTILE, 0, 0, 0, 0, 0, 0,
                   0);
        gDPLoadSync(gfx++);
        gDPLoadTile(gfx++, G_TX_LOADTILE, 0, (rows * i) << 2, (f->unk4 - 1) << 1, (rows * (i + 1) - 1) << 2);
        gDPPipeSync(gfx++);
        gDPSetTile(gfx++, G_IM_FMT_I, G_IM_SIZ_4b, ((f->unk4 >> 1) + 7) >> 3, 0, G_TX_RENDERTILE, 0, 0, 0, 0, 0, 0,
                   0);
        gDPSetTileSize(gfx++, G_TX_RENDERTILE, 0, (rows * i) << 2, (f->unk4 - 1) << 2, (rows * (i + 1) - 1) << 2);
        for (j = 0; j < rows / band; j++) {
            wave = func_800AEAC0(ang) * amp * 4.0f * scale;
            ang = (ang + step) % 360;
            top = (f32)y0 + rows * scale * i;
            h = band * scale;
            gSPScisTextureRectangle(gfx++, x0 * 4 + wave, (s16)(s32)(top + h * j) << 2, x1 * 4 + wave,
                                    (s32)(top + h * (j + 1)) * 4, G_TX_RENDERTILE, 0, (rows * i + band * j) << 5,
                                    (s32)(1.0 / scale * 1024.0), (s32)(1.0 / scale * 1024.0));
        }
    }
    gDPPipeSync(gfx++);
    gSPEndDisplayList(gfx++);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_32_TugOWar/231180", func_800FAE90_TugOWar);
#endif

/* Draws model `dst` with model `src`'s display data, then restores it. */
void func_800FB718_TugOWar(s16 dst, s16 src, s16 arg2, f32 arg3) {
    unk2C0C0StructC0* m;
    unk2C0C0StructE0* save;

    m = D_800F2B7C[dst].unk_6C;
    save = m->unk_04;
    m->unk_04 = D_800F2B7C[src].unk_6C->unk_04;
    func_80026174(dst, arg2, arg3);
    D_800F2B7C[dst].unk_6C->unk_04 = save;
}

/* The stick's angle in degrees (0..360), or -1 inside the dead zone. */
f32 func_800FB7AC_TugOWar(s8 port) {
    s8 sx;
    s8 sy;
    f32 fx;
    f32 fy;
    f32 angle;

    sy = ContStkY[port];
    sx = ContStkX[port];
    if (sx > 60) {
        sx = 60;
    }
    if (sy > 60) {
        sy = 60;
    }
    if (sx < -60) {
        sx = -60;
    }
    if (sy < -60) {
        sy = -60;
    }
    fx = sx;
    fy = sy;
    if (fx * fx + fy * fy > 100.0f) {
        angle = func_800B0CD8(fx, -fy) + 180.0f;
    } else {
        angle = -1.0f;
    }
    return angle;
}

void func_800FB8A4_TugOWar(s16 model, s16 motion, s16 start, s16 end, u16 attr, u16 shift) {
    unk_ovl_2D_struct* m;

    m = &D_800F2B7C[model];
    if (m->unk_0C != -1) {
        m->unk_08 = m->unk_0C;
        m->unk_48 = m->unk_54;
        m->unk_0A = m->unk_0E;
        m->unk_50 = m->unk_5C;
    }
    m->unk_0A = attr;
    m->unk_0C = motion;
    m->unk_54 = start;
    m->unk_12 = 0;
    m->unk_10 = end;
    m->unk_0E = shift;
    m->unk_5C = 0.0f;
}
