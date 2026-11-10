#include "common.h"

typedef struct {
    /* 0x00 */ u8 type;
    /* 0x01 */ u8 mode;
    /* 0x02 */ s16 y;
    /* 0x04 */ omObjData* obj;
    /* 0x08 */ s16 win;
    /* 0x0C */ u8* str;
    /* 0x10 */ char* extra;
} LabelWin;

typedef struct {
    /* 0x00 */ u8* str;
    /* 0x04 */ s16 len;
} LabelDef;

/* Label strings (Shift-JIS) and the format string D_800CAF7C (rodata moved here from 43760 and
   three unnamed subsegments). */
const char D_800CAE60[] = "\x89\x45\x81\x63\x83P\x81J\x81[\x83\x80\x82\xC9\x82\xE0\x82\xC6\x81J\x82\xE9";
const char D_800CAE78[] = "\x89\x45\x81@\x82n\x82\x96\x82\x85\x82\x92\x82\x96\x82\x89\x82\x85\x82\x97";
const char D_800CAE90[] = "\x83\xBF\x81\x63\x82\xBB\x82\xA4\x82\xB3\x82\xCC\x82\xAB\x82\xE8\x82\xA9\x82\xA6";
const char D_800CAEA8[] = "\x83\xBF\x81@\x82r\x82\x85\x82\x94\x82\x94\x82\x89\x82\x8E\x82\x87\x82\x93";
const char D_800CAEC0[] = "\x83\xC0\x81\x63\x82\xDC\x82\xA6\x82\xCC\x82\xA9\x81J\x82\xDF\x82\xF1\x82\xC9\x82\xE0\x82\xC6\x81J\x82\xE9";
const char D_800CAEE0[] = "\x83\xC0\x81\x63\x83P\x81J\x81[\x83\x80\x82\xF0\x82\xE2\x82\xDF\x82\xE9";
const char D_800CAEF8[] = "\x87@\x81@\x82l\x82\x8F\x82\x96\x82\x85\x82\x93";
const char D_800CAF08[] = "\x8En\x81@\x82\x61\x82\x81\x82\x83\x82\x8B\x81@\x82\x94\x82\x8F\x81@\x82\x66\x82\x81\x82\x8D\x82\x85";
const char D_800CAF28[] = "\x83\xC0\x81@\x82\x61\x82\x81\x82\x83\x82\x8B";
const char D_800CAF38[] = "\x83\xC0\x81@\x82l\x82\x81\x82\x90";
const char D_800CAF44[] = "\x83\xBF\x81@\x82\x61\x82\x8C\x82\x8F\x82\x83\x82\x8B";
const char D_800CAF54[] = "\x83\xBF\x81@\x82\x63\x82\x85\x82\x83\x82\x89\x82\x84\x82\x85";
const char D_800CAF68[] = "\x81\xA7\x81@\x82\x62\x82\x88\x82\x8F\x82\x8F\x82\x93\x82\x85";
const char D_800CAF7C[] = "\x09%2d\x08";
const u32 D_800CAF84[3] = { 0, 0, 0 }; /* unreferenced zero tail up to 47320's rodata */
LabelDef D_800C4E60[] = {
    { (u8*)D_800CAF68, 4 },
    { (u8*)D_800CAF54, 4 },
    { (u8*)D_800CAF44, 3 },
    { (u8*)D_800CAF38, 3 },
    { (u8*)D_800CAF28, 3 },
    { (u8*)D_800CAF08, 7 },
    { (u8*)D_800CAEF8, 4 },
    { (u8*)D_800CAEE0, 9 },
    { (u8*)D_800CAEC0, 12 },
    { (u8*)D_800CAEA8, 5 },
    { (u8*)D_800CAE90, 10 },
    { (u8*)D_800CAE78, 5 },
    { (u8*)D_800CAE60, 9 },
};

extern u8 D_800F64F8;
extern s16 D_800F3FF2;


void func_80045BE0(LabelWin* w) {
    LabelDef* def = &D_800C4E60[w->type];

    w->win = func_8006D010(160 - (def->len * 11 + 16) / 2, w->y, def->len * 11 + 16, 20, 0, 0);
    if (w->extra != NULL) {
        func_8006DA5C(w->win, w->extra, 0);
    }
    func_8006E0A4(w->win, 5);
    func_8006E154(w->win, 0);
    w->str = MallocTemp(def->len * 2 + 1);
    func_8007149C(w->str, def->str);
    LoadStringIntoWindow(w->win, w->str, -1, -1);
    func_8006E070(w->win, 0);
}
void func_80045CE4(LabelWin* w) {
    func_80070D90(w->win);
    FreeTemp(w->str);
    w->win = -1;
}
void func_80045D1C(omObjData* obj) {
    LabelWin* w = obj->unk_50;

    if (w->mode == 1 && D_800F64F8 != 0) {
        if (w->win >= 0) {
            func_80045CE4(w);
        }
    } else if (w->win < 0) {
        func_80045BE0(w);
    }
}
s32 func_80045D84(s16 type, s16 y, s8 mode) {
    LabelWin* w = MallocTemp(sizeof(LabelWin));

    if (w != NULL) {
        w->type = type;
        w->y = y;
        w->mode = mode;
        w->obj = omAddObj(0x100, 0, 0, -1, func_80045D1C);
        w->obj->unk_50 = w;
        omSetStatBit(w->obj, 0x80);
        w->win = -1;
        if (type == 6) {
            w->extra = MallocTemp(8);
            sprintf(w->extra, D_800CAF7C, D_800F3FF2);
        } else {
            w->extra = NULL;
        }
    }
    return (s32)w;
}

void func_80045E6C(s32 arg0) {
    LabelWin* w = (LabelWin*)arg0;

    if (w != NULL) {
        w->obj->unk_50 = NULL;
        omDelObj(w->obj);
        if (w->win >= 0) {
            func_80070D90(w->win);
            FreeTemp(w->str);
            if (w->extra != NULL) {
                FreeTemp(w->extra);
            }
        }
        FreeTemp(w);
    }
}