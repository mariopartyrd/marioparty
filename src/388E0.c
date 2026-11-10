#include "common.h"
#include "engine/mallocblock.h"
extern u16 D_800C41B0[]; /* 34D80.c */
unk2C0C0Struct70 D_800C41D0 = {
    "0123456789ABCDE", 0x00, 0x02, 0x04, 0x04, { 0xFF, 0 }, 0, 0, { 0, 0 }, (u8*)D_800C41B0, (struct unk2C0C0StructC0*)-1, NULL,
};



typedef struct unk388E0Struct40 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ char unk_08[2];
    /* 0x0A */ u8 unk_0A;
    /* 0x0B */ u8 unk_0B;
} unk388E0Struct40; //sizeof 0xC

typedef struct unk388E0Struct44 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
} unk388E0Struct44; //sizeof 4

typedef struct unk388E0Struct80 {
    /* 0x00 */ char unk_00[0x18];
    /* 0x18 */ u8 unk_18;
    /* 0x19 */ char unk_19;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ char unk_1E[2];
    /* 0x20 */ unk2C0C0StructC0* unk_20;
    /* 0x24 */ u16* unk_24;
} unk388E0Struct80; //sizeof 0x28

typedef struct unk388E0StructCC {
    /* 0x00 */ void* unk_00;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
} unk388E0StructCC; //sizeof 0xC

typedef struct unk388E0StructC4 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ char unk_07;
} unk388E0StructC4; //sizeof 8

typedef struct unk388E0StructC8 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ unk388E0StructC4* unk_04;
} unk388E0StructC8; //sizeof 8

typedef struct unk388E0StructC0 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ char unk_0A[2];
    /* 0x0C */ unk388E0StructCC* unk_0C;
    /* 0x10 */ unk388E0StructC8* unk_10;
    /* 0x14 */ u16* unk_14;
} unk388E0StructC0; //sizeof 0x18

u8* func_8001C2E8(s32, u8*, u8*);
u8* func_8001C378(u8*);
s16 func_8001CBD8(unk2C0C0StructC0*, u8*, s16);
s16 func_8001CD00(u8*);
unk2C0C0Struct70* func_80038194(unk2C0C0StructC0*, u8*);
void func_80038254(u8*, unk2C0C0StructC0*, unk2C0C0Struct70*);
void func_800384FC(unk2C0C0StructC0*);
void func_80038A2C(void);
void func_80039020(void);
void func_80038888(u8*, unk2C0C0StructC0*, unk388E0Struct80*);
void func_800238F0(s16);
void func_80038864(unk388E0Struct80*);
unk388E0Struct80* func_80038720(unk2C0C0StructC0*, s16);
void func_80039A4C(s16);
void func_800399F0(s16);
s32 func_8009B850(unk2C0C0Struct70*, u8*);
void func_8009B960(void*, void*);

extern s8 D_800ED565;
extern unk388E0Struct80* D_800ED730;
extern unk388E0Struct40* D_800F3708;
extern unk2C0C0Struct70* D_800F37AC;
extern unk388E0StructC0* D_800F3F40;

void func_80037CE0(void) {
    s16 i;

    D_800F37AC = func_80023668(128 * sizeof(unk2C0C0Struct70));
    D_800ED730 = func_80023668(128 * sizeof(unk388E0Struct80));

    for (i = 0; i < 128; i++) {
        D_800F37AC[i].unk_20 = 0;
    }

    for (i = 0; i < 128; i++) {
        D_800ED730[i].unk_1C = 0;
    }

    D_800ED565 = 0;
    func_80038A2C();
}

void func_80037DA0(unk2C0C0StructC0* arg0) {
    unk2C0C0Struct70* var_s0;
    s16 temp_s4;
    u8* var_s1;
    u8 sp10[24];
    s16 i;

    func_800384FC(arg0);

    for (var_s1 = arg0->unk_3C; var_s1 < (u8*) arg0->unk_38;) {
        var_s1 = func_8001C2E8(0x424D5031, var_s1, arg0->unk_38);
        if (var_s1 == NULL) {
            break;
        }

        temp_s4 = func_8001CBD8(arg0, sp10, (var_s1[8] << 8) + var_s1[9]);
        for (i = 0; i < 128; i++) {
            if (D_800F37AC[i].unk_20 == temp_s4 && func_8009B850(&D_800F37AC[i], sp10) == 0) {
                break;
            }
        }

        if (i == 128) {
            for (i = 0; i < 128; i++) {
                if (D_800F37AC[i].unk_20 == 0) {
                    break;
                }
            }
            if (i == 128) {
                break;
            }
            var_s0 = &D_800F37AC[i];
            var_s0->unk_20 = temp_s4;
            func_8009B960(var_s0, sp10);
            var_s0->unk_28 = arg0;
            func_80038254(var_s1, arg0, var_s0);
        } else {
            var_s0 = &D_800F37AC[i];
            if (D_800ED565 & 2) {
                func_80023888(var_s0->unk_24);
                var_s0->unk_28 = arg0;
                func_80038254(var_s1, arg0, var_s0);
            }
        }

        var_s1 = func_8001C378(var_s1 + 4);
    }
}

void func_80037FA0(unk2C0C0StructC0* arg0) {
    unk2C0C0Struct70* tex;
    unk2C0C0StructC0* m;
    s16 i;
    s16 j;
    s16 k;

    if (arg0->unk_A4 != NULL) {
        for (i = 0; i < arg0->unk_6C; i++) {
            tex = arg0->unk_A4[i].unk_0C;
            if (tex->unk_20 == 0) {
                continue;
            }
            for (j = 0; j < 128; j++) {
                m = D_800F2B7C[j].unk_6C;
                if (m == NULL) {
                    continue;
                }
                if (((u8) D_800F2B7C[j].unk_00 != 0) | (arg0 == m)) {
                    continue;
                }
                if (m->unk_A4 == NULL) {
                    continue;
                }
                for (k = 0; k < m->unk_6C; k++) {
                    if (m->unk_A4[k].unk_0C == tex) {
                        break;
                    }
                }
                if (k != m->unk_6C) {
                    break;
                }
            }
            if (j == 128) {
                tex->unk_20 = 0;
                tex->unk_28 = NULL;
                if (tex->unk_18 == 2) {
                    func_80038864((unk388E0Struct80*) tex->unk_2C);
                }
                func_80023888(tex->unk_24);
            }
        }
    }
}

unk2C0C0Struct70* func_8003813C(unk2C0C0StructC0* arg0, s16 arg1) {
    u8 sp10[24];

    func_8001CBD8(arg0, sp10, arg1);
    return func_80038194(arg0, sp10);
}


void func_80038178(unk2C0C0StructC0* arg0, u8* arg1) {
    func_80038194(arg0, arg1);
}
unk2C0C0Struct70* func_80038194(unk2C0C0StructC0* arg0, u8* arg1) {
    u16 temp_s2;
    u16 i;

    temp_s2 = func_8001CD00(arg1);

    for (i = 0; i < 128; i++) {
        if (D_800F37AC[i].unk_20 != 0 && D_800F37AC[i].unk_20 == temp_s2
            && func_8009B850(&D_800F37AC[i], arg1) == 0) {
            break;
        }
    }

    if (i == 128) {
        return NULL;
    }

    return &D_800F37AC[i];
}

// decomp-permuter
void func_80038254(u8 *arg0, unk2C0C0StructC0 *arg1, unk2C0C0Struct70 *arg2)
{
  u16 bpp;
  u16 size;
  u16 i;
  u16 c;
  u8 *dst;
  arg0 += 0xB;
  arg2->unk_1A = arg0[3];
  arg2->unk_1B = arg0[5];
  if (arg0[0] == 0x28)
  {
    arg2->unk_18 = 2;
    arg2->unk_2C = (unk2C0C0Struct60 *) func_80038720(arg1, (arg0[6] << 8) + arg0[7]);
    arg2->unk_1E = (arg0[8] << 8) + arg0[9];
    arg2->unk_19 = 1;
    bpp = 2;
    if (arg2->unk_2C->unk_1A < 0x11)
    {
      bpp = 1;
    }
    arg0 += 4;
  }
  else
  {
    switch (arg0[1])
    {
      case 8:
        arg2->unk_19 = (short) 1;
        bpp = 2;
        break;

      case 16:
        arg2->unk_19 = 2;
        bpp = 4;
        break;

      case 4:
        arg2->unk_19 = 0;
        bpp = 1;
        break;

      case 32:
        arg2->unk_19 = 3;
        bpp = 8;
        break;

      default:
        arg2->unk_19 = 2;
        bpp = 6;
        break;

    }

    switch (arg0[0])
    {
      case 0x26:
        arg2->unk_18 = 0;
        break;

      case 0x27:
        arg2->unk_18 = 0;
        break;

      case 0x25:
        arg2->unk_18 = 3;
        break;

      default:
        arg2->unk_18 = 4;
        break;

    }

  }
  size = (arg0[8] << 8) + arg0[9];
  if (bpp != 6)
  {
    if (((arg2->unk_18 == 2) && (size > 0x800)) || (size > 0x1000))
    {
      arg2->unk_1B = 0x10;
      arg2->unk_1A = 0x10;
    }
    arg2->unk_24 = func_80023684(size, 15000);
    func_80023A38(arg0 + 0xA, arg2->unk_24, size);
  }
  else
  {
    size = (size / 3) * 2;
    if (size > 0x1000)
    {
      arg2->unk_1B = 0x10;
      arg2->unk_1A = 0x10;
    }
    dst = (arg2->unk_24 = func_80023684(size, 15000));
    arg0 += 0xA;
    for (i = 0; i < size; i += 2)
    {
      if (arg0)
      {
        c = (((((*arg0) & 0xF8) << 8) + (((*arg0) & 0xF8) << 3)) + (((*arg0) & 0xF8) >> 2)) + 1;
        arg0 += 3;
        *(dst++) = c >> 8;
        *(dst++) = c;
      }
      else
      {
        c = (((((*arg0) & 0xF8) << 8) + (((*arg0) & 0xF8) << 3)) + (((*arg0) & 0xF8) >> 2)) + 1;
        arg0 += 3;
        *(dst++) = c >> 8;
        *(dst++) = c;
      }
    }

  }
}
void func_800384FC(unk2C0C0StructC0* arg0) {
    unk388E0Struct80* var_s0;
    s16 temp_s4;
    u8* var_s1;
    u8 sp10[24];
    s16 i;

    for (var_s1 = arg0->unk_3C; var_s1 < (u8*) arg0->unk_38;) {
        var_s1 = func_8001C2E8(0x50414C31, var_s1, arg0->unk_38);
        if (var_s1 == NULL) {
            break;
        }

        temp_s4 = func_8001CBD8(arg0, sp10, (var_s1[8] << 8) + var_s1[9]);
        for (i = 0; i < 128; i++) {
            if (D_800ED730[i].unk_1C == temp_s4 && func_8009B850((unk2C0C0Struct70*) &D_800ED730[i], sp10) == 0) {
                break;
            }
        }

        if (i == 128) {
            for (i = 0; i < 128; i++) {
                if (D_800ED730[i].unk_1C == 0) {
                    break;
                }
            }
            if (i == 128) {
                break;
            }
            var_s0 = &D_800ED730[i];
            var_s0->unk_1C = temp_s4;
            func_8009B960(var_s0, sp10);
            var_s0->unk_20 = arg0;
            var_s0->unk_18 = 1;
            func_80038888(var_s1, arg0, var_s0);
        } else {
            var_s0 = &D_800ED730[i];
            if (D_800ED565 & 2) {
                func_80023888(var_s0->unk_24);
                var_s0->unk_20 = arg0;
                func_80038888(var_s1, arg0, var_s0);
            }
            var_s0->unk_18++;
        }

        var_s1 = func_8001C378(var_s1 + 4);
    }
}

unk388E0Struct80* func_80038720(unk2C0C0StructC0* arg0, s16 arg1) {
    u8 sp10[24];
    u16 id;
    u16 i;

    id = func_8001CBD8(arg0, sp10, arg1);

    for (i = 0; i < 128; i++) {
        if ((u16) D_800ED730[i].unk_1C != 0 && (u16) D_800ED730[i].unk_1C == id
            && func_8009B850((unk2C0C0Struct70*) &D_800ED730[i], sp10) == 0) {
            break;
        }
    }

    if (i == 128) {
        return NULL;
    }

    return &D_800ED730[i];
}
void func_800387DC(unk2C0C0StructC0* arg0) {
    s16 i;

    for (i = 0; i < 128; i++) {
        if (D_800ED730[i].unk_1C != 0 && D_800ED730[i].unk_20 == arg0) {
            func_80038864(&D_800ED730[i]);
        }
    }
}
void func_80038864(unk388E0Struct80* arg0) {
    arg0->unk_1C = 0;
    arg0->unk_20 = NULL;
    func_80023888(arg0->unk_24);
}
// if (a >= 0x80) c++ is if-converted to srl/addu, src pointer folded into offsets (masked 10)
#ifdef NON_MATCHING
void func_80038888(u8* arg0, unk2C0C0StructC0* arg1, unk388E0Struct80* arg2) {
    u8* src;
    s16 count;
    s16 i;
    u32 c;
    u16* dst;
    u16* tbl;
    u8* col;

    src = arg0 + 0xA;
    count = (src[0] << 8) + src[1];
    arg2->unk_24 = func_80023684(count * 2, 15000);
    arg2->unk_1A = count;
    src += 2;
    tbl = arg2->unk_24;
    for (i = 0; i < count; i++) {
        dst = &tbl[i];
        col = &src[i * 4];
        c = ((col[0] & 0xF8) << 8) + ((col[1] & 0xF8) << 3) + ((col[2] & 0xF8) >> 2);
        if (col[3] >= 0x80) {
            *dst = c + 1;
        } else {
            *dst = c;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/388E0", func_80038888);
#endif

void func_8003897C(unk2C0C0Struct70* arg0) {
    s16 i;
    s16 j;
    unk2C0C0StructC0* m;

    for (i = 0; i < 128; i++) {
        if (D_800F2B7C[i].unk_6C != NULL) {
            m = D_800F2B7C[i].unk_6C;
            for (j = 0; j < m->unk_6C; j++) {
                if (m->unk_A4[j].unk_0C == arg0) {
                    m->unk_A4[j].unk_0C = &D_800C41D0;
                }
            }
        }
    }
}
void func_80038A2C(void) {
    s16 i;

    D_800F3708 = func_80023668(128 * sizeof(unk388E0Struct40));

    for (i = 0; i < 128; i++) {
        D_800F3708[i].unk_00 = -1;
    }

    func_80039020();
}

s16 func_80038A9C(unk2C0C0StructC0* arg0, void* arg1, s32 arg2, char* arg3) {
    unk2C0C0Struct70* tex;
    s16 id;
    s16 i;
    s16 slot;
    s16 j;

    id = func_8001CD00((u8*) arg3);
    for (i = 0; i < 128; i++) {
        if (D_800F37AC[i].unk_20 == id) {
            break;
        }
    }
    if (i == 128) {
        return -1;
    }

    for (slot = 0; slot < 128; slot++) {
        if (D_800F3708[slot].unk_00 == -1) {
            break;
        }
    }
    if (slot == 128) {
        return -1;
    }

    D_800F3708[slot].unk_00 = func_80039084(arg1);
    D_800F3708[slot].unk_04 = arg2;
    D_800F3708[slot].unk_02 = 0;
    D_800F3708[slot].unk_06 = 0;
    D_800F3708[slot].unk_0B = 0x10;
    D_800F3708[slot].unk_0A = 0;
    D_800F3F40[D_800F3708[slot].unk_00].unk_08 = 1;
    tex = &D_800F37AC[i];
    if (arg0 != (unk2C0C0StructC0*) -1) {
        for (i = 0; i < arg0->unk_6C; i++) {
            if (arg0->unk_A4[i].unk_0C == tex) {
                arg0->unk_A4[i].unk_09 = slot;
            }
        }
    } else {
        for (j = 0; j < 128; j++) {
            if (D_800F2B7C[j].unk_6C != NULL && (u8) D_800F2B7C[j].unk_00 == 0) {
                arg0 = D_800F2B7C[j].unk_6C;
                for (i = 0; i < arg0->unk_6C; i++) {
                    if (arg0->unk_A4[i].unk_0C == tex) {
                        arg0->unk_A4[i].unk_09 = slot;
                    }
                }
            }
        }
    }
    return slot;
}

s16 func_80038D5C(unk2C0C0StructC0* arg0, u16 arg1, s16 arg2, char* arg3) {
    unk2C0C0Struct70* tex;
    unk388E0Struct40* p;
    s16 id;
    s16 i;
    s16 slot;
    s16 j;

    id = func_8001CD00((u8*) arg3);
    for (i = 0; i < 128; i++) {
        if (D_800F37AC[i].unk_20 == id) {
            break;
        }
    }
    if (i == 128) {
        osSyncPrintf("Can't Find TextureName! LinkAnimMAn\n");
        return -1;
    }

    for (slot = 0; slot < 128; slot++) {
        if (D_800F3708[slot].unk_00 == -1) {
            break;
        }
    }
    if (slot == 128) {
        osSyncPrintf("Anime Link Over!\n");
        return -1;
    }

    p = &D_800F3708[slot];
    p->unk_00 = D_800F3708[arg1].unk_00;
    p->unk_04 = arg2;
    p->unk_0A = 0;
    p->unk_06 = 0;
    p->unk_02 = 0;
    p->unk_0B = 0x10;
    D_800F3F40[p->unk_00].unk_08++;
    tex = &D_800F37AC[i];
    if (arg0 != (unk2C0C0StructC0*) -1) {
        for (i = 0; i < arg0->unk_6C; i++) {
            if (arg0->unk_A4[i].unk_0C == tex) {
                arg0->unk_A4[i].unk_09 = slot;
            }
        }
    } else {
        for (j = 0; j < 128; j++) {
            if (D_800F2B7C[j].unk_6C != NULL && (u8) D_800F2B7C[j].unk_00 == 0) {
                arg0 = D_800F2B7C[j].unk_6C;
                for (i = 0; i < arg0->unk_6C; i++) {
                    if (arg0->unk_A4[i].unk_0C == tex) {
                        arg0->unk_A4[i].unk_09 = slot;
                    }
                }
            }
        }
    }
    return slot;
}

void func_80039020(void) {
    s16 i;

    D_800F3F40 = func_80023668(32 * sizeof(unk388E0StructC0));

    for (i = 0; i < 32; i++) {
        D_800F3F40[i].unk_0C = 0;
    }
}

// register allocation; bpp < 9 compiles sltiu not slti (masked 16)
#ifdef NON_MATCHING
s16 func_80039084(void* arg) {
    u8* arg0 = arg;
    unk388E0StructC0* spr;
    s16 w;
    s16 h;
    unk388E0StructCC* fr;
    unk388E0StructC4* af;
    u8* p;
    u8* q;
    u8* data;
    s16 nframes;
    u16 bpp;
    s16 slot;
    s16 i;
    s16 j;
    s16 n;
    s16 t;
    s16 total;
    s16 npal;

    for (slot = 0; slot < 32; slot++) {
        if (D_800F3F40[slot].unk_0C == NULL) {
            break;
        }
    }
    if (slot == 32) {
        return -1;
    }

    spr = &D_800F3F40[slot];
    nframes = (arg0[0x10] << 8) + arg0[0x11];
    spr->unk_00 = nframes;
    spr->unk_0C = func_80023684(nframes * sizeof(*spr->unk_0C), slot + 20000);
    p = arg0 + (arg0[1] << 16) + (arg0[2] << 8) + arg0[3];
    spr->unk_06 = (arg0[0x18] << 8) + arg0[0x19];
    bpp = spr->unk_06 & 0xFF;
    for (i = 0; i < nframes; i++) {
        fr = &spr->unk_0C[i];
        data = arg0 + (p[1] << 16) + (p[2] << 8) + p[3];
        w = fr->unk_04 = (p[4] << 8) + p[5];
        h = fr->unk_06 = (p[6] << 8) + p[7];
        fr->unk_08 = (p[8] << 8) + p[9];
        fr->unk_0A = (p[10] << 8) + p[11];
        fr->unk_00 = func_80023684(w * h * bpp / 8, slot + 20000);
        func_80023A38(data, fr->unk_00, w * h * bpp / 8);
        p += 12;
    }

    spr->unk_02 = n = (arg0[0x12] << 8) + arg0[0x13];
    if (n != 0) {
        spr->unk_10 = func_80023684(n * sizeof(*spr->unk_10), slot + 20000);
        p = arg0 + (arg0[5] << 16) + (arg0[6] << 8) + arg0[7];
        for (i = 0; i < n; i++) {
            q = arg0 + (p[i * 4 + 1] << 16) + (p[i * 4 + 2] << 8) + p[i * 4 + 3];
            spr->unk_10[i].unk_00 = t = (q[0] << 8) + q[1];
            spr->unk_10[i].unk_04 = func_80023684(t * sizeof(*spr->unk_10->unk_04), slot + 20000);
            q += 2;
            total = 0;
            for (j = 0; j < t; j++) {
                af = &spr->unk_10[i].unk_04[j];
                af->unk_00 = (q[0] << 8) + q[1];
                af->unk_02 = w = (q[2] << 8) + q[3];
                if (w > 0) {
                    total += w;
                }
                af->unk_04 = q[4];
                af->unk_05 = q[5];
                af->unk_06 = q[6];
                q += 7;
            }
            spr->unk_10[i].unk_02 = total;
        }
    } else {
        spr->unk_02 = 1;
        spr->unk_10 = func_80023684(sizeof(*spr->unk_10), slot + 20000);
        spr->unk_10->unk_00 = nframes;
        spr->unk_10->unk_04 = func_80023684(nframes * sizeof(*spr->unk_10->unk_04), slot + 20000);
        for (j = 0; j < nframes; j++) {
            af = &spr->unk_10->unk_04[j];
            af->unk_00 = j;
            af->unk_02 = 1;
            af->unk_05 = 0;
            af->unk_04 = 0;
            af->unk_06 = 0;
        }
        spr->unk_10->unk_02 = nframes;
    }

    npal = arg0[0x1A];
    spr->unk_04 = npal;
    p = arg0 + (arg0[0xD] << 16) + (arg0[0xE] << 8) + arg0[0xF];
    if ((s32) bpp < 9) {
        spr->unk_14 = func_80023684(npal * 2, slot + 20000);
        func_80023A38(p, spr->unk_14, npal * 2);
    } else {
        spr->unk_14 = NULL;
    }
    return slot;
}
#else
INCLUDE_ASM("asm/nonmatchings/388E0", func_80039084);
#endif

void func_80039644(s16 arg0, u8 arg1, u8 arg2) {
    unk388E0Struct40* p = &D_800F3708[arg0];

    p->unk_0A = (p->unk_0A & ~arg1) | arg2;
}
void func_8003967C(s16 arg0, u8 arg1) {
    unk388E0Struct40* p = &D_800F3708[arg0];

    p->unk_04 = arg1;
    p->unk_02 = 0;
    p->unk_06 = 0;
}
// decomp-permuter
void func_800396B0(s16 arg0, s32 arg1)
{
  unk388E0Struct40 *new_var2;
  unk388E0StructC8 *new_var;
  unk388E0Struct40 *p = &D_800F3708[arg0];
  new_var2 = p;
  new_var2->unk_02 = (u8) arg1;
  new_var = p->unk_04 + D_800F3F40[new_var2->unk_00].unk_10;
  if (new_var->unk_00 <= ((u8) arg1))
  {
    p->unk_02 = ((u8) arg1) % new_var->unk_00;
  }
  p->unk_06 = 0;
  p->unk_0B = 0x10;
}
// decomp-permuter
u8 func_80039758(s16 arg0)
{
  unk388E0StructC8 *new_var;
  unk388E0Struct40 *p = &D_800F3708[arg0];
  new_var = &D_800F3F40[p->unk_00].unk_10[p->unk_04];
  return (*new_var).unk_00;
}
void func_800397AC(u16 arg0) {
    unk388E0Struct40* p;
    unk388E0StructC8* bank;
    s16 i;
    s16 k;

    for (i = 0; i < 128; i++) {
        if (D_800F3708[i].unk_00 == -1) {
            continue;
        }
        p = &D_800F3708[i];
        if (p->unk_0A & 1) {
            continue;
        }
        bank = &D_800F3F40[p->unk_00].unk_10[p->unk_04];
        for (k = 0; k < arg0; k++) {
            p->unk_06 += p->unk_0B;
            while (p->unk_06 >= bank->unk_04[p->unk_02].unk_02 * 16) {
                p->unk_06 -= bank->unk_04[p->unk_02].unk_02 * 16;
                p->unk_02++;
                if (bank->unk_00 <= p->unk_02) {
                    if ((D_800F3708[i].unk_0A & 2) || bank->unk_04[p->unk_02 - 1].unk_02 != -1) {
                        p->unk_02--;
                    } else {
                        p->unk_02 = 0;
                    }
                }
            }
        }
    }
}

void func_80039970(s16 arg0, f32 arg1) {
    D_800F3708[arg0].unk_0B = arg1 * 16.0f;
}
void func_800399F0(s16 arg0) {
    unk388E0Struct40* p = &D_800F3708[arg0];

    if (p->unk_00 != -1) {
        func_80039A4C(p->unk_00);
        p->unk_00 = -1;
    }
}
void func_80039A4C(s16 arg0) {
    if (D_800F3F40[arg0].unk_0C != 0) {
        if (--D_800F3F40[arg0].unk_08 == 0) {
            func_800238F0(arg0 + 20000);
            D_800F3F40[arg0].unk_0C = 0;
        }
    }
}
void func_80039ACC(s16 arg0) {
    func_800399F0(arg0);
}
void func_80039AEC(void) {
    s16 i;

    for (i = 0; i < 32; i++) {
        if (D_800F3F40[i].unk_0C != NULL) {
            D_800F3F40[i].unk_0C = NULL;
            func_800238F0(i + 20000);
        }
    }

    for (i = 0; i < 128; i++) {
        D_800F3708[i].unk_00 = -1;
    }
}

void func_80039BAC(void) {
    s16 i;

    for (i = 0; i < 128; i++) {
        D_800F37AC[i].unk_20 = 0;
    }

    for (i = 0; i < 128; i++) {
        D_800ED730[i].unk_1C = 0;
    }

    func_800238F0(15000);
}

void func_80039C48(char* arg0, void* arg1) {
    unk388E0Struct44* out = arg1;
    u16 id;
    u16 i;

    id = func_8001CD00((u8*) arg0);

    for (i = 0; i < 128; i++) {
        if (D_800F37AC[i].unk_20 == id && func_8009B850(&D_800F37AC[i], (u8*) arg0) == 0) {
            break;
        }
    }

    if (i == 128) {
        return;
    }
    out->unk_00 = D_800F37AC[i].unk_1A;
    out->unk_02 = D_800F37AC[i].unk_1B;
}

// register allocation, sprite index order (masked 9)
#ifdef NON_MATCHING
void func_80039D10(unk2C0C0StructC0* arg0) {
    unk388E0Struct40* p;
    unk2C0C0Struct70* tex;
    s16 frame;
    s16 i;
    s32 idx;

    for (i = 0; i < arg0->unk_6C; i++) {
        if (arg0->unk_A4[i].unk_03 == -1) {
            continue;
        }
        idx = arg0->unk_A4[i].unk_09;
        if (!(idx & 0x80)) {
            p = &D_800F3708[idx];
            if (p->unk_00 != -1) {
                frame = D_800F3F40[p->unk_00].unk_10[p->unk_04].unk_04[p->unk_02].unk_00;
                if (frame != -1) {
                    gSPSegment(D_800F37DC++, arg0->unk_A4[i].unk_03,
                               osVirtualToPhysical(D_800F3F40[p->unk_00].unk_0C[frame].unk_00));
                    if (D_800F3F40[p->unk_00].unk_14 != NULL) {
                        gSPSegment(D_800F37DC++, arg0->unk_A4[i].unk_04,
                                   osVirtualToPhysical(D_800F3F40[p->unk_00].unk_14));
                    }
                    continue;
                }
            }
        }
        tex = arg0->unk_A4[i].unk_0C;
        gSPSegment(D_800F37DC++, arg0->unk_A4[i].unk_03, osVirtualToPhysical(tex->unk_24));
        if (tex->unk_2C != NULL) {
            gSPSegment(D_800F37DC++, arg0->unk_A4[i].unk_04,
                       osVirtualToPhysical(((unk388E0Struct80*) tex->unk_2C)->unk_24));
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/388E0", func_80039D10);
#endif

void func_80039F9C(unk2C0C0StructC0* arg0) {
    s16 i;

    for (i = 0; i < arg0->unk_6C; i++) {
        if (arg0->unk_A4[i].unk_03 != -1) {
            arg0->unk_A4[i].unk_09 |= 0x80;
        }
    }
}

void func_80039FFC(unk2C0C0StructC0* arg0) {
    s16 i;

    for (i = 0; i < arg0->unk_6C; i++) {
        if (arg0->unk_A4[i].unk_03 != -1) {
            arg0->unk_A4[i].unk_09 &= 0x7F;
        }
    }
}
