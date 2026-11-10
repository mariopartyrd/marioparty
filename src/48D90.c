#include "PR/os.h"
#include "engine/mallocblock.h"
#include "engine/data.h"
#include "engine/process.h"

typedef struct {
/* 0x00 */ u16        unk0;
/* 0x02 */ s16        unk2;
/* 0x04 */ void*      data;
/* 0x08 */ HuArchive* archive;
/* 0x0C */ s32        dirTblSize;
/* 0x10 */ u8*        bytes;
} unk20;

typedef struct unkStruct19 {
/* 0x00 */ s32 unk0;
/* 0x04 */ s32 unk4;
/* 0x08 */ s32 unk8;
/* 0x0C */ s32 unkC;
/* 0x10 */ f32 unk_10;
/* 0x14 */ f32 unk_14;
/* 0x18 */ f32 unk_18;
/* 0x1C */ f32 unk_1C;
/* 0x20 */ f32 unk_20;
/* 0x24 */ f32 unk_24;
/* 0x28 */ f32 unk_28;
/* 0x2C */ f32 unk_2C;
/* 0x30 */ f32 unk_30[3]; /* camera up vector (func_8004AFFC: pFloat[12..14]) */
} unkStruct19; //sizeof 0x3C

typedef struct unkStruct17 {
/* 0x00 */ s32 unk_00;
/* 0x04 */ char unk_04[0x0C];
} unkStruct17;

typedef struct Unk800D673C {
    char unk_00[0x2C0];
} Unk800D673C;

extern Unk800D673C* D_800D673C;

extern s32 D_800D6724;

extern u8* D_800D6728; // bytestream

extern Addr* D_800D6720;
extern s16 D_800D6730;
extern s16 D_800D6732;
extern s16 D_800D6734;
extern s16 D_800D6736;
extern s16 D_800D6738;
extern s32 D_800F6598;
extern f32 D_800D672C;
#define PB_BG_POOL 40
extern unk20 D_800D6740[40];
extern unk20 *D_800D6A60[6][6]; // Have no clue what this is

extern OSMesgQueue D_800D6AF0;
extern OSMesg D_800D6B08;
extern OSThread D_800D6BA8;
extern OSThread D_800D7560;
extern s32 D_800D7710;
extern OSMesgQueue D_800D7F20;
extern OSMesg D_800D7F38;
extern OSMesgQueue D_800D7FD8;
extern OSMesg D_800D7FF0;
extern OSMesgQueue D_800D8090;
extern OSMesg D_800D80A8;

extern Process *D_800D80B0;
extern f32 D_800D80B4;
extern f32 D_800D80B8;
extern Vec2f D_800D80BC;
extern Vec2f D_800D80C4; // offset coordinates?
extern Vec3f D_800D80CC;
extern Vec3f D_800D80D8;
extern Vec3f D_800D80E4;
extern Vec3f D_800D80F0;

void func_80028E8C(s32, void*);
void func_8004A7A4(void);
void func_8004AFFC(void);
void func_8004B7F8(s32);
void func_8004ACEC(Gfx**, s32, u8);
void func_8004A19C(s16, s16);
void func_8003A4EC(Gfx**, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_8007F54C(void*, void*, s32, Unk800D673C*);
extern void func_8007FAC0(void);

void func_80048190(Vec3f*);
void func_800481F8(omObjData*);
void func_80048540(void);
void func_80049414(void);
void func_80049478(void);
void func_80049640(void);
void func_80049904(void);
void func_8004858C(omObjData*);
void func_8007166C(s16);
void func_80071598(s16);
extern Vec3f D_800D6670;
extern Vec3f D_800D667C;
extern Vec3f D_800D6688;
extern Vec3f D_800D6694;
extern Vec3f D_800D66A0;
extern s16 D_800D66AC;
extern s16 D_800D66AE;

typedef struct unk48D90Box {
    /* 0x00 */ s16 win;
    /* 0x02 */ s16 x;
    /* 0x04 */ s16 y;
    /* 0x06 */ s16 w;
    /* 0x08 */ s16 h;
} unk48D90Box; //sizeof 0xA

extern s16 D_800D66B0;
extern unk48D90Box D_800D66B8[5];
extern u8 D_800D66EA[5];
extern omObjData* D_800D66F0;
extern s16 D_800D66F4[2];
extern s16 D_800D66F8;
extern s16 D_800D66FA;
extern s16 D_800D66FC;
extern s16 D_800D66FE;
extern s16 D_800D6700;
extern s16 D_800D6702;
extern s16 D_800D6704;
extern s32 D_800D6708;
extern s32 D_800D670C;
extern s32 D_800D6710;
typedef struct unk48D90Rect {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
    /* 0x04 */ s16 w;
    /* 0x06 */ s16 h;
} unk48D90Rect; //sizeof 8

typedef struct unk48D90Step {
    /* 0x00 */ s8 limit;
    /* 0x01 */ s8 x;
} unk48D90Step; //sizeof 2

s8 D_800C4F10 = -1;
unk48D90Rect D_800C4F14[5] = {
    { 0x160, 0x50, 0xC8, 0x14 }, { 0x160, 0x64, 0xC8, 0x14 }, { 0x160, 0x78, 0xC8, 0x14 },
    { 0x160, 0x8C, 0xC8, 0x14 }, { 0x160, 0xA0, 0xC8, 0x14 },
};
u8 D_800C4F3C = 0x5E;
unk48D90Step D_800C4F40[] = { { 1, 0 }, { 9, 15 }, { 11, 8 }, { 13, 0 } };
u8 D_800C4F48[26] = { 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 3, 4, 5, 6, 0, 1, 3, 4, 5, 6 };
u8 D_800C4F64[3] = { 7, 8, 9 };
u32 D_800C4F68 = 0;
u32 D_800C4F6C = 0; /* unreferenced */
s32* D_800C4F70 = NULL;
s32* D_800C4F74 = NULL; // offsets
unkStruct19* D_800C4F78 = NULL;
s8 D_800C4F7C = -1;
Gfx D_800C4F80[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetAlphaDither(G_AD_DISABLE),
    gsSPEndDisplayList(),
};

extern u32 D_800F383C;
void func_8004A7DC(void);
void func_8004B1EC(void);

void func_80048190(Vec3f* arg0) {
    func_8001D494(1, 40.0f, 80.0f, 8000.0f);
    func_8001D420(1, &D_800D6670, &D_800D667C, &D_800D6688);
    func_8001D57C(1);
    func_8001D520(1, &D_800D6694, &D_800D66A0);
}

void func_800481F8(omObjData* arg0) {
    while (TRUE) {
        // retail calls func_80048190 without an argument (its parameter is unused)
        ((void (*)()) func_80048190)();
        HuPrcVSleep();
    }
}

mystery_struct_ret_func_80048224* func_80048224(void* ptr) {
    Process* process;
    mystery_struct_ret_func_80048224* temp_v0;

    temp_v0 = MallocTemp(sizeof(mystery_struct_ret_func_80048224));
    if (temp_v0 != NULL) {
        if (_CheckFlag(0x2C) == 0) {
            temp_v0->unk0 = MBModelCreate(0x5D, ptr);
            func_800A0D00(&temp_v0->unk0->xScale, 0.5f, 0.5f, 0.5f);
            D_800D66AC = 0;
            D_800D66AE = 0;
        } else {
            temp_v0->unk0 = MBModelCreate(0x88, NULL);
            func_800A0D00(&temp_v0->unk0->xScale, 0.3f, 0.3f, 0.3f);
            D_800D66AC = 0xA;
            D_800D66AE = -0xA;
        }
        
        func_80025F10(*temp_v0->unk0->unk_3C->unk_40, 2);
        process = omAddPrcObj(func_800481F8, 0x4000U, 0, 0);
        temp_v0->unk4 = process;
        process->user_data = temp_v0;
        temp_v0->unkA = 0x69;
        
        D_800D6670.x = 0;
        D_800D6670.y = 0;
        D_800D6670.z = 600.0f;
        
        D_800D667C.x = 0;
        D_800D667C.y = 0;
        D_800D667C.z = 0;
        
        D_800D6688.x = 0;
        D_800D6688.y = 1.0f;
        D_800D6688.z = 0;
        
        D_800D6694.x = 1280.0f;
        D_800D6694.y = 960.0f;
        D_800D6694.z = 511.0f;
        
        D_800D66A0.x = (-100.0f - D_800D66AC) * 4.0f + 640.0f;
        D_800D66A0.y = (temp_v0->unkA + D_800D66AE) * 4.0f + 480.0f;
        D_800D66A0.z = 511.5f;
        
        func_80048190(&D_800D66A0);
        temp_v0->unk8 = func_8007194C(0x4B, temp_v0->unkA + 0x5A, 3);
        func_8006E070(temp_v0->unk8, 0);
    }
    return temp_v0;
}

void func_8004847C(mystery_struct_ret_func_80048224* arg0) {
    if (arg0 != NULL) {
        MBModelKill(arg0->unk0);
        EndProcess(arg0->unk4);
        func_80072080(arg0->unk8);
        FreeTemp(arg0);
    }
}

void func_800484C4(Object* arg0, s16 arg1) {
    arg0->unk_0A = arg1;
    D_800D66A0.y = (arg1 + D_800D66AE) * 4.0f + 480.0f;
    func_8006DDC8(arg0->unk_08, 0x4B, arg0->unk_0A + 0x5A);
}

void func_80048540(void) {
    if (D_800F383C >= D_800C4F68 + 4) {
        PlaySound(0x3D);
        D_800C4F68 = D_800F383C;
    }
}

void func_8004858C(omObjData* obj) {
    unk48D90Box* box;
    s32 i;

    switch (obj->work[0]) {
        case 3:
            break;
        case 0:
            obj->trans.y += 16.0f;
            for (i = 0; i < 5; i++) {
                box = &D_800D66B8[i];
                func_8006DDC8(box->win, (s16) (box->x + box->w / 2 - (s32) obj->trans.y), box->y + box->h / 2);
            }
            if (D_800D66FE != -1) {
                func_80066DC4(D_800D66FE, 0, D_800D66B8[0].x - (s32) obj->trans.y + 100, D_800D66B8[0].y + 50);
            }
            if (D_800D66FA != -1) {
                func_80066DC4(D_800D66FA, 0, D_800D66B8[0].x - (s32) obj->trans.y + 100, D_800D66B8[0].y - 30);
            }
            for (i = 0; i < 2; i++) {
                if (D_800D66F4[i] != -1) {
                    func_80066DC4(D_800D66F4[i], 0, D_800D66B8[0].x - (s32) obj->trans.y + i * 200,
                                  D_800D66B8[0].y - 40);
                }
            }
            if (obj->trans.y >= 288.0f) {
                func_80048540();
                func_8007166C(D_800D66B0);
                obj->work[0] = 1;
                obj->scale.x = 1.0f;
                obj->scale.z = -1.0f;
                obj->scale.y = 0.0f;
                obj->work[1] = 0;
                obj->work[2] = rand8() % 5;
                obj->work[3] = 0;
                obj->trans.z = 0.0f;
                i = rand8();
                if (i < 77) {
                    obj->rot.y = 0.0f;
                } else if (i < 115) {
                    obj->rot.y = 1.0f;
                } else if (i < 161) {
                    obj->rot.y = 2.0f;
                } else if (i < 187) {
                    obj->rot.y = 3.0f;
                } else if (i < 200) {
                    obj->rot.y = 4.0f;
                } else if (i < 226) {
                    obj->rot.y = -1.0f;
                } else if (i < 243) {
                    obj->rot.y = -2.0f;
                } else {
                    obj->rot.y = -3.0f;
                }
                i = rand8() & 8;
                if (i < 154) {
                    obj->mdlcnt = 20;
                } else if (i < 231) {
                    obj->mdlcnt = 14;
                } else {
                    obj->mdlcnt = 8;
                }
                obj->mtncnt = 0;
                i = obj->work[2] + (s32) obj->rot.y;
                if (i < 0) {
                    i += 5;
                }
                if (D_800D66EA[i % 5] >= 7) {
                    if (obj->rot.y == 4.0f) {
                        obj->rot.y = 3.0f;
                    } else {
                        obj->rot.y += 1.0f;
                    }
                }
                func_80049904();
            }
            break;
        case 1:
            if (GwPlayer[D_800D6708].flags & 1) {
                obj->trans.z = 1.0f;
            } else if (ContBtnTrg[GwPlayer[D_800D6708].port] & 0x8000) {
                obj->trans.z = 1.0f;
            }
            if (obj->mtncnt != 0) {
                obj->scale.x = obj->mdlcnt / 100.0f;
            }
            obj->scale.z += obj->scale.x;
            if (obj->scale.z >= 1.0f) {
                if (obj->work[3] != 0 && obj->scale.x <= 0.08f) {
                    obj->work[3]--;
                }
                obj->scale.z -= 1.0f;
                if (obj->scale.y == 0.0f) {
                    obj->work[1]++;
                    obj->work[1] %= 5;
                } else {
                    obj->work[1]--;
                    if (obj->work[1] >= 0x80) {
                        obj->work[1] = 4;
                    }
                }
                func_80048540();
            }
            for (i = 0; i < 5; i++) {
                box = &D_800D66B8[i];
                if (i == obj->work[1]) {
                    func_800714F0(box->win, 0, 200, 0);
                    func_8006E154(box->win, 0x100);
                    func_8006E0A4(box->win, 9000);
                } else {
                    func_800714F0(box->win, 0x40, 0x40, 0x80);
                    func_8006E154(box->win, 0);
                    func_8006E0A4(box->win, 10000);
                }
            }
            if (obj->work[1] == obj->work[2] || obj->scale.x < 1.0f) {
                if (obj->trans.z != 0.0f && obj->mtncnt == 0) {
                    obj->scale.x -= 0.02;
                }
            }
            if (obj->scale.x <= 0.08f || obj->mtncnt != 0) {
                if (obj->mtncnt == 0) {
                    obj->scale.x = 0.08f;
                }
                if (obj->work[1] == obj->work[2] && obj->work[3] == 0 && obj->scale.z + obj->scale.x >= 1.0f) {
                    if ((obj->rot.y > 0.0f ? obj->rot.y : 0.0f - obj->rot.y) <= 0.5f) {
                        PlaySound(0x3E);
                        obj->work[0] = 2;
                        obj->work[3] = 60;
                        func_8006DA1C(D_800D66B8[obj->work[1]].win, 0, 4);
                        LoadStringIntoWindow(D_800D66B8[obj->work[1]].win, (void*) (D_800D66EA[obj->work[1]] + 0xBC), -2, 4);
                        func_8006E288(D_800D66B8[obj->work[1]].win, 1);
                        func_8006E2B8(D_800D66B8[obj->work[1]].win, 0xA0, 0xA0, 0xA0);
                        func_800714F0(D_800D66B8[obj->work[1]].win, 0xFE, 0xFF, 0xD0);
                        func_8006E070(D_800D66B8[obj->work[1]].win, 0);
                    } else {
                        obj->mtncnt = 1;
                        if (obj->rot.y >= 0.5f) {
                            obj->rot.y -= 1.0f;
                            obj->work[2]++;
                            obj->work[2] %= 5;
                        } else {
                            obj->rot.y += 1.0f;
                            obj->scale.y = 1.0f;
                            obj->work[2]--;
                            if (obj->work[2] >= 0x80) {
                                obj->work[2] = 4;
                            }
                        }
                    }
                }
            }
            break;
        case 2:
            if (obj->work[3] == 0) {
                obj->work[0] = 4;
                func_80049414();
            } else {
                obj->work[3]--;
                obj->rot.z += 1.0f;
                if (obj->rot.z >= 13.0f) {
                    obj->rot.z -= 13.0f;
                }
            }
            break;
        case 4:
            obj->trans.y -= 32.0f;
            for (i = 0; i < 5; i++) {
                box = &D_800D66B8[i];
                func_8006DDC8(box->win, (s16) (box->x + box->w / 2 - (s32) obj->trans.y), box->y + box->h / 2);
            }
            if (D_800D66FE != -1) {
                func_80066DC4(D_800D66FE, 0, D_800D66B8[0].x - (s32) obj->trans.y + 100, D_800D66B8[0].y + 50);
            }
            if (D_800D66FA != -1) {
                func_80066DC4(D_800D66FA, 0, D_800D66B8[0].x - (s32) obj->trans.y + 100, D_800D66B8[0].y - 30);
            }
            for (i = 0; i < 2; i++) {
                if (D_800D66F4[i] != -1) {
                    func_80066DC4(D_800D66F4[i], 0, D_800D66B8[0].x - (s32) obj->trans.y + i * 200,
                                  D_800D66B8[0].y - 40);
                }
            }
            if (obj->trans.y <= 0.0f) {
                D_800C4F10 = D_800D6710 = D_800D670C = D_800D66EA[obj->work[2]];
                if ((D_800C4F10 == 0) | (D_800C4F10 == 3)) {
                    D_800C4F10 = -1;
                }
                func_80049478();
            }
            break;
    }

    if (D_800D6702 != -1) {
        for (i = 0; !(obj->rot.z < (D_800C4F40 + i)->limit); i++) {
        }
        func_80066DC4(D_800D6702, 0, D_800C4F40[i].x + 50, D_800C4F3C + obj->work[1] * 20);
    }
}

s32 func_80049328(void) {
    return D_800D670C;
}

s32 func_80049334(void) {
    return D_800D6710;
}

s32 func_80049340(void) {
    if (D_800D66F0 == NULL) {
        return -1;
    }
    return D_800D66F0->work[0];
}

void func_8004935C(void) {
    s32 i;

    for (i = 0; i < 5; i++) {
        D_800D66B8[i].win = -1;
    }
    D_800D66F0 = NULL;
    for (i = 0; i < 2; i++) {
        D_800D66F4[i] = -1;
    }
    D_800D66F8 = -1;
    D_800D66FC = -1;
    D_800D66FA = -1;
    D_800D6700 = -1;
    D_800D66FE = -1;
    D_800D6704 = -1;
    D_800D6702 = -1;
    D_800D670C = -1;
    D_800D66B0 = -1;
}

void func_80049414(void) {
    if (D_800D6702 != -1) {
        func_80064D38(D_800D6702);
        D_800D6702 = -1;
    }
    if (D_800D6704 != -1) {
        func_80067704(D_800D6704);
        D_800D6704 = -1;
    }
}

void func_80049478(void) {
    unk48D90Box* box;
    s32 i;

    for (i = 0; i < 5; i++) {
        box = &D_800D66B8[i];
        if (box->win != -1) {
            func_80070D90(box->win);
            box->win = -1;
        }
    }
    if (D_800D66B0 != -1) {
        func_80070D90(D_800D66B0);
        D_800D66B0 = -1;
    }
    if (D_800D66F0 != NULL) {
        omDelObj(D_800D66F0);
        D_800D66F0 = NULL;
    }
    if (D_800D66FE != -1) {
        func_80064D38(D_800D66FE);
        D_800D66FE = -1;
    }
    if (D_800D6700 != -1) {
        func_80067704(D_800D6700);
        D_800D6700 = -1;
    }
    if (D_800D66FA != -1) {
        func_80064D38(D_800D66FA);
        D_800D66FA = -1;
    }
    if (D_800D66FC != -1) {
        func_80067704(D_800D66FC);
        D_800D66FC = -1;
    }
    for (i = 0; i < 2; i++) {
        if (D_800D66F4[i] != -1) {
            func_80064D38(D_800D66F4[i]);
            D_800D66F4[i] = -1;
        }
    }
    if (D_800D66F8 != -1) {
        func_80067704(D_800D66F8);
        D_800D66F8 = -1;
    }
    func_80049414();
}

void func_80049640(void) {
    void* data;
    s32 i;

    if (D_800D66FE == -1) {
        D_800D66FE = func_80064EF4(1, 5);
        data = DataRead(0xA0023);
        D_800D6700 = func_800678A4(data);
        DataClose(data);
        func_80067208(D_800D66FE, 0, D_800D6700, 0);
        func_80067384(D_800D66FE, 0, 0x4770);
        func_800674BC(D_800D66FE, 0, 0x1000);
        func_80066DC4(D_800D66FE, 0, D_800D66B8[0].x + 100, D_800D66B8[0].y + 50);
        func_800674F4(D_800D66FE, 0, 0, 0, 0);
        D_800D66FA = func_80064EF4(1, 5);
        data = DataRead(0xA0026);
        D_800D66FC = func_800678A4(data);
        DataClose(data);
        func_80067208(D_800D66FA, 0, D_800D66FC, 0);
        func_80067384(D_800D66FA, 0, 0x4770);
        func_800674BC(D_800D66FA, 0, 0x1000);
        func_80066DC4(D_800D66FA, 0, D_800D66B8[0].x + 100, D_800D66B8[0].y - 30);
        data = DataRead(0xA0162);
        D_800D66F8 = func_800678A4(data);
        DataClose(data);
        for (i = 0; i < 2; i++) {
            D_800D66F4[i] = func_80064EF4(1, 5);
            func_80067208(D_800D66F4[i], 0, D_800D66F8, 1);
            func_80067384(D_800D66F4[i], 0, 0x4770);
            func_800674BC(D_800D66F4[i], 0, 0x1000);
            func_80066DC4(D_800D66F4[i], 0, D_800D66B8[0].x + i * 200, D_800D66B8[0].y - 40);
            func_800674F4(D_800D66F4[i], 0, 0xFF, 0, 0);
        }
    }
}

void func_80049904(void) {
    void* data;

    if (D_800D6702 == -1) {
        D_800D6702 = func_80064EF4(1, 5);
        data = DataRead(0xA0027);
        D_800D6704 = func_800678A4(data);
        DataClose(data);
        func_80067208(D_800D6702, 0, D_800D6704, 0);
        func_80067384(D_800D6702, 0, 0x100);
        func_800674BC(D_800D6702, 0, 0x1000);
        func_80066DC4(D_800D6702, 0, 0x32, D_800C4F3C);
    }
}

// i++ after the i == 4 test folds to li 5; base not hoisted; register allocation (masked 28)
#ifdef NON_MATCHING
void func_800499CC(s32 arg0) {
    unk48D90Box* box;
    unk48D90Rect* rect;
    omObjData* obj;
    s32 i;
    s32 j;
    s32 k;
    s32 a;
    s32 b;
    u8 t;

    i = 0;
    do {
        box = &D_800D66B8[i];
        rect = D_800C4F14 + i;
        box->x = rect->x;
        box->y = rect->y;
        box->w = rect->w;
        box->h = rect->h;
        box->win = func_8006D010(box->x + box->w / 2, box->y + box->h / 2, box->w, box->h, 0, 0);
        func_800717C0(box->win);
        func_8006DEC8(box->win, box->w / 2, box->h / 2);
        func_8006E154(box->win, 0);
    retry:
        if (i == 4) {
            i++;
            D_800D66EA[4] = D_800C4F64[(u8) (rand8() % 3)];
        } else {
            D_800D66EA[i] = D_800C4F48[(u8) (rand8() % 26)];
            for (j = 0; j < i; j++) {
                if (D_800D66EA[j] == D_800D66EA[i]) {
                    break;
                }
            }
            if (j != i) {
                goto retry;
            }
            if (D_800D66EA[i] == D_800C4F10) {
                goto retry;
            }
            switch (D_800D66EA[i]) {
                case 3:
                    if (GwPlayer[arg0].coins < 15) {
                        goto retry;
                    }
                    break;
                case 5:
                    for (k = 0; k < 4; k++) {
                        if ((k == arg0) ? (GwPlayer[arg0].coins < 15) : (GwPlayer[k].coins < 5)) {
                            break;
                        }
                    }
                    if (k != 4) {
                        goto retry;
                    }
                    break;
            }
            i++;
        }
    } while (i < 5);

    for (i = 0; i < 10; i++) {
        do {
            a = (u8) (rand8() % 5);
            b = (u8) (rand8() % 5);
        } while (a == b);
        t = D_800D66EA[a];
        D_800D66EA[a] = D_800D66EA[b];
        D_800D66EA[b] = t;
    }

    for (i = 0; i < 5; i++) {
        box = &D_800D66B8[i];
        LoadStringIntoWindow(box->win, (void*) (D_800D66EA[i] + 0xBC), -2, 4);
        func_8006E070(box->win, 0);
    }

    obj = D_800D66F0 = omAddObj(-0x8000, 0, 0, -1, func_8004858C);
    obj->work[0] = 3;
    obj->trans.y = 0.0f;
    obj->rot.z = 0.0f;
    func_80049640();
    D_800D6708 = arg0;
    D_800D66B0 = func_8006D010(0x7B, 0xC8, 0x82, 0x14, 0, 0);
    func_8006E154(D_800D66B0, 0);
    LoadStringIntoWindow(D_800D66B0, (void*) 0xC7, -1, -1);
    func_8006E070(D_800D66B0, 0);
    func_80071598(D_800D66B0);
}
#else
INCLUDE_ASM("asm/nonmatchings/48D90", func_800499CC);
#endif

void func_80049E60(void) {
    D_800D66F0->work[0] = 0;
}

void LoadBackgroundData(Addr arg0) {
    s32 temp_s0;
    s32* temp_v0;
    s32* temp_v0_2;

    D_800D6720 = arg0;
    temp_v0 = MallocTemp(0x10);
    dmaRead((u8*) arg0, temp_v0, 0x10);
    D_800D6724 = *temp_v0;
    FreeTemp(temp_v0);
    temp_s0 = D_800D6724 * 4;
    temp_v0_2 = MallocTemp(temp_s0);
    D_800C4F70 = temp_v0_2;
    dmaRead((u8*)arg0 + 4, temp_v0_2, temp_s0);
    D_800D673C = MallocTemp(sizeof(Unk800D673C));
}

void func_80049F0C(void) {
    if (D_800C4F70 != NULL) {
        FreeTemp(D_800C4F70);
        D_800C4F70 = NULL;
        FreeTemp(D_800D673C);
    }
}

void LoadBackgroundIndex(s32 arg0) {
    unkStruct17* temp_v0;
    s32 temp_s0;

    D_800F6598 = arg0;
    D_800D6728 = (u8*)((u8*)D_800D6720 + D_800C4F70[arg0]);
    temp_v0 = MallocTemp(sizeof(unkStruct17));
    dmaRead(&D_800D6728[0], temp_v0, 0x10);
    arg0 = temp_v0->unk_00;
    FreeTemp(temp_v0);
    temp_s0 = arg0 * 4;
    D_800C4F74 = MallocTemp(temp_s0);
    dmaRead(&D_800D6728[4], D_800C4F74, temp_s0);
    D_800C4F78 = MallocTemp(sizeof(unkStruct19));
    dmaRead(&D_800D6728[*D_800C4F74], D_800C4F78, 0x3C);
    D_800C4F78->unk_18 = (f32) (D_800C4F78->unk_18 * 5.0f);
    D_800C4F78->unk_1C = (f32) (D_800C4F78->unk_1C * 5.0f);
    D_800C4F78->unk_20 = (f32) (D_800C4F78->unk_20 * 5.0f);
    D_800C4F78->unk_24 = (f32) (D_800C4F78->unk_24 * 5.0f);
    D_800C4F78->unk_28 = (f32) (D_800C4F78->unk_28 * 5.0f);
    D_800C4F78->unk_2C = (f32) (D_800C4F78->unk_2C * 5.0f);
    D_800D6734 = 0;
    D_800D6732 = 0;
    D_800D6736 = (D_800C4F78->unk0 * D_800C4F78->unk8) / 2;
    D_800D6738 = (D_800C4F78->unk4 * D_800C4F78->unkC) / 2;
    D_800D6730 = 1;
    func_80028E8C(0, (&func_8004ACEC));
    func_8004A7A4();
    func_8004A510();
    func_8004AFFC();
    func_8004B5C4(1.0f);
    func_8004B7F8(0xFF);
    func_8004B838(-1.0f);
}

void func_8004A140(void) {
    if (D_800C4F74 != NULL) {
        FreeTemp(D_800C4F74);
        D_800C4F74 = NULL;
        FreeTemp(D_800C4F78);
        func_80028E8C(0, NULL);
        func_8004A7DC();
        func_8004B1EC();
    }
}

void func_8004A19C(s16 arg0, s16 arg1) {
    D_800D6732 = arg0;
    D_800D6734 = arg1;
}

u16 func_8004A1B0(Vec2f* arg0, f32 arg1) {
    u16 ret = 0;
#define hv 160.0f

    if (arg0->x <= ((-D_800D6736 + hv) / arg1) + 160.0f) {
        arg0->x =  ((-D_800D6736 + hv) / arg1) + 160.0f;
        ret |= 1;
    }

    if (arg0->x >= ((D_800D6736 - hv) / arg1) + 160.0f) {
        arg0->x =  ((D_800D6736 - hv) / arg1) + 160.0f;
        ret |= 2;
    }
#undef hv

    if (arg0->y <= ((-D_800D6738 + 120.0f) / arg1) + 120.0f) {
        arg0->y =  ((-D_800D6738 + 120.0f) / arg1) + 120.0f;
        ret |= 4;
    }

    if (arg0->y >= ((D_800D6738 - 120.0f) / arg1) + 120.0f) {
        arg0->y =  ((D_800D6738 - 120.0f) / arg1) + 120.0f;
        ret |= 8;
    }

    return ret;
}

void func_8004A2E8(u16 arg0) {
    s16 var_v0;

    if (arg0) {
        var_v0 = (u16) D_800D6730 | 1;
    } else {
        var_v0 = (u16) D_800D6730 & 0xFFFE;
    }
    D_800D6730 = var_v0;
}

void func_8004A31C(void) {
    unk20* sp10;

    while (TRUE) {
        osRecvMesg(&D_800D6AF0, (OSMesg) &sp10, 1);
        if (sp10 == NULL) break;
        dmaRead(sp10->bytes, sp10->archive, sp10->dirTblSize);
        osSendMesg(&D_800D7F20, sp10, 0);
    }
    osSendMesg(&D_800D8090, (OSMesg) 1, 0);
    osDestroyThread(NULL);
}

void func_8004A394(void) {
    unk20* sp10;

    func_8007FAC0();
    while (TRUE) {
        osRecvMesg(&D_800D7F20, (OSMesg) &sp10, 1);
        if (sp10 == NULL) break;
        func_8007F54C(sp10->archive, sp10->data, 0x40, D_800D673C);
        osSendMesg(&D_800D7FD8, sp10, 0);
    }
    osSendMesg(&D_800D8090, (OSMesg )2, 0);
    osDestroyThread(0);
}

void func_8004A41C(void) {
    osCreateMesgQueue(&D_800D6AF0, &D_800D6B08, 0x28);
    osCreateMesgQueue(&D_800D7F20, &D_800D7F38, 0x28);
    osCreateMesgQueue(&D_800D7FD8, &D_800D7FF0, 0x28);
    osCreateMesgQueue(&D_800D8090, &D_800D80A8, 2);
    D_800D7710 = 1;
    osCreateThread(&D_800D7560, 0x64, (void*)&func_8004A394, 0, &D_800D7F20, 1);
    osStartThread(&D_800D7560);
    osCreateThread(&D_800D6BA8, 0x65, (void*)&func_8004A31C, 0, &D_800D7560, 4);
    osStartThread(&D_800D6BA8);
}

void func_8004A510(void) {
    D_800D7710 = 3;
}

void func_8004A520(void) {
    D_800D7710 = 1;
}

void func_8004A530(void) {
    if (osGetThreadPri(&D_800D7560) != D_800D7710) {
        osSetThreadPri(&D_800D7560, D_800D7710);
    }
}

void func_8004A56C(void) {
    unk20* mesg;
    while (osRecvMesg(&D_800D7FD8, (OSMesg) &mesg, 0) == 0) {
        if (mesg) {
            FreeTemp(mesg->archive);
            mesg->archive = NULL;
        }
    }
}

void func_8004A5BC(void) {
    HuArchive* pArchive;
    s32 i;
    unk20* unkFile;

    osJamMesg(&D_800D6AF0, 0, 0);
    osJamMesg(&D_800D7F20, 0, 0);
    func_8004A510();
    func_8004A530();
    osRecvMesg(&D_800D8090, 0, 1);
    osRecvMesg(&D_800D8090, 0, 1);
    for (i = 0; i < PB_BG_POOL; i++) {
        unkFile = &D_800D6740[i];
        pArchive = unkFile->archive;
        if (pArchive != NULL) {
            FreeTemp(pArchive);
            unkFile->archive = NULL;
        }
    }
}

void func_8004A684(void) {
    unk20* var_s0;
    s32 i;

    var_s0 = D_800D6740;
    for(i = 0; i < PB_BG_POOL; i++) {
        var_s0->unk0 = 0;
        var_s0->unk2 = -1;
        var_s0->data = func_80023668(0x1800);
        var_s0->archive = NULL;
        var_s0++;
    }
    bzero(&D_800D6A60, sizeof(D_800D6A60)); /* retail wrote sizeof(Object): the same 0x90 bytes on the N64 only */
}

void func_8004A6F8(void) {
    unk20* var_v1;
    s32 i;

    var_v1 = D_800D6740;
    for(i = 0; i < PB_BG_POOL; i++) {
        if ((var_v1->archive == NULL) &&
             ((u16) var_v1->unk0 == 0)) {
            var_v1->unk2 = -1;
        }
        var_v1->unk0 = 0;
        var_v1++;
    }
}

void func_80023728(void*);

void func_8004A73C(void) {
    unk20* unkFile;
    void* pData;
    s32 i;

    unkFile = D_800D6740;
    for (i = 0; i < PB_BG_POOL; i++) {
        unkFile->unk0 = 0;
        unkFile->unk2 = -1;
        pData = unkFile->data;
        if (pData != NULL) {
            func_80023728(pData);
            unkFile->data = NULL;
        }
        unkFile++;
    }
}

void func_8004A7A4(void) {
    func_8004A684();
    func_8004A41C();
    D_800D6730 |= 4;
}

void func_8004A7DC(void) {
    func_8004A5BC();
    func_8004A73C();
    D_800D6730 &= 0xFFFB;
}

u16 func_8004A814(s32 arg0, s32 arg1) {
    return (D_800C4F78->unkC - arg1 - 1) * D_800C4F78->unk8 + arg0 + 1;
}

/* Get size of table */
u32 func_8004A844(u16 arg0) {
    return D_800C4F74[arg0 + 1] - D_800C4F74[arg0];
}

/* Get file bytes */
u8* func_8004A868(u16 arg0) {
    return D_800D6728 + D_800C4F74[arg0];
}

/* Find or create file object */
unk20* func_8004A890(u16 arg0) {
    unk20* var_s1;
    unk20* var_v1;
    s32 i;

    var_s1 = NULL;
    for (var_v1 = D_800D6740, i = 0; i < PB_BG_POOL; var_v1++, i++) {
        if (var_v1->unk2 == -1) {
            var_s1 = var_v1;
        } else if (var_v1->unk2 == arg0) {
            var_v1->unk0 = 1;
            return var_v1;
        }
    }

    if (var_s1) {
        u32 tblSize;
        var_s1->unk0 = 1;
        var_s1->unk2 = arg0;
        var_s1->bytes = func_8004A868(arg0);

        tblSize = func_8004A844(arg0);
        var_s1->dirTblSize = tblSize;
        var_s1->archive = MallocTemp(tblSize);
        osSendMesg(&D_800D6AF0, var_s1, 0);
    }
    return var_s1;
}


void func_8004A950(void) {
    s32 var_s1;
    u32 var_s2;
    s32 i, j;

    var_s2 = ((D_800D6738 + D_800D6734) - 0x78) / 48;
    for (i = 0; i < 6; var_s2++, i++) {
        s32 temp = D_800D6736 + D_800D6732 - 0xA0;
        if (temp < 0) {
            temp = D_800D6736 + D_800D6732 - 0x61;
        }
        var_s1 = temp >> 6;
        for (j = 0; j < 6; var_s1++, j++) {
            if (((((u32) var_s1 >> 0x1F) | (var_s2 >> 0x1F)) != 0) ||
                ((var_s1 < D_800C4F78->unk8) == 0) ||
                ((s32) var_s2 >= D_800C4F78->unkC)) {
                D_800D6A60[j][i] = NULL;
            } else {
                D_800D6A60[j][i] = func_8004A890(func_8004A814(var_s1, var_s2));
            }
        }
    }
}

// y sign extension hoisted out of the loop (masked 10)
#ifdef NON_MATCHING
void func_8004AAA8(Gfx** gfx, void* tex, s32 x, s16 y) {
    s32 i;

    for (i = 0; i < 2; i++) {
        func_8003A4EC(gfx, (s32) tex + i * (64 * 24 * 2), G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 24, 0, 0, 64, 24, 0,
                      G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPScisTextureRectangle((*gfx)++, x * 4, (y + i * 24) * 4, (x + 64) * 4, (y + (i + 1) * 24) * 4,
                                G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/48D90", func_8004AAA8);
#endif


void func_8004ACEC(Gfx** gfx, s32 arg1, u8 arg2) {
    s16 prev;
    s16 i;
    s16 j;
    s16 offY;
    s16 offX;

    if (arg2 == 0 && (D_800D6730 & 4)) {
        func_8004A56C();
        if (D_800D6730 & 1) {
            func_8004A6F8();
            prev = func_80061228(0, 0, 0);
            func_8004A950();
            func_80061264(prev);
            offY = (D_800D6738 + D_800D6734 - 120) % 48;
            offX = (D_800D6736 + D_800D6732 - 160) % 64;
            gSPDisplayList((*gfx)++, D_800C4F80);
            gDPSetEnvColor((*gfx)++, 0xFF, 0xFF, 0xFF, (u8) D_800C4F7C);
            if ((u8) D_800C4F7C < 0xFF) {
                if (D_800D6730 & 8) {
                    gDPSetCombine((*gfx)++, 0x52FEA5, 0x11FFFBFD);
                } else {
                    gDPSetCombine((*gfx)++, 0xFFFFFF, 0xFFFCFA7D);
                }
                gDPSetRenderMode((*gfx)++, 0x504240, 0);
            } else {
                if (D_800D6730 & 8) {
                    gDPSetCombine((*gfx)++, 0x52FEA5, 0x11FFF3F9);
                }
                gDPSetRenderMode((*gfx)++, 0x552048, 0);
            }
            for (j = 0; j < 6; j++) {
                for (i = 0; i < 6; i++) {
                    if (D_800D6A60[i][j] != NULL) {
                        func_8004AAA8(gfx, D_800D6A60[i][j]->data, (s16) (i * 64 - offX), (s16) (j * 48 - offY));
                    }
                }
            }
            func_8004A530();
        }
    }
}

void func_8001D57C(s16);
void omPrcSetStatBit(Process*, s32);
void func_8004B208(void);

void func_8004AFFC(void) {
    f32 temp_f2;
    Process *temp_v0;
    f32 *pFloat = (f32*) D_800C4F78;

    temp_f2 = (D_800C4F78->unk4 * D_800C4F78->unkC) / 240.0f;
    D_800D80B8 = temp_f2;
    D_800D80CC.x = pFloat[6];
    D_800D80CC.y = pFloat[7];
    D_800D80CC.z = pFloat[8];
    D_800D80D8.x = pFloat[9];
    D_800D80D8.y = pFloat[10];
    D_800D80D8.z = pFloat[11];
    D_800D80E4.x = pFloat[12];
    D_800D80E4.y = pFloat[13];
    D_800D80E4.z = pFloat[14];
    D_800D80F0.x = (temp_f2 * 640.0f);
    D_800D80F0.y = (temp_f2 * 480.0f);
    D_800D80F0.z = 511.0f;
    D_800D80C4.x = 640.0f;
    D_800D80C4.y = 480.0f;
    D_800D80BC.x = 159.5f;
    D_800D80BC.y = 119.5f;
    D_800D80B4 = 1.0f;
    temp_v0 = omAddPrcObj(&func_8004B208, 0x1001, 0, 0);
    D_800D80B0 = temp_v0;
    omPrcSetStatBit(temp_v0, 0x80);
    func_8001D494(0, ((f32*)D_800C4F78)[4], 80.0f, 8000.0f);
    func_8001D420(0, &D_800D80CC, &D_800D80D8, &D_800D80E4);
    func_8001D57C(0);
}

void func_8004B1B8(void) {
    if (D_800D80B0) {
        EndProcess(D_800D80B0);
        D_800D80B0 = NULL;
    }
}

void func_8004B1EC(void) {
    func_8004B1B8();
}

void func_8004B208(void) {
    Vec3f vec2;
    Vec2hu halfs;
    Vec3f vec;
    f32 temp_f4;
    f32 var_f2, var_f0;

    while (TRUE) {
        f32 temp_f0 = func_800A13C0(&D_800D80CC, &D_800D80D8);
        if (temp_f0 < 5000.0f) {
            var_f2 = 80.0f;
            var_f0 = 8000.0f;
        } else if (temp_f0 < 15000.0f) {
            var_f2 = 1000.0f;
            var_f0 = 20000.0f;
        } else {
            var_f2 = 3000.0f;
            var_f0 = 28000.0f;
        }
        func_8001D494(0, ((f32*)D_800C4F78)[4], var_f2, var_f0);
        func_8001D420(0, &D_800D80CC, &D_800D80D8, &D_800D80E4);
        func_8001D57C(0);
        vec.x = ((((D_800D80BC.x - 160.0f) * D_800D80B8 * -4.0f) + 640.0f) - D_800D80C4.x) / D_800D80B4;
        vec.y = ((((D_800D80BC.y - 120.0f) * D_800D80B8 * -4.0f) + 480.0f) - D_800D80C4.y) / D_800D80B4;
        vec.z = 0;
        temp_f4 = func_800A1200(&vec) / 4.0f;
        if (temp_f4 <= 1.0f) {
            D_800D6730 = (u16) D_800D6730 & 0xFFFD;
            D_800D80C4.x = ((D_800D80BC.x - 160.0f) * D_800D80B8 * -4.0f) + 640.0f;
            D_800D80C4.y = ((D_800D80BC.y - 120.0f) * D_800D80B8 * -4.0f) + 480.0f;
        } else {
            D_800D6730 = (u16) D_800D6730 | 2;
            if ((D_800D672C >= 0.0f) && (D_800D672C < temp_f4)) {
                func_8003D408((Vec3f* ) &vec);
                func_800A0F00((Vec3f* ) &vec, D_800D672C * 4.0f, (Vec3f* ) &vec);
            }
            D_800D80C4.x += vec.x;
            D_800D80C4.y = D_800D80C4.y + vec.y;
        }
        halfs.x = (u16) (s32) (D_800D80C4.x / 4.0f);
        halfs.y = (u16) (s32) (D_800D80C4.y / 4.0f);
        vec2.x = (f32) (((s32) (D_800D80C4.x / 4.0f) << 0x10) >> 0xE);
        vec2.y = (f32) (((s32) (D_800D80C4.y / 4.0f) << 0x10) >> 0xE);
        vec2.z = 511.5f;
        func_8001D520(0, &D_800D80F0, &vec2);
        func_8004A19C( -halfs.x + 0xA0, -halfs.y + 0x78);
        HuPrcVSleep();
    }
}

void func_8004B5C4(f32 arg0) {
    D_800D80B4 = arg0;
}

f32 func_8004B5D0(void) {
    return D_800D80B4;
}

u16 func_8004B5DC(Vec3f* coords3D) {
    Convert3DTo2D(0, coords3D, &D_800D80BC);
    return func_8004A1B0(&D_800D80BC, D_800D80B8);
}

u16 func_8004B61C(Vec2f* arg0) {
    D_800D80BC.x = (arg0->x / D_800D80B8) + 160.0f;
    D_800D80BC.y = (arg0->y / D_800D80B8) + 120.0f;
    return func_8004A1B0(&D_800D80BC, D_800D80B8);
}

void func_8004B68C(Vec2f* arg0) {
    arg0->x = (f32) ((D_800D80BC.x - 160.0f) * D_800D80B8);
    arg0->y = (f32) ((D_800D80BC.y - 120.0f) * D_800D80B8);
}

void func_8004B6D8(Vec2f* arg0) {
    arg0->x = -((D_800D80C4.x / 4.0f) - 160.0f);
    arg0->y = -((D_800D80C4.y / 4.0f) - 120.0f);
}

void func_8004B730(Vec3f* coords3D, Vec2f* offsetCoords2D) {
    Vec2f coords2D;
    Vec2f offset;

    Convert3DTo2D(0, coords3D, &coords2D);
    coords2D.x = ((coords2D.x - 160.0f) * D_800D80B8) + 160.0f;
    coords2D.y = ((coords2D.y - 120.0f) * D_800D80B8) + 120.0f;
    offset.x = (D_800D80C4.x / 4.0f) - 160.0f;
    offset.y = (D_800D80C4.y / 4.0f) - 120.0f;
    offsetCoords2D->x = coords2D.x + offset.x;
    offsetCoords2D->y = coords2D.y + offset.y;
}

void func_8004B7F8(s32 arg0) {
    D_800C4F7C = arg0;
}

void func_8004B804(s16 flag) {
    if (flag) {
        D_800D6730 |= 8;
    } else {
        D_800D6730 &= 0xFFF7;
    }
}

void func_8004B838(f32 arg0) {
    D_800D672C = arg0;
}

f32 func_8004B844(void) {
    return D_800D672C;
}

s32 func_8004B850(void) {
    return D_800D6730 & 2;
}
