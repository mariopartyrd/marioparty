#include "common.h"

void func_800F666C_MinigameIslandOverworldCopy(void);
void func_800F669C_MinigameIslandOverworldCopy(void);
void func_800F6814_MinigameIslandOverworldCopy(void);
void func_800F6830_MinigameIslandOverworldCopy(void);
void func_800F685C_MinigameIslandOverworldCopy(void);
void func_800F6888_MinigameIslandOverworldCopy(void);
void func_800F68B4_MinigameIslandOverworldCopy(void);

board_overlay_entrypoint D_800F80B0_MinigameIslandOverworldCopy[] = {
    {0, func_800F666C_MinigameIslandOverworldCopy},
    {1, func_800F669C_MinigameIslandOverworldCopy},
    {2, func_800F6814_MinigameIslandOverworldCopy},
    {5, func_800F6830_MinigameIslandOverworldCopy},
    {6, func_800F685C_MinigameIslandOverworldCopy},
    {7, func_800F6888_MinigameIslandOverworldCopy},
    {8, func_800F68B4_MinigameIslandOverworldCopy},
    {-1, 0}
};

void func_800F65E0_MinigameIslandOverworldCopy(void) {
    ExecBoardScene(D_800F80B0_MinigameIslandOverworldCopy, D_800C597A);
}
