#include "common.h"

/* Player/actor motion helpers working on the work block at omObjData::unk_50. */

typedef struct MotionEntry {
    /* 0x00 */ u16 flags;
    /* 0x02 */ u16 speed;
} MotionEntry;

typedef struct MotionReq {
    /* 0x00 */ u16 flags; /* 0xC8 */
    /* 0x02 */ u16 motion; /* 0xCA */
    /* 0x04 */ char unk_04[4];
    /* 0x08 */ s32 unk_08; /* 0xD0 */
    /* 0x0C */ f32 speed; /* 0xD4 */
} MotionReq;

typedef struct ActorWork {
    /* 0x00 */ char unk_00[0x50];
    /* 0x50 */ u16 flags;
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ char unk_53[9];
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ char unk_60[0x3C];
    /* 0x9C */ u16 unk_9C;
    /* 0x9E */ char unk_9E[2];
    /* 0xA0 */ f32 unk_A0;
    /* 0xA4 */ char unk_A4[4];
    /* 0xA8 */ f32 unk_A8;
    /* 0xAC */ char unk_AC[2];
    /* 0xAE */ u16 unk_AE;
    /* 0xB0 */ u8 unk_B0;
    /* 0xB1 */ char unk_B1[7];
    /* 0xB8 */ void* unk_B8; /* MgWork's held item: a pointer, so the host layout agrees */
    /* 0xBC */ char unk_BC[4];
    /* 0xC0 */ u16 cur;
    /* 0xC2 */ u16 count;
    /* 0xC4 */ char unk_C4[2];
    /* 0xC6 */ u16 pending;
    /* 0xC8 */ MotionReq req;
    /* 0xD8 */ MotionEntry* table;
} ActorWork;

extern u16 D_800F370C;

f32 func_80025D18(s16);
f32 func_80025D40(s16);
f32 func_80025E70(s16);
void func_80025FF0(s16, f32);
void func_80028498(s16, s16, s16);
void func_80028668(unk_ovl_2D_struct*, u16);
s16 func_80028784(u8*, s16);
f32 func_800288D8(s16);
s16 func_8001755C(s32);

u16 func_80017A50(omObjData* obj);
void func_80017B4C(u8 mdl);
void func_80017BB0(omObjData* obj);
void func_80017D1C(omObjData* obj);
void func_8001846C(MotionReq* req, u16 flags, u16 motion, u16 speed);
s32 func_800184A8(ActorWork* w, u16 motion);
s32 func_800185A4(omObjData* obj, u16 motion);

u16 func_80017A50(omObjData* obj) {
    return ((ActorWork*)obj->unk_50)->req.motion & 0x3FFF;
}

s32 func_80017A60(omObjData* obj) {
    ActorWork* w = obj->unk_50;
    s32 flags;

    if (w->cur == 0xFFFF) {
        return 1;
    } else {
        switch (func_80017A50(obj)) {
            case 0:
            case 11:
            case 24:
                flags = 2;
                break;
            case 16:
                flags = 0x20000;
                break;
            case 1:
            case 2:
            case 3:
            case 4:
                flags = 4;
                break;
            case 25:
            case 27:
                flags = 8;
                break;
            case 26:
                flags = 0x10;
                break;
            case 6:
                flags = 0x20;
                break;
            case 20:
                flags = 0x80;
                break;
            case 5:
                flags = 0x40;
                break;
            case 7:
                flags = 0x100;
                break;
            case 8:
                flags = 0x200;
                break;
            case 21:
                flags = 0x10000;
                break;
            case 18:
            case 19:
            case 28:
            case 30:
            case 31:
            case 33:
            case 34:
                flags = 0x8000;
                break;
            case 9:
            case 12:
            case 29:
                flags = 0x400;
                break;
            case 10:
            case 23:
                flags = 0x800;
                break;
            case 13:
            case 14:
            case 15:
                flags = 0x1000;
                break;
            case 17:
                flags = 0x2000;
                break;
            case 32:
                flags = 0x4000;
                break;
            default:
                flags = 0;
                break;
        }
        w->unk_5C = flags;
    }
    return flags;
}

void func_80017B4C(u8 mdl) {
    f32 cur;

    if (mdl != 0) {
        cur = func_80025D18(mdl);
        if (func_80025D40(mdl) <= cur) {
            func_800258EC(mdl, 4, 4);
        }
    }
}

void func_80017BB0(omObjData* obj) {
    s32 i;

    i = 3;
loop:
    if (i < obj->mdlcnt) {
        func_80017B4C(obj->model[i++]);
        if (i < 9) {
            goto loop;
        }
    }
}

void func_80017C0C(omObjData* obj, u8 idx, f32 x, f32 y, f32 z, f32 a, f32 b) {
    u8 mdl = obj->model[idx];
    f32 cur;

    if (obj->mdlcnt > idx) {
        if (mdl != 0) {
            cur = func_80025D18(mdl);
            if (func_80025D40(mdl) <= cur) {
                if (D_800F2B7C[mdl].unk_6C->unk_B8 != NULL) {
                    D_800F2B7C[mdl].unk_6C->unk_B8->unk_08 = 0;
                }
                func_80025CA8(mdl, 0.0f);
            }
            func_800258EC(mdl, 4, 0);
            func_80025798(mdl, x, y, z);
            func_800257E4(mdl, a, b, 0.0f);
        }
    }
}

// flip held in a copy register and the motion pointer preloaded only in retail (masked 11)
#ifdef NON_MATCHING
void func_80017D1C(omObjData* obj) {
    ActorWork* w = obj->unk_50;
    s16* motion = obj->motion;
    s32 flip = (w->req.flags & 1) * 2;

    if (w->table[22].flags & 4) {
        func_80028498(obj->model[0], motion[22] & 0x3FFF, flip);
    } else {
        func_80028498(obj->model[0], func_80025E48(obj->motion[22] & 0x3FFF), flip);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/18650", func_80017D1C);
#endif

void func_80017DB0(omObjData* obj) {
    u16 mdl = obj->model[0];
    ActorWork* w = obj->unk_50;
    MotionReq* req;
    s16 mot;
    s32 flip;
    f32 t;
    u16 spd;
    MotionEntry* e;

    if (w->pending != 0) {
        flip = 0;
        if (w->count != 0) {
            req = &w->req;
            if (req->flags & 4) {
                spd = (w->unk_A8 = func_800288D8(mot = obj->motion[req->motion] & 0x3FFF)) / 5.0f;
            } else {
                mot = func_80025E48(obj->motion[req->motion] & 0x3FFF);
                spd = (w->unk_A8 = func_80025D40(obj->motion[req->motion] & 0x3FFF)) / 5.0f;
            }
            if (req->flags & 1) {
                flip = 2;
            }
            func_80025C20(mdl, mot, 0, spd, flip);
            func_80025FF0(mdl, req->speed);
            if (w->flags & 0x100) {
                func_80017D1C(obj);
            }
        }
        w->pending = 0;
    } else {
        e = &w->table[func_80017A50(obj)];
        if (!(e->flags & 1)) {
            t = func_80025E70(mdl);
            if (t == -1.0f) {
                t = func_80025D18(mdl);
            }
            if (w->unk_A8 <= t) {
                w->cur++;
                if (w->count <= w->cur) {
                    w->count = 0;
                    w->cur = 0xFFFF;
                }
            }
        }
    }
}

// decomp-permuter
void func_8001802C(omObjData *obj)
{
  ActorWork *w = obj->unk_50;
  u16 lim1;
  u16 lim2;
  f32 sy;
  f32 sxz;
  f32 t;
  s32 off;
  u16 prev;
  if (w->flags & 7)
  {
    w->unk_9C += 2;
    lim1 = 60;
    if (w->flags & 2)
    {
      lim2 = 106;
      sy = 0.6f;
      sxz = w->unk_A0 * 1.4f;
    }
    else
    {
      lim1 = 120;
      lim2 = 166;
      sy = 0.1f;
      sxz = w->unk_A0 * 1.6f;
      if (w->unk_9C >= 120)
      {
        if (w->flags & 1)
        {
          w->flags = (w->flags & (~1)) | 4;
        }
      }
    }
    if (w->unk_9C < lim2)
    {
      if (w->unk_9C <= lim1)
      {
        obj->scale.x = (obj->scale.z = sxz);
        obj->scale.y = sy;
      }
      else
        if (w->unk_9C <= (lim1 + 10))
      {
        t = w->unk_9C - lim1;
        obj->scale.y = (t * 0.05f) + 0.2;
        obj->scale.z = (obj->scale.x = 1.8 - (t * 0.08f));
      }
      else
        if (w->unk_9C <= (lim1 + 20))
      {
        t = w->unk_9C - (lim1 + 10);
        obj->scale.y = 0.9 - (t * 0.05f);
        obj->scale.z = (obj->scale.x = (t * 0.05f) + 1.0);
      }
      else
        if (w->unk_9C <= (lim1 + 30))
      {
        t = w->unk_9C - (lim1 + 20);
        obj->scale.y = (t * 0.05f) + 0.7;
        obj->scale.z = (obj->scale.x = 1.4 - (t * 0.04f));
      }
      else
        if (w->unk_9C <= (lim1 + 38))
      {
        t = w->unk_9C - (lim1 + 30);
        obj->scale.y = 1.3 - (t * 0.1f);
        obj->scale.z = (obj->scale.x = (t * 0.02f) + 1.0);
      }
      else
      {
        t = w->unk_9C - (lim1 + 38);
        obj->scale.y = (t * 0.1f) + 0.3;
        obj->scale.z = (obj->scale.x = 1.1 - (t * 0.01f));
      }
    }
    else
    {
      obj->scale.x = (obj->scale.y = (obj->scale.z = 1.0f));
      w->flags &= ~7;
      w->unk_9C = 0;
    }
  }
  if (w->unk_AE != 0)
  {
    prev = w->unk_AE;
    w->unk_AE--;
    if (w->unk_AE == 0)
    {
      if (D_800F370C != 0)
      {
        w->unk_AE = prev;
      }
      else
      {
        w->unk_B0 = 1;
      }
    }
    prev = ((w->unk_B0 & 1) == 0) * 4;
    func_800258EC(obj->model[0], 4, off = prev);
    if (off != 0)
    {
      func_80028668(&D_800F2B7C[obj->model[0]], 2);
    }
    w->unk_B0 = (w->unk_B0 + 1) & 3;
  }
  func_80017BB0(obj);
}

void func_80018450(omObjData* obj, u8 flags) {
    ActorWork* w = obj->unk_50;

    w->flags |= flags;
    w->unk_9C = 0;
}

void func_8001846C(MotionReq* req, u16 flags, u16 motion, u16 speed) {
    req->flags = flags;
    req->motion = motion;
    req->unk_08 = 0;
    req->speed = speed;
}

s32 func_80018490(omObjData* obj, u16 motion) {
    return ((ActorWork*)obj->unk_50)->req.motion == motion;
}

s32 func_800184A8(ActorWork* w, u16 motion) {
    return w->req.motion == motion;
}

// decomp-permuter
s32 func_800184BC(omObjData *obj, u16 motion)
{
  ActorWork *w = obj->unk_50;
  MotionEntry *e;
  s32 flags;
  s32 speed;
  if (w->unk_52 == 0)
  {
    if (obj || obj->unk_50)
    {
      e = &w->table[func_80017A50(obj)];
    }
    else
    {
      e = &w->table[func_80017A50(obj)];
    }
    if ((w->cur == 0xFFFF) || ((!(e->flags & 2)) && (!func_800184A8(w, motion))))
    {
      e = &w->table[motion];
      if (((u16) obj->motion[motion]) != 0xFFFF)
      {
        flags = e->flags;
        speed = e->speed;
        w->cur = 0;
        w->count = 1;
        func_8001846C(&w->req, flags, motion, speed);
        w->pending = 1;
        return 1;
      }
    }
  }
  return 0;
}

s32 func_800185A4(omObjData* obj, u16 motion) {
    ActorWork* w = obj->unk_50;
    MotionEntry* e;
    s32 flags;
    s32 speed;

    if (w->unk_52 != 0 || (e = &w->table[motion], (u16)obj->motion[motion] == 0xFFFF)) {
        return 0;
    }
    flags = e->flags;
    speed = e->speed;
    w->cur = 0;
    w->count = 1;
    func_8001846C(&w->req, flags, motion, speed);
    w->pending = 1;
    return 1;
}

s32 func_8001863C(omObjData* obj, u16 motion, u16 next) {
    ActorWork* w = obj->unk_50;

    if (func_800185A4(obj, motion) == 1) {
        func_800186E4(obj, 22, next);
        w->flags |= 0x100;
        return 1;
    }
    return 0;
}

void func_800186A8(omObjData* obj, s32 src, s32 dst) {
    obj->motion[dst] = obj->motion[src];
}

void func_800186C8(omObjData* obj, s32 idx, s16 flags, s16 speed) {
    MotionEntry* e = &((ActorWork*)obj->unk_50)->table[idx];

    e->flags = flags;
    e->speed = speed;
}

void func_800186E4(omObjData* obj, s32 a, s32 b) {
    ActorWork* w = obj->unk_50;
    s32 tmp;
    MotionEntry* ea;
    MotionEntry* eb;
    u16 flags;
    u16 speed;

    tmp = obj->motion[a];
    obj->motion[a] = obj->motion[b];
    obj->motion[b] = tmp;
    ea = &w->table[a];
    eb = &w->table[b];
    speed = ea->speed;
    flags = ea->flags;
    ea->speed = eb->speed;
    ea->flags = eb->flags;
    eb->speed = speed;
    eb->flags = flags;
}

// register allocation of the parameters (masked 0)
#ifdef NON_MATCHING
void func_8001874C(omObjData* obj, s32 idx, s32 file, s32 flags, u16 speed) {
    s16 mot = func_8001755C(file);
    ActorWork* w;
    MotionEntry* e;

    if (mot >= 0) {
        w = obj->unk_50;
        obj->motion[(u16)idx] = mot;
        e = &w->table[(u16)idx];
        e->flags = flags;
        e->speed = speed;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/18650", func_8001874C);
#endif

// register allocation of the parameters (masked 0)
#ifdef NON_MATCHING
void func_800187D0(omObjData* obj, s32 idx, s32 file, s32 flags, u16 speed) {
    s16 mot = func_80028784(DataRead(file), 0x18);
    ActorWork* w;
    MotionEntry* e;

    if (mot >= 0) {
        w = obj->unk_50;
        obj->motion[(u16)idx] = mot;
        e = &w->table[(u16)idx];
        e->flags = flags | 4;
        e->speed = speed;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/18650", func_800187D0);
#endif
