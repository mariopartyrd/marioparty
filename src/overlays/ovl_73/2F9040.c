#include "common.h"

void func_800F6748_name_73(void);
void func_800F6764_name_73(void);
void func_800F6790_name_73(void);

board_overlay_entrypoint D_800F6B90_name_73[] = {
    {2, func_800F6748_name_73},
    {5, func_800F6764_name_73},
    {6, func_800F6790_name_73},
    {-1, 0}
};

void func_800F65E0_name_73(void) {
    ExecBoardScene(D_800F6B90_name_73, D_800C597A);
}