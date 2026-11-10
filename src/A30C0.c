#include "common.h"
#include "sdk_hu2.h"

/* guOrtho */
void func_800A24C0(Mtx* m, HuViewVolume* v) {
    Matrix4f mf;

    func_800A22E0(mf, v);
    func_800A0A20(mf, m);
}
