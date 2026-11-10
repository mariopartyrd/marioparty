#include "common.h"

typedef struct ModelEffectWork {
    /* 0x00 */ Object* model;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ Vec3f vel;
    /* 0x1C */ Vec3f scale;
    /* 0x28 */ f32 duration;
} ModelEffectWork; /* size = 0x2C */

typedef struct ModelEmitterWork {
    /* 0x00 */ Process* process;
    /* 0x04 */ Object* model;
    /* 0x08 */ Object* parent;
    /* 0x0C */ Vec3f offset;
    /* 0x18 */ s16 type;
    /* 0x1A */ u16 flags;
} ModelEmitterWork; /* size = 0x1C */

typedef struct SpriteAnimWork {
    /* 0x00 */ u16 flags;
    /* 0x02 */ s16 frame;
    /* 0x04 */ s16 count;
    /* 0x06 */ u16 attr;
    /* 0x08 */ s16 x;
    /* 0x0A */ s16 y;
    /* 0x0C */ f32 scale;
    /* 0x10 */ s32 file;
    /* 0x14 */ Process* process;
    /* 0x18 */ unk_Struct02* sprite;
} SpriteAnimWork; /* size = 0x1C */

typedef struct SpriteAnimEntry {
    /* 0x00 */ s32 file;
    /* 0x04 */ u16 count;
} SpriteAnimEntry;
SpriteAnimEntry D_800C4C70[] = { { 0x100000, 0x17 }, { 0x100034, 0x20 }, { 0x100082, 0x3A }, { 0x1001E5, 0x26 }, { 0x1000F3, 0x39 }, { 0x100169, 0x3F } };
SpriteAnimEntry D_800C4CA0[] = { { 0x100017, 0x1D }, { 0x100054, 0x2E }, { 0x1000BC, 0x37 }, { 0x10020B, 0x37 }, { 0x10012C, 0x3D }, { 0x1001A8, 0x3D } };

extern s16 D_800D63F0;
s16 func_80025F38(s16);
void func_8004246C(void);


void func_80042240(void) {
    ModelEffectWork* work = HuPrcCurrentGet()->user_data;
    Object* model = work->model;
    f32 t;
    f32 s;

    MBModelDispOn(model);
    func_800A0D50(&model->coords, &work->pos);
    t = 0.0f;
    while (D_800D63F0 != 0) {
        s = func_800AEFD0(t);
        func_800A0D00(&model->xScale, s * work->scale.x, s * work->scale.y, s * work->scale.z);
        t += 90.0f / work->duration;
        if (t >= 90.0f) {
            break;
        }
        HuPrcVSleep();
        model->coords.x += work->vel.x * work->scale.x;
        model->coords.y += work->vel.y * work->scale.y;
        model->coords.z += work->vel.z * work->scale.z;
    }
    MBModelKill(model);
    EndProcess(NULL);
}
Process* func_80042378(Object* model, Vec3f* pos, Vec3f* vel, Vec3f* scale, f32 duration) {
    Process* process = omAddPrcObj(func_80042240, 0x4700, 0, 0x40);
    ModelEffectWork* work = HuMemMemoryAlloc(process->heap, sizeof(ModelEffectWork));

    process->user_data = work;
    work->model = MBModelParamCreate(model);
    func_80025F10(work->model->unk_3C->unk_40[0], func_80025F38(model->unk_3C->unk_40[0]));
    func_800A0D50(&work->pos, pos);
    func_800A0D50(&work->vel, vel);
    func_800A0D50(&work->scale, scale);
    work->duration = duration;
    return process;
}
// register allocation: hoisted constant/process swap s2/s3 and float temps (masked 13)
#ifdef NON_MATCHING
void func_8004246C(void) {
    Vec3f scale;
    Vec3f pos;
    Vec3f vel;
    ModelEmitterWork* work = HuPrcCurrentGet()->user_data;
    Process* process = HuPrcCurrentGet();
    Vec3f* velp;
    f32 duration;

    while (TRUE) {
        velp = &vel;
        switch (work->type) {
        case 0:
        case 1:
            HuPrcSleep(0);
            break;
        case 2:
            HuPrcSleep(1);
            break;
        }
        if (work->flags & 1) {
            break;
        }
        scale.x = work->parent->xScale;
        scale.y = work->parent->yScale;
        scale.z = work->parent->zScale;
        pos.x = work->offset.x * scale.x + work->parent->coords.x;
        pos.y = work->offset.y * scale.y + work->parent->coords.y + work->parent->unk_30;
        pos.z = work->offset.z * scale.z + work->parent->coords.z;
        pos.x = ((u8)(rand8() % 200) - 100) * 0.5f * scale.x + pos.x;
        pos.y = ((u8)(rand8() % 200) - 100) * 0.5f * scale.y + pos.y;
        pos.z = ((u8)(rand8() % 200) - 100) * 0.5f * scale.z + pos.z;
        switch (work->type) {
        case 1:
        case 2:
            func_800A0D00(velp, 0.0f, -8.0f, 0.0f);
            duration = 8.0f;
            break;
        case 0:
            func_800A0D00(velp, 0.0f, -5.0f, 0.0f);
            duration = 16.0f;
            break;
        default:
            continue;
        }
        HuPrcChildLink(process, func_80042378(work->model, &pos, velp, &scale, duration));
    }
    HuPrcChildWatch();
    MBModelKill(work->model);
    FreeTemp(work);
    EndProcess(NULL);
}
#else
INCLUDE_ASM("asm/nonmatchings/42E40", func_8004246C);
#endif

void* func_80042728(Object* ptr, s16 num) {
    ModelEmitterWork* work;
    Process* process;
    Object* model;

    D_800D63F0 = 1;
    work = MallocTemp(sizeof(ModelEmitterWork));
    if (work != NULL) {
        work->process = process = omAddPrcObj(func_8004246C, 0x4700, 0, 0);
        process->user_data = work;
        work->model = model = MBModelCreate(0x6B, NULL);
        MBModelDispOff(model);
        work->parent = ptr;
        work->type = num;
        func_800A0D00(&work->offset, 0.0f, -30.0f, 0.0f);
        work->flags = 0;
    }
    return work;
}

void func_800427D4(void* work) {
    ((ModelEmitterWork*)work)->flags |= 1;
}
void func_800427E4(void) {
    D_800D63F0 = 0;
}
void func_800427F0(SpriteAnimWork* work) {
    unk_Struct02* sprite = work->sprite;

    func_80067384(sprite->unk_0A, 0, work->attr);
    func_80066DC4(sprite->unk_0A, 0, work->x, work->y);
    func_80067354(sprite->unk_0A, 0, work->scale, work->scale);
}
void func_80042854(SpriteAnimWork* work) {
    unk_Struct02* sprite;
    void* data;

    if (work->sprite != NULL) {
        func_80053454(work->sprite);
    }
    sprite = func_800533F8(1, 0);
    work->sprite = sprite;
    data = DataRead(work->frame + work->file);
    sprite->unk_0C[0] = func_800678A4(data);
    func_80067208(sprite->unk_0A, 0, sprite->unk_0C[0], 0);
    func_800674BC(sprite->unk_0A, 0, 0x1800);
    DataClose(data);
}
void func_800428F8(void) {
    SpriteAnimWork* work = HuPrcCurrentGet()->user_data;

    work->flags |= 1;
    while (TRUE) {
        func_800427F0(work);
        HuPrcVSleep();
        if (work->flags & 2) {
            continue;
        }
        if (work->flags & 4) {
            if (--work->frame < 0) {
                work->frame = 0;
                work->flags &= ~1;
                continue;
            }
        } else {
            if (++work->frame >= work->count) {
                work->frame = work->count - 1;
                work->flags &= ~1;
                continue;
            }
        }
        work->flags |= 1;
        func_80042854(work);
    }
}
void* func_800429CC(s16 index, s16 mode) {
    SpriteAnimWork* work = MallocTemp(sizeof(SpriteAnimWork));
    Process* process;

    if (work != NULL) {
        if (mode & 0x80) {
            work->flags = 4;
        } else {
            work->flags = 0;
        }
        mode &= ~0x80;
        work->frame = 0;
        work->attr = 0x8000;
        work->x = 160;
        work->y = 120;
        work->scale = 1.0f;
        work->sprite = NULL;
        if (mode == 0) {
            work->file = D_800C4C70[index].file;
            work->count = D_800C4C70[index].count;
        } else {
            work->file = D_800C4CA0[index].file;
            work->count = D_800C4CA0[index].count;
        }
        if (work->flags & 4) {
            work->frame = work->count - 1;
        }
        func_80042854(work);
        process = omAddPrcObj(func_800428F8, 0x1001, 0, 0);
        work->process = process;
        process->user_data = work;
    }
    return work;
}
void func_80042B10(SpriteAnimWork* work) {
    if (work->sprite != NULL) {
        func_80053454(work->sprite);
    }
    EndProcess(work->process);
    FreeTemp(work);
}