#include "UnusedMinigame0.h"

/* .data (0x80102C00..0x80102D14) */

/* The five exits of the board's edge: positions / 10 and the mask bit testing each
   (bits 0, 1: compare x; bits 2, 3: compare z). */
UM0Vec2 D_80102C00_UnusedMinigame0[5] = {
    { 30.0f, -30.0f }, { 40.0f, 0.0f }, { 10.0f, 30.0f }, { -30.0f, 30.0f }, { -40.0f, 0.0f },
};
s16 D_80102C28_UnusedMinigame0[6] = { 4, 2, 8, 8, 1, 0 };
/* Pairs of cells ({x, z}, {x, z}) that must both be free, and the position each one stands for. */
s16 D_80102C34_UnusedMinigame0[4][4] = {
    { 0, 5, 1, 5 },
    { 7, 2, 7, 3 },
    { 4, 5, 5, 5 },
    { 0, 2, 0, 3 },
};
UM0Vec2 D_80102C54_UnusedMinigame0[4] = {
    { -30.0f, 30.0f }, { 40.0f, 0.0f }, { 10.0f, 30.0f }, { -40.0f, 0.0f },
};
/* The corners of the movable pieces' outlines (x, z) * 2, per piece slot. */
UM0Vec2 D_80102C74_UnusedMinigame0[5][4] = {
    { { 0.0f, 0.0f }, { 0.0f, 0.0f }, { 0.0f, 0.0f }, { 0.0f, 0.0f } },
    { { -4.0f, 0.0f }, { -4.0f, -27.0f }, { 4.0f, -27.0f }, { 4.0f, 0.0f } },
    { { 0.0f, -4.0f }, { 27.0f, -3.0f }, { 27.0f, 2.0f }, { 0.0f, 4.0f } },
    { { 0.0f, 0.0f }, { 0.0f, 0.0f }, { 0.0f, 0.0f }, { 0.0f, 0.0f } },
    { { 4.0f, 0.0f }, { 4.0f, 27.0f }, { -4.0f, 27.0f }, { -4.0f, 0.0f } },
};

void func_800FADF0_UnusedMinigame0(omObjData* obj) {
    obj->func_ptr = func_800FB3B4_UnusedMinigame0;
    CZoom = 300.0f;
    CRot.x = -10.0f;
    CRot.y = 180.0f;
    CRot.z = 0.0f;
    Center.x = 300.0f;
    Center.y = 80.0f;
    Center.z = -400.0f;
    D_80104330_UnusedMinigame0 = 0;
    D_80104334_UnusedMinigame0 = -1;
    D_80104332_UnusedMinigame0 = 0;
}

void func_800FAE84_UnusedMinigame0(f32 zoom, f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz) {
    CZoom = zoom;
    Center.x = cx;
    Center.y = cy;
    Center.z = cz;
    CRot.x = rx;
    CRot.y = ry;
    CRot.z = rz;
}

/* Adds a camera key (the first one also records the current view); angles are taken the short
   way round from the previous key. */
// NON_MATCHING: retail stores the first key through each field label (lui at per store); GCC keeps the base in a register
#ifdef NON_MATCHING
void func_800FAEC4_UnusedMinigame0(f32 zoom, f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz, u16 frames) {
    if (D_80104330_UnusedMinigame0 == 0) {
        D_80104310_UnusedMinigame0[0] = CZoom;
        D_80104250_UnusedMinigame0[0][0] = Center.x;
        D_80104250_UnusedMinigame0[0][1] = Center.y;
        D_80104250_UnusedMinigame0[0][2] = Center.z;
        D_801042B0_UnusedMinigame0[0][0] = CRot.x;
        D_801042B0_UnusedMinigame0[0][1] = CRot.y;
        D_801042B0_UnusedMinigame0[0][2] = CRot.z;
        D_80104330_UnusedMinigame0++;
    }
    D_80104310_UnusedMinigame0[D_80104330_UnusedMinigame0] = zoom;
    D_80104250_UnusedMinigame0[D_80104330_UnusedMinigame0][0] = cx;
    D_80104250_UnusedMinigame0[D_80104330_UnusedMinigame0][1] = cy;
    D_80104250_UnusedMinigame0[D_80104330_UnusedMinigame0][2] = cz;
    rx = func_8009B618(rx, 360.0);
    ry = func_8009B618(ry, 360.0);
    rz = func_8009B618(rz, 360.0);
    if (rx - D_801042B0_UnusedMinigame0[D_80104330_UnusedMinigame0 - 1][0] > 180.0) {
        rx = -(360.0 - rx);
    }
    if (ry - D_801042B0_UnusedMinigame0[D_80104330_UnusedMinigame0 - 1][1] > 180.0) {
        ry = -(360.0 - ry);
    }
    if (rz - D_801042B0_UnusedMinigame0[D_80104330_UnusedMinigame0 - 1][2] > 180.0) {
        rz = -(360.0 - rz);
    }
    D_801042B0_UnusedMinigame0[D_80104330_UnusedMinigame0][0] = rx;
    D_801042B0_UnusedMinigame0[D_80104330_UnusedMinigame0][1] = ry;
    D_801042B0_UnusedMinigame0[D_80104330_UnusedMinigame0][2] = rz;
    if (D_80104334_UnusedMinigame0 < 0) {
        D_80104334_UnusedMinigame0 = frames;
    }
    D_80104330_UnusedMinigame0++;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_UnusedMinigame0/103D80", func_800FAEC4_UnusedMinigame0);
#endif

/* The camera at t on the quadratic Bezier through keys i, i + 1, i + 2. */
void func_800FB190_UnusedMinigame0(s32 i, f32 t) {
    f32 a = (1.0 - t) * (1.0 - t);
    f32 b = 2.0 * (1.0 - t) * t;
    f32 c = t * t;

    CZoom = a * D_80104310_UnusedMinigame0[i] + b * D_80104310_UnusedMinigame0[i + 1] + c * D_80104310_UnusedMinigame0[i + 2];
    CRot.x = a * D_801042B0_UnusedMinigame0[i][0] + b * D_801042B0_UnusedMinigame0[i + 1][0] + c * D_801042B0_UnusedMinigame0[i + 2][0];
    CRot.y = a * D_801042B0_UnusedMinigame0[i][1] + b * D_801042B0_UnusedMinigame0[i + 1][1] + c * D_801042B0_UnusedMinigame0[i + 2][1];
    CRot.z = a * D_801042B0_UnusedMinigame0[i][2] + b * D_801042B0_UnusedMinigame0[i + 1][2] + c * D_801042B0_UnusedMinigame0[i + 2][2];
    Center.x = a * D_80104250_UnusedMinigame0[i][0] + b * D_80104250_UnusedMinigame0[i + 1][0] + c * D_80104250_UnusedMinigame0[i + 2][0];
    Center.y = a * D_80104250_UnusedMinigame0[i][1] + b * D_80104250_UnusedMinigame0[i + 1][1] + c * D_80104250_UnusedMinigame0[i + 2][1];
    Center.z = a * D_80104250_UnusedMinigame0[i][2] + b * D_80104250_UnusedMinigame0[i + 1][2] + c * D_80104250_UnusedMinigame0[i + 2][2];
}

/* The camera object: plays the keys (padded to three with the last one). */
// NON_MATCHING: register allocation (masked 0)
#ifdef NON_MATCHING
void func_800FB3B4_UnusedMinigame0(omObjData* obj) {
    s16 i;

    if (D_80104330_UnusedMinigame0 != 0) {
        for (i = D_80104330_UnusedMinigame0; i < 3; i++) {
            D_80104310_UnusedMinigame0[i] = D_80104310_UnusedMinigame0[D_80104330_UnusedMinigame0 - 1];
            D_801042B0_UnusedMinigame0[i][0] = D_801042B0_UnusedMinigame0[D_80104330_UnusedMinigame0 - 1][0];
            D_801042B0_UnusedMinigame0[i][1] = D_801042B0_UnusedMinigame0[D_80104330_UnusedMinigame0 - 1][1];
            D_801042B0_UnusedMinigame0[i][2] = D_801042B0_UnusedMinigame0[D_80104330_UnusedMinigame0 - 1][2];
            D_80104250_UnusedMinigame0[i][0] = D_80104250_UnusedMinigame0[D_80104330_UnusedMinigame0 - 1][0];
            D_80104250_UnusedMinigame0[i][1] = D_80104250_UnusedMinigame0[D_80104330_UnusedMinigame0 - 1][1];
            D_80104250_UnusedMinigame0[i][2] = D_80104250_UnusedMinigame0[D_80104330_UnusedMinigame0 - 1][2];
        }
        func_800FB190_UnusedMinigame0(0, (f32)D_80104332_UnusedMinigame0 / (f32)D_80104334_UnusedMinigame0);
        if (++D_80104332_UnusedMinigame0 > D_80104334_UnusedMinigame0) {
            D_80104330_UnusedMinigame0 = 0;
            D_80104332_UnusedMinigame0 = 0;
            D_80104334_UnusedMinigame0 = -1;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_UnusedMinigame0/103D80", func_800FB3B4_UnusedMinigame0);
#endif

UM0Work* func_800FB568_UnusedMinigame0(omObjData* obj) {
    UM0Work* w = HuMemDirectMalloc(sizeof(UM0Work));

    D_801098C0_UnusedMinigame0[D_80108B80_UnusedMinigame0++] = w;
    obj->work[0] = (u32)w >> 24;
    obj->work[1] = (u32)w >> 16;
    obj->work[2] = (u32)w >> 8;
    obj->work[3] = (u32)w;
    w->unk0 = 0;
    w->unk2 = 0;
    w->unk8 = 0;
    w->obj = obj;
    w->unk10 = w->unk14 = w->unk18 = 0.0f;
    w->unk1C = w->unk20 = w->unk24 = 0.0f;
    w->unk28 = w->unk2C = w->unk30 = 0.0f;
    w->unk40 = w->unk42 = w->unk44 = w->unk46 = 0;
    w->unk48 = w->unk4A = w->unk4C = w->unk4E = 0;
    w->unk50 = w->unk52 = w->unk54 = w->unk56 = 0;
    w->unk58 = w->unk5A = w->unk5C = w->unk5E = 0;
    return w;
}

void func_800FB650_UnusedMinigame0(void) {
    s16 i;

    for (i = 0; i < D_80108B80_UnusedMinigame0; i++) {
        if (D_801098C0_UnusedMinigame0[i] != NULL) {
            HuMemDirectFree(D_801098C0_UnusedMinigame0[i]);
        }
    }
}

UM0Work* func_800FB6D0_UnusedMinigame0(omObjData* obj) {
    return (UM0Work*)((obj->work[0] << 24) | (obj->work[1] << 16) | (obj->work[2] << 8) | obj->work[3]);
}

/* A 16-bit random number. */
u32 func_800FB6FC_UnusedMinigame0(void) {
    u8 hi = rand8();

    return (hi << 8) | rand8();
}

/* Keeps the object on the board; returns which edges it touched (1 -x, 2 +x, 4 -z, 8 +z). */
s32 func_800FB734_UnusedMinigame0(omObjData* obj) {
    s32 hit = 0;

    if (obj->trans.x < -350.0) {
        obj->trans.x = -350.0f;
        hit = 1;
    }
    if (obj->trans.x > 350.0) {
        obj->trans.x = 350.0f;
        hit |= 2;
    }
    if (obj->trans.z < -250.0) {
        obj->trans.z = -250.0f;
        hit |= 4;
    }
    if (obj->trans.z > 250.0) {
        obj->trans.z = 250.0f;
        hit |= 8;
    }
    return (u8)hit;
}

/* The exit at (x, z) among those whose bit is in mask, or -1. */
s16 func_800FB810_UnusedMinigame0(f32 x, f32 z, s32 mask) {
    s16 i;

    for (i = 0; i < 5; i++) {
        if ((u8)mask & D_80102C28_UnusedMinigame0[i]) {
            if (!(D_80102C28_UnusedMinigame0[i] & 3)) {
                if (fabs(D_80102C00_UnusedMinigame0[i].x * 10.0 - x) < 25.0) {
                    return i;
                }
            } else if (fabs(D_80102C00_UnusedMinigame0[i].z * 10.0 - z) < 25.0) {
                return i;
            }
        }
    }
    return -1;
}

/* Picks a random spot whose two cells are free; returns its index, or -1 (x, z = 0). */
// NON_MATCHING: retail addresses board[] from cand[]'s base (one stack base register); register allocation
#ifdef NON_MATCHING
s16 func_800FB904_UnusedMinigame0(s16* x, s16* z) {
    s16 cand[4];
    u8 board[8][6];
    s16 n = 0;
    s16 i;
    s16 pick;

    func_801025B8_UnusedMinigame0(board);
    for (i = 0; i < 4; i++) {
        u8* a = &board[D_80102C34_UnusedMinigame0[i][0]][D_80102C34_UnusedMinigame0[i][1]];
        u8* b = &board[D_80102C34_UnusedMinigame0[i][2]][D_80102C34_UnusedMinigame0[i][3]];

        if ((*a == 0) & (*b == 0)) {
            cand[n++] = i;
        }
    }
    if (n != 0) {
        pick = 0;
        if (cand[0] != 0) {
            pick = cand[(func_800FB6FC_UnusedMinigame0() * n) >> 16];
        }
        *x = D_80102C54_UnusedMinigame0[pick].x * 10.0;
        *z = D_80102C54_UnusedMinigame0[pick].z * 10.0;
        return pick;
    }
    *x = 0;
    *z = 0;
    return -1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_UnusedMinigame0/103D80", func_800FB904_UnusedMinigame0);
#endif

/* Whether board cell (x, z) is empty (0 off the board). */
// NON_MATCHING: register allocation, retail keeps raw x and a sign-extended z live (masked 4, raw 11); tried early-return/ret-local shapes, a flag local; s32 params break the prototype
#ifdef NON_MATCHING
s32 func_800FBAA0_UnusedMinigame0(s16 x, s16 z) {
    if (((u16)x >= 8) | (z < 0)) {
        return 0;
    }
    if (z < 6) {
        return D_80108B88_UnusedMinigame0[x][z] == NULL;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_UnusedMinigame0/103D80", func_800FBAA0_UnusedMinigame0);
#endif

/* Builds the collision outline of the occupied cells around (x, z): each cell's square, with the
   edges that face an empty neighbour. */
// NON_MATCHING: retail reloads the outline pointer after the first store and folds the bounds test differently
#ifdef NON_MATCHING
void func_800FBB18_UnusedMinigame0(f32 x, f32 z) {
    s16 cx;
    s16 cz;
    s16 x0;
    s16 x1;
    s16 z0;
    s16 z1;
    s16 i;
    s16 j;
    s8 n;
    s16 px;
    s16 pz;

    n = 0;
    D_80104248_UnusedMinigame0 = D_80103E28_UnusedMinigame0;
    D_8010424C_UnusedMinigame0 = D_80104128_UnusedMinigame0;
    D_80103E20_UnusedMinigame0 = 0;
    D_80103E22_UnusedMinigame0 = 0;
    cx = x / 10.0f + 4.0f;
    cz = z / 10.0f + 3.0f;
    if (((u16)cx >= 8) | (cz < 0)) {
        return;
    }
    if (cz < 6) {
        x0 = cx - 1;
        if (x0 < 0) {
            x0 = 0;
        }
        z0 = cz - 1;
        if (z0 < 0) {
            z0 = 0;
        }
        x1 = cx + 1;
        if (x1 >= 8) {
            x1 = 7;
        }
        z1 = cz + 1;
        if (z1 >= 6) {
            z1 = 5;
        }
        for (j = z0; j <= z1; j++) {
            for (i = x0; i <= x1; i++) {
                pz = (j - 3) * 10;
                if (D_80108B88_UnusedMinigame0[i][j] != NULL) {
                    D_80104248_UnusedMinigame0->x = px = (i - 4) * 10;
                    D_80104248_UnusedMinigame0->z = pz;
                    D_80104248_UnusedMinigame0++;
                    D_80104248_UnusedMinigame0->x = px + 10;
                    D_80104248_UnusedMinigame0->z = pz;
                    D_80104248_UnusedMinigame0++;
                    D_80104248_UnusedMinigame0->x = px + 10;
                    D_80104248_UnusedMinigame0->z = pz + 10;
                    D_80104248_UnusedMinigame0++;
                    D_80104248_UnusedMinigame0->x = px;
                    D_80104248_UnusedMinigame0->z = pz + 10;
                    D_80104248_UnusedMinigame0++;
                    if (func_800FBAA0_UnusedMinigame0(i, j - 1)) {
                        *D_8010424C_UnusedMinigame0++ = n;
                        *D_8010424C_UnusedMinigame0++ = n + 1;
                        *D_8010424C_UnusedMinigame0++ = 0xFF;
                        D_80103E22_UnusedMinigame0 += 3;
                    }
                    if (func_800FBAA0_UnusedMinigame0(i + 1, j)) {
                        *D_8010424C_UnusedMinigame0++ = n + 1;
                        *D_8010424C_UnusedMinigame0++ = n + 2;
                        *D_8010424C_UnusedMinigame0++ = 0xFF;
                        D_80103E22_UnusedMinigame0 += 3;
                    }
                    if (func_800FBAA0_UnusedMinigame0(i, j + 1)) {
                        *D_8010424C_UnusedMinigame0++ = n + 2;
                        *D_8010424C_UnusedMinigame0++ = n + 3;
                        *D_8010424C_UnusedMinigame0++ = 0xFF;
                        D_80103E22_UnusedMinigame0 += 3;
                    }
                    if (func_800FBAA0_UnusedMinigame0(i - 1, j)) {
                        *D_8010424C_UnusedMinigame0++ = n + 3;
                        *D_8010424C_UnusedMinigame0++ = n;
                        *D_8010424C_UnusedMinigame0++ = 0xFF;
                        D_80103E22_UnusedMinigame0 += 3;
                    }
                    n += 4;
                }
            }
        }
        D_80103E20_UnusedMinigame0 = n;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_UnusedMinigame0/103D80", func_800FBB18_UnusedMinigame0);
#endif

/* Builds the outlines of the movable pieces (D_801098B4 slots 1, 2, 4) from their model nodes. */
// NON_MATCHING: retail reloads the outline pointers once more; table label addressing
#ifdef NON_MATCHING
void func_800FBFE4_UnusedMinigame0(omObjData* obj) {
    Matrix4f m;
    Matrix4f c;
    unk2C0C0Struct50* node;
    s16 i;
    s16 j;

    D_80104248_UnusedMinigame0 = D_80103E28_UnusedMinigame0;
    D_8010424C_UnusedMinigame0 = D_80104128_UnusedMinigame0;
    D_80103E20_UnusedMinigame0 = 0;
    D_80103E22_UnusedMinigame0 = 0;
    for (i = 0; i < 5; i++) {
        if (((i == 0) | (i == 3)) == 0 && D_801098B4_UnusedMinigame0[i] != 0) {
            node = D_800F2B7C[obj->model[i + 1]].unk_6C->unk_A0;
            guTranslateF(m, node->unk_08.x / 10.0, node->unk_08.y / 10.0, node->unk_08.z / 10.0);
            MtxRotate(m, 0.0f, node->unk_44.y, 0.0f);
            for (j = 0; j < 4; j++) {
                guTranslateF(c, D_80102C74_UnusedMinigame0[i][j].x / 2.0, 0.0f, D_80102C74_UnusedMinigame0[i][j].z / 2.0);
                guMtxCatF(c, m, c);
                D_80104248_UnusedMinigame0->x = c[3][0];
                D_80104248_UnusedMinigame0->z = c[3][2];
                D_80104248_UnusedMinigame0++;
                *D_8010424C_UnusedMinigame0++ = D_80103E20_UnusedMinigame0++;
            }
            *D_8010424C_UnusedMinigame0++ = 0xFF;
            D_80103E22_UnusedMinigame0 += 5;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_UnusedMinigame0/103D80", func_800FBFE4_UnusedMinigame0);
#endif

/* Moves (x, z) dist away from the edge list pts[n], along the sum of the edges' outward normals. */
void func_800FC29C_UnusedMinigame0(f32* x, f32* z, f32 dist, UM0Vec2* pts, s16 n) {
    f32 mx;
    f32 mz;
    f32 sx;
    f32 sz;
    f32 px;
    f32 pz;
    f32 nx;
    f32 nz;
    f32 dx;
    f32 len;
    s16 i;

    if (n >= 2) {
        mz = 0.0f;
        mx = 0.0f;
        for (i = 0; i < n; i++) {
            mx += pts[i].x;
            mz += pts[i].z;
        }
        mx /= n;
        mz /= n;
        px = pts[0].x;
        pz = pts[0].z;
        sz = 0.0f;
        sx = 0.0f;
        for (i = 0; i < n - 1; i++) {
            nx = pts[i + 1].z - pz;
            dx = pts[i + 1].x - px;
            nz = -dx;
            if (nx * (*x - mx) + nz * (*z - mz) < 0.0) {
                nx = -nx;
                nz = dx;
            }
            len = sqrtf(nx * nx + nz * nz);
            if (len != 0.0) {
                nx /= len;
                nz /= len;
                sx += nx;
                sz += nz;
            }
            px = pts[i + 1].x;
            pz = pts[i + 1].z;
        }
        len = sqrtf(sx * sx + sz * sz);
        if (len != 0.0) {
            sx /= len;
            sz /= len;
            *x = mx + sx * dist;
            *z = mz + sz * dist;
        }
    }
}

/* Pushes (x, z) out of the outline where a circle of radius crosses its edges; returns the number
   of crossings. */
// NON_MATCHING: retail computes -qb twice (neg.s/add.s) and converts t0 to double twice
#ifdef NON_MATCHING
s16 func_800FC564_UnusedMinigame0(f32* x, f32* z, f32 radius) {
    UM0Vec2 hits[256];
    s16 n = 0;
    s16 total = 0;
    s8 a = D_80104128_UnusedMinigame0[0];
    s8 b;
    s16 k = 1;
    f32 ex;
    f32 ez;
    f32 ox;
    f32 oz;
    f32 qa;
    f32 qb;
    f32 disc;
    f32 t0;
    f32 t1;

    while (k < D_80103E22_UnusedMinigame0) {
        b = D_80104128_UnusedMinigame0[k++];
        if ((a >= 0) & (b >= 0)) {
            ex = D_80103E28_UnusedMinigame0[b].x - D_80103E28_UnusedMinigame0[a].x;
            ez = D_80103E28_UnusedMinigame0[b].z - D_80103E28_UnusedMinigame0[a].z;
            ox = D_80103E28_UnusedMinigame0[a].x - *x;
            oz = D_80103E28_UnusedMinigame0[a].z - *z;
            qa = ex * ex + ez * ez;
            qb = 2.0f * (ex * ox + ez * oz);
            disc = qb * qb - 4.0 * qa * (ox * ox + oz * oz - radius * radius);
            if (disc > 0.0f) {
                disc = sqrtf(disc);
                t0 = (-qb - disc) / (2.0f * qa);
                t1 = (-qb + disc) / (2.0f * qa);
                if (t0 >= 0.0 && t0 <= 1.0) {
                    hits[n].x = D_80103E28_UnusedMinigame0[a].x + t0 * ex;
                    hits[n].z = D_80103E28_UnusedMinigame0[a].z + t0 * ez;
                    n++;
                    total++;
                }
                if (t1 >= 0.0 && t1 <= 1.0) {
                    hits[n].x = D_80103E28_UnusedMinigame0[a].x + t1 * ex;
                    hits[n].z = D_80103E28_UnusedMinigame0[a].z + t1 * ez;
                    n++;
                    total++;
                }
            }
            if (n >= 2) {
                func_800FC29C_UnusedMinigame0(x, z, radius, hits, n);
                n -= 2;
            }
        }
        a = b;
    }
    return total;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_UnusedMinigame0/103D80", func_800FC564_UnusedMinigame0);
#endif

/* The height of the board cell under (x, z): a raised block (state >= 8) gives 0..10. */
f32 func_800FC944_UnusedMinigame0(f32 x, f32 z) {
    f32 h = 0.0f;
    s16 cx = x / 10.0f + 4.0f;
    s16 cz = z / 10.0f + 3.0f;
    UM0Cell* cell;
    UM0CellState* s;

    if (!(((u16)cx >= 8) | (cz < 0)) && cz < 6) {
        cell = D_80108B88_UnusedMinigame0[cx][cz];
        if (cell != NULL) {
            s = cell->state;
            if (s->unk8 >= 8) {
                h = s->unk10 / 8.0 * 10.0;
                if (h > 10.0) {
                    h = 10.0f;
                }
            }
        }
    }
    return h;
}

/* Pushes obj off the first object of D_80108C4C on flat ground within radius + 40, sliding along
   it against the direction (dx, dz); returns that object's index, or -1. */
// NON_MATCHING: retail keeps the double constants 10.0/0.5 in integer registers (lw pairs); branch layout
#ifdef NON_MATCHING
s16 func_800FCA40_UnusedMinigame0(omObjData* obj, f32 dx, f32 dz, f32 radius) {
    s16 i;
    omObjData* o;
    f32 nx;
    f32 nz;
    f32 tx = 0.0f;
    f32 tz = 0.0f;
    f32 d;
    f32 push;

    for (i = 0; i < D_8010B450_UnusedMinigame0; i++) {
        o = D_80108C4C_UnusedMinigame0[i];
        if ((s8)o->work[0] >= 0 && func_800FC944_UnusedMinigame0(o->trans.x / 10.0, o->trans.z / 10.0) == 0.0) {
            nx = o->trans.x - obj->trans.x;
            nz = o->trans.z - obj->trans.z;
            d = sqrtf(nx * nx + nz * nz);
            if (d < radius + 40.0f) {
                if (d != 0.0) {
                    nx /= d;
                    nz /= d;
                }
                push = radius + 40.0f - d;
                if (nx != 0.0 && nz != 0.0) {
                    tx = nz;
                    tz = -nx;
                    if (tx * dx + tz * dz < 0.0f) {
                        tx = -tx;
                        tz = nx;
                    }
                } else {
                    if (nx == 0.0) {
                        tx = 0.0f;
                        tz = -nz;
                    }
                    if (nz == 0.0) {
                        tz = 0.0f;
                        tx = -nx;
                    }
                }
                obj->trans.x = obj->trans.x - nx * push + tx * push * 0.5;
                obj->trans.z = obj->trans.z - nz * push + tz * push * 0.5;
                return i;
            }
        }
    }
    return -1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_UnusedMinigame0/103D80", func_800FCA40_UnusedMinigame0);
/* its two doubles (10.0, 0.5), read as word pairs by the asm */
const u32 D_80103B48_UnusedMinigame0 __attribute__((section(".rodata"))) = 0x40240000;
const u32 D_80103B4C_UnusedMinigame0 __attribute__((section(".rodata"))) = 0;
const u32 D_80103B50_UnusedMinigame0 __attribute__((section(".rodata"))) = 0x3FE00000;
const u32 D_80103B54_UnusedMinigame0 __attribute__((section(".rodata"))) = 0;
#endif

/* Points camera 0 at Center from CRot / CZoom. */
// NON_MATCHING: scheduling of the Center address load (masked 4, raw 8); a Vec* local for Center is worse
#ifdef NON_MATCHING
void func_800FCD68_UnusedMinigame0(void) {
    Vec eye;
    Vec at;
    Vec up;
    f32 rx = CRot.x;
    f32 ry = CRot.y;

    eye.x = func_800AEAC0(ry) * func_800AEFD0(rx) * CZoom + Center.x;
    eye.y = -func_800AEAC0(rx) * CZoom + Center.y;
    eye.z = func_800AEFD0(ry) * func_800AEFD0(rx) * CZoom + Center.z;
    at.x = Center.x;
    at.y = Center.y;
    at.z = Center.z;
    up.x = func_800AEAC0(ry) * func_800AEAC0(rx);
    up.y = func_800AEFD0(rx);
    up.z = func_800AEFD0(ry) * func_800AEAC0(rx);
    D_800EE73C.x = eye.x;
    D_800EE73C.z = eye.z;
    ((f32*)&D_800EE73C)[-1] = CRot.y;
    D_800EE73C.fov = D_800C3110->unk_40;
    D_800EE73C.far = 20000.0f;
    D_800EE73C.near = 10000.0f;
    func_8001D420(0, (Vec3f*)&eye, (Vec3f*)&at, (Vec3f*)&up);
    func_8001D57C(0);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_UnusedMinigame0/103D80", func_800FCD68_UnusedMinigame0);
#endif
