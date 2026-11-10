#ifndef OVL62_H
#define OVL62_H

/* ovl_62 BoardIntro: declarations shared by its units. The objects below are defined in
   2A2500's .data and used by several units; each type is the one the code's accesses show. */

#include "common.h"

/* Board index for the intro (= GwSystem.curBoardIndex, set by func_800F65E0): fixed scratch RAM
   above the overlay. */
extern u8 D_801102B0; /* an undefined_syms label (no overlay suffix) */

extern Object* D_800FCD70_BoardIntro;
/* Model/sprite ids kept as words; retail also reads their low halves (big-endian +2) as s16 under
   their own labels. On the host the low half is the word's value. */
extern s32 D_800FCD74_BoardIntro;
extern s32 D_800FCD78_BoardIntro[4];
extern s16 D_800FCD76_BoardIntro;
extern s16 D_800FCD7A_BoardIntro;
/* Four models; splat split [1] off as D_800FCD8C and [2..3] as D_800FCD90 (N64 aliases only). */
extern Object* D_800FCD88_BoardIntro[4];
extern s32 D_800FCDA8_BoardIntro;
extern Process* D_800FCDB4_BoardIntro;
/* One camera position per board (indexed by D_801102B0); splat split it into the labels
   D_800FD3CC/D0/D4 (.x/.y/.z of element 0). Use D_800FD3CC_BoardIntro[i].x/.y/.z. */
extern Vec3f D_800FD3CC_BoardIntro[8];
extern Vec3f D_800FD42C_BoardIntro;
/* MBModelCreate motion list: a count word, then file ids (s32, never s16 halves). */
extern s32 D_800FD528_BoardIntro[4];

/* Functions called across units. */
void func_800F66E8_BoardIntro(void);  /* 2A2500 */
void func_800FBBB8_BoardIntro(void);  /* 2A76E0 */
void func_800FC460_BoardIntro(void);  /* 2A76E0 */
void func_800FC768_BoardIntro(void);  /* 2A76E0 */

#endif
