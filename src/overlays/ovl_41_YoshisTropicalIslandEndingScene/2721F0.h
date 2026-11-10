#include "ending.h"


extern Gfx* D_800F37DC;
extern Gfx D_8010ECB0_YoshisTropicalIslandEndingScene[];
void func_8010AA38_YoshisTropicalIslandEndingScene(omObjData*);
void func_80108B60_YoshisTropicalIslandEndingScene(omObjData*);
extern const f64 D_8010F758_YoshisTropicalIslandEndingScene;
extern const f64 D_8010F760_YoshisTropicalIslandEndingScene;
extern const f64 D_8010F768_YoshisTropicalIslandEndingScene;
void func_8010AC5C_YoshisTropicalIslandEndingScene(omObjData*);
void func_8010AE40_YoshisTropicalIslandEndingScene(omObjData*);
void func_8010AFF8_YoshisTropicalIslandEndingScene(omObjData*);

void func_80108CB8_YoshisTropicalIslandEndingScene(omObjData*);
void func_80108D40_YoshisTropicalIslandEndingScene(omObjData*);
void func_80108E20_YoshisTropicalIslandEndingScene(omObjData*);
void func_80108EB8_YoshisTropicalIslandEndingScene(omObjData*);
omObjData* func_8010903C_YoshisTropicalIslandEndingScene(s32, f32, f32);
void func_80109110_YoshisTropicalIslandEndingScene(omObjData*);
omObjData* func_801091A4_YoshisTropicalIslandEndingScene(u8);
void func_8010920C_YoshisTropicalIslandEndingScene(Gfx**);
void func_8010A740_YoshisTropicalIslandEndingScene(omObjData*);
void func_8010A7EC_YoshisTropicalIslandEndingScene(omObjData*);
void func_8010AC24_YoshisTropicalIslandEndingScene(omObjData*);
void func_8010AE08_YoshisTropicalIslandEndingScene(omObjData*);
void func_8010AF58_YoshisTropicalIslandEndingScene(omObjData*);
void func_8010B0C0_YoshisTropicalIslandEndingScene(omObjData*);
void func_8010B0E4_YoshisTropicalIslandEndingScene(void);

/* engine functions without an include/ prototype (types from their C definitions) */
void func_80052DC8(s16, void*);
void func_80026018(s16, f32);
void func_8004B68C(Vec2f*);
void func_8001ABA0(u16);
void func_8004B7F8(s32);
s16 func_8002451C(s32, void*, s32);
void func_80028C64(s16, u8, u8, u8, u8);
void func_8004B1B8(void);
void func_800ACE70(Matrix4f, Vec3f*, Vec3f*);


/* bss used only by this unit */
typedef struct EndingCam {
    /* 0x00 */ Vec3f eye;
    /* 0x0C */ Vec3f at;
    /* 0x18 */ Vec3f up;
    /* 0x24 */ Vec3f unk24;
    /* 0x30 */ f32 unk30[2];
} EndingCam; /* size 0x38 */
extern EndingCam D_80110210_YoshisTropicalIslandEndingScene[2];

/* The scene's player-position table */
extern const Vec3f D_8010F5D4_YoshisTropicalIslandEndingScene[12];
#define ENDING_PLAYER_POS D_8010F5D4_YoshisTropicalIslandEndingScene

/* Scene model table: MBModelCreate(id, list) at pos */
typedef struct EndingModel {
    /* 0x00 */ s32 id;
    /* 0x04 */ s32* list;
    /* 0x08 */ Vec3f pos;
} EndingModel; /* size 0x14 */

/* func_80042728's result (42E40.c ModelEmitterWork; only its leading fields) */
typedef struct EndingEmitterWork {
    /* 0x00 */ Process* process;
    /* 0x04 */ Object* model;
} EndingEmitterWork;

/* D_80110300[1] read as a scalar: retail's codegen here keeps it cached across a struct-field
 * store (GCC's scalar-vs-struct alias rule), which an array element does not. The N64 build names
 * splat's label for the element; the host reads the element itself. */
extern omObjData* D_80110304_YoshisTropicalIslandEndingScene;
#define D_80110304_SCALAR D_80110304_YoshisTropicalIslandEndingScene
