#include "common.h"
#include "PR/libaudio.h"
#include "PR/sptask.h"

/* N64 SDK demo audio manager (audiomgr.c) with the game's heap (func_8000AFA0) and DMA (func_80061FA0). */

typedef struct AMConfig {
    /* 0x00 */ char unk_00[0x34];
    /* 0x34 */ s32 outputRate;
    /* 0x38 */ s32 maxVoices;
    /* 0x3C */ s32 maxUpdates;
    /* 0x40 */ s32 fxType;
    /* 0x44 */ s32* params;
    /* 0x48 */ s32 maxACMDSize;
    /* 0x4C */ s32 numDMABuffers;
    /* 0x50 */ s32 dmaBufferLength;
    /* 0x54 */ s32 frameLag;
    /* 0x58 */ s32 framesPerField;
    /* 0x5C */ s32 fieldRate;
    /* 0x60 */ char unk_60[0x14];
    /* 0x74 */ OSPri pri;
    /* 0x78 */ OSId id;
    /* 0x7C */ s32 unk_7C;
} AMConfig;

typedef struct AMTask {
    /* 0x00 */ OSTask list;
    /* 0x40 */ OSMesgQueue* msgQ;
    /* 0x44 */ OSMesg msg;
} AMTask; /* size = 0x48 */

struct AudioInfo;

typedef struct AMAudioMsg {
    /* 0x00 */ s16 type;
    /* 0x04 */ struct AudioInfo* done;
} AMAudioMsg;

typedef struct AudioInfo {
    /* 0x00 */ s16* data;
    /* 0x04 */ s16 frameSamples;
    /* 0x08 */ AMTask task;
    /* 0x50 */ AMAudioMsg msg;
} AudioInfo; /* size = 0x58 */

typedef struct AMAudioMgr {
    /* 0x000 */ Acmd* ACMDList[2];
    /* 0x008 */ AudioInfo* audioInfo[3];
    /* 0x018 */ OSThread thread;
    /* 0x1C8 */ OSMesgQueue audioFrameMsgQ;
    /* 0x1E0 */ OSMesg audioFrameMsgBuf[8];
    /* 0x200 */ OSMesgQueue audioReplyMsgQ;
    /* 0x218 */ OSMesg audioReplyMsgBuf[8];
    /* 0x238 */ ALGlobals g;
} AMAudioMgr;

typedef struct DMABuffer {
    /* 0x00 */ ALLink node;
    /* 0x08 */ u32 startAddr;
    /* 0x0C */ u32 lastFrame;
    /* 0x10 */ char* ptr;
} DMABuffer; /* size = 0x14 */

typedef struct DMAState {
    /* 0x00 */ DMABuffer* firstUsed;
    /* 0x04 */ DMABuffer* firstFree;
} DMAState;

/* Scheduler client (0x10 bytes), followed directly by the 0x2000-byte audio thread stack. */
extern u8 D_800CEB00[];
extern OSMesgQueue* D_800D0B10; /* scheduler command queue; its address is also the stack top */
extern AMAudioMgr D_800D0B18;
extern DMAState D_800D0DA0;
extern u32 D_800D0DA8; /* audFrameCt */
extern s32 D_800D0DAC; /* nextDMA */
extern s32 D_800D0DB0; /* DMA buffer length */
extern u32 D_800D0DB4; /* frame lag */
extern s32 D_800D0DB8; /* curAcmdList */
extern u32 D_800D0DBC; /* minFrameSize */
extern u32 D_800D0DC0; /* maxFrameSize */
extern u32 D_800D0DC4; /* frameSize */
extern s32 D_800D0DC8; /* maxACMDSize */
extern OSIoMesg D_800D0DD0[];
extern OSMesgQueue D_800D10D0;
extern OSMesg D_800D10E8[];
extern OSMesgQueue D_800ED3A8;
extern u64 D_800B1760[]; /* rspbootTextStart */
extern u64 D_800B1830[]; /* rspbootTextEnd */
extern u64 D_800B7B30[]; /* aspMainTextStart */
extern u64 D_800C9BB0[]; /* aspMainDataStart */

void* func_8000AFA0(s32);
void func_8000B000(s32);
void func_8000BB30(void);
void func_8000BE6C(void);
void func_8000EC14(void);
void func_80010C08(void);
s32 func_80061FA0(OSIoMesg*, u8, s32, u32, void*, u32, OSMesgQueue*);
void func_80063A5C(void*);

void func_800130E8(void* arg);
u32 func_80013234(AudioInfo* info, AudioInfo* lastInfo);
void func_80013358(AudioInfo* info);
s32 func_80013360(s32 addr, s32 len, void* state);
ALDMAproc func_8001350C(void* state);
void func_80013524(void);
void func_8001365C(s32 arg0, s32 remove);
void func_800136C4(AMTask* t, AMAudioMsg* msg, Acmd* cmdp);

// register allocation: fxType value in v1 instead of v0 (masked 0)
#ifdef NON_MATCHING
s32 func_80012CF0(AMConfig* amc, ALHeap* heap) {
    ALSynConfig c;
    f32 fsize;
    s32 i;
    DMABuffer* dmaBuffs;

    c.outputRate = osAiSetFrequency(amc->outputRate);
    fsize = (f32)amc->framesPerField * c.outputRate / (f32)amc->fieldRate;
    D_800D0DC4 = (s32)fsize;
    if (D_800D0DC4 < fsize) {
        D_800D0DC4++;
    }
    if (D_800D0DC4 & 0xF) {
        D_800D0DC4 = (D_800D0DC4 & ~0xF) + 0x10;
    }
    D_800D0DBC = D_800D0DC4 - 0x10;
    D_800D0DC0 = D_800D0DC4 + 0x100;
    c.fxType = (amc->fxType < 7) ? (u8)amc->fxType : 6;
    c.params = amc->params;
    c.maxVVoices = amc->maxVoices;
    c.maxPVoices = amc->maxVoices;
    c.maxUpdates = amc->maxUpdates;
    c.dmaproc = func_8001350C;
    c.heap = heap;
    c.maxFXbusses = 0;
    alInit(&D_800D0B18.g, &c);
    D_800D0DB8 = 0;
    D_800D0DAC = 0;
    D_800D0DA8 = 0;
    D_800D0DB0 = amc->dmaBufferLength;
    D_800D0DB4 = amc->frameLag;
    dmaBuffs = func_8000AFA0(amc->numDMABuffers * sizeof(DMABuffer));
    if (dmaBuffs == NULL) {
        return 1;
    }
    dmaBuffs[amc->numDMABuffers - 1].node.next = NULL;
    dmaBuffs[0].node.next = NULL;
    dmaBuffs[0].node.prev = NULL;
    for (i = 0; i < amc->numDMABuffers - 1; i++) {
        alLink(&dmaBuffs[i + 1].node, &dmaBuffs[i].node);
        if ((dmaBuffs[i].ptr = func_8000AFA0(D_800D0DB0)) == NULL) {
            return 1;
        }
    }
    if ((dmaBuffs[i].ptr = func_8000AFA0(D_800D0DB0)) == NULL) {
        return 1;
    }
    D_800D0DA0.firstUsed = NULL;
    D_800D0DA0.firstFree = dmaBuffs;
    D_800D0DC8 = amc->maxACMDSize;
    for (i = 0; i < 2; i++) {
        if ((D_800D0B18.ACMDList[i] = func_8000AFA0(D_800D0DC8 * sizeof(Acmd))) == NULL) {
            return 1;
        }
    }
    for (i = 0; i < 3; i++) {
        if ((D_800D0B18.audioInfo[i] = func_8000AFA0(sizeof(AudioInfo))) == NULL) {
            return 1;
        }
        D_800D0B18.audioInfo[i]->msg.type = 0;
        D_800D0B18.audioInfo[i]->msg.done = D_800D0B18.audioInfo[i];
        D_800D0B18.audioInfo[i]->data = func_8000AFA0(D_800D0DC0 * 4);
        if (D_800D0B18.audioInfo[i]->data == NULL) {
            return 1;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/138F0", func_80012CF0);
#endif

void func_80013010(AMConfig* amc) {
    osCreateMesgQueue(&D_800D0B18.audioReplyMsgQ, D_800D0B18.audioReplyMsgBuf, 8);
    osCreateMesgQueue(&D_800D10D0, D_800D10E8, 0x20);
    func_8001365C(amc->unk_7C, 0);
    // Stack top: end of the 0x2000-byte stack after the 0x10-byte client (layout-dependent).
    osCreateThread(&D_800D0B18.thread, amc->id, func_800130E8, NULL, D_800CEB00 + 0x2010, amc->pri);
    osStartThread(&D_800D0B18.thread);
}

void func_800130A4(AMConfig* amc) {
    osDestroyThread(&D_800D0B18.thread);
    alClose(&D_800D0B18.g);
    func_8001365C(amc->unk_7C, 1);
}

void func_800130E8(void* arg) {
    OSMesg msg;
    AMAudioMsg* reply;
    s32 done = 0;
    AudioInfo* lastInfo = NULL;

    do {
        osRecvMesg(&D_800D0B18.audioFrameMsgQ, &msg, OS_MESG_BLOCK);
        switch ((u32)msg) {
            case 1:
                if (func_80013234(D_800D0B18.audioInfo[D_800D0DA8 % 3], lastInfo)) {
                    osRecvMesg(&D_800D0B18.audioReplyMsgQ, (OSMesg*)&reply, OS_MESG_BLOCK);
                    func_80013358(reply->done);
                    lastInfo = reply->done;
                    func_8000BB30();
                    func_8000EC14();
                }
                break;
            case 2:
                done = 1;
                func_8000BE6C();
                func_80010C08();
                break;
            case 10:
                done = 1;
                break;
        }
    } while (!done);
    alClose(&D_800D0B18.g);
}

u32 func_80013234(AudioInfo* info, AudioInfo* lastInfo) {
    s32 cmdLen;
    s16* audioPtr;
    Acmd* cmdp;
    AMTask* t;

    func_80013524();
    audioPtr = (s16*)osVirtualToPhysical(info->data);
    if (lastInfo != NULL) {
        osAiSetNextBuffer(lastInfo->data, lastInfo->frameSamples << 2);
    }
    info->frameSamples = ((D_800D0DC4 - (osAiGetLength() >> 2) + 0xF0) & ~0xF) + 0x10;
    if ((u32)info->frameSamples < D_800D0DBC) {
        info->frameSamples = D_800D0DBC;
    }
    cmdp = alAudioFrame(D_800D0B18.ACMDList[D_800D0DB8], &cmdLen, audioPtr, info->frameSamples);
    t = &info->task;
    if (cmdLen == 0) {
        return 0;
    }
    func_800136C4(t, &info->msg, cmdp);
    osSendMesg(D_800D0B10, t, OS_MESG_BLOCK);
    D_800D0DB8 ^= 1;
    return 1;
}

void func_80013358(AudioInfo* info) {
}

s32 func_80013360(s32 addr, s32 len, void* state) {
    void* foundBuffer;
    s32 delta;
    s32 addrEnd;
    s32 buffEnd;
    DMABuffer* dmaPtr;
    DMABuffer* lastDmaPtr;

    lastDmaPtr = NULL;
    dmaPtr = D_800D0DA0.firstUsed;
    addrEnd = addr + len;
    while (dmaPtr != NULL) {
        buffEnd = dmaPtr->startAddr + D_800D0DB0;
        if (dmaPtr->startAddr > addr) {
            break;
        } else if (addrEnd <= buffEnd) {
            dmaPtr->lastFrame = D_800D0DA8;
            foundBuffer = dmaPtr->ptr + addr - dmaPtr->startAddr;
            return osVirtualToPhysical(foundBuffer);
        }
        lastDmaPtr = dmaPtr;
        dmaPtr = (DMABuffer*)dmaPtr->node.next;
    }

    dmaPtr = D_800D0DA0.firstFree;
    if (dmaPtr == NULL) {
        return osVirtualToPhysical(D_800D0DA0.firstUsed);
    }
    D_800D0DA0.firstFree = (DMABuffer*)dmaPtr->node.next;
    alUnlink(&dmaPtr->node);
    if (lastDmaPtr != NULL) {
        alLink(&dmaPtr->node, &lastDmaPtr->node);
    } else if (D_800D0DA0.firstUsed != NULL) {
        lastDmaPtr = D_800D0DA0.firstUsed;
        D_800D0DA0.firstUsed = dmaPtr;
        dmaPtr->node.next = &lastDmaPtr->node;
        dmaPtr->node.prev = NULL;
        lastDmaPtr->node.prev = &dmaPtr->node;
    } else {
        D_800D0DA0.firstUsed = dmaPtr;
        dmaPtr->node.next = NULL;
        dmaPtr->node.prev = NULL;
    }

    foundBuffer = dmaPtr->ptr;
    delta = addr & 1;
    addr -= delta;
    dmaPtr->startAddr = addr;
    dmaPtr->lastFrame = D_800D0DA8;
    func_80061FA0(&D_800D0DD0[D_800D0DAC++], OS_MESG_PRI_NORMAL, OS_READ, addr, foundBuffer, D_800D0DB0,
                  &D_800D10D0);
    return osVirtualToPhysical(foundBuffer) + delta;
}

ALDMAproc func_8001350C(void* state) {
    *(DMAState**)state = &D_800D0DA0;
    return func_80013360;
}

void func_80013524(void) {
    OSMesg iomsg;
    u32 i;
    DMABuffer* dmaPtr;
    DMABuffer* nextPtr;

    for (i = 0, dmaPtr = D_800D0DA0.firstUsed; dmaPtr != NULL; i++) {
        dmaPtr = (DMABuffer*)dmaPtr->node.next;
    }
    func_8000B000(i);
    for (i = 0; i < D_800D0DAC; i++) {
        osRecvMesg(&D_800D10D0, &iomsg, OS_MESG_NOBLOCK);
    }
    dmaPtr = D_800D0DA0.firstUsed;
    while (dmaPtr != NULL) {
        nextPtr = (DMABuffer*)dmaPtr->node.next;
        if (dmaPtr->lastFrame + D_800D0DB4 < D_800D0DA8) {
            if (D_800D0DA0.firstUsed == dmaPtr) {
                D_800D0DA0.firstUsed = nextPtr;
            }
            alUnlink(&dmaPtr->node);
            if (D_800D0DA0.firstFree != NULL) {
                alLink(&dmaPtr->node, &D_800D0DA0.firstFree->node);
            } else {
                D_800D0DA0.firstFree = dmaPtr;
                dmaPtr->node.next = NULL;
                dmaPtr->node.prev = NULL;
            }
        }
        dmaPtr = nextPtr;
    }
    D_800D0DAC = 0;
    D_800D0DA8++;
}

void func_8001365C(s32 arg0, s32 remove) {
    if (remove) {
        func_80063A5C(D_800CEB00);
        return;
    }
    osCreateMesgQueue(&D_800D0B18.audioFrameMsgQ, D_800D0B18.audioFrameMsgBuf, 8);
    D_800D0B10 = &D_800ED3A8;
    func_800639F8((unkMesgWrapper*)D_800CEB00, &D_800D0B18.audioFrameMsgQ, 3);
}

void func_800136C4(AMTask* t, AMAudioMsg* msg, Acmd* cmdp) {
    t->msgQ = &D_800D0B18.audioReplyMsgQ;
    t->msg = msg;
    t->list.t.data_ptr = (u64*)D_800D0B18.ACMDList[D_800D0DB8];
    t->list.t.data_size = (cmdp - D_800D0B18.ACMDList[D_800D0DB8]) * sizeof(Acmd);
    t->list.t.type = 2; /* M_AUDTASK */
    t->list.t.ucode_boot = D_800B1760;
    t->list.t.ucode_boot_size = (s32)D_800B1830 - (s32)D_800B1760;
    t->list.t.flags = 0;
    t->list.t.ucode = D_800B7B30;
    t->list.t.ucode_data = D_800C9BB0;
    t->list.t.ucode_data_size = 0x800;
    t->list.t.dram_stack = NULL;
    t->list.t.dram_stack_size = 0;
    t->list.t.output_buff = NULL;
    t->list.t.output_buff_size = 0;
    t->list.t.yield_data_ptr = NULL;
    t->list.t.yield_data_size = 0;
}
