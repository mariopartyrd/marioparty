#include "common.h"
s16 D_800C4C30[7] = { 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C };
s32 D_800C4C40[] = { 0xA0000, 0xA0000, 0xA0000, 0xA0000, 0xA0000, 0xA0001 };
s32 D_800C4C58[] = { 0xA0004, 0xA0005, 0xA0006, 0xA0007, 0xA0008, 0xA0009 };

typedef struct DiceProcWork {
    /* 0x00 */ s32 player;
    /* 0x04 */ s32 state;
} DiceProcWork;

void func_80039ACC(s16);
void func_80047694(s32);
s32 func_80047B68(void);
void func_800471FC(void);
void func_80052C44(s32, s32, s32, s32, s32);
s32 func_80041644(s32);
s32 func_80041664(s32);
extern s16 D_800EE320;


s16 func_80038D5C(unk2C0C0StructC0*, u16, s32, char*);
void func_8003967C(s16, u8);
void func_800396B0(s16, u8);
s32 func_8004606C(void);


void func_80041250(s32);


void func_80067284(s16, s16, f32);
s16 func_80056990(void);


typedef struct DiceBlockWork {
    /* 0x00 */ s8 unk0;
    /* 0x01 */ s8 unk1;
    /* 0x02 */ s8 unk2;
    /* 0x03 */ s8 unk3;
    /* 0x04 */ s8 unk4;
    /* 0x05 */ s8 unk5;
    /* 0x06 */ s8 unk6;
    /* 0x07 */ s8 unk7;
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ s16 unk10[6];
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ s16 unk20;
    /* 0x22 */ char pad22[2];
    /* 0x24 */ void* unk24;
    /* 0x28 */ void* unk28;
    /* 0x2C */ omObjData* unk2C;
    /* 0x30 */ omObjData* unk30;
    /* 0x34 */ omObjData* unk34;
    /* 0x38 */ f32 unk38;
    /* 0x3C */ f32 unk3C;
    /* 0x40 */ f32 unk40;
} DiceBlockWork; /* size = 0x44 */

extern DiceBlockWork D_800D62D0[4];
extern u8 D_800D63E0;
extern u8 D_800D63E1;
extern u8 D_800D63E2;
extern s32 D_800D63E4;
extern s8 D_800F384E;


extern s16 D_800ECC20;
extern s16 D_800ED3C0;
extern s16 D_800F3180;
extern s16 D_800F3298;
extern s16 D_800F37E8;
extern s16 D_800F65D8;


extern s16 D_800F2CDC;
extern s16 D_800F65B8;
extern s16 D_800F37A8;
extern s16 D_800EE986;
extern s16 D_800F64C6;
s16 GetSumOfPlayerStars(void);

typedef struct {
    /* 0x00 */ Process* process;
    /* 0x04 */ u16* sequence;
    /* 0x08 */ s16 index;
} ButtonSeqWork;


s16 RunDecisionTree(DecisionTreeNonLeafNode* currentNode) {
    s32 loopIndex;
    DecisionTreeNonLeafNode* tempNode;
    s32 tempVal1;
    s16 tempVal2;
    u32 tempVal3;
    u32 tempVal4;
    u8 tempVal5;

    s32 phi_v0;
    s32 phi_s0;
    s32 phi_s0_2;
    s32 phi_v0_2;
    s32 phi_a0;
    s32 phi_a1;

    DecisionTreeNonLeafNode* phi_s1 = currentNode;

    for (;;phi_s1++) {
        switch ((phi_s1->type >> 24)) {
        case 1:
            if (PlayerHasCoins(-1, phi_s1->node_data1.data) != 0) {
                break;
            }
            continue;
        case 2:
            for (loopIndex = 0; loopIndex < 7; loopIndex++) {
                if ((1 << loopIndex) & phi_s1->node_data1.data) {
                    if (!_CheckFlag(D_800C4C30[loopIndex])) {
                        break;
                    }
                }
            }
            if (loopIndex == 7) {
                continue;
            }
            break;

        case 3:
            if (((1 << (D_800F3FF0 - 1)) & phi_s1->node_data1.data)) {
                break;
            }
            continue;
        case 4:
            tempVal4 = phi_s1->node_data1.data;
            tempVal1 = (tempVal4 >> 0x14);
            tempVal2 = phi_s1->node_data1.data;
            tempVal3 = (tempVal4 >> 0x10) & 0xF;
            tempVal1 &= 0xF;

            switch (tempVal3) {
            case 0:
                if (GwCommon.boardWork[tempVal1] == tempVal2) {
                    break;
                }
                continue;
            case 1:
                if (GwCommon.boardWork[tempVal1] != tempVal2) {
                    break;
                }
                continue;
            case 2:
                if ((GwCommon.boardWork[tempVal1] < tempVal2)) {
                    break;
                }
                continue;
            case 3:
                if ((GwCommon.boardWork[tempVal1] <= tempVal2)) {
                    break;
                }
                continue;
            case 4:
                if ((GwCommon.boardWork[tempVal1] > tempVal2)) {
                    break;
                }
                continue;
            case 5:
                if ((GwCommon.boardWork[tempVal1] < tempVal2)) {
                    continue;
                }
                break;
            }
            break;
        case 5:
            if (((1 << func_8004FEBC(GetCurrentPlayerIndex())) & phi_s1->node_data1.data)) {
                break;
            }
            continue;
        case 6:
            if (((func_ptr*)phi_s1->node_data1.data)() != 0) {
                break;
            }
            continue;
        case 7:
            if ((u32) GetTurnsElapsed() < (u32) phi_s1->node_data1.data) {
                continue;
            }
        case 0:
            break;
        }
        if ((s32)phi_s1->node_data2.data < 0) {
            phi_s1 = (DecisionTreeNonLeafNode*)phi_s1->node_data2.data - 1;
        } else {
            if (GetPlayerStruct(-1)->cpu_difficulty_copy == 0) {
                phi_a0 = phi_s1->node_data2.data & 0xFF;
            } else {
                phi_a0 = (phi_s1->node_data2.data >> 8);
            }
            if (RNGPercentChance(phi_a0) != 0) {
                tempVal2 = (phi_s1->node_data2.data >> 16) & 1;
            } else {
                tempVal2 = ((phi_s1->node_data2.data >> 16) ^ 1) & 1;
            }
            return tempVal2;
        }
    }
}

void func_8003ECB0(u16 arg0, u16 arg1, s32 arg2, u8 arg3, u8 arg4) {
    fontcolor = arg4;
    print8((arg0 + 1), (arg1 + 1), arg2);
    fontcolor = arg3;
    print8(arg0, arg1, arg2);
}


void func_8003ED30(void) {
    ButtonSeqWork* work = HuPrcCurrentGet()->user_data;

    while (TRUE) {
        if (ContBtnTrg[0] != 0) {
            if (ContBtnTrg[0] == work->sequence[work->index]) {
                work->index++;
                if (work->sequence[work->index] == 0) {
                    work->index = -1;
                    break;
                }
            } else {
                work->index = 0;
            }
        }
        HuPrcVSleep();
    }
    while (TRUE) {
        HuPrcVSleep();
    }
}

s32 func_8003EDDC(s32* sequence) {
    Process* process = omAddPrcObj(func_8003ED30, 0xEFFF, 0, 0x40);
    ButtonSeqWork* work = HuMemMemoryAlloc(process->heap, sizeof(ButtonSeqWork));

    process->user_data = work;
    work->sequence = (u16*)sequence;
    work->index = 0;
    work->process = process;
    return (s32)work;
}
void func_8003EE3C(s32 work) {
    EndProcess(((ButtonSeqWork*)work)->process);
}
s32 func_8003EE58(s32 work) {
    return ((ButtonSeqWork*)work)->index == -1;
}
void func_8003EE68(s16 x, s16 y) {
    s32 i;
    GW_PLAYER* player;

    sprintf(pfStrBuf, "   GAME COIN  ?  R  B  Y  !  M  K");
    func_8003ECB0(x * 8, y * 8, (s32)pfStrBuf, 15, 9);
    for (i = 0; i < 4; ) {
        player = GetPlayerStruct(i);
        i++;
        sprintf(pfStrBuf, "%d: %4d %4d %2d %2d %2d %2d %2d %2d %2d", i, player->coins_total, player->coins_max,
                (s8)player->happening_count, (s8)player->red_count, (s8)player->blue_count,
                (s8)player->minigame_count, (s8)player->chance_count, (s8)player->mushroom_count,
                (s8)player->bowser_count);
        func_8003ECB0(x * 8, (y + i) * 8, (s32)pfStrBuf, 15, 9);
    }
}
void func_8003EF98(s16 x, s16 y) {
    sprintf(pfStrBuf, "KM: %d", D_800F2CDC);
    func_8003ECB0(x * 8, y * 8, (s32)pfStrBuf, 15, 9);
}
void func_8003F008(s16 x, s16 y) {
    sprintf(pfStrBuf, "STAR:%2d", GetSumOfPlayerStars());
    func_8003ECB0(x * 8, y * 8, (s32)pfStrBuf, 15, 9);
}
void func_8003F07C(s16 x, s16 y) {
    sprintf(pfStrBuf, "1   :%2d", D_800F65B8);
    func_8003ECB0(x * 8, y * 8, (s32)pfStrBuf, 15, 9);
    sprintf(pfStrBuf, "1VS3:%2d", D_800F37A8);
    func_8003ECB0(x * 8, (y + 1) * 8, (s32)pfStrBuf, 15, 9);
    sprintf(pfStrBuf, "2VS2:%2d", D_800EE986);
    func_8003ECB0(x * 8, (y + 2) * 8, (s32)pfStrBuf, 15, 9);
    sprintf(pfStrBuf, "4   :%2d", D_800F64C6);
    func_8003ECB0(x * 8, (y + 3) * 8, (s32)pfStrBuf, 15, 9);
}
void func_8003F1C0(s16 x, s16 y) {
    sprintf(pfStrBuf, "+ :%2d", D_800F3298);
    func_8003ECB0(x * 8, y * 8, (s32)pfStrBuf, 15, 9);
    sprintf(pfStrBuf, "- :%2d", D_800F3180);
    func_8003ECB0(x * 8, (y + 1) * 8, (s32)pfStrBuf, 15, 9);
    sprintf(pfStrBuf, "S+:%2d", D_800ECC20);
    func_8003ECB0(x * 8, (y + 2) * 8, (s32)pfStrBuf, 15, 9);
    sprintf(pfStrBuf, "S-:%2d", D_800ED3C0);
    func_8003ECB0(x * 8, (y + 3) * 8, (s32)pfStrBuf, 15, 9);
    sprintf(pfStrBuf, "WA:%2d", D_800F65D8);
    func_8003ECB0(x * 8, (y + 4) * 8, (s32)pfStrBuf, 15, 9);
    sprintf(pfStrBuf, "YO:%2d", D_800F37E8);
    func_8003ECB0(x * 8, (y + 5) * 8, (s32)pfStrBuf, 15, 9);
}
void func_8003F384(s16 x, s16 y) {
    sprintf(pfStrBuf, "MAP: %d    TURN: %d", GwSystem.curBoardIndex + 1, GwSystem.currentTurn);
    func_8003ECB0(x * 8, y * 8, (s32)pfStrBuf, 15, 9);
}
void func_8003F400(omObjData* obj) {
    DiceBlockWork* work = &D_800D62D0[obj->work[3]];
    s32 i;
    s32 sound;

    switch (obj->work[0]) {
    case 0:
        if (D_800F384E != 0) {
            break;
        }
        obj->scale.x = obj->scale.y = obj->scale.z = sinf(obj->work[1] * 2 * (M_PI / 180.0)) * work->unk40 + 1.0f;
        obj->rot.y += 22.5f;
        obj->work[1] += 25;
        obj->work[1] %= 180;
        work->unk40 -= 0.05;
        if (work->unk40 <= 0.0f) {
            work->unk40 = 0.0f;
            obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
            obj->work[1] = 0;
            obj->work[0] = 1;
            if (D_800D63E1 == 1) {
                for (i = 0; i < 4; i++) {
                    if (D_800D62D0[i].unk1E != -1) {
                        break;
                    }
                }
                if (i == 4) {
                    sound = (GwSystem.curBoardIndex == 8) ? 0x2E : 0x2D;
                    goto play;
                }
                work->unk1E = D_800D62D0[i].unk1E;
            } else if (work->unk20 == 0) {
                if (D_800D63E1 == 3) {
                    sound = 0x4F;
                    goto play;
                }
                if (work->unk5 != 5 && D_800D63E1 != 4) {
                    sound = 0x2D;
                play:
                    work->unk1E = PlaySound(sound);
                }
            }
        }
        break;
    case 1:
        if (D_800F384E != 0) {
            break;
        }
        obj->trans.y = GwPlayer[obj->work[3]].player_obj->coords.y + D_800D63E4 +
                       sinf(obj->work[1] * 2 * (M_PI / 180.0)) * 10.0f;
        obj->work[1] += 5;
        obj->work[1] %= 180;
        break;
    case 2:
        D_800C34A4 = work->unk40;
        func_80025930(obj->model[0], 0x22000, 0x20000);
        func_80026B8C(obj->model[0], work->unk38, work->unk3C, 2);
        if (D_800F384E != 0) {
            break;
        }
        work->unk40 += 39.0f;
        work->unk38 += 0.05f;
        work->unk3C += (10.0f - work->unk3C) / 30.0f;
        if (work->unk38 > 1.0f) {
            func_80041250(obj->work[3]);
        }
        break;
    }
}
void func_8003F7FC(omObjData* obj) {
    DiceBlockWork* work = &D_800D62D0[obj->work[3]];
    Vec3f pos;
    Vec2f screen;
    f32 scale;

    if (obj->work[0] == 0 && D_800F384E == 0) {
        obj->scale.x = sinf(obj->rot.x * (M_PI / 180.0)) * obj->scale.z + 1.0f;
        obj->rot.x += 20.0f;
        if (obj->rot.x >= 360.0f) {
            obj->rot.x -= 360.0f;
        }
        obj->scale.z -= 0.15;
        if (obj->scale.z <= 0.0f) {
            obj->scale.x = 1.0f;
            obj->work[0] = 1;
        }
    }
    scale = obj->scale.x / 2.0f;
    func_80067354(work->unk8, 0, scale, scale);
    if (work->unk0 == 0) {
        func_800672DC(work->unk8, 0, work->unk3, 0);
        func_800672B0(work->unk8, 0, 1);
    }
    pos.x = GwPlayer[obj->work[3]].player_obj->coords.x;
    pos.y = GwPlayer[obj->work[3]].player_obj->coords.y + D_800D63E4 + obj->trans.y;
    pos.z = GwPlayer[obj->work[3]].player_obj->coords.z;
    func_8004B730(&pos, &screen);
    func_80066DC4(work->unk8, 0, screen.x, screen.y - 8.0f);
}
void func_8003FA5C(omObjData* obj) {
    DiceBlockWork* work = &D_800D62D0[obj->work[3]];
    Vec3f pos;
    Vec2f screen;

    if (obj->work[0] == 0 && D_800F384E == 0) {
        obj->scale.x = sinf(obj->rot.x * (M_PI / 180.0)) * obj->scale.z + 1.0f;
        obj->rot.x += 20.0f;
        if (obj->rot.x >= 360.0f) {
            obj->rot.x -= 360.0f;
        }
        obj->scale.z -= 0.05;
        if (obj->scale.z <= 0.0f) {
            obj->scale.x = 1.0f;
            obj->work[0] = 1;
        }
    }
    func_80067354(work->unk8, 0, obj->scale.x, obj->scale.x);
    if (work->unk0 == 0) {
        func_800672DC(work->unk8, 0, work->unk3, 0);
        func_800672B0(work->unk8, 0, 1);
    }
    pos.x = GwPlayer[obj->work[3]].player_obj->coords.x;
    pos.y = GwPlayer[obj->work[3]].player_obj->coords.y + D_800D63E4 + obj->trans.y;
    pos.z = GwPlayer[obj->work[3]].player_obj->coords.z;
    func_8004B730(&pos, &screen);
    func_80066DC4(work->unk8, 0, screen.x, screen.y);
}
void func_8003FC94(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_800D62D0[i].unk3 = 0;
        D_800D62D0[i].unk2 = 0;
    }
}
void func_8003FCD4(void) {
    s32 i;
    DiceBlockWork* work;

    for (i = 0; i < 4; i++) {
        work = &D_800D62D0[i];
        work->unkC = -1;
        work->unkE = -1;
        work->unk28 = NULL;
        work->unk1C = -1;
        work->unk8 = -1;
        work->unkA = -1;
        work->unk7 = 0;
        work->unk2C = NULL;
        work->unk30 = NULL;
        work->unk34 = NULL;
        work->unk6 = 0;
        work->unk0 = 0;
        work->unk2 = 0;
        work->unk1E = -1;
        work->unk20 = 0;
        work->unk4 = -1;
    }
    D_800D63E1 = 0;
    D_800D63E2 = 1;
    D_800D63E4 = 250;
}
void func_8003FD68(s32 idx) {
    s32 files[9] = { 0xA012F, 0xA0130, 0xA000D, 0xA000C, 0xA000E, 0xA000F, 0xA0010, 0xA0131, 0xA0130 };
    DiceBlockWork* work = &D_800D62D0[idx];
    s32 file;
    void* data;
    s16 shared;
    s16 sprite;

    if (work->unk0 != 0) {
        file = files[work->unk0 - 1];
    } else if (idx != 0 && (shared = D_800D62D0[0].unkA) != -1) {
        work->unkA = shared;
        D_800D62D0[0].unk7++;
        goto loaded;
    } else {
        file = 0xA000B;
    }
    data = DataRead(file);
    work->unkA = func_800678A4(data);
    work->unk7 = 1;
    DataClose(data);
loaded:
    sprite = func_80064EF4(1, 5);
    work->unk8 = sprite;
    func_80067208(sprite, 0, work->unkA, 0);
    func_80067384(work->unk8, 0, 0x4000);
    func_800674BC(work->unk8, 0, 0x9000);
    func_80067284(work->unk8, 0, 0.0f);
    func_80067354(work->unk8, 0, 0.0f, 0.0f);
    func_800672DC(work->unk8, 0, 0, 0);
    func_800672B0(work->unk8, 0, 1);
    work->unk6 = 1;
}
void func_8003FEFC(s32 idx) {
    DiceBlockWork* work = &D_800D62D0[idx];
    Vec3f pos;
    Vec2f screen;
    omObjData* obj;

    if ((work->unk0 != 0 || work->unk3 != 0) && (work->unk2C == NULL || work->unk2C->work[0] == 2)) {
        pos.x = GwPlayer[idx].player_obj->coords.x;
        pos.y = GwPlayer[idx].player_obj->coords.y + D_800D63E4;
        pos.z = GwPlayer[idx].player_obj->coords.z;
        func_8004B730(&pos, &screen);
        if (work->unk8 == -1) {
            func_8003FD68(idx);
            work->unk6 = 0;
        } else {
            func_800672DC(work->unk8, 0, work->unk3, 0);
            func_80067384(work->unk8, 0, 0x4000);
            func_800672B0(work->unk8, 0, 1);
        }
        if (func_80056990() == 0 && D_800D63E1 == 0) {
            func_80066DC4(work->unk8, 0, screen.x, screen.y - 8.0f);
        } else {
            func_80066DC4(work->unk8, 0, screen.x, screen.y);
        }
        func_80067480(work->unk8, 0, 0x8000);
        if (work->unk34 == NULL) {
            if (func_80056990() == 0 && D_800D63E1 == 0) {
                obj = omAddObj(0x8000, 0, 0, -1, func_8003F7FC);
                work->unk34 = obj;
                obj->scale.z = 3.0f;
            } else {
                obj = omAddObj(0x8000, 0, 0, -1, func_8003FA5C);
                work->unk34 = obj;
                obj->scale.z = 1.0f;
            }
            obj->work[0] = 0;
            obj->work[3] = idx;
            obj->scale.x = 0.0f;
            obj->rot.x = 270.0f;
            obj->trans.y = 0.0f;
        }
    }
}
void func_8004017C(s32 idx) {
    DiceBlockWork* work = &D_800D62D0[idx];
    s32 i;

    if (work->unk6 == 0) {
        func_800405DC(idx);
    }
    work->unk6 = 0;
    if (D_800D63E1 == 2) {
        if (D_800D63E0 == 0) {
            if ((work->unk0 = rand8() % 3 + 1) != 1) {
                goto set2;
            }
            goto call5;
        }
        if ((work->unk0 = rand8() % 3 + 1) == 1) {
            goto call5;
        }
    set2:
        work->unk0 = 2;
    } else if (D_800D63E1 == 5) {
        if ((work->unk0 = rand8() % 3 + 8) != 9) {
            work->unk0 = 8;
        }
        if (work->unk0 == 8) {
        call5:
            func_800503B0(idx, 5);
        } else {
            func_800503B0(idx, 4);
        }
    } else if (D_800D63E1 == 3) {
        if (work->unk2 != 0) {
            work->unk1 = work->unk0 = work->unk2;
            work->unk2 = 0;
        } else {
            work->unk1 = work->unk0 = rand8() % 3 + 3;
            if (work->unk0 == 3) {
                func_800503B0(idx, 6);
            } else {
                work->unk1 = work->unk0 = 4;
            }
        }
    } else if (D_800D63E1 == 4) {
        work->unk1 = work->unk0 = rand8() % 3 + 5;
    } else if (D_800D63E1 == 1) {
        do {
            if (work->unk2 != 0) {
                work->unk3 = work->unk2;
                work->unk2 = 0;
            } else {
                work->unk3 = rand8() % 10 + 1;
            }
            for (i = 0; i < 4; i++) {
                if (i != idx && D_800D62D0[i].unk3 == work->unk3) {
                    break;
                }
            }
        } while (i != 4);
    } else {
        switch (work->unk5) {
        case 0:
        case 1:
        case 2:
            if (work->unk2 != 0) {
                work->unk3 = work->unk2;
                work->unk2 = 0;
            } else {
                work->unk3 = rand8() % 10 + 1;
            }
            break;
        case 3:
            work->unk3 = rand8() % 3 + 8;
            break;
        case 4:
            work->unk3 = rand8() % 3 + 1;
            break;
        case 5:
            work->unk3 = 0;
            break;
        }
    }
    func_8003FEFC(idx);
}
void func_80040590(s32 idx) {
    DiceBlockWork* work = &D_800D62D0[idx];

    if (work->unk34 != NULL) {
        omDelObj(work->unk34);
        work->unk34 = NULL;
    }
}
void func_800405DC(s32 idx) {
    DiceBlockWork* work = &D_800D62D0[idx];

    work->unk0 = 0;
    if (work->unk8 != -1) {
        func_80064D38(work->unk8);
        work->unk8 = -1;
    }
    if (work->unkA != -1 && work->unk7 != 0) {
        if (--work->unk7 == 0) {
            func_80067704(work->unkA);
            work->unkA = -1;
        }
    }
    if (work->unk34 != NULL) {
        omDelObj(work->unk34);
        work->unk34 = NULL;
    }
}
void func_8004068C(s32 idx) {
    D_800D62D0[idx].unk3--;
    if (D_800D62D0[idx].unk3 <= 0) {
        func_800405DC(idx);
    }
}
void func_800406E4(s32 idx) {
    if (D_800D62D0[idx].unkC != -1) {
        func_800258EC(D_800D62D0[idx].unkC, 4, 4);
    }
}
void func_80040724(s32 idx) {
    if (D_800D62D0[idx].unkC != -1) {
        func_800258EC(D_800D62D0[idx].unkC, 4, 0);
    }
}
void func_80040764(s32 idx, s8 value) {
    D_800D62D0[idx].unk4 = value;
}
void func_80040780(s32 idx) {
    DiceBlockWork* work = &D_800D62D0[idx];
    omObjData* obj;
    s32 i;
    s32 color;
    s32 frame;
    s32 r;

    if (work->unkC != -1) {
        return;
    }
    func_800405DC(idx);
    if (work->unk4 != -1) {
        work->unk5 = work->unk4;
        work->unk4 = -1;
    } else {
        work->unk5 = 0;
        if (D_800D63E2 == 0 && GwSystem.curBoardIndex != 8 && _CheckFlag(0x2C) == 0) {
            r = rand8() & 0x1F;
            if (r == 0 && _CheckFlag(7) != 0) {
                work->unk5 = 1;
                D_800F3298++;
                func_800503B0(idx, 1);
            } else if (r == 1 && _CheckFlag(8) != 0) {
                work->unk5 = 2;
                D_800F3180++;
                func_800503B0(idx, 1);
            } else if (r == 2 && _CheckFlag(9) != 0) {
                work->unk5 = 3;
                D_800ECC20++;
                func_800503B0(idx, 1);
            } else if (r == 3 && _CheckFlag(10) != 0) {
                work->unk5 = 4;
                D_800ED3C0++;
                func_800503B0(idx, 1);
            } else if (r == 4 && _CheckFlag(11) != 0 && func_8004606C() != 0) {
                work->unk5 = 5;
                D_800F65D8++;
                func_800503B0(idx, 1);
            }
        }
    }
    work->unkC = LoadFormBinary(DataRead(D_800C4C40[work->unk5]), 0x6A9);
    func_80025F10(work->unkC, 1);
    func_80025830(work->unkC, 0.0f, 0.0f, 0.0f);
    func_80025930(work->unkC, 0x20000, 0x20000);
    if (work->unk5 != 5) {
        work->unk24 = DataRead(D_800C4C58[work->unk5]);
        work->unk10[0] = func_80038A9C(D_800F2B7C[work->unkC].unk_6C, work->unk24, 0, "tile01_DEF");
        work->unk10[1] = func_80038D5C(D_800F2B7C[work->unkC].unk_6C, work->unk10[0], 0, "tile02_DEF");
        work->unk10[2] = func_80038D5C(D_800F2B7C[work->unkC].unk_6C, work->unk10[0], 0, "tile03_DEF");
        work->unk10[3] = func_80038D5C(D_800F2B7C[work->unkC].unk_6C, work->unk10[0], 0, "tile04_DEF");
        work->unk10[4] = func_80038D5C(D_800F2B7C[work->unkC].unk_6C, work->unk10[0], 0, "tile06_DEF");
        work->unk10[5] = func_80038D5C(D_800F2B7C[work->unkC].unk_6C, work->unk10[0], 0, "tile10_DEF");
        frame = (u8)(rand8() % 10);
        color = rand8() & 3;
        for (i = 0; i < 6; i++) {
            switch (work->unk5) {
            case 0:
            case 1:
            case 2:
                func_8003967C(work->unk10[i], color);
                break;
            }
            func_800396B0(work->unk10[i], frame);
        }
    } else {
        work->unk24 = NULL;
        for (i = 0; i < 6; i++) {
            work->unk10[i] = -1;
        }
        func_80025EB4(work->unkC, 0, 2);
    }
    func_80025AD4(work->unkC);
    func_80026040(work->unkC);
    obj = omAddObj(0x8000, 1, 1, -1, func_8003F400);
    work->unk2C = obj;
    obj->model[0] = work->unkC;
    omSetStatBit(obj, 0xA0);
    obj->trans.x = GwPlayer[idx].player_obj->coords.x;
    obj->trans.y = GwPlayer[idx].player_obj->coords.y + D_800D63E4;
    obj->trans.z = GwPlayer[idx].player_obj->coords.z;
    obj->rot.y = -90.0f;
    obj->rot.x = obj->rot.z = 0.0f;
    obj->scale.z = obj->scale.y = obj->scale.x = 0.0f;
    obj->work[0] = 0;
    obj->work[1] = 135;
    obj->work[2] = 0;
    obj->work[3] = idx;
    work->unk40 = 1.0f;
    work->unk38 = 0.0f;
    work->unk3C = 1.0f;
    D_800D63E1 = 0;
    switch (work->unk5) {
    case 0:
        if (D_800D63E1 == 4) {
            PlaySound(0x7F);
        } else {
            PlaySound(0x34);
        }
        break;
    case 1:
        PlaySound(0x7D);
        break;
    case 2:
        PlaySound(0x7E);
        break;
    case 3:
        PlaySound(0x7B);
        break;
    case 4:
        PlaySound(0x7C);
        break;
    case 5:
        PlaySound(0x7A);
        break;
    default:
        PlaySound(0x6A);
        break;
    }
}
void func_80040D9C(s32 idx, s32 file, s32 tileFile, char** names) {
    DiceBlockWork* work = &D_800D62D0[idx];
    omObjData* obj;
    s32 i;

    if (work->unkC != -1) {
        return;
    }
    D_800D63E4 = 250;
    func_800405DC(idx);
    work->unk5 = 0;
    work->unkC = LoadFormBinary(DataRead(file), 0x6A9);
    func_80025F10(work->unkC, 1);
    func_80025830(work->unkC, 0.0f, 0.0f, 0.0f);
    func_80025930(work->unkC, 0x20000, 0x20000);
    if (tileFile != -1) {
        work->unk24 = DataRead(tileFile);
    } else {
        work->unk24 = NULL;
    }
    for (i = 0; i < 6; i++) {
        if (names[i] != NULL) {
            if (i == 0) {
                work->unk10[0] = func_80038A9C(D_800F2B7C[work->unkC].unk_6C, work->unk24, 0, names[0]);
            } else {
                // retail always stores to unk10[1]
                work->unk10[1] = func_80038D5C(D_800F2B7C[work->unkC].unk_6C, work->unk10[0], 0, names[i]);
            }
        } else {
            work->unk10[i] = -1;
        }
    }
    func_80025AD4(work->unkC);
    func_80026040(work->unkC);
    obj = omAddObj(0x8000, 1, 1, -1, func_8003F400);
    work->unk2C = obj;
    obj->model[0] = work->unkC;
    omSetStatBit(obj, 0xA0);
    obj->trans.x = GwPlayer[idx].player_obj->coords.x;
    obj->trans.y = GwPlayer[idx].player_obj->coords.y + D_800D63E4;
    obj->trans.z = GwPlayer[idx].player_obj->coords.z;
    obj->rot.y = -90.0f;
    obj->rot.x = obj->rot.z = 0.0f;
    obj->scale.z = obj->scale.y = obj->scale.x = 0.0f;
    obj->work[0] = 0;
    obj->work[1] = 135;
    obj->work[2] = 0;
    obj->work[3] = idx;
    work->unk40 = 1.0f;
    work->unk38 = 0.0f;
    work->unk3C = 1.0f;
    PlaySound(0x6A);
}
void func_80041048(s32 idx, s32 kind) {
    char* names[6] = { "donkeyxi_DEF", "starxi_DEF", NULL, NULL, NULL, NULL };
    s32 files[2] = { 0xA012C, 0xA012D };

    func_80040D9C(idx, 0xA012B, files[kind], names);
    D_800D63E1 = 2;
    D_800D63E0 = kind;
}
void func_800410E8(s32 idx) {
    char* names[6] = { "donkeyxi_DEF", "starxi_DEF", NULL, NULL, NULL, NULL };

    func_80040D9C(idx, 0xA012B, 0xA012E, names);
    D_800D63E1 = 5;
}
void func_80041158(s32 idx) {
    char* names[6] = { "starxi_DEF", NULL, NULL, NULL, NULL, NULL };

    func_80040D9C(idx, 0xA0002, 0xA000A, names);
    D_800D63E1 = 3;
}
void func_800411C8(s32 idx) {
    char* names[6] = { NULL, NULL, NULL, NULL, NULL, NULL };

    func_80040D9C(idx, 0xA0003, -1, names);
    D_800D63E1 = 4;
    func_800503B0(idx, 1);
}
void func_80041250(s32 idx) {
    DiceBlockWork* work = &D_800D62D0[idx];
    s32 i;

    if (work->unkC != -1) {
        func_8002456C(work->unkC);
        for (i = 0; i < 6; i++) {
            if (work->unk10[i] != -1) {
                func_80039ACC(work->unk10[i]);
            }
        }
        if (work->unk24 != NULL) {
            DataClose(work->unk24);
        }
        omDelObj(work->unk2C);
        work->unk2C = NULL;
        work->unkC = -1;
    }
    if (work->unkE != -1) {
        func_8002456C(work->unkE);
        work->unkE = -1;
        if (work->unk30 != NULL) {
            omDelObj(work->unk30);
            work->unk30 = NULL;
        }
    }
    if (work->unk1C != -1) {
        func_80039ACC(work->unk1C);
        work->unk1C = -1;
    }
    if (work->unk28 != NULL) {
        DataClose(work->unk28);
        work->unk28 = NULL;
    }
}
void func_80041370(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_80041250(i);
        func_800405DC(i);
    }
}
void func_800413B0(s32 idx) {
    DiceBlockWork* work = &D_800D62D0[idx];
    s32 value;
    s32 i;

    if (work->unkC == -1) {
        return;
    }
    work->unk2C->work[0] = 2;
    func_8004017C(idx);
    value = work->unk3;
    switch (work->unk5) {
    case 1:
        ShowPlayerCoinChange(idx, value);
        func_80055960(idx, value);
        break;
    case 2:
        value = -value;
        ShowPlayerCoinChange(idx, value);
        func_80055960(idx, value);
        func_800503B0(idx, 3);
        break;
    }
    if (D_800D63E1 == 1) {
        value = 0;
        for (i = 0; i < 4; i++) {
            value += D_800D62D0[i].unk1E != -1;
        }
    } else {
        value = 1;
    }
    if (value == 1) {
        func_8006071C(work->unk1E);
    }
    work->unk1E = -1;
    work->unk20 = 0;
    switch (D_800D63E1) {
    case 4:
        PlaySound(0x5D);
        break;
    case 3:
        if (func_80041644(idx) == 0) {
            PlaySound(0x100);
        } else {
            PlaySound(0xFF);
        }
        break;
    case 2:
        if (func_80041604(idx) == 0) {
            PlaySound(0x100);
        } else {
            PlaySound(0xFF);
        }
        break;
    default:
        if (work->unk5 == 5) {
            PlaySound(0x5D);
        } else {
            PlaySound(0x35);
        }
        break;
    }
}
void func_8004157C(void) {
    D_800D63E1 = 1;
}
s32 func_8004158C(s32 idx) {
    return D_800D62D0[idx].unkC != -1;
}
void func_800415B0(s32 idx, s8 value) {
    D_800D62D0[idx].unk3 = value;
}
void func_800415CC(s32 idx, s32 value) {
    D_800D62D0[idx].unk2 = value;
}
s32 func_800415E8(s32 idx) {
    return D_800D62D0[idx].unk3;
}
s32 func_80041604(s32 idx) {
    return D_800D62D0[idx].unk0 - 1;
}
s32 func_80041624(s32 idx) {
    return D_800D62D0[idx].unk0 - 8;
}
s32 func_80041644(s32 idx) {
    return D_800D62D0[idx].unk1 - 3;
}
s32 func_80041664(s32 idx) {
    return D_800D62D0[idx].unk1 - 5;
}
void func_80041684(void) {
    DiceProcWork* work = HuPrcCurrentGet()->user_data;

    while (TRUE) {
        switch (work->state) {
        case 0:
            func_80047694(work->player);
            work->state++;
            break;
        case 1:
            if (func_80047B68() == 0) {
                HuPrcSleep(5);
                work->state++;
            }
            if ((GwPlayer[work->player].flags & 1) || (ContBtnTrg[GwPlayer[work->player].port] & 0x8000)) {
                func_800471FC();
            }
            break;
        case 2:
            EndProcess(NULL);
            break;
        }
        HuPrcVSleep();
    }
}
void func_800417B4(void) {
    DiceProcWork* work = HuPrcCurrentGet()->user_data;
    s32 timer = 0;

    while (TRUE) {
        switch (work->state) {
        case 0:
            D_800D63E2 = 0;
            func_80040780(work->player);
            D_800D63E2 = 1;
            work->state++;
            HuPrcSleep(20);
            break;
        case 1:
            if ((GwPlayer[work->player].flags & 1) || (ContBtnTrg[GwPlayer[work->player].port] & 0x8000)) {
                work->state++;
                SetPlayerAnimation(work->player, 2, 0);
                func_8004F00C(GwPlayer[work->player].player_obj, 20.0f, -3.0f);
                D_800EE320 = 0;
            }
            break;
        case 2:
            if (++timer >= 5) {
                func_800413B0(work->player);
                func_80052C44(work->player, -1, 0, 10, 2);
                work->state++;
            }
            break;
        case 3:
            HuPrcSleep(20);
            EndProcess(NULL);
            break;
        }
        HuPrcVSleep();
    }
}
Process* func_80041978(s32 player) {
    Process* process = omAddPrcObj(func_80041684, 0, 0, 0x40);
    DiceProcWork* work = HuMemMemoryAlloc(process->heap, 0x10);

    process->user_data = work;
    work->player = player;
    work->state = 0;
    return process;
}
Process* func_800419D8(s32 player) {
    Process* process = omAddPrcObj(func_800417B4, 0, 0, 0x40);
    DiceProcWork* work = HuMemMemoryAlloc(process->heap, 0x10);

    process->user_data = work;
    work->player = player;
    work->state = 0;
    return process;
}
void func_80041A38(void) {
    DiceProcWork* work = HuPrcCurrentGet()->user_data;
    s32 timer = 0;

    while (TRUE) {
        switch (work->state) {
        case 0:
            D_800D63E2 = 0;
            func_80041158(work->player);
            D_800D63E2 = 1;
            work->state++;
            HuPrcSleep(20);
            break;
        case 1:
            if ((GwPlayer[work->player].flags & 1) || (ContBtnTrg[GwPlayer[work->player].port] & 0x8000)) {
                work->state++;
                SetPlayerAnimation(work->player, 2, 0);
                func_8004F00C(GwPlayer[work->player].player_obj, 20.0f, -3.0f);
                D_800EE320 = 0;
            }
            break;
        case 2:
            if (++timer >= 5) {
                func_800413B0(work->player);
                func_80052C44(work->player, -1, 0, 10, 2);
                work->state++;
            }
            break;
        case 3:
            HuPrcSleep(5);
            HuPrcSleep(15);
            EndProcess(NULL);
            break;
        }
        HuPrcVSleep();
    }
}
Process* func_80041C04(s32 player) {
    Process* process = omAddPrcObj(func_80041A38, 0, 0, 0x40);
    DiceProcWork* work = HuMemMemoryAlloc(process->heap, 0x10);

    process->user_data = work;
    work->player = player;
    work->state = 0;
    return process;
}
void func_80041C64(void) {
    s32 timer = 0;
    DiceProcWork* work = HuPrcCurrentGet()->user_data;
    f32 y;

    while (TRUE) {
        switch (work->state) {
        case 0:
            D_800D63E2 = 0;
            func_800411C8(work->player);
            D_800D63E2 = 1;
            work->state++;
            HuPrcSleep(20);
            break;
        case 1:
            if ((GwPlayer[work->player].flags & 1) || (ContBtnTrg[GwPlayer[work->player].port] & 0x8000)) {
                work->state++;
                SetPlayerAnimation(work->player, 2, 0);
                func_8004F00C(GwPlayer[work->player].player_obj, 20.0f, -3.0f);
                D_800EE320 = 0;
            }
            break;
        case 2:
            if (++timer >= 5) {
                func_800413B0(work->player);
                func_80052C44(work->player, -1, 0, 10, 2);
                work->state++;
            }
            break;
        case 3:
            HuPrcSleep(20);
            switch (func_80041664(work->player)) {
            case 0:
                PlaySound(0x81);
                break;
            case 1:
                PlaySound(0x83);
                break;
            case 2:
                PlaySound(0x82);
                break;
            }
            for (y = 0.0f; -D_800D63E4 < y; y -= 10.0f) {
                D_800D62D0[work->player].unk34->scale.x -= 0.05;
                D_800D62D0[work->player].unk34->trans.y = y;
                HuPrcVSleep();
            }
            func_800405DC(work->player);
            EndProcess(NULL);
            break;
        }
        HuPrcVSleep();
    }
}
Process* func_80041F24(s32 player) {
    Process* process = omAddPrcObj(func_80041C64, 0, 0, 0x40);
    DiceProcWork* work = HuMemMemoryAlloc(process->heap, 0x10);

    process->user_data = work;
    work->player = player;
    work->state = 0;
    return process;
}
void func_80041F84(s32 idx) {
    DiceBlockWork* work = &D_800D62D0[idx];

    if (work->unk1E != -1) {
        func_8006071C(work->unk1E);
        work->unk1E = -1;
    }
    work->unk20 = 1;
}
void func_80041FE0(s32 idx) {
    DiceBlockWork* work = &D_800D62D0[idx];
    s32 sound;

    if (work->unk20 == 1 && work->unkC != -1 && work->unk2C != NULL && work->unk2C->work[0] != 2) {
        if (D_800D63E1 == 3) {
            sound = 0x4F;
            goto play;
        }
        if (work->unk5 != 5 && D_800D63E1 != 4) {
            sound = 0x2D;
        play:
            work->unk1E = PlaySound(sound);
        }
    }
    work->unk20 = 0;
}