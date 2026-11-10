#include "common.h"

extern s16 D_800F3778;
extern omObjData* D_800FB1C8_BumperBallMaze;

typedef struct BumperBallMazeCameraWork {
    u16 frames;
    u16 pad_02;
    f32 zoomStep;
    Vec3f rotStep;
    Vec3f centerStep;
} BumperBallMazeCameraWork;

void func_800F9890_BumperBallMaze(omObjData*);
void func_800FA010_BumperBallMaze(void);
s32 func_80024198(u32, Gfx*, s32);
s32 func_8009B850(const void*, const void*);
void func_800295FC(Vtx*, Vtx*, Vtx*, Vec3f*);
f64 func_8009B618(f64, f64); /* fmod */

extern u8 D_800F37DA;
extern u8 D_800F37F0;
extern unk2C0C0Struct70* D_800F37AC;

typedef struct BumperBallMazeAnglePair {
    f32 first;
    f32 second;
} BumperBallMazeAnglePair;

/* Wave phases of the water mesh (bss): 7 rows of 30 floats, each row 7 (first, second) pairs for
   its near edge, a spare float, 7 pairs for its far edge and another spare. Retail indexes the near
   pairs from D_800FAE20 and the far ones as floats from D_800FAE5C (= D_800FAE20 + 0x3C), which on
   the host is a view (BumperBallMaze.h). */
extern BumperBallMazeAnglePair D_800FAE20_BumperBallMaze[];
#include "BumperBallMaze.h"
extern f32 D_800FAE5C_BumperBallMaze[];
#define BBM_FAR(row) ((BumperBallMazeAnglePair*) &D_800FAE5C_BumperBallMaze[(row) * 30])
extern unk2C0C0Struct70* D_800FB168_BumperBallMaze; /* the water texture */
extern Gfx* D_800FB170_BumperBallMaze[8];           /* per-screen display lists */
extern Vtx* D_800FB190_BumperBallMaze[8];           /* per-screen water vertices (7 x 30) */
extern s32 D_800FB1B0_BumperBallMaze;
/* Water texture scroll (.data): the s/t of the near columns and rows, the far ones (+1024), and
   the per-frame steps. */
extern f32 D_800FACC4_BumperBallMaze;
extern f32 D_800FACC8_BumperBallMaze;
extern f32 D_800FACCC_BumperBallMaze;
extern f32 D_800FACD0_BumperBallMaze;
extern f32 D_800FACD4_BumperBallMaze;
extern f32 D_800FACD8_BumperBallMaze;

void func_800F96B0_BumperBallMaze(f32 cameraValue, f32 zoom, f32 rotX, f32 rotY, f32 rotZ,
                                 f32 centerX, f32 centerY, f32 centerZ) {
    func_800178A0(1);
    func_800178E8();
    CZoom = zoom;
    CRot.x = rotX;
    CRot.y = rotY;
    CRot.z = rotZ;
    Center.x = centerX;
    Center.y = centerY;
    Center.z = centerZ;
    D_800C3110->unk_40 = cameraValue;
}

void func_800F9768_BumperBallMaze(void) {
    D_800FB1C8_BumperBallMaze = omAddObj(0x3C, 0, 0, -1, NULL);
    D_800FB1C8_BumperBallMaze->unk_50 = func_80023684(0x20, 0x7918);
}

void func_800F97B4_BumperBallMaze(u16 frames, f32 zoom, f32 rotX, f32 rotY, f32 rotZ,
                                 f32 centerX, f32 centerY, f32 centerZ) {
    BumperBallMazeCameraWork* work = D_800FB1C8_BumperBallMaze->unk_50;
    f32 duration;

    work->frames = frames;
    work->zoomStep = (zoom - CZoom) / (duration = (u16) frames);
    work->rotStep.x = (rotX - CRot.x) / duration;
    work->rotStep.y = (rotY - CRot.y) / duration;
    work->rotStep.z = (rotZ - CRot.z) / duration;
    work->centerStep.x = (centerX - Center.x) / duration;
    work->centerStep.y = (centerY - Center.y) / duration;
    work->centerStep.z = (centerZ - Center.z) / duration;
    D_800FB1C8_BumperBallMaze->func_ptr = func_800F9890_BumperBallMaze;
}

void func_800F9890_BumperBallMaze(omObjData* object) {
    BumperBallMazeCameraWork* work = object->unk_50;

    CZoom += work->zoomStep;
    CRot.x += work->rotStep.x;
    CRot.y += work->rotStep.y;
    CRot.z += work->rotStep.z;
    Center.x += work->centerStep.x;
    Center.y += work->centerStep.y;
    Center.z += work->centerStep.z;
    if (--work->frames == 0) {
        object->func_ptr = NULL;
    }
}

void func_800F993C_BumperBallMaze(void) {
    s32 i;

    for (i = 0; i < D_800F3778; i++) {
    }
}

void func_800F9974_BumperBallMaze(s32 arg0) {
    omOvlReturnEx(1);
}

// Logic-equivalent water mesh and buffer setup; loop scheduling and register allocation differ.
#ifdef NON_MATCHING
void func_800F9990_BumperBallMaze(void) {
    BumperBallMazeAnglePair* left;
    BumperBallMazeAnglePair* right;
    unk2C0C0Struct70* texture;
    Vtx* source;
    Vtx* dst;
    Vtx* src;
    Vtx* v;
    f32 angle;
    f32 rowAngle;
    f32 second;
    f32 rightFirst;
    f32 rightSecond;
    s32 x0;
    s32 x1;
    s32 z0;
    s32 z1;
    s32 row;
    s32 column;
    u16 textureId;
    u16 screen;
    u16 i;

    for (screen = 0; screen < D_800F37DA; screen++) {
        D_800FB190_BumperBallMaze[screen] = func_80023684(210 * sizeof(Vtx), 0x7918);
        D_800FB170_BumperBallMaze[screen] = func_80023684(0x800 * sizeof(Gfx), 0x7918);
    }
    rowAngle = 0.0f;
    angle = 0.0f;
    for (row = 0; row < 7; row++) {
        left = &D_800FAE20_BumperBallMaze[row * 15];
        right = BBM_FAR(row);
        for (column = 0; column < 7; column++) {
            second = angle + 90.0f;
            if (second >= 360.0f) {
                second -= 360.0f;
            }
            rightFirst = angle + 90.0f;
            if (rightFirst >= 360.0f) {
                rightFirst -= 360.0f;
            }
            rightSecond = angle + 180.0f;
            if (rightSecond >= 360.0f) {
                rightSecond -= 360.0f;
            }
            left[column].first = angle;
            left[column].second = second;
            right[column].first = rightFirst;
            angle += 90.0f;
            right[column].second = rightSecond;
            if (angle >= 360.0f) {
                angle -= 360.0f;
            }
        }
        rowAngle += 90.0f;
        if (rowAngle >= 360.0f) {
            rowAngle -= 360.0f;
        }
        angle = rowAngle;
    }
    source = D_800FB190_BumperBallMaze[D_800F37F0];
    for (row = 0; row < 7; row++) {
        left = &D_800FAE20_BumperBallMaze[row * 15];
        for (column = 0; column < 7; column++) {
            v = &source[column * 2 + row * 30];
            x0 = column * 650.0f - 1950.0f + -360.0f;
            v->n.ob[0] = x0;
            v->n.ob[1] = func_800AEAC0(left[column].first) * 40.0f + -100.0f;
            z0 = row * 615.0f - 1845.0f + -550.0f;
            v->n.ob[2] = z0;
            v->n.n[0] = 0;
            v->n.n[1] = -0x80;
            v->n.n[2] = 0;
            v->n.tc[0] = 0x400;
            v->n.tc[1] = 0;
            v->n.a = 0x90;
            v = &source[column * 2 + (row * 30 + 1)];
            x1 = (column + 1) * 650.0f - 1950.0f + -360.0f;
            v->n.ob[0] = x1;
            v->n.ob[1] = func_800AEAC0(left[column].second) * 40.0f + -100.0f;
            v->n.ob[2] = z0;
            v->n.n[0] = 0;
            v->n.n[1] = -0x80;
            v->n.n[2] = 0;
            v->n.tc[0] = 0;
            v->n.tc[1] = 0;
            v->n.a = 0x90;
            v = &source[column * 2 + (row * 2 + 1) * 15];
            v->n.ob[0] = x0;
            v->n.ob[1] = func_800AEAC0(BBM_FAR(row)[column].first) * 40.0f + -100.0f;
            z1 = (row + 1) * 615.0f - 1845.0f + -550.0f;
            v->n.ob[2] = z1;
            v->n.n[0] = 0;
            v->n.n[1] = -0x80;
            v->n.n[2] = 0;
            v->n.tc[0] = 0x400;
            v->n.tc[1] = 0x400;
            v->n.a = 0x90;
            v = &source[column * 2 + ((row * 2 + 1) * 15 + 1)];
            v->n.ob[0] = x1;
            v->n.ob[1] = func_800AEAC0(BBM_FAR(row)[column].second) * 40.0f + -100.0f;
            v->n.ob[2] = z1;
            v->n.n[0] = 0;
            v->n.n[1] = -0x80;
            v->n.n[2] = 0;
            v->n.tc[0] = 0;
            v->n.tc[1] = 0x400;
            v->n.a = 0x90;
        }
    }
    for (screen = 0; screen < D_800F37DA; screen++) {
        if (screen != D_800F37F0) {
            src = source;
            dst = D_800FB190_BumperBallMaze[screen];
            for (i = 0; i < 210; i++) {
                *dst++ = *src++;
            }
        }
    }
    textureId = func_8001CD00((u8*) "47mt003_DEF");
    for (i = 0; i < 0x80; i++) {
        texture = &D_800F37AC[i];
        if (texture->unk_20 == textureId && func_8009B850(texture, "47mt003_DEF") == 0) {
            break;
        }
    }
    D_800FB168_BumperBallMaze = &D_800F37AC[i];
    func_800FA010_BumperBallMaze();
    D_800FB1B0_BumperBallMaze = func_80024198(0x681, D_800FB170_BumperBallMaze[D_800F37F0], 4);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/240010", func_800F9990_BumperBallMaze);
#endif

void func_800FA010_BumperBallMaze(void) {
    Gfx* gfx;
    s32 screen;
    s32 row;
    s32 column;

    for (screen = 0; screen < D_800F37DA; screen++) {
        gfx = D_800FB170_BumperBallMaze[screen];
        gDPPipeSync(gfx++);
        gSPSetOtherMode(gfx++, G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, 0x504A50);
        gSPClearGeometryMode(gfx++, G_LIGHTING);
        gDPSetTextureFilter(gfx++, G_TF_BILERP);
        gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
        gDPSetPrimColor(gfx++, 0, 0, 0xB2, 0xB2, 0xB2, 0xA0);
        gDPSetCombineLERP(gfx++, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE,
            TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE);
        gDPSetTextureLUT(gfx++, G_TT_RGBA16);
        gDPLoadTLUT_pal16(gfx++, 0, D_800FB168_BumperBallMaze->unk_2C->unk_24);
        gDPLoadTextureBlock_4b(gfx++, D_800FB168_BumperBallMaze->unk_24,
            D_800FB168_BumperBallMaze->unk_18,
            D_800FB168_BumperBallMaze->unk_1A, D_800FB168_BumperBallMaze->unk_1B, 0,
            G_TX_WRAP, G_TX_WRAP, INTEGER_LOG2(D_800FB168_BumperBallMaze->unk_1A),
            INTEGER_LOG2(D_800FB168_BumperBallMaze->unk_1B), G_TX_NOLOD, G_TX_NOLOD);
        for (row = 0; row < 7; row++) {
            gSPVertex(gfx++, D_800FB190_BumperBallMaze[screen] + (row * 30), 30, 0);
            for (column = 0; column < 7; column++) {
                gSP2Triangles(gfx++, column * 2, column * 2 + 1, column * 2 + 15, 0,
                    column * 2 + 1, column * 2 + 16, column * 2 + 15, 0);
            }
        }
        gDPPipeSync(gfx++);
        gSPEndDisplayList(gfx++);
    }
}

// Logic-equivalent animated water update; addressing and register allocation differ (masked 34).
#ifdef NON_MATCHING
void func_800FA620_BumperBallMaze(void) {
    BumperBallMazeAnglePair* p;
    Vtx* vertices;
    Vtx* v0;
    Vtx* v1;
    Vtx* v2;
    Vtx* v3;
    Vec3f normal;
    f32 angle;
    s32 row;
    s32 column;
    s32 k;

    *D_800F2B7C[D_800FB1B0_BumperBallMaze].unk_6C->unk_00 = D_800FB170_BumperBallMaze[D_800F37F0];
    vertices = D_800FB190_BumperBallMaze[D_800F37F0];
    for (row = 0; row < 7; row++) {
        for (column = 0; column < 7; column++) {
            p = &D_800FAE20_BumperBallMaze[row * 15 + column];
            angle = p->first + 4.0f;
            p->first = angle;
            if (angle >= 360.0f) {
                p->first = angle - 360.0f;
            }
            v0 = &vertices[column * 2 + row * 30];
            v0->n.ob[1] = func_800AEAC0(p->first) * 40.0f + -100.0f;
            v0->n.tc[0] = D_800FACC4_BumperBallMaze;
            v0->n.tc[1] = D_800FACC8_BumperBallMaze;
            angle = p->second + 4.0f;
            p->second = angle;
            if (angle >= 360.0f) {
                p->second = angle - 360.0f;
            }
            v1 = v0 + 1;
            v1->n.ob[1] = func_800AEAC0(p->second) * 40.0f + -100.0f;
            v1->n.tc[0] = D_800FACCC_BumperBallMaze;
            v1->n.tc[1] = D_800FACC8_BumperBallMaze;
            p = &BBM_FAR(row)[column];
            angle = p->first + 4.0f;
            p->first = angle;
            if (angle >= 360.0f) {
                p->first = angle - 360.0f;
            }
            v2 = &vertices[column * 2 + (row * 2 + 1) * 15];
            v2->n.ob[1] = func_800AEAC0(p->first) * 40.0f + -100.0f;
            v2->n.tc[0] = D_800FACC4_BumperBallMaze;
            v2->n.tc[1] = D_800FACD0_BumperBallMaze;
            angle = p->second + 4.0f;
            p->second = angle;
            if (angle >= 360.0f) {
                p->second = angle - 360.0f;
            }
            v3 = v2 + 1;
            v3->n.ob[1] = func_800AEAC0(p->second) * 40.0f + -100.0f;
            v3->n.tc[0] = D_800FACCC_BumperBallMaze;
            v3->n.tc[1] = D_800FACD0_BumperBallMaze;
            func_800295FC(v0, v1, v2, &normal);
            for (k = 0; k < 3; k++) {
                v0->n.n[k] = ((f32*) &normal)[k] * 127.0f;
                v1->n.n[k] = ((f32*) &normal)[k] * 127.0f;
                v2->n.n[k] = ((f32*) &normal)[k] * 127.0f;
                v3->n.n[k] = ((f32*) &normal)[k] * 127.0f;
            }
        }
    }
    D_800FACC4_BumperBallMaze += D_800FACD4_BumperBallMaze;
    D_800FACC8_BumperBallMaze += D_800FACD8_BumperBallMaze;
    D_800FACC4_BumperBallMaze = func_8009B618(D_800FACC4_BumperBallMaze, 1024.0);
    D_800FACC8_BumperBallMaze = func_8009B618(D_800FACC8_BumperBallMaze, 1024.0);
    D_800FACCC_BumperBallMaze = D_800FACC4_BumperBallMaze + 1024.0f;
    D_800FACD0_BumperBallMaze = D_800FACC8_BumperBallMaze + 1024.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_BumperBallMaze/240010", func_800FA620_BumperBallMaze);
#endif
