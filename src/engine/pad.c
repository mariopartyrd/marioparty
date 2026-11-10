#include "engine/pad.h"

s32 func_80013770(u16* arg0) {
    OSContStatus status[PAD_COUNT];
    u8 pattern;
    s16 index;

    osContInit(&D_800EE960, &pattern, status);
    D_800D12B4 = 0;
    D_800D12B2 = 0;
    D_800D12B0 = 0;
    D_800F3778 = 0;
    for (index = 0; index < PAD_COUNT; index++) {
        if ((pattern >> index) & 1) {
            if (!(status[index].errno & 8)) {
                D_800F3778++;
                if (D_800F3778 == arg0[0]) {
                    break;
                }
            }
        }
        ContBtn[index] = ContBtnTrg[index] = D_800ECE08[index] = D_800F338C[index] = 0;
        D_800F2CE2[index] = D_800F33CC[index] = 0;
        ContStkY[index] = 0;
        ContStkX[index] = 0;
        D_800D12BA[index] = 0;
    }
    osContSetCh(arg0[0]);
    return 0;
}

s16 func_800138DC(s16 arg0, s32 arg1) {
    unkMesg sp10;
    s16 sp20;

    sp20 = arg0;
    RequestSIFunction(&sp10, (void*)func_80013770, (void*)&sp20, 1);
    D_800D12CC = 0;
    if (arg1 & 1) {
        func_80014174();
    }
    func_80013AEC(0x46, 0x46);
    osCreateMesgQueue(&D_800D12D0, &D_800D12E8, 1);
    osSendMesg(&D_800D12D0, NULL, 1);
    return D_800F3778;
}

s32 func_80013974(s32 arg0) {
    osRecvMesg(&D_800D12D0, 0, 1);
    if (D_800D12B0 < 8) {
        osSendMesg(&D_800D12D0, 0, 1);

        osContStartReadData(&D_800EE960);
        osRecvMesg(&D_800EE960, 0, 1);

        osContGetReadData(D_800D1170[D_800D12B4].pad);

        osRecvMesg(&D_800D12D0, 0, 1);

        D_800D12B0++;
        D_800D12B4++;
        if (D_800D12B4 >= 8) {
            D_800D12B4 = 0;
        }
    }
    osSendMesg(&D_800D12D0, 0, 1);

    return 0;
}

void func_80013A74(void) {
    osRecvMesg(&D_800D12D0, NULL, 1);
    if (D_800D12B0 < 8) {
        RequestSIFunction(&D_800D1230[D_800D12B4], (void*)&func_80013974, 0, 0);
    }
    osSendMesg(&D_800D12D0, NULL, 1);
}

void func_80013AEC(s8 arg0, s8 arg1) {
    D_800D12BE = arg0;
    D_800D12BF = arg1;
}

s16 func_80013B00(void);

// Logic rewritten from the asm 2026-10-03 (upstream C read the wrong slot and pad), then matched.
// Consumes the oldest queued read: updates held/triggered/repeat buttons and the dead-zoned,
// clamped sticks for every pad. Returns the queue count before this read (0 = nothing read).
// decomp-permuter
s16 func_80013B00(void)
{
  s16 count;
  s16 i;
  OSContPad *slot;
  u16 btn;
  osRecvMesg(&D_800D12D0, 0, 1);
  count = D_800D12B0;
  if (count != 0)
  {
    D_800D12B0 = count - 1;
    slot = D_800D1170[D_800D12B2].pad;
    if ((++D_800D12B2) >= 8)
    {
      D_800D12B2 = 0;
    }
    for (i = 0; i < 4; i++)
    {
      D_800D12BA[i] = slot[i].errno != 0x8;
      btn = (ContBtn[i] = slot[i].button);
      ContStkX[i] = slot[i].stick_x;
      D_800F2CE2[i] = ContStkX[i];
      ContStkY[i] = slot[i].stick_y;
      D_800F33CC[i] = ContStkY[i];
      ContBtnTrg[i] = btn & (btn ^ D_800ECE08[i]);
      if (D_800ECE08[i] == btn)
      {
        if ((--D_800D12B6[i]) == 0)
        {
          D_800F338C[i] = btn;
          D_800D12B6[i] = 10;
        }
        else
        {
          D_800F338C[i] = 0;
        }
      }
      else
      {
        D_800F338C[i] = ContBtnTrg[i];
        D_800D12B6[i] = 30;
      }
      if (((u8) (ContStkX[i] + 9)) < 19)
      {
        ContStkX[i] = 0;
      }
      else
        if (ContStkX[i] > D_800D12BE)
      {
        ContStkX[i] = D_800D12BE;
      }
      else
        if (ContStkX[i] < (-D_800D12BE))
      {
        ContStkX[i] = -D_800D12BE;
      }
      if (((u8) (ContStkY[i] + 9)) < 19)
      {
        ContStkY[i] = 0;
      }
      else
        if (ContStkY[i] > D_800D12BF)
      {
        ContStkY[i] = D_800D12BF;
      }
      else
        if (ContStkY[i] < (-D_800D12BF))
      {
        ContStkY[i] = -D_800D12BF;
      }
      D_800ECE08[i] = btn;
    }

  }
  osSendMesg(&D_800D12D0, 0, 1);
  return count;
}

extern s8 D_800F0A40[PAD_COUNT][8];   /* per-pad stick X history, one entry per queued read */
extern s8 D_800F5258[PAD_COUNT][8];   /* per-pad stick Y history */
extern s16 D_800F5440;                /* reads consumed by the last func_80013E84 */

/* Drains every queued controller read: ORs the trigger/repeat bits together, sums the sticks
 * into D_800F2CE2/D_800F33CC and records each read's stick values. At most 8 reads are queued
 * (D_800D12B0 < 8), so the history index stays in bounds. */
s16 func_80013E84(void) {
    u16 trg[PAD_COUNT];
    u16 rep[PAD_COUNT];
    s16 i;
    s16 n = 0;

    if (func_80013B00() > 0) {
        for (i = 0; i < PAD_COUNT; i++) {
            trg[i] = ContBtnTrg[i];
            rep[i] = D_800F338C[i];
            D_800F2CE2[i] = ContStkX[i];
            D_800F33CC[i] = ContStkY[i];
            D_800F0A40[i][n] = ContStkX[i];
            D_800F5258[i][n] = ContStkY[i];
        }
        n++;
        while (func_80013B00() != 0) {
            for (i = 0; i < PAD_COUNT; i++) {
                trg[i] |= ContBtnTrg[i];
                rep[i] |= D_800F338C[i];
                D_800F2CE2[i] += ContStkX[i];
                D_800F33CC[i] += ContStkY[i];
                D_800F0A40[i][n] = ContStkX[i];
                D_800F5258[i][n] = ContStkY[i];
            }
            n++;
        }
        for (i = 0; i < PAD_COUNT; i++) {
            ContBtnTrg[i] = trg[i];
            D_800F338C[i] = rep[i];
        }
    }
    D_800F5440 = n;
    return n;
}

void func_80014158(void) {
    func_80013974(0);
}

extern void func_8006407C(functionListEntry * entry, s16 type, void * func);
void func_80014174(void) {
    if (D_800D12CC != 0) {
        func_800141C4();
    }
    func_8006407C((functionListEntry*) &D_800D12C0, 0, func_80014158);
    D_800D12CC = 1;
}

extern void func_80064158(void *entry);
void func_800141C4(void) {
    if (D_800D12CC != 0) {
        func_80064158(&D_800D12C0);
    }
    D_800D12CC = 0;
}

s32 func_800141FC(s16 arg0) {
    return D_800D12BA[arg0];
}

