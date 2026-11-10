#include "MusicalMushroom.h"

/* .data (0x1216F0) */
s32 D_800FB4C0_MusicalMushroom = 150; /* frames the bell waits for everyone to land */
s32 D_800FB4C4_MusicalMushroom[3] = { 0, 0, 0 }; /* unreferenced */
u32 D_800FB4D0_MusicalMushroom = 0; /* intro state */
s32 D_800FB4D4_MusicalMushroom = 0; /* mushrooms fade in */
u32 D_800FB4D8_MusicalMushroom = 0;
u32 D_800FB4DC_MusicalMushroom = 121;
u32 D_800FB4E0_MusicalMushroom = 0;
s32 D_800FB4E4_MusicalMushroom = 0;
u32 D_800FB4E8_MusicalMushroom = 929; /* timer, frames */
s32 D_800FB4EC_MusicalMushroom = 0;
s32 D_800FB4F0_MusicalMushroom = 0;
u32 D_800FB4F4_MusicalMushroom = 0;
s32 D_800FB4F8_MusicalMushroom = 150;
s32 D_800FB4FC_MusicalMushroom = 0x80; /* shared model ids (s16 kept in a word); 0x80 until loaded */
s32 D_800FB500_MusicalMushroom = 0x80;
s32 D_800FB504_MusicalMushroom = 0x80;
s32 D_800FB508_MusicalMushroom = 0x80;
f32 D_800FB50C_MusicalMushroom[5] = { 0.0f, 90.0f, 180.0f, 270.0f, 0.0f }; /* player start angles */

void func_800F65E0_MusicalMushroom(void) {
    u8 temp_s0;

    func_80029090(0x32);
    func_8002ADF0(&D_800EDEC0, 0x40);
    func_8001DE70(0x20);
    omInitObjMan(0x32, 0);
    func_80060088();
    func_8000942C();
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    func_800178A0(1);
    temp_s0 = func_800178E8();
    func_80017660(temp_s0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(temp_s0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 30.0f, 80.0f, 8000.0f);
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    func_800F6E98_MusicalMushroom();
    func_800090B8(D_800ED440);
    D_800F2AF8[D_800ED440++] = omAddObj(0xA, 1, 0, -1, &func_800F9D70_MusicalMushroom);
    D_800F2AF8[D_800ED440++] = omAddObj(0xA, 1, 0, -1, &func_800FABE8_MusicalMushroom);
    D_800F2AF8[D_800ED440++] = omAddObj(0xA, 1, 0, -1, &func_800FAC38_MusicalMushroom);
    D_800F2AF8[D_800ED440++] = omAddObj(0xA, 1, 0, -1, &func_800FAC58_MusicalMushroom);
    D_800F2AF8[D_800ED440++] = omAddObj(0xA, 1, 0, -1, &func_800FACA4_MusicalMushroom);
    D_800F2AF8[D_800ED440++] = omAddObj(0xA, 1, 0, -1, &func_800FACF4_MusicalMushroom);
    D_800F2AF8[D_800ED440++] = omAddObj(0xA, 1, 0, -1, &func_800FAD50_MusicalMushroom);
    D_800F2AF8[D_800ED440++] = omAddObj(0xA, 1, 0, -1, &func_800FADAC_MusicalMushroom);
    func_800F6D8C_MusicalMushroom();
    func_80009500();
    D_800F3FB0[D_800F2BC0++] = omAddObj(0x14, 9, 0x32, -1, &func_800FAE08_MusicalMushroom);
    D_800F3FB0[D_800F2BC0++] = omAddObj(0x14, 9, 0x32, -1, &func_800FAE74_MusicalMushroom);
    D_800F3FB0[D_800F2BC0++] = omAddObj(0x14, 9, 0x32, -1, &func_800FAEE0_MusicalMushroom);
    D_800F3FB0[D_800F2BC0++] = omAddObj(0x14, 9, 0x32, -1, &func_800FAF4C_MusicalMushroom);
    func_8006B870();
    D_800FB644_MusicalMushroom = (omObjData*)func_8006B8A4(0x23, 0x699, 0xA89, 0x1A89, 1);
    func_8006B9B0(D_800FB644_MusicalMushroom, 0.0f, 497.0f, 475.0f);
    func_8006BAD0(D_800FB644_MusicalMushroom, D_800FB644_MusicalMushroom->trans.y - 240.0f);
    omAddObj(0x1E, 0, 0, -1, &func_800FA0A0_MusicalMushroom);
    D_800FB680_MusicalMushroom[0] = omAddObj(0x28, 2, 0, -1, &func_800FB1F0_MusicalMushroom);
    D_800FB680_MusicalMushroom[1] = omAddObj(0x29, 2, 0, -1, &func_800FB240_MusicalMushroom);
    D_800FB680_MusicalMushroom[2] = omAddObj(0x2A, 2, 0, -1, &func_800FB290_MusicalMushroom);
    D_800FB680_MusicalMushroom[3] = omAddObj(0x2B, 2, 0, -1, &func_800FB2E4_MusicalMushroom);
    D_800FB680_MusicalMushroom[4] = omAddObj(0x2C, 2, 0, -1, &func_800FB338_MusicalMushroom);
    D_800FB680_MusicalMushroom[5] = omAddObj(0x2D, 2, 0, -1, &func_800FB384_MusicalMushroom);
    D_800FB680_MusicalMushroom[6] = omAddObj(0x2E, 2, 0, -1, &func_800FB3D0_MusicalMushroom);
    D_800FB680_MusicalMushroom[7] = omAddObj(0x2F, 2, 0, -1, &func_800FB41C_MusicalMushroom);
    D_800FB680_MusicalMushroom[8] = omAddObj(0x30, 2, 0, -1, &func_800FB468_MusicalMushroom);
    omAddObj(1, 1, 0, -1, &func_800FAFB8_MusicalMushroom);
    omAddObj(1, 1, 0, -1, &func_800FB028_MusicalMushroom);
    omAddObj(1, 1, 0, -1, &func_800FB098_MusicalMushroom);
    omAddObj(1, 1, 0, -1, &func_800FB108_MusicalMushroom);
    omAddObj(1, 1, 0, -1, &func_800FB180_MusicalMushroom);
    omAddObj(0x32, 0, 0, -1, &func_800F71C8_MusicalMushroom);
    func_8007B168((u8*)"\x82\x65\x82\x68\x82\x6D\x82\x68\x82\x72\x82\x67", 1);
    omAddObj(0x64, 0, 0, -1, &func_800F6D40_MusicalMushroom);
    func_8002890C(0, 0, 0);
    SetFadeInTypeAndTime(0, 0x10);
}
void func_800F6D40_MusicalMushroom(omObjData* obj) {
    if (D_800F5144 == 1 || D_800F5144 == 1) { /* retail's test (as in CoinBlockBlitz) */
        func_800601D4(0x28);
        func_8002890C(0, 0, 0);
        omOvlReturnEx(1);
    }
}
void func_800F6D8C_MusicalMushroom(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 r;

    for (i = 0; i < 4; i++) {
        r = rand8() % (4 - i);
        for (j = 0; j < 4; j++) {
            for (k = i; k != 0; k--) {
                if (D_800FB6B0_MusicalMushroom[k - 1] == j) {
                    break;
                }
            }
            if (k == 0) {
                if (r == 0) {
                    break;
                }
                r--;
            }
        }
        if (j >= 4) {
            j = i;
        }
        if (j == 0) {
            D_800FB648_MusicalMushroom = i;
        }
        D_800FB6B0_MusicalMushroom[i] = j;
    }
}
void func_800F6E98_MusicalMushroom(void) {
    MMCpu* cpu;
    s32 i;

    for (cpu = D_800FB6B8_MusicalMushroom, i = 0; i < 4; i++, cpu++) {
        cpu->unk0 = 0;
        cpu->unk2 = 0;
        cpu->unk6 = 0;
        cpu->unk14 = 0;
        cpu->unk16 = 0;
        cpu->unk18 = 0;
        cpu->unk1A = 0;
        cpu->unkE = 0;
        cpu->unk24 = 10000.0f;
        cpu->unk28 = 10000.0f;
        cpu->unk2C = 0;
    }
    D_800FB6A4_MusicalMushroom = -1;
    D_800FB640_MusicalMushroom = 0;
    D_800FB78C_MusicalMushroom = 4;
    CZoom = 1160.0f;
    CRot.x = 310.0f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    Center.x = 0.0f;
    Center.y = 0.0f;
    Center.z = 145.0f;
}
void func_800F6F60_MusicalMushroom(omObjData* obj) {
    omObjData* bell = D_800FB644_MusicalMushroom;

    switch (obj->work[0]) {
    case 0:
        if (obj->work[1]++ >= 16) {
            obj->work[0] = 1;
            obj->work[1] = 0;
            obj->work[2] = 0;
        }
        CZoom = 1160.0f;
        CRot.x = 310.0f;
        CRot.y = 360.0f;
        CRot.z = 0.0f;
        Center.x = bell->trans.x;
        Center.y = bell->trans.y;
        Center.z = bell->trans.z;
        break;
    case 1:
        if (obj->work[1]++ < 90) {
            CZoom = (1.0f - func_800AEFD0(obj->work[1])) * 1340.0f + 1160.0f;
            CRot.x = 310.0f - func_800AEAC0(obj->work[2]) * 30.0f;
            CRot.y -= 4.0f;
            Center.y -= bell->trans.y / 90.0f;
            Center.z += (550.0f - bell->trans.z) / 90.0f;
            obj->work[2] += 2;
            break;
        }
        obj->work[0] = 2;
    case 2:
        CZoom = 2500.0f;
        CRot.x = 310.0f;
        CRot.y = 0.0f;
        CRot.z = 0.0f;
        Center.x = 0.0f;
        Center.y = 0.0f;
        Center.z = 550.0f;
        obj->func_ptr = NULL;
        break;
    }
}
void func_800F71C8_MusicalMushroom(omObjData* obj) {
    obj->work[0] = 0;
    obj->work[1] = 0;
    obj->work[2] = 0;
    obj->func_ptr = &func_800F6F60_MusicalMushroom;
}
void func_800F71E4_MusicalMushroom(void) {
}

void func_800F71EC_MusicalMushroom(omObjData* obj) {
    s32 i = obj->work[0];
    omObjData* pobj = D_800FB658_MusicalMushroom[i].obj;
    MMPlayerWork* work = D_800FB658_MusicalMushroom[i].work;

    work->unk_3C = 0.0f;
    func_8009ECB0(D_800F2B7C[pobj->model[0]].unk7C, work->unk_3C, work->unk_3C, work->unk_3C);
    if (D_800FB652_MusicalMushroom != 0) {
        Center.x += D_800FB64C_MusicalMushroom;
        Center.y += D_800FB788_MusicalMushroom;
        Center.z += D_800FB6A8_MusicalMushroom;
        CRot.x = func_800AEAC0(D_800FB790_MusicalMushroom) * 15.0f + 310.0f;
        D_800FB790_MusicalMushroom += D_800FB5C0_MusicalMushroom;
        CZoom += D_800FB6AC_MusicalMushroom;
        D_800FB652_MusicalMushroom--;
    } else {
        obj->func_ptr = NULL;
    }
}

void func_800F7338_MusicalMushroom(omObjData* obj) {
    omObjData* pobj = D_800FB658_MusicalMushroom[D_800FB78C_MusicalMushroom].obj;
    MMPlayerWork* work = D_800FB658_MusicalMushroom[D_800FB78C_MusicalMushroom].work;

    work->unk_3C = 0.0f;
    func_8009ECB0(D_800F2B7C[pobj->model[0]].unk7C, work->unk_3C, work->unk_3C, work->unk_3C);
    work->unk_40 = 0.0f;
    obj->work[0] = (u8)D_800FB78C_MusicalMushroom;
    obj->func_ptr = &func_800F71EC_MusicalMushroom;
    D_800FB652_MusicalMushroom = 27;
    D_800FB64C_MusicalMushroom = (pobj->trans.x - Center.x) / 27.0f;
    D_800FB788_MusicalMushroom = (pobj->trans.y - Center.y) / 27.0f;
    D_800FB6A8_MusicalMushroom = (pobj->trans.z - Center.z) / 27.0f;
    D_800FB790_MusicalMushroom = 0.0f;
    D_800FB5C0_MusicalMushroom = 3.3333333f;
    D_800FB6AC_MusicalMushroom = (1000.0f - CZoom) / 27.0f;
}
void func_800F7484_MusicalMushroom(omObjData* obj, f32 scale, f32 dy, s32 idx) {
    func_80025798(obj->model[idx], obj->trans.x, dy + obj->trans.y, obj->trans.z);
    func_80025830(obj->model[idx], scale, scale, scale);
}
void func_800F7508_MusicalMushroom(omObjData* arg0, f32* arg1) {
    arg0->trans.x = func_800AEAC0(*arg1) * 600.0f;
    arg0->trans.z = func_800AEFD0(*arg1) * 600.0f;
    arg0->trans.x += 0.0f;
    arg0->trans.z += 475.0f;
    arg0->rot.y = *arg1 + 90.0f;
    func_800184BC(arg0, 2);
    *arg1 += 0.975f; //increment timer
}

void func_800F75D8_MusicalMushroom(omObjData* arg0) { //matches but needs rodata support
    //line 1 was: unkGlobalStruct_00* temp_s1 = arg0->unk_50; but i think global struct 00 and 01 are the same struct
    unkGlobalStruct_00* temp_s1 = arg0->unk_50;
    f32* temp_a1 = &D_800FB778_MusicalMushroom[arg0->work[0]];

    switch (D_800FB4D0_MusicalMushroom) {
    case 1:
        func_80009624(temp_s1, 0);
        D_800FB4D0_MusicalMushroom = 2;
        break;
    case 2:
        func_800F7508_MusicalMushroom(arg0, temp_a1);
        break;
    case 3:
        func_8006071C(temp_s1->unk_B3);
        
        if (arg0->work[0] == (D_800F2BC0 - 1)) {
            D_800FB4D0_MusicalMushroom = 4;
        }
        arg0->rot.y += 90.0f;
        temp_s1->unk_3C = arg0->rot.y;
        /* fall through */
    case 0:
        func_800184BC(arg0, 0);
        break;
    case 4:
        arg0->rot.y = 0.0f;
        func_80009458();
        break;
    }
    func_80017DB0(arg0);
    func_800F7484_MusicalMushroom(arg0, 1.0f, 0, 1);
}

void func_800F76E8_MusicalMushroom(omObjData* obj) {
    s32 chance[2]; /* [0] react in 30 frames, [1] in 15 */
    s32 keep;
    s32 r;
    s32 i = obj->work[0];
    MMCpu* cpu = &D_800FB6B8_MusicalMushroom[i];

    if (GwPlayer[i].flags & 1) {
        cpu->unk0 |= 1;
        cpu->unk4 = GwPlayer[i].cpu_difficulty;
        switch (cpu->unk4) {
        case 0:
        default:
            chance[0] = 70;
            chance[1] = 30;
            keep = 100;
            break;
        case 1:
            chance[0] = 20;
            chance[1] = 50;
            keep = 70;
            break;
        case 2:
            chance[0] = 10;
            chance[1] = 30;
            keep = 30;
            break;
        case 3:
            chance[0] = 0;
            chance[1] = 20;
            keep = 0;
            break;
        }
        r = (u8)(rand8() % 100);
        if (r < keep) {
            cpu->unk6 = 0;
        } else {
            cpu->unk6 = 1;
        }
        r = (u8)(rand8() % 100);
        if (r < chance[0]) {
            cpu->unkA = 30;
        } else if (r < chance[0] + chance[1]) {
            cpu->unkA = 15;
        } else {
            cpu->unkA = 0;
        }
    }
}

void func_800F78A8_MusicalMushroom(omObjData* obj, MMCpu* cpu) {
    Vec3f v;
    Vec3f* p;
    f32 d;
    s32 i;

    cpu->unkE = 100;
    cpu->unk10 = 10000.0f;
    p = &v;
    for (i = 0; i < D_800ED440 - 2; i++) {
        func_800A0D00(p, (D_800FB5C8_MusicalMushroom + i)->x, (D_800FB5C8_MusicalMushroom + i)->y, (D_800FB5C8_MusicalMushroom + i)->z);
        p->x -= obj->trans.x;
        p->y -= obj->trans.y;
        p->z -= obj->trans.z;
        d = func_800A1200(p);
        if ((d < cpu->unk10) & (d > 250.0f)) {
            cpu->unkE = i;
            cpu->unk10 = d;
        }
    }
}

s32 func_800F79FC_MusicalMushroom(omObjData* obj, MMPlayerWork* work) {
    Vec3f v;
    Vec3f* p = &v;
    s32 i;

    for (i = 0; i < D_800ED440 - 2; i++) {
        func_800A0D00(p, (D_800FB5C8_MusicalMushroom + i)->x, (D_800FB5C8_MusicalMushroom + i)->y, (D_800FB5C8_MusicalMushroom + i)->z);
        p->x -= obj->trans.x;
        p->y -= obj->trans.y;
        p->z -= obj->trans.z;
        if (func_800A1200(p) < work->unk_48 + 95.0f) {
            return i + 2;
        }
    }
    func_800A0D00(p, 0.0f, 0.0f, 475.0f);
    p->x -= obj->trans.x;
    p->y -= 0.0f;
    p->z -= obj->trans.z;
    if (func_800A1200(p) < work->unk_48 + 300.0f) {
        return 1;
    }
    return 0;
}

// decomp-permuter
f32 func_800F7B84_MusicalMushroom(omObjData *obj, f32 x1, f32 z1, f32 x2, f32 z2, f32 step)
{
  Vec3f v;
  Vec3f *p = &v;
  f32 new_var;
  f32 a1;
  f32 a2;
  f32 zero;
  zero = 0.0f;
  func_800A0D00(p, x1, zero, z1);
  p->x -= obj->trans.x;
  p->y -= zero;
  p->z -= obj->trans.z;
  a1 = func_80029518(func_800B0CD8(p->x, p->z));
  new_var = x2;
  func_800A0D00(p, new_var, zero, z2);
  zero++;
  zero--;
  p->x -= obj->trans.x;
  p->y -= zero;
  p->z -= obj->trans.z;
  a2 = func_80029518(func_800B0CD8(p->x, p->z));
  if ((((a1 - a2) < zero) ? (-(a1 - a2)) : (a1 - a2)) > 180.0f)
  {
    step = -step;
    if (1)
    {
    }
  }
  if ((a1 - a2) < 0.0f)
  {
    step = -step;
  }
  return zero + step;
}

void func_800F7D1C_MusicalMushroom(omObjData* obj) {
    Vec3f v;
    Vec3f* p;
    Vec3f* t;
    f32 dist;
    f32 angle;
    f32 scale = 1.0f;
    MMPlayerWork* work = obj->unk_50;
    u16 player = obj->work[0];
    MMCpu* cpu = &D_800FB6B8_MusicalMushroom[player];

    if ((cpu->unk0 & 1) && D_800ED430 != 3) {
        ContBtn[GwPlayer[player].port] = 0;
        ContBtnTrg[GwPlayer[player].port] = 0;
        ContStkX[GwPlayer[player].port] = 0;
        ContStkY[GwPlayer[player].port] = 0;
        switch (cpu->unk2) {
        case 0:
            func_800F78A8_MusicalMushroom(obj, cpu);
            if (cpu->unkE == 100) {
                cpu->unk18 = 0;
                cpu->unk14 = 0;
                cpu->unk16 = 0;
            }
            cpu->unkC = cpu->unkA;
            cpu->unk2C = 0;
            cpu->unk2 = 1;
            /* fallthrough */
        case 1:
            if (cpu->unkC != 0) {
                cpu->unkC--;
                return;
            }
            p = &v;
            t = &D_800FB5C8_MusicalMushroom[cpu->unkE];
            func_800A0D00(p, t->x, 0.0f, t->z);
            p->x -= obj->trans.x;
            p->y -= 0.0f;
            p->z -= obj->trans.z;
            dist = func_800A1200(p);
            angle = func_800B0CD8(p->x, p->z);
            if (work->unk_54 != -1 || func_800F79FC_MusicalMushroom(obj, work) != 0) {
                angle += 90.0f;
            }
            if ((work->unk_40 >= 9.0f) & (dist < 300.0f)) {
                scale = 0.6f;
            }
            if (dist < 200.0f) {
                cpu->unk18 |= 0x8000;
                cpu->unk1A |= 0x8000;
                cpu->unk8 = 10;
                cpu->unk2 = 2;
                scale = 0.4f;
            }
            if (cpu->unk2C++ >= 151) {
                cpu->unk2 = 0;
            }
            cpu->unk14 = func_800AEAC0(angle) * 60.0f * scale;
            cpu->unk16 = func_800AEFD0(angle) * 60.0f * scale;
            break;
        case 2:
            cpu->unk18 = 0;
            if (cpu->unk8 == 0) {
                cpu->unk1A = 0;
                if (work->unk_53 != -1) {
                    if (work->unk_53 >= 2 && D_800ED440 >= work->unk_53 && func_800F79FC_MusicalMushroom(obj, work) != 0) {
                        cpu->unk2 = 3;
                    } else {
                        cpu->unk14 = 0;
                        cpu->unk16 = 0;
                        cpu->unk2 = 0;
                    }
                }
            } else {
                cpu->unk8--;
            }
            break;
        case 3:
            p = &v;
            func_800A0D00(p, 0.0f, 0.0f, 475.0f);
            p->x -= obj->trans.x;
            p->y -= 0.0f;
            p->z -= obj->trans.z;
            angle = func_800B0CD8(p->x, p->z);
            cpu->unk14 = func_800AEAC0(angle) * 60.0f;
            cpu->unk16 = func_800AEFD0(angle) * 60.0f;
            cpu->unk2 = 4;
            break;
        case 4:
            p = &v;
            func_800A0D00(p, 0.0f, 0.0f, 475.0f);
            p->x -= obj->trans.x;
            p->y -= 0.0f;
            p->z -= obj->trans.z;
            if (func_800A1200(p) < 350.0f) {
                cpu->unk18 |= 0x8000;
                cpu->unk1A |= 0x8000;
                cpu->unk8 = 20;
                cpu->unk2 = 5;
            }
            break;
        case 5:
            cpu->unk18 = 0;
            if (cpu->unk8 == 0) {
                cpu->unk1A = 0;
                if (work->unk_53 != -1) {
                    if (work->unk_53 == 1) {
                        cpu->unk2 = 6;
                    } else {
                        cpu->unk14 = 0;
                        cpu->unk16 = 0;
                        cpu->unk2 = 0;
                    }
                }
            } else {
                cpu->unk8--;
            }
            break;
        case 6:
            p = &v;
            func_800A0D00(p, 0.0f, 0.0f, 475.0f);
            p->x -= obj->trans.x;
            p->y -= 0.0f;
            p->z -= obj->trans.z;
            angle = func_800B0CD8(p->x, p->z);
            cpu->unk14 = func_800AEAC0(angle) * 60.0f * 0.5f;
            cpu->unk16 = func_800AEFD0(angle) * 60.0f * 0.5f;
            p->y = 0.0f;
            func_800A1200(p);
            cpu->unk18 |= 0x8000;
            cpu->unk1A |= 0x8000;
            cpu->unk8 = 20;
            cpu->unk2 = 5;
            break;
        }
        ContBtn[GwPlayer[player].port] = cpu->unk1A;
        ContBtnTrg[GwPlayer[player].port] = cpu->unk18;
        ContStkX[GwPlayer[player].port] = cpu->unk14;
        ContStkY[GwPlayer[player].port] = -cpu->unk16;
    }
}
// register allocation and scheduling of the D_800FB5C8 index: r in a0, table base before the index math (masked 4); tried base + r, [r - 2], inline field reads
#ifdef NON_MATCHING
void func_800F83BC_MusicalMushroom(omObjData* obj) {
    Vec3f v;
    Vec3f* p = &v;
    f32 angle;
    u16 r;
    Vec3f* t;
    f32 x;
    MMPlayerWork* work = obj->unk_50;
    u16 player = obj->work[0];
    MMCpu* cpu = &D_800FB6B8_MusicalMushroom[player];

    if ((cpu->unk0 & 1) && D_800ED430 != 3) {
        ContBtn[GwPlayer[player].port] = 0;
        ContBtnTrg[GwPlayer[player].port] = 0;
        ContStkX[GwPlayer[player].port] = 0;
        ContStkY[GwPlayer[player].port] = 0;
        switch (cpu->unk2) {
        case 0:
            func_800A0D00(p, 0.0f, 0.0f, 475.0f);
            p->x -= obj->trans.x;
            p->y -= 0.0f;
            p->z -= obj->trans.z;
            angle = func_800B0CD8(p->x, p->z);
            r = func_800F79FC_MusicalMushroom(obj, work);
            if (r == 0) {
            } else if (r == 1) {
            } else {
                /* r counts from 2 (func_800F79FC), so retail indexes from two entries before the table */
                t = &(D_800FB5C8_MusicalMushroom - 2)[r];
                x = t->x;
                angle += func_800F7B84_MusicalMushroom(obj, 0.0f, 475.0f, x, t->z, 45.0f);
            }
            cpu->unk14 = func_800AEAC0(angle) * 60.0f;
            cpu->unk16 = func_800AEFD0(angle) * 60.0f;
            func_800A0D00(p, 0.0f, 0.0f, 475.0f);
            p->x -= obj->trans.x;
            p->y -= 0.0f;
            p->z -= obj->trans.z;
            if (func_800A1200(p) < 400.0f) {
                cpu->unk18 |= 0x8000;
                cpu->unk1A |= 0x8000;
                cpu->unk8 = 20;
                cpu->unk2 = 1;
            }
            break;
        case 1:
            cpu->unk18 = 0;
            if (cpu->unk8 == 0) {
                cpu->unk1A = 0;
                if (work->unk_53 != -1) {
                    if (work->unk_53 == 1) {
                        cpu->unk8 = 5;
                        cpu->unk2 = 2;
                    } else {
                        cpu->unk14 = 0;
                        cpu->unk16 = 0;
                        cpu->unk2 = 0;
                    }
                }
            } else {
                cpu->unk8--;
            }
            break;
        case 2:
            func_800A0D00(p, 0.0f, 0.0f, 475.0f);
            p->x -= obj->trans.x;
            p->y -= 0.0f;
            p->z -= obj->trans.z;
            angle = func_800B0CD8(p->x, p->z);
            cpu->unk14 = func_800AEAC0(angle) * 60.0f;
            cpu->unk16 = func_800AEFD0(angle) * 60.0f;
            if (cpu->unk8 != 0) {
                cpu->unk8--;
            }
            cpu->unk18 |= 0x8000;
            cpu->unk1A |= 0x8000;
            cpu->unk8 = 20;
            cpu->unk2 = 1;
            break;
        }
        ContBtn[GwPlayer[player].port] = cpu->unk1A;
        ContBtnTrg[GwPlayer[player].port] = cpu->unk18;
        ContStkX[GwPlayer[player].port] = cpu->unk14;
        ContStkY[GwPlayer[player].port] = -cpu->unk16;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_MusicalMushroom/11C810", func_800F83BC_MusicalMushroom);
#endif
u8 func_800F8830_MusicalMushroom(u16 i) {
    omObjData* pobj = D_800F3FB0[i];
    MMPlayerWork* work = pobj->unk_50;
    s32 flags = func_80017A60(pobj);

    return work->unk_38 == 1000.0f && (flags & 6);
}
s32 func_800F8898_MusicalMushroom(u16 i, s32 bell) {
    omObjData* pobj = D_800F3FB0[i];
    MMPlayerWork* work = pobj->unk_50;
    s32 flags = func_80017A60(pobj);

    if (work->unk_38 == 1000.0f && (flags & 6) && !(work->unk_50 & 7)) {
        return 1;
    }
    return 0;
}

void func_800F8910_MusicalMushroom(omObjData* obj) {
    Vec3f v;
    Vec3f* p = &v;
    f32 angle;
    s32 player = obj->work[0];
    MMPlayerWork* work = obj->unk_50;

    func_800A0D00(p, obj->trans.x, 0.0f, obj->trans.z);
    p->x -= 0.0f;
    p->y -= 0.0f;
    p->z -= 475.0f;
    if (!func_800F8830_MusicalMushroom(player)) {
        angle = func_800B0CD8(p->x, p->z) + 20.0f;
        if (func_800A1200(p) > 650.0f) {
            angle = func_80029518(angle + 180.0f);
        }
        ContStkX[GwPlayer[player].port] = func_800AEAC0(angle) * 60.0f;
        ContStkY[GwPlayer[player].port] = -(func_800AEFD0(angle) * 60.0f);
    } else {
        u8 port;

        work->unk_40 = 0.0f;
        port = GwPlayer[player].port;
        ContStkY[port] = 0;
        ContStkX[port] = 0;
    }
}

// register allocation: obj/cpu in s1/s0 swapped (masked 0); tried declaration order, work before player, u8 player
#ifdef NON_MATCHING
void func_800F8AC4_MusicalMushroom(omObjData* obj) {
    void (*cpuFuncs[2])(omObjData*) = { func_800F7D1C_MusicalMushroom, func_800F83BC_MusicalMushroom };
    MMCpu* cpu;
    MMPlayerWork* work;
    s32 player;

    player = obj->work[0];
    work = obj->unk_50;
    cpu = &D_800FB6B8_MusicalMushroom[player];
    cpu->unk22 = ContBtn[GwPlayer[player].port];
    cpu->unk20 = ContBtnTrg[GwPlayer[player].port];
    cpu->unk1C = ContStkX[GwPlayer[player].port];
    cpu->unk1E = ContStkY[GwPlayer[player].port];
    switch (D_800ED430) {
    case 0:
        func_800F75D8_MusicalMushroom(obj);
        break;
    case 2:
        break;
    case 1:
        if (D_800FB650_MusicalMushroom == 0) {
            cpuFuncs[cpu->unk6](obj);
        } else {
            ContBtnTrg[GwPlayer[player].port] = 0;
            ContStkX[GwPlayer[player].port] = 0;
            ContStkY[GwPlayer[player].port] = 0;
            if (obj->work[1] == 0) {
                if (obj->work[2] == 1) {
                    work->unk_40 = 0.0f;
                } else {
                    func_800F8910_MusicalMushroom(obj);
                }
            }
        }
        func_80005A28(obj);
        ContBtn[GwPlayer[player].port] = cpu->unk22;
        ContBtnTrg[GwPlayer[player].port] = cpu->unk20;
        ContStkX[GwPlayer[player].port] = cpu->unk1C;
        ContStkY[GwPlayer[player].port] = cpu->unk1E;
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_MusicalMushroom/11C810", func_800F8AC4_MusicalMushroom);
#endif
// decomp-permuter
s32 func_800F8D20_MusicalMushroom(s32 i)
{
  Vec3f v;
  omObjData *pobj = D_800FB658_MusicalMushroom[i].obj;
  Vec3f *p = &v;
  s32 bell;
  s32 j;
  MMPlayerWork *work = pobj->unk_50;
  if ((bell = D_800FB6A4_MusicalMushroom) == i)
  {
    if (pobj->work[2] == 0)
    {
      pobj->work[2] = 1;
    }
    for (j = 0; j < D_800F2BC0; j++)
    {
      if ((j != bell) && (D_800FB658_MusicalMushroom[j].obj->work[1] == 0))
      {
        break;
      }
    }

    if (j < D_800F2BC0)
    {
      work->unk_40 = 0.0f;
      return 0;
    }
    return ((u8) func_800F8898_MusicalMushroom(i, bell)) != 0;
  }
  if ((work->unk_53 == 1) && (work->unk_38 == 1000.0f))
  {
    func_800A0D00(p, pobj->trans.x, 0.0f, pobj->trans.z);
    work->unk_3C = func_800B0CD8(p->x, p->z);
    func_800184BC(pobj, 6);
    work->unk_38 = -1.5f;
    work->unk_40 = D_800B8980 * 1.5f;
    return 0;
  }
  if (work->unk_53 == (-1))
  {
    return 0;
  }
  if (!((u8) func_800F8898_MusicalMushroom(i, bell)))
  {
    return 0;
  }
  if (!(func_80017A60(pobj) & 4))
  {
    return 1;
  }
  func_8006071C(work->unk_B3);
  func_800184BC(pobj, 0);
  func_80017DB0(pobj);
  return 1;
}

void func_800F8EE0_MusicalMushroom(omObjData* obj) {
    Vec3f d;
    Vec3f* p = &d;
    f32 y;
    f32 x;
    f32 z;
    f32 g;
    MMPlayerWork* work = obj->unk_50;
    omObjData* target = D_800F3FB0[D_800FB6A4_MusicalMushroom];

    switch (obj->work[1]) {
    case 0:
        break;
    case 1:
        if (--obj->work[2] == 0xFF) {
            p->x = target->trans.x - obj->trans.x;
            p->y = target->trans.y - obj->trans.y;
            p->z = target->trans.z - obj->trans.z;
            work->unk_3C = func_80029518(func_800B0CD8(p->x, p->z));
            work->unk_40 = 4.0f;
            work->unk_38 = -0.8f;
            func_800258EC(obj->model[0], 4, 0);
            obj->work[1] = 2;
        }
        break;
    case 2:
        x = obj->trans.x;
        y = obj->trans.y;
        z = obj->trans.z;
        D_800ED6B8 = D_800F5254 = 0.0f;
        x += func_800AEAC0(work->unk_3C) * work->unk_40;
        z += func_800AEFD0(work->unk_3C) * work->unk_40;
        if (work->unk_38 < 1000.0f) {
            g = work->unk_38;
            if (g > 2.0f) {
                g = 2.0f;
            }
            y += g * g * (work->unk_38 >= 0.0f ? -35.0f : 35.0f);
            work->unk_38 += D_800B8968;
        }
        obj->trans.x = x + D_800ED6B8;
        obj->trans.y = y;
        obj->trans.z = z + D_800F5254;
        obj->rot.y = work->unk_3C;
        obj->work[3]--;
        break;
    }
    if (obj->work[3] == 0) {
        PlaySound(0xFC);
        func_800258EC(obj->model[3], 4, 0);
        func_8001E2A8(work->unk_21[3], 0);
        func_8001E268(work->unk_21[3], 4, 4);
        func_80025798(obj->model[3], target->trans.x, target->trans.y, target->trans.z);
        func_80025830(obj->model[3], 5.0f, 5.0f, 5.0f);
        work->unk_54 = 0;
        func_800090D8(obj, 0, 0);
        func_800090D8(obj, 1, 0);
        obj->func_ptr = NULL;
    }
}
void func_800F91C8_MusicalMushroom(omObjData* obj) {
    Vec3f unused; /* frame space only */
    omObjData* pobj;
    s16 model;
    f32 frame;
    u8 player = obj->work[0];

    switch (obj->work[1]) {
    case 2:
        pobj = D_800F3FB0[player];
        func_8006BADC(D_800FB644_MusicalMushroom, pobj->trans.x, pobj->trans.y, pobj->trans.z);
        func_8006BAF0(D_800FB644_MusicalMushroom, 1);
        obj->work[1] = 3;
        break;
    case 3:
        model = D_800FB644_MusicalMushroom->model[0];
        frame = func_80025D18(model);
        if (func_80025D40(model) <= frame) {
            obj->work[2] = 10;
            obj->work[1] = 4;
        }
        break;
    case 4:
        if (obj->work[2] == 0) {
            func_800790C0();
            GMesCreate(2);
            obj->work[1] = 5;
        }
        obj->work[2]--;
        break;
    case 5:
        if (GMesStatAllGet() == 0 || (GMesStatAllGet() & 2)) {
            obj->work[1] = 6;
        }
        break;
    case 6:
        if (func_8006BAFC(D_800FB644_MusicalMushroom) == 0) {
            obj->work[1] = 7;
        }
        break;
    case 7:
        D_800FB640_MusicalMushroom = 1;
        break;
    }
}
void func_800F9338_MusicalMushroom(omObjData* obj) {
    Vec3f d;
    Vec3f* p = &d;
    f32 dist;
    f32 best;
    s32 i;
    s32 sel;
    s32 failed;
    omObjData* pobj;
    omObjData* o;
    MMPlayerWork* work;

    if (D_800FB6A4_MusicalMushroom == -1) {
        sel = -1;
        best = 10000.0f;
        for (i = 0; i < D_800F2BC0; i++) {
            o = D_800F3FB0[i];
            work = o->unk_50;
            p->x = D_800FB644_MusicalMushroom->trans.x - o->trans.x;
            p->y = D_800FB644_MusicalMushroom->trans.y - o->trans.y;
            p->z = D_800FB644_MusicalMushroom->trans.z - o->trans.z;
            dist = func_800A1200(p);
            if (dist <= work->unk_48 + 30.0f) {
                work->unk_38 = 0.5f;
                if (dist < best) {
                    best = dist;
                    sel = i;
                }
            }
        }
        if (sel != -1) {
            D_800FB6A4_MusicalMushroom = sel;
            o = D_800F3FB0[sel];
            work = o->unk_50;
            func_80060F04(work->unk_58, 20, 0, 20);
            obj->work[1] = 0;
        }
    } else {
        D_800FB650_MusicalMushroom = 1;
        switch (obj->work[1]) {
        case 0:
            D_800FB5A4_MusicalMushroom = 20.0f;
            D_800FB5A0_MusicalMushroom = D_800FB644_MusicalMushroom->trans.y;
            D_800F3FB0[D_800FB6A4_MusicalMushroom]->work[2] = 1;
            obj->work[1] = 1;
            break;
        case 1:
            if ((D_800FB644_MusicalMushroom->trans.y += D_800FB5A4_MusicalMushroom) < D_800FB5A0_MusicalMushroom) {
                D_800FB644_MusicalMushroom->trans.y = D_800FB5A0_MusicalMushroom;
                obj->work[1] = 2;
            }
            D_800FB5A4_MusicalMushroom -= 5.0f;
            break;
        case 2:
            failed = 0;
            for (i = 0; i < D_800F2BC0; i++) {
                pobj = D_800FB658_MusicalMushroom[i].obj;
                if (func_800F8D20_MusicalMushroom(i) != 0) {
                    pobj->work[1] = 1;
                } else {
                    failed = 1;
                }
            }
            if (failed == 0 || --D_800FB4C0_MusicalMushroom == 0) {
                obj->work[0] = (u8)D_800FB6A4_MusicalMushroom;
                obj->work[1] = 2;
                obj->work[2] = 0;
                obj->func_ptr = &func_800F91C8_MusicalMushroom;
                func_80009438();
            }
            break;
        }
    }
}