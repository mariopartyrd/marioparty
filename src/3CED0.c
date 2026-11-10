#include "common.h"
#include "spaces.h"
s32 D_800C42C0[] = { 0xA010C, 0xA010D, 0xA010E, 0xA010F, 0xA0110, 0xA0111, 0xA0109, 0xA0105, 0xA0108, 0xA0107, 0xA0106 };
s16 D_800C42EC[][4] = { { 0, 2, 0, 1 }, { 0, 2, -1, 0 }, { -2, 0, 0, 1 }, { -2, 0, -1, 0 } };
s16 D_800C430C[4] = { 0x42, 0xFC, 0x42, 0xFC };
s16 D_800C4314[4] = { 0x1E, 0x1E, 0xD2, 0xD2 };
s32 D_800C431C[] = { 0xA010C, 0xA010D, 0xA010E, 0xA010F, 0xA0110, 0xA0111 };
s32 D_800C4334[] = { 0x6E, 0x6F, 0x70, 0x71, 0x72, 0x73 };

typedef struct {
    /* 0x00 */ s8 type;
    /* 0x04 */ Object* obj;
    /* 0x08 */ Process* proc;
    /* 0x0C */ s16 dx;
    /* 0x0E */ s16 dy;
} MapMarker;

typedef struct {
    /* 0x00 */ s16 sprite;
    /* 0x02 */ s16 idx;
} MapMarkerBlink;

extern s32 D_800D6050;
extern s16 D_800D6054;
extern MapMarker D_800D6058[20];
extern s16 D_800D6198[4];
extern s16 D_800D61A0[4];
extern unk_Struct02* D_800D61A8[4];
extern s16 D_800D61B8;
extern s8 D_800F384E;
extern u16 D_800F5278;
extern s32 D_800F6598;
void func_800406E4(s32);
void func_80040724(s32);
void func_800559BC(void);
void func_800559F8(void);
void func_8004B7F8(s32);


void func_8003C2D0(s32 arg0) {
    s32 i;

    D_800D6050 = arg0;
    for (i = 0; i < 20; i++) {
        D_800D6058[i].type = -1;
    }
    D_800D6054 = 0;
}
void func_8003C30C(void) {
}

void func_8003C314(s8 a, void* ptr, s32 c, s32 d) {
    MapMarker* m = &D_800D6058[D_800D6054++];

    m->type = a;
    m->obj = ptr;
    m->dx = c;
    m->dy = d;
}
void func_8003C350(void) {
    s32 i;

    for (i = 0; i < 20; i++) {
        MapMarker* m = &D_800D6058[i];
        if (m->type >= 0) {
            if (m->proc != NULL) {
                EndProcess(m->proc);
            }
            m->proc = NULL;
        }
    }
}
void func_8003C3C4(void) {
    f32 v;
    f32 t1;
    f32 t2;
    MapMarkerBlink* d;
    s32 c;

    d = HuPrcCurrentGet()->user_data;
    t1 = 0.0f;
    t2 = 0.0f;
    while (TRUE) {
        v = func_800AEAC0(t2);
        v = (v < 0.0f) ? -v : v;
        c = v * 255.0f;
        t2 += 6.0f;
        if (t2 > 360.0f) {
            t2 -= 360.0f;
        }
        func_80067558(d->sprite, d->idx, 0xFF, c, 0, 0xC0);
        v = func_800AEAC0(t1);
        v = (v < 0.0f) ? 0.0f : 0.2f;
        t1 += 15.0f;
        if (t1 > 360.0f) {
            t1 -= 360.0f;
        }
        func_80067354(d->sprite, d->idx, v + 1.0f, v + 1.0f);
        HuPrcVSleep();
    }
}

Process* func_8003C528(s16 sprite, s16 idx) {
    Process* p = omAddPrcObj(func_8003C3C4, 0x1005, 0, 0x40);
    MapMarkerBlink* d = HuMemMemoryAlloc(p->heap, sizeof(MapMarkerBlink));

    p->user_data = d;
    d->sprite = sprite;
    d->idx = idx;
    return p;
}
void func_8003C594(unk_Struct02* arg0, s16 i) {
    Vec3f v;
    f32 angle;

    func_80066DC4(arg0->unk_0A, 0, D_800C430C[i], D_800C4314[i]);
    func_80066DC4(arg0->unk_0A, 1, D_800C430C[i], D_800C4314[i]);
    v.x = D_800D6198[i] - D_800C430C[i];
    v.y = 0.0f;
    v.z = D_800D61A0[i] - D_800C4314[i];
    angle = func_8003D2B0(&v);
    func_80067354(arg0->unk_0A, 0, 0.25f, func_800B1750(v.x * v.x + v.z * v.z) / 32.0f);
    func_800673B0(arg0->unk_0A, 0, angle);
}
void func_8003C6C4(void) {
    unk_Struct02* s;
    s32 i;
    void* data;
    void* data2;

    for (i = 0; i < 4; i++) {
        s = func_800533F8(2, 0);
        data = DataRead(0xA010B);
        s->unk_0C[0] = func_800678A4(data);
        func_80067208(s->unk_0A, 0, s->unk_0C[0], 0);
        func_800674BC(s->unk_0A, 0, 0x01001808);
        func_80067384(s->unk_0A, 0, 2);
        func_80067558(s->unk_0A, 0, 0, 0, 0xFF, 0x80);
        DataClose(data);
        data2 = DataRead(0xA0020);
        s->unk_0C[1] = func_800678A4(data2);
        func_80067208(s->unk_0A, 1, s->unk_0C[1], 0);
        func_800674BC(s->unk_0A, 1, 0x01001808);
        func_80067384(s->unk_0A, 1, 2);
        func_80067558(s->unk_0A, 1, 0, 0, 0xFF, 0x80);
        DataClose(data2);
        func_8003C594(s, i);
        D_800D61A8[i] = s;
    }
}
void func_8003C858(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_80053454(D_800D61A8[i]);
    }
}
void func_8003C8A8(void) {
    unk_Struct02* s;
    s16 cur;
    s32 i;
    s16 c;
    f32 t;

    cur = -1;
    t = 90.0f;
    while (TRUE) {
        // fake branch: fixes register allocation (MP3 MBMapFullLineFlash needs one too)
        if (cur) {
            HuPrcVSleep();
        } else {
            HuPrcVSleep();
        }
        if (cur != D_800D61B8) {
            cur = D_800D61B8;
            for (i = 0; i < 4; i++) {
                s = D_800D61A8[i];
                if (i == cur) {
                    func_80067384(s->unk_0A, 0, 2);
                    func_80067384(s->unk_0A, 1, 2);
                } else {
                    func_80067558(s->unk_0A, 0, 0, 0, 0xFF, 0xA0);
                    func_80067558(s->unk_0A, 1, 0, 0, 0xFF, 0xFF);
                    func_80067384(s->unk_0A, 0, 3);
                    func_80067384(s->unk_0A, 1, 3);
                }
                func_80067480(s->unk_0A, 0, 0x8000);
                func_80067480(s->unk_0A, 1, 0x8000);
            }
        }
        s = D_800D61A8[cur];
        c = func_800AEAC0(t) * 255.0f;
        c = (c < 0) ? -c : c;
        t += 6.0f;
        if (t > 360.0f) {
            t -= 360.0f;
        }
        func_80067558(s->unk_0A, 0, 0xFF, c, 0, 0xA0);
        func_80067558(s->unk_0A, 1, 0xFF, c, 0, 0xFF);
    }
}

void func_8003CAB4(void) {
    Vec2f cam;
    Vec2f pos;
    s32 port;
    s32 bg;
    s16 sel;
    Process* proc;
    s32 i;
    s32 j;
    GW_PLAYER* player;
    MapMarker* m;
    void* data;
    unk_Struct02* markers;
    unk_Struct02* icons;
    s16 x;
    s16 y;
    s32 label1;
    s32 label2;
    s16 dir;
    u16 pad;

    port = (s32)(HuPrcCurrentGet()->user_data);
    bg = D_800F6598;
    sel = 0;
    for (i = 0; i < 4; i++) {
        if (PlayerIsCPU(i) != 0) {
            continue;
        }
        if (GwPlayer[i].port == port) {
            sel = i;
            break;
        }
    }
    D_800D61B8 = sel;
    func_8004B6D8(&cam);
    func_800726AC(6, 8);
    HuPrcSleep(8);
    func_800559BC();
    func_800406E4(port);
    HuPrcVSleep();
    D_800F384E = 1;
    D_800F5278 &= ~1;
    func_800405DC(GwSystem.curPlayerIndex);
    func_800406E4(GwSystem.curPlayerIndex);
    ChangeSpaceTextures(1);
    func_8004A140();
    LoadBackgroundIndex(D_800D6050);
    func_8004B7F8(0x96);
    markers = func_800533F8(20, 0);
    for (i = 0; i < 4; i++) {
        player = GetPlayerStruct(i);
        func_8004B730(&BoardSpaceGet(GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain, player->cur_space))->coords, &pos);
        D_800D6198[i] = pos.x;
        D_800D61A0[i] = pos.y;
    }
    for (i = 0, j = 0; j < 20; i++, j++) {
        m = &D_800D6058[j];
        if (m->type >= 0) {
            data = DataRead(D_800C42C0[m->type]);
            markers->unk_0C[i] = func_800678A4(data);
            func_80067208(markers->unk_0A, i, markers->unk_0C[i], 0);
            func_800674BC(markers->unk_0A, i, 0x01001000);
            func_8004B730(&m->obj->coords, &pos);
            x = (s32)pos.x + m->dx;
            y = (s32)pos.y + m->dy;
            func_80066DC4(markers->unk_0A, i, x, y);
            func_80067384(markers->unk_0A, i, ~y);
            DataClose(data);
            if (m->type == 6 || m->type == 10) {
                i++;
                data = DataRead(0xA0124);
                markers->unk_0C[i] = func_800678A4(data);
                func_80067208(markers->unk_0A, i, markers->unk_0C[i], 0);
                func_800674BC(markers->unk_0A, i, 0x01001808);
                func_80066DC4(markers->unk_0A, i, x, y - 1);
                func_80067384(markers->unk_0A, i, 0xFFFF);
                DataClose(data);
                m->proc = func_8003C528(markers->unk_0A, i);
            }
        }
    }
    func_8003C6C4();
    proc = omAddPrcObj(func_8003C8A8, 0x1005, 0, 0);
    icons = func_800533F8(8, 0);
    for (i = 0; i < 4; i++) {
        player = GetPlayerStruct(i);
        data = DataRead(D_800C431C[player->character]);
        icons->unk_0C[i] = func_800678A4(data);
        func_80067208(icons->unk_0A, i, icons->unk_0C[i], 0);
        func_80067384(icons->unk_0A, i, 1);
        func_800674BC(icons->unk_0A, i, 0x01001000);
        func_80066DC4(icons->unk_0A, i, D_800C430C[i] - 30, D_800C4314[i]);
        DataClose(data);
        data = DataRead(D_800C4334[player->character]);
        icons->unk_0C[i + 4] = func_800678A4(data);
        func_80067208(icons->unk_0A, i + 4, icons->unk_0C[i + 4], 0);
        func_80067384(icons->unk_0A, i + 4, 1);
        func_800674BC(icons->unk_0A, i + 4, 0x01001000);
        func_80066DC4(icons->unk_0A, i + 4, D_800C430C[i] + 8, D_800C4314[i]);
        DataClose(data);
    }
    func_80060214(0x60);
    SetFadeInTypeAndTime(6, 8);
    HuPrcSleep(7);
    label1 = func_80045D84(0, 0x14, 0);
    label2 = func_80045D84(4, 0x22, 0);
    do {
        HuPrcVSleep();
        pad = ContDStkTrg[port];
        dir = -((pad & 0x800) == 0);
        if (pad & 0x400) {
            dir = 1;
        }
        if (ContDStkTrg[port] & 0x200) {
            dir = 2;
        }
        if (ContDStkTrg[port] & 0x100) {
            dir = 3;
        }
        if (dir != -1) {
            sel += D_800C42EC[sel][dir];
        }
        D_800D61B8 = sel;
    } while (!(ContBtnTrg[port] & 0xE010));
    func_800726AC(6, 8);
    HuPrcSleep(8);
    D_800F384E = 0;
    func_8004A140();
    LoadBackgroundIndex(bg);
    func_8004B61C(&cam);
    HuPrcVSleep();
    func_8004A520();
    D_800F5278 |= 1;
    func_8003FEFC(GwSystem.curPlayerIndex);
    func_80040724(GwSystem.curPlayerIndex);
    func_80045E6C(label1);
    func_80045E6C(label2);
    EndProcess(proc);
    func_80053454(icons);
    func_80053454(markers);
    func_8003C858();
    func_8003C350();
    func_80040724(port);
    func_800559F8();
    ChangeSpaceTextures(0);
    func_80060214(0x7F);
    SetFadeInTypeAndTime(6, 8);
    HuPrcSleep(8);
    EndProcess(NULL);
}
void func_8003D20C(void* arg0) {
    Process* cur;
    Process* p;

    D_800ECC22 = 1;
    func_8005FD7C();
    cur = HuPrcCurrentGet();
    p = omAddPrcObj(func_8003CAB4, 0x1005, 0, 0);
    p->user_data = arg0;
    omPrcSetStatBit(p, 0x80);
    HuPrcChildLink(cur, p);
    HuPrcChildWatch();
    func_8005FECC();
    D_800ECC22 = 0;
}