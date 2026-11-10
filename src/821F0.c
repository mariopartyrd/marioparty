#include "common.h"
#include "sdk_leo.h"

// libleo leoLba_to_phys, leoLba_to_vzone (IDO-compiled: NON_MATCHING, see sdk_leo.h).

#ifdef NON_MATCHING
u16 func_800815F0(u32 lba) {
    u16 vzone;
    u16 pzone;
    u16 zone;
    u16 start;
    u16 cyl;
    u16 n;
    u16 d;

    D_800E87F0.rdwr_blocks = 2 - (lba & 1);
    if (((lba & 3) == 0) || ((lba & 3) == 3)) {
        D_800E87F0.start_block = 0;
    } else {
        D_800E87F0.start_block = 1;
    }
    vzone = func_800817E4(lba);
    pzone = D_800CBD18[D_800E87E8][vzone];
    D_800E87F0.head = 0;
    D_800E87F0.zone = pzone;
    zone = pzone;
    if (zone >= 8) {
        D_800E87F0.zone = zone - 7;
        D_800E87F0.head = 1;
        zone = (u8)(zone - 7);
    }
    cyl = D_800CBCF8[pzone];
    start = (vzone != 0) ? D_800CBC16[D_800E87E8 * 16 + vzone] : 0;
    if (D_800E87F0.head != 0) {
        D_800E87F0.cylinder = cyl - ((lba - start) >> 1);
        cyl = D_800CBD86[zone];
    } else {
        D_800E87F0.cylinder = cyl + ((lba - start) >> 1);
    }
    d = (pzone != 0) ? D_800E7B00[7 + pzone] : 0;
    for (n = D_800E7B00[8 + pzone] - d; n != 0; n--) {
        if (D_800E87F0.cylinder < (u16)(D_800E7B00[0x20 + d] + cyl)) {
            break;
        }
        D_800E87F0.cylinder++;
        d++;
    }
    D_800E87F0.sec_bytes = D_800CBBF8[zone];
    D_800E87F0.blk_bytes = D_800CBC04[zone];
    if (D_800E87FC == 0 && lba < 12) {
        D_800E87F0.sec_bytes = 0xC0;
        D_800E87F0.blk_bytes = 0x3FC0;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/821F0", func_800815F0);
#endif

#ifdef NON_MATCHING
u16 func_800817E4(u32 lba) {
    u16 vzone;

    for (vzone = 0; vzone < 16; vzone++) {
        if (lba < D_800CBC18[D_800E87E8][vzone]) {
            return vzone;
        }
    }
    return 0xFF;
}
#else
INCLUDE_ASM("asm/nonmatchings/821F0", func_800817E4);
#endif
