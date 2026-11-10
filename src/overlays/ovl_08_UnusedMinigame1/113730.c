#include "UnusedMinigame1.h"

s32 D_800F92A0_UnusedMinigame1 = 0;

void func_800F8D80_UnusedMinigame1(f32 zoom, f32 rx, f32 ry, f32 rz, f32 cx, f32 cy, f32 cz) {
    func_800178A0(1);
    CZoom = zoom;
    CRot.x = rx;
    CRot.y = ry;
    CRot.z = rz;
    Center.x = cx;
    Center.y = cy;
    Center.z = cz;
}

/* Park-Miller minimal standard generator (Schrage's method), seeded from the count register. */
s32 func_800F8E18_UnusedMinigame1(u32 x) {
    u32 hi;
    u32 lo;

    if (x == 0) {
        x = rand8();
        x ^= osGetCount();
        x ^= 0xD826BC89;
    }
    hi = x / 127773;
    lo = x % 127773;
    x = hi * 2836 - lo * 16807;
    return x;
}

void func_800F8EEC_UnusedMinigame1(void) {
    D_800F92A0_UnusedMinigame1 = func_800F8E18_UnusedMinigame1(D_800F92A0_UnusedMinigame1);
}

void func_800F8F14_UnusedMinigame1(Matrix4f m, Vec* in, Vec* out) {
    out->x = in->x * m[0][0] + in->y * m[1][0] + in->z * m[2][0] + m[3][0];
    out->y = in->x * m[0][1] + in->y * m[1][1] + in->z * m[2][1] + m[3][1];
    out->z = in->x * m[0][2] + in->y * m[1][2] + in->z * m[2][2] + m[3][2];
}

/* World `pos` to screen coordinates (x, y from the centre) for camera `cam`. */
void func_800F8FC0_UnusedMinigame1(s16 cam, Vec* pos, f32* out) {
    Vec v;
    Matrix4f mtx;
    f32 (*m)[4];
    unk_Struct00* c;
    unk_Struct00* vp;
    f32 t;
    f32 d;

    c = &D_800C3110[cam];
    m = mtx;
    HuGuLookAtF(m, c->pos.x, c->pos.y, c->pos.z, c->unkC.x, c->unkC.y, c->unkC.z, c->unk18.x, c->unk18.y,
                c->unk18.z);
    func_800F8F14_UnusedMinigame1(m, pos, &v);
    t = func_800AEAC0(c->unk_40 * 0.5);
    t /= func_800AEFD0(c->unk_40 * 0.5);
    d = t * v.z;
    if (d < 0.0f) {
        d = -d;
    }
    /* the screen's viewport scale: an s16 pair every 0x10 bytes from unk58 */
    vp = (unk_Struct00*)((u8*)c + D_800F3FA8 * 16);
    out[0] = vp->unk58 / 4.0 * v.x / d * 0.75;
    out[1] = vp->unk5A / 4.0 * -v.y / d;
}

/* Trailing zero of the unit's .rodata (retail pads it to 16 bytes). */
const f64 D_800F9408_UnusedMinigame1 = 0.0;
