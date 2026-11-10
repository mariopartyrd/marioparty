#include "2721F0.h"

/* .data */
s32 D_8010EB80_YoshisTropicalIslandEndingScene[10] = { 9, 0x00010000, 0x00010001, 0x00010003, 0x00010004, 0x00010005, 0x00010039, 0x00010097, 0x00010096, 0x00010018 };
s32 D_8010EBA8_YoshisTropicalIslandEndingScene[10] = { 9, 0x00020000, 0x00020001, 0x00020003, 0x00020004, 0x00020005, 0x00020039, 0x00020097, 0x00020096, 0x00020018 };
s32 D_8010EBD0_YoshisTropicalIslandEndingScene[10] = { 9, 0x00060000, 0x00060001, 0x00060003, 0x00060004, 0x00060005, 0x00060039, 0x00060097, 0x00060096, 0x00060018 };
s32 D_8010EBF8_YoshisTropicalIslandEndingScene[10] = { 9, 0x00030000, 0x00030001, 0x00030003, 0x00030004, 0x00030005, 0x00030039, 0x00030097, 0x00030096, 0x00030018 };
s32 D_8010EC20_YoshisTropicalIslandEndingScene[10] = { 9, 0x00040000, 0x00040001, 0x00040003, 0x00040004, 0x00040005, 0x00040039, 0x00040097, 0x00040096, 0x00040018 };
s32 D_8010EC48_YoshisTropicalIslandEndingScene[10] = { 9, 0x00050000, 0x00050001, 0x00050003, 0x00050004, 0x00050005, 0x00050039, 0x00050097, 0x00050096, 0x00050018 };
s32 D_8010EC70_YoshisTropicalIslandEndingScene[5] = { 4, 0x000A0068, 0x000A0069, 0x000A006C, 0x000A006F };
/* per-character player model lists (func_80052DC8) */
s32* D_8010EC84_YoshisTropicalIslandEndingScene[6] = {
    D_8010EB80_YoshisTropicalIslandEndingScene, D_8010EBA8_YoshisTropicalIslandEndingScene,
    D_8010EBD0_YoshisTropicalIslandEndingScene, D_8010EBF8_YoshisTropicalIslandEndingScene,
    D_8010EC20_YoshisTropicalIslandEndingScene, D_8010EC48_YoshisTropicalIslandEndingScene,
};
s32 D_8010EC9C_YoshisTropicalIslandEndingScene[2] = { 1, 0x00070002 };
s32 D_8010ECA4_YoshisTropicalIslandEndingScene[2] = { 1, 0x000A0073 };
Gfx D_8010ECB0_YoshisTropicalIslandEndingScene[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_FILL),
    gsDPSetRenderMode(G_RM_NOOP, G_RM_NOOP2),
    gsDPSetFillColor(0xFFFCFFFC),
    gsDPFillRectangle(0, 0, 319, 239),
    gsSPEndDisplayList(),
};
Vec3f D_8010ECE0_YoshisTropicalIslandEndingScene = { 640.0f, 480.0f, 511.0f };
Vec3f D_8010ECEC_YoshisTropicalIslandEndingScene = { 640.0f, 480.0f, 511.0f };

/* .rodata */
#define ENDING_PLAYER_POS_REST \
    0.0f, -450.0f, \
    -805.0f, 0.0f, 1600.0f, \
    790.0f, 0.0f, -450.0f, \
    805.0f, 0.0f, 1600.0f, \
    -325.0f, 0.0f, 400.0f, \
    -265.0f, 0.0f, 800.0f, \
    325.0f, 0.0f, 400.0f, \
    265.0f, 0.0f, 800.0f, \
    -80.0f, 0.0f, 400.0f, \
    -80.0f, 0.0f, 800.0f, \
    80.0f, 0.0f, 400.0f, \
    80.0f, 0.0f, 800.0f
/* unreferenced .rodata at the head of the unit (splat put it in 26E620's D_8010F5A8) */
const s32 D_8010F5B0_YoshisTropicalIslandEndingScene[3] __attribute__((section(".rodata"))) = { 0x40, 6, -1 };
const f32 D_8010F5BC_YoshisTropicalIslandEndingScene[6] __attribute__((section(".rodata"))) = { 200.0f, 500.0f, 1800.0f, 0.0f, 450.0f, 500.0f };
const Vec3f D_8010F5D4_YoshisTropicalIslandEndingScene[12] = { -790.0f, ENDING_PLAYER_POS_REST };
const EndingModel D_8010F664_YoshisTropicalIslandEndingScene[6] = {
    { 0x40, NULL, { 0.0f, 650.0f, 800.0f } },
    { 6, D_8010EC70_YoshisTropicalIslandEndingScene, { 0.0f, 450.0f, 500.0f } },
    { 7, D_8010EC9C_YoshisTropicalIslandEndingScene, { -600.0f, 0.0f, 400.0f } },
    { 8, D_8010ECA4_YoshisTropicalIslandEndingScene, { -700.0f, 0.0f, 350.0f } },
    { 0x6D, NULL, { 790.0f, 275.0f, 0.0f } },
    { -1, NULL, { 0.0f, 0.0f, 0.0f } },
};
const EndingModel D_8010F6DC_YoshisTropicalIslandEndingScene[6] = {
    { 0x40, NULL, { 0.0f, 340.0f, 800.0f } },
    { 6, D_8010EC70_YoshisTropicalIslandEndingScene, { 0.0f, 450.0f, 500.0f } },
    { 7, D_8010EC9C_YoshisTropicalIslandEndingScene, { -200.0f, 0.0f, 400.0f } },
    { 8, D_8010ECA4_YoshisTropicalIslandEndingScene, { -300.0f, 0.0f, 350.0f } },
    { 0x6D, NULL, { 200.0f, 275.0f, 0.0f } },
    { -1, NULL, { 0.0f, 0.0f, 0.0f } },
};

void func_80108B60_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    if ((GwPlayer[arg0->work[0]].player_obj->unk_34 <= 0.0f) && (GwPlayer[arg0->work[0]].player_obj->unk_30 <= 0.0f)) {
        GwPlayer[arg0->work[0]].player_obj->unk_30 = 0.0f;
        return;
    }
    
    GwPlayer[arg0->work[0]].player_obj->unk_38 = -4.0f;
    GwPlayer[arg0->work[0]].player_obj->unk_34 += GwPlayer[arg0->work[0]].player_obj->unk_38;
    GwPlayer[arg0->work[0]].player_obj->unk_30 += GwPlayer[arg0->work[0]].player_obj->unk_34;

    if (GwPlayer[arg0->work[0]].player_obj->unk_30 < 0.0f) {
        GwPlayer[arg0->work[0]].player_obj->unk_30 = 0.0f;
    }
    func_800A0D00(&GwPlayer[arg0->work[0]].player_obj->coords, GwPlayer[arg0->work[0]].player_obj->coords.x, GwPlayer[arg0->work[0]].player_obj->unk_30, GwPlayer[arg0->work[0]].player_obj->coords.z);
}

void func_80108CB8_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    GwPlayer[arg0->work[0]].player_obj->unk_30 = 0;
    GwPlayer[arg0->work[0]].player_obj->unk_34 = 15.0f;
    GwPlayer[arg0->work[0]].player_obj->unk_38 = -4.0f;
    arg0->func_ptr = &func_80108B60_YoshisTropicalIslandEndingScene;
}

void func_80108D40_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    Vec3f sp10;
    Vec3f sp20;
    Vec3f* temp_s0;

    temp_s0 = &D_80110340_YoshisTropicalIslandEndingScene[arg0->work[1]];
    func_800A0D00(&sp10, arg0->scale.x, arg0->scale.y, arg0->scale.z);
    func_800A0D00(&sp20, arg0->rot.x, arg0->rot.y, arg0->rot.z);
    arg0->trans.x = sp10.x * temp_s0->z + sp20.x;
    arg0->trans.z = sp10.z * temp_s0->z + sp20.z;
    arg0->trans.y = (((temp_s0->y * temp_s0->z) + sp10.y) * temp_s0->z) + sp20.y;
    if (arg0->trans.y < temp_s0->x) {
        arg0->work[0]++;
    }
}

void func_80108E20_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    EndingCam* cam0 = &D_80110210_YoshisTropicalIslandEndingScene[0];
    EndingCam* cam1 = &D_80110210_YoshisTropicalIslandEndingScene[1];

    func_8001D494(0, 17.0f, 1000.0f, 20000.0f);
    func_8001D494(1, 17.0f, 1000.0f, 20000.0f);
    func_8001D420(0, &cam0->eye, &cam0->at, &cam0->up);
    func_8001D420(1, &cam1->eye, &cam1->at, &cam1->up);
    func_8001D57C(0);
    func_8001D57C(1);
}
void func_80108EB8_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    u8 idx = arg0->work[0];
    f32 angle = arg0->trans.x;
    f32 t = arg0->rot.x;
    f32 wave;

    if (t > 1.0f) {
        t = 1.0f;
    }
    func_800211BC(*D_80110448_YoshisTropicalIslandEndingScene[arg0->work[0]]->unk_3C->unk_40, (1.0f - t) * 255.0f);
    arg0->rot.x = t + 0.015625f;
    angle += 5.0f;
    if (angle < 360.0f) {
        angle -= 360.0f;
    }
    wave = func_800AEAC0(angle) * 25.0f;
    D_80110448_YoshisTropicalIslandEndingScene[idx]->coords.y = arg0->rot.z;
    D_80110448_YoshisTropicalIslandEndingScene[idx]->unk_30 = (wave + arg0->rot.y) - arg0->rot.z;
    arg0->trans.x = angle;
}
omObjData* func_8010903C_YoshisTropicalIslandEndingScene(s32 arg0, f32 arg1, f32 arg2) {
    omObjData* obj;

    obj = omAddObj(0x600, 0, 0, -1, &func_80108EB8_YoshisTropicalIslandEndingScene);
    obj->work[0] = arg0;
    MBModelDispOn(D_80110448_YoshisTropicalIslandEndingScene[arg0]);
    D_80110448_YoshisTropicalIslandEndingScene[arg0]->unk_0A |= 1;
    func_80021240(*D_80110448_YoshisTropicalIslandEndingScene[arg0]->unk_3C->unk_40);
    omSetRot(obj, 0.0f, arg1, arg2);
    omSetTra(obj, 0.0f, 0.0f, 0.0f);
    return obj;
}
void func_80109110_YoshisTropicalIslandEndingScene(omObjData *arg0) {
    s32 temp_s1 = arg0->work[0];
    f32 var_f20 = arg0->rot.x;
    f32 new_var;
    
    var_f20 = var_f20 + 5.0f;
    if (var_f20 < 360.0f) {
        var_f20 -= 360.0f;
    }
    
    new_var = (-func_800AEAC0(var_f20)) + D_80110448_YoshisTropicalIslandEndingScene[temp_s1]->coords.y;
    D_80110448_YoshisTropicalIslandEndingScene[temp_s1]->coords.y = new_var;
    arg0->rot.x = var_f20;
}

omObjData* func_801091A4_YoshisTropicalIslandEndingScene(u8 arg0) {
    omObjData* temp_v0;

    temp_v0 = omAddObj(0x600, 0, 0, -1, &func_80109110_YoshisTropicalIslandEndingScene);
    temp_v0->work[0] = arg0;
    omSetRot(temp_v0, 0.0f, 0.0f, 0.0f);
    return temp_v0;
}

void func_8010920C_YoshisTropicalIslandEndingScene(Gfx** arg0) {
    gDPSetDepthImage(D_800F37DC++, 0x003D0800);
    gDPSetColorImage(D_800F37DC++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, 0x003D0800);
    gSPDisplayList((*arg0)++, D_8010ECB0_YoshisTropicalIslandEndingScene);
    gDPSetColorImage(D_800F37DC++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, 0x02000000);
}









// register allocation (masked 0): the j * 0.04f temporary lands in $f20, retail $f0
#ifdef NON_MATCHING
void func_80109294_YoshisTropicalIslandEndingScene(void) {
    Vec3f from;
    Vec3f to;
    Vec3f delta;
    Vec2f sp48;
    Vec2f sp50;
    Vec3f start;
    Vec3f end;
    Vec3f diff;
    Vec3f pos;
    Vec3f start2;
    Vec3f end2;
    Vec3f diff2;
    Vec3f pos2;
    f32 t;
    s32 steps;
    s32 steps2;
    s32 k;
    f32 vy;
    f32 g;
    f32 vy2;
    f32 g2;
    s32 i;
    s32 j;

    HuPrcSleep(3);
    i = 0;
    func_8010B0E4_YoshisTropicalIslandEndingScene();
    HuPrcSleep(3);
    LoadBackgroundIndex(0x3F);
    for (i = 0; i < 4; i++) {
        func_80052DC8(i, D_8010EC84_YoshisTropicalIslandEndingScene[GwPlayer[i].character]);
        GwPlayer[i].flags |= 2;
    }
    for (i = 0; i < 4; i++) {
        func_80021B14(*GwPlayer[GwCommon.boardWork[i]].player_obj->unk_3C->unk_40, GwPlayer[GwCommon.boardWork[i]].character, 0);
        func_800A0D00(&GwPlayer[GwCommon.boardWork[i]].player_obj->coords, ENDING_PLAYER_POS[i].x, ENDING_PLAYER_POS[i].y, ENDING_PLAYER_POS[i].z);
        func_8004CCD0(&GwPlayer[GwCommon.boardWork[i]].player_obj->coords, (Vec3f*)&ENDING_PLAYER_POS[i + 4], &GwPlayer[GwCommon.boardWork[i]].player_obj->unk_18);
    }
    for (i = 0; i < 5; i++) {
        D_80110448_YoshisTropicalIslandEndingScene[i] = MBModelCreate(D_8010F664_YoshisTropicalIslandEndingScene[i].id, D_8010F664_YoshisTropicalIslandEndingScene[i].list);
        func_800A0D50(&D_80110448_YoshisTropicalIslandEndingScene[i]->coords, (Vec3f*)&D_8010F664_YoshisTropicalIslandEndingScene[i].pos);
        func_8004CCD0(&D_80110448_YoshisTropicalIslandEndingScene[i]->coords, &D_800F32A0->coords, &D_80110448_YoshisTropicalIslandEndingScene[i]->unk_18);
    }
    D_80110448_YoshisTropicalIslandEndingScene[1]->unk_18.x = 0.0f;
    D_80110448_YoshisTropicalIslandEndingScene[1]->unk_18.y = 0.0f;
    D_80110448_YoshisTropicalIslandEndingScene[1]->unk_18.z = 1.0f;
    D_80110448_YoshisTropicalIslandEndingScene[1]->xScale = D_80110448_YoshisTropicalIslandEndingScene[1]->yScale = D_80110448_YoshisTropicalIslandEndingScene[1]->zScale = 1.5f;
    func_8004F4D4(D_80110448_YoshisTropicalIslandEndingScene[1], 3, 2);
    i = 0;
    func_8004F140(*D_80110448_YoshisTropicalIslandEndingScene[3]->unk_3C->unk_40);
    func_80026018(*D_80110448_YoshisTropicalIslandEndingScene[4]->unk_3C->unk_40, 2.0f);
    HuPrcSleep(3);
    SetFadeInTypeAndTime(0, 0x10);
    for (i = 0; i < 4; i++) {
        func_8004F4D4(GwPlayer[i].player_obj, 1, 2);
    }
    for (j = 20; j < 101; j++) {
        t = j * 0.01f;
        for (i = 0; i < 4; i++) {
            func_800A0D00(&from, ENDING_PLAYER_POS[i].x, ENDING_PLAYER_POS[i].y, ENDING_PLAYER_POS[i].z);
            func_800A0D00(&to, ENDING_PLAYER_POS[i + 8].x, ENDING_PLAYER_POS[i + 8].y, ENDING_PLAYER_POS[i + 8].z);
            func_800A0D00(&delta, to.x - from.x, to.y - from.y, to.z - from.z);
            func_800A0D00(&GwPlayer[GwCommon.boardWork[i]].player_obj->coords, t * delta.x + from.x, t * delta.y + from.y, t * delta.z + from.z);
        }
        HuPrcSleep(0);
    }
    for (i = 0; i < 4; i++) {
        MBMotionShiftSet(GwPlayer[i].player_obj, 7, 0, 0x14, 2);
    }
    HuPrcSleep(0x32);
    for (i = 0; i < 4; i++) {
        MBMotionShiftSet(GwPlayer[i].player_obj, 2, 0, 8, 2);
        func_8004EE14(GwCommon.boardWork[i], (Vec3f*)&ENDING_PLAYER_POS[i + 4], 8, NULL);
    }
    HuPrcSleep(8);
    D_80110300_YoshisTropicalIslandEndingScene[1] = omAddObj(0x600, 0, 0, -1, &func_80108D40_YoshisTropicalIslandEndingScene);
    D_80110340_YoshisTropicalIslandEndingScene[1].x = 0.0f;
    D_80110340_YoshisTropicalIslandEndingScene[1].y = -4.5f;
    D_80110340_YoshisTropicalIslandEndingScene[1].z = 0.0f;
    D_80110300_YoshisTropicalIslandEndingScene[1]->work[0] = 0;
    D_80110300_YoshisTropicalIslandEndingScene[1]->work[1] = 1;
    omSetTra(D_80110300_YoshisTropicalIslandEndingScene[1], 0.0f, 450.0f, 500.0f);
    omSetRot(D_80110300_YoshisTropicalIslandEndingScene[1], 0.0f, 450.0f, 500.0f);
    omSetSca(D_80110300_YoshisTropicalIslandEndingScene[1], 0.0f, -25.0f, 0.0f);
    for (j = 0; j < 26; j++) {
        t = j * 0.04f;
        t *= t;
        for (i = 0; i < 4; i++) {
            func_800A0D00(&from, ENDING_PLAYER_POS[i + 8].x, ENDING_PLAYER_POS[i + 8].y, ENDING_PLAYER_POS[i + 8].z);
            func_800A0D00(&to, ENDING_PLAYER_POS[i + 4].x, ENDING_PLAYER_POS[i + 4].y, ENDING_PLAYER_POS[i + 4].z);
            func_800A0D00(&delta, to.x - from.x, to.y - from.y, to.z - from.z);
            func_800A0D00(&GwPlayer[GwCommon.boardWork[i]].player_obj->coords, t * delta.x + from.x, t * delta.y + from.y, t * delta.z + from.z);
        }
        HuPrcSleep(0);
    }
    while (D_80110300_YoshisTropicalIslandEndingScene[1]->work[0] == 0) {
        D_80110340_YoshisTropicalIslandEndingScene[1].z += 1.0f;
        func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[1]->coords, D_80110300_YoshisTropicalIslandEndingScene[1]->trans.x, D_80110300_YoshisTropicalIslandEndingScene[1]->trans.y, D_80110300_YoshisTropicalIslandEndingScene[1]->trans.z);
        HuPrcSleep(0);
    }
    D_80110448_YoshisTropicalIslandEndingScene[1]->coords.y = 0.0f;
    for (i = 0; i < 4; i++) {
        D_80110300_YoshisTropicalIslandEndingScene[2 + i] = omAddObj(0x600, 0, 0, -1, &func_80108CB8_YoshisTropicalIslandEndingScene);
        D_80110300_YoshisTropicalIslandEndingScene[2 + i]->work[0] = GwCommon.boardWork[i];
    }
    D_80110340_YoshisTropicalIslandEndingScene[1].z = 0.0f;
    D_80110300_YoshisTropicalIslandEndingScene[1]->work[0] = 0;
    omSetTra(D_80110300_YoshisTropicalIslandEndingScene[1], 0.0f, 0.0f, 500.0f);
    omSetRot(D_80110300_YoshisTropicalIslandEndingScene[1], 0.0f, 0.0f, 500.0f);
    omSetSca(D_80110300_YoshisTropicalIslandEndingScene[1], 0.0f, 40.0f, 0.0f);
    D_80110304_SCALAR->trans.y = 0.0f;
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[1]->coords, D_80110304_SCALAR->trans.y, D_80110304_SCALAR->trans.y, 500.0f);
    func_8004B68C(&sp48);
    sp48.y -= 1.0f;
    sp50.x = sp48.x;
    sp50.y = sp48.y;
    func_8001ABA0(2);
    func_8004B7F8(0xC0);
    func_8002578C(0);
    for (i = 0; i < 4; i++) {
        MBMotionShiftSet(GwPlayer[i].player_obj, 8, 0, 0x14, 0);
    }
    while (D_80110300_YoshisTropicalIslandEndingScene[1]->work[0] == 0) {
        HuPrcSleep(0);
        D_80110340_YoshisTropicalIslandEndingScene[1].z += 1.0f;
        func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[1]->coords, D_80110300_YoshisTropicalIslandEndingScene[1]->trans.x, D_80110300_YoshisTropicalIslandEndingScene[1]->trans.y, D_80110300_YoshisTropicalIslandEndingScene[1]->trans.z);
        func_8004B61C(&sp48);
        sp48.y -= 1.0f;
    }
    func_8004B61C(&sp50);
    D_80110448_YoshisTropicalIslandEndingScene[1]->coords.y = 0.0f;
    D_80110300_YoshisTropicalIslandEndingScene[1]->scale.y = 20.0f;
    for (i = 0; i < 4; i++) {
        GwPlayer[i].player_obj->unk_30 = 0.0f;
        GwPlayer[i].player_obj->unk_34 = 7.5f;
    }
    sp50.x = sp48.x;
    sp50.y = sp48.y;
    while (D_80110300_YoshisTropicalIslandEndingScene[1]->work[0] == 0) {
        HuPrcSleep(0);
        D_80110340_YoshisTropicalIslandEndingScene[1].z += 1.0f;
        func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[1]->coords, D_80110300_YoshisTropicalIslandEndingScene[1]->trans.x, D_80110300_YoshisTropicalIslandEndingScene[1]->trans.y, D_80110300_YoshisTropicalIslandEndingScene[1]->trans.z);
        func_8004B61C(&sp48);
        sp48.y -= 1.0f;
    }
    func_8004B61C(&sp50);
    D_80110448_YoshisTropicalIslandEndingScene[1]->coords.y = 0.0f;
    func_8004B7F8(0xFF);
    func_8002578C(1);
    for (i = 0; i < 4; i++) {
        MBMotionShiftSet(GwPlayer[i].player_obj, -1, 0, 0x14, 2);
        func_8004EE14(GwCommon.boardWork[i], &D_80110448_YoshisTropicalIslandEndingScene[1]->coords, 0x14, NULL);
    }
    i = 0;
    omDelObj(D_80110300_YoshisTropicalIslandEndingScene[1]);
    D_80110300_YoshisTropicalIslandEndingScene[1] = NULL;
    for (i = 0; i < 4; i++) {
        omDelObj(D_80110300_YoshisTropicalIslandEndingScene[2 + i]);
        D_80110300_YoshisTropicalIslandEndingScene[2 + i] = NULL;
    }
    HuPrcSleep(3);
    func_8001ABA0(3);
    HuPrcSleep(0x1B);
    vy = 50.0f;
    g = -3.5f;
    func_800A0D50(&start, &GwPlayer[GwCommon.boardWork[0]].player_obj->coords);
    func_800A0D00(&end, 0.0f, 225.0f, 500.0f);
    func_800A0D00(&diff, end.x - start.x, end.y - start.y, end.z - start.z);
    steps = (-vy - func_800B1750(vy * vy - 2.0f * g * (start.y - end.y))) / g;
    MBMotionShiftSet(GwPlayer[GwCommon.boardWork[0]].player_obj, 4, 0, 0x14, 0);
    for (k = 0; k <= steps; k++) {
        f32 frac = (f32)k / (f32)steps;
        pos.x = frac * diff.x + start.x;
        pos.y = start.y;
        pos.z = frac * diff.z + start.z;
        func_800A0D50(&GwPlayer[GwCommon.boardWork[0]].player_obj->coords, &pos);
        GwPlayer[GwCommon.boardWork[0]].player_obj->unk_30 = (g * 0.5f * k + vy) * k + start.y;
        HuPrcSleep(0);
    }
    func_800A0D00(&GwPlayer[GwCommon.boardWork[0]].player_obj->coords, 0.0f, 225.0f, 500.0f);
    GwPlayer[GwCommon.boardWork[0]].player_obj->unk_30 = 0.0f;
    func_8004EE14(GwCommon.boardWork[0], D_800F32A0, 8, NULL);
    func_8004F504(GwPlayer[GwCommon.boardWork[0]].player_obj);
    MBMotionShiftSet(GwPlayer[GwCommon.boardWork[0]].player_obj, -1, 0, 0x14, 2);
    HuPrcSleep(0x14);
    MBMotionShiftSet(GwPlayer[GwCommon.boardWork[0]].player_obj, 5, 0, 0x14, 0);
    func_8004F504(GwPlayer[GwCommon.boardWork[0]].player_obj);
    MBMotionShiftSet(GwPlayer[GwCommon.boardWork[0]].player_obj, -1, 0, 0x14, 2);
    for (k = 0; k < 5; k++) {
        func_8004EE14(0, D_800F32A0, 8, D_80110448_YoshisTropicalIslandEndingScene[k]);
    }
    func_8004EE14(0, (Vec3f*)&D_8010F6DC_YoshisTropicalIslandEndingScene[3].pos, 8, D_80110448_YoshisTropicalIslandEndingScene[3]);
    MBMotionSet(D_80110448_YoshisTropicalIslandEndingScene[3], 0, 2);
    func_8004E3E0(0, (Vec3f*)&D_8010F6DC_YoshisTropicalIslandEndingScene[3].pos, 0x1E, D_80110448_YoshisTropicalIslandEndingScene[3]);
    func_8004EE14(0, (Vec3f*)&D_8010F6DC_YoshisTropicalIslandEndingScene[2].pos, 8, D_80110448_YoshisTropicalIslandEndingScene[2]);
    MBMotionSet(D_80110448_YoshisTropicalIslandEndingScene[2], 0, 2);
    func_8004E3E0(0, (Vec3f*)&D_8010F6DC_YoshisTropicalIslandEndingScene[2].pos, 0x1E, D_80110448_YoshisTropicalIslandEndingScene[2]);
    func_800A0D50(&D_80110448_YoshisTropicalIslandEndingScene[4]->coords, (Vec3f*)&D_8010F6DC_YoshisTropicalIslandEndingScene[4].pos);
    D_80110300_YoshisTropicalIslandEndingScene[14] = func_8010903C_YoshisTropicalIslandEndingScene(4, D_8010F6DC_YoshisTropicalIslandEndingScene[4].pos.y, 0.0f);
    D_80110300_YoshisTropicalIslandEndingScene[14]->work[0] = 4;
    HuPrcSleep(0x1E);
    for (i = 0; i < 5; i++) {
        func_8004EE14(0, D_800F32A0, 0x10, D_80110448_YoshisTropicalIslandEndingScene[i]);
    }
    MBMotionShiftSet(D_80110448_YoshisTropicalIslandEndingScene[3], -1, 0, 0x14, 2);
    MBMotionShiftSet(D_80110448_YoshisTropicalIslandEndingScene[2], -1, 0, 0x14, 2);
    vy2 = 10.0f;
    g2 = -1.75f;
    func_800A0D50(&start2, &GwPlayer[GwCommon.boardWork[0]].player_obj->coords);
    func_800A0D00(&end2, 0.0f, 0.0f, 750.0f);
    steps2 = (-vy2 - func_800B1750(vy2 * vy2 - 2.0f * g2 * (start2.y - end2.y))) / g2;
    func_800A0D00(&diff2, end2.x - start2.x, end2.y - start2.y, end2.z - start2.z);
    func_8004CCD0(&D_80110448_YoshisTropicalIslandEndingScene[0]->coords, (Vec3f*)&D_8010F664_YoshisTropicalIslandEndingScene[0].pos, &D_80110448_YoshisTropicalIslandEndingScene[0]->unk_18);
    D_80110400_YoshisTropicalIslandEndingScene[0] = func_80042728(D_80110448_YoshisTropicalIslandEndingScene[0], 1);
    for (k = 0; k < 4; k++) {
        func_8004EE14(k, (Vec3f*)&D_8010F664_YoshisTropicalIslandEndingScene[0].pos, 0x14, NULL);
    }
    HuPrcSleep(0x14);
    func_8004E3E0(0, (Vec3f*)&D_8010F6DC_YoshisTropicalIslandEndingScene[0].pos, 0x5A, D_80110448_YoshisTropicalIslandEndingScene[0]);
    for (k = 0; k < 0x5A; k++) {
        func_8004CCD0(&GwPlayer[0].player_obj->coords, &D_80110448_YoshisTropicalIslandEndingScene[0]->coords, &GwPlayer[0].player_obj->unk_18);
        func_8004CCD0(&GwPlayer[1].player_obj->coords, &D_80110448_YoshisTropicalIslandEndingScene[0]->coords, &GwPlayer[1].player_obj->unk_18);
        func_8004CCD0(&GwPlayer[2].player_obj->coords, &D_80110448_YoshisTropicalIslandEndingScene[0]->coords, &GwPlayer[2].player_obj->unk_18);
        func_8004CCD0(&GwPlayer[3].player_obj->coords, &D_80110448_YoshisTropicalIslandEndingScene[0]->coords, &GwPlayer[3].player_obj->unk_18);
        HuPrcSleep(0);
    }
    D_80110300_YoshisTropicalIslandEndingScene[13] = func_801091A4_YoshisTropicalIslandEndingScene(0);
    for (k = 1; k < 4; k++) {
        func_8004EE14(GwCommon.boardWork[k], D_800F32A0, 0x14, NULL);
    }
    HuPrcSleep(0x14);
    MBMotionShiftSet(GwPlayer[GwCommon.boardWork[0]].player_obj, 4, 0, 0x14, 0);
    for (k = 0; k <= steps2; k++) {
        f32 frac = (f32)k / (f32)steps2;
        pos2.x = frac * diff2.x + start2.x;
        pos2.y = 0.0f;
        pos2.z = frac * diff2.z + start2.z;
        func_800A0D50(&GwPlayer[GwCommon.boardWork[0]].player_obj->coords, &pos2);
        GwPlayer[GwCommon.boardWork[0]].player_obj->unk_30 = (g2 * 0.5f * k + vy2) * k + start2.y;
        HuPrcSleep(0);
    }
    func_800A0D00(&GwPlayer[GwCommon.boardWork[0]].player_obj->coords, 0.0f, 0.0f, 750.0f);
    GwPlayer[GwCommon.boardWork[0]].player_obj->unk_30 = 0.0f;
    func_8004F504(GwPlayer[GwCommon.boardWork[0]].player_obj);
    MBMotionShiftSet(GwPlayer[GwCommon.boardWork[0]].player_obj, -1, 0, 0x14, 2);
    HuPrcSleep(0x14);
    MBMotionShiftSet(GwPlayer[GwCommon.boardWork[0]].player_obj, 6, 0, 0x14, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_YoshisTropicalIslandEndingScene/2721F0", func_80109294_YoshisTropicalIslandEndingScene);
/* the asm names labels inside the C tables */
__asm__(
    ".globl D_8010F5D8_YoshisTropicalIslandEndingScene\nD_8010F5D8_YoshisTropicalIslandEndingScene = D_8010F5D4_YoshisTropicalIslandEndingScene + 0x4\n"
    ".globl D_8010F5DC_YoshisTropicalIslandEndingScene\nD_8010F5DC_YoshisTropicalIslandEndingScene = D_8010F5D4_YoshisTropicalIslandEndingScene + 0x8\n"
    ".globl D_8010F604_YoshisTropicalIslandEndingScene\nD_8010F604_YoshisTropicalIslandEndingScene = D_8010F5D4_YoshisTropicalIslandEndingScene + 0x30\n"
    ".globl D_8010F667_YoshisTropicalIslandEndingScene\nD_8010F667_YoshisTropicalIslandEndingScene = D_8010F664_YoshisTropicalIslandEndingScene + 0x3\n"
    ".globl D_8010F668_YoshisTropicalIslandEndingScene\nD_8010F668_YoshisTropicalIslandEndingScene = D_8010F664_YoshisTropicalIslandEndingScene + 0x4\n"
    ".globl D_8010F66C_YoshisTropicalIslandEndingScene\nD_8010F66C_YoshisTropicalIslandEndingScene = D_8010F664_YoshisTropicalIslandEndingScene + 0x8\n"
    ".globl D_8010F6E4_YoshisTropicalIslandEndingScene\nD_8010F6E4_YoshisTropicalIslandEndingScene = D_8010F6DC_YoshisTropicalIslandEndingScene + 0x8\n"
    ".globl D_8010F70C_YoshisTropicalIslandEndingScene\nD_8010F70C_YoshisTropicalIslandEndingScene = D_8010F6DC_YoshisTropicalIslandEndingScene + 0x30\n"
    ".globl D_8010F720_YoshisTropicalIslandEndingScene\nD_8010F720_YoshisTropicalIslandEndingScene = D_8010F6DC_YoshisTropicalIslandEndingScene + 0x44\n"
    ".globl D_8010F734_YoshisTropicalIslandEndingScene\nD_8010F734_YoshisTropicalIslandEndingScene = D_8010F6DC_YoshisTropicalIslandEndingScene + 0x58\n"
    ".globl D_8010F738_YoshisTropicalIslandEndingScene\nD_8010F738_YoshisTropicalIslandEndingScene = D_8010F6DC_YoshisTropicalIslandEndingScene + 0x5C\n"
);
#endif
const f64 D_8010F758_YoshisTropicalIslandEndingScene __attribute__((section(".rodata"))) = 0.0174532925199432955;
void func_8010A740_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    omObjData* temp_s0;

    arg0->rot.x = arg0->rot.x + 5.0f;
    
    if (arg0->rot.x >= 360.0f) {
        arg0->rot.x -= 360.0f;
    }
    
    D_80110448_YoshisTropicalIslandEndingScene[0]->unk_18.x = (sinf((f32) (arg0->rot.x * D_8010F758_YoshisTropicalIslandEndingScene)) * 0.2f);
    D_80110448_YoshisTropicalIslandEndingScene[0]->unk_18.z = 1.0f;
}

const f64 D_8010F760_YoshisTropicalIslandEndingScene __attribute__((section(".rodata"))) = 0.0174532925199432955;
void func_8010A7EC_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    s32 count = D_8010DC90_YoshisTropicalIslandEndingScene[GwSystem.unk_00];
    s32 i;
    f32 angle;
    f32 x;

    for (i = 0; i < arg0->trans.y; i++) {
        angle = (360 / count) * i;
        x = sinf((angle + arg0->rot.y) * D_8010F760_YoshisTropicalIslandEndingScene) * arg0->trans.x + D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].x;
        func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[i]->coords, x, D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].y,
                      cosf((angle + arg0->rot.y) * D_8010F760_YoshisTropicalIslandEndingScene) * arg0->trans.x + D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].z);
        func_800A0D00((Vec3f*)&D_80110448_YoshisTropicalIslandEndingScene[i]->xScale, arg0->scale.x, arg0->scale.x, arg0->scale.x);
        func_80025F10(*D_80110448_YoshisTropicalIslandEndingScene[i]->unk_3C->unk_40, 2);
    }
    arg0->rot.y -= 2.0f;
    if (arg0->rot.y <= 0.0f) {
        arg0->rot.y += 360.0f;
    }
    arg0->work[0]++;
}
void func_8010AA38_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    Vec3f start;
    Vec3f delta;
    f32 t;
    f32 s;
    f32 scale;

    t = arg0->rot.x;
    if (t > 1.0f) {
        t = 1.0f;
    }
    s = 1.0f - t;
    s = s * (s * s * s);
    func_800A0D50(&start, &D_80110448_YoshisTropicalIslandEndingScene[14]->coords);
    func_800A0D00(&delta, D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].x - start.x, D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].y - start.y,
                  (D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].z + 1000.0f) - start.z);
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[0]->coords, s * delta.x + start.x, s * delta.y + start.y, (1.0f - t) * delta.z + start.z);
    func_800A0D00((Vec3f*)&D_80110448_YoshisTropicalIslandEndingScene[0]->xScale, scale = (s * 0.9f + 0.1f) * 6.0f, scale, scale);
    arg0->rot.x = t + 0.03f;
    if (arg0->rot.x > 1.0f) {
        arg0->work[0] = 0;
        arg0->rot.x = 1.0f;
    }
}
void func_8010AC24_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    arg0->func_ptr = &func_8010AA38_YoshisTropicalIslandEndingScene;
    arg0->trans.x = arg0->trans.y = arg0->trans.z = arg0->rot.x =
        arg0->rot.y = arg0->rot.z = 0.0f;
    
    arg0->work[0] = 1;
}

void func_8010AC5C_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    Vec3f start;
    Vec3f sp20;
    Vec3f pos;
    Vec3f offset;
    f32 t;
    f32 t2;
    f32 s;
    f32 c;

    t = arg0->rot.x;
    if (t > 1.0f) {
        t = 1.0f;
    }
    t2 = t * t;
    s = func_800AEAC0(t2 * 360.0f);
    c = func_800AEFD0(t2 * 360.0f);
    func_800A0D50(&start, &D_80110448_YoshisTropicalIslandEndingScene[14]->coords);
    func_800A0D00(&offset, 2500.0f, 1000.0f, -2500.0f);
    func_800A0D00(&sp20, start.x + offset.x, start.y + offset.y, start.z + offset.z);
    func_800A0D00(&pos, t2 * (s * 1000.0f + offset.x) + start.x, t2 * offset.y + start.y, t2 * (c * -1000.0f + offset.z) + start.z);
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[0]->coords, pos.x, pos.y, pos.z);
    arg0->rot.x = t + 0.03f;
}
void func_8010AE08_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    arg0->func_ptr = &func_8010AC5C_YoshisTropicalIslandEndingScene;
    arg0->trans.x = arg0->trans.y = arg0->trans.z = arg0->rot.x = arg0->rot.y = arg0->rot.z = 0.0f;
    arg0->work[0] = 1;
}

void func_8010AE40_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    D_800C34A4 = arg0->rot.x;
    
    if (arg0->rot.y > 1.0f) {
        func_800258EC(*D_80110448_YoshisTropicalIslandEndingScene[14]->unk_3C->unk_40, 4, 4);
        return;
    }
    
    func_80026B8C(*D_80110448_YoshisTropicalIslandEndingScene[14]->unk_3C->unk_40, arg0->rot.y, arg0->rot.z, 2);
    arg0->rot.x += 39.0f;
    
    if (arg0->rot.x > 360.0f) {
        arg0->rot.x -= 360.0f;
    }
    arg0->rot.y += 0.05f;
    arg0->rot.z = (10.0f - arg0->rot.z) / 30.0f + arg0->rot.z;
}

void func_8010AF58_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    arg0->func_ptr = &func_8010AE40_YoshisTropicalIslandEndingScene;
    func_80025930(*D_80110448_YoshisTropicalIslandEndingScene[14]->unk_3C->unk_40, 0x22000, 0x20000);
    func_80025AD4(*D_80110448_YoshisTropicalIslandEndingScene[14]->unk_3C->unk_40);
    func_80026040(*D_80110448_YoshisTropicalIslandEndingScene[14]->unk_3C->unk_40);
    arg0->rot.x = arg0->rot.y = 0.0f;
    arg0->rot.z = 1.0f;
}

void func_8010AFF8_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    Matrix4f mtx;
    Vec3f src;
    Vec3f dst;
    f32 angle;

    angle = arg0->rot.x;
    func_800A40D0(mtx, angle);
    func_800A0D50(&src, &D_80110448_YoshisTropicalIslandEndingScene[15]->unk_18);
    func_800ACE70(mtx, &src, &dst);
    func_800A0D50(&D_80110448_YoshisTropicalIslandEndingScene[15]->unk_18, &dst);
    angle += 33.0f;
    if (angle > 360.0f) {
        angle -= 360.0f;
    }
    arg0->rot.x = angle;
}
void func_8010B0C0_YoshisTropicalIslandEndingScene(omObjData* arg0) {
    arg0->func_ptr = &func_8010AFF8_YoshisTropicalIslandEndingScene;
    arg0->rot.x = arg0->rot.y = arg0->rot.z = 0.0f;
}

const f64 D_8010F768_YoshisTropicalIslandEndingScene __attribute__((section(".rodata"))) = 0.0174532925199432955;
void func_8010B0E4_YoshisTropicalIslandEndingScene(void) {
    Vec3f sp18;
    Vec3f sp28;
    Vec3f sp38;
    EndingCam* cam0 = &D_80110210_YoshisTropicalIslandEndingScene[0];
    EndingCam* cam1 = &D_80110210_YoshisTropicalIslandEndingScene[1];
    s32 count = D_8010DC90_YoshisTropicalIslandEndingScene[GwSystem.unk_00];
    f32 radius = D_8010DCFC_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene];
    f32 angle;
    f32 x;
    f32 t;
    f32 v;
    s16 layer;
    s32 i;
    omObjData* obj;

    for (i = 0; i < count; i++) {
        D_80110448_YoshisTropicalIslandEndingScene[i] = MBModelCreate(0x25, NULL);
        angle = (360 / count) * i * D_8010F768_YoshisTropicalIslandEndingScene;
        x = sinf(angle) * radius + D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].x;
        func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[i]->coords, x, D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].y,
                      cosf(angle) * radius + D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].z);
        /* retail writes the scale into coords */
        func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[i]->coords, D_8010DD1C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene],
                      D_8010DD1C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene], D_8010DD1C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene]);
        func_80025F10(*D_80110448_YoshisTropicalIslandEndingScene[i]->unk_3C->unk_40, 2);
        D_80110400_YoshisTropicalIslandEndingScene[i] = func_80042728(D_80110448_YoshisTropicalIslandEndingScene[i], 1);
        func_80025F10(*((EndingEmitterWork*)D_80110400_YoshisTropicalIslandEndingScene[i])->model->unk_3C->unk_40, 2);
    }
    obj = omAddObj(0x7FDA, 0, 0, -1, &func_8010A7EC_YoshisTropicalIslandEndingScene);
    obj->rot.y = 0.0f;
    obj->trans.x = radius;
    obj->trans.y = count;
    obj->scale.x = D_8010DD1C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene];
    obj->work[0] = 0;
    LoadBackgroundIndex(0x41);
    D_80110448_YoshisTropicalIslandEndingScene[14] = MBModelCreate(0x35, NULL);
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[14]->coords, 0.0f, 4.0f, -1300.0f);
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[14]->unk_18, 0.0f, 0.0f, 1.0f);
    func_80025F10(*D_80110448_YoshisTropicalIslandEndingScene[14]->unk_3C->unk_40, 1);
    D_80110448_YoshisTropicalIslandEndingScene[15] = MBModelCreate(6, D_8010EC70_YoshisTropicalIslandEndingScene);
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[15]->coords, 0.0f, 0.0f, -1200.0f);
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[15]->unk_18, 0.0f, 0.0f, 1.0f);
    func_80025F10(*D_80110448_YoshisTropicalIslandEndingScene[15]->unk_3C->unk_40, 1);
    func_80025F10(*D_80110448_YoshisTropicalIslandEndingScene[15]->unk_40->unk_40, 1);
    func_8004B1B8();
    InitCameras(2);
    func_8001D520(0, &D_8010ECE0_YoshisTropicalIslandEndingScene, &D_8010ECEC_YoshisTropicalIslandEndingScene);
    func_8001D520(1, &D_8010ECE0_YoshisTropicalIslandEndingScene, &D_8010ECEC_YoshisTropicalIslandEndingScene);
    layer = func_8002451C(0, &func_8010920C_YoshisTropicalIslandEndingScene, 0);
    func_80025F10(layer, 2);
    D_80110300_YoshisTropicalIslandEndingScene[0] = omAddObj(0x600, 0, 0, -1, &func_80108E20_YoshisTropicalIslandEndingScene);
    func_800A0D00(&cam0->eye, 0.0f, 9000.0f, 7000.0f);
    func_800A0D00(&cam0->at, 0.0f, 0.0f, 0.0f);
    func_800A0D00(&cam0->up, 0.0f, 1.0f, 0.0f);
    func_800A0D00(&cam0->unk24, 0.0f, 0.0f, 0.0f);
    func_800A0D00(&cam1->eye, 0.0f, 9000.0f, 7000.0f);
    func_800A0D00(&cam1->at, 0.0f, 0.0f, 0.0f);
    func_800A0D00(&cam1->up, 0.0f, 1.0f, 0.0f);
    func_800A0D00(&cam1->unk24, 0.0f, 0.0f, 0.0f);
    func_80072724(0xFF, 0xFF, 0xFF);
    SetFadeInTypeAndTime(2, 0x18);
    PlaySound(0x48);
    HuPrcSleep(0x36);
    while (radius >= 350.0f) {
        obj->trans.x = radius;
        if (radius - 10.0f < 350.0f) {
            PlaySound(0x78);
            func_80072724(0xFF, 0xFF, 0xFF);
            func_800726AC(0, 0);
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
    func_80025F10(*D_80110448_YoshisTropicalIslandEndingScene[0]->unk_3C->unk_40, 2);
    func_80028C64(*D_80110448_YoshisTropicalIslandEndingScene[0]->unk_3C->unk_40, 0xFF, 0xFF, 0xFF, 0xFF);
    v = 2.0f * D_8010DD1C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene];
    func_800A0D00((Vec3f*)&D_80110448_YoshisTropicalIslandEndingScene[0]->xScale, v, v, v);
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[0]->coords, D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].x,
                  D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].y, D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].z);
    func_80025F10(*((EndingEmitterWork*)D_80110400_YoshisTropicalIslandEndingScene[0])->model->unk_3C->unk_40, 2);
    omDelObj(obj);
    obj = omAddObj(0x600, 0, 0, -1, &func_8010A740_YoshisTropicalIslandEndingScene);
    obj->rot.x = 0.0f;
    HuPrcSleep(5);
    SetFadeInTypeAndTime(0, 0x10);
    HuPrcSleep(0x10);
    func_8004F4D4(D_80110448_YoshisTropicalIslandEndingScene[15], 1, 0);
    func_8004F504(D_80110448_YoshisTropicalIslandEndingScene[15]);
    func_8004F4D4(D_80110448_YoshisTropicalIslandEndingScene[15], -1, 2);
    do {
        func_80028C64(*D_80110448_YoshisTropicalIslandEndingScene[0]->unk_3C->unk_40, i, i, i, 0xFF);
        HuPrcVSleep();
        i -= 4;
    } while (i >= 0);
    HuPrcSleep(0xA);
    func_80060128(2);
    func_800A0D00(&sp18, 0.0f, 0.0f, 0.0f);
    func_800A0D00(&sp28, 0.0f, 0.0f, 0.0f);
    func_800A0D00(&sp38, 0.0f, 0.0f, 500.0f);
    for (i = 0; i < 0x3D; i++) {
        t = i * 0.033f;
        if (t > 2.0f) {
            t = 2.0f;
        }
        HuPrcSleep(0);
        if (t <= 1.0f) {
            v = t * t;
        } else {
            f32 d = t - 2.0f;
            v = -d * d + 2.0f;
        }
        func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[0]->coords, D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].x,
                      D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].y, v * 100.0f * 5.0f + D_8010DC9C_YoshisTropicalIslandEndingScene[D_801102B0_YoshisTropicalIslandEndingScene].z);
    }
    HuPrcSleep(0x1E);
    func_8004F4D4(D_80110448_YoshisTropicalIslandEndingScene[15], 2, 0);
    func_8004B7F8(0x40);
    func_8002578C(0);
    for (i = 0; i < 0xFD; i += 4) {
        func_80028C64(*D_80110448_YoshisTropicalIslandEndingScene[0]->unk_3C->unk_40, i, 0, 0, 0xFF);
        HuPrcVSleep();
    }
    func_8004F504(D_80110448_YoshisTropicalIslandEndingScene[15]);
    func_8004F4D4(D_80110448_YoshisTropicalIslandEndingScene[15], -1, 0);
    HuPrcSleep(5);
    func_8004F4D4(D_80110448_YoshisTropicalIslandEndingScene[15], 2, 0);
    D_80110300_YoshisTropicalIslandEndingScene[1] = omAddObj(0x600, 0, 0, -1, &func_8010AC24_YoshisTropicalIslandEndingScene);
    D_80110300_YoshisTropicalIslandEndingScene[1]->work[0] = 1;
    HuPrcSleep(5);
    D_80110448_YoshisTropicalIslandEndingScene[13] = MBModelCreate(0x56, NULL);
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[13]->coords, D_80110448_YoshisTropicalIslandEndingScene[14]->coords.x,
                  D_80110448_YoshisTropicalIslandEndingScene[14]->coords.y + 400.0f, D_80110448_YoshisTropicalIslandEndingScene[14]->coords.z);
    func_800A0D00(&D_80110448_YoshisTropicalIslandEndingScene[13]->unk_18, 0.0f, 0.0f, 1.0f);
    func_80025F10(*D_80110448_YoshisTropicalIslandEndingScene[13]->unk_3C->unk_40, 1);
    while (D_80110300_YoshisTropicalIslandEndingScene[1]->work[0] != 0) {
        HuPrcSleep(0);
    }
    omDelObj(D_80110300_YoshisTropicalIslandEndingScene[1]);
    D_80110300_YoshisTropicalIslandEndingScene[1] = NULL;
    D_80110300_YoshisTropicalIslandEndingScene[1] = omAddObj(0x600, 0, 0, -1, &func_8010AE08_YoshisTropicalIslandEndingScene);
    MBModelDispOff(D_80110448_YoshisTropicalIslandEndingScene[13]);
    D_80110300_YoshisTropicalIslandEndingScene[3] = omAddObj(0x600, 0, 0, -1, &func_8010AF58_YoshisTropicalIslandEndingScene);
    D_80110300_YoshisTropicalIslandEndingScene[4] = omAddObj(0x600, 0, 0, -1, &func_8010B0C0_YoshisTropicalIslandEndingScene);
    func_8004F00C(D_80110448_YoshisTropicalIslandEndingScene[15], 80.0f, -3.5f);
    HuPrcSleep(0xA);
    func_800726AC(0, 0x10);
    HuPrcSleep(0x10);
    InitCameras(1);
    func_8004B7F8(0xFF);
    func_8002578C(1);
    func_8002456C(layer);
    omDelObj(obj);
    func_800427D4(D_80110400_YoshisTropicalIslandEndingScene[0]);
    D_80110400_YoshisTropicalIslandEndingScene[0] = NULL;
    HuPrcSleep(4);
    func_8004A140();
    func_800F6B54_YoshisTropicalIslandEndingScene();
}
