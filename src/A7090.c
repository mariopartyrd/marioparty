#include "common.h"

/* guPositionF (Hudson) from precomputed {sin, cos} pairs (roll, pitch, heading) */
void func_800A6490(Matrix4f m, Vec2f* sc, Vec3f* scale, Vec3f* trans) {
    Vec2f* r;
    Vec2f* p;
    Vec2f* h;
    Vec3f s;
    Vec3f t;

    r = &sc[0];
    p = &sc[1];
    h = &sc[2];
    s = *scale;
    t = *trans;
    m[0][0] = s.x * (p->y * h->y);
    m[0][1] = s.y * (p->y * h->x);
    m[0][2] = s.z * -p->x;
    m[0][3] = 0.0f;
    m[1][0] = s.x * (r->x * p->x * h->y - r->y * h->x);
    m[1][1] = s.y * (r->x * p->x * h->x + r->y * h->y);
    m[1][2] = s.z * (r->x * p->y);
    m[1][3] = 0.0f;
    m[2][0] = s.x * (r->y * p->x * h->y + r->x * h->x);
    m[2][1] = s.y * (r->y * p->x * h->x - r->x * h->y);
    m[2][2] = s.z * (r->y * p->y);
    m[2][3] = 0.0f;
    m[3][0] = t.x;
    m[3][1] = t.y;
    m[3][2] = t.z;
    m[3][3] = 1.0f;
}
