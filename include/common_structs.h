#ifndef _COMMON_STRUCTS_
#define _COMMON_STRUCTS_

#include "types.h"
#include "engine/math.h"
#include "PR/mbi.h"

typedef struct Vec2f {
               f32 x;
               f32 y;
} Vec2f;

typedef struct Vec2s {
               s16 x;
               s16 y;
} Vec2s;

typedef struct {
    u16 x, y;
} Vec2hu;

typedef struct Vec2w {
               s32 x;
               s32 y;
} Vec2w;

typedef struct Vec3f {
               f32 x;
               f32 y;
               f32 z;
} Vec3f;

typedef struct Vec {
               f32 x;
               f32 y;
               f32 z;
} Vec;

typedef struct Vec3s {
               s32 x;
               s32 y;
               s32 z;
} Vec3s;

typedef struct Vec4f {
               f32 x;
               f32 y;
               f32 z;
               f32 w;
} Vec4f;

typedef struct Color_RGB8 {
    /* 0x00 */ u8 r;
    /* 0x01 */ u8 g;
    /* 0x02 */ u8 b;
} Color_RGB8; //sizeof 3

typedef struct unk_Struct01 {
    /* 0x00 */ u16 unk0;
    /* 0x02 */ char pad2[6];
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ char unk_14[4];
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ char unk_28[8];
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ char unk_34[0x1C];
    /* 0x50 */ volatile s32 unk_50;
    /* 0x54 */ u16 unk_54;
    /* 0x58 */ f32 unk_58;
    /* 0x5C */ f32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
} unk_Struct01;

typedef struct unkGlobalStruct_00 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ char unk_06[4];
    /* 0x0A */ u16 unk_0A;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
                union {
                    f32 floatingPoint;
                    u8 b[4];
                } unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ char unk_28[4];
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ char unk_44[8];
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ s16 unk_50;
    /* 0x52 */ s8 unk_52;
    /* 0x53 */ char unk_53[1];
    /* 0x54 */ u8 unk_54[2];
    /* 0x56 */ s8 unk_56;
    /* 0x57 */ s8 unk_57;
    /* 0x58 */ s8 unk_58;
    /* 0x59 */ char unk_59[3];
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ struct unkGlobalStruct_00* unk_68;
    /* 0x6C */ char unk_6C[0x14];

    /* 0x80 */ s32 unk80;
    /* 0x84 */ s32 unk84;
    /* 0x88 */ u16 unk88;
    /* 0x8A */ s16 unk8A;
    /* 0x8C */ s16 unk8C;
    /* 0x8E */ s16 unk8E;
    /* 0x90 */ s16 unk90;
    /* 0x92 */ s16 unk92;
    /* 0x94 */ char unk94[0x1A];
    /* 0xAE */ u16 unkAE;
    /* 0xB0 */ u16 unk_B0;
    /* 0xB2 */ char unk_B2[1];
    /* 0xB3 */ s8 unk_B3;
    /* 0xB4 */ char unk_B4[0x08];
    /* 0xBC */ f32 unk_BC;
    /* 0xC0 */ u16 unk_C0;
    /* 0xC2 */ char unk_C2[0x16];
    /* 0xD8 */ void* unk_D8; // possibly unkGlobalStruct_00*
    /* 0xDC */ s32 unk_DC;
    /* 0xE0 */ s32 unk_E0;
    /* 0xE4 */ unk_Struct01* unk_E4; // possibly void*
} unkGlobalStruct_00; /* size = 0xE8 */

typedef struct unkGlobalStruct_01 {
    /* 0x00 */ char unk_00[0x3C];
} unkGlobalStruct_01; //sizeof 0x3C

typedef struct unkGlobalStruct_02 {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ char unk_0C[0x1C];
    /* 0x28 */ unkGlobalStruct_01* unk_28;
} unkGlobalStruct_02; //sizeof 0x2C

typedef struct omObjData {
/* 0x00 */ u16 stat;
/* 0x02 */ s16 next_idx_alloc;
/* 0x04 */ s16 prio;
/* 0x06 */ s16 prev;
/* 0x08 */ s16 next;
/* 0x0A */ s16 next_idx;
/* 0x0C */ s16 group;
/* 0x0E */ s16 group_idx;
/* 0x10 */ s32 unk_10;
/* 0x14 */ void* func_ptr;
/* 0x18 */ Vec trans;
/* 0x24 */ Vec rot;
/* 0x30 */ Vec scale;
/* 0x3C */ u16 mdlcnt;
// /* 0x3E */ char unk_3E[2];
/* 0x40 */ s16* model;
/* 0x44 */ u16 mtncnt;
// /* 0x46 */ char unk_46[2];
/* 0x48 */ s16* motion;
/* 0x4C */ u8 work[4];
/* 0x50 */ void* unk_50;
} omObjData; //sizeof 0x54

typedef struct unkCommonStruct0 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x02 */ u8 unk_03;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ void* unk_10;
    /* 0x14 */ s16 unk_14[16];
    /* 0x34 */ s16 unk_34[16];
    /* 0x54 */ f32 unk_54;
    /* 0x58 */ f32 unk_58;
    /* 0x5C */ f32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
} unkCommonStruct0; //sizeof 0x68

typedef struct unkStructSize14 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ char unk_0C[8];
} unkStructSize14; //sizeof 0x14

typedef struct jump_buf
{
    void *sp;
    void *func;
    u32 regs[21];
} jmp_buf;

typedef void (*process_func)();

typedef struct Process {
/* 0x00 */ struct Process *next;
/* 0x04 */ struct Process *youngest_child;
/* 0x08 */ struct Process *oldest_child;
/* 0x0C */ struct Process *relative;
/* 0x10 */ struct Process *parent_oldest_child;
/* 0x14 */ struct Process *new_process;
/* 0x18 */ void *heap;
/* 0x1C */ u16 exec_mode;
/* 0x1E */ u16 stat;
/* 0x20 */ u16 priority;
/* 0x22 */ s16 dtor_idx;
/* 0x24 */ s32 sleep_time;
/* 0x28 */ void *base_sp;
/* 0x2C */ jmp_buf prc_jump;
/* 0x88 */ process_func destructor;
/* 0x8C */ void *user_data;
} Process; //sizeof 0x90

typedef struct ProcessHeader { //?
/* 0x00 */ struct Object* prev;
/* 0x04 */ Process* process;
/* 0x08 */ s16 unk_08;
/* 0x0A */ s16 unk_0A;
} ProcessHeader;

typedef struct unkProcessStruct {
           s16 unk0;
           s16 unk2;
           Process* processInstance;
           void (*unk8)();
} unkProcessStruct;

typedef struct unk_Struct00 {
    /* 0x000 */ Vec3f pos;
    /* 0x00C */ Vec3f unkC;
    /* 0x018 */ Vec3f unk18;
    /* 0x024 */ Vec3f unk24;
    /* 0x030 */ Vec3f unk30;
    /* 0x03C */ char pad3C[4];
    /* 0x040 */ f32 unk_40;
    /* 0x044 */ f32 unk_44;
    /* 0x048 */ f32 unk_48;
    /* 0x04C */ u16 unk4C;
    /* 0x04E */ s16 unk4E;
    /* 0x050 */ char pad50[8];
    /* 0x058 */ s16 unk58;
    /* 0x05A */ s16 unk5A;
    /* 0x05C */ s16 unk5C;
    /* 0x05E */ char unk5E[2];
    /* 0x060 */ s16 unk60;
    /* 0x062 */ s16 unk62;
    /* 0x064 */ s16 unk64;
    /* 0x066 */ char pad66[0x72];
    /* 0x0D8 */ Vec4f unkD8;
    /* 0x0E8 */ s32 unkE8;
    /* 0x0EC */ s32 unkEC;
    /* 0x0F0 */ s32 unkF0;
    /* 0x0F4 */ s32 unkF4;
    /* 0x0F8 */ Mtx unkF8;
    /* 0x138 */ Mtx unk_138;
    /* 0x178 */ char unk_178[0x380]; // more matrices?
} unk_Struct00;

typedef struct unk_Struct04 {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ char padC[0x18];
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ char pad30[0x10];
    /* 0x40 */ s16* unk_40;
} unk_Struct04; /* size = 0x44 */

typedef struct Object {
/* 0x00 */ struct Object *prev; // may be NULL
/* 0x04 */ struct Object *next;
/* 0x08 */ s16 unk_08;
/* 0x0A */ u16 unk_0A;
/* 0x0C */ Vec3f coords;
/* 0x18 */ Vec3f unk_18;
/* 0x24 */ f32 xScale;
/* 0x28 */ f32 yScale;
/* 0x2C */ f32 zScale;
/* 0x30 */ f32 unk_30;
/* 0x34 */ f32 unk_34;
/* 0x38 */ f32 unk_38;
/* 0x3C */ unk_Struct04* unk_3C;
/* 0x3C */ unk_Struct04* unk_40;
/* 0x44 */ f32 unk_44;
/* 0x48 */ f32 unk_48;
/* 0x4C */ s32 unk_4C;
/* 0x50 */ char unk_50[3];
/* 0x53 */ s8 unk_53;
/* 0x54 */ char unk_54[0x38];
/* 0x8C */ struct Object* unk_8C;
} Object; // //sizeof 0xAC? (this and mpSource_object are the same struct)

typedef struct GW_PLAYER {
/* 0x00 */ u8 group;
/* 0x01 */ u8 cpu_difficulty;
/* 0x02 */ u8 cpu_difficulty_copy;
/* 0x03 */ u8 port; //controller port
/* 0x04 */ u8 character;
/* 0x05 */ char unk_05; //likely padding
/* 0x06 */ u16 flags; // (flags) including CPU flag
/* 0x08 */ s16 coins; //player's current coins
/* 0x0A */ s16 coins_mg; //coins to give to player after minigame
/* 0x0C */ s16 stars;
/* 0x0E */ s16 cur_chain;
/* 0x10 */ u16 cur_space;
/* 0x12 */ u16 next_chain;
/* 0x14 */ u16 next_space;
/* 0x16 */ u8 poisoned_flag;
/* 0x17 */ u8 turn_status; //space type player landed on
/* 0x18 */ u8 player_index; //0, 1, 2, or 3
/* 0x19 */ char unk_19[3]; //likely padding
/* 0x1C */ Process* process; //some heap instance
/* 0x20 */ Object* player_obj; //ptr to player_obj on heap
/* 0x24 */ s16 coins_total; //how many coins a player has won/lost in minigames
/* 0x26 */ s16 coins_max; //highest amount of coins player has held
/* 0x28 */ u8 happening_count;
/* 0x29 */ u8 red_count;
/* 0x2A */ u8 blue_count;
/* 0x2B */ u8 minigame_count;
/* 0x2C */ u8 chance_count;
/* 0x2D */ u8 mushroom_count;
/* 0x2E */ u8 bowser_count;
/* 0x2F */ char unk_2F;
} GW_PLAYER __attribute__((aligned(4))); //sizeof 0x30
//P1 800F32B0, P2 800F32E0, P3 800F3310, P4 800F3340

//sprite related
typedef struct unk_800ECDE0 {
/* 0x00 */ s16 unk_00;
/* 0x02 */ s16 unk_02;
/* 0x04 */ u16 unk_04;
/* 0x06 */ s16 unk_06;
/* 0x08 */ s16 unk_08;
/* 0x0A */ s16 unk_0A;
/* 0x0C */ s16 unk_0C;
/* 0x0E */ s16 unk_0E;
/* 0x10 */ s16 unk_10;
/* 0x12 */ u8 unk_12;
/* 0x13 */ u8 unk_13;
/* 0x14 */ u8 unk_14;
/* 0x15 */ u8 unk_15;
/* 0x16 */ s8 unk_16;
/* 0x17 */ s8 unk_17;
/* 0x18 */ s8 unk_18;
/* 0x19 */ u8 unk_19;
/* 0x1A */ u8 unk_1A;
/* 0x1B */ u8 unk_1B;
/* 0x1C */ u8 unk_1C;
/* 0x1D */ u8 unk_1D;
/* 0x1E */ s16 unk_1E;
/* 0x20 */ s32 unk_20;
} unk_800ECDE0;

// typedef struct viewAngle {
// /* 0x00 */ f32 y;
// /* 0x04 */ f32 x;
// /* 0x08 */ f32 z;
// } viewAngle; //sizeof 0xC

// typedef struct cameraPosition {
// /* 0x00 */ f32 x;
// /* 0x04 */ f32 y;
// /* 0x08 */ f32 z;
// } cameraPosition;

typedef struct HeapNode {
    s32 size;
    u8 heap_constant;
    u8 used; // bool
    struct HeapNode* prev;
    struct HeapNode* next;
} HeapNode;

typedef struct board_overlay_entrypoint {
    s16 index;
    void (*fn)();
} board_overlay_entrypoint;

typedef struct GameStatus {
/* 0x00 */ s16 unk_00;
/* 0x02 */ s16 curBoardIndex;
/* 0x04 */ s16 playType; //lite play, standard play, full play (20, 35, 50 turns)
/* 0x06 */ s16 maxTurns;
/* 0x08 */ s16 currentTurn;
/* 0x0A */ s16 chosenStarSpaceIndex;
/* 0x0C */ s16 starSpaces[7];
/* 0x1A */ s16 unk_1A;
/* 0x1C */ s16 curPlayerIndex;
/* 0x1E */ s16 unk_1E;
/* 0x20 */ s16 curSpaceIndex;
/* 0x22 */ u8 saveSetting;
/* 0x23 */ s8 minigameExplanation;
/* 0x24 */ u8 messageSpeed;
/* 0x25 */ char unk_25;
} GameStatus; //sizeof 0x26

typedef struct GwQuest_s {
/* 0x00 */ s8 charNo;
/* 0x01 */ s8 charNoTeam;
/* 0x02 */ s8 mapNo;
/* 0x03 */ s8 lifeNum;
/* 0x04 */ u8 mgFlag[8];
/* 0x0C */ s8 coinNum;
/* 0x0D */ u8 masuPathNo;
/* 0x0E */ u8 masuNo;
} GWQUEST;

typedef struct mpSource_object_indirect2 {
    s16 unk0;
} mpSource_object_indirect2;

// Is this really just object? What is up with unk60?
typedef struct mpSource_object_indirect {
    s8 pad[24];

    /*0x18*/ f32 rot1;
    f32 rot2;
    f32 rot3;

    /*0x24*/ f32 unk36;
    f32 unk40;
    f32 unk44;

    /*0x30*/ f32 unk48;
    f32 funk52;
    f32 funk56;

    u16 unk60;
    struct mpSource_object_indirect2 *unk64;
    s16 unk68;
    s16 pad70;
    s32 pad72;
    u8 unk76;
} mpSource_object_indirect;


typedef struct mystery_struct_ret_func_80048224 {
    struct Object* unk0;
    s8 pad[4];
    s16 unk8; // window id
} mystery_struct_ret_func_80048224;


typedef struct mpSource_object {
    /*0x00*/ struct object *prev; // may be NULL
    /*0x04*/ struct object *next;
    /*0x08*/ s8 pad1[2];
    /*0x0A*/ u16 unka;

    /*0x0C*/ Vec3f coords;

    /*0x18*/ f32 rot1;
    f32 rot2;
    f32 rot3;

    /*0x24*/ f32 unk36;
    f32 unk40;
    f32 unk44;

    /*0x30*/ f32 unk48;
    f32 funk52;
    f32 funk56;

    mpSource_object_indirect* unk60;
    void *unk64;
    s8 pad5[2];
    s16 unk70;
} mpSource_object;

typedef struct mpSource_f2b7cstruct {
    s8 pad[108];
    void *unk108;
    s8 pad112[12];
    void *unk124;
    s8 pad2[64];
} mpSource_f2b7cstruct;

typedef struct camera {
    /* 0x00 */ Vec3f coords; // eye?
    /* 0x0C */ f32 unk_0C;   // at?
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;   // up?
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
} camera; //sizeof unknown

typedef struct unkStructTest {
/* 0x00 */ s16 unk_00[12];
/* 0x18 */ s16 unk_16;
/* 0x1A */ s16 unk_18;
/* 0x1C */ s16 unk_1A;
/* 0x1E */ s16 unk_1C;
} unkStructTest;

typedef struct unk_Struct02 {
    char unk_00[0x0A];
    s16 unk_0A;
    s16* unk_0C;
} unk_Struct02;

typedef struct unk2C0C0Struct20 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ char unk_01[3];
    /* 0x04 */ s16 unk_04[2]; // unknown array size
    /* 0x08 */ char unk_08[4];
    /* 0x0C */ f32 unk_0C[1]; // unknown array size
    /* 0x10 */ char unk_10[0xC];
    /* 0x1C */ f32 unk_1C[1]; // unknown array size
    /* 0x20 */ char unk_20[0xC];
    /* 0x2C */ u8 unk_2C[4]; // unknown array size
    /* 0x30 */ s16 unk_30;
    /* 0x32 */ s16 unk_32;
} unk2C0C0Struct20; //sizeof 0x34

typedef struct unk2C0C0Struct30 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ u16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ u16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ u32 unk_14;
    /* 0x18 */ u8 unk_18[4]; // unknown array size
    /* 0x1C */ char unk_1C[0x14];
    /* 0x30 */ u8 unk_30;
    /* 0x31 */ char unk_31[3];
    /* 0x34 */ unk2C0C0Struct20* unk_34;
    /* 0x38 */ char unk_38[0x12];
    /* 0x4A */ s16 unk_4A;
    /* 0x4C */ s16 unk_4C;
    /* 0x4E */ s16 unk_4E;
    /* 0x50 */ s16 unk_50;
    /* 0x52 */ s16 unk_52;
    /* 0x54 */ s16 unk_54;
    /* 0x56 */ char unk_56[2];
    /* 0x58 */ struct unk2C0C0StructC0* unk_58;
} unk2C0C0Struct30; //sizeof 0x5C

typedef struct unk2C0C0Struct40 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x02 */ char unk_06[2];
    /* 0x08 */ Vec3f unk_08;
    /* 0x14 */ Vec3f unk_14;
    /* 0x20 */ Vec3f unk_20;
    /* 0x2C */ Vec3f unk_2C;
    /* 0x38 */ Vec3f unk_38;
    /* 0x44 */ s8 unk_44;
    /* 0x45 */ s8 unk_45;
    /* 0x46 */ char unk_46[2];
    /* 0x48 */ struct unk2C0C0StructC0* unk_48;
    /* 0x4C */ Matrix4f unk_4C;
} unk2C0C0Struct40; //sizeof 0x8C

typedef struct unk2C0C0Struct50 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ char unk_02[2];
    /* 0x04 */ s16* unk_04;
    /* 0x08 */ Vec3f unk_08;
    /* 0x14 */ Vec3f unk_14;
    /* 0x20 */ Vec3f unk_20;
    /* 0x2C */ Vec3f unk_2C;
    /* 0x38 */ Vec3f unk_38;
    /* 0x44 */ Vec3f unk_44;
    /* 0x50 */ Vec3f unk_50;
    /* 0x5C */ s8 unk_5C;
    /* 0x5D */ s8 unk_5D;
    /* 0x5E */ s8 unk_5E;
    /* 0x5F */ char unk_5F;
    /* 0x60 */ struct unk2C0C0StructC0* unk_60;
    /* 0x64 */ Matrix4f unk_64;
} unk2C0C0Struct50; //sizeof 0xA4

typedef struct unk2C0C0Struct60 {
    /* 0x00 */ char unk_00[0x1A];
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ char unk_1C[8];
    /* 0x2C */ s32 unk_24;
} unk2C0C0Struct60; //sizeof unknown

typedef struct unk2C0C0Struct70 {
    /* 0x00 */ char unk_00[0x18];
    /* 0x1A */ u8 unk_18;
    /* 0x1B */ u8 unk_19;
    /* 0x1A */ u8 unk_1A;
    /* 0x1B */ u8 unk_1B;
    /* 0x1C */ char unk_1C[4];
    /* 0x20 */ u16 unk_20;
    /* 0x22 */ char unk_22[2];
    /* 0x24 */ u8* unk_24;
    /* 0x28 */ struct unk2C0C0StructC0* unk_28;
    /* 0x2C */ unk2C0C0Struct60* unk_2C;
} unk2C0C0Struct70; //sizeof 0x30

typedef struct unk2C0C0Struct80 {
    /* 0x00 */ s8 unk_00;
    /* 0x01 */ s8 unk_01;
    /* 0x02 */ s8 unk_02;
    /* 0x03 */ s8 unk_03;
    /* 0x04 */ s8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ u8 unk_07;
    /* 0x08 */ char unk_08;
    /* 0x09 */ u8 unk_09;
    /* 0x0A */ char unk_0A[2];
    /* 0x0C */ unk2C0C0Struct70* unk_0C;
} unk2C0C0Struct80; //sizeof 0x10

typedef struct unk2C0C0Struct90 {
    /* 0x00 */ char unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ char unk_04;
    /* 0x05 */ Color_RGB8 unk_05;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ s8 unk_09;
    /* 0x0A */ s8 unk_0A;
    /* 0x0B */ s8 unk_0B;
    /* 0x0C */ s8 unk_0C;
    /* 0x0D */ u8 unk_0D;
} unk2C0C0Struct90; //sizeof 0xE

typedef struct unk2C0C0StructA0 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
} unk2C0C0StructA0; //sizeof 6

typedef struct unk2C0C0StructB0 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ char unk_01;
    /* 0x02 */ s16 unk_02[1]; // unknown array size
    /* 0x04 */ char unk_04[8];
    /* 0x08 */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
} unk2C0C0StructB0; //sizeof 0x18

typedef struct unk2C0C0StructB4 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ u16* unk_08;
    /* 0x0C */ s32* unk_0C;
} unk2C0C0StructB4; //sizeof 0x10

typedef struct unk2C0C0StructB8 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ unk2C0C0StructB4 unk_0C[16]; // array size unknown
} unk2C0C0StructB8; //sizeof 0x10C

typedef struct unk2C0C0StructC0 {
    /* 0x00 */ Gfx** unk_00;
    /* 0x04 */ struct unk2C0C0StructE0* unk_04;
    /* 0x08 */ struct unk2C0C0StructE0* unk_08[8];
    /* 0x28 */ u8 unk_28;
    /* 0x29 */ char unk_29;
    /* 0x2A */ s8 unk_2A;
    /* 0x2B */ s8 unk_2B;
    /* 0x2C */ s8 unk_2C;
    /* 0x2D */ s8 unk_2D;
    /* 0x2E */ s8 unk_2E;
    /* 0x2F */ s8 unk_2F;
    /* 0x30 */ s8 unk_30;
    /* 0x31 */ s8 unk_31;
    /* 0x32 */ char unk_32[2];
    /* 0x34 */ u8* unk_34;
    /* 0x38 */ u8* unk_38;
    /* 0x3C */ u8* unk_3C;
    /* 0x40 */ void* unk_40;
    /* 0x44 */ void* unk_44;
    /* 0x48 */ void* unk_48;
    /* 0x4C */ void* unk_4C;
    /* 0x50 */ void* unk_50;
    /* 0x54 */ void* unk_54;
    /* 0x58 */ void* unk_58;
    /* 0x5C */ void* unk_5C;
    /* 0x60 */ void* unk_60;
    /* 0x64 */ u8 unk_64;
    /* 0x65 */ char unk_65;
    /* 0x66 */ s16 unk_66;
    /* 0x68 */ u16 unk_68;
    /* 0x6A */ s16 unk_6A;
    /* 0x6C */ s16 unk_6C;
    /* 0x6E */ s16 unk_6E;
    /* 0x70 */ s16 unk_70;
    /* 0x72 */ s16 unk_72;
    /* 0x74 */ s16 unk_74;
    /* 0x76 */ s16 unk_76;
    /* 0x78 */ unk2C0C0StructA0* unk_78;
    /* 0x7C */ Color_RGB8* unk_7C;
    /* 0x80 */ unk2C0C0Struct30* unk_80;
    /* 0x84 */ s16 unk_84;
    /* 0x86 */ char unk_86[2];
    /* 0x88 */ unk2C0C0Struct40* unk_88;
    /* 0x8C */ char unk_8C[0x14];
    /* 0xA0 */ unk2C0C0Struct50* unk_A0;
    /* 0xA4 */ unk2C0C0Struct80* unk_A4;
    /* 0xA8 */ unk2C0C0Struct90* unk_A8;
    /* 0xAC */ s32 unk_AC;
    /* 0xB0 */ s32 unk_B0;
    /* 0xB4 */ s32 unk_B4;
    /* 0xB8 */ unk2C0C0StructB8* unk_B8;
    /* 0xBC */ unk2C0C0Struct70* unk_BC;
    /* 0xC0 */ s32 unk_C0;
    /* 0xC4 */ s32 unk_C4;
    /* 0xC8 */ s32 unk_C8;
    /* 0xCC */ s32 unk_CC;
    /* 0xD0 */ unk2C0C0StructB0* unk_D0;
    /* 0xD4 */ char unk_D4[0xC];
} unk2C0C0StructC0; //sizeof 0xE0

typedef struct unk2C0C0StructE0 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ Color_RGB8 unk_0C;
    /* 0x0F */ u8 unk_0F;
} unk2C0C0StructE0; //sizeof 0x10

typedef struct unk72D90Struct3 {
    /* 0x00 */ char unk_00[1];
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ char unk_02[1];
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ char unk_05[1];
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ char unk_08[2];
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ char unk_0C[0x24];
} unk72D90Struct3; //sizeof 0x30

typedef struct unk_ovl_2D_struct { //actually global??
    /* 0x00 */ s8 unk_00;
    /* 0x01 */ char unk_01;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16;
    /* 0x18 */ char unk_18[2];
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ char unk_1C[4];
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ f32 unk_50;
    /* 0x54 */ f32 unk_54;
    /* 0x58 */ f32 unk_58;
    /* 0x5C */ f32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ f32 unk_68;
    /* 0x6C */ unk2C0C0StructC0* unk_6C;
    /* 0x70 */ char pad70[0xC];
    /* 0x7C */ Mat4 unk7C; // Transformation Matrix
    /* 0xBC */ char padBC[0x4];
} unk_ovl_2D_struct; //sizeof 0xC0

typedef struct SubTextWindow {
    s8 unk0;
    char unk_01;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
} SubTextWindow;
typedef struct TextWindow {
/* 0x00 */ u8 unk_00;
/* 0x01 */ char unk_01;
/* 0x02 */ u8 unk_02;
/* 0x03 */ u8 unk_03;
/* 0x04 */ u8 unk_04;
/* 0x05 */ u8 unk_05;
/* 0x06 */ u8 unk_06;
/* 0x07 */ u8 unk_07;
/* 0x08 */ u8 unk_08;
/* 0x09 */ u8 unk_09;
/* 0x0A */ u8 unk_0A;
/* 0x0B */ char unk_0B[2];
/* 0x0D */ u8 unk_0D;
/* 0x0E */ u8 unk_0E;
/* 0x0F */ u8 unk_0F;
/* 0x10 */ s8 unk_10;
/* 0x11 */ char unk_11;
/* 0x12 */ u8 unk_12;
/* 0x13 */ u8 unk_13;
/* 0x14 */ char unk_14[4];
/* 0x18 */ s16 unk_18;
/* 0x1A */ s16 unk_1A;
/* 0x1C */ s16 unk_1C;
/* 0x1E */ char unk_1E[6];
/* 0x24 */ s16 unk_24;
/* 0x26 */ s16 unk_26;
/* 0x28 */ s16 unk_28;
/* 0x26 */ s16 unk_2A;
/* 0x2C */ s16 unk_2C;
/* 0x2E */ s16 unk_2E;
/* 0x30 */ s16 unk_30;
/* 0x32 */ s16 unk_32;
/* 0x34 */ s16 unk_34;
/* 0x36 */ char unk_36[0x2];
/* 0x38 */ s16 unk_38;
/* 0x3A */ char unk_3A[2];
/* 0x3C */ f32 unk_3C;
/* 0x40 */ char unk_40[2];
/* 0x42 */ s16 unk_42;
/* 0x44 */ s16 unk_44;
/* 0x46 */ s16 unk_46[20];
/* 0x6E */ s16 unk_6E;
/* 0x70 */ char unk_70[11];
/* 0x7B */ s8 unk_7B[5]; //unknown array size
/* 0x80 */ char unk_80[8];
/* 0x88 */ void* unk_88[5]; //unknown array size
/* 0x9C */ char unk_9C[0x14];
/* 0xB0 */ u8* stringPtr;
/* 0xB4 */ void* string;
/* 0xB8 */ u8 usingStringIDBool;
/* 0xB9 */ char unk_B9[7];
/* 0xC0 */ void* unk_C0[10];
/* 0xE8 */ unkGlobalStruct_00* unk_E8;
/* 0xEC */ f32 unk_EC;
/* 0xF0 */ f32 unk_F0;
/* 0xF4 */ SubTextWindow unk_F4[5]; //unknown size
/* 0x144 */ char unk_144[0x130];
/* 0x274 */ s16 unk_274;
/* 0x276 */ char unk_276[6];
} TextWindow; //sizeof 0x27C

typedef struct DecisionTreeNonLeafNode {
    u32 type;
    union {
        void (*func) ();
        u32 data;
    } node_data1;
    union {
        u32 data;
        s32 *node_data;
    } node_data2;
} DecisionTreeNonLeafNode;

typedef struct file_1ACF0_struct {
/* 0x00 */ Addr* unk_00;
/* 0x04 */ Addr* unk_04;
/* 0x08 */ char unk_08[0x14];
/* 0x1C */ s32 unk_1C;
/* 0x20 */ s32 unk_20;
/* 0x24 */ Addr* unk_24;
/* 0x28 */ Addr* unk_28;
/* 0x2C */ char unk_2C[0x14];
/* 0x40 */ s32 unk_40;
/* 0x44 */ s32 unk_44;
/* 0x48 */ s32 unk_48;
/* 0x4C */ s32 unk_4C;
/* 0x50 */ s32 unk_50;
/* 0x54 */ s32 unk_54;
} file_1ACF0_struct;

typedef struct omOvlHisData { //Object Manager History Data
/* 0x00 */ s32 overlayID;
/* 0x04 */ s16 event;
/* 0x06 */ u16 stat;
} omOvlHisData; //sizeof 0x08

typedef struct GwCommon_s {
/* 0x00 */ u8 unk0;
/* 0x01 */ char unk_01[1];
/* 0x02 */ s16 mgRecord[8];
/* 0x12 */ u8 mgUnlock[7];
/* 0x19 */ u8 mgBuy[7];
/* 0x20 */ u16 boardRecord[8][2];
/* 0x40 */ u32 coinNum;
/* 0x44 */ s16 starNum;
/* 0x46 */ s8 unk_46;
/* 0x47 */ s8 boardItem;
/* 0x48 */ u8 flag[12];
/* 0x54 */ s16 boardWork[32];
} GWCOMMON; //sizeof 0x94

typedef struct unk2C0C0Struct10 {
    /* 0x00 */ Hilite unk_00;
    /* 0x10 */ char unk_10[0x30];
    /* 0x40 */ LookAt unk_40;
} unk2C0C0Struct10; //sizeof 0x60

typedef struct unk2C0C0StructD0 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02[4];
    /* 0x0A */ s8 unk_0A;
    /* 0x0B */ char unk_0B;
    /* 0x0C */ unk2C0C0Struct90* unk_0C;
    /* 0x10 */ unk2C0C0Struct80* unk_10;
} unk2C0C0StructD0; //sizeof 0x14

typedef struct unk2C0C0StructF0 {
    /* 0x00 */ char unk_00[0x40];
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ void* unk_44;
    /* 0x48 */ unk2C0C0StructC0* unk_48;
    /* 0x4C */ s32 unk_4C;
    /* 0x50 */ s32 unk_50;
    /* 0x54 */ s16 unk_54;
    /* 0x56 */ char unk_56;
    /* 0x57 */ u8 unk_57;
    /* 0x58 */ u8 unk_58;
    /* 0x59 */ char unk_59[3];
} unk2C0C0StructF0; //sizeof 0x5C

typedef struct unk3AC60Struct0 {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
} unk3AC60Struct0; //sizeof unknown

typedef struct unk3AC60Struct1 {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ char unk_08[8];
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ char unk_18[0x18];
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
} unk3AC60Struct1; //sizeof unknown

typedef struct unk3AC60Struct2 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ char unk_04[4];
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ char unk_0C[0xC];
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ char unk_1C[4];
    /* 0x20 */ s16 unk_20;
    /* 0x22 */ s16 unk_22;
    /* 0x24 */ char unk_24[4];
    /* 0x28 */ s16 unk_28;
    /* 0x2A */ s16 unk_2A;
    /* 0x2C */ char unk_2C[0xC];
    /* 0x38 */ s16 unk_38;
    /* 0x3A */ s16 unk_3A;
} unk3AC60Struct2; //sizeof unknown

typedef struct unk_ProcessUserData08 {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ char unk02[2];
    /* 0x04 */ Object* unk04;
} unk_ProcessUserData08;

typedef struct unk_8003B8D4Struct {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ struct unk_ProcessUserData08* unk04;
    /* 0x08 */ Process* unk08;
    /* 0x0C */ s16 unk0C;
    /* 0x0E */ s16 unk0E;
    /* 0x10 */ char unk_10[0x58];
    /* 0x68 */ s32 unk68;
} unk_8003B8D4Struct;

#endif
