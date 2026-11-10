#include "common.h"
#include "engine/esprite.h"

typedef struct SpritePalette {
    /* 0x00 */ u8 unk_00[0xC];
    /* 0x0C */ u16* colors;
    /* 0x10 */ u8 unk_10[0xA];
    /* 0x1A */ u8 count;
} SpritePalette;
extern SpritePalette* D_800EC700[];


extern u16 D_800EC6DC;
extern u16 D_800ECB38;
extern u16 D_800F527A;
void func_80064B70(void);
void func_80068398(void);
void func_80066DC4(s16, s16, s16, s16);
void func_80067284(s16, s16, f32);
s32 func_80067328(s16, s16);


void func_80018870(void) {
    u16 i;
    unkSpriteStruct* sprite;

    func_80064B70();
    D_800ED60C = func_80023668(0x100 * sizeof(*D_800ED60C));
    D_800EC6DC = 0x100;
    D_800ECB38 = 0;
    for (i = 0; i < 0x100; i++) {
        sprite = &D_800ED60C[i];
        sprite->unk_00 = 0;
        sprite->unk_02 = i + 1;
        sprite->unk_1C = 0xFF;
        sprite->unk_1E = 0xFF;
        sprite->unk_20 = 0;
    }
    D_800F527A = 0;
    D_800F6530 = 0;
}
s32 InitSprite(s32 arg0) {
    s16 temp_s0;
    void* temp_s1;

    temp_s1 = DataRead(arg0);
    temp_s0 = func_800678A4(temp_s1);
    D_800ED198[D_800F6530++] = temp_s0;
    HuMemDirectFree(temp_s1);
    return temp_s0;
}

// Scales each RGBA5551 palette entry's colour channels. Register allocation differs (masked 5).
#ifdef NON_MATCHING
void func_8001897C(s16 arg0, f32 r, f32 g, f32 b) {
    SpritePalette* pal = D_800EC700[arg0];
    u16* color = pal->colors;
    s32 i;

    for (i = 0; i < pal->count; i++) {
        u16 g5 = (*color >> 6) & 0x1F;
        u16 b5 = (*color >> 1) & 0x1F;
        u16 a1 = *color & 1;
        u32 r2 = (*color >> 11) * r;
        u32 g2 = g5 * g;
        u32 b2 = b5 * b;

        *color = a1 | ((r2 << 11) | (g2 << 6) | (b2 << 1));
        color++;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/engine/esprite", func_8001897C);
#endif
void func_80018AFC(void) {
    func_80068398();
    func_80023728(D_800ED60C);
    D_800ED60C = NULL;
}
// Logic-equivalent; GCC schedules the two clamp branches differently (masked ~33).
#ifdef NON_MATCHING
void func_80018B2C(void) {
    s32 i;
    s16 id;
    unkSpriteStruct* sprite;

    if (D_800ED60C != NULL) {
        for (i = 0; i < D_800EC6DC; i++) {
            sprite = &D_800ED60C[i];
            if (sprite->unk_00 & 1) {
                id = sprite->unk_04;
                func_80066DC4(id, 0, sprite->unk_0A, sprite->unk_0C);
                if (sprite->unk_00 & 2) {
                    func_8006752C(id, 0, sprite->unk_1E);
                    sprite->unk_1E += sprite->unk_20;
                    if (sprite->unk_20 > 0) {
                        if (sprite->unk_1C < sprite->unk_1E) {
                            sprite->unk_1E = sprite->unk_1C;
                        }
                    } else {
                        if (sprite->unk_1E < sprite->unk_1C) {
                            sprite->unk_1E = sprite->unk_1C;
                        }
                    }
                    if (sprite->unk_1E == sprite->unk_1C) {
                        sprite->unk_00 &= ~2;
                    }
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/engine/esprite", func_80018B2C);
#endif
void ShowBasicSprite(s32 arg0) {
    func_80067480(D_800ED60C[arg0 & 0xFFFF].unk_04, 0, 0x8000);
        //[arg0 & 0xFFFF] required to match for other calls to this function
        //perhaps an implicit declaration
}

void func_80018C90(u16 arg0) {
    func_800674BC(D_800ED60C[arg0].unk_04, 0, 0x8000);
}
void SetBasicSpritePos(s32 arg0, s16 arg1, s16 arg2) {
    unkSpriteStruct* spriteInstance = &D_800ED60C[arg0 & 0xFFFF];
        //[arg0 & 0xFFFF] required to match for other calls to this function
        //perhaps an implicit declaration

    spriteInstance->unk_0A = arg1;
    spriteInstance->unk_0C = arg2;
}

void func_80018CF8(s32 arg0, s32 arg1) {
    s32 v;
    unkSpriteStruct* sprite = &D_800ED60C[arg0 & 0xFFFF];

    v = sprite->unk_1E = arg1;
    sprite->unk_1C = v;
    v = arg1;
    func_8006752C(sprite->unk_04, 0, v);
}
void func_80018D44(s32 arg0, s32 arg1) {
    unkSpriteStruct* sprite = &D_800ED60C[arg0 & 0xFFFF];

    func_800674BC(sprite->unk_04, 0, arg1 & 0xFFFF);
}
void func_80018D84(u16 arg0, s32 arg1) {
    unkSpriteStruct* sprite = &D_800ED60C[arg0];

    func_80067384(sprite->unk_04, 0, arg1);
}
void func_80018DC4(u16 arg0, f32 arg1) {
    unkSpriteStruct* sprite = &D_800ED60C[arg0];

    func_80067284(sprite->unk_04, 0, arg1);
}
void func_80018E0C(u16 arg0, s16 arg1) {
    unkSpriteStruct* sprite = &D_800ED60C[arg0];

    func_800671DC(sprite->unk_04, 0, arg1);
}
void func_80018E50(s32 arg0, u16 arg1, s32 arg2) {
    unkSpriteStruct* sprite = &D_800ED60C[arg0 & 0xFFFF];

    func_800672DC(sprite->unk_04, 0, arg1, arg2 & 0xFFFF);
}
void func_80018E98(u16 arg0, u16 arg1) {
    unkSpriteStruct* sprite = &D_800ED60C[arg0];

    func_800672B0(sprite->unk_04, 0, arg1);
}
u8 func_80018ED8(u16 arg0) {
    unkSpriteStruct* sprite = &D_800ED60C[arg0];

    return func_80067328(sprite->unk_04, 0);
}
void SetBasicSpriteSize(u16 arg0, f32 arg1, f32 arg2) {
    unkSpriteStruct* spriteInstance = &D_800ED60C[arg0];
    
    func_80067354(spriteInstance->unk_04, 0, arg1, arg2);
}

void func_80018F68(u16 arg0, u8 arg1, u8 arg2, u8 arg3) {
    unkSpriteStruct* sprite = &D_800ED60C[arg0];

    func_800674F4(sprite->unk_04, 0, arg1, arg2, arg3);
}
void func_80018FBC(u16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    unkSpriteStruct* sprite = &D_800ED60C[arg0];

    sprite->unk_00 |= 2;
    sprite->unk_1C = arg1;
    if (arg2 > 0) {
        sprite->unk_1E = arg2;
    }
    sprite->unk_20 = arg3;
}
void func_80019000(u16 arg0, s16 arg1) {
    unkSpriteStruct* sprite = &D_800ED60C[arg0];

    sprite->unk_00 &= ~2;
    if (arg1 > 0) {
        sprite->unk_1C = sprite->unk_1E = arg1;
        func_8006752C(sprite->unk_04, 0, arg1);
    }
}
s32 func_80019060(s32 arg0, s16 arg1, u16 arg2) {
    s16 index;
    s16 id;
    unkSpriteStruct* sprite;

    if (D_800ECB38 == D_800EC6DC) {
        return -1;
    }
    D_800ECB38++;
    index = D_800F527A;
    sprite = &D_800ED60C[index];
    D_800F527A = sprite->unk_02;
    id = func_80064EF4(1, 0);
    sprite->unk_04 = id;
    sprite->unk_00 |= 1;
    sprite->unk_06 = arg0;
    sprite->unk_10 = sprite->unk_14 = 1.0f;
    func_8006752C(id, 0, 0xFF);
    func_80067480(id, 0, 0xFFFF);
    func_800674BC(id, 0, 0x1000);
    func_80067354(id, 0, 1.0f, 1.0f);
    func_800672B0(id, 0, arg2);
    func_80067208(id, 0, arg0, arg1);
    func_80067384(id, 0, 10);
    if (arg2 == 0) {
        func_800671DC(id, 0, 0);
    }
    return index;
}
void func_800191F8(u16 arg0) {
    unkSpriteStruct* sprite = &D_800ED60C[arg0];

    if (sprite->unk_00 & 1) {
        func_80064D38(sprite->unk_04);
        sprite->unk_00 = 0;
        sprite->unk_02 = D_800F527A;
        D_800F527A = arg0;
    }
}