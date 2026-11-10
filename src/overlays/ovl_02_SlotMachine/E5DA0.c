#include "SlotMachine.h"

f32 D_800FECD0_SlotMachine[8] = { 45.0f, 90.0f, 135.0f, 180.0f, 225.0f, 270.0f, 315.0f, 360.0f };
f32 D_800FECF0_SlotMachine[3][8] = {
    { 3.0f, 7.0f, 5.0f, 1.0f, 4.0f, 2.0f, 6.0f, 4.0f },
    { 7.0f, 4.0f, 3.0f, 6.0f, 1.0f, 5.0f, 2.0f, 4.0f },
    { 6.0f, 5.0f, 7.0f, 1.0f, 2.0f, 4.0f, 3.0f, 4.0f },
};
u8 D_800FED50_SlotMachine[10] = { 1, 2, 2, 3, 4, 4, 5, 6, 6, 7 };
u8 D_800FED5C_SlotMachine[4][3] = {
    { 0, 0, 0 },
    { 0, 4, 8 },
    { 0, 8, 16 },
    { 0, 16, 32 },
};
Vec3f D_800FED68_SlotMachine = { -130.0f, 420.0f, -100.0f };
Vec3f D_800FED74_SlotMachine = { 0.0f, 420.0f, -100.0f };
Vec3f D_800FED80_SlotMachine = { 130.0f, 420.0f, -100.0f };
SlotSymFx D_800FED8C_SlotMachine[8] = {
    { 2, 2, 0, 0 }, { 2, 2, 0, 1 }, { 2, 3, 0, 2 }, { 2, 4, 0, 3 },
    { 2, 3, 0, 4 }, { 3, 2, 0, 5 }, { 1, 1, 0, 6 }, { 1, 1, 0, 7 },
};
SlotFxKind D_800FEDAC_SlotMachine[4] = {
    { 3, 0, 40, 40 },
    { 6, 0, 60, 60 },
    { 3, 0, 0, 0 },
    { 3, 0, 0, 80 },
};
s8 D_800FEDBC_SlotMachine[4][3][2] = {
    { { -10, -3 }, { 0, -3 }, { 10, -3 } },
    { { -10, -3 }, { 0, -3 }, { 10, -3 } },
    { { 0x7F, 0 }, { 0, 0 }, { 0, 0 } },
    { { 0x7F, 0 }, { 0, 0 }, { 0, 0 } },
};

void func_800FC090_SlotMachine(s16 model) {
    char names[3][8] = { "r1", "r2", "r3" };
    SlotReel* reel;
    s32 i;
    u8 tmp;
    s32 j;

    D_800FFC8E_SlotMachine = model;
    D_800FFC94_SlotMachine = D_800FFC96_SlotMachine = -1;
    D_800FFC90_SlotMachine = 0;
    D_800FFC92_SlotMachine = 0;
    for (reel = D_800FFA70_SlotMachine, i = 0; i < 3; reel++, i++) {
        reel->unk_00 = 0;
        reel->unk_03 = reel->unk_01 = SLOT_RAND(8);
        reel->unk_02 = func_800FC8C8_SlotMachine(i, reel->unk_01);
        reel->unk_04 = 0;
        reel->unk_08 = func_800FC790_SlotMachine(reel->unk_01);
        reel->unk_0C = 0.0f;
        reel->unk_10 = reel->unk_14 = reel->unk_18 = 0.0f;
        reel->unk_1C = func_80026A0C(D_800FFC8E_SlotMachine, names[i]);
    }
    for (i = 0; i < 10; i++) {
        D_800FFA60_SlotMachine[i] = D_800FED50_SlotMachine[i % 10];
    }
    for (i = 0; i < 10; i++) {
        j = SLOT_RAND(10);
        tmp = D_800FFA60_SlotMachine[j];
        D_800FFA60_SlotMachine[j] = D_800FFA60_SlotMachine[i];
        D_800FFA60_SlotMachine[i] = tmp;
    }
    D_800FFA6A_SlotMachine = 0;
    D_800FFAD0_SlotMachine = -1;
    func_800FD248_SlotMachine();
}
s16 func_800FC2CC_SlotMachine(void) {
    u16 prev;
    u16 ret;
    s16 sym;
    s16 i;

    prev = D_800FFC90_SlotMachine;
    func_800FCC98_SlotMachine();
    ret = D_800FFC90_SlotMachine;
    if (D_800FFC90_SlotMachine == 0) {
        if (prev == 0) {
            goto end;
        }
        ret = 4;
        sym = func_800FC8C8_SlotMachine(0, D_800FFA70_SlotMachine[0].unk_01);
        for (i = 1; i < 3; i++) {
            if (sym != func_800FC8C8_SlotMachine(i, D_800FFA70_SlotMachine[i].unk_01)) {
                break;
            }
        }
        if (i == 3) {
            D_800FFC94_SlotMachine = sym;
        } else {
            D_800FFC94_SlotMachine = -1;
        }
        if (D_800FFAD0_SlotMachine >= 0) {
            func_8006071C((s16)D_800FFAD0_SlotMachine);
            D_800FFAD0_SlotMachine = -1;
        }
    }
end:
    func_800FD590_SlotMachine();
    return ret;
}
void func_800FC3F4_SlotMachine(void) {
    SlotReel* reel;
    s32 i;
    s32 r;

    if (D_800FFC90_SlotMachine == 0) {
        D_800FFC90_SlotMachine = 1;
        D_800FFC94_SlotMachine = D_800FFA60_SlotMachine[D_800FFA6A_SlotMachine++];
        if (D_800FFA6A_SlotMachine >= 10) {
            D_800FFA6A_SlotMachine = 0;
        }
        D_800FFC94_SlotMachine = -1;
        r = SLOT_RAND(4);
        for (i = 0, reel = D_800FFA70_SlotMachine; i < 3; i++, reel++) {
            reel->unk_03 = func_800FC904_SlotMachine(i, D_800FFC94_SlotMachine);
            reel->unk_08 = func_800FC790_SlotMachine(reel->unk_01);
            reel->unk_10 = 0.0f;
            reel->unk_18 = 9.0f;
            reel->unk_14 = (SLOT_RAND(50) + 50) * 0.01 * reel->unk_18 * 0.2;
            reel->unk_00 = 1;
            reel->unk_04 = D_800FED5C_SlotMachine[r][i];
        }
        if (D_800FFAD0_SlotMachine < 0) {
            D_800FFAD0_SlotMachine = func_80060540(0x1D4, 3);
        }
    }
}
void func_800FC5C4_SlotMachine(void) {
    s32 i;

    if ((u16)D_800FFC90_SlotMachine - 2 < 2U) {
        for (i = 0; i < 3; i++) {
            if (D_800FFA70_SlotMachine[i].unk_00 == 1) {
                D_800FFA70_SlotMachine[i].unk_00 = 2;
                D_800FFA70_SlotMachine[i].unk_04 = -1;
                D_800FFA70_SlotMachine[i].unk_14 = -(D_800FFA70_SlotMachine[i].unk_18 * 0.2);
                return;
            }
        }
    }
}

s16 func_800FC664_SlotMachine(void) {
    if (D_800FFC90_SlotMachine != 0) {
        return -1;
    }
    return D_800FFC94_SlotMachine;
}

s16 func_800FC684_SlotMachine(void) {
    s32 found;
    s32 sym;
    s32 frames;
    s32 i;

    found = 0;
    if ((u16)D_800FFC90_SlotMachine - 2 < 2U) {
        sym = 0;
        frames = 0;
        for (i = 0; i < 3; i++) {
            if (D_800FFA70_SlotMachine[i].unk_00 != 0) {
                if ((D_800FFA70_SlotMachine[i].unk_00 == 1) & (found != 0)) {
                    frames = (func_800FC790_SlotMachine(func_800FC904_SlotMachine(i, sym)) + 360.0 -
                              D_800FFA70_SlotMachine[i].unk_08) /
                             D_800FFA70_SlotMachine[i].unk_10;
                    break;
                }
            } else {
                found = 1;
                sym = D_800FFC94_SlotMachine;
            }
        }
        if (found) {
            return frames;
        }
    }
    return 0;
}
f32 func_800FC790_SlotMachine(s16 face) {
    return D_800FECD0_SlotMachine[face];
}
s16 func_800FC7A8_SlotMachine(f32 angle) {
    s16 i;

    for (i = 0; i < 8; i++) {
        if (angle <= D_800FECD0_SlotMachine[i]) {
            return i;
        }
    }
    return 0;
}
s16 func_800FC804_SlotMachine(f32 angle) {
    s16 i;

    for (i = 0; i < 8; i++) {
        if (i == 0) {
            if (angle <= (f32)(D_800FECD0_SlotMachine[0] * 0.5)) {
                return 7;
            }
        } else if (angle <= (f32)((D_800FECD0_SlotMachine[i] - D_800FECD0_SlotMachine[i - 1]) * 0.5 +
                                  D_800FECD0_SlotMachine[i - 1])) {
            return i - 1;
        }
    }
    return 7;
}
s16 func_800FC8C8_SlotMachine(s16 reel, s16 face) {
    return D_800FECF0_SlotMachine[reel][face];
}
s16 func_800FC904_SlotMachine(s16 reel, s16 symbol) {
    s16 i;

    for (i = 0; i < 8; i++) {
        if (symbol == D_800FECF0_SlotMachine[reel][i]) {
            return i;
        }
    }
    return SLOT_RAND(8);
}
void func_800FC9A8_SlotMachine(unk2C0C0Struct50* part) {
    f32 x = part->unk_64[3][0];
    f32 y = part->unk_64[3][1];
    f32 z = part->unk_64[3][2];

    func_800A2A50(part->unk_64);
    part->unk_64[3][0] = x;
    part->unk_64[3][1] = y;
    part->unk_64[3][2] = z;
    MtxRotate(part->unk_64, part->unk_44.x, part->unk_44.y, part->unk_44.z);
    MtxScale(part->unk_64, part->unk_50.x, part->unk_50.y, part->unk_50.z);
}
// decomp-permuter
void func_800FCA34_SlotMachine(s16 camera, Vec3f *pos, f32 *out)
{
  short new_var;
  f32 v[3];
  Matrix4f mtx;
  f32 (*m)[4];
  unk_Struct00 *cam;
  f32 t;
  f32 d;
  cam = &D_800C3110[camera];
  m = mtx;
  HuGuLookAtF(m, cam->pos.x, cam->pos.y, cam->pos.z, cam->unkC.x, cam->unkC.y, cam->unkC.z, cam->unk18.x, cam->unk18.y, cam->unk18.z);
  func_800FCBFC_SlotMachine(m, pos->x, pos->y, pos->z, v);
  t = func_800AEAC0(cam->unk_40 * 0.5);
  t = t / func_800AEFD0(cam->unk_40 * 0.5);
  d = t * v[2];
  if (d < 0.0f)
  {
    d = -d;
  }
  new_var = 16;
  out[0] = (((((unk_Struct00 *) ((D_800F3FA8 * new_var) + ((u8 *) cam)))->unk58 / 4.0) * v[0]) / d) * 0.75;
  out[1] = ((((unk_Struct00 *) ((D_800F3FA8 * new_var) + ((u8 *) cam)))->unk5A / 4.0) * (-v[1])) / d;
}
void func_800FCBFC_SlotMachine(Matrix4f m, f32 x, f32 y, f32 z, f32* out) {
    *out++ = x * m[0][0] + y * m[1][0] + z * m[2][0] + m[3][0];
    *out++ = x * m[0][1] + y * m[1][1] + z * m[2][1] + m[3][1];
    *out = x * m[0][2] + y * m[1][2] + z * m[2][2] + m[3][2];
}
// register allocation: s0/s1/s2 permuted (masked 0)
#ifdef NON_MATCHING
void func_800FCC98_SlotMachine(void) {
    s16 face;
    s16 cnt;
    SlotReel* reel;
    s16 t;
    s32 i;
    s16 stopped;
    s16 spinning;
    s32 j;
    f32 a;

    spinning = 0;
    stopped = 0;
    t = 0;
    for (reel = D_800FFA70_SlotMachine, i = 0; i < 3; reel++, i++) {
        switch (reel->unk_00) {
            case 0:
                reel->unk_10 = 0.0f;
                stopped++;
                break;
            case 1:
                if (reel->unk_04 != 0) {
                    reel->unk_04--;
                } else {
                    reel->unk_10 += reel->unk_14;
                }
                if (reel->unk_10 >= reel->unk_18) {
                    reel->unk_10 = reel->unk_18;
                } else {
                    spinning++;
                }
                reel->unk_08 += reel->unk_10;
                reel->unk_08 = (reel->unk_08 >= 360.0) ? reel->unk_08 - 360.0 : reel->unk_08;
                reel->unk_08 = (reel->unk_08 < 0.0) ? reel->unk_08 + 360.0 : reel->unk_08;
                break;
            case 2:
                if (reel->unk_04 < 0) {
                    t = 0;
                    if (D_800FFC94_SlotMachine >= 0) {
                        face = func_800FC804_SlotMachine(reel->unk_08);
                        t = -(face != func_800FC7A8_SlotMachine(reel->unk_08));
                        for (; t < 2; t++) {
                            if (D_800FFC94_SlotMachine == func_800FC8C8_SlotMachine(i, face)) {
                                break;
                            }
                            if (++face >= 8) {
                                face = 0;
                            }
                        }
                        if (t < 2) {
                            reel->unk_03 = face;
                            if (t < 0) {
                                t = 0;
                                reel->unk_01 = face;
                            }
                        } else {
                            t = 0;
                        }
                    }
                    reel->unk_04 = t;
                }
                if (reel->unk_04 == 0) {
                    reel->unk_03 = reel->unk_01;
                }
                if (reel->unk_03 == reel->unk_01) {
                    reel->unk_04 = 0;
                }
                reel->unk_08 += reel->unk_10;
                reel->unk_08 = (reel->unk_08 >= 360.0) ? reel->unk_08 - 360.0 : reel->unk_08;
                reel->unk_08 = (reel->unk_08 < 0.0) ? reel->unk_08 + 360.0 : reel->unk_08;
                t = func_800FC7A8_SlotMachine(reel->unk_08);
                if (t != reel->unk_01) {
                    if (reel->unk_04 != 0) {
                        reel->unk_04--;
                    } else {
                        reel->unk_08 = func_800FC790_SlotMachine(reel->unk_01);
                        reel->unk_00 = 0;
                        reel->unk_14 = reel->unk_10 = 0.0f;
                        PlaySound(0x1D5);
                        D_800FFC94_SlotMachine = func_800FC8C8_SlotMachine(i, func_800FC7A8_SlotMachine(reel->unk_08));
                        stopped++;
                        face = func_800FC8C8_SlotMachine(0, D_800FFA70_SlotMachine[0].unk_01);
                        if (face == func_800FC8C8_SlotMachine(i, reel->unk_01) && D_800FFC94_SlotMachine >= 6) {
                            for (j = i + 1; j < 3; j++) {
                                D_800FFA70_SlotMachine[j].unk_18 *= 1.2;
                            }
                        }
                    }
                }
                break;
        }
        reel->unk_01 = func_800FC7A8_SlotMachine(reel->unk_08);
        reel->unk_02 = func_800FC8C8_SlotMachine(i, reel->unk_01);
        a = (f32)(reel->unk_08 + -5.0 + reel->unk_0C) + 0.0f;
        a = (a >= 360.0) ? a - 360.0 : a;
        a = (a < 0.0) ? a + 360.0 : a;
        reel->unk_1C->unk_44.x = a;
        func_800FC9A8_SlotMachine(reel->unk_1C);
    }
    D_800FFC96_SlotMachine = -1;
    if (spinning != 0) {
        D_800FFC90_SlotMachine = 1;
    } else if (stopped == 3) {
        D_800FFC90_SlotMachine = 0;
    } else {
        D_800FFC90_SlotMachine = 2;
        cnt = 0;
        if (stopped == 2) {
            face = -1;
            for (i = 0; i < 3; i++) {
                if (D_800FFA70_SlotMachine[i].unk_00 == 0) {
                    t = func_800FC8C8_SlotMachine(i, D_800FFA70_SlotMachine[i].unk_01);
                    if ((face >= 0) & (t != face)) {
                        break;
                    }
                    cnt++;
                    face = t;
                }
            }
            if (cnt == stopped) {
                D_800FFC90_SlotMachine = 3;
                D_800FFC96_SlotMachine = t;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_SlotMachine/E5DA0", func_800FCC98_SlotMachine);
#endif
void func_800FD248_SlotMachine(void) {
    void* data;
    SlotFx* fx;
    s32 i;

    data = DataRead(0x140015);
    D_800FFC88_SlotMachine = func_800678A4(data);
    DataClose(data);
    D_800FFC8A_SlotMachine = func_80064EF4(6, 0);
    for (fx = D_800FFAD8_SlotMachine, i = 0; i < 6; fx++, i++) {
        fx->unk_02 = fx->unk_01 = fx->unk_03 = fx->unk_00 = 0;
        fx->unk_04 = fx->unk_08 = fx->unk_0C = 0.0f;
        fx->unk_10 = fx->unk_14 = 0.0f;
        fx->unk_18 = fx->unk_1C = 1.0f;
        fx->unk_20 = 0.0f;
        fx->unk_24 = 1.0f;
        fx->unk_28 = fx->unk_2C = fx->unk_30 = fx->unk_34 = 0.0f;
        fx->unk_3A = fx->unk_3C = fx->unk_38 = 0;
        fx->unk_3E = fx->unk_40 = fx->unk_42 = fx->unk_44 = 0;
        func_80067208(D_800FFC8A_SlotMachine, i, D_800FFC88_SlotMachine, 0);
        func_80066DC4(D_800FFC8A_SlotMachine, i, 160, 120);
        func_80067354(D_800FFC8A_SlotMachine, i, 1.0f, 1.0f);
        func_8006752C(D_800FFC8A_SlotMachine, i, 0x100);
        func_800674BC(D_800FFC8A_SlotMachine, i, 0x9008);
        func_800672B0(D_800FFC8A_SlotMachine, i, 0);
    }
    D_800FFC8C_SlotMachine = D_800FFC90_SlotMachine;
    D_800FFC96_SlotMachine = D_800FFC9A_SlotMachine = -1;
    D_800FFC98_SlotMachine = D_800FFC9C_SlotMachine = 0;
    D_800FFCA0_SlotMachine = 0;
    D_800FFC9E_SlotMachine = -1;
}
void func_800FD420_SlotMachine(void) {
    SlotFx* fx;
    s32 i;

    for (fx = D_800FFAD8_SlotMachine, i = 0; i < 6; fx++, i++) {
        if ((fx->unk_00 & 0xC0) == 0xC0) {
            func_80067480(D_800FFC8A_SlotMachine, i, 0x8000);
            func_800671DC(D_800FFC8A_SlotMachine, i, fx->unk_03);
            func_80066DC4(D_800FFC8A_SlotMachine, i, fx->unk_10 + 160.0f, fx->unk_14 + 120.0f);
            func_80067354(D_800FFC8A_SlotMachine, i, fx->unk_18, fx->unk_1C);
            func_8006752C(D_800FFC8A_SlotMachine, i, (s32)(fx->unk_24 * 256.0f));
            func_800673B0(D_800FFC8A_SlotMachine, i, fx->unk_20);
        } else {
            func_800674BC(D_800FFC8A_SlotMachine, i, 0x8000);
        }
    }
}
// one 0.2 constant hoisted out of the loop (breaks a cross-jump), D_800FEDBC row-base form, FP register
// numbering (n64chkf masked 143, mostly shifted branch targets; ~10 instructions after masking those)
#ifdef NON_MATCHING
void func_800FD590_SlotMachine(void) {
    f32 pos[3][2];
    SlotFx* fx;
    s32 i;
    s32 burst;
    s32 done;
    s32 b;
    SlotFx* e;
    s32 k;
    s16 sym;
    s16 kind;
    u8 frame;
    f32 a;

    func_800FCA34_SlotMachine(0, &D_800FED68_SlotMachine, pos[0]);
    func_800FCA34_SlotMachine(0, &D_800FED74_SlotMachine, pos[1]);
    func_800FCA34_SlotMachine(0, &D_800FED80_SlotMachine, pos[2]);
    burst = 0;
    if (D_800FFC90_SlotMachine != D_800FFC8C_SlotMachine) {
        D_800FFC8C_SlotMachine = D_800FFC90_SlotMachine;
        switch (D_800FFC90_SlotMachine) {
            case 3:
                D_800FFCA0_SlotMachine = 0;
                break;
            case 1:
            case 2:
                D_800FFC98_SlotMachine = 0;
                break;
            case 0:
                if (D_800FFC94_SlotMachine < 0) {
                    D_800FFCA0_SlotMachine = -1;
                } else {
                    if (D_800FFC98_SlotMachine == 0) {
                        D_800FFC96_SlotMachine = D_800FFC94_SlotMachine;
                    }
                    D_800FFC9A_SlotMachine = D_800FFC94_SlotMachine;
                    D_800FFC9C_SlotMachine = 20;
                }
                break;
        }
    }
    if (D_800FFC96_SlotMachine >= 0 && D_800FFC98_SlotMachine == 0) {
        sym = D_800FFC96_SlotMachine;
        kind = D_800FED8C_SlotMachine[sym].unk_00;
        frame = D_800FED8C_SlotMachine[sym].unk_03;
        for (fx = D_800FFAD8_SlotMachine, i = 0; i < D_800FEDAC_SlotMachine[kind].unk_00; fx++, i++) {
            k = i % 3;
            fx->unk_00 = 0xC0;
            fx->unk_01 = kind;
            fx->unk_03 = frame;
            fx->unk_02 = 0;
            fx->unk_38 = sym;
            if (D_800FEDBC_SlotMachine[kind][0][0] == 0x7F) {
                fx->unk_28 = fx->unk_10 = pos[k][0];
                fx->unk_2C = fx->unk_14 = pos[k][1];
            } else {
                fx->unk_28 = fx->unk_10 = (D_800FEDBC_SlotMachine + kind)[0][k][0] * 10.0;
                fx->unk_2C = fx->unk_14 = (D_800FEDBC_SlotMachine + kind)[0][k][1] * 10.0;
            }
            fx->unk_24 = D_800FEDAC_SlotMachine[kind].unk_01 * 0.1;
            fx->unk_30 = fx->unk_18 = D_800FEDAC_SlotMachine[kind].unk_02 * 0.1;
            fx->unk_34 = fx->unk_1C = D_800FEDAC_SlotMachine[kind].unk_03 * 0.1;
            fx->unk_20 = 0.0f;
            fx->unk_3A = fx->unk_3C = 0;
            fx->unk_3E = fx->unk_40 = fx->unk_42 = fx->unk_44 = 0;
        }
        for (; i < 6; i++) {
            D_800FFAD8_SlotMachine[i].unk_00 = 0;
        }
        burst = 1;
        D_800FFC9E_SlotMachine = -1;
        D_800FFC98_SlotMachine = burst;
        PlaySound(0x1D6);
    } else if (D_800FFC9C_SlotMachine != 0) {
        for (i = 0; i < 3; i++) {
            if (D_800FFAD8_SlotMachine[i].unk_02 != 1) {
                break;
            }
        }
        if (i >= 3 && --D_800FFC9C_SlotMachine == 0) {
            if (D_800FFC9E_SlotMachine & 0x1F) {
                D_800FFC9C_SlotMachine++;
            } else {
                for (fx = D_800FFAD8_SlotMachine, i = 0; i < 3; fx++, i++) {
                    fx->unk_02 = 2;
                    fx->unk_3A = fx->unk_3C = 0;
                }
                for (; i < 6; i++) {
                    D_800FFAD8_SlotMachine[i].unk_00 = 0;
                }
                D_800FFC9A_SlotMachine = -1;
            }
        }
    }
    if (D_800FFC9E_SlotMachine >= 0) {
        D_800FFC9E_SlotMachine = (D_800FFC9E_SlotMachine + 1) & 0x7FFF;
    }
    b = burst;
    fx = D_800FFAD8_SlotMachine;
    for (i = 0; i < 6; i++) {
        e = &fx[i];
        if (e->unk_00 == 0) {
            continue;
        }
        e->unk_3A++;
        if (e->unk_02 == 0) {
            done = 0;
            if ((e->unk_40 == 0 || e->unk_3E != 0) && D_800FFCA0_SlotMachine < 0) {
                e->unk_00 = 0;
                continue;
            }
            if (!b) {
                if (e->unk_40 == 0) {
                    if (D_800FFA70_SlotMachine[i % 3].unk_00 == 0) {
                        e->unk_40++;
                    }
                    continue;
                }
                if (e->unk_3E != 0) {
                    e->unk_3E--;
                    continue;
                }
                a = e->unk_24 + 0.1;
                if (a >= 1.0) {
                    a = 1.0f;
                    e->unk_3C++;
                    done = 1;
                }
                e->unk_24 = a;
            }
            a = e->unk_24;
            switch (e->unk_01) {
                case 0:
                case 1:
                    if (b) {
                        if (i >= 3) {
                            e->unk_3E = 5;
                        } else {
                            e->unk_3E = 0;
                        }
                        continue;
                    }
                    e->unk_10 = (pos[i % 3][0] - e->unk_28) * a + e->unk_28;
                    e->unk_14 = (pos[i % 3][1] - e->unk_2C) * a + e->unk_2C;
                case 2:
                case 3:
                    e->unk_18 = e->unk_30 + (1.0 - e->unk_30) * a;
                    e->unk_1C = e->unk_34 + (1.0 - e->unk_34) * a;
                    break;
            }
            if (done) {
                e->unk_02 = 1;
                if (i < 3) {
                    e->unk_01 = D_800FED8C_SlotMachine[e->unk_38].unk_01;
                } else {
                    e->unk_01 = 0;
                }
                if (D_800FFC9E_SlotMachine < 0) {
                    D_800FFC9E_SlotMachine = 0;
                }
                e->unk_3A = D_800FFC9E_SlotMachine;
                e->unk_3C = 0;
            }
        } else if (e->unk_02 == 1) {
            if (e->unk_3C == 0) {
                e->unk_24 = 0.8f;
                e->unk_3C++;
                e->unk_18 = e->unk_1C = 1.0f;
            }
            switch (e->unk_01) {
                case 0:
                    e->unk_24 = (f32)(D_800FFC9E_SlotMachine & 0xF) / 16.0 * 0.6 + 0.2;
                    e->unk_20 = func_800AEAC0((D_800FFC9E_SlotMachine & 0x1F) * 360.0 / 32.0) * 15.0;
                    break;
                case 1:
                    e->unk_18 = e->unk_1C = func_800AEAC0((D_800FFC9E_SlotMachine & 0xF) * 90.0 / 16.0) * 0.6 + 1.0;
                    e->unk_24 = (1.0 - (f32)(D_800FFC9E_SlotMachine & 0xF) / 16.0) * 0.8;
                    e->unk_20 = func_800AEAC0((D_800FFC9E_SlotMachine & 0x1F) * 360.0 / 32.0) * 15.0;
                    break;
                case 2:
                    e->unk_20 = func_800AEAC0((D_800FFC9E_SlotMachine & 0xF) * 360.0 / 16.0) * 30.0;
                    break;
                case 4:
                    e->unk_20 = func_800AEAC0((D_800FFC9E_SlotMachine & 0x1F) * 360.0 / 32.0) * 30.0;
                case 3:
                    e->unk_1C = (func_800AEFD0((D_800FFC9E_SlotMachine & 0xF) * 360.0 / 16.0 - 90.0) + 1.0) * 0.15 + 1.0;
                    break;
            }
            if (D_800FFCA0_SlotMachine < 0) {
                e->unk_02 = 3;
                e->unk_3C = 0;
            }
        } else if (e->unk_02 == 2) {
            if (e->unk_3C == 0) {
                if (i >= 3) {
                    e->unk_00 = 0;
                }
                e->unk_3C++;
                e->unk_24 = 0.8f;
                e->unk_18 = e->unk_1C = 1.0f;
                e->unk_20 = 0.0f;
                e->unk_28 = e->unk_2C = 1.0f;
                e->unk_3A = 0;
            }
            if (e->unk_3A >= i * 2) {
                e->unk_18 = e->unk_1C = e->unk_2C;
                e->unk_2C += 0.2;
                e->unk_24 = e->unk_28 * 0.8;
                if ((e->unk_28 -= 0.1) <= 0.0f) {
                    e->unk_00 = 0;
                }
            }
        } else if (e->unk_02 == 3) {
            if (e->unk_3C == 0) {
                if (i >= 3) {
                    e->unk_00 = 0;
                }
                e->unk_3C++;
                e->unk_24 = 0.8f;
                e->unk_18 = e->unk_1C = 1.0f;
                e->unk_20 = 0.0f;
                e->unk_28 = 1.0f;
            }
            e->unk_24 = e->unk_28 * 0.8;
            e->unk_1C = e->unk_28;
            if ((e->unk_28 -= 0.2) <= 0.0f) {
                e->unk_00 = 0;
            }
        }
    }
    func_800FD420_SlotMachine();
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_02_SlotMachine/E5DA0", func_800FD590_SlotMachine);
#endif
