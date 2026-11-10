#include "common.h"
#include "sdk_leo.h"

// libultra osDriveRomInit: the 64DD IPL ROM's PI handle (IDO-compiled with libleo: NON_MATCHING).

#ifdef NON_MATCHING
OSPiHandle* func_80082660(void) {
    u32 value;
    u32 latency;
    u32 pageSize;
    u32 relDuration;
    u32 pulse;
    u32 saveMask;

    __osPiGetAccess();
    if (!D_800C63E0) {
        __osPiRelAccess();
        return &D_800E9890;
    }
    D_800C63E0 = 0;
    D_800E9890.type = DEVICE_TYPE_BULK;
    D_800E9890.baseAddress = 0xA6000000;
    D_800E9890.domain = PI_DOMAIN1;
    D_800E9890.speed = 0;
    bzero(&D_800E9890.transferInfo, sizeof(__OSTranxInfo));
    while (LEO_IO_READ(PI_STATUS_REG) & (PI_STATUS_DMA_BUSY | PI_STATUS_IO_BUSY)) {
    }
    latency = LEO_IO_READ(PI_BSD_DOM1_LAT_REG);
    pageSize = LEO_IO_READ(PI_BSD_DOM1_PGS_REG);
    relDuration = LEO_IO_READ(PI_BSD_DOM1_RLS_REG);
    pulse = LEO_IO_READ(PI_BSD_DOM1_PWD_REG);
    LEO_IO_WRITE(PI_BSD_DOM1_LAT_REG, 0xFF);
    LEO_IO_WRITE(PI_BSD_DOM1_PGS_REG, 0);
    LEO_IO_WRITE(PI_BSD_DOM1_RLS_REG, 3);
    LEO_IO_WRITE(PI_BSD_DOM1_PWD_REG, 0xFF);
    value = LEO_IO_READ(D_800E9890.baseAddress);
    D_800E9890.pageSize = (value >> 16) & 0xF;
    D_800E9890.relDuration = (value >> 20) & 0xF;
    D_800E9890.pulse = value >> 8;
    D_800E9890.latency = value;
    LEO_IO_WRITE(PI_BSD_DOM1_LAT_REG, latency);
    LEO_IO_WRITE(PI_BSD_DOM1_PGS_REG, pageSize);
    LEO_IO_WRITE(PI_BSD_DOM1_RLS_REG, relDuration);
    LEO_IO_WRITE(PI_BSD_DOM1_PWD_REG, pulse);
    saveMask = __osDisableInt();
    D_800E9890.next = __osPiTable;
    __osPiTable = &D_800E9890;
    __osRestoreInt(saveMask);
    __osPiRelAccess();
    return &D_800E9890;
}
#else
INCLUDE_ASM("asm/nonmatchings/83260", func_80082660);
#endif
