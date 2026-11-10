#include "common.h"

void func_800F6F0C_LuigisEngineRoom(void);
void func_800F6F48_LuigisEngineRoom(void);
void func_800F719C_LuigisEngineRoom(void);
void func_800F7258_LuigisEngineRoom(void);
void func_800F9474_LuigisEngineRoom(void);

board_overlay_entrypoint D_800F94D0_LuigisEngineRoom[] = {
    {0, func_800F6F0C_LuigisEngineRoom},
    {1, func_800F6F48_LuigisEngineRoom},
    {2, func_800F719C_LuigisEngineRoom},
    {3, func_800F7258_LuigisEngineRoom},
    {4, func_800F9474_LuigisEngineRoom},
    {-1, 0},
};

void func_800F65E0_LuigisEngineRoom(void) {
    ExecBoardScene(D_800F94D0_LuigisEngineRoom, D_800C597A);
}
