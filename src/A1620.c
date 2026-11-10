#include "common.h"

/* guMtxF2L (Hudson's -O0 version: halves stored separately) */
void func_800A0A20(Matrix4f mf, void* m) {
    s32 i;
    s32 j;
    s32 e1;
    s32 e2;
    s16* ai;
    u16* af;

    ai = (s16*)m;
    af = (u16*)((u8*)m + 0x20);
    for (i = 0; i < 4; i++)
        for (j = 0; j < 2; j++) {
            e1 = mf[i][j * 2] * 65536.0f;
            e2 = *(&mf[i][j * 2] + 1) * 65536.0f;
            *ai = e1 >> 16;
            *(ai + 1) = e2 >> 16;
            ai += 2;
            *af = e1;
            *(af + 1) = e2;
            af += 2;
        }
}

/* guMtxL2F */
void func_800A0B90(Matrix4f mf, void* m) {
    s32 i;
    s32 j;
    u16* ai;
    u16* af;

    ai = (u16*)m;
    af = (u16*)((u8*)m + 0x20);
    for (i = 0; i < 4; i++)
        for (j = 0; j < 2; j++) {
            mf[i][j * 2] = (s32)((*ai << 16) | *af) * (1.0f / 65536.0f);
            *(&mf[i][j * 2] + 1) = (s32)((*(ai + 1) << 16) | *(af + 1)) * (1.0f / 65536.0f);
            ai += 2;
            af += 2;
        }
}

void func_800A0D00(Vec3f* v, f32 x, f32 y, f32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}
void func_800A0D50(Vec3f* ptr, Vec3f* ptr2) {
    *ptr = *ptr2;
}