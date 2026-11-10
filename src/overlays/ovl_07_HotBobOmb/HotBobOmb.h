#ifndef HOTBOBOMB_H
#define HOTBOBOMB_H

/* ovl_07 HotBobOmb: declarations for its units (10CD10.c, 10CF70.c, 10F6D0.c).
   Types come from the asm's accesses; N64 offsets are in the comments. */

#include "common.h"

/* D_800F9D44[4] and its six per-character templates (D_800F9DD4..D_800FA0A4): one seat per
   player. Splat labels inside entry 0: D_800F9D48 (pos.x), D_800F9D50 (pos.z), D_800F9D54 (rot),
   D_800F9D58 (scale), D_800F9D5C/60/64 (bomb.x/y/z). Pointer-free. */
typedef struct HbSeat {
    /* 0x00 */ f32 idx; /* player index, as a float */
    /* 0x04 */ Vec pos;
    /* 0x10 */ f32 rot;
    /* 0x14 */ f32 scale;
    /* 0x18 */ Vec bomb; /* where the bomb sits above this seat */
} HbSeat; /* size = 0x24 */

/* D_800FA8F0[4]: per player (labels D_800FA8F4 = [0].t, D_800FA8F8 = [0].done). */
typedef struct HbPlayer {
    /* 0x00 */ omObjData* obj;
    /* 0x04 */ f32 t;    /* motion timer */
    /* 0x08 */ s32 done; /* explosion reaction played */
} HbPlayer; /* N64 size = 0xC */

/* D_800FA1C8[13]: camera keyframes (D_800FA1D0 = [0].center.y, D_800FA1E4 = [0].dur). */
typedef struct HbCamKey {
    /* 0x00 */ f32 zoom;
    /* 0x04 */ Vec center;
    /* 0x10 */ Vec rot;
    /* 0x1C */ f32 dur;
    /* 0x20 */ u8 event; /* 1 message, 3/4 sounds */
} HbCamKey; /* size = 0x24 */

/* 10CD10 */
void func_800F65E0_HotBobOmb(void);
void func_800F66F8_HotBobOmb(omObjData* obj);
void func_800F6730_HotBobOmb(omObjData* obj);
void func_800F67C8_HotBobOmb(omObjData* obj);
void func_800F6800_HotBobOmb(s32 seed);
s32 func_800F680C_HotBobOmb(void);

/* 10CF70 */
void func_800F6840_HotBobOmb(omObjData* obj);
void func_800F6848_HotBobOmb(void);
void func_800F693C_HotBobOmb(void);
void func_800F6A10_HotBobOmb(omObjData* obj);
void func_800F6AF0_HotBobOmb(omObjData* obj);
void func_800F6B64_HotBobOmb(omObjData* obj);
void func_800F6BBC_HotBobOmb(omObjData* obj);
void func_800F6C20_HotBobOmb(omObjData* obj);
void func_800F6C78_HotBobOmb(omObjData* obj);
void func_800F6CEC_HotBobOmb(omObjData* obj);
void func_800F6D60_HotBobOmb(omObjData* obj);
void func_800F6D7C_HotBobOmb(omObjData* obj);
void func_800F6D98_HotBobOmb(omObjData* obj);
void func_800F6DB4_HotBobOmb(omObjData* obj);
void func_800F6DD0_HotBobOmb(omObjData* obj, s32 player);
void func_800F724C_HotBobOmb(omObjData* obj);
void func_800F77B8_HotBobOmb(omObjData* obj, s32 unused);
void func_800F7934_HotBobOmb(omObjData* obj);
void func_800F7E84_HotBobOmb(omObjData* obj);
void func_800F8A04_HotBobOmb(void);
s32 func_800F8AB4_HotBobOmb(void);
void func_800F8CC8_HotBobOmb(void);
void func_800F8D4C_HotBobOmb(f32 t, HbCamKey* key, HbCamKey* out);

/* 10F6D0 */
void func_800F8FA0_HotBobOmb(void);
void func_800F902C_HotBobOmb(void);
void func_800F94AC_HotBobOmb(void);
s32 func_800F9610_HotBobOmb(s32 player);
void func_800F9690_HotBobOmb(void);
void func_800F9814_HotBobOmb(s32 port);
s32 func_800F99F4_HotBobOmb(s8 x, s8 y);
void func_800F9AB8_HotBobOmb(s32 player);

/* Main-code functions with no shared prototype. */
void func_80025BB8(s16, s16);
void func_80039644(s16, u8, u8);
void func_80021E58(void);
void func_80021EC0(s16, f32, f32, f32);
s16 func_8000BEBC(s16);
void func_800191F8(u16);
void func_8001249C(s16, u8);
void func_80060F04(s16, s32, s32, s32);
extern unk34D80Struct80* D_800ED554;
extern s16 ContBtn[];
extern s8 ContStkY[];

/* .data (10CD10) */
extern u32 D_800F9D30_HotBobOmb; /* random seed */

/* .data (10CF70) */
extern s32 D_800F9D40_HotBobOmb; /* bomb state */
extern HbSeat D_800F9D44_HotBobOmb[4];
extern HbSeat D_800F9DD4_HotBobOmb[4];
extern HbSeat D_800F9E64_HotBobOmb[4];
extern HbSeat D_800F9EF4_HotBobOmb[4];
extern HbSeat D_800F9F84_HotBobOmb[4];
extern HbSeat D_800FA014_HotBobOmb[4];
extern HbSeat D_800FA0A4_HotBobOmb[4];
extern s32 D_800FA134_HotBobOmb[16]; /* fuse sounds; retail reads the low half (D_800FA136) */
extern s32 D_800FA174_HotBobOmb; /* sound handles: low halves read as D_800FA176/D_800FA17A */
extern s32 D_800FA178_HotBobOmb;
extern s32 D_800FA17C_HotBobOmb; /* pan; low byte read as D_800FA17F */
extern s32 D_800FA180_HotBobOmb[4];
extern s32 D_800FA190_HotBobOmb;
extern s32 D_800FA194_HotBobOmb;
extern s32 D_800FA198_HotBobOmb;
extern s32 D_800FA19C_HotBobOmb;
extern s32 D_800FA1A0_HotBobOmb;
extern s32 D_800FA1A4_HotBobOmb;
extern s32 D_800FA1A8_HotBobOmb;
extern s32 D_800FA1AC_HotBobOmb;
extern s32 D_800FA1B0_HotBobOmb;
extern s32 D_800FA1B4_HotBobOmb;
extern s32 D_800FA1B8_HotBobOmb;
extern s32 D_800FA1BC_HotBobOmb;
extern f32 D_800FA1C0_HotBobOmb;
extern f32 D_800FA1C4_HotBobOmb;
extern HbCamKey D_800FA1C8_HotBobOmb[13];
extern f32 D_800FA39C_HotBobOmb;
extern HbCamKey* D_800FA3A0_HotBobOmb;
extern s32 D_800FA3A4_HotBobOmb;
extern s32 D_800FA3A8_HotBobOmb;
extern f32 D_800FA3AC_HotBobOmb;
extern HbCamKey* D_800FA3B0_HotBobOmb;
extern s32 D_800FA3B4_HotBobOmb;

/* .data (10F6D0) */
extern s32 D_800FA3C0_HotBobOmb[5][25];
extern s32 D_800FA5B4_HotBobOmb[4];

/* .bss */
extern f32 D_800FA860_HotBobOmb;
extern f32 D_800FA864_HotBobOmb;
extern s32 D_800FA868_HotBobOmb;
extern s16 D_800FA86C_HotBobOmb[5]; /* retail indexes [i - 1] as D_800FA86A */
extern s32 D_800FA880_HotBobOmb[4];  /* controller port per player */
extern s16 D_800FA890_HotBobOmb[5];
extern s16 D_800FA89A_HotBobOmb;
extern s32 D_800FA89C_HotBobOmb;
extern s32 D_800FA8A0_HotBobOmb[4];
extern s32 D_800FA8B0_HotBobOmb;
extern s32 D_800FA8B8_HotBobOmb[4];
extern s32 D_800FA8C8_HotBobOmb;
extern s32 D_800FA8CC_HotBobOmb;
extern s32 D_800FA8D0_HotBobOmb;
extern omObjData* D_800FA8D8_HotBobOmb[4];
extern s32 D_800FA8E8_HotBobOmb;
extern s16 D_800FA8EC_HotBobOmb;
extern HbPlayer D_800FA8F0_HotBobOmb[4];
extern s32 D_800FA920_HotBobOmb;
extern s32 D_800FA924_HotBobOmb;
extern s32 D_800FA988_HotBobOmb;
extern s32 D_800FA98C_HotBobOmb;
extern u16 D_800FA990_HotBobOmb;
extern s32 D_800FA994_HotBobOmb;
extern s32 D_800FA998_HotBobOmb;
extern s32 D_800FA99C_HotBobOmb; /* bomb holder; low half read as D_800FA99E */
extern s32 D_800FA9A0_HotBobOmb;
extern omObjData* D_800FA9A4_HotBobOmb;
extern s32 D_800FA9A8_HotBobOmb;
extern s16 D_800FA9AC_HotBobOmb[5];
extern u16 D_800FA9B6_HotBobOmb;
extern s32 D_800FA9B8_HotBobOmb;
extern s32 D_800FA9BC_HotBobOmb; /* time left */

#endif
