#ifndef SDK_LIB_H
#define SDK_LIB_H
/* sdk-lib: ultralib's spellings of the controller-pak constants and macros that MP1's
   src/lib/2.0I/io/controller.h lacks or spells differently (include after it). */

#ifndef PFS_EOF
#define PFS_EOF 1
#define PFS_PAGE_NOT_EXIST 2
#define PFS_PAGE_NOT_USED 3
#endif
#ifndef PFS_WRITTEN
#define PFS_WRITTEN 2
#endif
#ifndef DEF_DIR_PAGES
#define DEF_DIR_PAGES 2
#endif
#ifndef PFS_ID_0AREA
#define PFS_ID_0AREA 1
#define PFS_ID_1AREA 3
#define PFS_ID_2AREA 4
#define PFS_ID_3AREA 6
#endif
#ifndef PFS_LABEL_AREA
#define PFS_LABEL_AREA 7
#endif
#ifndef PFS_INODE_SIZE_PER_PAGE
#define PFS_INODE_SIZE_PER_PAGE 128
#endif
#ifndef PFS_BANK_LAPPED_BY
#define PFS_BANK_LAPPED_BY 8
#define PFS_SECTOR_PER_BANK 32
#define PFS_INODE_DIST_MAP (PFS_BANK_LAPPED_BY * PFS_SECTOR_PER_BANK)
#define PFS_SECTOR_SIZE (PFS_INODE_SIZE_PER_PAGE / PFS_SECTOR_PER_BANK)
#endif

#ifndef SELECT_BANK
#define SELECT_BANK(pfs, bank) __osPfsSelectBank((pfs), (bank))
#endif
#undef SET_ACTIVEBANK_TO_ZERO
#define SET_ACTIVEBANK_TO_ZERO()          \
    if (pfs->activebank != 0) {           \
        ERRCK(__osPfsSelectBank(pfs, 0)); \
    } (void)0
#undef PFS_CHECK_ID
#define PFS_CHECK_ID()                        \
    if (__osCheckId(pfs) == PFS_ERR_NEW_PACK) \
        return PFS_ERR_NEW_PACK
#undef PFS_CHECK_STATUS
#define PFS_CHECK_STATUS()                    \
    if ((pfs->status & PFS_INITIALIZED) == 0) \
        return PFS_ERR_INVALID
#undef PFS_GET_STATUS
#define PFS_GET_STATUS()                    \
    __osSiGetAccess();                      \
    ret = __osPfsGetStatus(queue, channel); \
    __osSiRelAccess();                      \
    if (ret != 0)                           \
        return ret

#endif
