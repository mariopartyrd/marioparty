#include "common.h"
#include "TightropeTreachery.h"

/* .data (0x800FE300..0x800FE350) */
s8 D_800FE300_TightropeTreachery = 0; /* the rope is sliding forward */
s8 D_800FE301_TightropeTreachery = 0; /* camera shake on */
s16 D_800FE302_TightropeTreachery = 0; /* camera shake frame */
f32 D_800FE304_TightropeTreachery = 0.0f;
f32 D_800FE308_TightropeTreachery[4][2] = {
    { 10.0f, 10.0f }, { -10.0f, 10.0f }, { 10.0f, -10.0f }, { -10.0f, -10.0f },
};
s8 D_800FE328_TightropeTreachery = 0;
s8 D_800FE32C_TightropeTreachery[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
s8 D_800FE334_TightropeTreachery[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
s8 D_800FE33C_TightropeTreachery = 0; /* stick-sample ring index */
u16 D_800FE33E_TightropeTreachery = 0; /* the CPU's previous buttons */
s32 D_800FE340_TightropeTreachery = 0;

void func_800F8B20_TightropeTreachery(f32 zoom, f32 rx, f32 ry, f32 rz, f32 cx, f32 cy, f32 cz) {
    CZoom = D_800FE8A8_TightropeTreachery = zoom;
    CRot.x = D_800FE8B4_TightropeTreachery = rx;
    CRot.y = D_800FE7C4_TightropeTreachery = ry;
    CRot.z = D_800FE8C4_TightropeTreachery = rz;
    Center.x = D_800FE8A4_TightropeTreachery = cx;
    Center.y = D_800FE8B0_TightropeTreachery = cy;
    Center.z = D_800FE7C0_TightropeTreachery = cz;
}

void func_800F8BA0_TightropeTreachery(void) {
    if (D_800FE301_TightropeTreachery == 1) {
        f32 dx = D_800FE308_TightropeTreachery[D_800FE302_TightropeTreachery & 3][0];
        f32 dy = D_800FE308_TightropeTreachery[D_800FE302_TightropeTreachery & 3][1];

        Center.x = dx + D_800FE8A4_TightropeTreachery;
        Center.y = dy + D_800FE8B0_TightropeTreachery;
        if (++D_800FE302_TightropeTreachery >= 11) {
            D_800FE301_TightropeTreachery = 0;
            D_800FE302_TightropeTreachery = 0;
        }
    } else {
        Center.x = D_800FE8A4_TightropeTreachery;
        Center.y = D_800FE8B0_TightropeTreachery;
    }
    CZoom = D_800FE8A8_TightropeTreachery;
    CRot.x = D_800FE8B4_TightropeTreachery;
    CRot.y = D_800FE7C4_TightropeTreachery;
    CRot.z = D_800FE8C4_TightropeTreachery;
    Center.z = D_800FE7C0_TightropeTreachery;
}

void func_800F8CA8_TightropeTreachery(void) {
    if (D_800F5144 == 1) {
        if (D_800FE328_TightropeTreachery == 0) {
            func_800726AC(0, 20);
            D_800FE328_TightropeTreachery = 1;
        } else if (func_80072718() == 0) {
            func_800601D4(40);
            GMesSprClose();
            omOvlReturnEx(1);
        }
    }
}

/* The shadow: smaller the higher the object is. */
void func_800F8D20_TightropeTreachery(omObjData* obj) {
    f32 scale = 0.4f - obj->trans.y * 0.0015f;

    func_80025830(obj->model[1], scale, 0.0f, scale);
    func_80025798(obj->model[1], obj->trans.x, 2.4f, obj->trans.z);
}

/* The stick direction of player 0's port, averaged over 8 frames (-1 near the centre). */
f32 func_800F8DA4_TightropeTreachery(void) {
    s8 port = TT_WORK(D_800F3FB0[0])->port;
    s8 y = ContStkY[port];
    s8 x = ContStkX[port];
    f32 sumX;
    f32 sumY;
    f32 angle;
    s16 i;

    if (x > 60) {
        x = 60;
    }
    if (y > 60) {
        y = 60;
    }
    if (x < -60) {
        x = -60;
    }
    if (y < -60) {
        y = -60;
    }
    D_800FE32C_TightropeTreachery[D_800FE33C_TightropeTreachery] = (f32)x;
    D_800FE334_TightropeTreachery[D_800FE33C_TightropeTreachery] = (f32)y;
    D_800FE33C_TightropeTreachery = (D_800FE33C_TightropeTreachery + 1) & 7;
    sumX = sumY = 0.0f;
    for (i = 0; i < 8; i++) {
        sumX += D_800FE32C_TightropeTreachery[i];
        sumY += D_800FE334_TightropeTreachery[i];
    }
    sumX /= 8.0f;
    sumY /= 8.0f;
    if (sumX * sumX + sumY * sumY > 100.0f) {
        angle = func_800B0CD8(sumX, -sumY) + 180.0f;
    } else {
        angle = -1.0f;
    }
    return angle;
}

/* Rotation of angle about axis, translated (retail uses pos->z where pos->x would be expected;
   ovl_11's func_800FA1D8_BowlOver is the same function). */
void func_800F8F70_TightropeTreachery(Vec3f* pos, Vec3f* axis, f32 angle, Mat4 m) {
    f32 s;
    f32 c;
    f32 t;
    f32 x;
    f32 y;
    f32 z;
    f32 xx;
    f32 yy;
    f32 zz;
    f32 xs;
    f32 ys;
    f32 zs;
    f32 xy;
    f32 xz;
    f32 yz;
    f32 txy;
    f32 txz;
    f32 tyz;
    f32 py;
    f32 pz;

    func_800AF2E0(angle, &s, &c);
    t = 1.0f - c;
    pz = pos->z;
    py = pos->y;
    x = axis->x;
    y = axis->y;
    z = axis->z;
    xy = x * y;
    yz = y * z;
    xz = z * x;
    xx = x * x;
    yy = y * y;
    zz = z * z;
    xs = x * s;
    ys = y * s;
    zs = z * s;
    m[3][3] = 1.0f;
    m[0][3] = m[1][3] = m[2][3] = 0.0f;
    m[0][0] = t * xx + c;
    txy = t * xy;
    m[0][1] = txy + zs;
    txz = t * xz;
    m[0][2] = txz - ys;
    m[1][0] = txy - zs;
    m[1][1] = t * yy + c;
    tyz = t * yz;
    m[1][2] = tyz + xs;
    m[2][0] = txz + ys;
    m[2][1] = tyz - xs;
    m[2][2] = t * zz + c;
    m[3][0] = pz * t * (1.0f - xx) + py * (zs - txy) - pz * (txz + ys);
    m[3][1] = -pz * (txy + zs) + py * t * (1.0f - yy) + pz * (xs - tyz);
    m[3][2] = pz * (ys - txz) - py * (tyz + xs) + pz * t * (1.0f - zz);
}

/* A CPU player on the rope presses nothing but Z. */
void func_800F9168_TightropeTreachery(TTPlayerWork* work) {
    u16 btn = 0;

    if (ContBtn[work->port] & 0x1000) {
        btn |= 0x1000;
    }
    ContBtnTrg[work->port] = ContBtn[work->port] = btn;
    ContBtnTrg[work->port] = btn & (btn ^ D_800FE33E_TightropeTreachery);
    D_800FE33E_TightropeTreachery = btn;
    ContStkX[work->port] = 0;
    ContStkY[work->port] = 0;
}

void func_800F9204_TightropeTreachery(omObjData* obj, f32 dist) {
    D_800FE304_TightropeTreachery -= dist;
    /* func_80009028's s32 slot holds a float (the floor height); retail passed it as an f32 */
    FUNC_80009028_F(obj, -600.0f, -800.0f, -1200.0f, 800.0f, D_800FE304_TightropeTreachery + 1200.0f);
    func_80009090(obj);
}

/* Keeps a position on the board: x within +-660, z within the rope's moving window. */
void func_800F927C_TightropeTreachery(omObjData* obj, f32* dx, f32* dz) {
    f32 x = obj->trans.x + *dx;
    f32 z = obj->trans.z + *dz;

    if (x < -660.0f) {
        x = -660.0f;
        obj->trans.x = -660.0f;
        *dx = 0.0f;
    }
    if (x > 660.0f) {
        obj->trans.x = 660.0f;
        *dx = 0.0f;
    }
    if (D_800FE300_TightropeTreachery == 0) {
        if (D_800FE304_TightropeTreachery + 1000.0f - 140.0f < z) {
            z = D_800FE304_TightropeTreachery + 1000.0f - 140.0f;
            obj->trans.z = z;
            *dz = 0.0f;
        }
        if (z < D_800FE304_TightropeTreachery + -740.0f + 140.0f) {
            obj->trans.z = D_800FE304_TightropeTreachery + -740.0f + 140.0f;
            *dz = 0.0f;
        }
    }
}

/* Park-Miller minimal standard generator (Schrage's method). */

s32 func_800F937C_TightropeTreachery(u32 seed) {
    s32 hi;
    s32 lo;

    if (seed == 0) {
        seed = rand8();
        seed = seed ^ guRandom();
        seed ^= 0xD826BC89;
    }
    hi = seed / 127773;
    lo = seed - hi * 127773;
    seed = hi * 2836;
    seed = seed - lo * 16807;
    return seed;
}

s32 func_800F9450_TightropeTreachery(void) {
    return D_800FE340_TightropeTreachery = func_800F937C_TightropeTreachery(D_800FE340_TightropeTreachery);
}
