#include "common.h"
#include "14E940.h"

s32 func_800F8AD0_CoinBlockBlitz(void) {
    s32 i;

    for (i = 0; i < 9; i++) {
        if (!((D_800FA950_CoinBlockBlitz + i)->unk_0A - 3 < 2U)) {
            return 0;
        }
    }
    return 1;
}

void func_800F8B18_CoinBlockBlitz(void) {
    omObjData* p;
    CBBPlayerWork* w;
    s32 i;
    u32 coins;

    for (i = 0; i < D_800F2BC0; i++) {
        p = D_800F3FB0[i];
        w = p->unk_50;
        coins = p->work[1];
        if (_CheckFlag(0x2B) == 0 && p->work[1] >= 2) {
            coins >>= 1;
        }
        GwPlayer[w->unk_58].coins_mg += coins;
    }
}

void func_800F8BE4_CoinBlockBlitz(omObjData* obj) {
    s32 i;
    omObjData* p;
    CBBPlayerWork* w;

    func_800F6F1C_CoinBlockBlitz();
    func_80009468();
    switch (D_800ED430) {
    case 0:
        switch (D_800FA7E4_CoinBlockBlitz) {
        case 0:
            if (func_80072718() == 0) {
                if (D_800FA7E8_CoinBlockBlitz-- == 0) {
                    GMesCreate(0);
                    D_800FA7E4_CoinBlockBlitz = 1;
                }
            }
            break;
        case 1:
            if (GMesStatAllGet() == 0) {
                GMesCreate(8, 30, 160, 24);
                func_80009458();
            }
            break;
        }
        func_80079078(D_800FA7EC_CoinBlockBlitz / 30);
        break;
    case 1:
        if (D_800FA800_CoinBlockBlitz == 0 && D_800FA7EC_CoinBlockBlitz == D_800FA880_CoinBlockBlitz) {
            D_800FA800_CoinBlockBlitz++;
        }
        if (D_800FA94C_CoinBlockBlitz == 0) {
            func_80079078(D_800FA7EC_CoinBlockBlitz / 30);
            D_800FA7EC_CoinBlockBlitz--;
        }
        if (D_800FA7EC_CoinBlockBlitz == 0) {
            D_800FA94C_CoinBlockBlitz = 2;
        }
        if (func_800F8AD0_CoinBlockBlitz() != 0) {
            D_800FA94C_CoinBlockBlitz = 1;
        }
        if (D_800FA94C_CoinBlockBlitz != 0) {
            if (D_800FA7F8_CoinBlockBlitz == 0) {
                D_800FA7F8_CoinBlockBlitz = 1;
                func_800601D4(40);
                D_800FA7F0_CoinBlockBlitz = 210;
            }
            for (i = 0; i < D_800F2BC0; i++) {
                if (!(u8)func_800F73F4_CoinBlockBlitz(i)) {
                    break;
                }
            }
            if (i >= D_800F2BC0 || D_800FA7F0_CoinBlockBlitz-- == 0) {
                for (i = 0; i < D_800F2BC0; i++) {
                    p = D_800F3FB0[i];
                    w = p->unk_50;
                    w->unk_40 = 0.0f;
                    ContStkX[i] = ContStkY[i] = 0;
                    func_8006071C(w->unk_B3);
                }
                D_800FA7F0_CoinBlockBlitz = 0;
                func_80009438();
            }
        }
        break;
    case 2:
        if (D_800FA7F4_CoinBlockBlitz == 0) {
            D_800FA7F4_CoinBlockBlitz = 1;
            if (_CheckFlag(0x2B) != 0) {
                GMesCreate(2);
            } else {
                switch (D_800FA94C_CoinBlockBlitz) {
                case 1:
                    GMesCreate(2);
                    break;
                case 2:
                    GMesCreate(16);
                    break;
                }
            }
            func_800F7E5C_CoinBlockBlitz();
            break;
        }
        if (GMesStatAllGet() == 0 || GMesStatAllGet() & 2) {
            if (D_800FA7F0_CoinBlockBlitz == 0) {
                func_800790C0();
                if (_CheckFlag(0x2B) == 0) {
                    switch (D_800FA94C_CoinBlockBlitz) {
                    case 1:
                        func_80060128(0x36);
                        break;
                    case 2:
                        for (i = 0; i < D_800F2BC0; i++) {
                            p = D_800F3FB0[i];
                            if (p->work[1] != 0) {
                                break;
                            }
                        }
                        if (i < D_800F2BC0) {
                            func_80060128(0x3C);
                        } else {
                            func_80060128(0x34);
                        }
                        break;
                    }
                }
                func_800F8B18_CoinBlockBlitz();
                for (i = 0; i < D_800F2BC0; i++) {
                    p = D_800F3FB0[i];
                    w = p->unk_50;
                    if (_CheckFlag(0x2B) == 0) {
                        if (p->work[1] != 0) {
                            func_800184BC(p, 13);
                        } else {
                            func_800184BC(p, 14);
                        }
                        w->unk_3C = CRot.y;
                        func_8009ECB0(D_800F2B7C[p->model[0]].unk7C, 0.0f, w->unk_3C, 0.0f);
                    }
                }
            }
            if (_CheckFlag(0x2B) != 0) {
                if (++D_800FA7F0_CoinBlockBlitz >= 20) {
                    func_80009448();
                }
            } else {
                switch (D_800FA94C_CoinBlockBlitz) {
                case 1:
                    if (++D_800FA7F0_CoinBlockBlitz >= 105) {
                        func_80009448();
                    }
                    break;
                case 2:
                    if (++D_800FA7F0_CoinBlockBlitz >= 120) {
                        func_80009448();
                    }
                    break;
                }
            }
        }
        break;
    case 3:
        switch (D_800FA7FC_CoinBlockBlitz) {
        case 0:
            if (_CheckFlag(0x2B) == 0 || GMesWait() != 1) {
                func_800726AC(0, 20);
                D_800FA7FC_CoinBlockBlitz = 1;
            }
            break;
        case 1:
            if (func_80072718() == 0) {
                func_8002890C(0, 0, 0);
                omOvlReturnEx(1);
            }
            break;
        }
        break;
    }
}

void func_800F9208_CoinBlockBlitz(omObjData* obj) {
    CBBStageWork* w;

    obj->model[0] = func_800174C0(0x260000, 0x699);
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    w = func_80023684(0x2C, 0x7918);
    obj->unk_50 = w;
    func_8009B770(w, 0, 0x2C);
    obj->func_ptr = func_800F8BE4_CoinBlockBlitz;
    w->unk_04 = 1;
    func_80008FB8(obj, 0.5f);
    w->unk_05 = 0;
}

void func_800F92A0_CoinBlockBlitz(omObjData* obj) {
    BlockData* bd;
    f32 s;

    bd = &D_800FA950_CoinBlockBlitz[obj->work[0]];
    if (bd->unk_08 != 0) {
        bd->unk_08--;
        return;
    }
    obj->trans.y -= bd->unk_14;
    bd->unk_14 += bd->unk_18;
    if (obj->trans.y < 250.0f) {
        if (obj->work[0] == 3) {
            func_80060128(0x1B);
        }
        PlaySound(0x26F);
        obj->trans.y = 250.0f;
        obj->func_ptr = func_800F86F4_CoinBlockBlitz;
    }
    s = 0.6f - (obj->trans.y - 250.0f) * 0.001;
    if (s < 0.2f) {
        s = 0.2f;
    }
    func_80025830(obj->model[1], s, 1.0f, s);
}

void func_800F93E0_CoinBlockBlitz(omObjData* block, Vec* position, s32 blockIndex, s16 arg3) {
    BlockData* blockData;
    CBBStageWork* temp;
    s32 totalWeight;
    s32 randomValue;
    s32 i;
    s32 timerType;
    s16 timerDuration;
    f32 scale;

    // Initialize block model/graphics
    if (D_800FA804_CoinBlockBlitz == 0x80) {
        block->model[0] = func_800174C0(0x260001, 0x899);
        block->model[1] = func_800174C0(0x10, 0xA99);
        D_800FA804_CoinBlockBlitz = block->model[0];
        D_800FA808_CoinBlockBlitz = block->model[1];
    } else {
        block->model[0] = func_80023FC8(D_800FA804_CoinBlockBlitz);
        block->model[1] = func_80023FC8(D_800FA808_CoinBlockBlitz);
    }

    // Allocate and clear block data
    temp = func_80023684(0x2C, 0x7918);
    block->unk_50 = temp;
    func_8009B770(temp, 0, 0x2C);

    // Set position
    block->trans.x = position->x;
    block->trans.y = position->y;
    block->trans.z = position->z;

    func_80025798(block->model[1], block->trans.x, 0, block->trans.z);
    func_80025830(block->model[1], 0.6f, 1.0f, 0.6f);

    block->work[0] = blockIndex;
    temp->unk_04 = 1;
    func_80008FB8(block, 0.5f);
    temp->unk_05 = blockIndex + 1;

    blockData = &D_800FA950_CoinBlockBlitz[blockIndex];

    // Calculate total weight from weight table
    totalWeight = 0;
    for (i = 0; D_800FA80C_CoinBlockBlitz[i] != -1; i++) {
        totalWeight += D_800FA80C_CoinBlockBlitz[i];
    }

    // Pick random timer type based on weights
    randomValue = (rand8() & 0xFF) % totalWeight;
    for (timerType = 0; D_800FA80C_CoinBlockBlitz[timerType] != -1; timerType++) {
        if (randomValue - D_800FA80C_CoinBlockBlitz[timerType] < 0) {
            break;
        }
        randomValue -= D_800FA80C_CoinBlockBlitz[timerType];
    }

    blockData->timerType = timerType;

    // Decrement weight so this timer type is less likely next time
    if (D_800FA80C_CoinBlockBlitz[timerType] != -1) {
        D_800FA80C_CoinBlockBlitz[timerType]--;
    }

    // Set timer duration based on type
    // Type 0 = 300 frames (~5 sec)
    // Type 1 = 120 frames (~2 sec)
    // Type 2+ = infinite (-1)
    switch (blockData->timerType) {
    case 1:
        blockData->timerDuration = 120;
        break;
    case 0:
        blockData->timerDuration = 300;
        break;
    case 2:
        blockData->timerDuration = -1;
        break;
    }
    
    blockData->block = block;
    blockData->unk_08 = arg3;
    blockData->unk_0A = 0;
    blockData->unk_0C = 0.0f;
    blockData->unk_10 = 0.0f;
    blockData->unk_14 = 0.0f;
    blockData->unk_18 = 2.5f;
    blockData->unk_1C = 50.0f;

    // Scale based on Y position
    scale = 0.6f - ((block->trans.y - 250.0f) * 0.001);
    if (scale < 0.2f) {
        scale = 0.2f;
    }
    func_80025830(block->model[1], scale, 1.0f, scale);

    block->func_ptr = func_800F92A0_CoinBlockBlitz;
}

u16 func_800F9754_CoinBlockBlitz(s32 file, s32 arg1, s32 arg2, u16 shared) {
    void* data;
    s16 sprite;

    if (shared == 0) {
        data = DataRead(file);
        sprite = func_8001E00C(data, (u16)arg1, arg2);
        D_800FA882_CoinBlockBlitz = D_800ECDE0[sprite].unk_02;
        HuMemDirectFree(data);
    } else {
        sprite = func_8001E00C((void*)-1, (u16)arg1, arg2);
        if (sprite != -1) {
            D_800ECDE0[sprite].unk_02 = D_800FA882_CoinBlockBlitz;
        }
    }
    return sprite;
}

void func_800F9838_CoinBlockBlitz(omObjData* obj, u8 slot, s32 file, s32 arg3, s32 arg4, u16 shared) {
    CBBPlayerWork* w = obj->unk_50;
    u8 sprite;

    sprite = func_800F9754_CoinBlockBlitz(file, arg3, arg4, shared);
    obj->model[slot] = D_800ECDE0[sprite].unk_00;
    w->unk_21[slot] = sprite;
    func_80025930(D_800ECDE0[sprite].unk_00, 0x70000000, 0x70000000);
    func_8001E268(sprite, 4, 4);
}

void func_800F98F8_CoinBlockBlitz(omObjData* obj, s32 file, s32 arg2, Vec3f* pos, s32 index) {
    CBBCoinSlot* slot;
    CBBCoinWork* w;
    void* data;
    s32 dir;
    s32 bits;

    slot = &D_800FA898_CoinBlockBlitz[index];
    obj->unk_50 = func_80023684(sizeof(CBBCoinWork), 0x7918);
    func_8009B770(obj->unk_50, 0, sizeof(CBBCoinWork));
    obj->func_ptr = func_800F83A8_CoinBlockBlitz;
    w = obj->unk_50;
    dir = 0xA8D;
    bits = 8;
    if (D_800FA81E_CoinBlockBlitz == -1) {
        data = DataRead(file);
        w->unk_55 = func_8001E00C(data, 0xA8D, 8);
        D_800FA81E_CoinBlockBlitz = D_800ECDE0[w->unk_55].unk_02;
        HuMemDirectFree(data);
    } else {
        w->unk_55 = func_8001E00C((void*)-1, (u16)dir, bits);
        if (w->unk_55 != 0xFF) {
            D_800ECDE0[w->unk_55].unk_02 = D_800FA81E_CoinBlockBlitz;
        }
    }
    obj->model[0] = D_800ECDE0[w->unk_55].unk_00;
    func_80025930(obj->model[0], 0x70000000, 0x70000000);
    obj->model[1] = func_800174F4(6, 0xA9D);
    func_800F9838_CoinBlockBlitz(obj, 3, 0x2A, 0xA8D, 8, D_800FA81C_CoinBlockBlitz++);
    func_8001E360(w->unk_21[3], 0xFF, 0xFF, 0xBE);
    obj->trans.x = pos->x;
    obj->trans.y = pos->y;
    obj->trans.z = pos->z;
    obj->scale.x = obj->scale.y = obj->scale.z = 2.0f;
    func_800F6F24_CoinBlockBlitz(obj, 0.8f, 0.0f, 1);
    w->unk_44 = 0.1f;
    w->unk_48 = 30.0f;
    w->unk_34 = 500.0f;
    w->unk_5C = 0;
    w->unk_3C = 60.0f;
    w->unk_40 = D_800B8984;
    w->unk_38 = 1000.0f;
    w->unk_52 = arg2;
    w->unk_60 = 0.0f;
    w->unk_4C = 0.5f;
    w->unk_50 = 0;
    w->unk_54 = 0;
    w->unk_58 = 0.5f;
    obj->work[0] = index;
    slot->obj = obj;
    slot->unk_08 = 0;
}

void func_800F9BCC_CoinBlockBlitz(omObjData* obj, s32 arg1, s32 arg2, u16 player, Vec3f* pos, u16 arg5) {
    CBBPlayerWork* w;

    func_8000979C(obj, arg1, arg2, player, 0xA99, 0xA99);
    obj->model[3] = LoadFormFile(0x19, 0xA8D);
    obj->model[4] = LoadFormFile(0x1A, 0xA8D);
    obj->model[6] = LoadFormFile(0x1B, 0xA8D);
    func_800F9838_CoinBlockBlitz(obj, 10, 0x26, 0x168D, 8, D_800FA820_CoinBlockBlitz++);
    w = obj->unk_50;
    func_800187D0(obj, 0, arg1, 1, 0);
    func_800187D0(obj, 1, arg1 | 1, 1, 0);
    func_800187D0(obj, 2, arg1 | 3, 1, 0);
    func_800187D0(obj, 6, arg1 | 5, 1, 0x13);
    func_800187D0(obj, 9, arg1 | 0xA, 1, 0x27);
    if (rand8() & 1) {
        func_800187D0(obj, 0xD, arg1 | 0xF, 1, 0x78);
        func_800187D0(obj, 0xE, arg1 | 0x10, 1, 0x78);
    } else {
        func_800187D0(obj, 0xD, arg1 | 0x38, 1, 0x78);
        func_800187D0(obj, 0xE, arg1 | 0x3C, 1, 0x78);
    }
    func_800187D0(obj, 0x11, arg1 | 0x18, 0, 0);
    func_800187D0(obj, 0x12, arg1 | 0x1C, 2, 0);
    func_800187D0(obj, 0x13, arg1 | 0x1D, 2, 0);
    func_800187D0(obj, 0xA, arg1 | 0x1E, 1, 0x27);
    func_800187D0(obj, 0x15, arg1 | 0x62, 0, 0);
    func_800187D0(obj, 3, arg1 | 0x60, 1, 0);
    func_800187D0(obj, 4, arg1 | 0x61, 1, 0);
    func_800187D0(obj, 0x1E, arg1 | 0x63, 2, 0);
    func_800187D0(obj, 0x1F, arg1 | 0x64, 0, 0);
    func_800187D0(obj, 0x20, arg1 | 0x67, 0, 0);
    func_800090C4(obj, 0, 2);
    func_800090C4(obj, 1, 2);
    func_800090C4(obj, 2, 2);
    func_800090C4(obj, 3, 2);
    func_800090C4(obj, 4, 2);
    func_800090C4(obj, 5, 2);
    func_800090C4(obj, 6, 2);
    func_800090C4(obj, 7, 2);
    func_800090C4(obj, 8, 2);
    func_800090C4(obj, 9, 2);
    obj->work[0] = player;
    obj->work[1] = 0;
    func_800F6FA8_CoinBlockBlitz(obj);
    obj->trans.x = pos->x;
    obj->trans.y = pos->y;
    obj->trans.z = pos->z;
    w->unk_56 = GwPlayer[player].port;
    D_800B8964 = 1.3f;
    w->unk_3C = CRot.y;
    func_800F6F24_CoinBlockBlitz(obj, 1.0f, 0.0f, 1);
    obj->func_ptr = func_800F81F0_CoinBlockBlitz;
}




#define CBB_PLAYER_FUNC(name, n)                                                                   \
    void name(omObjData* obj) {                                                                    \
        Vec3f pos;                                                                                 \
        Vec3f* vp = &pos;                                                                          \
        s16 chr;                                                                                   \
        func_800A0D00(vp, D_800FA824_CoinBlockBlitz[D_800FA8E0_CoinBlockBlitz[n + 1]].x,          \
                      D_800FA824_CoinBlockBlitz[D_800FA8E0_CoinBlockBlitz[n + 1]].y,              \
                      D_800FA824_CoinBlockBlitz[D_800FA8E0_CoinBlockBlitz[n + 1]].z);             \
        chr = GwPlayer[n].character;                                                               \
        func_800F9BCC_CoinBlockBlitz(obj, D_800C59AC[chr].unk_00, D_800C59AC[chr].unk_04, n, vp,   \
                                     chr);                                                         \
    }

CBB_PLAYER_FUNC(func_800F9FB8_CoinBlockBlitz, 0)
CBB_PLAYER_FUNC(func_800FA068_CoinBlockBlitz, 1)
CBB_PLAYER_FUNC(func_800FA118_CoinBlockBlitz, 2)
CBB_PLAYER_FUNC(func_800FA1C8_CoinBlockBlitz, 3)

#define CBB_COIN_FUNC(name, n)                                                                     \
    void name(omObjData* obj) {                                                                    \
        Vec3f pos;                                                                                 \
        Vec3f* vp = &pos;                                                                          \
        func_800A0D00(vp, 0.0f, 0.0f, 0.0f);                                                       \
        func_800F98F8_CoinBlockBlitz(obj, 0x21, 3, vp, n);                                         \
    }

CBB_COIN_FUNC(func_800FA278_CoinBlockBlitz, 0)
CBB_COIN_FUNC(func_800FA2D0_CoinBlockBlitz, 1)
CBB_COIN_FUNC(func_800FA32C_CoinBlockBlitz, 2)
CBB_COIN_FUNC(func_800FA388_CoinBlockBlitz, 3)
CBB_COIN_FUNC(func_800FA3E4_CoinBlockBlitz, 4)
CBB_COIN_FUNC(func_800FA440_CoinBlockBlitz, 5)

#define CBB_BLOCK_FUNC(name, x, z, n, delay)                                                       \
    void name(omObjData* obj) {                                                                    \
        Vec3f pos;                                                                                 \
        Vec3f* vp = &pos;                                                                          \
        f32 px = x;                                                                                \
        f32 pz = z;                                                                                \
        func_800A0D00(vp, px, 1000.0f, pz);                                                        \
        func_800F93E0_CoinBlockBlitz(obj, (Vec*)vp, n, delay);                                     \
    }

CBB_BLOCK_FUNC(func_800FA49C_CoinBlockBlitz, -300.0f, -300.0f, 0, 0)
CBB_BLOCK_FUNC(func_800FA500_CoinBlockBlitz, 0.0f, -300.0f, 1, 10)
CBB_BLOCK_FUNC(func_800FA554_CoinBlockBlitz, 300.0f, -300.0f, 2, 20)
CBB_BLOCK_FUNC(func_800FA5A8_CoinBlockBlitz, -300.0f, 0.0f, 3, 70)
CBB_BLOCK_FUNC(func_800FA5FC_CoinBlockBlitz, 0.0f, 0.0f, 4, 80)
CBB_BLOCK_FUNC(func_800FA65C_CoinBlockBlitz, 300.0f, 0.0f, 5, 30)
CBB_BLOCK_FUNC(func_800FA6B0_CoinBlockBlitz, -300.0f, 300.0f, 6, 60)
CBB_BLOCK_FUNC(func_800FA704_CoinBlockBlitz, 0.0f, 300.0f, 7, 50)
CBB_BLOCK_FUNC(func_800FA758_CoinBlockBlitz, 300.0f, 300.0f, 8, 40)
