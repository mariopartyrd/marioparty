#include "common.h"

#include "engine/esprite.h"

void func_8005B648(s8 vol, s16 time);
s16 func_80009E4C(s16 player, s16 limit, s8 x, s8 y);
void func_80060F04(s16, s16, s16, s16);
void func_80060440(s16, s16);
void func_8006035C(s16, s8);
void func_800594E4(s16, u16);
extern s8 ContStkY[];
#define HOUSE_ABS(x) ((x) < 0 ? -(x) : (x))
f32 func_80059E28(f32 a, f32 b);
void func_800F8324_MinigameHouse(void);
void func_800F8514_MinigameHouse(void);
void func_800F8540_MinigameHouse(s16);


void func_800191F8(u16);
void GMesSprKill(unkCommonStruct0*);
void func_800FC204_MinigameHouse(unkCommonStruct0* font, s16* ids, u16* sprs, s32 row, s32 mode);


void func_80021240(s16);
extern u8 D_800C5728[];
extern char D_80100658_MinigameHouse[7][0x18];


extern u8 D_800C5723;
extern u8 D_80100260_MinigameHouse[3][4];
extern u8 D_8010026C_MinigameHouse[5][4];
extern u16 ContDStkTrg[];


extern Vec3f D_801001E4_MinigameHouse[6];
extern Vec3f D_8010022C_MinigameHouse[4];
extern s32 D_8010025C_MinigameHouse;
extern s32 D_80100648_MinigameHouse[4];


void func_80059B74(s16);
s32 func_800FAF5C_MinigameHouse(s16);
s32 func_800FB108_MinigameHouse(s16);
void func_800FB238_MinigameHouse(void);
s32 func_800FA92C_MinigameHouse(s32*);
extern const char D_801002BC_MinigameHouse[]; /* "%d"; also used by func_800F8860 and func_800FD2D0 */
/* retail called func_8006D010 here as returning int: the result is extended at each use */
#define D010 ((s32 (*)(s16, s16, s16, s16, s32, s16))func_8006D010)


/* The head of 42E40.c's SpriteAnimWork (func_800429CC's result); no pointers before 0x10. */
typedef struct HouseSpriteAnim {
    /* 0x00 */ u16 flags;
    /* 0x02 */ s16 frame;
    /* 0x04 */ s16 count;
    /* 0x06 */ u16 attr;
    /* 0x08 */ s16 x;
    /* 0x0A */ s16 y;
} HouseSpriteAnim;

/* A minigame category for the completion counts: minigame ids (1-based) and their count. */
typedef struct HouseMgCat {
    /* 0x00 */ u8* list;
    /* 0x04 */ u8 count;
} HouseMgCat;

void* func_800429CC(s16, s16);
void func_80025C20(s16, s16, s16, s16, s16);
void func_8002888C(s16, s16);
void func_8005A258(s16);
extern HouseSpriteAnim* D_80100638_MinigameHouse[3];
extern HouseMgCat D_801001C4_MinigameHouse[4];


extern s8 D_800C5720;


/* A minigame group shown in the house: its title message, the minigame list (1-based ids) and the
   range of that list to show. */
typedef struct HouseMgGroup {
    /* 0x00 */ s32 msg;
    /* 0x04 */ u8* list;
    /* 0x08 */ u8 start;
    /* 0x09 */ u8 end;
} HouseMgGroup; /* 0x0C on the N64 */

void func_8009B960(void*, void*);
void func_8006DA5C(s16, void*, s8);
void func_80071788(s32, s16);
extern HouseMgGroup D_80100170_MinigameHouse[7];
extern char D_80100430_MinigameHouse[10][30];
extern s16 D_80100634_MinigameHouse;


s16 func_80059400(s16);
s16 func_8005949C(s16);
char* func_800F9D64_MinigameHouse(s32);
s16 func_8006D93C(u8*);
extern char D_80100410_MinigameHouse[0x20];
extern u16 D_80100100_MinigameHouse[];
extern u16 D_80100632_MinigameHouse;


void func_800F6F94_MinigameHouse(omObjData* arg0);
s32 func_8005A22C(s32);
void func_80027E48(s16 arg0, f32 arg1, f32 arg2, u16 arg3, u16 arg4, char* arg5, u8 arg6);
TextWindow* func_8006DD60(s16);
extern unk_Struct00* D_800C3110;
extern f32 D_801000FC_MinigameHouse;
extern omObjData* D_80100614_MinigameHouse;
extern omObjData* D_80100618_MinigameHouse;
extern omObjData* D_8010061C_MinigameHouse;
extern omObjData* D_80100620_MinigameHouse;
extern u8 D_80100624_MinigameHouse[10];
extern s16 D_8010062E_MinigameHouse;
extern s16 D_80100630_MinigameHouse;


void func_8003A060(Gfx** arg0, s32 timg, s32 fmt, s32 siz, s32 width, s32 height, s32 uls, s32 ult, s32 lrs, s32 lrt, s32 pal, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt);


/* Menu choice: target point, camera index, message. */
typedef struct HouseMenuEntry {
    /* 0x00 */ s8 pos;
    /* 0x01 */ s8 cam;
    /* 0x04 */ s32 msg;
} HouseMenuEntry;

s32 func_80059CB8(void);
s32 func_80059CE8(void* str, s16 win);
void func_800532E0(void);
void func_800532F4(void);
void func_8007FAC0(void);
void func_8004F8DC(void);
s16 func_80059C28(void);
s16 func_80060128(s32);
void func_800601D4(s32);
void func_800726AC(s16, s16);
s32 func_80072718(void);
void func_80070ED4(void);
void func_8005B244(void);
void func_8006EB40(s16);
void func_8006E288(s16, u8);
void func_8007F54C(void* code, u16* outbuf, u32 outbufWidth, u16* workbuf);

void func_800F6AD0_MinigameHouse(void);
void func_800F7274_MinigameHouse(s16, s16);
void func_800F7C6C_MinigameHouse(omObjData*);
void func_800F7DE0_MinigameHouse(omObjData*);
s16 func_800F8364_MinigameHouse(s32, s16);
void func_800F6BAC_MinigameHouse(void);
void func_800F7024_MinigameHouse(void);
void func_800F70E8_MinigameHouse(void);
void func_800F7BA0_MinigameHouse(void);
void func_800F7F50_MinigameHouse(void);
void func_800F8860_MinigameHouse(void);
void func_800FB2DC_MinigameHouse(void);
void func_800FB96C_MinigameHouse(omObjData*);
void func_800FD2D0_MinigameHouse(void);
void AdjustPlayerCoins(s32, s32);
void func_80018E0C(u16, s16);
s32 func_800115C8(s16);
void func_80042B10(void*);
void func_80043460(void);
void func_800434E4(void);
void func_80043544(void);
void func_800760E4(s16);
void GMesMaxWaitSet(s16);
extern u8 D_800C5724[];
void func_800FBB28_MinigameHouse(s32 port, s32 p, s16 spr);
s32 func_800FAE94_MinigameHouse(s32 cat);
s32 func_800FC410_MinigameHouse(void);
extern u16 ContBtn[];

extern s8 D_800C5721;
extern u8 D_800C5722;
extern u32 D_800F383C;
extern s16 D_800F384C;
extern u16 D_800F5144;
extern u8 D_800ECC22;
extern Vec3f* D_800ED610;
extern Vec3f* D_800ED72C;
extern s16 D_800F3B74;

/* .data */
extern Vec3f D_800FFEC0_MinigameHouse[];
extern Vec3f D_800FFF38_MinigameHouse[];
extern Vec3f D_800FFFB0_MinigameHouse[];
extern HouseMenuEntry D_800FFFEC_MinigameHouse[5];
extern s32 D_80100014_MinigameHouse;
extern s32 D_80100018_MinigameHouse;
extern s32 D_8010001C_MinigameHouse[];

/* .bss */
extern s16 D_8010055C_MinigameHouse; /* the message window */
extern Process* D_80100560_MinigameHouse;
extern omObjData* D_80100568_MinigameHouse[6];
extern s16 D_80100580_MinigameHouse;
extern u16 D_80100582_MinigameHouse[2];
extern s16 D_80100586_MinigameHouse;
extern u16 D_80100588_MinigameHouse[4];
extern u16* D_80100590_MinigameHouse;
extern s32 D_80100594_MinigameHouse;
extern unkCommonStruct0 D_80100598_MinigameHouse;
extern s16 D_801005AC_MinigameHouse[];
extern s16 D_80100600_MinigameHouse;
extern s16 D_80100602_MinigameHouse;
extern u16 D_80100604_MinigameHouse;
extern s32 D_80100608_MinigameHouse;
extern omObjData* D_8010060C_MinigameHouse;
extern u16* D_80100610_MinigameHouse;




extern u8 D_800C4E14[], D_800C4E24[], D_800C4E2C[], D_800C4E38[];

/* .data */
Vec3f D_800FFEC0_MinigameHouse[10] = {
    { 0.0f, 120.0f, 350.0f },
    { 0.0f, 110.0f, 300.0f },
    { 0.0f, 110.0f, 130.0f },
    { -13.0f, 160.0f, -77.0f },
    { -35.0f, 90.0f, -45.0f },
    { 0.0f, 110.0f, 130.0f },
    { -77.0f, 120.0f, 110.0f },
    { 100.0f, 120.0f, 180.5f },
    { 185.0f, 450.0f, -243.5f },
    { -20.5f, 160.0f, -77.0f },
};
Vec3f D_800FFF38_MinigameHouse[10] = {
    { 4.0f, 180.01f, 0.0f },
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, 180.0f, 0.0f },
    { 90.0f, 180.0f, 0.0f },
    { 0.0f, 180.0f, 0.0f },
    { 4.0f, 295.0f, 0.0f },
    { 9.0f, 315.0f, 0.0f },
    { 9.0f, 170.0f, 0.0f },
    { 90.0f, 170.0f, 0.0f },
    { 90.0f, 180.0f, 0.0f },
};
Vec3f D_800FFFB0_MinigameHouse[5] = {
    { 0.0f, 140.0f, -170.0f },
    { -25.0f, 85.0f, -85.0f },
    { 0.0f, 140.0f, 610.0f },
    { -170.0f, 80.0f, 200.0f },
    { 185.0f, 80.0f, -243.5f },
};
HouseMenuEntry D_800FFFEC_MinigameHouse[5] = {{ 0, 0, 0x3A }, { 4, 0, 0x82 }, { 2, 1, 0x3C }, { 3, 5, 0x70 }, { 1, 0, 0x3B } };
s32 D_80100014_MinigameHouse = 0;
s32 D_80100018_MinigameHouse = 0;
s32 D_8010001C_MinigameHouse[56] = {
    0xB001E, 0xB001F, 0xB0020, 0xB0021, 0xB0022, 0xB0023, 0xB0042, 0xB0025,
    0xB0042, 0xB0026, 0xB0027, 0xB0028, 0xB0029, 0xB002A, 0xB002B, 0xB002C,
    0xB002D, 0xB002E, 0xB002F, 0xB0030, 0xB0031, 0xB0032, 0xB0033, 0xB0034,
    0xB0035, 0xB0036, 0xB0037, 0xB0051, 0xB0039, 0xB003A, 0xB003B, 0xB003C,
    0xB003D, 0xB003E, 0xB003F, 0xB0040, 0xB0052, 0xB0042, 0xB0043, 0xB0044,
    0xB0045, 0xB0046, 0xB0047, 0xB0048, 0xB0049, 0xB004A, 0xB004B, 0xB004C,
    0xB001D, 0xB004D, 0xB004E, 0xB004F, 0xB0050, 0xB0053, 0xB0041, 0xB0038,
};
f32 D_801000FC_MinigameHouse = 0.0f;
u16 D_80100100_MinigameHouse[56] = {
    50, 0, 200, 150, 250, 200, 450, 300, 500, 350, 100, 100, 150, 150,
    400, 200, 400, 350, 50, 400, 50, 50, 200, 300, 450, 100, 50, 0,
    400, 200, 250, 250, 200, 300, 250, 350, 0, 450, 350, 150, 250, 50,
    300, 250, 400, 400, 300, 200, 0, 300, 100, 150, 50, 0, 50, 450,
};
HouseMgGroup D_80100170_MinigameHouse[7] = {
    { 0x46, D_800C4E38, 0, 10 },
    { 0x46, D_800C4E38, 10, 20 },
    { 0x46, D_800C4E38, 20, 25 },
    { 0x45, D_800C4E2C, 0, 10 },
    { 0x44, D_800C4E24, 0, 5 },
    { 0x43, D_800C4E14, 0, 10 },
    { 0x43, D_800C4E14, 10, 13 },
};
HouseMgCat D_801001C4_MinigameHouse[4] = { { D_800C4E38, 25 }, { D_800C4E2C, 10 }, { D_800C4E24, 5 }, { D_800C4E14, 10 } };
Vec3f D_801001E4_MinigameHouse[6] = {
    { -15.0f, 75.1f, -78.0f },
    { 1.5f, 75.1f, -73.0f },
    { 18.0f, 75.1f, -78.0f },
    { -15.0f, 75.1f, -58.0f },
    { 1.5f, 75.1f, -53.0f },
    { 18.0f, 75.1f, -58.0f },
};
Vec3f D_8010022C_MinigameHouse[4] = {
    { -48.0f, 75.1f, -55.0f },
    { -40.0f, 75.1f, -55.0f },
    { -32.0f, 75.1f, -55.0f },
    { -24.0f, 75.1f, -55.0f },
};
s32 D_8010025C_MinigameHouse = 0;
u8 D_80100260_MinigameHouse[3][4] = { { 0, 0, 1, 1 }, { 0, 1, 0, 1 }, { 0, 1, 1, 0 } };
u8 D_8010026C_MinigameHouse[5][4] = { { 0, 1, 1, 1 }, { 1, 0, 1, 1 }, { 1, 1, 0, 1 }, { 1, 1, 1, 0 }, { 0, 0, 0, 0 } };

void func_800F65E0_MinigameHouse(void) {
    s32 i;
    s32 var_a0;

    InitCameras(1);
    omInitObjMan(0x20, 8);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80059EBC), 0xA0);
    D_800F384C = 0;
    func_8006CEA0();
    func_8004F8DC();
    D_80100608_MinigameHouse = func_8004F954(0x2B, 0x20);
    func_8004FA90(D_80100608_MinigameHouse, 1.0f, 1.0f, 1.0f);
    func_8007FAC0();
    D_80100590_MinigameHouse = func_80023684(0x1040, 0x7918);
    func_800532E0();
    func_800F7BA0_MinigameHouse();
    func_800F7F50_MinigameHouse();
    D_80100580_MinigameHouse = InitSprite(0x9004B);
    for (i = 0; i < 2; i++) {
        D_80100582_MinigameHouse[i] = func_80019060(D_80100580_MinigameHouse, 0, 1);
        func_80018C90(D_80100582_MinigameHouse[i]);
        func_80018D84(D_80100582_MinigameHouse[i], 0xFFF0);
    }
    func_800674BC(D_800ED60C[(s16)D_80100582_MinigameHouse[1]].unk_04, 0, 1);
    D_80100586_MinigameHouse = InitSprite(0x90024);
    for (i = 0; i < 4; i++) {
        D_80100588_MinigameHouse[i] = func_80019060(D_80100586_MinigameHouse, 0, 1);
        func_80018C90(D_80100588_MinigameHouse[i]);
        func_80018D84(D_80100588_MinigameHouse[i], 0xFFF0);
    }
    func_8007B168("\x82\x4F\x82\x60", 0);
    D_80100602_MinigameHouse = InitSprite(0xA0013);
    D_80100604_MinigameHouse = func_80019060(D_80100602_MinigameHouse, 0, 1);
    SetBasicSpriteSize(D_80100604_MinigameHouse, 0.5f, 0.5f);
    SetBasicSpritePos(D_80100604_MinigameHouse, 0x20, 0x18);
    D_80100600_MinigameHouse = GMesFontCreate(&D_80100598_MinigameHouse, "00000", 0, -1, -1);
    omAddObj(1, 0, 0, -1, &func_800F6AD0_MinigameHouse);
    func_80066DC4(D_801005AC_MinigameHouse[D_80100600_MinigameHouse], 0, 0x4C, 0x18);
    for (i = 0; i < 6; i++) {
        D_80100568_MinigameHouse[i] = omAddObj(1, 1, 1, -1, &func_800FB96C_MinigameHouse);
    }
    D_80100560_MinigameHouse = omAddPrcObj(func_800F6BAC_MinigameHouse, 0xA, 0, 0);
    SetFadeInTypeAndTime(0xFF, 8);
    D_80100594_MinigameHouse = func_8005AF60();
    if (D_80100594_MinigameHouse == 0) {
        D_80100594_MinigameHouse = 1;
    }
    if (D_800C5721 == 0) {
        D_8010055C_MinigameHouse = func_80059C28();
    }
    var_a0 = 7;
    if (D_800C5721 == 1 && !(D_800C5722 & 0x80)) {
        var_a0 = 0x13;
    }
    func_80060128(var_a0);
}
void func_800F6970_MinigameHouse(s32 arg0) {
    D_800ED610 = &D_800FFEC0_MinigameHouse[arg0];
    D_800ED72C = &D_800FFF38_MinigameHouse[arg0];
}
void func_800F69A8_MinigameHouse(void) {
    ShowBasicSprite(D_80100582_MinigameHouse[0]);
    ShowBasicSprite(D_80100582_MinigameHouse[1]);
}
void func_800F69DC_MinigameHouse(void) {
    func_80018C90(D_80100582_MinigameHouse[0]);
    func_80018C90(D_80100582_MinigameHouse[1]);
}
void func_800F6A10_MinigameHouse(s16 arg0, s32 arg1, s16 arg2) {
    SetBasicSpritePos(D_80100582_MinigameHouse[0], arg1 - ((D_800F383C & 0xC) >> 2) - 8, arg2);
    SetBasicSpritePos(D_80100582_MinigameHouse[1], arg1 + ((D_800F383C & 0xC) >> 2) + 8 + arg0 * 11, arg2);
}
void func_800F6AD0_MinigameHouse(void) {
    s32 i;
    s32 var_s0;
    s32 var_s1;

    var_s1 = 0x2710;
    var_s0 = GwCommon.coinNum;

    for (i = 1; i < 6; i++) {
        func_80067208(D_801005AC_MinigameHouse[D_80100600_MinigameHouse], i, D_800F3B74, var_s0 / var_s1);
        var_s0 = var_s0 % var_s1;
        var_s1 /= 0xA;
    }
}
void func_800F6BAC_MinigameHouse(void) {
    Vec2f pos;
    s32 prevMsg;
    s32 cur;
    s32 prevCam;
    s32 spr;
    u32 btn;

    prevMsg = -1;
    cur = 0;
    prevCam = 0;
    if (D_800C5721 != 0) {
        prevCam = -1;
        func_800FD2D0_MinigameHouse();
        D_800F384C = 0;
        cur = 4;
        HuPrcVSleep();
    }
    spr = func_80019060((s16)InitSprite(0x85), 1, 1);
    ShowBasicSprite((u16)spr);
    func_80018D84((u16)spr, 0xFFF0);
    while (1) {
        btn = func_80059CB8();
        D_800ECC22 = 1;
        if (btn & 0x8000) {
            D_800F384C = 0;
            D_800ECC22 = 0;
            PlaySound(0xF6);
            func_80018C90((u16)spr);
            switch (cur) {
            case 0:
                func_800FB2DC_MinigameHouse();
                break;
            case 1:
                func_800F70E8_MinigameHouse();
                break;
            case 4:
                func_800FD2D0_MinigameHouse();
                break;
            case 3:
                func_800F8860_MinigameHouse();
                break;
            case 2:
                if (func_80059CE8((void*)0x3D, D_8010055C_MinigameHouse) != 0) {
                    func_80025EB4(D_8010060C_MinigameHouse->model[0], 1, 0);
                    HuPrcSleep(15);
                    D_800F5144 = 1;
                    while (1) {
                        HuPrcVSleep();
                    }
                }
                break;
            }
            if (D_800F5144 != 1) {
                prevMsg = -1;
                prevCam = -1;
                ShowBasicSprite((u16)spr);
            }
        }
        if ((btn >> 14) & 1 & (cur != 2)) {
            PlaySound(0xF8);
            cur = 2;
        }
        if (func_8006FCC0(D_8010055C_MinigameHouse) == 0) {
            if (btn & 0x900) {
                cur++;
                if (cur == 3) {
                    cur += (_CheckFlag(0x1F) == 0);
                }
                if (cur >= 5) {
                    cur = 0;
                }
            }
            if (btn & 0x600) {
                cur--;
                if (cur == 3) {
                    cur -= (_CheckFlag(0x1F) == 0);
                }
                if (cur < 0) {
                    cur = 4;
                }
            }
        }
        if (prevMsg != D_800FFFEC_MinigameHouse[cur].msg) {
            if (prevMsg != -1) {
                PlaySound(0xF5);
            }
            func_8006EB40(D_8010055C_MinigameHouse);
            func_8006E288(D_8010055C_MinigameHouse, 7);
            LoadStringIntoWindow(D_8010055C_MinigameHouse, (void*)(s32)D_800FFFEC_MinigameHouse[cur].msg, -1, -1);
        }
        prevMsg = D_800FFFEC_MinigameHouse[cur].msg;
        if (prevCam != D_800FFFEC_MinigameHouse[cur].cam) {
            func_800F6970_MinigameHouse(D_800FFFEC_MinigameHouse[cur].cam);
            D_800F384C = btn;
        }
        prevCam = D_800FFFEC_MinigameHouse[cur].cam;
        Convert3DTo2D(0, &D_800FFFB0_MinigameHouse[D_800FFFEC_MinigameHouse[cur].pos], &pos);
        SetBasicSpritePos((u16)spr, pos.x - 24.0f, pos.y);
        if (!(D_80100018_MinigameHouse & 0x3F)) {
            func_8004F9F4(D_80100608_MinigameHouse, -35.5f, 90.0f, -60.0f, 4);
        }
        D_80100018_MinigameHouse++;
        HuPrcVSleep();
    }
}
void func_800F6F94_MinigameHouse(omObjData* arg0) {
    if (D_800F5144 != 0 || D_80100014_MinigameHouse != 0) {
        func_800601D4(0x1E);
        if (D_80100014_MinigameHouse == 2) {
            func_80072724(0, 0, 0);
        } else {
            func_80072724(0xFF, 0xFF, 0xFF);
        }
        func_800726AC(0, 4);
        arg0->func_ptr = &func_800F7024_MinigameHouse;
    }
}
void func_800F7024_MinigameHouse(void) {
    if (func_80072718() == 0) {
        func_800532F4();
        func_80070ED4();
        ClearBoardFeatureFlag(0x30);
        func_8005B244();
        switch (D_80100014_MinigameHouse) {
        case 1:
            SetBoardFeatureFlag(0x30);
            omOvlCallEx(0x6F, 0, 0x94);
            break;
        case 2:
            ClearBoardFeatureFlag(0x29);
            GwSystem.curBoardIndex = 9;
            omOvlCallEx(0x6A, 3, 0x91);
            break;
        default:
            ClearBoardFeatureFlag(0x29);
            omOvlReturnEx(1);
            break;
        }
    }
}
void func_800F70E8_MinigameHouse(void) {
    Vec3f center;
    Vec3f rot;
    s32 i;

    func_800F6970_MinigameHouse(7);
    if (func_80059CE8((void*)0x83, D_8010055C_MinigameHouse) != 0) {
        func_800F6970_MinigameHouse(8);
        HuPrcSleep(0x1E);
        func_80070D90(D_8010055C_MinigameHouse);
        rot.x = CRot.x;
        rot.y = CRot.y;
        rot.z = CRot.z;
        center.x = Center.x;
        center.y = Center.y;
        center.z = Center.z;
        PlaySound(0);
        for (i = 0; i < 40; i++) {
            center.y -= 10.0f;
            rot.y += 5.0f;
            D_800ED610 = &center;
            D_800ED72C = &rot;
            HuPrcVSleep();
        }
        D_80100014_MinigameHouse = 2;
        while (1) {
            HuPrcVSleep();
        }
    }
}
void func_800F7218_MinigameHouse(s16 arg0) {
    void* data;

    data = DataRead(D_8010001C_MinigameHouse[arg0]);
    func_8007F54C(data, D_80100610_MinigameHouse, 0xA0, D_80100590_MinigameHouse);
    DataClose(data);
}
// loop-invariant hoisting as in ovl_6F's twin func_800F94E8: retail hoists 32.0f/255 only to the inner loop and keeps 2^31 inline (masked 62)
#ifdef NON_MATCHING
void func_800F7274_MinigameHouse(s16 model, s16 idx) {
    Gfx* gfx;
    void* data;
    unk2C0C0StructC0* mdl;
    unk2C0C0Struct30* mesh;
    Vtx* vtx;
    Vtx* vtxStart;
    s16 i;
    s16 j;
    s16 k;
    s16 h;
    s32 w;
    f32 minX;
    f32 maxX;
    f32 minY;
    f32 maxY;
    f32 rangeX;
    f32 rangeY;
    f32 baseX;
    f32 baseY;
    f32 x;
    f32 y;
    f32 sLo;
    f32 sHi;
    f32 tLo;
    f32 tHi;

    data = DataRead(D_8010001C_MinigameHouse[idx]);
    w = 160;
    h = 128;
    D_80100610_MinigameHouse = func_80023684(0xA000, 0x7918);
    func_8007F54C(data, D_80100610_MinigameHouse, 160, D_80100590_MinigameHouse);
    DataClose(data);
    mdl = D_800F2B7C[model].unk_6C;
    mesh = mdl->unk_80;
    vtx = func_80023684(0x500, 0x7918);
    mdl->unk_00[0] = gfx = func_80023684(0x200 * sizeof(Gfx), 0x7918); /* 0x1000 on N64; host Gfx is 16 bytes */
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(gfx++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    gSPClearGeometryMode(gfx++, G_LIGHTING);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);

    maxY = maxX = -100000.0f;
    minY = minX = 100000.0f;
    for (i = 0; i < (s16) mesh->unk_04; i++) {
        for (j = 0; j < mesh->unk_34[i].unk_00; j++) {
            k = mesh->unk_34[i].unk_04[j];
            x = mdl->unk_78[k].unk_00;
            if (x < minX) {
                minX = x;
            }
            x = mdl->unk_78[k].unk_00;
            if (maxX < x) {
                maxX = x;
            }
            y = mdl->unk_78[k].unk_02;
            if (y < minY) {
                minY = y;
            }
            y = mdl->unk_78[k].unk_02;
            if (maxY < y) {
                maxY = y;
            }
        }
    }
    rangeX = maxX - minX;
    rangeY = maxY - minY;
    baseX = minX;
    baseY = minY;
    vtxStart = vtx;
    for (i = 0; i < (s16) mesh->unk_04; i++) {
        maxY = maxX = -100000.0f;
        minY = minX = 100000.0f;
        for (j = 0; j < mesh->unk_34[i].unk_00; j++) {
            k = mesh->unk_34[i].unk_04[j];
            x = (vtx->v.ob[0] = mdl->unk_78[k].unk_00);
            y = (vtx->v.ob[1] = mdl->unk_78[k].unk_02);
            vtx->v.ob[2] = mdl->unk_78[k].unk_04;
            if (x < minX) {
                minX = x;
            }
            if (maxX < x) {
                maxX = x;
            }
            if (y < minY) {
                minY = y;
            }
            if (maxY < y) {
                maxY = y;
            }
            vtx->v.cn[0] = vtx->v.cn[1] = vtx->v.cn[2] = -1;
            x = w * ((x - baseX) / rangeX);
            y = h * ((-y - baseY) / rangeY);
            vtx->v.tc[0] = x * 32.0f;
            vtx->v.tc[1] = y * 32.0f;
            vtx->v.cn[3] = 0xFF;
            vtx++;
        }
        sLo = ((minX - baseX) / rangeX) * w;
        sHi = ((maxX - baseX) / rangeX) * w;
        tLo = h - ((minY - baseY) / rangeY) * h;
        tHi = h - ((maxY - baseY) / rangeY) * h;
        gDPSetTextureLUT(gfx++, G_TT_NONE);
        func_8003A060(&gfx, (s32) D_80100610_MinigameHouse, G_IM_FMT_RGBA, G_IM_SIZ_16b, w, h, (u32) sLo, (u32) tHi,
                      (u32) sHi, (u32) tLo, 0, 2, 2, 0, 0, 0, 0);
        gSPVertex(gfx++, vtxStart, mesh->unk_34[i].unk_00, 0);
        if (mesh->unk_34[i].unk_00 == 3) {
            gSP1Triangle(gfx++, 0, 1, 2, 0);
        } else {
            gSP1Quadrangle(gfx++, 0, 1, 2, 3, 0);
        }
        vtxStart = vtx;
    }
    gSPEndDisplayList(gfx++);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800F7274_MinigameHouse);
#endif
void func_800F7B00_MinigameHouse(omObjData* arg0) {
    arg0->model[0] = func_800174C0(0x90045, 0x2D9);
    func_80025EB4(arg0->model[0], 1, 1);
    arg0->model[1] = func_800174C0(0x90043, 0x202B9);
    func_80025798(arg0->model[1], -17.0f, 0.0f, 0.0f);
    func_80025EB4(arg0->model[1], 1, 1);
    arg0->func_ptr = &func_800F6F94_MinigameHouse;
}
void func_800F7BA0_MinigameHouse(void) {
    CRot.x = 0.0f;
    CRot.y = 180.0f;
    CRot.z = 0.0f;
    Center.x = 0.0f;
    Center.y = 110.0f;
    Center.z = 700.0f;
    D_800C3110->unk_44 = 10.0f;
    if (D_800C5721 != 0) {
        func_800F6970_MinigameHouse(4);
    } else {
        func_800F6970_MinigameHouse(0);
    }
    func_8002890C(0xFF, 0xFF, 0xFF);
    D_8010060C_MinigameHouse = omAddObj(0x2710, 2, 0, -1, &func_800F7B00_MinigameHouse);
}
void func_800F7C6C_MinigameHouse(omObjData* arg0) {
    TextWindow* win;
    f32 angle;

    func_80027E48(arg0->model[0], D_801000FC_MinigameHouse, 0, 0x40, 0x40, "36t_002", 0);
    D_801000FC_MinigameHouse += 0.5f;
    if (D_801000FC_MinigameHouse > 64.0f) {
        D_801000FC_MinigameHouse -= 64.0f;
    }
    angle = func_800B0CD8(arg0->trans.y + 20.0f - Center.y, arg0->trans.z - Center.z);
    func_800257E4(arg0->model[1], 180.0f - angle, 0.0f, 0.0f);
    win = arg0->unk_50;
    if (win != NULL) {
        if ((s8)arg0->work[0] != win->unk_11) {
            if (D_80100624_MinigameHouse[win->unk_11] != 0) {
                func_800258EC(arg0->model[1], 4, 0);
                func_800F7218_MinigameHouse(D_80100624_MinigameHouse[win->unk_11] - 1);
            } else {
                func_800258EC(arg0->model[1], 4, 4);
            }
        }
        arg0->work[0] = win->unk_11;
    }
}
// float register allocation f0/f2 for scale (masked 0, raw 16); tried scale += 1.0f, declaration order, split mul
#ifdef NON_MATCHING
void func_800F7DE0_MinigameHouse(omObjData* arg0) {
    s32 v;
    u8 t;
    f32 scale;

    arg0->work[0]++;
    if (arg0->work[0] >= 0x5B) {
        arg0->work[0] = 0;
        arg0->work[1] = 12;
        arg0->work[2] = rand8() & 1;
    }
    if (arg0->work[1] != 0) {
        arg0->work[1]--;
        if (arg0->work[2] != 0) {
            v = arg0->work[1];
            if (v < 6U) {
                scale = v * 0.02f;
            } else {
                scale = (12 - v) * 0.02f;
            }
        } else {
            t = arg0->work[1] % 6;
            if (t < 3) {
                scale = t;
            } else {
                scale = 6 - t;
            }
            scale *= 0.04f;
        }
        arg0->scale.y = scale + 1.0f;
    } else {
        arg0->scale.x = arg0->scale.y = arg0->scale.z = 1.0f;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800F7DE0_MinigameHouse);
#endif
void func_800F7F50_MinigameHouse(void) {
    omObjData* obj;
    s32 idx;

    obj = omAddObj(1, 1, 3, -1, NULL);
    D_80100614_MinigameHouse = obj;
    obj->model[0] = LoadFormFile(0x90048, 0x202B9);
    obj->motion[0] = func_80025E48(obj->model[0]);
    obj->motion[1] = func_8005A22C(0x90049);
    obj->motion[2] = func_8005A22C(0x9004A);
    func_80025EB4(obj->model[0], 2, 2);
    obj->trans.x = 0.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = -180.0f;

    obj = omAddObj(1, 1, 0, -1, NULL);
    D_80100618_MinigameHouse = obj;
    obj->model[0] = func_800174C0(0x90044, 0x20299);
    func_800258EC(obj->model[0], 4, 4);
    obj->trans.x = 35.5f;
    obj->trans.y = 75.5f;
    obj->trans.z = -77.5f;

    obj = omAddObj(1, 2, 0, -1, &func_800F7C6C_MinigameHouse);
    D_8010061C_MinigameHouse = obj;
    obj->model[0] = func_800174C0(0x90046, 0x2B9);
    func_80026040(obj->model[0]);
    obj->trans.x = -35.5f;
    obj->trans.y = 68.0f;
    obj->trans.z = -85.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 0.5f;
    omSetStatBit(obj, 0xA0);
    obj->unk_50 = NULL;
    obj->work[0] = 0xFF;
    obj->model[1] = LoadFormFile(0x90010, 0x2C9);
    func_80025830(obj->model[1], 0.06f, 0.06f, 0.06f);
    func_80025798(obj->model[1], obj->trans.x, obj->trans.y + 20.0f, obj->trans.z);
    idx = GwSystem.unk_1E;
    if (idx > 0) {
        func_800F7274_MinigameHouse(obj->model[1], idx);
    } else {
        idx = 0;
        func_800F7274_MinigameHouse(obj->model[1], idx);
    }
    if (D_800C5721 == 0) {
        func_800258EC(obj->model[1], 4, 4);
    }

    obj = omAddObj(1, 1, 0, -1, &func_800F7DE0_MinigameHouse);
    obj->model[0] = LoadFormFile(0x90050, 0x202B9);
    obj->work[0] = obj->work[1] = 0;
    if (_CheckFlag(0x1F) != 0) {
        obj = omAddObj(1, 1, 2, -1, NULL);
    D_80100620_MinigameHouse = obj;
        obj->model[0] = func_800174C0(0x9004E, 0x2A9);
        func_80025EB4(obj->model[0], 1, 1);
        obj->motion[0] = func_80025E48(obj->model[0]);
        obj->motion[1] = func_8005A22C(0x9004F);
        obj->trans.x = -170.0f;
        obj->trans.y = 73.0f;
        obj->trans.z = 200.0f;
        obj->scale.x = obj->scale.y = obj->scale.z = 0.3f;
        obj->rot.x = 0.0f;
        obj->rot.y = 90.0f;
        obj->rot.z = 0.0f;
    }
}
void func_800F8324_MinigameHouse(void) {
    void* data;

    data = DataRead(0x87);
    D_8010062E_MinigameHouse = func_800678A4(data);
    DataClose(data);
}
// decomp-permuter
s16 func_800F8364_MinigameHouse(s32 arg0, s16 arg1)
{
  s16 i;
  short new_var;
  s16 x;
  s16 win;
  D_80100630_MinigameHouse = (win = func_80064EF4(7, 5));
  new_var = win;
  func_80067208(new_var, 0, D_8010062E_MinigameHouse, 0);
  func_80067480(new_var, 0, 0xFFFF);
  func_800674BC(new_var, 0, 0x8000);
  func_80066DC4(new_var, 0, arg0 - 0x10, arg1);
  func_80067384(new_var, 0, 1);
  x = 4;
  for (i = 1; i < 7; i++)
  {
    func_80067384(new_var, i, 1);
    func_80067208(new_var, i, D_8010062E_MinigameHouse, 0);
    func_80066DC4(new_var, i, x, 0);
    func_80067480(new_var, i, 0xFFFF);
    func_800674BC(new_var, i, 0x8000);
    if (i == 3)
    {
      x += 8;
    }
    else
    {
      x += 12;
    }
    func_80067598(new_var, i, 0);
  }

  func_80067480(new_var, 2, 0x8000);
  return new_var;
}
void func_800F8514_MinigameHouse(void) {
    func_80064D38(D_80100630_MinigameHouse);
    func_80067704(D_8010062E_MinigameHouse);
}
void func_800F8540_MinigameHouse(s16 arg0) {
    s16 sec;
    s16 hund;

    func_80067480(D_80100630_MinigameHouse, 0, 0x8000);
    func_800672DC(D_80100630_MinigameHouse, 0, arg0 / 1800, 0);
    func_800672B0(D_80100630_MinigameHouse, 0, 1);
    arg0 %= 1800;
    func_80067480(D_80100630_MinigameHouse, 1, 0x8000);
    func_800672DC(D_80100630_MinigameHouse, 1, 10, 0);
    func_800672B0(D_80100630_MinigameHouse, 1, 1);
    func_80067480(D_80100630_MinigameHouse, 2, 0x8000);
    func_800672DC(D_80100630_MinigameHouse, 2, arg0 / 300, 0);
    func_800672B0(D_80100630_MinigameHouse, 2, 1);
    arg0 %= 300;
    sec = arg0 / 30;
    func_80067480(D_80100630_MinigameHouse, 3, 0x8000);
    func_800672DC(D_80100630_MinigameHouse, 3, sec, 0);
    func_800672B0(D_80100630_MinigameHouse, 3, 1);
    hund = (arg0 * 100) / 30 - sec * 100;
    func_80067480(D_80100630_MinigameHouse, 4, 0x8000);
    func_800672DC(D_80100630_MinigameHouse, 4, 11, 0);
    func_800672B0(D_80100630_MinigameHouse, 4, 1);
    func_80067480(D_80100630_MinigameHouse, 5, 0x8000);
    func_800672DC(D_80100630_MinigameHouse, 5, hund / 10, 0);
    func_800672B0(D_80100630_MinigameHouse, 5, 1);
    hund %= 10;
    func_80067480(D_80100630_MinigameHouse, 6, 0x8000);
    func_800672DC(D_80100630_MinigameHouse, 6, hund, 0);
    func_800672B0(D_80100630_MinigameHouse, 6, 1);
}
// first C draft (masked 349): retail caches the pad port, ladders the result message with jumps, and allocates floats differently; call/constant sequence checked against the asm
#ifdef NON_MATCHING
void func_800F8860_MinigameHouse(void) {
    Vec3f rotv;
    char buf[8];
    char buf2[8];
    s16 sprA;
    u16 a;
    s16 sprB;
    s32 b;
    s32 win;
    s32 w2;
    TextWindow* tw;
    s32 rec;
    s32 i;
    s32 t;
    s32 x;
    s32 y;
    s16 dir;
    s16 r;
    s32 timer;
    s32 snd;
    s32 snd2;
    s32 turns;
    s32 vol;
    s32 pitch;
    f32 startAng;
    f32 curAng;
    f32 diff;
    f32 s;
    f32 sway;
    f32 spd;
    f32 bob;
    f32 ang;
    f32 fall;
    f32 spin;
    f32 radius;
    f32 px;
    f32 pz;
    s32 msg;

    snd = -1;
    func_800F6970_MinigameHouse(6);
    win = func_8006D010(0xC8, 0x4C, 0x60, 0x5A, 0, 0);
    func_8006E070(win, 0);
    rec = func_800594FC(4);
    sprintf(buf, "0\\%02d[%02d", rec / 30, ((rec % 30) * 100) / 30);
    func_8006DA5C(win, buf, 0);
    t = rec - 10;
    if (t < 0) {
        t = 0;
    }
    sprintf(buf2, "%2d", t / 4);
    func_8006DA5C(win, buf2, 1);
    LoadStringIntoWindow(win, (void*)0x73, -1, -1);
    if (func_80059CE8((void*)0x71, D_8010055C_MinigameHouse) == 0) {
        func_80070D90(win);
        return;
    }
    func_80070D90(win);
    func_8005B648(0x5A, 0x12);
    func_8006EB40(D_8010055C_MinigameHouse);
    LoadStringIntoWindow(D_8010055C_MinigameHouse, (void*)0x72, -1, -1);
    for (i = 0; i < 10; i++) {
        D_80100620_MinigameHouse->rot.x += 2.0f;
        HuPrcVSleep();
    }
    while (func_8006FCC0(D_8010055C_MinigameHouse) != 0) {
        HuPrcVSleep();
    }
    GMesCreate(0);
    while (GMesStatAllGet() != 0) {
        HuPrcVSleep();
    }
    GMesCreate(8, 0xA, 0x80, 0x20);

    /* wait for the stick to start turning, then count quarter turns for 300 frames */
    turns = 0;
    while ((dir = func_80009E4C(GwPlayer[0].port, 1, ContStkX[GwPlayer[0].port], ContStkY[GwPlayer[0].port])) == 0) {
        HuPrcVSleep();
    }
    startAng = func_800B0CD8(ContStkY[GwPlayer[0].port], ContStkX[GwPlayer[0].port]);
    if (HOUSE_ABS(dir) == 1) {
        dir *= 2;
    }
    func_80025EB4(D_80100620_MinigameHouse->model[0], 2, 2);
    timer = 0;
    func_800603F0(0x7F);
    for (i = 0; i < 300; i++) {
        r = func_80009E4C(GwPlayer[0].port, 8, ContStkX[GwPlayer[0].port], ContStkY[GwPlayer[0].port]);
        curAng = func_800B0CD8(ContStkY[GwPlayer[0].port], ContStkX[GwPlayer[0].port]);
        if (HOUSE_ABS(r) == 2) {
            if (dir == r) {
                turns += 4;
                func_80060F04(0, 5, 0, 5);
                timer = 16;
                snd = PlaySound(0x28);
                func_80025EB4(D_80100620_MinigameHouse->model[0], 1, 2);
            }
            dir = r;
        }
        timer--;
        D_80100620_MinigameHouse->trans.y = (turns & 1) * 0.5f + 73.0f;
        if (timer < 0) {
            func_80025EB4(D_80100620_MinigameHouse->model[0], 1, 1);
            if ((s16)snd != -1) {
                func_8006071C(snd);
                snd = -1;
            }
        }
        func_80079078(10 - i / 30);
        HuPrcVSleep();
    }
    if (dir <= 0) {
        diff = startAng - curAng;
    } else {
        diff = curAng - startAng;
    }
    while (diff < 0.0f) {
        diff += 360.0f;
    }
    turns += (s32)(diff / 90.0f);
    if ((s16)snd != -1) {
        func_8006071C(snd);
    }
    func_80025EB4(D_80100620_MinigameHouse->model[0], 1, 1);
    func_80079078(0);
    func_800790C0();
    func_80070D90(D_8010055C_MinigameHouse);

    /* the scale bounce */
    s = D_80100620_MinigameHouse->scale.x;
    for (i = 0; i < 10; i++) {
        D_80100620_MinigameHouse->rot.x -= 2.0f;
        if (i >= 5) {
            s -= 0.025f;
        } else {
            s += 0.025f;
        }
        D_80100620_MinigameHouse->scale.x = D_80100620_MinigameHouse->scale.y = D_80100620_MinigameHouse->scale.z = s;
        HuPrcVSleep();
    }
    for (i = 0; i < 8; i++) {
        if (i < 4) {
            s += 0.015f;
        } else {
            s -= 0.015f;
        }
        D_80100620_MinigameHouse->scale.x = D_80100620_MinigameHouse->scale.y = D_80100620_MinigameHouse->scale.z = s;
        HuPrcVSleep();
    }
    for (i = 0; i < 6; i++) {
        if (i < 3) {
            s += 0.01f;
        } else {
            s -= 0.01f;
        }
        D_80100620_MinigameHouse->scale.x = D_80100620_MinigameHouse->scale.y = D_80100620_MinigameHouse->scale.z = s;
        HuPrcVSleep();
    }
    D_80100620_MinigameHouse->scale.x = D_80100620_MinigameHouse->scale.y = D_80100620_MinigameHouse->scale.z = 0.3f;
    func_800F8324_MinigameHouse();
    func_800F8364_MinigameHouse(0xF0, 0x20);
    func_800F8540_MinigameHouse(0);
    for (i = 0; i < 20; i++) {
        D_80100620_MinigameHouse->trans.y = (i & 1) * 0.5f + 73.0f;
        HuPrcVSleep();
    }

    /* the spin: one frame per counted quarter turn (plus 11) */
    snd2 = PlaySound(0x29);
    func_80025C20(D_80100620_MinigameHouse->model[0], D_80100620_MinigameHouse->motion[1], 0, 10, 2);
    sway = -8.0f;
    spd = 10.0f;
    bob = 0.0f;
    ang = 295.0f;
    for (i = 0; i < turns + 11; i++) {
        if (i & 0x10) {
            sway -= 1.0f;
        } else {
            sway += 1.0f;
        }
        spd -= 0.6f;
        if (spd < 10.0f) {
            spd = 48.4f;
        }
        D_80100620_MinigameHouse->rot.x = (spd - D_80100620_MinigameHouse->rot.x) / 10.0f + D_80100620_MinigameHouse->rot.x;
        D_80100620_MinigameHouse->rot.y = func_80059E28(ang + 90.0f + sway / 2.0f, D_80100620_MinigameHouse->rot.y) / 10.0f + D_80100620_MinigameHouse->rot.y;
        D_80100620_MinigameHouse->rot.z = (sway - D_80100620_MinigameHouse->rot.z) / 10.0f + D_80100620_MinigameHouse->rot.z;
        bob += 0.3f;
        if (bob > 19.2f) {
            bob = 0.0f;
        }
        func_80060440(snd2, (s32)(bob * 31.25f) - 600);
        radius = sway + 100.0f;
        px = func_800AEAC0(ang) * radius;
        pz = func_800AEFD0(ang) * radius + 130.0f;
        D_80100620_MinigameHouse->trans.x = (px - D_80100620_MinigameHouse->trans.x) / 12.0f + D_80100620_MinigameHouse->trans.x;
        D_80100620_MinigameHouse->trans.y = (bob + 73.0f - D_80100620_MinigameHouse->trans.y) / 5.0f + D_80100620_MinigameHouse->trans.y;
        ang += 1.0f;
        D_80100620_MinigameHouse->trans.z = (pz - D_80100620_MinigameHouse->trans.z) / 12.0f + D_80100620_MinigameHouse->trans.z;
        if (ang > 360.0f) {
            ang -= 360.0f;
        }
        rotv.x = 0.0f;
        rotv.y = ang + 8.0f;
        rotv.z = 0.0f;
        D_800ED610 = &D_800FFEC0_MinigameHouse[5];
        D_800ED72C = &rotv;
        func_800F8540_MinigameHouse(i);
        HuPrcVSleep();
    }

    /* the fall */
    func_80025EB4(D_80100620_MinigameHouse->model[0], 2, 1);
    fall = 0.0f;
    spin = 0.0f;
    vol = 0x7F;
    pitch = 0;
    while (1) {
        i++;
        if (i & 0x10) {
            sway -= 1.0f;
        } else {
            sway += 1.0f;
        }
        fall -= 1.0f;
        spin += 8.0f;
        D_80100620_MinigameHouse->rot.x = (0.0f - D_80100620_MinigameHouse->rot.x) / 15.0f + D_80100620_MinigameHouse->rot.x;
        D_80100620_MinigameHouse->rot.y = ang + 90.0f + spin + sway;
        D_80100620_MinigameHouse->rot.z = (0.0f - D_80100620_MinigameHouse->rot.z) / 15.0f + D_80100620_MinigameHouse->rot.z;
        D_80100620_MinigameHouse->trans.y = fall + D_80100620_MinigameHouse->trans.y;
        if (D_80100620_MinigameHouse->trans.y < 5.0f) {
            break;
        }
        radius = sway + 100.0f;
        px = func_800AEAC0(ang) * radius;
        pz = func_800AEFD0(ang) * radius + 130.0f;
        D_80100620_MinigameHouse->trans.x = (px - D_80100620_MinigameHouse->trans.x) / 12.0f + D_80100620_MinigameHouse->trans.x;
        ang += 1.0f;
        D_80100620_MinigameHouse->trans.z = (pz - D_80100620_MinigameHouse->trans.z) / 12.0f + D_80100620_MinigameHouse->trans.z;
        if (ang > 360.0f) {
            ang -= 360.0f;
        }
        rotv.x = -func_800B0CD8(D_80100620_MinigameHouse->trans.y + 15.0f - D_800FFEC0_MinigameHouse[5].y, sway + 100.0f);
        D_800ED610 = &D_800FFEC0_MinigameHouse[5];
        D_800ED72C = &rotv;
        vol -= 10;
        if (vol < 0) {
            vol = 0;
        }
        pitch -= 0x3E;
        if (pitch < -800) {
            pitch = -800;
        }
        func_8006035C(snd2, vol);
        func_80060440(snd2, pitch);
        HuPrcVSleep();
    }
    D_80100620_MinigameHouse->trans.y = 5.0f;
    func_8006071C(snd2);
    PlaySound(0x2A);
    for (i = 0; i < 20; i++) {
        D_80100620_MinigameHouse->rot.x -= 5.0f;
        D_80100620_MinigameHouse->rot.y += 4.0f;
        HuPrcVSleep();
    }
    for (i = 0; i < 10; i++) {
        if (i & 1) {
            D_80100620_MinigameHouse->rot.x = D_80100620_MinigameHouse->rot.x + 1.0f;
        } else {
            D_80100620_MinigameHouse->rot.x = D_80100620_MinigameHouse->rot.x - 1.0f;
        }
        HuPrcVSleep();
    }

    /* the result */
    func_800F8514_MinigameHouse();
    sprA = InitSprite(0x9004C);
    a = func_80019060(sprA, 0, 1);
    func_80018D84(a, 0xFFF0);
    sprB = InitSprite(0x9004D);
    b = func_80019060(sprB, 0, 1);
    func_80018D84((u16)b, 0xFFF0);
    func_800674F4(D_800ED60C[(s16)b].unk_04, 0, 0xFF, 0xD3, 0x4F);
    PlaySound(0x2B);
    for (i = 0; i < 100; i += 10) {
        x = i / 5 + 0x8C;
        y = 0x6E - (i * 0x23) / 100;
        SetBasicSpritePos(a, x, y);
        s = i / 100.0f;
        SetBasicSpriteSize(a, s, s);
        SetBasicSpritePos((u16)b, x, y);
        SetBasicSpriteSize((u16)b, s, s);
        HuPrcVSleep();
    }
    SetBasicSpriteSize(a, 1.0f, 1.0f);
    SetBasicSpriteSize((u16)b, 1.0f, 1.0f);
    w2 = func_8006D010(0x4E, 0x32, 0xA2, 0x30, 0, 0);
    func_8006E070(w2, 0);
    func_8006E2B8(w2, 0xA0, 0xA0, 0xA0);
    tw = func_8006DD60(w2);
    func_800674F4(tw->unk_44, 8, 0x20, 0xE, 0x71);
    func_800674BC(tw->unk_44, 0, 0x8000);
    sprintf(buf, "0\\%02d[%02d", (turns + 10) / 30, (((turns + 10) % 30) * 100) / 30);
    func_8006DA5C(w2, buf, 0);
    LoadStringIntoWindow(w2, (void*)0x74, -1, -1);
    while (func_8006FCC0(w2) != 0) {
        HuPrcVSleep();
    }
    if ((u16)func_800594FC(4) < turns + 10) {
        func_800594E4(4, turns + 10);
        func_8006EB40(w2);
        LoadStringIntoWindow(w2, (void*)0x76, -1, -1);
        while (func_8006FCC0(w2) != 0) {
            HuPrcVSleep();
        }
    }
    func_8006EB40(w2);
    sprintf(buf, D_801002BC_MinigameHouse, turns / 4);
    func_8006DA5C(w2, buf, 0);
    LoadStringIntoWindow(w2, (void*)0x75, -1, -1);
    while (func_8006FCC0(w2) != 0) {
        HuPrcVSleep();
    }
    func_8006EB40(w2);
    if (turns < 8) {
        msg = 0x77;
    } else if (turns < 0x54) {
        msg = 0x78;
    } else if (turns < 0x90) {
        msg = 0x79;
    } else if (turns < 0xB4) {
        msg = 0x7A;
    } else if (turns < 0xC8) {
        msg = 0x7B;
    } else if (turns < 0xD8) {
        msg = 0x7C;
    } else if (turns < 0xE8) {
        msg = 0x7D;
    } else if (turns < 0xF4) {
        msg = 0x7E;
    } else if (turns < 0xFC) {
        msg = 0x7F;
    } else if (turns < 0x104) {
        msg = 0x80;
    } else {
        msg = 0x81;
    }
    LoadStringIntoWindow(w2, (void*)(s32)msg, -1, -1);
    while (func_8006FCC0(w2) != 0) {
        HuPrcVSleep();
    }
    func_80070D90(w2);
    for (i = 100; i > 0; i -= 10) {
        x = i / 5 + 0x8C;
        y = 0x6E - (i * 0x23) / 100;
        SetBasicSpritePos(a, x, y);
        s = i / 100.0f;
        SetBasicSpriteSize(a, s, s);
        SetBasicSpritePos((u16)b, x, y);
        SetBasicSpriteSize((u16)b, s, s);
        HuPrcVSleep();
    }
    func_800191F8(a);
    func_80067704(sprA);
    func_800191F8((u16)b);
    func_80067704(sprB);
    func_80072724(0, 0, 0);
    func_800726AC(1, 0x14);
    while (func_80072718() != 0) {
        HuPrcVSleep();
    }
    D_80100620_MinigameHouse->trans.x = -170.0f;
    D_80100620_MinigameHouse->trans.y = 73.0f;
    D_80100620_MinigameHouse->trans.z = 200.0f;
    D_80100620_MinigameHouse->rot.x = 0.0f;
    D_80100620_MinigameHouse->rot.y = 90.0f;
    D_80100620_MinigameHouse->rot.z = 0.0f;
    D_8010055C_MinigameHouse = func_80059C28();
    func_8002888C(D_80100620_MinigameHouse->model[0], D_80100620_MinigameHouse->motion[0]);
    func_80025EB4(D_80100620_MinigameHouse->model[0], 1, 1);
    func_800F6970_MinigameHouse(5);
    ClearBoardFeatureFlag(0x30);
    func_8005B244();
    HuPrcSleep(0x14);
    func_8005B648(0x7F, 0x12);
    SetFadeInTypeAndTime(0xFF, 0xA);
    while (func_80072718() != 0) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800F8860_MinigameHouse);
#endif
const char D_801002BC_MinigameHouse[] __attribute__((section(".rodata"))) = "%d";

// register allocation; retail hoists the buffer base out of three fill loops (masked 44, 197 vs 194 instructions);
// tried D[n] stores and a local buffer pointer (worse)
#ifdef NON_MATCHING
char* func_800F9D64_MinigameHouse(s32 arg0) {
    u8* str;
    char* p;
    s32 len;
    s32 width;
    s32 n;
    s32 digits;
    s32 i;
    u16 score;

    str = func_8005B7E8(arg0 + 0x325);
    p = (char*)str;
    len = (s16)((s32 (*)(u8*))func_8006D93C)(str); /* retail: called as returning int */
    if (func_80059400(arg0) != 0 || func_8005949C(arg0) != 0) {
        n = 0;
        while (*p != 0) {
            if (*p != '\n') {
                *(n + D_80100410_MinigameHouse) = *p;
                n++;
            }
            p++;
        }
        width = (s16)((s32 (*)(u8*, s16))func_8006D99C)(str, 0); /* retail: called as returning int */
    } else {
        for (n = 0; n < len; n++) {
            D_80100410_MinigameHouse[n] = 0xC3;
        }
        width = len * 6;
    }
    len = (0x83 - width) / 12;
    func_8005B838(str);
    if (D_80100632_MinigameHouse == 0 && func_8005949C(arg0) == 0) {
        score = D_80100100_MinigameHouse[arg0];
        if (len < 0) {
            len = 0;
        }
        for (i = 0; i < len; i++) {
            *(n + D_80100410_MinigameHouse) = 0xE;
            n++;
        }
        if (func_80059400(arg0) != 0) {
            sprintf((char*)&D_80100410_MinigameHouse[n], "%4d", score);
            return D_80100410_MinigameHouse;
        }
        digits = 1;
        if (score >= 10) {
            digits = (score >= 100) ? 3 : 2;
        }
        for (i = 0; i < 4 - digits; i++) {
            *(n + D_80100410_MinigameHouse) = ' ';
            n++;
        }
        for (i = 0; i < digits; i++) {
            *(n + D_80100410_MinigameHouse) = 0xC3;
            n++;
        }
    }
    D_80100410_MinigameHouse[n] = 0;
    return D_80100410_MinigameHouse;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800F9D64_MinigameHouse);
#endif
s32 func_800F9FF4_MinigameHouse(s16 win, s32 grp, char* out) {
    char buf[0x58];
    s32 n;
    s32 cnt;
    s32 i;
    s32 j;
    char* name;
    void* title;

    n = 0;
    cnt = 0;
    for (i = D_80100170_MinigameHouse[grp].start; i < D_80100170_MinigameHouse[grp].end; i++) {
        D_80100624_MinigameHouse[n] = D_80100170_MinigameHouse[grp].list[i];
        func_8009B960(name = D_80100430_MinigameHouse[n], func_800F9D64_MinigameHouse(D_80100624_MinigameHouse[n] - 1));
        if (*name != (char)0xC3) {
            cnt++;
        } else {
            D_80100624_MinigameHouse[n] = 0;
        }
        func_8006DA5C(win, D_80100430_MinigameHouse[n], n);
        n++;
    }
    for (i = n; i < 10; i++) {
        D_80100624_MinigameHouse[i] = 0;
    }
    j = 0;
    for (i = 0; i < n; i++) {
        buf[j++] = 10;
        if (D_80100624_MinigameHouse[i] != 0) {
            if (func_8005949C(D_80100624_MinigameHouse[i] - 1) != 0) {
                buf[j++] = 5;
                buf[j++] = 0x3B;
                buf[j++] = 14;
                buf[j++] = 8;
            } else {
                buf[j++] = 14;
                buf[j++] = 8;
            }
        } else {
            buf[j++] = 14;
            buf[j++] = 7;
        }
        buf[j++] = 12;
        buf[j++] = i + 0x11;
        buf[j++] = 13;
    }
    buf[j++] = 8;
    buf[j] = 0;
    title = func_8005B7E8(D_80100170_MinigameHouse[grp].msg);
    sprintf(out, "\x08%s\n%s", (char*)title, buf);
    func_8005B838(title);
    return cnt;
}
void func_800FA2E4_MinigameHouse(void) {
    TextWindow* w;
    s16 spr;

    D_80100634_MinigameHouse = func_8006D010(0x82, 0x20, 0xD9, 0xB0, 0, 0);
    func_8007155C(D_80100634_MinigameHouse, (s16)(1 << GwPlayer[0].port));
    func_8006E0A4(D_80100634_MinigameHouse, -1);
    w = func_8006DD60(D_80100634_MinigameHouse);
    w->unk_04 = 0;
    w->unk_03 = 0;
    w->unk_09 = 0;
    spr = w->unk_44;
    func_800674BC(spr, 0, 0x8000);
    func_800674F4(spr, 8, 0, 0, 0);
    func_800674F4(spr, 7, 0, 0, 0);
}
void func_800FA3B0_MinigameHouse(void) {
    s32 i;

    for (i = 0; i < 10; i++) {
        if (D_80100624_MinigameHouse[i] == 0 ||
            (D_80100632_MinigameHouse == 0 &&
             (func_8005949C(D_80100624_MinigameHouse[i] - 1) != 0 ||
              (s32)GwCommon.coinNum < D_80100100_MinigameHouse[D_80100624_MinigameHouse[i] - 1]))) {
            func_80071788(D_80100634_MinigameHouse, i);
        }
    }
}
void func_800FA470_MinigameHouse(omObjData* obj) {
    TextWindow* w;
    s32 i;

    w = func_8006DD60(D_80100634_MinigameHouse);
    func_80066DC4(w->unk_44, 0, w->unk_14, w->unk_16);
    for (i = 0; i < 0x100; i += 0x20) {
        D_80100618_MinigameHouse->rot.z = 270.0f - (i * 90.0f) / 256.0f;
        func_8006752C(w->unk_44, 5, i);
        func_8006752C(w->unk_44, 8, i / 2);
        func_8006752C(w->unk_44, 7, i / 4);
        if (obj != NULL) {
            func_800211BC(obj->model[0], (i * 90) / 256);
        }
        HuPrcVSleep();
    }
    D_80100618_MinigameHouse->rot.z = 180.0f;
    func_8006752C(w->unk_44, 5, 0xFF);
    func_8006752C(w->unk_44, 8, 0x7F);
    func_8006752C(w->unk_44, 7, 0x3F);
    if (obj != NULL) {
        func_800211BC(obj->model[0], 90);
    }
}
void func_800FA600_MinigameHouse(omObjData* obj) {
    TextWindow* w;
    s32 i;
    s32 v;

    w = func_8006DD60(D_80100634_MinigameHouse);
    for (i = 0; i < 0x100; i += 0x20) {
        D_80100618_MinigameHouse->rot.z = (i * 90.0f) / 256.0f + 180.0f;
        v = 0xFF - i;
        func_8006752C(w->unk_44, 5, v);
        func_8006752C(w->unk_44, 8, v / 2);
        func_8006752C(w->unk_44, 7, v / 4);
        if (obj != NULL) {
            func_800211BC(obj->model[0], ((0xFF - i) * 90) / 256);
        }
        HuPrcVSleep();
    }
    D_80100618_MinigameHouse->rot.z = 270.0f;
    func_80066DC4(w->unk_44, 0, 0x140, w->unk_16);
    func_8006752C(w->unk_44, 5, 0);
    func_8006752C(w->unk_44, 8, 0);
    func_8006752C(w->unk_44, 7, 0);
    if (obj != NULL) {
        func_800211BC(obj->model[0], 0);
    }
    func_8006EB40(D_80100634_MinigameHouse);
    HuPrcVSleep();
}
void func_800FA7C0_MinigameHouse(char* msg) {
    s32 i;

    LoadStringIntoWindow(D_80100634_MinigameHouse, msg, -1, -1);
    func_800258EC(D_80100618_MinigameHouse->model[0], 4, 0);
    PlaySound(0x27);
    for (i = 0; i < 0x100; i += 0x20) {
        D_80100618_MinigameHouse->rot.z = 360.0f - (i * 90.0f) / 256.0f;
        HuPrcVSleep();
    }
    while (func_8006FCC0(D_80100634_MinigameHouse) != 0) {
        HuPrcVSleep();
    }
    func_800FA470_MinigameHouse(NULL);
    func_800258EC(D_80100618_MinigameHouse->model[0], 4, 4);
}
s32 func_800FA8D0_MinigameHouse(void) {
    if (D_80100632_MinigameHouse == 0) {
        return 0;
    }
    switch (D_800C5720) {
    case 1:
        return 3;
    case 0:
        return 0;
    case 2:
        return 4;
    default:
        return 5;
    }
}
s32 func_800FA92C_MinigameHouse(s32* sel) {
    char buf[0x68];
    s16 win;
    s32 min;
    s32 max;
    s32 prev;
    s32 res;
    s32 i;
    u32 btn;

    min = func_800FA8D0_MinigameHouse();
    max = 5;
    if (D_80100632_MinigameHouse != 0) {
        if (D_800C5720 != 0) {
            max = 6;
            if (D_800C5720 != 3) {
                max = min;
            }
        } else {
            max = 2;
        }
    }
    goto loop;
found:
    func_800F7218_MinigameHouse(D_80100624_MinigameHouse[res] - 1);
    return D_80100624_MinigameHouse[res];
loop:
    {
    }
    prev = *sel;
    while (1) {
        func_800F69A8_MinigameHouse();
        func_800258EC(D_8010061C_MinigameHouse->model[1], 4, 4);
        btn = func_80059CB8();
        if (btn & 0x8000) {
            func_800F69DC_MinigameHouse();
            PlaySound(0xF6);
            if (D_80100632_MinigameHouse != 0) {
                win = func_8006D010(0x18, 0x94, 0x81, 0x30, 0, 0);
                func_8006E070(win, 0);
                LoadStringIntoWindow(win, (void*)0x68, -1, -1);
                while (func_8006FCC0(win) != 0) {
                    HuPrcVSleep();
                }
            }
            func_800FA3B0_MinigameHouse();
            D_8010061C_MinigameHouse->unk_50 = func_8006DD60(D_80100634_MinigameHouse);
            D_8010061C_MinigameHouse->work[0] = 0xFF;
            res = func_8006FCF0(D_80100634_MinigameHouse, 0, 0);
            if (D_80100632_MinigameHouse != 0) {
                func_80070D90(win);
            }
            D_8010061C_MinigameHouse->unk_50 = NULL;
            if (res != -1) {
                goto found;
            }
        }
        if (btn & 0x4000) {
            break;
        }
        if (btn & 0x100) {
            (*sel)++;
            if (max < *sel) {
                *sel = max;
            }
        }
        if (btn & 0x200) {
            (*sel)--;
            if (*sel < min) {
                *sel = min;
            }
        }
        if (D_80100632_MinigameHouse == 0) {
            func_800F6A10_MinigameHouse(0, 0x82, 0x1C);
        } else {
            func_800F6A10_MinigameHouse(0, 0x98, 0x1C);
        }
        if (*sel == min) {
            func_80018C90(D_80100582_MinigameHouse[0]);
        }
        if (*sel == max) {
            func_80018C90(D_80100582_MinigameHouse[1]);
        }
        if (prev != *sel) {
            func_800F69DC_MinigameHouse();
            func_800F9FF4_MinigameHouse(D_80100634_MinigameHouse, *sel, buf);
            if (btn & 0x100) {
                func_800FA600_MinigameHouse(NULL);
                func_800FA7C0_MinigameHouse(buf);
            } else {
                func_800258EC(D_80100618_MinigameHouse->model[0], 4, 0);
                PlaySound(0x27);
                func_800FA600_MinigameHouse(NULL);
                LoadStringIntoWindow(D_80100634_MinigameHouse, buf, -1, -1);
                for (i = 0x20; i < 0x100; i += 0x20) {
                    D_80100618_MinigameHouse->rot.z = (i * 90.0f) / 256.0f + 270.0f;
                    HuPrcVSleep();
                }
                func_800258EC(D_80100618_MinigameHouse->model[0], 4, 4);
                while (func_8006FCC0(D_80100634_MinigameHouse) != 0) {
                    HuPrcVSleep();
                }
                func_800FA470_MinigameHouse(NULL);
            }
        }
        prev = *sel;
        HuPrcVSleep();
    }
    func_800F69DC_MinigameHouse();
    PlaySound(0xF8);
    return 0;
}
s32 func_800FAD28_MinigameHouse(s16* out, s16 y) {
    s32 i;
    s32 n;
    s32 max;

    for (i = 0, max = 0; i < 4; i++) {
        if (max < GwPlayer[i].coins) {
            max = GwPlayer[i].coins;
        }
    }
    for (i = 0, n = 0; i < 4; i++) {
        if (max == GwPlayer[i].coins) {
            out[n] = GwPlayer[i].character;
            n++;
        }
    }
    if (n >= 4) {
        n = 0;
    }
    for (i = 0; i < n; i++) {
        D_80100638_MinigameHouse[i] = func_800429CC(out[i], 0);
        D_80100638_MinigameHouse[i]->x = (i * 2 - n) * 40 + 200;
        D_80100638_MinigameHouse[i]->y = y;
        D_80100638_MinigameHouse[i]->flags |= 2;
        D_80100638_MinigameHouse[i]->attr = 0x6000;
    }
    return n;
}
// decomp-permuter
s32 func_800FAE94_MinigameHouse(s32 cat)
{
  s32 ret;
  s32 r;
  int new_var;
  s32 i;
  s32 n;
  n = 0;
  for (i = 0; i < D_801001C4_MinigameHouse[cat].count; i++)
  {
    n += func_8005949C(D_801001C4_MinigameHouse[cat].list[i] - 1) != 0;
  }

  new_var = (cat == 0) | (cat == 3);
  r = n < 5;
  if (new_var == 0)
  {
    r = n < 3;
  }
  if (r != 0)
  {
    ret = 1;
  }
  else
    if (n)
  {
    ret = 0;
  }
  else
  {
    ret = 0;
  }
  return ret;
}
s32 func_800FAF5C_MinigameHouse(s16 win) {
    char buf[2][3];
    s32 total;
    s32 left;
    s32 c;
    s32 i;
    s32 n;

    total = 0;
    left = 0;
    for (c = 0; c < 4; c++) {
        n = 0;
        for (i = 0; i < D_801001C4_MinigameHouse[c].count; i++) {
            if (func_80059400(D_801001C4_MinigameHouse[c].list[i] - 1) != 0 ||
                func_8005949C(D_801001C4_MinigameHouse[c].list[i] - 1) != 0) {
                n++;
            }
        }
        left += D_801001C4_MinigameHouse[c].count - n;
        total += n;
    }
    sprintf(buf[0], "%02d", total);
    func_8006DA5C(win, buf[0], 0);
    sprintf(buf[1], "%02d", left);
    func_8006DA5C(win, buf[1], 1);
    LoadStringIntoWindow(win, (void*)0x57, -1, -1);
    while (func_8006FCC0(win) != 0) {
        HuPrcVSleep();
    }
    return total;
}
s32 func_800FB108_MinigameHouse(s16 win) {
    char buf[3];
    s32 total;
    s32 c;
    s32 i;
    s32 n;

    total = 0;
    for (c = 0; c < 4; c++) {
        n = 0;
        for (i = 0; i < D_801001C4_MinigameHouse[c].count; i++) {
            n += func_8005949C(D_801001C4_MinigameHouse[c].list[i] - 1) != 0;
        }
        total += n;
    }
    sprintf(buf, "%02d", total);
    func_8006DA5C(win, buf, 0);
    LoadStringIntoWindow(win, (void*)0x58, -1, -1);
    while (func_8006FCC0(win) != 0) {
        HuPrcVSleep();
    }
    return total;
}
void func_800FB238_MinigameHouse(void) {
    func_80025C20(D_80100614_MinigameHouse->model[0], D_80100614_MinigameHouse->motion[2], 0, 10, 1);
    HuPrcSleep(5);
    func_8002888C(D_80100614_MinigameHouse->model[0], D_80100614_MinigameHouse->motion[2]);
    HuPrcSleep(12);
    PlaySound(0x25);
    func_80025EB4(D_8010060C_MinigameHouse->model[1], 5, 0);
    func_8005A258(D_80100614_MinigameHouse->model[0]);
}
// register allocation s1/s2 (masked 0)
#ifdef NON_MATCHING
void func_800FB2DC_MinigameHouse(void) {
    char buf[0x68];
    char num[8];
    s32 sel;
    s32 msg;
    s32 w1;
    s32 w2;
    TextWindow* w;
    s32 i;
    u16* price;
    s32 mg;

    D_80100632_MinigameHouse = 0;
    msg = 0x3E;
    func_800F6970_MinigameHouse(2);
    sel = 0;
again:
    {
        func_800FA2E4_MinigameHouse();
        w1 = D010(0xBD, 0x25, 0x6B, 0x4C, 0, 0);
        w = func_8006DD60(w1);
        w->unk_04 = 0;
        w->unk_03 = 0;
        func_80066DC4(w->unk_44, 0, 0x140, w->unk_16);
        w2 = D010(0x18, 0x25, 0x6B, 0x3E, 0, 0);
        w = func_8006DD60(w2);
        w->unk_04 = 0;
        w->unk_03 = 0;
        func_80066DC4(w->unk_44, 0, 0x140, w->unk_16);
        func_800FAF5C_MinigameHouse(w1);
        func_800FB108_MinigameHouse(w2);
        func_80066DC4(w->unk_44, 0, w->unk_14, w->unk_16);
        w = func_8006DD60(w1);
        func_80066DC4(w->unk_44, 0, w->unk_14, w->unk_16);
        i = 0;
        do {
            if (sel >= 7) {
                sel = 0;
            }
            if (func_800F9FF4_MinigameHouse(D_80100634_MinigameHouse, sel, buf) != 0) {
                break;
            }
            i++;
            sel++;
        } while (i < 7);
        func_80025C20(D_80100614_MinigameHouse->model[0], D_80100614_MinigameHouse->motion[1], 0, 10, 2);
        if (i == 7) {
            func_8006EB40(D_8010055C_MinigameHouse);
            LoadStringIntoWindow(D_8010055C_MinigameHouse, (void*)0x3F, -1, -1);
            while (func_8006FCC0(D_8010055C_MinigameHouse) != 0) {
                HuPrcVSleep();
            }
            sel = 0;
            func_800F9FF4_MinigameHouse(D_80100634_MinigameHouse, 0, buf);
        } else if (func_80059CE8((void*)(s32)msg, D_8010055C_MinigameHouse) == 0) {
            func_80025C20(D_80100614_MinigameHouse->model[0], D_80100614_MinigameHouse->motion[0], 0, 10, 2);
            func_80025EB4(D_8010060C_MinigameHouse->model[1], 0, 4);
            func_80070D90(D_80100634_MinigameHouse);
            func_80070D90(w1);
            func_80070D90(w2);
            return;
        }
        if (msg != 0x42) {
            func_800FB238_MinigameHouse();
        }
        func_80070D90(w1);
        func_80070D90(w2);
    menu:
        {
            func_80025C20(D_80100614_MinigameHouse->model[0], D_80100614_MinigameHouse->motion[0], 0, 10, 2);
            w = func_8006DD60(D_80100634_MinigameHouse);
            func_80066DC4(w->unk_44, 0, 0x140, w->unk_16);
            func_80070D90(D_8010055C_MinigameHouse);
            LoadStringIntoWindow(D_80100634_MinigameHouse, buf, -1, -1);
            func_800F6970_MinigameHouse(3);
            HuPrcSleep(30);
            func_8006752C(w->unk_44, 1, 0);
            func_800FA470_MinigameHouse(NULL);
            mg = func_800FA92C_MinigameHouse(&sel);
            if (mg == 0) {
                goto cancel;
            }
            func_80070D90(D_80100634_MinigameHouse);
            func_800F6970_MinigameHouse(2);
            D_8010055C_MinigameHouse = func_80059C28();
            sprintf(num, D_801002BC_MinigameHouse, *(price = D_80100100_MinigameHouse - 1, price += mg));
            func_8006DA5C(D_8010055C_MinigameHouse, num, 0);
            func_80025C20(D_80100614_MinigameHouse->model[0], D_80100614_MinigameHouse->motion[1], 0, 10, 2);
            if (func_80059CE8((void*)0x41, D_8010055C_MinigameHouse) != 0) {
                func_800258EC(D_8010061C_MinigameHouse->model[1], 4, 4);
                GwCommon.coinNum -= *price;
                func_80059B74(mg - 1);
                msg = 0x42;
                goto again;
            }
            func_800258EC(D_8010061C_MinigameHouse->model[1], 4, 4);
            func_800FA2E4_MinigameHouse();
            func_800F9FF4_MinigameHouse(D_80100634_MinigameHouse, sel, buf);
            goto menu;
        }
    }
cancel:
    PlaySound(0xF8);
    func_80025EB4(D_8010060C_MinigameHouse->model[1], 0, 4);
    func_80070D90(D_80100634_MinigameHouse);
    HuPrcVSleep();
    D_8010055C_MinigameHouse = func_80059C28();
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FB2DC_MinigameHouse);
#endif
void func_800FB7E0_MinigameHouse(omObjData* obj) {
    s32 i;

    if (obj->work[0] != 0) {
        if ((obj->scale.z *= 1.5f) > 0.08f) {
            obj->scale.z = 0.08f;
        }
        if ((obj->trans.y += 0.5f) > 78.0f) {
            obj->trans.y = 78.0f;
        }
        func_80025EB4(obj->model[0], 1, 2);
    } else {
        i = obj->work[1];
        obj->trans.x = D_801001E4_MinigameHouse[i].x;
        obj->trans.y = 75.1f;
        obj->trans.z = D_801001E4_MinigameHouse[i].z;
        obj->scale.z = 0.005f;
        func_80025EB4(obj->model[0], 1, 1);
    }
    if (obj->work[0] == 2) {
        i = obj->work[2];
        obj->trans.x = (D_8010022C_MinigameHouse[i].x - obj->trans.x) / 10.0f + obj->trans.x;
        obj->trans.z = (D_8010022C_MinigameHouse[i].z - obj->trans.z) / 10.0f + obj->trans.z;
    }
}
void func_800FB96C_MinigameHouse(omObjData* obj) {
    obj->model[0] = LoadFormFile(D_800C59AC[D_8010025C_MinigameHouse].unk_00 | D_800C59AC[D_8010025C_MinigameHouse].unk_04, 0x202B9);
    obj->trans.x = D_801001E4_MinigameHouse[D_8010025C_MinigameHouse].x;
    obj->trans.y = D_801001E4_MinigameHouse[D_8010025C_MinigameHouse].y;
    obj->trans.z = D_801001E4_MinigameHouse[D_8010025C_MinigameHouse].z;
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800258EC(obj->model[0], 4, 4);
    obj->scale.z = 0.005f;
    obj->scale.x = obj->scale.y = 0.08f;
    obj->rot.x = 270.0f;
    obj->rot.y = obj->rot.z = 0.0f;
    obj->work[0] = 0;
    obj->work[1] = (u8)D_8010025C_MinigameHouse;
    obj->func_ptr = &func_800FB7E0_MinigameHouse;
    D_8010025C_MinigameHouse++;
}
s32 func_800FBAC0_MinigameHouse(s32 idx) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if ((i == idx) | (i == -1)) {
            continue;
        }
        if (D_80100648_MinigameHouse[i] == D_80100648_MinigameHouse[idx]) {
            return 0;
        }
    }
    return 1;
}
void func_800FBB28_MinigameHouse(s32 port, s32 p, s16 spr) {
    Vec3f pos;
    Vec2f scr;
    s32 prev;
    s32 save;
    s32 t;
    s32 u;
    s32 i;

    prev = D_80100648_MinigameHouse[p];
    if (ContDStkTrg[port] & 0x100) {
        i = 0;
        save = D_80100648_MinigameHouse[p];
        do {
            t = D_80100648_MinigameHouse[p];
            D_80100648_MinigameHouse[p] = t + 1;
            if (((t + 1) == 3) | ((t + 1) == 6)) {
                D_80100648_MinigameHouse[p] = t - 2;
            }
            if (func_800FBAC0_MinigameHouse(p) != 0) {
                break;
            }
            i++;
        } while (i < 3);
        if (i == 3) {
            D_80100648_MinigameHouse[p] = save;
        }
    }
    i = 0;
    if (ContDStkTrg[port] & 0x200) {
        save = D_80100648_MinigameHouse[p];
        do {
            t = D_80100648_MinigameHouse[p];
            D_80100648_MinigameHouse[p] = t - 1;
            if (((t - 1) == 2) | ((t - 1) == -1)) {
                D_80100648_MinigameHouse[p] = t + 2;
            }
            if (func_800FBAC0_MinigameHouse(p) != 0) {
                break;
            }
            i++;
        } while (i < 3);
        if (i == 3) {
            D_80100648_MinigameHouse[p] = save;
        }
    }
    if (ContDStkTrg[port] & 0x400) {
        save = D_80100648_MinigameHouse[p];
        do {
            u = D_80100648_MinigameHouse[p];
            D_80100648_MinigameHouse[p] = u + 3;
            if (u + 3 >= 6) {
                D_80100648_MinigameHouse[p] = u - 3;
            }
            for (i = 0; i < 3; i++) {
                if (func_800FBAC0_MinigameHouse(p) != 0) {
                    break;
                }
                t = D_80100648_MinigameHouse[p];
                D_80100648_MinigameHouse[p] = t + 1;
                if (((t + 1) == 3) | ((t + 1) == 6)) {
                    D_80100648_MinigameHouse[p] = t - 2;
                }
            }
            if (i == 3) {
                D_80100648_MinigameHouse[p] = save;
                break;
            }
        } while (func_800FBAC0_MinigameHouse(p) == 0);
    }
    if (ContDStkTrg[port] & 0x800) {
        save = D_80100648_MinigameHouse[p];
        do {
            u = D_80100648_MinigameHouse[p];
            D_80100648_MinigameHouse[p] = u - 3;
            if (u - 3 < 0) {
                D_80100648_MinigameHouse[p] = u + 3;
            }
            for (i = 0; i < 3; i++) {
                if (func_800FBAC0_MinigameHouse(p) != 0) {
                    break;
                }
                t = D_80100648_MinigameHouse[p];
                D_80100648_MinigameHouse[p] = t + 1;
                if (((t + 1) == 3) | ((t + 1) == 6)) {
                    D_80100648_MinigameHouse[p] = t - 2;
                }
            }
            if (i == 3) {
                D_80100648_MinigameHouse[p] = save;
                break;
            }
        } while (func_800FBAC0_MinigameHouse(p) == 0);
    }
    if (D_80100648_MinigameHouse[p] != prev) {
        PlaySound(0xF5);
    }
    pos.x = D_80100568_MinigameHouse[D_80100648_MinigameHouse[p]]->trans.x;
    pos.y = D_80100568_MinigameHouse[D_80100648_MinigameHouse[p]]->trans.y;
    pos.z = D_80100568_MinigameHouse[D_80100648_MinigameHouse[p]]->trans.z;
    Convert3DTo2D(0, &pos, &scr);
    scr.x += 10.0f;
    scr.y -= 24.0f;
    D_800ED60C[spr].unk_0A = D_800ED60C[spr].unk_0A + (scr.x - D_800ED60C[spr].unk_0A) / 2.0f;
    D_800ED60C[spr].unk_0C = D_800ED60C[spr].unk_0C + (scr.y - D_800ED60C[spr].unk_0C) / 2.0f;
}
void func_800FBFA4_MinigameHouse(s32 p, s32 spr) {
    Vec3f pos;
    Vec2f scr;

    pos.x = D_80100568_MinigameHouse[D_80100648_MinigameHouse[p]]->trans.x;
    pos.y = D_80100568_MinigameHouse[D_80100648_MinigameHouse[p]]->trans.y;
    pos.z = D_80100568_MinigameHouse[D_80100648_MinigameHouse[p]]->trans.z;
    Convert3DTo2D(0, &pos, &scr);
    SetBasicSpritePos((u16)spr, scr.x + 10.0f, scr.y - 24.0f);
}
const char D_801002D4_MinigameHouse[] = "%s"; /* also used by func_800FD2D0 */

void func_800FC090_MinigameHouse(char* out) {
    char* str;
    s32 len;

    str = func_8005B7E8(0x48);
    len = (s32)strlen(str) - 0x1C;
    sprintf(out, D_801002D4_MinigameHouse, str);
    func_8005B838(str);
    out[D_80100594_MinigameHouse * 7 + len] = 0;
}
void func_800FC110_MinigameHouse(void) {
    s32 i;

    switch (D_800C5720) {
    case 1:
        for (i = 0; i < 4; i++) {
            GwPlayer[i].group = D_8010026C_MinigameHouse[D_800C5723][i];
        }
        break;
    case 2:
        for (i = 0; i < 4; i++) {
            GwPlayer[i].group = D_80100260_MinigameHouse[D_800C5723][i];
        }
        break;
    default:
        for (i = 0; i < 4; i++) {
            GwPlayer[i].group = i;
        }
        break;
    }
}
// register allocation s6/v1 for the table pointer (masked 0, raw 2); tried D[row], D[0] + row * 4, &D[0][row * 4]
// (all compute the index first)
#ifdef NON_MATCHING
void func_800FC204_MinigameHouse(unkCommonStruct0* font, s16* ids, u16* sprs, s32 row, s32 mode) {
    s32 team;
    s32 i;
    s32 n;
    s16 x;
    u8* tbl;

    if (mode != 0) {
        team = 0;
        tbl = D_8010026C_MinigameHouse[0];
        tbl += row * 4;
        do {
            i = 0;
            n = 0;
            x = team * 0x61 + 0xB7;
            for (; i < 4; i++) {
                if (tbl[i] == team) {
                    SetBasicSpritePos(sprs[i], x, (n - team) * 40 + 0x78);
                    func_80066DC4(font->unk_14[ids[i]], 0, x, (n - team) * 40 + 0x88);
                    n++;
                }
            }
            team++;
        } while (team < 2);
        return;
    }
    team = 0;
    tbl = D_80100260_MinigameHouse[0];
    tbl += row * 4;
    do {
        i = 0;
        n = 0;
        x = team * 0x61 + 0xB7;
        for (; i < 4; i++) {
            if (tbl[i] == team) {
                SetBasicSpritePos(sprs[i], x, n * 40 + 0x60);
                func_80066DC4(font->unk_14[ids[i]], 0, x, n * 40 + 0x70);
                n++;
            }
        }
        team++;
    } while (team < 2);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FC204_MinigameHouse);
#endif
// register allocation of the arrow sprite's s16 extension (masked 1)
#ifdef NON_MATCHING
s32 func_800FC410_MinigameHouse(void) {
    unkCommonStruct0 font;
    char buf[8];
    u16 sprs[4];
    s16 chrSpr[4];
    s16 ids[4];
    s16 arrowSpr;
    s32 arrow;
    s32 mode;
    TextWindow* w;
    s32 i;
    s32 j;
    s32 t;
    s32 sel;
    u32 btn;

    LoadStringIntoWindow(D_80100634_MinigameHouse, (void*)0x4A, -1, -1);
    arrow = func_80019060(arrowSpr = InitSprite(0xA0021), 0, 1);
    SetBasicSpritePos((u16)arrow, 0xE8, 0x78);
    func_80018C90((u16)arrow);
    for (i = 0; i < 16; i++) {
        font.unk_14[i] = -1;
        font.unk_34[i] = -1;
    }
    for (i = 0; i < 4; i++) {
        sprintf(buf, "%dP", i + 1);
        ids[i] = GMesFontCreate(&font, buf, 0, -1, -1);
        chrSpr[i] = InitSprite((GwPlayer[i].character + 0x37) | 0xA0000);
        sprs[i] = func_80019060(chrSpr[i], 0, 1);
        func_80018C90(sprs[i]);
        func_800674BC(font.unk_14[ids[i]], 1, 0x8000);
        func_800674BC(font.unk_14[ids[i]], 2, 0x8000);
    }
    mode = D_800C5720 != 2;
    func_800FC204_MinigameHouse(&font, ids, sprs, 0, mode);
    func_800258EC(D_80100618_MinigameHouse->model[0], 4, 0);
    PlaySound(0x27);
    for (i = 0; i < 0x100; i += 0x20) {
        D_80100618_MinigameHouse->rot.z = 360.0f - (i * 90.0f) / 256.0f;
        HuPrcVSleep();
    }
    w = func_8006DD60(D_80100634_MinigameHouse);
    func_80066DC4(w->unk_44, 0, w->unk_14, w->unk_16);
    ShowBasicSprite((u16)arrow);
    for (i = 0; i < 4; i++) {
        ShowBasicSprite(sprs[i]);
        func_80067480(font.unk_14[ids[i]], 1, 0x8000);
        func_80067480(font.unk_14[ids[i]], 2, 0x8000);
    }
    for (t = 0; t < 0x100; t += 0x20) {
        for (j = 0; j < 4; j++) {
            func_8006752C(font.unk_14[ids[j]], 1, t);
            func_8006752C(font.unk_14[ids[j]], 2, t);
            func_80018CF8(sprs[j], (s16)t);
        }
        func_80018CF8((u16)arrow, (s16)t);
        D_80100618_MinigameHouse->rot.z = 270.0f - (t * 90.0f) / 256.0f;
        func_8006752C(w->unk_44, 8, t / 2);
        HuPrcVSleep();
    }
    D_80100618_MinigameHouse->rot.z = 180.0f;
    func_8006752C(w->unk_44, 8, 0x7F);
    func_800258EC(D_80100618_MinigameHouse->model[0], 4, 4);
    sel = 0;
    while (1) {
        btn = func_80059CB8();
        if (btn & 0x100) {
            PlaySound(0xF5);
            sel++;
            if ((mode + 2) < sel) {
                sel = 0;
            }
        }
        if (btn & 0x200) {
            PlaySound(0xF5);
            sel--;
            if (sel < 0) {
                sel = mode + 2;
            }
        }
        func_800FC204_MinigameHouse(&font, ids, sprs, sel, mode);
        if (btn & 0x4000) {
            break;
        }
        if (btn & 0x8000) {
            D_800C5723 = sel;
            PlaySound(0xF6);
            D_8010055C_MinigameHouse = func_80059C28();
            if (func_80059CE8((void*)0x4B, D_8010055C_MinigameHouse) != 0) {
                func_80070D90(D_8010055C_MinigameHouse);
                for (i = 0; i < 4; i++) {
                    func_800191F8(sprs[i]);
                    func_80067704(chrSpr[i]);
                }
                GMesSprKill(&font);
                func_800191F8((u16)arrow);
                func_80067704(arrowSpr);
                func_8006EB40(D_80100634_MinigameHouse);
                return 0;
            }
            func_80070D90(D_8010055C_MinigameHouse);
        }
        HuPrcVSleep();
    }
    PlaySound(0xF8);
    func_800258EC(D_80100618_MinigameHouse->model[0], 4, 0);
    PlaySound(0x27);
    for (t = 0; t < 0x100; t += 0x20) {
        for (j = 0; j < 4; j++) {
            func_8006752C(font.unk_14[ids[j]], 1, (s16)(0xFF - t));
            func_8006752C(font.unk_14[ids[j]], 2, (s16)(0xFF - t));
            func_80018CF8(sprs[j], (s16)(0xFF - t));
        }
        j = 0xFF - t;
        func_80018CF8((u16)arrow, (s16)j);
        D_80100618_MinigameHouse->rot.z = (t * 90.0f) / 256.0f + 180.0f;
        func_8006752C(w->unk_44, 8, j / 2);
        HuPrcVSleep();
    }
    D_80100618_MinigameHouse->rot.z = 270.0f;
    for (i = 0; i < 4; i++) {
        func_800191F8(sprs[i]);
        func_80067704(chrSpr[i]);
    }
    GMesSprKill(&font);
    func_800191F8((u16)arrow);
    func_80067704(arrowSpr);
    func_80066DC4(w->unk_44, 0, 0x140, w->unk_16);
    func_8006752C(w->unk_44, 8, 0);
    func_8006EB40(D_80100634_MinigameHouse);
    HuPrcVSleep();
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FC410_MinigameHouse);
#endif
omObjData* func_800FCB78_MinigameHouse(void) {
    omObjData* obj;

    obj = omAddObj(1, 1, 0, -1, NULL);
    obj->model[0] = func_800174C0(0x90044, 0x6A9);
    obj->trans.x = 36.0f;
    obj->trans.y = 75.6f;
    obj->trans.z = -77.1f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    func_80021240(obj->model[0]);
    func_800211BC(obj->model[0], 0);
    return obj;
}
void func_800FCC38_MinigameHouse(s16 win, s32 kind) {
    switch (kind) {
    case 0:
        LoadStringIntoWindow(win, (void*)(s32)((D_800C5722 & 0xF) + 0x5E), -1, -1);
        break;
    case 1:
        LoadStringIntoWindow(win, (void*)(s32)((D_800C5722 & 0x10) ? 0x63 : 0x62), -1, -1);
        break;
    default:
        LoadStringIntoWindow(win, (void*)(s32)((D_800C5722 & (8 << kind)) ? 0x65 : 0x64), -1, -1);
        break;
    }
}
omObjData* func_800FCCD8_MinigameHouse(void) {
    omObjData* obj;
    s32 i;

    for (i = 0; i < 6; i++) {
        func_800258EC(D_80100568_MinigameHouse[i]->model[0], 4, 4);
    }
    func_800258EC(D_80100618_MinigameHouse->model[0], 4, 0);
    PlaySound(0x27);
    func_800FA600_MinigameHouse(NULL);
    LoadStringIntoWindow(D_80100634_MinigameHouse, (void*)0x49, -1, -1);
    for (i = 0x20; i < 0x100; i += 0x20) {
        D_80100618_MinigameHouse->rot.z = (i * 90.0f) / 256.0f + 270.0f;
        HuPrcVSleep();
    }
    func_8006DD60(D_80100634_MinigameHouse)->unk_14 = 0x82;
    for (i = 0; i < 6; i++) {
        func_800258EC(D_80100568_MinigameHouse[i]->model[0], 4, 0);
        D_80100568_MinigameHouse[i]->work[0] = 0;
    }
    obj = func_800FCB78_MinigameHouse();
    func_800258EC(D_80100618_MinigameHouse->model[0], 4, 4);
    func_800FA470_MinigameHouse(obj);
    return obj;
}
void func_800FCE7C_MinigameHouse(omObjData* obj) {
    TextWindow* w;

    w = func_8006DD60(D_80100634_MinigameHouse);
    if (w != NULL) {
        if (w->unk_11 != (s8)obj->work[0]) {
            func_8006EB40(D_8010055C_MinigameHouse);
            LoadStringIntoWindow(D_8010055C_MinigameHouse, (void*)(s32)(w->unk_11 + 0x59), -1, -1);
        }
        obj->work[0] = w->unk_11;
    }
}
const char D_801002DC_MinigameHouse[] = "";
const char D_801002E0_MinigameHouse[] = "\x11\n\x12\n\x13\n\x14\n\x15\n\x16\n\x17"; /* also used by func_800FD2D0 */

void func_800FCEFC_MinigameHouse(s16 win, s32 n) {
    s32 i;

    if (func_8005949C(D_800C5728[n] - 1) == 0) {
        GwCommon.coinNum += 10;
    }
    for (i = 0; i < n; i++) {
        sprintf(D_80100658_MinigameHouse[i], D_801002D4_MinigameHouse, func_800F9D64_MinigameHouse(D_800C5728[i] - 1));
        func_8006DA5C(win, D_80100658_MinigameHouse[i], i);
    }
    func_8006DA5C(win, D_801002DC_MinigameHouse, n);
    D_800C5728[n] = 0;
    func_8006DA5C(win, D_801002DC_MinigameHouse, n);
    func_8006EB40(win);
    LoadStringIntoWindow(win, D_801002E0_MinigameHouse, -1, -1);
    while (func_8006FCC0(win) != 0) {
        HuPrcVSleep();
    }
}
void func_800FD078_MinigameHouse(void) {
    char num[8];

    func_800F6970_MinigameHouse(2);
    D_8010055C_MinigameHouse = func_80059C28();
    func_80025C20(D_80100614_MinigameHouse->model[0], D_80100614_MinigameHouse->motion[1], 0, 10, 2);
    LoadStringIntoWindow(D_8010055C_MinigameHouse, (void*)0x6C, -1, -1);
    while (func_8006FCC0(D_8010055C_MinigameHouse) != 0) {
        HuPrcVSleep();
    }
    if ((s32)GwCommon.coinNum >= D_80100100_MinigameHouse[GwSystem.unk_1E]) {
        func_8006EB40(D_8010055C_MinigameHouse);
        func_8006DA5C(D_8010055C_MinigameHouse, func_800F9D64_MinigameHouse(GwSystem.unk_1E), 0);
        sprintf(num, D_801002BC_MinigameHouse, D_80100100_MinigameHouse[GwSystem.unk_1E]);
        func_8006DA5C(D_8010055C_MinigameHouse, num, 1);
        LoadStringIntoWindow(D_8010055C_MinigameHouse, (void*)0x6D, -1, -1);
        while (func_8006FCC0(D_8010055C_MinigameHouse) != 0) {
            HuPrcVSleep();
        }
        func_8007155C(D_8010055C_MinigameHouse, (s16)(1 << GwPlayer[0].port));
        if (func_8006FCF0(D_8010055C_MinigameHouse, 1, 0) == 0) {
            GwCommon.coinNum -= D_80100100_MinigameHouse[GwSystem.unk_1E];
            func_80059B74(GwSystem.unk_1E);
            func_8006EB40(D_8010055C_MinigameHouse);
            LoadStringIntoWindow(D_8010055C_MinigameHouse, (void*)0x6E, -1, -1);
            goto wait;
        }
    }
    func_8006EB40(D_8010055C_MinigameHouse);
    LoadStringIntoWindow(D_8010055C_MinigameHouse, (void*)0x6F, -1, -1);
wait:
    while (func_8006FCC0(D_8010055C_MinigameHouse) != 0) {
        HuPrcVSleep();
    }
    func_80070D90(D_8010055C_MinigameHouse);
}
const char D_801002F0_MinigameHouse[] = "\x11\n\n\x12\n\x13\n\x14";
const char D_801002FC_MinigameHouse[] = "Will you buy\x05 5\x08 more of\nthis kind of game\xC3\xFF";
const char D_8010032C_MinigameHouse[] = "Will you buy\x05 3\x08 more of\nthis kind of game\xC3\xFF";

// register allocation (the menu-arrow object takes a spill slot; frame 8 bytes smaller) and
// float-constant hoisting (masked 38)
#ifdef NON_MATCHING
void func_800FD2D0_MinigameHouse(void) {
    unkCommonStruct0 font;
    char buf[0x68];
    char num[8];
    s32 ready[4];
    s16 wins[8];
    s16 ids[8];
    s32 sel;
    s32 rows;
    s16 listWin;
    s32 humans;
    s32 i;
    s32 j;
    s32 cur;
    s32 n;
    s32 count;
    s32 mg;
    s32 btn;
    s32 spr;
    s32 mes;
    s16 snd;
    s16 win;
    omObjData* arrow;
    omObjData* obj;
    TextWindow* w;
    char* str;
    char* msg;

    D_80100632_MinigameHouse = 0xFF;

    humans = 4;
    if (D_800C5721 != 0) {
        for (i = 0; i < 4; i++) {
            humans -= GwPlayer[i].flags & 1;
        }
        if (humans == 0) {
            humans = 1;
        }
        for (i = 0; i < 4; i++) {
            if (_CheckFlag(0x29) != 0) {
                AdjustPlayerCoins(i, GwPlayer[i].coins_mg);
            }
            GwPlayer[i].coins_mg = 0;
        }
        if (func_8005949C(GwSystem.unk_1E) == 0 && D_800C5721 != 1) {
            func_800FD078_MinigameHouse();
        }
        func_800F6970_MinigameHouse(4);
        HuPrcSleep(0x1E);
        if (D_800C5721 == 1) {
            goto next;
        }
        count = func_800FAD28_MinigameHouse(ids, 0x6E);
        spr = InitSprite(0xA0125);
        for (i = 0; i < count; i++) {
            ids[i] = func_80019060((s16)spr, 0, 1);
            SetBasicSpritePos((u16)ids[i], (i * 2 - count) * 40 + 200, 0x8E);
            func_80018D84(ids[i], 0x5000);
        }
        win = func_8006D010(0x70, 0x28, 0x60, 0x22, 0, 0);
        func_8006E070(win, 0);
        sprintf(num, D_801002BC_MinigameHouse, (D_800C5722 & 0xF) * 2 + 1);
        func_8006DA5C(win, num, 0);
        sprintf(buf, D_801002BC_MinigameHouse, (D_800C5722 & 0xF) * 2 - (n = D_800C5721 - 3));
        func_8006DA5C(win, buf, 1);
        LoadStringIntoWindow(win, (void*)0x67, -1, -1);
        while (func_8006FCC0(win) != 0) {
            HuPrcVSleep();
        }
        goto next;
    }
menu:
    func_800F6970_MinigameHouse(2);
    func_80025C20(D_80100614_MinigameHouse->model[0], D_80100614_MinigameHouse->motion[1], 0, 0xA, 2);
    func_8006EB40(D_8010055C_MinigameHouse);
    if (func_80059CE8((void*)0x69, D_8010055C_MinigameHouse) == 0) {
        func_80025C20(D_80100614_MinigameHouse->model[0], D_80100614_MinigameHouse->motion[0], 0, 0xA, 2);
        return;
    }
    func_800FA2E4_MinigameHouse();
    for (sel = 0; sel < 7; sel++) {
        if (func_800F9FF4_MinigameHouse(D_80100634_MinigameHouse, sel, buf) != 0) {
            break;
        }
    }
    if (sel == 7) {
        func_8006EB40(D_8010055C_MinigameHouse);
        LoadStringIntoWindow(D_8010055C_MinigameHouse, (void*)0x3F, -1, -1);
        while (func_8006FCC0(D_8010055C_MinigameHouse) != 0) {
            HuPrcVSleep();
        }
        func_80070D90(D_80100634_MinigameHouse);
        func_80025C20(D_80100614_MinigameHouse->model[0], D_80100614_MinigameHouse->motion[0], 0, 0xA, 2);
        return;
    }
    func_800FB238_MinigameHouse();
    func_800F6970_MinigameHouse(3);
    w = func_8006DD60(D_80100634_MinigameHouse);
    func_80066DC4(w->unk_44, 0, 0x140, w->unk_16);
    func_80070D90(D_8010055C_MinigameHouse);
    func_800FC090_MinigameHouse(buf);
    LoadStringIntoWindow(D_80100634_MinigameHouse, buf, -1, -1);
    HuPrcSleep(0x1E);
    while (func_8006FCC0(D_80100634_MinigameHouse) != 0) {
        HuPrcVSleep();
    }
    func_8006752C(w->unk_44, 1, 0);
choose:
    func_800FA470_MinigameHouse(NULL);
    D_8010055C_MinigameHouse = func_80059C28();
    obj = omAddObj(1, 0, 0, -1, func_800FCE7C_MinigameHouse);
    obj->work[0] = 0xFF;
    for (i = 0; i < 4; i++) {
        GwPlayer[i].coins = 5;
    }
    humans = func_8006FCF0(D_80100634_MinigameHouse, 0, 0) + 1;
    if (humans != 0) {
        goto players;
    }
    func_80070D90(D_80100634_MinigameHouse);
    omDelObj(obj);
    func_8006EB40(D_8010055C_MinigameHouse);
    func_80025EB4(D_8010060C_MinigameHouse->model[1], 0, 4);
    goto menu;
cpu_ok:
    PlaySound(0xF6);
    goto cpu_done;
rules_ok:
    PlaySound(0xF6);
    goto rules_done;
players:
    omDelObj(obj);
    i = 0;
    func_80070D90(D_8010055C_MinigameHouse);
    func_800FA600_MinigameHouse(NULL);
    LoadStringIntoWindow(D_80100634_MinigameHouse, (void*)0x49, -1, -1);
    func_800258EC(D_80100618_MinigameHouse->model[0], 4, 0);
    arrow = func_800FCB78_MinigameHouse();
    PlaySound(0x27);
    do {
        if (i == 0x20) {
            /* retail reuses the angle counter here: it continues from 6 */
            for (i = 0; i < 6; i++) {
                func_800258EC(D_80100568_MinigameHouse[i]->model[0], 4, 0);
            }
        }
        D_80100618_MinigameHouse->rot.z = 360.0f - (i * 90.0f) / 256.0f;
        HuPrcVSleep();
        i += 0x20;
    } while (i < 0x100);
    while (func_8006FCC0(D_80100634_MinigameHouse) != 0) {
        HuPrcVSleep();
    }
    func_800FA470_MinigameHouse(arrow);
    func_800258EC(D_80100618_MinigameHouse->model[0], 4, 4);
assign:
    for (i = 0; i < humans; i++) {
        func_80018E0C(D_80100588_MinigameHouse[i], GwPlayer[i].port);
        func_80018C90(D_80100588_MinigameHouse[i]);
        GwPlayer[i].flags = 0;
        D_80100648_MinigameHouse[i] = i;
    }
    for (; i < 4; i++) {
        func_80018E0C(D_80100588_MinigameHouse[i], GwPlayer[0].port);
        func_80018C90(D_80100588_MinigameHouse[i]);
        GwPlayer[i].flags = 1;
        D_80100648_MinigameHouse[i] = -1;
    }
pick:
    for (i = 0; i < humans; i++) {
        func_800FBFA4_MinigameHouse(i, (s16)D_80100588_MinigameHouse[i]);
        ShowBasicSprite(D_80100588_MinigameHouse[i]);
        ready[i] = 0;
    }
    msg = buf;
    while (1) {
        for (i = 0; i < humans; i++) {
            btn = ContDStkTrg[GwPlayer[i].port];
            if (ready[i] != 0) {
                if (btn & 0x4000) {
                    ShowBasicSprite(D_80100588_MinigameHouse[i]);
                    ready[i] = 0;
                    D_80100568_MinigameHouse[D_80100648_MinigameHouse[i]]->work[0] = 0;
                }
                continue;
            }
            func_800FBB28_MinigameHouse(GwPlayer[i].port, i, D_80100588_MinigameHouse[i]);
            if (btn & 0x8000) {
                PlaySound(0xF6);
                func_80018C90(D_80100588_MinigameHouse[i]);
                ready[i] = 1;
                D_80100568_MinigameHouse[D_80100648_MinigameHouse[i]]->work[0] = 1;
                for (n = 0, j = 0; j < humans; j++) {
                    n += ready[j] != 0;
                }
                if (n == humans) {
                    goto all_ready;
                }
            }
            if (btn & 0x4000) {
                PlaySound(0xF8);
                for (n = 0, j = 0; j < humans; j++) {
                    n += ready[j] == 0;
                }
                if (n == humans) {
                    for (j = 0; j < humans; j++) {
                        func_80018C90(D_80100588_MinigameHouse[j]);
                    }
                    func_800258EC(D_80100618_MinigameHouse->model[0], 4, 0);
                    PlaySound(0x27);
                    func_800FA600_MinigameHouse(arrow);
                    func_800FC090_MinigameHouse(msg);
                    LoadStringIntoWindow(D_80100634_MinigameHouse, msg, -1, -1);

                    for (j = 0x20; j < 0x100; j += 0x20) {
                        D_80100618_MinigameHouse->rot.z = (j * 90.0f) / 256.0f + 270.0f;
                        HuPrcVSleep();
                    }
                    for (i = 0; i < 6; i++) {
                        func_800258EC(D_80100568_MinigameHouse[i]->model[0], 4, 4);
                    }
                    func_8002456C(arrow->model[0]);
                    omDelObj(arrow);
                    func_800258EC(D_80100618_MinigameHouse->model[0], 4, 4);
                    while (func_8006FCC0(D_80100634_MinigameHouse) != 0) {
                        HuPrcVSleep();
                    }
                    goto choose;
                }
            }
        }
        HuPrcVSleep();
    }
all_ready:
    func_8006EB40(D_80100634_MinigameHouse);
    LoadStringIntoWindow(D_80100634_MinigameHouse, (void*)0x47, -1, -1);
    while (func_8006FCC0(D_80100634_MinigameHouse) != 0) {
        HuPrcVSleep();
    }
    for (i = 0; i < humans; i++) {
        D_80100568_MinigameHouse[D_80100648_MinigameHouse[i]]->work[0] = 2;
        D_80100568_MinigameHouse[D_80100648_MinigameHouse[i]]->work[2] = i;
    }
    for (i = humans; i < 4; i++) {
        D_80100648_MinigameHouse[i] = 0;
        for (j = 0; j < 6; j++) {
            if (func_800FBAC0_MinigameHouse(i) != 0) {
                break;
            }
            D_80100648_MinigameHouse[i]++;
        }
        func_800FBFA4_MinigameHouse(i, (s16)D_80100588_MinigameHouse[i]);
        ShowBasicSprite(D_80100588_MinigameHouse[i]);
        while (1) {
            btn = func_80059CB8();
            func_800FBB28_MinigameHouse(GwPlayer[0].port, i, D_80100588_MinigameHouse[i]);
            if (btn & 0x8000) {
                PlaySound(0xF6);
                D_80100568_MinigameHouse[D_80100648_MinigameHouse[i]]->work[0] = 1;
                func_80018C90(D_80100588_MinigameHouse[i]);
                break;
            }
            if (btn & 0x4000) {
                PlaySound(0xF8);
                func_80018C90(D_80100588_MinigameHouse[i]);
                D_80100648_MinigameHouse[i] = -1;
                if (i == humans) {
                    for (j = 0; j < 6; j++) {
                        D_80100568_MinigameHouse[j]->work[0] = 0;
                    }
                    func_8006EB40(D_80100634_MinigameHouse);
                    LoadStringIntoWindow(D_80100634_MinigameHouse, (void*)0x49, -1, -1);
                    while (func_8006FCC0(D_80100634_MinigameHouse) != 0) {
                        HuPrcVSleep();
                    }
                    goto pick;
                }
                D_80100568_MinigameHouse[D_80100648_MinigameHouse[i - 1]]->work[0] = 0;
                i -= 2;
                break;
            }
            HuPrcVSleep();
        }
        HuPrcVSleep();
    }
    for (i = 0; i < 4; i++) {
        GwPlayer[i].character = D_80100648_MinigameHouse[i];
    }
    for (i = humans; i < 4; i++) {
        D_80100568_MinigameHouse[D_80100648_MinigameHouse[i]]->work[0] = 2;
        D_80100568_MinigameHouse[D_80100648_MinigameHouse[i]]->work[2] = i;
    }
    for (i = 0; i < 4; i++) {
        func_80018C90(D_80100588_MinigameHouse[i]);
    }
    func_800FA600_MinigameHouse(arrow);
    for (i = 0; i < 6; i++) {
        if (D_80100568_MinigameHouse[i]->work[0] != 2) {
            func_800258EC(D_80100568_MinigameHouse[i]->model[0], 4, 4);
        }
    }
    w = func_8006DD60(D_80100634_MinigameHouse);
    func_80066DC4(w->unk_44, 0, 0x140, w->unk_16);
    func_8002456C(arrow->model[0]);
    omDelObj(arrow);
    if (humans == 4) {
        goto rules;
    }
    sprintf(buf, D_801002F0_MinigameHouse);
    buf[(5 - humans) * 2] = 0;
    func_8006DA5C(D_80100634_MinigameHouse, (void*)0x4C, 0);
    for (i = humans, j = 1; i < 4; i++, j++) {
        func_8006DA5C(D_80100634_MinigameHouse, (void*)(s32)(GwPlayer[i].character + 0x4D), j);
    }
    func_800FA7C0_MinigameHouse(buf);
cpu:
    for (i = humans, j = 0; i < 4; i++, j++) {
        win = func_8006D010(0xBD, j * 14 + 0x3C, 0x4A, 0x14, 0, 0);
        wins[j] = win;
        w = func_8006DD60(win);
        w->unk_04 = 0;
        w->unk_03 = 0;
        func_80066DC4(w->unk_44, 0, 0x140, w->unk_16);
        func_800674BC(w->unk_44, 0, 0x8000);
        func_800674F4(w->unk_44, 2, 0, 0x6D, 0xB7);
        func_800674F4(w->unk_44, 5, 0x1E, 0x87, 0x1A);
        func_800674F4(w->unk_44, 3, 0xE3, 0x64, 0);
        func_800674F4(w->unk_44, 4, 0xD7, 0x2E, 0x42);
        ids[j] = D_800C5724[i];
        LoadStringIntoWindow(wins[j], (void*)(s32)(ids[j] + 0x53), -1, -1);

        while (func_8006FCC0(wins[j]) != 0) {
            HuPrcVSleep();
        }
        func_8006752C(w->unk_44, 1, 0);
    }
    for (i = humans, j = 0; i < 4; i++, j++) {
        w = func_8006DD60(wins[j]);
        func_80066DC4(w->unk_44, 0, w->unk_14, w->unk_16);
    }
    cur = 0;
    func_800F69A8_MinigameHouse();
    while (1) {
        btn = func_80059CB8();
        if (btn & 0x8000) {
            goto cpu_ok;
        }
        if (btn & 0x4000) {
            PlaySound(0xF8);
            func_800F69DC_MinigameHouse();
            for (i = humans, j = 0; i < 4; i++, j++) {
                func_80070D90(wins[j]);
            }
            arrow = func_800FCCD8_MinigameHouse();
            goto assign;
        }
        if (btn & 0x800) {
            PlaySound(0xF5);
            cur--;
            if (cur < 0) {
                cur = 0;
            }
        }
        if (btn & 0x400) {
            PlaySound(0xF5);
            cur++;
            if (cur + humans >= 4) {
                cur = 3 - humans;
            }
        }
        if (btn & 0x200) {
            if (D_800C5724[cur + humans] != 0) {
                D_800C5724[cur + humans]--;
            } else {
                D_800C5724[cur + humans] = 3;
            }
        }
        if (btn & 0x100) {
            D_800C5724[cur + humans]++;
            if (D_800C5724[cur + humans] >= 4) {
                D_800C5724[cur + humans] = 0;
            }
        }
        if (ids[cur] != D_800C5724[cur + humans]) {
            PlaySound(0xF5);
            func_8006EB40(wins[cur]);
            LoadStringIntoWindow(wins[cur], (void*)(s32)(D_800C5724[cur + humans] + 0x53), -1, -1);
        }
        ids[cur] = D_800C5724[cur + humans];
        func_800F6A10_MinigameHouse(6, 0xC1, cur * 14 + 0x45);
        HuPrcVSleep();
    }
cpu_done:
    func_800F69DC_MinigameHouse();
    for (i = humans, j = 0; i < 4; i++, j++) {
        GwPlayer[i].cpu_difficulty = D_800C5724[i];
        func_80070D90(wins[j]);
    }
    func_800FA600_MinigameHouse(NULL);
rules:
    func_800FA7C0_MinigameHouse((char*)0x5D);
rules2:
    for (i = 0; i < 4; i++) {
        func_800258EC(D_80100568_MinigameHouse[D_80100648_MinigameHouse[i]]->model[0], 4, 0);
    }
    for (i = 0; i < 5; i++) {
        win = func_8006D010(0x8C, i * 28 + 0x2E, 0x64, 0x14, 0, 0);
        wins[i] = win;
        w = func_8006DD60(win);
        w->unk_04 = 0;
        w->unk_03 = 0;
        func_80066DC4(w->unk_44, 0, 0x140, w->unk_16);
        func_800674BC(w->unk_44, 0, 0x8000);
        func_800674F4(w->unk_44, 8, 0x58, 0x38, 0xC2);
        func_800FCC38_MinigameHouse(wins[i], i);
        while (func_8006FCC0(wins[i]) != 0) {
            HuPrcVSleep();
        }
        func_8006752C(w->unk_44, 1, 0);
    }
    for (i = 0; i < 5; i++) {
        w = func_8006DD60(wins[i]);
        func_80066DC4(w->unk_44, 0, w->unk_14, w->unk_16);
    }
    cur = 0;
    func_800F69A8_MinigameHouse();
    n = D_800C5722;
    while (1) {
        btn = func_80059CB8();
        if (btn & 0x8000) {
            goto rules_ok;
        }
        if (btn & 0x4000) {
            PlaySound(0xF8);
            func_800F69DC_MinigameHouse();
            for (i = 0; i < 5; i++) {
                func_80070D90(wins[i]);
            }
            if (humans == 4) {
                arrow = func_800FCCD8_MinigameHouse();
                goto assign;
            }
            func_800258EC(D_80100618_MinigameHouse->model[0], 4, 0);
            PlaySound(0x27);
            func_800FA600_MinigameHouse(NULL);
            sprintf(buf, D_801002F0_MinigameHouse);
            buf[(5 - humans) * 2] = 0;
            func_8006DA5C(D_80100634_MinigameHouse, (void*)0x4C, 0);
            for (i = humans, j = 1; i < 4; i++, j++) {
                func_8006DA5C(D_80100634_MinigameHouse, (void*)(s32)(GwPlayer[i].character + 0x4D), j);
            }
            LoadStringIntoWindow(D_80100634_MinigameHouse, buf, -1, -1);
            for (j = 0x20; j < 0x100; j += 0x20) {
                D_80100618_MinigameHouse->rot.z = (j * 90.0f) / 256.0f + 270.0f;
                HuPrcVSleep();
            }
            func_800258EC(D_80100618_MinigameHouse->model[0], 4, 4);
            while (func_8006FCC0(D_80100634_MinigameHouse) != 0) {
                HuPrcVSleep();
            }
            func_800FA470_MinigameHouse(NULL);
            goto cpu;
        }
        if (btn & 0x800) {
            PlaySound(0xF5);
            cur--;
            if (cur < 0) {
                cur = 0;
            }
        }
        if (btn & 0x400) {
            PlaySound(0xF5);
            cur++;
            if (cur >= 5) {
                cur = 4;
            }
        }
        if (btn & 0x200) {
            if (cur != 0) {
                D_800C5722 ^= 8 << cur;
            } else if (D_800C5722 & 0xF) {
                D_800C5722--;
            } else {
                D_800C5722 = (D_800C5722 & 0xF0) | 3;
            }
        }
        if (btn & 0x100) {
            if (cur != 0) {
                D_800C5722 ^= 8 << cur;
            } else if ((D_800C5722 & 0xF) < 3) {
                D_800C5722++;
            } else {
                D_800C5722 &= 0xF0;
            }
        }
        if (n != D_800C5722) {
            PlaySound(0xF5);
            func_8006EB40(wins[cur]);
            func_800FCC38_MinigameHouse(wins[cur], cur);
        }
        n = D_800C5722;
        if (cur == 0) {
            j = 4;
        } else if (cur == 1) {
            j = 9;
        } else {
            j = 2;
        }
        func_800F6A10_MinigameHouse(j, 0x90, cur * 28 + 0x37);
        HuPrcVSleep();
    }
rules_done:
    func_800F69DC_MinigameHouse();
    for (i = 0; i < 5; i++) {
        func_80070D90(wins[i]);
    }
    func_800FA600_MinigameHouse(NULL);
    func_800FA7C0_MinigameHouse((char*)0x66);
mode:
    {
        D_800C5720 = func_8006FCF0(D_80100634_MinigameHouse, 0, 0);
        if (D_800C5720 < 0) {
            func_800258EC(D_80100618_MinigameHouse->model[0], 4, 0);
            PlaySound(0x27);
            func_800FA600_MinigameHouse(NULL);
            LoadStringIntoWindow(D_80100634_MinigameHouse, (void*)0x5D, -1, -1);
            for (j = 0x20; j < 0x100; j += 0x20) {
                D_80100618_MinigameHouse->rot.z = (j * 90.0f) / 256.0f + 270.0f;
                HuPrcVSleep();
            }
            func_800258EC(D_80100618_MinigameHouse->model[0], 4, 4);
            while (func_8006FCC0(D_80100634_MinigameHouse) != 0) {
                HuPrcVSleep();
            }
            goto again;
        }
        if (D_800C5722 & 0x10) {
            if (func_800FAE94_MinigameHouse(D_800C5720) != 0) {
                PlaySound(0xF9);
                sprintf(buf, (D_800C5720 == 0 || D_800C5720 == 3) ? D_801002FC_MinigameHouse : D_8010032C_MinigameHouse);
                D_8010055C_MinigameHouse = func_80059C28();
                LoadStringIntoWindow(D_8010055C_MinigameHouse, buf, -1, -1);
                while (func_8006FCC0(D_8010055C_MinigameHouse) != 0) {
                    HuPrcVSleep();
                }
                func_80070D90(D_8010055C_MinigameHouse);
                goto mode;
            }
            if (D_800C5722 & 0x10) {
                goto order_done;
            }
        }
        func_800FA600_MinigameHouse(NULL);
        func_800F6970_MinigameHouse(9);
        HuPrcSleep(0xA);
        n = 0;
        func_8006DD60(D_80100634_MinigameHouse)->unk_14 = 0xA2;
        rows = D_800C5722 & 0xF;
        rows = rows * 2 + 1;
        listWin = func_8006D010(0x18, 0x28, 0x81, rows * 14 + 6, 0, 0);
        func_8006E070(listWin, 0);
        sel = func_800FA8D0_MinigameHouse();
        func_800F9FF4_MinigameHouse(D_80100634_MinigameHouse, sel, buf);
        func_800FA7C0_MinigameHouse(buf);
        if (rows == 0) {
            goto order_done;
        }
    order:
        func_800258EC(D_8010061C_MinigameHouse->model[1], 4, 4);
        mg = func_800FA92C_MinigameHouse(&sel);
        if (mg == 0) {
            if (n != 0) {
                n--;
                func_800FCEFC_MinigameHouse(listWin, n);
                n--;
                goto order_next;
            }
            func_80070D90(listWin);
            func_800258EC(D_80100618_MinigameHouse->model[0], 4, 0);
            PlaySound(0x27);
            func_800FA600_MinigameHouse(NULL);
            func_800F6970_MinigameHouse(3);
            HuPrcSleep(0xA);
            func_8006DD60(D_80100634_MinigameHouse)->unk_14 = 0x82;
            LoadStringIntoWindow(D_80100634_MinigameHouse, (void*)0x66, -1, -1);
            for (j = 0x20; j < 0x100; j += 0x20) {
                D_80100618_MinigameHouse->rot.z = (j * 90.0f) / 256.0f + 270.0f;
                HuPrcVSleep();
            }
            func_800258EC(D_80100618_MinigameHouse->model[0], 4, 4);
            while (func_8006FCC0(D_80100634_MinigameHouse) != 0) {
                HuPrcVSleep();
            }
            goto resume;
        }
        w = func_8006DD60(D_80100634_MinigameHouse);
        if (func_8005949C(mg - 1) == 0) {
            D_8010055C_MinigameHouse = func_80059C28();
            LoadStringIntoWindow(D_8010055C_MinigameHouse, (void*)0x6A, -1, -1);
            while (func_8006FCC0(D_8010055C_MinigameHouse) != 0) {
                HuPrcVSleep();
            }
            if ((s32)GwCommon.coinNum < 10) {
                func_80070D90(D_8010055C_MinigameHouse);
                w->unk_6E = 0;
                goto order;
            }
            if (func_80059CE8((void*)0x6B, D_8010055C_MinigameHouse) != 0) {
                func_80070D90(D_8010055C_MinigameHouse);
                GwCommon.coinNum -= 10;
                goto add;
            }
            func_80070D90(D_8010055C_MinigameHouse);
            w->unk_6E = 0;
            HuPrcVSleep();
            goto order;
        } else if ((ContBtn[GwPlayer[0].port] & 0x1000) && n < rows - 1) {
            for (; n < rows - 1; n++) {
                D_800C5728[n] = mg;
                sprintf(D_80100658_MinigameHouse[n], D_801002D4_MinigameHouse, func_800F9D64_MinigameHouse(mg - 1));
                func_8006DA5C(listWin, D_80100658_MinigameHouse[n], n);
            }
        }
    add:
        w->unk_6E = 0;
        D_800C5728[n] = mg;
        sprintf(D_80100658_MinigameHouse[n], D_801002D4_MinigameHouse, func_800F9D64_MinigameHouse(mg - 1));
        func_8006DA5C(listWin, D_80100658_MinigameHouse[n], n);
        func_8006EB40(listWin);
        LoadStringIntoWindow(listWin, (void*)D_801002E0_MinigameHouse, -1, -1);
        while (func_8006FCC0(listWin) != 0) {
            HuPrcVSleep();
        }
    order_next:
        n++;
        if (n < rows) {
            goto order;
        }
    order_done:
        if (D_800C5720 == 1 || D_800C5720 == 2) {
            func_800FA600_MinigameHouse(NULL);
            if (D_800C5722 & 0x10) {
                func_800F6970_MinigameHouse(9);
                HuPrcSleep(0xA);
                func_8006DD60(D_80100634_MinigameHouse)->unk_14 = 0xA2;
            }
            if (func_800FC410_MinigameHouse() == 0) {
                goto start;
            }
            if (D_800C5722 & 0x10) {
                LoadStringIntoWindow(D_80100634_MinigameHouse, (void*)0x66, -1, -1);
                for (i = 0x20; i < 0x100; i += 0x20) {
                    D_80100618_MinigameHouse->rot.z = (i * 90.0f) / 256.0f + 270.0f;
                    HuPrcVSleep();
                }
                func_800258EC(D_80100618_MinigameHouse->model[0], 4, 4);
                func_800F6970_MinigameHouse(3);
                HuPrcSleep(0xF);
                func_8006DD60(D_80100634_MinigameHouse)->unk_14 = 0x82;
            resume:
                func_800FA470_MinigameHouse(NULL);
                goto mode;
            }
            func_800F9FF4_MinigameHouse(D_80100634_MinigameHouse, sel, buf);
            LoadStringIntoWindow(D_80100634_MinigameHouse, buf, -1, -1);
            for (i = 0x20; i < 0x100; i += 0x20) {
                D_80100618_MinigameHouse->rot.z = (i * 90.0f) / 256.0f + 270.0f;
                HuPrcVSleep();
            }
            func_800258EC(D_80100618_MinigameHouse->model[0], 4, 4);
            func_800FA470_MinigameHouse(NULL);
            goto reorder;
        }
        for (i = 0; i < 4; i++) {
            GwPlayer[i].group = i;
        }
        D_8010055C_MinigameHouse = func_80059C28();
        if (func_80059CE8((void*)0x4B, D_8010055C_MinigameHouse) != 0) {
            goto close;
        }
        func_80070D90(D_8010055C_MinigameHouse);
        HuPrcVSleep();
        func_8006DD60(D_80100634_MinigameHouse)->unk_6E = 0;
        if (D_800C5722 & 0x10) {
            goto mode;
        }
    reorder:
        func_80070D90(listWin);
        listWin = func_8006D010(0x18, 0x28, 0x81, rows * 14 + 6, 0, 0);
        func_8006E070(listWin, 0);
        n = rows - 1;
        func_800FCEFC_MinigameHouse(listWin, n);
        goto order;
    }
close:
    func_80070D90(D_8010055C_MinigameHouse);
start:
    func_80070D90(D_80100634_MinigameHouse);
    if (!(D_800C5722 & 0x10)) {
        func_80070D90(listWin);
    }
    D_800C5721 = (D_800C5722 & 0xF) * 2 + 2;
    if (D_800C5722 & 0x20) {
        GwSystem.minigameExplanation = 1;
    } else {
        GwSystem.minigameExplanation = 0;
    }
    if (D_800C5722 & 0x40) {
        SetBoardFeatureFlag(0x29);
    } else {
        ClearBoardFeatureFlag(0x29);
    }
    func_80043460();
    for (i = 0; i < 4; i++) {
        GwPlayer[i].stars = 0;
        GwPlayer[i].coins_mg = 0;
        GwPlayer[i].coins = 0;
    }
    for (i = 0; i < 6; i++) {
        func_800258EC(D_80100568_MinigameHouse[i]->model[0], 4, 4);
        D_80100568_MinigameHouse[i]->work[0] = 0;
    }
    func_800F6970_MinigameHouse(4);
    HuPrcSleep(0x1E);
    win = func_8006D010(0x70, 0x28, 0x60, 0x14, 0, 0);
    func_8006E070(win, 0);
    sprintf(num, D_801002BC_MinigameHouse, (D_800C5722 & 0xF) * 2 + 1);
    func_8006DA5C(win, num, 0);
    str = func_8005B7E8(0x67);
    sprintf(buf, D_801002D4_MinigameHouse, str);
    func_8005B838(str);
    buf[10] = 0;
    LoadStringIntoWindow(win, buf, -1, -1);
    while (func_8006FCC0(win) != 0) {
        HuPrcVSleep();
    }
next:
    func_800FC110_MinigameHouse();
    if (--D_800C5721 == 0) {
        if (!(D_800C5722 & 0x80)) {
            count = func_800FAD28_MinigameHouse(ids, 0x50);
            switch (count) {
            case 1:
                mes = GMesCreate(4, ids[0]);
                break;
            case 2:
                mes = GMesCreate(0xF, ids[0], ids[1]);
                break;
            case 3:
                mes = GMesCreate(0x13, ids[0], ids[1], ids[2]);
                break;
            default:
                mes = GMesCreate(0x11);
                break;
            }
            for (i = 0; i < count; i++) {
                D_80100638_MinigameHouse[i]->flags &= ~2;
                snd = PlaySound((s16)(ids[i] + 0x426));

                while (func_800115C8(snd) != 0) {
                    HuPrcVSleep();
                }
            }
            if (count != 0) {
                PlaySound(0x41F);
            }
            GMesMaxWaitSet(0x78);
            while (GMesWait() != 0) {
                HuPrcVSleep();
            }
            for (i = 0; i < count; i++) {
                func_80042B10(D_80100638_MinigameHouse[i]);
            }
            func_800760E4(mes);
            func_80072724(0, 0, 0);
            func_800726AC(1, 0x14);
            func_800601D4(0x3C);
            while (func_80072718() != 0) {
                HuPrcVSleep();
            }
            func_800F6970_MinigameHouse(2);
            HuPrcSleep(0x14);
            func_80060128(7);
            SetFadeInTypeAndTime(0xFF, 0xA);
            while (func_80072718() != 0) {
                HuPrcVSleep();
            }
        }
        if (func_8005949C(GwSystem.unk_1E) == 0) {
            func_800FD078_MinigameHouse();
        }
        if (_CheckFlag(0x38) != 0 && _CheckFlag(0x39) != 0 && func_8005949C(0x35) == 0) {
            if (D_800C5722 & 0x80) {
                func_800F6970_MinigameHouse(2);
                HuPrcSleep(0x14);
            }
            func_80025C20(D_80100614_MinigameHouse->model[0], D_80100614_MinigameHouse->motion[1], 0, 0xA, 2);
            D_8010055C_MinigameHouse = func_80059C28();
            LoadStringIntoWindow(D_8010055C_MinigameHouse, (void*)0x84, -1, -1);
            while (func_8006FCC0(D_8010055C_MinigameHouse) != 0) {
                HuPrcVSleep();
            }
            func_80059B74(0x35);
            func_80070D90(D_8010055C_MinigameHouse);
        }
        func_800258EC(D_8010061C_MinigameHouse->model[1], 4, 4);
        func_800FB238_MinigameHouse();
        func_800F6970_MinigameHouse(3);
        for (i = 0; i < 4; i++) {
            D_80100648_MinigameHouse[i] = GwPlayer[i].character;
            D_80100568_MinigameHouse[D_80100648_MinigameHouse[i]]->work[0] = 2;
            D_80100568_MinigameHouse[D_80100648_MinigameHouse[i]]->work[2] = i;
        }
        func_800FA2E4_MinigameHouse();
        HuPrcSleep(0x1E);
        w = func_8006DD60(D_80100634_MinigameHouse);
        func_80066DC4(w->unk_44, 0, 0x140, w->unk_16);
        LoadStringIntoWindow(D_80100634_MinigameHouse, (void*)0x5D, -1, -1);
        while (func_8006FCC0(D_80100634_MinigameHouse) != 0) {
            HuPrcVSleep();
        }
        func_8006752C(w->unk_44, 1, 0);
    again:
        func_800FA470_MinigameHouse(NULL);
        goto rules2;

    }
    if (D_800C5722 & 0x10) {
        func_800434E4();
        func_8004501C(D_800C5720);
        while (GwSystem.unk_1E == -1) {
            HuPrcVSleep();
        }
        func_80043544();
    } else {
        func_80059348(D_800C5728[(D_800C5722 & 0xF) * 2 - (n = D_800C5721 - 1)] - 1);


    }
    switch (GwSystem.unk_1E) {
    case 0x1C:
    case 0x34:
        for (i = 0; i < 4; i++) {
            GwPlayer[i].coins += 5;
        }
        break;
    case 0x23:
        for (i = 0; i < 4; i++) {
            if (GwPlayer[i].group != 0) {
                GwPlayer[i].coins += 45;
            } else {
                GwPlayer[i].coins += 35;
            }
        }
        break;
    case 0x11:
        for (i = 0; i < 4; i++) {
            if (GwPlayer[i].group != 0) {
                GwPlayer[i].coins += 5;
            }
        }
        break;
    case 0x10:
        for (i = 0; i < 4; i++) {
            if (GwPlayer[i].group == 0) {
                GwPlayer[i].coins += 20;
            }
        }
        break;
    case 0x1F:
    case 0x32:
    case 0x33:
        for (i = 0; i < 4; i++) {
            GwPlayer[i].coins += 15;
        }
        break;
    }
    func_800F7218_MinigameHouse(GwSystem.unk_1E);
    func_800258EC(D_8010061C_MinigameHouse->model[1], 4, 0);
    func_80066DC4(font.unk_14[GMesFontCreate(&font, "PRESS ANY BUTTON", 0, -1, -1)], 0, 0xA0, 0xC4);
    while (!(func_80059CB8() & 0xD000)) {
        HuPrcVSleep();
    }
    D_80100014_MinigameHouse = 1;
    while (1) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_MinigameHouse/2CAA00", func_800FD2D0_MinigameHouse);
#endif
