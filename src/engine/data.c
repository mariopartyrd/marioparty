#include "engine/data.h"


extern u16 ContDStkTrg[4];
extern u16 ContBtn[4];

extern u16 D_800F2CF0[4];
extern s16 D_800F32A4[4];
extern u16 D_800F3396[4];
extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern u16 ContDStk[4];

typedef struct mainfsTableHeader {
    s32 dir;
    s32 offsets[3];
} mainfsTableHeader;
typedef struct mainfsEntryInfo {
    u8 *file_bytes;
    s32 size;
    s32 compression_type;
} mainfsEntryInfo;

// typedef struct unkMallocPermStruct {
//     u16 unk0;
//     u16 unk2;
//     s32 unk4;
//     void* unk8;
//     s16 unkC;
//     s16 unkE;
//     u8* unk10;
//     u8* unk14;
// } unkMallocPermStruct;

// deprecated!!
typedef struct HuFileInfoD {
    s16 compType;
    u32 size;
    u8* block;
    s16 unkC;
    s16 unkE;
    void* bytes;
    void* bytesCopy;
} HuFileInfoD;

typedef enum
{
    ARCHIVE_CACHED = 0x2E,
    ARCHIVE_DIRECT,
} EArchiveType;

void func_80014220(void) {
    s16 i;

    u16 *ContDStk_ptr;
    s16 *D_800F32A4_ptr;
    u16 *D_800F2CF0_ptr;
    u16 *ContDStkTrg_ptr;
    u16 *D_800F3396_ptr;

    for (i = 0; i < 4; i++) {
        ContDStk_ptr = (ContDStk + i);
        D_800F3396_ptr = (D_800F3396 + i);
        ContDStkTrg_ptr = (ContDStkTrg + i);
        D_800F2CF0_ptr = (D_800F2CF0 + i);
        D_800F32A4_ptr = (D_800F32A4 + i);

        *(D_800F32A4_ptr) = 0;
        *(D_800F2CF0_ptr) = 0;
        *(ContDStkTrg_ptr) = 0;
        *(D_800F3396_ptr) = 0;
        *(ContDStk_ptr) = 0;
    }
}

void func_8001429C(void) {
    s16 i;
    s32 sign;
    u16 btn;
    s8 stk;

    for (i = 0; i < 4; ++i) {
        D_800F3396[i] = ContDStk[i];
        btn = ContBtn[i];
        stk = ContStkX[i];
        sign = (stk >> 7) | 1;
        if ((stk * sign) - 30 > 0) {
            if (sign > 0) {
                btn = (btn & 0xFDFF) | 0x100;
            } else {
                btn = (btn & 0xFEFF) | 0x200;
            }
        }
        stk = ContStkY[i];
        sign = (stk >> 7) | 1;
        if ((stk * sign) - 30 > 0) {
            if (sign > 0) {
                btn = (btn & 0xFBFF) | 0x800;
            } else {
                btn = (btn & 0xF7FF) | 0x400;
            }
        }
        ContDStk[i] = btn;
        ContDStkTrg[i] = btn & (btn ^ D_800F3396[i]);
        if ((btn & 0xFFFF) != D_800F3396[i]) {
            D_800F32A4[i] = 15;
            D_800F2CF0[i] = ContDStkTrg[i];
        } else if (D_800F32A4[i] > 0) {
            D_800F32A4[i] = D_800F32A4[i] - 1;
            D_800F2CF0[i] = ContDStkTrg[i];
        } else {
            D_800F32A4[i] = 5;
            D_800F2CF0[i] = btn;
        }
    }
}

extern void *D_800D12F0; // FS ROM location
extern u32 D_800D12F4; // Directory count
extern s32 *D_800D12F8; // Directory offset table pointer.

extern void *D_800D12FC; // FS ROM location (copy)
extern u32 D_800D1300; // Directory count (copy)
extern s32 *D_800D1304; // Directory offset table pointer (copy)

extern HuArchive D_800D1310;

extern void *DataDecode(s32, s32);
extern void *DataDecodeTemp(s32, s32);
extern void DataDirInit(u32, u32);
extern void DataInfoRead(s32 type, s32 index, HuFileInfo* info);

// Initialize file system from ROM.
void DataInit(void* fs_rom_loc) {
    s32 dir_table_size;
    HuArchive* archiveHeader;

    D_800D12F0 = fs_rom_loc;
    archiveHeader = &D_800D1310;
    dmaRead(fs_rom_loc, archiveHeader, 16); // ExecRomCopy
    D_800D12F4 = archiveHeader->dir;
    dir_table_size = archiveHeader->dir * 4;
    D_800D12F8 = (s32 *)HuMemDirectMalloc(dir_table_size);
    dmaRead(fs_rom_loc + 4, D_800D12F8, dir_table_size);
    D_800D12FC = D_800D12F0;
    D_800D1300 = D_800D12F4;
    D_800D1304 = D_800D12F8;
}

void DataInfoRead(s32 type, s32 index, HuFileInfo* info) {
    HuArchive* archiveHeader;

    archiveHeader = &D_800D1310;

    switch (type) {
        case 0x2F:
            info->bytes = (u8 *)D_800D12F0 + D_800D12F8[index];
            break;
        case 0x2E:
            info->bytes = (u8 *)D_800D12FC + D_800D1304[index];
            break;
    }

    dmaRead(info->bytes, archiveHeader, 16); // ExecRomCopy
    info->bytes += 8;
    info->size = archiveHeader->dir;
    info->compType = archiveHeader->offsets[0];
}

/*
 * Reads a file from the main filesystem and decodes it.
 * File is in the permanent heap.
*/
void* DataRead(s32 dirAndFile) {
    u32 dir;
    u32 file;

    dir = dirAndFile >> 16;
    file = dirAndFile & 0xFFFF;

    if (dir < D_800D12F4) {
        DataDirInit(0x2F, dir);

        if (file < D_800D1300) {
            return DataDecode(0x2E, file);
        }
    }

    return NULL;
}

/*
 * Reads a file from the main filesystem and decodes it.
 * Files is in the temporary heap.
*/
void* func_80014614(s32 dirAndFile) {
    u32 dir;
    u32 file;

    dir = dirAndFile >> 16;
    file = dirAndFile & 0xFFFF;

    if (dir < D_800D12F4) {
        DataDirInit(0x2F, dir);

        if (file < D_800D1300) {
            return DataDecodeTemp(0x2E, file);
        }
    }

    return NULL;
}

/*
 * Read file, allocate space in perm heap, decode it.
*/
void *DataDecode(s32 type, s32 index) {
    HuFileInfo info;
    void* ret;

    DataInfoRead(type, index, &info);
    ret = HuMemDirectMalloc((info.size + 1) & -2);
    if (ret != NULL) {
        DecodeFile(info.bytes, ret, info.size, info.compType);
    }
    return ret;
}

/*
 * Read file, allocate space in temp heap, decode it.
*/
void* DataDecodeTemp(s32 type, s32 index) {
    HuFileInfo info;
    void* ret;

    DataInfoRead(type, index, &info);
    ret = MallocTemp((info.size + 1) & -2);
    if (ret != NULL) {
        DecodeFile(info.bytes, ret, info.size, info.compType);
    }
    return ret;
}

/*
 * HuMemMemoryFree file previously obtained through DataRead.
 * 80014730
*/
void DataClose(void *file) {
    if (file != NULL) {
        HuMemDirectFree(file);
    }
}

/*
 * HuMemMemoryFree file previously obtained through func_80014614.
*/
void DataCloseTemp(void *file) {
    if (file != NULL) {
        HuMemDirectFree(file); //! Should be FreeTemp, but not functionally problematic.
    }
}

void DataDirInit(u32 arg0, u32 arg1) {
    HuArchive* test;
    HuFileInfo sp10; //rom addr point to directory
    s32 tableSize;
    s32 dir;
    
    sp10.bytes = D_800D12F0 + D_800D12F8[arg1];
    if (D_800D12FC != sp10.bytes) {
        if (D_800D12FC != D_800D12F0) {
            HuMemDirectFree(D_800D1304);
        }
        
        D_800D12FC = sp10.bytes;
        test = &D_800D1310;
        
        dmaRead(sp10.bytes, test, 0x10);
        dir = test->dir;
        
        D_800D1300 = dir;
        tableSize = dir * 4;
        D_800D1304 = HuMemDirectMalloc(tableSize);
        dmaRead(sp10.bytes + 4, D_800D1304, tableSize);
    }
}

// -----------------------------------------------------------------

// STARTING HERE ARE DEPRECATED FUNCTIONS THAT ARE NOT UTILIZED

// -----------------------------------------------------------------

HuFileInfoD *FileCreate(EArchiveType type, s32 index) {
    HuFileInfo info;
    HuFileInfoD *dataInfo; // ! - deprecated

    dataInfo = HuMemDirectMalloc(sizeof(HuFileInfoD));
    if (dataInfo == NULL)
        return NULL;

    DataInfoRead(type, index, &info);

    dataInfo->size = info.size;
    dataInfo->compType = info.compType;
    dataInfo->block = HuMemDirectMalloc(0x400);
    dataInfo->unkC = 1;
    dataInfo->unkE = 0;
    dataInfo->bytes =
        dataInfo->bytesCopy = info.bytes;

    return dataInfo;
}

void FileClose(HuFileInfoD *info) {
    HuMemDirectFree(info->block);
    HuMemDirectFree(info);
}

s32 FileRead(HuFileInfoD *info) {
    if (((info->bytesCopy - info->bytes) + info->unkE) >= info->size) {
        return -1;
    }

    if (info->unkE >= 0x400) {
        info->unkC = 1;
        info->bytesCopy = (void *)(info->unkE + info->bytesCopy);
        info->unkE = 0;
    }

    if (info->unkC != 0) {
        info->unkC = 0;
        dmaRead(info->bytesCopy, info->block, 0x400);
    }

    return info->block[info->unkE++];
}

s32 FileReadBuf(s8 *arg0, s32 arg1, s32 arg2, HuFileInfoD *arg3) {
    s32 temp_v0;
    s8 *var_s1;

    s32 i = 0;
    s32 b = arg1 * arg2;
    var_s1 = arg0;

    while (TRUE) {
        temp_v0 = FileRead(arg3);

        if (temp_v0 == -1) {
            break;
        }

        *var_s1 = temp_v0;
        ++i;

        if (i >= b) {
            break;
        }

        var_s1++;
    }
    return i;
}

void FileSeek(HuFileInfoD *info, s32 arg1, s32 arg2) {
    switch (arg2) {
        case 0:
            arg2 = (u32)(info->bytes + arg1);
            break;
        case 1:
            arg2 = (u32)(info->bytesCopy + info->unkE + arg1);
            break;
        case 2:
            arg2 = (u32)(info->bytes + info->size + arg1);
            break;
        default:
            return;
    }
    arg2 = ((u32)arg2 < (u32)info->bytes) ? (u32)info->bytes : (u32)arg2;
    arg2 = ((u32)arg2 >= (u32)(info->bytes + info->size)) ? (u32)(info->bytes + info->size - 1) : (u32)arg2;

    if (((u32)arg2 < (u32)info->bytesCopy) || ((u32)arg2 >= (u32)(info->bytesCopy + 0x400))) {
        info->unkC = 1;
        info->unkE = arg2 & 1;
        info->bytesCopy = (u8 *)(arg2 - info->unkE);
    } else {
        info->unkE = arg2 - (u32)info->bytesCopy;
    }
}
