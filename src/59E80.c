#include "common.h"
#include "PR/os.h"

typedef struct {
    /* 0x00 */ u8* list;
    /* 0x04 */ u8 count;
} MgUnlockGroup;

typedef struct {
    /* 0x00 */ s32 shownFlag;
    /* 0x04 */ s32 nameStr;
    /* 0x08 */ s32 ownedFlag;
} ItemListEntry;
u8 D_800C5720 = 0;
u8 D_800C5721 = 0;
u8 D_800C5722 = 0;
u8 D_800C5723 = 0;
u8 D_800C5724[4] = { 1, 1, 1, 1 };
u8 D_800C5728[7] = { 0, 0, 0, 0, 0, 0, 0 };
u8 D_800C572F = 0;
extern u8 D_800C4E14[], D_800C4E24[], D_800C4E2C[], D_800C4E38[];
MgUnlockGroup D_800C5730[4] = { { D_800C4E14, 10 }, { D_800C4E24, 5 }, { D_800C4E2C, 10 }, { D_800C4E38, 25 } };
ItemListEntry D_800C5750[16] = {
    { 25, 0x85, 7 }, { 27, 0x87, 9 }, { 30, 0x8A, 12 }, { 32, 0x8C, 14 },
    { -1, 0x95, -3 }, { 36, 0x90, -2 }, { 34, 0x8E, -4 }, { 39, 0x93, -4 },
    { 26, 0x86, 8 }, { 28, 0x88, 10 }, { 29, 0x89, 11 }, { 33, 0x8D, 15 },
    { 31, 0x8B, -4 }, { 37, 0x91, -1 }, { 35, 0x8F, -4 }, { 40, 0x94, -4 }
};
s32 D_800C5810 = 1;
s32 D_800C5814 = 0x32;

extern char D_800D87D8[][18];
extern s16 D_800D8722[4];
extern s32 D_800D872C;
extern s32 D_800D8730;
extern char D_800D8738[8][20];
extern char D_800D88F8[6];
extern char D_800D88FE[4];
extern s16 D_800D8902;
extern s16 D_800D8904;
extern s16 D_800D8906;
extern f32 D_800D8908;
extern f32 D_800D890C;
extern u8* D_800D8910;
extern s32 D_800D8914;
extern s32* D_800D8918;
extern u16 D_800ED0CE;
extern const char D_800CB4C4[];
extern u16 D_800F2CF0[];
extern Vec3f* D_800ED610;
extern Vec3f* D_800ED72C;
extern u8 D_800F64F8;
extern u16 D_800F384C;
extern TextWindow* D_800ED4B0;
extern s8 omSysPauseEnableFlag;

void func_8005A4C0(omObjData* obj);
void func_8005AA88(omObjData* obj);
void func_8005AA5C(omObjData* obj);
void func_8005AC50(void);
void func_8005B510(void);
void func_8005B648(s8 vol, s16 time);
void func_8005B5D8(void);
s32 func_8005AE88(void);
f32 func_80059DAC(f32 angle);
f32 func_80059E28(f32 a, f32 b);
s32 func_80059CB8(void);
void func_8005A2B8(s16 win, s32 start);
void func_8005A9D8(s16 win);
void* func_8005B7E8(s32 stringIndex);
void func_8005B838(void* arg0);
void func_8005CDE0(void);
void func_8005CE04(void);
void func_8005B358(u8* buf);
int abs(int);
s16 func_80028784(void*, s16);
f32 func_80025D18(s16);
f32 func_80025D40(s16);
TextWindow* func_8006DD60(s16);
s16 func_8006DB3C(s16, s32, s16, s16, s16);
void func_80071598(s16);
s8 func_8000C4A0(void);


#define EEP_ABS_OFFSET_GWCOMMON     0
#define EEP_ABS_OFFSET_GWPLAYER     sizeof(GwCommon)
#define EEP_ABS_OFFSET_GWSYSTEM     EEP_ABS_OFFSET_GWPLAYER + sizeof(GwPlayer)
#define EEP_ABS_OFFSET_GWQUEST      EEP_ABS_OFFSET_GWSYSTEM + sizeof(GwSystem)
#define EEP_ABS_OFFSET_UNK          EEP_ABS_OFFSET_GWQUEST + sizeof(GwQuest)
#define EEP_ABS_EEP_SIZE            0x1F0 //size of total eeprom data

//the hudson header is at the beginning and takes up 8 bytes
typedef struct SaveFile {
/* 0x000 */ GWCOMMON common;
/* 0x094 */ GW_PLAYER player[4];
/* 0x154 */ GW_SYSTEM system;
/* 0x17A */ GWQUEST quest;
/* 0x189 */ char pad[0x67];
} SaveFile; //

//used to allow offsets from structs for the eep file offsets
#define offsetof(st, m) \
    ((u32)&(((st *)0)->m))

extern u8 D_800D8720;
s32 func_800141FC(s16 arg0);
s32 InitEeprom(char*);
s32 func_8005AFEC(void);
s32 ReadEeprom(s32, u8*, s32);
void func_8005B060(void);
void func_8000B364(s32);

#define HEAP_CONSTANT 0xA5
#define MIN_ALLOC_SIZE 16
#define MIN_HEAP_NODE_SIZE sizeof(struct HeapNode) + MIN_ALLOC_SIZE

typedef struct StrData {
/* 0x00 */ s32 string; /* ROM address */
/* 0x04 */ u16 size;
} StrData;

extern u32 D_800ED120[];
extern s16 D_800ED102[];
extern u8 D_800ED119[];

void func_8005B75C(s32, StrData*);
u16* func_80059520(s16);
void func_80059354(s16 param_1, s16 *param_2, s16 *param_3);
void func_80059768(s16 index, s16 param_2);
void func_8005963C(s16 index, u16 param_2);
s32 CalcChecksumEeprom(u16 checksumAddrOffset, u16 size);

void func_80059280(void) {
    s32 i;
    GWCOMMON* common;

    common = &GwCommon;
    bzero(common, sizeof(GWCOMMON));
    common->unk0 = 0x12;
    common->coinNum = 0;
    common->starNum = 0;
    common->unk_46 = -1;
    common->boardItem = 0;
    SetBoardFeatureFlag(0x10);
    for (i = 0; i < 8; i++) {
        func_80059768(i, 0);
        if (i < 6) {
            func_8005963C(i, 0x8000);
        }        
    }

    GwSystem.curBoardIndex = 0;
    GwSystem.unk_1E = 0; //?
    bzero(&GwQuest, sizeof(GwQuest));
}

void func_80059348(s16 arg0) {
    GwSystem.unk_1E = arg0;
}

void func_80059354(s16 flag, s16* byteIndex, s16* bitIndex) {
    if (flag < 0) {
        flag = GwSystem.unk_1E;
    }

    *byteIndex = flag / 8;
    *bitIndex = flag % 8;
}

void func_800593AC(s16 arg0) {
    s16 sp10;
    s16 sp12;

    func_80059354(arg0, &sp10, &sp12);
    GwCommon.mgUnlock[sp10] = GwCommon.mgUnlock[sp10] | (1 << sp12);
}

s32 func_80059400(s16 arg0) {
    s16 var0;
    s16 var1;

    func_80059354(arg0, &var0, &var1);
    return (GwCommon.mgUnlock[var0] & (1 << var1));
}

void func_80059448(s16 arg0) {
    s16 var0;
    s16 var1;

    func_80059354(arg0, &var0, &var1);
    GwCommon.mgBuy[var0] = (GwCommon.mgBuy[var0] | (1 << var1));
}

s16 func_8005949C(s16 arg0) {
    s16 var0;
    s16 var1;

    func_80059354(arg0, &var0, &var1);
    return GwCommon.mgBuy[var0] & (1 << var1);
}

void func_800594E4(s16 index, u16 value) {
    GwCommon.mgRecord[index] = value;
}

u16 func_800594FC(s16 index) {
    return GwCommon.mgRecord[index];
}

void func_80059514(u16 value) {
    GwSystem.curBoardIndex = value;
}

u16* func_80059520(s16 index) {
    if (index < 0) {
        index = GwSystem.curBoardIndex;
    }
    return &GwCommon.boardRecord[index][0];
}

u16 func_80059550(s16 index) {
    u16 *ptr;

    ptr = (u16 *)func_80059520(index);
    return *ptr & 0x3FF;
}

void func_80059578(s16 index) {
    u16 *ptr;

    ptr = (u16 *)func_80059520(index);
    if (index < 0) {
        index = GwSystem.curBoardIndex;
    }
    if (index < 8) {
        {
            u16 uVar;
            u16 uVarAnd;

            uVarAnd = *ptr & 0xFC00;
            uVar = *ptr & 0x3FF;

            if (++uVar > 999) {
                uVar = 999;
            }
            *ptr = uVar | uVarAnd;
        }
    }
}

s32 func_80059600(s16 index, u16 param_2) {
    u16 *ptr;
    u16 ret;
    u32 andr;

    ptr = (u16 *)func_80059520(index);
    ret = *ptr & 0xFC00;
    return ret & (andr = param_2); // ?
}

void func_8005963C(s16 index, u16 param_2) {
    u16 *ptr;

    ptr = (u16 *)func_80059520(index);
    *ptr |= param_2 & 0xFC00;
}

void func_80059678(s16 index, u16 param_2) {
    u16 *ptr;

    ptr = (u16 *)func_80059520(index);
    *ptr &= ~(param_2 & 0xFC00);
}

u16 func_800596B8(s16 index) {
    u16 *ptr;

    ptr = (u16 *)func_80059520(index);
    return ptr[1];
}

void func_800596DC(s16 index, s16 param_2) {
    u16 *ptr;

    ptr = (u16 *)func_80059520(index);
    if (index < 0) {
        index = GwSystem.curBoardIndex;
    }
    if (index < 8) {
        ptr[1] = param_2 + ptr[1];
        if (ptr[1] > 9999) {
            ptr[1] = 9999;
        }
    }
}

void func_80059768(s16 index, s16 param_2) {
    u16 *ptr;

    ptr = (u16 *)func_80059520(index);
    ptr[1] = param_2;
}

s32 _CheckFlag(s32 flag) {
    return GwCommon.flag[flag / 8] & (1 << flag % 8);
}

void SetBoardFeatureFlag(s32 flag) {
    GwCommon.flag[flag / 8] |= (1 << flag % 8);
}

void ClearBoardFeatureFlag(s32 flag) {
    GwCommon.flag[flag / 8] &= ~(1 << flag % 8);
}


void* HuMemHeapInit(void* ptr, u32 size) {
    HeapNode* heap = (HeapNode*)ptr;
    heap->size = size;
    heap->heap_constant = HEAP_CONSTANT;
    heap->used = 0;
    heap->prev = ptr;
    heap->next = ptr;
    return heap;
}

void* HuMemMemoryAlloc(HeapNode* heap, s32 size) {
    HeapNode* cur_heap;
    HeapNode* new_heap_temp;

    size = size + 0x1F;
    size = size & -16;

    cur_heap = heap;
    do {
        if (!cur_heap->used) {
            if (cur_heap->size >= size) {
                if ((u32)(cur_heap->size - size) > MIN_HEAP_NODE_SIZE) {
                    new_heap_temp = ((void *)cur_heap) + size;
                    new_heap_temp->size = cur_heap->size - size;
                    new_heap_temp->heap_constant = HEAP_CONSTANT;
                    new_heap_temp->used = FALSE;

                    cur_heap->next->prev = new_heap_temp;
                    new_heap_temp->next = cur_heap->next;
                    cur_heap->next = new_heap_temp;
                    new_heap_temp->prev = cur_heap;
                    cur_heap->size = size;
                }

                cur_heap->used = TRUE;
                return (void *)cur_heap + sizeof(HeapNode);
            }
        }

        cur_heap = cur_heap->next;
    }
    while (cur_heap != heap);

    return NULL;
}

void HuMemMemoryFree(void *ptr)
{
    HeapNode* given_heap;
    HeapNode* heap_other;

    if (ptr == NULL) {
        return;
    }

    given_heap = (HeapNode*)(ptr - sizeof(HeapNode));

    if (given_heap->heap_constant != HEAP_CONSTANT) {
        return;
    }

    heap_other = given_heap->prev;

    if (((u32)heap_other < (u32)given_heap) && !heap_other->used) {
        given_heap->next->prev = heap_other;
        given_heap->prev->next = given_heap->next;
        given_heap->prev->size += given_heap->size;
        given_heap = given_heap->prev;
    }

    heap_other = given_heap->next;

    if (((u32)given_heap < (u32)heap_other) && !heap_other->used) {
        heap_other->next->prev = given_heap;
        given_heap->size += given_heap->next->size;
        given_heap->next = given_heap->next->next;
    }

    given_heap->used = FALSE;
}

void* Realloc(HeapNode* heap, void* mem, u32 new_size)
{
    void *ret;
    HeapNode *given_heap;
    HeapNode *new_heap;
    s32 temp;

    given_heap = (HeapNode*)(mem - sizeof(HeapNode));
    temp = new_size + 0x1F;
    temp = temp & -16;

    if (given_heap->size >= temp) {
        if ((u32)(given_heap->size - temp) > MIN_HEAP_NODE_SIZE) {
            new_heap = (void *)given_heap + temp;
            new_heap->size = given_heap->size - temp;
            new_heap->heap_constant = HEAP_CONSTANT;
            new_heap->used = FALSE;
            given_heap->next->prev = new_heap;
            new_heap->next = given_heap->next;
            given_heap->next = new_heap;
            new_heap->prev = given_heap;
            given_heap->size = temp;
        }

        return (void *)given_heap + sizeof(HeapNode);
    } else {
        ret = HuMemMemoryAlloc(heap, new_size);
        if (ret != NULL) {
            bcopy(mem, ret, given_heap->size - sizeof(HeapNode));
            HuMemMemoryFree(mem);
        }

        return ret;
    }

    return NULL;
}

u32 GetAllocatedHeapSize(HeapNode* heap) {
    HeapNode* cur_heap;
    u32 total_size;

    cur_heap = heap;
    total_size = 0;
    do
    {
        if (cur_heap->used == TRUE)
        {
            total_size += cur_heap->size;
        }
        cur_heap = cur_heap->next;
    }
    while (cur_heap != heap);

    return total_size;
}

u32 GetUsedMemoryBlockCount(HeapNode* heap) {
    HeapNode* cur_heap;
    u32 count_free;

    cur_heap = heap;
    count_free = 0;
    do
    {
        count_free += (cur_heap->used ^ TRUE) == FALSE ? 1 : 0;
        cur_heap = cur_heap->next;
    }
    while (cur_heap != heap);

    return count_free;
}

s32 HuMemMemoryAllocSizeGet(s32 arg0) {
    return (arg0 + 0x1F) & ~0xF;
}

s32 func_80059B10(s32 arg0) {
    if (arg0 < 0) {
        if (arg0 + 3 == GwCommon.boardItem) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return _CheckFlag(arg0);
    }
}

s32 func_80059B48(s32 arg0) {
    if (arg0 < 0) {
        return 1;
    } else {
        return _CheckFlag(arg0);
    }
}

void func_80059B74(s16 index) {
    s32 i;
    s32 j;

    func_80059448(index);
    for (i = 0; i < 4; i++) {
        for (j = 0; j < D_800C5730[i].count; j++) {
            if (func_8005949C(D_800C5730[i].list[j] - 1) == 0) {
                return;
            }
        }
    }
    SetBoardFeatureFlag(0x26);
}

s16 func_80059C28(void) {
    s16 win = func_8006D010(0x40, 0xAA, 0xC0, 0x30, 0, 0);

    func_8006DA1C(win, 0x40, 0x40);
    func_8006E070(win, 0);
    func_800717C0(win);
    func_8006E154(win, 0xC8);
    func_8007155C(win, (s16)(1 << GwPlayer[0].port));
    return win;
}

s32 func_80059CB8(void) {
    return ContDStkTrg[GwPlayer[0].port] | (D_800F2CF0[GwPlayer[0].port] & 0xF00);
}

s32 func_80059CE8(void* str, s16 win) {
    func_8006EB40(win);
    func_8006E288(win, 7);
    LoadStringIntoWindow(win, str, -1, -1);
    while (func_8006FCC0(win) != 0) {
        HuPrcVSleep();
    }
    func_8007155C(win, (s16)(1 << GwPlayer[0].port));
    return func_8006FCF0(win, 0, 0) == 0;
}

f32 func_80059DAC(f32 angle) {
    while (angle >= 360.0f) {
        angle -= 360.0f;
    }
    while (angle < 0.0f) {
        angle += 360.0f;
    }
    return angle;
}

f32 func_80059E28(f32 a, f32 b) {
    f32 d = a - b;

    while (d >= 180.0f) {
        d -= 360.0f;
    }
    while (d < -180.0f) {
        d += 360.0f;
    }
    return d;
}

void func_80059EBC(void) {
    s32 pad[16]; // unused stack space in retail's frame
    Vec3f eye;
    Vec3f up;
    Vec3f* target;
    Vec3f* rot;
    f32 dy;
    f32 rx;
    s32 t;

    target = D_800ED610;
    rot = D_800ED72C;
    if (D_800F64F8 == 0) {
        CRot.x = func_80059DAC(func_80059E28(rot->x, CRot.x) / 6.0f + CRot.x);
        dy = func_80059E28(rot->y, CRot.y);
        if (func_8005FD5C() + D_800F64F8 == 0) {
            if ((D_800F384C >> 8) & 1 & (t = (dy > 0.0f))) {
                dy = -180.0f;
            }
            if ((D_800F384C >> 9) & 1 & (t = (dy < 0.0f))) {
                dy = 180.0f;
            }
            if (abs((s32)dy) > 90.0f) {
                dy = (dy < 0.0f) ? -90.0f : ((dy != 0.0f) ? 90.0f : 0.0f);
            }
        }
        CRot.y = func_80059DAC(CRot.y + dy / 6.0f);
        CRot.z = func_80059DAC(func_80059E28(rot->z, CRot.z) / 6.0f + CRot.z);
        Center.x += (target->x - Center.x) / 6.0f;
        Center.y += (target->y - Center.y) / 6.0f;
        Center.z += (target->z - Center.z) / 6.0f;
    }
    rx = CRot.x;
    dy = CRot.y;
    eye.x = Center.x + func_800AEAC0(dy) * func_800AEFD0(rx) * 1000.0f;
    eye.y = -func_800AEAC0(rx) * 1000.0f + Center.y;
    eye.z = func_800AEFD0(dy) * func_800AEFD0(rx) * 1000.0f + Center.z;
    up.x = func_800AEAC0(dy) * func_800AEAC0(rx);
    up.y = func_800AEFD0(rx);
    up.z = func_800AEFD0(dy) * func_800AEAC0(rx);
    func_8001D420(0, &Center, &eye, &up);
    func_8001D57C(0);
}

s32 func_8005A22C(s32 dataNum) {
    return (u16)func_80028784(DataRead(dataNum), 0x1D);
}

void func_8005A258(s16 model) {
    f32 t;

    while (1) {
        t = func_80025D18(model);
        if (func_80025D40(model) <= t) {
            break;
        }
        HuPrcVSleep();
    }
}

void func_8005A2B8(s16 win, s32 start) {
    TextWindow* w = func_8006DD60(win);
    s32 i;
    void* str;

    w->unk_04 = 0;
    w->unk_03 = 0;
    w->unk_09 = 1;
    w->unk_0A = 4;
    func_8006752C(w->unk_44, 0, 200);
    for (i = start; i < start + 8; i++) {
        if (func_80059B48(D_800C5750[i].shownFlag) != 0) {
            str = func_8005B7E8(D_800C5750[i].nameStr);
            sprintf(D_800D87D8[i], " %s", str);
            func_8005B838(str);
            if (func_80059B10(D_800C5750[i].ownedFlag) != 0 || D_800C5750[i].ownedFlag == -4) {
                D_800D87D8[i][0] = 8;
            } else {
                D_800D87D8[i][0] = 2;
            }
            if (func_80059B10(D_800C5750[i].ownedFlag) != 0) {
                func_8006DB3C(win, 0x85, 0x27 - start * 3, (i - start) * 16 + 0x40, 0);
            }
        } else {
            D_800D87D8[i][0] = 0;
        }
        func_8006DA5C(win, D_800D87D8[i], i - start);
    }
}

void func_8005A4C0(omObjData* obj) {
    TextWindow* w;
    s16 sprite;
    s32 i;

    if ((func_80059CB8() & 0x1000) && D_800ECC22 != 0 && func_80072718() == 0) {
        func_8005B648(0x5A, 0x12);
        func_8005FD7C();
        obj->func_ptr = func_8005AA88;
        D_800D8730 = 0;
        D_800D872C = 0;
        D_800D8722[0] = func_8006D010(0, 0, 0xA0, 0xF0, 0, 1);
        func_8006E0A4(D_800D8722[0], 1);
        D_800D8722[1] = func_8006D010(0xA0, 0, 0xA0, 0xF0, 0, 1);
        func_8006E0A4(D_800D8722[1], 1);
        D_800D8722[2] = func_8006D010(0x140, 0, 0x140, 0x50, 0, 1);
        func_8006E0A4(D_800D8722[2], 1);
        D_800D8722[3] = func_8006D010(0x140, 0x50, 0x140, 0xA0, 0, 1);
        func_8006E0A4(D_800D8722[3], 1);

        w = func_8006DD60(D_800D8722[0]);
        w->unk_28 = w->unk_18 - 4;
        func_8005A2B8(D_800D8722[0], 0);
        sprintf(D_800D88F8, "%5d", GwCommon.coinNum);
        func_8006DA5C(D_800D8722[0], D_800D88F8, 8);
        LoadStringIntoWindow(D_800D8722[0], "Item\n\n          \x11\n          \x12\n          \x13\n          \x14\n          \x15\n          \x16\n          \x17\n          \x18\n\n         \x08>\x19", 0x84, 0x18);
        sprite = func_8006DB3C(D_800D8722[0], 0xA0013, 0x50, 0x198, 0);
        func_80067384(w->unk_44, sprite, 0);
        func_80067354(w->unk_44, sprite, 0.5f, 0.5f);

        w = func_8006DD60(D_800D8722[1]);
        func_8005A2B8(D_800D8722[1], 8);
        if (_CheckFlag(3) != 0 && _CheckFlag(0x17) != 0 && _CheckFlag(0x18) == 0) {
            sprintf(D_800D88FE, "  0");
        } else {
            sprintf(D_800D88FE, "%3d", GwCommon.starNum);
        }
        func_8006DA5C(D_800D8722[1], D_800D88FE, 8);
        LoadStringIntoWindow(D_800D8722[1], "List\n\n     \x11\n     \x12\n     \x13\n     \x14\n     \x15\n     \x16\n     \x17\n     \x18\n\n               \x08>\x19", 4, 0x18);
        sprite = func_8006DB3C(D_800D8722[1], 0xA0014, 0x8E, 0x198, 0);
        func_80067384(w->unk_44, sprite, 0);
        func_80067354(w->unk_44, sprite, 0.5f, 0.5f);

        w = func_8006DD60(D_800D8722[2]);
        w->unk_04 = 0;
        w->unk_03 = 0;
        w->unk_09 = 1;
        w->unk_0A = 0x10;
        func_8006752C(w->unk_44, 0, 200);
        func_80067384(w->unk_44, func_8006DB3C(D_800D8722[2], 0x9006B, 0xC0, 0x41, 0), 0);
        func_80067384(w->unk_44, func_8006DB3C(D_800D8722[2], 0x9006C, 0x108, 0x41, 0), 0);
        LoadStringIntoWindow(D_800D8722[2], "Current Standings", 0x6E, 0x20);

        w = func_8006DD60(D_800D8722[3]);
        w->unk_04 = 0;
        w->unk_03 = 0;
        w->unk_09 = 1;
        w->unk_0A = 4;
        func_8006752C(w->unk_44, 0, 200);
        for (i = 0; i < 8; i++) {
            if (func_80059600(i, 0x8000) != 0 || i < 6) {
                func_80067384(w->unk_44, func_8006DB3C(D_800D8722[3], (i + 0x63) | 0x90000, 0x5E, i * 16 + 8, 0), 0);
                sprintf(D_800D8738[i], "%6dTimes    %4d", func_80059550(i), func_800596B8(i));
            } else {
                D_800D8738[i][0] = 0;
            }
            func_8006DA5C(D_800D8722[3], D_800D8738[i], i);
        }
        LoadStringIntoWindow(D_800D8722[3], (char*)D_800CB4C4, 0xAC, 3);
    }
}

void func_8005A9D8(s16 win) {
    TextWindow* w = &D_800ED4B0[win];
    s32 i;

    for (i = 12; i < 20; i++) {
        if (w->unk_46[i] != -1) {
            func_80067704(w->unk_46[i]);
        }
    }
}

void func_8005AA5C(omObjData* obj) {
    obj->work[0]--;
    if (obj->work[0] == 0) {
        obj->func_ptr = func_8005A4C0;
    }
}

void func_8005AA88(omObjData* obj) {
    TextWindow* w;
    s32 btn;
    s32 i;
    u16 sprite;

    btn = func_80059CB8();
    if ((btn & 0x100) && D_800D872C == 0) {
        D_800D8730 = 0x10;
        D_800D872C = 0x14;
    }
    if ((btn & 0x200) && D_800D872C == 0) {
        D_800D8730 = 0x10;
        D_800D872C = -0x14;
    }
    for (i = 0; i < 4; i++) {
        w = func_8006DD60(D_800D8722[i]);
        sprite = w->unk_44;
        w->unk_14 += (s16)D_800D872C;
        if (w->unk_14 > 0x140) {
            w->unk_14 -= 0x280;
        }
        if (w->unk_14 < -0x13F) {
            w->unk_14 += 0x280;
        }
        func_80066DC4(sprite, 0, w->unk_14, w->unk_16);
    }
    if (D_800D872C != 0 && --D_800D8730 == 0) {
        D_800D872C = 0;
    }
    if (btn & 0x1000) {
        func_8005B648(0x7F, 0x12);
        func_8005FECC();
        for (i = 0; i < 4; i++) {
            func_8005A9D8(D_800D8722[i]);
            func_80070D90(D_800D8722[i]);
        }
        obj->work[0] = 5;
        obj->func_ptr = func_8005AA5C;
    }
}

void func_8005AC50(void) {
    if (D_800C5810 != 0) {
        D_800C5814 += 15;
        if (D_800C5814 > 0x163) {
            D_800C5814 = 0x163;
            D_800C5810 = 0;
        }
    } else {
        D_800C5814 -= 15;
        if (D_800C5814 < 0x64) {
            D_800C5814 = 0x64;
            D_800C5810 = 1;
        }
    }
    if (D_800C5814 > 0xFF) {
        func_8006752C(D_800D8904, 0, 0xFF);
    } else {
        func_8006752C(D_800D8904, 0, (u16)D_800C5814);
    }
}

void func_8005AD18(void) {
    void* data;

    if (D_800C572F == 1) {
        D_800D8902 = func_8006D010(0x45, 0x94, 0xB6, 0x18, 0, 0);
        func_8006E0A4(D_800D8902, 1);
        data = DataRead(0x90070);
        D_800D8906 = func_800678A4(data);
        DataClose(data);
        D_800D8904 = func_80064EF4(1, 5);
        func_80067208(D_800D8904, 0, D_800D8906, 0);
        func_80067480(D_800D8904, 0, 0xFFFF);
        func_800674BC(D_800D8904, 0, 0x1000);
        func_80066DC4(D_800D8904, 0, 0xA0, 0xA0);
        func_80067384(D_800D8904, 0, 0);
        omAddObj(0, 0, 0, -1, func_8005AC50);
    }
}

void func_8005AE44(void) {
    if (D_800C572F == 1) {
        func_800674BC(D_800D8904, 0, 0x8000);
        func_80071598(D_800D8902);
    }
}

s32 func_8005AE88(void) {
    s32 port;
    s32 used;
    s32 empty;

    port = 0;
    used = 0;
    empty = 0;
    for (; port < 4; port++) {
        if (func_800141FC(port) == 1) {
            GwPlayer[used].port = port;
            used++;
        } else {
            GwPlayer[3 - empty].port = port;
            empty++;
        }
    }
    if (empty == 4) {
        GwPlayer[0].port = 0;
        GwPlayer[3].port = 3;
    }
    GwPlayer[0].flags = 0;
    return used;
}

s32 func_8005AF60(void) {
    omObjData* obj;

    omSysPauseEnableFlag = 1;
    obj = omAddObj(0, 0, 0, -1, func_8005A4C0);
    omSetStatBit(obj, 0xA0);
    obj->work[0] = 0;
    func_8005B5D8();
    return func_8005AE88();
}

u16 func_8005AFC8(void) {
    return CalcChecksumEeprom(0, (EEPROM_MAXBLOCKS * EEPROM_BLOCK_SIZE) - 0x10);
}

s32 func_8005AFEC(void) {
    u16 sum;

    sum = 0;
    if (D_800D8720 != 0) {
        ReadEeprom(EEP_ABS_EEP_SIZE, (u8*)&sum, 2);
    }
    return sum;
}

void func_8005B024(void) {
    u16 sp10;

    sp10 = func_8005AFC8();
    if (D_800D8720 != 0) {
        WriteEeprom(EEP_ABS_EEP_SIZE, &sp10, 2);
    }
}

void func_8005B060(void) {
    func_80059280();
    func_8001A498();
    GwCommon.coinNum = 0x12C;
    func_8005B280();
    func_8005B3B0();
    if (D_800D8720 != 0) {
        WriteEeprom(EEP_ABS_OFFSET_GWQUEST, &GwQuest, sizeof(GwQuest));
    }
    func_8005B024();
}

s32 func_8005B0C4(void) {
    char sp10[4]; //unk type and size
    s32 i;
    u16 temp_s1;
    s32 var_s1;

    for (i = 0; i < 4; i++) {
        if (func_800141FC(i) == 1) {
            break;
        }
    }
    if (i == 4) {
        D_800C572F = 1;
    }
    
    var_s1 = InitEeprom(sp10);
    
    if (var_s1 != 0) {
        D_800D8720 = 0;
    } else {
        D_800D8720 = 1;
    }
    if (D_800D8720 != 0) {
        var_s1 = ReadEeprom(offsetof(SaveFile, common), (void*)&GwCommon.unk0, sizeof(GwCommon));
        var_s1 = var_s1 | ReadEeprom(EEP_ABS_OFFSET_GWPLAYER, (void*)GwPlayer, sizeof(GwPlayer));
        var_s1 = var_s1 | ReadEeprom(EEP_ABS_OFFSET_GWSYSTEM, (void*)&GwSystem, sizeof(GwSystem));
        var_s1 = var_s1 | ReadEeprom(EEP_ABS_OFFSET_GWQUEST, (void*)&GwQuest, sizeof(GwQuest));
    }
    
    GwSystem.unk_1E = 0;
    
    if (var_s1 == 0) {
        temp_s1 = func_8005AFEC();
        if ((temp_s1) != (func_8005AFC8())) {
            var_s1 = 1;
        }
    }
    if (((GwCommon.unk0 != 0x12) | (var_s1 != 0)) != 0) {
        func_8005B060();
    }
    
    if (_CheckFlag(16) != 0) {
        func_8000B364(0);
    } else {
        func_8000B364(1);
    }
    return (GwCommon.unk0 == 0x12) & (var_s1 != 0);
}

void func_8005B244(void) {
    if (D_800D8720 != 0) {
        WriteEeprom(0, &GwCommon, 0x50); //TODO: only 0x50?
    }
    func_8005B024();
}

void func_8005B280(void) {
    if (_CheckFlag(0) != 0) {
        ClearBoardFeatureFlag(0x40);
        if (D_800D8720 != 0) {
            WriteEeprom(0, &GwCommon, sizeof(GwCommon));
        }
    } else if (D_800D8720 != 0) {
        WriteEeprom(0, &GwCommon, 0x50);
    }
    ClearBoardFeatureFlag(0);
    func_8005B024();
}

void func_8005B300(void) {
    func_8005CDE0();
    if (D_800D8720 != 0) {
        WriteEeprom(0, &GwCommon, 0x50);
        WriteEeprom(EEP_ABS_OFFSET_GWQUEST, &GwQuest, sizeof(GwQuest));
    }
    func_8005B024();
}

void func_8005B358(u8* buf) {
    if (D_800D8720 != 0) {
        ReadEeprom(EEP_ABS_OFFSET_GWQUEST, buf, sizeof(GwQuest));
    }
}

void func_8005B388(void) {
    func_8005B358((u8*)&GwQuest);
    func_8005CE04();
}

void func_8005B3B0(void) {
    if (D_800D8720 != 0) {
        WriteEeprom(0, &GwCommon, sizeof(GwCommon));
        WriteEeprom(0x94, &GwPlayer, sizeof(GwPlayer));
        WriteEeprom(0x154, &GwSystem, sizeof(GwSystem));
    }
    func_8005B024();
}

void func_8005B414(void) {
    if (D_800D8720 != 0) {
        ReadEeprom(0x50, (u8*)&GwCommon + 0x50, sizeof(GwCommon) - 0x50);
        ReadEeprom(EEP_ABS_OFFSET_GWPLAYER, (u8*)GwPlayer, sizeof(GwPlayer));
        ReadEeprom(EEP_ABS_OFFSET_GWSYSTEM, (u8*)&GwSystem, sizeof(GwSystem));
    }
}

s16 func_8005B470(s16 win) {
    s16 port;
    s32 mask;
    s16 ret;

    mask = 1;
    for (port = 0; port < 4; port++) {
        if (func_800141FC(port) != 0) {
            break;
        }
        mask <<= 1;
    }
    ret = (port != 4) ? port : 0;
    func_8007155C(win, (s16)mask);
    return ret;
}

void func_8005B510(void) {
    if (D_800ED0CE != 0) {
        D_800D8908 += D_800D890C;
        if (D_800D8908 >= 128.0f) {
            D_800D8908 = 127.0f;
        }
        if (D_800D8908 < 0.0f) {
            D_800D8908 = 0.0f;
        }
        D_800ED0CE--;
        func_80060214(D_800D8908);
    }
}

void func_8005B5D8(void) {
    omSetStatBit(omAddObj(1, 0, 0, -1, func_8005B510), 0xA0);
    D_800ED0CE = 0;
    D_800D8908 = func_8000C4A0();
    D_800D890C = 0.0f;
}

void func_8005B648(s8 vol, s16 time) {
    D_800ED0CE = time;
    D_800D8908 = func_8000C4A0();
    D_800D890C = (vol - D_800D8908) / (u16)time;
}

void func_8005B6D0(u8* rom) {
    s32* buf;
    s32 size;

    D_800D8910 = rom;
    buf = HuMemDirectMalloc(0x10);
    dmaRead(rom, buf, 0x10);
    D_800D8914 = *buf;
    HuMemDirectFree(buf);
    size = D_800D8914 * 4;
    D_800D8918 = HuMemDirectMalloc(size);
    dmaRead(rom + 4, D_800D8918, size);
}

void func_8005B75C(s32 index, StrData* out) {
    u16* buf = HuMemDirectMalloc(0x10);

    out->string = (s32)(D_800D8910 + D_800D8918[index]);
    dmaRead((u8*)out->string, buf, 0x10);
    out->string += 2;
    out->size = *buf;
    HuMemDirectFree(buf);
}

void* func_8005B7E8(s32 stringIndex) {
    StrData sp10;
    void* temp_v0;

    func_8005B75C(stringIndex, &sp10); //string index to pointer
    temp_v0 = HuMemDirectMalloc(sp10.size);
    
    if (temp_v0 != NULL) {
        dmaRead((void*)sp10.string, temp_v0, sp10.size);
    }
    
    return temp_v0;
}

void func_8005B838(void* arg0) {
    if (arg0 != NULL) {
        HuMemDirectFree(arg0);
    }
}

/* Standings text: rows 0x11-0x17 (row number, then 0x0A and fourteen 0x0E), then 0x18. Splat cut it
   at 0x800CB530; the string is one object and objmain's rodata starts after it. */
const char D_800CB4C4[] = "\x11\x0A\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x12\x0A\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x13\x0A\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x14\x0A\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x15\x0A\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x16\x0A\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x17\x0A\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x0E\x18";
