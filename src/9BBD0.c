#include "common.h"

// KMC libm: asin, acos (domain errors go to matherr, func_8009BA30).

f64 func_8009BA30(s32 type, char* name, f64 arg1, f64 arg2, f64 retval); // matherr
f64 func_8009B420(f64 y, f64 x);                                         // atan2 (9BD50.c)
f64 sqrt(f64 x);

// asin
f64 func_8009AFD0(f64 x) {
    if ((x > 1.0) | (x < -1.0)) {
        return func_8009BA30(1, "asin", x, 0.0, 0.0);
    }
    return func_8009B420(x, sqrt(1.0 - x * x));
}

// acos
f64 func_8009B0A8(f64 x) {
    if ((x > 1.0) | (x < -1.0)) {
        return func_8009BA30(1, "acos", x, 0.0, 0.0);
    }
    return 1.5707963267948966 - func_8009AFD0(x);
}
