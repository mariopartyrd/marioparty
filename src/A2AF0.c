#include "common.h"
#include "sdk_hu2.h"

f32 Vec3SqDistance(Vec3f*);
void func_800A0F70(Vec3f* out, Vec3f* a, f32 s, Vec3f* b);
f32 func_800A1480(Vec3f*, Vec3f*);

/* guLookAtHiliteF (Hudson) */
void func_800A1EF0(Matrix4f mf, LookAt* l, Hilite* h, HuLookAtHiliteArg* p) {
    Vec3f tmp[3];
    Vec3f hv;
    f32 len;

    func_800A1BD0(mf, l, p->v, tmp);
    len = func_800A1200(&p->l1);
    func_800A0F70(&hv, &tmp[2], 1.0f / len, &p->l1);
    len = Vec3SqDistance(&hv);
    if (len > 0.01f) {
        func_800A0F00(&hv, 1.0f / func_800B1750(len), &hv);
        h->h.x1 = 2.0f * ((func_800A1480(&hv, &tmp[0]) + 2.0f) * p->tw);
        h->h.y1 = 2.0f * ((func_800A1480(&hv, &tmp[1]) + 2.0f) * p->th);
    } else {
        h->h.x1 = 2.0f * p->tw;
        h->h.y1 = 2.0f * p->th;
    }
    len = func_800A1200(&p->l2);
    func_800A0F70(&hv, &tmp[2], 1.0f / len, &p->l2);
    len = Vec3SqDistance(&hv);
    if (len > 0.01f) {
        func_800A0F00(&hv, 1.0f / func_800B1750(len), &hv);
        h->h.x2 = 2.0f * ((func_800A1480(&hv, &tmp[0]) + 2.0f) * p->tw);
        h->h.y2 = 2.0f * ((func_800A1480(&hv, &tmp[1]) + 2.0f) * p->th);
    } else {
        h->h.x2 = 2.0f * p->tw;
        h->h.y2 = 2.0f * p->th;
    }
}
