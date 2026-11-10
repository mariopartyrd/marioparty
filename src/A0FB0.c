#include "sdk_hu1.h"

/* guMtxXFML (Hudson): m is an Mtx seen as its integer halves [0] and fraction halves [1]. */
#define MTXL(m, i, j) ((f32)(((m)[0][i][j] << 16) | (m)[1][i][j]) * (1.0f / 65536.0f))

void func_800A03B0(u16 m[2][4][4], f32 x, f32 y, f32 z, f32* ox, f32* oy, f32* oz) {
    *ox = MTXL(m, 0, 0) * x + MTXL(m, 1, 0) * y + MTXL(m, 2, 0) * z + MTXL(m, 3, 0);
    *oy = MTXL(m, 0, 1) * x + MTXL(m, 1, 1) * y + MTXL(m, 2, 1) * z + MTXL(m, 3, 1);
    *oz = MTXL(m, 0, 2) * x + MTXL(m, 1, 2) * y + MTXL(m, 2, 2) * z + MTXL(m, 3, 2);
}
