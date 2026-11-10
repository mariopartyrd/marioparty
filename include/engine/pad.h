#ifndef __PAD_H
#define __PAD_H

#include "PR/os.h"
#include "common.h"
#include "siman.h"

#define PAD_COUNT (4)

typedef struct {
    /* 0x00 */ OSContPad pad[PAD_COUNT]; /* one osContGetReadData result */
} pad_unk; /* sizeof = 0x18 */

extern pad_unk D_800D1170[8];
extern s16 D_800D12B0;
extern s16 D_800D12B2;
extern s16 D_800D12B4;
extern u8 D_800D12B6[]; /* per-pad auto-repeat countdown */
extern u8 D_800D12BA[];
extern s8 D_800D12BE;
extern s8 D_800D12BF;
extern u32 D_800D12C0; // unknown type
extern s16 D_800D12CC;
extern unkMesg D_800D1230[];
extern OSMesgQueue D_800D12D0;
extern OSMesgQueue D_800EE960;
extern OSMesg D_800D12E8;
extern u16 D_800ECE08[4];
extern s8 ContStkX[4];
extern u16 ContBtn[4];
extern u16 D_800F2CE2[4];
extern u16 D_800F338C[4];
extern s16 D_800F33CC[4];
extern s16 D_800F3778;
extern s8 ContStkY[4];

extern s32 func_80013770(u16* arg0);
extern s16 func_800138DC(s16 arg0, s32 arg1);
extern s32 func_80013974(s32 arg0);
extern void func_80013A74(void);
extern void func_80013AEC(s8 arg0, s8 arg1);
extern void func_80014158(void);
extern void func_80014174(void);
extern void func_800141C4(void);

#endif

