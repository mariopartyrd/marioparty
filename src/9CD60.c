#include "sdk_hu1.h"

/* guNormalize */
void func_8009C160(f32* x, f32* y, f32* z) {
    f32 m;

    m = 1 / func_800B1750((*x) * (*x) + (*y) * (*y) + (*z) * (*z));
    *x *= m;
    *y *= m;
    *z *= m;
}
