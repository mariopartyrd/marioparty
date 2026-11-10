#include "common.h"
#include "HotBobOmb.h"

u32 D_800F9D30_HotBobOmb = 0x0A6B99CD;

void func_800F65E0_HotBobOmb(void) {
    func_800F6800_HotBobOmb(rand8());
    func_80029090(1);
    func_8001DE70(0x14);
    omInitObjMan(0x14, 0);
    func_80060088();
    func_800F8CC8_HotBobOmb();
    func_8005D98C(0, 1);
    func_8005D98C(1, 4);
    func_8007B168((u8*)"\x82\x72\x82\x73\x82\x60\x82\x71\x82\x73", 1);         /* START */
    func_8007B168((u8*)"\x82\x65\x82\x68\x82\x6D\x82\x68\x82\x72\x82\x67", 1); /* FINISH */
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    omAddObj(4, 0, 0, -1, func_800F67C8_HotBobOmb);
    func_800F6848_HotBobOmb();
    func_800F693C_HotBobOmb();
    omAddObj(1, 0, 0, 1, func_800F66F8_HotBobOmb);
    func_800F8FA0_HotBobOmb();
    SetFadeInTypeAndTime(0, 0x10);
}

void func_800F66F8_HotBobOmb(omObjData* obj) {
    D_800FA8C8_HotBobOmb = 0;
    func_800F94AC_HotBobOmb();
    obj->func_ptr = func_800F6730_HotBobOmb;
}

void func_800F6730_HotBobOmb(omObjData* obj) {
    switch (D_800FA8C8_HotBobOmb) {
    case 0:
        func_800F8A04_HotBobOmb();
        D_800FA8C8_HotBobOmb = 1;
        break;
    case 1:
        if (func_800F8AB4_HotBobOmb() != 0) {
            D_800FA8C8_HotBobOmb = 2;
        }
        break;
    case 2:
        D_800FA8C8_HotBobOmb = 3;
        break;
    case 3:
        func_800F9690_HotBobOmb();
        break;
    case 4:
        func_800F902C_HotBobOmb();
        break;
    }
}

void func_800F67C8_HotBobOmb(omObjData* obj) {
    if (D_800F5144 == 1) {
        func_800601D4(0x3C);
        omOvlReturnEx(1);
    }
}

void func_800F6800_HotBobOmb(s32 seed) {
    D_800F9D30_HotBobOmb = seed;
}

// decomp-permuter
s32 func_800F680C_HotBobOmb(void)
{
  u32 t = (D_800F9D30_HotBobOmb * 4) + 2;
 do { } while (0);
  return D_800F9D30_HotBobOmb = (t * (t + 1)) >> 2;
}

/* Zero tail of .rodata: retail pads the unit to 16 bytes here. */
const s32 D_800FA608_HotBobOmb[2] = { 0, 0 };
