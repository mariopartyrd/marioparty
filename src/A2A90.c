#include "common.h"
#include "sdk_hu2.h"

/* guLookAtReflect */
void func_800A1E90(Mtx* m, LookAt* l, Vec3f* p) {
    Matrix4f mf;
    Vec3f tmp[3];

    func_800A1BD0(mf, l, p, tmp);
    func_800A0A20(mf, m);
}
