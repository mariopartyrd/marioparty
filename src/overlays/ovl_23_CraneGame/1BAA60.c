#include "CraneGame.h"

/* .data (0x800FF8E0..0x800FF940): the opening camera swing's Bezier control points (func_800FE874);
   element 2 of each curve is rewritten every frame. */
Vec D_800FF8E0_CraneGame[3] = { { -430.0f, 700.0f, 500.0f }, { -430.0f, 750.0f, 550.0f }, { 0.0f, 0.0f, 0.0f } }; /* look-at */
Vec D_800FF904_CraneGame[3] = { { -430.0f, 500.0f, 200.0f }, { 500.0f, 750.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }; /* eye */
f32 D_800FF928_CraneGame[3] = { 700.0f, 300.0f, 1000.0f }; /* zoom */

/* Collision against registered models (func_800FDC94: sweep a point and stop it at the first face)
   and the camera (func_800FEB08: frames the points queued with func_800FE80C each frame). */

void func_800FD240_CraneGame(void) {
    D_80100A50_CraneGame = 0;
    D_80100A52_CraneGame = func_8002451C(0, func_800FD3D0_CraneGame, 2);
}

void func_800FD278_CraneGame(void) {
    CGColGroup* g;
    void* p;
    s32 i;
    s32 j;

    if (D_80100A50_CraneGame != 0) {
        for (i = 0; i < D_80100A50_CraneGame; i++) {
            g = D_80100750_CraneGame[i].groups;
            for (j = 0; j < D_80100750_CraneGame[i].count; j++) {
                p = g->faces;
                g++;
                HuMemDirectFree(p);
            }
            HuMemDirectFree(D_80100750_CraneGame[i].groups);
            HuMemDirectFree(D_80100750_CraneGame[i].verts);
        }
    }
    D_80100A50_CraneGame = 0;
    func_8002456C(D_80100A52_CraneGame);
}

void func_800FD37C_CraneGame(s16 model) {
    func_800FD604_CraneGame(&D_80100750_CraneGame[D_80100A50_CraneGame], model);
    D_80100A50_CraneGame++;
}

/* The draw-pass callback: refreshes each group's world-to-group matrix. */
void func_800FD3D0_CraneGame(Gfx** gfx, Mtx* mtx, camera* cam) {
    Matrix4f m1;
    Matrix4f m2;
    Matrix4f inv;
    CGCol* e;
    unk_ovl_2D_struct* p;
    unk2C0C0StructC0* m;
    unk2C0C0Struct30* o;
    CGColGroup* g;
    s32 i;
    s32 j;

    func_800A0B90(m1, mtx + 1);
    func_8009EA40(m2, -m1[3][0], -m1[3][1], -m1[3][2]);
    MtxInv(m1, inv);
    func_800AC0B0(m2, inv, inv);
    for (i = 0; i < D_80100A50_CraneGame; i++) {
        e = &D_80100750_CraneGame[i];
        p = &D_800F2B7C[e->model];
        if (p->unk_6C != NULL && !(p->unk_20 & 4)) {
            m = p->unk_6C;
            if (e->unk2 != 0) {
                e->unk2--;
            }
            for (j = 0; j < (m->unk_6A & 0x3F); j++) {
                o = &m->unk_80[j];
                g = &e->groups[j];
                func_800A0B90(m1, D_800ED0D8[m->unk_28][o->unk_12].unk_44);
                func_800AC0B0(m1, inv, m1);
                MtxInv(m1, m2);
                func_8009EA40(m1, -m1[3][0], -m1[3][1], -m1[3][2]);
                func_800AC0B0(m1, m2, g->mtx);
            }
        }
    }
}

/* Retail stores the group count from the low byte of unk_6A (a byte read at +1). */
// decomp-permuter
void func_800FD604_CraneGame(CGCol *e, s16 model)
{
  unk2C0C0StructC0 *m;
  unk2C0C0Struct30 *g30;
  CGColGroup *g;
  s32 size;
  s32 i;
  m = D_800F2B7C[model].unk_6C;
  e->model = model;
  e->unk2 = 4;
  size = m->unk_6E * (sizeof(unk2C0C0StructA0));
  e->verts = HuMemDirectMalloc(size);
  func_80023A38(m->unk_78, e->verts, size);
  e->count = (u8) m->unk_6A;
  size = e->count;
  e->groups = HuMemDirectMalloc(size * (sizeof(CGColGroup)));
  for (i = 0; i < m->unk_6A; i++)
  {
    g30 = &m->unk_80[i];
    g = &e->groups[i];
    g->radius = sqrtf(((g30->unk_50 * g30->unk_50) + (g30->unk_52 * g30->unk_52)) + (g30->unk_54 * g30->unk_54));
    g->n = g30->unk_04;
    g->faces = HuMemDirectMalloc(g->n * (sizeof(CGColFace)));
    size = g->n;
    func_800FD7B4_CraneGame(e->verts, g->faces, g30->unk_34, size);
  }

}

#define CG_ABS(x) ((x) < 0.0f ? -(x) : (x))

void func_800FD7B4_CraneGame(unk2C0C0StructA0* verts, CGColFace* out, unk2C0C0Struct20* f, s16 n) {
    Vec p;
    Vec e1;
    Vec e2;
    f32 inv;
    s32 i;
    s32 j;

    for (i = 0; i < n; out++, i++, f++) {
        for (j = 0; j < 4; j++) {
            out->v[j] = f->unk_04[j];
        }
        if ((f->unk_00 & 7) < 4U) {
            out->v[3] = -1;
        }
        p.x = verts[out->v[1]].unk_00;
        e1.x = verts[out->v[0]].unk_00 - p.x;
        e2.x = verts[out->v[2]].unk_00 - p.x;
        p.y = verts[out->v[1]].unk_02;
        e1.y = verts[out->v[0]].unk_02 - p.y;
        e2.y = verts[out->v[2]].unk_02 - p.y;
        p.z = verts[out->v[1]].unk_04;
        e1.z = verts[out->v[0]].unk_04 - p.z;
        e2.z = verts[out->v[2]].unk_04 - p.z;
        out->nx = e1.y * e2.z - e1.z * e2.y;
        out->ny = e1.z * e2.x - e1.x * e2.z;
        out->nz = e1.x * e2.y - e1.y * e2.x;
        inv = 1.0 / sqrtf(out->nx * out->nx + out->ny * out->ny + out->nz * out->nz);
        out->nx = inv * out->nx;
        out->ny = inv * out->ny;
        out->nz = inv * out->nz;
        out->d = -(p.x * out->nx + p.y * out->ny + p.z * out->nz);
        if (CG_ABS(out->nx) >= CG_ABS(out->ny)) {
            out->axis = (CG_ABS(out->nx) >= CG_ABS(out->nz)) ? 0 : 2;
        } else {
            out->axis = (CG_ABS(out->ny) >= CG_ABS(out->nz)) ? 1 : 2;
        }
    }
}

// retail steps the output pointer by 4 before the z store (masked 3)
#ifdef NON_MATCHING
void func_800FDBF8_CraneGame(Matrix4f m, f32 x, f32 y, f32 z, Vec* out) {
    out->x = x * m[0][0] + y * m[1][0] + z * m[2][0] + m[3][0];
    out->y = x * m[0][1] + y * m[1][1] + z * m[2][1] + m[3][1];
    out->z = x * m[0][2] + y * m[1][2] + z * m[2][2] + m[3][2];
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CraneGame/1BAA60", func_800FDBF8_CraneGame);
#endif

/* Moves pos by (dx, dy, dz), stopped at the first collision face of any registered model other than
   `skip`. Returns 1 when something was hit. */
// retail reloads D_80100A58 for the second component (masked 16)
#ifdef NON_MATCHING
s32 func_800FDC94_CraneGame(Vec* pos, f32 dx, f32 dy, f32 dz, s16 skip) {
    Vec to;
    Vec a;
    Vec b;
    CGCol* e;
    CGColGroup* g;
    s32 i;
    s32 j;
    s32 ret;

    D_80100A58_CraneGame = 1.1f;
    to.x = dx + pos->x;
    to.y = dy + pos->y;
    to.z = dz + pos->z;
    for (i = 0; i < D_80100A50_CraneGame; i++) {
        if (D_80100750_CraneGame[i].model == skip) {
            continue;
        }
        if (D_80100750_CraneGame[i].unk2 != 0) {
            continue;
        }
        D_80100A54_CraneGame = D_80100750_CraneGame[i].verts;
        g = D_80100750_CraneGame[i].groups;
        for (j = 0; j < D_80100750_CraneGame[i].count; j++, g++) {
            func_800FDBF8_CraneGame(g->mtx, pos->x, pos->y, pos->z, &a);
            func_800FDBF8_CraneGame(g->mtx, to.x, to.y, to.z, &b);
            b.x -= a.x;
            b.y -= a.y;
            b.z -= a.z;
            if (func_800FDF54_CraneGame(&a, &b, g->radius) != 0) {
                func_800FE0A4_CraneGame(g->faces, g->n, &a, &b);
            }
        }
    }
    ret = 0;
    if (D_80100A58_CraneGame < 0.0 || D_80100A58_CraneGame > 1.0) {
        D_80100A58_CraneGame = 1.0f;
    } else {
        ret = 1;
    }
    pos->x = dx * D_80100A58_CraneGame + pos->x;
    pos->y = dy * D_80100A58_CraneGame + pos->y;
    pos->z = dz * D_80100A58_CraneGame + pos->z;
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CraneGame/1BAA60", func_800FDC94_CraneGame);
#endif

/* Whether the segment p + t * d (t in 0..1) passes within r of the origin. */
s32 func_800FDF54_CraneGame(Vec* p, Vec* d, f32 r) {
    f32 l2;
    f32 t;
    f32 rr;
    f32 x;
    f32 y;
    f32 z;
    s32 ret;

    l2 = d->x * d->x + d->y * d->y + d->z * d->z;
    t = -l2;
    t = (p->x * d->x + p->y * d->y + p->z * d->z) / t;
    rr = r / sqrtf(l2);
    ret = 0;
    if (!(t + rr < 0.0) && !(t - rr > 1.0)) {
        x = t * d->x + p->x;
        y = t * d->y + p->y;
        z = t * d->z + p->z;
        x = x * x + y * y + z * z;
        if (!(r * r <= x)) {
            ret = 1;
        }
    }
    return ret;
}

/* Intersects the segment p + t * d with the faces and keeps the nearest t in D_80100A58. */
// register allocation (masked 43)
#ifdef NON_MATCHING
void func_800FE0A4_CraneGame(CGColFace* f, s16 n, Vec* p, Vec* d) {
    unk2C0C0StructA0* prev;
    unk2C0C0StructA0* cur;
    f32 px;
    f32 py;
    f32 pz;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dn;
    s16 ix;
    s16 iy;
    s16 iz;
    s32 i;
    s32 j;
    s32 nv;
    s32 sgn;
    s32 c;

    px = p->x;
    py = p->y;
    pz = p->z;
    dx = d->x;
    dy = d->y;
    dz = d->z;
    for (i = 0; i < n; i++, f++) {
        dn = dx * f->nx + dy * f->ny + dz * f->nz;
        if (dn == 0.0) {
            continue;
        }
        dn = -(px * f->nx + py * f->ny + pz * f->nz + f->d) / dn;
        if (dn < 0.0) {
            continue;
        }
        if (D_80100A58_CraneGame <= dn) {
            continue;
        }
        ix = px + dn * dx;
        iy = py + dn * dy;
        iz = pz + dn * dz;
        if (f->v[3] >= 0) {
            prev = &D_80100A54_CraneGame[f->v[3]];
            nv = 4;
        } else {
            prev = &D_80100A54_CraneGame[f->v[2]];
            nv = 3;
        }
        switch (f->axis) {
            case 0:
                sgn = (0.0f <= f->nx) ? 1 : -1;
                for (j = 0; j < nv; j++, prev = cur) {
                    cur = &D_80100A54_CraneGame[f->v[j]];
                    c = (iy - prev->unk_02) * (cur->unk_04 - prev->unk_04) - (iz - prev->unk_04) * (cur->unk_02 - prev->unk_02);
                    if (c != 0 && (sgn ^ c) < 0) {
                        break;
                    }
                }
                break;
            case 1:
                sgn = (0.0f <= f->ny) ? 1 : -1;
                for (j = 0; j < nv; j++, prev = cur) {
                    cur = &D_80100A54_CraneGame[f->v[j]];
                    c = (iz - prev->unk_04) * (cur->unk_00 - prev->unk_00) - (ix - prev->unk_00) * (cur->unk_04 - prev->unk_04);
                    if (c != 0 && (sgn ^ c) < 0) {
                        break;
                    }
                }
                break;
            case 2:
                sgn = (0.0f <= f->nz) ? 1 : -1;
                for (j = 0; j < nv; j++, prev = cur) {
                    cur = &D_80100A54_CraneGame[f->v[j]];
                    c = (ix - prev->unk_00) * (cur->unk_02 - prev->unk_02) - (iy - prev->unk_02) * (cur->unk_00 - prev->unk_00);
                    if (c != 0 && (sgn ^ c) < 0) {
                        break;
                    }
                }
                break;
            default:
                osSyncPrintf("Normal Error!\n");
                continue;
        }
        if (j < nv) {
            continue;
        }
        D_80100A58_CraneGame = dn;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CraneGame/1BAA60", func_800FE0A4_CraneGame);
#endif

f32 func_800FE518_CraneGame(f32 x, f32 z) {
    f32 a;

    a = func_800B0CD8(z, x);
    if (a < 0.0) {
        a += 360.0;
    } else if (a >= 360.0) {
        a -= 360.0;
    }
    return a;
}

// retail steps the output pointer by 4 before the y/z stores (masked 4)
#ifdef NON_MATCHING
void func_800FE598_CraneGame(Vec* v, Vec* out) {
    out->x = func_800FE518_CraneGame(sqrtf(v->x * v->x + v->z * v->z), -v->y);
    out->y = func_800FE518_CraneGame(v->z, v->x);
    out->z = 0.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CraneGame/1BAA60", func_800FE598_CraneGame);
#endif

void func_800FE620_CraneGame(void) {
    D_80100A60_CraneGame = 0;
    D_80100A5C_CraneGame = 0;
    D_80100A5E_CraneGame = 2;
    D_80100A66_CraneGame = 30;
    D_80100A68_CraneGame = 60;
}

void func_800FE658_CraneGame(void) {
    Matrix4f m;
    Vec v;

    D_80100A5C_CraneGame = 1;
    D_80100A78_CraneGame[0] = D_80100AA0_CraneGame[0] = CRot.x;
    D_80100A78_CraneGame[1] = D_80100AA0_CraneGame[1] = CRot.y;
    D_80100A78_CraneGame[2] = D_80100AA0_CraneGame[2] = CRot.z;
    D_80100A6C_CraneGame[0] = D_80100A94_CraneGame[0] = Center.x;
    D_80100A6C_CraneGame[1] = D_80100A94_CraneGame[1] = Center.y;
    D_80100A6C_CraneGame[2] = D_80100A94_CraneGame[2] = Center.z;
    D_80100A84_CraneGame = D_80100AAC_CraneGame = CZoom;
    guTranslateF(m, Center.x, Center.y, Center.z);
    MtxRotate(m, CRot.x, CRot.y, CRot.z);
    func_800FDBF8_CraneGame(m, 0.0f, 0.0f, CZoom, &v);
    D_80100A88_CraneGame[0] = D_80100AB0_CraneGame[0] = v.x;
    D_80100A88_CraneGame[1] = D_80100AB0_CraneGame[1] = v.y;
    D_80100A88_CraneGame[2] = D_80100AB0_CraneGame[2] = v.z;
    D_80100A62_CraneGame = D_80100A64_CraneGame = 0;
}

void func_800FE7A0_CraneGame(void) {
    D_80100A5C_CraneGame = 0;
}

void func_800FE7AC_CraneGame(s16 mode) {
    D_80100A5E_CraneGame = mode;
}

void func_800FE7B8_CraneGame(s16 delay, s16 len) {
    func_800FE7AC_CraneGame(3);
    D_80100A62_CraneGame = D_80100A64_CraneGame = 0;
    D_80100A66_CraneGame = delay;
    D_80100A68_CraneGame = len;
}

void func_800FE80C_CraneGame(f32 x, f32 y, f32 z, f32 w) {
    if (D_80100A60_CraneGame < 16) {
        D_80100AC0_CraneGame[D_80100A60_CraneGame][0] = x;
        D_80100AC0_CraneGame[D_80100A60_CraneGame][1] = y;
        D_80100AC0_CraneGame[D_80100A60_CraneGame][2] = z;
        D_80100AC0_CraneGame[D_80100A60_CraneGame][3] = w;
        D_80100A60_CraneGame++;
    }
}

/* Mode 3: after a delay, swings the camera along quadratic Bezier curves to its default framing. */
// retail stores the curve end points through split labels and reloads them; register allocation (masked 38)
#ifdef NON_MATCHING
void func_800FE874_CraneGame(void) {
    Vec d;
    Vec eye;
    Vec at;
    f32 t;
    f64 u;
    f32 a;
    f32 b;
    f32 c;

    D_80100A60_CraneGame = 0;
    if (++D_80100A62_CraneGame < D_80100A66_CraneGame) {
        t = 0.0f;
    } else {
        t = (f32)(D_80100A62_CraneGame - D_80100A66_CraneGame) / (f32)D_80100A68_CraneGame;
    }
    if (D_80100A62_CraneGame >= D_80100A66_CraneGame + D_80100A68_CraneGame) {
        func_800FE7AC_CraneGame(0);
    }
    u = 1.0 - t;
    a = u * u;
    b = 2.0 * (u * t);
    c = t * t;
    D_800FF8E0_CraneGame[2].x = D_80100A94_CraneGame[0];
    D_800FF8E0_CraneGame[2].y = D_80100A94_CraneGame[1];
    D_800FF8E0_CraneGame[2].z = D_80100A94_CraneGame[2];
    at.x = a * D_800FF8E0_CraneGame[0].x + b * D_800FF8E0_CraneGame[1].x + c * D_800FF8E0_CraneGame[2].x;
    at.y = a * D_800FF8E0_CraneGame[0].y + b * D_800FF8E0_CraneGame[1].y + c * D_800FF8E0_CraneGame[2].y;
    at.z = a * D_800FF8E0_CraneGame[0].z + b * D_800FF8E0_CraneGame[1].z + c * D_800FF8E0_CraneGame[2].z;
    D_800FF904_CraneGame[2].x = D_80100AB0_CraneGame[0];
    D_800FF904_CraneGame[2].y = D_80100AB0_CraneGame[1];
    D_800FF904_CraneGame[2].z = D_80100AB0_CraneGame[2];
    eye.x = a * D_800FF904_CraneGame[0].x + b * D_800FF904_CraneGame[1].x + c * D_800FF904_CraneGame[2].x;
    eye.y = a * D_800FF904_CraneGame[0].y + b * D_800FF904_CraneGame[1].y + c * D_800FF904_CraneGame[2].y;
    eye.z = a * D_800FF904_CraneGame[0].z + b * D_800FF904_CraneGame[1].z + c * D_800FF904_CraneGame[2].z;
    CZoom = a * D_800FF928_CraneGame[0] + b * D_800FF928_CraneGame[1] + c * D_80100AAC_CraneGame;
    d.x = eye.x - at.x;
    d.y = eye.y - at.y;
    d.z = eye.z - at.z;
    func_800FE598_CraneGame(&d, (Vec*)&CRot);
    Center.x = at.x;
    Center.y = at.y;
    Center.z = at.z;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CraneGame/1BAA60", func_800FE874_CraneGame);
#endif

/* Modes: 0 hold the default framing, 1 follow the claw and the prize, 2 frame every queued point,
   3 the opening swing (func_800FE874). The result eases into Center, CRot and CZoom. */
// register allocation, stack layout and constant placement (masked 167)
#ifdef NON_MATCHING
void func_800FEB08_CraneGame(void) {
    f32 hi[3];
    f32 lo[3];
    f32 at[3];
    f32 eye[3];
    Matrix4f m;
    Vec z0;
    Vec v;
    Vec rot;
    s16 pts[16][3];
    f32 far;
    f32 rate;
    f32 d;
    f64 t;
    s32 i;
    s32 j;
    s32 k;
    s32 a;
    s32 b;

    if (D_80100A5C_CraneGame != 0 && D_80100A60_CraneGame != 0 && D_80100A5E_CraneGame >= 0) {
        if (D_80100A5E_CraneGame == 3) {
            func_800FE874_CraneGame();
        }
        if (D_80100A5E_CraneGame != 0) {
            for (i = 0; i < 3; i++) {
                hi[i] = -2000.0f;
                lo[i] = 2000.0f;
            }
            for (i = 0; i < D_80100A60_CraneGame; i++) {
                for (j = 0; j < 3; j++) {
                    if (hi[j] < D_80100AC0_CraneGame[i][j]) {
                        hi[j] = D_80100AC0_CraneGame[i][j];
                    }
                    if (D_80100AC0_CraneGame[i][j] < lo[j]) {
                        lo[j] = D_80100AC0_CraneGame[i][j];
                    }
                }
            }
            for (i = 0; i < 3; i++) {
                at[i] = lo[i] + (hi[i] - lo[i]) * 0.5;
            }
            k = 0;
            if (D_80100A5E_CraneGame == 1) {
                for (i = 0; i < D_80100A60_CraneGame; i++, k++) {
                    pts[k][0] = D_80100AC0_CraneGame[i][0];
                    pts[k][2] = D_80100AC0_CraneGame[i][2];
                }
                if (pts[0][2] >= pts[1][2]) {
                    a = 1;
                    b = 0;
                } else {
                    a = 0;
                    b = 1;
                }
                v.x = pts[a][0] - pts[b][0];
                v.z = pts[a][2] - pts[b][2];
                d = sqrtf(v.x * v.x + v.z * v.z);
                eye[0] = at[0] + 400.0;
                eye[2] = at[2] + -400.0;
                eye[1] = at[1] - 100.0;
                if (eye[1] < 100.0) {
                    eye[1] = 100.0f;
                }
                if (d < 400.0) {
                    d = d / 400.0;
                } else {
                    d = 1.0f;
                }
                eye[0] = d * eye[0] + D_80100A88_CraneGame[0] * (1.0 - d);
                eye[1] = d * eye[1] + D_80100A88_CraneGame[1] * (1.0 - d);
                eye[2] = d * eye[2] + D_80100A88_CraneGame[2] * (1.0 - d);
            } else {
                for (i = 0; i < D_80100A60_CraneGame; i++, k++) {
                    pts[k][0] = D_80100AC0_CraneGame[i][0];
                    pts[k][2] = D_80100AC0_CraneGame[i][2];
                }
                eye[0] = at[0] + 400.0;
                eye[2] = at[2] + -400.0;
                eye[1] = at[1] - 100.0;
            }
            HuGuLookAtF(m, eye[0], eye[1], eye[2], at[0], at[1], at[2], 0.0f, 1.0f, 0.0f);
            z0.z = z0.y = z0.x = 0.0f;
            far = 0.0f;
            t = (f32)(func_800AEAC0(D_800C3110->unk_40 * 0.5) / func_800AEFD0(D_800C3110->unk_40 * 0.5));
            for (i = 0; i < D_80100A60_CraneGame; i++) {
                func_800FDBF8_CraneGame(m, D_80100AC0_CraneGame[i][0] - at[0], D_80100AC0_CraneGame[i][1] - at[1],
                                        D_80100AC0_CraneGame[i][2] - at[2], &v);
                d = v.x;
                if (d < 0.0f) {
                    d = -d;
                }
                hi[0] = d / t + v.z;
                d = v.y;
                if (d < 0.0f) {
                    d = -d;
                }
                hi[1] = d / t + v.z;
                hi[2] = (hi[1] <= hi[0]) ? hi[0] : hi[1];
                if (far < hi[2]) {
                    far = hi[2];
                }
            }
            far *= 1.1111111111111112;
            if (far > 3000.0) {
                far = 3000.0f;
            } else if (far < 400.0) {
                far = 400.0f;
            }
            if (far > 3000.0f) {
                far = 3000.0f;
            }
            rate = 0.1f;
        } else {
            at[0] = D_80100A94_CraneGame[0];
            at[1] = D_80100A94_CraneGame[1];
            at[2] = D_80100A94_CraneGame[2];
            eye[0] = D_80100AB0_CraneGame[0];
            eye[1] = D_80100AB0_CraneGame[1];
            eye[2] = D_80100AB0_CraneGame[2];
            far = D_80100AAC_CraneGame;
            rate = 0.05f;
        }
        v.x = eye[0] - at[0];
        v.y = eye[1] - at[1];
        v.z = eye[2] - at[2];
        func_800FE598_CraneGame(&v, &rot);
        if (func_800AEAC0(-rot.x) * far + at[1] < 100.0) {
            d = at[1] - 100.0;
            rot.x = func_800B0CD8(d, sqrtf(far * far - d * d));
        }
        for (i = 0; i < 3; i++) {
            d = (at[i] - D_80100A6C_CraneGame[i]) * rate + D_80100A6C_CraneGame[i];
            D_80100A6C_CraneGame[i] = d;
            (&Center.x)[i] = d;
        }
        for (i = 0; i < 3; i++) {
            d = (&rot.x)[i] - D_80100A78_CraneGame[i];
            if (d >= 180.0) {
                d -= 360.0;
            } else if (d < -180.0) {
                d += 360.0;
            }
            d = d * rate + D_80100A78_CraneGame[i];
            if (d >= 360.0) {
                d -= 360.0;
            } else if (d < 0.0) {
                d += 360.0;
            }
            D_80100A78_CraneGame[i] = d;
            (&CRot.x)[i] = d;
        }
        CZoom = D_80100A84_CraneGame = (far - D_80100A84_CraneGame) * rate + D_80100A84_CraneGame;
    }
    D_80100A60_CraneGame = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CraneGame/1BAA60", func_800FEB08_CraneGame);
#endif
