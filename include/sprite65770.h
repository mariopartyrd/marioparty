#ifndef SPRITE65770_H
#define SPRITE65770_H

/* The sprite system's objects and animations (src/65770.c), shared with the overlays that reach
   into them, so every user has the real layout (pointer fields are wider on the host). */
#include "common.h"

typedef struct unk65770Obj {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ u16 unk10;
    /* 0x12 */ char pad12[2];
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ u8 unk24;
    /* 0x25 */ u8 unk25;
    /* 0x26 */ u8 unk26;
    /* 0x27 */ char pad27[1];
    /* 0x28 */ s16 unk28;
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ f32 unk30;
    /* 0x34 */ s16 unk34;
    /* 0x36 */ s16 unk36;
    /* 0x38 */ s16 unk38;
    /* 0x3A */ s16 unk3A;
    /* 0x3C */ s16 unk3C;
    /* 0x3E */ s16 unk3E;
    /* 0x40 */ s16 unk40;
    /* 0x42 */ s16 unk42;
    /* 0x44 */ f32 unk44;
    /* 0x48 */ s32 unk48;
    /* 0x4C */ struct unk65770Anim* unk4C;
    /* 0x50 */ s16 unk50;
    /* 0x52 */ s16 unk52;
    /* 0x54 */ u8 unk54;
    /* 0x55 */ u8 unk55;
    /* 0x56 */ u8 unk56;
    /* 0x57 */ char pad57[1];
    /* 0x58 */ f32 unk58;
    /* 0x5C */ u8 unk5C;
    /* 0x5D */ char pad5D[1];
    /* 0x5E */ s16 unk5E;
    /* 0x60 */ s16 unk60;
    /* 0x62 */ char pad62[2];
    /* 0x64 */ struct unk65770Obj* unk64;
    /* 0x68 */ struct unk65770Obj* unk68;
} unk65770Obj; // sizeof 0x6C

typedef struct unk65770AnimC {
    /* 0x00 */ u8* unk0;
    /* 0x04 */ u16 unk4;
    /* 0x06 */ u16 unk6;
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
} unk65770AnimC; // sizeof 0xC

typedef struct unk65770Key {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
    /* 0x07 */ char pad7[1];
} unk65770Key; // sizeof 0x8

typedef struct unk65770Anim8 {
    /* 0x00 */ u16 unk0;
    /* 0x02 */ char pad2[2];
    /* 0x04 */ unk65770Key* unk4;
} unk65770Anim8; // sizeof 0x8

typedef struct unk65770Anim {
    /* 0x00 */ unk65770AnimC* unk0;
    /* 0x04 */ unk65770Anim8** unk4;
    /* 0x08 */ u8* unk8;
    /* 0x0C */ void* unkC;
    /* 0x10 */ u16 unk10;
    /* 0x12 */ u16 unk12;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ u16 unk18;
    /* 0x1A */ u8 unk1A;
} unk65770Anim; // sizeof 0x1C

typedef struct unk65770Grp {
    /* 0x00 */ struct unk65770Grp* prev;
    /* 0x04 */ struct unk65770Grp* next;
    /* 0x08 */ u16 unk8;
    /* 0x0A */ u16 count;
    /* 0x0C */ unk65770Obj* obj[1];
} unk65770Grp;

extern unk65770Grp* D_800EE330[256];

unk65770Obj* func_800675F4(s16 grpIdx, s16 idx);

#endif
