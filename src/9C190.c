#include "common.h"

// KMC libm: __fint (truncate toward zero), fmod, ceil and floor.

typedef union {
    f64 d;
    s64 l;
    struct {
        u32 hi;
        u32 lo;
    } w;
} LibmDouble;

f64 func_8009B590(f64 x) {
    LibmDouble u;
    s32 e;

    u.d = x;
    e = ((u.w.hi >> 20) & 0x7FF) - 0x3FF;
    if (e < 0) {
        return 0.0;
    }
    u.l &= (s64)0x8000000000000000LL >> (e + 11);
    return u.d;
}

// fmod: 0 when y == 0.
f64 func_8009B618(f64 x, f64 y) {
    f64 r = 0.0;

    if (y != 0.0) {
        r = x - func_8009B590(x / y) * y;
    }
    return r;
}

// ceil
f64 func_8009B674(f64 x) {
    f64 t = func_8009B590(x);

    if ((x >= 0.0) & (t != x)) {
        return t + 1.0;
    }
    return t;
}

// floor
f64 func_8009B6F0(f64 x) {
    f64 t = func_8009B590(x);

    if ((x < 0.0) & (t != x)) {
        return t - 1.0;
    }
    return t;
}
