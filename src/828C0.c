#include "common.h"
#include "sdk_leo.h"

// libleo LeoCACreateLeoManager (US drives; splat's name for it is LeoDriveExist, the real
// LeoDriveExist is func_800827C0). IDO-compiled: NON_MATCHING, see sdk_leo.h.

#ifdef NON_MATCHING
s32 LeoDriveExist(OSPri comPri, OSPri intPri, OSMesg* cmdBuf, s32 cmdMsgCnt) {
    OSPiHandle* driveRomHandle;
    volatile LEOCmdInquiry cmdBlockInq;
    volatile s32 dummy;
    volatile u32 data;
    u32 stat;

    if (D_800C63D0) {
        return 0;
    }
    if (!func_800827C0()) {
        return 0x29; // LEO_ERROR_DEVICE_COMMUNICATION_FAILURE
    }
    osLeoDiskInit();
    driveRomHandle = func_80082660();
    D_800C63D0 = TRUE;
    func_80093660(1, __osLeoInterrupt, D_800E9800);
    func_8007FB70(comPri, intPri, cmdBuf, cmdMsgCnt);
    if (osResetType == 1) {
        func_8007FF34();
    }
    cmdBlockInq.header.command = 2; // inquiry
    cmdBlockInq.header.reserve1 = 0;
    cmdBlockInq.header.control = 0;
    cmdBlockInq.header.reserve3 = 0;
    func_8007FD44((LEOCmdRead*)&cmdBlockInq);

    dummy = (u32)func_80093660 & 0xA48D3C;
    while (dummy < 0xE00000) {
        dummy += ((((u32)func_8007FD44) & 0xFF) | 0x8A) << 16;
    }

    while (cmdBlockInq.header.status == 8) {
    }
    if (cmdBlockInq.header.status != 0) {
        return cmdBlockInq.header.sense_code;
    }
    D_800E8800.driver = cmdBlockInq.version;
    D_800E8800.drive = 6;
    D_800E8800.deviceType = cmdBlockInq.dev_type;
    D_800E8800.ndevices = cmdBlockInq.dev_num;
    stat = D_800E8800.driver & 0xF;
    if (stat == 4) {
        D_800E87FC = 0;
    } else if ((stat == 3) || (stat == 1)) {
        osEPiReadIo(driveRomHandle, 0x9FF00, &stat);
        if (((stat & 0xFF000000) >> 24) != 4) {
            while (TRUE) {
            }
        }
        data = 0x32F8EB20;
        D_800E87FC = 0x2263EE56;
        data += (u32)&D_800C63D0;
    } else {
        while (TRUE) {
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/828C0", LeoDriveExist);
#endif
