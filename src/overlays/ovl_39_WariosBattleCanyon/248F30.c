#include "common.h"
#include "engine/process.h"
#include "spaces.h"

/* One spark of the cannon-landing burst (func_800F8164's user_data). */
typedef struct WarioSpark {
    /* 0x00 */ s16 active;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ Vec3f vel;
} WarioSpark; // N64 size 0x1C

// main-code functions without a shared prototype
void func_8004DBD4(s32, s32);
void func_80056E30(s16);
void func_80056E48(Vec3f*);
f32 func_8004B844(void);
void func_8003D478(Vec3f* v, f32 angle);
void func_8004CD48(Object* arg0, s16 arg1);
s16 BoardGetRandomSpaceTypeInChain(u16 type, s16 chainIndex); /* retail passes the chain as s16 (lh) */
s16 GetChainSpaceIndexFromAbsSpaceIndex(s16 absIndex, s32 chainIndex);
void func_800559BC(void);
void func_800559F8(void);

// this overlay's functions
s16 func_800F6610_WariosBattleCanyon(void);
void func_800F663C_WariosBattleCanyon(void);
void func_800F67A4_WariosBattleCanyon(void);
void func_800F6830_WariosBattleCanyon(void);
s16 func_800F6958_WariosBattleCanyon(s32);
void func_800F6A38_WariosBattleCanyon(void);
void func_800F6CD8_WariosBattleCanyon(void);
void func_800F7030_WariosBattleCanyon(void);
void func_800F7340_WariosBattleCanyon(void*);
void func_800F73BC_WariosBattleCanyon(void);
void func_800F7408_WariosBattleCanyon(void);
void func_800F7468_WariosBattleCanyon(void);
void func_800F74E4_WariosBattleCanyon(void);
void func_800F7504_WariosBattleCanyon(s16);
void func_800F75EC_WariosBattleCanyon(void);
void func_800F7674_WariosBattleCanyon(s16);
void func_800F777C_WariosBattleCanyon(void);
void func_800F77BC_WariosBattleCanyon(s16);
void func_800F7884_WariosBattleCanyon(void);
void func_800F78C8_WariosBattleCanyon(s16);
void func_800F7990_WariosBattleCanyon(void);
Object* func_800F79D4_WariosBattleCanyon(s32);
void func_800F7A3C_WariosBattleCanyon(void);
void func_800F7AA4_WariosBattleCanyon(s32);
void func_800F7B14_WariosBattleCanyon(s16);
void func_800F7C3C_WariosBattleCanyon(void);
void func_800F7C80_WariosBattleCanyon(s16, Vec3f*);
void func_800F7CC4_WariosBattleCanyon(s16);
void func_800F7D8C_WariosBattleCanyon(void);
s16 func_800F7DCC_WariosBattleCanyon(s32);
void func_800F80B4_WariosBattleCanyon(void);
void func_800F8110_WariosBattleCanyon(s32);
s16 func_800F8158_WariosBattleCanyon(void);
void func_800F8164_WariosBattleCanyon(void);
WarioSpark* func_800F826C_WariosBattleCanyon(void);
void func_800F8314_WariosBattleCanyon(void);
void func_800F856C_WariosBattleCanyon(s16, s16);
void func_800F8688_WariosBattleCanyon(void);
void func_800F86A8_WariosBattleCanyon(s32);
void func_800F88A0_WariosBattleCanyon(s16);
void func_800F8B54_WariosBattleCanyon(void);
void func_800F8BE4_WariosBattleCanyon(void);
void func_800F8C08_WariosBattleCanyon(void);
void func_800F8C48_WariosBattleCanyon(void);
void func_800F8C88_WariosBattleCanyon(void);
void func_800F8CC8_WariosBattleCanyon(void);
void func_800F8D10_WariosBattleCanyon(void);
void func_800F8D48_WariosBattleCanyon(void);
void func_800F8D84_WariosBattleCanyon(Object*, Vec3f*);
void func_800F8DC0_WariosBattleCanyon(Object*);
void func_800F8E10_WariosBattleCanyon(Object*, Vec3f*, Vec3f*, f32, f32);
void func_800F8F04_WariosBattleCanyon(Object*, Object*);
void func_800F8F6C_WariosBattleCanyon(void);
void func_800F8FEC_WariosBattleCanyon(void);
void func_800F9210_WariosBattleCanyon(void);
void func_800F9308_WariosBattleCanyon(void);
void func_800F9348_WariosBattleCanyon(void);
void func_800F93C8_WariosBattleCanyon(void);
void func_800F93FC_WariosBattleCanyon(void);
void func_800F942C_WariosBattleCanyon(void);
void func_800F9560_WariosBattleCanyon(void);
void func_800F9630_WariosBattleCanyon(void);
void func_800F9664_WariosBattleCanyon(void);
void func_800F96C8_WariosBattleCanyon(void);

/* .data (0x800F97E0..0x800F9A70) */
Vec4f D_800F97E0_WariosBattleCanyon = { 0.0f, 0.0f, 320.0f, 240.0f };
s16 D_800F97F0_WariosBattleCanyon[] = { 1, 2, 3, 5, 0, 4, 6, 0 }; // star order
s16 D_800F9800_WariosBattleCanyon[] = { 0, 0, 0, 0, 1, 2, 4, 0 }; // star order constraints
s16 D_800F9810_WariosBattleCanyon[] = { 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0 }; // star flags
s16 D_800F9820_WariosBattleCanyon[] = { 0x63, 0x5C, 0x5B, 0x69, 0x68, 0x66, 0x5D, 0 }; // star spaces
s16 D_800F9830_WariosBattleCanyon[] = { 0x48, 0x41, 0x40, 0x54, 0x53, 0x51, 0x42, 0 }; // toad spaces
s32 D_800F9840_WariosBattleCanyon[] = { 1, 0x70003 }; /* MBModelCreate motion list: words */
s32 D_800F9848_WariosBattleCanyon[] = { 1, 0xA006A }; /* MBModelCreate motion list: words */
s16 D_800F9850_WariosBattleCanyon[] = { 0x48, 0x41, 0x40, 0x54, 0x53, 0x51, 0x42, 0 };
s16 D_800F9860_WariosBattleCanyon[] = { 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0 };
s16 D_800F9870_WariosBattleCanyon[] = { 0x55, 0 };             // boo
s16 D_800F9874_WariosBattleCanyon[] = { 0x3F, 0x52 };          // model 0xE
s16 D_800F9878_WariosBattleCanyon[] = { 0x50, 0x56 };          // model 0xF
s16 D_800F987C_WariosBattleCanyon[] = { 0x4E, 0x4F, 0x4D, 0x4C };
s16 D_800F9884_WariosBattleCanyon[] = { 0x50, 0x3F, 0x56, 0x52 };
s16 D_800F988C_WariosBattleCanyon[] = { 0x47, 0x49, 0x45, 0x46 }; // cannons
s16 D_800F9894_WariosBattleCanyon[] = { 0x62, 0x5F, 0x60, 0x61 };
s16 D_800F989C_WariosBattleCanyon[] = { 0x60, 0x61, 0x62, 0x5F };
s16 D_800F98A4_WariosBattleCanyon[] = { 0x3E, 0 };
/* cannon target chains; entry 4 was splat's D_800F98B0 */
s16 D_800F98A8_WariosBattleCanyon[] = { 2, 3, 8, 1, 0, 0 };
s16 D_800F98B4_WariosBattleCanyon[] = { 4, 5, 6, 7 };
s16 D_800F98BC_WariosBattleCanyon[] = { 0x61, 0x62, 0x5F, 0x60, 0x64, 0 };
/* model per character; read as u8 (splat's D_800F98C9 is the low byte of entry 0) */
s16 D_800F98C8_WariosBattleCanyon[] = { 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A };
s16 D_800F98D4_WariosBattleCanyon[] = { 1, 2, 3, 0 };
s16 D_800F98DC_WariosBattleCanyon[] = { 3, 0, 1, 2 };
EventListEntry D_800F98E4_WariosBattleCanyon[] = {
    { 1, 2, func_800F8B54_WariosBattleCanyon },
    { 2, 2, func_800F8BE4_WariosBattleCanyon },
    { 0, 0, NULL },
};
EventListEntry D_800F98FC_WariosBattleCanyon[] = {
    { 1, 2, func_800F8C08_WariosBattleCanyon },
    { 0, 0, NULL },
};
EventListEntry D_800F990C_WariosBattleCanyon[] = {
    { 1, 2, func_800F8C48_WariosBattleCanyon },
    { 0, 0, NULL },
};
EventListEntry D_800F991C_WariosBattleCanyon[] = {
    { 1, 2, func_800F8C88_WariosBattleCanyon },
    { 0, 0, NULL },
};
EventListEntry D_800F992C_WariosBattleCanyon[] = {
    { 1, 1, func_800F8CC8_WariosBattleCanyon },
    { 2, 2, func_800F8D10_WariosBattleCanyon },
    { 0, 0, NULL },
};
EventListEntry D_800F9944_WariosBattleCanyon[] = {
    { 1, 1, func_800F8D48_WariosBattleCanyon },
    { 2, 1, func_800F9210_WariosBattleCanyon },
    { 0, 0, NULL },
};
EventListEntry D_800F995C_WariosBattleCanyon[] = {
    { 3, 1, func_800F9308_WariosBattleCanyon },
    { 4, 2, func_800F9348_WariosBattleCanyon },
    { 0, 0, NULL },
};
EventListEntry D_800F9974_WariosBattleCanyon[] = {
    { 1, 1, func_800F93C8_WariosBattleCanyon },
    { 0, 0, NULL },
};
EventListEntry D_800F9984_WariosBattleCanyon[] = {
    { 1, 1, func_800F93FC_WariosBattleCanyon },
    { 0, 0, NULL },
};
EventListEntry D_800F9994_WariosBattleCanyon[] = {
    { 1, 1, func_800F93FC_WariosBattleCanyon },
    { 1, 2, func_800F9630_WariosBattleCanyon },
    { 0, 0, NULL },
};
EventListEntry D_800F99AC_WariosBattleCanyon[] = {
    { 1, 1, func_800F9664_WariosBattleCanyon },
    { 3, 1, func_800F96C8_WariosBattleCanyon },
    { 0, 0, NULL },
};
EventTableEntry D_800F99C4_WariosBattleCanyon[] = {
    { 0x58, D_800F9984_WariosBattleCanyon },
    { 0x63, D_800F99AC_WariosBattleCanyon },
    { 0x5C, D_800F99AC_WariosBattleCanyon },
    { 0x5B, D_800F99AC_WariosBattleCanyon },
    { 0x69, D_800F99AC_WariosBattleCanyon },
    { 0x68, D_800F99AC_WariosBattleCanyon },
    { 0x66, D_800F99AC_WariosBattleCanyon },
    { 0x5D, D_800F99AC_WariosBattleCanyon },
    { 0x5E, D_800F992C_WariosBattleCanyon },
    { 0x26, D_800F995C_WariosBattleCanyon },
    { 0x0A, D_800F995C_WariosBattleCanyon },
    { 0x65, D_800F98E4_WariosBattleCanyon },
    { 0x5A, D_800F98FC_WariosBattleCanyon },
    { 0x6B, D_800F990C_WariosBattleCanyon },
    { 0x67, D_800F991C_WariosBattleCanyon },
    { 0x59, D_800F9944_WariosBattleCanyon },
    { -1, NULL },
};
EventTableEntry D_800F9A4C_WariosBattleCanyon[] = {
    { 0x58, D_800F9994_WariosBattleCanyon },
    { -1, NULL },
};
EventTableEntry D_800F9A5C_WariosBattleCanyon[] = {
    { 0x6A, D_800F9974_WariosBattleCanyon },
    { -1, NULL },
};

/* .bss (asm, ovl_39_bss.bss.s) */
extern Object* D_800F9A70_WariosBattleCanyon;    // bowser
extern Object* D_800F9A74_WariosBattleCanyon;    // koopa
extern Object* D_800F9A78_WariosBattleCanyon;    // toad model
extern Object* D_800F9A80_WariosBattleCanyon[7]; // toads
extern Object* D_800F9A9C_WariosBattleCanyon;    // boo model
extern Object* D_800F9AA0_WariosBattleCanyon[1]; // boos
extern Object* D_800F9AA4_WariosBattleCanyon;    // model 0xE
extern Object* D_800F9AA8_WariosBattleCanyon[2];
extern Object* D_800F9AB0_WariosBattleCanyon;    // model 0xF
extern Object* D_800F9AB4_WariosBattleCanyon[2];
extern Object* D_800F9ABC_WariosBattleCanyon;    // cannon model
extern Object* D_800F9AC0_WariosBattleCanyon[4]; // cannons
extern Object* D_800F9AD0_WariosBattleCanyon;    // model 0x10
extern Object* D_800F9AD4_WariosBattleCanyon[1];
extern s16 D_800F9AD8_WariosBattleCanyon;        // picked landing space, -1 while picking
extern WarioSpark D_800F9AE0_WariosBattleCanyon[20];
extern Vec3f D_800F9D10_WariosBattleCanyon;
extern Vec3f D_800F9D1C_WariosBattleCanyon;
extern Object* D_800F9D28_WariosBattleCanyon;    // flying player model
extern Vec3f D_800F9D2C_WariosBattleCanyon;
extern Vec3f D_800F9D38_WariosBattleCanyon;

s16 func_800F6610_WariosBattleCanyon(void) {
    return D_800F9830_WariosBattleCanyon[GwSystem.starSpaces[GwSystem.chosenStarSpaceIndex]];
}

void func_800F663C_WariosBattleCanyon(void) {
    s32 s1;
    s32 rand1;
    s32 rand2;
    s32 swap1;
    GW_SYSTEM* ed5c0;

    ed5c0 = &GwSystem;
    for (s1 = 0; s1 < 30; s1++) {
        rand1 = rand8() % 7;
        rand2 = rand8() % 7;
        if (rand1 == rand2) {
            continue;
        }

        if (rand1 < D_800F9800_WariosBattleCanyon[rand2]) {
            continue;
        }

        if (rand2 < D_800F9800_WariosBattleCanyon[rand1]) {
            continue;
        }

        swap1 = D_800F97F0_WariosBattleCanyon[rand1];
        D_800F97F0_WariosBattleCanyon[rand1] = D_800F97F0_WariosBattleCanyon[rand2];
        D_800F97F0_WariosBattleCanyon[rand2] = swap1;

        swap1 = D_800F9800_WariosBattleCanyon[rand1];
        D_800F9800_WariosBattleCanyon[rand1] = D_800F9800_WariosBattleCanyon[rand2];
        D_800F9800_WariosBattleCanyon[rand2] = swap1;
    }

    for (s1 = 0; s1 < 7; s1++) {
        ed5c0->starSpaces[s1] = D_800F97F0_WariosBattleCanyon[s1];
    }
}

void func_800F67A4_WariosBattleCanyon(void) {
    s32 starSpaceTemp;
    GW_SYSTEM* ed5c0;

    ed5c0 = &GwSystem;

    if (++ed5c0->chosenStarSpaceIndex < 7) {
        return;
    }

    starSpaceTemp = ed5c0->starSpaces[6];
    ed5c0->chosenStarSpaceIndex = 0;

    SetBoardFeatureFlag(0x44);
    func_800F663C_WariosBattleCanyon();

    if (starSpaceTemp != ed5c0->starSpaces[0]) {
        return;
    }

    starSpaceTemp = ed5c0->starSpaces[0];
    ed5c0->starSpaces[0] = ed5c0->starSpaces[6];
    ed5c0->starSpaces[6] = starSpaceTemp;
}

void func_800F6830_WariosBattleCanyon(void) {
    s32 s0, s1;
    GW_SYSTEM* ed5c0 = &GwSystem;

    for (s1 = 0; s1 < 7; s1++) {
        BoardSpaceTypeSet(D_800F9820_WariosBattleCanyon[s1], 1);
        SetBoardFeatureFlag(D_800F9810_WariosBattleCanyon[s1]);
    }

    if (_CheckFlag(0x44)) {
        s0 = 7;
    } else {
        s0 = ed5c0->chosenStarSpaceIndex;
    }

    for (s1 = 0; s1 < s0; s1++) {
        BoardSpaceTypeSet(D_800F9820_WariosBattleCanyon[ed5c0->starSpaces[s1]], 6);
    }

    BoardSpaceTypeSet(D_800F9820_WariosBattleCanyon[ed5c0->starSpaces[ed5c0->chosenStarSpaceIndex]], 5);

    ClearBoardFeatureFlag(D_800F9810_WariosBattleCanyon[ed5c0->starSpaces[ed5c0->chosenStarSpaceIndex]]);
}

s16 func_800F6958_WariosBattleCanyon(s32 current_space_index) {
    s32 i;
    s32 j;
    s16* star_spaces;
    GW_SYSTEM* ed5c0 = &GwSystem;

    i = 0;

    star_spaces = D_800F9820_WariosBattleCanyon;

    current_space_index = (s16)current_space_index;

    for (; i < 7; i++) {
        if (current_space_index == star_spaces[i]) {
            if (i == ed5c0->starSpaces[ed5c0->chosenStarSpaceIndex]) {
                ed5c0->unk_1A = D_800F9810_WariosBattleCanyon[i];
                return 1;
            }

            if (_CheckFlag(68)) {
                current_space_index = 7;
            } else {
                current_space_index = ed5c0->chosenStarSpaceIndex;
            }

            for (j = 0; j < current_space_index; j++) {
                if (i == ed5c0->starSpaces[j]) {
                    return 2;
                }
            }

            return 0;
        }
    }
    return 0;
}

void func_800F6A38_WariosBattleCanyon(void) {
    BoardSpace* space_data;
    Object* ptr;
    mpSource_f2b7cstruct* f2bstr;
    void* ret;
    s32 s0;
    f32 ftemp;
    f32 ftt;
    f32 const20;

    space_data = (HuPrcCurrentGet())->user_data;

    PlaySound(109);
    ptr = MBModelCreate(64, NULL);
    ptr->unk_0A |= 4;
    func_8004CDCC(ptr);
    func_800A0D50(&ptr->coords, &space_data->coords);

    ptr->unk_30 = 500.0f;

    ret = func_80042728(ptr, 0);

    ftemp = 0.0f;
    for (s0 = 0; s0 < 6; s0++) {
        func_800A0D00(&ptr->xScale, ftemp, ftemp, ftemp);
        ftemp += 0.4f;
        HuPrcVSleep();
    }

    for (s0 = 0; s0 < 3; s0++) {
        func_800A0D00(&ptr->xScale, ftemp, ftemp, ftemp);
        ftemp -= 0.4f;
        HuPrcVSleep();
    }

    HuPrcSleep(30);
    PlaySound(68);

    ftt = 0.0f;
    const20 = 20.0f;
    while (TRUE) {
        f2bstr = (mpSource_f2b7cstruct*)&D_800F2B7C[*ptr->unk_3C->unk_40];
        func_800A40D0(&f2bstr->unk124, ftt);
        ftemp -= 0.02f;

        ftt += const20;
        if (ftemp < 0) {
            break;
        }

        func_800A0D00(&ptr->xScale, ftemp, ftemp, ftemp);
        ptr->unk_30 -= 6.0f;
        HuPrcVSleep();
    }

    func_800427D4(ret);
    HuPrcSleep(30);
    MBModelKill(ptr);
    EndProcess(NULL);
}

void func_800F6C48_WariosBattleCanyon(mystery_struct_ret_func_80048224* a0) {
    Object* unk0ptr;

    unk0ptr = a0->unk0;
    unk0ptr->unk_34 = 20.0f;
    unk0ptr->unk_38 = -3.0f;

    MBMotionSet(a0->unk0, 0, 0);
    HuPrcSleep(3);

    while (MBMotionCheck(a0->unk0) == 0) {
        HuPrcVSleep();
    }

    MBMotionSet(a0->unk0, -1, 2);
}

void func_800F6CD8_WariosBattleCanyon(void) {
    GW_SYSTEM* ed5c0;
    mystery_struct_ret_func_80048224* str;
    BoardSpace* spacedata;
    Process* proc_struct;
    s32 string_id;

    ed5c0 = &GwSystem;

    func_80060128(43);
    str = func_80048224(D_800F9840_WariosBattleCanyon);
    SetFadeInTypeAndTime(2, 16);

    while (func_80072718() != 0) {
        HuPrcVSleep();
    }

    func_8004A520();
    func_8004B5C4(3.0f);
    func_800F6C48_WariosBattleCanyon(str);

    if (ed5c0->chosenStarSpaceIndex == 0 && !_CheckFlag(68)) {
        string_id = 1256;
    } else {
        string_id = 1258;
    }

    LoadStringIntoWindow(str->unk8, (void*)(s32)string_id, -1, -1);
    func_80071C8C(str->unk8, 1);
    PlaySound(1125);
    WaitForTextConfirmation(str->unk8);
    func_80071E80(str->unk8, 1);
    func_8006EB40(str->unk8);

    spacedata = BoardSpaceGet(D_800F9830_WariosBattleCanyon[ed5c0->starSpaces[ed5c0->chosenStarSpaceIndex]]);
    func_8004B5DC(&spacedata->coords);
    func_8004B838(5.0f);
    HuPrcSleep(5);

    while (func_8004B850() != 0) {
        HuPrcVSleep();
    }

    HuPrcSleep(5);

    proc_struct = omAddPrcObj(&func_800F6A38_WariosBattleCanyon, 18432, 0, 0);
    proc_struct->user_data = spacedata;

    HuPrcSleep(30);

    if (ed5c0->chosenStarSpaceIndex == 0 && !_CheckFlag(68)) {
        string_id = 1257;
    } else {
        string_id = 1259;
    }

    LoadStringIntoWindow(str->unk8, (void*)(s32)string_id, -1, -1);
    func_80071C8C(str->unk8, 1);
    WaitForTextConfirmation(str->unk8);
    func_80071E80(str->unk8, 1);
    func_800601D4(90);
    HuPrcSleep(30);
    func_800726AC(2, 16);
    HuPrcSleep(17);
    func_8004847C(str);
    func_80056AF4();
    omOvlReturnEx(1);
    omOvlKill();
    HuPrcVSleep();
}

void func_800F6F0C_WariosBattleCanyon(void) {
    GW_SYSTEM* gameStatus = &GwSystem;

    gameStatus->curBoardIndex = 3;
    omInitObjMan(10, 0);
    omOvlGotoEx(53, 0, 146);
}

void func_800F6F48_WariosBattleCanyon(void) {
    GW_SYSTEM* ed5c0;
    ed5c0 = &GwSystem;

    omInitObjMan(10, 0);

    SetPlayerOntoChain(0, 2, 0);
    SetPlayerOntoChain(1, 2, 0);
    SetPlayerOntoChain(2, 2, 0);
    SetPlayerOntoChain(3, 2, 0);

    switch (ed5c0->unk_00) {
        case 0:
            SetBoardFeatureFlag(0x46);
            SetBoardFeatureFlag(0x48);
            SetBoardFeatureFlag(0x49);
            SetBoardFeatureFlag(0x4A);
            break;

        case 1:
            SetBoardFeatureFlag(0x48);
            SetBoardFeatureFlag(0x4A);
            break;
    }

    SetBoardFeatureFlag(0x43);

    func_800F663C_WariosBattleCanyon();

    GwCommon.boardWork[15] = 0;
    GwCommon.boardWork[1] = -1;
    ClearBoardFeatureFlag(0x4F);
    ClearBoardFeatureFlag(0x50);
    ClearBoardFeatureFlag(0x51);

    omOvlReturnEx(1);
}

void func_800F7030_WariosBattleCanyon(void) {
    GW_PLAYER* player;
    s32 i;

    omInitObjMan(0x50, 0x32);
    func_80060088();
    func_80023448(1);
    func_800234B8(0, 0x78, 0x78, 0x78);
    func_800234B8(1, 0x40, 0x40, 0x60);
    func_80023504(1, -100.0f, 100.0f, 300.0f);
    func_80056A08(0x1B, 0x48, 0x24, 0);
    func_80052E84(0);
    func_80052E84(1);
    func_80052E84(2);
    func_80052E84(3);

    for (i = 0; i < 4; i++) {
        player = GetPlayerStruct(i);
        func_8003E174(player->player_obj);
        player->player_obj->unk_0A |= 2;
    }

    if (_CheckFlag(0x4E) != 0) {
        ClearBoardFeatureFlag(0x4E);
        func_800F67A4_WariosBattleCanyon();
    }

    func_800F6830_WariosBattleCanyon();
    func_800F75EC_WariosBattleCanyon();
    func_800F7884_WariosBattleCanyon();
    func_800F7990_WariosBattleCanyon();
    func_800F7D8C_WariosBattleCanyon();
    func_800F7C3C_WariosBattleCanyon();
    func_800F7408_WariosBattleCanyon();

    if (_CheckFlag(0xE) == 0) {
        func_800F74E4_WariosBattleCanyon();
    }
    if (_CheckFlag(0xF) == 0) {
        func_800F777C_WariosBattleCanyon();
    }
}

void func_800F719C_WariosBattleCanyon(void) {
    GW_PLAYER* player2;
    GW_PLAYER* player;

    func_80060128(0xB);
    InitCameras(2);
    func_800F7030_WariosBattleCanyon();
    EventTableHydrate(D_800F99C4_WariosBattleCanyon);
    if (_CheckFlag(0xE) == 0) {
        EventTableHydrate(D_800F9A4C_WariosBattleCanyon);
    }
    if (_CheckFlag(0xF) == 0) {
        EventTableHydrate(D_800F9A5C_WariosBattleCanyon);
    }
    func_800584F0(0);
    if (_CheckFlag(0x50) != 0) {
        player = GetPlayerStruct(-1);
        ClearBoardFeatureFlag(0x50);
        func_800F7C80_WariosBattleCanyon(GwCommon.boardWork[2], &player->player_obj->coords);
        func_800F856C_WariosBattleCanyon(-1, GwCommon.boardWork[2]);
        player->player_obj->unk_0A &= ~2;
        MBModelDispOff(player->player_obj);
        func_800F7AA4_WariosBattleCanyon(GwCommon.boardWork[2]);
        PlaySound(0xC2);
        func_800559BC();
    }
    if (_CheckFlag(0x51) != 0) {
        player2 = GetPlayerStruct(-1);
        ClearBoardFeatureFlag(0x51);
        player2->player_obj->unk_0A &= ~2;
        MBModelDispOff(player2->player_obj);
        func_800559BC();
    }
    if (GwCommon.boardWork[1] == 4) {
        func_80056E30(2);
        func_80056E48(&BoardSpaceGet(0x64)->coords);
        func_800559BC();
    }
}

void func_800F7314_WariosBattleCanyon(void) {
    InitCameras(1);
    func_800F7030_WariosBattleCanyon();
    func_800584F0(1);
}

void func_800F7340_WariosBattleCanyon(void* motions) {
    Object* ptr;

    if (D_800F9A70_WariosBattleCanyon != NULL) {
        return;
    }

    ptr = MBModelCreate(0x3B, motions);
    func_8003E174(ptr);
    D_800F9A70_WariosBattleCanyon = ptr;

    ptr->unk_0A |= 0x2;

    func_800A0D50(&ptr->coords, &BoardSpaceGet(0x43)->coords);
    func_8003C314(7, ptr, 2, 0);
}

void func_800F73BC_WariosBattleCanyon(void) {
    MBMotionSet(D_800F9A70_WariosBattleCanyon, 0, 2);
    HuPrcSleep(150);
    MBMotionSet(D_800F9A70_WariosBattleCanyon, -1, 2);
    EndProcess(NULL);
}

void func_800F7408_WariosBattleCanyon(void) {
    D_800F9A70_WariosBattleCanyon = NULL;
    if (_CheckFlag(0x51) != 0) {
        func_800F7340_WariosBattleCanyon(D_800F9848_WariosBattleCanyon);
        omAddPrcObj(func_800F73BC_WariosBattleCanyon, 0x4800, 0, 0);
    } else {
        func_800F7340_WariosBattleCanyon(NULL);
    }
}

void func_800F7468_WariosBattleCanyon(void) {
    Object* ptr;

    if (D_800F9A74_WariosBattleCanyon != NULL) {
        return;
    }

    ptr = MBModelCreate(0x39, NULL);
    func_8003E174(ptr);
    D_800F9A74_WariosBattleCanyon = ptr;

    ptr->unk_0A |= 0x2;

    func_800A0D50(&ptr->coords, &BoardSpaceGet(0x3D)->coords);
    func_8003C314(9, ptr, 0, 0);
}

void func_800F74E4_WariosBattleCanyon(void) {
    D_800F9A74_WariosBattleCanyon = NULL;
    func_800F7468_WariosBattleCanyon();
}

void func_800F7504_WariosBattleCanyon(s16 arg0) {
    Object* obj;

    if (D_800F9A80_WariosBattleCanyon[arg0] == NULL) {
        if (D_800F9A78_WariosBattleCanyon == NULL) {
            obj = MBModelCreate(0x3A, NULL);
            func_8003E174(obj);
            D_800F9A78_WariosBattleCanyon = obj;
        } else {
            obj = MBModelParamCreate(D_800F9A78_WariosBattleCanyon);
        }
        obj->unk_0A |= 2;
        D_800F9A80_WariosBattleCanyon[arg0] = obj;
        func_8004CDCC(obj);
        func_800A0D50(&obj->coords, &BoardSpaceGet(D_800F9850_WariosBattleCanyon[arg0])->coords);
        func_8003C314(6, obj, 0, 0);
    }
}

void func_800F75EC_WariosBattleCanyon(void) {
    s32 i;

    D_800F9A78_WariosBattleCanyon = NULL;
    for (i = 0; i < 7; i++) {
        D_800F9A80_WariosBattleCanyon[i] = NULL;
        if (_CheckFlag(D_800F9860_WariosBattleCanyon[i]) == 0) {
            func_800F7504_WariosBattleCanyon(i);
        }
    }
}

void func_800F7674_WariosBattleCanyon(s16 arg0) {
    Object* obj;

    if (D_800F9AA0_WariosBattleCanyon[arg0] == NULL) {
        if (D_800F9A9C_WariosBattleCanyon == NULL) {
            obj = MBModelCreate(0x6A, NULL);
            func_8003E174(obj);
            D_800F9A9C_WariosBattleCanyon = obj;
        } else {
            obj = MBModelParamCreate(D_800F9A9C_WariosBattleCanyon);
        }
        D_800F9AA0_WariosBattleCanyon[arg0] = obj;
        obj->unk_0A |= 2;
        func_800A0D00(&obj->xScale, 0.6f, 0.6f, 0.6f);
        obj->unk_30 = 100.0f;
        func_800A0D50(&obj->coords, &BoardSpaceGet(D_800F9870_WariosBattleCanyon[arg0])->coords);
        func_8003C314(8, obj, 3, 0);
    }
}

void func_800F777C_WariosBattleCanyon(void) {
    s32 i;

    D_800F9A9C_WariosBattleCanyon = NULL;
    for (i = 0; i < 1; i++) {
        func_800F7674_WariosBattleCanyon(i);
    }
}

void func_800F77BC_WariosBattleCanyon(s16 arg0) {
    Object* obj;

    if (D_800F9AA8_WariosBattleCanyon[arg0] == NULL) {
        if (D_800F9AA4_WariosBattleCanyon == NULL) {
            obj = MBModelCreate(0xE, NULL);
            func_8003E174(obj);
            D_800F9AA4_WariosBattleCanyon = obj;
        } else {
            obj = MBModelParamCreate(D_800F9AA4_WariosBattleCanyon);
        }
        obj->unk_0A |= 2;
        D_800F9AA8_WariosBattleCanyon[arg0] = obj;
        func_800A0D50(&obj->coords, &BoardSpaceGet(D_800F9874_WariosBattleCanyon[arg0])->coords);
    }
}

void func_800F7884_WariosBattleCanyon(void) {
    s32 i;

    D_800F9AA4_WariosBattleCanyon = NULL;
    for (i = 0; i < 2; i++) {
        func_800F77BC_WariosBattleCanyon(i);
    }
}

void func_800F78C8_WariosBattleCanyon(s16 arg0) {
    Object* obj;

    if (D_800F9AB4_WariosBattleCanyon[arg0] == NULL) {
        if (D_800F9AB0_WariosBattleCanyon == NULL) {
            obj = MBModelCreate(0xF, NULL);
            func_8003E174(obj);
            D_800F9AB0_WariosBattleCanyon = obj;
        } else {
            obj = MBModelParamCreate(D_800F9AB0_WariosBattleCanyon);
        }
        obj->unk_0A |= 2;
        D_800F9AB4_WariosBattleCanyon[arg0] = obj;
        func_800A0D50(&obj->coords, &BoardSpaceGet(D_800F9878_WariosBattleCanyon[arg0])->coords);
    }
}

void func_800F7990_WariosBattleCanyon(void) {
    s32 i;

    D_800F9AB0_WariosBattleCanyon = NULL;
    for (i = 0; i < 2; i++) {
        func_800F78C8_WariosBattleCanyon(i);
    }
}

Object* func_800F79D4_WariosBattleCanyon(s32 arg0) {
    switch (arg0) {
    case 0:
        return D_800F9AB4_WariosBattleCanyon[0];
    case 1:
        return D_800F9AA8_WariosBattleCanyon[0];
    case 2:
        return D_800F9AB4_WariosBattleCanyon[1];
    default:
        return D_800F9AA8_WariosBattleCanyon[1];
    }
}

void func_800F7A3C_WariosBattleCanyon(void) {
    s32 cannon;
    Object* obj;

    cannon = (s32)(s32)HuPrcCurrentGet()->user_data;
    HuPrcSleep(90);
    obj = func_800F79D4_WariosBattleCanyon(cannon);
    func_800A0D50(&obj->coords, &BoardSpaceGet(D_800F9884_WariosBattleCanyon[cannon])->coords);
    EndProcess(NULL);
}

void func_800F7AA4_WariosBattleCanyon(s32 cannon) {
    Object* obj;

    omAddPrcObj(func_800F7A3C_WariosBattleCanyon, 0x4800, 0, 0)->user_data = (void*)(s32)cannon;
    obj = func_800F79D4_WariosBattleCanyon(cannon);
    func_800A0D50(&obj->coords, &BoardSpaceGet(D_800F987C_WariosBattleCanyon[cannon])->coords);
}

void func_800F7B14_WariosBattleCanyon(s16 arg0) {
    Object* obj;

    if (D_800F9AC0_WariosBattleCanyon[arg0] == NULL) {
        if (D_800F9ABC_WariosBattleCanyon == NULL) {
            obj = MBModelCreate(0x43, NULL);
            func_8003E174(obj);
            D_800F9ABC_WariosBattleCanyon = obj;
        } else {
            obj = MBModelParamCreate(D_800F9ABC_WariosBattleCanyon);
        }
        obj->unk_0A |= 2;
        D_800F9AC0_WariosBattleCanyon[arg0] = obj;
        func_800A0D00(&obj->xScale, 0.8f, 0.8f, 0.8f);
        func_800A0D50(&obj->coords, &BoardSpaceGet(D_800F988C_WariosBattleCanyon[arg0])->coords);
        if (GwCommon.boardWork[15] == 0) {
            func_8004CD48(obj, D_800F9894_WariosBattleCanyon[arg0]);
        } else {
            func_8004CD48(obj, D_800F989C_WariosBattleCanyon[arg0]);
        }
    }
}

void func_800F7C3C_WariosBattleCanyon(void) {
    s32 i;

    D_800F9ABC_WariosBattleCanyon = NULL;
    for (i = 0; i < 4; i++) {
        func_800F7B14_WariosBattleCanyon(i);
    }
}

void func_800F7C80_WariosBattleCanyon(s16 cannon, Vec3f* out) {
    func_800A0D50(out, &BoardSpaceGet(D_800F988C_WariosBattleCanyon[cannon])->coords);
}

void func_800F7CC4_WariosBattleCanyon(s16 arg0) {
    Object* obj;

    if (D_800F9AD4_WariosBattleCanyon[arg0] == NULL) {
        if (D_800F9AD0_WariosBattleCanyon == NULL) {
            obj = MBModelCreate(0x10, NULL);
            func_8003E174(obj);
            D_800F9AD0_WariosBattleCanyon = obj;
        } else {
            obj = MBModelParamCreate(D_800F9AD0_WariosBattleCanyon);
        }
        obj->unk_0A |= 2;
        D_800F9AD4_WariosBattleCanyon[arg0] = obj;
        func_800A0D50(&obj->coords, &BoardSpaceGet(D_800F98A4_WariosBattleCanyon[arg0])->coords);
    }
}

void func_800F7D8C_WariosBattleCanyon(void) {
    s32 i;

    D_800F9AD0_WariosBattleCanyon = NULL;
    for (i = 0; i < 1; i++) {
        func_800F7CC4_WariosBattleCanyon(i);
    }
}

s16 func_800F7DCC_WariosBattleCanyon(s32 target) {
    s16 win;
    GW_PLAYER* player;
    Object* obj;
    f32 angle;
    f32 scale;
    s16 space;
    s16 prev;
    s16 abs;
    s32 delay;
    s32 timer;

    player = GetPlayerStruct(-1);
    space = 0;
    prev = -1;
    win = CreateTextWindow(0x73, 0xC8, 7, 1);
    LoadStringIntoWindow(win, (void*)0x1CD, -1, -1);
    func_8006E070(win, 0);
    obj = MBModelCreate(0x4B, NULL);
    func_8003E174(obj);
    timer = 30;
    delay = 0;
    while (1) {
        if (delay == 0) {
            do {
                space = BoardGetRandomSpaceTypeInChain(0xE, D_800F98A8_WariosBattleCanyon[target]);
            } while (prev == space);
            abs = GetAbsSpaceIndexFromChainSpaceIndex(D_800F98A8_WariosBattleCanyon[target], space);
            if (target != 4 && GetChainSpaceIndexFromAbsSpaceIndex(abs, D_800F98B4_WariosBattleCanyon[target]) >= 0 && RNGPercentChance(100)) {
                do {
                    space = BoardGetRandomSpaceTypeInChain(0xE, D_800F98A8_WariosBattleCanyon[target]);
                } while (prev == space);
            }
            prev = space;
            func_800A0D50(&obj->coords, &BoardSpaceGet(GetAbsSpaceIndexFromChainSpaceIndex(D_800F98A8_WariosBattleCanyon[target], space))->coords);
            delay = 3;
            PlaySound(0xC1);
        } else {
            delay--;
        }
        if (PlayerIsCPU(-1) != 0) {
            if (--timer == 0) {
                break;
            }
        } else if (ContBtnTrg[player->port] & 0x8000) {
            break;
        }
        HuPrcVSleep();
    }
    PlaySound(0xC8);
    angle = 0.0f;
    for (timer = 0; timer < 40; timer++) {
        angle += 50.0f;
        if (angle > 360.0f) {
            angle -= 360.0f;
        }
        scale = func_800AEFD0(angle) * 0.3f + 1.2f;
        func_800A0D00(&obj->xScale, scale, 1.0f, scale);
        HuPrcVSleep();
    }
    MBModelKill(obj);
    func_80070D90(win);
    return space;
}

void func_800F80B4_WariosBattleCanyon(void) {
    s32 target;

    target = (s32)(s32)HuPrcCurrentGet()->user_data;
    while (func_80072718() != 0) {
        HuPrcVSleep();
    }
    D_800F9AD8_WariosBattleCanyon = func_800F7DCC_WariosBattleCanyon(target);
    EndProcess(NULL);
}

void func_800F8110_WariosBattleCanyon(s32 target) {
    D_800F9AD8_WariosBattleCanyon = -1;
    omAddPrcObj(func_800F80B4_WariosBattleCanyon, 0x4800, 0, 0)->user_data = (void*)(s32)target;
}

s16 func_800F8158_WariosBattleCanyon(void) {
    return D_800F9AD8_WariosBattleCanyon;
}

void func_800F8164_WariosBattleCanyon(void) {
    Vec3f step;
    WarioSpark* spark;
    Object* obj;
    f32 div;
    s32 alpha;

    alpha = 0xFF;
    spark = HuPrcCurrentGet()->user_data;
    div = 1.0f;
    obj = MBModelCreate(0x67, NULL);
    func_800A0D50(&obj->coords, &spark->pos);
    func_80021240(*obj->unk_3C->unk_40);
    do {
        func_800A0F00(&step, 1.0f / div, &spark->vel);
        func_800211BC(*obj->unk_3C->unk_40, alpha);
        func_800A0E00(&obj->coords, &obj->coords, &step);
        div += 1.3f;
        HuPrcVSleep();
        alpha -= 20;
    } while (alpha > 0);
    spark->active = 0;
    MBModelKill(obj);
    EndProcess(NULL);
}

WarioSpark* func_800F826C_WariosBattleCanyon(void) {
    s32 i;

    for (i = 0; i < 20; i++) {
        if (D_800F9AE0_WariosBattleCanyon[i].active == 0) {
            break;
        }
    }
    if (i == 20) {
        return NULL;
    }
    D_800F9AE0_WariosBattleCanyon[i].active = -1;
    omAddPrcObj(func_800F8164_WariosBattleCanyon, 0x4800, 0, 0)->user_data = &D_800F9AE0_WariosBattleCanyon[i];
    return &D_800F9AE0_WariosBattleCanyon[i];
}

void func_800F8314_WariosBattleCanyon(void) {
    Vec3f dir;
    WarioSpark* spark;
    f32 a;
    s32 i;

    for (i = 0; i < 20; i++) {
        D_800F9AE0_WariosBattleCanyon[i].active = 0;
    }
    for (i = 0; i < 12; i++) {
        spark = func_800F826C_WariosBattleCanyon();
        a = i * 30.0f;
        dir.x = func_800AEFD0(a);
        dir.y = func_800AEAC0(a);
        dir.z = 0.6f;
        func_8003D478(&dir, -45.0f);
        func_8003D514(&dir, func_8003D2B0(&D_800F9D1C_WariosBattleCanyon));
        func_800A0F00(&dir, 56.0f, &dir);
        func_800A0D50(&spark->vel, &dir);
        func_800A0D50(&spark->pos, &D_800F9D10_WariosBattleCanyon);
    }
    for (i = 0; i < 4; i++) {
        spark = func_800F826C_WariosBattleCanyon();
        dir.x = ((u8)(rand8() % 200) - 100) * 0.0015f;
        dir.y = ((u8)(rand8() % 200) - 100) * 0.0015f;
        dir.z = 1.0f;
        func_8003D478(&dir, -45.0f);
        func_8003D514(&dir, func_8003D2B0(&D_800F9D1C_WariosBattleCanyon));
        func_800A0F00(&dir, 72.0f, &dir);
        func_800A0D50(&spark->vel, &dir);
        func_800A0D50(&spark->pos, &D_800F9D10_WariosBattleCanyon);
        HuPrcSleep(1);
    }
    EndProcess(NULL);
}

void func_800F856C_WariosBattleCanyon(s16 playerIndex, s16 cannon) {
    GW_PLAYER* player;
    Object* obj;
    Vec3f* pos;
    BoardSpace* space;

    player = GetPlayerStruct(playerIndex);
    obj = MBModelCreate(D_800F98C8_WariosBattleCanyon[player->character], NULL);
    func_8003E174(obj);
    space = BoardSpaceGet(D_800F988C_WariosBattleCanyon[cannon]);
    func_800A0D50(&player->player_obj->coords, pos = &space->coords);
    func_800A0D50(&obj->unk_18, &D_800F9AC0_WariosBattleCanyon[cannon]->unk_18);
    func_8004CD84(&obj->coords);
    func_800A0F00(&obj->coords, 110.0f, &obj->coords);
    obj->coords.y = 210.0f;
    func_8003D514(&obj->coords, func_8003D2B0(&obj->unk_18));
    func_800A0E00(&obj->coords, &obj->coords, pos);
    D_800F9D28_WariosBattleCanyon = obj;
}

void func_800F8688_WariosBattleCanyon(void) {
    MBModelKill(D_800F9D28_WariosBattleCanyon);
}

void func_800F86A8_WariosBattleCanyon(s32 target) {
    Object* obj;
    f32 speed;
    s16 space;

    obj = GetPlayerStruct(-1)->player_obj;
    speed = func_8004B844();
    func_8004B838(6.0f);
    func_80056E30(2);
    func_80056E48(&BoardSpaceGet(D_800F98BC_WariosBattleCanyon[target])->coords);
    HuPrcSleep(1);
    while (func_8004B850() != 0) {
        HuPrcVSleep();
    }
    func_800F8110_WariosBattleCanyon(target);
    while ((space = func_800F8158_WariosBattleCanyon()) < 0) {
        HuPrcVSleep();
    }
    SetPlayerOntoChain(-1, D_800F98A8_WariosBattleCanyon[target], space);
    func_800A0D50(&obj->coords, &BoardSpaceGet(GetAbsSpaceIndexFromChainSpaceIndex(D_800F98A8_WariosBattleCanyon[target], space))->coords);
    MBModelDispOn(obj);
    obj->unk_0A |= 2;
    obj->unk_30 = 1000.0f;
    obj->unk_34 = 0.0f;
    obj->unk_38 = -10.0f;
    func_80056E30(1);
    MBMotionSet(obj, -1, 0);
    while (obj->unk_38 != 0.0f) {
        if (obj->unk_34 > 30.0f) {
            obj->unk_34 = 30.0f;
        }
        HuPrcVSleep();
    }
    func_80058910(-1, 0);
    HuPrcSleep(15);
    func_8004B838(speed);
}

void func_800F88A0_WariosBattleCanyon(s16 enter) {
    Vec3f pos;
    GW_PLAYER* player;
    s16 win;

    player = GetPlayerStruct(-1);
    if (enter != 0) {
        MBMotionSet(player->player_obj, -1, 0);
        while (func_8004B850() != 0) {
            HuPrcVSleep();
        }
        HuPrcVSleep();
        win = CreateTextWindow(0x64, 0x3C, 0xA, 3);
        LoadStringIntoWindow(win, (void*)0x1CE, -1, -1);
        func_8006E070(win, 0);
        ShowTextWindow(win);
        PlaySound(0xCB);
        func_8004DBD4(win, GetCurrentPlayerIndex());
        HideTextWindow(win);
        PlaySound(0xC4);
        func_800726AC(8, 16);
        while (func_80072718() != 0) {
            HuPrcVSleep();
        }
        func_800559BC();
        func_800405DC(player->player_index);
        func_800F856C_WariosBattleCanyon(-1, GwCommon.boardWork[2]);
        func_800F7AA4_WariosBattleCanyon(GwCommon.boardWork[2]);
        func_800F7C80_WariosBattleCanyon(GwCommon.boardWork[2], &pos);
        func_8005884C(&pos);
        HuPrcVSleep();
        player->player_obj->unk_0A &= ~2;
        MBModelDispOff(player->player_obj);
        SetFadeInTypeAndTime(8, 16);
        HuPrcSleep(15);
        PlaySound(0xC5);
        while (func_80072718() != 0) {
            HuPrcVSleep();
        }
        PlaySound(0xC2);
    }
    HuPrcSleep(15);
    func_800A0D50(&D_800F9D10_WariosBattleCanyon, &D_800F9D28_WariosBattleCanyon->coords);
    func_800A0D50(&D_800F9D1C_WariosBattleCanyon, &D_800F9D28_WariosBattleCanyon->unk_18);
    omAddPrcObj(func_800F8314_WariosBattleCanyon, 0x4800, 0, 0);
    func_800F8688_WariosBattleCanyon();
    HuPrcSleep(2);
    PlaySound(0xBE);
    func_80058910(-1, 5);
    PlaySound(0xC6);
    HuPrcSleep(12);
    if (GwCommon.boardWork[15] == 0) {
        func_800F86A8_WariosBattleCanyon(D_800F98D4_WariosBattleCanyon[GwCommon.boardWork[2]]);
    } else {
        func_800F86A8_WariosBattleCanyon(D_800F98DC_WariosBattleCanyon[GwCommon.boardWork[2]]);
    }
    func_800559F8();
    if (enter != 0) {
        func_8003FEFC(player->player_index);
    }
}

void func_800F8B54_WariosBattleCanyon(void) {
    func_8004D2A4(-1, 8, 0x50);
    GwCommon.boardWork[2] = 0;
    if (_CheckFlag(0x4F) == 0) {
        SetBoardFeatureFlag(0x4F);
        SetBoardFeatureFlag(0x50);
        GwCommon.boardWork[0] = 1;
        func_800587EC(0x50, 0, 1);
        SetEventReturnFlag(1);
    } else {
        func_800F88A0_WariosBattleCanyon(1);
    }
    EndProcess(NULL);
}

void func_800F8BE4_WariosBattleCanyon(void) {
    func_800F88A0_WariosBattleCanyon(0);
    EndProcess(NULL);
}

void func_800F8C08_WariosBattleCanyon(void) {
    func_8004D2A4(-1, 8, 0x3F);
    GwCommon.boardWork[2] = 1;
    func_800F88A0_WariosBattleCanyon(1);
    EndProcess(NULL);
}

void func_800F8C48_WariosBattleCanyon(void) {
    func_8004D2A4(-1, 8, 0x56);
    GwCommon.boardWork[2] = 2;
    func_800F88A0_WariosBattleCanyon(1);
    EndProcess(NULL);
}

void func_800F8C88_WariosBattleCanyon(void) {
    func_8004D2A4(-1, 8, 0x52);
    GwCommon.boardWork[2] = 3;
    func_800F88A0_WariosBattleCanyon(1);
    EndProcess(NULL);
}

void func_800F8CC8_WariosBattleCanyon(void) {
    func_8004D2A4(-1, 8, 0x43);
    func_800587BC(0x53, 0, 3, 1);
    SetEventReturnFlag(1);
    SetBoardFeatureFlag(0x51);
}

// decomp-permuter
void func_800F8D10_WariosBattleCanyon(void)
{
  short new_var;
  new_var = rand8() & 3;
  func_800F86A8_WariosBattleCanyon(new_var);
  func_800559F8();
  EndProcess(0);
}


void func_800F8D48_WariosBattleCanyon(void) {
    func_8004D2A4(-1, 8, 0x3E);
    func_800587EC(0x52, 0, 1);
    SetEventReturnFlag(1);
}

void func_800F8D84_WariosBattleCanyon(Object* obj, Vec3f* target) {
    func_800A0E80(&D_800F9D38_WariosBattleCanyon, target, &obj->coords);
    func_800A0F00(&D_800F9D38_WariosBattleCanyon, 1.0f / 30.0f, &D_800F9D38_WariosBattleCanyon);
}

void func_800F8DC0_WariosBattleCanyon(Object* obj) {
    func_800A0E00(&obj->coords, &obj->coords, &D_800F9D38_WariosBattleCanyon);
    obj->unk_30 *= 0.9f;
}

void func_800F8E10_WariosBattleCanyon(Object* obj, Vec3f* target, Vec3f* vel, f32 accel, f32 maxSpeed) {
    Vec3f d;
    Vec3f pos;

    pos.x = obj->coords.x;
    pos.y = obj->unk_30;
    pos.z = obj->coords.z;
    func_800A0E80(&d, target, &pos);
    func_8003D408(&d);
    func_800A0F00(&d, accel, &d);
    func_800A0E00(vel, &d, vel);
    if (maxSpeed <= func_800A1200(vel)) {
        func_8003D408(vel);
        func_800A0F00(vel, maxSpeed, vel);
    }
    func_800A0E00(&pos, vel, &pos);
    obj->coords.x = pos.x;
    obj->unk_30 = pos.y;
    obj->coords.z = pos.z;
}

void func_800F8F04_WariosBattleCanyon(Object* obj, Object* follow) {
    Vec3f offset;

    func_800A0D00(&offset, 0.0f, 0.0f, -60.0f);
    func_800A0E00(&obj->coords, &follow->coords, &offset);
    obj->unk_30 = follow->unk_30 + 75.0f;
}

void func_800F8F6C_WariosBattleCanyon(void) {
    Object* obj;

    obj = HuPrcCurrentGet()->user_data;
    while (1) {
        if ((obj->unk_30 += 35.0f) >= 700.0f) {
            break;
        }
        HuPrcVSleep();
    }
    MBModelKill(obj);
    EndProcess(NULL);
}

void func_800F8FEC_WariosBattleCanyon(void) {
    Vec3f target;
    GW_PLAYER* player;
    Object* obj;
    Object* cloud;
    BoardSpace* space;
    f32 speed;
    s16 index;

    player = GetPlayerStruct(-1);
    speed = func_8004B844();
    func_8004B838(3.0f);
    func_800F8110_WariosBattleCanyon(4);
    cloud = MBModelCreate(0x10, NULL);
    func_8003E174(cloud);
    obj = player->player_obj;
    func_8004CD84(&obj->unk_18);
    MBModelDispOn(cloud);
    MBModelDispOn(obj);
    func_800A0D50(&obj->coords, &BoardSpaceGet(0x4B)->coords);
    obj->unk_30 = obj->coords.y;
    obj->coords.y = 0.0f;
    func_800A0D50(&target, &BoardSpaceGet(0x4A)->coords);
    func_800A0D00(&D_800F9D2C_WariosBattleCanyon, -10.0f, 13.0f, -11.0f);
    while ((index = func_800F8158_WariosBattleCanyon()) < 0) {
        func_800F8E10_WariosBattleCanyon(obj, &target, &D_800F9D2C_WariosBattleCanyon, 0.4f, 6.0f);
        func_800F8F04_WariosBattleCanyon(cloud, obj);
        HuPrcVSleep();
    }
    SetPlayerOntoChain(-1, D_800F98A8_WariosBattleCanyon[4], index);
    PlaySound(0xCF);
    space = BoardSpaceGet(GetAbsSpaceIndexFromChainSpaceIndex(D_800F98A8_WariosBattleCanyon[4], index));
    func_800F8D84_WariosBattleCanyon(obj, &space->coords);
    while (1) {
        func_800F8DC0_WariosBattleCanyon(obj);
        func_800F8F04_WariosBattleCanyon(cloud, obj);
        if (func_800A13C0(&obj->coords, &space->coords) < 3.0f) {
            break;
        }
        HuPrcVSleep();
    }
    func_80056E30(1);
    omAddPrcObj(func_800F8F6C_WariosBattleCanyon, 0x4800, 0, 0)->user_data = cloud;
    HuPrcSleep(30);
    func_8004B838(speed);
    func_800559F8();
    EndProcess(NULL);
}

void func_800F9210_WariosBattleCanyon(void) {
    GW_PLAYER* other;
    GW_PLAYER* cur;
    s32 index;

    switch (GwCommon.boardWork[1]) {
    case 0:
    case 1:
    case 2:
    case 3:
        index = GwCommon.boardWork[1];
        cur = GetPlayerStruct(-1);
        other = GetPlayerStruct(index);
        SetPlayerOntoChain(index, cur->cur_chain, cur->cur_space - 1);
        func_8004CC8C(index, GetAbsSpaceIndexFromChainSpaceIndex(other->cur_chain, other->cur_space));
        break;
    case 4:
        HuPrcChildLink(HuPrcCurrentGet(), omAddPrcObj(func_800F8FEC_WariosBattleCanyon, 0x4800, 0, 0));
        HuPrcChildWatch();
        break;
    }
    GwCommon.boardWork[1] = -1;
}

void func_800F9308_WariosBattleCanyon(void) {
    func_800587EC(0x51, 0, 4);
    SetEventReturnFlag(1);
    GwCommon.boardWork[15] ^= 1;
}

void func_800F9348_WariosBattleCanyon(void) {
    s16 win;

    win = CreateTextWindow(0x36, 0x3C, 0x12, 2);
    LoadStringIntoWindow(win, (void*)0x1C6, -1, -1);
    func_8006E070(win, 0);
    ShowTextWindow(win);
    func_8004DBD4(win, GwSystem.curPlayerIndex);
    HideTextWindow(win);
    EndProcess(NULL);
}

void func_800F93C8_WariosBattleCanyon(void) {
    func_8004D2A4(-1, 8, 0x55);
    func_800587EC(0x65, 0, 1);
}

void func_800F93FC_WariosBattleCanyon(void) {
    SetNextChainAndSpace(GetCurrentPlayerIndex(), 2, 1);
}

// decomp-permuter
void func_800F942C_WariosBattleCanyon(void)
{
  s16 player;
  s16 win;
  short coins;
  player = GetCurrentPlayerIndex();
  func_800405DC(player);
  SetPlayerAnimation(-1, -1, 2);
  if (_CheckFlag(0x42) == 0)
  {
    win = CreateTextWindow(0x48, 0x3C, 0x10, 3);
    LoadStringIntoWindow(win, (void *) 0x239, -1, -1);
    coins = 10;
  }
  else
  {
    win = CreateTextWindow(0x41, 0x3C, 0x11, 3);
    LoadStringIntoWindow(win, (void *) 0x23A, -1, -1);
    coins = 20;
  }
  func_8006E070(win, 0);
  ShowTextWindow(win);
  PlaySound(0x432);
  func_8004DBD4(win, player);
  HideTextWindow(win);
  func_80055960(player, coins);
  ShowPlayerCoinChange(player, coins);
  HuPrcSleep(30);
  func_8003FEFC(player);
}


void func_800F9560_WariosBattleCanyon(void) {
    GwCommon.boardWork[31]++;
    if (_CheckFlag(0x42) == 0 && (GwCommon.boardWork[31] % 10 == 0 || _CheckFlag(0x4D) == 0)) {
        if (_CheckFlag(0x4D) != 0) {
            func_80058910(-1, 1);
        }
        SetBoardFeatureFlag(0x4D);
        func_800587EC(0x5F, 0, 1);
        return;
    }
    func_800F942C_WariosBattleCanyon();
}

void func_800F9630_WariosBattleCanyon(void) {
    func_8004D2A4(-1, 8, 0x3D);
    func_800F9560_WariosBattleCanyon();
    EndProcess(NULL);
}

void func_800F9664_WariosBattleCanyon(void) {
    if (func_800F6958_WariosBattleCanyon(GetCurrentSpaceIndex()) == 1) {
        func_800587EC(0x44, 0, 2);
        func_8004D2A4(-1, 8, func_800F6610_WariosBattleCanyon());
    }
}

void func_800F96C8_WariosBattleCanyon(void) {
    GW_PLAYER* player;
    s32 i;

    if (func_800F6958_WariosBattleCanyon(GetCurrentSpaceIndex()) == 2) {
        for (i = 0; i < 4; i++) {
            player = GetPlayerStruct(i);
            player->group = i != GetCurrentPlayerIndex();
        }
        func_800587BC(1, 0, 5, 1);
    }
}

void func_800F9754_WariosBattleCanyon(void) {
    InitCameras(2);
    func_8001D4D4(1, &D_800F97E0_WariosBattleCanyon);
    func_800F7030_WariosBattleCanyon();
    func_800584F0(2);
    omAddPrcObj(func_800F6CD8_WariosBattleCanyon, 0x1005, 0, 0);
}
