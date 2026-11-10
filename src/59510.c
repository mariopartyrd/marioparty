#include "common.h"

typedef struct {
    /* 0x00 */ s16 player;
    /* 0x02 */ s16 type;
    /* 0x04 */ s16 delay;
    /* 0x08 */ Process* proc;
} RumbleLoop;

void func_80060F04(s16, s16, s16, s16);

void func_80058910(s16 player, s16 type) {
    if (player == -1) {
        player = GetCurrentPlayerIndex();
    }
    switch (type) {
    case 0:
        func_80060F04(player, 5, 0, 5);
        break;
    case 1:
        func_80060F04(player, 2, 3, 10);
        break;
    case 2:
        func_80060F04(player, 10, 0, 10);
        break;
    case 3:
        func_80060F04(player, 20, 0, 20);
        break;
    case 4:
        func_80060F04(player, 2, 2, 20);
        break;
    case 5:
        func_80060F04(player, 30, 0, 30);
        break;
    }
}

void func_80058A0C(void) {
    RumbleLoop* r = HuPrcCurrentGet()->user_data;

    while (1) {
        func_80058910(r->player, r->type);
        HuPrcSleep(r->delay);
    }
}

RumbleLoop* func_80058A4C(s16 player, s16 type, s32 delay) {
    RumbleLoop* r = MallocTemp(sizeof(RumbleLoop));
    Process* p;

    if (r != NULL) {
        r->player = player;
        r->type = type;
        r->delay = delay - 1;
        p = omAddPrcObj(func_80058A0C, 0x1005, 0, 0);
        r->proc = p;
        p->user_data = r;
    }
    return r;
}

void func_80058AD0(RumbleLoop* r) {
    if (r != NULL) {
        EndProcess(r->proc);
        FreeTemp(r);
    }
}
