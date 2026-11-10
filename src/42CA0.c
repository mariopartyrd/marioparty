#include "common.h"

void func_800420A0(void) {
    f32 volume = 96.0f;

    func_80060214(96);
    do {
        HuPrcVSleep();
        volume += 1.9375f;
        if (volume >= 127.0f) {
            volume = 127.0f;
        }
        func_80060214((s8)volume);
    } while (volume < 127.0f);
    EndProcess(NULL);
}
void func_80042140(void) {
    f32 volume = 127.0f;

    func_80060214(127);
    do {
        HuPrcVSleep();
        volume -= 1.9375f;
        if (volume <= 96.0f) {
            volume = 96.0f;
        }
        func_80060214((s8)volume);
    } while (volume > 96.0f);
    EndProcess(NULL);
}
void func_800421E0(void) {
    omAddPrcObj(func_80042140, 0xEFFF, 0, 0);
}
void func_8004220C(void) {
    omAddPrcObj(func_800420A0, 0xEFFF, 0, 0);
}