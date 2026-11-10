#include "ChanceTime.h"

/* .data (0x80101360) */
s8 D_80101360_ChanceTime = 0;

void func_800FF6D0_ChanceTime(omObjData* arg0) {
    if (D_80101360_ChanceTime == 0) {
        if ((arg0->trans.x > -180.0f) && (arg0->trans.x < 180.0f) && (D_801011F8_ChanceTime == 1)) {
            func_80009028(arg0, 0, -2000.0f, -2000.0f, 2000.0f, 2000.0f);
            func_80009090(arg0);
            D_80101360_ChanceTime = 1;
        }
    }
}

void func_800FF780_ChanceTime(omObjData* arg0) {
    unkGlobalStruct_02* temp_s0;

    temp_s0 = func_80023684(sizeof(unkGlobalStruct_02), 0x7918);
    arg0->unk_50 = temp_s0;
    func_8009B770(temp_s0, 0, sizeof(unkGlobalStruct_02));
    temp_s0->unk_04 = 1;
    temp_s0->unk_05 = 0;
    func_80009028(arg0, 0, -250.0f, 1320.0f, 250.0f, 1480.0f);
    func_80009090(arg0);
    arg0->func_ptr = &func_800FF6D0_ChanceTime;
}

void func_800FF820_ChanceTime(void) { //fake match
    unkGlobalStruct_00 *new_var3;
    omObjData** new_var;
    
    new_var3 = D_800F3FB0[0]->unk_50;
    if (((D_800F3FB0[0]->trans.y + new_var3->unk_34) - 230.0f) >= (-40.0f)) {
        new_var3->unk_38 += 0.4f;
        new_var = &D_800F3FB0[0];
        (*new_var)->trans.y = 190.0f - new_var3->unk_34;
    }
}

void func_800FF8A4_ChanceTime(omObjData* arg0) {
    unkGlobalStruct_02* temp_s0;

    temp_s0 = func_80023684(sizeof(unkGlobalStruct_02), 0x7918);
    arg0->unk_50 = temp_s0;
    func_8009B770(temp_s0, 0, sizeof(unkGlobalStruct_02));
    temp_s0->unk_04 = 1;
    temp_s0->unk_05 = 1;
    func_80009028(arg0, 0, -2000.0f, -2000.0f, 2000.0f, 2000.0f);
    func_80009090(arg0);
    arg0->func_ptr = NULL;
}

void func_800FF930_ChanceTime(omObjData* arg0) {
    arg0->model[0] = func_800174F4(0x130000, 0x299);
    func_80025798(arg0->model[0], -140.0f, 0.0f, 1400.0f);
    func_80025830(arg0->model[0], 0.53f, 1.0f, 0.53f);
    arg0->trans.x = -140.0f;
    arg0->trans.y = 0.0f;
    arg0->trans.z = 1400.0f;
    arg0->scale.x = 0.53f;
    arg0->scale.y = 1.0f;
    arg0->scale.z = 0.53f;
    arg0->model[1] = func_80023FC8(arg0->model[0]);
    func_80025798(arg0->model[1], 0.0f, 0.0f, 1400.0f);
    func_80025830(arg0->model[1], 0.53f, 1.0f, 0.53f);
    arg0->model[2] = func_80023FC8(arg0->model[0]);
    func_80025798(arg0->model[2], 140.0f, 0.0f, 1400.0f);
    func_80025830(arg0->model[2], 0.53f, 1.0f, 0.53f);
    arg0->func_ptr = NULL;
}
