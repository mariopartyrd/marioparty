#include "common.h"
#include "sdk_leo.h"

// libleo LeoSeek, LeoReadWrite (IDO-compiled: NON_MATCHING, see sdk_leo.h).

#ifdef NON_MATCHING
s32 func_80081990(LEOCmdRead* cmd, u32 lba, OSMesgQueue* mq) {
    if (D_800C63D0 == 0) {
        return -1;
    }
    cmd->header.command = 0xC; // seek
    cmd->header.reserve1 = 0;
    cmd->header.control = 0;
    cmd->header.reserve3 = 0;
    cmd->lba = lba;
    if (mq != NULL) {
        cmd->header.control = 0x80; // post
        cmd->header.post = mq;
    }
    func_8007FD44(cmd);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/82590", func_80081990);
#endif

#ifdef NON_MATCHING
s32 func_800819F0(LEOCmdRead* cmd, s32 direction, u32 lba, void* vaddr, u32 nlbas, OSMesgQueue* mq) {
    if (D_800C63D0 == 0) {
        return -1;
    }
    cmd->header.command = (direction == 0) ? 5 : 6; // read, write
    cmd->header.reserve1 = 0;
    cmd->header.control = (mq != NULL) ? 0x80 : 0;
    cmd->header.reserve3 = 0;
    cmd->header.post = mq;
    cmd->lba = lba;
    cmd->buff_ptr = vaddr;
    cmd->xfer_blks = nlbas;
    func_8007FD44(cmd);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/82590", func_800819F0);
#endif
