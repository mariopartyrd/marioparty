#include "common.h"
#include "14E940.h"

/* .data (0x800FA7C0..0x800FA860). Most of it is used by 150E30.c. */
f32 D_800FA7C0_CoinBlockBlitz[4][2] = {
    { 470.0f, 470.0f }, { -470.0f, 470.0f }, { 470.0f, -470.0f }, { -470.0f, -470.0f },
};
f32 D_800FA7E0_CoinBlockBlitz = 0.0f; /* unreferenced */
s32 D_800FA7E4_CoinBlockBlitz = 0;
s32 D_800FA7E8_CoinBlockBlitz = 90;
u32 D_800FA7EC_CoinBlockBlitz = 1829;
u32 D_800FA7F0_CoinBlockBlitz = 0;
s32 D_800FA7F4_CoinBlockBlitz = 0;
s32 D_800FA7F8_CoinBlockBlitz = 0;
s32 D_800FA7FC_CoinBlockBlitz = 0;
u16 D_800FA800_CoinBlockBlitz = 0;
s32 D_800FA804_CoinBlockBlitz = 0x80;
s32 D_800FA808_CoinBlockBlitz = 0x80;
s32 D_800FA80C_CoinBlockBlitz[] = { 1, 5, 3, -1 };
u16 D_800FA81C_CoinBlockBlitz = 0;
s16 D_800FA81E_CoinBlockBlitz = -1;
u16 D_800FA820_CoinBlockBlitz = 0;
Vec3f D_800FA824_CoinBlockBlitz[5] = {
    { 405.0f, 0.0f, 386.0f },
    { -450.0f, 0.0f, 363.0f },
    { -450.0f, 0.0f, -430.0f },
    { 405.0f, 0.0f, -430.0f },
    { 0.0f, 0.0f, 0.0f },
};

/* Retail's vector helper shape: set, then subtract a position, through a pointer. */
#define CBB_VEC_DIFF(vp, ax, az, obj)                \
    func_800A0D00((vp), (ax), 0.0f, (az));           \
    (vp)->x -= (obj)->trans.x;                       \
    (vp)->y -= 0.0f;                                 \
    (vp)->z -= (obj)->trans.z

#define CBB_ABS(x) (((x) < 0.0f) ? -(x) : (x))


void func_800F65E0_CoinBlockBlitz(void) {
    u8 temp_s0;

    func_80029090(0x32);
    func_8002ADF0(&D_800EDEC0, 0x40);
    func_8001DE70(0x20);
    omInitObjMan(0x32, 0);
    func_80060088();
    func_8000942C();
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    func_800178A0(1);
    temp_s0 = func_800178E8();
    func_80017660(temp_s0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(temp_s0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_8001D494(0, 20.0f, 2500.0f, 6000.0f);
    D_800EE984 = 0;
    D_800F2BC0 = 0;
    D_800ED440 = 0;
    func_800F6D08_CoinBlockBlitz();
    func_800090B8(D_800ED440);
    D_800F2AF8[D_800ED440++] = omAddObj(1, 1, 0, -1, &func_800F9208_CoinBlockBlitz);
    D_800F2AF8[D_800ED440++] = omAddObj(4, 2, 0, -1, &func_800FA49C_CoinBlockBlitz);
    D_800F2AF8[D_800ED440++] = omAddObj(4, 2, 0, -1, &func_800FA500_CoinBlockBlitz);
    D_800F2AF8[D_800ED440++] = omAddObj(4, 2, 0, -1, &func_800FA554_CoinBlockBlitz);
    D_800F2AF8[D_800ED440++] = omAddObj(4, 2, 0, -1, &func_800FA5A8_CoinBlockBlitz);
    D_800F2AF8[D_800ED440++] = omAddObj(4, 2, 0, -1, &func_800FA5FC_CoinBlockBlitz);
    D_800F2AF8[D_800ED440++] = omAddObj(4, 2, 0, -1, &func_800FA65C_CoinBlockBlitz);
    D_800F2AF8[D_800ED440++] = omAddObj(4, 2, 0, -1, &func_800FA6B0_CoinBlockBlitz);
    D_800F2AF8[D_800ED440++] = omAddObj(4, 2, 0, -1, &func_800FA704_CoinBlockBlitz);
    D_800F2AF8[D_800ED440++] = omAddObj(4, 2, 0, -1, &func_800FA758_CoinBlockBlitz);

    func_800F6E1C_CoinBlockBlitz();
    func_80009500();
    D_800F3FB0[D_800F2BC0++] = omAddObj(2, 0xA, 0x32, -1, &func_800F9FB8_CoinBlockBlitz);
    D_800F3FB0[D_800F2BC0++] = omAddObj(2, 0xA, 0x32, -1, &func_800FA068_CoinBlockBlitz);
    D_800F3FB0[D_800F2BC0++] = omAddObj(2, 0xA, 0x32, -1, &func_800FA118_CoinBlockBlitz);
    D_800F3FB0[D_800F2BC0++] = omAddObj(2, 0xA, 0x32, -1, &func_800FA1C8_CoinBlockBlitz);
    D_800EDE70[D_800EE984++] = omAddObj(3, 4, 0, -1, &func_800FA278_CoinBlockBlitz);
    D_800EDE70[D_800EE984++] = omAddObj(3, 4, 0, -1, &func_800FA2D0_CoinBlockBlitz);
    D_800EDE70[D_800EE984++] = omAddObj(3, 4, 0, -1, &func_800FA32C_CoinBlockBlitz);
    D_800EDE70[D_800EE984++] = omAddObj(3, 4, 0, -1, &func_800FA388_CoinBlockBlitz);
    D_800EDE70[D_800EE984++] = omAddObj(3, 4, 0, -1, &func_800FA3E4_CoinBlockBlitz);
    D_800EDE70[D_800EE984++] = omAddObj(3, 4, 0, -1, &func_800FA440_CoinBlockBlitz);

    omAddObj(1, 0, 0, -1, &func_800F6CB4_CoinBlockBlitz);
    SetFadeInTypeAndTime(0, 0x10);
}

void func_800F6CB4_CoinBlockBlitz(omObjData* obj) {
    if (D_800F5144 == 1 || D_800F5144 == 1) { //yep, this is required to match
        func_800601D4(0x28);
        func_80009730();
        func_8002890C(0, 0, 0);
        omOvlReturnEx(1);
    }
}

void func_800F6D08_CoinBlockBlitz(void) {
    unkCoinBlockBlitzStruct1* var_s0;
    unkCoinBlockBlitzStruct2* var_s1;
    s16 temp_a0;
    s32 i;

    var_s0 = D_800FAA80_CoinBlockBlitz;
    var_s1 = D_800FA8F0_CoinBlockBlitz;
    temp_a0 = rand8() % 3;
    
    for (i = 0; i < 4; i++, var_s0++, var_s1++) {
        var_s0->unk0 = 0;
        var_s0->unk2 = 0;
        var_s0->unk6 = 0;
        var_s0->unk8 = 0;
        var_s0->unkC = 0;
        var_s0->unkE = 0;
        var_s0->unk10 = 0;
        var_s0->unk12 = 0;
        var_s1->unk0 = 0;
        var_s1->unkA = temp_a0;
    }
    
    D_800FAA78_CoinBlockBlitz = 0;
    CZoom = 3510.0f;
    CRot.x = -40.5f;
    CRot.y = 25.25f;
    CRot.z = 0.0f;
    Center.x = -100.0f;
    Center.y = -100.0f;
    Center.z = -185.0f;
}


void func_800F6E1C_CoinBlockBlitz(void) {
    s32 i;
    s32 candidate;
    s32 j;
    s32 randomIndex;

    for (i = 0; i < 4; i++) {
        randomIndex = (rand8() & 0xFF) % (4 - i);

        for (candidate = 0; candidate < 4; candidate++) {
            // Check if candidate was already used
            j = i;
            while (j != 0 && D_800FA8E0_CoinBlockBlitz[j] != candidate) {
                j--;
            }

            // If found, skip to next candidate
            if (j != 0) {
                continue;
            }

            // Found an unused candidate - is it the one we randomly picked?
            if (randomIndex == 0) {
                break;
            }
            randomIndex--;
        }

        // Fallback if loop exhausted
        if (candidate >= 4) {
            candidate = i;
        }

        D_800FA8E0_CoinBlockBlitz[i + 1] = candidate;
    }
}

void func_800F6F1C_CoinBlockBlitz(void) {
}

void func_800F6F24_CoinBlockBlitz(omObjData* obj, f32 scale, f32 y, s32 idx) {
    func_80025798(obj->model[idx], obj->trans.x, y + obj->trans.y, obj->trans.z);
    func_80025830(obj->model[idx], scale, scale, scale);
}

void func_800F6FA8_CoinBlockBlitz(omObjData* obj) {
    u8 player = obj->work[0];
    unkCoinBlockBlitzStruct1* cpu = &D_800FAA80_CoinBlockBlitz[player];

    if (GwPlayer[player].flags & 1) {
        cpu->unk0 |= 1;
        cpu->unk4 = GwPlayer[player].cpu_difficulty;
    }
}

u16 func_800F700C_CoinBlockBlitz(s32 block) {
    return !(D_800FA950_CoinBlockBlitz[block].unk_0A - 3 < 2U);
}

u16 func_800F702C_CoinBlockBlitz(s32 block, s32 player, f32 dist) {
    Vec3f vec;
    Vec3f* vp;
    omObjData* blk;
    omObjData* other;
    s32 i;

    blk = D_800FA950_CoinBlockBlitz[block].block;
    vp = &vec;
    for (i = 0; i < D_800F2BC0; i++) {
        if (i == player) {
            continue;
        }
        other = D_800F3FB0[i];
        func_800A0D00(vp, other->trans.x, 0.0f, other->trans.z);
        vp->x -= blk->trans.x;
        vp->y -= 0.0f;
        vp->z -= blk->trans.z;
        if (func_800A1200(vp) < dist) {
            return 0;
        }
    }
    return 1;
}

s16 func_800F713C_CoinBlockBlitz(omObjData* obj, s32 skip, s32 difficulty) {
    s32 list[9];
    Vec3f vec;
    Vec3f* vp;
    omObjData* blk;
    BlockData* bd;
    f32 best;
    f32 dist;
    s32 count;
    s32 i;
    s32 found;

    vp = &vec;
    i = 0;
    found = -1;
    best = 10000.0f;
    for (; i < 9; i++) {
        if (i == skip) {
            continue;
        }
        bd = &D_800FA950_CoinBlockBlitz[i];
        blk = bd->block;
        if (bd->unk_0A != 0) {
            continue;
        }
        if (!func_800F702C_CoinBlockBlitz(i, obj->work[0], 80.0f)) {
            continue;
        }
        CBB_VEC_DIFF(vp, blk->trans.x, blk->trans.z, obj);
        switch (difficulty) {
        case 0:
        case 1:
            break;
        case 2:
        case 3:
            dist = func_800A1200(vp);
            if (dist < best) {
                best = dist;
                found = i;
            }
            break;
        }
    }
    if (found == -1) {
        count = 0;
        i = 0;
        best = 10000.0f;
        for (; i < 9; i++) {
            bd = &D_800FA950_CoinBlockBlitz[i];
            blk = bd->block;
            if (!func_800F700C_CoinBlockBlitz(i)) {
                continue;
            }
            CBB_VEC_DIFF(vp, blk->trans.x, blk->trans.z, obj);
            switch (difficulty) {
            case 0:
            case 1:
                list[count] = i;
                count++;
                break;
            case 2:
            case 3:
                dist = func_800A1200(vp);
                if (dist < best) {
                    best = dist;
                    found = i;
                }
                break;
            }
        }
        switch (difficulty) {
        case 0:
        case 1:
            found = list[(rand8() & 0xFF) % count];
            break;
        }
    }
    return found;
}

s32 func_800F73F4_CoinBlockBlitz(u16 player) {
    omObjData* obj = D_800F3FB0[player];
    CBBPlayerWork* work = obj->unk_50;
    s32 flags = func_80017A60(obj);
    s32 ret = 0;

    if (work->unk_38 == 1000.0f) {
        ret = (flags & 6) != 0;
    }
    return ret;
}

f32 func_800F745C_CoinBlockBlitz(omObjData* obj, omObjData* block) {
    Vec3f vec;
    Vec3f* vp;
    omObjData* rival;
    f32 a;
    f32 b;
    f32 ofs;
    f32 ret;
    s8 idx;

    CBBPlayerWork* work;

    work = obj->unk_50;
    vp = &vec;
    ret = 0.0f;
    if (work->unk_54 != -1) {
        idx = work->unk_54;
        rival = D_800F3FB0[idx];
        func_800A0D00(vp, block->trans.x, 0.0f, block->trans.z);
        vec.x -= obj->trans.x;
        vec.y -= 0.0f;
        vec.z -= obj->trans.z;
        a = func_80029518(func_800B0CD8(vec.x, vec.z));
        func_800A0D00(vp, rival->trans.x, 0.0f, rival->trans.z);
        vec.x -= obj->trans.x;
        vec.y -= 0.0f;
        vec.z -= obj->trans.z;
        b = func_80029518(func_800B0CD8(vec.x, vec.z));
        if (CBB_ABS(a - b) > 180.0f) {
            ofs = -90.0f;
        } else {
            ofs = 90.0f;
        }
        if (a - b < 0.0f) {
            ofs = -ofs;
        }
        ret += ofs;
    }
    return ret;
}

void func_800F7604_CoinBlockBlitz(omObjData* obj) {
    Vec3f vec;
    Vec3f* vp;
    omObjData* blk;
    unkCoinBlockBlitzStruct1* cpu;
    f32 dist;
    f32 angle;
    u16 player;

    player = obj->work[0];
    cpu = &D_800FAA80_CoinBlockBlitz[player];
    vp = &vec;
    if (!(cpu->unk0 & 1) || D_800ED430 == 3) {
        return;
    }
    cpu->unkE = 0;
    cpu->unkC = 0;
    ContBtn[GwPlayer[player].port] = 0;
    ContBtnTrg[GwPlayer[player].port] = 0;
    ContStkX[GwPlayer[player].port] = 0;
    ContStkY[GwPlayer[player].port] = 0;
    switch (cpu->unk2) {
    case 0:
        cpu->unk8 = func_800F713C_CoinBlockBlitz(obj, -1, cpu->unk4);
        if (cpu->unk8 == -1) {
            break;
        }
        cpu->unk2 = 1;
    case 1:
        if ((!func_800F702C_CoinBlockBlitz(cpu->unk8, player, 30.0f) || !func_800F700C_CoinBlockBlitz(cpu->unk8))
            && !(cpu->unk0 & 2)) {
            cpu->unk0 |= 2;
        reset:
            cpu->unk2 = 0;
            break;
        }
        blk = D_800FA950_CoinBlockBlitz[cpu->unk8].block;
        CBB_VEC_DIFF(vp, blk->trans.x, blk->trans.z, obj);
        dist = func_800A1200(vp);
        if (dist > 30.0f && (func_800F702C_CoinBlockBlitz(cpu->unk8, player, 90.0f) || !(dist < 90.0f))) {
            angle = func_800B0CD8(vp->x, vp->z);
            angle += func_800F745C_CoinBlockBlitz(obj, blk);
            cpu->unkC = func_800AEAC0(angle) * 60.0f;
            cpu->unkE = func_800AEFD0(angle) * 60.0f;
            break;
        }
        cpu->unk2 = 2;
    case 2:
        cpu->unk10 |= 0x8000;
        cpu->unk12 |= 0x8000;
        cpu->unkA = 10;
        switch (cpu->unk4) {
        case 0:
            cpu->unk6 = (u8)(rand8() % 15) + 5;
            break;
        case 1:
            cpu->unk6 = (u8)(rand8() % 10) + 1;
            break;
        case 2:
            cpu->unk6 = (u8)(rand8() % 5);
            break;
        default:
            cpu->unk6 = 0;
            break;
        }
        cpu->unk2 = 3;
        break;
    case 3:
        cpu->unk10 = 0;
        if (cpu->unkA == 0) {
            cpu->unk12 = 0;
            if ((u8)func_800F73F4_CoinBlockBlitz(player)) {
                if (cpu->unk6 != 0) {
                    cpu->unk6--;
                } else if (func_800F700C_CoinBlockBlitz(cpu->unk8)) {
                    cpu->unk2 = 1;
                } else {
                    goto reset;
                }
            }
        } else {
            cpu->unkA--;
        }
        break;
    }
    ContBtn[GwPlayer[player].port] = cpu->unk12;
    ContBtnTrg[GwPlayer[player].port] = cpu->unk10;
    ContStkX[GwPlayer[player].port] = cpu->unkC;
    ContStkY[GwPlayer[player].port] = -cpu->unkE;
}

void func_800F7B00_CoinBlockBlitz(s32 player) {
    Vec3f vec;
    Vec3f* vp;
    f32 angle;
    f32 mag;

    vp = &vec;
    if (!(D_800FAA80_CoinBlockBlitz[player].unk0 & 1)) {
        vec.x = ContStkX[GwPlayer[player].port];
        vec.y = 0.0f;
        vec.z = ContStkY[GwPlayer[player].port];
        angle = func_800B0CD8(vec.x, vec.z);
        mag = func_800A1200(vp);
        angle -= CRot.y;
        ContStkX[GwPlayer[player].port] = func_800AEAC0(angle) * mag;
        ContStkY[GwPlayer[player].port] = func_800AEFD0(angle) * mag;
    }
}

u16 func_800F7C30_CoinBlockBlitz(omObjData* from, omObjData* player, s32 unused) {
    Vec3f d;
    omObjData* coin;
    CBBCoinWork* work;
    s32 i;

    for (i = 0; i < D_800EE984; i++) {
        coin = D_800EDE70[i];
        work = coin->unk_50;
        if (work->unk_54 == 0) {
            break;
        }
    }
    if (i >= D_800EE984) {
        return 0;
    }
    {
        coin->trans.x = from->trans.x;
        coin->trans.y = from->trans.y;
        coin->trans.z = from->trans.z;
        func_80025798(coin->model[0], player->trans.x, player->trans.y, player->trans.z);
        func_80025798(coin->model[1], player->trans.x, 0.0f, player->trans.z);
        d.x = player->trans.x;
        d.z = player->trans.z;
        d.x -= from->trans.x;
        d.z -= from->trans.z;
        work->unk_3C = 0.0f;
        work->unk_40 = D_800B8990;
        work->unk_38 = -1.2f;
        work->unk_54 = 1;
        func_800258EC(coin->model[0], 4, 0);
        func_800258EC(coin->model[1], 4, 0);
        return 1;
    }
}

void func_800F7D98_CoinBlockBlitz(omObjData* coin, Vec3f* pos) {
    CBBCoinWork* work = coin->unk_50;

    if (work->unk_54 != 0) {
        func_800258EC(coin->model[3], 4, 0);
        func_8001E2A8(work->unk_21[3], 0);
        func_8001E268(work->unk_21[3], 4, 4);
        func_80025798(coin->model[3], pos->x, pos->y, pos->z);
        func_80025830(coin->model[3], 10.0f, 10.0f, 10.0f);
        work->unk_54 = 0;
        func_800090D8(coin, 0, 0);
        func_800090D8(coin, 1, 0);
    }
}

void func_800F7E5C_CoinBlockBlitz(void) {
    Vec3f pos;
    Vec3f* vp;
    omObjData* coin;
    s32 i;

    vp = &pos;
    for (i = 0; i < D_800EE984; i++) {
        coin = D_800EDE70[i];
        vp->x = coin->trans.x;
        vp->y = coin->trans.y;
        vp->z = coin->trans.z;
        func_800F7D98_CoinBlockBlitz(coin, vp);
    }
}

void func_800F7EE8_CoinBlockBlitz(omObjData* obj) {
    Vec3f vec;
    Vec3f* vp;
    omObjData* other;
    CBBPlayerWork* work;
    f32 angle;
    s32 found;
    s32 q;
    s32 j;
    s32 player;

    vp = &vec;
    player = obj->work[0];
    work = obj->unk_50;
    ContStkX[GwPlayer[player].port] = ContStkY[GwPlayer[player].port] = 0;
    ContBtn[GwPlayer[player].port] = 0;
    ContBtnTrg[GwPlayer[player].port] = 0;
    func_800A0D00(vp, -obj->trans.x, 0.0f, -obj->trans.z);
    if (!(u8)func_800F73F4_CoinBlockBlitz(player)) {
        for (q = 0; q < 4; q++) {
            for (j = 0; j < 4; j++) {
                if (player != j) {
                    other = D_800F3FB0[j];
                    found = 0;
                    switch (q) {
                    case 0:
                        if (other->trans.x >= 0.0f && other->trans.z >= 0.0f) {
                            found = 1;
                        }
                        break;
                    case 1:
                        if (other->trans.x < 0.0f && other->trans.z >= 0.0f) {
                            found = 1;
                        }
                        break;
                    case 2:
                        if (other->trans.x >= 0.0f && other->trans.z < 0.0f) {
                            found = 1;
                        }
                        break;
                    case 3:
                        if (other->trans.x < 0.0f && other->trans.z < 0.0f) {
                            found = 1;
                        }
                        break;
                    }
                    if (found) {
                        break;
                    }
                }
            }
            if (j >= 4) {
                break;
            }
        }
        if (q >= 4) {
            q = 0;
        }
        CBB_VEC_DIFF(vp, D_800FA7C0_CoinBlockBlitz[q][0], D_800FA7C0_CoinBlockBlitz[q][1], obj);
        angle = func_80029518(func_800B0CD8(vp->x, vp->z));
        ContStkX[GwPlayer[player].port] = func_800AEAC0(angle) * 60.0f;
        ContStkY[GwPlayer[player].port] = -(func_800AEFD0(angle) * 60.0f);
    } else {
        work->unk_40 = 0.0f;
    }
}

// register allocation: retail reloads a0 = obj before func_800F7604 (masked 7)
#ifdef NON_MATCHING
void func_800F81F0_CoinBlockBlitz(omObjData* obj) {
    unkCoinBlockBlitzStruct1* cpu;
    s32 player;

    player = obj->work[0];
    cpu = &D_800FAA80_CoinBlockBlitz[player];
    cpu->unk1A = ContBtn[GwPlayer[player].port];
    cpu->unk18 = ContBtnTrg[GwPlayer[player].port];
    cpu->unk14 = ContStkX[GwPlayer[player].port];
    cpu->unk16 = ContStkY[GwPlayer[player].port];
    if (D_800ED430 >= 0) {
        if (D_800ED430 < 2) {
            if (D_800FA94C_CoinBlockBlitz == 0) {
                func_800F7604_CoinBlockBlitz(obj);
                func_800F7B00_CoinBlockBlitz(obj->work[0]);
            } else {
                func_800F7EE8_CoinBlockBlitz(obj);
            }
        }
    }
    func_80005A28(obj);
    ContBtn[GwPlayer[player].port] = cpu->unk1A;
    ContBtnTrg[GwPlayer[player].port] = cpu->unk18;
    ContStkX[GwPlayer[player].port] = cpu->unk14;
    ContStkY[GwPlayer[player].port] = cpu->unk16;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_CoinBlockBlitz/14E940", func_800F81F0_CoinBlockBlitz);
#endif

void func_800F83A8_CoinBlockBlitz(omObjData* obj) {
    Vec3f pos;
    CBBCoinWork* work;
    f32 x;
    f32 y;
    f32 z;
    f32 spd;
    f32 sq;
    f32 s;

    if (D_800ED430 != 1) {
        return;
    }
    work = obj->unk_50;
    if (work->unk_54 == 0) {
        return;
    }
    x = obj->trans.x;
    y = obj->trans.y;
    z = obj->trans.z;
    D_800ED6B8 = D_800F5254 = 0.0f;
    spd = work->unk_38;
    if (spd > 2.0f) {
        spd = 2.0f;
    }
    sq = spd * spd;
    y += sq * ((work->unk_38 >= 0.0f) ? -35.0f : 35.0f);
    work->unk_38 = D_800B8968 * 0.7f + work->unk_38;
    obj->trans.x = x + D_800ED6B8;
    obj->trans.y = y;
    obj->trans.z = z + D_800F5254;
    obj->rot.y = work->unk_3C;
    if (obj->trans.y >= 450.0f) {
        Vec3f* vp = &pos;
        func_800A0D00(vp, obj->trans.x, obj->trans.y, obj->trans.z);
        PlaySound(0xFC);
        func_800F7D98_CoinBlockBlitz(obj, vp);
    }
    func_80025798(obj->model[1], obj->trans.x, 0.0f, obj->trans.z);
    s = obj->trans.y - 0.0f;
    if (!(s > 200.0f)) {
        s = 0.4f - s / 2000.0001f;
    }
    func_80025830(obj->model[1], s, s, s);
}

void func_800F859C_CoinBlockBlitz(omObjData* block) {
    CBBStageWork* work = block->unk_50;
    s32 i;

    for (i = 0; i < D_800F2BC0; i++) {
        func_800090C4(D_800F3FB0[i], work->unk_05, 1);
    }
}

void func_800F8614_CoinBlockBlitz(omObjData* block, omObjData* player, BlockData* data) {
    CBBPlayerWork* work = player->unk_50;

    func_800258EC(player->model[10], 4, 0);
    func_8001E2A8(work->unk_21[10], 0);
    func_8001E268(work->unk_21[10], 4, 4);
    func_80025798(player->model[10], block->trans.x, block->trans.y, block->trans.z);
    func_80025830(player->model[10], 4.0f, 4.0f, 4.0f);
    data->unk_0A = 4;
    func_800F859C_CoinBlockBlitz(block);
    func_800258EC(block->model[0], 4, 4);
    func_800258EC(block->model[1], 4, 4);
    block->func_ptr = NULL;
}

void func_800F86F4_CoinBlockBlitz(omObjData* obj) {
    Vec3f unused; /* retail's frame has an unused vector */
    BlockData* bd;
    omObjData* p;
    CBBPlayerWork* pw;
    f32 s;
    s32 i;

    bd = &D_800FA950_CoinBlockBlitz[obj->work[0]];
    for (i = 0; i < D_800F2BC0; i++) {
        p = D_800F3FB0[i];
        pw = p->unk_50;
        if (CBB_ABS(obj->trans.x - p->trans.x) < 80.0f && CBB_ABS(obj->trans.z - p->trans.z) < 80.0f
            && p->trans.y + 180.0f > 250.0f && p->trans.y < 290.0f) {
            if (bd->timerType == 2) {
                func_80060540(0x194, pw->unk_58);
                func_800F8614_CoinBlockBlitz(obj, p, bd);
                func_800F7C30_CoinBlockBlitz(obj, p, 0);
                p->work[1]++;
            } else {
                if (bd->unk_0A < 2 && func_800F7C30_CoinBlockBlitz(obj, p, 0)) {
                    p->work[1]++;
                    func_80060540(0x194, pw->unk_58);
                    bd->unk_0A = 2;
                    bd->unk_0C = 0.0f;
                    bd->unk_10 = 10.0f;
                    bd->unk_14 = 0.0f;
                    bd->unk_18 = 2.5f;
                }
                pw->unk_38 = 0.5f;
                func_80017C0C(p, 6, obj->trans.x, obj->trans.y, obj->trans.z, 0.0f, 0.0f);
            }
        }
    }
    if (bd->unk_0A != 0 && bd->timerDuration != 0) {
        bd->timerDuration--;
    }
    switch (bd->unk_0A) {
    case 1:
        if (bd->timerDuration == 0) {
            bd->timerType = 2;
        }
        break;
    case 2:
        bd->unk_0C = bd->unk_0C + bd->unk_10 - bd->unk_14;
        bd->unk_14 += bd->unk_18;
        if (bd->unk_0C < 0.0f) {
            bd->unk_0C = 0.0f;
            bd->unk_0A = 1;
        }
        obj->trans.y = bd->unk_0C + 250.0f;
        s = 0.6f - bd->unk_0C * 0.005f;
        if (s < 0.5f) {
            s = 0.5f;
        }
        func_80025830(obj->model[1], s, 1.0f, s);
        break;
    }
}
