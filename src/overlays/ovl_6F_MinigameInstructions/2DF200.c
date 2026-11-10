#include "ovl6f.h"


extern s8 ContStkY[];

void func_800FA540_MinigameInstructions(void) {
    Process* proc = HuPrcCurrentGet();
    Ovl6FPairS16* state = proc->relative->user_data;
    Ovl6FPlayerWork* work = proc->user_data;

    work->unk_B6 = work->unk_B8 = work->unk_BA = work->unk_BC = work->unk_B4 = 0;
    work->unk_20 = work->unk_24 = work->unk_28 = 0.0f;
    work->unk_B0 = (3 - work->unk_38) * 4;
    work->unk_40 = GwPlayer[work->unk_38].character;
    D_8010F762_MinigameInstructions = 0;
    D_8010E970_MinigameInstructions[(s16) D_8010F766_MinigameInstructions].fn[0](work);
    while (1) {
        HuPrcVSleep();
        if (state->unk_00 == 1) {
            func_800FA630_MinigameInstructions(work);
        }
    }
}
void func_800FA630_MinigameInstructions(Ovl6FPlayerWork* work) {
    Ovl6FPairS16* state = HuPrcCurrentGet()->relative->user_data;

    HuPrcSleep(work->unk_B0);
    work->unk_44 = work->unk_46 = work->unk_48 = work->unk_4A = -1;
    work->unk_4C = 0;
    D_8010E970_MinigameInstructions[(s16) D_8010F766_MinigameInstructions].fn[1](work);
    state->unk_02++;
    work->unk_B2 = 0;
    while (1) {
        HuPrcVSleep();
        if (state->unk_00 == 2) {
            break;
        }
        D_8010E970_MinigameInstructions[(s16) D_8010F766_MinigameInstructions].fn[2](work);
        work->unk_B2 = 1;
    }
    D_8010F762_MinigameInstructions = 1;
    HuPrcSleep(work->unk_38 * 4);
    D_8010E970_MinigameInstructions[(s16) D_8010F766_MinigameInstructions].fn[3](work);
    state->unk_02++;
    do {
        HuPrcVSleep();
    } while (state->unk_00 != 0);
    D_8010F762_MinigameInstructions = 0;
}
void func_800FA77C_MinigameInstructions(s32 file) {
    if (D_8010E960_MinigameInstructions == NULL) {
        D_8010E960_MinigameInstructions = func_80021308(file, 0x10);
        omAddPrcObj(func_800FA7C8_MinigameInstructions, 0x3F00, 0x800, 0);
    }
}

void func_800FA7C8_MinigameInstructions(void) {
    while (1) {
        HuPrcVSleep();
        func_800214FC(D_8010E960_MinigameInstructions);
    }
}
void func_800FA7F8_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s32 ch;

    ch = GwPlayer[work->unk_38].character;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x9F, 0x299);
    work->unk_50 = func_80023FC8(work->unk_4E);
    func_800258EC(work->unk_50, 4, 4);
    work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 3, 0x1D);
    work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 1, 0x1D);
    work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 5, 0x1D);
    work->unk_58 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 9, 0x1D);
    work->unk_5A = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x1C, 0x1D);
    work->unk_5C = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 4, 0x1D);
    work->unk_5E = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 6, 0x1D);
    if (D_8010F760_MinigameInstructions == 0) {
        work->unk_08 = 78.0f;
    } else {
        work->unk_08 = (work->unk_38 * 35) + 25;
    }
    func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
    in.x = work->unk_00 = -50.0f;
    in.y = work->unk_04 = 150.0f;
    out.z = 0.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
}
void func_800FA9EC_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s16 angle;

    func_800258EC(work->unk_4E, 4, 0);
    func_80025BB8(work->unk_4E, work->unk_52);
    func_80025EB4(work->unk_4E, 2, 2);
    func_800257E4(work->unk_4E, 0.0f, 90.0f, 0.0f);
    in.x = work->unk_00;
    in.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 < work->unk_08) {
        in.x = work->unk_00 += 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
        func_80025798(work->unk_4E, out.x, out.y, -180.0f);
        if ((work->unk_42++ & 3) == 0) {
            func_800FA300_MinigameInstructions(0x119, work);
        }
        HuPrcVSleep();
    }
    in.x = work->unk_00 = work->unk_08;
    func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
    for (angle = 90; angle >= 0; angle -= 30) {
        func_800257E4(work->unk_4E, 0.0f, angle, 0.0f);
        HuPrcVSleep();
        if ((work->unk_42++ & 7) == 0) {
            func_800FA300_MinigameInstructions(0x112, work);
        }
    }
    func_80025C20(work->unk_4E, func_80025E48(work->unk_50), 0, 8, 2);
    work->unk_3C = 0;
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    work->unk_14 = -180.0f;
    work->unk_20 = 0.0f;
    work->unk_24 = 90.0f;
    work->unk_28 = 0.0f;
    HuPrcSleep(8);
}
void func_800FAC2C_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s16 angle;

    if (func_80025E48(work->unk_4E) != func_80025E48(work->unk_52)) {
        func_80025C20(work->unk_4E, func_80025E48(work->unk_52), 0, 8, 2);
    }
    HuPrcSleep(8);
    for (angle = 0; angle >= -90; angle -= 30) {
        func_800257E4(work->unk_4E, 0.0f, angle, 0.0f);
        if ((work->unk_42++ & 7) == 0) {
            func_800FA300_MinigameInstructions(0x119, work);
        }
        HuPrcVSleep();
    }
    in.x = work->unk_00;
    in.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 > -50.0f) {
        in.x = work->unk_00 -= 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
        func_80025798(work->unk_4E, out.x, out.y, -180.0f);
        if ((work->unk_42++ & 3) == 0) {
            func_800FA300_MinigameInstructions(0x112, work);
        }
        HuPrcVSleep();
    }
}
extern s8 ContStkY[4]; /* engine/pad.h */
extern u16 ContBtn[4];

// loop.c hoists 180.0f into $f28 (retail reloads it each use); s4/s5 swapped (masked 47)
#ifdef NON_MATCHING
void func_800FADF4_MinigameInstructions(Ovl6FPlayerWork* work) {
    s16 prevState;
    s16 port;
    f32 x;
    f32 y;
    f32 mag;
    u32 flags;
    s16 motion;
    s32 used;
    f32 t;
    f32 step;
    f32 amp;
    f32 h;

    port = GwPlayer[work->unk_38].port;
    x = (s8)(ContStkX[port] / 10);
    y = (s8)(ContStkY[port] / 10);
    mag = x * x + y * y;
    flags = D_8010E970_MinigameInstructions[(s16)D_8010F766_MinigameInstructions].flags;
    motion = 0;
    if (mag != 0.0f && (flags & 3)) {
        func_800257E4(work->unk_4E, 0.0f, func_800B0CD8(x, -y), 0.0f);
    }
    prevState = work->unk_3C;
    if ((ContBtnTrg[port] & 0x8000) && (flags & 4) && work->unk_56 != -1) {
        work->unk_3C = 3;
        used = 0;
        func_80025C20(work->unk_4E, func_80025E48(work->unk_56), 0, 8, 0);
        func_800FA300_MinigameInstructions(0x127, work);
        t = 0.0f;
        step = 10.0f;
        amp = 100.0f;
        h = func_800AEAC0(t) * amp;
        do {
            t += step;
            if ((ContBtnTrg[port] & 0x2000) && work->unk_3C != 4 && (flags & 8) && (used ^ 1) && work->unk_58 != -1) {
                work->unk_3C = 4;
                step = 20.0f;
                t = 90.0f;
                D_800F2B7C[work->unk_4E].unk_0C = -1;
                amp = h;
                func_80025BB8(work->unk_4E, work->unk_58);
                func_800FA300_MinigameInstructions(0x147, work);
                func_800FB4DC_MinigameInstructions(work->unk_4E);
            } else if (work->unk_3C != 4 && t == 40.0f && !(ContBtn[port] & 0x8000)) {
                t = 90.0f;
                amp = h;
            }
            if (ContBtnTrg[port] & 0x4000) {
                if ((flags & 0x60) && t > 20.0f && work->unk_3C != 4 && (used ^ 1) && work->unk_5C != -1) {
                    func_800FA300_MinigameInstructions(0x13C, work);
                    D_800F2B7C[work->unk_4E].unk_0C = -1;
                    if (flags & 0x20) {
                        func_80025BB8(work->unk_4E, work->unk_5E);
                    } else {
                        func_80025BB8(work->unk_4E, work->unk_5C);
                    }
                    amp = h;
                    used = 1;
                    func_800FB4DC_MinigameInstructions(work->unk_4E);
                    step = 20.0f;
                    t = 90.0f;
                }
            }
            if (t > 180.0f) {
                t = 180.0f;
            }
            h = func_800AEAC0(t) * amp;
            func_80025798(work->unk_4E, work->unk_0C, h + work->unk_10, work->unk_14);
            HuPrcVSleep();
        } while (t < 180.0f);
        if (work->unk_3C == 4) {
            func_800FA300_MinigameInstructions(0x14E, work);
            func_800FA3AC_MinigameInstructions(2, work);
            t = 0.0f;
            do {
                t += 20.0f;
                h = func_800AEAC0(t) * 20.0f;
                func_80025798(work->unk_4E, work->unk_0C, h + work->unk_10, work->unk_14);
                HuPrcVSleep();
            } while (t < 180.0f);
            func_80025BB8(work->unk_4E, work->unk_5A);
            func_800FB4DC_MinigameInstructions(work->unk_4E);
        } else {
            func_800FA300_MinigameInstructions(0x12E, work);
            func_80025C20(work->unk_4E, func_80025E48(work->unk_50), 0, 8, 2);
        }
        mag = 0.0f;
    }
    if (mag == 0.0f) {
        work->unk_3C = 0;
        motion = func_80025E48(work->unk_50);
    } else if (mag <= 16.0f && (flags & 1)) {
        work->unk_3C = 1;
        motion = func_80025E48(work->unk_54);
        func_800FB590_MinigameInstructions(work, motion);
    } else if (mag > 16.0f && (flags & 2)) {
        work->unk_3C = 2;
        motion = func_80025E48(work->unk_52);
        func_800FB60C_MinigameInstructions(work, motion);
    }
    if ((ContBtnTrg[port] & 0x4000) && (flags & 0x10) && work->unk_5C != -1) {
        func_800FA300_MinigameInstructions(0x135, work);
        func_80025BB8(work->unk_4E, work->unk_5C);
        D_800F2B7C[work->unk_4E].unk_0C = -1;
        func_800FB4DC_MinigameInstructions(work->unk_4E);
        prevState = -1;
        work->unk_3C = 0;
        motion = func_80025E48(work->unk_50);
    }
    if (prevState != work->unk_3C) {
        func_80025C20(work->unk_4E, motion, 0, 8, 2);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FADF4_MinigameInstructions);
#endif
void func_800FB4DC_MinigameInstructions(s16 model) {
    do {
        HuPrcVSleep();
        if (D_800F2B7C[model].unk_0A & 4) {
            if (func_80025D18(model) <= 0.0f) {
                break;
            }
        } else if (func_80025D18(model) == func_80025D40(model)) {
            break;
        }
    } while (1);
}
void func_800FB590_MinigameInstructions(Ovl6FPlayerWork* work, s16 motion) {
    if (func_80025D18(work->unk_4E) == 0.0f || func_80025E48(work->unk_4E) != motion) {
        func_800FA300_MinigameInstructions(0x112, work);
    }
}
void func_800FB60C_MinigameInstructions(Ovl6FPlayerWork* work, s16 motion) {
    if (func_80025D18(work->unk_4E) == 0.0f || func_80025E48(work->unk_4E) != motion) {
        func_800FA300_MinigameInstructions(0x119, work);
    }
}
void func_800FB688_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s32 ch;

    ch = GwPlayer[work->unk_38].character;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x9F, 0x29D);
    work->unk_50 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x40, 0x1D);
    func_80025BB8(work->unk_4E, work->unk_50);
    func_800FA77C_MinigameInstructions(0x150004);
    func_80021B04(D_8010E960_MinigameInstructions, 0x80, 0x80, 0x80);
    work->unk_08 = (work->unk_38 * 35) + 25;
    func_80025830(work->unk_4E, 0.35f, 0.35f, 0.35f);
    in.x = work->unk_00 = -50.0f;
    in.y = work->unk_04 = 130.0f;
    out.z = 0.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
}
void func_800FB7D8_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s16 angle;

    func_800258EC(work->unk_4E, 4, 0);
    func_80025EB4(work->unk_4E, 2, 2);
    D_800F2B7C[work->unk_4E].unk_4C = 3.0f;
    func_800257E4(work->unk_4E, 90.0f, 0.0f, 90.0f);
    in.x = work->unk_00;
    in.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 < work->unk_08) {
        in.x = work->unk_00 += 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
        func_80025798(work->unk_4E, out.x, out.y, -180.0f);
        if ((work->unk_42++ & 3) == 0) {
            func_800FA2C0_MinigameInstructions(0x1DD, work);
        }
        HuPrcVSleep();
    }
    in.x = work->unk_00 = work->unk_08;
    func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
    for (angle = 90; angle <= 180; angle += 30) {
        func_800257E4(work->unk_4E, 90.0f, 0.0f, angle);
        HuPrcVSleep();
    }
    work->unk_3C = 0;
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    work->unk_14 = -180.0f;
    work->unk_20 = 90.0f;
    work->unk_24 = 0.0f;
    work->unk_28 = 180.0f;
    D_800F2B7C[work->unk_4E].unk_4C = 0.0f;
}
void func_800FBA14_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s16 angle;

    func_80025EB4(work->unk_4E, 3, 2);
    D_800F2B7C[work->unk_4E].unk_4C = 3.0f;
    for (angle = 180; angle <= 270; angle += 30) {
        func_800257E4(work->unk_4E, 90.0f, 0.0f, angle);
        HuPrcVSleep();
    }
    in.x = work->unk_00;
    in.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 > -50.0f) {
        in.x = work->unk_00 -= 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
        func_80025798(work->unk_4E, out.x, out.y, -180.0f);
        if ((work->unk_42++ & 3) == 0) {
            func_800FA2C0_MinigameInstructions(0x1DD, work);
        }
        HuPrcVSleep();
    }
    func_800258EC(work->unk_4E, 4, 4);
}
void func_800FBBA8_MinigameInstructions(Ovl6FPlayerWork* work) {
    s16 port;
    f32 x;
    f32 y;
    f32 mag;
    f32 a;
    f32 d;
    s16 id;

    port = GwPlayer[work->unk_38].port;
    x = (s8)(ContStkX[port] / 10);
    y = (s8)(ContStkY[port] / 10);
    mag = func_800B1750(x * x + y * y);
    if (x != 0.0f || y != 0.0f) {
        a = func_800B0CD8(x, -y);
        if (work->unk_28 != a) {
            d = a - work->unk_28;
            d = d * d;
            if (d < 324.0f || d > 116964.0f) {
                work->unk_28 = a;
            } else if (work->unk_28 < 180.0f) {
                if (work->unk_28 < a && a < work->unk_28 + 180.0f) {
                    work->unk_28 += 18.0f;
                } else {
                    work->unk_28 -= 18.0f;
                }
            } else {
                if (work->unk_28 - 180.0f < a && a < work->unk_28) {
                    work->unk_28 -= 18.0f;
                } else {
                    work->unk_28 += 18.0f;
                }
            }
        }
        func_800257E4(work->unk_4E, 90.0f, 0.0f, work->unk_28);
    }
    if (ContBtnTrg[port] & 0x8000) {
        if ((work->unk_42++ & 1) == 0) {
            func_800FA2C0_MinigameInstructions(0x1DD, work);
        }
        id = func_80021794(D_8010E960_MinigameInstructions, 0, func_800AEAC0(work->unk_28) * 15.0f + work->unk_0C,
                           func_800AEFD0(work->unk_28 + 180.0f) * 15.0f + work->unk_10, work->unk_14, 4);
        if (id != -1) {
            func_800257E4(D_800ECDE0[D_8010E960_MinigameInstructions->unk_00[id].unk_1C].unk_00, 0.0f, 0.0f,
                          work->unk_28 + 180.0f);
        }
        work->unk_B4 = 8;
    }
    if (work->unk_B4 != 0) {
        work->unk_B4--;
        D_800F2B7C[work->unk_4E].unk_4C = 2.0f;
        if ((work->unk_4C++ & 0xF) == 0) {
            func_80060F04(work->unk_38, 5, 0, 5);
        }
    } else {
        D_800F2B7C[work->unk_4E].unk_4C = mag / 4.0f;
    }
}
void func_800FC008_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s16 ch;

    ch = GwPlayer[work->unk_38].character;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x9F, 0x29D);
    work->unk_50 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x17, 0x1D);
    work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0xC, 0x1D);
    work->unk_08 = (work->unk_38 * 35) + 25;
    work->unk_B4 = 0;
    work->unk_18 = 0.0f;
    func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
    in.x = work->unk_00 = -50.0f;
    if (ch == 4) {
        in.y = work->unk_04 = 140.0f;
    } else if (ch == 5) {
        in.y = work->unk_04 = 125.0f;
    } else {
        in.y = work->unk_04 = 130.0f;
    }
    out.z = 0.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
}
void func_800FC190_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s16 angle;

    func_800258EC(work->unk_4E, 4, 0);
    func_80025BB8(work->unk_4E, work->unk_52);
    func_80025EB4(work->unk_4E, 2, 2);
    func_800257E4(work->unk_4E, 0.0f, 90.0f, 0.0f);
    in.x = work->unk_00;
    in.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 < work->unk_08) {
        in.x = work->unk_00 += 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
        func_80025798(work->unk_4E, out.x, out.y, -180.0f);
        if ((work->unk_42++ & 3) == 0) {
            func_800FA300_MinigameInstructions(0x163, work);
        }
        HuPrcVSleep();
    }
    in.x = work->unk_00 = work->unk_08;
    func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
    for (angle = 90; angle >= 0; angle -= 30) {
        func_800257E4(work->unk_4E, 0.0f, angle, 0.0f);
        HuPrcVSleep();
    }
    func_80025C20(work->unk_4E, func_80025E48(work->unk_50), 0, 8, 2);
    work->unk_3C = 0;
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    work->unk_14 = -180.0f;
    work->unk_20 = 0.0f;
    work->unk_24 = 90.0f;
    work->unk_28 = 0.0f;
    HuPrcSleep(8);
}
void func_800FC3B0_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s16 angle;

    if (func_80025E48(work->unk_4E) != func_80025E48(work->unk_52)) {
        func_80025C20(work->unk_4E, func_80025E48(work->unk_52), 0, 8, 2);
    }
    HuPrcSleep(8);
    for (angle = 0; angle >= -90; angle -= 30) {
        func_800257E4(work->unk_4E, 0.0f, angle, 0.0f);
        HuPrcVSleep();
    }
    in.x = work->unk_00;
    in.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 > -50.0f) {
        in.x = work->unk_00 -= 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
        func_80025798(work->unk_4E, out.x, out.y, -180.0f);
        if ((work->unk_42++ & 3) == 0) {
            func_800FA300_MinigameInstructions(0x163, work);
        }
        HuPrcVSleep();
    }
}
void func_800FC558_MinigameInstructions(Ovl6FPlayerWork* work) {
    s16 port;
    f32 x;
    f32 y;
    f32 decay;
    s16 motion;

    port = GwPlayer[work->unk_38].port;
    x = (s8)(ContStkX[port] / 10);
    y = (s8)(ContStkY[port] / 10);
    if (x * x + y * y != 0.0f) {
        func_800257E4(work->unk_4E, 0.0f, func_800B0CD8(x, -y), 0.0f);
    }
    if (x != 0.0f) {
        if (x < 0.0f) {
            work->unk_24 -= 10.0f;
            if (work->unk_24 < -90.0f) {
                work->unk_24 = -90.0f;
            }
        } else {
            work->unk_24 += 10.0f;
            if (work->unk_24 > 90.0f) {
                work->unk_24 = 90.0f;
            }
        }
    } else {
        work->unk_24 = 0.0f;
    }
    if (y != 0.0f) {
        if (work->unk_18 != 0.0f) {
            if (y > 0.0f) {
                work->unk_20 -= work->unk_18 * 5.0f;
                if (work->unk_20 < -90.0f) {
                    work->unk_20 = -90.0f;
                }
            } else {
                work->unk_20 += work->unk_18 * 5.0f;
                if (work->unk_20 > 90.0f) {
                    work->unk_20 = 90.0f;
                }
            }
        } else {
            work->unk_20 /= 2.0f;
            if (work->unk_20 * work->unk_20 < 1.0f) {
                work->unk_20 = 0.0f;
            }
        }
    } else if (work->unk_20 != 0.0f) {
        work->unk_20 /= 2.0f;
        if (work->unk_20 * work->unk_20 < 1.0f) {
            work->unk_20 = 0.0f;
        }
    }
    func_800257E4(work->unk_4E, work->unk_20, work->unk_24, work->unk_28);
    if (ContBtnTrg[port] & 0x8000) {
        work->unk_18 += 1.0f;
        motion = func_80025E48(work->unk_52);
        if (func_80025E48(work->unk_4E) != motion && D_800F2B7C[work->unk_4E].unk_0C != motion) {
            func_800FA300_MinigameInstructions(0x163, work);
            func_80025C20(work->unk_4E, func_80025E48(work->unk_52), 0, 8, 2);
        }
        if (work->unk_4C == 0) {
            work->unk_4C = 8;
            func_800FA3AC_MinigameInstructions(0, work);
        }
        decay = 0.05f;
    } else {
        decay = 0.2f;
    }
    if (work->unk_4C != 0) {
        work->unk_4C--;
    }
    if (work->unk_18 != 0.0f) {
        work->unk_18 -= decay;
        if (work->unk_18 <= 0.0f) {
            func_80025C20(work->unk_4E, func_80025E48(work->unk_50), 0, 8, 2);
            work->unk_18 = 0.0f;
        }
    }
}
void func_800FC9F8_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    void* data;

    data = DataRead(D_8010EDD0_MinigameInstructions[GwPlayer[work->unk_38].character]);
    work->unk_90 = func_8001E00C(data, 0, 0);
    work->unk_4E = D_800ECDE0[work->unk_90].unk_00;
    DataClose(data);
    func_80025830(work->unk_4E, 1.7f, 1.7f, 1.7f);
    func_800FA77C_MinigameInstructions(0x2A);
    func_80021B04(D_8010E960_MinigameInstructions, 0xFF, 0xFF, 0x5F);
    work->unk_08 = (work->unk_38 * 35) + 25;
    work->unk_B4 = 0;
    in.x = work->unk_00 = -50.0f;
    in.y = work->unk_04 = 130.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
}
void func_800FCB50_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;

    in.x = work->unk_00;
    in.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 < work->unk_08) {
        in.x = work->unk_00;
        func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
        func_80025798(work->unk_4E, out.x, out.y, -180.0f);
        work->unk_00 += 12.0f;
        HuPrcVSleep();
    }
    in.x = work->unk_00 = work->unk_08;
    func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
    work->unk_0C = out.x;
    work->unk_10 = out.y;
}
void func_800FCC54_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;

    in.x = work->unk_00;
    in.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 > -50.0f) {
        in.x = work->unk_00 -= 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
        func_80025798(work->unk_4E, out.x, out.y, -180.0f);
        HuPrcVSleep();
    }
}
void func_800FCD20_MinigameInstructions(Ovl6FPlayerWork* work) {
    s16 port;
    f32 x;
    f32 y;
    unk_800ECDE0* spr;

    port = GwPlayer[work->unk_38].port;
    x = (s8)(ContStkX[port] / 10);
    y = (s8)(ContStkY[port] / 10);
    func_800B1750(x * x + y * y);
    spr = &D_800ECDE0[work->unk_90];
    if (ContBtnTrg[port] & 0x8000) {
        func_800FA2C0_MinigameInstructions(0x23E, work);
        spr->unk_06 = 1;
        spr->unk_08 = 0;
        spr->unk_04 = 0;
        func_800FA3AC_MinigameInstructions(1, work);
        func_80021794(D_8010E960_MinigameInstructions, 0, work->unk_0C, work->unk_10, -180.0f, 2);
        work->unk_B6 = 1;
    }
    if (work->unk_B6 != 0 && !(ContBtn[port] & 0x8000)) {
        spr->unk_06 = 0;
        spr->unk_08 = 0;
        spr->unk_04 = 0;
        work->unk_B6 = 1;
    }
}
void func_800FCED0_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s32 ch;
    void* data;

    ch = GwPlayer[work->unk_38].character;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x9F, 0x29D);
    work->unk_50 = func_80023FC8(work->unk_4E);
    work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 3, 0x1D);
    work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x2E, 0x1D);
    func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
    work->unk_08 = (work->unk_38 * 30) + 40;
    in.x = work->unk_00 = -50.0f;
    in.y = work->unk_04 = 140.0f;
    work->unk_14 = -230.0f;
    func_8001DD24(0, CZoom - work->unk_14, (Vec3f*)&in, &out);
    func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
    work->unk_70 = LoadFormFile(0x250002, 0x289);
    func_80025EB4(work->unk_70, 1, 1);
    func_80025830(work->unk_70, 0.01f, 0.01f, 0.01f);
    in.x = work->unk_08;
    in.y = 140.0f;
    func_8001DD24(0, CZoom - -200.0f, (Vec3f*)&in, &out);
    func_80025798(work->unk_70, out.x, out.y, -200.0f);
    data = DataRead(0x250009);
    work->unk_90 = func_80038A9C(D_800F2B7C[work->unk_70].unk_6C, data, 0, "pump0_DEF");
    DataClose(data);
    func_80025AD4(work->unk_70);
    func_80025B34(work->unk_70);
    func_80039644(work->unk_90, 1, 1);
}
void func_800FD130_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s16 angle;
    s16 i;
    f32 scale;

    func_800258EC(work->unk_4E, 4, 0);
    func_80025BB8(work->unk_4E, work->unk_52);
    func_80025EB4(work->unk_4E, 2, 2);
    func_800257E4(work->unk_4E, 0.0f, 90.0f, 0.0f);
    in.x = work->unk_00;
    in.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 < work->unk_08) {
        in.x = work->unk_00 += 12.0f;
        func_8001DD24(0, CZoom - work->unk_14, (Vec3f*)&in, &out);
        func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
        if ((work->unk_42++ & 3) == 0) {
            func_800FA300_MinigameInstructions(0x119, work);
        }
        HuPrcVSleep();
    }
    in.x = work->unk_00 = work->unk_08;
    func_8001DD24(0, CZoom - work->unk_14, (Vec3f*)&in, &out);
    func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
    for (angle = 90; angle >= 0; angle -= 30) {
        func_800257E4(work->unk_4E, 0.0f, angle, 0.0f);
        HuPrcVSleep();
    }
    func_80025C20(work->unk_4E, func_80025E48(work->unk_54), 2, 8, 1);
    func_80025CA8(work->unk_70, 2.0f);
    func_800396B0(work->unk_90, 0);
    work->unk_B4 = 2;
    work->unk_B8 = 0;
    work->unk_3C = 0;
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    work->unk_20 = 0.0f;
    work->unk_24 = 90.0f;
    work->unk_28 = 0.0f;
    for (i = 0; i < 9; i++) {
        scale = i / 8.0f * 0.4f;
        func_80025830(work->unk_70, scale, scale, scale);
        if ((work->unk_42++ & 7) == 0) {
            func_800FA300_MinigameInstructions(0x112, work);
        }
        HuPrcVSleep();
    }
}
void func_800FD408_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s16 i;
    s16 angle;
    f32 scale;

    if (func_80025E48(work->unk_4E) != func_80025E48(work->unk_52)) {
        func_80025C20(work->unk_4E, func_80025E48(work->unk_52), 0, 8, 2);
    }
    for (i = 8; i >= 0.0f; i--) {
        scale = i / 8.0f * 0.4f;
        func_80025830(work->unk_70, scale, scale, scale);
        HuPrcVSleep();
    }
    for (angle = 0; angle >= -90; angle -= 30) {
        func_800257E4(work->unk_4E, 0.0f, angle, 0.0f);
        if ((work->unk_42++ & 7) == 0) {
            func_800FA300_MinigameInstructions(0x112, work);
        }
        HuPrcVSleep();
    }
    in.x = work->unk_00;
    in.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 > -50.0f) {
        in.x = work->unk_00 -= 12.0f;
        func_8001DD24(0, CZoom - work->unk_14, (Vec3f*)&in, &out);
        func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
        if ((work->unk_42++ & 3) == 0) {
            func_800FA300_MinigameInstructions(0x119, work);
        }
        HuPrcVSleep();
    }
    func_800258EC(work->unk_4E, 4, 4);
}
void func_800FD674_MinigameInstructions(Ovl6FPlayerWork* work) {
    s16 port;

    port = GwPlayer[work->unk_38].port;
    if ((ContBtn[port] & 0xE000) == 0x8000) {
        if ((work->unk_B4 += 2) < 18) {
            if ((ContBtnTrg[port] & 0x8000) || work->unk_B8 == 1) {
                func_800FA2C0_MinigameInstructions(0x26C, work);
            }
            func_80025CA8(work->unk_4E, work->unk_B4);
            func_80025CA8(work->unk_70, work->unk_B4);
            func_800396B0(work->unk_90, work->unk_B4 * 0.22222222f);
            work->unk_B8 = 0;
        } else {
            work->unk_B4 = 18;
            work->unk_B8 = 0;
        }
    } else {
        if (!(ContBtn[port] & 0x8000) && (ContBtn[port] & 0x6000)) {
            if ((work->unk_B4 -= 2) >= 0) {
                if ((ContBtnTrg[port] & 0x6000) || work->unk_B8 == 0) {
                    func_800FA2C0_MinigameInstructions(0x26B, work);
                }
                func_80025CA8(work->unk_4E, work->unk_B4);
                func_80025CA8(work->unk_70, work->unk_B4);
                func_800396B0(work->unk_90, work->unk_B4 * 0.22222222f);
            } else {
                work->unk_B4 = 0;
            }
            work->unk_B8 = 1;
        }
    }
    if (work->unk_B4 == 0) {
        if (work->unk_B6 & 1) {
            func_800396B0(work->unk_90, 8);
        } else {
            func_800396B0(work->unk_90, 0);
        }
        work->unk_B6++;
    }
}
void func_800FD954_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s16 ch;

    ch = GwPlayer[work->unk_38].character;
    if ((work->unk_3E = GwPlayer[work->unk_38].group) == 0) {
        work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x9F, 0x299);
        work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x6A, 0x1D);
        work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x75, 0x1D);
        work->unk_70 = LoadFormFile(0x11, 0x299);
        func_80025830(work->unk_70, 0.28f, 0.28f, 0.28f);
        func_80025798(work->unk_70, -1000.0f, 0.0f, 0.0f);
        func_8002859C(work->unk_70, work->unk_4E, D_8010F268_MinigameInstructions);
        func_80025830(work->unk_4E, 0.28f, 0.28f, 0.28f);
        work->unk_08 = (work->unk_38 * 30) + 40;
        in.x = work->unk_00 = -50.0f;
        in.y = work->unk_04 = 140.0f;
        work->unk_14 = -180.0f;
    } else {
        work->unk_4E = LoadFormFile(D_8010EDE8_MinigameInstructions[ch], 0x29D);
        work->unk_70 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x9F, 0x29D);
        func_80025830(work->unk_4E, 0.28f, 0.28f, 0.28f);
        func_80020EA0(work->unk_70, (*(D_8010EE00_MinigameInstructions + ch))[0], work->unk_4E,
                      (*(D_8010EE00_MinigameInstructions + ch))[1]);
        in.x = work->unk_00 = (work->unk_38 * 30) + 40;
        in.y = work->unk_04 = 140.0f;
        work->unk_14 = -230.0f;
    }
    func_8001DD24(0, CZoom - work->unk_14, (Vec3f*)&in, &out);
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
    func_800257E4(work->unk_4E, 0.0f, 0.0f, 0.0f);
}
void func_800FDBF8_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s16 i;
    f32 scale;
    f32 rot;

    func_800258EC(work->unk_4E, 4, 0);
    if (work->unk_3E == 0) {
        func_800258EC(work->unk_70, 0x4000, 0x4000);
        func_80025BB8(work->unk_4E, work->unk_54);
        func_80025EB4(work->unk_4E, 2, 2);
        D_800F2B7C[work->unk_4E].unk_4C = 3.0f;
        in.x = work->unk_00;
        in.y = work->unk_04;
        out.z = 0.0f;
        while (work->unk_00 < work->unk_08) {
            in.x = work->unk_00 += 12.0f;
            func_8001DD24(0, CZoom - work->unk_14, (Vec3f*)&in, &out);
            func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
            HuPrcVSleep();
        }
        in.x = work->unk_00 = work->unk_08;
        func_8001DD24(0, CZoom - work->unk_14, (Vec3f*)&in, &out);
        work->unk_0C = out.x;
        work->unk_10 = out.y;
        func_80025798(work->unk_4E, work->unk_0C, work->unk_10, work->unk_14);
        D_800F2B7C[work->unk_4E].unk_4C = 1.0f;
        func_80025BB8(work->unk_4E, work->unk_52);
        func_80025EB4(work->unk_4E, 1, 1);
    } else {
        for (i = 0; i < 9; i++) {
            scale = i * 0.035f;
            rot = 180.0f - i * 22.5f;
            func_800257E4(work->unk_4E, 0.0f, rot, 0.0f);
            func_80025830(work->unk_4E, scale, scale, scale);
            HuPrcVSleep();
        }
    }
    work->unk_44 = -1;
}
void func_800FDEA4_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s16 i;
    f32 scale;
    f32 rot;

    if (work->unk_3E == 0) {
        if (work->unk_44 != -1) {
            func_80060BC8(work->unk_44, 0x14);
        }
        if (work->unk_46 != -1) {
            func_80060BC8(work->unk_46, 0x14);
        }
        func_80025BB8(work->unk_4E, work->unk_54);
        func_80025EB4(work->unk_4E, 2, 2);
        D_800F2B7C[work->unk_4E].unk_4C = 3.0f;
        in.x = work->unk_00;
        in.y = work->unk_04;
        out.z = work->unk_14;
        while (work->unk_00 > -50.0f) {
            in.x = work->unk_00 -= 12.0f;
            func_8001DD24(0, CZoom - work->unk_14, (Vec3f*)&in, &out);
            func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
            HuPrcVSleep();
        }
        func_800258EC(work->unk_70, 0x4000, 0);
    } else {
        for (i = 0; i < 9; i++) {
            scale = 0.4f - i * 0.035f;
            rot = i * 22.5f;
            func_800257E4(work->unk_4E, 0.0f, rot, 0.0f);
            func_80025830(work->unk_4E, scale, scale, scale);
            HuPrcVSleep();
        }
    }
    func_800258EC(work->unk_4E, 4, 4);
    work->unk_3C = 0;
}

// the -30.0f spin clamp is hoisted out of the loop into a saved register here; retail reloads it (masked 55, registers only)
#ifdef NON_MATCHING
void func_800FE0E8_MinigameInstructions(Ovl6FPlayerWork* work) {
    f32 height;
    f32 z2;
    f32 z;
    f32 spin;
    f32 t;
    f32 amp;
    s8 stick;
    s16 port;

    port = GwPlayer[work->unk_38].port;
    if (work->unk_3E == 0) {
        if ((s8)(ContStkX[port] / 10) != 0 && work->unk_3C != 1) {
            func_80025BB8(work->unk_4E, work->unk_54);
            func_80025EB4(work->unk_4E, 3, 2);
            work->unk_3C = 1;
        } else if ((s8)(ContStkX[port] / 10) == 0 && work->unk_3C == 1) {
            work->unk_3C = 0;
            func_80025BB8(work->unk_4E, work->unk_52);
            func_80025EB4(work->unk_4E, 1, 1);
        }
        if (ContBtnTrg[port] & 0x8000) {
            func_80025BB8(work->unk_4E, work->unk_52);
            while (func_80025D18(work->unk_4E) < 110.0f) {
                HuPrcVSleep();
            }
            func_800FA284_MinigameInstructions(0x257);
            func_800258EC(work->unk_70, 0x4000, 0);
            height = 14.0f;
            z2 = work->unk_14 - 2.8f;
            func_80025830(work->unk_70, 0.28f, 0.28f, 0.28f);
            z = work->unk_14;
            spin = 0.0f;
            work->unk_30 = spin;
            work->unk_46 = func_800FA284_MinigameInstructions(0x258);
            while (TRUE) {
                z -= 10.0f;
                if (z < -10000.0f) {
                    z = -10000.0f;
                }
                if (height <= 0.0f) {
                    height = 0.0f;
                } else {
                    height -= 5.0f;
                }
                func_80025798(work->unk_4E, work->unk_0C, work->unk_10, z);
                func_80025798(work->unk_70, work->unk_0C - 28.0f, height + work->unk_10, z2);
                stick = ContStkX[port] / 10;
                if (stick != 0) {
                    spin += (stick < 0) ? -1.0f : 1.0f;
                    if (spin >= 30.0f) {
                        spin = 30.0f;
                    }
                    if (spin <= -30.0f) {
                        spin = -30.0f;
                    }
                } else {
                    spin = (spin < 0.0f) ? spin + 0.5f : spin + -0.5f;
                    if (spin <= 0.5f && spin >= -0.5f) {
                        spin = 0.0f;
                    }
                }
                if (spin != 0.0f) {
                    if (work->unk_44 == -1) {
                        work->unk_44 = func_800FA284_MinigameInstructions(0x25A);
                    }
                    func_800FA350_MinigameInstructions(work->unk_44, ((spin < 0.0f) ? -spin : spin) / 30.0f * 500.0f);
                } else {
                    if (work->unk_44 != -1) {
                        func_800FA380_MinigameInstructions(work->unk_44);
                    }
                    work->unk_44 = -1;
                }
                work->unk_30 = spin + work->unk_30;
                if (work->unk_30 > 360.0f) {
                    work->unk_30 -= 360.0f;
                }
                if (work->unk_30 < -360.0f) {
                    work->unk_30 += 360.0f;
                }
                func_800257E4(work->unk_70, 0.0f, work->unk_30, 0.0f);
                if ((ContBtnTrg[port] & 0xC000) || D_8010F762_MinigameInstructions != 0) {
                    break;
                }
                HuPrcVSleep();
            }
            if (work->unk_44 != -1) {
                func_80060BC8(work->unk_44, 20);
            }
            if (work->unk_46 != -1) {
                func_80060BC8(work->unk_46, 20);
            }
            work->unk_44 = work->unk_46 = -1;
            func_80025798(work->unk_70, -1000.0f, 0.0f, 0.0f);
            func_800257E4(work->unk_70, 0.0f, 0.0f, 0.0f);
            func_80025798(work->unk_4E, work->unk_0C, work->unk_10, work->unk_14);
            func_800258EC(work->unk_70, 0x4000, 0x4000);
            func_80025BB8(work->unk_4E, work->unk_54);
            func_80025EB4(work->unk_4E, 1, 1);
        }
    } else {
        if (func_800FE8D8_MinigameInstructions(port) != 0.0f) {
            work->unk_24 = func_800B0CD8(ContStkX[port], -ContStkY[port]);
            func_800257E4(work->unk_4E, 0.0f, work->unk_24, 0.0f);
        }
        if (ContBtnTrg[port] & 0x8000) {
            func_800FA284_MinigameInstructions(0x263);
            for (t = 0.0f; t <= 180.0f; t += 20.0f) {
                if (func_800FE8D8_MinigameInstructions(port) != 0.0f) {
                    work->unk_24 = func_800B0CD8(ContStkX[port], -ContStkY[port]);
                    func_800257E4(work->unk_4E, 0.0f, work->unk_24, 0.0f);
                }
                func_80025798(work->unk_4E, work->unk_0C, func_800AEAC0(t) * 20.0f + work->unk_10, work->unk_14);
                HuPrcVSleep();
            }
            amp = 30.0f;
            for (t = 0.0f; t <= 360.0f; t += 20.0f) {
                func_800257E4(work->unk_4E, func_800AEAC0(t) * amp, work->unk_24, 0.0f);
                amp -= 1.5f;
                HuPrcVSleep();
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_800FE0E8_MinigameInstructions);
#endif
f32 func_800FE8D8_MinigameInstructions(s16 port) {
    f32 x = ContStkX[port];
    f32 y = ContStkY[port];

    return x * x + y * y;
}
const char D_8010F18C_MinigameInstructions[] __attribute__((section(".rodata"))) = "c030_000-kaodamy";

const char D_8010F1A0_MinigameInstructions[] __attribute__((section(".rodata"))) = "c005_000-bmerge1";

const char D_8010F1B4_MinigameInstructions[] __attribute__((section(".rodata"))) = "c029_000-kaodamy";

const char D_8010F1C8_MinigameInstructions[] __attribute__((section(".rodata"))) = "Luigi1-atama_1";

const char D_8010F1D8_MinigameInstructions[] __attribute__((section(".rodata"))) = "c028_000-kaodamy";

const char D_8010F1EC_MinigameInstructions[] __attribute__((section(".rodata"))) = "c003_000-head_1";

const char D_8010F1FC_MinigameInstructions[] __attribute__((section(".rodata"))) = "c027_000-kaodamy";

const char D_8010F210_MinigameInstructions[] __attribute__((section(".rodata"))) = "C002_000b-bmerge10_1";

const char D_8010F228_MinigameInstructions[] __attribute__((section(".rodata"))) = "c026_000-kaodamy";

const char D_8010F23C_MinigameInstructions[] __attribute__((section(".rodata"))) = "Luigi1-atama_2";

const char D_8010F24C_MinigameInstructions[] __attribute__((section(".rodata"))) = "c025_000-kaodamy";

const char D_8010F260_MinigameInstructions[] __attribute__((section(".rodata"))) = "atama_2";

const char D_8010F268_MinigameInstructions[] __attribute__((section(".rodata"))) = "item_hook";

const char D_8010F274_MinigameInstructions[] __attribute__((section(".rodata"))) = "38mt006_DEF";

const char D_8010F280_MinigameInstructions[] __attribute__((section(".rodata"))) = "38mt005_DEF";

const char D_8010F28C_MinigameInstructions[] __attribute__((section(".rodata"))) = "38mt004_DEF";

const char D_8010F298_MinigameInstructions[] __attribute__((section(".rodata"))) = "38mt003_DEF";

const char D_8010F2A4_MinigameInstructions[] __attribute__((section(".rodata"))) = "38mt002_DEF";

/* D_8010EE30[0] points at this string too, so it keeps its label. */
const char D_8010F2B0_MinigameInstructions[] __attribute__((section(".rodata"))) = "38mt001_DEF";

void func_800FE924_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    u8 chr;

    chr = GwPlayer[work->unk_38].character;

    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9F, 0x29D);
    work->unk_50 = func_80023FC8(work->unk_4E);
    work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 3, 0x1D);
    work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 1, 0x1D);
    func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
    if (work->unk_38 == 0) {
        work->unk_72 = LoadFormFile(0x310002, 0x29D);
    }
    work->unk_70 = LoadFormFile(0x310001, 0x289);
    func_80027AC8(work->unk_70, (u8*)D_8010F2B0_MinigameInstructions, D_8010EE30_MinigameInstructions[chr]);
    func_80025AD4(work->unk_70);
    func_80025B34(work->unk_70);
    func_80025830(work->unk_70, 0.4f, 0.4f, 0.4f);
    if (D_8010F760_MinigameInstructions == 0) {
        work->unk_08 = 78.0f;
    } else {
        work->unk_08 = work->unk_38 * 30 + 40;
    }
    pos.x = work->unk_00 = -50.0f;
    pos.y = work->unk_04 = 150.0f;
    work->unk_14 = -180.0f;
    func_8001DD24(0, CZoom - work->unk_14, (Vec3f*)&pos, &out);
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    func_80025798(work->unk_4E, out.x, out.y + 20.0f, work->unk_14);
    func_80025798(work->unk_70, out.x, out.y, work->unk_14);
    work->unk_2C = 0.0f;
}
void func_800FEB5C_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 i;

    func_800258EC(work->unk_4E, 4, 0);
    func_80025BB8(work->unk_4E, work->unk_52);
    func_80025EB4(work->unk_4E, 2, 2);
    func_800257E4(work->unk_4E, 0.0f, 90.0f, 0.0f);
    func_800257E4(work->unk_70, 0.0f, 90.0f, 0.0f);
    pos.x = work->unk_00;
    pos.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 < work->unk_08) {
        pos.x = work->unk_00 += 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_4E, out.x, out.y + 20.0f, work->unk_14);
        func_80025798(work->unk_70, out.x, out.y, work->unk_14);
        func_800257E4(work->unk_70, work->unk_2C, 90.0f, 0.0f);
        work->unk_2C += 20.0f;
        HuPrcVSleep();
    }
    pos.x = work->unk_00 = work->unk_08;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    func_80025798(work->unk_4E, out.x, out.y + 20.0f, work->unk_14);
    func_80025798(work->unk_70, out.x, out.y, work->unk_14);
    for (i = 90; i >= 0; i -= 30) {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        func_800257E4(work->unk_70, work->unk_2C, i, 0.0f);
        work->unk_2C += 2.0f;
        HuPrcVSleep();
    }
    func_80025C20(work->unk_4E, func_80025E48(work->unk_50), 0, 8, 2);
    work->unk_3C = 0;
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    work->unk_14 = -180.0f;
    work->unk_20 = 0.0f;
    work->unk_24 = 90.0f;
    work->unk_28 = 0.0f;
    HuPrcSleep(8);
}
void func_800FEE08_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 i;

    if (func_80025E48(work->unk_4E) != func_80025E48(work->unk_52)) {
        func_80025C20(work->unk_4E, func_80025E48(work->unk_52), 0, 8, 2);
    }
    HuPrcSleep(8);
    for (i = 0; i >= -90; i -= 30) {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        func_800257E4(work->unk_70, work->unk_2C, i, 0.0f);
        work->unk_2C += 2.0f;
        HuPrcVSleep();
    }
    pos.x = work->unk_00;
    pos.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 > -50.0f) {
        pos.x = work->unk_00 -= 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_4E, out.x, out.y + 20.0f, work->unk_14);
        func_80025798(work->unk_70, out.x, out.y, work->unk_14);
        func_800257E4(work->unk_70, work->unk_2C, 90.0f, 0.0f);
        work->unk_2C += 20.0f;
        HuPrcVSleep();
    }
    func_800258EC(work->unk_4E, 4, 4);
}
void func_800FF010_MinigameInstructions(Ovl6FPlayerWork* work) {
    f32 x;
    f32 y;
    f32 mag;
    s16 motion;
    u16 prev;
    u8 port;

    motion = 0;
    port = GwPlayer[work->unk_38].port;
    x = ContStkX[port];
    y = ContStkY[port];
    mag = func_800B1750(x * x + y * y);
    if (mag != 0.0f) {
        work->unk_24 = func_800B0CD8(x, -y);
        func_800257E4(work->unk_4E, 0.0f, work->unk_24, 0.0f);
        func_800257E4(work->unk_70, work->unk_30, work->unk_24, 0.0f);
    }
    prev = work->unk_3C;
    if (mag == 0.0f) {
        work->unk_3C = 0;
        motion = func_80025E48(work->unk_50);
    } else if (mag <= 16.0f) {
        work->unk_3C = 1;
        motion = func_80025E48(work->unk_54);
        work->unk_2C += 10.0f;
        func_800257E4(work->unk_70, work->unk_2C, work->unk_24, 0.0f);
    } else if (mag > 16.0f) {
        work->unk_3C = 2;
        motion = func_80025E48(work->unk_52);
        work->unk_2C += 20.0f;
        func_800257E4(work->unk_70, work->unk_2C, work->unk_24, 0.0f);
    }
    if ((s16)prev != work->unk_3C) {
        func_80025C20(work->unk_4E, motion, 0, 8, 2);
    }
    if (work->unk_2C > 360.0f) {
        work->unk_2C -= 360.0f;
    }
}
void func_800FF23C_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    u8 chr;

    chr = GwPlayer[work->unk_38].character;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9F, 0x29D);
    work->unk_50 = func_80023FC8(work->unk_4E);
    work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 3, 0x1D);
    work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x53, 0x1D);
    func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
    work->unk_70 = LoadFormFile(0x1E0006, 0x29D);
    func_80025830(work->unk_70, 0.4f, 0.4f, 0.4f);
    func_80025EB4(work->unk_70, 1, 1);
    work->unk_08 = 70.0f;
    pos.x = work->unk_00 = -50.0f;
    pos.y = work->unk_04 = 150.0f;
    work->unk_14 = -180.0f;
    func_8001DD24(0, CZoom - work->unk_14, (Vec3f*)&pos, &out);
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
}
void func_800FF3CC_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 i;

    work->unk_34 = 0.0f;
    work->unk_B4 = 0;
    func_800258EC(work->unk_4E, 4, 0);
    func_80025BB8(work->unk_4E, work->unk_52);
    func_80025EB4(work->unk_4E, 2, 2);
    func_800257E4(work->unk_4E, 0.0f, 90.0f, 0.0f);
    pos.x = work->unk_00;
    pos.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 < work->unk_08) {
        pos.x = work->unk_00 += 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
        HuPrcVSleep();
    }
    pos.x = work->unk_00 = work->unk_08;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
    for (i = 90; i >= -90; i -= 30) {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        HuPrcVSleep();
    }
    func_80025C20(work->unk_4E, func_80025E48(work->unk_54), 0, 8, 2);
    work->unk_3C = 0;
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    work->unk_14 = -180.0f;
    work->unk_B4 = work->unk_B6 = work->unk_B8 = work->unk_BA = 0;
    work->unk_34 = 0.0f;
    func_800258EC(work->unk_70, 4, 0);
    for (i = 0; i < 8; i++) {
        func_80025798(work->unk_70, work->unk_0C + 71.0f, work->unk_10 - (50.0f - i / 8.0f * 50.0f),
                      work->unk_14 - 203.0f);
        HuPrcVSleep();
    }
}
void func_800FF68C_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 i;

    func_80060758(0x22C);
    if (func_80025E48(work->unk_4E) != func_80025E48(work->unk_52)) {
        func_80025C20(work->unk_4E, func_80025E48(work->unk_52), 0, 8, 2);
    }
    for (i = 0; i < 8; i++) {
        func_80025798(work->unk_70, work->unk_0C + 71.0f, work->unk_10 - i / 8.0f * 100.0f,
                      work->unk_14 - 203.0f);
        HuPrcVSleep();
    }
    pos.x = work->unk_00;
    pos.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 > -50.0f) {
        pos.x = work->unk_00 -= 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
        HuPrcVSleep();
    }
    func_800258EC(work->unk_4E, 4, 4);
    func_800258EC(work->unk_70, 4, 4);
}
void func_800FF884_MinigameInstructions(Ovl6FPlayerWork* work) {
    u16 prev;
    s16 moved;
    s32 port;

    port = GwPlayer[work->unk_38].port;
    moved = func_80009E4C(port, 14, ContStkX[port], ContStkY[port]);
    prev = work->unk_BC;
    if (moved != 0) {
        work->unk_BA = 0;
        work->unk_BC = (++work->unk_B4 >= 31) ? 4 : 2;
    } else {
        if (++work->unk_BA >= 31) {
            work->unk_BC = 0;
        }
        work->unk_B4 = 0;
    }
    if (work->unk_BC == 0) {
        func_80060758(0x22C);
    } else if (work->unk_BC < 3) {
        if (prev == 0) {
            work->unk_44 = func_800FA284_MinigameInstructions(0x22C);
        }
        func_800FA350_MinigameInstructions(work->unk_44, 200);
    } else {
        if (prev == 0) {
            work->unk_44 = func_800FA284_MinigameInstructions(0x22C);
        }
        func_800FA350_MinigameInstructions(work->unk_44, 600);
    }
    work->unk_34 = work->unk_BC + work->unk_34;
    if (work->unk_34 > 45.0f) {
        work->unk_34 -= 45.0f;
    }
    func_80025CA8(work->unk_4E, work->unk_34);
    func_80025CA8(work->unk_70, work->unk_34);
}
void func_800FFA08_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    u8 chr;

    chr = GwPlayer[work->unk_38].character;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9F, 0x29D);
    work->unk_50 = func_80023FC8(work->unk_4E);
    work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 3, 0x1D);
    work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x5E, 0x1D);
    work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x6D, 0x1D);
    work->unk_58 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x46, 0x1D);
    work->unk_08 = work->unk_38 * 35 + 25;
    func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
    pos.x = work->unk_00 = -50.0f;
    pos.y = work->unk_04 = 150.0f;
    out.z = -180.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
}
void func_800FFB88_MinigameInstructions(Ovl6FPlayerWork* work) {
    s32 motion;
    s16 port;

    port = GwPlayer[work->unk_38].port;
    if (ContBtnTrg[port] & 0x8000) {
        if ((s8)(ContStkX[port] / 10) < 0) {
            motion = work->unk_54;
        } else if ((s8)(ContStkX[port] / 10) > 0) {
            motion = work->unk_58;
        } else {
            motion = work->unk_56;
        }
        func_80025C20(work->unk_4E, func_80025E48(motion), 0, 4, 0);
        HuPrcSleep(4);
        func_800FB4DC_MinigameInstructions(work->unk_4E);
        func_80025C20(work->unk_4E, func_80025E48(work->unk_50), 0, 4, 2);
    }
}
void func_800FFCD0_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    void* buf;
    u8 chr;

    chr = GwPlayer[work->unk_38].character;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9F, 0x29D);
    work->unk_50 = func_80023FC8(work->unk_4E);
    work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x54, 0x1D);
    func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
    work->unk_70 = LoadFormFile(0x1F0000, 0x289);
    buf = DataRead(0x1F0008);
    work->unk_90 = func_80038A9C(D_800F2B7C[work->unk_70].unk_6C, buf, 0, "16mt000_DEF");
    func_80025AD4(work->unk_70);
    func_80025B34(work->unk_70);
    HuMemDirectFree(buf);
    func_80025830(work->unk_70, 0.4f, 0.4f, 0.4f);
    work->unk_08 = work->unk_38 * 30 + 40;
    pos.x = work->unk_00 = -50.0f;
    pos.y = work->unk_04 = 150.0f;
    work->unk_14 = -180.0f;
    func_8001DD24(0, CZoom - work->unk_14, (Vec3f*)&pos, &out);
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
    func_80025798(work->unk_70, out.x, out.y, work->unk_14 + 10.0f);
}
void func_800FFECC_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;

    func_800258EC(work->unk_4E, 4, 0);
    func_80025BB8(work->unk_4E, work->unk_52);
    func_80025EB4(work->unk_4E, 2, 2);
    func_800FA284_MinigameInstructions(0x234);
    pos.x = work->unk_00;
    pos.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 < work->unk_08) {
        pos.x = work->unk_00 += 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
        func_80025798(work->unk_70, out.x, out.y, work->unk_14 + 10.0f);
        HuPrcVSleep();
    }
    pos.x = work->unk_00 = work->unk_08;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
    func_80025798(work->unk_70, out.x, out.y, work->unk_14 + 10.0f);
    work->unk_3C = 0;
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    work->unk_14 = -180.0f;
    work->unk_20 = 0.0f;
    work->unk_24 = 90.0f;
    work->unk_28 = 0.0f;
    HuPrcSleep(8);
}
void func_80100090_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;

    pos.x = work->unk_00;
    pos.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 > -50.0f) {
        pos.x = work->unk_00 -= 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
        func_80025798(work->unk_70, out.x, out.y, work->unk_14 + 10.0f);
        HuPrcVSleep();
    }
    func_800258EC(work->unk_4E, 4, 4);
    HuPrcSleep(work->unk_38 * 8);
    func_80060758(0x234);
}
void func_801001B0_MinigameInstructions(Ovl6FPlayerWork* work) {
    if (work->unk_4C == 0) {
        work->unk_4C = 10;
    }
    work->unk_4C--;
}

void func_801001D0_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 chr;

    chr = GwPlayer[work->unk_38].character;
    if ((work->unk_3E = GwPlayer[work->unk_38].group) == 0) {
        work->unk_4E = LoadFormFile(0x220003, 0x299);
        work->unk_50 = LoadFormFile(0x220004, 0x1D);
        work->unk_52 = LoadFormFile(0x220005, 0x1D);
        work->unk_54 = LoadFormFile(0x220006, 0x1D);
        work->unk_56 = LoadFormFile(0x220007, 0x1D);
        work->unk_70 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9F, 0x299);
        func_80020EA0(work->unk_70, D_8010EE00_MinigameInstructions[chr][0], work->unk_4E,
                      (u8*)"21_kimoti_1b-atama_3");
        func_80025830(work->unk_4E, 0.28f, 0.28f, 0.28f);
        func_80025798(work->unk_70, -1000.0f, 0.0f, 0.0f);
        work->unk_08 = work->unk_38 * 30 + 40;
        pos.x = work->unk_00 = -50.0f;
        pos.y = work->unk_04 = 150.0f;
        work->unk_14 = -180.0f;
    } else {
        work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9F, 0x299);
        work->unk_50 = func_80023FC8(work->unk_4E);
        func_800258EC(work->unk_50, 4, 4);
        work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 3, 0x1D);
        work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 1, 0x1D);
        work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x41, 0x1D);
        work->unk_58 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x44, 0x1D);
        work->unk_70 = LoadFormFile(0x220002, 0x299);
        func_8002859C(work->unk_70, work->unk_4E, D_8010F268_MinigameInstructions);
        func_800258EC(work->unk_70, 0x4000, 0x4000);
        func_80025830(work->unk_4E, 0.28f, 0.28f, 0.28f);
        func_80028498(work->unk_4E, func_80025E48(work->unk_56), 2);
        work->unk_08 = work->unk_38 * 30 + 40;
        pos.x = work->unk_00 = -50.0f;
        pos.y = work->unk_04 = 150.0f;
        work->unk_14 = -180.0f;
    }
    func_8001DD24(0, CZoom - -180.0f, (Vec3f*)&pos, &out);
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
    func_800257E4(work->unk_4E, 0.0f, 0.0f, 0.0f);
    work->unk_B4 = 0;
}
void func_801004EC_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 i;

    func_800258EC(work->unk_4E, 4, 0);
    func_80025BB8(work->unk_4E, work->unk_52);
    func_80025EB4(work->unk_4E, 2, 2);
    func_800257E4(work->unk_4E, 0.0f, 90.0f, 0.0f);
    pos.x = work->unk_00;
    pos.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 < work->unk_08) {
        pos.x = work->unk_00 += 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_4E, out.x, out.y, -180.0f);
        if (work->unk_3E == 0) {
            if ((work->unk_42++ & 7) == 0) {
                func_800FA284_MinigameInstructions(0x24C);
            }
        } else {
            if ((work->unk_42++ & 3) == 0) {
                func_800FA300_MinigameInstructions(0x119, work);
            }
        }
        HuPrcVSleep();
    }
    pos.x = work->unk_00 = work->unk_08;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
    for (i = 90; i >= 0; i -= 30) {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        HuPrcVSleep();
        if (work->unk_3E == 0) {
            if ((work->unk_42++ & 7) == 0) {
                func_800FA284_MinigameInstructions(0x24C);
            }
        } else {
            if ((work->unk_42++ & 7) == 0) {
                func_800FA300_MinigameInstructions(0x112, work);
            }
        }
    }
    func_80025C20(work->unk_4E, func_80025E48(work->unk_50), 0, 8, 2);
    work->unk_3C = 0;
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    work->unk_14 = -180.0f;
    work->unk_20 = 0.0f;
    work->unk_24 = 90.0f;
    work->unk_28 = 0.0f;
    HuPrcSleep(8);
}
void func_8010078C_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 i;

    if (func_80025E48(work->unk_4E) != func_80025E48(work->unk_52)) {
        func_80025C20(work->unk_4E, func_80025E48(work->unk_52), 0, 8, 2);
    }
    HuPrcSleep(8);
    for (i = 0; i >= -90; i -= 30) {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        if (work->unk_3E == 0) {
            if ((work->unk_42++ & 7) == 0) {
                func_800FA284_MinigameInstructions(0x24C);
            }
        } else {
            if ((work->unk_42++ & 7) == 0) {
                func_800FA300_MinigameInstructions(0x119, work);
            }
        }
        HuPrcVSleep();
    }
    pos.x = work->unk_00;
    pos.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 > -50.0f) {
        pos.x = work->unk_00 -= 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_4E, out.x, out.y, -180.0f);
        if (work->unk_3E == 0) {
            if ((work->unk_42++ & 7) == 0) {
                func_800FA284_MinigameInstructions(0x24C);
            }
        } else {
            if ((work->unk_42++ & 3) == 0) {
                func_800FA300_MinigameInstructions(0x119, work);
            }
        }
        HuPrcVSleep();
    }
}
// the loop's 10.0f/100.0f are hoisted above the dead func_800AEAC0(0) call in retail, below it here (masked 8); tried a while loop after the call
#ifdef NON_MATCHING
void func_801009B4_MinigameInstructions(Ovl6FPlayerWork* work) {
    f32 x;
    f32 y;
    f32 mag;
    s16 motion;
    s16 port;
    u16 prev;

    if (work->unk_3E != 0) {
        func_80100CCC_MinigameInstructions(work);
    } else {
        port = GwPlayer[work->unk_38].port;
        x = (s8)(ContStkX[port] / 10);
        y = (s8)(ContStkY[port] / 10);
        mag = x * x + y * y;
        if (mag != 0.0f) {
            func_800257E4(work->unk_4E, 0.0f, func_800B0CD8(x, -y), 0.0f);
        }
        prev = work->unk_3C;
        if (work->unk_B4 != 0) {
            work->unk_B4--;
        }
        if ((ContBtnTrg[port] & 0x8000) && work->unk_B4 == 0) {
            func_800FA284_MinigameInstructions(0x251);
            work->unk_3C = 3;
            func_80025C20(work->unk_4E, func_80025E48(work->unk_54), 0, 8, 0);
            for (mag = 0.0f, func_800AEAC0(mag); mag < 180.0f;) {
                mag += 10.0f;
                if (mag > 180.0f) {
                    mag = 180.0f;
                }
                func_80025798(work->unk_4E, work->unk_0C, func_800AEAC0(mag) * 100.0f + work->unk_10,
                              work->unk_14);
                HuPrcVSleep();
            }
            func_80025C20(work->unk_4E, func_80025E48(work->unk_50), 0, 8, 2);
            work->unk_B4 = 30;
            mag = 0.0f;
        }
        if (mag == 0.0f) {
            work->unk_3C = 0;
            motion = func_80025E48(work->unk_50);
        } else {
            work->unk_3C = 1;
            motion = func_80025E48(work->unk_52);
            if ((work->unk_42++ & 7) == 0) {
                func_800FA284_MinigameInstructions(0x24C);
            }
        }
        if ((s16)prev != work->unk_3C) {
            func_80025C20(work->unk_4E, motion, 0, 8, 2);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_801009B4_MinigameInstructions);
#endif
void func_80100CCC_MinigameInstructions(Ovl6FPlayerWork* work) {
    f32 x;
    f32 y;
    f32 mag;
    s16 motion;
    u16 prev;
    s16 port;

    port = GwPlayer[work->unk_38].port;
    x = (s8)(ContStkX[port] / 10);
    y = (s8)(ContStkY[port] / 10);
    mag = x * x + y * y;
    motion = 0;
    if (mag != 0.0f) {
        func_800257E4(work->unk_4E, 0.0f, func_800B0CD8(x, -y), 0.0f);
    }
    prev = work->unk_3C;
    if (ContBtnTrg[port] & 0x8000) {
        func_80028498(work->unk_4E, func_80025E48(work->unk_58), 0);
        HuPrcSleep(18);
        func_800FA284_MinigameInstructions(0x24D);
        do {
            HuPrcVSleep();
        } while (!(func_80025DD8(work->unk_4E) <= func_80025D90(work->unk_4E)));
        func_80028498(work->unk_4E, func_80025E48(work->unk_56), 2);
    }
    if (mag == 0.0f) {
        work->unk_3C = 0;
        motion = func_80025E48(work->unk_50);
    } else if (mag <= 16.0f) {
        work->unk_3C = 1;
        motion = func_80025E48(work->unk_54);
        func_800FB590_MinigameInstructions(work, motion);
    } else if (mag > 16.0f) {
        work->unk_3C = 2;
        motion = func_80025E48(work->unk_52);
        func_800FB60C_MinigameInstructions(work, motion);
    }
    if ((s16)prev != work->unk_3C) {
        func_80025C20(work->unk_4E, motion, 0, 8, 2);
    }
}
void func_80100F6C_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s32 pad[2]; /* unused: retail frame is 8 bytes larger */
    s16 chr;

    chr = GwPlayer[work->unk_38].character;
    work->unk_3E = GwPlayer[work->unk_38].group;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9F, 0x29D);
    work->unk_50 = func_80023FC8(work->unk_4E);
    work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 3, 0x1D);
    work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x5C, 0x1D);
    work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x5D, 0x1D);
    work->unk_70 = LoadFormFile(D_8010EE60_MinigameInstructions[chr][0], 0x29D);
    func_80101188_MinigameInstructions(work->unk_70, work->unk_4E, D_8010EE48_MinigameInstructions[chr][0]);
    work->unk_72 = LoadFormFile(D_8010EE60_MinigameInstructions[chr][1], 0x29D);
    func_80101188_MinigameInstructions(work->unk_72, work->unk_4E, D_8010EE48_MinigameInstructions[chr][1]);
    func_80025830(work->unk_4E, 0.28f, 0.28f, 0.28f);
    work->unk_08 = work->unk_38 * 30 + 40;
    pos.x = work->unk_00 = -50.0f;
    pos.y = work->unk_04 = 150.0f;
    work->unk_14 = -180.0f;
    func_8001DD24(0, CZoom - work->unk_14, (Vec3f*)&pos, &out);
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
    func_800257E4(work->unk_4E, 0.0f, 0.0f, 0.0f);
    work->unk_B4 = 0;
}
void func_80101188_MinigameInstructions(s16 model0, s16 model1, u16 arg2) {
    unk2C0C0StructC0* src;
    unk2C0C0StructC0* dst;
    unk2C0C0Struct40* ent;
    unk2C0C0Struct50* grp;
    u16 i;
    u16 j;

    src = D_800F2B7C[model0].unk_6C;
    dst = D_800F2B7C[model1].unk_6C;
    if (arg2 < src->unk_6A && arg2 < dst->unk_6A) {
        if (dst->unk_A0 == (unk2C0C0Struct50*)-1) {
            for (j = 0; j < src->unk_84; j++) {
                ent = &dst->unk_88[j];
                if (ent->unk_00 == arg2) {
                    ent->unk_48 = dst;
                    ent->unk_00 = arg2;
                    break;
                }
            }
        } else {
            for (i = 0; i < dst->unk_70; i++) {
                grp = &dst->unk_A0[i];
                for (j = 0; j < grp->unk_00; j++) {
                    if (grp->unk_04[j] == arg2) {
                        grp->unk_60 = src;
                        grp->unk_04[j] = arg2;
                        break;
                    }
                }
            }
        }
    }
}
void func_80101304_MinigameInstructions(Ovl6FPlayerWork* work) {
    u8 port;

    if (work->unk_B2 == 0) {
        func_80025C20(work->unk_4E, func_80025E48(work->unk_54), 0, 4, 1);
    }
    port = GwPlayer[work->unk_38].port;
    if (ContBtnTrg[port] & 0x4000) {
        func_800FA284_MinigameInstructions(0x2F9);
        func_80025EB4(work->unk_4E, 1, 0);
        func_80025C20(work->unk_4E, func_80025E48(work->unk_54), 0, 8, 0);
        func_800FB4DC_MinigameInstructions(work->unk_4E);
        HuPrcSleep(10);
        func_80025EB4(work->unk_4E, 4, 4);
        func_800FB4DC_MinigameInstructions(work->unk_4E);
    } else if (ContBtnTrg[port] & 0x8000) {
        func_800FA284_MinigameInstructions(0x2FA);
        func_80025EB4(work->unk_4E, 1, 0);
        func_80025C20(work->unk_4E, func_80025E48(work->unk_56), 0, 8, 0);
        func_800FB4DC_MinigameInstructions(work->unk_4E);
        HuPrcSleep(10);
        func_80025EB4(work->unk_4E, 4, 4);
        func_800FB4DC_MinigameInstructions(work->unk_4E);
    }
}
void func_8010143C_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    u8 chr;

    chr = GwPlayer[work->unk_38].character;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9F, 0x29D);
    work->unk_50 = func_80023FC8(work->unk_4E);
    work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 3, 0x1D);
    work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9A, 0x1D);
    work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9B, 0x1D);
    work->unk_58 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9C, 0x1D);
    work->unk_5A = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x31, 0x1D);
    work->unk_5C = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x30, 0x1D);
    func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
    work->unk_70 = LoadFormFile(0x3F0003, 0x289);
    func_80025798(work->unk_70, -10000.0f, 0.0f, 0.0f);
    func_8002859C(work->unk_70, work->unk_4E, D_8010F268_MinigameInstructions);
    func_80025830(work->unk_70, 0.4f, 0.4f, 0.4f);
    work->unk_08 = work->unk_38 * 30 + 40;
    pos.x = work->unk_00 = -50.0f;
    pos.y = work->unk_04 = 150.0f;
    work->unk_14 = -180.0f;
    func_8001DD24(0, CZoom - work->unk_14, (Vec3f*)&pos, &out);
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
}
void func_8010165C_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 i;

    func_800258EC(work->unk_4E, 4, 0);
    func_800258EC(work->unk_70, 0x4000, 0x4000);
    func_80025BB8(work->unk_4E, work->unk_52);
    func_80025EB4(work->unk_4E, 2, 2);
    func_800257E4(work->unk_4E, 0.0f, 90.0f, 0.0f);
    pos.x = work->unk_00;
    pos.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 < work->unk_08) {
        pos.x = work->unk_00 += 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_4E, out.x, out.y, -180.0f);
        if ((work->unk_42++ & 3) == 0) {
            func_800FA300_MinigameInstructions(0x119, work);
        }
        HuPrcVSleep();
    }
    pos.x = work->unk_00 = work->unk_08;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
    for (i = 90; i >= 0; i -= 30) {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        if ((work->unk_42++ & 7) == 0) {
            func_800FA300_MinigameInstructions(0x112, work);
        }
        HuPrcVSleep();
    }
    func_80025C20(work->unk_4E, func_80025E48(work->unk_5A), 0, 8, 1);
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    work->unk_14 = -180.0f;
    work->unk_20 = 0.0f;
    work->unk_24 = 90.0f;
    work->unk_28 = 0.0f;
    HuPrcSleep(8);
    work->unk_B6 = 2;
    work->unk_B8 = 0;
    work->unk_BA = 0;
    work->unk_BC = 0;
}
void func_801018BC_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 i;

    func_80060758(0x312);
    if (func_80025E48(work->unk_4E) != func_80025E48(work->unk_52)) {
        func_80025C20(work->unk_4E, func_80025E48(work->unk_52), 0, 8, 2);
    }
    HuPrcSleep(8);
    for (i = 0; i >= -90; i -= 30) {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        if ((work->unk_42++ & 7) == 0) {
            func_800FA300_MinigameInstructions(0x112, work);
        }
        HuPrcVSleep();
    }
    pos.x = work->unk_00;
    pos.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 > -50.0f) {
        pos.x = work->unk_00 -= 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_4E, out.x, out.y, -180.0f);
        if ((work->unk_42++ & 3) == 0) {
            func_800FA300_MinigameInstructions(0x119, work);
        }
        HuPrcVSleep();
    }
}
void func_80101A90_MinigameInstructions(Ovl6FPlayerWork* work) {
    f32 x;
    f32 y;
    f32 angle;
    f32 prev;
    s16 moved;
    s16 mag;
    s16 frame;
    s16 port;
    s32 next;
    s32 bc;

    port = GwPlayer[work->unk_38].port;
    x = (s8)(ContStkX[port] / 10);
    y = (s8)(ContStkY[port] / 10);
    if (func_800B1750(x * x + y * y) == 0.0f) {
        if (work->unk_44 != -1) {
            func_800FA380_MinigameInstructions(work->unk_44);
        }
        work->unk_44 = -1;
        if (work->unk_B6 == 1) {
            if (work->unk_BC >= 57) {
                func_800FA284_MinigameInstructions(0x30F);
                func_80025BB8(work->unk_4E, work->unk_54);
            } else if (work->unk_BC >= 34) {
                func_800FA284_MinigameInstructions(0x310);
                func_80025BB8(work->unk_4E, work->unk_56);
            } else {
                func_800FA284_MinigameInstructions(0x311);
                func_80025BB8(work->unk_4E, work->unk_58);
            }
            func_80025CA8(work->unk_4E, 0.0f);
            func_80025EB4(work->unk_4E, 3, 0);
            func_800FB4DC_MinigameInstructions(work->unk_4E);
            func_80025BB8(work->unk_4E, work->unk_5A);
            func_80025EB4(work->unk_4E, 1, 1);
            work->unk_B6 = 2;
            work->unk_B4 = 0;
        }
        work->unk_B8 = 0;
        work->unk_BA = 10000;
        work->unk_BC = 0;
        return;
    }
    angle = func_800B0CD8(x, -y);
    moved = func_80009E4C(port, 16, ContStkX[port], ContStkY[port]);
    if (angle < 0.0f) {
        angle += 360.0f;
    }
    prev = work->unk_BA;
    work->unk_BA = angle;
    if (angle < 5.0f) {
        if (prev > 355.0f) {
            prev -= 360.0f;
        }
    } else if (angle > 355.0f) {
        if (prev < 5.0f) {
            prev += 360.0f;
        }
    }
    prev -= angle;
    if ((moved != 0) & (func_800B1750(prev * prev) > 5.0f)) {
        if (work->unk_B4 == 0) {
            func_80025BB8(work->unk_4E, work->unk_5A);
            work->unk_44 = func_800FA284_MinigameInstructions(0x312);
        }
        func_80025CA8(work->unk_4E, work->unk_B4);
        work->unk_B4 += 2;
        if (func_80025D40(work->unk_4E) <= work->unk_B4) {
            work->unk_B4 = 0;
        }
        work->unk_B6 = 0;
        work->unk_B8 = 0;
        work->unk_BC = 0;
        return;
    }
    if (work->unk_44 != -1) {
        func_800FA380_MinigameInstructions(work->unk_44);
    }
    work->unk_44 = -1;
    x = ContStkX[port];
    y = ContStkY[port];
    mag = func_800B1750(x * x + y * y);
    if (work->unk_BC != mag) {
        if (((mag - work->unk_BC < 0) ? -(mag - work->unk_BC) : (mag - work->unk_BC)) == 1) {
            bc = work->unk_BC;
            if (mag - bc < 0) {
                next = bc - 1;
            } else {
                next = bc + 1;
            }
        } else {
            bc = work->unk_BC;
            if (mag - bc < 0) {
                next = bc - 2;
            } else {
                next = bc + 2;
            }
        }
        work->unk_BC = next;
    }
    if (work->unk_B8 >= 6) {
        frame = work->unk_BC / 80.0f * 30.0f;
        func_80025BB8(work->unk_4E, work->unk_5C);
        if (func_80025D40(work->unk_4E) <= frame) {
            frame = 30;
        }
        func_80025CA8(work->unk_4E, frame);
    } else {
        work->unk_B4 = 0;
    }
    work->unk_B6 = 1;
    work->unk_B8++;
}
// retail rematerialises the -180.0f for CZoom - unk_14 after func_80025830; here unk_14 is reloaded (masked 2)
#ifdef NON_MATCHING
void func_80102048_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 chr;

    chr = GwPlayer[work->unk_38].character;
    work->unk_3E = GwPlayer[work->unk_38].group;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9F, 0x299);
    work->unk_50 = func_80023FC8(work->unk_4E);
    func_800258EC(work->unk_50, 4, 4);
    work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 3, 0x1D);
    work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 1, 0x1D);
    if (work->unk_3E == 0) {
        work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x41, 0x1D);
        work->unk_58 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x44, 0x1D);
        work->unk_5A = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x45, 0x1D);
        work->unk_70 = LoadFormFile(0x270001, 0x299);
        func_8002859C(work->unk_70, work->unk_4E, D_8010F268_MinigameInstructions);
        func_800258EC(work->unk_70, 0x4000, 0x4000);
        func_80028498(work->unk_4E, func_80025E48(work->unk_56), 2);
    } else {
        work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 5, 0x1D);
        work->unk_58 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 9, 0x1D);
        work->unk_5A = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x1C, 0x1D);
        work->unk_5C = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 4, 0x1D);
        work->unk_5E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 6, 0x1D);
    }
    work->unk_08 = work->unk_38 * 30 + 40;
    pos.x = work->unk_00 = -50.0f;
    pos.y = work->unk_04 = 150.0f;
    work->unk_14 = -180.0f;
    func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
    func_8001DD24(0, CZoom - work->unk_14, (Vec3f*)&pos, &out);
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
    func_800257E4(work->unk_4E, 0.0f, 0.0f, 0.0f);
    work->unk_B4 = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2DF200", func_80102048_MinigameInstructions);
#endif
void func_80102334_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 i;

    if (func_80025E48(work->unk_4E) != func_80025E48(work->unk_52)) {
        func_80025C20(work->unk_4E, func_80025E48(work->unk_52), 0, 8, 2);
    }
    HuPrcSleep(8);
    for (i = 0; i >= -90; i -= 30) {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        if ((work->unk_42++ & 7) == 0) {
            func_800FA300_MinigameInstructions(0x112, work);
        }
        HuPrcVSleep();
    }
    pos.x = work->unk_00;
    pos.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 > -50.0f) {
        pos.x = work->unk_00 -= 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_4E, out.x, out.y, -180.0f);
        if ((work->unk_42++ & 3) == 0) {
            func_800FA300_MinigameInstructions(0x119, work);
        }
        HuPrcVSleep();
    }
}

void func_801024FC_MinigameInstructions(Ovl6FPlayerWork* work) {
    f32 x;
    f32 y;
    f32 mag;
    s16 motion;
    s16 prev;
    s16 port;
    u16* btn;

    motion = 0;
    if (work->unk_3E != 0) {
        func_800FADF4_MinigameInstructions(work);
        return;
    }
    port = GwPlayer[work->unk_38].port;
    x = (s8)(ContStkX[port] / 10);
    y = (s8)(ContStkY[port] / 10);
    mag = (x * x) + (y * y);
    if (mag != 0.0f) {
        func_800257E4(work->unk_4E, 0.0f, func_800B0CD8(x, -y), 0.0f);
    }
    prev = work->unk_3C;
    if (ContBtnTrg[port] & 0xC000) {
        func_800FA284_MinigameInstructions(0x272);
        func_80028498(work->unk_4E, func_80025E48((ContBtnTrg[port] & 0x8000) ? work->unk_58 : work->unk_5A), 0);
        while (1) {
            HuPrcVSleep();
            if (func_80025DD8(work->unk_4E) <= func_80025D90(work->unk_4E)) {
                break;
            }
        }
        func_80028498(work->unk_4E, func_80025E48(work->unk_56), 2);
    }
    if (mag == 0.0f) {
        work->unk_3C = 0;
        motion = func_80025E48(work->unk_50);
    } else if (mag <= 16.0f) {
        work->unk_3C = 1;
        motion = func_80025E48(work->unk_54);
        func_800FB60C_MinigameInstructions(work, motion);
    } else if (16.0f < mag) {
        work->unk_3C = 2;
        motion = func_80025E48(work->unk_52);
        func_800FB590_MinigameInstructions(work, motion);
    }
    if (prev != work->unk_3C) {
        func_80025C20(work->unk_4E, motion, 0, 8, 2);
    }
}
void func_801027CC_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    u8 chr;

    chr = GwPlayer[work->unk_38].character;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9F, 0x299);
    work->unk_50 = func_80023FC8(work->unk_4E);
    func_800258EC(work->unk_50, 4, 4);
    work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 3, 0x1D);
    work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 1, 0x1D);
    work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 5, 0x1D);
    work->unk_58 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 9, 0x1D);
    work->unk_5C = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 4, 0x1D);
    work->unk_70 = LoadFormFile(D_8010EE90_MinigameInstructions[chr], 0x299);
    func_8002859C(work->unk_70, work->unk_4E, D_8010EEA8_MinigameInstructions[chr]);
    func_800258EC(work->unk_70, 0x4000, 0x4000);
    work->unk_08 = (work->unk_38 * 0x23) + 0x19;
    func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
    pos.x = work->unk_00 = -50.0f;
    pos.y = work->unk_04 = 150.0f;
    out.z = 0.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
}
void func_801029BC_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    u8 chr;

    chr = GwPlayer[work->unk_38].character;
    if ((work->unk_3E = GwPlayer[work->unk_38].group) == 0) {
        work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9F, 0x29D);
        work->unk_50 = func_80023FC8(work->unk_4E);
        func_800258EC(work->unk_50, 4, 4);
        work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x57, 0x1D);
        work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x58, 0x1D);
        work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x59, 0x1D);
        work->unk_70 = LoadFormFile(0x360001, 0x29D);
        func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
        func_80025830(work->unk_70, 0.16000001f, 0.16000001f, 0.16000001f);
        pos.x = work->unk_00 = (work->unk_38 * 0x23) + 0x19;
        pos.y = work->unk_04 = 130.0f;
        out.z = 0.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_4E, out.x, out.y, -180.0f);
        func_800257E4(work->unk_4E, 0.0f, 45.0f, 0.0f);
        pos.x = work->unk_2C = work->unk_00;
        pos.y = work->unk_30 = work->unk_04 - 190.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_70, out.x, out.y, -180.0f);
        func_800257E4(work->unk_70, 0.0f, 45.0f, 0.0f);
        return;
    }
    work->unk_4E = LoadFormFile(D_8010EEC0_MinigameInstructions[chr], 0x29D);
    func_80025830(work->unk_4E, 0.16000001f, 0.16000001f, 0.16000001f);
    pos.x = work->unk_00 = (work->unk_38 * 0x23) + 0x19;
    pos.y = work->unk_04 = 130.0f;
    out.z = 0.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
    func_80025EB4(work->unk_4E, 2, 2);
}
void func_80102C9C_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 i;

    func_800258EC(work->unk_4E, 4, 0);
    if (work->unk_3E == 0) {
        func_800258EC(work->unk_70, 4, 0);
        func_80025BB8(work->unk_4E, work->unk_52);
        func_80025EB4(work->unk_4E, 2, 2);
        func_800FA284_MinigameInstructions(0x2CB);
        pos.x = work->unk_00;
        for (i = -20; i < 141; i += 20) {
            pos.y = i;
            func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
            func_80025798(work->unk_4E, out.x, out.y, -180.0f);
            pos.y -= 190.0f;
            func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
            func_80025798(work->unk_70, out.x, out.y, -180.0f);
            HuPrcVSleep();
        }
        pos.y = 130.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_4E, out.x, out.y, -180.0f);
        pos.y -= 190.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_70, out.x, out.y, -180.0f);
        func_80060758(0x2CB);
        func_800FA284_MinigameInstructions(0x2CC);
        return;
    }
    func_80025830(work->unk_4E, 0.16000001f, 0.16000001f, 0.16000001f);
    pos.x = work->unk_00;
    for (i = 0; i < 91; i += 10) {
        pos.y = 130.0f - func_800AEFD0(i) * 130.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_4E, out.x, out.y, -180.0f);
        HuPrcVSleep();
    }
    for (i = 0; i < 181; i += 30) {
        pos.y = 130.0f - func_800AEAC0(i) * 20.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_4E, out.x, out.y, -180.0f);
        HuPrcVSleep();
    }
    func_80025EB4(work->unk_4E, 1, 1);
}
void func_80102FC4_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    f32 s;
    s16 i;

    if (work->unk_3E == 0) {
        func_80060758(0x2CB);
        func_800FA284_MinigameInstructions(0x2CB);
        pos.x = work->unk_00;
        for (i = 130; i >= -20; i -= 20) {
            pos.y = i;
            func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
            func_80025798(work->unk_4E, out.x, out.y, -180.0f);
            pos.y -= 190.0f;
            func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
            func_80025798(work->unk_70, out.x, out.y, -180.0f);
            HuPrcVSleep();
        }
        func_80060758(0x2CB);
        func_800258EC(work->unk_70, 4, 4);
    } else {
        for (s = 1.0f; s >= 0.0f; s -= 0.1f) {
            func_80025830(work->unk_4E, s * 0.16000001f, ((1.0f - s) * 0.8f + 1.0f) * 0.16000001f, s * 0.16000001f);
            HuPrcVSleep();
        }
    }
    func_800258EC(work->unk_4E, 4, 4);
}
void func_801031BC_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    f32 t;
    s16 i;
    u8 port;

    port = GwPlayer[work->unk_38].port;
    if (work->unk_3E == 0) {
        if (ContBtnTrg[port] & 0x8000) {
            func_800FA284_MinigameInstructions(0x2CB);
            pos.x = work->unk_00;
            func_80025BB8(work->unk_4E, work->unk_54);
            for (i = work->unk_04; i < work->unk_04 + 30.0f; i += 2) {
                pos.y = i;
                func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
                func_80025798(work->unk_4E, out.x, out.y, -180.0f);
                pos.y -= 190.0f;
                func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
                func_80025798(work->unk_70, out.x, out.y, -180.0f);
                HuPrcVSleep();
            }
            func_80060758(0x2CB);
            HuPrcSleep(30);
            func_800FA284_MinigameInstructions(0x2CC);
            func_80025BB8(work->unk_4E, work->unk_52);
            func_80025EB4(work->unk_4E, 2, 2);
            for (i = work->unk_04 + 30.0f; work->unk_04 <= i; i -= 5) {
                pos.y = i;
                func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
                func_80025798(work->unk_4E, out.x, out.y, -180.0f);
                pos.y -= 190.0f;
                func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
                func_80025798(work->unk_70, out.x, out.y, -180.0f);
                HuPrcVSleep();
            }
            func_80060758(0x2CC);
        }
    } else if (ContBtnTrg[port] & 0x8000) {
        func_80025EB4(work->unk_4E, 1, 0);
        func_80025CA8(work->unk_4E, 0.0f);
        while (1) {
            HuPrcVSleep();
            t = func_80025D18(work->unk_4E) + 4.0f;
            if (func_80025D40(work->unk_4E) <= t) {
                break;
            }
        }
        func_80025EB4(work->unk_4E, 1, 1);
    }
}
const char D_8010F2E0_MinigameInstructions[] __attribute__((section(".rodata"))) = "c005_000-cyl1_1_3";

const char D_8010F2F4_MinigameInstructions[] __attribute__((section(".rodata"))) = "Luigi1-karada_2_1_1";

const char D_8010F308_MinigameInstructions[] __attribute__((section(".rodata"))) = "c003_000-yoshi_body_2";

const char D_8010F320_MinigameInstructions[] __attribute__((section(".rodata"))) = "C002_000b-cone7_1_1_1_1";

const char D_8010F338_MinigameInstructions[] __attribute__((section(".rodata"))) = "Luigi1-karada_1_2_1";

const char D_8010F34C_MinigameInstructions[] __attribute__((section(".rodata"))) = "karada_2_1_1_1";
const char D_8010F35C_MinigameInstructions[] __attribute__((section(".rodata"))) = "";


/* .data */
unk1EA70Struct1C* D_8010E960_MinigameInstructions = NULL;
s16 D_8010E964_MinigameInstructions[6] = { 1, 2, 6, 3, 4, 5 };
Ovl6FMinigameFuncs D_8010E970_MinigameInstructions[56] = {
    { { func_800FA7F8_MinigameInstructions, func_800FA9EC_MinigameInstructions, func_800FADF4_MinigameInstructions, func_800FAC2C_MinigameInstructions }, 0xF },
    { { func_800FA7F8_MinigameInstructions, func_800FA9EC_MinigameInstructions, func_800FADF4_MinigameInstructions, func_800FAC2C_MinigameInstructions }, 7 },
    { { func_800FA7F8_MinigameInstructions, func_800FA9EC_MinigameInstructions, func_800FADF4_MinigameInstructions, func_800FAC2C_MinigameInstructions }, 7 },
    { { func_800FB688_MinigameInstructions, func_800FB7D8_MinigameInstructions, func_800FBBA8_MinigameInstructions, func_800FBA14_MinigameInstructions }, 0xFFFFFFFF },
    { { func_800FC008_MinigameInstructions, func_800FC190_MinigameInstructions, func_800FC558_MinigameInstructions, func_800FC3B0_MinigameInstructions }, 0xFFFFFFFF },
    { { func_800FA7F8_MinigameInstructions, func_800FA9EC_MinigameInstructions, func_800FADF4_MinigameInstructions, func_800FAC2C_MinigameInstructions }, 0x3F },
    { { func_80105984_MinigameInstructions, func_80105B24_MinigameInstructions, func_80105E64_MinigameInstructions, func_80105D08_MinigameInstructions }, 0xFFFFFFFF },
    { { func_800FFA08_MinigameInstructions, func_800FA9EC_MinigameInstructions, func_800FFB88_MinigameInstructions, func_800FAC2C_MinigameInstructions }, 0xFFFFFFFF },
    { { func_80105984_MinigameInstructions, func_80105B24_MinigameInstructions, func_80105E64_MinigameInstructions, func_80105D08_MinigameInstructions }, 0xFFFFFFFF },
    { { func_80109BFC_MinigameInstructions, func_80109DB0_MinigameInstructions, func_8010A0D4_MinigameInstructions, func_80109F68_MinigameInstructions }, 0xFFFFFFFF },
    { { func_800FA7F8_MinigameInstructions, func_800FA9EC_MinigameInstructions, func_800FADF4_MinigameInstructions, func_800FAC2C_MinigameInstructions }, 0x3F },
    { { func_800FA7F8_MinigameInstructions, func_800FA9EC_MinigameInstructions, func_800FADF4_MinigameInstructions, func_800FAC2C_MinigameInstructions }, 0x1F },
    { { func_800FF23C_MinigameInstructions, func_800FF3CC_MinigameInstructions, func_800FF884_MinigameInstructions, func_800FF68C_MinigameInstructions }, 0xFFFFFFFF },
    { { func_800FFCD0_MinigameInstructions, func_800FFECC_MinigameInstructions, func_801001B0_MinigameInstructions, func_80100090_MinigameInstructions }, 0xFFFFFFFF },
    { { func_800FC9F8_MinigameInstructions, func_800FCB50_MinigameInstructions, func_800FCD20_MinigameInstructions, func_800FCC54_MinigameInstructions }, 0xFFFFFFFF },
    { { func_800FA7F8_MinigameInstructions, func_800FA9EC_MinigameInstructions, func_800FADF4_MinigameInstructions, func_800FAC2C_MinigameInstructions }, 7 },
    { { func_801001D0_MinigameInstructions, func_801004EC_MinigameInstructions, func_801009B4_MinigameInstructions, func_8010078C_MinigameInstructions }, 5 },
    { { func_800FD954_MinigameInstructions, func_800FDBF8_MinigameInstructions, func_800FE0E8_MinigameInstructions, func_800FDEA4_MinigameInstructions }, 0xFFFFFFFF },
    { { func_800FA7F8_MinigameInstructions, func_800FA9EC_MinigameInstructions, func_800FADF4_MinigameInstructions, func_800FAC2C_MinigameInstructions }, 0xF },
    { { func_800FCED0_MinigameInstructions, func_800FD130_MinigameInstructions, func_800FD674_MinigameInstructions, func_800FD408_MinigameInstructions }, 0xFFFFFFFF },
    { { func_800FA7F8_MinigameInstructions, func_800FA9EC_MinigameInstructions, func_800FADF4_MinigameInstructions, func_800FAC2C_MinigameInstructions }, 7 },
    { { func_80102048_MinigameInstructions, func_800FA9EC_MinigameInstructions, func_801024FC_MinigameInstructions, func_80102334_MinigameInstructions }, 0x17 },
    { { func_801064A4_MinigameInstructions, func_801066C4_MinigameInstructions, func_80106B2C_MinigameInstructions, func_80106948_MinigameInstructions }, 0xFFFFFFFF },
    { { func_800FA7F8_MinigameInstructions, func_800FA9EC_MinigameInstructions, func_800FADF4_MinigameInstructions, func_800FAC2C_MinigameInstructions }, 0x3F },
    { { func_800FA7F8_MinigameInstructions, func_800FA9EC_MinigameInstructions, func_800FADF4_MinigameInstructions, func_800FAC2C_MinigameInstructions }, 7 },
    { { func_800FA7F8_MinigameInstructions, func_800FA9EC_MinigameInstructions, func_800FADF4_MinigameInstructions, func_800FAC2C_MinigameInstructions }, 7 },
    { { func_800FA7F8_MinigameInstructions, func_800FA9EC_MinigameInstructions, func_800FADF4_MinigameInstructions, func_800FAC2C_MinigameInstructions }, 0xF },
    { { func_800FE924_MinigameInstructions, func_800FEB5C_MinigameInstructions, func_800FF010_MinigameInstructions, func_800FEE08_MinigameInstructions }, 0xFFFFFFFF },
    { { func_801027CC_MinigameInstructions, func_800FA9EC_MinigameInstructions, func_800FADF4_MinigameInstructions, func_800FAC2C_MinigameInstructions }, 0x17 },
    { { func_80108624_MinigameInstructions, func_80108A90_MinigameInstructions, func_80109600_MinigameInstructions, func_80108FE4_MinigameInstructions }, 0xFFFFFFFF },
    { { func_800FE924_MinigameInstructions, func_800FEB5C_MinigameInstructions, func_800FF010_MinigameInstructions, func_800FEE08_MinigameInstructions }, 0xFFFFFFFF },
    { { func_801040AC_MinigameInstructions, func_80104320_MinigameInstructions, func_80104988_MinigameInstructions, func_80104688_MinigameInstructions }, 0xFFFFFFFF },
    { { func_800FA7F8_MinigameInstructions, func_800FA9EC_MinigameInstructions, func_800FADF4_MinigameInstructions, func_800FAC2C_MinigameInstructions }, 0x57 },
    { { func_800FA7F8_MinigameInstructions, func_800FA9EC_MinigameInstructions, func_800FADF4_MinigameInstructions, func_800FAC2C_MinigameInstructions }, 7 },
    { { func_800FA7F8_MinigameInstructions, func_800FA9EC_MinigameInstructions, func_800FADF4_MinigameInstructions, func_800FAC2C_MinigameInstructions }, 7 },
    { { func_801029BC_MinigameInstructions, func_80102C9C_MinigameInstructions, func_801031BC_MinigameInstructions, func_80102FC4_MinigameInstructions }, 0xFFFFFFFF },
    { { func_800FE924_MinigameInstructions, func_800FEB5C_MinigameInstructions, func_800FF010_MinigameInstructions, func_800FEE08_MinigameInstructions }, 0xFFFFFFFF },
    { { func_80105984_MinigameInstructions, func_80105B24_MinigameInstructions, func_80105E64_MinigameInstructions, func_80105D08_MinigameInstructions }, 0xFFFFFFFF },
    { { func_8010AEA0_MinigameInstructions, func_8010B44C_MinigameInstructions, func_8010BB04_MinigameInstructions, func_8010B7EC_MinigameInstructions }, 0xFFFFFFFF },
    { { func_8010A43C_MinigameInstructions, func_800FA9EC_MinigameInstructions, func_8010A5D4_MinigameInstructions, func_800FAC2C_MinigameInstructions }, 0xFFFFFFFF },
    { { func_80100F6C_MinigameInstructions, func_800FA9EC_MinigameInstructions, func_80101304_MinigameInstructions, func_800FAC2C_MinigameInstructions }, 0xFFFFFFFF },
    { { func_80107F4C_MinigameInstructions, func_801080E4_MinigameInstructions, func_801083DC_MinigameInstructions, func_80108280_MinigameInstructions }, 0xFFFFFFFF },
    { { func_80107088_MinigameInstructions, func_8010732C_MinigameInstructions, func_801077C8_MinigameInstructions, func_801075B8_MinigameInstructions }, 0x17 },
    { { func_8010143C_MinigameInstructions, func_8010165C_MinigameInstructions, func_80101A90_MinigameInstructions, func_801018BC_MinigameInstructions }, 0xFFFFFFFF },
    { { func_80103560_MinigameInstructions, func_800FA9EC_MinigameInstructions, func_80103788_MinigameInstructions, func_800FAC2C_MinigameInstructions }, 7 },
    { { func_80103E48_MinigameInstructions, func_800FA9EC_MinigameInstructions, func_800FADF4_MinigameInstructions, func_800FAC2C_MinigameInstructions }, 0x37 },
    { { func_800FA7F8_MinigameInstructions, func_800FA9EC_MinigameInstructions, func_800FADF4_MinigameInstructions, func_800FAC2C_MinigameInstructions }, 4 },
    { { func_8010BF20_MinigameInstructions, func_8010C3A4_MinigameInstructions, func_8010CC54_MinigameInstructions, func_8010C8CC_MinigameInstructions }, 0xFFFFFFFF },
    { { func_800FA7F8_MinigameInstructions, func_800FA9EC_MinigameInstructions, func_800FADF4_MinigameInstructions, func_800FAC2C_MinigameInstructions }, 0xFFFFFFFF },
    { { func_8010A75C_MinigameInstructions, func_8010A938_MinigameInstructions, func_8010AD60_MinigameInstructions, func_8010ABA4_MinigameInstructions }, 0xFFFFFFFF },
    { { func_80106F90_MinigameInstructions, func_80106FE0_MinigameInstructions, func_80107050_MinigameInstructions, func_80107018_MinigameInstructions }, 0xF },
    { { func_801060DC_MinigameInstructions, func_801004EC_MinigameInstructions, func_80106358_MinigameInstructions, func_8010078C_MinigameInstructions }, 0xFFFFFFFF },
    { { func_8010D200_MinigameInstructions, func_8010D5E4_MinigameInstructions, func_8010DF34_MinigameInstructions, func_8010DB24_MinigameInstructions }, 0xFFFFFFFF },
    { { func_800FE924_MinigameInstructions, func_800FEB5C_MinigameInstructions, func_800FF010_MinigameInstructions, func_800FEE08_MinigameInstructions }, 0xFFFFFFFF },
    { { func_80104DF0_MinigameInstructions, func_80105148_MinigameInstructions, func_8010574C_MinigameInstructions, func_80105464_MinigameInstructions }, 7 },
    { { func_800FA7F8_MinigameInstructions, func_800FA9EC_MinigameInstructions, func_800FADF4_MinigameInstructions, func_800FAC2C_MinigameInstructions }, 0xF },
};
s32 D_8010EDD0_MinigameInstructions[6] = { 0x200005, 0x200006, 0x200007, 0x200008, 0x200009, 0x20000A };
s32 D_8010EDE8_MinigameInstructions[6] = { 0x230009, 0x23000A, 0x23000B, 0x23000C, 0x23000D, 0x23000E };
u8* D_8010EE00_MinigameInstructions[6][2] = { { (u8*)D_8010F260_MinigameInstructions, (u8*)D_8010F24C_MinigameInstructions }, { (u8*)D_8010F23C_MinigameInstructions, (u8*)D_8010F228_MinigameInstructions }, { (u8*)D_8010F210_MinigameInstructions, (u8*)D_8010F1FC_MinigameInstructions }, { (u8*)D_8010F1EC_MinigameInstructions, (u8*)D_8010F1D8_MinigameInstructions }, { (u8*)D_8010F1C8_MinigameInstructions, (u8*)D_8010F1B4_MinigameInstructions }, { (u8*)D_8010F1A0_MinigameInstructions, (u8*)D_8010F18C_MinigameInstructions } };
u8* D_8010EE30_MinigameInstructions[6] = { (u8*)D_8010F2B0_MinigameInstructions, (u8*)D_8010F2A4_MinigameInstructions, (u8*)D_8010F298_MinigameInstructions, (u8*)D_8010F28C_MinigameInstructions, (u8*)D_8010F280_MinigameInstructions, (u8*)D_8010F274_MinigameInstructions };
s16 D_8010EE48_MinigameInstructions[6][2] = { { 9, 12 }, { 9, 12 }, { 5, 8 }, { 4, 7 }, { 9, 11 }, { 5, 8 } };
s32 D_8010EE60_MinigameInstructions[6][2] = { { 0x3C000B, 0x3C0011 }, { 0x3C000C, 0x3C0012 }, { 0x3C000D, 0x3C0013 }, { 0x3C000E, 0x3C0014 }, { 0x3C000F, 0x3C0015 }, { 0x3C0010, 0x3C0016 } };
s32 D_8010EE90_MinigameInstructions[6] = { 0x2F0000, 0x2F0002, 0x2F0004, 0x2F0006, 0x2F0008, 0x2F000A };
char* D_8010EEA8_MinigameInstructions[6] = { (char*)D_8010F34C_MinigameInstructions, (char*)D_8010F338_MinigameInstructions, (char*)D_8010F320_MinigameInstructions, (char*)D_8010F308_MinigameInstructions, (char*)D_8010F2F4_MinigameInstructions, (char*)D_8010F2E0_MinigameInstructions };
s32 D_8010EEC0_MinigameInstructions[8] = { 0x360002, 0x360003, 0x360004, 0x360005, 0x360006, 0x360007, 0, 0 };
