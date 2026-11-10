#include "BowlOver.h"

#define PLAYER_WORK(obj) ((BowlPlayerWork*)(obj)->unk_50)
#define PIN_IDX(obj) ((obj)->work[3])

/* ---------------------------------------------------------------------------------------------
   .data
   --------------------------------------------------------------------------------------------- */

f32 D_800FD3E0_BowlOver[3][16][2] = {
    {
        { -66.5f, -940.0f }, { 69.8f, -940.0f }, { -14.1f, -709.0f }, { 129.5f, -737.0f },
        { 2.45f, -588.3f }, { 154.6f, -598.0f }, { 9.25f, -481.0f }, { 160.0f, -481.0f },
        { 2.82f, -392.0f }, { 154.2f, -371.0f }, { -13.8f, -260.5f }, { 130.8f, -225.0f },
        { -49.8f, -40.0f }, { 91.5f, -40.0f }, { 0.0f, 0.0f }, { 0.0f, 0.0f },
    },
    {
        { -69.7f, -940.0f }, { 66.78f, -940.0f }, { -129.5f, -737.0f }, { 14.2f, -708.6f },
        { -154.4f, -597.0f }, { -2.3f, -588.0f }, { -160.0f, -481.0f }, { -8.863f, -481.0f },
        { -154.0f, -370.0f }, { -2.63f, -391.3f }, { -129.9f, -224.5f }, { 14.015f, -260.5f },
        { -91.5f, -40.0f }, { 50.0f, -40.0f }, { 0.0f, 0.0f }, { 0.0f, 0.0f },
    },
    {
        { -66.2f, -940.0f }, { 70.4f, -940.0f }, { 8.9f, -724.0f }, { 151.4f, -750.5f },
        { 16.17f, -631.0f }, { 160.5f, -620.0f }, { 0.516f, -532.1f }, { 132.76f, -480.5f },
        { -104.8f, -434.6f }, { 17.5f, -386.0f }, { -160.4f, -329.4f }, { -17.9f, -291.5f },
        { -150.3f, -181.0f }, { -10.08f, -209.7f }, { -104.8f, -40.0f }, { 36.9f, -40.0f },
    },
};
u16 D_800FD560_BowlOver[2] = { 0, 0 };
Vec3f D_800FD564_BowlOver[6] = {
    { 0.0f, 0.0f, -4750.0f },    { -100.0f, 0.0f, -4950.0f }, { 100.0f, 0.0f, -4950.0f },
    { -200.0f, 0.0f, -5150.0f }, { 0.0f, 0.0f, -5150.0f },    { 200.0f, 0.0f, -5150.0f },
};
s16 D_800FD5AC_BowlOver[8] = { 0, 0, 0, 0, (s16)0xC396, 0, 0, 0 };
f32 D_800FD5BC_BowlOver[6] = { -5200.0f, 300.0f, 0.0f, -5200.0f, 0.0f, 0.0f };
f32 D_800FD5D4_BowlOver = -4700.0f;
BowlHead D_800FD5D8_BowlOver[6] = {
    { 1, 9, "atama_2", "c025_000-kaodamy" },
    { 2, 10, "Luigi1-atama_2", "c026_000-kaodamy" },
    { 3, 12, "c003_000-head_1", "c028_000-kaodamy" },
    { 4, 13, "Luigi1-atama_1", "c029_000-kaodamy" },
    { 5, 14, "c005_000-bmerge1", "c030_000-kaodamy" },
    { 6, 11, "C002_000b-bmerge10_1", "c027_000-kaodamy" },
};

/* ---------------------------------------------------------------------------------------------
   Code
   --------------------------------------------------------------------------------------------- */

void func_800FA4D0_BowlOver(omObjData* obj) {
    s16 i;

    func_80025F10(obj->model[0], D_800FDC58_BowlOver);
    func_80025F10(obj->model[1], D_800FDC58_BowlOver);
    for (i = 0; i < 16; i++) {
        func_800257E4(obj->model[3], 0.0f, CRotM[0].y, 0.0f);
        func_800257E4(obj->model[i + 19], 0.0f, CRotM[1].y, 0.0f);
    }
}

// register allocation
#ifdef NON_MATCHING
void func_800FA5A0_BowlOver(omObjData* obj) {
    BowlFloorWork* w;
    s16 i;

    obj->model[0] = func_800174C0(D_800FD3D4_BowlOver[D_800FD3D0_BowlOver[0]], 0x99);
    obj->model[1] = func_800174C0(0x230000, 0x99);
    obj->model[2] = func_800174C0(0x230001, 0x99);
    obj->model[3] = func_800174C0(0x230002, 0x99);
    for (i = 0; i < 31; i++) {
        obj->model[i + 4] = func_80023FC8(obj->model[3]);
    }
    for (i = 0; i < 16; i++) {
        func_80025798(obj->model[i + 3], D_800FD3E0_BowlOver[D_800FD3D0_BowlOver[0]][i][0] * 5.0f, 5.0f,
                      D_800FD3E0_BowlOver[D_800FD3D0_BowlOver[0]][i][1] * 5.0f);
        func_80025F10(obj->model[i + 3], 1);
        func_80025798(obj->model[i + 19], D_800FD3E0_BowlOver[D_800FD3D0_BowlOver[0]][i][0] * 5.0f, 5.0f,
                      D_800FD3E0_BowlOver[D_800FD3D0_BowlOver[0]][i][1] * 5.0f);
        func_80025F10(obj->model[i + 19], 2);
    }
    if (D_800FD3D0_BowlOver[0] != 2) {
        for (i = 0; i < 2; i++) {
            func_80025F10(obj->model[i + 17], 0);
            func_80025F10(obj->model[i + 33], 0);
        }
    }
    func_80025F10(obj->model[2], 2);
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80025798(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80025798(obj->model[2], obj->trans.x, obj->trans.y, obj->trans.z);
    obj->unk_50 = w = func_80023684(sizeof(BowlFloorWork), 0x7918);
    func_8009B770(w, 0, sizeof(BowlFloorWork));
    w->unk_04 = 1;
    w->unk_05 = 0;
    func_80009028(obj, 0, -250.0f, -5000.0f, 250.0f, 500.0f);
    obj->func_ptr = func_800FA4D0_BowlOver;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_11_BowlOver/142EA0", func_800FA5A0_BowlOver);
#endif

void func_800FA8D0_BowlOver(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 6; i++) {
        D_800FD880_BowlOver[i].unk_0E = 0;
        D_800FD880_BowlOver[i].unk_0F = 0;
        D_800FD880_BowlOver[i].unk_0C = 0;
        D_800FD880_BowlOver[i].unk_00 = 30.0f;
        D_800FD880_BowlOver[i].unk_04 = 0.0f;
        D_800FD880_BowlOver[i].unk_08 = 90.0f;
        D_800FD880_BowlOver[i].unk_10 = 0;
        D_800FD880_BowlOver[i].unk_11 = 0;
        D_800FD880_BowlOver[i].unk_14 = 0.0f;
        for (j = 0; j < 5; j++) {
            D_800FD880_BowlOver[i].unk_18[j] = 0.0f;
        }
    }
    for (i = 0; i < 6; i++) {
        D_800FDC60_BowlOver[i].unk_00 = 0.0f;
        D_800FDC60_BowlOver[i].unk_08 = 0.0f;
        D_800FDC60_BowlOver[i].unk_14 = 0;
        D_800FDC60_BowlOver[i].unk_16 = 0;
        D_800FDC60_BowlOver[i].unk_18 = 0;
        D_800FDC60_BowlOver[i].unk_1A = 0;
        D_800FDC60_BowlOver[i].unk_20 = 0;
        D_800FDC60_BowlOver[i].unk_04 = 0.0f;
        D_800FDC60_BowlOver[i].unk_1C = -1;
        D_800FDC60_BowlOver[i].unk_04 = 0.0f;
        for (j = 0; j < 8; j++) {
            D_800FDC60_BowlOver[i].unk_21[j] = 0;
            D_800FDC60_BowlOver[i].unk_29[j] = 0;
        }
        D_800FDC60_BowlOver[i].unk_31 = 0;
        D_800FDC60_BowlOver[i].unk_35 = 0;
        D_800FDC60_BowlOver[i].unk_0C = 0.0f;
        D_800FDC60_BowlOver[i].unk_10 = 0.0f;
        D_800FDC60_BowlOver[i].unk_33 = 0;
        D_800FDC60_BowlOver[i].unk_34 = -50;
    }
}

// decomp-permuter
void func_800FAAF8_BowlOver(u8 mdl, f32 x, f32 y, f32 z)
{
  f32 s;
  ;
  s = 0.4f - (y * 0.0015f);
  func_80025830(mdl, s * 2.5, 1.0f, (0.4f - (y * 0.0015f)) * 2.5);
  func_80025798(mdl, x, 5.0f, z);
}

// float register allocation (masked 0, raw 10): x/vz swap f6/f8; tried declaration order, branch order (M1c)
#ifdef NON_MATCHING
void func_800FABA0_BowlOver(omObjData* obj, f32* dx, f32* dz) {
    f32 vx;
    f32 vz;
    f32 x;
    f32 z;
    f32 lim;

    vx = *dx;
    vz = *dz;
    x = vx + obj->trans.x;
    z = vz + obj->trans.z;
    if (z < D_800FD5BC_BowlOver[0]) {
        vz = 0.0f;
        obj->trans.z = D_800FD5BC_BowlOver[0];
    } else if (D_800FD5D4_BowlOver - 50.0f < z) {
        vz = 0.0f;
        obj->trans.z = D_800FD5D4_BowlOver - 50.0f;
    }
    z = vz + obj->trans.z;
    lim = z - D_800FD5D4_BowlOver;
    if (x < 0.0f) {
        lim = lim / 2.0f;
        if (x <= lim) {
            vx = 0.0f;
            obj->trans.x = lim;
        }
    } else {
        lim = -lim / 2.0f;
        if (lim <= x) {
            vx = 0.0f;
            obj->trans.x = lim;
        }
    }
    *dx = vx;
    *dz = vz;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_11_BowlOver/142EA0", func_800FABA0_BowlOver);
#endif

void func_800FAC94_BowlOver(omObjData* obj, f32 dx, f32 dz) {
    omObjData* other;
    f32 ex;
    f32 ez;
    f32 d;
    f32 push;
    s16 i;

    func_800FABA0_BowlOver(obj, &dx, &dz);
    for (i = 0; i < 6; i++) {
        other = D_800FD860_BowlOver[i];
        if (obj == other) {
            continue;
        }
        ex = (obj->trans.x + dx) - other->trans.x;
        ez = (obj->trans.z + dz) - other->trans.z;
        d = sqrtf(ex * ex + ez * ez);
        if (d < 90.0f) {
            if (d != 0.0f) {
                push = 90.0f - d;
                obj->trans.x = (dx - (dx - (ex / d) * push)) + obj->trans.x;
                obj->trans.z = (dz - (dz - (ez / d) * push)) + obj->trans.z;
            } else {
                dx = 0.0f;
                dz = 0.0f;
            }
        } else {
            obj->trans.x += dx;
            obj->trans.z += dz;
        }
    }
}

// register allocation and float temporaries
#ifdef NON_MATCHING
void func_800FAE2C_BowlOver(omObjData* obj) {
    BowlPin* pin;
    BowlPin* hit;
    omObjData* other;
    Vec3f top;
    Vec3f d;
    f32 a;
    f32 dir;
    f32 r;
    s16 i;
    s16 snd;

    pin = &D_800FD880_BowlOver[PIN_IDX(obj)];
    if (pin->unk_0E != 1) {
        return;
    }
    dir = 360.0f - pin->unk_04;
    a = pin->unk_00 * 0.017453289f;
    top.y = cosf(a) * 130.0f;
    r = sinf(a) * 130.0f;
    a = dir * 0.017453289f;
    top.x = sinf(a) * r;
    top.z = cosf(a) * r;
    top.x += obj->trans.x;
    top.y += obj->trans.y;
    top.z += obj->trans.z;
    for (i = 0; i < 6; i++) {
        if (PIN_IDX(obj) == i) {
            continue;
        }
        other = D_800FD860_BowlOver[i];
        hit = &D_800FD880_BowlOver[PIN_IDX(other)];
        if (hit->unk_0E == 1) {
            continue;
        }
        d.x = other->trans.x - top.x;
        d.y = D_800FD860_BowlOver[i]->trans.y - top.y;
        d.z = D_800FD860_BowlOver[i]->trans.z - top.z;
        if (sqrtf(d.x * d.x + d.y * d.y + d.z * d.z) < 75.0f) {
            hit->unk_04 = pin->unk_04;
            hit->unk_00 = 40.0f;
            D_800FD860_BowlOver[i]->trans.y += 30.0;
            func_80025F10(D_800FD860_BowlOver[i]->model[1], 0);
            hit->unk_0E = 1;
            hit->unk_0F = 0;
            hit->unk_08 = 90.0f;
            pin->unk_08 = 90.0f;
            snd = 0x25D;
            if (D_800FD560_BowlOver[0] != 0) {
                snd = 0x25E;
                if (D_800FD560_BowlOver[0] != 1) {
                    snd = 0x25F;
                }
            }
            PlaySound(snd);
            D_800FD560_BowlOver[0]++;
            if (D_800FD860_BowlOver[0] == obj) {
                func_80060F04(D_800FDC5A_BowlOver[1], 0x14, 0, 0x14);
            }
            if (D_800FD860_BowlOver[1] == obj) {
                func_80060F04(D_800FDC5A_BowlOver[2], 0x14, 0, 0x14);
            }
            if (D_800FD860_BowlOver[2] == obj) {
                func_80060F04(D_800FDC5A_BowlOver[3], 0x14, 0, 0x14);
            }
            func_80025CA8(obj->model[5], 0.0f);
            func_80025798(obj->model[5], obj->trans.x, obj->trans.y, obj->trans.z);
            func_80025830(obj->model[5], 5.0f, 5.0f, 5.0f);
            func_800258EC(obj->model[5], 4, 0);
            func_80025CA8(obj->model[6], 0.0f);
            func_80025798(obj->model[6], obj->trans.x, obj->trans.y, obj->trans.z);
            func_800258EC(obj->model[6], 4, 0);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_11_BowlOver/142EA0", func_800FAE2C_BowlOver);
#endif

// register allocation and float temporaries
#ifdef NON_MATCHING
void func_800FB230_BowlOver(omObjData* obj) {
    BowlPin* pin;
    unk_ovl_2D_struct* mdl;
    Vec3f pos;
    Vec3f axis;
    f32 dx;
    f32 dz;
    f32 a;
    s16 snd;

    pin = &D_800FD880_BowlOver[PIN_IDX(obj)];
    if (D_800ED430 != 1) {
        return;
    }
    mdl = &D_800F2B7C[obj->model[0]];
    if (pin->unk_0E == 0) {
        if (obj->trans.y <= 86.0f) {
            dx = D_800FD878_BowlOver->trans.x - obj->trans.x;
            dz = D_800FD878_BowlOver->trans.z - obj->trans.z;
            if (sqrtf(dx * dx + dz * dz) < 88.0f) {
                pin->unk_04 = func_800B0CD8(dx, dz);
                pin->unk_00 = 30.0f;
                obj->trans.y += 30.0;
                func_80025F10(obj->model[1], 0);
                pin->unk_0E = 1;
                pin->unk_0F = 0;
                pin->unk_08 = 90.0f;
                if (D_800FD560_BowlOver[0] != 0) {
                    snd = 0x25E;
                    if (D_800FD560_BowlOver[0] != 1) {
                        snd = 0x25F;
                    }
                } else {
                    snd = 0x25D;
                }
                PlaySound(snd);
                D_800FD560_BowlOver[0]++;
                if (D_800FD860_BowlOver[0] == obj) {
                    func_80060F04(D_800FDC5A_BowlOver[1], 0x14, 0, 0x14);
                }
                if (D_800FD860_BowlOver[1] == obj) {
                    func_80060F04(D_800FDC5A_BowlOver[2], 0x14, 0, 0x14);
                }
                if (D_800FD860_BowlOver[2] == obj) {
                    func_80060F04(D_800FDC5A_BowlOver[3], 0x14, 0, 0x14);
                }
                func_80025CA8(obj->model[3], 0.0f);
                func_80025798(obj->model[3], obj->trans.x, obj->trans.y, obj->trans.z);
                func_80025830(obj->model[3], 5.0f, 5.0f, 5.0f);
                func_800258EC(obj->model[3], 4, 0);
                func_80025CA8(obj->model[4], 0.0f);
                func_80025798(obj->model[4], obj->trans.x, obj->trans.y, obj->trans.z);
                func_800258EC(obj->model[4], 4, 0);
            }
        }
    } else {
        a = pin->unk_04 + obj->rot.y;
        pos.x = 0.0f;
        pos.y = 30.0f;
        pos.z = 0.0f;
        a = (360.0f - (f32)(a - (s32)(a / 360.0f) * 360.0)) * 0.017453289f;
        axis.x = cosf(a);
        axis.y = 0.0f;
        axis.z = -sinf(a);
        if (pin->unk_00 < pin->unk_08) {
            pin->unk_00 += 8.0f;
        } else {
            pin->unk_00 = D_800FD880_BowlOver[PIN_IDX(obj)].unk_08;
            pin->unk_0F = 1;
        }
        func_800FA1D8_BowlOver(&pos, &axis, pin->unk_00, mdl->unk7C);
        func_800FAE2C_BowlOver(obj);
    }
    func_80017B4C(obj->model[3]);
    func_80017B4C(obj->model[4]);
    func_80017B4C(obj->model[5]);
    func_80017B4C(obj->model[6]);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_11_BowlOver/142EA0", func_800FB230_BowlOver);
#endif

// register allocation and switch layout
#ifdef NON_MATCHING
void func_800FB650_BowlOver(omObjData* obj, BowlJump* jump, u8* sx, u8* sy) {
    BowlPlayerWork* w;
    f32 dx;
    f32 dz;
    f32 dist;
    f32 d;
    u32 r;
    s32 near;
    s32 range;

    w = PLAYER_WORK(obj);
    range = 0;
    if (jump->unk_18 != 1) {
        return;
    }
    dx = D_800FD878_BowlOver->trans.x - obj->trans.x;
    dz = D_800FD878_BowlOver->trans.z - obj->trans.z;
    dist = dx * dx + dz * dz;
    near = guRandom() & 3;
    switch (GwPlayer[w->unk_58].cpu_difficulty) {
        case 1:
            range = 0x1324;
            break;
        case 0:
            range = 0x1900;
            break;
        case 2:
            range = 0xE10;
            break;
        case 3:
            range = 0x9C4;
            break;
    }
    if (near != 0 && !(dist <= range)) {
        *sx = (u8)jump->unk_33;
        *sy = (u8)jump->unk_34;
        return;
    }
    if (obj->trans.x < jump->unk_0C + 30.0f && jump->unk_0C - 30.0f < obj->trans.x &&
        obj->trans.z < jump->unk_10 + 30.0f && jump->unk_10 - 30.0f < obj->trans.z) {
        jump->unk_35 = guRandom() & 3;
    }
    r = guRandom();
    switch (jump->unk_35) {
        case 0:
            if (D_800FD878_BowlOver->trans.z < obj->trans.z) {
                *sy = (u8)jump->unk_34 - (r & 7);
            } else {
                *sy = (u8)jump->unk_34 + ((r >> 3) & 7);
            }
            if (D_800FD878_BowlOver->trans.x + 1000.0f < obj->trans.x + 1000.0f) {
                *sx = (u8)jump->unk_33 - ((r >> 6) & 7);
            } else {
                *sx = (u8)jump->unk_33 + ((r >> 9) & 7);
            }
            break;
        case 1:
            if (D_800FD878_BowlOver->trans.z < obj->trans.z) {
                *sy = (u8)jump->unk_34 - (r & 7);
            } else {
                *sy = (u8)jump->unk_34 + ((r >> 3) & 7);
            }
            if (D_800FD878_BowlOver->trans.x > 0.0f) {
                *sx = (u8)jump->unk_33 - ((r >> 6) & 7);
            } else {
                *sx = (u8)jump->unk_33 + ((r >> 9) & 7);
            }
            break;
        case 2:
            if (D_800FD878_BowlOver->trans.z < obj->trans.z) {
                *sy = -((r & 0x1F) + 0x14);
            } else {
                *sy = ((r >> 5) & 0x1F) + 0x14;
            }
            if (D_800FD878_BowlOver->trans.x + 1000.0f < obj->trans.x + 1000.0f) {
                *sx = -(((r >> 10) & 0x1F) + 0x14);
            } else {
                *sx = ((r >> 15) & 0x1F) + 0x14;
            }
            break;
        case 3:
            dx = obj->trans.x - D_800FD878_BowlOver->trans.x;
            dz = -(obj->trans.z - D_800FD878_BowlOver->trans.z);
            d = sqrtf(dx * dx + dz * dz);
            if (d != 0.0f) {
                *sx = (s32)((dx / d) * 50.0f);
                *sy = (s32)((dz / d) * -50.0f);
            } else {
                *sx = r & 0x3F;
                *sy = -((r >> 6) & 0x3F);
            }
            break;
    }
    jump->unk_0C = obj->trans.x;
    jump->unk_10 = obj->trans.z;
    jump->unk_33 = *sx;
    jump->unk_34 = *sy;
    if (!((r >> 20) & 3)) {
        jump->unk_31 = 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_11_BowlOver/142EA0", func_800FB650_BowlOver);
#endif

// register allocation and float temporaries
#ifdef NON_MATCHING
void func_800FBB30_BowlOver(omObjData* obj) {
    BowlPlayerWork* w;
    BowlPin* pin;
    BowlJump* jump;
    u8 sx;
    u8 sy;
    s32 keep;
    s16 slot;
    s16 i;
    s32 r;
    f32 ax;
    f32 ay;
    f32 x;
    f32 y;
    f32 z;
    f32 n;

    w = PLAYER_WORK(obj);
    pin = &D_800FD880_BowlOver[PIN_IDX(obj)];
    func_800F9B78_BowlOver(obj);
    func_80025F10(obj->model[0], D_800FDC58_BowlOver);
    func_80025F10(obj->model[1], D_800FDC58_BowlOver);
    jump = &D_800FDC60_BowlOver[PIN_IDX(obj)];
    if (jump->unk_14 == 0) {
        if (D_800ED430 > 0 && D_800FD2D0_BowlOver[0] != 1 && pin->unk_0E != 1) {
            if (!(GwPlayer[w->unk_58].flags & 1)) {
                if (ContBtnTrg[(s8)w->unk_56] & 0x8000) {
                    jump->unk_00 = 40.0f;
                    jump->unk_14 = 1;
                    jump->unk_18 = 0;
                    jump->unk_16 = 0;
                    jump->unk_04 = 2.5f;
                    jump->unk_1C = -1;
                    PlaySound(0x263);
                }
            } else if (jump->unk_31 == 1) {
                jump->unk_00 = 40.0f;
                jump->unk_14 = 1;
                jump->unk_18 = 0;
                jump->unk_16 = 0;
                jump->unk_04 = 2.5f;
                jump->unk_1C = -1;
                jump->unk_31 = 0;
                PlaySound(0x263);
            }
        }
    } else if (jump->unk_18 == 1) {
        if (jump->unk_16 > 20) {
            jump->unk_1A = 0;
            jump->unk_14 = 0;
            obj->rot.x = 0.0f;
        } else {
            jump->unk_1A = 1;
            if (jump->unk_1C < 0) {
                if (obj->rot.x > 8.0f) {
                    jump->unk_04 = -4.1f;
                    jump->unk_1C = ~jump->unk_1C;
                }
            } else if (obj->rot.x < -8.0f) {
                jump->unk_04 = 4.1f;
                jump->unk_1C = ~jump->unk_1C;
            }
            obj->rot.x = obj->rot.x + jump->unk_04 / ((f32)jump->unk_16 / 5.0f + 1.0);
        }
        jump->unk_16++;
    }
    obj->trans.y += jump->unk_00;
    jump->unk_00 -= 9.8f;
    if (obj->trans.y < 0.0f) {
        jump->unk_18 = 1;
        jump->unk_00 = 0.0f;
        obj->trans.y = 0.0f;
    }
    if (jump->unk_1A == 0) {
        slot = jump->unk_20;
        sy = 0;
        sx = 0;
        keep = 1;
        if (D_800ED430 > 0 && jump->unk_18 == 1 && D_800FD2D0_BowlOver[0] != jump->unk_18 &&
            pin->unk_0E != jump->unk_18) {
            if (!(GwPlayer[w->unk_58].flags & 1)) {
                jump->unk_33 = sx = ContStkX[(s8)w->unk_56];
                jump->unk_34 = sy = ContStkY[(s8)w->unk_56];
            } else {
                func_800FB650_BowlOver(obj, jump, &sx, &sy);
            }
            keep = 0;
        }
        if (keep == 1) {
            sx = jump->unk_33;
            sy = jump->unk_34;
        }
        if ((s8)sx > 60) {
            sx = 60;
        }
        if ((s8)sy > 60) {
            sy = 60;
        }
        if ((s8)sx < -60) {
            sx = -60;
        }
        if ((s8)sy < -60) {
            sy = -60;
        }
        jump->unk_21[slot] = sx;
        jump->unk_29[slot] = sy;
        ax = 0.0f;
        ay = 0.0f;
        for (i = 0; i < 8; i++) {
            ax += jump->unk_21[i];
            ay += jump->unk_29[i];
        }
        ax /= 8.0f;
        ay /= 8.0f;
        jump->unk_20 = (jump->unk_20 + 1) & 7;
        if (ax * ax + ay * ay > 100.0f) {
            obj->rot.y = jump->unk_08 = func_800B0CD8(ax, -ay);
        }
        if (jump->unk_14 == 1) {
            func_800FAC94_BowlOver(obj, ax / 40.0f, -ay / 40.0f);
        }
    }
    if (pin->unk_0E == 1) {
        obj->rot.y = jump->unk_08 = 180.0f;
    }
    func_800FB230_BowlOver(obj);
    if (pin->unk_0E != 1) {
        return;
    }
    if (pin->unk_10 != 1) {
        if (D_800FD5AC_BowlOver[w->unk_58] > 5) {
            pin->unk_14 = 5.0f;
            D_800FD5AC_BowlOver[D_800FDC5A_BowlOver[0]] += 5;
            D_800FD5AC_BowlOver[w->unk_58] -= 5;
        } else {
            pin->unk_14 = D_800FD5AC_BowlOver[w->unk_58];
            D_800FD5AC_BowlOver[D_800FDC5A_BowlOver[0]] += pin->unk_14;
            D_800FD5AC_BowlOver[w->unk_58] = 0;
        }
        for (i = 0; i < pin->unk_14; i++) {
            pin->unk_18[i] = i * 5;
            pin->unk_2C[i] = 18.5 - pin->unk_18[i] * 1.12f;
            r = guRandom();
            pin->unk_54[i] = ((f32)(r % 200) - 100.0f) / 100.0f;
            pin->unk_68[i] = ((f32)(guRandom() % 200) - 100.0f) / 100.0f;
            pin->unk_7C[i] = 50.0f;
            pin->unk_90[i] = 1.0f;
            func_800258EC(obj->model[i + 7], 4, 0);
            func_800258EC(obj->model[i + 12], 4, 0);
        }
        pin->unk_10 = 1;
    }
    for (i = 0; i < pin->unk_14; i++) {
        n = pin->unk_7C[i];
        x = pin->unk_54[i] * n + obj->trans.x;
        y = pin->unk_18[i] + 10.0f;
        z = obj->trans.z + 20.0f + pin->unk_68[i] * n;
        if (z < -5200.0f) {
            z = -5200.0f;
        }
        func_80025798(obj->model[i + 7], x, y, z);
        func_80025F10(obj->model[i + 7], D_800FDC58_BowlOver);
        func_800FAAF8_BowlOver(obj->model[i + 12], x, y, z);
        func_80025F10(obj->model[i + 12], D_800FDC58_BowlOver);
        pin->unk_18[i] += pin->unk_2C[i];
        pin->unk_2C[i] -= 1.12f;
        pin->unk_7C[i] += pin->unk_90[i] * 5.0;
        if (pin->unk_18[i] <= 0.0f) {
            pin->unk_18[i] = 0.0f;
            pin->unk_2C[i] = pin->unk_90[i] * 18.5;
            pin->unk_90[i] -= 0.173;
            if (pin->unk_90[i] < 0.0f) {
                pin->unk_90[i] = 0.0f;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_11_BowlOver/142EA0", func_800FBB30_BowlOver);
#endif

// register allocation
#ifdef NON_MATCHING
void func_800FC598_BowlOver(omObjData* obj, s32 dir, s32 file, s32 player, u16 slot, u16 pin) {
    BowlPlayerWork* w;
    s16 i;
    u16 img;

    obj->unk_50 = func_80023684(sizeof(BowlPlayerWork), 0x7918);
    func_8009B770(obj->unk_50, 0, sizeof(BowlPlayerWork));
    w = PLAYER_WORK(obj);
    w->unk_D8 = func_80023684(obj->mtncnt * 4, 0x7918);
    w->unk_56 = GwPlayer[(u16)player].port;
    w->unk_58 = player;
    for (i = 0; i < 6; i++) {
        if (D_800FD5D8_BowlOver[i].unk_00 == (u32)dir >> 16) {
            break;
        }
    }
    obj->model[0] = LoadFormFile(D_800FD5D8_BowlOver[i].unk_04 | 0x230000, 0x699);
    obj->model[1] = func_800174F4(6, 0x699);
    obj->model[2] = LoadFormFile(dir | file, 0x699);
    func_80020EA0(obj->model[2], D_800FD5D8_BowlOver[i].unk_08, obj->model[0], D_800FD5D8_BowlOver[i].unk_1D);
    obj->model[3] = LoadFormFile(0x19, 0x68D);
    obj->model[4] = LoadFormFile(0x1C, 0x68D);
    obj->model[5] = LoadFormFile(0x19, 0x68D);
    obj->model[6] = LoadFormFile(0x1C, 0x68D);
    for (i = 0; i < 5; i++) {
        img = ReadImgPackand(0x21, 0x289, 8);
        obj->model[i + 7] = D_800ECDE0[img].unk_00;
        func_80025930(obj->model[i + 7], 0x70000000, 0x70000000);
        func_80039970(D_800ECDE0[img].unk_02, ((u32)guRandom() >> 4) % 300 / 100);
        func_80025830(obj->model[i + 7], 2.0f, 2.0f, 2.0f);
        func_800258EC(obj->model[i + 7], 4, 4);
        obj->model[i + 12] = func_80023FC8(obj->model[1]);
        func_800258EC(obj->model[i + 12], 4, 4);
    }
    func_80025F10(obj->model[2], 0);
    func_800258EC(obj->model[3], 4, 4);
    func_800258EC(obj->model[4], 4, 4);
    func_800258EC(obj->model[5], 4, 4);
    func_800258EC(obj->model[6], 4, 4);
    PIN_IDX(obj) = pin;
    obj->trans.x = D_800FD564_BowlOver[slot].x;
    obj->trans.y = D_800FD564_BowlOver[slot].y;
    obj->trans.z = D_800FD564_BowlOver[slot].z;
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800F9B78_BowlOver(obj);
    obj->func_ptr = func_800FBB30_BowlOver;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_11_BowlOver/142EA0", func_800FC598_BowlOver);
#endif

void func_800FC9E0_BowlOver(omObjData* obj) {
    BowlPin* pin;
    s32 r;
    f32 x;
    f32 y;
    f32 z;

    pin = &D_800FD880_BowlOver[PIN_IDX(obj)];
    func_80025F10(obj->model[0], D_800FDC58_BowlOver);
    func_80025F10(obj->model[1], D_800FDC58_BowlOver);
    func_800FB230_BowlOver(obj);
    func_800F9B78_BowlOver(obj);
    if (pin->unk_0E != 1) {
        return;
    }
    if (pin->unk_10 != 1) {
        D_800FD5AC_BowlOver[D_800FDC5A_BowlOver[0]]++;
        pin->unk_18[0] = 32.5f;
        r = guRandom();
        pin->unk_54[0] = ((f32)(r % 200) - 100.0f) / 100.0f;
        pin->unk_68[0] = ((f32)(guRandom() % 200) - 100.0f) / 100.0f;
        pin->unk_7C[0] = 50.0f;
        pin->unk_90[0] = 1.0f;
        func_800258EC(obj->model[7], 4, 0);
        func_800258EC(obj->model[8], 4, 0);
        pin->unk_10 = 1;
    }
    x = obj->trans.x + pin->unk_54[0] * pin->unk_7C[0];
    y = pin->unk_18[0] + 10.0f;
    z = obj->trans.z + 20.0f + pin->unk_68[0] * pin->unk_7C[0];
    if (z < -5200.0f) {
        z = -5200.0f;
    }
    func_80025798(obj->model[7], x, y, z);
    func_80025F10(obj->model[7], D_800FDC58_BowlOver);
    func_800FAAF8_BowlOver(obj->model[8], x, y, z);
    func_80025F10(obj->model[8], D_800FDC58_BowlOver);
    pin->unk_18[0] += pin->unk_2C[0];
    pin->unk_2C[0] -= 1.12f;
    pin->unk_7C[0] += pin->unk_90[0] * 5.0;
    if (pin->unk_18[0] <= 0.0f) {
        pin->unk_18[0] = 0.0f;
        pin->unk_2C[0] = pin->unk_90[0] * 18.5;
        pin->unk_90[0] -= 0.173;
        if (pin->unk_90[0] < 0.0f) {
            pin->unk_90[0] = 0.0f;
        }
    }
}

void func_800FCD54_BowlOver(omObjData* obj, u16 slot, s8 pin) {
    BowlFloorWork* w;

    obj->model[0] = LoadFormFile(0x230006, 0x699);
    obj->model[1] = func_800174F4(6, 0x699);
    obj->model[3] = LoadFormFile(0x19, 0x68D);
    obj->model[4] = LoadFormFile(0x1C, 0x68D);
    obj->model[5] = LoadFormFile(0x19, 0x68D);
    obj->model[6] = LoadFormFile(0x1C, 0x68D);
    obj->model[7] = D_800ECDE0[ReadImgPackand(0x21, 0x289, 8)].unk_00;
    func_80025930(obj->model[7], 0x70000000, 0x70000000);
    func_80025830(obj->model[7], 2.0f, 2.0f, 2.0f);
    func_800258EC(obj->model[7], 4, 4);
    obj->model[8] = func_80023FC8(obj->model[1]);
    func_800258EC(obj->model[8], 4, 4);
    func_800258EC(obj->model[3], 4, 4);
    func_800258EC(obj->model[4], 4, 4);
    func_800258EC(obj->model[5], 4, 4);
    func_800258EC(obj->model[6], 4, 4);
    obj->unk_50 = w = func_80023684(sizeof(BowlFloorWork), 0x7918);
    func_8009B770(w, 0, sizeof(BowlFloorWork));
    w->unk_04 = 1;
    PIN_IDX(obj) = pin;
    obj->trans.x = D_800FD564_BowlOver[slot].x;
    obj->trans.y = D_800FD564_BowlOver[slot].y;
    obj->trans.z = D_800FD564_BowlOver[slot].z;
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800F9B78_BowlOver(obj);
    obj->func_ptr = func_800FC9E0_BowlOver;
}

void func_800FCFA0_BowlOver(void) {
    s16 i;
    u32 r;
    u32 a;
    u32 b;
    u16 t;

    for (i = 0; i < 6; i++) {
        D_800FD850_BowlOver[i] = i;
    }
    for (i = 0; i < 10; i++) {
        r = guRandom();
        a = r & 7;
        if (a >= 6) {
            a = (r >> 3) & 3;
        }
        b = (r >> 5) & 7;
        if (b >= 6) {
            b = (r >> 8) & 3;
        }
        t = D_800FD850_BowlOver[a];
        D_800FD850_BowlOver[a] = D_800FD850_BowlOver[b];
        D_800FD850_BowlOver[b] = t;
    }
}

// argument conversion of the player index (lbu/sll/sra/andi)
#ifdef NON_MATCHING
void func_800FD07C_BowlOver(omObjData* obj) {
    s32 p;
    u8 chr;
    s32 dir;
    s32 file;

    p = D_800FDC5A_BowlOver[1];
    chr = GwPlayer[p].character;
    dir = D_800C59AC[chr].unk_00;
    file = D_800C59AC[chr].unk_04;
    D_800FD5AC_BowlOver[p] = GwPlayer[p].coins;
    func_800FC598_BowlOver(obj, dir, file, D_800FDC5A_BowlOver[1], D_800FD850_BowlOver[0], 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_11_BowlOver/142EA0", func_800FD07C_BowlOver);
#endif

// argument conversion of the player index (lbu/sll/sra/andi)
#ifdef NON_MATCHING
void func_800FD118_BowlOver(omObjData* obj) {
    s32 p;
    u8 chr;
    s32 dir;
    s32 file;

    p = D_800FDC5A_BowlOver[2];
    chr = GwPlayer[p].character;
    dir = D_800C59AC[chr].unk_00;
    file = D_800C59AC[chr].unk_04;
    D_800FD5AC_BowlOver[p] = GwPlayer[p].coins;
    func_800FC598_BowlOver(obj, dir, file, D_800FDC5A_BowlOver[2], D_800FD850_BowlOver[1], 1);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_11_BowlOver/142EA0", func_800FD118_BowlOver);
#endif

// argument conversion of the player index (lbu/sll/sra/andi)
#ifdef NON_MATCHING
void func_800FD1B8_BowlOver(omObjData* obj) {
    s32 p;
    u8 chr;
    s32 dir;
    s32 file;

    p = D_800FDC5A_BowlOver[3];
    chr = GwPlayer[p].character;
    dir = D_800C59AC[chr].unk_00;
    file = D_800C59AC[chr].unk_04;
    D_800FD5AC_BowlOver[p] = GwPlayer[p].coins;
    func_800FC598_BowlOver(obj, dir, file, D_800FDC5A_BowlOver[3], D_800FD850_BowlOver[2], 2);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_11_BowlOver/142EA0", func_800FD1B8_BowlOver);
#endif

void func_800FD258_BowlOver(omObjData* obj) {
    func_800FCD54_BowlOver(obj, D_800FD850_BowlOver[3], 3);
}

void func_800FD27C_BowlOver(omObjData* obj) {
    func_800FCD54_BowlOver(obj, D_800FD850_BowlOver[4], 4);
}

void func_800FD2A0_BowlOver(omObjData* obj) {
    func_800FCD54_BowlOver(obj, D_800FD850_BowlOver[5], 5);
}
