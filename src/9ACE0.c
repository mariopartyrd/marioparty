#include <libaudio.h>
#include "synthInternals.h"

/* alFilterNew */
void func_8009A0E0(ALFilter* f, ALCmdHandler h, ALSetParam s, s32 type) {
    f->source = 0;
    f->handler = h;
    f->setParam = s;
    f->inp = 0;
    f->outp = 0;
    f->type = type;
}
