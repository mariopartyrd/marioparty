#include "common.h"

#include "engine/siman.h"
#include "engine/process.h"
#include "engine/pad.h"

/* Frame buffers, RDP/RSP buffers and the microcode table (text, data pairs; the texts sit in the
   main .data blob at 0x800B1760, which stays asm). The host has no fixed N64 RAM: it gets its own
   buffers, and its graphics bridge does not use the microcode addresses. */
extern u8 D_800B1830[], D_800C87E0[], D_800C8C00[], D_800C9020[], D_800C9430[], D_800C97C0[];
void* D_800C4250[] = { (void*)0x80360000, (void*)0x80385800, (void*)0x803AB000 };
u64* D_800C425C[] = { (u64*)0x803F6000, (u64*)0x803F6400, (u64*)0x803FC400, (u64*)0x803FC400 };
s32 D_800C426C[] = {
    (s32)D_800B1830, (s32)D_800C87E0, 0x800B2BC0, (s32)D_800C8C00, 0x800B3F50, (s32)D_800C9020,
    0x800B50E0, (s32)D_800C9430, 0x800B69A0, (s32)D_800C97C0,
    (s32)D_800B1830, (s32)D_800C87E0, 0x800B2BC0, (s32)D_800C8C00, 0x800B3F50, (s32)D_800C9020,
    1000,
};
s32 D_800C42B0 = 0;
f32 D_800C42B4[3] = { 0.0f, 0.0f, 0.0f };

// the scheduler client nnsched fills (next, queue, id); unkSchedStruct in engine/graphics.h
typedef struct {
    void* unk00;
    OSMesgQueue* unk04;
    s32 unk08;
} unk3BF30SchedClient;

extern u8 D_31C7E0[];
extern s32 D_800C32B0;
extern OSMesgQueue D_800ED538;
extern u8 D_800ED552;
extern s32 D_800F3758;
extern u32 D_800F383C;

void DataInit(void* fs_rom_loc);
void HuPrcCall(s32 time);
void HuPrcInit(void);
void MakePermHeap(void* arg0, u32 arg1);
void MakeTempHeap(void*, s32);
s16 func_80013E84(void);
void func_80014220(void);
void func_8001429C(void);
void func_8001A0F0(void);
void func_8001A600(void** arg1, s32 arg2, s32 arg3, u64** arg4, s32* arg5);
void func_8001ABF4(u32 arg0);
void func_80060F70(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u16 arg4);
void func_80061354(void);
void func_800613A0(void);
void func_80061F60(void);
void func_800637C0(s32, s32);
void func_80063F40(void);
void func_8006CBB0(void);
void func_8003B5EC(s16 arg0);


void func_8003B330(void) {
    unk3BF30SchedClient sp18;
    OSMesg sp28[0x140];
    OSMesg sp528;
    s16 temp_s1;
    s32 temp_s0;
    s32 done;
    u32 lastFrame;

    lastFrame = 0;
    done = 0;
    func_8003B5EC(3);
    MakePermHeap(((void *)0x80140000), 0x1A0000);
    MakeTempHeap(((void *)0x80120000), 0x20000);
    if (osTvType == OS_TV_NTSC) {
        func_800637C0(2, 1);
    } else {
        func_800637C0(0x1E, 1);
    }
    D_800ED552 = 3;
    func_8001A600(D_800C4250, 3, 2, D_800C425C, D_800C426C);
    func_80060F70(0, 0x20, 0xD2, 0x20, 0xD4);
    func_80063F40();
    func_800138DC(4, 1);
    func_8006CBB0();
    func_80014220();
    func_80061F60();
    DataInit(D_31C7E0);
    HuPrcInit();
    osCreateMesgQueue(&D_800ED538, sp28, 0x140);
    func_800639F8((unkMesgWrapper*)&sp18, &D_800ED538, 3);
    func_80013E84();
    osViSetSpecialFeatures(OS_VI_GAMMA_OFF);
    func_8001ABF4(2);
    HuPrcCreate(func_8001A0F0, 1, 0, 0);
    while (done == 0) {
        osRecvMesg(&D_800ED538, &sp528, OS_MESG_BLOCK);
        switch ((s32)sp528) {
            case 1:
                func_80061354();
                temp_s1 = func_80061228(0xC8, 0, 0);
                if (D_800F383C - lastFrame >= 2) {
                    lastFrame = D_800F383C;
                    if (D_800C42B0 < D_800ED552) {
                        func_80013E84();
                        func_8001429C();
                        temp_s0 = D_800C32B0;
                        HuPrcCall(1);
                        if (temp_s0 != D_800C32B0) {
                            D_800C42B0++;
                        }
                        func_80061264(temp_s1);
                        func_800613A0();
                    }
                }
                break;
            case 0x309:
                D_800C42B0--;
                D_800F3758++;
                break;
            case 2:
                done = 1;
                break;
        }
    }
    while (1) {
    }
}
void func_8003B5EC(s16 arg0) {
    s16 i;

    for (i = 0; i < arg0; i++) {
        func_8009B770(D_800C4250[i], 0, 0x25800);
    }
}