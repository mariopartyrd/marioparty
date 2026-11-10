#include "common.h"

typedef struct Unk6C470Part {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
    /* 0x0C */ f32 radius;
    /* 0x10 */ f32 angle;
    /* 0x14 */ f32 scale;
    /* 0x18 */ s16 state;
    /* 0x1A */ s16 timer;
} Unk6C470Part; // sizeof 0x1C

typedef struct Unk6C470Work {
    /* 0x000 */ s32 unk0;
    /* 0x004 */ void (*func4)(void);
    /* 0x008 */ void (*func8)(omObjData*);
    /* 0x00C */ void (*funcC)(omObjData*);
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01C */ f32 unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ Unk6C470Part parts[10];
    /* 0x13C */ Unk6C470Part parts2[10];
    /* 0x254 */ s16 sprites[23];
    /* 0x282 */ u16 unk282;
    /* 0x284 */ u16 unk284;
    /* 0x286 */ u16 unk286;
    /* 0x288 */ u16 unk288;
    /* 0x28A */ u16 unk28A;
    /* 0x28C */ u16 unk28C;
    /* 0x28E */ u16 unk28E;
} Unk6C470Work; // sizeof 0x290

extern s16 D_800E4130[4];

u16 func_8001E1D0(s16, s32);
void func_8001E268(s16, u8, u8);
void func_8001E2A8(s16, u16);
f32 func_80025D18(s16);
f32 func_80025D40(s16);

void func_8006BC38(omObjData* obj);
void func_8006BFF0(omObjData* obj);
s32 func_8006C058(omObjData* obj);
void func_8006C5A8(omObjData* obj);
void func_8006C7A4(omObjData* obj);

void func_8006B870(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_800E4130[i] = -1;
    }
}

s32 func_8006B8A4(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u16 arg4) {
    omObjData* obj;
    Unk6C470Work* w;
    s16* mdl;
    s32 i;

    obj = omAddObj(arg0, 0x17, 0, -1, func_8006BC38);
    mdl = obj->model;
    for (i = 0; i < 0x17; i++) {
        *mdl++ = -1;
    }
    w = func_80023684(sizeof(*w), 0x7918);
    obj->unk_50 = w;
    func_8009B770(w, 0, sizeof(*w));
    w->unk282 = arg1;
    w->unk284 = arg2;
    w->unk286 = arg3;
    w->unk288 = arg4;
    w->unk28A = 0x18;
    w->unk28C = 0x78;
    w->unk28E = 1;
    w->unk20 = 0;
    w->func4 = NULL;
    w->func8 = func_8006C5A8;
    w->funcC = func_8006C7A4;
    return (s32)obj;
}

void func_8006B9B0(omObjData* obj, f32 x, f32 y, f32 z) {
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = z;
}

void func_8006B9C0(omObjData* obj, f32 x, f32 y, f32 z) {
    obj->rot.x = x;
    obj->rot.y = y;
    obj->rot.z = z;
}

void func_8006B9D0(omObjData* obj, f32 x, f32 y, f32 z) {
    Unk6C470Work* w = obj->unk_50;
    s16 mdl;
    f32 s;

    obj->scale.x = x;
    obj->scale.y = y;
    obj->scale.z = z;
    w->unk28C = y * 120.0f;
    w->unk28E = y;
    mdl = obj->model[2];
    if (mdl >= 0) {
        s = y * 3.0f;
        func_80025798(mdl, s, s, s);
    }
}

void func_8006BAD0(omObjData* obj, f32 arg1) {
    ((Unk6C470Work*)obj->unk_50)->unk1C = arg1;
}

void func_8006BADC(omObjData* obj, f32 x, f32 y, f32 z) {
    Unk6C470Work* w = obj->unk_50;

    w->unk10 = x;
    w->unk14 = y;
    w->unk18 = z;
}

void func_8006BAF0(omObjData* obj, s32 arg1) {
    ((Unk6C470Work*)obj->unk_50)->unk20 = arg1;
}

s32 func_8006BAFC(omObjData* obj) {
    return ((Unk6C470Work*)obj->unk_50)->unk20;
}

void func_8006BB08(omObjData* obj, u16 mode) {
    s16 mdl = obj->model[0];
    Unk6C470Part* p;
    s16 i;

    if (mdl >= 0) {
        switch (mode) {
        case 0:
            func_80025CA8(mdl, 0.0f);
            break;
        case 4:
            p = ((Unk6C470Work*)obj->unk_50)->parts;
            for (i = 10; i != 0; i--) {
                p->state = 0;
                p++;
            }
            p = ((Unk6C470Work*)obj->unk_50)->parts2;
            for (i = 10; i != 0; i--) {
                p->state = 0;
                p++;
            }
            break;
        }
        func_800258EC(mdl, 4, mode);
        func_800258EC(obj->model[1], 4, mode);
        for (i = 2; i < 0x17; i++) {
            func_800258EC(obj->model[i], 4, 4);
        }
    }
}

// register allocation: obj and j swap s5/s6 (masked 0)
#ifdef NON_MATCHING
void func_8006BC38(omObjData* obj) {
    Unk6C470Work* w = obj->unk_50;
    u16 idx;
    s16 sprite;
    s32 i;
    s16 j;
    s16 k;

    if (D_800E4130[0] < 0) {
        idx = LoadFormFile(0x35, w->unk282);
        D_800E4130[0] = idx;
    } else {
        idx = func_80023FC8(D_800E4130[0]);
    }
    obj->model[0] = idx;
    func_80025EB4(idx, 1, 1);
    if (D_800E4130[1] < 0) {
        idx = func_800174F4(w->unk288 == 0 ? 0x10 : 0x20, w->unk284);
        D_800E4130[1] = idx;
    } else {
        idx = func_80023FC8(D_800E4130[1]);
    }
    obj->model[1] = idx;
    if (D_800E4130[2] < 0) {
        sprite = ReadImgPackand(0x2A, w->unk286 | 4, 8);
        D_800E4130[2] = sprite;
    } else {
        sprite = func_8001E1D0(D_800E4130[2], 8);
    }
    w->sprites[2] = sprite;
    idx = D_800ECDE0[sprite].unk_00;
    obj->model[2] = idx;
    func_800258EC(idx, 4, 4);
    func_8001E2F8(sprite, 0xC0);
    func_8001E360(sprite, 0xFF, 0xFF, 0xBE);
    func_80025930(idx, 0x70000000, 0x70000000);
    func_8001E268(sprite, 4, 0);
    func_80025830(idx, w->unk28E * 3.0f, w->unk28E * 3.0f, w->unk28E * 3.0f);
    for (j = 3, k = 13, i = 0; i < 10; i++, j++, k++) {
        if (D_800E4130[3] < 0) {
            sprite = ReadImgPackand(0x21, w->unk286, 8);
            D_800E4130[3] = sprite;
        } else {
            sprite = func_8001E1D0(D_800E4130[3], 8);
        }
        w->sprites[j] = sprite;
        idx = D_800ECDE0[sprite].unk_00;
        obj->model[j] = idx;
        func_80025930(idx, 0x70000000, 0x70000000);
        func_80025830(idx, 2.0f, 2.0f, 2.0f);
        func_800258EC(idx, 4, 4);
        sprite = func_8001E1D0(D_800E4130[3], 8);
        w->sprites[k] = sprite;
        idx = D_800ECDE0[sprite].unk_00;
        obj->model[k] = idx;
        func_80025930(idx, 0x70000000, 0x70000000);
        func_80025830(idx, 2.0f, 2.0f, 2.0f);
        func_800258EC(idx, 4, 4);
        func_8001E2F8(sprite, i * 15 + 0x60);
    }
    obj->func_ptr = func_8006BFF0;
}
#else
INCLUDE_ASM("asm/nonmatchings/6C470", func_8006BC38);
#endif

void func_8006BFF0(omObjData* obj) {
    Unk6C470Work* w = obj->unk_50;

    if (w->func4 != NULL) {
        w->func4();
    }
    if (w->func8 != NULL) {
        w->func8(obj);
    }
    if (w->funcC != NULL) {
        w->funcC(obj);
    }
}

// register choice and scheduling: f2/f6 for the scale step, obj->model load order (masked 6)
#ifdef NON_MATCHING
s32 func_8006C058(omObjData* obj) {
    Unk6C470Work* w = obj->unk_50;
    Unk6C470Part* p;
    s32 count;
    f32 grow;
    f32 shrink;
    f32 maxScale;
    f32 ang;
    f32 c;
    f32 s;
    f32 x;
    f32 y;
    f32 z;
    f32 sc;
    f32 t;
    s32 i;
    s16 mdl;

    count = 0;
    grow = 4.0f / w->unk28A;
    shrink = -1.6f / w->unk28A;
    maxScale = 2.0f * w->unk28E;
    ang = CRot.y + 90.0f;
    p = w->parts;
    if (ang > 360.0f) {
        ang -= 360.0f;
    }
    c = func_800AEAC0(ang);
    s = func_800AEFD0(ang);
    for (i = 3; i < 23; p++, i++) {
        if (i == 13) {
            p = w->parts2;
        }
        if (p->state == 0) {
            continue;
        }
        mdl = obj->model[i];
        count++;
        switch (p->state) {
            case 1:
                if (p->timer != 0) {
                    p->timer--;
                    break;
                }
                p->state = 2;
                p->timer = w->unk28A;
                func_80025830(mdl, p->scale, p->scale, p->scale);
                y = func_800AEAC0(p->angle) * p->radius;
                x = y * c;
                z = y * s;
                y = func_800AEFD0(p->angle) * p->radius;
                x += p->x;
                y += p->y;
                z += p->z;
                func_80025798(mdl, x, y, z);
                func_800258EC(mdl, 4, 0);
                if (i == 3) {
                    func_800258EC(obj->model[2], 4, 0);
                    func_80025798(obj->model[2], x + c * 10.0f, y - 10.0f, z + s * 10.0f);
                    func_8001E268(w->sprites[2], 4, 4);
                }
                break;
            case 2:
                if (p->timer != 0 && p->scale < maxScale) {
                    sc = grow + p->scale;
                    goto update;
                }
                p->state = 3;
                break;
            case 3:
                if (p->timer != 0) {
                    sc = shrink + p->scale;
            update:
                p->scale = sc;
                func_80025830(mdl, sc, sc, sc);
                x = w->unk10 - p->x;
                y = w->unk14 - p->y;
                z = w->unk18 - p->z;
                t = p->timer;
                x /= t;
                y /= t;
                z /= t;
                p->x = x + p->x;
                p->y = y + p->y;
                p->z = z + p->z;
                y = func_800AEAC0(p->angle) * p->radius;
                x = y * c;
                z = y * s;
                y = func_800AEFD0(p->angle) * p->radius;
                x += p->x;
                y += p->y;
                z += p->z;
                func_80025798(mdl, x, y, z);
                if (i == 3) {
                    func_80025798(obj->model[2], x + c * 10.0f, y - 10.0f, z + s * 10.0f);
                    func_8001E2A8(w->sprites[2], p->timer % 8);
                }
                p->radius -= p->radius / p->timer;
                p->angle += 450.0f / w->unk28A;
                if (p->angle > 360.0f) {
                    p->angle -= 360.0f;
                } else if (p->angle < 0.0f) {
                    p->angle += 360.0f;
                }
                p->timer--;
                } else {
                    p->state = 0;
                    func_800258EC(mdl, 4, 4);
                    if (i < 13) {
                        PlaySound(0xFC);
                    }
                }
                break;
        }
    }
    return count;
}
#else
INCLUDE_ASM("asm/nonmatchings/6C470", func_8006C058);
#endif
void func_8006C5A8(omObjData* obj) {
    Unk6C470Work* w = obj->unk_50;
    Unk6C470Part* p;
    s16 mdl;
    s32 t;
    s32 i;
    f32 cur;

    if (w->unk20 > 0) {
        mdl = obj->model[0];
        switch (w->unk20) {
            case 1:
                func_80025EB4(mdl, 1, 0);
                w->unk20 = 2;
                PlaySound(0x196);
                break;
            case 2:
                cur = func_80025D18(mdl);
                if (func_80025D40(mdl) <= cur) {
                    w->unk20 = 3;
                    p = w->parts;
                    t = 0;
                    for (i = 0; i < 10; i++, p++) {
                        p->timer = t;
                        t += 2;
                        p->radius = w->unk28C;
                        p->angle = 180.0f;
                        p->scale = w->unk28E;
                        p->state = 1;
                        p->x = obj->trans.x;
                        p->y = obj->trans.y + p->radius;
                        p->z = obj->trans.z;
                    }
                    p = w->parts2;
                    t--;
                    for (i = 0; i < 10; i++, p++) {
                        p->timer = t;
                        t++;
                        p->radius = w->unk28C;
                        p->angle = 180.0f;
                        p->scale = w->unk28E;
                        p->state = 1;
                        p->x = obj->trans.x;
                        p->y = obj->trans.y + p->radius;
                        p->z = obj->trans.z;
                    }
                }
                break;
            case 3:
                if (func_8006C058(obj) == 0) {
                    w->unk20 = 0;
                }
                break;
        }
    }
}

void func_8006C7A4(omObjData* obj) {
    Unk6C470Work* w = obj->unk_50;
    s16 mdl = obj->model[1];
    f32 d;
    f32 s;

    func_80025798(mdl, obj->trans.x, w->unk1C, obj->trans.z);
    d = obj->trans.y - w->unk1C - obj->scale.y * 50.0f;
    if (!w->unk288) {
        s = obj->scale.y * 0.58f;
    } else {
        s = obj->scale.y * 1.2f;
    }
    if (d < 0.0f) {
        d = s;
    } else {
        d = s - (d * 0.002f);
        if (d < 0.00001f) {
            d = 0.00001f;
        }
    }
    func_80025830(mdl, d, d, d);
    func_800257E4(mdl, obj->rot.x, obj->rot.y, obj->rot.z);
}