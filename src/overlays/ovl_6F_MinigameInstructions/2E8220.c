#include "ovl6f.h"

extern u16 ContBtn[];

extern s8 ContStkY[];


void func_80103560_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 p;
    u8 chr;

    p = work->unk_38;
    chr = GwPlayer[p].character;
    work->unk_3E = GwPlayer[p].group;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9F, 0x299);
    work->unk_50 = func_80023FC8(work->unk_4E);
    func_800258EC(work->unk_50, 4, 4);
    work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 3, 0x1D);
    work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 1, 0x1D);
    work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 5, 0x1D);
    if (work->unk_3E == 0) {
        work->unk_58 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x65, 0x1D);
        work->unk_5C = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x5F, 0x1D);
        func_80028498(work->unk_4E, func_80025E48(work->unk_58), 0);
        work->unk_70 = LoadFormFile(0x400000, 0x299);
        func_80025798(work->unk_70, -10000.0f, -10000.0f, 0.0f);
        func_8002859C(work->unk_70, work->unk_4E, D_8010F360_MinigameInstructions);
        func_800258EC(work->unk_70, 0x4000, 0x4000);
    }
    work->unk_08 = (work->unk_38 * 0x23) + 0x19;
    func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
    pos.x = work->unk_00 = -50.0f;
    pos.y = work->unk_04 = 150.0f;
    out.z = 0.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
}
void func_80103788_MinigameInstructions(Ovl6FPlayerWork* work) {
    f32 x;
    f32 y;
    f32 mag;
    f32 ang;
    f32 step;
    f32 amp;
    f32 h;
    s32 flags;
    s16 motion;
    s16 prev;
    s32 pressed;
    s16 f;
    s16 port;

    motion = 0;
    if (work->unk_3E != 0) {
        func_800FADF4_MinigameInstructions(work);
    }
    port = GwPlayer[work->unk_38].port;
    x = (s8)(ContStkX[port] / 10);
    y = (s8)(ContStkY[port] / 10);
    mag = (x * x) + (y * y);
    flags = D_8010E970_MinigameInstructions[(s16)D_8010F766_MinigameInstructions].flags;
    if (mag != 0.0f && (flags & 3)) {
        func_800257E4(work->unk_4E, 0.0f, func_800B0CD8(x, -y), 0.0f);
    }
    prev = work->unk_3C;
    if ((ContBtnTrg[port] & 0x8000) && (flags & 4)) {
        work->unk_3C = 3;
        func_80025C20(work->unk_4E, func_80025E48(work->unk_56), 0, 8, 0);
        func_800FA300_MinigameInstructions(0x127, work);
        if (work->unk_3E == 0) {
            func_800258EC(work->unk_70, 0x4000, 0x4000);
        }
        ang = 0.0f;
        step = 10.0f;
        amp = 100.0f;
        h = func_800AEAC0(ang) * amp;
        pressed = 0;
        do {
            ang += step;
            if (ang == 40.0f && !(ContBtn[port] & 0x8000)) {
                ang = 90.0f;
                amp = h;
            }
            if (((ContBtnTrg[port] >> 14) & 1 & (pressed ^ 1)) && work->unk_3E == 0) {
                func_800FA300_MinigameInstructions(0x13C, work);
                if (flags & 0x20) {
                    func_80025BB8(work->unk_4E, work->unk_5E);
                } else {
                    func_80025BB8(work->unk_4E, work->unk_5C);
                }
                if (work->unk_3E == 0) {
                    while (1) {
                        HuPrcVSleep();
                        f = func_80025D18(work->unk_4E);
                        if (f == 28) {
                            func_800258EC(work->unk_70, 0x4000, 0);
                        }
                        if (f == func_80025D40(work->unk_4E)) {
                            break;
                        }
                    }
                } else {
                    func_800FB4DC_MinigameInstructions(work->unk_4E);
                }
                step = 20.0f;
                ang = 90.0f;
                amp = h;
                pressed = 1;
            }
            if (ang > 180.0f) {
                ang = 180.0f;
            }
            h = func_800AEAC0(ang) * amp;
            func_80025798(work->unk_4E, work->unk_0C, h + work->unk_10, work->unk_14);
            HuPrcVSleep();
        } while (ang < 180.0f);
        func_800FA300_MinigameInstructions(0x12E, work);
        func_80025C20(work->unk_4E, func_80025E48(work->unk_50), 0, 8, 2);
        mag = 0.0f;
    }
    if (mag == 0.0f) {
        work->unk_3C = 0;
        motion = func_80025E48(work->unk_50);
    } else if (mag <= 16.0f && (flags & 1)) {
        work->unk_3C = 1;
        motion = func_80025E48(work->unk_54);
        func_800FB590_MinigameInstructions(work, motion);
    } else if (16.0f < mag && (flags & 2)) {
        work->unk_3C = 2;
        motion = func_80025E48(work->unk_52);
        func_800FB60C_MinigameInstructions(work, motion);
    }
    if ((ContBtnTrg[port] & 0x4000) && work->unk_3E == 0) {
        func_800FA300_MinigameInstructions(0x135, work);
        func_80025BB8(work->unk_4E, work->unk_5C);
        D_800F2B7C[work->unk_4E].unk_0C = -1;
        if (work->unk_3E == 0) {
            func_800258EC(work->unk_70, 0x4000, 0x4000);
            do {
                HuPrcVSleep();
                f = func_80025D18(work->unk_4E);
                if (f == 28) {
                    func_800258EC(work->unk_70, 0x4000, 0);
                }
            } while (f != func_80025D40(work->unk_4E));
            work->unk_3C = 0;
        } else {
            func_800FB4DC_MinigameInstructions(work->unk_4E);
            work->unk_3C = 0;
        }
        motion = func_80025E48(work->unk_50);
        prev = -1;
        if (work->unk_3E == 0) {
            func_80025C20(work->unk_4E, motion, 0, 8, 2);
            HuPrcSleep(8);
            func_800258EC(work->unk_70, 0x4000, 0x4000);
        }
    }
    if (prev != work->unk_3C) {
        func_80025C20(work->unk_4E, motion, 0, 8, 2);
    }
    if (D_800F2B7C[work->unk_4E].unk_0C == -1 && work->unk_3E == 0) {
        func_800258EC(work->unk_70, 0x4000, 0x4000);
    }
}
void func_80103E48_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 p;
    u8 chr;

    p = work->unk_38;
    chr = GwPlayer[p].character;
    work->unk_3E = GwPlayer[p].group;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9F, 0x299);
    work->unk_50 = func_80023FC8(work->unk_4E);
    func_800258EC(work->unk_50, 4, 4);
    work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 3, 0x1D);
    work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 1, 0x1D);
    work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 5, 0x1D);
    if (work->unk_3E == 0) {
        work->unk_58 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x24, 0x1D);
        func_80028498(work->unk_4E, func_80025E48(work->unk_58), 0);
        work->unk_70 = LoadFormFile(0x410003, 0x299);
        func_80025EB4(work->unk_70, 1, 1);
        func_8002859C(work->unk_70, work->unk_4E, D_8010F360_MinigameInstructions);
        func_800258EC(work->unk_70, 0x4000, 0x4000);
        work->unk_5C = work->unk_5E = -1;
    } else {
        work->unk_5C = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 4, 0x1D);
        work->unk_5E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 6, 0x1D);
    }
    work->unk_08 = (work->unk_38 * 0x23) + 0x19;
    func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
    pos.x = work->unk_00 = -50.0f;
    pos.y = work->unk_04 = 150.0f;
    out.z = 0.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
}
void func_801040AC_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 p;
    u8 chr;

    p = work->unk_38;
    chr = GwPlayer[p].character;
    work->unk_3E = GwPlayer[p].group;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9F, 0x299);
    work->unk_50 = func_80023FC8(work->unk_4E);
    func_800258EC(work->unk_50, 4, 4);
    work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 3, 0x1D);
    work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 1, 0x1D);
    work->unk_08 = (work->unk_38 * 0x23) + 0x19;
    func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
    pos.x = work->unk_00 = -50.0f;
    pos.y = work->unk_04 = 150.0f;
    out.z = 0.0f;
    work->unk_14 = -180.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
    if (work->unk_3E == 0) {
        work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x79, 0x1D);
        work->unk_58 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x4D, 0x1D);
        func_800FA77C_MinigameInstructions(0x26);
        func_80021B04(D_8010E960_MinigameInstructions, 0xA0, 0xA0, 0xC0);
        return;
    }
    func_80025830(work->unk_4E, 0.32000002f, 0.32000002f, 0.32000002f);
    work->unk_70 = LoadFormFile(0x320001, 0x299);
    func_80025830(work->unk_70, 0.0f, 0.0f, 0.0f);
    pos.x = work->unk_08;
    pos.y = work->unk_30 = work->unk_04;
    out.z = 0.0f;
    work->unk_14 = -230.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    func_80025798(work->unk_70, out.x, out.y, work->unk_14);
}
void func_80104320_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    f32 s;
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
        func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
        if ((work->unk_42++ & 3) == 0) {
            func_800FA300_MinigameInstructions(0x119, work);
        }
        HuPrcVSleep();
    }
    pos.x = work->unk_00 = work->unk_08;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
    for (i = 90; i >= 0; i -= 30) {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        if ((work->unk_42++ & 7) == 0) {
            func_800FA300_MinigameInstructions(0x112, work);
        }
        HuPrcVSleep();
    }
    if (work->unk_3E == 0) {
        func_80025C20(work->unk_4E, func_80025E48(work->unk_56), 0, 8, 2);
        HuPrcSleep(8);
        work->unk_3C = 0;
        work->unk_0C = out.x;
        work->unk_10 = out.y;
        work->unk_14 = -180.0f;
        return;
    }
    func_80025C20(work->unk_4E, func_80025E48(work->unk_50), 0, 8, 2);
    work->unk_24 = work->unk_30 = 0.0f;
    func_800257E4(work->unk_70, 0.0f, 0.0f, 0.0f);
    for (i = 0; i < 10; i++) {
        HuPrcVSleep();
        s = (i / 10.0f) * 0.32000002f;
        func_80025830(work->unk_70, s, s, s);
        work->unk_04 -= 1.0f;
        pos.x = work->unk_00;
        pos.y = work->unk_04;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
    }
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    work->unk_B6 = 0;
}
void func_80104688_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    f32 s;
    s16 i;

    if (work->unk_3E == 0) {
        if (func_80025E48(work->unk_4E) != func_80025E48(work->unk_52)) {
            func_80025C20(work->unk_4E, func_80025E48(work->unk_52), 0, 8, 2);
        }
        HuPrcSleep(8);
    } else {
        if (func_80025E48(work->unk_4E) != func_80025E48(work->unk_52)) {
            func_80025C20(work->unk_4E, func_80025E48(work->unk_52), 0, 8, 2);
        }
        for (i = 0; i < 11; i++) {
            HuPrcVSleep();
            s = (1.0f - i / 10.0f) * 0.32000002f;
            func_80025830(work->unk_70, s, s, s);
            work->unk_04 += 1.0f;
            pos.x = work->unk_00;
            pos.y = work->unk_04;
            func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
            func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
        }
    }
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
        func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
        if ((work->unk_42++ & 3) == 0) {
            func_800FA300_MinigameInstructions(0x119, work);
        }
        HuPrcVSleep();
    }
}
void func_80104988_MinigameInstructions(Ovl6FPlayerWork* work) {
    f32 x;
    f32 y;
    f32 mag;
    s16 prev;
    s16 a;
    s16 ang;
    s16 port;

    port = GwPlayer[work->unk_38].port;
    x = (s8)(ContStkX[port] / 10);
    y = (s8)(ContStkY[port] / 10);
    mag = (x * x) + (y * y);
    if (work->unk_3E == 0) {
        if (mag != 0.0f) {
            func_800257E4(work->unk_4E, 0.0f, func_800B0CD8(x, -y), 0.0f);
        }
        prev = work->unk_3C;
        if (mag == 0.0f) {
            work->unk_3C = 0;
            a = func_80025E48(work->unk_56);
        } else {
            work->unk_3C = 1;
            a = func_80025E48(work->unk_58);
        }
        if (prev != work->unk_3C) {
            func_80025C20(work->unk_4E, a, 0, 8, 2);
        }
    } else {
        if (mag != 0.0f) {
            ang = (s16)(func_800B0CD8(x, -y) / 10.0f) * 10;
            if (ang < 0) {
                ang += 360;
            }
            work->unk_30 = ang;
        }
        ang = work->unk_30;
        if (ang != work->unk_24) {
            if (work->unk_24 < 180.0f) {
                if (work->unk_24 < work->unk_30 && ang < work->unk_24 + 180.0f) {
                    work->unk_24 += 10.0f;
                } else {
                    work->unk_24 -= 10.0f;
                }
            } else {
                if (work->unk_24 - 180.0f < work->unk_30 && ang < work->unk_24) {
                    work->unk_24 -= 10.0f;
                } else {
                    work->unk_24 += 10.0f;
                }
            }
            if (work->unk_24 > 360.0f) {
                work->unk_24 -= 360.0f;
            }
            if (work->unk_24 < 0.0f) {
                work->unk_24 += 360.0f;
            }
        }
        func_800257E4(work->unk_4E, 0.0f, work->unk_24, 0.0f);
        func_800257E4(work->unk_70, 0.0f, work->unk_24, 0.0f);
        if ((work->unk_B6 == 0 || --work->unk_B6 == 0) && (ContBtnTrg[port] & 0x8000)) {
            func_800FA284_MinigameInstructions(0x2AA);
            func_80021794(D_8010E960_MinigameInstructions, 0, func_800AEAC0(work->unk_24) * 40.0f + work->unk_0C,
                          work->unk_10 + 10.0f, func_800AEFD0(work->unk_24) * 40.0f + work->unk_14, 4);
            work->unk_B6 = 45;
        }
    }
}
const char D_8010F360_MinigameInstructions[] __attribute__((section(".rodata"))) = "item_hook";
const char D_8010F36C_MinigameInstructions[] __attribute__((section(".rodata"))) = "";

void func_80104DF0_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    f32 s;
    f32 sh;
    f32 sm;
    s16 p;
    s16 chr;

    p = work->unk_38;
    chr = GwPlayer[p].character;
    work->unk_3E = GwPlayer[p].group;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9F, 0x299);
    work->unk_50 = func_80023FC8(work->unk_4E);
    func_800258EC(work->unk_50, 4, 4);
    work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 3, 0x1D);
    work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 1, 0x1D);
    work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 5, 0x1D);
    work->unk_08 = (work->unk_38 * 0x23) + 0x19;
    func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
    pos.x = work->unk_00 = -50.0f;
    pos.y = work->unk_04 = 150.0f;
    out.z = 0.0f;
    work->unk_14 = -180.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
    if (work->unk_3E != 0) {
        switch (chr) {
            case 0:
                sh = 1.0f;
                sm = 0.56f;
                break;
            case 1:
                sh = 1.0f;
                sm = 0.54f;
                break;
            case 2:
                sh = 1.0f;
                sm = 0.6f;
                break;
            case 4:
                sh = 0.8f;
                sm = 0.7f;
                break;
            case 3:
                sh = 0.9f;
                sm = 0.45f;
                break;
            case 5:
                sh = 0.7f;
                sm = 0.8f;
                break;
            default:
                sh = sm = 1.0f;
                break;
        }
        work->unk_58 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x2D, 0x1D);
        work->unk_5A = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x99, 0x1D);
        s = sh * 0.4f;
        func_80025830(work->unk_4E, s, s, s);
        work->unk_70 = LoadFormFile(7, 0x299);
        func_80025830(work->unk_70, sm * 0.4f, sm * 0.4f, sm * 0.4f);
        func_80025798(work->unk_70, out.x, out.y, work->unk_14);
    }
}
// the first walk-in loop keeps the 30.0f compare constant in a register (retail reloads it each frame; masked 18)
#ifdef NON_MATCHING
void func_80105148_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 i;

    if (work->unk_3E == 0) {
        func_80025BB8(work->unk_4E, work->unk_52);
    } else {
        func_80025BB8(work->unk_4E, work->unk_58);
    }
    func_80025EB4(work->unk_4E, 2, 2);
    func_800257E4(work->unk_4E, 0.0f, 90.0f, 0.0f);
    if (work->unk_3E != 0) {
        func_800257E4(work->unk_70, 0.0f, 90.0f, 0.0f);
    }
    pos.x = work->unk_00;
    pos.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 < work->unk_08) {
        pos.x = work->unk_00 += 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
        if (work->unk_3E != 0) {
            func_80025798(work->unk_70, out.x, out.y, work->unk_14);
            if (func_80025D18(work->unk_4E) == 30.0f) {
                func_800FA284_MinigameInstructions(0x178);
            }
        } else if ((work->unk_42++ & 3) == 0) {
            func_800FA300_MinigameInstructions(0x119, work);
        }
        HuPrcVSleep();
    }
    pos.x = work->unk_00 = work->unk_08;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
    for (i = 90; i >= 0; i -= 30) {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        if (work->unk_3E != 0) {
            func_800257E4(work->unk_70, 0.0f, i, 0.0f);
            if (func_80025D18(work->unk_4E) == 30.0f) {
                func_800FA284_MinigameInstructions(0x178);
            }
        } else if ((work->unk_42++ & 7) == 0) {
            func_800FA300_MinigameInstructions(0x112, work);
        }
        HuPrcVSleep();
    }
    func_80025C20(work->unk_4E, func_80025E48((work->unk_3E == 0) ? work->unk_50 : work->unk_5A), 0, 8, 2);
    HuPrcSleep(8);
    work->unk_3C = 0;
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    work->unk_14 = -180.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80105148_MinigameInstructions);
#endif
// the walk-out loop keeps the 30.0f compare constant in a register (retail reloads it each frame; masked 11); tried operand order, split -= 12.0f store
#ifdef NON_MATCHING
void func_80105464_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 i;

    if (work->unk_3E == 0) {
        if (func_80025E48(work->unk_4E) != func_80025E48(work->unk_52)) {
            func_80025C20(work->unk_4E, func_80025E48(work->unk_52), 0, 8, 2);
        }
        HuPrcSleep(8);
    } else {
        if (func_80025E48(work->unk_4E) != func_80025E48(work->unk_58)) {
            func_80025C20(work->unk_4E, func_80025E48(work->unk_58), 0, 8, 2);
        }
    }
    HuPrcSleep(8);
    for (i = 0; i >= -90; i -= 30) {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        if (work->unk_3E != 0) {
            func_800257E4(work->unk_70, 0.0f, i, 0.0f);
            if (func_80025D18(work->unk_4E) == 30.0f) {
                func_800FA284_MinigameInstructions(0x178);
            }
        } else if ((work->unk_42++ & 7) == 0) {
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
        func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
        if (work->unk_3E != 0) {
            func_80025798(work->unk_70, out.x, out.y, work->unk_14);
            if (func_80025D18(work->unk_4E) == 30.0f) {
                func_800FA284_MinigameInstructions(0x178);
            }
        } else if ((work->unk_42++ & 3) == 0) {
            func_800FA300_MinigameInstructions(0x119, work);
        }
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80105464_MinigameInstructions);
#endif
void func_8010574C_MinigameInstructions(Ovl6FPlayerWork* work) {
    f32 x;
    f32 y;
    f32 mag;
    f32 ang;
    s16 motion;
    s16 prev;
    s16 port;

    if (work->unk_3E == 0) {
        func_800FADF4_MinigameInstructions(work);
        return;
    }
    port = GwPlayer[work->unk_38].port;
    x = (s8)(ContStkX[port] / 10);
    y = (s8)(ContStkY[port] / 10);
    mag = (x * x) + (y * y);
    if (mag != 0.0f) {
        ang = func_800B0CD8(x, -y);
        func_800257E4(work->unk_4E, 0.0f, ang, 0.0f);
        func_800257E4(work->unk_70, 0.0f, ang, 0.0f);
    }
    prev = work->unk_3C;
    if (mag == 0.0f) {
        work->unk_3C = 0;
        motion = func_80025E48(work->unk_5A);
    } else {
        work->unk_3C = 1;
        motion = func_80025E48(work->unk_58);
        if (motion == func_80025E48(work->unk_4E) && func_80025D18(work->unk_4E) == 10.0f) {
            func_8006035C(func_800FA2C0_MinigameInstructions(0x2D1, work), 0x6F);
        }
    }
    if (prev != work->unk_3C) {
        func_80025C20(work->unk_4E, motion, 0, 8, 2);
    }
}
void func_80105984_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 p;
    u8 chr;

    p = work->unk_38;
    chr = GwPlayer[p].character;
    work->unk_3E = GwPlayer[p].group;
    if (_CheckFlag(0x2D) != 0 && work->unk_38 == 3) {
        work->unk_4E = LoadFormFile(0x390006, 0x299);
        work->unk_70 = LoadFormFile(0x70000, 0x29D);
        func_80020EA0(work->unk_70, (u8*)"c100_1-atama", work->unk_4E, (u8*)"head");
    } else {
        work->unk_4E = LoadFormFile(D_8010EEE0_MinigameInstructions[chr], 0x299);
    }
    work->unk_50 = func_80023FC8(work->unk_4E);
    func_800258EC(work->unk_50, 4, 4);
    work->unk_08 = (work->unk_38 * 0x23) + 0x19;
    func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
    pos.x = work->unk_00 = -50.0f;
    pos.y = work->unk_04 = 135.0f;
    out.z = 0.0f;
    work->unk_14 = -180.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
}
void func_80105B24_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 i;

    func_80025EB4(work->unk_4E, 2, 2);
    func_800257E4(work->unk_4E, 0.0f, 90.0f, 0.0f);
    pos.x = work->unk_00;
    pos.y = work->unk_04;
    out.z = 0.0f;
    work->unk_44 = func_800FA2C0_MinigameInstructions(0x2D8, work);
    while (work->unk_00 < work->unk_08) {
        pos.x = work->unk_00 += 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
        HuPrcVSleep();
    }
    func_800FA380_MinigameInstructions(work->unk_44);
    pos.x = work->unk_00 = work->unk_08;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
    func_800FA3AC_MinigameInstructions(2, work);
    func_8006035C(func_800FA2C0_MinigameInstructions(0x2D6, work), 0x6F);
    for (i = 90; i >= 0; i -= 30) {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        HuPrcVSleep();
    }
    work->unk_24 = work->unk_20 = 0.0f;
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    work->unk_14 = -180.0f;
}
void func_80105D08_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 i;

    HuPrcSleep(8);
    func_800FA2C0_MinigameInstructions(0x2D9, work);
    for (i = 0; i >= -90; i -= 30) {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        HuPrcVSleep();
    }
    pos.x = work->unk_00;
    pos.y = work->unk_04;
    out.z = 0.0f;
    work->unk_44 = func_800FA2C0_MinigameInstructions(0x2D8, work);
    while (work->unk_00 > -50.0f) {
        pos.x = work->unk_00 -= 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
        HuPrcVSleep();
    }
    func_800FA380_MinigameInstructions(work->unk_44);
}
void func_80105E64_MinigameInstructions(Ovl6FPlayerWork* work) {
    f32 x;
    f32 y;
    f32 mag;
    f32 tilt;
    f32 px;
    f32 pz;
    s16 port;

    port = GwPlayer[work->unk_38].port;
    x = (s8)(ContStkX[port] / 10);
    y = (s8)(ContStkY[port] / 10);
    mag = (x * x) + (y * y);
    if (mag != 0.0f) {
        work->unk_B6 = mag / 2.0f;
        if (work->unk_B6 < 31) {
            tilt = work->unk_B6;
        } else {
            tilt = 30.0f;
        }
    } else {
        if (work->unk_B6 != 0) {
            if ((work->unk_B6 /= 2) < 0.5f) {
                work->unk_B6 = 0;
            }
        }
        tilt = work->unk_B6;
    }
    work->unk_20 = -tilt;
    px = func_800AEAC0(work->unk_24 += 1.0f) * work->unk_B6 / 2.0f + work->unk_0C;
    pz = func_800AEFD0(work->unk_24) * work->unk_B6 / 2.0f + work->unk_14;
    func_80025798(work->unk_4E, px, func_800AEAC0(tilt) * 20.0f + work->unk_10, pz);
    func_800257E4(work->unk_4E, work->unk_20, work->unk_24, 0.0f);
}
void func_801060DC_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 p;
    s16 chr;

    p = work->unk_38;
    chr = GwPlayer[p].character;
    if ((work->unk_3E = GwPlayer[p].group) == 0) {
        work->unk_4E = LoadFormFile(0x220003, 0x299);
        work->unk_50 = LoadFormFile(0x220004, 0x1D);
        work->unk_52 = LoadFormFile(0x220005, 0x1D);
        work->unk_54 = LoadFormFile(0x460025, 0x1D);
        work->unk_70 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9F, 0x299);
        func_80020EA0(work->unk_70, D_8010EE00_MinigameInstructions[chr][0], work->unk_4E, (u8*)"21_kimoti_1b-atama_3");
        func_80025830(work->unk_4E, 0.28f, 0.28f, 0.28f);
        func_80025798(work->unk_70, -1000.0f, 0.0f, 0.0f);
        work->unk_08 = (work->unk_38 * 30) + 40;
        pos.x = work->unk_00 = -50.0f;
        pos.y = work->unk_04 = 150.0f;
        work->unk_14 = -180.0f;
    } else {
        work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9F, 0x299);
        work->unk_50 = func_80023FC8(work->unk_4E);
        func_800258EC(work->unk_50, 4, 4);
        work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 3, 0x1D);
        work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x7E, 0x1D);
        func_80025830(work->unk_4E, 0.28f, 0.28f, 0.28f);
        work->unk_08 = (work->unk_38 * 30) + 40;
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
void func_80106358_MinigameInstructions(Ovl6FPlayerWork* work) {
    s16 port;

    port = GwPlayer[work->unk_38].port;
    if (func_80009E4C(port, 0x12, ContStkX[port], ContStkY[port]) != 0) {
        if (work->unk_3C == 0) {
            func_80025C20(work->unk_4E, func_80025E48(work->unk_54), 0, 4, 2);
            func_80025CA8(work->unk_4E, 0.0f);
            func_80025EB4(work->unk_4E, 1, 0);
        }
        work->unk_3C = 5;
        func_80025EB4(work->unk_4E, 2, 2);
        if (func_80025D18(work->unk_4E) == 4.0f) {
            work->unk_44 = func_800FA2C0_MinigameInstructions(0x35F, work);
        }
    } else if (work->unk_3C != 0) {
        func_80025C20(work->unk_4E, func_80025E48(work->unk_54), 0, 4, 1);
        work->unk_3C = 0;
    }
}

const char D_8010F3B8_MinigameInstructions[] __attribute__((section(".rodata"))) = "27mt008_DEF";

const char D_8010F3C4_MinigameInstructions[] __attribute__((section(".rodata"))) = "27mt007_DEF";

const char D_8010F3D0_MinigameInstructions[] __attribute__((section(".rodata"))) = "27mt006_DEF";

const char D_8010F3DC_MinigameInstructions[] __attribute__((section(".rodata"))) = "27mt005_DEF";

const char D_8010F3E8_MinigameInstructions[] __attribute__((section(".rodata"))) = "27mt004_DEF";

const char D_8010F3F4_MinigameInstructions[] = "27mt003_DEF";

void func_801064A4_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    u8 chr;

    chr = GwPlayer[work->unk_38].character;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9F, 0x29D);
    work->unk_50 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x4A, 0x1D);
    work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x4B, 0x1D);
    work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x4C, 0x1D);
    work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x6E, 0x1D);
    func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
    work->unk_70 = LoadFormFile(0x280003, 0x289);
    work->unk_72 = LoadFormFile(0x280006, 0x29D);
    func_80027AC8(work->unk_70, (u8*)D_8010F3F4_MinigameInstructions, D_8010EEF8_MinigameInstructions[chr]);
    func_80025AD4(work->unk_70);
    func_80025B34(work->unk_70);
    func_80025830(work->unk_70, 0.4f, 0.4f, 0.4f);
    work->unk_08 = (work->unk_38 * 35) + 25;
    in.x = work->unk_00 = -50.0f;
    in.y = work->unk_04 = 150.0f;
    work->unk_14 = -180.0f;
    func_8001DD24(0, CZoom - -180.0f, (Vec3f*)&in, &out);
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    func_80025798(work->unk_4E, out.x, out.y + 0.0f, work->unk_14);
    func_80025798(work->unk_70, out.x, out.y, work->unk_14);
}
void func_801066C4_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s16 i;

    func_800258EC(work->unk_4E, 4, 0);
    func_80025BB8(work->unk_4E, work->unk_52);
    func_80025EB4(work->unk_4E, 2, 2);
    func_800257E4(work->unk_4E, 0.0f, 90.0f, 0.0f);
    func_800257E4(work->unk_70, 0.0f, 90.0f, 0.0f);
    in.x = work->unk_00;
    in.y = work->unk_04;
    out.z = 0.0f;
    func_800FA300_MinigameInstructions(0x273, work);
    while (work->unk_00 < work->unk_08) {
        in.x = work->unk_00 += 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
        func_80025798(work->unk_4E, out.x, out.y + 0.0f, work->unk_14);
        func_80025798(work->unk_70, out.x, out.y, work->unk_14);
        HuPrcVSleep();
    }
    in.x = work->unk_00 = work->unk_08;
    func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
    func_80025798(work->unk_4E, out.x, out.y + 0.0f, work->unk_14);
    func_80025798(work->unk_70, out.x, out.y, work->unk_14);
    for (i = 90; i >= 0; i -= 30) {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        func_800257E4(work->unk_70, 0.0f, i, 0.0f);
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
    work->unk_B6 = 0;
    work->unk_24 = 0.0f;
    HuPrcSleep(8);
}
void func_80106948_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s16 i;

    if (func_80025E48(work->unk_4E) != func_80025E48(work->unk_52)) {
        func_80025C20(work->unk_4E, func_80025E48(work->unk_52), 0, 8, 2);
    }
    HuPrcSleep(8);
    for (i = 0; i >= -90; i -= 30) {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        func_800257E4(work->unk_70, 0.0f, i, 0.0f);
        HuPrcVSleep();
    }
    in.x = work->unk_00;
    in.y = work->unk_04;
    out.z = 0.0f;
    func_800FA300_MinigameInstructions(0x273, work);
    while (work->unk_00 > -50.0f) {
        in.x = work->unk_00 -= 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
        func_80025798(work->unk_4E, out.x, out.y + 0.0f, work->unk_14);
        func_80025798(work->unk_70, out.x, out.y, work->unk_14);
        HuPrcVSleep();
    }
    func_800258EC(work->unk_4E, 4, 4);
}
void func_80106B2C_MinigameInstructions(Ovl6FPlayerWork* work) {
    f32 angle;
    f32 tilt;
    f32 y;
    f32 step;
    f32 amp;
    s16 motion;
    s16 prev;
    u8 port;

    port = GwPlayer[work->unk_38].port;
    prev = work->unk_3C;
    motion = 0;
    if (func_80025E48(work->unk_4E) == func_80025E48(work->unk_52)) {
        if (func_80025D18(work->unk_4E) == 22.0f) {
            func_800FA300_MinigameInstructions(0x273, work);
        }
    }
    if (ContBtnTrg[port] & 0x4000) {
        work->unk_3C = 2;
        work->unk_B6 = 0;
        motion = func_80025E48(work->unk_52);
    } else if (work->unk_3C != 2 || ++work->unk_B6 >= 16) {
        work->unk_3C = 0;
        motion = func_80025E48(work->unk_50);
    }
    if (ContBtnTrg[port] & 0x8000) {
        work->unk_3C = 3;
        func_80025C20(work->unk_4E, func_80025E48(work->unk_54), 0, 4, 0);
        func_800FA300_MinigameInstructions(0x127, work);
        angle = 0.0f;
        step = 10.0f;
        amp = 100.0f;
        tilt = 0.0f;
        y = func_800AEAC0(angle) * amp;
        do {
            angle += step;
            y = func_800AEAC0(angle) * amp;
            func_80025798(work->unk_4E, work->unk_0C, y + work->unk_10, work->unk_14);
            func_80025798(work->unk_70, work->unk_0C, y + work->unk_10, work->unk_14);
            tilt -= 3.5f;
            if (tilt > 45.0f) {
                tilt = 45.0f;
            }
            func_800257E4(work->unk_4E, 0.0f, work->unk_24, 0.0f);
            func_800257E4(work->unk_70, tilt, work->unk_24, 0.0f);
            HuPrcVSleep();
        } while (angle < 150.0f);
        func_80025BB8(work->unk_4E, work->unk_56);
        while (angle < 180.0f) {
            angle += step;
            if (angle > 180.0f) {
                angle = 180.0f;
            }
            y = func_800AEAC0(angle) * amp;
            func_80025798(work->unk_4E, work->unk_0C, y + work->unk_10, work->unk_14);
            func_80025798(work->unk_70, work->unk_0C, y + work->unk_10, work->unk_14);
            tilt *= 0.7f;
            func_800257E4(work->unk_4E, 0.0f, work->unk_24, 0.0f);
            func_800257E4(work->unk_70, tilt, work->unk_24, 0.0f);
            HuPrcVSleep();
        }
        func_800FA300_MinigameInstructions(0x12E, work);
        func_800257E4(work->unk_70, 0.0f, work->unk_24, 0.0f);
        prev = -1;
        motion = func_80025E48(work->unk_50);
    }
    if (prev != work->unk_3C) {
        func_80025C20(work->unk_4E, motion, 0, 8, 2);
    }
    func_800257E4(work->unk_4E, 0.0f, work->unk_24, 0.0f);
    func_800257E4(work->unk_70, 0.0f, work->unk_24, 0.0f);
    if ((work->unk_24 += 1.0f) >= 360.0f) {
        work->unk_24 = 0.0f;
    }
}
void func_80106F90_MinigameInstructions(Ovl6FPlayerWork* work) {
    if ((work->unk_3E = GwPlayer[work->unk_38].group) == 0) {
        func_801064A4_MinigameInstructions(work);
    } else {
        func_800FA7F8_MinigameInstructions(work);
    }
}
void func_80106FE0_MinigameInstructions(Ovl6FPlayerWork* work) {
    if (work->unk_3E == 0) {
        func_801066C4_MinigameInstructions(work);
    } else {
        func_800FA9EC_MinigameInstructions(work);
    }
}
void func_80107018_MinigameInstructions(Ovl6FPlayerWork* work) {
    if (work->unk_3E == 0) {
        func_80106948_MinigameInstructions(work);
    } else {
        func_800FAC2C_MinigameInstructions(work);
    }
}
void func_80107050_MinigameInstructions(Ovl6FPlayerWork* work) {
    if (work->unk_3E == 0) {
        func_80106B2C_MinigameInstructions(work);
    } else {
        func_800FADF4_MinigameInstructions(work);
    }
}

void func_80107088_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    u8 chr;

    chr = GwPlayer[work->unk_38].character;
    work->unk_3E = GwPlayer[work->unk_38].group;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9F, 0x299);
    if (work->unk_3E == 0) {
        work->unk_50 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x4F, 0x1D);
        work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x73, 0x1D);
        work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x72, 0x1D);
        work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x50, 0x1D);
        work->unk_5C = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x5F, 0x1D);
        work->unk_70 = LoadFormFile(0x3E0009, 0x299);
        func_80025830(work->unk_70, 0.4f, 0.4f, 0.4f);
        func_80025798(work->unk_70, -10000.0f, -10000.0f, 0.0f);
        func_8002859C(work->unk_70, work->unk_4E, D_8010F360_MinigameInstructions);
        func_800258EC(work->unk_70, 0x4000, 0x4000);
    } else {
        work->unk_50 = func_80023FC8(work->unk_4E);
        func_800258EC(work->unk_50, 4, 4);
        work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 3, 0x1D);
        work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 1, 0x1D);
        work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 5, 0x1D);
        work->unk_5C = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 4, 0x1D);
    }
    work->unk_08 = (work->unk_38 * 35) + 25;
    func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
    in.x = work->unk_00 = -50.0f;
    in.y = work->unk_04 = 150.0f;
    out.z = 0.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
}
void func_8010732C_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s16 i;

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
        if ((work->unk_42 & 7) == 0 && work->unk_3E == 0) {
            func_800FA2C0_MinigameInstructions(0x30C, work);
        }
        HuPrcVSleep();
    }
    in.x = work->unk_00 = work->unk_08;
    func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
    for (i = 90; i >= 0; i -= 30) {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        HuPrcVSleep();
        if ((work->unk_42++ & 7) == 0) {
            func_800FA300_MinigameInstructions(0x112, work);
        }
        if ((work->unk_42 & 7) == 0 && work->unk_3E == 0) {
            func_800FA2C0_MinigameInstructions(0x30C, work);
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
void func_801075B8_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s16 i;

    if (func_80025E48(work->unk_4E) != func_80025E48(work->unk_52)) {
        func_80025C20(work->unk_4E, func_80025E48(work->unk_52), 0, 8, 2);
    }
    HuPrcSleep(8);
    for (i = 0; i >= -90; i -= 30) {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        if ((work->unk_42++ & 7) == 0) {
            func_800FA300_MinigameInstructions(0x119, work);
        }
        if ((work->unk_42 & 7) == 0 && work->unk_3E == 0) {
            func_800FA2C0_MinigameInstructions(0x30C, work);
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
        if ((work->unk_42 & 7) == 0 && work->unk_3E == 0) {
            func_800FA2C0_MinigameInstructions(0x30C, work);
        }
        HuPrcVSleep();
    }
}
extern u16 ContBtn[];  /* engine/pad.h */
extern s8 ContStkY[];

void func_801077C8_MinigameInstructions(Ovl6FPlayerWork* work) {
    f32 sx;
    f32 sy;
    f32 mag;
    f32 angle;
    f32 step;
    f32 amp;
    f32 y;
    s32 flags;
    s16 motion;
    s16 prev;
    s16 frame;
    s32 pressed;
    s16 port;

    port = GwPlayer[work->unk_38].port;
    sx = (s8)(ContStkX[port] / 10);
    sy = (s8)(ContStkY[port] / 10);
    mag = sx * sx + sy * sy;
    flags = D_8010E970_MinigameInstructions[(s16)D_8010F766_MinigameInstructions].flags;
    motion = 0;
    if (mag != 0.0f && (flags & 3)) {
        func_800257E4(work->unk_4E, 0.0f, func_800B0CD8(sx, -sy), 0.0f);
    }
    prev = work->unk_3C;
    if ((ContBtnTrg[port] & 0x8000) && (flags & 4)) {
        work->unk_3C = 3;
        func_80025C20(work->unk_4E, func_80025E48(work->unk_56), 0, 8, 0);
        func_800FA300_MinigameInstructions(0x127, work);
        if (work->unk_3E == 0) {
            func_800258EC(work->unk_70, 0x4000, 0x4000);
        }
        angle = 0.0f;
        step = 10.0f;
        amp = 100.0f;
        y = func_800AEAC0(angle) * amp;
        pressed = 0;
        do {
            angle += step;
            if (angle == 40.0f && !(ContBtn[port] & 0x8000)) {
                angle = 90.0f;
                amp = y;
            }
            if (((ContBtnTrg[port] >> 14) & 1 & (pressed ^ 1)) && work->unk_3E == 0) {
                func_800FA300_MinigameInstructions(0x13C, work);
                if (flags & 0x20) {
                    func_80025BB8(work->unk_4E, work->unk_5E);
                } else {
                    func_80025BB8(work->unk_4E, work->unk_5C);
                }
                if (work->unk_3E == 0) {
                    while (1) {
                        HuPrcVSleep();
                        frame = func_80025D18(work->unk_4E);
                        if (frame == 28) {
                            func_800258EC(work->unk_70, 0x4000, 0);
                        }
                        if (frame == func_80025D40(work->unk_4E)) break;
                    }
                } else {
                    func_800FB4DC_MinigameInstructions(work->unk_4E);
                }
                step = 20.0f;
                angle = 90.0f;
                amp = y;
                pressed = 1;
            }
            if (angle > 180.0f) {
                angle = 180.0f;
            }
            y = func_800AEAC0(angle) * amp;
            func_80025798(work->unk_4E, work->unk_0C, y + work->unk_10, work->unk_14);
            HuPrcVSleep();
        } while (angle < 180.0f);
        func_800FA300_MinigameInstructions(0x12E, work);
        func_80025C20(work->unk_4E, func_80025E48(work->unk_50), 0, 8, 2);
        mag = 0.0f;
    }
    if (mag == 0.0f) {
        work->unk_3C = 0;
        motion = func_80025E48(work->unk_50);
        if (work->unk_3E == 0) {
            frame = func_80025D18(work->unk_4E);
            if (frame == 12 || frame == 34 || frame == 56) {
                func_800FA2C0_MinigameInstructions(0x30C, work);
            }
        }
    } else if (mag <= 16.0f && (flags & 1)) {
        work->unk_3C = 1;
        motion = func_80025E48(work->unk_54);
        func_800FB590_MinigameInstructions(work, motion);
        if (work->unk_3E == 0) {
            frame = func_80025D18(work->unk_4E);
            if (frame == 12 || frame == 45) {
                func_800FA2C0_MinigameInstructions(0x30C, work);
            }
        }
    } else if (mag > 16.0f && (flags & 2)) {
        work->unk_3C = 2;
        motion = func_80025E48(work->unk_52);
        func_800FB60C_MinigameInstructions(work, motion);
        if (work->unk_3E == 0) {
            frame = func_80025D18(work->unk_4E);
            if (frame == 12) {
                func_800FA2C0_MinigameInstructions(0x30C, work);
            }
        }
    }
    if (ContBtnTrg[port] & 0x4000) {
        func_800FA300_MinigameInstructions(0x135, work);
        func_80025BB8(work->unk_4E, work->unk_5C);
        D_800F2B7C[work->unk_4E].unk_0C = -1;
        if (work->unk_3E == 0) {
            func_800258EC(work->unk_70, 0x4000, 0x4000);
            do {
                HuPrcVSleep();
                frame = func_80025D18(work->unk_4E);
                if (frame == 28) {
                    func_800258EC(work->unk_70, 0x4000, 0);
                }
            } while (frame != func_80025D40(work->unk_4E));
        } else {
            func_800FB4DC_MinigameInstructions(work->unk_4E);
        }
        work->unk_3C = 0;
        prev = -1;
        motion = func_80025E48(work->unk_50);
        if (work->unk_3E == 0) {
            func_80025C20(work->unk_4E, motion, 0, 8, 2);
            HuPrcSleep(8);
            func_800258EC(work->unk_70, 0x4000, 0x4000);
        }
    }
    if (prev != work->unk_3C) {
        func_80025C20(work->unk_4E, motion, 0, 8, 2);
    }
    if (D_800F2B7C[work->unk_4E].unk_0C == -1 && work->unk_3E == 0) {
        func_800258EC(work->unk_70, 0x4000, 0x4000);
    }
}
void func_80107F4C_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    u8 chr;

    chr = GwPlayer[work->unk_38].character;
    work->unk_3E = GwPlayer[work->unk_38].group;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9F, 0x299);
    work->unk_50 = func_80023FC8(work->unk_4E);
    func_800258EC(work->unk_50, 4, 4);
    work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 3, 0x1D);
    work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 1, 0x1D);
    work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x70, 0x1D);
    work->unk_58 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x6F, 0x1D);
    work->unk_5A = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x71, 0x1D);
    work->unk_08 = 78.0f;
    func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
    in.x = work->unk_00 = -50.0f;
    in.y = work->unk_04 = 150.0f;
    out.z = 0.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
}
void func_801080E4_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;

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
        HuPrcVSleep();
    }
    in.x = work->unk_00 = work->unk_08;
    func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
    func_80025C20(work->unk_4E, func_80025E48(work->unk_50), 0, 8, 2);
    work->unk_3C = 0;
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    work->unk_14 = -180.0f;
    work->unk_B6 = 0;
    work->unk_20 = 0.0f;
    work->unk_24 = 0.0f;
    work->unk_28 = 0.0f;
    HuPrcSleep(8);
}
void func_80108280_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s16 i;

    D_800F2B7C[work->unk_4E].unk_0C = -1;
    func_80025BB8(work->unk_4E, work->unk_52);
    for (i = 90; i < 270; i += 30) {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        HuPrcVSleep();
    }
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
void func_801083DC_MinigameInstructions(Ovl6FPlayerWork* work) {
    s16 i;

    if (ContBtnTrg[GwPlayer[work->unk_38].port] & 0x8000) {
        func_800FA300_MinigameInstructions(0x2FE, work);
        if (work->unk_B6 + 15 >= 70) {
            D_800F2B7C[work->unk_4E].unk_0C = -1;
            PlaySound(0x306);
            func_800FA3AC_MinigameInstructions(2, work);
            func_80025BB8(work->unk_4E, work->unk_5A);
            func_80025EB4(work->unk_4E, 2, 2);
            HuPrcSleep(30);
            func_80025C20(work->unk_4E, func_80025E48(work->unk_50), 0, 8, 2);
            HuPrcSleep(8);
            work->unk_B6 = 0;
            return;
        }
        D_800F2B7C[work->unk_4E].unk_0C = -1;
        func_80025BB8(work->unk_4E, work->unk_56);
        func_80025C20(work->unk_4E, func_80025E48(work->unk_58), 0, 0x48, 0);
        work->unk_B6 += 15;
        for (i = 0; i <= 180; i += 30) {
            func_80025798(work->unk_4E, work->unk_0C, func_800AEAC0(i) * 10.0f + work->unk_10, work->unk_14);
            D_800F2B7C[work->unk_4E].unk_12 = work->unk_B6;
            HuPrcVSleep();
        }
    } else if (work->unk_B6 != 0) {
        work->unk_B6--;
    }
    D_800F2B7C[work->unk_4E].unk_12 = work->unk_B6;
}
// register allocation, D_8010EF10 base CSE and one threaded branch (masked 37)
#ifdef NON_MATCHING
void func_80108624_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s16 model;
    s16 i;
    s16 chr;
    s32 side;

    chr = GwPlayer[work->unk_38].character;
    work->unk_3E = side = GwPlayer[work->unk_38].group;
    if (chr != 1) {
        work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9F, 0x299);
    } else {
        work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9E, 0x299);
    }
    work->unk_50 = LoadFormFile(D_8010EF10_MinigameInstructions[chr][1], 0x1D);
    work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 3, 0x1D);
    work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 1, 0x1D);
    work->unk_56 = LoadFormFile(D_8010EF10_MinigameInstructions[chr][1] + 1, 0x1D);
    work->unk_58 = LoadFormFile(D_8010EF10_MinigameInstructions[chr][1] + 2, 0x1D);
    work->unk_5A = LoadFormFile(D_8010EF10_MinigameInstructions[chr][1] + 3, 0x1D);
    work->unk_70 = LoadFormFile(D_8010EF10_MinigameInstructions[chr][0], 0x299);
    func_80025830(work->unk_70, 0.28f, 0.28f, 0.28f);
    func_800258EC(work->unk_70, 4, 4);
    work->unk_08 = D_8010EF40_MinigameInstructions[(s16)((u16)D_8010F76A_MinigameInstructions[side] + side * 2)];
    func_80025830(work->unk_4E, 0.28f, 0.28f, 0.28f);
    in.x = work->unk_00 = -50.0f;
    in.y = work->unk_04 = 150.0f;
    out.z = 0.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
    D_8010F4F6_MinigameInstructions[work->unk_38] = 0;
    if (side == 0 && D_8010F76A_MinigameInstructions[0] != 0) {
        D_8010F4F4_MinigameInstructions = work->unk_38;
    }
    if (D_8010F76A_MinigameInstructions[side] == 0) {
        if (side == 0) {
            model = D_8010F4F0_MinigameInstructions[0] = LoadFormFile(0x300007, 0x299);
        } else {
            model = D_8010F4F2_MinigameInstructions = LoadFormFile(0x300008, 0x299);
        }
        func_80025830(model, 0.28f, 0.28f, 0.28f);
        func_800257E4(model, 0.0f, 270.0f, 0.0f);
        in.x = side * 70 + 42;
        in.y = -20.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
        func_80025798(model, out.x, out.y, -180.0f);
    }
    work->unk_2C = D_800F2B7C[work->unk_4E].unk_24 - D_800F2B7C[D_8010F4F0_MinigameInstructions[side]].unk_24;
    work->unk_30 = D_800F2B7C[work->unk_4E].unk_2C - D_800F2B7C[D_8010F4F0_MinigameInstructions[side]].unk_2C;
    for (i = 0; i < 4; i++) {
        if (work->unk_38 != i && side == GwPlayer[i].group) {
            break;
        }
    }
    work->unk_B6 = i;
    D_8010F76A_MinigameInstructions[side]++;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_80108624_MinigameInstructions);
#endif
void func_80108A90_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    s16 i;

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
    for (i = 90; i < 270; i += 30) {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        if ((work->unk_42++ & 7) == 0) {
            func_800FA300_MinigameInstructions(0x112, work);
        }
        HuPrcVSleep();
    }
    func_80025C20(work->unk_4E, func_80025E48(work->unk_56), 0, 8, 2);
    work->unk_3C = 0;
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    work->unk_14 = -180.0f;
    func_800257E4(work->unk_70, 0.0f, 270.0f, 0.0f);
    func_80025798(work->unk_70, out.x, out.y, -180.0f);
    work->unk_20 = 0.0f;
    work->unk_24 = 90.0f;
    work->unk_28 = 0.0f;
    work->unk_BA = 0;
    work->unk_B8 = 0;
    D_8010F4F6_MinigameInstructions[work->unk_38] = 0;
    D_8010F4FE_MinigameInstructions[work->unk_3E] = 0;
    if (work->unk_38 < work->unk_B6) {
        D_8010F504_MinigameInstructions[work->unk_3E] = 270.0f;
        func_800257E4(D_8010F4F0_MinigameInstructions[work->unk_3E], 0.0f, 270.0f, 0.0f);
    }
    HuPrcSleep(8);
    if (work->unk_38 == 3) {
        func_800257E4(D_8010F4F0_MinigameInstructions[0], 0.0f, 270.0f, 0.0f);
        func_800257E4(D_8010F4F0_MinigameInstructions[1], 0.0f, 270.0f, 0.0f);
        for (i = -20; i < 150; i += 30) {
            in.y = i;
            in.x = 42.0f;
            func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
            func_80025798(D_8010F4F0_MinigameInstructions[0], out.x, out.y, -180.0f);
            in.x = 112.0f;
            func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
            func_80025798(D_8010F4F0_MinigameInstructions[1], out.x, out.y, -180.0f);
            HuPrcVSleep();
        }
        PlaySound(0x29C);
        in.y = 150.0f;
        in.x = 42.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
        func_80025798(D_8010F4F0_MinigameInstructions[0], out.x, out.y, -180.0f);
        in.x = 112.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
        func_80025798(D_8010F4F0_MinigameInstructions[1], out.x, out.y, -180.0f);
    }
    work->unk_2C = D_800F2B7C[work->unk_4E].unk_24 - D_800F2B7C[D_8010F4F0_MinigameInstructions[work->unk_3E]].unk_24;
    work->unk_30 = D_800F2B7C[work->unk_4E].unk_2C - D_800F2B7C[D_8010F4F0_MinigameInstructions[work->unk_3E]].unk_2C;
}
void func_80108FE4_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    Ovl6FPlayerWork* p;
    f32 x;
    f32 z;
    f32 scale;
    s16 i;

    if (D_8010F4F6_MinigameInstructions[work->unk_38] == 0) {
        func_80025C20(work->unk_4E, func_80025E48(work->unk_52), 0, 8, 2);
        if (work->unk_38 < work->unk_B6) {
            in.x = work->unk_3E * 70 + 42;
            for (i = 0; i < 8; i++) {
                in.y = 150 - i * 20;
                func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
                func_80025798(D_8010F4F0_MinigameInstructions[work->unk_3E], out.x, out.y, -180.0f);
                if ((work->unk_42++ & 7) == 0) {
                    func_800FA300_MinigameInstructions(0x112, work);
                }
                HuPrcVSleep();
            }
            in.y = -20.0f;
            func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
            func_80025798(D_8010F4F0_MinigameInstructions[work->unk_3E], out.x, out.y, -180.0f);
        } else {
            HuPrcSleep(8);
        }
        in.x = work->unk_00;
        in.y = work->unk_04;
        out.z = 0.0f;
        while (work->unk_00 > -50.0f) {
            in.x = work->unk_00 -= 12.0f;
            func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
            func_80025798(work->unk_4E, out.x, out.y, -180.0f);
            if ((work->unk_42++ & 3) == 0) {
                func_800FA300_MinigameInstructions(0x119, work);
            }
            HuPrcVSleep();
        }
    } else if (work->unk_38 <= work->unk_B6) {
        scale = 0.28f;
        do {
            if (work->unk_38 < work->unk_B6) {
                D_800F2B7C[D_8010F4F0_MinigameInstructions[work->unk_3E]].unk_2C += 10.0f;
                func_80025830(D_8010F4F0_MinigameInstructions[work->unk_3E], scale, scale, scale);
            }
            p = work;
            for (i = 0; i < 2; i++) {
                x = func_800AEFD0(90.0f) * p->unk_2C - func_800AEAC0(90.0f) * p->unk_30;
                z = func_800AEAC0(90.0f) * p->unk_2C + func_800AEFD0(90.0f) * p->unk_30;
                x *= scale;
                z *= scale;
                func_80025798(p->unk_70,
                              x + D_800F2B7C[D_8010F4F0_MinigameInstructions[p->unk_3E]].unk_24,
                              p->unk_10,
                              z + D_800F2B7C[D_8010F4F0_MinigameInstructions[p->unk_3E]].unk_2C);
                func_800257E4(p->unk_70, 0.0f, i, 0.0f);
                func_80025830(p->unk_70, scale, scale, scale);
                p = D_8010F750_MinigameInstructions[work->unk_B6];
            }
            HuPrcVSleep();
            scale -= 0.028f;
        } while (scale > 0.0f);
        func_80060758(0x299);
        func_80025830(D_8010F4F0_MinigameInstructions[work->unk_3E], 0.28f, 0.28f, 0.28f);
        in.x = work->unk_3E * 70 + 42;
        in.y = -20.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
        func_80025798(D_8010F4F0_MinigameInstructions[work->unk_3E], out.x, out.y, -180.0f);
        p = work;
        for (i = 0; i < 2; i++) {
            func_80025830(p->unk_70, 0.28f, 0.28f, 0.28f);
            func_800258EC(p->unk_70, 4, 4);
            in.x = p->unk_00 = -50.0f;
            in.y = p->unk_04 = 150.0f;
            func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
            func_80025798(p->unk_4E, out.x, out.y, -180.0f);
            p = D_8010F750_MinigameInstructions[work->unk_B6];
        }
    }
}
void func_80109600_MinigameInstructions(Ovl6FPlayerWork* work) {
    f32 angle;
    f32 angle2;
    f32 r;
    f32 dx;
    f32 x;
    f32 z;
    s16 rot;
    s16 port;

    port = GwPlayer[work->unk_38].port;
    if (D_8010F4F6_MinigameInstructions[work->unk_38] == 0) {
        if (ContBtnTrg[port] & 0x8000) {
            func_800FB60C_MinigameInstructions(work, func_80025E48(work->unk_58));
            D_8010F4FE_MinigameInstructions[work->unk_3E]++;
            if (D_8010F4FE_MinigameInstructions[work->unk_3E] >= 31) {
                D_8010F4F6_MinigameInstructions[work->unk_38] = 1;
                D_8010F4F6_MinigameInstructions[work->unk_B6] = 1;
                return;
            }
            if (work->unk_BA <= 0) {
                func_80025C20(work->unk_4E, func_80025E48(work->unk_58), 0, 4, 2);
            }
            work->unk_BA = 8;
            return;
        }
        if (work->unk_BA != 0) {
            if (--work->unk_BA == 0) {
                func_80025C20(work->unk_4E, func_80025E48(work->unk_56), 0, 4, 2);
            }
        }
    } else if (D_8010F4F6_MinigameInstructions[work->unk_38] == 1) {
        func_80025BB8(work->unk_4E, work->unk_5A);
        func_800FB4DC_MinigameInstructions(work->unk_4E);
        PlaySound(0x2A1);
        func_800258EC(work->unk_4E, 4, 4);
        func_800258EC(work->unk_70, 4, 0);
        D_8010F4F6_MinigameInstructions[work->unk_38] = 2;
        for (rot = 270; rot >= 180; rot -= 15) {
            if (work->unk_38 < work->unk_B6) {
                D_8010F504_MinigameInstructions[work->unk_3E] = r = rot;
                func_800257E4(D_8010F4F0_MinigameInstructions[work->unk_3E], 0.0f, r, 0.0f);
            }
            angle = 270 - rot;
            x = func_800AEFD0(angle) * work->unk_2C - func_800AEAC0(angle) * work->unk_30;
            z = func_800AEAC0(angle) * work->unk_2C + func_800AEFD0(angle) * work->unk_30;
            func_80025798(work->unk_70, x + D_800F2B7C[D_8010F4F0_MinigameInstructions[work->unk_3E]].unk_24, work->unk_10,
                          z + D_800F2B7C[D_8010F4F0_MinigameInstructions[work->unk_3E]].unk_2C);
            func_800257E4(work->unk_70, 0.0f, rot, 0.0f);
            HuPrcVSleep();
        }
        PlaySound(0x299);
    } else if (D_8010F4F6_MinigameInstructions[work->unk_38] == 2) {
        dx = (s8)(ContStkX[port] / 10);
        D_8010F504_MinigameInstructions[work->unk_3E] -= dx * 0.1f;
        if (D_8010F504_MinigameInstructions[work->unk_3E] > 210.0f) {
            D_8010F504_MinigameInstructions[work->unk_3E] = 210.0f;
        }
        if (D_8010F504_MinigameInstructions[work->unk_3E] < 150.0f) {
            D_8010F504_MinigameInstructions[work->unk_3E] = 150.0f;
        }
        if (work->unk_38 < work->unk_B6) {
            func_800257E4(D_8010F4F0_MinigameInstructions[work->unk_3E], 0.0f, D_8010F504_MinigameInstructions[work->unk_3E], 0.0f);
        }
        rot = D_8010F504_MinigameInstructions[work->unk_3E];
        angle2 = 270 - rot;
        x = func_800AEFD0(angle2) * work->unk_2C - func_800AEAC0(angle2) * work->unk_30;
        z = func_800AEAC0(angle2) * work->unk_2C + func_800AEFD0(angle2) * work->unk_30;
        func_80025798(work->unk_70, x + D_800F2B7C[D_8010F4F0_MinigameInstructions[work->unk_3E]].unk_24, work->unk_10,
                      z + D_800F2B7C[D_8010F4F0_MinigameInstructions[work->unk_3E]].unk_2C);
        func_800257E4(work->unk_70, 0.0f, rot, 0.0f);
    }
}
void func_80109BFC_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;

    if ((work->unk_3E = GwPlayer[work->unk_38].group) == 0) {
        work->unk_4E = LoadFormFile(0x35, 0x299);
        work->unk_70 = LoadFormFile(0xB000C, 0x299);
        work->unk_08 = 48.0f;
        func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
        in.x = work->unk_00 = -50.0f;
        in.y = work->unk_04 = 85.0f;
        work->unk_14 = -230.0f;
        out.z = 0.0f;
        func_8001DD24(0, CZoom - work->unk_14, (Vec3f*)&in, &out);
        func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
        func_80025830(work->unk_70, 0.2f, 0.2f, 0.2f);
        in.x = work->unk_2C = 10.0f;
        in.y = work->unk_30 = 248.0f;
        work->unk_34 = -180.0f;
        func_8001DD24(0, CZoom - -180.0f, (Vec3f*)&in, &out);
        func_80025798(work->unk_70, out.x, out.y, work->unk_34);
        func_800258EC(work->unk_70, 4, 4);
        func_80025EB4(work->unk_4E, 1, 1);
    }
}
void func_80109DB0_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    f32 dy;

    if (work->unk_3E == 0) {
        func_800258EC(work->unk_70, 4, 0);
        out.z = 0.0f;
        dy = out.z;
        while (work->unk_00 < work->unk_08) {
            in.x = work->unk_00;
            in.y = work->unk_04;
            func_8001DD24(0, CZoom - work->unk_14, (Vec3f*)&in, &out);
            func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
            dy += 8.0f;
            if (dy > 60.0f) {
                dy = 60.0f;
            }
            in.x = work->unk_2C;
            in.y = work->unk_30 - dy;
            func_8001DD24(0, CZoom - work->unk_34, (Vec3f*)&in, &out);
            func_80025798(work->unk_70, out.x, out.y, work->unk_34);
            work->unk_00 += 12.0f;
            HuPrcVSleep();
        }
        in.x = work->unk_00 = work->unk_08;
        in.y = work->unk_04;
        func_8001DD24(0, CZoom - work->unk_14, (Vec3f*)&in, &out);
        func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
        work->unk_B6 = 0;
    }
}
void func_80109F68_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    f32 dy;

    if (work->unk_3E == 0) {
        out.z = 0.0f;
        dy = 60.0f;
        while (work->unk_00 > -50.0f) {
            in.x = work->unk_00 -= 12.0f;
            in.y = work->unk_04;
            func_8001DD24(0, CZoom - work->unk_14, (Vec3f*)&in, &out);
            func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
            dy -= 8.0f;
            if (dy < 0.0f) {
                dy = 0.0f;
            }
            in.x = work->unk_2C;
            in.y = work->unk_30 - dy;
            func_8001DD24(0, CZoom - work->unk_34, (Vec3f*)&in, &out);
            func_80025798(work->unk_70, out.x, out.y, work->unk_34);
            HuPrcVSleep();
        }
    }
}
void func_8010A0D4_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    f32 a;
    f32 dir;
    s16 dx;
    s16 port;

    if (work->unk_3E == 0) {
        port = GwPlayer[work->unk_38].port;
        dx = (s8)(ContStkX[port] / 10);
        if (ContBtnTrg[port] & 0x8000) {
            in.x = work->unk_00;
            for (a = 0.0f; a <= 90.0f; a += 10.0f) {
                in.y = (80.0f - func_800AEFD0(a) * 80.0f) + work->unk_04;
                func_8001DD24(0, CZoom - work->unk_14, (Vec3f*)&in, &out);
                func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
                HuPrcVSleep();
            }
            HuPrcSleep(15);
            for (a = 0.0f; a <= 90.0f; a += 10.0f) {
                in.y = work->unk_04 - func_800AEFD0(a) * 120.0f;
                func_8001DD24(0, CZoom - work->unk_14, (Vec3f*)&in, &out);
                func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
                HuPrcVSleep();
            }
        } else if (dx != 0) {
            dir = 0.0f;
            if (dx > 0 && work->unk_B6 == 0) {
                dir = 1.0f;
            } else if (dx < 0 && work->unk_B6 != 0) {
                dir = -1.0f;
            }
            if (dir != 0.0f) {
                func_800FA284_MinigameInstructions(0x21B);
                in.y = work->unk_04;
                for (a = 0.0f; a < 76.0f; a += 20.0f) {
                    in.x = dir * a + work->unk_00;
                    func_8001DD24(0, CZoom - work->unk_14, (Vec3f*)&in, &out);
                    func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
                    HuPrcVSleep();
                }
                in.x = work->unk_00 = dir * 76.0f + work->unk_00;
                func_8001DD24(0, CZoom - work->unk_14, (Vec3f*)&in, &out);
                func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
                work->unk_B6 = work->unk_B6 + dir;
                HuPrcSleep(2);
            }
        }
    }
}
void func_8010A43C_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f in;
    Vec3f out;
    u8 chr;

    chr = GwPlayer[work->unk_38].character;
    work->unk_3E = GwPlayer[work->unk_38].group;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x9F, 0x299);
    work->unk_50 = func_80023FC8(work->unk_4E);
    func_800258EC(work->unk_50, 4, 4);
    work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 3, 0x1D);
    work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 1, 0x1D);
    work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x5A, 0x1D);
    work->unk_58 = LoadFormFile((D_8010E964_MinigameInstructions[chr] << 16) | 0x5B, 0x1D);
    work->unk_08 = (work->unk_38 * 35) + 25;
    func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
    in.x = work->unk_00 = -50.0f;
    in.y = work->unk_04 = 150.0f;
    out.z = 0.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&in, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
}

void func_8010A5D4_MinigameInstructions(Ovl6FPlayerWork* work) {
    s16 stick = (s8)(ContStkX[GwPlayer[work->unk_38].port] / 50);

    if (work->unk_B2 == 0) {
        work->unk_B8 = -1;
    }
    if (stick > 0 && (work->unk_B8 == -1 || work->unk_B8 == 0)) {
        func_800FA2C0_MinigameInstructions(0x2F1, work);
        func_80025C20(work->unk_4E, func_80025E48(work->unk_56), 0, 4, 0);
        work->unk_B8 = 1;
    } else if (stick < 0 && (work->unk_B8 == 1 || work->unk_B8 == -1)) {
        func_800FA2C0_MinigameInstructions(0x2F2, work);
        func_80025C20(work->unk_4E, func_80025E48(work->unk_58), 0, 4, 0);
        work->unk_B8 = 0;
    } else {
        return;
    }
    do {
        HuPrcVSleep();
    } while (D_800F2B7C[work->unk_4E].unk_0C != -1);
    func_800FB4DC_MinigameInstructions(work->unk_4E);
}

void func_8010A75C_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16* bank;
    s32 ch;

    ch = GwPlayer[work->unk_38].character;
    work->unk_3E = GwPlayer[work->unk_38].group;
    if (work->unk_3E & 1) {
        func_800FC008_MinigameInstructions(work);
        return;
    }
    bank = &D_8010E964_MinigameInstructions[ch];
    work->unk_4E = LoadFormFile((*bank << 16) | 0x9F, 0x299);
    work->unk_50 = func_80023FC8(work->unk_4E);
    func_800258EC(work->unk_50, 4, 4);
    work->unk_52 = LoadFormFile((*bank << 16) | 3, 0x1D);
    work->unk_54 = LoadFormFile((*bank << 16) | 1, 0x1D);
    work->unk_56 = LoadFormFile((*bank << 16) | 0x31, 0x1D);
    work->unk_70 = LoadFormFile(0x3F0003, 0x289);
    func_80025798(work->unk_70, -10000.0f, 0.0f, 0.0f);
    func_8002859C(work->unk_70, work->unk_4E, D_8010F360_MinigameInstructions);
    work->unk_08 = (work->unk_38 * 0x23) + 0x19;
    func_80025830(work->unk_4E, 0.4f, 0.4f, 0.4f);
    pos.x = work->unk_00 = -50.0f;
    pos.y = work->unk_04 = 150.0f;
    out.z = 0.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
}
void func_8010A938_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 rot;

    if (work->unk_3E & 1) {
        func_800FA9EC_MinigameInstructions(work);
        return;
    }
    func_800258EC(work->unk_4E, 4, 0);
    func_800258EC(work->unk_70, 0x4000, 0x4000);
    func_80025BB8(work->unk_4E, work->unk_52);
    func_80025EB4(work->unk_4E, 2, 2);
    func_800257E4(work->unk_4E, 0.0f, 90.0f, 0.0f);
    pos.x = work->unk_00;
    pos.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 < work->unk_08) {
        pos.x = work->unk_00 = work->unk_00 + 12.0f;
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
    for (rot = 90; rot >= 0; rot -= 30) {
        func_800257E4(work->unk_4E, 0.0f, rot, 0.0f);
        if ((work->unk_42++ & 7) == 0) {
            func_800FA300_MinigameInstructions(0x112, work);
        }
        HuPrcVSleep();
    }
    func_80025C20(work->unk_4E, func_80025E48(work->unk_56), 0, 8, 1);
    work->unk_3C = 0;
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    work->unk_14 = -180.0f;
    work->unk_B6 = 0;
    work->unk_20 = 0.0f;
    work->unk_24 = 0.0f;
    work->unk_28 = 0.0f;
    work->unk_44 = -1;
    HuPrcSleep(8);
}
void func_8010ABA4_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 rot;

    if (work->unk_3E & 1) {
        func_800FAC2C_MinigameInstructions(work);
        return;
    }
    rot = 0;
    func_80025C20(work->unk_4E, func_80025E48(work->unk_52), 0, 8, 2);
    HuPrcSleep(8);
    do {
        func_800257E4(work->unk_4E, 0.0f, rot, 0.0f);
        if ((work->unk_42++ & 7) == 0) {
            func_800FA300_MinigameInstructions(0x112, work);
        }
        HuPrcVSleep();
        rot -= 30;
    } while (rot >= -90);
    pos.x = work->unk_00;
    pos.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 > -50.0f) {
        pos.x = work->unk_00 = work->unk_00 - 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_4E, out.x, out.y, -180.0f);
        if ((work->unk_42++ & 3) == 0) {
            func_800FA300_MinigameInstructions(0x119, work);
        }
        HuPrcVSleep();
    }
}
extern s8 ContStkY[4];

void func_8010AD60_MinigameInstructions(Ovl6FPlayerWork* work) {
    s32 port;

    if (work->unk_3E & 1) {
        func_800FC558_MinigameInstructions(work);
        return;
    }
    port = GwPlayer[work->unk_38].port;
    if (func_80009E4C(port, 0x10, ContStkX[port], ContStkY[port]) != 0) {
        if (work->unk_B4 == 0) {
            func_80025BB8(work->unk_4E, work->unk_56);
            work->unk_44 = func_800FA2C0_MinigameInstructions(0x342, work);
        }
        func_80025CA8(work->unk_4E, work->unk_B4);
        work->unk_B4 += 2;
        if (func_80025D40(work->unk_4E) <= work->unk_B4) {
            work->unk_B4 = 0;
        }
    } else {
        func_80025EB4(work->unk_4E, 1, 1);
        if (work->unk_44 != -1) {
            func_800FA380_MinigameInstructions(work->unk_44);
            work->unk_44 = -1;
        }
    }
}
void func_8010AEA0_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    f32 scale;
    s32 ch;
    s16 group;
    u16 model;
    s16 model2;

    ch = GwPlayer[work->unk_38].character;
    group = GwPlayer[work->unk_38].group;
    work->unk_3E = group;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x9F, 0x299);
    work->unk_50 = func_80023FC8(work->unk_4E);
    func_800258EC(work->unk_50, 4, 4);
    work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 3, 0x1D);
    work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 1, 0x1D);
    scale = 1.0f;
    work->unk_1C = scale;
    switch (group) {
        case 0:
            work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x83, 0x1D);
            work->unk_58 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x84, 0x1D);
            work->unk_5A = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x85, 0x1D);
            work->unk_5C = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x86, 0x1D);
            work->unk_5E = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x9D, 0x1D);
            break;
        case 1:
            work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x8B, 0x1D);
            work->unk_58 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x91, 0x1D);
            work->unk_5E = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x8C, 0x1D);
            break;
        case 2:
            work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x88, 0x1D);
            work->unk_5E = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x89, 0x1D);
            break;
        case 3:
            work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x8E, 0x1D);
            work->unk_5E = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x8F, 0x1D);
            break;
    }
    work->unk_08 = (work->unk_38 * 0x23) + 0x19;
    func_80025830(work->unk_4E, scale * 0.4f, scale * 0.4f, scale * 0.4f);
    pos.x = work->unk_00 = -50.0f;
    pos.y = work->unk_04 = 150.0f;
    out.z = 0.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
    pos.x = work->unk_08;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    out.z = -180.0f;
    model = LoadFormFile(D_8010EF48_MinigameInstructions[group], 0x299);
    work->unk_70 = model;
    func_80025798(model, out.x, out.y, out.z);
    func_80025830(model, 0.0f, 0.0f, 0.0f);
    work->unk_72 = work->unk_74 = work->unk_76 = -1;
    switch (group) {
        case 0:
            func_8002859C(model, work->unk_4E, D_8010F360_MinigameInstructions);
            func_800258EC(model, 0x4000, 0x4000);
            break;
        case 1:
            func_80025798(model, out.x, out.y, scale * 28.0f + out.z);
            model = LoadFormFile(0x3A0007, 0x299);
            work->unk_72 = model;
            func_80025830(model, 0.0f, 0.0f, 0.0f);
            func_80025798(model, out.x, out.y, out.z);
            model2 = func_80023FC8(model);
            work->unk_74 = model2;
            func_80025830(model2, 0.0f, 0.0f, 0.0f);
            func_8002859C(model2, work->unk_4E, D_8010F360_MinigameInstructions);
            func_800258EC(model2, 0x4000, 0x4000);
            work->unk_60 = LoadFormFile(0x3A0008, 0x1D);
            work->unk_62 = LoadFormFile(0x3A0009, 0x1D);
            func_80025BB8(work->unk_72, work->unk_60);
            break;
        case 2:
            func_8002859C(model, work->unk_4E, D_8010F360_MinigameInstructions);
            func_800258EC(model, 0x4000, 0x4000);
            model = LoadFormFile(0x3A0004, 0x299);
            work->unk_72 = model;
            func_80025EB4(model, 2, 2);
            func_80025798(model, out.x, out.y, out.z);
            func_80025830(model, 0.0f, 0.0f, 0.0f);
            break;
        case 3:
            func_8002859C(model, work->unk_4E, D_8010F360_MinigameInstructions);
            func_800258EC(model, 0x4000, 0x4000);
            break;
    }
}
void func_8010B44C_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 rot;
    f32 scale;

    func_80025BB8(work->unk_4E, work->unk_52);
    func_80025EB4(work->unk_4E, 2, 2);
    func_800257E4(work->unk_4E, 0.0f, 90.0f, 0.0f);
    pos.x = work->unk_00;
    pos.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 < work->unk_08) {
        pos.x = work->unk_00 = work->unk_00 + 12.0f;
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
    if (work->unk_3E == 0) {
        rot = 90;
        do {
            func_800257E4(work->unk_4E, 0.0f, rot, 0.0f);
            if ((work->unk_42++ & 7) == 0) {
                func_800FA300_MinigameInstructions(0x112, work);
            }
            HuPrcVSleep();
            rot += 30;
        } while (rot <= 180);
    } else {
        rot = 90;
        do {
            func_800257E4(work->unk_4E, 0.0f, rot, 0.0f);
            if ((work->unk_42++ & 7) == 0) {
                func_800FA300_MinigameInstructions(0x112, work);
            }
            HuPrcVSleep();
            rot -= 30;
        } while (rot >= 0);
    }
    func_80025C20(work->unk_4E, func_80025E48(work->unk_5E), 0, 8, 2);
    work->unk_3C = 0;
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    work->unk_14 = -180.0f;
    work->unk_B6 = 0;
    work->unk_20 = 0.0f;
    work->unk_24 = 0.0f;
    work->unk_28 = 0.0f;
    work->unk_B6 = -1;
    for (rot = 0; rot < 9; rot++) {
        HuPrcVSleep();
        scale = (rot / 8.0f) * work->unk_1C * 0.4f;
        if (work->unk_70 != -1) {
            func_80025830(work->unk_70, scale, scale, scale);
        }
        if (work->unk_72 != -1) {
            func_80025830(work->unk_72, scale, scale, scale);
        }
        if (work->unk_74 != -1) {
            func_80025830(work->unk_74, scale, scale, scale);
        }
        if (work->unk_76 != -1) {
            func_80025830(work->unk_76, scale, scale, scale);
        }
    }
}
void func_8010B7EC_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s16 rot;
    f32 scale;

    func_80025C20(work->unk_4E, func_80025E48(work->unk_52), 0, 8, 2);
    for (rot = 0; rot < 9; rot++) {
        HuPrcVSleep();
        scale = (1.0f - rot / 8.0f) * work->unk_1C * 0.4f;
        if (work->unk_70 != -1) {
            func_80025830(work->unk_70, scale, scale, scale);
        }
        if (work->unk_72 != -1) {
            func_80025830(work->unk_72, scale, scale, scale);
        }
        if (work->unk_74 != -1) {
            func_80025830(work->unk_74, scale, scale, scale);
        }
        if (work->unk_76 != -1) {
            func_80025830(work->unk_76, scale, scale, scale);
        }
    }
    if (work->unk_3E == 0) {
        rot = 180;
        do {
            func_800257E4(work->unk_4E, 0.0f, rot, 0.0f);
            if ((work->unk_42++ & 7) == 0) {
                func_800FA300_MinigameInstructions(0x112, work);
            }
            HuPrcVSleep();
            rot += 30;
        } while (rot <= 270);
    } else {
        rot = 0;
        do {
            func_800257E4(work->unk_4E, 0.0f, rot, 0.0f);
            if ((work->unk_42++ & 7) == 0) {
                func_800FA300_MinigameInstructions(0x112, work);
            }
            HuPrcVSleep();
            rot -= 30;
        } while (rot >= -90);
    }
    pos.x = work->unk_00;
    pos.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 > -50.0f) {
        pos.x = work->unk_00 = work->unk_00 - 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_4E, out.x, out.y, -180.0f);
        if ((work->unk_42++ & 3) == 0) {
            func_800FA300_MinigameInstructions(0x119, work);
        }
        HuPrcVSleep();
    }
}
void func_8010BB04_MinigameInstructions(Ovl6FPlayerWork* work) {
    s32 port;
    s16 x;
    s16 y;
    f32 angle;

    port = GwPlayer[work->unk_38].port;
    switch (work->unk_3E) {
        case 0:
            x = (s8)(ContStkX[port] / 20);
            y = (s8)(ContStkY[port] / 20);
            if ((f32)(x * x + y * y) == 0.0f) {
                break;
            }
            angle = func_800B0CD8(x, -y);
            if ((angle >= -45.0f) & (angle <= 45.0f)) {
                if (work->unk_B6 == 0) {
                    break;
                }
                work->unk_B6 = 0;
                func_80025C20(work->unk_4E, func_80025E48(work->unk_5A), 0, 8, 2);
            } else if ((angle >= -135.0f) & (angle <= -45.0f)) {
                if (work->unk_B6 == 1) {
                    break;
                }
                work->unk_B6 = 1;
                func_80025C20(work->unk_4E, func_80025E48(work->unk_58), 0, 8, 2);
            } else if ((angle >= 45.0f) & (angle <= 135.0f)) {
                if (work->unk_B6 == 2) {
                    break;
                }
                work->unk_B6 = 2;
                func_80025C20(work->unk_4E, func_80025E48(work->unk_5C), 0, 8, 2);
            } else {
                if (work->unk_B6 == 3) {
                    break;
                }
                work->unk_B6 = 3;
                func_80025C20(work->unk_4E, func_80025E48(work->unk_56), 0, 8, 2);
            }
            func_800FA2C0_MinigameInstructions(0x2E4, work);
            do {
                HuPrcVSleep();
            } while (D_800F2B7C[work->unk_4E].unk_0C != -1);
            break;
        case 1:
            if (ContBtnTrg[port] & 0x8000) {
                if (work->unk_B6 & 1) {
                    func_800FA2C0_MinigameInstructions(0x2E3, work);
                    func_80025BB8(work->unk_4E, work->unk_56);
                    func_80025BB8(work->unk_72, work->unk_62);
                } else {
                    func_800FA2C0_MinigameInstructions(0x2E3, work);
                    func_80025BB8(work->unk_4E, work->unk_58);
                    func_80025BB8(work->unk_72, work->unk_60);
                }
                work->unk_B6++;
                func_800FB4DC_MinigameInstructions(work->unk_4E);
                func_80025BB8(work->unk_4E, work->unk_5E);
                func_80025EB4(work->unk_4E, 2, 2);
            }
            break;
        case 2:
            if (ContBtnTrg[port] & 0x8000) {
                func_800FA2C0_MinigameInstructions(0x2E2, work);
                func_80025BB8(work->unk_4E, work->unk_56);
                func_800FB4DC_MinigameInstructions(work->unk_4E);
                func_80025BB8(work->unk_4E, work->unk_5E);
                func_80025EB4(work->unk_4E, 2, 2);
            }
            break;
        case 3:
            if (ContBtnTrg[port] & 0x8000) {
                func_800FA2C0_MinigameInstructions(0x2E1, work);
                func_80025BB8(work->unk_4E, work->unk_56);
                func_800FB4DC_MinigameInstructions(work->unk_4E);
                func_80025BB8(work->unk_4E, work->unk_5E);
                func_80025EB4(work->unk_4E, 2, 2);
            }
            break;
    }
}
// register allocation: a copy of group takes s5 (one extra saved register), store/move order (masked 20)
#ifdef NON_MATCHING
void func_8010BF20_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s32 ch;
    s16 group;
    s32 other;
    s16* count;
    u16 m0;
    u16 m1;
    s16 i;
    s32 pad[8]; /* unused: retail's frame is 0x60 */

    ch = GwPlayer[work->unk_38].character;
    group = GwPlayer[work->unk_38].group;
    work->unk_3E = group;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x9F, 0x299);
    work->unk_50 = func_80023FC8(work->unk_4E);
    func_800258EC(work->unk_50, 4, 4);
    work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 3, 0x1D);
    work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 1, 0x1D);
    work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x2E, 0x1D);
    count = &D_8010F76A_MinigameInstructions[group];
    work->unk_08 = D_8010EF58_MinigameInstructions[(s16)(*count + group * 2)];
    func_80025830(work->unk_4E, 0.28f, 0.28f, 0.28f);
    pos.x = work->unk_00 = -50.0f;
    pos.y = work->unk_04 = 150.0f;
    out.z = 0.0f;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
    if (*count == 0) {
        other = group ^ 1;
        if (D_8010EF60_MinigameInstructions == 0) {
            m0 = LoadFormFile(0x430003, 0x299);
            D_8010F50C_MinigameInstructions[group].unk_00 = m0;
            m1 = LoadFormFile(0x430004, 0x299);
            D_8010F50C_MinigameInstructions[group].unk_02 = m1;
            D_8010EF60_MinigameInstructions = 1;
        } else {
            m0 = func_80023FC8(D_8010F50C_MinigameInstructions[other].unk_00);
            D_8010F50C_MinigameInstructions[group].unk_00 = m0;
            m1 = func_80023FC8(D_8010F50C_MinigameInstructions[other].unk_02);
            D_8010F50C_MinigameInstructions[group].unk_02 = m1;
        }
        func_80025830(m0, 0.0f, 0.0f, 0.0f);
        func_80025830(m1, 0.0f, 0.0f, 0.0f);
        func_800257E4(m0, 0.0f, 270.0f, 0.0f);
        func_800257E4(m1, 0.0f, 270.0f, 0.0f);
        pos.x = group * 70 + 42;
        pos.y = work->unk_04 = 150.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(m0, out.x, out.y, -180.0f);
        func_80025798(m1, out.x, out.y, -180.0f);
        D_8010F524_MinigameInstructions[group] = 1.0f;
        D_8010F530_MinigameInstructions[group] = 0.0f;
        D_8010F52C_MinigameInstructions = func_80025D40(D_8010F50C_MinigameInstructions[group].unk_02);
    }
    /* retail indexes the model pairs as an s16 array here (group 1 reads pair 0's second model) */
    work->unk_2C = D_800F2B7C[work->unk_4E].unk_24 - D_800F2B7C[(&D_8010F50C_MinigameInstructions[0].unk_00)[group]].unk_24;
    work->unk_30 = D_800F2B7C[work->unk_4E].unk_2C - D_800F2B7C[(&D_8010F50C_MinigameInstructions[0].unk_00)[group]].unk_2C;
    for (i = 0; i < 4; i++) {
        if (work->unk_38 != i && group == GwPlayer[i].group) {
            break;
        }
    }
    work->unk_B6 = i;
    D_8010F76A_MinigameInstructions[group]++;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_8010BF20_MinigameInstructions);
#endif
/* D_8010F50C's model pairs as two s16 arrays with stride 2 (retail addresses D_8010F50C and
   D_8010F50E as separate bases; the pair halves are s16 so this is endian-neutral). */
#define OVL6F_F50C(g) ((&D_8010F50C_MinigameInstructions[0].unk_00)[(g) * 2])
#define OVL6F_F50E(g) ((&D_8010F50C_MinigameInstructions[0].unk_02)[(g) * 2])

// register allocation: v0/v1 swapped around the D_8010F514 store (masked 0, raw 6)
#ifdef NON_MATCHING
void func_8010C3A4_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    Ovl6FPlayerWork* partner;
    s16 rot;
    s16 frame;
    f32 t;

    func_800258EC(work->unk_4E, 4, 0);
    func_80025BB8(work->unk_4E, work->unk_52);
    func_80025EB4(work->unk_4E, 2, 2);
    func_800257E4(work->unk_4E, 0.0f, 90.0f, 0.0f);
    func_800A2A50(D_800F2B7C[work->unk_4E].unk7C);
    pos.x = work->unk_00;
    pos.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 < work->unk_08) {
        pos.x = work->unk_00 = work->unk_00 + 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        work->unk_0C = out.x;
        work->unk_10 = out.y;
        func_80025798(work->unk_4E, out.x, out.y, -180.0f);
        if ((work->unk_42++ & 3) == 0) {
            func_800FA300_MinigameInstructions(0x119, work);
        }
        HuPrcVSleep();
    }
    pos.x = work->unk_00 = work->unk_08;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    func_80025798(work->unk_4E, out.x, out.y, -180.0f);
    if (work->unk_38 > work->unk_B6) {
        s32 g = work->unk_3E;
        f32* speed = D_8010F514_MinigameInstructions;

        speed = g + speed;
        *speed = 0.0f;
        func_80025CA8(OVL6F_F50E(work->unk_3E), *speed);
        rot = 90;
        do {
            func_800257E4(work->unk_4E, 0.0f, rot, 0.0f);
            if ((work->unk_42++ & 7) == 0) {
                func_800FA300_MinigameInstructions(0x112, work);
            }
            HuPrcVSleep();
            rot += 30;
        } while (rot < 270);
    }
    frame = 0;
    if (work->unk_38 < work->unk_B6) {
        work->unk_B8 = 0;
        work->unk_B4 = 0;
    } else {
        work->unk_B8 = 1;
        frame = func_80025D40(work->unk_56);
        work->unk_B4 = frame;
    }
    func_80025C20(work->unk_4E, func_80025E48(work->unk_56), frame, 8, 0);
    D_800F2B7C[OVL6F_F50E(work->unk_3E)].unk_4C = 0.0f;
    D_800F2B7C[work->unk_4E].unk_58 = 0.0f;
    func_80025EB4(OVL6F_F50E(work->unk_3E), 1, 0);
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    work->unk_14 = -180.0f;
    work->unk_20 = 0.0f;
    work->unk_24 = 0.0f;
    work->unk_28 = 0.0f;
    partner = D_8010F750_MinigameInstructions[work->unk_B6];
    work->unk_BA = 0;
    pos.x = work->unk_08;
    work->unk_44 = -1;
    if (work->unk_38 > work->unk_B6) {
        func_800A2A50(D_800F2B7C[OVL6F_F50E(work->unk_3E)].unk7C);
        D_8010F530_MinigameInstructions[work->unk_3E] = 0.0f;
        for (frame = 0; frame < 9; frame++) {
            HuPrcVSleep();
            t = frame / 8.0f;
            pos.y = work->unk_04 - t * 32.0f;
            func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
            func_80025798(work->unk_4E, out.x, out.y, -180.0f);
            func_80025798(partner->unk_4E, partner->unk_0C, out.y, partner->unk_14);
            t *= 0.28f;
            func_80025830(OVL6F_F50C(work->unk_3E), 0.28f, t, 0.28f);
            func_80025830(OVL6F_F50E(work->unk_3E), 0.28f, t, 0.28f);
        }
        partner->unk_BA = 1;
    } else {
        while (work->unk_BA == 0) {
            HuPrcVSleep();
        }
    }
    work->unk_BC = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_MinigameInstructions/2E8220", func_8010C3A4_MinigameInstructions);
#endif
void func_8010C8CC_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    Ovl6FPlayerWork* partner;
    s16 frame;
    f32 t;

    func_800A2A50(D_800F2B7C[work->unk_4E].unk7C);
    func_80025C20(work->unk_4E, func_80025E48(work->unk_52), 0, 8, 2);
    partner = D_8010F750_MinigameInstructions[work->unk_B6];
    work->unk_BA = 0;
    pos.x = work->unk_08;
    if (work->unk_38 > work->unk_B6) {
        frame = 0;
        do {
            HuPrcVSleep();
            t = 1.0f - frame / 8.0f;
            pos.y = work->unk_04 - t * 32.0f;
            func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
            func_80025798(work->unk_4E, out.x, out.y, -180.0f);
            func_80025798(partner->unk_4E, partner->unk_0C, out.y, partner->unk_14);
            t *= 0.28f;
            func_80025830(OVL6F_F50C(work->unk_3E), 0.28f, t, 0.28f);
            func_80025830(OVL6F_F50E(work->unk_3E), 0.28f, t, 0.28f);
            frame++;
        } while (frame < 9);
        func_80025830(OVL6F_F50C(work->unk_3E), 0.0f, 0.0f, 0.0f);
        func_80025830(OVL6F_F50E(work->unk_3E), 0.0f, 0.0f, 0.0f);
        partner->unk_BA = 1;
    } else {
        while (work->unk_BA == 0) {
            HuPrcVSleep();
        }
    }
    frame = 0;
    do {
        func_800257E4(work->unk_4E, 0.0f, frame, 0.0f);
        if ((work->unk_42++ & 7) == 0) {
            func_800FA300_MinigameInstructions(0x112, work);
        }
        HuPrcVSleep();
        frame -= 15;
    } while (frame >= -90);
    pos.x = work->unk_00;
    pos.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 > -50.0f) {
        pos.x = work->unk_00 = work->unk_00 - 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_4E, out.x, out.y, -180.0f);
        if ((work->unk_42++ & 3) == 0) {
            func_800FA300_MinigameInstructions(0x119, work);
        }
        HuPrcVSleep();
    }
}
/* D_8010F538[i]'s low half; the header's D_8010F538_LO16 addresses it as a halfword pointer,
   retail as a field at +2 of each word (one base register). */
#define OVL6F_F538_LO16(i) (((Ovl6FPairS16*)D_8010F538_MinigameInstructions)[i].unk_02)

void func_8010CC54_MinigameInstructions(Ovl6FPlayerWork* work) {
    s16 port;
    Ovl6FPlayerWork* partner;
    s16 side;
    s16 sum;
    u16 model;

    port = GwPlayer[work->unk_38].port;
    partner = D_8010F750_MinigameInstructions[work->unk_B6];
    side = work->unk_3E;
    if (ContBtnTrg[port] & 0x8000) {
        D_8010F514_MinigameInstructions[side] += 0.3f;
        if (D_8010F514_MinigameInstructions[work->unk_3E] > 5.0f) {
            D_8010F514_MinigameInstructions[work->unk_3E] = 5.0f;
        }
    }
    D_8010F538_MinigameInstructions[work->unk_38] = (s8)(ContStkY[port] / 10);
    if (work->unk_38 > work->unk_B6) {
        sum = OVL6F_F538_LO16(work->unk_38);
        sum += OVL6F_F538_LO16(work->unk_B6);
        if (sum != 0) {
            D_8010F530_MinigameInstructions[side] = sum / 15.0f * 15.0f;
            if (D_8010F530_MinigameInstructions[side] > 15.0f) {
                D_8010F530_MinigameInstructions[side] = 15.0f;
            }
            if (D_8010F530_MinigameInstructions[side] < -15.0f) {
                D_8010F530_MinigameInstructions[side] = -15.0f;
            }
        } else {
            D_8010F530_MinigameInstructions[side] /= 2.0f;
            if (D_8010F530_MinigameInstructions[side] < 0.1f && D_8010F530_MinigameInstructions[side] > -0.1f) {
                D_8010F530_MinigameInstructions[side] = 0.0f;
            }
        }
        model = OVL6F_F50E(work->unk_3E);
        D_8010F51C_MinigameInstructions[side] += D_8010F514_MinigameInstructions[side] * D_8010F524_MinigameInstructions[side];
        if (D_8010F52C_MinigameInstructions < D_8010F51C_MinigameInstructions[side]) {
            D_8010F524_MinigameInstructions[side] = -D_8010F524_MinigameInstructions[side];
            D_8010F51C_MinigameInstructions[side] = D_8010F52C_MinigameInstructions;
        } else if (D_8010F51C_MinigameInstructions[side] < 0.0f) {
            D_8010F51C_MinigameInstructions[side] = 0.0f;
            D_8010F524_MinigameInstructions[side] = -D_8010F524_MinigameInstructions[side];
        }
        D_800F2B7C[(s16)model].unk_48 = D_8010F51C_MinigameInstructions[side];
        D_800F2B7C[work->unk_4E].unk_48 = D_8010F51C_MinigameInstructions[side];
        D_800F2B7C[partner->unk_4E].unk_48 = D_8010F52C_MinigameInstructions - D_8010F51C_MinigameInstructions[side];
        func_8009ECB0(D_800F2B7C[work->unk_4E].unk7C, 0.0f, 0.0f, D_8010F530_MinigameInstructions[side]);
        func_8009ECB0(D_800F2B7C[partner->unk_4E].unk7C, 0.0f, 0.0f, -D_8010F530_MinigameInstructions[side]);
        func_8009ECB0(D_800F2B7C[(s16)model].unk7C, 0.0f, 0.0f, D_8010F530_MinigameInstructions[side]);
        D_8010F514_MinigameInstructions[work->unk_3E] -= 0.06f;
        if (D_8010F514_MinigameInstructions[work->unk_3E] < 0.0f) {
            D_8010F514_MinigameInstructions[work->unk_3E] = 0.0f;
        }
        if (D_8010F514_MinigameInstructions[side] > 0.5f) {
            if (work->unk_44 == -1) {
                work->unk_44 = func_800FA284_MinigameInstructions(0x33C);
            }
            func_800FA350_MinigameInstructions(work->unk_44, (D_8010F514_MinigameInstructions[side] - 0.5f) * 0.6666667f * 100.0f);
            work->unk_BC = 10;
        } else if (work->unk_BC == 0 || --work->unk_BC == 0) {
            if (work->unk_44 != -1) {
                func_800FA380_MinigameInstructions(work->unk_44);
            }
            work->unk_44 = -1;
        }
    }
}
/* D_8010F548's low half (retail's D_8010F54A label). */
#define OVL6F_F54A (((s16*)&D_8010F548_MinigameInstructions)[1])

void func_8010D200_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    s32 ch;
    s16 group;
    u16 count;

    ch = GwPlayer[work->unk_38].character;
    group = GwPlayer[work->unk_38].group;
    work->unk_3E = group;
    work->unk_4E = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x9F, 0x299);
    work->unk_50 = func_80023FC8(work->unk_4E);
    func_800258EC(work->unk_50, 4, 4);
    work->unk_52 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 3, 0x1D);
    work->unk_54 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 1, 0x1D);
    work->unk_56 = LoadFormFile((D_8010E964_MinigameInstructions[ch] << 16) | 0x7C, 0x1D);
    if (group == 0) {
        work->unk_70 = LoadFormFile(0x470009, 0x299);
        func_80025830(work->unk_70, 0.0f, 0.0f, 0.0f);
        work->unk_72 = LoadFormFile(0x47000A, 0x1D);
    } else {
        work->unk_70 = LoadFormFile(0x47000B, 0x299);
        func_80025830(work->unk_70, 0.0f, 0.0f, 0.0f);
        work->unk_72 = LoadFormFile(0x47000C, 0x1D);
    }
    count = D_8010F76A_MinigameInstructions[group];
    if (group == 0) {
        work->unk_08 = 65.0f;
        work->unk_14 = -280.0f;
    } else {
        work->unk_08 = 89.0f;
        work->unk_14 = (3 - (s16)count) * 30 - 310;
    }
    func_80025830(work->unk_4E, 0.28f, 0.28f, 0.28f);
    pos.x = work->unk_00 = -50.0f;
    pos.y = work->unk_04 = 124.0f;
    out.z = 0.0f;
    func_8001DD24(0, CZoom - work->unk_14, (Vec3f*)&pos, &out);
    func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
    pos.x = work->unk_08;
    func_8001DD24(0, CZoom - work->unk_14, (Vec3f*)&pos, &out);
    func_80025798(work->unk_70, out.x, out.y, work->unk_14);
    if (work->unk_38 == 0) {
        D_8010F548_MinigameInstructions = LoadFormFile(0x470008, 0x299) & 0xFFFF;
        func_80025830(OVL6F_F54A, 0.0f, 0.0f, 0.0f);
        pos.x = 77.0f;
        pos.y = 130.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(OVL6F_F54A, out.x, out.y, -280.0f);
    }
    work->unk_2C = D_800F2B7C[work->unk_4E].unk_24 - D_800F2B7C[D_8010F548_MinigameInstructions].unk_24;
    work->unk_30 = D_800F2B7C[work->unk_4E].unk_28 - D_800F2B7C[D_8010F548_MinigameInstructions].unk_28;
    work->unk_34 = D_800F2B7C[work->unk_4E].unk_2C - D_800F2B7C[D_8010F548_MinigameInstructions].unk_2C;
    D_8010F76A_MinigameInstructions[group]++;
}
void func_8010D5E4_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    Ovl6FPlayerWork* p;
    s16 i;
    s16 j;
    f32 t;
    f32 scale;
    f32 angle;
    f32 y;
    f32 z;

    if (work->unk_38 == 3) {
        D_8010F768_MinigameInstructions = 0;
    }
    func_800258EC(work->unk_4E, 4, 0);
    func_80025BB8(work->unk_4E, work->unk_52);
    func_80025EB4(work->unk_4E, 2, 2);
    func_800257E4(work->unk_4E, 0.0f, 90.0f, 0.0f);
    pos.x = work->unk_00;
    pos.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 < work->unk_08) {
        pos.x = work->unk_00 = work->unk_00 + 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
        if ((work->unk_42++ & 3) == 0) {
            func_800FA300_MinigameInstructions(0x119, work);
        }
        HuPrcVSleep();
    }
    pos.x = work->unk_00 = work->unk_08;
    func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
    func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
    for (i = 90; i < 180; i += 30) {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        if ((work->unk_42++ & 7) == 0) {
            func_800FA300_MinigameInstructions(0x112, work);
        }
        HuPrcVSleep();
    }
    work->unk_3C = 0;
    work->unk_0C = out.x;
    work->unk_10 = out.y;
    work->unk_14 = -280.0f;
    work->unk_20 = 0.0f;
    work->unk_24 = 90.0f;
    work->unk_28 = 0.0f;
    if (work->unk_38 == 0) {
        for (i = 0; i < 4; i++) {
            p = D_8010F750_MinigameInstructions[i];
            func_80025C20(p->unk_4E, func_80025E48(p->unk_56), 0, 8, 2);
            D_800F2B7C[p->unk_4E].unk_4C = 0.02f;
            D_800F2B7C[p->unk_4E].unk_58 = 0.02f;
            func_80025EB4(p->unk_70, 2, 2);
            D_800F2B7C[p->unk_70].unk_4C = 0.02f;
        }
        for (i = 0; i < 9; i++) {
            HuPrcVSleep();
            t = i / 8.0f;
            scale = t * 0.28f;
            angle = t * 30.0f;
            func_80025830(OVL6F_F54A, scale, scale, scale);
            func_800257E4(OVL6F_F54A, angle, 0.0f, 0.0f);
            for (j = 0; j < 4; j++) {
                p = D_8010F750_MinigameInstructions[j];
                func_80025830(p->unk_70, scale, scale, scale);
                y = func_800AEAC0(-angle) * p->unk_34 + p->unk_10 + func_800AEFD0(-angle) * p->unk_30;
                z = func_800AEFD0(-angle) * p->unk_34 + p->unk_14 - func_800AEAC0(-angle) * p->unk_30;
                func_80025798(p->unk_4E, p->unk_0C, y, z);
                func_800257E4(p->unk_4E, -angle, 180.0f, 0.0f);
                func_80025798(p->unk_70, p->unk_0C, y, z);
                func_800257E4(p->unk_70, -angle, 180.0f, 0.0f);
            }
        }
        D_8010F768_MinigameInstructions = 1;
    } else {
        while (D_8010F768_MinigameInstructions == 0) {
            HuPrcVSleep();
        }
    }
    work->unk_B6 = 2;
}
void func_8010DB24_MinigameInstructions(Ovl6FPlayerWork* work) {
    Vec2f pos;
    Vec3f out;
    Ovl6FPlayerWork* p;
    s16 i;
    s16 j;
    f32 t;
    f32 scale;
    f32 angle;
    f32 y;
    f32 z;

    i = 0;
    if (work->unk_38 == 0) {
        D_8010F768_MinigameInstructions = 0;
        do {
            HuPrcVSleep();
            t = 1.0f - i / 8.0f;
            scale = t * 0.28f;
            angle = t * 30.0f;
            func_80025830(OVL6F_F54A, scale, scale, scale);
            func_800257E4(OVL6F_F54A, angle, 0.0f, 0.0f);
            for (j = 0; j < 4; j++) {
                p = D_8010F750_MinigameInstructions[j];
                func_80025830(p->unk_70, scale, scale, scale);
                y = func_800AEAC0(-angle) * p->unk_34 + p->unk_10 + func_800AEFD0(-angle) * p->unk_30;
                z = func_800AEFD0(-angle) * p->unk_34 + p->unk_14 - func_800AEAC0(-angle) * p->unk_30;
                func_80025798(p->unk_4E, p->unk_0C, y, z);
                func_800257E4(p->unk_4E, -angle, 180.0f, 0.0f);
                func_80025798(p->unk_70, p->unk_0C, y, z);
                func_800257E4(p->unk_70, -angle, 180.0f, 0.0f);
            }
            i++;
        } while (i < 9);
        D_8010F768_MinigameInstructions = 1;
    } else {
        while (D_8010F768_MinigameInstructions == 0) {
            HuPrcVSleep();
        }
    }
    D_800F2B7C[work->unk_4E].unk_4C = 1.0f;
    i = 0;
    func_80025C20(work->unk_4E, func_80025E48(work->unk_52), 0, 8, 2);
    HuPrcSleep(8);
    do {
        func_800257E4(work->unk_4E, 0.0f, i, 0.0f);
        if ((work->unk_42++ & 7) == 0) {
            func_800FA300_MinigameInstructions(0x112, work);
        }
        HuPrcVSleep();
        i -= 30;
    } while (i >= -90);
    pos.x = work->unk_00;
    pos.y = work->unk_04;
    out.z = 0.0f;
    while (work->unk_00 > -50.0f) {
        pos.x = work->unk_00 = work->unk_00 - 12.0f;
        func_8001DD24(0, CZoom, (Vec3f*)&pos, &out);
        func_80025798(work->unk_4E, out.x, out.y, work->unk_14);
        if ((work->unk_42++ & 3) == 0) {
            func_800FA300_MinigameInstructions(0x119, work);
        }
        HuPrcVSleep();
    }
}
void func_8010DF34_MinigameInstructions(Ovl6FPlayerWork* work) {
    s32 port;

    port = GwPlayer[work->unk_38].port;
    if (func_80009E4C(port, 0xE, ContStkX[port], ContStkY[port]) != 0) {
        if ((work->unk_B6 += 5) > 150) {
            work->unk_B6 = 150;
        }
    } else {
        if ((work->unk_B6 /= 2) < 2) {
            work->unk_B6 = 2;
        }
    }
    D_800F2B7C[work->unk_4E].unk_4C = work->unk_B6 / 100.0f;
    D_800F2B7C[work->unk_70].unk_4C = work->unk_B6 / 100.0f;
    if (func_80025D18(work->unk_4E) == 30.0f) {
        func_800FA2C0_MinigameInstructions(0x361, work);
    }
}
void func_8010E090_MinigameInstructions(s16 idx) {
    s16 chars[4];
    Ovl6FTeamEntry* entry;
    s16 noTeam;
    s16 i;
    s16 n;
    s16 tmp;
    s16 a;
    s16 b;

    ClearBoardFeatureFlag(0x2F);
    noTeam = (s8)(u8)GwQuest.charNoTeam;
    entry = &D_8010EF70_MinigameInstructions[idx];
    GwPlayer[0].group = entry->group;
    if (idx == 0x25) {
        func_800593AC(_CheckFlag(0x2D) ? 8 : 6);
    }
    for (i = 0; i < 4; i++) {
        GwPlayer[i].cpu_difficulty = entry->unk_03;
    }
    n = 0;
    for (i = 0; i < 6; i++) {
        if (((i == GwPlayer[0].character) | (i == noTeam)) == 0) {
            chars[n++] = i;
        }
    }
    for (i = 0; i < 20; i++) {
        a = rand8() & 3;
        b = rand8() & 3;
        tmp = chars[a];
        chars[a] = chars[b];
        chars[b] = tmp;
    }
    for (i = 1; i < 4; i++) {
        GwPlayer[i].flags |= 1;
        GwPlayer[i].coins = 60;
    }
    if (entry->unk_01 == -1) {
        if (D_8010F760_MinigameInstructions == 2) {
            GwPlayer[1].group = 0;
            GwPlayer[2].group = GwPlayer[3].group = 1;
        } else if (D_8010F760_MinigameInstructions == 3) {
            GwPlayer[1].group = GwPlayer[2].group = GwPlayer[3].group = 1;
        } else {
            for (i = 1; i < 4; i++) {
                GwPlayer[i].group = i;
            }
        }
        for (i = 1; i < 4; i++) {
            GwPlayer[i].character = chars[i];
        }
        return;
    }
    GwPlayer[1].cpu_difficulty = entry->unk_02;
    GwPlayer[1].character = noTeam;
    if (D_8010F760_MinigameInstructions == 2) {
        if (idx == 0x31) {
            GwPlayer[0].group = 1;
            GwPlayer[1].group = 0;
            GwPlayer[2].group = 2;
            GwPlayer[3].group = 3;
        } else {
            GwPlayer[1].group = entry->unk_01;
            GwPlayer[2].group = GwPlayer[3].group = 1;
        }
    } else if (D_8010F760_MinigameInstructions == 3) {
        GwPlayer[1].group = GwPlayer[2].group = GwPlayer[3].group = 1;
    } else {
        for (i = 1; i < 4; i++) {
            GwPlayer[i].group = i;
        }
    }
    for (i = 2; i < 4; i++) {
        GwPlayer[i].character = chars[i];
    }
}

/* .data */
s32 D_8010EEE0_MinigameInstructions[6] = { 0x390000, 0x390001, 0x390002, 0x390003, 0x390004, 0x390005 };
u8* D_8010EEF8_MinigameInstructions[6] = { (u8*)D_8010F3F4_MinigameInstructions, (u8*)D_8010F3E8_MinigameInstructions, (u8*)D_8010F3DC_MinigameInstructions, (u8*)D_8010F3D0_MinigameInstructions, (u8*)D_8010F3C4_MinigameInstructions, (u8*)D_8010F3B8_MinigameInstructions };
s32 D_8010EF10_MinigameInstructions[6][2] = { { 0x30000C, 0x300012 }, { 0x30000D, 0x300017 }, { 0x30000E, 0x30001C }, { 0x30000F, 0x300021 }, { 0x300010, 0x300026 }, { 0x300011, 0x30002B } };
u16 D_8010EF40_MinigameInstructions[4] = { 0x28, 0x3C, 0x6E, 0x7D };
s32 D_8010EF48_MinigameInstructions[4] = { 0x3A000B, 0x3A0002, 0x3A000A, 0x3A0005 };
u16 D_8010EF58_MinigameInstructions[4] = { 0x10, 0x44, 0x56, 0x8A };
u8 D_8010EF60_MinigameInstructions = 0;
/* zero filler to 0x8010EF70 (retail pads D_8010EF60 to 16 bytes): scalars to the word, then words */
u8 D_8010EF61_MinigameInstructions = 0;
u8 D_8010EF62_MinigameInstructions = 0;
u8 D_8010EF63_MinigameInstructions = 0;
s32 D_8010EF64_MinigameInstructions[3] = { 0, 0, 0 };
Ovl6FTeamEntry D_8010EF70_MinigameInstructions[56] = { { 0, -1, -1, 0 }, { 255, -1, -1, 0 }, { 0, -1, -1, 0 }, { 0, -1, -1, 3 }, { 0, -1, -1, 1 }, { 0, -1, -1, 0 }, { 0, -1, -1, 0 }, { 0, -1, -1, 3 }, { 0, -1, -1, 0 }, { 0, -1, -1, 1 }, { 0, -1, -1, 0 }, { 0, -1, -1, 0 }, { 0, -1, -1, 0 }, { 0, -1, -1, 1 }, { 0, -1, -1, 2 }, { 0, -1, -1, 0 }, { 0, -1, -1, 0 }, { 0, -1, -1, 1 }, { 0, -1, -1, 0 }, { 0, -1, -1, 2 }, { 0, -1, -1, 0 }, { 0, -1, -1, 0 }, { 0, -1, -1, 1 }, { 0, -1, -1, 1 }, { 0, -1, -1, 0 }, { 0, -1, -1, 3 }, { 0, -1, -1, 3 }, { 0, -1, -1, 0 }, { 0, -1, -1, 1 }, { 0, 0, 3, 3 }, { 0, -1, -1, 3 }, { 0, -1, -1, 1 }, { 0, -1, -1, 0 }, { 0, -1, -1, 2 }, { 0, -1, -1, 3 }, { 0, -1, -1, 3 }, { 0, -1, -1, 0 }, { 0, -1, -1, 3 }, { 0, -1, -1, 1 }, { 0, 0, 2, 3 }, { 0, -1, -1, 3 }, { 0, -1, -1, 0 }, { 0, 0, 2, 2 }, { 0, -1, -1, 1 }, { 0, 1, 1, 0 }, { 0, 1, 1, 0 }, { 0, -1, -1, 3 }, { 0, 0, 1, 1 }, { 0, -1, -1, 0 }, { 0, 1, 1, 1 }, { 0, -1, -1, 1 }, { 0, -1, -1, 0 }, { 0, -1, -1, 1 }, { 0, -1, -1, 0 }, { 0, -1, -1, 1 }, { 0, -1, -1, 1 } };
