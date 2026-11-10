#ifndef TIPSYTOURNEY_H
#define TIPSYTOURNEY_H

/* ovl_21 TipsyTourney: declarations for its unit (1A4EB0.c).
   Types come from the asm's accesses; N64 offsets are in the comments. */

#include "common.h"
#include "engine/pad.h"
#include "sprite65770.h"

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* Work of the board object and of the four platforms (func_80023684(0x2C)). No pointers. */
typedef struct TipsyBgWork {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05; /* platform 1..4 (0 for the board object); D_800F2AF8 index */
    /* 0x06 */ char unk_06[0x26];
} TipsyBgWork; /* size = 0x2C */

/* Work of the players (func_8000979C, 0xE8) and of the balls in D_800EDE70 (func_800F8088, only
   see TipsyBallWork): MgWork's layout (src/99E0.c), with every pointer
   member where MgWork has one so the host offsets agree. */
typedef struct TipsyWork {
    /* 0x00 */ char unk_00[0x34];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38; /* vertical speed, 1000 = on the ground */
    /* 0x3C */ f32 unk_3C; /* facing */
    /* 0x40 */ f32 unk_40; /* speed */
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48; /* radius */
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50; /* flags */
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ s8 unk_53; /* platform it is on (TipsyBgWork::unk_05), -1 none */
    /* 0x54 */ u8 unk_54; /* ball: 1 still held up (not yet dropped) */
    /* 0x55 */ char unk_55;
    /* 0x56 */ s8 unk_56; /* controller port */
    /* 0x57 */ char unk_57;
    /* 0x58 */ s8 unk_58; /* player */
    /* 0x59 */ char unk_59[3];
    /* 0x5C */ s32 unk_5C; /* ball: index 0..3 into the per-ball tables */
    /* 0x60 */ char unk_60[0x58];
    /* 0xB8 */ omObjData* unk_B8; /* MgWork's held item */
    /* 0xBC */ char unk_BC[0x1C];
    /* 0xD8 */ s16 (*unk_D8)[2]; /* one pair per motion */
    /* 0xDC */ void* unk_DC; /* collision callback */
    /* 0xE0 */ char unk_E0[4];
    /* 0xE4 */ void* unk_E4;
} TipsyWork; /* size = 0xE8 (N64) */

/* Work of a ball (func_800F8088, func_80023684(0x6C)): TipsyWork's first 0x6C bytes, with
   unk_53 unsigned (0xFF once it has fallen off). No pointers. */
typedef struct TipsyBallWork {
    /* 0x00 */ char unk_00[0x34];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38; /* vertical speed, 1000 = on the ground */
    /* 0x3C */ f32 unk_3C; /* direction */
    /* 0x40 */ f32 unk_40; /* speed */
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48; /* radius */
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ u8 unk_53; /* platform it is on (TipsyBgWork::unk_05), 0xFF none */
    /* 0x54 */ u8 unk_54; /* 1 until it is released (the timer runs out or a player wins) */
    /* 0x55 */ char unk_55[7];
    /* 0x5C */ s32 unk_5C; /* index 0..3 into the per-ball tables */
    /* 0x60 */ char unk_60[0xC];
} TipsyBallWork; /* size = 0x6C */

#define TIPSY_WORK(obj) ((TipsyWork*)(obj)->unk_50)
#define TIPSY_BG(obj) ((TipsyBgWork*)(obj)->unk_50)

/* A CPU's dash direction (D_800FB9A8_TipsyTourney): retail stores the halves and reads their low
   bytes (D_800FB9A9 / D_800FB9AB) as the stick values. */
typedef struct TipsyDash {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 z;
} TipsyDash;

/* ---------------------------------------------------------------------------------------------
   Main-code declarations
   --------------------------------------------------------------------------------------------- */

extern omObjData* D_800EDE70[]; /* src/1130.c's collision list, D_800EE984 entries */
extern u16 D_800EE984;
extern omObjData* D_800F2AF8[];
extern u16 D_800ED440;
extern s32 D_800EDEC0;
extern f32 D_800B895C;
extern f32 D_800B8990;
extern f32 D_800B8994;
extern f32 D_800ED6B8;
extern f32 D_800F5254;
extern u8 D_800F64F8;
extern u8 D_800ED433;
extern Vec3f CenterM[];
extern Vec3f CRotM[];
extern f32 CZoomM[];

void omOutViewMulti(omObjData* obj);
void func_80017940(s32);
void func_800090C4(omObjData* obj, u8 idx, u8 val);
void func_8000A1C0(Matrix4f m, Matrix4f out, Vec3f* p, omObjData* obj);
void func_8000A988(omObjData*, f32, f32);
void func_800078E8(f32, f32, f32);
void func_8002956C(Vec3f*);
f32 func_80029518(f32);
void func_80037178(s16, Vec3f*);
s32 func_80004D1C(omObjData*, Vec4f*, f32);
f32 func_800051D4(omObjData*, f32, f32, f32, Vec3f*);
void func_80060F04(s16, s32, s32, s32);
void func_8003A060(Gfx** arg0, s32 timg, s32 fmt, s32 siz, s32 width, s32 height, s32 uls, s32 ult,
                   s32 lrs, s32 lrt, s32 pal, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt);

/* ---------------------------------------------------------------------------------------------
   Overlay data (.data / .bss, 1A4EB0.c)
   --------------------------------------------------------------------------------------------- */

extern f32 D_800FB7B0_TipsyTourney;        /* ball drift scale: 20, 30 while playing, 0 after */
extern s16 D_800FB7B4_TipsyTourney;        /* frames since the end */
extern s16 D_800FB7B8_TipsyTourney[4][5][5]; /* tile state per platform: 0 up, >0 sinking, -1 gone */
extern Vec3f D_800FB880_TipsyTourney[4];   /* ball position in its platform's space */
extern s8 D_800FB8B0_TipsyTourney;         /* winner, -1 none */
extern s32 D_800FB8B4_TipsyTourney;
extern s32 D_800FB8B8_TipsyTourney;        /* time left */
extern s32 D_800FB8BC_TipsyTourney;
extern s32 D_800FB8C0_TipsyTourney;
extern Gfx D_800FB8C8_TipsyTourney[];
extern Vec3f D_800FB908_TipsyTourney[4];   /* ball spin (x, -, z) */
extern f32 D_800FB938_TipsyTourney[4];     /* ball yaw */
extern Vec3f D_800FB948_TipsyTourney[4];   /* ball ground normal */
extern f32 D_800FB978_TipsyTourney[4];     /* CPU stick strength */
extern u16 D_800FB988_TipsyTourney[4];     /* CPU frames before the next choice */
extern f32 D_800FB990_TipsyTourney[4];     /* CPU circling direction (+1 / -1) */
extern s16 D_800FB9A0_TipsyTourney[4];     /* CPU dash cooldown */
extern TipsyDash D_800FB9A8_TipsyTourney[4];

extern f32 D_800FB9D0_TipsyTourney;
extern f32 D_800FB9D4_TipsyTourney;
extern Matrix4f D_800FB9D8_TipsyTourney;
extern Matrix4f D_800FBA18_TipsyTourney;
extern s16 D_800FBA58_TipsyTourney[4][5][5]; /* tile -> unk_D0 group of the platform model */
extern u16 D_800FBB20_TipsyTourney;          /* background sprite group */

/* ---------------------------------------------------------------------------------------------
   Functions
   --------------------------------------------------------------------------------------------- */

void func_800F65E0_TipsyTourney(void);
void func_800F6CA4_TipsyTourney(void);
void func_800F6CCC_TipsyTourney(void);
void func_800F6CF8_TipsyTourney(omObjData* obj, u8 state, u32 time);
void func_800F6D60_TipsyTourney(omObjData* obj);
void func_800F7160_TipsyTourney(omObjData* obj);
void func_800F7354_TipsyTourney(omObjData* obj);
void func_800F7500_TipsyTourney(omObjData* obj);
void func_800F76A8_TipsyTourney(omObjData* obj);
void func_800F7854_TipsyTourney(omObjData* obj);
void func_800F7A00_TipsyTourney(omObjData* obj, s32 dir, s32 file0, s32 file1, s32 idx, f32 x, f32 y, f32 z);
void func_800F7C3C_TipsyTourney(omObjData* obj);
void func_800F7D4C_TipsyTourney(omObjData* obj);
void func_800F7E60_TipsyTourney(omObjData* obj);
void func_800F7F74_TipsyTourney(omObjData* obj);
void func_800F8088_TipsyTourney(omObjData* obj, s32 file, f32 scale, f32 angle, f32 x, f32 y, f32 z, s32 idx);
void func_800F81C8_TipsyTourney(omObjData* obj);
void func_800F8278_TipsyTourney(omObjData* obj);
void func_800F832C_TipsyTourney(omObjData* obj);
void func_800F83E4_TipsyTourney(omObjData* obj);
void func_800F849C_TipsyTourney(omObjData* obj);
void func_800F8500_TipsyTourney(void);
void func_800F8800_TipsyTourney(omObjData* obj);
void func_800F8C2C_TipsyTourney(omObjData* obj, f32 dx, f32 dz);
f32 func_800F8D2C_TipsyTourney(omObjData* obj);
f32 func_800F8FE0_TipsyTourney(omObjData* obj);
void func_800F9290_TipsyTourney(omObjData* obj);
void func_800F9454_TipsyTourney(omObjData* obj);
void func_800F9718_TipsyTourney(omObjData* obj);
void func_800F9800_TipsyTourney(void);
void func_800F9898_TipsyTourney(void);
void func_800F9980_TipsyTourney(s16 model, s32 p);
void func_800F9C48_TipsyTourney(s16 model, s32 p);
void func_800FA074_TipsyTourney(omObjData* obj);
f32 func_800FA14C_TipsyTourney(omObjData* obj, f32 x, f32 y, f32 z, Vec3f* normal);
void func_800FA238_TipsyTourney(omObjData* obj, Vec3f* normal);
void func_800FA3C4_TipsyTourney(omObjData* obj);
void func_800FA880_TipsyTourney(omObjData* obj);
s32 func_800FA94C_TipsyTourney(s32 p);
s32 func_800FAA9C_TipsyTourney(s32 p);
s32 func_800FABCC_TipsyTourney(s32 p);
void func_800FAC80_TipsyTourney(omObjData* obj);
void func_800FB504_TipsyTourney(Vec4f* p);
s32 func_800FB634_TipsyTourney(omObjData* obj, omObjData* other);

#endif /* TIPSYTOURNEY_H */
