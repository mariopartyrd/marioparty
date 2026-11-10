#include "common.h"
#include "PR/gu.h"
Vp D_800C5B40 = { { { 640, 480, 511, 0 }, { 640, 480, 511, 0 } } };

#define TREE_NEXT(obj, cur, sp, stack, grp)            \
    if ((obj)->unk60 >= 0) {                           \
        (stack)[(sp)++] = (cur); (cur) = (obj)->unk60; (sp) %= 256; \
    } else {                                           \
        while ((obj)->unk5E < 0 && (sp) != 0) {        \
            (obj) = (grp)->obj[(stack)[--(sp)]]; (sp) %= 256; \
        }                                              \
        (cur) = (obj)->unk5E;                          \
    }


#define READ32(p) (((p)[0] << 24) + ((p)[1] << 16) + ((p)[2] << 8) + (p)[3])
#define READ16(p) (((p)[0] << 8) + (p)[1])




#include "sprite65770.h"

typedef struct unk65770ObjInit {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ u16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ u16 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ u8 unk20;
    /* 0x21 */ u8 unk21;
    /* 0x22 */ u8 unk22;
    /* 0x24 */ s16 unk24;
    /* 0x26 */ s16 unk26;
} unk65770ObjInit;

typedef struct unk65770Bucket {
    /* 0x00 */ unk65770Obj* head;
    /* 0x04 */ unk65770Obj* tail;
} unk65770Bucket;

extern unk65770Grp* D_800ECB04;
extern unk65770Grp* D_800ED0C0;
extern u16 D_800F502E;
extern s16 D_800ECB20;
extern void* D_800F54B4;
extern void* D_800EE978[3];
extern s32 D_800F37CC;
extern Mtx D_800E40E0;
extern s16 D_800F2BD8;
extern s16 D_800F329E;

extern Gfx* D_800E4120;
void func_80068410(Gfx** gfx, unk65770Obj* obj);
void func_80023888(void*);
extern f32 D_800E4124;
extern unk65770Anim* D_800EC700[256];
extern u16 D_800ED3EC;
extern s8 D_800F384E;
void func_80067E38(unk65770Obj* obj);
void func_80068124(unk65770Obj* obj);
s16 func_8002451C(s32, void*, s32);
f64 func_8009B618(f64, f64);
void func_8003B6E4(void*, u32);
void func_8006677C(Gfx** gfx, Mtx* mtx, unk_Struct00* cam);
void func_80066B3C(Gfx** gfx, Mtx* mtx, unk_Struct00* cam);
unk65770Obj* func_80065700(void);
void func_80065BF8(void);
void func_800676BC(void);
unk65770Grp* func_80064C94(s16 num, u16 attr);
void func_80065520(unk65770Grp* grp, u16 num);


void func_80064B70(void) {
    s16 i;

    D_800F502E = 0;
    for (i = 0; i < 256; i++) {
        D_800EE330[i] = NULL;
    }
    D_800ED0C0 = NULL;
    D_800ECB04 = NULL;
    D_800ECB20 = 0;
    D_800EE978[0] = D_800EE978[1] = D_800EE978[2] = D_800F54B4 = NULL;
    D_800F37CC = 0;
    guOrtho(&D_800E40E0, -160.0f, 160.0f, -120.0f, 120.0f, 0.0f, 2000.0f, 1.0f);
    D_800F2BD8 = func_8002451C(0, func_8006677C, 0);
    func_80025F10(D_800F2BD8, 1);
    D_800F329E = func_8002451C(0, func_80066B3C, 6);
    func_800676BC();
}
unk65770Grp* func_80064C94(s16 num, u16 attr) {
    unk65770Grp* grp = func_80023668(num * sizeof(unk65770Obj*) + sizeof(unk65770Grp) - sizeof(unk65770Obj*));

    if (grp == NULL) {
        return NULL;
    }
    grp->unk8 = attr;
    grp->count = num;
    if (D_800ECB04 == NULL) {
        D_800ECB04 = grp;
    }
    grp->prev = D_800ED0C0;
    if (D_800ED0C0 != NULL) {
        D_800ED0C0->next = grp;
    }
    grp->next = NULL;
    D_800ED0C0 = grp;
    D_800F502E++;
    return grp;
}
void func_80064D38(s16 idx) {
    unk65770Grp* grp = D_800EE330[idx];
    unk65770Grp* prev = grp->prev;
    unk65770Grp* next = grp->next;
    unk65770Obj** p;
    s16 i;

    if (grp->obj[0] != NULL) {
        p = grp->obj;
        for (i = 0; i < grp->count; i++) {
            func_80023728(*p++);
        }
    }
    if (prev != NULL) {
        prev->next = next;
    }
    if (next != NULL) {
        next->prev = prev;
    }
    if (D_800ECB04 == grp) {
        D_800ECB04 = next;
        if (next != NULL) {
            next->prev = NULL;
        }
    }
    if (D_800ED0C0 == grp) {
        D_800ED0C0 = prev;
        if (prev != NULL) {
            prev->next = NULL;
        }
    }
    func_80023728(grp);
    D_800EE330[idx] = NULL;
    D_800F502E--;
}
void func_80064E64(void) {
    s16 i;

    D_800F502E = 0;
    for (i = 0; i < 256; i++) {
        if (D_800EE330[i] != NULL) {
            func_80064D38(i);
        }
    }
    D_800ED0C0 = NULL;
    D_800ECB04 = NULL;
    D_800ECB20 = 0;
}
s16 func_80064EF4(s32 num, s32 attr) {
    unk65770Grp* grp;
    unk65770Obj** p;
    s16 i;
    s16 idx;

    for (i = 0; i < 256; i++) {
        if (D_800EE330[i] == NULL) {
            break;
        }
    }
    if (i == 256) {
        return -1;
    }
    idx = i;
    grp = func_80064C94(num, attr);
    if (grp == NULL) {
        return -1;
    }
    D_800EE330[idx] = grp;
    grp->count = 0;
    p = grp->obj;
    for (i = 0; i < (u16)num; i++) {
        if ((*p++ = func_80023668(sizeof(**p))) == NULL) {
            func_80064D38(idx);
            return -1;
        }
        grp->count++;
    }
    func_80065520(grp, num);
    return idx;
}
s32 func_8006503C(s16 idx, s16 start, u16 num) {
    unk65770Grp* grp = D_800EE330[idx];
    unk65770Obj** p = &grp->obj[start];
    unk65770Obj* obj;
    s16 i;

    for (i = 0; i < num; i++) {
        func_80023728(*p++);
    }
    grp->count -= num;
    if (grp->count == 0) {
        grp->obj[0] = NULL;
        func_80064D38(idx);
        return 0;
    }
    func_8003B6E4(grp, grp->count * 4 + 0xC);
    p = &grp->obj[start];
    for (i = 0; i < grp->count - start; i++) {
        *p = p[num];
        p++;
    }
    for (i = 0; i < grp->count; i++) {
        obj = grp->obj[i];
        obj->unk0 = i;
        obj->unk2 = grp->count;
    }
    return 0;
}
s32 func_800651E0(s16 idx, s16 pos, u16 num) {
    unk65770Grp* old = D_800EE330[idx];
    unk65770Grp* grp;
    unk65770Obj** p;
    unk65770Obj* obj;
    s16 i;
    s16 newIdx;

    for (i = 0; i < 256; i++) {
        if (D_800EE330[i] == NULL) {
            break;
        }
    }
    if (i == 256) {
        return -1;
    }
    newIdx = i;
    grp = func_80064C94(num + old->count, old->unk8);
    if (grp == NULL) {
        return -1;
    }
    D_800EE330[newIdx] = grp;
    grp->count = 0;
    p = grp->obj;
    for (i = 0; i < num; i++) {
        if ((*p++ = func_80023668(sizeof(**p))) == NULL) {
            func_80064D38(newIdx);
            return -1;
        }
        grp->count++;
    }
    func_80065520(grp, num);
    grp->obj[0]->unk2A = 0;
    if (pos >= 0) {
        p = grp->obj + num - 1;
        for (i = 0; i < num; i++) {
            p[pos + 1] = *p;
            p--;
        }
        p = grp->obj;
        for (i = 0; i < pos + 1; i++) {
            *p++ = old->obj[i];
        }
    }
    p = &grp->obj[pos] + num + 1;
    for (i = 0; i < old->count - (pos + 1); i++) {
        *p++ = (old->obj + pos)[i + 1];
    }
    grp->count = num + old->count;
    for (i = 0; i < grp->count; i++) {
        obj = grp->obj[i];
        obj->unk0 = i;
        obj->unk2 = grp->count;
    }
    old->obj[0] = NULL;
    func_80064D38(idx);
    D_800EE330[idx] = grp;
    D_800EE330[newIdx] = NULL;
    return 0;
}
void func_80065520(unk65770Grp* grp, u16 num) {
    unk65770Obj* obj;
    s16 i;

    for (i = 0; i < num; i++) {
        obj = grp->obj[i];
        obj->unk4 = 0;
        obj->unk6 = 0;
        obj->unk8 = 0;
        obj->unkA = 0;
        obj->unkC = 0.0f;
        obj->unk14 = obj->unk18 = 1.0f;
        obj->unk10 = 0x8000;
        obj->unk1C = 0;
        obj->unk20 = 0;
        obj->unk24 = obj->unk25 = obj->unk26 = 0;
        obj->unk28 = 0x100;
        if (i != 0) {
            obj->unk2A = 0;
        } else {
            obj->unk2A = -1;
        }
        obj->unk2C = obj->unk30 = 1.0f;
        obj->unk34 = obj->unk36 = 0;
        obj->unk38 = obj->unk3A = obj->unk3C = obj->unk3E = 0;
        obj->unk5E = -1;
        obj->unk60 = -1;
        obj->unk40 = 0;
        obj->unk42 = 0;
        obj->unk44 = 0.0f;
        obj->unk48 = 0;
        obj->unk4C = NULL;
        obj->unk58 = 0;
        obj->unkC = 1.0f;
        obj->unk52 = 0;
        obj->unk54 = obj->unk55 = 0;
        obj->unk56 = 0;
        obj->unk50 = 0;
        obj->unk5C = func_8009B618(0.0, 0.0);
        obj->unk0 = i;
        obj->unk2 = num;
        obj->unk68 = NULL;
        obj->unk64 = NULL;
    }
}
void func_800656E4(unk65770Obj* obj, unk65770Obj* a, unk65770Obj* b) {
    if (a != NULL) {
        a->unk68 = obj;
    }
    if (b != NULL) {
        b->unk64 = obj;
    }
    obj->unk64 = a;
    obj->unk68 = b;
}
// decomp-permuter
unk65770Obj *func_80065700(void)
{
  unk65770Bucket bucket[256];
  unk65770Grp *grp;
  unk65770Obj *obj;
  unk65770Obj *s2;
  s16 min = -1;
  s16 max = 0;
  s16 pri;
  s16 i;
  s16 j;
  s2 = 0;
  D_800ECB20 = 0;
  grp = D_800ECB04;
  for (pri = 0; pri < 256; pri++)
  {
    bucket[pri].head = (bucket[pri].tail = 0);
  }

  for (; grp != 0; grp = grp->next)
  {
    for (i = 0; i < grp->count; i++)
    {
      obj = grp->obj[i];
      if (obj->unk20 & 0x8000)
      {
        continue;
      }
      pri = obj->unk10 >> 8;
 do { } while (0);
      if (min < 0)
      {
        min = (max = pri);
        bucket[max].head = (bucket[max].tail = obj);
      }
      else
      {
        if (pri <= max)
        {
          for (j = pri; j < (max + 1); j++)
          {
            s2 = bucket[j].tail;
            if ((s2 != 0) && (obj->unk10 <= s2->unk10))
            {
              if ((bucket[j].head != 0) && (bucket[j].head->unk10 >= obj->unk10))
              {
                s2 = bucket[j].head;
              }
              break;
            }
          }

          if (j == (max + 1))
          {
            s2 = bucket[max].tail;
          }
        }
        else
        {
          s2 = bucket[max].tail;
        }
        for (; s2 != 0; s2 = s2->unk64)
        {
          if (s2->unk10 < obj->unk10)
          {
            break;
          }
        }

        if (s2 != 0)
        {
          func_800656E4(obj, s2, s2->unk68);
        }
        else
        {
          func_800656E4(obj, 0, bucket[min].head);
        }
        if ((bucket[pri].head == 0) || (obj->unk10 <= bucket[pri].head->unk10))
        {
          bucket[pri].head = obj;
        }
        if ((bucket[pri].tail == 0) || (obj->unk10 > bucket[pri].tail->unk10))
        {
          bucket[pri].tail = obj;
        }
        if (pri < min)
        {
          min = pri;
        }
        if (pri > max)
        {
          max = pri;
        }
      }
      D_800ECB20++;
    }

  }

  return bucket[max].tail;
}

s16 func_80065A2C(unk65770Grp* grp) {
    unk65770Obj* obj;
    unk65770Obj* parent;
    unk65770Obj* other;
    s16 root = 0;
    s16 i;
    s16 j;

    for (j = 0; j < grp->count; j++) {
        obj = grp->obj[j];
        obj->unk5E = obj->unk60 = -1;
    }
    for (i = 0; i < grp->count; i++) {
        obj = grp->obj[i];
        if (obj->unk2A >= 0) {
            parent = grp->obj[obj->unk2A];
            if (parent->unk60 < 0) {
                parent->unk60 = i;
            } else {
                for (j = 0; j < i; j++) {
                    other = grp->obj[j];
                    if (j != i && obj->unk2A == other->unk2A && other->unk5E < 0) {
                        other->unk5E = i;
                        break;
                    }
                }
            }
        } else {
            root = i;
        }
    }
    return root;
}
void func_80065B68(f32 a[3][2], f32 b[3][2], f32 out[3][2]) {
    s16 i;

    for (i = 0; i < 3; i++) {
        out[i][0] = a[i][0] * b[0][0] + a[i][1] * b[1][0];
        out[i][1] = a[i][0] * b[0][1] + a[i][1] * b[1][1];
    }
    out[2][0] += b[2][0];
    out[2][1] += b[2][1];
}
// scheduling: tree-pop sp mask placed after the stack load (masked 10)
#ifdef NON_MATCHING
void func_80065BF8(void) {
    f32 mtx[256][3][2];
    f32 mA[3][2];
    f32 mB[3][2];
    s16 stack[256];
    unk65770Grp* grp;
    unk65770Obj* obj;
    unk65770Obj* parent;
    f32 angle;
    f32 s;
    u16 sp = 0;
    s16 cur;
    s16 i;

    for (grp = D_800ECB04; grp != NULL; grp = grp->next) {
        switch (grp->unk8) {
            case 0:
                for (cur = 0; cur < grp->count; cur++) {
                    obj = grp->obj[cur];
                    func_80067E38(obj);
                    obj->unk4 = obj->unk54 + obj->unk40;
                    obj->unk6 = obj->unk55 + obj->unk42;
                    obj->unk1C = obj->unk44;
                    func_80068124(obj);
                }
                break;
            case 1:
                cur = func_80065A2C(grp);
                for (i = 0; i < grp->count; i++) {
                    obj = grp->obj[cur];
                    func_80067E38(obj);
                    if (obj->unk2A < 0) {
                        obj->unk4 = obj->unk54 + obj->unk40;
                        obj->unk6 = obj->unk55 + obj->unk42;
                        obj->unk1C = obj->unk44;
                    } else {
                        parent = grp->obj[obj->unk2A];
                        obj->unk4 = obj->unk54 + obj->unk40;
                        obj->unk6 = obj->unk55 + obj->unk42;
                        obj->unk1C = parent->unk1C + obj->unk44;
                    }
                    func_80068124(obj);
                    TREE_NEXT(obj, cur, sp, stack, grp);
                }
                break;
            case 2:
                cur = func_80065A2C(grp);
                for (i = 0; i < grp->count; i++) {
                    obj = grp->obj[cur];
                    func_80067E38(obj);
                    if (obj->unk2A < 0) {
                        obj->unk4 = obj->unk54 + obj->unk40;
                        obj->unk6 = obj->unk55 + obj->unk42;
                    } else {
                        parent = grp->obj[obj->unk2A];
                        obj->unk4 = parent->unk4 + (obj->unk40 + obj->unk54) * obj->unk14;
                        obj->unk6 = parent->unk6 + (obj->unk42 + obj->unk55) * obj->unk18;
                    }
                    obj->unk1C = obj->unk44;
                    func_80068124(obj);
                    TREE_NEXT(obj, cur, sp, stack, grp);
                }
                break;
            case 3:
                cur = func_80065A2C(grp);
                for (i = 0; i < grp->count; i++) {
                    obj = grp->obj[cur];
                    func_80067E38(obj);
                    if (obj->unk2A < 0) {
                        obj->unk4 = obj->unk54 + obj->unk40;
                        obj->unk6 = obj->unk55 + obj->unk42;
                        obj->unk1C = obj->unk44;
                    } else {
                        parent = grp->obj[obj->unk2A];
                        obj->unk4 = parent->unk4 + (obj->unk40 + obj->unk54) * obj->unk14;
                        obj->unk6 = parent->unk6 + (obj->unk42 + obj->unk55) * obj->unk18;
                        obj->unk1C = parent->unk1C + obj->unk44;
                    }
                    func_80068124(obj);
                    TREE_NEXT(obj, cur, sp, stack, grp);
                }
                break;
            case 4:
                cur = func_80065A2C(grp);
                for (i = 0; i < grp->count; i++) {
                    obj = grp->obj[cur];
                    func_80067E38(obj);
                    if (obj->unk2A < 0) {
                        mA[0][0] = mA[1][1] = 1.0f;
                        mA[0][1] = mA[1][0] = 0.0f;
                        mA[2][0] = (f32)obj->unk40 + (f32)obj->unk54;
                        mA[2][1] = (f32)obj->unk42 + (f32)obj->unk55;
                        obj->unk4 = obj->unk40;
                        obj->unk6 = obj->unk42;
                    } else {
                        mB[0][0] = mB[1][1] = 1.0f;
                        mB[0][1] = mB[1][0] = 0.0f;
                        mB[2][0] = (obj->unk40 + obj->unk54) * obj->unk14;
                        mB[2][1] = (obj->unk42 + obj->unk55) * obj->unk18;
                        func_80065B68(mB, mtx[obj->unk2A], mA);
                        obj->unk4 = mA[2][0];
                        obj->unk6 = mA[2][1];
                    }
                    obj->unk1C = obj->unk44;
                    angle = -obj->unk44 * 0.0174532925222222225;
                    mB[0][0] = mB[1][1] = cosf(angle);
                    s = sinf(angle);
                    mB[0][1] = s;
                    mB[1][0] = -s;
                    mB[2][0] = mB[2][1] = 0.0f;
                    func_80065B68(mB, mA, mtx[obj->unk0]);
                    func_80068124(obj);
                    TREE_NEXT(obj, cur, sp, stack, grp);
                }
                break;
            case 5:
                cur = func_80065A2C(grp);
                for (i = 0; i < grp->count; i++) {
                    obj = grp->obj[cur];
                    func_80067E38(obj);
                    if (obj->unk2A < 0) {
                        mA[0][0] = mA[1][1] = 1.0f;
                        mA[0][1] = mA[1][0] = 0.0f;
                        mA[2][0] = (f32)obj->unk40 + (f32)obj->unk54;
                        mA[2][1] = (f32)obj->unk42 + (f32)obj->unk55;
                        obj->unk4 = obj->unk40;
                        obj->unk6 = obj->unk42;
                        obj->unk1C = obj->unk44;
                    } else {
                        parent = grp->obj[obj->unk2A];
                        mB[0][0] = mB[1][1] = 1.0f;
                        mB[0][1] = mB[1][0] = 0.0f;
                        mB[2][0] = (obj->unk40 + obj->unk54) * obj->unk14;
                        mB[2][1] = (obj->unk42 + obj->unk55) * obj->unk18;
                        func_80065B68(mB, mtx[obj->unk2A], mA);
                        obj->unk4 = mA[2][0];
                        obj->unk6 = mA[2][1];
                        obj->unk1C = parent->unk1C + obj->unk44;
                    }
                    angle = -obj->unk44 * 0.0174532925222222225;
                    mB[0][0] = mB[1][1] = cosf(angle);
                    s = sinf(angle);
                    mB[0][1] = s;
                    mB[1][0] = -s;
                    mB[2][0] = mB[2][1] = 0.0f;
                    func_80065B68(mB, mA, mtx[obj->unk0]);
                    func_80068124(obj);
                    TREE_NEXT(obj, cur, sp, stack, grp);
                }
                break;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/65770", func_80065BF8);
#endif

void func_800666D4(void) {
    if (D_800EE978[D_800F37F0] != NULL) {
        func_80023728(D_800EE978[D_800F37F0]);
    }
    if (D_800F37CC != 0) {
        D_800EE978[D_800F37F0] = func_80023668(D_800F37CC);
    } else {
        D_800EE978[D_800F37F0] = NULL;
    }
    D_800F54B4 = D_800EE978[D_800F37F0];
}
void func_8006677C(Gfx** gfx, Mtx* mtx, unk_Struct00* cam) {
    unk65770Obj* obj;
    unk65770Obj* next;
    s16 flag = 0;
    Gfx* branch = NULL;
    Gfx* end = NULL;

    D_800F37CC = 0;
    func_80065BF8();
    obj = func_80065700();
    func_800666D4();
    gSPViewport((*gfx)++, &D_800C5B40);
    gSPPerspNormalize((*gfx)++, 0x41);
    gSPMatrix((*gfx)++, osVirtualToPhysical(&D_800E40E0), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gDPSetScissor((*gfx)++, G_SC_NON_INTERLACE, 0, 0, 320, 240);
    gDPPipeSync((*gfx)++);
    gDPSetTexturePersp((*gfx)++, G_TP_NONE);
    gSPTexture((*gfx)++, 0xFFFF, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gSPClearGeometryMode((*gfx)++, G_CULL_BOTH);
    gDPSetBlendColor((*gfx)++, 0, 0, 0, 1);
    gDPSetAlphaCompare((*gfx)++, G_AC_THRESHOLD);
    D_800E4120 = NULL;
    while (obj != NULL) {
        if (obj->unk20 & 0x4000) {
            if (flag) {
                if (branch != NULL) {
                    gSPBranchList(branch, *gfx + 1);
                }
                end = (*gfx)++;
            }
            flag = 0;
        } else {
            if (!flag) {
                if (end != NULL) {
                    gSPBranchList(end, *gfx + 1);
                }
                branch = (*gfx)++;
                if (D_800E4120 == NULL) {
                    D_800E4120 = *gfx;
                }
            }
            flag = 1;
        }
        func_80068410(gfx, obj);
        next = obj->unk64;
        obj->unk68 = NULL;
        obj->unk64 = NULL;
        obj = next;
    }
    if (flag) {
        gSPEndDisplayList((*gfx)++);
        if (branch != NULL) {
            gSPBranchList(branch, *gfx);
        }
    } else if (D_800E4120 != NULL) {
        gSPEndDisplayList(end);
    }
    gDPSetTextureLUT((*gfx)++, G_TT_NONE);
    gSPMatrix((*gfx)++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix((*gfx)++, mtx + 1, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetScissor((*gfx)++, G_SC_NON_INTERLACE, cam->unkD8.x, cam->unkD8.y, cam->unkD8.z, cam->unkD8.w);
}
void func_80066B3C(Gfx** gfx, Mtx* mtx, unk_Struct00* cam) {
    if (D_800E4120 != NULL) {
        gSPViewport((*gfx)++, &D_800C5B40);
        gSPPerspNormalize((*gfx)++, 0x41);
        gSPMatrix((*gfx)++, osVirtualToPhysical(&D_800E40E0), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        gDPSetScissor((*gfx)++, G_SC_NON_INTERLACE, 0, 0, 320, 240);
        gDPPipeSync((*gfx)++);
        gDPSetTexturePersp((*gfx)++, G_TP_NONE);
        gSPTexture((*gfx)++, 0xFFFF, 0x8000, 0, G_TX_RENDERTILE, G_ON);
        gSPClearGeometryMode((*gfx)++, G_CULL_BOTH);
        gDPSetBlendColor((*gfx)++, 0, 0, 0, 1);
        gDPSetAlphaCompare((*gfx)++, G_AC_THRESHOLD);
        gSPDisplayList((*gfx)++, D_800E4120);
        gDPSetTextureLUT((*gfx)++, G_TT_NONE);
        gSPMatrix((*gfx)++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        gSPMatrix((*gfx)++, mtx + 1, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gDPSetScissor((*gfx)++, G_SC_NON_INTERLACE, cam->unkD8.x, cam->unkD8.y, cam->unkD8.z, cam->unkD8.w);
    }
}
void func_80066DC4(s16 grpIdx, s16 idx, s16 x, s16 y) {
    unk65770Obj* obj = D_800EE330[grpIdx]->obj[idx];

    obj->unk40 = x;
    obj->unk42 = y;
}
/* Halfword i of an N64-layout Mtx (integer halves 0..15, fractions 16..31). The host keeps the
   32-bit words in host byte order, so a u16 index would read the other half of each word. */
#define MTX_HALF(m, i) (((u16*)(m))[i])
void func_80066DF4(s16 grpIdx, s16 idx, s16 camIdx, f32 x, f32 y, f32 z) {
    Mtx mtx;
    unk65770Obj* obj = D_800EE330[grpIdx]->obj[idx];
    unk_Struct00* cam = &D_800C3110[camIdx];
    Mtx* view = (Mtx*)((u8*)&cam->unkF8 + D_800F3FA8 * 0x80) + 1;
    Mtx* m = &mtx;
    unk_Struct00* vp;
    f32 sx;
    f32 sy;
    f32 sz;
    f32 dist;

    guTranslate(m, x, y, z);
    guMtxCatL(m, view, m);
    sx = (s32)((MTX_HALF(&mtx, 12) << 16) | MTX_HALF(&mtx, 28)) >> 16;
    sy = (s32)((MTX_HALF(&mtx, 13) << 16) | MTX_HALF(&mtx, 29)) >> 16;
    sz = (s32)((MTX_HALF(&mtx, 14) << 16) | MTX_HALF(&mtx, 30)) >> 16;
    dist = sz * sinf(D_800C3110[camIdx].unk_40 * 0.017444444444444446 / 2.0);
    dist = fabsf(dist / cosf(D_800C3110[camIdx].unk_40 * 0.017444444444444446 / 2.0));
    D_800E4124 = dist;
    if (dist != 0.0) {
        vp = (unk_Struct00*)((u8*)cam + D_800F3FA8 * 16);
        obj->unk40 = (s16)(vp->unk58 / 4.0 * sx / dist / 1.3333334f) + vp->unk60 / 4.0;
        obj->unk42 = (s16)(vp->unk5A / 4.0 * -sy / dist) + vp->unk62 / 4.0;
    }
}
void func_800670C4(s16 grpIdx, s16 idx, s16 camIdx, f32 x, f32 y, f32 z) {
    unk65770Obj* obj = D_800EE330[grpIdx]->obj[idx];
    unk_Struct00* cam = &D_800C3110[camIdx];
    unk_Struct00* vp;

    func_80066DF4(grpIdx, idx, camIdx, x, y, z);
    if (D_800E4124 != 0.0) {
        vp = (unk_Struct00*)((u8*)cam + D_800F3FA8 * 16);
        obj->unk14 = vp->unk58 / 4.0 / D_800E4124 / 1.3333334f;
        obj->unk18 = vp->unk5A / 4.0 / D_800E4124;
    }
}
void func_800671DC(s16 grpIdx, s16 idx, s16 arg2) {
    D_800EE330[grpIdx]->obj[idx]->unk52 = arg2;
}
void func_80067208(s16 grpIdx, s16 idx, s16 animIdx, u16 attr) {
    unk65770Obj* obj = D_800EE330[grpIdx]->obj[idx];

    obj->unk4C = D_800EC700[animIdx];
    if (D_800EC700[animIdx]->unk4 != NULL) {
        obj->unkA = 1;
    }
    obj->unk8 = attr;
    obj->unk58 = 0;
    obj->unkC = 1.0f;
    obj->unk50 = 0;
    obj->unk5C = 0;
    obj->unk52 = 0;
}
void func_80067284(s16 grpIdx, s16 idx, f32 speed) {
    D_800EE330[grpIdx]->obj[idx]->unkC = speed;
}
void func_800672B0(s16 grpIdx, s16 idx, u16 arg2) {
    D_800EE330[grpIdx]->obj[idx]->unkA = arg2;
}
void func_800672DC(s16 grpIdx, s16 idx, u16 attr, s32 arg3) {
    unk65770Obj* obj = D_800EE330[grpIdx]->obj[idx];

    obj->unk8 = attr;
    obj->unk50 = arg3;
    obj->unk58 = 0;
}
unk65770Anim* func_80067310(s16 animIdx) {
    return D_800EC700[animIdx];
}
u8 func_80067328(s16 grpIdx, s16 idx) {
    return D_800EE330[grpIdx]->obj[idx]->unk5C;
}
void func_80067354(s16 grpIdx, s16 idx, f32 sx, f32 sy) {
    unk65770Obj* obj = D_800EE330[grpIdx]->obj[idx];

    obj->unk14 = sx;
    obj->unk18 = sy;
}
void func_80067384(s16 grpIdx, s16 idx, u16 pri) {
    D_800EE330[grpIdx]->obj[idx]->unk10 = pri;
}
void func_800673B0(s16 grpIdx, s16 idx, f32 rot) {
    D_800EE330[grpIdx]->obj[idx]->unk44 = rot;
}
void func_800673DC(s16 grpIdx, s16 idx, unk65770ObjInit* init) {
    unk65770Obj* obj = D_800EE330[grpIdx]->obj[idx];

    obj->unk40 = init->unk0;
    obj->unk42 = init->unk2;
    obj->unk8 = init->unk4;
    obj->unkA = init->unk6;
    obj->unkC = init->unk8;
    obj->unk10 = init->unkC;
    obj->unk14 = init->unk10;
    obj->unk18 = init->unk14;
    obj->unk44 = init->unk18;
    obj->unk48 = obj->unk20 = init->unk1C;
    obj->unk24 = init->unk20;
    obj->unk25 = init->unk21;
    obj->unk26 = init->unk22;
    obj->unk28 = init->unk24;
    obj->unk2A = init->unk26;
}
void func_80067480(s16 grpIdx, s16 idx, s32 flag) {
    unk65770Obj* obj = D_800EE330[grpIdx]->obj[idx];

    obj->unk20 = obj->unk48 &= ~flag;
}
void func_800674BC(s16 grpIdx, s16 idx, s32 flag) {
    unk65770Obj* obj = D_800EE330[grpIdx]->obj[idx];

    obj->unk20 = obj->unk48 |= flag;
}
void func_800674F4(s16 grpIdx, s32 idx, s32 r, s32 g, u8 b) {
    unk65770Obj* obj = D_800EE330[grpIdx]->obj[(s16)idx];

    obj->unk24 = r;
    obj->unk25 = g;
    obj->unk26 = b;
}
void func_8006752C(s16 grpIdx, s16 idx, u16 arg2) {
    D_800EE330[grpIdx]->obj[idx]->unk28 = arg2;
}
void func_80067558(s16 grpIdx, s32 idx, u8 r, u8 g, u8 b, u16 a) {
    unk65770Obj* obj = D_800EE330[grpIdx]->obj[(s16)idx];

    obj->unk24 = r;
    obj->unk25 = g;
    obj->unk26 = b;
    obj->unk28 = a;
}
void func_80067598(s16 grpIdx, s16 idx, s32 parent) {
    D_800EE330[grpIdx]->obj[idx]->unk2A = parent;
}
void func_800675C4(s16 grpIdx, s16 idx, u8 arg2, u8 arg3) {
    unk65770Obj* obj = D_800EE330[grpIdx]->obj[idx];

    obj->unk54 = arg2;
    obj->unk55 = arg3;
}
unk65770Obj* func_800675F4(s16 grpIdx, s16 idx) {
    return D_800EE330[grpIdx]->obj[idx];
}
void func_8006761C(s16 grpIdx, s16 idx, s16 arg2, s16 arg3, u16 arg4, u16 arg5) {
    unk65770Obj* obj = D_800EE330[grpIdx]->obj[idx];

    obj->unk38 = arg2;
    obj->unk3A = arg3;
    obj->unk3C = arg4;
    obj->unk3E = arg5;
}
void func_8006765C(s16 grpIdx, s16 idx, f32 arg2, f32 arg3) {
    unk65770Obj* obj = D_800EE330[grpIdx]->obj[idx];

    obj->unk2C = arg2;
    obj->unk30 = arg3;
}
void func_8006768C(s16 grpIdx, s16 idx, s16 arg2, s16 arg3) {
    unk65770Obj* obj = D_800EE330[grpIdx]->obj[idx];

    obj->unk34 = arg2;
    obj->unk36 = arg3;
}
void func_800676BC(void) {
    s16 i;

    D_800ED3EC = 0;
    for (i = 0; i < 256; i++) {
        D_800EC700[i] = NULL;
    }
}
void func_80067704(s16 animIdx) {
    unk65770Anim* anim = D_800EC700[animIdx];
    unk65770Anim8* p8;
    unk65770AnimC* pC;
    s16 i;

    if (anim->unk4 != NULL) {
        p8 = *anim->unk4;
        if (p8 != NULL) {
            for (i = 0; i < anim->unk12; i++) {
                func_80023728(p8->unk4);
                p8++;
            }
        }
        func_80023728(*anim->unk4);
        func_80023728(anim->unk4);
    }
    func_80023888(anim->unkC);
    pC = anim->unk0;
    for (i = 0; i < anim->unk10; i++) {
        func_80023888((pC++)->unk0);
    }
    func_80023728(anim->unk0);
    func_80023728(anim);
    D_800EC700[animIdx] = NULL;
    D_800ED3EC--;
}
void func_80067834(void) {
    s16 i;

    for (i = 0; i < 256; i++) {
        if (D_800EC700[i] != NULL) {
            func_80067704(i);
        }
    }
}
// register allocation: idx/pal swap s7/s8, keys[k] not reloaded (masked 26)
#ifdef NON_MATCHING
s16 func_800678A4(void* arg0) {
    u8* data = arg0;
    unk65770Key* keys[256];
    u8* bankTbl;
    unk65770Anim* anim;
    unk65770AnimC* frame;
    unk65770Anim8** tbl;
    unk65770Anim8* banks;
    unk65770Key* key;
    u8* src;
    u8* pix;
    u8* pal;
    u8* p;
    u8* palDst;
    s32 size;
    u32 j;
    s16 i;
    s16 k;
    s16 idx;

    for (i = 0; i < 256; i++) {
        if (D_800EC700[i] == NULL) {
            break;
        }
    }
    if (i == 256) {
        return -1;
    }
    idx = i;
    anim = func_80023668(sizeof(*anim));
    if (anim == NULL) {
        return -1;
    }
    src = data + READ32(data);
    bankTbl = data + READ32(data + 4);
    pix = data + READ32(data + 8);
    pal = data + READ32(data + 0xC);
    anim->unk10 = READ16(data + 0x10);
    anim->unk12 = READ16(data + 0x12);
    anim->unk14 = READ16(data + 0x14);
    anim->unk16 = READ16(data + 0x16);
    anim->unk18 = READ16(data + 0x18);
    anim->unk1A = data[0x1A];
    anim->unk0 = NULL;
    anim->unk4 = NULL;
    anim->unk8 = NULL;
    anim->unkC = NULL;
    D_800EC700[idx] = anim;
    D_800ED3EC++;
    frame = func_80023668(anim->unk10 * sizeof(*frame));
    if (frame == NULL) {
        func_80067704(idx);
        return -1;
    }
    anim->unk0 = frame;
    for (i = 0; i < anim->unk10; i++) {
        frame->unk4 = READ16(src + 4);
        frame->unk6 = READ16(src + 6);
        frame->unk8 = READ16(src + 8);
        frame->unkA = READ16(src + 0xA);
        size = frame->unk4 * frame->unk6 * (anim->unk18 & 0x7FFF) / 8;
        if ((frame->unk0 = func_80023668(size)) == NULL) {
            goto fail_frame;
        }
        for (j = 0; j < size; j++) {
            frame->unk0[j] = *pix++;
        }
        src += 0xC;
        if (i == 0) {
            anim->unk8 = frame->unk0;
        }
        frame++;
    }
    if (anim->unk1A != 0) {
        palDst = func_80023668(anim->unk1A * 2);
        if (palDst == NULL) {
            goto fail;
        }
        anim->unkC = palDst;
        for (i = 0; i < anim->unk1A; i++) {
            *palDst++ = pal[i * 2];
            *palDst++ = pal[i * 2 + 1];
        }
    }
    if (anim->unk12 != 0) {
        tbl = func_80023668(anim->unk12 * sizeof(*tbl));
        if (tbl == NULL) {
            goto fail;
        }
        anim->unk4 = tbl;
        banks = func_80023668(anim->unk12 * sizeof(*banks));
        if (banks != NULL) {
            goto ok;
        }
        goto fail;
    fail_frame:
        anim->unk10 = i;
        goto fail;
    fail_bank:
        anim->unk12 = k;
    fail:
        func_80067704(idx);
        return -1;
    ok:
        // retail bug: the stride is 64 bytes, not one bank; only tbl[0] is ever read
        for (i = 0; i < anim->unk12; i++) {
            tbl[i] = &banks[i * 8];
        }
        for (k = 0; k < anim->unk12; k++) {
            p = data + READ32(bankTbl + k * 4);
            banks->unk0 = READ16(p);
            p += 2;
            keys[k] = func_80023668(banks->unk0 * 8);
            if (keys[k] == NULL) {
                goto fail_bank;
            }
            banks->unk4 = keys[k];
            key = keys[k];
            for (i = 0; i < banks->unk0; i++) {
                key->unk0 = READ16(p);
                key->unk2 = READ16(p + 2);
                key->unk4 = p[4];
                key->unk5 = p[5];
                key->unk6 = p[6];
                p += 7;
                key++;
            }
            banks++;
        }
    }
    return idx;
}
#else
INCLUDE_ASM("asm/nonmatchings/65770", func_800678A4);
#endif

void func_80067E38(unk65770Obj* obj) {
    unk65770Anim* anim;
    unk65770Anim8* bank;
    unk65770Key* key;
    s16 paused;
    s16 old;

    paused = D_800F384E && !(obj->unk20 & 0x1000000);
    if (!paused) {
        obj->unk5C = 0;
    }
    anim = obj->unk4C;
    if (anim == NULL) {
        return;
    }
    switch (obj->unkA) {
        case 0:
            break;
        case 1:
            if (anim->unk4 == NULL) {
                break;
            }
            bank = &(*anim->unk4)[obj->unk8];
            key = &bank->unk4[obj->unk50];
            obj->unk52 = key->unk0;
            obj->unk54 = key->unk4;
            obj->unk55 = key->unk5;
            obj->unk56 = key->unk6;
            if (paused) {
                break;
            }
            obj->unk58 += obj->unkC;
            if ((s16)obj->unk58 > key->unk2) {
                obj->unk58 = 0.0f;
                obj->unk50++;
                obj->unk5C |= 8;
                if (obj->unk50 >= bank->unk0) {
                    obj->unkA = 0;
                    obj->unk5C |= 2;
                } else if (bank->unk4[obj->unk50].unk2 < 0) {
                    obj->unk50 = 0;
                    obj->unk5C |= 4;
                }
            }
            obj->unk5C |= 1;
            break;
        case 2:
            obj->unk52 = obj->unk50;
            if (paused) {
                break;
            }
            old = obj->unk50;
            obj->unk58 += obj->unkC;
            obj->unk50 = (s32)obj->unk58 + obj->unk50;
            if (obj->unk50 != old) {
                obj->unk58 -= obj->unk50 - old;
                obj->unk5C |= 8;
            }
            if (obj->unk50 >= obj->unk4C->unk10) {
                obj->unk50 = 0;
                obj->unk58 = 0.0f;
                obj->unk5C |= 4;
            }
            obj->unk5C |= 1;
            break;
        case 3:
            obj->unk52 = obj->unk50;
            if (paused) {
                break;
            }
            old = obj->unk50;
            obj->unk58 += obj->unkC;
            obj->unk50 = (s32)obj->unk58 + obj->unk50;
            if (obj->unk50 != old) {
                obj->unk58 -= obj->unk50 - old;
                obj->unk5C |= 4;
            }
            if (obj->unk50 < 0 || obj->unk50 >= obj->unk4C->unk10) {
                obj->unk50 = (obj->unkC < 0.0f) ? 1 : obj->unk4C->unk10 - 2;
                obj->unk58 = 0.0f;
                obj->unkC = -obj->unkC;
                obj->unk5C |= 4;
            }
            obj->unk5C |= 1;
            break;
    }
}
void func_80068124(unk65770Obj* obj) {
    unk65770Anim* anim;
    unk65770AnimC* frame;
    s32 fmt = 0;
    s32 siz = 0;
    s32 flags;
    s32 w;
    u32 lines;
    s32 n;

    flags = obj->unk20 = obj->unk56 ^ obj->unk48;
    if (obj->unk4C != NULL && !(flags & 0x8000) &&
        (obj->unk1C != 0.0 || (flags & 0x3C0000) || (flags & 0x30000) == 0x30000
        )) {
        anim = obj->unk4C;
        frame = &anim->unk0[obj->unk52];
        switch (anim->unk18 & 0x7FFF) {
            case 4:
                fmt = 2;
                siz = 0;
                break;
            case 8:
                fmt = 2;
                siz = 1;
                break;
            case 16:
                fmt = 0;
                siz = 2;
                break;
            case 24:
                fmt = 0;
                siz = 3;
                break;
        }
        w = (((frame->unk4 << siz) >> 4) << 4) >> siz;
        if (w < frame->unk4) {
            w += 16 >> siz;
        }
        switch (fmt) {
        case 2:
            if ((0x1000 >> siz) >= frame->unk6 * w) {
                lines = frame->unk6;
            } else {
                lines = (0x1000 >> siz) / w;
            }
            break;
        case 4:
            lines = frame->unk6;
            if (frame->unk6 * w > 0x1000) {
                lines = 0x1000 / w;
            }
            break;
        default:
            if ((0x2000 >> siz) >= frame->unk6 * w) {
                lines = frame->unk6;
            } else {
                lines = (0x2000 >> siz) / w;
            }
            break;
        }
        n = frame->unk6 / lines;
        if (!(obj->unk20 & 0x2000)) {
            D_800F37CC += ((n + 2) << 5) + 0x40;
        } else {
            D_800F37CC += ((n + 2) << 6) + 0x40;
        }
    }
}
void func_80068398(void) {
    s16 i;

    func_80064E64();
    func_80067834();
    for (i = 0; i < 3; i++) {
        if (D_800EE978[i] != NULL) {
            func_80023728(D_800EE978[i]);
        }
    }
}