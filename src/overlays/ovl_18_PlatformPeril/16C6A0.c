#include "PlatformPeril.h"

void func_800F8218_PlatformPeril(omObjData* obj);

f32 D_800FCDA0_PlatformPeril = 0.0f;
s32 D_800FCDA4_PlatformPeril[4] = { -300, -100, 100, 300 }; /* start x per lane */

/* Course pieces: tile rows copied into the tile map (D_800FE5B0). */
PPPiece D_800FCDB4_PlatformPeril[15] = {
    { 48, {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
    } },
    { 60, {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
    } },
    { 72, {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 0, 0, 0, 0, 0, 0, 0,
    } },
    { 60, {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
    } },
    { 60, {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1,
        3, 3, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
    } },
    { 60, {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1,
        3, 3, 3, 3, 2, 2, 3, 3, 3, 3, 3, 3,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
    } },
    { 60, {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1,
        3, 3, 3, 3, 3, 3, 2, 2, 3, 3, 3, 3,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
    } },
    { 60, {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1,
        3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 3, 3,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
    } },
    { 60, {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
    } },
    { 72, {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 0, 0, 0, 0, 0, 0, 0,
    } },
    { 72, {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1,
        3, 3, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 0, 0, 0, 0, 0, 0, 0,
    } },
    { 72, {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1,
        3, 3, 3, 3, 2, 2, 3, 3, 3, 3, 3, 3,
        0, 0, 0, 0, 0, 0, 0, 0,
    } },
    { 72, {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1,
        3, 3, 3, 3, 3, 3, 2, 2, 3, 3, 3, 3,
        0, 0, 0, 0, 0, 0, 0, 0,
    } },
    { 72, {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1,
        3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 3, 3,
        0, 0, 0, 0, 0, 0, 0, 0,
    } },
    { 72, {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2,
        0, 0, 0, 0, 0, 0, 0, 0,
    } },
};
PPPlatform D_800FD2A0_PlatformPeril[30] = {
    { 1, 0, func_800F8218_PlatformPeril, { 0.0f, 50.0f, 100.0f }, { 0.0f, 0.0f, 0.0f } },
    { 17, 0, func_800F87A0_PlatformPeril, { 0.0f, 50.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 16, 0, func_800F815C_PlatformPeril, { -2500.0f, 50.0f, 3000.0f }, { 0.0f, 0.0f, 0.0f } },
    { 16, 0, func_800F815C_PlatformPeril, { -2500.0f, 50.0f, 2000.0f }, { 0.0f, 0.0f, 0.0f } },
    { 16, 0, func_800F815C_PlatformPeril, { -2500.0f, 50.0f, 1000.0f }, { 0.0f, 0.0f, 0.0f } },
    { 16, 0, func_800F815C_PlatformPeril, { -2500.0f, 50.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 16, 0, func_800F815C_PlatformPeril, { -2500.0f, 50.0f, -1000.0f }, { 0.0f, 0.0f, 0.0f } },
    { 16, 0, func_800F815C_PlatformPeril, { -2500.0f, 50.0f, -2000.0f }, { 0.0f, 0.0f, 0.0f } },
    { 16, 0, func_800F815C_PlatformPeril, { -2500.0f, 50.0f, -3000.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0, 0, NULL, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0, 0, NULL, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0, 0, NULL, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0, 0, NULL, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0, 0, NULL, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0, 0, NULL, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0, 0, NULL, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0, 0, NULL, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0, 0, NULL, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0, 0, NULL, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0, 0, NULL, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0, 0, NULL, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0, 0, NULL, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0, 0, NULL, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0, 0, NULL, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0, 0, NULL, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0, 0, NULL, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0, 0, NULL, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0, 0, NULL, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0, 0, NULL, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0, 0, NULL, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
};
PPPlatform D_800FD6D8_PlatformPeril[15] = {
    { 18, 0, func_800F8218_PlatformPeril, { 0.0f, 50.0f, 2000.0f }, { 0.0f, 0.0f, 0.0f } },
    { 2, 0, func_800F8220_PlatformPeril, { 0.0f, 51.0f, 500.0f }, { 10000.0f, 0.0f, 150.0f } },
    { 3, 0, func_800F8220_PlatformPeril, { 0.0f, 51.0f, 600.0f }, { 10000.0f, 0.0f, 200.0f } },
    { 4, 0, func_800F8220_PlatformPeril, { 0.0f, 51.0f, 500.0f }, { -500.0f, 0.0f, 150.0f } },
    { 4, 0, func_800F8220_PlatformPeril, { 0.0f, 51.0f, 500.0f }, { -300.0f, 0.0f, 150.0f } },
    { 4, 0, func_800F8220_PlatformPeril, { 0.0f, 51.0f, 500.0f }, { -100.0f, 0.0f, 150.0f } },
    { 4, 0, func_800F8220_PlatformPeril, { 0.0f, 51.0f, 500.0f }, { 100.0f, 0.0f, 150.0f } },
    { 4, 0, func_800F8220_PlatformPeril, { 0.0f, 51.0f, 500.0f }, { 300.0f, 0.0f, 150.0f } },
    { 4, 0, func_800F8220_PlatformPeril, { 0.0f, 51.0f, 500.0f }, { 500.0f, 0.0f, 150.0f } },
    { 10, 0, func_800F8220_PlatformPeril, { 0.0f, 51.0f, 600.0f }, { -500.0f, 0.0f, 200.0f } },
    { 10, 0, func_800F8220_PlatformPeril, { 0.0f, 51.0f, 600.0f }, { -300.0f, 0.0f, 200.0f } },
    { 10, 0, func_800F8220_PlatformPeril, { 0.0f, 51.0f, 600.0f }, { -100.0f, 0.0f, 200.0f } },
    { 10, 0, func_800F8220_PlatformPeril, { 0.0f, 51.0f, 600.0f }, { 100.0f, 0.0f, 200.0f } },
    { 10, 0, func_800F8220_PlatformPeril, { 0.0f, 51.0f, 600.0f }, { 300.0f, 0.0f, 200.0f } },
    { 10, 0, func_800F8220_PlatformPeril, { 0.0f, 51.0f, 600.0f }, { 500.0f, 0.0f, 200.0f } },
};
PPItem D_800FD8F4_PlatformPeril[30] = { 0 };
s32 D_800FDD2C_PlatformPeril[5] = { 0 };

void func_800F6F60_PlatformPeril(void) {
}

void func_800F6F68_PlatformPeril(void) {
    u8 temp_s0;

    func_800178A0(1);
    temp_s0 = func_800178E8();
    func_80017660(temp_s0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(temp_s0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 30.0f, 80.0f, 8000.0f);
    Center.x = D_800FDD74_PlatformPeril[0].center.x;
    Center.y = D_800FDD74_PlatformPeril[0].center.y;
    Center.z = D_800FDD74_PlatformPeril[0].center.z;
    CRot.x = D_800FDD74_PlatformPeril[0].rot.x;
    CRot.y = D_800FDD74_PlatformPeril[0].rot.y;
    CRot.z = D_800FDD74_PlatformPeril[0].rot.z;
    CZoom = D_800FDD74_PlatformPeril[0].zoom;
}

// register allocation and D_800FE250 reloads (masked 98 incl. address shift; logic-equivalent)
#ifdef NON_MATCHING
/* Builds the course after `out`: random pieces, their items and the tile map. */
void func_800F7070_PlatformPeril(PPPlatform* out) {
    s32 n = 0;
    s32 order[6];
    s32 kinds[3];
    s32 i;
    s32 k;
    s32 t;
    s32 piece;
    u8 j;
    f32 z;

    *(PPOrder6*)order = *(PPOrder6*)D_800FDFB8_PlatformPeril;
    *(PPKinds3*)kinds = *(PPKinds3*)D_800FDFD0_PlatformPeril;
    for (i = 0; i < 6; i++) {
        j = rand8() % 6;
        t = order[i];
        order[i] = order[j];
        order[j] = t;
    }
    for (i = 0; i < 3; i++) {
        j = rand8() % 3;
        t = kinds[i];
        kinds[i] = kinds[j];
        kinds[j] = t;
    }
    D_800FE250_PlatformPeril = 0;
    z = 0.0f;
    for (i = 0; i < (((rand8() << 8) | rand8()) & 1) + 15; i++) {
        if (i >= 4) {
            piece = ((rand8() << 8) | rand8()) % 10 + 3;
        } else {
            piece = (((rand8() << 8) | rand8()) & 0) + 1;
        }
        out[i] = D_800FD6D8_PlatformPeril[piece];
        z -= out[i].pos.z;
        out[i].pos.z = z;
        if (piece >= 3 && D_800FD6D8_PlatformPeril[piece].ofs.x != 0.0f) {
            for (k = 0; k < 3;) {
                if (D_800FE250_PlatformPeril < 3) {
                    k++;
                    if (order[k] == i) {
                        D_800FD8F4_PlatformPeril[D_800FE250_PlatformPeril].pos.x =
                            -D_800FD6D8_PlatformPeril[piece].ofs.x * (f32)(((rand8() << 8) | rand8()) % 4 + 5) * 0.1f;
                        D_800FD8F4_PlatformPeril[D_800FE250_PlatformPeril].pos.y = 100.0f;
                        D_800FD8F4_PlatformPeril[D_800FE250_PlatformPeril].pos.z =
                            z + D_800FD6D8_PlatformPeril[piece].ofs.z + (f32)(((rand8() << 8) | rand8()) % 101 - 50);
                        D_800FD8F4_PlatformPeril[D_800FE250_PlatformPeril].type = kinds[D_800FE250_PlatformPeril];
                        D_800FD8F4_PlatformPeril[D_800FE250_PlatformPeril].func = func_800F8AE8_PlatformPeril;
                        D_800FE250_PlatformPeril++;
                        break;
                    }
                } else {
                    k++;
                }
            }
        }
        for (k = 0; k < D_800FCDB4_PlatformPeril[piece].count; k++) {
            D_800FE5B0_PlatformPeril[0][n++] = D_800FCDB4_PlatformPeril[piece].tiles[k];
        }
    }
    D_800FD8F4_PlatformPeril[D_800FE250_PlatformPeril].type = 0;
    out[i] = D_800FD6D8_PlatformPeril[0];
    z -= out[i].pos.z;
    out[i].pos.z = z;
    D_800FE2CC_PlatformPeril = z + 1500.0f;
    for (k = 0; k < D_800FCDB4_PlatformPeril[0].count; k++) {
        D_800FE5B0_PlatformPeril[0][n++] = D_800FCDB4_PlatformPeril[0].tiles[k];
    }
    out[i + 1].type = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_18_PlatformPeril/16C6A0", func_800F7070_PlatformPeril);
#endif

void func_800F76E4_PlatformPeril(void) {
    s32 i;
    s32 j;

    D_800FE1D0_PlatformPeril = 0;
    D_800FE1D4_PlatformPeril = 0;
    func_800090B8(D_800ED440);
    for (i = 0; i < 4; i++) {
        D_800FE258_PlatformPeril[i] = ((rand8() << 8) | rand8()) % 4;
        for (j = 0; j < i; j++) {
            if (D_800FE258_PlatformPeril[j] == D_800FE258_PlatformPeril[i]) {
                i--;
                break;
            }
        }
    }
    for (i = 0; D_800FD2A0_PlatformPeril[i].type != 0; i++) {
    }
    func_800F7070_PlatformPeril(&D_800FD2A0_PlatformPeril[i]);
    for (i = 0; D_800FD2A0_PlatformPeril[i].type != 0; i++) {
        omAddObj(0xA, 5, 5, -1, func_800F7868_PlatformPeril);
    }
}

/* Item kinds, shuffled by func_800F7070. */
const s32 D_800FDFD0_PlatformPeril[4] __attribute__((section(".rodata"))) = { 5, 1, 1, 0 };

// register allocation in the scenery switch (masked ~20)
#ifdef NON_MATCHING
/* Platform / scenery object set-up (D_800FD2A0[D_800FE1D0]). */
void func_800F7868_PlatformPeril(omObjData* obj) {
    PPPlatWork* w;
    s32 i;
    s32 y;

    obj->trans.x = D_800FD2A0_PlatformPeril[D_800FE1D0_PlatformPeril].pos.x;
    obj->trans.y = D_800FD2A0_PlatformPeril[D_800FE1D0_PlatformPeril].pos.y;
    obj->trans.z = D_800FD2A0_PlatformPeril[D_800FE1D0_PlatformPeril].pos.z;
    obj->func_ptr = D_800FD2A0_PlatformPeril[D_800FE1D0_PlatformPeril].func;
    obj->work[0] = obj->work[1] = obj->work[2] = obj->work[3] = 0;
    obj->model[0] = -1;
    D_800FE1D8_PlatformPeril[D_800FE1D4_PlatformPeril++] = obj;
    w = obj->unk_50 = func_80023684(sizeof(PPPlatWork), 0x7918);
    func_8009B770(w, 0, sizeof(PPPlatWork));
    w->unk_04 = 1;
    w->index = (u8)D_800FE1D0_PlatformPeril;
    switch (D_800FD2A0_PlatformPeril[D_800FE1D0_PlatformPeril].type) {
    case 1:
        D_800F2AF8[D_800ED440++] = obj;
        func_80008FB8(obj, 0.8f);
        func_80009058(obj, obj->trans.y + 0.0f, obj->trans.y + 1.0f, obj->trans.x + -2000.0f, obj->trans.z + -15000.0f,
                      obj->trans.x + 2000.0f, obj->trans.z + 200.0f);
        for (i = 0; i < 4; i++) {
            func_800090C4(D_800FE540_PlatformPeril[i], (u8)D_800FE1D0_PlatformPeril, 2);
        }
        break;
    case 2:
        obj->model[0] = func_800174C0(0x2A0000, 0x99);
        obj->model[1] = -1;
        break;
    case 3:
        obj->model[0] = func_800174C0(0x2A0001, 0x99);
        obj->model[1] = -1;
        break;
    case 4:
        obj->model[0] = func_800174C0(0x2A0000, 0x99);
        obj->model[1] = func_800174C0(0x2A0004, 0x99);
        func_80025830(obj->model[1], obj->scale.x, obj->scale.y, obj->scale.z * 1.5f);
        func_800257E4(obj->model[1], obj->rot.x, obj->rot.y, obj->rot.z);
        func_80025798(obj->model[1], obj->trans.x + D_800FD2A0_PlatformPeril[D_800FE1D0_PlatformPeril].ofs.x,
                      obj->trans.y + D_800FD2A0_PlatformPeril[D_800FE1D0_PlatformPeril].ofs.y,
                      obj->trans.z + D_800FD2A0_PlatformPeril[D_800FE1D0_PlatformPeril].ofs.z);
        break;
    case 10:
        obj->model[0] = func_800174C0(0x2A0001, 0x99);
        obj->model[1] = func_800174C0(0x2A0004, 0x99);
        func_80025830(obj->model[1], obj->scale.x, obj->scale.y, 2.0f * obj->scale.z);
        func_800257E4(obj->model[1], obj->rot.x, obj->rot.y, obj->rot.z);
        func_80025798(obj->model[1], obj->trans.x + D_800FD2A0_PlatformPeril[D_800FE1D0_PlatformPeril].ofs.x,
                      obj->trans.y + D_800FD2A0_PlatformPeril[D_800FE1D0_PlatformPeril].ofs.y,
                      obj->trans.z + D_800FD2A0_PlatformPeril[D_800FE1D0_PlatformPeril].ofs.z);
        break;
    case 17:
        obj->model[0] = func_800174C0(0x2A0002, 0x99);
        break;
    case 18:
        obj->model[0] = func_800174C0(0x2A0003, 0x99);
        func_80025798(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
        break;
    case 16:
        switch (((rand8() << 8) | rand8()) % 4) {
        case 0:
            obj->model[0] = func_800174C0(0x2A0005, 0x99);
            obj->trans.x = ((rand8() << 8) | rand8()) % 401 - 500;
            y = ((rand8() << 8) | rand8()) % 401 - 1000;
            break;
        case 1:
            obj->model[0] = func_800174C0(0x2A0006, 0x99);
            obj->trans.x = ((rand8() << 8) | rand8()) % 901 - 1000;
            y = ((rand8() << 8) | rand8()) % 501 - 1500;
            break;
        case 2:
            obj->model[0] = func_800174C0(0x2A0007, 0x99);
            obj->trans.x = ((rand8() << 8) | rand8()) % 1901 - 2000;
            y = ((rand8() << 8) | rand8()) % 501 - 2000;
            break;
        default:
            obj->model[0] = func_800174C0(0x2A0008, 0x99);
            obj->trans.x = ((rand8() << 8) | rand8()) % 2901 - 3000;
            y = ((rand8() << 8) | rand8()) % 1001 - 3000;
            break;
        }
        obj->trans.y = y;
        obj->work[0] = ((rand8() << 8) | rand8()) % 6;
        obj->work[1] = ((rand8() << 8) | rand8()) % 11;
        obj->work[2] = ((rand8() << 8) | rand8()) % 256;
        obj->work[3] = ((rand8() << 8) | rand8()) % 256;
        break;
    }
    D_800FE1D0_PlatformPeril++;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_18_PlatformPeril/16C6A0", func_800F7868_PlatformPeril);
#endif

/* Scenery: scrolls towards the camera and wraps. */
void func_800F815C_PlatformPeril(omObjData* obj) {
    obj->scale.x = 2.0f;
    obj->scale.y = 2.0f;
    obj->scale.z = 2.0f;
    obj->trans.z += 12.0f;
    if (Center.z - 800.0f < obj->trans.z - 3250.0f) {
        obj->trans.z -= 9750.0f;
    }
    if (D_800FE2F8_PlatformPeril == 5) {
        func_800258EC(obj->model[0], 4, 4);
    }
}

void func_800F8218_PlatformPeril(omObjData* obj) {
}

// float register choice (masked 4)
#ifdef NON_MATCHING
/* Falling platform: shakes (state 1), falls (2, 3), parks (4). */
void func_800F8220_PlatformPeril(omObjData* obj) {
    PPPlatWork* w = obj->unk_50;
    f32 rz;

    switch (D_800FD2A0_PlatformPeril[w->index].state) {
    case 1:
        if (obj->work[1] == 0 && obj->work[2] == 0) {
            obj->work[1] = 0;
            obj->work[2] = 0;
            obj->work[3] = 0;
        }
        obj->rot.x = (f32)((((rand8() << 8) | rand8()) % 31 - 15) * obj->work[0]) / 1200.0f;
        obj->rot.y = (f32)((((rand8() << 8) | rand8()) % 31 - 15) * obj->work[0]) / 1200.0f;
        obj->rot.z = rz = (f32)((((rand8() << 8) | rand8()) % 31 - 15) * obj->work[0]) / 1200.0f;
        if (obj->model[1] != -1) {
            func_80025798(obj->model[1], obj->trans.x + D_800FD2A0_PlatformPeril[w->index].ofs.x + obj->rot.x * 5.0f,
                          obj->trans.y + D_800FD2A0_PlatformPeril[w->index].ofs.y + obj->rot.y * 10.0f,
                          obj->trans.z + D_800FD2A0_PlatformPeril[w->index].ofs.z + rz * 5.0f);
        }
        if (obj->work[0]++ >= 0x33) {
            D_800FD2A0_PlatformPeril[w->index].state = 2;
            obj->work[0] = 0;
            obj->work[1] = 0;
            obj->work[2] = 0;
            obj->work[3] = 0;
        }
        break;
    case 0:
        obj->work[0] = 0;
        obj->work[1] = 0;
        obj->work[2] = 0;
        obj->work[3] = 0;
        break;
    case 2:
        obj->work[0]++;
        obj->work[1] += 5;
        obj->trans.y -= obj->work[1];
        if (obj->model[1] != -1) {
            func_80025798(obj->model[1], obj->trans.x + D_800FD2A0_PlatformPeril[w->index].ofs.x,
                          obj->trans.y + D_800FD2A0_PlatformPeril[w->index].ofs.y,
                          obj->trans.z + D_800FD2A0_PlatformPeril[w->index].ofs.z);
        }
        if (obj->trans.y < -300.0f) {
            D_800FD2A0_PlatformPeril[w->index].state = 3;
            PlaySound(0x28B);
        }
        break;
    case 3:
        obj->work[0]++;
        obj->work[1] += 5;
        obj->trans.y -= obj->work[1];
        if (obj->model[1] != -1) {
            func_80025798(obj->model[1], obj->trans.x + D_800FD2A0_PlatformPeril[w->index].ofs.x,
                          obj->trans.y + D_800FD2A0_PlatformPeril[w->index].ofs.y,
                          obj->trans.z + D_800FD2A0_PlatformPeril[w->index].ofs.z);
        }
        if (obj->trans.y < -5000.0f) {
            D_800FD2A0_PlatformPeril[w->index].state = 4;
        }
        break;
    case 4:
        obj->trans.x = obj->trans.y = obj->trans.z = -5000.0f;
        if (obj->model[1] != -1) {
            func_80025798(obj->model[1], obj->trans.x + D_800FD2A0_PlatformPeril[w->index].ofs.x + obj->rot.x * 5.0f,
                          obj->trans.y + D_800FD2A0_PlatformPeril[w->index].ofs.y + obj->rot.y * 10.0f,
                          obj->trans.z + D_800FD2A0_PlatformPeril[w->index].ofs.z + obj->rot.z * 5.0f);
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_18_PlatformPeril/16C6A0", func_800F8220_PlatformPeril);
#endif

/* Start platform: drops once the race is on. */
void func_800F87A0_PlatformPeril(omObjData* obj) {
    PPPlatWork* w = obj->unk_50;

    if (D_800FE2F8_PlatformPeril != 4) {
        return;
    }
    switch (D_800FD2A0_PlatformPeril[w->index].state) {
    case 1:
        if (obj->work[1] == 0 && obj->work[2] == 0) {
            obj->work[1] = 0;
            obj->work[2] = 0;
            obj->work[3] = 0;
        }
        obj->rot.x = (f32)((((rand8() << 8) | rand8()) % 31 - 15) * obj->work[0]) / 1200.0f;
        obj->rot.y = (f32)((((rand8() << 8) | rand8()) % 31 - 15) * obj->work[0]) / 1200.0f;
        obj->rot.z = (f32)((((rand8() << 8) | rand8()) % 31 - 15) * obj->work[0]) / 1200.0f;
        if (obj->work[0]++ >= 0x47) {
            D_800FD2A0_PlatformPeril[w->index].state = 2;
            obj->work[0] = 0;
            obj->work[1] = 0;
            obj->work[2] = 0;
            obj->work[3] = 0;
        }
        break;
    case 0:
        obj->work[0] = 0;
        obj->work[1] = 0;
        obj->work[2] = 0;
        obj->work[3] = 0;
        break;
    case 2:
        obj->work[0]++;
        obj->work[1] += 5;
        obj->trans.y -= obj->work[1];
        if (obj->trans.y < -300.0f) {
            D_800FD2A0_PlatformPeril[w->index].state = 3;
        }
        break;
    case 3:
        obj->work[0]++;
        obj->work[1] += 5;
        obj->trans.y -= obj->work[1];
        if (obj->trans.y < -5000.0f) {
            D_800FD2A0_PlatformPeril[w->index].state = 4;
        }
        break;
    case 4:
        obj->trans.x = obj->trans.y = obj->trans.z = -5000.0f;
        break;
    }
}

void func_800F8AE8_PlatformPeril(omObjData* arg0) {
    arg0->trans.y = D_800FE1D8_PlatformPeril[arg0->work[0]]->trans.y + 50.0f;
    func_80025798(arg0->model[1], arg0->trans.x, D_800FE1D8_PlatformPeril[arg0->work[0]]->trans.y, arg0->trans.z);
    func_80025830(arg0->model[1], 0.7f, 0.7f, 0.7f);
}

void func_800F8B7C_PlatformPeril(void) {
    s32 i;
    D_800FE250_PlatformPeril = 0;
    
    for (i = 0; D_800FD8F4_PlatformPeril[i].type != 0; i++) {
        D_800EDE70[D_800EE984++] = omAddObj(0xA, 5, 5, -1, &func_800F8C2C_PlatformPeril);
    }
}

// loop exit layout, float register (masked 5)
#ifdef NON_MATCHING
/* Item (Koopa, Shy Guy, ...) object set-up (D_800FD8F4[D_800FE250]). */
void func_800F8C2C_PlatformPeril(omObjData* obj) {
    PPItemWork* w;
    s32 i;

    obj->trans.x = D_800FD8F4_PlatformPeril[D_800FE250_PlatformPeril].pos.x;
    obj->trans.y = D_800FD8F4_PlatformPeril[D_800FE250_PlatformPeril].pos.y;
    obj->trans.z = D_800FD8F4_PlatformPeril[D_800FE250_PlatformPeril].pos.z;
    obj->func_ptr = func_800F6F60_PlatformPeril;
    obj->work[0] = obj->work[1] = obj->work[2] = obj->work[3] = 0;
    for (i = D_800FE1D4_PlatformPeril - 1; i > 0; i--) {
        if (D_800FE1D8_PlatformPeril[i]->trans.z - 200.0f < obj->trans.z && obj->trans.z < D_800FE1D8_PlatformPeril[i]->trans.z + 550.0f) {
            if (obj->trans.y > 50.0f) {
                obj->work[0] = i;
            }
            break;
        }
    }
    w = obj->unk_50 = func_80023684(sizeof(PPItemWork), 0x7918);
    func_8009B770(w, 0, sizeof(PPItemWork));
    switch (D_800FD8F4_PlatformPeril[D_800FE250_PlatformPeril].type) {
    case 1:
        func_800091BC(obj, 0x21, 0x289, 8);
        func_80009340(obj, 2, 0x25, 0x289, 8);
        func_80009340(obj, 3, 0x2A, 0x689, 8);
        func_8001E360(w->unk_24, 0xFF, 0xFF, 0xBE);
        func_8000941C(obj, 3.0f, 3.0f, 3.0f);
        func_80025830(obj->model[3], 2.0f, 2.0f, 2.0f);
        w->unk_52 = 3;
        obj->work[0] = 1;
        break;
    case 2:
        func_800091BC(obj, 0x22, 0x289, 8);
        func_80009340(obj, 2, 0x25, 0x289, 8);
        func_80009340(obj, 3, 0x34, 0x689, 8);
        func_8000941C(obj, 3.0f, 3.0f, 3.0f);
        w->unk_52 = 4;
        break;
    case 3:
        func_800091BC(obj, 0x23, 0x289, 8);
        func_80009340(obj, 2, 0x25, 0x289, 8);
        func_80009340(obj, 3, 0x34, 0x689, 8);
        func_8000941C(obj, 3.0f, 3.0f, 3.0f);
        w->unk_52 = 5;
        break;
    case 4:
        obj->model[0] = func_800174C0(0xA, 0x99);
        func_80009340(obj, 2, 0x25, 0x289, 8);
        func_8000941C(obj, 1.4f, 1.4f, 1.4f);
        w->unk_52 = 7;
        break;
    case 5:
        func_800091BC(obj, 0x37, 0xA89, 8);
        func_80009340(obj, 2, 0x25, 0x289, 8);
        func_80009340(obj, 3, 0x2A, 0x689, 8);
        func_8000941C(obj, 4.0f, 4.0f, 4.0f);
        func_80025830(obj->model[3], 2.0f, 2.0f, 2.0f);
        w->unk_52 = 6;
        obj->work[0] = 5;
        func_8001E360(w->unk_24, 0xFF, 0xFF, 0xBE);
        break;
    }
    obj->model[1] = LoadFormFile(6, 0x699);
    func_80025798(obj->model[1], obj->trans.x, 50.0f, obj->trans.z);
    func_80025830(obj->model[1], 1.0f, 1.0f, 1.0f);
    w->unk_5C = 0;
    w->unk_60 = 0x3C;
    w->unk_44 = 0.1f;
    w->unk_48 = 80.0f;
    w->unk_34 = 50.0f;
    w->unk_3C = 0.0f;
    w->unk_54 = 1;
    D_800FE250_PlatformPeril++;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_18_PlatformPeril/16C6A0", func_800F8C2C_PlatformPeril);
#endif

void func_800F90C0_PlatformPeril(void) {
    D_800FCDA0_PlatformPeril = 300.0f;
    D_800FE2B0_PlatformPeril[0] = 0;
    D_800FE2B0_PlatformPeril[1] = 0;
    D_800FE2B0_PlatformPeril[2] = 0;
    D_800FE2B0_PlatformPeril[3] = 0;
    func_80009500();
    func_80009618(0);
    D_800B8955 = 0;
    func_8005D98C(2, 4);
    D_800F3FB0[D_800F2BC0++] = omAddObj(2, 9, 0x3C, 2, &func_800F94EC_PlatformPeril);
    D_800F3FB0[D_800F2BC0++] = omAddObj(2, 9, 0x3C, 2, &func_800F9598_PlatformPeril);
    D_800F3FB0[D_800F2BC0++] = omAddObj(2, 9, 0x3C, 2, &func_800F9644_PlatformPeril);
    D_800F3FB0[D_800F2BC0++] = omAddObj(2, 9, 0x3C, 2, &func_800F96F0_PlatformPeril);
}

void func_800F922C_PlatformPeril(omObjData* arg0, s32 arg1, s32 arg2, u16 arg3, f32 arg4, f32 arg5, f32 arg6) {
    unkGlobalStruct_00* temp_s0_2;
    s32 i;
    s32 temp = 0x699;

    func_8000979C(arg0, arg1, arg2, arg3, temp, temp);
    D_800FE2A0_PlatformPeril[arg3] = GwPlayer[arg3].cpu_difficulty;
    func_800187D0(arg0, 0, arg1, 1, 0);
    func_800187D0(arg0, 1, arg1 | 1, 1, 0);
    func_800187D0(arg0, 2, arg1 | 3, 1, 0);
    func_800187D0(arg0, 6, arg1 | 5, 1, 0x13);
    
    if (!(rand8() & 1)) {
        func_8001775C(arg0, 0xD, arg1 | 0xF);
        func_8001775C(arg0, 0xE, arg1 | 0x10);
    } else {
        func_8001775C(arg0, 0xD, arg1 | 0x38);
        func_8001775C(arg0, 0xE, arg1 | 0x3C);
    }
    
    func_8001874C(arg0, 0x15, arg1 | 0x62, 0, 0);
    arg0->trans.x = arg4;
    arg0->trans.y = arg5;
    arg0->trans.z = arg6;
    arg0->scale.x = 1.0f;
    arg0->scale.y = 1.0f;
    arg0->scale.z = 1.0f;
    MtxRotate(D_800F2B7C[arg0->model[0]].unk7C, 0, 180.0f, 0);
    func_80025830(arg0->model[1], arg0->scale.x, arg0->scale.y, arg0->scale.z);
    func_800257E4(arg0->model[1], arg0->rot.x, arg0->rot.y, arg0->rot.z);
    func_80025798(arg0->model[1], arg0->trans.x, 1.0f, arg0->trans.z);
    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    temp_s0_2 = arg0->unk_50;
    func_80008FD0(arg0, 30.0f);
    arg0->func_ptr = &func_800F979C_PlatformPeril;
    arg0->work[0] = arg3;
    
    if (GwPlayer[arg3].flags & 1) { //checking if CPU?
        arg0->work[1] = 1;
    } else {
        arg0->work[1] = 0;
    }
    
    arg0->work[2] = 0;

    for (i = 0; i < 4; i++) {
        D_800FE1B0_PlatformPeril[i].fall = 0.0f;
        D_800FE1B0_PlatformPeril[i].state = 0;
    }
    temp_s0_2->unk_3C = 180.0f;
}

void func_800F94EC_PlatformPeril(omObjData* obj) {
    s32 file = D_800C59AC[GwPlayer[0].character].unk_04;
    s32 dir = D_800C59AC[GwPlayer[0].character].unk_00;

    D_800FE540_PlatformPeril[0] = obj;
    func_800F922C_PlatformPeril(obj, dir, file, 0, D_800FCDA4_PlatformPeril[D_800FE258_PlatformPeril[0]], 51.0f, 295.0f);
    ((unkGlobalStruct_00*)obj->unk_50)->unk_50 = 0x200;
}

void func_800F9598_PlatformPeril(omObjData* obj) {
    s32 file = D_800C59AC[GwPlayer[1].character].unk_04;
    s32 dir = D_800C59AC[GwPlayer[1].character].unk_00;

    D_800FE540_PlatformPeril[1] = obj;
    func_800F922C_PlatformPeril(obj, dir, file, 1, D_800FCDA4_PlatformPeril[D_800FE258_PlatformPeril[1]], 51.0f, 295.0f);
    ((unkGlobalStruct_00*)obj->unk_50)->unk_50 = 0x200;
}

void func_800F9644_PlatformPeril(omObjData* obj) {
    s32 file = D_800C59AC[GwPlayer[2].character].unk_04;
    s32 dir = D_800C59AC[GwPlayer[2].character].unk_00;

    D_800FE540_PlatformPeril[2] = obj;
    func_800F922C_PlatformPeril(obj, dir, file, 2, D_800FCDA4_PlatformPeril[D_800FE258_PlatformPeril[2]], 51.0f, 295.0f);
    ((unkGlobalStruct_00*)obj->unk_50)->unk_50 = 0x200;
}

void func_800F96F0_PlatformPeril(omObjData* obj) {
    s32 file = D_800C59AC[GwPlayer[3].character].unk_04;
    s32 dir = D_800C59AC[GwPlayer[3].character].unk_00;

    D_800FE540_PlatformPeril[3] = obj;
    func_800F922C_PlatformPeril(obj, dir, file, 3, D_800FCDA4_PlatformPeril[D_800FE258_PlatformPeril[3]], 51.0f, 295.0f);
    ((unkGlobalStruct_00*)obj->unk_50)->unk_50 = 0x200;
}

#define PP_PWORK(o) ((unkGlobalStruct_00*)(o)->unk_50)
#define PP_BOX(xl, xr, zl, zr) \
    ((xl) - 0.0f < obj->trans.x && obj->trans.x < (xr) + 0.0f && (zl) - 20.0f < obj->trans.z && obj->trans.z < (zr) + 20.0f)

// GCC cross-jumps the case 10 slope tail into case 4's, plus register allocation (masked 224 incl. that 46-instruction merge; logic-equivalent)
#ifdef NON_MATCHING
/* Player main: camera follow, platform collision, goal steps, falling. */
void func_800F979C_PlatformPeril(omObjData* obj) {
    s32 pl = obj->work[0];
    s32 idx = PP_PWORK(obj)->unk_58;
    s32 port = PP_PWORK(obj)->unk_56;
    s32 hit;
    s32 i;
    s32 j;
    f32 cx;
    f32 cy;
    f32 cz;
    f32 s;
    f32 xl;
    f32 xr;
    f32 zl;
    f32 zr;
    f32 w;
    f32 dx;
    f32 a;
    f32 b;
    f32 sx;
    f32 sy;

    if (D_800FE1B0_PlatformPeril[idx].state == -1) {
        return;
    }
    D_800FDD2C_PlatformPeril[pl] = GwPlayer[pl].coins_mg;
    if (obj->trans.z < D_800FCDA0_PlatformPeril) {
        D_800FCDA0_PlatformPeril = obj->trans.z;
        Center.z = obj->trans.z + 100.0f;
    }
    hit = -1;
    for (i = 0; D_800FD2A0_PlatformPeril[i].type != 0; i++) {
        if (D_800FD2A0_PlatformPeril[i].type != 18 && D_800FD2A0_PlatformPeril[i].state >= 3) {
            continue;
        }
        switch (D_800FD2A0_PlatformPeril[i].type) {
        case 2:
            if (PP_BOX(D_800FD2A0_PlatformPeril[i].pos.x - 600.0f, D_800FD2A0_PlatformPeril[i].pos.x + 600.0f,
                       D_800FD2A0_PlatformPeril[i].pos.z - 0.0f, D_800FD2A0_PlatformPeril[i].pos.z + 300.0f)) {
                hit = i;
            }
            break;
        case 4:
            if (PP_BOX(D_800FD2A0_PlatformPeril[i].pos.x - 600.0f, D_800FD2A0_PlatformPeril[i].pos.x + 600.0f,
                       D_800FD2A0_PlatformPeril[i].pos.z - 0.0f, D_800FD2A0_PlatformPeril[i].pos.z + 300.0f)) {
                hit = i;
                cx = D_800FD2A0_PlatformPeril[i].pos.x + D_800FD2A0_PlatformPeril[i].ofs.x;
                cy = D_800FD2A0_PlatformPeril[i].pos.y + D_800FD2A0_PlatformPeril[i].ofs.y;
                cz = D_800FD2A0_PlatformPeril[i].pos.z + D_800FD2A0_PlatformPeril[i].ofs.z;
                s = 1.0f - (obj->trans.y - cy) / 150.0f;
                xl = cx - s * 100.0f;
                xr = cx + s * 100.0f;
                zl = cz - s * 130.0f;
                zr = cz + s * 170.0f;
                if (xl < obj->trans.x && obj->trans.x < xr && zl < obj->trans.z && obj->trans.z < zr &&
                    0.0f <= obj->trans.y && obj->trans.y < 150.0f) {
                    w = xr - xl;
                    dx = obj->trans.x - xl;
                    a = (zl - zr) / w * dx + zr - obj->trans.z;
                    b = (zr - zl) / w * dx + zl - obj->trans.z;
                    if (a > 0.0f) {
                        if (b > 0.0f) {
                            obj->trans.z = zl;
                        } else {
                            obj->trans.x = xl;
                        }
                    } else if (b > 0.0f) {
                        obj->trans.x = xr;
                    } else {
                        obj->trans.z = zr;
                    }
                }
            }
            break;
        case 3:
            if (PP_BOX(D_800FD2A0_PlatformPeril[i].pos.x - 600.0f, D_800FD2A0_PlatformPeril[i].pos.x + 600.0f,
                       D_800FD2A0_PlatformPeril[i].pos.z - 0.0f, D_800FD2A0_PlatformPeril[i].pos.z + 400.0f)) {
                hit = i;
            }
            break;
        case 10:
            if (PP_BOX(D_800FD2A0_PlatformPeril[i].pos.x - 600.0f, D_800FD2A0_PlatformPeril[i].pos.x + 600.0f,
                       D_800FD2A0_PlatformPeril[i].pos.z - 0.0f, D_800FD2A0_PlatformPeril[i].pos.z + 400.0f)) {
                hit = i;
                cx = D_800FD2A0_PlatformPeril[i].pos.x + D_800FD2A0_PlatformPeril[i].ofs.x;
                cy = D_800FD2A0_PlatformPeril[i].pos.y + D_800FD2A0_PlatformPeril[i].ofs.y;
                cz = D_800FD2A0_PlatformPeril[i].pos.z + D_800FD2A0_PlatformPeril[i].ofs.z;
                s = 1.0f - (obj->trans.y - cy) / 150.0f;
                xl = cx - s * 100.0f;
                xr = cx + s * 100.0f;
                zl = cz - s * 180.0f;
                zr = cz + s * 220.0f;
                if (xl < obj->trans.x && obj->trans.x < xr && zl < obj->trans.z && obj->trans.z < zr &&
                    0.0f <= obj->trans.y && obj->trans.y < 150.0f) {
                    w = xr - xl;
                    dx = obj->trans.x - xl;
                    a = (zl - zr) / w * dx + zr - obj->trans.z;
                    b = (zr - zl) / w * dx + zl - obj->trans.z;
                    if (a > 0.0f) {
                        if (!(b > 0.0f)) {
                            obj->trans.x = xl;
                        } else {
                            obj->trans.z = zl;
                        }
                    } else if (!(b > 0.0f)) {
                        obj->trans.z = zr;
                    } else {
                        obj->trans.x = xr;
                    }
                }
            }
            break;
        case 17:
            if (PP_BOX(D_800FD2A0_PlatformPeril[i].pos.x - 600.0f, D_800FD2A0_PlatformPeril[i].pos.x + 600.0f,
                       D_800FD2A0_PlatformPeril[i].pos.z - 0.0f, D_800FD2A0_PlatformPeril[i].pos.z + 600.0f)) {
                hit = i;
            }
            break;
        case 18:
            /* The goal and its steps on both sides. */
            if (PP_BOX(D_800FD2A0_PlatformPeril[i].pos.x - 600.0f, D_800FD2A0_PlatformPeril[i].pos.x + 600.0f,
                       D_800FD2A0_PlatformPeril[i].pos.z - 0.0f, D_800FD2A0_PlatformPeril[i].pos.z + 1800.0f) ||
                PP_BOX(D_800FD2A0_PlatformPeril[i].pos.x - 650.0f, D_800FD2A0_PlatformPeril[i].pos.x - 600.0f,
                       D_800FD2A0_PlatformPeril[i].pos.z + 1550.0f, D_800FD2A0_PlatformPeril[i].pos.z + 1750.0f) ||
                PP_BOX(D_800FD2A0_PlatformPeril[i].pos.x + 600.0f, D_800FD2A0_PlatformPeril[i].pos.x + 650.0f,
                       D_800FD2A0_PlatformPeril[i].pos.z + 1550.0f, D_800FD2A0_PlatformPeril[i].pos.z + 1750.0f) ||
                PP_BOX(D_800FD2A0_PlatformPeril[i].pos.x - 700.0f, D_800FD2A0_PlatformPeril[i].pos.x - 650.0f,
                       D_800FD2A0_PlatformPeril[i].pos.z + 1400.0f, D_800FD2A0_PlatformPeril[i].pos.z + 1600.0f) ||
                PP_BOX(D_800FD2A0_PlatformPeril[i].pos.x + 650.0f, D_800FD2A0_PlatformPeril[i].pos.x + 700.0f,
                       D_800FD2A0_PlatformPeril[i].pos.z + 1400.0f, D_800FD2A0_PlatformPeril[i].pos.z + 1600.0f) ||
                PP_BOX(D_800FD2A0_PlatformPeril[i].pos.x - 750.0f, D_800FD2A0_PlatformPeril[i].pos.x - 700.0f,
                       D_800FD2A0_PlatformPeril[i].pos.z + 1250.0f, D_800FD2A0_PlatformPeril[i].pos.z + 1450.0f) ||
                PP_BOX(D_800FD2A0_PlatformPeril[i].pos.x + 700.0f, D_800FD2A0_PlatformPeril[i].pos.x + 750.0f,
                       D_800FD2A0_PlatformPeril[i].pos.z + 1250.0f, D_800FD2A0_PlatformPeril[i].pos.z + 1450.0f) ||
                PP_BOX(D_800FD2A0_PlatformPeril[i].pos.x - 800.0f, D_800FD2A0_PlatformPeril[i].pos.x - 750.0f,
                       D_800FD2A0_PlatformPeril[i].pos.z + 1150.0f, D_800FD2A0_PlatformPeril[i].pos.z + 1350.0f) ||
                PP_BOX(D_800FD2A0_PlatformPeril[i].pos.x + 750.0f, D_800FD2A0_PlatformPeril[i].pos.x + 800.0f,
                       D_800FD2A0_PlatformPeril[i].pos.z + 1150.0f, D_800FD2A0_PlatformPeril[i].pos.z + 1350.0f)) {
                if (!(PP_PWORK(obj)->unk_5C & 0x20)) {
                    for (j = 0; j < 4; j++) {
                        if (idx == j) {
                            D_800FE1B0_PlatformPeril[idx].state = 2;
                        }
                    }
                    D_800FE2B0_PlatformPeril[idx] = 1;
                }
                hit = i;
            }
            break;
        }
    }
    switch (D_800FE1B0_PlatformPeril[idx].state) {
    case 0:
        /* The course runs diagonally: rotate the stick by 45 degrees. */
        sx = ContStkX[port];
        sy = ContStkY[port];
        ContStkX[port] = sinf(0.785375f) * sx - cosf(0.785375f) * sy;
        ContStkY[port] = cosf(0.785375f) * sx + sinf(0.785375f) * sy;
        func_800FBCD4_PlatformPeril(obj);
        func_80025830(obj->model[1], obj->scale.x, obj->scale.y, obj->scale.z);
        func_800257E4(obj->model[1], obj->rot.x, obj->rot.y, obj->rot.z);
        func_80025798(obj->model[1], obj->trans.x, 50.0f, obj->trans.z);
        if (hit == -1) {
            if (!(PP_PWORK(obj)->unk_5C & 0x20)) {
                D_800FE1B0_PlatformPeril[idx].state = 1;
            }
        } else if (!(PP_PWORK(obj)->unk_5C & 0x20) && D_800FD2A0_PlatformPeril[hit].state == 0) {
            D_800FD2A0_PlatformPeril[hit].state = 1;
        }
        break;
    case 1:
        if (D_800FE1B0_PlatformPeril[idx].fall == 0.0) {
            func_80060618(0x45F, pl);
        }
        D_800FE1B0_PlatformPeril[idx].fall += 5.0f;
        obj->trans.y -= D_800FE1B0_PlatformPeril[idx].fall;
        if (obj->trans.y <= -5000.0f) {
            D_800FE1B0_PlatformPeril[idx].state = 3;
        }
        func_80025830(obj->model[1], obj->scale.x, obj->scale.y, obj->scale.z);
        func_800257E4(obj->model[1], obj->rot.x, obj->rot.y, obj->rot.z);
        func_80025798(obj->model[1], obj->trans.x, 10000.0f, obj->trans.z);
        break;
    case 3:
        D_800FE2C4_PlatformPeril &= ~D_800FDD60_PlatformPeril[pl];
        obj->work[2] = 0xFF;
        obj->trans.x = 5000.0f;
        obj->trans.y = -5000.0f;
        obj->trans.z = 5000.0f;
        func_80025830(obj->model[1], obj->scale.x, obj->scale.y, obj->scale.z);
        func_800257E4(obj->model[1], obj->rot.x, obj->rot.y, obj->rot.z);
        func_80025798(obj->model[1], obj->trans.x, 10000.0f, obj->trans.z);
        func_800258EC(obj->model[0], 4, 4);
        func_800258EC(obj->model[1], 4, 4);
        break;
    case 2:
        D_800FE1D8_PlatformPeril[1]->trans.y = -5000.0f;
        ContStkX[port] = 0;
        ContStkY[port] = 0;
        func_800FBCD4_PlatformPeril(obj);
        func_80025830(obj->model[1], obj->scale.x, obj->scale.y, obj->scale.z);
        func_800257E4(obj->model[1], obj->rot.x, obj->rot.y, obj->rot.z);
        func_80025798(obj->model[1], obj->trans.x, 50.0f, obj->trans.z);
        break;
    }
    if (300.0f < obj->trans.z) {
        D_800FE1B0_PlatformPeril[idx].state = 3;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_18_PlatformPeril/16C6A0", func_800F979C_PlatformPeril);
#endif

// decomp-permuter
void func_800FAAE0_PlatformPeril(f32 t, PPCamKey *k, PPCamKey *out)
{
  f32 s = 1.0f - t;
  f32 a = ((1.0f - t) * (1.0f - t)) / 2.0f;
  f32 b = ((1.0f - t) * t) + 0.5f;
  f32 c = (t * t) / 2.0f;
  if (k[2].zoom < 0.0f)
  {
    out->zoom = ((a * k[0].zoom) + (b * k[1].zoom)) + (c * k[1].zoom);
    out->rot.x = ((a * k[0].rot.x) + (b * k[1].rot.x)) + (c * k[1].rot.x);
    out->rot.y = ((a * k[0].rot.y) + (b * k[1].rot.y)) + (c * k[1].rot.y);
    out->rot.z = ((a * k[0].rot.z) + (b * k[1].rot.z)) + (c * k[1].rot.z);
    out->center.x = ((a * k[0].center.x) + (b * k[1].center.x)) + (c * k[1].center.x);
    out->center.y = ((a * k[0].center.y) + (b * k[1].center.y)) + (c * k[1].center.y);
    out->center.z = ((a * k[0].center.z) + (b * k[1].center.z)) + (c * k[1].center.z);
    return;
  }
  out->zoom = ((a * k[0].zoom) + (b * k[1].zoom)) + (c * k[2].zoom);
  out->rot.x = ((a * k[0].rot.x) + (b * k[1].rot.x)) + (c * k[2].rot.x);
  out->rot.y = ((a * k[0].rot.y) + (b * k[1].rot.y)) + (c * k[2].rot.y);
  out->rot.z = ((a * k[0].rot.z) + (b * k[1].rot.z)) + (c * k[2].rot.z);
  out->center.x = ((a * k[0].center.x) + (b * k[1].center.x)) + (c * k[2].center.x);
  out->center.y = ((a * k[0].center.y) + (b * k[1].center.y)) + (c * k[2].center.y);
  out->center.z = ((a * k[0].center.z) + (b * k[1].center.z)) + (c * k[2].center.z);
}
