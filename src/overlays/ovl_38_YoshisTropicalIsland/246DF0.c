#include "common.h"

void func_800F6A80_YoshisTropicalIsland(void);
void func_800F6ABC_YoshisTropicalIsland(void);
void func_800F6D4C_YoshisTropicalIsland(void);
void func_800F6DC4_YoshisTropicalIsland(void);
void func_800F7FB8_YoshisTropicalIsland(void);

board_overlay_entrypoint D_800F8010_YoshisTropicalIsland[] = {
    {0, func_800F6A80_YoshisTropicalIsland},
    {1, func_800F6ABC_YoshisTropicalIsland},
    {2, func_800F6D4C_YoshisTropicalIsland},
    {3, func_800F6DC4_YoshisTropicalIsland},
    {4, func_800F7FB8_YoshisTropicalIsland},
    {-1, 0}
};

void func_800F65E0_YoshisTropicalIsland(void) {
    ExecBoardScene(D_800F8010_YoshisTropicalIsland, D_800C597A);
}
