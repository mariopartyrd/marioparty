#include "CraneGame.h"

/* .data (0x800FF500..0x800FF560) */
s16 D_800FF500_CraneGame[4][2] = { { 0x38, 0x26 }, { 0x108, 0x26 }, { 0x38, 0xD8 }, { 0x108, 0xD8 } }; /* score digits */
s32 D_800FF510_CraneGame[4] = { 0, 0, 0, 0 }; /* shown coin counts */
s16 D_800FF520_CraneGame = 0;
s16 D_800FF522_CraneGame = 90;
s16 D_800FF524_CraneGame[4] = { 6, 9, 12, 0 }; /* grip strength per grab quality */
s16 D_800FF52C_CraneGame[6] = { 0, 0, 0, 0, 2, 5 }; /* grip bonus per prize */
f32 D_800FF538_CraneGame[6] = { 0.0f, 20.0f, 40.0f, 20.0f, -50.0f, -100.0f }; /* claw depth per character */
s32 D_800FF550_CraneGame[4] = { 0x00080008, 0x00060006, 0x00050005, 0 }; /* read as (s16): struggle rate */

void func_800F65E0_CraneGame(void) {
    s16 var_a0;
    u8 temp_s0;
    s16 i;

    func_80029090(0x32);
    func_8002ADF0(&D_800EDEC0, 0x40);
    func_8001DE70(0x20);
    omInitObjMan(0x32, 0);
    func_80060088();
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    func_800178A0(1);
    temp_s0 = func_800178E8();
    func_80017660(temp_s0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(temp_s0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 30.0f, 80.0f, 8000.0f);
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    D_800FFE24_CraneGame = 0;
    D_800FFE26_CraneGame = 0;
    D_800FFE30_CraneGame = 0x78;
    D_800FFE2C_CraneGame = 0;
    D_800FFE28_CraneGame = 1;
    D_800FFE2A_CraneGame = 0;
    D_800FFE34_CraneGame = _CheckFlag(0x2B);
    D_80100FC0_CraneGame = 0;
    for (i = 0; i < ARRAY_COUNT(D_80100BC0_CraneGame); i++) {
        D_80100BC0_CraneGame[i] = 0;
    }
    D_800FFE2E_CraneGame = 0x384;
    D_80100FD0_CraneGame = omAddObj(3, 0, 0, -1, func_800F6B10_CraneGame);
    D_800F2AF8[D_800ED440] = omAddObj(1, 2, 0, -1, func_800F77A8_CraneGame);
    omSetStatBit(D_800F2AF8[D_800ED440], 0xA0);
    D_800ED440++;
    D_800F3FB0[D_800F2BC0++] = omAddObj(2, 2, 0x32, -1, func_800F7DD0_CraneGame);
    D_800FFE32_CraneGame = 0;

    for (i = 0; i < ARRAY_COUNT(D_800FFE72_CraneGame); i++) {
        D_800FFE72_CraneGame[i] = i;
    }
    
    for (i = 0; i < 36; i++) {
        u32 index1;
        u32 index2;
        s16 temp;

        index1 = (rand8() * 3);
        index1 = index1 >> 7;
        index2 = (rand8() * 3);
        
        temp = D_800FFE72_CraneGame[index1];
        index2 = index2 >> 7;
        
        D_800FFE72_CraneGame[index1] = D_800FFE72_CraneGame[index2];
        D_800FFE72_CraneGame[index2] = temp;
    }

    for (i = 0; i < ARRAY_COUNT(D_800EDE70); i++) {
        D_800EDE70[D_800EE984] = omAddObj(5, 1, 0, -1, func_800FA154_CraneGame);
        omSetStatBit(D_800EDE70[D_800EE984], 0xA0);
        D_800EE984++;       
    }

    omAddObj(4, 0, 0, -1, func_800FB08C_CraneGame);
    func_800234B8(0, 0x80, 0x80, 0x80);
    func_800234B8(1, 0xFF, 0xFF, 0xFF);
    func_80023504(1, 0.0f, 64.0f, 192.0f);
    D_800FFE86_CraneGame[0] = D_800FFE86_CraneGame[1] = 0;
    CZoom = 2200.0f;
    CRot.x = -35.0f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    Center.x = 0.0f;
    Center.y = 420.0f;
    Center.z = 300.0f;
    func_800FD240_CraneGame();
    func_800FB830_CraneGame();
    func_800FBAE8_CraneGame(0.0f);
    func_800FE620_CraneGame();
    func_800FE658_CraneGame();
    func_800FE7B8_CraneGame(30, 30);
    for (i = 0, var_a0 = 0; i < MAX_PLAYERS; i++) {
        if (GwPlayer[i].group == 0) {
            D_800FFE7E_CraneGame = i;
        } else {
            D_800FFE80_CraneGame[var_a0++] = i;
        }
    }
}

void func_800F6B10_CraneGame(omObjData* arg0) {
    arg0->func_ptr = &func_800F6B3C_CraneGame;
    SetFadeInTypeAndTime(0, 0x10);
}

void func_800F6B3C_CraneGame(void) {
    switch (D_800FFE24_CraneGame) {
    case 0:
        if (--D_800FFE30_CraneGame == 0) {
            D_800FFE24_CraneGame++;
            D_800FFE30_CraneGame = 0x3C;
            GMesCreate(0);
        }
        if (D_800FFE30_CraneGame == 0x1E) {
            D_800FFE20_CraneGame = omAddObj(7, 0U, 0U, -1, &func_800F6F54_CraneGame);
        }
        if (D_800FFE30_CraneGame == 0x38) {
            func_80060128(0x1D);
        }
        break;
    case 1:
        if (--D_800FFE30_CraneGame == 0) {
            D_800FFE24_CraneGame++;
            D_800FFE28_CraneGame = 0;
            func_800FB674_CraneGame();
        }
        break;
    case 2:
        if ((D_800FFE28_CraneGame == 0) && (D_800FFE2E_CraneGame != 0)) {
            D_800FFE2E_CraneGame -= 1;
        }
        if (D_800FFE2C_CraneGame != 0) {
            D_800FFE28_CraneGame = 1;
            if (D_800FFE34_CraneGame == 0) {
                D_800FFE24_CraneGame = (u16) D_800FFE24_CraneGame + 1;
                if (D_800FFE2A_CraneGame == 0) {
                    GMesCreate(0xE);
                } else {
                    GMesCreate(2);
                    func_800FE7AC_CraneGame(0);
                }
            } else {
                D_800FFE24_CraneGame = 5;
                GMesCreate(2);
                if (D_800FFE2A_CraneGame != 0) {
                    func_800FE7AC_CraneGame(0);
                }
            }
            func_800601D4(0x28);
            func_800FB73C_CraneGame();
        }
        break;
    case 3:
        if (GMesStatAllGet() == 2) {
            D_800FFE24_CraneGame++;
            if (D_800FFE2A_CraneGame == 0) {
                func_80060128(0x34);
                D_800FFE30_CraneGame = 0x78;
            } else {
                func_80060128(0x33);
                D_800FFE30_CraneGame = 0x7D;
            }
        }
        break;
    case 4:
        if (D_800FFE30_CraneGame != 0) {
            D_800FFE30_CraneGame--;
        }
        if (D_800FF522_CraneGame != 0) {
            D_800FF522_CraneGame -= 1;
        }
        if (GMesWait() == 0) {
            D_800FF520_CraneGame = 1;
        }
        if ((D_800FFE30_CraneGame == 0) || ((D_800FF520_CraneGame != 0) && (D_800FF522_CraneGame == 0))) {
            D_800FFE24_CraneGame = -1;
            D_800FFE2C_CraneGame = -1;
            if (D_800FFE34_CraneGame == 0) {
                func_80060398(0x28);
                func_800601D4(0x28);
            }
            func_800726AC(0, 0x14);
        }
        break;
    case 5:
        if (GMesStatAllGet() == 2) {
            D_800FFE24_CraneGame = 4;
            D_800FFE30_CraneGame = 0x3C;
            D_800FF522_CraneGame = 0;
        }
        break;
    }
    func_800FEB08_CraneGame();
    if (D_800F5144 != 0) {
        D_800FFE2C_CraneGame = -1;
    }
    func_800F6EF0_CraneGame();
}



void func_800F6EC4_CraneGame(void) {
    HuMemDirectFree(D_800FFE3C_CraneGame);
    HuMemDirectFree(D_800FFE38_CraneGame);
}

void func_800F6EF0_CraneGame(void) {
    if ((D_800FFE2C_CraneGame < 0) && (func_80072718() == 0)) {
        func_800FD278_CraneGame();
        func_800FB8E8_CraneGame();
        func_800F7138_CraneGame();
        func_800F6EC4_CraneGame();
        func_80060198();
        omOvlReturnEx(1);
    }
}

void func_800F6F54_CraneGame(omObjData* arg0) {
    arg0->work[0] = GMesCreate(8, (D_800FFE2E_CraneGame / 30), 0xA0, 0x18);
    arg0->func_ptr = &func_800F6FCC_CraneGame;
}

void func_800F6FCC_CraneGame(omObjData* arg0) {
    func_80079078((D_800FFE2E_CraneGame + 29) / 30);
    if ((D_800FFE2E_CraneGame == 0) || (D_800FFE2C_CraneGame != 0)) {
        arg0->func_ptr = NULL;
        func_800790C0();
    }
}


/* The claw block's address is packed into obj->work[0..3]. The host keeps the block's index in
   D_80100BC0_CraneGame there instead (a host pointer does not fit in four bytes). */
CGClaw* func_800F704C_CraneGame(omObjData* arg0) {
    CGClaw* temp_v0;

    temp_v0 = HuMemDirectMalloc(sizeof(CGClaw));
    D_80100BC0_CraneGame[D_80100FC0_CraneGame] = temp_v0;
    arg0->work[0] = (u32)temp_v0 >> 0x18;
    arg0->work[1] = (u32)temp_v0 >> 0x10;
    arg0->work[2] = (u32)temp_v0 >> 8;
    arg0->work[3] = (u32)temp_v0;
    temp_v0->unk0 = 0;
    temp_v0->unk2 = 0;
    temp_v0->unk8 = 0;
    temp_v0->unkA = (u16) D_80100FC0_CraneGame;
    temp_v0->unkC = temp_v0->unk10 = temp_v0->unk14 = 0.0f;
    temp_v0->unk18 = temp_v0->unk1C = temp_v0->unk20 = 0.0f;
    temp_v0->unk24 = temp_v0->unk28 = temp_v0->unk2C = 0.0f;
    temp_v0->unk3C = temp_v0->unk3E = temp_v0->unk40 = temp_v0->unk42 = 0;
    temp_v0->unk44 = temp_v0->unk46 = temp_v0->unk48 = temp_v0->unk4A = 0;
    temp_v0->unk4C = temp_v0->unk4E = temp_v0->unk50 = temp_v0->unk52 = 0;
    temp_v0->unk54 = temp_v0->unk56 = temp_v0->unk58 = temp_v0->unk5A = 0;
    D_80100FC0_CraneGame++;
    return temp_v0;
}


void func_800F7138_CraneGame(void) {
    s16 i;

    for (i = 0; i < D_80100FC0_CraneGame; i++) {
        if (D_80100BC0_CraneGame[i] != NULL) {
            HuMemDirectFree(D_80100BC0_CraneGame[i]);
        }
    }
}

/* Unpacks func_800F704C's claw pointer (the host: its index). */
CGClaw* func_800F71B8_CraneGame(omObjData* arg0) {
    return (CGClaw*) ((arg0->work[0] << 0x18) | (arg0->work[1] << 0x10) | (arg0->work[2] << 8) | arg0->work[3]);
}

s32 func_800F71E4_CraneGame(omObjData* arg0) {
    f32 temp_f12;
    s32 var_s0;
    unk2C0C0Struct50* temp_v0;

    temp_v0 = D_800F2B7C[D_800FFE70_CraneGame].unk_6C->unk_A0;
    temp_f12 = (temp_v0->unk_08.x - arg0->trans.x) * (temp_v0->unk_08.x - arg0->trans.x) + (temp_v0->unk_08.z - arg0->trans.z) * (temp_v0->unk_08.z - arg0->trans.z);
    var_s0 = 0;
    if (sqrtf(temp_f12) < 180.0) {
        var_s0 = 1;
    }
    return var_s0;
}

s16 func_800F7290_CraneGame(f32 arg0) {
    f32 temp_f0;
    f32 var_f12;
    s16 var_s4;
    unk2C0C0StructC0* temp_s2;
    unk2C0C0StructE0* var_s0;
    unk2C0C0StructE0* var_s1;
    s16 i;

    var_s4 = 0;
    temp_s2 = D_800F2B7C[D_800FFE70_CraneGame].unk_6C;
    var_s1 = temp_s2->unk_04;
    var_s0 = temp_s2->unk_08[D_800F37F0];

    for (i = 0; i < temp_s2->unk_72; i++) {
        var_f12 = (temp_s2->unk_A0->unk_08.y + var_s0->unk_02 - arg0) / 4.0;
        if (var_f12 < -90.0) {
            var_f12 = -90.0f;
        }
        if (var_f12 > 90.0) {
            var_f12 = 90.0f;
        }
        temp_f0 = func_800AEFD0(var_f12);
        if (temp_f0 != 0.0) {
            var_s4 = 1;
        }
        var_s0->unk_00 = (var_s1->unk_00 + (var_s1->unk_00 * 0.8 * temp_f0));
        var_s0->unk_04 = (var_s1->unk_04 + (var_s1->unk_04 * 0.8 * temp_f0));
        var_s1++;
        var_s0++;        
    }
    
    return var_s4;
}

s16 func_800F746C_CraneGame(f32* x, f32* y, f32* z, f32 dx, f32 dy, f32 dz, f32 r, s16 mode) {
    Vec d;
    unk2C0C0StructC0* m;
    f32 dist;
    f32 h;
    f32 f;
    s16 ret;

    ret = 0;
    if (mode != 2) {
        m = D_800F2B7C[D_800FFE70_CraneGame].unk_6C;
        d.x = m->unk_A0->unk_08.x - *x;
        d.z = m->unk_A0->unk_08.z - *z;
        dist = sqrtf(d.x * d.x + d.z * d.z);
        if (dist < r + 180.0) {
            h = *y - r;
            if (h < 300.0) {
                if (mode == 0 && h - dy >= 300.0) {
                    *y = r + 300.0;
                } else {
                    f = 300.0 - (*y - r);
                    if (r < f) {
                        f = r;
                    }
                    h = func_800AEAC0(f / r * 90.0) * r + 180.0;
                    if (dist != 0.0) {
                        d.x /= dist;
                        d.z /= dist;
                        *x = m->unk_A0->unk_08.x + -d.x * h;
                        *z = m->unk_A0->unk_08.z + -d.z * h;
                    }
                }
                ret = 2;
            }
        }
    }
    if (*x < -420.0) {
        *x = -420.0f;
        ret |= 1;
    }
    if (*x > 500.0) {
        *x = 500.0f;
        ret |= 1;
    }
    if (*z < -480.0) {
        *z = -480.0f;
        ret |= 1;
    }
    if (*z > 640.0) {
        *z = 640.0f;
        ret |= 1;
    }
    return ret;
}
void func_800F77A8_CraneGame(omObjData* arg0) {
    CGBgWork* temp_v0;

    arg0->func_ptr = func_800F7964_CraneGame;
    arg0->trans.x = arg0->trans.y = arg0->trans.z = 0.0f;
    arg0->scale.z = 1.0f;
    arg0->scale.y = 1.0f;
    arg0->scale.x = 1.0f;
    arg0->model[0] = func_800174C0(0x360000, 0xDB);
    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_80025830(arg0->model[0], arg0->scale.x, arg0->scale.y, arg0->scale.z);
    temp_v0 = func_80023684(0x2C, 0x7918);
    arg0->unk_50 = temp_v0;
    func_8009B770(temp_v0, 0U, 0x2CU);
    temp_v0->unk4 = 1;
    temp_v0->unk5 = 0;
    func_80026040(arg0->model[0]);
    func_80039C48("crgbg03_DEF", D_800FFE40_CraneGame[temp_v0->unk5]);
    D_800FFE50_CraneGame[temp_v0->unk5] = D_800FFE60_CraneGame[temp_v0->unk5] = 0;
    arg0->model[1] = D_800FFE70_CraneGame = func_800174C0(0x36000B, 0xA9);
    func_80025798(arg0->model[1], 0.0f, 0.0f, 0.0f);
    func_800257E4(arg0->model[1], 0.0f, 0.0f, 0.0f);
    func_80025830(arg0->model[1], 1.0f, 1.0f, 1.0f);
    func_80026040(arg0->model[1]);
    func_800FB9C4_CraneGame(arg0->model[1]);
}

void func_800F7964_CraneGame(omObjData* arg0) {
    CGBgWork* temp_s1;

    temp_s1 = arg0->unk_50;
    func_80027E48(arg0->model[0], D_800FFE50_CraneGame[temp_s1->unk5], D_800FFE60_CraneGame[temp_s1->unk5], D_800FFE40_CraneGame[temp_s1->unk5][0], D_800FFE40_CraneGame[temp_s1->unk5][1], "doom", 1);
    if ((func_8005FD5C() + D_800F64F8) == 0) {
        D_800FFE50_CraneGame[temp_s1->unk5] = func_8009B618(D_800FFE50_CraneGame[temp_s1->unk5] + 0.4, D_800FFE40_CraneGame[temp_s1->unk5][0]);
        D_800FFE50_CraneGame[temp_s1->unk5] += 0.1;
    }
}


s16 func_800F7A88_CraneGame(f32 x, f32 y, f32 z, f32 r) {
    f32 dx;
    f32 dz;
    f32 d;
    f32 rad;
    f32 best;
    s16 sel;
    s16 i;
    omObjData* o;
    CGWork* w;

    sel = -1;
    best = 9999.0f;
    for (i = 0; i < D_800EE984; i++) {
        o = D_800EDE70[i];
        w = o->unk_50;
        if (w->unk34 > w->unk38) {
            rad = w->unk34;
        } else {
            rad = w->unk38;
        }
        if ((s16)w->unk50 >= 0) {
            dx = o->trans.x - x;
            if (fabs(dx) < rad + r) {
                dz = o->trans.z - z;
                if (fabs(dz) < rad + r) {
                    d = sqrtf(dx * dx + dz * dz);
                    if (d < best && d < 120.0) {
                        best = d;
                        sel = i;
                    }
                }
            }
        }
    }
    if (sel >= 0) {
        o = D_800EDE70[sel];
        if (o->trans.x != x) {
            if (x < o->trans.x) {
                o->trans.x -= 2.0;
                if (o->trans.x < x) {
                    o->trans.x = x;
                }
            } else {
                o->trans.x += 2.0;
                if (x < o->trans.x) {
                    o->trans.x = x;
                }
            }
        }
    }
    return sel;
}
s16 func_800F7CC8_CraneGame(f32 arg0, f32 arg1, f32 arg2, s16 arg3) {
    f32 distanceSquared;
    f32 clampedDistance;
    s16 ret;
    omObjData* temp_v0;

    temp_v0 = D_800EDE70[arg3];
    distanceSquared = ((temp_v0->trans.x - arg0) * (temp_v0->trans.x - arg0)) + ((temp_v0->trans.z - arg1) * (temp_v0->trans.z - arg1));
    clampedDistance = sqrtf(distanceSquared);

    clampedDistance -= arg2;
    if (clampedDistance < 0.0) {
        clampedDistance = 0.0f;
    }
    if (clampedDistance < 40.0) {
        ret = 0;
    } else if (clampedDistance < 80.0) {
        ret = 1;
    } else if (clampedDistance < 120.0) {
        ret = 2;
    } else {
        ret = -1;
    }
    return ret;
}

void func_800F7DD0_CraneGame(omObjData* obj) {
    s16 cand[3];
    CGClaw* c;
    CGWork* w;
    u8 chr;
    s16 i;
    s16 n;
    s16 max;
    s16 coins;

    chr = GwPlayer[D_800FFE7E_CraneGame].character;
    obj->model[0] = LoadFormFile(D_800C59AC[chr].unk_00 | D_800C59AC[chr].unk_08, 0x299);
    w = func_80023684(sizeof(CGWork), 0x7918);
    obj->unk_50 = w;
    func_8009B770(w, 0, sizeof(CGWork));
    w->unkD8 = func_80023684(obj->mtncnt * sizeof(CGWork), 0x7918);
    func_8009B770(w->unkD8, 0, obj->mtncnt * sizeof(CGWork));
    func_8001874C(obj, 0, D_800C59AC[GwPlayer[D_800FFE7E_CraneGame].character].unk_00 | 0x57, 1, 0);
    func_8001874C(obj, 1, D_800C59AC[GwPlayer[D_800FFE7E_CraneGame].character].unk_00 | 0x58, 2, 0);
    func_8001874C(obj, 2, D_800C59AC[GwPlayer[D_800FFE7E_CraneGame].character].unk_00 | 0x59, 0, 0);
    obj->model[1] = func_800174C0(0x360001, 0xD9);
    obj->func_ptr = func_800F82D4_CraneGame;
    func_800093FC(obj, -420.0f, 600.0f, 640.0f);
    func_8000940C(obj, 0.0f, 180.0f, 0.0f);
    func_8000941C(obj, 2.0f, 2.0f, 2.0f);
    w = obj->unk_50;
    w->unk50 = 0;
    w->unk52 = 0;
    w->unk58 = GwPlayer[D_800FFE7E_CraneGame].character;
    w->unk56 = GwPlayer[D_800FFE7E_CraneGame].port;
    w->unkC0 = 0xFFFF;
    w->unk3C = -1.0f;
    c = func_800F704C_CraneGame(obj);
    c->unkC = obj->trans.x;
    c->unk10 = obj->trans.y + 1700.0;
    c->unk14 = obj->trans.z;
    func_80025798(obj->model[1], c->unkC, c->unk10, c->unk14);
    if (GwPlayer[D_800FFE7E_CraneGame].flags & 1) {
        n = 0;
        max = 0;
        for (i = 0; i < 3; i++) {
            coins = GwPlayer[D_800FFE80_CraneGame[i]].coins;
            if (coins >= max) {
                if (max < coins) {
                    max = coins;
                    n = 0;
                }
                cand[n++] = i;
            }
        }
        if ((s16)(max / 3) >= 11) {
            c->unk58 = cand[(rand8() * n) >> 8];
        } else {
            c->unk58 = 5;
        }
    }
    func_800184BC(obj, 0);
    func_80025C20(obj->model[0], func_80025E48(obj->motion[w->unkCA] & 0x3FFF), 0,
                  func_80025D40(obj->motion[w->unkCA] & 0x3FFF), 2);
    if (D_800FFE34_CraneGame == 0) {
        func_800FB800_CraneGame(D_800FFE7E_CraneGame, GwPlayer[D_800FFE7E_CraneGame].coins);
    } else {
        func_800FB800_CraneGame(D_800FFE7E_CraneGame, GwQuest.coinNum);
    }
}
// register allocation (masked 0)
#ifdef NON_MATCHING
void func_800F82D4_CraneGame(omObjData* obj) {
    Vec pos;
    Vec d;
    Vec a;
    f32 oz;
    f32 ox;
    f32 oy;
    f32 ang;
    f32 low;
    CGWork* w;
    CGClaw* c;
    omObjData* o;
    unk2C0C0Struct50* m;
    u32 stick;
    s16 sz;
    s16 sx;
    s16 k;
    s16 t;
    s16 moving;
    u16 btn;

    w = obj->unk_50;
    moving = 0;
    c = func_800F71B8_CraneGame(obj);
    if (c->unk0 == 0) {
        c->unk0 |= 1;
        c->unk2 = 0;
        c->unk6 = 100;
        c->unk4 = 100;
        c->unk8 = 0;
        c->unk18 = c->unk20 = 0.0f;
        c->unk3C = 0;
        c->unk3E = 0;
        c->unk40 = 0;
        c->unk44 = -1;
        c->unk46 = 0;
        c->unk48 = -1;
        c->unk4C = 32;
        c->unk4E = 32;
        c->unk5A = -1;
    }
    ox = obj->trans.x;
    oy = obj->trans.y;
    oz = obj->trans.z;
    pos.x = c->unkC;
    pos.y = c->unk10;
    pos.z = c->unk14;
    btn = 0;
    if (D_800FFE28_CraneGame == 0) {
        switch (c->unk8) {
        case 0:
            func_800184BC(obj, 0);
            sz = 0;
            if (!(GwPlayer[D_800FFE7E_CraneGame].flags & 1)) {
                stick = func_80009C90(obj, ContStkX[w->unk56], ContStkY[w->unk56]);
                sx = stick >> 16;
                sz = stick;
                btn = ContBtnTrg[w->unk56];
            } else {
                o = D_800EDE70[c->unk58];
                sx = 0;
                if (fabs(pos.x - o->trans.x) >= 10.0) {
                    sx = -1;
                    if (pos.x < o->trans.x) {
                        sx = 1;
                    }
                } else if (fabs(pos.z - o->trans.z) >= 10.0) {
                    sz = 1;
                    if (pos.z < o->trans.z) {
                        sz = -1;
                    }
                } else {
                    btn |= 0x8000;
                }
            }
            ang = func_8009B618(func_800B0CD8(sx, sz) + 180.0, 360.0);
            if (sx | sz) {
                if (c->unk44 < 0 && w->unk3C == -1.0) {
                    c->unk44 = PlaySound(0x2BE);
                }
                ang = (s16)(func_8009B618(ang + 45.0, 360.0) / 90.0) * 90.0;
                if (ang != w->unk3C) {
                    c->unk3E = 0;
                    w->unk3C = ang;
                } else {
                    w->unk40 = (c->unk3E < 8) ? (f32)c->unk3E * 0.1 * 10.0 : 8.0f;
                    pos.x -= func_800AEAC0(ang) * w->unk40;
                    pos.z += func_800AEFD0(ang) * w->unk40;
                    c->unk3E++;
                }
                moving = 1;
            } else {
                w->unk3C = -1.0f;
            }
            if ((btn & 0x8000) || D_800FFE2E_CraneGame == 0) {
                c->unk2 &= ~4;
                c->unk8 = 1;
                c->unk3C = 16;
                low = 0.0f;
                for (k = 0; k < 33; k++) {
                    if (k == 0) {
                        d.x = pos.x;
                        d.z = pos.z;
                    } else if (k < 17) {
                        ang = (f32)(k - 1) * 22.5;
                        d.x = pos.x + func_800AEFD0(ang) * 10.0 * 10.0;
                        d.z = pos.z + func_800AEAC0(ang) * 10.0 * 10.0;
                    } else {
                        ang = (f32)(k - 17) * 22.5;
                        d.x = pos.x + func_800AEFD0(ang) * 5.0 * 10.0;
                        d.z = pos.z + func_800AEAC0(ang) * 5.0 * 10.0;
                    }
                    d.y = 600.0f;
                    if (func_800FDC94_CraneGame(&d, 0.0f, -800.0f, 0.0f, -1) != 0 && low < d.y) {
                        low = d.y;
                        if (k == 0) {
                            break;
                        }
                    }
                }
                c->unk1C = low - 100.0;
                c->unk48 = PlaySound(0x2C0);
            }
            break;
        case 1:
            pos.y -= 15.0;
            if (!(c->unk2 & 2)) {
                if (pos.y - 1700.0 <= c->unk1C - D_800FF538_CraneGame[w->unk58]) {
                    pos.y = c->unk1C + 1700.0 - D_800FF538_CraneGame[w->unk58];
                    goto stop;
                }
            } else {
            stop:
                c->unk8++;
                c->unk3C = 32;
                if ((c->unk2 & 2) || pos.y - 1700.0 <= -100.0) {
                    c->unk2 |= 4;
                }
                func_8006071C(c->unk48);
                c->unk48 = -1;
            }
            if (c->unk3C != 0) {
                if (--c->unk3C == 0) {
                    func_800184BC(obj, 1);
                }
            }
            func_800FE7AC_CraneGame(2);
            break;
        case 2:
            if (--c->unk3C == 0) {
                c->unk8++;
                if ((s8)c->unk5A >= 0) {
                    t = (s8)func_800F7CC8_CraneGame(obj->trans.x, obj->trans.z, 0.0f, c->unk5A);
                    c->unk40 = t;
                    if ((s8)t >= 0) {
                        CG_WORK(D_800EDE70[c->unk5A])->unk50 = 2;
                        c->unk4E = c->unk4C =
                            90 / (D_800FF524_CraneGame[c->unk40] + D_800FF52C_CraneGame[D_800EDE70[c->unk5A]->work[0]]);
                    } else {
                        c->unk5A = -1;
                    }
                }
                c->unk48 = PlaySound(0x2C0);
                break;
            }
            if ((s8)c->unk5A >= 0 && c->unk3C == 24) {
                PlaySound(0x2C1);
            }
            if (!(c->unk2 & 4)) {
                c->unk5A = func_800F7A88_CraneGame(obj->trans.x, obj->trans.y, obj->trans.z, c->unk4);
            }
            break;
        case 3:
            pos.y += 15.0;
            if (pos.y >= 2300.0) {
                pos.y = 2300.0f;
                func_8006071C(c->unk48);
                c->unk48 = -1;
                if ((s8)c->unk5A < 0) {
                    D_800FFE2C_CraneGame = 1;
                } else {
                    c->unk8++;
                    c->unk3C = 8;
                    if (c->unk44 < 0) {
                        c->unk44 = PlaySound(0x2BE);
                    }
                }
            }
            break;
        case 4:
            func_800FE7AC_CraneGame(1);
            moving = 1;
            if (pos.z != 640.0) {
                if (c->unk3C == 0) {
                    if (pos.z > 640.0) {
                        pos.z -= 8.0;
                        if (pos.z <= 640.0) {
                            pos.z = 640.0f;
                            c->unk3C = 16;
                        }
                    } else {
                        pos.z += 8.0;
                        if (pos.z >= 640.0) {
                            pos.z = 640.0f;
                            c->unk3C = 16;
                        }
                    }
                } else {
                    c->unk3C--;
                }
            } else if (pos.x != -420.0) {
                if (c->unk3C == 0) {
                    if (pos.x > -420.0) {
                        pos.x -= 8.0;
                        if (pos.x < -420.0) {
                            pos.x = -420.0f;
                        }
                    } else {
                        pos.x += 8.0;
                        if (pos.x > -420.0) {
                            pos.x = -420.0f;
                        }
                    }
                } else {
                    c->unk3C--;
                }
            } else {
                c->unk8++;
                c->unk3C = 32;
            }
            break;
        case 5:
            if (c->unk3C == 24) {
                func_800184BC(obj, 1);
            }
            if (c->unk3C == 16 && (s8)c->unk5A >= 0) {
                D_800EDE70[c->unk5A]->work[1] = 1;
            }
            if (--c->unk3C == 0) {
                c->unk8 = -1;
                D_800FFE28_CraneGame = 1;
            }
            break;
        }
        func_800F746C_CraneGame(&pos.x, &pos.y, &pos.z, 0.0f, 0.0f, 0.0f, 50.0f, 2);
        d.x = obj->trans.x - pos.x;
        d.y = obj->trans.y - pos.y + -128.0;
        d.z = obj->trans.z - pos.z;
        a.x = func_8009B618(func_800B0CD8(d.z, d.y) + 180.0, 360.0);
        a.y = func_8009B618(func_800B0CD8(d.y, d.x) + 90.0, 360.0);
        func_800257E4(obj->model[1], a.x, 0.0f, a.y);
        low = sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
        if (low != 0.0) {
            d.x /= low;
            d.y /= low;
            d.z /= low;
            obj->trans.x = pos.x + d.x * 1700.0;
            obj->trans.y = pos.y + d.y * 1700.0;
            obj->trans.z = pos.z + d.z * 1700.0;
        }
        c->unk2 = func_800F746C_CraneGame(&obj->trans.x, &obj->trans.y, &obj->trans.z, obj->trans.x - ox,
                                          obj->trans.y - oy, obj->trans.z - oz, 50.0f, 0) |
                  (c->unk2 & 0xFFFC);
        if ((u16)c->unk8 - 3 < 3U) {
            if ((s8)c->unk5A >= 0) {
                o = D_800EDE70[c->unk5A];
                if (CG_WORK(o)->unk50 == 2) {
                    o->trans.x += obj->trans.x - ox;
                    o->trans.y += obj->trans.y - oy;
                    o->trans.z += obj->trans.z - oz;
                }
            }
            if (GwPlayer[D_800FFE7E_CraneGame].flags & 1) {
                if (rand8() < GwPlayer[D_800FFE7E_CraneGame].cpu_difficulty * 8 + 88) {
                    btn |= 0x8000;
                }
            } else {
                btn = ContBtnTrg[w->unk56];
            }
            if (c->unk40 < 3 && (btn & 0x8000)) {
                c->unk4C = c->unk4E;
                func_800184BC(obj, 2);
            }
            if ((s8)c->unk5A >= 0 && (--c->unk4C == 0 || D_800EDE70[c->unk5A]->work[1] != 0)) {
                if (++c->unk40 < 3) {
                    c->unk4C = c->unk4E;
                } else if ((s8)c->unk5A >= 0) {
                    D_800EDE70[c->unk5A]->work[1] = 1;
                    c->unk5A = -1;
                    if (c->unk44 >= 0) {
                        func_8006071C(c->unk44);
                        c->unk44 = -1;
                    }
                }
            }
        }
    } else if (c->unk48 >= 0) {
        func_8006071C(c->unk48);
        c->unk48 = -1;
    }
    c->unkC = pos.x;
    c->unk10 = pos.y;
    c->unk14 = pos.z;
    func_80025798(obj->model[1], c->unkC, c->unk10, c->unk14);
    if (moving) {
        if (c->unk46 < 6) {
            c->unk46++;
            if (c->unk44 >= 0) {
                func_8006035C(c->unk44, c->unk46 * 10 + 67);
                func_80060440(c->unk44, c->unk46 * 100 - 600);
            }
        }
    } else if (c->unk46 != 0) {
        if (--c->unk46 == 0) {
            if (c->unk44 >= 0) {
                func_8006071C(c->unk44);
                c->unk44 = -1;
            }
        } else if (c->unk44 >= 0) {
            func_8006035C(c->unk44, c->unk46 * 10 + 67);
            func_80060440(c->unk44, c->unk46 * 100 - 600);
        }
    }
    func_800FBB00_CraneGame(obj->trans.x, obj->trans.y, obj->trans.z);
    func_800FE80C_CraneGame(obj->trans.x, obj->trans.y + 300.0, obj->trans.z, 0);
    if ((u16)c->unk8 - 1 < 3U) {
        func_800FE80C_CraneGame(obj->trans.x, -100.0f, obj->trans.z, 0);
    } else {
        m = D_800F2B7C[D_800FFE70_CraneGame].unk_6C->unk_A0;
        func_800FE80C_CraneGame(m->unk_08.x, 100.0f, m->unk_08.z, 0);
    }
    func_80017DB0(obj);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CraneGame/1B3E00", func_800F82D4_CraneGame);
#endif
// register allocation and loop-invariant placement of the vertex table bases (masked 14)
#ifdef NON_MATCHING
s32 func_800F9464_CraneGame(omObjData* obj, Vec* out) {
    f32 m[4][4];
    f32 m2[4][4];
    Vec r;
    s32 cnt = 0;
    f32 tri[3][2] = { { -1.0f, -1.0f }, { 1.0f, 0.0f }, { -1.0f, 1.0f } };
    f32 quad[4][2] = { { -1.0f, -1.0f }, { 1.0f, -1.0f }, { -1.0f, 1.0f }, { 1.0f, 1.0f } };
    f32* p;
    CGWork* w;
    s32 i;
    s32 n;

    w = obj->unk_50;
    guRotateRPYF(m, obj->rot.x, obj->rot.y, obj->rot.z);
    MtxTranslate(m, 0.0f, 1.0f, 0.0f);
    r.x = -func_800B0CD8(sqrtf(m[3][0] * m[3][0] + m[3][2] * m[3][2]), m[3][1]);
    n = 4;
    r.y = -(func_800B0CD8(m[3][2], m[3][0]) + 90.0f);
    guTranslateF(m, obj->trans.x, obj->trans.y, obj->trans.z);
    MtxRotate(m, r.x, r.y, 0.0f);
    if (w->unk53 == 0) {
        n = 3;
    }
    for (i = 0; i < n; i++) {
        if (w->unk53 == 0) {
            p = tri[i];
        } else {
            p = quad[i];
        }
        guTranslateF(m2, 0.0f, p[0] * w->unk34, p[1] * w->unk38);
        guMtxCatF(m2, m, m2);
        if (m2[3][1] < 0.0f) {
            out[cnt].x = m2[3][0];
            out[cnt].y = m2[3][1];
            out[cnt].z = m2[3][2];
            cnt++;
        }
    }
    return cnt;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CraneGame/1B3E00", func_800F9464_CraneGame);
#endif
void func_800F96D8_CraneGame(s16 n, Vec* v) {
    s16 i;
    s16 j;
    f32 x;
    f32 y;
    f32 z;

    for (i = 0; i < n - 1; i++) {
        for (j = n - 1; j > i; j--) {
            if (v[i].y > v[j].y) {
                x = v[i].x;
                y = v[i].y;
                z = v[i].z;
                v[i].x = v[j].x;
                v[i].y = v[j].y;
                v[i].z = v[j].z;
                v[j].x = x;
                v[j].y = y;
                v[j].z = z;
            }
        }
    }
}


#ifndef NON_MATCHING
/* func_800F9464's contact-point templates (its local initialisers) for its INCLUDE_ASM. */
const f32 D_800FFB58_CraneGame[3][2] __attribute__((section(".rodata"))) = { { -1.0f, -1.0f }, { 1.0f, 0.0f }, { -1.0f, 1.0f } };
const f32 D_800FFB70_CraneGame[4][2] __attribute__((section(".rodata"))) = {
    { -1.0f, -1.0f }, { 1.0f, -1.0f }, { -1.0f, 1.0f }, { 1.0f, 1.0f }
};
#endif

// float register allocation: px/py swap f26/f30 (masked 0, raw 25; tried declaration order, if/else for the nudge, separate dx/dz at the end)
#ifdef NON_MATCHING
s16 func_800F97D4_CraneGame(omObjData* obj) {
    f32 m1[4][4];
    f32 m2[4][4];
    Vec rot;
    Vec pts[64];
    f32 py;
    f32 px;
    f32 pz;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 x;
    f32 y;
    f32 z;
    f32 len;
    f32 l;
    f32 nx;
    f32 ny;
    f32 nz;
    f32 a1;
    f32 a2;
    s32 n;
    s32 n2;

    n = func_800F9464_CraneGame(obj, pts);
    if (n != 0) {
        if (n >= 2) {
            func_800F96D8_CraneGame(n, pts);
            l = 0.0 - pts[1].y;
            obj->trans.y += l;
            pts[0].y += l;
        }
        if (obj->trans.y < 0.0) {
            l = 0.0 - pts[0].y;
            obj->trans.y += l;
            pts[0].y += l;
        } else {
            px = pts[0].x;
            py = pts[0].y;
            pz = pts[0].z;
            dx = obj->trans.x - px;
            dy = obj->trans.y - py;
            dz = obj->trans.z - pz;
            if (n == 1 && dx == 0.0 && dz == 0.0) {
                obj->trans.x = (obj->trans.x > 0.0f) ? obj->trans.x - 1.0 : obj->trans.x + 1.0;
            }
            len = sqrtf(dx * dx + dy * dy + dz * dz);
            x = obj->trans.x;
            y = obj->trans.y;
            z = obj->trans.z;
            l = 0.0 - py;
            obj->trans.y = l + y;
            py += l;
            dx = x - px;
            dy = y - py;
            dz = z - pz;
            l = sqrtf(dx * dx + dy * dy + dz * dz);
            if (l != 0.0) {
                nx = px + dx / l * len;
                ny = py + dy / l * len;
                nz = pz + dz / l * len;
                a1 = 90.0 - func_800B0CD8(py - obj->trans.y, sqrtf((px - obj->trans.x) * (px - obj->trans.x) +
                                                                  (pz - obj->trans.z) * (pz - obj->trans.z)));
                a2 = 90.0 - func_800B0CD8(py - ny, sqrtf((px - nx) * (px - nx) + (pz - nz) * (pz - nz)));
                a1 -= a2;
                obj->trans.x = nx;
                obj->trans.y = ny;
                obj->trans.z = nz;
                guRotateRPYF(m1, obj->rot.x, obj->rot.y, obj->rot.z);
                px -= obj->trans.x;
                pz -= obj->trans.z;
                l = sqrtf(px * px + pz * pz);
                if (l != 0.0) {
                    guRotateF(m2, -a1, pz / l, 0.0f, -(px / l));
                    guMtxCatF(m1, m2, m2);
                    func_800F9FAC_CraneGame(m2, &rot);
                    obj->rot.x = rot.x;
                    obj->rot.y = rot.y;
                    obj->rot.z = rot.z;
                }
            }
            n2 = func_800F9464_CraneGame(obj, pts);
            if (n2 != 0) {
                func_800F96D8_CraneGame(n2, pts);
                obj->trans.y -= pts[n2 - 1].y;
            }
        }
    }
    return n;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CraneGame/1B3E00", func_800F97D4_CraneGame);
#endif
void func_800F9C94_CraneGame(omObjData* obj) {
    f32 r;
    f32 r2;
    f32 dy;
    f32 rr;
    f32 lim;
    f32 dx;
    f32 dz;
    f32 d;
    f32 a;
    s16 i;
    omObjData* o;
    CGWork* ow;

    ow = obj->unk_50;
    if (ow->unk38 > ow->unk34) {
        r = ow->unk38;
    } else {
        r = ow->unk34;
    }
    for (i = 0; i < D_800EE984; i++) {
        o = D_800EDE70[i];
        ow = o->unk_50;
        if (obj == o) {
            continue;
        }
        if (ow->unk52 != 0) {
            continue;
        }
        if (ow->unkB4 != 0) {
            continue;
        }
        if (ow->unk38 > ow->unk34) {
            r2 = ow->unk38;
        } else {
            r2 = ow->unk34;
        }
        dy = fabsf(o->trans.y - obj->trans.y);
        rr = r + r2;
        if (dy < rr) {
            lim = func_800AEFD0(dy / rr * 90.0) * rr;
            dx = o->trans.x - obj->trans.x;
            dz = o->trans.z - obj->trans.z;
            d = sqrtf(dx * dx + dz * dz);
            if (d < lim) {
                if (d != 0.0) {
                    dx /= d;
                    dz /= d;
                } else {
                    a = (rand8() * 45) >> 5;
                    dx = func_800AEFD0(a);
                    dz = func_800AEAC0(a);
                }
                d = lim - d;
                obj->trans.x += -dx * d;
                obj->trans.z += -dz * d;
            }
        }
    }
}
f32 func_800F9EEC_CraneGame(f32 x, f32 z) {
    f32 a;

    if (x == 0.0 && z == 0.0) {
        a = 0.0f;
    } else {
        a = func_800B0CD8(z, x);
        if (a < 0.0) {
            a += 360.0;
        } else if (a >= 360.0) {
            a -= 360.0;
        }
    }
    return a;
}
void func_800F9FAC_CraneGame(f32 (*m)[4], Vec* out) {
    f32 s;
    f32 c;
    f64 t;

    out->x = func_800F9EEC_CraneGame(m[2][2], m[1][2]);
    out->z = func_800F9EEC_CraneGame(m[0][0], m[0][1]);
    s = -m[0][2];
    t = 1.0 - s * s;
    if (t < 0.0) {
        t = -t;
    }
    c = sqrtf(t);
    if (out->x > 90.0 && out->x < 270.0) {
        if (out->z > 90.0 && out->z < 270.0) {
            out->x += 180.0;
            if (out->x >= 360.0) {
                out->x -= 360.0;
            }
            out->z += 180.0;
            c = -c;
            if (out->z >= 360.0) {
                out->z -= 360.0;
            }
        }
    }
    out->y = func_800F9EEC_CraneGame(c, s);
}

void func_800FA154_CraneGame(omObjData* obj) {
    CGPrizeType types[9] = {
        { 2, 0, 0, 15, 14 }, { 3, 0, 0, 16, 12 }, { 4, 0, 0, 16, 12 },
        { 5, 0, 0, 16, 12 }, { 6, 0, 0, 17, 16 }, { 7, 0, 0, 19, 19 },
        { 9, 0, 1, 4, 15 },  { 8, 0, 0, 15, 18 }, { 10, 0, 1, 16, 10 },
    };
    CGWork* w;
    CGPrizeType* t;
    unk_ovl_2D_struct* p;
    s16 idx;

    w = func_80023684(sizeof(CGWork), 0x7918);
    obj->unk_50 = w;
    func_8009B770(w, 0, sizeof(CGWork));
    if (D_800FFE32_CraneGame < 3) {
        idx = GwPlayer[D_800FFE80_CraneGame[D_800FFE32_CraneGame]].character;
        w->unk56 = GwPlayer[D_800FFE80_CraneGame[D_800FFE32_CraneGame]].port;
        func_800FB800_CraneGame(D_800FFE80_CraneGame[D_800FFE32_CraneGame],
                                GwPlayer[D_800FFE80_CraneGame[D_800FFE32_CraneGame]].coins);
    } else {
        idx = D_800FFE32_CraneGame + 3;
    }
    t = &types[idx];
    obj->model[0] = func_800174C0(t->file | 0x360000, 0xA9);
    D_800F2B7C[obj->model[0]].unk_4C = 0.0f;
    p = &D_800F2B7C[obj->model[0]];
    p->unk_48 = D_800ED554[p->unk_08].unk_02;
    obj->func_ptr = func_800FA770_CraneGame;
    func_800093FC(obj,
                  ((f32)(s16)(D_800FFE72_CraneGame[D_800FFE32_CraneGame] % 3) * 40.0 + ((f32)(s32)((u32)(rand8() * 5) >> 6) + -10.0) - 45.0) * 10.0,
                  1500.0f,
                  ((f32)(s16)(D_800FFE72_CraneGame[D_800FFE32_CraneGame] / 3) * 50.0 + ((f32)(s32)((u32)(rand8() * 5) >> 6) + -10.0) - 45.0) * 10.0);
    obj->rot.x = (rand8() * 45) >> 5;
    obj->rot.y = (rand8() * 45) >> 5;
    obj->rot.z = (rand8() * 45) >> 5;
    func_8000941C(obj, 1.0f, 1.0f, 1.0f);
    w->unk53 = t->unk3;
    w->unk34 = t->unk4 * 10.0;
    w->unk38 = t->unk6 * 10.0;
    w->unk50 = 0;
    w->unk52 = 0;
    w->unk40 = 0.0f;
    w->unk3C = -1.0f;
    w->unkAE = 1;
    w->unkB0 = 0;
    w->unkAC = 0;
    w->unkB4 = D_800FFE32_CraneGame * 8 + 30;
    func_800FD37C_CraneGame(obj->model[0]);
    func_800FB9C4_CraneGame(obj->model[0]);
    obj->work[0] = (u8)D_800FFE32_CraneGame;
    obj->work[1] = 0;
    obj->work[2] = 0;
    obj->work[3] = 0;
    D_800FFE32_CraneGame++;
}
void func_800FA684_CraneGame(omObjData* obj, s16 arg1) {
    f32 m1[4][4];
    f32 m2[4][4];
    Vec rot;

    guRotateRPYF(m1, obj->rot.x, obj->rot.y, obj->rot.z);
    guRotateF(m2, func_800AEAC0((f32)obj->work[2] * 11.25) * (2.0 * arg1), 1.0f, 0.0f, 0.0f);
    guMtxCatF(m1, m2, m2);
    func_800F9FAC_CraneGame(m2, &rot);
    obj->rot.x = rot.x;
    obj->rot.y = rot.y;
    obj->rot.z = rot.z;
    obj->work[2] = (obj->work[2] + 1) & 0x1F;
}
void func_800FA770_CraneGame(omObjData* obj) {
    f32 temp_f4;
    s16 temp_a0;
    s32 var_s2;
    s8 var_s3;
    int new_var;
    unk2C0C0StructC0* temp_v1_3;
    CGWork* temp_s1;
    CGClaw* temp_s4;

    temp_s1 = obj->unk_50;
    var_s3 = 0;
    
    temp_s4 = func_800F71B8_CraneGame(*D_800F3FB0);
    if ((obj->work[0] < 3U) && (D_800FFE28_CraneGame == 0)) {
        
        if (!(GwPlayer[D_800FFE80_CraneGame[obj->work[0]]].flags & 1)) {
            var_s2 = ContBtnTrg[temp_s1->unk56];
        } else {
            var_s2 = 0;
            if ((rand8() & 0xFF) < ((GwPlayer[D_800FFE80_CraneGame[obj->work[0]]].cpu_difficulty) * 8 + 56) ) {
                new_var = 0x8000; //TODO: ?
                var_s2 = new_var;
            }
        }
        if (var_s2 & 0x8000) {
            var_s3 = 1;
        }
        if (var_s3 != 0) {
            if (D_800F2B7C[obj->model[0]].unk_48 == D_800ED554[D_800F2B7C[obj->model[0]].unk_08].unk_02) {
                D_800F2B7C[obj->model[0]].unk_4C = 1.0f;
                D_800F2B7C[*obj->model].unk_48 = 0.0f;
            }
        }
    }
    switch (temp_s1->unk50) {
    case 0:
        if (((func_8005FD5C()) + D_800F64F8) == 0) {
            temp_s1->unkB4--;
            if (temp_s1->unkB4 == 0) {
                temp_s1->unk50++;
                return;
            }
        }
        return;
    case 1:
        if (((func_8005FD5C()) + D_800F64F8) == 0) {
            temp_f4 = obj->trans.y;
            temp_s1->unk40 += -4.0;
            obj->trans.y += temp_s1->unk40;
            if (temp_s1->unk52 == 0) {
                if (func_800F97D4_CraneGame(obj) != 0) {
                    temp_s1->unk40 = -16.0f;
                    if (temp_s1->unkAE != 0) {
                        temp_s1->unkAE = 0;
                        PlaySound(0x2C8);
                        if (obj->work[1] != 0) {
                            temp_s1->unk50 = -1;
                            D_800FFE2C_CraneGame = 1;
                        }
                    }
                } else {
                    temp_s1->unkAE = 1;
                }
            } else {
                if (obj->trans.y < 300.0) {
                    temp_v1_3 = D_800F2B7C[D_800FFE70_CraneGame].unk_6C;
                    if (obj->trans.x != temp_v1_3->unk_A0->unk_08.x) {
                        if (temp_v1_3->unk_A0->unk_08.x < obj->trans.x) {
                            obj->trans.x -= 20.0;
                            if (obj->trans.x < temp_v1_3->unk_A0->unk_08.x) {
                                obj->trans.x = temp_v1_3->unk_A0->unk_08.x;
                            }
                        } else {
                            obj->trans.x += 20.0;
                            if (temp_v1_3->unk_A0->unk_08.x < obj->trans.x) {
                                obj->trans.x = temp_v1_3->unk_A0->unk_08.x;
                            }
                        }
                    }
                    if (obj->trans.z != temp_v1_3->unk_A0->unk_08.z) {
                        if (temp_v1_3->unk_A0->unk_08.z < obj->trans.z) {
                            obj->trans.z -= 20.0;
                            if (obj->trans.z < temp_v1_3->unk_A0->unk_08.z) {
                                obj->trans.z = temp_v1_3->unk_A0->unk_08.z;
                            }
                        } else {
                            obj->trans.z += 20.0;
                            if (temp_v1_3->unk_A0->unk_08.z < obj->trans.z) {
                                obj->trans.z = temp_v1_3->unk_A0->unk_08.z;
                            }
                        }
                    }
                }

                if ((temp_f4 >= 300.0) && (obj->trans.y < 300.0)) {
                    PlaySound(0x2C9);
                    func_80060F04(D_800FFE7E_CraneGame, 20, 0, 20);
                    switch (obj->work[0]) {
                    default: //captured a player
                        temp_a0 = GwPlayer[D_800FFE80_CraneGame[obj->work[0]]].coins / 3;
                        GwPlayer[D_800FFE7E_CraneGame].coins_mg = temp_a0 + GwPlayer[D_800FFE7E_CraneGame].coins_mg;
                        GwPlayer[D_800FFE80_CraneGame[obj->work[0]]].coins_mg = GwPlayer[D_800FFE80_CraneGame[obj->work[0]]].coins_mg - temp_a0;
                        D_800FF510_CraneGame[D_800FFE80_CraneGame[obj->work[0]]] += GwPlayer[D_800FFE80_CraneGame[obj->work[0]]].coins_mg;
                        break;
                    case 3: //captured single coin
                        GwPlayer[D_800FFE7E_CraneGame].coins_mg += 1;
                        break;
                    case 4: //captured money bag
                        GwPlayer[D_800FFE7E_CraneGame].coins_mg += 5;
                        break;
                    case 5: //captured treasure chest
                        GwPlayer[D_800FFE7E_CraneGame].coins_mg += 10;
                        break;
                    }
                    if (D_800FFE34_CraneGame == 0) {
                        D_800FF510_CraneGame[D_800FFE7E_CraneGame] += GwPlayer[D_800FFE7E_CraneGame].coins_mg;
                    }
                }
                if (obj->trans.y < -2000.0) {
                    temp_s1->unk50 = -1;
                    D_800FFE2C_CraneGame = 1; //ends the game
                    D_800FFE2A_CraneGame = 1;
                }
            }
        }
        if ((temp_s1->unk52 != 0) && ((func_800F7290_CraneGame(obj->trans.y)) != 0)) {
            func_800FBA78_CraneGame(D_800FFE70_CraneGame, 0);
        }
        func_800F9C94_CraneGame(obj);
        
        if (temp_s1->unk34 > temp_s1->unk38) {
            temp_f4 = temp_s1->unk34;
        } else {
            temp_f4 = temp_s1->unk38;
        }
        func_800F746C_CraneGame(&obj->trans.x, &obj->trans.y, &obj->trans.z, 0.0f, 0, 0, temp_f4, temp_s1->unk52 + 1);
        return;
    case 2:
        if (((func_8005FD5C()) + D_800F64F8) == 0) {
            if (obj->work[1] != 0) {
                temp_s1->unk50 = 1;
                temp_s1->unk52 = func_800F71E4_CraneGame(obj);
                temp_s1->unk40 = 0.0f;
                return;
            }
            func_800FBA78_CraneGame(obj->model[0], 0);
            //unsure what's up with the needed s16 casting
            if (var_s3 != 0) {
                temp_s1->unkB0 = 30 / (s16)D_800FF550_CraneGame[temp_s4->unk40];
                func_80060F04(D_800FFE7E_CraneGame, 5, 0, 5);
            } else {
                temp_s1->unkB0--;
            }
            if (temp_s1->unkB0 <= 0) {
                temp_s1->unkB0 = 30 / (s16)D_800FF550_CraneGame[temp_s4->unk40];
                temp_s1->unkAC = 0;
            } else {
                temp_s1->unkAC++;
                if (temp_s1->unkAC >= 30) {
                    temp_s1->unkB0 = 30 / (s16)D_800FF550_CraneGame[temp_s4->unk40];
                    temp_s1->unkAC = 0;
                    obj->work[1] = 1;
                }
            }
            func_800FA684_CraneGame(obj, temp_s4->unk40);
        }
        break;
    }
}

void func_800FB08C_CraneGame(omObjData* obj) {
    s16 pos1[4][2] = { { 0x38, 0x18 }, { 0x108, 0x18 }, { 0x38, 0xCA }, { 0x108, 0xCA } };
    s16 pos2[4][2] = { { 0x27, 0x26 }, { 0xF7, 0x26 }, { 0x27, 0xD8 }, { 0xF7, 0xD8 } };
    s16 i;
    s16 j;
    s16 spr;

    for (i = 0; i < 4; i++) {
        spr = InitSprite(GwPlayer[i].character + 0x6E);
        D_800FFEA8_CraneGame[i] = func_80019060(spr, 0, 1);
        SetBasicSpritePos(D_800FFEA8_CraneGame[i], pos1[i][0], pos1[i][1]);
    }
    spr = InitSprite(0x74);
    for (j = 0; j < 4; j++) {
        D_800FFEB0_CraneGame[j] = func_80019060(spr, 0, 1);
        SetBasicSpritePos(D_800FFEB0_CraneGame[j], pos2[j][0], pos2[j][1]);
    }
    spr = InitSprite(0x87);
    for (j = 0; j < 4; j++) {
        D_800FFE90_CraneGame[j][0] = func_80019060(spr, 0, 1);
        SetBasicSpritePos(D_800FFE90_CraneGame[j][0], D_800FF500_CraneGame[j][0], D_800FF500_CraneGame[j][1]);
        D_800FFE90_CraneGame[j][1] = func_80019060(spr, 0, 1);
        SetBasicSpritePos(D_800FFE90_CraneGame[j][1], D_800FF500_CraneGame[j][0] + 12, D_800FF500_CraneGame[j][1]);
        D_800FFE90_CraneGame[j][2] = func_80019060(spr, 0, 1);
        SetBasicSpritePos(D_800FFE90_CraneGame[j][2], D_800FF500_CraneGame[j][0] + 24, D_800FF500_CraneGame[j][1]);
    }
    D_800FFEB8_CraneGame = obj;
    obj->work[1] = 0;
    obj->func_ptr = func_800FB3A8_CraneGame;
    func_800FB73C_CraneGame();
}
void func_800FB3A8_CraneGame(omObjData* obj) {
    s32 i;
    s32 v;
    s32 d;
    s32 x;

    switch (obj->work[1]) {
    case 0:
        break;
    case 1:
        for (i = 0; i < 4; i++) {
            v = D_800FF510_CraneGame[i];
            if (v >= 1000) {
                v = 999;
            }
            x = 0;
            ShowBasicSprite(D_800FFE90_CraneGame[i][2]);
            d = v / 100;
            if (d == 0) {
                func_80018C90(D_800FFE90_CraneGame[i][2]);
            }
            func_80018E0C(D_800FFE90_CraneGame[i][2], d);
            SetBasicSpritePos(D_800FFE90_CraneGame[i][2], D_800FF500_CraneGame[i][0] + x, D_800FF500_CraneGame[i][1]);
            if (d != 0) {
                x += 12;
            }
            ShowBasicSprite(D_800FFE90_CraneGame[i][1]);
            d = v % 100 / 10;
            if (d == 0 && v / 100 == 0) {
                func_80018C90(D_800FFE90_CraneGame[i][1]);
            }
            func_80018E0C(D_800FFE90_CraneGame[i][1], d);
            SetBasicSpritePos(D_800FFE90_CraneGame[i][1], D_800FF500_CraneGame[i][0] + x, D_800FF500_CraneGame[i][1]);
            if (d != 0 || v / 100 != 0) {
                x += 12;
            }
            func_80018E0C(D_800FFE90_CraneGame[i][0], v % 10);
            SetBasicSpritePos(D_800FFE90_CraneGame[i][0], D_800FF500_CraneGame[i][0] + x, D_800FF500_CraneGame[i][1]);
        }
        break;
    }
}
void func_800FB674_CraneGame(void) {
    s32 i;

    D_800FFEB8_CraneGame->work[1] = 1;
    for (i = 0; i < MAX_PLAYERS; i++) {
        ShowBasicSprite(D_800FFE90_CraneGame[i][0]);
        ShowBasicSprite(D_800FFE90_CraneGame[i][1]);
        ShowBasicSprite(D_800FFE90_CraneGame[i][2]);
        ShowBasicSprite(D_800FFEA8_CraneGame[i]);
        ShowBasicSprite(D_800FFEB0_CraneGame[i]);        
    }
}

void func_800FB73C_CraneGame(void) {
    s32 i;

    D_800FFEB8_CraneGame->work[1] = 0;
    for (i = 0; i < MAX_PLAYERS; i++) {
        func_80018C90(D_800FFE90_CraneGame[i][0]);
        func_80018C90(D_800FFE90_CraneGame[i][1]);
        func_80018C90(D_800FFE90_CraneGame[i][2]);
        func_80018C90(D_800FFEA8_CraneGame[i]);
        func_80018C90(D_800FFEB0_CraneGame[i]);        
    }
}

void func_800FB800_CraneGame(s32 arg0, s32 arg1) {
    s32 var_a1;

    var_a1 = (arg1 >= 0) ? arg1 : 0;
    if (var_a1 > 999) {
        var_a1 = 999;
    }
    D_800FF510_CraneGame[arg0] = var_a1;
}


