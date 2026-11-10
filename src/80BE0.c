#include "common.h"

// 64DD driver (libleo) command thread and mechanism control. This unit was built with
// IDO, not KMC GCC: its register allocation (t6, t7, ... temporaries, ra at 0x14(sp))
// cannot be reproduced, so every function except the trivial leoChk_mecha_int is kept as
// C behind NON_MATCHING for the PC port.

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

// Current transfer target (splat also labels +2 and +6 separately)
typedef struct LEOTgtParam {
    /* 0x00 */ u16 lba;
    /* 0x02 */ u16 cylinder;
    /* 0x04 */ u16 blk_bytes;
    /* 0x06 */ u8 sec_bytes;
    /* 0x07 */ u8 head;
    /* 0x08 */ u8 unk8;
    /* 0x09 */ u8 rdwr_blocks;
    /* 0x0A */ u8 unkA;
} LEOTgtParam;

// C1 error report handed to the interrupt thread
typedef struct LEORwInfo {
    /* 0x00 */ u8* dram;
    /* 0x04 */ u8* c2end;
    /* 0x08 */ u8 errSector[4];
    /* 0x0C */ u8 errNum;
    /* 0x0D */ u8 secBytes;
    /* 0x0E */ u16 blkBytes;
} LEORwInfo; // sizeof 0x10

u32 func_80080170(void);
u8 func_8008076C(void);
void func_800807D4(void);
u8 func_800808BC(void);
u8 func_800809D0(void);
u8 func_80080ADC(u32 asic_cmd);
u8 func_80080BC4(u32 asic_cmd);
u8 func_80080D78(u32 asic_cmd, u32 asic_data);
u8 func_80080E20(u32 asic_cmd);
u8 func_80080E70(u32 asic_cmd, u32 asic_data);
u8 func_80080F94(void);
u8 func_8008100C(u16 rwmode);
s32 func_800810AC(s32 control);
s32 func_80081100(u32 sense);
void func_80081250(void);
void func_80081320(u16 rwmode);
void func_800815F0(u16 lba);

extern u32 D_800CBB70[16];
extern u32 D_800CBBB0[16];
extern OSMesg D_800E7A90;
extern OSMesgQueue D_800E7A98;
extern u32 D_800E7AB0;
extern u32 D_800E7AB4;
extern u32 D_800E7AC0[16];
extern OSThread D_800E7D98;
extern OSMesgQueue D_800E8748;
extern OSMesgQueue D_800E8760;
extern OSMesgQueue D_800E8778;
extern OSMesgQueue D_800E8790;
extern u8* D_800E87D4;
extern LEOCmdRead* D_800E87D8;
extern u32 D_800E87DC;
extern u32 D_800E87E0;
extern u8 D_800E87E4;
extern u16 D_800E87E6;
extern LEOTgtParam D_800E87F0;
extern u8 D_800E9A00[0x3A0];
extern u8 D_800E9DA0[0x3A0];
extern LEORwInfo D_800EA140;
extern OSPiHandle* D_800EA150;
extern OSIoMesg D_800EA158;
extern s32 D_800EA170;

// IDO-compiled libleo (read/write command thread)
#ifdef NON_MATCHING
void func_8007FFE0(void* arg) {
    u32 blocks;
    u32 n;
    u32 sense;

    osCreateMesgQueue(&D_800E7A98, &D_800E7A90, 1);
    while (TRUE) {
        osStopThread(&D_800E7D98);
        blocks = D_800E87D8->xfer_blks;
        D_800E87D4 = D_800E87D8->buff_ptr;
        while (TRUE) {
            func_800815F0(D_800E87F0.lba);
            if (D_800E87E6 & 0x8000) {
                sense = func_8008100C(1);
            } else {
                sense = func_8008100C(0);
            }
            if (sense != 0) {
                break;
            }
            if (D_800E87E6 & 0x2000) {
                n = 1;
                D_800E87F0.rdwr_blocks = 1;
            } else {
                n = D_800E87F0.rdwr_blocks;
                if (blocks < n) {
                    n = blocks & 0xFF;
                    D_800E87F0.rdwr_blocks = blocks;
                }
            }
            blocks -= n;
            D_800E87F0.lba += n;
            sense = func_80080170();
            if (sense != 0) {
                break;
            }
            D_800E87D8->rw_bytes = D_800E87D4 - D_800E87D8->buff_ptr;
            if (blocks == 0) {
                sense = 0x90000;
                break;
            }
        }
        osSendMesg(&D_800E8778, (OSMesg)sense, OS_MESG_BLOCK);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/80BE0", func_8007FFE0);
#endif

// IDO-compiled libleo (one sector transfer with C1/C2 error handling and retries)
#ifdef NON_MATCHING
u32 func_80080170(void) {
    LEORwInfo info;
    u32 sense;
    u16 blkBytes;
    s32 retry;
    s32 i;
    __OSBlockInfo* blk;
    u8* c2;
    u32* c2w;

    blkBytes = D_800E87F0.blk_bytes;
    info.secBytes = D_800E87F0.sec_bytes;
    if (D_800E87E6 & 0x2000) {
        blkBytes = info.secBytes;
    }
    info.dram = D_800E87D4;
    D_800E87D4 += blkBytes;
    info.blkBytes = blkBytes;
    if (D_800E87F0.rdwr_blocks == 2) {
        D_800E87D4 += blkBytes;
        info.blkBytes = blkBytes;
    }
    retry = 0;

    while (TRUE) {
        D_800EA150->transferInfo.transferMode = 1;
        D_800EA150->transferInfo.blockNum = 0;
        D_800EA150->transferInfo.block[0].C1ErrNum = 0;
        D_800EA150->transferInfo.block[0].sectorSize = info.secBytes;
        D_800EA150->transferInfo.block[0].dramAddr = info.dram;
        D_800EA150->transferInfo.block[0].C2Addr = D_800E9A00;
        if (D_800E87E6 & 0x2000) {
            D_800E87F0.rdwr_blocks = 1;
            D_800EA150->transferInfo.transferMode = 3;
        } else if (D_800E87F0.rdwr_blocks == 2) {
            D_800EA150->transferInfo.transferMode = 2;
            D_800EA150->transferInfo.block[1] = D_800EA150->transferInfo.block[0];
            D_800EA150->transferInfo.block[1].C2Addr = D_800E9DA0;
            D_800EA150->transferInfo.block[1].dramAddr = (u8*)D_800EA150->transferInfo.block[1].dramAddr + info.blkBytes;
        }

        sense = func_8008076C();
        if (sense == 0) {
            if (D_800E87E6 & 0x8000) {
                func_80081320(1);
            } else {
                func_80081320(0);
            }
            func_800807D4();
            D_800EA150->transferInfo.bmCtlShadow = D_800E87DC;
            D_800EA150->transferInfo.seqCtlShadow = D_800E87E0;
            if (D_800E87E6 & 0x8000) {
                D_800EA150->transferInfo.cmdType = OS_WRITE;
                osWritebackDCache(info.dram, info.blkBytes * D_800E87F0.rdwr_blocks);
                osEPiStartDma(D_800EA150, &D_800EA158, OS_WRITE);
                osRecvMesg(&D_800E8790, NULL, OS_MESG_BLOCK);
                D_800E87DC = D_800EA150->transferInfo.bmCtlShadow;
                D_800E87E0 = D_800EA150->transferInfo.seqCtlShadow;
                sense = D_800EA150->transferInfo.block[D_800EA150->transferInfo.blockNum].errStatus;
                if (sense == 0) {
                    return 0;
                }
                goto error;
            }

            i = 0;
            if (D_800E87E6 & 0x4000) {
                osRecvMesg(&D_800E7A98, NULL, OS_MESG_BLOCK);
                osSendMesg(&D_800E7A98, NULL, OS_MESG_NOBLOCK);
            }
            D_800EA150->transferInfo.cmdType = OS_READ;
            osInvalDCache(info.dram, info.blkBytes * D_800E87F0.rdwr_blocks);
            osEPiStartDma(D_800EA150, &D_800EA158, OS_READ);
            if (D_800E87F0.rdwr_blocks == 0) {
                return 0;
            }
            while (TRUE) {
                osRecvMesg(&D_800E8790, NULL, OS_MESG_BLOCK);
                blk = &D_800EA150->transferInfo.block[i];
                D_800E87DC = D_800EA150->transferInfo.bmCtlShadow;
                D_800E87E0 = D_800EA150->transferInfo.seqCtlShadow;
                sense = blk->errStatus;
                if (sense != 0) {
                    goto error;
                }
                if (D_800E87E6 & 0x2000) {
                    return 0;
                }
                if (blk->C1ErrNum != 0) {
                    if (blk->C1ErrSector[0] < 0x55) {
                        if (D_800E87F0.rdwr_blocks == 1) {
                            osEPiReadIo(D_800EA150, 0x05000514, &sense);
                            if (sense & 0x10000000) {
                                sense = 4;
                                goto error;
                            }
                        }
                        if (i == 0) {
                            c2 = D_800E9A00;
                        } else {
                            c2 = D_800E9DA0;
                        }
                        info.c2end = c2 + info.secBytes * 4;
                        osInvalDCache(c2, info.secBytes * 4);
                        blk = &D_800EA150->transferInfo.block[i];
                        info.errNum = blk->C1ErrNum;
                        info.errSector[0] = blk->C1ErrSector[0];
                        info.errSector[1] = blk->C1ErrSector[1];
                        info.errSector[2] = blk->C1ErrSector[2];
                        info.errSector[3] = blk->C1ErrSector[3];
                        osRecvMesg(&D_800E7A98, NULL, OS_MESG_BLOCK);
                        D_800E87E6 |= 0x4000;
                        D_800EA140 = info;
                        osSendMesg(&D_800E8778, (OSMesg)0x80000, OS_MESG_BLOCK);
                    }
                } else if (D_800E87F0.rdwr_blocks == 1) {
                    c2w = (u32*)(D_800E9A00 + i * 0x3A0);
                    if ((c2w[3] | c2w[0] | c2w[1] | c2w[2]) != 0) {
                        sense = 0x17;
                        goto error;
                    }
                }
                i++;
                info.dram += info.blkBytes;
                D_800E87F0.unkA ^= 1;
                D_800E87F0.rdwr_blocks--;
                if (D_800E87F0.rdwr_blocks == 0) {
                    return 0;
                }
            }
        }

    error:
        if (sense == 0x16) {
            sense = func_800808BC();
        }
        while (TRUE) {
            if (func_80081100(sense) != 0 || (D_800E87E6 & 0x1000)) {
                return sense;
            }
            if (retry == 0x40) {
                return sense;
            }
            retry++;
            if ((retry & 7) == 0) {
                sense = func_80080E70(0x30001, 0);
                if (sense != 0) {
                    continue;
                }
            }
            if (sense == 0x18 || (sense == 0x17 && retry == 0x20)) {
                sense = func_80080F94();
                if (sense != 0) {
                    continue;
                }
            }
            if (D_800E87E6 & 0x8000) {
                sense = func_8008100C(1);
            } else {
                sense = func_8008100C(0);
            }
            if (sense == 0) {
                break;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/80BE0", func_80080170);
#endif

// IDO-compiled libleo
#ifdef NON_MATCHING
u8 func_8008076C(void) {
    u32 stat;
    u8 sense;

    sense = func_80080E20(0x10001);
    if (sense == 0) {
        osEPiReadIo(D_800EA150, 0x0500050C, &stat);
        if ((stat & 0x60000000) != 0x60000000) {
            sense = 0x18;
        }
    }
    return sense;
}
#else
INCLUDE_ASM("asm/nonmatchings/80BE0", func_8008076C);
#endif

// IDO-compiled libleo (buffer manager control register)
#ifdef NON_MATCHING
void func_800807D4(void) {
    osEPiWriteIo(D_800EA150, 0x05000510, D_800E87DC | 0x10000000);
    osEPiWriteIo(D_800EA150, 0x05000510, D_800E87DC);
    if (D_800E87F0.unkA != 0) {
        D_800E87DC = 0x5A0000;
    } else {
        D_800E87DC = 0;
    }
    if (!(D_800E87E6 & 0x8000)) {
        D_800E87DC |= 0x40000000;
    }
    if (D_800E87F0.rdwr_blocks == 2) {
        D_800E87DC |= 0x02000000;
    }
    osEPiWriteIo(D_800EA150, 0x05000510, D_800E87DC);
}
#else
INCLUDE_ASM("asm/nonmatchings/80BE0", func_800807D4);
#endif

// IDO-compiled libleo
#ifdef NON_MATCHING
u8 func_800808BC(void) {
    u32 stat;
    u32 bmStat;

    osEPiReadIo(D_800EA150, 0x05000514, &bmStat);
    osEPiWriteIo(D_800EA150, 0x05000510, D_800E87DC | 0x10000000);
    osEPiWriteIo(D_800EA150, 0x05000510, D_800E87DC);
    if (bmStat & 0x04000000) {
        return 0x31;
    }
    if (bmStat & 0x10000000) {
        return 4;
    }
    if (bmStat & 0x42000000) {
        if (D_800E87E6 & 0x8000) {
            return 0x16;
        }
        return 0x17;
    }
    if (!(bmStat & 0x80000000)) {
        osEPiReadIo(D_800EA150, 0x0500050C, &stat);
        if ((stat & 0x60000000) == 0x60000000) {
            return 0x19;
        }
    }
    return 0x18;
}
#else
INCLUDE_ASM("asm/nonmatchings/80BE0", func_800808BC);
#endif

// IDO-compiled libleo (leoAnalize_asic_status)
#ifdef NON_MATCHING
u8 func_800809D0(void) {
    u32 stat;

    osEPiReadIo(D_800EA150, 0x05000508, &D_800E7AB0);
    stat = D_800E7AB0 ^ 0x01000000;
    if (stat & 0x01C3FFFF) {
        if (stat & 0x01C1FFFF) {
            D_800E87E4 = 0;
        }
        if (stat & 0xFFFF) {
            return 0x29;
        }
        if ((stat & 0xC00000) == 0x800000) {
            return 3;
        }
        if (stat & 0x400000) {
            D_800E7AB4 |= 2;
            return 0x2B;
        }
        if (stat & 0x01000000) {
            return 0x31;
        }
        if (stat & 0x10000) {
            D_800E7AB4 |= 1;
            return 0x2F;
        }
        if (stat & 0x20000) {
            return 0x15;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/80BE0", func_800809D0);
#endif

// IDO-compiled libleo (leoChk_asic_ready)
#ifdef NON_MATCHING
u8 func_80080ADC(u32 asic_cmd) {
    u32 sense;

    sense = func_800809D0();
    switch (sense) {
        case 0x15:
            return 0;
        case 0x2F:
            if (asic_cmd == 0x80000) {
                return 0;
            }
            // fallthrough
        case 0x2B:
            if (D_800E7AB0 & 0x800000) {
                return sense;
            }
            if (asic_cmd == 0x90000) {
                return 0;
            }
            if (func_800810AC(0) != 0) {
                return 0x25;
            }
            osEPiWriteIo(D_800EA150, 0x05000508, 0x90000);
            if (func_800810AC(1) != 0) {
                return 0x25;
            }
            return sense;
        case 0x31:
            if (asic_cmd & 1) {
                return sense;
            }
            return 0;
        default:
            return sense;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/80BE0", func_80080ADC);
#endif

// IDO-compiled libleo (leoChk_done_status)
#ifdef NON_MATCHING
u8 func_80080BC4(u32 asic_cmd) {
    u32 sense;
    u32 data;
    u8 sense2;

    sense = func_800809D0();
    switch (sense) {
        case 0x2B:
        case 0x2F:
            if (D_800E7AB0 & 0x800000) {
                return sense;
            }
            if (func_800810AC(0) != 0) {
                return 0x25;
            }
            osEPiWriteIo(D_800EA150, 0x05000508, 0x90000);
            if (func_800810AC(1) != 0) {
                return 0x25;
            }
            return sense;
        case 0x31:
            if (!(asic_cmd & 1)) {
                return 0;
            }
            return sense;
        case 0x15:
            osEPiWriteIo(D_800EA150, 0x05000500, 0);
            if (func_800810AC(0) != 0) {
                return 0x25;
            }
            osEPiWriteIo(D_800EA150, 0x05000508, 0xC0000);
            if (func_800810AC(1) != 0) {
                return 0x25;
            }
            osEPiReadIo(D_800EA150, 0x05000500, &data);
            sense2 = func_80080ADC(0xC0000);
            if (sense2 != 0) {
                return sense2;
            }
            if (data & 0x10000) {
                return 2;
            }
            if (data & 0x20000) {
                return 0x18;
            }
            if (data & 0x40000) {
                return 1;
            }
            if (data & 0x80000) {
                return 0x15;
            }
            if (data & 0x200000) {
                return 0xB;
            }
            return 0x29;
        default:
            return sense;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/80BE0", func_80080BC4);
#endif

// IDO-compiled libleo (leoSend_asic_cmd_i)
#ifdef NON_MATCHING
u8 func_80080D78(u32 asic_cmd, u32 asic_data) {
    u8 sense;

    sense = func_80080ADC(asic_cmd);
    if (sense != 0) {
        D_800E87D8->header.sense_code = sense;
        return D_800E87D8->header.sense_code;
    }
    osEPiWriteIo(D_800EA150, 0x05000500, asic_data);
    if (func_800810AC(0) != 0) {
        D_800E87D8->header.sense_code = 0x25;
        return D_800E87D8->header.sense_code;
    }
    osEPiWriteIo(D_800EA150, 0x05000508, asic_cmd);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/80BE0", func_80080D78);
#endif

// IDO-compiled libleo (leoWait_mecha_cmd_done)
#ifdef NON_MATCHING
u8 func_80080E20(u32 asic_cmd) {
    u8 sense;

    if (func_800810AC(1) != 0) {
        return 0x25;
    }
    sense = func_80080BC4(asic_cmd);
    if (sense != 0) {
        return sense;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/80BE0", func_80080E20);
#endif

// IDO-compiled libleo (leoSend_asic_cmd_w)
#ifdef NON_MATCHING
u8 func_80080E70(u32 asic_cmd, u32 asic_data) {
    u8 sense;

    sense = func_80080D78(asic_cmd, asic_data);
    if (sense != 0) {
        return sense;
    }
    return func_80080E20(asic_cmd);
}
#else
INCLUDE_ASM("asm/nonmatchings/80BE0", func_80080E70);
#endif

// IDO-compiled libleo (leoSend_asic_cmd_w_nochkDiskChange)
#ifdef NON_MATCHING
u8 func_80080EA8(u32 asic_cmd, u32 asic_data) {
    u8 sense;

    sense = func_80080ADC(asic_cmd);
    if (sense != 0x2F && sense != 0) {
        D_800E87D8->header.sense_code = sense;
        return D_800E87D8->header.sense_code;
    }
    osEPiWriteIo(D_800EA150, 0x05000500, asic_data);
    if (func_800810AC(0) != 0) {
        D_800E87D8->header.sense_code = 0x25;
        return D_800E87D8->header.sense_code;
    }
    osEPiWriteIo(D_800EA150, 0x05000508, asic_cmd);
    if (func_800810AC(1) != 0) {
        return 0x25;
    }
    sense = func_80080BC4(asic_cmd);
    if (sense != 0x2F && sense != 0) {
        return sense;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/80BE0", func_80080EA8);
#endif

// IDO-compiled libleo (leoDetect_index_w)
#ifdef NON_MATCHING
u8 func_80080F94(void) {
    return func_80080E70(0xE0001, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/80BE0", func_80080F94);
#endif

// IDO-compiled libleo (leoRecal_i)
#ifdef NON_MATCHING
u8 func_80080FBC(void) {
    return func_80080D78(0x30001, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/80BE0", func_80080FBC);
#endif

// IDO-compiled libleo (leoRecal_w)
#ifdef NON_MATCHING
u8 func_80080FE4(void) {
    return func_80080E70(0x30001, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/80BE0", func_80080FE4);
#endif

// IDO-compiled libleo (leoSeek_i)
#ifdef NON_MATCHING
u8 func_8008100C(u16 rwmode) {
    u32 tgt_tk = ((D_800E87F0.head << 12) + D_800E87F0.cylinder) << 16;

    if (rwmode == 0) {
        return func_80080D78(0x10001, tgt_tk);
    } else {
        return func_80080D78(0x20001, tgt_tk);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/80BE0", func_8008100C);
#endif

// IDO-compiled libleo (leoSeek_w)
#ifdef NON_MATCHING
u8 func_80081070(void) {
    u8 sense;

    sense = func_8008100C(0);
    if (sense != 0) {
        return sense;
    }
    return func_80080E20(0x10001);
}
#else
INCLUDE_ASM("asm/nonmatchings/80BE0", func_80081070);
#endif

// IDO-compiled libleo (leoRecv_event_mesg)
#ifdef NON_MATCHING
s32 func_800810AC(s32 control) {
    OSMesg msg;

    if (osRecvMesg(&D_800E8760, &msg, control) == 0 && msg == (OSMesg)0xA0000) {
        func_80081250();
        return 0xFF;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/80BE0", func_800810AC);
#endif

// IDO-compiled libleo (leoChk_err_retry)
#ifdef NON_MATCHING
s32 func_80081100(u32 sense) {
    if (D_800EA170 == 0xC || D_800EA170 == 8) {
        switch (sense) {
            case 0x2B:
                D_800E7AB4 |= 2;
                // fallthrough
            case 2:
            case 3:
            case 0x25:
            case 0x29:
            case 0x2A:
            case 0x31:
                D_800E87E4 = 0;
                return -1;
        }
    } else {
        switch (sense) {
            case 0x2B:
                D_800E7AB4 |= 2;
                // fallthrough
            case 0x2F:
                D_800E7AB4 |= 1;
                // fallthrough
            case 2:
            case 3:
            case 0x25:
            case 0x29:
            case 0x2A:
            case 0x31:
                D_800E87E4 = 0;
                return -1;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/80BE0", func_80081100);
#endif

// IDO-compiled libleo (leoChk_cur_drvmode)
#ifdef NON_MATCHING
u8 func_80081210(void) {
    u8 mode = 0;

    if (!(D_800E7AB0 & 0x01000000)) {
        mode = 1;
    }
    if (D_800E7AB0 & 0x80000) {
        mode |= 2;
    }
    if (D_800E7AB0 & 0x100000) {
        mode |= 4;
    }
    return mode;
}
#else
INCLUDE_ASM("asm/nonmatchings/80BE0", func_80081210);
#endif

// IDO-compiled libleo (leoDrive_reset)
#ifdef NON_MATCHING
void func_80081250(void) {
    osEPiWriteIo(D_800EA150, 0x05000520, 0xAAAA0000);
}
#else
INCLUDE_ASM("asm/nonmatchings/80BE0", func_80081250);
#endif

// leoChk_mecha_int: the only function here GCC emits identically
u32 func_80081280(void) {
    return D_800E7AB4;
}

// IDO-compiled libleo
#ifdef NON_MATCHING
u8 func_8008128C(void) {
    if (D_800E7AB4 & 2) {
        return 0x2B;
    }
    if (D_800E7AB4 & 1) {
        return 0x2F;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/80BE0", func_8008128C);
#endif

// IDO-compiled libleo
#ifdef NON_MATCHING
void func_800812C0(void) {
    D_800E7AB4 &= ~2;
}
#else
INCLUDE_ASM("asm/nonmatchings/80BE0", func_800812C0);
#endif

// IDO-compiled libleo
#ifdef NON_MATCHING
void func_800812DC(void) {
    D_800E7AB4 &= ~1;
}
#else
INCLUDE_ASM("asm/nonmatchings/80BE0", func_800812DC);
#endif

// IDO-compiled libleo
#ifdef NON_MATCHING
void func_800812F8(void) {
    D_800E7AB4 |= 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/80BE0", func_800812F8);
#endif

// IDO-compiled libleo
#ifdef NON_MATCHING
void func_80081310(void) {
    D_800E7AB4 = 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/80BE0", func_80081310);
#endif

// IDO-compiled libleo (leoSet_mseq: load the read or write microsequence)
#ifdef NON_MATCHING
void func_80081320(u16 rwmode) {
    u32* src;
    u8 i;
    u32 secm1;
    u32 sec;

    D_800E87E0 &= ~0x40000000;
    osEPiWriteIo(D_800EA150, 0x05000518, D_800E87E0);
    if (rwmode == 1) {
        src = D_800CBBB0;
    } else {
        src = D_800CBB70;
    }
    for (i = 0; i < 16; i++) {
        D_800E7AC0[i] = *src++;
    }
    secm1 = D_800E87F0.sec_bytes - 1;
    D_800E7AC0[4] |= secm1 << 8;
    osWritebackDCache(D_800E7AC0, sizeof(D_800E7AC0));
    D_800EA158.dramAddr = D_800E7AC0;
    D_800EA158.devAddr = 0x05000580;
    D_800EA158.size = sizeof(D_800E7AC0);
    D_800EA150->transferInfo.cmdType = OS_OTHERS;
    osEPiStartDma(D_800EA150, &D_800EA158, OS_WRITE);
    osRecvMesg(&D_800E8790, NULL, OS_MESG_BLOCK);
    osEPiWriteIo(D_800EA150, 0x05000530, ((secm1 + 7) | 0x5900) << 16);
    sec = secm1 << 8;
    if (D_800E87E6 & 0x800) {
        sec += 0x100;
    }
    osEPiWriteIo(D_800EA150, 0x05000528, sec << 8);
    D_800E87E0 |= 0x40000000;
    osEPiWriteIo(D_800EA150, 0x05000518, D_800E87E0);
}
#else
INCLUDE_ASM("asm/nonmatchings/80BE0", func_80081320);
#endif

// IDO-compiled libleo (flush the command queue: every pending command is terminated)
#ifdef NON_MATCHING
void func_800814D0(void) {
    LEOCmdHeader* cmd;

    while (osRecvMesg(&D_800E8748, (OSMesg*)&cmd, OS_MESG_NOBLOCK) == 0) {
        cmd->sense_code = 0x22;
        cmd->status = 2;
        if (cmd->control & 0x80) {
            osSendMesg(cmd->post, (OSMesg)0x22, OS_MESG_BLOCK);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/80BE0", func_800814D0);
#endif

// IDO-compiled libleo
#ifdef NON_MATCHING
void func_80081578(void) {
    u8 sense;

    sense = func_800809D0();
    switch (sense) {
        case 3:
        case 0x29:
        case 0x2B:
            D_800E87D8->header.sense_code = sense;
            D_800E87D8->header.status = 2;
            break;
        default:
            D_800E87D8->header.sense_code = 0;
            D_800E87D8->header.status = 0;
            break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/80BE0", func_80081578);
#endif

INCLUDE_RODATA("asm/nonmatchings/80BE0", D_800CBB70);

INCLUDE_RODATA("asm/nonmatchings/80BE0", D_800CBBB0);

INCLUDE_RODATA("asm/nonmatchings/80BE0", D_800CBBF8);

INCLUDE_RODATA("asm/nonmatchings/80BE0", D_800CBC04);

INCLUDE_RODATA("asm/nonmatchings/80BE0", D_800CBC18);

INCLUDE_RODATA("asm/nonmatchings/80BE0", D_800CBCF8);

INCLUDE_RODATA("asm/nonmatchings/80BE0", D_800CBD18);
