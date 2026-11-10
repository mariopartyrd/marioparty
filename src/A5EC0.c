#include "common.h"

void func_800AF2E0(f32, f32*, f32*);

/* guRotateRPY (Hudson; m is the Mtx as halfwords: 16 integer parts, then 16 fractions) */
void func_800A52C0(u16* m, Vec3f* rpy) {
    f32 sr;
    f32 cr;
    f32 sp;
    f32 cp;
    f32 sh;
    f32 ch;
    s32 e1;
    s32 e2;

    func_800AF2E0(rpy->x, &sr, &cr);
    func_800AF2E0(rpy->y, &sp, &cp);
    func_800AF2E0(rpy->z, &sh, &ch);
    e1 = cp * ch * 65536.0f;
    e2 = cp * sh * 65536.0f;
    *m = e1 >> 16;
    *(m + 1) = e2 >> 16;
    *(m + 16) = e1;
    *(m + 17) = e2;
    e1 = -sp * 65536.0f;
    *(m + 2) = e1 >> 16;
    *(m + 3) = 0;
    *(m + 18) = e1;
    *(m + 19) = 0;
    e1 = (sr * sp * ch - cr * sh) * 65536.0f;
    e2 = (sr * sp * sh + cr * ch) * 65536.0f;
    *(m + 4) = e1 >> 16;
    *(m + 5) = e2 >> 16;
    *(m + 20) = e1;
    *(m + 21) = e2;
    e1 = sr * cp * 65536.0f;
    *(m + 6) = e1 >> 16;
    *(m + 7) = 0;
    *(m + 22) = e1;
    *(m + 23) = 0;
    e1 = (cr * sp * ch + sr * sh) * 65536.0f;
    e2 = (cr * sp * sh - sr * ch) * 65536.0f;
    *(m + 8) = e1 >> 16;
    *(m + 9) = e2 >> 16;
    *(m + 24) = e1;
    *(m + 25) = e2;
    e1 = cr * cp * 65536.0f;
    *(m + 10) = e1 >> 16;
    *(m + 11) = 0;
    *(m + 26) = e1;
    *(m + 27) = 0;
    *(m + 12) = 0;
    *(m + 13) = 0;
    *(m + 28) = 0;
    *(m + 29) = 0;
    *(m + 14) = 0;
    *(m + 15) = 1;
    *(m + 30) = 0;
    *(m + 31) = 0;
}
