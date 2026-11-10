#include "common.h"
#include "sdk_leo.h"

// libleo LeoLBAToByte (IDO-compiled: NON_MATCHING, see sdk_leo.h).

#ifdef NON_MATCHING
s32 func_80081840(s32 startlba, u32 nlbas, s32* bytes) {
    u32 resbytes = 0;
    u32 byte_p_blk;
    u16 vzone = 1;
    u16 zone;
    s32 flag = 1;

    if (D_800C63D0 == 0) {
        return -1;
    }
    startlba += 24;
    while (nlbas != 0) {
        if (flag || (D_800CBC18[D_800E87E8][vzone] == startlba)) {
            vzone = func_800817E4(startlba);
            zone = D_800CBD18[D_800E87E8][vzone];
            if (zone >= 8) {
                zone -= 7;
            }
            byte_p_blk = D_800CBC04[zone];
        }
        resbytes += byte_p_blk;
        nlbas--;
        startlba++;
        if ((nlbas != 0) && ((u32)startlba >= 0x10DC)) {
            return 0x20; // LEO_ERROR_LBA_OUT_OF_RANGE
        }
        flag = 0;
    }
    *bytes = resbytes;
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/82440", func_80081840);
#endif
