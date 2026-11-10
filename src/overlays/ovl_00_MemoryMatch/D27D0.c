#include "common.h"
#include "MemoryMatch.h"
#include "sprite65770.h"

typedef struct Unk {
    char unk_00[5];
    u8 unk5;
    char unk_06[0x26];
} Unk;

extern s16 D_800FE1DA_MemoryMatch;
extern omObjData* D_800FE1A0_MemoryMatch;
extern omObjData* D_800FE1A8_MemoryMatch[6];
extern omObjData* D_800FE1C0_MemoryMatch[6];
extern s16 D_800FE1D8_MemoryMatch;
extern s16 D_800FE1DC_MemoryMatch;
extern s16 D_800FE1DE_MemoryMatch;
extern s16 D_800FE1E0_MemoryMatch;
extern u16 D_800FE1E2_MemoryMatch;
extern s16 D_800FE1E4_MemoryMatch;
extern f32 D_800FE250_MemoryMatch[4][2];
extern f32 D_800FE270_MemoryMatch[4][2];
extern f32 D_800FE290_MemoryMatch[4][2];
extern u16 D_800FE2B0_MemoryMatch[8];
extern omObjData* D_800EDE70[];
extern u16 D_800EE984;
void func_800FB558_MemoryMatch(omObjData*);
void func_800FB570_MemoryMatch(void);
void func_800FB888_MemoryMatch(omObjData*);
void func_800FBC34_MemoryMatch(omObjData*);
void func_800FC5A4_MemoryMatch(omObjData*);

typedef struct unk_MemoryMatch_6C {
/* 0x00 */ char unk_00[0x27];
/* 0x27 */ u8 unk_27;
/* 0x28 */ char unk_28[0x10];
/* 0x38 */ f32 unk_38;
/* 0x3C */ char unk_3C[0x18];
/* 0x54 */ u8 unk_54;
/* 0x55 */ char unk_55[0x17];
} unk_MemoryMatch_6C; //sizeof 0x6C

typedef struct unk_MemoryMatch_ED554 {
/* 0x00 */ char unk_00[2];
/* 0x02 */ s16 unk_02;
/* 0x04 */ char unk_04[0x14];
} unk_MemoryMatch_ED554; //sizeof 0x18 (34D80.c's unk34D80Struct80 view)

extern unk_MemoryMatch_ED554* D_800ED554;
extern s16 D_800FE230_MemoryMatch[2];
extern f32 D_800FE248_MemoryMatch[2];
extern u16 D_800FE234_MemoryMatch[2];
extern f32 D_800FE238_MemoryMatch[2][2];
f32 func_800FB588_MemoryMatch(f32, f32, f32);
void func_800FBF24_MemoryMatch(omObjData*);
void func_800FCD58_MemoryMatch(omObjData*);
void func_800FC8A0_MemoryMatch(s16, Vec3f*, Vec3f*);
void func_800FC9E4_MemoryMatch(s16, Vec3f*, Vec3f*);
void func_800091BC(omObjData*, s32, s32, s32);
void func_80067284(s16, s16, f32);
void func_80066DF4(s16, s16, s16, f32, f32, f32);
extern u16 D_800FE1E8_MemoryMatch[6][2];
extern u8 D_800F64F8;
extern f32 D_800FE200_MemoryMatch[];
extern f32 D_800FE218_MemoryMatch[];
void func_80026040(s16);
void func_800FB778_MemoryMatch(omObjData*);
void func_800FB9FC_MemoryMatch(omObjData*);
void func_80027E48(s16 arg0, f32 arg1, f32 arg2, u16 arg3, u16 arg4, char* arg5, u8 arg6);

/* .data */
f32 D_800FD8C0_MemoryMatch[4] = { 3.0f, 4.0f, 3.0f, 3.0f };
u8 D_800FD8D0_MemoryMatch[] = "\x82\x72\x82\x73\x82\x60\x82\x71\x82\x73"; /* START (full-width) */
u8 D_800FD8DC_MemoryMatch[] = "\x82\x65\x82\x68\x82\x6D\x82\x68\x82\x72\x82\x67"; /* FINISH */
u8 D_800FD8EC_MemoryMatch[] = "\x82\x73\x82\x68\x82\x6C\x82\x64\x82\x74\x82\x6F"; /* TIMEUP */

void func_800FB360_MemoryMatch(void) {
    s16 i;

    D_800FE1A0_MemoryMatch = omAddObj(0xA, 0, 0, -1, func_800FB558_MemoryMatch);
    D_800FE1E0_MemoryMatch = 0;
    D_800FE1DC_MemoryMatch = 0;
    D_800FE1D8_MemoryMatch = 0;
    D_800EE984 = 0;
    D_800FE1DE_MemoryMatch = 0;
    D_800FE1DA_MemoryMatch = 0;
    for (i = 0; i < 6; i++) {
        omSetStatBit(D_800FE1A8_MemoryMatch[D_800FE1D8_MemoryMatch] = omAddObj(0xB, 1, 0, -1, func_800FB888_MemoryMatch), 0xA0);
        D_800FE1D8_MemoryMatch++;
    }
    for (i = 0; i < 2; i++) {
        D_800FE1C0_MemoryMatch[D_800FE1DC_MemoryMatch++] = omAddObj(0xC, 2, 0, -1, func_800FBC34_MemoryMatch);
    }
    for (i = 0; i < 4; i++) {
        omSetStatBit(D_800EDE70[D_800EE984] = omAddObj(0xD, 7, 0, -1, func_800FC5A4_MemoryMatch), 0xA0);
        D_800EE984++;
    }
    D_800FE1E4_MemoryMatch = InitSprite(0x2A);
}
void func_800FB558_MemoryMatch(omObjData* arg0) {
    arg0->func_ptr = func_800FB570_MemoryMatch;
    D_800FE1E2_MemoryMatch = 0;
}
void func_800FB570_MemoryMatch(void) {
    D_800FE1E2_MemoryMatch++;
}
f32 func_800FB588_MemoryMatch(f32 cur, f32 target, f32 step) {
    if (target != cur) {
        if ((target - cur < -180.0f && target - cur < 0.0f) || (target - cur < 180.0f && target - cur > 0.0f)) {
            cur += step;
            if ((target - cur > -180.0f && target - cur < 0.0f) || (target - cur > 180.0f && target - cur > 0.0f)) {
                cur = target;
            }
            if (cur > 360.0) {
                cur -= 360.0;
            }
        } else {
            cur -= step;
            if ((target - cur < -180.0f && target - cur < 0.0f) || (target - cur < 180.0f && target - cur > 0.0f)) {
                cur = target;
            }
            if (cur < 0.0) {
                cur += 360.0;
            }
        }
    }
    return cur;
}
void func_800FB778_MemoryMatch(omObjData* arg0) {
    Unk* temp_s0;

    temp_s0 = arg0->unk_50;
    arg0->work[1] = rand8() % 8;
    arg0->rot.x = arg0->rot.y = 0.0f;
    arg0->rot.z = (((rand8()) * 15) >> 8) + 15.0;
    
    if (temp_s0->unk5 & 1) {
        arg0->rot.z = -arg0->rot.z;
    }
    
    func_800257E4(arg0->model[0], arg0->rot.x, arg0->rot.y, arg0->rot.z);
    arg0->scale.z = 1.0f;
    arg0->scale.y = 1.0f;
    arg0->scale.x = (((f32) (rand8()) / 512.0) + 0.4);
    func_80025830(arg0->model[0], arg0->scale.x, arg0->scale.y, arg0->scale.z);
}

//give lights random X and Z starting positions
void func_800FB888_MemoryMatch(omObjData* arg0) {
    Unk* temp_v0;

    arg0->model[0] = func_800174C0(0x120007, 0xD9);
    func_80026040(arg0->model[0]);
    temp_v0 = func_80023684(0x2C, 0x7918);
    arg0->unk_50 = temp_v0;
    func_8009B770(temp_v0, 0, 0x2C);
    temp_v0->unk5 = D_800FE1DB_MemoryMatch;
    arg0->func_ptr = func_800FB9FC_MemoryMatch;
    arg0->trans.y = 600.0f;

    //-1000 to 992
    arg0->trans.x = (((rand8()) * 125) >> 4) - 1000;
    //-250 to 248
    arg0->trans.z = (((rand8()) * 125) >> 6) - 250;

    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_800FB778_MemoryMatch(arg0);
    func_80039C48("sin_dmy_DEF", D_800FE1E8_MemoryMatch[D_800FE1DA_MemoryMatch]);
    D_800FE200_MemoryMatch[D_800FE1DA_MemoryMatch] = D_800FE218_MemoryMatch[D_800FE1DA_MemoryMatch] = 0.0f;
    D_800FE1DA_MemoryMatch++;
}

//moves lights on the X axis
void func_800FB9FC_MemoryMatch(omObjData* arg0) {
    Unk* temp_s1;

    temp_s1 = arg0->unk_50;
    if (((func_8005FD5C()) + D_800F64F8) == 0) {
        if (temp_s1->unk5 & 1) {
            arg0->trans.x -= ((arg0->work[1] / 16.0f) + 0.2);
        } else {
            arg0->trans.x +=  ((arg0->work[1] / 16.0f) + 0.2);
        }
        
        if (arg0->trans.x < -1000.0f) {
            arg0->trans.x += 2000.0f;
            func_800FB778_MemoryMatch(arg0);
        }
        
        if (arg0->trans.x > 1000.0f) {
            arg0->trans.x -= 2000.0f;
            func_800FB778_MemoryMatch(arg0);
        }
        
        D_800FE200_MemoryMatch[temp_s1->unk5] = func_800AEAC0((arg0->work[0] * 1.40625)) * 4.0;
        D_800FE218_MemoryMatch[temp_s1->unk5] += 0.2f;
        arg0->work[0]++;
    }
    func_80027E48(arg0->model[0], D_800FE200_MemoryMatch[temp_s1->unk5], D_800FE218_MemoryMatch[temp_s1->unk5], D_800FE1E8_MemoryMatch[temp_s1->unk5][0], D_800FE1E8_MemoryMatch[temp_s1->unk5][1], "sin-light1", 1);
}

void func_800FBC34_MemoryMatch(omObjData* arg0) {
    arg0->model[0] = func_800174C0(0x120006, 0xD9);
    func_80025EB4(arg0->model[0], 2, 2);
    D_800F2B7C[arg0->model[0]].unk_48 = (rand8() * D_800ED554[D_800F2B7C[arg0->model[0]].unk_08].unk_02) >> 8;
    D_800F2B7C[arg0->model[0]].unk_4C = 1.5f;
    arg0->model[1] = func_800174F4(6, 0x699);
    arg0->func_ptr = func_800FBF24_MemoryMatch;
    D_800FE230_MemoryMatch[D_800FE1DE_MemoryMatch] = 0;
    D_800FE248_MemoryMatch[D_800FE1DE_MemoryMatch] = rand8() >> 4;
    arg0->work[0] = D_800FE1DF_MemoryMatch;
    arg0->work[1] = 0;
    arg0->trans.x = ((s32)((u32)(rand8() * 25) >> 6) - 50.0) * 5.0;
    arg0->trans.y = (D_800FE248_MemoryMatch[D_800FE1DE_MemoryMatch] + 15.0) * 5.0;
    arg0->trans.z = ((s32)((u32)(rand8() * 25) >> 6) - 50.0) * 5.0;
    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_80025798(arg0->model[1], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    arg0->rot.x = arg0->rot.y = arg0->rot.z = 0.0f;
    func_800257E4(arg0->model[0], arg0->rot.x, arg0->rot.y, arg0->rot.z);
    func_800257E4(arg0->model[1], arg0->rot.x, arg0->rot.y, arg0->rot.z);
    arg0->scale.x = arg0->scale.y = arg0->scale.z = 0.3f;
    func_80025830(arg0->model[0], arg0->scale.x, arg0->scale.y, arg0->scale.z);
    func_80025830(arg0->model[1], arg0->scale.x, arg0->scale.y, arg0->scale.z);
    D_800FE1DE_MemoryMatch++;
}
// index register copies and scheduling (masked 21)
#ifdef NON_MATCHING
void func_800FBF24_MemoryMatch(omObjData* arg0) {
    s32 i = arg0->work[0];
    omObjData* player = D_800F3FB0[0];
    f32 dx, dz, dist, s;

    switch (D_800FE230_MemoryMatch[i] & 0x7FFF) {
    case 0:
        if (rand8() == 0) {
            D_800FE230_MemoryMatch[i] = 1;
            if (arg0->trans.y < (D_800FE248_MemoryMatch[i] + 25.0) * 5.0) {
                D_800FE234_MemoryMatch[i] &= ~1;
            } else {
                D_800FE234_MemoryMatch[i] |= 1;
            }
        }
        break;
    case 1:
        if (!(D_800FE234_MemoryMatch[i] & 1)) {
            arg0->trans.y += 5.0;
            if ((D_800FE248_MemoryMatch[i] + 25.0) * 5.0 <= arg0->trans.y) {
                D_800FE230_MemoryMatch[i] = 0;
            }
        } else {
            arg0->trans.y -= 5.0;
            if (arg0->trans.y <= (D_800FE248_MemoryMatch[i] + 15.0) * 5.0) {
                D_800FE230_MemoryMatch[i] = 0;
            }
        }
        break;
    }
    arg0->rot.y = func_800FB588_MemoryMatch(arg0->rot.y,
        func_800B0CD8(D_800FE238_MemoryMatch[i][0] - arg0->trans.x, D_800FE238_MemoryMatch[i][1] - arg0->trans.z) + 180.0, 4.0f);
    arg0->trans.x -= func_800AEAC0(arg0->rot.y) * 4.0;
    arg0->trans.z -= func_800AEFD0(arg0->rot.y) * 4.0;
    dx = player->trans.x - arg0->trans.x;
    dz = player->trans.z - arg0->trans.z;
    dist = sqrtf(dx * dx + dz * dz);
    if (D_800FE2C0_MemoryMatch != 0) {
        func_800258EC(arg0->model[0], 4, 4);
        func_800258EC(arg0->model[1], 4, 4);
    }
    if ((s16)D_800FE234_MemoryMatch[i] < 0) {
        if (dist >= 256.0) {
            D_800FE238_MemoryMatch[i][0] = ((s32)((u32)(rand8() * 25) >> 6) - 50.0) * 5.0;
            D_800FE238_MemoryMatch[i][1] = ((s32)((u32)(rand8() * 25) >> 6) - 50.0) * 5.0;
            D_800FE234_MemoryMatch[i] &= 0x7FFF;
        } else if (arg0->work[1] == 0) {
            D_800FE238_MemoryMatch[i][0] = (f32)(rand8() >> 2) + player->trans.x - 32.0;
            D_800FE238_MemoryMatch[i][1] = (f32)(rand8() >> 2) + player->trans.z - 32.0;
            arg0->work[1] = rand8() | 0xC0;
        } else {
            arg0->work[1]--;
        }
    } else if (dist < 256.0) {
        D_800FE238_MemoryMatch[i][0] = (f32)(rand8() >> 2) + player->trans.x - 32.0;
        D_800FE238_MemoryMatch[i][1] = (f32)(rand8() >> 2) + player->trans.z - 32.0;
        D_800FE234_MemoryMatch[i] |= 0x8000;
    } else if (arg0->work[1] == 0) {
        D_800FE238_MemoryMatch[i][0] = ((s32)((u32)(rand8() * 25) >> 6) - 50.0) * 5.0;
        D_800FE238_MemoryMatch[i][1] = ((s32)((u32)(rand8() * 25) >> 6) - 50.0) * 5.0;
        arg0->work[1] = rand8() | 0xC0;
    } else {
        arg0->work[1]--;
    }
    func_80025798(arg0->model[1], arg0->trans.x, func_800F96A8_MemoryMatch(arg0->trans.x, arg0->trans.z), arg0->trans.z);
    s = 75.0 / arg0->trans.y * 0.0625 + 0.0625;
    func_80025830(arg0->model[1], s, 1.0f, s);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_00_MemoryMatch/D27D0", func_800FBF24_MemoryMatch);
#endif
void func_800FC5A4_MemoryMatch(omObjData* arg0) {
    unk_MemoryMatch_6C* w;
    s16 i;

    arg0->unk_50 = func_80023684(0x6C, 0x7918);
    func_8009B770(arg0->unk_50, 0, 0x6C);
    arg0->func_ptr = func_800FCD58_MemoryMatch;
    w = arg0->unk_50;
    func_800091BC(arg0, D_800FD8B0_MemoryMatch[D_800FE1E0_MemoryMatch], 0x68D, 8);
    func_8000941C(arg0, D_800FD8C0_MemoryMatch[D_800FE1E0_MemoryMatch], D_800FD8C0_MemoryMatch[D_800FE1E0_MemoryMatch], D_800FD8C0_MemoryMatch[D_800FE1E0_MemoryMatch]);
    arg0->model[3] = func_80023FC8(arg0->model[0]);
    func_80025830(arg0->model[3], D_800FD8C0_MemoryMatch[D_800FE1E0_MemoryMatch], D_800FD8C0_MemoryMatch[D_800FE1E0_MemoryMatch], D_800FD8C0_MemoryMatch[D_800FE1E0_MemoryMatch]);
    arg0->model[1] = func_800174F4(6, 0x29D);
    arg0->model[4] = func_80023FC8(arg0->model[1]);
    arg0->rot.x = -60.0f;
    arg0->rot.y = 180.0f;
    arg0->work[0] = 0xFF;
    arg0->work[3] = D_800FE1E1_MemoryMatch;
    arg0->model[2] = func_800174F4(0x120009, 0x29D);
    arg0->model[5] = func_800174F4(0x120009, 0x29D);
    func_80026040(arg0->model[2]);
    func_80026040(arg0->model[5]);
    func_80025798(arg0->model[2], 0.0f, 0.0f, 0.0f);
    func_80025798(arg0->model[5], 0.0f, 0.0f, 0.0f);
    func_80009340(arg0, 6, 0x2A, 0x68D, 8);
    func_8001E2F8(w->unk_27, 0xFF);
    func_8001E360(w->unk_27, 0xFF, 0xFF, 0xBE);
    arg0->work[2] = func_80064EF4(8, 0);
    for (i = 0; i < 8; i++) {
        func_80067480(arg0->work[2], i, -1);
        func_800674BC(arg0->work[2], i, 0x903C);
        func_80067208(arg0->work[2], i, D_800FE1E4_MemoryMatch, 0);
        func_800674F4(arg0->work[2], i, 0xFF, 0xFF, 0xBE);
        func_800672B0(arg0->work[2], i, 1);
        func_80067354(arg0->work[2], i, 1.6f, 1.6f);
        func_80067284(arg0->work[2], i, 0.0f);
        func_80067384(arg0->work[2], i, 0x9000);
    }
    D_800FE1E0_MemoryMatch++;
}
void func_800FC8A0_MemoryMatch(s16 arg0, Vec3f* arg1, Vec3f* arg2) {
    unk2C0C0StructE0* v;
    s16 i;
    s16 j;

    for (i = 0; i < D_800F37DA; i++) {
        v = D_800F2B7C[arg0].unk_6C->unk_08[i];
        for (j = 0; j < D_800F2B7C[arg0].unk_6C->unk_72; j++) {
            if (!(j & 2)) {
                v->unk_00 = arg1->x;
                v->unk_02 = arg1->y;
                v->unk_04 = arg1->z;
            } else {
                v->unk_00 = arg2->x;
                v->unk_02 = arg2->y;
                v->unk_04 = arg2->z;
            }
            v++;
        }
    }
}
// register allocation (masked 0, raw 119)
#ifdef NON_MATCHING
void func_800FC9E4_MemoryMatch(s16 arg0, Vec3f* arg1, Vec3f* arg2) {
    unk2C0C0StructE0* v;
    unk2C0C0StructE0* src;
    s16 prev;
    s16 j;

    v = D_800F2B7C[arg0].unk_6C->unk_08[D_800F37F0];
    prev = D_800F37F0 - 1;
    if (prev < 0) {
        prev = D_800F37DA - 1;
    }
    if (func_8005FD5C() + D_800F64F8 != 0) {
        src = D_800F2B7C[arg0].unk_6C->unk_08[prev];
        for (j = 0; j < D_800F2B7C[arg0].unk_6C->unk_72; j++) {
            v->unk_00 = src->unk_00;
            v->unk_02 = src->unk_02;
            v->unk_04 = src->unk_04;
            v++;
            src++;
        }
    } else {
        if (!(D_800FE1E2_MemoryMatch & 1)) {
            src = D_800F2B7C[arg0].unk_6C->unk_08[prev] + 4;
            for (j = 0; j < D_800F2B7C[arg0].unk_6C->unk_72 - 4; j++) {
                v->unk_00 = src->unk_00;
                v->unk_02 = src->unk_02;
                v->unk_04 = src->unk_04;
                v++;
                src++;
            }
            v->unk_00 = v[3].unk_00;
            v->unk_02 = v[3].unk_02;
            v->unk_04 = v[3].unk_04;
            v++;
            v->unk_00 = v[1].unk_00;
            v->unk_02 = v[1].unk_02;
            v->unk_04 = v[1].unk_04;
            v++;
        } else {
            src = D_800F2B7C[arg0].unk_6C->unk_08[prev];
            for (j = 0; j < D_800F2B7C[arg0].unk_6C->unk_72 - 2; j++) {
                v->unk_00 = src->unk_00;
                v->unk_02 = src->unk_02;
                v->unk_04 = src->unk_04;
                v++;
                src++;
            }
        }
        v->unk_00 = arg1->x;
        v->unk_02 = arg1->y;
        v->unk_04 = arg1->z;
        v++;
        v->unk_00 = arg2->x;
        v->unk_02 = arg2->y;
        v->unk_04 = arg2->z;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_00_MemoryMatch/D27D0", func_800FC9E4_MemoryMatch);
#endif
// switch compare tree, counter reload and loop index shape (masked 55)
#ifdef NON_MATCHING
void func_800FCD58_MemoryMatch(omObjData* arg0) {
    Vec3f a;
    Vec3f b;
    unk_MemoryMatch_6C* w;
    u8 idx;
    f32 h = 0.0f;
    f32 f;
    f32 x2;
    f32 z2;
    f32 s;
    s16 n;
    s16 j;

    w = arg0->unk_50;
    idx = arg0->work[3];
    f = 0.0f;
    if (arg0->work[0] == 0xFF) {
        return;
    }
    if (!(arg0->work[0] & 0x80)) {
        arg0->work[0] = (arg0->work[0] + 1) | 0x80;
        arg0->work[1] = 16;
        w->unk_38 = 4.0f;
        D_800F2B7C[arg0->model[0]].unk_20 &= ~4;
        D_800F2B7C[arg0->model[3]].unk_20 &= ~4;
        D_800F2B7C[arg0->model[1]].unk_20 &= ~4;
        D_800F2B7C[arg0->model[4]].unk_20 &= ~4;
        D_800F2B7C[arg0->model[2]].unk_20 &= ~4;
        D_800F2B7C[arg0->model[5]].unk_20 &= ~4;
        D_800ECDE0[w->unk_27].unk_04 = 0;
    }
    switch (arg0->work[0] & 0x7F) {
    case 1:
        f = (16.0 - (f32)arg0->work[1]) / 32.0;
        arg0->trans.x = f * (D_800FE270_MemoryMatch[idx][0] - D_800FE250_MemoryMatch[idx][0]) + D_800FE250_MemoryMatch[idx][0];
        arg0->trans.z = f * (D_800FE270_MemoryMatch[idx][1] - D_800FE250_MemoryMatch[idx][1]) + D_800FE250_MemoryMatch[idx][1];
        h = func_800AEAC0(f * 180.0) * 120.0;
        arg0->trans.y = h;
        break;
    case 2:
        if (func_8005FD5C() + D_800F64F8 == 0) {
            w->unk_38 += 0.25;
            arg0->trans.y += w->unk_38;
        }
        h = 120.0f;
        f = 0.5f;
        break;
    case 3:
        break;
    }
    a.x = arg0->trans.x + D_800FE290_MemoryMatch[idx][0];
    a.z = arg0->trans.z + D_800FE290_MemoryMatch[idx][1];
    a.y = h;
    b.x = arg0->trans.x - D_800FE290_MemoryMatch[idx][0];
    b.z = arg0->trans.z - D_800FE290_MemoryMatch[idx][1];
    b.y = h;
    if (f == 0.0) {
        func_800FC8A0_MemoryMatch(arg0->model[2], &a, &b);
    }
    func_800FC9E4_MemoryMatch(arg0->model[2], &a, &b);
    x2 = f * (D_800FE250_MemoryMatch[idx][0] - D_800FE270_MemoryMatch[idx][0]) + D_800FE270_MemoryMatch[idx][0];
    z2 = f * (D_800FE250_MemoryMatch[idx][1] - D_800FE270_MemoryMatch[idx][1]) + D_800FE270_MemoryMatch[idx][1];
    func_80025798(arg0->model[3], x2, h, z2);
    a.x = x2 + D_800FE290_MemoryMatch[idx][0];
    a.z = z2 + D_800FE290_MemoryMatch[idx][1];
    a.y = h;
    b.x = x2 - D_800FE290_MemoryMatch[idx][0];
    b.z = z2 - D_800FE290_MemoryMatch[idx][1];
    b.y = h;
    if (f == 0.0) {
        func_800FC8A0_MemoryMatch(arg0->model[5], &a, &b);
    }
    func_800FC9E4_MemoryMatch(arg0->model[5], &a, &b);
    if (arg0->work[1] == 0) {
        switch (arg0->work[0] & 0x7F) {
        case 1:
            arg0->work[0]++;
            arg0->work[1] = 16;
            D_800F2B7C[arg0->model[3]].unk_20 |= 4;
            break;
        case 2:
            arg0->work[0]++;
            arg0->work[1] = 16;
            D_800F2B7C[arg0->model[0]].unk_20 |= 4;
            D_800F2B7C[arg0->model[1]].unk_20 |= 4;
            D_800F2B7C[arg0->model[4]].unk_20 |= 4;
            D_800F2B7C[arg0->model[6]].unk_20 &= ~4;
            func_80025798(arg0->model[6], arg0->trans.x, arg0->trans.y, arg0->trans.z);
            func_80025830(arg0->model[6], 12.0f, 12.0f, 12.0f);
            if (arg0->work[3] == 0) {
                PlaySound(0xFC);
            } else {
                PlaySound(0xFD);
            }
            break;
        case 3:
            arg0->work[0] = 0xFF;
            D_800F2B7C[arg0->model[2]].unk_20 |= 4;
            D_800F2B7C[arg0->model[5]].unk_20 |= 4;
            w->unk_54 = 0;
            break;
        }
    } else if (func_8005FD5C() + D_800F64F8 == 0) {
        arg0->work[1]--;
    }
    if (func_8005FD5C() + D_800F64F8 == 0) {
        if (!(++D_800FE2B0_MemoryMatch[idx] & 3)) {
            n = (D_800FE2B0_MemoryMatch[idx] >> 2) & 3;
            if ((arg0->work[0] & 0x7F) == 1) {
                for (j = 0; j < 2; j++) {
                    if (j == 0) {
                        func_80066DF4(arg0->work[2], n, 0, arg0->trans.x, arg0->trans.y, arg0->trans.z);
                    } else {
                        func_80066DF4(arg0->work[2], n + j * 4, 0, x2, h, z2);
                    }
                    func_80067480(arg0->work[2], n + j * 4, 0x8000);
                    func_80067284(arg0->work[2], n + j * 4, 1.0f);
                    D_800EE330[arg0->work[2]]->obj[n + j * 4]->unk58 = 0.0f;
                    D_800EE330[arg0->work[2]]->obj[n + j * 4]->unk50 = 0;
                    D_800EE330[arg0->work[2]]->obj[n + j * 4]->unkA = 1;
                }
            } else {
                func_800674BC(arg0->work[2], n, 0x8000);
                func_800674BC(arg0->work[2], n + 4, 0x8000);
            }
        }
    }
    func_80025798(arg0->model[1], arg0->trans.x, func_800F96A8_MemoryMatch(arg0->trans.x, arg0->trans.z), arg0->trans.z);
    func_80025798(arg0->model[4], x2, func_800F96A8_MemoryMatch(x2, z2), z2);
    if (arg0->trans.y > 0.0) {
        s = 75.0 / arg0->trans.y * 0.03125 + 0.125;
    } else {
        s = 0.0f;
    }
    func_80025830(arg0->model[1], s, 1.0f, s);
    func_80025830(arg0->model[4], s, 1.0f, s);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_00_MemoryMatch/D27D0", func_800FCD58_MemoryMatch);
#endif
// retail stores D_800FE250/54/70/74 as separate symbols (masked 11)
#ifdef NON_MATCHING
void func_800FD6A0_MemoryMatch(omObjData* arg0, omObjData* arg1) {
    f32 dx, dz, d;
    s16 i = 0;

    D_800FE250_MemoryMatch[0][0] = arg0->trans.x;
    D_800FE250_MemoryMatch[0][1] = arg0->trans.z;
    D_800FE270_MemoryMatch[0][0] = arg1->trans.x;
    D_800FE270_MemoryMatch[0][1] = arg1->trans.z;
    dx = arg1->trans.x - arg0->trans.x;
    dz = arg1->trans.z - arg0->trans.z;
    d = sqrtf(dx * dx + dz * dz);
    if (d != 0.0) {
        dx /= d;
        dz /= d;
    }
    dx *= 60.0;
    dz *= 60.0;
    D_800FE290_MemoryMatch[i][0] = -dz;
    D_800FE290_MemoryMatch[i][1] = dx;
    D_800FE2B0_MemoryMatch[i] = 0;
    D_800EDE70[i]->work[0] = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_00_MemoryMatch/D27D0", func_800FD6A0_MemoryMatch);
#endif
