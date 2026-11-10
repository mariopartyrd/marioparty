#include "common.h"
#include "engine/mallocblock.h"

typedef struct TWMask {
    u8 a, b;
} TWMask;


void func_8006D650(u8* arg0, s16 arg1, s16 arg2);


typedef struct TWImage {
    /* 0x00 */ void* data;
    /* 0x04 */ s16 width;
    /* 0x06 */ s16 height;
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
} TWImage; /* sizeof 0xC */

typedef struct TWSprData {
    /* 0x00 */ TWImage* frames;
    /* 0x04 */ void* unk_04; /* unk65770Anim.unk4/unk8: pointers, so the host layout matches */
    /* 0x08 */ void* unk_08;
    /* 0x0C */ void* unkC; /* palette */
    /* 0x10 */ char unk_10[2];
    /* 0x12 */ u16 count;
} TWSprData;

typedef struct TWSprite {
    /* 0x00 */ char unk_00[0x4C];
    /* 0x4C */ TWSprData* unk_4C;
} TWSprite;

typedef struct TWColor {
    u8 r, g, b;
} TWColor;


TWSprite* func_800675F4(s16, s16);
s32 func_8006E87C(TextWindow* arg0);
u8* func_8006F718(s16 arg0, u8 arg1);
s32 func_8006E318(s16 arg0);
s32 func_8006EB90(TextWindow* tw);
void func_8006EA44(s16 arg0);
s32 func_8006FE4C(s16 arg0);
void func_8007094C(TextWindow* arg0, SubTextWindow* arg1);
s16 func_80071278(TextWindow* arg0);
void func_8006E984(TextWindow* arg0);



typedef struct RumbleState {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
} RumbleState;

extern OSPfs D_800E4140[4];
extern RumbleState D_800E42E0[4];
/* splat label for &D_800E42E0[0].unk2; func_8006CC18 addresses that field through it */
extern RumbleState D_800E42E2[];
extern functionListEntry D_800E4310;
extern functionListEntry D_800E431C;
extern s16 D_800E4328;
extern s16 D_800E4330;
extern OSMesgQueue D_800EE960;
extern s16 D_800F2CF0[4];

typedef struct TWStyle {
    /* 0x00 */ s32 frame;  /* window frame graphic */
    /* 0x04 */ s32 cursor; /* cursor graphic */
    /* 0x08 */ s16 width;
    /* 0x0A */ s16 height;
    /* 0x0C */ s16 textX;
    /* 0x0E */ s16 textY;
    /* 0x10 */ s16 textW;
    /* 0x12 */ s16 textH;
    /* 0x14 */ s16 offsetX;
    /* 0x16 */ s16 offsetY;
    /* 0x18 */ u8 color;
} TWStyle; /* sizeof 0x1C */

u8 D_800C5DF0 = 0;
u8 D_800C5DF1 = 0;
u8 D_800C5DF2 = 1;
TWColor D_800C5DF4[10] = { { 0x40, 0x40, 0x80 }, { 0x00, 0x00, 0x00 }, { 0x20, 0x0E, 0x71 }, { 0xE7, 0x00, 0x14 }, { 0xFF, 0x00, 0xFF }, { 0x00, 0xAB, 0x29 }, { 0x00, 0x3E, 0xF9 }, { 0xFF, 0xFF, 0x00 }, { 0xFF, 0xFF, 0xFF }, { 0x80, 0xFF, 0x80 } };
TWColor D_800C5E14[10] = { { 0x40, 0x40, 0x80 }, { 0x00, 0x00, 0x00 }, { 0x20, 0x0E, 0x71 }, { 0xFF, 0x00, 0x00 }, { 0xFF, 0x00, 0xFF }, { 0x00, 0xFF, 0x00 }, { 0x00, 0xFF, 0xFF }, { 0xFF, 0xFF, 0x00 }, { 0xFF, 0xFF, 0xFF }, { 0x80, 0xFF, 0x80 } };
u8 D_800C5E34[0x100] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x04, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A,
    0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x0A, 0x0A, 0x06, 0x06, 0x06, 0x06,
    0x04, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x08, 0x06, 0x04, 0x06, 0x08, 0x06, 0x08, 0x08, 0x06,
    0x06, 0x08, 0x06, 0x06, 0x06, 0x06, 0x06, 0x08, 0x08, 0x06, 0x06, 0x06, 0x02, 0x06, 0x06, 0x06,
    0x04, 0x06, 0x06, 0x06, 0x06, 0x06, 0x04, 0x06, 0x06, 0x02, 0x04, 0x06, 0x02, 0x08, 0x06, 0x06,
    0x06, 0x06, 0x06, 0x06, 0x04, 0x06, 0x06, 0x08, 0x06, 0x06, 0x06, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A,
    0x0A, 0x0A, 0x06, 0x0A, 0x0A, 0x04, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A,
    0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A,
    0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A,
    0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A,
    0x06, 0x06, 0x06, 0x06, 0x08, 0x08, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A,
    0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A,
    0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A,
    0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x06, 0x0A
};
u8 D_800C5F34[0x100] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x04, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A,
    0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x08, 0x08, 0x06, 0x06, 0x06, 0x06,
    0x04, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x08, 0x06, 0x04, 0x06, 0x08, 0x06, 0x08, 0x08, 0x06,
    0x06, 0x08, 0x06, 0x06, 0x06, 0x06, 0x06, 0x08, 0x08, 0x06, 0x06, 0x06, 0x02, 0x06, 0x06, 0x06,
    0x04, 0x06, 0x06, 0x06, 0x06, 0x06, 0x04, 0x06, 0x06, 0x04, 0x04, 0x06, 0x04, 0x08, 0x06, 0x06,
    0x06, 0x06, 0x06, 0x06, 0x04, 0x06, 0x06, 0x08, 0x06, 0x06, 0x06, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x06, 0x08, 0x08, 0x04, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x06, 0x06, 0x06, 0x06, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x06, 0x0A
};
TWMask D_800C6034[4] = { { 0x04, 0x8C }, { 0x4C, 0xEF }, { 0x8E, 0xFF }, { 0xCF, 0xFF } };
TWColor D_800C603C[4] = { { 0xFF, 0x40, 0x40 }, { 0xFF, 0xFF, 0x20 }, { 0xFF, 0x40, 0x40 }, { 0xFF, 0xFF, 0x20 } };
extern const char D_800CB96C[], D_800CB948[], D_800CB924[], D_800CB900[], D_800CB8DC[], D_800CB8B8[], D_800CB894[], D_800CB870[], D_800CB84C[], D_800CB828[], D_800CB804[], D_800CB7E0[], D_800CB7BC[], D_800CB798[], D_800CB774[], D_800CB750[];
u8* D_800C6048[16] = {
    (u8*)D_800CB96C,
    (u8*)D_800CB948,
    (u8*)D_800CB924,
    (u8*)D_800CB900,
    (u8*)D_800CB8DC,
    (u8*)D_800CB8B8,
    (u8*)D_800CB894,
    (u8*)D_800CB870,
    (u8*)D_800CB84C,
    (u8*)D_800CB828,
    (u8*)D_800CB804,
    (u8*)D_800CB7E0,
    (u8*)D_800CB7BC,
    (u8*)D_800CB798,
    (u8*)D_800CB774,
    (u8*)D_800CB750
};
/* Window styles 2-5; retail indexes them as D_800C6050[style] (an address-only label inside
   D_800C6048: styles 0 and 1 do not exist). */
TWStyle D_800C6088[4] = {
    { 589856, 589961, 220, 45, 34, 12, 180, 28, 2, 25, 1 },
    { 720911, 720912, 220, 68, 26, 20, 192, 44, 0, 42, 1 },
    { 720896, 720897, 230, 90, 22, 14, 192, 56, 0, 48, 1 },
    { 720913, 720914, 230, 90, 28, 21, 192, 56, 0, 48, 1 },
};
/* splat labels for fields of element 0 (undefined_syms.txt); retail indexes them as arrays */
extern TWColor D_800C5DF5[];
extern TWColor D_800C5DF6[];
extern TWColor D_800C5E15[];
extern TWColor D_800C5E16[];
extern TWMask D_800C6035[];
extern TWColor D_800C603D[];
extern TWColor D_800C603E[];

/* splat labels for D_800F2CF0[1..3] and ContDStkTrg[1..3] */
extern u16 D_800F2CF2;
extern u16 D_800F2CF4;
extern u16 D_800F2CF6;
extern u16 D_800EC6EC;
extern u16 D_800EC6EE;
extern u16 D_800EC6F0;

typedef struct TWInput {
    /* 0x00 */ s16 v[4];
    /* 0x08 */ s16 count;
} TWInput; /* sizeof 0xA */

extern TWInput D_800EE1D0[32];
/* splat labels for the fields of D_800EE1D0[0] */
extern TWInput D_800EE1D2[];
extern TWInput D_800EE1D4[];
extern TWInput D_800EE1D6[];
extern TWInput D_800EE1D8[];
extern u8 D_800F64F8;
extern Process* D_800F2BC4;
typedef struct FontFile {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4; /* offset of the 8-bit glyphs */
    /* 0x08 */ s32 unk8; /* offset of the 4-bit glyphs */
} FontFile;

extern FontFile* D_800F37D4;
extern FontFile* D_800F3294;
extern void* D_800F3F34;
extern void* D_800F3F38;

s32 RequestSIFunction(unkMesg* siMessg, HuSiFunc func, void* arg, s32 type);
void func_8006407C(functionListEntry* entry, s16 type, void* func);
s32 __osMotorAccess(OSPfs* pfs, s32 flag);
void* func_80014614(s32);
void func_8006F9B0(void);
void func_8006CDA0(s16* arg0);
s32 func_8006CC18(s16* arg0);


#define mp1SpaceCharacter 0x10
#define mp1UnkCharacter 0x20

extern TextWindow* D_800ED4B0;
extern u8 D_800ED722;
extern u8 D_800F3718;
extern u8 D_800F64C4;

void func_800710E4(s16, s16, s16, s16, s16);
void DataCloseTemp(void*);

void func_8006C8E0(void) {
    s16 i;
    RumbleState* r;
    OSPfs* pfs;

    if (D_800E4328 == 0) {
        for (i = 0; i < 4; i++) {
            r = &D_800E42E0[i];
            pfs = &D_800E4140[i];
            if (r->unk0 != 0 && r->unkA != 0) {
                r->unkA--;
                __osMotorAccess(pfs, 0);
            }
        }
        return;
    }
    for (i = 0; i < 4; i++) {
        r = &D_800E42E0[i];
        pfs = &D_800E4140[i];
        switch (r->unk2) {
        case 1:
            if (--r->unkA == 0) {
                r->unk0 = 1;
                r->unk2 = 0;
            }
            __osMotorAccess(pfs, 0);
            break;
        case 2:
            __osMotorAccess(pfs, 1);
            r->unk0 = 2;
            r->unk2 = 0;
            break;
        case 3:
            if (r->unk8 <= 0) {
                switch (r->unk0) {
                case 1:
                    if (r->unk4 != 0) {
                        __osMotorAccess(pfs, 1);
                        r->unk0 = 2;
                        r->unk8 = r->unk4;
                    }
                    break;
                case 2:
                    if (r->unk6 != 0) {
                        __osMotorAccess(pfs, 0);
                        r->unk0 = 1;
                        r->unk8 = r->unk6;
                    }
                    break;
                }
            }
            r->unk8--;
            if (r->unkA != 0) {
                if (--r->unkA == 0) {
                    r->unk2 = 1;
                    r->unkA = 3;
                }
            }
            break;
        }
    }
}
void func_8006CB1C(void) {
    s16 i;
    s16 sp10;

    D_800E4328 = 0;
    for (i = 0; i < 4; i++) {
        sp10 = i;
        func_8006CDA0(&sp10);
    }
}
s32 func_8006CB6C(void) {
    s16 i;

    for (i = 0; i < 4; i++) {
        func_8006CC18(&i);
    }
    return 0;
}
void func_8006CBB0(void) {
    unkMesg sp10;

    D_800E4328 = 1;
    RequestSIFunction(&sp10, (void*)func_8006CB6C, 0, 1);
    func_8006407C(&D_800E4310, 0, func_8006C8E0);
    func_8006407C(&D_800E431C, 1, func_8006CB1C);
}
s32 func_8006CC18(s16* arg0) {
    s32 ret = osMotorInit(&D_800EE960, &D_800E4140[*arg0], *arg0);

    if (ret == 0) {
        D_800E42E0[*arg0].unk0 = 1;
        __osMotorAccess(&D_800E4140[*arg0], 0);
    } else {
        D_800E42E0[*arg0].unk0 = 0;
    }
    D_800E42E2[*arg0].unk0 = 0;
    return ret;
}
void func_8006CD0C(s16 arg0) {
    unkMesg sp10;
    s16 sp20 = arg0;

    RequestSIFunction(&sp10, (void*)func_8006CC18, &sp20, 1);
}
void func_8006CD3C(s16* arg0) {
    RumbleState* r = &D_800E42E0[*arg0];

    if (r->unk0 != 0) {
        r->unk2 = 2;
    }
}
void func_8006CD70(s16 arg0) {
    unkMesg sp10;
    s16 sp20 = arg0;

    RequestSIFunction(&sp10, (void*)func_8006CD3C, &sp20, 1);
}
void func_8006CDA0(s16* arg0) {
    RumbleState* r = &D_800E42E0[*arg0];

    if (r->unk0 != 0) {
        r->unk2 = 1;
        r->unkA = 3;
    }
}
void func_8006CDDC(s16 arg0) {
    unkMesg sp10;
    s16 sp20 = arg0;

    RequestSIFunction(&sp10, (void*)func_8006CDA0, &sp20, 1);
}
void func_8006CE0C(s16* arg0) {
    RumbleState* r = &D_800E42E0[arg0[0]];

    if (r->unk0 != 0) {
        r->unk0 = 1;
        r->unk2 = 3;
        r->unk4 = arg0[1];
        r->unk6 = arg0[2];
        r->unkA = arg0[3];
        r->unk8 = 0;
    }
}
void func_8006CE64(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    unkMesg sp10;
    s16 sp20[4];

    sp20[0] = arg0;
    sp20[1] = arg1;
    sp20[2] = arg2;
    sp20[3] = arg3;
    RequestSIFunction(&sp10, (void*)func_8006CE0C, sp20, 1);
}
// decomp-permuter
void func_8006CEA0(void)
{
  s16 i;
  s32 mode;
  if (D_800C5DF1 == 0)
  {
    D_800ED4B0 = MallocTemp(14 * sizeof(TextWindow)); /* 0x22C8 on the N64; TextWindow holds pointers */
    for (i = 0; i < 14; i++)
    {
      D_800ED4B0[i].unk_36 = -1;
    }

    D_800ED4B0[0].unk_3A = -1;
    D_800ED4B0[0].unk_3C = 1;
    D_800ED4B0[0].unk_36 = 0;
    D_800ED4B0[1].unk_3A = 0;
    D_800ED4B0[1].unk_3C = -1;
    D_800ED4B0[1].unk_36 = -0x218;
    D_800F64C4 = 0;
    D_800F3718 = 0;
    D_800E4330 = 10000;
    i = 4;
    mode = D_800C5DF2;
    if ((mode == 0) || ((mode >= 0) && (mode < i)))
    {
      D_800F37D4 = func_80014614(0x7A);
      D_800F3294 = func_80014614(0x86);
    }
    D_800F2BC4 = omAddPrcObj(func_8006F9B0, 0x1001, 0x800, 0);
    omPrcSetStatBit(D_800F2BC4, 0xA0);
    D_800C5DF1 = 1;
    D_800ED722 = 0;
    D_800ECC22 = 0;
    D_800F3F34 = func_80014614(0x77);
    D_800F3F38 = func_80014614(0x78);
  }
}
s16 func_8006D010(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s16 arg5) {
    TextWindow* tw;
    TWSprite* spr;
    s16 i;
    s16 id;
    s16 sprId;

    for (id = 2; id < 14; id++) {
        if (D_800ED4B0[id].unk_36 == -1) {
            break;
        }
    }
    if (id == 14) {
        return -1;
    }
    if (arg2 & 1) {
        arg2++;
    }
    tw = &D_800ED4B0[id];
    tw->unk_3C = 1;
    tw->unk_3A = D_800ED4B0[1].unk_3A;
    tw->unk_36 = 0x7D00;
    D_800ED4B0[D_800ED4B0[1].unk_3A].unk_3C = id;
    D_800ED4B0[1].unk_3A = id;
    tw->unk_14 = arg0;
    tw->unk_16 = arg1;
    tw->unk_18 = arg2;
    tw->unk_1A = arg3;
    tw->unk_1C = (arg2 + 0xF) & 0xFFF0;
    tw->unk_1E = arg3 + 0x10;
    tw->unk_EC = tw->unk_F0 = 1.0f;
    tw->unk_24 = tw->unk_26 = tw->unk_2C = tw->unk_2E = 4;
    tw->unk_28 = arg2 - 8;
    tw->unk_2A = arg3 - 8;
    tw->unk_00 = 0;
    tw->unk_12 = tw->unk_02 = 7;
    tw->unk_03 = tw->unk_04 = 1;
    tw->unk_07 = 10;
    tw->unk_08 = 12;
    tw->unk_09 = 0;
    tw->unk_0A = 2;
    tw->unk_30 = tw->unk_18 - tw->unk_07;
    tw->unk_32 = tw->unk_1A - tw->unk_08;
    tw->unk_20 = tw->unk_22 = 0;
    tw->unk_05 = 0;
    tw->unk_0D = D_800C5DF4[0].r;
    tw->unk_0E = D_800C5DF4[0].g;
    tw->unk_0F = D_800C5DF4[0].b;
    tw->unk_01 = 0xF;
    tw->unk_11 = 0;
    tw->unk_06 = 0;
    tw->string = NULL;
    tw->unk_7A = -1;
    tw->unk_0C = 2;
    for (i = 0; i < 10; i++) {
        tw->unk_88[i] = NULL;
    }
    for (i = 0; i < 10; i++) {
        tw->unk_C0[i] = NULL;
    }
    tw->unk_E8 = NULL;
    tw->unk_42 = -1;
    for (i = 0; i < 20; i++) {
        tw->unk_46[i] = (i >= 12) ? -1 : 0;
    }
    tw->unk_6E = 0;
    tw->unk_3E = func_800678A4(D_800F3F34);
    tw->unk_40 = func_800678A4(D_800F3F38);
    tw->unk_44 = sprId = func_80064EF4(20, 5);
    for (i = 0; i < 10; i++) {
        func_8006752C(sprId, i, 0xFF);
        func_80067480(sprId, i, 0xFFFF);
        func_800674BC(sprId, i, 0x01009000);
        func_800672B0(sprId, i, 0);
        func_80067208(sprId, i, tw->unk_3E, i);
        func_80066DC4(sprId, i, 0, 0);
        func_800674F4(sprId, i, D_800C5DF4[i].r, D_800C5DF5[i].r, D_800C5DF6[i].r);
        func_80067598(sprId, i, 0);
    }
    func_80067598(sprId, 0, -1);
    func_80066DC4(sprId, 0, arg0, arg1);
    spr = func_800675F4(sprId, 0);
    spr->unk_4C->frames->width = arg2;
    spr->unk_4C->frames->height = arg3;
    func_80023728(spr->unk_4C->frames->data);
    spr->unk_4C->frames->data = tw->unk_C0[0] = func_80023668((arg2 * arg3) / 2);
    func_8009B770(tw->unk_C0[0], 0xFF, (arg2 * arg3) / 2);
    if (arg5 != 1) {
        func_8006D650(tw->unk_C0[0], arg2, arg3);
    }
    func_8006752C(sprId, 0, 100);
    func_80067480(sprId, 0, 0x8000);
    func_800672B0(sprId, 0, 0);
    func_8006752C(sprId, 10, 0x100);
    func_80067480(sprId, 10, 0xFFFF);
    func_800674BC(sprId, 10, 0x01009000);
    func_800672B0(sprId, 10, 0);
    func_80067208(sprId, 10, tw->unk_40, 0);
    func_80066DC4(sprId, 10, 0, 0);
    func_80067598(sprId, 10, 0);
    for (i = 0; i < 20; i++) {
        func_80067384(sprId, i, D_800E4330);
    }
    func_80067384(sprId, 11, D_800E4330 - 1);
    tw->unk_38 = D_800E4330;
    D_800E4330 -= 0x20;
    return id;
}
// retail recomputes (arg1 - 4) / 2 for every store; GCC hoists it out of the loop (masked 27)
#ifdef NON_MATCHING
void func_8006D650(u8* arg0, s16 arg1, s16 arg2) {
    s16 i;
    s32 top;
    s32 bot;
    s32 sw0;
    s32 sw1;
    u8* m0;
    u8* m1;

    for (i = 0; i < 4; i++) {
        top = (i * arg1) / 2;
        m0 = &D_800C6034[i].a;
        arg0[top] &= *m0;
        m1 = &D_800C6035[i].a;
        arg0[top + 1] &= *m1;
        bot = ((arg2 - i - 1) * arg1) / 2;
        arg0[bot] &= *m0;
        arg0[bot + 1] &= *m1;
        sw0 = (*m0 >> 4) | (*m0 << 4);
        sw1 = (*m1 >> 4) | (*m1 << 4);
        arg0[(arg1 - 4) / 2 + top] &= sw1;
        arg0[(arg1 - 4) / 2 + top + 1] &= sw0;
        arg0[(arg1 - 4) / 2 + bot] &= sw1;
        arg0[(arg1 - 4) / 2 + bot + 1] &= sw0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/6D4E0", func_8006D650);
#endif

void LoadStringIntoWindow(s16 win_id, void* string_id, s16 a, s16 b) {
    void* text;
    s32 tempVar;
    TextWindow* textWindow = &D_800ED4B0[win_id];

    if (textWindow->string != NULL) {
        if (textWindow->usingStringIDBool != 0) {
            func_8005B838(textWindow->string);
        }
    }
    
    textWindow->unk_34 = 1;
    
    if ((u32) string_id > 0x80000000U) { //is a pointer
        textWindow->usingStringIDBool = 0;
        textWindow->stringPtr = string_id;
    } else {
        textWindow->usingStringIDBool = 1;
        text = func_8005B7E8((u32)string_id); //get string from index
        textWindow->string = text;
        textWindow->stringPtr = text;
    }
    
    if (!(a < 0)) {
        textWindow->unk_2C = a;
    }
    
    else if (a == -2) {
        textWindow->unk_2C = (textWindow->unk_18 - func_8006D99C(textWindow->stringPtr, textWindow->unk_05)) / 2;
    }
    
    if (b >= 0) {
        textWindow->unk_2E = b;
    } else if (b == -2) {
        tempVar = -(textWindow->unk_05 < 1);
        tempVar = (tempVar & 0x0C);
        textWindow->unk_2E = (textWindow->unk_1A - (tempVar | 8)) / 2;
    }
    
    textWindow->unk_00 = 1;
    textWindow->unk_10 = 0;
}

s16 func_8006D93C(u8* arg0) {
    s16 var_a1 = 0;

    for (; *arg0 != 0; arg0++) {
        if ((*arg0 >= mp1UnkCharacter) | (*arg0 == mp1SpaceCharacter)) {
            var_a1 += 1;
        }
        
        if (((*arg0 + 0x80) & 0xFF) < 2U) {
            var_a1 -= 1;
        }
    }
    return var_a1;
}

s16 func_8006D99C(u8* arg0, s16 arg1) {
    s16 var_v1 = 0;

    for (; *arg0 != 0; arg0++) {
        if ((u8)(*arg0 + 0x80) >= 2) {
                var_v1 += (arg1 == 0) ? D_800C5E34[*arg0] : D_800C5F34[*arg0];
        }
    }
    return var_v1;
}

void func_8006DA1C(s16 arg0, s32 arg1, s32 arg2) {
    TextWindow* textWindow = &D_800ED4B0[arg0];

    textWindow->unk_06 &= ~arg1;
    textWindow->unk_06 |= arg2;
}

void func_8006DA5C(s16 arg0, void* arg1, s8 arg2) {
    TextWindow* textWindow = &D_800ED4B0[arg0];

    if (textWindow->unk_88[arg2] != NULL) {
        if (textWindow->unk_7B[arg2] != 0) {
            func_8005B838(textWindow->unk_88[arg2]);
        }
    }
    
    if (0x80000000U < (u32) arg1) { //if arg1 is stringID
        textWindow->unk_7B[arg2] = 0;
        textWindow->unk_88[arg2] = arg1;
        return;
    }
    
    textWindow->unk_7B[arg2] = 1;
    textWindow->unk_88[arg2] = func_8005B7E8((s32)arg1);
}

s16 func_8006DB3C(s16 arg0, s32 arg1, s16 arg2, s16 arg3, s16 arg4) {
    TextWindow* temp_s3 = &D_800ED4B0[arg0];
    s16 temp_v0_3;
    s16 i;
    void* file;

    for (i = 12; i < 20; i++) {
       if (temp_s3->unk_46[i] == -1) {
           break;
        }
    }

    if (i == 20) {
        return -1;
    }
 
    file = DataRead(arg1);
    temp_v0_3 = func_800678A4(file);
    temp_s3->unk_46[i] = temp_v0_3;
    HuMemDirectFree(file);
    func_80067208(temp_s3->unk_44, i, temp_v0_3, arg4);
    func_80066DC4(temp_s3->unk_44, i, arg2, arg3);
    func_80067598(temp_s3->unk_44, i, 0);
    return i;
}

s16 func_8006DC7C(s16 arg0, s32 arg1, s16 arg2, s16 arg3, s16 arg4) {
    TextWindow* temp_s0 = &D_800ED4B0[arg0];
    SubTextWindow* temp_v1;
    s32 temp_v0;

    temp_v0 = func_8006DB3C(arg0, arg1, arg2, arg3, arg4);
    temp_v1 = &temp_s0->unk_F4[temp_s0->unk_10];
    temp_v1->unk2 = arg2;
    temp_v1->unk4 = arg3;
    temp_v1->unk6 = 0;
    temp_v1->unk8 = 0;
    temp_v1->unk0 = 1;
    temp_s0->unk_10 += 1;
    return temp_v0;
}

void func_8006DD30(s16 arg0, u8 arg1) {
    TextWindow* textWindow = &D_800ED4B0[arg0];
    textWindow->unk_05 = arg1;
}

TextWindow* func_8006DD60(s16 arg0) {
    return &D_800ED4B0[arg0];
}

s16 func_8006DD8C(s16 arg0, s16 arg1) {
    TextWindow* textWindow = &D_800ED4B0[arg0];
    return textWindow->unk_46[arg1];
}

void func_8006DDC8(s16 arg0, s32 arg1, s16 arg2) {
    TextWindow* textWindow = &D_800ED4B0[arg0];
    func_80066DC4(textWindow->unk_44, 0, arg1, arg2);
}

void func_8006DE20(s16 arg0, f32 arg1, f32 arg2) {
    TextWindow* temp_s1 = &D_800ED4B0[arg0];
    s16 i;

    temp_s1->unk_EC = arg1;
    temp_s1->unk_F0 = arg2;

    for (i = 0; i < 11; i++) {
        func_80067354(temp_s1->unk_44, i, arg1, arg2);
    }
}

void func_8006DEC8(s16 arg0, s32 arg1, s32 arg2) {
    TextWindow* tw = &D_800ED4B0[arg0];
    TWSprite* spr;
    s16 i;

    tw->unk_20 = arg1;
    tw->unk_22 = arg2;
    spr = func_800675F4(tw->unk_44, 0);
    for (i = 0; i < spr->unk_4C->count; i++) {
        spr->unk_4C->frames[i].unk8 = arg1;
        spr->unk_4C->frames[i].unkA = arg2;
    }
    spr = func_800675F4(tw->unk_44, 10);
    for (i = 0; i < spr->unk_4C->count; i++) {
        spr->unk_4C->frames[i].unk8 = arg1;
        spr->unk_4C->frames[i].unkA = arg2;
    }
}
void func_8006E01C(s16 arg0, f32 arg1) {
    TextWindow* textWindow = &D_800ED4B0[arg0];
    func_800673B0(textWindow->unk_44, 0, arg1);
}

void func_8006E070(s16 arg0, s32 arg1) {
    TextWindow* textWindow = &D_800ED4B0[arg0];
    
    textWindow->unk_03 = arg1;
    textWindow->unk_04 = arg1;
}

void func_8006E0A4(s16 arg0, s32 arg1) {
    TextWindow* temp_s1 = &D_800ED4B0[arg0];
    s16 i;

    temp_s1->unk_38 = arg1;

    for (i = 0; i < 20; i++) {
        func_80067384(temp_s1->unk_44, i, arg1);
    }

    if (temp_s1->unk_42 != -1) {
        func_80067384(temp_s1->unk_44, 11, (arg1 - 1));
    }
}

void func_8006E154(s16 arg0, s16 arg1) {
    TextWindow* temp_s0 = &D_800ED4B0[arg0];
    
    if (arg1 == 0) {
        func_800674BC(temp_s0->unk_44, 0, 0x8000);
    } else {
        func_80067480(temp_s0->unk_44, 0, 0x8000);
    }
    
    func_8006752C(temp_s0->unk_44, 0, arg1);
}

void func_8006E1E4(s16 arg0, s32 arg1) {
    TextWindow* textWindow = &D_800ED4B0[arg0];
    s16 i;

    for (i = 1; i < 10; i++) {
        func_8006752C(textWindow->unk_44, i, arg1);
    }

    func_8006752C(textWindow->unk_44, 0xA, (0xFF - arg1));
}

void func_8006E288(s16 arg0, u8 arg1) {
    TextWindow* textWindow = &D_800ED4B0[arg0];
    textWindow->unk_02 = arg1;
}

void func_8006E2B8(s16 arg0, u8 arg1, u8 arg2, u8 arg3) {
    TextWindow* textWindow = &D_800ED4B0[arg0];
    func_800674F4(textWindow->unk_44, 1, arg1, arg2, arg3);
}

s32 func_8006E318(s16 arg0) {
    TextWindow* tw = &D_800ED4B0[arg0];
    SubTextWindow* sub;
    s16 n;
    s32 c;

    while (tw->unk_34 >= tw->unk_04) {
        while (*tw->stringPtr < 0x21) {
            if (*tw->stringPtr == 0) {
                if (tw->unk_7A >= 0) {
                    tw->unk_7A = -1;
                    tw->stringPtr = tw->unk_BC;
                    continue;
                }
                if (tw->usingStringIDBool != 0) {
                    func_8005B838(tw->string);
                }
                tw->string = NULL;
                tw->unk_00 = 0;
                D_800ED722 = 0;
                return 0;
            }
            if (*tw->stringPtr < 10) {
                tw->unk_02 = *tw->stringPtr - 1;
            }
            c = *tw->stringPtr - 0x11;
            if ((u8)c < 10) {
                tw->unk_7A = c;
                if (tw->unk_88[tw->unk_7A] != NULL) {
                    tw->unk_BC = ++tw->stringPtr;
                    tw->stringPtr = tw->unk_88[tw->unk_7A];
                    continue;
                }
                tw->unk_7A = -1;
            }
            if ((tw->unk_06 & 4) && (*tw->stringPtr == 0x10 || *tw->stringPtr == 0x20)) {
                *tw->stringPtr = 0x40;
                break;
            }
            switch (*tw->stringPtr) {
            case 0x10:
            case 0x20:
                tw->stringPtr++;
                tw->unk_13 = (D_800C5DF2 != 0) ? 4 : ((-(tw->unk_05 == 0) & 0xA) | 8);
                if (func_8006E87C(tw) == 0) {
                    tw->unk_00 = 2;
                    return 1;
                }
                continue;
            case 10:
                if (D_800ED722 == 0 && func_8006E93C(tw) == 0) {
                    tw->stringPtr++;
                    return 1;
                }
                break;
            case 11:
                func_8006E984(tw);
                break;
            case 12:
                sub = &tw->unk_F4[tw->unk_10];
                sub->unk2 = tw->unk_2C - tw->unk_20;
                sub->unk4 = tw->unk_2E - tw->unk_22;
                tw->unk_04 = 0;
                tw->unk_34 = 0;
                break;
            case 13:
                sub = &tw->unk_F4[tw->unk_10];
                sub->unk6 = tw->unk_2C - sub->unk2;
                sub->unk8 = (tw->unk_2E - sub->unk4) + tw->unk_08;
                sub->unk0 = 0;
                tw->unk_04 = tw->unk_03;
                if (++tw->unk_10 >= 24) {
                    osSyncPrintf("Select Max Over!\n");
                    tw->unk_10--;
                }
                break;
            case 14:
                n = ((s16)(tw->unk_2C - tw->unk_24) + 12) / 12 * 12;
                if (n < tw->unk_28) {
                    tw->unk_2C = n + tw->unk_24;
                }
                break;
            }
            tw->stringPtr++;
        }
        if (*tw->stringPtr == 0xFF) {
            tw->unk_00 = 2;
            tw->stringPtr++;
            return 1;
        }
        tw->unk_34 -= tw->unk_04;
        if (tw->unk_2E + tw->unk_08 > tw->unk_26 + tw->unk_2A) {
            tw->unk_00 = 5;
            tw->unk_0B = 0;
            return 1;
        }
        if (*tw->stringPtr >= 0x30) {
            func_8006EEB8(arg0, *tw->stringPtr, 0, tw->unk_2C + 1, tw->unk_2E + 1);
            func_8006EEB8(arg0, *tw->stringPtr, tw->unk_02, tw->unk_2C, tw->unk_2E);
        } else {
            func_8006EEB8(arg0, *tw->stringPtr, 9, tw->unk_2C, tw->unk_2E);
        }
        tw->stringPtr++;
        if ((u8)(*tw->stringPtr + 0x80) < 2) {
            func_8006EEB8(arg0, *tw->stringPtr, 0, tw->unk_07 + tw->unk_2C - 2, tw->unk_2E);
            func_8006EEB8(arg0, *tw->stringPtr, tw->unk_02, tw->unk_07 + tw->unk_2C - 3, tw->unk_2E - 1);
            tw->stringPtr++;
        }
        if (func_8006E87C(tw) == 0) {
            return 1;
        }
        if (*tw->stringPtr == 0) {
            return 0;
        }
    }
    tw->unk_34++;
    return 1;
}
s32 func_8006E87C(TextWindow* arg0) {
    s32 var_v1;

    arg0->unk_2C = (u16) (arg0->unk_2C + (arg0->unk_13 + arg0->unk_09));
    
    if (D_800C5DF2 == 0) {
        var_v1 = arg0->unk_07;
    } else if (arg0->unk_05 == 8) {
        var_v1 = D_800C5F34[*arg0->stringPtr];
    } else {
        var_v1 = D_800C5E34[*arg0->stringPtr];
    }
    
    if ((var_v1 + arg0->unk_2C) > (arg0->unk_24 + arg0->unk_28)) {
        if (*arg0->stringPtr >= 0x20) {
            return func_8006E93C(arg0);
        }
    }
    return 1;
}

s32 func_8006E93C(TextWindow* arg0) {
    arg0->unk_2C = arg0->unk_24;
    arg0->unk_2E = arg0->unk_2E + (arg0->unk_08 + arg0->unk_0A);
    return ((arg0->unk_2E + arg0->unk_08) > (arg0->unk_26 + arg0->unk_2A)) ^ 1;
}

void func_8006E984(TextWindow* arg0) {
    s16 i;
    
    for (i = 1; i < 10; i++) {
        if (arg0->unk_C0[i] != NULL) {
            func_8009B770(arg0->unk_C0[i], 0, (arg0->unk_1C * arg0->unk_1A) / 2);
        }
    }

    if (arg0->unk_E8 != NULL) {
        func_8009B770(arg0->unk_E8, 0, arg0->unk_18 * arg0->unk_1A);
    }
    
    arg0->unk_2C = arg0->unk_24;
    arg0->unk_2E = arg0->unk_26;
    arg0->unk_6E = 0;
}

void func_8006EA44(s16 arg0) {
    TextWindow* textWindow = &D_800ED4B0[arg0];
    
    if ((D_800C5DF0 & 7) < 6) {
        func_8006EEB8(arg0, 255, 0, textWindow->unk_30, textWindow->unk_32);
        func_8006EEB8(arg0, 255, textWindow->unk_12, (textWindow->unk_30 - 1), (textWindow->unk_32 - 1));
        return;
    }
    
    func_8006F3BC(arg0, (textWindow->unk_30 - 1), (textWindow->unk_32 - 1), (textWindow->unk_07 + 1), textWindow->unk_08 + 1);
}

void func_8006EB40(s16 win_id) {
    func_8006E984(&D_800ED4B0[win_id]);
}

void func_8006EB80(void) {
    D_800ED722 = 1;
}

s32 func_8006EB90(TextWindow* tw) {
    TWSprite* spr;
    u8* new;
    u8* old;
    s16 i;

    tw->unk_0B += tw->unk_0C;
    if (tw->unk_0B > tw->unk_08) {
        for (i = 1; i < 10; i++) {
            if (tw->unk_C0[i] != NULL) {
                old = tw->unk_C0[i];
                spr = func_800675F4(tw->unk_44, i);
                new = spr->unk_4C->frames[i].data = tw->unk_C0[i] = func_80023668((tw->unk_1C * tw->unk_1E) / 2);
                func_8009B770(new, 0, (tw->unk_1C * tw->unk_1E) / 2);
                func_80023A38(old + (tw->unk_1C * (tw->unk_08 + tw->unk_0A + tw->unk_26)) / 2,
                              new + (tw->unk_1C * tw->unk_26) / 2, (tw->unk_1C * tw->unk_2E) / 2);
                func_80023888(old);
            }
        }
        if (tw->unk_E8 != NULL) {
            old = tw->unk_E8;
            spr = func_800675F4(tw->unk_44, 10);
            new = spr->unk_4C->frames->data = tw->unk_E8 = func_80023668(tw->unk_1C * tw->unk_1E);
            func_8009B770(new, 0, tw->unk_1C * tw->unk_1E);
            func_80023A38(old + tw->unk_1C * (tw->unk_08 + tw->unk_0A + tw->unk_26),
                          new + tw->unk_1C * tw->unk_26, tw->unk_1C * tw->unk_2E);
            func_80023888(old);
        }
        return 0;
    }
    for (i = 1; i < 10; i++) {
        if (tw->unk_C0[i] != NULL) {
            spr = func_800675F4(tw->unk_44, i);
            spr->unk_4C->frames[i].data = tw->unk_1C / 2 * tw->unk_0B + tw->unk_C0[i];
        }
    }
    if (tw->unk_E8 != NULL) {
        func_800675F4(tw->unk_44, 10)->unk_4C->frames->data = tw->unk_1C * tw->unk_0B + tw->unk_E8;
    }
    return 1;
}
// GCC proves the glyph width/height non-negative and uses srl/ori where retail uses signed ops (masked 41)
#ifdef NON_MATCHING
void func_8006EEB8(s16 arg0, u8 arg1, u8 arg2, s16 arg3, s16 arg4) {
    TextWindow* tw = &D_800ED4B0[arg0];
    u8* src;
    u8* dst;
    u8* buf;
    s16 x;
    s16 y;
    s16 row;
    s16 col;
    s16 stride;
    s16 w;
    s16 h;
    s16 srcStride;

    y = (arg4 < 0) ? 0 : arg4;
    x = (arg3 < 0) ? 0 : arg3;
    buf = func_8006F718(arg0, arg2);
    if (arg2 < 9) {
        if (tw->unk_05 == 0) {
            src = (u8*)D_800F37D4 + D_800F37D4->unk8 + (arg1 - 0x30) * 60;
            w = 10;
            if (D_800C5DF2 != 0) {
                w = D_800C5E34[arg1];
            }
            h = 12;
            srcStride = 5;
        } else {
            src = (u8*)D_800F3294 + D_800F3294->unk8 + (arg1 - 0x30) * 32;
            if (D_800C5DF2 == 0 || (w = D_800C5F34[arg1]) >= 9) {
                w = 8;
            }
            h = 8;
            srcStride = 4;
        }
        tw->unk_13 = w;
        if ((tw->unk_06 & 4) && arg1 != 0x80 && arg1 != 0x81 && arg2 == 0) {
            func_8006F3BC(arg0, x - 1, y - 2, tw->unk_09 + 3 + w, h + 2);
        }
        dst = buf + (x + y * tw->unk_1C) / 2;
        stride = tw->unk_1C / 2;
        if (x & 1) {
            for (row = 0; row < h; row++) {
                for (col = 0; col < w / 2; col++) {
                    dst[col] |= *src >> 4;
                    dst[col + 1] |= *src << 4;
                    src++;
                }
                src += srcStride - col;
                dst += stride;
            }
        } else {
            for (row = 0; row < h; row++) {
                for (col = 0; col < w / 2; col++) {
                    dst[col] |= *src;
                    src++;
                }
                src += srcStride - col;
                dst += stride;
            }
        }
    } else {
        tw->unk_13 = 10;
        if ((tw->unk_06 & 4) && arg1 != 0x80 && arg1 != 0x81) {
            func_8006F3BC(arg0, x - 1, y - 2, tw->unk_07 + 3, tw->unk_08 + 2);
        }
        src = (u8*)D_800F37D4 + D_800F37D4->unk4 + (arg1 - 0x20) * 120;
        dst = buf + x + y * tw->unk_1C;
        for (row = 0; row < tw->unk_08; row++) {
            for (col = 0; col < tw->unk_07; col++) {
                dst[col] |= *src;
                src++;
            }
            dst += tw->unk_1C;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/6D4E0", func_8006EEB8);
#endif
void func_8006F3BC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    TextWindow* tw = &D_800ED4B0[arg0];
    u8* img;
    u8* buf;
    u8* dst;
    s16 x;
    s16 y;
    s16 i;
    s16 row;
    s16 col;

    y = (arg2 < 0) ? 0 : arg2;
    x = (arg1 < 0) ? 0 : arg1;
    for (i = 1; i < 11; i++) {
        if (i == 10) {
            img = tw->unk_E8;
        } else {
            img = tw->unk_C0[i];
        }
        if (img != NULL) {
            buf = func_8006F718(arg0, i - 1);
            if (i < 10) {
                dst = buf + (x + y * tw->unk_1C) / 2;
                if (x & 1) {
                    for (row = 0; row < arg4; row++) {
                        for (col = 0; col < arg3 / 2; col++) {
                            dst[col] &= 0xF0;
                            dst[col + 1] &= 0xF;
                        }
                        dst += tw->unk_1C / 2;
                    }
                } else {
                    for (row = 0; row < arg4; row++) {
                        for (col = 0; col < arg3 / 2; col++) {
                            dst[col] = 0;
                        }
                        dst += tw->unk_1C / 2;
                    }
                }
            } else {
                dst = buf + x + y * tw->unk_1C;
                for (row = 0; row < arg4; row++) {
                    for (col = 0; col < arg3; col++) {
                        dst[col] = 0;
                    }
                    dst += tw->unk_1C;
                }
            }
        }
    }
}
u8* func_8006F718(s16 arg0, u8 arg1) {
    TextWindow* tw = &D_800ED4B0[arg0];
    s16 sprId = tw->unk_44;
    TWSprite* spr = func_800675F4(sprId, arg1 + 1);
    u8* buf;
    s16 w;
    s16 h;

    if (arg1 < 9 && tw->unk_C0[arg1 + 1] != NULL) {
        return spr->unk_4C->frames[arg1 + 1].data;
    }
    if (arg1 == 9 && tw->unk_E8 != NULL) {
        return spr->unk_4C->frames->data;
    }
    arg1++;
    w = tw->unk_1C;
    h = tw->unk_1E;
    if (arg1 < 10) {
        func_80023728(spr->unk_4C->frames[arg1].data);
        spr->unk_4C->frames[arg1].width = w;
        spr->unk_4C->frames[arg1].height = tw->unk_1A;
        buf = spr->unk_4C->frames[arg1].data = tw->unk_C0[arg1] = func_80023668((w * h) / 2);
        func_8009B770(tw->unk_C0[arg1], 0, (w * h) / 2);
    } else {
        func_80023728(spr->unk_4C->frames->data);
        spr->unk_4C->frames->width = w;
        spr->unk_4C->frames->height = tw->unk_1A;
        buf = spr->unk_4C->frames->data = tw->unk_E8 = func_80023668(w * h);
        func_8009B770(tw->unk_E8, 0, w * h);
        func_80023728(spr->unk_4C->unkC);
        spr->unk_4C->unkC = func_80023668(200);
        func_80023A38((u8*)D_800F37D4 + 0xC, spr->unk_4C->unkC, 200);
    }
    if (!(tw->unk_06 & 8)) {
        func_80067480(sprId, arg1, 0x8000);
    }
    return buf;
}
// decomp-permuter
void func_8006F9B0(void)
{
  TextWindow *tw;
  s16 id;
  short c;
  while (1)
  {
    HuPrcVSleep();
    id = D_800ED4B0[0].unk_3C;
    while (D_800ED4B0[id].unk_3C != (-1))
    {
      tw = &D_800ED4B0[id];
      c = D_800C5DF0 & 3;
      func_800674F4(tw->unk_44, 9, D_800C603C[c].r, D_800C603D[c].r, D_800C603E[c].r);
      if (((D_800ECC22 == 0) || (tw->unk_06 & 0x40)) && ((func_8005FD5C() + D_800F64F8) != 0))
      {
        id = D_800ED4B0[id].unk_3C;
        continue;
      }
      switch (tw->unk_00)
      {
        case 1:
          func_8006E318(id);
          break;

        case 2:
          func_8006EA44(id);
          if ((!(tw->unk_06 & 0x10)) && (func_80071278(tw) & 0xC000))
        {
          PlaySound((tw->unk_06 & 0x20) ? (0x34) : (0x46));
          tw->unk_00 = 1;
          func_8006F3BC(id, tw->unk_30 - 1, tw->unk_32 - 1, tw->unk_07 + 1, tw->unk_08 + 1);
        }
          break;

        case 5:
          if (func_8006EB90(tw) == 0)
        {
          tw->unk_2E -= tw->unk_08 + tw->unk_0A;
          tw->unk_00 = 1;
        }
          break;

        case 6:
          if (func_8006FE4C(id) == 0)
        {
          tw->unk_00 = 0;
        }
          if (tw->unk_08)
        {
          break;
        }
        else
        {
          break;
        }

      }

      func_8007094C(tw, &tw->unk_F4[tw->unk_11]);
      id = D_800ED4B0[id].unk_3C;
    }

    D_800C5DF0++;
  }

}
s16 func_8006FCC0(s16 arg0) {
    return D_800ED4B0[arg0].unk_00;
}

s32 func_8006FCF0(s16 arg0, s8 arg1, s32 arg2) {
    TextWindow* tw = &D_800ED4B0[arg0];
    void* file;

    if (tw->unk_42 == -1) {
        file = DataRead(0x85);
        tw->unk_42 = func_800678A4(file);
        HuMemDirectFree(file);
        func_80067208(tw->unk_44, 11, tw->unk_42, 0);
        func_8006752C(tw->unk_44, 11, 0x100);
        func_80067480(tw->unk_44, 11, 0xFFFF);
        func_800674BC(tw->unk_44, 11, 0x01009000);
        func_80067384(tw->unk_44, 11, tw->unk_38 - 1);
    }
    if (arg2 != 0) {
        tw->unk_06 |= 1;
    }
    tw->unk_11 = arg1;
    tw->unk_00 = 6;
    tw->unk_6E = 1;
    tw->unk_78 = 0;
    while (func_8006FCC0(arg0) == 6) {
        HuPrcVSleep();
    }
    return tw->unk_11;
}
// register allocation in the cursor-move tail: the new entry's index reuses the compare's sign-extension (masked 9)
#ifdef NON_MATCHING
s32 func_8006FE4C(s16 arg0) {
    TextWindow* tw = &D_800ED4B0[arg0];
    SubTextWindow* sub;
    s16 cur;
    s16 sel;
    s16 dir;
    s16 x;
    s16 y;
    s16 count;
    s16 i;
    s16 best;
    s16 dy;
    s16 d2;
    s16 dx;
    s16 btn;
    s16 cancel;
    f32 d;
    f32 bestDx;
    f32 bestDy;

    sel = cur = tw->unk_11;
    dir = -1;
    if (tw->unk_6E != 3) {
        btn = func_80071278(tw);
    } else {
        btn = 0;
    }
    if (btn & 0x200) {
        dir = 0;
    }
    if (btn & 0x100) {
        dir = 2;
    }
    if (btn & 0x800) {
        dir = 1;
    }
    if (btn & 0x400) {
        dir = 3;
    }
    x = tw->unk_F4[cur].unk2;
    y = tw->unk_F4[cur].unk4;
    bestDx = 100000.0f;
    count = tw->unk_10;
    bestDy = bestDx;
    switch (dir) {
    case 0:
        for (i = 0; i < count; i++) {
            if (i != cur && tw->unk_F4[i].unk4 == y && tw->unk_F4[i].unk2 < x) {
                break;
            }
        }
        if (i != count) {
            for (i = 0; i < count; i++) {
                if (i != cur && tw->unk_F4[i].unk4 == y && tw->unk_F4[i].unk2 < x) {
                    d = x - tw->unk_F4[i].unk2;
                    if (d < bestDy) {
                        bestDy = d;
                        sel = i;
                    }
                }
            }
        } else {
            best = -1000;
            for (i = 0; i < count; i++) {
                if (i != cur && tw->unk_F4[i].unk4 == y && tw->unk_F4[i].unk2 > best) {
                    best = tw->unk_F4[i].unk2;
                    sel = i;
                }
            }
        }
        break;
    case 1:
        for (i = 0; i < count; i++) {
            if (i != cur && tw->unk_F4[i].unk4 < y) {
                break;
            }
        }
        if (i != count) {
            for (i = 0; i < count; i++) {
                if (i != cur && tw->unk_F4[i].unk4 < y) {
                    dy = y - tw->unk_F4[i].unk4;
                    if (dy <= bestDy) {
                        if (dy < bestDy) {
                            bestDx = 100000.0f;
                        }
                        dx = x - tw->unk_F4[i].unk2;
                        d2 = dx * dx;
                        if (d2 < bestDx) {
                            bestDy = dy;
                            bestDx = d2;
                            sel = i;
                        }
                    }
                }
            }
        } else {
            best = -1000;
            for (i = 0; i < count; i++) {
                if (i != cur && tw->unk_F4[i].unk4 > best) {
                    best = tw->unk_F4[i].unk4;
                }
            }
            bestDx = 100000.0f;
            for (i = 0; i < count; i++) {
                if (i != cur && tw->unk_F4[i].unk4 == best) {
                    dx = x - tw->unk_F4[i].unk2;
                    d2 = dx * dx;
                    if (d2 < bestDx) {
                        bestDx = d2;
                        sel = i;
                    }
                }
            }
        }
        break;
    case 2:
        for (i = 0; i < count; i++) {
            if (i != cur && tw->unk_F4[i].unk4 == y && x < tw->unk_F4[i].unk2) {
                break;
            }
        }
        if (i != count) {
            for (i = 0; i < count; i++) {
                if (i != cur && tw->unk_F4[i].unk4 == y && x < tw->unk_F4[i].unk2) {
                    d = tw->unk_F4[i].unk2 - x;
                    if (d < bestDy) {
                        bestDy = d;
                        sel = i;
                    }
                }
            }
        } else {
            best = 1000;
            for (i = 0; i < count; i++) {
                if (i != cur && tw->unk_F4[i].unk4 == y && tw->unk_F4[i].unk2 < best) {
                    best = tw->unk_F4[i].unk2;
                    sel = i;
                }
            }
        }
        break;
    case 3:
        for (i = 0; i < count; i++) {
            if (i != cur && y < tw->unk_F4[i].unk4) {
                break;
            }
        }
        if (i != count) {
            for (i = 0; i < count; i++) {
                if (i != cur && y < tw->unk_F4[i].unk4) {
                    dy = tw->unk_F4[i].unk4 - y;
                    if (dy <= bestDy) {
                        if (dy < bestDy) {
                            bestDx = 100000.0f;
                        }
                        dx = x - tw->unk_F4[i].unk2;
                        d2 = dx * dx;
                        if (d2 < bestDx) {
                            bestDy = dy;
                            bestDx = d2;
                            sel = i;
                        }
                    }
                }
            }
        } else {
            best = 1000;
            for (i = 0; i < count; i++) {
                if (i != cur && tw->unk_F4[i].unk4 < best) {
                    best = tw->unk_F4[i].unk4;
                }
            }
            bestDx = 100000.0f;
            for (i = 0; i < count; i++) {
                if (i != cur && tw->unk_F4[i].unk4 == best) {
                    dx = x - tw->unk_F4[i].unk2;
                    d2 = dx * dx;
                    if (d2 < bestDx) {
                        bestDx = d2;
                        sel = i;
                    }
                }
            }
        }
        break;
    }
    if (tw->unk_11 != sel) {
        sub = &tw->unk_F4[tw->unk_11];
        tw->unk_11 = sel;
        tw->unk_6E = 3;
        tw->unk_70 = sub->unk2 - 12;
        tw->unk_72 = sub->unk4 + 8;
        sub = &tw->unk_F4[sel];
        tw->unk_74 = sub->unk2 - 12;
        tw->unk_76 = sub->unk4 + 8;
        tw->unk_78 = 0;
        PlaySound(0xF5);
    }
    cancel = (tw->unk_06 & 1) ? 0 : 0x4000;
    if (btn & 0x8000) {
        if (tw->unk_F4[tw->unk_11].unk0 == 2) {
            PlaySound(0xF9);
            return 1;
        }
        tw->unk_6E = 4;
        tw->unk_78 = 0;
        PlaySound(0xF7);
        return 0;
    }
    if (btn & cancel) {
        tw->unk_6E = 0;
        tw->unk_78 = 0;
        tw->unk_11 = -1;
        PlaySound(0xF8);
        return 0;
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/6D4E0", func_8006FE4C);
#endif
void func_8007094C(TextWindow* tw, SubTextWindow* sub) {
    f32 sy;
    f32 sx;
    f32 px;
    f32 py;
    f32 dx;
    f32 dy;
    f32 len;
    f32 mx;
    f32 my;

    sy = 1.0f;
    px = sub->unk2 - 12;
    py = sub->unk4 + 8;
    sx = sy;
    switch (tw->unk_6E) {
    case 0:
        if (tw->unk_42 != -1) {
            func_800674BC(tw->unk_44, 11, 0x8000);
        }
        return;
    case 1:
        sx = sy = tw->unk_78 / 8.0f;
        if (++tw->unk_78 >= 8) {
            tw->unk_78 = 0;
            tw->unk_6E = 2;
        }
        break;
    case 3:
        tw->unk_78++;
        dx = tw->unk_74 - tw->unk_70;
        dy = tw->unk_76 - tw->unk_72;
        len = func_800B1750(dx * dx + dy * dy);
        mx = dx / len * 10.0f * tw->unk_78;
        my = dy / len * 10.0f * tw->unk_78;
        dx = tw->unk_70 + mx - tw->unk_74;
        dy = tw->unk_72 + my - tw->unk_76;
        if (dx * dx + dy * dy < 100.0f) {
            px = tw->unk_74;
            py = tw->unk_76;
            tw->unk_78 = 0;
            tw->unk_6E = 2;
        } else {
            px = tw->unk_70 + mx;
            py = tw->unk_72 + my;
        }
        break;
    case 2:
        tw->unk_78 = tw->unk_78 + 10.0f;
        if (tw->unk_78 >= 181) {
            tw->unk_78 = 0;
        }
        px += func_800AEAC0(tw->unk_78) * 4.0f;
        break;
    case 4:
        if (tw->unk_78 >= 11) {
            sx = sy = 4.0f / 3.0f;
        } else {
            sx = sy = ++tw->unk_78 / 30.0f + 1.0f;
        }
        break;
    case 5:
        if (--tw->unk_78 == 0) {
            tw->unk_78 = 0;
            tw->unk_6E = 2;
        }
        break;
    }
    if (sx == 0.0f || sy == 0.0f) {
        func_800674BC(tw->unk_44, 11, 0x8000);
        return;
    }
    dy = 0.8f;
    dx = sx * dy;
    func_80067354(tw->unk_44, 11, dx * tw->unk_EC, (dy = sy * dy) * tw->unk_F0);
    dx = px / dx * tw->unk_EC;
    func_80066DC4(tw->unk_44, 11, dx, dy = py / dy * tw->unk_F0);
    func_80067480(tw->unk_44, 11, 0x8000);
}
void func_80070D90(s16 arg0) {
    TextWindow* tw = &D_800ED4B0[arg0];
    s16 i;

    if (tw->string != NULL && tw->usingStringIDBool != 0) {
        func_8005B838(tw->string);
    }
    for (i = 0; i < 10; i++) {
        if (tw->unk_88[i] != NULL && tw->unk_7B[i] != 0) {
            func_8005B838(tw->unk_88[i]);
        }
    }
    func_80064D38(tw->unk_44);
    func_80067704(tw->unk_3E);
    func_80067704(tw->unk_40);
    if (tw->unk_42 != -1) {
        func_80067704(tw->unk_42);
    }
    tw->unk_36 = -1;
    D_800ED4B0[tw->unk_3C].unk_3A = tw->unk_3A;
    D_800ED4B0[tw->unk_3A].unk_3C = tw->unk_3C;
}
void func_80070ED4(void) {
    s16 id;

    if (D_800C5DF1 != 0) {
        id = D_800ED4B0[0].unk_3C;
        while (D_800ED4B0[id].unk_3C != -1) {
            func_80070D90(id);
            id = D_800ED4B0[id].unk_3C;
        }
        DataCloseTemp(D_800F37D4);
        DataCloseTemp(D_800F3294);
        DataCloseTemp(D_800F3F34);
        DataCloseTemp(D_800F3F38);
        FreeTemp(D_800ED4B0);
        EndProcess(D_800F2BC4);
        D_800C5DF1 = 0;
    }
}
void func_80070FF8(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4) {
    func_800710E4(-(~arg0 == 0), -(~arg1 == 0), -(~arg2 == 0), -(~arg3 == 0), arg4);
    func_800710E4(arg0, arg1, arg2, arg3, 1);
}

void func_800710A4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_800710E4(arg0, arg1, arg2, arg3, 1);
}

void func_800710E4(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    D_800EE1D0[D_800F3718].v[0] = arg0;
    D_800EE1D2[D_800F3718].v[0] = arg1;
    D_800EE1D4[D_800F3718].v[0] = arg2;
    D_800EE1D6[D_800F3718].v[0] = arg3;
    D_800EE1D8[D_800F3718].v[0] = arg4;
    D_800F3718 = (D_800F3718 + 1) & 0x1F;
}
void func_80071154(s16* arg0) {
    s16 i;

    if (D_800F64C4 == D_800F3718) {
        arg0[0] = arg0[1] = arg0[2] = arg0[3] = 0;
        return;
    }
    for (i = 0; i < 4; i++) {
        arg0[i] = (D_800EE1D0 + D_800F64C4)->v[i];
        if (arg0[i] == -1) {
            arg0[i] = D_800F2CF0[i];
        }
    }
    D_800EE1D8[D_800F64C4].v[0]--;
    if (D_800EE1D8[D_800F64C4].v[0] == 0) {
        D_800F64C4 = (D_800F64C4 + 1) & 0x1F;
    }
}
void func_80071264(void) {
    D_800F3718 = 0;
    D_800F64C4 = 0;
}

s16 func_80071278(TextWindow* tw) {
    u16 sp10[4];
    s16 btn = 0;

    if (tw->unk_06 & 2) {
        func_80071154((s16*)sp10);
    }
    if (tw->unk_01 & 1) {
        if (tw->unk_06 & 2) {
            btn |= sp10[0];
        } else {
            btn |= (D_800F2CF0[0] & 0x3FFF) | (ContDStkTrg[0] & 0xC000);
        }
    }
    if (tw->unk_01 & 2) {
        if (tw->unk_06 & 2) {
            btn |= sp10[1];
        } else {
            btn |= (D_800F2CF2 & 0x3FFF) | (D_800EC6EC & 0xC000);
        }
    }
    if (tw->unk_01 & 4) {
        if (tw->unk_06 & 2) {
            btn |= sp10[2];
        } else {
            btn |= (D_800F2CF4 & 0x3FFF) | (D_800EC6EE & 0xC000);
        }
    }
    if (tw->unk_01 & 8) {
        if (tw->unk_06 & 2) {
            btn |= sp10[3];
        } else {
            btn |= (D_800F2CF6 & 0x3FFF) | (D_800EC6F0 & 0xC000);
        }
    }
    return btn;
}
u8 func_800713F0(u8* arg0) {
    s16 row;
    s16 col;

    for (row = 0; row < 16; row++) {
        for (col = 0; col < 32; col += 2) {
            if (D_800C6048[row][col] == arg0[0] && D_800C6048[row][col + 1] == arg0[1]) {
                return col / 2 + row * 16;
            }
        }
    }
    return 16;
}
u8 func_800713F0(u8*);

void func_8007149C(u8* arg0, u8* arg1) {
    for (; *arg1 != 0; arg0++, arg1 += 2) {
        *arg0 = func_800713F0(arg1);
    }
    *arg0 = 0;
}

void func_800714F0(s16 arg0, u8 arg1, u8 arg2, u8 arg3) {
    TextWindow* textWindow = &D_800ED4B0[arg0];
    
    textWindow->unk_0D = arg1;
    textWindow->unk_0E = arg2;
    textWindow->unk_0F = arg3;
    func_800674F4(textWindow->unk_44, 0, arg1, arg2, arg3);
}

void func_8007155C(s16 arg0, s32 arg1) {
    TextWindow* temp_v1 = &D_800ED4B0[arg0];

    temp_v1->unk_01 = (temp_v1->unk_01 & 0xF0) | arg1;
}

void func_80071598(s16 arg0) {
    TextWindow* textWindow = &D_800ED4B0[arg0];
    s16 i;

    for (i = 0; i < 10; i++) {
        if (textWindow->unk_C0[i] != NULL) {
            func_800674BC(textWindow->unk_44, i, 0x8000);
        }
    }
    
    if (textWindow->unk_E8 != NULL) {
        func_800674BC(textWindow->unk_44, 0xA, 0x8000);
    }
    
    if (textWindow->unk_42 != -1) {
        func_800674BC(textWindow->unk_44, 0xB, 0x8000);
    }
    
    textWindow->unk_06 |= 8;
}

void func_8007166C(s16 arg0) {
    TextWindow* textWindow = &D_800ED4B0[arg0];
    s16 i;

    for (i = 0; i < 10; i++) {
        if (textWindow->unk_C0[i] != NULL) {
            func_80067480(textWindow->unk_44, i, 0x8000);
        }
    }
    
    if (textWindow->unk_E8 != NULL) {
        func_80067480(textWindow->unk_44, 0xA, 0x8000);
    }
    
    if (textWindow->unk_42 != -1) {
        func_80067480(textWindow->unk_44, 0xB, 0x8000);
    }
    
    textWindow->unk_06 &= ~0x8;
}

void func_80071740(s16 arg0, s32 arg1) {
    TextWindow* textWindow = &D_800ED4B0[arg0];

    if (arg1 != 0) {
        textWindow->unk_06 |= 0x10;
    } else {
        textWindow->unk_06 &= ~0x10;
    }
}

void func_80071788(s32 arg0, s16 arg1) {
    TextWindow* textWindow = &D_800ED4B0[arg0];
    textWindow->unk_F4[arg1].unk0 = 2;
}


void func_800717C0(s32 arg0) {
    TextWindow* tw = &D_800ED4B0[arg0];
    s16 sprId = tw->unk_44;
    s16 i;

    for (i = 0; i < 10; i++) {
        func_800674F4(sprId, i, D_800C5E14[i].r, D_800C5E15[i].r, D_800C5E16[i].r);
    }
}
s16 func_8007186C(s32 arg0) {
    return D_800ED4B0[arg0].unk_11;
}

void func_80071894(u8* arg0, u8* arg1) {
    while (*arg0 != 0) {
        if (*arg0 == 10) {
            arg0++;
        } else {
            *arg1++ = *arg0++;
        }
    }
    *arg1 = *arg0;
}
void func_800718DC(s16 arg0, void* arg1, s8 arg2) {
    TextWindow* tw = &D_800ED4B0[arg0];

    func_8006DA5C(arg0, arg1, arg2);
    func_80071894(tw->unk_88[arg2], tw->unk_88[arg2]);
}
s32 func_8007194C(s32 arg0, s32 arg1, s32 arg2) {
    TWStyle* style = &D_800C6088[arg2 - 2];
    TextWindow* tw;
    TWSprite* spr;
    s32 id;
    s32 sub;
    s32 i;

    id = func_8006D010(arg0, arg1, style->width, style->height, 0, 0);
    func_8006E070(id, 0);
    tw = &D_800ED4B0[id];
    tw->unk_2C = tw->unk_24 = style->textX;
    tw->unk_2E = tw->unk_26 = style->textY;
    tw->unk_28 = style->textW;
    tw->unk_2A = style->textH;
    func_8006DEC8(id, style->offsetX, style->offsetY);
    tw->unk_30 = tw->unk_2C + style->textW - tw->unk_07;
    tw->unk_32 = tw->unk_2E + style->textH - tw->unk_08;
    if (arg2 == 5) {
        tw->unk_09 = 0;
    }
    tw->unk_274 = sub = func_8006DB3C(id, style->frame, 0, 0, 0);
    func_80067384(tw->unk_44, sub, 15000);
    func_80066DC4(tw->unk_44, sub, 0, 0);
    func_80067354(tw->unk_44, sub, 0.0f, 0.0f);
    spr = func_800675F4(tw->unk_44, sub);
    for (i = 0; i < spr->unk_4C->count; i++) {
        spr->unk_4C->frames[i].unk8 = style->offsetX;
        spr->unk_4C->frames[i].unkA = style->offsetY;
    }
    tw->unk_276 = sub = func_8006DB3C(id, style->cursor, 0, 0, 0);
    func_80067384(tw->unk_44, sub, 15000);
    func_80066DC4(tw->unk_44, sub, 0, 0);
    func_80067354(tw->unk_44, sub, 0.0f, 0.0f);
    func_800674BC(tw->unk_44, tw->unk_276, 0x1000);
    func_8006752C(tw->unk_44, tw->unk_276, 0xFF);
    func_800674F4(tw->unk_44, tw->unk_276, 0xFF, 0xD3, 0x4F);
    spr = func_800675F4(tw->unk_44, sub);
    for (i = 0; i < spr->unk_4C->count; i++) {
        spr->unk_4C->frames[i].unk8 = style->offsetX;
        spr->unk_4C->frames[i].unkA = style->offsetY;
    }
    func_8006E154(id, 0);
    func_8006E2B8(id, 0xC0, 0xC0, 0xC0);
    func_8006E288(id, style->color);
    tw->unk_12 = style->color;
    func_8006DE20(id, 0.0f, 0.0f);
    return id;
}
void func_80071C8C(s32 a, s32 b) {
    TextWindow* tw = &D_800ED4B0[a];
    f32 scale;

    func_80071740(a, 1);
    if (b != 0) {
        PlaySound(0x3A);
    }
    for (scale = 0.0f; scale <= 1.0f; scale += 0.1f) {
        func_80067354(tw->unk_44, tw->unk_274, scale, scale);
        func_80067354(tw->unk_44, tw->unk_276, scale, scale);
        func_8006DE20(a, scale, scale);
        HuPrcVSleep();
    }
    func_80067354(tw->unk_44, tw->unk_274, 1.0f, 1.0f);
    func_80067354(tw->unk_44, tw->unk_276, 1.0f, 1.0f);
    func_8006DE20(a, 1.0f, 1.0f);
    func_80071740(a, 0);
}
void func_80071DE0(s32 arg0) {
    TextWindow* tw = &D_800ED4B0[arg0];

    func_80071740(arg0, 1);
    func_80067354(tw->unk_44, tw->unk_274, 1.0f, 1.0f);
    func_80067354(tw->unk_44, tw->unk_276, 1.0f, 1.0f);
    func_8006DE20(arg0, 1.0f, 1.0f);
    func_80071740(arg0, 0);
}
void func_80071E80(s32 a, s32 b) {
    TextWindow* tw = &D_800ED4B0[a];
    f32 scale = 1.0f;

    func_80071740(a, 1);
    if (b != 0) {
        PlaySound(0x3B);
    }
    while (scale > 0.0f) {
        func_80067354(tw->unk_44, tw->unk_274, scale, scale);
        func_80067354(tw->unk_44, tw->unk_276, scale, scale);
        func_8006DE20(a, scale, scale);
        scale -= 0.1f;
        HuPrcVSleep();
    }
    func_80067354(tw->unk_44, tw->unk_274, scale, scale);
    func_80067354(tw->unk_44, tw->unk_276, scale, scale);
    func_8006DE20(a, scale, scale);
    func_80071740(a, 0);
}
void func_80071FF4(s32 arg0, u8 arg1) {
    TextWindow* tw = &D_800ED4B0[arg0];

    func_800674BC(tw->unk_44, tw->unk_274, 0x1000);
    func_8006752C(tw->unk_44, tw->unk_274, arg1);
    func_800674BC(tw->unk_44, tw->unk_276, 0x1000);
    func_8006752C(tw->unk_44, tw->unk_276, arg1);
}
void func_80072080(s32 arg0) {
    TextWindow* tw = &D_800ED4B0[arg0];

    func_80067704(func_8006DD8C(arg0, tw->unk_274));
    func_80067704(func_8006DD8C(arg0, tw->unk_276));
    func_80070D90(arg0);
}
void func_80072108(s16 arg0, s16 arg1) {
    TextWindow* tw = &D_800ED4B0[arg0];

    func_8006E0A4(arg0, arg1);
    func_80067384(tw->unk_44, tw->unk_274, arg1 + 1);
    func_80067384(tw->unk_44, tw->unk_276, arg1 + 1);
}
/* Name-entry character rows (16 Shift-JIS characters each), indexed through D_800C6048. */
const char D_800CB750[] = "\x83\x7E\x83\x80\x83\x81\x83\x82\x83\x84\x83\x86\x83\x88\x83\x89\x83\x8A\x83\x8B\x83\x8C\x83\x8D\x83\x8F\x83\x93\x81\x63\x81\xA5";
const char D_800CB774[] = "\x83\x5E\x83\x60\x83\x63\x83\x65\x83\x67\x83\x69\x83\x6A\x83\x6B\x83\x6C\x83\x6D\x83\x6E\x83\x71\x83\x74\x83\x77\x83\x7A\x83\x7D";
const char D_800CB798[] = "\x81\xA6\x83\x41\x83\x43\x83\x45\x83\x47\x83\x49\x83\x4A\x83\x4C\x83\x4E\x83\x50\x83\x52\x83\x54\x83\x56\x83\x58\x83\x5A\x83\x5C";
const char D_800CB7BC[] = "\x81\x75\x81\x76\x81\x49\x81\x48\x81\xF2\x81\xF3\x83\x92\x83\x40\x83\x42\x83\x44\x83\x46\x83\x48\x83\x83\x83\x85\x83\x87\x83\x62";
const char D_800CB7E0[] = "\x82\xDD\x82\xDE\x82\xDF\x82\xE0\x82\xE2\x82\xE4\x82\xE6\x82\xE7\x82\xE8\x82\xE9\x82\xEA\x82\xEB\x82\xED\x82\xF1\x81\xA6\x81\xA6";
const char D_800CB804[] = "\x82\xBD\x82\xBF\x82\xC2\x82\xC4\x82\xC6\x82\xC8\x82\xC9\x82\xCA\x82\xCB\x82\xCC\x82\xCD\x82\xD0\x82\xD3\x82\xD6\x82\xD9\x82\xDC";
const char D_800CB828[] = "\x81\xA6\x82\xA0\x82\xA2\x82\xA4\x82\xA6\x82\xA8\x82\xA9\x82\xAB\x82\xAD\x82\xAF\x82\xB1\x82\xB3\x82\xB5\x82\xB7\x82\xB9\x82\xBB";
const char D_800CB84C[] = "\x81\x4A\x81\x8B\x81\x41\x81\x42\x81\x5B\x81\x44\x82\xF0\x82\x9F\x82\xA1\x82\xA3\x82\xA5\x82\xA7\x82\xE1\x82\xE3\x82\xE5\x82\xC1";
const char D_800CB870[] = "\x82\x90\x82\x91\x82\x92\x82\x93\x82\x94\x82\x95\x82\x96\x82\x97\x82\x98\x82\x99\x82\x9A\x81\xA6\x81\xA6\x81\xA6\x81\xA6\x81\xA6";
const char D_800CB894[] = "\x81\xA6\x82\x81\x82\x82\x82\x83\x82\x84\x82\x85\x82\x86\x82\x87\x82\x88\x82\x89\x82\x8A\x82\x8B\x82\x8C\x82\x8D\x82\x8E\x82\x8F";
const char D_800CB8B8[] = "\x82\x6F\x82\x70\x82\x71\x82\x72\x82\x73\x82\x74\x82\x75\x82\x76\x82\x77\x82\x78\x82\x79\x81\x68\x81\x66\x81\xA6\x81\xA6\x81\xA6";
const char D_800CB8DC[] = "\x81\xA6\x82\x60\x82\x61\x82\x62\x82\x63\x82\x64\x82\x65\x82\x66\x82\x67\x82\x68\x82\x69\x82\x6A\x82\x6B\x82\x6C\x82\x6D\x82\x6E";
const char D_800CB900[] = "\x82\x4F\x82\x50\x82\x51\x82\x52\x82\x53\x82\x54\x82\x55\x82\x56\x82\x57\x82\x58\x81\x9B\x81\x99\x81\x7B\x81\x7C\x81\x7E\x81\xA8";
const char D_800CB924[] = "\x81\xA6\x83\xBF\x83\xC0\x87\x85\x87\x89\x87\x88\x87\x87\x83\xA4\x81\xA7\x81\x9C\x81\x9A\x8E\x6E\x89\x45\x81\xA6\x81\xA6\x81\xA6";
const char D_800CB948[] = "\x81\x40\x87\x40\x87\x41\x87\x42\x87\x43\x87\x44\x87\x45\x87\x46\x87\x47\x87\x48\x87\x49\x81\xA6\x81\xA6\x81\xA6\x81\xA6\x81\xA6";
const char D_800CB96C[] = "\x8F\x49\x8D\x95\x90\xC2\x90\xD4\x8E\x87\x97\xCE\x90\x85\x89\xA9\x94\x92\x8C\xF5\x8D\x73\x95\xC5\x81\x83\x81\x84\x81\xA6\x81\xA6";
