#include "common.h"
#include "engine/pad.h"

s32 LeoDriveExistBool = 0; /* read by the logos overlay */

/* omObjData::unk_50 work block, typed as this unit uses it (compare PlayerWork/GroundWork in
   1130.c, which views the same block for players and floors). */
typedef struct MgWork {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01; /* flags */
    /* 0x02 */ char unk_02[3];
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ char unk_28[0xC];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50; /* flags: 0x20 holding an item */
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ char unk_53[2];
    /* 0x55 */ u8 unk_55;
    /* 0x56 */ s8 unk_56; /* controller port */
    /* 0x57 */ u8 unk_57;
    /* 0x58 */ s8 unk_58;
    /* 0x59 */ char unk_59[3];
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ f32 unk_68;
    /* 0x6C */ s32 unk_6C[6]; /* packed (x << 16) | (y & 0xFFFF) stick samples */
    /* 0x84 */ char unk_84[0xC];
    /* 0x90 */ f32 unk_90;
    /* 0x94 */ f32 unk_94;
    /* 0x98 */ f32 unk_98;
    /* 0x9C */ char unk_9C[4];
    /* 0xA0 */ f32 unk_A0;
    /* 0xA4 */ f32 unk_A4;
    /* 0xA8 */ char unk_A8[9];
    /* 0xB1 */ s8 unk_B1;
    /* 0xB2 */ s8 unk_B2;
    /* 0xB3 */ s8 unk_B3;
    /* 0xB4 */ char unk_B4[4];
    /* 0xB8 */ omObjData* unk_B8; /* held item */
    /* 0xBC */ f32 unk_BC;
    /* 0xC0 */ u16 unk_C0;
    /* 0xC2 */ char unk_C2[0x16];
    /* 0xD8 */ s16 (*unk_D8)[2]; /* one pair per motion */
    /* 0xDC */ void* unk_DC; /* collision callback (PlayerWork in 1130.c) */
    /* 0xE0 */ char unk_E0[4];
    /* 0xE4 */ void* unk_E4; /* unkGlobalStruct_00's pointer: named so the host layout agrees */
} MgWork; /* size = 0xE8 */

#define MG_WORK(obj) ((MgWork*)(obj)->unk_50)
/* func_80009238/func_80009340 keep per-model bytes at offset 0x21 + slot, over unk_20/unk_24. */

/* Work block of an item a player can carry (MgWork::unk_B8). */
typedef struct MgItemWork {
    /* 0x00 */ char unk_00[0x38];
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ char unk_44[4];
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ char unk_4C[4];
    /* 0x50 */ u16 unk_50; /* flags: 0x20 carried, 0x40 can be picked up */
    /* 0x52 */ char unk_52[6];
    /* 0x58 */ f32 unk_58;
    /* 0x5C */ char unk_5C[8];
    /* 0x64 */ omObjData* unk_64; /* carrier */
} MgItemWork;

/* XZ bounds of a collision model (0x48 bytes in). */
typedef struct MgColBounds {
    /* 0x00 */ char unk_00[0x4A];
    /* 0x4A */ s16 minX;
    /* 0x4C */ s16 minY;
    /* 0x4E */ s16 minZ;
    /* 0x50 */ s16 maxX;
    /* 0x52 */ s16 maxY;
    /* 0x54 */ s16 maxZ;
} MgColBounds;

extern u16 D_800ECB08[]; /* frames since the last quadrant change */
extern u8 D_800ED0C9[];  /* last stick quadrant */
extern s8 D_800F0A38[];  /* rotation direction (-1, 0, 1) */
extern s8 D_800F2BD4[];  /* frames held in one quadrant */
extern s16 D_800F377A[]; /* frames per half turn */
extern u8 D_800F64EE[];  /* quadrant two changes ago */

extern omObjData* D_800F2AF8[];
extern s32 D_800B8950;
extern u8 D_800B8954;
extern u8 D_800B8955;
extern u8 D_800B8959;
extern u8 D_800B895A;
extern f32 D_800B895C;
extern f32 D_800B8960;
extern f32 D_800B8964;
extern f32 D_800B8968;
extern f32 D_800B896C;
extern f32 D_800B8970;
extern f32 D_800B897C;
extern f32 D_800B8980;
extern f32 D_800B8984;
extern f32 D_800B8988;
extern f32 D_800B898C;
extern f32 D_800B8990;
extern f32 D_800B8994;
extern f32 D_800B8998;
extern f32 D_800B899C;
extern u16 D_800B89A4[][14];
extern s32 D_800B8A20[];
extern s32 D_800B8A38[];
extern char* D_800B8A50[];
extern u16 D_800EC6E0[];

void func_800370D4(s16);
void func_800196A0(Matrix4f, Matrix4f);
void MtxRotate(Mat4, f32, f32, f32);
int abs(int);
void func_800284E4(s16);
void func_8002859C(s16 arg0, s16 arg1, char* arg2);
f32 func_800A1480(Vec3f*, Vec3f*);
void func_8002956C(Vec3f*);
void func_800289D0(s16 arg0, s16 arg1, f32 arg2);
f32 func_80029518(f32);
s16 func_80017850(unk2C0C0StructC0* arg0, s32 arg1, char* arg2);
void func_80039644(s16 arg0, u8 arg1, u8 arg2);
void func_8001E268(s16 index, u8 arg1, u8 arg2);

void func_80008DE0(omObjData* obj, u16 idx, s32 type, s32 flags, f32 arg4) {
    u16 mdl;
    void* data;

    mdl = LoadFormFile(D_800B8A20[type], flags & ~0x11);
    obj->model[idx] = mdl;
    data = DataRead(D_800B8A38[type]);
    func_80038A9C(D_800F2B7C[mdl].unk_6C, data, 0, D_800B8A50[type]);
    DataClose(data);
    func_800258EC(mdl, 1, 1);
    func_80025AD4(mdl);
    func_80025B34(mdl);
    if (idx != 0) {
        func_800289D0(obj->model[0], mdl, arg4);
    }
}

void func_80008EF0(omObjData* obj, u16 idx, s32 dir, s32 file, f32 arg4) {
    s16 mdl = LoadFormFile(dir, file);

    obj->model[idx] = mdl;
    func_800289D0(obj->model[0], mdl, arg4);
}

void func_80008F64(omObjData* obj, f32 angle) {
    MgWork* work = MG_WORK(obj);

    work->unk_3C = func_80029518(angle);
}

void func_80008F94(omObjData* obj, f32 arg1) {
    MG_WORK(obj)->unk_40 = arg1;
}

void func_80008FA0(omObjData* obj, f32 arg1) {
    MG_WORK(obj)->unk_38 = arg1;
}

void func_80008FAC(omObjData* obj, f32 arg1) {
    MG_WORK(obj)->unk_44 = arg1;
}

void func_80008FB8(omObjData* obj, f32 arg1) {
    MG_WORK(obj)->unk_08 = arg1;
}

void func_80008FC4(omObjData* obj, f32 arg1) {
    MG_WORK(obj)->unk_0C = arg1;
}

void func_80008FD0(omObjData* obj, f32 arg1) {
    MG_WORK(obj)->unk_48 = arg1;
}

void func_80008FDC(omObjData* obj, f32 arg1) {
    MG_WORK(obj)->unk_34 = arg1;
}

void func_80008FE8(omObjData* obj, f32 arg1) {
    MG_WORK(obj)->unk_64 = arg1;
}

void func_80008FF4(omObjData* obj, f32 arg1) {
    MG_WORK(obj)->unk_68 = arg1;
}

void func_80009000(omObjData* obj, s32 flags, f32 arg2) {
    MgWork* work = MG_WORK(obj);

    work->unk_01 = flags | work->unk_01;
    if (flags & 2) {
        work->unk_10 = arg2;
    }
}

void func_80009028(omObjData* obj, s32 arg1, f32 minX, f32 minZ, f32 maxX, f32 maxZ) {
    MgWork* work = MG_WORK(obj);

    work->unk_01 |= 8;
    *(s32*)&work->unk_10 = arg1;
    work->unk_18 = minX;
    work->unk_1C = minZ;
    work->unk_20 = maxX;
    work->unk_24 = maxZ;
}

void func_80009058(omObjData* obj, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    MgWork* work = MG_WORK(obj);

    work->unk_01 |= 0x10;
    work->unk_10 = arg1;
    work->unk_14 = arg2;
    work->unk_18 = arg3;
    work->unk_1C = arg4;
    work->unk_20 = arg5;
    work->unk_24 = arg6;
}

void func_80009090(omObjData* obj) {
    MG_WORK(obj)->unk_01 |= 0x20;
}

void func_800090A4(omObjData* obj) {
    MG_WORK(obj)->unk_01 |= 0x80;
}

void func_800090B8(u16 arg0) {
    D_800B8954 = arg0;
}

void func_800090C4(omObjData* obj, u8 idx, u8 val) {
    u8* work = obj->unk_50;

    work[idx] = val;
}

void func_800090D8(omObjData* obj, u8 idx, u8 on) {
    if (on == 0) {
        func_800258EC(obj->model[idx], 4, 4);
    } else {
        func_800258EC(obj->model[idx], 4, 0);
    }
}
s32 func_80009138(s8 id) {
    s32 i;
    MgWork* work;

    if (id < 0) {
        return 0;
    }
    for (i = 0; i < D_800ED440; i++) {
        work = MG_WORK(D_800F2AF8[i]);
        if (work->unk_05 == id) {
            if (work->unk_01 & 0x20) {
                return 0;
            }
            break;
        }
    }
    return 1;
}

void func_800091BC(omObjData* obj, s32 dir, s32 file, s32 arg3) {
    MgWork* work = MG_WORK(obj);

    work->unk_55 = ReadImgPackand(dir, file, arg3);
    obj->model[0] = D_800ECDE0[work->unk_55].unk_00;
    func_80025930(obj->model[0], 0x70000000, 0x70000000);
}

void func_80009238(omObjData* obj, u8 idx, s32 dir, s32 arg3, char* arg4, s32 arg5) {
    u8* work = obj->unk_50;
    unk_ovl_2D_struct* m;
    u8 r;

    obj->model[idx] = func_800174F4(dir, arg5);
    m = &D_800F2B7C[obj->model[idx]];
    r = func_80017850(m->unk_6C, arg3, arg4);
    (work + idx)[0x21] = r;
    func_80025AD4(obj->model[idx]);
    func_80039644(r, 1, 1);
    func_80039644(r, 2, 2);
    func_80025830(obj->model[idx], 2.0f, 2.0f, 2.0f);
}

void func_80009340(omObjData* obj, s32 idx, s32 dir, s32 file, s32 arg4) {
    u8* work = obj->unk_50;
    u16 img = ReadImgPackand(dir, file, arg4);

    obj->model[(u8)idx] = D_800ECDE0[(u8)img].unk_00;
    work += (u8)idx;
    work[0x21] = img;
    func_80025930(D_800ECDE0[(u8)img].unk_00, 0x70000000, 0x70000000);
    func_8001E268((u8)img, 4, 4);
}

void func_800093FC(omObjData* obj, f32 x, f32 y, f32 z) {
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = z;
}

void func_8000940C(omObjData* obj, f32 x, f32 y, f32 z) {
    obj->rot.x = x;
    obj->rot.y = y;
    obj->rot.z = z;
}

void func_8000941C(omObjData* obj, f32 x, f32 y, f32 z) {
    obj->scale.x = x;
    obj->scale.y = y;
    obj->scale.z = z;
}

void func_8000942C(void) {
    D_800B8950 = 0;
}

void func_80009438(void) {
    D_800B8950 = 2;
}

void func_80009448(void) {
    D_800B8950 = 3;
}

void func_80009458(void) {
    D_800B8950 = 1;
}

void func_80009468(void) {
    D_800ED430 = D_800B8950;
}
s32 func_8000947C(s32 id) {
    s32 i;

    for (i = 0; i < D_800ED440; i++) {
        if (((u8*)D_800F2AF8[i])[0x54] == id) {
            return i;
        }
    }
    return D_800B8954;
}

void func_800094DC(void) {
    s32 buf;

    func_8009B770(&buf, 0, 1);
}

void func_80009500(void) {
    D_800B895C = 15.0f;
    D_800B8960 = 0.5f;
    D_800B8964 = 1.47f;
    D_800B8968 = 0.15f;
    D_800B896C = 7.0f;
    D_800B8970 = 30.0f;
    D_800B8998 = 0.5f;
    D_800B897C = 3.3333333f;
    D_800B8980 = 18.0f;
    D_800B8984 = 13.5f;
    D_800B8988 = 9.0f;
    D_800B898C = 4.5f;
    D_800B8990 = 0.0f;
    D_800B8994 = 1.7f;
    D_800B899C = 0.147f;
    D_800B8955 = 1;
    D_800B895A = 0;
}

void func_8000960C(s32 arg0) {
    D_800B895A = arg0;
}

void func_80009618(s32 arg0) {
    D_800B8959 = arg0;
}

void func_80009624(unkGlobalStruct_00* arg0, s32 arg1) {
    MgWork* work = (MgWork*)arg0;
    s8 player = work->unk_58;
    u16 id = D_800B89A4[player][arg1];

    if (work->unk_B2 != arg1) {
        work->unk_B3 = func_80060540(id, player);
        work->unk_B2 = arg1;
        D_800EC6E0[work->unk_58] = id;
    }
}

void func_800096B0(MgWork* work, s32 arg1) {
    s8 player = work->unk_58;
    s16 id = D_800B89A4[player][arg1];

    work->unk_B3 = func_80060540(id, player);
    work->unk_B2 = arg1;
    D_800EC6E0[work->unk_58] = id;
}

void func_80009730(void) {
    s32 i;

    for (i = 0; i < D_800F2BC0; i++) {
        func_8006071C(MG_WORK(D_800F3FB0[i])->unk_B3);
    }
}

/* Sets up a minigame player object for player `player`. */
void func_8000979C(omObjData* obj, s32 dir, s32 file, u16 player, s32 flags, s32 motFile) {
    MgWork* work;
    s32 i;

    for (i = 0; i < obj->mdlcnt; i++) {
        obj->model[i] = 0;
    }
    obj->unk_50 = func_80023684(sizeof(MgWork), 0x7918);
    func_8009B770(obj->unk_50, 0, sizeof(MgWork));
    work = obj->unk_50;
    work->unk_D8 = func_80023684(obj->mtncnt * 4, 0x7918);
    if (D_800B895A == 1) {
        func_80008DE0(obj, 0, GwPlayer[player].character, flags, 1000.0f);
    } else {
        obj->model[0] = LoadFormFile(dir | file, flags);
    }
    obj->model[1] = func_800174F4(D_800B8959 == 0 ? 6 : 0x20, motFile);
    func_800370D4(obj->model[1]);
    for (i = 0; i < obj->mtncnt; i++) {
        obj->motion[i] = -1;
    }
    for (i = 0; i < obj->mtncnt; i++) {
        work->unk_D8[i][0] = 0;
        work->unk_D8[i][1] = 0;
    }
    work->unk_56 = GwPlayer[player].port;
    obj->func_ptr = func_80005A28;
    work->unk_52 = 0;
    work->unk_A4 = 1.0f;
    work->unk_C0 = 0xFFFF;
    work->unk_4C = 0.5f;
    work->unk_BC = 1.0f;
    work->unk_60 = 0.0f;
    func_80008FD0(obj, 60.0f);
    func_80008FDC(obj, 150.0f);
    func_80008FE8(obj, 20.0f);
    func_80008FF4(obj, 30.0f);
    func_80008FA0(obj, 1000.0f);
    work->unk_90 = work->unk_94 = work->unk_98 = 0.0f;
    work->unk_58 = player;
    work->unk_B2 = work->unk_B1 = -1;
    switch ((u32)dir >> 16) {
        case 5:
            work->unk_A0 = 0.7f;
            break;
        case 3:
            work->unk_A0 = 0.9f;
            break;
        case 4:
            work->unk_A0 = 0.8f;
            break;
        default:
            work->unk_A0 = 1.0f;
            break;
    }
    i = GwPlayer[player].character + 1; /* character id, 1-based */
    D_800B89A4[work->unk_58][0] = i + 0x112;
    D_800B89A4[work->unk_58][1] = i + 0x119;
    D_800B89A4[work->unk_58][2] = i + 0x120;
    D_800B89A4[work->unk_58][3] = i + 0x127;
    D_800B89A4[work->unk_58][4] = i + 0x12E;
    D_800B89A4[work->unk_58][5] = i + 0x135;
    D_800B89A4[work->unk_58][6] = i + 0x13C;
    D_800B89A4[work->unk_58][7] = 0x144;
    D_800B89A4[work->unk_58][8] = 0x145;
    D_800B89A4[work->unk_58][9] = 0x146;
    D_800B89A4[work->unk_58][10] = i + 0x147;
    D_800B89A4[work->unk_58][11] = i + 0x14E;
    D_800B89A4[work->unk_58][12] = 0x160;
    D_800B89A4[work->unk_58][13] = 0x162;
}
// register allocation: retail builds the packed sample in a0 (masked 2)
#ifdef NON_MATCHING
/* Averages the last six stick samples. */
s32 func_80009C90(omObjData* obj, s16 x, s16 y) {
    MgWork* work = MG_WORK(obj);
    s32 v = (x << 16) | (y & 0xFFFF);
    s16 sy;
    s16 sx;
    u8 i;

    work->unk_6C[work->unk_57++] = v;
    if (work->unk_57 >= 6) {
        work->unk_57 = 0;
    }
    sy = 0;
    sx = 0;
    for (i = 0; i < 6; i++) {
        sx += work->unk_6C[i] >> 16;
        sy += (u16)work->unk_6C[i];
    }
    return ((sx / 6) << 16) | ((sy / 6) & 0xFFFF);
}
#else
INCLUDE_ASM("asm/nonmatchings/99E0", func_80009C90);
#endif

void func_80009D48(s16* x, s16* y) {
    Vec3f v;
    f32 fx = *x;
    f32 fy = *y;

    if (func_800B1750(fx * fx + fy * fy) > 60.0f) {
        v.x = fx;
        v.y = 0.0f;
        v.z = fy;
        func_8002956C(&v);
        *x = v.x * 60.0f;
        *y = v.z * 60.0f;
    }
}

void func_80009E20(omObjData* obj) {
    MgWork* work = MG_WORK(obj);
    s32 i;

    for (i = 0; i < 6; i++) {
        work->unk_6C[i] = 0;
    }
}
/* Stick rotation detector: returns the turning direction, doubled on a fast half turn. */
s16 func_80009E4C(s16 player, s16 limit, s8 x, s8 y) {
    s16 mult = 1;
    s16 quad;
    s16 d;
    s8 dir;

    if ((x == 0) & (y == 0)) {
        return 0;
    }
    quad = func_800B0CD8(y, x);
    if (quad < 0) {
        quad += 360;
    }
    quad /= 90;
    if (quad == D_800ED0C9[player]) {
        if (++D_800F2BD4[player] > limit) {
            D_800F2BD4[player] = limit;
            D_800F0A38[player] = 0;
            D_800F64EE[player] = quad;
            D_800ECB08[player] = 0;
            return 0;
        }
        D_800ECB08[player]++;
        return D_800F0A38[player];
    }
    D_800ECB08[player]++;
    D_800F2BD4[player] = 0;
    if (D_800F64EE[player] == quad) {
        mult = 2;
        D_800F377A[player] = D_800ECB08[player];
        D_800ECB08[player] = 0;
    }
    d = quad - D_800ED0C9[player];
    if ((d < 0 ? -d : d) == 3) {
        d = -d;
    }
    dir = (d >> 31) | 1;
    if (dir != 0 && dir != D_800F0A38[player]) {
        D_800F0A38[player] = dir;
        D_800ED0C9[player] = quad;
        D_800F2BD4[player] = 0;
        D_800F64EE[player] = quad;
        D_800ECB08[player] = 0;
        return 0;
    }
    D_800ECB08[player]++;
    if (((D_800ED0C9[player] + D_800F0A38[player]) & 3) == quad) {
        D_800ED0C9[player] = quad;
        return D_800F0A38[player] * mult;
    }
    D_800F0A38[player] = dir;
    D_800ED0C9[player] = quad;
    D_800F2BD4[player] = 0;
    D_800ECB08[player] = 0;
    return 0;
}

/* Moves p by obj's translation and rotation; m is scratch, out receives the matrix. */
void func_8000A1C0(Matrix4f m, Matrix4f out, Vec3f* p, omObjData* obj) {
    f32 rx = obj->rot.x;
    f32 ry = obj->rot.y;
    f32 rz = obj->rot.z;
    f32 tx = obj->trans.x;
    f32 ty = obj->trans.y;
    f32 tz = obj->trans.z;
    f32 x = p->x;
    f32 y = p->y;
    f32 z = p->z;

    if (((tx != 0.0f) | (ty != 0.0f)) || tz != 0.0f) {
        func_8009EA40(m, tx, ty, tz);
    } else {
        func_800A2A50(m);
    }
    if (((rx != 0.0f) | (ry != 0.0f)) || rz != 0.0f) {
        MtxRotate(m, rx, ry, rz);
    }
    func_800196A0(m, out);
    p->x = x * out[0][0] + y * out[1][0] + z * out[2][0] + out[3][0];
    p->y = x * out[0][1] + y * out[1][1] + z * out[2][1] + out[3][1];
    p->z = x * out[0][2] + y * out[1][2] + z * out[2][2] + out[3][2];
}

/* Rotates v by the 3x3 part of m. */
void func_8000A3E8(f32 m[4][4], Vec3f* v) {
    f32 x = v->x;
    f32 y = v->y;
    f32 z = v->z;

    v->x = x * m[0][0] + y * m[1][0] + z * m[2][0];
    v->y = x * m[0][1] + y * m[1][1] + z * m[2][1];
    v->z = x * m[0][2] + y * m[1][2] + z * m[2][2];
}

void func_8000A464(f32 m[4][4], Vec3f* v) {
    f32 x = v->x;
    f32 y = v->y;
    f32 z = v->z;

    v->x = x * m[0][0] + y * m[1][0] + z * m[2][0] + m[3][0];
    v->y = x * m[0][1] + y * m[1][1] + z * m[2][1] + m[3][1];
    v->z = x * m[0][2] + y * m[1][2] + z * m[2][2] + m[3][2];
}

void func_8000A4F8(f32 m[4][4], Vec3f* v) {
    f32 x = v->x;
    f32 y = v->y;
    f32 z = v->z;

    v->y = x * m[0][1] + y * m[1][1] + z * m[2][1] + m[3][1];
}

void func_8000A534(omObjData* obj, f32 speed) {
    MgWork* work = MG_WORK(obj);
    omObjData* item;
    MgItemWork* itemWork;

    if (work->unk_50 & 0x20) {
        item = work->unk_B8;
        itemWork = item->unk_50;
        work->unk_50 &= ~0x120;
        itemWork->unk_50 &= ~0x20;
        func_800258EC(item->model[0], 0x4000, 0);
        func_800284E4(obj->model[0]);
        itemWork->unk_38 = -D_800B8964 * 0.8f;
        itemWork->unk_3C = work->unk_3C;
        itemWork->unk_40 = speed;
        itemWork->unk_64 = NULL;
        item->trans.x = obj->trans.x;
        item->trans.y = work->unk_34 + itemWork->unk_48 + obj->trans.y;
        item->trans.z = obj->trans.z;
        work->unk_B8 = NULL;
        work->unk_A4 = 1.0f;
    }
}
const char D_800C9F20[] = "donky_kao_3_DEF";

const char D_800C9F30[] = "wario_kao2_DEF";

const char D_800C9F40[] = "c003_400b_DEF";

const char D_800C9F50[] = "pe_lod1a_DEF";

const char D_800C9F60[] = "luigi_lod_DEF";

const char D_800C9F70[] = "ma_l_3_DEF";

s32 func_8000A634(omObjData* obj, omObjData* item) {
    MgWork* work = MG_WORK(obj);
    MgItemWork* itemWork = item->unk_50;

    if (!(itemWork->unk_50 & 0x40)) {
        return 0;
    }
    if (itemWork->unk_50 & 0x20) {
        return 0;
    }
    if (work->unk_50 & 0x20) {
        return 0;
    }
    work->unk_50 |= 0x120;
    itemWork->unk_50 |= 0x20;
    work->unk_B8 = item;
    itemWork->unk_64 = obj;
    func_8002859C(item->model[0], obj->model[0], "item_hook");
    func_800258EC(item->model[0], 0x4000, 0x4000);
    work->unk_A4 = itemWork->unk_58;
    return 1;
}

void func_8000A6F4(omObjData* obj) {
    MgWork* work = MG_WORK(obj);

    func_800284E4(obj->model[0]);
    work->unk_50 &= ~0x100;
}
f32 func_8000A72C(f32 x1, f32 z1, f32 x2, f32 z2) {
    Vec3f a;
    Vec3f b;

    a.x = x1;
    a.y = 0.0f;
    a.z = z1;
    func_8002956C(&a);
    b.x = x2;
    b.y = 0.0f;
    b.z = z2;
    func_8002956C(&b);
    return func_800A1480(&b, &a);
}
s32 func_8000A798(MgColBounds* b, Vec3f* p) {
    f32 minX = b->minX;
    f32 minZ = b->minZ;
    f32 maxX = b->maxX;
    f32 maxZ = b->maxZ;

    if (minX <= p->x && minZ <= p->z && p->x <= maxX && p->z <= maxZ) {
        return 1;
    }
    return 0;
}
s32 func_8000A830(MgColBounds* b, Vec3f* p, f32 r) {
    f32 x = p->x;
    f32 z = p->z;
    f32 minX = b->minX - r;
    f32 maxZ;
    f32 maxX;
    f32 minZ = b->minZ - r;

    maxX = b->maxX + r;
    maxZ = b->maxZ + r;

    if ((minX <= x) & (minZ <= z)) {
        if ((x <= maxX) & (z <= maxZ)) {
            return 1;
        }
    }
    return 0;
}
s32 func_8000A910(Vec4f* p, MgWork* g) {
    f32 x;
    f32 z;

    if (!(g->unk_01 & 0x10)) {
        return 1;
    }
    x = p->x;
    z = p->z;
    if (g->unk_18 <= x && x <= g->unk_20 && g->unk_1C <= z && z <= g->unk_24) {
        return 1;
    }
    return 0;
}

void func_8000A988(omObjData* obj, f32 dx, f32 dz) {
    MgWork* work = MG_WORK(obj);
    s16 stick[2];
    s32 avg;

    if (work->unk_5C & 0x200) {
        work->unk_4C = 0.7f;
    } else {
        work->unk_4C = 0.6f;
    }
    func_800184BC(obj, 6);
    if (abs(ContStkX[work->unk_56]) >= 9 || abs(ContStkY[work->unk_56]) >= 9) {
        s32 sx = ContStkX[work->unk_56];
        s32 sy;

        stick[0] = sx;
        sy = ContStkY[work->unk_56];
        stick[1] = sy;
        if (sx > 60) {
            stick[0] = 60;
        }
        if (stick[1] > 60) {
            stick[1] = 60;
        }
        if (stick[0] < -60) {
            stick[0] = -60;
        }
        if (stick[1] < -60) {
            stick[1] = -60;
        }
        func_80009D48(&stick[0], &stick[1]);
        func_80009C90(obj, stick[0], stick[1]);
        func_80009C90(obj, stick[0], stick[1]);
        func_80009C90(obj, stick[0], stick[1]);
        func_80009C90(obj, stick[0], stick[1]);
        func_80009C90(obj, stick[0], stick[1]);
        avg = func_80009C90(obj, stick[0], stick[1]);
        stick[0] = avg >> 16;
        stick[1] = avg;
        work->unk_3C = func_800B0CD8(stick[0], -stick[1]) + work->unk_60;
        work->unk_40 = D_800B8980;
    } else if (func_8000A72C(func_800AEAC0(work->unk_3C), func_800AEFD0(work->unk_3C), dx, dz) < 0.0f) {
        work->unk_40 = D_800B8980;
    } else {
        work->unk_40 = -D_800B8980;
    }
    work->unk_38 = -D_800B8964 * 0.9f;
    work->unk_50 |= 0x10;
}

void func_8000AC28(MgWork* work, f32 dx, f32 dz) {
    f32 s = func_800AEAC0(work->unk_3C);

    if (func_8000A72C(s, func_800AEFD0(work->unk_3C), dx, dz) >= 0.0f) {
        work->unk_40 = D_800B8984;
    } else {
        work->unk_40 = -D_800B8984;
    }
    work->unk_50 |= 0x10;
    func_80009624((unkGlobalStruct_00*)work, 7);
}

void func_8000ACE4(omObjData* a, omObjData* b) {
    MgWork* bw = MG_WORK(b);

    func_8000AC28(MG_WORK(a), a->trans.x - b->trans.x, a->trans.z - b->trans.z);
    func_8000AC28(bw, b->trans.x - a->trans.x, b->trans.z - a->trans.z);
}
/* Two unreferenced empty strings end this unit's .rodata in the ROM. */
const char D_800C9F88[] = "";
const char D_800C9F8C[] = "";
