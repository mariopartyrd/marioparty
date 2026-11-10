#include "ChanceTime.h"

void func_80055B64(void);
void func_80055B80(void);


f32 func_80025D18(s16);
f32 func_80025D40(s16);


void func_80055810(s32, s32, s32);


void func_80025BB8(s16, s16);
void func_80055B50(s32, s32);
void func_80055B64(void);
/* The camera paths: retail reads the start Vec as the end Vec's [-1] (adjacent .data objects, one
   base register: D_801011FC/D_80101208, D_80101214/D_80101220); the host names the object. */
#define CT_PREV(cur, prev) ((&(cur))[-1])


void func_8005049C(void);
void func_80055A40(s32);
void func_8007B168(u8*, u8);
extern s16 D_800EE984;
extern omObjData* D_800F2AF8[];
extern s8 omSysPauseEnableFlag;
/* Retail calls func_80055A40 unprototyped with two arguments (-1, -1); the host calls it normally. */
#define func_80055A40_unproto(a, b) ((void (*)())func_80055A40)(a, b)


u16 func_8004F234(void);
int abs(int);


void func_800090C4(omObjData* obj, u8 idx, u8 val);
void func_800093FC(omObjData* obj, f32 x, f32 y, f32 z);
extern f32 D_800B8964;
extern f32 D_800B8968;


/* .data (0x801011F0..0x801012B0) */
s8 D_801011F0_ChanceTime = 0;
s8 D_801011F1_ChanceTime = 1;
s8 D_801011F2_ChanceTime = 0;
s8 D_801011F3_ChanceTime = 0;
s8 D_801011F4_ChanceTime = 0;
s8 D_801011F5_ChanceTime = 0;
s8 D_801011F6_ChanceTime = 0;
s8 D_801011F7_ChanceTime = 0;
s8 D_801011F8_ChanceTime = 0;
s8 D_801011F9_ChanceTime = 1;
Vec D_801011FC_ChanceTime = { 400.0f, 0.0f, 1520.0f };
Vec D_80101208_ChanceTime = { 90.0f, 0.0f, 1520.0f };
Vec D_80101214_ChanceTime = { -250.0f, 0.0f, 1700.0f };
Vec D_80101220_ChanceTime = { -125.0f, 0.0f, 1550.0f };
Vec D_8010122C_ChanceTime = { -325.0f, 0.0f, 1300.0f };
Vec D_80101238_ChanceTime = { -90.0f, 0.0f, 1480.0f };
Vec D_80101244_ChanceTime = { -140.0f, 0.0f, 1500.0f };
u32 D_80101250_ChanceTime = 0;
s32 D_80101254_ChanceTime = 0;
s8 D_80101258_ChanceTime = 0;
s8 D_80101259_ChanceTime = 0;
s8 D_8010125A_ChanceTime = 0;
s8 D_8010125B_ChanceTime = 0;
s8 D_8010125C_ChanceTime = 0;
f32 D_80101260_ChanceTime = 0.0f;
s16 D_80101264_ChanceTime = 0xFF;
u16 D_80101266_ChanceTime = 0;
u16 D_80101268_ChanceTime = 0;
u8 D_8010126A_ChanceTime = 0;
u16 D_8010126C_ChanceTime = 0;
s8 D_8010126E_ChanceTime = 0;
s8 D_8010126F_ChanceTime = 0;
s8 D_80101270_ChanceTime = 0;
s32 D_80101274_ChanceTime = 0;
s32 D_80101278_ChanceTime = 0;
u32 D_8010127C_ChanceTime = 0;
s8 D_80101280_ChanceTime = 0;
s8 D_80101281_ChanceTime = 0;
omObjData* D_80101284_ChanceTime = NULL;
u32 D_80101288_ChanceTime = 0xFFFFFFFF;
s8 D_8010128C_ChanceTime = 0;
f32 D_80101290_ChanceTime = 0.0f;
s8 D_80101294_ChanceTime = 0;
s8 D_80101298_ChanceTime[2] = { 0, 0 };
f32 D_8010129C_ChanceTime = 0.0f;
s8 D_801012A0_ChanceTime = 0;
s32 D_801012A4_ChanceTime = 0;
s32 D_801012A8_ChanceTime = 0;
u32 D_801012AC_ChanceTime = 0;

void func_800F65E0_ChanceTime(void) {
    s16 i;
    s16 n;

    for (i = 0; i < 4; i++) {
        if (GwPlayer[i].group == 0) {
            break;
        }
    }
    switch (i) {
    case 1:
        D_80101AAE_ChanceTime[0] = 1;
        break;
    case 2:
        D_80101AAE_ChanceTime[0] = 2;
        break;
    case 3:
        D_80101AAE_ChanceTime[0] = 3;
        break;
    case 0:
    default:
        D_80101AAE_ChanceTime[0] = 0;
        break;
    }
    for (i = 1, n = 0; i < 4; i++, n++) {
        if (D_80101AAE_ChanceTime[0] == n) {
            n++;
        }
        D_80101AAE_ChanceTime[i] = n;
    }
    func_80029090(0xA);
    func_8002ADF0(&D_800EDEC0, 0x40);
    func_8001DE70(0x3C);
    omInitObjMan(0x28, 0x3C);
    func_8006CEA0();
    func_80060088();
    func_80055A40_unproto(-1, -1);
    func_800178A0(1);
    func_800234B8(1, 0x40, 0x40, 0x60);
    func_80023504(1, -72.0f, 16.0f, 94.0f);
    omSysPauseEnableFlag = 1;
    D_801011F0_ChanceTime = _CheckFlag(0x45);
    func_80017660(0, 0.0f, 0.0f, 319.0f, 239.0f);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 20.0f, 80.0f, 8000.0f);
    LoadBackgroundData(D_FE2310);
    func_8005049C();
    func_8000942C();
    func_80009468();
    func_80009500();
    func_80009618(1);
    /* "ＣＨＡＮＣＥＴＩＭＥ" / "ＣＨＡＮＣＥＴＩＭＥ？" */
    func_8007B168(D_801011F0_ChanceTime == 0
                      ? (u8*)"\x82\x62\x82\x67\x82\x60\x82\x6D\x82\x62\x82\x64\x82\x73\x82\x68\x82\x6C\x82\x64"
                      : (u8*)"\x82\x62\x82\x67\x82\x60\x82\x6D\x82\x62\x82\x64\x82\x73\x82\x68\x82\x6C\x82\x64\x81\x48",
                  1);
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    if (D_801011F0_ChanceTime == 0) {
        omAddObj(1, 0xA, 5, -1, &func_800F99D8_ChanceTime);
    } else {
        omAddObj(1, 0xA, 0xA, -1, &func_800FC1C8_ChanceTime);
    }
    func_800090B8(D_800ED440);
    D_800F2AF8[D_800ED440++] = omAddObj(1, 0, 0, -1, &func_800FF780_ChanceTime);
    D_800F2AF8[D_800ED440++] = omAddObj(0xC, 0, 0, -1, &func_800FF8A4_ChanceTime);
    func_800FC390_ChanceTime();
    D_80101840_ChanceTime[0] = omAddObj(0xC, 2, 0, -1, &func_800FCC18_ChanceTime);
    D_80101840_ChanceTime[1] = omAddObj(0xC, 2, 0, -1, &func_800FD7DC_ChanceTime);
    if (D_801011F0_ChanceTime == 0) {
        /* retail: D_80101848 through the D_80101840 base (s0 + 8) */
        D_80101840_ChanceTime[2] = omAddObj(0xC, 2, 0, -1, &func_800FE554_ChanceTime);
    } else {
        D_80101848_ChanceTime = omAddObj(0xC, 2, 0, -1, &func_800FE9D8_ChanceTime);
    }
    omAddObj(5, 4, 0, -1, &func_800FF930_ChanceTime);
    omAddObj(0, 0, 0, -1, &func_800F6B00_ChanceTime);
    D_80101AD8_ChanceTime = omAddObj(5, 0x32, 0, -1, &func_800FB950_ChanceTime);
    omAddObj(0, 0, 0, -1, &func_800FEBA0_ChanceTime);
    D_800F3FB0[D_800F2BC0++] = omAddObj(0xA, 9, 0x2B, -1, &func_800F7818_ChanceTime);
    SetFadeInTypeAndTime(D_801011F0_ChanceTime == 0 ? 5 : 3, 0x10);
}




// delay-slot residue: retail hoists the else call's `li v0,1` (last GMesCreate argument) into the
// branch delay slot (one instruction longer); the rest is identical (masked 42 from the shift)
#ifdef NON_MATCHING
void func_800F6B00_ChanceTime(omObjData* obj) {
    CTPlayerWork* work;

    func_80009468();
    work = CT_PWORK(D_800F3FB0[0]);
    switch (D_800ED430) {
    case 0:
        if (D_80101250_ChanceTime == 0) {
            func_80060128(0x24);
            D_801011F2_ChanceTime = 1;
            D_801011F7_ChanceTime = 1;
            D_80101250_ChanceTime++;
        }
        if (D_801011F3_ChanceTime != 1) {
            break;
        }
        if (D_80101250_ChanceTime == 10) {
            /* "ＣＨＡＮＣＥ　ＴＩＭＥ" / "ＣＨＡＮＣＥ　ＴＩＭＥ♪" */
            if (D_801011F0_ChanceTime == 0) {
                D_801016F0_ChanceTime = GMesCreate(7, "\x82\x62\x82\x67\x82\x60\x82\x6D\x82\x62\x82\x64\x81\x40\x82\x73\x82\x68\x82\x6C\x82\x64",
                                                   0xA0, 0x64, 0, 0, 0, 0, 1);
            } else {
                D_801016F0_ChanceTime = GMesCreate(7, "\x82\x62\x82\x67\x82\x60\x82\x6D\x82\x62\x82\x64\x81\x40\x82\x73\x82\x68\x82\x6C\x82\x64\x81\xF3",
                                                   0xA0, 0x64, 0, 0, 0, 0, 1);
            }
            D_80101260_ChanceTime = 0.0f;
        }
        if (D_80101250_ChanceTime >= 11) {
            if (GMesStatAllGet() == 0 || (GMesStatAllGet() & 2)) {
                D_801012B6_ChanceTime = 1;
                func_80009458();
            } else {
                if (D_8010125B_ChanceTime == 0) {
                    PlaySound(0x43B);
                    D_8010125B_ChanceTime = 1;
                }
                if (GMesData[D_801016F0_ChanceTime].unk_04 + 40 < GMesData[D_801016F0_ChanceTime].unk_06) {
                    if (D_8010125C_ChanceTime == 0) {
                        GMesData[D_801016F0_ChanceTime].unk_5C += 0.3f;
                        GMesData[D_801016F0_ChanceTime].unk_60 += 0.3f;
                        if (GMesData[D_801016F0_ChanceTime].unk_5C > 1.2) {
                            GMesData[D_801016F0_ChanceTime].unk_5C += 1.0f;
                            GMesData[D_801016F0_ChanceTime].unk_60 += 1.0f;
                            D_8010125C_ChanceTime = 1;
                        }
                    } else {
                        GMesData[D_801016F0_ChanceTime].unk_5C = func_800AEFD0(D_80101260_ChanceTime) * 0.3f + 1.0f;
                        GMesData[D_801016F0_ChanceTime].unk_60 = func_800AEFD0(D_80101260_ChanceTime) * 0.3f + 1.0f;
                        D_80101260_ChanceTime += 60.0f;
                    }
                } else if (GMesData[D_801016F0_ChanceTime].unk_04 + 20 > GMesData[D_801016F0_ChanceTime].unk_06) {
                    GMesData[D_801016F0_ChanceTime].unk_5C = 1.0f;
                    GMesData[D_801016F0_ChanceTime].unk_60 = 1.0f;
                    GMesData[D_801016F0_ChanceTime].unk_03 = D_80101265_ChanceTime;
                    D_80101264_ChanceTime -= 12;
                    if (D_80101264_ChanceTime < 0) {
                        D_80101264_ChanceTime = 0;
                    }
                } else {
                    GMesData[D_801016F0_ChanceTime].unk_5C = 1.0f;
                    GMesData[D_801016F0_ChanceTime].unk_60 = 1.0f;
                }
            }
        }
        D_80101250_ChanceTime++;
        break;
    case 1:
        if ((u16)D_801012B0_ChanceTime[0] != 0 && (u16)D_801012B0_ChanceTime[1] != 0 && (u16)D_801012B0_ChanceTime[2] != 0 &&
            D_80101258_ChanceTime == 0) {
            if (work->unk_38 == 1000.0f && (work->unk_5C & 6) && D_80101254_ChanceTime == 0) {
                D_801011F8_ChanceTime = 1;
                func_80009730();
                work->unk_3C = 0.0f;
                work->unk_40 = 0.0f;
                D_80101254_ChanceTime = 1;
            }
            if (D_80101254_ChanceTime != 0) {
                D_801011F2_ChanceTime = 2;
                D_801011F7_ChanceTime = 2;
                D_80101258_ChanceTime = 1;
            }
        }
        break;
    case 2:
        func_80009448();
        break;
    case 3:
        func_80009730();
        if (D_8010125A_ChanceTime == 0) {
            D_8010125A_ChanceTime = 1;
        } else if (D_80101259_ChanceTime == 0) {
            func_800726AC(D_801011F0_ChanceTime == 0 ? 5 : 3, 0x10);
            func_800601D4(0x28);
            D_80101259_ChanceTime = 1;
        } else if (func_80072718() == 0) {
            func_80054654();
            func_8004A140();
            func_80049F0C();
            GMesSprClose();
            func_80070ED4();
            omOvlReturnEx(1);
        }
        break;
    }
}
#else
INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_01_ChanceTime/D51E0", D_801013B0_ChanceTime);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_01_ChanceTime/D51E0", D_801013C8_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_ChanceTime/D51E0", func_800F6B00_ChanceTime);
#endif
void func_800F7108_ChanceTime(omObjData* obj) {
    omObjData* objs[3];
    CTReel* reels[3];
    CTPlayerWork* work;
    s16 i;
    u16 btn;
    f32 angle;
    s8 port;
    u16 cur;

    btn = 0;
    angle = -1.0f;
    work = CT_PWORK(obj);
    /* Dead locals. [2] is D_80101848 (the third panel) read through D_80101840; the panels'
       reels are read from the omObjData itself (offset 0x28), not from its work. */
    for (i = 0; i < 3; i++) {
        objs[i] = D_80101840_ChanceTime[i];
        reels[i] = ((CTObjWork*)objs[i])->unk_28;
    }
    D_80101AA6_ChanceTime[work->unk_56] = ContBtn[work->unk_56];
    D_80101ACA_ChanceTime[work->unk_56] = ContStkX[work->unk_56];
    D_80101A98_ChanceTime[work->unk_56] = ContStkY[work->unk_56];
    D_80101AC2_ChanceTime[work->unk_56] = ContBtnTrg[work->unk_56];
    if (GwPlayer[work->unk_58].flags & 1) {
        if (D_80101266_ChanceTime == 0) {
            if (D_801011F0_ChanceTime == 0) {
                D_801016FA_ChanceTime = 1;
                if ((guRandom() & 0x10) == 0) {
                    D_801016F8_ChanceTime[0] = 0;
                    D_801016F8_ChanceTime[1] = 2;
                } else {
                    D_801016F8_ChanceTime[0] = 2;
                    D_801016F8_ChanceTime[1] = 0;
                }
            } else {
                D_801016F8_ChanceTime[0] = 0;
                D_801016F8_ChanceTime[1] = 1;
            }
            D_80101266_ChanceTime = 1;
        }
        if (D_800ED430 == 1) {
            if (D_801011F0_ChanceTime == 0) {
                if (D_8010126C_ChanceTime == 0) {
                    if (D_8010126A_ChanceTime < 3) {
                        angle = (obj->trans.x + 1000.0f > D_80101840_ChanceTime[D_801016F8_ChanceTime[D_8010126A_ChanceTime]]->trans.x + 1000.0f) ? 180.0f : 0.0f;
                        if (abs((s32)((obj->trans.x + 1000.0f) - (D_80101840_ChanceTime[D_801016F8_ChanceTime[D_8010126A_ChanceTime]]->trans.x + 1000.0f))) < 21) {
                            angle = -1.0f;
                            D_8010126C_ChanceTime = 1;
                            D_801016F4_ChanceTime = 0;
                            D_801016FC_ChanceTime = guRandom() % 30 + 60;
                        }
                    }
                    btn = 0;
                }
                if (D_8010126C_ChanceTime == 1) {
                    if (D_801016F4_ChanceTime++ > D_801016FC_ChanceTime) {
                        D_8010126A_ChanceTime++;
                        D_8010126C_ChanceTime = 0;
                        btn = 0x8000;
                    } else {
                        work->unk_3C = 0.0f;
                    }
                }
            } else {
                if (D_8010126C_ChanceTime == 0) {
                    if (D_8010126A_ChanceTime < 2) {
                        angle = (obj->trans.x + 1000.0f > D_80101840_ChanceTime[D_801016F8_ChanceTime[D_8010126A_ChanceTime]]->trans.x + 1000.0f) ? 180.0f : 0.0f;
                        if (abs((s32)((obj->trans.x + 1000.0f) - (D_80101840_ChanceTime[D_801016F8_ChanceTime[D_8010126A_ChanceTime]]->trans.x + 1000.0f))) < 21) {
                            angle = -1.0f;
                            D_8010126C_ChanceTime = 1;
                            D_801016F4_ChanceTime = 0;
                            D_801016FC_ChanceTime = guRandom() % 30 + 60;
                        }
                    }
                    btn = 0;
                }
                if (D_8010126C_ChanceTime == 1) {
                    if (D_801016F4_ChanceTime++ > D_801016FC_ChanceTime) {
                        D_8010126A_ChanceTime++;
                        D_8010126C_ChanceTime = 0;
                        btn = 0x8000;
                    } else {
                        work->unk_3C = 0.0f;
                    }
                }
            }
            port = work->unk_56;
            cur = btn | (ContBtn[port] & 0x7FFF);
            btn = cur;
            ContBtn[port] = btn;
            ContBtnTrg[port] = btn;
            ContBtnTrg[work->unk_56] = cur & (cur ^ D_80101268_ChanceTime);
            D_80101268_ChanceTime = btn;
            if (angle < 0.0f) {
                ContStkX[work->unk_56] = 0;
                ContStkY[work->unk_56] = 0;
            } else {
                ContStkX[work->unk_56] = (s32)(func_800AEFD0(angle) * 40.0f);
                ContStkY[work->unk_56] = (s32)(-func_800AEAC0(angle) * 40.0f);
            }
        }
    }
    if (D_801011F8_ChanceTime == 1) {
        ContBtn[work->unk_56] = D_80101A9C_ChanceTime[work->unk_56];
        ContStkX[work->unk_56] = D_80101AB8_ChanceTime[work->unk_56];
        ContStkY[work->unk_56] = D_80101AB2_ChanceTime[work->unk_56];
        ContBtnTrg[work->unk_56] = D_80101ACE_ChanceTime[work->unk_56];
    }
    func_80005A28(obj);
    if (obj->trans.y <= 0.0f) {
        D_801011F1_ChanceTime = 1;
    }
    ContBtn[work->unk_56] = D_80101AA6_ChanceTime[work->unk_56];
    ContStkX[work->unk_56] = D_80101ACA_ChanceTime[work->unk_56];
    ContStkY[work->unk_56] = D_80101A98_ChanceTime[work->unk_56];
    ContBtnTrg[work->unk_56] = D_80101AC2_ChanceTime[work->unk_56];
}
void func_800F7818_ChanceTime(omObjData* arg0) {
    s32 temp_v0;
    s32 temp_a1;
    s32 temp_a2;

    temp_v0 = GwPlayer[D_80101AAE_ChanceTime[0]].character;
    temp_a1 = D_800C59AC[temp_v0].unk_00;
    temp_a2 = D_800C59AC[temp_v0].unk_04;
    
    if (D_801011F0_ChanceTime == 0) {
        func_800F78C4_ChanceTime(arg0, temp_a1, temp_a2, D_80101AAE_ChanceTime[0], 0.0f, 0, 1400.0f);
    } else {
        func_800F78C4_ChanceTime(arg0, temp_a1, temp_a2, D_80101AAE_ChanceTime[0], -140.0f, 0, 1400.0f);
    }
}

void func_800F78C4_ChanceTime(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z) {
    CTPlayerWork* work;

    func_8000979C(obj, dir, file, player, 0x699, 0x299);
    work = CT_PWORK(obj);
    switch ((u32)dir >> 16) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 6:
        D_800B8964 = 0.9f;
        D_800B8968 = 0.25f;
        break;
    case 5:
        work->unk_34 += 25.0f;
        D_800B8964 = 0.4f;
        D_800B8968 = 0.25f;
        break;
    }
    if (D_801011F0_ChanceTime != 0) {
        work->unk_3C = 30.0f;
    }
    obj->func_ptr = &func_800F7108_ChanceTime;
    func_8001874C(obj, 0, dir, 1, 0);
    func_8001874C(obj, 1, dir | 1, 1, 0);
    func_8001874C(obj, 2, dir | 3, 1, 0);
    func_8001874C(obj, 6, dir | 5, 1, 0x13);
    func_8001874C(obj, 0xE, dir | 0x10, 1, 0x78);
    func_8001874C(obj, 0xD, dir | 0xF, 1, 0x78);
    func_8001874C(obj, 0x11, dir | 0x18, 0, 0);
    func_8001874C(obj, 0x15, dir | 0x62, 0, 0);
    switch ((u32)dir >> 16) {
    case 1:
        func_8001874C(obj, 0x23, dir | 0x39, 1, 0x46);
        func_8001874C(obj, 0x26, dir | 0x3D, 1, 0x46);
        func_8001874C(obj, 0x27, dir | 0x3F, 1, 0x50);
        break;
    case 6:
        func_8001874C(obj, 0x23, dir | 0x39, 1, 0x46);
        func_8001874C(obj, 0x26, dir | 0x3D, 1, 0x3C);
        func_8001874C(obj, 0x27, dir | 0x3F, 1, 0x3C);
        break;
    default:
        func_8001874C(obj, 0x23, dir | 0x39, 1, 0x3C);
        func_8001874C(obj, 0x26, dir | 0x3D, 1, 0x3C);
        func_8001874C(obj, 0x27, dir | 0x3F, 1, 0x3C);
        break;
    }
    func_8001874C(obj, 0x24, dir | 0x3E, 1, 0x3C);
    func_8001874C(obj, 0x25, dir | 0xF, 1, 0x78);
    func_800093FC(obj, x, y, z);
    func_80025798(obj->model[0], x, y, z);
    func_80025798(obj->model[1], x, y, z);
    func_80025798(obj->model[3], x, y, z);
    func_80025798(obj->model[4], x, y, z);
    obj->scale.x = obj->scale.y = obj->scale.z = 0.9f;
    obj->scale.x = obj->scale.y = obj->scale.z = 0.9f;
    func_800090C4(obj, 0, 2);
    func_800090C4(obj, 1, 1);
}
/* Runs the shared player update (func_80005A28) on the CPU's virtual pad: swaps the player's
   controller state for D_80101A9C/AB8/AB2/ACE around the call, saving it in AA6/ACA/A98/AC2. */
void func_800F7C7C_ChanceTime(omObjData* obj) {
    CTPlayerWork* work = CT_PWORK(obj);

    D_80101AA6_ChanceTime[work->unk_56] = ContBtn[work->unk_56];
    D_80101ACA_ChanceTime[work->unk_56] = ContStkX[work->unk_56];
    D_80101A98_ChanceTime[work->unk_56] = ContStkY[work->unk_56];
    D_80101AC2_ChanceTime[work->unk_56] = ContBtnTrg[work->unk_56];
    ContBtn[work->unk_56] = D_80101A9C_ChanceTime[work->unk_56];
    ContStkX[work->unk_56] = D_80101AB8_ChanceTime[work->unk_56];
    ContStkY[work->unk_56] = D_80101AB2_ChanceTime[work->unk_56];
    ContBtnTrg[work->unk_56] = D_80101ACE_ChanceTime[work->unk_56];
    func_80005A28(obj);
    ContBtn[work->unk_56] = D_80101AA6_ChanceTime[work->unk_56];
    ContStkX[work->unk_56] = D_80101ACA_ChanceTime[work->unk_56];
    ContStkY[work->unk_56] = D_80101A98_ChanceTime[work->unk_56];
    ContBtnTrg[work->unk_56] = D_80101AC2_ChanceTime[work->unk_56];
}

void func_800F7E08_ChanceTime(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z) {
    CTPlayerWork* work;

    func_8000979C(obj, dir, file, player, 0x699, 0x299);
    work = CT_PWORK(obj);
    D_80101AA6_ChanceTime[work->unk_56] = 0;
    D_80101ACA_ChanceTime[work->unk_56] = 0;
    D_80101A98_ChanceTime[work->unk_56] = 0;
    D_80101AC2_ChanceTime[work->unk_56] = 0;
    obj->func_ptr = &func_800F7C7C_ChanceTime;
    func_8001874C(obj, 0, dir, 1, 0);
    func_8001874C(obj, 1, dir | 1, 1, 0);
    switch ((u32)dir >> 16) {
    case 1:
        func_8001874C(obj, 0x23, dir | 0x39, 1, 0x46);
        func_8001874C(obj, 0x26, dir | 0x3D, 1, 0x46);
        func_8001874C(obj, 0x27, dir | 0x3F, 1, 0x50);
        break;
    case 6:
        func_8001874C(obj, 0x23, dir | 0x39, 1, 0x46);
        func_8001874C(obj, 0x26, dir | 0x3D, 1, 0x3C);
        func_8001874C(obj, 0x27, dir | 0x3F, 1, 0x3C);
        break;
    default:
        func_8001874C(obj, 0x23, dir | 0x39, 1, 0x3C);
        func_8001874C(obj, 0x26, dir | 0x3D, 1, 0x3C);
        func_8001874C(obj, 0x27, dir | 0x3F, 1, 0x3C);
        break;
    }
    func_8001874C(obj, 0x24, dir | 0x3E, 1, 0x3C);
    func_8001874C(obj, 0x25, dir | 0xF, 1, 0x78);
    func_800093FC(obj, x, y, z);
    func_80025798(obj->model[0], x, y, z);
    func_80025798(obj->model[1], x, y, z);
    func_80025798(obj->model[3], x, y, z);
    func_80025798(obj->model[4], x, y, z);
    obj->scale.x = obj->scale.y = obj->scale.z = 0.9f;
    func_800090C4(obj, 0, 1);
    func_800090C4(obj, 1, 2);
    func_800258EC(obj->model[0], 4, 4);
}
void func_800F80D8_ChanceTime(omObjData* arg0) {
    u8 temp_v1;
    s32 temp2;
    s32 temp3;

    temp_v1 = GwPlayer[D_80101AAF_ChanceTime].character;
    temp2 = D_800C59AC[temp_v1].unk_00;
    temp3 = D_800C59AC[temp_v1].unk_04;
    func_800F7E08_ChanceTime(arg0, temp2, temp3, D_80101AAF_ChanceTime, -800.0f, 10.0f, 800.0f);
}

void func_800F8168_ChanceTime(omObjData* arg0) {
    u8 temp_v1;
    s32 temp2;
    s32 temp3;

    temp_v1 = GwPlayer[D_80101AB0_ChanceTime].character;
    temp2 = D_800C59AC[temp_v1].unk_00;
    temp3 = D_800C59AC[temp_v1].unk_04;
    func_800F7E08_ChanceTime(arg0, temp2, temp3, D_80101AB0_ChanceTime, -700.0f, 10.0f, 800.0f);
}

void func_800F81F8_ChanceTime(omObjData* arg0) {
    u8 temp_v1;
    s32 temp2;
    s32 temp3;

    temp_v1 = GwPlayer[D_80101AB1_ChanceTime].character;
    temp2 = D_800C59AC[temp_v1].unk_00;
    temp3 = D_800C59AC[temp_v1].unk_04;
    func_800F7E08_ChanceTime(arg0, temp2, temp3, D_80101AB1_ChanceTime, -600.0f, 10.0f, 800.0f);
}

void func_800F8288_ChanceTime(void) {
    f32 dx;
    f32 dz;
    f32 angle;

    D_80101700_ChanceTime = CT_PWORK(D_800F3FB0[0]);
    while (1) {
        switch (D_8010126E_ChanceTime) {
        case 0:
            dx = 0.0f - D_800F3FB0[0]->trans.x;
            dz = 1400.0f - D_800F3FB0[0]->trans.z;
            if (dx * dx + dz * dz > 400.0f) {
                angle = func_800B0CD8(dz, dx);
                D_80101AB8_ChanceTime[D_80101700_ChanceTime->unk_56] = (s32)(func_800AEFD0(angle) * 40.0f);
                D_80101AB2_ChanceTime[D_80101700_ChanceTime->unk_56] = (s32)(-func_800AEAC0(angle) * 40.0f);
                D_80101A9C_ChanceTime[D_80101700_ChanceTime->unk_56] = 0;
                D_80101ACE_ChanceTime[D_80101700_ChanceTime->unk_56] = 0;
                break;
            }
            D_80101AB8_ChanceTime[D_80101700_ChanceTime->unk_56] = 0;
            ((s8*)D_80101AB2_ChanceTime)[D_80101700_ChanceTime->unk_56] = -80;
            D_80101A9C_ChanceTime[D_80101700_ChanceTime->unk_56] = 0;
            D_80101ACE_ChanceTime[D_80101700_ChanceTime->unk_56] = 0;
            D_8010126E_ChanceTime++;
            break;
        case 1:
            D_80101700_ChanceTime->unk_3C = 0.0f;
            D_80101700_ChanceTime->unk_40 = 0.0f;
            D_800F3FB0[0]->rot.y = 0.0f;
            D_80101AB8_ChanceTime[D_80101700_ChanceTime->unk_56] = 0;
            D_80101AB2_ChanceTime[D_80101700_ChanceTime->unk_56] = 0;
            D_80101A9C_ChanceTime[D_80101700_ChanceTime->unk_56] = 0;
            D_80101ACE_ChanceTime[D_80101700_ChanceTime->unk_56] = 0;
            D_8010126E_ChanceTime++;
            break;
        }
        HuPrcVSleep();
    }
}
void func_800F84B4_ChanceTime(void) {
    f32 dx;
    f32 dz;
    f32 angle;

    D_80101704_ChanceTime = CT_PWORK(D_800F3FB0[0]);
    while (1) {
        switch (D_8010126F_ChanceTime) {
        case 0:
            dx = -250.0f - D_800F3FB0[0]->trans.x;
            dz = 1700.0f - D_800F3FB0[0]->trans.z;
            if (dx * dx + dz * dz > 400.0f) {
                angle = func_800B0CD8(dz, dx);
                D_80101AB8_ChanceTime[D_80101704_ChanceTime->unk_56] = (s32)(func_800AEFD0(angle) * 60.0f);
                D_80101AB2_ChanceTime[D_80101704_ChanceTime->unk_56] = (s32)(-func_800AEAC0(angle) * 60.0f);
                D_80101A9C_ChanceTime[D_80101704_ChanceTime->unk_56] = 0;
                D_80101ACE_ChanceTime[D_80101704_ChanceTime->unk_56] = 0;
                break;
            }
            D_80101AB8_ChanceTime[D_80101704_ChanceTime->unk_56] = 0;
            ((s8*)D_80101AB2_ChanceTime)[D_80101704_ChanceTime->unk_56] = -80;
            D_80101A9C_ChanceTime[D_80101704_ChanceTime->unk_56] = 0;
            D_80101ACE_ChanceTime[D_80101704_ChanceTime->unk_56] = 0;
            D_8010126F_ChanceTime++;
            break;
        case 1:
            func_800258EC(D_800F3FB0[0]->model[0], 4, 4);
            D_80101704_ChanceTime->unk_3C = 0.0f;
            D_80101704_ChanceTime->unk_40 = 0.0f;
            D_800F3FB0[0]->rot.y = 0.0f;
            D_80101AB8_ChanceTime[D_80101704_ChanceTime->unk_56] = 0;
            D_80101AB2_ChanceTime[D_80101704_ChanceTime->unk_56] = 0;
            D_80101A9C_ChanceTime[D_80101704_ChanceTime->unk_56] = 0;
            D_80101ACE_ChanceTime[D_80101704_ChanceTime->unk_56] = 0;
            D_8010126F_ChanceTime++;
            break;
        }
        HuPrcVSleep();
    }
}
void func_800F8700_ChanceTime(s16 arg0) {
    switch (arg0) {
    case 1:
        D_800F3FB0[1] = omAddObj(0xA, 9, 0x2B, -1, &func_800F80D8_ChanceTime);
        return;
    case 2:
        D_800F3FB0[2] = omAddObj(0xA, 9, 0x2B, -1, &func_800F8168_ChanceTime);
        return;
    case 3:
        D_800F3FB0[3] = omAddObj(0xA, 9, 0x2B, -1, &func_800F81F8_ChanceTime);
        return;
    }
}

void func_800F87CC_ChanceTime(void) {
    f32 dx;
    f32 dz;
    f32 angle;

    D_80101708_ChanceTime = CT_PWORK(D_800F3FB0[0]);
    while (1) {
        switch (D_80101270_ChanceTime) {
        case 0:
            D_80101708_ChanceTime = CT_PWORK(D_800F3FB0[0]);
            dx = D_80101244_ChanceTime.x - D_800F3FB0[0]->trans.x;
            dz = D_80101244_ChanceTime.z - D_800F3FB0[0]->trans.z;
            if (dx * dx + dz * dz > 400.0f) {
                angle = func_800B0CD8(dz, dx);
                D_80101AB8_ChanceTime[D_80101708_ChanceTime->unk_56] = (s32)(func_800AEFD0(angle) * 40.0f);
                D_80101AB2_ChanceTime[D_80101708_ChanceTime->unk_56] = (s32)(-func_800AEAC0(angle) * 40.0f);
                D_80101A9C_ChanceTime[D_80101708_ChanceTime->unk_56] = 0;
                D_80101ACE_ChanceTime[D_80101708_ChanceTime->unk_56] = 0;
                break;
            }
            D_80101AB8_ChanceTime[D_80101708_ChanceTime->unk_56] = 0;
            D_80101AB2_ChanceTime[D_80101708_ChanceTime->unk_56] = 0;
            D_80101A9C_ChanceTime[D_80101708_ChanceTime->unk_56] = 0;
            D_80101ACE_ChanceTime[D_80101708_ChanceTime->unk_56] = 0;
            D_80101708_ChanceTime->unk_40 = 0.0f;
            D_80101708_ChanceTime->unk_3C = 30.0f;
            D_80101270_ChanceTime++;
            break;
        case 1:
            D_80101708_ChanceTime = CT_PWORK(D_800F3FB0[0]);
            D_80101AB8_ChanceTime[D_80101708_ChanceTime->unk_56] = 0;
            D_80101AB2_ChanceTime[D_80101708_ChanceTime->unk_56] = 0;
            D_80101A9C_ChanceTime[D_80101708_ChanceTime->unk_56] = 0;
            D_80101ACE_ChanceTime[D_80101708_ChanceTime->unk_56] = 0;
            D_80101708_ChanceTime->unk_3C = 30.0f;
            D_80101708_ChanceTime->unk_40 = 0.0f;
            if (++D_80101274_ChanceTime >= 11) {
                D_80101270_ChanceTime++;
            }
            break;
        }
        HuPrcVSleep();
    }
}
void func_800F8A6C_ChanceTime(omObjData* obj) {
    CTPlayerWork* work;
    f32 dx;
    f32 dz;
    f32 angle;

    switch (D_801011F2_ChanceTime) {
    case 1:
        switch (D_8010127C_ChanceTime) {
        case 0:
            func_800258EC(obj->model[0], 4, 0);
            func_800258EC(obj->model[1], 4, 0);
            func_80025BB8(obj->model[0], obj->motion[2]);
            func_80025EB4(obj->model[0], 2, 2);
            D_8010170C_ChanceTime = PlaySound(0x55);
            obj->rot.y = 170.0f;
            D_8010127C_ChanceTime++;
            break;
        case 1:
            if (D_80101278_ChanceTime < 16) {
                D_80101278_ChanceTime++;
                obj->trans.x += (D_80101220_ChanceTime.x - CT_PREV(D_80101220_ChanceTime, D_80101214_ChanceTime).x) / 16.0f;
                obj->trans.y += (D_80101220_ChanceTime.y - CT_PREV(D_80101220_ChanceTime, D_80101214_ChanceTime).y) / 16.0f;
                obj->trans.z += (D_80101220_ChanceTime.z - CT_PREV(D_80101220_ChanceTime, D_80101214_ChanceTime).z) / 16.0f;
            } else {
                D_8010127C_ChanceTime++;
            }
            break;
        case 2:
            if (obj->rot.y > 14.0f) {
                obj->rot.y -= 6.0f;
            } else {
                obj->rot.y = 14.0f;
                D_8010127C_ChanceTime++;
            }
            break;
        case 3:
            func_8006071C(D_8010170C_ChanceTime);
            func_80025BB8(obj->model[0], obj->motion[0]);
            func_80025EB4(obj->model[0], 2, 2);
            obj->rot.y = 14.0f;
            D_8010127C_ChanceTime++;
            break;
        case 4:
            omAddPrcObj(func_800FF2B8_ChanceTime, 0x3F00, 0x800, 0);
            D_8010127C_ChanceTime++;
            break;
        case 5:
            if (D_80101320_ChanceTime == 1) {
                D_8010170C_ChanceTime = PlaySound(0x55);
                D_8010127C_ChanceTime++;
                D_80101278_ChanceTime = 0;
            }
            break;
        case 6:
            if (obj->rot.y < 350.0f) {
                obj->rot.y -= 6.0f;
                if (obj->rot.y < 0.0f) {
                    obj->rot.y += 360.0f;
                }
            } else {
                obj->rot.y = 350.0f;
                D_8010127C_ChanceTime++;
            }
            break;
        case 7:
            D_801011F3_ChanceTime = 1;
            func_80025BB8(obj->model[0], obj->motion[2]);
            func_80025EB4(obj->model[0], 2, 2);
            obj->rot.y = 350.0f;
            D_8010127C_ChanceTime++;
            break;
        case 8:
            if (D_80101278_ChanceTime < 16) {
                D_80101278_ChanceTime++;
                obj->trans.x -= (D_80101220_ChanceTime.x - CT_PREV(D_80101220_ChanceTime, D_80101214_ChanceTime).x) / 16.0f;
                obj->trans.y -= (D_80101220_ChanceTime.y - CT_PREV(D_80101220_ChanceTime, D_80101214_ChanceTime).y) / 16.0f;
                obj->trans.z -= (D_80101220_ChanceTime.z - CT_PREV(D_80101220_ChanceTime, D_80101214_ChanceTime).z) / 16.0f;
            } else {
                func_8006071C(D_8010170C_ChanceTime);
                func_800258EC(obj->model[0], 4, 4);
                func_800258EC(obj->model[1], 4, 4);
                D_8010127C_ChanceTime++;
            }
            break;
        case 9:
            D_801011F2_ChanceTime = 0;
            D_80101278_ChanceTime = 0;
            D_8010127C_ChanceTime = 0;
            break;
        }
        break;
    case 2:
        switch (D_8010127C_ChanceTime) {
        case 0:
            D_8010170C_ChanceTime = PlaySound(0x55);
            func_800258EC(obj->model[0], 4, 0);
            func_800258EC(obj->model[1], 4, 0);
            func_80025BB8(obj->model[0], obj->motion[2]);
            func_80025EB4(obj->model[0], 2, 2);
            obj->rot.y = 170.0f;
            omAddPrcObj(func_800F8288_ChanceTime, 0x3F00, 0x800, 0);
            D_80101278_ChanceTime = 0;
            D_8010127C_ChanceTime++;
            break;
        case 1:
            if (D_80101278_ChanceTime < 16) {
                D_80101278_ChanceTime++;
                obj->trans.x += (D_80101220_ChanceTime.x - CT_PREV(D_80101220_ChanceTime, D_80101214_ChanceTime).x) / 16.0f;
                obj->trans.y += (D_80101220_ChanceTime.y - CT_PREV(D_80101220_ChanceTime, D_80101214_ChanceTime).y) / 16.0f;
                obj->trans.z += (D_80101220_ChanceTime.z - CT_PREV(D_80101220_ChanceTime, D_80101214_ChanceTime).z) / 16.0f;
            } else {
                D_8010127C_ChanceTime++;
            }
            break;
        case 2:
            if (obj->rot.y > 14.0f) {
                obj->rot.y -= 6.0f;
            } else {
                obj->rot.y = 14.0f;
                D_8010127C_ChanceTime++;
            }
            break;
        case 3:
            func_8006071C(D_8010170C_ChanceTime);
            func_80025BB8(obj->model[0], obj->motion[0]);
            func_80025EB4(obj->model[0], 2, 2);
            obj->rot.y = 14.0f;
            D_8010127C_ChanceTime++;
            break;
        case 4:
            omAddPrcObj(func_800FED28_ChanceTime, 0x3F00, 0x800, 0);
            D_8010127C_ChanceTime++;
            break;
        case 5:
            if (D_80101320_ChanceTime == 1) {
                D_8010127C_ChanceTime++;
                D_80101278_ChanceTime = 0;
                if (D_801012E2_ChanceTime == 9) {
                    D_801011F2_ChanceTime = 0;
                    D_8010127C_ChanceTime = 0;
                    func_80009438();
                } else {
                    D_8010170C_ChanceTime = PlaySound(0x55);
                }
            }
            break;
        case 6:
            if (D_801012E0_ChanceTime != D_80101AAE_ChanceTime[0] && D_801012E1_ChanceTime != D_80101AAE_ChanceTime[0]) {
                omAddPrcObj(func_800F84B4_ChanceTime, 0x3F00, 0x800, 0);
            }
            D_8010127C_ChanceTime++;
            break;
        case 7:
            if (obj->rot.y < 350.0f) {
                obj->rot.y -= 6.0f;
                if (obj->rot.y < 0.0f) {
                    obj->rot.y += 360.0f;
                }
            } else {
                obj->rot.y = 350.0f;
                D_8010127C_ChanceTime++;
            }
            break;
        case 8:
            func_80025BB8(obj->model[0], obj->motion[2]);
            func_80025EB4(obj->model[0], 2, 2);
            obj->rot.y = 350.0f;
            D_80101278_ChanceTime = 0;
            D_8010127C_ChanceTime++;
            break;
        case 9:
            if (D_80101278_ChanceTime < 16) {
                D_80101278_ChanceTime++;
                obj->trans.x -= (D_80101220_ChanceTime.x - CT_PREV(D_80101220_ChanceTime, D_80101214_ChanceTime).x) / 16.0f;
                obj->trans.y -= (D_80101220_ChanceTime.y - CT_PREV(D_80101220_ChanceTime, D_80101214_ChanceTime).y) / 16.0f;
                obj->trans.z -= (D_80101220_ChanceTime.z - CT_PREV(D_80101220_ChanceTime, D_80101214_ChanceTime).z) / 16.0f;
            } else {
                func_8006071C(D_8010170C_ChanceTime);
                func_800258EC(obj->model[0], 4, 4);
                func_800258EC(obj->model[1], 4, 4);
                if (D_801012E0_ChanceTime != D_80101AAE_ChanceTime[0] && D_801012E1_ChanceTime != D_80101AAE_ChanceTime[0]) {
                    D_80101278_ChanceTime = 0;
                } else {
                    D_80101278_ChanceTime = 30;
                }
                D_8010127C_ChanceTime++;
            }
            break;
        case 10:
            if (++D_80101278_ChanceTime >= 31) {
                if (D_80101AA4_ChanceTime[0] != 0) {
                    func_800F8700_ChanceTime(D_80101AA4_ChanceTime[0]);
                }
                D_8010127C_ChanceTime++;
            }
            break;
        case 11:
            if (++D_80101278_ChanceTime >= 9) {
                D_8010127C_ChanceTime++;
            }
            break;
        case 12:
            if (D_80101AA4_ChanceTime[1] != 0) {
                func_800F8700_ChanceTime(D_80101AA4_ChanceTime[1]);
            }
            D_80101278_ChanceTime = 0;
            D_8010127C_ChanceTime++;
            break;
        case 13:
            if (++D_80101278_ChanceTime >= 9) {
                func_80055B50(D_801012E0_ChanceTime, D_801012E1_ChanceTime);
                func_800559F8();
                if (D_80101AA4_ChanceTime[0] != 0) {
                    D_800F3FB0[D_80101AA4_ChanceTime[0]]->trans.x = D_8010122C_ChanceTime.x;
                    D_800F3FB0[D_80101AA4_ChanceTime[0]]->trans.y = D_8010122C_ChanceTime.y;
                    D_800F3FB0[D_80101AA4_ChanceTime[0]]->trans.z = D_8010122C_ChanceTime.z;
                    func_800090C4(D_800F3FB0[D_80101AA4_ChanceTime[0]], 0, 2);
                    func_800090C4(D_800F3FB0[D_80101AA4_ChanceTime[0]], 1, 1);
                    func_800258EC(D_800F3FB0[D_80101AA4_ChanceTime[0]]->model[0], 4, 0);
                }
                if (D_80101AA4_ChanceTime[1] != 0) {
                    D_800F3FB0[D_80101AA4_ChanceTime[1]]->trans.x = -D_8010122C_ChanceTime.x;
                    D_800F3FB0[D_80101AA4_ChanceTime[1]]->trans.y = D_8010122C_ChanceTime.y;
                    D_800F3FB0[D_80101AA4_ChanceTime[1]]->trans.z = D_8010122C_ChanceTime.z;
                    func_800090C4(D_800F3FB0[D_80101AA4_ChanceTime[1]], 0, 2);
                    func_800090C4(D_800F3FB0[D_80101AA4_ChanceTime[1]], 1, 1);
                    func_800258EC(D_800F3FB0[D_80101AA4_ChanceTime[1]]->model[0], 4, 0);
                }
                D_8010127C_ChanceTime++;
            }
            break;
        case 14:
            work = CT_PWORK(D_800F3FB0[D_80101AA4_ChanceTime[0]]);
            dx = D_80101238_ChanceTime.x - D_800F3FB0[D_80101AA4_ChanceTime[0]]->trans.x;
            dz = D_80101238_ChanceTime.z - D_800F3FB0[D_80101AA4_ChanceTime[0]]->trans.z;
            if (dx * dx + dz * dz > 400.0f) {
                angle = func_800B0CD8(dz, dx);
                D_80101AB8_ChanceTime[work->unk_56] = (s32)(func_800AEFD0(angle) * 40.0f);
                D_80101AB2_ChanceTime[work->unk_56] = (s32)(-func_800AEAC0(angle) * 40.0f);
                D_80101A9C_ChanceTime[work->unk_56] = 0;
                D_80101ACE_ChanceTime[work->unk_56] = 0;
            } else {
                D_80101AB8_ChanceTime[work->unk_56] = 0;
                D_80101AB2_ChanceTime[work->unk_56] = 0;
                D_80101A9C_ChanceTime[work->unk_56] = 0;
                D_80101ACE_ChanceTime[work->unk_56] = 0;
                work->unk_40 = 0.0f;
                work->unk_3C = 30.0f;
                if (D_80101280_ChanceTime == 0) {
                    func_80055B64();
                    D_80101280_ChanceTime = 1;
                }
            }
            work = CT_PWORK(D_800F3FB0[D_80101AA4_ChanceTime[1]]);
            dx = -D_80101238_ChanceTime.x - D_800F3FB0[D_80101AA4_ChanceTime[1]]->trans.x;
            dz = D_80101238_ChanceTime.z - D_800F3FB0[D_80101AA4_ChanceTime[1]]->trans.z;
            if (dx * dx + dz * dz > 400.0f) {
                angle = func_800B0CD8(dz, dx);
                D_80101AB8_ChanceTime[work->unk_56] = (s32)(func_800AEFD0(angle) * 40.0f);
                D_80101AB2_ChanceTime[work->unk_56] = (s32)(-func_800AEAC0(angle) * 40.0f);
                D_80101A9C_ChanceTime[work->unk_56] = 0;
                D_80101ACE_ChanceTime[work->unk_56] = 0;
            } else {
                D_80101AB8_ChanceTime[work->unk_56] = 0;
                D_80101AB2_ChanceTime[work->unk_56] = 0;
                D_80101A9C_ChanceTime[work->unk_56] = 0;
                D_80101ACE_ChanceTime[work->unk_56] = 0;
                work->unk_40 = 0.0f;
                work->unk_3C = 330.0f;
                if (D_80101281_ChanceTime == 0) {
                    func_80055B80();
                    D_80101281_ChanceTime = 1;
                }
            }
            if (D_80101280_ChanceTime == 1 && D_80101281_ChanceTime == D_80101280_ChanceTime) {
                D_80101278_ChanceTime = 0;
                D_8010127C_ChanceTime++;
            }
            break;
        case 15:
            work = CT_PWORK(D_800F3FB0[D_80101AA4_ChanceTime[0]]);
            D_80101AB8_ChanceTime[work->unk_56] = 0;
            D_80101AB2_ChanceTime[work->unk_56] = 0;
            D_80101A9C_ChanceTime[work->unk_56] = 0;
            D_80101ACE_ChanceTime[work->unk_56] = 0;
            work->unk_3C = 30.0f;
            work->unk_40 = 0.0f;
            work = CT_PWORK(D_800F3FB0[D_80101AA4_ChanceTime[1]]);
            D_80101AB8_ChanceTime[work->unk_56] = 0;
            D_80101AB2_ChanceTime[work->unk_56] = 0;
            D_80101A9C_ChanceTime[work->unk_56] = 0;
            D_80101ACE_ChanceTime[work->unk_56] = 0;
            work->unk_3C = 330.0f;
            work->unk_40 = 0.0f;
            if (D_80101278_ChanceTime++ >= 21) {
                D_80101278_ChanceTime = 0;
                D_8010127C_ChanceTime++;
            }
            break;
        case 16:
            D_801011F4_ChanceTime = 1;
            D_8010127C_ChanceTime++;
            break;
        case 17:
            if (D_801011F5_ChanceTime == 1) {
                D_8010127C_ChanceTime++;
            }
            break;
        case 18:
            D_801011F2_ChanceTime = 0;
            D_80101278_ChanceTime = 0;
            D_8010127C_ChanceTime = 0;
            func_80009438();
            break;
        }
        break;
    }
    func_80025798(obj->model[1], obj->trans.x, 0.0f, obj->trans.z);
}
void func_800F988C_ChanceTime(omObjData* arg0) {
    func_800264F8(arg0->mdlcnt, arg0->mtncnt, (sinf(arg0->trans.x * (M_PI/180)) / 2.0f) + 0.5f, "030-hata1", "hata2", 0);
    arg0->trans.x += 20.0f;
    if (arg0->trans.x >= 360.0f) {
        arg0->trans.x -= 360.0f;
    }
}

void func_800F9948_ChanceTime(s32 arg0) {
    D_80101288_ChanceTime = LoadFormFile(0xA0076, 0x2AD);
    func_80026040(arg0);
    D_80101284_ChanceTime = omAddObj(0x1000, 0, 0, -1, &func_800F988C_ChanceTime);
    D_80101284_ChanceTime->trans.x = 0.0f;
    D_80101284_ChanceTime->mdlcnt = arg0;
    D_80101284_ChanceTime->mtncnt = (u16)D_80101288_ChanceTime;
    omSetStatBit(D_80101284_ChanceTime, 0xA0);
}

void func_800F99D8_ChanceTime(omObjData* arg0) {
    f32 temp_f20 = D_80101214_ChanceTime.x;
    f32 temp_f24 = D_80101214_ChanceTime.y;
    f32 temp_f22 = D_80101214_ChanceTime.z;
    

    arg0->model[0] = LoadFormFile(0xA0072, 0x689);
    arg0->model[1] = func_800174F4(0x20, 0x299);
    func_80025830(arg0->model[1], 1.3f, 1.0f, 1.3f);
    func_8001775C(arg0, 0, 0xA0072);
    func_8001775C(arg0, 1, 0xA0073);
    func_8001775C(arg0, 2, 0xA0074);
    func_80025EB4(arg0->model[0], 2, 2);
    func_800258EC(arg0->model[0], 4, 4);
    func_800258EC(arg0->model[1], 4, 4);
    arg0->trans.x = temp_f20;
    arg0->trans.y = temp_f24;
    arg0->trans.z = temp_f22;
    arg0->rot.y = 0.0f;
    func_80025798(arg0->model[1], temp_f20, arg0->rot.y, temp_f22);
    arg0->scale.x = arg0->scale.y = arg0->scale.z = 0.9f;
    func_800F9948_ChanceTime(arg0->model[0]);
    func_80025B34(arg0->model[0]);
    arg0->func_ptr = &func_800F8A6C_ChanceTime;
}

void func_800F9B50_ChanceTime(void) {
    s16 var_s0;
    s32 tmp;

    var_s0 = CreateTextWindow(0x46, 0x3C, 0x10, 4);

    ShowTextWindow(var_s0);
    if (D_8010175C_ChanceTime == 0) {
        func_8006DA5C(var_s0, D_80101330_ChanceTime[GwPlayer[D_801012E0_ChanceTime].character], 0);
        func_8006DA5C(var_s0, D_80101330_ChanceTime[GwPlayer[D_801012E1_ChanceTime].character], 1);
    } else {
        func_8006DA5C(var_s0, D_80101330_ChanceTime[GwPlayer[D_801012E1_ChanceTime].character], 0);
        func_8006DA5C(var_s0, D_80101330_ChanceTime[GwPlayer[D_801012E0_ChanceTime].character], 1);
    }

    if (D_801011F6_ChanceTime == 0) {
        func_8006DA5C(var_s0, "Coins", 2);
    } else {
        func_8006DA5C(var_s0, "Stars", 2);
    }

    tmp = D_801012E2_ChanceTime;

    switch(tmp)
    {
        case 4:
            LoadStringIntoWindow(var_s0, (void*)0xF0, -1, -1);
            break;
        case 0:
        case 1:
            LoadStringIntoWindow(var_s0, (void*)0xEE, -1, -1);
            break;
        case 10:
            LoadStringIntoWindow(var_s0, (void*)0xF4, -1, -1);
            break;
        default:
            LoadStringIntoWindow(var_s0, (void*)0xED, -1, -1);
            break;
    }
    
    
    func_8006E070(var_s0, 0);
    WaitForTextConfirmation(var_s0);
    HideTextWindow(var_s0);
    D_801011F5_ChanceTime = 1;

    while (1) {
        HuPrcVSleep();
    }
}

s16 func_800F9D60_ChanceTime(s8 side) {
    s16 i;

    for (i = 0; i < 20; i++) {
        if (D_80101868_ChanceTime[i].unk_18 == 0 && D_80101868_ChanceTime[i].unk_19 == 1) {
            D_80101868_ChanceTime[i].unk_04 = D_800F3FB0[D_80101AA4_ChanceTime[side]]->trans.x;
            D_80101868_ChanceTime[i].unk_08 = 180.0f;
            D_80101868_ChanceTime[i].unk_0C = D_800F3FB0[D_80101AA4_ChanceTime[side]]->trans.z;
            D_80101868_ChanceTime[i].unk_10 = 0.0f;
            D_80101868_ChanceTime[i].unk_14 = 0.0f;
            D_80101868_ChanceTime[i].unk_18 = 1;
            D_80101868_ChanceTime[i].unk_19 = 0;
            return i;
        }
    }
    return -1;
}

void func_800F9E74_ChanceTime(omObjData* obj) {
    s16 i;

    for (i = 0; i < 20; i++) {
        D_80101868_ChanceTime[i].unk_00 = obj->model[i + 1];
        D_80101868_ChanceTime[i].unk_04 = -500.0f;
        D_80101868_ChanceTime[i].unk_08 = 0.0f;
        D_80101868_ChanceTime[i].unk_0C = 0.0f;
        D_80101868_ChanceTime[i].unk_10 = 0.0f;
        D_80101868_ChanceTime[i].unk_14 = 0.0f;
        D_80101868_ChanceTime[i].unk_18 = 0;
        D_80101868_ChanceTime[i].unk_19 = 1;
    }
}

s32 func_800F9F30_ChanceTime(omObjData* obj, s8 dir, s16 count) {
    s16 i;
    u8 player;
    s32 ret;

    ret = 0;
    if (D_8010128C_ChanceTime == 0) {
        func_800F9E74_ChanceTime(obj);
        D_80101742_ChanceTime = count;
        D_80101744_ChanceTime = 0;
        D_80101746_ChanceTime = 0;
        D_80101748_ChanceTime = 0.0f;
        D_80101740_ChanceTime = dir;
        D_80101741_ChanceTime = 0;
        if (dir == 0) {
            player = D_801012E0_ChanceTime;
        } else {
            player = D_801012E1_ChanceTime;
        }
        if (D_80101742_ChanceTime >= 30) {
            func_80060F04(player, 2, 2, 20);
        } else if (D_80101742_ChanceTime >= 20) {
            func_80060F04(player, 20, 0, 20);
        } else {
            func_80060F04(player, 10, 0, 10);
        }
        D_8010128C_ChanceTime = 1;
        return ret;
    }
    if (D_80101741_ChanceTime == 0 && D_80101744_ChanceTime < (s32)D_80101748_ChanceTime) {
        func_800F9D60_ChanceTime(D_80101740_ChanceTime);
        if (++D_80101744_ChanceTime >= D_80101742_ChanceTime) {
            D_80101741_ChanceTime = 1;
        }
    }
    for (i = 0; i < 20; i++) {
        if (D_80101868_ChanceTime[i].unk_19 != 0 || D_80101868_ChanceTime[i].unk_18 != 1) {
            continue;
        }
        func_800258EC(D_80101868_ChanceTime[i].unk_00, 4, 0);
        if (D_80101740_ChanceTime == 0) {
            D_80101868_ChanceTime[i].unk_04 += 13.0f;
            if (D_800F3FB0[D_80101AA5_ChanceTime]->trans.x < D_80101868_ChanceTime[i].unk_04) {
                D_80101868_ChanceTime[i].unk_19 = 1;
                D_80101868_ChanceTime[i].unk_18 = 0;
                func_80055810(D_801012E0_ChanceTime, -1, 0);
                func_80055960(D_801012E1_ChanceTime, 1);
                func_800258EC(D_80101868_ChanceTime[i].unk_00, 4, 4);
                D_80101746_ChanceTime++;
            }
        } else {
            D_80101868_ChanceTime[i].unk_04 -= 13.0f;
            if (D_80101868_ChanceTime[i].unk_04 < D_800F3FB0[D_80101AA4_ChanceTime[0]]->trans.x) {
                D_80101868_ChanceTime[i].unk_19 = 1;
                D_80101868_ChanceTime[i].unk_18 = 0;
                func_80055960(D_801012E0_ChanceTime, 1);
                func_80055810(D_801012E1_ChanceTime, -1, 0);
                func_800258EC(D_80101868_ChanceTime[i].unk_00, 4, 4);
                D_80101746_ChanceTime++;
            }
        }
        D_80101868_ChanceTime[i].unk_10 = func_800AEAC0(D_80101868_ChanceTime[i].unk_14) * 100.0f * 0.9;
        D_80101868_ChanceTime[i].unk_14 += 13.0;
        func_800257E4(D_80101868_ChanceTime[i].unk_00, 0.0f, D_80101290_ChanceTime, 0.0f);
        func_80025798(D_80101868_ChanceTime[i].unk_00, D_80101868_ChanceTime[i].unk_04,
                      D_80101868_ChanceTime[i].unk_08 + D_80101868_ChanceTime[i].unk_10, D_80101868_ChanceTime[i].unk_0C);
    }
    D_80101290_ChanceTime += 50.0f;
    if (D_80101290_ChanceTime >= 360.0f) {
        D_80101290_ChanceTime -= 360.0f;
    }
    D_80101748_ChanceTime += 0.2;
    if ((s32)D_80101748_ChanceTime >= D_80101742_ChanceTime) {
        D_80101748_ChanceTime = D_80101742_ChanceTime;
    }
    if (D_80101746_ChanceTime >= D_80101742_ChanceTime) {
        ret = 1;
    }
    return ret;
}
s32 func_800FA458_ChanceTime(omObjData* obj, s16 a, s16 b) {
    s16 i;
    s16 n;
    s16 d;
    s32 ret;

    ret = 0;
    if (D_80101294_ChanceTime == 0) {
        if (a >= 11) {
            D_8010174C_ChanceTime[0] = 10;
        } else {
            D_8010174C_ChanceTime[0] = a;
        }
        if (b >= 11) {
            D_8010174C_ChanceTime[1] = 10;
        } else {
            D_8010174C_ChanceTime[1] = b;
        }
        D_80101750_ChanceTime[0] = D_80101750_ChanceTime[1] = 0.0f;
        for (i = 0; i < D_8010174C_ChanceTime[0]; i++) {
            D_80101868_ChanceTime[i].unk_00 = obj->model[i + 1];
            D_80101868_ChanceTime[i].unk_04 = D_800F3FB0[D_80101AA4_ChanceTime[0]]->trans.x;
            D_80101868_ChanceTime[i].unk_08 = 180.0f;
            D_80101868_ChanceTime[i].unk_0C = D_800F3FB0[D_80101AA4_ChanceTime[0]]->trans.z;
            D_80101868_ChanceTime[i].unk_10 = 0.0f;
            D_80101868_ChanceTime[i].unk_14 = 0.0f;
            D_80101868_ChanceTime[i].unk_18 = 1;
            D_80101868_ChanceTime[i].unk_19 = 0;
        }
        for (i = D_8010174C_ChanceTime[0]; i < D_8010174C_ChanceTime[0] + D_8010174C_ChanceTime[1]; i++) {
            D_80101868_ChanceTime[i].unk_00 = obj->model[i + 1];
            D_80101868_ChanceTime[i].unk_04 = D_800F3FB0[D_80101AA4_ChanceTime[1]]->trans.x;
            D_80101868_ChanceTime[i].unk_08 = 180.0f;
            D_80101868_ChanceTime[i].unk_0C = D_800F3FB0[D_80101AA4_ChanceTime[1]]->trans.z;
            D_80101868_ChanceTime[i].unk_10 = 0.0f;
            D_80101868_ChanceTime[i].unk_14 = 0.0f;
            D_80101868_ChanceTime[i].unk_18 = 1;
            D_80101868_ChanceTime[i].unk_19 = 0;
        }
        D_80101758_ChanceTime[0] = GwPlayer[D_801012E0_ChanceTime].coins;
        D_80101758_ChanceTime[1] = GwPlayer[D_801012E1_ChanceTime].coins;
        if (D_80101758_ChanceTime[0] != D_80101758_ChanceTime[1]) {
            func_80060F04(D_80101758_ChanceTime[1] < D_80101758_ChanceTime[0] ? D_801012E0_ChanceTime : D_801012E1_ChanceTime, 2, 2, 20);
        }
        GwPlayer[D_801012E0_ChanceTime].coins = 0;
        GwPlayer[D_801012E1_ChanceTime].coins = 0;
        D_80101294_ChanceTime = 1;
        return ret;
    }
    n = 0;
    for (i = 0; i < (s32)D_80101750_ChanceTime[0]; i++) {
        if (D_80101868_ChanceTime[i].unk_19 == 0) {
            if (D_80101868_ChanceTime[i].unk_18 == 1) {
                func_800258EC(D_80101868_ChanceTime[i].unk_00, 4, 0);
                D_80101868_ChanceTime[i].unk_04 += 10.0f;
                if (D_800F3FB0[D_80101AA5_ChanceTime]->trans.x < D_80101868_ChanceTime[i].unk_04) {
                    if (D_80101298_ChanceTime[0] == 0) {
                        d = D_80101758_ChanceTime[0] - D_80101758_ChanceTime[1];
                        if (d >= 0) {
                            func_80055960(D_801012E1_ChanceTime, D_80101758_ChanceTime[0]);
                        } else {
                            func_80055810(D_801012E1_ChanceTime, D_80101758_ChanceTime[0], 0);
                        }
                        D_80101298_ChanceTime[0] = 1;
                    }
                    D_80101868_ChanceTime[i].unk_19 = 1;
                    func_800258EC(D_80101868_ChanceTime[i].unk_00, 4, 4);
                }
                D_80101868_ChanceTime[i].unk_10 = func_800AEAC0(D_80101868_ChanceTime[i].unk_14) * 90.0;
                D_80101868_ChanceTime[i].unk_14 += 10.0;
                func_800257E4(D_80101868_ChanceTime[i].unk_00, 0.0f, D_8010129C_ChanceTime, 0.0f);
                func_80025798(D_80101868_ChanceTime[i].unk_00, D_80101868_ChanceTime[i].unk_04,
                              D_80101868_ChanceTime[i].unk_08 + D_80101868_ChanceTime[i].unk_10, D_80101868_ChanceTime[i].unk_0C);
            }
        } else {
            n++;
        }
    }
    for (i = D_8010174C_ChanceTime[0]; i < (s32)D_80101754_ChanceTime + D_8010174C_ChanceTime[0]; i++) {
        if (D_80101868_ChanceTime[i].unk_19 == 0) {
            if (D_80101868_ChanceTime[i].unk_18 == 1) {
                func_800258EC(D_80101868_ChanceTime[i].unk_00, 4, 0);
                D_80101868_ChanceTime[i].unk_04 -= 10.0f;
                if (D_80101868_ChanceTime[i].unk_04 < D_800F3FB0[D_80101AA4_ChanceTime[0]]->trans.x) {
                    if (D_80101299_ChanceTime == 0) {
                        d = D_80101758_ChanceTime[1] - D_80101758_ChanceTime[0];
                        if (d > 0) {
                            func_80055960(D_801012E0_ChanceTime, D_80101758_ChanceTime[1]);
                        } else {
                            func_80055810(D_801012E0_ChanceTime, D_80101758_ChanceTime[1], 0);
                        }
                        D_80101299_ChanceTime = 1;
                    }
                    D_80101868_ChanceTime[i].unk_19 = 1;
                    func_800258EC(D_80101868_ChanceTime[i].unk_00, 4, 4);
                }
                D_80101868_ChanceTime[i].unk_10 = func_800AEAC0(D_80101868_ChanceTime[i].unk_14) * 45.0;
                D_80101868_ChanceTime[i].unk_14 += 10.0;
                func_800257E4(D_80101868_ChanceTime[i].unk_00, 0.0f, D_8010129C_ChanceTime, 0.0f);
                func_80025798(D_80101868_ChanceTime[i].unk_00, D_80101868_ChanceTime[i].unk_04,
                              D_80101868_ChanceTime[i].unk_08 + D_80101868_ChanceTime[i].unk_10, D_80101868_ChanceTime[i].unk_0C);
            }
        } else {
            n++;
        }
    }
    D_8010129C_ChanceTime += 50.0f;
    if (D_8010129C_ChanceTime >= 360.0f) {
        D_8010129C_ChanceTime -= 360.0f;
    }
    D_80101750_ChanceTime[0] += 0.8 / (11 - D_8010174C_ChanceTime[0]);
    if ((s32)D_80101750_ChanceTime[0] >= D_8010174C_ChanceTime[0]) {
        D_80101750_ChanceTime[0] = D_8010174C_ChanceTime[0];
    }
    D_80101750_ChanceTime[1] += 0.8 / (11 - D_8010174C_ChanceTime[1]);
    if ((s32)D_80101750_ChanceTime[1] >= D_8010174C_ChanceTime[1]) {
        D_80101750_ChanceTime[1] = D_8010174C_ChanceTime[1];
    }
    if (n >= D_8010174C_ChanceTime[0] + D_8010174C_ChanceTime[1]) {
        ret = 1;
    }
    return ret;
}
s8 func_800FAE60_ChanceTime(omObjData* obj) {
    s16 coins[2];
    s16 stars[2];
    s8 ret;

    coins[0] = coins[1] = 0;
    stars[0] = stars[1] = 0;
    ret = 1;
    switch (D_801012E2_ChanceTime) {
    case 0:
        ret = func_800FFF4C_ChanceTime(D_801012E1_ChanceTime, D_801012E0_ChanceTime);
        break;
    case 1:
        ret = func_800FFF4C_ChanceTime(D_801012E0_ChanceTime, D_801012E1_ChanceTime);
        break;
    case 4:
        coins[0] = GwPlayer[D_801012E0_ChanceTime].coins;
        coins[1] = GwPlayer[D_801012E1_ChanceTime].coins;
        ret = func_800FA458_ChanceTime(obj, coins[0], coins[1]);
        break;
    case 2:
    case 5:
    case 7:
        ret = func_800F9F30_ChanceTime(obj, 0, D_80101326_ChanceTime);
        break;
    case 3:
    case 6:
    case 8:
        ret = func_800F9F30_ChanceTime(obj, 1, D_80101324_ChanceTime[0]);
        break;
    case 10:
        stars[0] = GwPlayer[D_801012E0_ChanceTime].stars;
        stars[1] = GwPlayer[D_801012E1_ChanceTime].stars;
        if (stars[0] >= 11) {
            stars[0] = 10;
        }
        if (stars[1] >= 11) {
            stars[1] = 10;
        }
        ret = func_80101180_ChanceTime(stars[0], stars[1]);
        break;
    }
    return ret;
}
void func_800FB00C_ChanceTime(omObjData* obj) {
    CTPlayerWork* work[2];
    f32 t;

    if (D_801011F4_ChanceTime != 1) {
        return;
    }
    work[0] = CT_PWORK(D_800F3FB0[D_80101AA4_ChanceTime[0]]);
    work[1] = CT_PWORK(D_800F3FB0[D_80101AA4_ChanceTime[1]]);
    switch (D_801012A0_ChanceTime) {
    case 0:
        switch (D_801012E2_ChanceTime) {
        case 0:
            if (GwPlayer[D_801012E0_ChanceTime].stars == 0) {
                D_800F3FB0[D_80101AA4_ChanceTime[0]]->rot.y = 0.0f;
                D_800F3FB0[D_80101AA4_ChanceTime[1]]->rot.y = 0.0f;
                work[0]->unk_3C = 0.0f;
                work[1]->unk_3C = 0.0f;
                D_801011F4_ChanceTime = 0;
                D_801011F6_ChanceTime = 1;
                D_8010175C_ChanceTime = 0;
                func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[0]], 0x27);
                func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[1]], 0x27);
                omAddPrcObj(func_800F9B50_ChanceTime, 0x3F00, 0x800, 0);
            }
            break;
        case 1:
            if (GwPlayer[D_801012E1_ChanceTime].stars == 0) {
                D_800F3FB0[D_80101AA4_ChanceTime[0]]->rot.y = 0.0f;
                D_800F3FB0[D_80101AA4_ChanceTime[1]]->rot.y = 0.0f;
                work[0]->unk_3C = 0.0f;
                work[1]->unk_3C = 0.0f;
                D_801011F4_ChanceTime = 0;
                D_801011F6_ChanceTime = 1;
                D_8010175C_ChanceTime = 1;
                func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[0]], 0x27);
                func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[1]], 0x27);
                omAddPrcObj(func_800F9B50_ChanceTime, 0x3F00, 0x800, 0);
            }
            break;
        case 4:
            if (GwPlayer[D_801012E0_ChanceTime].coins == 0 && GwPlayer[D_801012E1_ChanceTime].coins == 0) {
                D_800F3FB0[D_80101AA4_ChanceTime[0]]->rot.y = 0.0f;
                D_800F3FB0[D_80101AA4_ChanceTime[1]]->rot.y = 0.0f;
                work[0]->unk_3C = 0.0f;
                work[1]->unk_3C = 0.0f;
                D_801011F4_ChanceTime = 0;
                D_801011F6_ChanceTime = 0;
                D_8010175C_ChanceTime = 0;
                func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[0]], 0x27);
                func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[1]], 0x27);
                omAddPrcObj(func_800F9B50_ChanceTime, 0x3F00, 0x800, 0);
            }
            break;
        case 2:
        case 5:
        case 7:
            if (GwPlayer[D_801012E0_ChanceTime].coins == 0) {
                D_800F3FB0[D_80101AA4_ChanceTime[0]]->rot.y = 0.0f;
                D_800F3FB0[D_80101AA4_ChanceTime[1]]->rot.y = 0.0f;
                work[0]->unk_3C = 0.0f;
                work[1]->unk_3C = 0.0f;
                D_801011F4_ChanceTime = 0;
                D_801011F6_ChanceTime = 0;
                D_8010175C_ChanceTime = 0;
                func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[0]], 0x27);
                func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[1]], 0x27);
                omAddPrcObj(func_800F9B50_ChanceTime, 0x3F00, 0x800, 0);
            }
            break;
        case 3:
        case 6:
        case 8:
            if (GwPlayer[D_801012E1_ChanceTime].coins == 0) {
                D_800F3FB0[D_80101AA4_ChanceTime[0]]->rot.y = 0.0f;
                D_800F3FB0[D_80101AA4_ChanceTime[1]]->rot.y = 0.0f;
                work[0]->unk_3C = 0.0f;
                work[1]->unk_3C = 0.0f;
                D_801011F4_ChanceTime = 0;
                D_801011F6_ChanceTime = 0;
                D_8010175C_ChanceTime = 1;
                func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[0]], 0x27);
                func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[1]], 0x27);
                omAddPrcObj(func_800F9B50_ChanceTime, 0x3F00, 0x800, 0);
            }
            break;
        case 10:
            if (GwPlayer[D_801012E0_ChanceTime].stars == 0 && GwPlayer[D_801012E1_ChanceTime].stars == 0) {
                D_800F3FB0[D_80101AA4_ChanceTime[0]]->rot.y = 0.0f;
                D_800F3FB0[D_80101AA4_ChanceTime[1]]->rot.y = 0.0f;
                work[0]->unk_3C = 0.0f;
                work[1]->unk_3C = 0.0f;
                D_801011F4_ChanceTime = 0;
                D_801011F6_ChanceTime = 1;
                D_8010175C_ChanceTime = 0;
                func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[0]], 0x27);
                func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[1]], 0x27);
                omAddPrcObj(func_800F9B50_ChanceTime, 0x3F00, 0x800, 0);
            }
            break;
        }
        D_801012A0_ChanceTime++;
        break;
    case 1:
        if (func_800FAE60_ChanceTime(obj) == 1) {
            D_801012A0_ChanceTime++;
        }
        break;
    case 3:
        if (D_801012A4_ChanceTime++ >= 31) {
            D_801012A4_ChanceTime = 0;
            D_801012A0_ChanceTime++;
        }
        break;
    case 4:
        work[0]->unk_3C = 0.0f;
        work[1]->unk_3C = 0.0f;
        D_800F3FB0[D_80101AA4_ChanceTime[0]]->rot.y = 0.0f;
        D_800F3FB0[D_80101AA4_ChanceTime[1]]->rot.y = 0.0f;
        work[0]->unk_40 = 0.0f;
        work[1]->unk_40 = 0.0f;
        switch (D_801012E2_ChanceTime) {
        case 0:
            func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[0]], 0x26);
            func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[1]], 0x25);
            break;
        case 1:
            func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[0]], 0x25);
            func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[1]], 0x26);
            break;
        case 4:
            if (GwPlayer[D_801012E0_ChanceTime].coins != GwPlayer[D_801012E1_ChanceTime].coins) {
                if (GwPlayer[D_801012E1_ChanceTime].coins < GwPlayer[D_801012E0_ChanceTime].coins) {
                    func_80060618(0x451, D_801012E0_ChanceTime);
                    func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[0]], 0x23);
                    func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[1]], 0x24);
                } else {
                    func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[0]], 0x24);
                    func_80060618(0x451, D_801012E1_ChanceTime);
                    func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[1]], 0x23);
                }
            } else {
                func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[0]], 0x27);
                func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[1]], 0x27);
            }
            break;
        case 2:
        case 5:
        case 7:
            func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[0]], 0x24);
            func_80060618(0x451, D_801012E1_ChanceTime);
            func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[1]], 0x23);
            break;
        case 3:
        case 6:
        case 8:
            func_80060618(0x451, D_801012E0_ChanceTime);
            func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[0]], 0x23);
            func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[1]], 0x24);
            break;
        case 10:
            if (GwPlayer[D_801012E0_ChanceTime].stars != GwPlayer[D_801012E1_ChanceTime].stars) {
                if (GwPlayer[D_801012E1_ChanceTime].stars < GwPlayer[D_801012E0_ChanceTime].stars) {
                    func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[0]], 0x25);
                    func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[1]], 0x26);
                } else {
                    func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[0]], 0x26);
                    func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[1]], 0x25);
                }
            } else {
                func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[0]], 0x27);
                func_800184BC(D_800F3FB0[D_80101AA4_ChanceTime[1]], 0x27);
            }
            break;
        }
        D_801012A0_ChanceTime++;
        break;
    case 5:
        if (D_801011F9_ChanceTime == 1) {
            t = func_80025D18(D_800F3FB0[D_80101AA4_ChanceTime[0]]->model[0]);
            if (func_80025D40(D_800F3FB0[D_80101AA4_ChanceTime[0]]->model[0]) <= t) {
                t = func_80025D18(D_800F3FB0[D_80101AA4_ChanceTime[1]]->model[0]);
                if (func_80025D40(D_800F3FB0[D_80101AA4_ChanceTime[1]]->model[0]) <= t) {
                    D_801011F4_ChanceTime = 0;
                    D_801011F5_ChanceTime = 1;
                    D_801012A0_ChanceTime++;
                }
            }
        }
        break;
    case 2:
        D_801012A0_ChanceTime++;
        break;
    }
}
void func_800FB950_ChanceTime(omObjData* obj) {
    s16 i;
    s16 m;
    s16 base;
    s16 base2;
    s16 loaded;

    base = 0;
    base2 = 0;
    for (i = 0; i < 20; i++) {
        D_80101868_ChanceTime[i].unk_00 = -1;
        D_80101868_ChanceTime[i].unk_04 = 0.0f;
        D_80101868_ChanceTime[i].unk_08 = 0.0f;
        D_80101868_ChanceTime[i].unk_0C = 0.0f;
        D_80101868_ChanceTime[i].unk_10 = 0.0f;
        D_80101868_ChanceTime[i].unk_14 = 0.0f;
        D_80101868_ChanceTime[i].unk_18 = 0;
        D_80101868_ChanceTime[i].unk_19 = 0;
    }
    obj->model[0] = -1;
    loaded = 0;
    for (i = 1; i < 21; i++) {
        if (loaded == 0) {
            m = LoadFormFile(0x1F0001, 0x6B9);
            base = m;
            loaded = 1;
        } else {
            m = func_80023FC8(base);
        }
        obj->model[i] = m;
        func_80025830(obj->model[i], 0.135f, 0.135f, 0.135f);
        func_800258EC(obj->model[i], 4, 4);
    }
    /* retail never sets loaded here: every coin model is a new func_8004F234 */
    loaded = 0;
    for (i = 21; i < 41; i++) {
        if (loaded == 0) {
            obj->model[i] = base2 = func_8004F234();
        } else {
            obj->model[i] = func_80023FC8(base2);
        }
        func_80025830(obj->model[i], 0.5f, 0.5f, 0.5f);
        func_800258EC(obj->model[i], 4, 4);
    }
    obj->func_ptr = &func_800FB00C_ChanceTime;
}
void func_800FBBC4_ChanceTime(omObjData* obj) {
    switch (D_801011F7_ChanceTime) {
    case 1:
        switch (D_801012AC_ChanceTime) {
        case 0:
            func_800258EC(obj->model[0], 4, 0);
            func_800258EC(obj->model[1], 4, 0);
            obj->rot.y = 0.0f;
            D_801012A8_ChanceTime = 0;
            D_801012AC_ChanceTime++;
            break;
        case 1:
            if (D_801012A8_ChanceTime >= 11) {
                func_80025C20(obj->model[0], func_80025E48(obj->motion[3]), 0, 0x1E, 2);
                D_801012AC_ChanceTime++;
            }
            D_801012A8_ChanceTime++;
            break;
        case 2:
            omAddPrcObj(func_800FF354_ChanceTime, 0x3F00, 0x800, 0);
            D_801012A8_ChanceTime = 0;
            D_801012AC_ChanceTime++;
            break;
        case 3:
            if (++D_801012A8_ChanceTime >= 21) {
                D_801012AC_ChanceTime++;
            }
            break;
        case 4:
            func_80025C20(obj->model[0], func_80025E48(obj->motion[0]), 0, 0x1E, 2);
            D_801012AC_ChanceTime++;
            break;
        case 5:
            if (D_80101320_ChanceTime == 1) {
                D_801012AC_ChanceTime++;
            }
            break;
        case 6:
            if (obj->rot.y < 90.0f) {
                obj->rot.y += 6.0f;
                if (obj->rot.y >= 90.0f) {
                    obj->rot.y = 90.0f;
                    D_801012AC_ChanceTime++;
                }
            }
            break;
        case 7:
            D_801011F3_ChanceTime = 1;
            func_80025C20(obj->model[0], func_80025E48(obj->motion[1]), 0, 0x1E, 2);
            D_801012A8_ChanceTime = 0;
            D_801012AC_ChanceTime++;
            break;
        case 8:
            if (D_801012A8_ChanceTime < 30) {
                D_801012A8_ChanceTime++;
                obj->trans.x -= (D_80101208_ChanceTime.x - CT_PREV(D_80101208_ChanceTime, D_801011FC_ChanceTime).x) / 30.0f;
                obj->trans.y -= (D_80101208_ChanceTime.y - CT_PREV(D_80101208_ChanceTime, D_801011FC_ChanceTime).y) / 30.0f;
                obj->trans.z -= (D_80101208_ChanceTime.z - CT_PREV(D_80101208_ChanceTime, D_801011FC_ChanceTime).z) / 30.0f;
            } else {
                func_800258EC(obj->model[0], 4, 4);
                func_800258EC(obj->model[1], 4, 4);
                D_801012AC_ChanceTime++;
            }
            break;
        case 9:
            D_801011F7_ChanceTime = 0;
            D_801012A8_ChanceTime = 0;
            D_801012AC_ChanceTime = 0;
            break;
        }
        break;
    case 2:
        switch (D_801012AC_ChanceTime) {
        case 0:
            func_800258EC(obj->model[0], 4, 0);
            func_800258EC(obj->model[1], 4, 0);
            func_80025BB8(obj->model[0], obj->motion[1]);
            func_80025EB4(obj->model[0], 2, 2);
            obj->rot.y = -90.0f;
            func_80055B50(D_801012E0_ChanceTime, D_801012E0_ChanceTime);
            func_800559F8();
            omAddPrcObj(func_800F87CC_ChanceTime, 0x3F00, 0x800, 0);
            D_801012A8_ChanceTime = 0;
            D_801012AC_ChanceTime++;
            break;
        case 1:
            if (D_801012A8_ChanceTime >= 31) {
                D_801012A8_ChanceTime = 0;
                D_801012AC_ChanceTime++;
            }
            D_801012A8_ChanceTime++;
            break;
        case 2:
            if (D_801012A8_ChanceTime < 30) {
                D_801012A8_ChanceTime++;
                obj->trans.x += (D_80101208_ChanceTime.x - CT_PREV(D_80101208_ChanceTime, D_801011FC_ChanceTime).x) / 30.0f;
                obj->trans.y += (D_80101208_ChanceTime.y - CT_PREV(D_80101208_ChanceTime, D_801011FC_ChanceTime).y) / 30.0f;
                obj->trans.z += (D_80101208_ChanceTime.z - CT_PREV(D_80101208_ChanceTime, D_801011FC_ChanceTime).z) / 30.0f;
            } else {
                D_801012AC_ChanceTime++;
            }
            break;
        case 3:
            if (obj->rot.y < 0.0f) {
                obj->rot.y += 6.0f;
                if (obj->rot.y >= 0.0f) {
                    obj->rot.y = 0.0f;
                    D_801012AC_ChanceTime++;
                }
            }
            break;
        case 4:
            func_80025C20(obj->model[0], func_80025E48(obj->motion[0]), 0, 0x1E, 2);
            func_80055B64();
            D_801012AC_ChanceTime++;
            break;
        case 5:
            omAddPrcObj(func_800FF3F0_ChanceTime, 0x3F00, 0x800, 0);
            D_801012AC_ChanceTime++;
            break;
        case 6:
            if (D_80101320_ChanceTime == 1) {
                D_801012AC_ChanceTime++;
                D_801012A8_ChanceTime = 0;
            }
            break;
        case 7:
            func_80025C20(obj->model[0], func_80025E48(obj->motion[3]), 0, 0x1E, 2);
            D_801012A8_ChanceTime = 0;
            D_801012AC_ChanceTime++;
            break;
        case 8:
            if (++D_801012A8_ChanceTime >= 31) {
                D_801012AC_ChanceTime++;
            }
            break;
        case 9:
            D_801011F7_ChanceTime = 0;
            D_801012A8_ChanceTime = 0;
            D_801012AC_ChanceTime = 0;
            func_80009438();
            break;
        }
        break;
    }
    func_80025798(obj->model[1], obj->trans.x, 0.0f, obj->trans.z);
}
void func_800FC1C8_ChanceTime(omObjData* obj) {
    f32 x = D_80101208_ChanceTime.x;
    f32 y = D_80101208_ChanceTime.y;
    f32 z = D_80101208_ChanceTime.z;

    obj->model[0] = LoadFormFile(0xA0068, 0x689);
    obj->model[1] = func_800174F4(0x20, 0x299);
    func_80025830(obj->model[1], 2.6999998f, 1.0f, 2.6999998f);
    func_8001775C(obj, 0, 0xA0068);
    func_8001775C(obj, 2, 0xA0069);
    func_8001775C(obj, 3, 0xA006A);
    func_8001775C(obj, 4, 0xA006B);
    func_8001775C(obj, 5, 0xA006C);
    func_8001775C(obj, 6, 0xA006D);
    func_8001775C(obj, 1, 0xA006E);
    func_8001775C(obj, 7, 0xA006F);
    func_80025EB4(obj->model[0], 2, 2);
    func_800258EC(obj->model[0], 4, 4);
    func_800258EC(obj->model[1], 4, 4);
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = z;
    obj->rot.y = 0.0f;
    func_80025798(obj->model[1], x, obj->rot.y, z);
    obj->scale.x = obj->scale.y = obj->scale.z = 1.3499999f;
    obj->func_ptr = &func_800FBBC4_ChanceTime;
}