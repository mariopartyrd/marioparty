#include "GrabBag.h"

extern f32 D_800B8988;
extern u8 D_800F64F8;

/* .data */
u8 D_800FB090_GrabBag = 0;  /* result jingle played */
u32 D_800FB094_GrabBag = 0; /* frame counters of the D_800ED430 stages */
u32 D_800FB098_GrabBag = 0;
u32 D_800FB09C_GrabBag = 0;
s32 D_800FB0A0_GrabBag = 0;
s32 D_800FB0A4_GrabBag = 0;
u8 D_800FB0A8_GrabBag[6] = { 0x21, 0x37, 0x23, 0x21, 0x37, 0x23 }; /* bag image per bag */
s32 D_800FB0B0_GrabBag = 0; /* bags set up */

extern GrabBagBagWork* D_800FB220_GrabBag;
extern s32 D_800FB290_GrabBag;

void func_8001E2A8(s16, u16);

void func_800F65E0_GrabBag(void) {
    func_80029090(0x10);
    func_8002ADF0(&D_800EDEC0, 0x40);
    func_8001DE70(0x10);
    omInitObjMan(0x14, 0);
    func_80060088();
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    func_8000942C();
    Center.x = -10.0f;
    Center.y = 0.0f;
    Center.z = -105.0f;
    CRot.x = -36.0f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;
    CZoom = 1880.0f;
    func_800F66F8_GrabBag();
    func_800F7260_GrabBag();
    func_800F67BC_GrabBag();
    func_800F6C08_GrabBag();
    func_800F7680_GrabBag();
    func_8002890C(0, 0, 0);
    SetFadeInTypeAndTime(0, 0x10);
}


void func_800F66F8_GrabBag(void) {
    s16 temp_v0;

    func_800178A0(1);
    temp_v0 = func_800178E8();
    func_80017660(temp_v0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(temp_v0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(temp_v0, 30.0f, 80.0f, 8000.0f);
}


void func_800F67BC_GrabBag(void) {
}


void func_800F67C4_GrabBag(omObjData* arg0, u32 arg1) {
    u32 time;

    time = 1800;
    switch (D_800ED430) {
    case 0:
        if (arg1 == 240) {
            GMesCreate(0);
            if (GMesStatAllGet() == 0 || GMesStatAllGet() & 2) {
            }
        } else if (arg1 >= 360) {
            func_80009458();
        }
        break;
    case 1:
        if (arg1 == 0) {
            GMesCreate(8, 60, 160, 32);
            if (GMesStatAllGet() == 0 || GMesStatAllGet() & 2) {
            }
        }
        if (func_8005FD5C() + D_800F64F8 == 0) {
            time = 1800 - arg1;
        }
        if (time == 0) {
            func_800790C0();
            func_800601D4(40);
            func_80009438();
        } else {
            func_80079078(time / 30);
        }
        break;
    case 2:
        if (arg1 == 0) {
            func_80009730();
            func_800790C0();
            GMesCreate(2);
        } else if ((GMesStatAllGet() == 0 || GMesStatAllGet() & 2) && D_800FB090_GrabBag == 0 &&
                   _CheckFlag(0x2B) == 0) {
            switch (D_800FB290_GrabBag) {
            case 0:
                func_80060128(0x32);
                break;
            case 1:
                func_80060128(0x3C);
                break;
            case 2:
                func_80060128(0x35);
                break;
            }
            D_800FB090_GrabBag = 1;
        }
        break;
    }
}
void func_800F69D4_GrabBag(omObjData* arg0) {
    func_80009468();
    switch (D_800ED430) {
    case 0:
        if (D_800FB094_GrabBag > 360) {
            func_80009458();
        }
        func_800F67C4_GrabBag(arg0, D_800FB094_GrabBag);
        D_800FB094_GrabBag += 2;
        break;
    case 1:
        func_800F67C4_GrabBag(arg0, D_800FB09C_GrabBag);
        if (func_8005FD5C() + D_800F64F8 == 0) {
            D_800FB09C_GrabBag++;
        }
        break;
    case 2:
        if (GMesStatAllGet() == 0 || GMesStatAllGet() & 2) {
            D_800FB0A4_GrabBag++;
        }
        if (D_800FB0A4_GrabBag == 30 && _CheckFlag(0x2B) != 0) {
            func_800726AC(0, 20);
            func_80009448();
        }
        if ((D_800FB0A4_GrabBag == 105 && D_800FB290_GrabBag == 0) ||
            (D_800FB0A4_GrabBag == 120 && D_800FB290_GrabBag == 1) ||
            (D_800FB0A4_GrabBag == 90 && D_800FB290_GrabBag == 2)) {
            func_800726AC(0, 20);
            func_80009448();
        }
        func_800F67C4_GrabBag(arg0, D_800FB098_GrabBag);
        D_800FB098_GrabBag += 2;
        break;
    case 3:
        if (func_80072718() == 0) {
            omOvlReturnEx(1);
        }
        D_800FB0A0_GrabBag += 2;
        break;
    }
}
void func_800F6C08_GrabBag(void) {
    s32 i;

    D_800EE984 = 0;
    for (i = 0; i < ARRAY_COUNT(D_800EDE70); i++) {
        D_800EDE70[D_800EE984++] = omAddObj(3, 2, 0, -1, func_800F6C98_GrabBag);
    }
}


void func_800F6C98_GrabBag(omObjData* arg0) {
    GrabBagBagWork* work;

    arg0->trans.x = arg0->trans.y = arg0->trans.z = 0.0f;
    arg0->scale.x = arg0->scale.y = arg0->scale.z = 2.0f;
    arg0->func_ptr = func_800F6E90_GrabBag;
    arg0->unk_50 = func_80023684(sizeof(GrabBagBagWork), 0x7918);
    func_8009B770(arg0->unk_50, 0, sizeof(GrabBagBagWork));
    work = arg0->unk_50;
    func_800091BC(arg0, D_800FB0A8_GrabBag[D_800FB0B0_GrabBag++], 0x28D, 8);
    func_80009340(arg0, 1, 0x2A, 0x28D, 8);
    work->unk_60 = 0;
    work->unk_5C = 0;
    work->unk_3C = 0.0f;
    work->unk_54 = 0;
    work->unk_44 = 0.1f;
    work->unk_48 = 30.0f;
    work->unk_34 = 500.0f;
    work->unk_40 = D_800B8988;
    work->unk_38 = 0.0f;
    work->unk_52 = D_800FB0B0_GrabBag % 3;
    work->unk_4C = 0.5f;
    work->unk_50 = 0;
    work->unk_58 = 0.5f;
    work->unk_6C = work->unk_6D = 0;
    work->unk_6E = -1;
    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_80025798(arg0->model[1], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_80025830(arg0->model[0], arg0->scale.x, arg0->scale.y, arg0->scale.z);
    func_80025830(arg0->model[1], 4.0f, 4.0f, 4.0f);
    func_8001E360(work->unk_22, 0xFF, 0xFF, 0xBE);
}
void func_800F6E90_GrabBag(omObjData* arg0) {
    GrabBagBagWork* work;
    unk_ovl_2D_struct* model;
    omObjData* player;
    f32 dx;
    f32 dz;
    f32 tilt;

    D_800FB220_GrabBag = work = arg0->unk_50;
    model = &D_800F2B7C[arg0->model[0]];
    if (model->unk_20 & 4) {
        work->unk_5C = 0;
        work->unk_3C = 0.0f;
        work->unk_44 = 0.1f;
        work->unk_48 = 30.0f;
        work->unk_34 = 500.0f;
        work->unk_40 = D_800B8988;
        work->unk_38 = 0.0f;
        work->unk_4C = 0.5f;
        work->unk_50 = 0;
        work->unk_58 = 0.5f;
        work->unk_6C = work->unk_6D = -1;
        D_800FB220_GrabBag->unk_6E = -1;
        return;
    }
    if (D_800F3FB0[D_800FB220_GrabBag->unk_6D] == NULL) {
        return;
    }
    D_800FB220_GrabBag->unk_5C++;
    func_8001E2A8(D_800FB220_GrabBag->unk_22, D_800FB220_GrabBag->unk_5C % 8);
    player = D_800F3FB0[D_800FB220_GrabBag->unk_6D];
    dx = arg0->trans.x - player->trans.x;
    dz = arg0->trans.z - player->trans.z;
    if (D_800B8988 < dx) {
        arg0->trans.x -= D_800B8988;
    } else if (dx < -D_800B8988) {
        arg0->trans.x += D_800B8988;
    }
    if (D_800B8988 < dz) {
        arg0->trans.z -= D_800B8988;
    } else if (dz < -D_800B8988) {
        arg0->trans.z += D_800B8988;
    }
    tilt = D_800FB220_GrabBag->unk_38;
    if (tilt > 0.9f) {
        tilt = 0.9f;
    } else if (tilt < -0.9f) {
        tilt = -0.9f;
    }
    if (D_800FB220_GrabBag->unk_5C < 15) {
        arg0->trans.y += tilt * tilt * 35.0f;
        D_800FB220_GrabBag->unk_38 += 0.3f;
    } else {
        arg0->trans.y -= tilt * tilt * 35.0f;
        D_800FB220_GrabBag->unk_38 -= 0.1f;
        if (arg0->trans.y < 20.0f) {
            arg0->trans.y = 20.0f;
        }
    }
    if (D_800FB220_GrabBag->unk_5C >= 21) {
        if (D_800FB220_GrabBag->unk_6E == 0) {
            PlaySound(0xFC);
        } else if (D_800FB220_GrabBag->unk_6E == 1) {
            PlaySound(0x109);
        }
        func_800258EC(arg0->model[0], 4, 4);
        D_800FB220_GrabBag->unk_5C = 0;
        D_800FB220_GrabBag->unk_6C = D_800FB220_GrabBag->unk_6D = -1;
        D_800FB220_GrabBag->unk_6E = -1;
    }
    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_80025798(arg0->model[1], arg0->trans.x, arg0->trans.y + 24.0f, arg0->trans.z);
}
