#include "common.h"

extern u8 D_800D1320[1024]; // compressed input chunk
extern u8 D_800D1720[1024]; // LZ window

typedef struct DecodeStruct {
/* 0x00 */ u16 chunk_len;
/* 0x02 */ s16 pad;
/* 0x04 */ u8 *src;
/* 0x08 */ u8 *dest;
/* 0x0C */ u32 len;
} DecodeStruct;

void func_800171EC(DecodeStruct*);

void func_80017150(DecodeStruct* decode) { //DecodeNone
    s32 copy_len;

    while(decode->len) {
        if(decode->len < 1024) {
            copy_len = (decode->len+1) & ~1;
            decode->len = 0;
        } else {
            copy_len = 1024;
            decode->len -= 1024;
        }
        
        dmaRead(decode->src, decode->dest, copy_len);
        decode->src += copy_len;
        decode->dest += copy_len;
    }
}

void func_800171EC(DecodeStruct* decode) {
    u16 flag = 0;
    u16 windowPos = 958;
    s32 winTemp;
    s32 i;
    s32 byte1;
    s32 len;
    s32 copyVal;

    bzero(D_800D1720, 1024);

    while (decode->len) {
        flag = flag >> 1;
        if ((flag & 0x100) == 0) {
            if (decode->chunk_len >= 1024) {
                dmaRead(decode->src, D_800D1320, 1024);
                decode->src += 1024;
                decode->chunk_len = 0;
            }
            byte1 = D_800D1320[decode->chunk_len++];

            flag = 0xFF00 | (byte1 & 0xFF);
        }
        if ((flag & 0x1)) {
            u32 read_val;
            if (decode->chunk_len >= 1024) {
                dmaRead(decode->src, D_800D1320, 1024);
                decode->src += 1024;
                decode->chunk_len = 0;
            }
            read_val = D_800D1320[decode->chunk_len++];
            D_800D1720[windowPos++] = *(decode->dest++) = read_val;
            windowPos &= 0x3FF;
            decode->len--;
        } else {
            if (decode->chunk_len >= 1024) {
                dmaRead(decode->src, D_800D1320, 1024);
                decode->src += 1024;
                decode->chunk_len = 0;
            }
            byte1 = D_800D1320[decode->chunk_len++];

            if (decode->chunk_len >= 1024) {
                dmaRead(decode->src, D_800D1320, 1024);
                decode->src += 1024;
                decode->chunk_len = 0;
            }
            len = D_800D1320[decode->chunk_len++];

            byte1 = byte1 | ((len & 0xC0) << 2);
            len = 3 + (len & 0x3F);

            for (i = 0; i < len; i++) {
                {
                    winTemp = windowPos++;
                    *(decode->dest++) = (copyVal = D_800D1720[(byte1 + i) & 0x3FF]);
                    D_800D1720[winTemp] = copyVal;
                    windowPos &= 0x3FF;
                }
            }
            decode->len -= i;
        }
    }
}

void DecodeFile(void* src, void* dest, s32 len, s32 decode_type) {
    DecodeStruct decode_struct;
    DecodeStruct* decode_ptr = &decode_struct;
    decode_struct.src = (u8 *)src;
    decode_struct.dest = (u8 *)dest;
    decode_struct.len = len;
    decode_struct.chunk_len = 1024;
    switch(decode_type) {
        case 0:
            func_80017150(decode_ptr);
            break;

        case 1:
            func_800171EC(decode_ptr);
            break;

        default:
            break;
    }
}
