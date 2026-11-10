
#ifndef __GRAPHICS_H
#define __GRAPHICS_H

#include "PR/os.h"

void func_8001AB84(void**, u16, u16); // Init graphics frame buffer pool                        
void func_8001ABAC(u64**); // Set gThreadStacks
void func_8001ABE8(s32*); // Set graphics state
void func_8001ABF4(u32); // Set unk swap chain state
void func_8001A7DC(void*); // Swap Chain Loop

// TODO: Move to respective header files
typedef struct {
    void* unk00; /* the nnsched client's next */
    OSMesgQueue *unk04;
    s32 unk08;
} unkSchedStruct;

typedef struct {
    u8 unk00[0x20];
} unkGraphicsMessage2; // OSMesg

void func_800639F8(unkSchedStruct*, OSMesgQueue*, s32);
void func_80061414();
void func_800613E8();


#endif
