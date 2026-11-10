#include "common.h"

typedef unk34D80Struct80 unk1EA70Struct18; /* D_800ED554 entries (common_structs.h) */

typedef struct unk1EA70StructC {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16* unk_04;
    /* 0x08 */ Matrix4f* unk_08;
} unk1EA70StructC; // sizeof 0xC

typedef struct unk1EA70Struct48 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ Matrix4f unk_04;
    /* 0x44 */ unk2C0C0StructC0* unk_44;
} unk1EA70Struct48; // sizeof 0x48

typedef struct unk1EA70Struct20 {
    /* 0x00 */ char unk_00[2];
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ char unk_14[4];
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ char unk_1E[2];
} unk1EA70Struct20; // sizeof 0x20

typedef struct unk1EA70Struct1C {
    /* 0x00 */ unk1EA70Struct20* unk_00;
    /* 0x04 */ u8* unk_04;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ u8 unk_09;
    /* 0x0A */ u8 unk_0A;
    /* 0x0B */ char unk_0B;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ u16 unk_18;
    /* 0x1A */ char unk_1A[2];
} unk1EA70Struct1C; // sizeof 0x1C

typedef struct unk1EA70Frame {
    /* 0x00 */ void* unk_00;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
} unk1EA70Frame; // sizeof 0xC

typedef struct unk1EA70AnimStep {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ char unk_04[4];
} unk1EA70AnimStep; // sizeof 0x8

typedef struct unk1EA70Anim {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ unk1EA70AnimStep* unk_04;
} unk1EA70Anim; // sizeof 0x8

typedef struct unk1EA70Struct3F40 {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ char unk_08[4];
    /* 0x0C */ unk1EA70Frame* unk_0C;
    /* 0x10 */ unk1EA70Anim* unk_10;
    /* 0x14 */ void* unk_14;
} unk1EA70Struct3F40; // sizeof 0x18

#define TEX_MASK(x) ((x) < 3 ? 1 : (x) < 5 ? 2 : (x) < 9 ? 3 : (x) < 17 ? 4 : (x) < 33 ? 5 : (x) < 65 ? 6 : (x) < 129 ? 7 : (x) < 257 ? 8 : 9)

void* func_80014614(s32);
void func_800196A0(Matrix4f, Matrix4f);
void func_80020544(s16 arg0, s16 arg1, unk1EA70StructC* arg2, s16 arg3);
void func_80020654(unk2C0C0StructC0* arg0, s16 arg1, s16 arg2);
void func_80020DCC(s32 arg0, u8* arg1);
s32 func_80021C50(s16 arg0, s16 arg1, s16 arg2);
void func_80021EA0(void);
s32 func_80024198(s32, s32, s32);
s16 func_8002451C(s32, void (*)(s32, u8*), s32);
s16 func_80038D5C(unk2C0C0StructC0*, u16, s32, char*);
void func_800399F0(s16);
s32 func_8009B850(u8*, u8**);
void func_800A0B90(Matrix4f, void*);
void DataCloseTemp(void*);
void guMtxCatF(float m[4][4], float n[4][4], float r[4][4]);

extern const char D_800CA8B8[], D_800CA8A8[], D_800CA898[], D_800CA888[], D_800CA878[], D_800CA868[], D_800CA85C[], D_800CA84C[], D_800CA83C[], D_800CA82C[], D_800CA81C[], D_800CA810[];
u8 D_800C31E0 = 0;
s16 D_800C31E4[] = { 0x0000, 0x3000, 0x2000, 0x0000 };
s16 D_800C31EC[] = { 1, 2, 6, 3, 4, 5 };
char* D_800C31F8[] = {
    (char*)D_800CA8B8, (char*)D_800CA8A8, (char*)D_800CA898, (char*)D_800CA888, (char*)D_800CA878, (char*)D_800CA868, (char*)D_800CA85C, (char*)D_800CA84C, (char*)D_800CA83C, (char*)D_800CA82C, (char*)D_800CA81C, (char*)D_800CA810
};
/* Colour keyframes read by func_8001E5A0 as bytes { time, r, g, b, a }; time 0xFF ends. */
u8 D_800C3228[] = {
    0x00, 0xFF, 0xFF, 0xFF, 0xFF,
    0x0A, 0xFF, 0xFF, 0x3C, 0xCC,
    0x12, 0xFF, 0x28, 0x00, 0x99,
    0xFF, 0x3C, 0x00, 0x1E, 0x1E,
};
u8 D_800C323C[] = {
    0x00, 0xFF, 0xFF, 0xFF, 0xFF,
    0x0A, 0xFF, 0xFF, 0x64, 0xCC,
    0x12, 0xFF, 0x78, 0x00, 0x99,
    0xFF, 0xD2, 0x00, 0x00, 0x1E,
};
u8 D_800C3250[] = {
    0x00, 0xF0, 0xFF, 0x96, 0xE6,
    0x0A, 0x75, 0xFF, 0xB0, 0xB2,
    0x12, 0xFF, 0xA1, 0x00, 0x80,
    0xFF, 0xFF, 0x3B, 0x05, 0x00,
};
u8 D_800C3264[] = {
    0x00, 0xDE, 0xD3, 0xC7, 0xBF,
    0x0A, 0x8F, 0x79, 0x6B, 0x8C,
    0x12, 0x5C, 0x45, 0x3D, 0x66,
    0xFF, 0x2E, 0x1E, 0x1C, 0x0A,
};
u8 D_800C3278[] = {
    0x00, 0xC9, 0xFF, 0xFA, 0xCC,
    0x0A, 0x63, 0xFF, 0xD7, 0x99,
    0x12, 0x29, 0xFF, 0xA1, 0x66,
    0xFF, 0x00, 0xF9, 0x6A, 0x32,
};
extern unk1EA70Struct1C* D_800ED4A8;
extern unk1EA70Struct18* D_800ED554;
extern s16 D_800ED5E6;
extern u16 D_800ED728;
extern s16* D_800F2C20;
extern Matrix4f* D_800F33A0;
extern s8 D_800F384E;
extern unk1EA70Struct3F40* D_800F3F40;
extern s16 D_800F3F48[][8];

void func_8001DE70(s16 arg0) {
    s16 i;
    unk_800ECDE0* temp_v1;

    D_800EE312 = arg0;
    for (i = 0; i < D_800F37DA; i++) {
        *(&D_800ED0A0 + i) = func_80023684(arg0 << 7, 0x7530);
        *(&D_800F33A8 + i) = func_80023684(arg0 << 8, 0x7530);
    }
    D_800ECDE0 = func_80023684(arg0 * sizeof(*D_800ECDE0), 0x7530);
    for (i = 0; i < arg0; i++) {
        temp_v1 = &D_800ECDE0[i];
        temp_v1->unk_00 = -1;
    }
    D_800C31E0 = 1;
    func_8001DFC0();
}

void func_8001DFC0() {
    u8 temp_v0;

    if (D_800C31E0 != 0) {
        temp_v0 = D_800F37F0;
        D_800EE318 = *(&D_800ED0A0 + temp_v0);
        D_800F3714 = *(&D_800F33A8 + temp_v0);
    }
}

u16 func_8001E00C(void* arg0, s32 arg1, u8 arg2) {
    s16 i;
    s16 temp;
    unk_800ECDE0* p2;

    for (i = 0; i < D_800EE312; i++) {
        if (D_800ECDE0[i].unk_00 == -1) {
            break;
        }
    }
    if (i == D_800EE312 || (temp = func_80024198(arg1, 0, 4)) == -1) {
        return 0xFFFF;
    }
    D_800ECDE0[i].unk_00 = temp;
    if (arg0 != (void*) -1) {
        temp = func_80039084(arg0);
        if (temp == -1) {
            func_8002456C(D_800ECDE0[i].unk_00);
            D_800ECDE0[i].unk_00 = -1;
        }
    } else {
        temp = -1;
    }
    D_800ECDE0[i].unk_02 = temp;
    D_800ECDE0[i].unk_10 = arg2;
    D_800ECDE0[i].unk_12 = D_800ECDE0[i].unk_13 = D_800ECDE0[i].unk_14 = D_800ECDE0[i].unk_15 = 0xFF;
    p2 = &D_800ECDE0[i];
    p2->unk_0A = 0;
    p2->unk_08 = 0;
    p2->unk_04 = 0;
    p2->unk_06 = 0;
    p2->unk_20 = 0;
    return i;
}
u16 func_8001E1D0(s16 index, s32 arg1) {
    s16 temp_v0;

    temp_v0 = func_8001E00C((void*) -1, D_800F2B7C[D_800ECDE0[index].unk_00].unk_20, arg1);
    D_800ECDE0[temp_v0].unk_02 = D_800ECDE0[index].unk_02;
    return temp_v0;
}

void func_8001E268(s16 index, u8 arg1, u8 arg2) {
    unk_800ECDE0* temp_v1;

    temp_v1 = &D_800ECDE0[index];
    temp_v1->unk_10 = temp_v1->unk_10 & ~arg1;
    temp_v1->unk_10 = arg2 | temp_v1->unk_10;
}

void func_8001E2A8(s16 index, u16 arg1) {
    D_800ECDE0[index].unk_04 = arg1;
}

u16 func_8001E2D0(s16 index) {
    return D_800ECDE0[index].unk_04;
}

void func_8001E2F8(s16 index, u8 arg1) {
    s32 unk_var;

    if (index != -1) {
        D_800ECDE0[index].unk_12 = arg1;
        unk_var = (arg1 != 0xFF) << 0x10;
        func_80025930(D_800ECDE0[index].unk_00, 0x10000, unk_var);
    }
}

void func_8001E360(s16 index, u8 arg1, u8 arg2, u8 arg3) {
    if (index != -1) {
        D_800ECDE0[index].unk_13 = arg1;
        D_800ECDE0[index].unk_14 = arg2;
        D_800ECDE0[index].unk_15 = arg3;
    }
}

void func_8001E3B4(s16 index) {
    unk_800ECDE0* temp_v1;

    temp_v1 = &D_800ECDE0[index];
    temp_v1->unk_0A = 0;
    temp_v1->unk_04 = 0;
    temp_v1->unk_10 = temp_v1->unk_10 & 0xFF7F;
    func_800258EC(temp_v1->unk_00, 4, 0);
}

void func_8001E40C(s16 index, s8 arg1, s8 arg2, s8 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8) {
    if (index != -1) {
        func_8001E268(index, 0x40, 0x40);
        D_800ECDE0[index].unk_16 = arg1;
        D_800ECDE0[index].unk_17 = arg2;
        D_800ECDE0[index].unk_18 = arg3;
        D_800ECDE0[index].unk_19 = arg4;
        D_800ECDE0[index].unk_1A = arg5;
        D_800ECDE0[index].unk_1B = arg6;
        D_800ECDE0[index].unk_1C = arg7;
        D_800ECDE0[index].unk_1D = arg8;
    }
}

void func_8001E534(s16 index, s32 arg1) {
    if (index != -1) {
        func_8001E268(index, 0x40, 0x40);
        D_800ECDE0[index].unk_20 = arg1;
        D_800ECDE0[index].unk_0E = 0;
        D_800ECDE0[index].unk_0C = 0;
    }
}

void func_8001E5A0(s32 arg0) {
    unk_800ECDE0* spr;
    unk2C0C0StructC0* model;
    unk1EA70Struct3F40* info;
    unk1EA70Anim* anim;
    unk1EA70Frame* frame;
    u8* key;
    u16 end;
    u8* prev;
    f32 t;
    s16 pos;
    s16 len;
    u16 w;
    u16 h;
    s16 x;
    s16 y;
    s16 j;
    s16 i;
    s16 nh;

    if (D_800C31E0 == 0) {
        return;
    }
    for (i = 0; i < D_800EE312; i++) {
        if (D_800ECDE0[i].unk_00 == -1) {
            continue;
        }
        spr = &D_800ECDE0[i];
        if (D_800F2B7C[spr->unk_00].unk_20 & 4) {
            continue;
        }
        if ((u16) spr->unk_02 == 0xFFFF) {
            continue;
        }
        if (spr->unk_10 & 0x80) {
            func_800258EC(spr->unk_00, 4, 4);
            spr->unk_10 &= ~0x80;
            continue;
        }
        model = D_800F2B7C[spr->unk_00].unk_6C;
        *model->unk_00 = D_800F3714;
        info = &D_800F3F40[(u16) spr->unk_02];
        anim = &info->unk_10[spr->unk_06];
        gDPSetCycleType(D_800F3714++, G_CYC_1CYCLE);
        if (spr->unk_10 & 0x40) {
            if (spr->unk_20 != 0) {
                key = (u8*) spr->unk_20;
                while (*key != 0xFF) {
                    if (spr->unk_0A < *key) {
                        break;
                    }
                    key += 5;
                }
                if (*key == 0xFF) {
                    end = anim->unk_02;
                } else {
                    end = *key;
                }
                prev = key - 5;
                pos = spr->unk_0A - prev[0];
                len = end - prev[0];
                t = (f32) pos / (f32) len;
                spr->unk_13 = prev[1] + (key[1] - prev[1]) * t;
                spr->unk_14 = prev[2] + (key[2] - prev[2]) * t;
                spr->unk_15 = prev[3] + (key[3] - prev[3]) * t;
                spr->unk_12 = prev[4] + (key[4] - prev[4]) * t;
            } else {
                t = (f32) spr->unk_0A / (f32) anim->unk_02;
                spr->unk_13 = (u8) spr->unk_16 + (spr->unk_1A - (u8) spr->unk_16) * t;
                spr->unk_14 = (u8) spr->unk_17 + (spr->unk_1B - (u8) spr->unk_17) * t;
                spr->unk_15 = (u8) spr->unk_18 + (spr->unk_1C - (u8) spr->unk_18) * t;
                spr->unk_12 = spr->unk_19 + (spr->unk_1D - spr->unk_19) * t;
            }
        }
        if (info->unk_04 == 1) {
            if (info->unk_06 & 0x8000) {
                gDPSetCombine(D_800F3714++, 0xFF97FF, 0xFF2DFEFF);
            } else {
                gDPSetCombine(D_800F3714++, 0x119623, 0xFF2FFFFF);
            }
            model->unk_80->unk_14 |= 0x10000;
            if (spr->unk_10 & 0x100) {
                gDPSetRenderMode(D_800F3714++, 0x5041C8, 0);
            } else {
                gDPSetRenderMode(D_800F3714++, 0x5049D8, 0);
            }
            gDPSetAlphaCompare(D_800F3714++, G_AC_THRESHOLD);
            gDPSetBlendColor(D_800F3714++, 0, 0, 0, 1);
            gDPSetPrimColor(D_800F3714++, 0, 0, spr->unk_13, spr->unk_14, spr->unk_15, spr->unk_12);
        } else if (spr->unk_12 == 0xFF) {
            if (spr->unk_10 & 0x100) {
                gDPSetRenderMode(D_800F3714++, 0x553048, 0);
            } else {
                gDPSetRenderMode(D_800F3714++, 0x553078, 0);
            }
            gDPSetCombine(D_800F3714++, 0xFFFFFF, 0xFFFCF279);
        } else {
            model->unk_80->unk_14 |= 0x10000;
            gDPSetAlphaCompare(D_800F3714++, G_AC_THRESHOLD);
            gDPSetBlendColor(D_800F3714++, 0, 0, 0, 1);
            gDPSetPrimColor(D_800F3714++, 0, 0, 0, 0, 0, spr->unk_12);
            if (spr->unk_10 & 0x100) {
                gDPSetRenderMode(D_800F3714++, 0x5041C8, 0);
            } else {
                gDPSetRenderMode(D_800F3714++, 0x5049D8, 0);
            }
            gDPSetCombine(D_800F3714++, 0x127624, 0xFFEF93C9);
        }
        gDPSetTextureFilter(D_800F3714++, D_800C31E4[(spr->unk_10 & 0x18) >> 3]);
        gSPClearGeometryMode(D_800F3714++, G_LIGHTING | G_CULL_BACK);
        gSPSetGeometryMode(D_800F3714++, G_ZBUFFER);
        frame = &info->unk_0C[anim->unk_04[(s16) spr->unk_04].unk_00];
        w = frame->unk_04;
        h = frame->unk_06;
        if (info->unk_04 == 1) {
            gDPSetTextureLUT(D_800F3714++, G_TT_NONE);
            if ((u8) info->unk_06 == 4) {
                gDPLoadTextureBlock_4b(D_800F3714++, frame->unk_00, G_IM_FMT_I, (s16) w, (s16) h, 0, G_TX_CLAMP, G_TX_CLAMP,
                                       TEX_MASK(frame->unk_04), TEX_MASK(frame->unk_06), G_TX_NOLOD, G_TX_NOLOD);
            } else {
                gDPLoadTextureBlock(D_800F3714++, frame->unk_00, G_IM_FMT_IA, G_IM_SIZ_8b, (s16) w, (s16) h, 0, G_TX_CLAMP,
                                    G_TX_CLAMP, TEX_MASK(frame->unk_04), TEX_MASK(frame->unk_06), G_TX_NOLOD, G_TX_NOLOD);
            }
        } else {
            gDPSetTextureLUT(D_800F3714++, G_TT_RGBA16);
            if (info->unk_04 < 0x11) {
                gDPLoadTLUT_pal16(D_800F3714++, 0, info->unk_14);
                gDPLoadTextureBlock_4b(D_800F3714++, frame->unk_00, G_IM_FMT_CI, (s16) w, (s16) h, 0, G_TX_CLAMP, G_TX_CLAMP,
                                       TEX_MASK(frame->unk_04), TEX_MASK(frame->unk_06), G_TX_NOLOD, G_TX_NOLOD);
            } else {
                gDPLoadTLUT_pal256(D_800F3714++, info->unk_14);
                gDPLoadTextureBlock(D_800F3714++, frame->unk_00, G_IM_FMT_CI, G_IM_SIZ_8b, (s16) w, (s16) h, 0, G_TX_CLAMP,
                                    G_TX_CLAMP, TEX_MASK(frame->unk_04), TEX_MASK(frame->unk_06), G_TX_NOLOD, G_TX_NOLOD);
            }
        }
        gSPVertex(D_800F3714++, osVirtualToPhysical(D_800EE318), 4, 0);
        gSP1Quadrangle(D_800F3714++, 0, 1, 2, 3, 0);
        nh = -h;
        x = -frame->unk_08;
        y = frame->unk_0A;
        D_800EE318->v.ob[0] = x;
        D_800EE318->v.ob[1] = y;
        D_800EE318->v.ob[2] = 0;
        D_800EE318->n.n[0] = D_800EE318->n.n[1] = D_800EE318->n.n[2] = -1;
        D_800EE318->v.tc[0] = 0;
        D_800EE318->v.tc[1] = 0;
        D_800EE318->n.a = 0xFF;
        D_800EE318++;
        D_800EE318->v.ob[0] = x;
        D_800EE318->v.ob[1] = nh + y;
        D_800EE318->v.ob[2] = 0;
        D_800EE318->n.n[0] = D_800EE318->n.n[1] = D_800EE318->n.n[2] = -1;
        D_800EE318->v.tc[0] = 0;
        D_800EE318->v.tc[1] = (-nh - 1) << 5;
        D_800EE318->n.a = 0xFF;
        D_800EE318++;
        D_800EE318->v.ob[0] = (s16) w + x;
        D_800EE318->v.ob[1] = nh + y;
        D_800EE318->v.ob[2] = 0;
        D_800EE318->n.n[0] = D_800EE318->n.n[1] = D_800EE318->n.n[2] = -1;
        D_800EE318->v.tc[0] = ((s16) w - 1) << 5;
        D_800EE318->v.tc[1] = (-nh - 1) << 5;
        D_800EE318->n.a = 0xFF;
        D_800EE318++;
        D_800EE318->v.ob[0] = (s16) w + x;
        D_800EE318->v.ob[1] = y;
        D_800EE318->v.ob[2] = 0;
        D_800EE318->n.n[0] = D_800EE318->n.n[1] = D_800EE318->n.n[2] = -1;
        D_800EE318->v.tc[0] = ((s16) w - 1) << 5;
        D_800EE318->v.tc[1] = 0;
        D_800EE318->n.a = 0xFF;
        D_800EE318++;
        gSPEndDisplayList(D_800F3714++);
        if (!(spr->unk_10 & 1) && (D_800F384E == 0 || (D_800F2B7C[spr->unk_00].unk_20 & 0x8000))) {
            for (j = 0; j < arg0; j++) {
                spr->unk_08++;
                spr->unk_0A++;
                if (spr->unk_08 >= anim->unk_04[(s16) spr->unk_04].unk_02) {
                    spr->unk_04++;
                    spr->unk_08 = 0;
                    if (anim->unk_00 <= (s16) spr->unk_04) {
                        if (spr->unk_10 & 4) {
                            spr->unk_10 |= 0x80;
                        }
                        if ((spr->unk_10 & 2) || anim->unk_04[(s16) spr->unk_04 - 1].unk_02 != -1) {
                            spr->unk_04--;
                            spr->unk_0A--;
                            break;
                        }
                        spr->unk_04 = 0;
                        spr->unk_0A = 0;
                    }
                }
            }
        }
    }
}

void func_8002019C(s32 index) {
    if (D_800C31E0 != 0) {
        if ((u16) D_800ECDE0[index].unk_02 != 0xFFFF) {
            func_80039A4C(D_800ECDE0[index].unk_02);
        }
        func_8002456C(D_800ECDE0[index].unk_00);
        D_800ECDE0[index].unk_00 = -1;
    }
}

void func_80020234() {
    s16 i;

    if (D_800C31E0 != 0) {
        for (i = 0; i < D_800EE312; i++) {
            if (D_800ECDE0[i].unk_00 != -1) {
                func_80039A4C(D_800ECDE0[i].unk_02);
            }
        }
        func_800238F0(0x7530);
        D_800C31E0 = 0;
    }
}

unk1EA70StructC* func_800202E8(s16 arg0, s16 arg1) {
    unk2C0C0StructC0* model;
    unk1EA70Struct18* anim;
    unk1EA70StructC* ret;

    model = D_800F2B7C[arg0].unk_6C;
    anim = &D_800ED554[D_800F2B7C[arg0].unk_08];
    ret = HuMemDirectMalloc(sizeof(unk1EA70StructC));
    ret->unk_08 = HuMemDirectMalloc(((anim->unk_02 + arg1) / arg1) * (model->unk_70 << 6));
    ret->unk_04 = HuMemDirectMalloc(model->unk_70 * 2);
    ret->unk_00 = anim->unk_02;
    ret->unk_02 = arg1;
    func_80020544(arg0, arg1, ret, -1);
    return ret;
}

unk1EA70StructC* func_8002040C(s16 arg0, s16 arg1, char* arg2) {
    unk2C0C0StructC0* model;
    unk1EA70Struct18* anim;
    unk1EA70StructC* ret;
    s16 temp;

    model = D_800F2B7C[arg0].unk_6C;
    anim = &D_800ED554[D_800F2B7C[arg0].unk_08];
    temp = func_80033718(model, arg2);
    ret = HuMemDirectMalloc(sizeof(unk1EA70StructC));
    ret->unk_08 = HuMemDirectMalloc(((anim->unk_02 + arg1) / arg1) << 6);
    ret->unk_04 = HuMemDirectMalloc(model->unk_70 * 2);
    ret->unk_00 = anim->unk_02;
    ret->unk_02 = arg1;
    func_80020544(arg0, arg1, ret, temp);
    return ret;
}

void func_80020544(s16 arg0, s16 arg1, unk1EA70StructC* arg2, s16 arg3) {
    unk2C0C0StructC0* model;
    unk1EA70Struct18* anim;
    s16 i;

    model = D_800F2B7C[arg0].unk_6C;
    anim = &D_800ED554[D_800F2B7C[arg0].unk_08];
    D_800F33A0 = arg2->unk_08;
    D_800F2C20 = arg2->unk_04;
    D_800ED5E6 = 0;
    for (i = 0; i < anim->unk_02; i += arg1) {
        func_80034ED8(model, i, (s32) anim, 1);
        D_800F33D4 = 0;
        func_80020654(model, 0, arg3);
    }
}

void func_80020654(unk2C0C0StructC0* arg0, s16 arg1, s16 arg2) {
    Matrix4f sp10;
    unk2C0C0Struct50* temp_s0;
    s16 pushed;
    s16 i;
    s16 child;

    temp_s0 = &arg0->unk_A0[arg1];
    pushed = 0;
    func_800A2A50(sp10);
    if (temp_s0->unk_38.x != 0.0f || temp_s0->unk_38.y != 0.0f || temp_s0->unk_38.z != 0.0f) {
        MtxTranslate(sp10, temp_s0->unk_38.x, temp_s0->unk_38.y, temp_s0->unk_38.z);
        pushed = 1;
    }
    if (temp_s0->unk_44.x != 0.0f || temp_s0->unk_44.y != 0.0f || temp_s0->unk_44.z != 0.0f) {
        MtxRotate(sp10, temp_s0->unk_44.x, temp_s0->unk_44.y, temp_s0->unk_44.z);
        pushed = 1;
    }
    if (temp_s0->unk_50.x != 1.0f || temp_s0->unk_50.y != 1.0f || temp_s0->unk_50.z != 1.0f) {
        MtxScale(sp10, temp_s0->unk_50.x, temp_s0->unk_50.y, temp_s0->unk_50.z);
        pushed = 1;
    }
    if (pushed != 0) {
        D_800F33D4++;
        MtxMult(sp10, D_800F5480[D_800F33D4], D_800F5480[D_800F33D4 + 1]);
    }
    if (D_800ED5E6 < arg0->unk_70) {
        D_800F2C20[arg1] = D_800ED5E6;
    }
    if ((arg2 == -1) | (arg2 == arg1)) {
        func_8002C37C(D_800F33A0[D_800ED5E6++], D_800F54C0[D_800F33D4]);
    }
    for (i = 0; i < temp_s0->unk_00; i++) {
        child = temp_s0->unk_04[i];
        if (child & 0x8000) {
            if (child != -1) {
                func_80020654(arg0, child & 0x7FFF, arg2);
            }
        }
    }
    if (pushed != 0) {
        D_800F33D4--;
    }
}

void func_80020958(s16 arg0, unk1EA70StructC* arg1, s16 arg2) {
    unk2C0C0StructC0* model;
    s16 i;
    s16 frame;

    if (arg2 >= arg1->unk_00) {
        arg2 = arg1->unk_00 - 1;
    }
    if (arg2 < 0) {
        arg2 = 0;
    }
    model = D_800F2B7C[arg0].unk_6C;
    D_800F2B7C[arg0].unk_08 = -1;
    frame = model->unk_70 * (arg2 / arg1->unk_02);
    D_800ED5E6 = 0;
    D_800F33A0 = &arg1->unk_08[frame];
    for (i = 0; i < model->unk_70; i++) {
        func_8002C37C(model->unk_A0[i].unk_64, D_800F33A0[arg1->unk_04[i]]);
    }
}

void func_80020ACC(s16 arg0, unk1EA70StructC* arg1, Matrix4f arg2, s16 arg3) {
    unk_ovl_2D_struct* obj;

    obj = &D_800F2B7C[arg0];
    if (arg3 >= arg1->unk_00) {
        arg3 = arg1->unk_00 - 1;
    }
    if (arg3 < 0) {
        arg3 = 0;
    }
    func_800A2A50(arg2);
    if (obj->unk_24 != 0.0f || obj->unk_28 != 0.0f || obj->unk_2C != 0.0f) {
        MtxTranslate(arg2, obj->unk_24, obj->unk_28, obj->unk_2C);
    }
    if (obj->unk_30 != 0.0f || obj->unk_34 != 0.0f || obj->unk_38 != 0.0f) {
        MtxRotate(arg2, obj->unk_30, obj->unk_34, obj->unk_38);
    }
    if (obj->unk_3C != 1.0f || obj->unk_40 != 1.0f || obj->unk_44 != 1.0f) {
        MtxScale(arg2, obj->unk_3C, obj->unk_40, obj->unk_44);
    }
    guMtxCatF(arg1->unk_08[arg3 / arg1->unk_02], arg2, arg2);
}

void func_80020CC4(unk1EA70StructC* arg0) {
    HuMemDirectFree(arg0->unk_08);
    HuMemDirectFree(arg0->unk_04);
    HuMemDirectFree(arg0);
}

unk1EA70Struct48* func_80020CFC(s16 arg0, char* arg1) {
    unk_ovl_2D_struct* obj;
    unk1EA70Struct48* ret;
    s16 idx;

    obj = &D_800F2B7C[arg0];
    ret = func_80023684(sizeof(unk1EA70Struct48), obj->unk_6C->unk_68 + 1);
    idx = func_8002451C(0, func_80020DCC, 2);
    ret->unk_02 = idx;
    D_800F2B7C[idx].unk_BC = ret;
    ret->unk_44 = obj->unk_6C;
    ret->unk_00 = func_80033718(obj->unk_6C, arg1);
    func_800A2A50(ret->unk_04);
    return ret;
}

void func_80020DCC(s32 arg0, u8* arg1) {
    Matrix4f sp10;
    Matrix4f sp50;
    unk1EA70Struct48* data;
    unk2C0C0StructC0* model;

    data = D_800F2B7C[D_800ED728].unk_BC;
    func_800A0B90(sp10, arg1 + 0x40);
    func_800196A0(sp10, sp50);
    model = data->unk_44;
    func_800A0B90(sp10, D_800ED0D8[model->unk_28][model->unk_80[data->unk_00].unk_12].unk_44);
    MtxMult(sp10, sp50, data->unk_04);
}

void func_80020EA0(s16 arg0, u8* arg1, s16 arg2, u8* arg3) {
    unk2C0C0StructC0* src;
    unk2C0C0StructC0* dst;
    unk2C0C0Struct40* obj40;
    unk2C0C0Struct50* obj50;
    s16 hash;
    s16 i;
    s16 j;
    s16 k;
    s16 l;

    src = D_800F2B7C[arg0].unk_6C;
    dst = D_800F2B7C[arg2].unk_6C;
    hash = func_8001CD00(arg1);
    for (i = 0; i < src->unk_6A; i++) {
        if (src->unk_80[i].unk_08 == hash && func_8009B850(dst->unk_80[i].unk_18, &arg1) != 0) {
            break;
        }
    }
    if (i == src->unk_6A) {
        osSyncPrintf("Can't find ObjName %s\n", arg1);
        return;
    }
    hash = func_8001CD00(arg3);
    for (j = 0; j < dst->unk_6A; j++) {
        if (dst->unk_80[j].unk_08 == hash && func_8009B850(dst->unk_80[j].unk_18, &arg3) != 0) {
            break;
        }
    }
    if (j == dst->unk_6A) {
        osSyncPrintf("Can't find ObjName %s\n", arg3);
        return;
    }
    if (dst->unk_A0 == (unk2C0C0Struct50*) -1) {
        for (k = 0; k < dst->unk_84; k++) {
            obj40 = &dst->unk_88[k];
            if (obj40->unk_00 == j) {
                obj40->unk_48 = src;
                obj40->unk_00 = i;
                return;
            }
        }
    } else {
        for (k = 0; k < dst->unk_70; k++) {
            obj50 = &dst->unk_A0[k];
            for (l = 0; l < obj50->unk_00; l++) {
                if (obj50->unk_04[l] == j) {
                    obj50->unk_60 = src;
                    obj50->unk_04[l] = i;
                    break;
                }
            }
        }
    }
}

void func_800211BC(s16 index, u8 arg1) {
    s16 i;
    unk2C0C0StructC0* temp_a3;

    temp_a3 = D_800F2B7C[index].unk_6C;
    for (i = 0; i < temp_a3->unk_6A; i++) {
        temp_a3->unk_80[i].unk_02 = arg1;
    }
}

void func_80021240(s16 index) {
    s16 i;
    unk2C0C0Struct90* temp_v1;
    unk2C0C0StructC0* temp_s0;

    temp_s0 = D_800F2B7C[index].unk_6C;
    func_80025930(index, 0x110000, 0x110000);
    for (i = 0; i < temp_s0->unk_76; i++) {
        temp_s0->unk_A8[i].unk_0D = 0xFF;
        temp_v1 = &temp_s0->unk_A8[i];
        temp_v1->unk_0C = temp_v1->unk_0C | 5;
    }
    func_80025AD4(index);
}

unk1EA70Struct1C* func_80021308(s32 arg0, s16 arg1) {
    unk1EA70Struct1C* ret;
    void* file;
    s16 sprite;
    s16 i;
    u16 idx;

    ret = func_80023684(sizeof(unk1EA70Struct1C), 0x7918);
    ret->unk_18 = arg1;
    ret->unk_00 = func_80023684(arg1 * sizeof(unk1EA70Struct20), 0x7918);
    ret->unk_04 = func_80023684(arg1, 0x7918);
    file = func_80014614(arg0);
    sprite = func_80039084(file);
    DataCloseTemp(file);
    for (i = 0; i < arg1; i++) {
        idx = func_8001E00C((void*) -1, 0x284, 8);
        ret->unk_00[i].unk_1C = idx;
        D_800ECDE0[(s16) idx].unk_02 = sprite;
        func_8001E268(idx, 4, 4);
        ret->unk_04[i] = 0;
    }
    ret->unk_14 = 1.0f;
    ret->unk_10 = 1.0f;
    ret->unk_0C = 1.0f;
    ret->unk_0A = 0xFF;
    ret->unk_09 = 0xFF;
    ret->unk_08 = 0xFF;
    return ret;
}

void func_80021474(unk1EA70Struct1C* arg0) {
    s16 i;

    for (i = 0; i < arg0->unk_18; i++) {
        func_8002019C(arg0->unk_00[i].unk_1C);
    }
    func_80023728(arg0->unk_04);
    func_80023728(arg0->unk_00);
    func_80023728(arg0);
}

void func_800214FC(unk1EA70Struct1C* arg0) {
    unk1EA70Struct20* e;
    unk1EA70Struct3F40* info;
    s16 i;
    s16 obj;

    for (i = 0; i < arg0->unk_18; i++) {
        if (arg0->unk_04[i] == 0) {
            continue;
        }
        e = &arg0->unk_00[i];
        obj = D_800ECDE0[e->unk_1C].unk_00;
        info = &D_800F3F40[(u16) D_800ECDE0[e->unk_1C].unk_02];
        if (e->unk_06 != 0) {
            if (--e->unk_06 != 0) {
                continue;
            }
            func_800258EC(obj, 4, 0);
            D_800ECDE0[arg0->unk_00[i].unk_1C].unk_04 = 0;
        }
        switch (arg0->unk_04[i]) {
            case 1:
                if (info->unk_04 != 1) {
                    func_8001E2F8(e->unk_1C, e->unk_04);
                } else {
                    func_8001E2F8(e->unk_1C, ~e->unk_04);
                }
                break;
            case 2:
                e->unk_0C += e->unk_18;
                e->unk_18 -= 0.3f;
                func_80025798(obj, e->unk_08, e->unk_0C, e->unk_10);
                if (info->unk_04 != 1) {
                    func_8001E2F8(e->unk_1C, e->unk_04);
                } else {
                    func_8001E2F8(e->unk_1C, ~e->unk_04);
                }
                break;
            case 3:
                e->unk_0C += e->unk_18;
                e->unk_18 -= 0.3f;
                func_80025798(obj, e->unk_08, e->unk_0C, e->unk_10);
                break;
        }
        e->unk_04 += 0xF;
        if (D_800F2B7C[obj].unk_20 & 4) {
            arg0->unk_04[i] = 0;
        }
    }
}

s16 func_80021794(unk1EA70Struct1C* arg0, s16 arg1, f32 arg2, f32 arg3, f32 arg4, u16 arg5) {
    s16 i;
    s16 obj;
    unk1EA70Struct3F40* info;
    unk_800ECDE0* spr;

    for (i = 0; i < arg0->unk_18; i++) {
        if (arg0->unk_04[i] == 0) {
            break;
        }
    }
    if (i == arg0->unk_18) {
        return -1;
    }
    obj = D_800ECDE0[arg0->unk_00[i].unk_1C].unk_00;
    arg0->unk_00[i].unk_08 = arg2;
    arg0->unk_00[i].unk_0C = arg3;
    arg0->unk_00[i].unk_10 = arg4;
    arg0->unk_00[i].unk_18 = 0.0f;
    arg0->unk_00[i].unk_04 = 0;
    arg0->unk_04[i] = arg5;
    arg0->unk_00[i].unk_02 = arg1;
    arg0->unk_00[i].unk_06 = 0;
    info = &D_800F3F40[(u16) D_800ECDE0[arg0->unk_00[i].unk_1C].unk_02];
    if (info->unk_04 != 1) {
        func_8001E2F8(arg0->unk_00[i].unk_1C, 0);
    } else {
        func_8001E2F8(arg0->unk_00[i].unk_1C, 0xFF);
    }
    func_800258EC(obj, 4, 0);
    spr = &D_800ECDE0[arg0->unk_00[i].unk_1C];
    spr->unk_0A = 0;
    spr->unk_04 = 0;
    func_8001E360(arg0->unk_00[i].unk_1C, arg0->unk_08, arg0->unk_09, arg0->unk_0A);
    func_80025798(obj, arg2, arg3, arg4);
    func_80025830(obj, arg0->unk_0C, arg0->unk_10, arg0->unk_14);
    func_80025F10(obj, (s16) (1 << arg1));
    return i;
}

void func_80021A00(unk1EA70Struct1C* arg0, s16 arg1, s16 arg2) {
    s16 obj;

    if (arg1 == -1) {
        return;
    }
    obj = D_800ECDE0[arg0->unk_00[arg1].unk_1C].unk_00;
    if (arg2 == 0) {
        func_800258EC(obj, 4, 0);
        D_800ECDE0[arg0->unk_00[arg1].unk_1C].unk_04 = 0;
        arg0->unk_00[arg1].unk_06 = 0;
    } else {
        func_800258EC(obj, 4, 4);
        arg0->unk_00[arg1].unk_06 = arg2;
    }
}

void func_80021AF4(unk1EA70Struct1C* arg0, f32 arg1, f32 arg2, f32 arg3) {
    arg0->unk_0C = arg1;
    arg0->unk_10 = arg2;
    arg0->unk_14 = arg3;
}

void func_80021B04(unk1EA70Struct1C* arg0, u8 arg1, u8 arg2, u8 arg3) {
    arg0->unk_08 = arg1;
    arg0->unk_09 = arg2;
    arg0->unk_0A = arg3;
}

void func_80021B14(s16 arg0, s16 arg1, s32 arg2) {
    void* file;
    s16 i;
    u8 flag;
    s16 idx;

    for (i = 0; i < 4; i++) {
        D_800F3F48[arg1][i] = -1;
    }
    flag = (arg2 & 0x80) ? 0 : 6;
    idx = arg2 & 0xF;
    file = DataRead(func_80021C50(arg1, flag, idx));
    D_800F3F48[arg1][idx] = func_80038A9C(D_800F2B7C[arg0].unk_6C, file, 0, D_800C31F8[arg1 + flag]);
    DataClose(file);
    func_80025AD4(arg0);
    func_80025B34(arg0);
}

s32 func_80021C50(s16 arg0, s16 arg1, s16 arg2) {
    switch (arg2) {
        case 0:
            if (arg1 == 0) {
                return (D_800C31EC[arg0] << 16) | 0xA0;
            }
            return (D_800C31EC[arg0] << 16) | 0xA1;
        case 1:
            if (arg1 == 0) {
                return (D_800C31EC[arg0] << 16) | 0xA2;
            }
            return (D_800C31EC[arg0] << 16) | 0xA1;
    }
    return 0;
}

void func_80021CDC(s16 arg0, s16 arg1, s32 arg2) {
    void* file;
    u8 flag;
    s16 idx;
    u16 old;

    flag = (arg2 & 0x80) ? 0 : 6;
    idx = arg2 & 0xF;
    if (D_800F3F48[arg1][idx] == -1) {
        file = DataRead(func_80021C50(arg1, flag, idx));
        D_800F3F48[arg1][idx] = func_80038A9C(D_800F2B7C[arg0].unk_6C, file, 0, D_800C31F8[arg1 + flag]);
        DataClose(file);
    } else {
        old = D_800F3F48[arg1][idx];
        D_800F3F48[arg1][idx] = func_80038D5C(D_800F2B7C[arg0].unk_6C, old, 0, D_800C31F8[arg1 + flag]);
        func_800399F0(old);
    }
}

void func_80021E58(void) {
    omAddObj(0x7F76, 0, 0, -1, func_80021EA0);
    D_800ED4A8 = func_80021308(0x29, 10);
}

void func_80021EA0() {
    func_800214FC(D_800ED4A8);
}

void func_80021EC0(s16 arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 x;
    f32 y;
    f32 z;
    f32 scale;
    s16 i;
    s16 slot;
    s16 idx;
    s32 spr;
    s32 pad[2];

    if (arg0 == 0) {
        func_80021AF4(D_800ED4A8, 12.0f, 12.0f, 12.0f);
        idx = D_800ED4A8->unk_00[func_80021794(D_800ED4A8, 0, arg1, arg2, arg3, 4)].unk_1C;
        func_80025930(D_800ECDE0[idx].unk_00, 0x70000000, 0x70000000);
        func_80025F60(D_800ECDE0[idx].unk_00, 0x1400);
        func_8001E534(idx, (s32) D_800C323C);
        D_800ECDE0[idx].unk_10 |= 0x100;
    } else if (arg0 == 1) {
        func_80021AF4(D_800ED4A8, 12.0f, 12.0f, 12.0f);
        idx = D_800ED4A8->unk_00[func_80021794(D_800ED4A8, 0, arg1, arg2, arg3, 4)].unk_1C;
        func_80025930(D_800ECDE0[idx].unk_00, 0x70000000, 0x70000000);
        func_80025F60(D_800ECDE0[idx].unk_00, 0x1400);
        func_8001E534(idx, (s32) D_800C3278);
        D_800ECDE0[idx].unk_10 |= 0x100;
    } else {
        for (i = 0; i < 4; i++) {
            if ((i == 0) | (i == 3)) {
                x = arg1;
                y = arg2;
                z = arg3;
            } else {
                x = arg1 + ((rand8() & 0x1F) - 0x10) * 12.0f;
                y = arg2 + ((rand8() & 0x1F) - 0x10) * 12.0f;
                z = arg3 + ((rand8() & 0x1F) - 0x10) * 1.2f;
            }
            scale = (s16) (i * 2.4f + 12.0f);
            func_80021AF4(D_800ED4A8, scale, scale, scale);
            slot = func_80021794(D_800ED4A8, 0, x, y, z, 4);
            if (slot == -1) {
                break;
            }
            spr = (u16) D_800ED4A8->unk_00[slot].unk_1C;
            idx = D_800ED4A8->unk_00[slot].unk_1C;
            func_80025930(D_800ECDE0[idx].unk_00, 0x70000000, 0x70000000);
            func_80025F60(D_800ECDE0[idx].unk_00, 0x1400);
            switch (i) {
                case 0:
                    func_8001E534(spr, (s32) D_800C3228);
                    break;
                case 1:
                    func_8001E534(spr, (s32) D_800C323C);
                    break;
                case 2:
                    func_8001E534(spr, (s32) D_800C3250);
                    break;
                case 3:
                    func_8001E534(spr, (s32) D_800C3264);
                    break;
            }
            func_80021A00(D_800ED4A8, slot, i * 4);
            D_800ECDE0[(s16) spr].unk_10 |= 0x100;
        }
    }
}
