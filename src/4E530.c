#include "common.h"

#include "common.h"

void func_80071264(void);


extern s32 D_800C5270[];
extern s32 D_800C529C[];
extern s16 D_800F329A;
void func_8004E564(omObjData* arg0);
void func_8004EC44(omObjData* arg0);


extern s8 D_800D8360;
extern f32 D_800D8364;
extern f32 D_800D8368;
extern s32 D_800C5250[7];
extern s32 D_800C526C;
s8 func_8000C4A0(void);
void func_80060F04(s16, s32, s32, s32);
void func_80050338(void);


typedef struct {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ Object* unk4;
    /* 0x08 */ omObjData* unk8;
} Unk4E530Motion;

typedef struct {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
} Unk4E530Sprite;

typedef struct unk1EA70Struct1C unk1EA70Struct1C;

typedef struct {
    /* 0x00 */ omObjData* unk0;
    /* 0x04 */ unk1EA70Struct1C* unk4;
} Unk4E530Effect;

typedef struct {
    /* 0x00 */ void* unk0;
    /* 0x04 */ s16 unk4;
} Unk4E530Data;

extern Unk4E530Motion D_800D8160[16];
extern Unk4E530Sprite D_800D8220[16];
extern Unk4E530Effect D_800D8260[16];
extern Unk4E530Data D_800D82E0[16];

void func_8005699C(s32);
f32 func_80025D18(s16);
f32 func_80025D40(s16);
void func_80067284(s16, s16, f32);
void func_800214FC(unk1EA70Struct1C*);
unk1EA70Struct1C* func_80021308(s32, s16);
s16 func_80021794(unk1EA70Struct1C*, s16, f32, f32, f32, s16);
void func_80021AF4(unk1EA70Struct1C*, f32, f32, f32);
void func_80021474(unk1EA70Struct1C*);
void func_80039ACC(s16);


extern char D_800CB110[];
extern char D_800CB11C[];
extern omObjData* D_800C5248;
extern s32 D_800C524C;
extern omObjData* D_800F50C0[32];

/* Character names; the .data tables D_800C5218 / D_800C5230 point at them. */
const char D_800CB090[] = "DK";
const char D_800CB094[] = "Wario";
const char D_800CB09C[] = "Yoshi";
const char D_800CB0A4[] = "Peach";
const char D_800CB0AC[] = "Luigi";
const char D_800CB0B4[] = "Mario";
const char D_800CB0BC[] = "DK    ";
const char D_800CB0C4[] = "Wario ";
const char D_800CB0CC[] = "Yoshi ";
const char D_800CB0D4[] = "Peach ";
const char D_800CB0DC[] = "Luigi ";
const char D_800CB0E4[] = "Mario ";

/* Controller-port bit per port; func_8004DBD4 and WaitForTextConfirmation copy it. */
typedef struct {
    u8 bit[4];
} PortMasks;

const PortMasks D_800CB0EC = { { 1, 2, 4, 8 } };

/* func_8004DBD4 (asm) reads the low byte through D_800C5213 (undefined_syms.txt). */
s32 D_800C5210 = 0x19;
s32 D_800C5214 = 0x19;
char* D_800C5218[] = { (char*)D_800CB0B4, (char*)D_800CB0AC, (char*)D_800CB0A4, (char*)D_800CB09C, (char*)D_800CB094, (char*)D_800CB090 };
char* D_800C5230[] = { (char*)D_800CB0E4, (char*)D_800CB0DC, (char*)D_800CB0D4, (char*)D_800CB0CC, (char*)D_800CB0C4, (char*)D_800CB0BC };
omObjData* D_800C5248 = NULL;
s32 D_800C524C = -1;
s32 D_800C5250[7] = { 0xA017C, 0xA017D, 0xA017E, 0xA017F, 0xA0180, 0xA0181, 0xA0182 };
s32 D_800C526C = -1;
s32 D_800C5270[] = { 2, 9, 0x14, 0x1D, 0x29, 0x31, 0x3A, 0x47, 0x47, 0x68, 0x47 };
s32 D_800C529C[] = { 0x5A, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F, 0x60, 0x61, 0x62, 0x59 };

s32 CreateTextWindow(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_s1;

    temp_s1 = func_8006D010(arg0, arg1, ((arg2 * 0xB) + 8), ((arg3 * 0xE) + 6), 0, 0);
    func_8006E154(temp_s1, 0xC8);
    func_800717C0(temp_s1);
    func_8006DA1C(temp_s1, 0x40, 0x40);
    return temp_s1;
}

void ShowTextWindow(s32 arg0) {
    s32 i;

    PlaySound(0x36);
    func_80071740(arg0, 1);
    func_8006DEC8(arg0, 0, 0);
    func_8006E01C(arg0, 180.0f);
    func_8006DE20(arg0, 0.0f, 0.0f);
    
    for (i = 0; i < 0xB5; i += 0x14) {
        HuPrcVSleep();
        func_8006E01C(arg0, 180.0f - i);
        func_8006DE20(arg0, i / 180.0f, i / 180.0f);        
    }
    
    func_80071740(arg0, 0);
}

void HideTextWindow(s32 arg0) {
    s32 i;

    PlaySound(0x37);
    
    for (i = 0xB4; i >= 0; i -= 0x14) {
        HuPrcVSleep();
        func_8006E01C(arg0, (0xB4 - i) * 2);
        func_8006DE20(arg0, i / 180.0f, i / 180.0f);
    }
    
    func_80070D90(arg0);
    HuPrcVSleep();
}

void func_8004DB9C(s32 arg0) {
    D_800C5214 = arg0;
    func_8004DBC8(arg0);
}

s32 func_8004DBBC(void) {
    return D_800C5214;
}

void func_8004DBC8(s32 arg0) {
    D_800C5210 = arg0;
}

// decomp-permuter
void func_8004DBD4(s32 arg0, s32 arg1)
{
  s32 cpu = 0;
  u8 new_var;
  s16 colors[4];
  PortMasks masks = D_800CB0EC;
  s32 i;
  for (i = 0; i < 4; i++)
  {
    if (i == arg1)
    {
      if (GwPlayer[i].flags & 1)
      {
        cpu = 1;
        colors[GwPlayer[i].port] = -0x8000;
      }
      else
      {
        new_var = GwPlayer[i].port;
        func_8007155C(arg0, masks.bit[new_var]);
        colors[GwPlayer[i].port] = -1;
      }
    }
    else
    {
      colors[GwPlayer[i].port] = 0;
    }
  }

  if (cpu != 0)
  {
    func_8006DA1C(arg0, 2, 2);
    func_80070FF8(colors[0], colors[1], colors[2], colors[3], (u8) D_800C5210);
    func_80070FF8(colors[0], colors[1], colors[2], colors[3], (u8) D_800C5210);
    func_80070FF8(colors[0], colors[1], colors[2], colors[3], (u8) D_800C5210);
    func_80070FF8(colors[0], colors[1], colors[2], colors[3], (u8) D_800C5210);
    func_80070FF8(colors[0], colors[1], colors[2], colors[3], (u8) D_800C5210);
    func_80070FF8(colors[0], colors[1], colors[2], colors[3], (u8) D_800C5210);
    func_80070FF8(colors[0], colors[1], colors[2], colors[3], (u8) D_800C5210);
    D_800C5210 = D_800C5214;
  }
  else
  {
    func_800710A4(colors[0], colors[1], colors[2], colors[3]);
  }
  while (func_8006FCC0(arg0) != 0)
  {
    HuPrcVSleep();
  }

  func_80071264();
}
void WaitForTextConfirmation(s16 arg0) {
    s16 colors[4];
    PortMasks masks = D_800CB0EC;
    u8 mask = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (!(GwPlayer[i].flags & 1)) {
            break;
        }
    }
    if (i == 4) {
        func_8006DA1C(arg0, 2, 2);
        func_80070FF8(-0x8000, -0x8000, -0x8000, -0x8000, (u8)D_800C5210);
        func_80070FF8(-0x8000, -0x8000, -0x8000, -0x8000, (u8)D_800C5210);
        func_80070FF8(-0x8000, -0x8000, -0x8000, -0x8000, (u8)D_800C5210);
        func_80070FF8(-0x8000, -0x8000, -0x8000, -0x8000, (u8)D_800C5210);
        func_80070FF8(-0x8000, -0x8000, -0x8000, -0x8000, (u8)D_800C5210);
        func_80070FF8(-0x8000, -0x8000, -0x8000, -0x8000, (u8)D_800C5210);
        func_80070FF8(-0x8000, -0x8000, -0x8000, -0x8000, (u8)D_800C5210);
        D_800C5210 = D_800C5214;
        while (func_8006FCC0(arg0) != 0) {
            HuPrcVSleep();
        }
        func_80071264();
    } else {
        for (i = 0; i < 4; i++) {
            if (GwPlayer[i].flags & 1) {
                colors[GwPlayer[i].port] = 0;
            } else {
                mask |= masks.bit[GwPlayer[i].port];
                colors[GwPlayer[i].port] = -1;
            }
        }
        func_8007155C(arg0, mask);
        func_800710A4(colors[0], colors[1], colors[2], colors[3]);
        while (func_8006FCC0(arg0) != 0) {
            HuPrcVSleep();
        }
    }
}
void func_8004E0E8(s32 arg0) {
    func_8007155C(arg0, 0xF);
    func_800710A4(-1, -1, -1, -1);
    
    while ((func_8006FCC0(arg0)) != 0) {
        HuPrcVSleep();
    }
}

void func_8004E154(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800F50C0); i++) {
        D_800F50C0[i] = 0;
    }

}

void func_8004E184(void) {
    s32 i;

    for (i = 0; i < 32; i++) {
        if (D_800F50C0[i] == NULL) {
            continue;
        }
        if (D_800F50C0[i]->func_ptr == func_8004E248 || D_800F50C0[i]->func_ptr == func_8004E564 ||
            D_800F50C0[i]->func_ptr == func_8004EC44) {
            if (D_800F50C0[i]->stat & 4) {
                D_800F50C0[i]->unk_50 = NULL;
                omDelObj(D_800F50C0[i]);
            }
        }
    }
}
void func_8004E248(omObjData* arg0) {
    Object* temp_v0;
    Object* temp_v1; /* a board model; was unkGlobalStruct_00, whose unk_0C.. sit 8 bytes before coords on 64-bit hosts */

    temp_v1 = arg0->unk_50;
    arg0->work[1]--;
    
    if (temp_v1 == NULL) {
        if (arg0->work[1] == 0) {
            GwPlayer[arg0->work[0]].player_obj->coords.x = arg0->trans.x;
            GwPlayer[arg0->work[0]].player_obj->coords.y = arg0->trans.y;
            GwPlayer[arg0->work[0]].player_obj->coords.z = arg0->trans.z;
            omDelObj(arg0);
            return;
        }
        temp_v0 = GwPlayer[arg0->work[0]].player_obj;
        temp_v0->coords.x = temp_v0->coords.x + arg0->scale.x;
        temp_v0 = GwPlayer[arg0->work[0]].player_obj;
        temp_v0->coords.y = temp_v0->coords.y + arg0->scale.y;
        temp_v0 = GwPlayer[arg0->work[0]].player_obj;
        temp_v0->coords.z = temp_v0->coords.z + arg0->scale.z;
        return;
    }
    
    if (arg0->work[1] == 0) {
        temp_v1->coords.x = arg0->trans.x;
        temp_v1->coords.y = arg0->trans.y;
        temp_v1->coords.z = arg0->trans.z;
        arg0->unk_50 = NULL;
        omDelObj(arg0);
        return;
    }
    
    temp_v1->coords.x += arg0->scale.x;
    temp_v1->coords.y += arg0->scale.y;
    temp_v1->coords.z += arg0->scale.z;
}

omObjData* func_8004E3E0(s32 arg0, Vec3f* arg1, s32 arg2, void* arg3) { //fix arg3 type later
    omObjData* obj;
    s32 i;
    arg3 = (Object*)arg3;

    obj = omAddObj(0x1000, 0, 0, -1, &func_8004E248);
    obj->work[0] = arg0;
    obj->work[1] = arg2;
    obj->trans.x = arg1->x;
    obj->trans.y = arg1->y;
    obj->trans.z = arg1->z;
    if (arg3 == NULL) {
        obj->scale.x = (arg1->x - GwPlayer[arg0].player_obj->coords.x) / arg2;
        obj->scale.y = (arg1->y - GwPlayer[arg0].player_obj->coords.y) / arg2;
        obj->scale.z = (arg1->z - GwPlayer[arg0].player_obj->coords.z) / arg2;
    } else {
        obj->scale.x = (arg1->x - ((Object*)arg3)->coords.x) / arg2;
        obj->scale.y = (arg1->y - ((Object*)arg3)->coords.y) / arg2;
        obj->scale.z = (arg1->z - ((Object*)arg3)->coords.z) / arg2;
    }
    
    obj->unk_50 = arg3;

    for (i = 0; i < ARRAY_COUNT(D_800F50C0); i++) {
        if (D_800F50C0[i] == NULL) {
            D_800F50C0[i] = obj;
            return obj;
            break;
        }
    }
    return obj;
}

f32 fsin(f32);
void func_8004E564(omObjData* arg0) { //matches, needs rodata support
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f20_5;
    Object* var_s0;
    Object* temp_v0;
    Object *new_var;

    var_s0 = (Object*)arg0->unk_50;
    arg0->work[1]--;
    
    if (var_s0 == NULL) {
        if (arg0->work[1] == 0) {
            GwPlayer[arg0->work[0]].player_obj->coords.x = arg0->trans.x;
            GwPlayer[arg0->work[0]].player_obj->coords.y = arg0->trans.y;
            GwPlayer[arg0->work[0]].player_obj->coords.z = arg0->trans.z;
            omDelObj(arg0);
            return;
        }
        
        GwPlayer[arg0->work[0]].player_obj->coords.x = GwPlayer[arg0->work[0]].player_obj->coords.x + arg0->scale.x;
        GwPlayer[arg0->work[0]].player_obj->coords.y = GwPlayer[arg0->work[0]].player_obj->coords.y + arg0->scale.y;
        GwPlayer[arg0->work[0]].player_obj->coords.z = GwPlayer[arg0->work[0]].player_obj->coords.z + arg0->scale.z;   
        new_var = GwPlayer[arg0->work[0]].player_obj;
        temp_v0 = new_var;
        temp_f20 = fsin(arg0->work[1] * 180.0f / arg0->work[2] * (M_PI/180)) * arg0->rot.x;
        temp_v0->coords.x += temp_f20 - (fsin((arg0->work[1] + 1) * 180.0f / arg0->work[2] * (M_PI/180)) * arg0->rot.x);
        temp_v0 = GwPlayer[arg0->work[0]].player_obj;
        temp_f20_2 = fsin(arg0->work[1] * 180.0f / arg0->work[2] * (M_PI/180)) * arg0->rot.y;
        temp_v0->coords.y += temp_f20_2 - (fsin((arg0->work[1] + 1) * 180.0f / arg0->work[2] * (M_PI/180)) * arg0->rot.y);
        var_s0 = GwPlayer[arg0->work[0]].player_obj;
        temp_f20_5 = fsin(arg0->work[1] * 180.0f / arg0->work[2] * (M_PI/180))* arg0->rot.z;
        temp_f20_5 = temp_f20_5 - (fsin(( (((arg0->work[1] + 1) * 180.0f) / arg0->work[2]) * (M_PI/180))) * arg0->rot.z);
        temp_f20_5 += var_s0->coords.z;
        var_s0->coords.z = temp_f20_5;
    } else if (arg0->work[1] == 0) {
        var_s0->coords.x = arg0->trans.x;
        var_s0->coords.y = arg0->trans.y;
        var_s0->coords.z = arg0->trans.z;
        arg0->unk_50 = NULL;
        omDelObj(arg0);
        return;
    } else {
        var_s0->coords.x += arg0->scale.x;
        var_s0->coords.y += arg0->scale.y;
        var_s0->coords.z += arg0->scale.z;

        temp_f20_3 = fsin(arg0->work[1] * 180.0f / arg0->work[2] * (M_PI/180))* arg0->rot.x;
        var_s0->coords.x += temp_f20_3 - (fsin(( (((arg0->work[1] + 1) * 180.0f) / arg0->work[2]) * (M_PI/180))) * arg0->rot.x);
        temp_f20_4 = fsin(arg0->work[1] * 180.0f / arg0->work[2] * (M_PI/180))* arg0->rot.y;
        var_s0->coords.y += temp_f20_4 - (fsin(( (((arg0->work[1] + 1) * 180.0f) / arg0->work[2]) * (M_PI/180))) * arg0->rot.y);
        temp_f20_5 = fsin(arg0->work[1] * 180.0f / arg0->work[2] * (M_PI/180))* arg0->rot.z;
        temp_f20_5 = temp_f20_5 - (fsin(( (((arg0->work[1] + 1) * 180.0f) / arg0->work[2]) * (M_PI/180))) * arg0->rot.z);
        temp_f20_5 += var_s0->coords.z;
        var_s0->coords.z = temp_f20_5;
    }
}

omObjData* func_8004EA8C(Object* arg0, Vec3f* arg1, s32 arg2, Vec3f* arg3) {
    s32 player = -1;
    omObjData* obj;
    f32 n;
    s32 i;

    obj = omAddObj(0x1000, 0, 0, -1, func_8004E564);
    if ((s32)arg0 >= 0) {
        player = (s32)arg0;
        arg0 = NULL;
        obj->work[0] = player;
    }
    obj->work[1] = arg2;
    obj->work[2] = arg2;
    obj->trans.x = arg1->x;
    obj->trans.y = arg1->y;
    obj->trans.z = arg1->z;
    if (arg0 == NULL) {
        obj->scale.x = (arg1->x - GwPlayer[player].player_obj->coords.x) / (n = arg2);
        obj->scale.y = (arg1->y - GwPlayer[player].player_obj->coords.y) / n;
        obj->scale.z = (arg1->z - GwPlayer[player].player_obj->coords.z) / n;
    } else {
        obj->scale.x = (arg1->x - arg0->coords.x) / (n = arg2);
        obj->scale.y = (arg1->y - arg0->coords.y) / n;
        obj->scale.z = (arg1->z - arg0->coords.z) / n;
    }
    obj->rot.x = arg3->x;
    obj->rot.y = arg3->y;
    obj->rot.z = arg3->z;
    obj->unk_50 = arg0;
    for (i = 0; i < 32; i++) {
        if (D_800F50C0[i] == NULL) {
            D_800F50C0[i] = obj;
            break;
        }
    }
    return obj;
}
void func_8004EC44(omObjData* arg0) {
    Object* obj = arg0->unk_50;

    arg0->work[1]--;
    if (obj == NULL) {
        if (arg0->work[1] == 0) {
            GwPlayer[arg0->work[0]].player_obj->unk_18.x = arg0->rot.x;
            GwPlayer[arg0->work[0]].player_obj->unk_18.y = arg0->rot.y;
            GwPlayer[arg0->work[0]].player_obj->unk_18.z = arg0->rot.z;
            omDelObj(arg0);
            return;
        }
        arg0->scale.y += arg0->scale.x;
        GwPlayer[arg0->work[0]].player_obj->unk_18.x = sinf(arg0->scale.y * (M_PI / 180));
        GwPlayer[arg0->work[0]].player_obj->unk_18.y = 0.0f;
        GwPlayer[arg0->work[0]].player_obj->unk_18.z = cosf(arg0->scale.y * (M_PI / 180));
        return;
    }
    if (arg0->work[1] == 0) {
        obj->unk_18.x = arg0->rot.x;
        obj->unk_18.y = arg0->rot.y;
        obj->unk_18.z = arg0->rot.z;
        arg0->unk_50 = NULL;
        omDelObj(arg0);
        return;
    }
    arg0->scale.y += arg0->scale.x;
    obj->unk_18.x = sinf(arg0->scale.y * (M_PI / 180));
    obj->unk_18.y = 0.0f;
    obj->unk_18.z = cosf(arg0->scale.y * (M_PI / 180));
}
omObjData* func_8004EE14(s32 arg0, void* arg1, s32 arg2, void* arg3) {
    Vec3f dir;
    f32 cur;
    f32 tgt;
    omObjData* obj;
    s32 i;

    if (arg3 == NULL) {
        func_8004CCD0(&GwPlayer[arg0].player_obj->coords, arg1, &dir);
    } else {
        func_8004CCD0(&((Object*)arg3)->coords, arg1, &dir);
    }
    obj = omAddObj(0x1000, 0, 0, -1, func_8004EC44);
    obj->work[0] = arg0;
    obj->work[1] = arg2;
    obj->rot.x = dir.x;
    obj->rot.y = dir.y;
    obj->rot.z = dir.z;
    if (arg3 == NULL) {
        cur = func_8003D2B0(&GwPlayer[arg0].player_obj->unk_18);
        tgt = func_8003D2B0(&dir);
        if (tgt < cur) {
            if (cur - tgt >= 180.0f) {
                tgt += 360.0f;
            }
        } else {
            if (tgt - cur >= 180.0f) {
                cur += 360.0f;
            }
        }
    } else {
        cur = func_8003D2B0(&((Object*)arg3)->unk_18);
        tgt = func_8003D2B0(&dir);
        if (tgt < cur) {
            if (cur - tgt >= 180.0f) {
                tgt += 360.0f;
            }
        } else {
            if (tgt - cur >= 180.0f) {
                cur += 360.0f;
            }
        }
    }
    obj->scale.y = cur;
    obj->scale.x = (tgt - cur) / arg2;
    obj->unk_50 = arg3;
    for (i = 0; i < 32; i++) {
        if (D_800F50C0[i] == NULL) {
            D_800F50C0[i] = obj;
            break;
        }
    }
    return obj;
}
void func_8004F00C(Object* arg0, f32 arg1, f32 arg2) {
    arg0->unk_34 = arg1;
    arg0->unk_38 = arg2;
}

s32 func_8004F018(Object* arg0) {
    if (!(arg0->unk_38 != 0.0f)) {
        return 0;
    } else {
        return 1;
    }
}

void func_8004F044(Object* arg0) {
    while (func_8004F018(arg0) != 0) {
        HuPrcVSleep();
    }
}

void func_8004F084(omObjData* arg0) {
    f32 temp_f0;

    func_800264F8(arg0->mdlcnt, arg0->mtncnt, (fsin((f32) (arg0->trans.x * (M_PI/180))) / 2.0f) + 0.5f, (u8*)"030-hata1", (u8*)"hata2", 0);
    arg0->trans.x += 20.0f;
    if (arg0->trans.x >= 360.0f) {
        arg0->trans.x -= 360.0f;
    }
}

void func_8004F140(s32 arg0) {
    omObjData* temp_v0;

    D_800C524C = LoadFormFile(0xA0076, 0x2AD);
    func_80026040(arg0);
    temp_v0 = omAddObj(0x1000, 0, 0, -1, &func_8004F084);
    D_800C5248 = temp_v0;
    temp_v0->trans.x = 0.0f;
    temp_v0->mdlcnt = arg0;
    temp_v0->mtncnt = (u16)D_800C524C;
    omSetStatBit(temp_v0, 0xA0);
}

void func_8004F1D0(void) {
    if (D_800C5248 != NULL) {
        omDelObj(D_800C5248);
        D_800C5248 = NULL;
    }
    if (D_800C524C != -1) {
        func_8002456C((s16)D_800C524C);
        D_800C524C = -1;
    }
}
u16 func_8004F234(void) {
    return LoadFormFile(0xA0089, 0x2B9);
}
u16 func_8004F25C(void) {
    return LoadFormFile(0x1F0001, 0x2B9);
}
void func_8004F284(void) {
}

void func_8004F28C(s32 arg0, s16 arg1) {
    func_8005699C(arg1);
}
void func_8004F2AC(void) {
    s32 i;

    for (i = 0; i < 16; i++) {
        D_800D8160[i].unk4 = NULL;
        D_800D8160[i].unk8 = NULL;
    }
}
void func_8004F2EC(void) {
    s32 i;

    for (i = 0; i < 16; i++) {
        Unk4E530Motion* p = &D_800D8160[i];
        if (p->unk8 != NULL) {
            omDelObj(p->unk8);
            p->unk8 = NULL;
        }
    }
}
void func_8004F358(omObjData* arg0) {
    Unk4E530Motion* p = &D_800D8160[arg0->work[0]];

    if (func_80025D18(*p->unk4->unk_3C->unk_40) == func_80025D40(*p->unk4->unk_3C->unk_40)) {
        MBMotionShiftSet(p->unk4, p->unk0, 0, 0xA, p->unk2);
        p->unk4 = NULL;
        p->unk8 = NULL;
        omDelObj(arg0);
    }
}
// decomp-permuter
s32 func_8004F40C(Object *arg0, s32 arg1, s32 arg2)
{
  Unk4E530Motion *p;
  omObjData *obj;
  s32 i;
  for (i = 0; i < 16; i++)
  {
    p = &D_800D8160[i];
    if (p->unk8 == 0)
    {
      break;
    }
  }

  if (i == 16)
  {
    if (1)
    {
      return -1;
    }
  }
  obj = omAddObj(0x2000, 0, 0, -1, func_8004F358);
  p->unk8 = obj;
  obj->work[0] = i;
  p->unk4 = arg0;
  p->unk0 = arg1;
  arg2++;
  arg2--;
  arg1 = arg2;
  p->unk2 = arg1;
  return i;
}
void func_8004F4D4(void* arg0, s32 arg1, s32 arg2) {
    MBMotionShiftSet(arg0, arg1, 0, 0xA, arg2);
}
void func_8004F504(void* arg0) {
    while (!(MBMotionCheck(arg0) & 1)) {
        HuPrcVSleep();
    }
}
void func_8004F548(void) {
    s32 i;

    for (i = 0; i < 16; i++) {
        D_800D8220[i].unk0 = -1;
        D_800D8220[i].unk2 = -1;
    }
}
void func_8004F584(s32 arg0) {
    Unk4E530Sprite* p = &D_800D8220[arg0];

    if (p->unk0 != -1) {
        func_80064D38(p->unk0);
        p->unk0 = -1;
    }
    if (p->unk2 != -1) {
        func_80067704(p->unk2);
        p->unk2 = -1;
    }
}
void func_8004F5F0(void) {
    s32 i;

    for (i = 0; i < 16; i++) {
        func_8004F584(i);
    }
}
s32 func_8004F628(s32 arg0, u16 arg1, s16 arg2, s16 arg3) {
    Unk4E530Sprite* p;
    void* data;
    s32 i;

    for (i = 0; i < 16; i++) {
        p = &D_800D8220[i];
        if (p->unk0 == -1) {
            break;
        }
    }
    if (i == 16) {
        return -1;
    }
    p->unk0 = func_80064EF4(1, 5);
    data = DataRead(arg0);
    p->unk2 = func_800678A4(data);
    DataClose(data);
    func_80067208(p->unk0, 0, p->unk2, 0);
    func_800672B0(p->unk0, 0, 1);
    func_80067384(p->unk0, 0, arg1);
    func_800674BC(p->unk0, 0, 0x1000);
    func_80066DC4(p->unk0, 0, arg2, arg3);
    return i;
}
void func_8004F754(s32 arg0, s16 arg1, s16 arg2) {
    func_80066DC4(D_800D8220[arg0].unk0, 0, arg1, arg2);
}
void func_8004F790(s32 arg0, u8 arg1) {
    func_8006752C(D_800D8220[arg0].unk0, 0, arg1);
}
void func_8004F7C0(s32 arg0, f32 arg1, f32 arg2) {
    func_80067354(D_800D8220[arg0].unk0, 0, arg1, arg2);
}
void func_8004F800(s32 arg0, s32 arg1) {
    func_800674BC(D_800D8220[arg0].unk0, 0, arg1);
}
void func_8004F830(s32 arg0, s32 arg1) {
    func_80067480(D_800D8220[arg0].unk0, 0, arg1);
}
void func_8004F860(s32 arg0, f32 arg1) {
    func_80067284(D_800D8220[arg0].unk0, 0, arg1);
}
void func_8004F898(s32 arg0, u8 arg1, u8 arg2, u8 arg3) {
    func_800674F4(D_800D8220[arg0].unk0, 0, arg1, arg2, arg3);
}
void func_8004F8DC(void) {
    s32 i;

    func_8001DE70(0x20);
    for (i = 0; i < 16; i++) {
        D_800D8260[i].unk4 = NULL;
        D_800D8260[i].unk0 = NULL;
    }
}
void func_8004F928(omObjData* arg0) {
    func_800214FC(D_800D8260[arg0->work[0]].unk4);
}
s32 func_8004F954(s32 arg0, s32 arg1) {
    Unk4E530Effect* p;
    omObjData* obj;
    s32 i;

    for (i = 0; i < 16; i++) {
        p = &D_800D8260[i];
        if (p->unk4 == NULL) {
            break;
        }
    }
    if (i == 16) {
        return -1;
    }
    p->unk4 = func_80021308(arg0, arg1);
    obj = omAddObj(0x3000, 0, 0, -1, func_8004F928);
    p->unk0 = obj;
    obj->work[0] = i;
    return i;
}
void func_8004F9F4(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4) {
    func_80021794(D_800D8260[arg0].unk4, 0, arg1, arg2, arg3, arg4);
}
void func_8004FA48(s32 arg0, s16 arg1, f32 arg2, f32 arg3, f32 arg4, s16 arg5) {
    func_80021794(D_800D8260[arg0].unk4, arg1, arg2, arg3, arg4, arg5);
}
void func_8004FA90(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    func_80021AF4(D_800D8260[arg0].unk4, arg1, arg2, arg3);
}
void func_8004FAB8(s32 arg0) {
    Unk4E530Effect* p = &D_800D8260[arg0];

    if (p->unk4 != NULL) {
        func_80021474(p->unk4);
        p->unk4 = NULL;
    }
    if (p->unk0 != NULL) {
        omDelObj(p->unk0);
        p->unk0 = NULL;
    }
}
void func_8004FB14(void) {
    s32 i;

    for (i = 0; i < 16; i++) {
        D_800D82E0[i].unk0 = NULL;
        D_800D82E0[i].unk4 = -1;
    }
}
void func_8004FB50(s32 arg0) {
    Unk4E530Data* p = &D_800D82E0[arg0];

    if (p->unk4 != -1) {
        func_80039ACC(p->unk4);
        p->unk4 = -1;
    }
    if (p->unk0 != NULL) {
        DataClose(p->unk0);
        p->unk0 = NULL;
    }
}
void func_8004FBB4(void) {
    s32 i;

    for (i = 0; i < 16; i++) {
        func_8004FB50(i);
    }
}
s32 func_8004FBEC(s32 arg0, s32 arg1, char* arg2) {
    Unk4E530Data* p;
    void* data;
    s32 i;

    for (i = 0; i < 16; i++) {
        p = &D_800D82E0[i];
        if (p->unk0 == NULL) {
            break;
        }
    }
    if (i == 16) {
        return -1;
    }
    data = DataRead(arg0);
    p->unk0 = data;
    p->unk4 = func_80038A9C(D_800F2B7C[arg1].unk_6C, data, 0, arg2);
    func_80025AD4(arg1);
    return i;
}
void func_8004FCB0(omObjData* arg0) {
    Vec3f pos;

    if (arg0->mdlcnt == 0) {
        arg0->trans.x = arg0->rot.x;
        arg0->trans.y = arg0->rot.y;
        arg0->trans.z = arg0->rot.z;
    } else {
        arg0->trans.x += arg0->scale.x;
        arg0->trans.y += arg0->scale.y;
        arg0->trans.z += arg0->scale.z;
    }
    pos.x = arg0->trans.x;
    pos.y = arg0->trans.y;
    pos.z = arg0->trans.z;
    func_8004B5DC(&pos);
    if (arg0->mdlcnt == 0) {
        omDelObj(arg0);
    }
    arg0->mdlcnt--;
}
s32 func_8004FD68(Vec3f* arg0, Vec3f* arg1, f32 arg2) {
    Vec3f dist;
    Vec3f vel;
    f32 angle;
    f32 count;
    omObjData* obj;
    s32 n;

    dist.x = arg1->x - arg0->x;
    dist.y = arg1->y - arg0->y;
    dist.z = arg1->z - arg0->z;
    angle = func_8003D2B0(&dist) * (M_PI / 180);
    vel.x = sinf(angle) * arg2;
    vel.y = 0.0f;
    vel.z = cosf(angle) * arg2;
    count = dist.x / vel.x;
    obj = omAddObj(0x5000, 0, 0, -1, func_8004FCB0);
    obj->trans.x = arg0->x;
    obj->trans.y = arg0->y;
    obj->trans.z = arg0->z;
    obj->scale.x = vel.x;
    obj->scale.y = vel.y;
    obj->scale.z = vel.z;
    obj->rot.x = arg1->x;
    obj->rot.y = arg1->y;
    obj->rot.z = arg1->z;
    obj->mdlcnt = n = count;
    return n;
}
s32 func_8004FEA0(Vec3f* arg0, Vec3f* arg1) {
    return func_8004FD68(arg0, arg1, 30.0f);
}
s32 func_8004FEBC(s32 arg0) {
    s32 scores[4];
    s32 i;
    s32 rank;

    for (i = 0; i < 4; i++) {
        scores[i] = GwPlayer[i].stars * 1000 + GwPlayer[i].coins;
    }
    for (i = 0, rank = 0; i < 4; i++) {
        if (i != arg0) {
            rank += scores[arg0] < scores[i];
        }
    }
    return rank;
}
s32 func_8004FF68(s32 arg0) {
    return GwPlayer[arg0].stars * 1000 + GwPlayer[arg0].coins;
}
void func_8004FFA8(void) {
    s32 i;

    HuPrcSleep(2);
    for (i = 0; i < 4; i++) {
        if (!(GwPlayer[i].flags & 1)) {
            break;
        }
    }
    if (i == 4) {
        HuPrcSleep(30);
        return;
    }
    while (1) {
        for (i = 0; i < 4; i++) {
            if (!(GwPlayer[i].flags & 1) && (ContBtnTrg[GwPlayer[i].port] & 0xC000)) {
                break;
            }
        }
        if (i != 4) {
            break;
        }
        HuPrcVSleep();
    }
}
void func_800500A4(void) {
    f32 t;

    D_800D8360 = func_8000C4A0();
    D_800D8364 = D_800D8360;
    D_800D8368 = D_800D8360 / 15.0f;
    while (1) {
        t = D_800D8364 - D_800D8368;
        D_800D8364 = t;
        if (t <= 0.0f) {
            break;
        }
        func_80060214(t);
        HuPrcVSleep();
    }
    func_80060214(0);
}
void func_80050160(void) {
    f32 t;

    D_800D8364 = 0.0f;
    D_800D8368 = D_800D8360 / 75.0f;
    while (1) {
        t = D_800D8364 + D_800D8368;
        D_800D8364 = t;
        if (D_800D8360 <= t) {
            break;
        }
        func_80060214(t);
        HuPrcVSleep();
    }
    func_80060214(D_800D8360);
}
s32 func_8005021C(f32 arg0) {
    u8 hi = rand8();
    u8 lo = rand8();
    s32 v = hi << 8;

    return (lo | v) / 65536.0f * arg0;
}
s16 func_80050288(void) {
    s32 id = GwCommon.unk_46;

    if (id == -1) {
        id = 6;
    }
    func_8004F548();
    if (D_800C526C != -1) {
        func_80050338();
    }
    D_800C526C = func_8004F628(D_800C5250[id], 10, 160, 120);
    func_800674BC(D_800D8220[D_800C526C].unk0, 0, 0x4000);
    return D_800D8220[D_800C526C].unk0;
}
void func_80050338(void) {
    func_8004F584(D_800C526C);
    D_800C526C = -1;
    func_8004F5F0();
}
void func_80050368(void) {
    func_8004F800(D_800C526C, 0x8000);
}
void func_8005038C(void) {
    func_8004F830(D_800C526C, 0x8000);
}
void func_800503B0(s32 arg0, s32 arg1) {
    if (!(GwPlayer[arg0].flags & 1)) {
        switch (arg1) {
        case 1:
            func_80060F04(arg0, 5, 0, 5);
            break;
        case 2:
            func_80060F04(arg0, 2, 3, 10);
            break;
        case 3:
            func_80060F04(arg0, 10, 0, 10);
            break;
        case 4:
            func_80060F04(arg0, 20, 0, 20);
            break;
        case 5:
            func_80060F04(arg0, 2, 2, 20);
            break;
        case 6:
            func_80060F04(arg0, 30, 0, 30);
            break;
        }
    }
}
void func_8005049C(void) {
    s32 board = GwSystem.curBoardIndex;
    s32 player = GwSystem.curPlayerIndex;
    s32 bg;

    if (_CheckFlag(0x30) != 0) {
        board = 9;
    }
    switch (board) {
    case 1:
        if (GwPlayer[player].cur_chain == 2) {
            bg = 12;
        } else {
            bg = 9;
        }
        break;
    case 3:
        switch (GwPlayer[player].cur_chain) {
        case 2:
            bg = 0x1D;
            break;
        case 3:
            bg = 0x21;
            break;
        case 8:
            bg = 0x1F;
            break;
        case 1:
            bg = 0x20;
            break;
        case 0:
        default:
            bg = 0x1E;
            break;
        }
        break;
    case 10:
        if ((D_800F329A == -1) | (D_800F329A >= 10)) {
            bg = 0x59;
        } else {
            bg = D_800C529C[D_800F329A];
        }
        break;
    default:
        bg = D_800C5270[board];
        break;
    }
    LoadBackgroundIndex(bg);
}
