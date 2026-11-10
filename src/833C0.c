#include "common.h"
#include "sdk_leo.h"

// libleo LeoDriveExist: reads the 64DD's ID word through domain-1 timing (IDO-compiled: NON_MATCHING).

#ifdef NON_MATCHING
s32 func_800827C0(void) {
    u32 data;
    u32 latency;
    u32 pageSize;
    u32 relDuration;
    u32 pulse;

    __osPiGetAccess();
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
    data = LEO_IO_READ(0x06001010);
    LEO_IO_WRITE(PI_BSD_DOM1_LAT_REG, latency);
    LEO_IO_WRITE(PI_BSD_DOM1_PGS_REG, pageSize);
    LEO_IO_WRITE(PI_BSD_DOM1_RLS_REG, relDuration);
    LEO_IO_WRITE(PI_BSD_DOM1_PWD_REG, pulse);
    __osPiRelAccess();
    if (data == 0x2129FFF8) {
        return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/833C0", func_800827C0);
#endif
