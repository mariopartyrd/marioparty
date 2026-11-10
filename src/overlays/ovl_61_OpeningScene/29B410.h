#include "common.h"

void func_800FB670_OpeningScene(Vec3f*, Vec3f*, f32);
void func_800FB7F8_OpeningScene(f32, f32, f32);
void func_800FB810_OpeningScene(omObjData*);
extern s16 D_800C5972;
extern s16 D_800C59A6;
extern s8 omSysPauseEnableFlag;
extern Vec3f D_800FD4A0_OpeningScene;
extern Vec3f D_800FD4AC_OpeningScene;
extern Process* D_800FD730_OpeningScene[];
void func_800FB86C_OpeningScene(void);
void func_800FBD48_OpeningScene(Object* arg0, Vec3f* arg1, f32 arg2);
extern Object* D_80110448_OpeningScene[];
void func_800F6788_OpeningScene(omObjData*);
void func_800FC394_OpeningScene(s32);
void func_8004B1B8(void);
s32 func_8004E184(void);
void func_800FC724_OpeningScene(void);
s32 func_800FC528_OpeningScene(s32, s32, s32, s32);
extern s32 D_800FD700_OpeningScene;

extern f32 D_800FD794_OpeningScene;
/* ovl_61 fork c: prototypes and data used by func_800FB670..func_800FCECC */
extern s32 D_800FD738_OpeningScene;
extern u8 D_800C572F;
s32 func_800141FC(s16);
void HuPrcDestructorSet(void (*)(void));
void func_800F6AB8_OpeningScene(void);
void func_800F983C_OpeningScene(void);
void func_800F98F0_OpeningScene(void);
void func_800FA990_OpeningScene(void);
void func_800FAEFC_OpeningScene(void);
s32 func_800FBAC0_OpeningScene(void);
s32 func_800FBAFC_OpeningScene(void);
void func_800FB97C_OpeningScene(omObjData*);
void func_800FB91C_OpeningScene(void);
void func_800FB864_OpeningScene(void);
void func_800FBB94_OpeningScene(void);
void func_800FBC9C_OpeningScene(void);
void func_800FC48C_OpeningScene(f32, f32, f32);
void func_800FC4C0_OpeningScene(f32, f32, f32);
void func_800FC4F4_OpeningScene(f32, f32, f32);

typedef struct OpeningModel {
    /* 0x00 */ s16 model;
    /* 0x04 */ struct OpeningModel* self;
    /* 0x08 */ s16 model2;
    /* 0x0C */ s16* self2; // &model2 when a second model is loaded, else NULL
    /* 0x10 */ Vec3f posA;
    /* 0x1C */ Vec3f posB;
    /* 0x28 */ Vec3f posC;
} OpeningModel; // retail size 0x34 (pointers are 4 bytes there)

typedef struct OpeningSprite {
    /* 0x00 */ s16 group;
    /* 0x02 */ s16 sprite;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
} OpeningSprite;

extern s32 D_801102B8[16];
/* Fixed scratch RAM above the overlay (0x801102B8...0x80110464); retail also names
   D_80110300[15] D_8011033C and D_80110448[2] D_80110450. */
extern omObjData* D_80110300[16];
extern void* D_80110400[16];
extern Vec3f D_800FD520_OpeningScene;
extern const Vec3f D_800FD4DC_OpeningScene;
void func_800FBD7C_OpeningScene(void);
void func_8004FB14(void);
void func_8004E154(void);
void func_8004F548(void);
void func_800FC17C_OpeningScene(OpeningModel*, Vec3f*);
void func_800FC1F0_OpeningScene(OpeningModel*, Vec3f*);
void func_800FC264_OpeningScene(OpeningModel*, Vec3f*);
s16 func_800FBD98_OpeningScene(OpeningModel* arg0, s32 arg1, s32 unused, Vec3f* arg2, s32 arg3);
s32 func_800FBEA8_OpeningScene(OpeningModel* arg0);
void func_800FBEEC_OpeningScene(OpeningSprite* arg0, s32 arg1, u16 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void func_800FC0BC_OpeningScene(OpeningSprite* arg0);
void func_800FC0EC_OpeningScene(s16* arg0);
void func_800FC110_OpeningScene(s16* arg0);
void func_800FC134_OpeningScene(OpeningModel* arg0);
typedef struct OpeningSpriteInfo {
    /* 0x00 */ char unk_00[0x14];
    /* 0x14 */ u16 width;
    /* 0x16 */ u16 height;
} OpeningSpriteInfo;
typedef struct OpeningSpriteObj {
    /* 0x00 */ char unk_00[0x4C];
    /* 0x4C */ OpeningSpriteInfo* info;
} OpeningSpriteObj;
OpeningSpriteObj* func_800675F4(s16, s16);
f32 func_80022D9C(f32*, f32*, f32);
s16 func_8002451C(s32, void*, s32);
void func_800FC5CC_OpeningScene(void*, s32);
void func_800FC758_OpeningScene(void);
void func_800FCEE8_OpeningScene(f32);
void func_800FCECC_OpeningScene(u8, u8, u8, u8);
s16 func_800FCE9C_OpeningScene(void);
void func_800FCAB0_OpeningScene(omObjData*);
void func_800FCC3C_OpeningScene(omObjData*);
void func_800FCDCC_OpeningScene(Gfx**);
void func_800FC77C_OpeningScene(Vec3f*, f32*, f32, Vec3f*);
extern s16 D_800FD780_OpeningScene;
extern u8 D_800FD782_OpeningScene[4];
extern Gfx D_800FD450_OpeningScene[];

/* Camera vectors, contiguous in bss (0x800FD6D0, 6DC, 6E8, 6F4): eye, at, up, and the
   perspective parameters func_800FB7F8 sets. */
extern Vec3f D_800FD6D0_OpeningScene[4];
