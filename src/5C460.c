#include "common.h"
#include "spaces.h"

typedef struct {
    /* 0x00 */ s8 flag;
    /* 0x01 */ s8 unk1;
    /* 0x02 */ s8 unk2;
} QuestEntry;
QuestEntry D_800C5820[50] = {
    { 0x14, 1, 1 }, { 0x15, 1, 2 }, { 0x36, 1, 3 }, { 0x34, 1, 4 }, { 0x00, 2, 1 }, { 0x12, 2, 2 }, { 0x29, 2, 3 }, { 0x0B, 2, 4 },
    { 0x32, 2, 5 }, { 0x0D, 3, 1 }, { 0x03, 3, 2 }, { 0x27, 3, 3 }, { 0x33, 3, 4 }, { 0x19, 3, 5 }, { 0x1D, 4, 1 }, { 0x16, 4, 2 },
    { 0x2F, 4, 3 }, { 0x0A, 4, 4 }, { 0x2B, 5, 1 }, { 0x28, 5, 2 }, { 0x1E, 5, 3 }, { 0x04, 5, 4 }, { 0x22, 5, 5 }, { 0x31, 5, 6 },
    { 0x1A, 5, 7 }, { 0x1F, 5, 8 }, { 0x17, 6, 1 }, { 0x0C, 6, 2 }, { 0x21, 6, 3 }, { 0x07, 6, 4 }, { 0x2A, 6, 5 }, { 0x2E, 6, 6 },
    { 0x02, 7, 1 }, { 0x23, 7, 2 }, { 0x09, 7, 3 }, { 0x11, 7, 4 }, { 0x0F, 7, 5 }, { 0x26, 7, 6 }, { 0x2D, 8, 1 }, { 0x1C, 8, 2 },
    { 0x2C, 8, 3 }, { 0x13, 8, 4 }, { 0x0E, 8, 5 }, { 0x10, 8, 6 }, { 0x37, 9, 1 }, { 0x25, 9, 2 }, { 0x05, 9, 3 }, { 0x20, 9, 4 },
    { 0x18, 9, 5 }, { 0x25, 9, 6 }
};

typedef struct {
    /* 0x00 */ s16 chain;
    /* 0x02 */ s16 space;
} ChainSpace;

extern s16 D_800D8920;
extern unk_ProcessUserData08* D_800D8930[4];
extern Process* D_800D8940;
extern s8 D_800F0A22;
extern s16 D_800F329A;
extern ChainSpace D_800F33D8[4];
extern s16 D_800F3750;
extern s8 D_800F3752;
extern s8 D_800F524A;
extern s8 ContStkY[];

void func_8005CE8C(s32);
void func_800718DC(s16, void*, s8);
void* func_8003B820();
void func_8003C198(unk_ProcessUserData08*, Vec3f*, Vec3f*, f32);
void func_8003B8A4(unk_ProcessUserData08*);
void func_8005BCC8(s16 chain, s16 space);
void func_8005BF08(void);


void func_8005B860(s16 index) {
    D_800D8920 = index;
    if (index >= 0) {
        func_80059348(D_800C5820[index].flag);
        D_800F329A = D_800C5820[index].unk1;
        D_800F3750 = D_800C5820[index].unk2;
    } else {
        func_80059348(index);
        D_800F329A = -1;
        D_800F3750 = -1;
    }
}

void func_8005B900(void) {
    s16 index = D_800D8920;

    if (_CheckFlag(0x2F) != 0 && index >= 0) {
        ClearBoardFeatureFlag(0x2F);
        func_8005CE8C(index + 7);
    }
}

s32 func_8005B950(void) {
    return (D_800D8920 < 0) ? 1 : func_8005CE48(D_800D8920 + 7);
}

s16 func_8005B984(void* str) {
    u8 port = GwPlayer[0].port;
    s16 win;
    s16 choice;

    PlaySound(0x36);
    win = func_8006D010(0x5F, 0x32, 0x81, 0x22, 0, 0);
    func_8006E0A4(win, 5);
    func_8006E154(win, 0xDC);
    if (str == NULL) {
        LoadStringIntoWindow(win, (void*)0x4A8, -1, -1);
    } else {
        LoadStringIntoWindow(win, str, -1, -1);
    }
    func_8006E070(win, 0);
    while (func_8006FCC0(win) != 0) {
        HuPrcVSleep();
    }
    func_8007155C(win, (s16)(1 << port));
    choice = func_8006FCF0(win, 0, 0);
    func_80070D90(win);
    PlaySound(0x37);
    return choice;
}

s16 func_8005BAB0(void* str) {
    s16 index = D_800D8920;
    s16 win;

    PlaySound(0x36);
    win = func_8006D010(0x48, 0x96, 0xAD, 0x30, 0, 0);
    func_8006E0A4(win, 5);
    func_8006E154(win, 0xDC);
    func_800717C0(win);
    if (str == NULL) {
        if (index == -2) {
            if (GwCommon.boardWork[0] != 0) {
                LoadStringIntoWindow(win, (void*)0x4AD, -1, -1);
            } else {
                LoadStringIntoWindow(win, (void*)0x4AC, -1, -1);
            }
        } else {
            if (func_8005CE48(index + 7) != 0) {
                LoadStringIntoWindow(win, (void*)0x4AA, -1, -1);
            } else {
                LoadStringIntoWindow(win, (void*)0x4AB, -1, -1);
            }
            func_800718DC(win, (void*)(D_800C5820[index].flag + 0x325), 0);
        }
    } else {
        LoadStringIntoWindow(win, str, -1, -1);
    }
    func_8006E070(win, 0);
    PlaySound(0x37);
    return win;
}

void func_8005BC28(void) {
    Vec3f pos;
    GW_PLAYER* player = GetPlayerStruct(-1);

    SetPlayerAnimation(-1, -1, 2);
    func_8004CD84(&pos);
    func_8004D1EC(&player->player_obj->unk_18, &pos, &player->player_obj->unk_18, 8);
}

void func_8005BC80(void) {
    s32 i;

    D_800F524A = 0;
    for (i = 0; i < 4; i++) {
        D_800F33D8[i].chain = -1;
    }
    D_800F3752 = 1;
    D_800F0A22 = 1;
}

void func_8005BCC8(s16 chain, s16 space) {
    if (D_800F524A < 4) {
        D_800F33D8[D_800F524A].chain = chain;
        D_800F33D8[D_800F524A].space = space;
        D_800F524A++;
    }
}

void func_8005BD10(s8 arg0) {
    D_800F3752 = arg0;
}

void func_8005BD1C(s8 arg0) {
    D_800F0A22 = arg0;
}

void func_8005BD28(void) {
    GW_PLAYER* player = GetPlayerStruct(0);

    if (D_800F3752 != 0) {
        func_8005BCC8(player->cur_chain, player->cur_space + 1);
    }
    if (D_800F0A22 != 0) {
        func_8005BCC8(player->cur_chain, player->cur_space - 1);
    }
}

s32 func_8005BDA0(u16* chain, u16* space) {
    Vec3f stick;
    Vec3f dir;
    GW_PLAYER* player;
    s32 i;

    player = GetPlayerStruct(0);
    stick.x = ContStkX[player->port];
    stick.z = -(f32)ContStkY[player->port];
    stick.y = 0.0f;
    for (i = 0; i < D_800F524A; i++) {
        func_800A0E80(&dir, &BoardSpaceGet(GetAbsSpaceIndexFromChainSpaceIndex(D_800F33D8[i].chain, D_800F33D8[i].space))->coords, &player->player_obj->coords);
        dir.y = 0.0f;
        if (func_8003D8CC(&stick, &dir) <= 30.0f) {
            *chain = D_800F33D8[i].chain;
            *space = D_800F33D8[i].space;
            return 1;
        }
    }
    return 0;
}

void func_8005BF08(void) {
    f32 angle;
    f32 scale;
    s32 i;

    angle = 0.0f;
    while (1) {
        HuPrcVSleep();
        angle += 15.0f;
        if (angle > 360.0f) {
            angle -= 360.0f;
        }
        scale = func_800AEFD0(angle) * 0.15f + 1.1f;
        for (i = 0; i < 4; i++) {
            if (D_800D8930[i] != NULL) {
                func_800A0D00(&D_800D8930[i]->unk04->xScale, scale, 1.0f, scale);
            }
        }
    }
}

void func_8005C00C(s16 curSpace) {
    GW_PLAYER* player = GetPlayerStruct(-1);
    s32 i;
    s16 space;
    BoardSpace* bs;

    for (i = 0; i < 4; i++) {
        D_800D8930[i] = NULL;
        if (D_800F33D8[i].chain != -1) {
            space = GetAbsSpaceIndexFromChainSpaceIndex(D_800F33D8[i].chain, D_800F33D8[i].space);
            if (space != curSpace) {
                bs = BoardSpaceGet(space);
                D_800D8930[i] = func_8003B820();
                func_8003C198(D_800D8930[i], &player->player_obj->coords, &bs->coords, 170.0f);
            }
        }
    }
    D_800D8940 = omAddPrcObj(func_8005BF08, 0x4800, 0, 0);
}

void func_8005C124(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_800D8930[i] != NULL) {
            func_8003B8A4(D_800D8930[i]);
            D_800D8930[i] = NULL;
        }
        if (D_800D8940 != NULL) {
            EndProcess(D_800D8940);
            D_800D8940 = NULL;
        }
    }
}