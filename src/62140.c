#include "common.h"
#include "PR/os.h"

extern u8 D_800C0A70[];       /* unk1.c */
extern u16 D_800C1670[16][16]; /* unk1.c */

/* Character code -> font index: ASCII 0x20-0x5B and half-width katakana 0xA1-0xE0. Retail
   indexes them through address-only labels (D_800C5A50[c], D_800C5A0B[c]). */
u8 D_800C5A70[60] = {
    0x0F, 0x34, 0x35, 0x36, 0x00, 0x00, 0x00, 0x37, 0x00, 0x00, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x3E, 0x00, 0x00, 0x3F, 0x00, 0x40,
    0x41, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28,
    0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x30, 0x31, 0x32, 0x33, 0x00
};
u8 D_800C5AAC[64] = {
    0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4B, 0x4C, 0x4D, 0x4A, 0x00,
    0x50, 0x51, 0x53, 0x54, 0x55, 0x55, 0x56, 0x57, 0x59, 0x5A, 0x5B, 0x5C, 0x5C, 0x5D, 0x5E, 0x5F,
    0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
    0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x4F, 0x43, 0x44, 0x00
};
Gfx D_800C5AF0[] = {
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetRenderMode(G_RM_ZB_OPA_SURF, G_RM_ZB_OPA_SURF2),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};
Gfx* D_800C5B30 = D_800C5AF0; /* unreferenced */
u16 D_800C5B34 = 0xFFFF;

typedef struct StrLine {
    /* 0x00 */ u16 color;
    /* 0x02 */ u16 x;
    /* 0x04 */ u16 y;
    /* 0x06 */ u16 next;
    /* 0x08 */ u8 str[0x40];
} StrLine; // size 0x48

extern StrLine D_800D9370[0x200];
extern u16 empstrline;
extern u16 strlinecnt;
void pfClsScr(void);


typedef struct PfsStateReq {
    /* 0x00 */ s16 channel;
    /* 0x04 */ s32 fileNo;
    /* 0x08 */ OSPfsState state;
} PfsStateReq;

typedef struct PfsFindReq {
    /* 0x00 */ s16 channel;
    /* 0x02 */ u16 company;
    /* 0x04 */ u32 gameCode;
    /* 0x08 */ u8* gameName;
    /* 0x0C */ u8* extName;
    /* 0x10 */ s32 fileNo;
} PfsFindReq;

typedef struct PfsAllocReq {
    /* 0x00 */ s16 channel;
    /* 0x02 */ u16 company;
    /* 0x04 */ u32 gameCode;
    /* 0x08 */ u8* gameName;
    /* 0x0C */ u8* extName;
    /* 0x10 */ s16 size;
    /* 0x14 */ s32 fileNo;
} PfsAllocReq;

typedef struct PfsFileReq {
    /* 0x00 */ s16 channel;
    /* 0x04 */ s32 fileNo;
} PfsFileReq;

typedef struct PfsRWReq {
    /* 0x00 */ s16 channel;
    /* 0x04 */ s32 fileNo;
    /* 0x08 */ s16 size;
    /* 0x0C */ u8* buf;
} PfsRWReq;

extern u8 D_800D9270[];
extern OSPiHandle* D_800EE31C;
extern OSMesg D_800ED570[];
extern OSMesgQueue D_800F65A0;


typedef struct box {
    u16 activeBool;
    s16 unk_02;
    s32 xPosStart;
    s32 yPosStart;
    s32 width;
    s32 height;
    u32 rgba;
} box;

typedef struct unk62140_2 {
/* 0x00 */ s16 unk_00;
/* 0x04 */ s32 unk_04;
/* 0x08 */ s32 unk_08;
/* 0x0C */ s32 unk_0C;
} unk62140_2;

typedef struct unk62140_3 {
/* 0x00 */ u8 unk_00; // red
/* 0x01 */ u8 unk_01; // green
/* 0x02 */ u8 unk_02; // blue
/* 0x03 */ s8 unk_03; // red step
/* 0x04 */ s8 unk_04; // green step
/* 0x05 */ s8 unk_05; // blue step
/* 0x06 */ u8 unk_06; // red max
/* 0x07 */ u8 unk_07; // green max
/* 0x08 */ u8 unk_08; // blue max
/* 0x09 */ u8 unk_09; // red min
/* 0x0A */ u8 unk_0A; // green min
/* 0x0B */ u8 unk_0B; // blue min
/* 0x0C */ s8 unk_0C;
} unk62140_3;

typedef struct unkStruct_zz {
    s32 unk_00;
    char unk_04[0x44];
} unkStruct_zz;

extern unkStruct_zz D_800D9378[];

s32 RequestSIFunction(unkMesg * siMessg, HuSiFunc func, void * arg, s32 type);
void func_800618A4(OSPfs* arg0);
s32 func_80061714(void);
s32 func_80061784(s16* arg0);

extern box pfWinData[];
extern u16 saftyFrameF;
extern OSMesgQueue D_800EE960;
extern unk62140_3 saftyFrameColor;
extern u16 emppfwin;
extern OSPfs D_800D90D0[];
s32 func_80061784(s16* arg0);

void func_80061540(u8* src, u8* dst, s32 len) {
    u8 c;
    u8 next;

    while (len-- != 0) {
        c = *src++;
        if (len > 0) {
            next = *src;
            if (next == 0xDE) {
                if (c >= 0xB6 && c < 0xC5) {
                    *dst = c + 0xC6;
                    dst++;
                    len--;
                    src++;
                    continue;
                }
                if (c >= 0xCA && c < 0xCF) {
                    *dst = c + 0xC1;
                    dst++;
                    len--;
                    src++;
                    continue;
                }
            } else if (next == 0xDF) {
                if (c >= 0xCA && c < 0xCF) {
                    *dst = c + 0xC6;
                    dst++;
                    len--;
                    src++;
                    continue;
                }
            }
        }
        if (c >= 0x20 && c < 0x5B) {
            *dst = D_800C5A70[c - 0x20];
        } else if (c >= 0xA1 && c < 0xE0) {
            *dst = D_800C5AAC[c - 0xA1];
        } else {
            *dst = 0;
        }
        dst++;
    }
}
void func_80061638(u8* name, u8* gameName, u8* extName) {
    u8* p;
    s16 len;

    bzero(gameName, 16);
    bzero(extName, 4);
    p = name;
    len = 0;
    while (((*p == 0) | (*p == '.')) == 0) {
        p++;
        len++;
    }
    func_80061540(name, gameName, len);
    if (*p != 0) {
        name = p + 1;
        p = name;
        len = 0;
        while (*p != 0) {
            p++;
            len++;
        }
        func_80061540(name, extName, len);
    }
}
s32 func_80061714(void) {
    s16 i;

    for (i = 0; i < 4; i++) {
        func_80061784(&i);
    }
    return 0;
}

void func_80061758() {
    unkMesg sp10;

    RequestSIFunction(&sp10, (void*)&func_80061714, 0, 1);
}

s32 func_80061784(s16* arg0) {
    u8 sp10;
    s16 temp_a2;
    s32 ret;

    if (osPfsIsPlug(&D_800EE960, &sp10) != 0) {
        sp10 = 0;
    }
    
    temp_a2 = *arg0;
    
    if ((sp10 >> temp_a2) & 1) {
        ret = osPfsInitPak(&D_800EE960, &D_800D90D0[temp_a2], temp_a2);
    } else {
        ret = 1;
    }
    return ret;
}

void func_80061808(s16 arg0) {
    unkMesg sp10;

    RequestSIFunction(&sp10, (void*)&func_80061784, &arg0, 2);
}

void func_80061838(s16* arg0) {
    osPfsRepairId(&D_800D90D0[*arg0]);
}


void func_80061874(s16 arg0) {
    unkMesg sp10;

    RequestSIFunction(&sp10, (void*)func_80061838, &arg0, 2);
}

void func_800618A4(OSPfs* arg0) { // TODO: fix argument
    arg0->channel = 0;
    arg0->queue = NULL;
    if (osPfsNumFiles(&D_800D90D0[((s16*)arg0)[0]], (s32*) &arg0->queue, (s32*) &arg0->channel) == 0) {
        osPfsFreeBlocks(&D_800D90D0[((s16*)arg0)[0]], (void*) arg0->id);
    }
}

s32 func_80061930(s16 arg0, s32* arg1, s32* arg2, s32* arg3) {
    unkMesg sp10;
    unk62140_2 sp20;
    sp20.unk_00 = arg0;

    RequestSIFunction(&sp10, (void*)&func_800618A4, &sp20, 2);
    *arg1 = sp20.unk_04;
    *arg2 = sp20.unk_08;
    *arg3 = sp20.unk_0C;
    return sp10.ret;
}

s32 func_800619A0(PfsStateReq* req) {
    return osPfsFileState(&D_800D90D0[req->channel], req->fileNo, &req->state);
}

s32 func_800619E8(s16 channel, s32 fileNo, OSPfsState* state) {
    unkMesg sp10;
    PfsStateReq req;

    req.channel = channel;
    req.fileNo = fileNo;
    RequestSIFunction(&sp10, (void*)&func_800619A0, &req, 2);
    bcopy(&req.state, state, sizeof(OSPfsState));
    return sp10.ret;
}
s32 func_80061A3C(PfsFindReq* req) {
    return osPfsFindFile(&D_800D90D0[req->channel], req->company, req->gameCode, req->gameName, req->extName, &req->fileNo);
}
s32 func_80061A98(s16 channel, u16 company, u32 gameCode, u8* name, s32* fileNo) {
    unkMesg sp10;
    PfsFindReq req;
    u8 gameName[16];
    u8 extName[4];

    func_80061638(name, gameName, extName);
    req.channel = channel;
    req.company = company;
    req.gameCode = gameCode;
    req.gameName = gameName;
    req.extName = extName;
    RequestSIFunction(&sp10, (void*)&func_80061A3C, &req, 2);
    *fileNo = req.fileNo;
    return sp10.ret;
}
s32 func_80061B3C(PfsAllocReq* req) {
    PfsFindReq find;
    s32 ret;

    ret = osPfsAllocateFile(&D_800D90D0[req->channel], req->company, req->gameCode, req->gameName, req->extName, req->size, &req->fileNo);
    if (ret == PFS_ERR_EXIST) {
        find.channel = req->channel;
        find.company = req->company;
        find.gameCode = req->gameCode;
        find.gameName = req->gameName;
        find.extName = req->extName;
        ret = func_80061A3C(&find);
        if (ret == 0) {
            req->fileNo = find.fileNo;
        }
    }
    return ret;
}
s32 func_80061C00(s16 channel, u16 company, u32 gameCode, u8* name, s32 size, s32* fileNo) {
    unkMesg sp10;
    PfsAllocReq req;
    u8 gameName[16];
    u8 extName[4];

    func_80061638(name, gameName, extName);
    req.channel = channel;
    req.company = company;
    req.gameCode = gameCode;
    req.gameName = gameName;
    req.extName = extName;
    req.size = size;
    RequestSIFunction(&sp10, (void*)&func_80061B3C, &req, 2);
    *fileNo = req.fileNo;
    return sp10.ret;
}
s32 func_80061CB4(PfsFileReq* req) {
    PfsStateReq st;
    s32 ret;

    st.channel = req->channel;
    st.fileNo = req->fileNo;
    ret = func_800619A0(&st);
    if (ret == 0) {
        ret = osPfsDeleteFile(&D_800D90D0[req->channel], st.state.company_code, st.state.game_code, (u8*)st.state.game_name, (u8*)st.state.ext_name);
    }
    return ret;
}
void func_80061D30(s16 channel, s32 fileNo) {
    unkMesg sp10;
    PfsFileReq req;

    req.channel = channel;
    req.fileNo = fileNo;
    RequestSIFunction(&sp10, (void*)&func_80061CB4, &req, 2);
}
s32 func_80061D64(PfsRWReq* req) {
    s16 size = (req->size + 0xFF) & ~0xFF;

    return osPfsReadWriteFile(&D_800D90D0[req->channel], req->fileNo, PFS_WRITE, 0, size, req->buf);
}
void func_80061DD4(s16 channel, s32 fileNo, s16 size, u8* buf) {
    unkMesg sp10;
    PfsRWReq req;

    req.channel = channel;
    req.fileNo = fileNo;
    req.size = size;
    req.buf = buf;
    RequestSIFunction(&sp10, (void*)&func_80061D64, &req, 2);
}
s32 func_80061E10(PfsRWReq* req) {
    s16 offset;
    s32 n;
    s32 ret;

    for (offset = 0; offset < req->size; offset += 0x100) {
        ret = osPfsReadWriteFile(&D_800D90D0[req->channel], req->fileNo, PFS_READ, offset, 0x100, D_800D9270);
        if (ret != 0) {
            break;
        }
        n = req->size - offset;
        if (n > 0x100) {
            n = 0x100;
        }
        bcopy(D_800D9270, req->buf + offset, (s16)n);
    }
    return ret;
}
void func_80061F24(s16 channel, s32 fileNo, s16 size, u8* buf) {
    unkMesg sp10;
    PfsRWReq req;

    req.channel = channel;
    req.fileNo = fileNo;
    req.size = size;
    req.buf = buf;
    RequestSIFunction(&sp10, (void*)&func_80061E10, &req, 2);
}
void func_80061F60(void) {
    osCreatePiManager(150, &D_800F65A0, D_800ED570, 20);
    D_800EE31C = osCartRomInit();
}
s32 func_80061FA0(OSIoMesg* mb, u8 pri, s32 direction, u32 devAddr, void* dramAddr, u32 size, OSMesgQueue* retQueue) {
    mb->hdr.pri = pri;
    mb->hdr.retQueue = retQueue;
    mb->dramAddr = dramAddr;
    mb->devAddr = devAddr;
    mb->size = size;
    return osEPiStartDma(D_800EE31C, mb, direction);
}
s32 dmaRead(u8* src, void* dest, s32 size) {
    OSMesgQueue queue;
    OSIoMesg ioMsg;
    OSMesg msg[1];
    s32 ret;

    osCreateMesgQueue(&queue, msg, 1);
    osInvalDCache(dest, ((u32)(size + 15) >> 4) << 4);
    ret = func_80061FA0(&ioMsg, OS_MESG_PRI_NORMAL, OS_READ, (u32)src, dest, size, &queue);
    if (ret == 0) {
        osRecvMesg(&queue, NULL, OS_MESG_BLOCK);
    }
    return ret;
}
s32 HuRomDmaCodeRead(void* src, void* dest, s32 size) {
    OSMesgQueue queue;
    OSIoMesg ioMsg;
    OSMesg msg[1];
    s32 alignedSize;
    s32 ret;

    osCreateMesgQueue(&queue, msg, 1);
    alignedSize = ((u32)(size + 15) >> 4) << 4;
    osInvalICache(dest, alignedSize);
    osInvalDCache(dest, alignedSize);
    ret = func_80061FA0(&ioMsg, OS_MESG_PRI_NORMAL, OS_READ, (u32)src, dest, size, &queue);
    if (ret == 0) {
        osRecvMesg(&queue, NULL, OS_MESG_BLOCK);
    }
    return ret;
}
void pfInit(void) {
    s32 i;

    fontcolor = 15;
    empstrline = 0;
    for (i = 0; i < 0x200; i++) {
        D_800D9370[i].str[0] = 0;
    }
    pfClsScr();
    emppfwin = 0;
    for (i = 0; i < 4; i++) {
        pfWinData[i].activeBool = 0;
    }
    saftyFrameF = 0;
}
void pfClsScr(void) {
    s32 i;

    empstrline = 0;
    strlinecnt = 0;
    for (i = 0; i < 0x200; i++) {
        D_800D9370[i].next = i + 1;
        if (D_800D9370[i].str[0] != 0) {
            D_800D9370[i].str[0] = 0;
        }
    }
}
void pfClrStrLine(s16 id) {
    if (D_800D9370[id].str[0] != 0 && strlinecnt != 0) {
        strlinecnt--;
        D_800D9370[id].str[0] = 0;
        D_800D9370[id].next = empstrline;
        empstrline = id;
    }
}
s16 print8(u16 x, u16 y, char* str) {
    StrLine* line = &D_800D9370[empstrline];
    u8* src;
    u8* dst;
    u16 id;

    if (strlinecnt < 0x200) {
        strlinecnt++;
        id = empstrline;
        empstrline = line->next;
        line->color = fontcolor;
        line->x = x;
        line->y = y;
        src = (u8*)str;
        for (dst = line->str; *src != 0; src++, dst++) {
            *dst = *src;
        }
        *dst = 0;
        return id;
    }
    return -1;
}
s16 pfWinCreate(s32 xPosStart, s32 yPosStart, s32 width, s32 height, s32 rgba) {
    box* boxPtr;
    s32 i;

    if (emppfwin >= 4) {
        return -1;
    }

    for (i = 0; i < 4; i++) {
       if (pfWinData[i].activeBool == 0) {
            break;
        }
    }

    boxPtr = &pfWinData[i];
    boxPtr->activeBool = 1;
    boxPtr->xPosStart = xPosStart;
    boxPtr->yPosStart = yPosStart;
    boxPtr->width = width;
    boxPtr->height = height;
    boxPtr->rgba = rgba;
    emppfwin++;
    return i;
}

void pfWinKill(s16 arg0) {
    if (emppfwin != 0) {
        pfWinData[arg0].activeBool = 0;
        emppfwin = emppfwin - 1;
    }
}

void pfWinClose(void) {
    s32 i;
    emppfwin = 0;

    for (i = 0; i < 4; i++) {
        pfWinData[i].activeBool = 0;
    }
}

void saftyFrameSet(s8 arg0, s8 arg1, s8 arg2) {
    saftyFrameColor.unk_00 = arg0;
    saftyFrameColor.unk_01 = arg1;
    saftyFrameColor.unk_02 = arg2;
    saftyFrameColor.unk_03 = saftyFrameColor.unk_04 = saftyFrameColor.unk_05 = 0;
    saftyFrameF = 1;
}

void saftyFrameFlashSet(s8 arg0, s8 arg1, s8 arg2, s8 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8) {
    saftyFrameColor.unk_03 = arg0;
    saftyFrameColor.unk_04 = arg1;
    saftyFrameColor.unk_05 = arg2;
    saftyFrameColor.unk_06 = arg3;
    saftyFrameColor.unk_07 = arg4;
    saftyFrameColor.unk_08 = arg5;
    saftyFrameColor.unk_09 = arg6;
    saftyFrameColor.unk_0A = arg7;
    saftyFrameColor.unk_0B = arg8;
}

void saftyFrameFlashReset(void) { 
    saftyFrameColor.unk_03 = saftyFrameColor.unk_04 = saftyFrameColor.unk_05 = 0;
}

void saftyFrameReset(void) {
    saftyFrameF = 0;
}

void func_80062524(s16 arg0, u8* arg1) {
    u8* temp_v0;
    
    if (&D_800D9378[arg0] != NULL) {
        temp_v0 = (u8*)&D_800D9378[arg0];
        for (; *arg1 != 0; temp_v0++, arg1++) {
            *temp_v0 = *arg1;
        }
        *temp_v0 = 0;
    }
}

#define RGBA32_R(color) ((color) >> 24)
#define RGBA32_G(color) (((color) >> 16) & 0xFF)
#define RGBA32_B(color) (((color) >> 8) & 0xFF)
#define RGBA32_A(color) ((color) & 0xFF)
#define FILL_COLOR_RGBA5551(r, g, b, a) ((GPACK_RGBA5551(r, g, b, a) << 16) | GPACK_RGBA5551(r, g, b, a))


#define PF_SCISSOR_W 319
#define PF_SCISSOR_H 339

Gfx *pfDrawFonts(Gfx *gfx) {
    u16 count;
    s32 i;
    u16 pal;
    u16 color;
    u16 x;
    u16 y;
    u8 *str;
    u8 c;
    s8 speed;

    count = strlinecnt;

    if (emppfwin != 0) {
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 0, 0, PF_SCISSOR_W, PF_SCISSOR_H);
        gDPPipeSync(gfx++);
        gDPSetTextureLOD(gfx++, G_TL_LOD);
        gSPTexture(gfx++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
        gDPSetTexturePersp(gfx++, G_TP_NONE);
        gDPSetAlphaCompare(gfx++, G_AC_THRESHOLD);
        for (i = 0; i < 4; i++) {
            if (pfWinData[i].activeBool != 0) {
                if (RGBA32_A(pfWinData[i].rgba) == 0xFF) {
                    gDPPipeSync(gfx++);
                    gDPSetCycleType(gfx++, G_CYC_FILL);
                    gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);
                    gDPSetFillColor(gfx++, FILL_COLOR_RGBA5551(RGBA32_R(pfWinData[i].rgba),
                                                               RGBA32_G(pfWinData[i].rgba),
                                                               RGBA32_B(pfWinData[i].rgba),
                                                               RGBA32_A(pfWinData[i].rgba)));
                } else {
                    gDPPipeSync(gfx++);
                    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
                    gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
                    gDPSetRenderMode(gfx++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
                    gDPSetPrimColor(gfx++, 0, 0, RGBA32_R(pfWinData[i].rgba),
                                    RGBA32_G(pfWinData[i].rgba), RGBA32_B(pfWinData[i].rgba),
                                    RGBA32_A(pfWinData[i].rgba));
                }
                gDPFillRectangle(gfx++, pfWinData[i].xPosStart, pfWinData[i].yPosStart,
                                 pfWinData[i].width, pfWinData[i].height);
            }
        }
    }

    if (saftyFrameF != 0) {
        if (saftyFrameColor.unk_03 != 0) {
            speed = saftyFrameColor.unk_03;
            if (speed < 0) {
                if (saftyFrameColor.unk_00 + speed >= saftyFrameColor.unk_09) {
                    saftyFrameColor.unk_00 += speed;
                } else {
                    saftyFrameColor.unk_00 = saftyFrameColor.unk_09;
                    saftyFrameColor.unk_03 = -saftyFrameColor.unk_03;
                }
            } else {
                if (saftyFrameColor.unk_00 + speed <= saftyFrameColor.unk_06) {
                    saftyFrameColor.unk_00 += speed;
                } else {
                    saftyFrameColor.unk_00 = saftyFrameColor.unk_06;
                    saftyFrameColor.unk_03 = -saftyFrameColor.unk_03;
                }
            }
        }
        if (saftyFrameColor.unk_04 != 0) {
            speed = saftyFrameColor.unk_04;
            if (speed < 0) {
                if (saftyFrameColor.unk_01 + speed >= saftyFrameColor.unk_0A) {
                    saftyFrameColor.unk_01 += speed;
                } else {
                    saftyFrameColor.unk_01 = saftyFrameColor.unk_0A;
                    saftyFrameColor.unk_04 = -saftyFrameColor.unk_04;
                }
            } else {
                if (saftyFrameColor.unk_01 + speed <= saftyFrameColor.unk_07) {
                    saftyFrameColor.unk_01 += speed;
                } else {
                    saftyFrameColor.unk_01 = saftyFrameColor.unk_07;
                    saftyFrameColor.unk_04 = -saftyFrameColor.unk_04;
                }
            }
        }
        if (saftyFrameColor.unk_05 != 0) {
            speed = saftyFrameColor.unk_05;
            if (speed < 0) {
                if (saftyFrameColor.unk_02 + speed >= saftyFrameColor.unk_0B) {
                    saftyFrameColor.unk_02 += speed;
                } else {
                    saftyFrameColor.unk_02 = saftyFrameColor.unk_0B;
                    saftyFrameColor.unk_05 = -saftyFrameColor.unk_05;
                }
            } else {
                if (saftyFrameColor.unk_02 + speed <= saftyFrameColor.unk_08) {
                    saftyFrameColor.unk_02 += speed;
                } else {
                    saftyFrameColor.unk_02 = saftyFrameColor.unk_08;
                    saftyFrameColor.unk_05 = -saftyFrameColor.unk_05;
                }
            }
        }
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_FILL);
        gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetFillColor(gfx++, FILL_COLOR_RGBA5551(saftyFrameColor.unk_00, saftyFrameColor.unk_01,
                                                   saftyFrameColor.unk_02, 1));
        gDPFillRectangle(gfx++, 24, 16, 296, 16);
        gDPFillRectangle(gfx++, 24, 224, 296, 224);
        gDPFillRectangle(gfx++, 24, 16, 24, 224);
        gDPFillRectangle(gfx++, 296, 16, 296, 224);
    }

    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 0, 0, PF_SCISSOR_W, PF_SCISSOR_H);
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_COPY);
    gDPSetAlphaCompare(gfx++, G_AC_THRESHOLD);
    gDPSetTextureLOD(gfx++, G_TL_LOD);
    gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);
    gSPTexture(gfx++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTexturePersp(gfx++, G_TP_NONE);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);
    gDPSetBlendColor(gfx++, 0xFF, 0xFF, 0xFF, 0xFF);
    gDPLoadTextureBlock_4b(gfx++, D_800C0A70, G_IM_FMT_CI, 64, 64, D_800C5B34,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                           G_TX_NOLOD, G_TX_NOLOD);
    gDPSetBlendColor(gfx++, 0, 0, 0, 1);
    for (pal = 0; pal < 16; pal++) {
        gDPLoadTLUT_pal16(gfx++, pal, D_800C1670[pal]);
    }

    for (i = 0; i < 0x200; i++) {
        if (D_800D9370[i].str[0] != '\0') {
            str = D_800D9370[i].str;
            color = D_800D9370[i].color;
            x = D_800D9370[i].x;
            y = D_800D9370[i].y;
            if (color != D_800C5B34) {
                D_800C5B34 = color;
                gDPTileSync(gfx++);
                gDPSetTile(gfx++, G_IM_FMT_CI, G_IM_SIZ_4b, 4, 0, G_TX_RENDERTILE, color, 0, 0, 0, 0, 0, 0);
            }
            for (; *str != '\0'; str++) {
                if (*str >= ' ') {
                    c = *str - ' ';
                    gSPTextureRectangle(gfx++, x << 2, y << 2, (x + 7) << 2, (y + 7) << 2, G_TX_RENDERTILE,
                                        ((c % 8) * 8) << 5, ((c / 8) * 8) << 5, 4 << 10, 1 << 10);
                    x += 8;
                    if (x >= 320) {
                        x = 0;
                        y += 8;
                    }
                }
            }
            if (--count == 0) {
                break;
            }
        }
    }

    gDPPipeSync(gfx++);
    gSPTexture(gfx++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
    gDPSetCombineMode(gfx++, G_CC_SHADE, G_CC_SHADE);
    gDPSetRenderMode(gfx++, G_RM_ZB_OPA_SURF, G_RM_ZB_OPA_SURF2);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gDPSetTexturePersp(gfx++, G_TP_PERSP);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    return gfx;
}
