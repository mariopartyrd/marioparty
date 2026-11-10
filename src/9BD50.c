#include "common.h"

// KMC libm: a 52-step CORDIC arctangent on 2.60 fixed point, atan and atan2.

extern s64 D_800C7C10[]; // atan(2^-i) in 2.60 fixed point

f64 func_8009BA30(s32 type, char* name, f64 arg1, f64 arg2, f64 retval); // matherr
s64 __fixdfdi(f64 x);
f64 __floatdidf(s64 x);

// CORDIC: *out = atan(y / x) for x > 0.
void func_8009B150(s64 x0, s64 y0, f64* out) {
    s64 x = x0;
    s64 y = y0;
    s64 z = 0;
    s64 nx;
    s32 i;

    for (i = 0; i < 52; i++) {
        if (y >= 0) {
            nx = x + (y >> i);
            y = y - (x >> i);
            z += D_800C7C10[i];
        } else {
            nx = x - (y >> i);
            y = y + (x >> i);
            z -= D_800C7C10[i];
        }
        x = nx;
    }
    *out = (f64)z / 1152921504606846976.0;
}

// atan
f64 func_8009B308(f64 x) {
    s32 sign;
    s64 a;
    s64 b;
    f64 r;

    if (x < 0.0) {
        x = -x;
        sign = -1;
    } else {
        sign = 1;
    }
    if (1e-7 < x) {
        if (1.0 <= x) {
            b = 0x1000000000000000LL;
            a = 1.0 / x * 1152921504606846976.0;
        } else {
            a = 0x1000000000000000LL;
            b = x * 1152921504606846976.0;
        }
        func_8009B150(a, b, &r);
    } else {
        r = x;
    }
    return (sign < 0) ? -r : r;
}

// atan2
f64 func_8009B420(f64 y, f64 x) {
    f64 r;

    if ((x == 0.0) & (y == 0.0)) {
        return func_8009BA30(1, "atan2", x, y, 0.0);
    }
    if (x == 0.0) {
        if (y > 0.0) {
            return 1.5707963267948966;
        }
        return -1.5707963267948966;
    }
    r = func_8009B308(y / x);
    if (x > 0.0) {
        return r;
    }
    if (y == 0.0) {
        return 3.141592653589793;
    }
    if (y > 0.0) {
        return r + 3.141592653589793;
    }
    return r - 3.141592653589793;
}
