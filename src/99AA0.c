#include "PR/os_internal.h"

#define ADDRESS_CRC_MESSAGE_LENGTH 10
#define ADDRESS_CRC_LENGTH 5
#define ADDRESS_CRC_GENERATOR 0x15
#define ADDRESS_CRC_MASK ((1 << ADDRESS_CRC_LENGTH) - 1)

u8 __osContAddressCrc(u16 addr) {
    u32 temp = 0;
    u32 i = (1 << ADDRESS_CRC_MESSAGE_LENGTH);

    do {
        temp <<= 1;
        if ((u32)addr & i) {
            if (temp & (1 << ADDRESS_CRC_LENGTH)) {
                temp ^= ADDRESS_CRC_GENERATOR - 1;
            } else {
                ++temp;
            }
        } else if (temp & (1 << ADDRESS_CRC_LENGTH)) {
            temp ^= ADDRESS_CRC_GENERATOR;
        }
        i >>= 1;
    } while (i != 0);
    i = ADDRESS_CRC_LENGTH;
    do {
        temp <<= 1;
        if (temp & (1 << ADDRESS_CRC_LENGTH)) {
            temp ^= ADDRESS_CRC_GENERATOR;
        }
    } while (--i != 0);
    return temp & ADDRESS_CRC_MASK;
}

#define DATA_CRC_MESSAGE_BYTES 32
#define DATA_CRC_LENGTH 8
#define DATA_CRC_GENERATOR 0x85

/* __osContDataCrc */
u8 func_80098F0C(u8* data) {
    u32 temp = 0;
    u32 i;
    u32 j;

    for (i = DATA_CRC_MESSAGE_BYTES; i; --i) {
        for (j = (1 << (DATA_CRC_LENGTH - 1)); j; j >>= 1) {
            temp <<= 1;
            if ((*data & j) != 0) {
                if ((temp & (1 << DATA_CRC_LENGTH)) != 0) {
                    temp ^= DATA_CRC_GENERATOR - 1;
                } else {
                    ++temp;
                }
            } else if (temp & (1 << DATA_CRC_LENGTH)) {
                temp ^= DATA_CRC_GENERATOR;
            }
        }
        data++;
    }
    do {
        temp <<= 1;
        if (temp & (1 << DATA_CRC_LENGTH)) {
            temp ^= DATA_CRC_GENERATOR;
        }
    } while (++i < DATA_CRC_LENGTH);
    return temp;
}
