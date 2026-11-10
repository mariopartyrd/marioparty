#include "AdventureModeSetup.h"

board_overlay_entrypoint D_80101840_AdventureModeSetup[] = {
    { 0, func_800F6610_AdventureModeSetup },
    { 1, func_800F6630_AdventureModeSetup },
    { 2, func_800F6654_AdventureModeSetup },
    { 3, func_800F6678_AdventureModeSetup },
    { -1, 0 },
};

void func_800F65E0_AdventureModeSetup() {
    ExecBoardScene(D_80101840_AdventureModeSetup, D_800C597A);
}
