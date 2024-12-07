#include "common.h"

#define SAVE_FILE_SIZE 0x1F8

typedef struct unkfunc_8001AFD8 {
    s16 unk0;
    struct unkfunc_8001AFD8* unk4; //is this correct?
    s16 unk8;
} unkfunc_8001AFD8;

typedef struct unkfunc_8007EE0C {
    void* GetEepTypeFunc; //func pointer
    unkfunc_8001AFD8* unk4; //is this correct?
    s32 unk8;
    OSMesgQueue* mesgQueue;
} unkfunc_8007EE0C;

typedef struct UnkEep {
/* 0x00 */ u16 dest;
/* 0x04 */ u8* src;
/* 0x08 */ u16 size;
} UnkEep;

s32 func_800195E0(void);
s32 func_80019540(UnkEep* arg0);
s32 func_80019438(UnkEep* arg0);
s32 GetEepType(s8** arg0);

extern u8 D_800D1B20[];
// extern u8 D_800D1B28[];
extern OSMesgQueue D_800EE960;
extern u8 D_800C30B0[];

s32 GetEepType(s8** arg0) {
    s32 eepromProbeResult;
    s32 var_s1;
    s16 i;

    var_s1 = 0;
    eepromProbeResult = osEepromProbe(&D_800EE960);

    if (!(eepromProbeResult)) {
        return EEPROM_TYPE_4K;
    }

    if (osEepromLongRead(&D_800EE960, 0, D_800D1B20, (EEPROM_MAXBLOCKS * EEPROM_BLOCK_SIZE)) != 0) {
        return EEPROM_TYPE_16K;
    }

    i = 0;
    if (D_800C30B0[i] != 0) {
        while (1) {
            if (D_800D1B20[i] != D_800C30B0[i]) {
                var_s1 = 1;
                //Write "HUDSON\0\0" header
                for (i = 0; i < 8; i++) {
                    D_800D1B20[i] = D_800C30B0[i];
                }

                for (i = 8; i < EEPROM_MAXBLOCKS * EEPROM_BLOCK_SIZE; i++) {
                    D_800D1B20[i] = 0;
                }

                //read all of save data except hudson header
                if (osEepromLongWrite(&D_800EE960, 1, &D_800D1B20[8], SAVE_FILE_SIZE) != 0) {
                    return EEPROM_TYPE_16K;
                }
                //read husdon header
                if (osEepromLongWrite(&D_800EE960, 0, &D_800D1B20[0], EEPROM_BLOCK_SIZE) == 0) {
                    **arg0 = var_s1;
                    return 0;
                }
                return EEPROM_TYPE_16K;
            }
            i++;
            if (D_800C30B0[i] == 0) {
                break;
            }
        }
    }
    **arg0 = var_s1;
    return 0;
}

s32 func_80019408(unkfunc_8001AFD8* arg0) {
    unkfunc_8007EE0C sp10;
    unkfunc_8001AFD8* sp20 = arg0; //?

    return func_800642FC(&sp10, &GetEepType, &sp20, 1);
}

s32 func_80019438(UnkEep* arg0) {
    u8 eepromBlockCount;
    s16 i;
    s32 alignmentOffset;
    s32 startOffset;

    if (arg0->dest >= 8) {
        for (i = 0; i < arg0->size; i++) {
            if (arg0->dest + i >= (EEPROM_MAXBLOCKS * EEPROM_BLOCK_SIZE)) {
                break;
            }
            D_800D1B20[arg0->dest + i] = arg0->src[i];
        }
        
        eepromBlockCount = (arg0->dest / EEPROM_BLOCK_SIZE);
        startOffset = ((u8)arg0->size + ((u8)arg0->dest & 7) + 7) & 0xF8;
        return (osEepromLongWrite(&D_800EE960, eepromBlockCount, &D_800D1B20[eepromBlockCount * EEPROM_BLOCK_SIZE], startOffset) != 0) * 2;
    }
    return 2;
}

void func_80019504(s32 arg0, void* arg1, s16 arg2) {
    unkfunc_8007EE0C sp10;
    UnkEep sp20;

    sp20.dest = arg0 + 8;
    sp20.src = arg1;
    sp20.size = arg2;

    func_800642FC(&sp10, func_80019438, &sp20, 1);
}

s32 func_80019540(UnkEep* arg0) {
    if (osEepromLongRead(&D_800EE960, 0, D_800D1B20, (EEPROM_MAXBLOCKS * EEPROM_BLOCK_SIZE)) != 0) {
        return 2;
    }
    bcopy(&D_800D1B20[arg0->dest], arg0->src, arg0->size);
    return 0;
}

void func_800195A4(s32 eepromAbsAddr, u16* src, s16 size) {
    unkfunc_8007EE0C sp10;
    UnkEep sp20;

    sp20.dest = eepromAbsAddr + EEPROM_BLOCK_SIZE; //?
    sp20.src = src;
    sp20.size = size;

    func_800642FC(&sp10, (HuSiFunc)func_80019540, &sp20, 1);
}

s32 func_800195E0(void) {
    return (osEepromWrite(&D_800EE960, 0, &D_800C30B0[1]) != 0) * 2;
}

s32 func_80019614(UnkEep* arg0) {
    unkfunc_8007EE0C sp10;

    return func_800642FC(&sp10, (HuSiFunc)func_800195E0, 0, 1);
}

s32 GetSaveFileChecksum(u16 checksumAddrOffset, u16 size) {
    u16 offset;
    u16 checksumTotal;

    checksumTotal = 0;
    checksumAddrOffset += EEPROM_BLOCK_SIZE;

    while (size--) {
        offset = checksumAddrOffset;
        checksumAddrOffset++;
        checksumTotal += D_800D1B20[offset];
        if ((checksumAddrOffset) >= (EEPROM_MAXBLOCKS * EEPROM_BLOCK_SIZE)) {
            break;
        }
    }
    return checksumTotal;
}
