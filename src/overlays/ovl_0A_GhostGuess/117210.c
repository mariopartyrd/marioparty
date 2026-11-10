#include "common.h"
#include "GhostGuess.h"

/* .data (0x800FB670..0x800FB710) */
s32 D_800FB670_GhostGuess = 0;
f32 D_800FB674_GhostGuess = 362.5f;
s32 D_800FB678_GhostGuess = 0;
s32 D_800FB67C_GhostGuess[8] = { 0 };
s32 D_800FB69C_GhostGuess = 0;
s32 D_800FB6A0_GhostGuess = 0;
s32 D_800FB6A4_GhostGuess = 0;
s32 D_800FB6A8_GhostGuess = 1;
s32 D_800FB6AC_GhostGuess = 0;
f32 D_800FB6B0_GhostGuess[4] = { 0.8f, 0.9f, 1.2f, 1.5f };
f32 D_800FB6C0_GhostGuess[4] = { 5.625f, 5.0f, 4.0f, 3.0f };
s32 D_800FB6D0_GhostGuess = 0;
s32 D_800FB6D4_GhostGuess = 10;
s16 D_800FB6D8_GhostGuess[2] = { 1, 2 };
s32 D_800FB6DC_GhostGuess = 60;
s32 D_800FB6E0_GhostGuess = 0;
s32 D_800FB6E4_GhostGuess = 0;
s32 D_800FB6E8_GhostGuess = 0;
s32 D_800FB6EC_GhostGuess = 0;
s32 D_800FB6F0_GhostGuess = 0;
f32 D_800FB6F4_GhostGuess = 0.0f;
f32 D_800FB6F8_GhostGuess = 1.47f;
f32 D_800FB6FC_GhostGuess = 0.0f;
f32 D_800FB700_GhostGuess = 0.0f;
s32 D_800FB704_GhostGuess = 50;
s32 D_800FB708_GhostGuess = 0;

void func_800F65E0_GhostGuess(void) {
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
    func_8001D494(0, 45.0f, 80.0f, 8000.0f);
    D_800FBC10_GhostGuess = 0;
    D_800FBC12_GhostGuess = 3600;
    D_800ED430 = 1;
    for (i = 0; i < 4; i++) {
        if (GwPlayer[i].group == 0) {
            break;
        }
    }
    D_800FBC08_GhostGuess = i;
    D_800B895C = 15.0f;
    D_800B8960 = 0.5f;
    D_800B8964 = 1.47f;
    D_800B8968 = 0.15f;
    D_800B896C = 7.0f;
    D_800B8970 = 30.0f;
    D_800B897C = 3.3333333f;
    D_800B8980 = 18.0f;
    D_800B8984 = 13.5f;
    D_800B8988 = 9.0f;
    D_800B898C = 4.5f;
    D_800B8990 = 0.0f;
    D_800B8994 = 1.7f;
    D_800B8998 = 0.5f;
    D_800B899C = 0.147f;
    D_800FB678_GhostGuess = _CheckFlag(0x2B);
    D_800FB6AC_GhostGuess = GwPlayer[D_800FBC08_GhostGuess].cpu_difficulty;
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    func_800090B8(0);
    D_800FBBE0_GhostGuess = omAddObj(1, 0, 0, -1, func_800F69DC_GhostGuess);
    D_800F2AF8[D_800ED440++] = omAddObj(2, 1, 0, -1, func_800F6AE0_GhostGuess);
    D_800FBBE8_GhostGuess = omAddObj(5, 4, 0, -1, &func_800F6BA4_GhostGuess);
    D_800FBBE4_GhostGuess = D_800F3FB0[D_800F2BC0++] = omAddObj(3, 9, 0x3C, -1, &func_800F6FF4_GhostGuess);
    omAddObj(4, 1, 0, -1, &func_800F6E78_GhostGuess);
    D_800FBBEC_GhostGuess = omAddObj(2, 0, 0, -1, &func_800F73E0_GhostGuess);
}
void func_800F69DC_GhostGuess(omObjData* arg0) {
    s32 temp_s1;
    void* temp_s0;

    arg0->func_ptr = &func_800F79D4_GhostGuess;
    temp_s0 = DataRead(0x1C000A);
    temp_s1 = func_800678A4(temp_s0);
    DataClose(temp_s0);
    D_800FBEC0_GhostGuess = func_80064EF4(1, 0);
    func_80067208(D_800FBEC0_GhostGuess, 0, temp_s1, 0);
    func_800674BC(D_800FBEC0_GhostGuess, 0, 0x9000);
    func_80067354(D_800FBEC0_GhostGuess, 0, 1.0f, 1.0f);
    func_80066DC4(D_800FBEC0_GhostGuess, 0, 160, 120);
    func_800FB3B0_GhostGuess();
}

void func_800F6AAC_GhostGuess(void) {
    if (func_80072718() == 0) {
        func_800FB21C_GhostGuess();
        omOvlReturnEx(1);
    }
}

void func_800F6AE0_GhostGuess(omObjData* arg0) {
    unkGlobalStruct_02* temp_s0;

    arg0->func_ptr = NULL;
    arg0->trans.x = arg0->trans.y = arg0->trans.z = 0.0f;
    arg0->scale.x = arg0->scale.y = arg0->scale.z = 5.0f;
    arg0->model[0] = func_800174C0(0x1C0000, 0x2DD);
    temp_s0 = func_80023684(sizeof(unkGlobalStruct_02), 31000);
    arg0->unk_50 = temp_s0;
    func_8009B770(temp_s0, 0, sizeof(unkGlobalStruct_02));
    temp_s0->unk_04 = 1;
    temp_s0->unk_05 = 0;
    func_80009000(arg0, 4, 1.0f);
    func_80008FC4(arg0, 20.0f);
    func_80008FB8(arg0, 1.0f);
}

void func_800F6BA4_GhostGuess(omObjData* arg0) {
    unkGlobalStruct_02* work;
    s16 i;

    arg0->func_ptr = NULL;
    arg0->trans.x = arg0->trans.y = arg0->trans.z = 0.0f;
    arg0->scale.x = arg0->scale.y = arg0->scale.z = 1.0f;
    for (i = 0; i < 2; i++) {
        arg0->model[i] = func_800174C0(D_800FB6D8_GhostGuess[i] | 0x1C0000, 0x2D9);
        func_80025798(arg0->model[i], arg0->trans.x, arg0->trans.y, arg0->trans.z);
        func_80025830(arg0->model[i], arg0->scale.x, arg0->scale.y, arg0->scale.z);
    }
    func_80025EB4(arg0->model[1], 2, 2);
    D_800F2B7C[arg0->model[1]].unk_4C = 0.2f;
    arg0->model[2] = func_80023FC8(arg0->model[1]);
    func_80025EB4(arg0->model[2], 2, 2);
    D_800F2B7C[arg0->model[2]].unk_4C = 0.2f;
    func_800257E4(arg0->model[2], 0.0f, 180.0f, 0.0f);
    func_80025CA8(arg0->model[2], func_80025D40(arg0->model[1]) * 0.66);
    arg0->model[3] = func_80023FC8(arg0->model[1]);
    func_80025EB4(arg0->model[3], 2, 2);
    D_800F2B7C[arg0->model[3]].unk_4C = 0.2f;
    func_80025CA8(arg0->model[3], func_80025D40(arg0->model[1]) * 0.33);
    work = func_80023684(sizeof(unkGlobalStruct_02), 31000);
    arg0->unk_50 = work;
    func_8009B770(work, 0, sizeof(unkGlobalStruct_02));
    work->unk_04 = 1;
    work->unk_05 = 0;
    D_800EE9A0.def[0].col[0] = D_800EE9A0.def[0].col[1] = D_800EE9A0.def[0].col[2] = 0;
    D_800EE9A0.def[1].col[0] = D_800EE9A0.def[1].col[1] = D_800EE9A0.def[1].col[2] = 0xC0;
    D_800EE9A0.def[1].dir[0] = 1;
    D_800EE9A0.def[1].dir[1] = 0x40;
    D_800EE9A0.def[1].dir[2] = 0x40;
    SetFadeInTypeAndTime(0, 0x10);
}
// decomp-permuter
void func_800F6E78_GhostGuess(omObjData *arg0)
{
  GGRec *r;
  s32 i;
  D_800FBEDC_GhostGuess = arg0;
  D_800FBEDA_GhostGuess = 1;
  D_800FBED2_GhostGuess = 0;
  arg0->func_ptr = &func_800F80E4_GhostGuess;
  arg0->scale.x = (arg0->scale.y = (arg0->scale.z = 1.5f));
  arg0->model[0] = func_800174C0(0x180006, 0x9D);
  D_800F2B7C[arg0->model[0]].unk_4C = 0.0f;
  D_800FBF10_GhostGuess = ReadImgPackand(0x21, 0x284, 8);
  for (i = 1; i < 11; i++)
  {
    if (i)
    {
      r = &D_800FBED0_GhostGuess[i];
      r->unk_40 = D_800ECDE0[func_8001E1D0(D_800FBED0_GhostGuess[0].unk_40, 8)].unk_00;
      func_80025930(r->unk_40, 0x70000000, 0x70000000);
      r->unk_0A = 1;
      r->unk_08 = 0;
      r->unk_02 = 0;
      r->scale.x = (r->scale.y = (r->scale.z = 3.0f));
      func_80025830(r->unk_40, r->scale.x, r->scale.y, r->scale.z);
    }
    else
    {
      r = &D_800FBED0_GhostGuess[i];
      r->unk_40 = D_800ECDE0[func_8001E1D0(D_800FBED0_GhostGuess[0].unk_40, 8)].unk_00;
      func_80025930(r->unk_40, 0x70000000, 0x70000000);
      r->unk_0A = 1;
      r->unk_08 = 0;
      r->unk_02 = 0;
      r->scale.x = (r->scale.y = (r->scale.z = 3.0f));
      func_80025830(r->unk_40, r->scale.x, r->scale.y, r->scale.z);
    }
  }

}
void func_800F6FF4_GhostGuess(omObjData* arg0) {
    s32 idle[5] = { 0x0F, 0x38, 0x39, 0x3A, 0x3B };
    s32 dir;
    s32 file1;
    u8 chr;

    chr = GwPlayer[D_800FBC08_GhostGuess].character;
    dir = D_800C59AC[chr].unk_00;
    file1 = D_800C59AC[chr].unk_08;
    func_8000979C(arg0, dir, file1, (s16)D_800FBC08_GhostGuess, 0x6D9, 0x6D9);
    arg0->func_ptr = &func_800F8888_GhostGuess;
    arg0->work[0] = arg0->work[1] = arg0->work[2] = 0;
    arg0->work[3] = 0x2D;
    ((unkGlobalStruct_00*)arg0->unk_50)->unk_DC = &func_800F86CC_GhostGuess;
    arg0->model[3] = LoadFormFile(0x19, 0x68D);
    arg0->model[4] = LoadFormFile(0x1A, 0x68D);
    arg0->model[6] = LoadFormFile(0x1B, 0x68D);
    arg0->model[5] = LoadFormFile(0x1C, 0x68D);
    arg0->model[7] = LoadFormFile(0x1E, 0x68D);
    arg0->model[8] = LoadFormFile(0x1D, 0x68D);
    func_800187D0(arg0, 0, dir, 1, 0);
    func_800187D0(arg0, 1, dir | 1, 1, 0);
    func_800187D0(arg0, 2, dir | 3, 1, 0);
    func_800187D0(arg0, 5, dir | 4, 0, 0);
    func_800187D0(arg0, 6, dir | 5, 1, 0x13);
    func_800187D0(arg0, 7, dir | 6, 1, 0x22);
    func_800187D0(arg0, 8, dir | 9, 1, 0x1D);
    func_800187D0(arg0, 9, dir | 0xA, 1, 0x27);
    func_8001874C(arg0, 0xD, dir | idle[rand8() & 1], 1, 0x78);
    func_800187D0(arg0, 0x11, dir | 0x18, 0, 0);
    func_800187D0(arg0, 0x12, dir | 0x1C, 2, 0);
    func_800187D0(arg0, 0x13, dir | 0x1D, 2, 0);
    func_800187D0(arg0, 0xA, dir | 0x1E, 1, 0x27);
    func_8001874C(arg0, 3, dir | 0x60, 1, 0);
    func_8001874C(arg0, 4, dir | 0x61, 1, 0);
    func_8001874C(arg0, 0x15, dir | 0x62, 0, 0);
    func_8001874C(arg0, 0x1E, dir | 0x63, 0, 0);
    func_8001874C(arg0, 0x1F, dir | 0x64, 0, 0);
    func_8001874C(arg0, 0x20, dir | 0x67, 0, 0);
    func_8001874C(arg0, 0x21, dir | 0x68, 2, 0);
    func_8001874C(arg0, 0x22, dir | 0x69, 2, 0);
    func_8001874C(arg0, 0x23, dir | 0x93, 1, 0);
    func_800093FC(arg0, 0.0f, 0.0f, 0.0f);
    omSetTra(arg0, 0.0f, 0.0f, 0.0f);
    func_800090C4(arg0, 0, 2);
}
void func_800F73E0_GhostGuess(omObjData* arg0) {
    GGGhost* g;
    omObjData* obj;
    void* file;
    f64 angle;
    f32 a;
    f32 r;
    s32 ghostSpr;
    s32 spr1;
    s32 spr2;
    s32 i;

    D_800FBBF0_GhostGuess[0] = LoadFormFile(0x1C0004, 0x6DD);
    D_800FBBF0_GhostGuess[1] = LoadFormFile(0x1C0005, 0x6DD);
    D_800FBBF0_GhostGuess[2] = LoadFormFile(0x1C0006, 0x6DD);
    D_800FBBF0_GhostGuess[3] = LoadFormFile(0x1C0003, 0x6DD);
    D_800FBC00_GhostGuess = LoadFormFile(0x1C0007, 0x25D);
    D_800FBC04_GhostGuess = LoadFormFile(0x1C0008, 0x25D);
    file = DataRead(0x1C0009);
    ghostSpr = func_800678A4(file);
    DataClose(file);
    D_800FBEB8_GhostGuess = func_80064EF4(8, 0);
    file = DataRead(0x21);
    spr1 = func_800678A4(file);
    DataClose(file);
    file = DataRead(0x2A);
    spr2 = func_800678A4(file);
    DataClose(file);
    D_800FBEBC_GhostGuess = func_80064EF4(2, 0);
    func_80067208((s16)D_800FBEBC_GhostGuess, 0, spr1, 0);
    func_800674BC((s16)D_800FBEBC_GhostGuess, 0, 0x9000);
    func_800672B0((s16)D_800FBEBC_GhostGuess, 0, 1);
    for (i = 1; i < 2; i++) {
        func_80067208((s16)D_800FBEBC_GhostGuess, i, spr2, 0);
        func_800674BC((s16)D_800FBEBC_GhostGuess, i, 0x9000);
        func_800672B0((s16)D_800FBEBC_GhostGuess, i, 0);
        func_800674F4((s16)D_800FBEBC_GhostGuess, (s16)i, 0xFF, 0xFF, 0xBE);
    }
    arg0->func_ptr = &func_800F948C_GhostGuess;
    D_800FB69C_GhostGuess = rand8() & 7;
    for (i = 0; i < 8; i++) {
        g = &D_800FBC18_GhostGuess[i];
        if (i == D_800FB69C_GhostGuess) {
            g->unk_04 = 1;
        } else {
            g->unk_04 = 0;
        }
        g->unk_05 = i;
        angle = i * 45.0;
        a = angle;
        g->pos.x = func_800AEAC0(a) * D_800FB674_GhostGuess;
        g->pos.y = -200.0f;
        g->pos.z = func_800AEFD0(a) * D_800FB674_GhostGuess;
        g->rot.x = g->rot.z = 0.0f;
        g->rot.y = g->unk_44 = r = func_8009B618(angle + 180.0, 360.0);
        if (r <= 90.0 || r >= 270.0) {
            g->rot.y = 0.0f;
        }
        g->rot.x = 6.0f;
        g->scale.x = g->scale.y = g->scale.z = 1.0f;
        g->unk_34.x = g->unk_34.y = g->unk_34.z = 0.0f;
        g->unk_4C = 0.05f;
        g->unk_48 = g->unk_50 = 0.0001f;
        g->unk_06 = 1;
        g->unk_08 = 0;
        g->unk_0A = 0;
        obj = omAddObj(4, 1, 0, -1, &func_800F789C_GhostGuess);
        D_800EDE70[D_800EE984++] = obj;
        GG_GHOST_SET(obj, g);
        func_80067208((s16)D_800FBEB8_GhostGuess, i, ghostSpr, 0);
        func_800674BC((s16)D_800FBEB8_GhostGuess, i, 0x9000);
        func_800672B0((s16)D_800FBEB8_GhostGuess, i, 0);
        func_80067558((s16)D_800FBEB8_GhostGuess, (s16)i, 0xFF, 0xFF, 0xFF, 0xFF);
    }
}
void func_800F789C_GhostGuess(omObjData* arg0) {
    GGGhost* g;
    GGGhostWork* work;

    arg0->func_ptr = &func_800FA764_GhostGuess;
    g = GG_GHOST(arg0);
    omSetTra(arg0, g->pos.x, g->pos.y, g->pos.z);
    omSetRot(arg0, g->rot.x, g->rot.y, g->rot.z);
    g->obj = arg0;
    arg0->model[0] = func_80023FC8((s16)D_800FBBF0_GhostGuess[3]);
    arg0->model[1] = func_80023FC8((s16)D_800FBC00_GhostGuess);
    func_800258EC(arg0->model[0], 4, 0);
    func_800258EC(arg0->model[1], 4, 0);
    func_80025830(arg0->model[1], 0.001f, 0.001f, 0.001f);
    work = func_80023684(sizeof(GGGhostWork), 0x7918);
    arg0->unk_50 = work;
    work->unk_44 = 0.1f;
    work->unk_48 = 90.0f;
    work->unk_34 = 20.0f;
    work->unk_3C = 0.0f;
    work->unk_5C = 0;
    work->unk_52 = 7;
    work->unk_60 = 0.0f;
    work->unk_50 = 0;
    work->unk_54 = 1;
}

void func_800F79D4_GhostGuess(omObjData* arg0) {
    s32 voice[6] = { 0x451, 0x452, 0x453, 0x454, 0x455, 0x456 };
    omObjData* player;
    s32 i;

    D_800FBC0C_GhostGuess = (D_800FBC0C_GhostGuess + 1) % 3;
    player = D_800FBBE4_GhostGuess;
    if (D_800F5144 == 1) {
        D_800FBC10_GhostGuess = -1;
        for (i = 0; i < 8; i++) {
            func_8006071C((s16)D_800FB67C_GhostGuess[i]);
        }
        func_800601D4(0x3C);
        arg0->func_ptr = func_800F6AAC_GhostGuess;
    }
    switch (D_800FB670_GhostGuess) {
    case 0:
        if (D_800FB6DC_GhostGuess == 0) {
            func_800FB448_GhostGuess(1625.0f, 0.0f, 0.0f, -145.0f, -30.0f, 0.0f, 0.0f, 45);
            D_800FB670_GhostGuess = 1;
            func_80060540(0x222, 0);
            D_800FB6DC_GhostGuess = 30;
            func_8006035C((s16)D_800FB6EC_GhostGuess, 0x74);
        } else {
            if (D_800FB6DC_GhostGuess == 60) {
                D_800FB6EC_GhostGuess = (s16)PlaySound(0x227);
            }
            D_800FB6DC_GhostGuess--;
        }
        break;
    case 2:
        if (--D_800FB6DC_GhostGuess == 0) {
            D_800FB670_GhostGuess = 3;
        }
        break;
    case 3:
        if (D_800FB6DC_GhostGuess == 0) {
            GMesCreate(0);
            func_80060398(0x3C);
        } else if (GMesStatAllGet() == 0) {
            func_80060128(0x20);
            D_800FB670_GhostGuess = 4;
            D_800FB6DC_GhostGuess = -1;
        }
        D_800FB6DC_GhostGuess++;
        break;
    case 4:
        D_800FB674_GhostGuess -= 0.3;
        break;
    case 7:
        if (D_800FB678_GhostGuess == 0) {
            D_800FB670_GhostGuess = 17;
        } else {
            D_800FB670_GhostGuess = 16;
        }
        break;
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 17:
        if (ContBtnTrg[GwPlayer[D_800FBC08_GhostGuess].port] & 0x9000) {
            D_800FB6E8_GhostGuess = 1;
        }
        if (D_800FB6D0_GhostGuess != 0) {
            if (D_800FB6E0_GhostGuess == 0) {
                GwPlayer[D_800FBC08_GhostGuess].coins_mg += 10;
            } else if (D_800FB6E0_GhostGuess == 10) {
                GMesCreate(2);
            } else if (D_800FB6E0_GhostGuess >= 11 && D_800FB6E4_GhostGuess == 0) {
                if (GMesStatAllGet() & 2) {
                    func_800FB448_GhostGuess(300.0f, player->trans.x, 100.0f, player->trans.z, 0.0f, 0.0f, 0.0f, 27);
                    func_800184BC(player, 0xD);
                    func_80060128(0x33);
                    D_800FB6E4_GhostGuess = D_800FB6E0_GhostGuess;
                }
            } else if (D_800FB6E0_GhostGuess == D_800FB6E4_GhostGuess + 36) {
                func_80060540(voice[GwPlayer[D_800FBC08_GhostGuess].character], 0);
            } else if (D_800FB6E0_GhostGuess == D_800FB6E4_GhostGuess + 93) {
                D_800FB670_GhostGuess = 18;
            } else if (D_800FB6E0_GhostGuess >= D_800FB6E4_GhostGuess + 60 && D_800FB6E8_GhostGuess != 0) {
                D_800FB670_GhostGuess = 18;
            }
        } else if (D_800FB6E0_GhostGuess == 0) {
            GMesCreate(0xE);
            GwPlayer[D_800FBC08_GhostGuess].coins_mg -= 5;
        } else if (D_800FB6E0_GhostGuess > 0 && D_800FB6E4_GhostGuess == 0) {
            if (GMesStatAllGet() & 2) {
                func_80060128(0x34);
                D_800FB6E4_GhostGuess = D_800FB6E0_GhostGuess;
            }
        } else if (D_800FB6E0_GhostGuess == D_800FB6E4_GhostGuess + 90) {
            D_800FB670_GhostGuess = 18;
        } else if (D_800FB6E0_GhostGuess >= D_800FB6E4_GhostGuess + 60 && D_800FB6E8_GhostGuess != 0) {
            D_800FB670_GhostGuess = 18;
        }
        D_800FB6E0_GhostGuess++;
        break;
    case 16:
        if (D_800FB6E0_GhostGuess == 0) {
            GMesCreate(2);
            if (D_800FB6D0_GhostGuess != 0) {
                GwPlayer[D_800FBC08_GhostGuess].coins_mg += 10;
            } else {
                GwPlayer[D_800FBC08_GhostGuess].coins_mg -= 5;
            }
        } else if (D_800FB6E0_GhostGuess >= 60) {
            D_800FB670_GhostGuess = 18;
        }
        D_800FB6E0_GhostGuess++;
        break;
    case 18:
        if (D_800FB678_GhostGuess != 0) {
            func_80060398(0x28);
        }
        D_800FBC10_GhostGuess = -1;
        func_800726AC(0, 0x14);
        arg0->func_ptr = func_800F6AAC_GhostGuess;
        break;
    }
    ((void (*)(omObjData*))func_800FB514_GhostGuess)(arg0); /* retail passes the object */
}
void func_800F7FD8_GhostGuess(f32 x, f32 y, f32 z, s32 arg3) {
    omObjData* player = D_800FBBE4_GhostGuess;
    f32 dx;
    f32 dz;

    D_800FBEDA_GhostGuess = 0;
    D_800FBEE0_GhostGuess = x;
    D_800FBEE4_GhostGuess = y + 25.0;
    D_800FBEE8_GhostGuess = z;
    dx = x - player->trans.x;
    dz = z - player->trans.z;
    D_800FBEF8_GhostGuess = player->trans.x;
    D_800FBEFC_GhostGuess = player->trans.y;
    D_800FBF00_GhostGuess = player->trans.z;
    D_800FBEEC_GhostGuess = func_800B1750(dx * dx + dz * dz);
    D_800FBEF0_GhostGuess = func_800B0CD8(dx, dz);
    D_800FBEF4_GhostGuess = (D_800FBEEC_GhostGuess - 150.0) / 12.0;
    D_800FBF12_GhostGuess = arg3;
}
void func_800F80E4_GhostGuess(omObjData* arg0) {
    GGRec* r0;
    GGRec* r;
    s32 i;

    if (D_800FB670_GhostGuess < 7) {
        r0 = D_800FBED0_GhostGuess;
        switch (D_800FBED2_GhostGuess) {
        case 0:
            if (r0->unk_0A == 0) {
                func_800258EC(arg0->model[0], 4, 0);
                r0->unk_02++;
                r0->unk_08 = 16;
                D_800FB6F0_GhostGuess = 8;
            }
            break;
        case 1:
            if (--r0->unk_08 == 0) {
                r0->unk_02++;
            }
            break;
        case 2:
            if ((r0->pos.y -= D_800FB6F0_GhostGuess) <= 0.0f) {
                r0->pos.y = 0.0f;
                if (D_800FB670_GhostGuess == 6) {
                    r0->unk_02++;
                    r0->unk_08 = 32;
                    D_800F2B7C[arg0->model[0]].unk_4C = 1.0f;
                }
            }
            D_800FB6F0_GhostGuess += 8;
            break;
        case 3:
            if (--r0->unk_08 == 0) {
                r0->unk_02++;
                PlaySound(0x196);
                r0->unk_08 = 64;
            }
            break;
        case 4:
            if (--r0->unk_08 == 0) {
                func_800258EC(arg0->model[0], 4, 4);
                r0->unk_02++;
            } else if (r0->unk_08 <= 32) {
                D_800F2B7C[arg0->model[0]].unk_20 ^= 4;
            }
        case 5:
            for (i = 1; i < r0->unk_42 + 1; i++) {
                r = &D_800FBED0_GhostGuess[i];
                switch (r->unk_02) {
                case 0:
                    if (++r->unk_08 >= i * 4) {
                        r->unk_1C = r->unk_42 = r0->unk_1C;
                        r->unk_20 = r->unk_44 = r0->unk_20;
                        r->unk_24 = r->unk_46 = r0->unk_24;
                        r->unk_48 = 0;
                        r->unk_02++;
                        func_800258EC(r->unk_40, 4, 0);
                    }
                    break;
                case 1:
                    r->unk_1C -= r->unk_24;
                    r->unk_20 -= 15.0f;
                    if (r->unk_20 <= r->unk_44 - 180) {
                        r->unk_02++;
                        r->unk_20 = func_8009B618(r->unk_20 + 360.0f, 360.0);
                        r->unk_24 = 4.1666665f;
                    }
                    break;
                case 2:
                    if (r->unk_20 - 15.0f < 0.0f) {
                        r->unk_02++;
                    }
                    r->unk_20 = func_8009B618(r->unk_20 - 15.0f + 360.0f, 360.0);
                    break;
                case 3:
                    r->unk_1C -= r->unk_24;
                    r->unk_20 -= 15.0f;
                    r->scale.x -= 0.08;
                    r->scale.y -= 0.08;
                    func_80025830(r->unk_40, r->scale.x, r->scale.y, r->scale.z);
                    if (r->unk_20 <= -180.0f) {
                        r->unk_02++;
                        func_800258EC(r->unk_40, 4, 4);
                        PlaySound(0xFC);
                    }
                    break;
                case 4:
                    if (i == r0->unk_42) {
                        D_800FB670_GhostGuess = 7;
                    }
                    break;
                }
                r->pos.x = func_800AEAC0(r->unk_20) * r->unk_1C + r0->unk_28;
                r->pos.y = func_800AEAC0(r->unk_48 * 3.75) * 200.0 + 75.0;
                r->pos.z = func_800AEFD0(r->unk_20) * r->unk_1C + r0->unk_30;
                func_80025798(r->unk_40, r->pos.x, r->pos.y, r->pos.z);
                if (r->unk_48 < 48) {
                    r->unk_48++;
                }
            }
            break;
        }
        omSetTra(arg0, r0->pos.x, r0->pos.y, r0->pos.z);
    }
}
s32 func_800F86CC_GhostGuess(omObjData* arg0, omObjData* arg1) {
    unkGlobalStruct_00* work = arg0->unk_50;
    GGGhost* g = GG_GHOST(arg1);

    if (D_800FB670_GhostGuess != 4) {
        return (g->unk_06 == 5) | (g->unk_06 == 9);
    }
    D_800FB670_GhostGuess = 5;
    func_800601D4(0x5A);
    if ((work->unk_5C & 0x320) && work->unk_38 >= 0.0) {
        func_800184BC(arg0, 6);
        work->unk_38 = -1.323f;
        work->unk_3C = func_800B0CD8(arg0->trans.x, arg0->trans.z);
        work->unk_40 = -(func_800B1750(arg0->trans.x * arg0->trans.x + arg0->trans.z * arg0->trans.z) / 20.0f);
        func_80017C0C(arg0, 7, arg0->trans.x, arg0->trans.y, arg0->trans.z, 0.0f, 0.0f);
        func_80060540(0x146, 0);
        D_800FB6A0_GhostGuess = g->unk_05;
        g->unk_06 = 5;
        return 1;
    }
    func_80060540(0x21E, 0);
    D_800FB6A0_GhostGuess = g->unk_05;
    g->unk_06 = 1;
    g->scale.x = g->scale.y = g->scale.z = 1.0f;
    g->rot.y = func_800B0CD8(arg0->trans.x - g->pos.x, arg0->trans.z - g->pos.z);
    return 0;
}
void func_800F8888_GhostGuess(omObjData* arg0) {
    Vec o;
    s32 pad[20]; /* unused: retail's frame is 0x50 bytes larger */
    unkGlobalStruct_00* work;
    GGGhost* g;
    f32 rot;
    f32 x;
    f32 y;
    f32 z;
    f32 dx;
    f32 dz;
    f32 ex;
    f32 ez;
    f32 spd;
    f32 v;
    f32 s;
    s32 btn;
    u8 port;

    work = arg0->unk_50;
    rot = work->unk_3C;
    port = work->unk_56;
    btn = func_80017A60(arg0);
    o.x = x = arg0->trans.x;
    o.y = y = arg0->trans.y;
    o.z = z = arg0->trans.z;
    switch (D_800FB670_GhostGuess) {
    case 0:
    case 1:
        func_800184BC(arg0, 0x23);
        break;
    case 2:
    case 3:
        y += D_800FB6F8_GhostGuess * 20.0f;
        D_800FB6F8_GhostGuess -= D_800B8968;
        if (y < 0.0f) {
            y = 0.0f;
            if (btn & 0x400) {
                func_80010ED4(GwPlayer[work->unk_58].character + 0x12E, 0);
                func_800184BC(arg0, 0x21);
                func_80060F04(work->unk_58, 10, 0, 10);
            } else {
                func_800184BC(arg0, 0);
            }
        } else {
            func_800184BC(arg0, 9);
        }
        rot = 0.0f;
        break;
    case 4:
        if (GwPlayer[work->unk_58].flags & 1) {
            ContStkY[(s8)port] = 0;
            ContStkX[(s8)port] = 0;
            ContBtnTrg[(s8)port] = 0;
            ContBtn[(s8)port] = 0;
            switch (arg0->work[0]) {
            case 0:
                if ((arg0->work[2] >> 4) & 1) {
                    D_800FB6F4_GhostGuess = (s32)((rand8() & 0xF) + 4) + D_800FB6F4_GhostGuess;
                } else {
                    D_800FB6F4_GhostGuess = D_800FB6F4_GhostGuess - (s32)((rand8() & 0xF) + 4);
                }
                if (D_800FB674_GhostGuess <= func_800B1750(x * x + z * z) + 90.0 + 100.0) {
                    dx = func_800AEAC0(D_800FB6F4_GhostGuess) * 10.0;
                    dz = func_800AEFD0(D_800FB6F4_GhostGuess) * 10.0;
                    if (fabs(x + dx) > fabs(x) && fabs(z + dz) > fabs(z)) {
                        D_800FB6F4_GhostGuess = func_8009B618(D_800FB6F4_GhostGuess + 180.0f, 360.0);
                    } else if (fabs(x + dx) > fabs(x)) {
                        if (dx * dz > 0.0f) {
                            D_800FB6F4_GhostGuess = func_8009B618(D_800FB6F4_GhostGuess + 270.0f, 360.0);
                        } else {
                            D_800FB6F4_GhostGuess = func_8009B618(D_800FB6F4_GhostGuess + 90.0f, 360.0);
                        }
                    } else if (fabs(x + dz) > fabs(z)) { /* retail tests x + dz */
                        if (dx * dz > 0.0f) {
                            D_800FB6F4_GhostGuess = func_8009B618(D_800FB6F4_GhostGuess + 90.0f, 360.0);
                        } else {
                            D_800FB6F4_GhostGuess = func_8009B618(D_800FB6F4_GhostGuess + 270.0f, 360.0);
                        }
                    }
                }
                ContStkX[(s8)port] = func_800AEAC0(D_800FB6F4_GhostGuess) * 40.0;
                ContStkY[(s8)port] = func_800AEFD0(D_800FB6F4_GhostGuess) * 40.0;
                if (arg0->work[3] != 0) {
                    arg0->work[3]--;
                } else {
                    rand8();
                    rand8();
                    rand8();
                    if (!(rand8() & 0x3F)) {
                        arg0->work[0]++;
                        if ((u8)(rand8() % 5) <= D_800FB6AC_GhostGuess) {
                            arg0->work[1] = (u8)D_800FB69C_GhostGuess;
                        } else {
                            arg0->work[1] = rand8() & 7;
                        }
                    }
                }
                arg0->work[2]++;
                break;
            case 1:
                g = &D_800FBC18_GhostGuess[arg0->work[1]];
                ex = g->pos.x - x;
                ez = g->pos.z - z;
                if (func_800B1750(ex * ex + ez * ez) < 270.0) {
                    arg0->work[0]++;
                    arg0->work[2] = rand8() & 1;
                    arg0->work[3] = 8;
                }
                D_800FB6F4_GhostGuess = func_800B0CD8(g->pos.x - x, -(g->pos.z - z));
                ContStkX[(s8)port] = func_800AEAC0(D_800FB6F4_GhostGuess) * 60.0;
                ContStkY[(s8)port] = func_800AEFD0(D_800FB6F4_GhostGuess) * 60.0;
                break;
            case 2:
                g = &D_800FBC18_GhostGuess[arg0->work[1]];
                if (arg0->work[2] != 0) {
                    ContBtn[(s8)port] = ContBtnTrg[(s8)port] |= 0x8000;
                    D_800FB6F4_GhostGuess = func_800B0CD8(g->pos.x - x, -(g->pos.z - z));
                    ContStkX[(s8)port] = func_800AEAC0(D_800FB6F4_GhostGuess) * 60.0;
                    ContStkY[(s8)port] = func_800AEFD0(D_800FB6F4_GhostGuess) * 60.0;
                } else if (arg0->work[3] != 0) {
                    D_800FB6F4_GhostGuess = func_800B0CD8(g->pos.x - x, -(g->pos.z - z));
                    ContStkX[(s8)port] = func_800AEAC0(D_800FB6F4_GhostGuess) * 4.0;
                    ContStkY[(s8)port] = func_800AEFD0(D_800FB6F4_GhostGuess) * 4.0;
                    arg0->work[3]--;
                } else {
                    ContBtn[(s8)port] = ContBtnTrg[(s8)port] |= 0x4000;
                }
                break;
            }
        }
        func_80005A28(arg0);
        func_800F9400_GhostGuess(arg0, D_800FB674_GhostGuess - 52.5);
        return;
    case 7:
    case 17:
        while (rot < 0.0) {
            rot += 360.0f;
        }
        rot = func_8009B618(rot, 360.0);
        if (fabs(rot) > 15.0) {
            if (rot > 180.0f) {
                rot += 10.0f;
            } else {
                rot -= 10.0f;
            }
        } else {
            rot = 0.0f;
        }
        break;
    case 14:
        func_80010ED4(GwPlayer[work->unk_58].character + 0x45F, 0);
        break;
    case 15:
        func_800258EC(arg0->model[0], 4, 4);
        func_800258EC(arg0->model[1], 4, 4);
        break;
    case 18:
        break;
    case 5:
        if (btn & 0x8D00) {
            func_80005A28(arg0);
            func_800F9400_GhostGuess(arg0, D_800FB674_GhostGuess - 52.5);
            return;
        }
    default:
        func_800258EC(arg0->model[0], 4, 0);
        spd = work->unk_40;
        x += func_800AEAC0(rot) * spd;
        z += func_800AEFD0(rot) * spd;
        if (btn & 0x20) {
            v = work->unk_38;
            y += v * v * (v >= 0.0f ? -35.0f : 35.0f);
            work->unk_38 += 0.15f;
            if (y <= 0.0) {
                func_800184BC(arg0, 0);
                work->unk_40 = 0.0f;
                work->unk_38 = 0.0f;
                y = work->unk_38;
            }
        } else if (btn & 0xC00) {
            if (fabs(x) > fabs(o.x) || fabs(z) > fabs(o.z)) {
                work->unk_40 = x = z = 0.0f;
            }
        } else {
            func_800184BC(arg0, 0);
            work->unk_40 = 0.0f;
        }
        break;
    }
    func_800F9400_GhostGuess(arg0, D_800FB674_GhostGuess - 52.5);
    func_8009ECB0(D_800F2B7C[arg0->model[0]].unk7C, 0.0f, 0.0f, 0.0f);
    arg0->trans.x = x;
    arg0->trans.y = y;
    arg0->trans.z = z;
    arg0->rot.y = work->unk_3C = rot;
    s = 1.0 - y / 4000.0;
    func_80025798(arg0->model[1], x, 0.0f, z);
    func_80025830(arg0->model[1], s, s, s);
    func_80017DB0(arg0);
}
void func_800F9400_GhostGuess(omObjData* arg0, f32 max) {
    f32 a;

    if (max * max < arg0->trans.x * arg0->trans.x + arg0->trans.z * arg0->trans.z) {
        a = func_800B0CD8(arg0->trans.x, arg0->trans.z);
        arg0->trans.x = max * func_800AEAC0(a);
        arg0->trans.z = max * func_800AEFD0(a);
    }
}
// register allocation of the loop's double constants (0.125 pinned in s6/s7), compare order (masked 300, structural 74 lines)
#ifdef NON_MATCHING
void func_800F948C_GhostGuess(omObjData* arg0) {
    Vec hit;
    s32 hitOn;
    f32 minDist;
    omObjData* player;
    unkGlobalStruct_00* work;
    GGGhost* g;
    s32 btn;
    s32 i;
    s32 t;
    f32 f;
    f32 r;
    f32 a;
    f32 old;
    f32 dx;
    f32 dy;
    f32 dz;

    hit.y = 0.0f;
    hit.x = hit.y;
    hit.z = r = hit.y;
    hitOn = 0;
    minDist = 3625.0f;
    player = D_800FBBE4_GhostGuess;
    btn = func_80017A60(player);
    work = player->unk_50;
    D_800FB700_GhostGuess = r;
    if (D_800FB670_GhostGuess == 3 || D_800FB670_GhostGuess == 4 ||
        ((D_800FB670_GhostGuess == 0) | (D_800FB670_GhostGuess == 2))) {
        if (btn & 0x140) {
            f = func_80025E70(player->model[0]);
            if (f == -1.0f) {
                f = func_80025D18(player->model[0]);
            }
            if ((f >= 16.0f) & (f <= 20.0f)) {
                hitOn = 1;
                r = work->unk_64 + work->unk_48;
                a = work->unk_3C;
                hit.x = func_800AEAC0(a) * r + player->trans.x;
                hit.y = player->trans.y;
                hit.z = func_800AEFD0(a) * r + player->trans.z;
            }
        }
        D_800FB700_GhostGuess = func_800AEAC0(2.0f * (D_800FB6FC_GhostGuess * D_800FB6C0_GhostGuess[D_800FB6AC_GhostGuess])) * 12.0f;
    } else {
        D_800FB704_GhostGuess--;
    }
    for (i = 0; i < 8; i++) {
        g = &D_800FBC18_GhostGuess[i];
        switch (D_800FB670_GhostGuess) {
        case 1:
            t = 50 - D_800FB704_GhostGuess;
            func_800FB2D0_GhostGuess(D_800FBBF0_GhostGuess[3], (u8)(t * 5 + 5));
            g->pos.y = (t * 0.04 + -1.0) * 100.0;
            if (t < 21) {
                if (g->rot.y >= 105.0f && g->rot.y <= 255.0f) {
                    g->unk_50 = t * 0.225;
                } else {
                    g->unk_50 = t * 0.2;
                }
            } else {
                g->unk_4C = (t - 20) * 0.033;
            }
            g->unk_48 = t * 0.02;
            break;
        case 2:
            func_800FB270_GhostGuess(g->obj->model[0], (s16)D_800FBBF0_GhostGuess[g->unk_08]);
        case 3:
        case 4:
            a = (f32)(i * 45) + D_800FB6FC_GhostGuess;
            g->pos.x = func_800AEAC0(a) * D_800FB674_GhostGuess;
            g->pos.y = (func_800AEAC0(D_800FB6FC_GhostGuess * D_800FB6C0_GhostGuess[D_800FB6AC_GhostGuess]) * 0.2 + 1.0) * 100.0;
            g->pos.z = func_800AEFD0(a) * D_800FB674_GhostGuess;
            old = g->rot.y;
            g->rot.y = g->unk_44 = r = func_8009B618(a + 180.0f, 360.0);
            if (r <= 90.0 || r >= 270.0) {
                g->rot.y = 0.0f;
            }
            if (D_800FB6A8_GhostGuess == 0) {
                if (g->rot.y + 10.0 <= old || old <= g->rot.y - 10.0) {
                    g->rot.y = func_8009B618(old + 3.2, 360.0);
                }
            } else if (D_800FB6A8_GhostGuess == 1) {
                if (g->rot.y + 4.0 <= old || old <= g->rot.y - 4.0) {
                    g->rot.y = func_8009B618(old - 3.2 + 360.0, 360.0);
                }
            }
            g->rot.x = func_800AEAC0(D_800FB6FC_GhostGuess * D_800FB6C0_GhostGuess[D_800FB6AC_GhostGuess]) * 12.0f + 6.0f;
            g->unk_48 = g->unk_4C = 362.5 / D_800FB674_GhostGuess;
            g->unk_50 = (762.5 - D_800FB674_GhostGuess) / 100.0;
            if (hitOn != 0) {
                dx = g->pos.x - hit.x;
                dy = g->pos.y - hit.y;
                dz = g->pos.z - hit.z;
                if (func_800B1750(dx * dx + dy * dy + dz * dz) < 200.0) {
                    func_80017C0C(player, 7, g->obj->trans.x, player->trans.y, g->obj->trans.z, 0.0f, func_800B0CD8(dx, dz) + 180.0f);
                    func_80060540(0x21D, 2);
                    func_80060540(0x21D, 3);
                    D_800FB6A0_GhostGuess = g->unk_05;
                    g->unk_06 = 4;
                    g->scale.x = g->scale.y = g->scale.z = 1.0f;
                    g->rot.y = func_800B0CD8(player->trans.x - g->pos.x, player->trans.z - g->pos.z);
                    g->unk_0A = 4;
                    g->unk_34.x = func_800AEAC0(g->rot.y) * -25.0;
                    g->unk_34.z = func_800AEFD0(g->rot.y) * -25.0;
                    D_800FB670_GhostGuess = 5;
                    func_800601D4(0x5A);
                    func_80060F04((s16)D_800FBC08_GhostGuess, 2, 3, 10);
                }
            }
            break;
        case 5:
            if (g->unk_06 != 5) {
                g->rot.x = func_800AEAC0(D_800FB6FC_GhostGuess * D_800FB6C0_GhostGuess[D_800FB6AC_GhostGuess]) * 12.0f + 6.0f;
                g->rot.y = func_800B0CD8(player->trans.x - g->pos.x, player->trans.z - g->pos.z);
                g->pos.y = (func_800AEAC0(D_800FB6FC_GhostGuess * D_800FB6C0_GhostGuess[D_800FB6AC_GhostGuess]) * 0.2 + 1.0) * 100.0;
            }
            g->unk_4C = g->unk_48 = 362.5 / D_800FB674_GhostGuess;
            g->unk_50 = (762.5 - D_800FB674_GhostGuess) / 100.0;
            if (i == D_800FB6A0_GhostGuess && D_800FB704_GhostGuess == 50) {
                if (i == D_800FB69C_GhostGuess) {
                    g->unk_06 = 9;
                    D_800FB6D0_GhostGuess = 1;
                } else {
                    PlaySound(0x100);
                    if (g->unk_06 == 4) {
                        g->unk_06 = 1;
                    } else if (g->unk_06 == 5) {
                        g->unk_06 = 6;
                    }
                    g->unk_08 = 0;
                    func_800FB270_GhostGuess(g->obj->model[0], (s16)D_800FBBF0_GhostGuess[0]);
                    D_800FB6D0_GhostGuess = 0;
                }
            }
            break;
        case 6:
            g->unk_06 = 9;
            break;
        case 8:
            if (i == D_800FB69C_GhostGuess) {
                g->unk_06 = 7;
                g->unk_0A = 0;
                g->unk_4C = g->unk_48;
                func_80060540(0x222, 2);
            }
            if (g->unk_44 >= 90.0f && g->unk_44 <= 270.0f) {
                func_800FB270_GhostGuess(g->obj->model[1], (s16)D_800FBC04_GhostGuess);
            }
            g->unk_34.x = g->unk_34.y = g->unk_34.z = 0.0f;
            dx = player->trans.x - g->pos.x;
            dz = player->trans.z - g->pos.z;
            g->unk_40 = sqrtf(dx * dx + dz * dz);
            if (g->unk_40 < minDist) {
                minDist = g->unk_40;
                D_800FB6A4_GhostGuess = i;
                g->unk_34.x = (g->unk_40 - 60.0) * func_800AEAC0(g->rot.y) * 0.125;
                g->unk_34.z = (g->unk_40 - 60.0) * func_800AEFD0(g->rot.y) * 0.125;
            }
            break;
        case 9:
            g->pos.y = (func_800AEAC0(D_800FB6FC_GhostGuess * D_800FB6C0_GhostGuess[D_800FB6AC_GhostGuess]) * 0.2 + 1.0) * 100.0;
            g->rot.y = func_800B0CD8(player->trans.x - g->pos.x, player->trans.z - g->pos.z);
            if (i == D_800FB6A4_GhostGuess) {
                if (D_800FB704_GhostGuess < 8) {
                    g->pos.x += g->unk_34.x;
                    g->pos.z += g->unk_34.z;
                    g->unk_48 += g->unk_40 * 0.125 / 362.5;
                    g->unk_50 += g->unk_40 * 0.125 / 100.0;
                    g->unk_4C = g->unk_48;
                }
            } else {
                g->unk_4C = g->unk_48;
            }
            break;
        case 10:
            g->unk_4C = g->unk_48;
            if (i != D_800FB6A4_GhostGuess) {
                break;
            }
            if (fabs(work->unk_3C - g->rot.y + 180.0f) <= 90.0) {
                func_800184BC(player, 9);
                work->unk_40 = -18.0f;
                work->unk_3C = func_800B0CD8(player->trans.x, player->trans.z);
            } else {
                func_800184BC(player, 10);
                work->unk_40 = 18.0f;
                work->unk_3C = func_800B0CD8(player->trans.x, player->trans.z) + 180.0f;
            }
            func_80017C0C(player, 5, g->pos.x, g->pos.y, g->pos.z, 0.0f, func_800B0CD8(player->trans.x, player->trans.z) + 180.0f);
            func_80060540(0x144, 0);
            func_80060F04((s16)D_800FBC08_GhostGuess, 20, 0, 20);
        case 11:
            g->pos.y = (func_800AEAC0(D_800FB6FC_GhostGuess * D_800FB6C0_GhostGuess[D_800FB6AC_GhostGuess]) * 0.2 + 1.0) * 100.0;
            g->rot.y = func_800B0CD8(player->trans.x - g->pos.x, player->trans.z - g->pos.z);
            g->unk_4C = g->unk_48;
            break;
        case 12:
            g->unk_06 = 7;
            g->rot.y = func_8009B618(func_800B0CD8(g->pos.x, g->pos.z) + 180.0f, 360.0);
            g->rot.x = 18.0f;
            g->unk_40 = sqrtf(g->pos.x * g->pos.x + g->pos.z * g->pos.z) - 70.0;
            g->unk_34.x = func_800AEAC0(g->rot.y) * g->unk_40 * 0.05;
            g->unk_34.z = func_800AEFD0(g->rot.y) * g->unk_40 * 0.05;
            g->unk_4C = g->unk_48;
        case 13:
            g->pos.y = (func_800AEAC0(D_800FB6FC_GhostGuess * D_800FB6C0_GhostGuess[D_800FB6AC_GhostGuess]) * 0.2 + 1.0) * 100.0;
            g->pos.x += g->unk_34.x;
            g->pos.z += g->unk_34.z;
            g->unk_48 += g->unk_40 * 0.05 / 362.5;
            g->unk_50 += g->unk_40 * 0.05 / 100.0;
            g->unk_4C = g->unk_48;
            break;
        case 14:
            g->unk_34.x = g->unk_48 * 0.03125;
            g->unk_34.y = g->unk_4C * 0.05;
            g->unk_34.z = g->unk_50 * 0.085;
            g->unk_0A = rand8() & 7;
            g->unk_4C = g->unk_48;
            break;
        case 15:
            if (D_800FB704_GhostGuess < 13) {
                g->unk_50 = (f32)D_800FB704_GhostGuess * g->unk_34.z + 0.001;
                g->unk_4C = g->unk_34.y;
            } else {
                g->unk_4C = (f32)(D_800FB704_GhostGuess - 12) * g->unk_34.y;
            }
            g->unk_48 = (f32)D_800FB704_GhostGuess * g->unk_34.x + 0.001;
            g->pos.y = (D_800FB704_GhostGuess * 0.078125 + -1.5) * 100.0;
            if (D_800FB704_GhostGuess == 0) {
                g->unk_06 = 1;
                func_800258EC(g->obj->model[0], 4, 4);
                func_800258EC(g->obj->model[1], 4, 4);
            }
            break;
        case 16:
        case 18:
            if (D_800FB6D0_GhostGuess == 0) {
                g->unk_4C = g->unk_48;
            }
            break;
        }
    }
    if (D_800FB704_GhostGuess <= 0) {
        switch (D_800FB670_GhostGuess) {
        case 1:
            D_800FB670_GhostGuess = 2;
            func_80010ED4(GwPlayer[work->unk_58].character + 0x127, 0);
            D_800FB704_GhostGuess = 80;
            D_800FB6FC_GhostGuess = 0.0f;
            break;
        case 5:
            if (D_800FB6D0_GhostGuess != 0) {
                D_800FB670_GhostGuess = 6;
            } else {
                D_800FB670_GhostGuess = 8;
            }
            break;
        case 8:
            if (D_800FB678_GhostGuess == 0) {
                D_800FB670_GhostGuess = 9;
            } else {
                D_800FB670_GhostGuess = 16;
            }
            D_800FB704_GhostGuess = 30;
            break;
        case 9:
            D_800FB670_GhostGuess = 10;
            break;
        case 10:
            D_800FB670_GhostGuess = 11;
            D_800FB704_GhostGuess = 12;
            break;
        case 11:
            D_800FB670_GhostGuess = 12;
            break;
        case 12:
            func_80060540(0x222, 2);
            D_800FB670_GhostGuess = 13;
            D_800FB704_GhostGuess = 20;
            break;
        case 13:
            D_800FB670_GhostGuess = 14;
            break;
        case 14:
            D_800FB670_GhostGuess = 15;
            func_80060540(0x225, 3);
            D_800FB704_GhostGuess = 32;
            break;
        case 7:
        case 17:
        case 18:
            D_800FB704_GhostGuess = 255;
            break;
        }
    }
    if (D_800FB6A8_GhostGuess == 0) {
        D_800FB6FC_GhostGuess = func_8009B618(D_800FB6FC_GhostGuess + D_800FB6B0_GhostGuess[D_800FB6AC_GhostGuess], 360.0);
    } else if (D_800FB6A8_GhostGuess == 1) {
        D_800FB6FC_GhostGuess = func_8009B618(D_800FB6FC_GhostGuess + 360.0f - D_800FB6B0_GhostGuess[D_800FB6AC_GhostGuess], 360.0);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_GhostGuess/117210", func_800F948C_GhostGuess);
#endif
// case 2/7 store tail not cross-jumped, sprite anim load order (masked 9)
#ifdef NON_MATCHING
void func_800FA764_GhostGuess(omObjData* arg0) {
    GGGhost* g;
    unk65770Obj* spr;
    s32 i;
    s32 v;
    f32 t;
    f32 r;

    g = GG_GHOST(arg0);
    if (D_800FB670_GhostGuess == 4) {
        if (g->unk_0A == 0) {
            if (g->unk_04 != 0) {
                switch (rand8() & 3) {
                case 0:
                    g->unk_06 = 2;
                    goto tex;
                case 1:
                    g->unk_06 = 3;
                tex:
                    g->unk_08 = (u8)(rand8() % 3);
                    func_800FB270_GhostGuess(arg0->model[0], (s16)D_800FBBF0_GhostGuess[g->unk_08]);
                    break;
                case 2:
                    g->unk_06 = 2;
                    break;
                case 3:
                    g->unk_06 = 3;
                    break;
                }
                for (i = 0; i < 8; i++) {
                    D_800FBC18_GhostGuess[i].unk_0A = (u8)rand8() % (D_800FB708_GhostGuess * 2 + 6) + (D_800FB708_GhostGuess >> 1) + 1;
                }
                g->unk_0A = (u8)(rand8() & 0xF) + 0x40;
                g->unk_34.x = g->unk_34.y = g->unk_34.z = 0.0f;
                D_800FB708_GhostGuess++;
            } else {
                g->unk_06 = D_800FBC18_GhostGuess[D_800FB69C_GhostGuess].unk_06;
                if (g->unk_08 != D_800FBC18_GhostGuess[D_800FB69C_GhostGuess].unk_08) {
                    g->unk_08 = D_800FBC18_GhostGuess[D_800FB69C_GhostGuess].unk_08;
                    func_800FB270_GhostGuess(arg0->model[0], (s16)D_800FBBF0_GhostGuess[g->unk_08]);
                }
                g->unk_34.x = g->unk_34.y = g->unk_34.z = 0.0f;
                g->unk_0A = -1;
                g->unk_0C = ~(u8)(rand8() % 50);
            }
        } else if (g->unk_0A >= -60) {
            if (g->unk_0A == g->unk_0C) {
                func_80060540(0x224, 1);
            }
            g->unk_0A--;
        }
    }
    switch (g->unk_06) {
    case 1:
        if (D_800FB670_GhostGuess == 5) {
            g->unk_08 = 0;
            func_800FB270_GhostGuess(arg0->model[0], (s16)D_800FBBF0_GhostGuess[0]);
            g->unk_0A = 0;
        }
        break;
    case 2:
        g->unk_34.y += 8.0;
        if (g->unk_34.y >= 360.0) {
            g->unk_34.y = 0.0f;
            g->unk_06 = 1;
        }
        g->scale.y = 1.0 - func_800AEAC0(g->unk_34.y) * 0.7;
        g->unk_4C *= g->scale.y;
        break;
    case 3:
        g->unk_34.x += 8.0;
        if (g->unk_34.x >= 360.0) {
            g->unk_34.x = 0.0f;
            g->unk_06 = 1;
        }
        g->scale.x = 1.0 - func_800AEAC0(g->unk_34.x) * 0.7;
        g->unk_48 *= g->scale.x;
        break;
    case 4:
        g->unk_48 = g->unk_4C = 362.5 / (D_800FB674_GhostGuess - 100.0);
        g->unk_08 = 2;
        func_800FB270_GhostGuess(arg0->model[0], (s16)D_800FBBF0_GhostGuess[2]);
        if (g->unk_0A > 0) {
            g->pos.x += g->unk_34.x;
            g->pos.z += g->unk_34.z;
            g->unk_50 -= 0.25;
            g->unk_0A--;
        }
        break;
    case 5:
        g->unk_08 = 2;
        func_800FB270_GhostGuess(arg0->model[0], (s16)D_800FBBF0_GhostGuess[2]);
        func_800258EC(arg0->model[1], 4, 4);
        g->pos.y = 5.0f;
        g->rot.x = 0.0f;
        g->scale.x = g->scale.z = 1.2f;
        g->scale.y = 0.01f;
        g->unk_0A = 0;
        break;
    case 6:
        g->unk_0A++;
        func_800258EC(arg0->model[1], 4, 0);
        t = func_800AEAC0(func_8009B618(g->unk_0A * 14.4, 180.0));
        g->pos.y = g->unk_0A * 0.04 * 100.0;
        g->scale.x = g->unk_48 = (func_800AEFD0(g->unk_0A * 3.6) * 0.3 + 1.0) * ((1.0f - t) * 0.6 + 0.4);
        g->scale.y = g->unk_4C = func_800AEAC0(g->unk_0A * 3.6) + func_800AEAC0(g->unk_0A * 3.6) * t;
        g->scale.z = 1.0f;
        if (g->unk_0A >= 25) {
            g->unk_06 = 1;
            g->unk_0A = 0;
        }
        break;
    case 7:
        g->unk_0A++;
        if (D_800FB670_GhostGuess == 15) {
            v = ((g->unk_0A >> 2) + 18) * g->unk_0A;
        } else {
            v = g->unk_0A * 16;
        }
        g->scale.y = func_800AEAC0(func_8009B618(v, 180.0)) * 0.8 + 1.0;
        g->unk_4C *= g->scale.y;
        break;
    case 9:
        spr = func_800675F4((s16)D_800FBEB8_GhostGuess, g->unk_05);
        if (g->unk_0A == 0) {
            func_80060540(0x21F, 3);
            func_800258EC(arg0->model[0], 4, 4);
            func_800258EC(arg0->model[1], 4, 4);
            func_80067480((s16)D_800FBEB8_GhostGuess, g->unk_05, 0x8000);
            func_800670C4((s16)D_800FBEB8_GhostGuess, g->unk_05, 0, g->pos.x, g->pos.y, g->pos.z);
            spr->unk14 *= 4.0;
            spr->unk18 *= 4.0;
            if (g->unk_05 == D_800FB69C_GhostGuess) {
                D_800FB6D4_GhostGuess = 10 - (D_800FB708_GhostGuess >> 1);
                if (D_800FB6D4_GhostGuess <= 0) {
                    D_800FB6D4_GhostGuess = 1;
                }
                func_800F7FD8_GhostGuess(g->pos.x, g->pos.y, g->pos.z, D_800FB6D4_GhostGuess);
            }
        }
        func_800671DC((s16)D_800FBEB8_GhostGuess, g->unk_05, g->unk_0A >> 1);
        func_80066DF4((s16)D_800FBEB8_GhostGuess, g->unk_05, 0, g->pos.x, g->pos.y, g->pos.z);
        spr->unk4C->unk0[spr->unk52].unkA = 0x20;
        if ((g->unk_0A >> 1) < 14) {
            g->unk_0A++;
        }
        break;
    }
    omSetTra(arg0, g->pos.x, g->pos.y, g->pos.z);
    omSetRot(arg0, g->rot.x, g->rot.y + D_800FB700_GhostGuess, g->rot.z);
    omSetSca(arg0, g->scale.x, g->scale.y, g->scale.z);
    r = func_800AEAC0(D_800FB6FC_GhostGuess * D_800FB6C0_GhostGuess[D_800FB6AC_GhostGuess]) * 0.5 * 100.0;
    func_80025798(arg0->model[1], g->pos.x - r * func_800AEAC0(g->unk_44), 4.0f, g->pos.z - r * func_800AEFD0(g->unk_44));
    func_800257E4(arg0->model[1], 0.0f, D_800FB700_GhostGuess / 3.0f + g->unk_44, 0.0f);
    if (g->rot.y >= 100.0f && g->rot.y <= 260.0f) {
        func_80025830(arg0->model[1], g->unk_48, g->unk_4C, g->unk_50 * 1.25);
    } else {
        func_80025830(arg0->model[1], g->unk_48, g->unk_4C, g->unk_50 * 1.1);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_GhostGuess/117210", func_800FA764_GhostGuess);
#endif
void func_800FB21C_GhostGuess(void) {
}

void func_800FB224_GhostGuess(omObjData* arg0, u32 arg1) { //construct pointer into u8s
    arg0->work[0] = arg1 >> 24;
    arg0->work[1] = arg1 >> 16;
    arg0->work[2] = arg1 >> 8;
    arg0->work[3] = arg1;
}

s32 func_800FB244_GhostGuess(omObjData* arg0) { //deconstruct u8s in struct into a pointer
    return  (arg0->work[0] << 24) |
            (arg0->work[1] << 16) |
            (arg0->work[2] << 8) |
            arg0->work[3];
}

void func_800FB270_GhostGuess(s16 arg0, s16 arg1) {
    unk_ovl_2D_struct* m = &D_800F2B7C[arg0];

    m->unk_6C->unk_66--;
    m->unk_6C = D_800F2B7C[arg1].unk_6C;
    m->unk_6C->unk_66++;
}

/* Sets the alpha byte of every RGBA32 texel of the texture model[arg0] uses. */
void func_800FB2D0_GhostGuess(s32 arg0, s32 arg1) {
    unk2C0C0Struct70* tex;
    unk2C0C0StructC0* target;
    u32* px;
    s32 i;
    s32 j;
    s32 a;
    u32 hi;

    target = D_800F2B7C[arg0].unk_6C;
    i = -1;
    do { /* retail visits records 0..128: one past the 128 */
        i++;
        if ((D_800F37AC + i)->unk_28 == target) {
            tex = D_800F37AC + i;
            px = (u32*)tex->unk_24;
            for (j = 0; j < tex->unk_1A * tex->unk_1B; j++, px++) {
                hi = *px >> 8;
                a = arg1;
                if ((u8)a >= 0xFF) {
                    a = 0xFF;
                }
                *px = (hi << 8) | (u8)a;
            }
        }
    } while (i != 128);
}
