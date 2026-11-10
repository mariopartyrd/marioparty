#include "common.h"
#include "113DC0.h"

/* .data (0x800F9900..0x800F9A00) */
s8 D_800F9900_PipeMaze = 0;
s16 D_800F9902_PipeMaze = 0;
s32 D_800F9904_PipeMaze = 0;
s32 D_800F9908_PipeMaze = 0;
s32 D_800F990C_PipeMaze = 0;
s32 D_800F9910_PipeMaze = 0;
u8 D_800F9914_PipeMaze = 0;
s8 D_800F9915_PipeMaze = 0;
s32 D_800F9918_PipeMaze = -1;
f32 D_800F991C_PipeMaze = 0.0f;
f32 D_800F9920_PipeMaze = 0.0f;
f32 D_800F9924_PipeMaze = -970.0f;
/* the rung patterns of one maze column (func_800F6744) */
u8 D_800F9928_PipeMaze[10][8] = {
    { 1, 1, 1, 1, 0, 0, 0, 0 }, { 0, 1, 1, 1, 0, 1, 0, 0 }, { 0, 0, 1, 1, 1, 1, 0, 0 },
    { 1, 0, 1, 0, 1, 0, 1, 0 }, { 1, 1, 0, 0, 1, 0, 1, 0 }, { 0, 1, 1, 1, 0, 1, 0, 0 },
    { 1, 0, 1, 1, 0, 0, 1, 0 }, { 1, 1, 1, 0, 0, 0, 1, 0 }, { 0, 0, 0, 1, 1, 1, 1, 0 },
    { 1, 0, 1, 0, 0, 1, 1, 0 },
};
s8 D_800F9978_PipeMaze = 0;
s8 D_800F9979_PipeMaze = 0;
s8 D_800F997A_PipeMaze = 0;
u8 D_800F997B_PipeMaze = 0;
u8 D_800F997C_PipeMaze = 0;
f32 D_800F9980_PipeMaze = 90.0f;
s32 D_800F9984_PipeMaze = 0;
s32 D_800F9988_PipeMaze[4] = { 0, 1, 2, 3 };
f32 D_800F9998_PipeMaze[4][3] = {
    { -900.0f, -200.0f, -800.0f }, { -300.0f, -200.0f, -800.0f },
    { 300.0f, -200.0f, -800.0f }, { 900.0f, -200.0f, -800.0f },
};
f32 D_800F99C8_PipeMaze = 0.0f;
f32 D_800F99CC_PipeMaze = 8.0f;
f32 D_800F99D0_PipeMaze = 0.0f;
s8 D_800F99D4_PipeMaze = 0;
u8 D_800F99D5_PipeMaze = 0;
s8 D_800F99D6_PipeMaze = 0;
u32 D_800F99D8_PipeMaze = 0;
u32 D_800F99DC_PipeMaze = 0;
s32 D_800F99E0_PipeMaze = 0;
s32 D_800F99E4_PipeMaze = 0x40000000;
s32 D_800F99E8_PipeMaze = 0;
u32 D_800F99EC_PipeMaze = 0;
u8 D_800F99F0_PipeMaze = 0;

void func_800F65E0_PipeMaze(void) {
    func_80029090(32);
    func_8001DE70(32);
    omInitObjMan(50, 0);
    func_80060088();
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 160);
    D_800F9A34_PipeMaze = 0;
    func_800F6678_PipeMaze();
    D_800F9902_PipeMaze = 0;
    func_800F7EA4_PipeMaze();
    func_800F7100_PipeMaze();
    func_800F68BC_PipeMaze();
    SetFadeInTypeAndTime(0, 16);
}

void func_800F6678_PipeMaze(void) {
    s16 temp_s0;
    
    func_800178A0(1);
    temp_s0 = func_800178E8();
    func_80017660(temp_s0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(temp_s0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(temp_s0, 36.0f, 80.0f, 8000.0f);
}

void func_800F673C_PipeMaze(void) {
}

// register allocation (masked 0)
#ifdef NON_MATCHING
void func_800F6744_PipeMaze(void) {
    s32 i;
    s32 r;

    r = (rand8() * 5U) >> 7;
    for (i = 0; i < 8; i++) {
        D_800F9AB8_PipeMaze[i * 2 + 1][1] = ((u8*)D_800F9928_PipeMaze)[r * 8 + i];
    }
    r = (rand8() * 5U) >> 7;
    for (i = 0; i < 8; i++) {
        D_800F9AB8_PipeMaze[i * 2 + 2][3] = ((u8*)D_800F9928_PipeMaze)[r * 8 + i];
    }
    r = (rand8() * 5U) >> 7;
    for (i = 0; i < 8; i++) {
        D_800F9AB8_PipeMaze[i * 2 + 1][5] = ((u8*)D_800F9928_PipeMaze)[r * 8 + i];
    }
    for (i = 0; i < 16; i++) {
        D_800F9AB8_PipeMaze[i][0] = D_800F9AB8_PipeMaze[i][2] = D_800F9AB8_PipeMaze[i][4] = D_800F9AB8_PipeMaze[i][6] = 2;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_09_PipeMaze/113DC0", func_800F6744_PipeMaze);
#endif
void func_800F68BC_PipeMaze(void) {
    s32 i;
    s32 j;
    s32 n;

    D_800ED440 = 0;
    D_800F2AF8[D_800ED440++] = omAddObj(3, 1, 0, -1, func_800F6A38_PipeMaze);
    for (i = 0; i < 4; i++) {
        omAddObj(3, 1, 0, -1, func_800F6B04_PipeMaze);
    }
    func_800F6744_PipeMaze();
    for (i = 0, n = 0; i < 16; i++) {
        for (j = 0; j < 7; j++) {
            if (D_800F9AB8_PipeMaze[i][j] == 1) {
                omAddObj(3, 1, 0, -1, func_800F6C34_PipeMaze);
                D_800F9A38_PipeMaze[n] = j;
                D_800F9A78_PipeMaze[n] = i;
                n++;
            }
        }
    }
}
void func_800F6A38_PipeMaze(omObjData* arg0) {
    arg0->func_ptr = &func_800F9134_PipeMaze;
    arg0->trans.x = arg0->trans.y = arg0->trans.z = 0;
    arg0->model[0] = func_800174C0(0x1B0000, 0x299);
    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    Center.x = 0.0f;
    Center.y = 200.0f;
    Center.z = -200.0f;
    CRot.x = 0.0f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    CZoom = 2500.0f;
    func_800F673C_PipeMaze();
}

void func_800F6B04_PipeMaze(omObjData* arg0) {
    f32 xs[4] = { -900.0f, -300.0f, 300.0f, 900.0f };

    D_800F9B40_PipeMaze[D_800F9904_PipeMaze] = arg0->model[0] = func_800174C0(0x1B0003, 0x289);
    arg0->func_ptr = NULL;
    arg0->trans.x = xs[D_800F9904_PipeMaze];
    arg0->trans.y = 3400.0f;
    arg0->trans.z = -970.0f;
    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_80026040(D_800F9B40_PipeMaze[D_800F9904_PipeMaze]);
    func_80025B34(D_800F9B40_PipeMaze[D_800F9904_PipeMaze]);
    D_800F9904_PipeMaze++;
}
void func_800F6C34_PipeMaze(omObjData* arg0) {
    u16 temp_v0;
    f32 temp_f0 = 0;
    f32 temp_f2 = 800.0f;

    switch (D_800F9A38_PipeMaze[D_800F9910_PipeMaze]) {
    case 1:
        arg0->trans.x = temp_f0 - 600.0f;
        break;
    case 3:
        arg0->trans.x = temp_f0;
        break;
    case 5:
        arg0->trans.x = temp_f0 + 600.0f;
        break;
    default:
        return;
    }
    
    arg0->trans.y = temp_f2 + ((14 - D_800F9A78_PipeMaze[D_800F9910_PipeMaze]) * 400.0f);
    D_800F9910_PipeMaze++;
    arg0->trans.z = -960.0f;
    arg0->func_ptr = NULL;
    temp_v0 = func_800174C0(0x1B0001, 0x289);
    D_800F9B48_PipeMaze[D_800F9908_PipeMaze] = arg0->model[0] = temp_v0;
    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_80026040(D_800F9B48_PipeMaze[D_800F9908_PipeMaze]);
    func_80025B34(D_800F9B48_PipeMaze[D_800F9908_PipeMaze]);
    D_800F9908_PipeMaze++;
}

void func_800F6DD8_PipeMaze(s16 arg0, s16 arg1) {
    unk2C0C0StructC0* c;
    unk2C0C0Struct30* b;
    unk2C0C0StructE0* src;
    unk2C0C0StructE0* dst;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 ex;
    f32 ey;
    f32 ez;
    f32 d;
    s16 i;

    c = D_800F2B7C[arg0].unk_6C;
    dx = D_800F991C_PipeMaze - D_800F2B7C[arg0].unk_24;
    dy = D_800F9920_PipeMaze - D_800F2B7C[arg0].unk_28;
    dz = D_800F9924_PipeMaze - D_800F2B7C[arg0].unk_2C;
    b = c->unk_80;
    if (dx < b->unk_4A || b->unk_50 < dx || dy < b->unk_4C || b->unk_52 < dy) {
        arg1 = -1;
    }
    src = c->unk_04;
    dst = c->unk_08[D_800F37F0];
    if (arg1 == -1) {
        for (i = 0; i < c->unk_72; i++) {
            dst->unk_00 = src->unk_00;
            dst->unk_02 = src->unk_02;
            src++;
            dst++;
        }
    } else {
        for (i = 0; i < c->unk_72; i++) {
            ex = dx - src->unk_00;
            ey = dy - src->unk_02;
            ez = dz - src->unk_04;
            d = func_800B1750(ex * ex + ey * ey + ez * ez);
            if (d < 256.0f) {
                if (arg1 == 0) {
                    d = (256.0f - d) * -func_800AEFD0(func_800B0CD8(256.0f, ex));
                    dst->unk_00 = src->unk_00 + d;
                } else {
                    d = (256.0f - d) * -func_800AEFD0(func_800B0CD8(256.0f, ey));
                    dst->unk_02 = src->unk_02 + d;
                }
            } else {
                dst->unk_00 = src->unk_00;
                dst->unk_02 = src->unk_02;
            }
            src++;
            dst++;
        }
    }
}
void func_800F7100_PipeMaze(void) {
    omObjData* temp_v0;

    D_800EE984 = 0;
    D_800F9B80_PipeMaze = (omObjData*)func_8006B8A4(1, 0x289, 0x289, 0x289, 1);
    func_8006B870();
    temp_v0 = omAddObj(1, 8, 0, -1, &func_800F7194_PipeMaze);
    D_800EDE70[D_800EE984++] = temp_v0;
    omSetStatBit(temp_v0, 0xA0);
}

void func_800F7194_PipeMaze(omObjData* arg0) {
    s32 i;
    s32 alpha;
    s32 file;

    file = 0x289;
    D_800F9B80_PipeMaze->trans.x = arg0->trans.x = D_800F991C_PipeMaze = -900.0f;
    D_800F9B80_PipeMaze->trans.y = arg0->trans.y = D_800F9920_PipeMaze = 7200.0f;
    D_800F9B80_PipeMaze->trans.z = arg0->trans.z = -965.0f;
    func_8006B9B0(D_800F9B80_PipeMaze, D_800F9B80_PipeMaze->trans.x, D_800F9B80_PipeMaze->trans.y, -965.0f);
    func_8006B9D0(D_800F9B80_PipeMaze, 2.0f, 2.0f, 2.0f);
    arg0->func_ptr = func_800F7368_PipeMaze;
    for (i = 0, alpha = 0x40; i < 8; i++, alpha += 0x28) {
        if (i == 0) {
            arg0->model[0] = LoadFormFile(0x35, (u16)file);
        } else {
            arg0->model[i] = func_80023FC8(arg0->model[0]);
        }
        func_80021240(arg0->model[i]);
        func_800211BC(arg0->model[i], alpha);
        func_800258EC(arg0->model[i], 4, 4);
        func_80025EB4(arg0->model[i], 1, 1);
        func_80025830(arg0->model[i], 2.0f, 2.0f, 2.0f);
    }
    D_800F9B74_PipeMaze = omAddObj(5, 0, 0, -1, func_800F9590_PipeMaze);
}
// stk==0 test: retail re-tests stk<0 / stk<=0 after D_800F997A=1, GCC threads it to one jump (1 insn short; logic-equivalent)
#ifdef NON_MATCHING
void func_800F7368_PipeMaze(omObjData* arg0) {
    s16 stk;
    s32 time;
    s32 mask;
    f32 x;

    stk = 0;
    D_800F9B80_PipeMaze->trans.x = arg0->trans.x;
    D_800F9B80_PipeMaze->trans.y = arg0->trans.y;
    D_800F9B80_PipeMaze->trans.y = arg0->trans.y;
    mask = 0;
    if (!(GwPlayer[D_800F9B3C_PipeMaze].flags & 1)) {
        stk = ContStkX[GwPlayer[D_800F9B3C_PipeMaze].port];
    }
    switch (D_800F990C_PipeMaze) {
    case 1:
        if (!(D_800F997C_PipeMaze & 1)) {
            GMesCreate(0);
            D_800F997C_PipeMaze |= 1;
        }
        if ((D_800F997C_PipeMaze & 1) && (GMesStatAllGet() == 0 || (GMesStatAllGet() & 2))) {
            if (!(D_800F997C_PipeMaze & 2)) {
                GMesCreate(8, 30, 160, 32);
                D_800F997C_PipeMaze |= 2;
            }
        }
        if (!(D_800F997C_PipeMaze & 2)) {
            break;
        }
        time = 900 - D_800F9A30_PipeMaze;
        func_80079078(time / 30);
        if (func_8005FD5C() + D_800F64F8 == 0) {
            D_800F9A30_PipeMaze++;
        }
        if (func_8005FD5C() + D_800F64F8 != 0) {
            break;
        }
        switch (GwPlayer[D_800F9B3C_PipeMaze].flags & 1) {
        case 0:
            if (stk >= 0) {
                if (stk <= 0) {
                    D_800F997A_PipeMaze = 1;
                }
            }
            if (stk > 0 && D_800F997A_PipeMaze != 0 && D_800F9979_PipeMaze == 0 && D_800F9978_PipeMaze == 0 &&
                (x = arg0->trans.x) >= -900.0f && x < 900.0f) {
                D_800F9B78_PipeMaze = x;
                D_800F9978_PipeMaze = 1;
                D_800F991C_PipeMaze += 600.0f;
                D_800F997A_PipeMaze = 0;
                PlaySound(0x21B);
            } else if (stk < 0 && D_800F997A_PipeMaze != 0 && D_800F9978_PipeMaze == 0 && D_800F9979_PipeMaze == 0 &&
                       (x = arg0->trans.x) > -900.0f && x <= 900.0f) {
                D_800F9B78_PipeMaze = x;
                D_800F9979_PipeMaze = 1;
                D_800F991C_PipeMaze -= 600.0f;
                D_800F997A_PipeMaze = 0;
                PlaySound(0x21B);
            }
            if (D_800F9978_PipeMaze == 1) {
                func_800F7AC8_PipeMaze(arg0, 0);
            }
            if (D_800F9979_PipeMaze == 1) {
                func_800F7AC8_PipeMaze(arg0, 1);
            }
            if ((D_800F997C_PipeMaze & 2) && D_800F9979_PipeMaze == 0 && D_800F9978_PipeMaze == 0) {
                stk = ContBtn[GwPlayer[D_800F9B3C_PipeMaze].port] & ~mask;
                if (func_8005FD5C() + D_800F64F8 == 0) {
                    if (time <= 0 || ((stk & 0x8000) && Center.y >= 6800.0f)) {
                        D_800F990C_PipeMaze = 2;
                    }
                }
            }
            break;
        case 1:
            D_800F997B_PipeMaze++;
            if (D_800F997B_PipeMaze >= 15) {
                D_800F997B_PipeMaze = 0;
                if (D_800F9915_PipeMaze == 0) {
                    func_800F7C78_PipeMaze();
                }
                if (D_800F9914_PipeMaze == 0) {
                    D_800F990C_PipeMaze = 2;
                } else if (D_800F9978_PipeMaze == 0) {
                    D_800F9B78_PipeMaze = arg0->trans.x;
                    D_800F9978_PipeMaze = 1;
                    D_800F991C_PipeMaze += 600.0f;
                    D_800F9914_PipeMaze--;
                    D_800F9915_PipeMaze = 1;
                    PlaySound(0x21B);
                }
            }
            if (D_800F9978_PipeMaze == 1) {
                func_800F7AC8_PipeMaze(arg0, 0);
            }
            break;
        }
        break;
    case 2:
        if (!(D_800F997C_PipeMaze & 4)) {
            func_800790C0();
            D_800F997C_PipeMaze |= 4;
        }
        func_800F8414_PipeMaze(arg0);
        if (arg0->trans.y > 2570.0f || (arg0->trans.y > 200.0f && arg0->trans.y < 340.0f)) {
            func_80025830(func_800F97C4_PipeMaze(0, arg0->trans.x, arg0->trans.y, arg0->trans.z, 1), arg0->scale.x,
                          arg0->scale.y, arg0->scale.z);
        }
        if (Center.y > 200.0f && arg0->trans.y <= Center.y) {
            Center.y = arg0->trans.y;
        } else if (Center.y <= 200.0f) {
            if (arg0->scale.x == 0.0f) {
                D_800F990C_PipeMaze = 3;
            }
            Center.y = 200.0f;
        }
        break;
    }
    D_800F9B80_PipeMaze->trans.x = arg0->trans.x;
    D_800F9B80_PipeMaze->trans.y = arg0->trans.y;
    D_800F9B80_PipeMaze->trans.y = arg0->trans.y;
    func_8006B9B0(D_800F9B80_PipeMaze, D_800F9B80_PipeMaze->trans.x, D_800F9B80_PipeMaze->trans.y,
                  D_800F9B80_PipeMaze->trans.z);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_09_PipeMaze/113DC0", func_800F7368_PipeMaze);
#endif
void func_800F7AC8_PipeMaze(omObjData* arg0, s32 arg1) {
    func_800F97C4_PipeMaze(0, arg0->trans.x, arg0->trans.y, arg0->trans.z, 1);
    if (arg1 == 0) {
        arg0->trans.x += D_800F9980_PipeMaze;
    } else if (arg1 == 1) {
        arg0->trans.x -= D_800F9980_PipeMaze;
    }
    if (D_800F9980_PipeMaze > 1.0f) {
        D_800F9980_PipeMaze -= 1.0f;
    }
    if (arg1 == 0 && arg0->trans.x - D_800F9B78_PipeMaze >= 600.0f) {
        D_800F9978_PipeMaze = 0;
        arg0->trans.x = D_800F9B78_PipeMaze + 600.0f;
        D_800F9980_PipeMaze = 90.0f;
    } else if (arg1 == 1 && arg0->trans.x - D_800F9B78_PipeMaze <= -600.0f) {
        D_800F9979_PipeMaze = 0;
        arg0->trans.x = D_800F9B78_PipeMaze - 600.0f;
        D_800F9980_PipeMaze = 90.0f;
    }
    if (arg1 == 0 && arg0->trans.x < -900.0f) {
        arg0->trans.x = -900.0f;
    } else if (arg1 == 1 && arg0->trans.x > 900.0f) {
        arg0->trans.x = 900.0f;
    }
}
void func_800F7C78_PipeMaze(void) {
    switch (D_800F9984_PipeMaze) {
    case 1:
        func_800F7E2C_PipeMaze();
        return;
    case 2:
        func_800F7CD8_PipeMaze();
        return;
    default:
        func_800F7E78_PipeMaze();
        return;
    }
}

void func_800F7CD8_PipeMaze(void) {
    s32 col;
    s32 row;
    u8 (*g)[7];

    col = 0;
    if (D_800F9B34_PipeMaze == -900.0f) {
        col = 0;
    } else if (D_800F9B34_PipeMaze == -300.0f) {
        col = 2;
    } else if (D_800F9B34_PipeMaze == 300.0f) {
        col = 4;
    } else if (D_800F9B34_PipeMaze == 900.0f) {
        col = 6;
    }
    row = 15;
    g = D_800F9AB8_PipeMaze - 1;
    for (; row > 0; row--) {
        if (col == 0) {
            if (g[row][1] == 1) {
                col = 2;
            }
        } else if (col == 6) {
            if (g[row][5] == 1) {
                col = 4;
            }
        } else if ((g[row] + col)[1] == 1) {
            col += 2;
        } else if ((g[row] + col)[-1] == 1) {
            col -= 2;
        }
    }
    D_800F9914_PipeMaze = col / 2;
}
void func_800F7E2C_PipeMaze(void) {
    func_800F7CD8_PipeMaze();
    D_800F9914_PipeMaze++;
    if (D_800F9914_PipeMaze >= 4) {
        D_800F9914_PipeMaze = 0;
    }
}

void func_800F7E78_PipeMaze(void) {
    D_800F9914_PipeMaze = rand8() >> 6;
}

void func_800F7EA4_PipeMaze(void) {
    s32 i;

    D_800F2BC0 = 0;
    for (i = 0; i < 4; i++) {
        if (GwPlayer[i].group == 0) {
            D_800F9B3C_PipeMaze = i;
        }
        if (GwPlayer[D_800F9B3C_PipeMaze].flags & 1) {
            if (GwPlayer[D_800F9B3C_PipeMaze].cpu_difficulty == 0) {
                if ((rand8() >> 6) == 0) {
                    D_800F9984_PipeMaze = 2;
                } else {
                    D_800F9984_PipeMaze = 1;
                }
            } else if (GwPlayer[D_800F9B3C_PipeMaze].cpu_difficulty == 1) {
                if ((rand8() >> 7) == 0) {
                    D_800F9984_PipeMaze = 2;
                } else {
                    D_800F9984_PipeMaze = 1;
                }
            } else if (GwPlayer[D_800F9B3C_PipeMaze].cpu_difficulty == 2) {
                if ((s32)((u32)(rand8() * 5) >> 7) < 8) {
                    D_800F9984_PipeMaze = 2;
                } else {
                    D_800F9984_PipeMaze = 1;
                }
            } else if (GwPlayer[D_800F9B3C_PipeMaze].cpu_difficulty == 3) {
                if (((rand8() * 255) >> 8) < 254) {
                    D_800F9984_PipeMaze = 2;
                } else {
                    D_800F9984_PipeMaze = 1;
                }
            }
        }
        D_800F3FB0[D_800F2BC0++] = omAddObj(2, 1, 5, -1, func_800F80CC_PipeMaze);
    }
}
void func_800F80CC_PipeMaze(omObjData* arg0) {
    unkGlobalStruct_00* w;
    s32 dir;
    s8 chr;
    s16 mot;
    u32 len;

    arg0->unk_50 = func_80023684(sizeof(unkGlobalStruct_00), 0x7918);
    func_8009B770(arg0->unk_50, 0, sizeof(unkGlobalStruct_00));
    w = arg0->unk_50;
    w->unk_D8 = func_80023684(arg0->mtncnt * sizeof(unkGlobalStruct_00), 0x7918);
    func_8009B770(w->unk_D8, 0, arg0->mtncnt * sizeof(unkGlobalStruct_00));
    w->unk_58 = (u8)D_800F9902_PipeMaze;
    D_800F9B38_PipeMaze = w->unk_56 = GwPlayer[D_800F9988_PipeMaze[D_800F9902_PipeMaze]].port;
    chr = GwPlayer[D_800F9988_PipeMaze[D_800F9902_PipeMaze]].character;
    dir = D_800C59AC[chr].unk_00;
    arg0->model[0] = LoadFormFile(dir | D_800C59AC[chr].unk_04, 0x2D9);
    arg0->scale.x = arg0->scale.y = arg0->scale.z = 1.8f;
    arg0->rot.y = 0.0f;
    arg0->rot.x = arg0->rot.z = arg0->rot.y;
    arg0->func_ptr = NULL;
    arg0->trans.x = D_800F9998_PipeMaze[D_800F9902_PipeMaze][0];
    arg0->trans.y = D_800F9998_PipeMaze[D_800F9902_PipeMaze][1];
    arg0->trans.z = D_800F9998_PipeMaze[D_800F9902_PipeMaze][2];
    if (GwPlayer[D_800F9902_PipeMaze].group == 0) {
        D_800F9B34_PipeMaze = arg0->trans.x;
    }
    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_80025830(arg0->model[0], arg0->scale.x, arg0->scale.y, arg0->scale.z);
    func_800257E4(arg0->model[0], arg0->rot.x, arg0->rot.y, arg0->rot.z);
    w->unk_C0 = 0xFFFF;
    func_8001874C(arg0, 0, dir, 1, 0);
    func_8001874C(arg0, 13, dir | 0x38, 1, 120);
    func_8001874C(arg0, 14, dir | 0x3C, 1, 120);
    mot = func_80025E48(arg0->motion[0] & 0x3FFF);
    len = func_80025D40(arg0->motion[0] & 0x3FFF) / 5.0f;
    func_80025C20(arg0->model[0], mot, 0, len, 2);
    func_800184BC(arg0, 0);
    func_80017DB0(arg0);
    D_800F9902_PipeMaze++;
}
// scheduling: D_800F2B7C load hoisted above the model*0xC0 multiply (masked 4)
#ifdef NON_MATCHING
void func_800F8414_PipeMaze(omObjData* arg0) {
    s32 n;
    s32 i;
    s32 j;

    if (arg0->trans.y >= 6100.0f) {
        D_800F9B28_PipeMaze = 0;
    } else if (arg0->trans.y >= 5700.0f) {
        D_800F9B28_PipeMaze = 1;
    } else if (arg0->trans.y >= 5300.0f) {
        D_800F9B28_PipeMaze = 2;
    } else if (arg0->trans.y >= 4900.0f) {
        D_800F9B28_PipeMaze = 3;
    } else if (arg0->trans.y >= 4500.0f) {
        D_800F9B28_PipeMaze = 4;
    } else if (arg0->trans.y >= 4100.0f) {
        D_800F9B28_PipeMaze = 5;
    } else if (arg0->trans.y >= 3700.0f) {
        D_800F9B28_PipeMaze = 6;
    } else if (arg0->trans.y >= 3300.0f) {
        D_800F9B28_PipeMaze = 7;
    } else if (arg0->trans.y >= 2900.0f) {
        D_800F9B28_PipeMaze = 8;
    } else if (arg0->trans.y >= 2500.0f) {
        D_800F9B28_PipeMaze = 9;
    } else if (arg0->trans.y >= 2100.0f) {
        D_800F9B28_PipeMaze = 10;
    } else if (arg0->trans.y >= 1700.0f) {
        D_800F9B28_PipeMaze = 11;
    } else if (arg0->trans.y >= 1300.0f) {
        D_800F9B28_PipeMaze = 12;
    } else if (arg0->trans.y >= 900.0f) {
        D_800F9B28_PipeMaze = 13;
    } else if (arg0->trans.y >= 500.0f) {
        D_800F9B28_PipeMaze = 14;
    } else {
        D_800F9B28_PipeMaze = -1;
    }
    D_800F9B2C_PipeMaze = (arg0->trans.x + 1050.0f) / 300.0f;
    D_800F9AB8_PipeMaze[D_800F9B28_PipeMaze][D_800F9B2C_PipeMaze] = 4;
    D_800F99CC_PipeMaze = 2.0f;
    if (D_800F9B28_PipeMaze == 0) {
        D_800F99CC_PipeMaze = 1.925f;
        arg0->scale.x = arg0->scale.y = arg0->scale.z = (&D_800F99C8_PipeMaze)[1];
        func_80025830(arg0->model[0], arg0->scale.x, arg0->scale.y, arg0->scale.z);
    } else if (D_800F9B28_PipeMaze == -1 && D_800F99CC_PipeMaze < 2.0f && arg0->trans.y > -50.0f) {
        arg0->scale.x = arg0->scale.y = arg0->scale.z = D_800F99CC_PipeMaze += 0.1f;
        func_80025830(arg0->model[0], arg0->scale.x, arg0->scale.y, arg0->scale.z);
    }
    if (D_800F9AB8_PipeMaze[D_800F9B28_PipeMaze][D_800F9B2C_PipeMaze - 1] == 1 && D_800F9B2C_PipeMaze != 0 &&
        (s32)(arg0->trans.y - 400.0) % 400 == 0) {
        D_800F99D4_PipeMaze = -1;
    } else if (D_800F9AB8_PipeMaze[D_800F9B28_PipeMaze][D_800F9B2C_PipeMaze + 1] == 1 && D_800F9B2C_PipeMaze != 6 &&
               (s32)(arg0->trans.y - 400.0) % 400 == 0) {
        D_800F99D4_PipeMaze = 1;
    } else if (D_800F9AB8_PipeMaze[D_800F9B28_PipeMaze + 1][D_800F9B2C_PipeMaze] == 2 &&
               (s32)arg0->trans.x % 300 == 0) {
        D_800F99D4_PipeMaze = 0;
    }
    if (D_800F9B28_PipeMaze == -1) {
        D_800F99D4_PipeMaze = 0;
    }
    if (D_800F99D4_PipeMaze != D_800F99D6_PipeMaze) {
        PlaySound(0x218);
    }
    D_800F99D6_PipeMaze = D_800F99D4_PipeMaze;
    n = 0;
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 7; j++) {
            if (j & 1) {
                n += D_800F9AB8_PipeMaze[i][j] != 0;
            }
        }
    }
    for (i = 0; i < n; i++) {
        func_800F6DD8_PipeMaze(D_800F9B48_PipeMaze[i], 1);
    }
    for (i = 0; i < 4; i++) {
        func_800F6DD8_PipeMaze(D_800F9B40_PipeMaze[i], 0);
    }
    if (func_8005FD5C() + D_800F64F8 == 0) {
        if (D_800F99D4_PipeMaze == -1) {
            arg0->trans.x -= 30.0f;
            D_800F991C_PipeMaze -= 30.0f;
        } else if (D_800F99D4_PipeMaze == 1) {
            arg0->trans.x += 30.0f;
            D_800F991C_PipeMaze += 30.0f;
        } else if (D_800F99D4_PipeMaze == 0) {
            if (arg0->trans.y > -50.0f) {
                if (arg0->trans.y > 6200.0f) {
                    arg0->trans.y -= D_800F99D0_PipeMaze + 20.0f;
                    D_800F9920_PipeMaze -= D_800F99D0_PipeMaze + 20.0f;
                    D_800F99D0_PipeMaze += 8.0f;
                    if (arg0->trans.y < 6200.0f) {
                        arg0->trans.y = 6200.0f;
                    }
                    if (!(D_800F99D5_PipeMaze & 1)) {
                        func_8006035C(PlaySound(0x216), 0x7F);
                        D_800F99D5_PipeMaze |= 1;
                    }
                } else {
                    arg0->trans.y -= 20.0f;
                    D_800F9920_PipeMaze -= 20.0f;
                    if (!(D_800F99D5_PipeMaze & 2)) {
                        func_8006035C(PlaySound(0x218), 0x7F);
                        D_800F99D5_PipeMaze |= 2;
                    }
                }
            }
        }
        if (arg0->trans.y < 6500.0f && arg0->trans.y >= 500.0f) {
            arg0->trans.z = -1170.0f;
        }
        if (D_800F9B28_PipeMaze == 14) {
            D_800F99C8_PipeMaze = arg0->trans.x;
        }
        if (arg0->trans.y < 500.0f && !(D_800F99D5_PipeMaze & 4)) {
            func_8006035C(PlaySound(0x219), 0x7F);
            D_800F99D5_PipeMaze |= 4;
        }
        if (arg0->trans.y <= 250.0f) {
            arg0->trans.y -= 20.0f;
            if (arg0->trans.y <= 200.0f) {
                arg0->trans.y = 200.0f;
            }
        }
        if (arg0->trans.y == 200.0f) {
            D_800F2B7C[arg0->model[0]].unk_4C = 1.0f;
            if (D_800F99D8_PipeMaze == 35) {
                D_800F9B80_PipeMaze->trans.x = arg0->trans.x;
                D_800F9B80_PipeMaze->trans.y = arg0->trans.y;
                D_800F9B80_PipeMaze->trans.z = arg0->trans.z;
                func_8006BAF0(D_800F9B80_PipeMaze, 1);
                func_8006BADC(D_800F9B80_PipeMaze, D_800F99C8_PipeMaze, -150.0f, -800.0f);
            }
            if (D_800F99D8_PipeMaze >= 36 && func_8006BAFC(D_800F9B80_PipeMaze) == 0) {
                D_800F9900_PipeMaze = 1;
            }
            for (i = 0; i < 8; i++) {
                func_800258EC(arg0->model[i], 4, 4);
            }
            if (D_800F9900_PipeMaze == 1 && D_800F9A34_PipeMaze == D_800F9900_PipeMaze) {
                D_800F9A34_PipeMaze = 2;
            }
            D_800F99D8_PipeMaze++;
        }
    }
    D_800F9B80_PipeMaze->trans.x = arg0->trans.x;
    D_800F9B80_PipeMaze->trans.y = arg0->trans.y;
    D_800F9B80_PipeMaze->trans.z = arg0->trans.z;
    func_8006B9B0(D_800F9B80_PipeMaze, D_800F9B80_PipeMaze->trans.x, D_800F9B80_PipeMaze->trans.y,
                  D_800F9B80_PipeMaze->trans.z);
    D_800F9B30_PipeMaze = arg0->trans.x;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_09_PipeMaze/113DC0", func_800F8414_PipeMaze);
#endif
void func_800F8F24_PipeMaze(omObjData* arg0, s32 arg1) {
    if (D_800F9A34_PipeMaze == 1) {
        if ((Center.y < 6800.0f) && (D_800F990C_PipeMaze == 0)) {
            Center.y += 150.0f;
            omSysPauseEnableFlag = 1;
        } else if ((Center.y >= 6800.0f) && (D_800F990C_PipeMaze == 0)) {
            D_800F990C_PipeMaze = 1;
            omSysPauseEnableFlag = 0;
        }
        if (D_800F990C_PipeMaze == 3) {
            D_800F9A34_PipeMaze = 2;
        }
    }
}

void func_800F9000_PipeMaze(void) {
    s32 i;

    if (D_800F9B30_PipeMaze == -900.0f) {
        D_800F9918_PipeMaze = 0;
    } else if (D_800F9B30_PipeMaze == -300.0f) {
        D_800F9918_PipeMaze = 1;
    } else if (D_800F9B30_PipeMaze == 300.0f) {
        D_800F9918_PipeMaze = 2;
    } else if (D_800F9B30_PipeMaze == 900.0f) {
        D_800F9918_PipeMaze = 3;
    }
    for (i = 0; i < 4; i++) {
        D_800F3FB0[i]->rot.y = 0.0f;
        if (i == D_800F9918_PipeMaze) {
            func_800184BC(D_800F3FB0[i], 13);
        } else {
            func_800184BC(D_800F3FB0[i], 14);
        }
        func_80017DB0(D_800F3FB0[i]);
    }
}
void func_800F9134_PipeMaze(omObjData* arg0) {
    switch (D_800F9A34_PipeMaze) {
    case 0:
        if (D_800F99DC_PipeMaze == 0) {
            func_80060128(0x1F);
        }
        if (D_800F99DC_PipeMaze > 75.0) {
            D_800F9A34_PipeMaze = 1;
        }
        func_800F8F24_PipeMaze(arg0, D_800F99DC_PipeMaze);
        D_800F99DC_PipeMaze++;
        break;
    case 1:
        func_800F8F24_PipeMaze(arg0, D_800F99E4_PipeMaze);
        D_800F99E4_PipeMaze -= 2;
        break;
    case 2:
        if (D_800F99E0_PipeMaze == 0) {
            GMesCreate(2);
            func_800601D4(0x28);
        } else if (!(D_800F99F0_PipeMaze & 1) && (GMesStatAllGet() == 0 || GMesStatAllGet() & 2)) {
            if (_CheckFlag(0x2B) == 0) {
                func_80060128(0x33);
            }
            D_800F99F0_PipeMaze |= 3;
        }
        if (D_800F99F0_PipeMaze & 2) {
            D_800F99EC_PipeMaze++;
        }
        if (D_800F99EC_PipeMaze >= 3 && _CheckFlag(0x2B) == 0) {
            func_800F9000_PipeMaze();
        }
        if (D_800F99EC_PipeMaze == 36) {
            if (_CheckFlag(0x2B) == 0) {
                func_80060618(0x451, D_800F9988_PipeMaze[D_800F9918_PipeMaze]);
                GMesPosSet(GMesCreate(4, GwPlayer[D_800F9988_PipeMaze[D_800F9918_PipeMaze]].character), 160.0f, 160.0f);
            } else if (D_800F9B30_PipeMaze == -900.0f) {
                D_800F9918_PipeMaze = 0;
            } else if (D_800F9B30_PipeMaze == -300.0f) {
                D_800F9918_PipeMaze = 1;
            } else if (D_800F9B30_PipeMaze == 300.0f) {
                D_800F9918_PipeMaze = 2;
            } else if (D_800F9B30_PipeMaze == 900.0f) {
                D_800F9918_PipeMaze = 3;
            }
        } else if (D_800F99EC_PipeMaze == 93) {
            GwPlayer[D_800F9918_PipeMaze].coins_mg += 10;
            if (_CheckFlag(0x2B) == 0) {
                func_800726AC(0, 20);
            }
            D_800F9A34_PipeMaze = 3;
        }
        if (_CheckFlag(0x2B) != 0 && D_800F99EC_PipeMaze >= 93) {
            func_800726AC(0, 20);
        }
        func_800F8F24_PipeMaze(arg0, D_800F99E0_PipeMaze);
        D_800F99E0_PipeMaze++;
        break;
    case 3:
        if (D_800F99E8_PipeMaze == 0) {
            func_80060758(0x216);
            func_80060758(0x218);
            func_80060758(0x219);
            func_80060758(0xFC);
        }
        if (func_80072718() == 0) {
            omOvlReturnEx(1);
        }
        D_800F99E8_PipeMaze += 2;
        break;
    }
}
void func_800F9590_PipeMaze(omObjData* arg0) {
    PMEffectWork* w;
    s16 i;

    w = arg0->unk_50 = func_80023684(sizeof(PMEffectWork), 0x7918);
    for (i = 0; i < 20; i++) {
        w->e[i].unk1C = LoadFormFile(0x35, 0x8D);
        func_80021240(w->e[i].unk1C);
        func_80025EB4(w->e[i].unk1C, 1, 1);
        func_80025830(w->e[i].unk1C, 2.0f, 2.0f, 2.0f);
        w->state[i] = 0;
    }
    arg0->func_ptr = func_800F9678_PipeMaze;
}
void func_800F9678_PipeMaze(omObjData* arg0) {
    PMEffectWork* w;
    PMEffect* e;
    s16 mdl;
    s16 i;

    w = arg0->unk_50;
    for (i = 0; i < 20; i++) {
        if (w->state[i] == 0) {
            continue;
        }
        e = &w->e[i];
        mdl = e->unk1C;
        switch (w->state[i]) {
        case 1:
            break;
        case 2:
            e->unkC += e->unk18 * 8.0f;
            e->unk18 -= 0.5f;
            func_80025798(mdl, e->unk8, e->unkC, e->unk10);
            break;
        }
        func_800211BC(mdl, e->unk4);
        e->unk4 += 0x20;
        if (e->unk4 > 0x100) {
            func_800258EC(mdl, 4, 4);
            w->state[i] = 0;
        }
    }
}
s16 func_800F97C4_PipeMaze(s16 arg0, f32 arg1, f32 arg2, f32 arg3, u16 arg4) {
    PMEffectWork* w;
    PMEffect* e;
    s16 mdl;
    s16 i;

    w = D_800F9B74_PipeMaze->unk_50;
    for (i = 0; i < 20; i++) {
        if (w->state[i] == 0) {
            break;
        }
    }
    if (i == 20) {
        return 0;
    }
    e = &w->e[i];
    mdl = e->unk1C;
    e->unk8 = arg1;
    e->unkC = arg2;
    e->unk10 = arg3;
    e->unk18 = 0.0f;
    e->unk4 = 0;
    w->state[i] = arg4;
    e->unk2 = arg0;
    func_800211BC(mdl, 0);
    func_800258EC(mdl, 4, 0);
    func_80025798(mdl, arg1, arg2, arg3);
    func_80025F10(mdl, (s16)(1 << arg0));
    func_80025830(mdl, 2.0f, 2.0f, 2.0f);
    return mdl;
}
