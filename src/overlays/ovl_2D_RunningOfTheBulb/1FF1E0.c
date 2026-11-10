#include "RunningOfTheBulb.h"

/* Shadow scale per character (x, z) and shadow offset/height (func_800F7B5C). */
f32 D_800FE240_RunningOfTheBulb[6][2] = {
    { 1.06f, 1.0f }, { 1.06f, 1.0f }, { 1.12f, 1.0f }, { 1.06f, 1.0f }, { 1.1f, 1.0f }, { 1.4f, 1.45f },
};
f32 D_800FE270_RunningOfTheBulb[6][2] = {
    { 120.0f, 70.0f }, { 120.0f, 70.0f }, { 120.0f, 60.0f }, { 120.0f, 70.0f }, { 120.0f, 50.0f }, { 130.0f, 30.0f },
};
/* Start positions: [0] the leading team, then the others in turn (D_800FE35C). */
Vec D_800FE2A0_RunningOfTheBulb[4] = {
    { 0.0f, 0.0f, 1900.0f }, { -150.0f, 0.0f, 2100.0f }, { 0.0f, 0.0f, 2100.0f }, { 150.0f, 0.0f, 2100.0f },
};
RotbDrop D_800FE2D0_RunningOfTheBulb[5] = {
    { 1700.0f, 1200.0f, 0.0f, 400.0f, 1100.0f, 400.0f, 0 },
    { 1300.0f, 800.0f, -200.0f, 400.0f, 200.0f, 400.0f, 0 },
    { 200.0f, -550.0f, 0.0f, 400.0f, -600.0f, 400.0f, 0 },
    { 200.0f, -550.0f, 160.0f, 400.0f, -600.0f, 400.0f, 0 },
    { -10000.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0 },
};
/* Next start position; retail reads its low half (lhu D_800FE35E) as well. */
s32 D_800FE35C_RunningOfTheBulb = 1;
s32 D_800FE360_RunningOfTheBulb = 0;
/* Goal points (x, z) per player at the end. */
f32 D_800FE364_RunningOfTheBulb[4][2] = {
    { -240.0f, -1640.0f }, { -80.0f, -1640.0f }, { 80.0f, -1640.0f }, { 240.0f, -1640.0f },
};
u16 D_800FE384_RunningOfTheBulb = 0;
f32 D_800FE388_RunningOfTheBulb = 0.0f;
f32 D_800FE38C_RunningOfTheBulb = 1.0f;
u16 D_800FE390_RunningOfTheBulb = 0;
f32 D_800FE394_RunningOfTheBulb = 0.0f;
f32 D_800FE398_RunningOfTheBulb = 1.0f;
u16 D_800FE39C_RunningOfTheBulb = 0;
u16 D_800FE3A0_RunningOfTheBulb[8] = { 0 };
char D_800FE3B0_RunningOfTheBulb[] = "00mt001s_IA44";
char D_800FE3C0_RunningOfTheBulb[] = "aura2_IA44";
char D_800FE3CC_RunningOfTheBulb[] = "";

void func_800F65E0_RunningOfTheBulb(void) {
    void* temp_s0;

    omInitObjMan(36, 0);
    func_80060088();
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    func_8001DE70(33);
    func_80029090(3);
    func_8002ADF0(&D_800EDEC0, 64);
    func_80009500();
    func_800FE090_RunningOfTheBulb(20.0f, 3100.0f, 324.0f, 45.0f, 0, -280.0f, 0, 1675.0f);
    func_80017660(0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    func_80023448(3);
    func_800234B8(0, 0, 0, 0);
    func_800234B8(1, 0, 0, 0);
    func_80023504(1, 0.0f, 100.0f, 0.0f);
    func_800234B8(2, 0xA0, 0x5A, 0xCA);
    func_80023504(2, -16.0f, 97.0f, -68.0f);
    func_800234B8(3, 0, 0, 0);
    func_80023504(3, 100.0f, 80.0f, 100.0f);
    func_8005D98C(0, 4);
    func_8005D98C(1, 4);
    func_8005D98C(2, 6);
    D_800FE49C_RunningOfTheBulb = func_8005DB44(1);
    D_800FE460_RunningOfTheBulb = func_8005DB44(0);
    D_800FE480_RunningOfTheBulb = func_8005DB44(2);
    omSetStatBit(omAddObj(0x64, 0, 0, -1, &func_800FE140_RunningOfTheBulb), 0xA0);
    omAddObj(10, 13, 38, 0, &func_800F7AEC_RunningOfTheBulb);
    omAddObj(10, 13, 38, 0, &func_800F7B08_RunningOfTheBulb);
    omAddObj(10, 13, 38, 0, &func_800F7B24_RunningOfTheBulb);
    omAddObj(10, 13, 38, 0, &func_800F7B40_RunningOfTheBulb);
    omAddObj(20, 3, 4, 1, &func_800F9724_RunningOfTheBulb);
    omAddObj(20, 3, 4, 1, &func_800F9724_RunningOfTheBulb);
    omAddObj(20, 3, 4, 1, &func_800F9724_RunningOfTheBulb);
    omAddObj(20, 3, 4, 1, &func_800F9724_RunningOfTheBulb);
    D_800FE478_RunningOfTheBulb = omAddObj(20, 6, 4, -1, &func_800FAB8C_RunningOfTheBulb);
    D_800FE4AC_RunningOfTheBulb = omAddObj(40, 2, 0, -1, &func_800FB28C_RunningOfTheBulb);
    D_800FE494_RunningOfTheBulb = omAddObj(42, 2, 0, -1, &func_800FB180_RunningOfTheBulb);
    D_800FE4C4_RunningOfTheBulb = omAddObj(45, 1, 0, -1, &func_800F6F04_RunningOfTheBulb);
    omAddObj(0, 0, 0, -1, &func_800F6AC0_RunningOfTheBulb);
    D_800FE470_RunningOfTheBulb[1] = omAddObj(6, 4, 0, -1, &func_800F6BE4_RunningOfTheBulb);
    D_800FE47C_RunningOfTheBulb = omAddObj(30, 0, 0, -1, &func_800F7034_RunningOfTheBulb);
    omAddObj(0x2710, 0, 0, -1, &func_800FBF30_RunningOfTheBulb);
    D_800FE4A8_RunningOfTheBulb = omAddObj(6, 0, 0, -1, NULL);
    temp_s0 = DataRead(38);
    D_800FE45A_RunningOfTheBulb = func_80039084(temp_s0);
    HuMemDirectFree(temp_s0);
    D_800FE458_RunningOfTheBulb = _CheckFlag(43);
    SetFadeInTypeAndTime(0, 16);
}

void func_800F6AC0_RunningOfTheBulb(omObjData* arg0) {
    s32 i;

    D_800FE464_RunningOfTheBulb = 0;
    D_800FE498_RunningOfTheBulb = 0;
    D_800FE490_RunningOfTheBulb = 0;
    D_800FE44A_RunningOfTheBulb = 0;
    
    for (i = 0; i < 4; i++) {
        D_800FE44C_RunningOfTheBulb[i] = 0;
    }
    
    D_800FE4B4_RunningOfTheBulb = 0;
    D_800ED430 = 0;
    arg0->func_ptr = &func_800F6B28_RunningOfTheBulb;
}

void func_800F6B28_RunningOfTheBulb(void) {
    switch (D_800FE464_RunningOfTheBulb) {
    case 0:
        if (D_800FE490_RunningOfTheBulb == NULL) {
            D_800FE490_RunningOfTheBulb = omAddObj(4, 0, 0, -1, &func_800FBAA4_RunningOfTheBulb);
            return;
        }
    case 1:
        return;
    case 2:
        if (D_800FE498_RunningOfTheBulb == NULL) {
            D_800FE498_RunningOfTheBulb = omAddObj(4, 0, 0, -1, &func_800FBB5C_RunningOfTheBulb);
        }
        break;
    }
}

void func_800F6BE4_RunningOfTheBulb(omObjData* arg0) {
    RotbFloorWork* temp_s0_2;
    RotbFloorWork* temp_s0_3;
    void* temp_s0;
    
    arg0->model[0] = LoadFormFile(0x410001, 0x289);
    temp_s0 = DataRead(0x27);
    func_80038A9C((&D_800F2B7C[arg0->model[0]])->unk_6C, temp_s0, 0, D_800FE3B0_RunningOfTheBulb);
    func_80025AD4(arg0->model[0]);
    func_80025B34(arg0->model[0]);
    HuMemDirectFree(temp_s0);
    arg0->model[3] = LoadFormFile(0x410002, 0x699);
    func_80025798(arg0->model[3], 0.0f, 1.0f, 0.0f);
    func_800090B8(D_800ED440);
    D_800F2AF8[D_800ED440++] = D_800FE4A8_RunningOfTheBulb;
    temp_s0_2 = func_80023684(sizeof(RotbFloorWork), 0x7918);
    D_800FE4A8_RunningOfTheBulb->unk_50 = temp_s0_2;
    func_8009B770(temp_s0_2, 0, sizeof(RotbFloorWork));
    temp_s0_2->unk_04 = 1;
    temp_s0_2->unk_05 = 1;
    func_80009000(D_800FE4A8_RunningOfTheBulb, 2, -1000.0f);
    D_800F2AF8[D_800ED440++] = arg0;
    temp_s0_3 = func_80023684(sizeof(RotbFloorWork), 0x7918);
    arg0->unk_50 = temp_s0_3;
    func_8009B770(temp_s0_3, 0, sizeof(RotbFloorWork));
    temp_s0_3->unk_04 = 1;
    temp_s0_3->unk_05 = 0;
    func_80009028(arg0, 0, -400.0f, -2500.0f, 400.0f, 2500.0f);
    temp_s0_3->unk_08 = 0.1f;
    arg0->work[0] = 1;
    arg0->func_ptr = &func_800F6DF4_RunningOfTheBulb;
}

void func_800F6DF4_RunningOfTheBulb(omObjData* arg0) {
    f32 temp_f2;

    if ((D_800FE464_RunningOfTheBulb != 0) && (arg0->work[0] == 1)) {
        temp_f2 = Center.z;
        if ((temp_f2 > -2150.0f)) {
            Center.z = temp_f2 + -2.186f;
        } else {
            arg0->work[0] = 0;
            func_8005DC18(D_800FE478_RunningOfTheBulb, 1);
        }
    }
}

void func_800F6E80_RunningOfTheBulb(omObjData* arg0) {
    f32 temp_f2;

    temp_f2 = Center.z;
    if ((temp_f2 > -2150.0f)) {
        Center.z = temp_f2 + -13.116001f;
    } else {
        arg0->work[0] = 0;
        func_8005DC18(D_800FE478_RunningOfTheBulb, 1);
        Center.z = -2150.0f;
    }
}

void func_800F6F04_RunningOfTheBulb(omObjData* arg0) {
    RotbFloorWork* temp_s0;

    arg0->model[0] = func_800174C0(0x41000A, 0x419);
    temp_s0 = func_80023684(sizeof(RotbFloorWork), 0x7918);
    arg0->unk_50 = temp_s0;
    func_8009B770(temp_s0, 0, sizeof(RotbFloorWork));
    temp_s0->unk_04 = 1;
    temp_s0->unk_05 = 2;
    D_800F2AF8[D_800ED440++] = arg0;
    omSetTra(arg0, 0.0f, 0.0f, Center.z + -935.0f);
    func_800258EC(arg0->model[0], 4, 4);
    func_80009090(arg0);
    arg0->func_ptr = &func_800F6FF4_RunningOfTheBulb;
}

void func_800F6FF4_RunningOfTheBulb(omObjData* arg0) {
    omSetTra(arg0, 0.0f, 0.0f, Center.z + -935.0f);
}

void func_800F7034_RunningOfTheBulb(omObjData* arg0) {
    RotbBlockList* list;
    RotbFloorWork* work;
    s32 i;

    list = arg0->unk_50 = func_80023684(sizeof(RotbBlockList), 0x7918);
    for (i = 0; i < 6; i++) {
        list->unk_04[i] = omAddObj(0x23, 2, 0, 2, NULL);
        D_800F2AF8[D_800ED440++] = list->unk_04[i];
        work = func_80023684(sizeof(RotbFloorWork), 0x7918);
        list->unk_04[i]->unk_50 = work;
        func_8009B770(list->unk_04[i]->unk_50, 0, sizeof(RotbFloorWork));
        work->unk_04 = 1;
        work->unk_05 = i + 4;
        func_80009058(list->unk_04[i], 160.0f, 160.0f, -80.0f, -80.0f, 80.0f, 80.0f);
        work->unk_08 = 0.5f;
        work->unk_28 = func_80023684(sizeof(RotbBlockExt), 0x7918);
        if (i == 0) {
            list->unk_04[0]->model[0] = LoadFormFile(0x410000, 0x20699);
            list->unk_04[0]->model[1] = LoadFormFile(0x10, 0x699);
        } else {
            list->unk_04[i]->model[0] = func_80023FC8(list->unk_04[0]->model[0]);
            list->unk_04[i]->model[1] = func_80023FC8(list->unk_04[0]->model[1]);
        }
        func_800258EC(list->unk_04[i]->model[0], 4, 4);
        func_800258EC(list->unk_04[i]->model[1], 4, 4);
        omSetTra(list->unk_04[i], 0.0f, 0.0f, 5000.0f);
    }
    list->unk_00 = 0;
    arg0->func_ptr = &func_800F7278_RunningOfTheBulb;
}
void func_800F7278_RunningOfTheBulb(omObjData* arg0) {
    RotbBlockList* list = D_800FE47C_RunningOfTheBulb->unk_50;
    s32 i;

    while (Center.z <= D_800FE2D0_RunningOfTheBulb[list->unk_00].unk_00) {
        for (i = 0; i < 6; i++) {
            if (list->unk_04[i]->func_ptr == NULL) {
                break;
            }
        }
        if (i != 6) {
            func_800F7364_RunningOfTheBulb(list->unk_00, i);
        }
        list->unk_00++;
    }
}
void func_800F7364_RunningOfTheBulb(u16 arg0, u16 arg1) {
    RotbDrop* drop = &D_800FE2D0_RunningOfTheBulb[arg0];
    omObjData* obj = ((RotbBlockList*)D_800FE47C_RunningOfTheBulb->unk_50)->unk_04[arg1];
    RotbBlockExt* ext = ROTB_FLOOR(obj)->unk_28;

    ext->unk_02 = drop->unk_18;
    ext->unk_06 = 50;
    ext->unk_08 = 7;
    ext->unk_04 = ext->unk_06;
    ext->unk_00 = arg1;
    ext->unk_10 = drop->unk_14;
    ext->unk_0C = 0.0f;
    ext->unk_14 = drop->unk_04;
    omSetTra(obj, drop->unk_08, drop->unk_0C, drop->unk_10);
    func_800258EC(obj->model[0], 4, 0);
    func_80025798(obj->model[1], drop->unk_08, 1.0f, drop->unk_10);
    func_80025830(obj->model[1], 1.0f, 1.0f, 1.0f);
    func_800258EC(obj->model[1], 4, 0);
    obj->func_ptr = &func_800F7478_RunningOfTheBulb;
}
void func_800F7478_RunningOfTheBulb(omObjData* arg0) {
    Vec pos;
    Vec2f scr;
    RotbBlockExt* ext;
    RotbPlayerExt* pext;
    omObjData* player;
    f32 oldY;
    f32 scale;
    s32 i;

    ext = ROTB_FLOOR(arg0)->unk_28;
    switch (ext->unk_02) {
    case 0:
        if (--ext->unk_04 == 0 && D_800FE464_RunningOfTheBulb != 2) {
            if (Center.z <= ext->unk_14) {
                ext->unk_02 = 1;
                ext->unk_0C = -40.0f;
            } else {
                ext->unk_04++;
            }
        }
        break;
    case 1:
        if (arg0->trans.y + ext->unk_0C <= 0.0f && Center.z != 0.0f) {
            omSetTra(arg0, arg0->trans.x, 0.0f, arg0->trans.z);
            ext->unk_02 = 2;
            ext->unk_04 = ext->unk_08;
            PlaySound(0x32C);
        } else {
            omSetTra(arg0, arg0->trans.x, arg0->trans.y + ext->unk_0C, arg0->trans.z);
        }
        break;
    case 2:
        if (--ext->unk_04 == 0) {
            ext->unk_02 = 3;
            ext->unk_0C = 15.0f;
        }
        break;
    case 3:
        oldY = arg0->trans.y;
        if (ext->unk_10 <= oldY + ext->unk_0C) {
            omSetTra(arg0, arg0->trans.x, ext->unk_10, arg0->trans.z);
            ext->unk_02 = 0;
            ext->unk_04 = ext->unk_06;
        } else {
            omSetTra(arg0, arg0->trans.x, arg0->trans.y + ext->unk_0C, arg0->trans.z);
        }
        for (i = 0; i < 4; i++) {
            player = D_800FE460_RunningOfTheBulb[i];
            pext = ROTB_PLAYER(player)->unk_E4;
            if (!(pext->unk_00 & 0x30) && pext->unk_28 == arg0) {
                player->trans.y = (arg0->trans.y - oldY) + player->trans.y;
            }
        }
        break;
    }
    scale = 1.0f - arg0->trans.y / 1000.0f;
    func_80025830(arg0->model[1], scale, 1.0f, scale);
    pos.x = arg0->trans.x;
    pos.y = arg0->trans.y;
    pos.z = arg0->trans.z;
    Convert3DTo2D(0, (Vec3f*)&pos, &scr);
    if (scr.x < -16.0f) {
        func_800258EC(arg0->model[0], 4, 4);
        func_800258EC(arg0->model[1], 4, 4);
        omSetTra(arg0, 0.0f, 0.0f, 5000.0f);
        arg0->func_ptr = NULL;
    }
}
omObjData* func_800F77B4_RunningOfTheBulb(omObjData* arg0) {
    Vec p0;
    Vec p1;
    Vec p2;
    Vec n;
    RotbPlayerWork* work;
    RotbPlayerExt* ext;
    RotbFloorWork* fw;
    RotbBlockExt* bext;
    omObjData* blk;
    f32 px;
    f32 py;
    f32 pz;
    f32 minX;
    f32 maxX;
    f32 minZ;
    f32 maxZ;
    f32 top;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 d;
    f32 ad;
    s32 i;

    work = arg0->unk_50;
    ext = work->unk_E4;
    px = arg0->trans.x;
    py = arg0->trans.y + work->unk_48;
    pz = arg0->trans.z;
    for (i = 0; i < 6; i++) {
        blk = D_800FE480_RunningOfTheBulb[i];
        if (blk->func_ptr != NULL) {
            fw = blk->unk_50;
            bext = fw->unk_28;
            minX = blk->trans.x + fw->unk_18;
            maxX = blk->trans.x + fw->unk_20;
            minZ = blk->trans.z + fw->unk_1C;
            maxZ = blk->trans.z + fw->unk_24;
            p0.x = minX;
            p0.y = top = (blk->trans.y + fw->unk_10) - fw->unk_14;
            p1.y = top;
            p2.y = top;
            p0.z = minZ;
            p1.x = maxX;
            p1.z = maxZ;
            p2.x = minX;
            p2.z = maxZ;
            func_800F7A0C_RunningOfTheBulb(&p0, &p1, &p2, &n);
            dx = p0.x - px;
            dy = p0.y - py;
            dz = p0.z - pz;
            d = dx * n.x + dy * n.y + dz * n.z;
            ad = fabsf(d);
            p1.x = px + d * n.x;
            p1.y = py + d * n.y;
            p1.z = pz + d * n.z;
            if (minX <= p1.x && p1.x <= maxX && minZ <= p1.z && p1.z <= maxZ && ad <= work->unk_48) {
                if (!(ext->unk_00 & 2)) {
                    arg0->trans.y -= ad;
                    if (bext->unk_0C < 0.0f) {
                        arg0->trans.y += bext->unk_0C;
                    }
                }
                return blk;
            }
        }
    }
    return NULL;
}
void func_800F7A0C_RunningOfTheBulb(Vec* arg0, Vec* arg1, Vec* arg2, Vec* arg3) {
    f32 temp_f10;
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f4;
    f32 temp_f6;
    f32 temp_f8;

    temp_f14 = arg1->x - arg0->x;
    temp_f12 = arg1->y - arg0->y;
    temp_f8 = arg1->z - arg0->z;
    temp_f10 = arg2->x - arg0->x;
    temp_f4 = arg2->y - arg0->y;
    temp_f6 = arg2->z - arg0->z;
    arg3->x = (temp_f12 * temp_f6) - (temp_f8 * temp_f4);
    arg3->y = (temp_f8 * temp_f10) - (temp_f14 * temp_f6);
    arg3->z = (temp_f14 * temp_f4) - (temp_f12 * temp_f10);
    temp_f14 = func_800B1750((arg3->x * arg3->x) + (arg3->y * arg3->y) + (arg3->z * arg3->z));
    arg3->x /= temp_f14;
    arg3->y /= temp_f14;
    arg3->z /= temp_f14;
}
void func_800F7AEC_RunningOfTheBulb(omObjData* arg0) {
    func_800F7B5C_RunningOfTheBulb(arg0, 0);
}

void func_800F7B08_RunningOfTheBulb(omObjData* arg0) {
    func_800F7B5C_RunningOfTheBulb(arg0, 1);
}

void func_800F7B24_RunningOfTheBulb(omObjData* arg0) {
    func_800F7B5C_RunningOfTheBulb(arg0, 2);
}

void func_800F7B40_RunningOfTheBulb(omObjData* arg0) {
    func_800F7B5C_RunningOfTheBulb(arg0, 3);
}

void func_800F7B5C_RunningOfTheBulb(omObjData* arg0, s32 arg1) {
    RotbPlayerWork* work;
    RotbPlayerExt* ext;
    s32 dir;
    s32 file0;
    u8 chr;
    s32 i;

    chr = GwPlayer[(u16)arg1].character;
    dir = D_800C59AC[chr].unk_00;
    file0 = D_800C59AC[chr].unk_04;
    func_8000979C(arg0, dir, file0, arg1, 0x20699, 0xA99);
    func_80008FF4(arg0, 40.0f);
    work = arg0->unk_50;
    work->unk_3C = 180.0f;
    work->unk_60 = 45.0f;
    work->unk_DC = func_800FB8EC_RunningOfTheBulb;
    work->unk_E4 = func_80023684(sizeof(RotbPlayerExt), 0x7918);
    work->unk_50 |= 0x200;
    ext = work->unk_E4;
    ext->unk_00 = 1;
    ext->unk_02 = arg1;
    ext->unk_28 = NULL;
    ext->unk_30 = NULL;
    ext->unk_2C = NULL;
    ext->unk_54 = 0;
    ext->unk_58 = 1.0f;
    if (D_800FE360_RunningOfTheBulb == 0) {
        arg0->model[3] = LoadFormFile(0x19, 0x68D);
        arg0->model[4] = LoadFormFile(0x1A, 0xA8D);
    } else {
        arg0->model[3] = func_80023FC8(D_800FE460_RunningOfTheBulb[0]->model[3]);
        arg0->model[4] = func_80023FC8(D_800FE460_RunningOfTheBulb[0]->model[4]);
    }
    func_800187D0(arg0, 0, dir, 1, 0);
    func_800187D0(arg0, 1, dir | 1, 1, 0);
    func_800187D0(arg0, 2, dir | 3, 1, 0);
    func_800187D0(arg0, 5, dir | 4, 0, 0);
    func_800187D0(arg0, 7, dir | 6, 1, 0x22);
    func_800187D0(arg0, 6, dir | 5, 1, 0x13);
    if (rand8() & 1) {
        func_800187D0(arg0, 0xD, dir | 0xF, 2, 0x18);
    } else {
        func_800187D0(arg0, 0xD, dir | 0x38, 2, 0x18);
    }
    if (rand8() & 1) {
        func_800187D0(arg0, 0xE, dir | 0x10, 1, 0x78);
    } else {
        func_800187D0(arg0, 0xE, dir | 0x3C, 1, 0x78);
    }
    func_800187D0(arg0, 0x11, dir | 0x18, 0, 0);
    func_800187D0(arg0, 0x16, dir | 0x24, 1, 0);
    func_800187D0(arg0, 0x15, dir | 0x62, 0, 0);
    func_800187D0(arg0, 0x20, dir | 0x67, 0, 0);
    func_800187D0(arg0, 0x23, dir | 0x52, 1, 0);
    func_800187D0(arg0, 0x24, dir | 0x5F, 2, 0);
    arg0->motion[0x25] = arg0->motion[1];
    work->unk_D8[0x25][0] = work->unk_D8[1][0];
    work->unk_D8[0x25][1] = work->unk_D8[1][1];
    func_800090C4(arg0, 0, 2);
    func_800090C4(arg0, 1, 2);
    func_800090C4(arg0, 2, 2);
    func_800090C4(arg0, 3, 2);
    for (i = 0; i < 6; i++) {
        func_800090C4(arg0, i + 4, 2);
    }
    if ((u32)dir >> 16 == 5) {
        arg0->scale.x = arg0->scale.y = arg0->scale.z = 0.95f;
    }
    if ((u32)dir >> 16 == 3) {
        arg0->scale.x = arg0->scale.y = arg0->scale.z = 1.1f;
    }
    D_800F3FB0[D_800F2BC0++] = arg0;
    arg0->model[9] = LoadFormFile(0x41000C, 0xA8D);
    if (D_800FE360_RunningOfTheBulb == 0) {
        D_800FE444_RunningOfTheBulb = DataRead(0x41000B);
    }
    ext->unk_36 = D_800FE440_RunningOfTheBulb = func_80038A9C(D_800F2B7C[arg0->model[9]].unk_6C, D_800FE444_RunningOfTheBulb, 0, D_800FE3C0_RunningOfTheBulb);
    func_80025930(arg0->model[9], 0x60000000, 0x20000000);
    func_80025AD4(arg0->model[9]);
    func_80025B34(arg0->model[9]);
    func_8003967C(D_800FE440_RunningOfTheBulb, 1);
    if (D_800FE360_RunningOfTheBulb == 3) {
        HuMemDirectFree(D_800FE444_RunningOfTheBulb);
    }
    D_800FE360_RunningOfTheBulb++;
    ext->unk_3C = D_800FE240_RunningOfTheBulb[chr][0];
    ext->unk_40 = D_800FE240_RunningOfTheBulb[chr][1];
    ext->unk_44 = D_800FE270_RunningOfTheBulb[chr][0];
    ext->unk_48 = D_800FE270_RunningOfTheBulb[chr][1];
    if (GwPlayer[(u16)arg1].group == 0) {
        omSetTra(arg0, D_800FE2A0_RunningOfTheBulb[0].x, D_800FE2A0_RunningOfTheBulb[0].y, D_800FE2A0_RunningOfTheBulb[0].z);
        func_80025798(arg0->model[1], D_800FE2A0_RunningOfTheBulb[0].x, D_800FE2A0_RunningOfTheBulb[0].y, D_800FE2A0_RunningOfTheBulb[0].z);
        ext->unk_14 = 1;
        ext->unk_16 = 1;
        D_800FE4A0_RunningOfTheBulb = arg0;
    } else {
        omSetTra(arg0, D_800FE2A0_RunningOfTheBulb[D_800FE35C_RunningOfTheBulb].x, D_800FE2A0_RunningOfTheBulb[D_800FE35C_RunningOfTheBulb].y, D_800FE2A0_RunningOfTheBulb[D_800FE35C_RunningOfTheBulb].z);
        func_80025798(arg0->model[1], D_800FE2A0_RunningOfTheBulb[D_800FE35C_RunningOfTheBulb].x, D_800FE2A0_RunningOfTheBulb[D_800FE35C_RunningOfTheBulb].y, D_800FE2A0_RunningOfTheBulb[D_800FE35C_RunningOfTheBulb].z);
        ext->unk_14 = (u16)D_800FE35C_RunningOfTheBulb - 1;
        ext->unk_16 = 1;
        D_800FE35C_RunningOfTheBulb++;
    }
    arg0->func_ptr = &func_800F8210_RunningOfTheBulb;
}
void func_800F8210_RunningOfTheBulb(omObjData* arg0) {
    u16 temp_s0;
    s32 temp_s1;
    s16 temp_s3;
    s16 temp_s4;
    s16* temp_s1_2;
    s16* temp_s2;
    s8 temp_s5;
    s8 temp_s6;
    s16* temp;

    if (D_800FE464_RunningOfTheBulb == 1) {
        arg0->func_ptr = &func_800F82F4_RunningOfTheBulb;
        return;
    }
    
    temp_s0 = ROTB_PLAYER(arg0)->unk_56;
    temp_s5 = ContStkX[temp_s0];
    temp_s6 = ContStkY[temp_s0];
    temp = ContBtnTrg;
    temp_s2 = &temp[temp_s0];
    temp_s4 = *temp_s2;
    temp_s1_2 = &ContBtn[temp_s0];
    temp_s3 = *temp_s1_2;
    func_80005A28(arg0);
    ContStkX[temp_s0] = temp_s5;
    ContStkY[temp_s0] = temp_s6;
    *temp_s2 = temp_s4;
    *temp_s1_2 = temp_s3;
}


// port read lb vs retail lbu+sign-extend, register allocation
#ifdef NON_MATCHING
void func_800F82F4_RunningOfTheBulb(omObjData* arg0) {
    RotbPlayerWork* work;
    RotbPlayerExt* ext;
    RotbPlayerWork* other;
    RotbBulbExt* bulb;
    omObjData* obj;
    u16* trgp;
    s16* btnp;
    f32 off;
    f32 height;
    f32 angle;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 d;
    f32 sy;
    s32 port;
    s16 i;
    u8 stkX;
    u8 stkY;
    u16 trg;
    u16 btn;

    work = arg0->unk_50;
    ext = work->unk_E4;
    port = work->unk_56;
    off = ext->unk_44;
    height = ext->unk_48;
    stkX = ContStkX[(u16)port];
    stkY = ContStkY[(u16)port];
    trgp = &ContBtnTrg[(u16)port];
    trg = *trgp;
    btnp = &ContBtn[(u16)port];
    btn = *btnp;
    if (D_800FE464_RunningOfTheBulb == 2) {
        *trgp = *btnp = ContStkX[(u16)port] = ContStkY[(u16)port] = 0;
        if (work->unk_38 != 1000.0f) {
            angle = func_800B0CD8(-arg0->trans.x, -arg0->trans.z);
            ContStkX[(u16)port] = func_800AEAC0(angle) * 80.0f;
            ContStkY[(u16)port] = -func_800AEFD0(angle) * 80.0f;
        } else if (!(ext->unk_00 & 0x80)) {
            ext->unk_00 |= 0x80;
            ContBtnTrg[(u16)port] = ContBtn[(u16)port] = ContStkX[(u16)port] = ContStkY[(u16)port] = 0;
        }
        func_80005A28(arg0);
    } else {
        if (work->unk_B1 != -1) {
            if (ext->unk_00 & 4) {
                if (ext->unk_00 & 0x40) {
                    func_800186E4(arg0, 1, 0x23);
                    if (func_80017A50(arg0) == 1) {
                        func_800185A4(arg0, 1);
                    }
                    ext->unk_00 &= ~0x40;
                }
                ext->unk_00 &= ~4;
                bulb = ROTB_BODY(ext->unk_2C)->unk_68.bulb;
                if (bulb->unk_00 & 8) {
                    bulb->unk_00 &= ~8;
                    other = D_800FE460_RunningOfTheBulb[work->unk_B1]->unk_50;
                    func_800FA44C_RunningOfTheBulb(ext->unk_2C, other->unk_3C);
                } else {
                    func_800FA44C_RunningOfTheBulb(ext->unk_2C, 1000.0f);
                }
                ext->unk_2C = NULL;
            }
            work->unk_B1 = -1;
        }
        if (ext->unk_00 & 0x10) {
            PlaySound(0x327);
            func_80060618(0x45F, ext->unk_02);
            func_80060F04(work->unk_58, 2, 2, 0x14);
            ext->unk_00 &= ~0x10;
            if (ext->unk_2C != NULL) {
                func_800FA44C_RunningOfTheBulb(ext->unk_2C, 1000.0f);
            }
            work->unk_40 = 0.0f;
            work->unk_38 = 1000.0f;
            func_80009E20(arg0);
            ext->unk_00 |= 0x20;
            func_800258EC(arg0->model[9], 4, 4);
            if (arg0 == D_800FE4A0_RunningOfTheBulb || (D_800FE458_RunningOfTheBulb != 0 && work->unk_58 == 0)) {
                func_800601D4(0x28);
                D_800FE464_RunningOfTheBulb = 2;
                D_800FE4A4_RunningOfTheBulb = 9;
                D_800FE470_RunningOfTheBulb[1]->work[0] = 0;
                D_800FE478_RunningOfTheBulb->func_ptr = &func_800FB0D8_RunningOfTheBulb;
                func_80009730();
                for (i = 0; i < 4; i++) {
                    if (GwPlayer[i].coins < 5) {
                        GwPlayer[i].coins_mg -= GwPlayer[i].coins;
                    } else {
                        GwPlayer[i].coins_mg -= 5;
                    }
                }
            }
            dx = D_800FE478_RunningOfTheBulb->trans.x - arg0->trans.x;
            dy = (D_800FE478_RunningOfTheBulb->trans.y + 300.0f) - arg0->trans.y;
            dz = (D_800FE478_RunningOfTheBulb->trans.z + 100.0f) - arg0->trans.z;
            d = func_800B1750(dx * dx + dy * dy + dz * dz) / 10.0f;
            ext->unk_5C = (D_800FE478_RunningOfTheBulb->trans.x - arg0->trans.x) / d;
            ext->unk_60 = ((D_800FE478_RunningOfTheBulb->trans.y + 300.0f) - arg0->trans.y) / d;
            ext->unk_64 = ((D_800FE478_RunningOfTheBulb->trans.z + 100.0f) - arg0->trans.z) / d;
            arg0->func_ptr = &func_800F8D80_RunningOfTheBulb;
            return;
        }
        if (ext->unk_00 & 4) {
            func_800FBF74_RunningOfTheBulb(arg0);
        } else if (GwPlayer[work->unk_58].flags & 1) {
            ContBtnTrg[(u16)port] = ContBtn[(u16)port] = ContStkX[(u16)port] = ContStkY[(u16)port] = 0;
            func_800FC0F4_RunningOfTheBulb(arg0);
        }
        if (work->unk_53 >= 0) {
            ext->unk_28 = D_800F2AF8[work->unk_53];
        }
        if (ext->unk_00 & 2) {
            sy = arg0->scale.y;
            if (sy < 0.7f) {
                sy = 0.7f;
            }
            func_80025830(arg0->model[9], arg0->scale.x * ext->unk_40, sy * ext->unk_3C, arg0->scale.z);
            if (!(work->unk_50 & 7)) {
                ext->unk_00 &= ~2;
                func_80025830(arg0->model[9], ext->unk_40, ext->unk_3C, 1.0f);
                for (i = 0; i < 6; i++) {
                    func_800090C4(arg0, i + 4, 2);
                }
            }
            off = 150.0f;
        }
        if (func_800F77B4_RunningOfTheBulb(arg0) != NULL) {
            if (work->unk_38 != 1000.0f) {
                if (work->unk_38 < 0.0f) {
                    work->unk_38 = -work->unk_38;
                }
            } else if (arg0->trans.y <= 0.0f && !(ext->unk_00 & 2)) {
                work->unk_50 |= 1;
                work->unk_9C = 0;
                arg0->trans.y = 0.0f;
                ext->unk_00 |= 2;
                for (i = 0; i < 6; i++) {
                    func_800090C4(arg0, i + 4, 1);
                }
                func_80060F04(work->unk_58, 2, 2, 0x14);
            }
        }
        if (ext->unk_00 & 8) {
            ContBtn[(u16)port] = ContBtnTrg[(u16)port] = ContStkX[(u16)port] = ContStkY[(u16)port] = 0;
        }
        func_80005A28(arg0);
        if (arg0->trans.y < 0.0f) {
            omSetTra(arg0, arg0->trans.x, 0.0f, arg0->trans.z);
        }
        /* Retail returns without restoring the controller when the round ends here. */
        if ((u16)func_800FDDC0_RunningOfTheBulb(arg0) == 1) {
            return;
        }
        if (D_800FE478_RunningOfTheBulb->trans.z - 200.0f <= arg0->trans.z && arg0->trans.y <= 550.0f) {
            ext->unk_00 |= 0x10;
        }
        if ((ext->unk_00 & 4) && ext->unk_2C != NULL) {
            if (!(ext->unk_00 & 8)) {
                if (ext->unk_38 < 1.0f) {
                    if ((ext->unk_38 += 0.15f) > 1.0f) {
                        ext->unk_38 = 1.0f;
                    }
                    func_80025830(arg0->model[9], ext->unk_38 * ext->unk_40, ext->unk_38 * ext->unk_3C, ext->unk_38);
                }
                omSetTra(ext->unk_2C, arg0->trans.x, arg0->trans.y + 100.0f, arg0->trans.z);
            }
            if (work->unk_54 != -1 && !(ext->unk_00 & 8)) {
                obj = D_800F3FB0[work->unk_54];
                if (obj == D_800FE4A0_RunningOfTheBulb) {
                    other = obj->unk_50;
                    if (!(other->unk_E4->unk_00 & 4)) {
                        func_8000A534(obj, 0.0f);
                        func_8000A6F4(D_800FE4A0_RunningOfTheBulb);
                        other->unk_50 &= ~0x20;
                        if (func_8000A634(arg0, D_800FE4AC_RunningOfTheBulb) == 1) {
                            func_80017D1C(arg0);
                        }
                        D_800FE4A0_RunningOfTheBulb = arg0;
                        func_800258EC(D_800FE4AC_RunningOfTheBulb->model[0], 4, 0);
                    }
                }
            }
        }
        func_80025798(arg0->model[9], func_800AEAC0(45.0f) * off + arg0->trans.x, height + arg0->trans.y, func_800AEFD0(45.0f) * off + arg0->trans.z);
    }
    ContStkX[(u16)port] = stkX;
    ContStkY[(u16)port] = stkY;
    ContBtnTrg[(u16)port] = trg;
    ContBtn[(u16)port] = btn;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2D_RunningOfTheBulb/1FF1E0", func_800F82F4_RunningOfTheBulb);
#endif
void func_800F8D80_RunningOfTheBulb(omObjData* arg0) {
    RotbPlayerExt* temp_s0;

    temp_s0 = ROTB_PLAYER(arg0)->unk_E4;
    temp_s0->unk_58 -= 0.05f;
    omSetSca(arg0, temp_s0->unk_58, temp_s0->unk_58, temp_s0->unk_58);
    omSetTra(arg0, arg0->trans.x + temp_s0->unk_5C, arg0->trans.y + temp_s0->unk_60, arg0->trans.z + temp_s0->unk_64);
    
    if (++temp_s0->unk_54 >= 20) {
        func_800258EC(arg0->model[0], 4, 4);
        func_800258EC(arg0->model[1], 4, 4);
        func_800258EC(arg0->model[9], 4, 4);
        if (arg0 == D_800FE4A0_RunningOfTheBulb) {
            func_800258EC(D_800FE4AC_RunningOfTheBulb->model[0], 4, 4);
        }
        arg0->func_ptr = NULL;
    }
}

void func_800F8EA0_RunningOfTheBulb(omObjData* arg0) {
    omObjData* temp_s1;
    f32 temp_f0;
    s16* temp_a0;
    s16* temp_v0_2;
    u16 temp_s0;
    u8 temp_s3;
    u8 temp_s4;
    u16 temp_s5;
    u16 temp_s6;
    RotbPlayerWork* temp_a1;
    s16* temp;

    temp_a1 = arg0->unk_50;
    if ((D_800FE470_RunningOfTheBulb[1])->work[0] == 0) {
        arg0->func_ptr = &func_800F9094_RunningOfTheBulb;
        return;
    }
    temp_s0 = temp_a1->unk_56;
    temp_s3 = ContStkX[temp_s0];
    temp_s4 = ContStkY[temp_s0];
    temp = ContBtn;
    temp_a0 = &temp[temp_s0];
    temp_s5 = *temp_a0;
    temp_v0_2 = &ContBtnTrg[temp_s0];
    temp_s6 = *temp_v0_2;
    *temp_v0_2 = 0;
    *temp_a0 = 0;
    ContStkY[temp_s0] = 0;
    ContStkX[temp_s0] = 0;
    
    if (arg0->trans.z > D_800FE364_RunningOfTheBulb[temp_a1->unk_58][1]) {
        temp_f0 = func_800FCEA0_RunningOfTheBulb(arg0, NULL, D_800FE364_RunningOfTheBulb[temp_a1->unk_58][0], D_800FE364_RunningOfTheBulb[temp_a1->unk_58][1], 40.0f, 190.0f);
        ContStkX[temp_s0] = (func_800AEAC0(temp_f0) * 80.0f);
        ContStkY[temp_s0] = (-func_800AEFD0(temp_f0) * 80.0f);
    }
    
    func_80005A28(arg0);
    ContStkX[temp_s0] = temp_s3;
    ContStkY[temp_s0] = temp_s4;
    ContBtn[temp_s0] = temp_s5;
    ContBtnTrg[temp_s0] = temp_s6;
}

// port read lb vs retail lbu+sign-extend, register allocation
#ifdef NON_MATCHING
void func_800F9094_RunningOfTheBulb(omObjData* arg0) {
    RotbPlayerWork* work;
    omObjData* other;
    s16* btnp;
    u16* trgp;
    f32 angle;
    s32 i;
    s32 port;
    u8 stkX;
    u8 stkY;
    u16 btn;
    u16 trg;

    work = arg0->unk_50;
    port = work->unk_56;
    stkX = ContStkX[(u16)port];
    stkY = ContStkY[(u16)port];
    btnp = &ContBtn[(u16)port];
    btn = *btnp;
    trgp = &ContBtnTrg[(u16)port];
    trg = *trgp;
    *btnp = *trgp = ContStkX[(u16)port] = ContStkY[(u16)port] = 0;
    switch (D_800FE384_RunningOfTheBulb) {
    case 0:
        if (arg0 == D_800FE4A0_RunningOfTheBulb) {
            angle = func_800B0CD8(0.0f - arg0->trans.x, -2235.0f - arg0->trans.z);
            if (angle < 0.0f) {
                angle += 360.0f;
            }
            if (work->unk_38 == 1000.0f) {
                if (work->unk_3C == angle) {
                    D_800FE384_RunningOfTheBulb = 1;
                    func_800186E4(arg0, 0x14, 0x24);
                    func_800185A4(arg0, 0x14);
                    func_80017DB0(arg0);
                    for (i = 0; i < 4; i++) {
                        other = D_800FE460_RunningOfTheBulb[i];
                        if (other != D_800FE4A0_RunningOfTheBulb) {
                            work = other->unk_50;
                            angle = func_800B0CD8(0.0f - other->trans.x, -2235.0f - other->trans.z);
                            if (angle < 0.0f) {
                                angle += 360.0f;
                            }
                            work->unk_3C = angle;
                        }
                    }
                    break;
                }
                goto set;
            } else {
                ContStkY[(u16)port] = 80;
            }
        } else if (arg0->trans.z <= -1770.0f && ROTB_PLAYER(D_800FE4A0_RunningOfTheBulb)->unk_38 != 1000.0f) {
            angle = func_800FCEA0_RunningOfTheBulb(arg0, NULL, D_800FE364_RunningOfTheBulb[work->unk_58][0], D_800FE364_RunningOfTheBulb[work->unk_58][1], 40.0f, 250.0f);
            ContStkX[(u16)port] = func_800AEAC0(angle) * 80.0f;
            ContStkY[(u16)port] = -func_800AEFD0(angle) * 80.0f;
        } else {
            goto turn;
        }
        break;
    case 1:
    turn:
        angle = func_800B0CD8(0.0f - arg0->trans.x, -2235.0f - arg0->trans.z);
        if (angle < 0.0f) {
            angle += 360.0f;
        }
    set:
        work->unk_3C = angle;
        break;
    }
    func_80005A28(arg0);
    ContStkX[(u16)port] = stkX;
    ContStkY[(u16)port] = stkY;
    ContBtn[(u16)port] = btn;
    ContBtnTrg[(u16)port] = trg;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2D_RunningOfTheBulb/1FF1E0", func_800F9094_RunningOfTheBulb);
#endif
void func_800F947C_RunningOfTheBulb(omObjData* arg0, f32 arg1) {
    RotbPlayerWork* work = arg0->unk_50;
    RotbPlayerExt* ext = work->unk_E4;

    ext->unk_4C = 10;
    func_800185A4(arg0, 1);
    arg1 -= work->unk_3C;
    if (arg1 < 0.0f) {
        arg1 += 360.0f;
    }
    if (!(arg1 < 180.0f)) {
        arg1 = -(360.0f - arg1);
    }
    arg1 /= 10.0f;
    ext->unk_50 = arg1;
    arg0->func_ptr = &func_800F9550_RunningOfTheBulb;
}
void func_800F9550_RunningOfTheBulb(omObjData* arg0) {
    RotbPlayerWork* work = arg0->unk_50;
    RotbPlayerExt* ext = work->unk_E4;

    func_80017DB0(arg0);
    work->unk_3C += ext->unk_50;
    func_8009ECB0(D_800F2B7C[arg0->model[0]].unk7C, 0.0f, work->unk_3C, 0.0f);
    if (--ext->unk_4C == 0) {
        ext->unk_00 |= 0x100;
        func_800184BC(arg0, 0);
        func_80017DB0(arg0);
        arg0->func_ptr = NULL;
    }
}
void func_800F960C_RunningOfTheBulb(omObjData* arg0) {
    func_800258EC(arg0->model[9], 4, 4);
    func_80017DB0(arg0);
}
void func_800F9648_RunningOfTheBulb(omObjData* arg0) {
}

// retail reloads the player pointer and flags and shares one n++ with a hoisted 2 (raw 18, masked 11); tried continue, one || test (hoists the 2 but CSEs the reloads) (M1c)
#ifdef NON_MATCHING
u16 func_800F9650_RunningOfTheBulb(void) {
    RotbPlayerWork* work;
    RotbPlayerExt* ext;
    s32 n;
    s32 i;

    n = 0;
    for (i = 0; i < 4; i++) {
        work = D_800FE460_RunningOfTheBulb[i]->unk_50;
        ext = work->unk_E4;
        if (ext->unk_00 & 0x30) {
            n++;
        } else if (work->unk_38 == 1000.0f && (ext->unk_00 & 0x80) && func_80017A60(D_800FE460_RunningOfTheBulb[i]) == 2) {
            n++;
        }
    }
    return (u16)n == 4;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2D_RunningOfTheBulb/1FF1E0", func_800F9650_RunningOfTheBulb);
#endif
void func_800F9724_RunningOfTheBulb(omObjData* arg0) {
    RotbBodyWork* body;
    RotbBulbExt* ext;
    u16 sprite;

    arg0->model[0] = LoadFormFile(0x410006, 0xA89);
    arg0->model[2] = LoadFormFile(6, 0x689);
    func_80021240(arg0->model[0]);
    func_80021240(arg0->model[2]);
    body = func_80023684(sizeof(RotbBodyWork), 0x7918);
    arg0->unk_50 = body;
    body->unk_68.bulb = func_80023684(sizeof(RotbBulbExt), 0x7918);
    body->unk_44 = 0.1f;
    body->unk_48 = 70.0f;
    body->unk_34 = 0.0f;
    body->unk_3C = 0.0f;
    body->unk_5C = 0;
    body->unk_52 = 7;
    body->unk_60 = 0.0f;
    body->unk_50 = 0x40;
    body->unk_54 = 1;
    body->unk_38 = 1000.0f;
    body->unk_40 = 6.0f;
    func_800F98F0_RunningOfTheBulb(arg0);
    ext = body->unk_68.bulb;
    sprite = func_8001E00C((void*)-1, 0x69D, 8);
    ext->unk_40 = sprite;
    D_800ECDE0[(s16)sprite].unk_02 = D_800FE45A_RunningOfTheBulb;
    func_80025930(ext->unk_42 = D_800ECDE0[ext->unk_40].unk_00, 0x70000000, 0x70000000);
    func_80025830(ext->unk_42, 2.0f, 2.0f, 2.0f);
    func_8001E268(ext->unk_40, 1, 1);
    D_800EDE70[D_800EE984++] = arg0;
    arg0->func_ptr = &func_800F9C2C_RunningOfTheBulb;
}
// mul.s operand order in s * dist (raw 1, masked 0); tried inline call both orders, *= then += (M1c)
#ifdef NON_MATCHING
void func_800F98F0_RunningOfTheBulb(omObjData* arg0) {
    RotbBulbExt* ext;
    f32 z;
    f32 dist;
    f32 angle;
    f32 s;
    f32 xs;
    f32 y;
    u8 r;

    ext = ROTB_BODY(arg0)->unk_68.bulb;
    ext->unk_00 = 1;
    ext->unk_08 = NULL;
    ext->unk_0C = 0;
    ext->unk_10 = 0;
    ext->unk_14 = NULL;
    ext->unk_02 = 0;
    ext->unk_1C = 0.0f;
    ext->unk_20 = 0.0f;
    ext->unk_24 = ext->unk_28 = ext->unk_20;
    z = D_800FE4A0_RunningOfTheBulb->trans.z;
    r = rand8();
    dist = r + rand8();
    dist = func_8009B618(dist, 1000.0);
    if (dist < 1100.0f) {
        dist = 1100.0f;
    }
    r = rand8();
    angle = r + rand8();
    angle = func_8009B618(angle, 180.0) + 90.0;
    s = func_800AEFD0(angle);
    xs = s * (u8)(rand8() % 100);
    if (xs < 0.0f) {
        xs += -450.0f;
    } else {
        xs += 650.0f;
    }
    s = func_800AEAC0(angle);
    dist = s * dist + z;
    if (D_800FE478_RunningOfTheBulb->trans.z - 200.0f < dist) {
        dist = D_800FE478_RunningOfTheBulb->trans.z - 1000.0f;
    }
    rand8();
    y = (u8)(rand8() % 10) + 120.0f;
    func_800211BC(arg0->model[0], 0x10);
    func_800211BC(arg0->model[2], 0xEF);
    ext->unk_04 = 0x10;
    ext->unk_2C = ext->unk_30 = ext->unk_34 = 0.0f;
    omSetTra(arg0, xs, y, dist);
    omSetSca(arg0, 1.0f, 1.0f, 1.0f);
    func_800FA36C_RunningOfTheBulb(arg0);
    func_800258EC(arg0->model[0], 4, 0);
    func_800258EC(arg0->model[2], 4, 0);
    func_8009ECB0(D_800F2B7C[arg0->model[0]].unk7C, 0.0f, ext->unk_20, 0.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2D_RunningOfTheBulb/1FF1E0", func_800F98F0_RunningOfTheBulb);
#endif
// CSE of 360-d and fabs register allocation
#ifdef NON_MATCHING
void func_800F9C2C_RunningOfTheBulb(omObjData* arg0) {
    f32 dist;
    RotbBodyWork* body;
    RotbBulbExt* ext;
    RotbPlayerExt* pext;
    omObjData* target;
    f32 tx;
    f32 ty;
    f32 tz;
    f32 d;
    f32 step;
    f32 vx;
    f32 vy;
    f32 vz;
    f64 dd;

    body = arg0->unk_50;
    ext = body->unk_68.bulb;
    if (D_800FE464_RunningOfTheBulb == 2 && D_800FE44A_RunningOfTheBulb == 1) {
        return;
    }
    if (!(ext->unk_00 & 2)) {
        target = func_800FDCAC_RunningOfTheBulb(arg0, &dist);
        if (target != NULL) {
            tx = target->trans.x;
            ty = target->trans.y + 100.0f;
            tz = target->trans.z;
        } else {
            tx = 0.0f;
            ty = 100.0f;
            tz = Center.z;
            dist = func_800B1750((tx - arg0->trans.x) * (tx - arg0->trans.x) + (ty - arg0->trans.y) * (ty - arg0->trans.y) + (tz - arg0->trans.z) * (tz - arg0->trans.z));
        }
        tz = func_800B0CD8(tx - arg0->trans.x, tz - arg0->trans.z);
        if (tz < 0.0f) {
            tz += 360.0f;
        }
        if (tz != ext->unk_20) {
            d = tz - ext->unk_20;
            if (d < 0.0f) {
                d += 360.0f;
            }
            if (d < 180.0f) {
                if (d > 2.0f) {
                    ext->unk_20 = ext->unk_20 + 2.0f;
                } else {
                    ext->unk_20 = d + ext->unk_20;
                }
            } else {
                step = 2.0f;
                if (!(360.0f - d > step)) {
                    step = 360.0f - d;
                }
                ext->unk_20 = ext->unk_20 - step;
            }
        }
        if (ext->unk_20 < 0.0f) {
            ext->unk_20 += 360.0f;
        }
        if (ext->unk_20 >= 360.0f) {
            ext->unk_20 -= 360.0f;
        }
        func_8009ECB0(D_800F2B7C[arg0->model[0]].unk7C, 0.0f, ext->unk_20, 0.0f);
        vx = func_800AEAC0(ext->unk_20) * body->unk_40;
        vz = func_800AEFD0(ext->unk_20) * body->unk_40;
        if (ty < arg0->trans.y) {
            vy = -body->unk_40 / 3.0f;
        } else {
            vy = body->unk_40 / 3.0f;
        }
        ext->unk_1C += 8.0f;
        if (ext->unk_1C >= 360.0f) {
            ext->unk_1C -= 360.0f;
        }
        omSetTra(arg0, vx + arg0->trans.x, vy + arg0->trans.y, vz + arg0->trans.z);
        func_800FA36C_RunningOfTheBulb(arg0);
        if (func_800FAA40_RunningOfTheBulb(arg0) == 0) {
            func_800FA5B8_RunningOfTheBulb(ext);
            return;
        }
        if (!(ext->unk_00 & 0x20)) {
            PlaySound(0x329);
            ext->unk_00 |= 0x20;
        }
    } else if (ext->unk_00 & 8) {
        if (ext->unk_02 == 0) {
            ext->unk_00 &= ~8;
            pext = ROTB_PLAYER(ext->unk_14)->unk_E4;
            pext->unk_00 &= ~8;
            omSetTra(arg0, 0.0f, 0.0f, 5000.0f);
            func_800258EC(arg0->model[0], 4, 4);
            func_800258EC(arg0->model[2], 4, 4);
            func_800258EC(ext->unk_14->model[9], 4, 0);
            func_80025830(ext->unk_14->model[9], pext->unk_40, pext->unk_3C, 1.0f);
            pext->unk_38 = 0.1f;
            return;
        }
        tx = ext->unk_14->trans.x;
        ty = ext->unk_14->trans.y + 100.0f;
        tz = ext->unk_14->trans.z;
        if (func_800B1750((tx - arg0->trans.x) * (tx - arg0->trans.x) + (ty - arg0->trans.y) * (ty - arg0->trans.y) + (tz - arg0->trans.z) * (tz - arg0->trans.z)) >= 10.0f) {
            vx = vy = vz = 0.0f;
            if (tx != arg0->trans.x || tz != arg0->trans.z) {
                tz = func_800B0CD8(tx - arg0->trans.x, tz - arg0->trans.z);
                vx = func_800AEAC0(tz) * body->unk_40;
                vz = func_800AEFD0(tz) * body->unk_40;
            }
            if (ty < arg0->trans.y) {
                dd = fabs(ty - arg0->trans.y);
                if (dd < body->unk_40) {
                    vy = vy - dd;
                } else {
                    vy = vy - body->unk_40;
                }
            } else if (arg0->trans.y < ty) {
                dd = fabs(ty - arg0->trans.y);
                if (dd < body->unk_40) {
                    vy = vy + dd;
                } else {
                    vy = vy + body->unk_40;
                }
            }
            omSetTra(arg0, vx + arg0->trans.x, vy + arg0->trans.y, vz + arg0->trans.z);
        }
        ext->unk_04 = (10 - ext->unk_02) * 23 + 16;
        func_800211BC(arg0->model[0], ext->unk_04);
        func_800211BC(arg0->model[2], ext->unk_04);
        ext->unk_02--;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2D_RunningOfTheBulb/1FF1E0", func_800F9C2C_RunningOfTheBulb);
#endif
void func_800FA2B8_RunningOfTheBulb(omObjData* arg0) {
    RotbBulbExt* temp = ROTB_BODY(arg0)->unk_68.bulb;

    if (arg0->trans.z > -1600.0f) {
        temp->unk_20 = 180.0f;
        func_8009ECB0(D_800F2B7C[arg0->model[0]].unk7C, 0.0f, 180.0f, 0.0f);
        arg0->trans.z += -13.116001f;
        return;
    }
    arg0->func_ptr = NULL;
}

void func_800FA36C_RunningOfTheBulb(omObjData* arg0) {
    f32 var_f20 = 2.0f - ((arg0->trans.y - 100.0f) / 240.0f);
    
    if (var_f20 < 1.0f) {
        var_f20 = 1.0f;
    }
    
    func_80025798(arg0->model[2], arg0->trans.x, 2.0f, arg0->trans.z);
    func_80025830(arg0->model[2], var_f20, 2.0f, var_f20);
}

void func_800FA41C_RunningOfTheBulb(omObjData* arg0) {
    RotbBulbExt* temp_v1;

    temp_v1 = ROTB_BODY(arg0)->unk_68.bulb;
    temp_v1->unk_00 |= 0x0A;
    temp_v1->unk_02 = 0xA;
    temp_v1->unk_18 = 1.0f;
}

void func_800FA44C_RunningOfTheBulb(omObjData* arg0, f32 arg1) {
    RotbBulbExt* ext;
    RotbPlayerExt* pext;

    ext = ROTB_BODY(arg0)->unk_68.bulb;
    if (ext->unk_00 & 2) {
        pext = ROTB_PLAYER(ext->unk_14)->unk_E4;
        if (pext->unk_00 & 0x40) {
            func_800186E4(ext->unk_14, 1, 0x23);
            if (func_80017A50(ext->unk_14) == 1) {
                func_800185A4(ext->unk_14, 1);
            }
            pext->unk_00 &= ~0x40;
        }
        pext->unk_00 &= ~0xC;
        func_800258EC(ext->unk_14->model[9], 4, 4);
    }
    func_800FA5B8_RunningOfTheBulb(ext);
    if (arg1 == 1000.0f) {
        func_800F98F0_RunningOfTheBulb(arg0);
        return;
    }
    ext->unk_24 = func_800AEAC0(arg1);
    ext->unk_28 = func_800AEFD0(arg1);
    ext->unk_02 = 30;
    ext->unk_00 |= 0x10;
    if (ext->unk_20 < 0.0f) {
        ext->unk_20 += 360.0f;
    }
    arg0->func_ptr = &func_800FA5EC_RunningOfTheBulb;
}
void func_800FA5B8_RunningOfTheBulb(RotbBulbExt* arg0) {
    if (arg0->unk_08 != NULL) {
        arg0->unk_00 = (u16) (arg0->unk_00 & 0xFFFB);
        ROTB_PLAYER(arg0->unk_08)->unk_E4->unk_30 = NULL;
        arg0->unk_08 = NULL;
    }
}

void func_800FA5EC_RunningOfTheBulb(omObjData* arg0) {
    RotbBulbExt* ext;

    ext = ROTB_BODY(arg0)->unk_68.bulb;
    if (ext->unk_02 == 0) {
        ext->unk_00 &= ~0x10;
        func_800F98F0_RunningOfTheBulb(arg0);
        if (D_800FE464_RunningOfTheBulb == 2 && D_800FE44A_RunningOfTheBulb == 1) {
            arg0->func_ptr = NULL;
        } else {
            arg0->func_ptr = &func_800F9C2C_RunningOfTheBulb;
        }
        return;
    }
    ext->unk_02--;
    omSetTra(arg0, ext->unk_24 * 30.0f + arg0->trans.x, arg0->trans.y, ext->unk_28 * 30.0f + arg0->trans.z);
    func_800FA36C_RunningOfTheBulb(arg0);
    ext->unk_04 += 10;
    if (ext->unk_04 >= 0x100) {
        ext->unk_04 = 0xFF;
        ext->unk_02 = 0;
    }
    func_800211BC(arg0->model[0], ext->unk_04);
    func_800211BC(arg0->model[2], ext->unk_04);
    ext->unk_20 += 16.0f;
    if (ext->unk_20 >= 360.0f) {
        ext->unk_20 -= 360.0f;
    }
    func_8009ECB0(D_800F2B7C[arg0->model[0]].unk7C, -ext->unk_20, ext->unk_20, -ext->unk_20);
}
void func_800FA78C_RunningOfTheBulb(omObjData* arg0) {
    RotbBulbExt* ext;
    f32 sx;
    f32 sy;

    ext = ROTB_BODY(arg0)->unk_68.bulb;
    if (ext->unk_02 == 45) {
        omSetSca(arg0, 1.0f, 1.0f, 1.0f);
    }
    if (ext->unk_02 >= 45) {
        omSetSca(arg0, ext->unk_38, ext->unk_38, ext->unk_38);
        if (ext->unk_02 & 1) {
            ext->unk_38 -= 0.1f;
        } else {
            ext->unk_38 += 0.040000003f;
        }
    } else {
        sx = (1.0f - func_800AEFD0(ext->unk_3C) / 2.0f) * ext->unk_38;
        sy = (1.0f - func_800AEAC0(ext->unk_3C) / 2.0f) * ext->unk_38;
        omSetSca(arg0, sx, sy, (1.0f - func_800AEFD0(ext->unk_3C) / 2.0f) * ext->unk_38);
    }
    if (++ext->unk_02 >= 75) {
        func_800258EC(arg0->model[0], 4, 4);
        func_800258EC(arg0->model[2], 4, 4);
        func_80025798(ext->unk_42, arg0->trans.x, arg0->trans.y - 120.0f, arg0->trans.z);
        func_800258EC(ext->unk_42, 4, 0);
        func_8001E268(ext->unk_40, 5, 4);
        func_8001E2A8(ext->unk_40, 0);
        arg0->func_ptr = NULL;
    }
    ext->unk_04 = func_800AEAC0(ext->unk_3C) * 16.0f + 16.0f;
    func_800211BC(arg0->model[0], ext->unk_04);
    func_800211BC(arg0->model[2], ext->unk_04);
    ext->unk_3C += 24.0f;
    if (ext->unk_3C >= 360.0f) {
        ext->unk_3C -= 360.0f;
    }
}
u16 func_800FAA40_RunningOfTheBulb(omObjData* arg0) {
    Vec pos;
    Vec2f scr;

    if (arg0->trans.x >= 382.5f || arg0->trans.x <= -382.5f) {
        return 0;
    }
    if (D_800FE478_RunningOfTheBulb->trans.z - 200.0f <= arg0->trans.z || arg0->trans.z <= -2482.5f) {
        return 0;
    }
    pos.x = arg0->trans.x;
    pos.y = arg0->trans.y;
    pos.z = arg0->trans.z;
    Convert3DTo2D(0, (Vec3f*)&pos, &scr);
    if (scr.x < 16.0f || scr.x > 304.0f || scr.y < 16.0f || scr.y > 224.0f) {
        return 0;
    }
    return 1;
}
void func_800FAB8C_RunningOfTheBulb(omObjData* arg0) {
    RotbBodyWork* body;
    RotbBossExt* ext;
    u16 sprite;

    arg0->model[0] = LoadFormFile(0x410008, 0x1899);
    body = func_80023684(sizeof(RotbBodyWork), 0x7918);
    arg0->unk_50 = body;
    body->unk_44 = 0.1f;
    body->unk_48 = 150.0f;
    body->unk_34 = 0.0f;
    body->unk_3C = 0.0f;
    body->unk_5C = 0;
    body->unk_52 = 7;
    body->unk_60 = 0.0f;
    body->unk_50 = 0x40;
    body->unk_54 = 1;
    body->unk_38 = 1000.0f;
    body->unk_40 = -2.186f;
    ext = func_80023684(sizeof(RotbBossExt), 0x7918);
    body->unk_68.boss = ext;
    sprite = func_8001E00C((void*)-1, 0x69D, 8);
    ext->unk_00 = sprite;
    D_800ECDE0[(s16)sprite].unk_02 = D_800FE45A_RunningOfTheBulb;
    func_80025930(ext->unk_02 = D_800ECDE0[ext->unk_00].unk_00, 0x70000000, 0x70000000);
    func_80025830(ext->unk_02, 4.0f, 4.0f, 4.0f);
    func_8001E268(ext->unk_00, 1, 1);
    omSetTra(arg0, 0.0f, 0.0f, 2500.0f);
    func_80025EB4(arg0->model[0], 2, 2);
    D_800EDE70[D_800EE984++] = arg0;
    arg0->work[0] = 1;
    arg0->func_ptr = &func_800FAD68_RunningOfTheBulb;
}
void func_800FAD68_RunningOfTheBulb(omObjData* arg0) {
    RotbBodyWork* body;
    s32 hit;
    s32 w;

    if (D_800FE464_RunningOfTheBulb != 0) {
        hit = arg0->unk_10;
        if (hit != 0) {
            arg0->unk_10 = 0;
            if (hit == 1) {
                arg0->work[0] = 0;
            }
        }
        body = arg0->unk_50;
        w = arg0->work[0];
        if (w == 1) {
            if (D_800FE464_RunningOfTheBulb == w) {
                omSetTra(arg0, arg0->trans.x, arg0->trans.y, arg0->trans.z + body->unk_40);
            } else {
                omSetTra(arg0, arg0->trans.x, arg0->trans.y, body->unk_40 * 6.0f + arg0->trans.z);
            }
        }
    }
}
void func_800FAE18_RunningOfTheBulb(omObjData* arg0) {
    RotbBodyWork* body;
    RotbBossExt* ext;
    s32 hit;
    f32 sx;
    f32 sy;

    hit = arg0->unk_10;
    if (hit != 0) {
        arg0->unk_10 = 0;
        if (hit == 1) {
            arg0->work[0] = 0;
        }
    }
    body = arg0->unk_50;
    ext = body->unk_68.boss;
    if (arg0->work[0] == 1) {
        omSetTra(arg0, arg0->trans.x, arg0->trans.y, arg0->trans.z + body->unk_40);
    }
    if (D_800FE390_RunningOfTheBulb == 45) {
        omSetSca(arg0, 1.0f, 1.0f, 1.0f);
    }
    if (D_800FE390_RunningOfTheBulb >= 45) {
        omSetSca(arg0, D_800FE38C_RunningOfTheBulb, D_800FE38C_RunningOfTheBulb, D_800FE38C_RunningOfTheBulb);
        if (D_800FE390_RunningOfTheBulb & 1) {
            D_800FE38C_RunningOfTheBulb -= 0.1f;
        } else {
            D_800FE38C_RunningOfTheBulb += 0.040000003f;
        }
    } else {
        sx = (1.0f - func_800AEFD0(D_800FE388_RunningOfTheBulb) / 2.0f) * D_800FE38C_RunningOfTheBulb;
        sy = (1.0f - func_800AEAC0(D_800FE388_RunningOfTheBulb) / 2.0f) * D_800FE38C_RunningOfTheBulb;
        omSetSca(arg0, sx, sy, (1.0f - func_800AEFD0(D_800FE388_RunningOfTheBulb) / 2.0f) * D_800FE38C_RunningOfTheBulb);
    }
    if (++D_800FE390_RunningOfTheBulb >= 75) {
        func_800258EC(arg0->model[0], 4, 4);
        arg0->func_ptr = NULL;
        D_800FE4A4_RunningOfTheBulb = 2;
        func_80025798(ext->unk_02, arg0->trans.x, arg0->trans.y - 120.0f, arg0->trans.z);
        func_800258EC(ext->unk_02, 4, 0);
        func_8001E268(ext->unk_00, 5, 4);
        func_8001E2A8(ext->unk_00, 0);
        PlaySound(0x333);
    }
    D_800FE388_RunningOfTheBulb += 24.0f;
    if (D_800FE388_RunningOfTheBulb >= 360.0f) {
        D_800FE388_RunningOfTheBulb -= 360.0f;
    }
}
void func_800FB0D8_RunningOfTheBulb(omObjData* arg0) {
    omSetSca(arg0, arg0->scale.x, D_800FE398_RunningOfTheBulb = func_800AEAC0(D_800FE394_RunningOfTheBulb) * 0.3f + 1.0f, arg0->scale.z);
    D_800FE394_RunningOfTheBulb = func_8009B618(D_800FE394_RunningOfTheBulb += 10.0f, 360.0);
}
void func_800FB180_RunningOfTheBulb(omObjData* arg0) {
    RotbFloorWork* work;

    arg0->model[0] = -1;
    arg0->model[1] = LoadFormFile(0x410004, 0x699);
    D_800F2AF8[D_800ED440++] = arg0;
    work = func_80023684(sizeof(RotbFloorWork), 0x7918);
    arg0->unk_50 = work;
    func_8009B770(work, 0, sizeof(RotbFloorWork));
    work->unk_04 = 1;
    work->unk_05 = 3;
    func_80009058(arg0, 1000.0f, 1000.0f, -400.0f, -450.0f, 400.0f, 500.0f);
    omSetTra(arg0, 0.0f, 0.0f, -2500.0f);
    func_80009090(arg0);
    arg0->func_ptr = NULL;
}
void func_800FB28C_RunningOfTheBulb(omObjData* arg0) {
    RotbBodyWork* body;
    RotbJumpExt* ext;

    arg0->model[0] = LoadFormFile(0x410003, 0x689);
    arg0->model[1] = LoadFormFile(0x41000D, 0x1A8D);
    body = func_80023684(sizeof(RotbBodyWork), 0x7918);
    arg0->unk_50 = body;
    ext = func_80023684(sizeof(RotbJumpExt), 0x7918);
    body->unk_68.jump = ext;
    body->unk_44 = 0.1f;
    body->unk_48 = 30.0f;
    body->unk_34 = 50.0f;
    body->unk_3C = 0.0f;
    body->unk_5C = 0;
    body->unk_38 = 1000.0f;
    body->unk_52 = 3;
    body->unk_60 = 0.0f;
    body->unk_4C = 0.5f;
    body->unk_50 = 0x40;
    body->unk_54 = 1;
    body->unk_58 = 0.8f;
    body->unk_40 = 0.0f;
    ext->unk_00 = 0.0f;
    ext->unk_04 = ext->unk_08 = ext->unk_0C = ext->unk_00;
    D_800EDE70[D_800EE984++] = arg0;
    omSetTra(arg0, D_800FE4A0_RunningOfTheBulb->trans.x, D_800FE4A0_RunningOfTheBulb->trans.y, D_800FE4A0_RunningOfTheBulb->trans.z);
    arg0->func_ptr = &func_800FB3F8_RunningOfTheBulb;
}
void func_800FB3F8_RunningOfTheBulb(omObjData* arg0) {
    RotbBodyWork* body;
    RotbJumpExt* ext;
    f32 angle;
    f32 dx;
    f32 dz;
    f32 step;

    body = arg0->unk_50;
    ext = body->unk_68.jump;
    if (!(body->unk_50 & 0x20)) {
        angle = func_800B0CD8(-2235.0f - arg0->trans.z, 0.0f - arg0->trans.x);
        ext->unk_14 = 0.0f;
        ext->unk_1C = ((250.0f - arg0->trans.y) + 1350.0) / (func_800AEAC0(60.0f) * 30.0f);
        dx = 0.0f - arg0->trans.x;
        dx *= dx;
        dz = -2235.0f - arg0->trans.z;
        dz *= dz;
        step = func_800B1750(dx + dz);
        ext->unk_04 = func_800AEFD0(angle) * (step /= 30.0f);
        ext->unk_0C = func_800AEAC0(angle) * step;
        ext->unk_08 = arg0->trans.y;
        ext->unk_20 = 0.5f;
        arg0->func_ptr = &func_800FB540_RunningOfTheBulb;
    }
}
void func_800FB540_RunningOfTheBulb(omObjData* arg0) {
    RotbJumpExt* ext;
    f32 y;

    ext = ROTB_BODY(arg0)->unk_68.jump;
    ext->unk_14 += 1.0f;
    y = func_800AEAC0(60.0f) * ext->unk_1C * ext->unk_14 - ext->unk_14 * 1.5 * ext->unk_14;
    omSetTra(arg0, arg0->trans.x + ext->unk_04, y + ext->unk_08, arg0->trans.z + ext->unk_0C);
    omSetRot(arg0, arg0->rot.x - 6.0f, arg0->rot.y, arg0->rot.z);
    if (ext->unk_14 >= 30.0f) {
        func_800258EC(arg0->model[1], 4, 0);
        func_80025798(arg0->model[1], ext->unk_20 * -270.0f + arg0->trans.x, ext->unk_20 * -90.0f + arg0->trans.y, ext->unk_20 * 200.0f + arg0->trans.z);
        func_800257E4(arg0->model[1], 0.0f, 45.0f, 0.0f);
        func_80025830(arg0->model[1], ext->unk_20, ext->unk_20, ext->unk_20);
        omSetRot(arg0, 180.0f, arg0->rot.y, arg0->rot.z);
        ext->unk_14 = 60.0f;
        arg0->func_ptr = &func_800FB738_RunningOfTheBulb;
        func_800601D4(0x28);
        PlaySound(0x32E);
    }
}
void func_800FB738_RunningOfTheBulb(omObjData* arg0) {
    u16 temp_v0;
    RotbJumpExt* temp_s0;
    RotbBulbExt* temp_v0_2;
    s32 i;

    temp_s0 = ROTB_BODY(arg0)->unk_68.jump;
    temp_s0->unk_14 = temp_s0->unk_14 - 1.0f;
    
    if (temp_s0->unk_14 != 0.0f) {
        temp_v0 = D_800FE39C_RunningOfTheBulb ^ 1;
        D_800FE39C_RunningOfTheBulb = D_800FE39C_RunningOfTheBulb ^ 1;
        if (temp_v0 != 0) {
            temp_s0->unk_20 = temp_s0->unk_20 + 0.15f;
        } else {
            temp_s0->unk_20 = temp_s0->unk_20 - 0.09f;
        }
        func_80025798(arg0->model[1], (temp_s0->unk_20 * -270.0f) + arg0->trans.x, (temp_s0->unk_20 * -90.0f) + arg0->trans.y, (temp_s0->unk_20 * 200.0f) + arg0->trans.z);
        func_80025830(arg0->model[1], temp_s0->unk_20, temp_s0->unk_20, temp_s0->unk_20);
        return;
    }
    
    PlaySound(0x330);
    PlaySound(0x331);
    arg0->func_ptr = NULL;
    D_800FE478_RunningOfTheBulb->func_ptr = &func_800FAE18_RunningOfTheBulb;
    
    for (i = 0; i < 4; i++) {
        temp_v0_2 = ROTB_BODY(D_800FE49C_RunningOfTheBulb[i])->unk_68.bulb;
        temp_v0_2->unk_02 = 0;
        temp_v0_2->unk_38 = 1.0f;
        temp_v0_2->unk_3C = 0;
        D_800FE49C_RunningOfTheBulb[i]->func_ptr = &func_800FA78C_RunningOfTheBulb;
    }
}

s32 func_800FB8EC_RunningOfTheBulb(omObjData* arg0, omObjData* arg1) {
    RotbPlayerWork* work;
    RotbPlayerExt* ext;
    RotbBodyWork* body;
    RotbBulbExt* bulb;

    work = arg0->unk_50;
    ext = work->unk_E4;
    body = arg1->unk_50;
    if (body->unk_52 == 3) {
        if (func_8000A634(arg0, arg1) == 1) {
            func_80017D1C(arg0);
        }
    } else if (body->unk_52 == 7 && D_800FE464_RunningOfTheBulb != 2) {
        if (work->unk_E0 == 0) {
            if (arg1 != D_800FE478_RunningOfTheBulb) {
                bulb = body->unk_68.bulb;
                if (!(ext->unk_00 & 0x3E) && !(bulb->unk_00 & 0x1A)) {
                    bulb->unk_14 = arg0;
                    ext->unk_00 |= 0xC;
                    func_80060F04(work->unk_58, 10, 0, 10);
                    if (!(ext->unk_00 & 0x40)) {
                        func_800186E4(arg0, 1, 0x23);
                        if (func_80017A50(arg0) == 1) {
                            func_800185A4(arg0, 1);
                        }
                        ext->unk_00 |= 0x40;
                    }
                    if (ext->unk_30 != NULL) {
                        body = ROTB_BODY(ext->unk_30);
                        func_800FA5B8_RunningOfTheBulb(body->unk_68.bulb);
                    }
                    ext->unk_2C = arg1;
                    func_800FA41C_RunningOfTheBulb(arg1);
                }
            } else {
                ext->unk_00 |= 0x10;
            }
        } else if (arg1 != D_800FE478_RunningOfTheBulb && !((bulb = body->unk_68.bulb)->unk_00 & 0x10)) {
            func_800FA44C_RunningOfTheBulb(arg1, work->unk_3C);
            PlaySound(0x32B);
        }
    }
    return 1;
}
void func_800FBAA4_RunningOfTheBulb(omObjData* arg0) {
    switch (D_800FE4B4_RunningOfTheBulb) {
    case 0:
        if (func_80072718() == 0) {
            D_800FE4B4_RunningOfTheBulb = 1;
            GMesCreate(0xD);
            return;
        }
        return;
    case 1:
        if ((GMesStatAllGet() == 0) || (GMesStatAllGet() & 2)) {
            D_800FE464_RunningOfTheBulb = 1;
            omDelObj(arg0);
            D_800FE490_RunningOfTheBulb = NULL;
            D_800ED430 = 1;
            func_80060128(0x1C);
        }
        break;
    }
}

// decomp-permuter
void func_800FBB5C_RunningOfTheBulb(omObjData *arg0)
{
  RotbPlayerWork *work;
  RotbPlayerExt *ext;
  omObjData *obj;
  s32 i;
  u16 n;
  switch (D_800FE4A4_RunningOfTheBulb)
  {
    case 5:
      for (i = 0; i < 4; i++)
    {
      func_800F9648_RunningOfTheBulb(D_800FE460_RunningOfTheBulb[i]);
    }

      GMesCreate(2);
      if (D_800FE458_RunningOfTheBulb != 0)
    {
      D_800FE4A4_RunningOfTheBulb = 11;
    }
    else
    {
      D_800FE4A4_RunningOfTheBulb = 6;
    }
      break;

    case 6:
      if (GMesStatAllGet() & 2)
    {
      D_800FE4A4_RunningOfTheBulb = 1;
    }
      break;

    case 1:
      for (i = 0; i < 4; i++)
    {
      work = D_800FE460_RunningOfTheBulb[i]->unk_50;
      ext = work->unk_E4;
      work->unk_40 = 0.0f;
      func_80009E20(D_800FE460_RunningOfTheBulb[i]);
      n = 0;
      if (!(ext->unk_00 & 0x20))
      {
        func_800185A4(D_800FE460_RunningOfTheBulb[i], 0xD);
        n = 1;
      }
      D_800FE460_RunningOfTheBulb[i]->func_ptr = &func_800F960C_RunningOfTheBulb;
    }

      if (n == 4)
    {
      D_800FE448_RunningOfTheBulb = 0xB4;
    }
    else
    {
      D_800FE448_RunningOfTheBulb = 0xA5;
    }
      func_80060128(0x37);
      D_800FE4A4_RunningOfTheBulb = 7;
      break;

    case 2:
      for (i = 0; i < 4; i++)
    {
      obj = D_800FE460_RunningOfTheBulb[i];
      work = (RotbPlayerWork *) obj->unk_50;
      ext = work->unk_E4;
      if (!(ext->unk_00 & 0x30))
      {
        func_800F947C_RunningOfTheBulb(obj, 45.0f);
      }
    }

      D_800FE4A4_RunningOfTheBulb = 3;
      break;

    case 3:
      n = 0;
      for (i = 0; i < 4; i++)
    {
      ext = ((RotbPlayerWork *) D_800FE460_RunningOfTheBulb[i]->unk_50)->unk_E4;
      if (ext->unk_00 & 0x130)
      {
        n++;
      }
    }

      if (n == 4)
    {
      D_800FE4A4_RunningOfTheBulb = 5;
    }
      break;

    case 7:
      if ((--D_800FE448_RunningOfTheBulb) == 0)
    {
      D_800FE4A4_RunningOfTheBulb = 8;
      func_800726AC(0, 0x14);
    }
      break;

    case 8:
      if (func_80072718() == 0)
    {
      D_800FE3A0_RunningOfTheBulb[0] = 1;
    }
      break;

    case 9:
      if (D_800FE458_RunningOfTheBulb == 0)
    {
      GMesCreate(0xE);
      D_800FE4A4_RunningOfTheBulb = 10;
    }
    else
    {
      GMesCreate(2);
      D_800FE4A4_RunningOfTheBulb = 11;
    }
      break;

    case 10:
      if ((GMesStatAllGet() & 2) && (func_800F9650_RunningOfTheBulb() == 1))
    {
      func_80060128(0x34);
      for (i = 0; i < 4; i++)
      {
        work = D_800FE460_RunningOfTheBulb[i]->unk_50;
        ext = work->unk_E4;
        work->unk_40 = 0.0f;
        func_80009E20(D_800FE460_RunningOfTheBulb[i]);
        if (!(ext->unk_00 & 0x30))
        {
          func_800185A4(D_800FE460_RunningOfTheBulb[i], 0xE);
        }
        func_800258EC(D_800FE460_RunningOfTheBulb[i]->model[9], 4, 4);
        D_800FE460_RunningOfTheBulb[i]->func_ptr = &func_800F960C_RunningOfTheBulb;
      }

      D_800FE448_RunningOfTheBulb = 0x96;
      D_800FE4A4_RunningOfTheBulb = 7;
    }
      break;

    case 11:
      if (GMesWait() != 1)
    {
      D_800FE4A4_RunningOfTheBulb = 8;
      func_800726AC(0, 0x14);
    }
      break;

    case 0:
      break;

  }

}
void func_800FBF30_RunningOfTheBulb(void) {
    if ((D_800FE3A0_RunningOfTheBulb[0] != 0) || (D_800F5144 != 0)) {
        func_800FE178_RunningOfTheBulb(0x83);
        func_800601D4(0x28);
    }
}

void func_800FBF74_RunningOfTheBulb(omObjData* arg0) {
    f32 temp_f20;
    f32 temp_f22;
    f32 var_f2;
    f32 var_f4;
    u16 temp_s0;

    temp_s0 = ROTB_PLAYER(arg0)->unk_56;
    
    if (arg0 == D_800FE4A0_RunningOfTheBulb) {
        var_f4 = D_800FE478_RunningOfTheBulb->trans.x;
        var_f2 = D_800FE478_RunningOfTheBulb->trans.z;
        temp_f22 = func_800FCEA0_RunningOfTheBulb(arg0, NULL, var_f4, var_f2, 40.0f, 250.0f);
    } else {
        if (!(ROTB_PLAYER(D_800FE4A0_RunningOfTheBulb)->unk_E4->unk_00 & 4)) {
            var_f4 = D_800FE4A0_RunningOfTheBulb->trans.x;
            var_f2 = D_800FE4A0_RunningOfTheBulb->trans.z;
        } else {
            var_f4 = D_800FE478_RunningOfTheBulb->trans.x;
            var_f2 = D_800FE478_RunningOfTheBulb->trans.z;
        }
        temp_f22 = func_800FCEA0_RunningOfTheBulb(arg0, D_800FE4A0_RunningOfTheBulb, var_f4, var_f2, 40.0f, 250.0f);
    }
    
    
    temp_f20 = (rand8() & 1) + 15.0f;
    ContStkX[temp_s0] = (func_800AEAC0(temp_f22) * temp_f20);
    ContStkY[temp_s0] = (-func_800AEFD0(temp_f22) * temp_f20);
    ContBtn[temp_s0] = 0;
    ContBtnTrg[temp_s0] = 0;
}

// register allocation and branch layout
#ifdef NON_MATCHING
void func_800FC0F4_RunningOfTheBulb(omObjData* arg0) {
    struct {
        omObjData* obj[4];
        f32 dist[4];
        f32 angle[4];
    } near;
    RotbPlayerWork* work;
    RotbPlayerExt* ext;
    RotbBulbExt* bulb;
    omObjData* target;
    omObjData* obj;
    f32 speed;
    f32 maxA;
    f32 range;
    f32 mult;
    f32 nearDist;
    f32 jitterX;
    f32 jitterZ;
    f32 best;
    f32 tx;
    f32 tz;
    f32 y;
    f32 lim;
    f32 dir;
    s32 i;
    u16 diff;
    u16 port;
    u16 chance;
    u16 track;
    s32 cnt;
    u16 n;
    u16 useLeader;
    u16 visible;
    u16 flags;

    track = 0;
    work = arg0->unk_50;
    ext = work->unk_E4;
    diff = GwPlayer[work->unk_58].cpu_difficulty;
    port = work->unk_56;
    target = NULL;
    switch (diff) {
    case 0:
        speed = (u8)(rand8() % 5) + 35;
        maxA = 30.0f;
        range = 300.0f;
        mult = 0.4f;
        chance = 3;
        nearDist = 200.0f;
        jitterZ = 32.0f;
        jitterX = jitterZ;
        break;
    case 1:
        speed = (u8)(rand8() % 5) + 45;
        maxA = 35.0f;
        range = 350.0f;
        mult = 0.6f;
        chance = 5;
        nearDist = 220.0f;
        jitterZ = 16.0f;
        jitterX = jitterZ;
        break;
    case 2:
        speed = (u8)(rand8() % 5) + 50;
        maxA = 40.0f;
        range = 400.0f;
        mult = 0.8f;
        chance = 7;
        nearDist = 240.0f;
        jitterZ = 8.0f;
        jitterX = jitterZ;
        break;
    case 3:
        speed = 60.0f;
        maxA = 45.0f;
        range = 400.0f;
        mult = 1.0f;
        chance = 10;
        nearDist = 260.0f;
        jitterZ = 0.0f;
        jitterX = jitterZ;
        break;
    }
    useLeader = 0;
    if (arg0 == D_800FE4A0_RunningOfTheBulb) {
        /* Retail computes the distance and angle to the goal and drops both. */
        func_800B1750((0.0f - arg0->trans.x) * (0.0f - arg0->trans.x) + (-2350.0f - arg0->trans.z) * (-2350.0f - arg0->trans.z));
        func_800B0CD8(0.0f - arg0->trans.x, -2350.0f - arg0->trans.z);
        cnt = func_800FDAC4_RunningOfTheBulb(arg0, near.obj, near.dist);
        n = 0;
        for (i = 0; i < (u16)cnt; i++) {
            if (near.dist[i] < 400.0f && near.obj[i]->trans.y < 300.0f) {
                near.angle[n] = func_800B0CD8(near.obj[i]->trans.x - arg0->trans.x, near.obj[i]->trans.z - arg0->trans.z);
                n++;
            }
        }
        if (n == 0) {
            dir = func_800FD394_RunningOfTheBulb(arg0, NULL, 180.0f - CRot.y, maxA, range);
        } else {
            dir = func_800FD9BC_RunningOfTheBulb(n, near.angle);
        }
    } else {
        cnt = func_800FDAC4_RunningOfTheBulb(arg0, near.obj, near.dist);
        if (ext->unk_30 == NULL) {
            if (target == NULL) {
                best = 100000.0f;
                for (i = 0; i < (u16)cnt; i++) {
                    if (func_800FAA40_RunningOfTheBulb(near.obj[i]) == 0) {
                        continue;
                    }
                    obj = near.obj[i];
                    if (300.0f <= obj->trans.y) {
                        continue;
                    }
                    if (ROTB_BODY(obj)->unk_68.bulb->unk_00 & 0x14) {
                        continue;
                    }
                    /* Retail keeps the last distance checked, not the smallest (the store sits
                       in the branch delay slot), while the target is the first nearer one. */
                    if (near.dist[i] < best) {
                        target = obj;
                    }
                    best = near.dist[i];
                }
                if (target == NULL) {
                    target = D_800FE4A0_RunningOfTheBulb;
                    useLeader = 1;
                }
            }
            if (!useLeader) {
                bulb = ROTB_BODY(target)->unk_68.bulb;
                bulb->unk_00 |= 4;
                bulb->unk_08 = arg0;
                ext->unk_30 = target;
            }
        } else if (!useLeader) {
            target = ext->unk_30;
        }
        if ((ROTB_PLAYER(D_800FE4A0_RunningOfTheBulb)->unk_E4->unk_00 & 4) && D_800FE4A0_RunningOfTheBulb->trans.y < 30.0f) {
            target = D_800FE4A0_RunningOfTheBulb;
            best = func_800B1750((target->trans.x - arg0->trans.x) * (target->trans.x - arg0->trans.x) + (target->trans.z - arg0->trans.z) * (target->trans.z - arg0->trans.z));
            track = 1;
        } else {
            for (i = 0; i < 4; i++) {
                if ((u8)(rand8() % 10) >= chance) {
                    continue;
                }
                obj = D_800FE460_RunningOfTheBulb[i];
                if (obj == D_800FE4A0_RunningOfTheBulb) {
                    continue;
                }
                if (GwPlayer[i].flags & 1) {
                    continue;
                }
                flags = ROTB_PLAYER(obj)->unk_E4->unk_00;
                if (flags & 0x30) {
                    continue;
                }
                if ((flags & 4) && obj->trans.y < 30.0f) {
                    target = obj;
                }
                best = func_800B1750((target->trans.x - arg0->trans.x) * (target->trans.x - arg0->trans.x) + (target->trans.z - arg0->trans.z) * (target->trans.z - arg0->trans.z));
                track = 1;
            }
        }
        tx = target->trans.x;
        tz = target->trans.z;
        if (track == 0) {
            best = 100000.0f;
            for (i = 0; i < (u16)cnt; i++) {
                if (near.dist[i] < best) {
                    best = near.dist[i];
                    target = near.obj[i];
                }
            }
            if (func_800FAA40_RunningOfTheBulb(target) == 0) {
                best = 100000.0f;
            }
            if ((visible = (best != 100000.0f)) | (useLeader ^ 1)) {
                bulb = ROTB_BODY(target)->unk_68.bulb;
                if (bulb->unk_14 != NULL && bulb->unk_14->trans.y < 30.0f) {
                    track = 1;
                }
            }
            bulb = ROTB_BODY(target)->unk_68.bulb;
            if (bulb->unk_14 == NULL) {
                goto aim;
            }
            y = bulb->unk_14->trans.y;
        } else {
            y = target->trans.y;
        }
        if (y >= 30.0f) {
            tz -= 200.0f;
            best = func_800B1750((target->trans.x - arg0->trans.x) * (target->trans.x - arg0->trans.x) + (target->trans.z - 200.0f - arg0->trans.z) * (target->trans.z - 200.0f - arg0->trans.z));
        }
    aim:
        if (((useLeader ^ 1) & (visible = (best < nearDist))) && target->trans.y < 300.0f && (u8)(rand8() % 10) < chance) {
            tx = target->trans.x;
            tz = target->trans.z;
            dir = func_800B0CD8(tx - arg0->trans.x, tz - arg0->trans.z);
            if (work->unk_38 == 1000.0f) {
                if (((target->trans.y > 180.0f) & (best > 150.0f)) && func_800FDB84_RunningOfTheBulb(dir, work->unk_3C) < 17.0f && diff >= 2) {
                    ContBtnTrg[port] |= 0x8000;
                }
            }
            if (best < work->unk_40 + 180.0f && func_800FDB84_RunningOfTheBulb(dir, work->unk_3C) < 17.0f && fabs(target->trans.y - arg0->trans.y) < 140.0) {
                ContBtnTrg[port] |= 0x4000;
            }
            if (best < 120.0f && ((fabs(target->trans.y - arg0->trans.y) < 120.0) & (diff >= 2))) {
                ContBtnTrg[port] |= 0x4000;
            }
        }
        best = func_800B1750((tx - arg0->trans.x) * (tx - arg0->trans.x) + (tz - arg0->trans.z) * (tz - arg0->trans.z));
        if (best < 160.0f) {
            speed = 30.0f;
        } else {
            speed = 80.0f;
            if (best < 500.0f) {
                speed = 40.0f;
            }
        }
        speed = mult * speed;
        if (jitterX != 0.0f) {
            tx += func_8009B618((f32)rand8(), jitterX) - jitterX / 2.0f;
        }
        if (jitterZ != 0.0f) {
            tz += func_8009B618((f32)rand8(), jitterZ) - jitterZ / 2.0f;
        }
        dir = func_800FCEA0_RunningOfTheBulb(arg0, NULL, tx, tz, maxA, 250.0f);
    }
    lim = D_800FE478_RunningOfTheBulb->trans.z - 150.0f;
    if (lim - 240.0f < arg0->trans.z) {
        if (track == 0 || arg0->trans.z < lim - 60.0f) {
            ContStkX[port] = 0;
            ContStkY[port] = 80;
            ContBtnTrg[port] &= 0x3FFF;
        }
    } else {
        ContStkX[port] = func_800AEAC0(dir) * speed;
        ContStkY[port] = -func_800AEFD0(dir) * speed;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2D_RunningOfTheBulb/1FF1E0", func_800FC0F4_RunningOfTheBulb);
#endif
// register allocation (retail keeps the count live across the retry loop)
#ifdef NON_MATCHING
f32 func_800FCEA0_RunningOfTheBulb(omObjData* arg0, omObjData* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    struct {
        f32 dist[10];
        f32 angle[10];
    } near;
    RotbPlayerWork* work;
    omObjData* obj;
    f32 angle;
    f32 x;
    f32 z;
    s32 i;
    s32 j;
    u16 n;
    u16 tries;

    angle = func_800B0CD8(arg2 - arg0->trans.x, arg3 - arg0->trans.z) - CRot.y;
    n = 0;
    if (angle < -180.0f) {
        angle += 360.0f;
    }
    for (i = 0; i < 4; i++) {
        obj = D_800FE460_RunningOfTheBulb[i];
        if (((obj == arg0) | (obj == arg1)) != 0) {
            continue;
        }
        work = obj->unk_50;
        if (work->unk_E4->unk_00 & 0x34) {
            continue;
        }
        x = obj->trans.x;
        z = obj->trans.z;
        near.dist[n] = func_800B1750((x - arg0->trans.x) * (x - arg0->trans.x) + (z - arg0->trans.z) * (z - arg0->trans.z));
        near.angle[n] = func_800B0CD8(x - arg0->trans.x, z - arg0->trans.z);
        if ((near.angle[n] = near.angle[n] - CRot.y) < -180.0f) {
            near.angle[n] += 360.0f;
        }
        n++;
    }
    for (i = 0; i < 6; i++) {
        obj = D_800FE480_RunningOfTheBulb[i];
        if (obj->func_ptr == NULL) {
            continue;
        }
        if (ROTB_FLOOR(obj)->unk_28->unk_02 != 1 && !(obj->trans.y < 180.0f)) {
            continue;
        }
        x = obj->trans.x;
        z = obj->trans.z;
        near.dist[n] = func_800B1750((x - arg0->trans.x) * (x - arg0->trans.x) + (z - arg0->trans.z) * (z - arg0->trans.z));
        near.angle[n] = func_800B0CD8(x - arg0->trans.x, z - arg0->trans.z);
        if ((near.angle[n] = near.angle[n] - CRot.y) < -180.0f) {
            near.angle[n] += 360.0f;
        }
        n++;
    }
    tries = 0;
    work = arg0->unk_50;
retry:
    /* Retail counts j past a blocking entry before leaving the scan, so a blocker in the last
       slot reads as "none". */
    for (j = 0; j < n;) {
        if (func_800FDB84_RunningOfTheBulb(near.angle[j], angle) <= arg4 && near.dist[j] <= arg5) {
            j++;
            break;
        }
        j++;
    }
    if (j == n) {
        x = func_800AEAC0(angle) * arg5 + arg0->trans.x;
        z = func_800AEFD0(angle) * arg5 + arg0->trans.z;
        if (work->unk_48 + -400.0f <= x && x <= 400.0f - work->unk_48 && work->unk_48 + -2500.0f <= z && z <= 2500.0f - work->unk_48) {
            goto done;
        }
        if (z < D_800FE478_RunningOfTheBulb->trans.z - 200.0f) {
            goto done;
        }
    }
    D_800FE456_RunningOfTheBulb++;
    if (++tries == 36) {
        D_800FE454_RunningOfTheBulb = 1;
        goto done;
    }
    angle += 10.0f;
    if (angle > 180.0f) {
        angle -= 360.0f;
    }
    goto retry;
done:
    if (angle < 0.0f) {
        angle += 360.0f;
    }
    if (angle >= 360.0f) {
        angle -= 360.0f;
    }
    return angle;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2D_RunningOfTheBulb/1FF1E0", func_800FCEA0_RunningOfTheBulb);
#endif
// register allocation (retail keeps the count live across the retry loop)
#ifdef NON_MATCHING
f32 func_800FD394_RunningOfTheBulb(omObjData* arg0, omObjData* arg1, f32 arg2, f32 arg3, f32 arg4) {
    struct {
        f32 dist[14];
        f32 angle[14];
    } near;
    RotbPlayerWork* work;
    omObjData* obj;
    f32 x;
    f32 z;
    s32 i;
    s32 j;
    u16 n;
    u16 tries;

    n = 0;
    for (i = 0; i < 4; i++) {
        obj = D_800FE460_RunningOfTheBulb[i];
        if (((obj == arg0) | (obj == arg1)) != 0) {
            continue;
        }
        work = obj->unk_50;
        if (work->unk_E4->unk_00 & 0x34) {
            continue;
        }
        x = obj->trans.x;
        z = obj->trans.z;
        near.dist[n] = func_800B1750((x - arg0->trans.x) * (x - arg0->trans.x) + (z - arg0->trans.z) * (z - arg0->trans.z));
        near.angle[n] = func_800B0CD8(x - arg0->trans.x, z - arg0->trans.z);
        if ((near.angle[n] = near.angle[n] - CRot.y) < -180.0f) {
            near.angle[n] += 360.0f;
        }
        n++;
    }
    for (i = 0; i < 4; i++) {
        obj = D_800FE49C_RunningOfTheBulb[i];
        x = obj->trans.x;
        if (x + 70.0f < -400.0f) {
            continue;
        }
        if (400.0f < x - 70.0f) {
            continue;
        }
        z = obj->trans.z;
        if (z + 70.0f < -2500.0f) {
            continue;
        }
        if (D_800FE478_RunningOfTheBulb->trans.z + 200.0f < z - 70.0f) {
            continue;
        }
        if (200.0f < obj->trans.y) {
            continue;
        }
        near.dist[n] = func_800B1750((x - arg0->trans.x) * (x - arg0->trans.x) + (z - arg0->trans.z) * (z - arg0->trans.z));
        near.angle[n] = func_800B0CD8(x - arg0->trans.x, z - arg0->trans.z);
        if ((near.angle[n] = near.angle[n] - CRot.y) < -180.0f) {
            near.angle[n] += 360.0f;
        }
        n++;
    }
    for (i = 0; i < 6; i++) {
        obj = D_800FE480_RunningOfTheBulb[i];
        if (obj->func_ptr == NULL) {
            continue;
        }
        if (ROTB_FLOOR(obj)->unk_28->unk_02 != 1 && !(obj->trans.y < 180.0f)) {
            continue;
        }
        x = obj->trans.x;
        z = obj->trans.z;
        near.dist[n] = func_800B1750((x - arg0->trans.x) * (x - arg0->trans.x) + (z - arg0->trans.z) * (z - arg0->trans.z));
        near.angle[n] = func_800B0CD8(x - arg0->trans.x, z - arg0->trans.z);
        if ((near.angle[n] = near.angle[n] - CRot.y) < -180.0f) {
            near.angle[n] += 360.0f;
        }
        n++;
    }
    tries = 0;
    work = arg0->unk_50;
retry:
    /* Retail counts j past a blocking entry before leaving the scan, so a blocker in the last
       slot reads as "none". */
    for (j = 0; j < n;) {
        if (func_800FDB84_RunningOfTheBulb(near.angle[j], arg2) <= arg3 && near.dist[j] <= arg4) {
            j++;
            break;
        }
        j++;
    }
    if (j == n) {
        x = func_800AEAC0(arg2) * arg4 + arg0->trans.x;
        z = func_800AEFD0(arg2) * arg4 + arg0->trans.z;
        if (work->unk_48 + -400.0f <= x && x <= 400.0f - work->unk_48 && work->unk_48 + -2500.0f <= z && z <= 2500.0f - work->unk_48) {
            goto done;
        }
        if (z < D_800FE478_RunningOfTheBulb->trans.z - 200.0f) {
            goto done;
        }
    }
    D_800FE456_RunningOfTheBulb++;
    if (++tries == 36) {
        D_800FE454_RunningOfTheBulb = 1;
        goto done;
    }
    arg2 += 10.0f;
    if (arg2 > 180.0f) {
        arg2 -= 360.0f;
    }
    goto retry;
done:
    if (arg2 < 0.0f) {
        arg2 += 360.0f;
    }
    if (arg2 >= 360.0f) {
        arg2 -= 360.0f;
    }
    return arg2;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2D_RunningOfTheBulb/1FF1E0", func_800FD394_RunningOfTheBulb);
#endif
f32 func_800FD9BC_RunningOfTheBulb(u16 arg0, f32* arg1) {
    f32 temp_f0;
    f32 var_f12;
    f32 var_f14;
    f32 var_f20;
    s32 i;

    if (arg0 == 1) {
        temp_f0 = *arg1 + 180.0f;
        if (temp_f0 >= 360.0f) {
            return temp_f0 - 360.0f;
        }
        return temp_f0;
    }
    
    var_f20 = 10000.0f;

    for (i = 0; i < arg0; i++) {
        if (i == arg0 - 1) {
            temp_f0 = func_800FDB84_RunningOfTheBulb(arg1[i], arg1[0]);
        } else {
            temp_f0 = func_800FDB84_RunningOfTheBulb(arg1[i + 0], arg1[i + 1]);
        }
        
        if (temp_f0 < var_f20) {
            var_f20 = temp_f0;
        }      
    }

    return var_f20 / 2.0f;
}

u16 func_800FDAC4_RunningOfTheBulb(omObjData* arg0, omObjData** arg1, f32* arg2) {
    omObjData* temp_v1;
    f32 temp_f12;
    f32 temp_f2;
    u16 i;
    s32 j;

    for (i = 0, j = 0; j < 4; i++, j++) {
        temp_v1 = D_800FE49C_RunningOfTheBulb[j];
        arg1[i] = temp_v1;
        temp_f2 = (arg1[i]->trans.x - arg0->trans.x) * (arg1[i]->trans.x - arg0->trans.x);
        temp_f12 = (arg1[i]->trans.z - arg0->trans.z) * (arg1[i]->trans.z - arg0->trans.z);
        arg2[i] = func_800B1750(temp_f2 + temp_f12);
    }
    return i;
}

f32 func_800FDB84_RunningOfTheBulb(f32 arg0, f32 arg1) {
    f32 var_f2;
    f32 newVar;
 
    while (arg0 < 0.0f) {
        arg0 += 360.0f;
    }
    
    while (arg0 >= 360.0f) {
        arg0 -= 360.0f;
    }

    while (arg1 < 0.0f) {
        arg1 += 360.0f;
    }

    while (arg1 >= 360.0f) {
        arg1 -= 360.0f;
    }

    newVar = arg0 - arg1;
    var_f2 = fabsf(newVar);
    
    if (var_f2 > 180.0f) {
        var_f2 = 360.0f - var_f2;
    }
    
    return var_f2;
}


omObjData* func_800FDCAC_RunningOfTheBulb(omObjData* arg0, f32* arg1) {
    omObjData* temp_s0;
    omObjData* var_s3;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f12;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f2;
    s32 i;

    var_s3 = NULL;
    *arg1 = 100000.0f;
    temp_f24 = arg0->trans.x;
    temp_f22 = arg0->trans.y + 100.0f;
    temp_f20 = arg0->trans.z;
    for (i = 0; i < 4; i++) {
        temp_s0 = D_800FE460_RunningOfTheBulb[i];
        if (ROTB_PLAYER(temp_s0)->unk_E4->unk_00 & 0x36) {
            continue;
        } else {
            temp_f2 = (temp_s0->trans.x - temp_f24) * (temp_s0->trans.x - temp_f24);
            temp_f0 = (temp_s0->trans.y - temp_f22) * (temp_s0->trans.y - temp_f22);
            temp_f2 = temp_f2 + temp_f0;
            temp_f12 = temp_s0->trans.z - temp_f20;
            temp_f0_2 = func_800B1750((temp_f2) + (temp_f12 * temp_f12));
            
            if (temp_f0_2 < *arg1) {
                *arg1 = temp_f0_2;
                var_s3 = temp_s0;
            }            
        }
        
    }
    return var_s3;
}

s32 func_800FDDC0_RunningOfTheBulb(omObjData* arg0) {
    RotbPlayerWork* temp_s0;
    RotbBulbExt* temp_s1;
    RotbPlayerExt* temp_s3;
    omObjData* temp_v0;
    omObjData* temp_v1;
    s32 i;

    if (arg0 == D_800FE4A0_RunningOfTheBulb) {
        if (!(arg0->trans.z > -1850.0f)) {
            D_800FE464_RunningOfTheBulb = 2;
            D_800FE4A4_RunningOfTheBulb = 0;
            D_800FE44A_RunningOfTheBulb = 1;
            for (i = 0; i < 4; i++) {
                temp_v1 = D_800FE460_RunningOfTheBulb[i];
                temp_s0 = temp_v1->unk_50;
                temp_s3 = temp_s0->unk_E4;
                if (!(temp_s3->unk_00 & 0x30)) {
                    temp_v1->func_ptr = &func_800F8EA0_RunningOfTheBulb;
                    temp_s0->unk_40 = 0.0f;
                    temp_v0 = D_800FE460_RunningOfTheBulb[i];
                    temp_s0->unk_3C = func_800B0CD8(0.0f - temp_v0->trans.x, -2235.0f - temp_v0->trans.z);
                    func_80009E20(D_800FE460_RunningOfTheBulb[i]);
                    GwPlayer[i].coins_mg += 10;
                }
                if (temp_s3->unk_00 & 0x40) {
                    func_800186E4(D_800FE460_RunningOfTheBulb[i], 1, 0x23);
                }                
            }
            
            for (i = 0; i < 4; i++) {
                func_800258EC(D_800FE460_RunningOfTheBulb[i]->model[9], 4, 4);
            }


            for (i = 0; i < 4; i++) {
                temp_s1 = ROTB_BODY(D_800FE49C_RunningOfTheBulb[i])->unk_68.bulb;
                if (temp_s1->unk_00 & 8) {
                    temp_s1->unk_00 &= ~0x8;
                    if (temp_s1->unk_02 < 5) {
                        omSetTra(D_800FE49C_RunningOfTheBulb[i], 0.0f, 0.0f, 5000.0f);
                    } else {
                        temp_s1->unk_04 = 0x10;
                        func_800211BC(D_800FE49C_RunningOfTheBulb[i]->model[0], temp_s1->unk_04);
                        func_800211BC(D_800FE49C_RunningOfTheBulb[i]->model[2], temp_s1->unk_04);
                    }
                }
                if (!(temp_s1->unk_00 & 0x10)) {
                    D_800FE49C_RunningOfTheBulb[i]->func_ptr = &func_800FA2B8_RunningOfTheBulb;
                }                
            }

            D_800FE470_RunningOfTheBulb[1]->func_ptr = &func_800F6E80_RunningOfTheBulb;
            return 1;
        }
    }
    return 0;
}
