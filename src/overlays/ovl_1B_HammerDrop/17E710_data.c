#include "HammerDrop.h"

/* 17E710.c's initialised data, then its switch table (jtbl_800FB608, below). */
s32 D_800FB590_HammerDrop[4] = { 15, 10, 5, 1 };
f32 D_800FB5A0_HammerDrop = 0.0f; /* background texture scroll (func_800FB050) */
f32 D_800FB5A4_HammerDrop = 0.0f;
f32 D_800FB5A8_HammerDrop = 1024.0f;
f32 D_800FB5AC_HammerDrop = 1024.0f;
f32 D_800FB5B0_HammerDrop = 12.8f;
f32 D_800FB5B4_HammerDrop[3] = { 12.8f, 0.0f, 0.0f };
u8 D_800FB5C0_HammerDrop[8] = { 0x82, 0x60, 0x82, 0x61, 0x82, 0x62, 0, 0 }; /* "ＡＢＣ" (Shift-JIS) */
f32 D_800FB5C8_HammerDrop[4] = { -300.0f, 0.0f, 300.0f, 0.0f };
f32 D_800FB5D8_HammerDrop[4] = { 0.0f, 300.0f, 0.0f, -300.0f };
f32 D_800FB5E8_HammerDrop[4] = { 90.0f, 180.0f, 270.0f, 0.0f };
f32 D_800FB5F8_HammerDrop[4] = { 500.0f, 650.0f, 700.0f, 1200.0f };
/* func_800F7D64's switch table, for the N64 asm path: the overlay runs at a fixed address, so
   its case labels are written as their addresses. The C path's switch builds its own table. */
u32 jtbl_800FB608_HammerDrop[6] = { 0x800F7D94, 0x800F7DA8, 0x800F7DB8, 0x800F7DC8, 0x800F7DD8, 0x800F7DE0 };
