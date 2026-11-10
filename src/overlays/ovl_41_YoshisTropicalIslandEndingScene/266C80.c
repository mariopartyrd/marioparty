#include "ending.h"
#include "PR/gu.h"

void func_8001ABA0(u16 size);
void func_80026018(s16 arg0, f32 arg1);
void func_8004B7F8(s32);
void func_8004FAB8(s32);
void func_80052DC8(s16, void*);
/* 2643A0.c's .rodata: the players' positions in the last scene */
extern Vec3f D_8010F114_YoshisTropicalIslandEndingScene[4];


extern const f64 D_8010F1A8_YoshisTropicalIslandEndingScene;
extern const f64 D_8010F1B0_YoshisTropicalIslandEndingScene;
extern const f64 D_8010F1B8_YoshisTropicalIslandEndingScene;
void func_80028C64(s16 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4);
void func_800FF364_YoshisTropicalIslandEndingScene(omObjData* arg0);
void func_800FF240_YoshisTropicalIslandEndingScene(omObjData* arg0);
void func_800FF59C_YoshisTropicalIslandEndingScene(void);
void func_800FFF5C_YoshisTropicalIslandEndingScene(unk2C0C0StructC0* arg0, f32 arg1, s16 arg2);
void func_8010024C_YoshisTropicalIslandEndingScene(void);
void func_80100268_YoshisTropicalIslandEndingScene(void);
void func_801005C0_YoshisTropicalIslandEndingScene(void);
void func_8010087C_YoshisTropicalIslandEndingScene(void);
void func_8010102C_YoshisTropicalIslandEndingScene(void);
void func_8010151C_YoshisTropicalIslandEndingScene(void);

/* A vertex position copied out of a display vertex */
typedef struct Unk266V3s {
    s16 x, y, z;
} Unk266V3s;


/* A model placed by the scenes (.data D_8010E5D4_YoshisTropicalIslandEndingScene/E698/E7B0: id, position, scale; id -1 ends a list) */
typedef struct Unk266Model {
    /* 0x00 */ s32 id;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ Vec3f scale;
} Unk266Model; /* sizeof 0x1C */

/* A board model to create (.data D_8010E830_YoshisTropicalIslandEndingScene..D_8010E8D8_YoshisTropicalIslandEndingScene) */
typedef struct Unk266Obj {
    /* 0x00 */ s32 model;
    /* 0x04 */ void* list;
    /* 0x08 */ Vec3f pos;
    /* 0x14 */ s32 dispOn;
} Unk266Obj; /* sizeof 0x18 (N64) */

/* This unit's functions (several are NON_MATCHING: their C is not seen by the N64 build) */
void func_800FD5F0_YoshisTropicalIslandEndingScene(void);
void func_800FD60C_YoshisTropicalIslandEndingScene(omObjData* arg0);
omObjData* func_800FDA0C_YoshisTropicalIslandEndingScene(f32 arg0, f32 arg1, f32 arg2);
void func_800FDACC_YoshisTropicalIslandEndingScene(s16 arg0);
omObjData* func_800FDF78_YoshisTropicalIslandEndingScene(s32 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_800FE310_YoshisTropicalIslandEndingScene(s32 arg0);
void func_800FE538_YoshisTropicalIslandEndingScene(omObjData* arg0);
omObjData* func_800FE730_YoshisTropicalIslandEndingScene(u8 arg0, f32 arg1, f32 arg2);
omObjData* func_800FE86C_YoshisTropicalIslandEndingScene(s32 arg0);
omObjData* func_800FE9B8_YoshisTropicalIslandEndingScene(s32 arg0, f32 arg1, f32 arg2);
s16 func_800FEB8C_YoshisTropicalIslandEndingScene(s32 arg0);
omObjData* func_800FEE24_YoshisTropicalIslandEndingScene(s32 arg0, s32 arg1, s32 arg2);
void func_800FEFE0_YoshisTropicalIslandEndingScene(s32 arg0);
omObjData* func_800FF1A0_YoshisTropicalIslandEndingScene(s32 arg0);
Object* func_800FF1E4_YoshisTropicalIslandEndingScene(Unk266Obj* arg0);
void func_800FFC08_YoshisTropicalIslandEndingScene(s32* arg0, s32* arg1);
void func_800FFE6C_YoshisTropicalIslandEndingScene(s32* arg0, s32* arg1);
void func_800FFEBC_YoshisTropicalIslandEndingScene(s32* arg0, s32* arg1);
void func_800FFF08_YoshisTropicalIslandEndingScene(s32* arg0, s32* arg1);

/* .data */
s32 D_8010E460_YoshisTropicalIslandEndingScene[3] = { 0x2, 0x10001, 0x10039 };
s32 D_8010E46C_YoshisTropicalIslandEndingScene[2] = { 0x1, 0x10049 };
s32 D_8010E474_YoshisTropicalIslandEndingScene[3] = { 0x2, 0x10001, 0x10097 };
s32 D_8010E480_YoshisTropicalIslandEndingScene[2] = { 0x1, 0x10028 };
s32 D_8010E488_YoshisTropicalIslandEndingScene[3] = { 0x2, 0x20001, 0x20039 };
s32 D_8010E494_YoshisTropicalIslandEndingScene[2] = { 0x1, 0x20049 };
s32 D_8010E49C_YoshisTropicalIslandEndingScene[3] = { 0x2, 0x20001, 0x20097 };
s32 D_8010E4A8_YoshisTropicalIslandEndingScene[2] = { 0x1, 0x20028 };
s32 D_8010E4B0_YoshisTropicalIslandEndingScene[3] = { 0x2, 0x60001, 0x60039 };
s32 D_8010E4BC_YoshisTropicalIslandEndingScene[2] = { 0x1, 0x60049 };
s32 D_8010E4C4_YoshisTropicalIslandEndingScene[3] = { 0x2, 0x60001, 0x60097 };
s32 D_8010E4D0_YoshisTropicalIslandEndingScene[2] = { 0x1, 0x60028 };
s32 D_8010E4D8_YoshisTropicalIslandEndingScene[3] = { 0x2, 0x30001, 0x30039 };
s32 D_8010E4E4_YoshisTropicalIslandEndingScene[2] = { 0x1, 0x30049 };
s32 D_8010E4EC_YoshisTropicalIslandEndingScene[3] = { 0x2, 0x30001, 0x30097 };
s32 D_8010E4F8_YoshisTropicalIslandEndingScene[2] = { 0x1, 0x30028 };
s32 D_8010E500_YoshisTropicalIslandEndingScene[3] = { 0x2, 0x40001, 0x40039 };
s32 D_8010E50C_YoshisTropicalIslandEndingScene[2] = { 0x1, 0x40049 };
s32 D_8010E514_YoshisTropicalIslandEndingScene[3] = { 0x2, 0x40001, 0x40097 };
s32 D_8010E520_YoshisTropicalIslandEndingScene[2] = { 0x1, 0x40028 };
s32 D_8010E528_YoshisTropicalIslandEndingScene[3] = { 0x2, 0x50001, 0x50039 };
s32 D_8010E534_YoshisTropicalIslandEndingScene[2] = { 0x1, 0x50049 };
s32 D_8010E53C_YoshisTropicalIslandEndingScene[3] = { 0x2, 0x50001, 0x50097 };
s32 D_8010E548_YoshisTropicalIslandEndingScene[2] = { 0x1, 0x50028 };
s32* D_8010E550_YoshisTropicalIslandEndingScene[6] = { D_8010E460_YoshisTropicalIslandEndingScene, D_8010E488_YoshisTropicalIslandEndingScene, D_8010E4B0_YoshisTropicalIslandEndingScene, D_8010E4D8_YoshisTropicalIslandEndingScene, D_8010E500_YoshisTropicalIslandEndingScene, D_8010E528_YoshisTropicalIslandEndingScene };
s32* D_8010E568_YoshisTropicalIslandEndingScene[6] = { D_8010E46C_YoshisTropicalIslandEndingScene, D_8010E494_YoshisTropicalIslandEndingScene, D_8010E4BC_YoshisTropicalIslandEndingScene, D_8010E4E4_YoshisTropicalIslandEndingScene, D_8010E50C_YoshisTropicalIslandEndingScene, D_8010E534_YoshisTropicalIslandEndingScene };
s32* D_8010E580_YoshisTropicalIslandEndingScene[6] = { D_8010E474_YoshisTropicalIslandEndingScene, D_8010E49C_YoshisTropicalIslandEndingScene, D_8010E4C4_YoshisTropicalIslandEndingScene, D_8010E4EC_YoshisTropicalIslandEndingScene, D_8010E514_YoshisTropicalIslandEndingScene, D_8010E53C_YoshisTropicalIslandEndingScene };
s32* D_8010E598_YoshisTropicalIslandEndingScene[6] = { D_8010E480_YoshisTropicalIslandEndingScene, D_8010E4A8_YoshisTropicalIslandEndingScene, D_8010E4D0_YoshisTropicalIslandEndingScene, D_8010E4F8_YoshisTropicalIslandEndingScene, D_8010E520_YoshisTropicalIslandEndingScene, D_8010E548_YoshisTropicalIslandEndingScene };
s32 D_8010E5B0_YoshisTropicalIslandEndingScene[7] = { 0x6, 0xA0068, 0xA0069, 0xA006A, 0xA006B, 0xA006C, 0xA006D };
s32 D_8010E5CC_YoshisTropicalIslandEndingScene[2] = { 0x1, 0xA0073 };
Unk266Model D_8010E5D4_YoshisTropicalIslandEndingScene[7] = {
    { 0xA014A, { 0.0f, 2000.0f, 400.0f }, { 1.2f, 1.2f, 1.2f } },
    { 0xA014C, { -400.0f, 1000.0f, 400.0f }, { 1.2f, 1.2f, 1.2f } },
    { 0xA014A, { 400.0f, 1200.0f, 400.0f }, { 1.2f, 1.2f, 1.2f } },
    { 0xA014C, { 0.0f, 500.0f, 400.0f }, { 1.2f, 1.2f, 1.2f } },
    { 0xA014A, { -750.0f, 1500.0f, 400.0f }, { 1.2f, 1.2f, 1.2f } },
    { 0xA014C, { 750.0f, 1000.0f, 400.0f }, { 1.2f, 1.2f, 1.2f } },
    { -1, { 0.0f, 0.0f, 0.0f }, { 0.001f, 0.001f, 0.001f } },
};
Unk266Model D_8010E698_YoshisTropicalIslandEndingScene[10] = {
    { 0xA014C, { 350.0f, 450.0f, 1160.0f }, { 0.6f, 0.6f, 0.6f } },
    { 0xA014C, { -350.0f, 450.0f, 1160.0f }, { 0.6f, 0.6f, 0.6f } },
    { 0xA014C, { 0.0f, 620.0f, 1135.0f }, { 0.6f, 0.6f, 0.6f } },
    { 0xA014C, { 0.0f, 450.0f, 11600.0f }, { 0.6f, 0.6f, 0.6f } },
    { 0xA00D6, { 350.0f, 450.0f, 1160.0f }, { 0.6f, 0.6f, 0.6f } },
    { 0xA0068, { 350.0f, 450.0f, 1160.0f }, { 0.6f, 0.6f, 0.6f } },
    { 0x49, { -350.0f, 450.0f, 1160.0f }, { 0.6f, 0.6f, 0.6f } },
    { 0xA00D6, { 0.0f, 620.0f, 1135.0f }, { 0.6f, 0.6f, 0.6f } },
    { 0xA00C1, { 0.0f, 450.0f, 11600.0f }, { 0.6f, 0.6f, 0.6f } },
    { -1, { 0.0f, 0.0f, 0.0f }, { 0.001f, 0.001f, 0.001f } },
};
Unk266Model D_8010E7B0_YoshisTropicalIslandEndingScene[4] = {
    { 0xA014C, { 350.0f, 300.0f, 1160.0f }, { 0.4f, 0.4f, 0.4f } },
    { 0xA014C, { -350.0f, 300.0f, 1160.0f }, { 0.4f, 0.4f, 0.4f } },
    { 0xA014C, { 0.0f, 620.0f, 1135.0f }, { 0.4f, 0.4f, 0.4f } },
    { -1, { 0.0f, 0.0f, 0.0f }, { 0.001f, 0.001f, 0.001f } },
};
Unk266Model* D_8010E820_YoshisTropicalIslandEndingScene[3] = { D_8010E5D4_YoshisTropicalIslandEndingScene, D_8010E698_YoshisTropicalIslandEndingScene, D_8010E7B0_YoshisTropicalIslandEndingScene };
s32 D_8010E82C_YoshisTropicalIslandEndingScene = 0xA;
Unk266Obj D_8010E830_YoshisTropicalIslandEndingScene[8] = {
    { 0x40, NULL, { 0.0f, 810.0f, 1210.0f }, 0x1 },
    { 0x32, NULL, { -100.0f, 0.0f, 1237.5f }, 0x0 },
    { 0x7, NULL, { -142.5f, 0.0f, 1485.0f }, 0x1 },
    { 0x8, D_8010E5CC_YoshisTropicalIslandEndingScene, { -345.0f, 0.0f, 1532.5f }, 0x1 },
    { 0x10, NULL, { -150.0f, 130.0f, 1410.0f }, 0x1 },
    { 0xE, NULL, { 135.0f, 0.0f, 1610.0f }, 0x1 },
    { 0xF, NULL, { -240.0f, 0.0f, 1485.0f }, 0x1 },
    { 0x6D, NULL, { 262.5f, 210.0f, 1085.0f }, 0x0 },
};
extern const f64 D_8010F198_YoshisTropicalIslandEndingScene;
extern const f64 D_8010F1A0_YoshisTropicalIslandEndingScene;
extern 
void func_800FEC20_YoshisTropicalIslandEndingScene(omObjData* arg0);
void func_800FF048_YoshisTropicalIslandEndingScene(omObjData* arg0);


void func_800FE5A4_YoshisTropicalIslandEndingScene(omObjData* arg0);
void func_800FE658_YoshisTropicalIslandEndingScene(omObjData* arg0);
void func_800FE7C8_YoshisTropicalIslandEndingScene(omObjData* arg0);
void func_800FE900_YoshisTropicalIslandEndingScene(omObjData* arg0);
void func_800FEA50_YoshisTropicalIslandEndingScene(omObjData* arg0);
void func_800FEAA0_YoshisTropicalIslandEndingScene(omObjData* arg0);
void func_801001D0_YoshisTropicalIslandEndingScene(s16 arg0, f32 arg1, char* arg2);


/* One sprite of the sparkle effect (bss D_8010F880_YoshisTropicalIslandEndingScene: 16 records, then the large one at [16]) */
typedef struct Unk266Spr {
    /* 0x00 */ s16 id;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ Vec3f rot;
    /* 0x1C */ Vec3f scale;
    /* 0x28 */ f32 t;
    /* 0x2C */ char unk_2C[0xC];
    /* 0x38 */ s32 timer;
    /* 0x3C */ char unk_3C[0xC];
} Unk266Spr; /* sizeof 0x48 */

extern Unk266Spr D_8010F880_YoshisTropicalIslandEndingScene[17];
extern s32 D_8010F870_YoshisTropicalIslandEndingScene;
extern s32 D_8010F874_YoshisTropicalIslandEndingScene;
extern s32 D_8010F878_YoshisTropicalIslandEndingScene;

void func_801022E8_YoshisTropicalIslandEndingScene(void);
void func_800FD918_YoshisTropicalIslandEndingScene(omObjData* arg0);
void func_800FDB24_YoshisTropicalIslandEndingScene(omObjData* arg0);
void func_800ACE70(Matrix4f mf, Vec3f* src, Vec3f* dest);
void func_8001E3B4(s16);
void func_8002019C(s32);
void func_800A1250(Vec3f*);


/* Double constants are named objects: KMC as gives .rodata 16-byte alignment for li.d literals */
extern const f64 D_8010F160_YoshisTropicalIslandEndingScene;
extern const f64 D_8010F168_YoshisTropicalIslandEndingScene;
extern const f64 D_8010F170_YoshisTropicalIslandEndingScene;
extern const f64 D_8010F178_YoshisTropicalIslandEndingScene;


void func_800FD5F0_YoshisTropicalIslandEndingScene(void) {
    func_801022E8_YoshisTropicalIslandEndingScene();
}
void func_800FD60C_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    Vec3f sp10;
    Matrix4f sp20;

    switch (arg0->work[0]) {
    case 0:
    case 1:
        arg0->rot.x += 5.0f;
        if (arg0->rot.x >= 360.0f) {
            if (arg0->work[0] == 1) {
                arg0->work[0] = 2;
            }
            arg0->rot.x -= 360.0f;
        }
        D_80110448_YoshisTropicalIslandEndingScene[0]->coords.x = (sinf(arg0->rot.x * D_8010F160_YoshisTropicalIslandEndingScene) * 70.0f * 5.0f) + arg0->trans.x;
        D_80110448_YoshisTropicalIslandEndingScene[0]->coords.y = arg0->trans.y;
        D_80110448_YoshisTropicalIslandEndingScene[0]->coords.z = (arg0->trans.z - 30.0f) + (cosf(arg0->rot.x * D_8010F160_YoshisTropicalIslandEndingScene) * 30.0f * 5.0f);
        break;
    case 2:
        arg0->rot.x += 5.0f;
        if (arg0->rot.x >= 360.0f) {
            arg0->rot.x -= 360.0f;
        }
        D_80110448_YoshisTropicalIslandEndingScene[0]->unk_3C->unk_24 = 90.0f;
        D_80110448_YoshisTropicalIslandEndingScene[0]->unk_3C->unk28 = 0.0f;
        D_80110448_YoshisTropicalIslandEndingScene[0]->unk_3C->unk_2C = sinf(arg0->rot.x * D_8010F168_YoshisTropicalIslandEndingScene) * 10.0f;
        break;
    case 3:
        D_80110448_YoshisTropicalIslandEndingScene[0]->coords.x -= 10.0f;
        D_80110448_YoshisTropicalIslandEndingScene[0]->coords.y -= 10.0f;
        if (D_80110448_YoshisTropicalIslandEndingScene[0]->coords.x < -75.0f || D_80110448_YoshisTropicalIslandEndingScene[0]->coords.y < 100.0f) {
            D_80110300_YoshisTropicalIslandEndingScene[0]->work[0] = 4;
        }
    case 4:
        func_800A40D0(sp20, 5.0f);
        func_800ACE70(sp20, &D_80110448_YoshisTropicalIslandEndingScene[0]->unk_18, &sp10);
        func_800A1250(&sp10);
        D_80110448_YoshisTropicalIslandEndingScene[0]->unk_18.x = sp10.x;
        D_80110448_YoshisTropicalIslandEndingScene[0]->unk_18.y = sp10.y;
        D_80110448_YoshisTropicalIslandEndingScene[0]->unk_18.z = sp10.z;
        break;
    }
}
const f64 D_8010F160_YoshisTropicalIslandEndingScene = 0.017453292519943295;
const f64 D_8010F168_YoshisTropicalIslandEndingScene = 0.017453292519943295;

void func_800FD918_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    f32 t = arg0->rot.x;

    if (!(t > 1.0f)) {
        t += 0.1f;
        func_8004FA90(D_80110440_YoshisTropicalIslandEndingScene, 2.3f - (t * 0.4f), 2.3f - (t * 0.4f), 2.3f - (t * 0.4f));
        func_8004F9F4(D_80110440_YoshisTropicalIslandEndingScene, (t * 20.0f * 5.0f) + arg0->trans.x, (t * 20.0f * 5.0f) + arg0->trans.y, arg0->trans.z, 1);
        arg0->rot.x = t;
    }
}
omObjData* func_800FDA0C_YoshisTropicalIslandEndingScene(f32 arg0, f32 arg1, f32 arg2) {
    omObjData* obj;

    obj = omAddObj(0x1000, 0, 0, -1, &func_800FD918_YoshisTropicalIslandEndingScene);
    omSetRot(obj, 0.0f, 0.0f, 0.0f);
    omSetTra(obj, arg0, arg1, arg2);
    obj->work[0] = 0;
    D_80110440_YoshisTropicalIslandEndingScene = func_8004F954(0x26, 8);
    func_8004FA90(D_80110440_YoshisTropicalIslandEndingScene, 5.0f, 5.0f, 5.0f);
    return obj;
}
void func_800FDACC_YoshisTropicalIslandEndingScene(s16 arg0) {
    unk_800ECDE0* e = &D_800ECDE0[arg0];

    e->unk_0A = 0;
    e->unk_04 = 0;
    e->unk_10 &= 0xFF7F;
    func_800258EC(e->unk_00, 4, 4);
}
// s->id reload in the loop and the base register of the last record (masked 8)
#ifdef NON_MATCHING
void func_800FDB24_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    Unk266Spr* s;
    Unk266Spr* b;
    u16 id;
    f32 t;
    f32 sc;
    s32 i;

    if (arg0->work[0] != 0) {
        if (arg0->work[1] != 0) {
            arg0->work[1]--;
        } else {
            arg0->work[1] = 1;
            arg0->work[0]--;
            s = &D_8010F880_YoshisTropicalIslandEndingScene[arg0->work[0]];
            func_800A0D00(&s->pos, s->pos.x, s->pos.y, s->pos.z);
            func_800A0D00(&s->scale, s->scale.x, s->scale.y, s->scale.z);
            func_800A0D00(&s->rot, s->rot.x, s->rot.y, s->rot.z);
            s->t = 0.1f;
            s->pos.x += arg0->scale.x;
            s->pos.y += arg0->scale.y;
            s->pos.z += arg0->scale.z;
        }
    }
    for (i = 0; i < arg0->work[2]; i++) {
        s = &D_8010F880_YoshisTropicalIslandEndingScene[i];
        id = D_800ECDE0[s->id].unk_00;
        t = s->t;
        if (!(t > 1.0f)) {
            func_8001E2F8(s->id, (0.601f - (t * 0.6f)) * 255.0f);
            sc = ((t * 0.6f) + 0.4f) * arg0->rot.x;
            func_80025830(id, sc, sc, sc);
            func_80025798(id, s->pos.x, s->pos.y, s->pos.z);
            t += 0.05f;
            if (t > 1.0f) {
                func_800FDACC_YoshisTropicalIslandEndingScene(s->id);
            }
            s->t = t;
        }
    }
    b = D_8010F880_YoshisTropicalIslandEndingScene;
    s = &b[16];
    id = D_800ECDE0[b[16].id].unk_00;
    t = b[16].t;
    func_8001E2F8(s->id, (1.0f - func_800B1750(t)) * 255.0f);
    {
        f32 k = 1.01f - func_800B1750(t);
        func_80025830(id, s->scale.x * (k * D_8010F170_YoshisTropicalIslandEndingScene + D_8010F178_YoshisTropicalIslandEndingScene), k * s->scale.y, s->scale.z);
    }
    func_80025798(id, s->pos.x, s->pos.y, s->pos.z);
    func_800257E4(id, s->rot.x, s->rot.y, s->rot.z);
    if (s->timer != 0) {
        if (--s->timer == 0) {
            func_8001E3B4(s->id);
        }
    }
    if (t > 1.0f) {
        t = 1.0f;
        func_800FDACC_YoshisTropicalIslandEndingScene(s->id);
    }
    s->t = t + 0.05f;
}
const f64 D_8010F170_YoshisTropicalIslandEndingScene = 0.4;
const f64 D_8010F178_YoshisTropicalIslandEndingScene = 0.6f;
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/266C80", func_800FDB24_YoshisTropicalIslandEndingScene);
#endif

// D_800ECDE0 load scheduled before the index scaling in the loop (masked 4)
#ifdef NON_MATCHING
omObjData* func_800FDF78_YoshisTropicalIslandEndingScene(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    omObjData* obj;
    u16 id;
    s32 i;
    s32 j;

    obj = omAddObj(0x1000, 0, 0, -1, &func_800FDB24_YoshisTropicalIslandEndingScene);
    obj->work[2] = obj->work[0] = arg0;
    obj->work[1] = 0;
    omSetRot(obj, 16.0f, 0.01f, 0.0f);
    omSetTra(obj, arg1 + 35.0f, arg2 + 35.0f, arg3 + 200.0f);
    omSetSca(obj, 0.099999994f, 0.099999994f, 0.0f);
    for (i = 0; i < arg0; i++) {
        id = D_800ECDE0[D_8010F880_YoshisTropicalIslandEndingScene[i].id].unk_00;
        func_8001E3B4(D_8010F880_YoshisTropicalIslandEndingScene[i].id);
        func_8001E2F8(D_8010F880_YoshisTropicalIslandEndingScene[i].id, 0);
        func_800A0D00(&D_8010F880_YoshisTropicalIslandEndingScene[i].pos, arg1 + 35.0f, arg2 + 35.0f, arg3 + 200.0f);
        func_800A0D00(&D_8010F880_YoshisTropicalIslandEndingScene[i].scale, 10.0f, 10.0f, 10.0f);
        func_800A0D00(&D_8010F880_YoshisTropicalIslandEndingScene[i].rot, 0.0f, 0.0f, 0.0f);
        func_80025830(id, D_8010F880_YoshisTropicalIslandEndingScene[i].scale.x, D_8010F880_YoshisTropicalIslandEndingScene[i].scale.y, D_8010F880_YoshisTropicalIslandEndingScene[i].scale.z);
        func_800257E4(id, D_8010F880_YoshisTropicalIslandEndingScene[i].rot.x, D_8010F880_YoshisTropicalIslandEndingScene[i].rot.y, D_8010F880_YoshisTropicalIslandEndingScene[i].rot.z);
        func_80025798(id, D_8010F880_YoshisTropicalIslandEndingScene[i].pos.x, D_8010F880_YoshisTropicalIslandEndingScene[i].pos.y, D_8010F880_YoshisTropicalIslandEndingScene[i].pos.z);
    }
    j = 16;
    id = D_800ECDE0[D_8010F880_YoshisTropicalIslandEndingScene[j].id].unk_00;
    func_800A0D00(&D_8010F880_YoshisTropicalIslandEndingScene[j].pos, arg1, arg2, arg3);
    func_800A0D00(&D_8010F880_YoshisTropicalIslandEndingScene[j].scale, 5.0f, 5.0f, 5.0f);
    func_800A0D00(&D_8010F880_YoshisTropicalIslandEndingScene[j].rot, 0.0f, 0.0f, -45.0f);
    func_8001E2F8(D_8010F880_YoshisTropicalIslandEndingScene[j].id, 0xFF);
    func_80025830(id, D_8010F880_YoshisTropicalIslandEndingScene[j].scale.x, D_8010F880_YoshisTropicalIslandEndingScene[j].scale.y, D_8010F880_YoshisTropicalIslandEndingScene[j].scale.z);
    func_800257E4(id, D_8010F880_YoshisTropicalIslandEndingScene[j].rot.x, D_8010F880_YoshisTropicalIslandEndingScene[j].rot.y, D_8010F880_YoshisTropicalIslandEndingScene[j].rot.z);
    func_80025798(id, D_8010F880_YoshisTropicalIslandEndingScene[j].pos.x, D_8010F880_YoshisTropicalIslandEndingScene[j].pos.y, D_8010F880_YoshisTropicalIslandEndingScene[j].pos.z);
    D_8010F880_YoshisTropicalIslandEndingScene[j].t = 0.0f;
    D_8010F880_YoshisTropicalIslandEndingScene[j].timer = 4;
    return obj;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/266C80", func_800FDF78_YoshisTropicalIslandEndingScene);
#endif
void func_800FE310_YoshisTropicalIslandEndingScene(s32 arg0) {
    void* file;
    s16 sprite;
    s16 id;
    u16 id2;
    s32 i;

    file = DataRead(0xA0152);
    for (i = 0; i < arg0; i++) {
        sprite = func_8001E00C(file, 0xA80, 8);
        func_800FDACC_YoshisTropicalIslandEndingScene(sprite);
        id = D_800ECDE0[sprite].unk_00;
        func_80025798(id, 0.0f, 0.0f, 0.0f);
        func_80025830(id, 0.01f, 0.01f, 0.01f);
        func_800257E4(id, 0.0f, 0.0f, 0.0f);
        D_8010F880_YoshisTropicalIslandEndingScene[i].id = sprite;
    }
    DataClose(file);
    file = DataRead(0xA014F);
    sprite = func_8001E00C(file, 0xA80, 8);
    func_800FDACC_YoshisTropicalIslandEndingScene(sprite);
    id2 = D_800ECDE0[sprite].unk_00;
    func_800A0D00(&D_8010F880_YoshisTropicalIslandEndingScene[16].pos, 0.0f, 0.0f, 0.0f);
    func_800A0D00(&D_8010F880_YoshisTropicalIslandEndingScene[16].scale, 7.0f, 7.0f, 7.0f);
    func_800A0D00(&D_8010F880_YoshisTropicalIslandEndingScene[16].rot, 0.0f, 0.0f, -45.0f);
    func_80025798(id2, -25.0f, 275.0f, 1075.0f);
    func_80025830(id2, 0.01f, 0.01f, 0.01f);
    func_800257E4(id2, 0.0f, 0.0f, -45.0f);
    D_8010F880_YoshisTropicalIslandEndingScene[16].id = sprite;
    DataClose(file);
}
void func_800FE538_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    s32 count = arg0->work[2];
    s32 i;

    omDelObj(arg0);
    for (i = 0; i < count; i++) {
        func_8002019C(D_8010F880_YoshisTropicalIslandEndingScene[i].id);
    }
    func_8002019C(D_8010F880_YoshisTropicalIslandEndingScene[16].id);
}
void func_800FE5A4_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    f32 t = arg0->trans.x;

    if (t > 1.0f) {
        t -= 1.0f;
    }
    func_801001D0_YoshisTropicalIslandEndingScene(*D_80110448_YoshisTropicalIslandEndingScene[arg0->work[0]]->unk_3C->unk_40, t, "wario_b5-grid6_5_2");
    t += 0.02f;
    if (t > 1.0f) {
        t -= 1.0f;
    }
    arg0->trans.x = t;
}
// decomp-permuter
void func_800FE658_YoshisTropicalIslandEndingScene(omObjData *arg0)
{
  s32 idx = arg0->work[0];
  f32 t = arg0->rot.x;
  Object **new_var;
  f32 y;
  Object **p;
  y = (func_800AEAC0(t * 360.0f) * 4.0f) * 5.0f;
  new_var = D_80110448_YoshisTropicalIslandEndingScene;
  p = new_var;
  p += idx;
  (*p)->coords.y = arg0->rot.z;
  (*p)->unk_30 = (y + arg0->rot.y) - arg0->rot.z;
  t += 0.01f;
  if (t > 1.0f)
  {
    t -= 1.0f;
  }
  arg0->rot.x = t;
}
omObjData* func_800FE730_YoshisTropicalIslandEndingScene(u8 arg0, f32 arg1, f32 arg2) {
    omObjData* obj;

    obj = omAddObj(0x800, 0, 0, -1, &func_800FE658_YoshisTropicalIslandEndingScene);
    obj->work[0] = arg0;
    omSetRot(obj, 0.0f, arg1, arg2);
    omSetTra(obj, 0.0f, 0.0f, 0.0f);
    return obj;
}
void func_800FE7C8_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    u8 idx = arg0->work[0];
    f32 t = arg0->rot.x;
    f32 y;

    t += 5.0f;
    if (t < 360.0f) {
        t -= 360.0f;
    }
    y = -func_800AEAC0(t);
    D_80110448_YoshisTropicalIslandEndingScene[idx]->unk_30 = y * 5.0f * 5.0f;
    arg0->rot.x = t;
}
omObjData* func_800FE86C_YoshisTropicalIslandEndingScene(s32 arg0) {
    Object* model = D_80110448_YoshisTropicalIslandEndingScene[arg0];
    omObjData* obj;

    obj = omAddObj(0x600, 0, 0, -1, &func_800FE7C8_YoshisTropicalIslandEndingScene);
    obj->work[0] = arg0;
    omSetRot(obj, 0.0f, 0.0f, 0.0f);
    omSetSca(obj, model->coords.x, model->coords.y, model->coords.z);
    return obj;
}
// decomp-permuter
void func_800FE900_YoshisTropicalIslandEndingScene(omObjData *arg0)
{
  s32 idx = arg0->work[0];
  f32 t = arg0->rot.x;
  f32 y;
  f32 new_var;
  Object **p;
  t += 5.0f;
  if (t < 360.0f)
  {
    t -= 360.0f;
  }
  y = func_800AEAC0(t) * 25.0f;
  p = D_80110448_YoshisTropicalIslandEndingScene;
  ;
  (*(p + idx))->coords.y = arg0->rot.z;
  new_var = y;
  (*(p + idx))->unk_30 = (new_var + arg0->rot.y) - arg0->rot.z;
  arg0->rot.x = t;
}
omObjData* func_800FE9B8_YoshisTropicalIslandEndingScene(s32 arg0, f32 arg1, f32 arg2) {
    omObjData* obj;

    obj = omAddObj(0x600, 0, 0, -1, &func_800FE900_YoshisTropicalIslandEndingScene);
    obj->work[0] = arg0;
    omSetRot(obj, 0.0f, arg1, arg2);
    omSetTra(obj, 0.0f, 0.0f, 0.0f);
    return obj;
}
void func_800FEA50_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    Object* model = D_80110448_YoshisTropicalIslandEndingScene[arg0->work[0]];

    if (model->unk_30 == 0.0f) {
        model->unk_30 = model->unk_34 = model->unk_38 = 0.0f;
        arg0->func_ptr = &func_800FEAA0_YoshisTropicalIslandEndingScene;
    }
}
// decomp-permuter
void func_800FEAA0_YoshisTropicalIslandEndingScene(omObjData *arg0)
{
  f32 new_var;
  Object **new_var2;
  u8 idx = arg0->work[0];
  f32 t = arg0->trans.x;
  new_var = t;
  if (new_var > 1.0f)
  {
    Object **p;
    arg0->func_ptr = &func_800FEA50_YoshisTropicalIslandEndingScene;
    arg0->trans.x = (arg0->trans.y = (arg0->trans.z = (arg0->rot.x = (arg0->rot.y = (arg0->rot.z = 0.0f)))));
    new_var2 = D_80110448_YoshisTropicalIslandEndingScene;
    p = new_var2;
    p += idx;
    (*p)->unk_30 = ((*p)->unk_38 = -1.5f);
    (*p)->unk_34 = 20.0f;
    t = 0.0f;
  }
  t += (rand8() & 0xFF) * 0.000039215687f;
  arg0->trans.x = t;
}
s16 func_800FEB8C_YoshisTropicalIslandEndingScene(s32 arg0) {
    s16 id;

    id = LoadFormFile(arg0, 0x6AD);
    func_80025930(id, 0x22000, 0x20000);
    func_80025AD4(id);
    func_80026040(id);
    func_80025798(id, 0.0f, 0.0f, 0.0f);
    func_80025830(id, 0.001f, 0.001f, 0.001f);
    func_800257E4(id, 0.0f, 0.0f, 0.0f);
    return id;
}
// load order of work[3] and the model-id pointer (masked 2)
#ifdef NON_MATCHING
void func_800FEC20_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    u8 idx = arg0->work[0];
    u8 k = arg0->work[2];
    u8 j = arg0->work[3];
    Unk266Model* tbl = D_8010E820_YoshisTropicalIslandEndingScene[k];
    Vec3f* pos = &tbl[j].pos;
    Vec3f* scale = &tbl[j].scale;
    s32* m;
    f32 y;

    D_800C34A4 = arg0->rot.x;
    if (arg0->rot.y > 1.0f) {
        func_800258EC((s16)D_801102B8_YoshisTropicalIslandEndingScene[idx], 4, 4);
        arg0->work[1] = 0;
        omSetRot(arg0, 79.0f, 0.29f, 1.0f);
        return;
    }
    func_80026B8C((s16)D_801102B8_YoshisTropicalIslandEndingScene[idx], arg0->rot.y, arg0->rot.z, 2);
    arg0->rot.x = arg0->rot.x + 23.0f;
    if (arg0->rot.x > 360.0f) {
        arg0->rot.x -= 360.0f;
    }
    arg0->rot.y += 0.0125f;
    arg0->rot.z = ((10.0f - arg0->rot.z) / 67.0f) + arg0->rot.z;
    y = arg0->rot.y * arg0->rot.y * 30.0f * 5.0f;
    m = D_801102B8_YoshisTropicalIslandEndingScene;
    m += idx;
    func_80025798((s16)*m, pos->x, pos->y - y, pos->z);
    func_80025830((s16)*m, scale->x, scale->y, scale->z);
    func_800257E4((s16)*m, 0.0f, 0.0f, 0.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/266C80", func_800FEC20_YoshisTropicalIslandEndingScene);
#endif
// decomp-permuter
omObjData *func_800FEE24_YoshisTropicalIslandEndingScene(s32 arg0, s32 arg1, s32 arg2)
{
  s32 *new_var;
  s32 *m;
  u16 id;
  Unk266Model *tbl;
  omObjData *obj;
  Vec3f *pos;
  Vec3f *scale;
  new_var = D_801102B8_YoshisTropicalIslandEndingScene;
  m = new_var;
  m += arg0;
  id = *m;
  tbl = D_8010E820_YoshisTropicalIslandEndingScene[arg1];
  obj = omAddObj(0x800, 0, 0, -1, &func_800FEC20_YoshisTropicalIslandEndingScene);
  obj->work[0] = arg0;
  obj->work[1] = 1;
  obj->work[2] = arg1;
  obj->work[3] = arg2;
  func_800258EC(id, 4, 0);
  func_80025EB4(id, 2, 2);
  func_80025F10(id, 1);
  pos = &tbl[arg2].pos;
  scale = &tbl[arg2].scale;
  func_80025798(id, pos->x, pos->y, pos->z);
  func_80025830(id, scale->x, scale->y, scale->z);
  func_800257E4(id, 0.0f, 0.0f, 0.0f);
  omSetTra(obj, 0.0f, 0.0f, 1.0f);
  omSetSca(obj, 0.0f, 0.0f, 1.0f);
  omSetRot(obj, 0.0f, 0.0f, 1.0f);
  func_80025798((s16) (*m), pos->x, pos->y, pos->z);
  func_80025830((s16) (*m), scale->x, scale->y, scale->z);
  func_800257E4((s16) (*m), 0.0f, 0.0f, 0.0f);
  return obj;
}
// scheduling: both index shifts are emitted before their base `lui/addiu` (raw 4, masked 4);
// `base; base += i`, `base + i` and fully indexed spellings tried
#ifdef NON_MATCHING
void func_800FEFE0_YoshisTropicalIslandEndingScene(s32 arg0) {
    omObjData** o;
    s32* m;

    o = &D_80110300_YoshisTropicalIslandEndingScene[arg0];
    m = &D_801102B8_YoshisTropicalIslandEndingScene[(*o)->work[0]];
    func_8002456C((s16)*m);
    *m = -1;
    omDelObj(*o);
    *o = NULL;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/266C80", func_800FEFE0_YoshisTropicalIslandEndingScene);
#endif
void func_800FF048_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    omObjData* o = D_80110300_YoshisTropicalIslandEndingScene[arg0->work[0]];
    s32 id = D_801102B8_YoshisTropicalIslandEndingScene[o->work[0]];
    u8 k = o->work[2];
    Unk266Model* tbl;
    s32 i;

    if (o->work[1] == 0) {
        if (D_8010F878_YoshisTropicalIslandEndingScene != 0) {
            PlaySound(D_8010F870_YoshisTropicalIslandEndingScene != 0 ? 0x62 : 0x64);
            D_8010F870_YoshisTropicalIslandEndingScene = ~D_8010F870_YoshisTropicalIslandEndingScene;
        }
        o->work[1] = 1;
        func_800258EC((s16)id, 4, 0);
        omSetRot(o, 79.0f, 0.29f, 1.0f);
        tbl = D_8010E820_YoshisTropicalIslandEndingScene[k];
        i = 0;
        while (tbl[i].id != -1) {
            i++;
        }
        o->work[3] = ((i - 1) * (rand8() & 0xFF)) / 255;
    }
}
omObjData* func_800FF1A0_YoshisTropicalIslandEndingScene(s32 arg0) {
    omObjData* obj = omAddObj(0x800, 0, 0, -1, &func_800FF048_YoshisTropicalIslandEndingScene);

    obj->work[0] = arg0;
    return obj;
}
Object* func_800FF1E4_YoshisTropicalIslandEndingScene(Unk266Obj* arg0) {
    Object* m = MBModelCreate(arg0->model, arg0->list);

    if (arg0->dispOn != 0) {
        func_8003E174(m);
    }
    func_800A0D50(&m->coords, &arg0->pos);
    return m;
}
void func_800FF240_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    f32 t;
    f32 k;

    arg0->rot.x += 5.0f;
    t = arg0->rot.z;
    if (t > 1.0f) {
        t = 1.0f;
        arg0->work[1] = 0;
    }
    k = (1.0f - t) * 0.2f;
    if (arg0->rot.x >= 360.0f) {
        arg0->rot.x -= 360.0f;
    }
    D_80110448_YoshisTropicalIslandEndingScene[0]->unk_18.x = k * sinf(arg0->rot.x * D_8010F198_YoshisTropicalIslandEndingScene);
    D_80110448_YoshisTropicalIslandEndingScene[0]->unk_18.z = 1.0f;
    t += 0.005f;
    arg0->rot.z = t;
}
const f64 D_8010F198_YoshisTropicalIslandEndingScene __attribute__((section(".rodata"))) = 0.017453292519943295;

// loop-invariant D_80110448 base not hoisted, model address order (masked ~18)
#ifdef NON_MATCHING
void func_800FF364_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    s32 n = D_8010DC90_YoshisTropicalIslandEndingScene[GwSystem.unk_00];
    s32 i;
    f32 a;
    f32 x;
    f32 z;
    Object** p;

    for (i = 0; i < arg0->trans.y; i++) {
        a = (360 / n) * i;
        x = (sinf((a + arg0->rot.y) * D_8010F1A0_YoshisTropicalIslandEndingScene) * arg0->trans.x) + D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].x;
        z = (cosf((a + arg0->rot.y) * D_8010F1A0_YoshisTropicalIslandEndingScene) * arg0->trans.x) + D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].z;
        p = D_80110448_YoshisTropicalIslandEndingScene;
        p += i;
        func_800A0D00(&(*p)->coords, x, D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].y, z);
        func_800A0D00((Vec3f*)&(*p)->xScale, arg0->scale.x, arg0->scale.x, arg0->scale.x);
    }
    arg0->rot.y -= 2.0f;
    if (arg0->rot.y <= 0.0f) {
        arg0->rot.y += 360.0f;
    }
    arg0->work[0]++;
}
const f64 D_8010F1A0_YoshisTropicalIslandEndingScene = 0.017453292519943295;
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/266C80", func_800FF364_YoshisTropicalIslandEndingScene);
#endif

// D_80110448 base not hoisted out of the first loop; register allocation (masked 23)
#ifdef NON_MATCHING
void func_800FF59C_YoshisTropicalIslandEndingScene(void) {
    s32 n = D_8010DC90_YoshisTropicalIslandEndingScene[GwSystem.unk_00];
    f32 r = D_8010DCFC_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene];
    s32 i;
    s32 c;
    f32 a;
    f32 s;
    Object** p;
    omObjData* obj;
    omObjData* obj2;

    for (i = 0; i < n; i++) {
        p = &D_80110448_YoshisTropicalIslandEndingScene[i];
        *p = MBModelCreate(0x25, NULL);
        a = ((360 / n) * i) * D_8010F1A8_YoshisTropicalIslandEndingScene;
        func_800A0D00(&(*p)->coords, (sinf(a) * r) + D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].x, D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].y,
                      (cosf(a) * r) + D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].z);
        func_800A0D00(&(*p)->coords, D_8010DD1C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene], D_8010DD1C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene], D_8010DD1C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene]);
        D_80110400_YoshisTropicalIslandEndingScene[i] = func_80042728(*p, 1);
    }
    obj = omAddObj(0x1000, 0, 0, -1, &func_800FF364_YoshisTropicalIslandEndingScene);
    obj->rot.y = 0.0f;
    obj->trans.x = r;
    obj->trans.y = n;
    obj->scale.x = D_8010DD1C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene];
    LoadBackgroundIndex(D_8010DD3C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene]);
    func_80072724(0xFF, 0xFF, 0xFF);
    SetFadeInTypeAndTime(2, 0x18);
    PlaySound(0x48);
    HuPrcSleep(0x36);
    while (r >= 350.0f) {
        obj->trans.x = r;
        if ((r - 10.0f) < 350.0f) {
            func_80072724(0xFF, 0xFF, 0xFF);
            func_800726AC(0, 0);
            PlaySound(0x4B);
        }
        HuPrcVSleep();
        r -= 10.0f;
    }
    HuPrcSleep(5);
    for (i = 0; i < n; i++) {
        MBModelKill(D_80110448_YoshisTropicalIslandEndingScene[i]);
        D_80110448_YoshisTropicalIslandEndingScene[i] = NULL;
        func_800427D4(D_80110400_YoshisTropicalIslandEndingScene[i]);
        D_80110400_YoshisTropicalIslandEndingScene[i] = NULL;
    }
    D_80110448_YoshisTropicalIslandEndingScene[0] = MBModelCreate(0x25, NULL);
    D_80110400_YoshisTropicalIslandEndingScene[0] = func_80042728(D_80110448_YoshisTropicalIslandEndingScene[0], 1);
    func_800258EC(*D_80110448_YoshisTropicalIslandEndingScene[0]->unk_3C->unk_40, 0x10000, 0x10000);
    func_80025AD4(*D_80110448_YoshisTropicalIslandEndingScene[0]->unk_3C->unk_40);
    func_80028C64(*D_80110448_YoshisTropicalIslandEndingScene[0]->unk_3C->unk_40, 0xFF, 0xFF, 0xFF, 0xFF);
    D_80110448_YoshisTropicalIslandEndingScene[0]->xScale = 2.0f * D_8010DD1C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene];
    D_80110448_YoshisTropicalIslandEndingScene[0]->yScale = 2.0f * D_8010DD1C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene];
    D_80110448_YoshisTropicalIslandEndingScene[0]->zScale = 2.0f * D_8010DD1C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene];
    D_80110448_YoshisTropicalIslandEndingScene[0]->coords.x = D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].x;
    D_80110448_YoshisTropicalIslandEndingScene[0]->coords.y = D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].y;
    D_80110448_YoshisTropicalIslandEndingScene[0]->coords.z = D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].z;
    omDelObj(obj);
    obj2 = omAddObj(0x1000, 0, 0, -1, &func_800FF240_YoshisTropicalIslandEndingScene);
    omSetRot(obj2, 0.0f, 0.0f, 0.0f);
    obj2->work[1] = 1;
    HuPrcSleep(5);
    SetFadeInTypeAndTime(0, 0x10);
    HuPrcSleep(0x10);
    for (c = 0xF8; c >= 0; c -= 4) {
        func_80028C64(*D_80110448_YoshisTropicalIslandEndingScene[0]->unk_3C->unk_40, c, c, c, 0xFF);
        HuPrcVSleep();
    }
    while (obj2->work[1] == 0) {
        HuPrcSleep(0);
    }
    func_800726AC(0, 0x24);
    for (i = 0; i < 0x25; i++) {
        D_80110448_YoshisTropicalIslandEndingScene[0]->coords.z -= 30.0f;
        s = (2.0f * D_8010DD1C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene]) * (D_8010F1B8_YoshisTropicalIslandEndingScene - ((i * 0.027777778f) * D_8010F1B0_YoshisTropicalIslandEndingScene));
        func_800A0D00((Vec3f*)&D_80110448_YoshisTropicalIslandEndingScene[0]->xScale, s, s, s);
        HuPrcSleep(0);
    }
    omDelObj(obj2);
    MBModelKill(D_80110448_YoshisTropicalIslandEndingScene[0]);
    D_80110448_YoshisTropicalIslandEndingScene[0] = NULL;
    func_800427D4(D_80110400_YoshisTropicalIslandEndingScene[0]);
    D_80110400_YoshisTropicalIslandEndingScene[0] = NULL;
    func_8004A140();
    HuPrcSleep(10);
}
const f64 D_8010F1A8_YoshisTropicalIslandEndingScene = 0.017453292519943295;
const f64 D_8010F1B0_YoshisTropicalIslandEndingScene = 0.7;
const f64 D_8010F1B8_YoshisTropicalIslandEndingScene = 1.0;
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/266C80", func_800FF59C_YoshisTropicalIslandEndingScene);
#endif

void func_800FFC08_YoshisTropicalIslandEndingScene(s32* arg0, s32* arg1) {
    f32 pos[5][2] = { { 16.0f, 160.0f }, { 68.0f, 152.0f }, { 160.0f, 140.0f }, { 252.0f, 152.0f }, { 304.0f, 160.0f } };
    void* file;
    s32 i;

    *arg0 = func_80064EF4(5, 0);
    file = DataRead(0xA0154);
    arg1[0] = func_800678A4(file);
    DataClose(file);
    func_80067208(*arg0, 0, arg1[0], 0);
    file = DataRead(0xA0155);
    arg1[1] = func_800678A4(file);
    DataClose(file);
    func_80067208(*arg0, 1, arg1[1], 0);
    file = DataRead(0xA0156);
    arg1[2] = func_800678A4(file);
    DataClose(file);
    func_80067208(*arg0, 2, arg1[2], 0);
    file = DataRead(0xA0157);
    arg1[3] = func_800678A4(file);
    DataClose(file);
    func_80067208(*arg0, 3, arg1[3], 0);
    file = DataRead(0xA0158);
    arg1[4] = func_800678A4(file);
    DataClose(file);
    func_80067208(*arg0, 4, arg1[4], 0);
    for (i = 0; i < 5; i++) {
        func_80067384(*arg0, i, 0x47F4);
        func_800674BC(*arg0, i, 0xD000);
        func_80066DC4(*arg0, i, pos[i][0], pos[i][1]);
    }
}
void func_800FFE6C_YoshisTropicalIslandEndingScene(s32* arg0, s32* arg1) {
    s32 i;

    for (i = 0; i < 5; i++) {
        func_80067480(*arg0, i, 0x8000);
    }
}
void func_800FFEBC_YoshisTropicalIslandEndingScene(s32* arg0, s32* arg1) {
    s32 i;

    for (i = 0; i < 5; i++) {
        func_800674BC(*arg0, 0, 0x8000);
    }
}
void func_800FFF08_YoshisTropicalIslandEndingScene(s32* arg0, s32* arg1) {
    s32 i;

    func_80064D38(*arg0);
    for (i = 0; i < 5; i++) {
        func_80067704(arg1[i]);
    }
}
// load of arg0->unk_80 scheduled after the index arithmetic (raw 2, masked 2); `&unk_80[i]`,
// `e = unk_80; e += i;` and declaring e first tried
#ifdef NON_MATCHING
void func_800FFF5C_YoshisTropicalIslandEndingScene(unk2C0C0StructC0* arg0, f32 arg1, s16 arg2) {
    f32 w = 190.0f;
    f32 off = -910.0f;
    f32 k = 1080.0f;
    unk2C0C0Struct30* e = arg0->unk_80 + arg2;
    unk2C0C0StructE0* src = &arg0->unk_04[e->unk_0A];
    unk2C0C0StructE0* dst = &arg0->unk_08[D_800F37F0][e->unk_0A];
    Unk266V3s p;
    f32 x;
    f32 d;
    f32 base;
    f32 y;
    s16 i;
    s16 n;

    n = e->unk_0C;
    for (i = 0; i < n; i++) {
        p.x = src->unk_00;
        p.y = src->unk_02;
        p.z = src->unk_04;
        x = p.x - off;
        d = w + ((190.0f / w) * x);
        base = func_800AEFD0(-arg1 * 360.0f);
        y = (((x / w) * 60.0f) + 30.0f) * (func_800AEFD0(((x * k) / d) - (arg1 * 360.0f)) - base);
        *dst = *src;
        dst->unk_00 = p.x;
        dst->unk_02 = p.y;
        dst->unk_04 = p.z + y;
        dst->unk_0C.r = src->unk_0C.r;
        dst->unk_0C.g = src->unk_0C.g;
        dst->unk_0C.b = src->unk_0C.b;
        src++;
        dst++;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/266C80", func_800FFF5C_YoshisTropicalIslandEndingScene);
#endif
void func_801001D0_YoshisTropicalIslandEndingScene(s16 arg0, f32 arg1, char* arg2) {
    unk2C0C0StructC0* s = D_800F2B7C[arg0].unk_6C;
    s8 k = func_80033718(s, arg2);

    if (k != -1) {
        func_800FFF5C_YoshisTropicalIslandEndingScene(s, arg1, k);
    }
}
void func_8010024C_YoshisTropicalIslandEndingScene(void) {
    func_800FF59C_YoshisTropicalIslandEndingScene();
}
void func_80100268_YoshisTropicalIslandEndingScene(void) {
    omObjData* fx;
    omObjData* spr;
    f32 x;

    LoadBackgroundIndex(0x23);
    D_80110448_YoshisTropicalIslandEndingScene[0] = MBModelCreate(0x40, NULL);
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[0]->coords, 275.0f, 550.0f, 1050.0f);
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[0]->unk_18, 0.0f, 0.0f, 1.0f);
    func_800A0D00((Vec3f*)&D_80110448_YoshisTropicalIslandEndingScene[0]->xScale, 0.75f, 0.75f, 0.75f);
    D_80110300_YoshisTropicalIslandEndingScene[0] = omAddObj(0x1000, 0, 0, -1, &func_800FD60C_YoshisTropicalIslandEndingScene);
    omSetTra(D_80110300_YoshisTropicalIslandEndingScene[0], 0.0f, 0.0f, 0.0f);
    omSetRot(D_80110300_YoshisTropicalIslandEndingScene[0], 0.0f, 0.0f, 0.0f);
    omSetSca(D_80110300_YoshisTropicalIslandEndingScene[0], 0.75f, 0.75f, 0.75f);
    D_80110300_YoshisTropicalIslandEndingScene[0]->work[0] = 3;
    D_80110400_YoshisTropicalIslandEndingScene[0] = func_80042728(D_80110448_YoshisTropicalIslandEndingScene[0], 1);
    D_80110448_YoshisTropicalIslandEndingScene[1] = MBModelCreate(0x2E, NULL);
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[1]->coords, -150.0f, 0.0f, 1050.0f);
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[1]->unk_18, 1.0f, 0.0f, 0.0f);
    func_8004FAB8(D_80110440_YoshisTropicalIslandEndingScene);
    func_800FE310_YoshisTropicalIslandEndingScene(8);
    SetFadeInTypeAndTime(0, 0x10);
    HuPrcSleep(0x10);
    PlaySound(0x5E);
    x = ((-75.0f - D_80110448_YoshisTropicalIslandEndingScene[0]->coords.x) * 0.5f) + D_80110448_YoshisTropicalIslandEndingScene[0]->coords.x;
    do {
        HuPrcSleep(0);
    } while (!(D_80110448_YoshisTropicalIslandEndingScene[0]->coords.x < x));
    func_800427D4(D_80110400_YoshisTropicalIslandEndingScene[0]);
    D_80110400_YoshisTropicalIslandEndingScene[0] = NULL;
    while (D_80110300_YoshisTropicalIslandEndingScene[0]->work[0] != 4) {
        HuPrcSleep(0);
    }
    HuPrcSleep(0x14);
    PlaySound(0x5F);
    fx = func_800FDA0C_YoshisTropicalIslandEndingScene(-25.0f, 175.0f, 1050.0f);
    spr = func_800FDF78_YoshisTropicalIslandEndingScene(8, -25.0f, 275.0f, 1075.0f);
    do {
        HuPrcSleep(0);
        D_80110448_YoshisTropicalIslandEndingScene[0]->coords.x += 50.0f;
        D_80110448_YoshisTropicalIslandEndingScene[0]->coords.y += 50.0f;
    } while (!(D_80110448_YoshisTropicalIslandEndingScene[0]->coords.x > 750.0f) && !(D_80110448_YoshisTropicalIslandEndingScene[0]->coords.x > 850.0f));
    HuPrcSleep(8);
    func_800726AC(0, 0x14);
    HuPrcSleep(0x14);
    func_800FE538_YoshisTropicalIslandEndingScene(spr);
    omDelObj(fx);
    func_8004FAB8(D_80110440_YoshisTropicalIslandEndingScene);
    func_8004A140();
    func_800F6B54_YoshisTropicalIslandEndingScene();
}
void func_801005C0_YoshisTropicalIslandEndingScene(void) {
    LoadBackgroundIndex(0x25);
    func_8004B7F8(0x60);
    func_8002578C(0);
    D_801102B8_YoshisTropicalIslandEndingScene[D_8010E82C_YoshisTropicalIslandEndingScene] = func_800FEB8C_YoshisTropicalIslandEndingScene(D_8010E5D4_YoshisTropicalIslandEndingScene[0].id);
    (&D_801102B8_YoshisTropicalIslandEndingScene[1])[D_8010E82C_YoshisTropicalIslandEndingScene] = func_800FEB8C_YoshisTropicalIslandEndingScene(D_8010E5D4_YoshisTropicalIslandEndingScene[1].id);
    (&D_801102B8_YoshisTropicalIslandEndingScene[2])[D_8010E82C_YoshisTropicalIslandEndingScene] = func_800FEB8C_YoshisTropicalIslandEndingScene(D_8010E5D4_YoshisTropicalIslandEndingScene[2].id);
    D_80110300_YoshisTropicalIslandEndingScene[D_8010E82C_YoshisTropicalIslandEndingScene] = func_800FEE24_YoshisTropicalIslandEndingScene(D_8010E82C_YoshisTropicalIslandEndingScene, 0, 0);
    (&D_80110300_YoshisTropicalIslandEndingScene[1])[D_8010E82C_YoshisTropicalIslandEndingScene] = func_800FEE24_YoshisTropicalIslandEndingScene(D_8010E82C_YoshisTropicalIslandEndingScene + 1, 0, 1);
    (&D_80110300_YoshisTropicalIslandEndingScene[2])[D_8010E82C_YoshisTropicalIslandEndingScene] = func_800FEE24_YoshisTropicalIslandEndingScene(D_8010E82C_YoshisTropicalIslandEndingScene + 2, 0, 2);
    PlaySound(0x64);
    (&D_80110300_YoshisTropicalIslandEndingScene[3])[D_8010E82C_YoshisTropicalIslandEndingScene] = func_800FF1A0_YoshisTropicalIslandEndingScene(D_8010E82C_YoshisTropicalIslandEndingScene);
    (&D_80110300_YoshisTropicalIslandEndingScene[4])[D_8010E82C_YoshisTropicalIslandEndingScene] = func_800FF1A0_YoshisTropicalIslandEndingScene(D_8010E82C_YoshisTropicalIslandEndingScene + 1);
    (&D_80110300_YoshisTropicalIslandEndingScene[5])[D_8010E82C_YoshisTropicalIslandEndingScene] = func_800FF1A0_YoshisTropicalIslandEndingScene(D_8010E82C_YoshisTropicalIslandEndingScene + 2);
    SetFadeInTypeAndTime(0, 0x10);
    HuPrcSleep(6);
    HuPrcSleep(0x30);
    D_8010F870_YoshisTropicalIslandEndingScene = 0;
    func_80060128(2);
    HuPrcSleep(0x48);
    func_800726AC(0, 0x14);
    HuPrcSleep(0x14);
    func_800FEFE0_YoshisTropicalIslandEndingScene(D_8010E82C_YoshisTropicalIslandEndingScene);
    omDelObj((&D_80110300_YoshisTropicalIslandEndingScene[3])[D_8010E82C_YoshisTropicalIslandEndingScene]);
    (&D_80110300_YoshisTropicalIslandEndingScene[3])[D_8010E82C_YoshisTropicalIslandEndingScene] = NULL;
    func_800FEFE0_YoshisTropicalIslandEndingScene(D_8010E82C_YoshisTropicalIslandEndingScene + 1);
    omDelObj((&D_80110300_YoshisTropicalIslandEndingScene[4])[D_8010E82C_YoshisTropicalIslandEndingScene]);
    (&D_80110300_YoshisTropicalIslandEndingScene[4])[D_8010E82C_YoshisTropicalIslandEndingScene] = NULL;
    func_800FEFE0_YoshisTropicalIslandEndingScene(D_8010E82C_YoshisTropicalIslandEndingScene + 2);
    omDelObj((&D_80110300_YoshisTropicalIslandEndingScene[5])[D_8010E82C_YoshisTropicalIslandEndingScene]);
    (&D_80110300_YoshisTropicalIslandEndingScene[5])[D_8010E82C_YoshisTropicalIslandEndingScene] = NULL;
    func_8004B7F8(0xFF);
    func_8002578C(1);
    func_8004A140();
    func_800F6B54_YoshisTropicalIslandEndingScene();
}
/* The plant models' start ([0..3]) and end ([4..7]) positions in the third scene */
const Vec3f D_8010F1E8_YoshisTropicalIslandEndingScene[8] = {
    { 500.0f, 0.0f, 1485.0f }, { 650.0f, 0.0f, 1485.0f }, { 975.0f, 0.0f, 1485.0f }, { 1125.0f, 0.0f, 1485.0f },
    { -325.0f, 0.0f, 1485.0f }, { -175.0f, 0.0f, 1485.0f }, { 175.0f, 0.0f, 1485.0f }, { 325.0f, 0.0f, 1485.0f },
};

void func_8010087C_YoshisTropicalIslandEndingScene(void) {
    s32 sp18[16];
    s32 sp58[2];
    f32 x;
    s32 i;

    LoadBackgroundIndex(0x22);
    func_800FFC08_YoshisTropicalIslandEndingScene(sp58, sp18);
    {
        Vec3f sp60 = { 0.0f, 0.0f, 1475.0f };

        func_80052DC8(GwCommon.boardWork[0], D_8010E550_YoshisTropicalIslandEndingScene[GwPlayer[GwCommon.boardWork[0]].character]);
        MBMotionSet(GwPlayer[GwCommon.boardWork[0]].player_obj, 0, 2);
        GwPlayer[GwCommon.boardWork[0]].flags |= 2;
        func_800A0D00(&GwPlayer[GwCommon.boardWork[0]].player_obj->coords, 812.5f, 0.0f, 1475.0f);
        func_8004CCD0(&GwPlayer[GwCommon.boardWork[0]].player_obj->coords, &sp60, &GwPlayer[GwCommon.boardWork[0]].player_obj->unk_18);
        D_80110448_YoshisTropicalIslandEndingScene[6] = MBModelCreate(0xF, NULL);
        D_80110448_YoshisTropicalIslandEndingScene[7] = MBModelCreate(0xE, NULL);
        D_80110448_YoshisTropicalIslandEndingScene[8] = MBModelCreate(0xF, NULL);
        D_80110448_YoshisTropicalIslandEndingScene[9] = MBModelCreate(0xE, NULL);
        for (i = 0; i < 4; i++) {
            func_80026018(*D_80110448_YoshisTropicalIslandEndingScene[6 + i]->unk_3C->unk_40, 2.0f);
        }
        func_80026018(*GwPlayer[GwCommon.boardWork[0]].player_obj->unk_3C->unk_40, 2.0f);
        for (i = 0; i < 4; i++) {
            func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[6 + i]->coords, D_8010F1E8_YoshisTropicalIslandEndingScene[i].x, D_8010F1E8_YoshisTropicalIslandEndingScene[i].y, D_8010F1E8_YoshisTropicalIslandEndingScene[i].z);
            func_8004CCD0(&D_80110448_YoshisTropicalIslandEndingScene[6 + i]->coords, (Vec3f*)&D_8010F1E8_YoshisTropicalIslandEndingScene[4 + i], &D_80110448_YoshisTropicalIslandEndingScene[6 + i]->unk_18);
        }
        D_80110448_YoshisTropicalIslandEndingScene[1] = MBModelCreate(0x32, NULL);
        func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[1]->coords, -100.0f, 0.0f, 1237.5f);
        func_80026040(*D_80110448_YoshisTropicalIslandEndingScene[1]->unk_3C->unk_40);
        D_80110300_YoshisTropicalIslandEndingScene[1] = omAddObj(0x1000, 0, 0, -1, &func_800FE5A4_YoshisTropicalIslandEndingScene);
        D_80110300_YoshisTropicalIslandEndingScene[1]->trans.x = 0.0f;
        D_80110300_YoshisTropicalIslandEndingScene[1]->work[0] = 1;
        func_8001ABA0(2);
        func_8004B7F8(0xC0);
        func_8002578C(0);
        D_801102B8_YoshisTropicalIslandEndingScene[10] = func_800FEB8C_YoshisTropicalIslandEndingScene(D_8010E698_YoshisTropicalIslandEndingScene[0].id);
        D_801102B8_YoshisTropicalIslandEndingScene[11] = func_800FEB8C_YoshisTropicalIslandEndingScene(D_8010E698_YoshisTropicalIslandEndingScene[1].id);
        D_801102B8_YoshisTropicalIslandEndingScene[12] = func_800FEB8C_YoshisTropicalIslandEndingScene(D_8010E698_YoshisTropicalIslandEndingScene[2].id);
        SetFadeInTypeAndTime(0, 0x10);
        HuPrcSleep(6);
        D_80110300_YoshisTropicalIslandEndingScene[10] = func_800FEE24_YoshisTropicalIslandEndingScene(0xA, 1, 0);
        D_80110300_YoshisTropicalIslandEndingScene[11] = func_800FEE24_YoshisTropicalIslandEndingScene(0xB, 1, 1);
        D_80110300_YoshisTropicalIslandEndingScene[12] = func_800FEE24_YoshisTropicalIslandEndingScene(0xC, 1, 2);
        D_80110300_YoshisTropicalIslandEndingScene[13] = func_800FF1A0_YoshisTropicalIslandEndingScene(0xA);
        D_80110300_YoshisTropicalIslandEndingScene[14] = func_800FF1A0_YoshisTropicalIslandEndingScene(0xB);
        D_80110300_YoshisTropicalIslandEndingScene[15] = func_800FF1A0_YoshisTropicalIslandEndingScene(0xC);
        HuPrcSleep(0xA);
        func_800FFE6C_YoshisTropicalIslandEndingScene(sp58, sp18);
        x = D_8010F1E8_YoshisTropicalIslandEndingScene[0].x - D_8010F1E8_YoshisTropicalIslandEndingScene[4].x;
        while (D_8010F1E8_YoshisTropicalIslandEndingScene[4].x <= D_80110448_YoshisTropicalIslandEndingScene[6]->coords.x) {
            HuPrcSleep(0);
            D_80110448_YoshisTropicalIslandEndingScene[6]->coords.x = x + D_8010F1E8_YoshisTropicalIslandEndingScene[4].x;
            D_80110448_YoshisTropicalIslandEndingScene[7]->coords.x = x + D_8010F1E8_YoshisTropicalIslandEndingScene[5].x;
            D_80110448_YoshisTropicalIslandEndingScene[8]->coords.x = x + D_8010F1E8_YoshisTropicalIslandEndingScene[6].x;
            D_80110448_YoshisTropicalIslandEndingScene[9]->coords.x = x + D_8010F1E8_YoshisTropicalIslandEndingScene[7].x;
            GwPlayer[GwCommon.boardWork[0]].player_obj->coords.x = x + 0.0f;
            x -= 6.5f;
        }
        MBMotionShiftSet(GwPlayer[GwCommon.boardWork[0]].player_obj, -1, 0, 8, 2);
        HuPrcSleep(8);
        func_8004EE14(GwCommon.boardWork[0], D_800F32A0, 8, NULL);
        for (i = 0; i < 4; i++) {
            func_80026018(*D_80110448_YoshisTropicalIslandEndingScene[6 + i]->unk_3C->unk_40, 1.0f);
        }
        func_80026018(*GwPlayer[GwCommon.boardWork[0]].player_obj->unk_3C->unk_40, 1.0f);
        for (i = 0; i < 4; i++) {
            func_8004EE14(0, D_800F32A0, 8, D_80110448_YoshisTropicalIslandEndingScene[6 + i]);
        }
        HuPrcSleep(0x14);
        func_8004F4D4(GwPlayer[GwCommon.boardWork[0]].player_obj, 1, 2);
        D_80110300_YoshisTropicalIslandEndingScene[6] = omAddObj(0x400, 0, 0, -1, &func_800FEAA0_YoshisTropicalIslandEndingScene);
        D_80110300_YoshisTropicalIslandEndingScene[6]->work[0] = 6;
        D_80110300_YoshisTropicalIslandEndingScene[7] = omAddObj(0x400, 0, 0, -1, &func_800FEAA0_YoshisTropicalIslandEndingScene);
        D_80110300_YoshisTropicalIslandEndingScene[7]->work[0] = 7;
        D_80110300_YoshisTropicalIslandEndingScene[8] = omAddObj(0x400, 0, 0, -1, &func_800FEAA0_YoshisTropicalIslandEndingScene);
        D_80110300_YoshisTropicalIslandEndingScene[8]->work[0] = 8;
        D_80110300_YoshisTropicalIslandEndingScene[9] = omAddObj(0x400, 0, 0, -1, &func_800FEAA0_YoshisTropicalIslandEndingScene);
        D_80110300_YoshisTropicalIslandEndingScene[9]->work[0] = 9;
        HuPrcSleep(0x39);
        func_8004B7F8(0xFF);
        func_8002578C(1);
        HuPrcSleep(3);
        func_8001ABA0(3);
        func_800FFEBC_YoshisTropicalIslandEndingScene(sp58, sp18);
        func_800FFF08_YoshisTropicalIslandEndingScene(sp58, sp18);
        func_800726AC(1, 0x14);
        HuPrcSleep(0x14);
        func_800FEFE0_YoshisTropicalIslandEndingScene(0xA);
        omDelObj(D_80110300_YoshisTropicalIslandEndingScene[13]);
        D_80110300_YoshisTropicalIslandEndingScene[13] = NULL;
        func_800FEFE0_YoshisTropicalIslandEndingScene(0xB);
        omDelObj(D_80110300_YoshisTropicalIslandEndingScene[14]);
        D_80110300_YoshisTropicalIslandEndingScene[14] = NULL;
        func_800FEFE0_YoshisTropicalIslandEndingScene(0xC);
        omDelObj(D_80110300_YoshisTropicalIslandEndingScene[15]);
        D_80110300_YoshisTropicalIslandEndingScene[15] = NULL;
        func_8004A140();
        func_800F6B54_YoshisTropicalIslandEndingScene();
    }
}
void func_8010102C_YoshisTropicalIslandEndingScene(void) {
    Matrix4f sp18;
    omObjData* spr;
    u16 id;

    LoadBackgroundIndex(0x23);
    {
        Vec3f sp58[6] = {
            { 165.0f, 200.0f, 1000.0f }, { 125.0f, 175.0f, 1000.0f }, { 165.0f, 225.0f, 1000.0f },
            { 125.0f, 195.0f, 1000.0f }, { 165.0f, 155.0f, 1000.0f }, { 125.0f, 150.0f, 1000.0f },
        };
        f32 spA0[6] = { 30.0f, -30.0f, 30.0f, 30.0f, 30.0f, 30.0f };

        func_80052DC8(GwCommon.boardWork[3], D_8010E568_YoshisTropicalIslandEndingScene[GwPlayer[GwCommon.boardWork[3]].character]);
        GwPlayer[GwCommon.boardWork[3]].flags |= 2;
        func_800A0D50(&GwPlayer[GwCommon.boardWork[3]].player_obj->coords, &sp58[GwPlayer[GwCommon.boardWork[3]].character]);
        func_800A0D00(&GwPlayer[GwCommon.boardWork[3]].player_obj->unk_18, -1.0f, 0.0f, 0.0f);
        func_800A0D00((Vec3f*)&GwPlayer[GwCommon.boardWork[3]].player_obj->xScale, 0.55f, 0.55f, 0.55f);
        GwPlayer[GwCommon.boardWork[3]].player_obj->unk_0A |= 1;
        func_8004F4D4(GwPlayer[GwCommon.boardWork[3]].player_obj, 0, 2);
        id = *GwPlayer[GwCommon.boardWork[3]].player_obj->unk_3C->unk_40;
        guRotateF(sp18, spA0[GwPlayer[GwCommon.boardWork[3]].character], 1.0f, 0.0f, 0.0f);
        guMtxCatF(sp18, D_800F2B7C[(s16)id].unk7C, D_800F2B7C[(s16)id].unk7C);
        D_80110448_YoshisTropicalIslandEndingScene[1] = MBModelCreate(0x2F, NULL);
        func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[1]->coords, 25.0f, 0.0f, 1050.0f);
        func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[1]->unk_18, 1.0f, 0.0f, 0.0f);
        D_80110448_YoshisTropicalIslandEndingScene[2] = MBModelCreate(6, D_8010E5B0_YoshisTropicalIslandEndingScene);
        func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[2]->coords, -240.0f, 0.0f, 945.0f);
        func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[2]->unk_18, 1.0f, 0.0f, 0.0f);
        func_8004FAB8(D_80110440_YoshisTropicalIslandEndingScene);
        func_800FE310_YoshisTropicalIslandEndingScene(8);
        SetFadeInTypeAndTime(1, 0x10);
        HuPrcSleep(0x24);
        MBMotionShiftSet(D_80110448_YoshisTropicalIslandEndingScene[2], 4, 0, 0xA, 0);
        func_8004F504(D_80110448_YoshisTropicalIslandEndingScene[2]);
        MBMotionShiftSet(D_80110448_YoshisTropicalIslandEndingScene[2], 2, 0, 0x14, 2);
        PlaySound(0x5F);
        D_80110300_YoshisTropicalIslandEndingScene[1] = func_800FDA0C_YoshisTropicalIslandEndingScene(125.0f, 175.0f, 1050.0f);
        spr = func_800FDF78_YoshisTropicalIslandEndingScene(8, 150.0f, 275.0f, 1075.0f);
        do {
            HuPrcSleep(0);
            GwPlayer[GwCommon.boardWork[3]].player_obj->coords.x += 40.0f;
            GwPlayer[GwCommon.boardWork[3]].player_obj->coords.y += 40.0f;
        } while (!(GwPlayer[GwCommon.boardWork[3]].player_obj->coords.x > 750.0f) &&
                 !(GwPlayer[GwCommon.boardWork[3]].player_obj->coords.x > 850.0f));
        HuPrcSleep(0x1E);
        func_800726AC(1, 0x14);
        func_8004FAB8(D_80110440_YoshisTropicalIslandEndingScene);
        HuPrcSleep(0x14);
        func_800FE538_YoshisTropicalIslandEndingScene(spr);
        func_8004A140();
        func_800F6B54_YoshisTropicalIslandEndingScene();
    }
}
/* The point func_8004E3E0 is given in the last scene */
const Vec3f D_8010F2B4_YoshisTropicalIslandEndingScene = { 0.0f, 310.0f, 2165.0f };

void func_8010151C_YoshisTropicalIslandEndingScene(void) {
    s32 sp18[16];
    s32 sp58[2];
    Matrix4f sp60;
    Vec3f spA0;
    Vec3f spB0;
    Vec3f spC0;
    Vec3f spD0;
    Vec3f spE0;
    Vec3f spF0;
    Vec3f sp100;
    Vec3f sp110;
    f32 t;
    f32 v;
    s32 i;
    s32 j;
    u16 id;

    LoadBackgroundIndex(0x22);
    func_800FFC08_YoshisTropicalIslandEndingScene(sp58, sp18);
    for (i = 0; i < 4; i++) {
        if (GwCommon.boardWork[0] == i) {
            func_80052DC8(i, D_8010E580_YoshisTropicalIslandEndingScene[GwPlayer[i].character]);
        } else if (GwCommon.boardWork[3] == i) {
            func_80052DC8(i, D_8010E598_YoshisTropicalIslandEndingScene[GwPlayer[i].character]);
        } else {
            func_80052E84(i);
        }
        GwPlayer[i].flags |= 2;
        func_80021B14(*GwPlayer[i].player_obj->unk_3C->unk_40, GwPlayer[i].character, 0);
    }
    for (j = 0; j < 4; j++) {
        func_800A0D00(&GwPlayer[GwCommon.boardWork[j]].player_obj->coords, D_8010F114_YoshisTropicalIslandEndingScene[j].x, D_8010F114_YoshisTropicalIslandEndingScene[j].y, D_8010F114_YoshisTropicalIslandEndingScene[j].z);
    }
    id = *GwPlayer[GwCommon.boardWork[3]].player_obj->unk_3C->unk_40;
    MBMotionSet(GwPlayer[GwCommon.boardWork[3]].player_obj, 0, 2);
    MBModelDispOff(GwPlayer[GwCommon.boardWork[3]].player_obj);
    GwPlayer[GwCommon.boardWork[3]].player_obj->unk_0A |= 1;
    func_800A0D00(&spA0, 400.0f, 300.0f, 1160.0f);
    func_8004CCD0(&GwPlayer[GwCommon.boardWork[3]].player_obj->coords, &spA0, &GwPlayer[GwCommon.boardWork[3]].player_obj->unk_18);
    guRotateF(sp60, 25.0f, 1.0f, 0.0f, 0.0f);
    guMtxCatF(sp60, D_800F2B7C[(s16)id].unk7C, D_800F2B7C[(s16)id].unk7C);
    func_800A0D00(&spB0, -500.0f, 600.0f, 1160.0f);
    func_800A0D50(&GwPlayer[GwCommon.boardWork[3]].player_obj->coords, &spB0);
    D_80110448_YoshisTropicalIslandEndingScene[0] = func_800FF1E4_YoshisTropicalIslandEndingScene(&D_8010E830_YoshisTropicalIslandEndingScene[0]);
    D_80110448_YoshisTropicalIslandEndingScene[1] = func_800FF1E4_YoshisTropicalIslandEndingScene(&D_8010E830_YoshisTropicalIslandEndingScene[1]);
    D_80110448_YoshisTropicalIslandEndingScene[5] = func_800FF1E4_YoshisTropicalIslandEndingScene(&D_8010E830_YoshisTropicalIslandEndingScene[5]);
    D_80110448_YoshisTropicalIslandEndingScene[6] = func_800FF1E4_YoshisTropicalIslandEndingScene(&D_8010E830_YoshisTropicalIslandEndingScene[6]);
    D_80110448_YoshisTropicalIslandEndingScene[2] = func_800FF1E4_YoshisTropicalIslandEndingScene(&D_8010E830_YoshisTropicalIslandEndingScene[2]);
    func_8004CCD0(&GwPlayer[GwCommon.boardWork[0]].player_obj->coords, &spB0, &GwPlayer[GwCommon.boardWork[0]].player_obj->unk_18);
    func_8004CCD0(&GwPlayer[GwCommon.boardWork[1]].player_obj->coords, &spB0, &GwPlayer[GwCommon.boardWork[1]].player_obj->unk_18);
    func_8004CCD0(&GwPlayer[GwCommon.boardWork[2]].player_obj->coords, &spB0, &GwPlayer[GwCommon.boardWork[2]].player_obj->unk_18);
    func_8004CCD0(&D_80110448_YoshisTropicalIslandEndingScene[0]->coords, &spB0, &D_80110448_YoshisTropicalIslandEndingScene[0]->unk_18);
    func_8004CCD0(&D_80110448_YoshisTropicalIslandEndingScene[5]->coords, &spB0, &D_80110448_YoshisTropicalIslandEndingScene[5]->unk_18);
    func_8004CCD0(&D_80110448_YoshisTropicalIslandEndingScene[6]->coords, &spB0, &D_80110448_YoshisTropicalIslandEndingScene[6]->unk_18);
    func_8004CCD0(&D_80110448_YoshisTropicalIslandEndingScene[2]->coords, &spB0, &D_80110448_YoshisTropicalIslandEndingScene[2]->unk_18);
    func_80026040(*D_80110448_YoshisTropicalIslandEndingScene[1]->unk_3C->unk_40);
    D_80110300_YoshisTropicalIslandEndingScene[1] = omAddObj(0x800, 0, 0, -1, &func_800FE5A4_YoshisTropicalIslandEndingScene);
    D_80110300_YoshisTropicalIslandEndingScene[1]->trans.x = 0.0f;
    D_80110300_YoshisTropicalIslandEndingScene[1]->work[0] = 1;
    D_801102B8_YoshisTropicalIslandEndingScene[11] = func_800FEB8C_YoshisTropicalIslandEndingScene(D_8010E7B0_YoshisTropicalIslandEndingScene[0].id);
    D_801102B8_YoshisTropicalIslandEndingScene[12] = func_800FEB8C_YoshisTropicalIslandEndingScene(D_8010E7B0_YoshisTropicalIslandEndingScene[1].id);
    HuPrcSleep(3);
    SetFadeInTypeAndTime(1, 0x10);
    HuPrcSleep(0x10);
    func_800FFE6C_YoshisTropicalIslandEndingScene(sp58, sp18);
    func_8001ABA0(2);
    func_8004B7F8(0xC0);
    func_8002578C(0);
    func_800A0D00(&spC0, -500.0f, 600.0f, 1160.0f);
    func_800A0D00(&spD0, 850.0f, 250.0f, 1160.0f);
    MBModelDispOn(GwPlayer[GwCommon.boardWork[3]].player_obj);
    GwPlayer[GwCommon.boardWork[3]].player_obj->unk_0A |= 1;
    func_8004CCD0(&GwPlayer[GwCommon.boardWork[3]].player_obj->coords, &spD0, &GwPlayer[GwCommon.boardWork[3]].player_obj->unk_18);
    t = 0.0f;
    do {
        HuPrcSleep(0);
        if (t > 100.0f) {
            t = 100.0f;
        }
        func_800A0D00(&spE0, ((spD0.x - spC0.x) * 0.01f * t) + spC0.x, ((spD0.y - spC0.y) * 0.01f * t) + spC0.y,
                      ((spD0.z - spC0.z) * 0.01f * t) + spC0.z);
        func_800A0D00(&GwPlayer[GwCommon.boardWork[3]].player_obj->coords, spE0.x, spE0.y, spE0.z);
        func_800A0D00((Vec3f*)&GwPlayer[GwCommon.boardWork[3]].player_obj->xScale, 0.001f, 0.001f, 0.001f);
        for (j = 0; j < 3; j++) {
            func_8004CCD0(&GwPlayer[GwCommon.boardWork[j]].player_obj->coords, &GwPlayer[GwCommon.boardWork[3]].player_obj->coords,
                          &GwPlayer[GwCommon.boardWork[j]].player_obj->unk_18);
        }
        func_8004CCD0(&D_80110448_YoshisTropicalIslandEndingScene[5]->coords, &GwPlayer[GwCommon.boardWork[3]].player_obj->coords, &D_80110448_YoshisTropicalIslandEndingScene[5]->unk_18);
        func_8004CCD0(&D_80110448_YoshisTropicalIslandEndingScene[6]->coords, &GwPlayer[GwCommon.boardWork[3]].player_obj->coords, &D_80110448_YoshisTropicalIslandEndingScene[6]->unk_18);
        func_8004CCD0(&D_80110448_YoshisTropicalIslandEndingScene[2]->coords, &GwPlayer[GwCommon.boardWork[3]].player_obj->coords, &D_80110448_YoshisTropicalIslandEndingScene[2]->unk_18);
        if (t > 30.0f && D_80110300_YoshisTropicalIslandEndingScene[11] == NULL) {
            func_800A0D00(&D_8010E7B0_YoshisTropicalIslandEndingScene[0].pos, spE0.x, spE0.y, spE0.z);
            D_80110300_YoshisTropicalIslandEndingScene[11] = func_800FEE24_YoshisTropicalIslandEndingScene(0xB, 2, 0);
        } else if (t > 60.0f && D_80110300_YoshisTropicalIslandEndingScene[12] == NULL) {
            func_800A0D00(&D_8010E7B0_YoshisTropicalIslandEndingScene[1].pos, spE0.x, spE0.y, spE0.z);
            D_80110300_YoshisTropicalIslandEndingScene[12] = func_800FEE24_YoshisTropicalIslandEndingScene(0xC, 2, 1);
        }
        t += 2.5f;
    } while (t <= 100.0f);
    do {
        HuPrcSleep(0);
    } while (D_80110300_YoshisTropicalIslandEndingScene[12]->work[1] != 0);
    func_800FEFE0_YoshisTropicalIslandEndingScene(0xB);
    func_800FEFE0_YoshisTropicalIslandEndingScene(0xC);
    func_80052FD4(GwCommon.boardWork[3]);
    func_8004B7F8(0xFF);
    func_8002578C(1);
    func_800FFEBC_YoshisTropicalIslandEndingScene(sp58, sp18);
    HuPrcSleep(3);
    func_800FFF08_YoshisTropicalIslandEndingScene(sp58, sp18);
    HuPrcSleep(1);
    func_8001ABA0(3);
    for (j = 0; j < 3; j++) {
        func_8004EE14(GwCommon.boardWork[j], D_800F32A0, 8, NULL);
    }
    func_8004EE14(0, D_800F32A0, 8, D_80110448_YoshisTropicalIslandEndingScene[5]);
    func_8004EE14(0, D_800F32A0, 8, D_80110448_YoshisTropicalIslandEndingScene[6]);
    func_8004EE14(0, D_800F32A0, 8, D_80110448_YoshisTropicalIslandEndingScene[2]);
    HuPrcSleep(8);
    D_80110448_YoshisTropicalIslandEndingScene[7] = func_800FF1E4_YoshisTropicalIslandEndingScene(&D_8010E830_YoshisTropicalIslandEndingScene[7]);
    D_80110448_YoshisTropicalIslandEndingScene[3] = func_800FF1E4_YoshisTropicalIslandEndingScene(&D_8010E830_YoshisTropicalIslandEndingScene[3]);
    D_80110448_YoshisTropicalIslandEndingScene[4] = func_800FF1E4_YoshisTropicalIslandEndingScene(&D_8010E830_YoshisTropicalIslandEndingScene[4]);
    MBMotionSet(D_80110448_YoshisTropicalIslandEndingScene[3], 0, 2);
    func_8004F140(*D_80110448_YoshisTropicalIslandEndingScene[3]->unk_3C->unk_40);
    D_80110300_YoshisTropicalIslandEndingScene[4] = func_800FE730_YoshisTropicalIslandEndingScene(4, D_8010E830_YoshisTropicalIslandEndingScene[4].pos.y, 0.0f);
    D_80110300_YoshisTropicalIslandEndingScene[4]->work[0] = 4;
    D_80110300_YoshisTropicalIslandEndingScene[7] = func_800FE9B8_YoshisTropicalIslandEndingScene(7, D_8010E830_YoshisTropicalIslandEndingScene[7].pos.y, 0.0f);
    D_80110300_YoshisTropicalIslandEndingScene[7]->work[0] = 7;
    D_80110448_YoshisTropicalIslandEndingScene[7]->unk_0A |= 1;
    func_80021240(*D_80110448_YoshisTropicalIslandEndingScene[7]->unk_3C->unk_40);
    D_80110448_YoshisTropicalIslandEndingScene[3]->coords.x = D_8010E830_YoshisTropicalIslandEndingScene[3].pos.x - 400.0f;
    func_8004CCD0(&D_80110448_YoshisTropicalIslandEndingScene[3]->coords, &D_8010E830_YoshisTropicalIslandEndingScene[3].pos, &D_80110448_YoshisTropicalIslandEndingScene[3]->unk_18);
    func_8004F4D4(GwPlayer[GwCommon.boardWork[0]].player_obj, 0, 2);
    spF0 = D_8010F2B4_YoshisTropicalIslandEndingScene;
    func_8004E3E0(0, &spF0, 0x50, D_80110448_YoshisTropicalIslandEndingScene[0]);
    func_8004EE14(0, D_800F32A0, 0x50, D_80110448_YoshisTropicalIslandEndingScene[0]);
    D_80110400_YoshisTropicalIslandEndingScene[0] = func_80042728(D_80110448_YoshisTropicalIslandEndingScene[0], 1);
    func_800A0D00(&sp100, GwPlayer[GwCommon.boardWork[0]].player_obj->coords.x, GwPlayer[GwCommon.boardWork[0]].player_obj->coords.y,
                  GwPlayer[GwCommon.boardWork[0]].player_obj->coords.z);
    func_800A0D00(&sp110, 0.0f, 0.0f, 2165.0f);
    for (j = 0; j < 0x51; j++) {
        t = j * 0.0125f;
        v = (1.0f - t) * 255.0f;
        func_800211BC(*D_80110448_YoshisTropicalIslandEndingScene[7]->unk_3C->unk_40, v);
        v = (1.0f - func_800B1750(t)) * 500.0f;
        D_80110300_YoshisTropicalIslandEndingScene[4]->rot.y = v + D_8010E830_YoshisTropicalIslandEndingScene[4].pos.y;
        v = (1.0f - t) * -400.0f;
        D_80110448_YoshisTropicalIslandEndingScene[3]->coords.x = v + D_8010E830_YoshisTropicalIslandEndingScene[3].pos.x;
        func_800A0D00(&GwPlayer[GwCommon.boardWork[0]].player_obj->coords, ((sp110.x - sp100.x) * t) + sp100.x,
                      ((sp110.y - sp100.y) * t) + sp100.y, ((sp110.z - sp100.z) * t) + sp100.z);
        HuPrcSleep(0);
    }
    D_80110300_YoshisTropicalIslandEndingScene[0] = func_800FE86C_YoshisTropicalIslandEndingScene(0);
    MBMotionShiftSet(D_80110448_YoshisTropicalIslandEndingScene[3], -1, 0, 8, 2);
    func_8004EE14(0, D_800F32A0, 8, D_80110448_YoshisTropicalIslandEndingScene[3]);
    func_8004F4D4(GwPlayer[GwCommon.boardWork[0]].player_obj, 1, 0);
}
void func_801022E8_YoshisTropicalIslandEndingScene(void) {
    D_8010F878_YoshisTropicalIslandEndingScene = 1;
    HuPrcSleep(3);
    func_8010024C_YoshisTropicalIslandEndingScene();
    HuPrcSleep(3);
    func_80100268_YoshisTropicalIslandEndingScene();
    D_8010F878_YoshisTropicalIslandEndingScene = 0;
    D_8010F874_YoshisTropicalIslandEndingScene = 0;
    HuPrcSleep(3);
    func_801005C0_YoshisTropicalIslandEndingScene();
    HuPrcSleep(3);
    func_8010087C_YoshisTropicalIslandEndingScene();
    HuPrcSleep(3);
    func_8010102C_YoshisTropicalIslandEndingScene();
    HuPrcSleep(3);
    func_8010151C_YoshisTropicalIslandEndingScene();
}
