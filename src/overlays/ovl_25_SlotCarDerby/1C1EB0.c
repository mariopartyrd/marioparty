#include "SlotCarDerby.h"

int abs(int);
extern s8 ContStkY[];

void func_800F65E0_SlotCarDerby(void) {
    omObjData* obj;
    u8 cam;

    D_80101DF2_SlotCarDerby = 0;
    D_80101DEE_SlotCarDerby = 0;
    D_80101DF0_SlotCarDerby = 0;
    D_80101DF4_SlotCarDerby = 0;
    D_80101DF6_SlotCarDerby = 0;
    func_80029090(50);
    func_8001DE70(32);
    omInitObjMan(32, 0);
    func_80060088();
    D_801024B4_SlotCarDerby = 0;
    D_801024B2_SlotCarDerby = 0;
    D_801024B0_SlotCarDerby = 0;
    if (_CheckFlag(0x2B) != 0) {
        D_801024B0_SlotCarDerby = 1;
        if (_CheckFlag(0x2D) != 0) {
            D_801024B0_SlotCarDerby = 2;
        }
    }
    if (D_801024B0_SlotCarDerby == 2 && GwCommon.boardWork[1] > 0) {
        if ((s32)((u32)(((rand8() << 8) | rand8()) * 25) >> 14) < 20) {
            D_801024B4_SlotCarDerby = 1;
        }
    }
    obj = omAddObj(0x7FDA, 0, 0, -1, omOutView);
    omOutView(obj);
    omSetStatBit(obj, 0xA0);
    func_800178A0(1);
    cam = func_800178E8();
    func_80017660(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 45.0f, 80.0f, 4000.0f);
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    if (D_801024B0_SlotCarDerby != 0) {
        D_80101420_SlotCarDerby = D_801024B0_SlotCarDerby != 1;
    } else {
        D_80101420_SlotCarDerby = 0;
        if (_CheckFlag(0x32) != 0) {
            D_80101420_SlotCarDerby = 1;
        }
    }
    func_800234B8(0, 0x88, 0x88, 0x88);
    func_800234B8(1, 0xFF, 0xFF, 0xFF);
    func_80023504(1, 0.0f, 2000.0f, 2000.0f);
    D_800ED440 = 0;
    D_800F2AF8[D_800ED440++] = omAddObj(0, 0, 0, -1, func_800F6A14_SlotCarDerby);
    D_800F2AF8[D_800ED440++] = omAddObj(1, 3, 0, -1, func_800FB004_SlotCarDerby);
    D_800F3FB0[D_800F2BC0++] = omAddObj(4, 2, 2, -1, func_800F7678_SlotCarDerby);
    D_800F3FB0[D_800F2BC0++] = omAddObj(5, 2, 2, -1, func_800F7694_SlotCarDerby);
    D_800F3FB0[D_800F2BC0++] = omAddObj(6, 2, 2, -1, func_800F76B0_SlotCarDerby);
    D_800F3FB0[D_800F2BC0++] = omAddObj(7, 2, 2, -1, func_800F76CC_SlotCarDerby);
    func_800FBEE0_SlotCarDerby(D_80101420_SlotCarDerby);
    /* Shift-JIS "ＳＴＡＲＴＧＯＡＬＷＩＮ！" (written as bytes: the source is UTF-8) */
    func_8007B168((u8*)"\x82\x72\x82\x73\x82\x60\x82\x71\x82\x73\x82\x66\x82\x6E\x82\x60\x82\x6B\x82\x76\x82\x68\x82\x6D\x81\x49", 1);
}
void func_800F6A14_SlotCarDerby(omObjData* obj) {
    obj->func_ptr = func_800F6A38_SlotCarDerby;
    func_800FB1C0_SlotCarDerby();
}
void func_800F6A38_SlotCarDerby(omObjData* obj) {
    if (D_80101DEE_SlotCarDerby != 0 && D_80101DF0_SlotCarDerby == 0) {
        func_800726AC(0, 20);
        D_80101DF0_SlotCarDerby = 1;
        func_80060398(40);
    } else if (D_80101DF0_SlotCarDerby != 0 && D_80101DF2_SlotCarDerby == 0 && func_80072718() == 0) {
        D_80101DF2_SlotCarDerby = 1;
        func_800FBDFC_SlotCarDerby();
        omOvlReturnEx(1);
        return;
    }
    func_800FB2FC_SlotCarDerby(0, 400, 400);
}

// register allocation (masked 0)
#ifdef NON_MATCHING
void func_800F6AEC_SlotCarDerby(void) {
    f32 dx;
    f32 dy;
    f32 dz;
    f32 total;
    s32 i;
    s32 j;
    Vec* base;
    Vec* a;
    Vec* b;

    D_80101424_SlotCarDerby = D_80100C70_SlotCarDerby[D_80101420_SlotCarDerby];
    D_80101428_SlotCarDerby = D_80100C78_SlotCarDerby[D_80101420_SlotCarDerby];
    D_8010142C_SlotCarDerby = func_80023684(D_80101428_SlotCarDerby * sizeof(f32), 0x7918);
    D_80101430_SlotCarDerby = func_80023684((D_80101428_SlotCarDerby + 1) * sizeof(f32), 0x7918);
    total = 0.0f;
    for (i = 0; i < D_80101428_SlotCarDerby; i++) {
        j = (i + 1) % D_80101428_SlotCarDerby;
        base = D_80101424_SlotCarDerby;
        b = &base[j];
        a = &base[i];
        dx = b->x - a->x;
        dy = b->y - a->y;
        dz = b->z - a->z;
        D_8010142C_SlotCarDerby[i] = sqrtf(dx * dx + dy * dy + dz * dz);
        D_80101430_SlotCarDerby[i] = total;
        total += D_8010142C_SlotCarDerby[i];
        a = &D_80101424_SlotCarDerby[i];
        D_80101440_SlotCarDerby[i].x = a->x + dx * 0.5;
        D_80101440_SlotCarDerby[i].y = a->y + dy * 0.5;
        D_80101440_SlotCarDerby[i].z = a->z + dz * 0.5;
    }
    D_80101430_SlotCarDerby[i] = total;
    D_80101434_SlotCarDerby = total;
    for (i = 0; i < 16; i++) {
        D_80101DA0_SlotCarDerby[i] = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800F6AEC_SlotCarDerby);
#endif
void func_800F6D90_SlotCarDerby(void) {
    s32 i;
    s32 j;
    s32 t;

    for (i = 0; i < 4; i++) {
        func_8009B770(&D_80101DF8_SlotCarDerby[i], 0, sizeof(SCDCar));
    }
    for (i = 0; i < 4; i++) {
        D_8010230A_SlotCarDerby[i] = i;
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (i != j && ((((rand8() << 8) | rand8()) * 125) >> 13) < 500) {
                t = D_8010230A_SlotCarDerby[i];
                D_8010230A_SlotCarDerby[i] = D_8010230A_SlotCarDerby[j];
                D_8010230A_SlotCarDerby[j] = t;
            }
        }
    }
    D_80102308_SlotCarDerby = 0;
    D_80102312_SlotCarDerby = 1;
    D_80102314_SlotCarDerby = 1;
}
void func_800F6ED4_SlotCarDerby(SCDCar* car, s16 sound) {
    if (car->unk_74 >= 0) {
        func_8006071C(car->unk_74);
    }
    car->unk_74 = -1;
    if (sound >= 0) {
        func_80060540(sound, car->unk_01);
        car->unk_76 = 30;
    }
}
// decomp-permuter
void func_800F6F38_SlotCarDerby(omObjData *obj)
{
  SCDCar *car;
  long n;
  s32 lane;
  s32 i;
  n = D_80102308_SlotCarDerby;
  if (n < 4)
  {
    D_80102308_SlotCarDerby++;
    lane = D_8010230A_SlotCarDerby[n];
    D_80102314_SlotCarDerby = D_80102308_SlotCarDerby;
    car = &D_80101DF8_SlotCarDerby[lane];
    car->unk_00 = 1;
    car->unk_02 = 4;
    car->unk_01 = n;
    car->unk_78 = -1;
    car->unk_74 = -1;
    car->unk_60 = 0;
    car->unk_7C = obj;
    obj->work[1] = lane;
    for (i = 0; i < D_80100C7C_SlotCarDerby[D_80101420_SlotCarDerby][lane]; i++)
    {
      car->unk_48 += D_8010142C_SlotCarDerby[i];
    }

    car->unk_48 += D_80100C8C_SlotCarDerby[D_80101420_SlotCarDerby];
    func_800F7650_SlotCarDerby(obj->model[0], 0.0f);
  }
}
void func_800F7084_SlotCarDerby(omObjData* obj) {
    func_800F6F38_SlotCarDerby(obj);
    func_800184BC(obj, 0);
    func_800F7650_SlotCarDerby(obj->model[0], 0.0f);
}
SCDCar* func_800F70C4_SlotCarDerby(omObjData* obj) {
    return &D_80101DF8_SlotCarDerby[obj->work[1]];
}
s32 func_800F70DC_SlotCarDerby(void) {
    s8 hit[4];
    s16 lane[4];
    f32 dist[4];
    SCDCar* car;
    SCDCar* other;
    s16 n;
    s32 left;
    s32 i;
    s32 j;
    s32 k;
    f32 range;
    f32 d;

    n = 0;
    car = D_80101DF8_SlotCarDerby;
    for (i = 0; i < 4; i++, car++) {
        if ((car->unk_00 & 1) && (car->unk_02 == 1 || car->unk_02 == 2)) {
            hit[n] = 0;
            lane[n] = i;
            d = car->unk_48 + car->unk_4C;
            dist[n] = func_8009B618(d, D_80101434_SlotCarDerby);
            n++;
        }
    }
    if (n < 2) {
        return n;
    }
    range = (D_80101DE0_SlotCarDerby.unk_00 == 2) ? 15.0f : 30.0f;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            d = dist[j] - dist[i];
            if (d < 0.0) {
                d += D_80101434_SlotCarDerby;
            }
            if (d > 40.0) {
                continue;
            }
            car = &D_80101DF8_SlotCarDerby[lane[i]];
            other = &D_80101DF8_SlotCarDerby[lane[j]];
            d = 0.0f;
            for (k = 0; k < 3; k++) {
                d += ((&car->unk_0C.x)[k] - (&other->unk_0C.x)[k]) * ((&car->unk_0C.x)[k] - (&other->unk_0C.x)[k]);
            }
            if (range < sqrtf(d)) {
                continue;
            }
            hit[j] = -1;
            if (hit[i] == 0) {
                hit[i] = 1;
            }
            if (D_80101DE0_SlotCarDerby.unk_00 == 2) {
                func_800F6ED4_SlotCarDerby(car, 0x144);
            }
        }
    }
    left = n;
    for (i = 0; i < n; i++) {
        if (hit[i] != 0) {
            car = &D_80101DF8_SlotCarDerby[lane[i]];
            if (hit[i] > 0) {
                if (D_80101DE0_SlotCarDerby.unk_00 == 2) {
                    func_800F744C_SlotCarDerby(2, car);
                }
            } else if (D_80101DE0_SlotCarDerby.unk_00 != 2) {
                car->unk_50 = 10.5f;
            } else {
                car->unk_02 = 3;
                car->unk_64 = car->unk_66 = 0;
                left--;
            }
        }
    }
    return left;
}
void func_800F744C_SlotCarDerby(s16 kind, SCDCar* car) {
    f32 ahead[3] = { -8.0f, -10.0f, 10.0f };
    f32 rise[3] = { -0.0f, -5.0f, 0.0f };
    Vec pos;
    Vec dir;
    Vec angles;
    Matrix4f m;

    func_800F96F4_SlotCarDerby(car->unk_48, car->unk_4C, ahead[kind], &pos, &dir);
    dir.x = -dir.x;
    dir.y = -dir.y;
    dir.z = -dir.z;
    func_800F9EA4_SlotCarDerby(&dir, &angles.x);
    if (kind < 2) {
        if (kind == 0) {
            func_800F96F4_SlotCarDerby(car->unk_48, car->unk_4C, car->unk_50, &pos, &dir);
            func_8009EA40(m, pos.x, pos.y, pos.z);
        } else {
            func_8009EA40(m, car->unk_0C.x, car->unk_0C.y, car->unk_0C.z);
        }
        MtxRotate(m, car->unk_24.x, car->unk_24.y, car->unk_24.z);
        func_800F9F2C_SlotCarDerby(m, 0.0f, 0.0f, ahead[kind], &pos.x);
    }
    pos.y += rise[kind];
    if (kind < 2) {
        func_800FD9E8_SlotCarDerby(kind, &pos, &angles);
    } else {
        func_80021EC0(1, pos.x * 10.0, pos.y * 10.0, pos.z * 10.0);
    }
}
void func_800F7650_SlotCarDerby(s16 model, f32 speed) {
    unk_ovl_2D_struct* p = &D_800F2B7C[model];

    p->unk_4C = speed;
}
void func_800F7678_SlotCarDerby(omObjData* obj) {
    func_800F76E8_SlotCarDerby(obj, 0);
}
void func_800F7694_SlotCarDerby(omObjData* obj) {
    func_800F76E8_SlotCarDerby(obj, 1);
}
void func_800F76B0_SlotCarDerby(omObjData* obj) {
    func_800F76E8_SlotCarDerby(obj, 2);
}
void func_800F76CC_SlotCarDerby(omObjData* obj) {
    func_800F76E8_SlotCarDerby(obj, 3);
}
/* .data (the strings of D_80100CBC land in .rodata here, after func_800F744C's constants) */
Vec D_801002B0_SlotCarDerby[86] = {
    { 43.255f, 131.195f, 101.305f },
    { 7.362f, 131.2f, 101.778f },
    { -41.595f, 131.204f, 101.305f },
    { -71.693f, 131.204f, 101.445f },
    { -100.58f, 131.204f, 100.478f },
    { -128.784f, 130.728f, 84.847f },
    { -144.522f, 133.008f, 59.208f },
    { -154.665f, 137.989f, 11.419f },
    { -144.69f, 140.469f, -38.054f },
    { -128.018f, 140.253f, -63.487f },
    { -99.755f, 140.462f, -78.379f },
    { -76.887f, 141.889f, -77.955f },
    { -28.747f, 178.337f, -78.926f },
    { 33.824f, 196.881f, -113.796f },
    { 82.259f, 173.888f, -131.195f },
    { 126.163f, 167.512f, -134.715f },
    { 166.591f, 167.512f, -105.606f },
    { 199.587f, 167.496f, -51.949f },
    { 212.526f, 165.682f, 12.137f },
    { 199.398f, 148.176f, 77.506f },
    { 165.292f, 139.541f, 125.061f },
    { 114.113f, 131.195f, 157.323f },
    { 74.693f, 131.195f, 157.293f },
    { 43.764f, 131.195f, 157.598f },
    { 6.663f, 131.195f, 157.243f },
    { -41.351f, 131.195f, 157.599f },
    { -73.684f, 131.195f, 157.561f },
    { -113.857f, 131.195f, 157.048f },
    { -164.935f, 139.52f, 124.839f },
    { -199.469f, 148.116f, 77.436f },
    { -212.265f, 165.663f, 11.968f },
    { -200.158f, 167.326f, -51.616f },
    { -165.418f, 167.326f, -105.116f },
    { -114.39f, 167.321f, -134.226f },
    { -24.184f, 167.11f, -143.647f },
    { 47.405f, 157.108f, -107.931f },
    { 111.672f, 156.889f, -119.768f },
    { 154.386f, 157.544f, -89.353f },
    { 180.5f, 157.535f, -45.275f },
    { 192.35f, 155.649f, 11.632f },
    { 180.0f, 142.989f, 71.603f },
    { 151.421f, 136.194f, 111.78f },
    { 109.569f, 131.204f, 137.937f },
    { 73.268f, 131.204f, 137.766f },
    { 43.985f, 131.204f, 137.827f },
    { 7.362f, 131.204f, 138.007f },
    { -40.866f, 131.204f, 138.342f },
    { -72.637f, 131.204f, 138.268f },
    { -108.18f, 131.204f, 138.292f },
    { -153.618f, 136.332f, 111.649f },
    { -180.592f, 142.977f, 71.578f },
    { -191.56f, 155.531f, 11.468f },
    { -179.759f, 157.683f, -47.811f },
    { -152.536f, 157.816f, -91.259f },
    { -110.589f, 157.734f, -115.471f },
    { -28.113f, 157.518f, -125.067f },
    { 45.344f, 149.036f, -91.828f },
    { 105.398f, 148.701f, -101.053f },
    { 141.149f, 148.701f, -76.295f },
    { 163.516f, 148.524f, -40.138f },
    { 173.579f, 146.64f, 11.558f },
    { 162.459f, 138.04f, 64.543f },
    { 138.842f, 133.104f, 98.195f },
    { 104.931f, 131.204f, 120.243f },
    { 73.262f, 131.204f, 120.256f },
    { 43.331f, 131.204f, 120.532f },
    { 7.362f, 131.204f, 120.542f },
    { -41.545f, 131.204f, 120.507f },
    { -72.66f, 131.204f, 119.889f },
    { -104.156f, 131.204f, 120.022f },
    { -139.31f, 133.128f, 97.998f },
    { -162.643f, 138.031f, 64.644f },
    { -173.913f, 146.632f, 11.652f },
    { -162.906f, 148.479f, -42.219f },
    { -139.882f, 148.864f, -76.509f },
    { -105.776f, 149.036f, -97.03f },
    { -32.801f, 148.709f, -105.242f },
    { 38.241f, 139.547f, -72.242f },
    { 99.33f, 139.874f, -82.658f },
    { 129.143f, 139.555f, -63.277f },
    { 147.62f, 139.516f, -36.194f },
    { 155.018f, 137.989f, 11.451f },
    { 145.348f, 133.008f, 58.727f },
    { 127.275f, 130.72f, 83.466f },
    { 100.535f, 131.195f, 101.16f },
    { 73.127f, 131.195f, 101.589f },
};
Vec D_801006B8_SlotCarDerby[122] = {
    { 90.76f, 131.195f, 98.805f },
    { 87.282f, 131.197f, 61.773f },
    { 57.425f, 131.198f, 11.875f },
    { 0.54f, 131.2f, -1.756f },
    { -54.511f, 131.202f, 10.702f },
    { -84.093f, 131.203f, 62.459f },
    { -89.023f, 131.204f, 100.755f },
    { -100.434f, 131.204f, 119.942f },
    { -124.945f, 131.204f, 132.102f },
    { -139.342f, 130.966f, 132.303f },
    { -163.841f, 131.52f, 120.052f },
    { -182.69f, 134.093f, 91.326f },
    { -191.948f, 138.84f, 42.65f },
    { -191.841f, 137.989f, -11.682f },
    { -183.477f, 140.469f, -38.054f },
    { -166.805f, 140.253f, -63.487f },
    { -99.755f, 140.462f, -78.379f },
    { -76.887f, 141.889f, -77.955f },
    { -28.747f, 178.337f, -78.926f },
    { 33.824f, 196.881f, -113.796f },
    { 82.259f, 173.888f, -131.195f },
    { 126.163f, 167.512f, -134.715f },
    { 206.671f, 167.512f, -105.606f },
    { 239.667f, 167.496f, -51.949f },
    { 251.453f, 166.589f, -13.636f },
    { 251.731f, 166.444f, 17.387f },
    { 252.604f, 165.656f, 45.127f },
    { 238.709f, 150.918f, 110.059f },
    { 206.195f, 139.892f, 158.653f },
    { 159.118f, 131.195f, 189.827f },
    { 110.53f, 131.195f, 187.296f },
    { 60.392f, 131.195f, 159.487f },
    { 33.763f, 131.195f, 113.427f },
    { 32.439f, 131.195f, 87.142f },
    { 21.175f, 131.195f, 64.484f },
    { -0.159f, 131.195f, 53.709f },
    { -21.4f, 131.195f, 62.427f },
    { -34.735f, 131.195f, 88.514f },
    { -35.723f, 131.195f, 115.132f },
    { -56.92f, 131.195f, 157.681f },
    { -109.344f, 131.195f, 188.671f },
    { -152.462f, 131.544f, 189.184f },
    { -202.337f, 140.131f, 158.556f },
    { -234.68f, 151.184f, 109.0f },
    { -248.335f, 166.061f, 43.598f },
    { -249.44f, 165.663f, -12.745f },
    { -238.945f, 167.326f, -51.616f },
    { -204.205f, 167.326f, -105.116f },
    { -114.39f, 167.321f, -134.226f },
    { -24.184f, 167.11f, -143.647f },
    { 47.405f, 157.108f, -107.931f },
    { 111.672f, 156.889f, -119.768f },
    { 194.466f, 157.544f, -89.353f },
    { 220.58f, 157.535f, -45.275f },
    { 233.082f, 156.592f, -13.636f },
    { 231.555f, 156.411f, 16.883f },
    { 232.332f, 156.146f, 44.475f },
    { 219.838f, 144.32f, 103.446f },
    { 192.033f, 136.643f, 145.319f },
    { 154.574f, 131.204f, 170.44f },
    { 114.105f, 131.204f, 169.436f },
    { 74.555f, 131.204f, 148.652f },
    { 52.319f, 131.204f, 107.824f },
    { 49.576f, 131.204f, 79.6f },
    { 34.402f, 131.204f, 47.05f },
    { 0.54f, 131.204f, 34.472f },
    { -32.371f, 131.204f, 44.506f },
    { -50.501f, 131.204f, 79.6f },
    { -52.634f, 131.204f, 110.713f },
    { -70.75f, 131.204f, 147.139f },
    { -112.418f, 131.204f, 171.666f },
    { -148.963f, 133.768f, 170.807f },
    { -188.338f, 136.845f, 144.554f },
    { -216.883f, 143.959f, 104.45f },
    { -228.738f, 156.66f, 43.5f },
    { -229.81f, 155.531f, -12.708f },
    { -218.547f, 157.683f, -47.811f },
    { -191.324f, 157.816f, -91.259f },
    { -110.589f, 157.734f, -115.471f },
    { -28.113f, 157.518f, -125.067f },
    { 45.344f, 149.036f, -91.828f },
    { 105.398f, 148.701f, -101.053f },
    { 181.229f, 148.701f, -76.295f },
    { 203.596f, 148.524f, -40.138f },
    { 212.963f, 147.582f, -11.885f },
    { 212.784f, 147.402f, 16.808f },
    { 213.04f, 147.449f, 42.666f },
    { 202.258f, 138.343f, 98.195f },
    { 178.701f, 133.445f, 130.317f },
    { 149.103f, 131.204f, 151.913f },
    { 119.1f, 131.204f, 152.759f },
    { 88.72f, 131.204f, 134.484f },
    { 70.834f, 131.204f, 102.197f },
    { 68.772f, 131.204f, 70.001f },
    { 46.058f, 131.204f, 29.508f },
    { 0.54f, 131.204f, 17.007f },
    { -43.54f, 131.204f, 29.021f },
    { -67.64f, 131.204f, 71.372f },
    { -71.472f, 131.204f, 104.205f },
    { -86.524f, 131.204f, 132.261f },
    { -118.896f, 131.204f, 152.521f },
    { -143.715f, 132.166f, 151.555f },
    { -175.214f, 133.544f, 131.428f },
    { -199.695f, 138.287f, 98.718f },
    { -210.069f, 147.677f, 43.046f },
    { -210.551f, 146.632f, -12.523f },
    { -201.693f, 148.479f, -42.219f },
    { -178.67f, 148.864f, -76.509f },
    { -105.776f, 149.036f, -97.03f },
    { -32.801f, 148.709f, -105.242f },
    { 38.241f, 139.547f, -72.242f },
    { 99.33f, 139.874f, -82.658f },
    { 169.223f, 139.555f, -63.277f },
    { 187.701f, 139.516f, -36.194f },
    { 192.843f, 138.752f, -11.01f },
    { 194.223f, 138.751f, 16.701f },
    { 194.18f, 138.67f, 43.851f },
    { 185.691f, 133.922f, 91.801f },
    { 167.868f, 131.915f, 118.649f },
    { 143.039f, 131.195f, 132.83f },
    { 123.966f, 131.195f, 134.925f },
    { 101.217f, 131.195f, 120.316f },
};
Vec* D_80100C70_SlotCarDerby[2] = { D_801002B0_SlotCarDerby, D_801006B8_SlotCarDerby };
u16 D_80100C78_SlotCarDerby[2] = { 86, 122 };
s16 D_80100C7C_SlotCarDerby[2][4] = { { 0, 23, 44, 65 }, { 24, 54, 84, 114 } };
s16 D_80100C8C_SlotCarDerby[2] = { 30, 15 };
s32 D_80100C90_SlotCarDerby[7] = { 0, 40, 55, 70, 85, 100, 150 };
s32 D_80100CAC_SlotCarDerby[4] = { 0, 5, 10, 15 };
char* D_80100CBC_SlotCarDerby[7] = {
    "atama_2", "Luigi1-atama_2", "C002_000b-bmerge10_1", "c003_000-head_1",
    "Luigi1-atama_1", "c005_000-bmerge1", "c100_1-atama",
};
u16 D_80100CD8_SlotCarDerby[7] = { 0, 1, 2, 3, 4, 5, 6 };
f32 D_80100CE8_SlotCarDerby[7] = { 1.2f, 1.45f, 1.3f, 1.2f, 1.0f, 1.1f, 0.9f };
f32 D_80100D04_SlotCarDerby[7][2] = {
    { 0.0f, 0.0f }, { 0.0f, 0.0f }, { 0.0f, 0.0f }, { 0.0f, 0.0f },
    { 0.0f, 0.0f }, { 10.0f, -20.0f }, { 0.0f, 0.0f },
};
u8 D_80100D3C_SlotCarDerby[10][3] = {
    { 3, 10, 2 }, { 34, 35, 4 }, { 36, 41, 4 }, { 48, 53, 4 }, { 55, 56, 4 },
    { 57, 62, 3 }, { 69, 74, 3 }, { 76, 77, 4 }, { 78, 83, 2 }, { 0xFF, 0xFF, 0xFF },
};
u8 D_80100D5C_SlotCarDerby[18][3] = {
    { 0, 6, 4 }, { 6, 9, 1 }, { 28, 32, 4 }, { 32, 38, 1 }, { 38, 41, 4 }, { 49, 51, 4 },
    { 58, 62, 3 }, { 62, 68, 2 }, { 68, 71, 3 }, { 79, 81, 4 }, { 82, 84, 4 }, { 88, 92, 2 },
    { 92, 98, 3 }, { 98, 101, 2 }, { 109, 111, 4 }, { 112, 114, 3 }, { 118, 119, 1 },
    { 0xFF, 0xFF, 0xFF },
};
f32 D_80100D94_SlotCarDerby[6] = { 40.0f, -60.0f, 0.0f, 200.0f, 80.0f, 440.0f };
f32 D_80100DAC_SlotCarDerby[6] = { 60.0f, -60.0f, 0.0f, 240.0f, 120.0f, 500.0f };
f32 D_80100DC4_SlotCarDerby[6] = { 0.0f, 80.0f, 0.0f, 0.0f, 200.0f, 600.0f };
f32 D_80100DDC_SlotCarDerby[6] = { 0.0f, 80.0f, 0.0f, 0.0f, 400.0f, 700.0f };
f32* D_80100DF4_SlotCarDerby[2] = { D_80100DC4_SlotCarDerby, D_80100DDC_SlotCarDerby };
f32 D_80100DFC_SlotCarDerby = 0.0f;
SCDFocus D_80100E00_SlotCarDerby[9] = {
    { { -100.0f, 173.6f, 75.4f }, 0.12f }, { { 0.0f, 160.0f, 160.0f }, 0.12f },
    { { -120.0f, 180.0f, 180.0f }, 0.12f }, { { 150.0f, 200.0f, 0.0f }, 0.12f },
    { { 240.0f, 140.0f, 0.0f }, 0.12f }, { { 140.0f, 170.0f, 180.0f }, 0.12f },
    { { 0.0f, 180.0f, 75.4f }, 0.2f }, { { 80.0f, 160.0f, 40.0f }, 0.2f },
    { { -80.0f, 160.0f, 40.0f }, 0.2f },
};
s16 D_80100E90_SlotCarDerby = -1;
s16 D_80100E92_SlotCarDerby = 0;
f32 D_80100E94_SlotCarDerby = 0.0f;
f32 D_80100E98_SlotCarDerby[2] = { 0.0f, 0.0f };
s32 D_80100EA0_SlotCarDerby = 0;
s32 D_80100EA4_SlotCarDerby = 0;
s32 D_80100EA8_SlotCarDerby = 0;
s32 D_80100EAC_SlotCarDerby = 0;
s32 D_80100EB0_SlotCarDerby = 0;
s32 D_80100EB4_SlotCarDerby = 0;
s32 D_80100EB8_SlotCarDerby = 0;
s32 D_80100EBC_SlotCarDerby = 0;
Vec D_80100EC0_SlotCarDerby[2] = { { -85.0f, 183.6f, 75.4f }, { 167.0f, 183.6f, 13.0f } };
f32 D_80100ED8_SlotCarDerby[6] = { -71.0f, -39.0f, -14.0f, 18.0f, 43.0f, 68.0f };
f32 D_80100EF0_SlotCarDerby[2] = { 21.0f, -35.0f };
f32 D_80100EF8_SlotCarDerby[2] = { -55.0f, 2.0f };
Vec D_80100F00_SlotCarDerby[2] = { { -85.0f, 160.08f, 79.0f }, { 167.0f, 160.08f, 17.0f } };
s32 D_80100F18_SlotCarDerby[7] = { 0, 16, 28, 48, 60, 4, 36 };
s32 D_80100F34_SlotCarDerby[7] = { 5, 0, 0, 0, 0, 10, 11 };
s32 D_80100F50_SlotCarDerby[2] = { 0x1B, 0x1C };
s32 D_80100F58_SlotCarDerby[6] = { 30, 2, 27, 2, 27, 2 };
s32 D_80100F70_SlotCarDerby[6] = { 0, 0, 0, 0, 0, 0 };
s16 D_80100F88_SlotCarDerby[4] = { 0, 0x3000, 0x2000, 0 };

// register allocation of the D_800C59AC file-id load (masked 0)
#ifdef NON_MATCHING
void func_800F76E8_SlotCarDerby(omObjData* obj, s16 player) {
    SCDPlayerWork* work;
    unk2C0C0Struct50* head;
    s32 file;
    u32 chr;

    obj->func_ptr = func_800F7A00_SlotCarDerby;
    obj->work[0] = player;
    obj->unk_50 = func_80023684(sizeof(SCDPlayerWork), 0x7918);
    func_8009B770(obj->unk_50, 0, sizeof(SCDPlayerWork));
    work = obj->unk_50;
    work->unk_D8 = func_80023684(obj->mtncnt * 4, 0x7918); /* s16[2] per motion */
    func_8009B770(work->unk_D8, 0, obj->mtncnt * 4);
    chr = GwPlayer[player].character;
    if ((D_801024B0_SlotCarDerby == 2) & (player == 3)) {
        chr = 6;
    }
    if (chr < 6) {
        file = D_800C59AC[chr].unk_00 | D_800C59AC[chr].unk_08;
    } else {
        chr = 6;
        file = 0x70000;
    }
    obj->model[1] = LoadFormFile(file, 0x6BD);
    obj->model[0] = LoadFormFile(D_80100CD8_SlotCarDerby[chr] | 0x390000, 0x6B9);
    func_800343C8(D_800F2B7C[obj->model[1]].unk_08);
    head = func_80026A0C(obj->model[0], "head");
    D_80101FF8_SlotCarDerby[obj->work[0]] = head;
    func_80020EA0(obj->model[1], D_80100CBC_SlotCarDerby[chr], obj->model[0], "head");
    head->unk_38.y += D_80100D04_SlotCarDerby[chr][0];
    head->unk_38.z += D_80100D04_SlotCarDerby[chr][1];
    head->unk_50.x = D_80100CE8_SlotCarDerby[chr];
    head->unk_50.y = D_80100CE8_SlotCarDerby[chr];
    head->unk_50.z = D_80100CE8_SlotCarDerby[chr];
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.4f;
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80025830(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    work->unk_C0 = 0xFFFF;
    func_8001874C(obj, 0, 0x390007, 1, 0);
    D_800F2B7C[obj->model[0]].unk_08 = 0;
    work->unk_56 = GwPlayer[player].port;
    func_800F7084_SlotCarDerby(obj);
    func_800F70C4_SlotCarDerby(obj)->unk_0A = chr;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800F76E8_SlotCarDerby);
#endif
void func_800F7A00_SlotCarDerby(omObjData* obj) {
    SCDCar* car;
    s32 throttle;

    if (D_80101DF2_SlotCarDerby == 0) {
        throttle = 0;
        if (D_80101DE0_SlotCarDerby.unk_00 == 2) {
            throttle = func_800F7A7C_SlotCarDerby(obj);
        }
        func_800F8270_SlotCarDerby(obj, throttle);
        car = func_800F70C4_SlotCarDerby(obj);
        if (car->unk_76 != 0) {
            car->unk_76--;
        }
        func_80017DB0(obj);
    }
}
// register allocation; the CPU speed-step random term is computed before lvl (masked 2)
#ifdef NON_MATCHING
s32 func_800F7A7C_SlotCarDerby(omObjData* obj) {
    SCDCar* car;
    s32 throttle;
    u8 diff;
    s32 go;
    u8 lvl;
    s32 step;
    s32 k;
    s32 i;
    s32 lo;
    s32 hi;
    s32 t;
    s8 port;
    s8 x;
    s8 y;
    s32 pad[4]; /* unused: retail's frame is 16 bytes larger */

    car = func_800F70C4_SlotCarDerby(obj);
    car->unk_03 = 0;
    diff = GwPlayer[obj->work[0]].cpu_difficulty & 3;
    lvl = 4 - diff;
    port = SCD_WORK(obj)->unk_56;
    if (!(GwPlayer[obj->work[0]].flags & 1)) {
        x = ContStkX[port];
        y = ContStkY[port];
        i = func_800B1750(x * x + y * y) / 64.0f * 5.0f;
        if (i > 5) {
            i = 5;
        }
        throttle = D_80100C90_SlotCarDerby[i];
        if (throttle != 0) {
            throttle += D_80100CAC_SlotCarDerby[car->unk_05];
        }
        if (throttle > 100) {
            throttle = 100;
        }
        car->unk_03 = 1;
        if (throttle < 10 || throttle > 90) {
            rand8();
            rand8();
        }
    } else if (D_801024B0_SlotCarDerby == 0) {
        step = 1600 - lvl * 200;
        if (D_80101DE0_SlotCarDerby.unk_00 == 2) {
            throttle = car->unk_6C;
            go = 0;
            if (car->unk_6E == 0) {
                go = (s32)((u32)(((rand8() << 8) | rand8()) * 25) >> 14) < lvl * 8;
                car->unk_6A = (u32)(((rand8() << 8) | rand8()) * 25) >> 14;
            } else if (car->unk_06 == 0 && (car->unk_6E & 7) == 1) {
                go = 1;
            }
            if (go) {
                k = 10000 - (func_800F95F4_SlotCarDerby(car->unk_48 + car->unk_4C + 40.0) +
                             D_80100CAC_SlotCarDerby[car->unk_05]) * 100;
                if (k < 0) {
                    k = 0;
                }
                go = lvl + 1;
                if (go > 4) {
                    go = 4;
                }
                throttle = 9900 - ((((rand8() << 8) | rand8()) * 75) >> 14);
                throttle -= k * go / 4;
                throttle -= car->unk_6A;
            }
            if (car->unk_06 == 0) {
                car->unk_72 = lvl * 2 + (((((rand8() << 8) | rand8()) << 1) * lvl) >> 16) + car->unk_6A * 0.03;
            } else {
                if (car->unk_06 > 20 - car->unk_72) {
                    throttle = 0;
                    car->unk_6E = 0;
                }
                step = 4500 / (car->unk_72 + 1) - ((((rand8() << 8) | rand8()) * 100 * lvl) >> 16) - car->unk_6A * 0.5;
            }
            car->unk_6C = throttle;
        }
        if (car->unk_6C > car->unk_70) {
            car->unk_70 += step;
            hi = car->unk_70;
            t = car->unk_6C;
            lo = t;
        } else {
            car->unk_70 -= step;
            lo = car->unk_70;
            t = car->unk_6C;
            hi = t;
        }
        if (lo < hi) {
            car->unk_70 = t;
        }
        throttle = car->unk_70 * 0.01;
        car->unk_6E++;
    } else {
        if (car->unk_0A == 6) {
            lvl = 1;
            if (D_801024B4_SlotCarDerby != 0 && car->unk_68 < car->unk_6A * 4 + 390) {
                lvl = 2;
            }
        } else {
            lvl = 3;
            if (D_801024B4_SlotCarDerby != 0 && car->unk_68 > 600 - car->unk_6A * 2) {
                lvl = 5;
            }
        }
        if (D_80101DE0_SlotCarDerby.unk_00 == 2) {
            throttle = car->unk_6C;
            if (car->unk_06 == 0 && (car->unk_6E & 7) == 1) {
                throttle = 9800 - ((((rand8() << 8) | rand8()) * 35) >> 13);
                throttle -= lvl * 200;
                if (diff == 5) {
                    throttle -= car->unk_6A * 5;
                }
            }
            if (car->unk_68 == 0) {
                car->unk_6A = (u32)(((rand8() << 8) | rand8()) * 25) >> 14;
                if (D_801024B4_SlotCarDerby != 0 && car->unk_0A == 6) {
                    throttle = 10000;
                }
            }
            if (car->unk_06 == 0) {
                car->unk_72 = 20 - lvl * 2;
            } else if (car->unk_06 > car->unk_72) {
                throttle = 0;
                car->unk_6E = 0;
            }
            car->unk_6C = throttle;
        }
        if (car->unk_6C > car->unk_70) {
            car->unk_70 += 1700 - lvl * 200;
            if (car->unk_70 > car->unk_6C) {
                car->unk_70 = car->unk_6C;
            }
        } else {
            car->unk_70 -= 1700 - lvl * 200;
            if (car->unk_70 < car->unk_6C) {
                car->unk_70 = car->unk_6C;
            }
        }
        throttle = car->unk_70 * 0.01;
        car->unk_6E++;
        car->unk_68++;
    }
    if (throttle < 0) {
        throttle = 0;
    } else if (throttle > 100) {
        throttle = 100;
    }
    return throttle;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800F7A7C_SlotCarDerby);
#endif
void func_800F8270_SlotCarDerby(omObjData* obj, s32 throttle) {
    Matrix4f m;
    Matrix4f rm;
    Vec angles;
    Vec v;
    f32 t;
    f32 a;
    f64 speed;
    SCDCar* car;
    unk2C0C0Struct50* head;

    t = throttle * 0.01;
    car = func_800F70C4_SlotCarDerby(obj);
    if (car->unk_02 == 4) {
        if (D_80101DE0_SlotCarDerby.unk_00 == 2) {
            car->unk_02 = 1;
            car->unk_64 = car->unk_66 = 0;
        }
    }
    switch (car->unk_02) {
        case 0:
            break;
        case 1:
            func_800F88CC_SlotCarDerby(obj, t);
            break;
        case 2:
            func_800F8FF8_SlotCarDerby(obj);
            break;
        case 3:
            func_800F91B4_SlotCarDerby(obj);
            break;
        case 4:
            func_800F9554_SlotCarDerby(obj);
            break;
    }
    car->unk_64++;
    if (car->unk_00 & 0x10) {
        if ((car->unk_58 -= 24.0) < 0.0) {
            /* unk_06 and unk_07 tested together (lhu): endian-neutral against 0 */
            if (*(u16*)&car->unk_06 != 0) {
                car->unk_58 += 360.0;
            } else {
                car->unk_58 = 0.0f;
            }
        }
        if (car->unk_07 != 0) {
            a = func_800AEAC0(car->unk_58) * 45.0;
        } else {
            a = car->unk_06;
            if (a > 20.0f) {
                a = 20.0f;
            }
            a = (a + 40.0f) * func_800AEAC0(car->unk_58);
        }
        func_800A2A50(m);
        func_800A2A50(rm);
        func_8009E060(m, a + car->unk_5C, 0.0f, 1.0f, 0.0f);
        m[3][3] = 1.0f;
        func_800F9EA4_SlotCarDerby(&car->unk_30, &angles.x);
        MtxRotate(rm, angles.x, angles.y, angles.z);
        func_800AC0B0(m, rm, m);
        func_800F9FC8_SlotCarDerby(m, &car->unk_24);
        speed = car->unk_50 / 7.0 * 2.5;
        func_800F7650_SlotCarDerby(obj->model[0], speed);
        if ((((s16)car->unk_64 + car->unk_01) & 3) == 0 && car->unk_58 != 0.0f) {
            func_800F744C_SlotCarDerby(1, car);
        }
        head = D_80101FF8_SlotCarDerby[obj->work[0]];
        if (head != (unk2C0C0Struct50*)-1 && car->unk_62 == 0) {
            head->unk_44.x = car->unk_3C;
            head->unk_44.z = car->unk_44;
            func_800F96F4_SlotCarDerby(car->unk_48, car->unk_4C, car->unk_50 * 12.0f + 1.0, &v, &angles);
            v.x -= car->unk_0C.x;
            v.y -= car->unk_0C.y;
            v.z -= car->unk_0C.z;
            func_800F9EA4_SlotCarDerby(&v, &angles.x);
            a = angles.y - car->unk_24.y;
            if (a < 0.0) {
                a += 360.0;
            }
            if (a > 180.0) {
                a -= 360.0;
            }
            head->unk_44.y = a * 0.75;
            func_8009EA40(head->unk_64, head->unk_08.x, head->unk_08.y, head->unk_08.z);
            MtxRotate(head->unk_64, head->unk_44.x, head->unk_44.y, head->unk_44.z);
            MtxScale(head->unk_64, head->unk_50.x, head->unk_50.y, head->unk_50.z);
        }
    }
    if (car->unk_08 != 0) {
        D_800F2B7C[obj->model[0]].unk_20 ^= 4;
        if (--car->unk_08 == 0) {
            D_800F2B7C[obj->model[0]].unk_20 |= 4;
            D_800F2B7C[obj->model[0]].unk_0A |= 1;
            car->unk_02 = 0;
        }
    }
    obj->trans.x = car->unk_0C.x * 10.0;
    obj->trans.y = car->unk_0C.y * 10.0;
    obj->trans.z = car->unk_0C.z * 10.0;
    obj->rot.x = car->unk_24.x;
    obj->rot.y = car->unk_24.y;
    obj->rot.z = car->unk_24.z;
}
void func_800F87E4_SlotCarDerby(SCDCar* car, f32 ahead) {
    Vec a;
    Vec b;
    Vec c;
    f32 d;

    func_800F96F4_SlotCarDerby(car->unk_48, car->unk_4C, ahead, &a, &b);
    func_800F9EA4_SlotCarDerby(&car->unk_30, &a.x);
    func_800F9EA4_SlotCarDerby(&b, &c.x);
    car->unk_40 = a.y;
    d = c.y - a.y;
    if (d < 0.0f) {
        d += 360.0;
    }
    if (d > 180.0) {
        d -= 360.0;
    }
    car->unk_44 = d * 0.3;
}
// float register allocation; GCC shares the braking subtraction (masked 50)
#ifdef NON_MATCHING
void func_800F88CC_SlotCarDerby(omObjData* obj, f32 throttle) {
    Vec a;
    Vec b;
    SCDCar* car;
    f32 target;
    f32 speed;
    f32 cur;
    f32 prev;
    f32 f;
    f64 d;
    s32 lim;

    car = func_800F70C4_SlotCarDerby(obj);
    if (car->unk_62 != 0) {
        throttle = 0.1f;
        car->unk_62--;
    }
    if (SCD_CAR_FRAMES0(car)) {
        car->unk_66 = 1;
        if (throttle != 0.0f) {
            car->unk_07 = 1;
            func_800F6ED4_SlotCarDerby(car, 0x2D6);
        }
    }
    target = throttle * 7.0;
    cur = car->unk_50;
    if (cur < target) {
        speed = cur + 0.14;
        if (target < speed) {
            speed = target;
        }
    } else if (target < cur) {
        if (car->unk_60 != 0) {
            d = cur - (f32)(20 - car->unk_60) / 10.0 * 0.42;
        } else {
            d = car->unk_50 - 0.42;
        }
        speed = d;
        if (speed < target) {
            speed = target;
        }
    } else {
        speed = car->unk_50;
    }
    car->unk_50 = speed;
    target = speed;
    if (D_80101DE0_SlotCarDerby.unk_00 == 2) {
        if (car->unk_74 < 0) {
            if (car->unk_76 == 0) {
                car->unk_74 = func_80060540(0x2D8, car->unk_01);
            }
        }
        if (car->unk_74 >= 0) {
            f = speed / 7.0 - 0.2;
            if (f >= 0.0) {
                d = f / 0.8;
                d *= 1000.0;
            } else {
                d = f / 0.2;
                d *= 1400.0;
            }
            f = d - 400.0;
            func_80060440(car->unk_74, f);
        }
    }
    if (car->unk_07 != 0) {
        speed = 0.0f;
        car->unk_50 = speed;
        target = speed;
        if (++car->unk_07 >= 31) {
            car->unk_07 = 0;
        }
    }
    prev = car->unk_4C;
    car->unk_4C = func_800F96F4_SlotCarDerby(car->unk_48, prev, target, &car->unk_0C, &car->unk_30);
    if (car->unk_00 & 0x80) {
        if (D_801024B0_SlotCarDerby == 0) {
            D_800F2B7C[obj->model[0]].unk_20 ^= 4;
        }
    } else {
        if (D_80101434_SlotCarDerby * 0.9 < prev && car->unk_4C < D_80101434_SlotCarDerby * 0.1) {
            car->unk_00 |= 0x80;
            if (car->unk_04 == 0) {
                car->unk_04 = D_80102312_SlotCarDerby++;
                if (car->unk_04 == 1) {
                    D_80101DF4_SlotCarDerby = 1;
                    if (D_801024B0_SlotCarDerby != 0) {
                        if (GwPlayer[obj->work[0]].group == 0) {
                            D_801024B2_SlotCarDerby = 1;
                        }
                    } else if (!(GwPlayer[obj->work[0]].flags & 1)) {
                        D_801024B2_SlotCarDerby = 1;
                    }
                }
            }
            car->unk_06 = 0;
            D_80101DE0_SlotCarDerby.unk_0A = 60;
            D_80101DF6_SlotCarDerby += func_800FBE7C_SlotCarDerby(car->unk_01, 1);
        }
    }
    lim = func_800F95F4_SlotCarDerby(car->unk_4C + car->unk_48) + D_80100CAC_SlotCarDerby[car->unk_05];
    if (lim > 100) {
        lim = 100;
    }
    speed = lim * 7.0 / 100.0;
    if (speed < target && (((car->unk_00 & 0x80) == 0) & (throttle != 0.0f))) {
        if (car->unk_06 == 0) {
            func_80060F04(car->unk_01, 10, 0, 10);
            func_800F6ED4_SlotCarDerby(car, 0x2D6);
        } else if (!(car->unk_06 & 3)) {
            func_80060F04(car->unk_01, 2, 3, 10);
        }
        if (car->unk_06++ >= 26) {
            if (throttle > 0.0f) {
                car->unk_62 = 40;
                car->unk_5C = 0.0f;
            }
            car->unk_06 = 0;
            func_80060F04(car->unk_01, 2, 2, 20);
            func_800F6ED4_SlotCarDerby(car, 0x2DC);
        }
    } else {
        car->unk_06 = 0;
    }
    if (car->unk_06 >= 8) {
        car->unk_60 = car->unk_06 - 6;
    }
    if (car->unk_60 != 0) {
        if (--car->unk_60 < 0) {
            car->unk_60 = 0;
        }
    }
    car->unk_00 |= 0x10;
    if (car->unk_62 == 0) {
        func_800F87E4_SlotCarDerby(car, -car->unk_50 * 16.0f);
        car->unk_5C = 0.0f;
    } else {
        car->unk_40 = 0.0f;
        if ((car->unk_5C += 27.0) > 360.0f) {
            car->unk_5C -= 360.0f;
        }
        if (!(car->unk_62 & 3)) {
            func_800F744C_SlotCarDerby(1, car);
        }
    }
    func_800FA2C0_SlotCarDerby(&car->unk_0C.x, 0.2f);
    speed = car->unk_03 ? 80.0f : 20.0f;
    func_800F96F4_SlotCarDerby(car->unk_48, car->unk_4C, speed, &a, &b);
    func_800FA2C0_SlotCarDerby(&a.x, 0.2f);
    if (!(car->unk_64 & 0xF) && car->unk_50 >= 6.3) {
        func_800F744C_SlotCarDerby(0, car);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800F88CC_SlotCarDerby);
#endif
void func_800F8FF8_SlotCarDerby(omObjData* obj) {
    Vec a;
    Vec b;
    Vec c;
    SCDCar* car;
    Vec* pos;
    Vec* dir;

    car = func_800F70C4_SlotCarDerby(obj);
    D_800F2B7C[obj->model[0]].unk_20 &= ~4;
    car->unk_50 += 0.14;
    if (car->unk_50 > 7.0 * 0.8) { /* retail's constant is 5.6 + 1 ulp */
        car->unk_50 = 5.6f;
    }
    if (car->unk_74 >= 0) {
        func_8006071C(car->unk_74);
    }
    car->unk_74 = -1;
    pos = &car->unk_0C;
    dir = &car->unk_30;
    car->unk_4C = func_800F96F4_SlotCarDerby(car->unk_48, car->unk_4C, car->unk_50, pos, dir);
    func_800F87E4_SlotCarDerby(car, -car->unk_50 * 16.0f);
    car->unk_5C = 0.0f;
    if (car->unk_04 == 1) {
        func_800F96F4_SlotCarDerby(car->unk_48, car->unk_4C, car->unk_50 * 10.0f, &a, &b);
        func_800F9EA4_SlotCarDerby(dir, &a.x);
        func_800F9EA4_SlotCarDerby(&b, &c.x);
        car->unk_5C = c.y - a.y;
        func_800FA2C0_SlotCarDerby(&pos->x, 0.5f);
        if (!(car->unk_64 & 0xF)) {
            func_800F744C_SlotCarDerby(0, car);
        }
    }
    car->unk_00 |= 0x10;
}
void func_800F91B4_SlotCarDerby(omObjData* obj) {
    Vec rot;
    Vec pos;
    f32 ground;
    SCDCar* car;
    s16 i;
    s16 j;
    s16 r;

    car = func_800F70C4_SlotCarDerby(obj);
    if (SCD_CAR_FRAMES0(car)) {
        func_800FBE7C_SlotCarDerby(car->unk_01, 0);
        car->unk_04 = 4;
        car->unk_00 |= 0x40;
        func_800F6ED4_SlotCarDerby(car, 0x2D7);
        if (car->unk_74 >= 0) {
            func_8006071C(car->unk_74);
        }
        car->unk_74 = car->unk_78 = -1;
        func_80060F04(car->unk_01, 30, 0, 30);
        func_80060618(0x45F, obj->work[0]);
        car->unk_18.x = car->unk_30.x * 8.0;
        car->unk_18.y = car->unk_30.y * 8.0 + 8.0;
        car->unk_18.z = car->unk_30.z * 8.0;
    }
    for (j = 0; j < 3; j++) {
        (&car->unk_0C.x)[j] += (&car->unk_18.x)[j];
        (&rot.x)[j] = -(&car->unk_18.x)[j];
    }
    car->unk_18.y -= 1.0;
    if (car->unk_18.y < -20.0) {
        car->unk_18.y = -20.0f;
    }
    if (car->unk_18.y < 0.0f) {
        r = func_800F9A0C_SlotCarDerby(&car->unk_0C, &ground);
        if (r != 0) {
            if (r > 0) {
                car->unk_0C.y = ground;
                car->unk_18.y = 8.0f;
                rot.x = 30.0f;
                rot.y = guRandom() % 90;
                rot.z = 0.0f;
                pos.y = car->unk_0C.y;
                for (i = 0; i < 3; i++) {
                    pos.x = car->unk_0C.x + func_800AEFD0(rot.y) * 20.0f * 0.5;
                    pos.z = car->unk_0C.z + func_800AEAC0(rot.y) * 20.0f * 0.5;
                    func_800FD9E8_SlotCarDerby(1, &pos, &rot);
                    rot.y = func_8009B618(rot.y + 120.0, 360.0);
                }
            }
        } else if (car->unk_08 == 0) {
            car->unk_08 = 30;
        }
    }
    car->unk_24.y = func_8009B618(car->unk_24.y + 30.0, 360.0);
    car->unk_24.z = func_8009B618(car->unk_24.z + 15.0, 360.0);
    car->unk_00 &= ~0x10;
    if (car->unk_08 == 0) {
        func_800FA2C0_SlotCarDerby(&car->unk_0C.x, 0.2f);
    }
}
void func_800F9554_SlotCarDerby(omObjData* obj) {
    SCDCar* car = func_800F70C4_SlotCarDerby(obj);

    if (SCD_CAR_FRAMES0(car)) {
        func_800F96F4_SlotCarDerby(car->unk_48, 0.0f, 0.0f, &car->unk_0C, &car->unk_30);
        car->unk_00 |= 0x10;
    }
    car->unk_40 = car->unk_24.y;
    car->unk_3C = car->unk_44 = 0.0f;
    if (car->unk_74 < 0) {
        car->unk_74 = func_80060540(0x2D8, car->unk_01);
        func_80060440(car->unk_74, -1800);
    }
}
s32 func_800F95F4_SlotCarDerby(f32 dist) {
    u8(*p)[3];
    s32 cls;

    if (dist >= 0.0f) {
        dist = func_8009B618(dist, D_80101434_SlotCarDerby);
    } else {
        dist += D_80101434_SlotCarDerby;
    }
    if (D_80101420_SlotCarDerby == 0) {
        p = D_80100D3C_SlotCarDerby;
    } else {
        p = D_80100D5C_SlotCarDerby;
    }
    cls = 6;
    for (; (*p)[0] != 0xFF; p++) {
        if (D_80101430_SlotCarDerby[(*p)[0]] <= dist && dist < D_80101430_SlotCarDerby[(*p)[1]]) {
            cls = (*p)[2];
            break;
        }
    }
    return D_80100C90_SlotCarDerby[cls] + 1;
}
f32 func_800F96F4_SlotCarDerby(f32 start, f32 dist, f32 step, Vec* pos, Vec* dir) {
    f32 d;
    f32 at;
    f32 sum;
    f32 prev;
    f32 t;
    s16 i;
    s16 next;

    d = dist + step;
    if (d >= 0.0f) {
        d = func_8009B618(d, D_80101434_SlotCarDerby);
    } else {
        d += D_80101434_SlotCarDerby;
    }
    at = start + d;
    if (at >= 0.0f) {
        at = func_8009B618(at, D_80101434_SlotCarDerby);
    } else {
        at += D_80101434_SlotCarDerby;
    }
    sum = 0.0f;
    prev = sum;
    for (i = 0; i < D_80101428_SlotCarDerby; i++) {
        sum += D_8010142C_SlotCarDerby[i];
        if (at <= sum) {
            break;
        }
        prev = sum;
    }
    if (i >= D_80101428_SlotCarDerby) {
        i = 0;
        at -= D_80101434_SlotCarDerby;
        prev = 0.0f;
    }
    at -= prev;
    step = at / D_8010142C_SlotCarDerby[i];
    t = fabsf(step);
    if (t >= 0.5) {
        t = t - 0.5;
    } else {
        t = t + 0.5;
        i = (i != 0) ? i - 1 : D_80101428_SlotCarDerby - 1;
    }
    if (i < D_80101428_SlotCarDerby - 1) {
        next = i + 1;
    } else {
        next = 0;
    }
    prev = D_8010142C_SlotCarDerby[i] * 0.5;
    sum = prev + D_8010142C_SlotCarDerby[next] * 0.5;
    t = func_800F9B60_SlotCarDerby(t, 0.0f, prev, sum) / sum;
    func_800F9BC0_SlotCarDerby(t, &D_80101440_SlotCarDerby[i], &D_80101424_SlotCarDerby[next], &D_80101440_SlotCarDerby[next], pos);
    func_800F9CB4_SlotCarDerby(t, &D_80101440_SlotCarDerby[i], &D_80101424_SlotCarDerby[next], &D_80101440_SlotCarDerby[next], dir);
    return d;
}
// retail keeps the pos pointer increment (addiu; lwc1 0/4) where GCC folds it (masked 13)
#ifdef NON_MATCHING
s32 func_800F9A0C_SlotCarDerby(Vec* pos, f32* groundY) {
    f32 best;
    Vec* mid;
    f32* len;
    f32* p;
    f32 x, y, z;
    f32 r;
    s32 i;
    s32 hit;

    best = 30000.0f;
    mid = D_80101440_SlotCarDerby;
    len = D_8010142C_SlotCarDerby;
    p = (f32*)pos;
    x = *p++;
    y = *p++;
    z = *p;
    hit = 0;
    for (i = 0; i < D_80101428_SlotCarDerby; i++, mid++) {
        r = *len++ * 0.75;
        if (abs((s32)(mid->x - x)) < r && abs((s32)(mid->z - z)) < r) {
            hit = 1;
            if (y <= mid->y && mid->y < best) {
                best = mid->y;
            }
        }
    }
    if (hit == 0) {
        return 0;
    }
    if (best == 30000.0f) {
        return -1;
    }
    *groundY = best;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800F9A0C_SlotCarDerby);
#endif
f32 func_800F9B60_SlotCarDerby(f32 t, f32 a, f32 b, f32 c) {
    f32 u = 1.0 - t;

    return u * u * a + 2.0 * (u * t * b) + t * t * c;
}
void func_800F9BC0_SlotCarDerby(f32 t, Vec* a, Vec* b, Vec* c, Vec* out) {
    f32* pa = (f32*)a;
    f32* pb = (f32*)b;
    f32* pc = (f32*)c;
    f32* po = (f32*)out;
    s32 i;

    for (i = 0; i < 3; i++) {
        *po++ = func_800F9B60_SlotCarDerby(t, *pa++, *pb++, *pc++);
    }
}
f32 func_800F9C5C_SlotCarDerby(f32 t, f32 a, f32 b, f32 c) {
    return 2.0 * ((t - 1.0) * a + (1.0 - 2.0 * t) * b + t * c);
}
void func_800F9CB4_SlotCarDerby(f32 t, Vec* a, Vec* b, Vec* c, Vec* out) {
    f32 d[3];
    f32* pa = (f32*)a;
    f32* pb = (f32*)b;
    f32* pc = (f32*)c;
    f32* po = (f32*)out;
    f32 len;
    s32 i;

    for (i = 0; i < 3; i++) {
        d[i] = func_800F9C5C_SlotCarDerby(t, *pa++, *pb++, *pc++);
    }
    len = sqrtf(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]);
    if (len != 0.0f) {
        for (i = 0; i < 3; i++) {
            *po++ = (f32)(1.0 / len) * d[i];
        }
        return;
    }
    *po++ = 0.0f;
    *po++ = 0.0f;
    *po = 1.0f;
}
f32 func_800F9E24_SlotCarDerby(f32 x, f32 y) {
    f32 a = func_800B0CD8(y, x);

    if (a < 0.0) {
        a += 360.0;
    } else if (a >= 360.0) {
        a -= 360.0;
    }
    return a;
}
void func_800F9EA4_SlotCarDerby(Vec* dir, f32* angles) {
    f32 h = sqrtf(dir->x * dir->x + dir->z * dir->z);

    *angles++ = func_800F9E24_SlotCarDerby(h, -dir->y);
    *angles++ = func_800F9E24_SlotCarDerby(dir->z, dir->x);
    *angles = 0.0f;
}
void func_800F9F2C_SlotCarDerby(Matrix4f m, f32 x, f32 y, f32 z, f32* o) {
    *o++ = x * m[0][0] + y * m[1][0] + z * m[2][0] + m[3][0];
    *o++ = x * m[0][1] + y * m[1][1] + z * m[2][1] + m[3][1];
    *o = x * m[0][2] + y * m[1][2] + z * m[2][2] + m[3][2];
}
void func_800F9FC8_SlotCarDerby(Matrix4f m, Vec* angles) {
    f32 s;
    f32 c;
    f64 t;

    angles->x = func_800F9E24_SlotCarDerby(m[2][2], m[1][2]);
    angles->z = func_800F9E24_SlotCarDerby(m[0][0], m[0][1]);
    s = -m[0][2];
    t = 1.0 - s * s;
    if (t < 0.0) {
        t = -t;
    }
    c = sqrtf(t);
    if (angles->x > 90.0 && angles->x < 270.0 && angles->z > 90.0 && angles->z < 270.0) {
        angles->x = func_8009B618(angles->x + 180.0, 360.0);
        angles->z = func_8009B618(angles->z + 180.0, 360.0);
        c = -c;
    }
    angles->y = func_800F9E24_SlotCarDerby(c, s);
}

void func_800FA154_SlotCarDerby(void) {
    f32* tbl[2];
    f32* p;
    SCDCamera* cam;
    SCDCamPose* cur;
    f32 d;
    f32 sum;

    tbl[0] = D_80100D94_SlotCarDerby;
    tbl[1] = D_80100DAC_SlotCarDerby;
    D_800C3110->unk_40 = 45.0f;
    D_800C3110->unk_44 = 80.0f;
    D_800C3110->unk_48 = 16000.0f;
    D_800C3110->unk18.x = D_800C3110->unk18.z = 0.0f;
    D_800C3110->unk18.y = 1.0f;
    cam = &D_80102420_SlotCarDerby;
    p = tbl[D_80101420_SlotCarDerby];
    cam->target.pos[0] = D_80102420_SlotCarDerby.cur.pos[0] = *p++;
    cam->target.pos[1] = D_80102420_SlotCarDerby.cur.pos[1] = *p++;
    cam->target.pos[2] = D_80102420_SlotCarDerby.cur.pos[2] = *p++;
    cam->target.view[0] = D_80102420_SlotCarDerby.cur.view[0] = *p++;
    cam->target.view[1] = D_80102420_SlotCarDerby.cur.view[1] = *p++;
    cam->target.view[2] = D_80102420_SlotCarDerby.cur.view[2] = *p;
    cur = &cam->cur;
    d = cur->view[0] - cur->pos[0];
    sum = d * d;
    d = cur->view[1] - cur->pos[1];
    sum += d * d;
    d = cur->view[2] - cur->pos[2];
    sum += d * d;
    cam->target.zoom = cur->zoom = sqrtf(sum);
    D_80102318_SlotCarDerby = 0;
}
void func_800FA2C0_SlotCarDerby(f32* pos, f32 weight) {
    if (D_80102318_SlotCarDerby < 16) {
        D_80102320_SlotCarDerby[D_80102318_SlotCarDerby].pos.x = *pos++;
        D_80102320_SlotCarDerby[D_80102318_SlotCarDerby].pos.y = *pos++;
        D_80102320_SlotCarDerby[D_80102318_SlotCarDerby].pos.z = *pos;
        D_80102320_SlotCarDerby[D_80102318_SlotCarDerby].weight = weight;
        D_80102318_SlotCarDerby++;
    }
}
void func_800FA32C_SlotCarDerby(s32 x, s32 y, s32 z, s32 weight) {
    Vec v;

    v.x = x * 0.01;
    v.y = y * 0.01;
    v.z = z * 0.01;
    func_800FA2C0_SlotCarDerby(&v.x, weight * 0.01);
}
// register allocation: ease not in f26, so 1.0 is hoisted out of the zoom loop (masked 14)
#ifdef NON_MATCHING
void func_800FA3B4_SlotCarDerby(Vec* look) {
    f32 max[3];
    f32 min[3];
    Matrix4f mtx;
    f32 out[3];
    f32 up[3];
    SCDCamera* cam;
    SCDCamPose* cur;
    s32 i;
    s32 j;
    s32 n;
    f64 t;
    f32 best;
    f32 ease;
    f32 d;
    f32* p;
    f32* pmax;
    f32* pmin;

    ease = 0.0f;
    cam = &D_80102420_SlotCarDerby;
    cam->target.view[0] = look->x;
    cam->target.view[1] = look->y;
    cam->target.view[2] = look->z;
    up[0] = up[2] = ease;
    up[1] = 1.0f;
    cur = &cam->cur;
    if (D_80102318_SlotCarDerby != 0) {
        for (i = 0; i < 3; i++) {
            max[i] = -30000.0f;
            min[i] = 30000.0f;
        }
        for (i = 0; i < D_80102318_SlotCarDerby; i++) {
            pmax = max;
            pmin = min;
            for (j = 0, p = &D_80102320_SlotCarDerby[i].pos.x; j < 3; j++, pmax++, pmin++) {
                if (p[j] > *pmax) {
                    *pmax = p[j];
                }
                if (p[j] < *pmin) {
                    *pmin = p[j];
                }
            }
        }
        if (D_80101DE0_SlotCarDerby.unk_00 == 3) {
            cam->target.view[1] = 300.0 - cam->target.pos[2] / 1.5;
        }
        for (i = 0; i < 3; i++) {
            cam->target.pos[i] = min[i] + (max[i] - min[i]) * 0.5;
            cam->target.view[i] -= cam->target.pos[i];
        }
        if (D_80101DE0_SlotCarDerby.unk_00 == 2) {
            cam->target.view[0] = 0.0f;
        }
        for (i = 0; i < D_80102318_SlotCarDerby; i++) {
            for (j = 0, p = &D_80102320_SlotCarDerby[i].pos.x; j < 3; j++) {
                p[j] -= cam->target.pos[j];
            }
        }
        HuGuLookAtF(mtx, cam->target.view[0], cam->target.view[1], cam->target.view[2], 0.0f, 0.0f, 0.0f, up[0],
                    up[1], up[2]);
        best = mtx[3][0] = mtx[3][1] = mtx[3][2] = 0.0f;
        t = func_800AEAC0(D_800C3110->unk_40 * 0.5) / func_800AEFD0(D_800C3110->unk_40 * 0.5);
        for (i = 0; i < D_80102318_SlotCarDerby; i++) {
            func_800F9F2C_SlotCarDerby(mtx, D_80102320_SlotCarDerby[i].pos.x, D_80102320_SlotCarDerby[i].pos.y,
                                       D_80102320_SlotCarDerby[i].pos.z, out);
            max[0] = fabs(fabs(out[0]) / t) + out[2];
            max[1] = fabs(fabs(out[1]) / t) + out[2];
            d = (max[1] <= max[0]) ? max[0] : max[1];
            max[2] = d * (1.0 - d / 6000.0 * 0.3);
            if (best < max[2]) {
                best = max[2];
            }
        }
        best *= 1.1111111111111112;
        if (best > 600.0) {
            best = 600.0f;
        } else if (best < 40.0) {
            best = 40.0f;
        }
        cam->target.zoom = best;
    } else {
        p = D_80100DF4_SlotCarDerby[D_80101420_SlotCarDerby];
        cam->target.pos[0] = *p++;
        cam->target.pos[1] = *p++;
        cam->target.pos[2] = *p++;
        cam->target.view[0] = *p++;
        cam->target.view[1] = *p++;
        cam->target.view[2] = *p;
        ease = (cam->target.view[0] - cam->target.pos[0]) * (cam->target.view[0] - cam->target.pos[0]);
        ease += (cam->target.view[1] - cam->target.pos[1]) * (cam->target.view[1] - cam->target.pos[1]);
        ease += (cam->target.view[2] - cam->target.pos[2]) * (cam->target.view[2] - cam->target.pos[2]);
        cam->target.zoom = sqrtf(ease);
    }
    D_80100DFC_SlotCarDerby += 0.002;
    if (D_80100DFC_SlotCarDerby > 0.075) {
        D_80100DFC_SlotCarDerby = 0.075f;
    }
    ease = D_80100DFC_SlotCarDerby;
    n = 0;
    for (i = 0; i < D_80102318_SlotCarDerby; i++) {
        if (D_80102320_SlotCarDerby[i].weight != 0.0f) {
            ease += D_80102320_SlotCarDerby[i].weight;
        }
        n++;
    }
    if (n != 0) {
        ease /= n;
    }
    for (i = 0; i < 3; i++) {
        cur->pos[i] = (cam->target.pos[i] - cur->pos[i]) * ease + cur->pos[i];
        cur->view[i] = (cam->target.view[i] - cur->view[i]) * ease + cur->view[i];
    }
    cur->zoom = (cam->target.zoom - cur->zoom) * ease + cur->zoom;
    CZoom = cur->zoom * 10.0;
    func_800F9EA4_SlotCarDerby((Vec*)cur->view, &CRot.x);
    Center.x = cur->pos[0] * 10.0;
    Center.y = cur->pos[1] * 10.0;
    Center.z = cur->pos[2] * 10.0;
    D_80102318_SlotCarDerby = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800FA3B4_SlotCarDerby);
#endif
void func_800FAACC_SlotCarDerby(void) {
    SCDParticle* p;
    s32 i;
    s32 sprite;
    s32 group;
    void* data;

    for (i = 0; i < 16; i++) {
        D_80102008_SlotCarDerby[i].unk_00 = 0;
    }
    data = DataRead(0x39001A);
    sprite = func_800678A4(data);
    DataClose(data);
    group = func_80064EF4(16, 0);
    for (p = D_80102008_SlotCarDerby, i = 0; i < 16; i++, p++) {
        func_80067208(group, i, sprite, 0);
        func_800672B0(group, i, 0);
        func_800671DC(group, i, i & 3);
        func_8006752C(group, i, 0xE8);
        func_800674BC(group, i, 0x9008);
        p->unk_00 = -0x7FFF;
        p->unk_02 = sprite;
        p->unk_04 = group;
        p->unk_06 = i;
    }
}
void func_800FAC28_SlotCarDerby(void) {
    SCDParticle* p;
    s32 i;
    f32 s;

    for (p = D_80102008_SlotCarDerby, i = 0; i < 16; i++, p++) {
        if (p->unk_00 != 0) {
            p->unk_00 &= 1;
            p->unk_0C = 160.0 - (f32)(((((rand8() << 8) | rand8())) >> 8) - 128);
            p->unk_10 = 200.0 - (f32)(((((rand8() << 8) | rand8())) >> 10) - 32);
            p->unk_18 = -(f32)(((((rand8() << 8) | rand8()) * 75) >> 13) + 200) * 0.01;
            p->unk_24 = (f32)((((rand8() << 8) | rand8()) * 75) >> 14) * 0.01;
            s = (f32)((((rand8() << 8) | rand8()) * 15) >> 13) * 0.01 + 0.8;
            p->unk_1C = p->unk_20 = p->unk_28 = s;
            p->unk_08 = 0;
            p->unk_0A = (((rand8() << 8) | rand8()) * 45) >> 13;
            func_80066DC4(p->unk_04, p->unk_06, p->unk_0C, p->unk_10);
            func_80067354(p->unk_04, p->unk_06, p->unk_1C, p->unk_20);
            func_80067480(p->unk_04, p->unk_06, 0x8000);
        }
    }
}
void func_800FAE98_SlotCarDerby(void) {
    SCDParticle* p;
    s32 i;

    for (p = D_80102008_SlotCarDerby, i = 0; i < 16; i++, p++) {
        if (p->unk_00 > 0) {
            p->unk_0C += func_800AEAC0(p->unk_0A) * p->unk_24;
            p->unk_10 += p->unk_18;
            p->unk_1C = p->unk_20 = p->unk_28;
            func_80066DC4(p->unk_04, p->unk_06, p->unk_0C, p->unk_10);
            func_80067354(p->unk_04, p->unk_06, p->unk_1C, p->unk_20);
            p->unk_0A = (p->unk_0A + 2) % 360;
            if (p->unk_10 < -100.0) {
                p->unk_00 |= 0x8000;
                func_800674BC(p->unk_04, p->unk_06, 0x8000);
            }
            p->unk_08++;
        }
    }
}
void func_800FB004_SlotCarDerby(omObjData* obj) {
    s32 ids[2][2] = { { 8, 9 }, { 10, 11 } };
    void* data;
    s16 sprite;
    s32 group;

    obj->func_ptr = NULL;
    data = DataRead(0x390013);
    sprite = func_800678A4(data);
    DataClose(data);
    group = func_80064EF4(1, 0);
    func_80067208(group, 0, sprite, 0);
    func_80066DC4(group, 0, 160, 120);
    func_800674BC(group, 0, 0x4000);
    obj->model[0] = func_800174C0(ids[D_80101420_SlotCarDerby][0] | 0x390000, 0x2B9);
    obj->model[1] = func_800174C0(ids[D_80101420_SlotCarDerby][1] | 0x390000, 0x299);
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 2.0f;
    func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80025798(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80025830(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    func_80025830(obj->model[1], obj->scale.x, obj->scale.y, obj->scale.z);
}
void func_800FB1C0_SlotCarDerby(void) {
    func_800FBE20_SlotCarDerby(5);
    D_80101DE0_SlotCarDerby.unk_00 = 0;
    D_80101DE0_SlotCarDerby.unk_06 = 0;
    D_80101DE0_SlotCarDerby.unk_08 = 3600;
    D_80101DE0_SlotCarDerby.unk_0C = 0;
    func_800FBE20_SlotCarDerby(0);
    func_800F6AEC_SlotCarDerby();
    func_800F6D90_SlotCarDerby();
    func_800FA154_SlotCarDerby();
    func_800FAACC_SlotCarDerby();
    func_800FAC28_SlotCarDerby();
}
void func_800FB228_SlotCarDerby(void) {
    SCDCar* car;
    SCDCar* other;
    s32 i;
    s32 j;
    s16 most = 0;

    if (!(D_80101DE0_SlotCarDerby.unk_06 & 0xF)) {
        for (car = D_80101DF8_SlotCarDerby, i = 0; i < 4; i++, car++) {
            car->unk_05 = 0;
            if ((car->unk_00 & 1) && car->unk_04 == 0) {
                for (other = D_80101DF8_SlotCarDerby, j = 0; j < 4; j++, other++) {
                    if ((other->unk_00 & 1) && other->unk_04 == 0 && car->unk_4C < other->unk_4C) {
                        car->unk_05++;
                    }
                }
            }
            if (car->unk_03 != 0) {
                s16 n = car->unk_05;

                if (most < n) {
                    most = n;
                }
            }
        }
        D_80101DE0_SlotCarDerby.unk_0C = most;
    }
}

// branch layout of the car-count loop and one base register in state 1 (masked ~8)
#ifdef NON_MATCHING
void func_800FB2FC_SlotCarDerby(s32 x, s32 y, s32 z) {
    s16 unused[16]; /* retail stores [1] and [9] before func_80060468 and never reads them */
    Vec v;
    SCDCar* car;
    s32 c;
    s32 i;
    s32 j;
    s32 t;
    s32 player;
    s32 lost;
    s16 alive;
    s16 winner;
    s32 mes;

    v.x = x;
    v.y = y;
    v.z = z;
    c = D_80101420_SlotCarDerby * 3;
    switch (D_80101DE0_SlotCarDerby.unk_00) {
        case 0:
            if (D_80101DE0_SlotCarDerby.unk_06 == 1) {
                D_80101DE0_SlotCarDerby.unk_0A = 0;
                D_80100E92_SlotCarDerby = 0;
                func_80060128(0x3D);
                func_80021E58();
                SetFadeInTypeAndTime(0, 16);
            }
            if (D_80100E90_SlotCarDerby < 0) {
                D_80100E90_SlotCarDerby = PlaySound(0x1BB);
                D_80101DF4_SlotCarDerby = 0;
            }
            if (D_80100E94_SlotCarDerby > 0.0) {
                func_800FA2C0_SlotCarDerby(&D_80100E00_SlotCarDerby[c].pos.x,
                                           D_80100E00_SlotCarDerby[c].weight * D_80100E94_SlotCarDerby);
                func_800FA2C0_SlotCarDerby(&D_80100E00_SlotCarDerby[c + 1].pos.x,
                                           D_80100E00_SlotCarDerby[c + 1].weight * D_80100E94_SlotCarDerby);
            }
            v.x = D_80100E00_SlotCarDerby[c + 2].pos.x;
            v.y = D_80100E00_SlotCarDerby[c + 2].pos.y;
            v.z = D_80100E00_SlotCarDerby[c + 2].pos.z;
            if (D_80101DE0_SlotCarDerby.unk_06 == 60) {
                D_80100E94_SlotCarDerby = 0.01f;
            } else if (D_80101DE0_SlotCarDerby.unk_06 >= 81) {
                D_80101DE0_SlotCarDerby.unk_00 = 1;
                D_80101DE0_SlotCarDerby.unk_06 = 0;
                D_80101DE0_SlotCarDerby.unk_04 = -1;
                D_80101DE0_SlotCarDerby.unk_02 = 3;
                func_800FBE20_SlotCarDerby(1);
            }
            break;
        case 1:
            func_800FA2C0_SlotCarDerby(&D_80100E00_SlotCarDerby[c].pos.x,
                                       D_80100E00_SlotCarDerby[c].weight * D_80100E94_SlotCarDerby);
            func_800FA2C0_SlotCarDerby(&D_80100E00_SlotCarDerby[c + 1].pos.x,
                                       D_80100E00_SlotCarDerby[c + 1].weight * D_80100E94_SlotCarDerby);
            v.x = D_80100E00_SlotCarDerby[c + 2].pos.x;
            v.y = D_80100E00_SlotCarDerby[c + 2].pos.y;
            v.z = D_80100E00_SlotCarDerby[c + 2].pos.z;
            if (D_80101DE0_SlotCarDerby.unk_06 >= 31) {
                D_80101DE0_SlotCarDerby.unk_02--;
                D_80101DE0_SlotCarDerby.unk_06 = 0;
                if (D_80101DE0_SlotCarDerby.unk_02 == 0) {
                    D_80101DE0_SlotCarDerby.unk_00 = 2;
                    func_800FBE20_SlotCarDerby(2);
                    D_80101DE0_SlotCarDerby.unk_0A = 60;
                    D_80101DE0_SlotCarDerby.unk_0C = 0;
                    PlaySound(0x2D5);
                    func_80060128(0x26);
                } else {
                    PlaySound(0x2D4);
                }
            }
            if (D_80101DE0_SlotCarDerby.unk_02 == 1 && D_80101DE0_SlotCarDerby.unk_06 == 0) {
                GMesCreate(13);
            }
            break;
        case 2:
            if (D_80101DF0_SlotCarDerby == 0) {
                if (--D_80101DE0_SlotCarDerby.unk_08 < 301) {
                    if (D_80101DE0_SlotCarDerby.unk_08 == 300) {
                        GMesCreate(8, 300, 160, 32);
                    }
                    func_80079078((D_80101DE0_SlotCarDerby.unk_08 + 29) / 30);
                }
                if (D_80101DE0_SlotCarDerby.unk_0A != 0) {
                    for (i = 0; i < 3; i++) {
                        func_800FA2C0_SlotCarDerby(&(&D_80100E60_SlotCarDerby)[i].pos.x,
                                                   D_80100E00_SlotCarDerby[i + 6].weight);
                    }
                    if (D_801024B0_SlotCarDerby == 0) {
                        D_80101DE0_SlotCarDerby.unk_0A--;
                    }
                }
                i = 0;
                func_800F70DC_SlotCarDerby();
                func_800FB228_SlotCarDerby();
                car = D_80101DF8_SlotCarDerby;
                lost = 0;
                alive = 0;
                winner = -1;
                for (; i < 4; i++, car++) {
                    if (!(car->unk_00 & 1)) {
                        continue;
                    }
                    if (car->unk_04 == 0 && !(car->unk_00 & 0x40)) {
                        alive++;
                        continue;
                    }
                    if (car->unk_04 == 1) {
                        winner = i;
                        continue;
                    }
                    if (D_801024B0_SlotCarDerby != 0) {
                        if (GwPlayer[car->unk_7C->work[0]].group == 0) {
                            lost = 1;
                            continue;
                        }
                    }
                }
                if (lost == 1) {
                    alive = 0;
                }
                if (winner >= 0) {
                    D_80101DE0_SlotCarDerby.unk_04 = winner;
                    for (i = 0, car = D_80101DF8_SlotCarDerby; i < 4; i++, car++) {
                        if ((car->unk_00 & 1) && car->unk_02 == 1) {
                            car->unk_02 = 2;
                            car->unk_06 = 0;
                            car->unk_64 = car->unk_66 = 0;
                            if (car->unk_04 == 1) {
                                GwPlayer[car->unk_7C->work[0]].coins_mg += 10;
                            }
                        }
                    }
                    func_800601D4(90);
                    if (D_801024B0_SlotCarDerby == 0) {
                        PlaySound(0x1BD);
                        D_80101DE0_SlotCarDerby.unk_00 = 3;
                    } else {
                        D_80101DE0_SlotCarDerby.unk_00 = 7;
                        if (D_801024B2_SlotCarDerby == 0) {
                            GMesCreate(2);
                        }
                    }
                    D_80101DE0_SlotCarDerby.unk_06 = 0;
                    func_800FBE20_SlotCarDerby(D_80101DE0_SlotCarDerby.unk_00);
                    if (D_80101DE0_SlotCarDerby.unk_08 < 301) {
                        func_800790C0();
                    }
                } else if (D_80101DE0_SlotCarDerby.unk_08 <= 0 || alive == 0) {
                    func_800601D4(90);
                    D_80101DE0_SlotCarDerby.unk_00 = 7;
                    D_80101DE0_SlotCarDerby.unk_06 = 0;
                    mes = 2;
                    if (D_801024B0_SlotCarDerby == 0) {
                        mes = 0x11;
                    }
                    GMesCreate(mes);
                    for (j = 0; j < 4; j++) {
                        func_800F6ED4_SlotCarDerby(&D_80101DF8_SlotCarDerby[j], -1);
                        func_800FBE7C_SlotCarDerby(D_80101DF8_SlotCarDerby[j].unk_01, 0);
                    }
                }
            }
            break;
        case 3:
            if (D_80101DF0_SlotCarDerby == 0) {
                func_800F70DC_SlotCarDerby();
                if (D_80100E92_SlotCarDerby == 0) {
                    if (GMesStatAllGet() == 2 || D_80101DE0_SlotCarDerby.unk_06 == 100) {
                        if (D_80101DF6_SlotCarDerby != 0) {
                            D_80100E92_SlotCarDerby = 48;
                            mes = 0x37;
                        } else {
                            D_80100E92_SlotCarDerby = 36;
                            mes = 0x33;
                        }
                        func_80060128(mes);
                        for (j = 0; j < 4; j++) {
                            if (D_80101DF8_SlotCarDerby[j].unk_04 == 1) {
                                GMesCreate(4, GwPlayer[D_80101DF8_SlotCarDerby[j].unk_7C->work[0]].character);
                                break;
                            }
                        }
                        D_80101DE0_SlotCarDerby.unk_06 = 101;
                    }
                } else if (--D_80100E92_SlotCarDerby == 0) {
                    for (j = 0; j < 4; j++) {
                        if (D_80101DF8_SlotCarDerby[j].unk_04 == 1) {
                            break;
                        }
                    }
                    player = D_80101DF8_SlotCarDerby[j].unk_7C->work[0];
                    unused[1] = player;
                    unused[9] = j;
                    func_80060468(0x451, GwPlayer[player].character);
                    D_80101DE0_SlotCarDerby.unk_00 = 4;
                    D_80101DE0_SlotCarDerby.unk_06 = 233;
                }
                if (D_80101DE0_SlotCarDerby.unk_0A != 0) {
                    for (i = 0; i < 3; i++) {
                        func_800FA2C0_SlotCarDerby(&(&D_80100E60_SlotCarDerby)[i].pos.x,
                                                   D_80100E00_SlotCarDerby[i + 6].weight);
                    }
                    D_80101DE0_SlotCarDerby.unk_0A--;
                }
            }
            break;
        case 7:
            func_800F70DC_SlotCarDerby();
            for (i = 0; i < 3; i++) {
                func_800FA2C0_SlotCarDerby(&(&D_80100E60_SlotCarDerby)[i].pos.x, D_80100E00_SlotCarDerby[i + 6].weight);
            }
            if ((D_80101DE0_SlotCarDerby.unk_06 < 300 && GMesStatAllGet() == 2) ||
                (D_801024B0_SlotCarDerby != 0 && D_80101DE0_SlotCarDerby.unk_06 == 90)) {
                if (D_801024B0_SlotCarDerby == 0) {
                    D_80100E92_SlotCarDerby = 90;
                    func_80060128(0x34);
                } else {
                    if (D_80101DE0_SlotCarDerby.unk_06 == 90) {
                        D_80100E92_SlotCarDerby = 10;
                    } else {
                        D_80100E92_SlotCarDerby = 60;
                    }
                }
                D_80101DE0_SlotCarDerby.unk_06 = 300;
            }
            if (D_80100E92_SlotCarDerby != 0) {
                if (--D_80100E92_SlotCarDerby == 0) {
                    D_80101DEE_SlotCarDerby = 1;
                }
            }
            break;
        case 4:
            if (D_80101DE0_SlotCarDerby.unk_06 == 300) {
                D_80101DEE_SlotCarDerby = 1;
            }
            break;
    }
    D_80101DE0_SlotCarDerby.unk_06++;
    if (D_80100E94_SlotCarDerby > 0.0 && D_80100E94_SlotCarDerby < 1.0) {
        D_80100E94_SlotCarDerby += 0.05;
    }
    if (D_80100E90_SlotCarDerby >= 0 && D_80101DF4_SlotCarDerby > 0 && D_80101DF4_SlotCarDerby < 16) {
        func_8006035C(D_80100E90_SlotCarDerby, D_80101DF5_SlotCarDerby + 110);
        func_80060440(D_80100E90_SlotCarDerby, D_80101DF4_SlotCarDerby * 33);
        D_80101DF4_SlotCarDerby++;
    }
    func_800FA3B4_SlotCarDerby(&v);
    func_800FAE98_SlotCarDerby();
    if (D_800F5144 == 1) {
        D_80101DEE_SlotCarDerby = 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800FB2FC_SlotCarDerby);
#endif
void func_800FBDFC_SlotCarDerby(void) {
    func_80060198();
    func_800FBE20_SlotCarDerby(6);
}
void func_800FBE20_SlotCarDerby(s16 state) {
    D_80100EA0_SlotCarDerby = state;
    if (state == 6) {
        func_801001F8_SlotCarDerby();
        HuMemDirectFree(D_80102468_SlotCarDerby);
        HuMemDirectFree(D_8010246C_SlotCarDerby);
        HuMemDirectFree(D_80102470_SlotCarDerby);
    }
}
s32 func_800FBE7C_SlotCarDerby(u8 player, s16 crossed) {
    if (crossed != 0 && D_80100EA4_SlotCarDerby == 0) {
        D_80100EA4_SlotCarDerby = 1;
    }
    if (D_80100EB0_SlotCarDerby < D_80100EB4_SlotCarDerby && D_801024B2_SlotCarDerby != 0) {
        D_80100EB8_SlotCarDerby = 1;
    }
    return D_80100EB8_SlotCarDerby;
}
/* Clears a scenery record (func_800FBEE0, func_800FC394). */
#define SCD_OBJ_CLEAR(o)                                                                         \
    {                                                                                            \
        (o)->unk_00 = 0;                                                                         \
        (o)->unk_02 = 0;                                                                         \
        (o)->unk_08 = 0;                                                                         \
        (o)->unk_0C = 0;                                                                         \
        (o)->unk_10.x = (o)->unk_10.y = (o)->unk_10.z = 0.0f;                                    \
        (o)->unk_1C.x = (o)->unk_1C.y = (o)->unk_1C.z = 0.0f;                                    \
        (o)->unk_28.x = (o)->unk_28.y = (o)->unk_28.z = 0.0f;                                    \
        (o)->unk_40[0] = (o)->unk_40[1] = (o)->unk_40[2] = (o)->unk_40[3] = 0;                   \
        (o)->unk_40[4] = (o)->unk_40[5] = (o)->unk_40[6] = (o)->unk_40[7] = 0;                   \
        (o)->unk_40[8] = (o)->unk_40[9] = (o)->unk_40[10] = (o)->unk_40[11] = 0;                 \
        (o)->unk_40[12] = (o)->unk_40[13] = (o)->unk_40[14] = (o)->unk_40[15] = 0;               \
    }

void func_800FBEE0_SlotCarDerby(s16 course) {
    s32 i;
    SCDObj* o;

    D_800F2AF8[D_800ED440++] = omAddObj(10, 5, 8, -1, func_800FC0BC_SlotCarDerby);
    D_800F2AF8[D_800ED440++] = omAddObj(11, 0, 0, -1, func_800FC394_SlotCarDerby);
    D_800F2AF8[D_800ED440++] = omAddObj(12, 0, 0, -1, func_800FCD6C_SlotCarDerby);
    D_80102468_SlotCarDerby = HuMemDirectMalloc(16 * sizeof(SCDObj));
    for (i = 0; i < 16; i++) {
        o = &D_80102468_SlotCarDerby[i];
        o->unk_00 = 0;
        o->unk_02 = 0;
        o->unk_08 = 0;
        o->unk_0C = 0;
        o->unk_10.x = o->unk_10.y =
            o->unk_10.z = 0.0f;
        o->unk_1C.x = o->unk_1C.y =
            o->unk_1C.z = 0.0f;
        o->unk_28.x = o->unk_28.y =
            o->unk_28.z = 0.0f;
        o->unk_40[0] = o->unk_40[1] =
            o->unk_40[2] = o->unk_40[3] = 0;
        o->unk_40[4] = o->unk_40[5] =
            o->unk_40[6] = o->unk_40[7] = 0;
        o->unk_40[8] = o->unk_40[9] =
            o->unk_40[10] = o->unk_40[11] = 0;
        o->unk_40[12] = o->unk_40[13] =
            o->unk_40[14] = o->unk_40[15] = 0;
    }
    func_800FE138_SlotCarDerby(48);
    func_800FFD18_SlotCarDerby();
    D_80100EAC_SlotCarDerby = course;
    if (D_801024B0_SlotCarDerby == 2) {
        D_80100EBC_SlotCarDerby = 1;
    }
}
void func_800FC0BC_SlotCarDerby(omObjData* obj) {
    SCDPlayerWork* w;

    obj->func_ptr = func_800FCF50_SlotCarDerby;
    omSetStatBit(obj, 0xA0);
    if (D_80100EBC_SlotCarDerby == 0) {
        obj->model[0] = LoadFormFile(0x70000, 0x499);
        obj->model[1] = func_800174C0(0x39000D, 0x489);
    } else {
        obj->model[0] = LoadFormFile(0x70000, 0x49D);
        obj->model[1] = func_800174C0(0x39000D, 0x48D);
    }
    obj->model[4] = func_800174C0(0x39000C, 0x99);
    obj->model[2] = func_800174C0(0x39000E, 0x49D);
    obj->model[3] = func_800174C0(0x39000F, 0x49D);
    func_80026040(obj->model[1]);
    func_80025EB4(obj->model[1], 2, 2);
    obj->unk_50 = func_80023684(sizeof(SCDPlayerWork), 0x7918);
    func_8009B770(obj->unk_50, 0, sizeof(SCDPlayerWork));
    w = SCD_WORK(obj);
    w->unk_D8 = func_80023684(obj->mtncnt * sizeof(SCDPlayerWork), 0x7918);
    func_8009B770(w->unk_D8, 0, obj->mtncnt * sizeof(SCDPlayerWork));
    w->unk_C0 = 0xFFFF;
    func_8001874C(obj, 0, 0x390011, 1, 0);
    func_8001874C(obj, 1, 0x390012, 1, 0);
    obj->trans.x = D_80100EC0_SlotCarDerby[D_80100EAC_SlotCarDerby].x * 10.0;
    obj->trans.y = D_80100EC0_SlotCarDerby[D_80100EAC_SlotCarDerby].y * 10.0;
    obj->trans.z = D_80100EC0_SlotCarDerby[D_80100EAC_SlotCarDerby].z * 10.0;
    obj->scale.x = obj->scale.y = obj->scale.z = 2.0f;
    func_80025798(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80025830(obj->model[1], obj->scale.x, obj->scale.y, obj->scale.z);
    func_80025798(obj->model[4], obj->trans.x, obj->trans.y - 240.0, obj->trans.z - 40.0);
    func_80025830(obj->model[4], obj->scale.x, obj->scale.y, obj->scale.z);
    func_800FDD08_SlotCarDerby(obj, D_80102468_SlotCarDerby);
}
// register allocation; one extra copy of the colon sprite id (masked ~6)
#ifdef NON_MATCHING
void func_800FC394_SlotCarDerby(omObjData* obj) {
    SCDObj* rec;
    SCDObj* o;
    s32 digit;
    s32 colon;
    void* data;
    s32* px;
    s32 t;
    s32 i;
    s32 sprite;

    obj->func_ptr = func_800FD2C4_SlotCarDerby;
    rec = &D_80102468_SlotCarDerby[1];
    func_800FDD08_SlotCarDerby(obj, rec);
    t = func_800594FC(D_80100EAE_SlotCarDerby + 1);
    D_80100EB4_SlotCarDerby = t;
    D_80100F34_SlotCarDerby[4] = (t % 3) * 3;
    t /= 3;
    D_80100F34_SlotCarDerby[3] = t % 10;
    t /= 10;
    D_80100F34_SlotCarDerby[2] = t % 10;
    t /= 10;
    D_80100F34_SlotCarDerby[1] = t % 6;
    t /= 6;
    if (t >= 9) {
        D_80100F34_SlotCarDerby[0] = 9;
    } else {
        D_80100F34_SlotCarDerby[0] = t;
    }
    D_80102474_SlotCarDerby = func_80064EF4(7, 5);
    data = DataRead(0x87);
    digit = func_800678A4(data);
    DataClose(data);
    D_80102478_SlotCarDerby = func_80064EF4(7, 5);
    data = DataRead(0x87);
    colon = func_800678A4(data);
    DataClose(data);
    func_800FCCA0_SlotCarDerby(colon, 0, 256, 0);
    func_80066DC4(D_8010247A_SlotCarDerby, 0, 230, 28);
    func_80067208(D_8010247A_SlotCarDerby, 0, colon, 0);
    func_800672B0(D_8010247A_SlotCarDerby, 0, 0);
    func_800671DC(D_8010247A_SlotCarDerby, 0, (s16)D_80100F34_SlotCarDerby[0]);
    func_800674BC(D_8010247A_SlotCarDerby, 0, 0x1000);
    func_80066DC4(D_80102476_SlotCarDerby, 0, 230, 44);
    func_80067208(D_80102476_SlotCarDerby, 0, digit, 0);
    func_800672B0(D_80102476_SlotCarDerby, 0, 0);
    func_800674BC(D_80102476_SlotCarDerby, 0, 0x1000);
    for (i = 1; i < 7; i++) {
        func_80067208(D_80102476_SlotCarDerby, i, digit, 0);
        func_800672B0(D_80102476_SlotCarDerby, i, 0);
        px = &D_80100F18_SlotCarDerby[i];
        func_80066DC4(D_80102476_SlotCarDerby, i, (s16)*px, 0);
        func_80067598(D_80102476_SlotCarDerby, i, 0);
        func_800674BC(D_80102476_SlotCarDerby, i, 0x1000);
        func_80067208(D_8010247A_SlotCarDerby, i, colon, 0);
        func_80066DC4(D_8010247A_SlotCarDerby, i, (s16)*px, 0);
        func_80067598(D_8010247A_SlotCarDerby, i, 0);
        func_800671DC(D_8010247A_SlotCarDerby, i, (s16)D_80100F34_SlotCarDerby[i]);
        func_800672B0(D_8010247A_SlotCarDerby, i, 0);
        func_800674BC(D_8010247A_SlotCarDerby, i, 0x1000);
    }
    func_800671DC(D_80102476_SlotCarDerby, 5, (s16)D_80100F34_SlotCarDerby[5]);
    func_800671DC(D_80102476_SlotCarDerby, 6, (s16)D_80100F34_SlotCarDerby[6]);
    data = DataRead(0x390014);
    digit = func_800678A4(data);
    DataClose(data);
    D_8010246C_SlotCarDerby = HuMemDirectMalloc(8 * sizeof(SCDObj));
    for (i = 0; i < 5; i++) {
        o = &D_8010246C_SlotCarDerby[i];
        SCD_OBJ_CLEAR(o);
        o->unk_10.x = (D_80100ED8_SlotCarDerby[i] + 10.0) * 10.0;
        o->unk_10.y = 1470.0f;
        o->unk_10.z = D_80100EF0_SlotCarDerby[D_80100EAC_SlotCarDerby] * 10.0;
        o->unk_40[0] = func_800FE2F0_SlotCarDerby(digit, 0x91);
        func_800FF5BC_SlotCarDerby(o->unk_40[0], o->unk_10.x, o->unk_10.y, o->unk_10.z);
        func_800FF65C_SlotCarDerby(o->unk_40[0], -47.0f, 0.0f, 0.0f);
        func_800FF60C_SlotCarDerby(o->unk_40[0], 10.0f, 10.0f, 1.0f);
        func_800FF53C_SlotCarDerby(o->unk_40[0], 0);
    }
    for (i = 0; i < 2; i++) {
        data = DataRead(D_80100F50_SlotCarDerby[i] | 0x390000);
        sprite = func_800678A4(data);
        DataClose(data);
        o = &D_8010246C_SlotCarDerby[i + 6];
        SCD_OBJ_CLEAR(o);
        o->unk_10.x = (D_80100EF8_SlotCarDerby[i] + 10.0) * 10.0;
        o->unk_10.y = 1480.0f;
        o->unk_10.z = (D_80100EF0_SlotCarDerby[D_80100EAC_SlotCarDerby] + 1.5) * 10.0;
        o->unk_40[0] = func_800FE2F0_SlotCarDerby(sprite, 0x91);
        func_800FF5BC_SlotCarDerby(o->unk_40[0], o->unk_10.x, o->unk_10.y, o->unk_10.z);
        func_800FF65C_SlotCarDerby(o->unk_40[0], -43.2f, 0.0f, 0.0f);
        func_800FF738_SlotCarDerby(o->unk_40[0], 0, 0, 0, 254);
        func_800FF60C_SlotCarDerby(o->unk_40[0], 10.0f, 10.0f, 1.0f);
        func_800FF53C_SlotCarDerby(o->unk_40[0], 0);
    }
    data = DataRead(0x390015);
    sprite = func_800678A4(data);
    DataClose(data);
    rec->unk_40[0] = func_800FE2F0_SlotCarDerby(sprite, 0x91);
    rec->unk_40[1] = func_800FE2F0_SlotCarDerby(sprite, 0x91);
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    rec->unk_10.x = D_80100F00_SlotCarDerby[D_80100EAC_SlotCarDerby].x * 10.0;
    rec->unk_10.y = D_80100F00_SlotCarDerby[D_80100EAC_SlotCarDerby].y * 10.0;
    rec->unk_10.z = D_80100F00_SlotCarDerby[D_80100EAC_SlotCarDerby].z * 10.0;
    func_800FF5BC_SlotCarDerby(rec->unk_40[0], rec->unk_10.x + 72.1, rec->unk_10.y, rec->unk_10.z);
    func_800FF5BC_SlotCarDerby(rec->unk_40[1], rec->unk_10.x - 72.1, rec->unk_10.y, rec->unk_10.z);
    func_800FF60C_SlotCarDerby(rec->unk_40[0], 11.25f, 14.5f, 1.0f);
    func_800FF60C_SlotCarDerby(rec->unk_40[1], 11.25f, 14.5f, 1.0f);
    func_800FF65C_SlotCarDerby(rec->unk_40[0], 0.0f, 45.0f, 0.0f);
    func_800FF65C_SlotCarDerby(rec->unk_40[1], 0.0f, -45.0f, 0.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800FC394_SlotCarDerby);
#endif
// register allocation and multiply order (masked 12)
#ifdef NON_MATCHING
/* Scales a sprite palette's RGBA5551 colours by r/g/b (/256), keeping alpha. */
void func_800FCCA0_SlotCarDerby(s16 anim, s32 r, s32 g, s32 b) {
    unk65770Anim* a = func_80067310(anim);
    u16* p = a->unkC;
    s32 i;

    for (i = 0; i < a->unk1A; i++, p++) {
        u16 c = *p;

        *p = (*p & 1) | (((((c >> 11) * r) >> 8) << 11) | (((((c >> 6) & 0x1F) * g) >> 8) << 6) |
                         (((((c >> 1) & 0x1F) * b) >> 8) << 1));
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800FCCA0_SlotCarDerby);
#endif
void func_800FCD6C_SlotCarDerby(omObjData* obj) {
    SCDFx* fx;
    unk65770Anim* anim;
    void* data;
    s32 i;

    obj->func_ptr = func_800FD658_SlotCarDerby;
    D_80102488_SlotCarDerby = func_80064EF4(32, 0);
    data = DataRead(0x390017);
    D_8010247C_SlotCarDerby[2] = func_800678A4(data);
    DataClose(data);
    data = DataRead(0x390018);
    D_8010247C_SlotCarDerby[0] = func_800678A4(data);
    DataClose(data);
    data = DataRead(0x390019);
    D_8010247C_SlotCarDerby[1] = func_800678A4(data);
    DataClose(data);
    D_80102470_SlotCarDerby = HuMemDirectMalloc(32 * sizeof(SCDFx));
    for (i = 0; i < 32; i++) {
        fx = &D_80102470_SlotCarDerby[i];
        fx->unk_01 = -1;
        fx->unk_02 = fx->unk_04 = 0;
        fx->unk_08.x = fx->unk_08.y = fx->unk_08.z = 0.0f;
        fx->unk_14.x = fx->unk_14.y = fx->unk_14.z = 0.0f;
        fx->unk_20 = fx->unk_24 = fx->unk_28 = 1.0f;
        fx->unk_2C.x = fx->unk_2C.y = fx->unk_2C.z = 0.0f;
        anim = func_80067310(D_8010247E_SlotCarDerby);
        anim->unk0->unk8 = 0;
        anim->unk0->unkA = 27;
        fx->unk_00 = func_800FE2F0_SlotCarDerby(D_8010247E_SlotCarDerby, 0xB1);
        func_800674BC(D_8010248A_SlotCarDerby, i, 0x9008);
        func_800672B0(D_8010248A_SlotCarDerby, i, 0);
    }
    func_800FFD18_SlotCarDerby();
}
void func_800FCF50_SlotCarDerby(omObjData* obj) {
    SCDObj* rec = func_800FDD28_SlotCarDerby(obj);

    switch (D_80100EA0_SlotCarDerby) {
        case 0:
        case 1:
        case 5:
            if (rec->unk_00 == 0) {
                D_80102460_SlotCarDerby[0] = obj->model[2];
                D_80102460_SlotCarDerby[1] = obj->model[3];
                func_800184BC(obj, 1);
                if (D_80100EBC_SlotCarDerby == 0) {
                    func_800258EC(obj->model[1], 4, 0);
                }
                D_800F2B7C[obj->model[0]].unk_4C = 0.0f;
                D_800F2B7C[obj->model[1]].unk_4C = 0.0f;
                rec->unk_02 = 4;
                rec->unk_40[0] = 0;
                rec->unk_40[1] = 0;
                rec->unk_00 = 1;
            }
            break;
        case 2:
            if (rec->unk_02 & 4) {
                if (rec->unk_08 != 0) {
                    if (rec->unk_08 >= 150) {
                        func_800184BC(obj, 0);
                        func_800258EC(obj->model[1], 4, 4);
                        rec->unk_02 = 2;
                        rec->unk_08 = 0;
                        rec->unk_00 = 0;
                        break;
                    }
                } else {
                    D_800F2B7C[obj->model[0]].unk_4C = 1.0f;
                    D_800F2B7C[obj->model[1]].unk_4C = 1.0f;
                    rec->unk_40[0] = 0;
                    rec->unk_40[1] = 0;
                }
                if ((func_8005FD5C() + D_800F64F8) == 0 && D_80100EA4_SlotCarDerby == 0) {
                    rec->unk_08++;
                }
            }
            if (D_80100EA4_SlotCarDerby == 0) {
                break;
            }
        case 3:
        case 4:
            if (rec->unk_00 == 0) {
                rec->unk_02 = 4;
                func_800184BC(obj, 1);
                if (D_80100EBC_SlotCarDerby == 0) {
                    func_800258EC(obj->model[1], 4, 0);
                }
                func_80025CA8(obj->model[0], 0.0f);
                func_80025CA8(obj->model[1], 0.0f);
                rec->unk_08 = 0;
                rec->unk_40[0] = 0;
                rec->unk_40[1] = 0;
                rec->unk_00 = 1;
                if (D_80100EB8_SlotCarDerby != 0) {
                    GMesCreate(12);
                    func_800594E4(D_80100EAE_SlotCarDerby + 1, D_80100EB2_SlotCarDerby);
                } else if (D_801024B0_SlotCarDerby == 0) {
                    GMesCreate(18);
                }
            }
            break;
        case 6:
            break;
    }
    if ((s16)rec->unk_02 == 4) {
        func_80026174(obj->model[1], (s16)D_80102460_SlotCarDerby[rec->unk_40[0]],
                      1.0f - func_800AEAC0(rec->unk_40[1]));
        if ((func_8005FD5C() + D_800F64F8) == 0) {
            rec->unk_40[1] += 6;
        }
        if (rec->unk_40[1] >= 180) {
            rec->unk_40[0] ^= 1;
            rec->unk_40[1] = 0;
        }
    }
    func_80017DB0(obj);
}
// addu operand order for one array address (masked 0)
#ifdef NON_MATCHING
void func_800FD2C4_SlotCarDerby(omObjData* obj) {
    SCDObj* rec = func_800FDD28_SlotCarDerby(obj);
    SCDObj* o;
    s32* p;
    s32* digits;
    s32 i;
    s32 d;

    switch (D_80100EA0_SlotCarDerby) {
        case 1:
            if (++rec->unk_08 >= D_80100F58_SlotCarDerby[rec->unk_00]) {
                if (rec->unk_00 >= 5) {
                    rec->unk_00 = 5;
                    rec->unk_08 = 0;
                } else {
                    rec->unk_08 = 0;
                    rec->unk_00++;
                    func_800FF53C_SlotCarDerby(rec->unk_40[0], rec->unk_00);
                    func_800FF53C_SlotCarDerby(rec->unk_40[1], rec->unk_00);
                }
            }
            break;
        case 2:
            if (rec->unk_00 == 5) {
                rec->unk_00 = 0;
                rec->unk_08 = 0;
                func_800FF784_SlotCarDerby(rec->unk_40[0]);
                func_800FF784_SlotCarDerby(rec->unk_40[1]);
            }
            if (D_80100EA4_SlotCarDerby == 0) {
                D_80100EB0_SlotCarDerby++;
                D_80100F70_SlotCarDerby[4]++;
            }
            i = 0;
            if (D_80100F70_SlotCarDerby[4] >= 3) {
                D_80100F70_SlotCarDerby[4] = 0;
                D_80100F70_SlotCarDerby[3]++;
                D_8010246C_SlotCarDerby[7].unk_00 ^= 1;
                if (D_80100F70_SlotCarDerby[3] >= 5) {
                    D_8010246C_SlotCarDerby[6].unk_00 = 1;
                }
                i = 0;
                if (D_80100F70_SlotCarDerby[3] >= 10) {
                    D_80100F70_SlotCarDerby[3] = 0;
                    D_80100F70_SlotCarDerby[2]++;
                    D_8010246C_SlotCarDerby[6].unk_00 = 0;
                    if (D_80100F70_SlotCarDerby[2] >= 10) {
                        D_80100F70_SlotCarDerby[2] = 0;
                        if (++D_80100F70_SlotCarDerby[1] >= 6) {
                            D_80100F70_SlotCarDerby[1] = 0;
                            D_80100F70_SlotCarDerby[0]++;
                        }
                    }
                }
            }
            digits = D_80100F70_SlotCarDerby;
            do {
                o = &D_8010246C_SlotCarDerby[i];
                if (i == 4) {
                    d = (u8)(rand8() % 3) + digits[4] * 3;
                    func_800FF53C_SlotCarDerby(o->unk_40[0], d);
                    func_800671DC(D_80102476_SlotCarDerby, 4, d);
                } else {
                    p = i + digits;
                    func_800FF53C_SlotCarDerby(o->unk_40[0], (s16)*p);
                    func_800671DC(D_80102476_SlotCarDerby, i, (s16)*p);
                }
            i++;
            } while (i < 5);
            func_800FF53C_SlotCarDerby(D_8010246C_SlotCarDerby[6].unk_40[0], D_8010246C_SlotCarDerby[6].unk_00);
            func_800FF53C_SlotCarDerby(D_8010246C_SlotCarDerby[7].unk_40[0], D_8010246C_SlotCarDerby[7].unk_00);
            break;
        case 4:
        case 5:
        case 6:
            break;
        case 3:
        case 7:
            if (D_80100EB0_SlotCarDerby == D_80100EB4_SlotCarDerby) {
                func_800FF53C_SlotCarDerby(D_8010246C_SlotCarDerby[4].unk_40[0], d = D_80100F70_SlotCarDerby[4] * 3 + 1);
                func_800671DC(D_80102476_SlotCarDerby, 4, d);
            } else if (D_80100EB0_SlotCarDerby < D_80100EB4_SlotCarDerby) {
                func_800FF53C_SlotCarDerby(D_8010246C_SlotCarDerby[4].unk_40[0], d = D_80100F70_SlotCarDerby[4] * 3);
                func_800671DC(D_80102476_SlotCarDerby, 4, d);
            }
            break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800FD2C4_SlotCarDerby);
#endif

void func_800FD658_SlotCarDerby(omObjData* obj) {
    Vec pos;
    Vec screen;
    SCDFx* fx;
    s32 i;

    D_80100EA8_SlotCarDerby = (D_80100EA8_SlotCarDerby + 1) % 3;
    if (D_80100EA0_SlotCarDerby != 6) {
        for (i = 0; i < 32; i++) {
            fx = &D_80102470_SlotCarDerby[i];
            if (fx->unk_01 == -1) {
                continue;
            }
            pos.x = fx->unk_08.x;
            pos.y = fx->unk_08.y + 80.0;
            pos.z = fx->unk_08.z;
            func_800FDD54_SlotCarDerby(0, &pos, &screen);
            switch (fx->unk_01) {
                case 0:
                    fx->unk_20 *= 0.8;
                    fx->unk_24 *= 0.8;
                    func_800FF60C_SlotCarDerby(fx->unk_00, fx->unk_20, fx->unk_24, fx->unk_28);
                    func_800FF53C_SlotCarDerby(fx->unk_00, fx->unk_02);
                    fx->unk_02++;
                    if ((s16)fx->unk_04 == 0) {
                        func_800FF6AC_SlotCarDerby(fx->unk_00, 0x20);
                        fx->unk_01 = -1;
                        fx->unk_02 = 0;
                        fx->unk_04 = 0;
                    }
                    break;
                case 1:
                    func_80066DC4(D_8010248A_SlotCarDerby, i, screen.x, screen.y);
                    screen.z = screen.z + (8 - (s16)fx->unk_04) * screen.z * 0.05;
                    func_80067354(D_8010248A_SlotCarDerby, i, screen.z * fx->unk_20, screen.z * fx->unk_24);
                    func_800671DC(D_8010248A_SlotCarDerby, i, fx->unk_02 + 4);
                    fx->unk_02++;
                    if ((s16)fx->unk_04 == 0) {
                        func_800674BC(D_8010248A_SlotCarDerby, i, 0x8000);
                        fx->unk_01 = -1;
                    }
                    break;
                case 2:
                    func_80066DC4(D_8010248A_SlotCarDerby, i, screen.x, screen.y);
                    screen.z = screen.z + (fx->unk_04 & 3) * screen.z * 0.25;
                    func_80067354(D_8010248A_SlotCarDerby, i, screen.z * fx->unk_20, screen.z * fx->unk_24);
                    fx->unk_02 ^= 1;
                    func_800671DC(D_8010248A_SlotCarDerby, i, fx->unk_02);
                    if ((s16)fx->unk_04 == 0) {
                        func_800674BC(D_8010248A_SlotCarDerby, i, 0x8000);
                        fx->unk_01 = -1;
                    }
                    break;
            }
            fx->unk_04--;
        }
        func_800FFD18_SlotCarDerby();
    }
}
void func_800FD9E8_SlotCarDerby(s32 type, Vec* pos, Vec* rot) {
    func_800FDA04_SlotCarDerby(type, pos, rot);
}
void func_800FDA04_SlotCarDerby(s32 type, Vec* pos, Vec* rot) {
    SCDFx* fx;
    s32 i;

    for (i = 0; i < 32; i++) {
        fx = &D_80102470_SlotCarDerby[i];
        if (fx->unk_01 == -1) {
            break;
        }
    }
    if (i == 32) {
        return;
    }
    fx->unk_01 = type;
    fx->unk_04 = 0;
    fx->unk_02 = 0;
    fx->unk_08.x = pos->x * 10.0f;
    fx->unk_08.y = pos->y * 10.0f;
    fx->unk_08.z = pos->z * 10.0f;
    fx->unk_14.x = rot->x;
    fx->unk_14.y = rot->y;
    fx->unk_14.z = rot->z;
    switch (fx->unk_01) {
        case 0:
            func_800FF6F0_SlotCarDerby(fx->unk_00, 0x20);
            func_800FF5BC_SlotCarDerby(fx->unk_00, fx->unk_08.x, fx->unk_08.y, fx->unk_08.z);
            func_800FF65C_SlotCarDerby(fx->unk_00, fx->unk_14.z, fx->unk_14.y - 90.0f, fx->unk_14.x);
            func_800FF738_SlotCarDerby(fx->unk_00, 0xFF, 0x96, 0, 0xFF);
            fx->unk_20 = 60.0f;
            fx->unk_24 = 20.0f;
            fx->unk_28 = 1.0f;
            func_800FF60C_SlotCarDerby(fx->unk_00, fx->unk_20, fx->unk_24, fx->unk_28);
            func_800FF57C_SlotCarDerby(fx->unk_00, 4.0f);
            if (D_80100EA0_SlotCarDerby == 2) {
                PlaySound(0x2DA);
            }
            fx->unk_04 = 15;
            break;
        case 1:
            func_80067558(D_8010248A_SlotCarDerby, (s16)i, 0xFF, 0xFF, 0xFF, 0xFF);
            func_80067208(D_8010248A_SlotCarDerby, i, (s16)D_8010247C_SlotCarDerby[fx->unk_01], 0);
            func_80067480(D_8010248A_SlotCarDerby, i, 0x8000);
            fx->unk_20 = 2.5f;
            fx->unk_24 = 2.5f;
            fx->unk_28 = 1.0f;
            fx->unk_04 = 7;
            break;
        case 2:
            fx->unk_08.y += 160.0f;
            func_80067558(D_8010248A_SlotCarDerby, (s16)i, 0, 0, 0, 0xFF);
            func_80067208(D_8010248A_SlotCarDerby, i, (s16)D_8010247C_SlotCarDerby[fx->unk_01], 0);
            fx->unk_20 = 10.0f;
            fx->unk_24 = 10.0f;
            fx->unk_28 = 1.0f;
            func_80067480(D_8010248A_SlotCarDerby, i, 0x8000);
            fx->unk_04 = 7;
            break;
    }
}
void func_800FDD08_SlotCarDerby(omObjData* obj, SCDObj* rec) {
    u32 v = (u32)rec;

    obj->work[0] = v >> 24;
    obj->work[1] = v >> 16;
    obj->work[2] = v >> 8;
    obj->work[3] = v;
}
SCDObj* func_800FDD28_SlotCarDerby(omObjData* obj) {
    u32 v = (obj->work[0] << 24) | (obj->work[1] << 16) | (obj->work[2] << 8) | obj->work[3];

    return (SCDObj*)v;
}
/* The N64 Mtx's n-th halfword in N64 order (the integer halves are the first 16, the fractions
   the next 16), read endian-neutrally on the host. */
#define SCD_MTX_H(mtx, n) (((u16*)&(mtx))[n])

/* Projects pos through camera cam's view into screen x, y and a perspective scale (z). */
// scheduling of &Center and the viewport register (masked 4)
#ifdef NON_MATCHING
void func_800FDD54_SlotCarDerby(s32 cam, Vec* pos, Vec* screen) {
    Mtx look;
    Mtx mtx;
    Vec eye;
    Vec at;
    Vec up;
    unk_Struct00* c = &D_800C3110[cam];
    Mtx* m = &mtx;
    unk_Struct00* vp;
    f32 rx;
    f32 ry;
    f32 sx;
    f32 sy;
    f32 sz;
    f32 sn;
    f32 dist;

    rx = CRot.x;
    ry = CRot.y;
    eye.x = func_800AEAC0(ry) * func_800AEFD0(rx) * CZoom + Center.x;
    eye.y = -func_800AEAC0(rx) * CZoom + Center.y;
    eye.z = func_800AEFD0(ry) * func_800AEFD0(rx) * CZoom + Center.z;
    at.x = Center.x;
    at.y = Center.y;
    at.z = Center.z;
    up.x = func_800AEAC0(ry) * func_800AEAC0(rx);
    up.y = func_800AEFD0(rx);
    up.z = func_800AEFD0(ry) * func_800AEAC0(rx);
    guLookAt(&look, eye.x, eye.y, eye.z, at.x, at.y, at.z, up.x, up.y, up.z);
    guTranslate(m, pos->x, pos->y, pos->z);
    guMtxCatL(m, &look, m);
    sx = (s32)((SCD_MTX_H(mtx, 12) << 16) | SCD_MTX_H(mtx, 28)) >> 16;
    sy = (s32)((SCD_MTX_H(mtx, 13) << 16) | SCD_MTX_H(mtx, 29)) >> 16;
    sz = (s32)((SCD_MTX_H(mtx, 14) << 16) | SCD_MTX_H(mtx, 30)) >> 16;
    sn = func_800AEAC0(D_800C3110[cam].unk_40 / 2.0);
    dist = fabsf(sz * sn / func_800AEFD0(D_800C3110[cam].unk_40 / 2.0));
    if (dist != 0.0) {
        vp = (unk_Struct00*)((u8*)c + D_800F3FA8 * 16);
        /* written through f32* (not Vec fields): retail reloads D_800F3FA8 after the store */
        ((f32*)screen)[0] = (s16)(vp->unk58 / 4.0 * sx / dist / 1.3333334f) + vp->unk60 / 4.0;
        vp = (unk_Struct00*)((u8*)c + D_800F3FA8 * 16);
        ((f32*)screen)[1] = (s16)(vp->unk5A / 4.0 * -sy / dist) + vp->unk62 / 4.0;
        ((f32*)screen)[2] = vp->unk5A / 4.0 / dist;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800FDD54_SlotCarDerby);
#endif
/* Allocates count billboards and the per-frame display-list and matrix buffers. */
void func_800FE138_SlotCarDerby(u8 count) {
    SCDBillboard* b;
    s16 i;

    D_8010248C_SlotCarDerby = count;
    for (i = 0; i < 3; i++) {
        D_80102490_SlotCarDerby[i] = HuMemDirectMalloc(D_8010248C_SlotCarDerby * 20 * sizeof(Gfx));
        D_8010249C_SlotCarDerby[i] = HuMemDirectMalloc(D_8010248C_SlotCarDerby * sizeof(Mtx));
    }
    D_801024A8_SlotCarDerby = func_80024198(0x499, D_80102490_SlotCarDerby[0], 4);
    D_80103298 = HuMemDirectMalloc(D_8010248C_SlotCarDerby * sizeof(SCDBillboard));
    for (i = 0; i < D_8010248C_SlotCarDerby; i++) {
        b = &D_80103298[i];
        b->unk_00 = (Gfx*)-1;
        b->unk_20 = 0;
        b->unk_28 = 0;
        b->unk_22 = 0;
        b->unk_29 = b->unk_2A = b->unk_2B = b->unk_2C = 0xFF;
        b->unk_30 = 0.0f;
        b->unk_24 = 0;
        b->unk_26 = 0;
        b->unk_34 = 1.0f;
        b->unk_38.x = b->unk_38.y = b->unk_38.z = 0.0f;
        b->unk_44.x = b->unk_44.y = b->unk_44.z = 1.0f;
        b->unk_50.x = b->unk_50.y = b->unk_50.z = 0.0f;
    }
}
/* gDPSetTile's mask for a texture dimension (as src/1EA70.c's TEX_MASK). */
#define SCD_TEX_MASK(x) \
    ((x) < 3 ? 1 : (x) < 5 ? 2 : (x) < 9 ? 3 : (x) < 17 ? 4 : (x) < 33 ? 5 : (x) < 65 ? 6 : (x) < 129 ? 7 : (x) < 257 ? 8 : 9)

/* Takes a free billboard for sprite and builds its display list (texture and quad), its
   per-frame vertex copies and its per-frame material lists. Returns its id, -1 if none is free. */
// register allocation: the vertex pointer and the quad x (masked 10)
#ifdef NON_MATCHING
s16 func_800FE2F0_SlotCarDerby(s16 sprite, u8 flags) {
    SCDBillboard* b;
    unk65770Anim* anim;
    unk65770AnimC* frame;
    Gfx* dl;
    Gfx* gfx;
    Vtx* vbuf;
    Vtx* v;
    s32 size;
    u16 w;
    u16 h;
    s16 x;
    s16 y;
    s16 nh;
    s16 i;
    s16 id;

    for (id = 0; id < D_8010248C_SlotCarDerby; id++) {
        if (D_80103298[id].unk_00 == (Gfx*)-1) {
            break;
        }
    }
    if (id == D_8010248C_SlotCarDerby) {
        return -1;
    }
    b = &D_80103298[id];
    b->unk_22 = sprite;
    b->unk_28 = flags;
    dl = HuMemDirectMalloc(0x2000 * sizeof(Gfx)); /* 0x10000 bytes on the N64 */
    vbuf = v = HuMemDirectMalloc(8 * sizeof(Vtx));
    gfx = dl;
    gDPPipeSync(gfx++);
    anim = D_800EC700[b->unk_22];
    if (anim->unk18 & 0x8000) {
        gDPSetCombine(gfx++, 0xFF97FF, 0xFF2DFEFF);
        gDPSetRenderMode(gfx++, 0x4049D8, 0);
        gDPSetBlendColor(gfx++, 1, 1, 1, 1);
    } else if (b->unk_29 == 0xFF) {
        gDPSetRenderMode(gfx++, 0x443078, 0);
        gDPSetCombine(gfx++, 0xFFFFFF, 0xFFFCF279);
    } else {
        gDPSetBlendColor(gfx++, 0, 0, 0, 1);
        gDPSetRenderMode(gfx++, 0x5049D8, 0);
        gDPSetCombine(gfx++, 0x143228, 0xFF65FEFF);
    }
    frame = &anim->unk0[b->unk_24];
    w = frame->unk4;
    h = frame->unk6;
    if (anim->unk18 & 0x8000) {
        gDPLoadTextureBlock_4b(gfx++, 0x02000000, G_IM_FMT_I, (s16)w, (s16)h, 0, G_TX_CLAMP, G_TX_CLAMP,
                               SCD_TEX_MASK((s16)w), SCD_TEX_MASK((s16)h), G_TX_NOLOD, G_TX_NOLOD);
    } else if (anim->unk18 < 0x11) {
        gDPLoadTextureBlock_4b(gfx++, 0x02000000, G_IM_FMT_CI, (s16)w, (s16)h, 0, G_TX_CLAMP, G_TX_CLAMP,
                               SCD_TEX_MASK((s16)w), SCD_TEX_MASK((s16)h), G_TX_NOLOD, G_TX_NOLOD);
    } else {
        gDPLoadTextureBlock(gfx++, 0x02000000, G_IM_FMT_CI, G_IM_SIZ_8b, (s16)w, (s16)h, 0, G_TX_CLAMP, G_TX_CLAMP,
                            SCD_TEX_MASK((s16)w), SCD_TEX_MASK((s16)h), G_TX_NOLOD, G_TX_NOLOD);
    }
    gSPVertex(gfx++, 0x01000000, 4, 0);
    gSP1Quadrangle(gfx++, 0, 1, 2, 3, 0);
    gSPEndDisplayList(gfx++);
    nh = -h;
    x = -frame->unk8;
    y = frame->unkA;
    v->v.ob[0] = x;
    v->v.ob[1] = y;
    v->v.ob[2] = 0;
    v->n.n[0] = v->n.n[1] = v->n.n[2] = -1;
    v->v.tc[0] = 0;
    v->v.tc[1] = 0;
    v->n.a = 0xFF;
    v++;
    v->v.ob[0] = x;
    v->v.ob[1] = nh + y;
    v->v.ob[2] = 0;
    v->n.n[0] = v->n.n[1] = v->n.n[2] = -1;
    v->v.tc[0] = 0;
    v->v.tc[1] = (-nh - 1) << 6;
    v->n.a = 0xFF;
    v++;
    v->v.ob[0] = (s16)w + x;
    v->v.ob[1] = nh + y;
    v->v.ob[2] = 0;
    v->n.n[0] = v->n.n[1] = v->n.n[2] = -1;
    v->v.tc[0] = ((s16)w - 1) << 6;
    v->v.tc[1] = (-nh - 1) << 6;
    v->n.a = 0xFF;
    v++;
    v->v.ob[0] = (s16)w + x;
    v->v.ob[1] = y;
    v->v.ob[2] = 0;
    v->n.n[0] = v->n.n[1] = v->n.n[2] = -1;
    v->v.tc[0] = ((s16)w - 1) << 6;
    v->v.tc[1] = 0;
    v->n.a = 0xFF;
    size = (u8*)gfx - (u8*)dl;
    for (i = 0; i < D_800F37DA; i++) {
        b->unk_10[i] = HuMemDirectMalloc(8 * sizeof(Vtx));
        func_80023A38(vbuf, b->unk_10[i], 8 * sizeof(Vtx));
    }
    b->unk_00 = HuMemDirectMalloc(size);
    func_80023A38(dl, b->unk_00, size);
    HuMemDirectFree(dl);
    HuMemDirectFree(vbuf);
    dl = HuMemDirectMalloc(0x2000 * sizeof(Gfx)); /* 0x10000 bytes on the N64 */
    gfx = dl;
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, b->unk_2A, b->unk_2B, b->unk_2C, b->unk_29);
    gDPSetTextureFilter(gfx++, D_80100F88_SlotCarDerby[(b->unk_28 & 0x18) >> 3]);
    if (anim->unk18 & 0x8000) {
        gDPSetTextureLUT(gfx++, G_TT_NONE);
    } else {
        gDPSetTextureLUT(gfx++, G_TT_RGBA16);
        if (anim->unk18 < 0x11) {
            gDPLoadTLUT_pal16(gfx++, 0, anim->unkC);
        } else {
            gDPLoadTLUT_pal256(gfx++, anim->unkC);
        }
    }
    gSPSegment(gfx++, 2, osVirtualToPhysical(frame->unk0));
    gSPSegment(gfx++, 1, osVirtualToPhysical(b->unk_10[0]));
    gSPDisplayList(gfx++, b->unk_00);
    gSPEndDisplayList(gfx++);
    size = (u8*)gfx - (u8*)dl;
    for (i = 0; i < D_800F37DA; i++) {
        b->unk_04[i] = HuMemDirectMalloc(size);
        func_80023A38(dl, b->unk_04[i], size);
    }
    HuMemDirectFree(dl);
    return id;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800FE2F0_SlotCarDerby);
#endif
void func_800FF53C_SlotCarDerby(s16 id, s16 frame) {
    SCDBillboard* b;

    if (id != -1) {
        b = &D_80103298[id];
        b->unk_24 = frame;
        b->unk_30 = 0.0f;
    }
}
void func_800FF57C_SlotCarDerby(s16 id, f32 speed) {
    if (id != -1) {
        SCDBillboard* b = &D_80103298[id];

        b->unk_34 = speed;
    }
}
void func_800FF5BC_SlotCarDerby(s16 id, f32 x, f32 y, f32 z) {
    SCDBillboard* b;

    if (id != -1) {
        b = &D_80103298[id];
        b->unk_38.x = x;
        b->unk_38.y = y;
        b->unk_38.z = z;
    }
}
void func_800FF60C_SlotCarDerby(s16 id, f32 x, f32 y, f32 z) {
    SCDBillboard* b;

    if (id != -1) {
        b = &D_80103298[id];
        b->unk_44.x = x;
        b->unk_44.y = y;
        b->unk_44.z = z;
    }
}
void func_800FF65C_SlotCarDerby(s16 id, f32 x, f32 y, f32 z) {
    SCDBillboard* b;

    if (id != -1) {
        b = &D_80103298[id];
        b->unk_50.x = x;
        b->unk_50.y = y;
        b->unk_50.z = z;
    }
}
void func_800FF6AC_SlotCarDerby(s16 id, u8 flags) {
    SCDBillboard* b;

    if (id != -1) {
        b = &D_80103298[id];
        b->unk_28 |= flags;
    }
}
void func_800FF6F0_SlotCarDerby(s16 id, u8 flags) {
    SCDBillboard* b;

    if (id != -1) {
        b = &D_80103298[id];
        b->unk_28 &= ~flags;
    }
}
void func_800FF738_SlotCarDerby(s16 id, u8 r, u8 g, u8 b, s32 a) {
    SCDBillboard* bb;

    if (id != -1) {
        bb = &D_80103298[id];
        bb->unk_2A = r;
        bb->unk_2B = g;
        bb->unk_2C = b;
        bb->unk_29 = a;
    }
}
/* Frees a billboard's display lists and resets it. */
void func_800FF784_SlotCarDerby(s16 id) {
    SCDBillboard* b;
    s32 i;

    if (id != -1) {
        b = &D_80103298[id];
        if (b->unk_00 != (Gfx*)-1) {
            for (i = 0; i < D_800F37DA; i++) {
                HuMemDirectFree(b->unk_10[i]);
                HuMemDirectFree(b->unk_04[i]);
            }
            HuMemDirectFree(b->unk_00);
            b->unk_00 = (Gfx*)-1;
            b->unk_1C = 0;
            b->unk_20 = 0;
            b->unk_28 = 0;
            b->unk_22 = 0;
            b->unk_29 = b->unk_2A = b->unk_2B = b->unk_2C = 0xFF;
            b->unk_30 = 0.0f;
            b->unk_24 = 0;
            b->unk_26 = 0;
            b->unk_38.x = b->unk_38.y = b->unk_38.z = 0.0f;
            b->unk_34 = b->unk_44.x = b->unk_44.y = b->unk_44.z = 1.0f;
        }
    }
}
/* Rewrites each visible billboard's material list for this frame and advances its animation
   (two steps a frame; flags 4/0x40/2 hide, free or hold it at the end). */
void func_800FF8A4_SlotCarDerby(void) {
    SCDBillboard* b;
    unk65770Anim* anim;
    unk65770AnimC* frame;
    Gfx* gfx;
    unk65770Anim8* seq;
    s32 len;
    s32 count;
    s16 j;
    s16 i;

    for (i = 0; i < D_8010248C_SlotCarDerby; i++) {
        b = &D_80103298[i];
        if (b->unk_00 == (Gfx*)-1 || b->unk_20 != 0 || (b->unk_28 & 0x20)) {
            continue;
        }
        gfx = b->unk_04[D_800F37F0];
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, b->unk_2A, b->unk_2B, b->unk_2C, b->unk_29);
        gDPSetTextureFilter(gfx++, D_80100F88_SlotCarDerby[(b->unk_28 & 0x18) >> 3]);
        anim = D_800EC700[b->unk_22];
        frame = &anim->unk0[b->unk_24];
        if (anim->unk18 & 0x8000) {
            gDPSetTextureLUT(gfx++, G_TT_NONE);
        } else {
            gDPSetTextureLUT(gfx++, G_TT_RGBA16);
            if (anim->unk18 < 0x11) {
                gDPLoadTLUT_pal16(gfx++, 0, anim->unkC);
            } else {
                gDPLoadTLUT_pal256(gfx++, anim->unkC);
            }
        }
        gSPSegment(gfx++, 2, osVirtualToPhysical(frame->unk0));
        gSPSegment(gfx++, 1, osVirtualToPhysical(b->unk_10[D_800F37F0]));
        gSPDisplayList(gfx++, b->unk_00);
        gSPEndDisplayList(gfx++);
        if (b->unk_28 & 1) {
            continue;
        }
        if (anim->unk4 != NULL) {
            seq = *anim->unk4;
            len = seq->unk4[b->unk_24].unk2;
            count = seq->unk0;
        } else {
            len = 8;
            count = anim->unk10;
        }
        for (j = 0; j < 2; j++) {
            b->unk_30 += b->unk_34;
            if (b->unk_30 >= len) {
                b->unk_24++;
                b->unk_30 -= len;
                if (b->unk_24 + 1 >= count) {
                    if (b->unk_28 & 4) {
                        func_800FF6AC_SlotCarDerby(i, 0x20);
                        break;
                    }
                    if (b->unk_28 & 0x40) {
                        func_800FF784_SlotCarDerby(i);
                        break;
                    }
                    if (b->unk_28 & 2) {
                        b->unk_24--;
                        break;
                    }
                    b->unk_24 = 0;
                }
            }
        }
    }
}
/* Builds this frame's billboard display list: each visible billboard's matrix (camera-facing
   unless flag 0x80) and material list, then restores the viewport's matrix. */
// scheduling: &Center, the viewport index and the unk_1C base loads (masked 10)
#ifdef NON_MATCHING
void func_800FFD18_SlotCarDerby(void) {
    Mtx view;
    Mtx proj;
    Matrix4f mf;
    Matrix4f tmp;
    Matrix4f sc;
    Vec eye;
    Vec at;
    Vec up;
    SCDBillboard* b;
    Gfx* gfx;
    Mtx* mtx;
    f32 rx;
    f32 ry;
    s32 i;

    func_800FF8A4_SlotCarDerby();
    D_800F2B7C[D_801024A8_SlotCarDerby].unk_6C->unk_00 = &D_80102490_SlotCarDerby[D_80100EA8_SlotCarDerby];
    gfx = D_80102490_SlotCarDerby[D_80100EA8_SlotCarDerby];
    mtx = D_8010249C_SlotCarDerby[D_80100EA8_SlotCarDerby];
    proj = *(&D_800C3110->unk_138 + D_800F3FA8 * 2); /* the viewport's projection pair */
    rx = CRot.x;
    ry = CRot.y;
    eye.x = func_800AEAC0(ry) * func_800AEFD0(rx) * CZoom + Center.x;
    eye.y = -func_800AEAC0(rx) * CZoom + Center.y;
    eye.z = func_800AEFD0(ry) * func_800AEFD0(rx) * CZoom + Center.z;
    at.x = Center.x;
    at.y = Center.y;
    at.z = Center.z;
    up.x = func_800AEAC0(ry) * func_800AEAC0(rx);
    up.y = func_800AEFD0(rx);
    up.z = func_800AEFD0(ry) * func_800AEAC0(rx);
    guLookAt(&view, eye.x, eye.y, eye.z, at.x, at.y, at.z, up.x, up.y, up.z);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gfx++, G_LIGHTING | G_FOG | G_CULL_BOTH);
    gSPSetGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH);
    gDPSetBlendColor(gfx++, 0, 0, 0, 1);
    gDPSetAlphaCompare(gfx++, G_AC_THRESHOLD);
    gSPTexture(gfx++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    for (i = 0; i < D_8010248C_SlotCarDerby; i++) {
        b = &D_80103298[i];
        if (b->unk_00 == (Gfx*)-1 || (b->unk_28 & 0x20)) {
            continue;
        }
        guMtxL2F(mf, &view);
        MtxTranslate(mf, b->unk_38.x, b->unk_38.y, b->unk_38.z);
        MtxRotate(mf, b->unk_50.x, b->unk_50.y, b->unk_50.z);
        MtxScale(mf, b->unk_44.x, b->unk_44.y, b->unk_44.z);
        if (!(b->unk_28 & 0x80)) {
            sc[0][0] = b->unk_44.x;
            sc[1][1] = b->unk_44.y;
            sc[2][2] = b->unk_44.z;
            sc[3][3] = 1.0f;
            sc[0][1] = sc[0][2] = sc[0][3] = sc[1][0] = sc[1][2] = sc[1][3] = sc[2][0] = sc[2][1] = sc[2][3] =
                sc[3][0] = sc[3][1] = sc[3][2] = 0.0f;
            MtxReset(mf, tmp);
            MtxMult(sc, tmp, mf);
        }
        if (b->unk_20 != 0) {
            gSPSegment(gfx++, 1, osVirtualToPhysical(*((Vtx**)b->unk_1C + D_800F37F0 + 2)));
        }
        func_800A0A20(mf, mtx);
        gSPMatrix(gfx++, osVirtualToPhysical(mtx++), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gfx++, b->unk_04[D_800F37F0]);
    }
    gSPMatrix(gfx++, osVirtualToPhysical(&proj), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPEndDisplayList(gfx++);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_25_SlotCarDerby/1C1EB0", func_800FFD18_SlotCarDerby);
#endif
void func_801001F8_SlotCarDerby(void) {
    s32 i;

    for (i = 0; i < D_8010248C_SlotCarDerby; i++) {
        func_800FF784_SlotCarDerby(i);
    }
    HuMemDirectFree(D_80103298);
    for (i = 0; i < 3; i++) {
        HuMemDirectFree(D_80102490_SlotCarDerby[i]);
        HuMemDirectFree(D_8010249C_SlotCarDerby[i]);
    }
}