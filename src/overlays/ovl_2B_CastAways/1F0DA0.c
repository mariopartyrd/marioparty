#include "CastAways.h"

extern u16 D_800FB9B0_CastAways[][3];
extern u16 D_800FB9C4_CastAways[];

/* Hook object: flies out on the cast, sinks, catches a fish it touches, and is reeled back in. */


/* End of the game: freeze the fish, put the rods away, turn the players round, then the result. */


/* Player object: reads the stick (or the CPU), sets the cast power, casts and reels. */


extern char D_800FBA80_CastAways[];

/* Player object setup: seat, models, rod object, line sprites, motions, CPU tuning. */


/* Fish/item object: swims across the screen, then is hooked and flies to the player. */


extern u16 D_800FB99C_CastAways[];
extern f32 D_800FB9F4_CastAways[];
extern u8 D_800FB9E8_CastAways[][3];

/* CPU input: picks a spawner whose next item the cast would reach, then waits and reels. */


/* Lets the fishing line sag: lowers every sample by drop and clamps it to the water or rod line. */


extern u16 D_800FBA06_CastAways;
extern u16 D_800FBA08_CastAways;


extern u8 D_800FBA0C_CastAways[][3];
extern u8 D_800FBA18_CastAways[][3];




extern u8 D_800F64F8;

/* .data (1F60F0), in address order. */
extern char D_800FBA40_CastAways[];
extern char D_800FBA58_CastAways[];

/* Player seat positions. */
Vec D_800FB930_CastAways[4] = {
    { -300.0f, 77.0f, 2700.0f },
    { -100.0f, 77.0f, 2620.0f },
    { 100.0f, 77.0f, 2590.0f },
    { 300.0f, 77.0f, 2590.0f },
};
CastAwaysItemSetDef D_800FB960_CastAways[3] = {
    { 30, 6, -8.0f, 1700.0f, 1800.0f, 33, { 0 } },
    { 25, 8, 11.999999046325684f, -1800.0f, 1050.0f, 56, { 0 } },
    { 70, 4, -16.0f, 2000.0f, 300.0f, 80, { 0 } },
};
u16 D_800FB99C_CastAways[4] = { 45, 45, 45, 0 };
s32 D_800FB9A4_CastAways[3] = { 0x21, 0x37, 0x23 };
/* Reel steps per spawner and item type. */
u16 D_800FB9B0_CastAways[3][3] = {
    { 4, 5, 6 },
    { 8, 9, 11 },
    { 11, 13, 15 },
};
u16 D_800FB9C4_CastAways[8] = { 4, 7, 10, 0, 0, 0, 0, 0 };
char* D_800FB9D4_CastAways = D_800FBA58_CastAways;
char* D_800FB9D8_CastAways[2] = { D_800FBA40_CastAways, NULL };
s32 D_800FB9E0_CastAways = 0;
u16 D_800FB9E4_CastAways = 0;
/* CPU hold-off chance (percent) per difficulty and item type. */
u8 D_800FB9E8_CastAways[4][3] = {
    { 30, 60, 95 },
    { 20, 50, 70 },
    { 10, 20, 40 },
    { 5, 10, 15 },
};
f32 D_800FB9F4_CastAways[3] = { 10.0f, 20.0f, 30.0f };
u8 D_800FBA00_CastAways[4] = { 0, 0, 0, 0 };
u8 D_800FBA04_CastAways = 0;
u16 D_800FBA06_CastAways = 120;
u16 D_800FBA08_CastAways = 55;
/* Item-type weights (out of 10) and the types they select, per spawner. */
u8 D_800FBA0C_CastAways[4][3] = {
    { 1, 2, 7 },
    { 2, 3, 5 },
    { 2, 3, 5 },
    { 0, 0, 0 },
};
u8 D_800FBA18_CastAways[4][3] = {
    { 2, 1, 0 },
    { 2, 0, 1 },
    { 0, 1, 2 },
    { 0, 0, 0 },
};
f32 D_800FBA24_CastAways[3] = { 10.0f, 20.0f, 30.0f };
extern char D_800FBA64_CastAways[];
extern char D_800FBA70_CastAways[];
void func_80027E48(s16, f32, f32, u16, u16, char*, u8);

void func_800F65E0_CastAways(void) {
    s32 i;
    void* filePtr;

    omInitObjMan(0x35, 0);
    func_80060088();
    func_80029090(1);
    func_8001DE70(0x64);
    func_8002890C(0x21, 0x42, 0xD6);
    func_800178A0(1);
    D_800FBB80_CastAways.x = 0;
    D_800FBB80_CastAways.y = 3072.0f;
    D_800FBB80_CastAways.z = -200.0f;
    D_800FBB70_CastAways.x = 0;
    D_800FBB70_CastAways.y = 0;
    D_800FBB70_CastAways.z = -300.0f;
    D_800FBB9C_CastAways[0].x = 0;
    D_800FBB9C_CastAways[0].y = 1.0f;
    D_800FBB9C_CastAways[0].z = 0;
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, &func_800FB884_CastAways), 0xA0);
    func_80023448(3);
    func_800234B8(0, 0x78, 0x78, 0x78);
    func_800234B8(1, 0x40, 0x40, 0x60);
    func_80023504(1, -100.0f, 100.0f, 100.0f);
    func_800234B8(2, 0, 0, 0);
    func_80023504(2, -100.0f, 100.0f, 100.0f);
    func_800234B8(3, 0, 0, 0);
    func_80023504(3, -100.0f, 100.0f, 100.0f);
    func_8005D98C(0, 0xA);
    func_8005D98C(1, 0xC);
    func_8005D98C(2, 0xA);
    func_8005D98C(4, 4);
    omAddObj(0x64, 0, 0, -1, &func_800F7014_CastAways);
    omAddObj(0, 0, 0, -1, &func_800F704C_CastAways);
    omSetStatBit(omAddObj(4, 4, 0, -1, &func_800F71AC_CastAways), 0xA0);
    D_800FBB48_CastAways[0] = omAddObj(6, 0, 0, -1, &func_800F761C_CastAways);
    D_800FBB48_CastAways[1] = omAddObj(6, 0, 0, -1, &func_800F7650_CastAways);
    D_800FBB48_CastAways[2] = omAddObj(6, 0, 0, -1, &func_800F7684_CastAways);
    omAddObj(8, 5, 0xF, 4, &func_800F8AAC_CastAways);
    omAddObj(8, 5, 0xF, 4, &func_800F8AC8_CastAways);
    omAddObj(8, 5, 0xF, 4, &func_800F8AE4_CastAways);
    omAddObj(8, 5, 0xF, 4, &func_800F8B00_CastAways);
    omAddObj(0x2710, 0, 0, -1, &func_800FACA8_CastAways);

    for (i = 0; i < 2; i++) {
        filePtr = DataRead(D_800FB9A4_CastAways[i]);
        D_800FBB04_CastAways[i] = func_80039084(filePtr);
        HuMemDirectFree(filePtr);
    }

    D_800FBB46_CastAways = LoadFormFile(0x35, 0x2009D);
    filePtr = DataRead(0x2A);
    D_800FBB40_CastAways = func_80039084(filePtr);
    HuMemDirectFree(filePtr);
    filePtr = DataRead(0x25);
    D_800FBB42_CastAways = func_80039084(filePtr);
    HuMemDirectFree(filePtr);
    filePtr = DataRead(0x24);
    D_800FBB44_CastAways = func_80039084(filePtr);
    HuMemDirectFree(filePtr);
    D_800FBB56_CastAways = _CheckFlag(0x2B);
    SetFadeInTypeAndTime(0, 0x10);
    D_800FBB98_CastAways = 0;
}

// register allocation and loop layout
#ifdef NON_MATCHING
void func_800F6A24_CastAways(omObjData* arg0, s8* stickX, s8* stickY, s8* button) {
    CastAwaysPlayerWork* work;
    omObjData* rodObj;
    omObjData** fish;
    CastAwaysFishWork* fishWork;
    u16 set;
    s32 tries;
    s32 i;
    f32 reach;
    f32 fishY;
    f32 fishZ;

    work = arg0->unk_50;
    switch (work->state) {
    case 1:
        rodObj = work->rodObj;
        *stickY = 0;
        *stickX = 0;
        set = rand8() % 3;
        if (!(work->unk_150 < 2.0f)) {
            func_8009B618((f32)rand8(), work->unk_150 + 1.0f);
        }
        for (tries = 0; tries < 3; tries++) {
            reach = ((f32)D_800FB99C_CastAways[set] + (D_800FB9F4_CastAways[set] + 5.0f + 0.0f))
                  * D_800FB960_CastAways[set].speed;
            fish = func_8005DB44(set);
            *stickY = 0;
            *stickX = 0;
            for (i = 0; i < D_800ED618[set].max; i++) {
                if (fish[i] == NULL) {
                    continue;
                }
                fishWork = fish[i]->unk_50;
                if (fishWork->state != 0) {
                    continue;
                }
                if (fishWork->type != 2) {
                    fishY = fish[i]->trans.y;
                    fishZ = fish[i]->trans.z;
                } else {
                    fishY = fish[i]->trans.y - 30.0f;
                    fishZ = fish[i]->trans.z - -150.0f;
                }
                if ((u16)func_800FB53C_CastAways(rodObj->trans.x, 0.0f, D_800FB960_CastAways[set].z, fishWork->type,
                                                 fish[i]->trans.x + reach, fishY, fishZ) == 1) {
                    if ((u8)(rand8() % 100) < D_800FB9E8_CastAways[GwPlayer[work->playerNo].cpu_difficulty][fishWork->type]) {
                        return;
                    }
                    *stickY = (f32)D_800FB960_CastAways[set].stickY - 5.0f;
                    work->targetSet = set;
                    work->unk_148 = 0;
                    return;
                }
                if ((f32)(u8)(rand8() % 20) < work->unk_150) {
                    *stickY = (f32)D_800FB960_CastAways[set].stickY - 5.0f;
                    work->targetSet = set;
                    work->unk_148 = 0;
                    return;
                }
            }
            set++;
            if (set >= 3) {
                set = 0;
            }
        }
        break;
    case 2:
        if (work->unk_154 <= (f32)(u8)(rand8() % 100)) {
            *stickY = 0;
            *stickX = 0;
            arg0->work[3] = rand8() % 12 + 4;
            work->unk_148 = arg0->work[3];
            if (arg0->work[3] - 4 > 0 && (work->flags & 2)) {
                func_8006071C(work->sound);
                work->flags &= ~2;
            }
        } else {
            *stickX = 0;
            *stickY = (f32)D_800FB960_CastAways[work->targetSet].stickY - 5.0f;
        }
        break;
    case 4:
    case 8:
        *stickY = 0;
        *stickX = 0;
        if (--arg0->work[3] == 0) {
            *button = 1;
            arg0->work[3] = rand8() % 18 + 2;
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F0DA0", func_800F6A24_CastAways);
#endif
void func_800F7014_CastAways(void) {
    s32 i;
    for (i = 0; i < D_800F3778; i++) {}
}

void func_800F704C_CastAways(omObjData* arg0) {
    D_800FBB7C_CastAways = 0;
    D_800FBB58_CastAways = 60;
    D_800FBB5A_CastAways = 30;
    D_800FBB64_CastAways = D_800FBB68_CastAways = 0.0f;
    D_800FBB54_CastAways = 0;
    D_800FBB6C_CastAways = PlaySound(0x1AA);
    arg0->func_ptr = &func_800F70C4_CastAways;
}

void func_800F70C4_CastAways(void) {
    func_80079078(D_800FBB58_CastAways);
    switch (D_800FBB7C_CastAways) {
    case 0:
        func_800FA198_CastAways();
        return;
    case 1:
        D_800FBB5A_CastAways--;
        if (D_800FBB5A_CastAways == 0) {
            D_800FBB58_CastAways--;
            D_800FBB5A_CastAways = 30;
        }
        if (D_800FBB58_CastAways == 0) {
            D_800FBB7C_CastAways = 2;
            D_800FBB8C_CastAways = 0;
            func_800601D4(40);
            return;
        }
        return;
    case 2:
        func_800FA410_CastAways();
        break;
    }
}

void func_800F71AC_CastAways(omObjData* arg0) {
    s16 sprite;

    sprite = InitSprite(0x3F0002);
    D_800FBB5C_CastAways = sprite;
    D_800FBB5E_CastAways = func_80019060(sprite, 0, 1);
    func_80018D44(D_800FBB5E_CastAways, 0x4008);
    SetBasicSpritePos(D_800FBB5E_CastAways, 0xA0, 0x82);
    ShowBasicSprite(D_800FBB5E_CastAways);
    SetBasicSpriteSize(D_800FBB5E_CastAways, 2.0f, 2.0f);
    func_80017660(0, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    arg0->model[0] = LoadFormFile(0x3F0000, 0x499);
    arg0->model[3] = func_800174C0(0x3F0001, 0x1499);
    func_80039C48(D_800FBA64_CastAways, &D_800FBB60_CastAways);
    func_80026040(arg0->model[3]);
    arg0->func_ptr = &func_800F7308_CastAways;
}

void func_800F7308_CastAways(omObjData* arg0) {
    if (((func_8005FD5C() & 0xFFFF) + D_800F64F8) == 0) {
        D_800FBB64_CastAways += 0.4f;
    }
    func_80027E48(arg0->model[3], D_800FBB64_CastAways, D_800FBB68_CastAways,
        D_800FBB60_CastAways.unk_00, D_800FBB60_CastAways.unk_02,
        D_800FBA70_CastAways, 1);
}

// scheduling: the result store and one index multiply are ordered differently (masked 6)
#ifdef NON_MATCHING
void func_800F73AC_CastAways(omObjData* arg0, s32 arg1) {
    CastAwaysItemSet* set;
    unk_800ECDE0* sprite;
    s16 id;
    s32 i;

    arg0->unk_50 = set = func_80023684(sizeof(CastAwaysItemSet), 0x7918);
    set->id = arg1;
    set->interval = D_800FB960_CastAways[(u16)arg1].interval;
    set->count = D_800FB960_CastAways[(u16)arg1].count;
    set->speed = D_800FB960_CastAways[(u16)arg1].speed;
    set->spawned = 0;
    set->timer = rand8() % 20;
    set->x = D_800FB960_CastAways[(u16)arg1].x;
    set->y = -25.0f;
    set->z = D_800FB960_CastAways[(u16)arg1].z;
    set->angle = 0;
    for (i = 0; i < set->count; i++) {
        id = func_8001E00C((void*)-1, 0x68D, 8);
        sprite = D_800ECDE0 + id;
        sprite->unk_02 = D_800FBB04_CastAways[0];
        func_80025930(sprite->unk_00, 0x40000000, 0x40000000);
        set->models[0][i] = D_800ECDE0[id].unk_00;
        set->spriteIds[i] = id;
        set->slots[0][i] = 0;
    }
    for (i = 0; i < set->count; i++) {
        set->models[2][i] = func_80023FC8(D_800FBB46_CastAways);
        set->slots[2][i] = 0;
        func_80025830(set->models[2][i], 1.5f, 1.5f, 1.5f);
        func_80025EB4(set->models[2][i], 1, 1);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F0DA0", func_800F73AC_CastAways);
#endif
s32 func_800F75BC_CastAways(CastAwaysItemSet* arg0, s32 arg1) {
    s32 slotIndex;
    s32 pad[1]; // Original function has an otherwise-unused 8-byte stack frame.

    for (slotIndex = 0; slotIndex < arg0->count; slotIndex++) {
        u8* slots = (u8*)(((arg1 & 0xFF) * 8) + (u32)arg0 + 0x66);
        if (slots[slotIndex] == 0) {
            slots[slotIndex] = 1;
            return (s16)slotIndex;
        }
    }
    return -1;
}

void func_800F761C_CastAways(omObjData* arg0) {
    func_800F73AC_CastAways(arg0, 0);
    arg0->func_ptr = &func_800F76B8_CastAways;
}

void func_800F7650_CastAways(omObjData* arg0) {
    func_800F73AC_CastAways(arg0, 1);
    arg0->func_ptr = &func_800F76B8_CastAways;
}

void func_800F7684_CastAways(omObjData* arg0) {
    func_800F73AC_CastAways(arg0, 2);
    arg0->func_ptr = &func_800F76B8_CastAways;
}

// register allocation and block order of the switch arms (masked 27); retail keeps arg0 in $s2 and
// reuses it for the new fish object (masked 26 that way); tried a chained work store
#ifdef NON_MATCHING
void func_800F76B8_CastAways(omObjData* arg0) {
    CastAwaysItemSet* set;
    omObjData* fish;
    CastAwaysFishWork* work;
    s16 type;
    s16 slot;
    f32 angle;

    if (D_800FBB7C_CastAways != 2) {
        set = arg0->unk_50;
        if (set->timer == 0) {
            if (set->spawned != set->count) {
                set->timer = (u8)(rand8() % 20) + set->interval;
                fish = omAddObj(0xC, 1, 0, set->id, &func_800F7A38_CastAways);
                work = func_80023684(sizeof(CastAwaysFishWork), 0x7918);
                fish->unk_50 = work;
                type = func_800FABE4_CastAways(set->id);
                switch (type) {
                case 0:
                    slot = func_800F75BC_CastAways(set, 0);
                    D_800ECDE0[set->spriteIds[slot]].unk_02 = D_800FBB04_CastAways[0];
                    func_8001E268(set->spriteIds[slot], 1, 0);
                    func_8001E2A8(set->spriteIds[slot], 0);
                    fish->model[0] = set->models[0][slot];
                    omSetTra(fish, set->x, func_800AEAC0(set->angle) + set->y, set->z);
                    omSetSca(fish, 4.0f, 4.0f, 4.0f);
                    break;
                case 1:
                    slot = func_800F75BC_CastAways(set, 0);
                    D_800ECDE0[set->spriteIds[slot]].unk_02 = D_800FBB06_CastAways;
                    func_8001E268(set->spriteIds[slot], 1, 0);
                    func_8001E2A8(set->spriteIds[slot], 0);
                    fish->model[0] = set->models[0][slot];
                    omSetTra(fish, set->x, func_800AEAC0(set->angle) + set->y, set->z);
                    omSetSca(fish, 4.0f, 4.0f, 4.0f);
                    break;
                case 2:
                    slot = func_800F75BC_CastAways(set, type);
                    fish->model[0] = set->models[type][slot];
                    omSetTra(fish, set->x, func_800AEAC0(set->angle) + set->y + 30.0f, set->z + -150.0f);
                    omSetSca(fish, 1.5f, 1.5f, 1.5f);
                    break;
                }
                func_800258EC(fish->model[0], 4, 0);
                work->state = 0;
                work->type = type;
                work->slot = slot;
                work->set = set;
                work->speed = set->speed;
                work->angle = set->angle;
                set->spawned++;
            }
        } else {
            set->timer--;
        }
        angle = set->angle + 45.0f;
        set->angle = angle;
        if (angle >= 360.0f) {
            set->angle = angle - 360.0f;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F0DA0", func_800F76B8_CastAways);
#endif
// register allocation and block order
#ifdef NON_MATCHING
void func_800F7A38_CastAways(omObjData* arg0) {
    Vec3f pos;
    Vec2f scr;
    CastAwaysFishWork* work;
    CastAwaysItemSet* set;
    CastAwaysRodWork* rod;
    CastAwaysPlayerWork* player;
    omObjData* playerObj;
    s32 event;
    u8 offscreen;
    f32 angle;
    f32 dx, dy, dz;
    s16 model;
    s16 sound;

    offscreen = 0;
    if (D_800FBB7C_CastAways == 2) {
        return;
    }
    work = arg0->unk_50;
    set = work->set;
    event = arg0->unk_10;
    if (event != 0) {
        arg0->unk_10 = 0;
        switch (event) {
        case 1:
            rod = work->rodObj->unk_50;
            work->state = 1;
            switch (work->type) {
            case 0:
                func_8001E268(set->spriteIds[work->slot], 1, 1);
                func_8001E2A8(set->spriteIds[work->slot], 0);
                break;
            case 1:
                func_8001E268(set->spriteIds[work->slot], 1, 1);
                func_8001E2A8(set->spriteIds[work->slot], 0);
                func_80060F04(rod->playerNo, 2, 3, 10);
                break;
            case 2:
                func_80060F04(rod->playerNo, 20, 0, 20);
                break;
            }
            break;
        case 2:
            playerObj = ((CastAwaysRodWork*)work->rodObj->unk_50)->playerObj;
            player = playerObj->unk_50;
            work->state = 2;
            work->unk_10 = 0;
            dx = playerObj->trans.x - arg0->trans.x;
            dy = playerObj->trans.y - arg0->trans.y;
            dz = playerObj->trans.z - arg0->trans.z;
            work->dist = func_800B1750(dx * dx + dy * dy + dz * dz);
            work->start.x = arg0->trans.x;
            work->start.y = arg0->trans.y;
            work->start.z = arg0->trans.z;
            work->step.x = (playerObj->trans.x - arg0->trans.x) / 5.0f;
            if (work->type != 2) {
                work->step.y = ((playerObj->trans.y + 250.0f) - arg0->trans.y) / 5.0f;
            } else {
                work->step.y = ((playerObj->trans.y + 350.0f) - arg0->trans.y) / 5.0f;
            }
            work->step.z = (playerObj->trans.z - arg0->trans.z) / 5.0f;
            work->steps = 5;
            work->timer = 25;
            if (work->type != 2) {
                func_8001E268(set->spriteIds[work->slot], 1, 0);
            }
            switch (work->type) {
            case 1:
                GwPlayer[player->playerNo].coins_mg += 5;
                break;
            case 2:
                GwPlayer[player->playerNo].coins_mg += 10;
                break;
            default:
                GwPlayer[player->playerNo].coins_mg += 1;
                break;
            }
            break;
        }
    }
    switch (work->state) {
    case 0:
        angle = work->angle + 20.0f;
        work->angle = angle;
        if (angle >= 360.0f) {
            work->angle = angle - 360.0f;
        }
        pos.x = arg0->trans.x;
        pos.y = arg0->trans.y;
        pos.z = arg0->trans.z;
        pos.x += work->speed;
        pos.y += func_800AEAC0(work->angle);
        Convert3DTo2D(0, &pos, &scr);
        if (work->speed >= 0.0f ? scr.x >= 340.0f : scr.x <= -20.0f) {
            offscreen = 1;
        }
        if (!offscreen) {
            omSetTra(arg0, pos.x, pos.y, pos.z);
            return;
        }
        set->spawned--;
        func_800258EC(arg0->model[0], 4, 4);
        switch (work->type) {
        case 0:
        case 1:
            set->slots[0][work->slot] = 0;
            break;
        case 2:
            set->slots[2][work->slot] = 0;
            break;
        }
        omDelObj(arg0);
        break;
    case 1:
        playerObj = work->rodObj;
        if (work->type != 2) {
            omSetTra(arg0, arg0->trans.x, playerObj->trans.y, playerObj->trans.z - 40.0f);
            return;
        }
        omSetTra(arg0, arg0->trans.x, playerObj->trans.y, (playerObj->trans.z - 40.0f) + -150.0f);
        return;
    case 2:
        rod = work->rodObj->unk_50;
        player = rod->playerObj->unk_50;
        if (work->steps != 0) {
            omSetTra(arg0, arg0->trans.x + work->step.x, arg0->trans.y + work->step.y, arg0->trans.z + work->step.z);
            work->steps--;
        }
        if (--work->timer == 0) {
            set->spawned--;
            func_800258EC(arg0->model[0], 4, 4);
            switch (work->type) {
            case 0:
            case 1:
                set->slots[0][work->slot] = 0;
                break;
            case 2:
                set->slots[2][work->slot] = 0;
                break;
            }
            model = D_800FBB10_CastAways[rod->playerNo].model;
            func_80025798(model, arg0->trans.x, (work->type != 2) ? arg0->trans.y : arg0->trans.y - 100.0f,
                          arg0->trans.z);
            func_80025830(model, 8.0f, 8.0f, 8.0f);
            func_800258EC(model, 4, 0);
            func_8001E2A8(D_800FBB10_CastAways[rod->playerNo].id, 0);
            D_800FBB54_CastAways = 1;
            if (work->type == 1) {
                sound = 0x109;
            } else {
                sound = 0xFC;
                if (work->type == 2) {
                    sound = 0x196;
                }
            }
            player->sound = func_80060540(sound, player->playerNo);
            omDelObj(arg0);
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F0DA0", func_800F7A38_CastAways);
#endif
// register allocation
#ifdef NON_MATCHING
void func_800F8194_CastAways(omObjData* arg0, s32 arg1) {
    omObjData** players;
    CastAwaysPlayerWork* work;
    CastAwaysRodWork* rodWork;
    omObjData* rod;
    u8 seat;
    s32 i;
    s32 dir;
    s8 chr;
    s16 id;

    players = func_8005DB44(4);
    if (D_800FBA04_CastAways == 3) {
        for (i = 0; i < 4; i++) {
            if (D_800FBA00_CastAways[i] == 0) {
                seat = i;
                break;
            }
        }
    } else {
        do {
            seat = rand8() & 3;
        } while (D_800FBA00_CastAways[seat] != 0);
    }
    D_800FBA00_CastAways[seat] = 1;
    work = func_80023684(sizeof(CastAwaysPlayerWork), 0x7918);
    arg0->unk_50 = work;
    work->seat = seat;
    work->playerNo = arg1;
    work->state = 1;
    work->power = 0;
    work->lastPower = 0;
    work->repeat = 0;
    work->catches = 0;
    work->unk_140 = 0;
    work->lureObj = NULL;
    work->fishType = -1;
    work->unk_14C = 0;
    work->unk_14E = 0;
    for (i = 0; i < 4; i++) {
        arg0->work[i] = 0;
    }
    work->flags = 0;
    chr = GwPlayer[arg1].character;
    dir = D_800C59AC[chr].unk_00;
    arg0->model[0] = LoadFormFile(dir | D_800C59AC[chr].unk_04, 0x20699);
    omSetTra(arg0, D_800FB930_CastAways[seat].x, D_800FB930_CastAways[seat].y, D_800FB930_CastAways[seat].z);
    omSetRot(arg0, 0.0f, 180.0f, 0.0f);
    func_80025798(arg0->model[0], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    arg0->model[2] = LoadFormFile(0x3F0003, 0x499);
    arg0->model[3] = LoadFormFile(0x3F0004, 0x499);
    func_800258EC(arg0->model[2], 4, 4);
    func_8002859C(arg0->model[2], arg0->model[0], D_800FBA80_CastAways);
    arg0->motion[0xB] = arg0->model[3];
    func_8001775C(arg0, 8, 0x3F0005);
    func_8001775C(arg0, 9, 0x3F0006);
    func_8001775C(arg0, 0xA, 0x3F0007);
    work->savedSpeed[0] = D_800F2B7C[arg0->motion[8]].unk_08;
    work->savedSpeed[1] = D_800F2B7C[arg0->motion[9]].unk_08;
    work->savedSpeed[2] = D_800F2B7C[arg0->motion[0xA]].unk_08;
    work->savedSpeed[3] = D_800F2B7C[arg0->motion[0xB]].unk_08;
    func_800257E4(arg0->model[3], 0.0f, 180.0f, 0.0f);
    func_80025798(arg0->model[3], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_80025EB4(arg0->model[3], 1, 1);
    func_8001775C(arg0, 0, dir | 1);
    func_8001775C(arg0, 6, dir | 0x32);
    func_8001775C(arg0, 7, dir | 0x34);
    func_8001775C(arg0, 0xC, dir | 0xF);
    func_8001775C(arg0, 0xD, dir | 0x10);
    arg0->motion[0xE] = func_80028784(DataRead(dir), 0x18);

    rod = omAddObj(0xA, 1, 0, -1, &func_800F92FC_CastAways);
    rodWork = func_80023684(sizeof(CastAwaysRodWork), 0x7918);
    rod->unk_50 = rodWork;
    rodWork->playerObj = arg0;
    rodWork->playerNo = arg1;
    rodWork->fishObj = NULL;
    rodWork->state = 0;
    if (arg1 == 0) {
        rod->model[0] = LoadFormFile(0x3F0008, 0x899);
    } else {
        rod->model[0] = func_80023FC8(((CastAwaysPlayerWork*)players[0]->unk_50)->rodObj->model[0]);
    }
    func_8002859C(rod->model[0], arg0->model[3], D_800FB9D8_CastAways[0]);
    func_800258EC(rod->model[0], 0x4000, 0x4000);
    omSetTra(rod, arg0->trans.x, arg0->trans.y + 145.0f, arg0->trans.z);
    omSetRot(rod, 45.0f, 180.0f, 0.0f);
    work->rodObj = rod;
    work->sampleCount = 1;
    work->spriteData = func_800FAFF0_CastAways(0xFF, 0xFF, 0xFF);
    for (i = 0; i < work->sampleCount + 1; i++) {
        work->samples[i].x = arg0->trans.x;
        work->samples[i].y = arg0->trans.y + 145.0f;
        work->samples[i].z = arg0->trans.z;
    }

    arg0->model[1] = func_800174F4(6, 0x689);
    func_800370D4(arg0->model[1]);
    func_80025798(arg0->model[1], arg0->trans.x, arg0->trans.y, arg0->trans.z);
    func_80025930(arg0->model[1], 0x80000000, 0);
    func_80025AD4(arg0->model[1]);
    func_80025B34(arg0->model[1]);

    id = func_8001E00C((void*)-1, 0x1A8D, 8);
    D_800ECDE0[id].unk_02 = D_800FBB40_CastAways;
    func_80025930(D_800ECDE0[id].unk_00, 0x40000000, 0x40000000);
    D_800FBB10_CastAways[arg1].model = D_800ECDE0[id].unk_00;
    D_800FBB10_CastAways[arg1].id = id;
    func_8001E268(id, 4, 4);
    func_8001E2F8(id, 0xFF);
    func_8001E360(id, 0xFF, 0xFF, 0xBE);

    id = func_8001E00C((void*)-1, 0x1A8D, 8);
    D_800ECDE0[id].unk_02 = D_800FBB42_CastAways;
    func_80025930(D_800ECDE0[id].unk_00, 0x40000000, 0x40000000);
    D_800FBB20_CastAways[arg1].model = D_800ECDE0[id].unk_00;
    D_800FBB20_CastAways[arg1].id = id;
    func_8001E268(id, 4, 4);

    id = func_8001E00C((void*)-1, 0x1A8D, 8);
    D_800ECDE0[id].unk_02 = D_800FBB44_CastAways;
    func_80025930(D_800ECDE0[id].unk_00, 0x40000000, 0x40000000);
    D_800FBB30_CastAways[arg1].model = D_800ECDE0[id].unk_00;
    D_800FBB30_CastAways[arg1].id = id;
    func_8001E268(id, 4, 4);

    func_8001775C(arg0, 1, dir | 0x30);
    func_8001775C(arg0, 2, dir | 0x9C);
    func_8001775C(arg0, 3, dir | 0x9B);
    func_8001775C(arg0, 4, dir | 0x9A);
    func_8001775C(arg0, 5, dir | 0x31);
    func_80025BB8(arg0->model[0], arg0->motion[1]);
    work->animDataA = func_800202E8(arg0->model[0], 2);
    func_80025BB8(arg0->model[0], arg0->motion[5]);
    work->animDataB = func_800202E8(arg0->model[0], 2);
    func_80020958(arg0->model[0], work->animDataA, 0);
    func_8002456C(arg0->motion[1]);
    func_8002456C(arg0->motion[5]);
    switch (GwPlayer[arg1].cpu_difficulty) {
    case 0:
        work->unk_150 = 10.0f;
        work->unk_154 = 30.0f;
        break;
    case 1:
        work->unk_150 = 6.0f;
        work->unk_154 = 20.0f;
        break;
    case 2:
        work->unk_150 = 4.0f;
        work->unk_154 = 10.0f;
        break;
    case 3:
        work->unk_150 = 0.0f;
        work->unk_154 = 5.0f;
        break;
    }
    arg0->func_ptr = &func_800F8B1C_CastAways;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F0DA0", func_800F8194_CastAways);
#endif
void func_800F8AAC_CastAways(omObjData* arg0) {
    func_800F8194_CastAways(arg0, 0);
}

void func_800F8AC8_CastAways(omObjData* arg0) {
    func_800F8194_CastAways(arg0, 1);
}

void func_800F8AE4_CastAways(omObjData* arg0) {
    func_800F8194_CastAways(arg0, 2);
}

void func_800F8B00_CastAways(omObjData* arg0) {
    func_800F8194_CastAways(arg0, 3);
}

// register allocation and branch layout
#ifdef NON_MATCHING
void func_800F8B1C_CastAways(omObjData* arg0) {
    s8 stick[2];
    s8 button;
    CastAwaysPlayerWork* work;
    CastAwaysRodWork* rod;
    s32 event;
    u8 port;
    s16 r;
    s16 power;
    f32 frame;

    button = 0;
    if (D_800FBB7C_CastAways != 1) {
        return;
    }
    work = arg0->unk_50;
    rod = work->rodObj->unk_50;
    port = GwPlayer[work->playerNo].port;
    event = arg0->unk_10;
    if (event != 0) {
        arg0->unk_10 = 0;
        if (event == D_800FBB7C_CastAways) {
            work->state = 0x10;
            work->motionIdx = 7;
            work->flags &= ~1;
        } else if (event == 2) {
            work->state = 0x10;
            work->flags &= ~1;
            work->motionIdx = 6;
            work->catches++;
        }
    }
    if (work->state == 0x10) {
        D_800F2B7C[arg0->motion[0xB]].unk_08 = work->savedSpeed[3];
        if (work->lureObj != NULL) {
            omDelObj(work->lureObj);
            work->lureObj = NULL;
        }
        work->state = 0x20;
        work->repeat = 0;
        work->lastPower = 0;
        work->power = 0;
        func_800258EC(arg0->model[2], 4, 0);
        func_800258EC(arg0->model[3], 4, 4);
        func_8002859C(work->rodObj->model[0], arg0->model[2], D_800FB9D4_CastAways);
        func_800258EC(work->rodObj->model[0], 0x4000, 0x4000);
        func_80025BB8(arg0->model[0], arg0->motion[work->motionIdx]);
        func_80025EB4(arg0->model[0], 1, 0);
        func_800258EC(arg0->model[2], 0x4000, 0x4000);
    }
    if (work->state == 0x20) {
        frame = func_80025D18(arg0->model[0]);
        if (func_80025D40(arg0->model[0]) <= frame) {
            work->state = 1;
            func_80020958(arg0->model[0], work->animDataA, 0);
            func_80025EB4(arg0->model[0], 3, 3);
            func_800258EC(arg0->model[2], 4, 4);
            func_800258EC(arg0->model[2], 0x4000, 0);
            func_800258EC(arg0->model[3], 4, 0);
            func_8002859C(work->rodObj->model[0], arg0->model[3], D_800FB9D8_CastAways[0]);
            func_80025EB4(arg0->model[3], 1, 1);
            func_80025CA8(arg0->model[3], 0.0f);
        }
    }
    if (!(GwPlayer[work->playerNo].flags & 1)) {
        stick[0] = ContStkX[port];
        stick[1] = ContStkY[port];
        r = func_80009E4C(work->playerNo, 15, ContStkX[port], ContStkY[port]);
        if (r < 0) {
            r = -r;
        }
        if (r == 2) {
            button = 1;
            work->unk_148 = D_800F377A[work->playerNo];
        } else if (r == 0 && rod->state == 2 && work->state == 8 && (work->flags & 2)) {
            func_8006071C(work->sound);
            work->flags &= ~2;
        }
    } else {
        func_800F6A24_CastAways(arg0, &stick[0], &stick[1], &button);
    }
    power = func_800FB404_CastAways(stick[0], stick[1]);
    if (power != 0) {
        if ((u16)(work->state - 1) < 2) {
            work->state = 2;
            if (work->power < power) {
                work->power = power;
            }
            if (power != work->lastPower) {
                work->repeat = 0;
            } else if (++work->repeat == 2) {
                work->repeat = 0;
                work->power = power;
            }
            work->lastPower = power;
            func_800FAD2C_CastAways(arg0);
        }
    } else if (work->state == 2) {
        work->state = 4;
    }
    if (work->state == 4) {
        if (work->unk_14E == 0) {
            func_800FAD2C_CastAways(arg0);
        } else {
            work->state = 8;
        }
    }
    if (work->state == 8) {
        if (work->unk_14E == 1) {
            work->unk_14E = 0;
            work->lastPower = 0;
            work->castState = 1;
            rod = work->rodObj->unk_50;
            rod->timer = 3;
            rod->group = work->fishType;
            switch (work->fishType) {
            case 0:
                rod->targetZ = 1800.0f;
                rod->velY = -6.0f;
                D_800FBB00_CastAways = 0x311;
                break;
            case 1:
                rod->targetZ = 1050.0f;
                rod->velY = -7.0f;
                D_800FBB00_CastAways = 0x310;
                break;
            case 2:
                rod->targetZ = 300.0f;
                rod->velY = -8.0f;
                D_800FBB00_CastAways = 0x30F;
                break;
            }
            func_80025BB8(arg0->model[0], arg0->motion[work->fishType + 2]);
            func_80025BB8(arg0->model[3], arg0->motion[10 - work->fishType]);
            func_80025EB4(arg0->model[0], 1, 0);
            omDelObj(work->lureObj);
            work->lureObj = NULL;
            work->fishType = -1;
        }
        if (func_80025D18(arg0->model[0]) >= 10.0f && rod->state == 0) {
            if (!(work->flags & 1)) {
                work->sound = func_80060540(D_800FBB00_CastAways, work->playerNo);
                work->flags |= 1;
            }
            func_8005DC18(work->rodObj, 1);
            func_800258EC(work->rodObj->model[0], 0x4000, 0);
            omSetTra(work->rodObj, arg0->trans.x + 15.0f, arg0->trans.y + 145.0f, arg0->trans.z + -125.0f);
            for (event = 0; event < 2; event++) {
                work->samples[event].x = work->rodObj->trans.x;
                work->samples[event].y = work->rodObj->trans.y;
                work->samples[event].z = work->rodObj->trans.z;
            }
        }
    }
    if (button == 1) {
        func_8005DC18(work->rodObj, 2);
        if (rod->state == 2 && work->state == 8) {
            func_800FB668_CastAways(arg0, arg0->model[0], work->animDataB, 0.0f, 1.0f, rod->state, 5);
            if (!(work->flags & 2)) {
                work->sound = func_80060540(0x312, work->playerNo);
                work->flags |= 2;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F0DA0", func_800F8B1C_CastAways);
#endif
// register allocation and block order
#ifdef NON_MATCHING
void func_800F92FC_CastAways(omObjData* arg0) {
    CastAwaysRodWork* rod;
    CastAwaysPlayerWork* player;
    CastAwaysFishWork* fishWork;
    omObjData** fish;
    s32 event;
    u8 reel;
    s32 i;
    s16 model;
    f32 half;
    f32 y;
    f32 z;
    f32 fishY;
    f32 fishZ;
    f32 drop;
    u16 n;

    reel = 0;
    if (D_800FBB7C_CastAways != 1) {
        return;
    }
    rod = arg0->unk_50;
    player = rod->playerObj->unk_50;
    event = arg0->unk_10;
    if (event != 0) {
        arg0->unk_10 = 0;
        if (event == D_800FBB7C_CastAways) {
            if (rod->state == 0) {
                rod->state = 1;
                rod->counter = 0;
                half = fabsf(arg0->trans.z - rod->targetZ) / 2.0f;
                rod->startZ = arg0->trans.z;
                rod->startY = arg0->trans.y;
                rod->stepZ = fabsf((half + half) / 45.0f);
                rod->stepY = rod->velY;
                rod->gravity = fabsf((rod->velY + rod->velY) / 41.0f);
                func_800258EC(player->spriteData->model, 4, 0);
                player->sound = func_80060540(0x314, player->playerNo);
            }
        } else if (event == 2) {
            reel = 1;
        }
    }
    switch (rod->state) {
    case 1:
        z = arg0->trans.z - rod->stepZ;
        y = arg0->trans.y - fabs(rod->stepY) * rod->stepY;
        rod->stepY += rod->gravity;
        if (rod->stepY >= 0.0f) {
            player->castState = 2;
        }
        omSetTra(arg0, arg0->trans.x, y, z);
        if (++rod->counter == 45) {
            rod->state = 8;
        }
        func_800F9E2C_CastAways(arg0, player, rod);
        break;
    case 8:
        fish = func_8005DB44(rod->group);
        for (i = 0; i < D_800ED618[rod->group].max; i++) {
            if (fish[i] == NULL) {
                continue;
            }
            fishWork = fish[i]->unk_50;
            if (fishWork->type != 2) {
                fishY = fish[i]->trans.y;
                fishZ = fish[i]->trans.z;
            } else {
                fishY = fish[i]->trans.y - 30.0f;
                fishZ = fish[i]->trans.z - -150.0f;
            }
            if ((u16)func_800FB4D4_CastAways(arg0->trans.x, arg0->trans.y + 8.0f, arg0->trans.z, fishWork->type,
                                             fish[i]->trans.x, fishY, fishZ) != 1) {
                continue;
            }
            player->sound = func_80060540(0x315, player->playerNo);
            func_8005DC18(fish[i], 1);
            rod->fishObj = fish[i];
            ((CastAwaysFishWork*)fish[i]->unk_50)->rodObj = arg0;
            rod->state = 2;
            fishWork = rod->fishObj->unk_50;
            rod->steps = D_800FB9B0_CastAways[rod->group][fishWork->type];
            rod->stepZ = ((rod->startZ - arg0->trans.z) / (f32)rod->steps) / 5.0f;
            rod->stepY = ((rod->startY - arg0->trans.y) / (f32)rod->steps) / 5.0f;
            rod->slope = 0.0f;
            rod->baseZ = 0.0f;
            arg0->work[0] = 0;
            arg0->trans.y = 0.0f;
            model = D_800FBB20_CastAways[rod->playerNo].model;
            if (fishWork->type != 2) {
                func_80025798(model, fish[i]->trans.x, -80.0f, fish[i]->trans.z + 48.0f);
            } else {
                func_80025798(model, fish[i]->trans.x, -80.0f, fish[i]->trans.z + 48.0f + 50.0f);
            }
            func_80025830(model, 8.5f, 8.5f, 8.5f);
            func_800258EC(model, 4, 0);
            func_8001E2A8(D_800FBB20_CastAways[rod->playerNo].id, 0);
            break;
        }
        if (rod->state != 2) {
            z = arg0->trans.z - rod->stepZ;
            y = arg0->trans.y - fabs(rod->stepY) * rod->stepY;
            rod->stepY += rod->gravity;
            if (rod->stepY >= 0.0f) {
                player->castState = 2;
            }
            omSetTra(arg0, arg0->trans.x, y, z);
            rod->state = 0x10;
        }
        func_800F9E2C_CastAways(arg0, player, rod);
        break;
    case 0x10:
        if (arg0->trans.y < 0.0f) {
            player->sound = func_80060540(0x313, player->playerNo);
            model = D_800FBB20_CastAways[rod->playerNo].model;
            func_80025798(model, arg0->trans.x, -80.0f, arg0->trans.z + 32.0f);
            func_80025830(model, 8.5f, 8.5f, 8.5f);
            func_800258EC(model, 4, 0);
            func_8001E2A8(D_800FBB20_CastAways[rod->playerNo].id, 0);
            model = D_800FBB30_CastAways[rod->playerNo].model;
            func_80025798(model, arg0->trans.x, 0.0f, arg0->trans.z);
            func_80025830(model, 6.0f, 6.0f, 6.0f);
            func_800258EC(model, 4, 0);
            func_8001E2A8(D_800FBB30_CastAways[rod->playerNo].id, 0);
        }
        if (arg0->trans.y <= -100.0f) {
            omSetTra(arg0, arg0->trans.x, -100.0f, arg0->trans.z);
            player->samples[player->sampleCount].x = arg0->trans.x;
            player->samples[player->sampleCount].y = arg0->trans.y;
            player->samples[player->sampleCount].z = arg0->trans.z;
            rod->state = 2;
            rod->steps = D_800FB9C4_CastAways[rod->group];
            rod->stepZ = ((rod->startZ - arg0->trans.z) / (f32)rod->steps) / 5.0f;
            rod->stepY = ((rod->startY - arg0->trans.y) / (f32)rod->steps) / 5.0f;
            arg0->work[0] = 0;
            rod->baseZ = player->samples[4].z;
            rod->slope = arg0->trans.y / (arg0->trans.z - rod->baseZ);
            break;
        }
        z = arg0->trans.z - rod->stepZ;
        y = arg0->trans.y - fabs(rod->stepY) * rod->stepY;
        rod->stepY += rod->gravity;
        if (rod->stepY >= 0.0f) {
            player->castState = 2;
        }
        if (y < -100.0f) {
            y = -100.0f;
        }
        omSetTra(arg0, arg0->trans.x, y, z);
        func_800F9E2C_CastAways(arg0, player, rod);
        break;
    case 2:
        rod->counter = 0;
        rod->timer = 3;
        if (reel) {
            rod->state = 4;
        }
        break;
    }
    if (rod->state == 4) {
        if (reel) {
            func_80060440(player->sound, (0x38 - (s16)player->unk_148) * 42 - 1200);
        }
        if (player->castState == 4) {
            z = arg0->trans.z + rod->stepZ;
            if (player->sampleCount >= 4) {
                y = (z - rod->baseZ) * rod->slope;
            } else {
                y = arg0->trans.y;
            }
            omSetTra(arg0, arg0->trans.x, y, z);
            player->samples[player->sampleCount].x = arg0->trans.x;
            player->samples[player->sampleCount].y = arg0->trans.y;
            player->samples[player->sampleCount].z = arg0->trans.z;
            n = player->sampleCount;
            if (n >= 2 && player->samples[n - 1].z < player->samples[n].z) {
                player->sampleCount--;
                player->samples[player->sampleCount].x = arg0->trans.x;
                player->samples[player->sampleCount].y = arg0->trans.y;
                player->samples[player->sampleCount].z = arg0->trans.z;
                if (player->sampleCount == 3) {
                    rod->slope = 0.0f;
                }
            }
            if (++rod->counter == 5) {
                rod->state = 2;
                if (++arg0->work[0] == rod->steps) {
                    rod->state = 0;
                    func_800258EC(player->spriteData->model, 4, 4);
                    player->castState = 1;
                    player->sampleCount = 1;
                    player->flags &= ~2;
                    if (rod->fishObj != NULL) {
                        func_8005DC18(rod->fishObj, 2);
                        rod->fishObj = NULL;
                        func_8005DC18(rod->playerObj, 2);
                        func_8006071C(player->sound);
                        player->flags &= ~2;
                        player->sound = func_80060540(0x313, player->playerNo);
                    } else {
                        func_8006071C(player->sound);
                        player->flags &= ~2;
                        func_8005DC18(rod->playerObj, 1);
                    }
                }
            }
        } else {
            func_800F9EAC_CastAways(player, 20.0f);
        }
    }
    if (rod->state != 0) {
        if (player->castState == 2) {
            drop = 7.0f;
        } else if (player->castState == 1) {
            drop = 7.0f;
        } else {
            drop = 1.0f;
        }
        func_800F9EAC_CastAways(player, drop);
        func_800FB0C8_CastAways(player->spriteData, player->samples, player->sampleCount + 1);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F0DA0", func_800F92FC_CastAways);
#endif
void func_800F9E2C_CastAways(omObjData* arg0, CastAwaysPlayerWork* arg1, CastAwaysRodWork* arg2) {
    u16 timer = arg2->timer - 1;

    arg2->timer = timer;
    if (!(timer & 0xFFFF)) {
        arg2->timer = 3;
        arg1->sampleCount++;
    }
    arg1->samples[arg1->sampleCount].x = arg0->trans.x;
    arg1->samples[arg1->sampleCount].y = arg0->trans.y;
    arg1->samples[arg1->sampleCount].z = arg0->trans.z;
}

// float register allocation: slope in $f4, retail $f6 (raw 9, masked 0); tried decl order, reusing limit/surface
#ifdef NON_MATCHING
void func_800F9EAC_CastAways(CastAwaysPlayerWork* arg0, f32 drop) {
    f32 k = 0.6f;
    s32 i;
    s32 clamped;
    u16 j;
    f32 surface;
    f32 limit;
    f32 slope;

    clamped = 0;
    for (i = 1; i < arg0->sampleCount; i++) {
        arg0->samples[i].y -= drop;
        if (i == 4) {
            if (arg0->samples[4].y < 0.0f) {
                arg0->samples[4].y = 0.0f;
                clamped++;
            }
        } else if (i >= 5) {
            surface = arg0->samples[4].y;
            if (0.0f < surface) {
                surface = 0.0f;
            }
            if ((arg0->samples[arg0->sampleCount].y == 0.0f) & (surface == 0.0f)) {
                limit = 0.0f;
            } else {
                slope = surface - arg0->samples[arg0->sampleCount].y;
                slope = slope / (arg0->samples[arg0->sampleCount].z - arg0->samples[4].z);
                limit = fabs(arg0->samples[4].z - arg0->samples[i].z) * slope;
            }
            if (arg0->samples[i].y <= limit && arg0->samples[i].y <= 0.0f) {
                arg0->samples[i].y = limit;
                clamped++;
            }
        } else {
            j = 3;
            if (arg0->sampleCount < 3) {
                j = arg0->sampleCount;
            }
            if (i > 0) {
                if (arg0->sampleCount >= 4) {
                    limit = k * arg0->samples[0].y;
                    k -= 0.25f - (f32)i * 0.01f;
                    if (arg0->samples[i].y < limit) {
                        arg0->samples[i].y = limit;
                        clamped++;
                    }
                } else {
                    slope = (arg0->samples[0].y - arg0->samples[j].y) / (arg0->samples[0].z - arg0->samples[j].z);
                    k -= 0.25f - (f32)i * 0.01f;
                    if (arg0->samples[i].y < slope * arg0->samples[i].z) {
                        arg0->samples[i].y = slope * (arg0->samples[i].z - arg0->samples[0].z) + arg0->samples[0].y;
                        clamped++;
                    }
                }
            }
        }
    }
    if ((u16)clamped == arg0->sampleCount - 1 && arg0->sampleCount != 1) {
        arg0->castState = 4;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F0DA0", func_800F9EAC_CastAways);
#endif
void func_800FA198_CastAways(void) {
    Vec3f pos;
    Vec2f scr;

    switch (D_800FBB98_CastAways) {
    case 0:
        pos.x = 0;
        pos.y = 0;
        pos.z = -2300.0f;
        Convert3DTo2D(0, &pos, &scr);
        SetBasicSpritePos(D_800FBB5E_CastAways, 0xA0, (s32)((scr.y + 120.0f + 10.0f) - 68.0f));
        if (D_800FBA06_CastAways >= 0x1F) {
            D_800FBB80_CastAways.z += 44.533333f;
            D_800FBB70_CastAways.z += 19.88889f;
        } else {
            D_800FBB80_CastAways.x += 0.0f;
            D_800FBB80_CastAways.y += -81.7f;
            D_800FBB80_CastAways.z += -6.6666665f;
            D_800FBB70_CastAways.x += 0.0f;
            D_800FBB70_CastAways.y += 0.0f;
            D_800FBB70_CastAways.z += -6.6666665f;
        }
        if (--D_800FBA06_CastAways == 0) {
            D_800FBB98_CastAways = 2;
            func_8006071C(D_800FBB6C_CastAways);
        }
        break;
    case 2:
        if (func_80072718() == 0) {
            D_800FBB98_CastAways = 3;
            GMesCreate(0);
        }
        break;
    case 3:
        if (GMesStatAllGet() == 0) {
            D_800FBB7C_CastAways = 1;
            GMesCreate(8, D_800FBB58_CastAways, 0xA0, 0x20);
        }
        break;
    }
    if (D_800FBA08_CastAways == 0) {
        func_80060128(0x19);
        return;
    }
    D_800FBA08_CastAways--;
}
// register allocation and block order
#ifdef NON_MATCHING
void func_800FA410_CastAways(void) {
    omObjData** players;
    omObjData** fish;
    CastAwaysItemSet* set;
    CastAwaysFishWork* fishWork;
    CastAwaysPlayerWork* work;
    omObjData* obj;
    s32 i;
    s32 j;
    s16 slot;
    s16 id;
    u16 winners;

    players = func_8005DB44(4);
    switch (D_800FBB8C_CastAways) {
    case 0:
        for (i = 0; i < 3; i++) {
            set = D_800FBB48_CastAways[i]->unk_50;
            for (j = 0; j < set->count; j++) {
                set->slots[0][j] = 0;
            }
            fish = func_8005DB44(i);
            for (j = 0; j < D_800ED618[i].max; j++) {
                if (fish[j] == NULL) {
                    continue;
                }
                fishWork = fish[j]->unk_50;
                switch (fishWork->type) {
                case 0:
                    id = set->spriteIds[fishWork->slot];
                    omSetSca(fish[j], 8.0f, 8.0f, 8.0f);
                    break;
                case 1:
                    func_800258EC(fish[j]->model[0], 4, 4);
                    slot = func_800F75BC_CastAways(set, 0);
                    fish[j]->model[0] = set->models[0][slot];
                    func_800258EC(fish[j]->model[0], 4, 0);
                    id = set->spriteIds[slot];
                    omSetSca(fish[j], 8.0f, 8.0f, 8.0f);
                    break;
                case 2:
                    func_800258EC(fish[j]->model[0], 4, 4);
                    slot = func_800F75BC_CastAways(set, 0);
                    fish[j]->model[0] = set->models[0][slot];
                    func_800258EC(fish[j]->model[0], 4, 0);
                    id = set->spriteIds[slot];
                    obj = fish[j];
                    omSetTra(obj, obj->trans.x, obj->trans.y - 30.0f, obj->trans.z - -150.0f);
                    omSetSca(fish[j], 8.0f, 8.0f, 8.0f);
                    break;
                }
                /* Retail reuses the previous id for any other type (none exist). */
                D_800ECDE0[id].unk_02 = D_800FBB40_CastAways;
                D_800ECDE0[id].unk_08 = 0;
                D_800ECDE0[id].unk_04 = 0;
                func_8001E268(id, 6, 6);
                func_8001E268(id, 1, 0);
                func_8001E360(id, 0xFF, 0xFF, 0xBE);
            }
        }
        for (i = 0; i < 4; i++) {
            obj = players[i];
            work = obj->unk_50;
            if (work->lureObj != NULL) {
                omDelObj(work->lureObj);
                work->lureObj = NULL;
            }
            func_8006071C(work->sound);
            func_800258EC(obj->model[2], 4, 4);
            func_800258EC(obj->model[3], 4, 4);
            func_800258EC(work->spriteData->model, 4, 4);
            func_800258EC(obj->model[2], 0x4000, 0);
            func_800258EC(work->rodObj->model[0], 0x4000, 0);
            func_8002456C(obj->model[2]);
            func_8002456C(obj->model[3]);
            func_8002456C(work->rodObj->model[0]);
            omDelObj(work->rodObj);
            func_80025BB8(obj->model[0], obj->motion[0]);
            func_80025EB4(obj->model[0], 2, 2);
            func_8002456C(obj->motion[7]);
            func_8002456C(obj->motion[6]);
        }
        D_800FBB8C_CastAways = 1;
        GMesCreate((D_800FBB56_CastAways == 0 && D_800FBB54_CastAways != 1) ? 0x10 : 2);
        func_800790C0();
        break;
    case 1:
        for (i = 0; i < 4; i++) {
            players[i]->rot.y -= 12.0f;
            if (players[i]->rot.y < 0.0f) {
                players[i]->rot.y = 0.0f;
            }
        }
        if (players[0]->rot.y == 0.0f) {
            D_800FBB8C_CastAways = (D_800FBB56_CastAways != 0) ? 7 : 2;
            for (i = 0; i < 4; i++) {
                func_80025C20(players[i]->model[0], players[i]->motion[0xE], 0, 0xF, 2);
            }
        }
        break;
    case 2:
        winners = 0;
        if (GMesStatAllGet() & 2) {
            for (i = 0; i < 4; i++) {
                if (((CastAwaysPlayerWork*)players[i]->unk_50)->catches != 0) {
                    winners++;
                    func_80025BB8(players[i]->model[0], players[i]->motion[0xC]);
                } else {
                    func_80025BB8(players[i]->model[0], players[i]->motion[0xD]);
                }
                func_80025EB4(players[i]->model[0], 2, 0);
            }
            if (winners == 0) {
                func_80060128(0x34);
                D_800FBB02_CastAways = 0x58;
            } else if (winners == 4) {
                func_80060128(0x36);
                D_800FBB02_CastAways = 0x67;
            } else {
                func_80060128(0x3C);
                D_800FBB02_CastAways = 0x76;
            }
            D_800FBB8C_CastAways = 3;
        }
        break;
    case 3:
        if (--D_800FBB02_CastAways != 0) {
            break;
        }
        /* Retail reuses i for the player loop inside the spawner loop, so only spawner 0's fish
           are removed (the objects go with the overlay). */
        for (i = 0; i < 3; i++) {
            fish = func_8005DB44(i);
            set = D_800FBB48_CastAways[i]->unk_50;
            for (j = 0; j < set->count; j++) {
                if (fish[j] != NULL) {
                    omDelObj(fish[j]);
                }
                func_8002019C(set->spriteIds[j]);
            }
            for (i = 0; i < 4; i++) {
                work = players[i]->unk_50;
                func_80020CC4(work->animDataA);
                func_80020CC4(work->animDataB);
                work->animDataB = NULL;
                work->animDataA = NULL;
            }
        }
        D_800FBB8C_CastAways = 4;
        for (i = 0; i < 3; i++) {
            omDelObj(D_800FBB48_CastAways[i]);
        }
        break;
    case 4:
        D_800FBB8C_CastAways = 5;
        break;
    case 6:
        if (func_80072718() == 0) {
            D_800FB9E4_CastAways = 1;
        }
        break;
    case 7:
        if (GMesWait() == 1) {
            break;
        }
        /* fallthrough */
    case 5:
        D_800FBB8C_CastAways = 6;
        func_800726AC(0, 20);
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F0DA0", func_800FA410_CastAways);
#endif
// decomp-permuter
s16 func_800FABE4_CastAways(u16 arg0)
{
  u16 r;
  u16 i;
  u8 w;
  r = (u8) (rand8() % 10);
  for (i = 0; i < 3; i++)
  {
    w = D_800FBA0C_CastAways[arg0][i];
    if (w > r)
    {
      break;
    }
    r -= w;
  }

  return D_800FBA18_CastAways[arg0][i];
}
void func_800FACA8_CastAways(void) {
    if ((D_800FB9E4_CastAways != 0) || (D_800F5144 != 0)) {
        func_800FB5B4_CastAways(131);
        func_800601D4(40);
    }
}

s32 func_800FACEC_CastAways(CastAwaysPlayerWork* arg0) {
    if (arg0->power == 0) {
        return -1;
    }
    if (arg0->power < 0x22) {
        return 0;
    }
    
    if (arg0->power < 0x39) {
        return 1;
    } else {
        return 2;
    }
}

extern f32 D_800FBA24_CastAways[];

// retail shares one clamp block between the two direction tests (masked 29)
#ifdef NON_MATCHING
void func_800FAD2C_CastAways(omObjData* arg0) {
    CastAwaysPlayerWork* work;
    CastAwaysLureWork* lure;
    s16 prev;
    s16 type;
    s16 dir;
    f32 frame;
    f32 target;

    work = arg0->unk_50;
    prev = work->fishType;
    if (prev == -1) {
        type = func_800FACEC_CastAways(work);
        work->fishType = type;
        if (type != prev) {
            func_800FB668_CastAways(arg0, arg0->model[0], work->animDataA, 0.0f, 1.0f, 2, 0xE);
            func_80025BB8(arg0->model[3], arg0->motion[0xB]);
            func_80025EB4(arg0->model[3], 1, 1);
            work->unk_14C = 1;
        }
    } else {
        type = func_800FACEC_CastAways(work);
        lure = work->lureObj->unk_50;
        if (work->fishType != type) {
            if (D_800FBA24_CastAways[type] < lure->frame) {
                work->unk_14C = -1;
            } else if (lure->frame < D_800FBA24_CastAways[type]) {
                work->unk_14C = 1;
            } else {
                work->unk_14C = 0;
            }
            work->unk_14E = 0;
            work->fishType = type;
        }
        lure->frame = (f32)work->unk_14C + lure->frame;
        dir = work->unk_14C;
        frame = func_80025D18(arg0->model[3]) + (f32)dir;
        if (dir > 0) {
            target = D_800FBA24_CastAways[work->fishType];
            if (target <= lure->frame) {
                lure->frame = target;
                work->unk_14C = 0;
                work->unk_14E = 1;
            }
        } else {
            target = D_800FBA24_CastAways[work->fishType];
            if (lure->frame <= target) {
                lure->frame = target;
                work->unk_14C = 0;
                work->unk_14E = 1;
            }
        }
        func_80025CA8(arg0->model[3], frame);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2B_CastAways/1F0DA0", func_800FAD2C_CastAways);
#endif
