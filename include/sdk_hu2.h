#ifndef SDK_HU2_H
#define SDK_HU2_H

/* Hudson's -O0 gu math (main units A1330-A7090): argument blocks the matrix builders take. */

/* guOrthoF / guFrustumF (func_800A22E0, func_800A2510) */
typedef struct HuViewVolume {
    /* 0x00 */ f32 l;
    /* 0x04 */ f32 r;
    /* 0x08 */ f32 b;
    /* 0x0C */ f32 t;
    /* 0x10 */ f32 n;
    /* 0x14 */ f32 f;
    /* 0x18 */ f32 scale;
} HuViewVolume;

/* guLookAtHiliteF (func_800A1EF0): eye/at/up, two light directions, texture size */
typedef struct HuLookAtHiliteArg {
    /* 0x00 */ Vec3f v[3];
    /* 0x24 */ Vec3f l1;
    /* 0x30 */ Vec3f l2;
    /* 0x3C */ s32 tw;
    /* 0x40 */ s32 th;
} HuLookAtHiliteArg;

/* {sin, cos} of roll, pitch and heading (func_800A56D0, func_800A5900) */
typedef struct HuRPYSinCos {
    /* 0x00 */ f32 sr;
    /* 0x04 */ f32 cr;
    /* 0x08 */ f32 sp;
    /* 0x0C */ f32 cp;
    /* 0x10 */ f32 sh;
    /* 0x14 */ f32 ch;
} HuRPYSinCos;

void func_800A18F0(Matrix4f mf, Vec3f* p, Vec3f* tmp);
void func_800A1BD0(Matrix4f mf, LookAt* l, Vec3f* p, Vec3f* tmp);
void func_800A1EF0(Matrix4f mf, LookAt* l, Hilite* h, HuLookAtHiliteArg* p);
void func_800A22E0(Matrix4f mf, HuViewVolume* v);
void func_800A2510(Matrix4f mf, HuViewVolume* v);

#endif
