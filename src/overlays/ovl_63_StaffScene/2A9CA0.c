#include "StaffScene.h"
#include "PR/gu.h"

/* Turns the camera towards m: within dist of it (mode >= 3 also pulls the camera in and lifts it by
   rise), yaw by at most maxYaw a frame, pitch by at most 1 degree */



extern char* D_800FD2E0_StaffScene;
extern StaffCamera D_800FD2E4_StaffScene;
extern StaffCtl D_800FD304_StaffScene;
extern StaffCtl D_800FD308_StaffScene;
extern char* D_800FD30C_StaffScene;
extern StaffCamera D_800FD310_StaffScene;
extern StaffCtl D_800FD330_StaffScene;
extern StaffCtl D_800FD334_StaffScene;
extern char* D_800FD338_StaffScene;
extern Vec3f D_800FD33C_StaffScene;
extern Vec3f D_800FD348_StaffScene;
extern Vec3f D_800FD354_StaffScene;
extern Vec3f D_800FD360_StaffScene;
extern Vec3f D_800FD36C_StaffScene;
extern Vec3f D_800FD378_StaffScene;
extern Vec3f D_800FD9C0_StaffScene;
extern StaffCamera D_800FD954_StaffScene;
extern Vec3f D_800FD974_StaffScene;
extern StaffCtl D_800FD980_StaffScene;
extern StaffCtl D_800FD984_StaffScene;
extern StaffCtl D_800FD988_StaffScene;
extern StaffCtl D_800FD98C_StaffScene;
extern StaffCtl D_800FD990_StaffScene;
extern Vec3f D_800FD9CC_StaffScene;
extern Vec3f D_800FD9D8_StaffScene;
extern Vec3f D_800FD9E4_StaffScene[3];
extern Vec3f D_800FDA10_StaffScene[160];
extern f32 D_800FD390_StaffScene;

extern StaffScaleKey D_800FD394_StaffScene[];


StaffModel* func_800FC998_StaffScene(void);
void func_800FCA8C_StaffScene(StaffModel*);
StaffSparkle* func_800FD0F0_StaffScene(StaffModel*, s16);
void func_800FD170_StaffScene(StaffSparkle*);

void* func_80014614(s32);
s32 func_800141FC(s16);
s32 func_8004F628(s32, u16, s16, s16);
void func_8004F898(s32, u8, u8, u8);
void func_8004F7C0(s32, f32, f32);
void func_8004F584(s32);

void func_800F6910_StaffScene(void);
void func_800F6C7C_StaffScene(StaffCtl*);
void func_800F7AC0_StaffScene(void);
void func_800F7F54_StaffScene(void);
void func_800F8128_StaffScene(void);
void func_800F91E0_StaffScene(void);
void func_800F9C38_StaffScene(void);
extern f32 D_800FE190_StaffScene[3]; /* fov, near, far */
extern f32 D_800FE19C_StaffScene;    /* the fov last applied */

/* Halfword i of an N64-layout Mtx (65770.c's MTX_HALF) */
#define MTX_HALF(m, i) (((u16*)(m))[i])

void func_800FC554_StaffScene(StaffCamera*);
void func_800FC5B0_StaffScene(omObjData*);
void func_800FC864_StaffScene(void);
s16 func_8006D93C(u8*);
void func_8005B838(void*);
void* func_8005B7E8(s32);
void func_8002019C(s16);
void func_800FA3D8_StaffScene(void);
void func_800FAA4C_StaffScene(void);
void func_800FAD30_StaffScene(void);
void func_800FB1A0_StaffScene(void);
void func_800FBE80_StaffScene(void);
s16 func_80038A9C(unk2C0C0StructC0*, void*, s32, char*);
void func_80025930(s16, s32, s32);
void func_80025AD4(s16);
void func_80039ACC(s16);
void func_800FB5F0_StaffScene(StaffModel*, Vec3f*, s32);
void func_800FBCF4_StaffScene(StaffModel*, Vec3f*, s32, s32);
void func_8002854C(void);
f32 func_80025D40(s16);
void func_800FC624_StaffScene(s16*, s16, f32, f32, f32);
void func_800F8380_StaffScene(void);
void func_800F8894_StaffScene(void);
void func_800F94E0_StaffScene(void);
s32 LoadFormBinary(void*, u32);
void func_80025BB8(s16, s16);
void func_800FB6A8_StaffScene(StaffModel*, f32, s32, f32, f32);
void func_800FBB88_StaffScene(StaffModel*, s32*, s32);
void func_800FCAF4_StaffScene(void);
u32 func_800FD1D8_StaffScene(u32);
u32 func_800FD2AC_StaffScene(void);
extern u32 D_800FE1A0_StaffScene;


/* .data (in address order; 2A9970.c has none) */
char* D_800FD2E0_StaffScene = "MARIOPARTY STAFF";
StaffCamera D_800FD2E4_StaffScene = { { 0.0f, 300.0f, -500.0f }, { 0.0f, 0.0f, 0.0f }, 1580.0f, 45.0f };
StaffCtl D_800FD304_StaffScene = { 0, 0 };
StaffCtl D_800FD308_StaffScene = { 0, 0 };
char* D_800FD30C_StaffScene = "WE ARE THE SUPER STAR\xC4";
StaffCamera D_800FD310_StaffScene = { { 0.0f, 340.0f, -450.0f }, { 0.0f, 0.0f, 0.0f }, 1580.0f, 45.0f };
StaffCtl D_800FD330_StaffScene = { 0, 0 };
StaffCtl D_800FD334_StaffScene = { 0, 0 };
char* D_800FD338_StaffScene = "THE END";
Vec3f D_800FD33C_StaffScene = { 0.0f, 340.0f, 800.0f };
Vec3f D_800FD348_StaffScene = { 0.0f, 380.0f, -200.0f };
Vec3f D_800FD354_StaffScene = { 0.0f, 300.0f, 1000.0f };
Vec3f D_800FD360_StaffScene = { 0.0f, 500.0f, 0.0f };
Vec3f D_800FD36C_StaffScene = { 0.0f, 340.0f, 1000.0f };
Vec3f D_800FD378_StaffScene = { -1700.0f, 2100.0f, -8200.0f };
Vec3f D_800FD384_StaffScene = { 0.0f, 0.0f, 0.0f };
f32 D_800FD390_StaffScene = 0.0f;
StaffScaleKey D_800FD394_StaffScene[6] = { { 1.1f, 2 }, { 0.9f, 3 }, { 1.05f, 4 }, { 0.98f, 4 }, { 1.0f, 2 }, { 0.0f, 0 } };
/* the credits: each entry's names (message ids), and how many names each page shows */
s16 D_800FD3C4_StaffScene[2] = { 0x3dd };
s16 D_800FD3C8_StaffScene[2] = { 0x3e1 };
s16 D_800FD3CC_StaffScene[4] = { 0x3e2, 0x3de, 0x3df };
s16 D_800FD3D4_StaffScene[2] = { 0x3e0 };
s16 D_800FD3D8_StaffScene[4] = { 0x3e3, 0x3e4, 0x3e5 };
s16 D_800FD3E0_StaffScene[10] = { 0x3e6, 0x3e7, 0x3e8, 0x3e9, 0x3ea, 0x3eb, 0x3ec, 0x3ed, 0x3ee };
s16 D_800FD3F4_StaffScene[2] = { 0x3ef };
s16 D_800FD3F8_StaffScene[4] = { 0x3f0, 0x3f1, 0x3f2 };
s16 D_800FD400_StaffScene[16] = { 0x3f3, 0x3f4, 0x3f5, 0x3f6, 0x3f7, 0x3f8, 0x3f9, 0x3fa, 0x3fb, 0x3fc, 0x3fd, 0x3fe, 0x3ff, 0x400, 0x401, 0x402 };
s16 D_800FD420_StaffScene[2] = { 0x403, 0x404 };
s16 D_800FD424_StaffScene[2] = { 0x405 };
s16 D_800FD428_StaffScene[2] = { 0x406 };
s16 D_800FD42C_StaffScene[2] = { 0x407 };
s16 D_800FD430_StaffScene[2] = { 0x408 };
s16 D_800FD434_StaffScene[2] = { 0x409, 0x40a };
s16 D_800FD438_StaffScene[2] = { 0x40b, 0x40c };
s16 D_800FD43C_StaffScene[4] = { 0x40d, 0x40e, 0x40f, 0x410 };
s16 D_800FD444_StaffScene[2] = { 0x411, 0x412 };
s16 D_800FD448_StaffScene[4] = { 0x413, 0x414, 0x415 };
s16 D_800FD450_StaffScene[2] = { 0x416 };
s16 D_800FD454_StaffScene[2] = { 0x417 };
s16 D_800FD458_StaffScene[2] = { 0x418 };
s16 D_800FD45C_StaffScene[14] = { 0x419, 0x41a, 0x41b, 0x41c, 0x41d, 0x41e, 0x41f, 0x420, 0x421, 0x422, 0x423, 0x424, 0x431 };
s16 D_800FD478_StaffScene[2] = { 0x425 };
s16 D_800FD47C_StaffScene[2] = { 0x426 };
s16 D_800FD480_StaffScene[4] = { 0x427, 0x428, 0x429 };
s16 D_800FD488_StaffScene[2] = { 0x42a, 0x42b };
s16 D_800FD48C_StaffScene[2] = { 0x42c, 0x42d };
s16 D_800FD490_StaffScene[4] = { 0x42f, 0x430, 0x42e };
s16 D_800FD498_StaffScene[6] = { 0x4, 0x4, 0x4, 0x4, 0x4 };
s16 D_800FD4A4_StaffScene[4] = { 0x3, 0x3, 0x3 };
s16 D_800FD4AC_StaffScene[6] = { 0x2, 0x3, 0x3, 0x4, 0x4 };
s16 D_800FD4B8_StaffScene[4] = { 0x4, 0x3, 0x2, 0x4 };
StaffCredit D_800FD4C0_StaffScene[30] = {
    { D_800FD3C4_StaffScene, 1, D_800FD498_StaffScene, 0x512 },
    { D_800FD3C8_StaffScene, 1, D_800FD498_StaffScene, 0x52D },
    { D_800FD3CC_StaffScene, 3, D_800FD498_StaffScene, 0x513 },
    { D_800FD3D4_StaffScene, 1, D_800FD498_StaffScene, 0x514 },
    { D_800FD3D8_StaffScene, 3, D_800FD498_StaffScene, 0x515 },
    { D_800FD3E0_StaffScene, 9, D_800FD4A4_StaffScene, 0x516 },
    { D_800FD3F4_StaffScene, 1, D_800FD498_StaffScene, 0x517 },
    { D_800FD3F8_StaffScene, 3, D_800FD498_StaffScene, 0x518 },
    { D_800FD400_StaffScene, 16, D_800FD4AC_StaffScene, 0x519 },
    { D_800FD420_StaffScene, 2, D_800FD498_StaffScene, 0x51A },
    { D_800FD424_StaffScene, 1, D_800FD498_StaffScene, 0x51B },
    { D_800FD428_StaffScene, 1, D_800FD498_StaffScene, 0x51C },
    { D_800FD42C_StaffScene, 1, D_800FD498_StaffScene, 0x51D },
    { D_800FD430_StaffScene, 1, D_800FD498_StaffScene, 0x51E },
    { D_800FD434_StaffScene, 2, D_800FD498_StaffScene, 0x51F },
    { D_800FD438_StaffScene, 2, D_800FD498_StaffScene, 0x520 },
    { D_800FD490_StaffScene, 3, D_800FD498_StaffScene, 0x52E },
    { D_800FD43C_StaffScene, 4, D_800FD498_StaffScene, 0x521 },
    { D_800FD444_StaffScene, 2, D_800FD498_StaffScene, 0x522 },
    { D_800FD448_StaffScene, 3, D_800FD498_StaffScene, 0x523 },
    { D_800FD450_StaffScene, 1, D_800FD498_StaffScene, 0x524 },
    { D_800FD454_StaffScene, 1, D_800FD498_StaffScene, 0x525 },
    { D_800FD458_StaffScene, 1, D_800FD498_StaffScene, 0x526 },
    { D_800FD45C_StaffScene, 13, D_800FD4B8_StaffScene, 0x527 },
    { D_800FD478_StaffScene, 1, D_800FD498_StaffScene, 0x528 },
    { D_800FD47C_StaffScene, 1, D_800FD498_StaffScene, 0x529 },
    { D_800FD480_StaffScene, 3, D_800FD498_StaffScene, 0x52A },
    { D_800FD488_StaffScene, 2, D_800FD498_StaffScene, 0x52B },
    { D_800FD48C_StaffScene, 2, D_800FD498_StaffScene, 0x52C },
    { NULL, 0, NULL, 0 },
};
StaffObjDef D_800FD6A0_StaffScene[29] = {
    { 0, 0x2D, 0.0f, 0x0001009F, 0x0001000F },
    { 0, 0x2D, 0.0f, 0x0002009F, 0x0002000F },
    { 0, 0x2D, 0.0f, 0x0006009F, 0x0006000F },
    { 0, 0x2D, 0.0f, 0x0003009F, 0x0003000F },
    { 0, 0x2D, 0.0f, 0x0004009F, 0x0004000F },
    { 0, 0x2D, 0.0f, 0x0005009F, 0x0005000F },
    { 1, 0x45, 0.0f, 0x00070000, 0x00070004 },
    { 0, 0x2D, 0.0f, 0x000A0072, 0xFFFFFFFF },
    { 0, 0x45, 0.0f, 0x000A00F4, 0x000A0073 },
    { 0, 0x2D, 80.0f, 0x000F0002, 0xFFFFFFFF },
    { 0, 0x3C, 0.0f, 0x000A0068, 0x000A006A },
    { 0, 0x2D, 0.0f, 0x000F0004, 0xFFFFFFFF },
    { 0, 0x2D, 0.0f, 0x000F0003, 0xFFFFFFFF },
    { 2, 0x2D, 0.0f, 0x000F0003, 0xFFFFFFFF },
    { 0, 0x2D, 0.0f, 0x00090053, 0x00090055 },
    { 0, 0x2D, 0.0f, 0x000F0005, 0xFFFFFFFF },
    { 4, 0x4B, 0.0f, 0x00000069, 0x00000068 },
    { 0, 0x2D, 0.0f, 0x000A009E, 0xFFFFFFFF },
    { 0, 0x2D, 0.0f, 0x00000049, 0x0000004A },
    { 0, 0x2D, 0.0f, 0x0000004F, 0xFFFFFFFF },
    { 1, 0x2D, 10.0f, 0x000A00AF, 0xFFFFFFFF },
    { 0, 0x2D, 0.0f, 0x000A00CA, 0xFFFFFFFF },
    { 0, 0x2D, 0.0f, 0x000A00C9, 0xFFFFFFFF },
    { 0, 0x2D, 0.0f, 0x0000006A, 0xFFFFFFFF },
    { 0, 0x2D, 0.0f, 0x000A00CF, 0xFFFFFFFF },
    { 1, 0x2D, 110.0f, 0x000A00D4, 0xFFFFFFFF },
    { 0, 0x45, 0.0f, 0x000A00E6, 0x000A00E8 },
    { 0, 0x2D, 80.0f, 0x000A00D7, 0xFFFFFFFF },
    { -1, 0x0, 0.0f, 0x00000000, 0xFFFFFFFF },
};
Vec3f D_800FD870_StaffScene[12] = {
    { 35.0f, 95.0f, 310.0f }, { -40.0f, 95.0f, 305.0f }, { 125.0f, 95.0f, 375.0f },
    { 200.0f, 55.0f, 380.0f }, { -135.0f, 90.0f, 300.0f }, { -195.0f, 60.0f, 355.0f },
    { 255.0f, 125.0f, 0.0f }, { 340.0f, 90.0f, -10.0f }, { -260.0f, 235.0f, 95.0f },
    { 0.0f, 125.0f, -295.0f }, { -135.0f, 125.0f, -70.0f }, { 120.0f, 130.0f, 80.0f },
};
s16 D_800FD900_StaffScene[16] = { 0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x9, 0xa, 0x8, 0xb };
void (*D_800FD920_StaffScene[])(void) = { func_800F9F70_StaffScene, func_800FA4F4_StaffScene, func_800F6AA0_StaffScene, func_800F6F00_StaffScene, NULL };
StaffCamera D_800FD934_StaffScene = { { 0.0f, 210.0f, -905.0f }, { -4.0f, 0.0f, 0.0f }, 1580.0f, 45.0f };
StaffCamera D_800FD954_StaffScene = { { -580.0f, 680.0f, 1450.0f }, { -20.0f, 15.0f, 0.0f }, 200.0f, 45.0f };
Vec3f D_800FD974_StaffScene = { 5.0f, 980.0f, 2430.0f };
StaffCtl D_800FD980_StaffScene = { 0, 0 };
StaffCtl D_800FD984_StaffScene = { 0, 0 };
StaffCtl D_800FD988_StaffScene = { 0, 0 };
StaffCtl D_800FD98C_StaffScene = { 0, 0 };
StaffCtl D_800FD990_StaffScene = { 0, 0 };
StaffXY D_800FD994_StaffScene[8] = { { -80, 0x0 }, { 0x50, 0x0 }, { -80, 0x80 }, { 0x50, 0x80 }, { -80, 0x100 }, { 0x50, 0x100 }, { -80, 0x180 }, { 0x50, 0x180 } };
Vec3f D_800FD9B4_StaffScene = { 0.0f, 2000.0f, 0.0f }; /* the snow centre */
Vec3f D_800FD9C0_StaffScene = { -1160.0f, 145.0f, 275.0f };
Vec3f D_800FD9CC_StaffScene = { -940.0f, 145.0f, 580.0f };
Vec3f D_800FD9D8_StaffScene = { 0.0f, 620.0f, 0.0f };
Vec3f D_800FD9E4_StaffScene[3] = { { 0.0f, 2000.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } };
f32 D_800FDA08_StaffScene = 0.0f;
f32 D_800FDA0C_StaffScene = 0.0f;
/* the camera path of the last scene */
Vec3f D_800FDA10_StaffScene[160] = {
    { -940.00006f, 145.0f, 580.00006f }, { -933.383f, 151.68309f, 594.67865f }, { -926.10254f, 159.0376f, 610.83276f },
    { -918.1716f, 167.05272f, 628.43976f }, { -909.60394f, 175.71754f, 647.47736f }, { -900.4147f, 185.02122f, 667.924f },
    { -890.6204f, 194.95232f, 689.75757f }, { -880.23895f, 205.49951f, 712.95667f }, { -869.28894f, 216.65202f, 737.50214f },
    { -857.7896f, 228.39989f, 763.37695f }, { -845.7653f, 240.72888f, 790.5557f }, { -833.236f, 253.6306f, 819.0261f },
    { -820.2262f, 267.09296f, 848.7685f }, { -806.76086f, 281.104f, 879.76373f }, { -792.8655f, 295.652f, 911.99347f },
    { -778.5649f, 310.72556f, 945.44037f }, { -763.884f, 326.3136f, 980.08734f }, { -748.8469f, 342.40524f, 1015.9181f },
    { -733.4771f, 358.98972f, 1052.9156f }, { -717.80225f, 376.05072f, 1091.0505f }, { -701.8408f, 393.58072f, 1130.3125f },
    { -685.6124f, 411.56998f, 1170.685f }, { -669.14215f, 430.00104f, 1212.1344f }, { -652.445f, 448.86612f, 1254.6475f },
    { -635.5363f, 468.1561f, 1298.2075f }, { -618.4356f, 487.85522f, 1342.7823f }, { -601.15765f, 507.95184f, 1388.3477f },
    { -583.7127f, 528.4383f, 1434.8884f }, { -566.08923f, 549.3024f, 1482.3732f }, { -548.15125f, 570.5227f, 1530.722f },
    { -529.72345f, 592.0761f, 1579.8435f }, { -510.62683f, 613.9396f, 1629.6466f }, { -490.67093f, 636.0888f, 1680.036f },
    { -469.64978f, 658.493f, 1730.8986f }, { -447.3315f, 681.11475f, 1782.1008f }, { -423.44434f, 703.9115f, 1833.4899f },
    { -397.6774f, 726.8178f, 1884.8505f }, { -369.64078f, 749.7612f, 1935.9375f }, { -338.8789f, 772.62317f, 1986.3815f },
    { -304.8267f, 795.2418f, 2035.6879f }, { -266.80643f, 817.37366f, 2083.1436f }, { -224.01695f, 838.65875f, 2127.729f },
    { -175.66139f, 858.53485f, 2167.9304f }, { -121.14273f, 876.20435f, 2201.692f }, { -60.56759f, 890.6486f, 2226.5366f },
    { 4.79126f, 900.8865f, 2240.2786f }, { 74.61189f, 906.494f, 2241.9292f }, { 148.3109f, 907.226f, 2230.9832f },
    { 223.75671f, 903.3038f, 2208.3176f }, { 299.97278f, 895.59937f, 2176.1309f }, { 376.711f, 884.8455f, 2136.1624f },
    { 453.93555f, 871.561f, 2089.6055f }, { 531.71136f, 856.1126f, 2037.2705f }, { 610.08185f, 838.7783f, 1979.7538f },
    { 689.08386f, 819.77496f, 1917.4993f }, { 768.7382f, 799.28f, 1850.851f }, { 849.0504f, 777.44574f, 1780.0831f },
    { 930.00903f, 754.4087f, 1705.4207f }, { 1011.58936f, 730.2966f, 1627.0514f }, { 1093.7533f, 705.2337f, 1545.133f },
    { 1176.4491f, 679.34717f, 1459.8002f }, { 1259.6173f, 652.7698f, 1371.158f }, { 1343.1727f, 625.6528f, 1279.3003f },
    { 1427.0227f, 598.1685f, 1184.2817f }, { 1511.0414f, 570.53345f, 1086.1324f }, { 1595.0825f, 543.02765f, 984.8116f },
    { 1678.8809f, 516.0595f, 880.25366f }, { 1761.9703f, 490.03702f, 772.20667f }, { 1843.6615f, 465.36615f, 660.23206f },
    { 1922.9468f, 442.6008f, 543.8644f }, { 1998.4977f, 422.45633f, 422.48352f }, { 2068.5103f, 405.85706f, 295.43008f },
    { 2130.6638f, 393.91226f, 162.18185f }, { 2182.3657f, 387.73492f, 22.664335f }, { 2221.4988f, 388.0226f, -122.34207f },
    { 2247.5388f, 394.57272f, -271.32153f }, { 2259.918f, 407.00256f, -422.73285f }, { 2255.6917f, 425.72858f, -574.8623f },
    { 2231.635f, 451.14066f, -724.963f }, { 2185.2354f, 483.24673f, -869.11066f }, { 2115.7961f, 521.4069f, -1002.768f },
    { 2025.0885f, 564.3253f, -1122.0358f }, { 1916.8208f, 610.4015f, -1224.8744f }, { 1795.7374f, 657.8859f, -1312.0234f },
    { 1665.7639f, 705.288f, -1385.6526f }, { 1529.3202f, 751.6347f, -1447.3322f }, { 1387.977f, 796.2146f, -1498.07f },
    { 1242.8572f, 838.42645f, -1538.4462f }, { 1094.8464f, 877.70233f, -1568.7196f }, { 944.7139f, 913.464f, -1588.8958f },
    { 793.22314f, 945.0882f, -1598.7709f }, { 641.1882f, 971.8919f, -1597.9741f }, { 489.56143f, 993.1932f, -1586.0693f },
    { 339.45264f, 1009.04694f, -1563.2256f }, { 191.9186f, 1019.9735f, -1529.9596f }, { 47.938156f, 1026.476f, -1486.7003f },
    { -91.54808f, 1029.0269f, -1433.759f }, { -225.54367f, 1028.069f, -1371.33f }, { -352.9515f, 1024.0239f, -1299.482f },
    { -472.46887f, 1017.3053f, -1218.1783f }, { -582.477f, 1008.3406f, -1127.3198f }, { -680.9387f, 997.6008f, -1026.8171f },
    { -765.2754f, 985.6371f, -916.83685f }, { -833.3058f, 972.8454f, -798.5782f }, { -883.9584f, 959.3894f, -674.3521f },
    { -916.7706f, 945.43567f, -546.72034f }, { -931.8184f, 931.1571f, -418.29095f }, { -929.6457f, 916.7249f, -291.57645f },
    { -911.18134f, 902.3041f, -168.8993f }, { -877.66974f, 888.0506f, -52.32994f }, { -830.6267f, 874.1133f, 56.34018f },
    { -771.7945f, 860.62866f, 155.66895f }, { -703.3255f, 847.69354f, 244.77061f }, { -628.0448f, 835.27795f, 323.85733f },
    { -548.30347f, 823.30597f, 393.48984f }, { -465.8444f, 811.6939f, 454.23267f }, { -381.99075f, 800.35986f, 506.55093f },
    { -297.7304f, 789.21906f, 550.8025f }, { -213.73738f, 778.1722f, 587.2323f }, { -130.54016f, 767.1133f, 615.8762f },
    { -48.617096f, 755.9263f, 636.50916f }, { 31.500395f, 744.48f, 648.5702f }, { 109.03938f, 732.63f, 651.0506f },
    { 182.716f, 720.22974f, 642.3853f }, { 250.38707f, 707.3288f, 621.384f }, { 309.96143f, 694.3454f, 589.22577f },
    { 360.16083f, 681.7403f, 548.39886f }, { 400.7695f, 669.85406f, 501.72983f }, { 432.31216f, 658.88086f, 451.72415f },
    { 455.62125f, 648.90125f, 400.29785f }, { 471.51535f, 639.9344f, 348.82126f }, { 480.62805f, 631.9816f, 298.29117f },
    { 483.3342f, 625.05225f, 249.48604f }, { 479.69186f, 619.1895f, 203.14288f }, { 469.39194f, 614.5054f, 160.22133f },
    { 451.88608f, 611.20355f, 122.18942f }, { 427.823f, 609.4175f, 90.66006f }, { 399.39655f, 609.0034f, 66.19746f },
    { 369.03067f, 609.6203f, 48.0503f }, { 338.45978f, 610.9141f, 34.851444f }, { 308.67197f, 612.6134f, 25.29704f },
    { 280.16248f, 614.534f, 18.370886f }, { 253.153f, 616.5561f, 13.335695f }, { 227.7324f, 618.6014f, 9.66851f },
    { 203.91176f, 620.6193f, 6.995985f }, { 181.66672f, 622.57666f, 5.050135f }, { 160.94734f, 624.4527f, 3.63631f },
    { 141.69945f, 626.2339f, 2.612505f }, { 123.85422f, 627.9132f, 1.87381f }, { 107.34596f, 629.48694f, 1.342995f },
    { 92.10377f, 630.9546f, 0.96282f }, { 78.055115f, 632.31775f, 0.69106f }, { 65.1292f, 633.5793f, 0.496605f },
    { 53.253784f, 634.7435f, 0.356605f }, { 42.3555f, 635.81537f, 0.25466f }, { 32.365f, 636.8003f, 0.178745f },
    { 23.206175f, 637.7048f, 0.12046f }, { 14.80736f, 638.5351f, 0.073825f }, { 7.095335f, 639.298f, 0.03455f },
    { 0.0f, 640.0f, 0.0f },
};
f32 D_800FE190_StaffScene[3] = { 45.0f, 80.0f, 8000.0f }; /* fov, near, far */
f32 D_800FE19C_StaffScene = 0.0f; /* the fov last applied */
u32 D_800FE1A0_StaffScene = 0; /* func_800FD2AC's seed */
const char D_800FE1E4_StaffScene[] = ""; /* unreferenced (.rodata after "THE END") */

void func_800F6910_StaffScene(void) {
    unkCommonStruct0 mes;
    s16 id;
    s32 len;
    s32 i;
    s32 a;
    s32 t;

    HuPrcSleep(30);
    id = GMesFontMesCreate(&mes, D_800FD2E0_StaffScene, 0, -1, -1);
    func_80066DC4(mes.unk_14[id], 0, 160, 120);
    t = 0;
    len = strlen(D_800FD2E0_StaffScene) + 1;
    for (a = 0; a < 256; a += 3, t++) {
        for (i = 1; i < len; i++) {
            func_8006752C(mes.unk_14[id], i, a);
        }
        if (t == 45) {
            func_80060128(5);
        }
        HuPrcSleep(0);
    }
    HuPrcSleep(30);
    HuPrcSleep(30);
    for (a = 255; a > 0; a -= 3) {
        for (i = 1; i < len; i++) {
            func_8006752C(mes.unk_14[id], i, a);
        }
        HuPrcSleep(0);
    }
    func_80077044(&mes);
    HuPrcSleep(2);
}
void func_800F6AA0_StaffScene(void) {
    Process* p1;
    Process* p2;

    func_8002578C(0);
    func_800FC554_StaffScene(&D_800FD2E4_StaffScene);
    p1 = omAddPrcObj(func_800F7AC0_StaffScene, 0x3F00, 0x1000, 0);
    omPrcSetStatBit(p1, 0xA0);
    p1->user_data = &D_800FD304_StaffScene;
    p2 = omAddPrcObj(func_800F8128_StaffScene, 0x3F00, 0x1000, 0);
    omPrcSetStatBit(p2, 0xA0);
    p2->user_data = &D_800FD308_StaffScene;
    SetFadeInTypeAndTime(0, 3);
    HuPrcSleep(3);
    D_800FD304_StaffScene.cmd = 4;
    HuPrcVSleep();
    while (D_800FD304_StaffScene.stat != 3) {
        HuPrcVSleep();
    }
    func_800F6910_StaffScene();
    func_800F91E0_StaffScene();
    D_800FD304_StaffScene.cmd = 5;
    while (D_800FD304_StaffScene.stat != 7) {
        HuPrcVSleep();
    }
    func_80072724(0xFF, 0xFF, 0xE0);
    func_800726AC(0, 3);
    HuPrcSleep(3);
    D_800FD304_StaffScene.cmd = 1;
    D_800FD308_StaffScene.cmd = 1;
    while (D_800FD304_StaffScene.stat >= 0) {
        HuPrcSleep(0);
    }
    EndProcess(p1);
    while (D_800FD308_StaffScene.stat >= 0) {
        HuPrcSleep(0);
    }
    EndProcess(p2);
    HuPrcSleep(0);
}
void func_800F6C7C_StaffScene(StaffCtl* ctl) {
    unkCommonStruct0 mes;
    s16 id;
    s32 len;
    s16* alpha;
    u16* p;
    s32 i;
    s32 a;
    s32 first;
    s32 v;

    HuPrcSleep(15);
    id = GMesFontMesCreate(&mes, D_800FD30C_StaffScene, 1, -1, -1);
    func_80066DC4(mes.unk_14[id], 0, 160, 40);
    a = 9;
    len = strlen(D_800FD30C_StaffScene) + 1;
    alpha = func_80023684(len * 2, 0x7918);
    for (i = 1, p = (u16*)alpha; i < len; i++, p++, a -= 18) {
        func_80067354(mes.unk_14[id], i, 0.56f, 1.5f);
        func_8006752C(mes.unk_14[id], i, 0);
        *p = a;
    }
    first = 1;
    do {
        a = 0;
        p = (u16*)alpha;
        if (first != 0 && *alpha > 0x80) {
            first = 0;
            PlaySound(0x86);
        }
        for (i = 1; i < len; i++, p++) {
            v = *p;
            if (v - 1 < 0x107U) {
                if ((s16)v >= 0x100) {
                    *p = 0xFF;
                }
                func_8006752C(mes.unk_14[id], i, *p);
                a++;
            }
            *p += 9;
        }
        HuPrcSleep(0);
    } while (a != 0);
    ctl->cmd = 2;
    HuPrcSleep(30);
    for (a = 255; a > 0; a -= 9) {
        for (i = 1; i < len; i++) {
            func_8006752C(mes.unk_14[id], i, a);
        }
        HuPrcSleep(0);
    }
    func_80077044(&mes);
    func_80023728(alpha);
    HuPrcSleep(0);
}
// register allocation (masked 2: two locals swap registers)
#ifdef NON_MATCHING
void func_800F6F00_StaffScene(void) {
    unkCommonStruct0 mes;
    s16 tex;
    s16 win;
    Process* p1;
    Process* p2;
    f32 f;
    s16 model;
    s16 spr;
    s16 id;
    s16 i;
    s16 j;
    s16 x;
    s16 y;
    s32 len;
    s32 a;
    s32 n;
    s16 skip;
    void* file;

    func_8002578C(0);
    n = 0;
    func_800FC554_StaffScene(&D_800FD310_StaffScene);
    file = func_80014614(0xF0006);
    tex = func_800678A4(file);
    FreeTemp(file);
    win = func_80064EF4(6, 0);
    for (x = 80, j = 0; j < 2; j++, x += 160) {
        for (y = -64, i = 0; i < 3; y += 128, i++, n++) {
            func_80067208(win, n, tex, 0);
            func_800672B0(win, n, 0);
            func_800674BC(win, n, 0x5000);
            func_80067384(win, n, 0xFFFF);
            func_80066DC4(win, n, x, y);
        }
    }
    p1 = omAddPrcObj(func_800F9C38_StaffScene, 0x3F00, 0x1000, 0);
    omPrcSetStatBit(p1, 0xA0);
    p1->user_data = &D_800FD334_StaffScene;
    p2 = omAddPrcObj(func_800F7F54_StaffScene, 0x3F00, 0x1000, 0);
    omPrcSetStatBit(p2, 0xA0);
    p2->user_data = &D_800FD330_StaffScene;
    HuPrcVSleep();
    model = LoadFormFile(0xA00E0, 0x6B9);
    func_80025830(model, 7.0f, 7.0f, 7.0f);
    func_800257E4(model, 8.0f, 0.0f, 0.0f);
    func_80025F10(model, 1);
    SetFadeInTypeAndTime(0, 3);
    HuPrcSleep(1);
    D_800FD330_StaffScene.cmd = 4;
    HuPrcVSleep();
    while (D_800FD330_StaffScene.stat != 3) {
        HuPrcVSleep();
    }
    func_800F6C7C_StaffScene(&D_800FD334_StaffScene);
    D_800FD330_StaffScene.cmd = 5;
    HuPrcVSleep();
    while (D_800FD330_StaffScene.stat != 6) {
        HuPrcVSleep();
    }
    D_800FD334_StaffScene.cmd = 3;
    f = 0.0f;
    while (D_800FD330_StaffScene.stat != 7) {
        f -= 5.0f;
        func_80025798(model, 0.0f, f, 0.0f);
        HuPrcVSleep();
    }
    D_800FD330_StaffScene.cmd = 1;
    spr = func_8004F628(0xA0161, 10, 0x60, 0x38);
    func_8004F898(spr, 0xFF, 0xFF, 0xFF);
    PlaySound(0x4E);
    for (f = 0.0f; f < 2.0f; f += 0.5f) {
        func_8004F7C0(spr, f, f);
        HuPrcVSleep();
    }
    D_800FD334_StaffScene.cmd = -1;
    for (; f > 0.0f; f -= 0.5f) {
        func_8004F7C0(spr, f, f);
        HuPrcVSleep();
    }
    if (spr >= 0) {
        func_8004F584(spr);
    }
    HuPrcSleep(1);
    id = GMesFontMesCreate(&mes, D_800FD338_StaffScene, 1, -1, -1);
    func_80066DC4(mes.unk_14[id], 0, 160, 120);
    a = 0;
    len = strlen(D_800FD338_StaffScene) + 1;
    n = 1;
    for (; a < 0xFF; a += 4) {
        for (n = 1; n < len; n++) {
            func_8006752C(mes.unk_14[id], n, a);
        }
        HuPrcSleep(0);
    }
    for (n = 1; n < len; n++) {
        func_8006752C(mes.unk_14[id], n, 0xFF);
    }
    n = 1800;
    skip = 0;
    while (1) {
        for (a = 0; a < 4; a++) {
            if (func_800141FC(a) != 0 && (ContBtnTrg[a] & 0xF000)) {
                skip++;
                break;
            }
        }
        if (skip != 0) {
            break;
        }
        HuPrcSleep(0);
        skip = 0;
        if (--n == 0) {
            break;
        }
    }
    func_80072724(0, 0, 0);
    func_800726AC(0, 0x14);
    HuPrcSleep(0x14);
    func_800601D4(0x28);
    D_800FD330_StaffScene.cmd = 1;
    func_80064D38(win);
    func_80067704(tex);
    func_8002456C(model);
    func_80077044(&mes);
    while (D_800FD330_StaffScene.stat >= 0) {
        HuPrcSleep(0);
    }
    EndProcess(p2);
    while (D_800FD334_StaffScene.stat != -1) {
        HuPrcSleep(0);
    }
    EndProcess(p1);
    HuPrcSleep(0);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_63_StaffScene/2A9CA0", func_800F6F00_StaffScene);
#endif
s32 func_800F758C_StaffScene(StaffModel* m, s32 check) {
    f32* rz = &*rz;
    f32 v;

    rz = &m->rot.z;
    if (check != 0 && m->rot.z == 0.0f) {
        return 1;
    }
    v = func_800AEAC0(D_800FD390_StaffScene) * 30.0f;
    D_800FD390_StaffScene += 6.0f;
    if (D_800FD390_StaffScene > 360.0f) {
        D_800FD390_StaffScene -= 360.0f;
    }
    if (check != 0 && v * *rz < 0.0f) {
        D_800FD390_StaffScene = 0.0f;
        *rz = 0.0f;
        return 1;
    }
    *rz = v;
    return 0;
}
// register allocation (24.0f and 360.0f swap between FPR and GPR)
#ifdef NON_MATCHING
void func_800F7684_StaffScene(StaffModel* m) {
    StaffScaleKey* k;
    Vec3f* sc;
    s32 i;
    f32 d;
    f32 step;
    Vec3f* p;
    f32 tt;
    f32 vx;
    f32 ax;
    f32 dr;
    f32* ry;
    f32* rx;
    f32 vy;
    f32 ay;
    f32 vz;

    k = D_800FD394_StaffScene;
    sc = &m->scale;
    for (; k->frames != 0; k++) {
        step = (k->scale - sc->x) / k->frames;
        for (i = k->frames; i != 0; i--) {
            if (i == 1) {
                sc->x = k->scale;
                sc->y = k->scale;
                sc->z = k->scale;
            } else {
                sc->x = step + sc->x;
                sc->y = step + sc->y;
                sc->z = step + sc->z;
            }
            HuPrcVSleep();
        }
    }
    HuPrcSleep(6);
    p = &m->pos;
    tt = 3600.0f;
    d = D_800FD348_StaffScene.y - p->y;
    vy = -10.0f;
    ay = 2.0f * d / tt - 2.0f * vy / 60.0f;
    vz = (D_800FD348_StaffScene.z - p->z) / 60.0f;
    vx = -12.0f;
    ax = 0.4f;
    dr = 24.0f;
    ry = &m->rot.y;
    rx = &m->rot.x;
    i = 60;
    do {
        p->x = vx + p->x;
        vx += ax;
        p->y = vy + p->y;
        vy += ay;
        p->z = vz + p->z;
        *ry -= dr;
        if (*ry < 0.0f) {
            *ry += 360.0f;
        }
        if (i < 5) {
            *rx -= 4.0f;
        }
        i--;
        HuPrcVSleep();
    } while (i != 0);
    *p = D_800FD348_StaffScene;
    *ry = 0.0f;
    HuPrcSleep(2);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_63_StaffScene/2A9CA0", func_800F7684_StaffScene);
#endif
// register allocation only (masked 0): d and the folded 2*vy/60 constant swap $f2/$f0; tried d inline, no tt, tt*tt, 2*vy/60 via a local
#ifdef NON_MATCHING
void func_800F78F8_StaffScene(StaffModel* m) {
    f32* rx;
    s32 i;
    f32 d;
    Vec3f* p;
    f32 tt;
    f32* ry;
    f32 vx;
    f32 ax;
    f32 vy;
    f32 ay;
    f32 vz;

    HuPrcSleep(2);
    p = &m->pos;
    tt = 3600.0f;
    d = D_800FD354_StaffScene.y - p->y;
    vy = 5.0f;
    d = 2.0f * d / tt;
    ay = d - 2.0f * vy / 60.0f;
    vz = (D_800FD354_StaffScene.z - p->z) / 60.0f;
    vx = -12.0f;
    ax = 0.4f;
    ry = &m->rot.y;
    rx = &m->rot.x;
    for (i = 60; i != 0; i--) {
        if (*rx < 0.0f) {
            *rx += 4.0f;
            if (*rx > 0.0f) {
                *rx = 0.0f;
            }
        }
        p->x = vx + p->x;
        vx += ax;
        p->y = vy + p->y;
        vy += ay;
        p->z = vz + p->z;
        *ry = func_800B0CD8(0.0f - p->x, 500.0f - p->z);
        HuPrcVSleep();
    }
    *p = D_800FD354_StaffScene;
    *ry = 180.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_63_StaffScene/2A9CA0", func_800F78F8_StaffScene);
#endif
void func_800F7AC0_StaffScene(void) {
    StaffCtl* ctl;
    StaffModel* m;
    StaffSparkle* s;

    ctl = HuPrcCurrentGet()->user_data;
    m = func_800FC998_StaffScene();
    m->pos = D_800FD33C_StaffScene;
    s = func_800FD0F0_StaffScene(m, 0);
    s->cmd = 4;
    ctl->stat = 0;
    while (1) {
        HuPrcVSleep();
        if (ctl->cmd != 0) {
            ctl->stat = ctl->cmd;
            ctl->cmd = 0;
        }
        if (ctl->stat == 1) {
            break;
        }
        switch (ctl->stat) {
        case 0:
        case 1:
        case 2:
        case 7:
            break;
        case 4:
            m->rot.x = 0.0f;
            func_800F7684_StaffScene(m);
            ctl->stat = 3;
            break;
        case 3:
            m->rot.x = -20.0f;
            func_800F758C_StaffScene(m, 0);
            break;
        case 5:
            if (func_800F758C_StaffScene(m, 1) != 0) {
                ctl->stat = 6;
            }
            break;
        case 6:
            func_800F78F8_StaffScene(m);
            ctl->stat = 7;
            break;
        }
    }
    func_800FD170_StaffScene(s);
    func_800FCA8C_StaffScene(m);
    ctl->stat = -1;
    while (1) {
        HuPrcVSleep();
    }
}
// register allocation only (masked 0): d and the folded 2*vy/60 constant swap $f2/$f0; tried d inline, no tt, tt*tt, 2*vy/60 via a local
#ifdef NON_MATCHING
void func_800F7C48_StaffScene(StaffModel* m) {
    s32 i;
    f32 d;
    Vec3f* p;
    f32 tt;
    f32* ry;
    f32 vx;
    f32 ax;
    f32 vy;
    f32 ay;
    f32 vz;

    HuPrcSleep(2);
    p = &m->pos;
    tt = 3600.0f;
    d = D_800FD360_StaffScene.y - p->y;
    vy = 5.0f;
    d = 2.0f * d / tt;
    ay = d - 2.0f * vy / 60.0f;
    vz = (D_800FD360_StaffScene.z - p->z) / 60.0f;
    vx = 12.0f;
    ax = -0.4f;
    ry = &m->rot.y;
    for (i = 60; i != 0; i--) {
        p->x = vx + p->x;
        vx += ax;
        p->y = vy + p->y;
        vy += ay;
        p->z = vz + p->z;
        *ry = func_800B0CD8(0.0f - p->x, 500.0f - p->z);
        HuPrcVSleep();
    }
    *p = D_800FD360_StaffScene;
    *ry = 0.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_63_StaffScene/2A9CA0", func_800F7C48_StaffScene);
#endif
// register allocation only (masked 0): d and the folded 2*v/60 constants swap $f0/$f2; tried d accumulating the result, d declared last
#ifdef NON_MATCHING
void func_800F7DB4_StaffScene(StaffModel* m) {
    Vec3f* p;
    f32* ry;
    s32 i;
    f32 d;
    f32 vx;
    f32 vy;
    f32 vz;
    f32 ax;
    f32 ay;
    f32 az;

    p = &m->pos;
    d = D_800FD378_StaffScene.y - p->y;
    vy = -25.0f;
    d = 2.0f * d / 3600.0f;
    ay = d - 2.0f * vy / 60.0f;
    d = D_800FD378_StaffScene.x - p->x;
    vx = 35.0f;
    d = 2.0f * d / 3600.0f;
    ax = d - 2.0f * vx / 60.0f;
    d = D_800FD378_StaffScene.z - p->z;
    vz = -12.0f;
    d = 2.0f * d / 3600.0f;
    az = d - 2.0f * vz / 60.0f;
    ry = &m->rot.y;
    i = 60;
    do {
        p->x = vx + p->x;
        vx += ax;
        p->y = vy + p->y;
        vy += ay;
        p->z = vz + p->z;
        vz += az;
        if ((*ry += 10.0f) > 360.0f) {
            *ry -= 360.0f;
        }
        i--;
        HuPrcVSleep();
    } while (i != 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_63_StaffScene/2A9CA0", func_800F7DB4_StaffScene);
#endif
// decomp-permuter
void func_800F7F54_StaffScene(void)
{
  s32 t;
  Vec3f *p;
  StaffSparkle *s;
  StaffModel *m;
  StaffCtl *ctl;
  ctl = HuPrcCurrentGet()->user_data;
  m = func_800FC998_StaffScene();
  m->pos = D_800FD36C_StaffScene;
  m->rot.y = 180.0f;
  s = func_800FD0F0_StaffScene(m, 0);
  s->cmd = 4;
  ctl->stat = 0;
  while (1)
  {
    HuPrcVSleep();
    if (ctl->cmd != 0)
    {
      ctl->stat = ctl->cmd;
      ctl->cmd = 0;
    }
    if (ctl->stat == 1)
    {
      break;
    }
    switch (ctl->stat)
    {
      case 0:

      case 1:

      case 2:
        break;

      case 4:
        func_800F7C48_StaffScene(m);
        s->cmd = 6;
        ctl->stat = 3;
        break;

      case 5:
        s->cmd = 7;
        p = &m->pos;
        t = 90;
        ctl->stat = 6;

      case 3:
        if (m)
      {
        func_800F758C_StaffScene(m, 0);
        break;
      }
      else
      {
        func_800F758C_StaffScene(m, 0);
        break;
      }

      case 6:
        func_800F758C_StaffScene(m, 1);
        if (t != 0)
      {
        t--;
        p->z -= 12.0f;
        Center.z -= 12.0f;
      }
      else
      {
        PlaySound(0x4C);
        func_800F7DB4_StaffScene(m);
        ctl->stat = 7;
      }
        break;

    }

  }

  func_800FD170_StaffScene(s);
  func_800FCA8C_StaffScene(m);
  ctl->stat = -1;
  while (1)
  {
    HuPrcVSleep();
  }

}
void func_800F8128_StaffScene(void) {
    StaffCtl* ctl;
    void* file;
    s16 tex;
    s16 win;
    StaffXY xy[6];
    s32 k;
    s16 i;
    s16 j;
    s16 x;
    s16 y;

    ctl = HuPrcCurrentGet()->user_data;
    file = func_80014614(0xF0006);
    tex = func_800678A4(file);
    FreeTemp(file);
    win = func_80064EF4(6, 0);
    k = 0;
    for (x = 80, j = 0; j < 2; j++, x += 160) {
        for (y = -64, i = 0; i < 3; y += 128, i++, k++) {
            func_80067208(win, k, tex, 0);
            func_800672B0(win, k, 0);
            func_800674BC(win, k, 0x5000);
            func_80067384(win, k, 0xFFFF);
            xy[k].x = x;
            xy[k].y = y;
            func_80066DC4(win, k, x, y);
        }
    }
    while (ctl->cmd != 1) {
        for (k = 0; k < 6; k++) {
            xy[k].y += 2;
            if (xy[k].y > 320) {
                xy[k].y -= 384;
            }
            func_80066DC4(win, k, xy[k].x, xy[k].y);
        }
        HuPrcVSleep();
    }
    func_80064D38(win);
    func_80067704(tex);
    ctl->stat = -1;
    while (1) {
        HuPrcVSleep();
    }
}
void func_800F8380_StaffScene(void) {
    unkCommonStruct0 mes;
    s32 vx;
    s32 vy;
    s16 id;
    s16 win;
    StaffRoll* r;
    u8* str;
    s16 len;
    s32 w;
    s32 i;
    s32 d;
    f32 sx;
    s32 x;
    s32 y;
    s32 tx;
    s32 ty;
    s16 next;

    r = HuPrcCurrentGet()->user_data;
    win = func_80064EF4(1, 0);
    func_80067208(win, 0, r->tex, 0);
    func_800672B0(win, 0, 0);
    func_800674BC(win, 0, 0x100C);
    func_80067384(win, 0, 0x1000);
    func_80066DC4(win, 0, 400, 0);
    func_80067354(win, 0, 0.5f, 0.5f);
    id = -1;
    r->stat = 1;
    do {
        switch (r->cmd) {
        case 1:
            str = func_8005B7E8(*(u16*)r->names);
            id = GMesFontMesCreate(&mes, (char*)str, 0, 0, -1);
            len = func_8006D93C(str);
            func_8005B838(str);
            w = len * 16;
            if (w >= 0x110) {
                sx = 272.0f / w;
                w = 264;
                for (i = 1; i < len + 1; i++) {
                    func_80067354(mes.unk_14[id], i, sx, 1.0f);
                }
            }
            func_80066DC4(mes.unk_14[id], 0, 320, 0);
            switch (r->slot) {
            case 0:
                y = 248;
                x = 312 - w;
                vx = 0;
                vy = -6;
                tx = x;
                ty = 32;
                break;
            case 1:
                y = 32;
                x = 352;
                vx = -6;
                vy = 0;
                tx = 48;
                ty = 32;
                break;
            case 2:
                y = -16;
                x = 48;
                vx = 0;
                vy = 6;
                tx = 48;
                ty = 208;
                break;
            case 3:
                y = 208;
                x = -32 - w;
                vx = 6;
                vy = 0;
                tx = 312 - w;
                ty = 208;
                break;
            }
            next = 3;
            r->stat = 2;
            r->cmd = 0;
            break;
        case -1:
            r->stat = 0;
            r->cmd = 0;
            break;
        case 2:
            switch (r->slot) {
            case 0:
                ty = -16;
                vy = -8;
                break;
            case 1:
                tx = -32 - w;
                vx = -8;
                break;
            case 2:
                ty = 256;
                vy = 8;
                break;
            case 3:
                tx = 352;
                vx = 8;
                break;
            }
            next = 4;
            r->stat = 2;
            r->cmd = 0;
            break;
        default:
            r->cmd = 0;
            break;
        }
        switch (r->stat) {
        case 2:
            if ((tx != x) | (ty != y)) {
                d = tx - x;
                if (vx != 0) {
                    x += vx;
                    if ((d *= tx - x) < 0) {
                        x = tx;
                    }
                }
                d = ty - y;
                if (vy != 0) {
                    y += vy;
                    if ((d *= ty - y) < 0) {
                        y = ty;
                    }
                }
                func_80066DC4(mes.unk_14[id], 0, x, y);
                func_80066DC4(win, 0, x - 16, y);
            }
            if ((tx == x) & (ty == y)) {
                r->stat = next;
            }
            break;
        case 3:
            break;
        case 4:
            func_80066DC4(win, 0, 400, 0);
            func_80077044(&mes);
            id = -1;
            r->stat = 1;
            break;
        }
        HuPrcVSleep();
    } while (r->stat != 0);
    func_80064D38(win);
    r->stat = -1;
    while (1) {
        HuPrcVSleep();
    }
}
TextWindow* func_8006DD60(s16);
void func_8006E984(TextWindow*);

/* The names of each credits page: up to four rows of text windows behind a bar, slid in from the
   page's corner (StaffRoll.slot), a page at a time; the last page adds a fifth bar */
void func_800F8894_StaffScene(void) {
    TextWindow* tw[4];
    s16 win[4];
    s16 w[4];
    s16 bar;
    StaffRoll* r;
    void* file;
    s16 n;
    s16* names;
    s16* rows;
    s16 nrows;
    s16 next;
    s16 maxw;
    s16 timer;
    s32 vx;
    s32 vy;
    s32 tx;
    s32 ty;
    s16 tex;
    s16 bar2;
    s16 last;
    s32 i;
    s32 d;
    s16 l;
    s32 x;
    s32 y;

    r = HuPrcCurrentGet()->user_data;
    i = 0;
    bar = func_80064EF4(4, 0);
    for (; i < 4; i++) {
        func_80067208(bar, i, r->tex, 0);
        func_800672B0(bar, i, 0);
        func_800674BC(bar, i, 0x100C);
        func_80067384(bar, i, 0x1000);
        func_80066DC4(bar, i, 400, 0);
        func_80067354(bar, i, 0.5f, 0.5f);
        win[i] = func_8006D010(320, 240, 264, 32, 0, 0);
        tw[i] = func_8006DD60(win[i]);
        tw[i]->unk_03 = tw[i]->unk_04 = 0;
        tw[i]->unk_09 = 4;
        func_800674BC(tw[i]->unk_44, 0, 0x8000);
        func_8006E2B8(win[i], 40, 200, 255);
    }
    file = func_80014614(0xF0007);
    tex = func_800678A4(file);
    FreeTemp(file);
    bar2 = -1;
    last = 0;
    r->stat = 1;
    do {
        switch (r->cmd) {
        case -1:
            r->stat = 0;
            break;
        case 1:
            names = r->names;
            rows = r->rows;
            n = 0;
            r->stat = 2;
            if (names == D_800FD45C_StaffScene) {
                last = 1;
            }
            break;
        case 2:
            r->stat = 3;
            break;
        }
        r->cmd = 0;
        switch (r->stat) {
        case 2:
            if (n < r->count) {
                maxw = 0;
                for (i = 0; i < *rows && n < r->count; i++, n++) {
                    func_8006E984(tw[i]);
                    LoadStringIntoWindow(win[i], (void*)(s32)*names, 0, 0);
                    names++;
                    func_80066DC4(tw[i]->unk_44, 0, 320, 0);
                    l = func_8006D93C(tw[i]->stringPtr) + 1;
                    l = l * tw[i]->unk_09;
                    l = l + func_8006D99C(tw[i]->stringPtr, 0) + 8;
                    w[i] = l;
                    if (maxw < l) {
                        maxw = l;
                    }
                }
                if (last && n == r->count) {
                    i--;
                    bar2 = func_80064EF4(1, 0);
                    func_80067208(bar2, 0, tex, 0);
                    func_800672B0(bar2, 0, 0);
                    func_800674BC(bar2, 0, 0x100C);
                    func_80067384(bar2, 0, 0x1000);
                    func_80066DC4(bar2, 0, 400, 0);
                    i++;
                }
                rows++;
                nrows = i;
                switch (r->slot) {
                case 0:
                    y = 224 - (nrows << 4);
                    x = 352;
                    vx = -6;
                    vy = 0;
                    tx = 48;
                    ty = y;
                    break;
                case 1:
                    y = -16;
                    x = 308 - maxw;
                    vx = 0;
                    vy = 6;
                    tx = x;
                    ty = 224 - (nrows << 4);
                    break;
                case 2:
                    y = 24;
                    x = -32 - maxw;
                    vx = 6;
                    vy = 0;
                    tx = 308 - maxw;
                    ty = 24;
                    break;
                case 3:
                    y = 248;
                    x = 48;
                    vx = 0;
                    vy = -6;
                    tx = 48;
                    ty = 24;
                    break;
                }
                timer = 90;
                r->stat = 3;
                next = (n < r->count) ? 4 : 5;
            } else {
                r->stat = 1;
            }
            break;
        case 3:
            if ((tx != x) | (ty != y)) {
                if (vx != 0) {
                    d = tx - x;
                    x += vx;
                    if ((d *= tx - x) < 0) {
                        x = tx;
                    }
                }
                if (vy != 0) {
                    d = ty - y;
                    y += vy;
                    if ((d *= ty - y) < 0) {
                        y = ty;
                    }
                }
                for (i = 0; i < nrows; i++) {
                    d = i * 16;
                    func_80066DC4(tw[i]->unk_44, 0, x, y + d);
                    func_80066DC4(bar, i, x - 10, y + (u32)(d + 4));
                    if ((bar2 >= 0) & (i == 3)) {
                        func_80066DC4(tw[i]->unk_44, 0, x + 37, y + d);
                        func_80066DC4(bar2, 0, x + 16, y + (u32)(d + 6));
                    }
                }
            }
            if ((tx == x) & (ty == y)) {
                r->stat = next;
                if ((next == 1) & (bar2 >= 0)) {
                    func_8006DE20(win[3], 1.0f, 1.0f);
                    func_80064D38(bar2);
                    bar2 = -1;
                    last = 0;
                }
            }
            break;
        case 4:
        case 5:
            if (timer != 0) {
                timer--;
                break;
            }
            switch (r->slot) {
            case 0:
                tx = -32 - maxw;
                vx = -8;
                break;
            case 1:
                ty = 256;
                vy = 8;
                break;
            case 2:
                tx = 352;
                vx = 8;
                break;
            case 3:
                ty = -64;
                vy = -8;
                break;
            }
            if (n < r->count) {
                r->stat = 3;
                next = 2;
            } else {
                r->stat = 1;
                next = 1;
            }
            break;
        }
        HuPrcVSleep();
    } while (r->stat != 0);
    func_80067704(tex);
    if (bar2 >= 0) {
        func_80064D38(bar2);
    }
    func_80064D38(bar);
    func_80070ED4();
    r->stat = -1;
    while (1) {
        HuPrcVSleep();
    }
}

void func_800F91E0_StaffScene(void) {
    StaffRoll title;
    StaffRoll names;
    StaffRoll coin;
    Process* p1;
    Process* p2;
    Process* p3;
    void* file;
    s16 tex;
    StaffCredit* c;
    s16 slot;

    file = func_80014614(0xA0014);
    tex = func_800678A4(file);
    FreeTemp(file);
    title.tex = tex;
    names.tex = tex;
    p1 = omAddPrcObj(func_800F8380_StaffScene, 0x3F08, 0x800, 0);
    p1->user_data = &title;
    title.cmd = 0;
    omPrcSetStatBit(p1, 0xA0);
    p2 = omAddPrcObj(func_800F8894_StaffScene, 0x3F08, 0x800, 0);
    p2->user_data = &names;
    names.cmd = 0;
    omPrcSetStatBit(p2, 0xA0);
    p3 = omAddPrcObj(func_800F94E0_StaffScene, 0x3F08, 0x800, 0);
    p3->user_data = &coin;
    coin.cmd = 0;
    omPrcSetStatBit(p3, 0xA0);
    slot = 0;
    HuPrcVSleep();
    c = D_800FD4C0_StaffScene;
    while (c->names != NULL) {
        title.names = &c->title;
        title.slot = slot;
        title.cmd = 1;
        while (title.stat != 3) {
            HuPrcVSleep();
        }
        names.count = c->count;
        names.names = c->names;
        names.rows = c->rows;
        names.slot = slot;
        names.cmd = 1;
        do {
            HuPrcVSleep();
        } while (names.stat != 5);
        coin.slot = slot;
        coin.cmd = 1;
        do {
            HuPrcVSleep();
        } while (coin.stat != 4);
        coin.cmd = 2;
        names.cmd = 2;
        do {
            HuPrcVSleep();
        } while (names.stat != 1);
        title.cmd = 2;
        do {
            HuPrcVSleep();
        } while (title.stat != 1);
        if (++slot >= 4) {
            slot = 0;
        }
        c++;
        if (c->names == NULL) {
            break;
        }
        HuPrcSleep(30);
    }
    title.cmd = -1;
    names.cmd = -1;
    coin.cmd = -1;
    while (title.stat != -1) {
        HuPrcVSleep();
    }
    while (names.stat != -1) {
        HuPrcVSleep();
    }
    while (coin.stat != -1) {
        HuPrcVSleep();
    }
    EndProcess(p1);
    EndProcess(p2);
    EndProcess(p3);
    func_80067704(tex);
}
void DataCloseTemp(void*);

/* The model of each credits page, flying from the page's corner to the coin in the middle */
void func_800F94E0_StaffScene(void) {
    StaffModel obj;
    Vec3f off;
    Vec3f target;
    Vec3f vel;
    StaffRoll* r;
    StaffObjDef* def;
    unk_ovl_2D_struct* o;
    void* file;
    s16 coin;
    s16 m;
    s16 anim;
    s16 frame;
    s16 t;
    s16 next;
    s32 b;
    Vec3f* pos;

    r = HuPrcCurrentGet()->user_data;
    coin = LoadFormFile(0xF0001, 0x6B9);
    func_800258EC(coin, 4, 4);
    obj.scale.x = 1.0f;
    obj.scale.y = 1.0f;
    obj.scale.z = 1.0f;
    obj.rot.x = 0.0f;
    obj.rot.y = 0.0f;
    obj.rot.z = 0.0f;
    pos = &obj.pos;
    def = D_800FD6A0_StaffScene;
    r->stat = 1;
    do {
        switch (r->cmd) {
        case -1:
            r->stat = 0;
            r->cmd = 0;
            break;
        case 1:
            if (def->unk_00 < 0) {
                def = D_800FD6A0_StaffScene;
            }
            file = func_80014614(def->file);
            HuPrcVSleep();
            m = LoadFormBinary(file, 0x68D);
            func_80025EB4(m, 2, 2);
            FreeTemp(file);
            if (def->file2 < 0) {
                anim = -1;
            } else {
                HuPrcVSleep();
                file = func_80014614(def->file2);
                HuPrcVSleep();
                anim = LoadFormBinary(file, 0x1D);
                FreeTemp(file);
                frame = def->unk_02;
            }
            off.x = 0.0f;
            off.y = def->unk_04;
            off.z = 0.0f;
            switch (def->unk_00) {
            case 1:
                func_80025830(m, 0.7f, 0.7f, 0.7f);
                break;
            case 2:
                o = &D_800F2B7C[m];
                file = func_80014614(0x90041);
                func_80038A9C(o->unk_6C, file, 0, "coin_DEF");
                DataCloseTemp(file);
                func_80025AD4(m);
                break;
            case 3:
                break;
            case 4:
                func_80025830(m, 0.5f, 0.5f, 0.5f);
                break;
            case 5:
                break;
            }
            switch (r->slot) {
            case 0:
                pos->x = -1100.0f;
                pos->y = 780.0f;
                pos->z = -780.0f;
                target.x = 400.0f;
                target.y = 40.0f;
                target.z = 680.0f;
                break;
            case 1:
                pos->x = -1100.0f;
                pos->y = -250.0f;
                pos->z = -780.0f;
                target.x = 400.0f;
                target.y = 330.0f;
                target.z = 680.0f;
                break;
            case 2:
                pos->x = 1100.0f;
                pos->y = -250.0f;
                pos->z = -780.0f;
                target.x = -400.0f;
                target.y = 330.0f;
                target.z = 680.0f;
                break;
            case 3:
                pos->x = 1100.0f;
                pos->y = 780.0f;
                pos->z = -780.0f;
                target.x = -400.0f;
                target.y = 40.0f;
                target.z = 680.0f;
                break;
            }
            vel.x = (target.x - pos->x) * 0.008333334f;
            vel.y = (target.y - pos->y) * 0.008333334f;
            vel.z = (target.z - pos->z) * 0.008333334f;
            func_800258EC(m, 4, 0);
            func_800258EC(coin, 4, 0);
            r->stat = 2;
            r->cmd = 0;
            next = 3;
            t = 0;
            def++;
            break;
        case 2:
            r->stat = 1;
            break;
        }
        switch (r->stat) {
        case 2:
            t++;
            if (target.x == pos->x && target.y == pos->y && target.z == pos->z) {
                r->stat = next;
                break;
            }
            if (anim >= 0) {
                if (t == frame) {
                    func_80025BB8(m, anim);
                }
            }
            if (target.x != pos->x) {
                b = 0;
                if (pos->x < target.x) {
                    b = 1;
                }
                pos->x += vel.x;
                if (pos->x < target.x) {
                    b ^= 1;
                }
                if (b) {
                    pos->x = target.x;
                }
            }
            if (target.y != pos->y) {
                b = 0;
                if (pos->y < target.y) {
                    b = 1;
                }
                pos->y += vel.y;
                if (pos->y < target.y) {
                    b ^= 1;
                }
                if (b) {
                    pos->y = target.y;
                }
            }
            if (target.z != pos->z) {
                b = 0;
                if (pos->z < target.z) {
                    b = 1;
                }
                pos->z += vel.z;
                if (pos->z < target.z) {
                    b ^= 1;
                }
                if (b) {
                    pos->z = target.z;
                }
            }
            func_80025798(m, pos->x + off.x, pos->y + off.y, pos->z + off.z);
            func_80025798(coin, pos->x, pos->y, pos->z);
            break;
        case 3:
            func_800258EC(coin, 4, 4);
            func_8002456C(m);
            if (anim >= 0) {
                func_8002456C(anim);
            }
            r->stat = 4;
            break;
        case 4:
            break;
        }
        HuPrcVSleep();
    } while (r->stat != 0);
    func_8002456C(coin);
    r->stat = -1;
    while (1) {
        HuPrcVSleep();
    }
}

/* unreferenced: the zero tail after jtbl_800FE230, before func_800FAD30's double D_800FE250
   (16-aligned in retail) */
const s32 D_800FE244_StaffScene[3] = { 0, 0, 0 };

void func_800F9C38_StaffScene(void) {
    s16 model[12];
    s16 anim[12];
    f32 y[12];
    StaffCtl* ctl;
    StaffObjDef* def;
    void* file;
    s16 m;
    s16 c;
    s32 i;

    ctl = HuPrcCurrentGet()->user_data;
    for (i = 0; i < 12; i++) {
        def = &D_800FD6A0_StaffScene[D_800FD900_StaffScene[i]];
        file = func_80014614(def->file);
        m = LoadFormBinary(file, 0x6A9);
        func_80025EB4(m, 2, 2);
        func_80025798(m, D_800FD870_StaffScene[i].x, D_800FD870_StaffScene[i].y, D_800FD870_StaffScene[i].z);
        y[i] = D_800FD870_StaffScene[i].y;
        if (i == 9) {
            func_80025830(m, 1.5f, 1.5f, 1.5f);
        }
        FreeTemp(file);
        model[i] = m;
        if ((def->file2 < 0) | (i >= 6)) {
            anim[i] = -1;
        } else {
            file = func_80014614(def->file2);
            anim[i] = LoadFormBinary(file, 0x1D);
            FreeTemp(file);
        }
    }
    ctl->stat = 1;
    do {
        c = ctl->cmd;
        if (c != 0) {
            switch (c) {
            case 2:
                ctl->stat = 2;
                break;
            case -1:
                ctl->stat = 0;
                break;
            case 3:
                ctl->stat = 3;
                break;
            }
            ctl->cmd = 0;
        }
        switch (ctl->stat) {
        case 1:
            break;
        case 3:
            for (i = 0; i < 12; i++) {
                y[i] -= 5.0f;
                func_80025798(model[i], D_800FD870_StaffScene[i].x, y[i], D_800FD870_StaffScene[i].z);
            }
            break;
        case 2:
            PlaySound(0x96);
            for (i = 0; i < 6; i++) {
                func_80025BB8(model[i], anim[i]);
            }
            ctl->stat = 1;
            break;
        }
        HuPrcVSleep();
    } while (ctl->stat != 0);
    for (i = 0; i < 12; i++) {
        func_8002456C(model[i]);
        if (anim[i] >= 0) {
            func_8002456C(anim[i]);
        }
    }
    ctl->stat = -1;
    while (1) {
        HuPrcVSleep();
    }
}
// register allocation (retail hoists two more constants and keeps one more callee-saved FPR)
#ifdef NON_MATCHING
void func_800F9F70_StaffScene(void) {
    Vec3f vel;
    Vec3f acc;
    s16 model[16];
    StaffModel* m;
    StaffSparkle* s;
    Vec3f* p;
    f32* rz;
    s32 i;
    s16 m0;
    s16 m1;
    s16 m2;
    s16 t;
    f32 a;
    f32 v;
    f32 s1;
    f32 s2;

    for (i = 0; i < 16; i++) {
        model[i] = -1;
    }
    func_8002578C(0);
    func_800FC554_StaffScene(&D_800FD934_StaffScene);
    func_80028510(0x36B, 0x3C0, 0, 0, 0x30);
    HuPrcVSleep();
    m0 = func_800174C0(0x90035, 0x699);
    func_80025CA8(m0, func_80025D40(m0) - 1.0f);
    func_80025EB4(m0, 1, 1);
    model[0] = m0;
    m1 = LoadFormFile(0x210001, 0x689);
    func_80025830(m1, 2.3f, 0.7f, 2.3f);
    func_80025798(m1, 0.0f, -100.0f, 0.0f);
    model[1] = m1;
    m2 = func_80023FC8(m1);
    func_80025830(m2, 2.0f, 0.7f, 2.0f);
    func_80025798(m2, 0.0f, -100.0f, 0.0f);
    model[2] = m2;
    m = func_800FC998_StaffScene();
    func_800A0D00(&m->pos, 0.0f, 320.0f, 0.0f);
    s = func_800FD0F0_StaffScene(m, 0);
    func_80060128(4);
    SetFadeInTypeAndTime(0, 0x10);
    a = 0.0f;
    rz = &m->rot.z;
    t = 136;
    do {
        v = func_800AEAC0(a) * 30.0f;
        if (t != 0) {
            t--;
            a += 6.0f;
        } else {
            a += 4.0f;
            if (v * *rz < 0.0f) {
                v = 0.0f;
            }
        }
        *rz = v;
        if (a > 360.0f) {
            a -= 360.0f;
        }
        HuPrcVSleep();
    } while (t != 0 || *rz != 0.0f);
    s->cmd = 4;
    PlaySound(5);
    p = &m->pos;
    func_800A0D00(&vel, -10.0f, -14.0f, 15.0f);
    func_800A0D00(&acc, 0.7f, 1.0f, 0.0f);
    s1 = 2.3f;
    s2 = 2.0f;
    t = 60;
    do {
        func_800A0E00(p, p, &vel);
        func_800A0E00(&vel, &vel, &acc);
        if (vel.x > 13.0f) {
            vel.x = 13.0f;
        }
        s1 *= 0.94f;
        s2 *= 0.94f;
        func_80025830(m1, s1, 0.7f, s1);
        func_80025830(m2, s2, 0.7f, s2);
        if (t == 20) {
            func_80072724(0xFF, 0xFF, 0xFF);
            func_800726AC(0, 0x14);
        }
        HuPrcVSleep();
    } while (--t != 0);
    HuPrcSleep(0x14);
    func_8002854C();
    func_800FD170_StaffScene(s);
    func_800FCA8C_StaffScene(m);
    for (i = 0; i < 16; i++) {
        if (model[i] > 0) {
            func_8002456C(model[i]);
        }
    }
    HuPrcVSleep();
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_63_StaffScene/2A9CA0", func_800F9F70_StaffScene);
#endif
void func_800FA3D8_StaffScene(void) {
    StaffCtl* ctl;
    s16 model;
    f32 v;
    f32 u;

    ctl = HuPrcCurrentGet()->user_data;
    model = LoadFormFile(0x9001A, 0x699);
    func_80026040(model);
    func_80025F10(model, 1);
    u = v = 0.0f;
    ctl->stat = 1;
    do {
        HuPrcVSleep();
        switch (ctl->cmd) {
        case 0:
            break;
        case 1:
            ctl->stat = 0;
            break;
        }
        func_80027C1C(model, u, v, 0x20, 0x20);
        v += 0.5f;
    } while (ctl->stat != 0);
    func_8002456C(model);
    ctl->stat = -1;
    while (1) {
        HuPrcVSleep();
    }
}
void func_800FA4F4_StaffScene(void) {
    s32 pad[2]; /* retail frame */
    s16 model[16];
    s16 bg[8];
    Process* p1;
    Process* p2;
    Process* p3;
    Process* p4;
    Process* p5;
    s32 i;
    s16 wait;
    s16 n;
    f32 dx;
    f32 dy;
    f32 dz;

    n = 105;
    dx = (D_800FD974_StaffScene.x - D_800FD954_StaffScene.center.x) / 105.0f;
    dy = (D_800FD974_StaffScene.y - D_800FD954_StaffScene.center.y) / 105.0f;
    dz = (D_800FD974_StaffScene.z - D_800FD954_StaffScene.center.z) / 105.0f;
    func_8002578C(1);
    for (i = 0; i < 16; i++) {
        model[i] = -1;
    }
    for (i = 0; i < 8; i++) {
        bg[i] = -1;
    }
    wait = 18;
    func_800FC554_StaffScene(&D_800FD954_StaffScene);
    p1 = omAddPrcObj(func_800FA3D8_StaffScene, 0x3F00, 0x800, 0);
    p1->user_data = &D_800FD980_StaffScene;
    p2 = omAddPrcObj(func_800FBE80_StaffScene, 0x3F00, 0x1000, 0);
    p2->user_data = &D_800FD984_StaffScene;
    p3 = omAddPrcObj(func_800FB1A0_StaffScene, 0x3F00, 0x1000, 0);
    p3->user_data = &D_800FD988_StaffScene;
    p4 = omAddPrcObj(func_800FAD30_StaffScene, 0x3F00, 0x1000, 0);
    p4->user_data = &D_800FD98C_StaffScene;
    p5 = omAddPrcObj(func_800FAA4C_StaffScene, 0x3F00, 0x800, 0);
    p5->user_data = &D_800FD990_StaffScene;
    model[0] = func_800174C0(0xF0000, 0x299);
    SetFadeInTypeAndTime(0, 8);
    PlaySound(0xB);
    HuPrcSleep(8);
    D_800FD984_StaffScene.cmd = 3;
    HuPrcSleep(0);
    while (D_800FD984_StaffScene.stat != 4) {
        if (wait != 0) {
            wait--;
        } else if (n != 0) {
            n--;
            Center.x += dx;
            Center.y += dy;
            Center.z += dz;
        }
        HuPrcSleep(0);
    }
    D_800FD98C_StaffScene.cmd = 2;
    while (D_800FD984_StaffScene.stat != 5) {
        HuPrcSleep(0);
    }
    do {
        HuPrcSleep(0);
    } while ((CRot.x += 3.0f) < 42.0f);
    CRot.x = 42.0f;
    PlaySound(8);
    D_800FD988_StaffScene.cmd = 4;
    HuPrcVSleep();
    while (D_800FD988_StaffScene.stat == 4) {
        HuPrcVSleep();
    }
    HuPrcSleep(3);
    func_80072724(0xFF, 0xFF, 0xFF);
    func_800726AC(0, 3);
    HuPrcSleep(3);
    PlaySound(0xE);
    PlaySound(0x11);
    D_800FD980_StaffScene.cmd = 1;
    D_800FD984_StaffScene.cmd = -1;
    D_800FD988_StaffScene.cmd = 1;
    D_800FD98C_StaffScene.cmd = 1;
    D_800FD990_StaffScene.cmd = -1;
    while (D_800FD980_StaffScene.stat != -1) {
        HuPrcSleep(0);
    }
    EndProcess(p1);
    while (D_800FD984_StaffScene.stat != -1) {
        HuPrcSleep(0);
    }
    EndProcess(p2);
    while (D_800FD988_StaffScene.stat != -1) {
        HuPrcSleep(0);
    }
    EndProcess(p3);
    while (D_800FD98C_StaffScene.stat >= 0) {
        HuPrcSleep(0);
    }
    EndProcess(p4);
    while (D_800FD990_StaffScene.stat != -1) {
        HuPrcSleep(0);
    }
    EndProcess(p5);
    for (i = 0; i < 16; i++) {
        if (model[i] >= 0) {
            func_8002456C(model[i]);
        }
    }
    for (i = 0; i < 8; i++) {
        if (bg[i] >= 0) {
            func_8002019C(bg[i]);
        }
    }
    HuPrcVSleep();
}
void func_800FAA4C_StaffScene(void) {
    s16 xy[2];
    StaffCtl* ctl;
    void* file;
    s16 tex;
    s16 win;
    s32 i;
    f32 x;
    f32 y;

    i = 0;
    ctl = HuPrcCurrentGet()->user_data;
    func_800FC624_StaffScene(xy, 0, 0.0f, 2200.0f, 0.0f);
    file = func_80014614(0xF0006);
    tex = func_800678A4(file);
    FreeTemp(file);
    win = func_80064EF4(6, 0);
    for (; i < 6; i++) {
        func_80067208(win, i, tex, 0);
        func_800672B0(win, i, 0);
        func_800674BC(win, i, 0x5000);
        func_80067384(win, i, 0xFFFF);
        func_80066DC4(win, i, xy[0] + D_800FD994_StaffScene[i].x, xy[1] + D_800FD994_StaffScene[i].y);
    }
    ctl->stat = 1;
    do {
        HuPrcVSleep();
        if (ctl->cmd != 0) {
            if (ctl->cmd == -1) {
                ctl->stat = 0;
            }
            ctl->cmd = 0;
        }
        switch (ctl->stat) {
        case 0:
            break;
        case 1:
            func_800FC624_StaffScene(xy, 0, 0.0f, 2300.0f, 0.0f);
            for (i = 0; i < 6; i++) {
                x = xy[0] + D_800FD994_StaffScene[i].x;
                y = xy[1] + D_800FD994_StaffScene[i].y;
                if (y > 320.0f) {
                    y -= 384.0f;
                } else if (y <= -192.0f) {
                    y += 384.0f;
                }
                func_80066DC4(win, i, x, y);
            }
            break;
        }
    } while (ctl->stat != 0);
    func_80064D38(win);
    func_80067704(tex);
    ctl->stat = -1;
    while (1) {
        HuPrcVSleep();
    }
}
// loop-invariant hoisting: 1.0f is hoisted into an FPR here, not in retail (masked 5)
#ifdef NON_MATCHING
void func_800FAD30_StaffScene(void) {
    StaffSparkleDot dots[52];
    StaffCtl* ctl;
    StaffSparkleDot* d;
    s32 i;
    s16 first;
    s16 model;
    s16 active;
    s16 cnt;
    s16 t;
    f32 f;
    f32 sc;
    f32 a;
    f32 x;
    f32 z;

    first = -1;
    ctl = HuPrcCurrentGet()->user_data;
    f = 0.0f;
    for (d = dots, i = 52; i != 0; i--, d++) {
        d->timer = f;
        d->angle = 0.0f;
        d->pos.x = 0.0f;
        d->pos.y = 0.0f;
        d->pos.z = 0.0f;
        f += 2.4615386f;
        if (first < 0) {
            model = LoadFormFile(0xA0138, 0x699);
            first = model;
        } else {
            model = func_80023FC8(first);
        }
        d->model = model;
        func_800258EC(model, 4, 4);
        func_80025EB4(model, 2, 2);
        func_80025F10(model, 1);
    }
    active = 1;
    ctl->stat = 1;
    do {
        switch (ctl->cmd) {
        case 1:
            active = 0;
            break;
        case 2:
            t = 64;
            ctl->stat = 2;
            break;
        }
        ctl->cmd = 0;
        cnt = 0;
        if (ctl->stat == 2) {
            D_800FD9B4_StaffScene.y += 5.0f;
            if (--t == 0) {
                active = 0;
            }
        }
        for (d = dots, i = 0; i < 52; i++, d++) {
            model = d->model;
            if (d->timer != 0) {
                d->timer--;
                cnt++;
                a = d->angle - 0.00546875f;
                d->angle = a;
                sc = (1.25f - rand8() / 510.0f) * a;
                func_80025830(model, sc, sc, sc);
                d->pos.y -= 10.0f;
                func_80025798(model, d->pos.x, d->pos.y, d->pos.z);
            } else if (active != 0) {
                x = 2700.0f - (f32)(func_800FD2AC_StaffScene() % 5400);
                z = 2700.0f - (f32)(func_800FD2AC_StaffScene() % 5400);
                d->pos.x = x + D_800FD9B4_StaffScene.x;
                d->pos.z = z + D_800FD9B4_StaffScene.z;
                d->pos.y = (s32)((rand8() & 0x7F) - 0x40) + D_800FD9B4_StaffScene.y;
                func_80025798(model, d->pos.x, d->pos.y, d->pos.z);
                d->angle = 1.0f;
                func_80025830(model, 1.0f, 1.0f, 1.0f);
                func_800258EC(model, 4, 0);
                d->timer = 128;
            } else {
                func_800258EC(model, 4, 4);
            }
        }
        if (cnt == 0) {
            break;
        }
        HuPrcVSleep();
    } while (ctl->stat != 0);
    for (d = dots, i = 52; i != 0; i--, d++) {
        if (d->model >= 0) {
            func_8002456C(d->model);
        }
    }
    ctl->stat = -1;
    while (1) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_63_StaffScene/2A9CA0", func_800FAD30_StaffScene);
#endif
// loop-invariant hoisting: retail hoists 21 and 21.0f into callee-saved registers (frame 216 vs 208)
#ifdef NON_MATCHING
void func_800FB1A0_StaffScene(void) {
    struct {
        StaffModel* m[6];
        StaffSparkle* s[6];
        s16 state[8];
        s16 timer[8];
    } w;
    struct {
        f32 x;
        f32 z;
    } vel[5];
    StaffCtl* ctl;
    s32 i;
    s16 c;
    s16 n;
    f32 f;
    f32 a;

    i = 0;
    ctl = HuPrcCurrentGet()->user_data;
    for (f = 0.0f; i < 5; i++) {
        w.state[i] = 0;
        w.timer[i] = f;
        f += 6.0f;
        w.m[i] = func_800FC998_StaffScene();
        w.m[i]->cmd = 3;
        func_80025930(w.m[i]->model, 0x20000000, 0x20000000);
        w.s[i] = func_800FD0F0_StaffScene(w.m[i], 2);
    }
    ctl->stat = 3;
    do {
        HuPrcVSleep();
        c = ctl->cmd;
        if (c != 0) {
            switch (c) {
            case 1:
                ctl->stat = 0;
                break;
            case 4:
                ctl->stat = 4;
                break;
            }
            ctl->cmd = 0;
        }
        if (ctl->stat == 1) {
            break;
        }
        switch (ctl->stat) {
        case 2:
            break;
        case 3:
            break;
        case 4:
            n = 5;
            for (i = 0; i < 5; i++) {
                if (w.timer[i] != 0) {
                    w.timer[i]--;
                    if (w.state[i] != 0) {
                        if (fabs(w.m[i]->pos.x) < fabs(vel[i].x) || fabs(w.m[i]->pos.z) < fabs(vel[i].z)) {
                            w.timer[i] = 0;
                            w.m[i]->pos.x = 0.0f;
                            w.m[i]->pos.z = 0.0f;
                        } else {
                            w.m[i]->pos.x -= vel[i].x;
                            w.m[i]->pos.z -= vel[i].z;
                            vel[i].x *= 1.1f;
                            vel[i].z *= 1.1f;
                        }
                    }
                    continue;
                }
                if (w.state[i] != 0) {
                    if (w.state[i] == 10) {
                        w.s[i]->cmd = 1;
                        w.m[i]->cmd = 1;
                        n--;
                        continue;
                    }
                } else {
                    w.s[i]->cmd = 4;
                    w.m[i]->cmd = 4;
                }
                a = func_800FD2AC_StaffScene() % 360;
                w.m[i]->pos.x = func_800AEAC0(a) * 1500.0f;
                w.m[i]->pos.z = func_800AEFD0(a) * 1500.0f;
                w.m[i]->pos.y = 2000.0f;
                w.state[i]++;
                w.timer[i] = 21;
                vel[i].x = w.m[i]->pos.x / 21.0f;
                vel[i].z = w.m[i]->pos.z / w.timer[i];
            }
            if (n == 0) {
                ctl->stat = 0;
            }
            break;
        }
    } while (ctl->stat != 0);
    for (i = 0; i < 5; i++) {
        func_800FD170_StaffScene(w.s[i]);
        func_800FCA8C_StaffScene(w.m[i]);
    }
    ctl->stat = -1;
    while (1) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_63_StaffScene/2A9CA0", func_800FB1A0_StaffScene);
#endif
void func_800FB5F0_StaffScene(StaffModel* m, Vec3f* to, s32 n) {
    Vec3f* p;
    f32 fn;
    f32 dx;
    f32 dy;
    f32 dz;

    p = &m->pos;
    dx = to->x - p->x;
    dy = to->y - p->y;
    dz = to->z - p->z;
    fn = n;
    dx /= fn;
    dy /= fn;
    dz /= fn;
    for (; n != 0; n--) {
        p->x = dx + p->x;
        p->y = dy + p->y;
        p->z = dz + p->z;
        HuPrcVSleep();
    }
}
void func_800FB6A8_StaffScene(StaffModel* m, f32 dist, s32 mode, f32 rise, f32 maxYaw) {
    f32 minYaw;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dxz;
    f32 d;
    f32 yaw;
    f32 pitch;
    f32 a;
    f32 lim;
    f32 dist2;
    f32 k;

    if (mode != 0) {
        minYaw = 0.0f - maxYaw;
        dist2 = dist * dist;
        dx = m->pos.x - Center.x;
        dy = m->pos.y - Center.y;
        dz = m->pos.z - Center.z;
        dxz = dx * dx + dz * dz;
        if (mode >= 3) {
            d = dxz + dy * dy;
            if (dist2 < d) {
                k = dist / func_800B1750(d);
                Center.x = m->pos.x - dx * k;
                Center.y = m->pos.y - dy * k;
                Center.z = m->pos.z - dz * k;
            }
            Center.y += rise;
        }
        yaw = func_800B0CD8(dx, dz) - 180.0f;
        if (yaw > 360.0f) {
            yaw -= 360.0f;
        } else if (yaw < 0.0f) {
            yaw += 360.0f;
        }
        pitch = func_800B0CD8(dy, func_800B1750(dxz));
        a = func_800B0CD8(0.0f - Center.x, 0.0f - Center.z) - 180.0f;
        if (a > 360.0f) {
            a -= 360.0f;
        } else if (a < 0.0f) {
            a += 360.0f;
        }
        a -= yaw;
        if (a > 180.0f) {
            a -= 360.0f;
        } else if (a < -180.0f) {
            a += 360.0f;
        }
        lim = 30.0f;
        if (a > lim || (lim = -30.0f, a < lim)) {
            a = lim;
        }
        yaw += a;
        if (yaw > 360.0f) {
            yaw -= 360.0f;
        } else if (yaw < 0.0f) {
            yaw += 360.0f;
        }
        a = yaw - CRot.y;
        if (a > 180.0f) {
            a -= 360.0f;
        } else if (a < -180.0f) {
            a += 360.0f;
        }
        if (maxYaw < a) {
            a = maxYaw;
        } else if (a < minYaw) {
            a = minYaw;
        }
        a += CRot.y;
        if (a > 360.0f) {
            a -= 360.0f;
        } else if (a < 0.0f) {
            a += 360.0f;
        }
        CRot.y = a;
        a = pitch - CRot.x;
        if (a > 180.0f) {
            a -= 360.0f;
        } else if (a < -180.0f) {
            a += 360.0f;
        }
        lim = 1.0f;
        if (a > lim || (lim = -1.0f, a < lim)) {
            a = lim;
        }
        CRot.x += a;
    }
}
void func_800FBB88_StaffScene(StaffModel* m, s32* state, s32 t) {
    s32 hit;
    s32 z;

    switch (*state) {
    case 0:
        if (t == 0) {
            D_800FDA08_StaffScene = 0.0f;
        }
        hit = 1;
        if (!(m->pos.x > 86.0f)) {
            hit = 0;
        }
        if (hit | (z = (t == 56))) {
            D_800FDA0C_StaffScene = 2.0f;
            *state = 3;
        }
        break;
    case 2:
    case 3:
        if (t >= 75) {
            if (t < 100) {
                if (D_800FDA08_StaffScene < 60.0f) {
                    D_800FDA08_StaffScene += 2.5f;
                }
            } else {
                if (t == 100) {
                    *state = 2;
                }
                if (Center.y > 640.0f) {
                    Center.y -= 10.0f;
                }
            }
        }
        break;
    }
    if (*state != 0) {
        func_800FB6A8_StaffScene(m, 450.0f, *state, D_800FDA08_StaffScene, D_800FDA0C_StaffScene);
    }
}
void func_800FBCF4_StaffScene(StaffModel* m, Vec3f* path, s32 n, s32 steps) {
    s32 state;
    Vec3f* p;
    Vec3f* r;
    s32 t;
    s32 i;
    f32 fn;
    f32 dx;
    f32 dy;
    f32 dz;

    state = 0;
    p = &m->pos;
    r = &m->rot;
    for (t = 0; n != 0; n--, path++, t++) {
        i = steps;
        dx = path->x - p->x;
        dy = path->y - p->y;
        dz = path->z - p->z;
        fn = i;
        dx /= fn;
        dy /= fn;
        dz /= fn;
        for (; i != 0; i--) {
            p->x = dx + p->x;
            p->y = dy + p->y;
            p->z = dz + p->z;
            func_800FBB88_StaffScene(m, &state, t);
            if (t >= 43) {
                r->y += 24.0f;
                if (r->y > 360.0f) {
                    r->y -= 360.0f;
                }
            } else {
                r->y = CRot.y;
            }
            HuPrcVSleep();
        }
    }
}
void func_800FBE80_StaffScene(void) {
    StaffCtl* ctl;
    StaffModel* m;
    StaffSparkle* s;
    s16 ring;
    s16 star;
    s16 tex;
    s16 c;
    void* file;
    f32 f;
    f32 g;

    star = -1;
    ctl = HuPrcCurrentGet()->user_data;
    m = func_800FC998_StaffScene();
    m->pos = D_800FD9C0_StaffScene;
    s = func_800FD0F0_StaffScene(m, 3);
    s->cmd = 4;
    ctl->stat = 2;
    do {
        HuPrcVSleep();
        c = ctl->cmd;
        if (c != 0) {
            switch (c) {
            case -1:
                ctl->stat = 0;
                break;
            case 3:
                ctl->stat = 3;
                break;
            }
            ctl->cmd = 0;
        }
        switch (ctl->stat) {
        case 0:
        case 1:
        case 2:
            break;
        case 3:
            m->rot.y = CRot.y;
            PlaySound(0x1D);
            func_800FB5F0_StaffScene(m, &D_800FD9CC_StaffScene, 12);
            func_800FBCF4_StaffScene(m, D_800FDA10_StaffScene, 160, 3);
            while (fabs(g = m->rot.y - CRot.y) > 8.0) {
                HuPrcVSleep();
                m->rot.y += 8.0f;
                if (m->rot.y > 360.0f) {
                    m->rot.y -= 360.0f;
                }
            }
            m->rot.y = CRot.y;
            ctl->stat = 4;
            break;
        case 4:
            HuPrcSleep(15);
            PlaySound(0x1A);
            func_800FB5F0_StaffScene(m, &D_800FD9D8_StaffScene, 30);
            func_80025930(m->model, 0x70000000, 0x70000000);
            ctl->stat = 5;
        case 5:
            func_800FB5F0_StaffScene(m, D_800FD9E4_StaffScene, 24);
            s->cmd = 6;
            ring = LoadFormFile(0xA0136, 0x6B9);
            func_80025798(ring, m->pos.x, m->pos.y - 20.0f, m->pos.z);
            func_800257E4(ring, CRot.x + 90.0f, m->rot.y, m->rot.z);
            PlaySound(0x18);
            for (f = 3.0f; f < 5.0f; f += 0.4f) {
                func_80025830(ring, f, f, f);
                HuPrcVSleep();
            }
            func_8002456C(ring);
            star = LoadFormFile(0xA0139, 0x6A9);
            file = func_80014614(0xA013A);
            tex = func_80038A9C(D_800F2B7C[star].unk_6C, file, 0, "m1e_020_IA44");
            FreeTemp(file);
            func_80025AD4(star);
            func_80025798(star, m->pos.x, m->pos.y, m->pos.z);
            for (f = 0.0f; f < 3.0f; f += 0.5f) {
                func_80025830(star, f, f, f);
                func_80025798(star, m->pos.x, m->pos.y - f * 96.0f, m->pos.z);
                HuPrcVSleep();
            }
            for (g = 1.0f; f >= 2.0f; f -= 0.5f, g -= 0.5f) {
                func_80025830(star, f, f, f);
                func_80025798(star, m->pos.x, m->pos.y - f * 96.0f, m->pos.z);
                m->scale.x = g;
                m->scale.y = g;
                m->scale.z = g;
                HuPrcVSleep();
            }
            ctl->stat = 6;
        case 6:
            if (f < 6.0f) {
                f += 0.04f;
            }
            g = (1.125f - rand8() / 1024.0f) * f;
            func_80025830(star, g, g, g);
            func_80025798(star, m->pos.x, m->pos.y - g * 96.0f, m->pos.z);
            break;
        }
    } while (ctl->stat != 0);
    if (star >= 0) {
        func_80039ACC(tex);
        func_8002456C(star);
    }
    func_800FD170_StaffScene(s);
    func_800FCA8C_StaffScene(m);
    ctl->stat = -1;
    while (1) {
        HuPrcVSleep();
    }
}
void func_800FC480_StaffScene(void) {
    func_800178A0(1);
    func_80017660(0, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, D_800FE190_StaffScene[0], D_800FE190_StaffScene[1], D_800FE190_StaffScene[2]);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_800FC5B0_StaffScene), 0xA0);
}
void func_800FC554_StaffScene(StaffCamera* cam) {
    Center = cam->center;
    CRot = cam->rot;
    CZoom = cam->zoom;
    D_800FE190_StaffScene[0] = cam->fov;
}
void func_800FC5B0_StaffScene(omObjData* obj) {
    if (D_800FE19C_StaffScene != D_800FE190_StaffScene[0]) {
        func_8001D494(0, D_800FE190_StaffScene[0], D_800FE190_StaffScene[1], D_800FE190_StaffScene[2]);
        D_800FE19C_StaffScene = D_800FE190_StaffScene[0];
    }
    omOutView(obj);
}
void func_800FC624_StaffScene(s16* out, s16 camIdx, f32 x, f32 y, f32 z) {
    Mtx mtx;
    unk_Struct00* cam = &D_800C3110[camIdx];
    Mtx* view = (Mtx*)((u8*)&cam->unkF8 + D_800F3FA8 * 0x80) + 1;
    Mtx* m = &mtx;
    s16* vp;
    f32 sx;
    f32 sy;
    f32 sz;
    f32 a;
    f32 dist;

    guTranslate(m, x, y, z);
    guMtxCatL(m, view, m);
    sx = (s32)((MTX_HALF(&mtx, 12) << 16) | MTX_HALF(&mtx, 28)) >> 16;
    sy = (s32)((MTX_HALF(&mtx, 13) << 16) | MTX_HALF(&mtx, 29)) >> 16;
    sz = (s32)((MTX_HALF(&mtx, 14) << 16) | MTX_HALF(&mtx, 30)) >> 16;
    a = D_800C3110[camIdx].unk_40 * 0.008726646259971648;
    dist = sz * sinf(a);
    dist = fabsf(dist / cosf(a));
    if (dist != 0.0) {
        vp = (s16*)((u8*)&cam->unk58 + D_800F3FA8 * 16);
        out[0] = vp[0] / 4.0 * sx / dist / 1.3333333730697632 + vp[4] / 4.0;
        out[1] = vp[1] / 4.0 * -sy / dist + vp[5] / 4.0;
    }
}
void func_800FC864_StaffScene(void) {
    StaffModel* m = HuPrcCurrentGet()->user_data;
    s16 model = m->model;

    m->stat = 2;
    do {
        switch (m->cmd) {
        case 1:
            m->stat = 0;
            m->cmd = 0;
            break;
        case 2:
            m->stat = 2;
            m->cmd = 0;
            break;
        case 3:
            func_800258EC(model, 4, 4);
            m->stat = 2;
            m->cmd = 0;
            break;
        case 4:
            func_800258EC(model, 4, 0);
            m->stat = 2;
            m->cmd = 0;
            break;
        default:
            m->cmd = 0;
            break;
        }
        func_80025798(model, m->pos.x, m->pos.y, m->pos.z);
        func_80025830(model, m->scale.x, m->scale.y, m->scale.z);
        func_800257E4(model, m->rot.x, m->rot.y, m->rot.z);
        HuPrcVSleep();
    } while (m->stat != 0);
    func_8002456C(model);
    m->stat = -1;
    while (1) {
        HuPrcVSleep();
    }
}
StaffModel* func_800FC998_StaffScene(void) {
    StaffModel* m;
    s16 model;
    Process* p;

    m = func_80023684(sizeof(StaffModel), 0x7918);
    func_8009B770(m, 0, sizeof(StaffModel));
    model = LoadFormFile(0xA008A, 0x6A9);
    func_800258EC(model, 4, 4);
    func_80025EB4(model, 2, 2);
    func_80025F10(model, 1);
    m->model = model;
    m->pos.x = 0.0f;
    m->pos.y = 0.0f;
    m->pos.z = 0.0f;
    m->rot.x = 0.0f;
    m->rot.y = 0.0f;
    m->rot.z = 0.0f;
    m->scale.x = 1.0f;
    m->scale.y = 1.0f;
    m->scale.z = 1.0f;
    p = omAddPrcObj(func_800FC864_StaffScene, 0x3F00, 0x400, 0);
    m->proc = p;
    p->user_data = m;
    m->cmd = 4;
    return m;
}
void func_800FCA8C_StaffScene(StaffModel* m) {
    m->cmd = 1;
    while (m->stat != -1) {
        HuPrcVSleep();
    }
    EndProcess(m->proc);
    func_80023728(m);
}
// register/stack allocation (retail keeps one more float callee-saved; frame 184 vs 168)
#ifdef NON_MATCHING
void func_800FCAF4_StaffScene(void) {
    StaffSparkleDot* dots;
    Vec3f* pos;
    s32 life;
    u16 done;
    StaffSparkle* s;
    Vec3f* scale;
    StaffSparkleDot* d;
    s32 i;
    s32 n;
    s16 active;
    s32 active2;
    s16 cnt;
    s32 z;
    s16 st;
    u16 model;
    u16 first;
    u16 m2;
    f32 vel;
    f32 t;
    f32 dy;
    f32 sc;
    f32 ox;
    f32 oy;
    f32 oz;

    s = HuPrcCurrentGet()->user_data;
    switch (s->type) {
    case 1:
    case 2:
        n = 8;
        vel = -8.0f;
        life = 8;
        break;
    case 0:
        n = 16;
        vel = -5.0f;
        life = 16;
        break;
    case 3:
        n = 16;
        vel = -4.0f;
        life = 48;
        break;
    }
    dots = func_80023684(n * sizeof(StaffSparkleDot), 0x7918);
    pos = &s->target->pos;
    scale = &s->target->scale;
    for (i = 0, d = dots, t = 0.0f; i < n; i++, d++) {
        d->timer = t;
        t += (f32)life / n;
        d->angle = 0.0f;
        d->pos.x = 0.0f;
        d->pos.y = 0.0f;
        d->pos.z = 0.0f;
        if (i != 0) {
            m2 = func_80023FC8(first);
            d->model = m2;
        } else {
            m2 = LoadFormFile(0xA0138, 0x699);
            first = m2;
            d->model = m2;
        }
        func_800258EC(m2, 4, 4);
        func_80025EB4(m2, 2, 2);
        func_80025F10(m2, 1);
    }
    done = 0;
    active = 1;
    s->stat = 1;
    do {
        switch ((s16)s->cmd) {
        case 1:
            s->stat = 0;
        case 2:
            active = 0;
            done = 0;
            break;
        case 3:
            st = 1;
            goto set_stat;
        case 5:
            for (i = 0, d = dots; i < n; i++, d++) {
                if (d->model >= 0) {
                    func_800258EC(d->model, 4, 4);
                }
            }
            st = 1;
            goto set_stat;
        case 6:
            active = 0;
            done = 1;
            break;
        case 7:
            for (i = 0, d = dots, t = 0.0f; i < n; i++, d++) {
                d->timer = t;
                t += (f32)life / n;
            }
            active = 1;
        case 4:
            st = 2;
        set_stat:
            s->stat = st;
            break;
        }
        s->cmd = 0;
        if (s->stat >= 2) {
            dy = vel * scale->x;
            cnt = 0;
            for (i = 0, d = dots, active2 = active; i < n; i++, d++) {
                model = d->model;
                if (d->timer != 0) {
                    sc = func_800AEFD0(d->angle) * scale->x;
                    d->angle += 90.0f / life;
                    func_80025830(model, sc, sc, sc);
                    d->pos.y += dy;
                    func_80025798(model, d->pos.x, d->pos.y, d->pos.z);
                    d->timer--;
                    cnt++;
                } else if (active2 != 0) {
                    ox = (s32)((func_800FD2AC_StaffScene() % 200) - 100) * 0.5f * scale->x;
                    oz = (s32)((func_800FD2AC_StaffScene() % 200) - 100) * 0.5f * scale->z;
                    oy = ((s32)((func_800FD2AC_StaffScene() % 200) - 100) * 0.5f - 30.0f) * scale->y;
                    d->pos.x = ox + pos->x;
                    d->pos.y = oy + pos->y;
                    d->pos.z = oz + pos->z;
                    func_80025798(model, d->pos.x, d->pos.y, d->pos.z);
                    sc = scale->x;
                    func_80025830(model, sc, sc, sc);
                    d->timer = life - 1;
                    d->angle = 0.0f;
                    func_800258EC(model, 4, 0);
                } else {
                    func_800258EC(model, 4, 4);
                }
            }
            if ((z = (cnt == 0)) & (active ^ 1)) {
                s->stat = done;
                if (done != 0) {
                    active = 1;
                }
            }
        } else if (active == 0) {
            s->stat = 0;
        }
        HuPrcVSleep();
    } while (s->stat != 0);
    for (i = 0, d = dots; i < n; i++, d++) {
        if (d->model >= 0) {
            func_8002456C(d->model);
        }
    }
    func_80023728(dots);
    s->stat = -1;
    while (1) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_63_StaffScene/2A9CA0", func_800FCAF4_StaffScene);
#endif
StaffSparkle* func_800FD0F0_StaffScene(StaffModel* target, s16 type) {
    StaffSparkle* s;
    Process* p;

    s = func_80023684(sizeof(StaffSparkle), 0x7918);
    func_8009B770(s, 0, sizeof(StaffSparkle));
    s->type = type;
    s->target = target;
    p = omAddPrcObj(func_800FCAF4_StaffScene, 0x3F00, 0x800, 0);
    s->proc = p;
    p->user_data = s;
    return s;
}
void func_800FD170_StaffScene(StaffSparkle* s) {
    s->cmd = 1;
    while (s->stat != -1) {
        HuPrcVSleep();
    }
    EndProcess(s->proc);
    func_80023728(s);
}
u32 func_800FD1D8_StaffScene(u32 param) {
    s32 hi, lo;

    if (param == 0) {
        param = rand8();
        param = param ^ osGetCount();
        param ^= 0xD826BC89;
    }
    hi = param / 0x1F31D;
    lo = param - (hi * 0x1F31D);
    param = hi * 0xB14;
    param = param - lo * 0x41A7;
    return param;
}
u32 func_800FD2AC_StaffScene(void) {
    return D_800FE1A0_StaffScene = func_800FD1D8_StaffScene(D_800FE1A0_StaffScene);
}