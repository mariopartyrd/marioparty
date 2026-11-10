#include "HandcarHavoc.h"

void func_800FD1B0_HandcarHavoc(omObjData* obj) {
    s32 i = 0;

    for (i = 0; i < D_800F3778; i++) {}
}

void func_800FD1E8_HandcarHavoc(s32 arg0) {
    omOvlReturnEx(1);
}

/* objmain.c's camera update for the two viewports (far 10000, near 2000). */
void func_800FD204_HandcarHavoc(omObjData* obj) {
    Vec3f pos;
    Vec3f target;
    Vec3f up;
    f32 rx;
    f32 ry;
    s32 i;

    for (i = 0; i < 2; i++) {
        rx = CRotM[i].x;
        ry = CRotM[i].y;
        pos.x = func_800AEAC0(ry) * func_800AEFD0(rx) * CZoomM[i] + CenterM[i].x;
        pos.y = -func_800AEAC0(rx) * CZoomM[i] + CenterM[i].y;
        pos.z = func_800AEFD0(ry) * func_800AEFD0(rx) * CZoomM[i] + CenterM[i].z;
        target.x = CenterM[i].x;
        target.y = CenterM[i].y;
        target.z = CenterM[i].z;
        up.x = func_800AEAC0(ry) * func_800AEAC0(rx);
        up.y = func_800AEFD0(rx);
        up.z = func_800AEFD0(ry) * func_800AEAC0(rx);
        D_800F2C28[i].x = pos.x;
        D_800F2C28[i].z = pos.z;
        D_800F2C28[i].rot = CRotM[i].y;
        D_800F2C28[i].fov = D_800C3110[i].unk_40;
        D_800F2C28[i].far = 10000.0f;
        D_800F2C28[i].near = 2000.0f;
        func_8001D420(i, &pos, &target, &up);
        func_8001D57C(i);
    }
}

/* Height of the face's plane at (x, z); unused. */
f32 func_800FD464_HandcarHavoc(f32 x, f32 y, f32 z, HHColVtx* vtx, HHColFace* face) {
    Vec3f n;
    Vec3f p;
    HHColVtx* a;
    f32 nx;
    f32 ny;
    f32 nz;

    a = &vtx[face->v[0]];
    p.x = a->x;
    p.y = a->y;
    p.z = a->z;
    func_800295FC(&vtx[face->v[0]], &vtx[face->v[1]], &vtx[face->v[2]], &n);
    nx = n.x;
    ny = n.y;
    nz = n.z;
    if (ny == 0.0f) {
        return -100000.0f;
    }
    return y + (nx * (p.x - x) + ny * (p.y - y) + nz * (p.z - z)) / ny;
}

/* A rider's seat position: the car's rotations applied to (0, 162.5, seat offset). */
// decomp-permuter
void func_800FD59C_HandcarHavoc(omObjData *obj, u16 seat, Vec *out)
{
  Matrix4f m;
  f32 v[4];
  f32 t[4];
  HHCar *w;
  f32 rx;
  float new_var;
  f32 ry;
  f32 rz;
  f32 s;
  f32 c;
  s32 i;
  float new_var2;
  s32 j;
  w = obj->unk_50;
  v[0] = 0.0f;
  v[1] = 162.5f;
  v[2] = w->seat[seat];
  v[3] = 1.0f;
  s = func_800AEAC0(w->rot.y);
  c = func_800AEFD0(w->rot.y);
  new_var2 = s * w->lean;
  rx = (new_var2 + w->rot.x) + (s * w->tilt);
  ry = w->rot.y;
  new_var = c * w->lean;
  rz = (new_var + w->rot.z) + (c * w->tilt);
  if (rx < 0.0f)
  {
    rx += 360.0f;
  }
  if (rx >= 360.0f)
  {
    rx -= 360.0f;
  }
  if (ry < 0.0f)
  {
    ry += 360.0f;
  }
  if (ry >= 360.0f)
  {
    ry -= 360.0f;
  }
  if (rz < 0.0f)
  {
    rz += 360.0f;
  }
  if (rz >= 360.0f)
  {
    rz -= 360.0f;
  }
  guMtxIdentF(m);
  MtxRotate(m, 0.0f, ry, 0.0f);
  for (j = 0; j < 4; j++)
  {
    t[j] = 0;
    for (i = 0; i < 4; i++)
    {
      t[j] += v[i] * m[i][j];
    }

  }

  guMtxIdentF(m);
  MtxRotate(m, rx, 0.0f, rz);
  for (j = 0; j < 4; j++)
  {
    v[j] = 0.0f;
    for (i = 0; i < 4; i++)
    {
      v[j] += t[i] * m[i][j];
    }

  }

  out->x = obj->trans.x + v[0];
  out->y = obj->trans.y + v[1];
  out->z = obj->trans.z + v[2];
}

/* The two wheel spots of one side (D_800FF404). */
// NON_MATCHING: stack addressing of the copy array
#ifdef NON_MATCHING
void func_800FD888_HandcarHavoc(omObjData* obj, u16 side, Vec* out) {
    Matrix4f m;
    f32 v[4];
    f32 t[4];
    Vec tmp[2];
    HHCar* w;
    f32 rx;
    f32 ry;
    f32 rz;
    s32 k;
    s32 i;
    s32 j;

    w = obj->unk_50;
    rx = func_800AEAC0(w->rot.y) + w->rot.x;
    ry = w->rot.y;
    rz = func_800AEFD0(ry) + w->rot.z;
    if (rx < 0.0f) {
        rx += 360.0f;
    }
    if (rx >= 360.0f) {
        rx -= 360.0f;
    }
    if (ry < 0.0f) {
        ry += 360.0f;
    }
    if (ry >= 360.0f) {
        ry -= 360.0f;
    }
    if (rz < 0.0f) {
        rz += 360.0f;
    }
    if (rz >= 360.0f) {
        rz -= 360.0f;
    }
    for (k = 0; k < 2; k++) {
        v[0] = D_800FF404_HandcarHavoc[side * 2 + k].x;
        v[1] = D_800FF404_HandcarHavoc[side * 2 + k].y;
        v[2] = D_800FF404_HandcarHavoc[side * 2 + k].z;
        v[3] = 1.0f;
        guMtxIdentF(m);
        MtxRotate(m, 0.0f, ry, 0.0f);
        for (j = 0; j < 4; j++) {
            t[j] = 0;
            for (i = 0; i < 4; i++) {
                t[j] += v[i] * m[i][j];
            }
        }
        guMtxIdentF(m);
        MtxRotate(m, rx, 0.0f, rz);
        for (j = 0; j < 4; j++) {
            v[j] = 0;
            for (i = 0; i < 4; i++) {
                v[j] += t[i] * m[i][j];
            }
        }
        tmp[k].x = out[k].x = obj->trans.x + v[0];
        tmp[k].y = out[k].y = obj->trans.y + v[1];
        tmp[k].z = out[k].z = obj->trans.z + v[2];
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2F_HandcarHavoc/216140", func_800FD888_HandcarHavoc);
#endif

/* Pumps the levers by the car's speed and pump power. */
// NON_MATCHING: register allocation of the lever model
#ifdef NON_MATCHING
void func_800FDBC8_HandcarHavoc(omObjData* obj) {
    HHCar* w;
    f32 pump;
    u16 mdl;

    w = obj->unk_50;
    func_800FDCEC_HandcarHavoc(obj->model[0], w->leverDir, fabs(w->speed) / 20.0);
    pump = w->pump;
    mdl = obj->model[1];
    w->lever1Dir = func_800FDCEC_HandcarHavoc(mdl, w->lever1Dir, pump);
    w->lever2Dir = func_800FDCEC_HandcarHavoc(obj->model[2], w->lever2Dir, pump);
    D_800F2B7C[obj->model[3]].unk_48 = 18.0f - D_800F2B7C[mdl].unk_48;
    D_800F2B7C[obj->model[4]].unk_48 = D_800F2B7C[mdl].unk_48;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2F_HandcarHavoc/216140", func_800FDBC8_HandcarHavoc);
#endif

/* Steps a model's animation frame back and forth between 0 and its length; returns the
   direction (1 = backwards). */
u16 func_800FDCEC_HandcarHavoc(s16 mdl, u16 dir, f32 step) {
    f32 len;

    len = func_80025D40(mdl);
    if (dir) {
        D_800F2B7C[mdl].unk_48 -= step;
        if (func_80025D18(mdl) <= 0.0f) {
            dir = 0;
            D_800F2B7C[mdl].unk_48 = fabsf(func_80025D18(mdl));
        }
    } else {
        D_800F2B7C[mdl].unk_48 += step;
        if (len <= func_80025D18(mdl)) {
            dir = 1;
            D_800F2B7C[mdl].unk_48 = len + (len - func_80025D18(mdl));
        }
    }
    return dir;
}

void func_800FDE28_HandcarHavoc(void) {
    s32 i;

    for (i = 0; i < D_800F37DA; i++) {
        D_800FF690_HandcarHavoc[i] = func_80023684(1000 * sizeof(Gfx), 0x7918);
    }
    D_800FF6B0_HandcarHavoc = func_80024198(0x680, D_800FF690_HandcarHavoc[D_800F37F0], 0);
}

void func_800FDEC0_HandcarHavoc(u16 sprite, HHScroll* s, f32 u, f32 v) {
    unk65770Obj* o;

    o = func_800675F4(sprite, 0);
    s->sprite = sprite;
    s->sx = 0x400;
    s->sy = 0x400;
    s->w = o->unk4C->unk14;
    s->h = o->unk4C->unk16;
    s->cols = s->w / 40;
    s->rows = s->h / 40;
    if (s->w % 40) {
        s->cols++;
    }
    if (s->h % 40) {
        s->rows++;
    }
    s->u = u;
    s->v = v;
    s->unk2C = 0;
    s->angle = s->unk24 = s->dAngle = 0.0f;
}

/* Draws the two viewports' scrolling backgrounds in 40x40 CI8 tiles. */
// NON_MATCHING: retail writes the display list through fixed offsets (not attempted)
#ifdef NON_MATCHING
void func_800FE004_HandcarHavoc(HHScroll* s) {
    Gfx* gfx;
    HHScroll* p;
    unk65770Obj* o;
    s16 x0;
    s16 y0;
    s16 cw;
    s16 ch;
    s16 col;
    s16 c;
    s32 lastCol;
    f32 u;
    f32 v;
    f32 xs;
    f32 y;
    f32 x;
    s32 i;
    s32 r;
    s32 k;

    gfx = D_800FF690_HandcarHavoc[D_800F37F0];
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gSPSetOtherMode(gfx++, G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, 0x00552230);
    gDPSetDepthSource(gfx++, G_ZS_PRIM);
    gDPSetPrimDepth(gfx++, 0xFFFF, 0xFFFF);
    gSPTexture(gfx++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTexturePersp(gfx++, G_TP_NONE);
    gDPSetTextureFilter(gfx++, G_TF_POINT);
    gDPSetCombine(gfx++, 0xFFFFFF, 0xFFFCF279);
    for (i = 0; i < 2; i++) {
        p = &s[i];
        o = func_800675F4(p->sprite, 0);
        gDPLoadTLUT_pal256(gfx++, o->unk4C->unkC);
        gDPSetTextureLUT(gfx++, G_TT_RGBA16);
        x0 = p->x0;
        y0 = p->y0;
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, x0, y0, p->x1, p->y1);
        lastCol = p->w;
        u = p->u;
        v = p->v;
        cw = (1024.0f / p->sx) * 40.0f;
        ch = (1024.0f / p->sy) * 40.0f;
        col = (p->cols - u / cw) - 1.0f;
        if (col & 0x8000) {
            col = p->cols + col;
        }
        if (col >= p->cols) {
            col -= p->cols;
        }
        for (r = 0; r < p->rows; r++) {
            c = col;
            xs = (func_8009B618(u, cw) - cw) + x0;
            y = v + y0 + r * ch;
            for (k = 0; k < p->cols + 1; k++) {
                x = xs + k * cw;
                gDPLoadTextureTile(gfx++, o->unk4C->unk8 + c * 40 + r * lastCol * 40, G_IM_FMT_CI, G_IM_SIZ_8b,
                                   lastCol, 0, 0, 0, 40, 40, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                   G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                gSPScisTextureRectangle(gfx++, (s32)(x * 4.0f), (s32)(y * 4.0f), (s32)((x + cw) * 4.0f),
                                        (s32)((y + ch - 1.0f) * 4.0f), G_TX_RENDERTILE, 0, 0, p->sx, p->sy);
                c++;
                if (c >= p->cols) {
                    c -= p->cols;
                }
            }
        }
    }
    gDPPipeSync(gfx++);
    gDPSetDepthSource(gfx++, G_ZS_PIXEL);
    gSPEndDisplayList(gfx++);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2F_HandcarHavoc/216140", func_800FE004_HandcarHavoc);
#endif

// NON_MATCHING: loop layout (masked 6): retail ends the b loop with bnez, not bnezl, and passes the
// layer through a3; the second loop's counters swapped to match retail's registers
#ifdef NON_MATCHING
void func_800FE8D4_HandcarHavoc(s32 team) {
    s32 file;
    u16 layer;
    Vtx* v;
    s16 mdl;
    s32 i;
    s32 b;
    s32 k;

    if (team == 0) {
        file = 0x684;
        layer = 1;
    } else {
        file = 0x684;
        layer = 2;
    }
    for (i = 0; i < 12; i++) {
        for (b = 0; b < D_800F37DA; b++) {
            D_800FF6B8_HandcarHavoc[team][i][b] = func_80023684(12 * sizeof(Vtx), 0x7918);
            D_800FF9B8_HandcarHavoc[team][i][b] = func_80023684(50 * sizeof(Gfx), 0x7918);
            v = D_800FF6B8_HandcarHavoc[team][i][b];
            for (k = 0; k < 4; k++) {
                v->v.ob[0] = 0;
                v->v.ob[1] = 0;
                v->v.ob[2] = 0;
                v->v.cn[0] = 0xFF;
                v->v.cn[1] = 0xFF;
                v->v.cn[2] = 0;
                v->v.cn[3] = 0xFF;
                v++;
                v->v.cn[0] = 0xFF;
                v->v.cn[1] = 0xFF;
                v->v.cn[2] = 0xFF;
                v->v.cn[3] = 0xFF;
                v++;
                v->v.cn[0] = 0xFF;
                v->v.cn[1] = 0xFF;
                v->v.cn[2] = 0x96;
                v->v.cn[3] = 0xFF;
                v++;
            }
        }
        mdl = func_80024198(file, D_800FF9B8_HandcarHavoc[team][i][D_800F37F0], 4);
        D_80101C40_HandcarHavoc[team][i] = mdl;
        func_80025F10(mdl, layer);
    }
    for (b = 0; b < 12; b++) {
        D_800FFCC0_HandcarHavoc[team][b].active = 0;
        for (i = 0; i < D_800F37DA; i++) {
            func_800FEB4C_HandcarHavoc(team, b, i);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2F_HandcarHavoc/216140", func_800FE8D4_HandcarHavoc);
#endif

void func_800FEB4C_HandcarHavoc(s32 team, s32 i, s32 buf) {
    Gfx* gfx;
    s32 k;

    gfx = D_800FF9B8_HandcarHavoc[team][i][buf];
    if (D_800FFCC0_HandcarHavoc[team][i].active == 1) {
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        gSPSetOtherMode(gfx++, G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, 0x00552230);
        gSPClearGeometryMode(gfx++, G_LIGHTING);
        gDPSetCombineMode(gfx++, G_CC_SHADE, G_CC_SHADE);
        gSPTexture(gfx++, 0, 0x8000, 0, G_TX_RENDERTILE, G_OFF);
        gSPVertex(gfx++, D_800FF6B8_HandcarHavoc[team][i][buf], 12, 0);
        for (k = 0; k < 12; k += 3) {
            gSP1Triangle(gfx++, k, k + 1, k + 2, 0);
        }
    }
    gDPPipeSync(gfx++);
    gSPEndDisplayList(gfx++);
}

/* Starts a spark burst at a wheel; returns its model, or -1 when all 12 are in use. */
// NON_MATCHING: spark struct addressed from a different base
#ifdef NON_MATCHING
s16 func_800FECF4_HandcarHavoc(s32 team, s32 side, u16 wheel) {
    HHSparks* p;
    HHChip* c;
    f32 yaw;
    f32 pitch;
    f32 r;
    s32 i;
    s32 k;
    u16 sel;

    sel = (u16)side * 2 + wheel;
    for (i = 0; i < 12; i++) {
        if (D_800FFCC0_HandcarHavoc[team][i].active == 0) {
            break;
        }
    }
    if (i == 12) {
        return -1;
    }
    p = &D_800FFCC0_HandcarHavoc[team][i];
    p->active = 1;
    p->timer = 4;
    p->side = side;
    p->wheel = wheel;
    func_800258EC(D_80101C40_HandcarHavoc[team][i], 4, 0);
    for (k = 0; k < 4; k++) {
        pitch = (u8)(rand8() % 5) + 3;
        switch (sel) {
            case 0:
                yaw = -5 - (u8)(rand8() % 31);
                break;
            case 1:
                yaw = -(u8)(rand8() % 36) + 5;
                break;
            case 2:
                yaw = (u8)(rand8() % 31) + 5;
                break;
            case 3:
                yaw = (u8)(rand8() % 36) - 5;
                break;
        }
        r = D_800FF434_HandcarHavoc[k];
        c = &p->chip[k];
        c->a.x = func_800AEAC0(yaw) * r;
        c->a.y = func_800AEAC0(pitch) * r;
        c->a.z = func_800AEFD0(yaw) * r;
        c->b.x = func_800AEAC0(yaw + 1.0f) * r;
        c->b.y = func_800AEAC0(pitch) * r;
        c->b.z = func_800AEFD0(yaw + 1.0f) * r;
    }
    return D_80101C40_HandcarHavoc[team][i];
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2F_HandcarHavoc/216140", func_800FECF4_HandcarHavoc);
#endif

/* Updates a car's spark bursts (vertices, display lists, timers) and their sound. */
// NON_MATCHING: spark struct addressed from a different base
#ifdef NON_MATCHING
void func_800FF0AC_HandcarHavoc(HHCar* w) {
    HHSparks* p;
    Vtx* v;
    s16* mdl;
    u16 team;
    u16 any;
    s32 i;
    s32 k;

    any = 0;
    team = w->team;
    mdl = D_80101C40_HandcarHavoc[team];
    for (i = 0; i < 12; i++) {
        *D_800F2B7C[mdl[i]].unk_6C->unk_00 = D_800FF9B8_HandcarHavoc[team][i][D_800F37F0];
        p = &D_800FFCC0_HandcarHavoc[team][i];
        if (p->active != 0) {
            any = 1;
            v = D_800FF6B8_HandcarHavoc[team][i][D_800F37F0];
            for (k = 0; k < 4; k++) {
                v++;
                v->v.ob[0] = p->chip[k].a.x;
                v->v.ob[1] = p->chip[k].a.y;
                v->v.ob[2] = p->chip[k].a.z;
                v++;
                v->v.ob[0] = p->chip[k].b.x;
                v->v.ob[1] = p->chip[k].b.y;
                v->v.ob[2] = p->chip[k].b.z;
                v++;
            }
            func_800FEB4C_HandcarHavoc(team, i, D_800F37F0);
            if (--p->timer == 0) {
                p->active = 0;
                func_800258EC(D_80101C40_HandcarHavoc[team][i], 4, 4);
                w->chips[p->side][p->wheel]--;
            }
        }
    }
    if (any == 1) {
        if (w->sparkSndOn == 0) {
            w->sparkSnd = func_80060540(w->team + 0x340, w->team + 2);
            w->sparkSndOn = 1;
        }
    } else if (w->sparkSndOn == 1) {
        func_8006071C(w->sparkSnd);
        w->sparkSndOn = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2F_HandcarHavoc/216140", func_800FF0AC_HandcarHavoc);
#endif
