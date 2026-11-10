#include "common.h"

#include "engine/math.h"

typedef struct ColVtx {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 z;
} ColVtx;

typedef struct ColTri {
    /* 0x0 */ s16 flags;
    /* 0x2 */ s16 v[3];
} ColTri;

/* One cell of a collision grid: a run of polygons in the grid's polygon stream. */
typedef struct HitCell {
    /* 0x00 */ s32 offset;
    /* 0x04 */ s16 count;
} HitCell; /* size = 0x8 */

/* Collision grid built from a model's hit data (func_80029174). */
typedef struct HitGrid {
    /* 0x00 */ s32 w;
    /* 0x04 */ s32 h;
    /* 0x08 */ f32 cw;
    /* 0x0C */ f32 ch;
    /* 0x10 */ u16* polys;
    /* 0x14 */ s16* map0;
    /* 0x18 */ s16* map1;
    /* 0x1C */ s16* map2;
    /* 0x20 */ HitCell* cells;
} HitGrid; /* size = 0x24 */

/* Result list of func_8002AE24 (callers declare it as an s32). */
typedef struct HitList {
    /* 0x00 */ u16** list;
    /* 0x04 */ u16 count;
    /* 0x06 */ u16 pos;
} HitList;

typedef struct HitProbe {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
    /* 0x0C */ f32 r;
} HitProbe;

/* Draw-culling views passed by the model draw callbacks. */
typedef struct HitViewCells {
    /* 0x00 */ f32 angle;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 z;
    /* 0x0C */ s32 rx;
    /* 0x10 */ s32 rz;
} HitViewCells;

typedef struct HitViewFan {
    /* 0x00 */ f32 angle;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 z;
    /* 0x0C */ f32 fov;
    /* 0x10 */ f32 len;
    /* 0x14 */ f32 back;
} HitViewFan;

typedef struct HitViewCircle {
    /* 0x00 */ f32 angle;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 z;
    /* 0x0C */ f32 r;
} HitViewCircle;

extern s16 D_800D6000;
extern s16 D_800D6002;
extern s16 D_800D6004;
extern s16* D_800D6008;
extern HitGrid* D_800F32AC;

void MtxRotate(Mat4, f32, f32, f32);
f32 func_800B1750(f32);
s32 func_8002956C(Vec3f*);
f32 func_8002B1A8(ColVtx*, s16, s16, s16, f32*, f32*);
s32 func_8002A784(f32, f32, ColVtx*);
int abs(int);
void guMtxL2F(float mf[4][4], Mtx* m);
void guMtxF2L(float mf[4][4], Mtx* m);
void guMtxCatF(float m[4][4], float n[4][4], float r[4][4]);

#define CLAMP_S16(v) if ((v) > 0x7FFF) { (v) = 0x7FFF; } else if ((v) < -0x8000) { (v) = -0x8000; }


void func_80029090(s16 n) {
    s32 i;

    D_800D6002 = 0;
    D_800F32AC = func_80023684(n * sizeof(HitGrid), 0x55F0);
    D_800D6000 = n;
    D_800D6008 = func_80023684(n * 2, 0x55F0);
    for (i = 0; i < n; i++) {
        D_800D6008[i] = i + 1;
    }
    D_800D6004 = 0;
}
s32 func_80029140(s16 idx) {
    return D_800F32AC[idx].w == D_800F32AC[idx].h;
}
s32 func_80029174(s16 mi) {
    s16 idx;
    u8* p;
    u32 size;
    HitGrid* g;
    HitCell* cell;
    u16 y;
    u16 x;
    u16* dst;
    u32 i;
    union { s32 i; f32 f; } u;

    if (D_800D6002 != D_800D6000) {
        idx = D_800D6004;
        D_800D6004 = D_800D6008[idx];
        p = D_800F2B7C[mi].unk_6C->unk_60;
        size = ((p[4] << 24) | (p[5] << 16) | (p[6] << 8) | p[7]) - 0x10;
        g = &D_800F32AC[idx];
        g->w = (p[8] << 8) | p[9];
        g->h = (p[10] << 8) | p[11];
        u.i = (p[16] << 24) | (p[17] << 16) | (p[18] << 8) | p[19];
        g->cw = u.f;
        u.i = (p[20] << 24) | (p[21] << 16) | (p[22] << 8) | p[23];
        g->ch = u.f;
        cell = g->cells = func_80023684((g->h << 3) * g->w, 0x55F0);
        p += 0x18;
        g->map0 = func_80023684((g->h << 1) * g->w, 0x55F0);
        g->map1 = func_80023684((g->h << 1) * g->w, 0x55F0);
        g->map2 = func_80023684((g->h << 1) * g->w, 0x55F0);
        for (y = 0; y < g->h; y++) {
            for (x = 0; x < g->w; x++) {
                g->map0[y * g->w + x] = (p[0] << 8) | p[1];
                g->map1[y * g->w + x] = (p[2] << 8) | p[3];
                g->map2[y * g->w + x] = (p[4] << 8) | p[5];
                cell->offset = (p[6] << 24) | (p[7] << 16) | (p[8] << 8) | p[9];
                cell->count = (p[10] << 8) | p[11];
                p += 0xC;
                cell++;
                size -= 0xC;
            }
        }
        dst = g->polys = func_80023684(size, 0x55F0);
        for (i = 0; i < size; i += 2) {
            *dst = (p[0] << 8) | p[1];
            dst++;
            p += 2;
        }
        D_800D6002++;
        return idx;
    }
    return -1;
}
f32 func_80029518(f32 angle) {
    if (angle >= 360.0f) {
        angle -= 360.0f;
    } else if (angle < 0.0f) {
        angle += 360.0f;
    }
    return angle;
}
s32 func_8002956C(Vec3f* v) {
    f32 x = v->x;
    f32 y = v->y;
    f32 z = v->z;
    f32 len = func_800B1750(x * x + y * y + z * z);
    s32 ret = 0;

    if (len != 0.0f) {
        v->x /= len;
        v->y /= len;
        v->z /= len;
        ret = 1;
    }
    return ret;
}
void func_800295FC(ColVtx* a, ColVtx* b, ColVtx* c, Vec3f* n) {
    f32 abx = (f32)b->x - (f32)a->x;
    f32 aby = (f32)b->y - (f32)a->y;
    f32 abz = (f32)b->z - (f32)a->z;
    f32 acx = (f32)c->x - (f32)a->x;
    f32 acy = (f32)c->y - (f32)a->y;
    f32 acz = (f32)c->z - (f32)a->z;

    n->x = aby * acz - abz * acy;
    n->y = abz * acx - abx * acz;
    n->z = abx * acy - aby * acx;
    func_8002956C(n);
}
f32 func_800296FC(f32 x, f32 z, ColVtx* a, ColVtx* b) {
    f32 ax = a->x - x;
    f32 az = a->z - z;
    f32 bx = b->x - x;
    f32 bz = b->z - z;

    return -(az * bx - ax * bz);
}
f32 func_80029764(f32 x, f32 y, f32 z, ColVtx* verts, ColTri* tri) {
    Vec3f n;
    Vec3f p;
    f32 nx;
    f32 ny;
    f32 nz;
    ColVtx* v = &verts[tri->v[0]];

    p.x = v->x;
    p.y = v->y;
    p.z = v->z;
    func_800295FC(&verts[tri->v[0]], &verts[tri->v[1]], &verts[tri->v[2]], &n);
    nx = n.x;
    ny = n.y;
    nz = n.z;
    return y + (nx * (p.x - x) + ny * (p.y - y) + nz * (p.z - z)) / ny;
}
s32 func_80029874(f32 x, f32 z, s16* poly, ColVtx* verts) {
    Vec3f n;
    s32 cnt;
    s32 i;
    s32 j;

    func_800295FC(&verts[poly[1]], &verts[poly[2]], &verts[poly[3]], &n);
    if (n.y == 0.0f) {
        return 0;
    }
    cnt = ((u16)poly[0] >> 14) + 2;
    poly++;
    if (func_800296FC(x, z, &verts[poly[0]], &verts[poly[1]]) > 0.0f) {
        for (i = 1; i < cnt; i++) {
            j = (i + 1) % cnt;
            if (func_800296FC(x, z, &verts[poly[i]], &verts[poly[j]]) < 0.0f) {
                return 0;
            }
        }
    } else {
        for (i = 1; i < cnt; i++) {
            j = (i + 1) % cnt;
            if (func_800296FC(x, z, &verts[poly[i]], &verts[poly[j]]) > 0.0f) {
                return 0;
            }
        }
    }
    return 1;
}
void func_80029AEC(unk_ovl_2D_struct* m, Matrix4f mtx) {
    Matrix4f tmp;
    unk2C0C0Struct40* xf;

    D_800ECB14 = m->unk_20;
    guMtxL2F(mtx, (Mtx*)((u8*)D_800F32A0 + D_800F3FA8 * 0x80 + 0x138));
    if (m->unk_24 != 0.0f || m->unk_28 != 0.0f || m->unk_2C != 0.0f) {
        MtxTranslate(mtx, m->unk_24, m->unk_28, m->unk_2C);
    }
    if (m->unk_30 != 0.0f || m->unk_34 != 0.0f || m->unk_38 != 0.0f) {
        MtxRotate(mtx, m->unk_30, m->unk_34, m->unk_38);
    }
    if (m->unk_3C != 1.0f || m->unk_40 != 1.0f || m->unk_44 != 1.0f) {
        MtxScale(mtx, m->unk_3C, m->unk_40, m->unk_44);
    }
    MtxMult(m->unk7C, mtx, mtx);
    xf = m->unk_6C->unk_88;
    guMtxIdentF(tmp);
    if (xf->unk_08.x == 0.0f || xf->unk_08.y == 0.0f || xf->unk_08.z == 0.0f) {
        MtxTranslate(tmp, xf->unk_08.x, xf->unk_08.y, xf->unk_08.z);
    }
    if (xf->unk_14.x == 0.0f || xf->unk_14.y == 0.0f || xf->unk_14.z == 0.0f) {
        MtxRotate(tmp, xf->unk_14.x, xf->unk_14.y, xf->unk_14.z);
    }
    if (xf->unk_20.x != 1.0f || xf->unk_20.y != 1.0f || xf->unk_20.z != 1.0f) {
        MtxScale(tmp, xf->unk_20.x, xf->unk_20.y, xf->unk_20.z);
    }
    guMtxCatF(tmp, mtx, mtx);
    guMtxF2L(mtx, (Mtx*)((u8*)D_800F374C + D_800ED52C * 0x40));
}
void func_80029DB8(HitViewCells* view, unk_ovl_2D_struct* m) {
    Matrix4f mtx;
    Matrix4f ident;
    s16 gi;
    s32 x0;
    s32 x1;
    s32 z0;
    s32 z1;
    s32 x;
    s32 z;
    s32 idx;
    s16 id;

    gi = m->unk_04;
    func_80029AEC(m, mtx);
    guMtxIdentF(ident);
    x = abs(((D_800F32AC[gi].w * D_800F32AC[gi].cw) / 2.0f + view->x + m->unk_24 - 2.0f * func_800AEAC0(view->angle) * D_800F32AC[gi].cw) / D_800F32AC[gi].cw);
    z = abs(((D_800F32AC[gi].h * D_800F32AC[gi].ch) / 2.0f + view->z + m->unk_2C - 2.0f * func_800AEFD0(view->angle) * D_800F32AC[gi].ch) / D_800F32AC[gi].ch);
    x0 = x - view->rx;
    x1 = x + view->rx + 1;
    z0 = z - view->rz;
    z1 = z + view->rz + 1;
    if (x0 < 0) {
        x0 = 0;
    }
    if (z0 < 0) {
        z0 = 0;
    }
    if (D_800F32AC[gi].w < x1) {
        x1 = D_800F32AC[gi].w;
    }
    if (D_800F32AC[gi].h < z1) {
        z1 = D_800F32AC[gi].h;
    }
    for (z = z0; z < z1; z++) {
        for (x = x0; x < x1; x++) {
            idx = z * D_800F32AC[gi].w + x;
            id = D_800F32AC[gi].map0[idx];
            if (id != -1) {
                func_8002D2CC(m->unk_6C, id, (u8*)D_800F374C + D_800ED52C * 0x40, mtx);
            }
            id = D_800F32AC[gi].map1[idx];
            if (id != -1) {
                func_8002D2CC(m->unk_6C, id, (u8*)D_800F374C + D_800ED52C * 0x40, mtx);
            }
            id = D_800F32AC[gi].map2[idx];
            if (id != -1) {
                func_8002D2CC(m->unk_6C, id, (u8*)D_800F374C + D_800ED52C * 0x40, mtx);
            }
        }
    }
    D_800ED52C++;
}
// register allocation: view/model pointers and loop counters take shifted saved registers (masked 0)
#ifdef NON_MATCHING
void func_8002A0E4(HitViewFan* view, unk_ovl_2D_struct* m) {
    ColVtx tri[3];
    Matrix4f mtx;
    Matrix4f ident;
    f32* fan;
    s16 gi;
    s32 t;
    s32 x;
    s32 z;
    s32 idx;
    s32 id;
    f32 x0;
    f32 x1;
    f32 z0;
    f32 z1;

    fan = &view->fov;
    gi = m->unk_04;
    func_80029AEC(m, mtx);
    guMtxIdentF(ident);
    func_800AEAC0(view->angle);
    t = (D_800F32AC[gi].w * D_800F32AC[gi].cw) / 2.0f;
    func_800AEFD0(view->angle);
    tri[0].y = tri[1].y = tri[2].y = 0;
    t = (D_800F32AC[gi].w * D_800F32AC[gi].cw) / 2.0f + view->x + func_800AEAC0(view->angle) * view->back;
    CLAMP_S16(t);
    tri[0].x = t;
    t = (D_800F32AC[gi].h * D_800F32AC[gi].ch) / 2.0f + view->z + func_800AEFD0(view->angle) * fan[2];
    CLAMP_S16(t);
    tri[0].z = t;
    t = tri[0].x - func_800AEAC0(fan[0] / 2.0f + view->angle) * fan[1];
    CLAMP_S16(t);
    tri[1].x = t;
    t = tri[0].z - func_800AEFD0(fan[0] / 2.0f + view->angle) * fan[1];
    CLAMP_S16(t);
    tri[1].z = t;
    t = tri[0].x - func_800AEAC0(view->angle - fan[0] / 2.0f) * fan[1];
    CLAMP_S16(t);
    tri[2].x = t;
    t = tri[0].z - func_800AEFD0(view->angle - fan[0] / 2.0f) * fan[1];
    CLAMP_S16(t);
    tri[2].z = t;
    for (z = 0; z < D_800F32AC[gi].h; z++) {
        z0 = z * D_800F32AC[gi].ch + m->unk_2C;
        z1 = z0 + D_800F32AC[gi].ch;
        for (x = 0; x < D_800F32AC[gi].w; x++) {
            idx = z * D_800F32AC[gi].w + x;
            x0 = x * D_800F32AC[gi].cw + m->unk_24;
            x1 = x0 + D_800F32AC[gi].cw;
            id = D_800F32AC[gi].map0[idx];
            if (id != -1 && (func_8002A784(x0, z0, tri) == 1 || func_8002A784(x1, z0, tri) == 1 ||
                             func_8002A784(x0, z1, tri) == 1 || func_8002A784(x1, z1, tri) == 1)) {
                func_8002D2CC(m->unk_6C, id, (u8*)D_800F374C + D_800ED52C * 0x40, ident);
            }
            id = D_800F32AC[gi].map1[idx];
            if (id != -1 && (func_8002A784(x0, z0, tri) == 1 || func_8002A784(x1, z0, tri) == 1 ||
                             func_8002A784(x0, z1, tri) == 1 || func_8002A784(x1, z1, tri) == 1)) {
                func_8002D2CC(m->unk_6C, id, (u8*)D_800F374C + D_800ED52C * 0x40, mtx);
            }
            id = D_800F32AC[gi].map2[idx];
            if (id != -1 && (func_8002A784(x0, z0, tri) == 1 || func_8002A784(x1, z0, tri) == 1 ||
                             func_8002A784(x0, z1, tri) == 1 || func_8002A784(x1, z1, tri) == 1)) {
                func_8002D2CC(m->unk_6C, id, (u8*)D_800F374C + D_800ED52C * 0x40, mtx);
            }
        }
    }
    D_800ED52C++;
}
#else
INCLUDE_ASM("asm/nonmatchings/29C90", func_8002A0E4);
#endif
s32 func_8002A784(f32 x, f32 z, ColVtx* v) {
    s32 i;
    s32 j;
    f32 f;

    if (func_800296FC(x, z, &v[0], &v[1]) > 0.0f) {
        for (i = 1; i < 3; i++) {
            j = (i + 1) % 3;
            f = func_800296FC(x, z, &v[i], &v[j]);
            if (f == 0.0f) {
                return 1;
            }
            if (f < 0.0f) {
                return 0;
            }
        }
    } else {
        for (i = 1; i < 3; i++) {
            j = (i + 1) % 3;
            f = func_800296FC(x, z, &v[i], &v[j]);
            if (f == 0.0f) {
                return 1;
            }
            if (f > 0.0f) {
                return 0;
            }
        }
    }
    return 1;
}

// decomp-permuter
void func_8002A92C(HitViewCircle *view, unk_ovl_2D_struct *m)
{
  Matrix4f mtx;
  Matrix4f ident;
  f32 *rp;
  s16 gi;
  s32 x0;
  s32 x1;
  s32 z0;
  s32 z1;
  s32 x;
  s32 z;
  s32 idx;
  unsigned int id;
  f32 dx;
  f32 dz;
  rp = &view->r;
  gi = m->unk_04;
  func_80029AEC(m, mtx);
  guMtxIdentF(ident);
  x0 = ((view->x - view->r) + ((D_800F32AC[gi].w * D_800F32AC[gi].cw) / 2.0f)) / D_800F32AC[gi].cw;
  x1 = ((view->x + view->r) + ((D_800F32AC[gi].w * D_800F32AC[gi].cw) / 2.0f)) / D_800F32AC[gi].cw;
  z0 = ((view->z - view->r) + ((D_800F32AC[gi].h * D_800F32AC[gi].ch) / 2.0f)) / D_800F32AC[gi].ch;
  z1 = ((view->z + view->r) + ((D_800F32AC[gi].h * D_800F32AC[gi].ch) / 2.0f)) / D_800F32AC[gi].ch;
  if (x0 < 0)
  {
    x0 = 0;
  }
  if (z0 < 0)
  {
    z0 = 0;
  }
  if (D_800F32AC[gi].w < x1)
  {
    x1 = D_800F32AC[gi].w;
  }
  if (D_800F32AC[gi].h < z1)
  {
    z1 = D_800F32AC[gi].h;
  }
  for (z = z0; z < z1; z++)
  {
    dz = (((z * D_800F32AC[gi].ch) + m->unk_2C) + (D_800F32AC[gi].ch / 2.0f)) - (((D_800F32AC[gi].h * D_800F32AC[gi].ch) / 2.0f) + view->z);
    for (x = x0; x < x1; x++)
    {
      dx = (((x * D_800F32AC[gi].cw) + m->unk_24) + (D_800F32AC[gi].cw / 2.0f)) - (((D_800F32AC[gi].w * D_800F32AC[gi].cw) / 2.0f) + view->x);
      if (func_800B1750((dx * dx) + (dz * dz)) < (*rp))
      {
        idx = (z * D_800F32AC[gi].w) + x;
        id = D_800F32AC[gi].map0[idx];
        if (id != (-1))
        {
          func_8002D2CC(m->unk_6C, id, ((u8 *) D_800F374C) + (D_800ED52C * 0x40), mtx);
        }
        id = D_800F32AC[gi].map1[idx];
        if (id != (-1))
        {
          func_8002D2CC(m->unk_6C, id, ((u8 *) D_800F374C) + (D_800ED52C * 0x40), mtx);
        }
        id = D_800F32AC[gi].map2[idx];
        if (id != (-1))
        {
          func_8002D2CC(m->unk_6C, id, ((u8 *) D_800F374C) + (D_800ED52C * 0x40), mtx);
        }
      }
    }

  }

  D_800ED52C++;
}
void func_8002AD04(void) {
    func_800237BC(0x55F0);
    D_800D6000 = 0;
    D_800D6002 = 0;
}
void func_8002AD30(s16 idx) {
    HitGrid* g;

    if (D_800D6002 != 0) {
        g = &D_800F32AC[idx];
        func_80023728(g->cells);
        func_80023728(g->map0);
        func_80023728(g->map1);
        func_80023728(g->map2);
        func_80023728(g->polys);
        D_800D6002--;
        D_800D6008[idx] = D_800D6004;
        D_800D6004 = idx;
    }
}
void func_8002ADF0(s32* arg0, s32 n) {
    ((HitList*)arg0)->list = func_80023684((u16)n * sizeof(u16*), 0x55F0);
}
// scheduling: the list-pointer copy lands after the cb/probe spills (masked 2)
#ifdef NON_MATCHING
void func_8002AE24(s16 mi, s32* arg1, s32 (*cb)(s32, u16*, unk2C0C0StructA0*, HitProbe*), HitProbe* probe) {
    HitList* l = (HitList*)arg1;
    s32 x0;
    s32 z1;
    unk2C0C0StructC0* mdl;
    unk_ovl_2D_struct* m;
    HitGrid* g;
    HitCell* cell;
    u16** out;
    u16* p;
    s32 x1;
    s32 z0;
    s32 x;
    s32 z;
    s32 i;

    l->pos = 0;
    l->count = 0;
    mdl = (D_800F2B7C + mi)->unk_6C;
    m = D_800F2B7C + mi;
    g = &D_800F32AC[m->unk_04];
    x = ((g->w * g->cw) / 2.0f + probe->x) / g->cw;
    z = ((g->h * g->ch) / 2.0f + probe->z) / g->ch;
    x0 = x - 1;
    x1 = x + 2;
    z0 = z - 1;
    z1 = z + 2;
    if (x0 < 0) {
        x0 = 0;
    }
    if (z0 < 0) {
        z0 = 0;
    }
    if (g->w < x1) {
        x1 = g->w;
    }
    if (g->h < z1) {
        z1 = g->h;
    }
    out = l->list;
    for (z = z0; z < z1; z++) {
        for (x = x0; x < x1; x++) {
            cell = &g->cells[z * g->w + x];
            if (cell->count != 0) {
                p = &g->polys[cell->offset];
                for (i = 0; i < cell->count; i++) {
                    if (cb((*p >> 14) + 2, p + 1, mdl->unk_78, probe) != 0) {
                        *out++ = p;
                        l->count++;
                    }
                    p += (*p >> 14) + 3;
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/29C90", func_8002AE24);
#endif

s32 func_8002B074(u16 n, s16* idx, ColVtx* verts, HitProbe* probe) {
    f32 cx;
    f32 cz;
    f32 r;

    if (n == 4) {
        r = func_8002B1A8(verts, idx[0], idx[2], idx[3], &cx, &cz) + probe->r;
        cx -= probe->x;
        cz -= probe->z;
        if (cx * cx + cz * cz < r * r) {
            return 1;
        }
    }
    r = func_8002B1A8(verts, idx[0], idx[1], idx[2], &cx, &cz) + probe->r;
    cx -= probe->x;
    cz -= probe->z;
    return cx * cx + cz * cz < r * r;
}
f32 func_8002B1A8(ColVtx* verts, s16 a, s16 b, s16 c, f32* cx, f32* cz) {
    f32 dx;
    f32 dz;
    f32 ex;
    f32 ez;

    *cx = (verts[a].x + verts[b].x + verts[c].x) / 3;
    *cz = (verts[a].z + verts[b].z + verts[c].z) / 3;
    dx = verts[a].x - *cx;
    dz = verts[a].z - *cz;
    ex = verts[b].x - *cx;
    ez = verts[b].z - *cz;
    if (dx * dx + dz * dz < ex * ex + ez * ez) {
        dx = ex;
        dz = ez;
    }
    ex = verts[c].x - *cx;
    ez = verts[c].z - *cz;
    if (dx * dx + dz * dz < ex * ex + ez * ez) {
        dx = ex;
        dz = ez;
    }
    return func_800B1750(dx * dx + dz * dz);
}
u16* func_8002B3A8(HitList* l) {
    if (l->pos != l->count) {
        return l->list[l->pos++];
    }
    return NULL;
}
void func_8002B3DC(HitList* l, s32 off, u16 mode) {
    s32 t;

    switch (mode) {
        case 0:
            if (off >= 0 && off + l->pos < l->count) {
                l->pos = off;
            }
            break;
        case 1:
            if (off + l->pos >= 0 && off + l->pos < l->count) {
                l->pos += off;
            }
            break;
        case 2:
            if (off <= 0 && off + l->pos >= 0) {
                t = off + 0xFFFF; /* == off - 1 as a u16 */
                l->pos = l->count + t;
            }
            break;
    }
}
void func_8002B498(HitList* l) {
    func_80023728(l->list);
}