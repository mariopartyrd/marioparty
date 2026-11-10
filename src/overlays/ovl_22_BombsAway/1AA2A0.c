#include "BombsAway.h"

/* View of the stage's surface plane (D_80100438 = D_80100328.unk_110). */
extern omObjData* D_800F2AF8[];
extern u8 D_800F64F8;
extern u16 D_800EE984;
extern u16 ContBtn[4];
extern u16 D_800F2CE2[4];
extern s16 D_800F33CC[4];
extern s8 ContStkY[4];

/* A player's work (obj->unk_50): MgWork's layout (src/99E0.c); no pointers below 0x60. */
typedef struct BaPlayerWork {
    /* 0x00 */ char unk_00[0x50];
    /* 0x50 */ u16 unk_50; /* flags */
    /* 0x52 */ char unk_52[4];
    /* 0x56 */ s8 unk_56; /* controller port */
    /* 0x57 */ char unk_57;
    /* 0x58 */ s8 unk_58; /* player index */
    /* 0x59 */ char unk_59[3];
    /* 0x5C */ s32 unk_5C;
} BaPlayerWork;
#define BA_WORK(obj) ((BaPlayerWork*)(obj)->unk_50)

/* The ground's work (D_800F2AF8[0]->unk_50, func_800F9824): MgWork's first 0x2C bytes. */
typedef struct BaGroundWork {
    /* 0x00 */ char unk_00[0x10];
    /* 0x10 */ f32 unk_10; /* ground height */
} BaGroundWork;

/* Height of the stage's surface plane (D_80100438 = D_80100328.unk_110: a, b, c, d) above pos.
   Retail keeps the plane's address in a register; an index variable (always 0) reproduces it. */
#define BA_PLANE_HEIGHT(pos, i) \
    (((pos)->x * (&D_80100438_BombsAway)[(i)] + (pos)->y * (&D_80100438_BombsAway)[(i) + 1] + \
      (pos)->z * (&D_80100438_BombsAway)[(i) + 2] - (&D_80100438_BombsAway)[(i) + 3]) / \
     -(&D_80100438_BombsAway)[(i) + 1])


/* Time between bombs per players left (func_800F723C). */
s16 D_800FFA70_BombsAway[6] = { 100, 15, 20, 25, 30, 0 };
/* CPU target offsets (x, z) from the platform centre, per corner slot (func_800F8538). */
f32 D_800FFA7C_BombsAway[6][2] = {
    { 0.0f, 0.0f }, { 300.0f, 300.0f }, { 300.0f, -300.0f }, { -300.0f, 300.0f }, { -300.0f, -300.0f }, { 0.0f, 800.0f },
};
/* Model pairs (indices into D_801004D0) per state (func_800FB2E4). */
u8 D_800FFAAC_BombsAway[10][2] = {
    { 5, 4 }, { 5, 4 }, { 0, 1 }, { 2, 3 }, { 5, 4 }, { 4, 5 }, { 4, 5 }, { 4, 5 }, { 0, 0 }, { 0, 0 },
};

void func_800F65E0_BombsAway(void) {
    BaPlayer* p;
    BaStage* s;
    void* data;
    s16 i;
    u8 cam;

    func_80029090(10);
    func_8002ADF0(&D_800EDEC0, 10);
    func_8001DE70(0x30);
    omInitObjMan(0x20, 0);
    i = 0;
    func_80060088();
    D_80100148_BombsAway = _CheckFlag(0x2B) != 0;
    D_8010014A_BombsAway = 0;
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    func_800178A0(1);
    cam = func_800178E8();
    func_80017660(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 45.0f, 80.0f, 4000.0f);
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    D_800ED430 = 0;
    D_80100140_BombsAway.unk_00 = 0;
    D_80100140_BombsAway.unk_04 = 0;
    D_80100140_BombsAway.unk_02 = 0;
    D_80100140_BombsAway.unk_06 = 900;
    D_80100310_BombsAway = D_80100314_BombsAway = D_80100318_BombsAway = D_8010031C_BombsAway =
        D_80100320_BombsAway = 0;
    p = D_80100150_BombsAway;
    do {
        func_8009B770(p, 0, sizeof(BaPlayer));
        i++;
        p++;
    } while (i < 4);
    s = &D_80100328_BombsAway;
    func_8009B770(s, 0, sizeof(BaStage));
    func_800A2A50(s->unk_50);
    func_800A2A50(s->unk_90);
    func_800A2A50(s->unk_D0);
    D_80100458_BombsAway = 0;
    /* Retail zeroes columns 1 and 2 of the eight rows unk_50[0..3] and unk_90[0..3] (the
       identities just set lose their [1][1] and [2][2]), and each weight's x. */
    for (i = 0; i < 8; i++) {
        s->unk_134[i].unk_00 = s->unk_50[i][1] = s->unk_50[i][2] = 0.0f;
    }
    D_801004BC_BombsAway = 0;
    for (i = 0; i < 6; i++) {
        D_801004BE_BombsAway[i] = 0;
    }
    func_8009B770(D_80100500_BombsAway, 0, sizeof(D_80100500_BombsAway));
    D_801006F8_BombsAway = -1;
    func_8009B770(D_80100698_BombsAway, 0, sizeof(D_80100698_BombsAway));
    i = 0;
    func_800FAFB4_BombsAway();
    func_800F6B28_BombsAway();
    D_80100324_BombsAway = func_800174C0(0x350007, 0x9D);
    D_800ED440 = 0;
    func_800090B8(0);
    D_800F2AF8[D_800ED440++] = omAddObj(1, 1, 0, -1, func_800F9824_BombsAway);
    omAddObj(20, 0, 0, -1, func_800F6B88_BombsAway);
    omAddObj(8, 1, 0, -1, func_800FB1C4_BombsAway);
    omAddObj(8, 1, 0, -1, func_800FB1E0_BombsAway);
    for (; i < 9; i++) {
        D_80100700_BombsAway[i] = -1;
    }
    i = 0;
    func_800F7B00_BombsAway();
    func_8007B168((u8*)"\x82\x72\x82\x73\x82\x60\x82\x71\x82\x73", 1); /* "START" in full-width SJIS */
    data = DataRead(0x270004);
    D_801006FA_BombsAway = func_800678A4(data);
    DataClose(data);
    D_80100690_BombsAway = -1;
    D_80100692_BombsAway = 0;
    D_80100694_BombsAway = 0;
    D_801006FC_BombsAway = func_80064EF4(12, 0);
    do {
        func_80067208(D_801006FC_BombsAway, i, D_801006FA_BombsAway, 0);
        func_80067354(D_801006FC_BombsAway, i, 0.5f, 0.5f);
        func_8006752C(D_801006FC_BombsAway, i, 0x100);
        func_800674BC(D_801006FC_BombsAway, i, 0x9000);
        func_800672B0(D_801006FC_BombsAway, i, 0);
        D_801005A0_BombsAway[i].unk_00 = D_801005A0_BombsAway[i].unk_02 = 0;
        D_801005A0_BombsAway[i].unk_04 = D_801005A0_BombsAway[i].unk_08 = D_801005A0_BombsAway[i].unk_0C =
            D_801005A0_BombsAway[i].unk_10 = 0.0f;
        i++;
    } while (i < 12);
    func_800FC5E0_BombsAway();
}
void func_800F6B28_BombsAway(void) {
    Center.x = Center.y = Center.z = 0.0f;
    Center.y = 180.0f;
    CRot.y = CRot.z = 0.0f;
    CRot.x = -21.0f;
    CZoom = 1400.0f;
}
void func_800F6B88_BombsAway(omObjData* obj) {
    obj->func_ptr = func_800F6B98_BombsAway;
}
void func_800F6B98_BombsAway(omObjData* obj) {
    s16 endFrame[] = { 90, 105, 105, 105, 130 };
    BaPlayer* p;
    s32 i;
    s32 out; /* players out (case 2), then the end test (case 3) */
    s32 fallen;
    s32 flag;

    switch (D_80100140_BombsAway.unk_00) {
        case 0:
            func_800FC39C_BombsAway(0);
            if (D_80100144_BombsAway == 1) {
                PlaySound(0x1B6);
                func_80021E58();
                SetFadeInTypeAndTime(0, 16);
            } else if (D_80100144_BombsAway == 0x80) {
                GMesCreate(0);
            } else if (D_80100144_BombsAway == 70) {
                func_80060128(0x1B);
            } else if (D_80100140_BombsAway.unk_04 >= 180) {
                GMesCreate(8, (s16)(D_80100140_BombsAway.unk_06 / 30), 0xA0, 0x20);
                D_80100140_BombsAway.unk_00 = 1;
                D_80100140_BombsAway.unk_04 = -1;
                D_800ED430 = 1;
            }
            break;
        case 1:
            if (--D_80100140_BombsAway.unk_06 >= 61) {
                func_800F723C_BombsAway();
            }
            func_800F7604_BombsAway();
            if (D_80100314_BombsAway < 2 || D_80100146_BombsAway <= 0 || D_8010014A_BombsAway != 0) {
                D_80100140_BombsAway.unk_00 = 2;
                D_80100140_BombsAway.unk_04 = -1;
                func_800790C0();
            }
            break;
        case 2:
            if (D_80100140_BombsAway.unk_04 < 5000) {
                D_80100140_BombsAway.unk_06 = -1;
                fallen = 0;
                out = 0;
                p = D_80100150_BombsAway;
                for (i = 0; i < D_80100310_BombsAway; i++, p++) {
                    if (p->unk_02 == 7) {
                        out++;
                    } else {
                        flag = p->unk_00 & 0x10;
                        fallen += flag != 0;
                    }
                }
                if (out + fallen >= D_80100310_BombsAway) {
                    D_80100314_BombsAway = out;
                    D_80100144_BombsAway = 5000;
                    func_800601D4(90);
                    if (D_80100148_BombsAway != 0) {
                        if (D_8010014A_BombsAway != 0) {
                            GMesCreate(2);
                        }
                    } else if (D_80100314_BombsAway > 0) {
                        GMesCreate(2);
                    } else {
                        GMesCreate(0x11);
                    }
                }
            } else if (D_80100148_BombsAway != 0) {
                if (D_80100140_BombsAway.unk_04 >= 60) {
                    D_80100140_BombsAway.unk_00 = 3;
                    D_80100140_BombsAway.unk_04 = -1;
                }
            } else if (GMesStatAllGet() == 2) {
                D_80100140_BombsAway.unk_00 = 3;
                D_80100140_BombsAway.unk_04 = -1;
                switch (D_80100314_BombsAway) {
                    case 1:
                        func_80060128(0x32);
                        break;
                    case 2:
                    case 3:
                        func_80060128(0x36);
                        break;
                    case 4:
                        func_80060128(0x37);
                        break;
                    default:
                        func_80060128(0x34);
                        break;
                }
            }
            break;
        case 3:
            D_800ED430 = 2;
            if (D_80100144_BombsAway == 21 && D_80100314_BombsAway == 1 && D_80100148_BombsAway == 0) {
                for (i = 0; i < D_80100310_BombsAway; i++) {
                    if (D_80100150_BombsAway[i].unk_02 == 7) {
                        GMesCreate(4, GwPlayer[i].character);
                        func_80060468(0x451, GwPlayer[i].character);
                        break;
                    }
                }
            }
            out = 0;
            if (D_80100148_BombsAway != 0) {
                out = D_80100144_BombsAway == 60;
            } else if (D_80100144_BombsAway == endFrame[D_80100314_BombsAway]) {
                out = 1;
            }
            if (out) {
                if (D_80100148_BombsAway != 0) {
                    func_80060398(40);
                    if (D_8010014A_BombsAway == 0) {
                        for (i = 0; i < 4; i++) {
                            if (GwPlayer[i].group == 0) {
                                GwPlayer[i].coins_mg += 10;
                            }
                        }
                    }
                }
                func_800726AC(0, 20);
                obj->func_ptr = func_800F71E4_BombsAway;
                return;
            }
            break;
    }
    if (++D_80100140_BombsAway.unk_04 >= 0x7800) {
        D_80100140_BombsAway.unk_04 -= 0x800;
    }
    if (D_80100146_BombsAway >= 0) {
        func_80079078((D_80100146_BombsAway + 29) / 30);
    }
    func_800FB988_BombsAway();
    if (D_801004BC_BombsAway != 0) {
        D_801004BC_BombsAway--;
    }
    if (D_800F5144 == 1) {
        func_800F7218_BombsAway();
        omOvlReturnEx(1);
    }
}
void func_800F71E4_BombsAway(omObjData* obj) {
    if (func_80072718() == 0) {
        func_800F7218_BombsAway();
        omOvlReturnEx(1);
    }
}
void func_800F7218_BombsAway(void) {
    func_80060198();
    func_800FC7F4_BombsAway();
}


// register allocation and one mul.s/lui scheduling swap (masked 7)
#ifdef NON_MATCHING
void func_800F723C_BombsAway(void) {
    s32 i;
    s16 newestIdx;
    s16 newest;
    s32 fire;
    f32 x;
    f32 z;
    f32 angle;
    f32 dist;
    s32 left;

    newest = -1;
    newestIdx = -1;

    for (i = 0; i < 8; i++) {
        if (D_80100698_BombsAway[i].unk_00 != 0) {
            D_80100698_BombsAway[i].unk_00++;
            D_80100698_BombsAway[i].unk_02--;
            if (newest < D_80100698_BombsAway[i].unk_00) {
                newest = D_80100698_BombsAway[i].unk_00;
                newestIdx = i;
            }
        }
    }
    D_801006F8_BombsAway = newestIdx;
    if (D_80100320_BombsAway == 0) {
        fire = 1;
        D_80100320_BombsAway = 1;
    } else {
        fire = 0;
        if (D_80100318_BombsAway != 0) {
            D_80100318_BombsAway--;
        } else if (!(D_80100144_BombsAway & 7)) {
            if ((s32)((u32)(((rand8() << 8) | rand8()) * 25) >> 14) < 30) {
                fire = 1;
            }
        }
    }
    if (fire) {
        if (D_8010031C_BombsAway == 0 && (s32)((u32)(((rand8() << 8) | rand8()) * 25) >> 14) < 20) {
            dist = (((rand8() << 8) | rand8()) * 75) >> 14;
            D_8010031C_BombsAway = 2;
        } else {
            dist = (s32)((u32)(((rand8() << 8) | rand8()) * 25) >> 14) + 550.0;
            if (D_8010031C_BombsAway != 0) {
                D_8010031C_BombsAway--;
            }
        }
        angle = (((rand8() << 8) | rand8()) * 45) >> 13;
        x = func_800AEFD0(angle) * dist + D_80100360_BombsAway.x;
        z = func_800AEAC0(angle) * dist + D_80100360_BombsAway.z;
        func_800FE948_BombsAway(x, z, 0.4f, 1);
        left = D_80100314_BombsAway;
        D_80100318_BombsAway = D_800FFA70_BombsAway[~left >> 31 & left] /* max(left, 0) */;
        for (i = 0; i < 8; i++) {
            if (D_80100698_BombsAway[i].unk_00 == 0) {
                D_80100698_BombsAway[i].unk_00 = 1;
                D_80100698_BombsAway[i].unk_02 = 60;
                D_80100698_BombsAway[i].unk_04 = x;
                D_80100698_BombsAway[i].unk_08 = z;
                if (newest < D_80100698_BombsAway[i].unk_00) {
                    newestIdx = i;
                }
                break;
            }
        }
    }
    D_801006F8_BombsAway = newestIdx;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F723C_BombsAway);
#endif
void func_800F7604_BombsAway(void) {
    s16 ids[8];
    Vec pos;
    s16 n = 0;
    s32 i;
    s32 j;
    BaPlayer* p;
    omObjData* obj;
    BaShock* w;
    f32 x, y, z;
    f32 dx, dy, dz;

    for (i = 0; i < 8; i++) {
        if (D_80100500_BombsAway[i].unk_00 != 0) {
            D_80100500_BombsAway[i].unk_00--;
            if (D_80100500_BombsAway[i].unk_00 != 0) {
                pos.x = D_80100500_BombsAway[i].unk_04;
                pos.y = D_80100500_BombsAway[i].unk_08;
                pos.z = D_80100500_BombsAway[i].unk_0C;
                func_800FA6FC_BombsAway(&pos, &pos);
                D_80100500_BombsAway[i].unk_08 = pos.y;
            }
            ids[n] = i;
            n++;
        }
    }
    if (n != 0) {
        for (i = 0; i < D_80100310_BombsAway; i++) {
            p = &D_80100150_BombsAway[i];
            if (p->unk_00 & 2) {
                continue;
            }
            obj = p->unk_48;
            x = obj->trans.x;
            y = obj->trans.y + p->unk_08;
            z = obj->trans.z;
            for (j = 0; j < n; j++) {
                w = &D_80100500_BombsAway[ids[j]];
                dx = x - w->unk_04;
                dy = y - w->unk_08;
                dz = z - w->unk_0C;
                if (dx * dx + dy * dy + dz * dz < (p->unk_08 + w->unk_10) * (p->unk_08 + w->unk_10)) {
                    break;
                }
            }
            if (j < n) {
                p->unk_00 |= 2;
                p->unk_05 = 1;
                p->unk_02 = 9;
                p->unk_3C = 0;
            }
        }
    }
}
void func_800F7850_BombsAway(s16 time, f32 x, f32 y, f32 z, f32 radius) {
    s32 i;

    /* Retail fills every free slot, not just the first. */
    for (i = 0; i < 8; i++) {
        if (D_80100500_BombsAway[i].unk_00 == 0) {
            D_80100500_BombsAway[i].unk_00 = time;
            D_80100500_BombsAway[i].unk_04 = x;
            D_80100500_BombsAway[i].unk_08 = y;
            D_80100500_BombsAway[i].unk_0C = z;
            D_80100500_BombsAway[i].unk_10 = radius;
        }
    }
}
BaPlayer* func_800F78D4_BombsAway(omObjData* obj) {
    BaPlayer* p = D_80100150_BombsAway;
    s32 i;

    for (i = 0; i < D_80100310_BombsAway; i++, p++) {
        if (p->unk_48 == obj) {
            break;
        }
    }
    return p;
}
void func_800F791C_BombsAway(omObjData* obj, s32 motion) {
    s16 cur = func_80017A50(obj);
    BaPlayer* p = func_800F78D4_BombsAway(obj);
    u8 idx;

    if (p->unk_36 != cur && p->unk_38 != cur) {
        if (p->unk_34 != 0) {
            p->unk_38 = cur;
        } else {
            p->unk_36 = cur;
        }
        p->unk_34 = 1 - p->unk_34;
    }
    idx = obj->model[0];
    if (func_80018490(obj, motion) != 0) {
        D_800F2B7C[idx].unk_0A |= 2;
    } else {
        D_800F2B7C[idx].unk_0A &= ~2;
    }
    func_800184BC(obj, (u8)motion);
}
void func_800F7A14_BombsAway(omObjData* obj, s32 m1, s32 m2) {
    BaPlayer* p;
    s32 i;

    if (func_80018490(obj, m1) != 0 || func_80018490(obj, m2) != 0) {
        p = func_800F78D4_BombsAway(obj);
        for (i = 0; i < obj->mtncnt; i++) {
            if (obj->motion[i] == -1) {
                continue;
            }
            if (i == (u8)m1) {
                continue;
            }
            if (i == (u8)m2) {
                continue;
            }
            if (i == p->unk_36) {
                continue;
            }
            if (i == p->unk_38) {
                continue;
            }
            func_8002456C(obj->motion[i]);
            obj->motion[i] = -1;
            return;
        }
    }
}
void func_800F7B00_BombsAway(void) {
    D_800F3FB0[D_800F2BC0++] = omAddObj(4, 9, 0x3C, -1, func_800F7C24_BombsAway);
    D_800F3FB0[D_800F2BC0++] = omAddObj(5, 9, 0x3C, -1, func_800F7C40_BombsAway);
    D_800F3FB0[D_800F2BC0++] = omAddObj(6, 9, 0x3C, -1, func_800F7C5C_BombsAway);
    D_800F3FB0[D_800F2BC0++] = omAddObj(7, 9, 0x3C, -1, func_800F7C78_BombsAway);
}
void func_800F7C24_BombsAway(omObjData* obj) {
    func_800F8100_BombsAway(obj, 0);
}
void func_800F7C40_BombsAway(omObjData* obj) {
    func_800F8100_BombsAway(obj, 1);
}
void func_800F7C5C_BombsAway(omObjData* obj) {
    func_800F8100_BombsAway(obj, 2);
}
void func_800F7C78_BombsAway(omObjData* obj) {
    func_800F8100_BombsAway(obj, 3);
}
// register allocation: p and the ground work swap s0/s1 (masked 0)
#ifdef NON_MATCHING
void func_800F7C94_BombsAway(omObjData* obj) {
    Vec pos;
    Vec vel;
    BaPlayer* p;
    BaPlayerWork* w;
    BaGroundWork* gw;
    f32 groundY;
    s16 model;
    s32 corner;
    s32 j;

    p = func_800F78D4_BombsAway(obj);
    if (!(p->unk_00 & 0x80)) {
        p->unk_00 |= 0x80;
        return;
    }
    pos.x = obj->trans.x;
    pos.y = obj->trans.y;
    pos.z = obj->trans.z;
    gw = D_800F2AF8[0]->unk_50;
    if (func_800FA6FC_BombsAway(&pos, &vel) != 0) {
        groundY = vel.y;
        gw->unk_10 = groundY;
        if (vel.y > obj->trans.y) {
            obj->trans.y = vel.y;
        }
    } else {
        gw->unk_10 = groundY = -200.0f;
    }
    if (p->unk_05 == 0) {
        w = obj->unk_50;
        if ((GwPlayer[w->unk_58].flags & 1) || D_80100140_BombsAway.unk_00 != 1) {
            func_800F8538_BombsAway(obj);
        }
        func_80005A28(obj);
        vel.x = p->unk_0C = obj->trans.x - pos.x;
        vel.y = p->unk_10 = obj->trans.y - pos.y;
        vel.z = p->unk_14 = obj->trans.z - pos.z;
        if (D_80100140_BombsAway.unk_00 == 1) {
            vel.y -= 30.0;
        }
    } else {
        func_800F8D48_BombsAway(obj);
        vel.x = p->unk_0C;
        vel.y = p->unk_10;
        vel.z = p->unk_14;
    }
    p->unk_6A = 0;
    if (!(p->unk_00 & 2)) {
        w = obj->unk_50;
        if (!(w->unk_5C & 0x220) || (w->unk_50 & 0x80)) {
            func_800FA7E8_BombsAway(&pos, &vel, &pos, 1);
            if (func_800FA664_BombsAway(&pos) == 0) {
                goto fall;
            }
            obj->trans.x = pos.x;
            obj->trans.y = pos.y;
            obj->trans.z = pos.z;
            func_800FADA8_BombsAway(pos.x, pos.z, -1.0f);
            if (p->unk_05 == 0 && D_80100140_BombsAway.unk_00 == 2) {
                p->unk_05 = 1;
                p->unk_02 = 7;
                corner = 0;
                if (pos.z < D_80100368_BombsAway) {
                    corner = 1;
                }
                if (pos.x < D_80100360_BombsAway.x) {
                    corner |= 2;
                }
                corner++;
                D_801004BE_BombsAway[corner] |= 1;
            } else if (D_80100354_BombsAway != 0 && D_80100140_BombsAway.unk_00 == 1) {
                p->unk_05 = 1;
                p->unk_02 = 3;
                p->unk_3C = 0;
            }
            if (D_801004BC_BombsAway == 1) {
                func_80060F04(p->unk_06, 2, 3, 10);
            }
        } else {
            func_800FA7E8_BombsAway(&pos, &vel, &pos, 0);
            if (func_800FA664_BombsAway(&pos) <= 0 && pos.y < 0.0) {
            fall:
                p->unk_00 |= 2;
                p->unk_05 = 1;
                p->unk_02 = 5;
                p->unk_3C = 0;
            } else if (D_80100140_BombsAway.unk_00 == 2 && D_80100140_BombsAway.unk_04 >= 8) {
                if (!(D_80100140_BombsAway.unk_04 & 7)) {
                    for (j = 1; j < 5; j++) {
                        if (!(D_801004BE_BombsAway[j] & 1)) {
                            break;
                        }
                    }
                    p->unk_68 = j;
                    D_801004BE_BombsAway[j] |= 2;
                }
                p->unk_6A = 1;
            }
        }
    }
    model = obj->model[1];
    func_80025798(model, obj->trans.x, groundY, obj->trans.z);
    func_800257E4(model, D_8010036C_BombsAway.x, D_8010036C_BombsAway.y, D_8010036C_BombsAway.z);
    if (p->unk_00 & 2) {
        func_800258EC(model, 4, 4);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F7C94_BombsAway);
#endif


void func_800F8100_BombsAway(omObjData* obj, s16 player) {
    f32 startX[] = { -3.0f, -1.0f, 1.0f, 3.0f };
    s32 waitMotions[] = { 0x0F, 0x38, 0x39, 0x3A, 0x3B };
    BaPlayer* p;
    BaPlayerWork* w;
    s32 dir;
    s32 file;
    u8 chr;
    s32 r;
    s32 pad[2]; /* unused: retail's frame is 8 bytes larger */

    D_80100314_BombsAway = ++D_80100310_BombsAway;
    chr = GwPlayer[player].character;
    dir = D_800C59AC[chr].unk_00;
    file = D_800C59AC[chr].unk_04;
    func_80009500();
    func_8000979C(obj, dir, file, player, 0x2B9, 0x689);
    func_80025930(obj->model[1], 0x80000000, 0);
    func_80025AD4(obj->model[1]);
    func_80025B34(obj->model[1]);
    func_8009EA40(D_800F2B7C[obj->model[1]].unk7C, 0.0f, 15.0f, 0.0f);
    func_80009340(obj, 2, 0x25, 0x289, 0);
    if (D_80100706_BombsAway[0] < 0) {
        obj->model[3] = D_80100706_BombsAway[0] = LoadFormFile(0x19, 0x68D);
        obj->model[4] = D_80100706_BombsAway[1] = LoadFormFile(0x1A, 0x68D);
        obj->model[5] = D_80100706_BombsAway[2] = LoadFormFile(0x1C, 0x68D);
    } else {
        obj->model[3] = func_80023FC8(D_80100706_BombsAway[0]);
        obj->model[4] = func_80023FC8(D_80100706_BombsAway[1]);
        obj->model[5] = func_80023FC8(D_80100706_BombsAway[2]);
    }
    func_8001874C(obj, 0, dir, 1, 0);
    func_8001874C(obj, 1, dir | 1, 1, 0);
    func_8001874C(obj, 2, dir | 3, 1, 0);
    func_8001874C(obj, 6, dir | 5, 1, 0x13);
    func_8001874C(obj, 15, dir | 0x11, 1, 0);
    func_8001874C(obj, 16, dir | 0x17, 1, 0);
    func_8001874C(obj, 17, dir | 0x18, 0, 0);
    func_8001874C(obj, 21, dir | 0x62, 0, 0);
    func_8001874C(obj, 11, dir | 0xB, 1, 0);
    r = ((rand8() << 8) | rand8()) >> 15;
    func_8001874C(obj, 13, dir | waitMotions[r], 1, 0x78);
    obj->func_ptr = func_800F7C94_BombsAway;
    omSetTra(obj, startX[player] * 100.0, 160.0f, 700.0f);
    func_800090C4(obj, 0, 2);
    w = obj->unk_50;
    w->unk_50 = 0;
    w->unk_56 = GwPlayer[player].port;
    func_800258EC(obj->model[3], 4, 4);
    func_800258EC(obj->model[4], 4, 4);
    p = &D_80100150_BombsAway[player];
    p->unk_48 = obj;
    p->unk_00 = 1;
    p->unk_05 = 0;
    p->unk_06 = player;
    p->unk_08 = 50.0f;
    p->unk_42 = 12;
    p->unk_44 = -1;
}
// register allocation: diff and move swap s3/s4 (masked 0)
#ifdef NON_MATCHING
void func_800F8538_BombsAway(omObjData* obj) {
    BaPlayer* p;
    s32 port;
    s16 move;
    s32 diff;
    f32 dx;
    f32 dz;
    f32 ang;
    f32 r;
    s32 stick;
    s32 pad;

    p = func_800F78D4_BombsAway(obj);
    port = GwPlayer[p->unk_06].port;
    diff = GwPlayer[p->unk_06].cpu_difficulty;
    move = 0;
    if (D_80100328_BombsAway.unk_1C != 0.0) {
        move = 1;
    }
    if (D_80100328_BombsAway.unk_1C > 0.75) {
        if (!(D_80100144_BombsAway & 7)) {
            p->unk_58 = (s32)((u32)(((rand8() << 8) | rand8()) * 25) >> 13) + D_80100328_BombsAway.unk_38.x;
            p->unk_60 = (s32)((u32)(((rand8() << 8) | rand8()) * 25) >> 13) + D_80100328_BombsAway.unk_38.z;
        }
    } else if (D_801006F8_BombsAway >= 0) {
        move = 1;
        dx = D_80100328_BombsAway.unk_38.x - D_80100698_BombsAway[D_801006F8_BombsAway].unk_04;
        dz = D_80100328_BombsAway.unk_38.z - D_80100698_BombsAway[D_801006F8_BombsAway].unk_08;
        if (D_80100698_BombsAway[D_801006F8_BombsAway].unk_02 < 2) {
            if ((s32)((u32)(((rand8() << 8) | rand8()) * 25) >> 14) < 18 - diff * 5) {
                p->unk_54 = 1;
            } else if (dx * dx + dz * dz < 160000.0 &&
                       (s32)((u32)(((rand8() << 8) | rand8()) * 25) >> 14) < diff * 20) {
                p->unk_54 = 1;
            }
        }
        if (!((D_80100698_BombsAway[D_801006F8_BombsAway].unk_00 + p->unk_3E) & 0xF)) {
            ang = func_800FC0EC_BombsAway(dx, dz);
            ang += (((((rand8() << 8) | rand8()) * 15) >> 13) - 60);
            if (ang >= 360.0f) {
                ang -= 360.0f;
            } else if (ang < 0.0f) {
                ang += 360.0f;
            }
            dx = D_80100328_BombsAway.unk_38.x + func_800AEFD0(ang) * 2.0 * 100.0;
            dz = D_80100328_BombsAway.unk_38.z + func_800AEAC0(ang) * 1.5 * 100.0;
            ang = (((rand8() << 8) | rand8()) * 45) >> 13;
            r = ((((rand8() << 8) | rand8()) * (s32)((2.5 - diff * 0.5) * 100.0)) >> 16) + 30.0;
            p->unk_58 = dx + func_800AEFD0(ang) * r;
            p->unk_60 = dz + func_800AEAC0(ang) * r * 0.8;
        }
    }
    if (D_80100354_BombsAway != 0) {
        if ((s32)((u32)(((rand8() << 8) | rand8()) * 25) >> 14) < diff * 10 + 60) {
            p->unk_54 = 1;
        }
    }
    if (p->unk_6A != 0) {
        move = 1;
        p->unk_58 = D_80100328_BombsAway.unk_38.x + D_800FFA7C_BombsAway[p->unk_68][0];
        p->unk_60 = D_80100328_BombsAway.unk_38.z + D_800FFA7C_BombsAway[p->unk_68][1];
    }
    if (move != 0) {
        dx = p->unk_58 - obj->trans.x;
        dz = p->unk_60 - obj->trans.z;
        p->unk_4C = func_800FC0EC_BombsAway(dx, -dz) + 90.0;
        if (p->unk_4C >= 360.0) {
            p->unk_4C -= 360.0;
        }
        p->unk_50 = sqrtf(dx * dx + dz * dz) / 150.0;
        if (p->unk_50 < 0.2) {
            p->unk_50 = 0.0f;
        }
        if (p->unk_50 > 1.0) {
            p->unk_50 = 1.0f;
        }
    } else {
        p->unk_50 = 0.0f;
    }
    ContBtn[port] &= 0x1030;
    ContBtnTrg[port] &= 0x1030;
    if (D_80100140_BombsAway.unk_00 == 1 || p->unk_6A != 0) {
        if (p->unk_54 != 0) {
            ContBtnTrg[port] |= 0x8000;
        }
        pad = port;
        ContBtn[pad] = ContBtnTrg[pad];
        stick = func_800AEAC0(p->unk_4C) * p->unk_50 * 64.0f;
        D_800F2CE2[pad] = stick;
        ContStkX[pad] = stick;
        stick = -func_800AEFD0(p->unk_4C) * p->unk_50 * 64.0f;
        D_800F33CC[pad] = stick;
        ContStkY[pad] = stick;
    } else {
        pad = port;
        D_800F2CE2[pad] = 0;
        ContStkX[pad] = 0;
        D_800F33CC[pad] = 0;
        ContStkY[pad] = 0;
    }
    p->unk_54 = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F8538_BombsAway);
#endif
void func_800F8D48_BombsAway(omObjData* obj) {
    Vec d;
    Vec pos;
    Vec vel;
    Matrix4f m1;
    Matrix4f m2;
    BaPlayer* p;
    f32 ang;
    f32 t;
    s16 n;

    p = func_800F78D4_BombsAway(obj);
    pos.x = obj->trans.x;
    pos.y = obj->trans.y;
    pos.z = obj->trans.z;
    vel.x = p->unk_0C;
    vel.y = p->unk_10;
    vel.z = p->unk_14;
    switch (p->unk_02) {
        case 0:
            func_800F791C_BombsAway(obj, 0);
            if (p->unk_44 >= 0) {
                func_8006071C(p->unk_44);
            }
            p->unk_44 = -1;
            break;
        case 3:
            if (p->unk_3C == 0) {
                p->unk_3A = 0;
                p->unk_3C++;
                func_80060F04(p->unk_06, 2, 2, 20);
            }
            func_800F791C_BombsAway(obj, 11);
            vel.x = vel.z = 0.0f;
            vel.y = -20.0f;
            if (p->unk_3A >= 31) {
                p->unk_05 = 0;
                p->unk_02 = 0;
                if (p->unk_44 >= 0) {
                    func_8006071C(p->unk_44);
                }
                p->unk_44 = -1;
            }
            break;
        case 5:
            ang = func_800FA47C_BombsAway(&pos);
            d.x = func_800AEFD0(ang) * 5.5 * 100.0 + D_80100360_BombsAway.x - pos.x;
            d.z = func_800AEAC0(ang) * 4.5 * 100.0 + D_80100360_BombsAway.z - pos.z;
            func_800FC0EC_BombsAway(d.x, d.z);
            sqrtf(d.x * d.x + d.z * d.z);
            switch (p->unk_3C) {
                case 0:
                    p->unk_00 |= 8;
                    vel.y = p->unk_30 = -5.0f;
                    vel.x = vel.z = 0.0f;
                    D_80100314_BombsAway--;
                    p->unk_00 |= 2;
                    if (p->unk_44 >= 0) {
                        func_8006071C(p->unk_44);
                    }
                    p->unk_44 = -1;
                    p->unk_3E = 0;
                    p->unk_3A = 0;
                    p->unk_3C++;
                    break;
                case 1:
                    func_800F791C_BombsAway(obj, 16);
                    if (p->unk_3E == 0 && pos.y < 0.0) {
                        func_800FC530_BombsAway(func_80060618(0x45F, p->unk_06), &pos);
                        func_800FD4B8_BombsAway(pos.x, pos.y, pos.z, 0.75f);
                        func_800FC530_BombsAway(func_80060540(0x2BD, p->unk_06), &pos);
                        p->unk_00 |= 0x10;
                        if (D_80100148_BombsAway != 0 && GwPlayer[p->unk_06].group == 0) {
                            D_8010014A_BombsAway = 1;
                        }
                        p->unk_3E++;
                    }
                    if (vel.y > -50.0) {
                        vel.y += p->unk_30;
                    }
                    ang = (f32)p->unk_3A / 15.0;
                    if (ang > 1.0) {
                        ang = 1.0f;
                    }
                    vel.x = d.x * 0.1 * ang;
                    vel.z = d.z * 0.1 * ang;
                    if (pos.y < -100.0) {
                        p->unk_3C++;
                    }
                    break;
                case 2:
                    func_800F791C_BombsAway(obj, 16);
                    if (pos.y + vel.y > -50.0) {
                        pos.y = -50.0f;
                        vel.y = 0.0f;
                        p->unk_3C++;
                        func_800FB0D0_BombsAway(obj);
                    } else {
                        vel.y -= p->unk_30;
                    }
                    ang = (f32)p->unk_3A / 15.0;
                    if (ang > 1.0) {
                        ang = 1.0f;
                    }
                    vel.x = d.x * 0.1 * ang;
                    vel.z = d.z * 0.1 * ang;
                    break;
                case 3:
                case 4:
                    vel.x = d.x * 0.1;
                    vel.z = d.z * 0.1;
                    vel.y = 0.0f;
                    pos.y = -50.0f;
                    if (p->unk_3C == 4) {
                        vel.x = vel.z = vel.y;
                        p->unk_02 = 6;
                        func_800F791C_BombsAway(obj, 15);
                        guMtxIdentF(D_800F2B7C[obj->model[0]].unk7C);
                        p->unk_3C = 0;
                    }
                    break;
            }
            pos.x += vel.x;
            pos.y += vel.y;
            pos.z += vel.z;
            if (p->unk_3C >= 3) {
                func_800F7A14_BombsAway(obj, 15, 16);
            }
            break;
        case 6:
            if (p->unk_3C != 0) {
                D_800F2B7C[obj->model[0]].unk_0A |= 1;
                func_800258EC(obj->model[0], 4, 4);
            }
            func_800F7A14_BombsAway(obj, 15, 16);
            break;
        case 7:
            if (p->unk_44 >= 0) {
                func_8006071C(p->unk_44);
            }
            p->unk_44 = -1;
            func_800FA6FC_BombsAway(&obj->trans, &obj->trans);
            obj->rot.y = 0.0f;
            guMtxIdentF(D_800F2B7C[obj->model[0]].unk7C);
            vel.x = vel.y = vel.z = 0.0f;
            D_800F2B7C[obj->model[1]].unk_28 = obj->trans.y;
            if (D_80100140_BombsAway.unk_00 != 3) {
                func_800F791C_BombsAway(obj, 0);
            } else if (D_80100148_BombsAway == 0) {
                func_800F791C_BombsAway(obj, 13);
                if (p->unk_42 != 0) {
                    GwPlayer[p->unk_06].coins_mg += 10;
                }
                p->unk_42 = 0;
            } else {
                p->unk_42 = 0;
            }
            break;
        case 9:
            if (p->unk_3C == 0) {
                p->unk_00 |= 2;
                func_800F791C_BombsAway(obj, 11);
                if (p->unk_44 >= 0) {
                    func_8006071C(p->unk_44);
                }
                p->unk_44 = -1;
                ang = func_800FA47C_BombsAway(&pos);
                t = (600.0 - func_800FA4B4_BombsAway(&pos)) / 30.0;
                vel.x = func_800AEFD0(ang) * t;
                vel.y = 60.0f;
                vel.z = func_800AEAC0(ang) * t;
                p->unk_30 = -4.0f;
                p->unk_3E = ang;
                p->unk_3C++;
                p->unk_3A = 0;
                func_80060F04(p->unk_06, 30, 0, 30);
                if (D_80100694_BombsAway == 0) {
                    func_80060540(0x2BC, p->unk_06);
                    D_80100694_BombsAway = 10;
                }
            }
            vel.y += p->unk_30;
            pos.x += vel.x;
            pos.y += vel.y;
            pos.z += vel.z;
            n = p->unk_3A;
            if (n >= 7) {
                p->unk_3A = n - 6;
            }
            func_800A2A50(m1);
            func_8009E060(m1, p->unk_3A * 60.0f, 0.0f, 1.0f, 0.0f);
            m1[3][3] = 1.0f;
            func_800FC16C_BombsAway(&vel, &d);
            func_800A2A50(m2);
            func_8009ECB0(m2, d.x + 90.0f, d.y, d.z);
            m2[3][3] = 1.0f;
            func_800AC0B0(m1, m2, m2);
            func_800FC1F4_BombsAway(m2, &d);
            obj->rot.x = d.x;
            obj->rot.y = d.y;
            obj->rot.z = d.z;
            if (vel.y < 0.0 && pos.y < -50.0) {
                p->unk_02 = 5;
                p->unk_3C = 0;
                obj->rot.x = obj->rot.z = 0.0f;
            }
            break;
    }
    p->unk_18 = pos.x - obj->trans.x;
    p->unk_1C = pos.y - obj->trans.y;
    p->unk_20 = pos.z - obj->trans.z;
    p->unk_0C = vel.x;
    p->unk_10 = vel.y;
    p->unk_14 = vel.z;
    obj->trans.x = pos.x;
    obj->trans.y = pos.y;
    obj->trans.z = pos.z;
    p->unk_3A++;
    func_80017DB0(obj);
    func_8001802C(obj);
}
void func_800F9824_BombsAway(omObjData* obj) {
    u8* w;

    obj->func_ptr = func_800F997C_BombsAway;
    obj->model[0] = func_800174C0(0x350000, 0x99);
    D_80100360_BombsAway.x = obj->trans.x = 0.0f;
    D_80100364_BombsAway = obj->trans.y = -20.0f;
    D_80100368_BombsAway = obj->trans.z = 700.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80025830(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    D_80100358_BombsAway = 160.0f;
    D_8010035C_BombsAway = 0.8f;
    obj->unk_50 = w = func_80023684(0x2C, 0x7918);
    func_8009B770(w, 0, 0x2C);
    w[4] = 1;
    w[5] = 0;
    /* Retail passed the area kind as a float 0.0 (mfc1 a1): a prototype with an f32 second argument. */
    ((void (*)(omObjData*, f32, f32, f32, f32, f32))func_80009028)(obj, 0.0f, -2000.0f, -2000.0f, 2000.0f, 2000.0f);
}
// register allocation: the sine and 1.0f swap f20/f22 (masked 0)
#ifdef NON_MATCHING
void func_800F997C_BombsAway(omObjData* obj) {
    Matrix4f m;
    f32 p0[3];
    f32 p1[3];
    f32 p2[3];
    f32 out[3];
    BaStage* s = &D_80100328_BombsAway;
    f32 sx;
    f32 sz;
    f32 a;
    f32 k;
    f32 t;
    f32 v;
    s32 i;
    s32 j;

    if (D_80100140_BombsAway.unk_00 == 0 && D_80100140_BombsAway.unk_04 >= 61) {
        if (D_80100368_BombsAway > 100.0) {
            D_80100368_BombsAway = obj->trans.z = D_80100368_BombsAway - 10.0;
        }
    }
    if (s->unk_130 != 0) {
        sx = sz = 0.0f;
        for (i = 0; i < s->unk_130; i++) {
            /* Retail adds the weight's z where the plane's c * z belongs. */
            func_800FBF9C_BombsAway(s->unk_90, s->unk_134[i].unk_00,
                                    -(s->unk_110[0] * s->unk_134[i].unk_00 + s->unk_110[2] + s->unk_134[i].unk_08 -
                                      s->unk_110[3]) /
                                        s->unk_110[1],
                                    s->unk_134[i].unk_08, out);
            t = s->unk_134[i].unk_04 / 4.0;
            sx += t * out[0];
            sz += t * out[2];
        }
        t = func_800FC0EC_BombsAway(sx, sz) + 90.0;
        t -= (s32)(t / 360.0f) * 360;
        if (t < 0.0) {
            t += 360.0;
        }
        t -= s->unk_0C;
        if (t >= 0.0f) {
            if (t > 180.0) {
                t -= 360.0;
            }
        } else if (t < -180.0) {
            t += 360.0;
        }
        t = s->unk_0C + t * 0.2;
        if (t >= 360.0) {
            t -= 360.0;
        } else if (t < 0.0) {
            t += 360.0;
        }
        s->unk_0C = t;
        t = sqrtf(sx * sx + sz * sz) / 300.0;
        if (t > 1.0) {
            t = 1.0f;
        } else if (t < -1.0) {
            t = -1.0f;
        }
        s->unk_10 += (t - s->unk_10) * 0.2;
        s->unk_130 = 0;
    } else {
        s->unk_10 -= s->unk_10 * 0.1;
    }
    if (s->unk_20 > 0.0f) {
        s->unk_14 = (f32)(s->unk_14 + 6.0) - (s32)((f32)(s->unk_14 + 6.0) / 360.0f) * 360;
        if (s->unk_14 < 0.0) {
            s->unk_14 += 360.0;
        }
    }
    s->unk_18 = (f32)(s->unk_18 + 5.0) - (s32)((f32)(s->unk_18 + 5.0) / 360.0f) * 360;
    if (s->unk_18 < 0.0) {
        s->unk_18 += 360.0;
    }
    if (s->unk_1C > 0.0) {
        s->unk_1C -= 0.01;
        if (s->unk_1C < 0.0) {
            s->unk_1C = 0.0f;
        }
    }
    s->unk_28 -= 0.02;
    if (s->unk_28 < 0.0) {
        s->unk_28 = 0.0f;
    }
    if (s->unk_2C != 0) {
        s->unk_2C--;
    }
    s->unk_00 = (f32)(s->unk_00 + 2.0) - (s32)((f32)(s->unk_00 + 2.0) / 360.0f) * 360;
    if (s->unk_00 < 0.0) {
        s->unk_00 += 360.0;
    }
    s->unk_38.y = func_800AEAC0(s->unk_00) * 20.0 + -20.0;
    obj->trans.y = s->unk_38.y + ((f32)(D_80100144_BombsAway & 1) - 0.5) * 0.2 * 100.0 * s->unk_28;
    s->unk_04 += 2.0;
    if (s->unk_04 >= 360.0) {
        s->unk_04 -= 360.0;
    }
    s->unk_08 += 1.0;
    if (s->unk_08 >= 360.0) {
        s->unk_08 -= 360.0;
    }
    a = func_800AEAC0(s->unk_08) * 2.0;
    k = func_800AEFD0(s->unk_04);
    func_8009E060(s->unk_50, a, k, 0.0f, func_800AEAC0(s->unk_04));
    s->unk_50[3][3] = 1.0f;
    a = s->unk_10 * 8.0;
    k = func_800AEFD0(s->unk_0C);
    func_8009E060(m, a, k, 0.0f, func_800AEAC0(s->unk_0C));
    m[3][3] = 1.0f;
    func_800AC0B0(m, s->unk_50, s->unk_50);
    a = func_800AEAC0(s->unk_18) * 20.0;
    k = func_800AEFD0(s->unk_14);
    func_8009E060(m, a * s->unk_1C, k, 0.0f, func_800AEAC0(s->unk_14));
    m[3][3] = 1.0f;
    func_800AC0B0(m, s->unk_50, m);
    func_8009EA40(s->unk_50, obj->trans.x, obj->trans.y, obj->trans.z);
    func_800AC0B0(m, s->unk_50, s->unk_50);
    func_800FC1F4_BombsAway(s->unk_50, (Vec*)p0);
    obj->rot.x = s->unk_44.x = p0[0];
    obj->rot.y = s->unk_44.y = p0[1];
    obj->rot.z = s->unk_44.z = p0[2];
    for (j = 0; j < 4; j++) {
        s->unk_D0[j][0] = s->unk_90[j][0];
        s->unk_D0[j][1] = s->unk_90[j][1];
        s->unk_D0[j][2] = s->unk_90[j][2];
        s->unk_D0[j][3] = s->unk_90[j][3];
    }
    func_8009EA40(m, -obj->trans.x, -obj->trans.y, -obj->trans.z);
    MtxInv(s->unk_50, s->unk_90);
    func_800AC0B0(m, s->unk_90, s->unk_90);
    func_800FBF9C_BombsAway(s->unk_50, 0.0f, s->unk_30, 0.0f, p0);
    func_800FBF9C_BombsAway(s->unk_50, 1.0f, s->unk_30, 0.0f, p1);
    func_800FBF9C_BombsAway(s->unk_50, 0.0f, s->unk_30, 1.0f, p2);
    for (j = 0; j < 3; j++) {
        p1[j] -= p0[j];
        p2[j] = p0[j] - p2[j];
    }
    s->unk_110[0] = p1[1] * p2[2] - p1[2] * p2[1];
    s->unk_110[1] = p1[2] * p2[0] - p1[0] * p2[2];
    s->unk_110[2] = p1[0] * p2[1] - p1[1] * p2[0];
    s->unk_110[3] = p0[0] * s->unk_110[0] + p0[1] * s->unk_110[1] + p0[2] * s->unk_110[2];
    s->unk_120 = 1.0 / sqrtf(s->unk_110[0] * s->unk_110[0] + s->unk_110[1] * s->unk_110[1] +
                             s->unk_110[2] * s->unk_110[2]);
    s->unk_124.x = s->unk_110[0] * s->unk_120;
    s->unk_124.y = s->unk_110[1] * s->unk_120;
    s->unk_124.z = s->unk_110[2] * s->unk_120;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_BombsAway/1AA2A0", func_800F997C_BombsAway);
#endif
f32 func_800FA47C_BombsAway(Vec* pos) {
    return func_800FC0EC_BombsAway(pos->x - D_80100328_BombsAway.unk_38.x, pos->z - D_80100328_BombsAway.unk_38.z);
}
f32 func_800FA4B4_BombsAway(Vec* pos) {
    f32 dx = pos->x - D_80100360_BombsAway.x;
    f32 dz = pos->z - D_80100360_BombsAway.z;

    return sqrtf(dx * dx + dz * dz);
}
s32 func_800FA514_BombsAway(Vec* pos, Vec* out) {
    BaStage* s = &D_80100328_BombsAway;
    f32 d = pos->x * D_80100438_BombsAway + pos->y * D_8010043C_BombsAway + pos->z * D_80100440_BombsAway -
            D_80100444_BombsAway;

    if (d <= 0.0) {
        d *= s->unk_120;
        out->x = pos->x - d * s->unk_124.x;
        out->y = pos->y - d * s->unk_124.y;
        out->z = pos->z - d * s->unk_124.z;
        return 1;
    }
    return 0;
}
s32 func_800FA5D8_BombsAway(Vec* pos) {
    f32 out[3];

    func_800FBF9C_BombsAway(D_801003B8_BombsAway, pos->x, pos->y, pos->z, out);
    if (out[0] * out[0] + out[2] * 1.35 * out[2] * 1.35 <= 230400.0) {
        return 1;
    }
    return 0;
}
s32 func_800FA664_BombsAway(Vec* pos) {
    Vec v;
    s32 i = 0;
    f32 h = BA_PLANE_HEIGHT(pos, i);

    v.x = pos->x;
    v.y = h + pos->y;
    v.z = pos->z;
    if (50.0 <= h) {
        return 0;
    }
    return func_800FA5D8_BombsAway(&v);
}
s32 func_800FA6FC_BombsAway(Vec* pos, Vec* out) {
    Vec v;
    s32 i = 0;
    f32 h = BA_PLANE_HEIGHT(pos, i);
    s32 ret;

    v.x = pos->x;
    v.y = h + pos->y;
    v.z = pos->z;
    if (func_800FA5D8_BombsAway(&v) == 0) {
        return 0;
    }
    if (h < 50.0) {
        out->x = v.x;
        out->y = v.y;
        out->z = v.z;
        ret = -1;
        if (0.0f <= h) {
            ret = 1;
        }
        return ret;
    }
    return 0;
}
s32 func_800FA7E8_BombsAway(Vec* pos, Vec* vel, Vec* out, s16 onStage) {
    BaStage* s = &D_80100328_BombsAway;
    Vec next;
    Vec tmp;
    Vec cur;
    f32 t;
    f32 den;
    s32 ret = 0;

    if (onStage != 0) {
        func_800FBF9C_BombsAway(s->unk_D0, pos->x, pos->y, pos->z, &tmp.x);
        func_800FBF9C_BombsAway(s->unk_50, tmp.x, tmp.y, tmp.z, &cur.x);
        if (vel->x == 0.0f && vel->y == 0.0f && vel->z == 0.0f) {
            out->x = cur.x;
            out->y = cur.y;
            out->z = cur.z;
            return 1;
        }
        ret = 1;
    } else {
        if (vel->x == 0.0f && vel->y == 0.0f && vel->z == 0.0f) {
            return 0;
        }
        cur.x = pos->x;
        cur.y = pos->y;
        cur.z = pos->z;
    }
    t = -(cur.x * s->unk_110[0] + cur.y * s->unk_110[1] + cur.z * s->unk_110[2] - s->unk_110[3]);
    den = vel->x * s->unk_110[0] + vel->y * s->unk_110[1] + vel->z * s->unk_110[2];
    t /= den;
    if (den < 0.0 && !(t > 1.0)) {
        ret = 1;
    } else {
        t = 1.0f;
    }
    next.x = t * vel->x + cur.x;
    next.y = t * vel->y + cur.y;
    next.z = t * vel->z + cur.z;
    if (func_800FA664_BombsAway(&next) == 0) {
        out->x = cur.x + vel->x;
        out->y = cur.y + vel->y;
        out->z = cur.z + vel->z;
        ret = 0;
        if (onStage == 0) {
            if (out->y < -50.0) {
                out->y = -50.0f;
                ret = -1;
            }
        } else {
            ret = -1;
        }
        return ret;
    }
    if (ret != 0) {
        cur.x += vel->x;
        cur.y += vel->y;
        cur.z += vel->z;
        if (func_800FA514_BombsAway(&cur, &tmp) != 0) {
            next.x += (tmp.x - next.x) * s->unk_34;
            next.y += (tmp.y - next.y) * s->unk_34;
            next.z += (tmp.z - next.z) * s->unk_34;
        }
    }
    out->x = next.x;
    out->y = next.y;
    out->z = next.z;
    return ret;
}
s32 func_800FAB74_BombsAway(Vec* pos, Vec* dir, Vec* out) {
    BaStage* s = &D_80100328_BombsAway;
    Vec v;
    Vec d;
    f32 t;
    f32 den;
    s32 ok;

    if (dir->y >= 0.0) {
        return 0;
    }
    d.x = pos->x - dir->x;
    d.y = pos->y - dir->y;
    d.z = pos->z - dir->z;
    t = -(d.x * s->unk_110[0] + d.y * s->unk_110[1] + d.z * s->unk_110[2] - s->unk_110[3]);
    den = dir->x * s->unk_110[0] + dir->y * s->unk_110[1] + dir->z * s->unk_110[2];
    t /= den;
    if (den < 0.0) {
        ok = 1;
        if (t > 1.0) {
            ok = 0;
        }
    } else {
        ok = 0;
    }
    if (ok) {
        v.x = t * dir->x + d.x;
        v.y = t * dir->y + d.y;
        v.z = t * dir->z + d.z;
        if (func_800FA5D8_BombsAway(&v) != 0) {
            out->x = v.x;
            out->y = v.y;
            out->z = v.z;
            return 1;
        }
    }
    if (pos->y <= 0.0) {
        t = -(d.y - 0.0) / dir->y;
        out->x = t * dir->x + d.x;
        out->y = t * dir->y + d.y;
        out->z = t * dir->z + d.z;
        return -1;
    }
    return 0;
}
void func_800FADA8_BombsAway(f32 x, f32 z, f32 weight) {
    BaStage* s = &D_80100328_BombsAway;
    s32 n = D_80100458_BombsAway;

    if (n < 8) {
        D_80100458_BombsAway = n + 1;
        s->unk_134[n].unk_00 = x;
        s->unk_134[n].unk_04 = weight;
        s->unk_134[n].unk_08 = z;
    }
}
void func_800FADF4_BombsAway(f32 x, f32 z, f32 dir) {
    BaStage* s;
    f32 a;

    if (D_80100140_BombsAway.unk_00 == 1) {
        s = &D_80100328_BombsAway;
        if (D_801006F8_BombsAway >= 0) {
            D_80100698_BombsAway[D_801006F8_BombsAway].unk_00 = 0;
        }
        a = func_800FC0EC_BombsAway(x, z) + 90.0;
        a = a - (s32)(a / 360.0f) * 360;
        s->unk_14 = a;
        if (s->unk_14 < 0.0) {
            s->unk_14 += 360.0;
        }
        if (dir >= 0.0) {
            s->unk_00 = 270.0f;
            s->unk_18 = 180.0f;
            s->unk_20 = 1.0f;
            s->unk_28 = 1.0f;
            s->unk_2C = 15;
        } else {
            s->unk_00 = 0.0f;
            s->unk_18 = 0.0f;
            dir = -dir;
            s->unk_20 = -1.0f;
            s->unk_28 = 0.0f;
            s->unk_2C = 0;
            D_801004BC_BombsAway = 2;
        }
        if (dir > 1.0) {
            dir = 1.0f;
        }
        s->unk_1C = dir;
    }
}
void func_800FAFB4_BombsAway(void) {
    u16 ids[] = { 8, 9, 10, 11, 12, 13, 0xFFFF };
    s32 dir = 0x350000;
    s32 i;

    for (i = 0; ids[i] != 0xFFFF; i++) {
        D_801004D0_BombsAway[i] = func_800174C0(dir | ids[i], 0x9D);
    }
    for (i = 0; i < 4; i++) {
        D_801004E0_BombsAway.unk_00[i] = NULL;
        D_801004F0_BombsAway[i] = NULL;
    }
}
void func_800FB0D0_BombsAway(omObjData* obj) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_801004E0_BombsAway.unk_00[i] == NULL) {
            break;
        }
    }
    if (i < 4) {
        D_801004E0_BombsAway.unk_00[i] = obj;
    }
}
s16 func_800FB120_BombsAway(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_801004E0_BombsAway.unk_00[i] >= (omObjData*)2) {
            break;
        }
    }
    if (i < 4) {
        D_801004E0_BombsAway.unk_10[i] = D_801004E0_BombsAway.unk_00[i];
        D_801004E0_BombsAway.unk_00[i] = (omObjData*)1;
        return i;
    }
    return -1;
}
void func_800FB19C_BombsAway(s16 i) {
    D_801004E0_BombsAway.unk_00[i] = D_801004E0_BombsAway.unk_10[i] = NULL;
}
void func_800FB1C4_BombsAway(omObjData* obj) {
    func_800FB1FC_BombsAway(obj, 0);
}
void func_800FB1E0_BombsAway(omObjData* obj) {
    func_800FB1FC_BombsAway(obj, 1);
}
void func_800FB1FC_BombsAway(omObjData* obj, u8 kind) {
    obj->func_ptr = func_800FB2E4_BombsAway;
    omSetStatBit(obj, 0xA0);
    obj->model[0] = func_800174C0(0x350008, 0x99);
    func_80026040(obj->model[0]);
    obj->trans.x = obj->trans.z = 0.0f;
    obj->trans.y = -80.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 0.8f;
    obj->work[0] = obj->work[1] = obj->work[2] = obj->work[3] = 0;
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80025830(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    obj->work[0] = 0;
    obj->work[3] = kind;
}



void func_800FB2E4_BombsAway(omObjData* obj) {
    f32 drop[] = { -50.0f, -20.0f, 1000.0f, -90.0f, 50.0f, -50.0f, -1000.0f, 90.0f };
    f32 start[] = { -800.0f, 300.0f, 800.0f, 300.0f, -200.0f, 400.0f, 200.0f, 400.0f };
    s16 visible;
    s32 side;
    omObjData* carrier;
    BaPlayer* cp;
    f32 dx;
    f32 dz;
    f32 ang;
    f32 s;
    s32 k;
    s16 n; /* the slot (case 0), then k * 4 (cases 2, 3) */
    u16 m0;
    u16 m1;

    visible = 1;
    if (func_8005FD5C() + D_800F64F8 != 0) {
        visible = obj->work[0] != 0;
    } else {
        switch (obj->work[0]) {
            case 0:
                n = func_800FB120_BombsAway();
                if (n >= 0) {
                    obj->work[0]++;
                    obj->work[1] = n;
                    carrier = D_801004F0_BombsAway[n];
                    obj->work[3] = carrier->trans.x >= 0.0;
                } else {
                    visible = 0;
                }
                side = obj->work[3];
                obj->trans.x = start[side * 2];
                obj->trans.z = start[side * 2 + 1];
                break;
            case 1:
                carrier = D_801004F0_BombsAway[obj->work[1]];
                cp = func_800F78D4_BombsAway(carrier);
                dx = carrier->trans.x - obj->trans.x;
                dz = carrier->trans.z - obj->trans.z;
                ang = func_800FC0EC_BombsAway(dx, dz);
                s = func_800AEAC0((f32)obj->work[2] / 256.0 * 360.0) * 0.5 + 0.5;
                obj->trans.x += func_800AEFD0(ang) * (s * 0.1 + 0.05) * 100.0;
                obj->trans.z += func_800AEAC0(ang) * (s * 0.1 + 0.05) * 100.0;
                if (sqrtf(dx * dx + dz * dz) < 50.0) {
                    cp->unk_3C = 4;
                    if (carrier->trans.x > 0.0) {
                        obj->work[0] = 2;
                    } else {
                        obj->work[0] = 3;
                    }
                }
                break;
            case 2:
            case 3:
                carrier = D_801004F0_BombsAway[obj->work[1]];
                cp = func_800F78D4_BombsAway(carrier);
                k = obj->work[0] - 2;
                n = k * 4;
                s = func_800AEAC0((f32)obj->work[2] / 256.0 * 360.0) * 0.5 + 0.5;
                dx = drop[k * 4 + 2] - obj->trans.x;
                dz = 200.0 - obj->trans.z;
                ang = func_800FC0EC_BombsAway(dx, dz);
                obj->trans.x += func_800AEFD0(ang) * (s * 0.1 + 0.05) * 100.0;
                obj->trans.z += func_800AEAC0(ang) * (s * 0.1 + 0.05) * 100.0;
                if (sqrtf(dx * dx + dz * dz) < 50.0) {
                    obj->work[0] = 0;
                    cp->unk_3C++;
                    func_800FB19C_BombsAway(obj->work[1]);
                }
                carrier->trans.x += (obj->trans.x + drop[n] - carrier->trans.x) * 0.2;
                carrier->trans.y += (obj->trans.y + drop[n + 1] - carrier->trans.y) * 0.2;
                carrier->trans.z += (obj->trans.z - carrier->trans.z) * 0.2;
                carrier->rot.y = drop[n + 3];
                break;
        }
        obj->work[2] += 8;
    }
    if (visible) {
        func_800258EC(obj->model[0], 4, 0);
        m0 = D_801004D0_BombsAway[D_800FFAAC_BombsAway[obj->work[0]][0]];
        m1 = D_801004D0_BombsAway[D_800FFAAC_BombsAway[obj->work[0]][1]];
        func_800FBF08_BombsAway(obj->model[0], m0, m1,
                                func_800AEAC0((f32)obj->work[2] / 256.0 * 360.0) * 0.5 + 0.5);
    } else {
        func_800258EC(obj->model[0], 4, 4);
    }
}
void func_800FB988_BombsAway(void) {
    Vec v;
    s32 i;
    s32 j;
    s32 idx;
    s32 ph;
    BaSparkle* sp;
    omObjData* obj;

    D_80100692_BombsAway = -1;
    for (i = 0; i < 4; i++) {
        idx = i * 3;
        sp = &D_801005A0_BombsAway[idx];
        if (D_80100150_BombsAway[i].unk_02 == 3) {
            obj = D_80100150_BombsAway[i].unk_48;
            for (j = 0; j < 3; j++) {
                func_80067480(D_801006FC_BombsAway, idx, 0x8000);
                ph = (sp->unk_02 + j * 10) & 0x1F;
                v.x = obj->trans.x + func_800AEFD0(ph * 360 / 32) * 100.0 * 0.5;
                v.z = obj->trans.z + func_800AEAC0(ph * 360 / 32) * 100.0 * 0.5;
                v.y = obj->trans.y + 160.0 + func_800AEAC0((ph & 0xF) * 24) * 100.0 * 0.2;
                func_80066DF4(D_801006FC_BombsAway, idx, 0, v.x, v.y, v.z);
                func_800671DC(D_801006FC_BombsAway, idx, 0);
                sp->unk_02++;
                idx++;
                sp++;
            }
            D_80100692_BombsAway = i;
        } else {
            for (; idx < (i + 1) * 3; idx++) {
                func_800674BC(D_801006FC_BombsAway, idx, 0x8000);
            }
        }
    }
    if (D_80100690_BombsAway < 0) {
        if (D_80100692_BombsAway >= 0) {
            D_80100690_BombsAway = func_80060540(0x155, D_80100692_BombsAway);
        }
    } else if (D_80100692_BombsAway < 0) {
        func_8006071C(D_80100690_BombsAway);
        D_80100690_BombsAway = -1;
    }
    if (D_80100694_BombsAway != 0) {
        D_80100694_BombsAway--;
    }
}