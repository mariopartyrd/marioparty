#include "BombsAway.h"

/* Model-node helpers, the camera projection and angle utilities. */

s16 func_800FBCC0_BombsAway(unk2C0C0StructC0* m, const char* name) {
    unk2C0C0Struct30* p = m->unk_80;
    s32 i;

    for (i = 0; i < m->unk_6A; i++, p++) {
        if (func_8009B850(p->unk_18, name) == 0) {
            return i;
        }
    }
    return -1;
}
unk2C0C0Struct50* func_800FBD40_BombsAway(unk2C0C0StructC0* m, s16 id, s32 idx) {
    unk2C0C0Struct50* n = &m->unk_A0[idx & 0x7FFF];
    unk2C0C0Struct50* r;
    s32 i;
    s16 c;

    if (n == (unk2C0C0Struct50*)-1) {
        return NULL;
    }
    for (i = 0; i < n->unk_00; i++) {
        c = n->unk_04[i];
        if (c & 0x8000) {
            if (c != -1) {
                r = func_800FBD40_BombsAway(m, id, c & 0x7FFF);
                if (r != NULL) {
                    return r;
                }
            }
        } else if (c == id) {
            return n;
        }
    }
    return NULL;
}
unk2C0C0Struct50* func_800FBE34_BombsAway(s16 model, const char* name) {
    unk2C0C0StructC0* m = D_800F2B7C[model].unk_6C;
    s16 id = func_800FBCC0_BombsAway(m, name);
    unk2C0C0Struct50* n;

    if (id < 0) {
        return NULL;
    }
    n = func_800FBD40_BombsAway(m, id, 0);
    if (n != NULL) {
        return n;
    }
    return NULL;
}
Vec3f* func_800FBEB0_BombsAway(s16 model, const char* name) {
    unk2C0C0Struct50* n = func_800FBE34_BombsAway(model, name);

    if (n == NULL) {
        return NULL;
    }
    return &n->unk_44;
}
Vec3f* func_800FBEDC_BombsAway(s16 model, const char* name) {
    unk2C0C0Struct50* n = func_800FBE34_BombsAway(model, name);

    if (n == NULL) {
        return NULL;
    }
    return &n->unk_50;
}
void func_800FBF08_BombsAway(s16 model, s16 src, s16 motion, f32 t) {
    unk2C0C0StructC0* m = D_800F2B7C[model].unk_6C;
    unk2C0C0StructE0* save = m->unk_04;

    m->unk_04 = D_800F2B7C[src].unk_6C->unk_04;
    func_80026174(model, motion, t);
    D_800F2B7C[model].unk_6C->unk_04 = save;
}
void func_800FBF9C_BombsAway(Matrix4f m, f32 x, f32 y, f32 z, f32* o) {
    *o++ = x * m[0][0] + y * m[1][0] + z * m[2][0] + m[3][0];
    *o++ = x * m[0][1] + y * m[1][1] + z * m[2][1] + m[3][1];
    *o = x * m[0][2] + y * m[1][2] + z * m[2][2] + m[3][2];
}
void func_800FC038_BombsAway(Vec* v) {
    f32 len = v->x * v->x + v->y * v->y + v->z * v->z;

    len = sqrtf(len);
    if (len != 0.0f) {
        len = 1.0 / len;
        v->x = len * v->x;
        v->y = len * v->y;
        v->z = len * v->z;
    }
}
f32 func_800FC0EC_BombsAway(f32 x, f32 z) {
    f32 a = func_800B0CD8(z, x);

    if (a < 0.0) {
        a += 360.0;
    } else if (a >= 360.0) {
        a -= 360.0;
    }
    return a;
}
// decomp-permuter
void func_800FC16C_BombsAway(Vec *v, Vec *out)
{
  f32 *o = (f32 *) out;
  f32 *new_var;
  f32 len = sqrtf((v->x * v->x) + (v->z * v->z));
 do { *o = func_800FC0EC_BombsAway(len, -v->y); len = v->z; new_var = ++o; *new_var = func_800FC0EC_BombsAway(len, v->x); o[1] = 0; } while (0);
}
void func_800FC1F4_BombsAway(Matrix4f m, Vec* r) {
    f32 s;
    f32 c;
    f64 d;

    r->x = func_800FC0EC_BombsAway(m[2][2], m[1][2]);
    r->z = func_800FC0EC_BombsAway(m[0][0], m[0][1]);
    s = -m[0][2];
    d = 1.0 - s * s;
    if (d < 0.0) {
        d = -d;
    }
    c = sqrtf(d);
    if (r->x > 90.0 && r->x < 270.0 && r->z > 90.0 && r->z < 270.0) {
        r->x += 180.0;
        if (r->x >= 360.0) {
            r->x -= 360.0;
        }
        r->z += 180.0;
        if (r->z >= 360.0) {
            r->z -= 360.0;
        }
        c = -c;
    }
    r->y = func_800FC0EC_BombsAway(c, s);
}
void func_800FC39C_BombsAway(s16 camera) {
    unk_Struct00* cam = &D_800C3110[camera];

    HuGuLookAtF(D_80100720_BombsAway, cam->pos.x, cam->pos.y, cam->pos.z, cam->unkC.x, cam->unkC.y, cam->unkC.z,
                cam->unk18.x, cam->unk18.y, cam->unk18.z);
    D_80100760_BombsAway = func_800AEAC0(cam->unk_40 * 0.5) / func_800AEFD0(cam->unk_40 * 0.5);
}
void func_800FC478_BombsAway(Vec* pos, Vec* out) {
    f32 v[3];
    f32 d;

    func_800FBF9C_BombsAway(D_80100720_BombsAway, pos->x, pos->y, pos->z, v);
    d = v[2] * D_80100760_BombsAway;
    if (d < 0.0f) {
        d = -d;
    }
    out->x = v[0] * 0.75 / d;
    out->y = -v[1] / d;
    out->z = 400.0 / d;
}
void func_800FC530_BombsAway(s16 sound, Vec* pos) {
    Vec o;
    f32 pan;

    func_800FC478_BombsAway(pos, &o);
    pan = o.x * 32.0f;
    if (pan < -32.0f) {
        pan = -32.0f;
    } else if (pan > 32.0f) {
        pan = 32.0f;
    }
    func_800607C4(sound, (s32)pan + 64);
}
