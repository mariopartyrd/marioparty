#include "common.h"
Vec4f D_800C54C0 = { 16.0f, 12.0f, 304.0f, 228.0f };

typedef struct UnkList53 {
    /* 0x00 */ struct UnkList53* next;
    /* 0x04 */ struct UnkList53* prev;
    /* 0x08 */ s16 count;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ s16* data;
} UnkList53;

extern UnkList53* D_800D8390;
extern u16 D_800D8394;

/* The board camera's scissor (D_800C54C0) insets a black frame for TV overscan, and the
   functions below animate it as a vertical wipe. In host widescreen the 3D view is wider than
   4:3 and the inset became side bars: map the family onto the full screen (x 0..320, y 12..228
   to 0..240) so the wipe still runs and the frame is gone. 4:3 keeps retail's frame. */
#define BOARD_SCISSOR_SET() func_8001D4D4(0, &D_800C54C0)


void func_80053080(void) {
    D_800C54C0.x = 16.0f;
    D_800C54C0.y = 12.0f;
    D_800C54C0.z = 304.0f;
    D_800C54C0.w = 228.0f;
    BOARD_SCISSOR_SET();
}

void func_800530E4(void) {
    D_800C54C0.x = 16.0f;
    D_800C54C0.y = 120.0f;
    D_800C54C0.z = 304.0f;
    D_800C54C0.w = 120.0f;
    BOARD_SCISSOR_SET();
}

void func_8005313C(void) {
    s32 i;

    D_800C54C0.y = 12.0f;
    D_800C54C0.w = 228.0f;
    for (i = 0; i < 9; i++) {
        HuPrcVSleep();
        D_800C54C0.y += 12.0f;
        D_800C54C0.w -= 12.0f;
        BOARD_SCISSOR_SET();
    }
    EndProcess(NULL);
}

Process* func_800531E8(void) {
    return omAddPrcObj(func_8005313C, 0x1002, 0, 0);
}

void func_80053214(void) {
    s32 i;

    D_800C54C0.y = 120.0f;
    D_800C54C0.w = 120.0f;
    for (i = 0; i < 9; i++) {
        HuPrcVSleep();
        D_800C54C0.y -= 12.0f;
        D_800C54C0.w += 12.0f;
        BOARD_SCISSOR_SET();
    }
    EndProcess(NULL);
}

Process* func_800532B4(void) {
    return omAddPrcObj(func_80053214, 0x1002, 0, 0);
}

void func_800532E0(void) {
    D_800D8390 = NULL;
    D_800D8394 = 0;
}

void func_800532F4(void) {
    while (D_800D8390 != NULL) {
        func_80053454((unk_Struct02*)D_800D8390);
    }
}

UnkList53* func_80053334(s16 n) {
    UnkList53* p;
    s32 i;

    p = MallocTemp(sizeof(UnkList53));
    if (p != NULL) {
    D_800D8394++;
    p->next = D_800D8390;
    p->prev = NULL;
    if (D_800D8390 != NULL) {
        D_800D8390->prev = p;
    }
    D_800D8390 = p;
    p->count = n;
    p->data = MallocTemp(n * 2);
    for (i = 0; i < n; i++) {
        p->data[i] = -1;
    }
    }
    return p;
}

void* func_800533F8(u16 a, u16 b) {
    UnkList53* p;

    p = func_80053334(a);
    if (p != NULL) {
        p->unkA = func_80064EF4(a, b);
    }
    return p;
}

void func_80053454(unk_Struct02* arg) {
    UnkList53* p = (UnkList53*)arg;
    s32 i;

    if (p->next != NULL) {
        p->next->prev = p->prev;
    }
    if (p->prev != NULL) {
        p->prev->next = p->next;
    } else {
        D_800D8390 = p->next;
    }
    for (i = 0; i < p->count; i++) {
        if (p->data[i] >= 0) {
            func_80067704(p->data[i]);
        }
    }
    func_80064D38(p->unkA);
    FreeTemp(p->data);
    FreeTemp(p);
    D_800D8394--;
}
