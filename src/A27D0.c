#include "common.h"
#include "sdk_hu2.h"

typedef struct unkTesting { //unk struct of 0x28 size
    char unk_00[0x28];
} unkTesting; //sizeof 0x28

/* guLookAtReflectF (Hudson) */
void func_800A1BD0(Matrix4f mf, LookAt* l, Vec3f* p, Vec3f* tmp) {
    func_800A18F0(mf, p, tmp);
    l->l[0].l.dir[0] = (s32)(tmp[0].x * 127.0f);
    l->l[0].l.dir[1] = (s32)(tmp[0].y * 127.0f);
    l->l[0].l.dir[2] = (s32)(tmp[0].z * 127.0f);
    l->l[1].l.dir[0] = (s32)(tmp[1].x * 127.0f);
    l->l[1].l.dir[1] = (s32)(tmp[1].y * 127.0f);
    l->l[1].l.dir[2] = (s32)(tmp[1].z * 127.0f);
    l->l[0].l.col[0] = 0;
    l->l[0].l.col[1] = 0;
    l->l[0].l.col[2] = 0;
    l->l[0].l.pad1 = 0;
    l->l[0].l.colc[0] = 0;
    l->l[0].l.colc[1] = 0;
    l->l[0].l.colc[2] = 0;
    l->l[0].l.pad2 = 0;
    l->l[1].l.col[0] = 0;
    l->l[1].l.col[1] = 0x80;
    l->l[1].l.col[2] = 0;
    l->l[1].l.pad1 = 0;
    l->l[1].l.colc[0] = 0;
    l->l[1].l.colc[1] = 0x80;
    l->l[1].l.colc[2] = 0;
    l->l[1].l.pad2 = 0;
}

void func_800A1DB0(Matrix4f arg0, Vec3f* arg1) {
    unkTesting sp10;

    func_800A18F0(arg0, arg1, (Vec3f*)&sp10);
}