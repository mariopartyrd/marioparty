#ifndef SDK_LEO_H
#define SDK_LEO_H

// libleo (64DD) units of the SDK pass (821F0.c-83960.c). Every libleo unit was built with IDO,
// not KMC GCC, so their C is NON_MATCHING (logic-equivalent) like 80770.c and 80BE0.c. The
// layouts below repeat 80770.c's/80BE0.c's local ones (same offsets).

typedef struct LEOCmdHeader {
    /* 0x00 */ u8 command;
    /* 0x01 */ u8 reserve1;
    /* 0x02 */ u8 control;
    /* 0x03 */ u8 reserve3;
    /* 0x04 */ u8 status;
    /* 0x05 */ u8 sense_code;
    /* 0x06 */ u8 reserve6;
    /* 0x07 */ u8 reserve7;
    /* 0x08 */ OSMesgQueue* post;
} LEOCmdHeader; // sizeof 0xC

typedef struct LEOCmdRead {
    /* 0x00 */ LEOCmdHeader header;
    /* 0x0C */ u32 lba;
    /* 0x10 */ u32 xfer_blks;
    /* 0x14 */ u8* buff_ptr;
    /* 0x18 */ u32 rw_bytes;
} LEOCmdRead; // sizeof 0x1C

// Current transfer target (LEOtgt_param)
typedef struct LEOTgtParam {
    /* 0x00 */ u16 lba;
    /* 0x02 */ u16 cylinder;
    /* 0x04 */ u16 blk_bytes;
    /* 0x06 */ u8 sec_bytes;
    /* 0x07 */ u8 head;
    /* 0x08 */ u8 zone;
    /* 0x09 */ u8 rdwr_blocks;
    /* 0x0A */ u8 start_block;
} LEOTgtParam;

extern s32 D_800C63D0;          // __leoActive
extern u8 D_800E87E8;           // disk type
extern LEOTgtParam D_800E87F0;  // LEOtgt_param
extern u32 D_800E87FC;          // non-zero once the system area has been read
extern u8 D_800E7B00[];         // system area (defect counts at 0x08, defect tracks at 0x20)
extern u8 D_800CBBF8[];         // sectors' bytes per zone
extern u16 D_800CBC04[];        // block bytes per zone
extern u16 D_800CBC16[];        // = D_800CBC18 - 1 element (start lba of the previous vzone)
extern u16 D_800CBC18[][16];    // end lba of each vzone, per disk type
extern u16 D_800CBCF8[];        // start cylinder of each physical zone
extern u8 D_800CBD18[][16];     // physical zone of each vzone, per disk type
extern u16 D_800CBD86[];        // outer cylinder of each zone (head 1)

void func_8007FD44(LEOCmdRead* cmd); // leoCommand
u16 func_800815F0(u32 lba);          // leoLba_to_phys
u16 func_800817E4(u32 lba);          // leoLba_to_vzone

// LEO_COMMAND_INQUIRY's block (LeoC?CreateLeoManager)
typedef struct LEOCmdInquiry {
    /* 0x00 */ LEOCmdHeader header;
    /* 0x0C */ u8 dev_type;
    /* 0x0D */ u8 version;
    /* 0x0E */ u8 dev_num;
    /* 0x0F */ u8 leo_bios_ver;
    /* 0x10 */ u32 reserve5[2];
} LEOCmdInquiry; // sizeof 0x18

typedef struct LEOVersion {
    /* 0x00 */ u8 driver;
    /* 0x01 */ u8 drive;
    /* 0x02 */ u8 deviceType;
    /* 0x03 */ u8 ndevices;
} LEOVersion;

#include "PR/rcp.h"

#define LEO_IO_READ(addr) (*(vu32*)((addr) | 0xA0000000))
#define LEO_IO_WRITE(addr, data) (*(vu32*)((addr) | 0xA0000000) = (u32)(data))

extern LEOVersion D_800E8800;   // __leoVersion
extern u8 D_800E9800[];         // stack end for the 64DD interrupt handler
extern OSPiHandle D_800E9890;   // __DriveRomHandle
extern s32 D_800C63E0;          // osDriveRomInit's first-call flag

void __osPiGetAccess(void);
void __osPiRelAccess(void);
u32 __osDisableInt(void);
void __osRestoreInt(u32 mask);
s32 __osLeoInterrupt(void);
void func_80093660(s32 intr, s32 (*handler)(void), void* stackEnd); // __osSetHWIntrRoutine
void func_8007FB70(OSPri comPri, OSPri intPri, OSMesg* cmdBuf, s32 cmdMsgCnt); // leoInitialize
void func_8007FF34(void);           // __leoSetReset
OSPiHandle* osLeoDiskInit(void);
OSPiHandle* func_80082660(void);    // osDriveRomInit
s32 func_800827C0(void);            // LeoDriveExist (the real one)

#endif
