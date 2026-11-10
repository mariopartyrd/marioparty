#include "common.h"

typedef struct MBModel {
    /* 0x00 */ struct MBModel* next;
    /* 0x04 */ struct MBModel* prev;
    /* 0x08 */ u8 id;
    /* 0x0A */ u16 attr;
    /* 0x0C */ Vec3f pos;
    /* 0x18 */ Vec3f rot;
    /* 0x24 */ Vec3f scale;
    /* 0x30 */ f32 jumpY;
    /* 0x34 */ f32 jumpVel;
    /* 0x38 */ f32 jumpAccel;
    /* 0x3C */ omObjData* obj;
    /* 0x40 */ omObjData* shadow;
    /* 0x44 */ s16 baseMot;
    /* 0x46 */ s16 curMot;
} MBModel; // sizeof 0x48

#define MB(o) ((MBModel*)(o))

typedef struct MBModelWork {
    /* 0x00 */ MBModel* model;
    /* 0x04 */ f32 scale;
} MBModelWork;

typedef struct MBModelData {
    /* 0x00 */ s32 file;
    /* 0x04 */ s32 shadowFile;
    /* 0x08 */ f32 scale;
    /* 0x0C */ f32 shadowScale;
} MBModelData;
/* Board model file, shadow file and their scales, by model id. */
MBModelData D_800C4350[] = {
    { 0x1009F, 0x20, 1.0f, 0.9f },
    { 0x2009F, 0x20, 1.0f, 0.9f },
    { 0x6009F, 0x20, 1.0f, 1.2f },
    { 0x3009F, 0x20, 1.0f, 1.1f },
    { 0x4009F, 0x20, 1.0f, 1.1f },
    { 0x5009F, 0x20, 1.0f, 1.5f },
    { 0xA0068, 0x20, 1.0f, 2.0f },
    { 0x70000, 0x20, 0.7f, 0.7f },
    { 0xA0072, 0x20, 1.0f, 1.3f },
    { 0x1E0007, 0x20, 1.0f, 1.2f },
    { 0x69, 0xA00BA, 0.5f, 2.0f },
    { 0xA009E, 0x20, 1.0f, 1.0f },
    { 0x49, 0x20, 1.0f, 1.4f },
    { 0x4F, 0xA00BA, 1.0f, 2.0f },
    { 0xA00CA, 0x20, 1.0f, 0.9f },
    { 0xA00C9, 0x20, 1.0f, 0.9f },
    { 0x6A, 0x20, 1.0f, 0.9f },
    { 0xA00CF, 0x20, 1.0f, 0.9f },
    { 0xA00D4, 0x20, 1.0f, 0.0f },
    { 0xA00D7, 0x20, 1.0f, 0.9f },
    { 0xA00D5, 0x20, 1.0f, 0.0f },
    { 0xA00D6, 0x20, 1.0f, 0.0f },
    { 0xA0061, 0x20, 1.0f, 0.0f },
    { 0x1009E, 0x20, 1.0f, 0.9f },
    { 0x2009E, 0x20, 1.0f, 0.9f },
    { 0x6009E, 0x20, 1.0f, 1.2f },
    { 0x3009E, 0x20, 1.0f, 1.1f },
    { 0x4009E, 0x20, 1.0f, 1.1f },
    { 0x5009E, 0x20, 1.0f, 1.5f },
    { 0xA009F, 0x20, 1.0f, 0.0f },
    { 0xA00A0, 0x20, 1.0f, 0.0f },
    { 0xA00A1, 0x20, 1.0f, 0.0f },
    { 0xA00A2, 0x20, 1.0f, 0.0f },
    { 0xA00A3, 0x20, 1.0f, 0.0f },
    { 0xA00A4, 0x20, 1.0f, 0.0f },
    { 0xA00A6, 0x20, 1.0f, 0.0f },
    { 0xA0077, 0x20, 1.0f, 0.0f },
    { 0xA0089, 0x20, 1.0f, 0.0f },
    { 0xA0097, 0x20, 1.0f, 3.0f },
    { 0xA0098, 0x20, 1.0f, 1.0f },
    { 0xA009A, 0x20, 1.0f, 1.0f },
    { 0xA009B, 0x20, 1.0f, 0.0f },
    { 0xA009C, 0x20, 1.0f, 0.0f },
    { 0xA00AC, 0x20, 1.0f, 0.0f },
    { 0xA00AD, 0x20, 1.0f, 0.0f },
    { 0xA00AE, 0x20, 1.0f, 0.0f },
    { 0xA00BD, 0x20, 1.0f, 0.0f },
    { 0xA00BF, 0x20, 1.0f, 0.0f },
    { 0xA00C3, 0x20, 1.0f, 1.0f },
    { 0xA00C5, 0x20, 1.0f, 1.0f },
    { 0xA00C7, 0x20, 1.0f, 1.0f },
    { 0xA00CB, 0x20, 1.0f, 0.0f },
    { 0xA00D1, 0x20, 1.0f, 0.0f },
    { 0xA00DC, 0x20, 1.0f, 0.0f },
    { 0xA00DE, 0x20, 1.0f, 0.0f },
    { 0xA00DF, 0x20, 1.0f, 0.0f },
    { 0xA00C1, 0x20, 1.0f, 0.0f },
    { 0xA0075, 0x20, 1.0f, 1.3f },
    { 0xA0078, 0x20, 1.0f, 0.7f },
    { 0xA0070, 0x20, 1.0f, 2.0f },
    { 0xA00CE, 0x20, 1.0f, 0.0f },
    { 0x6B, 0x20, 0.15f, 0.0f },
    { 0xA0099, 0x20, 1.0f, 1.0f },
    { 0xA009D, 0x20, 1.0f, 0.0f },
    { 0xA008A, 0x20, 1.0f, 0.0f },
    { 0xA00E5, 0x20, 1.0f, 0.0f },
    { 0xA00CD, 0x20, 1.0f, 0.0f },
    { 0xA00BE, 0x20, 1.0f, 0.0f },
    { 0xA00C0, 0x20, 1.0f, 0.0f },
    { 0xA0062, 0x20, 1.0f, 0.0f },
    { 0xA0063, 0x20, 1.0f, 0.0f },
    { 0xA0064, 0x20, 1.0f, 0.0f },
    { 0xA0065, 0x20, 1.0f, 0.0f },
    { 0xA0066, 0x20, 1.0f, 0.0f },
    { 0xA0067, 0x20, 1.0f, 0.0f },
    { 0xA00C2, 0x20, 1.0f, 0.0f },
    { 0xA015F, 0x20, 1.0f, 0.0f },
    { 0xA0139, 0x20, 1.0f, 0.0f },
    { 0xA013B, 0x20, 1.0f, 0.0f },
    { 0xA015E, 0x20, 1.0f, 0.0f },
    { 0xA007B, 0x20, 1.0f, 0.0f },
    { 0xA007C, 0x20, 1.0f, 0.0f },
    { 0xA007D, 0x20, 1.0f, 0.0f },
    { 0xA007E, 0x20, 1.0f, 0.0f },
    { 0xA007F, 0x20, 1.0f, 0.0f },
    { 0xA0080, 0x20, 1.0f, 0.0f },
    { 0xA015D, 0x20, 1.0f, 0.0f },
    { 0xA0159, 0x20, 1.0f, 0.0f },
    { 0xA013E, 0x20, 1.0f, 0.0f },
    { 0x90027, 0x20, 1.0f, 0.0f },
    { 0x90028, 0x20, 1.0f, 0.0f },
    { 0x9002E, 0x20, 1.0f, 0.0f },
    { 0xA00AF, 0xA00B2, 1.0f, 1.0f },
    { 0x70000, 0x20, 1.0f, 0.0f },
    { 0xA0081, 0x20, 1.0f, 0.8f },
    { 0xA0082, 0x20, 1.0f, 0.8f },
    { 0xA0083, 0x20, 1.0f, 0.8f },
    { 0xA0084, 0x20, 1.0f, 0.8f },
    { 0xA0085, 0x20, 1.0f, 0.8f },
    { 0xA0086, 0x20, 1.0f, 0.8f },
    { 0xA0137, 0x20, 1.0f, 0.0f },
    { 0xA00BB, 0x20, 1.0f, 1.1f },
    { 0xA00BC, 0x20, 1.0f, 1.1f },
    { 0xA0150, 0x20, 1.0f, 0.0f },
    { 0xA00E0, 0x20, 1.0f, 0.0f },
    { 0xA00E1, 0x20, 1.0f, 0.0f },
    { 0xA0087, 0x20, 1.0f, 1.2f },
    { 0xA0138, 0x20, 1.0f, 0.0f },
    { 0xA0068, 0x20, 1.0f, 1.4f },
    { 0xA0088, 0x20, 1.0f, 1.2f },
    { 0xA00B3, 0x20, 1.0f, 1.0f },
    { 0xA00B5, 0x20, 1.0f, 1.0f },
    { 0xA00B4, 0x20, 1.0f, 1.0f },
    { 0xA00B0, 0x20, 1.0f, 0.0f },
    { 0xA00B9, 0x20, 1.0f, 1.0f },
    { 0xA00B7, 0x20, 1.0f, 1.0f },
    { 0xA00B8, 0x20, 1.0f, 1.0f },
    { 0xA0143, 0x20, 1.0f, 0.0f },
    { 0xA00DD, 0x20, 1.0f, 0.0f },
    { 0xA00CC, 0x20, 1.0f, 0.0f },
    { 0xA00E6, 0x20, 0.7f, 0.7f },
    { 0xA00EA, 0x20, 1.0f, 0.7f },
    { 0xA00EB, 0x20, 0.7f, 0.7f },
    { 0xA00E6, 0x20, 1.0f, 0.0f },
    { 0xA013F, 0x20, 1.0f, 0.0f },
    { 0xA0140, 0x20, 1.0f, 0.0f },
    { 0xA0141, 0x20, 1.0f, 0.0f },
    { 0xA0142, 0x20, 1.0f, 0.0f },
    { 0xA00AB, 0x20, 1.0f, 1.0f },
    { 0xA00AA, 0x20, 1.0f, 0.0f },
    { 0xA00A8, 0x20, 1.0f, 0.0f },
    { 0xA00F4, 0x20, 1.0f, 1.3f },
    { 0xA00F3, 0x20, 1.0f, 0.0f },
    { 0x90006, 0x20, 1.0f, 0.0f },
    { 0xA00F5, 0x20, 1.0f, 1.0f },
    { 0x6C, 0x20, 1.0f, 1.0f },
    { 0x6D, 0x20, 1.0f, 0.0f },
    { 0xA00FF, 0x20, 1.0f, 1.3f },
    { 0xA00F6, 0x20, 1.0f, 0.0f },
    { 0xA00FE, 0x20, 1.0f, 0.0f },
    { 0x5D, 0x20, 1.0f, 0.0f },
    { 0xA00F7, 0xA00F8, 1.0f, 3.0f }
};

extern MBModel* D_800D61C0;
extern u16 D_800D61C4;
extern s16 D_800D61C8[128];
extern u16 D_800F5278;
extern u8 D_800F64F8;

s16 func_80028784(void*, s16);
void func_8002888C(s16, s16);
f32 func_80025D18(s16);
f32 func_80025D40(s16);
void func_800343C8(s16);
void func_8003DE60(omObjData*);
void func_8003E040(omObjData*);
void MBModelAttrSetDispOn(Object*);
void MBModelAttrSetDispOff(Object*);

void func_8003D960(void) {
    s32 i;

    for (i = 0; i < 128; i++) {
        D_800D61C8[i] = 0;
    }
}

s16 func_8003D990(s16 arg0) {
    D_800D61C8[arg0]++;
    return arg0;
}

s16 func_8003D9B8(s32 arg0) {
    s16 idx = func_80028784(DataRead(arg0), 8);

    D_800D61C8[idx]++;
    return idx;
}

void func_8003DA04(s16 arg0) {
    if (D_800D61C8[arg0] != 0) {
        if (--D_800D61C8[arg0] == 0) {
            func_800343C8(arg0);
        }
    }
}

s16 func_8003DA58(s16 arg0) {
    if (D_800D61C8[arg0] != 0) {
        D_800D61C8[arg0]++;
        return arg0;
    }
    return -1;
}

void MBModelInit(void) {
    D_800D61C0 = NULL;
    D_800D61C4 = 0;
    D_800F5278 = 1;
    func_8003D960();
}

void MBModelClose(void) {
    while (D_800D61C0 != NULL) {
        MBModelKill(D_800D61C0);
    }
}

MBModel* func_8003DB1C(void) {
    MBModel* m = MallocTemp(sizeof(MBModel));

    if (m != NULL) {
        D_800D61C4++;
        m->next = D_800D61C0;
        m->prev = NULL;
        if (D_800D61C0 != NULL) {
            D_800D61C0->prev = m;
        }
        D_800D61C0 = m;
        m->attr = 8;
        func_800A0D00(&m->pos, 0.0f, 0.0f, 0.0f);
        func_800A0D00(&m->rot, 0.0f, 0.0f, 1.0f);
        func_800A0D00(&m->scale, 1.0f, 1.0f, 1.0f);
        m->jumpY = 0.0f;
        m->jumpVel = 0.0f;
        m->jumpAccel = 0.0f;
        m->baseMot = -1;
        m->curMot = -1;
    }
    return m;
}

Object* MBModelCreate(u8 id, void* arg1) {
    MBModel* m;
    u16 mtncnt;
    omObjData* obj;
    MBModelWork* work;
    s16 model;
    s16 i;

    mtncnt = 0;
    m = func_8003DB1C();
    if (m != NULL) {
        m->id = id;
        if (arg1 != NULL) {
            mtncnt = ((u16*)arg1)[1];
            arg1 = (s32*)arg1 + 1;
        }
        obj = m->obj = omAddObj(0x4000, 1, mtncnt, -1, func_8003DE60);
        model = LoadFormFile(D_800C4350[m->id].file, 0x6A9);
        omSetStatBit(obj, 0x80);
        *obj->model = model;
        omSetRot(obj, 0.0f, 0.0f, 0.0f);
        func_80025EB4(model, 2, 2);
        func_80025F10(model, 1);
        m->baseMot = func_8003D990(func_80025E48(model));
        work = MallocTemp(sizeof(MBModelWork));
        obj->unk_50 = work;
        work->model = m;
        work->scale = D_800C4350[m->id].scale;
        for (i = 0; i < (s16)mtncnt; i++) {
            obj->motion[i] = func_8003D9B8(*(s32*)arg1);
            arg1 = (s32*)arg1 + 1;
        }
        if (D_800C4350[m->id].shadowScale > 0.0f) {
            obj = m->shadow = omAddObj(0x4000, 1, 0, -1, func_8003E040);
            model = LoadFormFile(D_800C4350[m->id].shadowFile, 0x229);
            omSetStatBit(obj, 0x80);
            *obj->model = model;
            omSetRot(obj, 0.0f, 0.0f, 0.0f);
            func_80025F10(model, 1);
            work = MallocTemp(sizeof(MBModelWork));
            obj->unk_50 = work;
            work->model = m;
            work->scale = D_800C4350[m->id].shadowScale;
        } else {
            m->shadow = NULL;
        }
    }
    return (Object*)m;
}

void func_8003DE60(omObjData* obj) {
    Vec2f pos2d;
    MBModelWork* work = obj->unk_50;
    MBModel* m = work->model;

    if (D_800F64F8 == 0 || (m->attr & 0x10)) {
        if (m->jumpAccel != 0.0f) {
            m->jumpVel += m->jumpAccel;
            if ((m->jumpY += m->jumpVel) < 0.0f) {
                m->jumpY = 0.0f;
                m->jumpVel = 0.0f;
                m->jumpAccel = 0.0f;
            }
        }
    }
    if (!(D_800F5278 & 1)) {
        goto off;
    }
    // retail reloads attr for each test; only a volatile read reproduces it
    if (!(((volatile MBModel*)m)->attr & 8)) {
        goto off;
    }
    if (!(((volatile MBModel*)m)->attr & 2)) {
        goto on;
    }
    func_8004B730(&m->pos, &pos2d);
    if (pos2d.x > 370.0f || pos2d.x < -50.0f || pos2d.y > 290.0f || pos2d.y < -20.0f) {
    off:
        MBModelAttrSetDispOff((Object*)m);
        return;
    }
on:
    MBModelAttrSetDispOn((Object*)m);
    if (!(m->attr & 4)) {
        obj->rot.y = func_8003D2B0(&m->rot);
    }
    obj->trans.x = m->pos.x;
    obj->trans.y = m->pos.y + m->jumpY;
    obj->trans.z = m->pos.z;
    obj->scale.x = m->scale.x * work->scale;
    obj->scale.y = m->scale.y * work->scale;
    obj->scale.z = m->scale.z * work->scale;
}

void func_8003E040(omObjData* obj) {
    MBModelWork* work = obj->unk_50;
    MBModel* m = work->model;
    f32 scale = 1.0f;

    obj->rot.y = func_8003D2B0(&m->rot);
    if (m->attr & 1) {
        scale = 0.0f;
    } else if (m->jumpY != 0.0f) {
        scale = 1.0f - m->jumpY / 700.0f;
        if (scale <= 0.0f) {
            scale = 0.0f;
        }
        if (scale >= 1.0f) {
            scale = 1.0f;
        }
    }
    obj->scale.x = scale * m->scale.x * work->scale;
    obj->scale.y = 1.0f;
    obj->scale.z = scale * m->scale.z * work->scale;
    obj->trans.x = m->pos.x;
    obj->trans.y = m->pos.y;
    obj->trans.z = m->pos.z;
}

void func_8003E174(Object* ptr) {
    MBModel* m = (MBModel*)ptr;

    func_80025B34(*m->obj->model);
    if (m->shadow != NULL) {
        func_80025B34(*m->shadow->model);
    }
}

void MBModelIDSet(Object* arg0, u8 id) {
    MBModel* m = (MBModel*)arg0;
    s16 model;

    m->id = id;
    func_8002888C(*m->obj->model, -1);
    func_8002456C(*m->obj->model);
    if (m->baseMot != -1) {
        func_8003DA04(m->baseMot);
    }
    model = LoadFormFile(D_800C4350[m->id].file, 0x6A9);
    *m->obj->model = model;
    func_80025EB4(model, 2, 2);
    func_80025F10(model, 1);
    ((MBModelWork*)m->obj->unk_50)->scale = D_800C4350[m->id].scale;
    m->baseMot = func_8003D990(func_80025E48(model));
    if (m->shadow != NULL) {
        func_8002456C(*m->shadow->model);
        model = LoadFormFile(D_800C4350[m->id].shadowFile, 0x229);
        *m->shadow->model = model;
        func_80025F10(model, 1);
        ((MBModelWork*)m->shadow->unk_50)->scale = D_800C4350[m->id].shadowScale;
    }
}

// register allocation: retail stores a copy of the model index (masked 18 incl. split-label relocs)
#ifdef NON_MATCHING
Object* MBModelParamCreate(Object* arg0) {
    MBModel* m;
    omObjData* obj;
    MBModelWork* work;
    s16 model;
    s16 i;

    m = func_8003DB1C();
    if (m != NULL) {
        m->id = MB(arg0)->id;
        obj = m->obj = omAddObj(0x4000, 1, MB(arg0)->obj->mtncnt, -1, func_8003DE60);
        model = func_80023FC8(*MB(arg0)->obj->model);
        omSetStatBit(obj, 0x80);
        *obj->model = model;
        omSetRot(obj, 0.0f, 0.0f, 0.0f);
        func_80025EB4(model, 2, 2);
        func_80025F10(model, 1);
        m->baseMot = func_8003DA58(func_80025E48(model));
        work = MallocTemp(sizeof(MBModelWork));
        obj->unk_50 = work;
        work->model = m;
        work->scale = D_800C4350[m->id].scale;
        for (i = 0; i < MB(arg0)->obj->mtncnt; i++) {
            obj->motion[i] = func_8003DA58(MB(arg0)->obj->motion[i]);
        }
        if (D_800C4350[m->id].shadowScale > 0.0f) {
            obj = m->shadow = omAddObj(0x4000, 1, 0, -1, func_8003E040);
            model = func_80023FC8(*MB(arg0)->shadow->model);
            omSetStatBit(obj, 0x80);
            *obj->model = model;
            omSetRot(obj, 0.0f, 0.0f, 0.0f);
            func_80025F10(model, 1);
            work = MallocTemp(sizeof(MBModelWork));
            obj->unk_50 = work;
            work->model = m;
            work->scale = D_800C4350[m->id].shadowScale;
        } else {
            m->shadow = NULL;
        }
    }
    return (Object*)m;
}
#else
INCLUDE_ASM("asm/nonmatchings/3E560", MBModelParamCreate);
#endif

void MBModelAttrSetDispOn(Object* arg0) {
    func_800258EC(*arg0->unk_3C->unk_40, 4, 0);
    if (arg0->unk_40 != NULL) {
        func_800258EC(*arg0->unk_40->unk_40, 4, 0);
    }
}

void MBModelDispOn(Object* arg0) {
    MBModelAttrSetDispOn(arg0);
    arg0->unk_0A |= 8;
}

void MBModelAttrSetDispOff(Object* arg0) {
    func_800258EC(*arg0->unk_3C->unk_40, 4, 4);
    if (arg0->unk_40 != NULL) {
        func_800258EC(*arg0->unk_40->unk_40, 4, 4);
    }
}

void MBModelDispOff(Object* arg0) {
    MBModelAttrSetDispOff(arg0);
    arg0->unk_0A &= ~8;
}

void MBModelKill(void* arg0) {
    MBModel* m = arg0;
    s32 i;

    if (m->next != NULL) {
        m->next->prev = m->prev;
    }
    if (m->prev != NULL) {
        m->prev->next = m->next;
    } else {
        D_800D61C0 = m->next;
    }
    func_8002888C(*m->obj->model, -1);
    func_8002456C(*m->obj->model);
    if (m->shadow != NULL) {
        func_8002456C(*m->shadow->model);
    }
    for (i = 0; i < m->obj->mtncnt; i++) {
        func_8003DA04(m->obj->motion[i]);
    }
    if (m->baseMot != -1) {
        func_8003DA04(m->baseMot);
    }
    FreeTemp(m->obj->unk_50);
    m->obj->unk_50 = NULL;
    omDelObj(m->obj);
    if (m->shadow != NULL) {
        FreeTemp(m->shadow->unk_50);
        m->shadow->unk_50 = NULL;
        omDelObj(m->shadow);
    }
    FreeTemp(m);
    D_800D61C4--;
}

s32 MBModelCheck(void* arg0) {
    MBModel* m;

    for (m = D_800D61C0; m != NULL; m = m->next) {
        if (m == arg0) {
            return 1;
        }
    }
    return 0;
}

void MBMotionSet(Object* arg0, s16 arg1, u16 arg2) {
    u16 mot;

    if (arg1 == -1) {
        mot = MB(arg0)->baseMot;
        MB(arg0)->curMot = arg1;
    } else {
        mot = MB(arg0)->obj->motion[arg1];
        MB(arg0)->curMot = arg1;
    }
    func_8002888C(*MB(arg0)->obj->model, mot);
    func_80025EB4(*MB(arg0)->obj->model, -1, (s16)arg2);
}

void MBMotionShiftSet(Object* ptr, s16 a, s16 b, s16 c, u16 d) {
    MBModel* m = (MBModel*)ptr;
    u16 mot;

    if (a == -1) {
        mot = m->baseMot;
        m->curMot = a;
    } else {
        mot = m->obj->motion[a];
        m->curMot = a;
    }
    func_80025C20(*m->obj->model, mot, b, c, d);
}

u16 MBMotionCheck(Object* arg0) {
    MBModel* m = (MBModel*)arg0;
    s32 ret = 0;
    s16 model = *m->obj->model;
    f32 cur = func_80025D18(model);

    if (cur == func_80025D40(model)) {
        ret = 1;
    }
    return ret;
}
