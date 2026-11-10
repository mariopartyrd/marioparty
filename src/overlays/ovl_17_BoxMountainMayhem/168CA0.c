#include "BoxMountainMayhem.h"

/* Chance (of 128) that a stack of n boxes grows one more (func_800F96A4). */
u8 D_800FBFE0_BoxMountainMayhem[16] = { 0x00, 0x20, 0x60, 0x80, 0x80 };
/* Player start (x, z). */
f32 D_800FBFF0_BoxMountainMayhem[4][2] = {
    { -168.0f, -504.0f },
    { -28.0f, -205.0f },
    { 205.0f, 28.0f },
    { 504.0f, 168.0f },
};
/* CPU hesitation per difficulty. */
u8 D_800FC010_BoxMountainMayhem[16] = { 0x80, 0x55, 0x2A, 0x00, 0x00, 0x2A, 0x55, 0x80 };
/* Camera pitch table: squared distance thresholds (func_800FB4E8). */
f32 D_800FC020_BoxMountainMayhem = 2163200.0f;
f32 D_800FC024_BoxMountainMayhem[16] = {
    1695955.0f, 1328621.0f, 1203729.0f, 1086969.0f, 968416.0f, 917979.0f, 899666.0f, 881352.0f,
    870903.0f,  860455.0f,  823769.0f,  787083.0f,  741524.0f, 648124.0f, 616781.0f, 579526.0f,
};
/* Neighbouring cells (dx, dz) and their distances (func_800FB598). */
u8 D_800FC064_BoxMountainMayhem[6][2] = { { 0, 1 }, { 1, 0 }, { 1, 1 }, { 1, 2 }, { 2, 1 }, { 2, 2 } };
f32 D_800FC070_BoxMountainMayhem[6] = { 100.0f, 100.0f, 141.4f, 250.0f, 250.0f, 353.6f };
u32 D_800FC088_BoxMountainMayhem = 0;

void func_800F9060_BoxMountainMayhem(void) {
}

void func_800F9068_BoxMountainMayhem(void) {
    D_800FC240_BoxMountainMayhem = omAddObj(4, 4, 0, -1, func_800F90A8_BoxMountainMayhem);
    func_800F9840_BoxMountainMayhem();
}

void func_800F90A8_BoxMountainMayhem(omObjData* obj) {
    BMMStageWork* work;

    obj->model[0] = func_800174C0(0xB, 0x299);
    work = func_80023684(sizeof(BMMStageWork), 0x7918);
    obj->unk_50 = work;
    func_8009B770(work, 0, sizeof(BMMStageWork));
    func_800090B8(D_800ED440);
    work->unk_05 = D_800ED440;
    D_800F2AF8[D_800ED440++] = obj;
    work->unk_04 = 1;
    func_80009028(obj, 0, -350.0f, -750.0f, 750.0f, 350.0f);
    obj->func_ptr = NULL;
}

void func_800F918C_BoxMountainMayhem(omObjData* obj) {
    BMMStackExt* ext;
    f32 h;
    f32 y;
    s32 i;
    u8 n;

    ext = BMM_STAGE(obj)->unk_28;
    n = obj->work[0];
    if (n != 0) {
        h = 0.0f;
        for (i = 0; i < n; i++) {
            if (!(ext->unk_00[i] <= 0.0f)) {
                ext->unk_00[i] -= 37.5f;
                if (ext->unk_00[i] < 0.0f) {
                    ext->unk_00[i] = 0.0f;
                }
                y = h + ext->unk_00[i];
                func_80025798(obj->model[i + 1], obj->trans.x, y, obj->trans.z);
                if (i == n - 1) {
                    func_80009058(obj, y + 150.0f, 600.0f, -75.0f, -75.0f, 75.0f, 75.0f);
                }
            }
            h += 150.0f;
        }
    }
    for (i = 0; i < 4; i++) {
        if (ext->unk_10[i] >= 0) {
            if (ext->unk_18[i] <= 0) {
                func_80064D38(ext->unk_10[i]);
                ext->unk_10[i] = -1;
            }
            ext->unk_18[i]--;
        }
    }
}

// register allocation (masked 23)
#ifdef NON_MATCHING
void func_800F935C_BoxMountainMayhem(omObjData* obj) {
    BMMStageWork* work;
    BMMStackExt* ext;
    Vec pos;
    u8* cell;
    u16 model;
    s32 x;
    s32 z;
    s32 n;
    s32 k;
    s32 i;

    work = func_80023684(sizeof(BMMStageWork), 0x7918);
    obj->unk_50 = work;
    func_8009B770(work, 0, sizeof(BMMStageWork));
    ext = func_80023684(sizeof(BMMStackExt), 0x7918);
    work->unk_28 = ext;
    func_8009B770(ext, 0, sizeof(BMMStackExt));
    for (i = 0; i < 4; i++) {
        ext->unk_10[i] = -1;
        ext->unk_00[i] = 0.0f;
    }
    z = D_800FC188_BoxMountainMayhem[D_800FC1B0_BoxMountainMayhem][1];
    x = D_800FC188_BoxMountainMayhem[D_800FC1B0_BoxMountainMayhem][0];
    pos.x = 675.0f - x * 150.0f;
    pos.z = z * 150.0f + -675.0f;
    obj->model[0] = -1;
    obj->trans.x = pos.x;
    obj->trans.y = pos.y = 0.0f;
    obj->trans.z = pos.z;
    cell = D_800FC138_BoxMountainMayhem[z][x];
    n = cell[0];
    obj->work[0] = n;
    for (i = 0, k = 0; i < n; i++, k++) {
        if (D_800FC1A8_BoxMountainMayhem < 0) {
            D_800FC1A8_BoxMountainMayhem = model = func_800174C0(0x290000, 0x299);
        } else {
            model = func_80023FC8(D_800FC1A8_BoxMountainMayhem);
        }
        obj->model[k + 1] = model;
        pos.y = i * 150.0f;
        func_80025798(model, pos.x, pos.y, pos.z);
        ext->unk_20[k] = cell[k + 1];
        ext->unk_24[k] = 1;
    }
    work->unk_04 = 1;
    work->unk_05 = D_800ED440;
    D_800F2AF8[D_800ED440++] = obj;
    func_80008FB8(obj, 0.5f);
    func_8000941C(obj, 1.0f, 1.0f, 1.0f);
    func_80008FC4(obj, 20.0f);
    func_80009058(obj, n * 150.0f, 600.0f, -75.0f, -75.0f, 75.0f, 75.0f);
    obj->func_ptr = func_800F918C_BoxMountainMayhem;
    D_800FC1B0_BoxMountainMayhem++;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_BoxMountainMayhem/168CA0", func_800F935C_BoxMountainMayhem);
#endif

void func_800F96A4_BoxMountainMayhem(u8 x, u8 z, u8 depth) {
    s32 r;
    u8 n;

    n = D_800FC138_BoxMountainMayhem[z][x][0];
    if (depth != 0) {
        depth--;
    } else if (n < 3) {
        n++;
        D_800FC138_BoxMountainMayhem[z][x][0] = n;
    }
    r = func_800FBD2C_BoxMountainMayhem();
    if ((r & 0x7F) < D_800FBFE0_BoxMountainMayhem[n]) {
        r = (r >> 7) & 0xFF;
        if (r < 0x60) {
            x++;
        } else {
            if (r >= 0xC0) {
                x++;
            }
            z++;
        }
        if (x >= 4) {
            x = 0;
        }
        if (z >= 4) {
            z = 0;
        }
        if ((x == 3) & (z == 3)) {
            x = 0;
            z = 0;
        }
        func_800F96A4_BoxMountainMayhem(x, z, depth);
        return;
    }
    n++;
    D_800FC138_BoxMountainMayhem[z][x][0] = n;
}

// register allocation (masked 2)
#ifdef NON_MATCHING
void func_800F9840_BoxMountainMayhem(void) {
    u16 kinds[30];
    void* data;
    u16 t;
    s32 r;
    s32 flag;
    s32 n;
    s32 i;
    s32 m;
    s32 x;
    s32 z;

    flag = _CheckFlag(0x2B);
    n = 2;
    if (flag != 0) {
        n = 4;
    }
    for (i = 0; i < n; i++) {
        kinds[i] = 3;
    }
    r = func_800FBD2C_BoxMountainMayhem();
    n = (r & 1) + ((r >> 20) & 1);
    if (flag != 0) {
        n += 3;
    } else {
        n += 5;
    }
    for (; n != 0; n--) {
        kinds[i++] = 2;
    }
    for (; i < 30; i++) {
        kinds[i] = 1;
    }
    for (i = 32; i != 0; i--) {
        x = (u8)(rand8() % 30);
        z = (u8)(rand8() % 30);
        t = kinds[x];
        kinds[x] = kinds[z];
        kinds[z] = t;
    }
    for (z = 0; z < 4; z++) {
        for (x = 0; x < 4; x++) {
            D_800FC138_BoxMountainMayhem[z][x][0] = 0;
        }
    }
    for (i = 0; i < 30; i++) {
        func_800F96A4_BoxMountainMayhem(0, 0, 0x80);
    }
    i = 0;
    for (z = 0; z < 4; z++) {
        for (x = 0; x < 4; x++) {
            for (m = 0; m < D_800FC138_BoxMountainMayhem[z][x][0]; m++) {
                (D_800FC138_BoxMountainMayhem[z][x] + 1)[m] = kinds[i++];
            }
        }
    }
    data = DataRead(0x35000F);
    D_800FC1F0_BoxMountainMayhem = func_800678A4(data);
    HuMemDirectFree(data);
    D_800FC1AC_BoxMountainMayhem = 0;
    D_800FC1B0_BoxMountainMayhem = 0;
    D_800FC1A8_BoxMountainMayhem = -1;
    D_800FC130_BoxMountainMayhem = 0;
    for (z = 0; z < 4; z++) {
        for (x = 0; x < 4; x++) {
            if (D_800FC138_BoxMountainMayhem[z][x][0] != 0) {
                D_800FC1F8_BoxMountainMayhem[z][x] = omAddObj(4, 4, 0, -1, func_800F935C_BoxMountainMayhem);
                D_800FC188_BoxMountainMayhem[D_800FC1AC_BoxMountainMayhem][0] = x;
                D_800FC188_BoxMountainMayhem[D_800FC1AC_BoxMountainMayhem][1] = z;
                D_800FC1AC_BoxMountainMayhem++;
            } else {
                D_800FC1F8_BoxMountainMayhem[z][x] = NULL;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_BoxMountainMayhem/168CA0", func_800F9840_BoxMountainMayhem);
#endif

void func_800F9C20_BoxMountainMayhem(omObjData* stack, s32 x, s32 level, s32 z, Vec* unused, omObjData* player) {
    BMMStackExt* ext;
    Vec pos;
    f32 y;
    s32 n;
    s32 i;
    s16 grp;
    u8 kind;

    ext = BMM_STAGE(stack)->unk_28;
    n = stack->work[0];
    if ((n != 0) & (level < n)) {
        ext->unk_24[level]--;
        if (ext->unk_24[level] != 0) {
            return;
        }
        kind = ext->unk_20[level];
        for (i = level; i < 3; i++) {
            ext->unk_20[i] = ext->unk_20[i + 1];
            ext->unk_24[i] = ext->unk_24[i + 1];
        }
        ext->unk_20[i] = 0;
        pos.x = 675.0f - x * 150.0f;
        pos.y = level * 150.0f + 37.5f;
        pos.z = z * 150.0f + -675.0f;
        switch (kind) {
        case 3:
            func_800F7C30_BoxMountainMayhem(&pos, player, 3);
            break;
        case 2:
            func_800F7C30_BoxMountainMayhem(&pos, player, 0);
            break;
        case 1:
            func_800FAF84_BoxMountainMayhem(player);
            break;
        }
        n--;
        stack->work[0] = n;
        func_800258EC(stack->model[n + 1], 4, 4);
        ext->unk_00[n] = 0.0f;
        if (level < n) {
            y = 150.0f;
            for (i = level; i < n; i++) {
                ext->unk_00[i] += 150.0f;
                func_80025798(stack->model[i + 1], stack->trans.x, y, stack->trans.z);
                y += 150.0f;
            }
        } else if (n != 0) {
            func_80009058(stack, n * 150.0f, 600.0f, -75.0f, -75.0f, 75.0f, 75.0f);
        } else {
            func_80009058(stack, -150.0f, 600.0f, -75.0f, -75.0f, 75.0f, 75.0f);
        }
        for (i = 0; i < 4; i++) {
            if (ext->unk_10[i] < 0) {
                break;
            }
        }
        if (i < 4) {
            grp = func_80064EF4(1, 0);
            func_80067208(grp, 0, D_800FC1F0_BoxMountainMayhem, 0);
            func_80067284(grp, 0, 1.0f);
            func_800672B0(grp, 0, 2);
            func_800674BC(grp, 0, 0x100C);
            func_80067558(grp, 0, 0xFF, 0xFF, 0xFF, 0xFF);
            func_80066DF4(grp, 0, 0, stack->trans.x, level * 150.0f, stack->trans.z);
            func_80067354(grp, 0, 2.0f, 2.0f);
            ext->unk_10[i] = grp;
            ext->unk_18[i] = 14;
        }
    } else if (n == 0) {
        func_80009058(stack, -150.0f, 600.0f, -75.0f, -75.0f, 75.0f, 75.0f);
    }
}

// retail keeps the 0 return value in s2, ours rematerialises 0 (masked 13); a second `ret = 0`
// after the hit gives masked 8 plus one extra move; tried moving the initial set
#ifdef NON_MATCHING
s32 func_800FA058_BoxMountainMayhem(omObjData* obj) {
    BMMPlayerWork* work;
    omObjData* stack;
    Vec pos;
    f32 frame;
    f32 d;
    f32 a;
    s32 x;
    s32 z;
    s32 level;
    s32 ret;

    ret = 0;
    work = BMM_PLAYER(obj);
    if (!(work->unk_5C & 0x340)) {
        goto end;
    }
    pos.x = obj->trans.x;
    pos.y = obj->trans.y;
    pos.z = obj->trans.z;
    if (work->unk_5C & 0x140) {
        frame = func_80025E70(obj->model[0]);
        if (frame == -1.0f) {
            frame = func_80025D18(obj->model[0]);
        }
        if ((frame < 16.0f) | (frame > 20.0f)) {
            goto end;
        }
        d = work->unk_64 + work->unk_48 + 40.0f;
        a = work->unk_3C;
        pos.x += func_800AEAC0(a) * d;
        pos.z += func_800AEFD0(a) * d;
        pos.y += 50.0f;
    } else {
        pos.y -= 15.0f;
    }
    x = (750.0f - pos.x) / 150.0f;
    z = (pos.z + 750.0f) / 150.0f;
    if ((x < 4) & (z < 4)) {
        level = pos.y / 150.0f;
        stack = D_800FC1F8_BoxMountainMayhem[z][x];
        if (stack != NULL && level < stack->work[0] && obj->work[0] == 0) {
            func_800F9C20_BoxMountainMayhem(stack, x, level, z, &pos, obj);
            obj->work[0] = 18;
        }
    }
end:
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_BoxMountainMayhem/168CA0", func_800FA058_BoxMountainMayhem);
#endif

s32 func_800FA2A0_BoxMountainMayhem(void) {
    omObjData* obj;
    s32 count;
    s32 i;
    s32 j;

    count = 0;
    for (j = 0; j < 4; j++) {
        for (i = 0; i < 4; i++) {
            obj = D_800FC1F8_BoxMountainMayhem[j][i];
            if (obj != NULL) {
                count += obj->work[0];
            }
        }
    }
    return count;
}

s32 func_800FA2FC_BoxMountainMayhem(Vec* from, Vec* out, f32* dist) {
    omObjData* obj;
    f32 x;
    f32 z;
    f32 dx;
    f32 dz;
    f32 d;
    s32 count;
    s32 i;
    s32 j;
    u8 n;

    count = 0;
    *dist = 6.4e7f;
    z = -675.0f;
    for (j = 0; j < 4; j++) {
        x = 675.0f;
        for (i = 0; i < 4; i++) {
            obj = D_800FC1F8_BoxMountainMayhem[j][i];
            if (obj != NULL && (n = obj->work[0]) != 0) {
                dx = from->x - x;
                dz = from->z - z;
                d = dx * dx + dz * dz;
                count += n;
                if (d < *dist) {
                    *dist = d;
                    out->x = x;
                    out->y = obj->work[0] * 150.0f;
                    out->z = z;
                }
            }
            x -= 150.0f;
        }
        z += 150.0f;
    }
    return count;
}

void func_800FA3F0_BoxMountainMayhem(void) {
    s32 i;

    D_800FC1C0_BoxMountainMayhem = 0;
    for (i = 0; i < 6; i++) {
        D_800FC1C2_BoxMountainMayhem[i] = -1;
    }
    for (i = 0; i < 4; i++) {
        D_800FC278_BoxMountainMayhem[i] = omAddObj(8, 11, 42, -1, func_800FA498_BoxMountainMayhem);
    }
}

// register allocation of the character/D_800C59AC loads (masked 6)
#ifdef NON_MATCHING
void func_800FA498_BoxMountainMayhem(omObjData* obj) {
    BMMPlayerWork* work;
    BMMPlayerExt* ext;
    void* p;
    s32 dir;
    s32 r;
    s32 i;
    s32 player;
    f32* start;
    s32 v;
    u8 chr;
    u8 sprite;

    player = D_800FC1C0_BoxMountainMayhem;
    chr = GwPlayer[player].character;
    dir = D_800C59AC[chr].unk_00;
    func_8000979C(obj, dir, D_800C59AC[chr].unk_04, player, 0x699, 0x689);
    work = obj->unk_50;
    if (D_800FC1C2_BoxMountainMayhem[0] < 0) {
        D_800FC1C2_BoxMountainMayhem[0] = LoadFormFile(0x19, 0x68D);
        D_800FC1C2_BoxMountainMayhem[1] = LoadFormFile(0x1A, 0x68D);
        D_800FC1C2_BoxMountainMayhem[2] = LoadFormFile(0x1B, 0x68D);
        D_800FC1C2_BoxMountainMayhem[3] = LoadFormFile(0x1C, 0x68D);
        D_800FC1C2_BoxMountainMayhem[4] = LoadFormFile(0x1E, 0x68D);
        D_800FC1C2_BoxMountainMayhem[5] = LoadFormFile(0x1D, 0x68D);
        obj->model[3] = D_800FC1C2_BoxMountainMayhem[0];
        obj->model[4] = D_800FC1C2_BoxMountainMayhem[1];
        obj->model[6] = D_800FC1C2_BoxMountainMayhem[2];
        obj->model[5] = D_800FC1C2_BoxMountainMayhem[3];
        obj->model[7] = D_800FC1C2_BoxMountainMayhem[4];
        obj->model[8] = D_800FC1C2_BoxMountainMayhem[5];
    } else {
        obj->model[3] = func_80023FC8(D_800FC1C2_BoxMountainMayhem[0]);
        obj->model[4] = func_80023FC8(D_800FC1C2_BoxMountainMayhem[1]);
        obj->model[6] = func_80023FC8(D_800FC1C2_BoxMountainMayhem[2]);
        obj->model[5] = func_80023FC8(D_800FC1C2_BoxMountainMayhem[3]);
        obj->model[7] = func_80023FC8(D_800FC1C2_BoxMountainMayhem[4]);
        obj->model[8] = func_80023FC8(D_800FC1C2_BoxMountainMayhem[5]);
    }
    func_800FBE9C_BoxMountainMayhem(obj, 0x21, 0x289, 8, 9, &D_800FC238_BoxMountainMayhem[0]);
    func_80025830(obj->model[9], 2.0f, 2.0f, 2.0f);
    func_80025798(obj->model[9], obj->trans.x, 100.0f, obj->trans.z);
    func_800258EC(obj->model[9], 4, 4);
    func_800FBE9C_BoxMountainMayhem(obj, 0x2A, 0x68D, 8, 10, &D_800FC238_BoxMountainMayhem[1]);
    sprite = work->unk_21[10];
    func_8001E2F8(sprite, 0xC0);
    func_8001E360(sprite, 0xFF, 0xFF, 0xBE);
    func_800258EC(obj->model[10], 4, 4);
    p = func_80023684(sizeof(BMMPlayerExt), 0x7918);
    work->unk_E4 = p;
    func_8009B770(p, 0, sizeof(BMMPlayerExt));
    ext = work->unk_E4;
    if (work->unk_56 < 0) {
        work->unk_56 = work->unk_58;
    }
    work->unk_3C = -45.0f;
    D_800B895C = 10.0f;
    ext->unk_10 = 0;
    ext->unk_12 = 0;
    start = D_800FBFF0_BoxMountainMayhem[player];
    omSetTra(obj, start[0], 0.0f, start[1]);
    func_800187D0(obj, 0, dir, 1, 0);
    func_800187D0(obj, 1, dir | 1, 1, 0);
    func_800187D0(obj, 2, dir | 3, 1, 0);
    func_800187D0(obj, 5, dir | 4, 0, 0);
    func_800187D0(obj, 6, dir | 5, 1, 0x13);
    func_800187D0(obj, 7, dir | 6, 1, 0x22);
    func_800187D0(obj, 8, dir | 9, 1, 0x1B);
    func_800187D0(obj, 9, dir | 0xA, 1, 0x27);
    func_800187D0(obj, 0x11, dir | 0x18, 0, 0);
    func_800187D0(obj, 0x12, dir | 0x1C, 2, 0);
    func_800187D0(obj, 0x13, dir | 0x1D, 2, 0);
    func_800187D0(obj, 0xA, dir | 0x1E, 1, 0x27);
    func_800187D0(obj, 0x16, dir | 0x24, 1, 0);
    func_800187D0(obj, 0x15, dir | 0x62, 0, 0);
    func_800187D0(obj, 0x14, dir | 0x5F, 0, 0);
    func_800187D0(obj, 3, dir | 0x60, 1, 0);
    func_800187D0(obj, 4, dir | 0x61, 1, 0);
    func_800187D0(obj, 0x1E, dir | 0x63, 0, 0);
    func_800187D0(obj, 0x1F, dir | 0x64, 0, 0);
    func_800187D0(obj, 0x20, dir | 0x67, 0, 0);
    func_800187D0(obj, 0x21, dir | 0x68, 2, 0);
    func_800187D0(obj, 0x22, dir | 0x69, 2, 0);
    r = func_800FBD2C_BoxMountainMayhem();
    v = 0x38;
    if (r & 1) {
        v = 0xF;
    }
    func_800187D0(obj, 0xD, dir | v, 1, 0x77);
    v = (r & 8) ? 0x10 : 0x3C;
    func_800187D0(obj, 0xE, dir | v, 1, 0x78);
    for (i = 0; i < 32; i++) {
        func_800090C4(obj, i, 2);
    }
    D_800F3FB0[D_800F2BC0++] = obj;
    func_800184BC(obj, 1);
    if (GwPlayer[player].flags & 1) {
        ext->unk_04 = work->unk_56;
        ext->unk_06 = 0;
        ext->unk_08 = 0;
        ext->unk_0C = GwPlayer[work->unk_58].cpu_difficulty;
        ext->unk_0E = 0;
    }
    obj->work[0] = 0;
    obj->work[1] = 0;
    obj->work[2] = 0;
    obj->work[3] = 0;
    work->unk_DC = NULL;
    obj->func_ptr = func_800FAD84_BoxMountainMayhem;
    D_800FC1C0_BoxMountainMayhem++;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_BoxMountainMayhem/168CA0", func_800FA498_BoxMountainMayhem);
#endif

s16 func_800FAB1C_BoxMountainMayhem(s16 model, s32 mask) {
    unk_ovl_2D_struct* m = &D_800F2B7C[model];

    if (m->unk_6C == NULL) {
        return 0;
    }
    return mask & (u16)m->unk_20;
}

void func_800FAB60_BoxMountainMayhem(omObjData* obj, BMMPlayerWork* work, BMMPlayerExt* ext) {
    s16 model;
    u8 sprite;

    if (ext->unk_10 == 0) {
        return;
    }
    switch (ext->unk_10) {
    case 1:
        GwPlayer[work->unk_58].coins_mg++;
        func_800258EC(obj->model[9], 4, 0);
        ext->unk_00 = 120.0f;
        ext->unk_12 = 6;
        ext->unk_10++;
        func_80060540(0x195, work->unk_58);
        PlaySound(0xFC);
        break;
    case 2:
        if (ext->unk_12 != 0) {
            ext->unk_00 += 8.0f;
            ext->unk_12--;
        } else {
            ext->unk_00 -= 16.0f;
            func_800258EC(obj->model[9], 4, 4);
            model = obj->model[10];
            func_800258EC(model, 4, 0);
            func_80025830(model, 5.0f, 5.0f, 5.0f);
            sprite = work->unk_21[10];
            func_8001E2A8(sprite, 0);
            func_8001E268(sprite, 4, 4);
            ext->unk_10++;
        }
        break;
    case 3:
        if (func_800FAB1C_BoxMountainMayhem(obj->model[10], 4) == 4) {
            ext->unk_10 = 0;
        }
        break;
    }
    func_80025798(obj->model[9], obj->trans.x, obj->trans.y + ext->unk_00, obj->trans.z);
    func_80025798(obj->model[10], obj->trans.x, obj->trans.y + ext->unk_00, obj->trans.z);
}

// register allocation: stick in $v1, retail $a0 (raw 4, masked 0); tried u8 stick, chained store, if/else
#ifdef NON_MATCHING
void func_800FAD84_BoxMountainMayhem(omObjData* obj) {
    BMMPlayerWork* work;
    BMMPlayerExt* ext;
    s32 stick;

    work = BMM_PLAYER(obj);
    ext = work->unk_E4;
    if ((GwPlayer[work->unk_58].flags & 1) && D_800ED430 == 1) {
        func_800FB1BC_BoxMountainMayhem(obj);
    } else {
        func_800FBD54_BoxMountainMayhem(work->unk_56);
    }
    if (obj->work[2] != 0) {
        ContBtnTrg[work->unk_56] &= 0x1030;
        ContBtn[work->unk_56] &= 0x1030;
        ContStkX[work->unk_56] = 0;
        ContStkY[work->unk_56] = 0;
        work->unk_B2 = 13;
    } else if (obj->work[3] != 0) {
        ContBtnTrg[work->unk_56] &= 0x1030;
        ContBtn[work->unk_56] &= 0x1030;
        stick = 0;
        if (work->unk_38 != 1000.0f) {
            stick = 0x80;
        }
        ContStkX[work->unk_56] = stick;
        ContStkY[work->unk_56] = stick;
    }
    if (D_800ED430 == 2) {
        work->unk_40 = 0.0f;
    }
    func_80005A28(obj);
    func_800FA058_BoxMountainMayhem(obj);
    if (obj->work[0] != 0) {
        if (work->unk_40 < 0.0f) {
            work->unk_40 = 0.0f;
        }
        obj->work[0]--;
    }
    func_800FAB60_BoxMountainMayhem(obj, work, ext);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_BoxMountainMayhem/168CA0", func_800FAD84_BoxMountainMayhem);
#endif

void func_800FAF84_BoxMountainMayhem(omObjData* player) {
    BMM_PLAYER(player)->unk_E4->unk_10 = 1;
}

f32 func_800FAF98_BoxMountainMayhem(Vec* from, Vec* to) {
    f32 dx = to->x - from->x;
    f32 dz = to->z - from->z;

    return func_800B0CD8(dz, dx);
}

f32 func_800FAFC8_BoxMountainMayhem(BMMPlayerWork* work, Vec* from, Vec* to, f32 dist, u16* buttons) {
    BMMPlayerExt* ext;
    f32 a;
    f32 t;
    s32 reach;
    s32 b;

    ext = work->unk_E4;
    b = 0;
    a = func_800FAF98_BoxMountainMayhem(from, to);
    reach = work->unk_64 + work->unk_48 + 75.0f + 40.0f;
    reach *= reach;
    if (dist <= reach) {
        reach = func_800FBD2C_BoxMountainMayhem() & 0xFF;
        b = (reach >= D_800FC010_BoxMountainMayhem[ext->unk_0C]) << 14;
    } else if (dist < 65025.0f) {
        reach = func_800FBD2C_BoxMountainMayhem() & 0x3FF;
        if (reach < D_800FC010_BoxMountainMayhem[ext->unk_0C]) {
            b = 0x4000;
        }
        t = a + 22.5f;
        if (t < 0.0f) {
            t += 360.0f;
        } else if (t > 360.0f) {
            t -= 360.0f;
        }
        t /= 45.0f;
        reach = t;
        if (reach & 1) {
            a += 45.0f;
            if (a > 360.0f) {
                a -= 360.0f;
            }
        }
    }
    if (b != 0) {
        *buttons |= b;
    }
    return a;
}

// ContBtn load goes to $v0 then andi into $a0; retail loads into $a0 (raw 5, masked 1);
// tried temp r for both roles, u16 r, reusing n
#ifdef NON_MATCHING
void func_800FB1BC_BoxMountainMayhem(omObjData* obj) {
    BMMPlayerWork* work;
    BMMPlayerExt* ext;
    Vec pos;
    Vec coin;
    Vec stack;
    f32 dCoin;
    f32 dStack;
    u16 buttons;
    f32 a;
    s32 n;
    s32 move;
    s32 target;
    s32 r;

    work = BMM_PLAYER(obj);
    ext = work->unk_E4;
    target = 0;
    buttons = 0;
    move = 0;
    pos.x = obj->trans.x;
    pos.y = obj->trans.y;
    pos.z = obj->trans.z;
    n = func_800F8400_BoxMountainMayhem(&pos, &coin, &dCoin);
    if (n != 0) {
        if (dCoin < 22500.0f) {
            target = 1;
        } else if (n >= 4) {
            target = 1;
        }
    }
    if (target == 0) {
        if (func_800FA2FC_BoxMountainMayhem(&pos, &stack, &dStack) != 0) {
            target = 3;
            if (n != 0 && dCoin < dStack) {
                target = 1;
            }
        } else if (n != 0) {
            target = 1;
        }
    }
    if (ext->unk_08 != target) {
        r = func_800FBD2C_BoxMountainMayhem() & 0x1FF;
        target &= -(r >= D_800FC010_BoxMountainMayhem[ext->unk_0C]);
    }
    ext->unk_08 = target;
    switch (target) {
    case 1:
        a = func_800FAF98_BoxMountainMayhem(&pos, &coin);
        move = 1;
        break;
    case 3:
        a = func_800FAFC8_BoxMountainMayhem(work, &pos, &stack, dStack, &buttons);
        move = 1;
        break;
    case 0:
        break;
    }
    r = ContBtn[work->unk_56] & 0x1FFF;
    buttons |= r;
    buttons ^= ext->unk_06 & buttons & 0x4000;
    ContBtnTrg[work->unk_56] = ContBtn[work->unk_56] = buttons;
    ContBtnTrg[work->unk_56] = buttons & (buttons ^ ext->unk_06);
    ext->unk_06 = buttons;
    if (move) {
        ContStkX[work->unk_56] = func_800AEFD0(a) * 80.0f;
        ContStkY[work->unk_56] = -func_800AEAC0(a) * 80.0f;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_BoxMountainMayhem/168CA0", func_800FB1BC_BoxMountainMayhem);
#endif

void func_800FB440_BoxMountainMayhem(f32 zoom, f32 rotX, f32 rotY, f32 rotZ, f32 x, f32 y, f32 z) {
    func_800178A0(1);
    CZoom = zoom;
    CRot.x = rotX;
    CRot.y = rotY;
    CRot.z = rotZ;
    Center.x = x;
    Center.y = y;
    Center.z = z;
    D_800FC1D0_BoxMountainMayhem = zoom;
}

/* Camera pitch for the farthest player's squared distance: +10 beyond the first threshold, else
   -15 down to -85 (+k). When the distance is under every threshold retail adds an uninitialised k
   (whatever $a0 held); the host uses 0. */
f32 func_800FB4E8_BoxMountainMayhem(f32 dist) {
    f32 prev;
    f32 cur;
    f32 step;
    s32 res;
    s32 i;
    s32 k;

    prev = D_800FC020_BoxMountainMayhem;
    res = 10;
    if (!(prev <= dist)) {
        for (i = 1; i < 16; i++) {
            cur = D_800FC024_BoxMountainMayhem[i];
            if (cur < dist) {
                step = (prev - cur) / 5.0f;
                for (k = 4; k != 0; k--) {
                    cur += step;
                    if (dist < cur) {
                        break;
                    }
                }
                break;
            }
            prev = cur;
            res += 5;
        }
        res = -(res + k);
    }
    return res;
}

// decomp-permuter
f32 func_800FB598_BoxMountainMayhem(void)
{
  omObjData *p;
  omObjData *stack;
  f32 best;
  f32 h;
  f32 a;
  s32 x;
  s32 z;
  s32 cx;
  s32 cz;
  s32 i;
  s32 k;
  u8 n;
  best = 0.0f;
  for (i = 0; i < 4; i++)
  {
    p = D_800FC278_BoxMountainMayhem[i];
    if ((p == 0) || (p->work[1] != 0))
    {
      continue;
    }
    x = (750.0f - p->trans.x) / 150.0f;
    z = (p->trans.z + 750.0f) / 150.0f;
    if ((x >= 4) | (z >= 4))
    {
      continue;
    }
    for (k = 0; k < 6; k++)
    {
      cx = x + D_800FC064_BoxMountainMayhem[k][0];
      if (cx < 4)
      {
        cz = z + D_800FC064_BoxMountainMayhem[k][1];
        if (cz < 4)
        {
          stack = D_800FC1F8_BoxMountainMayhem[cz][cx];
          if ((stack != 0) && ((n = stack->work[0]) >= 2))
          {
            h = n * 150.0f;
            h = h - p->trans.y;
            if (h > 0.0f)
            {
              a = func_800B0CD8(h, D_800FC070_BoxMountainMayhem[k]);
              if (best < a)
              {
                best = a;
              }
            }
          }
        }
      }
    }

  }

  return 0.0f - best;
}

// decomp-permuter
void func_800FB788_BoxMountainMayhem(void)
{
  f32 a;
  f32 d;
  f32 zoom;
  a = 0.0f - CRot.x;
  d = func_800AEAC0(a) * 1105.5f;
  Center.y = d + 308.0f;
  d = func_800AEFD0(a) * 781.7066f;
  Center.x = 525.0f - d;
  Center.z = d + (-525.0f);
  if (a > 85.0f)
  {
    zoom = ((90.0f - a) * 51.0f) + 700.0f;
  }
  else
    if (a > 80.0f)
  {
    zoom = ((85.0f - a) * 38.4f) + 955.0f;
  }
  else
    if (a > 72.0f)
  {
    zoom = ((80.0f - a) * 50.375f) + 1147.0f;
  }
  else
    if (a > 62.0f)
  {
    zoom = ((72.0f - a) * 30.9f) + 1550.0f;
  }
  else
  {
    return;
  }
  if (zoom < CZoom)
  {
    CZoom = zoom;
  }
}

// float register allocation: trans.x loaded into $f2, retail $f0 (masked 1; other raw lines are
// NON_MATCHING data offsets); tried decl order, inlined squares
#ifdef NON_MATCHING
void func_800FB9B4_BoxMountainMayhem(void) {
    omObjData* p;
    f32 far;
    f32 dx;
    f32 dz;
    f32 d;
    f32 b;
    f32 t;
    s32 i;

    far = 0.0f;
    for (i = 0; i < 4; i++) {
        p = D_800FC278_BoxMountainMayhem[i];
        if (p != NULL && p->work[1] == 0) {
            dx = 750.0f - p->trans.x;
            dz = -750.0f - p->trans.z;
            d = dx * dx + dz * dz;
            if (far < d) {
                far = d;
            }
        }
    }
    d = func_800B1750(far) * 3.216f - 1197.4f - D_800FC1D0_BoxMountainMayhem;
    if (d < -24.0f) {
        D_800FC1D0_BoxMountainMayhem = D_800FC1D0_BoxMountainMayhem - 24.0f;
    } else if (!(d < 0.0f) && d > 24.0f) {
        D_800FC1D0_BoxMountainMayhem = D_800FC1D0_BoxMountainMayhem + 24.0f;
    } else {
        D_800FC1D0_BoxMountainMayhem = d + D_800FC1D0_BoxMountainMayhem;
    }
    if (D_800FC1D0_BoxMountainMayhem < 700.0f) {
        D_800FC1D0_BoxMountainMayhem = 700.0f;
    } else if (D_800FC1D0_BoxMountainMayhem > 1859.0f) {
        D_800FC1D0_BoxMountainMayhem = 1859.0f;
    }
    CZoom = D_800FC1D0_BoxMountainMayhem;
    d = func_800FB598_BoxMountainMayhem();
    b = func_800FB4E8_BoxMountainMayhem(far);
    if (d < b) {
        d = b;
    }
    t = d - CRot.x;
    if (t < -2.0f) {
        t = -2.0f;
    } else if (t > 2.0f) {
        t = 2.0f;
    }
    CRot.x += t;
    if (CRot.x >= -10.0f) {
        CRot.x = -10.0f;
    } else if (CRot.x < -90.0f) {
        CRot.x = -90.0f;
    }
    func_800FB788_BoxMountainMayhem();
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_17_BoxMountainMayhem/168CA0", func_800FB9B4_BoxMountainMayhem);
#endif

//direct copy of frandom from mario party 4
u32 func_800FBC58_BoxMountainMayhem(u32 param) {
    s32 rand2, rand3;

    if (param == 0) {
        param = rand8();
        param = param ^ osGetCount();
        param ^= 0xD826BC89;
    }

    rand2 = param / 0x1F31D;
    rand3 = param - (rand2 * 0x1F31D);
    param = rand2 * 0xB14;
    param =  param - rand3 * 0x41A7;
    return param;
}

u32 func_800FBD2C_BoxMountainMayhem(void) {
    return D_800FC088_BoxMountainMayhem = func_800FBC58_BoxMountainMayhem(D_800FC088_BoxMountainMayhem);
}

void func_800FBD54_BoxMountainMayhem(s8 port) {
    f32 x;
    f32 y;
    f32 mag;
    f32 m;

    if (port >= 0) {
        x = ContStkX[port];
        y = ContStkY[port];
        mag = x * x + y * y;
        if (mag != 0.0f) {
            m = func_800B1750(mag);
            mag = func_800B0CD8(x, y) - 45.0f; /* now the angle */
            if (mag < -180.0f) {
                mag += 360.0f;
            }
            ContStkX[port] = func_800AEFD0(mag) * m;
            ContStkY[port] = -func_800AEAC0(mag) * m;
        }
    }
}

void func_800FBE9C_BoxMountainMayhem(omObjData* obj, s32 file, u16 arg2, u8 arg3, s16 slot, s16* shared) {
    u8* work;
    void* data;
    u16 sprite;
    s16 model;

    work = obj->unk_50;
    if (*shared < 0) {
        data = DataRead(file);
        sprite = func_8001E00C(data, arg2, arg3);
        HuMemDirectFree(data);
        *shared = sprite;
    } else {
        sprite = func_8001E1D0(*shared, arg3);
    }
    model = D_800ECDE0[(s16)sprite].unk_00;
    obj->model[slot] = model;
    func_80025930(model, 0x70000000, 0x70000000);
    if (slot == 0) {
        work[0x55] = sprite;
    } else {
        (work + slot)[0x21] = sprite;
    }
}
