#include "RunningOfTheBulb.h"

void func_800FE090_RunningOfTheBulb(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    func_800178A0(1);
    CZoom = arg1;
    CRot.x = arg2;
    CRot.y = arg3;
    CRot.z = arg4;
    Center.x = arg5;
    Center.y = arg6;
    Center.z = arg7;
    D_800C3110->unk_40 = arg0;
}

void func_800FE140_RunningOfTheBulb(void) {
    s32 i;
    for (i = 0; i < D_800F3778; i++) {}
}

void func_800FE178_RunningOfTheBulb(s32 arg0) {
    omOvlReturnEx(1);
}

void func_800FE194_RunningOfTheBulb(void) {
    D_800EE738.unk4 = 0;
    D_800EE738.unk8 = 900.0f;
    D_800EE738.unk0 = 0;
    D_800C3110->unk_40 = 20.0f;
    D_800EE738.unkC = 20.0f;
    D_800EE738.unk10 = 20000.0f;
    D_800EE738.unk14 = 10000.0f;
    func_8001D420(0, &D_800FE484_RunningOfTheBulb, &D_800FE468_RunningOfTheBulb, &D_800FE4B8_RunningOfTheBulb);
    func_8001D57C(0);
}
