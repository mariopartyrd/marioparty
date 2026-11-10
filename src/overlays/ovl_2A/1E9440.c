#include "common.h"
#include "engine/pad.h"

int abs(int);

/* ovl_2A (name_2A): a 2 vs 2 ball minigame. Two teams (GwPlayer[].group) chase one ball (D_800FE040)
   and score by putting it through the hoop object D_800FE048 (at its position + (0, 350, -560)).
   Types come from the asm's accesses; N64 offsets are in the comments. Work blocks are allocated
   with sizeof: the host strides pointers 8 bytes. */

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* A player object's work (func_8000979C allocates a MgWork, 0xE8). MgWork's layout (src/99E0.c)
   with the fields this overlay touches; its pointers sit where MgWork's do (0xB8, 0xD8, 0xE4). */
typedef struct N2APlayerWork {
    /* 0x00 */ char unk_00[0x38];
    /* 0x38 */ f32 unk_38; /* vertical speed; 1000.0f = on the ground */
    /* 0x3C */ f32 unk_3C; /* facing angle */
    /* 0x40 */ f32 unk_40; /* speed */
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48; /* radius */
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50; /* flags */
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ s8 unk_53;
    /* 0x54 */ s8 unk_54;
    /* 0x55 */ u8 unk_55;
    /* 0x56 */ s8 unk_56; /* controller port */
    /* 0x57 */ u8 unk_57;
    /* 0x58 */ s8 unk_58;
    /* 0x59 */ char unk_59[3];
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ f32 unk_60; /* camera yaw */
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ char unk_68[0x3C];
    /* 0xA4 */ f32 unk_A4;
    /* 0xA8 */ char unk_A8[9];
    /* 0xB1 */ s8 unk_B1; /* player the ball was passed to, -1 none */
    /* 0xB2 */ char unk_B2[6];
    /* 0xB8 */ void* unk_B8; /* MgWork's held item: a pointer in every view of this work */
    /* 0xBC */ f32 unk_BC;
    /* 0xC0 */ u16 unk_C0;
    /* 0xC2 */ char unk_C2[0x16];
    /* 0xD8 */ s16 (*unk_D8)[2]; /* motion table, one pair per motion */
    /* 0xDC */ void* unk_DC;
    /* 0xE0 */ s32 unk_E0;
    /* 0xE4 */ struct N2APlayerExt* unk_E4;
} N2APlayerWork; /* size = 0xE8 */

/* The overlay's per-player extension (N2APlayerWork.unk_E4; func_80023684(0xE8) in
   func_800F8940). No pointers. */
typedef struct N2APlayerExt {
    /* 0x00 */ char unk_00[0xC];
    /* 0x0C */ f32 unk_0C; /* last position */
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ char unk_18[0xC];
    /* 0x24 */ f32 unk_24; /* CPU target x */
    /* 0x28 */ f32 unk_28; /* CPU target z */
    /* 0x2C */ s32 player;
    /* 0x30 */ char unk_30[4];
    /* 0x34 */ f32 unk_34; /* stick angle */
    /* 0x38 */ f32 unk_38; /* N2APlayerWork.unk_38 this frame */
    /* 0x3C */ s32 unk_3C; /* CPU timer */
    /* 0x40 */ char unk_40[4];
    /* 0x44 */ f32 unk_44; /* N2APlayerWork.unk_38 last frame */
    /* 0x48 */ f32 unk_48; /* home x */
    /* 0x4C */ f32 unk_4C; /* home z */
    /* 0x50 */ s32 unk_50; /* controller port */
    /* 0x54 */ s32 unk_54;
    /* 0x58 */ f32 unk_58[31]; /* unk_38 history; func_800FB878 shifts [29] into [30] = unk_D0 */
    /* 0xD4 */ s32 unk_D4; /* CPU action frames */
    /* 0xD8 */ s32 unk_D8; /* CPU level 0..3 */
    /* 0xDC */ s32 unk_DC; /* CPU action flags */
    /* 0xE0 */ f32 unk_E0; /* CPU heading */
    /* 0xE4 */ s32 unk_E4; /* slot within the team */
} N2APlayerExt; /* size = 0xE8 */

#define unk_D0 unk_58[30]

/* The ball's extension (N2ABallWork.unk_68; func_80023684(0x68) in func_800FC098). No pointers. */
typedef struct N2ABallExt {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ char unk_24[0xC];
    /* 0x30 */ f32 unk_30; /* demo target x */
    /* 0x34 */ f32 unk_34; /* demo target z */
    /* 0x38 */ char unk_38[8];
    /* 0x40 */ f32 unk_40; /* vertical speed */
    /* 0x44 */ f32 unk_44; /* demo speed */
    /* 0x48 */ s32 unk_48; /* holder, -1 none */
    /* 0x4C */ s32 unk_4C; /* last frame's holder */
    /* 0x50 */ f32 unk_50; /* gravity */
    /* 0x54 */ f32 unk_54; /* bounce speed */
    /* 0x58 */ s32 unk_58; /* rest timer */
    /* 0x5C */ f32 unk_5C; /* last position */
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
} N2ABallExt; /* size = 0x68 */

/* The ball's (and the hoop's) work: main code's MgItemWork (src/99E0.c) to 0x64 -- the player
   carrying it is written at 0x64 -- then the overlay's extension pointer. */
typedef struct N2ABallWork {
    /* 0x00 */ char unk_00[0x34];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C; /* heading */
    /* 0x40 */ f32 unk_40; /* speed */
    /* 0x44 */ f32 unk_44; /* friction */
    /* 0x48 */ f32 unk_48; /* radius */
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ char unk_52[6];
    /* 0x58 */ f32 unk_58;
    /* 0x5C */ char unk_5C[8];
    /* 0x64 */ omObjData* unk_64; /* carrier: main code's MgItemWork (func_8000A634) writes it */
    /* 0x68 */ N2ABallExt* unk_68;
} N2ABallWork; /* size = 0x6C */

/* The camera objects' work (func_800F7760, func_800F7C00: 0x20). */
typedef struct N2ACamWork {
    /* 0x00 */ s32 unk_00; /* timer / bounce count */
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ s32 unk_14; /* state */
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
} N2ACamWork; /* size = 0x20 */

#define N2A_WRAP(a) ((a) >= 360.0f ? (a) - 360.0f : (a) < 0.0f ? (a) + 360.0f : (a))

/* D_800FDF60[i] for a player index that may be -1 (nobody has held the ball yet). Retail reads
   the unused bss word before the array (always 0 there); the host must not. */
#define N2A_HOLDER_FLAGS(i) (D_800FDF60_name_2A[i])

#define N2A_PLAYER(obj) ((N2APlayerWork*)(obj)->unk_50)
#define N2A_BALL(obj) ((N2ABallWork*)(obj)->unk_50)

/* ---------------------------------------------------------------------------------------------
   Bss
   --------------------------------------------------------------------------------------------- */
extern s32 D_800FDF40_name_2A;
extern f32 D_800FDF44_name_2A;
extern f32 D_800FDF48_name_2A;
extern f32 D_800FDF4C_name_2A;
extern f32 D_800FDF50_name_2A;
extern f32 D_800FDF54_name_2A; /* throw speed */
extern u16 D_800FDF58_name_2A; /* seconds left */
extern u16 D_800FDF5A_name_2A; /* frames to the next second */
extern s32 D_800FDF60_name_2A[4]; /* per-player flags; 1 = team 0 */
extern s32 D_800FDF70_name_2A; /* ball flags */
extern s32 D_800FDF74_name_2A; /* 1 = scored */
extern s32 D_800FDF78_name_2A; /* camera flags */
extern s32 D_800FDF7C_name_2A;
extern s16 D_800FDF82_name_2A; /* never written: model 0 */
extern s32 D_800FDF90_name_2A;
extern s32 D_800FDF94_name_2A;
extern s32 D_800FDF98_name_2A; /* last holder */
extern s32 D_800FDF9C_name_2A;
extern s32 D_800FDFA0_name_2A;
extern s32 D_800FDFA4_name_2A[2]; /* players placed at each basket end */
extern f32 D_800FDFAC_name_2A;
extern f32 D_800FDFB0_name_2A; /* Mini-Game Island */
extern omObjData* D_800FDFC0_name_2A; /* spotlight on team 0's second player */
extern s16 D_800FDFC4_name_2A;
extern f32 D_800FDFC8_name_2A;
extern f32 D_800FDFD0_name_2A;
extern omObjData* D_800FDFD4_name_2A;
extern omObjData* D_800FDFD8_name_2A;
extern f32 D_800FE020_name_2A;
extern s32 D_800FE024_name_2A; /* game state */
extern s16 D_800FE028_name_2A;
extern u8 D_800FE02A_name_2A;
extern omObjData* D_800FE02C_name_2A; /* ball shadow */
extern omObjData* D_800FE030_name_2A[4]; /* players */
extern omObjData* D_800FE040_name_2A; /* ball */
extern omObjData* D_800FE044_name_2A; /* spotlight on team 0's first player */
extern omObjData* D_800FE048_name_2A; /* hoop */
extern f32 D_800FE04C_name_2A;
extern s32 D_800FE050_name_2A;

/* ---------------------------------------------------------------------------------------------
   Main code
   --------------------------------------------------------------------------------------------- */
extern omObjData* D_800F2AF8[];
extern u16 D_800EE984;
extern f32 D_800ED6B8;
extern f32 D_800F5254;
extern f32 D_800B8990;

void* func_80014614(s32);
void DataCloseTemp(void*);
s32 func_80004D1C(omObjData*, Vec4f*, f32);
void func_8000A534(omObjData* obj, f32 speed);
s32 func_8000A634(omObjData* obj, omObjData* item);
void func_8000A6F4(omObjData*);
void func_80008FAC(omObjData*, f32);
void func_80008FE8(omObjData*, f32);
void func_800090C4(omObjData* obj, u8 idx, u8 val);
void func_80009E20(omObjData*);
s32 func_80017A60(omObjData*);
s32 func_800185A4(omObjData*, u16);
f32 func_80025D18(s16);
f32 func_80025D40(s16);
s16 func_80025E48(s16);
void func_80025BB8(s16, s16);
void func_80028498(s16, s16, s16);
void func_800284E4(s16);
void func_800370D4(s16);
void func_80021E58(void);
void func_80021EC0(s16, f32, f32, f32);
void func_80060F04(s16, s32, s32, s32);
/* src/6C470.c: the result spotlights */
void func_8006B9B0(omObjData* obj, f32 x, f32 y, f32 z);
void func_8006B9C0(omObjData* obj, f32 x, f32 y, f32 z);
void func_8006B9D0(omObjData* obj, f32 x, f32 y, f32 z);
void func_8006BAD0(omObjData* obj, f32 arg1);
void func_8006BADC(omObjData* obj, f32 x, f32 y, f32 z);
void func_8006BAF0(omObjData* obj, s32 arg1);
s32 func_8006BAFC(omObjData* obj);
void func_8006BB08(omObjData* obj, u16 mode);

/* ---------------------------------------------------------------------------------------------
   Overlay functions
   --------------------------------------------------------------------------------------------- */
void func_800F6810_name_2A(void);
void func_800F6880_name_2A(void);
void func_800F68E0_name_2A(omObjData* obj);
void func_800F69D8_name_2A(void);
void func_800F6A3C_name_2A(omObjData* obj);
void func_800F6AA0_name_2A(void);
void func_800F6B10_name_2A(omObjData* obj);
void func_800F6B94_name_2A(void);
void func_800F6CCC_name_2A(omObjData* obj);
void func_800F6DB8_name_2A(void);
void func_800F6DF8_name_2A(void);
void func_800F6E74_name_2A(omObjData* obj);
void func_800F6EDC_name_2A(void);
void func_800F7030_name_2A(omObjData* obj);
void func_800F7094_name_2A(void);
void func_800F7144_name_2A(omObjData* obj);
void func_800F7190_name_2A(omObjData* obj);
void func_800F71D4_name_2A(void);
void func_800F728C_name_2A(omObjData* obj);
void func_800F731C_name_2A(void);
void func_800F7350_name_2A(f32 zoom, f32 rotX, f32 rotY, f32 rotZ, f32 x, f32 y, f32 z);
void func_800F7440_name_2A(omObjData* obj);
void func_800F7760_name_2A(s32 player);
void func_800F79E8_name_2A(omObjData* obj);
void func_800F7C00_name_2A(void);
void func_800F7C84_name_2A(omObjData* obj);
void func_800F81B8_name_2A(omObjData* obj);
void func_800F836C_name_2A(omObjData* obj);
void func_800F8438_name_2A(omObjData* obj);
void func_800F84B0_name_2A(omObjData* obj);
void func_800F8530_name_2A(omObjData* obj);
void func_800F85C0_name_2A(omObjData* obj);
void func_800F878C_name_2A(omObjData* obj);
void func_800F8830_name_2A(omObjData* obj);
void func_800F8940_name_2A(omObjData* obj, s32 player);
void func_800F9050_name_2A(omObjData* obj);
void func_800F9E20_name_2A(omObjData* obj);
void func_800F9E3C_name_2A(omObjData* obj);
void func_800F9E58_name_2A(omObjData* obj);
void func_800F9E74_name_2A(omObjData* obj);
s32 func_800F9E90_name_2A(s32 player);
void func_800F9F1C_name_2A(omObjData* obj);
void func_800FA088_name_2A(omObjData* obj);
void func_800FA124_name_2A(void);
void func_800FA1CC_name_2A(omObjData* obj);
void func_800FA614_name_2A(omObjData* obj);
void func_800FA8EC_name_2A(omObjData* obj);
void func_800FAEEC_name_2A(omObjData* obj);
f32 func_800FB280_name_2A(omObjData* a, omObjData* b);
void func_800FB2DC_name_2A(N2APlayerExt* ext, s32 arg1);
void func_800FB334_name_2A(N2APlayerExt* ext);
void func_800FB3FC_name_2A(omObjData* obj);
void func_800FB6A8_name_2A(omObjData* obj);
void func_800FB6F0_name_2A(omObjData* obj);
f32 func_800FB718_name_2A(omObjData* obj);
f32 func_800FB79C_name_2A(omObjData* obj);
void func_800FB878_name_2A(N2APlayerExt* ext);
void func_800FB8BC_name_2A(void);
void func_800FBB50_name_2A(omObjData* obj);
void func_800FBFC8_name_2A(omObjData* obj);
void func_800FC098_name_2A(void);
void func_800FC364_name_2A(omObjData* obj);
void func_800FC70C_name_2A(omObjData* obj);
void func_800FC7A4_name_2A(omObjData* obj);
void func_800FC8C8_name_2A(N2ABallExt* ext);
void func_800FC990_name_2A(omObjData* obj, Vec* out);
void func_800FC9EC_name_2A(omObjData* obj, s32 player);
void func_800FCB5C_name_2A(omObjData* obj);
void func_800FD1B4_name_2A(omObjData* obj);
void func_800FD20C_name_2A(omObjData* obj);
void func_800FD254_name_2A(omObjData* obj);
void func_800FD428_name_2A(void);
void func_800FD54C_name_2A(void);
void func_800FD670_name_2A(omObjData* obj);
f32 func_800FD7D8_name_2A(omObjData* obj);
s32 func_800FD850_name_2A(s32 flags, s32 mask);
void func_800FD85C_name_2A(s32* flags, s32 mask, s32 set);
void func_800FD880_name_2A(Vec* from, Vec* to, Vec* out);
f32 func_800FDBF4_name_2A(f32 x);
void func_800FDD44_name_2A(void);

/* ---------------------------------------------------------------------------------------------
   Code
   --------------------------------------------------------------------------------------------- */

void func_800F65E0_name_2A(void) {
    func_800F6810_name_2A();
    func_80029090(5);
    func_8002ADF0(&D_800EDEC0, 0x40);
    func_80009500();
    func_8001DE70(0x3C);
    omInitObjMan(0x1E, 0);
    func_80060088();
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    func_800F7350_name_2A(2130.0f, 339.0f, 0.0f, 0.0f, 0.0f, 0.0f, -560.0f);
    func_8005D98C(4, 4);
    omAddObj(0xA, 0, 0, -1, &func_800F731C_name_2A);
    omAddObj(2, 3, 0, -1, &func_800F81B8_name_2A);
    omAddObj(2, 3, 0, -1, &func_800F836C_name_2A);
    omAddObj(2, 1, 0, -1, &func_800F84B0_name_2A);
    omAddObj(2, 1, 0, -1, &func_800F8530_name_2A);
    D_800FDF90_name_2A = 0;
    D_800FDF94_name_2A = 0;
    omAddObj(4, 0xA, 0x32, -1, &func_800F9E20_name_2A);
    omAddObj(4, 0xA, 0x32, -1, &func_800F9E3C_name_2A);
    omAddObj(4, 0xA, 0x32, -1, &func_800F9E58_name_2A);
    omAddObj(4, 0xA, 0x32, -1, &func_800F9E74_name_2A);
    func_800F6880_name_2A();
    func_800FC098_name_2A();
    func_800F7C00_name_2A();
    func_8007B168((u8*)"\x82\x60\x82\x61\x82\x62", 1); /* "ＡＢＣ" (Shift-JIS) */
    SetFadeInTypeAndTime(0, 0x10);
}

void func_800F6810_name_2A(void) {
    D_800ED440 = 0;
    D_800F2BC0 = 0;
    D_800EE984 = 0;
    D_800FE050_name_2A = 0;
    D_800FDF9C_name_2A = 0;
    D_800FDFA0_name_2A = 0;
    D_800FDFA4_name_2A[0] = 0;
    D_800FDFA4_name_2A[1] = 0;
    D_800FDFB0_name_2A = _CheckFlag(MINIGAME_ISLAND_ENDING);
}

void func_800F6880_name_2A(void) {
    omObjData* obj;

    obj = omAddObj(0, 0, 0, -1, &func_800F68E0_name_2A);
    D_800FDFD8_name_2A = obj;
    obj->unk_50 = func_80023684(sizeof(s32), 0x7918);
    D_800FE024_name_2A = 0;
}

/* Called as an object function: retail passes its object on to func_800F6E74 in a0. */
void func_800F68E0_name_2A(omObjData* obj) {
    switch (D_800FE024_name_2A) {
        case 0:
            func_800F69D8_name_2A();
            D_800ED430 = 0;
            break;
        case 1:
            func_800F6AA0_name_2A();
            break;
        case 2:
            func_800F6DF8_name_2A();
            break;
        case 3:
            func_800FD254_name_2A(D_800FE040_name_2A);
            break;
        case 6:
            func_800F6E74_name_2A(obj);
            break;
        case 4:
            func_800F6B94_name_2A();
            break;
        case 5:
            func_800F6EDC_name_2A();
            break;
        case 7:
            func_800F71D4_name_2A();
            break;
        case 8:
            func_800FD85C_name_2A(&D_800FDF7C_name_2A, 2, 1);
            break;
        case 9:
            func_800FD54C_name_2A();
            break;
        case 10:
            func_800F7094_name_2A();
            break;
    }
}

void func_800F69D8_name_2A(void) {
    omObjData* obj;
    s32* timer;

    obj = omAddObj(0x10, 0, 0, -1, &func_800F6A3C_name_2A);
    timer = func_80023684(sizeof(s32), 0x7918);
    obj->unk_50 = timer;
    *timer = 1;
    D_800FE024_name_2A = -1;
}

void func_800F6A3C_name_2A(omObjData* obj) {
    s32* timer = obj->unk_50;

    (*timer)--;
    if (*timer == 0) {
        func_800FD428_name_2A();
    }
    if (func_800FD850_name_2A(D_800FDF78_name_2A, 2) == 0) {
        D_800FE024_name_2A = 1;
        omDelObj(obj);
    }
}

void func_800F6AA0_name_2A(void) {
    omObjData* obj;

    GMesCreate(0);
    obj = omAddObj(0x10, 0, 0, -1, &func_800F6B10_name_2A);
    obj->unk_50 = func_80023684(sizeof(s32), 0x7918);
    D_800FE024_name_2A = -1;
    *(s32*)obj->unk_50 = 20;
}

void func_800F6B10_name_2A(omObjData* obj) {
    s32* timer = obj->unk_50;

    if ((GMesStatAllGet() == 0) || (GMesStatAllGet() & 2)) {
        (*timer)--;
        if (*timer == 0) {
            D_800FE024_name_2A = 2;
            D_800ED430 = 1;
            omDelObj(obj);
            func_800F6DB8_name_2A();
        }
    }
}

void func_800F6B94_name_2A(void) {
    s32 i;

    if ((D_800FDFB0_name_2A == 0.0f) && (func_800FD850_name_2A(D_800FDF74_name_2A, 1) == 0)) {
        GMesCreate(0x11);
    } else {
        GMesCreate(2);
        func_800790C0();
        if (func_800FD850_name_2A(D_800FDF74_name_2A, 1) != 0) {
            for (i = 0; i < 4; i++) {
                if (func_800FD850_name_2A(D_800FDF60_name_2A[i], 1) != 0) {
                    GwPlayer[i].coins_mg += 10;
                } else {
                    GwPlayer[i].coins_mg -= 10;
                }
            }
        }
    }
    omAddObj(0x10, 0, 0, -1, &func_800F6CCC_name_2A);
    D_800FE024_name_2A = -1;
}

void func_800F6CCC_name_2A(omObjData* obj) {
    s32* timer = D_800FDFD8_name_2A->unk_50;

    if ((GMesStatAllGet() == 0) || (GMesStatAllGet() & 2)) {
        if (D_800FDF58_name_2A == 0 && D_800FDFB0_name_2A == 0.0f) {
            D_800FE024_name_2A = 10;
        } else {
            if (D_800FDFB0_name_2A == 0.0f) {
                D_800FE024_name_2A = 6;
                func_80060128(0x36);
            } else {
                D_800FE024_name_2A = 5;
            }
            *timer = 60;
        }
        omDelObj(obj);
    }
}

void func_800F6DB8_name_2A(void) {
    D_800FDF58_name_2A = 60;
    D_800FDF5A_name_2A = 30;
    GMesCreate(8, 60, 160, 32);
}

void func_800F6DF8_name_2A(void) {
    D_800FDF5A_name_2A--;
    if (D_800FDF5A_name_2A == 0) {
        D_800FDF5A_name_2A = 30;
        D_800FDF58_name_2A--;
    }
    func_80079078(D_800FDF58_name_2A);
    if (D_800FDF58_name_2A == 0) {
        D_800FE024_name_2A = 3;
        func_800790C0();
    }
}

void func_800F6E74_name_2A(omObjData* obj) {
    s32* timer = obj->unk_50;

    (*timer)--;
    /* D_800FDF98 is -1 when nobody ever caught the ball: retail reads unused bss before the array. */
    if ((func_800FD850_name_2A(N2A_HOLDER_FLAGS(D_800FDF98_name_2A), 0x20) != 0) || (*timer == 0)) {
        D_800FE024_name_2A = 5;
    }
}

void func_800F6EDC_name_2A(void) {
    s32 chr[2];
    s32 i;

    omAddObj(0x10, 0, 0, -1, &func_800F7030_name_2A);
    if ((D_800FDFB0_name_2A == 0.0f) && (func_800FD850_name_2A(D_800FDF74_name_2A, 1) != 0)) {
        for (i = 0; i < 4; i++) {
            if (func_800FD850_name_2A(D_800FDF60_name_2A[i], 1) != 0) {
                if (N2A_PLAYER(D_800FE030_name_2A[i])->unk_E4->unk_48 == -78.0f) {
                    chr[0] = GwPlayer[i].character;
                } else {
                    chr[1] = GwPlayer[i].character;
                }
            }
        }
        GMesCreate(0xF, chr[0], chr[1]);
    }
    D_800FE024_name_2A = -1;
}

void func_800F7030_name_2A(omObjData* obj) {
    if (((GMesStatAllGet() == 0) || (GMesStatAllGet() & 2)) && (GMesWait() == 0)) {
        func_800726AC(0, 20);
        obj->func_ptr = &func_800F7190_name_2A;
    }
}

void func_800F7094_name_2A(void) {
    omObjData* obj;
    s32* timer;
    s32 i;

    obj = omAddObj(0x10, 0, 0, -1, &func_800F7144_name_2A);
    timer = obj->unk_50 = func_80023684(sizeof(s32), 0x7918);
    for (i = 0; i < 4; i++) {
        func_800FD85C_name_2A(&D_800FDF60_name_2A[i], 0x1000, 1);
    }
    func_80060128(0x34);
    D_800FE024_name_2A = -1;
    *timer = 90;
}

void func_800F7144_name_2A(omObjData* obj) {
    s32* timer = obj->unk_50;

    (*timer)--;
    if (*timer == 0) {
        func_800726AC(0, 20);
        obj->func_ptr = &func_800F7190_name_2A;
    }
}

void func_800F7190_name_2A(omObjData* obj) {
    if (func_80072718() == 0) {
        omOvlReturnEx(1);
        func_800601D4(40);
        omDelObj(obj);
    }
}

void func_800F71D4_name_2A(void) {
    omObjData* obj;
    s32* timer;
    s32 n;
    s32 i;

    n = 0;
    for (i = 0; i < 4; i++) {
        n += func_800FD850_name_2A(D_800FDF60_name_2A[i], 0x80);
    }
    if (n == 0) {
        D_800FE024_name_2A = -1;
        obj = omAddObj(0x10, 0, 0, -1, &func_800F728C_name_2A);
        timer = func_80023684(sizeof(s32), 0x7918);
        obj->unk_50 = timer;
        *timer = 30;
        D_800ED430 = 0;
    }
}

void func_800F728C_name_2A(omObjData* obj) {
    s32* timer = obj->unk_50;

    fontcolor = 0xE;
    sprintf(pfStrBuf, "READY!");
    print8(0x88, 0x70, pfStrBuf);
    (*timer)--;
    if (*timer == 0) {
        D_800FE024_name_2A = 2;
        D_800ED430 = 1;
        omDelObj(obj);
    }
}

void func_800F731C_name_2A(void) {
    if (D_800F5144 != 0) {
        func_800601D4(40);
        omOvlReturnEx(1);
    }
}

void func_800F7350_name_2A(f32 zoom, f32 rotX, f32 rotY, f32 rotZ, f32 x, f32 y, f32 z) {
    func_800178A0(1);
    CZoom = zoom;
    CRot.x = rotX;
    CRot.y = rotY;
    CRot.z = rotZ;
    Center.x = x;
    Center.y = y;
    Center.z = z;
    D_800FDFD0_name_2A = x;
    D_800FDFC8_name_2A = y;
    D_800FE04C_name_2A = z;
    D_800FE020_name_2A = rotX;
    D_800FDFAC_name_2A = 45.0f;
    omAddObj(0xE, 0, 0, -1, &func_800F7440_name_2A);
}

void func_800F7440_name_2A(omObjData* obj) {
    f32 dist;
    f32 d;
    f32 dx;
    f32 dz;
    f32 zoom;
    f32 rot;
    f32 cx;
    f32 cz;
    s32 i;

    if (func_800FD850_name_2A(D_800FDF78_name_2A, 1) != 0) {
        omDelObj(obj);
        return;
    }
    if (func_800FD850_name_2A(D_800FDF78_name_2A, 2) == 0) {
        if ((func_800FD850_name_2A(D_800FDF70_name_2A, 8) != 0) && (func_800FD850_name_2A(D_800FDF74_name_2A, 1) == 0)) {
            Center.x = D_800FE048_name_2A->trans.x + 0.0f;
            Center.y = D_800FE048_name_2A->trans.y + 350.0f + 100.0f;
            Center.z = D_800FE048_name_2A->trans.z + -560.0f;
            CZoom = 400.0f;
            return;
        }
        dist = 0.0f;
        cx = 650.0f;
        cz = -650.0f;
        for (i = 0; i < 4; i++) {
            dx = D_800FE030_name_2A[i]->trans.x;
            dz = D_800FE030_name_2A[i]->trans.z;
            d = sqrtf((dx - cx) * (dx - cx) + (dz - cz) * (dz - cz));
            if (dist < d) {
                dist = d;
            }
        }
        dx = D_800FE040_name_2A->trans.x;
        dz = D_800FE040_name_2A->trans.z;
        d = sqrtf((dx - cx) * (dx - cx) + (dz - cz) * (dz - cz));
        if (dist < d) {
            dist = d;
        }
        zoom = dist * 1.03f + 657.0f;
        if (zoom > 2105.0f) {
            zoom = 2105.0f;
        }
        if (zoom < 1480.0f) {
            zoom = 1480.0f;
        }
        rot = dist * -0.051 + 72.93000030517578;
        if (rot < 0.0f) {
            rot = 0.0f;
        }
        if (rot > 32.0f) {
            rot = 32.0f;
        }
        CZoom = zoom;
        CRot.y = rot;
        CRot.x = D_800FE020_name_2A;
        Center.x = D_800FDFD0_name_2A;
        Center.y = D_800FDFC8_name_2A;
        Center.z = D_800FE04C_name_2A;
    }
}

void func_800F7760_name_2A(s32 player) {
    Vec from;
    Vec to;
    Vec out;
    omObjData* obj;
    N2ACamWork* work;

    obj = omAddObj(0xE, 0, 0, -1, &func_800F79E8_name_2A);
    work = func_80023684(sizeof(N2ACamWork), 0x7918);
    obj->unk_50 = work;
    work->unk_00 = 0;
    Center.x = 0.0f;
    Center.y = 60.0f;
    Center.z = -300.0f;
    func_800FD85C_name_2A(&D_800FDF78_name_2A, 1, 1);
    from.x = D_800FE030_name_2A[player]->trans.x;
    from.y = D_800FE030_name_2A[player]->trans.y;
    from.z = D_800FE030_name_2A[player]->trans.z;
    to.x = func_800AEAC0(CRot.y) * func_800AEFD0(CRot.x) * CZoom + Center.x;
    to.y = from.y;
    to.z = func_800AEFD0(CRot.y) * func_800AEFD0(CRot.x) * CZoom + Center.z;
    func_800FD880_name_2A(&from, &to, &out);
    D_800FE030_name_2A[player]->rot.y = out.z;
    N2A_PLAYER(D_800FE030_name_2A[player])->unk_3C = 0.0f;
    to.x = func_800AEAC0(CRot.y) * func_800AEFD0(CRot.x) * CZoom + Center.x;
    to.y = -func_800AEAC0(CRot.x) * CZoom + Center.y;
    to.z = func_800AEFD0(CRot.y) * func_800AEFD0(CRot.x) * CZoom + Center.z;
    func_800FD880_name_2A(&from, &to, &out);
    work->unk_04 = -out.x / 15.0f;
    work->unk_08 = (360.0f - CRot.x) / 25.0f;
    work->unk_0C = -CRot.y / 25.0f;
    work->unk_10 = 0.0f;
}

void func_800F79E8_name_2A(omObjData* obj) {
    N2ACamWork* work = obj->unk_50;
    f32 minZoom;
    s32 i;

    minZoom = 400.0f;
    for (i = 0; i < 4; i++) {
        if ((func_800FD850_name_2A(D_800FDF60_name_2A[i], 1) != 0) && (GwPlayer[i].character == 5)) {
            minZoom = 470.0f;
        }
    }
    CZoom += work->unk_04;
    CRot.y += work->unk_0C;
    CRot.z += work->unk_10;
    if (CZoom < minZoom && !(work->unk_00 & 1)) {
        if (work->unk_00 == 0) {
            work->unk_04 = -126.3f;
        }
        work->unk_00++;
        work->unk_04 = -work->unk_04;
    }
    if (minZoom + 252.6f - 1.0f < CZoom && (work->unk_00 & 1)) {
        work->unk_00++;
        work->unk_04 = -work->unk_04;
    }
    if (work->unk_00 == 5) {
        D_800FE024_name_2A = 4;
        for (i = 0; i < 4; i++) {
            if (func_800FD850_name_2A(D_800FDF60_name_2A[i], 1) != 0) {
                func_800FD85C_name_2A(&D_800FDF60_name_2A[i], 0x400, 1);
            } else {
                func_800FD85C_name_2A(&D_800FDF60_name_2A[i], 0x1000, 1);
            }
        }
        omDelObj(obj);
    }
}

void func_800F7C00_name_2A(void) {
    omObjData* obj;
    N2ACamWork* work;

    obj = omAddObj(0xE, 0, 0, -1, &func_800F7C84_name_2A);
    work = func_80023684(sizeof(N2ACamWork), 0x7918);
    obj->unk_50 = work;
    work->unk_00 = 1;
    work->unk_14 = 0;
    work->unk_18 = 1.0f;
    work->unk_1C = 0.0f;
    func_800FD85C_name_2A(&D_800FDF78_name_2A, 2, 1);
}

/* Intro camera: a close-up of player 1's character, then a pull back to the court. */
void func_800F7C84_name_2A(omObjData* obj) {
    f32 x[6] = { 35.0f, 35.0f, 35.0f, 35.0f, 35.0f, 35.0f };
    f32 y[6] = { 78.0f, 85.0f, 80.0f, 79.0f, 83.0f, 80.0f };
    f32 z[6] = { -20.0f, -20.0f, -20.0f, -20.0f, -20.0f, -20.0f };
    f32 zoom[6] = { 200.0f, 220.0f, 220.0f, 200.0f, 230.0f, 230.0f };
    N2ACamWork* work = obj->unk_50;

    switch (work->unk_14) {
        case 0:
            if (--work->unk_00 == 0) {
                D_800FE02A_name_2A = GwPlayer[0].character;
                work->unk_14++;
                work->unk_00 = 22;
                Center.x = x[D_800FE02A_name_2A] + -200.0f;
                Center.y = y[D_800FE02A_name_2A];
                Center.z = z[D_800FE02A_name_2A] + 500.0f;
                CRot.x = 360.0f;
                CRot.y = 180.0f;
                CZoom = zoom[D_800FE02A_name_2A];
            }
            break;
        case 1:
            if (--work->unk_00 == 0) {
                D_800FDFC4_name_2A = PlaySound(0x30B);
                work->unk_14++;
                work->unk_00 = 8;
            }
            break;
        case 2:
            if (--work->unk_00 == 0) {
                func_80060128(0x1F);
                work->unk_14++;
                work->unk_00 = 60;
            }
            break;
        case 3:
            if (--work->unk_00 == 0) {
                work->unk_14++;
                work->unk_00 = 75;
            }
            break;
        case 4:
            CRot.y += 2.4f;
            if (CRot.y > 360.0f) {
                CRot.y = 0.0f;
            }
            CRot.x -= 0.28f;
            if (CRot.x < 339.0f) {
                CRot.x = 339.0f;
            }
            if (CZoom < 2130.0f) {
                CZoom += work->unk_18;
                work->unk_18 += work->unk_1C;
                work->unk_1C += 0.03f;
                if (CZoom > 2130.0f) {
                    CZoom = 2130.0f;
                }
            }
            Center.x += (0.0f - (x[D_800FE02A_name_2A] + -200.0f)) / 75.0f;
            if (Center.x > 0.0f) {
                Center.x = 0.0f;
            }
            Center.y += (0.0f - y[D_800FE02A_name_2A]) / 75.0f;
            if (Center.y < 0.0f) {
                Center.y = 0.0f;
            }
            Center.z += (z[D_800FE02A_name_2A] + -1060.0f) / 75.0f;
            if (Center.z < -560.0f) {
                Center.z = -560.0f;
            }
            if (--work->unk_00 == 0) {
                CZoom = 2130.0f;
                CRot.x = 339.0f;
                CRot.y = 0.0f;
                CRot.z = 0.0f;
                Center.x = 0.0f;
                Center.y = 0.0f;
                Center.z = -560.0f;
                func_800FD85C_name_2A(&D_800FDF78_name_2A, 2, 0);
                omDelObj(obj);
            }
            break;
    }
}

void func_800F81B8_name_2A(omObjData* obj) {
    unkGlobalStruct_02* work;
    void* data;

    func_80017660(0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    obj->unk_50 = func_80023684(sizeof(unkGlobalStruct_02), 0x7918);
    D_800FDFD4_name_2A = obj;
    work = obj->unk_50;
    obj->model[0] = func_800174C0(0x3E0000, 0x699);
    obj->model[1] = func_800174C0(0x3E0008, 0x689);
    data = func_80014614(0x27);
    func_80038A9C(D_800F2B7C[obj->model[1]].unk_6C, data, 0, "00mt001s_IA44");
    func_80025AD4(obj->model[1]);
    func_80025B34(obj->model[1]);
    DataCloseTemp(data);
    func_800090B8(D_800ED440);
    D_800F2AF8[D_800ED440++] = obj;
    func_8009B770(obj->unk_50, 0, sizeof(unkGlobalStruct_02));
    work->unk_04 = 1;
    work->unk_05 = 0;
    func_800F878C_name_2A(obj);
    func_80009090(obj);
    obj->func_ptr = &func_800FDD44_name_2A;
}

void func_800F836C_name_2A(omObjData* obj) {
    obj->model[0] = LoadFormFile(0x3E0002, 0x299);
    obj->model[1] = LoadFormFile(0x3E0003, 0x29D);
    obj->model[2] = LoadFormFile(0x3E0007, 0x29D);
    omSetTra(obj, 0.0f, 0.0f, 0.0f);
    func_80025798(obj->model[1], 0.0f, 0.0f, 0.0f);
    func_80025798(obj->model[2], 0.0f, 0.0f, 0.0f);
    omSetRot(obj, 0.0f, 0.0f, 0.0f);
    obj->func_ptr = &func_800F8438_name_2A;
}

void func_800F8438_name_2A(omObjData* obj) {
    if (func_800FD850_name_2A(D_800FDF74_name_2A, 1) != 0) {
        func_800258EC(obj->model[0], 4, 4);
        func_800258EC(obj->model[1], 4, 0);
        func_800258EC(obj->model[2], 4, 0);
        omDelObj(obj);
    }
}

void func_800F84B0_name_2A(omObjData* obj) {
    obj->unk_50 = func_80023684(sizeof(N2ABallWork), 0x7918);
    obj->model[0] = LoadFormFile(0x3E0004, 0x699);
    obj->func_ptr = NULL;
    omSetTra(obj, 0.0f, 0.0f, 0.0f);
    omSetRot(obj, 0.0f, 0.0f, 0.0f);
    obj->func_ptr = &func_800FDD44_name_2A;
}

void func_800F8530_name_2A(omObjData* obj) {
    D_800FE048_name_2A = obj;
    obj->unk_50 = func_80023684(sizeof(N2ABallWork), 0x7918);
    obj->model[0] = LoadFormFile(0x3E0005, 0x699);
    obj->func_ptr = NULL;
    omSetTra(obj, 0.0f, 0.0f, 0.0f);
    omSetRot(obj, 0.0f, 0.0f, 0.0f);
    D_800FDF74_name_2A = 0;
    obj->func_ptr = &func_800F85C0_name_2A;
}

/* The hoop: a ball coming down through the ring scores. */
void func_800F85C0_name_2A(omObjData* obj) {
    N2ABallExt* ball;
    f32 dx;
    f32 dy;
    f32 dz;

    if (func_800FD850_name_2A(D_800FDF70_name_2A, 4) == 0) {
        ball = N2A_BALL(D_800FE040_name_2A)->unk_68;
        if (ball->unk_48 == -1) {
            dx = obj->trans.x + 0.0f - D_800FE040_name_2A->trans.x;
            dy = obj->trans.y + 350.0f - D_800FE040_name_2A->trans.y;
            dz = obj->trans.z + -560.0f - D_800FE040_name_2A->trans.z;
            if (func_800B1750(dx * dx + dy * dy + dz * dz) < 115.0 && func_800FD850_name_2A(D_800FDF74_name_2A, 1) == 0) {
                if (dy <= -10.0f) {
                    func_800258EC(obj->model[0], 4, 4);
                    func_800FD85C_name_2A(&D_800FDF74_name_2A, 1, 1);
                    func_800258EC(D_800FDF82_name_2A, 4, 0);
                    func_800FD1B4_name_2A(D_800FE040_name_2A);
                    if (func_800FD850_name_2A(D_800FDF70_name_2A, 8) != 0) {
                        func_80060F04((s16)D_800FDF98_name_2A, 10, 0, 10);
                    }
                    func_800FB8BC_name_2A();
                } else if (ball->unk_40 >= 0.0f) {
                    ball->unk_40 = -ball->unk_40;
                }
            }
        }
    }
}

void func_800F878C_name_2A(omObjData* obj) {
    omObjData* shadow;

    shadow = omAddObj(0xF, 2, 0, -1, &func_800F8830_name_2A);
    shadow->model[0] = LoadFormFile(0x210001, 0x699);
    shadow->model[1] = func_80023FC8(shadow->model[0]);
    D_800FE02C_name_2A = shadow;
    func_80025798(shadow->model[0], 0.0f, 4.0f, 0.0f);
    func_80025798(shadow->model[1], 0.0f, 4.0f, 0.0f);
}

void func_800F8830_name_2A(omObjData* obj) {
    s32 team[2];
    s32 n;
    s32 i;

    if (func_800FD850_name_2A(D_800FDF70_name_2A, 4) != 0) {
        func_8002456C(obj->model[0]);
        omDelObj(obj);
        return;
    }
    n = 0;
    for (i = 0; i < 4; i++) {
        if (func_800FD850_name_2A(D_800FDF60_name_2A[i], 1) != 0) {
            team[n] = i;
            n++;
        }
    }
    omSetTra(obj, D_800FE030_name_2A[team[0]]->trans.x, 4.0f, D_800FE030_name_2A[team[0]]->trans.z);
    func_80025798(obj->model[1], D_800FE030_name_2A[team[1]]->trans.x, 4.0f, D_800FE030_name_2A[team[1]]->trans.z);
}

void func_800F8940_name_2A(omObjData* obj, s32 player) {
    f32 posX[4] = { -200.0f, 200.0f, -200.0f, 200.0f };
    f32 posZ[4] = { 500.0f, 500.0f, 200.0f, 200.0f };
    f32 rotY[4] = { 180.0f, 180.0f, 0.0f, 0.0f };
    N2APlayerWork* work;
    N2APlayerExt* ext;
    s32 dir;
    s32 file;
    s32 slot;
    s32 i;

    D_800FE02A_name_2A = GwPlayer[player].character;
    D_800FDF60_name_2A[player] = 0;
    if (GwPlayer[player].group == 0) {
        func_800FD85C_name_2A(&D_800FDF60_name_2A[player], 1, 1);
    }
    dir = D_800C59AC[D_800FE02A_name_2A].unk_00;
    file = D_800C59AC[D_800FE02A_name_2A].unk_08;
    func_8000979C(obj, dir, file, player, 0x699, 0x699);
    slot = 0;
    if (func_800FD850_name_2A(D_800FDF60_name_2A[player], 1) != 0) {
        slot = D_800FDF90_name_2A;
    } else {
        slot += 2 + D_800FDF94_name_2A;
    }
    omSetTra(obj, posX[slot], 0.0f, posZ[slot]);
    if (func_800FD850_name_2A(D_800FDF60_name_2A[player], 1) != 0) {
        D_800FDF90_name_2A++;
    } else {
        D_800FDF94_name_2A++;
    }
    work = obj->unk_50;
    ext = work->unk_E4 = func_80023684(sizeof(N2APlayerExt), 0x7918);
    ext->unk_50 = work->unk_56;
    obj->model[3] = LoadFormFile(0x19, 0x68D);
    obj->model[4] = LoadFormFile(0x1A, 0x68D);
    func_800187D0(obj, 0, dir, 1, 0);
    func_800187D0(obj, 1, dir | 1, 1, 0);
    func_800187D0(obj, 2, dir | 3, 1, 0);
    func_800187D0(obj, 6, dir | 5, 1, 0x13);
    if (rand8() & 1) {
        func_800187D0(obj, 0xD, dir | 0xF, 1, 0x78);
    } else {
        func_800187D0(obj, 0xD, dir | 0x38, 1, 0x78);
    }
    if (rand8() & 1) {
        func_800187D0(obj, 0xE, dir | 0x10, 1, 0x78);
    } else {
        func_800187D0(obj, 0xE, dir | 0x3C, 1, 0x78);
    }
    func_800187D0(obj, 5, dir | 4, 0, 0);
    func_800187D0(obj, 0x15, dir | 0x62, 0, 0);
    func_800187D0(obj, 0x14, dir | 0x5F, 2, 0);
    func_800187D0(obj, 0x1E, dir | 0x63, 0, 0);
    func_800187D0(obj, 0x1F, dir | 0x64, 0, 0);
    func_800187D0(obj, 0x23, dir | 0x4F, 1, 0);
    func_800187D0(obj, 0x24, dir | 0x72, 1, 0);
    func_800187D0(obj, 0x25, dir | 0x73, 1, 0);
    func_800187D0(obj, 0x26, dir | 0x24, 2, 0);
    func_800187D0(obj, 0x28, dir | 0x50, 2, 0);
    func_800187D0(obj, 0x29, dir | 0x51, 2, 0);
    work->unk_48 = 60.0f;
    work->unk_38 = 1000.0f;
    work->unk_50 = 0;
    work->unk_60 = 0.0f;
    work->unk_B1 = -1;
    work->unk_3C = rotY[slot];
    func_80008FE8(obj, 20.0f);
    ext->player = player;
    ext->unk_44 = 1000.0f;
    ext->unk_3C = 0;
    ext->unk_0C = 0.0f;
    ext->unk_10 = 0.0f;
    ext->unk_14 = 0.0f;
    ext->unk_D4 = 0;
    ext->unk_DC = 0;
    ext->unk_E0 = 0.0f;
    ext->unk_34 = 0.0f;
    ext->unk_D0 = ext->unk_34;
    if (func_800FD850_name_2A(D_800FDF60_name_2A[player], 1) != 0) {
        ext->unk_E4 = D_800FDF9C_name_2A;
        D_800FDF9C_name_2A++;
    } else {
        ext->unk_E4 = D_800FDFA0_name_2A;
        D_800FDFA0_name_2A++;
    }
    if (!(GwPlayer[player].flags & 1)) {
        ext->unk_D8 = 1;
    } else {
        switch (GwPlayer[player].cpu_difficulty) {
            case 0:
                ext->unk_D8 = 0;
                break;
            case 1:
                ext->unk_D8 = 1;
                break;
            case 2:
                ext->unk_D8 = 2;
                break;
            case 3:
                ext->unk_D8 = 3;
                break;
        }
    }
    func_800FB2DC_name_2A(ext, 0);
    func_800FB334_name_2A(ext);
    D_800FE030_name_2A[player] = obj;
    func_800090C4(obj, 0, 2);
    func_800090C4(obj, 1, 2);
    D_800F3FB0[D_800F2BC0++] = obj;
    func_800184BC(obj, 0);
    ContStkX[work->unk_56] = ContStkY[work->unk_56] = 0;
    ContBtn[work->unk_56] &= 0x7FFF;
    ContBtnTrg[work->unk_56] &= 0x7FFF;
    switch (GwPlayer[player].cpu_difficulty) {
        case 0:
            ext->unk_D8 = 0;
            break;
        case 1:
            ext->unk_D8 = 1;
            break;
        case 2:
            ext->unk_D8 = 2;
            break;
        case 3:
            ext->unk_D8 = 3;
            break;
    }
    D_800ED430 = 0;
    obj->func_ptr = &func_800F9050_name_2A;
    for (i = 0; i < 30; i++) {
        ext->unk_58[i] = 0.0f;
    }
}

/* A player's frame: input (CPU or pad), catching, passing, shooting, and the after-goal walk. */
// register allocation: retail keeps a second copy of the hit flags and the ball pointer in s6
#ifdef NON_MATCHING
void func_800F9050_name_2A(omObjData* obj) {
    Vec from;
    Vec to;
    Vec out;
    N2APlayerWork* work = obj->unk_50;
    N2APlayerExt* ext = work->unk_E4;
    N2ABallExt* ball;
    s32 hit;
    s32 hit2;
    s16 motion;
    f32 mag;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 a;

    ext->unk_38 = work->unk_38;
    func_80017A60(obj);
    ball = NULL;
    if (func_800FD850_name_2A(D_800FDF70_name_2A, 4) == 0) {
        ball = N2A_BALL(D_800FE040_name_2A)->unk_68;
    }
    work->unk_60 = CRot.y;
    from.x = obj->trans.x;
    from.y = obj->trans.y;
    from.z = obj->trans.z;
    to.x = func_800AEAC0(CRot.y) * func_800AEFD0(CRot.x) * CZoom + Center.x;
    to.y = -func_800AEAC0(CRot.x) * CZoom + Center.y;
    to.z = func_800AEFD0(CRot.y) * func_800AEFD0(CRot.x) * CZoom + Center.z;
    func_800FD880_name_2A(&from, &to, &out);
    if (out.x < work->unk_48 * 3.0f) {
        func_800258EC(obj->model[0], 4, 4);
    } else {
        func_800258EC(obj->model[0], 4, 0);
    }
    if (func_800FD850_name_2A(D_800FDF60_name_2A[ext->player], 2) != 0) {
        return;
    }
    if (GwPlayer[ext->player].flags & 1) {
        ContStkX[work->unk_56] = 0;
        ContStkY[work->unk_56] = 0;
        ContBtn[work->unk_56] = 0;
        ContBtnTrg[work->unk_56] = 0;
        if (func_800FD850_name_2A(D_800FDF70_name_2A, 4) == 0) {
            func_800FA614_name_2A(obj);
        }
    }
    if (func_800FD850_name_2A(D_800FDF60_name_2A[ext->player], 0x20000) != 0) {
        ContStkX[work->unk_56] = 0;
        ContStkY[work->unk_56] = 0;
        ContBtn[work->unk_56] = 0;
        ContBtnTrg[work->unk_56] = 0;
        func_800FBB50_name_2A(obj);
    }
    if (func_800FD850_name_2A(D_800FDF60_name_2A[ext->player], 0x40000) != 0) {
        ContStkX[work->unk_56] = 0;
        ContStkY[work->unk_56] = 0;
        ContBtn[work->unk_56] = 0;
        ContBtnTrg[work->unk_56] = 0;
    }
    func_80005A28(obj);
    work->unk_3C = N2A_WRAP(work->unk_3C);
    if (func_800FD850_name_2A(D_800FDF60_name_2A[ext->player], 1) != 0 &&
        func_800FD850_name_2A(D_800FDF60_name_2A[ext->player], 0x200) == 0) {
        obj->trans.y += 3.0f;
    }
    hit2 = hit = func_80017A60(obj);
    if (func_800FD850_name_2A(D_800FDF60_name_2A[ext->player], 0x4000) != 0) {
        /* Holding the ball. */
        if (func_800FD850_name_2A(D_800FDF60_name_2A[ext->player], 0x8000) != 0) {
            func_800186E4(obj, 0, 0x23);
            func_800186E4(obj, 1, 0x24);
            func_800186E4(obj, 2, 0x25);
            func_800FD85C_name_2A(&D_800FDF60_name_2A[ext->player], 0x8000, 0);
            if (hit & 2) {
                func_800185A4(obj, 0);
            }
            if (hit2 & 4) {
                func_800185A4(obj, 2);
            }
        }
        if (work->unk_38 != 1000.0f && ext->unk_44 == 1000.0f) {
            if (work->unk_D8[0x26][0] & 4) {
                motion = obj->motion[0x26] & 0x3FFF;
            } else {
                motion = func_80025E48(obj->motion[0x26] & 0x3FFF);
            }
            func_80028498(obj->model[0], motion, 2);
            func_800FD85C_name_2A(&D_800FDF60_name_2A[ext->player], 0x100, 1);
            func_800186E4(obj, 0x14, 0x28);
        }
        if ((hit2 & 6) && (func_80025D18(obj->model[0]) == 12.0f || func_80025D18(obj->model[0]) == 34.0f ||
                          func_80025D18(obj->model[0]) == 56.0f)) {
            D_800FE028_name_2A = PlaySound(0x30C);
        }
    } else if (func_800FD850_name_2A(D_800FDF60_name_2A[ext->player], 0x8000) != 0) {
        func_800186E4(obj, 0, 0x23);
        func_800186E4(obj, 1, 0x24);
        func_800186E4(obj, 2, 0x25);
        func_800FD85C_name_2A(&D_800FDF60_name_2A[ext->player], 0x8000, 0);
        if (hit2 & 2) {
            func_800185A4(obj, 0);
        }
    } else if (D_800ED430 == 0 ||
               (D_800ED430 == 1 && D_800FE024_name_2A == 2 && func_800FD850_name_2A(D_800FDF70_name_2A, 4) == 0)) {
        /* Free ball close enough: catch it. */
        dx = obj->trans.x - D_800FE040_name_2A->trans.x;
        dy = obj->trans.y - D_800FE040_name_2A->trans.y;
        dz = obj->trans.z - D_800FE040_name_2A->trans.z;
        if (func_800B1750(dx * dx + dy * dy + dz * dz) < 90.0 && ball->unk_48 == -1) {
            func_800FC9EC_name_2A(D_800FE040_name_2A, ext->player);
            if (func_800FD850_name_2A(D_800FDF60_name_2A[ext->player], 1) == 0) {
                func_800FA124_name_2A();
            }
        }
    }
    if (work->unk_38 != 1000.0f && func_800FD850_name_2A(D_800FDF60_name_2A[ext->player], 0x4000) != 0 &&
        (ContBtnTrg[work->unk_56] & 0x4000) && func_800FD850_name_2A(D_800FDF70_name_2A, 4) == 0 &&
        func_800FB718_name_2A(obj) < 150.0f) {
        /* B in the air near the hoop: dunk. */
        func_800186E4(obj, 0x14, 0x29);
        func_800FD85C_name_2A(&D_800FDF60_name_2A[ext->player], 0x40, 1);
        func_800FD85C_name_2A(&D_800FDF70_name_2A, 8, 1);
    }
    if (work->unk_38 == 1000.0f && ext->unk_44 != 1000.0f) {
        func_800284E4(obj->model[0]);
        func_800FD85C_name_2A(&D_800FDF60_name_2A[ext->player], 0x100, 0);
        func_800FD85C_name_2A(&D_800FDF60_name_2A[ext->player], 0x40, 0);
        func_800186E4(obj, 0x14, 0x28);
    }
    if (work->unk_38 == 1000.0f || D_800FE024_name_2A == 4) {
        if (func_800FD850_name_2A(D_800FDF60_name_2A[ext->player], 0x200) != 0) {
            a = func_80025D18(obj->model[0]);
            if (func_80025D40(obj->model[0]) <= a) {
                func_800FD85C_name_2A(&D_800FDF60_name_2A[ext->player], 0x200, 0);
                func_800FD85C_name_2A(&D_800FDF60_name_2A[ext->player], 0x20, 1);
                func_800FD85C_name_2A(&D_800FDF60_name_2A[ext->player], 2, 1);
            }
        } else if (D_800FDFB0_name_2A == 0.0f) {
            /* Result poses (win 0x400, lose 0x1000). */
            if (func_800FD850_name_2A(D_800FDF60_name_2A[ext->player], 0x400) != 0) {
                work->unk_40 = D_800B8990;
                if (func_800FD850_name_2A(D_800FDF60_name_2A[ext->player], 0x8000) != 0) {
                    func_800186E4(obj, 0, 0x23);
                    func_800186E4(obj, 1, 0x24);
                    func_800186E4(obj, 2, 0x25);
                }
                func_8000A6F4(obj);
                func_800185A4(obj, 0xD);
                func_800FD85C_name_2A(&D_800FDF60_name_2A[ext->player], 0x200, 1);
                func_800FD85C_name_2A(&D_800FDF60_name_2A[ext->player], 0x4000, 0);
                func_800FD85C_name_2A(&D_800FDF60_name_2A[ext->player], 0x400, 0);
                work->unk_3C = 0.0f;
            }
            if (D_800FDFB0_name_2A == 0.0f && func_800FD850_name_2A(D_800FDF60_name_2A[ext->player], 0x1000) != 0) {
                work->unk_40 = D_800B8990;
                if (func_800FD850_name_2A(D_800FDF60_name_2A[ext->player], 0x8000) != 0) {
                    func_800186E4(obj, 0, 0x23);
                    func_800186E4(obj, 1, 0x24);
                    func_800186E4(obj, 2, 0x25);
                }
                func_8000A6F4(obj);
                func_800185A4(obj, 0xE);
                func_800FD85C_name_2A(&D_800FDF60_name_2A[ext->player], 0x200, 1);
                func_800FD85C_name_2A(&D_800FDF60_name_2A[ext->player], 0x4000, 0);
                func_800FD85C_name_2A(&D_800FDF60_name_2A[ext->player], 0x1000, 0);
            }
        }
    } else if (func_800FD850_name_2A(D_800FDF60_name_2A[ext->player], 0x400) != 0 ||
               func_800FD850_name_2A(D_800FDF60_name_2A[ext->player], 0x1000) != 0) {
        /* Result jump in the air: spin. */
        a = func_800FB79C_name_2A(obj);
        ext->unk_34 = a;
        mag = 60.0f;
        ContStkX[work->unk_56] = func_800AEAC0(a) * mag;
        ContStkY[work->unk_56] = func_800AEFD0(a) * -mag;
    }
    if (hit2 & 0x80) {
        if (func_800FD850_name_2A(D_800FDF60_name_2A[ext->player], 0x800) == 0) {
            if (work->unk_38 != 1000.0f) {
                func_800FA088_name_2A(obj);
            } else {
                func_800F9F1C_name_2A(obj);
            }
            func_800FD85C_name_2A(&D_800FDF60_name_2A[ext->player], 0x800, 1);
            func_800FD85C_name_2A(&ext->unk_DC, 1, 1);
        }
    } else {
        func_800FD85C_name_2A(&D_800FDF60_name_2A[ext->player], 0x800, 0);
    }
    if (func_800FD850_name_2A(D_800FDF74_name_2A, 1) == 0) {
        func_800FA1CC_name_2A(obj);
    }
    ext->unk_44 = work->unk_38;
    ext->unk_0C = obj->trans.x;
    ext->unk_10 = obj->trans.y;
    ext->unk_14 = obj->trans.z;
    func_800FB878_name_2A(ext);
    ext->unk_D0 = ext->unk_34;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800F9050_name_2A);
#endif

void func_800F9E20_name_2A(omObjData* obj) {
    func_800F8940_name_2A(obj, 0);
}

void func_800F9E3C_name_2A(omObjData* obj) {
    func_800F8940_name_2A(obj, 1);
}

void func_800F9E58_name_2A(omObjData* obj) {
    func_800F8940_name_2A(obj, 2);
}

void func_800F9E74_name_2A(omObjData* obj) {
    func_800F8940_name_2A(obj, 3);
}

/* The other member of `player`'s team. */
s32 func_800F9E90_name_2A(s32 player) {
    s32 i;

    D_800FDF40_name_2A = -1;
    for (i = 0; i < 4; i++) {
        if (i != player && func_800FD850_name_2A(D_800FDF60_name_2A[i], 1) != 0) {
            D_800FDF40_name_2A = i;
            break;
        }
    }
    return D_800FDF40_name_2A;
}

void func_800F9F1C_name_2A(omObjData* obj) {
    Vec from;
    Vec to;
    Vec out;
    N2APlayerWork* work = obj->unk_50;
    N2APlayerExt* ext = work->unk_E4;
    s32 mate;
    f32 d;

    mate = func_800F9E90_name_2A(ext->player);
    from.x = obj->trans.x;
    from.y = obj->trans.y;
    from.z = obj->trans.z;
    to.x = D_800FE030_name_2A[mate]->trans.x;
    to.y = D_800FE030_name_2A[mate]->trans.y;
    to.z = D_800FE030_name_2A[mate]->trans.z;
    func_800FD880_name_2A(&from, &to, &out);
    if (GwPlayer[ext->player].flags & 1) {
        work->unk_3C = ext->unk_E0;
    }
    D_800FDF54_name_2A = 27.0f;
    d = out.z - work->unk_3C;
    if (d >= -20.0f) {
        if (d < 20.0f) {
        work->unk_3C = out.z;
        ext->unk_E0 = out.z;
        if (out.x <= 647.0f) {
            D_800FDF54_name_2A = out.x / 23.96f;
        }
        }
    }
}

void func_800FA088_name_2A(omObjData* obj) {
    Vec from;
    Vec to;
    Vec out;
    N2APlayerWork* work = obj->unk_50;

    from.x = obj->trans.x;
    from.y = obj->trans.y;
    from.z = obj->trans.z;
    to.x = D_800FE048_name_2A->trans.x + 0.0f;
    to.y = obj->trans.y;
    to.z = D_800FE048_name_2A->trans.z + -560.0f;
    func_800FD880_name_2A(&from, &to, &out);
    work->unk_3C = out.z;
    D_800FDF54_name_2A = 12.0f;
}

void func_800FA124_name_2A(void) {
    s32 unused[4];
    s32 i;

    for (i = 0; i < 4; i++) {
        if (func_800FD850_name_2A(D_800FDF60_name_2A[i], 1) != 0) {
            func_800FD85C_name_2A(&D_800FDF60_name_2A[i], 1, 0);
        } else {
            func_800FD85C_name_2A(&D_800FDF60_name_2A[i], 1, 1);
        }
        func_800FD85C_name_2A(&D_800FDF60_name_2A[i], 0x80, 1);
        unused[i] = 0;
    }
}

/* Keeps a player out of the hoop's post and the four corner posts. */
// float register allocation (dx/dz in f22/f20, 0.0f reloaded)
// decomp-permuter
void func_800FA1CC_name_2A(omObjData *obj)
{
  f32 dx;
  f32 dy;
  f32 dz;
  dx = (D_800FE048_name_2A->trans.x + 0.0f) - obj->trans.x;
  dy = (D_800FE048_name_2A->trans.y + 250.0f) - obj->trans.y;
  dz = (D_800FE048_name_2A->trans.z + (-560.0f)) - obj->trans.z;
  if (func_800B1750(((dx * dx) + (dy * dy)) + (dz * dz)) < 125.0f)
  {
    if (dx >= 0.0f)
    {
      obj->trans.x -= 30.0f;
    }
    else
    {
      obj->trans.x += 30.0f;
    }
    if (dz >= 0.0f)
    {
      obj->trans.z -= 30.0f;
    }
    else
    {
      obj->trans.z += 30.0f;
    }
  }
  dx = (-430.0f) - obj->trans.x;
  dy = 170.0f - obj->trans.y;
  dz = (-560.0f) - obj->trans.z;
  if (func_800B1750(((dx * dx) + (dy * dy)) + (dz * dz)) < 90.0f)
  {
    if (dx >= 0.0f)
    {
      obj->trans.x -= 30.0f;
    }
    else
    {
      obj->trans.x += 30.0f;
    }
    obj->trans.z += 30.0f;
  }
  dx = 430.0f - obj->trans.x;
  dy = 170.0f - obj->trans.y;
  dz = (-560.0f) - obj->trans.z;
  if (func_800B1750(((dx * dx) + (dy * dy)) + (dz * dz)) < 90.0f)
  {
    if (dx >= 0.0f)
    {
      obj->trans.x -= 30.0f;
    }
    else
    {
      obj->trans.x += 30.0f;
    }
    if (dz)
    {
      obj->trans.z += 30.0f;
    }
    else
    {
      obj->trans.z += 30.0f;
    }
  }
  dx = (-610.0f) - obj->trans.x;
  dy = 170.0f - obj->trans.y;
  dz = 50.0f - obj->trans.z;
  if (func_800B1750(((dx * dx) + (dy * dy)) + (dz * dz)) < 90.0f)
  {
    obj->trans.x += 30.0f;
    if (dz >= 0.0f)
    {
      obj->trans.z -= 30.0f;
    }
    else
    {
      obj->trans.z += 30.0f;
    }
  }
  dx = 610.0f - obj->trans.x;
  dy = 170.0f - obj->trans.y;
  dz = 50.0f - obj->trans.z;
  if (func_800B1750(((dx * dx) + (dy * dy)) + (dz * dz)) < 90.0f)
  {
    obj->trans.x -= 30.0f;
    if (dz >= 0.0f)
    {
      obj->trans.z -= 30.0f;
    }
    else
    {
      obj->trans.z += 30.0f;
    }
  }
}

/* CPU control. */
// register allocation (work/mate in s3/s4) and the -1 constant's delay slot (masked 8, raw 20); declaration order has no effect
#ifdef NON_MATCHING
void func_800FA614_name_2A(omObjData* obj) {
    Vec from;
    Vec to;
    Vec out;
    s32 mate;
    N2APlayerWork* work;
    N2APlayerExt* ext;
    N2ABallExt* ball;
    omObjData** holder;

    if (func_800FD850_name_2A(D_800FDF70_name_2A, 4) == 0 && D_800ED430 != 0) {
        work = obj->unk_50;
        ext = work->unk_E4;
        ball = N2A_BALL(D_800FE040_name_2A)->unk_68;
        if (func_800FD850_name_2A(ext->unk_DC, 2) != 0) {
            work->unk_3C = ext->unk_E0;
            func_800FB3FC_name_2A(obj);
            if (--ext->unk_D4 == 0) {
                func_800FD85C_name_2A(&ext->unk_DC, 2, 0);
            }
        } else if (func_800FD850_name_2A(ext->unk_DC, 1) != 0) {
            work->unk_3C = ext->unk_E0;
            func_800FB6F0_name_2A(obj);
        } else if (func_800FD850_name_2A(ext->unk_DC, 4) != 0) {
            work->unk_3C = ext->unk_E0;
            if (--ext->unk_D4 == 0) {
                func_800FB6F0_name_2A(obj);
                func_800FD85C_name_2A(&ext->unk_DC, 4, 0);
            }
        } else if (ball->unk_48 == ext->player) {
            func_800FA8EC_name_2A(obj);
        } else {
            mate = func_800F9E90_name_2A(ext->player);
            if (func_800FD850_name_2A(D_800FDF60_name_2A[ext->player], 1) != 0 && ball->unk_48 == mate) {
                holder = &D_800FE030_name_2A[ball->unk_48];
                if (func_800FD850_name_2A(N2A_PLAYER(*holder)->unk_E4->unk_DC, 1) == 0) {
                    ext->unk_24 = -(*holder)->trans.x;
                    ext->unk_28 = -abs((s32)(*holder)->trans.z);
                    from.x = obj->trans.x;
                    from.y = 0.0f;
                    from.z = obj->trans.z;
                    to.x = ext->unk_24;
                    to.y = 0.0f;
                    to.z = ext->unk_28;
                    func_800FD880_name_2A(&from, &to, &out);
                    goto turn;
                }
            } else if (ball->unk_48 == -1) {
                ext->unk_24 = D_800FE040_name_2A->trans.x;
                ext->unk_28 = D_800FE040_name_2A->trans.z;
                from.x = obj->trans.x;
                from.y = 0.0f;
                from.z = obj->trans.z;
                to.x = ext->unk_24;
                to.y = 0.0f;
                to.z = ext->unk_28;
                func_800FD880_name_2A(&from, &to, &out);
                if (work->unk_38 == 1000.0f) {
                turn:
                    work->unk_3C = out.z;
                    func_800FB3FC_name_2A(obj);
                }
            } else {
                func_800FAEEC_name_2A(obj);
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FA614_name_2A);
#endif

/* CPU holding the ball: shoot when near the hoop, else pass or run. */
// index-before-base order of the teammate pointer (one sll)
#ifdef NON_MATCHING
void func_800FA8EC_name_2A(omObjData* obj) {
    Vec from;
    Vec to;
    Vec out;
    s32 near[4];
    f32 range[4] = { 400.0f, 300.0f, 200.0f, 100.0f };
    s32 odds[4][2] = { { 3, 5 }, { 3, 7 }, { 2, 7 }, { 2, 9 } };
    u16 flags;
    N2APlayerWork* work;
    N2APlayerExt* ext;
    omObjData** p;
    s32 n;
    s32 i;
    s32 r;
    f32 d;

    work = obj->unk_50;
    flags = func_80017A60(obj);
    ext = work->unk_E4;
    from.x = obj->trans.x;
    from.y = 0.0f;
    from.z = obj->trans.z;
    to.x = D_800FE048_name_2A->trans.x + from.y;
    to.y = from.y;
    to.z = D_800FE048_name_2A->trans.z + -560.0f;
    func_800FD880_name_2A(&from, &to, &out);
    n = 0;
    if (out.x < range[ext->unk_D8]) {
        if (work->unk_38 == 1000.0f) {
            work->unk_3C = out.z;
            func_800FB6A8_name_2A(obj);
            func_800FD85C_name_2A(&ext->unk_DC, 4, 1);
            ext->unk_D4 = 3;
            ext->unk_E0 = out.z;
            D_800FE050_name_2A = 0;
        } else if (--ext->unk_D4 == 0) {
            func_800FB6F0_name_2A(obj);
        }
        return;
    }
    for (i = 0; i < 4; i++) {
        if (func_800FD850_name_2A(D_800FDF60_name_2A[i], 1) == 0 && func_800FB280_name_2A(obj, D_800FE030_name_2A[i]) < 200.0f) {
            near[n] = i;
            n++;
        }
    }
    if (n == 2) {
        i = func_800F9E90_name_2A(ext->player);
        to.x = D_800FE030_name_2A[i]->trans.x;
        to.y = 0.0f;
        to.z = D_800FE030_name_2A[i]->trans.z;
        func_800FD880_name_2A(&from, &to, &out);
        if (work->unk_38 == 1000.0f && !(flags & 0x80)) {
            work->unk_3C = out.z;
            func_800FD85C_name_2A(&ext->unk_DC, 1, 1);
            i = func_800F9E90_name_2A(ext->player);
            to.x = D_800FE030_name_2A[i]->trans.x;
            to.y = 0.0f;
            to.z = D_800FE030_name_2A[i]->trans.z;
            func_800FD880_name_2A(&from, &to, &out);
            work->unk_3C = out.z;
            ext->unk_D4 = 0;
            ext->unk_E0 = out.z;
        }
    } else if (n == 1) {
        to.x = D_800FE030_name_2A[near[0]]->trans.x;
        to.y = 0.0f;
        to.z = D_800FE030_name_2A[near[0]]->trans.z;
        func_800FD880_name_2A(&from, &to, &out);
        d = out.z - work->unk_3C;
        if (d >= -45.0f) {
            if (d < 45.0f) {
                func_800FB6A8_name_2A(obj);
                goto turn;
            }
        }
        if (work->unk_38 == 1000.0f) {
            r = rand8() & 0xF;
            if (r < odds[ext->unk_D8][0]) {
                work->unk_3C = N2A_WRAP(out.z + 180.0f);
            } else if (r < odds[ext->unk_D8][1]) {
                p = D_800FE030_name_2A + func_800F9E90_name_2A(ext->player);
                if (func_800FD7D8_name_2A(*p) < func_800FD7D8_name_2A(obj)) {
                    to.x = (*p)->trans.x;
                    to.y = 0.0f;
                    to.z = (*p)->trans.z;
                    func_800FD880_name_2A(&from, &to, &out);
                    func_800FD85C_name_2A(&ext->unk_DC, 1, 1);
                    ext->unk_E0 = out.z;
                }
                return;
            } else {
                to.x = D_800FE048_name_2A->trans.x + 0.0f;
                to.y = 0.0f;
                to.z = D_800FE048_name_2A->trans.z + -560.0f;
                func_800FD880_name_2A(&from, &to, &out);
                work->unk_3C = out.z;
            }
            func_800FB3FC_name_2A(obj);
            func_800FD85C_name_2A(&ext->unk_DC, 2, 1);
            ext->unk_E0 = out.z;
            ext->unk_D4 = 30;
        }
    } else if (work->unk_38 == 1000.0f) {
    turn:
        work->unk_3C = out.z;
        func_800FB3FC_name_2A(obj);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FA8EC_name_2A);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_2A/1E9440", D_800FDE68_name_2A);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_2A/1E9440", D_800FDE78_name_2A);
#endif

/* CPU without the ball while the other team holds it: guard or wander. */
void func_800FAEEC_name_2A(omObjData* obj) {
    Vec from;
    Vec to;
    Vec out;
    N2APlayerWork* work = obj->unk_50;
    N2APlayerExt* ext = work->unk_E4;
    N2ABallExt* ball = N2A_BALL(D_800FE040_name_2A)->unk_68;
    f32 ox;
    f32 oz;
    f32 d;

    from.x = obj->trans.x;
    from.y = 0.0f;
    from.z = obj->trans.z;
    to.x = D_800FE030_name_2A[ball->unk_48]->trans.x;
    to.y = 0.0f;
    to.z = D_800FE030_name_2A[ball->unk_48]->trans.z;
    func_800FD880_name_2A(&from, &to, &out);
    if (out.x < 200.0) {
        work->unk_3C = out.z;
        func_800FB6F0_name_2A(obj);
        return;
    }
    if (--ext->unk_3C == 0) {
        if (ext->unk_54 == 1) {
            ext->unk_3C = 30;
            ext->unk_54 = 0;
        } else {
            ext->unk_3C = 90;
            ext->unk_54 = 1;
        }
        return;
    }
    if (ext->unk_54 == 0) {
        ox = (rand8() % (ext->unk_D8 + 1)) * 30 - (ext->unk_D8 + 1) * 15;
        oz = (rand8() % (ext->unk_D8 + 1)) * 30 - (ext->unk_D8 + 1) * 15;
        ext->unk_24 = ox + D_800FE030_name_2A[ball->unk_48]->trans.x;
        ext->unk_28 = oz + D_800FE030_name_2A[ball->unk_48]->trans.z;
    } else {
        from.x = D_800FE030_name_2A[ball->unk_48]->trans.x;
        from.y = 0.0f;
        from.z = D_800FE030_name_2A[ball->unk_48]->trans.z;
        to.x = D_800FE048_name_2A->trans.x + from.y;
        to.y = from.y;
        to.z = D_800FE048_name_2A->trans.z + -560.0f;
        func_800FD880_name_2A(&from, &to, &out);
        d = out.x * 0.4f;
        ext->unk_24 = D_800FE030_name_2A[ball->unk_48]->trans.x + d * func_800AEAC0(out.z);
        ext->unk_28 = D_800FE030_name_2A[ball->unk_48]->trans.z + d * func_800AEFD0(out.z);
    }
    from.x = obj->trans.x;
    from.y = 0.0f;
    from.z = obj->trans.z;
    to.x = ext->unk_24;
    to.y = 0.0f;
    to.z = ext->unk_28;
    func_800FD880_name_2A(&from, &to, &out);
    if (work->unk_38 == 1000.0f) {
        work->unk_3C = out.z;
        func_800FB3FC_name_2A(obj);
    }
}

f32 func_800FB280_name_2A(omObjData* a, omObjData* b) {
    return D_800FDF44_name_2A = sqrtf((a->trans.x - b->trans.x) * (a->trans.x - b->trans.x) +
                                      (a->trans.z - b->trans.z) * (a->trans.z - b->trans.z));
}

void func_800FB2DC_name_2A(N2APlayerExt* ext, s32 arg1) {
    s32 pad[4];
    s32 unused[32] = { 0, 1, 2, 3, 2, 3, 2, 0, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 0, 2, 0, 1, 2, 3, 0, 1, 0, 2 };

    ext->unk_54 = 0;
    ext->unk_3C = 1;
}

void func_800FB334_name_2A(N2APlayerExt* ext) {
    ext->unk_24 = (rand8() * 4) % 1000 - 500;
    ext->unk_28 = (rand8() * 4) % 1000 - 500;
}

/* Stick toward work->unk_3C; deflection by CPU level (team 0 and team 1 use the levels in
   opposite order). */
// GCC cross-jumps the identical team-1 cases into team 0's; retail keeps both copies
#ifdef NON_MATCHING
void func_800FB3FC_name_2A(omObjData* obj) {
    N2APlayerWork* work = obj->unk_50;
    N2APlayerExt* ext = work->unk_E4;
    f32 angle = work->unk_3C;
    s32 mag;
    f32 f;

    if (func_800FD850_name_2A(D_800FDF60_name_2A[ext->player], 1) != 0) {
        switch (ext->unk_D8) {
            case 0:
                mag = (u8)(rand8() % 14) * 5;
                break;
            case 1:
                mag = (u8)(rand8() % 10) * 5 + 20;
                break;
            case 2:
                mag = (u8)(rand8() % 6) * 5 + 40;
                break;
            default:
                mag = (rand8() & 1) * 5 + 60;
                break;
        }
    } else {
        switch (ext->unk_D8) {
            case 0:
                mag = 60 + (rand8() & 1) * 5;
                break;
            case 1:
                mag = 40 + (u8)(rand8() % 6) * 5;
                break;
            case 2:
                mag = 20 + (u8)(rand8() % 10) * 5;
                break;
            default:
                mag = (u8)(rand8() % 14) * 5;
                break;
        }
    }
    f = mag;
    ContStkX[work->unk_56] = f * func_800AEAC0(angle);
    ContStkY[work->unk_56] = -f * func_800AEFD0(angle);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FB3FC_name_2A);
#endif

void func_800FB6A8_name_2A(omObjData* obj) {
    N2APlayerWork* work = obj->unk_50;

    ContBtnTrg[work->unk_56] |= 0x8000;
    ContBtn[work->unk_56] |= 0x8000;
}

void func_800FB6F0_name_2A(omObjData* obj) {
    ContBtnTrg[N2A_PLAYER(obj)->unk_56] |= 0x4000;
}

f32 func_800FB718_name_2A(omObjData* obj) {
    Vec from;
    Vec to;
    Vec out;

    from.x = obj->trans.x;
    from.y = obj->trans.y;
    from.z = obj->trans.z;
    to.x = D_800FE048_name_2A->trans.x + 0.0f;
    to.y = obj->trans.y;
    to.z = D_800FE048_name_2A->trans.z + -560.0f;
    func_800FD880_name_2A(&from, &to, &out);
    return D_800FDF48_name_2A = out.x;
}

f32 func_800FB79C_name_2A(omObjData* obj) {
    N2APlayerWork* work = obj->unk_50;
    N2APlayerExt* ext = work->unk_E4;

    if (--ext->unk_3C == 0 && ext->unk_58[29] != 1000.0f) {
        ext->unk_D0 = N2A_WRAP(ext->unk_D0 + 30.0f);
        ext->unk_3C = 30;
        work->unk_38 = 300.0f;
    }
    return D_800FDF4C_name_2A = ext->unk_D0;
}

void func_800FB878_name_2A(N2APlayerExt* ext) {
    s32 i;

    /* Retail shifts 30 entries up by one: [29] lands in [30], which is unk_D0. */
    for (i = 0; i < 30; i++) {
        ext->unk_58[30 - i] = ext->unk_58[29 - i];
    }
    ext->unk_58[0] = ext->unk_38;
}

/* After a goal: send each team-0 player to the free end of the court (ext->unk_48/4C). */
// register allocation; retail tests the end counters through hoisted pointers
#ifdef NON_MATCHING
void func_800FB8BC_name_2A(void) {
    f32 homeX[2];
    f32 homeZ[2];
    Vec from;
    Vec to;
    Vec out;
    omObjData* obj;
    N2APlayerExt* ext;
    s32* timer;
    f32 d;
    s32 i;

    homeX[0] = -78.0f;
    homeX[1] = 78.0f;
    homeZ[1] = homeZ[0] = -300.0f;
    for (i = 0; i < 4; i++) {
        ext = N2A_PLAYER(D_800FE030_name_2A[i])->unk_E4;
        if (func_800FD850_name_2A(D_800FDF60_name_2A[ext->player], 1) != 0) {
            from.x = D_800FE030_name_2A[i]->trans.x;
            from.y = 0.0f;
            from.z = D_800FE030_name_2A[i]->trans.z;
            to.x = homeX[0];
            to.y = 0.0f;
            to.z = homeZ[0];
            func_800FD880_name_2A(&from, &to, &out);
            d = out.x;
            to.x = homeX[1];
            to.y = 0.0f;
            to.z = homeZ[1];
            func_800FD880_name_2A(&from, &to, &out);
            if (d < out.x) {
                if (D_800FDFA4_name_2A[0] == 0) {
                    goto home0;
                }
                goto home1;
            }
            if (D_800FDFA4_name_2A[1] != 0) {
            home0:
                ext->unk_48 = homeX[0];
                ext->unk_4C = homeZ[0];
                D_800FDFA4_name_2A[0]++;
            } else {
            home1:
                ext->unk_48 = homeX[1];
                ext->unk_4C = homeZ[1];
                D_800FDFA4_name_2A[1]++;
            }
            if (D_800FDFA4_name_2A[0] == 2) {
                ext->unk_48 = homeX[1];
                ext->unk_4C = homeZ[1];
            }
            if (D_800FDFA4_name_2A[1] == 2) {
                ext->unk_48 = homeX[0];
                ext->unk_4C = homeZ[0];
            }
        } else {
            ext->unk_48 = 0.0f;
            ext->unk_4C = -300.0f;
        }
        func_800FD85C_name_2A(&D_800FDF60_name_2A[i], 0x20000, 1);
    }
    obj = omAddObj(0x10, 0, 0, -1, &func_800FBFC8_name_2A);
    timer = func_80023684(sizeof(s32), 0x7918);
    obj->unk_50 = timer;
    *timer = 120;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FB8BC_name_2A);
#endif

/* After a goal: walk to the home spot (team 0) or away from it (team 1). */
void func_800FBB50_name_2A(omObjData* obj) {
    Vec from;
    Vec to;
    Vec out;
    N2APlayerWork* work = obj->unk_50;
    N2APlayerExt* ext = work->unk_E4;
    omObjData* other;
    f32 mag;
    f32 best;
    f32 ox;
    f32 tx;
    f32 oz;
    f32 tz;
    f32 d;
    s32 nearest;
    s32 i;

    nearest = 0;
    if (func_800FD850_name_2A(D_800FDF60_name_2A[ext->player], 1) != 0) {
        from.x = obj->trans.x;
        from.y = obj->trans.y;
        from.z = obj->trans.z;
        to.x = ext->unk_48;
        to.y = 0.0f;
        to.z = ext->unk_4C;
        func_800FD880_name_2A(&from, &to, &out);
        mag = (out.x >= 180.0f) ? 60.0f : 36.0f;
        ContStkX[work->unk_56] = mag * func_800AEAC0(out.z);
        ContStkY[work->unk_56] = -mag * func_800AEFD0(out.z);
        best = 1000.0f;
        for (i = 0; i < 4; i++) {
            other = D_800FE030_name_2A[i];
            if (obj != other) {
                ox = obj->trans.x;
                tx = other->trans.x;
                oz = obj->trans.z;
                tz = other->trans.z;
                d = sqrtf((tx - ox) * (tx - ox) + (tz - oz) * (tz - oz));
                if (d < best) {
                    best = d;
                    nearest = i;
                }
            }
        }
        if (best < 135.0f && N2A_PLAYER(D_800FE030_name_2A[nearest])->unk_38 == 1000.0f) {
            ContBtnTrg[work->unk_56] |= 0x8000;
            ContBtn[work->unk_56] |= 0x8000;
        }
        if (out.x <= 30.0f) {
            func_800FD85C_name_2A(&D_800FDF60_name_2A[ext->player], 0x20000, 0);
            func_800FD85C_name_2A(&D_800FDF60_name_2A[ext->player], 0x40000, 1);
            ContStkX[work->unk_56] = 0;
            ContStkY[work->unk_56] = 0;
            func_80009E20(obj);
            work->unk_50 &= ~0x200;
            work->unk_3C = 0.0f;
        }
    } else {
        from.x = obj->trans.x;
        from.y = obj->trans.y;
        from.z = obj->trans.z;
        to.x = ext->unk_48;
        to.y = 0.0f;
        to.z = ext->unk_4C;
        func_800FD880_name_2A(&from, &to, &out);
        out.z = N2A_WRAP(out.z + 180.0f);
        mag = 60.0f;
        ContStkX[work->unk_56] = func_800AEAC0(out.z) * mag;
        ContStkY[work->unk_56] = func_800AEFD0(out.z) * -mag;
        if (out.x >= 500.0f) {
            func_800FD85C_name_2A(&D_800FDF60_name_2A[ext->player], 0x20000, 0);
            func_800FD85C_name_2A(&D_800FDF60_name_2A[ext->player], 0x40000, 1);
            ContStkX[work->unk_56] = 0;
            ContStkY[work->unk_56] = 0;
            func_80009E20(obj);
            work->unk_50 &= ~0x200;
        }
    }
}

void func_800FBFC8_name_2A(omObjData* obj) {
    s32* timer = obj->unk_50;
    s32 n;
    s32 i;

    n = 0;
    for (i = 0; i < 4; i++) {
        if (func_800FD850_name_2A(D_800FDF60_name_2A[i], 1) != 0) {
            n += func_800FD850_name_2A(D_800FDF60_name_2A[i], 0x20000);
        }
    }
    (*timer)--;
    if (n == 0 || *timer == 0) {
        D_800FE024_name_2A = 9;
        D_800ED430 = 2;
        omDelObj(obj);
    }
}

void func_800FC098_name_2A(void) {
    omObjData* obj;
    N2ABallWork* work;
    N2ABallExt* ext;
    s32 i;

    obj = omAddObj(5, 2, 2, -1, &func_800FC364_name_2A);
    D_800FE040_name_2A = obj;
    obj->unk_50 = func_80023684(sizeof(N2ABallWork), 0x7918);
    for (i = 0; i < 4; i++) {
        if (func_800FD850_name_2A(D_800FDF60_name_2A[i], 1) != 0) {
            break;
        }
    }
    obj->trans.x = -200.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 500.0f;
    obj->rot.x = 0.0f;
    obj->rot.y = 0.0f;
    obj->rot.z = 0.0f;
    obj->scale.x = 1.0f;
    obj->scale.y = 1.0f;
    obj->scale.z = 1.0f;
    work = obj->unk_50;
    ext = work->unk_68 = func_80023684(sizeof(N2ABallExt), 0x7918);
    obj->model[0] = LoadFormFile(0x3E0009, 0x699);
    work->unk_50 = 0x40;
    work->unk_48 = 40.0f;
    work->unk_34 = 40.0f;
    work->unk_38 = 1000.0f;
    work->unk_3C = 180.0f;
    work->unk_58 = 0.8f;
    work->unk_4C = 0.5f;
    work->unk_40 = 0.0f;
    ext->unk_00 = 0.0f;
    ext->unk_04 = 0.0f;
    ext->unk_08 = 0.0f;
    ext->unk_0C = 0.0f;
    ext->unk_10 = 0.0f;
    ext->unk_14 = 0.0f;
    ext->unk_18 = 1.0f;
    ext->unk_1C = 1.0f;
    ext->unk_20 = 1.0f;
    ext->unk_44 = 2.0f;
    ext->unk_48 = -1;
    ext->unk_50 = 4.9f;
    ext->unk_40 = 0.0f;
    ext->unk_58 = 0;
    ext->unk_4C = -1;
    ext->unk_5C = 0.0f;
    ext->unk_60 = 0.0f;
    ext->unk_64 = 0.0f;
    D_800FDF98_name_2A = -1;
    omSetTra(obj, obj->trans.x, obj->trans.y, obj->trans.z);
    obj->model[1] = LoadFormFile(6, 0x699);
    func_800370D4(obj->model[1]);
    func_80025830(obj->model[1], 1.0f, 1.0f, 1.0f);
    D_800FDF70_name_2A = 0;
    func_800090C4(obj, 0, 2);
    func_800090C4(obj, 1, 2);
    func_80008FAC(obj, 0.5f);
    func_8001775C(obj, 0, 0x3E000A);
    func_8001775C(obj, 1, 0x3E000B);
    func_800FC70C_name_2A(obj);
    ext->unk_30 = -200.0f;
    ext->unk_34 = 500.0f;
    func_80021E58();
}

void func_800FC364_name_2A(omObjData* obj) {
    Vec4f sphere;
    N2ABallWork* work;
    N2ABallExt* ext;
    f32 x;
    f32 y;
    f32 z;
    s32 hit;
    s32 i;

    if (func_800FD850_name_2A(D_800FDF70_name_2A, 4) != 0) {
        func_800258EC(obj->model[0], 4, 4);
        func_800258EC(obj->model[1], 4, 4);
        omDelObj(obj);
        return;
    }
    work = obj->unk_50;
    ext = work->unk_68;
    omSetTra(obj, obj->trans.x, obj->trans.y, obj->trans.z);
    omSetRot(obj, obj->rot.x, obj->rot.y, obj->rot.z);
    x = obj->trans.x;
    y = obj->trans.y;
    z = obj->trans.z;
    D_800ED6B8 = 0.0f;
    D_800F5254 = 0.0f;
    sphere.x = x;
    sphere.y = y;
    sphere.z = z;
    sphere.w = work->unk_48;
    func_80004D1C(obj, &sphere, 0.0f);
    hit = 0;
    if (D_800F5254 >= 0.00001f || D_800F5254 <= -0.00001f) {
        work->unk_3C = N2A_WRAP(-(work->unk_3C - 180.0f));
        hit = 1;
    }
    if (D_800ED6B8 >= 0.00001f || D_800ED6B8 <= -0.00001f) {
        work->unk_3C = N2A_WRAP(-work->unk_3C);
        hit = 1;
    }
    if (hit) {
        if (D_800FDF54_name_2A * 0.5f <= work->unk_40 && ext->unk_48 == -1) {
            work->unk_40 *= 0.5f;
            obj->trans.x = ext->unk_5C;
            obj->trans.y = ext->unk_60;
            obj->trans.z = ext->unk_64;
            D_800FE028_name_2A = PlaySound(0x30C);
        }
    }
    func_80025798(obj->model[1], obj->trans.x, 4.0f, obj->trans.z);
    ext->unk_5C = obj->trans.x;
    ext->unk_60 = obj->trans.y;
    ext->unk_64 = obj->trans.z;
    if (D_800FE024_name_2A != 0 && D_800FE024_name_2A != 1 && D_800FE024_name_2A != -1) {
        if (func_800FD850_name_2A(D_800FDF70_name_2A, 1) != 0) {
            func_800FC7A4_name_2A(obj);
        } else {
            func_800FCB5C_name_2A(obj);
        }
    }
    ext->unk_4C = ext->unk_48;
    for (i = 0; i < 4; i++) {
        if (N2A_PLAYER(D_800FE030_name_2A[i])->unk_B1 != -1) {
            N2A_PLAYER(D_800FE030_name_2A[i])->unk_B1 = -1;
        }
    }
}

/* Puts the ball in demo mode (rolling to random spots) until the game starts. */
void func_800FC70C_name_2A(omObjData* obj) {
    N2ABallExt* ext = N2A_BALL(obj)->unk_68;

    obj->rot.x = 0.0f;
    obj->rot.z = 0.0f;
    func_800FC8C8_name_2A(ext);
    func_800FD85C_name_2A(&D_800FDF70_name_2A, 1, 1);
    func_800FD85C_name_2A(&D_800FDF70_name_2A, 2, 0);
    func_800258EC(obj->model[0], 0x4000, 0);
    func_80025BB8(obj->model[0], obj->motion[1]);
    func_80025EB4(obj->model[0], 2, 2);
}

void func_800FC7A4_name_2A(omObjData* obj) {
    s16 pos[2];
    s16 target[2];
    Vec out;
    N2ABallWork* work = obj->unk_50;
    N2ABallExt* ext = work->unk_68;

    func_800FC990_name_2A(obj, &out);
    obj->rot.y = work->unk_3C = out.z;
    obj->trans.x += func_800AEAC0(work->unk_3C) * ext->unk_44;
    obj->trans.z += func_800AEFD0(work->unk_3C) * ext->unk_44;
    pos[0] = (s32)obj->trans.x / 32;
    pos[1] = (s32)obj->trans.z / 32;
    target[0] = (s32)ext->unk_30 / 32;
    target[1] = (s32)ext->unk_34 / 32;
    if (out.x < ext->unk_44) {
        func_800FC8C8_name_2A(ext);
    }
}

void func_800FC8C8_name_2A(N2ABallExt* ext) {
    ext->unk_30 = (rand8() * 4) % 1000 - 500;
    ext->unk_34 = (rand8() * 4) % 1000 - 500;
}

void func_800FC990_name_2A(omObjData* obj, Vec* out) {
    Vec from;
    Vec to;
    N2ABallExt* ext = N2A_BALL(obj)->unk_68;

    from.x = obj->trans.x;
    from.y = obj->trans.y;
    from.z = obj->trans.z;
    to.x = ext->unk_30;
    to.y = obj->trans.y;
    to.z = ext->unk_34;
    func_800FD880_name_2A(&from, &to, out);
}

/* `player` catches the ball. */
void func_800FC9EC_name_2A(omObjData* obj, s32 player) {
    N2ABallWork* work = obj->unk_50;
    N2ABallExt* ext = work->unk_68;
    N2APlayerWork* pw = D_800FE030_name_2A[player]->unk_50;
    s32* flags;

    func_800FD85C_name_2A(&D_800FDF70_name_2A, 8, 0);
    func_800FD85C_name_2A(&D_800FDF70_name_2A, 1, 0);
    flags = &D_800FDF60_name_2A[player];
    func_800FD85C_name_2A(flags, 0x4000, 1);
    func_800FD85C_name_2A(flags, 0x8000, 1);
    func_8000A634(D_800FE030_name_2A[player], obj);
    pw->unk_50 &= ~0x100;
    pw->unk_A4 = 0.8f;
    ext->unk_48 = player;
    D_800FDF98_name_2A = player;
    func_80025BB8(obj->model[0], obj->motion[0]);
    func_80025EB4(obj->model[0], 2, 0);
    obj->trans.y += work->unk_48;
    func_800258EC(D_800FE02C_name_2A->model[0], 4, 0);
    func_800258EC(D_800FE02C_name_2A->model[1], 4, 0);
}

void func_800FCB5C_name_2A(omObjData* obj) {
    Vec from;
    Vec to;
    Vec out;
    N2ABallWork* work;
    N2ABallExt* ext;
    N2APlayerWork* holder;
    s32* flags;
    f32 frames;
    f32 y;
    f32 vy;
    f32 gravity;

    if (func_800FD850_name_2A(D_800FDF70_name_2A, 4) != 0) {
        return;
    }
    work = obj->unk_50;
    ext = work->unk_68;
    if (!(work->unk_50 & 0x20)) {
        if (ext->unk_48 == -1) {
            obj->trans.x += func_800AEAC0(work->unk_3C) * work->unk_40;
            obj->trans.y += ext->unk_40;
            if (obj->trans.y < work->unk_48) {
                obj->trans.y = work->unk_48;
                func_800FD85C_name_2A(&D_800FDF70_name_2A, 8, 0);
                if (ext->unk_54 > 10.0f) {
                    D_800FE028_name_2A = PlaySound(0x30C);
                }
                ext->unk_54 *= 0.6f;
                if (ext->unk_54 < 0.1f) {
                    ext->unk_54 = 0.0f;
                }
                ext->unk_40 = ext->unk_54;
            }
            ext->unk_40 -= ext->unk_50;
            obj->trans.z += func_800AEFD0(work->unk_3C) * work->unk_40;
            if (obj->trans.y == work->unk_48) {
                work->unk_40 -= work->unk_44;
                if (work->unk_40 < 0.0f) {
                    work->unk_40 = 0.0f;
                }
                if (work->unk_40 == 0.0f) {
                    if (func_800FD850_name_2A(D_800FDF70_name_2A, 2) == 0) {
                        func_800FD85C_name_2A(&D_800FDF70_name_2A, 2, 1);
                        ext->unk_58 = 30;
                    } else if (--ext->unk_58 == 0) {
                        func_800FC70C_name_2A(obj);
                    }
                }
                obj->rot.x += func_800AEFD0(work->unk_3C) * work->unk_40;
                obj->rot.x = N2A_WRAP(obj->rot.x);
                obj->rot.z -= func_800AEAC0(work->unk_3C) * work->unk_40;
                obj->rot.z = N2A_WRAP(obj->rot.z);
            }
        } else {
            holder = D_800FE030_name_2A[ext->unk_48]->unk_50;
            func_800FD85C_name_2A(&D_800FDF60_name_2A[ext->unk_48], 0x4000, 0);
            func_800FD85C_name_2A(&D_800FDF60_name_2A[ext->unk_48], 0x8000, 1);
            ext->unk_48 = -1;
            ext->unk_54 = 50.0f;
            ext->unk_40 = 50.0f;
            if (holder->unk_B1 != -1) {
                obj->trans.x = D_800FE030_name_2A[holder->unk_B1]->trans.x;
                obj->trans.y = D_800FE030_name_2A[holder->unk_B1]->trans.y;
                obj->trans.z = D_800FE030_name_2A[holder->unk_B1]->trans.z;
                func_800FD85C_name_2A(&D_800FDF70_name_2A, 8, 0);
                work->unk_40 = 0.0f;
                work->unk_38 = 0.0f;
                holder->unk_B1 = -1;
            } else {
                work->unk_40 = D_800FDF54_name_2A;
                if (func_800FD850_name_2A(D_800FDF60_name_2A[D_800FDF98_name_2A], 0x40) != 0) {
                    /* A shot: time the arc to come down at the hoop. */
                    ext->unk_54 = 10.0f;
                    ext->unk_40 = 10.0f;
                    frames = 0.0f;
                    y = obj->trans.y;
                    vy = 10.0f;
                    gravity = ext->unk_50;
                    while ((D_800FE048_name_2A->trans.y + 350.0f <= y) | (vy > 0.0f)) {
                        y += vy;
                        vy -= gravity;
                        frames += 1.0f;
                    }
                    from.x = obj->trans.x;
                    from.y = obj->trans.y;
                    from.z = obj->trans.z;
                    to.x = D_800FE048_name_2A->trans.x + 0.0f;
                    to.y = from.y;
                    to.z = D_800FE048_name_2A->trans.z + -560.0f;
                    func_800FD880_name_2A(&from, &to, &out);
                    work->unk_40 = out.x / frames;
                }
                func_800258EC(D_800FE02C_name_2A->model[0], 4, 4);
                func_800258EC(D_800FE02C_name_2A->model[1], 4, 4);
            }
            obj->rot.x = 0.0f;
            obj->rot.y = 0.0f;
            obj->rot.z = 0.0f;
            flags = &holder->unk_E4->unk_DC;
            func_800FD85C_name_2A(flags, 1, 0);
            func_800FD85C_name_2A(flags, 2, 0);
            func_800FD85C_name_2A(flags, 4, 0);
        }
    } else {
        if (ext->unk_48 != -1) {
            obj->trans.x = D_800FE030_name_2A[ext->unk_48]->trans.x;
            obj->trans.y = D_800FE030_name_2A[ext->unk_48]->trans.y;
            obj->trans.z = D_800FE030_name_2A[ext->unk_48]->trans.z;
        }
        if (ext->unk_4C != -1 && ext->unk_4C != ext->unk_48) {
            func_800FD85C_name_2A(&D_800FDF60_name_2A[ext->unk_4C], 0x4000, 0);
            func_800FD85C_name_2A(&D_800FDF60_name_2A[ext->unk_4C], 0x8000, 1);
        }
    }
}

void func_800FD1B4_name_2A(omObjData* obj) {
    omObjData* timerObj;
    s32* timer;

    timerObj = omAddObj(5, 0, 0, -1, &func_800FD20C_name_2A);
    timer = func_80023684(sizeof(N2ABallExt), 0x7918);
    timerObj->unk_50 = timer;
    *timer = 1;
}

void func_800FD20C_name_2A(omObjData* obj) {
    s32* timer = obj->unk_50;

    (*timer)--;
    if (*timer == 0) {
        func_800FD254_name_2A(D_800FE040_name_2A);
        omDelObj(obj);
    }
}

/* Goal or time up: a camera on the ball (or the court), then the result. */
void func_800FD254_name_2A(omObjData* obj) {
    N2ABallExt* ext = N2A_BALL(obj)->unk_68;
    f32 dz;
    f32 dx;

    func_800258EC(D_800FE02C_name_2A->model[0], 4, 4);
    func_800258EC(D_800FE02C_name_2A->model[1], 4, 4);
    dz = 0.0f;
    dx = dz;
    if (ext->unk_48 != -1) {
        dx = -50.0f;
    } else {
        dz = 100.0f;
    }
    if (D_800FE024_name_2A == 3) {
        func_80021EC0(2, dx + D_800FE040_name_2A->trans.x, D_800FE040_name_2A->trans.y + 50.0f,
                      dz + D_800FE040_name_2A->trans.z);
    } else {
        func_80021EC0(2, 0.0f, 300.0f, -500.0f);
    }
    D_800FE024_name_2A = -1;
    func_800FD85C_name_2A(&D_800FDF70_name_2A, 4, 1);
    func_800FD85C_name_2A(&D_800FDF70_name_2A, 8, 0);
    if (func_800FD850_name_2A(D_800FDF74_name_2A, 1) != 0) {
        D_800FDFC4_name_2A = PlaySound(0x308);
    } else {
        D_800FDFC4_name_2A = PlaySound(0x30E);
    }
    func_80009730();
    if (ext->unk_48 != -1) {
        func_8000A534(D_800FE030_name_2A[ext->unk_48], 0.0f);
    }
    if (D_800FDF58_name_2A == 0) {
        D_800FE024_name_2A = 4;
        {
            func_800FD85C_name_2A(&D_800FDF60_name_2A[ext->unk_48], 0x4000, 0);
            func_800FD85C_name_2A(&D_800FDF60_name_2A[ext->unk_48], 0x8000, 1);
        }
    }
    func_800601D4(40);
}

void func_800FD428_name_2A(void) {
    omObjData* light;

    func_8006B870();
    light = (omObjData*)func_8006B8A4(0xC, 0x6D9, 0x699, 0x289, 1);
    func_8006B9B0(light, 0.0f, 50.0f, -805.0f);
    func_8006B9C0(light, 0.0f, 0.0f, 0.0f);
    func_8006B9D0(light, 1.0f, 1.0f, 1.0f);
    func_8006BAD0(light, 0.0f);
    func_8006BB08(light, 0);
    D_800FE044_name_2A = light;
    light = (omObjData*)func_8006B8A4(0xC, 0x6D9, 0x699, 0x289, 1);
    func_8006B9B0(light, 0.0f, 50.0f, -805.0f);
    func_8006B9C0(light, 0.0f, 0.0f, 0.0f);
    func_8006B9D0(light, 1.0f, 1.0f, 1.0f);
    func_8006BAD0(light, 0.0f);
    func_8006BB08(light, 4);
    D_800FDFC0_name_2A = light;
}

void func_800FD54C_name_2A(void) {
    s32 team[2];
    s32 n;
    s32 i;

    n = 0;
    for (i = 0; i < 4; i++) {
        if (func_800FD850_name_2A(D_800FDF60_name_2A[i], 1) != 0) {
            team[n] = i;
            n++;
        }
    }
    func_8006BADC(D_800FE044_name_2A, D_800FE030_name_2A[team[0]]->trans.x, 0.0f, D_800FE030_name_2A[team[0]]->trans.z);
    func_8006BADC(D_800FDFC0_name_2A, D_800FE030_name_2A[team[1]]->trans.x, 0.0f, D_800FE030_name_2A[team[1]]->trans.z);
    func_8006BAF0(D_800FE044_name_2A, 1);
    func_8006BAF0(D_800FDFC0_name_2A, 1);
    omAddObj(0xC, 0, 0, -1, &func_800FD670_name_2A);
    D_800FE024_name_2A = -1;
}

void func_800FD670_name_2A(omObjData* obj) {
    s32 team[2];
    N2APlayerWork* work;
    N2APlayerExt* ext;
    s32 n;
    s32 i;

    n = 0;
    for (i = 0; i < 4; i++) {
        if (func_800FD850_name_2A(D_800FDF60_name_2A[i], 1) != 0) {
            team[n] = i;
            n++;
        }
    }
    func_8006BADC(D_800FE044_name_2A, D_800FE030_name_2A[team[0]]->trans.x, D_800FE030_name_2A[team[0]]->trans.y, D_800FE030_name_2A[team[0]]->trans.z);
    func_8006BADC(D_800FDFC0_name_2A, D_800FE030_name_2A[team[1]]->trans.x, D_800FE030_name_2A[team[1]]->trans.y, D_800FE030_name_2A[team[1]]->trans.z);
    if (func_8006BAFC(D_800FE044_name_2A) == 0 && func_8006BAFC(D_800FDFC0_name_2A) == 0) {
        for (i = 0; i < 4; i++) {
            work = D_800FE030_name_2A[i]->unk_50;
            ext = work->unk_E4;
            work->unk_50 = (work->unk_50 | 0x200) & 0xFFF8;
            ext->unk_3C = 15;
            ext->unk_D0 = work->unk_3C;
        }
        func_800F7760_name_2A(D_800FDF98_name_2A);
        omDelObj(obj);
    }
}

f32 func_800FD7D8_name_2A(omObjData* obj) {
    f32 hx = D_800FE048_name_2A->trans.x + 0.0f;
    f32 hy = D_800FE048_name_2A->trans.y + 350.0f;
    f32 hz = D_800FE048_name_2A->trans.z + -560.0f;
    f32 ox = obj->trans.x;
    f32 oy = obj->trans.y;
    f32 oz = obj->trans.z;

    return D_800FDF50_name_2A = (hx - ox) * (hx - ox) + (hy - oy) * (hy - oy) + (hz - oz) * (hz - oz);
}

s32 func_800FD850_name_2A(s32 flags, s32 mask) {
    return (flags & mask) != 0;
}

void func_800FD85C_name_2A(s32* flags, s32 mask, s32 set) {
    if (set != 0) {
        *flags |= mask;
    } else {
        *flags &= ~mask;
    }
}

/* out = (distance, -, yaw) from `from` to `to`. */
// retail keeps the dead pitch range compares (as ovl_1B/ovl_0D's twin; 17 instructions) and schedules
// the 180.0f load after the compare (masked 24, raw 24); y/eps locals as MP2 RollCall's twin
#ifdef NON_MATCHING
void func_800FD880_name_2A(Vec* from, Vec* to, Vec* out) {
    Vec delta;
    Vec fromCopy;
    Vec toCopy;
    f32 horizontal;
    f32 pitch;
    f32 yaw;
    f32 y;
    f32 eps;
    s32 nearPositive;
    s32 nearNegative;

    fromCopy.x = from->x;
    fromCopy.y = from->y;
    fromCopy.z = from->z;
    toCopy.x = to->x;
    toCopy.y = to->y;
    toCopy.z = to->z;
    delta.x = toCopy.x - fromCopy.x;
    delta.y = toCopy.y - fromCopy.y;
    delta.z = toCopy.z - fromCopy.z;
    horizontal = sqrtf((delta.x * delta.x) + (delta.z * delta.z));
    nearPositive = horizontal <= 0.002f;
    nearNegative = horizontal >= -0.002f;
    if (nearPositive & nearNegative) {
        horizontal = 0.0f;
        y = delta.y;
        eps = 0.0001f;
        yaw = horizontal;
        pitch = 180.0f;
        if (!(y > eps) && y < eps) {
            pitch = horizontal;
        }
    } else {
        if (delta.x != 0.0f && delta.z != 0.0f) {
            yaw = func_800FDBF4_name_2A(delta.x / delta.z) * 57.29577951308232;
        } else {
            yaw = 0.0f;
        }
        if (delta.z < 0.0f) {
            yaw -= 180.0f;
        }
        if (horizontal != 0.0f && delta.y != 0.0f) {
            pitch = func_800FDBF4_name_2A(delta.y / horizontal) * 57.29577951308232;
        } else {
            pitch = 0.0f;
        }
        yaw = N2A_WRAP(yaw);
        pitch = N2A_WRAP(pitch + 90.0f);
    }
    nearPositive = pitch <= 0.002f;
    nearNegative = pitch >= -0.002f;
    horizontal = sqrtf((delta.y * delta.y) + (horizontal * horizontal));
    out->z = yaw;
    out->x = horizontal;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A/1E9440", func_800FD880_name_2A);
#endif

/* atan(x) by a continued fraction. */
f32 func_800FDBF4_name_2A(f32 x) {
    f32 a;
    f32 b;
    f32 sum;
    s32 sign;
    s32 i;

    sign = 1;
    if (x > 1.0f) {
        x = 1.0f / x;
    } else {
        sign = -1;
        if (x < -1.0f) {
            x = 1.0f / x;
        } else {
            sign = 0;
        }
    }
    sum = 0.0f;
    i = 6;
    do {
        a = (f32)(i * i) * x * x;
        b = (f32)(i * 2 + 1) + sum;
        i--;
        sum = a / b;
    } while (i > 0);
    if (sum != -1.0f) {
        if (sign > 0) {
            return 1.5707963267948966 - (x / (sum + 1.0f));
        }
        if (sign < 0) {
            return -1.5707963267948966 - (x / (sum + 1.0f));
        }
        return x / (sum + 1.0f);
    }
    return 0.0f;
}

void func_800FDD44_name_2A(void) {
}
