#include "UnusedMinigame1.h"

u16 D_800F9170_UnusedMinigame1 = 0;

void func_800F65E0_UnusedMinigame1(void) {
    omInitObjMan(0x20, 0);
    func_80060088();
    func_80029090(0x18);
    func_8001DE70(0x60);
    func_800F8D80_UnusedMinigame1(4100.0f, 318.0f, 0.0f, 0.0f, -140.0f, 308.0f, 170.0f);
    func_80017660(0, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 10.0f, 80.0f, 8000.0f);
    func_8002578C(0);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    omAddObj(0, 0, 0, -1, func_800F683C_UnusedMinigame1);
    D_800F9490_UnusedMinigame1 = -1;
    D_800F9470_UnusedMinigame1 = -1;
    func_800F67B0_UnusedMinigame1();
    func_800F6EE0_UnusedMinigame1();
    func_800F84CC_UnusedMinigame1();
    omAddObj(0x2710, 0, 0, -1, func_800F6E78_UnusedMinigame1);
    SetFadeInTypeAndTime(0, 0x10);
    D_800F941E_UnusedMinigame1 = 1;
    PlaySound(0x1AC);
    PlaySound(0x1AE);
}

/* Shuffle the face rows 0..3 (D_800F9492). */
void func_800F67B0_UnusedMinigame1(void) {
    s32 i;
    s32 r;
    s32 a;
    s32 b;
    u8 t;

    for (i = 0; i < 4; i++) {
        D_800F9492_UnusedMinigame1[i] = i;
    }
    for (i = 16; i != 0; i--) {
        r = rand8();
        a = (r >> 4) & 3;
        b = r & 3;
        t = D_800F9492_UnusedMinigame1[b];
        D_800F9492_UnusedMinigame1[b] = D_800F9492_UnusedMinigame1[a];
        D_800F9492_UnusedMinigame1[a] = t;
    }
}

void func_800F683C_UnusedMinigame1(omObjData* obj) {
    D_800F941C_UnusedMinigame1 = 0;
    D_800F9422_UnusedMinigame1 = 30;
    D_800ED430 = 0;
    D_800F94AC_UnusedMinigame1 = 1.0f;
    D_800F9418_UnusedMinigame1 = 0.0f;
    obj->func_ptr = func_800F6880_UnusedMinigame1;
}

void func_800F6880_UnusedMinigame1(omObjData* obj) {
    if (D_800C5982 == 1) {
        return;
    }
    switch (D_800F941C_UnusedMinigame1) {
        case 0:
            func_800F6C80_UnusedMinigame1();
            break;
        case 1:
            D_800F9418_UnusedMinigame1 += 0.005f;
            if (D_800F9418_UnusedMinigame1 > 1.0f) {
                D_800F9418_UnusedMinigame1 = 1.0f;
            }
            D_800F94AC_UnusedMinigame1 += D_800F9418_UnusedMinigame1;
            if (D_800F94AC_UnusedMinigame1 > 15.0f) {
                D_800F94AC_UnusedMinigame1 = 15.0f;
                D_800F941C_UnusedMinigame1 = 2;
                D_800F9420_UnusedMinigame1 = 1;
            }
            Center.x += 8.0f;
            if (Center.x > 165.0f) {
                Center.x = 165.0f;
            }
            D_800F9422_UnusedMinigame1--;
            if (D_800F9422_UnusedMinigame1 == 0) {
                D_800F9422_UnusedMinigame1 = 30;
            }
            break;
        case 2:
            func_800F6D88_UnusedMinigame1();
            break;
    }
}

/* The camera pans right, then bounces back to the start; returns the step (0 when done). */
u16 func_800F6A08_UnusedMinigame1(void) {
    switch (D_800F9426_UnusedMinigame1) {
        case 1:
            D_800F9424_UnusedMinigame1--;
            if (D_800F9424_UnusedMinigame1 == 0) {
                D_800F9410_UnusedMinigame1 = 8.0f;
                D_800F9414_UnusedMinigame1 = -0.1f;
                D_800F9426_UnusedMinigame1++;
            }
            break;
        case 2:
            Center.x += D_800F9410_UnusedMinigame1;
            D_800F9410_UnusedMinigame1 += D_800F9414_UnusedMinigame1;
            if (Center.x > 165.0f) {
                D_800F9426_UnusedMinigame1++;
                D_800F9424_UnusedMinigame1 = 10;
            }
            break;
        case 3:
            D_800F9424_UnusedMinigame1--;
            if (D_800F9424_UnusedMinigame1 == 0) {
                D_800F9426_UnusedMinigame1++;
                D_800F9410_UnusedMinigame1 = 0.0f;
                D_800F9414_UnusedMinigame1 = -2.5f;
                D_800F9424_UnusedMinigame1 = 5;
            }
            break;
        case 4:
            Center.x += D_800F9410_UnusedMinigame1;
            D_800F9410_UnusedMinigame1 += D_800F9414_UnusedMinigame1;
            if (Center.x < -140.0f) {
                D_800F9410_UnusedMinigame1 = 0.0f - D_800F9410_UnusedMinigame1 / 2.0f;
                D_800F9424_UnusedMinigame1--;
                if (D_800F9424_UnusedMinigame1 == 0) {
                    D_800F9426_UnusedMinigame1 = 0;
                }
            }
            break;
    }
    if (Center.x > 165.0f) {
        Center.x = 165.0f;
    } else if (Center.x < -140.0f) {
        Center.x = -140.0f;
    }
    return D_800F9426_UnusedMinigame1;
}

void func_800F6C80_UnusedMinigame1(void) {
    s32 stat;

    switch (D_800F941E_UnusedMinigame1) {
        case 1:
            if (func_80072718() == 0) {
                D_800F9424_UnusedMinigame1 = 4;
                D_800F9426_UnusedMinigame1 = 1;
                D_800F941E_UnusedMinigame1 = 2;
            }
            break;
        case 2:
            if (func_800F6A08_UnusedMinigame1() == 0) {
                D_800F941E_UnusedMinigame1 = 4;
            }
            break;
        case 4:
            D_800F941E_UnusedMinigame1 = 5;
            GMesCreate(0xD);
            break;
        case 5:
            stat = GMesStatAllGet();
            if (stat == 0 || (stat & 2)) {
                D_800F941E_UnusedMinigame1 = 6;
                D_800ED430 = 1;
                PlaySound(0x102);
            }
            break;
        case 6:
            if (func_800F8CD0_UnusedMinigame1() != 0) {
                D_800F941C_UnusedMinigame1 = 1;
            }
            break;
    }
}

void func_800F6D88_UnusedMinigame1(void) {
    s32 stat;

    switch (D_800F9420_UnusedMinigame1) {
        case 1:
        case 2:
            D_800ED430 = 2;
            D_800F9420_UnusedMinigame1 = 3;
            D_800F9424_UnusedMinigame1 = 120;
            func_800F85A0_UnusedMinigame1();
            func_800601D4(40);
            break;
        case 3:
            stat = GMesStatAllGet();
            if (stat == 0 || (stat & 2)) {
                D_800ED430 = 3;
                D_800F9420_UnusedMinigame1 = 4;
            }
            break;
        case 4:
            if (GMesWait() == 0) {
                D_800F9420_UnusedMinigame1 = 5;
                func_800726AC(0, 20);
            }
            break;
        case 5:
            if (func_80072718() == 0) {
                D_800F9170_UnusedMinigame1 = 1;
            }
            break;
    }
}

void func_800F6E78_UnusedMinigame1(omObjData* obj) {
    if (D_800F5144 != 0 || D_800F9170_UnusedMinigame1 != 0) {
        D_800B895C = 15.0f;
        func_800601D4(10);
        omOvlReturnEx(1);
    }
}

void func_800F6ECC_UnusedMinigame1(void) {
}
