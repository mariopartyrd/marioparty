#include "GrabBag.h"

/* .data */
u8 D_800FB0C0_GrabBag = 0;
u16 D_800FB0C2_GrabBag = 0;
extern u16 D_800FB230_GrabBag;


extern omObjData* D_800F2AF8[];

typedef struct GrabBagGroundWork {
    char unk_00[4];
    s8 unk_04;
    s8 unk_05;
    char unk_06[0x26];
} GrabBagGroundWork;

void func_800F738C_GrabBag(omObjData*);
void func_800F7470_GrabBag(omObjData*);
void func_800F7538_GrabBag(omObjData*);
void func_800F69D4_GrabBag(omObjData*);

void func_800F7260_GrabBag(void) {
    omObjData* obj;
    u16 index;

    D_800ED440 = 0;
    func_800090B8(0);
    obj = omAddObj(1, 3, 0, -1, func_800F738C_GrabBag);
    index = D_800ED440;
    D_800ED440 = index + 1;
    D_800F2AF8[index] = obj;
    omAddObj(1, 2, 0, -1, func_800F7470_GrabBag);
}

void func_800F72E8_GrabBag(omObjData* arg0) {
    GrabBagGroundWork* work;

    work = func_80023684(sizeof(GrabBagGroundWork), 0x7918);
    arg0->unk_50 = work;
    func_8009B770(work, 0, sizeof(GrabBagGroundWork));
    work->unk_04 = 1;
    work->unk_05 = 1;
    arg0->model[0] = -1;
    arg0->func_ptr = NULL;
    func_80009028(arg0, 0, -475.0f, -2000.0f, 475.0f, 2000.0f);
}

void func_800F738C_GrabBag(omObjData* arg0) {
    f32 zero;
    GrabBagGroundWork* work;

    arg0->model[0] = func_800174C0(0x2F000C, 0x299);
    arg0->model[1] = func_800174C0(0x190004, 0x299);
    arg0->model[2] = func_800174C0(0x190003, 0x299);
    zero = 0.0f;
    arg0->trans.z = zero;
    arg0->trans.y = zero;
    arg0->trans.x = zero;
    func_80025798(arg0->model[0], 0.0f, arg0->trans.y, arg0->trans.z);
    work = func_80023684(sizeof(GrabBagGroundWork), 0x7918);
    arg0->unk_50 = work;
    func_8009B770(work, 0, sizeof(GrabBagGroundWork));
    work->unk_04 = 1;
    work->unk_05 = 0;
    func_80008FB8(arg0, 0.5f);
    arg0->func_ptr = func_800F69D4_GrabBag;
}

void func_800F7470_GrabBag(omObjData* arg0) {
    f32 zero;
    GrabBagGroundWork* work;

    arg0->model[0] = func_800174C0(0x220001, 0x299);
    arg0->model[1] = LoadFormFile(0x1E, 0x2CD);
    zero = 0.0f;
    arg0->trans.z = zero;
    arg0->trans.x = zero;
    arg0->trans.y = 190.0f;
    func_80025798(arg0->model[0], arg0->trans.x, 190.0f, arg0->trans.z);
    work = func_80023684(sizeof(GrabBagGroundWork), 0x7918);
    arg0->unk_50 = work;
    func_8009B770(work, 0, sizeof(GrabBagGroundWork));
    work->unk_04 = 1;
    work->unk_05 = 0;
    arg0->func_ptr = func_800F7538_GrabBag;
}

void func_800F7538_GrabBag(omObjData* arg0) {
    if (D_800ED430 == 0) {
        if (D_800FB230_GrabBag > 60) {
            arg0->trans.y -= 10.0f;
            if (arg0->trans.y < 0.0f) {
                arg0->trans.y = 0.0f;
            }
            if (D_800FB230_GrabBag == 80) {
                func_80017C0C(arg0, 1, 450.0f, 0.0f, -350.0f, 0.0f, 0.0f);
                PlaySound(0x1A0);
                func_80060128(0x1B);
            } else if (D_800FB230_GrabBag == 90) {
                D_800FB0C0_GrabBag = 1;
            }
            if (D_800FB230_GrabBag >= 86 && D_800FB230_GrabBag <= 96) {
                if (D_800FB0C2_GrabBag != 0) {
                    Center.y = -32.0f;
                } else {
                    Center.y = 32.0f;
                }
                D_800FB0C2_GrabBag ^= 1;
            }
        }
        D_800FB230_GrabBag++;
    }
}