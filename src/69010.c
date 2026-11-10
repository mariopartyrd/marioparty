#include "common.h"
s32 D_800C5B50 = 0x100;
s32 D_800C5B54[4] = { 12, 6, 20, 0 };
s32 D_800C5B64[] = { 1, 0, 3 };
s32 D_800C5B70[4] = { 4, 3, 2, 1 };
s16 D_800C5B80[] = {
    0x0, 0x200, 0x100, 0xAA, 0x80, 0x66, 0x55, 0x49, 0x40, 0x38, 0x33, 0x14,
    0x2A, 0x1A, 0xE, 0x13, 0x20, 0xD, 0x1C, 0x1A, 0x8, 0x9, 0x4, 0x4,
    0x5, 0x14, 0xD, 0x12, 0x3, 0x6, 0x3, 0x2, 0x10, 0x2, 0x2, 0x3,
    0xE, 0x2, 0xD, 0x2, 0x1, 0xC, 0x4, 0x2, 0x2, 0x2, 0x2, 0x2,
    0x2, 0x4, 0xA, 0x0, 0x1, 0x2, 0x9, 0x0, 0x1, 0x8, 0x0, 0x2,
    0x0, 0x1, 0x0, 0x1, 0x8, 0x0, 0x0, 0x1, 0x0, 0x1, 0x0, 0x2,
    0x0, 0x0, 0x1, 0x0, 0x6, 0x0, 0x0, 0x4, 0x0, 0x0, 0x6, 0x0,
    0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x1, 0x0,
    0x0, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0,
    0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0
};
s16 D_800C5CB8[] = {
    0x0, 0x200, 0x100, 0xAA, 0x80, 0x66, 0x55, 0x49, 0x40, 0x38, 0x33, 0x2E,
    0x2A, 0x27, 0x24, 0x22, 0x20, 0x1E, 0x1C, 0x1A, 0x19, 0x18, 0x17, 0x16,
    0x15, 0x14, 0x13, 0x13, 0x12, 0x12, 0x11, 0x11, 0x10, 0x10, 0xF, 0xF,
    0xE, 0xE, 0xD, 0xD, 0xD, 0xC, 0xC, 0xC, 0xB, 0xB, 0xB, 0xA,
    0xA, 0xA, 0xA, 0xA, 0x9, 0x9, 0x9, 0x9, 0x9, 0x8, 0x8, 0x8,
    0x8, 0x8, 0x8, 0x8, 0x8, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7,
    0x7, 0x7, 0x6, 0x6, 0x6, 0x6, 0x6, 0x6, 0x6, 0x6, 0x6, 0x6,
    0x6, 0x6, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5,
    0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x4, 0x4, 0x4, 0x4, 0x4,
    0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4,
    0x4, 0x4, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3,
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3,
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x0
};

typedef struct unk69010Frame {
    /* 0x00 */ u32 timg; /* unk65770AnimC.unk0, the pixels (a pointer: wide on the host) */
    /* 0x04 */ u16 width;
    /* 0x06 */ u16 height;
    /* 0x08 */ u16 centerX;
    /* 0x0A */ u16 centerY;
} unk69010Frame; // sizeof 0xC

typedef struct unk69010Sheet {
    /* 0x00 */ unk69010Frame* frames;
    /* 0x04 */ void* unk_04; /* unk65770Anim.unk4 and unk8 (pointers) */
    /* 0x08 */ void* unk_08;
    /* 0x0C */ u32 palette; /* unk65770Anim.unkC */
    /* 0x10 */ char unk_10[8];
    /* 0x18 */ u16 format;
    /* 0x1A */ u8 unk_1A;
} unk69010Sheet;

typedef struct unk69010Sprite {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s16 x;
    /* 0x06 */ s16 y;
    /* 0x08 */ char unk_08[0xC];
    /* 0x14 */ f32 scaleX;
    /* 0x18 */ f32 scaleY;
    /* 0x1C */ f32 rot;
    /* 0x20 */ u32 flags;
    /* 0x24 */ u8 r;
    /* 0x25 */ u8 g;
    /* 0x26 */ u8 b;
    /* 0x27 */ char unk_27;
    /* 0x28 */ u16 alpha;
    /* 0x2A */ char unk_2A[2];
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ u16 unk_34;
    /* 0x36 */ u16 unk_36;
    /* 0x38 */ s16 unk_38;
    /* 0x3A */ s16 unk_3A;
    /* 0x3C */ s16 unk_3C;
    /* 0x3E */ s16 unk_3E;
    /* 0x40 */ char unk_40[0xC];
    /* 0x4C */ unk69010Sheet* sheet;
    /* 0x50 */ char unk_50[2];
    /* 0x52 */ s16 frame;
} unk69010Sprite;

extern s32 D_800ED0F8;
extern s32 D_800EE314;
extern s32 D_800F2A74;
extern s32 D_800F3B84;
extern s32 D_800F5444;
extern s32 D_800F5448;
extern s32 D_800F5454;
extern void* D_800F54B4;

void func_8003B0AC(unk3AC60Struct1* arg0, f64 arg1, f64 arg2, f64 arg3);
void func_8003B190(unk3AC60Struct0* arg0, unk3AC60Struct1* arg1, unk3AC60Struct2* arg2);
void guMtxIdent(Mtx* m);

void func_8003A060(Gfx**, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_8003A28C(Gfx**, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_8003A4EC(Gfx**, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_8003A828(Gfx**, s32, s32, u32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_8003AA98(Gfx**, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_8003AE00(Gfx**, s32, s32, u32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_80069394(Gfx** arg0, unk69010Sprite* arg1);
void func_8006B014(Gfx** arg0, unk69010Sprite* arg1, u16 arg2, u16 arg3, u16 arg4, u16 arg5, u16 arg6, u16 arg7, u16 arg8, u16 arg9, u16 arg10);
void func_8006B464(Gfx** arg0, unk69010Sprite* arg1, u16 arg2, u16 arg3, u16 arg4, u16 arg5, u16 arg6, u16 arg7, u16 arg8, u16 arg9, u16 arg10);

// decomp-permuter

void func_80068410(Gfx **arg0, unk69010Sprite *arg1)
{
  f32 corners[4][2];
  Gfx *gfx;
  unk69010Frame *frame;
  f32 scaleX;
  f32 scaleY;
  f32 sinR;
  f32 cosR;
  f32 maxX = -1.0f;
  int new_var;
  f32 maxY = -1.0f;
  f32 minX = 321.0f;
  f32 minY = 241.0f;
  s32 i;
  s32 alignW;
  u16 format;
  s32 cycScale;
  if (arg1->sheet == 0)
  {
    return;
  }
  scaleX = arg1->scaleX;
  scaleY = arg1->scaleY;
  if ((!(scaleX > 0.0f)) || (!(scaleY > 0.0f)))
  {
    return;
  }
  frame = &arg1->sheet->frames[arg1->frame];
  sinR = func_800AEAC0(arg1->rot);
  cosR = func_800AEFD0(arg1->rot);
  corners[0][0] = arg1->x - (((frame->centerX * scaleX) * cosR) + ((frame->centerY * scaleY) * (-sinR)));
  corners[0][1] = arg1->y - (((frame->centerX * scaleX) * sinR) + ((frame->centerY * scaleY) * cosR));
  corners[1][0] = arg1->x + ((((frame->width - frame->centerX) * scaleX) * cosR) + ((frame->centerY * scaleY) * (-sinR)));
  corners[1][1] = arg1->y - ((((frame->width - frame->centerX) * scaleX) * sinR) + ((frame->centerY * scaleY) * cosR));
  corners[2][0] = arg1->x - (((frame->centerX * scaleX) * cosR) + (((frame->height - frame->centerY) * scaleY) * (-sinR)));
  corners[2][1] = arg1->y + (((frame->centerX * scaleX) * func_800AEAC0(arg1->rot)) + (((frame->height - frame->centerY) * scaleY) * cosR));
  corners[3][0] = arg1->x - ((((frame->width - frame->centerX) * scaleX) * cosR) + (((frame->height - frame->centerY) * scaleY) * (-sinR)));
  corners[3][1] = arg1->y + ((((frame->width - frame->centerX) * scaleX) * sinR) + (((frame->height - frame->centerY) * scaleY) * cosR));
  for (i = 0; i < 4; i++)
  {
    if (maxX <= corners[i][0])
    {
      maxX = corners[i][0];
    }
    if (corners[i][0] <= minX)
    {
      minX = corners[i][0];
    }
    if (maxY <= corners[i][1])
    {
      maxY = corners[i][1];
    }
    if (corners[i][1] <= minY)
    {
      minY = corners[i][1];
    }
  }

  if (maxX < 0.0f)
  {
    return;
  }
  if (minX > 320.0)
  {
    return;
  }
  if (maxY < 0.0f)
  {
    return;
  }
  if (minY > 240.0)
  {
    return;
  }
  gfx = *arg0;
  switch (arg1->sheet->format)
  {
    case 0x4:
      D_800F5444 = 0;
      if (arg1->sheet->unk_1A == 1)
    {
      D_800F3B84 = 3;
      gDPSetTextureLUT(gfx++, G_TT_NONE);
    }
    else
    {
      D_800F3B84 = 2;
      gDPLoadTLUT_pal16(gfx++, 0, arg1->sheet->palette);
      gDPSetTextureLUT(gfx++, G_TT_RGBA16);
      D_800C5B50 = 0x80;
    }
      D_800F2A74 = 0;
      break;

    case 0x8:
      D_800F5444 = 1;
      if (arg1->sheet->unk_1A == 1)
    {
      D_800F3B84 = 3;
      gDPSetTextureLUT(gfx++, G_TT_NONE);
    }
    else
    {
      D_800F3B84 = 2;
      gDPLoadTLUT_pal256(gfx++, arg1->sheet->palette);
      gDPSetTextureLUT(gfx++, G_TT_RGBA16);
      D_800C5B50 = 0x80;
    }
      D_800F2A74 = 2;
      break;

    case 0x10:
      D_800F5444 = 2;
      if (arg1->sheet->unk_1A == 1)
    {
      D_800F3B84 = 3;
    }
    else
    {
      D_800F3B84 = 0;
    }
      gDPSetTextureLUT(gfx++, G_TT_NONE);
      D_800C5B50 = 0x100;
      D_800F2A74 = 2;
      break;

    case 0x20:
      D_800F5444 = 3;
      D_800F3B84 = 0;
      gDPSetTextureLUT(gfx++, G_TT_NONE);
      D_800C5B50 = 0x100;
      D_800F2A74 = 2;
      break;

    case 0x8004:
      D_800F5444 = 0;
      D_800F3B84 = 4;
      gDPSetTextureLUT(gfx++, G_TT_NONE);
      D_800C5B50 = 0x100;
      D_800F2A74 = 0;
      break;

    case 0x8008:
      D_800F5444 = 1;
      D_800F3B84 = 4;
      gDPSetTextureLUT(gfx++, G_TT_NONE);
      D_800C5B50 = 0x100;
      D_800F2A74 = 2;
      break;

  }

  alignW = (((frame->width << D_800F5444) >> 4) << 4) >> D_800F5444;
  if (alignW < frame->width)
  {
    alignW += 16 >> D_800F5444;
  }
  switch (D_800F3B84)
  {
    case 2:
      if ((0x1000 >> D_800F5444) >= (frame->height * alignW))
    {
      D_800EE314 = frame->height;
    }
    else
    {
      D_800EE314 = (0x1000 >> D_800F5444) / alignW;
    }
      break;

    case 4:
      if ((frame->height * alignW) < 0x1001)
    {
      D_800EE314 = frame->height;
    }
    else
    {
      D_800EE314 = 0x1000 / alignW;
    }
      break;

    default:
      if ((0x2000 >> D_800F5444) >= (frame->height * alignW))
    {
      D_800EE314 = frame->height;
    }
    else
    {
      D_800EE314 = (0x2000 >> D_800F5444) / alignW;
    }
      break;

  }

  D_800F5448 = frame->height / D_800EE314;
  D_800ED0F8 = frame->height - (D_800F5448 * D_800EE314);
  if ((((frame->width % (16 >> D_800F5444)) == 0) && (((frame->width * D_800EE314) << D_800F5444) <= 0x1000)) && ((D_800C5B80[frame->width >> D_800C5B70[D_800F5444]] >= D_800EE314) || (D_800EE314 == D_800C5CB8[frame->width >> D_800C5B70[D_800F5444]])))
  {
    D_800F2A74++;
  }
  new_var = 4;
  gDPPipeSync(gfx++);
  gSPSetOtherMode(gfx++, G_SETOTHERMODE_H, D_800C5B54[0], 2, ((arg1->flags >> 2) & 3) << D_800C5B54[0]);
  gSPSetOtherMode(gfx++, G_SETOTHERMODE_H, D_800C5B54[1], 2, (((arg1->flags >> new_var) ^ 3) & 3) << D_800C5B54[1]);
  gSPSetOtherMode(gfx++, G_SETOTHERMODE_H, D_800C5B54[2], 2, ((arg1->flags >> 6) & 3) << D_800C5B54[2]);
  gSPSetOtherMode(gfx++, G_SETOTHERMODE_L, D_800C5B54[3], 2, D_800C5B64[(arg1->flags >> 22) & 3]);
  if ((arg1->flags >> 6) & 2)
  {
    cycScale = 4;
    gDPSetRenderMode(gfx++, 0, 0);
    gDPSetCombine(gfx++, 0xFFFFFF, 0xFFFCF279);
    D_800F5454 = cycScale;
    func_80069394(&gfx, arg1);
    *arg0 = gfx;
  }
  else
  {
    format = arg1->sheet->format;
    switch ((arg1->flags >> 10) & 3)
    {
      case 0:
        if (arg1->flags & 0x1000)
      {
        if ((arg1->alpha == 0x100) && (!(format & 0x8000)))
        {
          gDPSetRenderMode(gfx++, 0x0C087008, 0);
        }
        else
        {
          gDPSetRenderMode(gfx++, 0x404240, 0);
        }
      }
      else
      {
        gDPSetRenderMode(gfx++, 0x0C084000, 0);
      }
        break;

      case 1:
        if (arg1->flags & 0x1000)
      {
        if ((arg1->alpha == 0x100) && (!(format & 0x8000)))
        {
          gDPSetRenderMode(gfx++, 0x443048, 0);
        }
        else
        {
          gDPSetRenderMode(gfx++, 0x4041C8, 0);
        }
      }
      else
      {
        gDPSetRenderMode(gfx++, 0x552008, 0);
      }
        break;

      case 2:
        if (arg1->flags & 0x1000)
      {
        if ((arg1->alpha == 0x100) && (!(format & 0x8000)))
        {
          gDPSetRenderMode(gfx++, 0x443048, 0);
        }
        else
        {
          gDPSetRenderMode(gfx++, 0x4041C8, 0);
        }
      }
      else
      {
        gDPSetRenderMode(gfx++, 0x442048, 0);
      }
        break;

    }

    if (format & 0x8000)
    {
      if (arg1->alpha == 0x100)
      {
        gDPSetCombine(gfx++, 0xFFFFFF, 0xFFFDF2F9);
      }
      else
      {
        gDPSetCombine(gfx++, 0xFF97FF, 0xFF2DFEFF);
      }
    }
    else
      if (arg1->alpha == 0x100)
    {
      if (arg1->flags & 0x02000000)
      {
        gDPSetCombine(gfx++, 0x60FEC1, 0x33FDF2F9);
      }
      else
      {
        gDPSetCombine(gfx++, 0xFFFFFF, 0xFFFCF279);
      }
    }
    else
      if (arg1->flags & 0x02000000)
    {
      gDPSetCombine(gfx++, 0x6096C1, 0x332DFEFF);
    }
    else
    {
      gDPSetCombine(gfx++, 0xFF97FF, 0xFF2CFE7F);
    }
    gDPSetPrimColor(gfx++, 0, 0, arg1->r, arg1->g, arg1->b, arg1->alpha);
    D_800F5454 = 1;
    func_80069394(&gfx, arg1);
    *arg0 = gfx;
  }
}

// register allocation: flip/dt get t1/t2/t3 swapped with hoisted temporaries; the masked residue (6) is
// only the u16 read of D_800EE314/D_800ED0F8, which retail's object relocates against the split bss labels
// D_800EE316/D_800ED0FA (same address once linked)
#define SPRITE_QUAD (fabs(arg1->rot) > 0.1f || (arg1->flags & 0xC0000) || (arg1->flags & 0x30000) == 0x30000)
#ifdef NON_MATCHING
void func_80069394(Gfx** arg0, unk69010Sprite* arg1) {
    Matrix4f mf;
    unk3AC60Struct0 pos;
    Gfx* gfx;
    s32 cms;
    s32 masks;
    s32 maskt;
    s32 x0;
    s32 x1;
    s32 s0;
    unk69010Frame* frame;
    Vtx* vtx;
    Mtx* mtx;
    f32 scaleX;
    f32 scaleY;
    f32 rowStep;
    f32 texS0;
    f32 texS1;
    s32 texT;
    s32 y0;
    s32 dir;
    s32 dt;
    s32 i;
    s32 j;
    s32 row;
    s32 flip;
    s32 cmt;
    s32 temp;

    frame = &arg1->sheet->frames[arg1->frame];
    vtx = NULL;
    scaleX = arg1->scaleX;
    scaleY = arg1->scaleY;
    x0 = 0;
    x1 = 0;
    rowStep = 0.0f;
    s0 = 0;
    gfx = *arg0;
    y0 = 0;
    if (arg1->flags & 0x2000) {
        gDPSetCycleType(gfx++, G_CYC_2CYCLE);
        gDPPipeSync(gfx++);
        gDPSetCombine(gfx++, 0x2527FF, 0x1FFC9238);
        gDPSetRenderMode(gfx++, 0x0C1841C8, 0);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, arg1->alpha);
        D_800F5448 *= 2;
        D_800EE314 >>= 1;
    }
    if ((arg1->flags & 0x30000) == 0x30000) {
        arg1->unk_2C = (f32)(arg1->unk_3C - arg1->unk_38) / (frame->width * scaleX);
        arg1->unk_30 = (f32)(arg1->unk_3E - arg1->unk_3A) / (frame->height * scaleY);
    }
    if (SPRITE_QUAD) {
        vtx = D_800F54B4;
        mtx = (Mtx*)&vtx[(D_800F5448 + 2) * 2];
        D_800F54B4 = mtx + 1;
        dir = 0;
        if (arg1->flags & 1) {
            texS0 = frame->width * 63.999;
            texS1 = 0.0f;
        } else {
            texS0 = 0.0f;
            texS1 = frame->width * 63.999;
            dir = 1;
        }
        for (i = 0; i < D_800F5448 + 1; i++) {
            if (arg1->flags & 2) {
                row = D_800F5448 - i;
                flip = 1;
            } else {
                row = i;
                flip = 0;
            }
            if (arg1->flags & 0x10000) {
                vtx[row * 2].v.ob[0] = 0;
                vtx[row * 2 + 1].v.ob[0] = (f32)(arg1->unk_3C - arg1->unk_38) / arg1->unk_2C;
                vtx[row * 2].v.ob[1] = vtx[row * 2 + 1].v.ob[1] =
                    (f32)-((i * ((arg1->unk_3E - arg1->unk_3A) - D_800ED0F8)) / D_800F5448 + flip * D_800ED0F8) / arg1->unk_30;
            } else {
                vtx[row * 2].v.ob[0] = -frame->width * scaleX * (arg1->unk_2C - 1.0f) * (dir ^ 1);
                vtx[row * 2 + 1].v.ob[0] = frame->width * scaleX;
                vtx[row * 2].v.ob[1] = vtx[row * 2 + 1].v.ob[1] = -(i * D_800EE314 + flip * D_800ED0F8) * scaleY;
            }
            vtx[i * 2].v.tc[0] = texS0;
            vtx[i * 2 + 1].v.tc[0] = texS1;
            vtx[i * 2 + 1].v.tc[1] = vtx[i * 2].v.tc[1] = (i * D_800EE314) << 7;
            if ((arg1->flags & 0xC0000) && arg1->unk_34 != 0) {
                vtx[row * 2 + 1].v.ob[0] = vtx[row * 2 + 1].v.ob[0] + vtx[row * 2 + 1].v.ob[0] * (arg1->unk_2C - 1.0f) * dir;
                vtx[i * 2].v.tc[0] = vtx[i * 2].v.tc[0] * arg1->unk_2C;
                vtx[i * 2 + 1].v.tc[0] = vtx[i * 2 + 1].v.tc[0] * arg1->unk_2C;
            }
            if ((arg1->flags & 0x300000) && arg1->unk_34 != 0) {
                vtx[row * 2].v.ob[1] = vtx[row * 2].v.ob[1] * arg1->unk_30 + frame->height * (arg1->unk_30 - 1.0f) * flip;
                vtx[row * 2 + 1].v.ob[1] = vtx[row * 2 + 1].v.ob[1] * arg1->unk_30 + frame->height * (arg1->unk_30 - 1.0f) * flip;
                vtx[i * 2].v.tc[1] = vtx[i * 2].v.tc[1] * arg1->unk_30;
                vtx[i * 2 + 1].v.tc[1] = vtx[i * 2 + 1].v.tc[1] * arg1->unk_30;
            }
            for (j = 0; j < 2; j++) {
                vtx[i * 2 + j].v.ob[2] = -1;
                vtx[i * 2 + j].v.cn[0] = 0;
                vtx[i * 2 + j].v.cn[1] = 0;
                vtx[i * 2 + j].v.cn[2] = 0;
                vtx[i * 2 + j].v.cn[3] = 0xFF;
            }
        }
        if (D_800ED0F8 != 0) {
            if (arg1->flags & 0x10000) {
                vtx[i * 2].v.ob[0] = 0;
                vtx[i * 2 + 1].v.ob[0] = (f32)(arg1->unk_3C - arg1->unk_38) / arg1->unk_2C;
                if (arg1->flags & 2) {
                    flip = 1;
                    vtx[i * 2].v.ob[1] = vtx[i * 2 + 1].v.ob[1] = 0;
                } else {
                    flip = 0;
                    vtx[i * 2].v.ob[1] = vtx[i * 2 + 1].v.ob[1] = (f32)(arg1->unk_3A - arg1->unk_3E) / arg1->unk_30;
                }
            } else {
                vtx[i * 2].v.ob[0] = -frame->width * scaleX * (arg1->unk_2C - 1.0f) * (dir ^ 1);
                vtx[i * 2 + 1].v.ob[0] = frame->width * scaleX;
                if (arg1->flags & 2) {
                    flip = 1;
                    vtx[i * 2].v.ob[1] = vtx[i * 2 + 1].v.ob[1] = 0;
                } else {
                    flip = 0;
                    vtx[i * 2].v.ob[1] = vtx[i * 2 + 1].v.ob[1] = -frame->height * scaleY;
                }
            }
            vtx[i * 2].v.tc[0] = texS0;
            vtx[i * 2 + 1].v.tc[0] = texS1;
            vtx[i * 2].v.tc[1] = frame->height << 7;
            vtx[i * 2 + 1].v.tc[1] = frame->height << 7;
            if ((arg1->flags & 0xC0000) && arg1->unk_34 != 0) {
                vtx[i * 2 + 1].v.ob[0] = vtx[i * 2 + 1].v.ob[0] + vtx[i * 2 + 1].v.ob[0] * (arg1->unk_2C - 1.0f) * dir;
                vtx[i * 2].v.tc[0] = vtx[i * 2].v.tc[0] * arg1->unk_2C;
                vtx[i * 2 + 1].v.tc[0] = vtx[i * 2 + 1].v.tc[0] * arg1->unk_2C;
            }
            if ((arg1->flags & 0x300000) && arg1->unk_34 != 0) {
                vtx[i * 2].v.ob[1] = vtx[i * 2].v.ob[1] * arg1->unk_30 + frame->height * (arg1->unk_30 - 1.0f) * flip;
                vtx[i * 2 + 1].v.ob[1] = vtx[i * 2 + 1].v.ob[1] * arg1->unk_30 + frame->height * (arg1->unk_30 - 1.0f) * flip;
                vtx[i * 2].v.tc[1] = vtx[i * 2].v.tc[1] * arg1->unk_30;
                vtx[i * 2 + 1].v.tc[1] = vtx[i * 2 + 1].v.tc[1] * arg1->unk_30;
            }
            for (j = 0; j < 2; j++) {
                vtx[i * 2 + j].v.ob[2] = -1;
                vtx[i * 2 + j].v.cn[0] = 0;
                vtx[i * 2 + j].v.cn[1] = 0;
                vtx[i * 2 + j].v.cn[2] = 0;
                vtx[i * 2 + j].v.cn[3] = 0xFF;
            }
        }
        if (arg1->flags & 0x10000) {
            pos.unk_00 = (arg1->unk_38 - arg1->unk_3C) * frame->centerX / frame->width;
            pos.unk_04 = (arg1->unk_3E - arg1->unk_3A) * frame->centerY / frame->height;
            arg1->x = arg1->unk_38 + (arg1->unk_3C - arg1->unk_38) * frame->centerX / frame->width;
            arg1->y = arg1->unk_3A + (arg1->unk_3E - arg1->unk_3A) * frame->centerY / frame->height;
        } else {
            pos.unk_00 = -frame->centerX * scaleX;
            pos.unk_04 = frame->centerY * scaleY;
        }
        func_8003B0AC((unk3AC60Struct1*)mf, arg1->x - 160, 120 - arg1->y, arg1->rot);
        guMtxIdent(mtx);
        func_8003B190(&pos, (unk3AC60Struct1*)mf, (unk3AC60Struct2*)mtx);
        gSPMatrix(gfx++, osVirtualToPhysical(mtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    } else {
        if (arg1->flags & 0x10000) {
            x0 = arg1->unk_38;
            x1 = arg1->unk_3C;
            y0 = arg1->unk_3A;
            scaleX = (f32)(x1 - x0) / frame->width;
            temp = arg1->unk_3E - y0;
            scaleY = (f32)temp / frame->height;
            rowStep = temp / D_800F5448;
        } else {
            x0 = arg1->x - frame->centerX * scaleX;
            x1 = x0 + frame->width * scaleX;
            y0 = arg1->y - frame->centerY * scaleY;
            rowStep = D_800EE314 * scaleY;
        }
        dir = -1;
        if (arg1->flags & 1) {
            s0 = frame->width;
        } else {
            s0 = 0;
            dir = 1;
        }
    }
    if (arg1->flags & 0xC0000) {
        masks = arg1->unk_34;
        cms = arg1->flags >> 18;
        cms--;
    } else {
        masks = 0;
        cms = 0;
    }
    if (arg1->flags & 0x300000) {
        maskt = arg1->unk_36;
        cmt = (arg1->flags >> 20) - 1;
    } else {
        maskt = 0;
        cmt = 0;
    }
    for (i = 0; i < D_800F5448; i++) {
        func_8006B014(&gfx, arg1, D_800EE314, 0, i * D_800EE314, frame->width - 1, (i + 1) * D_800EE314 - 1, cms, cmt, masks, maskt);
        if (SPRITE_QUAD) {
            gSPVertex(gfx++, &vtx[i * 2], 4, 0);
            gSP2Triangles(gfx++, 0, 2, 3, 0, 0, 3, 1, 0);
        } else {
            dt = -1;
            if (arg1->flags & 2) {
                row = D_800F5448 - 1;
                row -= i;
                flip = 1;
                texT = (i + 1) * (rowStep / scaleY) - 1.0f;
            } else {
                row = i;
                dt = 1;
                flip = 0;
                texT = row * (rowStep / scaleY);
            }
            gSPScisTextureRectangle(gfx++, x0 * 4, (s16)(s32)(y0 + row * rowStep + flip * D_800ED0F8) << 2, x1 * 4,
                                    (s32)(y0 + (row + 1) * rowStep + flip * D_800ED0F8) * 4, 0, s0 << 5, texT << 5,
                                    (s32)(D_800F5454 / scaleX * 1024.0f * dir), (s32)(1.0f / scaleY * 1024.0f * dt));
        }
    }
    if (D_800ED0F8 != 0) {
        func_8006B014(&gfx, arg1, D_800ED0F8, 0, i * D_800EE314, frame->width - 1, frame->height - 1, cms, cmt, masks, maskt);
        if (SPRITE_QUAD) {
            gSPVertex(gfx++, &vtx[i * 2], 4, 0);
            gSP2Triangles(gfx++, 0, 2, 3, 0, 0, 3, 1, 0);
        } else {
            dt = -1;
            if (arg1->flags & 2) {
                texT = frame->height - 1;
                gSPScisTextureRectangle(gfx++, x0 * 4, (s16)y0 << 2, x1 * 4, (s32)(y0 + D_800ED0F8 * scaleY) * 4, 0, s0 << 5,
                                        texT << 5, (s32)(D_800F5454 / scaleX * 1024.0f * dir),
                                        (s32)(1.0f / scaleY * 1024.0f * dt));
            } else {
                row = i;
                dt = 1;
                texT = row * (rowStep / scaleY);
                gSPScisTextureRectangle(gfx++, x0 * 4, (s16)(s32)(y0 + row * rowStep) << 2, x1 * 4,
                                        (s32)(y0 + frame->height * scaleY) * 4, 0, s0 << 5, texT << 5, (s32)(D_800F5454 / scaleX * 1024.0f * dir),
                                        (s32)(1.0f / scaleY * 1024.0f * dt));
            }
        }
    }
    gDPPipeSync(gfx++);
    *arg0 = gfx;
}
#else
INCLUDE_ASM("asm/nonmatchings/69010", func_80069394);
#endif

void func_8006B014(Gfx** arg0, unk69010Sprite* arg1, u16 arg2, u16 arg3, u16 arg4, u16 arg5, u16 arg6, u16 arg7, u16 arg8, u16 arg9, u16 arg10) {
    unk69010Frame* frame = &arg1->sheet->frames[arg1->frame];
    Gfx* gfx = *arg0;

    switch (D_800F2A74) {
        case 0:
            gDPLoadTextureTile_4b(gfx++, frame->timg, D_800F3B84, frame->width, frame->height, arg3, arg4, arg5, arg6, 0, arg7, arg8, arg9, arg10, 0, 0);
            break;
        case 1:
            func_8003A828(&gfx, frame->timg, D_800F3B84, frame->width, arg2, arg3, arg4, arg5, arg6, 0, arg7, arg8, arg9, arg10, 0, 0);
            break;
        case 2:
            func_8003A060(&gfx, frame->timg, D_800F3B84, D_800F5444, frame->width, frame->height, arg3, arg4, arg5, arg6, 0, arg7, arg8, arg9, arg10, 0, 0);
            break;
        case 3:
            func_8003A4EC(&gfx, frame->timg, D_800F3B84, D_800F5444, frame->width, arg2, arg3, arg4, arg5, arg6, 0, arg7, arg8, arg9, arg10, 0, 0);
            break;
    }
    if (arg1->flags & 0x2000) {
        func_8006B464(&gfx, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
    }
    *arg0 = gfx;
}

void func_8006B464(Gfx** arg0, unk69010Sprite* arg1, u16 arg2, u16 arg3, u16 arg4, u16 arg5, u16 arg6, u16 arg7, u16 arg8, u16 arg9, u16 arg10) {
    unk69010Frame* frame = &arg1->sheet->frames[arg1->frame];
    Gfx* gfx = *arg0;

    switch (D_800F2A74) {
        case 0:
            gDPLoadMultiTile_4b(gfx++, frame->timg, D_800C5B50, 1, D_800F3B84, frame->width, frame->height, arg3, arg4, arg5, arg6, 0, arg7, arg8, arg9, arg10, 0, 0);
            break;
        case 1:
            func_8003AE00(&gfx, frame->timg, D_800F3B84, frame->width, arg2, arg3, arg4, arg5, arg6, 0, arg7, arg8, arg9, arg10, 0, 0, 1, D_800C5B50);
            break;
        case 2:
            func_8003A28C(&gfx, frame->timg, D_800F3B84, D_800F5444, frame->width, frame->height, arg3, arg4, arg5, arg6, 0, arg7, arg8, arg9, arg10, 0, 0, 1, D_800C5B50);
            break;
        case 3:
            func_8003AA98(&gfx, frame->timg, D_800F3B84, D_800F5444, frame->width, arg2, arg3, arg4, arg5, arg6, 0, arg7, arg8, arg9, arg10, 0, 0, 1, D_800C5B50);
            break;
    }
    *arg0 = gfx;
}
