#include "common.h"

/* KMC libm matherr: the default handler (returns 0, so the caller sets errno). */
s32 func_8009C090(void* exc) { /* matherr */
    return 0;
}
