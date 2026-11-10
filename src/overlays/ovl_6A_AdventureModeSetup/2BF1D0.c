#include "AdventureModeSetup.h"

/* .data (0x80101870..0x80101AF0) */
s32 D_80101870_AdventureModeSetup[4][4] = {
    { 2, 2, 1, 1 },
    { 3, 3, 0, 0 },
    { 0, 0, 3, 3 },
    { 1, 1, 2, 2 },
};
s32 D_801018B0_AdventureModeSetup[6][8] = {
    { 3, 4, 1, 4, 3, 5, 2, 5 },
    { 4, 5, 2, 5, 4, 3, 0, 3 },
    { 5, 3, 0, 3, 5, 4, 1, 4 },
    { 0, 1, 4, 1, 0, 2, 5, 2 },
    { 1, 2, 5, 2, 1, 0, 3, 0 },
    { 2, 0, 3, 0, 2, 1, 4, 1 },
};
f32 D_80101970_AdventureModeSetup[6][4] = {
    { -70.0f, -200.0f, 75.0f, 500.0f },
    { 20.0f, -270.0f, 70.0f, 500.0f },
    { 120.0f, -350.0f, 65.0f, 500.0f },
    { -80.0f, -330.0f, -50.0f, 500.0f },
    { 10.0f, -500.0f, -25.0f, 500.0f },
    { 100.0f, -400.0f, -45.0f, 500.0f },
};
f32 D_801019D0_AdventureModeSetup[4][2] = {
    { 250.0f, 140.0f }, { 250.0f, 70.0f }, { 250.0f, 0.0f }, { 250.0f, -70.0f },
};
AMSetupVec2 D_801019F0_AdventureModeSetup[4] = {
    { -100.0f, 60.0f }, { -300.0f, 60.0f }, { -100.0f, 130.0f }, { -300.0f, 130.0f },
};
s32 D_80101A10_AdventureModeSetup[4] = { 0, 1, 2, 3 };
f32 D_80101A20_AdventureModeSetup[4] = { -170.0f, 130.0f, -150.0f, 160.0f };
f32 D_80101A30_AdventureModeSetup[4] = { -160.0f, -160.0f, 130.0f, 170.0f };
s32 D_80101A40_AdventureModeSetup = 0;
s32 D_80101A44_AdventureModeSetup[4] = { 0, 0, 0, 0 };
f32 D_80101A54_AdventureModeSetup[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
s32 D_80101A64_AdventureModeSetup = 0x80; /* the s16 at D_80101A66 is its low half */
s32 D_80101A68_AdventureModeSetup = 0;
s32 D_80101A6C_AdventureModeSetup = -1;
/* [board][answer - 1]; the last word (D_80101ACC) also starts the table retail indexes from 1 */
void* D_80101A70_AdventureModeSetup[8][3] = {
    { (void*)D_80101DC0_AdventureModeSetup, (void*)D_80101DBC_AdventureModeSetup, (void*)D_80101DB8_AdventureModeSetup },
    { (void*)D_80101DC0_AdventureModeSetup, (void*)D_80101DBC_AdventureModeSetup, (void*)D_80101DB8_AdventureModeSetup },
    { (void*)D_80101DC0_AdventureModeSetup, (void*)D_80101DBC_AdventureModeSetup, (void*)D_80101DB8_AdventureModeSetup },
    { (void*)D_80101DC0_AdventureModeSetup, (void*)D_80101DBC_AdventureModeSetup, (void*)D_80101DB8_AdventureModeSetup },
    { (void*)D_80101DC0_AdventureModeSetup, (void*)D_80101DBC_AdventureModeSetup, (void*)D_80101DB8_AdventureModeSetup },
    { (void*)D_80101DC0_AdventureModeSetup, (void*)D_80101DBC_AdventureModeSetup, (void*)D_80101DB8_AdventureModeSetup },
    { (void*)D_80101DC0_AdventureModeSetup, (void*)D_80101DBC_AdventureModeSetup, (void*)D_80101DB8_AdventureModeSetup },
    { (void*)D_80101DC0_AdventureModeSetup, (void*)D_80101DBC_AdventureModeSetup, (void*)D_80101DB8_AdventureModeSetup },
};
void* D_80101AD0_AdventureModeSetup[3] = {
    (void*)D_80101DB4_AdventureModeSetup, (void*)D_80101DC0_AdventureModeSetup, (void*)D_80101DB0_AdventureModeSetup,
};
s32 D_80101ADC_AdventureModeSetup = 0; /* the u16 at D_80101ADE is its low half */
s32 D_80101AE0_AdventureModeSetup = 0;
s32 D_80101AE4_AdventureModeSetup = 0;

void func_800F6610_AdventureModeSetup() {
    D_80101F70_AdventureModeSetup = 0;
    func_800F66A8_AdventureModeSetup();
}

void func_800F6630_AdventureModeSetup() {
    D_80101F70_AdventureModeSetup = 1;
    func_800F66A8_AdventureModeSetup();
}


void func_800F6654_AdventureModeSetup() {
    D_80101F70_AdventureModeSetup = 2;
    func_800F66A8_AdventureModeSetup();
}

void func_800F6678_AdventureModeSetup() {
    D_80101F70_AdventureModeSetup = 3;
    SetBoardFeatureFlag(0x2C);
    func_800F66A8_AdventureModeSetup();
}

void func_800F66A8_AdventureModeSetup(void) {
    s16 cam;
    s32 i;

    func_80101374_AdventureModeSetup();
    func_80029090(0x32);
    func_8001DE70(0x20);
    omInitObjMan(0x3C, 0x3C);
    func_80060088();
    func_8006CEA0();
    omSysPauseEnableFlag = 1;
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80101338_AdventureModeSetup), 0xA0);
    func_800178A0(1);
    cam = func_800178E8();
    func_80017660(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(cam, 45.0f, 80.0f, 8000.0f);
    func_8001D420(0, &D_80102000_AdventureModeSetup, &D_8010200C_AdventureModeSetup, &D_80102018_AdventureModeSetup);
    func_8001D57C(0);
    func_8001D494(0, 45.0f, 80.0f, 8000.0f);
    D_80102610_AdventureModeSetup = omAddObj(1, 0, 0, -1, func_801014C0_AdventureModeSetup);
    func_800F6EEC_AdventureModeSetup();
    func_800FBD98_AdventureModeSetup();
    func_800FD3D8_AdventureModeSetup();
    func_800FF064_AdventureModeSetup();
    func_80100528_AdventureModeSetup();
    func_801008B4_AdventureModeSetup();
    func_80100D84_AdventureModeSetup();
    func_80101274_AdventureModeSetup();
    omAddPrcObj(func_800F70E4_AdventureModeSetup, 0x1002, 0x800, 0);
    omAddPrcObj(func_800F71DC_AdventureModeSetup, 0x1002, 0x800, 0);
    if (D_80101F70_AdventureModeSetup == 1) {
        MBModelInit();
        D_80101FF8_AdventureModeSetup = omAddObj(0x1E, 0, 0, -1, func_800F8FD8_AdventureModeSetup);
    }
    if (D_80101F70_AdventureModeSetup == 2) {
        func_800532E0();
        D_801025D4_AdventureModeSetup = func_8005077C(1);
        for (i = 0; i < 7; i++) {
            if (D_801025D4_AdventureModeSetup->unk_0C[i] != -1) {
                func_800674BC(D_801025D4_AdventureModeSetup->unk_0A, i, 0x8000);
            }
        }
    }
}
void func_800F6958_AdventureModeSetup(omObjData* arg0, Vec3f* arg1) {
    Vec3f vec;
    Vec3f* vecptr;
    f32 angle;

    vecptr = &vec;
    arg0->trans.x = arg0->trans.z = arg0->trans.y = 0.0f;
    func_800A0D00(vecptr, D_80102000_AdventureModeSetup.x, 0.0f, D_80102000_AdventureModeSetup.z);

    vec.x -= D_8010200C_AdventureModeSetup.x;
    vec.y -= 0.0f;
    vec.z -= D_8010200C_AdventureModeSetup.z;
    if ((vec.x != 0.0f) || (vec.z != 0.0f)) {
        angle = func_80029518(func_800B0CD8(vecptr->x, vecptr->z));
        arg0->trans.x = D_80102000_AdventureModeSetup.x - (func_800AEAC0(angle) * arg1->z);
        arg0->trans.z = D_80102000_AdventureModeSetup.z - (func_800AEFD0(angle) * arg1->z);
    }
    func_800A0D00(vecptr, D_80102000_AdventureModeSetup.x, 0.0f, D_80102000_AdventureModeSetup.z);
    arg0->trans.x = (func_800AEFD0(func_80029518(func_800B0CD8(vecptr->x, vecptr->z))) * arg1->x) + arg0->trans.x;
    func_800A0D00(vecptr, 0.0f, D_80102000_AdventureModeSetup.y, -D_80102000_AdventureModeSetup.z);

    vecptr->x -= 0.0f;
    vecptr->y -= D_80102010_AdventureModeSetup.x;
    vecptr->z += D_80102010_AdventureModeSetup.y;
    if ((vecptr->z != 0.0f) || (vecptr->y != 0.0f)) {
        arg0->trans.y = D_80102004_AdventureModeSetup.x - (func_800AEFD0(func_80029518(func_800B0CD8(vecptr->z, vecptr->y))) * arg1->z);
    }
    func_800A0D00(vecptr, 0.0f, -D_80102004_AdventureModeSetup.x, -D_80102004_AdventureModeSetup.y);
    arg0->trans.y = (func_800AEFD0(func_80029518(func_800B0CD8(vecptr->z, vecptr->y))) * arg1->y) + arg0->trans.y;
}

void func_800F6BDC_AdventureModeSetup(omObjData* arg0) {
    if ((func_8005FD5C() + D_800F64F8) == 0) {
        D_801025E0_AdventureModeSetup += D_801025E4_AdventureModeSetup;
        if (D_80101F70_AdventureModeSetup != 3) {
            D_801025E4_AdventureModeSetup -= 0.7f;
            if (D_801025E4_AdventureModeSetup < -3.0f) {
                D_801025E4_AdventureModeSetup = -4.2f;
            }
        } else {
            D_801025E4_AdventureModeSetup -= 0.5f;
            if (D_801025E4_AdventureModeSetup < -3.0f) {
                D_801025E4_AdventureModeSetup = -3.0f;
            }
        }
    }

    func_80027C1C(*arg0->model, D_801025DC_AdventureModeSetup, D_801025E0_AdventureModeSetup, D_801025D8_AdventureModeSetup[0], D_801025D8_AdventureModeSetup[1]);
}

void func_800F6D08_AdventureModeSetup(omObjData* arg0) {
    if (D_80101F70_AdventureModeSetup != 3) {
        if ((func_8005FD5C() + D_800F64F8) == 0) {
            D_801025E0_AdventureModeSetup += 4.2f;
        }
    } else if ((func_8005FD5C() + D_800F64F8) == 0) {
        D_801025E0_AdventureModeSetup += 3.0f;
    }
    D_801025E0_AdventureModeSetup = D_801025E0_AdventureModeSetup;

    if (D_801025DA_AdventureModeSetup < D_801025E0_AdventureModeSetup) {
        D_801025E0_AdventureModeSetup -= D_801025DA_AdventureModeSetup;
    }

    func_80027C1C(*arg0->model, D_801025DC_AdventureModeSetup, D_801025E0_AdventureModeSetup, D_801025D8_AdventureModeSetup[0], D_801025D8_AdventureModeSetup[1]);
}

void func_800F6E20_AdventureModeSetup(omObjData* arg0) {
    *arg0->model = func_800174C0(D_80101F70_AdventureModeSetup != 3 ? 0x9000B : 0x9008A, 0x299);

    arg0->trans.x = arg0->trans.y = arg0->trans.z = 0.0f;
    arg0->func_ptr = func_800F6D08_AdventureModeSetup;

    func_80026040(*arg0->model);
    func_80039C48(D_80101F70_AdventureModeSetup != 3 ? "12tt000_DEF" : "tsubo_DEF", D_801025D8_AdventureModeSetup);

    D_801025DC_AdventureModeSetup = D_801025E0_AdventureModeSetup = 0.0f;
    D_801025E4_AdventureModeSetup = 3.0f;
}

void func_800F6EEC_AdventureModeSetup() {
    D_80101F7C_AdventureModeSetup = omAddObj(0xA, 1U, 0U, -1, func_800F6E20_AdventureModeSetup);
    omSetStatBit(D_80101F7C_AdventureModeSetup, 0xA0);
}

void func_800F6F34_AdventureModeSetup(omObjData* arg0) {
    AMSObjWork* work;
    s32 i;

    for (i = 0; i < arg0->mdlcnt; i++) {
        arg0->model[i] = 0;
    }
    arg0->unk_50 = func_80023684(sizeof(AMSObjWork), 0x7918);
    func_8009B770(arg0->unk_50, 0, sizeof(AMSObjWork));
    work = arg0->unk_50;
    work->unk_D8 = func_80023684(arg0->mtncnt * 4, 0x7918);
    for (i = 0; i < arg0->mtncnt; i++) {
        arg0->motion[i] = -1;
    }
    for (i = 0; i < arg0->mtncnt; i++) {
        work->unk_D8[i][0] = 0;
        work->unk_D8[i][1] = 0;
    }
    work->unk_56 = -1;
    work->unk_52 = 0;
    work->unk_A4 = 1.0f;
    work->unk_C0 = 0xFFFF;
    work->unk_4C = 0.5f;
    work->unk_BC = 1.0f;
    work->unk_60 = 0.0f;
    func_80008FD0(arg0, 60.0f);
    func_80008FDC(arg0, 150.0f);
    func_80008FE8(arg0, 20.0f);
    func_80008FF4(arg0, 30.0f);
    func_80008FA0(arg0, 1000.0f);
    work->unk_90 = work->unk_94 = work->unk_98 = 0.0f;
    work->unk_B1 = -1;
}
// decomp-permuter
s32 func_800F70CC_AdventureModeSetup(s32 arg0)
{
  s32 ret = 1;
  int new_var;
  new_var = arg0 < 7;
  if (new_var)
  {
    ret = (new_var = arg0 < 1);
  }
  return ret;
}
void func_800F70E4_AdventureModeSetup() {
    while (TRUE) {
        if (D_801025C0_AdventureModeSetup != 0) {
            D_801025C0_AdventureModeSetup = 0;
            func_80071C8C(D_801025B4_AdventureModeSetup, 1);
        }

        if (D_801025B8_AdventureModeSetup != -1) {
            LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)D_801025B8_AdventureModeSetup, -1, -1);
            D_801025B8_AdventureModeSetup = -1;
        }

        if (D_801025BC_AdventureModeSetup != 0) {
            while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                HuPrcVSleep();
            }
            func_80071E80(D_801025B4_AdventureModeSetup, 1);

            while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                HuPrcVSleep();
            }
            D_801025BC_AdventureModeSetup = 0;
        }
        HuPrcVSleep();
    }
}

void func_800F71DC_AdventureModeSetup() {
    while (TRUE) {
        if (D_801025C4_AdventureModeSetup != -1) {
            LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)D_801025C4_AdventureModeSetup, -1, -1);
            func_8006DA5C(D_801025B4_AdventureModeSetup, D_801025D0_AdventureModeSetup, 0);

            while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                HuPrcVSleep();
            }
            D_801025C4_AdventureModeSetup = -1;

            if (D_801025CC_AdventureModeSetup == 0) {
                D_801025C8_AdventureModeSetup = 0;
                func_80071C8C(D_801025B4_AdventureModeSetup, 1);

                while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                    HuPrcVSleep();
                }
                D_801025CC_AdventureModeSetup = 1;
            }
            D_801025C8_AdventureModeSetup = 1;
        }
        HuPrcVSleep();
    }
}

void func_800F72E0_AdventureModeSetup(void) {
    Vec3f vec;
    s32 port;
    s32 shown;
    omObjData* obj;
    AMSPiece* piece;
    Vec3f* vecptr;
    s32 i;
    s32 j;
    s32 k;
    f32 target;
    f32 step;
    f32 diff;
    GW_PLAYER* player;


    shown = 0;
    obj = D_80101FA0_AdventureModeSetup;
    piece = &AMS_PIECES[obj->work[0]];
    vecptr = &vec;
    while (TRUE) {
        switch (obj->work[1]) {
            case 1:
                if (D_80101F70_AdventureModeSetup != 2) {
                    D_801025B4_AdventureModeSetup = func_8007194C(0x48, 0xBC, 5);
                } else {
                    D_801025B4_AdventureModeSetup = func_8007194C(0x48, 0xC0, 3);
                }
                port = func_8005B470(D_801025B4_AdventureModeSetup);
                AMS_SEL.port = port;
                func_8006E288(D_801025B4_AdventureModeSetup, 1);
                func_80071FF4(D_801025B4_AdventureModeSetup, 0xDC);
                if (D_80101F70_AdventureModeSetup != 3) {
                    PlaySound(0x3C);
                }
                piece->unk40 = 4.0f;
                piece->unk3C = 40.0f;
                piece->unk58 = 0;
                D_80101E40_AdventureModeSetup = 0.0f;
                D_80101E44_AdventureModeSetup = 90.0f;
                D_80101E48_AdventureModeSetup = 0.0f;
                if (D_80101F70_AdventureModeSetup != 3) {
                    func_800184BC(obj, 3);
                }
                obj->work[1] = 2;
            case 2:
                piece->unk3C += piece->unk40;
                if (piece->unk3C > 40.0f) {
                    piece->unk3C = 40.0f;
                    piece->unk58++;
                }
                obj->trans.y -= piece->unk3C;
                if (obj->trans.y < -4654.0f) {
                    obj->work[1] = 3;
                }
                D_80102000_AdventureModeSetup.x = obj->trans.x;
                D_80102000_AdventureModeSetup.y = obj->trans.y - func_800AEAC0(D_80101E44_AdventureModeSetup) * 500.0f + func_800AEAC0(D_80101E48_AdventureModeSetup) * 170.0f;
                D_80102000_AdventureModeSetup.z = obj->trans.z + 400.0f;
                D_8010200C_AdventureModeSetup.x = func_800AEAC0(D_80101E40_AdventureModeSetup) * 400.0f + obj->trans.x;
                D_80102010_AdventureModeSetup.x = obj->trans.y - func_800AEAC0(D_80101E44_AdventureModeSetup) * 200.0f + func_800AEAC0(D_80101E48_AdventureModeSetup) * 170.0f;
                D_80102014_AdventureModeSetup = obj->trans.z + 400.0f - func_800AEFD0(D_80101E40_AdventureModeSetup) * 400.0f;
                D_80101E40_AdventureModeSetup += 0.4f;
                if (D_80101E40_AdventureModeSetup > 20.0f) {
                    D_80101E40_AdventureModeSetup = 20.0f;
                }
                D_80101E44_AdventureModeSetup -= 6.0f;
                if (D_80101E44_AdventureModeSetup < 0.0f) {
                    D_80101E44_AdventureModeSetup = 0.0f;
                }
                if (D_80101E44_AdventureModeSetup == 0.0f) {
                    D_80101E48_AdventureModeSetup += 1.0f;
                    if (D_80101E48_AdventureModeSetup > 90.0f) {
                        D_80101E48_AdventureModeSetup = 90.0f;
                    }
                }
                break;
            case 3:
                obj->work[1] = 4;
            case 4:
                piece->unk3C = 0.0f;
                if (D_80101F70_AdventureModeSetup != 3) {
                    func_800184BC(obj, 0);
                }
                switch (D_80101F70_AdventureModeSetup) {
                    case 1:
                        obj->work[1] = 0x20;
                        break;
                    case 2:
                        obj->work[1] = 0x22;
                        break;
                    case 0:
                    case 3:
                        obj->work[1] = 7;
                        break;
                }
                break;
            case 5:
                piece->unk40 = 2.0f;
                piece->unk3C = -25.0f;
                if (D_80101F70_AdventureModeSetup != 3) {
                    func_800184BC(obj, 1);
                }
                obj->work[1] = 6;
            case 6:
                piece->unk3C += piece->unk40;
                if (piece->unk3C > 0.0f) {
                    piece->unk3C = 0.0f;
                    if (D_80101F70_AdventureModeSetup != 3) {
                        func_800184BC(obj, 0);
                    }
                    obj->work[1] = 7;
                }
                obj->trans.y -= piece->unk3C;
                break;
            case 7:
                if (D_80101F70_AdventureModeSetup != 3) {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)0x284, -1, -1);
                } else {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)0x26C, -1, -1);
                }
                func_80071C8C(D_801025B4_AdventureModeSetup, 1);
                while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                    HuPrcVSleep();
                }
                obj->work[1] = 8;
                break;
            case 8:
                if (D_80101F70_AdventureModeSetup != 3) {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)0x285, -1, -1);
                } else {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)0x26D, -1, -1);
                    while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                        HuPrcVSleep();
                    }
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)0x26E, -1, -1);
                }
                while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                    HuPrcVSleep();
                }
                func_80071E80(D_801025B4_AdventureModeSetup, 1);
                obj->work[1] = 9;
                break;
            case 9:
                D_80101FA4_AdventureModeSetup->work[1] = 1;
                obj->work[1] = 0xA;
                break;
            case 10:
                if (D_80101FA4_AdventureModeSetup->work[1] == 0) {
                    if (AMS_SEL.count != -1) {
                        obj->work[1] = 0xB;
                    } else {
                        obj->work[1] = 0x26;
                    }
                }
                break;
            case 11:
                if (D_80101F70_AdventureModeSetup != 3) {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)0x286, -1, -1);
                } else {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)0x273, -1, -1);
                }
                func_80071C8C(D_801025B4_AdventureModeSetup, 1);
                while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                    HuPrcVSleep();
                }
                func_80071E80(D_801025B4_AdventureModeSetup, 1);
                obj->work[1] = 0xC;
                break;
            case 12:
                D_80101FA8_AdventureModeSetup->work[1] = 1;
                obj->work[1] = 0xD;
                break;
            case 13:
                if (D_80101FA8_AdventureModeSetup->work[1] == 0) {
                    if (AMS_SEL.count == 4) {
                        obj->work[1] = 0x10;
                    } else if (AMS_SEL.count != -1) {
                        obj->work[1] = 0xE;
                    } else {
                        D_80101FA4_AdventureModeSetup->work[1] = 0xC;
                        obj->work[1] = 0x1D;
                    }
                }
                break;
            case 14:
                i = 0;
                if (AMS_SEL.count != 4) {
                    for (j = 0; j < 4; j++) {
                        i += AMS_SEL.unk18[j] != -1;
                    }
                    if (i >= AMS_SEL.count) {
                        if (D_80101F70_AdventureModeSetup != 3) {
                            LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)(AMS_SEL.count + 0x286), -1, -1);
                        } else {
                            LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)(AMS_SEL.count + 0x273), -1, -1);
                        }
                        func_80071C8C(D_801025B4_AdventureModeSetup, 1);
                        while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                            HuPrcVSleep();
                        }
                    }
                }
                obj->work[1] = 0xF;
                break;
            case 15:
                D_80101FA8_AdventureModeSetup->work[1] = 6;
                obj->work[1] = 0x10;
                break;
            case 16:
                if (D_80101FA8_AdventureModeSetup->work[1] == 0) {
                    obj->work[1] = 0x11;
                }
                break;
            case 17:
                D_80101FA8_AdventureModeSetup->work[1] = 8;
                if (D_80101F70_AdventureModeSetup != 3) {
                    obj->work[1] = 0x13;
                } else {
                    obj->work[1] = 0x14;
                }
                break;
            case 19:
                if (D_80101FA8_AdventureModeSetup->work[1] == 0) {
                    if (AMS_SEL.count < 4) {
                        for (j = AMS_SEL.count; j < 4; j++) {
                            D_80101FD8_AdventureModeSetup[j]->work[1] = 1;
                        }
                        D_80101FA8_AdventureModeSetup->work[1] = 0x13;
                    }
                    obj->work[1] = 0x12;
                }
                break;
            case 20:
                if (D_80101FA8_AdventureModeSetup->work[1] == 0) {
                    D_80101FA8_AdventureModeSetup->work[1] = 0x15;
                    obj->work[1] = 0x13;
                }
                break;
            case 18:
                if (D_80101FA8_AdventureModeSetup->work[1] == 0) {
                    if (D_80101F70_AdventureModeSetup != 3) {
                        obj->work[1] = 0x15;
                    } else {
                        obj->work[1] = 0x1A;
                    }
                }
                break;
            case 21:
                LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)0x28A, -1, -1);
                func_80071C8C(D_801025B4_AdventureModeSetup, 1);
                while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                    HuPrcVSleep();
                }
                func_80071E80(D_801025B4_AdventureModeSetup, 1);
                obj->work[1] = 0x16;
                break;
            case 22:
                D_80101FC0_AdventureModeSetup->work[1] = 1;
                obj->work[1] = 0x17;
                break;
            case 23:
                if (D_80101FC0_AdventureModeSetup->work[1] == 0) {
                    obj->work[1] = 0x18;
                }
                break;
            case 24:
                D_80101FC0_AdventureModeSetup->work[1] = 3;
                obj->work[1] = 0x19;
                break;
            case 25:
                if (D_80101FC0_AdventureModeSetup->work[1] == 0) {
                    if (AMS_SEL.unk2C != -1) {
                        obj->work[1] = 0x1A;
                    } else if (AMS_SEL.count == 4) {
                        D_80101FA8_AdventureModeSetup->work[1] = 0xC;
                        obj->work[1] = 0x1E;
                    } else {
                        obj->work[1] = 0x13;
                    }
                }
                break;
            case 26:
                if (D_80101F70_AdventureModeSetup != 3) {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)0x295, -1, -1);
                    func_80071C8C(D_801025B4_AdventureModeSetup, 1);
                } else {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)0x27C, -1, -1);
                }
                while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                    HuPrcVSleep();
                }
                func_80071E80(D_801025B4_AdventureModeSetup, 1);
                obj->work[1] = 0x1B;
                break;
            case 27:
                D_80101FC4_AdventureModeSetup->work[1] = 1;
                obj->work[1] = 0x1C;
                break;
            case 28:
                if (D_80101FC4_AdventureModeSetup->work[1] == 0) {
                    if (AMS_SEL.unk30 == -1) {
                        D_80101FC0_AdventureModeSetup->work[1] = 0xF;
                        obj->work[1] = 0x1F;
                    } else if (AMS_SEL.unk30 == 1000) {
                        for (i = 0; i < 4; i++) {
                            AMS_SEL.unk18[i] = -1;
                        }
                        D_80101FA8_AdventureModeSetup->work[1] = 0x11;
                        AMS_SEL.count = -1;
                        D_80101FA4_AdventureModeSetup->work[1] = 0xD;
                        AMS_SEL.unk2C = -1;
                        if (D_80101F70_AdventureModeSetup != 3) {
                            D_80101FC0_AdventureModeSetup->work[1] = 0x13;
                        }
                        AMS_SEL.unk30 = -1;
                        D_80101FC4_AdventureModeSetup->work[1] = 6;
                        obj->work[1] = 8;
                    } else {
                        obj->work[1] = 0x25;
                    }
                }
                break;
            case 29:
                if (D_80101FA4_AdventureModeSetup->work[1] == 0) {
                    obj->work[1] = 0xA;
                }
                break;
            case 30:
                if (D_80101FA8_AdventureModeSetup->work[1] == 0) {
                    D_80101FA8_AdventureModeSetup->work[1] = 4;
                    obj->work[1] = 0xD;
                }
                break;
            case 31:
                if (D_80101FC0_AdventureModeSetup->work[1] == 0) {
                    if (D_80101F70_AdventureModeSetup != 3) {
                        D_80101FC0_AdventureModeSetup->work[1] = 3;
                        obj->work[1] = 0x19;
                    } else if (AMS_SEL.count == 4) {
                        obj->work[1] = 0x14;
                    } else {
                        obj->work[1] = 0x13;
                    }
                }
                break;
            case 32:
                obj->work[1] = 0x21;
                break;
            case 33:
                i = 0;
                k = 0;
                while (TRUE) {
                    if ((i == 3) & (shown == 0)) {
                        shown = 1;
                        D_80101FF8_AdventureModeSetup->work[1] = 1;
                    }
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)(i + 0x29A), -1, -1);
                    if (k == 0) {
                        k = 1;
                        func_80071C8C(D_801025B4_AdventureModeSetup, 1);
                    }
                    while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                        if (ContDStkTrg[port] & 0x4000) {
                            LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)0x2A6, -1, -1);
                            HuPrcVSleep();
                            j = func_8006FCF0(D_801025B4_AdventureModeSetup, 1, 0);
                            if (j == 0) {
                                obj->work[1] = 0x26;
                            } else {
                                i--;
                            }

                        }
                        if (j == 0) {
                            goto close33;
                        }
                        HuPrcVSleep();
                    }
                    if (j == 0) {
                        break;
                    }
                    i++;
                    j = 1;
                    if (i >= 6) {
                        break;
                    }
                }
            close33:
                func_80071E80(D_801025B4_AdventureModeSetup, 1);
                if (j != 0) {
                    D_80101FF8_AdventureModeSetup->work[1] = 3;
                    obj->work[1] = 0x23;
                }
                break;
            case 34:
                for (i = 0; i < 7; i++) {
                    if (D_801025D4_AdventureModeSetup->unk_0C[i] != -1) {
                        func_80067480(D_801025D4_AdventureModeSetup->unk_0A, i, 0x8000);
                    }
                }
                k = 0;
                do {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)0x2A7, -1, -1);
                    if (k == 0) {
                        k = 1;
                        func_80071C8C(D_801025B4_AdventureModeSetup, 1);
                    }
                    HuPrcVSleep();
                    i = func_8006FCF0(D_801025B4_AdventureModeSetup, 0, 0);
                    if (i == 0) {
                        obj->work[1] = 0x23;
                    } else {
                        LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)0x2A6, -1, -1);
                        HuPrcVSleep();
                        j = func_8006FCF0(D_801025B4_AdventureModeSetup, 1, 0);
                        if (j == 0) {
                            obj->work[1] = 0x26;
                        }
                    }
                } while (((i == 0) | (j == 0)) == 0);
                func_80071E80(D_801025B4_AdventureModeSetup, 1);
                for (i = 0; i < 7; i++) {
                    if (D_801025D4_AdventureModeSetup->unk_0C[i] != -1) {
                        func_800674BC(D_801025D4_AdventureModeSetup->unk_0A, i, 0x8000);
                    }
                }
                break;
            case 35:
                omAddObj(0x64, 0, 0, -1, func_800F88C0_AdventureModeSetup);
                if (D_80101F70_AdventureModeSetup != 3) {
                    func_800184BC(obj, 2);
                }
                for (i = 0; i < 6; i++) {
                    D_80101F88_AdventureModeSetup[i]->work[3] &= ~8;
                }
                HuPrcVSleep();
                PlaySound(3);
                obj->work[1] = 0x24;
                break;
            case 36:
                obj->trans.y -= 20.0f;
                if (D_80101F70_AdventureModeSetup != 3) {
                    func_800A0D00(vecptr, 0.0f, -D_80102004_AdventureModeSetup.x, D_80102004_AdventureModeSetup.y);
                    vecptr->x -= 0.0f;
                    vecptr->y += obj->trans.y;
                    vecptr->z -= obj->trans.z;
                    target = func_80029518(func_800B0CD8(vecptr->y, vecptr->z));
                    obj->rot.x = func_80029518(obj->rot.x);
                    step = 5.0f;
                    if (obj->rot.x < target) {
                        if (target - obj->rot.x > 180.0f) {
                            step = -step;
                        }
                    } else if (obj->rot.x - target < 180.0f) {
                        step = -step;
                    }
                    diff = target - obj->rot.x;
                    if (diff < 0.0f) {
                        diff = -diff;
                    }
                    if ((step < 0.0f) ? (-step < diff) : (step < diff)) {
                        obj->rot.x = func_80029518(step + obj->rot.x);
                    } else {
                        obj->rot.x = target;
                    }
                }
                if (obj->trans.y < -5500.0f) {
                    switch (D_80101F70_AdventureModeSetup) {
                        case 1:
                            AMS_SEL.count = 1;
                            AMS_SEL.unk2C = 8;
                            AMS_SEL.joined[0] = 0;
                            AMS_SEL.joined[1] = 0;
                            AMS_SEL.joined[2] = 0;
                            AMS_SEL.joined[3] = 0;
                            AMS_SEL.joined[AMS_SEL.port] = 1;
                            AMS_SEL.unk30 = 0;
                            AMS_SEL.unk18[0] = 0;
                            AMS_SEL.unk18[1] = 0;
                            AMS_SEL.unk18[2] = 0;
                            AMS_SEL.unk18[3] = 0;
                            SetBoardFeatureFlag(1);
                            break;
                        case 2:
                            AMS_SEL.count = 0;
                            for (i = 0; i < 4; i++) {
                                player = &GwPlayer[i];
                                j = player->port;
                                if (player->flags &= 1) {
                                    AMS_SEL.joined[j] = 0;
                                } else {
                                    AMS_SEL.joined[j] = 1;
                                    AMS_SEL.count++;
                                }
                            }
                            AMS_SEL.unk2C = 8;
                            AMS_SEL.unk30 = 0;
                            AMS_SEL.unk18[0] = 0;
                            AMS_SEL.unk18[1] = 0;
                            AMS_SEL.unk18[2] = 0;
                            AMS_SEL.unk18[3] = 0;
                            break;
                        default:
                            osSyncPrintf("how!! enter");
                            while (TRUE) {
                                HuPrcVSleep();
                            }
                        case 0:
                        case 3:
                            break;
                    }
                    if (D_80101F74_AdventureModeSetup == 0) {
                        D_80101F74_AdventureModeSetup = 1;
                        omAddPrcObj(func_801015D0_AdventureModeSetup, 0x1002, 0x800, 0);
                    }
                }
                break;
            case 37:
                D_80101FA8_AdventureModeSetup->work[1] = 0x12;
                D_80101FA4_AdventureModeSetup->work[1] = 0xD;
                if (D_80101F70_AdventureModeSetup != 3) {
                    D_80101FC0_AdventureModeSetup->work[1] = 0x13;
                }
                D_80101FC4_AdventureModeSetup->work[1] = 6;
                obj->work[1] = 0x23;
                break;
            case 38:
                omAddObj(0x64, 0, 0, -1, func_800F88D4_AdventureModeSetup);
                D_80101F7C_AdventureModeSetup->func_ptr = func_800F6BDC_AdventureModeSetup;
                HuPrcVSleep();
                PlaySound(3);
                obj->work[1] = 0x27;
                break;
            case 39:
                obj->trans.y += 20.0f;
                if (obj->trans.y > -3500.0f && D_80101F74_AdventureModeSetup == 0) {
                    D_80101F74_AdventureModeSetup = 1;
                    D_80101F78_AdventureModeSetup = 1;
                    omAddPrcObj(func_801015D0_AdventureModeSetup, 0x1002, 0x800, 0);
                }
                break;
            case 0:
                break;
        }
        func_80017DB0(obj);
        HuPrcVSleep();
    }
}
void func_800F86F8_AdventureModeSetup(omObjData* arg0) {
    omObjData* obj = D_80101FA0_AdventureModeSetup;

    switch (arg0->work[1]) {
        case 0:
            D_80101E4C_AdventureModeSetup = 40;
            D_80101E50_AdventureModeSetup = -15.0f;
            arg0->work[1] = 2;
            break;
        case 1:
            D_80101E4C_AdventureModeSetup = 80;
            D_80101E50_AdventureModeSetup = 15.0f;
            arg0->work[1] = 2;
            break;
    }

    switch (arg0->work[1]) {
        case 2:
            D_80101E54_AdventureModeSetup.x = obj->trans.x;
            D_80101E54_AdventureModeSetup.y = obj->trans.y;
            D_80101E54_AdventureModeSetup.z = obj->trans.z;
            D_80101E60_AdventureModeSetup.x = (D_80101E54_AdventureModeSetup.x - D_8010200C_AdventureModeSetup.x) / D_80101E4C_AdventureModeSetup;
            D_80101E60_AdventureModeSetup.y = (D_80101E54_AdventureModeSetup.y - D_8010200C_AdventureModeSetup.y) / D_80101E4C_AdventureModeSetup;
            D_80101E60_AdventureModeSetup.z = (D_80101E54_AdventureModeSetup.z - D_8010200C_AdventureModeSetup.z) / D_80101E4C_AdventureModeSetup;
            D_80101E54_AdventureModeSetup.x = D_8010200C_AdventureModeSetup.x - D_80101E54_AdventureModeSetup.x;
            D_80101E54_AdventureModeSetup.y = D_8010200C_AdventureModeSetup.y - D_80101E54_AdventureModeSetup.y;
            D_80101E54_AdventureModeSetup.z = D_8010200C_AdventureModeSetup.z - D_80101E54_AdventureModeSetup.z;
            arg0->work[1] = 3;
        case 3:
            if (--D_80101E4C_AdventureModeSetup == -1) {
                arg0->work[1] = 4;
                break;
            }
            D_80102004_AdventureModeSetup.x += D_80101E50_AdventureModeSetup;
            D_8010200C_AdventureModeSetup.x = obj->trans.x + D_80101E54_AdventureModeSetup.x;
            D_8010200C_AdventureModeSetup.y = obj->trans.y + D_80101E54_AdventureModeSetup.y;
            D_8010200C_AdventureModeSetup.z = obj->trans.z + D_80101E54_AdventureModeSetup.z;
            D_80101E54_AdventureModeSetup.x += D_80101E60_AdventureModeSetup.x;
            D_80101E54_AdventureModeSetup.y += D_80101E60_AdventureModeSetup.y;
            D_80101E54_AdventureModeSetup.z += D_80101E60_AdventureModeSetup.z;
            break;
        case 4:
            break;
    }
}
void func_800F88C0_AdventureModeSetup(omObjData* arg0) {
    arg0->work[1] = 0;
    arg0->func_ptr = func_800F86F8_AdventureModeSetup;
}
void func_800F88D4_AdventureModeSetup(omObjData* arg0) {
    arg0->work[1] = 1;
    arg0->func_ptr = func_800F86F8_AdventureModeSetup;
}

void func_800F88EC_AdventureModeSetup(omObjData* arg0) {
    Vec3f vec;
    AMSPiece* piece;
    Vec3f* vecptr;

    piece = &AMS_PIECES[arg0->work[0]];
    vecptr = &vec;
    func_800A0D00(vecptr, D_80102000_AdventureModeSetup.x, 0.0f, D_80102000_AdventureModeSetup.z);
    vec.x -= arg0->trans.x;
    vec.y -= 0.0f;
    vec.z -= arg0->trans.z;
    arg0->rot.y = func_80029518(func_800B0CD8(vec.x, vec.z));
    if (arg0->work[2] != 0) {
        func_800A0D00(vecptr, 0.0f, -D_80102000_AdventureModeSetup.y, D_80102000_AdventureModeSetup.z);
        vec.x -= 0.0f;
        vec.y += arg0->trans.y;
        vec.z -= arg0->trans.z;
        arg0->rot.x = func_80029518(func_800B0CD8(vec.y, vec.z));
    }
    if (func_800F70CC_AdventureModeSetup(arg0->work[1]) != 0) {
        piece->unk44 += 5.0f;
        if (piece->unk44 >= 360.0f) {
            piece->unk44 -= 360.0f;
        }
    } else if (piece->unk44 != 0.0f || piece->unk44 != 180.0f) {
        piece->unk44 += 5.0f;
        if (piece->unk44 >= 360.0f) {
            piece->unk44 -= 360.0f;
        }
        if (piece->unk44 > 0.0f && piece->unk44 < 5.0f) {
            piece->unk44 = 0.0f;
        }
        if (piece->unk44 > 180.0f && piece->unk44 < 185.0f) {
            piece->unk44 = 180.0f;
        }
    }
    func_8009EA40(D_800F2B7C[*arg0->model].unk7C, 0.0f, func_800AEAC0(piece->unk44) * 10.0f, 0.0f);
}
void func_800F8BA4_AdventureModeSetup(omObjData* arg0) {
    func_800F6F34_AdventureModeSetup(arg0);
    if (D_80101F70_AdventureModeSetup != 3) {
        *arg0->model = func_800174C0(0x70000, 0xAB9);
    } else {
        *arg0->model = func_800174C0(0x6D, 0xAB9);
        func_80025EB4(*arg0->model, 2, 2);
        func_80025930(*arg0->model, 0x70000000, 0);
    }

    arg0->trans.x = 0.0f;
    arg0->trans.y = -2400.0f;
    arg0->trans.z = 0.0f;
    arg0->scale.x = arg0->scale.y = arg0->scale.z = 0.5f;

    if (D_80101F70_AdventureModeSetup != 3) {
        func_8001874C(arg0, 0, 0x70001, 1, 0);
        func_8001874C(arg0, 1, 0x70003, 1, 0);
        func_8001874C(arg0, 2, 0x70004, 1, 0);
        func_8001874C(arg0, 3, 0x70005, 1, 0);
        func_8001874C(arg0, 4, 0x70006, 1, 0);
        func_8001874C(arg0, 5, 0x70007, 1, 0);
    }

    arg0->func_ptr = func_800F88EC_AdventureModeSetup;
    omAddPrcObj(func_800F72E0_AdventureModeSetup, 0x1002U, 0x800, 0);
    arg0->work[0] = 6;
    arg0->work[1] = 0;

    if (D_80101F70_AdventureModeSetup != 3) {
        arg0->work[2] = 0;
    } else {
        arg0->work[2] = 1;
    }

    *(&D_8010206C_AdventureModeSetup + (arg0->work[0] * 0x1B)) = 0;
    func_80017DB0(arg0);
}

void func_800F8D90_AdventureModeSetup(omObjData* arg0) {
    Vec3f vec;
    Vec3f* vecptr;
    omObjData* obj;

    obj = D_80101FA0_AdventureModeSetup;
    vecptr = &vec;
    switch (arg0->work[1]) {
        case 1:
            D_80101E6C_AdventureModeSetup = 0.0f;
            func_800A0D00(&D_801025E8_AdventureModeSetup->coords, obj->trans.x + 150.0f, obj->trans.y - 150.0f, obj->trans.z);
            arg0->work[1] = 2;
            break;
        case 2:
            D_801025E8_AdventureModeSetup->coords.y += 20.0f;
            if (obj->trans.y + 150.0f < D_801025E8_AdventureModeSetup->coords.y) {
                D_801025F0_AdventureModeSetup = D_801025E8_AdventureModeSetup->coords.y;
                arg0->work[1] = 4;
            }
            break;
        case 3:
            D_801025E8_AdventureModeSetup->coords.y += 20.0f;
            if (obj->trans.y + 500.0f < D_801025E8_AdventureModeSetup->coords.y) {
                arg0->work[1] = 0;
            }
            break;
        case 0:
            break;
    }
    func_800A0D00(vecptr, D_80102000_AdventureModeSetup.x, D_80102000_AdventureModeSetup.y, D_80102000_AdventureModeSetup.z);
    vecptr->x -= D_801025E8_AdventureModeSetup->coords.x;
    vecptr->y -= D_801025E8_AdventureModeSetup->coords.y;
    vecptr->z -= D_801025E8_AdventureModeSetup->coords.z;
    func_800A1250(vecptr);
    func_800A0D50(&D_801025E8_AdventureModeSetup->unk_18, vecptr);
    if (arg0->work[1] == 4) {
        D_80101E6C_AdventureModeSetup += 5.0f;
        if (D_80101E6C_AdventureModeSetup >= 360.0f) {
            D_80101E6C_AdventureModeSetup -= 360.0f;
        }
        D_801025E8_AdventureModeSetup->coords.y = func_800AEAC0(D_80101E6C_AdventureModeSetup) * 20.0f + D_801025F0_AdventureModeSetup;
    }
}
void func_800F8FD8_AdventureModeSetup(omObjData* arg0) {
    Object *temp_v0;

    temp_v0 = MBModelCreate(0x40U, NULL);
    D_801025E8_AdventureModeSetup = temp_v0;
    D_801025EC_AdventureModeSetup = func_80042728(temp_v0, 0);
    arg0->func_ptr = func_800F8D90_AdventureModeSetup;
    arg0->work[1] = 0;
}

s32 func_800F9030_AdventureModeSetup(s32 arg0, s32 arg1) {
    s32 i = arg1;
    s32* row;

    while (TRUE) {
        row = ((s32(*)[8])&D_801018B0_AdventureModeSetup)[i];
        i = row[arg0];
        if (D_80101F88_AdventureModeSetup[i]->work[1] == 0 && D_80101F88_AdventureModeSetup[i]->work[2] == 0) {
            return i;
        }
        if (i == arg1) {
            return -1;
        }
    }
}

// regalloc, hoisting, and two byte tests retail merges into one word test (masked 579; 116/2194 normalised)
#ifdef NON_MATCHING
void func_800F9090_AdventureModeSetup(void) {
    s32 prev[4];
    omObjData* obj;
    omObjData* o;
    omObjData* q;
    unkAMSetupMove* c;
    s32 i;
    s32 j;
    s32 k;
    s32 n;
    s32 dir;
    s32 res;

    while (1) {
        obj = D_80101FA8_AdventureModeSetup;
        switch (obj->work[1]) {
        case 0:
            break;
        case 1:
            for (i = 0; i < 6; i++) {
                func_800258EC(*D_80101F88_AdventureModeSetup[i]->model, 4, 0);
                AMS_PIECES[i].unkC.x = D_80101970_AdventureModeSetup[i][0];
                AMS_PIECES[i].unkC.y = D_80101970_AdventureModeSetup[i][1];
                AMS_PIECES[i].unk1C = D_80101970_AdventureModeSetup[i][2];
                AMS_PIECES[i].unkC.z = D_80101970_AdventureModeSetup[i][3];
            }
        case 2:
            for (i = 0; i < 6; i++) {
                D_80101F88_AdventureModeSetup[i]->work[1] = 1;
            }
            for (i = 0; i < 6; i++) {
                D_80101F88_AdventureModeSetup[i]->work[2] = 1;
            }
            obj->work[1] = 3;
            break;
        case 3:
            for (i = 0; i < 6; i++) {
                if (D_80101F88_AdventureModeSetup[i]->work[1] != 0) {
                    break;
                }
            }
            if (i == 6) {
                obj->work[1] = 4;
            }
            break;
        case 4:
            for (i = 0; i < 6; i++) {
                D_80101F88_AdventureModeSetup[i]->work[2] = 1;
            }
            for (i = 0, n = 0; n < AMS_COUNT; i++) {
                if (AMS_ACTIVE[i] != 0) {
                    D_80101A10_AdventureModeSetup[i] = n;
                    D_80101F88_AdventureModeSetup[n]->work[2] = 2;
                    n++;
                }
            }
            for (i = AMS_CUR, n = 0; n < AMS_COUNT; i++) {
                if (AMS_ACTIVE[i] != 0) {
                    n++;
                    q = D_80101FC8_AdventureModeSetup[i];
                    o = D_80101F88_AdventureModeSetup[D_80101A10_AdventureModeSetup[i]];
                    q->work[1] = 2;
                    q->trans.x = o->trans.x;
                    q->trans.y = o->trans.y;
                    q->trans.z = o->trans.z;
                }
            }
            obj->work[1] = 5;
            break;
        case 5:
            if (AMS_COUNT < 4) {
                D_80101E7C_AdventureModeSetup = 1;
            } else {
                D_80101E7C_AdventureModeSetup = 0;
            }
            for (j = 0, n = 0; j < 4; j++) {
                if (AMS_SLOTS[j] != -1) {
                    n += AMS_WORK(D_80101F88_AdventureModeSetup[AMS_SLOTS[j]])->w1 == 0 &&
                         (AMS_WORK(D_80101F88_AdventureModeSetup[AMS_SLOTS[j]])->w3 & 4);
                }
            }
            if (n >= AMS_COUNT) {
                if (D_801025BC_AdventureModeSetup == 0) {
                    obj->work[1] = 0;
                }
                break;
            }
            for (i = 0; i < 6; i++) {
                o = D_80101F88_AdventureModeSetup[i];
                if (o->work[3] & 2) {
                    for (j = 0; j < 4; j++) {
                        if (AMS_SLOTS[j] == i) {
                            break;
                        }
                    }
                    if (j < 4) {
                        for (k = 0, n = j; k < 5; k++) {
                            if (AMS_ACTIVE[k] != 0) {
                                if (n-- == 0) {
                                    break;
                                }
                            }
                        }
                        q = D_80101FC8_AdventureModeSetup[k];
                        q->work[1] = 2;
                        q->trans.x = o->trans.x;
                        q->trans.y = o->trans.y;
                        q->trans.z = o->trans.z;
                        D_80101A10_AdventureModeSetup[k] = i;
                    }
                    o->work[2] = 2;
                    o->work[3] &= ~3;
                    AMS_SLOTS[j] = -1;
                }
            }
            for (i = AMS_CUR, n = 0; n < AMS_COUNT; i++) {
                if (AMS_ACTIVE[i] == 0) {
                    continue;
                }
                o = D_80101F88_AdventureModeSetup[D_80101A10_AdventureModeSetup[i]];
                n++;
                if (o->work[1] != 0) {
                    continue;
                }
                if (o->work[3] & 1) {
                    o->work[3] &= ~1;
                    for (j = 0, k = 0; k < i; k++) {
                        j += AMS_ACTIVE[k] != 0;
                    }
                    AMS_SLOTS[j] = -1;
                    if (D_80101FC8_AdventureModeSetup[i]->work[1] == 0) {
                        D_80101FC8_AdventureModeSetup[i]->work[1] = 2;
                    }
                }
                if (ContDStkTrg[i] & 0x4000) {
                    for (j = 0; j < 4; j++) {
                        if (AMS_SLOTS[j] != -1) {
                            break;
                        }
                    }
                    if (j >= 4) {
                        for (j = 0; j < 6; j++) {
                            if (D_80101F88_AdventureModeSetup[j]->work[1] != 0) {
                                break;
                            }
                        }
                        if (j >= 6) {
                            for (j = 0; j < 6; j++) {
                                D_80101F88_AdventureModeSetup[j]->work[1] = 11;
                            }
                            for (j = 0; j < 4; j++) {
                                D_80101FC8_AdventureModeSetup[j]->work[1] = 1;
                            }
                            AMS_COUNT = -1;
                            obj->work[1] = 0;
                        }
                    }
                    for (j = 0, k = 0; k < i; k++) {
                        j += AMS_ACTIVE[k] != 0;
                    }
                    if (AMS_SLOTS[j] != -1) {
                        D_80101F88_AdventureModeSetup[D_80101A10_AdventureModeSetup[i]]->work[2] = 2;
                        D_80101F88_AdventureModeSetup[D_80101A10_AdventureModeSetup[i]]->work[3] |= 1;
                        D_80101F88_AdventureModeSetup[D_80101A10_AdventureModeSetup[i]]->work[1] = 8;
                    }
                }
                if (D_80101FC8_AdventureModeSetup[i]->work[1] != 5) {
                    continue;
                }
                dir = (ContDStkTrg[i] & 0x800) ? 0 : -1;
                if (ContDStkTrg[i] & 0x100) {
                    dir = 2;
                }
                if (ContDStkTrg[i] & 0x400) {
                    dir = 4;
                }
                if (ContDStkTrg[i] & 0x200) {
                    dir = 6;
                }
                if ((ContDStkTrg[i] & 0x800) && (ContDStkTrg[i] & 0x100)) {
                    dir = 1;
                }
                if ((ContDStkTrg[i] & 0x400) && (ContDStkTrg[i] & 0x100)) {
                    dir = 3;
                }
                if ((ContDStkTrg[i] & 0x400) && (ContDStkTrg[i] & 0x200)) {
                    dir = 5;
                }
                if ((ContDStkTrg[i] & 0x800) && (ContDStkTrg[i] & 0x200)) {
                    dir = 7;
                }
                if (ContDStkTrg[i] & 0x8000) {
                    func_80060540(D_80101A10_AdventureModeSetup[i] + 0x451, i);
                    func_8006CE64(i, 2, 3, 10);
                    AMS_SLOTS[n - 1] = D_80101A10_AdventureModeSetup[i];
                    D_80101FC8_AdventureModeSetup[i]->work[1] = 1;
                    for (j = 0, k = 0; k <= i; k++) {
                        j += AMS_ACTIVE[k] != 0;
                    }
                    D_80101F88_AdventureModeSetup[D_80101A10_AdventureModeSetup[i]]->work[1] = j + 2;
                    goto end;
                }
                if (dir != -1) {
                    prev[i] = D_80101A10_AdventureModeSetup[i];
                    if ((D_80101A10_AdventureModeSetup[i] = func_800F9030_AdventureModeSetup(dir, D_80101A10_AdventureModeSetup[i])) == -1) {
                        D_80101A10_AdventureModeSetup[i] = prev[i];
                        k = dir + 2;
                        if (k >= 4) {
                            k = dir - 2;
                        }
                        if ((D_80101A10_AdventureModeSetup[i] = func_800F9030_AdventureModeSetup(k, (*(AMS_NEIGHBORS + D_80101A10_AdventureModeSetup[i]))[dir])) == -1) {
                            D_80101A10_AdventureModeSetup[i] = prev[i];
                        }
                    }
                    if (prev[i] != D_80101A10_AdventureModeSetup[i]) {
                        D_80101F88_AdventureModeSetup[prev[i]]->work[2] = 1;
                        o = D_80101F88_AdventureModeSetup[D_80101A10_AdventureModeSetup[i]];
                        o->work[2] = 2;
                        D_80101FC8_AdventureModeSetup[i]->work[1] = 3;
                        c = &D_80102490_AdventureModeSetup[i];
                        c->target.x = o->trans.x;
                        c->target.y = o->trans.y;
                        c->target.z = o->trans.z;
                    }
                }
            }
            break;
        case 6:
            for (i = 0; i < 6; i++) {
                if (D_80101F88_AdventureModeSetup[i]->work[2] == 0) {
                    q = D_80101FC8_AdventureModeSetup[AMS_CUR];
                    q->work[1] = 2;
                    o = D_80101F88_AdventureModeSetup[i];
                    q->trans.x = o->trans.x;
                    q->trans.y = o->trans.y;
                    q->trans.z = o->trans.z;
                    o->work[2] = 2;
                    D_80101A10_AdventureModeSetup[AMS_CUR] = i;
                    break;
                }
            }
            if (D_80101F70_AdventureModeSetup != 3) {
                LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)0x2A8, -1, -1);
            } else {
                LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)0x281, -1, -1);
            }
            while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                HuPrcVSleep();
            }
            obj->work[1] = 7;
        case 7:
            if (D_80101F88_AdventureModeSetup[D_80101A10_AdventureModeSetup[AMS_CUR]]->work[1] != 0) {
                break;
            }
            for (j = 0; j < 4; j++) {
                if (AMS_SLOTS[j] == -1) {
                    break;
                }
            }
            if (j < 1 || j > 3) {
                while (1) {
                }
            }
            o = D_80101F88_AdventureModeSetup[AMS_SLOTS[j - 1]];
            if (o->work[3] & 2) {
                o->work[2] = 1;
                D_80101F88_AdventureModeSetup[AMS_SLOTS[j - 1]]->work[3] &= ~3;
                AMS_SLOTS[j - 1] = -1;
            }
            if (D_80101FC8_AdventureModeSetup[AMS_CUR]->work[1] != 5) {
                break;
            }
            if (ContDStkTrg[AMS_CUR] & 0x4000) {
                for (j = 0; j < 6; j++) {
                    if (D_80101F88_AdventureModeSetup[j]->work[1] != 0) {
                        break;
                    }
                }
                if (j < 6) {
                    goto dpad7;
                }
                for (j = 0; j < 4; j++) {
                    if (AMS_SLOTS[j] == -1) {
                        break;
                    }
                }
                if (AMS_COUNT >= j) {
                    for (k = j - 1; k >= 0; k--) {
                        D_80101FC8_AdventureModeSetup[AMS_CUR]->work[1] = 1;
                        D_80101F88_AdventureModeSetup[AMS_SLOTS[k]]->work[3] |= 2;
                        D_80101F88_AdventureModeSetup[AMS_SLOTS[k]]->work[1] = 8;
                    }
                    func_80071E80(D_801025B4_AdventureModeSetup, 1);
                    D_80101F88_AdventureModeSetup[D_80101A10_AdventureModeSetup[AMS_CUR]]->work[2] = 1;
                    D_80101FA0_AdventureModeSetup->work[1] = 13;
                    obj->work[1] = 16;
                    break;
                }
                if (D_80101F70_AdventureModeSetup != 3) {
                    k = AMS_COUNT - 0x2A8;
                } else {
                    k = AMS_COUNT - 0x281;
                }
                LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)(s32)(j - k - 1), -1, -1);
                while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                    HuPrcVSleep();
                }
                D_80101F88_AdventureModeSetup[AMS_SLOTS[j - 1]]->work[3] |= 2;
                D_80101F88_AdventureModeSetup[AMS_SLOTS[j - 1]]->work[1] = 8;
                break;
            }
        dpad7:
            dir = (ContDStkTrg[AMS_CUR] & 0x800) ? 0 : -1;
            if (ContDStkTrg[AMS_CUR] & 0x100) {
                dir = 2;
            }
            if (ContDStkTrg[AMS_CUR] & 0x400) {
                dir = 4;
            }
            if (ContDStkTrg[AMS_CUR] & 0x200) {
                dir = 6;
            }
            if ((ContDStkTrg[AMS_CUR] & 0x800) && (ContDStkTrg[AMS_CUR] & 0x100)) {
                dir = 1;
            }
            if ((ContDStkTrg[AMS_CUR] & 0x400) && (ContDStkTrg[AMS_CUR] & 0x100)) {
                dir = 3;
            }
            if ((ContDStkTrg[AMS_CUR] & 0x400) && (ContDStkTrg[AMS_CUR] & 0x200)) {
                dir = 5;
            }
            if ((ContDStkTrg[AMS_CUR] & 0x800) && (ContDStkTrg[AMS_CUR] & 0x200)) {
                dir = 7;
            }
            if (ContDStkTrg[AMS_CUR] & 0x8000) {
                for (j = 0; j < 4; j++) {
                    if (AMS_SLOTS[j] == -1) {
                        break;
                    }
                }
                if (j < 4) {
                    AMS_SLOTS[j] = D_80101A10_AdventureModeSetup[AMS_CUR];
                }
                for (j = 0; j < 4; j++) {
                    if (AMS_SLOTS[j] == -1) {
                        break;
                    }
                }
                if (j >= 4) {
                    D_80101FC8_AdventureModeSetup[AMS_CUR]->work[1] = 1;
                    obj->work[1] = 0;
                } else {
                    if (D_80101F70_AdventureModeSetup != 3) {
                        k = AMS_COUNT - 0x2A8;
                    } else {
                        k = AMS_COUNT - 0x281;
                    }
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)(s32)(j - k), -1, -1);
                    while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                        HuPrcVSleep();
                    }
                }
                func_80060540(D_80101A10_AdventureModeSetup[AMS_CUR] + 0x451, j - 1);
                D_80101F88_AdventureModeSetup[D_80101A10_AdventureModeSetup[AMS_CUR]]->work[1] = j + 2;
                if (j < 4) {
                    for (k = 0; k < 6; k++) {
                        o = D_80101F88_AdventureModeSetup[k];
                        if (AMS_WORK(o)->w1 == 0 && AMS_WORK(o)->w2 == 0) {
                            q = D_80101FC8_AdventureModeSetup[AMS_CUR];
                            q->work[1] = 2;
                            q->trans.x = o->trans.x;
                            q->trans.y = o->trans.y;
                            q->trans.z = o->trans.z;
                            o->work[2] = 2;
                            D_80101A10_AdventureModeSetup[AMS_CUR] = k;
                            break;
                        }
                    }
                }
                break;
            }
            if (dir == -1) {
                break;
            }
            prev[AMS_CUR] = D_80101A10_AdventureModeSetup[AMS_CUR];
            D_80101A10_AdventureModeSetup[AMS_CUR] = func_800F9030_AdventureModeSetup(dir, D_80101A10_AdventureModeSetup[AMS_CUR]);
            if (D_80101A10_AdventureModeSetup[AMS_CUR] == -1) {
                D_80101A10_AdventureModeSetup[AMS_CUR] = prev[AMS_CUR];
                k = dir + 2;
                if (k >= 4) {
                    k = dir - 2;
                }
                D_80101A10_AdventureModeSetup[AMS_CUR] = func_800F9030_AdventureModeSetup(k, (*(AMS_NEIGHBORS + D_80101A10_AdventureModeSetup[AMS_CUR]))[dir]);
                if (D_80101A10_AdventureModeSetup[AMS_CUR] == -1) {
                    D_80101A10_AdventureModeSetup[AMS_CUR] = prev[AMS_CUR];
                }
            }
            if (prev[AMS_CUR] != D_80101A10_AdventureModeSetup[AMS_CUR]) {
                D_80101F88_AdventureModeSetup[prev[AMS_CUR]]->work[2] = 1;
                o = D_80101F88_AdventureModeSetup[D_80101A10_AdventureModeSetup[AMS_CUR]];
                o->work[2] = 2;
                D_80101FC8_AdventureModeSetup[AMS_CUR]->work[1] = 3;
                c = &D_80102490_AdventureModeSetup[AMS_CUR];
                c->target.x = o->trans.x;
                c->target.y = o->trans.y;
                c->target.z = o->trans.z;
            }
            break;
        case 8:
            for (i = 0; i < 6; i++) {
                if (D_80101F88_AdventureModeSetup[i]->work[1] != 0) {
                    break;
                }
            }
            if (i < 6) {
                break;
            }
            for (i = 0; i < 6; i++) {
                if (D_80101F88_AdventureModeSetup[i]->work[2] == 0) {
                    D_80101F88_AdventureModeSetup[i]->work[1] = 10;
                }
            }
            obj->work[1] = 9;
            break;
        case 9:
            D_80101E70_AdventureModeSetup = 10;
            D_80101E74_AdventureModeSetup = 0;
            D_80101E80_AdventureModeSetup = D_8010200C_AdventureModeSetup.x / 10.0f;
            D_80101E84_AdventureModeSetup = D_8010200C_AdventureModeSetup.y;
            D_80101E84_AdventureModeSetup = D_8010200C_AdventureModeSetup.z / 10.0f;
            obj->work[1] = 10;
        case 10:
            obj->work[1] = 11;
            break;
        case 12:
            for (i = 0; i < 6; i++) {
                if (D_80101F88_AdventureModeSetup[i]->work[2] == 0) {
                    AMS_PIECES[i].unkC.x = D_80101970_AdventureModeSetup[i][0];
                    AMS_PIECES[i].unkC.y = D_80101970_AdventureModeSetup[i][1];
                    AMS_PIECES[i].unk1C = D_80101970_AdventureModeSetup[i][2];
                    AMS_PIECES[i].unkC.z = D_80101970_AdventureModeSetup[i][3];
                    D_80101F88_AdventureModeSetup[i]->work[1] = 1;
                }
            }
            obj->work[1] = 13;
            break;
        case 13:
            for (i = 0; i < 6; i++) {
                if (D_80101F88_AdventureModeSetup[i]->work[1] != 0) {
                    obj->work[1] = 14;
                }
            }
            break;
        case 14:
            for (i = 0; i < 6; i++) {
                o = D_80101F88_AdventureModeSetup[i];
                if (o->work[2] == 3) {
                    o->work[3] |= 1;
                    D_80101F88_AdventureModeSetup[i]->work[1] = 8;
                }
            }
            obj->work[1] = 15;
            break;
        case 15:
            for (i = 0; i < 6; i++) {
                if (D_80101F88_AdventureModeSetup[i]->work[1] != 0) {
                    for (j = 0; j < AMS_COUNT; j++) {
                        D_80101F88_AdventureModeSetup[j]->work[2] = 2;
                    }
                    for (; j < 6; j++) {
                        D_80101F88_AdventureModeSetup[j]->work[2] = 1;
                    }
                    for (j = 0; j < 4; j++) {
                        AMS_SLOTS[j] = -1;
                    }
                    break;
                }
            }
            if (i >= 6) {
                obj->work[1] = 0;
            }
            break;
        case 16:
            for (i = 0; i < 6; i++) {
                if (D_80101F88_AdventureModeSetup[i]->work[1] != 0) {
                    break;
                }
            }
            if (i < 6) {
                break;
            }
            obj->work[1] = 5;
            break;
        case 17:
            for (i = 0; i < 6; i++) {
                D_80101F88_AdventureModeSetup[i]->work[1] = 13;
            }
            for (j = AMS_COUNT; j < 4; j++) {
                D_80101FD8_AdventureModeSetup[j]->work[1] = 1;
            }
            for (j = 0; j < 4; j++) {
                D_80101FE8_AdventureModeSetup[j]->work[1] = 1;
            }
            obj->work[1] = 0;
            break;
        case 18:
            for (j = AMS_COUNT; j < 4; j++) {
                D_80101FD8_AdventureModeSetup[j]->work[1] = 1;
            }
            for (j = 0; j < 4; j++) {
                D_80101FE8_AdventureModeSetup[j]->work[1] = 1;
            }
            HuPrcVSleep();
            HuPrcVSleep();
            for (i = 0; i < 6; i++) {
                D_80101F88_AdventureModeSetup[i]->work[1] = 14;
            }
            obj->work[1] = 0;
            break;
        case 19:
            if (AMS_COUNT < 3) {
                for (k = AMS_COUNT; k < 4; k++) {
                    func_800184BC(D_80101F88_AdventureModeSetup[AMS_SLOTS[k]], 2);
                }
                if (D_80101F70_AdventureModeSetup != 3) {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)0x2A5, -1, -1);
                } else {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)0x27B, -1, -1);
                }
                if (D_80101E7C_AdventureModeSetup == 0) {
                    D_80101E7C_AdventureModeSetup = 1;
                    func_80071C8C(D_801025B4_AdventureModeSetup, 1);
                }
                while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                    HuPrcVSleep();
                }
                res = func_8006FCF0(D_801025B4_AdventureModeSetup, 2, 0);
                switch (res) {
                case 0:
                    for (j = AMS_COUNT; j < 4; j++) {
                        func_80052CCC(j, 0);
                        AMS_2500[j].unk00 = 1;
                        D_80101FD8_AdventureModeSetup[j]->work[1] = 3;
                        D_80101FD8_AdventureModeSetup[j]->work[3] = AMS_SLOTS[j];
                    }
                    break;
                case 1:
                    D_80101E78_AdventureModeSetup = 0;
                    obj->work[1] = 20;
                    break;
                case 2:
                    for (j = AMS_COUNT; j < 4; j++) {
                        func_80052CCC(j, 1);
                        AMS_2500[j].unk00 = 2;
                        D_80101FD8_AdventureModeSetup[j]->work[1] = 3;
                        D_80101FD8_AdventureModeSetup[j]->work[3] = AMS_SLOTS[j];
                    }
                    break;
                case 3:
                    for (j = AMS_COUNT; j < 4; j++) {
                        func_80052CCC(j, 2);
                        AMS_2500[j].unk00 = 0;
                        D_80101FD8_AdventureModeSetup[j]->work[1] = 3;
                        D_80101FD8_AdventureModeSetup[j]->work[3] = AMS_SLOTS[j];
                    }
                    break;
                default:
                    for (j = AMS_COUNT; j < 4; j++) {
                        D_80101FD8_AdventureModeSetup[j]->work[1] = 1;
                    }
                    if (D_80101F70_AdventureModeSetup != 3) {
                        D_80101FA0_AdventureModeSetup->work[1] = 30;
                        obj->work[1] = 12;
                    } else {
                        D_80101FA0_AdventureModeSetup->work[1] = 20;
                        obj->work[1] = 0;
                    }
                    break;
                }
                for (k = AMS_COUNT + 1; k < 4; k++) {
                    func_800184BC(D_80101F88_AdventureModeSetup[AMS_SLOTS[k]], 0);
                }
                if (res == 1) {
                    break;
                }
                func_800184BC(D_80101F88_AdventureModeSetup[AMS_SLOTS[AMS_COUNT]], 0);
                if (D_80101F70_AdventureModeSetup != 3) {
                    func_80071E80(D_801025B4_AdventureModeSetup, 1);
                }
                if (res == -1) {
                    break;
                }
                goto tail404;
            } else {
                obj->work[1] = 20;
            }
            break;
        case 20:
            for (j = AMS_COUNT; j < 4; j++) {
                D_80101E78_AdventureModeSetup = 0;
                k = j;
                D_80101FD8_AdventureModeSetup[j]->work[1] = 1;
                func_800184BC(D_80101F88_AdventureModeSetup[AMS_SLOTS[j]], 2);
                if (D_80101F70_AdventureModeSetup != 3) {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)0x2A4, -1, -1);
                } else {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)0x27A, -1, -1);
                }
                func_8006DA5C(D_801025B4_AdventureModeSetup, (void*)(s32)(AMS_SLOTS[j] + 0x2C), 0);
                if (D_80101E7C_AdventureModeSetup == 0) {
                    D_80101E7C_AdventureModeSetup = 1;
                    func_80071C8C(D_801025B4_AdventureModeSetup, 1);
                }
                while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                    HuPrcVSleep();
                }
                res = func_8006FCF0(D_801025B4_AdventureModeSetup, 1, 0);
                switch (res) {
                case 0:
                    func_80052CCC(j, 0);
                    AMS_2500[j].unk00 = 1;
                    goto set20;
                case 1:
                    func_80052CCC(j, 1);
                    AMS_2500[j].unk00 = 2;
                    goto set20;
                case 2:
                    func_80052CCC(j, 2);
                    AMS_2500[j].unk00 = 0;
                set20:
                    D_80101FD8_AdventureModeSetup[j]->work[1] = 3;
                    D_80101FD8_AdventureModeSetup[j]->work[3] = AMS_SLOTS[j];
                    break;
                default:
                    j -= 2;
                    if (j < AMS_COUNT - 1) {
                        D_80101E78_AdventureModeSetup = 1;
                        j = 100;
                        if (AMS_COUNT == 3) {
                            if (D_80101F70_AdventureModeSetup != 3) {
                                func_80071E80(D_801025B4_AdventureModeSetup, 1);
                                D_80101E7C_AdventureModeSetup = 0;
                                D_80101FA0_AdventureModeSetup->work[1] = 30;
                                obj->work[1] = 12;
                            } else {
                                D_80101FA0_AdventureModeSetup->work[1] = 20;
                                obj->work[1] = 0;
                            }
                        } else {
                            obj->work[1] = 19;
                        }
                    }
                    break;
                }
                if (D_80101E78_AdventureModeSetup == 0) {
                    func_800184BC(D_80101F88_AdventureModeSetup[AMS_SLOTS[k]], 0);
                }
            }
            if (D_80101E78_AdventureModeSetup == 0) {
                goto tail404;
            }
            break;
        case 21:
            LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)0x277, -1, -1);
            if (D_80101E7C_AdventureModeSetup == 0) {
                D_80101E7C_AdventureModeSetup = 1;
                func_80071C8C(D_801025B4_AdventureModeSetup, 1);
            }
            while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                HuPrcVSleep();
            }
            res = func_8006FCF0(D_801025B4_AdventureModeSetup, 1, 0);
            switch (res) {
            case 0:
                obj->work[1] = 22;
                break;
            case 1:
                for (j = 0; j < 4; j++) {
                    AMS_A4[j] = 0;
                    D_80101FE8_AdventureModeSetup[j]->work[1] = 1;
                }
                goto tail403;
            default:
                for (j = 0; j < 4; j++) {
                    AMS_A4[j] = 0;
                    D_80101FE8_AdventureModeSetup[j]->work[1] = 1;
                }
                D_80101FA0_AdventureModeSetup->work[1] = 30;
                func_80071E80(D_801025B4_AdventureModeSetup, 1);
                obj->work[1] = 12;
                break;
            }
            break;
        case 22:
            for (j = 0; j < 4; j++) {
                k = j;
                D_80101E78_AdventureModeSetup = 0;
                D_80101FE8_AdventureModeSetup[j]->work[1] = 1;
                AMS_A4[j] = 0;
                func_800184BC(D_80101F88_AdventureModeSetup[AMS_SLOTS[j]], 2);
                if (j < AMS_COUNT) {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)0x278, -1, -1);
                } else {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)0x279, -1, -1);
                }
                func_8006DA5C(D_801025B4_AdventureModeSetup, (void*)(s32)(AMS_SLOTS[k] + 0x2C), 0);
                if (D_80101E7C_AdventureModeSetup == 0) {
                    D_80101E7C_AdventureModeSetup = 1;
                    func_80071C8C(D_801025B4_AdventureModeSetup, 1);
                }
                while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                    HuPrcVSleep();
                }
                n = 0;
                res = func_8006FCF0(D_801025B4_AdventureModeSetup, 0, 0);
                switch (res) {
                case 0:
                    break;
                case 5:
                    n++;
                case 3:
                    n++;
                case 1:
                    n++;
                case 4:
                    n++;
                case 2:
                    AMS_A4[k] = (n + 1) * 10;
                    AMS_2530[j].unk00 = n;
                    D_80101FE8_AdventureModeSetup[j]->work[1] = 3;
                    D_80101FE8_AdventureModeSetup[j]->work[3] = AMS_SLOTS[k];
                    break;
                default:
                    AMS_A4[k] = 0;
                    if (j != 0) {
                        j -= 2;
                    } else {
                        D_80101E78_AdventureModeSetup = 1;
                        obj->work[1] = 21;
                    }
                    break;
                }
                func_800184BC(D_80101F88_AdventureModeSetup[AMS_SLOTS[k]], 0);
                if (D_80101E78_AdventureModeSetup != 0) {
                    break;
                }
            }
            if (D_80101E78_AdventureModeSetup != 0) {
                break;
            }
        tail403:
            if (AMS_COUNT == 4) {
            tail404:
                D_80101E7C_AdventureModeSetup = 0;
            }
        case 11:
            obj->work[1] = 0;
            break;
        }
    end:
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_800F9090_AdventureModeSetup);
#endif

void func_800FB2D8_AdventureModeSetup(omObjData* arg0) {
    arg0->work[1] = 0;
    arg0->func_ptr = 0;
    omAddPrcObj(func_800F9090_AdventureModeSetup, 0x1002U, 0x800, 0);
}

void func_800FB30C_AdventureModeSetup(omObjData* arg0) {
    Vec3f vec;
    Vec3f* vp;
    AMSPiece* p;
    s32 idx;
    s32 i;
    s32 k;

    idx = arg0->work[0];
    p = &AMS_PIECES[idx];
    vp = &vec;
    switch (arg0->work[1]) {
    case 0:
        break;
    case 1:
        func_800258EC(*arg0->model, 4, 0);
        arg0->work[3] |= 8;
        func_800A0D00(vp, D_80102000_AdventureModeSetup.x, 0.0f, D_80102000_AdventureModeSetup.z);
        vp->x -= arg0->trans.x;
        vp->y -= 0.0f;
        vp->z -= arg0->trans.z;
        arg0->rot.y = func_800B0CD8(vp->x, vp->z);
        arg0->work[1] = 2;
    case 2:
        p->unkC.y += 20.0f;
        if (p->unk1C < p->unkC.y) {
            p->unkC.y = p->unk1C;
            p->unk24.x = p->unkC.x;
            p->unk24.y = p->unkC.y;
            p->unk24.z = p->unkC.z;
            arg0->work[1] = 0;
        }
        break;
    case 3:
    case 4:
    case 5:
    case 6:
        D_80101E90_AdventureModeSetup[idx] = 20;
        k = arg0->work[1] - 3;
        D_80101EA8_AdventureModeSetup[idx] = (D_801019D0_AdventureModeSetup[k][0] - p->unkC.x) / D_80101E90_AdventureModeSetup[idx];
        D_80101EC0_AdventureModeSetup[idx] = (D_801019D0_AdventureModeSetup[k][1] - p->unkC.y) / D_80101E90_AdventureModeSetup[idx];
        p->unk48 = 0.0f;
        p->unk4C = p->unkC.z;
        p->unk50 = 180.0f / D_80101E90_AdventureModeSetup[idx];
        p->unk54 = 200.0f;
        p->unk30.x = D_801019D0_AdventureModeSetup[k][0];
        p->unk30.y = D_801019D0_AdventureModeSetup[k][1];
        p->unk30.z = p->unkC.z;
        D_80101E88_AdventureModeSetup[idx] = 7;
        arg0->work[3] |= 4;
        arg0->work[1] = 9;
        break;
    case 7:
        func_800184BC(arg0, 0);
        arg0->work[1] = 0;
        break;
    case 8:
        D_80101E90_AdventureModeSetup[idx] = 20;
        D_80101EA8_AdventureModeSetup[idx] = (p->unk24.x - p->unkC.x) / D_80101E90_AdventureModeSetup[idx];
        D_80101EC0_AdventureModeSetup[idx] = (p->unk24.y - p->unkC.y) / D_80101E90_AdventureModeSetup[idx];
        p->unk48 = 0.0f;
        p->unk4C = p->unkC.z;
        p->unk50 = 180.0f / D_80101E90_AdventureModeSetup[idx];
        p->unk54 = 200.0f;
        p->unk30.x = p->unk24.x;
        p->unk30.y = p->unk24.y;
        p->unk30.z = p->unkC.z;
        D_80101E88_AdventureModeSetup[idx] = 0;
        arg0->work[3] &= ~4;
        arg0->work[1] = 9;
        break;
    case 9:
        if (D_80101E90_AdventureModeSetup[idx] != 0) {
            D_80101E90_AdventureModeSetup[idx]--;
            p->unkC.x += D_80101EA8_AdventureModeSetup[idx];
            p->unkC.y += D_80101EC0_AdventureModeSetup[idx];
            p->unkC.z = func_800AEAC0(p->unk48) * p->unk54 + p->unk4C;
            p->unk48 += p->unk50;
        } else {
            p->unkC.x = p->unk30.x;
            p->unkC.y = p->unk30.y;
            p->unkC.z = p->unk30.z;
            arg0->work[1] = D_80101E88_AdventureModeSetup[idx];
        }
        break;
    case 10:
        p->unkC.y += 20.0f;
        if (p->unkC.y > 500.0f) {
            p->unkC.y = 500.0f;
            func_800258EC(*arg0->model, 4, 4);
            arg0->work[1] = 0;
        }
        break;
    case 11:
        func_800258EC(*arg0->model, 4, 0);
        arg0->work[1] = 12;
    case 12:
        p->unkC.y -= 20.0f;
        if (p->unkC.y < -330.0f) {
            p->unkC.y = -330.0f;
            p->unk24.x = p->unkC.x;
            p->unk24.y = p->unkC.y;
            p->unk24.z = p->unkC.z;
            func_800258EC(*arg0->model, 4, 4);
            arg0->work[1] = 0;
        }
        break;
    case 13:
        p->unkC.x += 20.0f;
        if (p->unkC.x > 400.0f) {
            p->unkC.x = 400.0f;
            arg0->work[1] = 0;
        }
        break;
    case 14:
        for (i = 0; i < 4; i++) {
            if (AMS_SLOTS[i] == idx) {
                break;
            }
        }
        if (i >= 4) {
            arg0->work[1] = 0;
        } else {
            D_80101E90_AdventureModeSetup[i] = 30;
            D_80101EA8_AdventureModeSetup[i] = (D_80101FA0_AdventureModeSetup->trans.x - D_80101A20_AdventureModeSetup[i] - arg0->trans.x) / D_80101E90_AdventureModeSetup[i];
            D_80101ED8_AdventureModeSetup[i] = (D_80101FA0_AdventureModeSetup->trans.z - D_80101A30_AdventureModeSetup[i] - arg0->trans.z) / D_80101E90_AdventureModeSetup[i];
            p->unk3C = 0.0f;
            p->unk40 = -2.0f;
            arg0->work[1] = 15;
        }
    case 15:
        for (i = 0; i < 4; i++) {
            if (AMS_SLOTS[i] == idx) {
                break;
            }
        }
        if (D_80101E90_AdventureModeSetup[i] != 0) {
            D_80101E90_AdventureModeSetup[i]--;
            arg0->trans.x += D_80101EA8_AdventureModeSetup[i];
            arg0->trans.z += D_80101ED8_AdventureModeSetup[i];
        }
        arg0->trans.y += p->unk3C;
        p->unk3C += p->unk40;
        if (p->unk3C < -20.0f) {
            p->unk3C = -20.0f;
        }
        break;
    }

    switch (arg0->work[2]) {
    case 0:
        break;
    case 1:
        func_800184BC(arg0, 0);
        arg0->work[2] = 0;
        break;
    case 2:
        func_800184BC(arg0, 2);
        arg0->work[2] = 3;
        break;
    }

    func_800A0D00(vp, D_80102000_AdventureModeSetup.x, 0.0f, D_80102000_AdventureModeSetup.z);
    vp->x -= arg0->trans.x;
    vp->y -= 0.0f;
    vp->z -= arg0->trans.z;
    arg0->rot.y = func_80029518(func_800B0CD8(vp->x, vp->z));
    if (arg0->work[3] & 8) {
        func_800F6958_AdventureModeSetup(arg0, &p->unkC);
    }
    if (arg0->work[1] == 0) {
        p->unk44 += 5.0f;
        if (p->unk44 >= 360.0f) {
            p->unk44 -= 360.0f;
        }
    } else if (p->unk44 != 0.0f || p->unk44 != 180.0f) {
        p->unk44 += 5.0f;
        if (p->unk44 >= 360.0f) {
            p->unk44 -= 360.0f;
        }
        if (p->unk44 > 0.0f && p->unk44 < 5.0f) {
            p->unk44 = 0.0f;
        }
        if (p->unk44 > 180.0f && p->unk44 < 185.0f) {
            p->unk44 = 180.0f;
        }
    }
    func_8009EA40(D_800F2B7C[*arg0->model].unk7C, 0.0f, func_800AEAC0(p->unk44) * 15.0f, 0.0f);
    func_80017DB0(arg0);
}

void func_800FBBE8_AdventureModeSetup(omObjData* arg0) {
    s32 base;

    func_800F6F34_AdventureModeSetup(arg0);
    base = D_800C59AC[D_80101A40_AdventureModeSetup].unk_00;
    arg0->model[0] = func_800174C0(base | D_800C59AC[D_80101A40_AdventureModeSetup].unk_04, 0x69D);
    arg0->trans.x = arg0->trans.y = arg0->trans.z = 0.0f;
    arg0->scale.x = arg0->scale.y = arg0->scale.z = 0.4f;
    func_8001874C(arg0, 0, base | 0x82, 1, 0);
    func_8001874C(arg0, 2, base | 3, 1, 0);
    func_8001874C(arg0, 1, base | 0x17, 1, 0);
    func_8001874C(arg0, 3, base | 0xF, 2, 0x18);
    func_8001874C(arg0, 4, base | 0x10, 2, 0x18);
    func_80025EB4(arg0->model[0], 2, 2);
    arg0->func_ptr = func_800FB30C_AdventureModeSetup;
    arg0->work[0] = (u8)D_80101A40_AdventureModeSetup;
    arg0->work[1] = 0;
    arg0->work[2] = 0;
    arg0->work[3] = 0;
    ((f32*)&D_8010206C_AdventureModeSetup)[arg0->work[0] * 27] = arg0->work[0] * 60;
    func_80017DB0(arg0);
    D_80101A40_AdventureModeSetup++;
}
void func_800FBD98_AdventureModeSetup() {
    D_80101FA8_AdventureModeSetup = omAddObj(0x1E, 0U, 0U, -1, func_800FB2D8_AdventureModeSetup);
    D_80101F88_AdventureModeSetup[0] = omAddObj(0x28, 1U, 8U, -1, func_800FBBE8_AdventureModeSetup);
    D_80101F88_AdventureModeSetup[1] = omAddObj(0x28, 1U, 8U, -1, func_800FBBE8_AdventureModeSetup);
    D_80101F88_AdventureModeSetup[2] = omAddObj(0x28, 1U, 8U, -1, func_800FBBE8_AdventureModeSetup);
    D_80101F88_AdventureModeSetup[3] = omAddObj(0x28, 1U, 8U, -1, func_800FBBE8_AdventureModeSetup);
    D_80101F88_AdventureModeSetup[4] = omAddObj(0x28, 1U, 8U, -1, func_800FBBE8_AdventureModeSetup);
    D_80101F88_AdventureModeSetup[5] = omAddObj(0x28, 1U, 8U, -1, func_800FBBE8_AdventureModeSetup);
    D_80101F88_AdventureModeSetup[6] = omAddObj(0x14, 1U, 8U, -1, func_800F8BA4_AdventureModeSetup);
}

void func_800FBEC0_AdventureModeSetup(omObjData* arg0) {
    Vec3f sp10;
    Vec3f* v;
    s32 s0;
    s32 s5;
    omObjData* obj;
    s32 idx;
    AMSetup3C* cam;

    idx = arg0->work[0];
    cam = &D_80102320_AdventureModeSetup[idx];
    v = &sp10;
    switch (arg0->work[1]) {
    case 0:
        break;
    case 1:
        func_800258EC(arg0->model[0], 4, 0);
        func_800258EC(arg0->model[1], 4, 0);
        func_800A0D00(v, D_80102000_AdventureModeSetup.x, 0.0f, D_80102000_AdventureModeSetup.z);
        v->x -= arg0->trans.x;
        v->y -= 0.0f;
        v->z -= arg0->trans.z;
        arg0->rot.y = func_800B0CD8(v->x, v->z);
        D_80101A54_AdventureModeSetup[idx] = 180.0f;
        func_800A0D00(v, 0.0f, -D_80102000_AdventureModeSetup.y, D_80102000_AdventureModeSetup.z);
        v->x -= 0.0f;
        v->y += arg0->trans.y;
        v->z -= arg0->trans.z;
        arg0->rot.x = func_80029518(func_800B0CD8(v->y, v->z));
        func_800257E4(arg0->model[1], arg0->rot.x, arg0->rot.y, 0.0f);
        cam->unk30 = 45.0f;
        arg0->work[1] = 2;
        /* fallthrough */
    case 2:
        cam->unk28 += 20.0f;
        if (cam->unk04 + 250.0f < cam->unk28) {
            cam->unk28 = cam->unk04 + 250.0f;
            arg0->work[1] = 0;
        }
        break;
    case 3:
        D_80101A54_AdventureModeSetup[idx] -= 10.0f;
        if (D_80101A54_AdventureModeSetup[idx] <= 0.0f) {
            D_80101A54_AdventureModeSetup[idx] = 0.0f;
            arg0->work[1] = 0;
        }
        break;
    case 4:
        obj = D_80101FA0_AdventureModeSetup;
        D_80101EF0_AdventureModeSetup = 20;
        D_80101EF4_AdventureModeSetup = ((obj->trans.x + 10.0f) - cam->unk24) / 20.0f;
        D_80101EF8_AdventureModeSetup = ((obj->trans.y + 200.0f) - cam->unk28) / 20.0f;
        D_80101F04_AdventureModeSetup = 0.0f;
        D_80101EFC_AdventureModeSetup = cam->unk2C;
        D_80101F08_AdventureModeSetup = 9.0f;
        D_80101F00_AdventureModeSetup = 200.0f;
        arg0->work[1] = 5;
        /* fallthrough */
    case 5:
        if (D_80101EF0_AdventureModeSetup != 0) {
            D_80101EF0_AdventureModeSetup--;
            cam->unk24 += D_80101EF4_AdventureModeSetup;
            cam->unk28 += D_80101EF8_AdventureModeSetup;
            D_80101F04_AdventureModeSetup += D_80101F08_AdventureModeSetup;
            cam->unk2C = D_80101EFC_AdventureModeSetup - (func_800AEAC0(D_80101F04_AdventureModeSetup) * D_80101F00_AdventureModeSetup);
        } else {
            arg0->work[1] = 0;
        }
        break;
    case 6:
        cam->unk28 += 20.0f;
        if (cam->unk28 > -4300.0f) {
            func_800258EC(arg0->model[0], 4, 4);
            func_800258EC(arg0->model[1], 4, 4);
            arg0->work[1] = 0;
        }
        break;
    case 7:
        cam->unk28 -= 20.0f;
        if (cam->unk28 < -4800.0f) {
            func_800258EC(arg0->model[0], 4, 4);
            func_800258EC(arg0->model[1], 4, 4);
            arg0->work[1] = 0;
        }
        break;
    case 8:
        cam->unk24 -= 20.0f;
        obj = D_80101FA0_AdventureModeSetup;
        if (cam->unk24 < obj->trans.x - 500.0f) {
            func_800258EC(arg0->model[0], 4, 4);
            func_800258EC(arg0->model[1], 4, 4);
            cam->unk24 = obj->trans.x - 500.0f;
            arg0->work[1] = 0;
        }
        break;
    case 9:
        obj = D_80101FA0_AdventureModeSetup;
        D_80101EF0_AdventureModeSetup = 20;
        D_80101EF4_AdventureModeSetup = ((obj->trans.x - D_801019F0_AdventureModeSetup[idx].x) - cam->unk24) / 20.0f;
        D_80101EF8_AdventureModeSetup = (((obj->trans.y - D_801019F0_AdventureModeSetup[idx].y) + 250.0f) - cam->unk28) / 20.0f;
        D_80101F04_AdventureModeSetup = 0.0f;
        D_80101EFC_AdventureModeSetup = cam->unk2C;
        D_80101F08_AdventureModeSetup = 9.0f;
        D_80101F00_AdventureModeSetup = 200.0f;
        arg0->work[1] = 5;
        break;
    }
    if (arg0->work[2] != 0) {
        D_80101A44_AdventureModeSetup[idx] = 1;
    }
    s5 = 0;
    if (D_80101A44_AdventureModeSetup[idx] != 0) {
        s0 = 0;
        if (arg0->scale.x > 0.35f) {
            s0 = 1;
        }
        if (arg0->scale.x < 0.35f) {
            s5 = 1;
        }
        arg0->scale.x = arg0->scale.y = func_800AEAC0(cam->unk30) * 0.2 + 0.35f - 0.1f;
        arg0->scale.z = 0.35f;
        if ((arg0->scale.x < 0.35f) & (s0 != 0)) {
            D_80101A44_AdventureModeSetup[idx] = 0;
        }
        if ((arg0->scale.x > 0.35f) & (s5 != 0)) {
            D_80101A44_AdventureModeSetup[idx] = 0;
        }
        if (arg0->scale.x == 0.35f) {
            D_80101A44_AdventureModeSetup[idx] = 0;
        }
        if (D_80101A44_AdventureModeSetup[idx] == 0) {
            arg0->scale.x = arg0->scale.y = 0.35f;
        }
        func_80025830(arg0->model[1], arg0->scale.x, arg0->scale.y, arg0->scale.z);
        cam->unk30 += 10.0f;
        if (cam->unk30 > 180.0f) {
            cam->unk30 -= 180.0f;
        }
    }
    func_80025798(arg0->model[1], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    if (arg0->work[1] == 0) {
        cam->unk34 += 5.0f;
        if (cam->unk34 >= 360.0f) {
            cam->unk34 -= 360.0f;
        }
    } else if ((cam->unk34 != 0.0f) || (cam->unk34 != 180.0f)) {
        cam->unk34 += 5.0f;
        if (cam->unk34 >= 360.0f) {
            cam->unk34 -= 360.0f;
        }
        if (cam->unk34 > 0.0f) {
            if (cam->unk34 < 5.0f) {
                cam->unk34 = 0.0f;
            }
        }
        if ((cam->unk34 > 180.0f) && (cam->unk34 < 185.0f)) {
            cam->unk34 = 180.0f;
        }
    }
    arg0->trans.x = cam->unk24;
    arg0->trans.y = (func_800AEAC0(cam->unk34) * 5.0f) + cam->unk28;
    arg0->trans.z = cam->unk2C;
    func_80025798(arg0->model[1], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_800A0D00(v, D_80102000_AdventureModeSetup.x, 0.0f, D_80102000_AdventureModeSetup.z);
    v->x -= arg0->trans.x;
    v->y -= 0.0f;
    v->z -= arg0->trans.z;
    arg0->rot.y = func_80029518(func_800B0CD8(v->x, v->z));
    func_800A0D00(v, 0.0f, -D_80102000_AdventureModeSetup.y, D_80102000_AdventureModeSetup.z);
    v->x -= 0.0f;
    v->y += arg0->trans.y;
    v->z -= arg0->trans.z;
    arg0->rot.x = func_80029518(func_800B0CD8(v->y, v->z));
    func_800257E4(arg0->model[1], arg0->rot.x, arg0->rot.y, 0.0f);
    func_8009ECB0(D_800F2B7C[arg0->model[0]].unk7C, 0.0f, D_80101A54_AdventureModeSetup[idx], 0.0f);
    func_8009ECB0(D_800F2B7C[arg0->model[1]].unk7C, 0.0f, D_80101A54_AdventureModeSetup[idx], 0.0f);
    func_80017DB0(arg0);
}
void func_800FC924_AdventureModeSetup(omObjData* arg0) {
    func_800F6F34_AdventureModeSetup(arg0);
    if (D_80101A64_AdventureModeSetup == 0x80) {
        arg0->model[0] = func_800174C0(0x90006, 0x69D);
        D_80101A64_AdventureModeSetup = arg0->model[0];
    } else {
        arg0->model[0] = func_80023FC8((s16)D_80101A64_AdventureModeSetup);
    }
    arg0->model[1] = func_800174C0((D_80101A68_AdventureModeSetup + 2) | 0x90000, 0x69D);
    arg0->scale.x = arg0->scale.y = arg0->scale.z = 0.35f;
    func_80025830(arg0->model[1], arg0->scale.x, arg0->scale.y, arg0->scale.z);
    func_80025EB4(arg0->model[0], 2, 2);
    arg0->work[0] = D_80101A68_AdventureModeSetup++;
    arg0->work[1] = 0;
    arg0->work[2] = 0;
    D_80102320_AdventureModeSetup[arg0->work[0]].unk34 = arg0->work[0] * 90;
    arg0->func_ptr = func_800FBEC0_AdventureModeSetup;
    func_80017DB0(arg0);
}
s32 func_800FCA78_AdventureModeSetup(s32 arg0, s32 arg1, s32 arg2) {
    s32 cur = arg1;

    while (1) {
        cur = D_80101870_AdventureModeSetup[cur][arg0];
        if (cur < arg2) {
            return cur;
        }
        if (cur == arg1) {
            return -1;
        }
    }
}
void func_800FCAB8_AdventureModeSetup(void) {
    omObjData* self;
    omObjData* obj;
    omObjData* it;
    AMSetup3C* cam;
    AMSetup3C* pos;
    unkAMSetupMove* dst;
    s32 sel;
    s32 prev;
    s32 dir;
    s32 dir2;
    s32 cnt;
    s32 i;

    sel = 0;
    self = D_80101FA4_AdventureModeSetup;
    while (1) {
        switch (self->work[1]) {
        case 0:
            break;
        case 1:
            i = 0;
            D_80101F0C_AdventureModeSetup = 0;
            for (; i < 4; i++) {
                if (func_800141FC(i) == 1) {
                    if (D_80102580_AdventureModeSetup.unk00 == -1) {
                        D_80102580_AdventureModeSetup.unk00 = i;
                    }
                    D_80102570_AdventureModeSetup.joined[i] = 1;
                    D_80101F0C_AdventureModeSetup++;
                } else {
                    D_80102570_AdventureModeSetup.joined[i] = 0;
                }
            }
            if (D_80101F0C_AdventureModeSetup == 0) {
                D_80102580_AdventureModeSetup.unk00 = 0;
                D_80101F0C_AdventureModeSetup = 1;
            }
            obj = D_80101FA0_AdventureModeSetup;
            for (i = 0; i < D_80101F0C_AdventureModeSetup; i++) {
                it = D_80101FB0_AdventureModeSetup[i];
                it->trans.x = obj->trans.x - D_801019F0_AdventureModeSetup[i].x;
                it->trans.y = obj->trans.y - D_801019F0_AdventureModeSetup[i].y;
                it->trans.z = obj->trans.z;
                cam = &D_80102320_AdventureModeSetup[i];
                cam->unk04 = it->trans.y;
                cam->unk24 = it->trans.x;
                cam->unk28 = it->trans.y;
                cam->unk2C = it->trans.z;
            }
        case 2:
            for (i = 0; i < D_80101F0C_AdventureModeSetup; i++) {
                obj = D_80101FB0_AdventureModeSetup[i];
                obj->work[1] = 1;
            }
            sel = 0;
            self->work[1] = 3;
            break;
        case 3:
            for (i = 0; i < D_80101F0C_AdventureModeSetup; i++) {
                if (D_80101FB0_AdventureModeSetup[i]->work[1] != 0) {
                    break;
                }
            }
            if (i == D_80101F0C_AdventureModeSetup) {
                D_80101FB0_AdventureModeSetup[sel]->work[2] = 1;
                self->work[1] = 4;
            }
            break;
        case 4:
            D_80101FC8_AdventureModeSetup[D_80102580_AdventureModeSetup.unk00]->work[1] = 2;
            obj = D_80101FC8_AdventureModeSetup[D_80102580_AdventureModeSetup.unk00];
            pos = &D_80102320_AdventureModeSetup[sel];
            obj->trans.x = pos->unk24;
            obj->trans.y = pos->unk28;
            obj->trans.z = pos->unk2C;
            if (D_80101F70_AdventureModeSetup != 3) {
                LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)(sel + 0x2A0), -1, -1);
            } else {
                LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)(sel + 0x26F), -1, -1);
            }
            func_80071C8C(D_801025B4_AdventureModeSetup, 1);
            self->work[1] = 5;
            break;
        case 5:
            if (D_80101FC8_AdventureModeSetup[D_80102580_AdventureModeSetup.unk00]->work[1] != 5) {
                break;
            }
            dir = -1;
            if (ContDStkTrg[D_80102580_AdventureModeSetup.unk00] & 0x800) {
                dir = 0;
            }
            if (ContDStkTrg[D_80102580_AdventureModeSetup.unk00] & 0x400) {
                dir = 1;
            }
            if (ContDStkTrg[D_80102580_AdventureModeSetup.unk00] & 0x200) {
                dir = 2;
            }
            if (ContDStkTrg[D_80102580_AdventureModeSetup.unk00] & 0x100) {
                dir = 3;
            }
            if ((ContDStkTrg[D_80102580_AdventureModeSetup.unk00] & 0x4000) &&
                D_80101FC8_AdventureModeSetup[D_80102580_AdventureModeSetup.unk00]->work[1] == 5) {
                for (i = 0; i < D_80101F0C_AdventureModeSetup; i++) {
                    D_80101FB0_AdventureModeSetup[i]->work[1] = 7;
                }
                D_80101FC8_AdventureModeSetup[D_80102580_AdventureModeSetup.unk00]->work[1] = 1;
                D_801025BC_AdventureModeSetup = 1;
                D_80102584_AdventureModeSetup = -1;
                self->work[1] = 0;
            } else if ((ContDStkTrg[D_80102580_AdventureModeSetup.unk00] & 0x8000) &&
                       D_80101FC8_AdventureModeSetup[D_80102580_AdventureModeSetup.unk00]->work[1] == 5) {
                PlaySound(0x53);
                i = D_80102580_AdventureModeSetup.unk00;
                for (cnt = 0; cnt < sel + 1; i++) {
                    if (D_80102570_AdventureModeSetup.joined[i] != 0) {
                        cnt++;
                        func_8006CE64(i, 2, 3, 10);
                    }
                }
                self->work[1] = 6;
            } else if (dir != -1) {
                prev = sel;
                sel = func_800FCA78_AdventureModeSetup(dir, sel, D_80101F0C_AdventureModeSetup);
                if (sel == -1) {
                    dir2 = dir + 2;
                    if (dir2 >= 4) {
                        dir2 = dir - 2;
                    }
                    sel = func_800FCA78_AdventureModeSetup(dir2, D_80101870_AdventureModeSetup[prev][dir], D_80101F0C_AdventureModeSetup);
                    if (sel == -1) {
                        sel = prev;
                    }
                }
                if (sel != prev) {
                    obj = D_80101FB0_AdventureModeSetup[prev];
                    obj->work[2] = 0;
                    obj = D_80101FB0_AdventureModeSetup[sel];
                    obj->work[2] = 1;
                    cam = &D_80102320_AdventureModeSetup[sel];
                    D_80101FC8_AdventureModeSetup[D_80102580_AdventureModeSetup.unk00]->work[1] = 3;
                    dst = &D_80102490_AdventureModeSetup[D_80102580_AdventureModeSetup.unk00];
                    dst->target.x = cam->unk24;
                    dst->target.y = cam->unk28;
                    dst->target.z = cam->unk2C;
                    if (D_80101F70_AdventureModeSetup != 3) {
                        D_801025B8_AdventureModeSetup = sel + 0x2A0;
                    } else {
                        D_801025B8_AdventureModeSetup = sel + 0x26F;
                    }
                }
            }
            break;
        case 6:
            D_801025BC_AdventureModeSetup = 1;
            D_80101FB0_AdventureModeSetup[sel]->work[2] = 0;
            D_80101FC8_AdventureModeSetup[D_80102580_AdventureModeSetup.unk00]->work[1] = 1;
            for (i = 0; i < D_80101F0C_AdventureModeSetup; i++) {
                if (i == sel) {
                    D_80101FB0_AdventureModeSetup[i]->work[1] = 4;
                } else {
                    D_80101FB0_AdventureModeSetup[i]->work[1] = 3;
                }
            }
            D_80102584_AdventureModeSetup = sel + 1;
            self->work[1] = 7;
            /* fallthrough */
        case 7:
            for (i = 0; i < D_80101F0C_AdventureModeSetup; i++) {
                if (D_80101FB0_AdventureModeSetup[i]->work[1] != 0) {
                    break;
                }
            }
            if (i == D_80101F0C_AdventureModeSetup) {
                self->work[1] = 8;
            }
            break;
        case 8:
            for (i = 0; i < D_80101F0C_AdventureModeSetup; i++) {
                if (i != sel) {
                    D_80101FB0_AdventureModeSetup[i]->work[1] = 6;
                }
            }
            if (i == D_80101F0C_AdventureModeSetup) {
                self->work[1] = 9;
            }
            break;
        case 9:
            self->work[1] = 10;
            /* fallthrough */
        case 10:
            self->work[1] = 11;
            break;
        case 12:
            obj = D_80101FA0_AdventureModeSetup;
            for (i = 0; i < D_80101F0C_AdventureModeSetup; i++) {
                if (i == sel) {
                    D_80101FB0_AdventureModeSetup[i]->work[1] = 9;
                } else {
                    it = D_80101FB0_AdventureModeSetup[i];
                    it->trans.x = obj->trans.x - D_801019F0_AdventureModeSetup[i].x;
                    it->trans.y = obj->trans.y - D_801019F0_AdventureModeSetup[i].y;
                    it->trans.z = obj->trans.z;
                    cam = &D_80102320_AdventureModeSetup[i];
                cam->unk04 = it->trans.y;
                    cam->unk24 = it->trans.x;
                    cam->unk28 = it->trans.y;
                    cam->unk2C = it->trans.z;
                    it->work[1] = 1;
                }
            }
            self->work[1] = 3;
            break;
        case 13:
            for (i = 0; i < D_80101F0C_AdventureModeSetup; i++) {
                if (i == sel) {
                    D_80101FB0_AdventureModeSetup[i]->work[1] = 8;
                }
            }
            /* fallthrough */
        case 11:
            self->work[1] = 0;
            break;
        }
        HuPrcVSleep();
    }
}
void func_800FD3A4_AdventureModeSetup(omObjData* arg0) {
    arg0->work[1] = 0;
    arg0->func_ptr = 0;
    omAddPrcObj(func_800FCAB8_AdventureModeSetup, 0x1002U, 0x800, 0);
}

void func_800FD3D8_AdventureModeSetup() {
    D_80101FA4_AdventureModeSetup = omAddObj(0x32, 0U, 0U, -1, func_800FD3A4_AdventureModeSetup);
    D_80101FB0_AdventureModeSetup[0] = omAddObj(0x32, 2U, 1U, -1, func_800FC924_AdventureModeSetup);
    D_80101FB0_AdventureModeSetup[1] = omAddObj(0x32, 2U, 1U, -1, func_800FC924_AdventureModeSetup);
    D_80101FB0_AdventureModeSetup[2] = omAddObj(0x32, 2U, 1U, -1, func_800FC924_AdventureModeSetup);
    D_80101FB0_AdventureModeSetup[3] = omAddObj(0x32, 2U, 1U, -1, func_800FC924_AdventureModeSetup);
}

void func_800FD4A4_AdventureModeSetup(omObjData* arg0) {
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    omObjData* temp_s0;

    temp_s0 = D_80101FC0_AdventureModeSetup;
    switch (arg0->work[1]) {
    case 1:
        func_800258EC(temp_s0->model[3], 4, 0);
        func_800258EC(temp_s0->model[4], 4, 0);
        D_80101F10_AdventureModeSetup = 0.0f;
        arg0->work[1] = 2;
        /* fallthrough */
    case 2:
        D_80101F10_AdventureModeSetup += 0.1f;
        if (D_80101F10_AdventureModeSetup > 0.315f) {
            D_80101F10_AdventureModeSetup = 0.315f;
            arg0->work[1] = 0;
        }
        func_80025830(temp_s0->model[3], D_80101F10_AdventureModeSetup, D_80101F10_AdventureModeSetup, D_80101F10_AdventureModeSetup);
        func_80025830(temp_s0->model[4], D_80101F10_AdventureModeSetup, D_80101F10_AdventureModeSetup, D_80101F10_AdventureModeSetup);
        return;
    case 3:
        D_80101F10_AdventureModeSetup -= 0.1f;
        if (D_80101F10_AdventureModeSetup < 0.0f) {
            D_80101F10_AdventureModeSetup = 0.0f;
            func_800258EC(temp_s0->model[3], 4, 4);
            func_800258EC(temp_s0->model[4], 4, 4);
            arg0->work[1] = 0;
        }
        func_80025830(temp_s0->model[3], D_80101F10_AdventureModeSetup, D_80101F10_AdventureModeSetup, D_80101F10_AdventureModeSetup);
        func_80025830(temp_s0->model[4], D_80101F10_AdventureModeSetup, D_80101F10_AdventureModeSetup, D_80101F10_AdventureModeSetup);
        return;
    case 4:
        D_80101F14_AdventureModeSetup = 0.0f;
        D_80101F18_AdventureModeSetup = 18.0f;
        D_80101F1C_AdventureModeSetup = D_800F2B7C[temp_s0->model[3]].unk_24;
        arg0->work[1] = 5;
        /* fallthrough */
    case 5:
        D_80101F14_AdventureModeSetup += D_80101F18_AdventureModeSetup;
        if (D_80101F14_AdventureModeSetup > 180.0f) {
            D_80101F14_AdventureModeSetup = 0.0f;
            arg0->work[1] = 0;
        }
        D_800F2B7C[temp_s0->model[3]].unk_24 = D_80101F1C_AdventureModeSetup - (func_800AEAC0(D_80101F14_AdventureModeSetup) * 10.0f);
        return;
    case 6:
        D_80101F14_AdventureModeSetup = 0.0f;
        D_80101F18_AdventureModeSetup = 18.0f;
        D_80101F1C_AdventureModeSetup = D_800F2B7C[temp_s0->model[4]].unk_24;
        arg0->work[1] = 7;
        /* fallthrough */
    case 7:
        D_80101F14_AdventureModeSetup += D_80101F18_AdventureModeSetup;
        if (D_80101F14_AdventureModeSetup > 180.0f) {
            D_80101F14_AdventureModeSetup = 0.0f;
            arg0->work[1] = 0;
        }
        D_800F2B7C[temp_s0->model[4]].unk_24 = (func_800AEAC0(D_80101F14_AdventureModeSetup) * 10.0f) + D_80101F1C_AdventureModeSetup;
    case 0:
    default:
        return;
    }
}

void func_800FD7F0_AdventureModeSetup(omObjData* arg0) {
    arg0->work[1] = 0;
    arg0->func_ptr = func_800FD4A4_AdventureModeSetup;
}

void func_800FD804_AdventureModeSetup(void) {
    omObjData* self;
    unk_Struct00* p;
    omObjData* obj;
    s32 prev;
    s32 dir;
    s32 i;

    self = D_80101FC0_AdventureModeSetup;
    p = &D_80102410_AdventureModeSetup;
    while (1) {
        switch (self->work[1]) {
        case 0:
            break;
        case 1:
            func_800258EC(self->model[0], 4, 0);
            func_800258EC(self->model[2], 4, 0);
            func_800258EC(self->model[5], 4, 4);
            func_800258EC(self->model[6], 4, 4);
            func_800258EC(self->model[7], 4, 4);
            func_800258EC(self->model[8], 4, 4);
            func_800258EC(self->model[9], 4, 4);
            func_800258EC(self->model[10], 4, 4);
            func_800258EC(self->model[11], 4, 4);
            func_800258EC(self->model[12], 4, 4);
            obj = D_80101FA0_AdventureModeSetup;
            p->unk24.x = obj->trans.x + 150.0f;
            p->unk24.y = obj->trans.y - 150.0f;
            p->unk24.z = obj->trans.z;
            D_80102410_AdventureModeSetup.pos.y = p->unk24.y;
            p->unk30.y = 0.0f;
            self->scale.x = self->scale.z = 0.45f;
            self->scale.y = 0.5f;
            if (_CheckFlag(0x27) != 0 && _CheckFlag(0x17) != 0 && _CheckFlag(3) != 0 && _CheckFlag(0x18) == 0) {
                D_80101A6C_AdventureModeSetup = 7;
            } else {
                D_80101A6C_AdventureModeSetup = 0;
            }
            func_800258EC(self->model[D_80101A6C_AdventureModeSetup + 5], 4, 0);
            self->work[1] = 2;
            /* fallthrough */
        case 2:
            p->unk24.y += 20.0f;
            if (p->pos.y + 280.0f < p->unk24.y) {
                p->unk24.y = p->pos.y + 280.0f;
                self->work[1] = 0;
            }
            break;
        case 3:
            self->work[1] = 4;
            /* fallthrough */
        case 4:
            p->unk30.y += 10.0f;
            if (p->unk30.y >= 180.0f) {
                p->unk30.y = 180.0f;
                D_80101FFC_AdventureModeSetup->work[1] = 1;
                self->work[1] = 5;
            }
            break;
        case 5:
            LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)(D_80101A6C_AdventureModeSetup + 0x28C), -1, -1);
            func_80071C8C(D_801025B4_AdventureModeSetup, 1);
            while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                HuPrcVSleep();
            }
            self->work[1] = 6;
            /* fallthrough */
        case 6:
            if (ContDStkTrg[D_80102580_AdventureModeSetup.unk00] & 0x4000) {
                D_80101FFC_AdventureModeSetup->work[1] = 3;
                func_80071E80(D_801025B4_AdventureModeSetup, 1);
                self->work[1] = 13;
            }
            dir = -1;
            if (ContDStkTrg[D_80102580_AdventureModeSetup.unk00] & 0x200) {
                dir = 2;
            }
            if (ContDStkTrg[D_80102580_AdventureModeSetup.unk00] & 0x100) {
                dir = 3;
            }
            if (ContDStkTrg[D_80102580_AdventureModeSetup.unk00] & 0x8000) {
                PlaySound(0x53);
                LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)0x28B, -1, -1);
                while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                    HuPrcVSleep();
                }
                if (func_8006FCF0(D_801025B4_AdventureModeSetup, 0, 0) == 0) {
                    D_80101FFC_AdventureModeSetup->work[1] = 3;
                    D_8010259C_AdventureModeSetup.unk00 = D_80101A6C_AdventureModeSetup;
                    self->work[1] = 11;
                    func_80071E80(D_801025B4_AdventureModeSetup, 1);
                } else {
                    LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)(D_80101A6C_AdventureModeSetup + 0x28C), -1, -1);
                }
            } else if (dir != -1) {
                prev = D_80101A6C_AdventureModeSetup;
                if (dir == 2) {
                    D_80101A6C_AdventureModeSetup = prev - 1;
                    D_80101FFC_AdventureModeSetup->work[1] = 4;
                }
                if (dir == 3) {
                    D_80101A6C_AdventureModeSetup++;
                    D_80101FFC_AdventureModeSetup->work[1] = 6;
                }
                if (_CheckFlag(0x27) == 0) {
                    if (D_80101A6C_AdventureModeSetup < 0) {
                        D_80101A6C_AdventureModeSetup = 5;
                    }
                    if (D_80101A6C_AdventureModeSetup >= 6) {
                        D_80101A6C_AdventureModeSetup = 0;
                    }
                } else if (_CheckFlag(0x17) == 0 || _CheckFlag(3) == 0) {
                    if (D_80101A6C_AdventureModeSetup < 0) {
                        D_80101A6C_AdventureModeSetup = 6;
                    }
                    if (D_80101A6C_AdventureModeSetup >= 7) {
                        D_80101A6C_AdventureModeSetup = 0;
                    }
                } else if (_CheckFlag(0x18) == 0) {
                    D_80101A6C_AdventureModeSetup = 7;
                } else {
                    if (D_80101A6C_AdventureModeSetup < 0) {
                        D_80101A6C_AdventureModeSetup = 7;
                    }
                    if (D_80101A6C_AdventureModeSetup >= 8) {
                        D_80101A6C_AdventureModeSetup = 0;
                    }
                }
                D_801025B8_AdventureModeSetup = D_80101A6C_AdventureModeSetup + 0x28C;
                if (_CheckFlag(0x18) != 0 && D_80101A6C_AdventureModeSetup == 7) {
                    D_801025B8_AdventureModeSetup = 0x294;
                }
                func_80025830(self->model[1], self->scale.x, self->scale.y, self->scale.z);
                func_800258EC(self->model[prev + 5], 4, 4);
                func_800258EC(self->model[1], 4, 0);
                PlaySound(0x10B);
                HuPrcSleep(10);
                func_800258EC(self->model[1], 4, 4);
                func_800258EC(self->model[D_80101A6C_AdventureModeSetup + 5], 4, 0);
            }
            break;
        case 7:
            self->work[1] = 8;
            /* fallthrough */
        case 8:
            p->unk30.y -= 10.0f;
            if (p->unk30.y <= 0.0f) {
                p->unk30.y = 0.0f;
                self->work[1] = 9;
                p->unk30.x = 45.0f;
            }
            break;
        case 9:
            self->scale.x = func_800AEAC0(p->unk30.x) * 0.2 + 0.45f - 0.1f;
            self->scale.y = func_800AEAC0(p->unk30.x) * 0.2 + 0.5 - 0.1f;
            if (p->unk30.x > 550.0f) {
                p->unk30.x = 550.0f;
                p->pos.x = self->trans.x + 20.0f;
                p->pos.y = self->trans.y;
                p->pos.z = self->trans.z - 70.0f;
                HuPrcVSleep();
                func_800257E4(self->model[D_80101A6C_AdventureModeSetup + 5], self->rot.x, self->rot.y + 180.0f, self->rot.z);
                self->work[1] = 10;
            }
            func_80025830(self->model[1], self->scale.x, self->scale.y, self->scale.z);
            func_80025830(self->model[D_80101A6C_AdventureModeSetup + 5], self->scale.x, self->scale.y, self->scale.z);
            p->unk30.x += 15.0f;
            break;
        case 10:
            p->unk24.y += 20.0f;
            if (p->unk24.y > -4000.0f) {
                func_800258EC(self->model[0], 4, 4);
                func_800258EC(self->model[2], 4, 4);
                func_800258EC(self->model[3], 4, 4);
                func_800258EC(self->model[4], 4, 4);
                for (i = 0; i < 8; i++) {
                    if (D_80101A6C_AdventureModeSetup != i) {
                        func_800258EC(self->model[i + 5], 4, 4);
                    }
                }
                self->work[1] = 11;
            }
            break;
        case 11:
            obj = D_80101FA0_AdventureModeSetup;
            D_80101F20_AdventureModeSetup = 20;
            D_80101F24_AdventureModeSetup = ((obj->trans.x + 25.0f) - p->unk24.x) / 20.0f;
            D_80101F28_AdventureModeSetup = ((obj->trans.y + 120.0f) - p->unk24.y) / 20.0f;
            D_80101F34_AdventureModeSetup = 0.0f;
            D_80101F2C_AdventureModeSetup = p->unk24.z;
            D_80101F38_AdventureModeSetup = 9.0f;
            D_80101F30_AdventureModeSetup = 200.0f;
            D_80101F3C_AdventureModeSetup = 0.011499999f;
            D_80101F40_AdventureModeSetup = 0.014f;
            self->work[1] = 12;
            /* fallthrough */
        case 12:
            if (D_80101F20_AdventureModeSetup != 0) {
                D_80101F20_AdventureModeSetup--;
                p->unk24.x += D_80101F24_AdventureModeSetup;
                p->unk24.y += D_80101F28_AdventureModeSetup;
                p->unk24.z = D_80101F2C_AdventureModeSetup - (func_800AEAC0(D_80101F34_AdventureModeSetup) * D_80101F30_AdventureModeSetup);
                D_80101F34_AdventureModeSetup += D_80101F38_AdventureModeSetup;
                self->scale.x -= D_80101F3C_AdventureModeSetup;
                self->scale.y -= D_80101F40_AdventureModeSetup;
                self->scale.z = self->scale.x;
            } else {
                self->scale.x = self->scale.y = self->scale.z = 0.22f;
                self->work[1] = 0;
            }
            break;
        case 13:
            p->unk30.y -= 10.0f;
            if (p->unk30.y <= 0.0f) {
                p->unk30.y = 0.0f;
                self->work[1] = 14;
            }
            break;
        case 14:
            p->unk24.y -= 20.0f;
            obj = D_80101FA0_AdventureModeSetup;
            if (p->unk24.y < obj->trans.y - 300.0f) {
                func_800258EC(self->model[0], 4, 4);
                func_800258EC(self->model[1], 4, 4);
                func_800258EC(self->model[2], 4, 4);
                func_800258EC(self->model[3], 4, 4);
                func_800258EC(self->model[4], 4, 4);
                for (i = 0; i < 8; i++) {
                    if (D_80101A6C_AdventureModeSetup != i) {
                        func_800258EC(self->model[i + 5], 4, 4);
                    }
                }
                D_8010259C_AdventureModeSetup.unk00 = -1;
                p->unk24.y = obj->trans.y - 300.0f;
                self->work[1] = 0;
            }
            break;
        case 15:
            obj = D_80101FA0_AdventureModeSetup;
            D_80101F20_AdventureModeSetup = 20;
            D_80101F24_AdventureModeSetup = ((obj->trans.x + 150.0f) - p->unk24.x) / 20.0f;
            D_80101F28_AdventureModeSetup = ((p->pos.y + 280.0f) - p->unk24.y) / 20.0f;
            D_80101F34_AdventureModeSetup = 0.0f;
            D_80101F2C_AdventureModeSetup = obj->trans.z;
            D_80101F38_AdventureModeSetup = 9.0f;
            D_80101F30_AdventureModeSetup = 200.0f;
            D_80101F3C_AdventureModeSetup = -0.011499999f;
            D_80101F40_AdventureModeSetup = -0.014f;
            self->work[1] = 16;
            /* fallthrough */
        case 16:
            if (D_80101F20_AdventureModeSetup != 0) {
                D_80101F20_AdventureModeSetup--;
                p->unk24.x += D_80101F24_AdventureModeSetup;
                p->unk24.y += D_80101F28_AdventureModeSetup;
                D_80101F34_AdventureModeSetup += D_80101F38_AdventureModeSetup;
                p->unk24.z = D_80101F2C_AdventureModeSetup - (func_800AEAC0(D_80101F34_AdventureModeSetup) * D_80101F30_AdventureModeSetup);
                self->scale.x -= D_80101F3C_AdventureModeSetup;
                self->scale.y -= D_80101F40_AdventureModeSetup;
                self->scale.z = self->scale.x;
            } else {
                self->scale.x = self->scale.z = 0.45f;
                self->scale.y = 0.5f;
                self->work[1] = 0;
            }
            break;
        case 19:
            p->unk24.x -= 20.0f;
            obj = D_80101FA0_AdventureModeSetup;
            if (p->unk24.x < obj->trans.x - 500.0f) {
                func_800258EC(self->model[0], 4, 4);
                func_800258EC(self->model[1], 4, 4);
                func_800258EC(self->model[2], 4, 4);
                func_800258EC(self->model[3], 4, 4);
                func_800258EC(self->model[4], 4, 4);
                for (i = 0; i < 8; i++) {
                    if (D_80101A6C_AdventureModeSetup != i) {
                        func_800258EC(self->model[i + 5], 4, 4);
                    }
                }
                self->scale.x = self->scale.z = 0.45f;
                self->scale.y = 0.5f;
                if (D_80101A6C_AdventureModeSetup != -1) {
                    func_80025830(self->model[D_80101A6C_AdventureModeSetup + 5], self->scale.x, self->scale.y, self->scale.z);
                }
                p->unk24.x = obj->trans.x - 500.0f;
                self->work[1] = 0;
            }
            break;
        }
        HuPrcVSleep();
    }
}
void func_800FE68C_AdventureModeSetup(omObjData* arg0) {
    Vec3f sp10;
    Vec3f* vec_ptr;
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f22;
    f32 temp_f24;
    s16 temp_a0;
    s32 i;
    unk_Struct00* temp_ptr;

    temp_ptr = &D_80102410_AdventureModeSetup;
    vec_ptr = &sp10;
    if (arg0->work[1] != 0) {
        D_80102448_AdventureModeSetup += 5.0f;
        if (D_80102448_AdventureModeSetup >= 360.0f) {
            D_80102448_AdventureModeSetup -= 360.0f;
        }
    } else if ((temp_ptr->unk30.z != 0.0f) || (temp_ptr->unk30.z != 180.0f)) {
        temp_ptr->unk30.z += 5.0f;
        if (temp_ptr->unk30.z >= 360.0f) {
            temp_ptr->unk30.z -= 360.0f;
        }
        if (temp_ptr->unk30.z > 0.0f) {
            if (temp_ptr->unk30.z < 5.0f) {
                temp_ptr->unk30.z = 0.0f;
            }
        }
        if ((temp_ptr->unk30.z > 180.0f) && (temp_ptr->unk30.z < 185.0f)) {
            temp_ptr->unk30.z = 180.0f;
        }
    }

    arg0->trans.x = temp_ptr->unk24.x;
    arg0->trans.y = (func_800AEAC0(temp_ptr->unk30.z) * 5.0f) + temp_ptr->unk24.y;
    arg0->trans.z = temp_ptr->unk24.z;
    func_80025798(arg0->model[1], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_800A0D00(vec_ptr, D_80102000_AdventureModeSetup.x, 0.0f, D_80102000_AdventureModeSetup.z);
    vec_ptr->x -= arg0->trans.x;
    vec_ptr->y -= 0.0f;
    vec_ptr->z -= arg0->trans.z;
    arg0->rot.y = func_80029518(func_800B0CD8(vec_ptr->x, vec_ptr->z));
    func_800A0D00(vec_ptr, 0.0f, -D_80102000_AdventureModeSetup.y, D_80102000_AdventureModeSetup.z);

    vec_ptr->x -= 0.0f;
    vec_ptr->y += arg0->trans.y;
    vec_ptr->z -= arg0->trans.z;
    arg0->rot.x = func_80029518(func_800B0CD8(vec_ptr->y, vec_ptr->z));
    func_80025798(arg0->model[1], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_80025798(arg0->model[2], arg0->trans.x, arg0->trans.y, arg0->trans.z);

    temp_f0 = func_80029518(func_800B0CD8(50.0f, -30.0f) + temp_ptr->unk30.y + arg0->rot.y);
    temp_f24 = (arg0->scale.x / 0.45f) * 92.799995f;
    temp_f22 = (arg0->scale.x / 0.45f) * 40.0f;
    temp_f20 = (func_800AEAC0(temp_f0) * temp_f24) + arg0->trans.x;
    func_80025798(arg0->model[3], temp_f20, temp_f22 + arg0->trans.y, (func_800AEFD0(temp_f0) * temp_f24) + arg0->trans.z);
    temp_f0 = func_80029518(func_800B0CD8(-50.0f, -30.0f) + temp_ptr->unk30.y + arg0->rot.y);
    temp_f20_2 = (func_800AEAC0(temp_f0) * temp_f24) + arg0->trans.x;
    func_80025798(arg0->model[4], temp_f20_2, temp_f22 + arg0->trans.y, (func_800AEFD0(temp_f0) * temp_f24) + arg0->trans.z);

    for (i = 0; i < 8; i++) {
        temp_a0 = arg0->model[i + 5];
        func_80025798(temp_a0, arg0->trans.x, arg0->trans.y, arg0->trans.z + 5.0f);
    }

    func_800257E4(arg0->model[1], arg0->rot.x, arg0->rot.y, 0.0f);
    func_800257E4(arg0->model[2], arg0->rot.x, arg0->rot.y, 0.0f);
    func_800257E4(arg0->model[3], arg0->rot.x, arg0->rot.y, 0.0f);
    func_800257E4(arg0->model[4], arg0->rot.x, arg0->rot.y, 0.0f);
    func_8009ECB0(D_800F2B7C[arg0->model[0]].unk7C[0], 0.0f, temp_ptr->unk30.y, 0.0f);
    func_8009ECB0(D_800F2B7C[arg0->model[1]].unk7C[0], 0.0f, temp_ptr->unk30.y, 0.0f);
    func_8009ECB0(D_800F2B7C[arg0->model[2]].unk7C[0], 0.0f, temp_ptr->unk30.y, 0.0f);
    func_8009ECB0(D_800F2B7C[arg0->model[3]].unk7C[0], 0.0f, temp_ptr->unk30.y - 180.0f, 0.0f);
    func_8009ECB0(D_800F2B7C[arg0->model[4]].unk7C[0], 0.0f, 180.0f - temp_ptr->unk30.y, 180.0f);

    for (i = 0; i < 8; i++) {
        temp_a0 = arg0->model[i + 5];
        func_800257E4(temp_a0, arg0->rot.x, arg0->rot.y, 0.0f);
        func_8009ECB0(D_800F2B7C[arg0->model[i + 5]].unk7C[0], 0.0f, temp_ptr->unk30.y, 0.0f);
    }

    temp_f20_3 = arg0->scale.x * 1.1f;
    func_80025830(arg0->model[1], temp_f20_3, temp_f20_3, temp_f20_3);
    func_80025830(arg0->model[2], temp_f20_3, temp_f20_3, temp_f20_3);
    for (i = 5; i < 0xD; i++) {
        temp_a0 = arg0->model[i];
        func_80025830(temp_a0, temp_f20_3, temp_f20_3, temp_f20_3);
    }
    func_80017DB0(arg0);
}

void func_800FED7C_AdventureModeSetup(omObjData* arg0) {
    f32 temp_f20;
    s16 temp_a0;
    s32 i;

    func_800F6F34_AdventureModeSetup(arg0);
    arg0->model[0] = func_800174C0(0x90007, 0x69D);
    arg0->model[1] = func_800174C0(0x90008, 0x69D);
    arg0->model[2] = func_800174C0(0x90009, 0x69D);
    arg0->model[3] = func_800174C0(0x9000A, 0x69D);
    arg0->model[4] = func_800174C0(0x9000A, 0x69D);
    arg0->model[5] = func_800174C0(0x90011, 0x2BD);
    arg0->model[6] = func_800174C0(0x90014, 0x2BD);
    arg0->model[7] = func_800174C0(0x90012, 0x2BD);
    arg0->model[8] = func_800174C0(0x90013, 0x2BD);
    arg0->model[9] = func_800174C0(0x90015, 0x2BD);
    arg0->model[10] = func_800174C0(0x90016, 0x2BD);
    arg0->model[11] = func_800174C0(0x90017, 0x2BD);
    arg0->model[12] = func_800174C0(0x90018, 0x2BD);

    arg0->scale.z = 0.45f;
    arg0->scale.x = 0.45f;
    arg0->scale.y = 0.5f;
    for (i = 3; i < 5; i++) {
        temp_a0 = arg0->model[i];
        func_80025830(temp_a0, arg0->scale.x * 0.7f, arg0->scale.y * 0.7f, arg0->scale.z * 0.7f);
    }
    temp_f20 = arg0->scale.x * 1.1f;
    func_80025830((s16) arg0->model[1], temp_f20, temp_f20, temp_f20);
    func_80025830((s16) arg0->model[2], temp_f20, temp_f20, temp_f20);
    for (i = 5; i < 0xD; i++) {
        temp_a0 = arg0->model[i];
        func_80025830(temp_a0, temp_f20, temp_f20, temp_f20);
    }

    func_80025EB4(arg0->model[0], 2, 2);
    arg0->work[1] = 0;
    D_80102448_AdventureModeSetup = 0.0f;
    arg0->func_ptr = func_800FE68C_AdventureModeSetup;
    omAddPrcObj(func_800FD804_AdventureModeSetup, 0x1002U, 0x800, 0);
    D_80101FFC_AdventureModeSetup = omAddObj(0x3C, 0U, 0U, -1, func_800FD7F0_AdventureModeSetup);
    func_80017DB0(arg0);
}

void func_800FF064_AdventureModeSetup() {
    D_80101FC0_AdventureModeSetup = omAddObj(0x3C, 0xEU, 1U, -1, func_800FED7C_AdventureModeSetup);
}

// retail loads &GwSystem/&D_801025A0 into a1/a0 just before the tail; here GCC hoists them to the function start (masked 20);
// assigning them after the second loop makes GCC CSE &GwSystem into the playType store instead (M1c)
#ifdef NON_MATCHING
void func_800FF0A0_AdventureModeSetup(void) {
    s32 saved[4];
    s32 i;
    s32 k;
    s32 j;
    s16 board;
    GW_PLAYER* p;
    GW_SYSTEM* sys = &GwSystem;
    s32* sel = (s32*)&D_801025A0_AdventureModeSetup;

    for (i = 0; i < 4; i++) {
        saved[i] = AMSD_ORDER[i];
    }
    for (i = 0; i < 4; i++) {
        AMSD_ORDER[i] = -1;
    }
    i = 0;
    j = 0;
    k = D_80102584_AdventureModeSetup;
    for (; i < 4; i++) {
        if (j < D_80102580_AdventureModeSetup.unk04 && AMSD_ACTIVE[i] != 0) {
            AMSD_ORDER[i] = saved[j++];
        } else {
            AMSD_ORDER[i] = saved[k++];
        }
    }
    i = 0;
    j = 0;
    for (; i < 4; i++) {
        p = &GwPlayer[i];
        p->port = i;
        p->character = AMSD_ORDER[i];
        if (j < AMSD_ORDER[-1] && AMSD_ACTIVE[i] != 0) {
            j++;
            p->flags = 0;
        } else {
            p->flags = 1;
        }
        if (D_80101F70_AdventureModeSetup != 3) {
            p->coins = 0;
        } else {
            p->coins = AMSD_COINS[i];
        }
    }
    GwSystem.playType = D_801025A2_AdventureModeSetup;
    if (D_80101F70_AdventureModeSetup == 3) {
        sel[-1] = 9;
    }
    switch (D_8010259C_AdventureModeSetup.unk00) {
        case 0: board = 0; break;
        case 1: board = 1; break;
        case 2: board = 2; break;
        case 3: board = 3; break;
        case 4: board = 4; break;
        case 5: board = 5; break;
        case 6: board = 6; break;
        case 7: board = 7; break;
        case 8: board = 8; break;
        case 9: board = 9; break;
        default:
            osSyncPrintf("how!! mapnum");
            while (1) {
                HuPrcVSleep();
            }
    }
    sys->curBoardIndex = board;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_AdventureModeSetup/2BF1D0", func_800FF0A0_AdventureModeSetup);
#endif
const char D_80101DB0_AdventureModeSetup[] = "30";

const char D_80101DB4_AdventureModeSetup[] = "10";

const char D_80101DB8_AdventureModeSetup[] = "50";

const char D_80101DBC_AdventureModeSetup[] = "35";

const char D_80101DC0_AdventureModeSetup[] = "20";

void func_800FF328_AdventureModeSetup(void) {
    s32 pad[4]; // retail's frame has an unexplained 16-byte local area
    omObjData* obj = D_80101FC4_AdventureModeSetup;
    unk_D80102450_AdventureModeSetup* c = &D_80102450_AdventureModeSetup;
    omObjData* tgt;
    f32 x;
    f32 y;
    f32 step;
    f32 t;
    f32 diff;
    s32 ret;
    s32 n;

    while (1) {
        switch (obj->work[1]) {
            case 0:
                break;
            case 1:
                func_800258EC(obj->model[0], 4, 0);
                func_800258EC(obj->model[1], 4, 0);
                func_800258EC(obj->model[2], 4, 0);
                tgt = D_80101FA0_AdventureModeSetup;
                obj->trans.x = tgt->trans.x;
                c->unk28 = tgt->trans.y;
                obj->trans.z = tgt->trans.z - 50.0f;
                obj->scale.z = 0.2f;
                obj->scale.y = 0.2f;
                obj->scale.x = 0.2f;
                c->unk34 = -19.0f;
                c->unk38 = 1.0f;
                c->unk3C = 0;
                c->unk2C = 65.0f;
                D_80101F48_AdventureModeSetup = 65.0f;
                D_80101F4C_AdventureModeSetup = 65.0f;
                c->unk18 = 0;
                c->unk24 = 0.0f;
                D_801025CC_AdventureModeSetup = 0;
                obj->work[1] = 2;
                /* fallthrough */
            case 2:
                obj->scale.x += 0.05f;
                if (obj->scale.x > 0.6f) {
                    obj->scale.x = 0.6f;
                }
                t = obj->scale.x;
                obj->scale.z = t;
                obj->scale.y = t;
                c->unk34 += c->unk38;
                if (c->unk34 > 40.0f) {
                    c->unk3C++;
                    c->unk34 = 40.0f;
                }
                c->unk28 -= c->unk34;
                obj->trans.x += 10.0f;
                tgt = D_80101FA0_AdventureModeSetup;
                if (tgt->trans.x + 170.0f < obj->trans.x) {
                    D_80101F44_AdventureModeSetup = 0;
                    c->unk1C = 0;
                    D_801025C8_AdventureModeSetup = 0;
                    if (D_80101F70_AdventureModeSetup != 3) {
                        D_801025C4_AdventureModeSetup = 0x296;
                        D_801025D0_AdventureModeSetup = D_80101A70_AdventureModeSetup[D_8010259C_AdventureModeSetup.unk00][0];
                    } else {
                        D_801025C4_AdventureModeSetup = 0x27D;
                        D_801025D0_AdventureModeSetup = D_80101AD0_AdventureModeSetup[1 - 1];
                    }
                    c->unk18 = 1;
                    obj->work[1] = 3;
                }
                break;
            case 3:
                if ((ContDStkTrg[D_80102580_AdventureModeSetup.unk00] & 0x4000) && D_801025C8_AdventureModeSetup != 0 &&
                    (c->unk2C == 65.0f || c->unk2C == 180.0f ||
                     c->unk2C == 300.0f)) {
                    obj->work[1] = 4;
                    break;
                }
                if ((ContDStkTrg[D_80102580_AdventureModeSetup.unk00] & 0x8000) && c->unk18 != 0 &&
                    D_801025C8_AdventureModeSetup != 0 && D_801025C4_AdventureModeSetup == -1) {
                    PlaySound(0x53);
                    if (D_80101F70_AdventureModeSetup != 3) {
                        LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)0x299, -1, -1);
                    } else {
                        LoadStringIntoWindow(D_801025B4_AdventureModeSetup, (void*)(s32)0x280, -1, -1);
                    }
                    while (func_8006FCC0(D_801025B4_AdventureModeSetup) != 0) {
                        HuPrcVSleep();
                    }
                    ret = func_8006FCF0(D_801025B4_AdventureModeSetup, 0, 0);
                    switch (ret) {
                        case 0:
                            switch (c->unk18) {
                                case 1:
                                    AMSD_MODE = 0;
                                    break;
                                case 2:
                                    AMSD_MODE = 1;
                                    break;
                                case 3:
                                    AMSD_MODE = 2;
                                    break;
                                default:
                                    osSyncPrintf("how!! clock");
                                    while (1) {
                                        HuPrcVSleep();
                                    }
                            }
                            func_80071E80(D_801025B4_AdventureModeSetup, 1);
                            obj->work[1] = 0;
                            break;
                        case 1:
                        default:
                            n = 0;
                            if (D_80101F48_AdventureModeSetup == 65.0f) {
                                n = 1;
                            }
                            if (D_80101F48_AdventureModeSetup == 180.0f) {
                                n = 2;
                            }
                            if (D_80101F48_AdventureModeSetup == 300.0f) {
                                n = 3;
                            }
                            if (n != 0) {
                                if (D_80101F70_AdventureModeSetup != 3) {
                                    D_801025C4_AdventureModeSetup = n + 0x295;
                                    D_801025D0_AdventureModeSetup = D_80101A70_AdventureModeSetup[D_8010259C_AdventureModeSetup.unk00][n - 1];
                                } else {
                                    D_801025C4_AdventureModeSetup = n + 0x27C;
                                    D_801025D0_AdventureModeSetup = D_80101AD0_AdventureModeSetup[n - 1];
                                }
                            }
                            break;
                        case 2:
                            AMSD_MODE = 0x3E8;
                            obj->work[1] = 0;
                            break;
                    }
                    break;
                }
                if (D_801025C8_AdventureModeSetup != 0 && D_801025C4_AdventureModeSetup == -1) {
                    x = ContStkX[D_80102580_AdventureModeSetup.unk00];
                    y = ContStkY[D_80102580_AdventureModeSetup.unk00];
                    if (ContBtnTrg[D_80102580_AdventureModeSetup.unk00] & 0x400) {
                        x = 0.0f;
                        y = -50.0f;
                    }
                    if (ContBtnTrg[D_80102580_AdventureModeSetup.unk00] & 0x200) {
                        x = -50.0f;
                        y = 0.0f;
                    }
                    if (ContBtnTrg[D_80102580_AdventureModeSetup.unk00] & 0x100) {
                        x = 50.0f;
                        y = 0.0f;
                    }
                } else {
                    x = 0.0f;
                    y = 0.0f;
                }
                if (AMSD_ABS(x) > 30.0f || AMSD_ABS(y) > 30.0f) {
                    if (D_80101F44_AdventureModeSetup == 0) {
                        D_80101F48_AdventureModeSetup = func_80029518(func_800B0CD8(x, y));
                        if (D_80101F48_AdventureModeSetup >= 0.0f && D_80101F48_AdventureModeSetup < 120.0f) {
                            if (D_80101F4C_AdventureModeSetup != 65.0f) {
                                D_80101F44_AdventureModeSetup = 1;
                            }
                            D_80101F48_AdventureModeSetup = 65.0f;
                            D_80101F4C_AdventureModeSetup = 65.0f;
                        } else if (D_80101F48_AdventureModeSetup >= 120.0f && D_80101F48_AdventureModeSetup < 240.0f) {
                            if (D_80101F4C_AdventureModeSetup != 180.0f) {
                                D_80101F44_AdventureModeSetup = 1;
                            }
                            D_80101F48_AdventureModeSetup = 180.0f;
                            D_80101F4C_AdventureModeSetup = 180.0f;
                        } else if (D_80101F48_AdventureModeSetup >= 240.0f && D_80101F48_AdventureModeSetup < 360.0f) {
                            if (D_80101F4C_AdventureModeSetup != 300.0f) {
                                D_80101F44_AdventureModeSetup = 1;
                            }
                            D_80101F48_AdventureModeSetup = 300.0f;
                            D_80101F4C_AdventureModeSetup = 300.0f;
                        } else {
                            while (1) {
                                HuPrcVSleep();
                            }
                        }
                        if (D_80101F44_AdventureModeSetup != 0) {
                            n = 0;
                            if (D_80101F48_AdventureModeSetup == 65.0f) {
                                n = 1;
                            }
                            if (D_80101F48_AdventureModeSetup == 180.0f) {
                                n = 2;
                            }
                            if (D_80101F48_AdventureModeSetup == 300.0f) {
                                n = 3;
                            }
                            if (n != 0) {
                                if (D_80101F70_AdventureModeSetup != 3) {
                                    D_801025C4_AdventureModeSetup = n + 0x295;
                                    D_801025D0_AdventureModeSetup = D_80101A70_AdventureModeSetup[D_8010259C_AdventureModeSetup.unk00][n - 1];
                                } else {
                                    D_801025C4_AdventureModeSetup = n + 0x27C;
                                    D_801025D0_AdventureModeSetup = D_80101AD0_AdventureModeSetup[n - 1];
                                }
                            }
                            PlaySound(0x4A);
                        }
                    }
                }
                if (D_80101F44_AdventureModeSetup == 0) {
                    break;
                }
                step = 10.0f;
                if (D_80101F48_AdventureModeSetup > c->unk2C) {
                    if (D_80101F48_AdventureModeSetup - c->unk2C > 180.0f) {
                        step = -step;
                    }
                } else {
                    if (c->unk2C - D_80101F48_AdventureModeSetup < 180.0f) {
                        step = -step;
                    }
                }
                diff = D_80101F48_AdventureModeSetup - c->unk2C;
                if (diff < 0.0f) {
                    diff = -diff;
                }
                if (AMSD_ABS(step) < diff) {
                    c->unk2C = func_80029518(step + c->unk2C);
                } else {
                    PlaySound(0x4B);
                    func_8006CE64((s16)D_80102580_AdventureModeSetup.unk00, 2, 3, 0xA);
                    c->unk2C = D_80101F48_AdventureModeSetup;
                    func_8009ECB0(D_800F2B7C[obj->model[1]].unk7C, 0.0f, 0.0f, 360.0f - D_80101F48_AdventureModeSetup);
                    HuPrcVSleep();
                    D_80101F44_AdventureModeSetup = 0;
                }
                c->unk18 = 0;
                if (AMSD_ABS(c->unk2C - 65.0f) < 1.0f) {
                    c->unk18 = 1;
                }
                if (AMSD_ABS(c->unk2C - 180.0f) < 1.0f) {
                    c->unk18 = 2;
                }
                if (AMSD_ABS(c->unk2C - 300.0f) < 1.0f) {
                    c->unk18 = 3;
                }
                if (AMSD_ABS(c->unk2C - D_80101F48_AdventureModeSetup) > 1.0f) {
                    c->unk18 = 0;
                }
                c->unk1C = c->unk18;
                break;
            case 4:
                if (D_801025CC_AdventureModeSetup != 0) {
                    D_801025CC_AdventureModeSetup = 0;
                    func_80071E80(D_801025B4_AdventureModeSetup, 1);
                }
                obj->work[1] = 5;
                /* fallthrough */
            case 5:
                obj->scale.x -= 0.05f;
                if (obj->scale.x < 0.2f) {
                    obj->scale.x = 0.2f;
                }
                t = obj->scale.x;
                obj->scale.z = t;
                obj->scale.y = t;
                if (c->unk3C == 0) {
                    c->unk34 -= c->unk38;
                } else {
                    c->unk3C--;
                }
                c->unk28 += c->unk34;
                obj->trans.x -= 10.0f;
                tgt = D_80101FA0_AdventureModeSetup;
                if (obj->trans.x <= tgt->trans.x) {
                    AMSD_MODE = -1;
                    func_800258EC(obj->model[0], 4, 4);
                    func_800258EC(obj->model[1], 4, 4);
                    func_800258EC(obj->model[2], 4, 4);
                    obj->trans.x = tgt->trans.x;
                    c->unk28 = tgt->trans.y;
                    obj->trans.z = tgt->trans.z - 50.0f;
                    obj->scale.z = 0.2f;
                obj->scale.y = 0.2f;
                obj->scale.x = 0.2f;
                    c->unk24 = 0.0f;
                    obj->work[1] = 0;
                }
                break;
            case 6:
                c->unk28 += 20.0f;
                if (c->unk28 > -4000.0f) {
                    func_800258EC(obj->model[0], 4, 4);
                    func_800258EC(obj->model[1], 4, 4);
                    func_800258EC(obj->model[2], 4, 4);
                    c->unk28 = -4000.0f;
                    obj->work[1] = 0;
                }
                break;
        }
        HuPrcVSleep();
    }
}
void func_80100198_AdventureModeSetup(omObjData* arg0) {
    Vec3f sp10;
    Vec3f* vec_ptr;
    unk_D80102450_AdventureModeSetup* temp00;

    temp00 = &D_80102450_AdventureModeSetup;
    vec_ptr = &sp10;
    func_800A0D00(vec_ptr, D_80102000_AdventureModeSetup.x, 0.0f, D_80102000_AdventureModeSetup.z);

    sp10.x -= arg0->trans.x;
    sp10.y -= 0.0f;
    sp10.z -= arg0->trans.z;
    arg0->rot.y = func_80029518(func_800B0CD8(sp10.x, sp10.z));
    func_800A0D00(vec_ptr, 0.0f, -D_80102000_AdventureModeSetup.y, D_80102000_AdventureModeSetup.z);

    sp10.x -= 0.0f;
    sp10.y += D_80102478_AdventureModeSetup;
    sp10.z -= arg0->trans.z;
    arg0->rot.x = func_80029518(func_800B0CD8(sp10.y, sp10.z));

    D_80102474_AdventureModeSetup += 5.0f;
    if (D_80102474_AdventureModeSetup >= 360.0f) {
        D_80102474_AdventureModeSetup -= 360.0f;
    }
    arg0->trans.y = (func_800AEAC0(temp00->unk24) * 5.0f) + temp00->unk28;

    func_800257E4(arg0->model[0], arg0->rot.x, arg0->rot.y, arg0->rot.z);
    func_800257E4(arg0->model[1], arg0->rot.x, arg0->rot.y, arg0->rot.z);
    func_800257E4(arg0->model[2], arg0->rot.x, arg0->rot.y, arg0->rot.z);
    func_8009ECB0(D_800F2B7C[arg0->model[1]].unk7C, 0.0f, 0.0f, 360.0f - temp00->unk2C);
    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_80025798(arg0->model[1], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_80025798(arg0->model[2], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_80025830(arg0->model[0], arg0->scale.x, arg0->scale.y, arg0->scale.z);
    func_80025830(arg0->model[1], arg0->scale.x, arg0->scale.y, arg0->scale.z);
    func_80025830(arg0->model[2], arg0->scale.x, arg0->scale.y, arg0->scale.z);
}


void func_8010042C_AdventureModeSetup(omObjData* arg0) {
    func_800F6F34_AdventureModeSetup(arg0);
    arg0->model[0] = func_800174C0(0x9000C, 0x6BD);
    arg0->model[1] = func_800174C0(0x9000D, 0x6BD);
    if (D_80101F70_AdventureModeSetup != 3) {
        arg0->model[2] = func_800174C0(0x9000E, 0x6BD);
    } else {
        arg0->model[2] = func_800174C0(0x9000F, 0x6BD);
    }
    func_80025930(arg0->model[0], 0x2000, 0);
    arg0->scale.z = 0.2f;
    arg0->scale.y = 0.2f;
    arg0->scale.x = 0.2f;
    func_80025830(arg0->model[1], 0.2f, arg0->scale.y, arg0->scale.z);
    arg0->work[1] = 0;
    arg0->func_ptr = func_80100198_AdventureModeSetup;
    omAddPrcObj(func_800FF328_AdventureModeSetup, 0x1002U, 0x800, 0);
    func_80017DB0(arg0);
}
void func_80100528_AdventureModeSetup(void) {
    D_80101FC4_AdventureModeSetup = omAddObj(0x46, 3U, 1U, -1, func_8010042C_AdventureModeSetup);
}

void func_80100564_AdventureModeSetup(omObjData* arg0) {
    Vec3f sp10;
    Vec2f sp20;
    unkAMSetupMove* p = &D_80102490_AdventureModeSetup[arg0->work[0]];

    switch (arg0->work[1]) {
        case 0:
        case 5:
            break;
        case 1:
            func_80018C90(arg0->work[2]);
            arg0->work[1] = 0;
            break;
        case 2:
            ShowBasicSprite(arg0->work[2]);
            arg0->work[1] = 5;
            break;
        case 3:
            p->frames = 5;
            p->step.x = (arg0->trans.x - p->target.x) / (f32)p->frames;
            p->step.y = (arg0->trans.y - p->target.y) / (f32)p->frames;
            p->step.z = (arg0->trans.z - p->target.z) / (f32)p->frames;
            PlaySound(0x52);
            arg0->work[1] = 4;
            /* fallthrough */
        case 4:
            if (--p->frames != -1) {
                arg0->trans.x -= p->step.x;
                arg0->trans.y -= p->step.y;
                arg0->trans.z -= p->step.z;
            } else {
                arg0->trans.x = p->target.x;
                arg0->trans.y = p->target.y;
                arg0->trans.z = p->target.z;
                arg0->work[1] = 5;
            }
            break;
    }
    sp10.x = arg0->trans.x + 10.0f;
    sp10.y = arg0->trans.y + 20.0f;
    sp10.z = arg0->trans.z;
    Convert3DTo2D(0, &sp10, &sp20);
    SetBasicSpritePos(arg0->work[2], (s16)(s32)sp20.x, (s16)(s32)sp20.y);
}
void func_80100744_AdventureModeSetup(omObjData* arg0) {
    Vec3f sp18;
    Vec2f sp28;
    s32 spr;
    u16 id;

    arg0->unk_50 = func_80023684(0x6C, 0x7918);
    func_8009B770(arg0->unk_50, 0, 0x6C);
    spr = func_80019060((s16)InitSprite(0x90024), 0, 1);
    id = spr;
    func_80018E50(id, D_80101ADE_AdventureModeSetup, 0);
    func_80018C90(id);
    arg0->trans.z = sp18.z = 0.0f;
    arg0->trans.y = sp18.y = 0.0f;
    arg0->trans.x = sp18.x = 0.0f;
    *arg0->model = -1;
    func_80009340(arg0, 1, 0x34, 0x168D, 8);
    Convert3DTo2D(0, &sp18, &sp28);
    SetBasicSpritePos(id, (s16)(s32)sp28.x, (s16)(s32)sp28.y);
    func_80018C90(id);
    arg0->work[0] = D_80101ADC_AdventureModeSetup++;
    if ((s16)spr >= 0x100) {
        while (1) {}
    }
    arg0->work[1] = 0;
    arg0->work[2] = spr;
    arg0->func_ptr = func_80100564_AdventureModeSetup;
}
void func_801008B4_AdventureModeSetup() {
    D_80101FC8_AdventureModeSetup[0] = omAddObj(0x64, 2U, 0U, -1, func_80100744_AdventureModeSetup);
    D_80101FC8_AdventureModeSetup[1] = omAddObj(0x64, 2U, 0U, -1, func_80100744_AdventureModeSetup);
    D_80101FC8_AdventureModeSetup[2] = omAddObj(0x64, 2U, 0U, -1, func_80100744_AdventureModeSetup);
    D_80101FC8_AdventureModeSetup[3] = omAddObj(0x64, 2U, 0U, -1, func_80100744_AdventureModeSetup);
}

void func_80100958_AdventureModeSetup(omObjData* arg0) {
    Vec3f sp10;
    Vec2f sp20;
    s32 i;
    s32 idx = arg0->work[0];
    omObjData* obj = D_80101F88_AdventureModeSetup[arg0->work[3]];
    AMSPiece* chr = &AMSD_CHAR[arg0->work[3]];
    unkAMSetupSprites3* p = &D_80102500_AdventureModeSetup[idx];

    switch (arg0->work[1]) {
        case 0:
            break;
        case 1:
            D_80101F50_AdventureModeSetup[idx] = 1.0f;
            arg0->work[1] = 2;
            /* fallthrough */
        case 2:
            D_80101F50_AdventureModeSetup[idx] -= 0.1f;
            if (D_80101F50_AdventureModeSetup[idx] < 0.0f) {
                D_80101F50_AdventureModeSetup[idx] = 0.0f;
                func_80018C90(arg0->work[2]);
                arg0->work[1] = 0;
            }
            goto setalpha;
        case 3:
            for (i = 0; i < 3; i++) {
                func_80018C90(p->sprite[i]);
            }
            arg0->work[2] = p->sprite[p->unk00];
            ShowBasicSprite(arg0->work[2]);
            D_80101F50_AdventureModeSetup[idx] = 0;
            arg0->work[1] = 4;
            /* fallthrough */
        case 4:
            D_80101F50_AdventureModeSetup[idx] += 0.1f;
            if (D_80101F50_AdventureModeSetup[idx] > 1.0f) {
                D_80101F50_AdventureModeSetup[idx] = 1.0f;
                arg0->work[1] = 0;
            }
        setalpha:
            func_80067354(arg0->work[2], 0, D_80101F50_AdventureModeSetup[idx], D_80101F50_AdventureModeSetup[idx]);
            break;
    }
    sp10.x = obj->trans.x - 50.0f;
    sp10.y = obj->trans.y + 60.0f;
    sp10.z = obj->trans.z;
    sp10.y += func_800AEAC0(chr->unk44) * 8.0f;
    Convert3DTo2D(0, &sp10, &sp20);
    SetBasicSpritePos(arg0->work[2], (s16)(s32)sp20.x, (s16)(s32)sp20.y);
}
void func_80100BF8_AdventureModeSetup(omObjData *arg0) {
    s16 i;

    for (i = 0; i < 3; i++) {
        D_801025F4_AdventureModeSetup[i] = InitSprite((i + 0x86) | 0x90000);
    }
    arg0->func_ptr = NULL;
}


// decomp-permuter
void func_80100C88_AdventureModeSetup(omObjData *arg0)
{
  s32 idx;
  omObjData *new_var;
  unkAMSetupSprites3 *p = &D_80102500_AdventureModeSetup[D_80101AE0_AdventureModeSetup];
  s32 i;
  for (i = 0; i < 3; i++)
  {
    p->sprite[i] = func_80019060((s16) D_801025F4_AdventureModeSetup[i], 0, 1);
    arg0->work[2] = p->sprite[i];
    idx = p->sprite[i];
    func_80018C90(idx);
    func_80067354(arg0->work[2], 0, 0.0f, 0.0f);
  }

  idx = D_80101AE0_AdventureModeSetup;
  D_80101AE0_AdventureModeSetup = idx + 1;
  arg0->work[0] = idx;
  arg0->work[1] = 0;
  (new_var = arg0)->work[3] = 0;
  new_var->func_ptr = func_80100958_AdventureModeSetup;
}
void func_80100D84_AdventureModeSetup() {
    omAddObj(0xBE, 0U, 0U, -1, func_80100BF8_AdventureModeSetup);
    D_80101FD8_AdventureModeSetup[0] = omAddObj(0xC8, 0U, 0U, -1, func_80100C88_AdventureModeSetup);
    D_80101FD8_AdventureModeSetup[1] = omAddObj(0xC8, 0U, 0U, -1, func_80100C88_AdventureModeSetup);
    D_80101FD8_AdventureModeSetup[2] = omAddObj(0xC8, 0U, 0U, -1, func_80100C88_AdventureModeSetup);
    D_80101FD8_AdventureModeSetup[3] = omAddObj(0xC8, 0U, 0U, -1, func_80100C88_AdventureModeSetup);
}


void func_80100E48_AdventureModeSetup(omObjData* arg0) {
    Vec3f sp10;
    Vec2f sp20;
    s32 i;
    s32 idx = arg0->work[0];
    omObjData* obj = D_80101F88_AdventureModeSetup[arg0->work[3]];
    AMSPiece* chr = &AMSD_CHAR[arg0->work[3]];
    unkAMSetupSprites5* p = &AMSD_SPR5[idx];

    switch (arg0->work[1]) {
        case 0:
            break;
        case 1:
            AMSD_ALPHA5[idx] = 1.0f;
            arg0->work[1] = 2;
            /* fallthrough */
        case 2:
            AMSD_ALPHA5[idx] -= 0.1f;
            if (AMSD_ALPHA5[idx] < 0.0f) {
                AMSD_ALPHA5[idx] = 0.0f;
                func_80018C90(arg0->work[2]);
                arg0->work[1] = 0;
            }
            goto setalpha;
        case 3:
            for (i = 0; i < 5; i++) {
                func_80018C90(p->sprite[i]);
            }
            arg0->work[2] = p->sprite[p->unk00];
            ShowBasicSprite(arg0->work[2]);
            AMSD_ALPHA5[idx] = 0;
            arg0->work[1] = 4;
            /* fallthrough */
        case 4:
            AMSD_ALPHA5[idx] += 0.1f;
            if (AMSD_ALPHA5[idx] > 1.0f) {
                AMSD_ALPHA5[idx] = 1.0f;
                arg0->work[1] = 0;
            }
        setalpha:
            func_80067354(arg0->work[2], 0, AMSD_ALPHA5[idx], AMSD_ALPHA5[idx]);
            break;
    }
    sp10.x = obj->trans.x + 20.0f;
    sp10.y = obj->trans.y + 15.0f;
    sp10.z = obj->trans.z;
    sp10.y += func_800AEAC0(chr->unk44) * 8.0f;
    Convert3DTo2D(0, &sp10, &sp20);
    SetBasicSpritePos(arg0->work[2], (s16)(s32)sp20.x, (s16)(s32)sp20.y);
}
void func_801010E0_AdventureModeSetup(omObjData* arg0) {
    s16 i;

    for (i = 0; i < 5; i++) {
        D_801025FA_AdventureModeSetup[i] = InitSprite((i + 0x8B) | 0x90000);
    }
    arg0->func_ptr = 0;
}

// decomp-permuter
void func_80101170_AdventureModeSetup(omObjData *arg0)
{
  s32 idx;
  s32 i;
  unkAMSetupSprites5 *p = &D_80102530_AdventureModeSetup[D_80101AE4_AdventureModeSetup];
  s32 new_var;
  for (i = 0; i < 5; i++)
  {
    new_var = func_80019060((s16) D_801025FA_AdventureModeSetup[i], 0, 1);
    p->sprite[i] = new_var;
    arg0->work[2] = p->sprite[i];
    func_80018C90(p->sprite[i]);
    func_80067354(arg0->work[2], 0, 0.0f, 0.0f);
    idx = arg0->work[2];
    func_80067384(idx, 0, 0x3E80);
  }

  idx = D_80101AE4_AdventureModeSetup;
  D_80101AE4_AdventureModeSetup = idx + 1;
  arg0->work[0] = idx;
  arg0->work[1] = 0;
  arg0->work[3] = 0;
  arg0->func_ptr = func_80100E48_AdventureModeSetup;
}
void func_80101274_AdventureModeSetup() {
    omAddObj(0xBE, 0U, 0U, -1, &func_801010E0_AdventureModeSetup);
    D_80101FE8_AdventureModeSetup[0] = omAddObj(0xC8, 0U, 0U, -1, &func_80101170_AdventureModeSetup);
    D_80101FE8_AdventureModeSetup[1] = omAddObj(0xC8, 0U, 0U, -1, &func_80101170_AdventureModeSetup);
    D_80101FE8_AdventureModeSetup[2] = omAddObj(0xC8, 0U, 0U, -1, &func_80101170_AdventureModeSetup);
    D_80101FE8_AdventureModeSetup[3] = omAddObj(0xC8, 0U, 0U, -1, &func_80101170_AdventureModeSetup);
}

void func_80101338_AdventureModeSetup() {
    func_8001D420(0, &D_80102000_AdventureModeSetup, &D_8010200C_AdventureModeSetup, &D_80102018_AdventureModeSetup);
    func_8001D57C(0);
}

void func_80101374_AdventureModeSetup() {
    s32 i;

    D_80102000_AdventureModeSetup.x = 0.0f;
    D_80102000_AdventureModeSetup.y = -2900.0f;
    D_80102000_AdventureModeSetup.z = 400.0f;
    D_8010200C_AdventureModeSetup.x = 0.0f;
    D_8010200C_AdventureModeSetup.y = -2600.0f;
    D_8010200C_AdventureModeSetup.z = 0.0f;
    D_80102018_AdventureModeSetup.x = 0.0f;
    D_80102018_AdventureModeSetup.y = 1.0f;
    D_80102018_AdventureModeSetup.z = 0.0f;

    D_801025B4_AdventureModeSetup = -1;
    D_80101F74_AdventureModeSetup = 0;
    D_80101F78_AdventureModeSetup = 0;
    D_801025BC_AdventureModeSetup = 0;
    D_801025C0_AdventureModeSetup = 0;
    D_801025C8_AdventureModeSetup = 0;
    D_801025B8_AdventureModeSetup = -1;
    D_801025C4_AdventureModeSetup = -1;

    D_80102580_AdventureModeSetup.unk00 = -1;
    D_80102580_AdventureModeSetup.unk04 = -1;

    for (i = 0; i < 4; i++) {
        *(&D_80102588_AdventureModeSetup + i) = -1;
        *(&D_801025A4_AdventureModeSetup + i) = 0;
    }

    D_8010259C_AdventureModeSetup.unk00 = -1;
    D_8010259C_AdventureModeSetup.unk04 = -1;
}

void func_80101494_AdventureModeSetup() {
    while (TRUE) {
        rand8();
        HuPrcVSleep();
    }
}

void func_801014C0_AdventureModeSetup(omObjData* arg0) {
    arg0->func_ptr = func_801014F8_AdventureModeSetup;
    arg0->work[1] = 0;
    SetFadeInTypeAndTime(0, 0x10);
    func_80060128(3);
}

void func_801014F8_AdventureModeSetup(omObjData* arg0) {
    func_8010179C_AdventureModeSetup();
    switch (arg0->work[1]) {
        case 0:
            omAddPrcObj(func_80101494_AdventureModeSetup, 0x1002U, 0x800, 0);
            arg0->work[1] = 1;
            D_80101FA0_AdventureModeSetup->work[1] = 1;
            break;
        case 1:
            if (D_80101FA0_AdventureModeSetup->work[1] == 0) {
                arg0->work[1] = 2;
                D_80101FA0_AdventureModeSetup->work[1] = 8;
            }
            break;
        case 2:
            if (D_80101FA0_AdventureModeSetup->work[1] == 0) {
                arg0->work[1] = 3;
                D_80101FA0_AdventureModeSetup->work[1] = 0xB;
            }
            break;
    }
}

void func_801015D0_AdventureModeSetup(void) {
    s32 pad[2]; // retail's frame has an unexplained 8-byte local area
    s32 i;
    s32 count;

    if (D_80101F78_AdventureModeSetup == 0 && D_80101F70_AdventureModeSetup != 2) {
        func_800FF0A0_AdventureModeSetup();
    }
    func_80072080(D_801025B4_AdventureModeSetup);
    func_80070ED4();
    func_80072724(0xFF, 0xFF, 0xFF);
    func_800726AC(0, 0x14);
    if (D_80101F78_AdventureModeSetup == 0) {
        i = D_80102580_AdventureModeSetup.unk00;
        count = 0;
        if (D_80102580_AdventureModeSetup.unk04 > 0) {
            do {
                if (AMSD_ACTIVE[i] != 0) {
                    count++;
                    func_8006CE64(i, 2, 0xA, 0x78);
                }
                i++;
            } while (count < D_80102584_AdventureModeSetup);
        }
    }
    func_800601D4(0x28);
    while (func_80072718() != 0) {
        HuPrcVSleep();
    }
    if (D_80101F70_AdventureModeSetup == 1) {
        func_800427E4();
        MBModelKill(D_801025E8_AdventureModeSetup);
        MBModelClose();
    }
    if (D_80101F70_AdventureModeSetup == 2) {
        func_80050A7C(D_801025D4_AdventureModeSetup);
        func_800532F4();
    }
    omOvlKill();
    if (D_80101F78_AdventureModeSetup != 0) {
        if (_CheckFlag(0x2C) != 0) {
            ClearBoardFeatureFlag(0x2C);
        }
        omOvlReturnEx(1);
    } else {
        omOvlGotoEx(0x35, 0, 0x92);
    }
    while (1) {
        HuPrcVSleep();
    }
}
void func_8010179C_AdventureModeSetup() {
    if (D_800F5144 != 0) {
        if (D_801025B4_AdventureModeSetup != -1) {
            func_80072080(D_801025B4_AdventureModeSetup);
        }
        if (D_80101F70_AdventureModeSetup == 1) {
            MBModelClose();
        }
        if (D_80101F70_AdventureModeSetup == 2) {
            func_80050A7C(D_801025D4_AdventureModeSetup);
            func_800532F4();
        }

        func_80070ED4();
        func_800601D4(0x28);
        omOvlReturnEx(1);
    }
}
