#include "common.h"

typedef struct unkFloatStruct unkFloatStruct;
void func_800A2770(Matrix4f arg0, u16* perspNorm, unkFloatStruct* arg2);

/* guPerspective */
void func_800A2A00(Mtx* m, u16* perspNorm, unkFloatStruct* p) {
    Matrix4f mf;

    func_800A2770(mf, perspNorm, p);
    func_800A0A20(mf, m);
}
