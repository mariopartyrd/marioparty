#include "common.h"

void InitCameras(s16 count) {
    s16 j;
    s16 i;

    D_800ECB00 = count;
    D_800F3FA8 = 0;
    if (D_800C3110 != NULL) {
        func_80023728(D_800C3110);
    }
    D_800C3110 = func_80023668(0x1DD0);
    for (i = 0; i < 6; i++) {
        D_800C3110[i].unk_40 = 45.0f;
        D_800C3110[i].unk_44 = 80.0f;
        D_800C3110[i].unk_48 = 8000.0f;
        D_800C3110[i].unk4E = 0;
        func_8001D520(i, &D_800C3114, &D_800C3150);
        func_8001D4D4(i, &D_800C318C);
        D_800C3110[i].unkE8 = 0;
        D_800C3110[i].unkF0 = 0;
        D_800C3110[i].unkF4 = 0;
        for (j = 0; j < D_800F37DA; j++) {
            func_800A2B40(&D_800C3110[i].unkF8 + j * 2);
            func_800A2B40(&D_800C3110[i].unkF8 + j * 2 + 1);
        }
    }
    D_800F32A0 = (camera *) D_800C3110;
    D_800F2BCC = &D_800C3110->unkF8;
}

void func_8001D40C() {
    D_800F3FA8 = D_800F37F0;
}

void func_8001D420(s16 index, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3) {
    unk_Struct00* temp_v0;

    temp_v0 = &D_800C3110[index];
    temp_v0->pos = *arg1;
    temp_v0->unkC = *arg2;
    temp_v0->unk18 = *arg3;
}

void func_8001D494(s16 index, f32 arg1, f32 arg2, f32 arg3) {
    unk_Struct00* temp_v0;

    temp_v0 = &D_800C3110[index];
    temp_v0->unk_40 = arg1;
    temp_v0->unk_44 = arg2;
    temp_v0->unk_48 = arg3;
    temp_v0->unk4C = 1;
}

void func_8001D4D4(s16 index, Vec4f* arg1) {
    unk_Struct00* temp_v0;

    temp_v0 = &D_800C3110[index];
    temp_v0->unkD8.x = arg1->x;
    temp_v0->unkD8.y = arg1->y;
    temp_v0->unkD8.z = arg1->z;
    temp_v0->unkD8.w = arg1->w;
}

void func_8001D520(s16 index, Vec3f* arg1, Vec3f* arg2) {
    unk_Struct00* temp_v0;

    temp_v0 = &D_800C3110[index];
    temp_v0->unk24 = *arg1;
    temp_v0->unk30 = *arg2;
}

void func_8001D57C(s16 index) {
    unk_Struct00* temp_s0;
    Mtx* temp_s1;

    temp_s0 = &D_800C3110[index];
    temp_s1 = &temp_s0->unkF8 + (D_800F3FA8 << 1);
    guPerspective(temp_s1, &temp_s0->unk4C, temp_s0->unk_40, (4.0f / 3.0f), temp_s0->unk_44, temp_s0->unk_48, 1.0f);
    guLookAt(temp_s1 + 0x1, temp_s0->pos.x, temp_s0->pos.y, temp_s0->pos.z, temp_s0->unkC.x, temp_s0->unkC.y, temp_s0->unkC.z, temp_s0->unk18.x, temp_s0->unk18.y, temp_s0->unk18.z);
}

void func_8001D658(s16 index, Gfx** gfx) {
    unk_Struct00* temp_v1;
    unk_Struct00* temp_a0;
    Mtx* temp_s1;

    temp_v1 = &D_800C3110[index];
    temp_s1 = &temp_v1->unkF8 + (D_800F3FA8 * 2);
    temp_a0 = (void*) temp_v1 + (D_800F3FA8 * 16);
    temp_a0->unk58 = temp_v1->unk24.x;
    temp_a0->unk5A = temp_v1->unk24.y;
    temp_a0->unk5C = temp_v1->unk24.z;
    temp_a0->unk60 = temp_v1->unk30.x;
    temp_a0->unk62 = temp_v1->unk30.y;
    temp_a0->unk64 = temp_v1->unk30.z;

    gSPViewport((*gfx)++, &temp_v1->unk58 + (D_800F3FA8 * 8));
    gSPPerspNormalize((*gfx)++, temp_v1->unk4C);
    gSPMatrix((*gfx)++, osVirtualToPhysical(temp_s1), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix((*gfx)++, (void*) temp_s1 + 0x80000040, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
}


void func_8001D7DC(s16 index, Gfx** gfx) {
    unk_Struct00* temp_a2;

    temp_a2 = &D_800C3110[index];
    gDPSetScissor((*gfx)++, G_SC_NON_INTERLACE, temp_a2->unkD8.x, temp_a2->unkD8.y, temp_a2->unkD8.z, temp_a2->unkD8.w);
}

void func_8001D8A0(s16 index, s32 arg1, s32 arg2) {
    unk_Struct00* temp_v0;

    temp_v0 = &D_800C3110[index];
    temp_v0->unkE8 = arg1;
    temp_v0->unkEC = arg2;
}

void func_8001D8D4(s16 index, s32 arg1) {
    D_800C3110[index].unkF0 = arg1;
}

void func_8001D904(s16 index, s32 arg1) {
    D_800C3110[index].unkF4 = arg1;
}

void Convert3DTo2D(s16 index, Vec3f* arg1, Vec2f* arg2) {
    Matrix4f sp28;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f28;
    f32 temp_f2;
    f32 temp_f30;
    unk_Struct00* temp_s0;

    temp_s0 = &D_800C3110[index];
    HuGuLookAtF(sp28, temp_s0->pos.x, temp_s0->pos.y, temp_s0->pos.z, temp_s0->unkC.x, temp_s0->unkC.y, temp_s0->unkC.z, temp_s0->unk18.x, temp_s0->unk18.y, temp_s0->unk18.z);
    temp_f30 = arg1->x;
    temp_f28 = arg1->y;
    temp_f2 = arg1->z;
    temp_f30 -= temp_s0->pos.x;
    temp_f28 -= temp_s0->pos.y;
    temp_f2 -= temp_s0->pos.z;
    temp_f24 = ((temp_f30 * sp28[0][0]) + (temp_f28 * sp28[1][0])) + (temp_f2 * sp28[2][0]);
    temp_f22 = ((temp_f30 * sp28[0][1]) + (temp_f28 * sp28[1][1])) + (temp_f2 * sp28[2][1]);
    temp_f20 = ((temp_f30 * sp28[0][2]) + (temp_f28 * sp28[1][2])) + (temp_f2 * sp28[2][2]);
    temp_f30 = func_800AEAC0(temp_s0->unk_40 / 2.0f) / func_800AEFD0(temp_s0->unk_40 / 2.0f) * temp_f20 * (4.0f / 3.0f);
    temp_f28 = (func_800AEAC0(temp_s0->unk_40 / 2.0f) / func_800AEFD0(temp_s0->unk_40 / 2.0f)) * temp_f20;
    arg2->x = (temp_f24 * (160.0f / (-temp_f30))) + 160.0f;
    arg2->y = ((temp_f22 * (120.0f / temp_f28)) + 120.0f);
}

void func_8001DB2C(s16 index, Vec3f* arg1, Vec2f* arg2) {
    Matrix4f sp28;
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f28;
    f32 temp_f30;
    f32 temp_f2;
    f32 temp_f2_2;
    unk_Struct00* temp_s0;

    temp_s0 = &D_800C3110[index];
    HuGuLookAtF(sp28, temp_s0->pos.x, temp_s0->pos.y, temp_s0->pos.z, temp_s0->unkC.x, temp_s0->unkC.y, temp_s0->unkC.z, temp_s0->unk18.x, temp_s0->unk18.y, temp_s0->unk18.z);
    temp_f30 = arg1->x;
    temp_f28 = arg1->y;
    temp_f2 = arg1->z;
    temp_f30 -= temp_s0->pos.x;
    temp_f28 -= temp_s0->pos.y;
    temp_f2 -= temp_s0->pos.z;
    temp_f24 = (temp_f30 * sp28[0][0]) + (temp_f28 * sp28[1][0]) + (temp_f2 * sp28[2][0]);
    temp_f22 = (temp_f30 * sp28[0][1]) + (temp_f28 * sp28[1][1]) + (temp_f2 * sp28[2][1]);
    temp_f20 = (temp_f30 * sp28[0][2]) + (temp_f28 * sp28[1][2]) + (temp_f2 * sp28[2][2]);
    temp_f30 = func_800AEAC0(temp_s0->unk_40 / 2.0f) / func_800AEFD0(temp_s0->unk_40 / 2.0f) * temp_f20 * (temp_s0->unk24.x / temp_s0->unk24.y);
    temp_f28 = func_800AEAC0(temp_s0->unk_40 / 2.0f) / func_800AEFD0(temp_s0->unk_40 / 2.0f) * temp_f20;
    temp_f2_2 = temp_s0->unk30.x / 4.0f;
    arg2->x = temp_f24 * (temp_f2_2 / -temp_f30) + temp_f2_2;
    temp_f0 = temp_s0->unk30.y / 4.0f;
    arg2->y = temp_f22 * (temp_f0 / temp_f28) + temp_f0;
}

void func_8001DD24(s16 index, f32 arg1, Vec3f* arg2, Vec3f* arg3) {
    Matrix4f sp28;
    f32 temp_f20;
    f32 temp_f4;
    f32 unk_var1;
    f32 unk_var2;
    unk_Struct00* temp_s0;

    temp_s0 = &D_800C3110[index];
    HuGuLookAtF(sp28, temp_s0->pos.x, temp_s0->pos.y, temp_s0->pos.z, temp_s0->unkC.x, temp_s0->unkC.y, temp_s0->unkC.z, temp_s0->unk18.x, temp_s0->unk18.y, temp_s0->unk18.z);
    temp_f20 = func_800AEAC0(temp_s0->unk_40 / 2.0f) / func_800AEFD0(temp_s0->unk_40 / 2.0f) * arg1;
    temp_f4 = temp_f20 * (4.0f / 3.0f);
    unk_var1 = arg2->x / 320.0f;
    unk_var2 = (240.0f - arg2->y) / 240.0f;
    arg3->x = 2.0f * temp_f4 * unk_var1 - temp_f4;
    arg3->y = 2.0f * temp_f20 * unk_var2 - temp_f20;
}
