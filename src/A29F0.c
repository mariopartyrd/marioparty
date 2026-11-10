#include "common.h"
#include "sdk_hu2.h"

/* guLookAt */
void func_800A1DF0(Mtx* m, Vec3f* p) {
    Matrix4f mf;
    Vec3f tmp[3];

    func_800A18F0(mf, p, tmp);
    func_800A0A20(mf, m);
}
