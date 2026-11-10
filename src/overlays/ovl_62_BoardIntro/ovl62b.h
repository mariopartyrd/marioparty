#ifndef OVL62B_H
#define OVL62B_H

/* ovl_62 BoardIntro, units 2A51E0..2A76E0. */

#include "common.h"
#include "ovl62.h"
#define MDL88_0 (D_800FCD88_BoardIntro[0])
#define MDL88_1 (D_800FCD88_BoardIntro[1])
#define MDL88_2 (D_800FCD88_BoardIntro[2])
/* Camera move along two points; returns its length in frames. */
s32 func_8004FD68(Vec3f*, Vec3f*, f32);
s32 func_8004FEA0(Vec3f*, Vec3f*);
void func_8004FAB8(s32);

#endif
