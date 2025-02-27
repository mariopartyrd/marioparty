#include "common.h"

extern HeapNode* D_800D6030;
extern HeapNode* D_800D6040;

void MakePermHeap(void* arg0, u32 arg1) {
    D_800D6030 = HuMemHeapInit(arg0, arg1);
}

void* HuMemDirectMalloc(s32 size) {
    return HuMemMemoryAlloc(D_800D6030, size);
}

void HuMemDirectFree(void* arg0) {
    HuMemMemoryFree(arg0);
}

void func_8003B6E4(void* arg0, u32 arg1) {
    Realloc(D_800D6030, arg0, arg1);
}

void func_8003B710() {
    GetAllocatedHeapSize(D_800D6030);
}

void func_8003B730() {
    GetUsedMemoryBlockCount(D_800D6030);
}

void MakeTempHeap(void* arg0, u32 arg1) {
    D_800D6040 = HuMemHeapInit(arg0, arg1);
}

void* MallocTemp(u32 size) {
    return HuMemMemoryAlloc(D_800D6040, (s32) size);
}

void FreeTemp(void* arg0) {
    HuMemMemoryFree(arg0);
}

void func_8003B7B4(void* arg0, u32 arg1) {
    Realloc(D_800D6040, arg0, arg1);
}

void func_8003B7E0() {
    GetAllocatedHeapSize(D_800D6040);
}

void func_8003B800() {
    GetUsedMemoryBlockCount(D_800D6040);
}
