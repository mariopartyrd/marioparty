#include "common.h"
#include "105EA0.h"

/* .data (0x80102D20..0x80103780) */

Vtx D_80102D20_UnusedMinigame0[24] = {
    { { { -14, -20, 20 }, 0, { 0, 0 }, { 0xD0, 0x00, 0x75, 0xFF } } },
    { { { -14, 20, 20 }, 0, { 0, 0 }, { 0xD0, 0x00, 0x75, 0xFF } } },
    { { { -20, 20, 14 }, 0, { 0, 0 }, { 0x8B, 0x00, 0x30, 0xFF } } },
    { { { -20, -20, 14 }, 0, { 0, 0 }, { 0x8B, 0x00, 0x30, 0xFF } } },
    { { { -20, -20, -14 }, 0, { 0, 0 }, { 0x8B, 0x00, 0xD0, 0xFF } } },
    { { { -20, 20, -14 }, 0, { 0, 0 }, { 0x8B, 0x00, 0xD0, 0xFF } } },
    { { { 14, -20, 20 }, 0, { 0, 0 }, { 0x30, 0x00, 0x75, 0xFF } } },
    { { { 14, 20, 20 }, 0, { 0, 0 }, { 0x30, 0x00, 0x75, 0xFF } } },
    { { { 20, -20, 14 }, 0, { 0, 0 }, { 0x75, 0x00, 0x30, 0xFF } } },
    { { { 20, 20, 14 }, 0, { 0, 0 }, { 0x75, 0x00, 0x30, 0xFF } } },
    { { { -20, 20, -14 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { -20, 20, 14 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { 14, 20, -20 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { 20, -20, -14 }, 0, { 0, 0 }, { 0x75, 0x00, 0xD0, 0xFF } } },
    { { { 20, 20, -14 }, 0, { 0, 0 }, { 0x75, 0x00, 0xD0, 0xFF } } },
    { { { -14, 20, 20 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { 14, 20, 20 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { 20, 20, 14 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { -14, 20, -20 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { 20, 20, -14 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { 14, -20, -20 }, 0, { 0, 0 }, { 0x30, 0x00, 0x8B, 0xFF } } },
    { { { 14, 20, -20 }, 0, { 0, 0 }, { 0x30, 0x00, 0x8B, 0xFF } } },
    { { { -14, 20, -20 }, 0, { 0, 0 }, { 0xD0, 0x00, 0x8B, 0xFF } } },
    { { { -14, -20, -20 }, 0, { 0, 0 }, { 0xD0, 0x00, 0x8B, 0xFF } } },
};

Gfx D_80102EA0_UnusedMinigame0[] = {
    gsSPVertex(0x0F000000, 24, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 3, 2, 0, 4, 2, 5, 0),
    gsSP2Triangles(0, 6, 7, 0, 0, 7, 1, 0),
    gsSP2Triangles(8, 9, 7, 0, 8, 7, 6, 0),
    gsSP1Triangle(10, 11, 12, 0),
    gsSP2Triangles(8, 13, 14, 0, 8, 14, 9, 0),
    gsSP1Triangle(11, 15, 12, 0),
    gsSP1Triangle(12, 16, 17, 0),
    gsSP1Triangle(12, 18, 10, 0),
    gsSP1Triangle(17, 19, 12, 0),
    gsSP1Triangle(12, 15, 16, 0),
    gsSP2Triangles(20, 21, 14, 0, 20, 14, 13, 0),
    gsSP2Triangles(22, 23, 4, 0, 22, 4, 5, 0),
    gsSP2Triangles(20, 23, 22, 0, 20, 22, 21, 0),
    gsSPEndDisplayList(),
};

Gfx D_80102F20_UnusedMinigame0[] = {
    gsSPDisplayList(D_80102EA0_UnusedMinigame0),
    gsSPEndDisplayList(),
};

Vtx D_80102F30_UnusedMinigame0[20] = {
    { { { 14, 20, -20 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { 14, 20, 20 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { 20, 20, 14 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { -20, 20, 20 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { 20, -20, 14 }, 0, { 0, 0 }, { 0x75, 0x00, 0x30, 0xFF } } },
    { { { 20, 20, 14 }, 0, { 0, 0 }, { 0x75, 0x00, 0x30, 0xFF } } },
    { { { 14, 20, 20 }, 0, { 0, 0 }, { 0x30, 0x00, 0x75, 0xFF } } },
    { { { 14, -20, 20 }, 0, { 0, 0 }, { 0x30, 0x00, 0x75, 0xFF } } },
    { { { 20, 20, -14 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { -20, 20, 14 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { -20, 20, -14 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { 20, -20, -14 }, 0, { 0, 0 }, { 0x75, 0x00, 0xD0, 0xFF } } },
    { { { 20, 20, -14 }, 0, { 0, 0 }, { 0x75, 0x00, 0xD0, 0xFF } } },
    { { { -20, 20, -20 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { 14, -20, -20 }, 0, { 0, 0 }, { 0x30, 0x00, 0x8B, 0xFF } } },
    { { { 14, 20, -20 }, 0, { 0, 0 }, { 0x30, 0x00, 0x8B, 0xFF } } },
    { { { -20, -20, 20 }, 0, { 0, 0 }, { 0x00, 0x00, 0x7F, 0xFF } } },
    { { { -20, 20, 20 }, 0, { 0, 0 }, { 0x00, 0x00, 0x7F, 0xFF } } },
    { { { -20, -20, -20 }, 0, { 0, 0 }, { 0x00, 0x00, 0x81, 0xFF } } },
    { { { -20, 20, -20 }, 0, { 0, 0 }, { 0x00, 0x00, 0x81, 0xFF } } },
};

Gfx D_80103070_UnusedMinigame0[] = {
    gsSPVertex(0x0F000000, 20, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP1Triangle(2, 8, 0, 0),
    gsSP2Triangles(9, 3, 0, 0, 10, 9, 0, 0),
    gsSP2Triangles(4, 11, 12, 0, 4, 12, 5, 0),
    gsSP1Triangle(0, 13, 10, 0),
    gsSP2Triangles(14, 15, 12, 0, 14, 12, 11, 0),
    gsSP2Triangles(16, 7, 6, 0, 16, 6, 17, 0),
    gsSP2Triangles(14, 18, 19, 0, 14, 19, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_801030C8_UnusedMinigame0[] = {
    gsSPDisplayList(D_80103070_UnusedMinigame0),
    gsSPEndDisplayList(),
};

Vtx D_801030D8_UnusedMinigame0[16] = {
    { { { 14, 20, -20 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { 14, 20, 20 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { 20, 20, 20 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { -20, 20, 20 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { -20, 20, 14 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { -20, 20, -14 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { 20, 20, -14 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { -20, 20, -20 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { 14, -20, -20 }, 0, { 0, 0 }, { 0x30, 0x00, 0x8B, 0xFF } } },
    { { { 14, 20, -20 }, 0, { 0, 0 }, { 0x30, 0x00, 0x8B, 0xFF } } },
    { { { 20, 20, -14 }, 0, { 0, 0 }, { 0x75, 0x00, 0xD0, 0xFF } } },
    { { { 20, -20, -14 }, 0, { 0, 0 }, { 0x75, 0x00, 0xD0, 0xFF } } },
    { { { -20, -20, -20 }, 0, { 0, 0 }, { 0x00, 0x00, 0x81, 0xFF } } },
    { { { -20, 20, -20 }, 0, { 0, 0 }, { 0x00, 0x00, 0x81, 0xFF } } },
    { { { 20, -20, 20 }, 0, { 0, 0 }, { 0x7F, 0x00, 0x00, 0xFF } } },
    { { { 20, 20, 20 }, 0, { 0, 0 }, { 0x7F, 0x00, 0x00, 0xFF } } },
};

Gfx D_801031D8_UnusedMinigame0[] = {
    gsSPVertex(0x0F000000, 16, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 3, 0, 0, 5, 4, 0, 0),
    gsSP1Triangle(2, 6, 0, 0),
    gsSP1Triangle(0, 7, 5, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(8, 12, 13, 0, 8, 13, 9, 0),
    gsSP2Triangles(14, 11, 10, 0, 14, 10, 15, 0),
    gsSPEndDisplayList(),
};

Gfx D_80103220_UnusedMinigame0[] = {
    gsSPDisplayList(D_801031D8_UnusedMinigame0),
    gsSPEndDisplayList(),
};

Vtx D_80103230_UnusedMinigame0[14] = {
    { { { -20, 20, 14 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { -20, 20, 20 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { 20, 20, -20 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { -20, 20, -14 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { -20, 20, -20 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { 20, 20, 20 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { -20, -20, 20 }, 0, { 0, 0 }, { 0x00, 0x00, 0x7F, 0xFF } } },
    { { { 20, -20, 20 }, 0, { 0, 0 }, { 0x00, 0x00, 0x7F, 0xFF } } },
    { { { 20, 20, 20 }, 0, { 0, 0 }, { 0x00, 0x00, 0x7F, 0xFF } } },
    { { { -20, 20, 20 }, 0, { 0, 0 }, { 0x00, 0x00, 0x7F, 0xFF } } },
    { { { 20, -20, -20 }, 0, { 0, 0 }, { 0x00, 0x00, 0x81, 0xFF } } },
    { { { -20, -20, -20 }, 0, { 0, 0 }, { 0x00, 0x00, 0x81, 0xFF } } },
    { { { -20, 20, -20 }, 0, { 0, 0 }, { 0x00, 0x00, 0x81, 0xFF } } },
    { { { 20, 20, -20 }, 0, { 0, 0 }, { 0x00, 0x00, 0x81, 0xFF } } },
};

Gfx D_80103310_UnusedMinigame0[] = {
    gsSPVertex(0x0F000000, 14, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(3, 0, 2, 0),
    gsSP1Triangle(2, 4, 3, 0),
    gsSP1Triangle(2, 1, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
    gsSP2Triangles(10, 11, 12, 0, 10, 12, 13, 0),
    gsSPEndDisplayList(),
};

Gfx D_80103350_UnusedMinigame0[] = {
    gsSPDisplayList(D_80103310_UnusedMinigame0),
    gsSPEndDisplayList(),
};

Vtx D_80103360_UnusedMinigame0[10] = {
    { { { -20, 20, -14 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { -20, 20, 14 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { 20, 20, -20 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { -20, 20, -20 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { -20, 20, 20 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { 20, 20, 20 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { 20, -20, -20 }, 0, { 0, 0 }, { 0x00, 0x00, 0x81, 0xFF } } },
    { { { -20, -20, -20 }, 0, { 0, 0 }, { 0x00, 0x00, 0x81, 0xFF } } },
    { { { -20, 20, -20 }, 0, { 0, 0 }, { 0x00, 0x00, 0x81, 0xFF } } },
    { { { 20, 20, -20 }, 0, { 0, 0 }, { 0x00, 0x00, 0x81, 0xFF } } },
};

Gfx D_80103400_UnusedMinigame0[] = {
    gsSPVertex(0x0F000000, 10, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
    gsSP2Triangles(1, 4, 2, 0, 2, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
    gsSPEndDisplayList(),
};

Gfx D_80103428_UnusedMinigame0[] = {
    gsSPDisplayList(D_80103400_UnusedMinigame0),
    gsSPEndDisplayList(),
};

Vtx D_80103438_UnusedMinigame0[4] = {
    { { { -20, 20, 20 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { 20, 20, -20 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { 20, 20, 20 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
    { { { -20, 20, -20 }, 0, { 0, 0 }, { 0x00, 0x7F, 0x00, 0xFF } } },
};

Gfx D_80103478_UnusedMinigame0[] = {
    gsSPVertex(0x0F000000, 4, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 1, 3, 0),
    gsSPEndDisplayList(),
};

Gfx D_80103498_UnusedMinigame0[] = {
    gsSPDisplayList(D_80103478_UnusedMinigame0),
    gsSPEndDisplayList(),
};

Vtx D_801034A8_UnusedMinigame0[17] = {
    { { { 0, 1, -20 }, 0, { 0, 0 }, { 0x00, 0x40, 0x00, 0xFF } } },
    { { { -14, 1, -20 }, 0, { 0, 0 }, { 0x00, 0x40, 0x00, 0xFF } } },
    { { { -17, 1, -17 }, 0, { 0, 0 }, { 0x00, 0x40, 0x00, 0xFF } } },
    { { { -20, 1, -14 }, 0, { 0, 0 }, { 0x00, 0x40, 0x00, 0xFF } } },
    { { { -20, 1, 0 }, 0, { 0, 0 }, { 0x00, 0x40, 0x00, 0xFF } } },
    { { { -20, 1, 14 }, 0, { 0, 0 }, { 0x00, 0x40, 0x00, 0xFF } } },
    { { { -17, 1, 17 }, 0, { 0, 0 }, { 0x00, 0x40, 0x00, 0xFF } } },
    { { { -14, 1, 20 }, 0, { 0, 0 }, { 0x00, 0x40, 0x00, 0xFF } } },
    { { { 0, 1, 20 }, 0, { 0, 0 }, { 0x00, 0x40, 0x00, 0xFF } } },
    { { { 14, 1, 20 }, 0, { 0, 0 }, { 0x00, 0x40, 0x00, 0xFF } } },
    { { { 17, 1, 17 }, 0, { 0, 0 }, { 0x00, 0x40, 0x00, 0xFF } } },
    { { { 20, 1, 14 }, 0, { 0, 0 }, { 0x00, 0x40, 0x00, 0xFF } } },
    { { { 20, 1, 0 }, 0, { 0, 0 }, { 0x00, 0x40, 0x00, 0xFF } } },
    { { { 20, 1, -14 }, 0, { 0, 0 }, { 0x00, 0x40, 0x00, 0xFF } } },
    { { { 17, 1, -17 }, 0, { 0, 0 }, { 0x00, 0x40, 0x00, 0xFF } } },
    { { { 14, 1, -20 }, 0, { 0, 0 }, { 0x00, 0x40, 0x00, 0xFF } } },
    { { { 0, 5, 0 }, 0, { 0, 0 }, { 0x00, 0x40, 0x00, 0xFF } } },
};

Gfx D_801035B8_UnusedMinigame0[] = {
    gsSPVertex(0x0F000000, 17, 0),
    gsSP2Triangles(0, 1, 16, 0, 1, 2, 16, 0),
    gsSP2Triangles(2, 3, 16, 0, 3, 4, 16, 0),
    gsSP2Triangles(4, 5, 16, 0, 5, 6, 16, 0),
    gsSP2Triangles(6, 7, 16, 0, 7, 8, 16, 0),
    gsSP2Triangles(8, 9, 16, 0, 9, 10, 16, 0),
    gsSP2Triangles(10, 11, 16, 0, 11, 12, 16, 0),
    gsSP2Triangles(12, 13, 16, 0, 13, 14, 16, 0),
    gsSP2Triangles(14, 15, 16, 0, 15, 0, 16, 0),
    gsSPEndDisplayList(),
};

/* (shape, rot) per same-colour neighbour mask; entries 7..15 are splat's D_80103640. */
UM0ShapeRot D_80103608_UnusedMinigame0[16] = {
    { 0, 0 },
    { 1, 0 },
    { 1, 1 },
    { 2, 0 },
    { 1, 2 },
    { 3, 0 },
    { 2, 1 },
    { 4, 0 },
    { 1, 3 },
    { 2, 3 },
    { 3, 1 },
    { 4, 3 },
    { 2, 2 },
    { 4, 2 },
    { 4, 1 },
    { 5, 0 },
};

s32 D_80103688_UnusedMinigame0[6] = { 24, 20, 16, 14, 10, 4 };

/* random seeds; D_80103640[3..5] in the original indexing */
u32 D_801036A0_UnusedMinigame0[3][8] = {
    { 0x41C64E6D, 0x45651696, 0xAF63BE8C, 0x3008C321, 0x0DE13587, 0xDAEB6AAC, 0x4CD63358, 0x7F9DFF74 },
    { 0xBE50FA40, 0x2E70BBC0, 0x5DA877A1, 0xF1F3C5CD, 0x81F204CD, 0xC8482322, 0x7542D60B, 0x30FAC1EE },
    { 0x9CB973E6, 0x021D0B74, 0x8C093124, 0xB7EADCAA, 0x8F213E84, 0x18A2628A, 0xEE21BB86, 0xDF297FA7 },
};

s32 D_80103700_UnusedMinigame0 = 0;
s32 D_80103704_UnusedMinigame0 = 0;
u32 D_80103708_UnusedMinigame0 = 0x41C64E6D;
s16 D_8010370C_UnusedMinigame0[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
s16 D_8010371C_UnusedMinigame0[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
UM0LinkBit D_8010372C_UnusedMinigame0[4] = { { 0, 1 }, { 0, 4 }, { 0, 8 }, { 0, 2 } };
s16 D_80103734_UnusedMinigame0 = 0;
s32 D_80103738_UnusedMinigame0 = 1;
s32 D_8010373C_UnusedMinigame0 = 0;
s16 D_80103740_UnusedMinigame0 = 0;
/* unreferenced halfwords up to D_80103748 */
s16 D_80103742_UnusedMinigame0 = 0;
s16 D_80103744_UnusedMinigame0 = 0;
s16 D_80103746_UnusedMinigame0 = 0;
s32 D_80103748_UnusedMinigame0 = 0;
s32 D_8010374C_UnusedMinigame0 = 0;
s32 D_80103750_UnusedMinigame0 = -1;
f32 D_80103754_UnusedMinigame0 = 1.6f;
s16 D_80103758_UnusedMinigame0[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
/* the last two rows are zero padding up to the unit's .rodata */
s16 D_80103768_UnusedMinigame0[6][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }, { 0, 0 }, { 0, 0 } };


void func_800FCF10_UnusedMinigame0(s16 arg0) {
    D_80103700_UnusedMinigame0 = 0;
    func_800FD5E0_UnusedMinigame0();
    func_800FCFB4_UnusedMinigame0(arg0);
    func_800FF488_UnusedMinigame0();
    func_800FE360_UnusedMinigame0();
    func_801025B8_UnusedMinigame0(D_80108B50_UnusedMinigame0);
    func_800258EC(UM0_MODEL(0), 4, 4);
    func_800258EC(UM0_MODEL(1), 4, 4);
    func_800258EC(UM0_MODEL(2), 4, 4);
    func_800258EC(UM0_MODEL_DROP, 4, 4);
}
// register allocation: retail recomputes &D_8010A040[i] where GCC reuses it
#ifdef NON_MATCHING
void func_800FCFB4_UnusedMinigame0(s32 arg0) {
    UM0Tile* t;
    UM0Tile* p;
    UM0Tile** slot;
    s32 k;
    s32 col;
    s32 row;
    s32 i;
    s32 j;
    void* buf;

    col = 0;
    row = 0;
    D_80103708_UnusedMinigame0 = UM0_SEED_ROW(arg0)[rand8() & 7];
    for (j = 0; j < 6; j++) {
        for (i = 0; i < 8; i++) {
            D_80108B88_UnusedMinigame0[i][j] = NULL;
        }
    }
    D_80108B88_UnusedMinigame0[0][5] = &D_8010A040_UnusedMinigame0[47];
    for (i = 0; i < 48; i++) {
        t = &D_8010A040_UnusedMinigame0[i];
        if (i < 40) {
            p = D_8010A040_UnusedMinigame0 + i;
            do {
                col = func_80102568_UnusedMinigame0(8);
                row = func_80102568_UnusedMinigame0(6);
                slot = &D_80108B88_UnusedMinigame0[col][row];
            } while (*slot != NULL);
            *slot = p;
        } else if (i == 47) {
            col = 0;
            row = 5;
        } else {
            p = &D_8010A040_UnusedMinigame0[i];
            for (j = 0; j < 6; j++) {
                for (k = 0; k < 8; k++) {
                    if (D_80108B88_UnusedMinigame0[k][j] == NULL) {
                        col = k;
                        row = j;
                        D_80108B88_UnusedMinigame0[k][j] = p;
                        j = 8;
                        k = 8;
                    }
                }
            }
        }
        t->col = col;
        t->row = row;
        t->x = col * 40.0 + -140.0;
        t->z = row * 40.0 + -100.0;
        t->color = func_80102568_UnusedMinigame0(arg0);
        t->fade = 0;
        t->links = 0;
        t->rot = 0;
        t->shape = 0;
        t->flags = 1;
        t->visited = 0;
        t->state = 0;
        t->dx = t->dy = 0.0f;
        t->moveTimer = 0;
        t->match = NULL;
    }
    for (j = 0; j < 6; j++) {
        for (i = 0; i < 8; i++) {
            t = &D_8010A040_UnusedMinigame0[i + j * 8];
            func_800FDA50_UnusedMinigame0(t, 0);
            if (t->shape == 0) {
                t->fade = 0x70;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        buf = HuMemDirectMalloc(960 * sizeof(Gfx));
        D_801098A8_UnusedMinigame0[i] = buf;
        D_80109CC0_UnusedMinigame0[i] = func_80024198(0x19, buf, 4);
    }
    func_800FEBF0_UnusedMinigame0(0);
    func_80025830(UM0_MODEL(0), 2.5f, 2.5f, 2.5f);
    func_80025830(UM0_MODEL(1), 2.5f, 2.5f, 2.5f);
    func_80025830(UM0_MODEL(2), 2.5f, 2.5f, 2.5f);
    buf = DataRead(0x180007);
    D_80109CD0_UnusedMinigame0 = func_800678A4(buf);
    HuMemDirectFree(buf);
    D_80109CD4_UnusedMinigame0 = func_80064EF4(0x20, 0);
    for (i = 0; i < 32; i++) {
        func_80067208(UM0_SPRGRP, i, UM0_SPRITE, 0);
        func_800674BC(UM0_SPRGRP, i, 0x9000);
        func_800672B0(UM0_SPRGRP, i, 2);
        func_80067284(UM0_SPRGRP, i, 1.0f);
        D_8010AD60_UnusedMinigame0[i].active = 0;
        (D_8010AD60_UnusedMinigame0 + i)->timer = 0;
        D_8010AD60_UnusedMinigame0[i].unk_08 = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_UnusedMinigame0/105EA0", func_800FCFB4_UnusedMinigame0);
#endif

void func_800FD430_UnusedMinigame0(void) {
    s32 i;
    s32 k;
    s32 f;
    s32 j;

    for (i = 0; i < 3; i++) {
        HuMemDirectFree(D_801098A8_UnusedMinigame0[i]);
    }
    for (i = 0; i < 6; i++) {
        for (j = 1; j < 3; j++) {
            for (k = 0; k < 4; k++) {
                for (f = 0; f < 3; f++) {
                    HuMemDirectFree(D_80109CD8_UnusedMinigame0[i][j][k][f]);
                }
            }
        }
    }
    for (i = 0; i < 3; i++) {
        HuMemDirectFree(D_80108C50_UnusedMinigame0[i]);
        for (j = 0; j < 4; j++) {
            HuMemDirectFree(D_8010B070_UnusedMinigame0[j][i]);
            HuMemDirectFree(D_8010B0D0_UnusedMinigame0[j][i]);
            HuMemDirectFree(D_8010B0D0_UnusedMinigame0[j + 4][i]);
        }
    }
}
void func_800FD5E0_UnusedMinigame0(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 f;
    s32 n;

    D_8010AD00_UnusedMinigame0[0] = D_80102F20_UnusedMinigame0;
    D_8010AD00_UnusedMinigame0[1] = D_801030C8_UnusedMinigame0;
    D_8010AD00_UnusedMinigame0[2] = D_80103220_UnusedMinigame0;
    D_8010AD00_UnusedMinigame0[3] = D_80103350_UnusedMinigame0;
    D_8010AD00_UnusedMinigame0[4] = D_80103428_UnusedMinigame0;
    D_8010AD00_UnusedMinigame0[5] = D_80103498_UnusedMinigame0;
    D_80109CD8_UnusedMinigame0[0][0][0][0] = D_80102D20_UnusedMinigame0;
    D_80109CD8_UnusedMinigame0[1][0][0][0] = D_80102F30_UnusedMinigame0;
    D_80109CD8_UnusedMinigame0[2][0][0][0] = D_801030D8_UnusedMinigame0;
    D_80109CD8_UnusedMinigame0[3][0][0][0] = D_80103230_UnusedMinigame0;
    D_80109CD8_UnusedMinigame0[4][0][0][0] = D_80103360_UnusedMinigame0;
    D_80109CD8_UnusedMinigame0[5][0][0][0] = D_80103438_UnusedMinigame0;
    for (i = 0; i < 6; i++) {
        for (j = 1; j < 3; j++) {
            for (k = 0; k < 4; k++) {
                for (f = 0; f < 3; f++) {
                    D_80109CD8_UnusedMinigame0[i][j][k][f] = HuMemDirectMalloc(D_80103688_UnusedMinigame0[i] * sizeof(Vtx));
                    for (n = 0; n < D_80103688_UnusedMinigame0[i]; n++) {
                        D_80109CD8_UnusedMinigame0[i][j][k][f][n] = D_80109CD8_UnusedMinigame0[i][0][0][0][n];
                    }
                }
            }
        }
    }
}
s32 func_800FD800_UnusedMinigame0(s32 col, s32 row) {
    UM0Tile* t;
    UM0Tile* n;
    UM0Tile* u;
    UM0Tile* w;
    u32 c;
    u32 r;
    s32 i;
    s32 j;
    s32 k;

    t = D_80108B88_UnusedMinigame0[col][row];
    if (t == NULL) {
        return 0;
    }
    t->match = NULL;
    t->visited = 1;
    for (i = 0; i < 4; i++) {
        c = D_8010370C_UnusedMinigame0[i][0] + t->col;
        if (c < 8) {
            r = D_8010370C_UnusedMinigame0[i][1] + t->row;
            if (r < 6) {
                n = D_80108B88_UnusedMinigame0[c][r];
                if (n != NULL && t->color == n->color) {
                    n->match = t;
                    func_800FDA50_UnusedMinigame0(n, 1);
                    t->state = 1;
                }
            }
        }
    }
    if (t->state != 0) {
        for (i = t->row - 1; i >= 0; i--) {
            u = D_80108B88_UnusedMinigame0[t->col][i];
            if (u != NULL) {
                u->dy += 1.0f;
            }
        }
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 6; j++) {
                w = D_80108B88_UnusedMinigame0[i][j];
                if (w != NULL && w->state == 0) {
                    break;
                }
            }
            if (j == 6) {
                for (k = i; k < 8; k++) {
                    for (j = 0; j < 6; j++) {
                        w = D_80108B88_UnusedMinigame0[k][j];
                        if (w != NULL) {
                            w->dx += 1.0f;
                        }
                    }
                }
            }
        }
    }
    return 1;
}
void func_800FDA50_UnusedMinigame0(UM0Tile* t, s32 match) {
    UM0Tile* n;
    UM0Tile* u;
    u32 c;
    u32 r;
    s32 i;

    if (t->visited == 0) {
        t->visited = 1;
        t->links = 0;
        for (i = 0; i < 4; i++) {
            c = D_8010371C_UnusedMinigame0[i][0] + t->col;
            if (c < 8) {
                r = D_8010371C_UnusedMinigame0[i][1] + t->row;
                if (r < 6) {
                    n = D_80108B88_UnusedMinigame0[c][r];
                    if (n != NULL && n->state == 0 && t->color == n->color) {
                        if (n->visited == 0) {
                            n->match = t;
                            func_800FDA50_UnusedMinigame0(n, match);
                        }
                        t->links |= (D_8010372C_UnusedMinigame0 + i)->bit;
                    }
                }
            }
        }
        if (match != 0) {
            t->state = 1;
            for (i = t->row - 1; i >= 0; i--) {
                u = D_80108B88_UnusedMinigame0[t->col][i];
                if (u != NULL) {
                    u->dy += 1.0f;
                }
            }
        } else {
            t->shape = D_80103608_UnusedMinigame0[t->links].shape;
            t->rot = D_80103608_UnusedMinigame0[t->links].rot;
        }
    }
}
// argument narrowing order: retail narrows col/row twice, GCC CSEs them (masked 41, raw 36); tried implicit narrowing, s16 locals after the call
#ifdef NON_MATCHING
s32 func_800FDC1C_UnusedMinigame0(s32 col, s32 row) {
    UM0Tile** p;

    if ((s16)func_800FD800_UnusedMinigame0((s16)col, (s16)row) != 0) {
        func_801025B8_UnusedMinigame0(D_80108B50_UnusedMinigame0);
        func_80102634_UnusedMinigame0(D_80108B50_UnusedMinigame0, (s16)col, (s16)row);
        p = &D_80108B88_UnusedMinigame0[(s16)col][(s16)row];
        if ((*p)->state == 0) {
            D_80103734_UnusedMinigame0 = 0x10;
            (*p)->flags |= 1;
            return 0;
        }
        D_80103734_UnusedMinigame0 = 0x18;
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_UnusedMinigame0/105EA0", func_800FDC1C_UnusedMinigame0);
#endif
s32 func_800FDCF8_UnusedMinigame0(s16 arg0) {
    UM0Tile* t;
    s32 i;
    s32 j;
    s32 r;

    switch (D_80103700_UnusedMinigame0) {
    case 0:
        D_80103704_UnusedMinigame0 = (D_80103704_UnusedMinigame0 + 1) % 3;
        if (D_80103738_UnusedMinigame0 != 0) {
            func_800258EC(UM0_MODEL_DROP, 4, 0);
            D_8010373C_UnusedMinigame0 = func_80060540(0x1EB, 0);
            D_80103738_UnusedMinigame0 = 0;
        }
        if ((s16)func_80100850_UnusedMinigame0() != 0) {
            D_80103700_UnusedMinigame0 = 1;
            func_800258EC(UM0_MODEL_DROP, 4, 4);
            func_800258EC(UM0_MODEL(D_80103704_UnusedMinigame0), 4, 0);
            func_800FEBF0_UnusedMinigame0(arg0);
            func_8006071C(UM0_SOUND);
            func_80060540(0x1F0, 2);
            D_80103734_UnusedMinigame0 = 0x10;
        }
        break;
    case 1:
        if (D_80103734_UnusedMinigame0 > 0 || arg0 != D_80103740_UnusedMinigame0) {
            D_80103704_UnusedMinigame0 = (D_80103704_UnusedMinigame0 + 1) % 3;
            if (D_80103734_UnusedMinigame0 > 0x10) {
                for (i = 0; i < 6; i++) {
                    for (j = 0; j < 8; j++) {
                        t = &D_8010A040_UnusedMinigame0[j + i * 8];
                        if (t->state == 2) {
                            continue;
                        }
                        if (t->state == 1) {
                            func_800FE1FC_UnusedMinigame0(t);
                        } else if (t->dy > 0.0f || t->dx > 0.0f) {
                            if (D_80103734_UnusedMinigame0 == 0x18) {
                                if (t == D_80108B88_UnusedMinigame0[t->col][t->row]) {
                                    D_80108B88_UnusedMinigame0[t->col][t->row] = NULL;
                                }
                                t->col = t->col - t->dx;
                                t->row = t->row + t->dy;
                                D_80108B88_UnusedMinigame0[t->col][t->row] = t;
                                if (t->dx != 0.0f) {
                                    t->flags |= 2;
                                }
                                if (t->dy != 0.0f) {
                                    t->flags |= 1;
                                }
                            }
                            func_800FE168_UnusedMinigame0(t);
                        }
                    }
                }
            }
            func_800FE3CC_UnusedMinigame0(D_80103734_UnusedMinigame0);
            if (D_80103734_UnusedMinigame0 == 1) {
                func_800FE360_UnusedMinigame0();
            }
            func_800FEBF0_UnusedMinigame0(arg0);
            D_80103734_UnusedMinigame0--;
            func_800258EC(UM0_MODEL((D_80103704_UnusedMinigame0 + 2) % 3), 4, 4);
            func_800258EC(UM0_MODEL((D_80103704_UnusedMinigame0 + 1) % 3), 4, 4);
            func_800258EC(UM0_MODEL(D_80103704_UnusedMinigame0), 4, 0);
            D_80103740_UnusedMinigame0 = arg0;
        }
        func_800FF284_UnusedMinigame0();
        break;
    }
    return D_80103700_UnusedMinigame0;
}
void func_800FE168_UnusedMinigame0(UM0Tile* t) {
    t->x = t->x - t->dx * 5.0;
    t->z = t->z + t->dy * 5.0;
    if (++t->moveTimer >= 8) {
        t->moveTimer = 0;
        t->dx = t->dy = 0.0f;
        func_80060540(0x1EF, 2);
    }
}
void func_800FE1FC_UnusedMinigame0(UM0Tile* t) {
    s32 i;

    if (t == D_80108B88_UnusedMinigame0[t->col][t->row]) {
        D_80108B88_UnusedMinigame0[t->col][t->row] = NULL;
    }
    t->state = 2;
    func_80060540(0x1EE, 2);
    for (i = 0; i < 32; i++) {
        if (D_8010AD60_UnusedMinigame0[i].active == 0) {
            break;
        }
    }
    if (i != 32) {
        D_8010AD60_UnusedMinigame0[i].active = 1;
        D_8010AD60_UnusedMinigame0[i].color = t->color;
        D_8010AD60_UnusedMinigame0[i].timer = 0;
        func_80067480(UM0_SPRGRP, i, 0x8000);
        func_80066DF4(UM0_SPRGRP, i, 0, t->x * 2.5, 100.0f, t->z * 2.5);
        func_800672DC(UM0_SPRGRP, i, 0, 0);
    }
}
void func_800FE360_UnusedMinigame0(void) {
    UM0Tile** slot;
    UM0Tile* t;
    s32 i;
    s32 j;

    for (j = 0; j < 6; j++) {
        for (i = 0; i < 8; i++) {
            t = D_80108B88_UnusedMinigame0[i][j];
            if (t != NULL) {
                if (t->state != 0) {
                    D_80108B88_UnusedMinigame0[i][j] = NULL;
                }
                t->visited = 0;
            }
        }
    }
}
void func_800FE3CC_UnusedMinigame0(s32 arg0) {
    UM0Tile* t;
    s32 i;
    s32 n;

    if ((arg0 == 0x18) | (arg0 == 0x10)) {
        D_80104340_UnusedMinigame0 = 90;
        D_80104344_UnusedMinigame0 = 8.0f;
        func_80060540(0x1F0, 3);
    }
    for (i = 0; i < 6; i++) {
        for (n = 0; n < D_80103688_UnusedMinigame0[i]; n++) {
            if (D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[1] >= 0) {
                D_80109CD8_UnusedMinigame0[i][1][0][D_80103704_UnusedMinigame0][n].v.ob[0] = D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[0];
                D_80109CD8_UnusedMinigame0[i][1][0][D_80103704_UnusedMinigame0][n].v.ob[2] =
                    D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[2] - func_800AEAC0(D_80104340_UnusedMinigame0) * D_80104344_UnusedMinigame0;
                D_80109CD8_UnusedMinigame0[i][1][1][D_80103704_UnusedMinigame0][n].v.ob[0] =
                    D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[0] + func_800AEAC0(D_80104340_UnusedMinigame0) * D_80104344_UnusedMinigame0;
                D_80109CD8_UnusedMinigame0[i][1][1][D_80103704_UnusedMinigame0][n].v.ob[2] = D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[2];
                D_80109CD8_UnusedMinigame0[i][1][2][D_80103704_UnusedMinigame0][n].v.ob[0] = D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[0];
                D_80109CD8_UnusedMinigame0[i][1][2][D_80103704_UnusedMinigame0][n].v.ob[2] =
                    D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[2] + func_800AEAC0(D_80104340_UnusedMinigame0) * D_80104344_UnusedMinigame0;
                D_80109CD8_UnusedMinigame0[i][1][3][D_80103704_UnusedMinigame0][n].v.ob[0] =
                    D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[0] - func_800AEAC0(D_80104340_UnusedMinigame0) * D_80104344_UnusedMinigame0;
                D_80109CD8_UnusedMinigame0[i][1][3][D_80103704_UnusedMinigame0][n].v.ob[2] = D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[2];
                D_80109CD8_UnusedMinigame0[i][2][0][D_80103704_UnusedMinigame0][n].v.ob[0] =
                    D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[0] + func_800AEAC0(D_80104340_UnusedMinigame0) * D_80104344_UnusedMinigame0;
                D_80109CD8_UnusedMinigame0[i][2][0][D_80103704_UnusedMinigame0][n].v.ob[2] =
                    D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[2] - func_800AEAC0(D_80104340_UnusedMinigame0) * D_80104344_UnusedMinigame0;
                D_80109CD8_UnusedMinigame0[i][2][1][D_80103704_UnusedMinigame0][n].v.ob[0] =
                    D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[0] + func_800AEAC0(D_80104340_UnusedMinigame0) * D_80104344_UnusedMinigame0;
                D_80109CD8_UnusedMinigame0[i][2][1][D_80103704_UnusedMinigame0][n].v.ob[2] =
                    D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[2] + func_800AEAC0(D_80104340_UnusedMinigame0) * D_80104344_UnusedMinigame0;
                D_80109CD8_UnusedMinigame0[i][2][2][D_80103704_UnusedMinigame0][n].v.ob[0] =
                    D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[0] - func_800AEAC0(D_80104340_UnusedMinigame0) * D_80104344_UnusedMinigame0;
                D_80109CD8_UnusedMinigame0[i][2][2][D_80103704_UnusedMinigame0][n].v.ob[2] =
                    D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[2] + func_800AEAC0(D_80104340_UnusedMinigame0) * D_80104344_UnusedMinigame0;
                D_80109CD8_UnusedMinigame0[i][2][3][D_80103704_UnusedMinigame0][n].v.ob[0] =
                    D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[0] - func_800AEAC0(D_80104340_UnusedMinigame0) * D_80104344_UnusedMinigame0;
                D_80109CD8_UnusedMinigame0[i][2][3][D_80103704_UnusedMinigame0][n].v.ob[2] =
                    D_80109CD8_UnusedMinigame0[i][0][0][0][n].v.ob[2] - func_800AEAC0(D_80104340_UnusedMinigame0) * D_80104344_UnusedMinigame0;
            }
        }
    }
    if (arg0 < 0x11 && D_80104344_UnusedMinigame0 >= 0.0f) {
        D_80104340_UnusedMinigame0 = (D_80104340_UnusedMinigame0 + 90) % 360;
        D_80104344_UnusedMinigame0 -= 0.5;
    }
    for (i = 0; i < 8; i++) {
        for (n = 0; n < 6; n++) {
            t = &D_8010A040_UnusedMinigame0[i + n * 8];
            if (t->state != 2) {
                if (arg0 == 0x10) {
                    func_800FDA50_UnusedMinigame0(t, 0);
                } else if (arg0 == 1) {
                    t->flags = 0;
                }
                if (t->shape != 0 && t->fade > 0) {
                    t->fade -= 8;
                } else if (t->shape == 0 && t->fade < 0x70) {
                    t->fade += 8;
                }
            }
        }
    }
}
void func_800FEBF0_UnusedMinigame0(s16 arg0) {
    Gfx* gfx;
    Mtx* mtx;
    UM0Tile* t;
    Mtx m;
    s32 i;

    gfx = D_801098A8_UnusedMinigame0[D_80103704_UnusedMinigame0];
    mtx = D_80104350_UnusedMinigame0[D_80103704_UnusedMinigame0];
    gDPPipeSync(gfx++);
    if (arg0 == 0) {
        gDPSetRenderMode(gfx++, 0x404240, 0);
    } else {
        gDPSetRenderMode(gfx++, 0x404A50, 0);
    }
    gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    for (i = 0; i < 48; i++) {
        t = &D_8010A040_UnusedMinigame0[i];
        if (t->state == 0) {
            switch (t->color) {
            case 0:
                gDPSetPrimColor(gfx++, 0, 0, 0xFF - t->fade, 0, 0, t->fade * 0.5 + 112.0);
                break;
            case 1:
                gDPSetPrimColor(gfx++, 0, 0, 0, 56.0 - t->fade * 0.5, 0xFF - t->fade, t->fade * 0.5 + 112.0);
                break;
            case 2:
                gDPSetPrimColor(gfx++, 0, 0, 0, 0xFF - t->fade, 0, t->fade * 0.5 + 112.0);
                break;
            case 3:
                gDPSetPrimColor(gfx++, 0, 0, 0xFF - t->fade, 0xFF - t->fade, 0, t->fade * 0.5 + 112.0);
                break;
            case 4:
                gDPSetPrimColor(gfx++, 0, 0, 0xFF - t->fade, 128.0 - t->fade * 0.5, 0, t->fade * 0.5 + 112.0);
                break;
            }
            switch (t->flags) {
            case 0:
                gSPSegment(gfx++, 15, osVirtualToPhysical(D_80109CD8_UnusedMinigame0[t->shape][0][0][0]));
                break;
            case 1:
                gSPSegment(gfx++, 15, osVirtualToPhysical(D_80109CD8_UnusedMinigame0[t->shape][1][t->rot][D_80103704_UnusedMinigame0]));
                break;
            case 2:
                gSPSegment(gfx++, 15, osVirtualToPhysical(D_80109CD8_UnusedMinigame0[t->shape][1][(t->rot + 1) & 3][D_80103704_UnusedMinigame0]));
                break;
            case 3:
                gSPSegment(gfx++, 15, osVirtualToPhysical(D_80109CD8_UnusedMinigame0[t->shape][2][t->rot][D_80103704_UnusedMinigame0]));
                break;
            }
            guMtxIdent(mtx);
            guRotate(&m, t->rot * 90, 0.0f, 1.0f, 0.0f);
            guMtxCatL(mtx, &m, mtx);
            guTranslate(&m, t->x, 20.0f, t->z);
            guMtxCatL(mtx, &m, mtx);
            gSPMatrix(gfx++, osVirtualToPhysical(mtx++), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gfx++, D_8010AD00_UnusedMinigame0[t->shape]);
            gSPPopMatrix(gfx++, G_MTX_MODELVIEW);
        }
    }
    gSPEndDisplayList(gfx++);
}
void func_800FF284_UnusedMinigame0(void) {
    s32 i;

    for (i = 0; i < 32; i++) {
        if (D_8010AD60_UnusedMinigame0[i].active == 1) {
            D_8010AD60_UnusedMinigame0[i].timer++;
            if (D_8010AD60_UnusedMinigame0[i].timer == 1) {
                switch (D_8010AD60_UnusedMinigame0[i].color) {
                case 0:
                    func_80067558(UM0_SPRGRP, (s16)i, 0xFF, 0x40, 0x40, 0xE4);
                    break;
                case 1:
                    func_80067558(UM0_SPRGRP, (s16)i, 0x40, 0x40, 0xFF, 0xE4);
                    break;
                case 2:
                    func_80067558(UM0_SPRGRP, (s16)i, 0x40, 0xFF, 0x40, 0xE4);
                    break;
                case 3:
                    func_80067558(UM0_SPRGRP, (s16)i, 0xFF, 0xFF, 0x40, 0xE4);
                    break;
                case 4:
                    func_80067558(UM0_SPRGRP, (s16)i, 0xFF, 0xA0, 0x40, 0xE4);
                    break;
                }
            } else if (D_8010AD60_UnusedMinigame0[i].timer > 0x10) {
                func_800674BC(UM0_SPRGRP, i, 0x8000);
                func_800672DC(UM0_SPRGRP, i, 0, 0);
                D_8010AD60_UnusedMinigame0[i].active = 0;
                D_8010AD60_UnusedMinigame0[i].timer = 0;
            }
        }
    }
}
void func_800FF488_UnusedMinigame0(void) {
    s32 i;
    s32 f;
    s32 n;
    s32 flag;

    for (i = 0; i < 4; i++) {
        for (f = 0; f < 3; f++) {
            D_8010B070_UnusedMinigame0[i][f] = HuMemDirectMalloc(17 * sizeof(Vtx));
            D_8010B0A0_UnusedMinigame0[i][f] = 0;
            D_8010B0D0_UnusedMinigame0[i][f] = HuMemDirectMalloc(17 * sizeof(Vtx));
            D_8010B0D0_UnusedMinigame0[i + 4][f] = HuMemDirectMalloc(17 * sizeof(Vtx));
        }
        for (n = 0; n < 17; n++) {
            for (f = 0; f < 3; f++) {
                D_8010B070_UnusedMinigame0[i][f][n] = D_801034A8_UnusedMinigame0[n];
                D_8010B0D0_UnusedMinigame0[i][f][n] = D_801034A8_UnusedMinigame0[n];
                D_8010B0D0_UnusedMinigame0[i + 4][f][n] = D_801034A8_UnusedMinigame0[n];
            }
            D_8010AF60_UnusedMinigame0[i][n] = 0;
            D_8010B458_UnusedMinigame0[i][n] = func_80102568_UnusedMinigame0(32) + 16;
        }
    }
    for (i = 0; i < 48; i++) {
        D_8010A040_UnusedMinigame0[i].drop = &D_80108C60_UnusedMinigame0[i];
        D_80108C60_UnusedMinigame0[i].tile = i;
        D_80108C60_UnusedMinigame0[i].skin = rand8() & 3;
        D_80108C60_UnusedMinigame0[i].state = 0;
        D_80108C60_UnusedMinigame0[i].timer = 0;
        flag = 0;
        switch (i & 7) {
        case 0:
            flag = 1;
        case 4:
            if (flag) {
                D_80108C60_UnusedMinigame0[i].x = -170.0f;
                D_80108C60_UnusedMinigame0[i].z = 100.0f;
            } else {
                D_80108C60_UnusedMinigame0[i].x = -140.0f;
                D_80108C60_UnusedMinigame0[i].z = 130.0f;
            }
            D_80108C60_UnusedMinigame0[i].y = 100.0f;
            D_80108C60_UnusedMinigame0[i].fromX = -140.0f;
            D_80108C60_UnusedMinigame0[i].fromZ = 100.0f;
            break;
        case 1:
            flag = 1;
        case 5:
            if (flag) {
                D_80108C60_UnusedMinigame0[i].x = 170.0f;
                D_80108C60_UnusedMinigame0[i].z = 100.0f;
            } else {
                D_80108C60_UnusedMinigame0[i].x = 140.0f;
                D_80108C60_UnusedMinigame0[i].z = 130.0f;
            }
            D_80108C60_UnusedMinigame0[i].y = 100.0f;
            D_80108C60_UnusedMinigame0[i].fromX = 140.0f;
            D_80108C60_UnusedMinigame0[i].fromZ = 100.0f;
            break;
        case 2:
            flag = 1;
        case 6:
            if (flag) {
                D_80108C60_UnusedMinigame0[i].x = -170.0f;
                D_80108C60_UnusedMinigame0[i].z = -100.0f;
            } else {
                D_80108C60_UnusedMinigame0[i].x = -140.0f;
                D_80108C60_UnusedMinigame0[i].z = -130.0f;
            }
            D_80108C60_UnusedMinigame0[i].y = 100.0f;
            D_80108C60_UnusedMinigame0[i].fromX = -140.0f;
            D_80108C60_UnusedMinigame0[i].fromZ = -100.0f;
            break;
        case 3:
            flag = 1;
        case 7:
            if (flag) {
                D_80108C60_UnusedMinigame0[i].x = 170.0f;
                D_80108C60_UnusedMinigame0[i].z = -100.0f;
            } else {
                D_80108C60_UnusedMinigame0[i].x = 140.0f;
                D_80108C60_UnusedMinigame0[i].z = -130.0f;
            }
            D_80108C60_UnusedMinigame0[i].y = 100.0f;
            D_80108C60_UnusedMinigame0[i].fromX = 140.0f;
            D_80108C60_UnusedMinigame0[i].fromZ = -100.0f;
            break;
        }
        D_80108C60_UnusedMinigame0[i].vx = D_8010A040_UnusedMinigame0[i].x - D_80108C60_UnusedMinigame0[i].fromX;
        D_80108C60_UnusedMinigame0[i].vz = D_8010A040_UnusedMinigame0[i].z - D_80108C60_UnusedMinigame0[i].fromZ;
        D_80108C60_UnusedMinigame0[i].angle =
            func_800B0CD8(D_80108C60_UnusedMinigame0[i].vx, D_80108C60_UnusedMinigame0[i].vz) + 90.0f;
    }
    for (i = 0; i < 8; i++) {
        D_80108C60_UnusedMinigame0[i].state = 1;
    }
    D_80108C50_UnusedMinigame0[0] = HuMemDirectMalloc(768 * sizeof(Gfx));
    D_80108C50_UnusedMinigame0[1] = HuMemDirectMalloc(768 * sizeof(Gfx));
    D_80108C50_UnusedMinigame0[2] = HuMemDirectMalloc(768 * sizeof(Gfx));
    D_80109CCC_UnusedMinigame0 = func_80024198(0x19, D_80108C50_UnusedMinigame0[0], 4);
    func_800FFA64_UnusedMinigame0();
    func_80025830(UM0_MODEL_DROP, 2.5f, 2.5f, 2.5f);
}
// float register allocation (masked 0)
#ifdef NON_MATCHING
void func_800FFA64_UnusedMinigame0(void) {
    Gfx* gfx;
    Mtx* mtx;
    Mtx m;
    s32 i;
    s32 n;
    s32 ring;
    f32 w;
    f32 s;
    f32 sc;

    ring = 0;
    *D_800F2B7C[D_80109CCC_UnusedMinigame0].unk_6C->unk_00 = D_80108C50_UnusedMinigame0[D_80103704_UnusedMinigame0];
    gfx = D_80108C50_UnusedMinigame0[D_80103704_UnusedMinigame0];
    mtx = D_80106750_UnusedMinigame0[D_80103704_UnusedMinigame0];
    gDPPipeSync(gfx++);
    gDPSetRenderMode(gfx++, 0x504240, 0);
    gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    for (i = 0; i < 48; i++) {
        switch (D_8010A040_UnusedMinigame0[i].color) {
        case 0:
            gDPSetPrimColor(gfx++, 0, 0, 0xFF, 0, 0, 0x70);
            break;
        case 1:
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0xFF, 0x70);
            break;
        case 2:
            gDPSetPrimColor(gfx++, 0, 0, 0, 0xFF, 0, 0x70);
            break;
        case 3:
            gDPSetPrimColor(gfx++, 0, 0, 0xFF, 0xFF, 0, 0x70);
            break;
        case 4:
            gDPSetPrimColor(gfx++, 0, 0, 0xFF, 0x80, 0, 0x70);
            break;
        }
        switch (D_80108C60_UnusedMinigame0[i].state) {
        case 0:
            continue;
        case 1:
            gSPSegment(gfx++, 15, osVirtualToPhysical(D_8010B070_UnusedMinigame0[D_80108C60_UnusedMinigame0[i].skin][D_80103704_UnusedMinigame0]));
            guMtxIdent(mtx);
            if ((i & 7) < 4) {
                s = 2.0f * func_800AEAC0(D_80108C60_UnusedMinigame0[i].timer * 180 * 0.25 * 0.5) + 1.0f;
                guScale(&m, s, 1.0f, 1.0 - func_800AEAC0(D_80108C60_UnusedMinigame0[i].timer * 180 * 0.25 * 0.5) * 0.75);
                guMtxCatL(mtx, &m, mtx);
                guRotate(&m, 90.0f, 0.0f, 0.0f, 1.0f);
            } else {
                s = 1.0 - func_800AEAC0(D_80108C60_UnusedMinigame0[i].timer * 180 * 0.25 * 0.5) * 0.75;
                guScale(&m, s, 1.0f, 2.0f * func_800AEAC0(D_80108C60_UnusedMinigame0[i].timer * 180 * 0.25 * 0.5) + 1.0f);
                guMtxCatL(mtx, &m, mtx);
                guRotate(&m, 90.0f, 1.0f, 0.0f, 0.0f);
            }
            guMtxCatL(mtx, &m, mtx);
            guTranslate(&m, D_80108C60_UnusedMinigame0[i].x, D_80108C60_UnusedMinigame0[i].y, D_80108C60_UnusedMinigame0[i].z);
            guMtxCatL(mtx, &m, mtx);
            gSPMatrix(gfx++, osVirtualToPhysical(mtx++), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gfx++, D_801035B8_UnusedMinigame0);
            break;
        case 2:
            gSPSegment(gfx++, 15, osVirtualToPhysical(D_8010B070_UnusedMinigame0[D_80108C60_UnusedMinigame0[i].skin][D_80103704_UnusedMinigame0]));
            guMtxIdent(mtx);
            guRotate(&m, (D_80108C60_UnusedMinigame0[i].angle + 90.0f) * func_800AEAC0(D_80108C60_UnusedMinigame0[i].timer * 90 * 0.25 * 0.5),
                     0.0f, 1.0f, 0.0f);
            guMtxCatL(mtx, &m, mtx);
            if ((i & 7) < 4) {
                guRotate(&m, 90.0 - D_80108C60_UnusedMinigame0[i].timer * 90 * 0.25 * 0.5, 0.0f, 0.0f, 1.0f);
            } else {
                guRotate(&m, 90.0 - D_80108C60_UnusedMinigame0[i].timer * 90 * 0.25 * 0.5, 1.0f, 0.0f, 0.0f);
            }
            guMtxCatL(mtx, &m, mtx);
            guTranslate(&m, D_80108C60_UnusedMinigame0[i].x, D_80108C60_UnusedMinigame0[i].y, D_80108C60_UnusedMinigame0[i].z);
            guMtxCatL(mtx, &m, mtx);
            gSPMatrix(gfx++, osVirtualToPhysical(mtx++), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gfx++, D_801035B8_UnusedMinigame0);
            break;
        case 3:
        case 4:
        case 5:
        case 6:
            gSPSegment(gfx++, 15, osVirtualToPhysical(D_8010B070_UnusedMinigame0[D_80108C60_UnusedMinigame0[i].skin][D_80103704_UnusedMinigame0]));
            w = (D_80108C60_UnusedMinigame0[i].speed - 1.0f) * 0.125;
            if (w < 0.2) {
                w = 0.2f;
            }
            guMtxIdent(mtx);
            sc = (func_800AEAC0((D_80108C60_UnusedMinigame0[i].timer & 0xF) * 360 * 0.0625 - 90.0) + 1.0f) * w + 1.0f;
            guScale(&m, sc, 1.0f, 1.0 - (func_800AEAC0((D_80108C60_UnusedMinigame0[i].timer & 0xF) * 360 * 0.0625 - 90.0) + 1.0f) * 0.25);
            guMtxCatL(mtx, &m, mtx);
            guRotate(&m, D_80108C60_UnusedMinigame0[i].dir + 90.0f, 0.0f, 1.0f, 0.0f);
            guMtxCatL(mtx, &m, mtx);
            guTranslate(&m, D_80108C60_UnusedMinigame0[i].x, 1.0f, D_80108C60_UnusedMinigame0[i].z);
            guMtxCatL(mtx, &m, mtx);
            gSPMatrix(gfx++, osVirtualToPhysical(mtx++), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gfx++, D_801035B8_UnusedMinigame0);
            break;
        case 7:
            for (n = 0; n < 16; n++) {
                D_8010B0D0_UnusedMinigame0[ring][D_80103704_UnusedMinigame0][n].v.ob[0] =
                    D_801034A8_UnusedMinigame0[n].v.ob[0] * D_80108C60_UnusedMinigame0[i].timer * 0.25 +
                    D_8010B070_UnusedMinigame0[D_80108C60_UnusedMinigame0[i].skin][D_80103704_UnusedMinigame0][n].v.ob[0] *
                        (4 - D_80108C60_UnusedMinigame0[i].timer) * 0.25;
                D_8010B0D0_UnusedMinigame0[ring][D_80103704_UnusedMinigame0][n].v.ob[2] =
                    D_801034A8_UnusedMinigame0[n].v.ob[2] * D_80108C60_UnusedMinigame0[i].timer * 0.25 +
                    D_8010B070_UnusedMinigame0[D_80108C60_UnusedMinigame0[i].skin][D_80103704_UnusedMinigame0][n].v.ob[2] *
                        (4 - D_80108C60_UnusedMinigame0[i].timer) * 0.25;
            }
            gSPSegment(gfx++, 15, osVirtualToPhysical(D_8010B0D0_UnusedMinigame0[ring][D_80103704_UnusedMinigame0]));
            ring = (ring + 1) & 7;
            guMtxIdent(mtx);
            guTranslate(&m, D_80108C60_UnusedMinigame0[i].x, 2.0f, D_80108C60_UnusedMinigame0[i].z);
            guMtxCatL(mtx, &m, mtx);
            gSPMatrix(gfx++, osVirtualToPhysical(mtx++), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gfx++, D_801035B8_UnusedMinigame0);
            break;
        case 8:
            gSPSegment(gfx++, 15, osVirtualToPhysical(D_80102D20_UnusedMinigame0));
            guMtxIdent(mtx);
            guScale(&m, 1.0f, D_80108C60_UnusedMinigame0[i].timer * 0.125, 1.0f);
            guMtxCatL(mtx, &m, mtx);
            guTranslate(&m, D_80108C60_UnusedMinigame0[i].x, D_80108C60_UnusedMinigame0[i].timer * 20 * 0.125, D_80108C60_UnusedMinigame0[i].z);
            guMtxCatL(mtx, &m, mtx);
            gSPMatrix(gfx++, osVirtualToPhysical(mtx++), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gfx++, D_80102F20_UnusedMinigame0);
            break;
        case 9:
            gSPSegment(gfx++, 15, osVirtualToPhysical(D_80109CD8_UnusedMinigame0[0][1][0][D_80103704_UnusedMinigame0]));
            guMtxIdent(mtx);
            guTranslate(&m, D_80108C60_UnusedMinigame0[i].x, 20.0f, D_80108C60_UnusedMinigame0[i].z);
            guMtxCatL(mtx, &m, mtx);
            gSPMatrix(gfx++, osVirtualToPhysical(mtx++), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gfx++, D_80102F20_UnusedMinigame0);
            break;
        case 10:
            gSPSegment(gfx++, 15, osVirtualToPhysical(D_80102D20_UnusedMinigame0));
            guMtxIdent(mtx);
            guTranslate(&m, D_80108C60_UnusedMinigame0[i].x, 20.0f, D_80108C60_UnusedMinigame0[i].z);
            guMtxCatL(mtx, &m, mtx);
            gSPMatrix(gfx++, osVirtualToPhysical(mtx++), G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gSPDisplayList(gfx++, D_80102F20_UnusedMinigame0);
            break;
        }
        gSPPopMatrix(gfx++, G_MTX_MODELVIEW);
    }
    gSPEndDisplayList(gfx++);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_UnusedMinigame0/105EA0", func_800FFA64_UnusedMinigame0);
#endif
// register allocation and block order (state machine; logic checked against the asm)
#ifdef NON_MATCHING
s32 func_80100850_UnusedMinigame0(void) {
    s32* p;
    s32 i;
    s32 n;
    s32 a;
    f32 diff;
    f32 dist;
    f32 nx;
    f32 nz;

    for (i = 0; i < 4; i++) {
        for (n = 0; n < 16; n++) {
            p = &D_8010AF60_UnusedMinigame0[i][n];
            D_8010B070_UnusedMinigame0[i][D_80103704_UnusedMinigame0][n].v.ob[0] =
                D_801034A8_UnusedMinigame0[n].v.ob[0] + D_801034A8_UnusedMinigame0[n].v.ob[0] * (func_800AEAC0(*p) + 1.0f) * 0.225;
            D_8010B070_UnusedMinigame0[i][D_80103704_UnusedMinigame0][n].v.ob[2] =
                D_801034A8_UnusedMinigame0[n].v.ob[2] + D_801034A8_UnusedMinigame0[n].v.ob[2] * (-func_800AEAC0(*p) - 1.0f) * -0.225;
            D_8010B070_UnusedMinigame0[i][D_80103704_UnusedMinigame0][n].v.ob[0] =
                D_8010B070_UnusedMinigame0[i][D_80103704_UnusedMinigame0][n].v.ob[0] * 0.85;
            D_8010B070_UnusedMinigame0[i][D_80103704_UnusedMinigame0][n].v.ob[2] =
                D_8010B070_UnusedMinigame0[i][D_80103704_UnusedMinigame0][n].v.ob[2] * 0.85;
            a = (*p + D_8010B458_UnusedMinigame0[i][n]) % 360;
            if ((s32)fabs(a - D_8010AF60_UnusedMinigame0[i][(n + 15) & 0xF]) < 270) {
                *p = a;
            }
        }
    }
    for (i = 0; i < 48; i++) {
        switch (D_80108C60_UnusedMinigame0[i].state) {
        case 0:
            continue;
        case 1:
            if (D_80108C60_UnusedMinigame0[i].timer < 8) {
                D_80108C60_UnusedMinigame0[i].y =
                    100.0f - func_800AEAC0(D_80108C60_UnusedMinigame0[i].timer * 90 * 0.25 * 0.5) * 90.0f;
            } else if (D_80108C60_UnusedMinigame0[i].timer >= 9) {
                D_80108C60_UnusedMinigame0[i].state = 2;
                if (i + 8 < 48) {
                    D_80108C60_UnusedMinigame0[i + 8].state = 1;
                }
                D_80108C60_UnusedMinigame0[i].timer = 0;
            }
            break;
        case 2:
            if ((i & 7) < 4) {
                if (i & 1) {
                    D_80108C60_UnusedMinigame0[i].x =
                        D_80108C60_UnusedMinigame0[i].timer * D_80108C60_UnusedMinigame0[i].fromX * 0.25 * 0.5 +
                        (8 - D_80108C60_UnusedMinigame0[i].timer) * 170 * 0.25 * 0.5;
                } else {
                    D_80108C60_UnusedMinigame0[i].x =
                        D_80108C60_UnusedMinigame0[i].timer * D_80108C60_UnusedMinigame0[i].fromX * 0.25 * 0.5 +
                        -((8 - D_80108C60_UnusedMinigame0[i].timer) * 170) * 0.25 * 0.5;
                }
            } else {
                if ((i & 3) < 2) {
                    D_80108C60_UnusedMinigame0[i].z =
                        D_80108C60_UnusedMinigame0[i].timer * D_80108C60_UnusedMinigame0[i].fromZ * 0.25 * 0.5 +
                        (8 - D_80108C60_UnusedMinigame0[i].timer) * 130 * 0.25 * 0.5;
                } else {
                    D_80108C60_UnusedMinigame0[i].z =
                        D_80108C60_UnusedMinigame0[i].timer * D_80108C60_UnusedMinigame0[i].fromZ * 0.25 * 0.5 +
                        -((8 - D_80108C60_UnusedMinigame0[i].timer) * 130) * 0.25 * 0.5;
                }
            }
            D_80108C60_UnusedMinigame0[i].y = D_80108C60_UnusedMinigame0[i].timer * 0.25 * 0.5 +
                                              (8 - D_80108C60_UnusedMinigame0[i].timer) * 10 * 0.25 * 0.5;
            if (D_80108C60_UnusedMinigame0[i].timer >= 9) {
                D_80108C60_UnusedMinigame0[i].state = 3;
                D_80108C60_UnusedMinigame0[i].wait = (rand8() & 0xF) + 4;
                D_80108C60_UnusedMinigame0[i].timer = 0;
                D_80108C60_UnusedMinigame0[i].speed = 0.0f;
                switch (i & 3) {
                case 0:
                    D_80108C60_UnusedMinigame0[i].vx = rand8() & 0x1F;
                    D_80108C60_UnusedMinigame0[i].vz = -(u8)(rand8() % 24);
                    break;
                case 1:
                    D_80108C60_UnusedMinigame0[i].vx = -(f32)(rand8() & 0x1F);
                    D_80108C60_UnusedMinigame0[i].vz = -(u8)(rand8() % 24);
                    break;
                case 2:
                    D_80108C60_UnusedMinigame0[i].vx = rand8() & 0x1F;
                    D_80108C60_UnusedMinigame0[i].vz = (u8)(rand8() % 24);
                    break;
                case 3:
                    D_80108C60_UnusedMinigame0[i].vx = -(f32)(rand8() & 0x1F);
                    D_80108C60_UnusedMinigame0[i].vz = (u8)(rand8() % 24);
                    break;
                }
                D_80108C60_UnusedMinigame0[i].spin = ((rand8() & 7) + 1) * 0.5;
                if (rand8() & 1) {
                    D_80108C60_UnusedMinigame0[i].spin = -D_80108C60_UnusedMinigame0[i].spin;
                }
                D_80108C60_UnusedMinigame0[i].angle = D_80108C60_UnusedMinigame0[i].dir =
                    func_800B0CD8(D_80108C60_UnusedMinigame0[i].vx, D_80108C60_UnusedMinigame0[i].vz);
                D_80108C60_UnusedMinigame0[i].vx = D_80108C60_UnusedMinigame0[i].vx * 0.1;
                D_80108C60_UnusedMinigame0[i].vz = D_80108C60_UnusedMinigame0[i].vz * 0.1;
                D_80108C60_UnusedMinigame0[i].speed =
                    func_800B1750(D_80108C60_UnusedMinigame0[i].vx * D_80108C60_UnusedMinigame0[i].vx +
                                  D_80108C60_UnusedMinigame0[i].vz * D_80108C60_UnusedMinigame0[i].vz);
            }
            break;
        case 3:
            if (D_80108C60_UnusedMinigame0[i].timer > D_80108C60_UnusedMinigame0[i].wait) {
                D_80108C60_UnusedMinigame0[i].fromX = D_80108C60_UnusedMinigame0[i].x;
                D_80108C60_UnusedMinigame0[i].fromZ = D_80108C60_UnusedMinigame0[i].z;
                diff = D_80108C60_UnusedMinigame0[i].angle - D_80108C60_UnusedMinigame0[i].dir;
                dist = func_800B1750(
                    (D_8010A040_UnusedMinigame0[D_80108C60_UnusedMinigame0[i].tile].x - D_80108C60_UnusedMinigame0[i].fromX) *
                        (D_8010A040_UnusedMinigame0[D_80108C60_UnusedMinigame0[i].tile].x - D_80108C60_UnusedMinigame0[i].fromX) +
                    (D_8010A040_UnusedMinigame0[D_80108C60_UnusedMinigame0[i].tile].z - D_80108C60_UnusedMinigame0[i].fromZ) *
                        (D_8010A040_UnusedMinigame0[D_80108C60_UnusedMinigame0[i].tile].z - D_80108C60_UnusedMinigame0[i].fromZ));
                D_80108C60_UnusedMinigame0[i].angle =
                    func_800B0CD8(D_8010A040_UnusedMinigame0[i].x - D_80108C60_UnusedMinigame0[i].fromX,
                                  D_8010A040_UnusedMinigame0[i].z - D_80108C60_UnusedMinigame0[i].fromZ);
                if (dist > 45.0f) {
                    D_80108C60_UnusedMinigame0[i].speed = 450.0 / dist;
                    D_80108C60_UnusedMinigame0[i].state = 4;
                    if (((diff <= 180.0f) & (diff > 0.0f)) || diff < -180.0f) {
                        D_80108C60_UnusedMinigame0[i].spin = 4.0f;
                    } else if (((diff > 180.0f) | (diff >= -180.0f)) && diff <= 0.0f) {
                        D_80108C60_UnusedMinigame0[i].spin = -4.0f;
                    }
                } else if (dist > 5.0f) {
                    D_80108C60_UnusedMinigame0[i].state = 5;
                    if (((diff <= 180.0f) & (diff > 0.0f)) || diff < -180.0f) {
                        D_80108C60_UnusedMinigame0[i].spin = 8.0f;
                    } else if (diff > 180.0f || ((diff >= -180.0f) & (diff <= 0.0f))) {
                        D_80108C60_UnusedMinigame0[i].spin = -8.0f;
                    }
                    D_80108C60_UnusedMinigame0[i].speed =
                        func_800B1750(D_80108C60_UnusedMinigame0[i].vx * D_80108C60_UnusedMinigame0[i].vx +
                                      D_80108C60_UnusedMinigame0[i].vz * D_80108C60_UnusedMinigame0[i].vz) * 0.8;
                } else {
                    D_80108C60_UnusedMinigame0[i].state = 7;
                    D_80108C60_UnusedMinigame0[i].x = D_8010A040_UnusedMinigame0[i].x;
                    D_80108C60_UnusedMinigame0[i].z = D_8010A040_UnusedMinigame0[i].z;
                    D_80108C60_UnusedMinigame0[i].vx = 0.0f;
                    D_80108C60_UnusedMinigame0[i].vz = 0.0f;
                    D_80108C60_UnusedMinigame0[i].timer = 0;
                    break;
                }
                D_80108C60_UnusedMinigame0[i].vz = func_800AEFD0(D_80108C60_UnusedMinigame0[i].dir) * D_80108C60_UnusedMinigame0[i].speed;
                D_80108C60_UnusedMinigame0[i].vx = func_800AEAC0(D_80108C60_UnusedMinigame0[i].dir) * D_80108C60_UnusedMinigame0[i].speed;
                D_80108C60_UnusedMinigame0[i].timer = 0;
            } else if ((D_80108C60_UnusedMinigame0[i].timer & 3) == 0) {
                D_80108C60_UnusedMinigame0[i].spin = ((rand8() & 7) + 1) * 0.5;
                if (rand8() & 1) {
                    D_80108C60_UnusedMinigame0[i].spin = -D_80108C60_UnusedMinigame0[i].spin;
                }
            }
            D_80108C60_UnusedMinigame0[i].dir = D_80108C60_UnusedMinigame0[i].dir + D_80108C60_UnusedMinigame0[i].spin;
            D_80108C60_UnusedMinigame0[i].vz = func_800AEFD0(D_80108C60_UnusedMinigame0[i].dir) * D_80108C60_UnusedMinigame0[i].speed;
            D_80108C60_UnusedMinigame0[i].vx = func_800AEAC0(D_80108C60_UnusedMinigame0[i].dir) * D_80108C60_UnusedMinigame0[i].speed;
            nx = D_80108C60_UnusedMinigame0[i].x + D_80108C60_UnusedMinigame0[i].vx;
            if (-140.0f < nx) {
                if (nx < 140.0f) {
                    D_80108C60_UnusedMinigame0[i].x = nx;
                }
            }
            nz = D_80108C60_UnusedMinigame0[i].z + D_80108C60_UnusedMinigame0[i].vz;
            if (-100.0f < nz) {
                if (nz < 100.0f) {
                    D_80108C60_UnusedMinigame0[i].z = nz;
                }
            }
            break;
        case 4:
            D_80108C60_UnusedMinigame0[i].fromX = D_80108C60_UnusedMinigame0[i].x;
            D_80108C60_UnusedMinigame0[i].fromZ = D_80108C60_UnusedMinigame0[i].z;
            D_80108C60_UnusedMinigame0[i].angle =
                (s32)(func_800B0CD8(D_8010A040_UnusedMinigame0[i].x - D_80108C60_UnusedMinigame0[i].fromX,
                                    D_8010A040_UnusedMinigame0[i].z - D_80108C60_UnusedMinigame0[i].fromZ) + 360.0f) % 360;
            diff = D_80108C60_UnusedMinigame0[i].angle - D_80108C60_UnusedMinigame0[i].dir;
            dist = func_800B1750((D_8010A040_UnusedMinigame0[i].x - D_80108C60_UnusedMinigame0[i].fromX) *
                                     (D_8010A040_UnusedMinigame0[i].x - D_80108C60_UnusedMinigame0[i].fromX) +
                                 (D_8010A040_UnusedMinigame0[i].z - D_80108C60_UnusedMinigame0[i].fromZ) *
                                     (D_8010A040_UnusedMinigame0[i].z - D_80108C60_UnusedMinigame0[i].fromZ));
            if (dist > 45.0f) {
                D_80108C60_UnusedMinigame0[i].speed = 450.0 / dist;
                if (((diff <= 180.0f) & (diff > 0.0f)) || diff < -180.0f) {
                    D_80108C60_UnusedMinigame0[i].spin =
                        D_80108C60_UnusedMinigame0[i].speed * D_80108C60_UnusedMinigame0[i].speed * 0.03125 + 4.5;
                } else if (diff > 180.0f || ((diff >= -180.0f) & (diff <= 0.0f))) {
                    D_80108C60_UnusedMinigame0[i].spin =
                        -4.5 - D_80108C60_UnusedMinigame0[i].speed * D_80108C60_UnusedMinigame0[i].speed * 0.03125;
                }
                if (D_80108C60_UnusedMinigame0[i].timer >= 16) {
                    D_80108C60_UnusedMinigame0[i].state = 6;
                }
            } else if (dist > 5.0f) {
                D_80108C60_UnusedMinigame0[i].state = 5;
                if (((diff <= 180.0f) & (diff > 0.0f)) || diff < -180.0f) {
                    D_80108C60_UnusedMinigame0[i].spin = 9.0f;
                } else if (diff > 180.0f || ((diff >= -180.0f) & (diff <= 0.0f))) {
                    D_80108C60_UnusedMinigame0[i].spin = -9.0f;
                }
                D_80108C60_UnusedMinigame0[i].speed =
                    func_800B1750(D_80108C60_UnusedMinigame0[i].vx * D_80108C60_UnusedMinigame0[i].vx +
                                  D_80108C60_UnusedMinigame0[i].vz * D_80108C60_UnusedMinigame0[i].vz) * 0.8;
            } else {
                D_80108C60_UnusedMinigame0[i].state = 7;
                D_80108C60_UnusedMinigame0[i].x = D_8010A040_UnusedMinigame0[i].x;
                D_80108C60_UnusedMinigame0[i].z = D_8010A040_UnusedMinigame0[i].z;
                D_80108C60_UnusedMinigame0[i].vx = 0.0f;
                D_80108C60_UnusedMinigame0[i].vz = 0.0f;
                D_80108C60_UnusedMinigame0[i].timer = 0;
                break;
            }
            D_80108C60_UnusedMinigame0[i].dir =
                (s32)(D_80108C60_UnusedMinigame0[i].dir + D_80108C60_UnusedMinigame0[i].spin + 360.0f) % 360;
            D_80108C60_UnusedMinigame0[i].vz = func_800AEFD0(D_80108C60_UnusedMinigame0[i].dir) * D_80108C60_UnusedMinigame0[i].speed;
            D_80108C60_UnusedMinigame0[i].vx = func_800AEAC0(D_80108C60_UnusedMinigame0[i].dir) * D_80108C60_UnusedMinigame0[i].speed;
            nx = D_80108C60_UnusedMinigame0[i].x + D_80108C60_UnusedMinigame0[i].vx;
            if (-140.0f < nx) {
                if (nx < 140.0f) {
                    D_80108C60_UnusedMinigame0[i].x = nx;
                }
            }
            nz = D_80108C60_UnusedMinigame0[i].z + D_80108C60_UnusedMinigame0[i].vz;
            if (-100.0f < nz) {
                if (nz < 100.0f) {
                    D_80108C60_UnusedMinigame0[i].z = nz;
                }
            }
            break;
        case 5:
            D_80108C60_UnusedMinigame0[i].fromX = D_80108C60_UnusedMinigame0[i].x;
            D_80108C60_UnusedMinigame0[i].fromZ = D_80108C60_UnusedMinigame0[i].z;
            D_80108C60_UnusedMinigame0[i].angle =
                (s32)(func_800B0CD8(D_8010A040_UnusedMinigame0[i].x - D_80108C60_UnusedMinigame0[i].fromX,
                                    D_8010A040_UnusedMinigame0[i].z - D_80108C60_UnusedMinigame0[i].fromZ) + 360.0f) % 360;
            diff = D_80108C60_UnusedMinigame0[i].angle - D_80108C60_UnusedMinigame0[i].dir;
            dist = func_800B1750((D_8010A040_UnusedMinigame0[i].x - D_80108C60_UnusedMinigame0[i].fromX) *
                                     (D_8010A040_UnusedMinigame0[i].x - D_80108C60_UnusedMinigame0[i].fromX) +
                                 (D_8010A040_UnusedMinigame0[i].z - D_80108C60_UnusedMinigame0[i].fromZ) *
                                     (D_8010A040_UnusedMinigame0[i].z - D_80108C60_UnusedMinigame0[i].fromZ));
            if (((diff <= 180.0f) & (diff > 0.0f)) || diff < -180.0f) {
                D_80108C60_UnusedMinigame0[i].spin = 9.0f;
            } else if (diff > 180.0f || ((diff >= -180.0f) & (diff <= 0.0f))) {
                D_80108C60_UnusedMinigame0[i].spin = -9.0f;
            }
            if (dist <= 5.0f) {
                D_80108C60_UnusedMinigame0[i].state = 7;
                D_80108C60_UnusedMinigame0[i].x = D_8010A040_UnusedMinigame0[i].x;
                D_80108C60_UnusedMinigame0[i].z = D_8010A040_UnusedMinigame0[i].z;
                D_80108C60_UnusedMinigame0[i].vx = 0.0f;
                D_80108C60_UnusedMinigame0[i].vz = 0.0f;
                D_80108C60_UnusedMinigame0[i].timer = 0;
                break;
            }
            if (D_80108C60_UnusedMinigame0[i].timer >= 32) {
                D_80108C60_UnusedMinigame0[i].state = 6;
            }
            if (D_80108C60_UnusedMinigame0[i].speed > 0.5) {
                D_80108C60_UnusedMinigame0[i].speed = D_80108C60_UnusedMinigame0[i].speed * 0.9;
            }
            D_80108C60_UnusedMinigame0[i].dir =
                (s32)(D_80108C60_UnusedMinigame0[i].dir + D_80108C60_UnusedMinigame0[i].spin + 360.0f) % 360;
            D_80108C60_UnusedMinigame0[i].vz = func_800AEFD0(D_80108C60_UnusedMinigame0[i].dir) * D_80108C60_UnusedMinigame0[i].speed;
            D_80108C60_UnusedMinigame0[i].vx = func_800AEAC0(D_80108C60_UnusedMinigame0[i].dir) * D_80108C60_UnusedMinigame0[i].speed;
            D_80108C60_UnusedMinigame0[i].x = D_80108C60_UnusedMinigame0[i].x + D_80108C60_UnusedMinigame0[i].vx;
            D_80108C60_UnusedMinigame0[i].z = D_80108C60_UnusedMinigame0[i].z + D_80108C60_UnusedMinigame0[i].vz;
            break;
        case 6:
            D_80108C60_UnusedMinigame0[i].fromX = D_80108C60_UnusedMinigame0[i].x;
            D_80108C60_UnusedMinigame0[i].fromZ = D_80108C60_UnusedMinigame0[i].z;
            D_80108C60_UnusedMinigame0[i].angle =
                func_800B0CD8(D_8010A040_UnusedMinigame0[i].x - D_80108C60_UnusedMinigame0[i].fromX,
                              D_8010A040_UnusedMinigame0[i].z - D_80108C60_UnusedMinigame0[i].fromZ);
            D_80108C60_UnusedMinigame0[i].dir = (s32)(D_80108C60_UnusedMinigame0[i].angle + 360.0f) % 360;
            dist = func_800B1750((D_8010A040_UnusedMinigame0[i].x - D_80108C60_UnusedMinigame0[i].fromX) *
                                     (D_8010A040_UnusedMinigame0[i].x - D_80108C60_UnusedMinigame0[i].fromX) +
                                 (D_8010A040_UnusedMinigame0[i].z - D_80108C60_UnusedMinigame0[i].fromZ) *
                                     (D_8010A040_UnusedMinigame0[i].z - D_80108C60_UnusedMinigame0[i].fromZ));
            if (dist <= 5.0f) {
                D_80108C60_UnusedMinigame0[i].state = 7;
                D_80108C60_UnusedMinigame0[i].x = D_8010A040_UnusedMinigame0[i].x;
                D_80108C60_UnusedMinigame0[i].z = D_8010A040_UnusedMinigame0[i].z;
                D_80108C60_UnusedMinigame0[i].vx = 0.0f;
                D_80108C60_UnusedMinigame0[i].vz = 0.0f;
                D_80108C60_UnusedMinigame0[i].timer = 0;
                break;
            }
            if (dist > 36.0f) {
                D_80108C60_UnusedMinigame0[i].speed = 540.0 / dist;
            } else if (D_80108C60_UnusedMinigame0[i].speed > 1.0) {
                D_80108C60_UnusedMinigame0[i].speed = D_80108C60_UnusedMinigame0[i].speed * 0.9;
            }
            D_80108C60_UnusedMinigame0[i].vz = func_800AEFD0(D_80108C60_UnusedMinigame0[i].dir) * D_80108C60_UnusedMinigame0[i].speed;
            D_80108C60_UnusedMinigame0[i].vx = func_800AEAC0(D_80108C60_UnusedMinigame0[i].dir) * D_80108C60_UnusedMinigame0[i].speed;
            D_80108C60_UnusedMinigame0[i].x = D_80108C60_UnusedMinigame0[i].x + D_80108C60_UnusedMinigame0[i].vx;
            D_80108C60_UnusedMinigame0[i].z = D_80108C60_UnusedMinigame0[i].z + D_80108C60_UnusedMinigame0[i].vz;
            break;
        case 7:
            if (D_80108C60_UnusedMinigame0[i].timer >= 5) {
                D_80108C60_UnusedMinigame0[i].state = 8;
                D_80108C60_UnusedMinigame0[i].timer = 0;
            }
            break;
        case 8:
            if (D_80108C60_UnusedMinigame0[i].timer >= 8) {
                D_80108C60_UnusedMinigame0[i].state = 10;
                D_80103748_UnusedMinigame0 = 90;
                D_80103754_UnusedMinigame0 = 1.6f;
                if (func_800115C8(UM0_SOUND2) == 0 || D_80103750_UnusedMinigame0 == -1) {
                    D_80103750_UnusedMinigame0 = func_80060540(0x1F1, 3);
                }
                D_80103750_UnusedMinigame0 ^= 1;
                D_8010374C_UnusedMinigame0++;
            }
            break;
        case 9:
            if (D_80108C60_UnusedMinigame0[i].timer >= 16) {
                D_80108C60_UnusedMinigame0[i].state = 10;
                D_80108C60_UnusedMinigame0[i].timer = 0;
            }
            break;
        case 10:
            if (D_8010374C_UnusedMinigame0 == 48) {
                return 1;
            }
            break;
        }
        if (D_80108C60_UnusedMinigame0[i].state != 10) {
            D_80108C60_UnusedMinigame0[i].timer++;
        }
    }
    for (n = 0; n < 24; n++) {
        if (D_80109CD8_UnusedMinigame0[0][0][0][0][n].v.ob[1] >= 0) {
            D_80109CD8_UnusedMinigame0[0][1][0][D_80103704_UnusedMinigame0][n].v.ob[0] = D_80109CD8_UnusedMinigame0[0][0][0][0][n].v.ob[0];
            D_80109CD8_UnusedMinigame0[0][1][0][D_80103704_UnusedMinigame0][n].v.ob[2] =
                D_80109CD8_UnusedMinigame0[0][0][0][0][n].v.ob[2] - func_800AEAC0(D_80103748_UnusedMinigame0) * D_80103754_UnusedMinigame0;
        }
    }
    func_800FFA64_UnusedMinigame0();
    D_80103748_UnusedMinigame0 = (D_80103748_UnusedMinigame0 + 90) % 360;
    D_80103754_UnusedMinigame0 = D_80103754_UnusedMinigame0 - 0.1;
    if (D_80103754_UnusedMinigame0 < 0.0f) {
        D_80103754_UnusedMinigame0 = 1.6f;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_UnusedMinigame0/105EA0", func_80100850_UnusedMinigame0);
#endif
u32 func_80102568_UnusedMinigame0(u32 n) {
    D_80103708_UnusedMinigame0 = D_80103708_UnusedMinigame0 * 0x41C64E6D + 0x3039;
    return ((D_80103708_UnusedMinigame0 >> 16) + ((D_80103708_UnusedMinigame0 << 16) >> 31)) % n;
}
void func_801025B8_UnusedMinigame0(u8 (*out)[6]) {
    UM0Tile* t;
    s32 i;
    s32 j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 6; j++) {
            t = D_80108B88_UnusedMinigame0[i][j];
            if (t == NULL) {
                out[i][j] = 0;
            } else {
                out[i][j] = (u8)t->color + 1;
            }
        }
    }
}
// register allocation (masked 0)
#ifdef NON_MATCHING
s32 func_80102634_UnusedMinigame0(u8 (*grid)[6], s32 col, s32 row) {
    UM0Cell* c;
    UM0Cell* n;
    u32 nc;
    u32 nr;
    s32 i;
    s32 j;
    s32 k;
    s32 count;

    for (j = 0; j < 6; j++) {
        for (i = 0; i < 8; i++) {
            c = &D_8010B150_UnusedMinigame0[i][j];
            if ((c->color = grid[i][j] & 0x7F) != 0) {
                c->done = 0;
                c->seen = 0;
            } else {
                c->done = 1;
                c->seen = 1;
            }
            c->shiftRows = 0;
            c->shiftCols = 0;
            grid[i][j] = 0;
        }
    }
    c = &D_8010B150_UnusedMinigame0[col][row];
    c->seen = 1;
    for (i = 0; i < 4; i++) {
        nc = col + D_80103758_UnusedMinigame0[i][0];
        if (nc < 8) {
            nr = row + D_80103758_UnusedMinigame0[i][1];
            if (nr < 6) {
                n = &D_8010B150_UnusedMinigame0[nc][nr];
                /* done and seen both clear (one word test) */
                if (*(s32*)&n->done == 0) {
                    n->seen = 1;
                    if (c->color == n->color) {
                        func_8010298C_UnusedMinigame0(col + D_80103758_UnusedMinigame0[i][0],
                                                      row + D_80103758_UnusedMinigame0[i][1]);
                        c->done = 1;
                    }
                }
            }
        }
    }
    if (c->done != 0) {
        for (i = row - 1; i >= 0; i--) {
            n = &D_8010B150_UnusedMinigame0[col][i];
            n->shiftRows++;
        }
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 6; j++) {
                if (D_8010B150_UnusedMinigame0[i][j].done == 0) {
                    break;
                }
            }
            if (j == 6) {
                for (k = i; k < 8; k++) {
                    for (j = 0; j < 6; j++) {
                        n = &D_8010B150_UnusedMinigame0[k][j];
                        n->shiftCols++;
                    }
                }
            }
        }
    }
    count = 0;
    for (j = 0; j < 6; j++) {
        for (i = 0; i < 8; i++) {
            c = &D_8010B150_UnusedMinigame0[i][j];
            if (c->done == 0) {
                grid[i - c->shiftCols][j + c->shiftRows] = (u8)c->color;
                count++;
            }
        }
    }
    return count;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_UnusedMinigame0/105EA0", func_80102634_UnusedMinigame0);
#endif
// decomp-permuter
void func_8010298C_UnusedMinigame0(s32 col, s32 row)
{
  UM0Cell *c0;
  UM0Cell *n;
  u32 nc;
  UM0Cell *new_var;
  u32 nr;
  s32 i;
  s32 j;
  c0 = &D_8010B150_UnusedMinigame0[col][row];
  c0->done = 1;
  for (j = row - 1; j >= 0; j--)
  {
    n = &D_8010B150_UnusedMinigame0[col][j];
    n->shiftRows++;
  }

  for (i = 0; i < 4; i++)
  {
    nc = col + D_80103768_UnusedMinigame0[i][0];
    if (nc < 8)
    {
      nr = row + D_80103768_UnusedMinigame0[i][1];
      if (nr < 6)
      {
        n = (new_var = &D_8010B150_UnusedMinigame0[nc][nr]);
        if ((*((s32 *) (&new_var->done))) == 0)
        {
          n->seen = 1;
          if (c0->color == new_var->color)
          {
            func_8010298C_UnusedMinigame0(col + D_80103768_UnusedMinigame0[i][0], row + D_80103768_UnusedMinigame0[i][1]);
          }
        }
      }
    }
  }

}
