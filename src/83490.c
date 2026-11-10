#include "common.h"

// libleo LeoBootGame (IDO-compiled: NON_MATCHING). It decrypts __LeoBootGame2 and the 0x50 bytes
// after it (D_80082D10) in place, keyed by the sum of __LeoBootGame2's address bytes, then calls it.
// __LeoBootGame2 is encrypted code, not compilable C: it stays as asm (bytes).

void __LeoBootGame2(void* entry);
extern u8 D_80082D10[];

#ifdef NON_MATCHING
void LeoBootGame(void* entry) {
    u8* p;
    u32 addr = (u32)__LeoBootGame2;
    u8 key = (addr >> 24) + ((addr & 0xFF0000) >> 16) + ((addr & 0xFF00) >> 8) + addr;
    u32 i;

    for (p = (u8*)__LeoBootGame2, i = 0; i < 0x344; i += 4, p += 4) {
        p[2] -= key;
        p[3] += key;
    }
    osWritebackDCacheAll();
    osInvalICache(__LeoBootGame2, 0x344);
    for (p = D_80082D10, i = 0; i < 0x50; i += 4, p += 4) {
        p[2] -= key;
        p[3] += key;
    }
    osWritebackDCacheAll();
    osInvalICache(D_80082D10, 0x50);
    __LeoBootGame2(entry);
}
#else
INCLUDE_ASM("asm/nonmatchings/83490", LeoBootGame);
#endif

// Encrypted (see above).
INCLUDE_ASM("asm/nonmatchings/83490", __LeoBootGame2);
