#include "common.h"

void func_800F6F0C_WariosBattleCanyon(void);
void func_800F6F48_WariosBattleCanyon(void);
void func_800F719C_WariosBattleCanyon(void);
void func_800F7314_WariosBattleCanyon(void);
void func_800F9754_WariosBattleCanyon(void);

board_overlay_entrypoint D_800F97B0_WariosBattleCanyon[] = {
{0, func_800F6F0C_WariosBattleCanyon},
{1, func_800F6F48_WariosBattleCanyon},
{2, func_800F719C_WariosBattleCanyon},
{3, func_800F7314_WariosBattleCanyon},
{4, func_800F9754_WariosBattleCanyon},
{-1, 0}
};

void func_800F65E0_WariosBattleCanyon(void) {
    ExecBoardScene(D_800F97B0_WariosBattleCanyon, D_800C597A);
}
