#include "common.h"
#include "sdk_hu2.h"

/* guFrustum */
void func_800A2720(Mtx* m, HuViewVolume* v) {
    Matrix4f mf;

    func_800A2510(mf, v);
    func_800A0A20(mf, m);
}
