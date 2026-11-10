#include "common.h"
#include "PR/gu.h"



void func_80023040(void) {
    s16 i;

    for (i = 0; i < 8; i++) {
        D_800EE9A0.def[i].flags = 0;
        D_800EE9A0.def[i].col[0] = D_800EE9A0.def[i].col[1] = D_800EE9A0.def[i].col[2] = 0x40;
        D_800EE9A0.def[i].dir[0] = D_800EE9A0.def[i].dir[1] = 0;
        D_800EE9A0.def[i].dir[2] = 100;
    }
    D_800EE9A0.count = 1;
}
void func_800230D0(s32 arg0) {
}

void func_800230D8(s16 arg0) {
    f32 mf[4][4];
    Light* light;
    f32 x;
    f32 y;
    f32 z;
    f32 tx;
    f32 ty;
    f32 tz;
    f32 len;
    s16 i;

    D_800ECB28 = D_800EE9A0.lights[D_800F37F0][arg0];
    for (i = 0; i < D_800EE9A0.count + 1; i++) {
        light = &D_800ECB28[i];
        light->l.col[0] = light->l.colc[0] = D_800EE9A0.def[i].col[0];
        light->l.col[1] = light->l.colc[1] = D_800EE9A0.def[i].col[1];
        light->l.col[2] = light->l.colc[2] = D_800EE9A0.def[i].col[2];
        if (D_800EE9A0.def[i].flags & 1) {
            x = D_800EE9A0.def[i].dir[0];
            y = D_800EE9A0.def[i].dir[1];
            z = D_800EE9A0.def[i].dir[2];
            guMtxL2F(mf, &D_800F2BCC[1]);
            tx = x * mf[0][0] + y * mf[1][0] + z * mf[2][0];
            ty = x * mf[0][1] + y * mf[1][1] + z * mf[2][1];
            tz = x * mf[0][2] + y * mf[1][2] + z * mf[2][2];
            len = tx * tx + ty * ty;
            len = func_800B1750(len + tz * tz);
            light->l.dir[0] = (tx / len) * 120.0f;
            light->l.dir[1] = (ty / len) * 120.0f;
            light->l.dir[2] = (tz / len) * 120.0f;
        } else {
            light->l.dir[0] = D_800EE9A0.def[i].dir[0];
            light->l.dir[1] = D_800EE9A0.def[i].dir[1];
            light->l.dir[2] = D_800EE9A0.def[i].dir[2];
        }
    }
}
void func_80023370(void) {
    s16 i;

    D_800ECB28 = D_800EE9A0.lights[D_800F37F0][0];
    for (i = 0; i < D_800EE9A0.count + 1; i++) {
        D_800ECB28[i].l.col[0] = D_800ECB28[i].l.colc[0] = D_800EE9A0.def[i].col[0];
        D_800ECB28[i].l.col[1] = D_800ECB28[i].l.colc[1] = D_800EE9A0.def[i].col[1];
        D_800ECB28[i].l.col[2] = D_800ECB28[i].l.colc[2] = D_800EE9A0.def[i].col[2];
    }
}
void func_80023448(s16 arg0) {
    if (arg0 >= 8) {
        arg0 = 7;
    }
    D_800EE9A0.count = arg0;
}
void func_8002346C(s16 arg0, s32 arg1, s32 arg2) {
    if (D_800EE9A0.count >= arg0) {
        D_800EE9A0.def[arg0].flags = arg2 | (D_800EE9A0.def[arg0].flags & ~arg1);
    }
}
void func_800234B8(s16 arg0, u8 arg1, u8 arg2, u8 arg3) {
    if (D_800EE9A0.count >= (s16)arg0) {
        D_800EE9A0.def[(s16)arg0].col[0] = arg1;
        D_800EE9A0.def[(s16)arg0].col[1] = arg2;
        D_800EE9A0.def[(s16)arg0].col[2] = arg3;
    }
}
void func_80023504(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 len;

    if (D_800EE9A0.count >= (s16)arg0) {
        len = arg1 * arg1 + arg2 * arg2;
        len = func_800B1750(len + arg3 * arg3);
        D_800EE9A0.def[(s16)arg0].dir[0] = (arg1 / len) * 120.0f;
        D_800EE9A0.def[(s16)arg0].dir[1] = (arg2 / len) * 120.0f;
        D_800EE9A0.def[(s16)arg0].dir[2] = (arg3 / len) * 120.0f;
    }
}