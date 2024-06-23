#include "common.h"
#include "WhackAPlant.h"

INCLUDE_ASM(s32, "overlays/ovl_0F_WhackAPlant/131FA0", func_800F65E0_131FA0);

void func_800F6B8C_13254C(void) {
    s32 i = 0;
    
    for (i = 0; i < D_800F3778; i++) {}

}

void func_800F6BC4_132584(omObjData* arg0) {
    s16 temp_s2;
    s32 i;

    D_800FB740 = 0;
    D_800FB69A = 0;
    D_800FB6F4 = 0;
    D_800FB710[1] = 0;

    for (i = 0; i < 9; i++) {
        temp_s2 = func_8001E00C((void*)-1, 0x68D, 8);
        D_800ECDE0[temp_s2].unk_02 = D_800FB6BA;
        func_80025930(D_800ECDE0[temp_s2].unk_00, 0x60000000, 0x60000000);
        D_800FB6C0[i] = temp_s2;
        D_800FB6EA[i] = 0;
    }

    for (i = 0; i < 9; i++) {
        temp_s2 = func_8001E00C((void*)-1, 0x68D, 8);
        D_800ECDE0[temp_s2].unk_02 = D_800FB6BC;
        func_80025930(D_800ECDE0[temp_s2].unk_00, 0x60000000, 0x60000000);
        D_800FB6D8[i] = temp_s2;
        func_8001E2F8(temp_s2, 0xE0);
        func_8001E360(temp_s2, 0xFF, 0xFF, 0xBE);
    }

    D_800ED430 = 1;
    arg0->func_ptr = &func_800F6D54_132714;
}

void func_800F6D54_132714(void) {
    switch (D_800FB740) {
    case 0:
        func_800FA078_135A38();
        break;
    case 1:
        break;
    case 2:
        func_800FA1E0_135BA0();
        break;
    }
}

INCLUDE_ASM(s32, "overlays/ovl_0F_WhackAPlant/131FA0", func_800F6DBC_13277C);

void func_800F6FE4_1329A4(omObjData* arg0) {
    unkGlobalStruct_02* temp_s0;
    
    D_800F2AF8[D_800ED440++] = arg0;
    temp_s0 = HuMemTempDirectMalloc(sizeof(unkGlobalStruct_02), 0x7918);
    arg0->unk_50 = temp_s0;
    func_8009B770(temp_s0, 0, sizeof(unkGlobalStruct_02));
    temp_s0->unk_04 = 1;
    temp_s0->unk_05 = 1;
    func_80009058(arg0, 170.0f, 170.0f, -320.0f, -320.0f, 320.0f, 320.0f);
    func_80008FB8(arg0, 0.5f);
    arg0->func_ptr = NULL;
}

INCLUDE_ASM(s32, "overlays/ovl_0F_WhackAPlant/131FA0", func_800F70AC_132A6C);

void func_800F7570_132F30(omObjData* arg0) {
    unkGlobalStruct_00* temp_s1 = arg0->unk_50;

    if (D_800FB60A < 0x69) {
        omSetTra(arg0, arg0->trans.x, arg0->trans.y + PI, arg0->trans.z);
        func_80017DB0(arg0);
    } else {
        D_800FB710[0] = 3;
        arg0->func_ptr = &func_800F7714_1330D4;
        func_800258EC(D_800FB6F8->model[0], 0x1C00, 0x400);
        temp_s1->unk_3C = 0.0f;
    }

    D_800FB60A += 1;
    D_800FB724.x = func_800AEAC0(D_800FB60C) * D_800FB610;
    D_800FB724.z = func_800AEFD0(D_800FB60C) * D_800FB610;
    D_800FB724.y = D_800FB614 + 270.0f;
    D_800FB718 = D_800FB618 + 270.0f;
    D_800FB60C -= 3.4285715f;
    D_800FB610 = D_800FB610 + 7.561905f;
    D_800FB614 = D_800FB614 + 7.6190476f;
    D_800FB618 = D_800FB618 + -2.5714285f;
}

INCLUDE_ASM(s32, "overlays/ovl_0F_WhackAPlant/131FA0", func_800F7714_1330D4);

INCLUDE_ASM(s32, "overlays/ovl_0F_WhackAPlant/131FA0", func_800F7AE0_1334A0);

void func_800F7F90_133950(omObjData* arg0) {
    unkGlobalStruct_00* temp_s1 = arg0->unk_50;
    unk_Struct01* temp_v1 = temp_s1->unk_E4;

    if (D_800FB61C < 0xF) {
        temp_s1->unk_3C += temp_v1->unk_08;
        arg0->trans.x += temp_v1->unk_0C;
        arg0->trans.z += temp_v1->unk_10;
        D_800FB61C += 1;
        if (D_800FB61C == 0xF) {
            func_800184BC(arg0, 0);
            arg0->trans.x = arg0->trans.z = 0.0f;
            if (D_800FB698 == 0) {
                D_800FB730 = 1;
            }
        }
    }
    func_80017DB0(arg0);
    func_8009ECB0(&D_800F2B7C[arg0->model[0]].unk7C, 0.0f, temp_s1->unk_3C, 0.0f);
}

INCLUDE_ASM(s32, "overlays/ovl_0F_WhackAPlant/131FA0", func_800F8098_133A58);

// void func_800F8098_133A58(omObjData* arg0) {
//     u16 temp = (++D_800FB61E);
//     if (temp < 0x5A) {
//         arg0->unk_1C += -2.7777777f;
//     }
    
//     if (D_800FB620 != 0) {
//         u16 temp2 = (--D_800FB620); 
//         if (!temp2) {
//             func_80060540(0x24B, 0);
//         }
//     }
    
//     func_80017DB0(arg0);
// }

INCLUDE_ASM(s32, "overlays/ovl_0F_WhackAPlant/131FA0", func_800F8134_133AF4);

INCLUDE_ASM(s32, "overlays/ovl_0F_WhackAPlant/131FA0", func_800F82B4_133C74);

INCLUDE_ASM(s32, "overlays/ovl_0F_WhackAPlant/131FA0", func_800F8614_133FD4);

INCLUDE_ASM(s32, "overlays/ovl_0F_WhackAPlant/131FA0", func_800F87EC_1341AC);

INCLUDE_ASM(s32, "overlays/ovl_0F_WhackAPlant/131FA0", func_800F8A58_134418);

INCLUDE_ASM(s32, "overlays/ovl_0F_WhackAPlant/131FA0", func_800F8BE8_1345A8);

INCLUDE_ASM(s32, "overlays/ovl_0F_WhackAPlant/131FA0", func_800F92FC_134CBC);

INCLUDE_ASM(s32, "overlays/ovl_0F_WhackAPlant/131FA0", func_800F968C_13504C);

INCLUDE_ASM(s32, "overlays/ovl_0F_WhackAPlant/131FA0", func_800F97F8_1351B8);

INCLUDE_ASM(s32, "overlays/ovl_0F_WhackAPlant/131FA0", func_800F998C_13534C);

INCLUDE_ASM(s32, "overlays/ovl_0F_WhackAPlant/131FA0", func_800F9AF4_1354B4);

void func_800F9D38_1356F8(omObjData* arg0) {
    D_800FB6A4 = func_80019060(D_800FB6A2, 0, 1);
    func_80018D84(D_800FB6A4, 0x8000);
    D_800FB69E = func_80019060(D_800FB69C, 0, 1);
    D_800FB6A0 = func_80019060(D_800FB69C, 0, 1);
    func_80018D84(D_800FB69E, 0x8000);
    func_80018D84(D_800FB6A0, 0x8000);
    SetBasicSpritePos(D_800FB6A4, 0x8E, 0x20);
    SetBasicSpritePos(D_800FB69E, 0xA2, 0x20);
    SetBasicSpritePos(D_800FB6A0, 0xAA, 0x20);
    arg0->work[0] = 0;
    arg0->work[1] = 0;
    arg0->work[2] = 0;
    arg0->work[3] = 0;
    arg0->scale.y = 1.0f;
    arg0->func_ptr = &func_800F9E44_135804;
}

void func_800F9E44_135804(omObjData* arg0) {
    s32 temp_v1;
    u32 temp_s0;
    s32 temp_s1;
    
    temp_v1 = arg0->unk_10;
    
    if (temp_v1 != 0) {
        arg0->unk_10 = 0;
        if (temp_v1 == 1) {
            arg0->work[0] += arg0->work[3];
            arg0->work[3] = 0;
            arg0->work[1] = 2;
            arg0->scale.y = 1.0f;
        }
    }
    
    switch (arg0->work[1]) {
    case 2:
        arg0->scale.y += 0.3f;
        if (arg0->scale.y >= 2.4f) {
            arg0->work[1] = 4;
            arg0->scale.y = 2.4f;
        }
        break;

    case 4:
        arg0->scale.y -= 0.3f;
        if (arg0->scale.y <= 1.0f) {
            arg0->work[1] = 0;
            arg0->scale.y = 1.0f;
        }
        break;
    }

    temp_s1 = arg0->work[0];
    temp_s0 = arg0->work[0];
    temp_s0 = temp_s0 / 10;
    func_80018E50(D_800FB69E, temp_s0, 0);
    func_80018E50(D_800FB6A0, temp_s1 - (temp_s0 * 0xA), 0);
    SetBasicSpriteSize(D_800FB69E, 1.0f, arg0->scale.y);
    SetBasicSpriteSize(D_800FB6A0, 1.0f, arg0->scale.y);
    SetBasicSpritePos(D_800FB69E, 0xA0, 32.0f - ((arg0->scale.y - 1.0f) * 6.0f));
    SetBasicSpritePos(D_800FB6A0, 0xB0, 32.0f - ((arg0->scale.y - 1.0f) * 6.0f));
}


INCLUDE_ASM(s32, "overlays/ovl_0F_WhackAPlant/131FA0", func_800FA078_135A38);

INCLUDE_ASM(s32, "overlays/ovl_0F_WhackAPlant/131FA0", func_800FA1E0_135BA0);

void func_800FA668_136028(void) {
    if ((D_800FB608 != 0) || (D_800F5144 != 0)) {
        func_800FB4C0_136E80(131);
        func_800601D4(40);
    }
}

INCLUDE_ASM(s32, "overlays/ovl_0F_WhackAPlant/131FA0", func_800FA6AC_13606C);

INCLUDE_ASM(s32, "overlays/ovl_0F_WhackAPlant/131FA0", func_800FA760_136120);

INCLUDE_ASM(s32, "overlays/ovl_0F_WhackAPlant/131FA0", func_800FAF34_1368F4);

INCLUDE_ASM(s32, "overlays/ovl_0F_WhackAPlant/131FA0", func_800FB138_136AF8);
