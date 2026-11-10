#include "common.h"
#include "TreasureDivers.h"

void func_800FA440_TreasureDivers(void) {
    CZoom = 2194.856f;
    CRot.x = 2.9249f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    Center.x = 0.0f;
    Center.y = 800.0f;
    Center.z = -72.0f;
}

TDWork* func_800FA4A8_TreasureDivers(omObjData* obj) {
    TDWork* w = HuMemDirectMalloc(sizeof(TDWork));

    D_800FED40_TreasureDivers[D_800FF180_TreasureDivers] = w;
    obj->work[0] = (u32)w >> 24;
    obj->work[1] = (u32)w >> 16;
    obj->work[2] = (u32)w >> 8;
    obj->work[3] = (u32)w;
    w->unk0 = 0;
    w->unk2 = 0;
    w->unk8 = 0;
    w->unkA = D_800FF180_TreasureDivers;
    w->pos.x = w->pos.y = w->pos.z = 0.0f;
    w->unk18 = w->unk1C = w->unk20 = 0.0f;
    w->unk24 = w->unk28 = w->unk2C = 0.0f;
    w->unk3C = w->unk3E = w->unk40 = w->unk42 = 0;
    w->unk44 = w->unk46 = w->unk48 = w->unk4A = 0;
    w->unk4C = w->unk4E = w->unk50 = w->unk52 = 0;
    w->unk54 = w->unk56 = w->unk58 = w->unk5A = 0;
    D_800FF180_TreasureDivers++;
    return w;
}

void func_800FA594_TreasureDivers(void) {
    s16 i;

    for (i = 0; i < D_800FF180_TreasureDivers; i++) {
        if (D_800FED40_TreasureDivers[i] != NULL) {
            HuMemDirectFree(D_800FED40_TreasureDivers[i]);
        }
    }
}

TDWork* func_800FA614_TreasureDivers(omObjData* obj) {
    return (TDWork*)((obj->work[0] << 24) | (obj->work[1] << 16) | (obj->work[2] << 8) | obj->work[3]);
}

u32 func_800FA640_TreasureDivers(void) {
    u8 hi = rand8();

    return (hi << 8) | rand8();
}

/* Inverts m in place (Gauss-Jordan without pivoting). */
void func_800FA678_TreasureDivers(Matrix4f m) {
    s32 i;
    s32 j;
    s32 k;
    f32 piv;
    f32 f;

    for (i = 0; i < 4; i++) {
        piv = m[i][i];
        for (j = 0; j < 4; j++) {
            if (piv != 0.0f) {
                m[i][j] /= piv;
            } else {
                m[i][j] = 0;
            }
        }
        if (piv != 0.0f) {
            m[i][i] = 1.0f / piv;
        } else {
            m[i][i] = 0;
        }
        for (k = 0; k < 4; k++) {
            if (k != i) {
                f = m[k][i];
                for (j = 0; j < 4; j++) {
                    if (j != i) {
                        m[k][j] -= f * m[i][j];
                    } else if (piv != 0.0f) {
                        m[k][j] = -f / piv;
                    } else {
                        m[k][j] = 0;
                    }
                }
            }
        }
    }
}

/* World position -> screen offset from the centre. */
// NON_MATCHING: register allocation / scheduling
// decomp-permuter
void func_800FA7E8_TreasureDivers(Vec *pos, Vec *out)
{
  Matrix4f m;
  float new_var;
  f32 w;
  guTranslateF(m, pos->x, pos->y, pos->z);
  guMtxCatF(m, D_800FF140_TreasureDivers, m);
  new_var = m[3][2] * D_800FF258_TreasureDivers;
  if ((w = fabsf(new_var)) != 0.0)
  {
    (*out).x = ((m[3][0] * 160.0f) / w) / 1.3333334f;
    out->y = ((-m[3][1]) * 120.0f) / w;
  }
}

/* Screen offset and depth -> world position. */
// NON_MATCHING: register allocation / scheduling
// decomp-permuter
void func_800FA8B8_TreasureDivers(f32 x, f32 y, f32 z, Vec *out)
{
  int new_var2;
  Matrix4f m;
  float new_var;
  f32 w;
  z += D_800FF178_TreasureDivers;
  w = fabsf(z * D_800FF258_TreasureDivers);
 do { new_var = (2.0f * x) * w; guTranslateF(m, (new_var * 1.3333334f) / 320.0f, -(((2.0f * y) * w) / 240.0f), z); guMtxCatF(m, D_800FFAE0_TreasureDivers, m); } while (0);
  out->x = m[3][0];
  out->y = m[3][1];
  new_var2 = 3;
  out->z = m[new_var2][2];
}

/* Named: KMC as's li.d literals pool apart from an asm unit's .double (8 bytes appear after it). */
const f64 D_800FE680_TreasureDivers __attribute__((section(".rodata"))) = -48.0;
const f64 D_800FE688_TreasureDivers __attribute__((section(".rodata"))) = 104.0;

void func_800FA984_TreasureDivers(s32 unused, f32* x, f32* y, f32* z) {
    if (*x < -144.0f) {
        *x = -144.0f;
    }
    if (*x > 144.0f) {
        *x = 144.0f;
    }
    if (*y < D_800FE680_TreasureDivers) {
        *y = -48.0f;
    }
    if (*y > D_800FE688_TreasureDivers) {
        *y = 104.0f;
    }
}

/* Reads the sea-floor outline: a point table and an index list, both big-endian. */
void func_800FAA34_TreasureDivers(u8* data) {
    s32 off1 = (data[0] << 24) + (data[1] << 16) + (data[2] << 8) + data[3];
    s32 off2 = (data[4] << 24) + (data[5] << 16) + (data[6] << 8) + data[7];
    u8* p = data + off1;
    s16* pt;
    s8* idx;
    s16 i;

    D_800FE770_TreasureDivers = (p[0] << 8) + p[1];
    p += 2;
    pt = (s16*)(D_800FE774_TreasureDivers = HuMemDirectMalloc(D_800FE770_TreasureDivers * sizeof(TDPoint)));
    for (i = 0; i < D_800FE770_TreasureDivers; i++) {
        pt[0] = ((p[0] << 8) + p[1]) - 160;
        p += 2;
        pt[1] = ((p[0] << 8) + p[1]) - 120;
        p += 2;
        pt += 2;
    }
    p = data + off2;
    D_800FE772_TreasureDivers = (p[0] << 8) + p[1];
    p += 2;
    D_800FE778_TreasureDivers = idx = HuMemDirectMalloc(D_800FE772_TreasureDivers);
    for (i = 0; i < D_800FE772_TreasureDivers; i++) {
        *idx++ = *p++;
    }
}

void func_800FABD0_TreasureDivers(void) {
    HuMemDirectFree(D_800FE774_TreasureDivers);
    HuMemDirectFree(D_800FE778_TreasureDivers);
}

/* Pushes a circle of radius r at (*x, *y) out of the sea-floor outline. */
// NON_MATCHING: register allocation / scheduling
#ifdef NON_MATCHING
s32 func_800FABFC_TreasureDivers(f32* x, f32* y, s16 r) {
    TDVec2 hit[256];
    s16 n;
    s16 i;
    s8 prev;
    s8 cur;
    f32 cx;
    f32 cy;
    f32 dx;
    f32 dy;
    f32 ex;
    f32 ey;
    f32 a;
    f32 b;
    f32 disc;
    f32 s;
    f32 t1;
    f32 t2;
    f32 sx;
    f32 sy;
    f32 nx;
    f32 ny;
    f32 len;
    f32 px;
    f32 py;
    f32 cnt;
    f32 c;

    n = 0;
    cx = *x;
    cy = *y;
    prev = D_800FE778_TreasureDivers[0];
    for (i = 1; i < D_800FE772_TreasureDivers;) {
        cur = D_800FE778_TreasureDivers[i++];
        if ((prev >= 0) & (cur >= 0)) {
            dx = D_800FE774_TreasureDivers[cur].x - D_800FE774_TreasureDivers[prev].x;
            dy = D_800FE774_TreasureDivers[cur].y - D_800FE774_TreasureDivers[prev].y;
            ex = D_800FE774_TreasureDivers[prev].x - cx;
            ey = D_800FE774_TreasureDivers[prev].y - cy;
            a = dx * dx + dy * dy;
            b = 2.0f * (dx * ex + dy * ey);
            c = -(r * r) + ex * ex + ey * ey;
            disc = b * b - a * 4.0 * c;
            if (disc > 0.0f) {
                s = sqrtf(disc);
                t1 = (-b - s) / (2.0f * a);
                t2 = (-b + s) / (2.0f * a);
                if (t1 >= 0.0 && t1 <= 1.0) {
                    hit[n].x = D_800FE774_TreasureDivers[prev].x + t1 * dx;
                    hit[n].y = D_800FE774_TreasureDivers[prev].y + t1 * dy;
                    n++;
                }
                if (t2 >= 0.0 && t2 <= 1.0) {
                    hit[n].x = D_800FE774_TreasureDivers[prev].x + t2 * dx;
                    hit[n].y = D_800FE774_TreasureDivers[prev].y + t2 * dy;
                    n++;
                }
            }
        }
        prev = cur;
    }
    if (n >= 2) {
        sx = 0.0f;
        sy = 0.0f;
        for (i = 0; i < n; i++) {
            sx += hit[i].x;
            sy += hit[i].y;
        }
        cnt = n;
        sx /= cnt;
        sy /= cnt;
        px = hit[0].x;
        py = hit[0].y;
        nx = 0.0f;
        ny = 0.0f;
        for (i = 0; i < n - 1; i++) {
            dx = hit[i + 1].y - py;
            dy = -(hit[i + 1].x - px);
            len = sqrtf(dx * dx + dy * dy);
            if (len != 0.0) {
                dx /= len;
                dy /= len;
                nx += dx;
                ny += dy;
            }
            px = hit[i + 1].x;
            py = hit[i + 1].y;
        }
        len = sqrtf(nx * nx + ny * ny);
        if (len != 0.0) {
            nx /= len;
            ny /= len;
            *x = sx + nx * r;
            *y = sy + ny * r;
        }
    }
    return 0;
}
#else
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_04_TreasureDivers/F2800", D_800FE690_TreasureDivers);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_04_TreasureDivers/F2800", D_800FE694_TreasureDivers);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_04_TreasureDivers/F2800", D_800FE698_TreasureDivers);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_04_TreasureDivers/F2800", func_800FABFC_TreasureDivers);
#endif



/* The outline's height at screen x. */
s16 func_800FB1D4_TreasureDivers(f32 x) {
    s8 prev;
    s8 cur;
    s16 i;
    TDPoint* p;
    TDPoint* q;
    f32 t;

    i = 0;
    prev = D_800FE778_TreasureDivers[i++];
    while (i < D_800FE772_TreasureDivers) {
        cur = D_800FE778_TreasureDivers[i++];
        if ((prev >= 0) & (cur >= 0)) {
            if ((D_800FE774_TreasureDivers[prev].x <= x && x < D_800FE774_TreasureDivers[cur].x) ||
                (x < D_800FE774_TreasureDivers[prev].x && D_800FE774_TreasureDivers[cur].x <= x)) {
                q = &D_800FE774_TreasureDivers[cur];
                p = &D_800FE774_TreasureDivers[prev];
                if (q->x != p->x) {
                    t = (x - p->x) / (q->x - p->x);
                    return p->y + t * (q->y - p->y);
                }
            }
        }
        prev = cur;
    }
    return 104;
}

/* The nearest free treasure whose box (grown by w, h) holds (x, y), or -1. */
s16 func_800FB3A8_TreasureDivers(f32 x, f32 y, f32 w, f32 h) {
    TDWork* t;
    s16 best;
    s16 i;
    f32 bestDist;
    f64 adx;
    f64 ady;
    f32 d;

    best = -1;
    bestDist = 999.0f;
    for (i = 0; i < D_800FF25C_TreasureDivers; i++) {
        t = func_800FA614_TreasureDivers(D_800FED08_TreasureDivers[i]);
        if ((s8)t->unk0 < 0 && t->unk5A < 0) {
            adx = fabs(t->pos.x - x);
            if (adx < t->unk4 + w) {
                ady = fabs(t->pos.y - y);
                if (ady < t->unk6 + h) {
                    d = adx + ady;
                    if (d < bestDist) {
                        bestDist = d;
                        best = i;
                    }
                }
            }
        }
    }
    return best;
}

/* The diver whose box overlaps w's: (diver index | its unk0 << 8), or -1. */
s16 func_800FB528_TreasureDivers(TDWork* w) {
    s16 i;

    for (i = 0; i < 3; i++) {
        if ((s8)w->unk0 < 0) {
            if (fabs(D_800FF188_TreasureDivers[i].scr.x - w->pos.x) < w->unk4 + D_800FF188_TreasureDivers[i].unk2 &&
                fabs(D_800FF188_TreasureDivers[i].scr.y - w->pos.y) < w->unk6 + D_800FF188_TreasureDivers[i].unk4) {
                return i | (D_800FF188_TreasureDivers[i].unk0 << 8);
            }
        }
    }
    return -1;
}

s16 func_800FB620_TreasureDivers(TDWork* w, f32 dy) {
    s16 i;
    f32 top;
    f32 h;

    for (i = 0; i < 3; i++) {
        if ((s8)w->unk0 < 0) {
            if (fabs(D_800FF188_TreasureDivers[i].scr.x - w->pos.x) < w->unk4 + D_800FF188_TreasureDivers[i].unk2) {
                if (w->pos.y - dy <= D_800FF188_TreasureDivers[i].oldScr.y - (h = D_800FF188_TreasureDivers[i].unk4)) {
                    top = D_800FF188_TreasureDivers[i].scr.y - h;
                    if (top < w->pos.y) {
                        w->pos.y = top;
                        if (w->unk18 == 0.0) {
                            if (w->unk18 < D_800FF188_TreasureDivers[i].scr.x) {
                                w->unk18 = -1.0f;
                            } else {
                                w->unk18 = 1.0f;
                            }
                        }
                        return i | (D_800FF188_TreasureDivers[i].unk0 << 8);
                    }
                }
            }
        }
    }
    return -1;
}

/* Pushes w out of the other players' circles, sliding along (vx, vy). */
void func_800FB79C_TreasureDivers(TDWork* w, f32 vx, f32 vy) {
    TDWork* o;
    s16 i;
    f32 r;
    f32 or;
    f32 dx;
    f32 dy;
    f32 d;
    f32 push;
    f32 tx;
    f32 ty;
    f32 px;
    f32 py;

    ty = 0.0f;
    tx = 0.0f;
    if (w->unk4 > w->unk6) {
        r = w->unk4;
    } else {
        r = w->unk6;
    }
    for (i = 0; i < D_800F2BC0; i++) {
        o = func_800FA614_TreasureDivers(D_800F3FB0[i]);
        if (o != w && o->unk8 >= 0) {
            dx = o->pos.x - w->pos.x;
            dy = o->pos.y - w->pos.y;
            if (o->unk4 > o->unk6) {
                or = o->unk4;
            } else {
                or = o->unk6;
            }
            d = sqrtf(dx * dx + dy * dy);
            if (d < r + or) {
                if (d != 0.0) {
                    dx /= d;
                    dy /= d;
                }
                push = (r + or) - d;
                px = w->pos.x - dx * push;
                py = w->pos.y - dy * push;
                if (dx == 0.0 || dy == 0.0) {
                    if (dx == 0.0) {
                        tx = 0.0f;
                        ty = -dy;
                    }
                    if (dy == 0.0) {
                        ty = 0.0f;
                        tx = -dx;
                    }
                } else {
                    tx = dy;
                    ty = -dx;
                    if (tx * vx + ty * vy < 0.0f) {
                        tx = -tx;
                        ty = dx;
                    }
                }
                px = px + tx * push * 0.5;
                py = py + ty * push * 0.5;
                w->pos.x = px;
                w->pos.y = py;
            }
        }
    }
}

s16 func_800FBAC8_TreasureDivers(s32 file) {
    void* data = DataRead(file);
    s16 anim = func_800678A4(data);

    DataClose(data);
    return anim & 0xFF;
}

void func_800FBB0C_TreasureDivers(void) {
    unk65770Anim* anim;
    unk65770AnimC* c;
    s16 i;
    s16 spr;
    s16 file;

    D_800FED00_TreasureDivers.unk0 = func_800FBAC8_TreasureDivers(0x160010);
    D_800FED00_TreasureDivers.unk2 = func_800FBAC8_TreasureDivers(0x21);
    D_800FED00_TreasureDivers.unk4 = func_800FBAC8_TreasureDivers(0x440008);
    anim = func_80067310(D_800FED00_TreasureDivers.unk2);
    c = anim->unk0;
    for (i = 0; i < anim->unk10; i++) {
        c->unk8 = c->unkA = 16;
        c++;
    }
    file = func_800FBAC8_TreasureDivers(0x160011);
    spr = func_80064EF4(1, 0);
    func_80067208(spr, 0, file, 0);
    func_800674BC(spr, 0, 0x4000);
    func_80066DC4(spr, 0, 160, 120);
    func_80067354(spr, 0, 2.0f, 1.0f);
    for (i = 0; i < 64; i++) {
        D_800FF260_TreasureDivers[i].active = 0;
        D_800FF260_TreasureDivers[i].type = 0;
        D_800FF260_TreasureDivers[i].sprite = func_80064EF4(1, 0);
        func_80067480(D_800FF260_TreasureDivers[i].sprite, 0, -1);
        func_800674BC(D_800FF260_TreasureDivers[i].sprite, 0, 0xC000);
        D_800FF260_TreasureDivers[i].unk6 = 0;
        D_800FF260_TreasureDivers[i].x = 0;
        D_800FF260_TreasureDivers[i].y = 0;
        D_800FF260_TreasureDivers[i].unk10 = D_800FF260_TreasureDivers[i].unk12 = D_800FF260_TreasureDivers[i].unk14 = D_800FF260_TreasureDivers[i].unk16 = 0;
        D_800FF260_TreasureDivers[i].unk18 = D_800FF260_TreasureDivers[i].unk1A = D_800FF260_TreasureDivers[i].unk1C = D_800FF260_TreasureDivers[i].unk1E = 0;
    }
}

s16 func_800FBD10_TreasureDivers(s16 type, f32 x, f32 y, s16 arg3) {
    s16 i;

    for (i = 0; i < 64; i++) {
        if (D_800FF260_TreasureDivers[i].active == 0) {
            D_800FF260_TreasureDivers[i].active = 1;
            D_800FF260_TreasureDivers[i].type = type;
            D_800FF260_TreasureDivers[i].unk6 = arg3;
            D_800FF260_TreasureDivers[i].x = x;
            D_800FF260_TreasureDivers[i].y = y;
            if (D_800FF260_TreasureDivers[i].sprite >= 0) {
                func_8006752C(D_800FF260_TreasureDivers[i].sprite, 0, 0x100);
                func_80067480(D_800FF260_TreasureDivers[i].sprite, 0, 0xFFFF);
                func_800674BC(D_800FF260_TreasureDivers[i].sprite, 0, 0x1000);
                func_80067354(D_800FF260_TreasureDivers[i].sprite, 0, 1.0f, 1.0f);
                func_800672B0(D_800FF260_TreasureDivers[i].sprite, 0, 1);
            }
            D_800FF260_TreasureDivers[i].unk10 = D_800FF260_TreasureDivers[i].unk12 = D_800FF260_TreasureDivers[i].unk14 = D_800FF260_TreasureDivers[i].unk16 = 0;
            D_800FF260_TreasureDivers[i].unk18 = D_800FF260_TreasureDivers[i].unk1A = D_800FF260_TreasureDivers[i].unk1C = D_800FF260_TreasureDivers[i].unk1E = 0;
            return i;
        }
    }
    return -1;
}

void func_800FBE84_TreasureDivers(s16 i) {
    D_800FF260_TreasureDivers[i].active = 0;
    if (D_800FF260_TreasureDivers[i].sprite >= 0) {
        func_800674BC(D_800FF260_TreasureDivers[i].sprite, 0, 0x8000);
    }
}

void func_800FBEC8_TreasureDivers(void) {
    s16 i;

    for (i = 0; i < 64; i++) {
        if (D_800FF260_TreasureDivers[i].active != 0) {
            switch (D_800FF260_TreasureDivers[i].type) {
                case 0:
                    func_800F92A0_TreasureDivers(i);
                    break;
                case 1:
                    func_800F9580_TreasureDivers(i);
                    break;
                case 2:
                    func_800F9668_TreasureDivers(i);
                    break;
                case 3:
                    func_800F9728_TreasureDivers(i);
                    break;
                case 4:
                    func_800F98B8_TreasureDivers(i);
                    break;
                case 5:
                    func_800F9BAC_TreasureDivers(i);
                    break;
            }
            if (D_800FF260_TreasureDivers[i].active != 0 && D_800FF260_TreasureDivers[i].sprite >= 0) {
                func_80066DC4(D_800FF260_TreasureDivers[i].sprite, 0, D_800FF260_TreasureDivers[i].x + 160.0,
                              D_800FF260_TreasureDivers[i].y + 120.0);
            }
        }
    }
}
