#ifndef SLOTCARDERBY_H
#define SLOTCARDERBY_H

/* ovl_25 SlotCarDerby: declarations for its one unit, 1C1EB0.c.
   Types come from the asm's accesses; N64 offsets are in the comments. A struct with no pointers
   has the same layout on the host. Every block is allocated with sizeof (never retail's literal
   size): the host strides pointers 8 bytes.

   Split splat labels inside a struct or array (D_80101DE6 inside D_80101DE0, D_80101E74 inside
   D_80101DF8...) are #defined below as views of the real object, so C never names a second host
   object for them; the asm keeps its labels (.bss stays asm; .data aliases are in
   undefined_syms.txt). */

#include "common.h"
#include "PR/gu.h"
#include "sprite65770.h"

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* A weighted point the camera frames (func_800FA2C0 adds one to D_80102320; D_80100E00's fixed
   course points). No pointers. */
typedef struct SCDFocus {
    /* 0x00 */ Vec pos;
    /* 0x0C */ f32 weight;
} SCDFocus; /* size = 0x10 */

/* A slot car (D_80101DF8[4], indexed by the car's track lane obj->work[1]; func_800F70C4 maps an
   object to its car). Zeroed with func_8009B770(car, 0, sizeof). Only unk_7C is a pointer, last,
   so every other offset is the host's too. */
typedef struct SCDCar {
    /* 0x00 */ u8 unk_00; /* flags: 1 in use, 0x10 on the track (pose update), 0x40 crashed out,
                             0x80 crossed the line */
    /* 0x01 */ u8 unk_01; /* player index (GwPlayer) */
    /* 0x02 */ u8 unk_02; /* state: 0 idle, 1 racing, 2 finished, 3 off the track, 4 respawn */
    /* 0x03 */ u8 unk_03; /* 1: a human is driving (stick read this frame) */
    /* 0x04 */ u8 unk_04; /* finishing place, 0 none */
    /* 0x05 */ u8 unk_05; /* cars ahead (func_800FB228) */
    /* 0x06 */ u8 unk_06; /* frames over the corner's speed limit */
    /* 0x07 */ u8 unk_07; /* start-jolt frames */
    /* 0x08 */ u8 unk_08; /* blink frames after a respawn */
    /* 0x09 */ char unk_09;
    /* 0x0A */ s16 unk_0A; /* character, 6 = the extra CPU */
    /* 0x0C */ Vec unk_0C; /* position (world / 10) */
    /* 0x18 */ Vec unk_18; /* velocity when off the track */
    /* 0x24 */ Vec unk_24; /* rotation */
    /* 0x30 */ Vec unk_30; /* track direction */
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40; /* yaw */
    /* 0x44 */ f32 unk_44; /* lean */
    /* 0x48 */ f32 unk_48; /* track distance of the lane's start */
    /* 0x4C */ f32 unk_4C; /* distance travelled */
    /* 0x50 */ f32 unk_50; /* speed (0..7) */
    /* 0x54 */ f32 unk_54;
    /* 0x58 */ f32 unk_58; /* wheel spin angle */
    /* 0x5C */ f32 unk_5C; /* spin-out angle */
    /* 0x60 */ s16 unk_60; /* braking frames */
    /* 0x62 */ s16 unk_62; /* spin-out frames */
    /* 0x64 */ u16 unk_64; /* frames in the state */
    /* 0x66 */ u16 unk_66;
    /* 0x68 */ s16 unk_68; /* CPU: frames raced */
    /* 0x6A */ s16 unk_6A; /* CPU: random bias */
    /* 0x6C */ s16 unk_6C; /* CPU: target throttle x100 */
    /* 0x6E */ s16 unk_6E; /* CPU: frame counter */
    /* 0x70 */ s16 unk_70; /* CPU: throttle x100 */
    /* 0x72 */ s16 unk_72; /* CPU: overspeed tolerance */
    /* 0x74 */ s16 unk_74; /* engine sound handle, -1 none */
    /* 0x76 */ s16 unk_76; /* frames before the engine sound restarts */
    /* 0x78 */ s16 unk_78;
    /* 0x7A */ char unk_7A[2];
    /* 0x7C */ omObjData* unk_7C; /* the player object (func_800F6F38) */
} SCDCar; /* size = 0x80 (N64) */

/* Retail tests unk_64 and unk_66 together with one word load (lw 0x64) on a state's first frame
   (func_800F88CC, func_800F91B4, func_800F9554). Comparing with 0 is endian-neutral. */
#define SCD_CAR_FRAMES0(car) (*(s32*)&(car)->unk_64 == 0)

/* The race state D_80101DE0 (one object: retail addresses its fields from one base register,
   named after the first field each function touches: D_80101DE2/E6/E8/EA). No pointers. */
typedef struct SCDGame {
    /* 0x00 */ s16 unk_00; /* state: 0 intro, 1 countdown, 2 race, 3 result, 4 leave, 7 time up */
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04; /* winning car, -1 none */
    /* 0x06 */ s16 unk_06; /* frames in the state */
    /* 0x08 */ s16 unk_08; /* race frames left (0xE10) */
    /* 0x0A */ s16 unk_0A; /* frames the start-line focus stays */
    /* 0x0C */ s16 unk_0C; /* most cars ahead of a human */
} SCDGame; /* size = 0xE */

/* The background particles D_80102008[16] (func_800FAACC). No pointers. */
typedef struct SCDParticle {
    /* 0x00 */ s16 unk_00; /* 0 off, -0x7FFF unused, 0x8000 bit hidden */
    /* 0x02 */ s16 unk_02; /* sprite */
    /* 0x04 */ s16 unk_04; /* sprite group */
    /* 0x06 */ s16 unk_06; /* index in the group */
    /* 0x08 */ u16 unk_08; /* frames alive */
    /* 0x0A */ s16 unk_0A; /* sway angle */
    /* 0x0C */ f32 unk_0C; /* screen x */
    /* 0x10 */ f32 unk_10; /* screen y */
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18; /* y speed */
    /* 0x1C */ f32 unk_1C; /* x scale */
    /* 0x20 */ f32 unk_20; /* y scale */
    /* 0x24 */ f32 unk_24; /* sway amplitude */
    /* 0x28 */ f32 unk_28; /* scale */
    /* 0x2C */ char unk_2C[4];
} SCDParticle; /* size = 0x30 */

/* One camera pose: retail indexes centre and view as f32[3] (func_800FA3B4). No pointers. */
typedef struct SCDCamPose {
    /* 0x00 */ f32 pos[3];  /* centre */
    /* 0x0C */ f32 view[3]; /* view direction */
    /* 0x18 */ f32 zoom;
} SCDCamPose; /* size = 0x1C */

/* The camera D_80102420 (func_800FA154 sets it, func_800FA3B4 eases cur towards target). */
typedef struct SCDCamera {
    /* 0x00 */ SCDCamPose target;
    /* 0x1C */ SCDCamPose cur;
    /* 0x38 */ char unk_38[8];
} SCDCamera; /* size = 0x40 */

/* A scenery record: D_80102468 (HuMemDirectMalloc(0x600): 16) and D_8010246C (0x300: 8). The
   board (D_80102468[0], func_800FC0BC's object) and the time board (D_80102468[1], func_800FC394's
   object) are reached through omObjData::work (func_800FDD08/func_800FDD28). No pointers. */
typedef struct SCDObj {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ char unk_04[4];
    /* 0x08 */ s16 unk_08; /* frame counter */
    /* 0x0A */ char unk_0A[2];
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ Vec unk_10; /* position */
    /* 0x1C */ Vec unk_1C;
    /* 0x28 */ Vec unk_28;
    /* 0x34 */ char unk_34[0xC];
    /* 0x40 */ s16 unk_40[16]; /* billboards (func_800FE2F0), [0]/[1] also an alternating index */
} SCDObj; /* size = 0x60 */

/* An effect slot D_80102470 (HuMemDirectMalloc(0x700): 32, func_800FCD6C). No pointers. */
typedef struct SCDFx {
    /* 0x00 */ s8 unk_00; /* its billboard (func_800FE2F0) */
    /* 0x01 */ s8 unk_01; /* type: 0 smoke billboard, 1 spark, 2 dust sprite; -1 free */
    /* 0x02 */ u16 unk_02; /* frame */
    /* 0x04 */ u16 unk_04; /* frames left */
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ Vec unk_08; /* position */
    /* 0x14 */ Vec unk_14; /* rotation */
    /* 0x20 */ f32 unk_20; /* scale x */
    /* 0x24 */ f32 unk_24; /* scale y */
    /* 0x28 */ f32 unk_28; /* scale z */
    /* 0x2C */ Vec unk_2C;
} SCDFx; /* size = 0x38 */

/* A billboard D_80103298[D_8010248C] (func_800FE138; func_800FE2F0 builds its display lists,
   func_800FFD18 draws it). The pointer fields shift every later field on the host: use names,
   never offsets. unk_04/unk_10 hold D_800F37DA (<= 3) per-frame copies. */
typedef struct SCDBillboard {
    /* 0x00 */ Gfx* unk_00;    /* display list, (Gfx*)-1 = free */
    /* 0x04 */ Gfx* unk_04[3]; /* per-frame material lists (D_800F37F0 picks one) */
    /* 0x10 */ Vtx* unk_10[3]; /* per-frame vertices (0x80 bytes) */
    /* 0x1C */ s32 unk_1C; /* a pointer: only cleared here; func_800FFD18 reads [2 + frame]
                                   from it when unk_20 is set, which nothing in the overlay does */
    /* 0x20 */ s8 unk_20;
    /* 0x21 */ char unk_21;
    /* 0x22 */ u16 unk_22; /* sprite (D_800EC700 index) */
    /* 0x24 */ s16 unk_24; /* frame */
    /* 0x26 */ s16 unk_26;
    /* 0x28 */ u8 unk_28; /* flags: 1 no animation, 2 hold, 4 hide at end, 0x18 render mode,
                             0x20 hidden, 0x40 free at end, 0x80 no billboard */
    /* 0x29 */ u8 unk_29; /* alpha */
    /* 0x2A */ u8 unk_2A; /* r */
    /* 0x2B */ u8 unk_2B; /* g */
    /* 0x2C */ u8 unk_2C; /* b */
    /* 0x2D */ char unk_2D[3];
    /* 0x30 */ f32 unk_30; /* frame timer */
    /* 0x34 */ f32 unk_34; /* animation speed */
    /* 0x38 */ Vec unk_38; /* position */
    /* 0x44 */ Vec unk_44; /* scale */
    /* 0x50 */ Vec unk_50; /* rotation */
} SCDBillboard; /* size = 0x5C (N64) */

/* omObjData::unk_50 of the car-driver objects (func_800F76E8) and of the board object
   (func_800FC0BC): func_80023684(0xE8), MgWork's layout (src/99E0.c), whose pointers sit at 0xB8,
   0xD8, 0xDC and 0xE4. */
typedef struct SCDPlayerWork {
    /* 0x00 */ char unk_00[0x56];
    /* 0x56 */ s8 unk_56; /* controller port */
    /* 0x57 */ char unk_57[0x61];
    /* 0xB8 */ void* unk_B8;
    /* 0xBC */ char unk_BC[4];
    /* 0xC0 */ u16 unk_C0; /* current motion, 0xFFFF none */
    /* 0xC2 */ char unk_C2[0x16];
    /* 0xD8 */ void* unk_D8; /* motion table: obj->mtncnt * 4 (drivers), * sizeof (board) */
    /* 0xDC */ void* unk_DC;
    /* 0xE0 */ char unk_E0[4];
    /* 0xE4 */ void* unk_E4;
} SCDPlayerWork; /* size = 0xE8 (N64) */

#define SCD_WORK(obj) ((SCDPlayerWork*)(obj)->unk_50)

/* ---------------------------------------------------------------------------------------------
   Main-code declarations missing from include/ (or declared wider there)
   --------------------------------------------------------------------------------------------- */
void func_80020EA0(s16, char*, s16, char*);
void func_80021E58(void);
void func_80021EC0(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
/* Defined s16 (src/24740.c); retail's caller here uses the whole v0 (a call without the s16
   prototype), so the N64 build declares it s32 as src/1EA70.c does. */
s32 func_80024198(u32, Gfx*, s32);
unk2C0C0Struct50* func_80026A0C(s16, char*);
void func_80023A38(void* src, void* dst, s32 size); /* copy (engine/mallocblock.h) */
void func_800343C8(s16);
void func_800594E4(s16, u16);
void func_8006035C(s16, s8);
void func_80060440(s16, s16);
void func_80060F04(s16, s16, s16, s16);
unk65770Anim* func_80067310(s16);
f64 func_8009B618(f64, f64); /* fmod */
void func_8009E060(Matrix4f, f32 angle, f32 x, f32 y, f32 z);
void func_800AC0B0(Matrix4f, Matrix4f, Matrix4f);

extern u8 D_800F64F8;
extern s16 D_800EE984;
extern omObjData* D_800F2AF8[];
extern unk65770Anim* D_800EC700[256];

/* ---------------------------------------------------------------------------------------------
   Overlay functions
   --------------------------------------------------------------------------------------------- */
void func_800F65E0_SlotCarDerby(void);
void func_800F6A14_SlotCarDerby(omObjData* obj);
void func_800F6A38_SlotCarDerby(omObjData* obj);
void func_800F6AEC_SlotCarDerby(void);
void func_800F6D90_SlotCarDerby(void);
void func_800F6ED4_SlotCarDerby(SCDCar* car, s16 sound);
void func_800F6F38_SlotCarDerby(omObjData* obj);
void func_800F7084_SlotCarDerby(omObjData* obj);
SCDCar* func_800F70C4_SlotCarDerby(omObjData* obj);
s32 func_800F70DC_SlotCarDerby(void);
void func_800F744C_SlotCarDerby(s16 kind, SCDCar* car);
void func_800F7650_SlotCarDerby(s16 model, f32 speed);
void func_800F7678_SlotCarDerby(omObjData* obj);
void func_800F7694_SlotCarDerby(omObjData* obj);
void func_800F76B0_SlotCarDerby(omObjData* obj);
void func_800F76CC_SlotCarDerby(omObjData* obj);
void func_800F76E8_SlotCarDerby(omObjData* obj, s16 player);
void func_800F7A00_SlotCarDerby(omObjData* obj);
s32 func_800F7A7C_SlotCarDerby(omObjData* obj);
void func_800F8270_SlotCarDerby(omObjData* obj, s32 throttle);
void func_800F87E4_SlotCarDerby(SCDCar* car, f32 ahead);
void func_800F88CC_SlotCarDerby(omObjData* obj, f32 throttle);
void func_800F8FF8_SlotCarDerby(omObjData* obj);
void func_800F91B4_SlotCarDerby(omObjData* obj);
void func_800F9554_SlotCarDerby(omObjData* obj);
s32 func_800F95F4_SlotCarDerby(f32 dist);
f32 func_800F96F4_SlotCarDerby(f32 start, f32 dist, f32 step, Vec* pos, Vec* dir);
s32 func_800F9A0C_SlotCarDerby(Vec* pos, f32* groundY);
f32 func_800F9B60_SlotCarDerby(f32 t, f32 a, f32 b, f32 c);
void func_800F9BC0_SlotCarDerby(f32 t, Vec* a, Vec* b, Vec* c, Vec* out);
f32 func_800F9C5C_SlotCarDerby(f32 t, f32 a, f32 b, f32 c);
void func_800F9CB4_SlotCarDerby(f32 t, Vec* a, Vec* b, Vec* c, Vec* out);
f32 func_800F9E24_SlotCarDerby(f32 x, f32 y);
void func_800F9EA4_SlotCarDerby(Vec* dir, f32* angles); /* angles: a Vec, written through ++ */
void func_800F9F2C_SlotCarDerby(Matrix4f m, f32 x, f32 y, f32 z, f32* out); /* out: a Vec */
void func_800F9FC8_SlotCarDerby(Matrix4f m, Vec* angles);
void func_800FA154_SlotCarDerby(void);
void func_800FA2C0_SlotCarDerby(f32* pos, f32 weight); /* pos: a Vec, read through ++ */
void func_800FA32C_SlotCarDerby(s32 x, s32 y, s32 z, s32 weight);
void func_800FA3B4_SlotCarDerby(Vec* centre);
void func_800FAACC_SlotCarDerby(void);
void func_800FAC28_SlotCarDerby(void);
void func_800FAE98_SlotCarDerby(void);
void func_800FB004_SlotCarDerby(omObjData* obj);
void func_800FB1C0_SlotCarDerby(void);
void func_800FB228_SlotCarDerby(void);
void func_800FB2FC_SlotCarDerby(s32 x, s32 y, s32 z);
void func_800FBDFC_SlotCarDerby(void);
void func_800FBE20_SlotCarDerby(s16 state);
s32 func_800FBE7C_SlotCarDerby(u8 player, s16 crossed);
void func_800FBEE0_SlotCarDerby(s16 course);
void func_800FC0BC_SlotCarDerby(omObjData* obj);
void func_800FC394_SlotCarDerby(omObjData* obj);
void func_800FCCA0_SlotCarDerby(s16 anim, s32 r, s32 g, s32 b);
void func_800FCD6C_SlotCarDerby(omObjData* obj);
void func_800FCF50_SlotCarDerby(omObjData* obj);
void func_800FD2C4_SlotCarDerby(omObjData* obj);
void func_800FD658_SlotCarDerby(omObjData* obj);
void func_800FD9E8_SlotCarDerby(s32 type, Vec* pos, Vec* rot);
void func_800FDA04_SlotCarDerby(s32 type, Vec* pos, Vec* rot); /* type: SCDFx.unk_01 */
void func_800FDD08_SlotCarDerby(omObjData* obj, SCDObj* rec);
SCDObj* func_800FDD28_SlotCarDerby(omObjData* obj);
void func_800FDD54_SlotCarDerby(s32 cam, Vec* pos, Vec* screen);
void func_800FE138_SlotCarDerby(u8 count);
s16 func_800FE2F0_SlotCarDerby(s16 sprite, u8 flags); /* callers pass sprite unmasked (lh) */
void func_800FF53C_SlotCarDerby(s16 id, s16 frame);
void func_800FF57C_SlotCarDerby(s16 id, f32 speed);
void func_800FF5BC_SlotCarDerby(s16 id, f32 x, f32 y, f32 z);
void func_800FF60C_SlotCarDerby(s16 id, f32 x, f32 y, f32 z);
void func_800FF65C_SlotCarDerby(s16 id, f32 x, f32 y, f32 z);
void func_800FF6AC_SlotCarDerby(s16 id, u8 flags);
void func_800FF6F0_SlotCarDerby(s16 id, u8 flags);
void func_800FF738_SlotCarDerby(s16 id, u8 r, u8 g, u8 b, s32 a);
void func_800FF784_SlotCarDerby(s16 id);
void func_800FF8A4_SlotCarDerby(void);
void func_800FFD18_SlotCarDerby(void);
void func_801001F8_SlotCarDerby(void);

/* ---------------------------------------------------------------------------------------------
   .data (defined in 1C1EB0.c, before func_800F76E8)
   --------------------------------------------------------------------------------------------- */
extern Vec D_801002B0_SlotCarDerby[86];  /* course 0's track points */
extern Vec D_801006B8_SlotCarDerby[122]; /* course 1's */
extern Vec* D_80100C70_SlotCarDerby[2];  /* track points per course */
extern u16 D_80100C78_SlotCarDerby[2];   /* their counts */
extern s16 D_80100C7C_SlotCarDerby[2][4]; /* [course][lane]: start segment */
extern s16 D_80100C8C_SlotCarDerby[2];   /* [course]: start offset */
extern s32 D_80100C90_SlotCarDerby[7];   /* speed limits by corner class */
extern s32 D_80100CAC_SlotCarDerby[4];   /* limit bonus by cars ahead */
extern char* D_80100CBC_SlotCarDerby[7]; /* [character]: head part name */
extern u16 D_80100CD8_SlotCarDerby[7];   /* [character]: car model */
extern f32 D_80100CE8_SlotCarDerby[7];   /* [character]: head scale */
extern f32 D_80100D04_SlotCarDerby[7][2]; /* [character]: head offset (D_80100D08 = [0][1]) */
extern u8 D_80100D3C_SlotCarDerby[10][3]; /* course 0 corners: first, last segment, class; 0xFF ends */
extern u8 D_80100D5C_SlotCarDerby[18][3]; /* course 1's */
extern f32 D_80100D94_SlotCarDerby[6];   /* course 0 camera: centre, view */
extern f32 D_80100DAC_SlotCarDerby[6];   /* course 1's */
extern f32 D_80100DC4_SlotCarDerby[6];
extern f32 D_80100DDC_SlotCarDerby[6];
extern f32* D_80100DF4_SlotCarDerby[2];  /* {D_80100DC4, D_80100DDC} */
extern f32 D_80100DFC_SlotCarDerby;      /* camera ease */
extern SCDFocus D_80100E00_SlotCarDerby[9]; /* [course * 3 + i] intro points, [6..8] start line */
extern s16 D_80100E90_SlotCarDerby;      /* crowd sound handle, -1 none */
extern s16 D_80100E92_SlotCarDerby;      /* result frames */
extern f32 D_80100E94_SlotCarDerby;      /* intro zoom-in factor */
extern f32 D_80100E98_SlotCarDerby[2];   /* unreferenced */
extern s32 D_80100EA0_SlotCarDerby;      /* scenery state (func_800FBE20) */
extern s32 D_80100EA4_SlotCarDerby;      /* a car crossed the line */
extern s32 D_80100EA8_SlotCarDerby;      /* frame buffer index 0..2 */
extern s32 D_80100EAC_SlotCarDerby;      /* course; retail reads (u16) */
extern s32 D_80100EB0_SlotCarDerby;      /* race time; retail reads (u16) */
extern s32 D_80100EB4_SlotCarDerby;      /* record time */
extern s32 D_80100EB8_SlotCarDerby;      /* new record */
extern s32 D_80100EBC_SlotCarDerby;
extern Vec D_80100EC0_SlotCarDerby[2];   /* [course]: board position */
extern f32 D_80100ED8_SlotCarDerby[6];   /* time digit x */
extern f32 D_80100EF0_SlotCarDerby[2];   /* [course]: time board z */
extern f32 D_80100EF8_SlotCarDerby[2];
extern Vec D_80100F00_SlotCarDerby[2];   /* [course]: lamp position */
extern s32 D_80100F18_SlotCarDerby[7];   /* record digit x (read (s16)) */
extern s32 D_80100F34_SlotCarDerby[7];   /* record digits (read (s16)) */
extern s32 D_80100F50_SlotCarDerby[2];   /* file ids */
extern s32 D_80100F58_SlotCarDerby[6];   /* lamp frame lengths */
extern s32 D_80100F70_SlotCarDerby[6];   /* race time digits (read (s16)) */
extern s16 D_80100F88_SlotCarDerby[4];   /* render modes by SCDBillboard.unk_28 & 0x18 */

/* Labels inside those objects that the remaining asm uses (undefined_syms.txt) */
#define D_80100D08_SlotCarDerby (D_80100D04_SlotCarDerby[0][1])
#define D_80100E04_SlotCarDerby (D_80100E00_SlotCarDerby[0].pos.y)
#define D_80100E08_SlotCarDerby (D_80100E00_SlotCarDerby[0].pos.z)
#define D_80100E0C_SlotCarDerby (D_80100E00_SlotCarDerby[0].weight)
#define D_80100E60_SlotCarDerby (D_80100E00_SlotCarDerby[6])
#define D_80100EAE_SlotCarDerby ((u16)D_80100EAC_SlotCarDerby)
#define D_80100EB2_SlotCarDerby ((u16)D_80100EB0_SlotCarDerby)
#define D_80100EC4_SlotCarDerby (D_80100EC0_SlotCarDerby[0].y)
#define D_80100EC8_SlotCarDerby (D_80100EC0_SlotCarDerby[0].z)
#define D_80100F04_SlotCarDerby (D_80100F00_SlotCarDerby[0].y)
#define D_80100F08_SlotCarDerby (D_80100F00_SlotCarDerby[0].z)

/* ---------------------------------------------------------------------------------------------
   .bss (ovl_25_bss.bss.s, 0x80101420..0x801024C0)
   --------------------------------------------------------------------------------------------- */
extern s16 D_80101420_SlotCarDerby;      /* course 0/1 */
extern Vec* D_80101424_SlotCarDerby;     /* track points (D_80100C70[course]) */
extern s16 D_80101428_SlotCarDerby;      /* their count */
extern f32* D_8010142C_SlotCarDerby;     /* [count] segment lengths */
extern f32* D_80101430_SlotCarDerby;     /* [count + 1] distance at each point */
extern f32 D_80101434_SlotCarDerby;      /* lap length */
extern Vec D_80101440_SlotCarDerby[200]; /* segment midpoints (D_80101444/48 are .y/.z of [0]) */
extern s32 D_80101DA0_SlotCarDerby[16];
extern SCDGame D_80101DE0_SlotCarDerby;
extern s16 D_80101DEE_SlotCarDerby;      /* 1: leave */
extern s16 D_80101DF0_SlotCarDerby;      /* fade-out started */
extern s16 D_80101DF2_SlotCarDerby;      /* overlay return requested */
extern s16 D_80101DF4_SlotCarDerby;      /* crowd swell frame; retail also reads (u8) */
extern s16 D_80101DF6_SlotCarDerby;      /* a new record was set */
extern SCDCar D_80101DF8_SlotCarDerby[4];
extern unk2C0C0Struct50* D_80101FF8_SlotCarDerby[4]; /* [player]: the driver's head part */
extern SCDParticle D_80102008_SlotCarDerby[16];
extern s16 D_80102308_SlotCarDerby;      /* cars placed */
extern s16 D_8010230A_SlotCarDerby[4];   /* lane order */
extern s16 D_80102312_SlotCarDerby;      /* next finishing place */
extern s16 D_80102314_SlotCarDerby;
extern s32 D_80102318_SlotCarDerby;      /* focus points this frame */
extern SCDFocus D_80102320_SlotCarDerby[16];
extern SCDCamera D_80102420_SlotCarDerby;
extern s32 D_80102460_SlotCarDerby[2];   /* board model ids (read (s16)) */
extern SCDObj* D_80102468_SlotCarDerby;  /* [16] */
extern SCDObj* D_8010246C_SlotCarDerby;  /* [8] */
extern SCDFx* D_80102470_SlotCarDerby;   /* [32] */
extern s32 D_80102474_SlotCarDerby;      /* sprite group (s16 in a word; read (s16)) */
extern s32 D_80102478_SlotCarDerby;      /* sprite group (read (s16)) */
extern s32 D_8010247C_SlotCarDerby[3];   /* effect sprites by SCDFx type (read (s16)) */
extern s32 D_80102488_SlotCarDerby;      /* effect sprite group (read (s16)) */
extern s32 D_8010248C_SlotCarDerby;      /* billboard count */
extern Gfx* D_80102490_SlotCarDerby[3];  /* per-frame billboard display lists */
extern Mtx* D_8010249C_SlotCarDerby[3];  /* per-frame billboard matrices */
extern s32 D_801024A8_SlotCarDerby;      /* the billboard model (func_80024198) */
extern s16 D_801024B0_SlotCarDerby;      /* mode: 0 minigame, 1/2 story variants (flags 0x2B/0x2D) */
extern s16 D_801024B2_SlotCarDerby;
extern s16 D_801024B4_SlotCarDerby;
/* Fixed RAM past the overlay's .bss (undefined_syms_auto.txt: 0x80103298); the host's gen_ovl.py
   gives it a scratch object. */
extern SCDBillboard* D_80103298;

/* Views of the split .bss labels: write these as fields, never as separate objects */
#define D_80101DE2_SlotCarDerby (D_80101DE0_SlotCarDerby.unk_02)
#define D_80101DE4_SlotCarDerby (D_80101DE0_SlotCarDerby.unk_04)
#define D_80101DE6_SlotCarDerby (D_80101DE0_SlotCarDerby.unk_06)
#define D_80101DE8_SlotCarDerby (D_80101DE0_SlotCarDerby.unk_08)
#define D_80101DEA_SlotCarDerby (D_80101DE0_SlotCarDerby.unk_0A)
#define D_80101DEC_SlotCarDerby (D_80101DE0_SlotCarDerby.unk_0C)
#define D_80101DF5_SlotCarDerby ((u8)D_80101DF4_SlotCarDerby)
#define D_80101DF9_SlotCarDerby (D_80101DF8_SlotCarDerby[0].unk_01)
#define D_80101DFC_SlotCarDerby (D_80101DF8_SlotCarDerby[0].unk_04)
#define D_80101E74_SlotCarDerby (D_80101DF8_SlotCarDerby[0].unk_7C)
#define D_80101444_SlotCarDerby (D_80101440_SlotCarDerby[0].y)
#define D_80101448_SlotCarDerby (D_80101440_SlotCarDerby[0].z)
#define D_80102324_SlotCarDerby (D_80102320_SlotCarDerby[0].pos.y)
#define D_80102328_SlotCarDerby (D_80102320_SlotCarDerby[0].pos.z)
#define D_8010232C_SlotCarDerby (D_80102320_SlotCarDerby[0].weight)
#define D_80102424_SlotCarDerby (D_80102420_SlotCarDerby.target.pos[1])
#define D_80102428_SlotCarDerby (D_80102420_SlotCarDerby.target.pos[2])
#define D_8010242C_SlotCarDerby (D_80102420_SlotCarDerby.target.view[0])
#define D_80102430_SlotCarDerby (D_80102420_SlotCarDerby.target.view[1])
#define D_80102434_SlotCarDerby (D_80102420_SlotCarDerby.target.view[2])
#define D_80102462_SlotCarDerby ((s16)D_80102460_SlotCarDerby[0])
#define D_80102476_SlotCarDerby ((s16)D_80102474_SlotCarDerby)
#define D_8010247A_SlotCarDerby ((s16)D_80102478_SlotCarDerby)
#define D_8010247E_SlotCarDerby ((s16)D_8010247C_SlotCarDerby[0])
#define D_80102484_SlotCarDerby (D_8010247C_SlotCarDerby[2])
#define D_8010248A_SlotCarDerby ((s16)D_80102488_SlotCarDerby)

#endif
