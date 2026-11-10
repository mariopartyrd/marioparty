#include "common.h"
#include "HotBobOmb.h"

/* .data 0x800F9D40..0x800FA3C0 */
s32 D_800F9D40_HotBobOmb = 0;
HbSeat D_800F9D44_HotBobOmb[4] = {
    { 0.0f, { -230.0f, 0.0f, -230.0f }, 45.0f, 1.0f, { -180.0f, 30.0f, -180.0f } },
    { 1.0f, { 230.0f, 0.0f, -230.0f }, 315.0f, 1.0f, { 180.0f, 30.0f, -180.0f } },
    { 2.0f, { 230.0f, 0.0f, 230.0f }, 225.0f, 1.0f, { 180.0f, 30.0f, 180.0f } },
    { 3.0f, { -230.0f, 0.0f, 230.0f }, 135.0f, 1.0f, { -180.0f, 30.0f, 180.0f } },
};
HbSeat D_800F9DD4_HotBobOmb[4] = {
    { 0.0f, { -228.5f, 0.0f, -243.5f }, 45.0f, 1.0f, { -180.0f, 30.0f, -180.0f } },
    { 1.0f, { 208.5f, 0.0f, -223.5f }, 315.0f, 1.0f, { 180.0f, 30.0f, -180.0f } },
    { 2.0f, { 225.5f, 0.0f, 177.0f }, 225.0f, 1.0f, { 180.0f, 30.0f, 180.0f } },
    { 3.0f, { -212.0f, 0.0f, 177.0f }, 135.0f, 1.0f, { -180.0f, 30.0f, 180.0f } },
};
HbSeat D_800F9E64_HotBobOmb[4] = {
    { 0.0f, { -233.0f, 0.0f, -253.0f }, 45.0f, 1.0f, { -180.0f, 10.0f, -180.0f } },
    { 1.0f, { 231.49998f, 0.0f, -241.49998f }, 315.0f, 1.0f, { 180.0f, 10.0f, -180.0f } },
    { 2.0f, { 241.49998f, 0.0f, 207.0f }, 225.0f, 1.0f, { 180.0f, 10.0f, 180.0f } },
    { 3.0f, { -240.0f, 0.0f, 210.0f }, 135.0f, 1.0f, { -180.0f, 10.0f, 180.0f } },
};
HbSeat D_800F9EF4_HotBobOmb[4] = {
    { 0.0f, { -231.49998f, 0.0f, -241.49998f }, 45.0f, 1.0f, { -180.0f, 20.0f, -180.0f } },
    { 1.0f, { 231.49998f, 0.0f, -251.49998f }, 315.0f, 1.0f, { 180.0f, 20.0f, -180.0f } },
    { 2.0f, { 253.0f, 0.0f, 213.5f }, 225.0f, 1.0f, { 180.0f, 20.0f, 180.0f } },
    { 3.0f, { -261.5f, 0.0f, 201.49998f }, 135.0f, 1.0f, { -180.0f, 20.0f, 180.0f } },
};
HbSeat D_800F9F84_HotBobOmb[4] = {
    { 0.0f, { -223.0f, 0.0f, -230.0f }, 45.0f, 1.0f, { -180.0f, 60.0f, -180.0f } },
    { 1.0f, { 210.0f, 0.0f, -250.0f }, 315.0f, 1.0f, { 180.0f, 60.0f, -180.0f } },
    { 2.0f, { 207.0f, 0.0f, 180.0f }, 225.0f, 1.0f, { 180.0f, 60.0f, 180.0f } },
    { 3.0f, { -203.90001f, 0.0f, 198.90001f }, 135.0f, 1.0f, { -180.0f, 60.0f, 180.0f } },
};
HbSeat D_800FA014_HotBobOmb[4] = {
    { 0.0f, { -234.49998f, 0.0f, -241.49998f }, 45.0f, 1.0f, { -180.0f, 50.0f, -180.0f } },
    { 1.0f, { 225.0f, 0.0f, -241.49998f }, 315.0f, 1.0f, { 180.0f, 50.0f, -180.0f } },
    { 2.0f, { 218.5f, 0.0f, 182.0f }, 225.0f, 1.0f, { 180.0f, 50.0f, 180.0f } },
    { 3.0f, { -227.3f, 0.0f, 192.3f }, 135.0f, 1.0f, { -180.0f, 50.0f, 180.0f } },
};
HbSeat D_800FA0A4_HotBobOmb[4] = {
    { 0.0f, { -226.49998f, 0.0f, -241.49998f }, 45.0f, 1.0f, { -180.0f, 40.0f, -180.0f } },
    { 1.0f, { 200.0f, 0.0f, -261.5f }, 315.0f, 1.0f, { 180.0f, 50.0f, -180.0f } },
    { 2.0f, { 202.0f, 0.0f, 192.0f }, 225.0f, 1.0f, { 180.0f, 40.0f, 180.0f } },
    { 3.0f, { -218.5f, 0.0f, 193.5f }, 135.0f, 1.0f, { -180.0f, 40.0f, 180.0f } },
};

s32 D_800FA134_HotBobOmb[16] = {
    0x211, 0x211, 0x211, 0x212, 0x212, 0x212, 0x213, 0x213,
    0x213, 0x214, 0x214, 0x214, 0x215, 0x215, 0x215, 0x215,
};
s32 D_800FA174_HotBobOmb = -1;
s32 D_800FA178_HotBobOmb = -1;
s32 D_800FA17C_HotBobOmb = 0x28;
s32 D_800FA180_HotBobOmb[4] = { 0x28, 0x58, 0x60, 0x20 };
s32 D_800FA190_HotBobOmb = 0;
s32 D_800FA194_HotBobOmb = 0;
s32 D_800FA198_HotBobOmb = 0;
s32 D_800FA19C_HotBobOmb = 0;
s32 D_800FA1A0_HotBobOmb = 0;
s32 D_800FA1A4_HotBobOmb = -1;
s32 D_800FA1A8_HotBobOmb = 0;
s32 D_800FA1AC_HotBobOmb = 0;
s32 D_800FA1B0_HotBobOmb = 0;
s32 D_800FA1B4_HotBobOmb = -1;
s32 D_800FA1B8_HotBobOmb = 0;
s32 D_800FA1BC_HotBobOmb = -1;
f32 D_800FA1C0_HotBobOmb = 0.0f;
f32 D_800FA1C4_HotBobOmb = 0.0f;
HbCamKey D_800FA1C8_HotBobOmb[13] = {
    { 500.0f, { -180.0f, 3500.0f, -180.0f }, { 300.0f, 13.0f, 0.0f }, 10.0f, 0 },
    { 500.0f, { -180.0f, 3150.0f, -180.0f }, { 305.0f, 13.0f, 0.0f }, 10.0f, 3 },
    { 500.0f, { -180.0f, 2800.0f, -180.0f }, { 310.0f, 13.0f, 0.0f }, 10.0f, 0 },
    { 500.0f, { -180.0f, 2450.0f, -180.0f }, { 315.0f, 13.0f, 0.0f }, 10.0f, 0 },
    { 500.0f, { -180.0f, 2100.0f, -180.0f }, { 320.0f, 13.0f, 0.0f }, 10.0f, 4 },
    { 500.0f, { -180.0f, 1750.0f, -180.0f }, { 320.0f, 13.0f, 0.0f }, 10.0f, 0 },
    { 620.0f, { -172.0f, 1400.0f, -182.0f }, { 320.0f, 13.0f, 0.0f }, 10.0f, 0 },
    { 740.0f, { -164.0f, 1050.0f, -184.0f }, { 320.0f, 13.0f, 0.0f }, 10.0f, 1 },
    { 980.0f, { -148.0f, 700.0f, -188.0f }, { 320.0f, 13.0f, 0.0f }, 10.0f, 0 },
    { 1340.0f, { -124.0f, 350.0f, -194.0f }, { 320.0f, 13.0f, 0.0f }, 10.0f, 0 },
    { 1700.0f, { -100.0f, 0.0f, -200.0f }, { 320.0f, 13.0f, 0.0f }, 10.0f, 0 },
    { 1700.0f, { -100.0f, 0.0f, -200.0f }, { 320.0f, 13.0f, 0.0f }, 30.0f, 2 },
    { -1.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f, 0 },
};
f32 D_800FA39C_HotBobOmb = 0.0f;
HbCamKey* D_800FA3A0_HotBobOmb = D_800FA1C8_HotBobOmb;
s32 D_800FA3A4_HotBobOmb = 0;
s32 D_800FA3A8_HotBobOmb = 0;
f32 D_800FA3AC_HotBobOmb = 0.0f;
HbCamKey* D_800FA3B0_HotBobOmb = D_800FA1C8_HotBobOmb;
s32 D_800FA3B4_HotBobOmb = 0;

void func_800F6840_HotBobOmb(omObjData* obj) {
}

void func_800F6848_HotBobOmb(void) {
    omAddObj(1, 1, 0, -1, func_800F6A10_HotBobOmb);
    omAddObj(1, 1, 0, -1, func_800F6AF0_HotBobOmb);
    omAddObj(1, 1, 0, -1, func_800F6B64_HotBobOmb);
    omAddObj(1, 1, 0, -1, func_800F6BBC_HotBobOmb);
    omAddObj(1, 1, 0, -1, func_800F6C20_HotBobOmb);
    omAddObj(1, 1, 0, -1, func_800F6C78_HotBobOmb);
    omAddObj(1, 1, 0, -1, func_800F6CEC_HotBobOmb);
}

void func_800F693C_HotBobOmb(void) {
    D_800FA8D8_HotBobOmb[0] = omAddObj(2, 5, 7, -1, func_800F6D60_HotBobOmb);
    D_800FA8D8_HotBobOmb[1] = omAddObj(2, 5, 7, -1, func_800F6D7C_HotBobOmb);
    D_800FA8D8_HotBobOmb[2] = omAddObj(2, 5, 7, -1, func_800F6D98_HotBobOmb);
    D_800FA8D8_HotBobOmb[3] = omAddObj(2, 5, 7, -1, func_800F6DB4_HotBobOmb);
    omAddObj(2, 6, 10, -1, func_800F7934_HotBobOmb);
}

void func_800F6A10_HotBobOmb(omObjData* obj) {
    func_80017660(0, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    obj->trans.x = 0.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = -100.0f;
    obj->scale.x = 1.0f;
    obj->scale.y = 1.0f;
    obj->scale.z = 1.0f;
    obj->model[0] = func_800174C0(0x190000, 0x99);
    obj->func_ptr = func_800F6840_HotBobOmb;
}

void func_800F6AF0_HotBobOmb(omObjData* obj) {
    obj->model[0] = LoadFormFile(0x190001, 0x99);
    obj->trans.x = 0.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = -100.0f;
    obj->scale.x = 1.0f;
    obj->scale.y = 1.0f;
    obj->scale.z = 1.0f;
    obj->func_ptr = func_800F6840_HotBobOmb;
}

void func_800F6B64_HotBobOmb(omObjData* obj) {
    obj->model[0] = LoadFormFile(0x190002, 0x99);
    obj->trans.x = -50.0f;
    obj->trans.z = -50.0f;
    obj->func_ptr = func_800F6840_HotBobOmb;
}

void func_800F6BBC_HotBobOmb(omObjData* obj) {
    obj->model[0] = LoadFormFile(0x190002, 0x99);
    obj->trans.x = 50.0f;
    obj->trans.z = -200.0f;
    obj->func_ptr = func_800F6840_HotBobOmb;
}

void func_800F6C20_HotBobOmb(omObjData* obj) {
    obj->model[0] = LoadFormFile(0x190002, 0x99);
    obj->trans.x = -900.0f;
    obj->trans.z = 0.0f;
    obj->func_ptr = func_800F6840_HotBobOmb;
}

void func_800F6C78_HotBobOmb(omObjData* obj) {
    obj->model[0] = LoadFormFile(0x190003, 0x99);
    obj->trans.x = 0.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = -100.0f;
    obj->scale.x = 1.0f;
    obj->scale.y = 1.0f;
    obj->scale.z = 1.0f;
    obj->func_ptr = func_800F6840_HotBobOmb;
}

void func_800F6CEC_HotBobOmb(omObjData* obj) {
    obj->model[0] = LoadFormFile(0x190004, 0x99);
    obj->trans.x = 0.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = -100.0f;
    obj->scale.x = 1.0f;
    obj->scale.y = 1.0f;
    obj->scale.z = 1.0f;
    obj->func_ptr = func_800F6840_HotBobOmb;
}

void func_800F6D60_HotBobOmb(omObjData* obj) {
    func_800F6DD0_HotBobOmb(obj, 0);
}

void func_800F6D7C_HotBobOmb(omObjData* obj) {
    func_800F6DD0_HotBobOmb(obj, 1);
}

void func_800F6D98_HotBobOmb(omObjData* obj) {
    func_800F6DD0_HotBobOmb(obj, 2);
}

void func_800F6DB4_HotBobOmb(omObjData* obj) {
    func_800F6DD0_HotBobOmb(obj, 3);
}

void func_800F6DD0_HotBobOmb(omObjData* obj, s32 player) {
    s32 chr;
    s32 dir;

    chr = (s8)GwPlayer[player].character;
    dir = D_800C59AC[chr].unk_00;
    obj->model[0] = LoadFormFile(dir | D_800C59AC[chr].unk_04, 0x699);
    obj->model[1] = func_800174F4(6, 0x699);
    func_8001775C(obj, 1, dir | 0x46);
    func_8001775C(obj, 2, dir | 0x6D);
    func_8001775C(obj, 3, dir | 0x5E);
    func_8001775C(obj, 4, dir);
    func_8001775C(obj, 0, dir | 0x2F);
    if (!(rand8() & 1)) {
        func_8001775C(obj, 5, dir | 0xF);
        func_8001775C(obj, 7, dir | 0x10);
    } else {
        func_8001775C(obj, 5, dir | 0x38);
        func_8001775C(obj, 7, dir | 0x3C);
    }
    switch ((u32)dir >> 16) {
    case 5:
        D_800F9D44_HotBobOmb[player] = D_800F9DD4_HotBobOmb[player];
        break;
    case 3:
        D_800F9D44_HotBobOmb[player] = D_800FA0A4_HotBobOmb[player];
        break;
    case 4:
        D_800F9D44_HotBobOmb[player] = D_800F9EF4_HotBobOmb[player];
        break;
    case 2:
        D_800F9D44_HotBobOmb[player] = D_800F9E64_HotBobOmb[player];
        break;
    case 1:
        D_800F9D44_HotBobOmb[player] = D_800FA014_HotBobOmb[player];
        break;
    case 6:
        D_800F9D44_HotBobOmb[player] = D_800F9F84_HotBobOmb[player];
        break;
    }
    obj->scale.x = D_800F9D44_HotBobOmb[player].scale;
    obj->scale.y = D_800F9D44_HotBobOmb[player].scale;
    obj->scale.z = D_800F9D44_HotBobOmb[player].scale;
    obj->trans.x = D_800F9D44_HotBobOmb[player].pos.x;
    obj->trans.y = 0.0f;
    obj->trans.z = D_800F9D44_HotBobOmb[player].pos.z;
    obj->rot.y = D_800F9D44_HotBobOmb[player].rot;
    obj->unk_50 = &D_800F9D44_HotBobOmb[player];
    D_800FA8F0_HotBobOmb[player].obj = obj;
    D_800FA8F0_HotBobOmb[player].done = 0;
    D_800FA8F0_HotBobOmb[player].t = 0.0f;
    func_80025BB8(obj->model[0], obj->motion[2]);
    func_80025CA8(obj->model[0], 16.0f);
    func_80025EB4(obj->model[0], 1, 1);
    obj->func_ptr = func_800F724C_HotBobOmb;
}

// masked
#ifdef NON_MATCHING
void func_800F724C_HotBobOmb(omObjData* obj) {
    s32 idx;
    HbPlayer* p;

    idx = ((HbSeat*)obj->unk_50)->idx;
    p = &D_800FA8F0_HotBobOmb[idx];
    if (D_800FA99C_HotBobOmb == idx) {
        func_800F9AB8_HotBobOmb(idx);
        if (D_800F9D40_HotBobOmb == 0 && D_800FA864_HotBobOmb < 680.0f && p->t == 0.0f) {
            p->t = 0.0f;
            func_80025BB8(obj->model[0], obj->motion[2]);
            func_80025CA8(obj->model[0], 15.0f);
            func_80025EB4(obj->model[0], 4, 4);
        } else if (D_800FA9BC_HotBobOmb <= 0 && D_800FA99C_HotBobOmb == D_800FA998_HotBobOmb && D_800F9D40_HotBobOmb == 3) {
            if (D_800FA8F0_HotBobOmb[idx].done == 0) {
                D_800FA8F0_HotBobOmb[idx].done = 1;
                p->t = 0.0f;
                func_80025BB8(obj->model[0], obj->motion[0]);
                func_80025EB4(obj->model[0], 4, 0);
            }
        } else if (D_800FA8D0_HotBobOmb != 2 && D_800FA924_HotBobOmb == 0x12 - D_800FA994_HotBobOmb) {
            D_800FA1A4_HotBobOmb = idx;
            D_800FA1A0_HotBobOmb = 10;
            if (D_800FA988_HotBobOmb == 0) {
                p->t = 0.0f;
                func_80025BB8(obj->model[0], obj->motion[1]);
            } else if (D_800FA988_HotBobOmb == 1) {
                p->t = 0.0f;
                func_80025BB8(obj->model[0], obj->motion[3]);
            } else {
                p->t = 0.0f;
                func_80025BB8(obj->model[0], obj->motion[2]);
            }
            func_80025EB4(obj->model[0], 4, 0);
        }
    } else if (D_800FA998_HotBobOmb == idx) {
        if (D_800FA924_HotBobOmb == 0x11 - D_800FA994_HotBobOmb) {
            if (D_800FA988_HotBobOmb == 0) {
                p->t = 0.0f;
                func_80025BB8(obj->model[0], obj->motion[3]);
            } else if (D_800FA988_HotBobOmb == 1) {
                p->t = 0.0f;
                func_80025BB8(obj->model[0], obj->motion[1]);
            } else {
                p->t = 0.0f;
                func_80025BB8(obj->model[0], obj->motion[2]);
            }
            D_800FA174_HotBobOmb = (s16)PlaySound(0x206);
            D_800FA17C_HotBobOmb = D_800FA180_HotBobOmb[idx];
            func_8001249C((s16)D_800FA174_HotBobOmb, (u8)D_800FA17C_HotBobOmb);
            func_8001249C((s16)D_800FA178_HotBobOmb, (u8)D_800FA17C_HotBobOmb);
            func_80025CA8(obj->model[0], D_800ED554[D_800F2B7C[obj->model[0]].unk_08].unk_02 - 1);
            func_80025EB4(obj->model[0], 4, 4);
        }
    } else if (D_800FA9BC_HotBobOmb <= 0 && D_800FA99C_HotBobOmb == D_800FA998_HotBobOmb && D_800F9D40_HotBobOmb == 3) {
        if (D_800FA8F0_HotBobOmb[idx].done == 0) {
            D_800FA8F0_HotBobOmb[idx].done = 1;
            p->t = 0.0f;
        }
    } else if (p->t > 1.0f) {
        func_80025BB8(obj->model[0], obj->motion[4]);
        p->t = 0.0f;
    }
    if (D_800FA9BC_HotBobOmb > 0 || D_800FA99C_HotBobOmb != D_800FA998_HotBobOmb) {
        if (p->t > 1.0f) {
            p->t = 0.0f;
        } else {
            p->t += 0.033333335f;
        }
    }
    if (D_800FA1A4_HotBobOmb == idx) {
        if (--D_800FA1A0_HotBobOmb == 0) {
            D_800FA174_HotBobOmb = (s16)PlaySound(0x204);
            D_800FA17C_HotBobOmb = D_800FA180_HotBobOmb[idx];
            func_8001249C((s16)D_800FA174_HotBobOmb, (u8)D_800FA17C_HotBobOmb);
            func_8001249C((s16)D_800FA178_HotBobOmb, (u8)D_800FA17C_HotBobOmb);
            D_800FA1A4_HotBobOmb = -1;
        }
    }
    func_80025830(obj->model[1], obj->scale.x, obj->scale.y, obj->scale.z);
    func_800257E4(obj->model[1], obj->rot.x, obj->rot.y, obj->rot.z);
    func_80025798(obj->model[1], obj->trans.x, 1.0f, obj->trans.z);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_07_HotBobOmb/10CF70", func_800F724C_HotBobOmb);
#endif

void func_800F77B8_HotBobOmb(omObjData* obj, s32 unused) {
    unk_ovl_2D_struct* m;
    s32 i;

    for (i = 0; i < 4; i++) {
        m = &D_800F2B7C[obj->model[i]];
        if (++D_800FA1AC_HotBobOmb >= D_800ED554[m->unk_08].unk_02 * 2) {
            D_800FA1AC_HotBobOmb = 0;
        }
        m->unk_48 = D_800FA1AC_HotBobOmb / 2;
        func_80025830(obj->model[i], obj->scale.x, obj->scale.y, obj->scale.z);
        func_800257E4(obj->model[i], obj->rot.x, obj->rot.y, obj->rot.z);
        func_80025798(obj->model[i], obj->trans.x, obj->trans.y, obj->trans.z);
    }
    func_80025830(obj->model[4], obj->scale.x, obj->scale.y, obj->scale.z);
    func_800257E4(obj->model[4], obj->rot.x, obj->rot.y, obj->rot.z);
    func_80025798(obj->model[4], obj->trans.x, obj->trans.y, obj->trans.z);
}

// masked
#ifdef NON_MATCHING
void func_800F7934_HotBobOmb(omObjData* obj) {
    u16 m;
    void* data;
    s16 r;
    s32 i;

    D_800FA86C_HotBobOmb[0] = obj->model[0] = LoadFormFile(0x190006, 0x68D);
    D_800FA86C_HotBobOmb[1] = obj->model[1] = LoadFormFile(0x190006, 0x68D);
    D_800FA86C_HotBobOmb[2] = obj->model[2] = LoadFormFile(0x190006, 0x68D);
    D_800FA86C_HotBobOmb[3] = obj->model[3] = LoadFormFile(0x190006, 0x68D);
    D_800FA86C_HotBobOmb[4] = obj->model[4] = LoadFormFile(0x190006, 0x28D);
    obj->model[5] = func_800174F4(6, 0x699);

    m = obj->model[0];
    data = DataRead(0x190009);
    D_800FA9AC_HotBobOmb[0] = r = func_80038A9C(D_800F2B7C[m].unk_6C, data, 0, "maru_DEF");
    func_80039644(r, 1, 1);
    HuMemDirectFree(data);
    func_80025AD4(m);

    m = obj->model[1];
    data = DataRead(0x19000A);
    D_800FA9AC_HotBobOmb[1] = r = func_80038A9C(D_800F2B7C[m].unk_6C, data, 0, "maru_DEF");
    func_80039644(r, 1, 1);
    HuMemDirectFree(data);
    func_80025AD4(m);

    m = obj->model[2];
    data = DataRead(0x19000B);
    D_800FA9AC_HotBobOmb[2] = r = func_80038A9C(D_800F2B7C[m].unk_6C, data, 0, "maru_DEF");
    func_80039644(r, 1, 1);
    HuMemDirectFree(data);
    func_80025AD4(m);

    m = obj->model[3];
    data = DataRead(0x19000C);
    D_800FA9AC_HotBobOmb[3] = r = func_80038A9C(D_800F2B7C[m].unk_6C, data, 0, "maru_DEF");
    func_80039644(r, 1, 1);
    HuMemDirectFree(data);
    func_80025AD4(m);

    m = obj->model[4];
    data = DataRead(0x19000D);
    D_800FA9AC_HotBobOmb[4] = r = func_80038A9C(D_800F2B7C[m].unk_6C, data, 0, "maru_DEF");
    func_80039644(r, 1, 1);
    HuMemDirectFree(data);
    func_80025AD4(m);

    D_800FA89A_HotBobOmb = D_800FA9AC_HotBobOmb[0];
    for (i = 0; i < 5; i++) {
        m = obj->model[i];
        data = DataRead(0x19000E);
        D_800FA890_HotBobOmb[i] = r = func_80038A9C(D_800F2B7C[m].unk_6C, data, 0, "spark0_DEF");
        func_80039644(r, 1, 1);
        func_80025AD4(m);
        func_80025B34(m);
        HuMemDirectFree(data);
    }
    func_800258EC(D_800FA86C_HotBobOmb[0], 4, 0);
    func_800258EC(D_800FA86C_HotBobOmb[1], 4, 4);
    func_800258EC(D_800FA86C_HotBobOmb[2], 4, 4);
    func_800258EC(D_800FA86C_HotBobOmb[3], 4, 4);
    func_800258EC(D_800FA86C_HotBobOmb[4], 4, 4);
    func_8001775C(obj, 7, 0x190007);
    func_80025BB8(obj->model[0], obj->motion[7]);
    func_80025EB4(obj->model[0], 2, 2);
    func_80025BB8(obj->model[1], obj->motion[7]);
    func_80025EB4(obj->model[1], 2, 2);
    func_80025BB8(obj->model[2], obj->motion[7]);
    func_80025EB4(obj->model[2], 2, 2);
    func_80025BB8(obj->model[3], obj->motion[7]);
    func_80025EB4(obj->model[3], 2, 2);
    func_80025BB8(obj->model[4], obj->motion[7]);
    func_80025EB4(obj->model[4], 2, 2);
    D_800FA9A4_HotBobOmb = obj;
    obj->func_ptr = func_800F7E84_HotBobOmb;
    func_80021E58();
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_07_HotBobOmb/10CF70", func_800F7934_HotBobOmb);
#endif

// masked
#ifdef NON_MATCHING
void func_800F7E84_HotBobOmb(omObjData* obj) {
    f32 tbl[60] = {
        1.0f, 1.0f, 0.3f, 0.5f, 0.0f, 0.2f, 0.4f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.2f, 0.4f, 0.6f, 0.8f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
    };
    f32 f;
    f32 u;
    f32 s;
    s32 i;
    s32 n;
    s32 k;
    s32 a;
    s32 b;
    s32 v;

    f = ((18.0f - (f32)D_800FA924_HotBobOmb) - 5.0f) / 13.0f;
    switch (D_800F9D40_HotBobOmb) {
    case 0:
        for (i = 0; i < 5; i++) {
            func_80039644(D_800FA890_HotBobOmb[i], 1, 0);
        }
        obj->trans.y = D_800FA864_HotBobOmb;
        u = 1.0f - f;
        obj->trans.x = u * D_800F9D44_HotBobOmb[D_800FA99C_HotBobOmb].bomb.x + f * D_800F9D44_HotBobOmb[D_800FA998_HotBobOmb].bomb.x;
        obj->trans.z = u * D_800F9D44_HotBobOmb[D_800FA99C_HotBobOmb].bomb.z + f * D_800F9D44_HotBobOmb[D_800FA998_HotBobOmb].bomb.z;
        if (!(D_800FA864_HotBobOmb > 30.0f)) {
            obj->trans.y = 30.0f;
            D_800F9D40_HotBobOmb = 1;
            D_800FA864_HotBobOmb = 30.0f;
        }
        D_800FA1C0_HotBobOmb += 0.03f;
        break;
    case 1:
        for (i = 0; i < 5; i++) {
            func_80039644(D_800FA9AC_HotBobOmb[i], 1, 0);
            func_80039644(D_800FA890_HotBobOmb[i], 1, 0);
        }
        for (i = 0; i < 4; i++) {
            n = D_800FA8A0_HotBobOmb[i];
            if (n > 0) {
                break;
            }
        }
        if (n > 0 && D_800FA8D0_HotBobOmb == 2) {
            obj->trans.y = sinf(f * 3.1415f) * 30.0f + (D_800F9D44_HotBobOmb[D_800FA99C_HotBobOmb].bomb.y + 30.0f) * tbl[0x37 - n];
        } else if (f < 0.0f) {
            obj->trans.y = sinf(f * 3.1415f) * 30.0f + D_800F9D44_HotBobOmb[D_800FA99C_HotBobOmb].bomb.y;
            a = D_800FA180_HotBobOmb[D_800FA99C_HotBobOmb];
            b = D_800FA180_HotBobOmb[D_800FA998_HotBobOmb];
            if (b < a) {
                D_800FA198_HotBobOmb = -((a - b) / 30);
            } else {
                D_800FA198_HotBobOmb = (D_800FA180_HotBobOmb[D_800FA99C_HotBobOmb] - D_800FA180_HotBobOmb[D_800FA998_HotBobOmb]) / 30;
            }
        } else {
            obj->trans.y = sinf(f * 3.1415f) * 200.0f * ((5.0f - (f32)D_800FA994_HotBobOmb) / 5.0f) + 40.0f + D_800F9D44_HotBobOmb[D_800FA99C_HotBobOmb].bomb.y;
            u = 1.0f - f;
            obj->trans.x = u * D_800F9D44_HotBobOmb[D_800FA99C_HotBobOmb].bomb.x + f * D_800F9D44_HotBobOmb[D_800FA998_HotBobOmb].bomb.x;
            obj->trans.z = u * D_800F9D44_HotBobOmb[D_800FA99C_HotBobOmb].bomb.z + f * D_800F9D44_HotBobOmb[D_800FA998_HotBobOmb].bomb.z;
            D_800FA17C_HotBobOmb += D_800FA198_HotBobOmb;
            func_8001249C((s16)D_800FA174_HotBobOmb, (u8)D_800FA17C_HotBobOmb);
            func_8001249C((s16)D_800FA178_HotBobOmb, (u8)D_800FA17C_HotBobOmb);
        }
        if (D_800FA9BC_HotBobOmb <= 0 && D_800FA99C_HotBobOmb == D_800FA998_HotBobOmb) {
            D_800F9D40_HotBobOmb = 2;
        }
        if (D_800FA1B0_HotBobOmb == 0) {
            n = D_800FA19C_HotBobOmb++;
            if (n % 3 == 0) {
                k = n / 3;
                if ((k != 0) & (k < 5)) {
                    func_800258EC(D_800FA86C_HotBobOmb[k], 4, 0);
                    func_800258EC(D_800FA86C_HotBobOmb[k - 1], 4, 4);
                }
            }
            for (i = D_800FA190_HotBobOmb; i < 16; i++) {
                if (i * D_800FA194_HotBobOmb >= D_800FA9A8_HotBobOmb - D_800FA9BC_HotBobOmb) {
                    break;
                }
            }
            if (D_800FA194_HotBobOmb >= D_800FA9BC_HotBobOmb) {
                i = 15;
            }
            func_80060F04((s16)D_800FA99C_HotBobOmb, 5, 0, 5);
            D_800FA178_HotBobOmb = (s16)PlaySound((s16)D_800FA134_HotBobOmb[i]);
            D_800FA190_HotBobOmb = i + 1;
            if (D_800FA9BC_HotBobOmb < 450) {
                D_800FA860_HotBobOmb = (f32)(450 - D_800FA9BC_HotBobOmb) / 450.0f + 0.1f;
            } else {
                D_800FA860_HotBobOmb = 0.1f;
            }
            D_800FA1B0_HotBobOmb++;
        }
        s = sinf(2.0 * (D_800FA1C0_HotBobOmb * 3.1415)) * D_800FA860_HotBobOmb / (f32)D_800FA1B0_HotBobOmb;
        if (s < 0.0f) {
            s = -s;
        }
        obj->scale.x = obj->scale.y = obj->scale.z = s + 1.0f;
        n = ++D_800FA1B8_HotBobOmb;
        v = -1;
        if (D_800FA1C4_HotBobOmb < obj->scale.x) {
            v = 1;
            if (D_800FA1B4_HotBobOmb == -1) {
                D_800FA1B0_HotBobOmb++;
                if (D_800FA1BC_HotBobOmb == D_800FA1B4_HotBobOmb) {
                    if (n >= 41) {
                        D_800FA1B8_HotBobOmb = 0;
                        D_800FA1B0_HotBobOmb = 0;
                        D_800FA1BC_HotBobOmb = 0;
                    }
                } else if (D_800FA1B0_HotBobOmb >= 4) {
                    D_800FA1B8_HotBobOmb = 0;
                    D_800FA1B0_HotBobOmb = 0;
                }
            }
        }
        D_800FA1B4_HotBobOmb = v;
        D_800FA1C4_HotBobOmb = obj->scale.x;
        D_800FA1C0_HotBobOmb += 0.6f / (f32)(20 - D_800FA1B0_HotBobOmb * 2);
        break;
    case 2:
        for (i = 0; i < 5; i++) {
            func_80039644(D_800FA9AC_HotBobOmb[i], 1, 1);
            func_80039644(D_800FA890_HotBobOmb[i], 1, 1);
        }
        if (obj->scale.x < 3.4 && obj->scale.y < 3.4 && obj->scale.z < 3.4) {
            PlaySound(0x208);
            obj->scale.x = obj->scale.x * obj->scale.x / (f32)(func_800F680C_HotBobOmb() % 2 + 17) + obj->scale.x;
            obj->scale.y = obj->scale.y * obj->scale.y / (f32)(func_800F680C_HotBobOmb() % 2 + 17) + obj->scale.y;
            obj->scale.z = obj->scale.z * obj->scale.z / (f32)(func_800F680C_HotBobOmb() % 2 + 17) + obj->scale.z;
        } else {
            PlaySound(0x20A);
            func_800601D4(0x28);
            func_80060F04((s16)D_800FA99C_HotBobOmb, 2, 2, 0x14);
            func_80021EC0(2, obj->trans.x, obj->trans.y, obj->trans.z);
            D_800F9D40_HotBobOmb = 3;
        }
        break;
    case 3:
        if (D_800FA1A8_HotBobOmb < 28) {
            D_800FA1A8_HotBobOmb += 2;
        }
        obj->trans.x = 10000.0f;
        obj->trans.y = 10000.0f;
        obj->trans.z = 10000.0f;
        break;
    }
    func_80025830(obj->model[5], obj->scale.x, obj->scale.y, obj->scale.z);
    func_800257E4(obj->model[5], obj->rot.x, obj->rot.y, obj->rot.z);
    func_80025798(obj->model[5], obj->trans.x, 1.0f, obj->trans.z);
    obj->rot.x = obj->rot.z = 0.0f;
    func_800F77B8_HotBobOmb(obj, D_800FA868_HotBobOmb);
    if (++D_800FA868_HotBobOmb >= 4) {
        D_800FA868_HotBobOmb = 0;
    }
}
#else
const f32 D_800FA640_HotBobOmb[60] __attribute__((section(".rodata"))) = {
    1.0f, 1.0f, 0.3f, 0.5f, 0.0f, 0.2f, 0.4f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.2f, 0.4f, 0.6f, 0.8f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
};
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_07_HotBobOmb/10CF70", func_800F7E84_HotBobOmb);
#endif

void func_800F8A04_HotBobOmb(void) {
    s32 i;

    D_800FA39C_HotBobOmb = 0.0f;
    D_800FA3A0_HotBobOmb = D_800FA1C8_HotBobOmb;
    D_800FA3A4_HotBobOmb = 0;
    i = 0;
    D_800FA39C_HotBobOmb = 0.0f;
    while (D_800FA1C8_HotBobOmb[i].center.y > 0.0f) {
        D_800FA39C_HotBobOmb += D_800FA1C8_HotBobOmb[0].dur; /* retail: entry 0's every time */
        i++;
    }
    D_800F9D40_HotBobOmb = 0;
    D_800FA864_HotBobOmb = D_800FA1C8_HotBobOmb[0].center.y;
}

s32 func_800F8AB4_HotBobOmb(void) {
    HbCamKey cam; /* only the camera fields are filled */

    func_800F8D4C_HotBobOmb(D_800FA3AC_HotBobOmb, D_800FA3B0_HotBobOmb, &cam);
    CZoom = cam.zoom;
    CRot.x = cam.rot.x;
    CRot.y = cam.rot.y;
    CRot.z = cam.rot.z;
    Center.x = cam.center.x;
    Center.y = cam.center.y;
    Center.z = cam.center.z;
    D_800FA864_HotBobOmb = cam.center.y - 30.0f;
    D_800FA3AC_HotBobOmb += 1.0f / D_800FA3B0_HotBobOmb->dur;
    switch (D_800FA3B0_HotBobOmb->event) {
    case 2:
        break;
    case 1:
        GMesCreate(0);
        D_800FA3B0_HotBobOmb->event++;
        break;
    case 3:
        if (D_800FA3A8_HotBobOmb == 0) {
            PlaySound(0x20C);
            D_800FA3A8_HotBobOmb++;
        }
        break;
    case 4:
        if (D_800FA3A8_HotBobOmb == 1) {
            PlaySound(0x20E);
            func_8000BEBC(0x1E);
            D_800FA3A8_HotBobOmb++;
        }
        break;
    }
    if (D_800FA3AC_HotBobOmb >= 1.0f) {
        D_800FA3AC_HotBobOmb = 0.0f;
        D_800FA3B0_HotBobOmb++;
        D_800FA3B4_HotBobOmb++;
        if (D_800FA3B0_HotBobOmb[1].zoom <= 0.0f) {
            D_800FA3B0_HotBobOmb = D_800FA1C8_HotBobOmb;
            D_800FA3B4_HotBobOmb = 0;
            func_800191F8(D_800FA9B6_HotBobOmb);
            return 1;
        }
        return 0;
    }
    return 0;
}

void func_800F8CC8_HotBobOmb(void) {
    func_800178A0(1);
    CZoom = D_800FA3A0_HotBobOmb->zoom;
    CRot.x = D_800FA3A0_HotBobOmb->rot.x;
    CRot.y = D_800FA3A0_HotBobOmb->rot.y;
    CRot.z = D_800FA3A0_HotBobOmb->rot.z;
    Center.x = D_800FA3A0_HotBobOmb->center.x;
    Center.y = D_800FA3A0_HotBobOmb->center.y;
    Center.z = D_800FA3A0_HotBobOmb->center.z;
    func_8001D494(0, 33.0f, 80.0f, 4000.0f);
}

void func_800F8D4C_HotBobOmb(f32 t, HbCamKey* key, HbCamKey* out) {
    f32 u;
    f32 a;
    f32 b;
    f32 c;

    a = 1.0f - t;
    u = a;
    a = (a * a) / 2.0f;
    b = u * t + 0.5f;
    c = (t * t) / 2.0f;
    if (key[2].zoom < 0.0f) {
        out->zoom = a * key[0].zoom + b * key[1].zoom + c * key[1].zoom;
        out->rot.x = a * key[0].rot.x + b * key[1].rot.x + c * key[1].rot.x;
        out->rot.y = a * key[0].rot.y + b * key[1].rot.y + c * key[1].rot.y;
        out->rot.z = a * key[0].rot.z + b * key[1].rot.z + c * key[1].rot.z;
        out->center.x = a * key[0].center.x + b * key[1].center.x + c * key[1].center.x;
        out->center.y = a * key[0].center.y + b * key[1].center.y + c * key[1].center.y;
        out->center.z = a * key[0].center.z + b * key[1].center.z + c * key[1].center.z;
        return;
    }
    out->zoom = a * key[0].zoom + b * key[1].zoom + c * key[2].zoom;
    out->rot.x = a * key[0].rot.x + b * key[1].rot.x + c * key[2].rot.x;
    out->rot.y = a * key[0].rot.y + b * key[1].rot.y + c * key[2].rot.y;
    out->rot.z = a * key[0].rot.z + b * key[1].rot.z + c * key[2].rot.z;
    out->center.x = a * key[0].center.x + b * key[1].center.x + c * key[2].center.x;
    out->center.y = a * key[0].center.y + b * key[1].center.y + c * key[2].center.y;
    out->center.z = a * key[0].center.z + b * key[1].center.z + c * key[2].center.z;
}
