#include "common.h"
#include "sdk_hu2.h"

/* guLookAtHilite */
void func_800A2280(Mtx* m, LookAt* l, Hilite* h, HuLookAtHiliteArg* p) {
    Matrix4f mf;

    func_800A1EF0(mf, l, h, p);
    func_800A0A20(mf, m);
}
