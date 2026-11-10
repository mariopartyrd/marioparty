#include "KeyPaWay.h"

void func_800F65E0_KeyPaWay(void) {
    void* temp_s0;
    s32 i;

    omInitObjMan(60, 0);
    func_80060088();
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    func_8001DE70(15);
    func_80029090(1);
    func_80009500();
    D_800FF538_KeyPaWay = 0;
    
    for (i = 0; i < 4; i++) {
        if (!(GwPlayer[i].flags & 1)) {
            D_800FF538_KeyPaWay += 1;
        }
    }
    
    func_800178A0(1);
    D_800FF564_KeyPaWay.x = 0;
    D_800FF564_KeyPaWay.y = -100.0f;
    D_800FF564_KeyPaWay.z = 1880.0f;
    D_800FF584_KeyPaWay.x = 0;
    D_800FF584_KeyPaWay.y = 300.0f;
    D_800FF584_KeyPaWay.z = 700.0f;
    D_800FF598_KeyPaWay.x = 0;
    D_800FF598_KeyPaWay.y = 1.0f;
    D_800FF598_KeyPaWay.z = 0;
    func_80017660(0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, &func_800FE33C_KeyPaWay), 0xA0);
    func_80023448(3);
    func_800234B8(0, 44, 44, 64);
    func_800234B8(1, 96, 96, 16);
    func_80023504(1, 100.0f, 80.0f, 100.0f);
    func_800234B8(2, 0, 0, 0);
    func_80023504(2, 100.0f, 80.0f, 100.0f);
    func_800234B8(3, 0, 0, 0);
    func_80023504(3, 100.0f, 80.0f, 100.0f);
    func_8005D98C(0, 4);
    func_8005D98C(1, 5);
    D_800FF548_KeyPaWay = func_8005DB44(1);
    D_800FF594_KeyPaWay = func_8005DB44(0);
    omSetStatBit(omAddObj(100, 0, 0, -1, &func_800FE2E8_KeyPaWay), 0xA0);
    omAddObj(10, 11, 37, 0, &func_800F8C54_KeyPaWay);
    omAddObj(10, 11, 37, 0, &func_800F8C70_KeyPaWay);
    omAddObj(10, 11, 37, 0, &func_800F8C8C_KeyPaWay);
    omAddObj(10, 11, 37, 0, &func_800F8CA8_KeyPaWay);
    D_800FF558_KeyPaWay = omAddObj(15, 0, 0, -1, &func_800FA7E0_KeyPaWay);
    omAddObj(20, 6, 4, 1, &func_800FA3B0_KeyPaWay);
    omAddObj(20, 6, 4, 1, &func_800FA3D0_KeyPaWay);
    omAddObj(20, 6, 4, 1, &func_800FA3F0_KeyPaWay);
    omAddObj(20, 6, 4, 1, &func_800FA410_KeyPaWay);
    omAddObj(20, 6, 4, 1, &func_800FA430_KeyPaWay);
    D_800FF590_KeyPaWay = omAddObj(30, 2, 0, -1, &func_800F76C8_KeyPaWay);
    D_800FF550_KeyPaWay = omAddObj(40, 10, 0, -1, &func_800F842C_KeyPaWay);
    D_800FF554_KeyPaWay = omAddObj(40, 11, 0, -1, &func_800F8918_KeyPaWay);
    D_800FF560_KeyPaWay = omAddObj(50, 1, 0, -1, &func_800FB9D4_KeyPaWay);
    omAddObj(0, 0, 0, -1, &func_800F6BD8_KeyPaWay);
    D_800FF53C_KeyPaWay = omAddObj(6, 6, 0, -1, &func_800F747C_KeyPaWay);
    omAddObj(0x2710, 0, 0, -1, &func_800FCC6C_KeyPaWay);
    D_800FF574_KeyPaWay = omAddObj(60, 0, 0, -1, &func_800FE710_KeyPaWay);
    D_800FF55C_KeyPaWay = omAddObj(40, 2, 0, -1, &func_800F6D98_KeyPaWay);
    D_800FF55C_KeyPaWay->unk_50 = func_80023684(sizeof(unkKeyPaWayStruct), 0x7918);
    func_8007B168(D_800FF3B0_KeyPaWay, 1);
    temp_s0 = DataRead(42);
    D_800FF534_KeyPaWay = func_80039084(temp_s0);
    HuMemDirectFree(temp_s0);
    temp_s0 = DataRead(38);
    D_800FF536_KeyPaWay = func_80039084(temp_s0);
    HuMemDirectFree(temp_s0);
    D_800FF526_KeyPaWay = _CheckFlag(43);
    D_800FF5A4_KeyPaWay = 0;
    SetFadeInTypeAndTime(0, 16);
}

void func_800F6BD8_KeyPaWay(omObjData* arg0) {
    s32 i;

    D_800FF580_KeyPaWay = 0;
    D_800FF544_KeyPaWay = 0;
    D_800FF540_KeyPaWay = 0;
    D_800FF532_KeyPaWay = 30;
    D_800FF530_KeyPaWay = 30;
    D_800FF514_KeyPaWay = 0;
    D_800FF54C_KeyPaWay = 0;
    
    for (i = 0; i < 4; i++) {
        D_800FF516_KeyPaWay[i] = 0;
    }
    
    D_800ED430 = 1;
    arg0->func_ptr = &func_800F6C58_KeyPaWay;
}


void func_800F6C58_KeyPaWay(omObjData* arg0) {
    func_80079078(D_800FF532_KeyPaWay);
    switch (D_800FF580_KeyPaWay) {
    case 0:
        if (D_800FF540_KeyPaWay == NULL) {
            D_800FF540_KeyPaWay = omAddObj(4, 0, 0, -1, func_800FBAD4_KeyPaWay);
        }
        break;
    case 1:
        D_800FF530_KeyPaWay--;
        if (D_800FF530_KeyPaWay == 0) {
            D_800FF532_KeyPaWay--;
            D_800FF530_KeyPaWay = 30;
        }
        if (*(u16*)&D_800FF532_KeyPaWay == 0) {
            D_800FF580_KeyPaWay = 2;
            D_800FF578_KeyPaWay = 15;
            D_800FF524_KeyPaWay = 16;
        }
        break;
    case 2:
        if (D_800FF544_KeyPaWay == NULL) {
            D_800FF544_KeyPaWay = omAddObj(4, 0, 0, -1, func_800FBC98_KeyPaWay);
        }
        break;
    }
}

void func_800F6D98_KeyPaWay(omObjData* arg0) {
    unkKeyPaWayStruct* temp_v0;

    temp_v0 = arg0->unk_50;
    temp_v0->unk_04 = 0;
    temp_v0->unk_08 = 0;
    arg0->model[0] = LoadFormFile(0x400011, 0xD);
    arg0->model[1] = LoadFormFile(0x400010, 0xD);
    func_80026040(arg0->model[0]);
    arg0->func_ptr = NULL;
}

void func_800F6E04_KeyPaWay(u16 arg0, f32 arg1, f32 arg2, f32 arg3) {
    unkKeyPaWayStruct* temp_v0;

    temp_v0 = D_800FF55C_KeyPaWay->unk_50;
    temp_v0->unk_04 = arg1;
    temp_v0->unk_08 = arg2;
    temp_v0->unk_0C = arg3;
    temp_v0->unk_00 = arg0;
    func_800258EC(D_800FF55C_KeyPaWay->model[0], 4, 0);
    omSetStatBit(D_800FF55C_KeyPaWay, 0xA0);
    D_800FF55C_KeyPaWay->func_ptr = &func_800F6E6C_KeyPaWay;
}

void func_800F6E6C_KeyPaWay(omObjData* arg0) {
    unkKeyPaWayStruct* temp_s0 = arg0->unk_50;
    f32 temp_f0;
    
    if (temp_s0->unk_00 != 0) {
        temp_s0->unk_00 -= 1;
    } else if ((func_8005FD5C() + D_800F64F8) == 0) {
        temp_f0 = temp_s0->unk_04 + temp_s0->unk_08;
        temp_s0->unk_04 = temp_f0;
        if (temp_s0->unk_0C < temp_f0) {
            temp_s0->unk_04 = temp_s0->unk_0C;
        }
    }
    func_80026174(arg0->model[0], arg0->model[1], temp_s0->unk_04);
}

// float constant register allocation; the 0.0f arguments come from a hoisted register (masked 14)
#ifdef NON_MATCHING
void func_800F6F10_KeyPaWay(omObjData* obj, u8 port) {
    KPWPlayerWork* work;
    KPWPlayerWork* ow;
    omObjData* other;
    f32 dx, dz, dist, x, z, angle, r;
    s32 i;

    work = KPW_PLAYER(obj);
    for (i = 0; i < 4; i++) {
        other = D_800FF594_KeyPaWay[i];
        if (other == D_800FF54C_KeyPaWay) {
            continue;
        }
        ow = KPW_PLAYER(other);
        if (ow->unk_38 == 1000.0f) {
            continue;
        }
        dx = obj->trans.x - other->trans.x;
        dx *= dx;
        dz = obj->trans.z - other->trans.z;
        dz *= dz;
        dist = func_800B1750(dx + dz);
        r = work->unk_48 + ow->unk_48;
        if (dist <= func_800B1750(r * r)) {
            if (func_800B1750(obj->trans.x * obj->trans.x + obj->trans.z * obj->trans.z) <= 400.0f) {
                x = 700.0f;
                if (obj->trans.x <= 0.0f) {
                    x = -700.0f;
                }
                z = 1000.0f;
                if (obj->trans.z <= 0.0f) {
                    z = -1000.0f;
                }
                angle = func_800F7134_KeyPaWay(obj, x, z, 45.0f, 220.0f);
            } else {
                angle = func_800F7134_KeyPaWay(obj, 0, 0, 45.0f, 220.0f);
            }
            ContStkX[port] = func_800AEAC0(angle) * 80.0f;
            ContStkY[port] = -func_800AEFD0(angle) * 80.0f;
            return;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800F6F10_KeyPaWay);
#endif

f32 func_800F7134_KeyPaWay(omObjData* obj, f32 x, f32 z, f32 angle, f32 dist) {
    f32 dists[4];
    f32 angs[4];
    KPWPlayerWork* work;
    omObjData* other;
    f32 dir, ox, oz, dx, dz;
    s32 i;
    u16 n;
    u16 tries;

    dir = func_800B0CD8(x - obj->trans.x, z - obj->trans.z);
    n = 0;
    for (i = 0; i < 4; i++) {
        other = D_800FF594_KeyPaWay[i];
        if (other == obj || other == D_800FF54C_KeyPaWay) {
            continue;
        }
        ox = other->trans.x;
        oz = other->trans.z;
        dx = ox - obj->trans.x;
        dx *= dx;
        dz = oz - obj->trans.z;
        dz *= dz;
        dists[n] = func_800B1750(dx + dz);
        angs[n] = func_800B0CD8(ox - obj->trans.x, oz - obj->trans.z);
        n++;
    }
    tries = 0;
    if (n != 0) {
        D_800FF51E_KeyPaWay = 0;
        D_800FF522_KeyPaWay = 0;
        work = KPW_PLAYER(obj);
        while (1) {
            for (i = 0; i < n; i++) {
                if (func_800FE1F0_KeyPaWay(angs[i], dir) <= angle && dists[i] <= dist) {
                    break;
                }
            }
            if (i == n) {
                ox = func_800AEAC0(dir) * work->unk_40 + obj->trans.x;
                oz = func_800AEFD0(dir) * work->unk_40 + obj->trans.z;
                if (work->unk_48 + -700.0f <= ox && ox <= 700.0f - work->unk_48 && work->unk_48 + -1000.0f <= oz && oz <= 1000.0f - work->unk_48) {
                    break;
                }
            }
            D_800FF522_KeyPaWay++;
            if (++tries == 36) {
                D_800FF51E_KeyPaWay = 1;
                break;
            }
            dir += 10.0f;
            if (dir > 180.0f) {
                dir -= 360.0f;
            }
        }
        if (dir < 0.0f) {
            dir += 360.0f;
        }
        if (dir >= 360.0f) {
            dir -= 360.0f;
        }
    }
    return dir;
}

const u8 D_800FF3B0_KeyPaWay[] __attribute__((section(".rodata"))) = { 0x82, 0x72, 0x82, 0x73, 0x82, 0x60, 0x82, 0x71, 0x00 };

void func_800F747C_KeyPaWay(omObjData* arg0) {
    void* data;
    KPWStageWork* work;

    arg0->model[0] = LoadFormFile(0x400012, 0x289);
    data = DataRead(0x27);
    func_80038A9C(D_800F2B7C[arg0->model[0]].unk_6C, data, 0, "00mt001s_IA44");
    func_80025AD4(arg0->model[0]);
    func_80025B34(arg0->model[0]);
    HuMemDirectFree(data);
    arg0->model[1] = LoadFormFile(0x40000E, 0x299);
    arg0->model[2] = LoadFormFile(0x40000F, 0x289);
    arg0->model[4] = LoadFormFile(0x400013, 0x2029D);
    func_80025798(arg0->model[4], 0.0f, 0.0f, -15.0f);
    arg0->model[5] = LoadFormFile(0x40000D, 0x69D);
    data = DataRead(0x400014);
    D_800FF53A_KeyPaWay = func_80038A9C(D_800F2B7C[arg0->model[2]].unk_6C, data, 0, "keybar_DEF");
    func_80025AD4(arg0->model[2]);
    func_80025B34(arg0->model[2]);
    HuMemDirectFree(data);
    func_8003967C(D_800FF53A_KeyPaWay, 1);
    func_80039644(D_800FF53A_KeyPaWay, 1, 1);
    func_800090B8(D_800ED440);
    D_800F2AF8[D_800ED440++] = arg0;
    work = arg0->unk_50 = func_80023684(sizeof(KPWStageWork), 0x7918);
    func_8009B770(work, 0, sizeof(KPWStageWork));
    work->unk_04 = 1;
    work->unk_05 = 0;
    func_80009028(arg0, 0, -700.0f, -1000.0f, 700.0f, 1000.0f);
    arg0->func_ptr = NULL;
}

void func_800F76C8_KeyPaWay(omObjData* arg0) {
    KPWBodyWork* work;
    KPWKeyExt* key;

    arg0->model[0] = LoadFormFile(0x400000, 0x699);
    arg0->model[1] = LoadFormFile(6, 0x699);
    func_800258EC(arg0->model[1], 4, 4);
    work = arg0->unk_50 = func_80023684(sizeof(KPWBodyWork), 0x7918);
    work->unk_44 = 0.1f;
    work->unk_48 = 30.0f;
    work->unk_34 = 0;
    work->unk_3C = 0;
    work->unk_5C = 0;
    work->unk_52 = 3;
    work->unk_60 = 0;
    work->unk_50 = 0x40;
    work->unk_54 = 1;
    work->unk_38 = 1000.0f;
    work->unk_40 = 0;
    work->unk_58 = 0.7f;
    work->unk_64 = NULL;
    omSetTra(arg0, 0.0f, 300.0f, 700.0f);
    omSetSca(arg0, 0.0f, 1.0f, 0.0f);
    D_800EDE70[D_800EE984++] = arg0;
    key = work->unk_68.key = func_80023684(sizeof(KPWKeyExt), 0x7918);
    key->unk_00 = 0;
    key->unk_18 = key->unk_10 = key->unk_1C = 0.0f;
    key->unk_20 = 0;
    key->unk_24 = NULL;
    arg0->func_ptr = func_800F7840_KeyPaWay;
}

/* Retail read D_800FF370's two halves as u16 scalars (a fresh %hi/%lo per access); the array
   spelling CSEs the address. The matching build names them through asm labels. */
extern u16 D_800FF370_0 __asm__("D_800FF370_KeyPaWay");
extern u16 D_800FF370_1 __asm__("D_800FF370_KeyPaWay+2");
/* Retail read D_800FF370's two halves as u16 scalars (a fresh %hi/%lo per access); the array
   spelling CSEs the address. The matching build names them through asm labels. */
extern u16 D_800FF370_0 __asm__("D_800FF370_KeyPaWay");
extern u16 D_800FF370_1 __asm__("D_800FF370_KeyPaWay+2");
// matches once 1F62C0.c.o is in the Makefile's blank-line-strip rule: KMC as adds a nop before the
void func_800F7840_KeyPaWay(omObjData* arg0) {
    f32 s, c;

    if (D_800FF370_0 != 0) {
        D_800FF370_0--;
        return;
    }
    if (--D_800FF370_1 == 0) {
        func_80060128(0x1F);
    }
    if (D_800FF368_KeyPaWay == 0.0f) {
        PlaySound(0x316);
    }
    if (D_800FF368_KeyPaWay < 1.0f) {
        D_800FF368_KeyPaWay += 0.01f;
        D_800FF36C_KeyPaWay += 0.01f;
        if (D_800FF368_KeyPaWay >= 1.0f) {
            D_800FF5A4_KeyPaWay = 3;
            D_800FF368_KeyPaWay = D_800FF36C_KeyPaWay = 1.0f;
        }
        omSetSca(arg0, D_800FF368_KeyPaWay, arg0->scale.y, D_800FF36C_KeyPaWay);
    }
    D_800FF360_KeyPaWay += 1.5f;
    if (--D_800FF364_KeyPaWay == 0) {
        s = func_800AEFD0(-D_800FF35C_KeyPaWay) * 60.0f;
        c = func_800AEAC0(-D_800FF35C_KeyPaWay) * 60.0f;
        func_800F8A28_KeyPaWay(-9.0f, s + arg0->trans.x, arg0->trans.y + D_800FF360_KeyPaWay, c + arg0->trans.z);
        D_800FF364_KeyPaWay = 3;
    }
    D_800FF35C_KeyPaWay += 12.0f;
    if (D_800FF35C_KeyPaWay >= 360.0f) {
        D_800FF35C_KeyPaWay -= 360.0f;
    }
    D_800FF358_KeyPaWay += 5.0f;
    if (D_800FF358_KeyPaWay >= 360.0f) {
        D_800FF358_KeyPaWay -= 360.0f;
    }
    omSetRot(arg0, arg0->rot.x, D_800FF358_KeyPaWay, arg0->rot.z);
}

void func_800F7AE0_KeyPaWay(omObjData* arg0) {
    KPWBodyWork* work;
    KPWKeyExt* key;
    KPWPlayerWork* pw;
    omObjData* other;
    f32 scale, dx, dy, dz, dist, r, x, y, z;
    u32 i;
    s32 hit;

    work = KPW_BODY(arg0);
    key = work->unk_68.key;
    if (work->unk_64 != key->unk_24) {
        if (work->unk_64 != NULL) {
            key->unk_00 = 1;
            func_800258EC(arg0->model[1], 4, 4);
            work->unk_38 = 1000.0f;
            work->unk_40 = 0.0f;
            D_800FF57C_KeyPaWay = work->unk_64;
        } else {
            scale = (800.0f - arg0->trans.y) / 800.0f;
            func_80025798(arg0->model[1], arg0->trans.x, 0.0f, arg0->trans.z);
            func_80025830(arg0->model[1], scale, scale, scale);
            if (work->unk_40 < 10.0f) {
                work->unk_40 = 10.0f;
            }
            key->unk_00 = 0;
            pw = KPW_PLAYER(D_800FF57C_KeyPaWay);
            pw->unk_E4->unk_30 = 0;
            D_800FF57C_KeyPaWay = NULL;
            func_800258EC(arg0->model[1], 4, 0);
            key->unk_08 = 30.0f;
            key->unk_10 = 30.0f;
            key->unk_04 = 6.0f;
            work->unk_40 = fabs(work->unk_40) * 2.0;
            key->unk_0C = func_800AEAC0(work->unk_3C);
            key->unk_14 = func_800AEFD0(work->unk_3C);
            key->unk_18 = key->unk_0C * work->unk_40;
            key->unk_1C = key->unk_14 * work->unk_40;
            work->unk_38 = 0.0f;
            key->unk_20 = 6;
            key->unk_22 = 1;
        }
        key->unk_24 = work->unk_64;
    }
    if (D_800FF580_KeyPaWay == 1) {
        hit = arg0->unk_10;
        if (hit != 0 && (arg0->unk_10 = 0, hit == D_800FF580_KeyPaWay)) {
            func_800258EC(arg0->model[1], 4, 4);
            D_800FF524_KeyPaWay = 14;
            D_800FF580_KeyPaWay = 2;
            D_800FF578_KeyPaWay = 14;
            func_800601D4(0x28);
            PlaySound(0x323);
            for (i = 0; i < 4; i++) {
                pw = KPW_PLAYER(D_800FF594_KeyPaWay[i]);
                pw->unk_50 |= 0x200;
                pw->unk_AE = 0;
                pw->unk_9C = 0;
                pw->unk_50 &= 0xFFF8;
                omSetSca(D_800FF594_KeyPaWay[i], 1.0f, 1.0f, 1.0f);
            }
        } else {
            if (key->unk_20 != 0) {
                if (--key->unk_22 == 0) {
                    func_800F8A28_KeyPaWay(0.0f, arg0->trans.x, arg0->trans.y, arg0->trans.z);
                    key->unk_22 = 2;
                    key->unk_20--;
                }
            }
            if (work->unk_38 != 1000.0f) {
                if ((u16)func_800FE134_KeyPaWay(arg0->trans.x + key->unk_18, arg0->trans.y, arg0->trans.z + key->unk_1C, work->unk_48) == 1) {
                    work->unk_40 *= 0.7f;
                    key->unk_08 -= 5.0f;
                    key->unk_14 = -key->unk_14;
                    key->unk_0C = -key->unk_0C;
                    key->unk_1C = key->unk_14 * work->unk_40;
                    key->unk_18 = key->unk_0C * work->unk_40;
                }
                for (i = 0; i < 4; i++) {
                    other = D_800FF594_KeyPaWay[i];
                    pw = KPW_PLAYER(other);
                    if (pw->unk_AE == 0) {
                        continue;
                    }
                    x = arg0->trans.x + key->unk_18;
                    y = arg0->trans.y + key->unk_10;
                    z = arg0->trans.z + key->unk_1C;
                    dx = other->trans.x;
                    dy = other->trans.y;
                    dz = other->trans.z;
                    dist = func_800B1750((dx - x) * (dx - x) + (dy - y) * (dy - y) + (dz - z) * (dz - z));
                    r = pw->unk_48 + work->unk_48;
                    if (dist <= func_800B1750(r * r)) {
                        work->unk_3C = func_8009B618((f32)(rand8() + rand8()), 360.0);
                        if (key->unk_08 < 15.0f) {
                            key->unk_08 = 15.0f;
                        }
                        key->unk_10 = key->unk_08;
                        if (work->unk_40 < 10.0f) {
                            work->unk_40 = 10.0f;
                        }
                        key->unk_0C = func_800AEAC0(work->unk_3C);
                        key->unk_14 = func_800AEFD0(work->unk_3C);
                        key->unk_18 = key->unk_0C * work->unk_40;
                        key->unk_1C = key->unk_14 * work->unk_40;
                        break;
                    }
                }
                if (arg0->trans.x + key->unk_18 >= 670.0f || arg0->trans.x + key->unk_18 <= -670.0f) {
                    work->unk_40 *= 0.3f;
                    key->unk_08 -= 9.0f;
                    key->unk_0C = -key->unk_0C;
                    key->unk_18 = key->unk_0C * work->unk_40;
                    func_800F8514_KeyPaWay(2, 3, 1.5f, arg0->trans.x, arg0->trans.y, arg0->trans.z);
                }
                if (arg0->trans.z + key->unk_1C >= 970.0f || arg0->trans.z + key->unk_1C <= -970.0f) {
                    work->unk_40 *= 0.3f;
                    key->unk_08 -= 9.0f;
                    key->unk_14 = -key->unk_14;
                    key->unk_1C = key->unk_14 * work->unk_40;
                    func_800F8514_KeyPaWay(1, 3, 1.5f, arg0->trans.x, arg0->trans.y, arg0->trans.z);
                }
                if (key->unk_08 <= 6.0f) {
                    if (arg0->trans.y <= 0.0f) {
                        work->unk_40 *= 0.9f;
                        key->unk_08 -= 0.05f;
                        if (key->unk_08 <= 0.0f) {
                            work->unk_40 = 0.0f;
                            work->unk_38 = 1000.0f;
                            key->unk_18 = key->unk_10 = key->unk_1C = 0.0f;
                        } else {
                            key->unk_18 = key->unk_0C * work->unk_40;
                            key->unk_1C = key->unk_14 * work->unk_40;
                        }
                    } else {
                        key->unk_08 += 6.0f;
                        work->unk_40 += 2.0f;
                    }
                }
                if (key->unk_08 > 6.0f) {
                    arg0->trans.y += key->unk_10;
                    key->unk_10 -= key->unk_04;
                    if ((u16)func_800FE134_KeyPaWay(arg0->trans.x + key->unk_18, arg0->trans.y, arg0->trans.z + key->unk_1C, work->unk_48) == 1) {
                        arg0->trans.y = 201.0f;
                        if (key->unk_08 > 6.0f) {
                            key->unk_10 = key->unk_08;
                        }
                    } else if (arg0->trans.y < 0.0f) {
                        arg0->trans.y = 0.0f;
                        key->unk_08 -= 6.0f;
                        if (key->unk_08 > 6.0f) {
                            key->unk_10 = key->unk_08;
                            work->unk_40 *= 0.9f;
                            key->unk_18 = key->unk_0C * work->unk_40;
                            key->unk_1C = key->unk_14 * work->unk_40;
                            func_800F8514_KeyPaWay(0, 3, 1.5f, arg0->trans.x, arg0->trans.y, arg0->trans.z);
                        }
                    }
                }
            }
            arg0->trans.x += key->unk_18;
            arg0->trans.z += key->unk_1C;
            func_80025798(arg0->model[1], arg0->trans.x, 0.0f, arg0->trans.z);
        }
    }
}

void func_800F842C_KeyPaWay(omObjData* arg0) {
    KPWFxSlots* slots;
    s32 i;

    slots = arg0->unk_50 = func_80023684(sizeof(KPWFxSlots), 0x7918);
    arg0->model[0] = -1;
    for (i = 1; i < 10; i++) {
        if (i == 1) {
            arg0->model[1] = LoadFormFile(3, 0x699);
        } else {
            arg0->model[i] = func_80023FC8(arg0->model[1]);
        }
        func_800258EC(arg0->model[i], 4, 4);
    }
    for (i = 0; i < 3; i++) {
        slots->busy[i] = 0;
    }
    arg0->func_ptr = NULL;
}

void func_800F8514_KeyPaWay(s16 mode, s16 count, f32 scale, f32 x, f32 y, f32 z) {
    omObjData* obj;
    KPWFxWork* fx;
    KPWFxSlots* slots;
    s16* mdl;
    s32 i;
    u16 slot;

    slots = D_800FF550_KeyPaWay->unk_50;
    for (i = 0; i < 3; i++) {
        if (slots->busy[i] == 0) {
            slot = i;
            slots->busy[i] = 1;
            break;
        }
    }
    if (i != 3) {
        obj = omAddObj(40, 0, 0, -1, func_800F8678_KeyPaWay);
        fx = obj->unk_50 = func_80023684(sizeof(KPWFxWork), 0x7918);
        omSetTra(obj, x, y, z);
        fx->slot = slot;
        fx->timer = 5;
        fx->count = count;
        fx->mode = mode;
        fx->radius = 50.0f;
        fx->scale = scale;
        mdl = &D_800FF550_KeyPaWay->model[slot * 3 + 1];
        for (i = 0; i < 3; i++) {
            func_800258EC(*mdl++, 4, 0);
        }
    }
}

void func_800F8678_KeyPaWay(omObjData* arg0) {
    KPWFxSlots* slots;
    KPWFxWork* fx;
    s16* mdl;
    f32 dx, dy, dz;
    s32 i;

    slots = D_800FF550_KeyPaWay->unk_50;
    fx = arg0->unk_50;
    mdl = &D_800FF550_KeyPaWay->model[fx->slot * 3 + 1];
    if (--fx->timer == 0) {
        for (i = 0; i < 3; i++) {
            func_800258EC(*mdl++, 4, 4);
        }
        slots->busy[fx->slot] = 0;
        omDelObj(arg0);
        return;
    }
    dz = 0.0f;
    dy = 0.0f;
    dx = 0.0f;
    for (i = 0; i < fx->count; i++) {
        switch (fx->mode) {
        case 0:
            dx = func_800AEFD0((360.0f / fx->count) * i) * fx->radius;
            dz = func_800AEAC0((360.0f / fx->count) * i) * fx->radius;
            break;
        case 1:
            dx = func_800AEFD0((360.0f / fx->count) * i) * fx->radius;
            dy = func_800AEAC0((360.0f / fx->count) * i) * fx->radius;
            break;
        case 2:
            dz = func_800AEFD0((360.0f / fx->count) * i) * fx->radius;
            dy = func_800AEAC0((360.0f / fx->count) * i) * fx->radius;
            break;
        }
        func_80025798(*mdl, dx + arg0->trans.x, dy + arg0->trans.y, dz + arg0->trans.z);
        func_80025830(*mdl, fx->scale, fx->scale, fx->scale);
        mdl++;
    }
    fx->radius += 40.0f;
}

void func_800F8918_KeyPaWay(omObjData* arg0) {
    KPWSparkSlots* slots;
    s32 i;

    slots = arg0->unk_50 = func_80023684(sizeof(KPWSparkSlots), 0x7918);
    arg0->model[0] = -1;
    for (i = 0; i < 10; i++) {
        slots->busy[i] = 0;
        slots->sprite[i] = func_8001E00C((void*)-1, 0x69D, 8);
        D_800ECDE0[slots->sprite[i]].unk_02 = D_800FF534_KeyPaWay;
        func_80025930(D_800ECDE0[slots->sprite[i]].unk_00, 0x40000000, 0x40000000);
        func_8001E268(slots->sprite[i], 4, 4);
        func_8001E2F8(slots->sprite[i], 0xE0);
        func_8001E360(slots->sprite[i], 0xFF, 0xFF, 0xBE);
    }
    arg0->func_ptr = NULL;
}

void func_800F8A28_KeyPaWay(f32 vy, f32 x, f32 y, f32 z) {
    KPWSparkSlots* slots;
    KPWSparkWork* sp;
    omObjData* obj;
    s32 i;
    u16 slot;

    slots = D_800FF554_KeyPaWay->unk_50;
    for (i = 0; i < 10; i++) {
        if (slots->busy[i] == 0) {
            slot = i;
            slots->busy[i] = 1;
            break;
        }
    }
    if (i != 10) {
        obj = omAddObj(40, 1, 0, -1, func_800F8B94_KeyPaWay);
        obj->unk_50 = func_80023684(sizeof(KPWSparkWork), 0x7918);
        omSetTra(obj, x, y, z);
        omSetSca(obj, 3.0f, 3.0f, 3.0f);
        sp = obj->unk_50;
        sp->timer = 30;
        sp->vy = vy;
        sp->slot = slot;
        obj->model[0] = D_800ECDE0[slots->sprite[slot]].unk_00;
        func_800258EC(obj->model[0], 4, 0);
        func_8001E2A8(slots->sprite[slot], 0);
    }
}

void func_800F8B94_KeyPaWay(omObjData* arg0) {
    KPWSparkSlots* slots;
    KPWSparkWork* sp;

    slots = D_800FF554_KeyPaWay->unk_50;
    sp = arg0->unk_50;
    arg0->trans.y += sp->vy;
    if (arg0->trans.y < 0.0f) {
        arg0->trans.y = 0.0f;
    }
    omSetTra(arg0, arg0->trans.x, arg0->trans.y, arg0->trans.z);
    if (--sp->timer == 0) {
        func_800258EC(arg0->model[0], 4, 4);
        slots->busy[sp->slot] = 0;
        omDelObj(arg0);
    }
}

void func_800F8C54_KeyPaWay(omObjData* arg0) {
    func_800F8CC4_KeyPaWay(arg0, 0);
}

void func_800F8C70_KeyPaWay(omObjData* arg0) {
    func_800F8CC4_KeyPaWay(arg0, 1);
}

void func_800F8C8C_KeyPaWay(omObjData* arg0) {
    func_800F8CC4_KeyPaWay(arg0, 2);
}

void func_800F8CA8_KeyPaWay(omObjData* arg0) {
    func_800F8CC4_KeyPaWay(arg0, 3);
}

// register allocation: chr/idx/mot in s0/s1/s6 instead of s1/s6/s0 (masked 0)
#ifdef NON_MATCHING
void func_800F8CC4_KeyPaWay(omObjData* obj, s32 player) {
    u8 chr;
    u16 idx;
    u32 dir;
    s32 file0;
    s32 mot;
    KPWPlayerWork* work;
    KPWPlayerExt* ext;

    chr = GwPlayer[(u16)player].character;
    idx = D_800C59A8[chr].index;
    dir = D_800C59AC[chr].unk_00;
    file0 = D_800C59AC[chr].unk_04;
    func_8000979C(obj, dir, file0, player, 0x20699, 0xA99);
    work = KPW_PLAYER(obj);
    work->unk_3C = 180.0f;
    work->unk_DC = func_800FB748_KeyPaWay;
    ext = work->unk_E4 = func_80023684(sizeof(KPWPlayerExt), 0x7918);
    ext->unk_00 = 0;
    ext->unk_30 = 1;
    ext->unk_28 = 0;
    ext->unk_14 = 0;
    ext->unk_26 = 1;
    if (D_800F2BC0 == 0) {
        obj->model[3] = LoadFormFile(0x19, 0x69D);
        obj->model[4] = LoadFormFile(0x1A, 0x69D);
    } else {
        obj->model[3] = func_80023FC8(D_800FF594_KeyPaWay[0]->model[3]);
        obj->model[4] = func_80023FC8(D_800FF594_KeyPaWay[0]->model[4]);
    }
    obj->model[9] = LoadFormFile(D_800FF2F8_KeyPaWay[idx] | 0x400000, 0x69D);
    switch (chr) {
    case 0:
    case 4:
        mot = 0xF;
        break;
    case 1:
    case 2:
    case 3:
    case 5:
        mot = 0x38;
        break;
    }
    func_800187D0(obj, 0xD, dir | mot, 1, 0x78);
    func_800187D0(obj, 0, dir, 1, 0);
    func_800187D0(obj, 1, dir | 1, 1, 0);
    func_800187D0(obj, 2, dir | 3, 1, 0);
    func_800187D0(obj, 6, dir | 5, 1, 0x13);
    func_800187D0(obj, 9, dir | 0xA, 1, 0x27);
    func_800187D0(obj, 0xE, dir | 0x10, 1, 0x78);
    func_800187D0(obj, 0x11, dir | 0x18, 0, 0);
    func_800187D0(obj, 0x12, dir | 0x1C, 0, 0);
    func_800187D0(obj, 0x13, dir | 0x1D, 0, 0);
    func_800187D0(obj, 0xA, dir | 0x1E, 1, 0x27);
    func_800187D0(obj, 0x16, dir | 0x65, 1, 0);
    func_800187D0(obj, 0x15, dir | 0x62, 0, 0);
    func_800187D0(obj, 0x14, dir | 0x5F, 2, 0);
    func_800187D0(obj, 0x20, dir | 0x67, 0, 0);
    func_800187D0(obj, 0x21, dir | 0x68, 0, 0);
    func_800187D0(obj, 0x22, dir | 0x69, 0, 0);
    func_8001874C(obj, 0x23, dir | 0x6C, 2, 0);
    obj->motion[36] = obj->motion[1];
    work->unk_D8[36][0] = work->unk_D8[1][0];
    work->unk_D8[36][1] = work->unk_D8[1][1];
    func_800090C4(obj, 0, 2);
    func_800090C4(obj, 1, 2);
    if (dir >> 16 == 5) {
        obj->scale.x = obj->scale.y = obj->scale.z = 0.95f;
    }
    if (dir >> 16 == 3) {
        obj->scale.x = obj->scale.y = obj->scale.z = 1.1f;
    }
    if (GwPlayer[work->unk_58].group == 0) {
        omSetTra(obj, D_800FF298_KeyPaWay[0].x, D_800FF298_KeyPaWay[0].y, D_800FF298_KeyPaWay[0].z);
        func_80025798(obj->model[1], D_800FF298_KeyPaWay[0].x, D_800FF298_KeyPaWay[0].y, D_800FF298_KeyPaWay[0].z);
        ext->unk_16 = 1;
        ext->unk_18 = 1;
        ext->unk_1C = D_800FF310_KeyPaWay[1][1][0];
        ext->unk_20 = D_800FF310_KeyPaWay[1][1][1];
        D_800FF50C_KeyPaWay[D_800F2BC0] = 0;
    } else {
        omSetTra(obj, D_800FF298_KeyPaWay[D_800FF374_KeyPaWay].x, D_800FF298_KeyPaWay[D_800FF374_KeyPaWay].y,
                 D_800FF298_KeyPaWay[D_800FF374_KeyPaWay].z);
        func_80025798(obj->model[1], D_800FF298_KeyPaWay[D_800FF374_KeyPaWay].x,
                      D_800FF298_KeyPaWay[D_800FF374_KeyPaWay].y, D_800FF298_KeyPaWay[D_800FF374_KeyPaWay].z);
        ext->unk_16 = D_800FF376_KeyPaWay - 1;
        ext->unk_18 = 1;
        ext->unk_1C = D_800FF310_KeyPaWay[D_800FF374_KeyPaWay - 1][1][0];
        ext->unk_20 = D_800FF310_KeyPaWay[D_800FF374_KeyPaWay - 1][ext->unk_18][1];
        D_800FF50C_KeyPaWay[D_800F2BC0] = D_800FF376_KeyPaWay;
        D_800FF374_KeyPaWay++;
    }
    D_800F3FB0[D_800F2BC0++] = obj;
    obj->func_ptr = func_800F92B8_KeyPaWay;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800F8CC4_KeyPaWay);
#endif

void func_800F92B8_KeyPaWay(omObjData* arg0) {
    KPWPlayerWork* work;
    s16 stkX;
    s16 stkY;
    u16 btnTrg;
    u16 btn;

    if (D_800FF580_KeyPaWay != 0) {
        arg0->func_ptr = func_800F9620_KeyPaWay;
        func_800F9620_KeyPaWay(arg0);
        return;
    }
    work = KPW_PLAYER(arg0);
    stkX = (s8)((u8*)ContStkX)[work->unk_56];
    stkY = (s8)((u8*)ContStkY)[work->unk_56];
    btnTrg = ContBtnTrg[work->unk_56];
    btn = ContBtn[work->unk_56];
    ContStkX[work->unk_56] = ContStkY[work->unk_56] = 0;
    ContBtnTrg[work->unk_56] &= 0x3FFF;
    ContBtn[work->unk_56] &= 0x3FFF;
    if (D_800FF5A4_KeyPaWay == 3 || D_800FF5A4_KeyPaWay == 4) {
        if (D_800FF5A4_KeyPaWay == 3) {
            if (GwPlayer[work->unk_58].group == 0) {
                if (D_800FF57C_KeyPaWay == NULL) {
                    ContStkY[work->unk_56] = 80;
                    if (arg0->trans.z < 750.0f && D_800FF57C_KeyPaWay == NULL) {
                        ContBtn[work->unk_56] |= 0x8000;
                        ContBtnTrg[work->unk_56] |= 0x8000;
                    }
                } else if (D_800FF590_KeyPaWay->func_ptr != func_800F7AE0_KeyPaWay) {
                    D_800FF590_KeyPaWay->func_ptr = func_800F7AE0_KeyPaWay;
                    omSetRot(D_800FF590_KeyPaWay, 0.0f, 0.0f, 0.0f);
                }
            } else if (arg0->trans.x > D_800FF2C8_KeyPaWay[D_800FF50C_KeyPaWay[work->unk_58]].x) {
                ContStkX[work->unk_56] = -80;
            }
        } else {
            if (GwPlayer[work->unk_58].group != 0) {
                if (D_800FF2C8_KeyPaWay[D_800FF50C_KeyPaWay[work->unk_58]].x + 80.0f < arg0->trans.x) {
                    ContStkX[work->unk_56] = -80;
                } else if (work->unk_3C != 180.0f) {
                    ContStkY[work->unk_56] = 80;
                }
            }
        }
    }
    func_80005A28(arg0);
    ContStkX[work->unk_56] = stkX;
    ContStkY[work->unk_56] = stkY;
    ContBtnTrg[work->unk_56] = btnTrg;
    ContBtn[work->unk_56] = btn;
}

void func_800F9620_KeyPaWay(omObjData* arg0) {
    KPWPlayerWork* work;
    KPWPlayerExt* ext;
    KPWEnemyExt* en;
    omObjData* obj;
    u16 btn;
    u16 btnTrg;
    u8 stkX;
    u8 stkY;
    s16 i;

    work = KPW_PLAYER(arg0);
    ext = work->unk_E4;
    btn = ContBtn[work->unk_56];
    btnTrg = ContBtnTrg[work->unk_56];
    stkX = ContStkX[work->unk_56];
    stkY = ContStkY[work->unk_56];
    if (D_800FF580_KeyPaWay == 2) {
        func_80009730();
        arg0->func_ptr = func_800F9A90_KeyPaWay;
        func_800F9A90_KeyPaWay(arg0);
        return;
    }
    if (GwPlayer[work->unk_58].flags & 1) {
        ContBtn[work->unk_56] = ContBtnTrg[work->unk_56] = ContStkX[work->unk_56] = ContStkY[work->unk_56] = 0;
        func_800FCCB0_KeyPaWay(arg0);
    }
    func_80005A28(arg0);
    ContBtn[work->unk_56] = btn;
    ContBtnTrg[work->unk_56] = btnTrg;
    ContStkX[work->unk_56] = stkX;
    ContStkY[work->unk_56] = stkY;
    if (work->unk_AE == 0) {
        ext->unk_00 = 0;
    }
    if (D_800FF57C_KeyPaWay == arg0 && work->unk_53 == 1) {
        D_800FF528_KeyPaWay = arg0->trans.x;
        D_800FF52C_KeyPaWay = arg0->trans.z;
        D_800FF514_KeyPaWay = 1;
        D_800FF524_KeyPaWay = 2;
        D_800FF580_KeyPaWay = 2;
        D_800FF578_KeyPaWay = 4;
        ext->unk_08 = (180.0 - fabs(work->unk_3C)) / 5.0;
        if (work->unk_3C < 0.0f) {
            ext->unk_08 = -ext->unk_08;
        }
        work->unk_40 = 0.0f;
        ext->unk_0C = (work->unk_40 - arg0->trans.x) / 5.0f;
        ext->unk_10 = (-850.0f - arg0->trans.z) / 5.0f;
        ext->unk_24 = 5;
        D_800FF54C_KeyPaWay = arg0;
        for (i = 0; i < 4; i++) {
            obj = D_800FF594_KeyPaWay[i];
            work = KPW_PLAYER(obj);
            ext = work->unk_E4;
            func_80009E20(obj);
            work->unk_40 = 0.0f;
            work->unk_50 |= 0x200;
            ext->unk_08 = (180.0 - fabs(work->unk_3C)) / 5.0;
            if (work->unk_3C < 0.0f) {
                ext->unk_08 = -ext->unk_08;
            }
            ext->unk_24 = 5;
            GwPlayer[i].coins_mg += 10;
        }
        PlaySound(0x326);
        for (i = 0; i < 5; i++) {
            func_800258EC(D_800FF548_KeyPaWay[i]->model[0], 4, 4);
            en = KPW_BODY(D_800FF548_KeyPaWay[i])->unk_68.enemy;
            func_800258EC(en->unk_2C, 4, 0);
            func_80025798(en->unk_2C, D_800FF548_KeyPaWay[i]->trans.x, D_800FF548_KeyPaWay[i]->trans.y + 50.0f,
                          D_800FF548_KeyPaWay[i]->trans.z + 100.0f);
            func_8001E268(en->unk_2A, 4, 4);
            func_8001E268(en->unk_2A, 1, 0);
            func_8001E2A8(en->unk_2A, 0);
        }
    }
}

void func_800F9A90_KeyPaWay(omObjData* arg0) {
    KPWPlayerWork* work;
    KPWPlayerExt* ext;
    f32 t;
    u8 port;
    u8 stkX;
    u8 stkY;
    u16 btnTrg;
    u16 btn;
    s16 i;
    s16 n;

    work = KPW_PLAYER(arg0);
    port = work->unk_56;
    stkX = ContStkX[port];
    stkY = ContStkY[port];
    btnTrg = ContBtnTrg[port];
    btn = ContBtn[port];
    ContBtnTrg[port] = ContBtn[port] = ContStkX[port] = ContStkY[port] = 0;
    if (D_800FF578_KeyPaWay == 4) {
        D_800FF578_KeyPaWay = 5;
    }
    ext = work->unk_E4;
    if (arg0 == D_800FF54C_KeyPaWay && D_800FF578_KeyPaWay != 15) {
        if (D_800FF578_KeyPaWay == 6) {
            if (ext->unk_24 != 0) {
                func_80005A28(arg0);
                work->unk_3C += ext->unk_08;
                omSetTra(arg0, arg0->trans.x + ext->unk_0C, 200.0f, arg0->trans.z + ext->unk_10);
                ext->unk_24--;
                goto restore;
            }
            for (i = 0; i < 5; i++) { /* retail's loop has an empty body */
            }
            if (i == 5) {
                D_800FF578_KeyPaWay = 7;
                work->unk_3C = 180.0f;
                D_800FF378_KeyPaWay = 20;
                func_800FE744_KeyPaWay(20, 0.0f, 250.0f, 800.0f, 0.0f, 250.0f, -700.0f);
            }
            func_80005A28(arg0);
        } else if (D_800FF578_KeyPaWay == 5) {
            D_800FF37A_KeyPaWay++;
            func_80005A28(arg0);
            omSetTra(arg0, D_800FF528_KeyPaWay, 200.0f, D_800FF52C_KeyPaWay);
        } else if (D_800FF578_KeyPaWay == 7) {
            if (--D_800FF378_KeyPaWay == 0) {
                D_800FF578_KeyPaWay = 8;
                func_8000A6F4(arg0);
                func_80025BB8(arg0->model[0], arg0->motion[35] & 0x3FFF);
            }
        } else if (D_800FF578_KeyPaWay == 8) {
            t = func_80025D18(arg0->model[0]);
            if (func_80025D40(arg0->model[0]) <= t) {
                D_800FF578_KeyPaWay = 9;
                for (i = 0; i < 5; i++) {
                    func_80025BB8(D_800FF548_KeyPaWay[i]->model[0], D_800FF548_KeyPaWay[i]->motion[2]);
                }
                func_800184BC(arg0, 0);
            } else if (func_80025D18(arg0->model[0]) > 50.0f && ext->unk_14 == 0) {
                PlaySound(0x320);
                ext->unk_14 = 1;
                func_8000A534(arg0, 0.0f);
                omSetTra(D_800FF590_KeyPaWay, arg0->trans.x, arg0->trans.y + 90.0f, arg0->trans.z - 30.0f);
                omSetRot(D_800FF590_KeyPaWay, 270.0f, 0.0f, 0.0f);
                KPW_BODY(D_800FF590_KeyPaWay)->unk_50 &= 0xFFDF;
                func_80009E20(arg0);
            }
            func_8009ECB0(D_800F2B7C[arg0->model[0]].unk7C, 0.0f, work->unk_3C, 0.0f);
        } else {
            func_80005A28(arg0);
            if (ext->unk_26 == 0) {
                func_800258EC(arg0->model[1], 4, 4);
            }
        }
    } else if (D_800FF578_KeyPaWay == 5 || D_800FF578_KeyPaWay == 14) {
        if ((D_800FF578_KeyPaWay == 5 && arg0->trans.y > 0.0f) ||
            (D_800FF578_KeyPaWay == 14 && work->unk_38 != 1000.0f)) {
            if (arg0->trans.x <= 0.0f) {
                if (arg0->trans.x <= -550.0f) {
                    ContStkX[port] = 80;
                } else {
                    ContStkX[port] = -80;
                }
            } else if (arg0->trans.x >= 550.0f) {
                ContStkX[port] = -80;
            } else {
                ContStkX[port] = 80;
            }
                        if (arg0->trans.z <= 0.0f) {
                if (arg0->trans.z <= -750.0f) {
                    ContStkY[port] = -80;
                } else {
                    ContStkY[port] = 80;
                }
            } else if (arg0->trans.z >= 750.0f) {
                ContStkY[port] = 80;
            } else {
                ContStkY[port] = -80;
            }
                        ContBtn[port] |= 0x8000;
            ContBtnTrg[port] |= 0x8000;
        } else {
            func_800F6F10_KeyPaWay(arg0, port);
        }
        func_80005A28(arg0);
        if (D_800FF578_KeyPaWay == 14 && work->unk_58 == 0) {
            D_800FF37A_KeyPaWay++;
        }
    } else {
        if (D_800FF578_KeyPaWay == 6 && ext->unk_24 != 0) {
            work->unk_3C += ext->unk_08;
            if (--ext->unk_24 == 0) {
                func_800184BC(arg0, 0);
            }
        }
        func_80005A28(arg0);
        if (ext->unk_26 == 0) {
            func_800258EC(arg0->model[1], 4, 4);
        }
    }
restore:
    ContStkX[port] = stkX;
    ContStkY[port] = stkY;
    ContBtnTrg[port] = btnTrg;
    ContBtn[port] = btn;
    if ((D_800FF578_KeyPaWay == 5 && arg0 == D_800FF54C_KeyPaWay) || D_800FF37A_KeyPaWay == 150) {
        n = 0;
        for (i = 0; i < 4; i++) {
            if (D_800FF594_KeyPaWay[i] == D_800FF54C_KeyPaWay) {
                n++;
            } else if (D_800FF594_KeyPaWay[i]->trans.y <= 0.0f) {
                n++;
            }
        }
        if (n == 4 || D_800FF37A_KeyPaWay == 150) {
            D_800ED430 = 2;
            if (D_800FF578_KeyPaWay != 14) {
                for (i = 0; i < 4; i++) {
                    work = KPW_PLAYER(D_800FF594_KeyPaWay[i]);
                    work->unk_AE = 0;
                    work->unk_9C = 0;
                    work->unk_50 &= 0xFFF8;
                    omSetSca(D_800FF594_KeyPaWay[i], 1.0f, 1.0f, 1.0f);
                    ext = work->unk_E4;
                    func_80009E20(D_800FF594_KeyPaWay[i]);
                    func_800185A4(D_800FF594_KeyPaWay[i], 0x24);
                    work->unk_40 = 0.0f;
                    ext->unk_08 = (180.0 - fabs(work->unk_3C)) / 5.0;
                    if (work->unk_3C < 0.0f) {
                        ext->unk_08 = -ext->unk_08;
                    }
                    ext->unk_24 = 5;
                }
                D_800FF578_KeyPaWay = 6;
            }
        }
    }
}

void func_800FA3B0_KeyPaWay(omObjData* arg0) {
    func_800FA450_KeyPaWay(arg0, 0, 0);
}

void func_800FA3D0_KeyPaWay(omObjData* arg0) {
    func_800FA450_KeyPaWay(arg0, 1, 0);
}

void func_800FA3F0_KeyPaWay(omObjData* arg0) {
    func_800FA450_KeyPaWay(arg0, 2, 0);
}

void func_800FA410_KeyPaWay(omObjData* arg0) {
    func_800FA450_KeyPaWay(arg0, 3, 0);
}

void func_800FA430_KeyPaWay(omObjData* arg0) {
    func_800FA450_KeyPaWay(arg0, 4, 0);
}

void func_800FA450_KeyPaWay(omObjData* obj, u16 index, u16 kind) {
    KPWBodyWork* work;

    work = obj->unk_50 = func_80023684(sizeof(KPWBodyWork), 0x7918);
    work->unk_44 = 0.1f;
    work->unk_48 = 45.0f;
    work->unk_34 = 100.0f;
    work->unk_3C = 0;
    work->unk_5C = 0;
    work->unk_52 = 7;
    work->unk_60 = 0;
    work->unk_50 = 0;
    work->unk_54 = 1;
    work->unk_68.enemy = NULL;
    work->unk_38 = 1000.0f;
    work->unk_40 = 0;
    func_800FA59C_KeyPaWay(obj, kind);
    work->unk_68.enemy->unk_02 = index;
    func_80025BB8(obj->model[0], obj->motion[1]);
    func_80025EB4(obj->model[0], 2, 2);
    omSetTra(obj, D_800FF270_KeyPaWay[index][0], 0.0f, D_800FF270_KeyPaWay[index][1]);
    D_800EDE70[D_800EE984++] = obj;
}

void func_800FA59C_KeyPaWay(omObjData* obj, u16 kind) {
    KPWBodyWork* work;
    KPWEnemyExt* en;

    work = KPW_BODY(obj);
    en = work->unk_68.enemy = func_80023684(sizeof(KPWEnemyExt), 0x7918);
    en->unk_06 = kind;
    en->unk_0A = 0;
    en->unk_1C = 0;
    en->unk_28 = 0;
    en->unk_34 = 1;
    if (kind == 0) {
        if (D_800FF37C_KeyPaWay == NULL) {
            obj->model[0] = LoadFormFile(0x400002, 0x20699);
            func_8001775C(obj, 0, 0x400004);
            func_8001775C(obj, 1, 0x400003);
            func_8001775C(obj, 2, 0x400005);
            D_800FF37C_KeyPaWay = obj;
        } else {
            obj->model[0] = func_80023FC8(D_800FF37C_KeyPaWay->model[0]);
            obj->motion[0] = D_800FF37C_KeyPaWay->motion[0];
            obj->motion[1] = D_800FF37C_KeyPaWay->motion[1];
            obj->motion[2] = D_800FF37C_KeyPaWay->motion[2];
        }
        en->unk_2A = func_8001E00C((void*)-1, 0x69D, 8);
        D_800ECDE0[en->unk_2A].unk_02 = D_800FF536_KeyPaWay;
        en->unk_2C = D_800ECDE0[en->unk_2A].unk_00;
        func_80025930(en->unk_2C, 0x40000000, 0x40000000);
        func_80025830(en->unk_2C, 2.0f, 2.0f, 2.0f);
        func_8001E268(en->unk_2A, 1, 1);
        en->unk_04 = 0;
        work->unk_40 = en->unk_18 = (D_800FF538_KeyPaWay * 2.5f + 370.0f) / 30.0f;
        en->unk_08 = 10;
        en->unk_24 = 200.0f;
        obj->func_ptr = func_800FAF28_KeyPaWay;
    }
}

void func_800FA7E0_KeyPaWay(omObjData* arg0) {
    arg0->work[0] = 0;
    arg0->func_ptr = &func_800FA7F4_KeyPaWay;
}

/* en briefly holds the body work before its extension: retail kept both in one register. */
void func_800FA7F4_KeyPaWay(omObjData* arg0) {
    f32 dists[5];
    KPWEnemyExt* en;
    omObjData* e;
    omObjData* best;
    f32 min;
    s32 i;

    if (D_800FF580_KeyPaWay == 1 && --D_800FF382_KeyPaWay == 0) {
        D_800FF382_KeyPaWay = (u8)(rand8() % 3) + 4;
        if (D_800FF380_KeyPaWay == 1) {
            if (D_800FF57C_KeyPaWay == NULL) {
                D_800FF380_KeyPaWay = 0;
            }
        }
        if (D_800FF380_KeyPaWay == 0) {
            if (D_800FF57C_KeyPaWay != NULL) {
                D_800FF380_KeyPaWay = 1;
            }
            if (D_800FF380_KeyPaWay == 0) {
                min = 10000.0f;
                for (i = 0; i < 5; i++) {
                    e = D_800FF548_KeyPaWay[i];
                    dists[i] = func_800B1750((D_800FF590_KeyPaWay->trans.x - e->trans.x) * (D_800FF590_KeyPaWay->trans.x - e->trans.x) +
                                             (D_800FF590_KeyPaWay->trans.z - e->trans.z) * (D_800FF590_KeyPaWay->trans.z - e->trans.z));
                    if (dists[i] < min) {
                        min = dists[i];
                        best = e;
                    }
                }
                if (min <= 300.0f) {
                    func_800FAAF4_KeyPaWay(best, D_800FF590_KeyPaWay);
                    en = best->unk_50;
                    en = ((KPWBodyWork*)en)->unk_68.enemy;
                    en->unk_04 = 2;
                    en->unk_0C = D_800FF590_KeyPaWay;
                    en->unk_10 = D_800FF590_KeyPaWay->trans.x;
                    en->unk_14 = D_800FF590_KeyPaWay->trans.z;
                } else {
                    for (i = 0; i < 5; i++) {
                        en = D_800FF548_KeyPaWay[i]->unk_50;
                        en = ((KPWBodyWork*)en)->unk_68.enemy;
                        en->unk_04 = 2;
                        en->unk_0C = D_800FF590_KeyPaWay;
                        en->unk_10 = D_800FF590_KeyPaWay->trans.x;
                        en->unk_14 = D_800FF590_KeyPaWay->trans.z;
                    }
                }
                return;
            }
        }
        min = 10000.0f;
        for (i = 0; i < 5; i++) {
            e = D_800FF548_KeyPaWay[i];
            dists[i] = func_800B1750((D_800FF57C_KeyPaWay->trans.x - e->trans.x) * (D_800FF57C_KeyPaWay->trans.x - e->trans.x) +
                                     (D_800FF57C_KeyPaWay->trans.z - e->trans.z) * (D_800FF57C_KeyPaWay->trans.z - e->trans.z));
            if (dists[i] < min) {
                min = dists[i];
                best = e;
            }
        }
        func_800FAAF4_KeyPaWay(best, D_800FF57C_KeyPaWay);
        en = best->unk_50;
        en = ((KPWBodyWork*)en)->unk_68.enemy;
        en->unk_04 = 3;
        en->unk_0C = D_800FF57C_KeyPaWay;
        en->unk_10 = D_800FF57C_KeyPaWay->trans.x;
        en->unk_14 = D_800FF57C_KeyPaWay->trans.z;
    }
}

// register allocation: v0/v1 swapped for the key/carrier pointer (masked 0)
#ifdef NON_MATCHING
void func_800FAAF4_KeyPaWay(omObjData* obj, omObjData* target) {
    f32 dist[4];
    f32 tx[4];
    f32 tz[4];
    u16 idx[4];
    omObjData* e;
    omObjData* p;
    omObjData* ref;
    KPWEnemyExt* ext;
    f32 dSelf;
    f32 dRef;
    f32 aSelf;
    f32 aRef;
    u16 t;
    s32 i;
    s32 n;

    for (i = 0; i < 4; i++) {
        D_800FF516_KeyPaWay[i] = 0;
    }
    for (n = 0; n < 5; n++) {
        e = D_800FF548_KeyPaWay[n];
        if (e == obj) {
            continue;
        }
        ext = KPW_BODY(e)->unk_68.enemy;
        for (i = 0; i < 4; i++) {
            p = D_800FF594_KeyPaWay[i];
            tx[i] = (target->trans.x - p->trans.x) * 0.75f + p->trans.x;
            tz[i] = (target->trans.z - p->trans.z) * 0.75f + p->trans.z;
            dist[i] = func_800B1750(SQ(tx[i] - e->trans.x) + SQ(tz[i] - e->trans.z));
            idx[i] = i;
        }
        for (i = 0; i < 3; i++) {
            if (dist[idx[i]] > dist[idx[i + 1]]) {
                t = idx[i + 1];
                idx[i + 1] = idx[i];
                idx[i] = t;
            }
        }
        for (i = 0; i < 4; i++) {
            if (D_800FF516_KeyPaWay[idx[i]] != 1) {
                ext->unk_0C = D_800FF594_KeyPaWay[idx[i]];
                ext->unk_10 = tx[idx[i]];
                ext->unk_14 = tz[idx[i]];
                D_800FF516_KeyPaWay[idx[i]] = 1;
                dSelf = func_800B1750(SQ(ext->unk_0C->trans.x - e->trans.x) + SQ(ext->unk_0C->trans.z - e->trans.z));
                if (D_800FF57C_KeyPaWay == NULL) {
                    aSelf = func_800B0CD8(e->trans.z - D_800FF590_KeyPaWay->trans.z, e->trans.x - D_800FF590_KeyPaWay->trans.x);
                    dRef = func_800B1750(SQ(ext->unk_0C->trans.x - D_800FF590_KeyPaWay->trans.x) +
                                         SQ(ext->unk_0C->trans.z - D_800FF590_KeyPaWay->trans.z));
                    ref = D_800FF590_KeyPaWay;
                } else {
                    aSelf = func_800B0CD8(e->trans.z - ext->unk_0C->trans.z, e->trans.x - ext->unk_0C->trans.x);
                    dRef = func_800B1750(SQ(ext->unk_0C->trans.x - D_800FF57C_KeyPaWay->trans.x) +
                                         SQ(ext->unk_0C->trans.z - D_800FF57C_KeyPaWay->trans.z));
                    ref = D_800FF57C_KeyPaWay;
                }
                aRef = func_800B0CD8(ref->trans.z - ext->unk_0C->trans.z, ref->trans.x - ext->unk_0C->trans.x);
                if ((u8)(rand8() % 10) < 3 || (func_800FE1F0_KeyPaWay(aSelf, aRef) < 20.0f && dSelf < dRef)) {
                    ext->unk_04 = 4;
                } else {
                    ext->unk_04 = 1;
                }
                break;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2C_KeyPaWay/1F62C0", func_800FAAF4_KeyPaWay);
#endif
void func_800FAF28_KeyPaWay(omObjData* obj) {
    f32 dummy;
    KPWBodyWork* work = KPW_BODY(obj);
    KPWEnemyExt* ext = work->unk_68.enemy;
    f32 dx;
    f32 dz;
    f32 angle;
    u16 count;
    u16 done;
    u16 t;

    if (D_800FF580_KeyPaWay == 2) {
        return;
    }
    if (D_800FF580_KeyPaWay != 1) {
        return;
    }
    dz = 0.0f;
    angle = work->unk_3C;
    dx = dz;
    switch (ext->unk_04) {
    case 0:
        break;
    case 1:
    case 2:
        if (ext->unk_28 == 0) {
            goto calc;
        }
        goto dec;
    case 3:
        if (ext->unk_28 != 0) {
            goto dec;
        }
    calc:
        angle = func_800FB38C_KeyPaWay(work, func_800B0CD8(ext->unk_10 - obj->trans.x, ext->unk_14 - obj->trans.z));
        goto move;
    dec:
        ext->unk_28--;
    move:
        dx = func_800AEAC0(angle) * ext->unk_18;
        dz = func_800AEFD0(angle) * ext->unk_18;
        break;
    case 4:
        func_800FB38C_KeyPaWay(work, func_800B0CD8(ext->unk_10 - obj->trans.x, ext->unk_14 - obj->trans.z));
        break;
    case 5:
        func_800FB38C_KeyPaWay(work, ext->unk_30);
        break;
    }
    if (work->unk_3C < 0.0f) {
        work->unk_3C += 360.0f;
    }
    count = 0;
    if (work->unk_3C >= 360.0f) {
        work->unk_3C -= 360.0f;
    }
    done = 0;
    angle = work->unk_3C;
    do {
        switch (func_800FB498_KeyPaWay(obj, dx + obj->trans.x, dz + obj->trans.z, &dummy)) {
        case 1:
        case 2:
            angle += 45.0f;
            if (angle >= 360.0f) {
                angle -= 360.0f;
            }
            dx = func_800AEAC0(angle) * ext->unk_18;
            dz = func_800AEFD0(angle) * ext->unk_18;
            if (++count == 8) {
                angle -= 180.0f;
                done = 1;
                if (angle < 0.0f) {
                    angle += 360.0f;
                }
                dz = 0.0f;
                dx = dz;
            }
            ext->unk_04 = 5;
            ext->unk_30 = angle;
            ext->unk_28 = 300;
            break;
        case 3:
            KPW_BODY(D_800FF590_KeyPaWay)->unk_50 |= 0x20;
            func_8005DC18(D_800FF590_KeyPaWay, 1);
            if (ext->unk_02 != 4) {
                t = D_800FF548_KeyPaWay[4]->model[0];
                D_800FF548_KeyPaWay[4]->model[0] = D_800FF548_KeyPaWay[ext->unk_02]->model[0];
                D_800FF548_KeyPaWay[ext->unk_02]->model[0] = t;
            }
            done = 1;
            func_80025BB8(obj->model[0], obj->motion[0]);
            func_80025EB4(obj->model[0], 2, 2);
            func_8002859C(D_800FF590_KeyPaWay->model[0], obj->model[0], "c110_4_2-item");
            func_800258EC(D_800FF590_KeyPaWay->model[0], 0x4000, 0x4000);
            break;
        case 4:
            ext->unk_28 = 0;
            break;
        case 5:
            ext->unk_04 = 4;
            dz = 0.0f;
            dx = dz;
            done = 1;
            break;
        default:
            if (angle == work->unk_3C) {
                done = 1;
            } else if (ext->unk_04 == 5) {
                done = 1;
            } else {
                work->unk_3C = angle;
                done = 1;
            }
            break;
        }
    } while (done == 0);
    omSetRot(obj, 0.0f, work->unk_3C, 0.0f);
    omSetTra(obj, dx + obj->trans.x, obj->trans.y, dz + obj->trans.z);
}
f32 func_800FB38C_KeyPaWay(KPWBodyWork* work, f32 angle) {
    f32 cur;
    f32 d;

    cur = work->unk_3C;
    if (cur > 180.0f) {
        cur -= 360.0f;
    }
    if (cur != angle) {
        d = angle - cur;
        if (d < 0.0f) {
            d += 360.0f;
        }
        if (d < 180.0f) {
            if (d > 10.0f) {
                cur += 10.0f;
            } else {
                cur += d;
            }
        } else if (360.0f - d > 10.0f) {
            cur -= 10.0f;
        } else {
            cur -= 360.0f - d;
        }
    }
    work->unk_3C = cur;
    return cur;
}
u16 func_800FB498_KeyPaWay(omObjData* obj, f32 x, f32 z, f32* out) {
    KPWBodyWork* work = KPW_BODY(obj);
    KPWEnemyExt* ext = work->unk_68.enemy;
    f32 r = work->unk_48;
    omObjData* p;
    f32 r2;
    f32 dist;
    f32 lim;
    s32 i;

    if (D_800FF57C_KeyPaWay == NULL) {
        p = D_800FF590_KeyPaWay;
        r2 = KPW_BODY(p)->unk_48;
        dist = func_800B1750(SQ(x - p->trans.x) + SQ(obj->trans.y - p->trans.y) + SQ(z - p->trans.z));
        if (dist < func_800B1750((r + r2) * (r + r2))) {
            return 3;
        }
    }
    if ((u16)func_800FE134_KeyPaWay(x, obj->trans.y, z, r) == 1) {
        dist = func_800B1750(SQ(x - 0.0f) + SQ(z - -850.0f));
        *out = func_800B1750((r + 115.0f) * (r + 115.0f)) - dist;
        return 2;
    }
    if (x < -655.0f) {
        obj->trans.x += -655.0f - x;
        return 4;
    } else if (x > 655.0f) {
        obj->trans.x += 655.0f - x;
        return 4;
    }
    if (z < -955.0f) {
        obj->trans.z += -955.0f - z;
        return 4;
    } else if (z > 955.0f) {
        obj->trans.z += 955.0f - z;
        return 4;
    }
    r = ext->unk_24;
    for (i = 0; i < 5; i++) {
        if (D_800FF548_KeyPaWay[i] == obj) {
            continue;
        }
        p = D_800FF548_KeyPaWay[i];
        r2 = KPW_BODY(p)->unk_68.enemy->unk_24;
        dist = func_800B1750(SQ(x - p->trans.x) + SQ(z - p->trans.z));
        lim = func_800B1750((r + r2) * (r + r2));
        if (dist < lim) {
            *out = lim - dist;
            return 1;
        }
    }
    return 0;
}
s32 func_800FB748_KeyPaWay(omObjData* obj, omObjData* other) {
    KPWPlayerWork* work = KPW_PLAYER(obj);
    KPWPlayerExt* ext = work->unk_E4;
    KPWBodyWork* ow = KPW_BODY(other);
    f32 dot;

    if (D_800FF580_KeyPaWay == 2) {
        return 1;
    }
    if (ow->unk_52 == 3 && work->unk_AE == 0) {
        if (func_8000A634(obj, other) == 1) {
            func_80017D1C(obj);
            D_800FF57C_KeyPaWay = obj;
            ext->unk_30 = 2;
            if (D_800FF580_KeyPaWay != 0) {
                func_80060540(0x15F, work->unk_58);
            }
        }
    } else if (ow->unk_52 == 7) {
        func_80060618(0x145, work->unk_58);
        func_80060F04(work->unk_58, 2, 2, 20);
        ext->unk_00 = 1;
        ext->unk_30 = 0;
        dot = func_8000A72C(func_800AEAC0(work->unk_3C), func_800AEFD0(work->unk_3C),
                            obj->trans.x - other->trans.x, obj->trans.z - other->trans.z);
        if (work->unk_50 & 0x20) {
            func_8000A534(obj, D_800B8988);
        }
        if (dot < 0.0f) {
            func_800184BC(obj, 30);
            if (work->unk_38 == 1000.0f) {
                work->unk_40 = -D_800B8980;
            } else {
                work->unk_40 = -D_800B8980;
                work->unk_38 = -D_800B8964 * 0.8f;
            }
            work->unk_3C = func_80029518(ow->unk_3C) + 180.0f;
        } else {
            func_800184BC(obj, 31);
            if (work->unk_38 == 1000.0f) {
                work->unk_40 = D_800B8980;
            } else {
                work->unk_40 = D_800B8980;
                work->unk_38 = -D_800B8964 * 0.8f;
            }
            work->unk_3C = ow->unk_3C;
        }
    }
    return 1;
}
void func_800FB9D4_KeyPaWay(omObjData* obj) {
    KPWStageWork* work;

    obj->model[0] = LoadFormFile(0x400001, 0x20699);
    omSetTra(obj, 0.0f, 0.0f, -850.0f);
    D_800F2AF8[D_800ED440++] = obj;
    work = obj->unk_50 = func_80023684(sizeof(KPWStageWork), 0x7918);
    func_8009B770(work, 0, sizeof(KPWStageWork));
    work->unk_04 = 1;
    work->unk_05 = 1;
    work->unk_08 = 0.8f;
    func_80009058(obj, 200.0f, 200.0f, -90.0f, -180.0f, 90.0f, 90.0f);
    obj->func_ptr = NULL;
}
void func_800FBAD4_KeyPaWay(omObjData* obj) {
    f32 temp;

    switch (D_800FF5A4_KeyPaWay) {
    case 0:
        D_800FF5A4_KeyPaWay = 1;
        break;
    case 1:
        if (func_80072718() == 0) {
            D_800FF5A4_KeyPaWay = 2;
            D_800FF500_KeyPaWay = 22;
        }
        break;
    case 3:
        if (D_800FF590_KeyPaWay->func_ptr == func_800F7AE0_KeyPaWay) {
            D_800FF502_KeyPaWay = 22;
            func_800FE744_KeyPaWay(22, 0.0f, 1100.0f, 2700.0f, 0.0f, 0.0f, -120.0f);
            D_800FF5A4_KeyPaWay = 4;
        }
        break;
    case 4:
        if (--D_800FF502_KeyPaWay == 0) {
            D_800FF5A4_KeyPaWay = 5;
        }
        break;
    case 5:
        D_800FF5A4_KeyPaWay = 6;
        GMesCreate(0);
        break;
    case 6:
        if (GMesStatAllGet() == 0) {
            temp = func_800B0CD8(1100.0f, 2100.0f);
            func_800FE82C_KeyPaWay(temp, func_800B1750(9162400.0f));
            D_800FF580_KeyPaWay = 1;
            D_800ED430 = 1;
            omDelObj(obj);
            GMesCreate(8, (u16)D_800FF532_KeyPaWay, 160, 32);
        }
        break;
    }
}
void func_800FBC98_KeyPaWay(omObjData* obj) {
    Vec3f pos;
    omObjData* p;
    KPWPlayerWork* w;
    KPWPlayerExt* ext;
    s32 i;
    s32 j;

    switch (D_800FF578_KeyPaWay) {
    case 9:
        func_800258EC(D_800FF590_KeyPaWay->model[1], 4, 4);
        D_800FF504_KeyPaWay = 20;
        D_800FF506_KeyPaWay = 0;
        PlaySound(0x31E);
        D_800FF578_KeyPaWay = 10;
        break;
    case 10:
        omSetRot(D_800FF590_KeyPaWay, D_800FF590_KeyPaWay->rot.x, D_800FF590_KeyPaWay->rot.y,
                 D_800FF590_KeyPaWay->rot.z - 4.5f);
        if (--D_800FF504_KeyPaWay == 0) {
            PlaySound(0x31F);
            D_800FF578_KeyPaWay = 11;
            D_800FF504_KeyPaWay = 10;
        } else if (D_800FF504_KeyPaWay == 5) {
            PlaySound(0x31C);
        }
        break;
    case 11:
        if (--D_800FF504_KeyPaWay == 0) {
            func_80039644(D_800FF53A_KeyPaWay, 1, 0);
            D_800FF578_KeyPaWay = 12;
            PlaySound(0x321);
            D_800FF504_KeyPaWay = 15;
        }
        break;
    case 12:
        if (--D_800FF504_KeyPaWay == 0) {
            D_800FF508_KeyPaWay = 0.0f;
            D_800FF578_KeyPaWay = 13;
            func_800258EC(D_800FF53C_KeyPaWay->model[4], 4, 0);
            func_800F6E04_KeyPaWay(1, 0.0f, 0.02f, 1.0f);
            func_800FE3DC_KeyPaWay(&pos);
            if (pos.z >= 2500.0f) {
                pos.z = 2500.0f;
            }
            func_800FE744_KeyPaWay(50, pos.x, pos.y, pos.z, 0.0f, 250.0f, -700.0f);
            func_800234B8(0, 128, 128, 120);
            func_800234B8(2, 255, 255, 240);
            func_80023504(2, 0.0f, 80.0f, -1000.0f);
            for (i = 0; i < 4; i++) {
                w = KPW_PLAYER(D_800FF594_KeyPaWay[i]);
                ext = w->unk_E4;
                ext->unk_26 = 0;
                ext->unk_2C = 1.0f;
                func_800258EC(D_800FF594_KeyPaWay[i]->model[9], 4, 0);
                if (D_800FF54C_KeyPaWay == D_800FF594_KeyPaWay[i]) {
                    func_80025798(D_800FF54C_KeyPaWay->model[9], 0.0f, 3.0f, D_800FF390_KeyPaWay * 200.0f + -850.0f);
                } else {
                    func_80025798(D_800FF594_KeyPaWay[i]->model[9], D_800FF594_KeyPaWay[i]->trans.x, 3.0f,
                                  D_800FF594_KeyPaWay[i]->trans.z);
                }
            }
            func_800258EC(D_800FF53C_KeyPaWay->model[5], 4, 0);
            func_80025798(D_800FF53C_KeyPaWay->model[5], 0.0f, 3.0f, -850.0f);
            PlaySound(0x318);
        }
        break;
    case 13:
        D_800FF384_KeyPaWay -= 8.0f;
        D_800FF388_KeyPaWay += 8.0f;
        func_80025798(D_800FF53C_KeyPaWay->model[1], D_800FF384_KeyPaWay, 0.0f, 0.0f);
        func_80025798(D_800FF53C_KeyPaWay->model[2], D_800FF388_KeyPaWay, 0.0f, 0.0f);
        omSetTra(D_800FF590_KeyPaWay, D_800FF590_KeyPaWay->trans.x + 8.0f, D_800FF590_KeyPaWay->trans.y,
                 D_800FF590_KeyPaWay->trans.z);
        for (i = 0; i < 4; i++) {
            func_80060F04(i, 2, 0, 2);
        }
        if (D_800FF388_KeyPaWay >= 400.0f) {
            PlaySound(0x31A);
            D_800FF578_KeyPaWay = 16;
            D_800FF504_KeyPaWay = 10;
            func_800185A4(D_800FF54C_KeyPaWay, 36);
            func_800FE744_KeyPaWay(D_800FF504_KeyPaWay, 0.0f, 250.0f, 500.0f, 0.0f, 250.0f, -700.0f);
            break;
        }
        if (D_800FF388_KeyPaWay >= 300.0f) {
            func_800601D4(40);
        }
        D_800FF38C_KeyPaWay += 0.02f;
        D_800FF564_KeyPaWay.y -= D_800FF508_KeyPaWay;
        D_800FF584_KeyPaWay.y -= D_800FF508_KeyPaWay;
        D_800FF508_KeyPaWay = (u8)(rand8() % 7) - 3;
        D_800FF564_KeyPaWay.y += D_800FF508_KeyPaWay;
        D_800FF584_KeyPaWay.y += D_800FF508_KeyPaWay;
        D_800FF390_KeyPaWay += 0.328f;
        func_80025830(D_800FF53C_KeyPaWay->model[5], 1.0f, 1.0f, D_800FF390_KeyPaWay);
        for (i = 0; i < 4; i++) {
            w = KPW_PLAYER(D_800FF594_KeyPaWay[i]);
            ext = w->unk_E4;
            ext->unk_2C += 0.3f;
            func_80025830(D_800FF594_KeyPaWay[i]->model[9], 1.0f, 1.0f, ext->unk_2C);
        }
        break;
    case 16:
        for (i = 0; i < 4; i++) {
            w = KPW_PLAYER(D_800FF594_KeyPaWay[i]);
            w->unk_3C -= 18.0f;
            func_80005A28(D_800FF594_KeyPaWay[i]);
        }
        if (--D_800FF504_KeyPaWay == 0) {
            for (i = 0; i < 4; i++) {
                func_800185A4(D_800FF594_KeyPaWay[i], 0);
                func_80017DB0(D_800FF594_KeyPaWay[i]);
            }
            D_800FF578_KeyPaWay = 17;
        }
        break;
    case 17:
        D_800FF578_KeyPaWay = 0;
        D_800FF564_KeyPaWay.y = D_800FF584_KeyPaWay.y = 250.0f;
        break;
    case 0:
        if (D_800FF526_KeyPaWay == 0) {
            GMesCreate(D_800FF524_KeyPaWay);
            D_800FF578_KeyPaWay = 1;
        } else {
            GMesCreate(2);
            D_800FF578_KeyPaWay = 18;
        }
        func_800790C0();
        break;
    case 1:
        if (GMesStatAllGet() & 2) {
            if (D_800FF514_KeyPaWay == 1) {
                D_800FF504_KeyPaWay = 165;
                func_80060128(0x36);
                for (i = 0; i < 4; i++) {
                    func_800185A4(D_800FF594_KeyPaWay[i], 13);
                }
            } else {
                D_800FF504_KeyPaWay = 150;
                func_80060128(0x34);
                for (i = 0; i < 4; i++) {
                    func_800184BC(D_800FF594_KeyPaWay[i], 14);
                    p = D_800FF594_KeyPaWay[i];
                    w = KPW_PLAYER(p);
                    w->unk_40 = 0.0f;
                    if (GwPlayer[i].coins < 5) {
                        GwPlayer[i].coins_mg -= GwPlayer[i].coins;
                    } else {
                        GwPlayer[i].coins_mg -= 5;
                    }
                }
            }
            D_800FF578_KeyPaWay = 2;
        }
        break;
    case 2:
        if (--D_800FF504_KeyPaWay == 0) {
            D_800FF578_KeyPaWay = 3;
            func_800726AC(0, 20);
        }
        break;
    case 3:
        if (func_80072718() == 0) {
            D_800FF3A4_KeyPaWay = 1;
        }
        break;
    case 14:
        for (i = 0; i < 4; i++) {
            p = D_800FF594_KeyPaWay[i];
            w = KPW_PLAYER(p);
            if (w->unk_38 != 1000.0f) {
                break;
            }
        }
        if (i == 4) {
            for (j = 0; j < 4; j++) {
                if (func_80017A60(D_800FF594_KeyPaWay[j]) != 2) {
                    break;
                }
            }
            if (j == 4) {
                D_800ED430 = 2;
                D_800FF578_KeyPaWay = 0;
            }
        }
        break;
    case 15:
        if (D_800FF57C_KeyPaWay != NULL) {
            p = D_800FF57C_KeyPaWay;
            func_8000A6F4(p);
        } else {
            p = D_800FF590_KeyPaWay;
        }
        D_800FF57C_KeyPaWay = NULL;
        func_800258EC(D_800FF590_KeyPaWay->model[0], 4, 4);
        func_800258EC(D_800FF590_KeyPaWay->model[1], 4, 4);
        func_800F8A28_KeyPaWay(-3.0f, p->trans.x, p->trans.y, p->trans.z);
        func_800F8A28_KeyPaWay(-3.0f, p->trans.x - 100.0f + (u8)(rand8() % 201), p->trans.y - 2.0f + (u8)(rand8() % 5),
                               p->trans.z - 2.0f + (u8)(rand8() % 5));
        func_800F8A28_KeyPaWay(-8.0f, p->trans.x - 100.0f + (u8)(rand8() % 201), p->trans.y - 2.0f + (u8)(rand8() % 5),
                               p->trans.z - 2.0f + (u8)(rand8() % 5));
        func_800F8A28_KeyPaWay(-8.0f, p->trans.x - 100.0f + (u8)(rand8() % 201), p->trans.y - 2.0f + (u8)(rand8() % 5),
                               p->trans.z - 2.0f + (u8)(rand8() % 5));
        func_800F8A28_KeyPaWay(-13.0f, p->trans.x - 100.0f + (u8)(rand8() % 201), p->trans.y - 2.0f + (u8)(rand8() % 5),
                               p->trans.z - 2.0f + (u8)(rand8() % 5));
        func_800F8A28_KeyPaWay(-13.0f, p->trans.x - 100.0f + (u8)(rand8() % 201), p->trans.y - 2.0f + (u8)(rand8() % 5),
                               p->trans.z - 2.0f + (u8)(rand8() % 5));
        D_800FF578_KeyPaWay = 14;
        for (i = 0; i < 4; i++) {
            p = D_800FF594_KeyPaWay[i];
            w = KPW_PLAYER(p);
            w->unk_50 |= 0x200;
            w->unk_AE = 0;
            w->unk_9C = 0;
            w->unk_50 &= ~7;
            omSetSca(D_800FF594_KeyPaWay[i], 1.0f, 1.0f, 1.0f);
        }
        break;
    case 18:
        if (GMesWait() != 1) {
            D_800FF578_KeyPaWay = 3;
            func_800726AC(0, 20);
        }
        break;
    }
}
void func_800FCC6C_KeyPaWay(void) {
    if ((D_800FF3A4_KeyPaWay != 0) || (D_800F5144 != 0)) {
        func_800FE320_KeyPaWay(0x83);
        func_800601D4(0x28);
    }
}

void func_800FCCB0_KeyPaWay(omObjData* obj) {
    omObjData* buf[6];
    KPWPlayerWork* work;
    KPWPlayerExt* ext;
    KPWKeyExt* kext;
    omObjData* target;
    f32 nearDist;
    f32 range;
    f32 speed;
    f32 v;
    f32 a1;
    f32 a2;
    f32 d;
    f32 a;
    u16 port;
    u16 row;
    u16 col;
    u16 n;
    u16 diff;

    row = rand8() % 3;
    work = KPW_PLAYER(obj);
    ext = work->unk_E4;
    port = work->unk_56;
    if (D_800FF57C_KeyPaWay == NULL) {
        ext->unk_30 = 0;
    } else if (D_800FF57C_KeyPaWay != obj) {
        ext->unk_30 = 1;
    }
    diff = GwPlayer[work->unk_58].cpu_difficulty;
    switch (diff) {
    case 0:
        speed = (u8)(rand8() % 11) + 35.0f;
        nearDist = 200.0f;
        range = 340.0f;
        break;
    case 1:
        speed = (u8)(rand8() % 11) + 40.0f;
        nearDist = 240.0f;
        range = 310.0f;
        break;
    case 2:
        speed = (u8)(rand8() % 11) + 45.0f;
        nearDist = range = 280.0f;
        break;
    case 3:
        speed = (u8)(rand8() % 11) + 50.0f;
        nearDist = 320.0f;
        range = 250.0f;
        break;
    }
    switch (ext->unk_30) {
    case 0:
        kext = KPW_BODY(D_800FF590_KeyPaWay)->unk_68.key;
        v = func_800B1750(SQ(kext->unk_18) + SQ(kext->unk_1C)) * 6.0f;
        a1 = func_800B0CD8(obj->trans.z - D_800FF590_KeyPaWay->trans.z, obj->trans.x - D_800FF590_KeyPaWay->trans.x);
        a2 = func_800B0CD8(kext->unk_14, kext->unk_0C);
        d = func_800B1750(SQ(D_800FF590_KeyPaWay->trans.x - obj->trans.x) + SQ(D_800FF590_KeyPaWay->trans.z - obj->trans.z));
        if (v / 2.0f < d && d < v && kext->unk_10 < 0.0f) {
            if (D_800FF590_KeyPaWay->trans.y > 150.0f && D_800FF590_KeyPaWay->trans.y < 300.0f &&
                func_800FE1F0_KeyPaWay(a1, a2) < 30.0f && diff >= 2) {
                ContBtnTrg[port] |= 0x8000;
            }
        }
        if (d < nearDist) {
            a = func_800B0CD8(D_800FF590_KeyPaWay->trans.x - obj->trans.x, D_800FF590_KeyPaWay->trans.z - obj->trans.z);
            ContStkX[port] = func_800AEAC0(a) * 80.0f;
            ContStkY[port] = -func_800AEFD0(a) * 80.0f;
        } else {
            a = func_800FDA7C_KeyPaWay(obj, D_800FF590_KeyPaWay->trans.x, D_800FF590_KeyPaWay->trans.z, 50.0f, 250.0f);
            ContStkX[port] = func_800AEAC0(a) * speed;
            ContStkY[port] = -func_800AEFD0(a) * speed;
        }
        break;
    case 1:
        func_800B1750(SQ(D_800FF57C_KeyPaWay->trans.x - obj->trans.x) + SQ(D_800FF57C_KeyPaWay->trans.z - obj->trans.z));
        if (obj->trans.x < -200.0f) {
            col = 0;
        } else if (obj->trans.x > 200.0f) {
            col = 2;
        } else {
            col = 1;
        }
        if (col == ext->unk_16) {
            if (obj->trans.z < 500.0f) {
                if (obj->trans.z > -500.0f) {
                    row = 1;
                } else {
                    row = 2;
                }
            } else {
                row = 0;
            }
            ext->unk_16 = col;
            ext->unk_1C = D_800FF310_KeyPaWay[col][ext->unk_18][0];
        }
        if (row == ext->unk_18) {
            if (row == 2) {
                if (D_800FF57C_KeyPaWay->trans.z > 0.0f) {
                    ext->unk_18 = 0;
                    ext->unk_20 = D_800FF310_KeyPaWay[ext->unk_16][0][1];
                } else {
                    ext->unk_18 = 1;
                    ext->unk_20 = D_800FF310_KeyPaWay[ext->unk_16][1][1];
                }
            } else {
                ext->unk_18 = row + 1;
                ext->unk_20 = D_800FF310_KeyPaWay[ext->unk_16][ext->unk_18][1];
            }
        }
        a = func_800FDA7C_KeyPaWay(obj, ext->unk_1C, ext->unk_20, 45.0f, range);
        ContStkX[port] = func_800AEAC0(a) * speed;
        ContStkY[port] = -func_800AEFD0(a) * speed;
        break;
    case 2:
        d = func_800B1750(SQ(0.0f - obj->trans.x) + SQ(-850.0f - obj->trans.z));
        a1 = func_800FE1F0_KeyPaWay(work->unk_3C, func_800B0CD8(0.0f - obj->trans.x, -850.0f - obj->trans.z));
        if ((d < 250.0f && a1 <= 10.0f) || ext->unk_28 == 1) {
            ext->unk_28 = 1;
            a = func_800B0CD8(0.0f - obj->trans.x, -850.0f - obj->trans.z);
            ContStkX[port] = func_800AEAC0(a) * 80.0f;
            ContStkY[port] = -func_800AEFD0(a) * 80.0f;
            ContBtn[port] |= 0x8000;
            ContBtnTrg[port] |= 0x8000;
            break;
        }
        ext->unk_28 = 0;
        a = func_800FDA7C_KeyPaWay(obj, 0.0f, -850.0f, 60.0f, 300.0f);
        n = func_800FDE64_KeyPaWay(obj->trans.x, obj->trans.z, range, buf);
        if ((D_800FF522_KeyPaWay > 16 && n != 0 && D_800FF520_KeyPaWay < 250.0f && d >= 400.0f) ||
            (D_800FF520_KeyPaWay <= 100.0f && n != 0 && d >= 400.0f)) {
            target = func_800FE06C_KeyPaWay(obj);
            if (func_800FDE64_KeyPaWay(target->trans.x, target->trans.z, 250.0f, buf) >= 2) {
                target = func_800FDFAC_KeyPaWay(obj);
            }
            if (target == NULL) {
                if (func_800FDE64_KeyPaWay(D_800FF560_KeyPaWay->trans.x, D_800FF560_KeyPaWay->trans.z, 350.0f, buf) < 2) {
                    target = D_800FF560_KeyPaWay;
                }
                if (target == NULL) {
                    a = func_800FDA7C_KeyPaWay(obj, 0.0f, -850.0f, 35.0f, range);
                    ContStkX[port] = func_800AEAC0(a) * speed;
                    ContStkY[port] = -func_800AEFD0(a) * speed;
                    break;
                }
            }
            a = func_800B0CD8(target->trans.x - obj->trans.x, target->trans.z - obj->trans.z);
            ContStkX[port] = func_800AEAC0(a) * 20.0f;
            ContStkY[port] = -func_800AEFD0(a) * 20.0f;
            d = func_800B1750(SQ(target->trans.x - obj->trans.x) + SQ(target->trans.z - obj->trans.z));
            if (d >= 300.0f) {
                if (d < 500.0f && work->unk_38 != 1000.0f) {
                    ext->unk_30 = 4;
                    ext->unk_34 = a;
                    ext->unk_38 = d;
                    work->unk_BC = d / 100.0f + 1.0f;
                    if (work->unk_BC > 3.6f) {
                        work->unk_BC = 3.6f;
                    }
                } else {
                    ext->unk_30 = 3;
                    ext->unk_32 = 4;
                    ext->unk_34 = a;
                    work->unk_BC = d / 500.0f;
                    if (work->unk_BC > 3.6f) {
                        work->unk_BC = 3.6f;
                    }
                    if (work->unk_38 != 1000.0f) {
                        work->unk_BC = work->unk_BC / 2.0f;
                    }
                }
            }
        } else {
            ContStkX[port] = func_800AEAC0(a) * speed;
            ContStkY[port] = -func_800AEFD0(a) * speed;
        }
        break;
    case 3:
        if (work->unk_3C != ext->unk_34) {
            work->unk_3C = ext->unk_34;
        } else if (work->unk_38 == 1000.0f) {
            ext->unk_32 = 2;
            ContBtnTrg[port] |= 0x8000;
            ContBtn[port] |= 0x8000;
        } else {
            ext->unk_30 = 5;
        }
        break;
    case 4:
        if (work->unk_3C != ext->unk_34) {
            work->unk_3C = ext->unk_34;
        } else {
            work->unk_BC = ext->unk_38 / 400.0f * 0.5f + 0.5f;
            ContBtnTrg[port] |= 0x4000;
        }
        break;
    case 5:
        if (--ext->unk_32 == 0) {
            ContBtnTrg[port] |= 0x4000;
        }
        break;
    }
}
f32 func_800FDA7C_KeyPaWay(omObjData* obj, f32 x, f32 z, f32 angle, f32 range) {
    f32 dist[8];
    f32 ang[8];
    omObjData* p;
    KPWBodyWork* bw;
    KPWPlayerWork* work;
    f32 nx;
    f32 nz;
    f32 a;
    u16 n;
    s32 i;

    a = func_800B0CD8(x - obj->trans.x, z - obj->trans.z);
    for (i = 0; i < 5; i++) {
        p = D_800FF548_KeyPaWay[i];
        bw = KPW_BODY(p);
        nx = func_800AEAC0(bw->unk_3C) * bw->unk_40 * 4.0f + p->trans.x;
        nz = func_800AEFD0(bw->unk_3C) * bw->unk_40 * 4.0f + p->trans.z;
        dist[i] = func_800B1750(SQ(nx - obj->trans.x) + SQ(nz - obj->trans.z));
        ang[i] = func_800B0CD8(nx - obj->trans.x, nz - obj->trans.z);
    }
    n = 0;
    for (i = 0; i < 4; i++) {
        if (D_800FF594_KeyPaWay[i] == obj) {
            continue;
        }
        p = D_800FF594_KeyPaWay[i];
        nx = p->trans.x;
        nz = p->trans.z;
        dist[n + 5] = func_800B1750(SQ(nx - obj->trans.x) + SQ(nz - obj->trans.z));
        ang[n + 5] = func_800B0CD8(nx - obj->trans.x, nz - obj->trans.z);
        n++;
    }
    D_800FF51E_KeyPaWay = 0;
    D_800FF522_KeyPaWay = 0;
    work = KPW_PLAYER(obj);
    n = 0;
    while (TRUE) {
        i = 0;
        do {
            if (func_800FE1F0_KeyPaWay(ang[i], a) <= angle && dist[i] <= range) {
                break;
            }
            i++;
        } while (i < 8);
        if (i == 8) {
            nx = func_800AEAC0(a) * work->unk_40 + obj->trans.x;
            nz = func_800AEFD0(a) * work->unk_40 + obj->trans.z;
            if (work->unk_48 + -700.0f <= nx && nx <= 700.0f - work->unk_48 && work->unk_48 + -1000.0f <= nz &&
                nz <= 1000.0f - work->unk_48) {
                break;
            }
        }
        D_800FF522_KeyPaWay++;
        if (++n == 36) {
            D_800FF51E_KeyPaWay = 1;
            break;
        }
        a += 10.0f;
        if (a > 180.0f) {
            a -= 360.0f;
        }
    }
    if (a < 0.0f) {
        a += 360.0f;
    }
    if (a >= 360.0f) {
        a -= 360.0f;
    }
    return a;
}
u16 func_800FDE64_KeyPaWay(f32 x, f32 z, f32 range, omObjData* out[]) {
    omObjData* p;
    f32 dx;
    f32 dz;
    f32 dist;
    f32 nearest;
    u16 count;
    s32 i;

    count = 0;
    nearest = 10000.0f;
    for (i = 0; i < 5; i++) {
        p = D_800FF548_KeyPaWay[i];
        dx = p->trans.x - x;
        dx *= dx;
        dz = p->trans.z - z;
        dist = func_800B1750(dx + dz * dz);
        if (dist < nearest) {
            nearest = dist;
        }
        if (dist <= range) {
            out[count++] = p;
        }
    }
    D_800FF520_KeyPaWay = nearest;
    return count;
}
omObjData* func_800FDFAC_KeyPaWay(omObjData* arg0) {
    omObjData* sp10[6]; //likely some unknown struct
    omObjData* temp_s0;
    u16 var_a0;
    s32 i;
    omObjData* temp_s5 = arg0;
    u16 var_s3 = 15;
    omObjData* var_s4 = NULL;
    KPWPlayerWork* temp_s2;

    for (i = 0; i < 4; i++) {
        temp_s0 = D_800FF594_KeyPaWay[i];
        if (temp_s0 == temp_s5) {
            continue;
        } else {
            temp_s2 = temp_s0->unk_50;
            var_a0 = func_800FDE64_KeyPaWay(temp_s0->trans.x, temp_s0->trans.z, 700.0f, sp10);
            if ((var_a0 < var_s3) && (temp_s2->unk_AE == 0)) {
                var_s3 = var_a0;
                var_s4 = temp_s0;
            }
        }
    }
    return var_s4;
}

omObjData* func_800FE06C_KeyPaWay(omObjData* arg0) {
    omObjData* temp_s0;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f12;
    f32 var_f20 = 100000.0f;
    s32 i;

    for (i = 0; i < 4; i++) {
        temp_s0 = D_800FF594_KeyPaWay[i];
        if (temp_s0 != arg0) {
            temp_f0 = 0.0f - temp_s0->trans.x;
            temp_f0 *= temp_f0;
            temp_f12 = -850.0f - temp_s0->trans.z;
            temp_f0_2 = func_800B1750((temp_f0) + SQ(temp_f12));
            if (temp_f0_2 < var_f20) {
                var_f20 = temp_f0_2;
            }
        }        
    }
    return temp_s0;
}

s32 func_800FE134_KeyPaWay(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f2;
    f32 temp3 = 0.0f;
    f32 temp = 200.0f;
    f32 temp_f0 = -850.0f;
    f32 temp2 = 115.0f;
    
    temp_f2 = temp3 - arg0;
    temp_f2 *= temp_f2;
    temp_f0 = temp_f0 - arg2;
    temp_f22 = func_800B1750(temp_f2 + SQ(temp_f0));
    temp_f20 = arg3 + temp2;
    
    if ((temp_f22 <= func_800B1750(temp_f20 * temp_f20)) && (arg1 <= temp)) {
        return 1;
    } else {
        return 0;
    }
}

f32 func_800FE1F0_KeyPaWay(f32 arg0, f32 arg1) {
    f32 var_f12 = fabsf(arg0 - arg1);

    if (var_f12 > 180.0f) {
        var_f12 = 360.0f - var_f12;
    }

    return var_f12;
}

/* .data */
f32 D_800FF270_KeyPaWay[5][2] = { { -600.0f, -100.0f }, { -300.0f, -350.0f }, { 0.0f, -600.0f }, { 300.0f, -350.0f }, { 600.0f, -100.0f } };
Vec3f D_800FF298_KeyPaWay[4] = { { 0.0f, 0.0f, 900.0f }, { 300.0f, 0.0f, 900.0f }, { 450.0f, 0.0f, 900.0f }, { 600.0f, 0.0f, 900.0f } };
Vec3f D_800FF2C8_KeyPaWay[4] = { { 0.0f, 0.0f, 0.0f }, { -200.0f, 0.0f, 900.0f }, { 0.0f, 0.0f, 900.0f }, { 200.0f, 0.0f, 900.0f } };
s32 D_800FF2F8_KeyPaWay[6] = { 0x7, 0x8, 0x9, 0xa, 0xb, 0xc };
f32 D_800FF310_KeyPaWay[3][3][2] = { { { -450.0f, 750.0f }, { -450.0f, 0.0f }, { -450.0f, -850.0f } }, { { 0.0f, 750.0f }, { 0.0f, 0.0f }, { 0.0f, -750.0f } }, { { 450.0f, 750.0f }, { 450.0f, 0.0f }, { 450.0f, -850.0f } } };
f32 D_800FF358_KeyPaWay = 0.0f;
f32 D_800FF35C_KeyPaWay = 0.0f;
f32 D_800FF360_KeyPaWay = 0.0f;
u16 D_800FF364_KeyPaWay = 1;
u16 D_800FF366_KeyPaWay = 0; /* unreferenced */
f32 D_800FF368_KeyPaWay = 0.0f;
f32 D_800FF36C_KeyPaWay = 0.0f;
u16 D_800FF370_KeyPaWay[2] = { 30, 30 };
s32 D_800FF374_KeyPaWay = 1;
u16 D_800FF378_KeyPaWay = 0;
u16 D_800FF37A_KeyPaWay = 0;
omObjData* D_800FF37C_KeyPaWay = NULL;
u16 D_800FF380_KeyPaWay = 0;
u16 D_800FF382_KeyPaWay = 1;
f32 D_800FF384_KeyPaWay = 0.0f;
f32 D_800FF388_KeyPaWay = 0.0f;
f32 D_800FF38C_KeyPaWay = 0.0f;
f32 D_800FF390_KeyPaWay = 1.0f;
f32 D_800FF394_KeyPaWay[4] = { 0.0f, 0.0f, 0.0f, 0.0f }; /* unreferenced */
u16 D_800FF3A4_KeyPaWay = 0;
u16 D_800FF3A6_KeyPaWay = 0; /* unreferenced */
u16 D_800FF3A8_KeyPaWay = 0; /* unreferenced */
u16 D_800FF3AA_KeyPaWay = 0; /* unreferenced */
u16 D_800FF3AC_KeyPaWay = 0; /* unreferenced */
u16 D_800FF3AE_KeyPaWay = 0; /* unreferenced */
