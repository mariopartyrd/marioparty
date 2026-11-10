#include "7B.h"

#define D_800FB240 D_800FB240_MinigameStadiumMinigameResultsScreen
#define D_800FB248 D_800FB248_MinigameStadiumMinigameResultsScreen
#define D_800FB0D0 D_800FB0D0_MinigameStadiumMinigameResultsScreen
#define D_800FB258 D_800FB258_MinigameStadiumMinigameResultsScreen

f32 D_800FB0D0_MinigameStadiumMinigameResultsScreen[4] = { -450.0f, -150.0f, 150.0f, 450.0f };

/* The background: the board, each player's column base and coin bar. */
// register allocation: base/index of the ids[j] store swap a0/v1 (raw 5, masked 0); inverted
// ternary, post-increment indices and a file-id local tried
#ifdef NON_MATCHING
void func_800F8A00_MinigameStadiumMinigameResultsScreen(void) {
    Process* procs[4];
    Process* proc;
    s32 i;
    s32 j;
    s32 k;

    i = 0;
    proc = HuPrcCurrentGet();
    D_800FB240 = proc->user_data;
    D_800FB244_MinigameStadiumMinigameResultsScreen = proc->relative->user_data;
    for (; i < 4; i++) {
        procs[i] = D_800FB244_MinigameStadiumMinigameResultsScreen->player[i];
        D_800FB248[i] = procs[i]->user_data;
    }
    i = 1;
    LoadBackgroundData(D_FE2310);
    j = 5;
    func_8005049C();
    func_8004B7F8(0x80);
    k = 0;
    func_800F7F0C_MinigameStadiumMinigameResultsScreen();
    D_800FB240->ids[0] = func_800174C0(0xC000A, 0x80099);
    do {
        D_800FB240->ids[i] = func_80023FC8(D_800FB294_MinigameStadiumMinigameResultsScreen);
        D_800FB240->ids[j] = func_80023FC8(D_800FB248[k]->coinsMg > 0 ? D_800FB28E_MinigameStadiumMinigameResultsScreen
                                                                   : D_800FB29E_MinigameStadiumMinigameResultsScreen);
        i++;
        j++;
        k++;
    } while (i < 5);
    func_80025798(D_800FB240->ids[0], 0.0f, 0.0f, 0.0f);
    func_80025830(D_800FB240->ids[0], 1.0f, 1.0f, 1.0f);
    D_800FB240->flags = 0;
    for (i = 1, j = 5, k = 0; i < 5; i++, j++, k++) {
        func_80025798(D_800FB240->ids[i], D_800FB0D0[k], 0.0f, 0.0f);
        func_80025830(D_800FB240->ids[i], 1.0f, 1.0f, 1.0f);
        func_800258EC(D_800FB240->ids[i], 4, 0);
        func_80025798(D_800FB240->ids[j], D_800FB0D0[k], 0.0f, 150.0f);
        D_800FB240->scale[k].x = 0.1f;
        D_800FB240->scale[k].z = 1.0f;
        D_800FB240->scale[k].y = 1.0f;
        func_80025830(D_800FB240->ids[j], D_800FB240->scale[k].x, 1.0f, D_800FB240->scale[k].z);
    }
    func_800F8DB4_MinigameStadiumMinigameResultsScreen();
    for (i = 0; i < 4; i++) {
        func_800F8E74_MinigameStadiumMinigameResultsScreen(D_800FB248[i], i);
    }
    HuPrcSleep(0x10);
    SetFadeInTypeAndTime(0, 0x10);
    D_800FB2A0_MinigameStadiumMinigameResultsScreen = 1;
    while (TRUE) {
        HuPrcVSleep();
        for (i = 0; i < 4; i++) {
            func_800F8E74_MinigameStadiumMinigameResultsScreen(D_800FB248[i], i);
        }
        for (i = 0; i < 4; i++) {
            if (D_800FB248[i]->coinsMg != 0) {
                func_800F91CC_MinigameStadiumMinigameResultsScreen(D_800FB240, i, 1);
            }
        }
        func_800F8E28_MinigameStadiumMinigameResultsScreen();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_7B_MinigameStadiumMinigameResultsScreen/306290", func_800F8A00_MinigameStadiumMinigameResultsScreen);
#endif

void func_800F8DB4_MinigameStadiumMinigameResultsScreen(void) {
    D_800FB258 = func_80019060(D_800FB282_MinigameStadiumMinigameResultsScreen, 0, 1);
    func_80018D84(D_800FB258, 0x10);
    SetBasicSpriteSize(D_800FB258, 1.0f, 1.0f);
    func_80018C90(D_800FB258);
    SetBasicSpritePos(D_800FB258, 0x118, 0x28);
}

void func_800F8E28_MinigameStadiumMinigameResultsScreen(void) {
    if ((ContBtn[3] & 0x2830) == 0x2830) {
        ShowBasicSprite(D_800FB258);
    } else {
        func_80018C90(D_800FB258);
    }
}

/* A player's total in digits over their column: spinning digits until flags bit 0x80 (counted). */
void func_800F8E74_MinigameStadiumMinigameResultsScreen(PlayerRes* res, s32 i) {
    Vec3f pos;
    Vec2f scr;
    f32 x;
    s32 k;
    u32 r;
    s16 rem;

    HuPrcCurrentGet();
    if (!(res->flags & 0x80)) {
        for (k = 0, x = -65.0f; k < 3; k++, x += 65.0f) {
            r = (u32)(rand8() * 5) >> 7;
            pos.x = x + D_800FB0D0[i];
            pos.y = 75.0f;
            pos.z = 100.0f;
            Convert3DTo2D(0, &pos, &scr);
            SetBasicSpritePos(res->sprTotal[k], scr.x, scr.y);
            func_80018E0C(res->sprTotal[k], (u8)r);
            func_80018D84(res->sprTotal[k], 0x11);
            ShowBasicSprite(res->sprTotal[k]);
        }
        return;
    }
    if (res->total >= 1000) {
        res->digTotal[0] = res->digTotal[1] = res->digTotal[2] = 9;
    } else if (res->total <= 0) {
        res->digTotal[0] = res->digTotal[1] = res->digTotal[2] = 0;
    } else {
        res->digTotal[0] = res->total / 100;
        rem = res->total % 100;
        res->digTotal[1] = rem / 10;
        res->digTotal[2] = rem % 10;
    }
    for (k = 0, x = -65.0f; k < 3; k++, x += 65.0f) {
        pos.x = x + D_800FB0D0[i];
        pos.y = 75.0f;
        pos.z = 100.0f;
        Convert3DTo2D(0, &pos, &scr);
        SetBasicSpritePos(res->sprTotal[k], scr.x, scr.y);
        func_80018E0C(res->sprTotal[k], res->digTotal[k]);
        func_80018D84(res->sprTotal[k], 0x11);
        if (res->digTotal[0] == 0 && res->digTotal[1] == 0) {
            func_80018C90(res->sprTotal[0]);
            func_80018C90(res->sprTotal[1]);
            ShowBasicSprite(res->sprTotal[2]);
        } else if (res->digTotal[0] == 0 && res->digTotal[1] != 0) {
            func_80018C90(res->sprTotal[0]);
            ShowBasicSprite(res->sprTotal[1]);
            ShowBasicSprite(res->sprTotal[2]);
        } else {
            ShowBasicSprite(res->sprTotal[k]);
        }
    }
}

/* grow (dir 1) or shrink (dir 0) a player's coin bar; flags bit 0 once it reaches its limit */
void func_800F91CC_MinigameStadiumMinigameResultsScreen(BgWork* bg, s32 i, s8 dir) {
    func_800258EC(bg->ids[5 + i], 4, 0);
    if (dir != 0) {
        if (dir == 1) {
            bg->scale[i].x += 0.1f;
            if (bg->scale[i].x > 2.2f) {
                bg->scale[i].x = 2.2f;
                bg->flags |= 1;
            }
        }
    } else {
        bg->scale[i].x -= 0.1f;
        if (bg->scale[i].x < 0.2f) {
            bg->scale[i].x = 0.2f;
            bg->flags |= 1;
        }
    }
    func_80025830(bg->ids[5 + i], bg->scale[i].x, bg->scale[i].y, bg->scale[i].z);
}
