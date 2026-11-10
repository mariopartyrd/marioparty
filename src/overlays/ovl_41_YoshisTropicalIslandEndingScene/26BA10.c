#include "ending.h"

/* 26BA10: one board's ending scene (func_8010329C) and its helpers */

/* A model the scene places: MBModelCreate(id, list) at pos */
typedef struct EndingModelDef {
    /* 0x00 */ s32 id;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ void* list;
} EndingModelDef; /* N64 size 0x14 */


extern Vec3f D_80110180_YoshisTropicalIslandEndingScene[4]; /* camera: eye, at, up, spare (bss) */

f32 func_80022D9C(f32* vals, f32* times, f32 t);
void func_80052DC8(s16 index, void* list);
void func_80028C64(s16 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4);
void func_8004B1B8(void);
void func_8004F584(s32);
s32 func_8004F628(s32, u16, s16, s16);
void func_8004F7C0(s32, f32, f32);
void func_8004FAB8(s32);

void func_80102380_YoshisTropicalIslandEndingScene(omObjData* obj);
void func_80102598_YoshisTropicalIslandEndingScene(omObjData* obj);
void func_8010262C_YoshisTropicalIslandEndingScene(omObjData* obj);
void func_80102760_YoshisTropicalIslandEndingScene(omObjData* obj);
void func_80102AE4_YoshisTropicalIslandEndingScene(omObjData* obj);
omObjData* func_80102BAC_YoshisTropicalIslandEndingScene(u8 idx);
void func_80102C14_YoshisTropicalIslandEndingScene(void);
void func_80102FB4_YoshisTropicalIslandEndingScene(omObjData* obj);
omObjData* func_801031C8_YoshisTropicalIslandEndingScene(s32 idx, f32 y, f32 z);
void func_8010444C_YoshisTropicalIslandEndingScene(void);
void func_80102B18_YoshisTropicalIslandEndingScene(omObjData* obj);
void func_80102F54_YoshisTropicalIslandEndingScene(omObjData* obj);
void func_80103044_YoshisTropicalIslandEndingScene(omObjData* obj);
void func_8010400C_YoshisTropicalIslandEndingScene(omObjData* obj);
void func_801040B8_YoshisTropicalIslandEndingScene(omObjData* obj);
void func_801042F0_YoshisTropicalIslandEndingScene(omObjData* obj);
Object* func_80104B9C_YoshisTropicalIslandEndingScene(struct EndingModelDef* def);
void func_80104C50_YoshisTropicalIslandEndingScene(Vec3f* pts, f32* times, f32 t, Vec3f* out);
void func_80104D24_YoshisTropicalIslandEndingScene(s16 hmf, f32 len, f32 t, Vec3f* out);

/* .data */
s32 D_8010E8F0_YoshisTropicalIslandEndingScene[5] = { 3, 0x00010097, 0x00010049, 0x00010068, 0x00010092 };
s32 D_8010E904_YoshisTropicalIslandEndingScene[5] = { 3, 0x00020097, 0x00020049, 0x00020068, 0x00020092 };
s32 D_8010E918_YoshisTropicalIslandEndingScene[5] = { 3, 0x00060097, 0x00060049, 0x00060068, 0x00060092 };
s32 D_8010E92C_YoshisTropicalIslandEndingScene[5] = { 3, 0x00030097, 0x00030049, 0x00030068, 0x00030092 };
s32 D_8010E940_YoshisTropicalIslandEndingScene[5] = { 3, 0x00040097, 0x00040049, 0x00040068, 0x00040092 };
s32 D_8010E954_YoshisTropicalIslandEndingScene[5] = { 3, 0x00050097, 0x00050049, 0x00050068, 0x00050092 };
s32 D_8010E968_YoshisTropicalIslandEndingScene[2] = { 1, 0x000A006A };
/* model lists per character */
s32* D_8010E970_YoshisTropicalIslandEndingScene[6] = {
    D_8010E8F0_YoshisTropicalIslandEndingScene, D_8010E904_YoshisTropicalIslandEndingScene,
    D_8010E918_YoshisTropicalIslandEndingScene, D_8010E92C_YoshisTropicalIslandEndingScene,
    D_8010E940_YoshisTropicalIslandEndingScene, D_8010E954_YoshisTropicalIslandEndingScene,
};
/* unreferenced model list */
s32 D_8010E988_YoshisTropicalIslandEndingScene[9] = {
    8, 0x00070002, 0x00070003, 0x00070004, 0x00070005, 0x00070006, 0x00070007, 0x00070008, 0x00070009,
};
EndingModelDef D_8010E9AC_YoshisTropicalIslandEndingScene[5] = {
    { 0x40, { 0.0f, 910.0f, 1662.5f }, NULL },
    { 0x07, { 262.5f, 225.0f, 1050.0f }, NULL },
    { 0x08, { -275.0f, 225.0f, 987.5f }, NULL },
    { 0x42, { 0.0f, 0.0f, 0.0f }, NULL },
    { 0x6D, { 262.5f, 350.0f, 912.5f }, NULL },
};

void func_80102380_YoshisTropicalIslandEndingScene(omObjData* obj) {
    switch (obj->work[0]) {
        case 0:
        case 1:
            obj->rot.x += 5.0f;
            if (obj->rot.x >= 360.0f) {
                if (obj->work[0] == 1) {
                    obj->work[0] = 2;
                }
                obj->rot.x -= 360.0f;
            }
            D_80110448_YoshisTropicalIslandEndingScene[0]->coords.x =
                sinf(obj->rot.x * M_DTOR) * 70.0f * 5.0f + obj->trans.x;
            D_80110448_YoshisTropicalIslandEndingScene[0]->coords.y = obj->trans.y;
            D_80110448_YoshisTropicalIslandEndingScene[0]->coords.z =
                (obj->trans.z - 30.0f) + cosf(obj->rot.x * M_DTOR) * 30.0f * 5.0f;
            break;
        case 2:
            obj->rot.x += 5.0f;
            if (obj->rot.x >= 360.0f) {
                obj->rot.x -= 360.0f;
            }
            D_80110448_YoshisTropicalIslandEndingScene[0]->unk_3C->unk_24 = 90.0f;
            D_80110448_YoshisTropicalIslandEndingScene[0]->unk_3C->unk28 = 0.0f;
            D_80110448_YoshisTropicalIslandEndingScene[0]->unk_3C->unk_2C = sinf(obj->rot.x * M_DTOR) * 10.0f;
            break;
    }
}

void func_80102598_YoshisTropicalIslandEndingScene(omObjData* obj) {
    f32 angle = obj->rot.y;

    angle += 10.0f;
    if (angle > 360.0f) {
        angle -= 360.0f;
    }
    D_80110448_YoshisTropicalIslandEndingScene[0]->unk_18.x = func_800AEAC0(angle);
    D_80110448_YoshisTropicalIslandEndingScene[0]->unk_18.y = 0.0f;
    D_80110448_YoshisTropicalIslandEndingScene[0]->unk_18.z = func_800AEFD0(angle);
    obj->rot.y = angle;
}

void func_8010262C_YoshisTropicalIslandEndingScene(omObjData* obj) {
    Vec3f end;
    Vec3f start;
    Vec3f pos;
    f32 t;
    f32 rate = obj->rot.x;

    if (rate > 1.0f) {
        rate = 1.0f;
        obj->work[0] = 1;
    }
    t = func_800B1750(rate);
    func_800A0D00(&start, 0.0f, 0.0f, 0.0f);
    func_800A0D00(&end, 0.0f, 300.0f, -650.0f);
    func_800A0D00(&pos, obj->trans.x, obj->trans.y, obj->trans.z);
    pos.x = (end.x - start.x) * t + start.x;
    pos.y = (end.y - start.y) * t + start.y;
    pos.z = (end.z - start.z) * t + start.z;
    D_80110448_YoshisTropicalIslandEndingScene[0]->coords.x = pos.x;
    D_80110448_YoshisTropicalIslandEndingScene[0]->coords.y = pos.y;
    D_80110448_YoshisTropicalIslandEndingScene[0]->coords.z = pos.z;
    rate += 0.02;
    obj->rot.x = rate;
}

void func_80102760_YoshisTropicalIslandEndingScene(omObjData* obj) {
    Vec3f end;
    Vec3f start;
    Vec3f pos;
    f32 t = obj->rot.x;
    f32 phase;
    f32 scale;
    f32 y;

    if (GwPlayer[GwCommon.boardWork[3]].player_obj->unk_30 <= 120.0f) {
        t = 0.0f;
        GwPlayer[GwCommon.boardWork[3]].player_obj->unk_30 = 120.0f;
        GwPlayer[GwCommon.boardWork[3]].player_obj->unk_34 = 60.0f;
        GwPlayer[GwCommon.boardWork[3]].player_obj->unk_38 = -4.0f;
        obj->work[0] = obj->work[0] == 0;
        GwPlayer[GwCommon.boardWork[3]].player_obj->unk_18.x = -GwPlayer[GwCommon.boardWork[3]].player_obj->unk_18.x;
        GwPlayer[GwCommon.boardWork[3]].player_obj->unk_18.y = -GwPlayer[GwCommon.boardWork[3]].player_obj->unk_18.y;
        GwPlayer[GwCommon.boardWork[3]].player_obj->unk_18.z = -GwPlayer[GwCommon.boardWork[3]].player_obj->unk_18.z;
    }
    t += 0.033333335f;
    if (obj->work[0] != 0) {
        func_800A0D00(&start, -1010.0f, 0.0f, -286.5f);
        func_800A0D00(&end, -860.0f, 0.0f, -262.5f);
    } else {
        func_800A0D00(&start, -860.0f, 0.0f, -262.5f);
        func_800A0D00(&end, -1010.0f, 0.0f, -286.5f);
    }
    func_800A0D00(&pos, (end.x - start.x) * t + start.x, (end.y - start.y) * t + start.y,
                  (end.z - start.z) * t + start.z);
    func_800A0D00(&GwPlayer[GwCommon.boardWork[3]].player_obj->coords, pos.x, pos.y, pos.z);
    phase = t + 0.25f;
    if (phase > 1.0f) {
        phase -= 1.0f;
    }
    if (phase < 0.25) {
        scale = (phase + 0.1f) * 24.0f;
        func_8004FA90(D_80110440_YoshisTropicalIslandEndingScene, scale, scale, scale);
        y = phase * 3.0f * 24.0f * 5.0f;
        func_8004F9F4(D_80110440_YoshisTropicalIslandEndingScene, -1010.0f, y, -286.5f, 3);
        func_8004F9F4(D_80110440_YoshisTropicalIslandEndingScene, -860.0f, y, -286.5f, 3);
    }
    obj->rot.x = t;
}

void func_80102AE4_YoshisTropicalIslandEndingScene(omObjData* obj) {
    obj->func_ptr = func_80102760_YoshisTropicalIslandEndingScene;
    obj->trans.x = obj->trans.y = obj->trans.z = obj->rot.x = obj->rot.y = obj->rot.z = 0.0f;
    obj->work[0] = 0;
}

// decomp-permuter
void func_80102B18_YoshisTropicalIslandEndingScene(omObjData *obj)
{
  u8 idx = obj->work[0];
  f32 angle = obj->rot.x;
  f32 d;
  f32 new_var;
  angle += 5.0f;
  if (angle < 360.0f)
  {
    angle -= 360.0f;
  }
  new_var = func_800AEAC0(angle);
  d = -new_var;
  D_80110448_YoshisTropicalIslandEndingScene[idx]->coords.y += d;
  obj->rot.x = angle;
}

omObjData* func_80102BAC_YoshisTropicalIslandEndingScene(u8 idx) {
    omObjData* obj = omAddObj(0x600, 0, 0, -1, func_80102B18_YoshisTropicalIslandEndingScene);

    obj->work[0] = idx;
    omSetRot(obj, 0.0f, 0.0f, 0.0f);
    return obj;
}

/* Player positions in the scene */
const Vec3f D_8010F2E0_YoshisTropicalIslandEndingScene[4] = {
    { 0.0f, 285.0f, 1662.5f },
    { -162.5f, 225.0f, 1050.0f },
    { 162.5f, 225.0f, 1037.5f },
    { 0.0f, 620.0f, 1135.0f },
};

void func_80102C14_YoshisTropicalIslandEndingScene(void) {
    Vec3f dir;
    Vec3f eye;
    Vec3f at;
    Vec3f up;
    s32 i;
    s32 j;
    u32 k;

    func_800A0D00(&eye, 0.0f, 0.0f, 4100.0f);
    func_800A0D00(&at, 0.0f, 0.0f, 0.0f);
    func_800A0D00(&up, 0.0f, 5.0f, 0.0f);
    func_8001D420(0, &eye, &at, &up);
    func_8001D57C(0);
    func_800A0D50(&dir, &eye);
    for (i = 0; i < 4; i++) {
        if (GwCommon.boardWork[3] != i) {
            func_80052DC8(i, D_8010E970_YoshisTropicalIslandEndingScene[GwPlayer[i].character]);
            func_80021B14(*GwPlayer[i].player_obj->unk_3C->unk_40, GwPlayer[i].character, 0);
            func_800258EC(*GwPlayer[i].player_obj->unk_40->unk_40, 0x180, 0x80);
            func_80025AD4(*GwPlayer[i].player_obj->unk_40->unk_40);
            GwPlayer[i].flags |= 2;
        }
    }
    for (j = 0; j < 3; j++) {
        s16* p = &GwCommon.boardWork[j];
        func_800A0D50(&GwPlayer[*p].player_obj->coords, (Vec3f*)&D_8010F2E0_YoshisTropicalIslandEndingScene[j]);
        func_800A0D00((Vec3f*)&GwPlayer[*p].player_obj->xScale, 1.0f, 1.0f, 1.0f);
        func_8004CCD0(&GwPlayer[*p].player_obj->coords, &dir, &GwPlayer[*p].player_obj->unk_18);
    }
    for (k = 0; k < 5; k++) {
        if (D_8010E9AC_YoshisTropicalIslandEndingScene[k].id == 0x42) {
            D_80110448_YoshisTropicalIslandEndingScene[k] = MBModelCreate(0x42, NULL);
            func_80025F60(*D_80110448_YoshisTropicalIslandEndingScene[k]->unk_3C->unk_40, 0);
            D_80110448_YoshisTropicalIslandEndingScene[k]->unk_0A |= 1;
        } else {
            D_80110448_YoshisTropicalIslandEndingScene[k] =
                func_80104B9C_YoshisTropicalIslandEndingScene(&D_8010E9AC_YoshisTropicalIslandEndingScene[k]);
        }
        func_8004CCD0(&D_80110448_YoshisTropicalIslandEndingScene[k]->coords, &dir,
                      &D_80110448_YoshisTropicalIslandEndingScene[k]->unk_18);
    }
    func_8004F140(*D_80110448_YoshisTropicalIslandEndingScene[2]->unk_3C->unk_40);
    MBModelDispOff(D_80110448_YoshisTropicalIslandEndingScene[4]);
    MBModelDispOff(D_80110448_YoshisTropicalIslandEndingScene[0]);
}

// retail keeps a dead copy of the argument in $s0 (frame 0x20 vs 0x18; masked 5); calls identical;
// direct array addresses and the permuter's best (10) tried
#ifdef NON_MATCHING
void func_80102F54_YoshisTropicalIslandEndingScene(omObjData* obj) {
    Vec3f* cam = D_80110180_YoshisTropicalIslandEndingScene;

    func_8001D494(0, 30.0f, 80.0f, 8000.0f);
    func_8001D420(0, &cam[0], &cam[1], &cam[2]);
    func_8001D57C(0);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/26BA10", func_80102F54_YoshisTropicalIslandEndingScene);
#endif

void func_80102FB4_YoshisTropicalIslandEndingScene(omObjData* obj) {
    Vec3f* cam = D_80110180_YoshisTropicalIslandEndingScene;

    obj->func_ptr = func_80102F54_YoshisTropicalIslandEndingScene;
    if (obj->work[0] == 0xFF) {
        func_800A0D00(&cam[0], 0.0f, 410.0f, 4100.0f);
        func_800A0D00(&cam[1], 0.0f, 0.0f, 0.0f);
        func_800A0D00(&cam[2], 0.0f, 1.0f, 0.0f);
        func_800A0D00(&cam[3], 0.0f, 0.0f, 0.0f);
    }
}

void func_80103044_YoshisTropicalIslandEndingScene(omObjData* obj) {
    u8 idx = obj->work[0];
    f32 angle = obj->trans.x;
    f32 fade = obj->rot.x;
    f32 bob;

    if (fade > 1.0f) {
        fade = 1.0f;
    }
    func_800211BC(*D_80110448_YoshisTropicalIslandEndingScene[obj->work[0]]->unk_3C->unk_40,
                  (u32)((1.0f - fade) * 255.0f));
    obj->rot.x = fade + 0.015625f;
    angle += 5.0f;
    /* retail: the wrap test is inverted (< instead of >=) */
    if (angle < 360.0f) {
        angle -= 360.0f;
    }
    bob = func_800AEAC0(angle) * 25.0f;
    D_80110448_YoshisTropicalIslandEndingScene[idx]->coords.y = obj->rot.z;
    D_80110448_YoshisTropicalIslandEndingScene[idx]->unk_30 = (bob + obj->rot.y) - obj->rot.z;
    obj->trans.x = angle;
}

omObjData* func_801031C8_YoshisTropicalIslandEndingScene(s32 idx, f32 y, f32 z) {
    omObjData* obj = omAddObj(0x600, 0, 0, -1, func_80103044_YoshisTropicalIslandEndingScene);

    obj->work[0] = idx;
    MBModelDispOn(D_80110448_YoshisTropicalIslandEndingScene[idx]);
    D_80110448_YoshisTropicalIslandEndingScene[idx]->unk_0A |= 1;
    func_80021240(*D_80110448_YoshisTropicalIslandEndingScene[idx]->unk_3C->unk_40);
    omSetRot(obj, 0.0f, y, z);
    omSetTra(obj, 0.0f, 0.0f, 0.0f);
    return obj;
}

const Vec3f D_8010F310_YoshisTropicalIslandEndingScene = { 0.0f, 610.0f, 1662.5f };

// wait loop: beqzl vs beqz (a0 = 0 in the delay slot either way; masked 2)
#ifdef NON_MATCHING
void func_8010329C_YoshisTropicalIslandEndingScene(void) {
    Vec3f focus;
    Vec3f pt;
    Vec3f focus2;
    Vec3f focus3;
    Vec3f a;
    Vec3f b;
    Vec3f c;
    Vec3f eye;
    Vec3f* cam = D_80110180_YoshisTropicalIslandEndingScene;
    f32 angle;
    f32 speed;
    f32 t;
    f32 s;
    s32 i;
    s32 j;
    s32 wait;
    s32 msg;

    HuPrcSleep(3);
    func_8010444C_YoshisTropicalIslandEndingScene();
    HuPrcSleep(3);

    /* the star rises and spins */
    LoadBackgroundIndex(0x2B);
    D_80110448_YoshisTropicalIslandEndingScene[0] = MBModelCreate(0x40, NULL);
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[0]->coords, 0.0f, 300.0f, 0.0f);
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[0]->unk_18, 0.0f, 0.0f, 1.0f);
    func_800A0D00((Vec3f*)&D_80110448_YoshisTropicalIslandEndingScene[0]->xScale, 0.75f, 0.75f, 0.75f);
    D_80110300_YoshisTropicalIslandEndingScene[0] = omAddObj(0x1000, 0, 0, -1, func_80102380_YoshisTropicalIslandEndingScene);
    D_80110300_YoshisTropicalIslandEndingScene[0]->trans.x = 0.0f;
    D_80110300_YoshisTropicalIslandEndingScene[0]->trans.y = 0.0f;
    D_80110300_YoshisTropicalIslandEndingScene[0]->trans.z = 0.0f;
    D_80110300_YoshisTropicalIslandEndingScene[0]->rot.x = 0.0f;
    D_80110300_YoshisTropicalIslandEndingScene[0]->rot.y = 0.0f;
    D_80110300_YoshisTropicalIslandEndingScene[0]->rot.z = 0.0f;
    D_80110300_YoshisTropicalIslandEndingScene[0]->work[0] = 3;
    D_80110300_YoshisTropicalIslandEndingScene[1] = omAddObj(0x1000, 0, 0, -1, func_80102598_YoshisTropicalIslandEndingScene);
    D_80110300_YoshisTropicalIslandEndingScene[1]->rot.y = 0.0f;
    D_80110300_YoshisTropicalIslandEndingScene[2] = omAddObj(0x1000, 0, 0, -1, func_8010262C_YoshisTropicalIslandEndingScene);
    D_80110300_YoshisTropicalIslandEndingScene[2]->rot.x = 0.0f;
    D_80110300_YoshisTropicalIslandEndingScene[2]->work[0] = 0;
    D_80110400_YoshisTropicalIslandEndingScene[0] = func_80042728(D_80110448_YoshisTropicalIslandEndingScene[0], 1);
    D_80110448_YoshisTropicalIslandEndingScene[1] = MBModelCreate(0x34, NULL);
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[1]->coords, -360.0f, 205.0f, -1065.0f);
    D_80110448_YoshisTropicalIslandEndingScene[2] = MBModelCreate(0x34, NULL);
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[2]->coords, 360.0f, 205.0f, -1065.0f);
    for (i = 0; i < D_80110448_YoshisTropicalIslandEndingScene[1]->unk_3C->mdlcnt; i++) {
        func_80025EB4(D_80110448_YoshisTropicalIslandEndingScene[1]->unk_3C->unk_40[i], 2, 1);
        func_80025EB4(D_80110448_YoshisTropicalIslandEndingScene[2]->unk_3C->unk_40[i], 2, 1);
    }
    func_800A0D00(&focus, 0.0f, 300.0f, -650.0f);
    func_8004B5DC(&focus);
    PlaySound(0x66);
    SetFadeInTypeAndTime(0, 0x10);
    wait = 0x10;
    do {
        HuPrcSleep(wait);
        wait = 0;
    } while (D_80110300_YoshisTropicalIslandEndingScene[2]->work[0] == 0);
    omDelObj(D_80110300_YoshisTropicalIslandEndingScene[1]);
    D_80110300_YoshisTropicalIslandEndingScene[1] = NULL;
    omDelObj(D_80110300_YoshisTropicalIslandEndingScene[2]);
    D_80110300_YoshisTropicalIslandEndingScene[2] = NULL;
    speed = 10.0f;
    angle = 360.0f;
    do {
        D_80110448_YoshisTropicalIslandEndingScene[0]->unk_18.x = func_800AEAC0(angle);
        D_80110448_YoshisTropicalIslandEndingScene[0]->unk_18.y = 0.0f;
        D_80110448_YoshisTropicalIslandEndingScene[0]->unk_18.z = func_800AEFD0(angle);
        angle += speed;
        speed -= 0.05f;
        HuPrcSleep(0);
    } while (angle <= 360.0f);
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[0]->unk_18, 0.0f, 0.0f, 1.0f);
    HuPrcSleep(0x14);
    PlaySound(0x68);
    func_80072724(0xFF, 0xFF, 0xFF);
    func_800726AC(0, 0);
    HuPrcSleep(0x10);
    PlaySound(0x69);
    for (i = 0; i < D_80110448_YoshisTropicalIslandEndingScene[1]->unk_3C->mdlcnt; i++) {
        func_80025EB4(D_80110448_YoshisTropicalIslandEndingScene[1]->unk_3C->unk_40[i], 1, 2);
        func_80025EB4(D_80110448_YoshisTropicalIslandEndingScene[2]->unk_3C->unk_40[i], 1, 2);
    }
    msg = func_8004F628(0xA015A, 0xA, 0xA0, 0xB0);
    func_8004F7C0(msg, 1.0f, 1.0f);
    SetFadeInTypeAndTime(0, 0x10);
    HuPrcSleep(0x10);
    HuPrcSleep(0x2E);
    func_80060128(2);
    HuPrcSleep(0xE);
    func_800726AC(0, 5);
    HuPrcSleep(5);
    func_8004F584(msg);
    func_8004A140();
    func_800F6B54_YoshisTropicalIslandEndingScene();
    HuPrcSleep(3);

    /* the winner on the island; the camera follows two paths */
    LoadBackgroundIndex(0x2A);
    D_80110448_YoshisTropicalIslandEndingScene[0] = MBModelCreate(0x42, NULL);
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[0]->coords, 0.0f, 0.0f, 0.0f);
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[0]->unk_18, 0.0f, 0.0f, 1.0f);
    func_800A0D00((Vec3f*)&D_80110448_YoshisTropicalIslandEndingScene[0]->xScale, 1.0f, 1.0f, 1.0f);
    func_80025F60(*D_80110448_YoshisTropicalIslandEndingScene[0]->unk_3C->unk_40, 0);
    func_80052DC8(GwCommon.boardWork[0], D_8010E970_YoshisTropicalIslandEndingScene[GwPlayer[GwCommon.boardWork[0]].character]);
    func_80021B14(*GwPlayer[GwCommon.boardWork[0]].player_obj->unk_3C->unk_40, GwPlayer[GwCommon.boardWork[0]].character, 0);
    func_800258EC(*GwPlayer[GwCommon.boardWork[0]].player_obj->unk_40->unk_40, 0x180, 0x80);
    func_80025AD4(*GwPlayer[GwCommon.boardWork[0]].player_obj->unk_40->unk_40);
    func_800A0D00(&GwPlayer[GwCommon.boardWork[0]].player_obj->coords, 0.0f, 285.0f, 1662.5f);
    HuPrcSleep(3);
    func_8004B1B8();
    D_80110300_YoshisTropicalIslandEndingScene[0] = omAddObj(0x1000, 0, 0, -1, func_80102FB4_YoshisTropicalIslandEndingScene);
    D_80110300_YoshisTropicalIslandEndingScene[0]->work[0] = 0;
    func_800A0D00(&cam[0], 0.0f, 410.0f, 4100.0f);
    func_800A0D00(&cam[1], 0.0f, 25.0f, -1000.0f);
    func_800A0D00(&cam[2], 0.0f, 1.0f, 0.0f);
    func_800A0D00(&cam[3], 0.0f, 0.0f, 0.0f);
    D_801102B8_YoshisTropicalIslandEndingScene[3] = LoadFormFile(0xA00D2, 0x2AD);
    D_801102B8_YoshisTropicalIslandEndingScene[4] = LoadFormFile(0xA00D3, 0x2AD);
    SetFadeInTypeAndTime(0, 0x10);
    for (j = 10; j < 0x18D; j++) {
        if (j == 11) {
            HuPrcSleep(0x28);
        }
        func_80104D24_YoshisTropicalIslandEndingScene((s16)D_801102B8_YoshisTropicalIslandEndingScene[3], 400.0f, j, &pt);
        func_800A0D00(&cam[0], pt.x, pt.y, pt.z);
        func_80104D24_YoshisTropicalIslandEndingScene((s16)D_801102B8_YoshisTropicalIslandEndingScene[4], 400.0f, j, &pt);
        func_800A0D00(&cam[1], pt.x, pt.y, pt.z);
        if (j == 0x176) {
            func_800726AC(0, 0x14);
        }
        HuPrcSleep(0);
    }
    HuPrcSleep(4);
    omDelObj(D_80110300_YoshisTropicalIslandEndingScene[0]);
    D_80110300_YoshisTropicalIslandEndingScene[0] = NULL;
    func_8004A140();
    func_800F6B54_YoshisTropicalIslandEndingScene();
    HuPrcSleep(3);

    /* the player walks past the effects */
    LoadBackgroundIndex(0x27);
    func_800A0D00(&focus2, -800.0f, 0.0f, -286.5f);
    func_8004B5DC(&focus2);
    D_80110448_YoshisTropicalIslandEndingScene[1] = MBModelCreate(6, D_8010E968_YoshisTropicalIslandEndingScene);
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[1]->coords, -400.0f, 0.0f, -286.5f);
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[1]->unk_18, -5.0f, 0.0f, 0.0f);
    func_800A0D00((Vec3f*)&D_80110448_YoshisTropicalIslandEndingScene[1]->xScale, 1.0f, 1.0f, 1.0f);
    MBMotionSet(D_80110448_YoshisTropicalIslandEndingScene[1], 0, 2);
    func_80052DC8(GwCommon.boardWork[3], D_8010E970_YoshisTropicalIslandEndingScene[GwPlayer[GwCommon.boardWork[3]].character]);
    func_800A0D00(&GwPlayer[GwCommon.boardWork[3]].player_obj->coords, -1010.0f, 0.0f, -286.5f);
    func_800A0D00(&GwPlayer[GwCommon.boardWork[3]].player_obj->unk_18, -1.0f, 0.0f, 0.0f);
    GwPlayer[GwCommon.boardWork[3]].flags |= 2;
    func_8004F4D4(GwPlayer[GwCommon.boardWork[3]].player_obj, 1, 2);
    func_8004FAB8(D_80110440_YoshisTropicalIslandEndingScene);
    D_80110440_YoshisTropicalIslandEndingScene = func_8004F954(0x26, 0x20);
    func_8004FA90(D_80110440_YoshisTropicalIslandEndingScene, 5.0f, 5.0f, 5.0f);
    D_80110300_YoshisTropicalIslandEndingScene[0] = omAddObj(0x1000, 0, 0, -1, func_80102AE4_YoshisTropicalIslandEndingScene);
    HuPrcSleep(0x14);
    SetFadeInTypeAndTime(1, 0x10);
    HuPrcSleep(0x10);
    HuPrcSleep(0x5A);
    func_800726AC(1, 0x14);
    HuPrcSleep(0x14);
    func_8004A140();
    func_800F6B54_YoshisTropicalIslandEndingScene();
    HuPrcSleep(3);

    /* everyone on the island; the camera pulls back */
    LoadBackgroundIndex(0x2A);
    func_800A0D00(&focus3, 0.0f, 0.0f, 0.0f);
    func_8004B5DC(&focus3);
    func_80102C14_YoshisTropicalIslandEndingScene();
    HuPrcSleep(3);
    func_8004B1B8();
    func_8001D494(0, 30.0f, 200.0f, 36000.0f);
    D_80110300_YoshisTropicalIslandEndingScene[0] = omAddObj(0x1000, 0, 0, -1, func_80102FB4_YoshisTropicalIslandEndingScene);
    D_80110300_YoshisTropicalIslandEndingScene[0]->work[0] = 0;
    func_800A0D00(&cam[0], 0.0f, 560.0f, 4200.0f);
    func_800A0D00(&cam[1], 0.0f, 25.0f, -1000.0f);
    func_800A0D00(&cam[2], 0.0f, 1.0f, 0.0f);
    func_800A0D00(&cam[3], 0.0f, 0.0f, 0.0f);
    SetFadeInTypeAndTime(0, 0x10);
    t = 0.2f;
    while (1) {
        s = func_800B1750(t);
        if (s > 1.0f) {
            s = 1.0f;
        }
        func_800A0D00(&a, 0.0f, 610.0f, 3700.0f);
        func_800A0D00(&b, 0.0f, 0.0f, 4200.0f);
        func_800A0D00(&c, 0.0f, 0.0f, -5400.0f);
        func_800A0D00(&eye, s * c.x + b.x + a.x, s * c.y + b.y + a.y, s * c.z + b.z + a.z);
        func_800A0D00(&cam[0], eye.x, eye.y, eye.z);
        t += 0.0125f;
        if (t > 1.0f) {
            break;
        }
        HuPrcSleep(0);
    }
    D_80110300_YoshisTropicalIslandEndingScene[14] =
        func_801031C8_YoshisTropicalIslandEndingScene(4, D_80110448_YoshisTropicalIslandEndingScene[4]->coords.y, 0.0f);
    a = D_8010F310_YoshisTropicalIslandEndingScene;
    func_8004E3E0(0, &a, 0x3C, D_80110448_YoshisTropicalIslandEndingScene[0]);
    D_80110400_YoshisTropicalIslandEndingScene[0] = func_80042728(D_80110448_YoshisTropicalIslandEndingScene[0], 1);
    MBModelDispOn(D_80110448_YoshisTropicalIslandEndingScene[0]);
    D_80110300_YoshisTropicalIslandEndingScene[0] = func_80102BAC_YoshisTropicalIslandEndingScene(0);
    HuPrcSleep(0x3C);
    func_8004F4D4(GwPlayer[GwCommon.boardWork[0]].player_obj, 0, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/26BA10", func_8010329C_YoshisTropicalIslandEndingScene);
#endif

void func_8010400C_YoshisTropicalIslandEndingScene(omObjData* obj) {
    obj->rot.x += 5.0f;
    if (obj->rot.x >= 360.0f) {
        obj->rot.x -= 360.0f;
    }
    D_80110448_YoshisTropicalIslandEndingScene[0]->unk_18.x = sinf(obj->rot.x * M_DTOR) * 0.2f;
    D_80110448_YoshisTropicalIslandEndingScene[0]->unk_18.z = 1.0f;
}

void func_801040B8_YoshisTropicalIslandEndingScene(omObjData* obj) {
    s32 count = D_8010DC90_YoshisTropicalIslandEndingScene[GwSystem.unk_00];
    s32 i;
    f32 angle;
    f32 x;

    for (i = 0; i < obj->trans.y; i++) {
        angle = (360 / count) * i;
        x = sinf((angle + obj->rot.y) * M_DTOR) * obj->trans.x + D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].x;
        func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[i]->coords, x, D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].y,
                      cosf((angle + obj->rot.y) * M_DTOR) * obj->trans.x + D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].z);
        func_800A0D00((Vec3f*)&D_80110448_YoshisTropicalIslandEndingScene[i]->xScale, obj->scale.x, obj->scale.x,
                      obj->scale.x);
    }
    obj->rot.y -= 2.0f;
    if (obj->rot.y <= 0.0f) {
        obj->rot.y += 360.0f;
    }
    obj->work[0]++;
}

void func_801042F0_YoshisTropicalIslandEndingScene(omObjData* obj) {
    Vec3f base;
    Vec3f pos;
    f32 t = obj->trans.x;
    f32 s;

    if (!(t > 100.0f)) {
        func_800A0D00(&base, 0.0f, 0.0f, 0.0f);
        func_800A0D00(&pos, base.x * 5.0f, base.y * 5.0f, (base.z - t * 0.75f) * 5.0f);
        func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[0]->coords, pos.x, pos.y, pos.z);
        s = (100.0f - t) * 0.8f * 0.01f;
        s = (s * s + 0.35999995f) * 6.0f;
        func_800A0D00((Vec3f*)&D_80110448_YoshisTropicalIslandEndingScene[0]->xScale, s, s, s);
        t += 5.0f;
        obj->trans.x = t;
    }
}

void func_8010444C_YoshisTropicalIslandEndingScene(void) {
    s32 count = D_8010DC90_YoshisTropicalIslandEndingScene[GwSystem.unk_00];
    f32 radius = D_8010DCFC_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene];
    f32 angle;
    f32 x;
    s32 i;
    omObjData* ring;

    for (i = 0; i < count; i++) {
        D_80110448_YoshisTropicalIslandEndingScene[i] = MBModelCreate(0x25, NULL);
        angle = (360 / count) * i * M_DTOR;
        x = sinf(angle) * radius + D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].x;
        func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[i]->coords, x, D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].y,
                      cosf(angle) * radius + D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].z);
        /* retail: writes the scale into coords */
        func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[i]->coords,
                      D_8010DD1C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene],
                      D_8010DD1C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene],
                      D_8010DD1C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene]);
        D_80110400_YoshisTropicalIslandEndingScene[i] = func_80042728(D_80110448_YoshisTropicalIslandEndingScene[i], 1);
    }
    ring = omAddObj(0x1000, 0, 0, -1, func_801040B8_YoshisTropicalIslandEndingScene);
    ring->rot.y = 0.0f;
    ring->trans.x = radius;
    ring->trans.y = count;
    ring->scale.x = D_8010DD1C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene];
    ring->work[0] = 0;
    LoadBackgroundIndex(0x2D);
    func_80072724(0xFF, 0xFF, 0xFF);
    SetFadeInTypeAndTime(2, 0x18);
    PlaySound(0x48);
    HuPrcSleep(0x36);
    while (radius >= 350.0f) {
        ring->trans.x = radius;
        if (radius - 10.0f < 350.0f) {
            func_80072724(0xFF, 0xFF, 0xFF);
            func_800726AC(0, 0);
            PlaySound(0x4B);
        }
        HuPrcVSleep();
        radius -= 10.0f;
    }
    HuPrcSleep(5);
    for (i = 0; i < count; i++) {
        MBModelKill(D_80110448_YoshisTropicalIslandEndingScene[i]);
        D_80110448_YoshisTropicalIslandEndingScene[i] = NULL;
        func_800427D4(D_80110400_YoshisTropicalIslandEndingScene[i]);
        D_80110400_YoshisTropicalIslandEndingScene[i] = NULL;
    }
    D_80110448_YoshisTropicalIslandEndingScene[0] = MBModelCreate(0x25, NULL);
    D_80110400_YoshisTropicalIslandEndingScene[0] = func_80042728(D_80110448_YoshisTropicalIslandEndingScene[0], 1);
    func_800258EC(*D_80110448_YoshisTropicalIslandEndingScene[0]->unk_3C->unk_40, 0x10000, 0x10000);
    i = 0xF8;
    func_80025AD4(*D_80110448_YoshisTropicalIslandEndingScene[0]->unk_3C->unk_40);
    func_80028C64(*D_80110448_YoshisTropicalIslandEndingScene[0]->unk_3C->unk_40, 0xFF, 0xFF, 0xFF, 0xFF);
    D_80110448_YoshisTropicalIslandEndingScene[0]->xScale = 2.0f * D_8010DD1C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene];
    D_80110448_YoshisTropicalIslandEndingScene[0]->yScale = 2.0f * D_8010DD1C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene];
    D_80110448_YoshisTropicalIslandEndingScene[0]->zScale = 2.0f * D_8010DD1C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene];
    D_80110448_YoshisTropicalIslandEndingScene[0]->coords.x = D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].x;
    D_80110448_YoshisTropicalIslandEndingScene[0]->coords.y = D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].y;
    D_80110448_YoshisTropicalIslandEndingScene[0]->coords.z = D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].z;
    omDelObj(ring);
    ring = omAddObj(0x1000, 0, 0, -1, func_8010400C_YoshisTropicalIslandEndingScene);
    ring->rot.x = 0.0f;
    HuPrcSleep(5);
    SetFadeInTypeAndTime(0, 0x10);
    HuPrcSleep(0x10);
    do {
        func_80028C64(*D_80110448_YoshisTropicalIslandEndingScene[0]->unk_3C->unk_40, i, i, i, 0xFF);
        i -= 4;
        HuPrcVSleep();
    } while (i >= 0);
    HuPrcSleep(0x1E);
    D_80110300_YoshisTropicalIslandEndingScene[2] = omAddObj(0x1000, 0, 0, -1, func_801042F0_YoshisTropicalIslandEndingScene);
    D_80110300_YoshisTropicalIslandEndingScene[2]->trans.x = 0.0f;
    func_800726AC(0, 0x10);
    HuPrcSleep(0x10);
    omDelObj(D_80110300_YoshisTropicalIslandEndingScene[2]);
    D_80110300_YoshisTropicalIslandEndingScene[2] = NULL;
    omDelObj(ring);
    MBModelKill(D_80110448_YoshisTropicalIslandEndingScene[0]);
    D_80110448_YoshisTropicalIslandEndingScene[0] = NULL;
    func_800427D4(D_80110400_YoshisTropicalIslandEndingScene[0]);
    D_80110400_YoshisTropicalIslandEndingScene[0] = NULL;
    func_8004A140();
    HuPrcSleep(0xA);
}

void func_80104A14_YoshisTropicalIslandEndingScene(s16 hmf) {
    Vec3f pt;
    unk2C0C0StructC0* m = D_800F2B7C[hmf].unk_6C;
    unk2C0C0StructA0* pts = m->unk_78;
    s32 count = m->unk_6E;
    s32 i;

    osSyncPrintf("\n-- HmfID(%d) Start --", hmf);
    osSyncPrintf("\nid(%d):tx(%4.2f,%4.2f,%4.2f)", hmf, D_800F2B7C[hmf].unk_24, D_800F2B7C[hmf].unk_28,
                 D_800F2B7C[hmf].unk_2C);
    for (i = 0; i < count; i++) {
        func_800A0D00(&pt, pts[i].unk_00, pts[i].unk_02, pts[i].unk_04);
        osSyncPrintf("\n%d:(%4.2f,%4.2f,%4.2f)", i, pt.x, pt.y, pt.z);
    }
    osSyncPrintf("\n-- HmfID(%d) End --", hmf);
}

Object* func_80104B9C_YoshisTropicalIslandEndingScene(EndingModelDef* def) {
    Object* model = MBModelCreate(def->id, def->list);

    if (model->unk_40 != NULL) {
        func_80025F60(*model->unk_40->unk_40, 0);
        func_800258EC(*model->unk_40->unk_40, 0x180, 0x80);
        func_80025AD4(*model->unk_40->unk_40);
    }
    func_800A0D50(&model->coords, &def->pos);
    func_800A0D00((Vec3f*)&model->xScale, 1.0f, 1.0f, 1.0f);
    func_800A0D00(&model->unk_18, 0.0f, 0.0f, 1.0f);
    return model;
}

void func_80104C50_YoshisTropicalIslandEndingScene(Vec3f* pts, f32* times, f32 t, Vec3f* out) {
    f32 v[4][4];
    s32 i;

    for (i = 0; i < 4; i++) {
        v[0][i] = pts[i].x;
        v[1][i] = pts[i].y;
        v[2][i] = pts[i].z;
        v[3][i] = times[i];
    }
    out->x = func_80022D9C(v[0], v[3], t);
    out->y = func_80022D9C(v[1], v[3], t);
    out->z = func_80022D9C(v[2], v[3], t);
}

// decomp-permuter
void func_80104D24_YoshisTropicalIslandEndingScene(s16 hmf, f32 len, f32 t, Vec3f *out)
{
  Vec3f v[4];
  f32 times[4];
  unk2C0C0StructC0 *m = D_800F2B7C[hmf].unk_6C;
  unk2C0C0StructA0 *base = &m->unk_78[1];
  unk2C0C0StructA0 *pts;
  s32 n = m->unk_6E;
  s32 segs = n - 3;
  f32 step = len / segs;
  s32 seg = t / step;
  if ((seg + 1) >= segs)
  {
    seg = n - 4;
  }
  else
    if (seg < 0)
  {
    seg = -1;
  }
  pts = &base[seg];
  func_800A0D00(&v[0], (&base[seg])[-1].unk_00, (&base[seg])[-1].unk_02, (&base[seg])[-1].unk_04);
  times[0] = step * (seg - 1);
  func_800A0D00(&v[1], (&base[seg])[0].unk_00, (&base[seg])[0].unk_02, (&base[seg])[0].unk_04);
  times[1] = step * seg;
  func_800A0D00(&v[2], (&base[seg])[1].unk_00, (&base[seg])[1].unk_02, (&base[seg])[1].unk_04);
  times[2] = step * (seg + 1);
  func_800A0D00(&v[3], (&base[seg])[2].unk_00, (&base[seg])[2].unk_02, (&base[seg])[2].unk_04);
  times[3] = step * (seg + 2);
  func_80104C50_YoshisTropicalIslandEndingScene(v, times, t, out);
}
